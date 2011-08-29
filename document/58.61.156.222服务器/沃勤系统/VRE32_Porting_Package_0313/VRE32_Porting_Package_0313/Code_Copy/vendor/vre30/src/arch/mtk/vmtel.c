#ifdef __VRE__
#include "mmi_include.h"
#include "SimDetectionGprot.h"

#include "UcmGProt.h"
#if defined(__VRE_RB_09A__)
#include "DevConfigGprot.h"
#endif

#include "vmtel.h"
#include "vmlog.h"
#include "vmstdlib.h"
#include "vmsim.h"
#include "vmopt.h"
#include "vmmod.h"
#include "vmpromng.h"
#include "vmresmng.h"

#if defined(__VRE_RB_09A__)
extern void MakeCall(PS8 strNumber);
#endif

extern VMINT vm_selected_simcard;
#if defined(__VRE_RB_09A__)
 /**
 * 系统配置用于Compile Option
 */
extern mmi_devconfig_system_config_struct sysconf;
#endif

static VMINT vm_callout_status;

#if defined(__VRE_RB_09A__)
static void vm_callout_ucm_callback(void* param)
#else
static mmi_ret vm_callout_ucm_callback(mmi_event_struct * param)
#endif
{
	//srv_ucm_status_change_evt_struct *evt = (srv_ucm_status_change_evt_struct *)param;
	VMINT resid = -1;
	VM_CALLOUT_RESPONSE_T callout_callback;
	VMWSTR phonenum = NULL;
	VMINT size = 0;

	VMINT callcount = 0;

	/*根据系统回调设置callout状态*/
#if defined(__VRE_RB_09A__)
	callcount = mmi_ucm_app_incoming_call(MMI_UCM_CALL_TYPE_ALL) + 
	                 mmi_ucm_app_outgoing_call(MMI_UCM_CALL_TYPE_ALL) + 
	                 mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_NO_CSD) ;
#else
	callcount = srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL);
#endif

	vm_log_debug("vm_callout_ucm_callback : callcount=%d", callcount);
	if (callcount > 0)
	{
		vm_callout_status = VM_CALLOUT_BUSY;
	}
	else
	{
		vm_callout_status = VM_CALLOUT_IDEL;
		
	}

	/*调用用户回调函数*/
	if ((resid = vm_res_findfirst(-1, VM_RES_TYPE_CALLOUT)) != VM_RES_NOT_FIND)
	{
		VM_P_HANDLE phandle = vm_res_get_process_handle(VM_RES_TYPE_CALLOUT, resid);
		vm_res_get_callback(VM_RES_TYPE_CALLOUT, resid, (void**)&callout_callback);
		vm_res_get_data(VM_RES_TYPE_CALLOUT, resid, (void**)&phonenum, &size);

		if (vm_pmng_set_ctx(phandle) == VM_PMNG_OP_OK)
		{
			if (callout_callback != NULL)
			{
				callout_callback(phonenum, vm_callout_status);
			}

			/*恢复现场*/
			vm_pmng_reset_ctx();
		}

		if (vm_callout_status == VM_CALLOUT_IDEL)
		{
			vm_res_release_data(VM_RES_TYPE_CALLOUT, resid);
		}
		
		vm_res_findclose(VM_RES_TYPE_CALLOUT);
		
	}
#if !defined(__VRE_RB_09A__)
	return MMI_RET_OK;
#endif
}


/**
 * 进程状态处理机
 */
static void vm_callout_process_state_pro(VM_P_HANDLE phandle, VMINT pro_state)
{
	VMINT resid = 0;
	
	switch(pro_state)
	{
		case VM_PMNG_UNLOAD:
			while ((resid = vm_res_findfirst(phandle, VM_RES_TYPE_CALLOUT)) != VM_RES_NOT_FIND)
			{
				vm_res_release_data(VM_RES_TYPE_CALLOUT, resid);		
				vm_res_findclose(VM_RES_TYPE_CALLOUT);		
			}				
			break;
		case VM_PMNG_FOREGROUND:
			break;
		case VM_PMNG_BACKGROUND:
			break;
	}
}


static void vm_callout_initial(void)
{
	VMINT callcount = 0;

#if defined(__VRE_RB_09A__)
	callcount = mmi_ucm_app_incoming_call(MMI_UCM_CALL_TYPE_ALL) + 
	                 mmi_ucm_app_outgoing_call(MMI_UCM_CALL_TYPE_ALL) + 
	                 mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_NO_CSD) ;
#else
	callcount = srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL);	
#endif
	
	if (callcount > 0)
	{
		vm_callout_status = VM_CALLOUT_BUSY;
	}
	else
	{
		vm_callout_status = VM_CALLOUT_IDEL;
	}

#if defined(__VRE_RB_09A__)
	mmi_ucm_reg_call_status_change_cb(MMI_UCM_CB_VRE, vm_callout_ucm_callback, NULL);
#else
	mmi_frm_cb_reg_event(EVT_ID_SRV_UCM_STATUS_CHANGE, vm_callout_ucm_callback, NULL);
#endif

	vm_res_type_set_notify_callback(VM_RES_TYPE_CALLOUT, vm_callout_process_state_pro);	
}

static void vm_callout_finialize(void)
{
	VMINT callcount = 0;

	vm_res_type_set_notify_callback(VM_RES_TYPE_CALLOUT, NULL);

#if defined(__VRE_RB_09A__)
	mmi_ucm_unreg_call_status_change_cb(MMI_UCM_CB_VRE);

	callcount = mmi_ucm_app_incoming_call(MMI_UCM_CALL_TYPE_ALL) + 
	                 mmi_ucm_app_outgoing_call(MMI_UCM_CALL_TYPE_ALL) + 
	                 mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_NO_CSD) ;
#else
	mmi_frm_cb_dereg_event(EVT_ID_SRV_UCM_STATUS_CHANGE, vm_callout_ucm_callback, NULL);
	
	callcount = srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL);	
#endif

	if (callcount > 0)
	{
		vm_callout_status = VM_CALLOUT_BUSY;
	}
	else
	{
		vm_callout_status = VM_CALLOUT_IDEL;
	}

	vm_log_debug("vm_callout_finialize : callcount=%d, status=%d", callcount, vm_callout_status);
}

 static VMINT vm_callout_mod_evt_proc(VRE_MOD_LIFECIRCLE_EVT event)
{
	switch(event)
	{
		case EVT_MOD_INIT:
			vm_callout_initial();
			break;
 		case EVT_MOD_RELEASE:
			vm_callout_finialize();
			break;
	}
	return 0;
}

 VMINT _vm_reg_callout_module(void)
{
	int res = 0;

	if ((res = _vm_reg_module("CALLOUT MODULE", (MOD_EVT_PROCESS)vm_callout_mod_evt_proc)) 
		!= REG_VRE_MODULE_SUCCESS)
	{
		vm_log_debug("_vm_reg_callout_modual : failed to register callout module. errorcode=%d", res);
	}
	return res;
}

 static VMINT vm_available_phnum(VMWSTR phnum)
{
	while(*phnum != 0)
	{
		if (   *phnum != (VMWCHAR)L'0'
			&& *phnum != (VMWCHAR)L'1'
			&& *phnum != (VMWCHAR)L'2'
			&& *phnum != (VMWCHAR)L'3'
			&& *phnum != (VMWCHAR)L'4'
			&& *phnum != (VMWCHAR)L'5'
			&& *phnum != (VMWCHAR)L'6'
			&& *phnum != (VMWCHAR)L'7'
			&& *phnum != (VMWCHAR)L'8'
			&& *phnum != (VMWCHAR)L'9'
			&& *phnum != (VMWCHAR)L'*'
			&& *phnum != (VMWCHAR)L'#')
		{
			return FALSE;
		}
		phnum++;
	}
	return TRUE;
}

VMINT vm_callout_ex(VMWSTR phnum, VM_CALLOUT_RESPONSE_T callback)
{
	VM_P_HANDLE phandle =  vm_pmng_get_current_handle();
	VMINT resid = -1;
	
#if !defined(__VRE_RB_09A__)
	mmi_ucm_make_call_para_struct  make_call_para;
	VMUINT16 gid = 0; /*ucm参数，为screen group id，现在预备，以后修改*/
#endif

	if (vm_pmng_state(phandle) != VM_PMNG_FOREGROUND)
	{
		vm_log_debug("vm_callout: state is not foreground");
		return VM_CALLOUT_ERR_STATE;
	}
	/*无sim卡，返回错误*/
	if (vm_sim_card_count() <= 0)
	{
		vm_log_debug("vm_callout: no sim card");
		return VM_CALLOUT_ERR_NO_SIM;
	}
	/*飞行模式，返回错误*/
	if (mmi_bootup_get_active_flight_mode() == TRUE)
	{
		vm_log_debug("vm_callout: flight mode");
		return VM_CALLOUT_ERR_FLIGHT;
	}
	/*设备忙，返回错误*/
	if (vm_callout_status != VM_CALLOUT_IDEL)
	{
		vm_log_debug("vm_callout: device is busy now");
		return VM_CALLOUT_ERR_BUSY;
	}
	/*电话号码非法，返回错误*/
	if (phnum == NULL)
	{
		vm_log_debug("vm_callout : the ptr of phnum is NULL");
		return VM_CALLOUT_ERR_PHONE_NUM;
	}
	if ((vm_wstrlen(phnum) <= 0) || (vm_wstrlen(phnum) >= 40))
	{
		vm_log_debug("vm_callout : the len of phnum is error");
		return VM_CALLOUT_ERR_PHONE_NUM;
	}
	if (vm_available_phnum(phnum) == FALSE)
	{
		vm_log_debug("vm_callout : the content of phnum is error");
		return VM_CALLOUT_ERR_PHONE_NUM;
	}
	if (phandle < 0)
	{
		vm_log_debug("vm_callout : phandle is error");
		return VM_CALLOUT_ERR_PROCESS;
	}
	/*向资源管理器申请电话外拨资源*/
	if ((resid = vm_res_save_data(VM_RES_TYPE_CALLOUT, phnum, (vm_wstrlen(phnum) * 2), (void*)callback, phandle)) < 0)
	{
		vm_log_debug("vm_callout: res save error");
		return VM_CALLOUT_ERR_NO_RES;
	}

#if defined(__VRE_RB_09A__)
	if (sysconf.dual_sim_master == MMI_TRUE)
	{
	//#ifdef VRE_DUAL_SIM
		vm_log_debug("vm_callout : before mmi_ucm_app_make_call");
		if(vm_selected_simcard == 2)
		{
    			mmi_ucm_app_make_call(MMI_UCM_VOICE_CALL_TYPE_SIM2, (U8 *)phnum);
		}
		else
		{
			mmi_ucm_app_make_call(MMI_UCM_VOICE_CALL_TYPE, (U8 *)phnum);
		}
	}
	//#else
	else
	{
		vm_log_debug("vm_callout : before make call");
		MakeCall((PS8)phnum);
	}
#else
	/*调用底层接口，外拨电话*/
	vm_log_debug("vm_callout : before mmi_ucm_init_call_para");
	mmi_ucm_init_call_para(&make_call_para);  
	vm_log_debug("vm_callout : after mmi_ucm_init_call_para");

	if(vm_selected_simcard == 2)
    	{
       	make_call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM2;
    	}
       else
       {
       	make_call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE;
       }
	make_call_para.ucs2_num_uri = (U16*)phnum;
    
	vm_log_debug("vm_callout : before mmi_ucm_call_launch");
	mmi_ucm_call_launch(gid, &make_call_para);	
	vm_log_debug("vm_callout : after mmi_ucm_call_launch");
#endif
	
	return VM_CALLOUT_NO_ERR;
}

void vm_callout(VMWSTR phnum) 
{
	vm_callout_ex(phnum, NULL);
}

#endif
 
