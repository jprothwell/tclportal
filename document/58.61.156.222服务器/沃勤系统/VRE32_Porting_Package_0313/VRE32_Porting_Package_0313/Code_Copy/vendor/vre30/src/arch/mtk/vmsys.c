#ifdef __VRE__
#include "mmi_include.h"
#include "DataAccountGProt.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "gpioInc.h"
#include "SimDetectionGexdcl.h"
#include "DevConfigGprot.h"

#include "med_main.h"
#include "med_api.h"
#if(!defined(__VRE_RB_09A__) && !defined(__VRE_RB_08A__))
#include "mmi_cb_mgr_gprot.h"
#endif

#include "AMDef.h"
#include "AMGprot.h"

#include "VREDef.h"
#include "vmopt.h"
#include "vmsys.h"
#include "gnu-malloc.h"
#include "vmlog.h"
#include "vmio.h"
#include "vmchset.h"
#include "vmwin.h"
#include "vmhttp.h"
#include "vmsim.h"
#include "vmgraph.h"
#include "vmgfxold.h"
#include "vmmod.h"
#include "vmvip.h"
#include "vmmem.h"
#include "vmstdlib.h"
#include "vmdl.h"
#include "vmnvram.h"
#include "vmmm.h"
#include "vmua.h"
#include "vmmacrostub.h"

#include "vmresmng.h"
#include "vmpromng.h"
#include "vmproevt.h"

#include "vmenv.h"

#include "vmstatusbar.h"

/* -------------------------------------------------------------------------- */
/* 手机系统全局函数引用。                                        				  */
/* -------------------------------------------------------------------------- */
extern U8 EntryNewScreen(U16 newscrnID, FuncPtr newExitHandler, FuncPtr newEntryHandler, void  *peerBuf);
extern U8 SetDelScrnIDCallbackHandler(U16 ScrnID, HistoryDelCBPtr funcPtr);
extern void GoBackHistory(void);
extern void applib_dt_get_rtc_time(applib_time_struct *t);
extern void mmi_ime_delete_editor_common_scr(U16 scr_id);
#if(!defined(__VRE_RB_09A__) && !defined(__VRE_RB_08A__))
extern U16 mmi_frm_group_enter_ex(U16 parent_id, U16 group_id, mmi_proc_func proc, void *user_data, S16 flag);
#endif

extern void vm_init_imei_number(void);
extern void vm_init_imsi_number(void);
extern void _vm_init_sim_card_status(void);
//extern void vm_set_log_out(int log_out);
//extern void vm_set_log_level(int log_level);
//extern void vm_set_log_mtk(int log_mtk);
extern int vre_get_options_log_level(void);
extern int vre_get_options_log_out(void);
extern int vre_get_options_log_mtk(void);
extern VMINT vre_options_init(char* filename);
extern void vm_nvram_init(void);
extern void vm_go_back_host_platform_history(void);
//extern void _vm_autorun(void);
#ifdef VM_SUPPORT_SMS_NO_POPUP
extern void	vm_set_sms_no_popup(void);
#endif
extern void	init_chset_memory(void);
extern void	free_chset_memory(void);

extern void * am_mem_ptr;
/* -------------------------------------------------------------------------- */
/* 系统模块的全局变量                                                   */
/* -------------------------------------------------------------------------- */
/*
 * VRE正在运行标志。
 */
VMINT vre_running = FALSE;
VMINT is_gobackhistory = FALSE;

/**
 * 系统配置用于Compile Option
 */
mmi_devconfig_system_config_struct sysconf;

vm_local_info current_local_info;

/* -------------------------------------------------------------------------- */
/* 被其它模块引用到的函数。                                  */
/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */
/* 局部变量声明。                                                             */
/* -------------------------------------------------------------------------- */
/*
 * VAM注册上来的回调函数，VRE在ASM分配成功或强制退出时
 * 通知VAM。
 */
vm_vre_evt_cb_t vam_callback = NULL;
/* -------------------------------------------------------------------------- */
/* 局部函数声明。                                                             */
/* -------------------------------------------------------------------------- */
/**
 * ASM分配了内存以后重入的函数。
 */
static void vm_asm_alloc_entry(void);
/************************************************/
/**************函数实现******************/
/***********************************************/
VMUINT8* vm_graphic_get_resource(VMINT resid,VMINT* len)
{
	return NULL;
}

void vm_vre_init(void)
{
	/* add by zaiping.chen, 2010.07.23, begin */
	extern void vm_wlan_event_notify_set(void);
	
	/* need be called in InitializeAll() */
	vm_wlan_event_notify_set();
	/* add by zaiping.chen, 2010.07.23, end */

	vm_init_imei_number();
	vm_init_imsi_number();

	return;
}

VMINT vm_get_time(vm_time_t* time) 
{
	applib_time_struct mt;

	if (time == NULL)
	{
		//vm_log_debug("vm_get_time : malloc vm_time_t fail");
		return -1;
	}
	
	memset(time, 0x00, sizeof(vm_time_t));
	
    	applib_dt_get_rtc_time(&mt);
		
	time->year = mt.nYear;
	time->mon = mt.nMonth;
	time->day = mt.nDay;
	time->hour = mt.nHour;
	time->min = mt.nMin;
	time->sec = mt.nSec;
	
	return 0;
}

void vre_folder_init(void)
{
     VMINT findhandle;
     vm_fileinfo_ext fileinfo;
     char path[30] = {0};
     VMINT file_drv;
     
     file_drv = vm_get_removeable_driver();
     if(file_drv < 0)
         file_drv = vm_get_system_driver();
     sprintf(path, "%c:\\vre", file_drv); 
     if ((findhandle = vm_find_first_ext(vm_ucs2_string_by_ascii(path), &fileinfo)) >= 0)
     {
          if(findhandle >= 0)
          {
               vm_find_close_ext(findhandle);
               if((fileinfo.attributes & 0x10) == 0)//文件
               {
                   vm_file_delete(vm_ucs2_string_by_ascii(path));
               }
          }
     }
     vm_file_mkdir(vm_ucs2_string_by_ascii(path));
}
static VMINT vm_never_call_mmi_dtcnt_ready_check_on_background = TRUE;
static void vre_init_dataaccount_callback(void)
{
	if (vam_callback)
	{
		vm_log_debug("vam_callback = %x, vre_init_dataaccount_callback", vam_callback);
			vam_callback(VRE_EVT_START_SUCCESS);
	}
}

static VMINT vre_check_am_is_quick_start(void)
{
    return mmi_am_check_is_quick_start();
}
    
static VMINT vre_dataaccount_ready_check(void)
{
	if (vm_never_call_mmi_dtcnt_ready_check_on_background == TRUE)
	{
		vm_never_call_mmi_dtcnt_ready_check_on_background = FALSE;
#if (defined(__VRE_RB_08A__))
		/* 在08A上还是调用DataAccountReadyCheck会重启  */
		if (vre_check_am_is_quick_start())
		{
			mmi_dtcnt_ready_check_on_background(vre_init_dataaccount_callback);
		}
#else
		mmi_dtcnt_ready_check_on_background(vre_init_dataaccount_callback);
#endif
	}
}

VMINT vm_start_vre_envirment(vm_vre_evt_cb_t vam_cb, VMINT state)
{	
	vam_callback = vam_cb;
	is_gobackhistory = FALSE;

	mmi_devconfig_get_system_config(&sysconf);
	
	if (!vre_running)
	{
		VMUINT8* kernel_mem_base = NULL;
		VMCHAR log_filename[50];
		VMCHAR options_filename[50];
		VMINT drv;

		/* Mass storgage. 		*/
		if (stub_mmi_usb_is_in_mass_storage_mode())
		{
			return VM_VLC_MASS_STORAGE;
		}

		/* Initialize log system. 		*/
		if ((drv = vm_get_removeable_driver()) < 0)
		{
			drv = (char)vm_get_system_driver();
		}
		sprintf(log_filename, "%c:\\vre.log", drv);
		vm_log_init(log_filename, VM_DEBUG_LEVEL); 		
		vm_log_info("VRE initialize....");	
				
		/* Initialize VRE Kernel memory for heap segment.	*/
		_vm_init_mem_pool();
		if ((kernel_mem_base = _vm_alloc_app_seg_mem(0, NULL, VRE_30_KERNEL_MEM_SIZE, TRUE)) != NULL)
		{
			if (_vm_set_app_heap_attr_mem(0, kernel_mem_base, VRE_30_KERNEL_MEM_SIZE) != 0)
			{
				_vm_free_app_seg_mem(0);
				
				if (state && vam_callback)
				{
					vam_callback(VRE_EVT_START_INTERNEL_ERROR);
				}
				return VM_VLC_INTERNEL_ERROR;
			}
		}
		else
		{
			_vm_prompt_to_release_mem(VRE_30_KERNEL_MEM_SIZE, vm_asm_alloc_entry, TRUE);
			return VM_VLC_ASYN_ALLOC_ASM;
		}
		
		/* add by zaiping.chen, 2010.07.15, static memory optimize, begin */
		init_chset_memory();
		/* add by zaiping.chen, 2010.07.15, static memory optimize, end */

		/* 初始化进程管理器。			*/
		if (vm_pmng_init() != 0)
		{
			_vm_free_app_seg_mem(0);
			
			if (state && vam_callback)
			{
				vam_callback(VRE_EVT_START_INTERNEL_ERROR);
			}

			return VM_VLC_INTERNEL_ERROR;
		}
		
		/*  资源管理器初始化。 		*/
		if (vm_res_init() != 0)
		{
			vm_pmng_finialize();
			
			_vm_free_app_seg_mem(0);
			
			if (state && vam_callback)
			{
				vam_callback(VRE_EVT_START_INTERNEL_ERROR);
			}
			return VM_VLC_INTERNEL_ERROR;
		}

		/* 置VRE运行标志					*/			
		vre_running = TRUE;
		vm_vre_init();
		vm_nvram_init();
		
	 	/* 注册VRE各个模块并初始化。*/
		_vm_initizlize_module_manager();
		_vm_reg_modules();
		if (_vm_notify_modules(EVT_MOD_INIT) != 0)
		{
			vm_log_fatal("vm_start_vre_envirment : Failed to setup vre modules");
			vm_exit();

			if (state && vam_callback)
			{
				vam_callback(VRE_EVT_START_INTERNEL_ERROR);
			}
			return VM_VLC_INTERNEL_ERROR;
		}	

		/* 初始化SIM卡的状态 			*/
		_vm_init_sim_card_status();
		
		vm_log_info("VRE initialize complete. VRE version is %s.", VRE_SYS_VRESION_NUMBER);
		
		sprintf(options_filename, "%c:\\vre.cfg", drv);
		vre_options_init(options_filename);
		//vm_set_log_out(vre_get_options_log_out());
		//vm_set_log_mtk(vre_get_options_log_mtk());
		//vm_set_log_level(vre_get_options_log_level());	
		vre_folder_init();

	  	vm_log_debug("vm_start_vre_envirment:log_out=%d, log_mtk=%d, log_level =%d",vre_get_options_log_out(), vre_get_options_log_mtk(),vre_get_options_log_level());

#if (defined(__VRE_RB_09A__) )
		/* 获取短信中心号码*/
		vm_sms_init_sc_addr();
#endif

		vm_get_local_setting(&current_local_info);


		//注册statusbar icon点击函数
#if defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_VUI_HOMESCREEN__)
		vm_register_status_icon_pen_event();
#endif	
		
		if (state && vam_callback)
		{
			vm_log_debug("vam_callback = %x, vam_callback", vam_callback);
            
			vre_dataaccount_ready_check();
            return VM_VLC_ASYN_DATAACCOUNT_CHECK;
		}

		kal_wap_trace(MOD_MMI, TRACE_GROUP_7, "[MOD_VRE]vm_start_vre_envirment ------- [end]");
		return VM_VLC_START_SUCCESS;
	}

	/* 初始化SIM卡的状态 			*/
	_vm_init_sim_card_status();
	vm_get_local_setting(&current_local_info);
	return VM_VLC_START_SUCCESS;
}

VMINT vm_get_tick_count(void)
{
	kal_uint32 time;

	kal_get_time(&time);
	return kal_ticks_to_milli_secs(time);
}

void vm_stop_vre_envirment(void)
{
	if (vre_running)
	{
		vm_pmng_finialize();
	
		_vm_notify_modules(EVT_MOD_RELEASE);
		_vm_destory_module_manager();

		vm_res_finialize();

		mmi_frm_clear_interrupt_event_handler(MMI_FRM_INT_FMGR_CARD);
		ClearKeyEvents();
		mmi_pen_reset();

		//注销statusbar icon点击函数
#if defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_VUI_HOMESCREEN__)
		vm_reset_status_icon_pen_event();
#endif
			
		/* add by zaiping.chen, 2010.07.15, static memory optimize, begin */
		free_chset_memory();
		/* add by zaiping.chen, 2010.07.15, static memory optimize, end */

		_vm_free_app_seg_mem(0);
		
		vm_log_info("VRE finialize...");
		vm_log_close();

		vam_callback = NULL;
		vre_running = FALSE;
		
	}
}

void vm_clear_all_key_events(void)
{
	ClearKeyEvents();
}

void vm_clear_all_pen_events(void)
{
	mmi_pen_reset();
}

#ifdef VRE_SUPPORT_SCREEN_GROUP_FRAMEWOK
static VMUINT8 (*vm_promng_del_screen_handler)(void*) = NULL;
static mmi_ret vm_vre_screen_delete_callback_wrap(mmi_event_struct *param)
{
	kal_wap_trace(MOD_MMI, TRACE_GROUP_7, "[MOD_VRE]vm_vre_screen_delete_callback_wrap ------- [start]");
	if (param)
	{
		vm_log_debug("leave proc event id = %d", param->evt_id);
	}

	switch (param->evt_id)
	{
	case EVT_ID_SCRN_GOBACK_IN_END_KEY:
	case EVT_ID_SCRN_DELETE_REQ:
	case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
	   	if (vre_running && vm_promng_del_screen_handler)
		{
			vm_promng_del_screen_handler(NULL);
		}
		break;
	case EVT_ID_SCRN_GOBACK:
		break;
	case EVT_ID_SCRN_DEINIT:
		vm_promng_del_screen_handler = NULL;
		break;
	default:
		break;
	}
	return MMI_RET_OK;
	kal_wap_trace(MOD_MMI, TRACE_GROUP_7, "[MOD_VRE]vm_vre_screen_delete_callback_wrap ------- [end]");
}
#endif

VMINT vm_entry_host_platform_new_screen_group(void)
{
#ifdef VRE_SUPPORT_SCREEN_GROUP_FRAMEWOK
	mmi_frm_group_enter_ex(GRP_ID_ROOT, 
		GRP_ID_VRE, NULL, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
	return TRUE;
#else
	return TRUE;
#endif
}

VMUINT vm_entry_host_platform_new_screen(void (*exitHandler)(void), void (*entryHandler)(void), 
	VMUINT8 (*delHandler)(void*))
{
#ifdef VRE_SUPPORT_SCREEN_GROUP_FRAMEWOK
	mmi_frm_scrn_enter(GRP_ID_VRE, VRE_SCREEN_ID, (FuncPtr)exitHandler, 
		(FuncPtr)entryHandler, MMI_FRM_FULL_SCRN);

	vm_promng_del_screen_handler = delHandler;
	mmi_frm_scrn_set_leave_proc(GRP_ID_VRE, VRE_SCREEN_ID, 
		(mmi_proc_func)vm_vre_screen_delete_callback_wrap);
	entry_full_screen();
#ifdef VM_SUPPORT_SMS_NO_POPUP
	vm_set_sms_no_popup();
#endif

	return TRUE;
#else
	VMUINT ret = EntryNewScreen(VRE_SCREEN_ID, (FuncPtr)exitHandler, 
		(FuncPtr)entryHandler, MMI_FULL_SCREEN);
	SetDelScrnIDCallbackHandler(VRE_SCREEN_ID, (HistoryDelCBPtr)delHandler);
	entry_full_screen();
#ifdef VM_SUPPORT_SMS_NO_POPUP
	vm_set_sms_no_popup();
#endif

	return ret;
#endif
}

void vm_go_back_host_platform_history(void)
{
kal_wap_trace(MOD_MMI, TRACE_GROUP_7, "[MOD_VRE]vm_go_back_host_platform_history ------- [start]");
#ifdef VRE_SUPPORT_SCREEN_GROUP_FRAMEWOK
	if (mmi_frm_scrn_get_active_id() == VRE_SCREEN_ID)
	{
		leave_full_screen();
		mmi_frm_scrn_close_active_id();
	}	
#else
	if(GetActiveScreenId() == VRE_SCREEN_ID)
	{
		leave_full_screen();
		/*设置gobackhistory标志位*/
		is_gobackhistory = TRUE;
		
		kal_wap_trace(MOD_MMI, TRACE_GROUP_7, "[MOD_VRE]vm_go_back_host_platform_history ----will gobackhistory");
		GoBackHistory();
	}
#endif
kal_wap_trace(MOD_MMI, TRACE_GROUP_7, "[MOD_VRE]vm_go_back_host_platform_history ------- [end]");
}

void vm_del_vre_and_input_platform_screen(void)
{
#if(!defined(__VRE_RB_08A__) && !defined(__VRE_RB_08B__))
	mmi_ime_delete_editor_common_scr(
			VRE_INPUT_SCREEN_ID);
#endif
#ifdef VRE_SUPPORT_SCREEN_GROUP_FRAMEWOK
	mmi_frm_group_close(GRP_ID_VRE);
#else
	DeleteScreenIfPresent(VRE_INPUT_SCREEN_ID);
	DeleteScreenIfPresent(VRE_SCREEN_ID);
#endif
}

VMINT vm_vre_platform_screen_is_active_screen(void)
{
#ifdef VRE_SUPPORT_SCREEN_GROUP_FRAMEWOK
	if (mmi_frm_scrn_get_active_id() == VRE_SCREEN_ID)
		return TRUE;
#else
	if(GetActiveScreenId() == VRE_SCREEN_ID)
		return TRUE;
#endif
	return FALSE;
}

static void vm_asm_alloc_entry(void)
{
	vm_start_vre_envirment(vam_callback, 1);
}




static void sys_pen_down_proc(mmi_pen_point_struct pos)
{
	vm_pmng_deal_pen_event(VM_PEN_EVENT_TAP, pos.x, pos.y);
}

static void sys_pen_up_proc(mmi_pen_point_struct pos)
{
	vm_pmng_deal_pen_event(VM_PEN_EVENT_RELEASE, pos.x, pos.y);
}

static void sys_pen_move_proc(mmi_pen_point_struct pos)
{
	vm_pmng_deal_pen_event(VM_PEN_EVENT_MOVE, pos.x, pos.y);
}

static void sys_pen_long_tap_proc(mmi_pen_point_struct pos)
{
	vm_pmng_deal_pen_event(VM_PEN_EVENT_LONG_TAP, pos.x, pos.y);
}

static void sys_pen_double_click_proc(mmi_pen_point_struct pos)
{
	vm_pmng_deal_pen_event(VM_PEN_EVENT_DOUBLE_CLICK, pos.x, pos.y);
}

static void sys_pen_repeat_proc(mmi_pen_point_struct pos)
{
	vm_pmng_deal_pen_event(VM_PEN_EVENT_REPEAT, pos.x, pos.y);
}

void vm_reg_pen_handler(void) 
{
	mmi_pen_register_down_handler(sys_pen_down_proc);
	mmi_pen_register_up_handler(sys_pen_up_proc);
	mmi_pen_register_move_handler(sys_pen_move_proc);
	mmi_pen_register_long_tap_handler(sys_pen_long_tap_proc);
	mmi_pen_register_double_click_handler(sys_pen_double_click_proc);
	mmi_pen_register_repeat_handler(sys_pen_repeat_proc);
}

static VMINT vm_query_userid(void)
{
	vm_nvram_sysconf_t sys_conf;

	if (vm_get_sysconf(&sys_conf))
		return sys_conf.uid;
	else
		return -1;
}

VMINT mmi_vre_pre_format_hdlr(VMINT8 drv)
{
	return (!vre_running);
}

VMUINT vm_get_sys_property(const VMINT key, VMCHAR* value, VMUINT len)
{
	VMCHAR s[64] = {0};
	VMUINT length = 0;
	VMINT tmp = -1;
	VMWCHAR home_dir[31] = {0};
	
	if (value && len > 0)
	{
		switch(key)
		{
		case VRE_SYS_SUBSCRIBER_ID:	
			if ((tmp = vm_query_userid()) < 0)
				break;
			
			sprintf(s, "%d", tmp);
			length = strlen(s);
			if (length >= len)
				length = len - 1;
			strncpy(value, s, length);
			value[length] = '\0';
			break;
		case VRE_SYS_EQUIPMENT_ID:
			length = vm_get_useragent(value, len);
			break;
		case VRE_SYS_VERSION:
			length = strlen(VRE_SYS_VRESION_NUMBER);
			if (length >= len)
				length = len - 1;
			strncpy(value, VRE_SYS_VRESION_NUMBER, length);
			value[length] = '\0';
			break;
		case VRE_SYS_HOST_VERSION:
			length = vm_get_host_version(value, len);
			break;
		case VRE_SYS_HOME_DIR:
			if ((tmp = vm_get_removable_driver()) < 0)
				tmp = vm_get_system_driver();
			sprintf(s, "%c:\\VRE", (char)tmp);
			vm_ascii_to_ucs2(home_dir, sizeof(home_dir), s);
			vm_file_mkdir(home_dir);
			
			length = strlen(s);
			if (length >= len)
				length = len - 1;
			strncpy(value, s, length);
			value[length] = '\0';
			break;
		case VRE_SYS_HOST_MAX_MEM:
			sprintf(s, "%d", ((sysconf.memory_size) >> 10));

			length = strlen(s);
			if (length >= len)
				length = len - 1;
			strncpy(value, s, length);
			value[length] = '\0';
			break;
		}
	}

	return length;
}

/*获取手机当前城市时区的时差。*/
extern FLOAT GetTimeZone(U8 cityIndex);
extern U8 PhnsetGetHomeCity(void);
float vm_get_sys_time_zone(void)
{
	return GetTimeZone(PhnsetGetHomeCity());
}

/*获取手机情景模式。*/
extern U8 gactivatedprofile;
VMINT vm_get_sys_scene(void)
{
	return gactivatedprofile;
}

/*获取电池电量等级。*/
VMINT vm_get_battery_level(void) 
{
	return stub_vm_get_battery_level();
}

void vm_leave_full_screen(void)
{
	leave_full_screen();
}
#endif
