#ifdef __VRE__

#include "mmi_include.h"
#include "custom_data_account.h"
#include "soc_api.h"
//#include "DataAccountDef.h"
#include "SimDetectionGprot.h"
//#include "DataAccountGProt.h"



#include "CommonScreens.h"
#include "ServiceDefs.h"
#include "ProfileGprots.h"
#include "SimDetectionGprot.h"
#include "NetworkSetupDefs.h"

#include "custom_nvram_editor_data_item.h"

#ifdef __MMI_WLAN_FEATURES__

#include "wndrv_cnst.h"
#include "wndrv_supc_types.h"
#include "supc_abm_msgs.h"
#include "supc_mmi_msgs.h"
#include "mmi2abm_struct.h"
#include "FileMgr.h"

#endif /* __MMI_WLAN_FEATURES__ */ 

#include "DataAccountResDef.h"
#include "DataAccountDef.h"
#include "DataAccountEnum.h"
#include "DataAccountStruct.h"
#include "DataAccountGProt.h"
#include "DataAccountProt.h"





#include "SimDetectionDef.h"

#include "protocolevents.h"



#include "ABM_SOC_ENUMS.H"
#include "abm_api.h"
#include "cbm_api.h"

#include "vmsock.h"
#include "vmsys.h"
#include "vmlog.h"
#include "vmopt.h"
#include "vmmod.h"
#include "vmsim.h"
#include "vmchset.h"
#include "vmglobalver.h"
#include "vmmem.h"
#include "vmpromng.h"
#include "vmresmng.h"
#include "vmmacrostub.h"
#include "vredef.h"
#include "vmenv.h"



#define VM_SOCK_POOL_SIZE 		VRE_SUPPORT_TCP_CONTEXT_MAX_NUM
#define PF_INET 					SOC_PF_INET 
#define SOCK_STREAM 			SOC_SOCK_STREAM


#define DATAACCOUNT_PREVIOUS_POS (1)
#define DATAACCOUNT_NEXT_POS     (DATAACCOUNT_PREVIOUS_POS - 1)


#define AM_WAP_STR "AM WAP ACCOUNT"
#define AM_NET_STR "AM NET ACCOUNT"


#define VRE_DATAACCOUNT_READY_TIME  (50)

/*
 * 得到联网账号。
 */
extern VMUINT vm_get_account_id(VMUINT account_id, VMUINT8 app_id);

/*
  * TCP链路读通道的状态。
  */
typedef enum 
{
	read_block = 0,								// 读阻塞状态
	read_notify									// 读允许状态
} sock_read_pipe_t;

/*
  * TCP链路写通道的状态。
  */
typedef enum 
{
	write_block = 0,								// 写阻塞状态
	write_notify									// 写允许状态
} sock_write_pipe_t;

/*
  * TCP链路的状态。
  */
typedef enum 
{
	conn_init = 0,								// 未连接状态
	conn_host_by_name,							// DSN 解析状态
	conn_connected,								// 已连接状态
	conn_unkown								// 未知的SOCKET 状态
} sock_connection_t;

/*
  * TCP链路的上下文的结构。
  */
typedef struct vm_sock_context_t 
{
	kal_int8 sock;								/**< socket 句柄								*/
	kal_uint16 port;								/**< socket 远程端口							*/
	sock_connection_t socket_state;				/**<socket 链路的状态						*/
	sock_read_pipe_t read_pipe_state;				/**< 写通道的状态							*/
	sock_write_pipe_t write_pipe_state;				/**< 读通道的状态							*/
	void (*callback)(VMINT handle, VMINT event);		/**< 事件回调函数句柄					*/
	VMINT res_handle;							/**< 该上下的空间是否已经被使用 	*/
} vm_sock_context_t;


typedef struct
{
	VMWCHAR     apn[MAX_GPRS_APN_LEN];
	VMCHAR     user_name[MAX_GPRS_USER_NAME_LEN];
	VMCHAR     pass_word[MAX_GPRS_PASSWORD_LEN];
}vm_tcp_apn_info;



vm_tcp_check_ready_callback g_vre_tcp_check_ready_cb;
vm_apn_info *vm_tcp_apn_info_timer;

extern VMINT vre_running;

/*
  * 从socket 上下文资源池中获得socket上下文。
  */
static vm_sock_context_t* vm_malloc_socket_context(void);

/*
  * 把socket上下文归还到socket上下文资源池中。
  */
static void vm_free_socket_context(vm_sock_context_t*);

/*
  * 根据使用的socket句柄找到对应的socket链路上下
  * 文，如果找不到返回NULL。
  */
static vm_sock_context_t* vm_get_socket_context(VMINT);

/*
 * 注册到MTK的协议事件里的soc_notify函数。
 */
static MMI_BOOL vm_soc_notify(void*);

/*
 * 注册到MTK的协议事件里的get_host_by_name函数。
 */
static MMI_BOOL vm_get_host_by_name(void*);

/*
  * 初始化本模块的资源。
  */
static VMINT initialize_socket_resource(void);

/*
  * 释放本模块的资源
  */
static VMINT finialize_socket_resource(void);

/*
  * SOCKET模块生命周期事件的处理函数。
  */
static VMINT sock_mod_evt_proc(VRE_MOD_LIFECIRCLE_EVT event);

/*
  * 加入close的保护，防止MTK不传回CLOSE事件。
  */
//static void vm_close_timer_proc(int timer_id);

/*
 * 查找str_1和str_2是否相等，本函数大小不敏感。
 * 例如:str1为L"jie.chen"而str2为L"JIE.chen"则毕竟返回TRUE。
 */
static VMINT vm_cmp_wstr_ignore_case(VMWSTR str_1, VMWSTR str_2, VMUINT count);
BOOL mmi_dtcnt_get_apn_info(U32 account_id, vm_tcp_apn_info *dest);

static void vm_soc_notify_process_status(VM_P_HANDLE process_handle, 
	VMINT sys_state)
{
	VMINT resHandle = 0, bufSize = 0;
	vm_sock_context_t* socket_context = NULL;

	switch (sys_state)
	{
	case VM_PMNG_UNLOAD:
		while ((resHandle = vm_res_findfirst(process_handle, VM_RES_TYPE_TCP_HANDLE)) 
			!= VM_RES_NOT_FIND)
		{
			if (vm_res_get_data(VM_RES_TYPE_TCP_HANDLE, 
				resHandle, (void**)&socket_context, &bufSize) == 0 && socket_context != NULL)
			{
				if (socket_context->socket_state == conn_host_by_name)
				{
					soc_abort_dns_query(KAL_TRUE, MOD_MMI, KAL_TRUE, 
						socket_context->sock, KAL_FALSE, 0, KAL_FALSE, 0);
				}
				soc_close(socket_context->sock);
				/* 分配内存的时候是通过vm_malloc分配的。 */
				_vm_kernel_free(socket_context);
			}
			else
			{
				vm_log_warn("[TCP MODULE]Failed to get socket id form resource manager.");
			}
			vm_res_release_data(VM_RES_TYPE_TCP_HANDLE, resHandle);
			vm_res_findclose(VM_RES_TYPE_TCP_HANDLE); 
		}
		break;
	}
}

static VMINT g_vre_is_ready_dataaccount = FALSE;
VMINT g_vre_add_data_account_done = FALSE;

static void init_dataaccount_callback(void)
{
	vm_log_fatal("Finish init data account.");
	g_vre_is_ready_dataaccount = TRUE;
}

VMINT vm_is_ready_dataaccount(void)
{
	return g_vre_add_data_account_done;
}

VMINT vm_is_ready_dataaccount2(void)
{
	return g_vre_is_ready_dataaccount;
}

void vm_set_dataaccount_done(VMINT done)
{
	g_vre_add_data_account_done = done;
}




static kal_uint8 cbm_app_id = 1;


static VMINT vm_never_call_mmi_dtcnt_ready_check_on_background = TRUE;
static VMINT vre_check_am_is_quick_start(void)
{
    return mmi_am_check_is_quick_start();
}
    

static VMINT initialize_socket_resource(void)
{
	if (vm_never_call_mmi_dtcnt_ready_check_on_background == TRUE)
	{
		vm_never_call_mmi_dtcnt_ready_check_on_background = FALSE;
		mmi_dtcnt_ready_check_on_background(init_dataaccount_callback);
	}

	if (vm_res_type_set_notify_callback(VM_RES_TYPE_TCP_HANDLE, 
		vm_soc_notify_process_status) != 0)
	{
		return -1;
	}

	return 0;
}

static VMINT finialize_socket_resource(void)
{
	VMINT resHandle = 0, bufSize = 0;
	vm_sock_context_t* socket_context = NULL;

	while ((resHandle = vm_res_findfirst(-1, VM_RES_TYPE_TCP_HANDLE)) 
		!= VM_RES_NOT_FIND)
	{
		if (vm_res_get_data(VM_RES_TYPE_TCP_HANDLE, 
			resHandle, (void**)&socket_context, &bufSize) == 0 && socket_context != NULL)
		{
			if (socket_context->socket_state == conn_host_by_name)
			{
				soc_abort_dns_query(KAL_TRUE, MOD_MMI, KAL_TRUE, 
					socket_context->sock, KAL_FALSE, 0, KAL_FALSE, 0);
			}
			soc_close(socket_context->sock);
			/* 分配内存的时候是通过vm_malloc分配的。 */
			_vm_kernel_free(socket_context);
		}
		else
		{
			vm_log_warn("[TCP MODULE]Failed to get socket id form resource manager.");
		}
		vm_res_release_data(VM_RES_TYPE_TCP_HANDLE, resHandle);
		vm_res_findclose(VM_RES_TYPE_TCP_HANDLE);
	}
	
	vm_res_type_set_notify_callback(VM_RES_TYPE_TCP_HANDLE, NULL);


#if defined(__VRE_RB_08A__)
	mmi_frm_clear_protocol_event_handler(MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND);
	mmi_frm_clear_protocol_event_handler(MSG_ID_APP_SOC_NOTIFY_IND);
#elif defined(__VRE_RB_08B__)
	mmi_frm_clear_protocol_event_handler(MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND, (PsFuncPtr)vm_get_host_by_name);
	mmi_frm_clear_protocol_event_handler(MSG_ID_APP_SOC_NOTIFY_IND, (PsFuncPtr)vm_soc_notify);
#else
	mmi_frm_clear_protocol_event_handler(MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND, (PsIntFuncPtr)vm_get_host_by_name);
	mmi_frm_clear_protocol_event_handler(MSG_ID_APP_SOC_NOTIFY_IND, (PsIntFuncPtr)vm_soc_notify);	
#endif

	//cbm_release_bearer(MOD_MMI, cbm_app_id);
	//cbm_deregister_app_id(cbm_app_id);

	return 0;
}

static VMINT sock_mod_evt_proc(VRE_MOD_LIFECIRCLE_EVT event)
{
	switch(event)
	{
	case EVT_MOD_INIT:
		if (initialize_socket_resource() != 0)
			return -1;
		break;
	case EVT_MOD_RELEASE:
		finialize_socket_resource();
		break;
	case EVT_MOD_ACTIVE:
		break;
	case EVT_MOD_INACTIVE:
		break;
	default:
		vm_log_error("[TCP MODULE]Receive unkown[%d] event.", event);
		return -2;
	}

	return 0;
}

static vm_sock_context_t* vm_get_socket_context(VMINT sock_id)
{
	VMINT resHandle = 0, bufSize = 0;
	vm_sock_context_t* socketContext = NULL;
	
	if ((resHandle = vm_res_findfirst(-1, VM_RES_TYPE_TCP_HANDLE)) != VM_RES_NOT_FIND)
	{
		if (vm_res_get_data(VM_RES_TYPE_TCP_HANDLE, 
			resHandle, (void**)&socketContext, &bufSize) == 0 && socketContext != NULL)
		{
			if (socketContext->sock == sock_id)
			{
				vm_res_findclose(VM_RES_TYPE_TCP_HANDLE);
				return socketContext;
			}
		}

		while ((resHandle = vm_res_findnext(-1, VM_RES_TYPE_TCP_HANDLE)) != VM_RES_NOT_FIND)
		{
			if (vm_res_get_data(VM_RES_TYPE_TCP_HANDLE, 
				resHandle, (void**)&socketContext, &bufSize) == 0 && socketContext != NULL)
			{
				if (socketContext->sock == sock_id)
				{
					vm_res_findclose(VM_RES_TYPE_TCP_HANDLE);
					return socketContext;
				}
			}
		}
		vm_res_findclose(VM_RES_TYPE_TCP_HANDLE);
	}	
	return NULL;
}

static vm_sock_context_t* vm_malloc_socket_context(void)
{
	vm_sock_context_t* socket_context = NULL;

	if ((socket_context = _vm_kernel_calloc(sizeof(vm_sock_context_t))) != NULL)
	{
		if ((socket_context->res_handle = vm_res_save_data(VM_RES_TYPE_TCP_HANDLE, 
			(void*)socket_context, sizeof(socket_context), NULL, vm_pmng_get_current_handle())) >= 0)
		{
			vm_log_debug("[TCP MODULE]Alloc resource[%d] socket context", 
				socket_context->res_handle);
			return socket_context;
		}
		else
		{
			_vm_kernel_free(socket_context);
		}
	}

	return NULL;
}

static void vm_free_socket_context(vm_sock_context_t* context_ptr)
{
	if (context_ptr)
	{
		vm_log_debug("[TCP MODULE]Free resource[%d] socket context.", 
			context_ptr->res_handle);
		vm_res_release_data(VM_RES_TYPE_TCP_HANDLE, context_ptr->res_handle);
		_vm_kernel_free(context_ptr);
	}
}

static VMINT vm_cmp_wstr_ignore_case(VMWSTR str_1, VMWSTR str_2, VMUINT count)
{
	if (count == 0)
		return TRUE;
	else
	{
		VMUINT i = 0;

		if (str_1 == str_2)
			return TRUE;

		if (!str_1 || !str_2)
			return FALSE;

		for (i = 0; i < count; i++)
		{
			if (str_1[i] != str_2[i])
			{
				if (str_1[i] >= L'A' && str_1[i] <= L'Z')
				{
					if (str_1[i] + ('a' - 'A') != str_2[i])
						return FALSE;
				}
				else if (str_1[i] >= L'a' && str_1[i] <= L'z')
				{
					if (str_1[i] - ('a' - 'A') != str_2[i])
						return FALSE;
				}
				else
					return FALSE;
			}
		}	
	}
		
	return TRUE;
}

/*
#ifdef __MMI_WLAN_FEATURES__
static U16 wifi_status = DTCNT_BEARER_STATE_INACTIVE;
static void vm_wifi_status_callback_handler(U16 status)
{
	wifi_status = status;
}
#endif


void vm_vre_wifi_init(void)
{
#ifdef __MMI_WLAN_FEATURES__
	mmi_wlan_add_event_notify_hdlr(vm_wifi_status_callback_handler);
#endif	
}

VMINT vm_tcp_wifi_connected (void)
{
#ifdef __MMI_WLAN_FEATURES__
	if (wifi_status == DTCNT_BEARER_STATE_CONNECTED)
	{
		return TRUE;
	}
#endif
	return FALSE;
}
*/

VMINT vm_is_support_wifi(void)
{
	return stub_tcp_is_support_wifi();
}

/* add by zaiping.chen, 2010.07.23, begin */
VMINT wifi_connectted_flag = FALSE;

VMINT vm_wifi_is_connected(void)
{
	if (TRUE == wifi_connectted_flag)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
/* add by zaiping.chen, 2010.07.23, end */

VMINT _vm_reg_tcp_module(void)
{
	int res_code = REG_VRE_MODULE_SUCCESS;
	
	if ((res_code = _vm_reg_module("TCP MODULE", 
		(MOD_EVT_PROCESS)sock_mod_evt_proc)) != REG_VRE_MODULE_SUCCESS)
	{
		vm_log_error("[TCP MODULE]Failed to regisiter tcp module. Error Code : %d", res_code);
	}

	return res_code;
}

VMINT vm_tcp_apn_exists(VMINT apn)
{
	VMINT i = 0, cmwap_idx = -1;
	operator_t ioperator = vm_get_operator();
    vm_apn_info current_apn_info;
    vm_tcp_apn_info *native_apn_info;

    VMCHAR ascii_apn[MAX_GPRS_APN_LEN];
	/* 
	 * 查询APN得到与当前卡的运营商和联网方式 匹配的
	 * GPRS帐号是否存在。
	 
	if ((apn_wstr = vm_malloc((MAX_GPRS_MMI_APN_LEN + 1) * ENCODING_LENGTH)) == NULL)
	{
		vm_log_warn("[TCP MODULE]PID[%d] HEAP memory is not enough.", 
			vm_pmng_get_current_handle());
		return FALSE;
	}*/

 	if ((native_apn_info = vm_calloc(sizeof(vm_tcp_apn_info))) == NULL)
	{
		vm_log_warn("[TCP MODULE]PID[%d] HEAP memory is not enough.", 
			vm_pmng_get_current_handle());
		return FALSE;
	}   
    memset(ascii_apn,0,MAX_GPRS_APN_LEN);

#ifdef VRE_GLOBAL_VERSION		
		if (vm_get_current_apn(&current_apn_info) < VM_APN_OK)
		{
			vm_log_warn("[TCP MODULE]Don't find apn.");
			vm_free(native_apn_info);
			return VM_TCP_ERR_CREATE_FAILED;	
		}	
		vm_log_warn("[GLOBAL] vm_get_current_apn in tcp_connect :current_apn_info apnproxy = %s",current_apn_info.apn_proxy);
		vm_log_warn("[GLOBAL] vm_get_current_apn in tcp_connect :current_apn_info apn_no_proxy = %s",current_apn_info.apn_no_proxy);
#endif    

	for (i = MAX_DATA_ACCOUNT_GSM_LIMIT; 
		i < (MAX_DATA_ACCOUNT_GPRS_LIMIT + MAX_DATA_ACCOUNT_GSM_LIMIT);
		i++)
	{
		mmi_dtcnt_get_apn_info(i, native_apn_info);
		
        vm_ucs2_to_ascii(ascii_apn,MAX_GPRS_APN_LEN,native_apn_info->apn);


#ifndef VRE_GLOBAL_VERSION		
		if (ioperator == CMCC)
		{
			if (vm_cmp_wstr_ignore_case(native_apn_info->apn, 
				(VMWSTR)(apn == VM_TCP_APN_CMWAP ? L"cmwap" : L"cmnet"), 6))
			{
				vm_free(native_apn_info);
				return TRUE;
			}
		}
		else if (ioperator == UNICOM)
		{
			if (vm_cmp_wstr_ignore_case(native_apn_info->apn, 
				(VMWSTR)(apn == VM_TCP_APN_CMWAP ? L"cmwap" : L"cmnet"), 6))
			{
				cmwap_idx = i;
			}
		
			if (vm_cmp_wstr_ignore_case(native_apn_info->apn, 
				(VMWSTR)(apn == VM_TCP_APN_CMWAP ? L"uniwap" : L"uninet"), 7))
			{
				vm_free(native_apn_info);
				return TRUE;
			}
		}
#else

			vm_log_warn("[GLOBAL] vm_get_current_apn in tcp_connect :apn_wstr = %s,len=%d",ascii_apn,strlen(current_apn_info.apn_proxy));

			if (apn == VM_TCP_APN_CMWAP )
			{
				if (vm_cmp_wstr_ignore_case(native_apn_info->apn, 
					(VMWSTR)(vm_ucs2_string_by_ascii(current_apn_info.apn_proxy)), strlen(current_apn_info.apn_proxy))
					&& (strlen(ascii_apn) == strlen(current_apn_info.apn_proxy))
					&&(vm_wstrlen(native_apn_info->apn) > 0))
				{
                    if (
                        (strncmp(native_apn_info->user_name, current_apn_info.wap_user_name, strlen(current_apn_info.wap_user_name)) == 0)
    					&& (strlen(native_apn_info->user_name) == strlen(current_apn_info.wap_user_name))
                        && (strncmp(native_apn_info->pass_word, current_apn_info.wap_pass_word, strlen(current_apn_info.wap_pass_word)) == 0)
    					&& (strlen(native_apn_info->pass_word) == strlen(current_apn_info.wap_pass_word))
                    )
                    {
                        vm_free(native_apn_info);
    					vm_log_warn("[GLOBAL] I'm VM_TCP_APN_CMWAP");
    					return TRUE;
                    }
				}
			}
			else
			{
				if (vm_cmp_wstr_ignore_case(native_apn_info->apn, 
					(VMWSTR)(vm_ucs2_string_by_ascii(current_apn_info.apn_no_proxy)), strlen(current_apn_info.apn_no_proxy))
					&& (strlen(ascii_apn) == strlen(current_apn_info.apn_no_proxy))
					&&(vm_wstrlen(native_apn_info->apn) > 0))					
				{
                    if (
                        (strncmp(native_apn_info->user_name, current_apn_info.net_user_name, strlen(current_apn_info.net_user_name)) == 0)
    					&& (strlen(native_apn_info->user_name) == strlen(current_apn_info.net_user_name))
                        && (strncmp(native_apn_info->pass_word, current_apn_info.net_pass_word, strlen(current_apn_info.net_pass_word)) == 0)
    					&& (strlen(native_apn_info->pass_word) == strlen(current_apn_info.net_pass_word))
                    )
                    {                    
                        vm_free(native_apn_info);
    					vm_log_warn("[GLOBAL] I'm VM_TCP_APN_CMNET");					
    					return TRUE;
                    }
				}
			}	
#endif

        
	}	

	vm_free(native_apn_info);
	if (ioperator == UNICOM && cmwap_idx != -1)
	{
		return TRUE;
	}

	
	return FALSE;
}





VMINT vm_tcp_apn_exists_no_query(VMINT apn,vm_apn_info *current_apn_info,VMINT *account_id)
{
    vm_tcp_apn_info *native_apn_info;
	VMINT i = 0, cmwap_idx = -1;
	operator_t ioperator = vm_get_operator();
    VMCHAR ascii_apn[MAX_GPRS_APN_LEN];
    vm_log_warn("[GLOBAL]-vm_tcp_apn_exists_no_query_internal ");
	/* 
	 * 查询APN得到与当前卡的运营商和联网方式 匹配的
	 * GPRS帐号是否存在。
	 */
    if (!current_apn_info)
        return FALSE;

    if ((strlen(current_apn_info->apn_proxy) == 0) && (apn == VM_TCP_APN_CMWAP))
    {
        vm_log_warn("[GLOBAL]-vm_tcp_apn_exists_no_query :VM_TCP_APN_CMWAP is empty");
        return FALSE;
    }
    if ((strlen(current_apn_info->apn_no_proxy) == 0) && (apn == VM_TCP_APN_CMNET))
    {
        vm_log_warn("[GLOBAL]-vm_tcp_apn_exists_no_query :VM_TCP_APN_CMNET is empty");
        return FALSE;
    }   
    
 	if ((native_apn_info = vm_calloc(sizeof(vm_tcp_apn_info))) == NULL)
	{
		vm_log_warn("[TCP MODULE]PID[%d] HEAP memory is not enough.", 
			vm_pmng_get_current_handle());
		return FALSE;
	}  
    showapninfo(current_apn_info,1);
    vm_log_warn("vm_tcp_apn_exists_no_query_internal:apn = %d",apn);
    memset(ascii_apn,0,MAX_GPRS_APN_LEN);
	for (i = MAX_DATA_ACCOUNT_GSM_LIMIT; 
		i < (MAX_DATA_ACCOUNT_GPRS_LIMIT + MAX_DATA_ACCOUNT_GSM_LIMIT);
		i++)
	{
        mmi_dtcnt_get_apn_info(i, native_apn_info);
		vm_ucs2_to_ascii(ascii_apn,MAX_GPRS_APN_LEN,native_apn_info->apn);
        vm_log_warn("[GLOBAL]-vm_tcp_apn_exists_no_query :apn_wstr{%d}=%s",i,ascii_apn);

#ifndef VRE_GLOBAL_VERSION		
		if (ioperator == CMCC)
		{
			if (vm_cmp_wstr_ignore_case(native_apn_info->apn, 
				(VMWSTR)(apn == VM_TCP_APN_CMWAP ? L"cmwap" : L"cmnet"), 6))
			{
				vm_free(native_apn_info);
               
				return TRUE;
			}
		}
		else if (ioperator == UNICOM)
		{
			if (vm_cmp_wstr_ignore_case(native_apn_info->apn, 
				(VMWSTR)(apn == VM_TCP_APN_CMWAP ? L"cmwap" : L"cmnet"), 6))
			{
				cmwap_idx = i;
			}
		
			if (vm_cmp_wstr_ignore_case(native_apn_info->apn, 
				(VMWSTR)(apn == VM_TCP_APN_CMWAP ? L"uniwap" : L"uninet"), 7))
			{
				vm_free(native_apn_info);
             
				return TRUE;
			}
		}
#else
        
		vm_log_warn("[GLOBAL] vm_tcp_apn_exists_no_query_internal :apn_wstr = %s,len=%d",ascii_apn,strlen(current_apn_info->apn_proxy));

		if (apn == VM_TCP_APN_CMWAP )
		{
			if (vm_cmp_wstr_ignore_case(native_apn_info->apn, 
				(VMWSTR)(vm_ucs2_string_by_ascii(current_apn_info->apn_proxy)), strlen(current_apn_info->apn_proxy))
					&& (strlen(ascii_apn) == strlen(current_apn_info->apn_proxy))
					&&(vm_wstrlen(native_apn_info->apn) > 0))
			{
                //vm_log_warn("i = %d",i);
                if (
                    (strncmp(native_apn_info->user_name, current_apn_info->wap_user_name, strlen(current_apn_info->wap_user_name)) == 0)
					&& (strlen(native_apn_info->user_name) == strlen(current_apn_info->wap_user_name))
                    && (strncmp(native_apn_info->pass_word, current_apn_info->wap_pass_word, strlen(current_apn_info->wap_pass_word)) == 0)
					&& (strlen(native_apn_info->pass_word) == strlen(current_apn_info->wap_pass_word))
                )
                {    
                    //vm_log_warn("i = %d",i);
                    vm_free(native_apn_info);
                    *account_id = i;                
    				vm_log_warn("[GLOBAL] I'm VM_TCP_APN_CMWAP");
    				return TRUE;
                }
                else
                    vm_log_warn("[GLOBAL] CMWAP Username or password doesn't match!");
			}
		}
		else
		{
			if (vm_cmp_wstr_ignore_case(native_apn_info->apn, 
				(VMWSTR)(vm_ucs2_string_by_ascii(current_apn_info->apn_no_proxy)), strlen(current_apn_info->apn_no_proxy))
				&& (strlen(ascii_apn) == strlen(current_apn_info->apn_no_proxy))
				&&(vm_wstrlen(native_apn_info->apn) > 0))
			{
                //vm_log_warn("i = %d",i);
                if (
                    (strncmp(native_apn_info->user_name, current_apn_info->net_user_name, strlen(current_apn_info->net_user_name)) == 0)
					&& (strlen(native_apn_info->user_name) == strlen(current_apn_info->net_user_name))
                    && (strncmp(native_apn_info->pass_word, current_apn_info->net_pass_word, strlen(current_apn_info->net_pass_word)) == 0)
					&& (strlen(native_apn_info->pass_word) == strlen(current_apn_info->net_pass_word))
                )
                {

                    //vm_log_warn("i = %d",i);
                    vm_free(native_apn_info);
                    *account_id = i;                
    				vm_log_warn("[GLOBAL] I'm VM_TCP_APN_CMNET");					
    				return TRUE;
                }
                else
                    vm_log_warn("[GLOBAL] CMWAP Username or password doesn't match!");                
			}
		}	
#endif

        
	}	

	vm_free(native_apn_info);
	if (ioperator == UNICOM && cmwap_idx != -1)
	{
		return TRUE;
	}

	
	return FALSE;
}



void vm_tcp_apn_exists_no_query_callback(VMINT tid)
{
    VMINT ret;
    VMINT wap_exist,net_exist;
    VMINT wap_account_id=0,net_account_id=0;    
    if (!vre_running)
        return;
    if (g_vre_is_ready_dataaccount == TRUE)
    {

        vm_delete_timer(tid);
        wap_exist = vm_tcp_apn_exists_no_query(VM_TCP_APN_CMWAP,vm_tcp_apn_info_timer,&wap_account_id);
        net_exist = vm_tcp_apn_exists_no_query(VM_TCP_APN_CMNET,vm_tcp_apn_info_timer,&net_account_id);
        if (wap_exist && net_exist)
            ret = VM_APN_ALL_IN_NATIVE_LIST;
        else if (!wap_exist && net_exist)
            ret = VM_APN_ONLY_NET_IN_NATIVE_LIST;
        else if (wap_exist && !net_exist)
            ret = VM_APN_ONLY_WAP_IN_NATIVE_LIST;
        else
            ret = VM_APN_NO_IN_NATIVE_LIST;         
        if (g_vre_tcp_check_ready_cb)
            g_vre_tcp_check_ready_cb(ret);
        g_vre_tcp_check_ready_cb = NULL;
        vm_tcp_apn_info_timer = NULL;
        return;        
    }    

}



void vm_global_check_apn_status(vm_apn_info *current_apn_info,vm_tcp_check_ready_callback cb)
{
    VMINT ret;
    ret = vm_get_current_apn(current_apn_info);
    if (ret < 0 )
    {
        if (cb)
            cb(ret);
        return;
    }
    g_vre_tcp_check_ready_cb = cb;
    vm_tcp_apn_info_timer = current_apn_info;
    
    vm_create_timer(VRE_DATAACCOUNT_READY_TIME, vm_tcp_apn_exists_no_query_callback); 
    return;
}



















VMINT vm_tcp_connect(const char* host, const VMINT port, const VMINT apn,
	void (*callback)(VMINT handle, VMINT event))
{
	VMINT account_id = 0, i = 0;
	operator_t ioperator = CMCC;
	vm_sock_context_t* context_ptr = NULL;
    VMCHAR ascii_apn[MAX_GPRS_APN_LEN];
	
 
	vm_log_debug("[TCP MODULE]tcp info: host=%s,port=%d,connect_type=%s", host, port, (apn == VM_TCP_APN_CMWAP ? "CMWAP" : (apn == VM_TCP_APN_CMNET ? "CMNET" : "WIFI")));

	// check mobile is in flight mode and wifi is connected
	if (mmi_bootup_get_active_flight_mode() == MMI_TRUE)
	{
		vm_log_error("[TCP MODULE]Phone is in flight mode.");
		return VM_TCP_ERR_CREATE_FAILED;
	}

	// check params 
	if (!host  || port <= 0 || !callback)
	{
		vm_log_error("[TCP MODULE]Failed to check params.");
		return VM_TCP_ERR_CREATE_FAILED;
	}

	// check apn
	if (stub_tcp_is_support_wifi())
	{
		if (apn != VM_TCP_APN_CMNET 
			&& apn != VM_TCP_APN_CMWAP && apn != VM_TCP_APN_WIFI)
		{
			vm_log_error("[TCP MODULE] Error apn = %d.", apn);
			return VM_TCP_ERR_CREATE_FAILED;
		}		
	}
	else
	{
		if (apn != VM_TCP_APN_CMNET && apn != VM_TCP_APN_CMWAP)
		{
			vm_log_error("[TCP MODULE] Error apn = %d.", apn);
			return VM_TCP_ERR_CREATE_FAILED;
		}
	}

	// 没有更多的资源 
	if ((context_ptr = vm_malloc_socket_context()) == NULL) 
	{
		vm_log_error("[TCP MODULE]Failed to alloc socket context.");
		return VM_TCP_ERR_NO_ENOUGH_RES;
	}
	memset(ascii_apn,0,MAX_GPRS_APN_LEN);
	context_ptr->port = port;
	context_ptr->callback = callback;

	if (stub_tcp_is_support_wifi() && VM_TCP_APN_WIFI == apn)
	{
		if (abm_bearer2nw_id(ABM_E_SOCKET_BEARER_WIFI, 
			0, (VMUINT *)&i) != KAL_TRUE)
		{
			vm_log_error("[TCP MODULE]Failed to set Wi-Fi bearer.");
			vm_free_socket_context(context_ptr);
			return VM_TCP_ERR_CREATE_FAILED;
		}

		account_id = cbm_encode_data_account_id(i, 0, cbm_app_id, 0);
		
		vm_log_debug("[TCP MODULE]WiFi account id = %d", account_id);
	}
	else
	{
		//VMWSTR apn_wstr = NULL;
		vm_tcp_apn_info *native_apn_info;
		VMINT cmwap_idx = -1;
		vm_apn_info current_apn_info;
	 
#ifdef WIN32
		ioperator = CMCC;
#else
		ioperator = vm_get_operator();
#endif

#ifndef VRE_GLOBAL_VERSION
		if (ioperator != CMCC && ioperator != UNICOM)
		{
			vm_log_warn("[TCP MODULE]unkown operator %d.", ioperator);
			vm_free_socket_context(context_ptr);
			return VM_TCP_ERR_CREATE_FAILED;
		}
#endif
		
     	if ((native_apn_info = vm_calloc(sizeof(vm_tcp_apn_info))) == NULL)
    	{
    		vm_log_warn("[TCP MODULE]PID[%d] HEAP memory is not enough.", 
    			vm_pmng_get_current_handle());
    		return FALSE;
    	}  
#ifdef VRE_GLOBAL_VERSION		
		if (vm_get_current_apn(&current_apn_info) < VM_APN_OK)
		{
			vm_log_warn("[TCP MODULE]Don't find apn.");
            vm_free(native_apn_info);
			vm_free_socket_context(context_ptr);
			return VM_TCP_ERR_CREATE_FAILED;	
		}	
		vm_log_warn("[GLOBAL] vm_get_current_apn in tcp_connect :current_apn_info apnproxy = %s",current_apn_info.apn_proxy);
		vm_log_warn("[GLOBAL] vm_get_current_apn in tcp_connect :current_apn_info apn_no_proxy = %s",current_apn_info.apn_no_proxy);
#endif 
		for (i = MAX_DATA_ACCOUNT_GSM_LIMIT; 
			i < (MAX_DATA_ACCOUNT_GPRS_LIMIT + MAX_DATA_ACCOUNT_GSM_LIMIT);
			i++)
		{
            mmi_dtcnt_get_apn_info(i, native_apn_info);
            vm_ucs2_to_ascii(ascii_apn,MAX_GPRS_APN_LEN,native_apn_info->apn);            
#ifndef VRE_GLOBAL_VERSION		
			if (ioperator == CMCC)
			{
				if (vm_cmp_wstr_ignore_case(native_apn_info->apn, 
					(VMWSTR)(apn == VM_TCP_APN_CMWAP ? L"cmwap" : L"cmnet"), 6))
				{
					account_id = vm_get_account_id(i, cbm_app_id);
					break;
				}
			}
			else
			{
				if (vm_cmp_wstr_ignore_case(native_apn_info->apn, 
					(VMWSTR)(apn == VM_TCP_APN_CMWAP ? L"cmwap" : L"cmnet"), 6))
				{
					account_id = vm_get_account_id(i, cbm_app_id);
					cmwap_idx = i;
				}
			
				if (vm_cmp_wstr_ignore_case(native_apn_info->apn, 
					(VMWSTR)(apn == VM_TCP_APN_CMWAP ? L"uniwap" : L"uninet"), 7))
				{
					account_id = vm_get_account_id(i, cbm_app_id);
					break;
				}				
			}
#else
			vm_log_warn("[GLOBAL] vm_get_current_apn in tcp_connect :apn_wstr = %s,len=%d",ascii_apn,strlen(current_apn_info.apn_proxy));

			if (apn == VM_TCP_APN_CMWAP )
			{
				if (vm_cmp_wstr_ignore_case(native_apn_info->apn, 
					(VMWSTR)(vm_ucs2_string_by_ascii(current_apn_info.apn_proxy)), strlen(current_apn_info.apn_proxy))
    				&& (strlen(ascii_apn) == strlen(current_apn_info.apn_proxy))
    				&&(vm_wstrlen(native_apn_info->apn) > 0))
				{


                    if (
                        (strncmp(native_apn_info->user_name, current_apn_info.wap_user_name, strlen(current_apn_info.wap_user_name)) == 0)
    					&& (strlen(native_apn_info->user_name) == strlen(current_apn_info.wap_user_name))
                        && (strncmp(native_apn_info->pass_word, current_apn_info.wap_pass_word, strlen(current_apn_info.wap_pass_word)) == 0)
    					&& (strlen(native_apn_info->pass_word) == strlen(current_apn_info.wap_pass_word))
                    )
                    {
                        account_id = vm_get_account_id(i, cbm_app_id);
            			vm_log_warn("[GLOBAL] I'm VM_TCP_APN_CMWAP");
            			break;
                    }
				}
			}
			else
			{
				if (vm_cmp_wstr_ignore_case(native_apn_info->apn, 
					(VMWSTR)(vm_ucs2_string_by_ascii(current_apn_info.apn_no_proxy)), strlen(current_apn_info.apn_no_proxy))
    				&& (strlen(ascii_apn) == strlen(current_apn_info.apn_no_proxy))
    				&&(vm_wstrlen(native_apn_info->apn) > 0))
				{
                    if (
                        (strncmp(native_apn_info->user_name, current_apn_info.net_user_name, strlen(current_apn_info.net_user_name)) == 0)
    					&& (strlen(native_apn_info->user_name) == strlen(current_apn_info.net_user_name))
                        && (strncmp(native_apn_info->pass_word, current_apn_info.net_pass_word, strlen(current_apn_info.net_pass_word)) == 0)
    					&& (strlen(native_apn_info->pass_word) == strlen(current_apn_info.net_pass_word))
                    )
                    {
    					account_id = vm_get_account_id(i, cbm_app_id);
    					vm_log_warn("[GLOBAL] I'm VM_TCP_APN_CMNET");					
    					break;
                    }
				}
			}	
#endif
		}
		vm_free(native_apn_info);
		// 没有找到适合的APN帐号，则返回失败。
		if (i >= (MAX_DATA_ACCOUNT_GPRS_LIMIT + MAX_DATA_ACCOUNT_GSM_LIMIT))
		{
			if (ioperator != UNICOM || cmwap_idx == -1)
			{
				vm_log_warn("[TCP MODULE]Don't find account.");
				vm_free_socket_context(context_ptr);
				return VM_TCP_ERR_CREATE_FAILED;	
			}
		}
	}

	if ((context_ptr->sock = soc_create(PF_INET, SOCK_STREAM, 0, MOD_MMI, account_id)) >= 0)
	{
		kal_uint8 val = 1;

		vm_log_debug("[TCP MODULE]TCP[%d] is created by GPRS accound[%d].", context_ptr->sock, 
			account_id);
		if (soc_setsockopt(context_ptr->sock, SOC_NBIO, &val, sizeof(val)) < 0)
		{
			soc_close(context_ptr->sock);
			vm_free_socket_context(context_ptr);

			vm_log_error("[TCP MODULE]Failed to set socket option(non block).");
		}
		else
		{	
			val = SOC_READ | SOC_WRITE | SOC_CLOSE | SOC_CONNECT;
			if (soc_setsockopt(context_ptr->sock, SOC_ASYNC, &val, sizeof(val)) < 0)
			{
				soc_close(context_ptr->sock);
				vm_free_socket_context(context_ptr);

				vm_log_error("[TCP MODULE]Failed to set socket option(read/write/close/connect).");
			}
			else											// 开始连接过程
			{
				sockaddr_struct addr;				// connect 地址

				memset(&addr, 0x00, sizeof(addr));
				if (apn == VM_TCP_APN_CMWAP) 	// cmwap 连接
				{
					kal_char* host_name  = vm_malloc(strlen(host) + 1);
					kal_bool is_ip_valid = KAL_FALSE;
					kal_uint8 buf[4];
					
					if (!host_name)
					{
						vm_free_socket_context(context_ptr);
						return VM_TCP_ERR_CREATE_FAILED;
					}
					memset(buf, 0x00, sizeof(buf));
					memset(host_name, 0x00, strlen(host) + 1);
					strcpy(host_name, host);
				
					if (soc_ip_check(host_name, addr.addr, &is_ip_valid) == KAL_FALSE)
					{
						vm_free(host_name);
						vm_free_socket_context(context_ptr);
						return VM_TCP_ERR_CREATE_FAILED;
					}
					else if (is_ip_valid == KAL_FALSE)
					{
						vm_free(host_name);
						vm_free_socket_context(context_ptr);
						return VM_TCP_ERR_CREATE_FAILED;
					}
					else
					{
						vm_free(host_name);
						addr.addr_len = 4;
						addr.port = port;
					}					
				}
				else								// cmnet 连接
				{
					kal_uint8 buf[4], addr_len = 0;
					kal_int8 ret = -1;
					kal_bool is_ip_valid = KAL_FALSE;
					kal_char* host_name  = vm_malloc(strlen(host) + 1);

					if (!host_name)
					{
						vm_free_socket_context(context_ptr);
						return VM_TCP_ERR_CREATE_FAILED;
					}
					memset(buf, 0x00, sizeof(buf));
					memset(host_name, 0x00, strlen(host) + 1);
					strcpy(host_name, host);
					
					if (soc_ip_check(host_name, addr.addr, &is_ip_valid) == KAL_FALSE)
					{
						// 是主机名而非ip地址 
						vm_free(host_name);
						ret = soc_gethostbyname(KAL_FALSE, MOD_MMI, context_ptr->sock, 
							host, buf, &addr_len, 0, account_id); //这里的request id 就是socket id。
					    vm_log_error("ret = %d, account_id = %d, host_name = %s, socket = %d", ret, account_id, host, context_ptr->sock);
						if (ret == SOC_SUCCESS)				// success
						{
							addr.addr[0] = buf[0];    
							addr.addr[1] = buf[1];
							addr.addr[2] = buf[2];
							addr.addr[3] = buf[3];
							addr.addr_len = addr_len;
							addr.port = port;						
						}
						else if (ret == SOC_WOULDBLOCK)			// block
						{
							context_ptr->socket_state = conn_host_by_name;
							//SetProtocolEventHandler(vm_get_host_by_name, MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND);
#if defined(__VRE_RB_08A__)
							mmi_frm_set_protocol_event_handler((PsFuncPtr)vm_get_host_by_name,MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND);								
#elif defined(__VRE_RB_08B__)
							mmi_frm_set_protocol_event_handler(MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND, (PsFuncPtr)vm_get_host_by_name, MMI_TRUE);							
#else
							mmi_frm_set_protocol_event_handler(MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND, (PsIntFuncPtr)vm_get_host_by_name, MMI_TRUE);			
#endif
							vm_log_debug("[TCP MODULE]Socket is in get hostbyname state.socket is %d", context_ptr->sock);
							return context_ptr->sock;
						}
						else									// error
						{
							soc_close(context_ptr->sock);
							vm_free_socket_context(context_ptr);

							vm_log_error("[TCP MODULE]Failed to get host by name.");
							return VM_TCP_ERR_CREATE_FAILED;
						}
					}
					else if (is_ip_valid == KAL_FALSE)	
					{
						// 非法的ip 地址 
						vm_free(host_name);
						soc_close(context_ptr->sock);
						vm_free_socket_context(context_ptr);
						return VM_TCP_ERR_CREATE_FAILED;
					}
					else
					{
						vm_free(host_name);
						addr.addr_len = 4;
						addr.port = port;
						vm_log_debug("[TCP MODULE]host is ip address.");
					}
				}	

				// 对于cmnet ，只有在get_host_by_name成功后才可能走连接过程。 
				switch (soc_connect(context_ptr->sock, &addr))
				{
					case SOC_SUCCESS:
					case SOC_WOULDBLOCK:
						//SetProtocolEventHandler(vm_soc_notify, MSG_ID_APP_SOC_NOTIFY_IND);
#if defined(__VRE_RB_08A__)
						mmi_frm_set_protocol_event_handler((PsFuncPtr)vm_soc_notify,MSG_ID_APP_SOC_NOTIFY_IND);
#elif defined(__VRE_RB_08B__)
						mmi_frm_set_protocol_event_handler(MSG_ID_APP_SOC_NOTIFY_IND, (PsFuncPtr)vm_soc_notify, MMI_TRUE);							
#else
						mmi_frm_set_protocol_event_handler(MSG_ID_APP_SOC_NOTIFY_IND, (PsIntFuncPtr)vm_soc_notify, MMI_TRUE);			
#endif
						vm_log_debug("[TCP MODULE]TCP[%d] is waited to connect.", context_ptr->sock);
						return context_ptr->sock;
					default:
						soc_close(context_ptr->sock);
						vm_free_socket_context(context_ptr);
						break;
				}
			}
		}
	}
	else
	{
		soc_close(context_ptr->sock);
		vm_free_socket_context(context_ptr);
		
		vm_log_error("[TCP MODULE]Failed to create socket.");
	}

	return VM_TCP_ERR_CREATE_FAILED;
}

void vm_tcp_close(VMINT handle)
{
	vm_sock_context_t* socketContext = NULL;
	VM_P_HANDLE pHandle = vm_pmng_get_current_handle();

	if ((socketContext = vm_get_socket_context(handle)) != NULL
		&& vm_res_get_process_handle(VM_RES_TYPE_TCP_HANDLE, socketContext->res_handle) == pHandle)
	{
		if (socketContext->socket_state <= conn_connected 
			|| socketContext->socket_state == conn_unkown)
		{
			if (socketContext->socket_state == conn_host_by_name)
			{
				soc_abort_dns_query(KAL_TRUE, MOD_MMI, KAL_TRUE, handle, 
					KAL_FALSE, 0, KAL_FALSE, 0);
				vm_log_debug("[TCP MODULE]Abort tcp[%d] dns query operation.", handle);
			}
			vm_log_debug("[TCP MODULE]TCP[%d] closed", handle);
			soc_close((kal_int8)handle);
			vm_free_socket_context(socketContext);
			return;
		}
	}
}

VMINT vm_tcp_read(VMINT handle, void* buf, VMINT len)
{
	kal_int32 ret = 0;
	vm_sock_context_t* context_ptr = NULL;

	if (!buf || len <= 0)
	{
		return 0;
	}

	if ((context_ptr = vm_get_socket_context(handle)) == NULL) 
	{
		return (VM_TCP_READ_EOF  -2);
	}
	
	if (context_ptr->socket_state != conn_connected || context_ptr->read_pipe_state <= read_block)
	{
		vm_log_debug("[TCP MODULE]TCP[%d] can't read data.", handle);
		return 0; 
	}

	if ((ret = soc_recv(context_ptr->sock, (kal_uint8*)buf, len, 0)) <= 0)
	{
		if (ret == SOC_WOULDBLOCK)
		{
			vm_log_debug("[TCP MODULE]TCP[%d] read block.", handle);
			context_ptr->read_pipe_state = read_block;
			return 0;
		}
		else if (ret == 0)
		{
			vm_log_debug("[TCP MODULE]TCP[%d] receive FIN.", handle);
			return VM_TCP_READ_EOF;
		}
		else
		{
			vm_log_warn("[TCP MODULE]TCP[%d] read data error.", handle);
			return (VM_TCP_READ_EOF - 1);
		}
	}
	else
	{
		vm_log_debug("[TCP MODULE]TCP[%d] read data %d bytes.", 
			handle, ret);
	}
	return ret;
}

VMINT vm_tcp_write(VMINT handle, void* buf, VMINT len)
{
	vm_sock_context_t* context_ptr = NULL;
	kal_int32 ret = 0;

	if (!buf || len <= 0)
	{
		return 0;
	}

	if ((context_ptr = vm_get_socket_context(handle)) == NULL)
	{
		return -1;
	}
	
	if (context_ptr->socket_state != conn_connected || context_ptr->write_pipe_state <= write_block)
	{
		vm_log_debug("[TCP MODULE]TCP[%d] can't write data.", handle);
		return 0;
	}

	if ((ret = soc_send(context_ptr->sock, (kal_uint8*)buf, len, 0)) < 0)
	{
		if (ret == SOC_WOULDBLOCK)
		{
			vm_log_debug("[TCP MODULE]TCP[%d] write block.", handle);
			context_ptr->write_pipe_state = write_block;
			return 0;
		}
		else
		{
			vm_log_warn("[TCP MODULE]TCP[%d] write data error.", handle);
			return -1;
		}
	}
	else
	{
		vm_log_debug("[TCP MODULE]TCP[%d] write data %d bytes.", handle, ret);
	}
	
	return ret;
}

static MMI_BOOL  vm_soc_notify(void* inMsg)
{
	vm_sock_context_t* context_ptr = NULL;
	void (*notify_callback)(VMINT handle, VMINT event) = NULL;
	VM_P_HANDLE processHandle = 0;
	
	app_soc_notify_ind_struct* ind = (app_soc_notify_ind_struct*)inMsg;

	/* 防止对指向null 的指针的操作 */
	if (!ind)					
	{
		vm_log_warn("[TCP MODULE]MTK socket notify callback function param error.");
		return MMI_FALSE;
	}

	if ((context_ptr = vm_get_socket_context(ind->socket_id)) != NULL)
	{
		/* 得到进程句柄。 */
		processHandle = vm_res_get_process_handle(VM_RES_TYPE_TCP_HANDLE, 
			context_ptr->res_handle);
		
		
		vm_log_debug("[TCP MODULE]PCB[%d] of TCP[%d] receive %d message, res handle=%d", 
			processHandle, context_ptr->sock, ind->event_type, context_ptr->res_handle);
	
		switch (ind->event_type)
		{
		case SOC_WRITE:
			context_ptr->write_pipe_state = write_notify;
			
			
			if (context_ptr->callback && context_ptr->socket_state == conn_connected)
			{
				vm_log_debug("[TCP MODULE]TCP[%d] can write callback.", context_ptr->sock);

				if (processHandle != 0)
				{
					PMNG_WRAP_CALLBACK(processHandle, 
						context_ptr->callback(context_ptr->sock, VM_TCP_EVT_CAN_WRITE));
				}
				else
				{
					context_ptr->callback(context_ptr->sock, VM_TCP_EVT_CAN_WRITE);
				}
			}
			break;
		case SOC_READ:
			context_ptr->read_pipe_state= read_notify;
			if (context_ptr->callback && context_ptr->socket_state == conn_connected)
			{
				vm_log_debug("[TCP MODULE]TCP[%d] can read callback.", 
					context_ptr->sock);

				if (processHandle != 0)
				{
					PMNG_WRAP_CALLBACK(processHandle, 
						context_ptr->callback(context_ptr->sock, VM_TCP_EVT_CAN_READ));
				}
				else
				{
					context_ptr->callback(context_ptr->sock, VM_TCP_EVT_CAN_READ);
				}
			}
			break;
		case SOC_CONNECT:
			if (ind->result != FALSE)
			{
				vm_log_debug("[TCP MODULE]TCP[socket = %d] connected", ind->socket_id);
				context_ptr->socket_state = conn_connected;
				context_ptr->read_pipe_state = read_notify;
				context_ptr->write_pipe_state = write_notify;

				if (context_ptr->callback)
				{
					vm_log_debug("[TCP MODULE]TCP[%d] connected callback.", 
						context_ptr->sock);
					if (processHandle != 0)
					{
						PMNG_WRAP_CALLBACK(processHandle, 
							context_ptr->callback(context_ptr->sock, VM_TCP_EVT_CONNECTED));
					}
					else
					{
						context_ptr->callback(context_ptr->sock, VM_TCP_EVT_CONNECTED);
					}
				}
			}
			else
			{
				notify_callback = context_ptr->callback;
				vm_free_socket_context(context_ptr);
				soc_close(ind->socket_id);

				if (notify_callback)
				{
					vm_log_debug("[TCP MODULE]Failed to connected. TCP[%d] callback.", ind->socket_id);
					if (processHandle != 0)
					{
						PMNG_WRAP_CALLBACK(processHandle, 
							notify_callback(ind->socket_id, VM_TCP_EVT_PIPE_BROKEN));
					}
					else
					{
						notify_callback(ind->socket_id, VM_TCP_EVT_PIPE_BROKEN);
					}
				}
			}
			break;
		case SOC_CLOSE:
			notify_callback = context_ptr->callback;
			vm_free_socket_context(context_ptr);
			soc_close(ind->socket_id);
				
			if (notify_callback)
			{
				vm_log_debug("[TCP MODULE]TCP[%d] closed callback.", ind->socket_id);
				if (processHandle != 0)
				{
					PMNG_WRAP_CALLBACK(processHandle, 
						notify_callback(ind->socket_id, VM_TCP_EVT_PIPE_CLOSED));
				}
				else
				{
					notify_callback(ind->socket_id, VM_TCP_EVT_PIPE_CLOSED);
				}
			}			
			break;
		default:
			vm_log_warn("[TCP MODULE]Unkown sock evt, value is :%d", ind->event_type);
		}

		return MMI_TRUE;
	}
	
	return MMI_FALSE;
}

static MMI_BOOL vm_get_host_by_name(void* inMsg)
{
	vm_sock_context_t* context_ptr = NULL;
	void (*notify_callback)(VMINT handle, VMINT event) = NULL;
	app_soc_get_host_by_name_ind_struct* dns_ind = (app_soc_get_host_by_name_ind_struct*)inMsg;
	
	if (dns_ind && dns_ind->result != FALSE)
	{
		sockaddr_struct addr;

		if ((context_ptr = vm_get_socket_context(dns_ind->request_id)) != NULL) 									
		{
			VM_P_HANDLE processHandle = vm_res_get_process_handle(
				VM_RES_TYPE_TCP_HANDLE, context_ptr->res_handle);
		
			if(context_ptr->socket_state != conn_host_by_name)
			{
				/* 当前的状态不为get host by name 状态。 	*/
				vm_log_warn("[TCP MODULE]Socket %d has error connection state: %d, but in conn_host_by_name state.", 
					dns_ind->request_id, context_ptr->socket_state);
				return MMI_TRUE;
			}

			memset(&addr, 0x00, sizeof(addr));
			memcpy(addr.addr, dns_ind->addr, dns_ind->addr_len);
			addr.addr_len = dns_ind->addr_len;
			addr.port = context_ptr->port;

			switch (soc_connect(context_ptr->sock, &addr))
			{
			case SOC_SUCCESS:
			case SOC_WOULDBLOCK:
				//mmi_frm_set_protocol_event_handler(MSG_ID_APP_SOC_NOTIFY_IND, (PsIntFuncPtr)vm_soc_notify, MMI_TRUE);
#if defined(__VRE_RB_08A__)
				mmi_frm_set_protocol_event_handler((PsFuncPtr)vm_soc_notify,MSG_ID_APP_SOC_NOTIFY_IND);
#elif defined(__VRE_RB_08B__)
				mmi_frm_set_protocol_event_handler(MSG_ID_APP_SOC_NOTIFY_IND, (PsFuncPtr)vm_soc_notify, MMI_TRUE);					
#else
				mmi_frm_set_protocol_event_handler(MSG_ID_APP_SOC_NOTIFY_IND, (PsIntFuncPtr)vm_soc_notify, MMI_TRUE);			
#endif

				break;
			default:
				notify_callback = context_ptr->callback;
				vm_free_socket_context(context_ptr);
				soc_close((kal_int8)dns_ind->request_id);
				
				if (notify_callback)
				{
					if (processHandle > 0)
					{
						PMNG_WRAP_CALLBACK(processHandle, 
							notify_callback((kal_int8)dns_ind->request_id, VM_TCP_EVT_PIPE_BROKEN));
					}
					else if (processHandle == 0)
					{
						notify_callback((kal_int8)dns_ind->request_id, VM_TCP_EVT_PIPE_BROKEN);
					}
					else
					{
						vm_log_error("[TCP MODULE]Error Process handle[%d].", processHandle);
					}
				}				
				break;
			}

			return MMI_TRUE;
		}
	}
	else								// dns analyse error.
	{
		if (dns_ind)
		{
			vm_log_error("[TCP MODULE]Failed to get host by name, socket id is :%d, error_cause :%d, detail_cause :%d", dns_ind->request_id,
                dns_ind->error_cause, dns_ind->detail_cause);
			if ((context_ptr = vm_get_socket_context(dns_ind->request_id)) != NULL)
			{
				VM_P_HANDLE processHandle = vm_res_get_process_handle(
					VM_RES_TYPE_TCP_HANDLE, context_ptr->res_handle);
				
				notify_callback = context_ptr->callback;
				vm_free_socket_context(context_ptr);
				soc_close((kal_int8)dns_ind->request_id);
				
				if (notify_callback)
				{
					if (processHandle > 0)
					{
						PMNG_WRAP_CALLBACK(processHandle, 
							notify_callback((kal_int8)dns_ind->request_id, 
							VM_TCP_EVT_HOST_NOT_FOUND));
					}
					else if (processHandle == 0)
					{
						notify_callback((kal_int8)dns_ind->request_id, 
							VM_TCP_EVT_HOST_NOT_FOUND);
					}
					else
					{
						vm_log_error("[TCP MODULE]Error Process handle[%d].", 
							processHandle);
					}
				}

				return MMI_TRUE;
			}
		}
	}

	return MMI_FALSE;
}










#define DTCNT_MAX_ACCT_ALLOCATED 0xff
#define VRE_SET_GPRS_ACCT_1 (1)
#define VRE_SET_GPRS_ACCT_2 (2)
#define FIRST_RECORD_EDIT_POS (MAX_DATA_ACCOUNT_GPRS_LIMIT - 1)


extern GPRSDataAccountNode g_GPRS_DataAccount[];
extern DataAccountNodeDisplay g_DataAccount_Display;


vre_gprs_acct_set_done_callback am_set_gprs_acct_callback = NULL;
vm_apn_info cb_apn_info;
VMINT current_apn;
VMINT vre_first_data_account_pos = -1;

#ifndef __VRE_RB_08B__
extern void DTCNTReenterList(void);
extern void mmi_dtcnt_arrange_acct_list(DataAccountNode * GSM_list, GPRSDataAccountNode *GPRS_list, DATA_ACCOUNT_ARRANGE_TYPE_ENUM type);
extern void mmi_dtcnt_delete_notify(dtcnt_list_bearer_enum bearer_type, U8 disp_index);
extern void mmi_dtcnt_rectify_GPRS_account_buffer(void);
#endif

static void vre_gprs_add_gprs_account_second(void);



static void showGPRSDataAccount(VMINT id)
{
#if 0
    VMINT i;
	for (i = 0;i < (MAX_DATA_ACCOUNT_GPRS_LIMIT);	i++)
    {
        vm_log_fatal("[GPRS APN%d]:==========================================================",id);  
        vm_log_fatal("[GPRS APN%d]:g_GPRS_DataAccount[%d].Present = %c",id,i,g_GPRS_DataAccount[i].Present);  
        vm_log_fatal("[GPRS APN%d]:g_GPRS_DataAccount[%d].org_acct_id = %d",id,i,g_GPRS_DataAccount[i].org_acct_id);
        vm_log_fatal("[GPRS APN%d]:g_GPRS_DataAccount[%d].DataAccountName = %s",id,i,vm_gb2312_string((VMWSTR)g_GPRS_DataAccount[i].DataAccountName));
        vm_log_fatal("[GPRS APN%d]:g_GPRS_DataAccount[%d].napid_hash_val = %s",id,i,g_GPRS_DataAccount[i].napid_hash_val);        
        vm_log_fatal("[GPRS APN%d]:g_GPRS_DataAccount[%d].provurl_hash_val = %s",id,i,g_GPRS_DataAccount[i].provurl_hash_val);
        vm_log_fatal("[GPRS APN%d]:g_GPRS_DataAccount[%d].acct_type = %d",id,i,g_GPRS_DataAccount[i].acct_type);
        vm_log_fatal("[GPRS APN%d]:g_GPRS_DataAccount[%d].readonly = %d",id,i,g_GPRS_DataAccount[i].readonly);
        vm_log_fatal("[GPRS APN%d]:g_GPRS_DataAccount[%d].APN = %s",id,i,vm_gb2312_string((VMWSTR)g_GPRS_DataAccount[i].APN));
        vm_log_fatal("[GPRS APN%d]:g_GPRS_DataAccount[%d].AuthType = %d",id,i,g_GPRS_DataAccount[i].AuthType);
        vm_log_fatal("[GPRS APN%d]:g_GPRS_DataAccount[%d].UserName = %s",id,i,g_GPRS_DataAccount[i].UserName);
        vm_log_fatal("[GPRS APN%d]:g_GPRS_DataAccount[%d].Passwd = %s",id,i,g_GPRS_DataAccount[i].Passwd);        
        vm_log_fatal("[GPRS APN%d]:g_GPRS_DataAccount[%d].DnsAddress1 = %d",id,i,g_GPRS_DataAccount[i].DnsAddress[0]);
        vm_log_fatal("[GPRS APN%d]:g_GPRS_DataAccount[%d].DnsAddress2 = %d",id,i,g_GPRS_DataAccount[i].DnsAddress[1]);        
        vm_log_fatal("[GPRS APN%d]:g_GPRS_DataAccount[%d].DnsAddress3 = %d",id,i,g_GPRS_DataAccount[i].DnsAddress[2]);
        vm_log_fatal("[GPRS APN%d]:g_GPRS_DataAccount[%d].DnsAddress4 = %d",id,i,g_GPRS_DataAccount[i].DnsAddress[3]);        
        vm_log_fatal("[GPRS APN%d]:g_GPRS_DataAccount[%d].ViceDnsAddress = %s",id,i,g_GPRS_DataAccount[i].ViceDnsAddress);
        vm_log_fatal("[GPRS APN%d]:g_GPRS_DataAccount[%d].iFdcs = %d",id,i,g_GPRS_DataAccount[i].iFdcs);      
        vm_log_fatal("[GPRS APN%d]:==========================================================");
    }
#endif
}



static U8 vre_gprs_allocate_acct_id(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j;
#ifndef __VRE_RB_08B__
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i = 0; i < MAX_DATA_ACCOUNT_GPRS_LIMIT; i++)
    {    
        for(j = 0; j < g_DataAccount_Display.GPRS_acct_num; j++)
        {
            if (i == g_GPRS_DataAccount[j].org_acct_id)
            {
                break;
            }
        }
        if (j == g_DataAccount_Display.GPRS_acct_num)
        {
            return i;
        }
    }
    return DTCNT_MAX_ACCT_ALLOCATED;
#else
	return FIRST_RECORD_EDIT_POS;	
#endif
}


static U8 vre_gprs_find_acct_id(VMINT apn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 bearer;
    kal_uint8 id;   /* dummy */

    VMINT i,j;
#ifndef __VRE_RB_08B__
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for (i = MAX_DATA_ACCOUNT_GSM_LIMIT; 
		i < (MAX_DATA_ACCOUNT_GPRS_LIMIT + MAX_DATA_ACCOUNT_GSM_LIMIT);
		i++)    
    {      
        if (abm_nw2bearer_id(i, &bearer, &id) == KAL_TRUE)
        {
            //vm_log_warn("abm_nw2bearer_id (%d id) = %d,%d",i,id,bearer);
            if(bearer == ABM_E_SOCKET_BEARER_GSM_GPRS)
            {
                for(j = 0; j < g_DataAccount_Display.GPRS_acct_num; j++)
                {
                	if (id - 1 == g_GPRS_DataAccount[j].org_acct_id)
                	{
                        if (apn == VM_TCP_APN_CMWAP)
                        {
                            if (mmi_ucs2cmp((S8*) vm_ucs2_string(cb_apn_info.apn_no_proxy),(S8*) g_GPRS_DataAccount[j].APN) == 0)
                            {
                                
                                vm_log_warn("[AUTO APN]g_GPRS_DataAccount[%d].org_acct_id = %d",j,g_GPRS_DataAccount[j].org_acct_id);
                                return g_GPRS_DataAccount[j].org_acct_id;
                            }
                                
                        }
                        else
                        {
                            if (mmi_ucs2cmp((S8*) vm_ucs2_string(cb_apn_info.apn_proxy),(S8*) g_GPRS_DataAccount[j].APN) == 0)
                            {
                                
                                vm_log_warn("[AUTO APN]g_GPRS_DataAccount[%d].org_acct_id = %d",j,g_GPRS_DataAccount[j].org_acct_id);
                                return g_GPRS_DataAccount[j].org_acct_id;
                            }
                        }                        
                	}
                }
            }
        }
    }
    return DTCNT_MAX_ACCT_ALLOCATED;
#else
	for (i = MAX_DATA_ACCOUNT_GSM_LIMIT; 
		i < (MAX_DATA_ACCOUNT_GPRS_LIMIT + MAX_DATA_ACCOUNT_GSM_LIMIT);
		i++)  
    {      
        if (abm_nw2bearer_id(i, &bearer, &id) == KAL_TRUE)
        {
            if(bearer == ABM_E_SOCKET_BEARER_GSM_GPRS)
            {
                if (apn == VM_TCP_APN_CMWAP)
                {
                    if (mmi_ucs2cmp((S8*) vm_ucs2_string(cb_apn_info.apn_no_proxy),(S8*) g_GPRS_DataAccount[id-1].APN) == 0)
                    {
                        
                        return (id-1);
                    }
                        
                }
                else
                {
                    if (mmi_ucs2cmp((S8*) vm_ucs2_string(cb_apn_info.apn_proxy),(S8*) g_GPRS_DataAccount[id-1].APN) == 0)
                    {
                        
                        return (id-1);
                    }
                }   
            }
        }
    }
    return DTCNT_MAX_ACCT_ALLOCATED;
#endif
}

BOOL mmi_dtcnt_get_apn_info(U32 account_id, vm_tcp_apn_info *dest)
{
#ifdef __MMI_GPRS_FEATURES__
    kal_uint8 bearer;
    kal_uint8 id;   /* dummy */
    U8 i;

    if(!dest)
    {
        return FALSE;
    }

    if (abm_nw2bearer_id(account_id, &bearer, &id) == KAL_TRUE)
    {
        if(bearer == ABM_E_SOCKET_BEARER_GSM_GPRS)
        {
#ifndef __VRE_RB_08B__        
        #ifdef __MMI_OP01_GPRS_DATACFG__
        #else
            for(i = 0; i < g_DataAccount_Display.GPRS_acct_num; i++)
        #endif
            {
            	if (id - 1 == g_GPRS_DataAccount[i].org_acct_id)
            	{
                    mmi_ucs2ncpy((kal_char *)dest->apn, (kal_char *)g_GPRS_DataAccount[i].APN, MAX_GPRS_APN_LEN);
                    strncpy((kal_char *)dest->user_name, (kal_char *)g_GPRS_DataAccount[i].UserName, MAX_GPRS_USER_NAME_LEN);
                    strncpy((kal_char *)dest->pass_word, (kal_char *)g_GPRS_DataAccount[i].Passwd, MAX_GPRS_PASSWORD_LEN);                    
                    return TRUE;
            	}
            }
#else
            mmi_ucs2ncpy((kal_char *)dest->apn, (kal_char *)g_GPRS_DataAccount[id-1].APN, MAX_GPRS_APN_LEN);
            strncpy((kal_char *)dest->user_name, (kal_char *)g_GPRS_DataAccount[id-1].UserName, MAX_GPRS_USER_NAME_LEN);
            strncpy((kal_char *)dest->pass_word, (kal_char *)g_GPRS_DataAccount[id-1].Passwd, MAX_GPRS_PASSWORD_LEN);
			return TRUE;			
#endif			
        }
    }
    memset(dest, 0, sizeof(vm_tcp_apn_info));
    return FALSE;
#else
    return FALSE;
#endif /* __MMI_GPRS_FEATURES__ */ 
}








//======================================================================================================================
#ifdef  __VRE_RB_08B__
static void mtk_dtcnt_gprs_set_account_rsp(mmi_ps_set_gprs_data_account_rsp_struct *localPtr)
{

#ifdef __MMI_GPRS_FEATURES__
    if (localPtr->result == KAL_TRUE /* OK */ )
    {
        g_GPRS_DataAccount[g_DataAccount_Display.GPRSCurrSelectItem].Present = 'P';
	    return;
    }
#endif /* __MMI_GPRS_FEATURES__ */ 
}

#else
static void mtk_dtcnt_gprs_set_account_rsp(mmi_ps_set_gprs_data_account_rsp_struct *localPtr)
{
#ifdef __MMI_GPRS_FEATURES__
    g_DataAccount_Display.profile_setted = 1;
    if (g_DataAccount_Display.set_type == MMI_DTCNT_GPRS_PROFILE_EDIT)
    {
      	if (localPtr->result == KAL_TRUE  )
       	{
            g_GPRS_DataAccount[g_DataAccount_Display.CurrSelectItem].Present = 'P';
            mmi_dtcnt_arrange_acct_list(NULL, g_GPRS_DataAccount, ARRANGE_ACCT_TYPE_ALPHABET);
            g_DataAccount_Display.GPRSCurrSelectItem = 0;
       	}
       	else
       	{
            mmi_dtcnt_ready_check_on_background(DTCNTReenterList);
       	}
    }
    else if (g_DataAccount_Display.set_type == MMI_DTCNT_GPRS_PROFILE_ADD)
    {
       	if (localPtr->result == KAL_TRUE )
       	{
                g_GPRS_DataAccount[g_DataAccount_Display.GPRS_acct_num].Present = 'P';
                g_DataAccount_Display.GPRS_acct_num++;
                mmi_dtcnt_arrange_acct_list(NULL, g_GPRS_DataAccount, ARRANGE_ACCT_TYPE_ALPHABET);
                g_DataAccount_Display.GPRSCurrSelectItem = 0;
        }
    	else
    	{
            mmi_dtcnt_ready_check_on_background(DTCNTReenterList);
    	}
          
    }
    else if (g_DataAccount_Display.set_type == MMI_DTCNT_GPRS_PROFILE_DELETE)
    {
        if (localPtr->result == KAL_TRUE )
        {
            mmi_dtcnt_delete_notify(DTCNT_LIST_BEARER_GPRS, g_DataAccount_Display.GPRSCurrSelectItem);
            memset(&g_GPRS_DataAccount[g_DataAccount_Display.GPRSCurrSelectItem], 0, sizeof(DataAccountNode));  
            g_GPRS_DataAccount[g_DataAccount_Display.GPRSCurrSelectItem].Present = 'E';
            mmi_dtcnt_rectify_GPRS_account_buffer();
            g_DataAccount_Display.GPRS_acct_num--;
            mmi_dtcnt_arrange_acct_list(NULL, g_GPRS_DataAccount, ARRANGE_ACCT_TYPE_ALPHABET);
            g_DataAccount_Display.GPRSCurrSelectItem = 0;
        }
        else
        {
            mmi_dtcnt_ready_check_on_background(DTCNTReenterList);
        }

    }
#endif /* __MMI_GPRS_FEATURES__ */     
}
#endif

static void vre_add_GPRS_account_done(void)
{
	  if (!vre_running)
        return;
    vm_log_warn("[AUTO APN]vre_add_GPRS_account_done1!!!!!!!!!");
    g_vre_add_data_account_done = TRUE;
    if (am_set_gprs_acct_callback != NULL)
        am_set_gprs_acct_callback();
    am_set_gprs_acct_callback =NULL;
    vre_first_data_account_pos = -1;
    vm_log_warn("[AUTO APN]vre_add_GPRS_account_done2!!!!!!!!!");
}



static void vre_gprs_set_account_rsp_first(void *info)
{

#ifdef __MMI_GPRS_FEATURES__

    mmi_ps_set_gprs_data_account_rsp_struct *localPtr = (mmi_ps_set_gprs_data_account_rsp_struct*) info;
    mtk_dtcnt_gprs_set_account_rsp(localPtr);
    vre_gprs_add_gprs_account_second();
    showGPRSDataAccount(2);

#endif 
}



static void vre_gprs_set_account_rsp_second(void *info)
{

#ifdef __MMI_GPRS_FEATURES__

    mmi_ps_set_gprs_data_account_rsp_struct *localPtr = (mmi_ps_set_gprs_data_account_rsp_struct*) info;
    mtk_dtcnt_gprs_set_account_rsp(localPtr);
    vre_add_GPRS_account_done();
    showGPRSDataAccount(3);

#endif 
}


#ifdef  __VRE_RB_08B__
static void vre_gprs_set_account_req(U8 disp_index,VMINT record_set_index)
#else
static void vre_gprs_set_account_req(U8 org_index, U8 disp_index,VMINT record_set_index)
#endif
{
    
#ifdef __MMI_GPRS_FEATURES__
    
    mmi_ps_set_gprs_data_account_req_struct *myMsgPtr;
    

    U8 ref_count;
    U16 msg_len;
    
    MYQUEUE Message;
    U8 DataAccountName_ASCII[(MAX_GPRS_DATAACCOUNT_NAME + 1) * ENCODING_LENGTH];
    U8 DataAccountAPN_ASCII[MAX_APN_LEN];
    U8 i = 0;
    

    if (disp_index >= MAX_DATA_ACCOUNT_GPRS_LIMIT)
    {
        vm_log_error("[AUTO APN] disp_index >= MAX_DATA_ACCOUNT_GPRS_LIMIT!");
        return;
    }
    
    memset(DataAccountName_ASCII, '\0', (MAX_GPRS_DATAACCOUNT_NAME + 1) * ENCODING_LENGTH);
    memset(DataAccountAPN_ASCII, '\0', MAX_APN_LEN);
    
    myMsgPtr =
    	(mmi_ps_set_gprs_data_account_req_struct*)
    	OslConstructDataPtr(sizeof(mmi_ps_set_gprs_data_account_req_struct));
    

    ref_count = myMsgPtr->ref_count;
    msg_len = myMsgPtr->msg_len;
    memset(myMsgPtr, '\0', sizeof(mmi_ps_set_gprs_data_account_req_struct));
    myMsgPtr->ref_count = ref_count;
    myMsgPtr->msg_len = msg_len;


    
#ifdef  __VRE_RB_08B__    
    myMsgPtr->gprs_account.context_id = disp_index + 1;
#else
    myMsgPtr->gprs_account.context_id = org_index + 1;
#endif


    myMsgPtr->gprs_account.authentication_type = g_GPRS_DataAccount[disp_index].AuthType;
    
    if (g_GPRS_DataAccount[disp_index].iFdcs > 0)
    {
    	g_GPRS_DataAccount[disp_index].iFdcs = mmi_ucs2strlen((PS8) g_GPRS_DataAccount[disp_index].DataAccountName) * ENCODING_LENGTH;
    	myMsgPtr->gprs_account.name_length = g_GPRS_DataAccount[disp_index].iFdcs;
    	myMsgPtr->gprs_account.name_dcs = DATA_ACCOUNT_UCS; /* 0x8 */
    	i = 0;
    	while (i != g_GPRS_DataAccount[disp_index].iFdcs)
    	{
    		myMsgPtr->gprs_account.name[i] = g_GPRS_DataAccount[disp_index].DataAccountName[i + 1];
    		myMsgPtr->gprs_account.name[i + 1] = g_GPRS_DataAccount[disp_index].DataAccountName[i];
    		i += 2;
    	}
    	myMsgPtr->gprs_account.name[i] = '\0';
    	myMsgPtr->gprs_account.name[i + 1] = '\0';
    }
    else
    {
    	myMsgPtr->gprs_account.name_dcs = DATA_ACCOUNT_ASCII;
    	mmi_ucs2_to_asc((PS8) DataAccountName_ASCII, (PS8) g_GPRS_DataAccount[disp_index].DataAccountName);
    	myMsgPtr->gprs_account.name_length = strlen((PS8) DataAccountName_ASCII);
    	memcpy(myMsgPtr->gprs_account.name, DataAccountName_ASCII, strlen((PS8) DataAccountName_ASCII));
    	g_GPRS_DataAccount[disp_index].iFdcs = 0;
    }
    
    mmi_ucs2_to_asc((PS8) DataAccountAPN_ASCII, (PS8) g_GPRS_DataAccount[disp_index].APN);

    memcpy(myMsgPtr->gprs_account.apn, DataAccountAPN_ASCII, strlen((PS8) DataAccountAPN_ASCII) + 1);
    myMsgPtr->gprs_account.apn_length = strlen((PS8) DataAccountAPN_ASCII);
    
    memcpy(
    	myMsgPtr->gprs_account.user_name,
    	g_GPRS_DataAccount[disp_index].UserName,
    	strlen((PS8) g_GPRS_DataAccount[disp_index].UserName) + 1);
    
    memcpy(
    	myMsgPtr->gprs_account.password,
    	g_GPRS_DataAccount[disp_index].Passwd,
    	strlen((PS8) g_GPRS_DataAccount[disp_index].Passwd) + 1);
    

#ifdef __VRE_RB_08B__
    for (i = 0; i < 4; i++)
    {
        myMsgPtr->gprs_account.dns[i] = 0;
    }
#else
	for (i = 0; i < 4; i++)
    {
    	myMsgPtr->gprs_account.dns[i] = (U8) g_GPRS_DataAccount[disp_index].DnsAddress[i];
    	myMsgPtr->gprs_account.sec_dns[i] = (U8) g_GPRS_DataAccount[disp_index].ViceDnsAddress[i];
    }
#endif
    

    
    
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__

    memcpy(myMsgPtr->gprs_account.provurl, g_GPRS_DataAccount[disp_index].provurl_hash_val, MMI_DTCNT_PROVURL_HASH_LEN);
    memcpy(myMsgPtr->gprs_account.napid, g_GPRS_DataAccount[disp_index].napid_hash_val, MMI_DTCNT_NAPID_HASH_LEN);
    myMsgPtr->gprs_account.account_type = g_GPRS_DataAccount[disp_index].acct_type;
#endif 
    myMsgPtr->gprs_account.read_only = g_GPRS_DataAccount[disp_index].readonly;

#ifndef __VRE_RB_08B__	
    myMsgPtr->gprs_account.dcomp_algo = 0x02;
    myMsgPtr->gprs_account.hcomp_algo = 0x02;
    myMsgPtr->gprs_account.pdp_type = 0x21;
    myMsgPtr->gprs_account.pdp_addr_len = 0x01;
#endif


    myMsgPtr->profile_type = DATA_ACCT_GPRS_PROF;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = PRT_MMI_PS_SET_GPRS_DATA_ACCOUNT_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    if (record_set_index == 1)
        SetProtocolEventHandler(vre_gprs_set_account_rsp_first, PRT_MMI_PS_SET_GPRS_DATA_ACCOUNT_RSP);
    else
        SetProtocolEventHandler(vre_gprs_set_account_rsp_second, PRT_MMI_PS_SET_GPRS_DATA_ACCOUNT_RSP);
    OslMsgSendExtQueue(&Message);

    
#endif /* __MMI_GPRS_FEATURES__ */ 


}

#ifdef  __VRE_RB_08B__
static void vre_gprs_set_account_info_internal(VMINT disp_index,VMINT apn)
#else
static void vre_gprs_set_account_info_internal(VMINT org_index,VMINT disp_index,VMINT apn)
#endif
{
#ifdef __MMI_GPRS_FEATURES__
    stopRequestedTone(WARNING_TONE);
    memset(&g_GPRS_DataAccount[disp_index], '\0', sizeof(GPRSDataAccountNode));
    

    
   	mmi_ucs2cpy((PS8) g_GPRS_DataAccount[disp_index].DataAccountName, (PS8) vm_ucs2_string(apn == VM_TCP_APN_CMWAP ? AM_WAP_STR : AM_NET_STR));
    g_GPRS_DataAccount[disp_index].iFdcs = mmi_ucs2strlen((PS8) g_GPRS_DataAccount[disp_index].DataAccountName);
    
    mmi_ucs2cpy((PS8) g_GPRS_DataAccount[disp_index].APN, (PS8) vm_ucs2_string(apn == VM_TCP_APN_CMWAP ? cb_apn_info.apn_proxy : cb_apn_info.apn_no_proxy));
    if (apn == VM_TCP_APN_CMWAP)
    {
        mmi_ucs2_to_asc((PS8) g_GPRS_DataAccount[disp_index].UserName, (PS8) vm_ucs2_string(cb_apn_info.wap_user_name));
        mmi_ucs2_to_asc((PS8) g_GPRS_DataAccount[disp_index].Passwd, (PS8) vm_ucs2_string(cb_apn_info.wap_pass_word));
    }
    else
    {
        mmi_ucs2_to_asc((PS8) g_GPRS_DataAccount[disp_index].UserName, (PS8) vm_ucs2_string(cb_apn_info.net_user_name));
        mmi_ucs2_to_asc((PS8) g_GPRS_DataAccount[disp_index].Passwd, (PS8) vm_ucs2_string(cb_apn_info.net_pass_word));
    }

    g_GPRS_DataAccount[disp_index].AuthType = 0;
    g_GPRS_DataAccount[disp_index].Present = 'P';
    g_GPRS_DataAccount[disp_index].acct_type = 0;
    g_GPRS_DataAccount[disp_index].readonly = 0;
#ifndef __VRE_RB_08B__	    
    g_GPRS_DataAccount[disp_index].org_acct_id = org_index;
#endif
#endif /* __MMI_GPRS_FEATURES__ */     

}

static void vre_gprs_edit_gprs_account_first(void)
{

    U8 i,j;

    i = FIRST_RECORD_EDIT_POS;
#ifndef __VRE_RB_08B__	    
    j = g_GPRS_DataAccount[i].org_acct_id;
    g_DataAccount_Display.set_type = MMI_DTCNT_GPRS_PROFILE_EDIT;
    vre_first_data_account_pos = j;
#else
 	vre_first_data_account_pos = i;
#endif
    vm_log_warn("[AUTO APN]vre_gprs_edit_gprs_account_first  i=%d,j=%d",i,j);


    vm_log_warn("[AUTO APN]vre_gprs_edit_gprs_account_first end before edit_GPRS_account_req1!");

#ifndef __VRE_RB_08B__    
    vre_gprs_set_account_info_internal(j, i, VM_TCP_APN_CMWAP);
    vre_gprs_set_account_req(j, i, VRE_SET_GPRS_ACCT_1);
#else
    vre_gprs_set_account_info_internal(i, VM_TCP_APN_CMWAP);
    vre_gprs_set_account_req(i, VRE_SET_GPRS_ACCT_1);
#endif


    vm_log_warn("[AUTO APN]vre_gprs_edit_gprs_account_first end before edit_GPRS_account_req2!");
}

static void vre_gprs_edit_gprs_account_second(void)
{
    U8 i,j;

    if (vre_first_data_account_pos == FIRST_RECORD_EDIT_POS)
        i = FIRST_RECORD_EDIT_POS -1;
    else
        i = FIRST_RECORD_EDIT_POS;

    
#ifndef __VRE_RB_08B__    
    j = g_GPRS_DataAccount[i].org_acct_id;    
    g_DataAccount_Display.set_type = MMI_DTCNT_GPRS_PROFILE_EDIT;
#endif
       
    vm_log_warn("[AUTO APN]vre_gprs_edit_gprs_account_second i=%d,j=%d",i,j);
    
    vm_log_warn("[AUTO APN]vre_gprs_edit_gprs_account_second end before edit_GPRS_account_req1!");

    
#ifndef __VRE_RB_08B__     
    vre_gprs_set_account_info_internal(j, i, VM_TCP_APN_CMNET);
    vre_gprs_set_account_req(j, i, VRE_SET_GPRS_ACCT_2);
#else
    vre_gprs_set_account_info_internal(i, VM_TCP_APN_CMNET);
    vre_gprs_set_account_req(i, VRE_SET_GPRS_ACCT_2);
#endif


    vm_log_warn("[AUTO APN]vre_gprs_edit_gprs_account_second end before edit_GPRS_account_req2!");    
}


static void vre_gprs_edit_gprs_account_single(VMINT apn)
{

    U8 i,j;

    if (vre_first_data_account_pos == FIRST_RECORD_EDIT_POS)
        i = FIRST_RECORD_EDIT_POS -1;
    else
        i = FIRST_RECORD_EDIT_POS;

#ifndef __VRE_RB_08B__     
    j = g_GPRS_DataAccount[i].org_acct_id; 
    g_DataAccount_Display.set_type = MMI_DTCNT_GPRS_PROFILE_EDIT;
#endif

    vm_log_warn("[AUTO APN]vre_gprs_edit_gprs_account_single i=%d,j=%d",i,j);
    
    vm_log_warn("[AUTO APN]vre_gprs_edit_gprs_account_single end before edit_GPRS_account_req1!");

#ifndef __VRE_RB_08B__    
    vre_gprs_set_account_info_internal(j, i, apn);
    vre_gprs_set_account_req(j, i, VRE_SET_GPRS_ACCT_2);
#else
    vre_gprs_set_account_info_internal(i, apn);
    vre_gprs_set_account_req(i, VRE_SET_GPRS_ACCT_2);
#endif

    vm_log_warn("[AUTO APN]vre_gprs_edit_gprs_account_single end before edit_GPRS_account_req2!");    
}




static void vre_gprs_add_gprs_account_first(void)
{
    U8 i, j;

    vm_log_warn("[AUTO APN]vre_gprs_add_gprs_account_first beign!");
#ifdef __VRE_RB_08B__	
	vre_gprs_edit_gprs_account_first();
	return;
#else
    i = g_DataAccount_Display.GPRS_acct_num;
    j = vre_gprs_allocate_acct_id();

    
    vm_log_warn("[AUTO APN]vre_gprs_add_gprs_account_first i=%d,j=%d",i,j);
    if (j == DTCNT_MAX_ACCT_ALLOCATED)
    {
        vm_log_warn("[AUTO APN]vre_gprs_add_gprs_account_first j == DTCNT_MAX_ACCT_ALLOCATED!");
        vre_gprs_edit_gprs_account_first();
        return;
    }
    vre_first_data_account_pos = j;

    vm_log_warn("[AUTO APN]vre_gprs_add_gprs_account_first end before edit_GPRS_account_req1!");    
    g_DataAccount_Display.set_type = MMI_DTCNT_GPRS_PROFILE_ADD;   
    vre_gprs_set_account_info_internal(j, i, VM_TCP_APN_CMWAP);
    vre_gprs_set_account_req(j, i, VRE_SET_GPRS_ACCT_1);
    vm_log_warn("[AUTO APN]vre_gprs_add_gprs_account_first end before edit_GPRS_account_req2!");
#endif	
}


static void vre_gprs_add_gprs_account_second(void)
{
    U8 i, j;

    vm_log_warn("[AUTO APN]vre_gprs_add_gprs_account_second beign!");
#ifdef __VRE_RB_08B__	
	vre_gprs_edit_gprs_account_second();
	return;
#else    
    i = g_DataAccount_Display.GPRS_acct_num;
    j = vre_gprs_allocate_acct_id();


    
    vm_log_warn("[AUTO APN]vre_gprs_add_gprs_account_second i=%d,j=%d",i,j);
    if (j == DTCNT_MAX_ACCT_ALLOCATED)
    {
        vm_log_warn("[AUTO APN]vre_gprs_add_gprs_account_second j == DTCNT_MAX_ACCT_ALLOCATED!");
        vre_gprs_edit_gprs_account_second();
        return;
    }
    
	
    vm_log_warn("[AUTO APN]vre_gprs_add_gprs_account_second end before edit_GPRS_account_req1!");
    g_DataAccount_Display.set_type = MMI_DTCNT_GPRS_PROFILE_ADD;   
    vre_gprs_set_account_info_internal(j, i, VM_TCP_APN_CMNET);
    vre_gprs_set_account_req(j, i, VRE_SET_GPRS_ACCT_2);
    vm_log_warn("[AUTO APN]vre_gprs_add_gprs_account_second end before edit_GPRS_account_req2!");
#endif	
}



static void vre_gprs_add_gprs_account_single(VMINT apn)
{
    U8 i, j;
	

    vm_log_warn("[AUTO APN]vre_gprs_add_gprs_account_single beign!");

#ifdef __VRE_RB_08B__	
	vre_gprs_edit_gprs_account_single(apn);
	return;
#else     
    i = g_DataAccount_Display.GPRS_acct_num;
    j = vre_gprs_allocate_acct_id();


	vm_log_warn("[AUTO APN]vre_gprs_add_gprs_account_single i=%d,j=%d",i,j);
	if (j == DTCNT_MAX_ACCT_ALLOCATED)
	{
	    vm_log_warn("[AUTO APN]vre_gprs_add_gprs_account_single j == DTCNT_MAX_ACCT_ALLOCATED!");
	    vre_gprs_edit_gprs_account_single(apn);
	    return;
	}

	vm_log_warn("[AUTO APN]vre_gprs_add_gprs_account_single end before edit_GPRS_account_req1!");
    	g_DataAccount_Display.set_type = MMI_DTCNT_GPRS_PROFILE_ADD;   
	vre_gprs_set_account_info_internal(j, i, apn);
	vre_gprs_set_account_req(j, i, VRE_SET_GPRS_ACCT_2);
	vm_log_warn("[AUTO APN]vre_gprs_add_gprs_account_single end before edit_GPRS_account_req2!");    
#endif    
}



static void vre_gprs_ready_callback(void)
{
    showGPRSDataAccount(1);
    vre_gprs_add_gprs_account_first();

    vm_log_warn("[AUTO APN] ready_callback_one :vre_first_data_account_pos = %s",vm_gb2312_string((VMWSTR)g_DataAccount_Display.DataAccountName));
}


static void vre_gprs_ready_timer_callback(VMINT tid)
{
    if (!vre_running)
        return;

    if (g_vre_is_ready_dataaccount == TRUE)
    {
        vm_log_warn("[AUTO APN] vre_gprs_ready_timer_callback");
        vm_delete_timer(tid);
        vre_gprs_ready_callback();
    }    
}

static void vre_gprs_ready_callback_single(void)
{
    vre_first_data_account_pos = vre_gprs_find_acct_id(current_apn);
    vm_log_warn("[AUTO APN] vre_gprs_ready_callback_single :vre_first_data_account_pos = %d",vre_first_data_account_pos); 
 

//#ifndef __VRE_RB_08B__	
    if (vre_first_data_account_pos == DTCNT_MAX_ACCT_ALLOCATED)
        vre_first_data_account_pos = -1;
//#else
//	vre_first_data_account_pos = FIRST_RECORD_EDIT_POS;
//#endif
    showGPRSDataAccount(11);
    vre_gprs_add_gprs_account_single(current_apn);

    vm_log_warn("[AUTO APN] vre_gprs_ready_callback_single :vre_first_data_account_pos = %s",g_DataAccount_Display.DataAccountName); 
    vm_log_warn("[AUTO APN] vre_gprs_ready_callback_single :vre_first_data_account_pos = %s",vm_gb2312_string((VMWSTR)g_DataAccount_Display.DataAccountName));
      
}

static void vre_gprs_ready_timer_callback_single(VMINT tid)
{
    if (!vre_running)
        return;
    if (g_vre_is_ready_dataaccount == TRUE)
    {
        vm_log_warn("[AUTO APN] vre_gprs_ready_timer_callback_single");
        vm_delete_timer(tid);
        vre_gprs_ready_callback_single();
    }    
}

VMINT vm_tcp_add_gprs_account(vm_apn_info *current_apn_info,vre_gprs_acct_set_done_callback cb)
{
	vm_apn_info apn_info;
    
    memcpy(&cb_apn_info,current_apn_info,sizeof(vm_apn_info));
    g_vre_add_data_account_done = FALSE;
    am_set_gprs_acct_callback = cb;
    

//    mmi_dtcnt_ready_check_on_background(vre_gprs_ready_callback);


/*#if defined(__VRE_RB_08A__)
	if (vm_global_check_apn_status(&apn_info) == VM_APN_ALL_IN_NATIVE_LIST)
	{
		vm_log_fatal("vm_tcp_add_gprs_account-------->APN is exist!");
		g_vre_add_data_account_done = TRUE;
	}
	else
	{
		mmi_dtcnt_ready_check_on_background(vre_gprs_ready_callback);
		return g_DataAccount_Display.GPRSCurrSelectItem;
	}
#else    	
    	mmi_dtcnt_ready_check_on_background(vre_gprs_ready_callback);
#endif*/

    if (g_vre_is_ready_dataaccount == TRUE)
        vre_gprs_ready_callback();
    else
    {
        vm_create_timer(VRE_DATAACCOUNT_READY_TIME, vre_gprs_ready_timer_callback);
    }
        

   

#ifdef __VRE_RB_08B__
	return g_DataAccount_Display.GPRSCurrSelectItem;
#else
	return g_DataAccount_Display.GPRS_acct_num;
#endif
}

VMINT vm_tcp_add_single_gprs_account(vm_apn_info *current_apn_info,VMINT apn,vre_gprs_acct_set_done_callback cb)
{
    vm_apn_info apn_info;
    memcpy(&cb_apn_info,current_apn_info,sizeof(vm_apn_info));
    g_vre_add_data_account_done = FALSE;
    am_set_gprs_acct_callback = cb; 

    current_apn = apn;

    //mmi_dtcnt_ready_check_on_background(vre_gprs_ready_callback_single);    

/*#if defined(__VRE_RB_08A__)
	if (vm_global_check_apn_status(&apn_info) == VM_APN_ALL_IN_NATIVE_LIST)
	{
		vm_log_fatal("vm_tcp_add_single_gprs_account-------->APN is exist!");
		g_vre_add_data_account_done = TRUE;
	}
	else
	{
		mmi_dtcnt_ready_check_on_background(vre_gprs_ready_callback_single);
		return g_DataAccount_Display.GPRSCurrSelectItem;
	}
#else    	
    	mmi_dtcnt_ready_check_on_background(vre_gprs_ready_callback_single);
#endif    
*/
    if (g_vre_is_ready_dataaccount == TRUE)
        vre_gprs_ready_callback_single();
    else
    {
        vm_create_timer(VRE_DATAACCOUNT_READY_TIME, vre_gprs_ready_timer_callback_single);
    }


#ifdef __VRE_RB_08B__
	return g_DataAccount_Display.GPRSCurrSelectItem;
#else
	return g_DataAccount_Display.GPRS_acct_num;
#endif

}



#endif

