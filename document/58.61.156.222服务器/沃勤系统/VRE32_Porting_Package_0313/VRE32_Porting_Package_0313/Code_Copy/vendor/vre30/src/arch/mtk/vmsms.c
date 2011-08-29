#ifdef __VRE__
#include "mmi_include.h"
#if (defined(__VRE_RB_09A__)||defined(__VRE_RB_08A__))
#include "SimDetectionGprot.h"
#include "mmi_msg_context.h"
#else 
#include "SmsSrvGprot.h"
#endif

#include "string.h"
#include "vmmod.h"
#include "vmsys.h"
#include "vmio.h"
#include "vmlog.h"
#include "vmopt.h"
#include "vmstdlib.h"
#include "vmchset.h"
#include "vmsim.h"
#include "vmmem.h"

#include "vmtel.h"
#include "vmresmng.h"
#include "vmpromng.h"
#include "vmmacrostub.h"


#include "vmsms.h"

#include "vmglobalver.h"
#include "CommonScreens.h"
/* ------------------------------------------------------------------------ */
/* 系统全局变量声明。                                                       */
/* ------------------------------------------------------------------------ */
extern VMINT vre_running;

/* ------------------------------------------------------------------------ */
/* 系统函数声明。                                                           */
/* ------------------------------------------------------------------------ */

 extern VMINT vm_is_card2Absent(void);
 extern VMINT vm_is_card1Absent(void);
 extern VMINT vm_sal_initialize_sms_module(void);
 extern VMINT vm_sal_finialize_sms_module(void);
 extern VMINT vm_sal_send_sms(VMWSTR phone_number, VMWSTR content, void (*callback)(VMINT result));
 extern VMINT vm_sal_sms_read_msg(VMUINT16 msg_id, VMINT change_status,  vm_sms_msg_data_t* msg_data, 
	            VmSmsCallbackFunc  callback_func, void* user_data, VMINT * cause);
 extern VMINT vm_sal_sms_add_msg(vm_sms_add_msg_data_t * msg_data, VmSmsCallbackFunc callback_func, void* user_data, VMINT * cause);
 extern VMINT vm_sal_sms_delete_msg(VMUINT16 msg_id, VmSmsCallbackFunc callback_func,  void* user_data, VMINT * cause);
 extern VMINT vm_sal_sms_delete_msg_list(vm_sms_box_enum box_type,  vm_sms_sim_enum sim_id, VmSmsCallbackFunc callback_func,  void* user_data, VMINT * cause);
 extern VMINT vm_sal_sms_get_msg_id_list(vm_sms_query_t* query_data,  VmSmsCallbackFunc callback_func,  void* user_data, VMINT * cause);
 extern VMINT16 vm_sal_sms_get_msg_id(vm_sms_box_enum box_type, VMUINT16 msg_index);
 extern VMINT16 vm_sal_sms_get_box_size(vm_sms_box_enum box_type);
 extern VMINT vm_sal_sms_get_sc_address(vm_sms_sim_enum sim_id, VmSmsCallbackFunc callback, void* user_data);
#if (!defined(__VRE_RB_09A__) && !defined(__VRE_RB_08A__))
 extern VMINT vm_sal_sms_get_sc_address_syn(VMCHAR * sc_addr, vm_sms_sim_enum sim_id);
#else
 extern VMINT vm_sal_sms_delete_msg_for_interrupt(VMUINT16 index, VmSmsCallbackFunc callback_func,  void* user_data,VMINT * cause);
#endif
/*
  * 应用程序短消息回调函数。
  */

/* ------------------------------------------------------------------------ */
/* 模块内部变量声明。                                                       */
/* ------------------------------------------------------------------------ */
#define  VM_SMS_NUM0    L'0'
#define  VM_SMS_NUM1    L'1'
#define  VM_SMS_NUM3    L'3'
#define  VM_SMS_NUM5    L'5'
#define  VM_SMS_NUM8    L'8'


typedef enum
{
  VM_SMS_SEND,
  VM_SMS_SEND_PERSON,
  VM_SMS_READ,
  VM_SMS_ADD,
  VM_SMS_DELETE,
  VM_SMS_DELETE_LIST,
  VM_SMS_GET_MSG_ID_LIST,
  VM_SMS_GET_SC_ADDR,
  VM_SMS_DELETE_FOR_PAY
     
}sms_operation_type;

typedef struct
{
  VMINT operation_type;
  VMWSTR phone_number;
  VMWSTR content;
  void (* user_sms_callback)(VMINT result);
 }sms_send_sms_t;

typedef struct
{
  VMINT operation_type;
  VMUINT16 msg_id;
  VMINT change_status;
  vm_sms_msg_data_t* msg_data;
  VmSmsCallbackFunc  callback_func;
  void* user_data;
 }sms_read_t;

typedef struct
{
  VMINT operation_type;
  vm_sms_add_msg_data_t * msg_data;
  VmSmsCallbackFunc  callback_func;
  void* user_data;
 }sms_add_t;

typedef struct
{
  VMINT operation_type;
  VMUINT16 msg_id;
  VmSmsCallbackFunc  callback_func;
  void* user_data;
 }sms_delete_t;

typedef struct
{
  VMINT operation_type;
  vm_sms_box_enum box_type;
  vm_sms_sim_enum sim_id;
  VmSmsCallbackFunc  callback_func;
  void* user_data;
 }sms_delete_list_t;

typedef struct
{
  VMINT operation_type;
  vm_sms_query_t* query_data;
  VmSmsCallbackFunc  callback_func;
  void* user_data;
 }sms_get_msg_id_list_t;

typedef struct
{
  VMINT operation_type;
  vm_sms_sim_enum sim_id;
  VmSmsCallbackFunc  callback_func;
  void* user_data;
 }sms_get_sc_addr_t;

static VMINT  sms_busy_flag = FALSE;

static  VMINT sms_process_handle = -1;
/* ------------------------------------------------------------------------ */
/* 模块内部函数声明。                                                       */
/* ------------------------------------------------------------------------ */
static void  vm_sms_queue_manager(VMINT tid);
static void  vm_sms_process_status_callback(VM_P_HANDLE process_handle, VMINT sys_state);
static VMINT vm_sms_sim_is_valid(VMINT sim_id);
#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
void vm_sms_callback(vm_sms_callback_t* callback_data);
#else
void vm_sms_callback(srv_sms_callback_struct* callback_data);
#endif
static void vm_sms_release_node_by_process(VMINT process_handle);

#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
 VMINT8 sim1_sc_addr[VM_SMS_MAX_ADDR_LEN + 1];
 VMINT8 sim2_sc_addr[VM_SMS_MAX_ADDR_LEN + 1];
#endif

/* ------------------------------------------------------------------------ */
/* 模块内部函数定义。                                        */
/* ------------------------------------------------------------------------ */
#ifdef VM_SUPPORT_SMS_NO_POPUP
static U8	vm_sms_pre_hdlr(mmi_frm_int_event_type type)
{
	if (vm_res_get_data_list_count_by_type(VM_RES_TYPE_VIDEO_HANDLE) ||
		vm_res_get_data_list_count_by_type(VM_RES_TYPE_VIDEO_BIT_HANDLE) ||
		vm_res_get_data_list_count_by_type(VM_RES_TYPE_AUDIO_HANDLE) ||
		vm_res_get_data_list_count_by_type(VM_RES_TYPE_AUDIO_BIT_HANDLE) ||
		vm_res_get_data_list_count_by_type(VM_RES_TYPE_MIDI_HANDLE) ||
		vm_res_get_data_list_count_by_type(VM_RES_TYPE_RECORD_HANDLE)
		)
	{
		/* handle video, audio, midi, record, no popup, no tone. */
		SetInterruptPopupDisplay(POPUP_ALL_OFF);
	}
	else
	{
		SetInterruptPopupDisplay(POPUP_TONE_ON);
	}
	return 0;
}

static U8	vm_sms_post_hdlr(mmi_frm_int_event_type type)
{
	SetInterruptPopupDisplay(POPUP_ALL_ON);
	return 0;
}

void	vm_set_sms_no_popup(void)
{
	mmi_frm_block_interrupt_event_handler(MMI_FRM_INT_SMS, vm_sms_pre_hdlr, vm_sms_post_hdlr);
}
#endif

static void vm_finialize_sms_module(void)
{
    vm_sal_finialize_sms_module();
	vm_res_type_set_notify_callback(VM_RES_TYPE_SMS_HANDLE,  NULL);
	sms_busy_flag = FALSE;
	sms_process_handle =-1;
}

static void vm_intial_sms_module(void)
{
    vm_sal_initialize_sms_module(); 
    vm_res_type_set_notify_callback(VM_RES_TYPE_SMS_HANDLE,  vm_sms_process_status_callback);
 	sms_busy_flag = FALSE;
	sms_process_handle =-1;
#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
	memset(sim1_sc_addr, 0 , sizeof(sim1_sc_addr));
	memset(sim2_sc_addr, 0 , sizeof(sim2_sc_addr));
#endif
}

/*
  * 短消息发送模块的生命周期函数。
  */
static VMINT sms_mod_evt_proc(VRE_MOD_LIFECIRCLE_EVT event)
{
	switch(event)
	{
	case EVT_MOD_INIT:
		vm_intial_sms_module();
		break;
	case EVT_MOD_ACTIVE:
		break;
	case EVT_MOD_INACTIVE:
		break;
	case EVT_MOD_RELEASE:
		vm_finialize_sms_module();
		break;
	default:
		vm_log_debug("{SMS MODULE}Receive unkown [%d] event.", event);
		return -2;
	}

	return 0;
}

VMINT _vm_reg_sms_module(void)
{
	int res = 0;
	
	if ((res = _vm_reg_module("SMS MODULE", (MOD_EVT_PROCESS)sms_mod_evt_proc)) != REG_VRE_MODULE_SUCCESS)
	{
		vm_log_error("Failed to regisiter sms module. Error Code : %d", res);
	}

	return res;
}

static void  vm_sms_process_status_callback(VM_P_HANDLE process_handle, VMINT sys_state)
{           
	
    VMINT ret;
    if(process_handle < 0)
	{
		vm_log_error("vm_sms_process_status_callback:process_handle=%d",process_handle);
		return;
	}
		
	switch(sys_state)
	{
		case VM_PMNG_UNLOAD:
			/*删除该进程所有结点*/
			//vm_log_debug("vm_sms_process_status_callback:VM_PMNG_UNLOAD start");  
			vm_sms_release_node_by_process(process_handle);
            ret = vm_sms_clear_interrupt_event_handler_forpay(VM_EVT_ID_SMS_NEW_MSG, NULL, NULL);
		      
            vm_log_warn("vm_sms_process_status_callback: VM_PMNG_UNLOAD ret=%d",ret);  
                
			break;
		case VM_PMNG_FOREGROUND:
			break;
		case VM_PMNG_BACKGROUND:
			break;
	}

}


static void  vm_sms_queue_manager(VMINT tid)
{ 
       VMINT res;
       VMINT i =0;
       sms_send_sms_t * sms_send = NULL;
	sms_read_t * sms_read = NULL;
	sms_add_t * sms_add = NULL;
	sms_delete_t * sms_delete = NULL;
	sms_delete_list_t * sms_delete_list = NULL;
	sms_get_msg_id_list_t * sms_get_msg_id_list = NULL;
	sms_get_sc_addr_t * sms_get_sc_addr = NULL;
	
	vm_res_node_t   res_node;
	VMINT * data_buffer = NULL;

#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
	vm_sms_callback_t fail_callback;
#else
	srv_sms_callback_struct fail_callback;
#endif
	VMINT cause = 0;
		
       //vm_log_debug("vm_sms_queue_manager:start");
		
        if(tid >=0)
        {
           // vm_log_debug("vm_sms_queue_manager  delete time1=%d", tid);
            i = vm_delete_timer_ex(tid);
	     if(i < 0)
	     {
	          vm_log_error("vm_sms_queue_manager:vm_delete_timer fail");
	     }
	     else
	     {
	      //  vm_log_debug("vm_sms_queue_manager:vm_delete_timer success");
	     }
        }
	 if( sms_busy_flag == TRUE)
	 {
	       vm_log_error("vm_sms_queue_manager:sms_busy_flag=1");
		return;
	 }
	
        res = vm_res_get_data_list_by_type(VM_RES_TYPE_SMS_HANDLE, &res_node, 1);
	 if(res <= 0)
	 {
	        vm_log_error("vm_sms_queue_manager:vm_res_get_data fail");
	        return;
	 }
        vm_log_debug("vm_sms_queue_manager:res=%d",res);
	  sms_busy_flag = TRUE;

	 data_buffer = (VMINT *)res_node.data_content;
	 vm_log_debug("vm_sms_queue_manager:data_buffer[0]=%d",data_buffer[0], data_buffer[0]);
	 sms_process_handle = res_node.phandle;
	 switch(data_buffer[0])
	 {
	    
	      case VM_SMS_SEND:
		  	vm_log_debug("vm_sms_queue_manager:VM_SEND_SMS");
			
	      case VM_SMS_SEND_PERSON:
		  	sms_send = (sms_send_sms_t *)res_node.data_content;
			res = vm_sal_send_sms( sms_send->phone_number ,  sms_send->content, sms_send->user_sms_callback);
			if(res <= 0)
	              {
	                     fail_callback.result = 2;
#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
				fail_callback.cause = VM_SMS_CAUSE_DATA_INVALID;
			       fail_callback.action= VM_SMS_ACTION_SEND;
#else
				fail_callback.cause = SRV_SMS_CAUSE_DATA_INVALID;
			       fail_callback.action= SRV_SMS_ACTION_SEND;
#endif
				fail_callback.action_data = NULL;
		              vm_sms_callback(&fail_callback);
	                     vm_log_error("vm_sms_queue_manager:vm_sal_send_sms fail");
	                     return;
	              }
			vm_log_debug("vm_sms_queue_manager:VM_SEND_SMS_PERSON");
			
			break;
			
	    case VM_SMS_READ:
		  	sms_read = (sms_read_t *)res_node.data_content;
#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
			res = vm_sal_sms_read_msg(sms_read->msg_id,  sms_read->change_status, sms_read->msg_data, vm_sms_callback, sms_read->user_data, &cause);
#else
			res = vm_sal_sms_read_msg(sms_read->msg_id,  sms_read->change_status, sms_read->msg_data, sms_read->callback_func, sms_read->user_data, &cause);
#endif
			if(res < 0)
	              {
	                     fail_callback.result = 0;
#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
				fail_callback.cause = VM_SMS_CAUSE_DATA_INVALID;
			       fail_callback.action= VM_SMS_ACTION_READ;
#else
			res = vm_sal_sms_read_msg(sms_read->msg_id,  sms_read->change_status, sms_read->msg_data, sms_read->callback_func, sms_read->user_data, &cause);
				fail_callback.cause = cause;
			       fail_callback.action= SRV_SMS_ACTION_READ;
#endif
				fail_callback.action_data = NULL;
		              vm_sms_callback(&fail_callback);
	                     vm_log_error("vm_sms_queue_manager:vm_sal_sms_read_msg fail");
	                     return;
	              }
			vm_log_debug("vm_sms_queue_manager:VM_SMS_READ");
			
			break;
			
	     case VM_SMS_ADD:
		  	sms_add = (sms_add_t *)res_node.data_content;
#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
			res = vm_sal_sms_add_msg(sms_add->msg_data, vm_sms_callback, sms_add->user_data, &cause);
#else
			res = vm_sal_sms_add_msg(sms_add->msg_data, sms_add->callback_func, sms_add->user_data, &cause);
#endif
			if(res < 0)
	              {
	                     fail_callback.result = 0;
#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
	                     fail_callback.cause = VM_SMS_CAUSE_DATA_INVALID;
			       fail_callback.action= VM_SMS_ACTION_SAVE;
#else
	                     fail_callback.cause = cause;
			       fail_callback.action= SRV_SMS_ACTION_SAVE;
#endif
				fail_callback.action_data = NULL;
		              vm_sms_callback(&fail_callback);
	                     vm_log_error("vm_sms_queue_manager:vm_sal_sms_add_msg fail");
	                     return;
	              }
			vm_log_debug("vm_sms_queue_manager:VM_SMS_ADD");
			
			break;
#if (!defined(__VRE_RB_09A__) && !defined(__VRE_RB_08A__))
			
	     case VM_SMS_DELETE:
         case VM_SMS_DELETE_FOR_PAY:
		  	sms_delete = (sms_delete_t *)res_node.data_content;
			res = vm_sal_sms_delete_msg(sms_delete->msg_id, sms_delete->callback_func, sms_delete->user_data, &cause);
			if(res < 0)
	              {
	                     fail_callback.result = 0;
				fail_callback.cause = cause;
			       fail_callback.action= SRV_SMS_ACTION_DELETE;
				fail_callback.action_data = NULL;
		              vm_sms_callback(&fail_callback);
	                     vm_log_error("vm_sms_queue_manager:vm_sal_sms_delete_msg fail");
	                     return;
	              }
			vm_log_debug("vm_sms_queue_manager:VM_SMS_DELETE");
			
			break;
#else
	     case VM_SMS_DELETE:
		  	sms_delete = (sms_delete_t *)res_node.data_content;
			res = vm_sal_sms_delete_msg(sms_delete->msg_id, vm_sms_callback, sms_delete->user_data, &cause);
			if(res < 0)
	              {
	                     fail_callback.result = 0;
				fail_callback.cause = VM_SMS_CAUSE_DATA_INVALID;
			       fail_callback.action= VM_SMS_ACTION_DELETE;
				fail_callback.action_data = NULL;
		              vm_sms_callback(&fail_callback);
	                     vm_log_error("vm_sms_queue_manager:vm_sal_sms_delete_msg fail");
	                     return;
	              }
			vm_log_debug("vm_sms_queue_manager:VM_SMS_DELETE");
			
			break;
	     case VM_SMS_DELETE_FOR_PAY:
		  	sms_delete = (sms_delete_t *)res_node.data_content;
			res = vm_sal_sms_delete_msg_for_interrupt(sms_delete->msg_id, vm_sms_callback, sms_delete->user_data, &cause);
			if(res < 0)
	              {
	                     fail_callback.result = 0;
				fail_callback.cause = VM_SMS_CAUSE_DATA_INVALID;
			       fail_callback.action= VM_SMS_ACTION_DELETE;
				fail_callback.action_data = NULL;
		              vm_sms_callback(&fail_callback);
	                     vm_log_error("vm_sms_queue_manager:vm_sal_sms_delete_msg_for_pay fail");
	                     return;
	              }
			vm_log_debug("vm_sms_queue_manager:VM_SMS_DELETE_FOR_PAY");
			
			break;            

#endif			
	     case VM_SMS_DELETE_LIST:
		  	sms_delete_list = (sms_delete_list_t *)res_node.data_content;
#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
			res = vm_sal_sms_delete_msg_list(sms_delete_list->box_type,  sms_delete_list->sim_id, vm_sms_callback, sms_delete_list->user_data, &cause);
#else
			res = vm_sal_sms_delete_msg_list(sms_delete_list->box_type,  sms_delete_list->sim_id, sms_delete_list->callback_func, sms_delete_list->user_data, &cause);
#endif
			if(res < 0)
	              {
	                     fail_callback.result = 0;
#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
				fail_callback.cause = VM_SMS_CAUSE_DATA_INVALID;
			       fail_callback.action=  VM_SMS_ACTION_DELETE;
#else
				fail_callback.cause = cause;
			       fail_callback.action=  SRV_SMS_ACTION_DELETE;
#endif
				fail_callback.action_data = NULL;
		              vm_sms_callback(&fail_callback);
	                     vm_log_error("vm_sms_queue_manager:vm_sal_sms_delete_msg_list fail");
	                     return;
	              }
			vm_log_debug("vm_sms_queue_manager:VM_SMS_DELETE_LIST");
			
			break;

	      case VM_SMS_GET_MSG_ID_LIST:
		  	sms_get_msg_id_list = (sms_get_msg_id_list_t *)res_node.data_content;
#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
			res = vm_sal_sms_get_msg_id_list( sms_get_msg_id_list->query_data, vm_sms_callback, sms_get_msg_id_list->user_data, &cause);
#else
			res = vm_sal_sms_get_msg_id_list( sms_get_msg_id_list->query_data,  sms_get_msg_id_list->callback_func, sms_get_msg_id_list->user_data, &cause);
#endif
			if(res < 0)
	              {
	                     fail_callback.result = 0;
#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
				fail_callback.cause = VM_SMS_CAUSE_DATA_INVALID;
			       fail_callback.action= VM_SMS_ACTION_QUERY;
#else
				fail_callback.cause = cause;
			       fail_callback.action= SRV_SMS_ACTION_QUERY;
#endif
				fail_callback.action_data = NULL;
		              vm_sms_callback(&fail_callback);
	                     vm_log_error("vm_sms_queue_manager:vm_sal_sms_get_msg_id_list fail");
	                     return;
	              }
			vm_log_debug("vm_sms_queue_manager:VM_SMS_GET_MSG_ID_LIST");
			
			break;
			
	   case VM_SMS_GET_SC_ADDR:
		  	sms_get_sc_addr = (sms_get_sc_addr_t *)res_node.data_content;
#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
			res = vm_sal_sms_get_sc_address( sms_get_sc_addr->sim_id,  vm_sms_callback, sms_get_msg_id_list->user_data);
#else
			res = vm_sal_sms_get_sc_address( sms_get_sc_addr->sim_id,  sms_get_msg_id_list->callback_func, sms_get_msg_id_list->user_data);
#endif
			if(res < 0)
	              {
	                     fail_callback.result = 0;
#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
				fail_callback.cause = VM_SMS_CAUSE_DATA_INVALID;
			       fail_callback.action= VM_SMS_ACTION_GET_SC_ADDR;
#else
				fail_callback.cause = SRV_SMS_CAUSE_SC_INVALID;
			       fail_callback.action= VM_SMS_GET_SC_ADDR;
#endif
				fail_callback.action_data = NULL;
		              vm_sms_callback(&fail_callback);
#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
	                     vm_log_error("vm_sms_queue_manager:vm_sal_sms_get_sc_address fail");
#else
	                     vm_log_error("vm_sms_queue_manager:vm_sal_sms_get_sc_address_asyn fail");
#endif
	                     return;
	              }
			vm_log_debug("vm_sms_queue_manager:VM_SMS_GET_MSG_ID_LIST");
			
			break;
	
	     default:
		 	vm_log_debug("vm_sms_queue_manager:default type");
			sms_busy_flag = TRUE;

		 	break;
			
	 }
		

         vm_log_debug("vm_sms_queue_manager:end");
 
}

static void vm_sms_release_node_by_process(VMINT process_handle)
{
       VMINT i = 0; 
	VMINT res = -1;
       VMINT * data_buffer = NULL;  
	VMINT buffer_size = 0;

	sms_send_sms_t * sms_send = NULL;
	sms_read_t  * sms_read = NULL;
       sms_add_t  * sms_add = NULL;
	sms_delete_t  * sms_delete = NULL;
       sms_delete_list_t  * sms_delete_list = NULL;
	sms_get_msg_id_list_t  * sms_get_msg_id_list = NULL;

	sms_get_sc_addr_t * sms_get_sc = NULL;

	VMINT cur_data_handle = -1;
	VMINT is_cur_node = FALSE;
	VMINT p_handle = -1;

	cur_data_handle = vm_res_findfirst(-1, VM_RES_TYPE_SMS_HANDLE);
	if(cur_data_handle == VM_RES_NOT_FIND)
		return;
	vm_res_findclose(VM_RES_TYPE_SMS_HANDLE);
	
	p_handle = vm_res_get_process_handle( VM_RES_TYPE_SMS_HANDLE, cur_data_handle);
	 		
	if(p_handle == process_handle)
	{
		is_cur_node = TRUE;
	}	  
		
	while ( (i = vm_res_findfirst(process_handle, VM_RES_TYPE_SMS_HANDLE)) != VM_RES_NOT_FIND)
	{
		res= vm_res_get_data( VM_RES_TYPE_SMS_HANDLE, i, (void**)&data_buffer, &buffer_size );

		if(res == 0)
		{
			vm_log_debug("vm_sms_release_node_by_process, data_buffer[0]=%d", data_buffer[0]);
			switch(data_buffer[0])
			{
				case VM_SMS_SEND:
				case VM_SMS_SEND_PERSON:
					sms_send = (sms_send_sms_t  *)data_buffer;
				          
					vm_free(sms_send->phone_number);
					vm_free(sms_send->content);	
					vm_free(sms_send);
					vm_log_debug("vm_sms_release_node_by_process, VM_SMS_SEND");
					break;
							
			case VM_SMS_READ:
					sms_read = (sms_read_t  *)data_buffer;
					vm_free(sms_read);
					vm_log_debug("vm_sms_release_node_by_process, VM_SMS_READ");
					break;

			case VM_SMS_ADD:
					sms_add = (sms_add_t  *)data_buffer;
					vm_free(sms_add->msg_data->content);
					vm_free(sms_add->msg_data);
					vm_free(sms_add);
					vm_log_debug("vm_sms_release_node_by_process, VM_SMS_ADD");
					break;

			case VM_SMS_DELETE:
					sms_delete = (sms_delete_t  *)data_buffer;
					vm_free(sms_delete);
					vm_log_debug("vm_sms_release_node_by_process, VM_SMS_DELETE");
					break;
			case VM_SMS_DELETE_FOR_PAY:
					sms_delete = (sms_delete_t  *)data_buffer;
					vm_free(sms_delete);
					vm_log_debug("vm_sms_release_node_by_process, VM_SMS_DELETE_FOR_PAY");
					break;                    
							
			case VM_SMS_DELETE_LIST:
					sms_delete_list = (sms_delete_list_t  *)data_buffer;
					vm_free(sms_delete_list);		
					vm_log_debug("vm_sms_release_node_by_process, VM_SMS_DELETE_LIST");
					break;
                                         		
			case VM_SMS_GET_MSG_ID_LIST:
					sms_get_msg_id_list = (sms_get_msg_id_list_t  *)data_buffer;
					vm_free(sms_get_msg_id_list);
					vm_log_debug("vm_sms_release_node_by_process, VM_SMS_GET_MSG_ID_LIST");
					break;
					
			case VM_SMS_GET_SC_ADDR:
					sms_get_sc = (sms_get_sc_addr_t  *)data_buffer;
					vm_free(sms_get_sc);
					vm_log_debug("vm_sms_release_node_by_process, VM_SMS_GET_SC_ADDR");
					break;
			default:
					vm_log_error("vm_sms_release_node_by_process: error type data_buffer[0]=%d",data_buffer[0]);
					break;
							
			}
				
		}
		vm_res_release_data(VM_RES_TYPE_SMS_HANDLE,  i); 
		vm_log_debug("vm_sms_release_node_by_process : data handle=%d", i);
		vm_res_findclose(VM_RES_TYPE_SMS_HANDLE);
	}
	
	if(( is_cur_node == TRUE) && (sms_process_handle == -1))
	{
		cur_data_handle = vm_res_findfirst(-1, VM_RES_TYPE_SMS_HANDLE);
		if(cur_data_handle == VM_RES_NOT_FIND)
			return;
		vm_res_findclose(VM_RES_TYPE_SMS_HANDLE);	
				 
		p_handle = vm_res_get_process_handle( VM_RES_TYPE_SMS_HANDLE, cur_data_handle);
		if (vm_pmng_set_ctx(p_handle) == VM_PMNG_OP_OK)
		{
			if(vm_create_timer_ex(100, (VM_TIMERPROC_T)vm_sms_queue_manager)<0)
			{
				
				vm_log_debug("vm_sms_release_node_by_process timer fail");
			}
			sms_process_handle = -1;
			vm_pmng_reset_ctx();     
		}	
			
	 }
   
}


void vm_cancel_send_sms(void)
{
       VMINT process_handle = -1;
        
  
       process_handle = vm_pmng_get_current_handle();
	vm_log_debug("vm_cancel_send_sms :start phandle=%d",process_handle);  
	
	if(process_handle < 0)
	{
	    vm_log_error("vm_cancel_send_sms:process_handle=%d",process_handle);
	    return;	
	}

	vm_sms_release_node_by_process(process_handle);
   
	vm_log_debug("vm_cancel_send_sms :end");
	   

}


VMINT vm_send_sms(VMWSTR phone_number, VMWSTR content, void (*callback)(VMINT result)) 
{
	
       VMINT pid = -1;
	
	VMWSTR vm_number = NULL;
	VMWSTR vm_content = NULL;
	            
	 sms_send_sms_t * sms_send = NULL;
	 VMINT avaliable = -1;
	 VMINT data_handle = -1;
	 
	if (vm_sim_card_count() <= 0)
	{
		vm_log_error("vm_send_sms: no sim card");
		return FALSE;
	}
	
	if (phone_number == NULL || content == NULL)
	{
		vm_log_error("vm_send_sms : the ptr of phone or content is NULL");
		return FALSE;
	}
	if (vm_wstrlen(phone_number) == 0 || vm_wstrlen(phone_number) > VM_SMS_MAX_ADDR_LEN)
	{
		vm_log_error("vm_send_sms : the length of phone_number is out of range");
		return FALSE;
	}	
	if (vm_wstrlen(content) == 0 || vm_wstrlen(content) > VM_SMS_MSG_CONTENT_LEN)
	{
		vm_log_error("vm_send_sms : the length of sms's content is out of range(0-500)");
		return FALSE;
	}
	
	pid = vm_pmng_get_current_handle();
	if(pid < 0)
	    return FALSE;	
       vm_log_error("vm_send_sms : pid=%d",pid);
		   
       avaliable = vm_res_type_avaliable_handle(VM_RES_TYPE_SMS_HANDLE, pid);
	if(avaliable <= 0)
	{
	   vm_log_error("vm_send_sms : avaliable <= 0");
	   return FALSE;
	   
	}
	 vm_log_debug("vm_send_sms : avaliable =%d", avaliable);
	 
	sms_send =(sms_send_sms_t *)vm_calloc(sizeof(sms_send_sms_t));
	if(!sms_send)
	{
	      vm_log_error("vm_send_sms : !sms_send");
	      return FALSE;
	}
	
	vm_number = (VMWSTR)vm_calloc((VM_SMS_MAX_ADDR_LEN+1)*sizeof(VMINT16));
	if(!vm_number)
	{
	       vm_free(sms_send);
	       vm_log_error("vm_send_sms : !vm_number");
	       return FALSE;
	}
	
	vm_content = (VMWSTR)vm_calloc((VM_SMS_MSG_CONTENT_LEN+1)*sizeof(VMINT16));
	if(!vm_content)
	{
	       vm_free(sms_send);
	       vm_free(vm_number);
	       vm_log_error("vm_send_sms : !vm_content");
	        return FALSE;
	}

	vm_wstrncpy(vm_number, phone_number, VM_SMS_MAX_ADDR_LEN);
	vm_wstrncpy(vm_content, content, VM_SMS_MSG_CONTENT_LEN);
	
	sms_send->phone_number = vm_number;
	sms_send->content = vm_content;
	sms_send->operation_type = VM_SMS_SEND;
	
	sms_send->user_sms_callback =  callback;

       
	if(vm_res_get_data_list_count_by_type(VM_RES_TYPE_SMS_HANDLE) == 0)
	{
	   
	     if(vm_create_timer_ex(100, (VM_TIMERPROC_T)vm_sms_queue_manager) <0)
            {
			vm_log_error("vm_send_sms timer fail");
            }
	     
	 }
	vm_log_debug("vm_send_sms: vm_res_save_data");
	data_handle = vm_res_save_data(VM_RES_TYPE_SMS_HANDLE,sms_send, sizeof(sms_send_sms_t),(void *)callback, pid);
	if(data_handle < 0)
       {
             vm_log_error("vm_send_sms data_handle < 0");
	      vm_free(sms_send);
	      vm_free(vm_number);
	      vm_free(vm_content); 
             return FALSE;
        }
	vm_log_debug("vm_send_sms count = %d",vm_res_get_data_list_count_by_type(VM_RES_TYPE_SMS_HANDLE));
	
	return TRUE;
}



VMINT vm_send_sms_person(VMWSTR phone_number, VMWSTR content, void (*callback)(VMINT result)) 
{
	VMINT i = 0;
	VMINT retval = FALSE;
	
       VMINT pid = -1;
       sms_send_sms_t * sms_send = NULL;
	VMINT avaliable = -1;
	VMINT data_handle = -1;
	VMWSTR vm_number = NULL;
	VMWSTR vm_content = NULL;

	if (vm_sim_card_count() <= 0)
	{
		vm_log_error("vm_send_sms_person: no sim card");
		return FALSE;
	}

		//vm_log_debug("vm_send_sms_person : ready");
	if (phone_number == NULL || content == NULL)
	{
		vm_log_error("vm_send_sms_person : the ptr of phone or content is NULL");
		return FALSE;
	}
	if (vm_wstrlen(phone_number) == 0 || vm_wstrlen(phone_number) > VM_SMS_MAX_ADDR_LEN)
	{
		vm_log_error("vm_send_sms_person : the length of phone_number is  out of range");
		return FALSE;
	}
	if (vm_wstrlen(content) == 0 || vm_wstrlen(content) > VM_SMS_MSG_CONTENT_LEN)
	{
		vm_log_error("vm_send_sms_person : the length of sms's content is out of range(0-500)");
		return FALSE;
	}
	
	//vm_ucs2_to_gb2312(phn, VM_SMS_NUM_LEN, phone_number);
	#ifndef  VRE_GLOBAL_VERSION
	if (vm_wstrlen(phone_number) == 11 || vm_wstrlen(phone_number) == 12)
	{
		if (phone_number[0] == VM_SMS_NUM0)
		{
			i = 1;
		}
	       else
		{
			i = 0;
		}
		   
	      if (phone_number[i] == VM_SMS_NUM1)
	      {
			if (phone_number[i+1] == VM_SMS_NUM3 || phone_number[i+1] == VM_SMS_NUM5  || phone_number[i+1] == VM_SMS_NUM8 )
			{
				
				retval = TRUE;
				
			}
			else
			{
				vm_log_error("vm_send_sms_person : the phone number is not person");
				  return FALSE;
			}
	    }
	    else
	    {
				vm_log_error("vm_send_sms_person : the phone number is not person");
	       	  return FALSE;
	    }
     }
    else
    {
			vm_log_error("vm_send_sms_person : the length of phone number is error");
			  return FALSE;
    }
#endif
	
      pid = vm_pmng_get_current_handle();
	if(pid < 0)
	{
	    vm_log_error("vm_send_sms_person : pid=%d",pid);
	    return FALSE;	
	}
		   
       avaliable = vm_res_type_avaliable_handle(VM_RES_TYPE_SMS_HANDLE, pid);
	if(avaliable <= 0)
	{
	   vm_log_error("vm_send_sms_person : avaliable <= 0");
	   return FALSE;
	   
	}
	 vm_log_debug("vm_send_sms_person : avaliable =%d", avaliable);
	 
	sms_send = (sms_send_sms_t*)vm_calloc(sizeof(sms_send_sms_t));
	if(!sms_send)
	{
	    vm_log_error("vm_send_sms_person : !sms_send");
	    return FALSE;
	}
	
	vm_number = (VMWSTR)vm_calloc((VM_SMS_MAX_ADDR_LEN+1)*sizeof(VMINT16));
	if(!vm_number)
	{
	       vm_log_error("vm_send_sms_person : !vm_number");
		vm_free(sms_send);
	       return FALSE;
	}
	
	vm_content = (VMWSTR)vm_calloc((VM_SMS_MSG_CONTENT_LEN+1)*sizeof(VMINT16));
	if(!vm_content)
	{
	       vm_log_error("vm_send_sms_person : !vm_content");
		vm_free(sms_send);
		vm_free(vm_number);
	       return FALSE;
	}

	vm_wstrncpy(vm_number, phone_number, VM_SMS_MAX_ADDR_LEN);
	vm_wstrncpy(vm_content, content, VM_SMS_MSG_CONTENT_LEN);
	
	sms_send->phone_number = vm_number;
	sms_send->content = content;
	sms_send->operation_type = VM_SMS_SEND_PERSON;
	
	sms_send->user_sms_callback =  callback;

       
	if(vm_res_get_data_list_count_by_type(VM_RES_TYPE_SMS_HANDLE) == 0 )
	{
	   
	     if(vm_create_timer_ex(100, (VM_TIMERPROC_T)vm_sms_queue_manager) <0)
            {
                
                 vm_log_error("vm_send_sms_person timer fail");
            }
	   
	 }
	vm_log_debug("vm_send_sms_person: vm_res_save_data");
	data_handle = vm_res_save_data(VM_RES_TYPE_SMS_HANDLE,sms_send, sizeof(sms_send_sms_t),(void *)callback, pid);
	if(data_handle < 0)
       {
            vm_log_error("vm_send_sms_person data_handle < 0");
	     vm_free(sms_send);
	     vm_free(vm_number);
	     vm_free(vm_content);
            return FALSE;
        }
	vm_log_debug("vm_send_sms_person count = %d",vm_res_get_data_list_count_by_type(VM_RES_TYPE_SMS_HANDLE));
	
	return TRUE;
}


VMINT vm_sms_read_msg(VMUINT16 msg_id, VMINT change_status,  vm_sms_msg_data_t* msg_data, 
	            VmSmsCallbackFunc  callback_func, void* user_data)
{
      sms_read_t * sms_read = NULL;
      VMINT pid = -1;
      VMINT avaliable = -1;
      VMINT data_handle = -1;
	  
      vm_log_debug("vm_sms_read_msg:start");  
      if(msg_data==NULL ||msg_data->content_buff == NULL)
      {
          vm_log_error("vm_sms_read_msg:msg_data == NULL || msg_data->content_buff == NULL");
	   return VM_SMS_REQ_ERROR;
      }
	  
      	pid = vm_pmng_get_current_handle();
	if(pid <=0)
	    return VM_SMS_REQ_ERROR;	
	
	avaliable = vm_res_type_avaliable_handle(VM_RES_TYPE_SMS_HANDLE, pid);
	if(avaliable <= 0)
	{
	   vm_log_error("vm_sms_read_msg : avaliable <= 0");
	   return VM_SMS_REQ_ERROR;
	   
	}
#if (!defined(__VRE_RB_09A__) && !defined(__VRE_RB_08A__))
	if(srv_sms_is_sms_ready()==0)  
	{
	   vm_log_error("vm_sms_read_msg:srv_sms_is_sms_ready()==0");
	   return VM_SMS_REQ_ERROR;
	}
#endif	   
	sms_read =(sms_read_t * )vm_calloc(sizeof(sms_read_t));
	if(sms_read == NULL)
      	{
      	    vm_log_error("vm_sms_read_msg: sms_read == NULL");
	    return VM_SMS_REQ_ERROR;
      	}
	sms_read->operation_type = VM_SMS_READ;
	sms_read->msg_id = msg_id;
	sms_read->change_status = change_status;
	sms_read->msg_data = msg_data;
	sms_read->callback_func = callback_func;
	sms_read->user_data = user_data;

	if(vm_res_get_data_list_count_by_type(VM_RES_TYPE_SMS_HANDLE) == 0 )
	{
	     if(vm_create_timer_ex(100, (VM_TIMERPROC_T)vm_sms_queue_manager)<0)
            {
                
                vm_log_error("vm_sms_read_msg timer fail");
            }
	    	     
	}
	
       data_handle = vm_res_save_data(VM_RES_TYPE_SMS_HANDLE, sms_read,  sizeof(sms_read_t), (void *)callback_func, pid);
	if(data_handle < 0)
       {
            vm_log_error("vm_sms_read_msg data_handle < 0");
	     vm_free(sms_read);
            return VM_SMS_REQ_ERROR;
        }
	vm_log_debug("vm_sms_read_msg count = %d",vm_res_get_data_list_count_by_type(VM_RES_TYPE_SMS_HANDLE));
	
	vm_log_debug("vm_sms_read_msg:end");   
      return VM_SMS_REQ_NO_ERROR;
 
}


VMINT vm_sms_add_msg(vm_sms_add_msg_data_t * msg_data, VmSmsCallbackFunc callback_func, void* user_data)
{
      sms_add_t * sms_add = NULL;
      vm_sms_add_msg_data_t * msg_data_ptr = NULL;
      VMINT16* content = NULL;
      VMINT  pid = -1;
      VMINT  avaliable = -1;
      VMINT data_handle = -1;
	
       vm_log_debug("vm_sms_add_msg:start");  
	if(msg_data == NULL || msg_data->content == NULL)
	{
		vm_log_error("vm_sms_add_msg:msg_data ==NULL");
		return VM_SMS_REQ_ERROR;
	}

	if(msg_data->status < VM_SMS_STATUS_UNREAD || msg_data->status >= VM_SMS_STATUS_UNSUPPORTED )
	{
		vm_log_error("vm_sms_add_msg:status invalid");
		return VM_SMS_REQ_ERROR;
	}
	if ((msg_data->content_size > (VM_SMS_MSG_CONTENT_LEN+1)*2) || vm_wstrlen((VMWSTR)msg_data->content) > VM_SMS_MSG_CONTENT_LEN 
	  	|| vm_wstrlen((VMWSTR)msg_data->number) > VM_SMS_MAX_ADDR_LEN)
	{
		vm_log_error("vm_send_sms : msg_data->content_size > VM_SMS_MSG_CONTENT_LEN");
		return VM_SMS_REQ_ERROR;
	}
	if(vm_sms_sim_is_valid(msg_data->sim_id) == VM_SMS_REQ_ERROR)
	{
		vm_log_error("vm_sms_add_msg:sim_id  error");
		return VM_SMS_REQ_ERROR;
	}
#if (!defined(__VRE_RB_09A__) && !defined(__VRE_RB_08A__))
	if(msg_data->storage_type < VM_SMS_STORAGE_ME || msg_data->storage_type > VM_SMS_STORAGE_SIM)
	{
		vm_log_error("vm_sms_add_msg:storage_type  error");
		return VM_SMS_REQ_ERROR;
	
	}
	if(srv_sms_is_sms_ready()==0)  
	{
	   vm_log_error("vm_sms_add_msg:srv_sms_is_sms_ready()==0");
	   return VM_SMS_REQ_ERROR;
	}
#endif
	pid = vm_pmng_get_current_handle();
	if(pid <=0)
	    return VM_SMS_REQ_ERROR;	
	
	avaliable = vm_res_type_avaliable_handle(VM_RES_TYPE_SMS_HANDLE, pid);
	if(avaliable <= 0)
	{
	    vm_log_error("vm_sms_add_msg : avaliable <= 0");
	    return VM_SMS_REQ_ERROR;
	   
	}
	msg_data_ptr =(vm_sms_add_msg_data_t * )vm_calloc(sizeof(vm_sms_add_msg_data_t));
	if(msg_data_ptr == NULL)
	{
	     vm_log_error("vm_sms_add_msg:msg_data_ptr == NULL");
	     return VM_SMS_REQ_ERROR;
	}
       sms_add = (sms_add_t * )vm_calloc(sizeof(sms_add_t));
	if(sms_add == NULL)
	{
	     vm_free(msg_data_ptr);
	     vm_log_error("vm_sms_add_msg:sms_add == NULL");
            return VM_SMS_REQ_ERROR;
	}
	//content =(VMINT16*)vm_calloc((VM_SMS_MSG_CONTENT_LEN+1)*sizeof(VMINT16));
	content = (VMINT16*)vm_calloc((vm_wstrlen((VMWSTR)msg_data->content) + 1)*sizeof(VMINT16));
	if(content == NULL)
	{
	     vm_free(msg_data_ptr);
	     vm_free(sms_add);
	     vm_log_error("vm_sms_add_msg:content == NULL");
           return VM_SMS_REQ_ERROR;
	}
		
       sms_add->operation_type = VM_SMS_ADD;
	sms_add->msg_data = msg_data_ptr;
	sms_add->callback_func = callback_func;
	sms_add->user_data = user_data;
       msg_data_ptr->content = (VMINT8*)content;
	msg_data_ptr->content_size = (vm_wstrlen((VMWSTR)msg_data->content) + 1)*sizeof(VMINT16);
	   
	msg_data_ptr->status = msg_data->status;
	msg_data_ptr->sim_id = msg_data->sim_id;
	
	memcpy((void*)&msg_data_ptr->timestamp, &msg_data->timestamp, sizeof(vm_time_t));
	vm_wstrncpy((VMWSTR)content,  (VMWSTR)msg_data->content, vm_wstrlen((VMWSTR)msg_data->content));
	vm_wstrncpy((VMWSTR)msg_data_ptr->number,  (VMWSTR)msg_data->number, VM_SMS_MAX_ADDR_LEN);

       if(vm_res_get_data_list_count_by_type(VM_RES_TYPE_SMS_HANDLE) == 0 )
	{
	     if(vm_create_timer_ex(100, (VM_TIMERPROC_T)vm_sms_queue_manager)<0)
            {
                vm_log_error("vm_sms_add_msg timer fail");
		
            }
	 
	}
	
       data_handle = vm_res_save_data(VM_RES_TYPE_SMS_HANDLE, sms_add,  sizeof(sms_add_t), (void *)callback_func, pid);
	if(data_handle < 0)
       {
            vm_log_error("vm_sms_add_msg data_handle < 0");
	     vm_free(msg_data_ptr);
	     vm_free(sms_add);
	     vm_free(content);
            return VM_SMS_REQ_ERROR;
        }
	vm_log_debug("vm_sms_add_msg count = %d",vm_res_get_data_list_count_by_type(VM_RES_TYPE_SMS_HANDLE));
	
	vm_log_debug("vm_sms_add_msg:end");   
    
       return VM_SMS_REQ_NO_ERROR;
}


VMINT vm_sms_delete_msg(VMUINT16 msg_id, VmSmsCallbackFunc callback_func,  void* user_data)
{
      sms_delete_t * sms_delete = NULL;
      VMINT  pid = -1;
      VMINT  avaliable = -1;
      VMINT data_handle = -1;
	
     vm_log_debug("vm_sms_delete_msg:start");  

#if (!defined(__VRE_RB_09A__) && !defined(__VRE_RB_08A__))
     if(srv_sms_is_sms_ready()==0 )  
     {
	   vm_log_error("vm_sms_delete_msg:srv_sms_is_sms_ready()==0");
	   return VM_SMS_REQ_ERROR;
     }
#endif
     pid = vm_pmng_get_current_handle();
     if(pid <=0)
	    return VM_SMS_REQ_ERROR;	
	
     avaliable = vm_res_type_avaliable_handle(VM_RES_TYPE_SMS_HANDLE, pid);
     if(avaliable <= 0)
     {
	    vm_log_error("vm_sms_delete_msg:avaliable <= 0");
	    return VM_SMS_REQ_ERROR;
     }
     sms_delete =(sms_delete_t *)vm_calloc(sizeof(sms_delete_t));
     if(sms_delete == NULL)
     {
	     vm_log_error("vm_sms_delete_msg:sms_delete == NULL");
            return VM_SMS_REQ_ERROR;
     } 
     sms_delete->operation_type = VM_SMS_DELETE;
     sms_delete->msg_id = msg_id;
     sms_delete->callback_func = callback_func;
     sms_delete->user_data = user_data;
	 
     if(vm_res_get_data_list_count_by_type(VM_RES_TYPE_SMS_HANDLE) == 0 )
	{
	     if(vm_create_timer_ex(100, (VM_TIMERPROC_T)vm_sms_queue_manager)<0)
            {
                vm_log_error("vm_sms_delete_msg timer fail");
		
            }
		     
	}
	
       data_handle = vm_res_save_data(VM_RES_TYPE_SMS_HANDLE, sms_delete,  sizeof(sms_delete), (void *)callback_func, pid);
	if(data_handle < 0)
       {
            vm_log_error("vm_sms_delete_msg data_handle < 0");
	     vm_free(sms_delete);
            return VM_SMS_REQ_ERROR;
        }
	vm_log_debug("vm_sms_delete_msg count = %d",vm_res_get_data_list_count_by_type(VM_RES_TYPE_SMS_HANDLE));
	
	vm_log_debug("vm_sms_delete_msg:end");   
      return VM_SMS_REQ_NO_ERROR;
}

VMINT vm_sms_delete_msg_forpay(VMUINT16 msg_id, VmSmsCallbackFunc callback_func,  void* user_data)
{
      sms_delete_t * sms_delete = NULL;
      VMINT  pid = -1;
      VMINT  avaliable = -1;
      VMINT data_handle = -1;
	
     vm_log_debug("vm_sms_delete_msg_for_pay:start");  

//#if defined(__VRE_RB_09B__)
#if (!defined(__VRE_RB_09A__) && !defined(__VRE_RB_08A__))
     if(srv_sms_is_sms_ready()==0 )  
     {
	   vm_log_error("vm_sms_delete_msg:srv_sms_is_sms_ready()==0");
	   return VM_SMS_REQ_ERROR;
     }
#endif
     pid = vm_pmng_get_current_handle();
     if(pid <=0)
	    return VM_SMS_REQ_ERROR;	
	
     avaliable = vm_res_type_avaliable_handle(VM_RES_TYPE_SMS_HANDLE, pid);
     if(avaliable <= 0)
     {
	    vm_log_error("vm_sms_delete_msg_for_pay:avaliable <= 0");
	    return VM_SMS_REQ_ERROR;
     }
     sms_delete =(sms_delete_t *)vm_calloc(sizeof(sms_delete_t));
     if(sms_delete == NULL)
     {
	     vm_log_error("vm_sms_delete_msg_for_pay:sms_delete == NULL");
            return VM_SMS_REQ_ERROR;
     } 
     sms_delete->operation_type = VM_SMS_DELETE_FOR_PAY;
     sms_delete->msg_id = msg_id;
     sms_delete->callback_func = callback_func;
     sms_delete->user_data = user_data;
	 
     if(vm_res_get_data_list_count_by_type(VM_RES_TYPE_SMS_HANDLE) == 0 )
	{
	     if(vm_create_timer_ex(100, (VM_TIMERPROC_T)vm_sms_queue_manager)<0)
            {
                vm_log_debug("vm_sms_delete_msg_for_pay timer fail");
		
            }
		     
	}
	
       data_handle = vm_res_save_data(VM_RES_TYPE_SMS_HANDLE, sms_delete,  sizeof(sms_delete), (void *)callback_func, pid);
	if(data_handle < 0)
       {
            vm_log_error("vm_sms_delete_msg_for_pay data_handle < 0");
	     vm_free(sms_delete);
            return VM_SMS_REQ_ERROR;
        }
	vm_log_debug("vm_sms_delete_msg_for_pay count = %d",vm_res_get_data_list_count_by_type(VM_RES_TYPE_SMS_HANDLE));
	
	vm_log_debug("vm_sms_delete_msg_for_pay:end");   
      return VM_SMS_REQ_NO_ERROR;
}



VMINT vm_sms_delete_msg_list(vm_sms_box_enum box_type,  vm_sms_sim_enum sim_id, VmSmsCallbackFunc callback_func,  void* user_data)
{
      sms_delete_list_t * sms_delete_list = NULL;
      VMINT  pid = -1;
      VMINT  avaliable = -1;
      VMINT data_handle = -1;
	  
      vm_log_debug("vm_sms_delete_msg_list:start");  
      
      if(box_type < VM_SMS_BOX_INBOX || box_type >= VM_SMS_BOX_RESERVED)
      {
         vm_log_error("vm_sms_delete_msg_list:list_type is not valid");
	  return VM_SMS_REQ_ERROR;
      }
     if(vm_sms_sim_is_valid(sim_id) == VM_SMS_REQ_ERROR)
      {
  	   vm_log_error("vm_sms_delete_msg_list:sim_id  error");
	   return VM_SMS_REQ_ERROR;
      }
//#if defined (__VRE_RB_09B__)
#if (!defined(__VRE_RB_09A__) && !defined(__VRE_RB_08A__))
      if(srv_sms_is_sms_ready()==0)  
      {
	   vm_log_error("vm_sms_delete_msg_list:srv_sms_is_sms_ready()==0");
	   return VM_SMS_REQ_ERROR;
      }
#endif
      pid = vm_pmng_get_current_handle();
      if(pid <=0)
	    return VM_SMS_REQ_ERROR;	
	
      avaliable = vm_res_type_avaliable_handle(VM_RES_TYPE_SMS_HANDLE, pid);
      if(avaliable <= 0)
      {
	    vm_log_error("vm_sms_delete_msg_list:avaliable <= 0");
	    return VM_SMS_REQ_ERROR;
      }
      sms_delete_list =(sms_delete_list_t *)vm_calloc(sizeof(sms_delete_list_t));
      if(sms_delete_list == NULL)
      {
	     vm_log_error("vm_sms_delete_msg_list:sms_delete_list == NULL");
            return VM_SMS_REQ_ERROR;
      } 
      sms_delete_list->operation_type = VM_SMS_DELETE_LIST;
      sms_delete_list->box_type = box_type;
      sms_delete_list->sim_id = sim_id;
      sms_delete_list->callback_func = callback_func;
      sms_delete_list->user_data = user_data;
	 
      if(vm_res_get_data_list_count_by_type(VM_RES_TYPE_SMS_HANDLE) == 0 )
      {
	     if(vm_create_timer_ex(100, (VM_TIMERPROC_T)vm_sms_queue_manager)<0)
            {
              
                  vm_log_error("vm_sms_delete_msg_list timer fail");
            }
	   	     
      }
	
       data_handle = vm_res_save_data(VM_RES_TYPE_SMS_HANDLE, sms_delete_list,  sizeof(sms_delete_list_t), (void *)callback_func, pid);
	if(data_handle < 0)
       {
            vm_log_error("vm_sms_delete_msg_list data_handle < 0");
	     vm_free(sms_delete_list);
            return VM_SMS_REQ_ERROR;
        }
	vm_log_debug("vm_sms_delete_msg_list count = %d",vm_res_get_data_list_count_by_type(VM_RES_TYPE_SMS_HANDLE));
	
       vm_log_debug("vm_sms_delete_msg_list:end");  
       return VM_SMS_REQ_NO_ERROR;

}


VMINT vm_sms_get_msg_id_list(vm_sms_query_t* query_data,  VmSmsCallbackFunc callback_func,  void* user_data)
{
      
      sms_get_msg_id_list_t * sms_get_msg_id_list = NULL;
      vm_sms_query_t * query_data_ptr = NULL;
      VMINT  pid = -1;
      VMINT  avaliable = -1;
      VMINT data_handle = -1;
	
     vm_log_debug("vm_sms_get_msg_id_list:start");  
     if(!query_data)
     {
          vm_log_error("vm_sms_get_msg_id_list:query_data == NULL");
	   return VM_SMS_REQ_ERROR;
     }
//#if defined(__VRE_RB_09B__)
#if (!defined(__VRE_RB_09A__) && !defined(__VRE_RB_08A__))
      if(srv_sms_is_sms_ready()==0 )  
      {
	   vm_log_error("vm_sms_get_msg_id_list:srv_sms_is_sms_ready()==0");
	   return VM_SMS_REQ_ERROR;
      }
#endif
    
      if(query_data->status < VM_SMS_STATUS_UNREAD || query_data->status >= VM_SMS_STATUS_UNSUPPORTED )
      {
          vm_log_error("vm_sms_get_msg_id_list:status invalid");
	   return VM_SMS_REQ_ERROR;
      }
	  
      pid = vm_pmng_get_current_handle();
      if(pid <=0)
	    return VM_SMS_REQ_ERROR;	
	
      avaliable = vm_res_type_avaliable_handle(VM_RES_TYPE_SMS_HANDLE, pid);
      if(avaliable <= 0)
      {
	    vm_log_error("vm_sms_get_msg_id_list:avaliable <= 0");
	    return VM_SMS_REQ_ERROR;
      }
     query_data_ptr = (vm_sms_query_t *)vm_calloc(sizeof(vm_sms_query_t));
     if(query_data_ptr == NULL)
     {
          vm_log_error("vm_sms_get_msg_id_list:query_data_ptr ==NULL");
	   return VM_SMS_REQ_ERROR;
     }
     sms_get_msg_id_list =(sms_get_msg_id_list_t *)vm_calloc(sizeof(sms_get_msg_id_list_t));
     if(sms_get_msg_id_list == NULL)
     { 
          vm_free(query_data_ptr);
          vm_log_error("vm_sms_get_msg_id_list:sms_query ==NULL");
	   return VM_SMS_REQ_ERROR;
      } 
      sms_get_msg_id_list->operation_type = VM_SMS_GET_MSG_ID_LIST;
      sms_get_msg_id_list->query_data = query_data_ptr;
      sms_get_msg_id_list->callback_func = callback_func;
      sms_get_msg_id_list->user_data = user_data;
	 
      query_data_ptr->sort_flag = query_data->sort_flag;  
      query_data_ptr->order_flag = query_data->order_flag;  
      query_data_ptr->status = query_data->status;  

       if(vm_res_get_data_list_count_by_type(VM_RES_TYPE_SMS_HANDLE) == 0 )
      {
	     if(vm_create_timer_ex(100, (VM_TIMERPROC_T)vm_sms_queue_manager)<0)
            {
                
                vm_log_error("vm_sms_get_msg_id_list timer fail");
            }
		     
      }
	
       data_handle = vm_res_save_data(VM_RES_TYPE_SMS_HANDLE, sms_get_msg_id_list,  sizeof(sms_get_msg_id_list_t), (void *)callback_func, pid);
	if(data_handle < 0)
       {
            vm_log_error("vm_sms_get_msg_id_list data_handle < 0");
	     vm_free(query_data_ptr);
	     vm_free(sms_get_msg_id_list);
            return VM_SMS_REQ_ERROR;
        }
	vm_log_debug("vm_sms_get_msg_id_list count = %d",vm_res_get_data_list_count_by_type(VM_RES_TYPE_SMS_HANDLE));
	     
       vm_log_debug("vm_sms_get_msg_id_list:end");  
      return VM_SMS_REQ_NO_ERROR;
}


VMINT16 vm_sms_get_msg_id(vm_sms_box_enum box_type, VMUINT16 msg_index)
{
    VMINT msg_id = -1;
	
    vm_log_debug("vm_sms_get_msg_id:start");  
    
    if(box_type < VM_SMS_BOX_INBOX || box_type >= VM_SMS_BOX_RESERVED)
    {
         vm_log_error("vm_sms_get_list_size:box_type is not valid,box_type=%d",box_type);
	  return VM_SMS_REQ_ERROR;
    }
    msg_id = vm_sal_sms_get_msg_id(box_type, msg_index);
	
    vm_log_debug("vm_sms_get_msg_id:end msg_id=%d", msg_id);  
	
    return msg_id;

}


VMINT16 vm_sms_get_box_size(vm_sms_box_enum box_type)
{
     VMINT size = 0;

     vm_log_debug("vm_sms_get_list_size:start");  
     if(box_type < VM_SMS_BOX_INBOX || box_type >= VM_SMS_BOX_RESERVED)
     {
         vm_log_error("vm_sms_get_list_size:box_type is not valid,box_type=%0x", box_type);
	  return VM_SMS_REQ_ERROR;
     }
   
     size = vm_sal_sms_get_box_size(box_type);
	
     vm_log_debug("vm_sms_get_list_size:end size=%d", size);  
     return size;

}

static VMINT vm_sms_sim_is_valid(VMINT sim_id)
{

     if(sim_id < VM_SMS_SIM_1 ||sim_id >VM_SMS_SIM_2)
     {
          vm_log_error("vm_sms_sim_is_valid:sim_id is not valid");
	  return VM_SMS_REQ_ERROR;
     }
   // #if (defined(VRE_DUAL_SIM))
     if (sysconf.dual_sim_master == MMI_TRUE)
    {
	  
	   if(sim_id == VM_SMS_SIM_1)
	   {
	       if(vm_is_card1Absent()!=0)
	       {
	         vm_log_error("vm_sms_sim_is_valid:vm_is_card1Absent ");
		  return VM_SMS_REQ_ERROR;
	       }
	   }
	  else if(sim_id == VM_SMS_SIM_2)
	  {
	       if(vm_is_card2Absent()!=0)
	       {
	         vm_log_error("vm_sms_sim_is_valid:vm_is_card2Absent");
		  return VM_SMS_REQ_ERROR;
	      }
	  }
    }
     //#else
    else
    {
	 if(sim_id == VM_SMS_SIM_1)
	 {
          if(vm_has_sim_card()==FALSE)
	   {
	         vm_log_error("vm_sms_sim_is_valid:vm_has_sim_card fail");
		  return VM_SMS_REQ_ERROR;
	    }
	 }
	 else if(sim_id == VM_SMS_SIM_2)
	 {
	     vm_log_error("vm_sms_sim_is_valid:sim_id ==VM_SMS_SIM_2  error");
	     return VM_SMS_REQ_ERROR;
	 }
    //#endif
   }

   return VM_SMS_REQ_NO_ERROR;

}



VMINT vm_sms_get_sc_address( vm_sms_sim_enum sim_id, VmSmsCallbackFunc callback_func, void* user_data)
{
	
	sms_get_sc_addr_t * sms_get_sc = NULL;
	VMINT  pid = -1;
	VMINT  avaliable = -1;
	VMINT data_handle = -1;
	
	vm_log_debug("vm_sms_get_sc_address:start");  

//#if defined(__VRE_RB_09B__)
#if (!defined(__VRE_RB_09A__) && !defined(__VRE_RB_08A__))
	if(srv_sms_is_sms_ready()==0 )  
	{
		vm_log_error("vm_sms_get_sc_address:srv_sms_is_sms_ready()==0");
		return VM_SMS_REQ_ERROR;
	}
#endif
	if(vm_sms_sim_is_valid(sim_id) == VM_SMS_REQ_ERROR)
	{
		vm_log_error("vm_sms_get_sc_address:sim_id  error");
		return VM_SMS_REQ_ERROR;
	}
	pid = vm_pmng_get_current_handle();
	if(pid <=0)
		return VM_SMS_REQ_ERROR;	
	
	avaliable = vm_res_type_avaliable_handle(VM_RES_TYPE_SMS_HANDLE, pid);
	if(avaliable <= 0)
	{
		vm_log_error("vm_sms_get_sc_address:avaliable <= 0");
		return VM_SMS_REQ_ERROR;
	}
	sms_get_sc =(sms_get_sc_addr_t *)vm_calloc(sizeof(sms_get_sc_addr_t));
	if(sms_get_sc == NULL)
	{
		vm_log_error("vm_sms_get_sc_address:sms_delete == NULL");
		return VM_SMS_REQ_ERROR;
	} 
	sms_get_sc->operation_type = VM_SMS_GET_SC_ADDR;
	sms_get_sc->sim_id = sim_id;
	sms_get_sc->callback_func = callback_func;
	sms_get_sc->user_data = user_data;
	 
	if(vm_res_get_data_list_count_by_type(VM_RES_TYPE_SMS_HANDLE) == 0 )
	{
	     if(vm_create_timer_ex(100, (VM_TIMERPROC_T)vm_sms_queue_manager)<0)
            {
                vm_log_error("vm_sms_get_sc_address timer fail");
		
            }
		     
	}
	
       data_handle = vm_res_save_data(VM_RES_TYPE_SMS_HANDLE, sms_get_sc,  sizeof(sms_get_sc), (void *)callback_func, pid);
	if(data_handle < 0)
       {
            vm_log_error("vm_sms_get_sc_address data_handle < 0");
	     vm_free(sms_get_sc);
            return VM_SMS_REQ_ERROR;
        }
	vm_log_debug("vm_sms_get_sc_address count = %d",vm_res_get_data_list_count_by_type(VM_RES_TYPE_SMS_HANDLE));
	
	vm_log_debug("vm_sms_get_sc_address:end");   
	return VM_SMS_REQ_NO_ERROR;
}

VMINT vm_sms_get_sc_address_syn(vm_sms_get_sc_addr_cb_t * vm_sc_addr,  vm_sms_sim_enum sim_id)
{
#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
	if(vm_sc_addr == NULL)
		 return VM_SMS_REQ_ERROR;

	vm_log_debug("vm_sms_get_sc_address_syn:sim_id=%d",sim_id);   
	if(sim_id == VM_SMS_SIM_1)
	{
		 if(strlen(sim1_sc_addr) == 0)
		 {
		 	vm_log_error("vm_sms_get_sc_address_syn:strlen(sim1_sc_addr) == 0");   
		 	return VM_SMS_REQ_ERROR;
		 }
		 
		 strncpy(vm_sc_addr->sc_addr, sim1_sc_addr, VM_SMS_MAX_ADDR_LEN);
		 	
	}
	else if(sim_id == VM_SMS_SIM_2)
	{
		if(strlen(sim2_sc_addr) == 0)
		 {
		 	vm_log_error("vm_sms_get_sc_address_syn:strlen(sim2_sc_addr) == 0");   
		 	return VM_SMS_REQ_ERROR;
		}
		
		 strncpy(vm_sc_addr->sc_addr, sim2_sc_addr, VM_SMS_MAX_ADDR_LEN);
	}
	else
	{
		 return VM_SMS_NOT_SUPPORT_SYN_SCA;
	}
#else
     if(vm_sc_addr == NULL)
     {
  	   vm_log_error("vm_sms_get_sc_address_syn:vm_sc_addr== NULL");
	   return VM_SMS_REQ_ERROR;
     }	
   	 
     if(vm_sms_sim_is_valid(sim_id) == VM_SMS_REQ_ERROR)
     {
  	   vm_log_error("vm_sms_get_sc_address_syn:sim_id  error");
	   return VM_SMS_REQ_ERROR;
     }
   
     vm_sal_sms_get_sc_address_syn(vm_sc_addr->sc_addr ,sim_id);
   	 
      vm_log_debug("vm_sms_get_sc_address_syn:sc_addr=%s",vm_sc_addr->sc_addr);  
	 
#endif         	 
     return VM_SMS_SUPPORT_SYN_SCA;

}

#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
void vm_sms_callback(vm_sms_callback_t* callback_data)
{
      vm_res_node_t   res_node;
      vm_sms_callback_t   callback_data_ptr;
	  
      vm_sms_read_msg_cb_t   read_msg_ptr;
      vm_sms_read_msg_cb_t * read_msg = NULL;
	  
      vm_sms_save_msg_cb_t  add_msg_ptr ;
      vm_sms_save_msg_cb_t  * add_msg = NULL;
	   
      vm_sms_query_msg_cb_t  query_msg_ptr;
      vm_sms_query_msg_cb_t * query_msg = NULL;  
#else
void vm_sms_callback(srv_sms_callback_struct* callback_data)
{
      vm_res_node_t   res_node;
      vm_sms_callback_t   callback_data_ptr;
	  
      vm_sms_read_msg_cb_t   read_msg_ptr;
      srv_sms_read_msg_cb_struct * read_msg = NULL;
	  
      vm_sms_save_msg_cb_t  add_msg_ptr ;
      srv_sms_save_msg_cb_struct  * add_msg = NULL;
	   
      vm_sms_query_msg_cb_t  query_msg_ptr;
      srv_sms_query_msg_cb_struct * query_msg = NULL;  
#endif
      VMINT data_handle; 
	  
      VMINT i =0;
      VMINT index = 0;
      VMINT res = -1;
      VMINT sendresult = VM_SMS_RESULT_ERROR;
      VmSmsCallbackFunc  user_callback_fun;
      sms_send_sms_t * sms_send = NULL;
      sms_read_t  * sms_read = NULL;
      sms_add_t  * sms_add = NULL;
      sms_delete_t  * sms_delete= NULL;

      sms_get_msg_id_list_t * sms_get_msg_id_list = NULL;
      VMINT operate_type = TRUE;

	sms_get_sc_addr_t * sms_get_sc = NULL;
	vm_sms_get_sc_addr_cb_t  sms_get_sc_cb;
	
   
      if(vre_running == FALSE)
                   return;

      vm_log_debug("vm_sms_callback:callback_data->cause=%d,callback_data->action=%d",callback_data->cause,callback_data->action);
      if(!callback_data)
	{
	     vm_log_error("vm_sms_callback:callback_data == NULL");
	     return;
	}
  	 
      res = vm_res_get_data_list_by_type(VM_RES_TYPE_SMS_HANDLE, &res_node, 1);
	  
      vm_log_debug("vm_sms_callback:res=%d count = %d", res, vm_res_get_data_list_count_by_type(VM_RES_TYPE_SMS_HANDLE));
	 
      if(res <= 0)
      {
              vm_log_error("vm_sms_callback:res <= 0");
	       return;
      }

      vm_log_debug("vm_sms_callback:sms_process_handle =%d res_node.phandle=%d", sms_process_handle, res_node.phandle);
      if(sms_process_handle == res_node.phandle)
      {
	 
           data_handle = res_node.res_id;
	  
           if (vm_pmng_set_ctx(res_node.phandle) == VM_PMNG_OP_OK)
           {   
               vm_log_debug("vm_sms_callback:res_node.phandle=%d", res_node.phandle);
               vm_res_get_callback(VM_RES_TYPE_SMS_HANDLE,  data_handle, (void * * )&user_callback_fun);
	   	 
               vm_log_debug("vm_sms_callback:res_node->res_id=%d",data_handle);
	           	 
	        vm_log_debug("vm_sms_callback:release_data i=%d",i);
		 
              callback_data_ptr.cause = callback_data->cause;
		callback_data_ptr.result = callback_data->result;
		
               switch(callback_data->action )
               {
#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
                     case VM_SMS_ACTION_SEND:
#else
                     case SRV_SMS_ACTION_SEND:
#endif	   	
                           sms_send = res_node.data_content;
			      if((sms_send->operation_type != VM_SMS_SEND) && (sms_send->operation_type != VM_SMS_SEND_PERSON))
			      {
			           operate_type = FALSE;
			      	    break;
			      }
		     	      if (callback_data->result == TRUE)
	                    {
		                   sendresult = VM_SMS_RESULT_OK;
	                    }
                           else
	                    {
#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
                                if(callback_data->cause ==VM_SMS_RESULT_ABORT)
#else
                                if(callback_data->cause ==SRV_SMS_CAUSE_SEND_ABORT)
#endif	   	
                                {
                                     sendresult = VM_SMS_RESULT_ABORT;
                                }
                		    else
                		    {
                		         sendresult = VM_SMS_RESULT_ERROR;
                		    }
                  			
                          }
             		     vm_log_debug("vm_sms_callback:SRV_SMS_ACTION_SEND sendresult=%d",sendresult);
			     sms_send->user_sms_callback(sendresult);
				 
			     if(sms_send->phone_number)
                                 vm_free(sms_send->phone_number);
				 
			     if(sms_send->content) 
			             vm_free(sms_send->content);   
				 
			      if(sms_send)  
                                  vm_free(sms_send);   
			     break;
              			
#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
                 case VM_SMS_ACTION_READ:
#else
                 case SRV_SMS_ACTION_READ:
#endif	   	
		         sms_read = res_node.data_content;
			  if(sms_read->operation_type != VM_SMS_READ)
			  {
			         operate_type = FALSE;
			      	  break;
			  }	   	
			  callback_data_ptr.action = VM_SMS_ACTION_READ;
		         callback_data_ptr.action_data = &read_msg_ptr;
#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
			  callback_data_ptr.user_data = sms_read->user_data;
#endif	   	
		
			  read_msg_ptr.msg_data = sms_read->msg_data;

		         if(callback_data->action_data != NULL)
		         {
		             
		  
#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
			      read_msg = (vm_sms_read_msg_cb_t*)callback_data->action_data;
#else
			      read_msg = (srv_sms_read_msg_cb_struct*)callback_data->action_data;
#endif	   	
		 
		             if(callback_data_ptr.cause == VM_SMS_CAUSE_NO_ERROR)
		             {

			   
			               vm_wstrncpy((VMWSTR)sms_read->msg_data->number, (VMWSTR)read_msg->msg_data->number, (VM_SMS_MAX_ADDR_LEN + 1) );
			               //vm_log_debug("user_msg_data->number=%s", vm_gb2312_string((VMWSTR)sms_read->msg_data->number));
			   
			               sms_read->msg_data->status = read_msg->msg_data->status;
			               //vm_log_debug("user_msg_data->status=%d",  sms_read->msg_data->status);	
			   
			               sms_read->msg_data->mti = read_msg->msg_data->mti;
			              // vm_log_debug("user_msg_data->mti =%d",  sms_read->msg_data->mti);
				
			              sms_read->msg_data->tp_st = read_msg->msg_data->tp_st;
			             // vm_log_debug("user_msg_data->tp_st =%d",   sms_read->msg_data->tp_st);
			   
		             	       sms_read->msg_data->folder_id = read_msg->msg_data->folder_id;
			               //vm_log_debug("user_msg_data->folder_id =%d",   sms_read->msg_data->folder_id);	
			   
			              sms_read->msg_data->para_flag = read_msg->msg_data->para_flag;
			            //  vm_log_debug("user_msg_data->para_flag =%d",   sms_read->msg_data->para_flag);	
			   
#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
			              sms_read->msg_data->timestamp.year = read_msg->msg_data->timestamp.year;
			              sms_read->msg_data->timestamp.mon = read_msg->msg_data->timestamp.mon;
			              sms_read->msg_data->timestamp.day = read_msg->msg_data->timestamp.day;
			              sms_read->msg_data->timestamp.hour = read_msg->msg_data->timestamp.hour;
			              sms_read->msg_data->timestamp.min = read_msg->msg_data->timestamp.min;
			              sms_read->msg_data->timestamp.sec = read_msg->msg_data->timestamp.sec;
#else
			              sms_read->msg_data->timestamp.year = read_msg->msg_data->timestamp.nYear;
			              sms_read->msg_data->timestamp.mon = read_msg->msg_data->timestamp.nMonth;
			              sms_read->msg_data->timestamp.day = read_msg->msg_data->timestamp.nDay;
			              sms_read->msg_data->timestamp.hour = read_msg->msg_data->timestamp.nHour;
			              sms_read->msg_data->timestamp.min = read_msg->msg_data->timestamp.nMin;
			              sms_read->msg_data->timestamp.sec = read_msg->msg_data->timestamp.nSec;
#endif	   	
						  
                                   //vm_log_debug("user_msg_data->timestamp.year =%d",   sms_read->msg_data->timestamp.year);	
			              //vm_log_debug("user_msg_data->timestamp.mon =%d",   sms_read->msg_data->timestamp.mon);	
			              //vm_log_debug("user_msg_data->timestamp.day =%d",   sms_read->msg_data->timestamp.day);	
			             // vm_log_debug("user_msg_data->timestamp.hour =%d",   sms_read->msg_data->timestamp.hour);	
			            //  vm_log_debug("user_msg_data->timestamp.min =%d",   sms_read->msg_data->timestamp.min);	
			             // vm_log_debug("user_msg_data->timestamp.sec  =%d",   sms_read->msg_data->timestamp.sec);	
			   
		                     sms_read->msg_data->storage_type = read_msg->msg_data->storage_type;
			              //vm_log_debug(" user_msg_data->storage_type  =%d",   sms_read->msg_data->storage_type);	
			   
			              sms_read->msg_data->sim_id = read_msg->msg_data->sim_id;
			             // vm_log_debug("user_msg_data->sim_id =%d",   sms_read->msg_data->sim_id);	

			              vm_wstrncpy((VMWSTR)sms_read->msg_data->sc_address, (VMWSTR)read_msg->msg_data->sc_address, (VM_SMS_MAX_ADDR_LEN + 1));
                                  // vm_log_debug("user_msg_data->sc_address =%s",  vm_gb2312_string((VMWSTR) sms_read->msg_data->sc_address));	

			              sms_read->msg_data->pid = read_msg->msg_data->pid;
			             // vm_log_debug("user_msg_data->pid=%d",  sms_read->msg_data->pid);	

			              sms_read->msg_data->vp = read_msg->msg_data->vp;
			              //vm_log_debug("user_msg_data->vp=%d",  sms_read->msg_data->vp);	

			              sms_read->msg_data->status_report = read_msg->msg_data->status_report;
			              //vm_log_debug("user_msg_data->status_report =%d",    sms_read->msg_data->status_report);	
			   
			              sms_read->msg_data->reply_path = read_msg->msg_data->reply_path;
			              //vm_log_debug("user_msg_data->reply_path =%d",    sms_read->msg_data->reply_path);
			   
			             sms_read->msg_data->src_port = read_msg->msg_data->src_port;
			             //vm_log_debug("user_msg_data->src_port =%d",    sms_read->msg_data->src_port);

		                    sms_read->msg_data->dest_port = read_msg->msg_data->dest_port;
			             //vm_log_debug("user_msg_data->dest_port =%d",    sms_read->msg_data->dest_port);
			   
			             sms_read->msg_data->dcs = read_msg->msg_data->dcs;
			             //vm_log_debug("user_msg_data->dcs =%d",    sms_read->msg_data->dcs);
			   
			             sms_read->msg_data->msg_class = read_msg->msg_data->msg_class;
			            // vm_log_debug("user_msg_data->msg_class =%d",    sms_read->msg_data->msg_class);
			   
			          //user_msg_data->content_buff_size = read_msg->msg_data->content_buff_size;
			             vm_log_debug("user_msg_data->content_buff_size =%d",    sms_read->msg_data->content_buff_size);
			   			   
			             vm_wstrncpy((VMWSTR)sms_read->msg_data->content_buff, (VMWSTR)read_msg->msg_data->content_buff, (sms_read->msg_data->content_buff_size-2)/2);
			   			 
			     //  vm_log_debug("user_msg_data->content_buff=%s", vm_gb2312_string((VMWSTR)sms_read->msg_data->content_buff));			
		          
		               }
					 
			
          
		           }
			  
                        if(sms_read)
                               vm_free(sms_read);
		         // vm_log_debug("vm_sms_callback:  vm_free(sms_read)");
				
		          vm_log_debug("vm_sms_callback:SRV_SMS_ACTION_READ end");
		  

			  // callback_data_ptr.user_data = callback_data->user_data;
			  break;
	
#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
	          case VM_SMS_ACTION_SAVE:
#else
	          case SRV_SMS_ACTION_SAVE:
#endif
	   	         sms_add = res_node.data_content;
			  if(sms_add->operation_type != VM_SMS_ADD)
			  {
			         operate_type = FALSE;
			      	  break;
			  }	   	
                       //   callback_data_ptr.result = callback_data->result;
			  callback_data_ptr.action = VM_SMS_ACTION_SAVE;
			  callback_data_ptr.action_data = &add_msg_ptr;
#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
			  callback_data_ptr.user_data  = sms_add->user_data;
#endif
			
                       if(callback_data->action_data != NULL)
		         {
		        
#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
		              add_msg = (vm_sms_save_msg_cb_t*)callback_data->action_data;
#else
		              add_msg = (srv_sms_save_msg_cb_struct*)callback_data->action_data;
#endif
			
		             	if(callback_data_ptr.cause == VM_SMS_CAUSE_NO_ERROR)
			       {
  		       
			           add_msg_ptr.msg_id = add_msg->msg_id;
  		                    
			         }
                       }
					 
		         if(sms_add->msg_data->content)
			        vm_free(sms_add->msg_data->content);
		               vm_log_debug("vm_sms_callback:vm_free(sms_add->msg_data->content)");	  
		 
	                if(sms_add->msg_data)
		 	         vm_free(sms_add->msg_data);
		     	  
	                       vm_log_debug("vm_sms_callback:vm_free(sms_add->msg_data)");	  
	                if(sms_add)
			      vm_free(sms_add);
		 
 	                    vm_log_debug("vm_sms_callback:vm_free(callback_data_ptr.action == SRV_SMS_ACTION_SAVE)");
		 				
			  break;
	 
#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
	          case VM_SMS_ACTION_DELETE:
#else
	          case SRV_SMS_ACTION_DELETE:
#endif
	            	   //      	callback_data_ptr.result = callback_data->result;
	            	   sms_delete = res_node.data_content;
			   if((sms_delete->operation_type != VM_SMS_DELETE) && (sms_delete->operation_type != VM_SMS_DELETE_FOR_PAY) && (sms_delete->operation_type != VM_SMS_DELETE_LIST))
			   {
			         operate_type = FALSE;
			      	  break;
			   }	
                       callback_data_ptr.action = VM_SMS_ACTION_DELETE;
#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
			        callback_data_ptr.user_data  = sms_delete->user_data;		
#endif
					 
		         if(res_node.data_content)
                              vm_free(res_node.data_content);
			  
		          vm_log_debug("vm_sms_callback:vm_free(callback_data_ptr.action == SRV_SMS_ACTION_DELETE)");
			   break;
	
#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
                case VM_SMS_ACTION_QUERY:
#else
                case SRV_SMS_ACTION_QUERY:
#endif
		  	  sms_get_msg_id_list = res_node.data_content;

			   if(sms_get_msg_id_list->operation_type != VM_SMS_GET_MSG_ID_LIST)
			   {
			         operate_type = FALSE;
			      	  break;
			   }
			
                       //     callback_data_ptr.result = callback_data->result;
	               callback_data_ptr.action = VM_SMS_ACTION_QUERY;
#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
  			 callback_data_ptr.user_data  = sms_get_msg_id_list->user_data;
#endif
  
		        callback_data_ptr.action_data = &query_msg_ptr;
#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
			 query_msg = (vm_sms_query_msg_cb_t*)callback_data->action_data;
#else
			 query_msg = (srv_sms_query_msg_cb_struct*)callback_data->action_data;
#endif
			 if(callback_data->action_data != NULL)
		        {
		 			     
			       if(callback_data_ptr.cause == VM_SMS_CAUSE_NO_ERROR)	
			       {
	
			              query_msg_ptr.msg_num = query_msg->msg_num; 
			              query_msg_ptr.msg_id_list =(VMUINT16 *)vm_calloc(query_msg_ptr.msg_num*sizeof(VMUINT16));
			              if(!query_msg_ptr.msg_id_list)
			              {
			                     vm_log_error("vm_sms_callback:msg_id_list == NULL");
			                      break;
			              }
				 
			             if(!query_msg->msg_id_list)
			             {
			                      vm_log_error("vm_sms_callback:callback_data->action_data->msg_id_list== NULL");
			                      break;
			             }
				 
			            for(index=0; index <query_msg_ptr.msg_num; index++)
			            {
			                      query_msg_ptr.msg_id_list[index] =  query_msg->msg_id_list[index];
			            }
				 
			     }
		      }
			 
		      if(sms_get_msg_id_list->query_data)
                          vm_free(sms_get_msg_id_list->query_data);
			   
                     vm_log_debug("vm_sms_callback:vm_free(sms_get_msg_id_list->query_data)");	
				 
	             if(sms_get_msg_id_list)
                           vm_free(sms_get_msg_id_list);
                           vm_log_debug("vm_sms_callback:vm_free(sms_get_msg_id_list)"); 
		     break;
		case VM_SMS_ACTION_GET_SC_ADDR:
			sms_get_sc = res_node.data_content;
			if(sms_get_sc->operation_type != VM_SMS_GET_SC_ADDR)
			{
				 operate_type = FALSE;
				   break;
			}
			callback_data_ptr.action = VM_SMS_ACTION_GET_SC_ADDR;
#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
			 callback_data_ptr.user_data = sms_get_sc->user_data;
#endif
			
			memset(&sms_get_sc_cb, 0 , sizeof(vm_sms_get_sc_addr_cb_t));
			strncpy((char *)&sms_get_sc_cb.sc_addr, callback_data->action_data, VM_SMS_MAX_ADDR_LEN);
			callback_data_ptr.action_data = &sms_get_sc_cb;
			vm_log_debug("vm_sms_callback:vm_free(sms_get_msg_id_list)"); 
			break;
				 
               default:
		 	callback_data_ptr.result = callback_data->result;
	              callback_data_ptr.action = VM_SMS_ACTION_NONE;
			operate_type = FALSE;
#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
			vm_log_debug("vm_sms_callback:callback_data_ptr->action is invalid!");
#else
			vm_log_debug("vm_sms_callback:VM_SMS_ACTION_GET_SC_ADDR");
#endif
		 	break;

	
              }
			   
              if( operate_type == TRUE)	 
              {
	
#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
      	            if(callback_data->action  != VM_SMS_ACTION_SEND)
	            {
#else
      	            if(callback_data->action  != SRV_SMS_ACTION_SEND)
	            {
	                callback_data_ptr.user_data = callback_data->user_data;
#endif
				 
                       if(user_callback_fun !=NULL)
	 	              user_callback_fun(&callback_data_ptr);
	            }

	            if( (callback_data_ptr.action == VM_SMS_ACTION_QUERY) && (callback_data_ptr.cause == VM_SMS_CAUSE_NO_ERROR))
                   {
                       if(query_msg_ptr.msg_id_list )
		              vm_free(query_msg_ptr.msg_id_list);
           
		         vm_log_debug("vm_sms_callback:vm_free(query_msg_ptr.msg_id_list)");
	           
                   }
    
                   i= vm_res_release_data(VM_RES_TYPE_SMS_HANDLE,  data_handle); 
                   if(i < 0)
                   {
	               vm_log_error("vm_sms_callback:vm_res_release_data fail");
                    }
          	 
	             vm_log_debug("vm_sms_callback:release_data i=%d",i); 	
			     
	        
	
             }
		 vm_pmng_reset_ctx();	  
          }
       }

	  vm_log_debug("vm_sms_callback:count=%d",vm_res_get_data_list_count_by_type(VM_RES_TYPE_SMS_HANDLE) );
       if(vm_res_get_data_list_count_by_type(VM_RES_TYPE_SMS_HANDLE) > 0 )
       {
           			 
             memset(&res_node, 0 ,sizeof(vm_res_node_t));
             vm_res_get_data_list_by_type(VM_RES_TYPE_SMS_HANDLE, &res_node, 1);
	      if (vm_pmng_set_ctx(res_node.phandle) == VM_PMNG_OP_OK)
             {
                 if(vm_create_timer_ex(100, (VM_TIMERPROC_T)vm_sms_queue_manager) <0)
                 {
                  
                     vm_log_error("vm_sms_callback:vm_create_timer fail");
                 }
		   sms_process_handle = -1;
	          vm_log_debug("vm_sms_callback:vm_create_timer success");
                 vm_pmng_reset_ctx();     
	     }
  
      }	
	   
      sms_busy_flag = FALSE;
      vm_log_debug("vm_sms_callback:end"); 	
    

 }

#endif
