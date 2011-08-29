#ifdef __VRE__
#include "mmi_include.h"

#if (!defined(__VRE_RB_08A__) && !defined(__VRE_RB_08B__))
#include "Browser_api.h"
#include "GeneralDeviceGprot.h"
#endif

#if (defined(__VRE_RB_08A__) || defined(__VRE_RB_08B__))
#include "gpioInc.h"
#endif

#include "VREDef.h"
#include "vmio.h"
#include "vmlog.h"
#include "vmsys.h"
#include "vmstdlib.h" 
#include "vmopt.h"
#include "vmmod.h"

#include "vmresmng.h"
#include "vmproevt.h"
#include "vmpromng.h"

#define ALWAYS_ASK_SIM_INFO_SIM1    				CBM_SIM_ID_SIM1
#define ALWAYS_ASK_SIM_INFO_SIM2    				CBM_SIM_ID_SIM2
#define INPUT_TYPE_NUMERIC_PASSWORD 				IMM_INPUT_TYPE_NUMERIC_PASSWORD
#define INPUT_TYPE_NUMERIC          					IMM_INPUT_TYPE_NUMERIC
#define INPUT_TYPE_DECIMAL_NUMERIC  				IMM_INPUT_TYPE_DECIMAL_NUMERIC
#define INPUT_TYPE_ALPHANUMERIC_PASSWORD    		IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD
#define INPUT_TYPE_ALPHANUMERIC_SENTENCECASE    	IMM_INPUT_TYPE_SENTENCE
#define INPUT_TYPE_PHONE_NUMBER     				IMM_INPUT_TYPE_PHONE_NUMBER
#define INPUT_TYPE_ALPHANUMERIC_LOWERCASE  		IMM_INPUT_TYPE_SENTENCE

#ifdef VM_SUPPORT_SMS_NO_POPUP
extern void	vm_set_sms_no_popup(void);
#endif
/* -------------------------------------------------------------------------- */
/* 模块内部函数声明。                                                         */
/* -------------------------------------------------------------------------- */
#define MAX_SIZE_OF_INPUT 250

/**
 * VRE 的输入缓冲。改成动态分配
 */
//static VMWCHAR vre_input_text[MAX_SIZE_OF_INPUT + 1];

/**
 * 从到MTK函数里的输入缓冲。
 */
static VMWSTR input_text_ptr = NULL;

/**
 * 默认输入法。
 */
static VMINT vm_input_mode = IMM_INPUT_TYPE_MULTITAP_SENTENCE;

/**
 * 默认的输入缓冲的字节个数。
 */
static VMINT vm_input_size = MAX_SIZE_OF_INPUT;

struct  vm_power_saving_controller_t
{
	VMINT vm_power_saving_switch;
	VMINT vm_process_handle;
};

/**
 * 节电模式的控制块。
 */
static struct vm_power_saving_controller_t vm_power_saving_controller = {TRUE, 0};

/*
 * 检查当前进程的是否有调用权限。
 */
static VMINT entry_input_screen(VMWSTR input_txt_buffer, VMINT input_buffer_size,
	VMINT input_mode, void (*app_input_callback)(VMINT state, VMWSTR text));

/**
 * 进入MTK的输入界面。
 */
static void vm_show_ime_screen(void);

/*
 * 输入完毕后回调用户钩子函数。
 */
static void do_input_ok(void);
static void do_input_cancel(void);

static void vm_ime_process_staus_callback(VM_P_HANDLE process_handle, 
	VMINT sys_state)
{
	VMINT rHandle = 0;

	switch (sys_state)
	{
	case VM_PMNG_UNLOAD:
		while ((rHandle = vm_res_findfirst(process_handle, VM_RES_TYPE_IME)) != VM_RES_NOT_FIND)
		{
			vm_res_findclose(VM_RES_TYPE_IME);
			vm_res_release_data(VM_RES_TYPE_IME, rHandle);
		}
	case VM_PMNG_BACKGROUND:
		if (process_handle == vm_power_saving_controller.vm_process_handle
			&& vm_power_saving_controller.vm_power_saving_switch == FALSE)
		{
			TurnOnBacklight(GPIO_BACKLIGHT_SHORT_TIME);
			TurnOffBacklight();
			vm_power_saving_controller.vm_power_saving_switch = TRUE;
			vm_power_saving_controller.vm_process_handle = 0;
		}
		break;
	}
}

static VMINT vm_initialize_ime(void)
{
	if (!vm_power_saving_controller.vm_power_saving_switch)
	{
		TurnOnBacklight(GPIO_BACKLIGHT_SHORT_TIME);
		TurnOffBacklight();
	}
	vm_power_saving_controller.vm_power_saving_switch = TRUE;
	vm_power_saving_controller.vm_process_handle = 0;

	if (vm_res_type_set_notify_callback(
		VM_RES_TYPE_IME, vm_ime_process_staus_callback) != 0)
		return -1;
	return 0;
}

static VMINT vm_finialize_ime(void)
{
	VMINT rHandle = VM_RES_NOT_FIND;

	if (!vm_power_saving_controller.vm_power_saving_switch)
	{
		TurnOnBacklight(GPIO_BACKLIGHT_SHORT_TIME);
		TurnOffBacklight();
	}
	vm_power_saving_controller.vm_power_saving_switch = TRUE;
	vm_power_saving_controller.vm_process_handle = 0;

	while ((rHandle = vm_res_findfirst(-1, VM_RES_TYPE_IME)) != VM_RES_NOT_FIND)
	{
		vm_res_findclose(VM_RES_TYPE_IME);
		vm_res_release_data(VM_RES_TYPE_IME, rHandle);
	}
	vm_res_type_set_notify_callback(VM_RES_TYPE_IME, NULL);

	return 0;
}

static VMINT vm_ime_mod_evt_proc(VRE_MOD_LIFECIRCLE_EVT event)
{
	switch(event)
	{
		case EVT_MOD_INIT:
			vm_initialize_ime();
			break;
 		case EVT_MOD_RELEASE:
			vm_finialize_ime();
			break;
	}
	return 0;
}

VMINT _vm_reg_ime_module(void)
{
	int res_code = REG_VRE_MODULE_SUCCESS;
	
	if ((res_code = _vm_reg_module("IME MODULE", 
		(MOD_EVT_PROCESS)vm_ime_mod_evt_proc)) != REG_VRE_MODULE_SUCCESS)
	{
		vm_log_error("[IME MODULE]Failed to regisiter ime module. Error Code : %d", res_code);
	}

	return res_code;
}

static VMINT entry_input_screen(VMWSTR input_txt_buffer ,VMINT input_buffer_size, 
	VMINT input_mode, void (*app_input_callback)(VMINT state, VMWSTR text)) 
{
	VMINT rHandle = 0;
	VM_P_HANDLE pHandle = vm_pmng_get_current_handle();
	
	if (vm_pmng_state(pHandle) != VM_PMNG_FOREGROUND)
	{
		vm_log_warn("[IME MODULE]PID[%d] is not in foreground status.");
		return -1;
	}
	
	if ((rHandle = vm_res_save_data(VM_RES_TYPE_IME, NULL, 0, 
		(void*)app_input_callback,pHandle)) < 0)
	{
		vm_log_warn("[IME MODULE]PID[%d] is not allow entry ime scree.");
		return -2;
	}

	vm_input_mode = input_mode;
	input_text_ptr = input_txt_buffer;
	vm_input_size = input_buffer_size;
	vm_show_ime_screen();

	return 0;
}

#ifdef VRE_SUPPORT_SCREEN_GROUP_FRAMEWOK
mmi_ret vm_del_input_screen_handler(mmi_event_struct *param)
{
	VMINT rHandle = 0;
	VM_P_HANDLE pHandle = 0;

	if (param)
	{
		vm_log_debug("[IME MODULE]leave screen event id = %d", param->evt_id);
	}
	
	switch (param->evt_id)
	{
	case EVT_ID_SCRN_DEINIT:
		while ((rHandle = vm_res_findfirst(-1, VM_RES_TYPE_IME)) != VM_RES_NOT_FIND)
		{
			vm_res_findclose(VM_RES_TYPE_IME);
			
			if ((pHandle = vm_res_get_process_handle(VM_RES_TYPE_IME, rHandle)) >= 0)
			{
				if (vm_pmng_set_ctx(pHandle) == VM_PMNG_OP_OK)
				{
					//if (input_text_ptr != NULL && input_text_ptr != vre_input_text)
					if (input_text_ptr != NULL)
					{
						vm_free(input_text_ptr);
					}
					vm_pmng_reset_ctx();
				}
				input_text_ptr = NULL;
			}
			vm_res_release_data(VM_RES_TYPE_IME, rHandle);
		}
		
		break;
	default:
		break;
	}

	return MMI_RET_OK;
}
#else
static U8 vm_del_input_screen_handler(void* ptr)
{
	VMINT rHandle = 0;
	VM_P_HANDLE pHandle = 0;
	
	while ((rHandle = vm_res_findfirst(-1, VM_RES_TYPE_IME)) != VM_RES_NOT_FIND)
	{
		vm_res_findclose(VM_RES_TYPE_IME);
		vm_res_release_data(VM_RES_TYPE_IME, rHandle);

		if ((pHandle = vm_res_get_process_handle(VM_RES_TYPE_IME, rHandle)) >= 0)
		{
			if ((pHandle = vm_res_get_process_handle(VM_RES_TYPE_IME, rHandle)) >= 0)
			{
				if (vm_pmng_set_ctx(pHandle) == VM_PMNG_OP_OK)
				{
					//if (input_text_ptr != NULL && input_text_ptr != vre_input_text)
					if (input_text_ptr != NULL)
					{
						vm_free(input_text_ptr);
					}
					vm_pmng_reset_ctx();
				}
				input_text_ptr = NULL;
			}
		}
	}
	
	return FALSE;
}
#endif

static void vm_show_ime_screen(void)
{
	U8* gui_buffer = NULL;
	S32 ime = (S32)IMM_INPUT_TYPE_SENTENCE;
	
#ifdef VRE_SUPPORT_SCREEN_GROUP_FRAMEWOK
	mmi_frm_scrn_enter(GRP_ID_VRE, VRE_INPUT_SCREEN_ID, NULL, 
		(FuncPtr)vm_show_ime_screen, MMI_FRM_FULL_SCRN);
	mmi_frm_scrn_set_leave_proc(GRP_ID_VRE, VRE_INPUT_SCREEN_ID, 
		(mmi_proc_func)vm_del_input_screen_handler);
	gui_buffer = mmi_frm_scrn_get_active_gui_buf();
#else
	EntryNewScreen(VRE_INPUT_SCREEN_ID, NULL, (FuncPtr)vm_show_ime_screen, NULL);
	SetDelScrnIDCallbackHandler(VRE_INPUT_SCREEN_ID, (HistoryDelCBPtr)vm_del_input_screen_handler);
	gui_buffer = GetCurrGuiBuffer(VRE_INPUT_SCREEN_ID);
#endif

#ifdef VM_SUPPORT_SMS_NO_POPUP
	vm_set_sms_no_popup();
#endif

	//if (gui_buffer == NULL) 
	//{
	switch (vm_input_mode) 
	{
	case VM_INPUT_METHOD_PASSWORD:
		ime = (S32)IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD;		
		break;
	case VM_INPUT_METHOD_NUMERIC:
		ime = (S32)IMM_INPUT_TYPE_NUMERIC_SYMBOL;
		if (gui_buffer == NULL)
		{
			mmi_imm_set_app_desired_input_mode(IMM_INPUT_MODE_123_SYMBOLS);
		}
		break;
	case VM_INPUT_METHOD_ALPHABETIC:
		ime = (S32)IMM_INPUT_TYPE_ENGLISH_SENTENCE_LOWERCASE;
		if (gui_buffer == NULL)
		{
			mmi_imm_set_app_desired_input_mode(
				IMM_INPUT_MODE_MULTITAP_LOWERCASE_ABC);
		}
		break;
	default:
		ime = (S32)IMM_INPUT_TYPE_SENTENCE;
		if (gui_buffer == NULL)
		{
			mmi_imm_set_app_desired_input_mode(
				IMM_INPUT_MODE_SM_MULTITAP_PINYIN);
		}
		break;
	}
	//}

	ShowCategory5Screen(
		STR_VRE_TITLE, 
#ifdef __MMI_FTE_SUPPORT__
        0,
#else 		
		IMAGE_VRE_SMALL_ICON,
#endif		
		STR_GLOBAL_OK,
		IMG_GLOBAL_OK,
		STR_GLOBAL_BACK,
		IMG_GLOBAL_BACK,
		ime,
		(PU8)input_text_ptr,
		vm_input_size + 1,
		gui_buffer
	);

	SetLeftSoftkeyFunction(do_input_ok, KEY_EVENT_UP);
	SetCategory5RightSoftkeyFunction(
		do_input_cancel, KEY_EVENT_UP);
}

VMINT vm_input_text(void (*f)(VMINT state, VMWSTR text)) 
{
	/* changed by zaiping.chen, 2010.07.12, static memory optimize, begin */
#if 0
	if (f == NULL || !(vm_pmng_is_fg(VM_PMNG_CUR_HANDLE)))
		return -1;
	
	memset(vre_input_text, 0x00, sizeof(vre_input_text));
	return entry_input_screen(vre_input_text, MAX_SIZE_OF_INPUT, 
		VM_INPUT_METHOD_TEXT, f);
#endif
	
	VMWSTR input_buffer = NULL;
	
	if (f == NULL || !(vm_pmng_is_fg(VM_PMNG_CUR_HANDLE)))
		return -1;

	vm_log_debug("static memory optimize: vm_input_text - input_buffer");
	input_buffer = vm_calloc((MAX_SIZE_OF_INPUT + 1) * sizeof(VMWCHAR));
	if (NULL == input_buffer)
	{
		vm_log_error("vm_input_text vm_calloc fail");
		return -2;
	}

	return entry_input_screen(input_buffer, MAX_SIZE_OF_INPUT, 
		VM_INPUT_METHOD_TEXT, f);
	/* changed by zaiping.chen, 2010.07.12, static memory optimize, end */
}

VMINT vm_input_text2(VMWSTR default_string, VMINT default_input_method, 
	void (*f)(VMINT state, VMWSTR text))
{
	/* changed by zaiping.chen, 2010.07.12, static memory optimize, begin */
#if 0
	if (f == NULL || !(vm_pmng_is_fg(VM_PMNG_CUR_HANDLE)))
		return -1;

	/* 把默认字符拷贝到输入缓冲中。 */
	memset(vre_input_text, 0x00, sizeof(vre_input_text));
	if (default_string != NULL && default_string[0] != 0)
	{
		vm_wstrncpy(vre_input_text, default_string, 
			MAX_SIZE_OF_INPUT);
	}
	
	return entry_input_screen(vre_input_text, MAX_SIZE_OF_INPUT, 
		default_input_method, f);
#endif
	VMWSTR input_buffer = NULL;
	
	if (f == NULL || !(vm_pmng_is_fg(VM_PMNG_CUR_HANDLE)))
		return -1;

	vm_log_debug("static memory optimize: vm_input_text2 - input_buffer");
	input_buffer = vm_calloc((MAX_SIZE_OF_INPUT + 1) * sizeof(VMWCHAR));
	if (NULL == input_buffer)
	{
		vm_log_error("vm_input_text2 vm_calloc fail");
		return -2;
	}
		
	if (default_string != NULL && default_string[0] != 0)
	{
		vm_wstrncpy(input_buffer, default_string, 
			MAX_SIZE_OF_INPUT);
	}
	
	return entry_input_screen(input_buffer, MAX_SIZE_OF_INPUT, 
		default_input_method, f);
	/* changed by zaiping.chen, 2010.07.12, static memory optimize, end */
}

VMINT vm_input_text3(VMWSTR default_string, VMINT input_max_size, 
	VMINT default_input_method, void (*f)(VMINT state, VMWSTR text))
{
	VMWSTR input_buffer = NULL;

	if (f == NULL || input_max_size <= 0 || !(vm_pmng_is_fg(VM_PMNG_CUR_HANDLE)))
		return -1;

	/* changed by zaiping.chen, 2010.07.12, static memory optimize, begin */
#if 0
	if (input_max_size > MAX_SIZE_OF_INPUT)
	{
		if ((input_buffer = vm_malloc((input_max_size + 1) * sizeof(VMWCHAR))) == NULL)
		{
			return -2;
		}
		memset(input_buffer, 0x00, (input_max_size + 1) * sizeof(VMWCHAR));
	}
	else
	{
		memset(vre_input_text, 0x00, sizeof(vre_input_text));
		input_buffer = vre_input_text;
	}

	
	if (default_string != NULL && default_string[0] != 0)
	{
		vm_wstrncpy(input_buffer, default_string, input_max_size);
	}
	return entry_input_screen(input_buffer, input_max_size, 
		default_input_method, f);
#endif
	vm_log_debug("static memory optimize: vm_input_text3 - input_buffer");
	//if (input_max_size < MAX_SIZE_OF_INPUT)
	//{
	//	input_max_size = MAX_SIZE_OF_INPUT;
	//}
	input_buffer = vm_calloc((input_max_size + 1) * sizeof(VMWCHAR));
	if (NULL == input_buffer)
	{
		return -2;
	}
	
	if ((default_string != NULL) && (default_string[0] != 0))
	{
		vm_wstrncpy(input_buffer, default_string, input_max_size);
	}
	
	return entry_input_screen(input_buffer, input_max_size, 
		default_input_method, f);
	/* changed by zaiping.chen, 2010.07.12, static memory optimize, end */
}

void do_input_ok(void) 
{
	VMINT rHandle = 0;
	VM_P_HANDLE pHandle = 0;
	void (*app_callback)(VMINT state, VMWSTR text) = NULL;
	
	if (vm_res_get_data_list_count_by_type(VM_RES_TYPE_IME) != 1)
	{
#ifdef VRE_SUPPORT_SCREEN_GROUP_FRAMEWOK
		mmi_frm_scrn_close_active_id();
#else
		GoBackHistory();
#endif
		vm_log_error("[IME MOUDLE]IME resource is error.");
		return;
	}

	while ((rHandle = vm_res_findfirst(-1, VM_RES_TYPE_IME)) != VM_RES_NOT_FIND)
	{
		vm_res_findclose(VM_RES_TYPE_IME);

		
		if (vm_res_get_callback(VM_RES_TYPE_IME, rHandle, (void**)&app_callback) == 0
			&& app_callback != NULL
			&& (pHandle = vm_res_get_process_handle(VM_RES_TYPE_IME, rHandle)) >= 0)
		{
			vm_res_release_data(VM_RES_TYPE_IME, rHandle);
		
#ifdef VRE_SUPPORT_SCREEN_GROUP_FRAMEWOK
			mmi_frm_scrn_close_active_id();
#else
			GoBackHistory();
#endif
			if (vm_pmng_set_ctx(pHandle) == VM_PMNG_OP_OK)
			{
				app_callback(VM_INPUT_OK, input_text_ptr);
				//if (input_text_ptr != NULL && input_text_ptr != vre_input_text)
				if (input_text_ptr != NULL)
				{
					vm_free(input_text_ptr);
				}
				vm_pmng_reset_ctx();
			}
			input_text_ptr = NULL;
			break;
		}
		else
		{
			vm_res_release_data(VM_RES_TYPE_IME, rHandle);
#ifdef VRE_SUPPORT_SCREEN_GROUP_FRAMEWOK
			mmi_frm_scrn_close_active_id();
#else
			GoBackHistory();
#endif
			break;
		}
	}
}

void do_input_cancel(void) 
{
	VMINT rHandle = 0;
	VM_P_HANDLE pHandle = 0;
	void (*app_callback)(VMINT state, VMWSTR text) = NULL;
	
	if (vm_res_get_data_list_count_by_type(VM_RES_TYPE_IME) != 1)
	{
#ifdef VRE_SUPPORT_SCREEN_GROUP_FRAMEWOK
		mmi_frm_scrn_close_active_id();
#else
		GoBackHistory();
#endif
		vm_log_error("[IME MOUDLE]IME resource is error.");
		return;
	}

	while ((rHandle = vm_res_findfirst(-1, VM_RES_TYPE_IME)) != VM_RES_NOT_FIND)
	{
		vm_res_findclose(VM_RES_TYPE_IME);

		if (vm_res_get_callback(VM_RES_TYPE_IME, rHandle, (void**)&app_callback) == 0 
			&& app_callback != NULL
			&& (pHandle = vm_res_get_process_handle(VM_RES_TYPE_IME, rHandle)) >= 0)
		{
			vm_res_release_data(VM_RES_TYPE_IME, rHandle);

#ifdef VRE_SUPPORT_SCREEN_GROUP_FRAMEWOK
			mmi_frm_scrn_close_active_id();
#else
			GoBackHistory();
#endif
			if (vm_pmng_set_ctx(pHandle) == VM_PMNG_OP_OK)
			{
				app_callback(VM_INPUT_CANCEL, input_text_ptr);
				//if (input_text_ptr != NULL && input_text_ptr != vre_input_text)
				if (input_text_ptr != NULL)
				{
					vm_free(input_text_ptr);
				}
				vm_pmng_reset_ctx();
			}
			
			input_text_ptr = NULL;
			break;
		}
		else
		{
			vm_res_release_data(VM_RES_TYPE_IME, rHandle);
#ifdef VRE_SUPPORT_SCREEN_GROUP_FRAMEWOK
			mmi_frm_scrn_close_active_id();
#else
			GoBackHistory();
#endif
			break;
		}
	}
}


VMINT vm_switch_power_saving_mode(power_saving_mode_enum mode)
{
	if (vm_pmng_is_fg(VM_PMNG_CUR_HANDLE) 
		|| (vm_power_saving_controller.vm_process_handle == vm_pmng_get_current_handle() 
			&& mode == turn_on_mode))
	{
		VMINT ret = 0;
	
		switch (mode)
		{
		case turn_on_mode:
			if (!vm_power_saving_controller.vm_power_saving_switch)
			{
				TurnOnBacklight(GPIO_BACKLIGHT_SHORT_TIME);
				TurnOffBacklight();
				vm_power_saving_controller.vm_power_saving_switch = TRUE;
				vm_power_saving_controller.vm_process_handle = vm_pmng_get_current_handle();
			}
			ret = 0;
			break;
		case turn_off_mode:
			if (vm_power_saving_controller.vm_power_saving_switch)
			{
				TurnOnBacklight(GPIO_BACKLIGHT_PERMANENT);
				vm_power_saving_controller.vm_power_saving_switch = FALSE;
				vm_power_saving_controller.vm_process_handle = vm_pmng_get_current_handle();
			}
			ret = 0;
			break;
		default:
			ret = -1;
			break;
		}
		return ret;
	}

	return -2;
}


#include "worldclock.h"
#include "worldclockResdef.h"
#include "PhoneSetup.h"


#ifdef __MMI_WORLD_CLOCK__
extern wc_context_struct g_wc_cntx;
#endif
extern PHNSET_CNTX g_phnset_cntx;
extern U8 PhnsetGetHomeCity(void);
extern U8 PhnsetGetForeignCity(void);
extern U8 PhnsetGetDateSeperatorFormat(void);
extern U8 PhnsetGetDateFormat(void);
extern U8 PhnsetGetTimeFormat(void);
extern BOOL ATSetHomeCity(U8 CityIndex);
extern void PhnsetSetForeignCity(void);


void vm_get_phoneset_info(vm_phoneset_info_struct * phnset_info)
{
	U8  seperator = 0;
    S16 error = 0;
    U8  foreign_index = 0, wc_dst = 0, setting_dt_dst = 0;
    U16 timezone = 0, frn_timezone = 0;
	
	memset(phnset_info, 0x00, sizeof(vm_phoneset_info_struct));
	
	/* Get current home city index */
	phnset_info->current_city = PhnsetGetHomeCity();

#ifdef __MMI_DUAL_CLOCK__
	/* Get current foreign city index */
	phnset_info->foreign_city = PhnsetGetForeignCity();
#endif
	
	/* Get the seperator of current date */
	switch (PhnsetGetDateSeperatorFormat())
	{
		case 0:
			seperator = '.';
			break;
		case 1:
			seperator = ':';
			break;
		case 2:
			seperator = '/';
			break;
		case 3:
			seperator = '-';
			break;
		default:
			seperator = '.';
			break;
	}
	phnset_info->date_seperator = seperator;
	
	/* Get the current format of date */
	phnset_info->date_format = PhnsetGetDateFormat();
	
	/* Get the current format of time */
	phnset_info->time_format = PhnsetGetTimeFormat();
	
	/* Get the current city daylight saving time */
	phnset_info->current_dst = g_phnset_cntx.currentDST;
	
	/* read the nvram value */
#ifdef  __MMI_WORLDCLOCK_DST__
	ReadValue(NVRAM_WC_DST, &wc_dst, DS_BYTE, &error);
#endif
	ReadValue(NVRAM_SETTING_DT_DST, &setting_dt_dst, DS_BYTE, &error);
#ifdef  __MMI_WC_TZ_SUPPORT__
    ReadValue(FOREIGN_CITY, &foreign_index, DS_BYTE, &error);
	ReadValue(NVRAM_TIMEZONE, &timezone, DS_SHORT, &error);
#endif
#ifdef  __MMI_DUAL_CLOCK__
	ReadValue(NVRAM_FRN_TIMEZONE, &frn_timezone, DS_SHORT, &error);
#endif
	
	phnset_info->foreign_index = foreign_index;
	phnset_info->wc_dst = wc_dst;
	phnset_info->setting_dt_dst = setting_dt_dst;
	phnset_info->timezone = timezone;
	phnset_info->frn_timezone = frn_timezone;
}

void vm_set_phoneset_info(vm_phoneset_info_struct * phnset_info)
{
    S16 error = 0;
    U8  foreign_index = 0, wc_dst = 0, setting_dt_dst = 0;
    U16 timezone = 0, frn_timezone = 0;

#if 0    
	/* Set current home city index */
	ATSetHomeCity((VMUINT8)phnset_info->current_city);

	g_wc_cntx.CurrCityIndex = phnset_info->current_city;
#ifdef __MMI_WC_TZ_SUPPORT__
	g_wc_cntx.CurrTZ = phnset_info->current_timezone;
    g_wc_cntx.highlightIndex = phnset_info->highlightIndex;
#endif

#if 0   /* This function is to set the home city, the app should be launched from setting. But now not ready */
	PhnsetSetHomeCity();
#endif
	
	/* Set current foreign city index */
	g_wc_cntx.CurrCityIndex = phnset_info->current_city;
#ifdef __MMI_WC_TZ_SUPPORT__
	g_wc_cntx.CurrTZ = phnset_info->current_timezone;
    g_wc_cntx.highlightIndex = phnset_info->highlightIndex;
#endif

#if 0   /* This function is to set the home city, the app should be launched from setting. But now not ready */
#ifdef __MMI_DUAL_CLOCK__
	PhnsetSetForeignCity();
#endif
#endif

#ifdef  __MMI_WORLDCLOCK_DST__
    g_wc_cntx.DSTForeign = phnset_info->wc_dst;
#endif
#endif
    
    /* save the setting information to the nvram value */
    wc_dst = phnset_info->wc_dst;
	timezone = phnset_info->timezone;
	frn_timezone = phnset_info->frn_timezone;

#ifdef  __MMI_WORLDCLOCK_DST__
    WriteValue(NVRAM_WC_DST, &wc_dst, DS_BYTE, &error);
#endif
#if 0
#ifdef  __MMI_WC_TZ_SUPPORT__
	WriteValue(NVRAM_TIMEZONE, &timezone, DS_SHORT, &error);
#endif
#ifdef  __MMI_DUAL_CLOCK__
	WriteValue(NVRAM_FRN_TIMEZONE, &frn_timezone, DS_SHORT, &error);
#endif
#endif
}

/* Play Tone API, can play the error, key tone */
#include "SettingProfile.h"
#include "ProfileGprots.h"

void vm_play_request_tone(VMINT play_tone)
{
	playRequestedTone(ERROR_TONE);
}

#endif
