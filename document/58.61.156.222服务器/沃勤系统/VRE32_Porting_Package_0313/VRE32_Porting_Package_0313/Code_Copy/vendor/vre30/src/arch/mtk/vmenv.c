#ifdef __VRE__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mmi_include.h"
#include "DataAccountGProt.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "gpioInc.h"
#include "SimDetectionGexdcl.h"
#include "DevConfigGprot.h"

#include "med_main.h"
#include "med_api.h"
#include "Conversions.h"

#include "AMDef.h"
#include "AMGprot.h"

#include "vmsys.h"
#include "vmchset.h"
#include "vmio.h"
#include "vmstdlib.h"
#include "vmlog.h"
#include "vmdl.h"
#include "vmgraph.h"
#include "vmres.h"
#include "vmnvram.h"
#include "vmgettag.h"
#include "vredef.h"
#include "vmcert.h"
#include "vmmem.h"
#include "vmopt.h"
#include "vmcermng.h"
#include "vmmod.h"
#include "vmgfxold.h"
#include "vmvip.h"
#include "vmmd5.h"
#include "vmsock.h"

#include "vmenv.h"
#include "vmtimer.h"
#include "vmnvramadapter.h"

#include "CommonScreens.h"
#include "nvram_enums.h"
#include "nvram_common_defs.h"
#include "vmsim.h"

#include "vmenv.h"
#include "vmproevt.h"
#include "vmpromng.h"
#include "vmglobalver.h"
#include "vmmacrostub.h"
#include "vmmullang.h"
#ifdef AM_SUPPORT_GZIP
#include "vmgzip.h"
#include "vmgzipcore.h"
//#include "ScrMemMgrGprot_Int.h"
//#include "mmi_frm_mem_gprot.h"
#endif


/************************************************************
* 
* 全局函数声明。
*
************************************************************/
extern VMINT vm_start_vre_envirment(vm_vre_evt_cb_t vam_cb, VMINT state);
extern void vm_stop_vre_envirment(void);
/*
#if defined(__USB_IN_NORMAL_MODE__)
extern kal_bool mmi_usb_is_in_mass_storage_mode(void);
extern void mmi_usb_app_unavailable_popup(U16 stringId);
#endif
*/

extern VMUINT8 vm_init_default_game(void);
extern VMUINT8* vre_buildin_app_array[];


extern VMINT vre_running;

void * am_mem_ptr = NULL;

/************************************************************
* 
* VAM需要实现的函数，当前只是调试。
*
************************************************************/
/*
static void my_vam_callback(VAM_START_VRE_EVT evt)
{
	VMINT ret = 0;

	switch (evt)
	{
	case VRE_EVT_START_SUCCESS:
		if ((ret = vm_execute((VMWSTR)L"e:\\vre\\hello.vxp")) != VM_EXECUTE_APP_SUCCESS)
		{
			// 需要提示应用启动不了的错误。 
			vm_log_debug("vm_pmng_create_process ret = %d", ret);
			vm_exit();
		}
		break;
	case VRE_EVT_START_INTERNEL_ERROR:
		mmi_display_popup(
				(UI_string_type)GetString(STR_ID_VRE_FAIL_TO_START),
				MMI_EVENT_FAILURE);
		break;
	default:
		// do nothing.
		break;
	}
}
*/

void vm_open_vre_exec_file_callback(const VMWSTR path, VMINT is_short)
{
	return;
}

void appstore_main(void)
{
/*
	// 这里是VAM 的menu的入口。 
	VMINT ret = 0;

	if ((ret = vm_vam_load_core(my_vam_callback))  < 0)
	{
		if (ret == VM_VLC_MASS_STORAGE)
		{
#if defined(__USB_IN_NORMAL_MODE__)
			mmi_usb_app_unavailable_popup(0);
#else
			mmi_display_popup(
				(UI_string_type)GetString(STR_ID_VRE_USB_FAIL_TO_START),
				MMI_EVENT_FAILURE);
#endif
		}
		else
		{
			mmi_display_popup(
				(UI_string_type)GetString(STR_ID_VRE_FAIL_TO_START),
				MMI_EVENT_FAILURE);
		}
	}
	else
	{
		// 为了调试这里先启动应用。 
		if (ret == VM_VLC_START_SUCCESS)
		{
			if ((ret = vm_execute((VMWSTR)L"e:\\vre\\hello.vxp")) 
				!= VM_EXECUTE_APP_SUCCESS)
			{
				// 需要提示应用启动不了的错误。 
				vm_log_debug("vm_pmng_create_process ret = %d", ret);
				vm_exit();
			}		

			return;
		}
	}
*/
}


/*************************************************************************
 *
 * vmenv.c需要实现的函数。
 *
 *************************************************************************/
const static VMUINT8 bits[] = {0x80, 0x40, 0x20, 0x10, 8, 4, 2, 1};

static VMINT vam_state = VAM_OUT_OF_USE;

/**
 * 绘制ASCII码
 */
static void vm_vam_draw_asc(VMUINT8 *dst_buf, VMINT x, VMINT y, VMINT font_size,
							const VMUINT8 *font_data, VMUINT16 color);

/**
 * 绘制汉字
 */
static void vm_vam_draw_hz(VMUINT8 *dst_buf, VMINT x, VMINT y, VMINT font_size,
			              const VMUINT8 *font_data, VMUINT16 color);

static void vm_vam_draw_asc(VMUINT8 *dst_buf, VMINT x, VMINT y, VMINT font_size,
			  const VMUINT8 *font_data, VMUINT16 color)
{
	int i, j;
	
	for (i = 0; i < font_size; i++) {
		for (j = 0; j < font_size / 2; j++) {
			if (font_data[i * ((font_size / 2 + 7) / 8) + (j / 8)] &
				bits[j % 8])
			{
				if((x + j > 0) && (x + j < vm_graphic_get_screen_width()) 
					&& (y + i) > 0 && (y + i < vm_graphic_get_screen_height()))
				vm_dd_setpixel(dst_buf, x + j, y + i, color);	
			}
		}
	}
}

static void vm_vam_draw_hz(VMUINT8 *dst_buf, VMINT x, VMINT y, VMINT font_size,
			 const VMUINT8 *font_data, VMUINT16 color)
{
	int i, j;
	
	for (i = 0; i < font_size; i++) {
		for (j = 0; j < font_size; j++) {
			if (font_data[i * ((font_size + 7) / 8) + (j / 8)] &
				bits[j % 8])
			{
				if((x + j > 0) && (x + j < vm_graphic_get_screen_width()) 
					&& (y + i) > 0 && (y + i < vm_graphic_get_screen_height()))
				vm_dd_setpixel(dst_buf, x + j, y + i, color);
			}
		}
	}
}

VMINT vm_vam_load_core(vm_vre_evt_cb_t vam_cb)
{
	return vm_start_vre_envirment(vam_cb, 0);
}

void vm_vam_set_vam_state(VMINT state)
{
	vam_state = state;
}

VMINT vm_vam_is_in_use(void)
{
	if (vam_state == VAM_IN_USE)
		return TRUE;
	return FALSE;
}

void vm_vam_unload_core(void)
{
	if (vm_pmng_current_counter() <= 0)
		vm_exit();
}

extern MMI_BOOL mmi_am_app_update(U32 app_id, U16 *app_name);
/*MMI_BOOL mmi_am_app_update(U32 app_id, U16 *app_name)
{
	return MMI_TRUE;
}*/

VMINT vm_vam_app_update(VMWSTR appName, VMINT appId)
{
	if (mmi_am_app_update((U32)appId, (U16*)appName) == MMI_TRUE)
	{
		vm_log_debug("UPDATE UPDATE DUPDATE %d", appId);
		return TRUE;
	}

	return FALSE;
}

/**
 * 退出VRE的所有进程，释放VRE资源，删除VRE的SCREEN。
 */
void vm_exit(void) 
{
	if (!vre_running)
	{
		return;
	}
	
	vm_stop_vre_envirment();

#ifdef VRE_SUPPORT_SCREEN_GROUP_FRAMEWOK
	switch (mmi_frm_scrn_get_active_id())
	{
	case VRE_INPUT_SCREEN_ID:
  #if (!defined(__VRE_RB_08A__) && !defined(__VRE_RB_08B__))
		mmi_ime_delete_editor_common_scr(VRE_INPUT_SCREEN_ID);
	#endif
		DeleteScreenIfPresent(VRE_INPUT_SCREEN_ID);
	case VRE_SCREEN_ID:
		mmi_frm_group_close(GRP_ID_VRE);
		break;
	default:
		// donothing.
		break;
	}
#else
	kal_wap_trace(MOD_MMI, TRACE_GROUP_7, "[MOD_VRE]vm_exit ------- [start]");
	switch (GetActiveScreenId())
	{
	case VRE_SCREEN_ID:
		DeleteScreenIfPresent(VRE_SCREEN_ID);
		break;
	case VRE_INPUT_SCREEN_ID:
  #if (!defined(__VRE_RB_08A__)&& !defined(__VRE_RB_08B__))
		mmi_ime_delete_editor_common_scr(VRE_INPUT_SCREEN_ID);
	#endif
		DeleteScreenIfPresent(VRE_INPUT_SCREEN_ID);
		DeleteScreenIfPresent(VRE_SCREEN_ID);
		break;
	default:
		// do nothing.
		break;
	}
	kal_wap_trace(MOD_MMI, TRACE_GROUP_7, "[MOD_VRE]vm_exit ------- [End]");
#endif
	
}

void vm_exit_by_asm(void)
{
	extern vm_vre_evt_cb_t vam_callback;

	if (!vre_running)
	{
		return;
	}

	if (vam_state == VAM_IN_USE)
	{
		if (vam_callback != NULL)
		{
			vm_log_debug("ASM callback to AM callback.");
			vam_callback(VRE_EVT_QUIT);
		}
		vam_state = VAM_OUT_OF_USE;
	}

	vm_stop_vre_envirment();

#if (!defined(__VRE_RB_08A__) && !defined(__VRE_RB_08B__))
	mmi_ime_delete_editor_common_scr(VRE_INPUT_SCREEN_ID);
#endif
#ifdef VRE_SUPPORT_SCREEN_GROUP_FRAMEWOK
	mmi_frm_group_close(GRP_ID_VRE);
#else
	DeleteScreenIfPresent(VRE_INPUT_SCREEN_ID);
	DeleteScreenIfPresent(VRE_SCREEN_ID);
#endif
}

static VMINT vm_is_exceed_files_in_vre_directory(VMINT driver, VMUINT max_file_num)
{
	VMCHAR filename[10] = {0};
	VMWCHAR wFilename[10] = {0};

	if (driver > 0)
	{
		sprintf(filename, "%c:\\vre", (VMCHAR)driver);
		vm_default_to_ucs2(wFilename, sizeof(wFilename), filename);
		if (FS_Count((WCHAR*)wFilename, FS_FILE_TYPE, NULL, 0) > 5000)
		{
			return TRUE;
		}
	}

	return FALSE;
}

static vm_multi_lang_app_name_t* vm_create_multi_lang_app_name(VMWSTR filename)
{
	vm_multi_lang_app_name_t *appName = NULL, *tmp = NULL, *tmp2 = NULL;
	VMINT i = 0, bufferSize = 4;
	VMSTR tempBuf = NULL;

	for (i = 0; i < 3; i++)
   	{
     		if (vm_get_tag_by_lang_id(filename, VM_CE_INFO_NAME_LIST, NULL, &bufferSize, i + 1) <= 0)
        	{
			while (appName)
			{
				tmp = appName->next;
				_vm_kernel_free(appName->app_name);
				_vm_kernel_free(appName);
				appName = tmp;
			}
				
            		if ((vm_get_vm_tag(filename, VM_CE_INFO_NAME, NULL, &bufferSize) <= 0))
            		{
                			vm_log_error("Failed to get app name string.");
                			return NULL;
            		}
            		else
            		{   
				if ((tempBuf = _vm_kernel_malloc(bufferSize + 1)) == NULL)
				{
					return NULL;
				}
				
				if (vm_get_vm_tag(filename, VM_CE_INFO_NAME, tempBuf, &bufferSize) <= 0)
				{
					_vm_kernel_free(tempBuf);
					return NULL;
				}
				tempBuf[bufferSize] = 0;

				if ((appName = _vm_kernel_malloc(sizeof(vm_multi_lang_app_name_t))) == NULL)
				{
					_vm_kernel_free(tempBuf);
					return NULL;
				}
				
				if ((appName->app_name = _vm_kernel_malloc((bufferSize + 1) * sizeof(VMWCHAR))) == NULL)
				{
					_vm_kernel_free(tempBuf);
					_vm_kernel_free(appName);
				}

				appName->lang_id = VM_LANG_CHS;
				appName->next = NULL;
				mmi_chset_convert(
                        		MMI_CHSET_GB2312,
                        		MMI_CHSET_UCS2,
                        		(S8*) tempBuf,
                        		(S8*)appName->app_name,
                        		(bufferSize + 1) * sizeof(VMWCHAR));
                			
                		_vm_kernel_free(tempBuf);
            		}
        	}
        	else
        	{
			if ((tempBuf = _vm_kernel_malloc(bufferSize + 1)) == NULL)
			{
				while (appName)
				{
					tmp = appName->next;
					_vm_kernel_free(appName->app_name);
					_vm_kernel_free(appName);
					appName = tmp;
				}
			
				return NULL;
			}

			/* Get app name by language id. */
			if (vm_get_tag_by_lang_id(filename, VM_CE_INFO_NAME_LIST, tempBuf, &bufferSize, i + 1) <= 0)
			{
				_vm_kernel_free(tempBuf);
				continue;
			}
			tempBuf[bufferSize] = 0;

			/* Alloc memory for mulit appname struct. */
			if ((tmp = _vm_kernel_malloc(sizeof(vm_multi_lang_app_name_t))) == NULL)
			{
				_vm_kernel_free(tempBuf);
				while (appName)
				{
					tmp = appName->next;
					_vm_kernel_free(appName->app_name);
					_vm_kernel_free(appName);
					appName = tmp;
				}
				return NULL;
			}

			/* Alloc memory for appname. */
			if ((tmp->app_name = _vm_kernel_malloc((bufferSize + 1) * sizeof(VMWCHAR))) == NULL)
			{
				_vm_kernel_free(tempBuf);
				_vm_kernel_free(tmp);
				while (appName)
				{
					tmp = appName->next;
					_vm_kernel_free(appName->app_name);
					_vm_kernel_free(appName);
					appName = tmp;
				}
				return NULL;
			}

			tmp->next = NULL;
			switch (i)
			{
			case 0:
				tmp->lang_id = VM_LANG_ENG;
				mmi_chset_convert(MMI_CHSET_ASCII, MMI_CHSET_UCS2,
                            		(S8*) tempBuf,
                            		(S8*) tmp->app_name, (bufferSize + 1) * sizeof(VMWCHAR));
				break;
			case 1:
				tmp->lang_id = VM_LANG_CHS;
				mmi_chset_convert(MMI_CHSET_GB2312, MMI_CHSET_UCS2,
                            		(S8*) tempBuf,
                            		(S8*) tmp->app_name, (bufferSize + 1) * sizeof(VMWCHAR));
				break;
			default:
				tmp->lang_id = VM_LANG_CHT;
				mmi_chset_convert(MMI_CHSET_BIG5, MMI_CHSET_UCS2,
                            		(S8*) tempBuf,
                            		(S8*) tmp->app_name, (bufferSize + 1) * sizeof(VMWCHAR));
				break;
			}

			/* Add multi language to list. */
			if (appName)
			{
				for (tmp2 = appName; tmp2->next != NULL; tmp2 = tmp2->next);
				
				tmp2->next = tmp;
			}
			else
			{
				appName = tmp;
			}
			
            		_vm_kernel_free(tempBuf);
		}
	}

	return appName;
}

static void vm_destory_multi_lang_app_name(vm_multi_lang_app_name_t* appName)
{
	vm_multi_lang_app_name_t* tmp = NULL;

	while (appName)
	{
		tmp = appName->next;
		_vm_kernel_free(appName->app_name);
		_vm_kernel_free(appName);
		appName = tmp;
	}
}

VMINT vm_execute(VMWSTR filename, void (*mem_retry_callback)(void))
{
	VMINT ret = VM_EXECUTE_APP_SUCCESS;
	vm_multi_lang_app_name_t *appName = NULL;
	
	if (!vre_running)
	{
		return VM_EXECUTE_INTERNAL_ERROR;
	}

	if (vm_is_exceed_files_in_vre_directory(vm_get_removeable_driver(), 5000)
		|| vm_is_exceed_files_in_vre_directory(vm_get_system_driver(), 5000))
	{
		/* Check file and folder num in vre folder. */
		return VM_EXECUTE_EXCEED_FILE_IN_VRE_DIRECTORY;
	}

	if (vm_vam_app_is_running(filename))
	{
		/* Application is aleary startup. Don't to get appname */
		appName = NULL;
	}
	else
	{
		if ((appName = vm_create_multi_lang_app_name(filename)) == NULL)
		{
			return VM_EXECUTE_APP_ILLEGAL;
		}
	}

	if ((ret = vm_pmng_create_process(filename, appName, mem_retry_callback)) >= 0)
	{
		return VM_EXECUTE_APP_SUCCESS;
	}
	else
	{
		vm_log_error("Failed create process, ret = %d", ret);

		if (ret != VM_PMNG_EXIT)
			vm_destory_multi_lang_app_name(appName);
		
		switch (ret)
		{
		case VM_PMNG_ERROR_PARAM:
		case VM_PMNG_ERROR_IO:
			return VM_EXECUTE_APP_ILLEGAL;
		case VM_PMNG_NO_SCHEDULE:
			return VM_EXECUTE_INTERNAL_ERROR;
		case VM_PMNG_NO_MEM:
			return VM_EXECUTE_APP_NOT_ENOUGH_MEMORY;
		case VM_PMNG_SEC_TAG_PLATFORM_PARAM_DISMATCH:
			return VM_EXECUTE_PLATFORM_PARAM_DISMATCH;
		case VM_PMNG_SEC_APP_TIMESTAMP_ERROR:
			return VM_EXECUTE_TIMESTAMP_ERROR;
		case VM_PMNG_SEC_IMSI_DISMATCH:
			return VM_EXECUTE_IMSI_DISMATCH;
		case VM_PMNG_SEC_BAN_LIST_APP:
			return VM_EXECUTE_BANNED_APP;
		case VM_PMNG_SEC_INVALIDATE_APP:
			return VM_EXECUTE_APP_ILLEGAL;
		case VM_PMNG_SEC_CERT_OVREDUE:
			return VM_EXECUTE_CERT_OVERDUE;
		case VM_PMNG_SEC_CERT_SMALL_SYS_MEM:
			return VM_EXECUTE_SYS_NOT_ENOUGH_MEMORY;
		case VM_PMNG_EXCEED_MAX_PROCESS_NUM:
			return VM_EXECUTE_EXCEED_MAX_APP_NUM;
		default:
			return VM_EXECUTE_INTERNAL_ERROR;
		}
	}
}

/*
VMINT vm_execute_app(VMWSTR filename, vm_running_app_info_t** bg_app_infos, VMUINT* app_info_num)
{
	VMINT ret = VM_EXECUTE_APP_SUCCESS;

	if ((ret =  vm_execute(filename)) == VM_EXECUTE_APP_NOT_ENOUGH_MEMORY)
	{
		VMUINT process_num = 0, i = 0;
		vm_running_app_info_t* app_infos =NULL;
		VMINT int_buffer_size = 4;
		VM_P_HANDLE* pHandle = NULL;
		extern mmi_devconfig_system_config_struct sysconf;

		if (vm_get_vm_tag(filename, VM_CE_INFO_MEM_REQ, &i, &int_buffer_size) == GET_TAG_TRUE
			&& (sysconf.memory_size << 10) >= i)
		{
			if (vm_pmng_get_process_lst(VM_PMNG_BACKGROUND, &pHandle, &process_num) == VM_PMNG_OP_OK)
			{
				if (process_num > 0)
				{
					// 存在BG的进程。 
					if ((app_infos = _vm_kernel_calloc(sizeof(vm_running_app_info_t) * process_num)) != NULL)
					{
						for (i = 0; i < process_num; i++)
						{
							// 得到进程归属的应用程序文件名称 	
							vm_pmng_file_name(*(pHandle + i), 
								(app_infos + i)->app_filename, MAX_APP_NAME_LEN);
							// 得到进程的内存需求。 					
							vm_get_vm_tag((app_infos + i)->app_filename, VM_CE_INFO_MEM_REQ, 
								&((app_infos + i)->alloc_mem), &int_buffer_size);
							// 得到应用程序编号。 						
							(app_infos + i)->app_id = vm_pmng_app_id(*(pHandle + i));
						}

						if (bg_app_infos)
							*bg_app_infos = app_infos;
						if (app_info_num)
							*app_info_num = process_num;
					}
					else
					{
						ret = VM_EXECUTE_SYS_NOT_ENOUGH_MEMORY;
					}
			
					_vm_kernel_free(pHandle);
				}
				else
				{
					// 没有进程在后台运行。 
					ret = VM_EXECUTE_INTERNAL_ERROR;
				}
			}
			else
			{
				ret = VM_EXECUTE_SYS_NOT_ENOUGH_MEMORY;
			}
		}
		else
		{
			ret = VM_EXECUTE_SYS_NOT_ENOUGH_MEMORY;
		}
	
		
	}

	return ret;
}
*/

/* add by zaiping.chen, 2010.07.12,  for run with param, begin */
#define	RUN_PARAM_LEN	MAX_APP_NAME_LEN
static VMWSTR run_param;

static void	save_run_param(VMWSTR param)
{
	run_param = _vm_kernel_malloc(MAX_APP_NAME_LEN * sizeof(VMINT16));
	if (NULL == run_param)
	{
		vm_log_error("save_run_param - vm_malloc fail.");
		return;
	}
	vm_log_debug("save_run_param - run_param: %p", run_param);
	vm_wstrcpy(run_param, param);
}

VMINT	get_run_param_addr(void)
{
	vm_log_debug("get_run_param_addr - run_param: %p", run_param);
	if (NULL != run_param)
	{
		return (VMINT)run_param;
	}
	return 0;
}

static void	delete_run_param(void)
{
	vm_log_debug("delete_run_param - run_param: %p", run_param);
	if (NULL != run_param)
	{
		_vm_kernel_free(run_param);
		run_param = NULL;
	}
}

VMINT vm_execute_ex(VMWSTR filename, VMWSTR param)
{
	VMINT ret;
	
	save_run_param(param);
	ret = vm_execute(filename, NULL);
	delete_run_param();
	return ret;
}

VMINT vm_execute_app_ex(VMWSTR filename, VMWSTR param, void (*mem_retry_callback)(void))
{
	VMINT ret;
	
	save_run_param(param);
	ret = vm_execute(filename, mem_retry_callback);
	delete_run_param();
	return ret;
}
/* add by zaiping.chen, 2010.07.12,  for run with param, end */

VMINT vm_get_bg_app_infos(vm_running_app_info_t** bg_app_infos)
{
	VM_P_HANDLE* pHandle = NULL;
	VMUINT pNum = 0, i = 0;
	vm_running_app_info_t* app_infos =NULL;
	VMINT int_buffer_size = 4;

	if (vm_pmng_get_process_lst(VM_PMNG_BACKGROUND, &pHandle, &pNum) == VM_PMNG_OP_OK)
	{
		if (pNum > 0)
		{
			/* 存在BG的进程。 */
			if ((app_infos = _vm_kernel_calloc(sizeof(vm_running_app_info_t) * pNum)) != NULL)
			{
				for (i = 0; i < pNum; i++)
				{
					/* 得到进程归属的应用程序文件名称 	*/
					vm_pmng_file_name(*(pHandle + i), 
						(app_infos + i)->app_filename, MAX_APP_NAME_LEN);
					/* 得到进程的需求。 						*/
					vm_get_vm_tag((app_infos + i)->app_filename, VM_CE_INFO_MEM_REQ, 
						&((app_infos + i)->alloc_mem), &int_buffer_size);
					/* 得到应用程序编号。 						*/
					(app_infos + i)->app_id = vm_pmng_app_id(*(pHandle + i));
				}

				if (bg_app_infos)
					*bg_app_infos = app_infos;
			}
			else
			{
				pNum = 0;
			}

			_vm_kernel_free(pHandle);
		}
	}

	return pNum;
}

void* vm_vam_malloc(VMINT size)
{
#if (!defined(MMI_AM_USING_VRE_MEM) || !defined(__VRE30_AM__))
	return NULL;
#else
	if (size == MMI_AM_MAX_DYN_MEM_SIZE)
	{
		return am_mem_ptr;
	}
	else
	{
		return NULL;
	}
#endif
}

void vm_vam_free(void* p)
{
	// do nothing.
}

void* vm_vam_realloc(void* p, VMINT size)
{
#if (!defined(MMI_AM_USING_VRE_MEM) || !defined(__VRE30_AM__))
	return NULL;
#else
	if (size == MMI_AM_MAX_DYN_MEM_SIZE)
	{
		return am_mem_ptr;
	}
	else
	{
		return NULL;
	}
#endif
	//return _vm_kernel_realloc(p, size);
}

VMINT vm_vam_set_sim_card(VMINT choose_index)
{
	vm_nvram_appstore_config_t* appstore_config = NULL;
	extern VMINT vm_selected_simcard;

	if (choose_index != 1 && choose_index != 2)
		return -1;

	vm_selected_simcard = choose_index;
	if ((appstore_config = _vm_kernel_malloc(sizeof(vm_nvram_appstore_config_t))) != NULL)
	{
		if (vm_get_appstore_config(appstore_config))
		{
			appstore_config->sim_index = choose_index;
			if (vm_set_appstore_config(appstore_config))
			{
				_vm_kernel_free(appstore_config);
				return 0;
			}
		}

		_vm_kernel_free(appstore_config);
	}

	return -1;
}

VMINT vm_vam_set_net_type(VMINT net_type)
{
	vm_nvram_appstore_config_t* appstore_config = NULL;

	if (net_type != 1 && net_type != 2)
	{
		return -1;
	}

	if ((appstore_config = _vm_kernel_malloc(sizeof(vm_nvram_appstore_config_t))) != NULL)
	{
		if (vm_get_appstore_config(appstore_config))
		{
			appstore_config->update_hint = net_type - 1;
			if (vm_set_appstore_config(appstore_config))
			{
				_vm_kernel_free(appstore_config);
				return 0;
			}
		}

		_vm_kernel_free(appstore_config);
	}

	return -1;
	
}

VMINT vm_vam_get_sim_card(VMINT* sim_index)
{
	vm_nvram_appstore_config_t* appstore_config = NULL;

	if (sim_index == NULL)
		return TRUE;

	if ((appstore_config = _vm_kernel_malloc(sizeof(vm_nvram_appstore_config_t))) != NULL)
	{
		if (vm_get_appstore_config(appstore_config))
		{
			*sim_index = appstore_config->sim_index;
			_vm_kernel_free(appstore_config);
			return TRUE;
		}

		_vm_kernel_free(appstore_config);
	}

	return FALSE;
}

VMINT vm_vam_get_net_type(VMINT* net_type)
{
	vm_nvram_appstore_config_t* appstore_config = NULL;

	if (net_type == NULL)
		return TRUE;

	if ((appstore_config = _vm_kernel_malloc(sizeof(vm_nvram_appstore_config_t))) != NULL)
	{
		if (vm_get_appstore_config(appstore_config))
		{
			*net_type = (appstore_config->update_hint + 1);
			_vm_kernel_free(appstore_config);
			return TRUE;
		}

		_vm_kernel_free(appstore_config);
	}

	return FALSE;
	
}


/**
 * 在插入USB时会调用
 */
void mmi_vre_enter_usb_mode(void)
{
	if (stub_mmi_usb_is_in_mass_storage_mode())
	{
		vm_exit();
	}
}

/**
 * 在拔出USB时会调用
 */
void mmi_vre_exit_usb_mode(void)
{
	return;
}

/**
 * T卡拔出的时候被调用。
 */
void mmi_vre_card_plug_out_hdlr(void)
{
	if (vm_pmng_deal_card_plug_out_event(NULL) == 0 
		&& vam_state != VAM_IN_USE)
	{
		vm_exit();
	}
}

VMINT vm_vam_load_resource_from_file(VMSHORT * filename, VMCHAR* res_name, VMINT* res_size, VMCHAR* cache_buf, VMINT cache_size )
{
	VMUINT8* res_buf = NULL;
	
	if( filename == NULL || res_name == NULL || res_size == NULL || cache_buf == NULL )
		return LOAD_VAM_RES_PARAM_ERROR;
	
	res_buf = vm_load_resource_from_file(filename, res_name, res_size);
	if( res_buf == NULL )
		return LOAD_VAM_RES_FAIL;
		
	if( cache_size < *res_size )
	{
		vm_free( res_buf );
		
		return LOAD_VAM_RES_INSUFFICIENT_BUF;
	}
		
	memcpy( cache_buf, res_buf, *res_size );
	
	vm_free( res_buf );
	
	return 0;
}

VMINT vm_vam_get_gif_data(VMUINT8 *gifzm, VMUINT8 ** data_buf, VMINT *data_len)
{
	VMINT icon_dat_sz;
	VMINT offset = 13;
	
	if (gifzm == NULL)
		return -1;
	
	icon_dat_sz = *(gifzm + offset + 6) +
		((*(gifzm + offset + 7)) << 8) +
		((*(gifzm + offset + 8)) << 16) +
		((*(gifzm + offset + 9)) << 24);
	
	if (icon_dat_sz <= 0)
		return -1;
	*data_len = icon_dat_sz;
	*data_buf = (VMUINT8 *)gifzm + offset + 10;
	
	return 0;
}

VMINT vm_vam_get_string_data(VMUINT8* gifzm, VMUINT8** data_buf, LANGUAGE_TYPE lan, VMINT* data_len, VMINT* font, VMINT * data_size)
{
	VMINT icon_dat_sz, zm_dat_sz;
	VMINT offset = 13;
	VMINT language = ENG;
	
	if (gifzm == NULL)
		return -1;
	
	icon_dat_sz = *(gifzm + offset + 6) +
		((*(gifzm + offset + 7)) << 8) +
		((*(gifzm + offset + 8)) << 16) +
		((*(gifzm + offset + 9)) << 24);
	
	offset = 23 + icon_dat_sz;	//start addr of matrix
	
	//jump to the addr of specified language matrix
	while (language < lan)
	{
		zm_dat_sz = *(gifzm + offset + 8) +
			((*(gifzm + offset + 9)) << 8) +
			((*(gifzm + offset + 10)) << 16) +
			((*(gifzm + offset + 11)) << 24);
		offset += (12 + zm_dat_sz);
		language++;
	}
	
	//get info
	*data_len = *(gifzm + offset + 5)
		+ ((*(gifzm + offset + 6)) << 8);
	*font = *(gifzm + offset+ 7);
	
	zm_dat_sz = *(gifzm + offset + 8) +
		((*(gifzm + offset + 9)) << 8) +
		((*(gifzm + offset + 10)) << 16) +
		((*(gifzm + offset + 11)) << 24);
	
	if (zm_dat_sz <= 0)
		return -1;

	*data_size = zm_dat_sz;
	
	*data_buf = (VMUINT8 *)(gifzm + offset + 12);
	return 0;
}

VMINT vm_vam_measure_zimo_string(VMUINT8 *zimo_buf, VMINT str_len)
{
	VMINT i;
	VMINT offset = 0 ;
	VMINT flag;
	VMINT offset_ch;
	VMINT nTempWidth = 0;
	
	for (i = 0; i < str_len; i++) 
	{
		flag = *(zimo_buf+offset);
		offset_ch = *( zimo_buf+offset+1);
		
		if (flag == 2)
		{
			//nTempWidth +=  7 + 1;//7 代表ASC的实际宽度  + 1代表每个字之间的空格
			nTempWidth +=  7;	//14号字体不需加空格	-linminqi 2010-2-8
		}
		else 
		{
			//nTempWidth += 14 + 1;//14 代表HZ的实际宽度  + 1代表每个字之间的空格
			nTempWidth += 14;	//14号字体不需加空格	-linminqi 2010-2-8
		}
		offset += offset_ch + 2;
	}
	return nTempWidth - 1; //nTempWidth整个字符创都进行加1之后的宽度，但最后一个字符宽度不需要再加1，所以此处-1处理

}

void vm_vam_draw_text(VMUINT8 *dst_buf, VMINT x, VMINT y, VMINT start_idx, VMINT out_str_len, VMUINT8 *src_buf, VMINT str_len, VMINT font, VMUINT16 color) 
{
	VMINT count, flag, offset, offset_out, offset_ch;
	VMINT i;
	
	if (!dst_buf || !src_buf || (str_len <= 0) || (start_idx >= str_len) || ((font != 12) && (font != 14) && (font != 16)) )
		return ;
	
	count = (start_idx + out_str_len < str_len) ? out_str_len : (str_len - start_idx);
	offset	= 0;
	
	for (i = 0; i < start_idx; i++)
	{
		offset += *(src_buf+offset+1) + 2;
	}
	
	for (i = 0, offset_out = 0; i < count; i++) 
	{
		flag	= *(src_buf+offset);
		offset_ch = *(src_buf+offset+1);
		
		if (flag == 2)
		{
			vm_vam_draw_asc(dst_buf, x + offset_out, y, font, (src_buf+offset+2), color);
			offset_out += font / 2;
		}
		else 
		{
			vm_vam_draw_hz(dst_buf, x + offset_out, y, font, (src_buf+offset+2), color);
			offset_out += font;
		}
		offset_out += 1;//
		offset += offset_ch + 2;
	}
}

/**************************** VIP 下载代码************************************/
#define  MAX_LEN_FILE_NAME           			(260)
#define  MAX_LEN_APP_VERSIONID       			(22)
#define  MAX_LEN_APP_NAME            			(24)
#define  VAM_LEN_MD5                 				(32)  
#define  MAX_LEN_TIME                				(10)
#define  SAFE_FREE(p)						if(p){ vm_free(p); (p) = NULL; }
#define  VAM_DOWNLOAD_DEFAULT_SIZE           (25 * 1024)
#define  VAM_INT_SIZE                                   	sizeof(VMUINT32)
#define  VAM_BYTE_SIZE                                  	sizeof(VMBYTE)

#define  VAM_ADD_APP                             0   //VAM添加的应用
#define  VAM_ADD_VAS                             4   //VAM添加的VAS
#define  APPSTORE_ID                     "appstore"
#define  SM_CHARGE_ID                  "sm_billing"

#define  VAM_MAX_APP_NUM                         10 //VAM支持的应用个数
/**
 * 下载完一块再下另一块的时间间隔,单位:毫秒
 */
#define VAM_DOWNLOAD_INTERVAL			(10)      

/**
 * 下载文件的块大小
 */
#define  VAM_DOWNLOAD_DEFAULT_SIZE		(25 * 1024)

/**
 * 临时文件后缀
 */
#define  VAM_TASK_TEMP_SUFFIX                     	"tmp"     /*临时文件后缀*/
#define  VAM_APPSTORE_SUFFIX                        "pht"

//added by rencai.xiao 2010/07/22
#ifdef AM_SUPPORT_GZIP
#define VAM_GZIP_SUFFIX                                  ".gz"
#endif
/**
 * 任务列表文件名
 */
#define  VAM_TASK_FILENAME					"phdmlist.dat"

/**
 * 任务列表缓存长度
 */
#define  VAM_TASK_BUF_SIZE					(20 * 1024)

//copy 块大小
#define DM_COPY_SIZE                          (5 * 1024)

#define LOG_AM_DOWNLOAD
//是否支持uft转码
#define AM_SUPPORT_UTF_CHSET
/**
 * 最大重试次数
 */
 #define VAM_DOWNLOAD_RETRY_MAX_COUNT                           3

/*
*	应用下载状态类型定义
*/
typedef enum 
{
	APPDLSTATE_UNKNOWN = 0,			//未知状态
	APPDLSTATE_DOWNLOADING,			//正在下载	
	APPDLSTATE_FAIL,					//下载失败
	APPDLSTATE_OK,						//已下载
	APPDLSTATE_NOT,					//未下载
	APPDLSTATE_PAUSE,					//暂停下载
	APPDLSTATE_WAIT					//等待下载
}E_AppDlState_t;

/**
 * 任务结构
 */
typedef struct Vam_Task_t 
{
	E_AppDlState_t eState;                                    		/*任务状态*/
	VMINT          nPercent;                                  			/*任务进度*/
	VMINT          nFilehandle;                              	 		/*临时文件句柄*/
	VMINT          nDriver;                                   			/*临时文件存放位置*/
	VMINT          nRetryCount;                               		/*重试次数*/
	VMINT          nFilesize;                                 			/*文件大小*/
	VMINT          nASFlag;                                   			/*标记是从AS(1)添加还是VAM(0)添加,若为AppStore值为2*/
	VMUINT32       nAppid;                                   	 		/*应用ID*/
	struct Vam_Task_t     *next;                              		/*下一个节点*/
	VMWCHAR        szFilename[MAX_LEN_FILE_NAME + 1];          	/*文件名*/
	VMWCHAR        szVersionID[MAX_LEN_APP_VERSIONID + 1];      	/*版本号ID*/
	VMWCHAR        szName[MAX_LEN_APP_NAME + 1];              		/*任务名称*/
	VMWCHAR        szVXPDigest[VAM_LEN_MD5 + 1];              		/*对vxp文件做的摘要*/
	VMWCHAR        szTime[MAX_LEN_TIME + 1];                       /*时间*/
} Vam_Task_t;

/**
 * 下载过程中保存数据的结构
 */
typedef struct Vam_Download_t
{
	void(*download_app_cb)(VMINT nResult, VMINT nPercent);  /*下载应用回调*/
    	Vam_Task_t * pDownloadingTask;                            		/*正在下载的任务*/
    	VMINT nTimerID;                                          				/*定时器ID*/
	VMINT nBlockSize;                                        				/*下载块的大小*/
	VMCHAR * pHistoryList;                               				/*下载历史列表*/
	VMINT nHistoryLen;                                   				/*下载历史列表长度*/
	VMINT nPhoneID;                                      				/*Phone ID*/
	VMINT nUserID;                                      				 	/*User ID*/
	
	//rencai.xiao 2010/03/01
	VMUINT nChargeSeqID;                                             /*计费信息应用程序编号*/
	VMUINT nSmsSeqID;                                           /*短信信息应用程序编号*/

	VMUCHAR bFirstBlock;                                      /*是否是第一块*/
	VMUCHAR bAppStore;                                        /*是否是VAS*/
	VMUCHAR nIsSave;                                               /*是否已经保存过列表*/
	VMINT nConnectTimer;                                  /*联网成功后启动timer 通知调用者*/
	
	//rencai.xiao 2010/03/01
	VMUCHAR bSmsDetail;                                   /*是否同步短信信息*/
	VMUCHAR bChargeDetail;                                /*是否同步计费信息*/
	VMUCHAR bPay;                                         /*是否获取余额*/
	VMUCHAR bChannel;

	//rencai.xiao 2010/03/18
	VMUCHAR bDlApp;                                    /*是否调用了vm_vam_download_app接口*/

	//rencai.xiao 2010/03/15
	VMINT nChargeDetailCount;                     /*NVRAM中计费信息个数*/
	VMINT nSmsDetailCount;                         /*NVRAM中短信信息个数*/

	VMINT8 nRetryCount;                                        /*重试次数*/
	VMINT nStartPos;										 /*记录下载块的起始位置*/
	void * (*vam_malloc)(VMINT size);                        /*申请内存函数指针*/
	void (*vam_free)(void* ptr);                             /*释放内存函数指针*/

	void * (*vam_malloc_ex)(VMINT size);                        /*申请内存函数指针*/
	void (*vam_free_ex)(void* ptr);                             /*释放内存函数指针*/

	void(*sync_cb)(VMINT nResult); /*更新计费通道*/

	//added by rencai.xiao 2010/06/04
	VMCHAR szFilePath[40];
	VMWCHAR szwFilePath[40];

	//added by rencai.xiao 2010/07/22
	check_filesize_cb check_size_cb;                           /*检测size的回调*/
       check_dll_version_cb check_dll_cb;                        /*检测dll version的回调*/
}Vam_Download_t;

static Vam_Download_t g_VamTask = {0};
static Vam_Task_t * pTaskRoot;
struct vm_fileinfo_t fileinfo;

//rencai.xiao 2010/03/03
#define AM_UPDATE_BILLING_INTERVAL                       3

//rencai.xiao 2010/03/15
#define AM_NVRAM_READ_MAX_VALUE                        16

//rencai.xiao 2010/03/01
//static VMCHAR res_path[600];
#define VAM_RES_PATH_SIZE               (1024 * 4)

//rencai.xiao 2010/04/28 download payment notification and rate.
#ifdef AM_DOWNLOAD_PAYMENT_NOTIFICATION
#define AM_TEMP_BUFFER_SIZE         (1024)
#endif

//rencai.xiao 2010/03/01
#define UPDATE_CONFIG_PATH "/update/config.txt?timezonzeid=China&permission=%s&cert=%s&appblalst=%s&channel=%s&appstore=%s"

//rencai.xiao 2010/03/01
/*
*	系统配置数据类型
*/
typedef enum 
{
	VRE_SYSTEM_TIME = 1,  /*系统时间*/
	VRE_PUBLIC_KEY,       /*public key*/
	VRE_PERMISSION_BLACK_LIST, /*系统权限*/
	VRE_APPLICATION_BLACK_LIST,/*黑名单*/
	VRE_PAYMENT_CHANNEL,/*计费通道*/
	VRE_APPSTORE_VERSION,/*AS是否更新标志*/
	VRE_SHOW_FEE_HINT, /*计费信息提示标志*/
	VRE_TWICE_CONFIRM_INFO /*二次确认计费信息*/
}E_SysCfgCnt_t;

//rencai.xiao 2010/03/15
//static vm_nvram_charge_detail_list_t charge_detail_list = {0};//NVRAM中计费信息
//static vm_nvram_charge_sms_detail_list_t sms_detail_list = {0};//NVRAM中短信信息
vm_nvram_charge_sms_detail_list_t * sms_detail_list = NULL;

#ifdef AM_SUPPORT_EXTEND_PAY_CONFIG
vm_nvram_charge_detail_list_ext_t * charge_detail_list = NULL;//NVRAM中计费信息
#else

vm_nvram_charge_detail_list_t * charge_detail_list = NULL;
#endif
/**
 * 下载完成的处理
 *
 * @param pTask             下载的任务
 *
 * 
 */
static void vm_vam_download_finish(Vam_Task_t * pTask);

/**
 * 释放列表
 */
static void vm_vam_release_task_list(void);

/**
 * 读取任务列表
 *
 * @return            读取成功返回VAM_DL_OK，否则返回VAM_DL_ERR
 */
static VMINT vm_vam_read_task_list(void);

/**
 * 校验下载管理任务列表是否合法
 *
 * @return 校验通过返回VAM_DL_OK，否则返回VAM_DL_ERR
 */
static VMINT vm_vam_check_task_file(void);

/**
 * 解析读取到的任务列表
 *
 * @param pTaskBuf       缓存数据
 * 
 * @return 解析成功返回VAM_DL_OK,否则返回VAM_DL_ERR
 */
static VMINT vm_vam_parse_task_list(VMCHAR * pTaskBuf);

/**
 * 将任务添加到尾部
 *
 * @param pTask   要添加的任务
 *
 * @return   添加成功返回VAM_DL_OK，否则返回VAM_DL_ERR
 */
static VMINT vm_vam_add_task_to_end(Vam_Task_t * pTask);

/**
 * 发起下载请求
 *
 * @param pTask        要下载的任务
 *
 * @return             成功发起请求返回VAM_DL_OK，否则返回VAN_DL_ERR
 */
static VMINT vm_vam_request_data(Vam_Task_t * pTask);

/**
 * 打开一任务的临时文件
 * 
 * @param PTask            任务
 *
 * @return                 打开成功返回VAM_DL_OK,否则返回VAM_DL_ERR
 */
static VMINT vm_vam_open_temp_file(Vam_Task_t * pTask);

static VMINT vm_vam_delete_temp_file(Vam_Task_t * pTask);


/**
 * 获取临时文件名,包含路径
 * 
 * @param szDesName            得到的结果
 * @param szSrcName            源文件名
 * @param nDriver              盘符
 * @param nASFlag            是否是AS
 *
 * @return                     获取成功返回VAM_DL_OK，否则返回VAM_DL_ERR
 */
static VMINT vm_vam_get_temp_filename(VMWCHAR * szDesName, VMWCHAR * szSrcName, VMINT8 nDriver, VMINT8 nASFlag);

/**
 * 获取一任务的保存路径
 *
 * @param pTask             任务
 * @param pFilename         得到的保存路径
 *
 * @return 获取成功返回VAM_DL_OK，否则返回VAM_DL_ERR
 */
static VMINT vm_vam_get_task_save_path(Vam_Task_t * pTask, VMWCHAR * pFilename);

/**
 * 交换整型数据字节顺序，支持16位和32位整型
 *
 * @param 				pSrcData 源数据
 * @param 				pDestData32 转换后的32位整型数据
 * @param 				pDestData16 转换后的16位整型数据
 */
static void vm_vam_int_byte_switch(VMCHAR * pSrcData, VMUINT32 * pDestData32, VMUINT16 * pDestData16);

/**
 * 交换字符串字节顺序
 *
 * @param 				pwDesData 交换后的字串
 * @param 				pwSrcData 源数据
 */
static void vm_vam_string_byte_switch(VMWCHAR * pwDesData, VMWCHAR * pwSrcData);

/**
 * 下载失败的处理
 *
 * @param 				pTask 下载的任务
 * @param				nErrorCode 错误码
 * @return                   		处理成功返回VAM_DL_OK，否则返回VAM_DL_ERR
 */
static void vm_vam_download_app_fail(Vam_Task_t * pTask, VMINT nErrorCode);

/**
 * 下载应用回调
 * @param 				nUserID 用户ID
 * @param 				nPhoneID 手机ID
 * @param 				nResult 下载结果
 * @param				pData 下载数据
 * @param				nDataSize 下载数据大小
 */
static void vm_vam_download_app_callback(VMINT uid, VMINT mpi, VMINT vip_response_type, 
	const void* vip_response, VMUINT response_size);

/**
 * 获取下载进度
 */
static VMINT vm_vam_get_download_percent(Vam_Task_t * pTask);

/**
 * 检测临时文件是否合法
 *
 * @param 				pTask 下载的任务
 * @param 				pNetDigest 下载得到的MD5摘要
 *
 * @return                		检测通过返回VAM_DL_OK,否则返回VAM_DL_ERR
 */
static VMINT vm_vam_check_temp_file(Vam_Task_t * pTask, VMWSTR pNetDigest);

/**
 * 删除任务
 *
 * @param 				pszVersionID 要删除任务的版本号ID
 *
 * @return                		删除成功返回VAM_DL_OK,否则返回VAM_DL_ERR
 */
static VMINT vm_vam_delete_task(VMUINT32 nAppID/*VMWSTR pszVersionID*/);

/**
 * 保存任务列表
 *
 * @param  				保存成功返回VAM_DL_OK, 否则返回VAM_DL_ERR
 */
static VMINT vm_vam_save_task_list(void);

/**
 * 添加任务到列表中
 *
 * @param				pszVersionID 应用版本号ID
 * @param 				pszFileName 文件名
 *
 * @return        			添加成功返回VAM_DL_OK，否则返回VAM_DL_ERR
 */
static VMINT vm_vam_add_task(VMUINT32 nAppID/*VMWSTR pszVersionID*/, VMWSTR pszFileName);

/**
 * 获取任务
 *
 * @param 				pszVersionID  应用版本号ID
 * @return  				获取成功返回任务指针，否则返回NULL
 */
static Vam_Task_t * vm_vam_get_task(VMUINT32 nAppID/*VMWSTR pszVersionID*/);

/**
 * 保存下载数据
 * 
 * @param 				pTask 下载的任务
 * @param 				pszData 要保存的数据
 * @param				nDataSize 要保存数据的大小
 *
 * @return                      	保存成功返回VAM_DL_OK
 */
static VMINT vm_vam_save_data(Vam_Task_t * pTask, VMSTR pszData, VMINT nDataSize);

/**
 * 更新任务进度
 *
 * @param 				pTask 任务
 *
 */
static void vm_vam_update_task_percent(Vam_Task_t * pTask);

/**
 * VAM中启动定时器下载应用的处理
 *
 * @param nTimerID      定时器ID
 */
static void vm_vam_download_app_proc(VMINT nTimerID);

/**
 * 获取列表个数
 *
 * @return 返回任务个数
 */
static VMINT vm_vam_task_count(void);

/**
 * 将任务列表整合到buf中
 *
 * @param pTaskRoot        任务列表
 * @param pTaskBuf         缓存
 *
 * @return                 成功返回任务总长度，否则返回VAM_DL_ERR
 */
static VMINT vm_vam_save_task_list_buf(Vam_Task_t * pTaskRoot, VMCHAR * pTaskBuf);

/**
 * 获取指定盘符的剩余空间
 *
 * @nDriver 指定的盘符
 *
 * @return 返回指定盘符的剩余空间
 */
static VMUINT vm_vam_get_free_space(VMINT8 nDriver);//rencai.xiao 10/01/21 修改返回值类型

static VMINT dm_file_copy(VMWSTR pwFileName, VMWSTR pwNewFileName);

static VMINT vm_vam_get_task_size(Vam_Task_t * pTask, VMINT nSize);

static VMINT vm_vam_is_file(VMWSTR pwFilePath);
static VMINT vm_vam_check_vre_folder(void);

static VMINT vm_vam_check_temp_size(Vam_Task_t * pTask);
static VMINT vm_vam_check_temp_file_size(Vam_Task_t * pTask);

static void vm_vam_connect_done_proc(VMINT nTimerID);

//rencai.xiao 2010/03/01 添加更新系统配置回调
void vm_vam_vip_syscfg_callback(VMINT uid, VMINT mpi, VMINT vip_response_type, 
							 const void* vip_response, VMUINT response_size);

/**
  * gzip解压
  * @param pSrcName                   源文件名，包含路径，需要添加.gz后缀
  * @param pDesName                  解压后的文件名
  * @param bGz                            目标串是否需要追加.gz后缀
  *
  * @return                                   成功返回0，否则返回-1
  */
VMINT vm_vam_unpack_gzip(VMWCHAR * pSrcName, VMWCHAR  * pDesName, VMUINT8 bGz);
/**
 * 判断是否是VAS
 *
 * @param nAppID APPID
 *
 * @return 返回TRUE表示是VAS，否则不是
 */
static VMINT vm_vam_is_vas(VMUINT32 nAppID);

static VMINT vm_vam_add_app_count(void);
static VMINT vm_vam_task_count(void)
{
	VMINT nCount = 0;
	Vam_Task_t * pTask = NULL;

	pTask = pTaskRoot;
	while(pTask)
	{
		nCount ++;
		pTask = pTask->next;
	}

	return nCount;
}

static VMINT vm_vam_is_file(VMWSTR pwFilePath)
{
       vm_fileinfo_ext direntry;
	VMINT nHandle;


	nHandle = vm_find_first_ext(pwFilePath, &direntry);

	if(nHandle >= 0)
	{
		vm_find_close_ext(nHandle);
		
		if ((direntry.attributes & 0x10) == 0)
			return TRUE;
		else
			return FALSE; 
	}
	else
		return FALSE;
}

//rencai.xiao 2010/03/01 获取应用版本号
VMINT vm_vam_get_app_version(VMWSTR filename, VMCHAR * appversion)
{
	VMINT size;
	char * tag_buf = NULL;
	
	size = 0;
	if(vm_get_vm_tag(filename, VM_CE_INFO_VER, NULL, &size) == GET_TAG_TRUE)
	{
		
		tag_buf = vm_malloc(size + 1);

		
		if(tag_buf)
		{
			memset(tag_buf, 0, size + 1);
			if(vm_get_vm_tag(filename, VM_CE_INFO_VER, tag_buf, &size) == GET_TAG_TRUE)
			{
				VMINT8 byte1, byte2, byte3;
				if(size >= 4)
				{
					memcpy(&byte1, tag_buf + 1, 1);
					memcpy(&byte2, tag_buf + 2, 1);
					memcpy(&byte3, tag_buf + 3, 1);
					sprintf(appversion, "%d.%d.%d", byte1, byte2, byte3);
				}
			}
			else
			{
				vm_free(tag_buf);

				tag_buf = NULL;
				return FALSE;
			}
			vm_free(tag_buf);

			tag_buf = NULL;
		}
		else//tab buf malloc fail.
			return FALSE;
	}
	else
		return FALSE;
	
	return TRUE;
}


//rencai.xiao 2010/03/01 解析时间
VMINT vm_vam_parse_time_data(vm_time_t *timestamp, char* str_time)
{
	VMUINT32 year;
	VMINT16 param_time;
	VMINT8 pos = 0;
	VMCHAR str_year[5];
	VMCHAR str_data[3];
	
	memset(str_year, 0, sizeof(str_year));
	
	memcpy(str_year, str_time, 4);
	year = atoi(str_year);
	
	if(year > 9999)
		return -1;
	timestamp->year = year;
	
	pos += 4;
	
	memset(str_data, 0, sizeof(str_data));
	memcpy(str_data, str_time + pos, 2);
	param_time = atoi(str_data);
	if(param_time < 0 || param_time > 12)
		return -1;
	timestamp->mon = param_time;
	pos += 2;
	
	memset(str_data, 0, sizeof(str_data));
	memcpy(str_data, str_time + pos, 2);
	param_time = atoi(str_data);
	if(param_time < 0 || param_time > 31)
		return -1;
	timestamp->day = param_time;
	pos += 2;
	
	memset(str_data, 0, sizeof(str_data));
	memcpy(str_data, str_time + pos, 2);
	param_time = atoi(str_data);
	if(param_time < 0 || param_time > 23)
		return -1;
	timestamp->hour = param_time;
	pos += 2;
	
	memset(str_data, 0, sizeof(str_data));
	memcpy(str_data, str_time + pos, 2);
	param_time = atoi(str_data);
	if(param_time < 0 || param_time > 59)
		return -1;
	timestamp->min = param_time;
	pos += 2;
	
	memset(str_data, 0, sizeof(str_data));
	memcpy(str_data, str_time + pos, 2);
	param_time = atoi(str_data);
	if(param_time <0 || param_time > 59)
		return -1;
	timestamp->sec = param_time;
	
	return 0;
}


//rencai.xiao 2010/03/01
VMINT vm_vam_is_leap_year(VMINT nYear) 
{
	if ((nYear % 4 == 0) && (nYear % 100 != 0))
		return 1;
	else if ((nYear % 100 == 0) && (nYear % 400 == 0))
		return 1;
	else
		return 0;
}

//rencai.xiao 2010/03/01
VMINT vm_vam_days_of_month(VMINT nYear, VMINT nMonth) 
{
	static VMINT nszDaysMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	VMINT nDays = -1;
	
	if (nMonth >= 1 && nMonth <= 12) 
	{
		nDays = nszDaysMonth[nMonth - 1];
		if (nMonth == 2)
			if (vm_vam_is_leap_year(nYear))
				nDays = 29;
	}
	
	return nDays;
}

//rencai.xiao 2010/03/01
VMINT vm_vam_get_today_from_2000(void)
{
	int i, nDay = -1;
	vm_time_t Time;
	
	if (vm_get_time(&Time) != 0){
		return nDay;
	}
	
	if (Time.year >= 2000) {
		nDay = 0;
		for (i = 2000; i < Time.year; i++) 
			nDay += vm_vam_is_leap_year(i) ? 366 : 365;
		
		for (i = 1; i < Time.mon; i++)
			nDay += vm_vam_days_of_month(Time.year, i);
		
		nDay += Time.day;
	}
	
	return nDay;
}


static VMINT vm_vam_check_vre_folder(void)
{
    //static VMCHAR szFileName[80];
    //static VMWCHAR szwFileName[80];
    VMINT8 nSysDriver, nRemoveDriver;
    VMINT16 nRet = 0;
    vm_log_debug("vm_vam_check_vre_folder");
    nSysDriver = vm_get_system_driver();
    nRemoveDriver = vm_get_removable_driver();

    if(nRemoveDriver > 0)
    {
       memset(g_VamTask.szFilePath, 0, sizeof(g_VamTask.szFilePath));
	memset(g_VamTask.szwFilePath, 0, sizeof(g_VamTask.szwFilePath));
	sprintf(g_VamTask.szFilePath, "%c:\\vre", nRemoveDriver);
	vm_default_to_ucs2(g_VamTask.szwFilePath, sizeof(g_VamTask.szwFilePath), g_VamTask.szFilePath);
       //memset(szFileName, 0, sizeof(szFileName));
	//memset(szwFileName, 0, sizeof(szwFileName));
       //sprintf(szFileName, "%c:\\vre", nRemoveDriver);
	//vm_default_to_ucs2(szwFileName, sizeof(szwFileName), szFileName);
	if(vm_vam_is_file(g_VamTask.szwFilePath/*szwFileName*/))
	{
	    vm_log_debug("vre folder is file.");
	    vm_file_delete(g_VamTask.szwFilePath/*szwFileName*/);
	   //modified by rencai.xiao 10/01/25
	    if(vm_file_mkdir(g_VamTask.szwFilePath/*szwFileName*/) < 0)
			nRet =  -1;
	}
	else 
	{
	    VMINT nFindHandle;
	    //struct vm_fileinfo_t fileinfo;
          //added by rencai.xiao 10/01/25
	    nFindHandle = vm_find_first(g_VamTask.szwFilePath/*szwFileName*/, &fileinfo);
#ifdef LOG_AM_DOWNLOAD
           vm_log_debug("[AM] nFindhandle = %d", nFindHandle);
#endif
	    if(nFindHandle < 0)
	    {
	        if(vm_file_mkdir(g_VamTask.szwFilePath/*szwFileName*/) < 0)
			nRet = -1;
	    }
	    else
		 vm_find_close(nFindHandle);
	}
    }
     if(nSysDriver> 0)
    {
       memset(g_VamTask.szFilePath, 0, sizeof(g_VamTask.szFilePath));
	memset(g_VamTask.szwFilePath, 0, sizeof(g_VamTask.szwFilePath));
	sprintf(g_VamTask.szFilePath, "%c:\\vre", nSysDriver);
	vm_default_to_ucs2(g_VamTask.szwFilePath, sizeof(g_VamTask.szwFilePath), g_VamTask.szFilePath);
       //memset(szFileName, 0, sizeof(szFileName));
	//memset(szwFileName, 0, sizeof(szwFileName));
       //sprintf(szFileName, "%c:\\vre", nSysDriver);
	
	//vm_default_to_ucs2(szwFileName, sizeof(szwFileName), szFileName);
	if(vm_vam_is_file(g_VamTask.szwFilePath/*szwFileName*/))
	{
	    vm_file_delete(g_VamTask.szwFilePath/*szwFileName*/);
	}

	    //modified by rencai.xiao 10/01/25
	    vm_file_mkdir(g_VamTask.szwFilePath/*szwFileName*/);

    }

   if(nRet == -1)
   	return -1;

   return TRUE;
}
static VMINT vm_vam_add_app_count(void)
{
	VMINT nCount = 0;
	Vam_Task_t * pTask = NULL;
	
	pTask = pTaskRoot;
	while(pTask)
	{
		if(pTask->nASFlag == VAM_ADD_APP)
		   nCount ++;
		pTask = pTask->next;
	}
	
	return nCount;
}

static VMINT vm_vam_save_task_list(void)
{
	Vam_Task_t * pTask = NULL;
	VMINT nFileHandle;
	VMINT nDriver;
	//static VMCHAR szFilePath[50];
	//static VMWCHAR szwFilePaht[50];
	VMINT nCount;
	VMUINT nWritten;
	VMCHAR * pTaskBuf = NULL;
	VMINT nTaskLen;
	md5_state_t md5State;
	md5_byte_t szDigest[16];
	static VMCHAR szMd5String[25];
	VMINT nMd5Len;
	
	//rencai.xiao 2010/03/04
	//static VMCHAR vrefolder[20];
	//static VMWCHAR wvrefolder[20];
	VMINT nFindHandle;
	//struct vm_fileinfo_t  fileinfo; 

#ifdef LOG_AM_DOWNLOAD
	vm_log_fatal("vm_vam_save_task_list");
#endif

       memset(g_VamTask.szFilePath, 0, sizeof(g_VamTask.szFilePath));
	memset(g_VamTask.szwFilePath, 0, sizeof(g_VamTask.szwFilePath));
	
	//memset(szFilePath, 0, sizeof(szFilePath));
	//memset(szwFilePaht, 0, sizeof(szwFilePaht));
	memset(szMd5String, 0, sizeof(szMd5String));
	pTask = pTaskRoot;


      //rencai.xiao 2010/03/07
      if(g_VamTask.vam_malloc == NULL || g_VamTask.vam_free == NULL)
	  	return VAM_DL_ERR;

	

	nCount = vm_vam_task_count();
	
	pTaskBuf = /*vm_malloc*/g_VamTask.vam_malloc(VAM_TASK_BUF_SIZE + 1);
	if(!pTaskBuf)
		return VAM_DL_ERR;
	memset(pTaskBuf, 0, VAM_TASK_BUF_SIZE + 1);
	
	//添加任务个数
	memcpy(pTaskBuf + VAM_INT_SIZE, &nCount, VAM_INT_SIZE);

	if(vm_vam_task_count() > 0)
	    nTaskLen = vm_vam_save_task_list_buf(pTaskRoot, pTaskBuf + VAM_INT_SIZE * 2);
	else
	    nTaskLen = 0;
	if(nTaskLen == VAM_DL_ERR)
	{
		g_VamTask.vam_free(pTaskBuf);
		pTaskBuf = NULL;
		//SAFE_FREE(pTaskBuf);
		return VAM_DL_ERR;
	}

	//添加任务列表长度
	nTaskLen += VAM_INT_SIZE;//包含个数的长度
	memcpy(pTaskBuf, &nTaskLen, VAM_INT_SIZE);

	nDriver = vm_get_removable_driver();
	if(nDriver < 0)
		nDriver = vm_get_system_driver();

	//rencai.xiao 2010/03/04
	//memset(vrefolder, 0, sizeof(vrefolder));
       //memset(wvrefolder, 0, sizeof(wvrefolder));
	//sprintf(vrefolder, "%c:\\vre", nDriver);
	sprintf(g_VamTask.szFilePath, "%c:\\vre", nDriver);
	#ifdef LOG_AM_DOWNLOAD
	vm_log_fatal("[AM] vrefolder = %s", g_VamTask.szFilePath);
	#endif
	//vm_ascii_to_ucs2(wvrefolder, sizeof(wvrefolder), vrefolder);
	vm_ascii_to_ucs2(g_VamTask.szwFilePath, sizeof(g_VamTask.szwFilePath), g_VamTask.szFilePath);
	nFindHandle = vm_find_first(g_VamTask.szwFilePath/*wvrefolder*/, &fileinfo);
	if(nFindHandle < 0)
	{
	    VMINT nRet;
		
	#ifdef LOG_AM_DOWNLOAD
	    vm_log_fatal("[AM] rm vre dir.");
	#endif
	    nRet = vm_file_mkdir(g_VamTask.szwFilePath/*wvrefolder*/);
	#ifdef LOG_AM_DOWNLOAD
	    vm_log_fatal("[AM] vm_file_rmdir nRet = %d", nRet);
	#endif
	}
	else
		vm_find_close(nFindHandle);
    	//memset(szFilePath, 0, sizeof(szFilePath));
	//memset(szwFilePaht, 0, sizeof(szwFilePaht));
	//sprintf(szFilePath, "%c:\\vre\\%s", nDriver, VAM_TASK_FILENAME);
    	//vm_ascii_to_ucs2(szwFilePaht, sizeof(szwFilePaht), szFilePath);
    	memset(g_VamTask.szFilePath, 0, sizeof(g_VamTask.szFilePath));
	memset(g_VamTask.szwFilePath, 0, sizeof(g_VamTask.szwFilePath));
	sprintf(g_VamTask.szFilePath, "%c:\\vre\\%s", nDriver, VAM_TASK_FILENAME);
	vm_ascii_to_ucs2(g_VamTask.szwFilePath, sizeof(g_VamTask.szwFilePath), g_VamTask.szFilePath);
	nFileHandle = vm_file_open(g_VamTask.szwFilePath, MODE_CREATE_ALWAYS_WRITE, TRUE);
	if(nFileHandle < 0)
	{
		g_VamTask.vam_free(pTaskBuf);
		pTaskBuf = NULL;
		return VAM_DL_IO_ERROR;
	}

	//初始化MD5
	md5_init(&md5State);
	//计算MD5
	md5_append(&md5State, (const md5_byte_t *)pTaskBuf, nTaskLen + VAM_INT_SIZE);
	//将内容写入文件
	if(vm_vam_get_free_space((VMINT8)nDriver) < (VMINT)(nTaskLen + VAM_INT_SIZE))
	{
	      vm_log_debug("[AM] no enough free space flag 6");
		g_VamTask.vam_free(pTaskBuf);
		pTaskBuf = NULL;
		vm_file_close(nFileHandle);
		md5_finish(&md5State, szDigest);
		return VAM_DL_SPACE_FULL;
	}
	if(vm_file_write(nFileHandle, pTaskBuf, nTaskLen + VAM_INT_SIZE, &nWritten) != (VMINT)(nTaskLen + VAM_INT_SIZE))
	{
		g_VamTask.vam_free(pTaskBuf);
		pTaskBuf = NULL;
		vm_file_close(nFileHandle);
		md5_finish(&md5State, szDigest);
		return VAM_DL_IO_ERROR;
	}

	md5_append(&md5State, (const md5_byte_t *)g_VamTask.pHistoryList, g_VamTask.nHistoryLen + VAM_INT_SIZE);
	if(vm_vam_get_free_space((VMINT8)nDriver) < (VMUINT)(g_VamTask.nHistoryLen + VAM_INT_SIZE))
	{
		g_VamTask.vam_free(pTaskBuf);
		pTaskBuf = NULL;
		vm_file_close(nFileHandle);
		md5_finish(&md5State, szDigest);
		return VAM_DL_SPACE_FULL;
	}
	if(vm_file_write(nFileHandle, g_VamTask.pHistoryList, g_VamTask.nHistoryLen + VAM_INT_SIZE, &nWritten) != (VMINT)(g_VamTask.nHistoryLen + VAM_INT_SIZE))
	{
md5_finish(&md5State, szDigest);
		g_VamTask.vam_free(pTaskBuf);
		pTaskBuf = NULL;

		vm_file_close(nFileHandle);
		return VAM_DL_IO_ERROR;  
	}
	
	//计算MD5
	md5_finish(&md5State, szDigest);
	
	//将MD5写入文件
	nMd5Len = 16;
	memset(szMd5String, 0, sizeof(szMd5String));
	memcpy(szMd5String, &nMd5Len, VAM_INT_SIZE);
	memcpy(szMd5String + VAM_INT_SIZE, szDigest, sizeof(szDigest));
	if(vm_vam_get_free_space((VMINT8)nDriver) < (VMUINT)(sizeof(szDigest) + VAM_INT_SIZE))
	{
		g_VamTask.vam_free(pTaskBuf);
		pTaskBuf = NULL;
		vm_file_close(nFileHandle);
		return VAM_DL_SPACE_FULL;
	}
	if(vm_file_write(nFileHandle, szMd5String, sizeof(szDigest) + VAM_INT_SIZE, &nWritten) != sizeof(szDigest) + VAM_INT_SIZE)
	{

        g_VamTask.vam_free(pTaskBuf);
		pTaskBuf = NULL;
		vm_file_close(nFileHandle);
		return VAM_DL_IO_ERROR;
	}

	vm_file_commit(nFileHandle);
	vm_file_close(nFileHandle);

	g_VamTask.vam_free(pTaskBuf);
	pTaskBuf = NULL;

	return VAM_DL_OK;
}

static void vm_vam_download_app_proc(VMINT nTimerID)
{
	VMINT nReqRet;
	if(g_VamTask.nTimerID >= 0)
    	{
    		//vm_delete_timer(g_VamTask.nTimerID);
			vm_delete_timer_ex(g_VamTask.nTimerID);
    		g_VamTask.nTimerID = -1;
    	}
    
	 nReqRet = vm_vam_request_data(g_VamTask.pDownloadingTask);
    	if(nReqRet == VAM_DL_ERR || nReqRet == VAM_DL_IO_ERROR)
		{
			if(g_VamTask.download_app_cb)
				g_VamTask.download_app_cb(nReqRet, g_VamTask.pDownloadingTask->nPercent);
		    vm_vam_release_task_list();
		}
       	return;
}

static VMINT vm_vam_get_download_percent(Vam_Task_t * pTask)
{
	VMUINT nFileSize;
	
	if(pTask->nFilehandle >= 0)
	{
		vm_file_seek(pTask->nFilehandle, 0, BASE_BEGIN);
		vm_file_getfilesize(pTask->nFilehandle, &nFileSize);
	}
	else
	{
		//临时文件未打开时，将其打开获取文件大小
		if(vm_vam_open_temp_file(pTask) == VAM_DL_ERR)
			return 0;
		vm_file_seek(pTask->nFilehandle, 0, BASE_BEGIN);
		vm_file_getfilesize(pTask->nFilehandle, &nFileSize);
	}
	
	//关闭句柄
	vm_file_close(pTask->nFilehandle);
	pTask->nFilehandle = -1;
	
	
	if(pTask->nFilesize > 0 && (VMINT)nFileSize <= pTask->nFilesize)
		pTask->nPercent = ((VMINT)nFileSize  * 100) / pTask->nFilesize;
	else
		pTask->nPercent = 0;
	
	if((VMINT)nFileSize == pTask->nFilesize && nFileSize > 0 && pTask->nFilesize > 0)
		pTask->nPercent = 99;
	
	return pTask->nPercent;
}

 VMINT vm_get_total_and_downloaded_size(VMUINT * nTotalSize, VMUINT * nDownloadedSize)
 {
   VMUINT nFileSize;
	 Vam_Task_t * pTask = g_VamTask.pDownloadingTask;

	 if(!pTask)
	 	return VAM_DL_ERR;
	
	if(pTask->nFilehandle >= 0)
	{
		vm_file_seek(pTask->nFilehandle, 0, BASE_BEGIN);
		vm_file_getfilesize(pTask->nFilehandle, &nFileSize);
	}
	else
	{
		//临时文件未打开时，将其打开获取文件大小
		if(vm_vam_open_temp_file(pTask) == VAM_DL_ERR)
			return VAM_DL_ERR;
		vm_file_seek(pTask->nFilehandle, 0, BASE_BEGIN);
		vm_file_getfilesize(pTask->nFilehandle, &nFileSize);
	}

	*nDownloadedSize = nFileSize;
	*nTotalSize = pTask->nFilesize;
	
	return VAM_DL_OK;
 }

void vm_vam_update_task_percent(Vam_Task_t * pTask)
{

#ifdef LOG_AM_DOWNLOAD
      vm_log_fatal("[AM] vm_vam_update_task_percent");
#endif
	pTask->nPercent = vm_vam_get_download_percent(pTask);
#ifdef LOG_AM_DOWNLOAD
    vm_log_fatal("[AM] percent = %d", pTask->nPercent );
#endif
       //rencai.xiao 10/02/22
       g_VamTask.nRetryCount = 0;
	
	//状态更新，通知UI刷新窗口
	if(g_VamTask.download_app_cb)
		g_VamTask.download_app_cb(VAM_DL_OK, pTask->nPercent);
	
	//保存已下载列表
    	vm_vam_save_task_list();
	
	//启动定时器继续下载
	g_VamTask.nTimerID = vm_create_timer_ex(VAM_DOWNLOAD_INTERVAL, vm_vam_download_app_proc);
	
	return;
}

static VMINT vm_vam_save_data(Vam_Task_t * pTask, VMSTR pszData, VMINT nDataSize)
{
	VMUINT nWitten, nFileSize;
#ifdef LOG_AM_DOWNLOAD
      vm_log_debug("[AM] vm_vam_save_data");
#endif
	//打开临时文件
	if(vm_vam_open_temp_file(pTask) == VAM_DL_ERR)
		return VAM_DL_IO_ERROR;

	//定位到文件尾
	vm_file_seek(pTask->nFilehandle, 0, BASE_END);
	
	//追加到文件尾
	if(vm_vam_get_free_space((VMINT8)pTask->nDriver) < (VMUINT)nDataSize)
	{
#ifdef LOG_AM_DOWNLOAD
	       vm_log_fatal("[AM] no enough free space flag 9");
		vm_log_fatal("file write error.");
#endif
		vm_file_close(pTask->nFilehandle);
		pTask->nFilehandle = -1;
		return VAM_DL_SPACE_FULL;
	}
	vm_file_write(pTask->nFilehandle, pszData, nDataSize, &nWitten);
	if(nDataSize != (VMINT)nWitten)
	{
#ifdef LOG_AM_DOWNLOAD
            vm_log_debug("[AM] write data error. nDataSize = %d, nWritten = %d", nDataSize, nWitten);
#endif
		//写入失败
		vm_file_close(pTask->nFilehandle);
		pTask->nFilehandle = -1;
		return VAM_DL_IO_ERROR;
	}
	vm_file_commit(pTask->nFilehandle);

	//判断App是否已经下载完成
	vm_file_seek(pTask->nFilehandle, 0, BASE_BEGIN);
	vm_file_getfilesize(pTask->nFilehandle, &nFileSize);
    	if(pTask->nFilesize == (VMINT)nFileSize)
	{
		//应用下载完成，重命名
		//static VMWCHAR pFilename[MAX_LEN_FILE_NAME  + 1]/*, pTempFilename[MAX_LEN_FILE_NAME  + 1]*/;	

		//memset(pFilename, 0, sizeof(pFilename));
		//memset(pTempFilename, 0, sizeof(pTempFilename));
		//memset(g_VamTask.szwFileName, 0, sizeof(g_VamTask.szwFileName));
		VMWCHAR * pFilename = NULL, *pTempFilename = NULL;

		pFilename = g_VamTask.vam_malloc(MAX_LEN_FILE_NAME * 2 + 1);
		if(!pFilename)
			return VAM_DL_ERR;
		memset(pFilename, 0, MAX_LEN_FILE_NAME * 2 + 1);
		pTempFilename = g_VamTask.vam_malloc(MAX_LEN_FILE_NAME * 2 + 1);
		if(!pTempFilename)
		{
		    g_VamTask.vam_free(pFilename);
		    pFilename = NULL;
		    return VAM_DL_ERR;
		}
		memset(pTempFilename, 0, MAX_LEN_FILE_NAME * 2 + 1);

		
		//获取vxp文件保存路径以及tmp文件保存路径
		if(vm_vam_get_task_save_path(pTask, pFilename) == VAM_DL_ERR || vm_vam_get_temp_filename(pTempFilename, pTask->szFilename, (VMINT8)pTask->nDriver, FALSE) == VAM_DL_ERR)
		{
			vm_file_close(pTask->nFilehandle);
			pTask->nFilehandle = -1;
			g_VamTask.vam_free(pFilename);
		       pFilename = NULL;
			g_VamTask.vam_free(pTempFilename);
		       pTempFilename = NULL;
			return VAM_DL_IO_ERROR;
		}

		//重命名之前关闭临时文件句柄
		vm_file_close(pTask->nFilehandle);
	   	pTask->nFilehandle = -1;

		//下载VAS不需要重命名
		if(!g_VamTask.bAppStore)
		{
			//删除一遍vxp文件
			vm_file_delete(pFilename);
			vm_file_rmdir(pFilename);

			#ifdef AM_SUPPORT_GZIP
			if(vm_vam_unpack_gzip(pTempFilename, pFilename, TRUE))
			{
			    g_VamTask.vam_free(pFilename);
		           pFilename = NULL;
			    g_VamTask.vam_free(pTempFilename);
		           pTempFilename = NULL;
			    //重命名失败
			    return VAM_DL_IO_ERROR;
			}

			g_VamTask.vam_free(pFilename);
		       pFilename = NULL;
			g_VamTask.vam_free(pTempFilename);
		       pTempFilename = NULL;
                     return VAM_DL_DONE;
			#endif

			if(vm_file_rename(pTempFilename, pFilename) != 0)
			{
			       g_VamTask.vam_free(pFilename);
		              pFilename = NULL;
			       g_VamTask.vam_free(pTempFilename);
		              pTempFilename = NULL;
				//重命名失败
				return VAM_DL_IO_ERROR;
			}

			//删除临时文件
			vm_file_delete(pTempFilename);
		}
		else
		{
			//static VMWCHAR szAsTempName[MAX_LEN_FILE_NAME  + 1];

			//memset(szAsTempName, 0, sizeof(szAsTempName));
			memset(pFilename, 0, MAX_LEN_FILE_NAME * 2 + 1);
			//memset(pFilename, 0, sizeof(pFilename));
			if(vm_vam_get_temp_filename(pFilename/*szAsTempName*/, pTask->szFilename, (VMINT8)pTask->nDriver, TRUE) == VAM_DL_ERR)
			{
				return VAM_DL_IO_ERROR;
			}
			vm_file_delete(pFilename/*szAsTempName*/);
			vm_file_rmdir(pFilename/*szAsTempName*/);

			#ifdef AM_SUPPORT_GZIP
			if(vm_vam_unpack_gzip(pTempFilename, pFilename, TRUE))
			{
			    g_VamTask.vam_free(pFilename);
		           pFilename = NULL;
			    g_VamTask.vam_free(pTempFilename);
		           pTempFilename = NULL;
			    //重命名失败
			    return VAM_DL_IO_ERROR;
			}
			g_VamTask.vam_free(pFilename);
		       pFilename = NULL;
			g_VamTask.vam_free(pTempFilename);
		           pTempFilename = NULL;
                     return VAM_DL_DONE;
			#endif
			vm_file_rename(pTempFilename, pFilename/*szAsTempName*/);
		}

		g_VamTask.vam_free(pFilename);
		pFilename = NULL;
		g_VamTask.vam_free(pTempFilename);
		pTempFilename = NULL;
		return VAM_DL_DONE;
	}

	vm_file_close(pTask->nFilehandle);
	pTask->nFilehandle = -1;
	return VAM_DL_OK;
}

static Vam_Task_t * vm_vam_get_task(VMUINT32 nAppID/*VMWSTR pszVersionID*/)
{
	Vam_Task_t * pTask = NULL;
	VMINT8 nASFlag;

	if(vm_vam_is_vas(nAppID))
		nASFlag = VAM_ADD_VAS;
	else
		nASFlag = VAM_ADD_APP;

	pTask = pTaskRoot;
	while(pTask)
	{
		if(pTask->nASFlag == nASFlag && pTask->nAppid == nAppID)
			return pTask;
		pTask = pTask->next;
	}

	return pTask;
}

static VMINT vm_vam_add_task(VMUINT32 nAppID, VMWSTR pszFileName)
{
	Vam_Task_t * pTempTask = pTaskRoot;
  	Vam_Task_t * pTask = NULL, * pEndTask = NULL;
	VMINT8 nASFlag;
	Vam_Task_t * pOldTask = NULL;

	if(vm_vam_is_vas(nAppID))
		nASFlag = VAM_ADD_VAS;
	else
		nASFlag = VAM_ADD_APP;

  	while(pTempTask)
  	{
		if(pTempTask->nASFlag == nASFlag && pTempTask->nAppid == nAppID)
	  	{
			//由VAM添加且在列表中
		  	return VAM_DL_DONE;
	  	}
		if(!pOldTask && pTempTask->nASFlag == VAM_ADD_APP)
			pOldTask = pTempTask;
	  	pEndTask = pTempTask;
	  	pTempTask = pTempTask->next;
  	}

	if(vm_vam_add_app_count() >= VAM_MAX_APP_NUM)
	{
		if(vm_vam_delete_task(pOldTask->nAppid) == VAM_DL_ERR)
			return VAM_DL_ERR;
	}

  	//添加新任务到列表尾部
  	pTask = g_VamTask.vam_malloc(sizeof(Vam_Task_t));
  	if(!pTask)
		return VAM_DL_ERR;
  	memset(pTask, 0, sizeof(Vam_Task_t));

	//赋值
  	pTask->eState = APPDLSTATE_WAIT;
  	pTask->nPercent = 0;
  	pTask->nFilehandle = -1;
  	pTask->nDriver = vm_get_removable_driver();
  	if(pTask->nDriver < 0)
		pTask->nDriver = vm_get_system_driver();
  	pTask->nRetryCount = 0;
  	pTask->nFilesize = 0;
	if(vm_vam_is_vas(nAppID))
		pTask->nASFlag = VAM_ADD_VAS;
	else
  	    pTask->nASFlag = VAM_ADD_APP;//VAM添加标志
  	vm_wstrcpy(pTask->szFilename, pszFileName);
  	
	pTask->nAppid = nAppID;

  	if(pEndTask)
    		pEndTask->next = pTask;
  	else
		pTaskRoot = pTask;  
  	pTask->next = NULL;

  	return VAM_DL_OK;  
}

static VMINT vm_vam_save_task_list_buf(Vam_Task_t * pTaskRoot, VMCHAR * pTaskBuf)
{
	Vam_Task_t * pTask = NULL;
  	VMINT nTaskLen = 0;
  	VMINT nFileNameLen, nVersionIDLen, nNameLen, nDigestLen, nTimeLen;

  	pTask = pTaskRoot;
  	while(pTask)
  	{
		//任务状态
	  	memcpy(pTaskBuf + nTaskLen, &pTask->eState, VAM_INT_SIZE);
	  	nTaskLen += VAM_INT_SIZE;
	  	//任务进度
	  	memcpy(pTaskBuf + nTaskLen, &pTask->nPercent, VAM_INT_SIZE);
	  	nTaskLen += VAM_INT_SIZE;
	  	//临时文件句柄
      		memcpy(pTaskBuf + nTaskLen, &pTask->nFilehandle, VAM_INT_SIZE);
      		nTaskLen += VAM_INT_SIZE;
	  	//临时文件存放位置
	  	memcpy(pTaskBuf + nTaskLen, &pTask->nDriver, VAM_INT_SIZE);
	  	nTaskLen += VAM_INT_SIZE;
	  	//重试次数
	  	memcpy(pTaskBuf + nTaskLen, &pTask->nRetryCount, VAM_INT_SIZE);
	  	nTaskLen += VAM_INT_SIZE;
	  	//文件大小
	  	memcpy(pTaskBuf + nTaskLen, &pTask->nFilesize, VAM_INT_SIZE);
	  	nTaskLen += VAM_INT_SIZE;
	  	//标记
	  	memcpy(pTaskBuf + nTaskLen, &pTask->nASFlag, VAM_INT_SIZE);
	  	nTaskLen += VAM_INT_SIZE;
	  	//应用ID
	  	memcpy(pTaskBuf + nTaskLen, &pTask->nAppid, VAM_INT_SIZE);
	  	nTaskLen += VAM_INT_SIZE;
	  
	  	//文件名长度
	  	nFileNameLen = vm_wstrlen(pTask->szFilename) * 2;
	  	memcpy(pTaskBuf + nTaskLen, &nFileNameLen, VAM_INT_SIZE);
	  	nTaskLen += VAM_INT_SIZE;
	  	//文件名
	  	memcpy(pTaskBuf + nTaskLen, pTask->szFilename, nFileNameLen);
	  	nTaskLen += (nFileNameLen);
	  
	  	//版本号ID长度
	  	nVersionIDLen = vm_wstrlen(pTask->szVersionID) * 2;
	  	memcpy(pTaskBuf + nTaskLen, &nVersionIDLen, VAM_INT_SIZE);
	  	nTaskLen += VAM_INT_SIZE;
	  	//版本号ID
	  	memcpy(pTaskBuf + nTaskLen, pTask->szVersionID, nVersionIDLen);
	  	nTaskLen += (nVersionIDLen);
	  
	  	//任务名称长度
	  	nNameLen = vm_wstrlen(pTask->szName) * 2;
	  	memcpy(pTaskBuf + nTaskLen, &nNameLen, VAM_INT_SIZE);
	  	nTaskLen += VAM_INT_SIZE;
	  	//任务名称
	  	memcpy(pTaskBuf + nTaskLen, pTask->szName, nNameLen);
	  	nTaskLen += (nNameLen);
	  
	  	//摘要长度
	  	nDigestLen = vm_wstrlen(pTask->szVXPDigest) * 2;
	  	memcpy(pTaskBuf + nTaskLen, &nDigestLen, VAM_INT_SIZE);
	  	nTaskLen += VAM_INT_SIZE;
	  	//摘要
	  	memcpy(pTaskBuf + nTaskLen, pTask->szVXPDigest, nDigestLen);
	  	nTaskLen += (nDigestLen );

	  	//时间
	  	nTimeLen = vm_wstrlen(pTask->szTime) * 2;
	  	memcpy(pTaskBuf + nTaskLen, &nTimeLen, VAM_INT_SIZE);
	  	nTaskLen += VAM_INT_SIZE;
	  	memcpy(pTaskBuf + nTaskLen, pTask->szTime, nTimeLen);
	  	nTaskLen += (nTimeLen);

	  	pTask = pTask->next;
  }

  return nTaskLen;
}

static VMINT vm_vam_delete_task(VMUINT32 nAppID)
{
	Vam_Task_t * pTask = NULL, * pBefoTask = NULL, * pTempTask = NULL;

	if(!pTaskRoot)
		return VAM_DL_ERR;
	pTask = pTaskRoot;
	pBefoTask = pTaskRoot;
	while(pTask)
	{
		if(pTask->nAppid == nAppID)
		{
			if(pTask == pTaskRoot)
			{
				pTaskRoot = pTask->next;
				pTask->next = NULL;
				g_VamTask.vam_free(pTask);
				pTask = NULL;
				pTask = pTaskRoot;
			}
			else
			{
				if(pBefoTask && pTask)
					pBefoTask->next = pTask->next;

				pTempTask = pTask->next;
				pTask->next = NULL;
				//SAFE_FREE(pTask);
				g_VamTask.vam_free(pTask);
				pTask = NULL;
				pTask = pTempTask;
			}
		}
		else
		{
			pBefoTask = pTask;
			pTask = pTask->next;
		}
	}

   return VAM_DL_OK;
}

static void vm_vam_download_finish(Vam_Task_t * pTask)
{
       VMINT8 nDriver = pTask->nDriver;
#ifdef LOG_AM_DOWNLOAD
       vm_log_fatal("[AM] vm_vam_download_finish, Driver = %d", nDriver);
#endif
	//关闭临时文件句柄
	if(pTask->nFilehandle >= 0)
	{
		vm_file_close(pTask->nFilehandle);
		pTask->nFilehandle = -1;
	}
	
	//更改任务状态,标记为失败
	pTask->eState = APPDLSTATE_OK;
		
	//从链表中清除该任务
	vm_vam_delete_task(pTask->nAppid/*pTask->szVersionID*/);
#ifdef LOG_AM_DOWNLOAD
       vm_log_fatal("[AM] save task list");
#endif
	//保存链表
	if(g_VamTask.nIsSave == FALSE)
	{
	   vm_vam_save_task_list();
          g_VamTask.nIsSave = TRUE;
	}
#ifdef LOG_AM_DOWNLOAD
      vm_log_fatal("[AM] release task list");
#endif
	//释放链表
	vm_vam_release_task_list();
#ifdef LOG_AM_DOWNLOAD
       vm_log_fatal("[AM] cancel request and finalize");
#endif
	//vip_cancel_request_and_finalize();
	vip_cancel_request_handle(VIP_APP_HANDLE);
#ifdef LOG_AM_DOWNLOAD
       vm_log_fatal("[AM] download app cb, nDriver = %c", nDriver);
#endif
       g_VamTask.nRetryCount = 0;
        //rencai.xiao 2010/03/18
       g_VamTask.bDlApp = FALSE;
	//通知VAM下载完成,将盘符回传
	if(g_VamTask.download_app_cb)
		g_VamTask.download_app_cb(VAM_DL_DONE, nDriver/*pTask->nDriver*/);
#ifdef LOG_AM_DOWNLOAD
	vm_log_fatal("[AM] finish done");
#endif
	
}

static VMINT vm_vam_check_temp_file(Vam_Task_t * pTask, VMWSTR pNetDigest)
{
       VMUINT nFileSize = 0;

	 if(vm_vam_open_temp_file(pTask) == VAM_DL_ERR)
		return VAM_DL_ERR;
			
       vm_file_seek(pTask->nFilehandle, 0, BASE_BEGIN);
	vm_file_getfilesize(pTask->nFilehandle, &nFileSize);
	
	if(vm_wstrlen(pTask->szVXPDigest) > 0 && vm_wstrcmp(pTask->szVXPDigest, pNetDigest) == 0)
	{
	       if(pTask->nFilesize < nFileSize)
		   	return VAM_DL_ERR;
		return VAM_DL_OK;
	}
	else
	{
		
		//判断临时文件大小是否为0
		if(vm_wstrlen(pTask->szVXPDigest) > 0 && vm_wstrcmp(pTask->szVXPDigest, pNetDigest) != 0)
		{
			
			if((VMINT)nFileSize == 0)//临时文件为0时返回DM_OK
				return VAM_DL_OK;
			else
				return VAM_DL_ERR;
		}
		else
			return VAM_DL_OK;
	}
}

static void vm_vam_release_task_list(void)
{
	Vam_Task_t * pTask = NULL , *pNextTask = NULL;

	      //rencai.xiao 2010/03/07
      if(g_VamTask.vam_malloc == NULL || g_VamTask.vam_free == NULL)
	  	return ;

      vm_log_debug("vm_vam_release_task_list ..");
	pTask = pTaskRoot;
	while(pTask)
	{
		pNextTask = pTask->next;
	
		if(pTask->nFilehandle >= 0)
		{
			vm_file_close(pTask->nFilehandle);
			pTask->nFilehandle = -1;
		}
		g_VamTask.vam_free(pTask);
		pTask = NULL;
		pTask = pNextTask;
	}

	pTaskRoot = NULL;
      vm_log_debug("release History List. g_VamTask.pHistoryList = %p", g_VamTask.pHistoryList);
	//释放历史列表
	if(g_VamTask.pHistoryList)
	{
		g_VamTask.vam_free(g_VamTask.pHistoryList);
		g_VamTask.pHistoryList = NULL;
		g_VamTask.nHistoryLen = 0;
	}
	vm_log_debug("vm_vam_release_task_list end.");
}

static void vm_vam_download_app_fail(Vam_Task_t * pTask, VMINT nErrorCode)
{
	VMINT8 nFailFlag;
#ifdef LOG_AM_DOWNLOAD
	vm_log_fatal("[AM] vm_vam_download_app_fail");
#endif
	nFailFlag = pTask->eState;
	//关闭临时文件句柄
	if(pTask->nFilehandle >= 0)
	{
		vm_file_close(pTask->nFilehandle);
		pTask->nFilehandle = -1;
	}

	if(!g_VamTask.pDownloadingTask)
		g_VamTask.pDownloadingTask = pTask;

	//更改任务状态,标记为失败
	//pTask->eState = APPDLSTATE_FAIL;

	if(g_VamTask.pDownloadingTask->eState != APPDLSTATE_WAIT)
	{
	//清除保存的正在下载的信息
	g_VamTask.pDownloadingTask = NULL;

	//释放列表
	vm_vam_release_task_list();
#ifdef LOG_AM_DOWNLOAD
	       vm_log_fatal("[AM] start cancel request.");
#endif
	//vip_cancel_request_and_finalize();
	vip_cancel_request_handle(VIP_APP_HANDLE);
	}

	//状态更新
	if(nFailFlag == APPDLSTATE_FAIL)
	{
		VMINT nRetCode;

	      //added by rencai.xiao 2010/05/28
	      if(nErrorCode == 1302)
		  	nRetCode = VAM_DL_1302_ERR;
	      else if(nErrorCode >= 1401 && nErrorCode <= 1407)
		  	nRetCode = 1401 - nErrorCode - 10;
		else
			nRetCode = VAM_DL_ERR;
	       //rencai.xiao 2010/03/18
		g_VamTask.bDlApp = FALSE;
	       g_VamTask.nRetryCount = 0;
	       g_VamTask.nIsSave = TRUE;


	       #ifdef LOG_AM_DOWNLOAD
		   vm_log_fatal("[AM] nRetCode = %d", nRetCode);
		#endif


		//modified by rencai.xiao 2010/05/28
 		if(g_VamTask.download_app_cb)
 			g_VamTask.download_app_cb(/*VAM_DL_ERR*/nRetCode, 0);
	
#ifdef LOG_AM_DOWNLOAD
		vm_log_fatal("[AM] download app cb end.");
#endif
	}
	else
	{
		//启动定时器继续下载
#ifdef LOG_AM_DOWNLOAD
	  vm_log_fatal("[AM] start create_timer_ex");
#endif
	  g_VamTask.nTimerID = vm_create_timer_ex(VAM_DOWNLOAD_INTERVAL, vm_vam_download_app_proc);
	}
}

static void vm_vam_string_byte_switch(VMWCHAR * pwDesData, VMWCHAR * pwSrcData)
{
	VMINT i;
	
	for(i = 0 ; i < vm_wstrlen(pwSrcData) ; i ++)
	{
		pwDesData[i] = (pwSrcData[i] >> 8) | (pwSrcData[i] << 8);
	}
}

static void vm_vam_string_byte_switch_ex(VMWCHAR * pwDesData, VMWCHAR * pwSrcData, VMINT nStrlen)
{
	VMINT i;

	for(i = 0 ; i < nStrlen/*vm_wstrlen(pwSrcData)*/ ; i ++)
	{
		pwDesData[i] = (pwSrcData[i] >> 8) | (pwSrcData[i] << 8);
	}
}

static void vm_vam_int_byte_switch(VMCHAR * pSrcData, VMUINT32 * pDestData32, VMUINT16 * pDestData16)
{
	if(pDestData32)
	{
		//32位整型字节交换
		VMCHAR szStrData[5];
		
		memset(szStrData, 0, sizeof(szStrData));
		
		szStrData[0] = pSrcData[3];
		szStrData[1] = pSrcData[2];
		szStrData[2] = pSrcData[1];
		szStrData[3] = pSrcData[0];
        
		memcpy(pDestData32, szStrData, 4);
	}
	else if(pDestData16)
	{
		//16位整型字节交换
		VMCHAR szStrData[3];
		
		memset(szStrData, 0, sizeof(szStrData));
		
		szStrData[0] = pSrcData[1];
		szStrData[1] = pSrcData[0];
		
		memcpy(pDestData16, szStrData, 2);
	}
	
}

static VMUINT vm_vam_get_free_space(VMINT8 nDriver)
{
	VMCHAR swDriver[4] = {0};
	VMWCHAR wswDriver[4] = {0};
	
	sprintf(swDriver, "%c", (VMCHAR)nDriver);
	memset(wswDriver, 0, sizeof(wswDriver));
	vm_ascii_to_ucs2(wswDriver, sizeof(wswDriver), swDriver);
	
	return vm_get_disk_free_space(wswDriver);
}


static VMINT vm_vam_check_temp_size(Vam_Task_t * pTask)
{
    VMUINT nFileSize = 0;
	
      if(pTask->nFilehandle >= 0)
	{
		vm_file_seek(pTask->nFilehandle, 0, BASE_BEGIN);
		vm_file_getfilesize(pTask->nFilehandle, &nFileSize);
	}
	else
	{
		//临时文件未打开时，将其打开获取文件大小
		if(vm_vam_open_temp_file(pTask) == VAM_DL_ERR)
			return 0;
		vm_file_seek(pTask->nFilehandle, 0, BASE_BEGIN);
		vm_file_getfilesize(pTask->nFilehandle, &nFileSize);
		vm_file_close(pTask->nFilehandle);
		pTask->nFilehandle = -1;
	}

	return (VMINT)nFileSize;
}


/**
  * gzip解压
  * @param pSrcName                   源文件名，包含路径，需要添加.gz后缀
  * @param pDesName                  解压后的文件名
  * @param bGz                            目标串是否需要追加.gz后缀
  *
  * @return                                   成功返回0，否则返回-1
  */
  #ifdef AM_SUPPORT_GZIP
  extern void *mmi_am_scrmem_malloc(int size);
  extern void mmi_am_scrmem_free(void *point);
VMINT vm_vam_unpack_gzip(VMWCHAR * pSrcName, VMWCHAR  * pDesName, VMUINT8 bGz)
{
    VMWCHAR szwSuffix[8];
    gzip_file_and_mem_t gzip_file_mem;
    VMCHAR * pDes = NULL;
    VMINT nRet;

    #ifdef LOG_AM_DOWNLOAD
	vm_log_fatal("[AM] vm_vam_unpack_gzip bGz = %d", bGz);
    #endif

    if(bGz)
    {
	    memset(szwSuffix, 0, sizeof(szwSuffix));
	    vm_chset_convert(VM_CHSET_ASCII, VM_CHSET_UCS2, VAM_GZIP_SUFFIX, (VMSTR)szwSuffix, sizeof(szwSuffix));

	     /*追加.gz*/
	   vm_wstrcat(pDesName, szwSuffix);

	   /*重命名之前，删除一遍.gz文件*/
	   vm_file_delete(pDesName);
/*
	   #ifdef LOG_AM_DOWNLOAD
	   {
	      static VMCHAR szLog[80];

	      memset(szLog, 0, sizeof(szLog));
	      vm_chset_convert(VM_CHSET_UCS2, VM_CHSET_ASCII, (VMSTR)pSrcName, szLog, sizeof(szLog));
	   }
	   #endif
*/
	   /*将tmp文件重名名成vxp.gz*/
	   if(vm_file_rename(pSrcName, pDesName) != 0)
	   	return -1;
    	}

    vm_gzip_pre_decompress(mmi_am_scrmem_malloc/*mmi_frm_scrmem_alloc*/, mmi_am_scrmem_free);
	
   #ifdef LOG_AM_DOWNLOAD
   vm_log_fatal("[AM] start vm_gzip_init");
   #endif
   //if(vm_gzip_init(GZIP_FILE_DECOMPRESS, GZIP_SAVE_DYNAMIC_RAM_MODE) != 1)
   //	return -1;
   nRet = vm_gzip_init(GZIP_FILE_DECOMPRESS, GZIP_SAVE_DYNAMIC_RAM_MODE);
   vm_log_fatal("[AM] vm_gzip_init ret = %d", nRet);
   if(nRet != 1)
   	return -1;

   vm_log_fatal("[AM] start malloc gzip file");

   gzip_file_mem.gzip_file = g_VamTask.vam_malloc(sizeof(gzip_file_t));
   if(!gzip_file_mem.gzip_file)
   	return -1;
   
   vm_log_fatal("[AM] start malloc pdes");
   pDes = g_VamTask.vam_malloc(MAX_LEN_FILE_NAME + 1);
   if(!pDes)
   {
      g_VamTask.vam_free(gzip_file_mem.gzip_file);
      return -1;
   }

   vm_log_fatal("[AM] start change chset.");
   vm_ucs2_to_default(pDes, MAX_LEN_FILE_NAME, pDesName);
   vm_log_fatal("[AM] after change chset.");

   #ifdef LOG_AM_DOWNLOAD
   vm_log_fatal("[AM] pDes = %s", pDes);
   #endif
   
   gzip_file_mem.gzip_file->input_filename = pDes;

  nRet = vm_gzip_run(&gzip_file_mem);
  vm_log_fatal("[AM] vm_gzip_run nRet = %d", nRet);
  if(nRet != 1)
  {
       vm_gzip_finalize();
       g_VamTask.vam_free(gzip_file_mem.gzip_file);
	g_VamTask.vam_free(pDes);
      return -1;
  }
/*
   if(vm_gzip_run(&gzip_file_mem) != 1)
   {
      #ifdef LOG_AM_DOWNLOAD
	vm_log_fatal("[AM] vm_gzip_run error.");
    #endif
      g_VamTask.vam_free(gzip_file_mem.gzip_file);
      return -1;
   }
  */
   vm_gzip_finalize();

   g_VamTask.vam_free(gzip_file_mem.gzip_file);
   g_VamTask.vam_free(pDes);

   /*删除.gz文件*/
   vm_file_delete(pDesName);
   #ifdef LOG_AM_DOWNLOAD
	vm_log_fatal("[AM] vm_vam_unpack_gzip done.");
    #endif

   return 0;
	
}
 #endif
static void vm_vam_send_fail_message(void)
{
    g_VamTask.pDownloadingTask->eState = APPDLSTATE_FAIL;
    vm_vam_download_app_fail(g_VamTask.pDownloadingTask, 0);
}
static void vm_vam_download_app_callback(VMINT uid, VMINT mpi, VMINT vip_response_type, 
	                                        const void* vip_response, VMUINT response_size)
{
    	//保存UserID和PhoneID
	VMINT nUserID, nPhoneID, nResult;
	VMUINT nDataSize;
	VMCHAR * pData = NULL;
#ifdef LOG_AM_DOWNLOAD
	vm_log_fatal("[AM] vm_vam_download_app_callback, result = %d", vip_response_type);
#endif

       if(g_VamTask.nConnectTimer >= 0)
       {
#ifdef LOG_AM_DOWNLOAD
          vm_log_fatal("[AM] delete connect timer .");
#endif
	    vm_delete_timer_ex(g_VamTask.nConnectTimer);
	    g_VamTask.nConnectTimer = -1;
	    
	    if(g_VamTask.download_app_cb)
	         g_VamTask.download_app_cb(VAM_DL_OK, vm_vam_get_download_percent(g_VamTask.pDownloadingTask ));
	    
       }
	nUserID = uid;
	nPhoneID = mpi;
	nResult = vip_response_type;
	pData = (VMCHAR *)vip_response;
	nDataSize = response_size;
#ifndef _DEBUG
    	vm_save_mobile_phone_id_record(mpi);
    	vm_save_user_id_record(uid);
#endif

    	if(nResult == RES_RESCONTENT_CMD)
    	{
    		VMINT nSaveRet, nCheckRet;
    		VMCHAR szAppSize[10], szMD5Len[10];
        	VMUINT32 nAppSize, nMD5Len;
		VMINT nOffset = 0;
	    
		//static VMWCHAR pszDigest[65];
		VMWCHAR * pszDigest = NULL;

		#ifdef AM_SUPPORT_GZIP
		VMUINT32 nFilenameLen;
		//VMWCHAR * pFileName = NULL, *pTempFilename = NULL; 
		memset(szAppSize, 0, sizeof(szAppSize));
		memcpy(szAppSize, (VMCHAR*)pData, VAM_INT_SIZE);
		vm_vam_int_byte_switch(szAppSize, &nFilenameLen, NULL);
		nOffset += VAM_INT_SIZE;
		#ifdef LOG_AM_DOWNLOAD
		vm_log_fatal("[AM] nFilenameLen = %d", nFilenameLen);
		#endif
/*
		pFileName = g_VamTask.vam_malloc(nFilenameLen * 2 + 1);
		if(!pFileName)
		{
		       vm_vam_send_fail_message();
			return;
		}
		memset(pFileName, 0, nFilenameLen * 2 + 1);
		pTempFilename = g_VamTask.vam_malloc(nFilenameLen * 2 + 1);
		if(!pTempFilename)
		{
		   g_VamTask.vam_free(pFileName);
		   vm_vam_send_fail_message();
		   return;
		}
		memset(pTempFilename, 0, nFilenameLen * 2 + 1);
		memcpy(pFileName, pData + nOffset, nFilenameLen * 2);
*/
		//memset(g_VamTask.pDownloadingTask->szFilename, 0, sizeof(g_VamTask.pDownloadingTask->szFilename));
//		vm_vam_string_byte_switch(pTempFilename, pFileName);
//		vm_log_fatal("[AM] sizeof(pTempFilename = %d)", vm_wstrlen(pTempFilename));
		//memcpy(g_VamTask.pDownloadingTask->szFilename, pTempFilename, (nFilenameLen - 3) * 2);//remove .gz
//		g_VamTask.vam_free(pFileName);
//		g_VamTask.vam_free(pTempFilename);
		nOffset += (nFilenameLen * 2);

		#ifdef LOG_AM_DOWNLOAD
		{
		   static VMCHAR szLog[80];
		   memset(szLog, 0, sizeof(szLog));
		   vm_chset_convert(VM_CHSET_UCS2, VM_CHSET_ASCII, (VMSTR)g_VamTask.pDownloadingTask->szFilename, szLog, sizeof(szLog));
		   vm_log_fatal("[AM] filename = %s", szLog);
		}
		#endif
		#endif//AM_SUPPORT_GZIP

		pszDigest = g_VamTask.vam_malloc(65 * 2);
		if(!pszDigest)
		{
		    vm_vam_send_fail_message();
		    return;
		}
		memset(pszDigest, 0, 65 * 2);
	
		//读取应用大小
		memset(szAppSize, 0, sizeof(szAppSize));
		/*Modified by rencai.xiao 2010/07/22*/
		memcpy(szAppSize, (VMCHAR*)pData + nOffset, VAM_INT_SIZE);
		nOffset += VAM_INT_SIZE;
		//交换字节顺序
		vm_vam_int_byte_switch(szAppSize, &nAppSize, NULL);
#ifdef LOG_AM_DOWNLOAD
		vm_log_fatal("[AM] App size = %d", nAppSize);
#endif
	

		//读取MD5摘要长度
		memset(szMD5Len, 0, sizeof(szMD5Len));
              /*modified by rencai.xiao 2010/07/22*/
              memcpy(szMD5Len, (VMCHAR*)(pData + nOffset), VAM_INT_SIZE);
              nOffset += VAM_INT_SIZE;
		//memcpy(szMD5Len, (VMCHAR*)(pData + VAM_INT_SIZE), VAM_INT_SIZE);
		vm_vam_int_byte_switch(szMD5Len, &nMD5Len, NULL);

		//memset(pszDigest, 0, sizeof(pszDigest));
		/*modified by rencai.xiao 2010/07/22*/
		memcpy(pszDigest, (VMCHAR*)(pData + nOffset), nMD5Len * 2);
		nOffset += (nMD5Len * 2);
		//memcpy(pszDigest, (VMCHAR*)(pData + VAM_INT_SIZE * 2), nMD5Len * 2);

		//保存应用大小
		g_VamTask.pDownloadingTask->nFilesize = (VMINT)nAppSize;

		//检测MD5摘要
		if(vm_vam_check_temp_file(g_VamTask.pDownloadingTask, pszDigest) == VAM_DL_ERR)
		{
			//static VMWCHAR pTempFile[MAX_LEN_FILE_NAME  + 1];
		   	//检测未通过
		   	VMWCHAR * pTempFile = NULL; 

			pTempFile = g_VamTask.vam_malloc(MAX_LEN_FILE_NAME * 2 + 1);
			if(!pTempFile)
			{
			       if(pszDigest)
			       {
			         g_VamTask.vam_free(pszDigest);
				  pszDigest = NULL;
			       }
				vm_vam_send_fail_message();
				return;
			}
			memset(pTempFile, 0, MAX_LEN_FILE_NAME * 2 + 1);
		   	
			//memset(pTempFile, 0, sizeof(pTempFile));
			//memset(g_VamTask.szwFileName, 0, sizeof(g_VamTask.szwFileName));
#ifdef LOG_AM_DOWNLOAD
			vm_log_fatal("[AM] check temp file error.");
#endif
		   	//将临时文件删除
		   	if(vm_vam_get_temp_filename(pTempFile, g_VamTask.pDownloadingTask->szFilename, (VMINT8)g_VamTask.pDownloadingTask->nDriver, FALSE) == VAM_DL_ERR)
		   	       g_VamTask.pDownloadingTask->eState = APPDLSTATE_FAIL;
			else
			{
				 VMINT nDelRet;
				 //static VMCHAR szTempFilename[80];

                             //memset(szTempFilename, 0, sizeof(szTempFilename));
				 //vm_ucs2_to_default(szTempFilename, sizeof(szTempFilename), g_VamTask.szwFileName/*pTempFile*/);
				 //vm_log_debug("get temp filename done., tempfilename = %s", szTempFilename);
				 g_VamTask.pDownloadingTask->eState = APPDLSTATE_WAIT;
				 if(g_VamTask.pDownloadingTask->nFilehandle > 0)
				 {
				    vm_file_close(g_VamTask.pDownloadingTask->nFilehandle);
				    g_VamTask.pDownloadingTask->nFilehandle = -1;
				 }
				 nDelRet = vm_file_delete(pTempFile);
				 vm_log_debug("nDelRet = %d", nDelRet);
				 if(nDelRet != 0)
				 	 g_VamTask.pDownloadingTask->eState = APPDLSTATE_FAIL;
				 else
				 	g_VamTask.pDownloadingTask->eState = APPDLSTATE_WAIT;
			}

		   	//下载失败
			
		   	vm_vam_download_app_fail(g_VamTask.pDownloadingTask, 0);

			g_VamTask.vam_free(pTempFile);
			pTempFile = NULL;

			 if(pszDigest)
			       {
			         g_VamTask.vam_free(pszDigest);
				  pszDigest = NULL;
			       }
		   	return;
		}

#ifdef LOG_AM_DOWNLOAD
              vm_log_fatal("g_VamTask.pDownloadingTask = %d", g_VamTask.pDownloadingTask->nFilesize);
              vm_log_fatal("get temp size = %d, nStartPos = %d", vm_vam_check_temp_size(g_VamTask.pDownloadingTask), g_VamTask.nStartPos);
#endif
		if(vm_vam_check_temp_size(g_VamTask.pDownloadingTask) != g_VamTask.nStartPos)
		{
#ifdef LOG_AM_DOWNLOAD
		     vm_log_fatal("[AM] tvm_vam_check_temp_size error.");
#endif
		     vm_vam_update_task_percent(g_VamTask.pDownloadingTask);
                    if(pszDigest)
			       {
			         g_VamTask.vam_free(pszDigest);
				  pszDigest = NULL;
			       }
			vm_vam_send_fail_message();
		     return ;
		}


		nCheckRet = vm_vam_check_temp_file_size(g_VamTask.pDownloadingTask);
#ifdef LOG_AM_DOWNLOAD
          vm_log_fatal("[AM] nCheckRet = %d", nCheckRet);
#endif
	      if(nCheckRet == VAM_DL_OK)
	     {
	        //modified by rencai.xiao 10/01/18
	     if(g_VamTask.download_app_cb)
		g_VamTask.download_app_cb(VAM_DL_OK, 0);
	        vm_vam_download_finish(g_VamTask.pDownloadingTask);

		if(pszDigest)
			       {
			         g_VamTask.vam_free(pszDigest);
				  pszDigest = NULL;
			       }
	       return ;
	     }
	     else if(nCheckRet == VAM_DL_IO_ERROR)
	    {
		g_VamTask.pDownloadingTask->eState = APPDLSTATE_FAIL;
		vm_vam_download_app_fail(g_VamTask.pDownloadingTask, -1);
		if(pszDigest)
			       {
			         g_VamTask.vam_free(pszDigest);
				  pszDigest = NULL;
			       }
		return ;
	    }

		

		//TODO:判断空间是否足够
//		if(g_VamTask.bFirstBlock)
		{
			//下载的是第一块
#ifdef LOG_AM_DOWNLOAD
			vm_log_fatal("[AM] get free space = %d", vm_vam_get_free_space((VMINT8)g_VamTask.pDownloadingTask->nDriver) );
			vm_log_fatal("[AM] get task size = %d", vm_vam_get_task_size(g_VamTask.pDownloadingTask, (VMINT)nAppSize));
#endif
			if(vm_vam_get_free_space((VMINT8)g_VamTask.pDownloadingTask->nDriver) < (VMUINT)vm_vam_get_task_size(g_VamTask.pDownloadingTask, (VMINT)nAppSize))
			{
				//空间不足
				VMINT8 nTempDriver;
#ifdef LOG_AM_DOWNLOAD
				vm_log_fatal("[AM] no enough free space flag 1");
#endif
				if(g_VamTask.pDownloadingTask->nDriver == vm_get_removable_driver())
					nTempDriver = vm_get_system_driver();
				else
					nTempDriver = vm_get_removable_driver();
#ifdef LOG_AM_DOWNLOAD
				vm_log_fatal("[AM] temp free space = %d", vm_vam_get_free_space(nTempDriver));
#endif
				if(vm_vam_get_free_space(nTempDriver) < (VMUINT)vm_vam_get_task_size(g_VamTask.pDownloadingTask, (VMINT)nAppSize))
				{
					//空间不足
#ifdef LOG_AM_DOWNLOAD
					vm_log_fatal("[AM] no enough free space flag 2");
#endif
                                     //rencai.xiao 2010/03/18
		                     g_VamTask.bDlApp = FALSE;
                                   g_VamTask.nIsSave = TRUE;
					vm_vam_release_task_list();
					if(g_VamTask.download_app_cb)
				          g_VamTask.download_app_cb(VAM_DL_SPACE_FULL, 0);

					if(pszDigest)
			       {
			         g_VamTask.vam_free(pszDigest);
				  pszDigest = NULL;
			       }
					return ;
				}
				else
				{
				   // static VMWCHAR szwFileName[MAX_LEN_FILE_NAME  + 1];
				    //static VMWCHAR szwNewFileName[MAX_LEN_FILE_NAME  + 1];

					   VMWCHAR * szwFileName = NULL, * szwNewFileName = NULL;

					   szwFileName = g_VamTask.vam_malloc(MAX_LEN_FILE_NAME * 2 + 1);
					   if(!szwFileName)
					   	{
					   	  if(pszDigest)
			       {
			         g_VamTask.vam_free(pszDigest);
				  pszDigest = NULL;
			       }
						vm_vam_send_fail_message();
					   	return;
					   	}
					   memset(szwFileName, 0, MAX_LEN_FILE_NAME * 2 + 1);

					   szwNewFileName = g_VamTask.vam_malloc(MAX_LEN_FILE_NAME * 2 + 1);
					   if(!szwNewFileName)
					   {
					       g_VamTask.vam_free(szwFileName);
						szwFileName = NULL;
						if(pszDigest)
			       {
			         g_VamTask.vam_free(pszDigest);
				  pszDigest = NULL;
			       }
						vm_vam_send_fail_message();
					   	return;
					   }
					   memset(szwNewFileName, 0, MAX_LEN_FILE_NAME * 2 + 1);
					
					  //memset(szwFileName, 0, sizeof(szwFileName));
					  //memset(szwNewFileName, 0, sizeof(szwNewFileName));
					  //memset(g_VamTask.szwFileName, 0, sizeof(g_VamTask.szwFileName));
					  if(vm_vam_get_temp_filename(szwFileName, g_VamTask.pDownloadingTask->szFilename, 
						(VMINT8)g_VamTask.pDownloadingTask->nDriver, FALSE) == VAM_DL_ERR || 
						vm_vam_get_temp_filename(szwNewFileName, g_VamTask.pDownloadingTask->szFilename, 
						nTempDriver, FALSE) == VAM_DL_ERR)
					{
#ifdef LOG_AM_DOWNLOAD
					       vm_log_fatal("[AM] no enough free space flag 3");
#endif
                                            //rencai.xiao 2010/03/18
		                            g_VamTask.bDlApp = FALSE;
                                          g_VamTask.nIsSave = TRUE;
						vm_vam_release_task_list();
						g_VamTask.vam_free(szwFileName);
						szwFileName = NULL;
						g_VamTask.vam_free(szwNewFileName);
						szwNewFileName = NULL;
						if(g_VamTask.download_app_cb)
							g_VamTask.download_app_cb(VAM_DL_SPACE_FULL, 0);
						if(pszDigest)
			       {
			         g_VamTask.vam_free(pszDigest);
				  pszDigest = NULL;
			       }
					    return ;
					}
		                   //added by rencai.xiao 10/01/25
		                   if(g_VamTask.pDownloadingTask->nFilehandle > 0)
		                   {
		                       vm_file_close(g_VamTask.pDownloadingTask->nFilehandle);
					  g_VamTask.pDownloadingTask->nFilehandle = -1;
		                   }
                               if(dm_file_copy(szwFileName, szwNewFileName) == VAM_DL_ERR)
				   {
#ifdef LOG_AM_DOWNLOAD
				          vm_log_fatal("[AM] no enough free space flag 4");
#endif
                                        //rencai.xiao 2010/03/18
		                        g_VamTask.bDlApp = FALSE;
                                      g_VamTask.nIsSave = TRUE;
					   vm_vam_release_task_list();
					   g_VamTask.vam_free(szwFileName);
					   szwFileName = NULL;
					   g_VamTask.vam_free(szwNewFileName);
					   szwNewFileName = NULL;
					   if(g_VamTask.download_app_cb)
						   g_VamTask.download_app_cb(VAM_DL_SPACE_FULL, 0);
					   if(pszDigest)
			       {
			         g_VamTask.vam_free(pszDigest);
				  pszDigest = NULL;
			       }
					    return ;
				   }
				  g_VamTask.pDownloadingTask->nDriver = nTempDriver;

				  g_VamTask.vam_free(szwFileName);
				  szwFileName = NULL;
				  g_VamTask.vam_free(szwNewFileName);
				  szwNewFileName = NULL;
				}
			}
		}

		//保存摘要
		vm_wstrcpy(g_VamTask.pDownloadingTask->szVXPDigest, pszDigest);

		g_VamTask.vam_free(pszDigest);
		pszDigest = NULL;


		//保存
		nSaveRet = vm_vam_save_data(g_VamTask.pDownloadingTask, (VMCHAR*)pData + nOffset/*VAM_INT_SIZE * 2 + nMD5Len * 2*/, nDataSize - nOffset/*VAM_INT_SIZE * 2 - nMD5Len * 2*/); 
#ifdef LOG_AM_DOWNLOAD
		vm_log_fatal("[AM] nSaveRet = %d", nSaveRet);
#endif
		if(nSaveRet == VAM_DL_ERR || nSaveRet == VAM_DL_IO_ERROR || nSaveRet == VAM_DL_SPACE_FULL)
		{
			//保存失败
			if(g_VamTask.pDownloadingTask->nFilehandle >= 0)
	        {
		      vm_file_close(g_VamTask.pDownloadingTask->nFilehandle);
		      g_VamTask.pDownloadingTask->nFilehandle = -1;
	         }
			  //rencai.xiao 2010/03/18
		     g_VamTask.bDlApp = FALSE;
			vm_vam_release_task_list();
			g_VamTask.nIsSave = TRUE;
		  	if(g_VamTask.download_app_cb)
				g_VamTask.download_app_cb(nSaveRet, 0);
		  	g_VamTask.pDownloadingTask = NULL;
			vip_cancel_request_handle(VIP_APP_HANDLE);
			//vip_cancel_request_and_finalize();
		  	return;
		}
		else if(nSaveRet == VAM_DL_DONE)
		{
			//应用下载完成,更新本地存储
		  	vm_vam_download_finish(g_VamTask.pDownloadingTask);
		  	return;
		}
		else
		{
			//保存成功，但仍未下载完毕，需要继续发起下载请求
		   	//重新计算下载进度并更新本地存储
		   	vm_vam_update_task_percent(g_VamTask.pDownloadingTask);
		}
	}
	else
	{
    		//根据错误类型回调给调用者
 		error_t * pError = NULL;
 		pError = (error_t *)vip_response;
		g_VamTask.nRetryCount ++;
#ifdef LOG_AM_DOWNLOAD
		vm_log_fatal("[AM] g_VamTask.nRetryCount = %d", g_VamTask.nRetryCount);
#endif
		if(g_VamTask.nRetryCount < VAM_DOWNLOAD_RETRY_MAX_COUNT)
		{
#ifdef LOG_AM_DOWNLOAD
		   vm_log_fatal("[AM] retry download app.");
#endif
		   g_VamTask.pDownloadingTask->eState = APPDLSTATE_WAIT;
		   vm_vam_download_app_fail(g_VamTask.pDownloadingTask, pError->code);
		}
		else
		{
#ifdef LOG_AM_DOWNLOAD
		   vm_log_fatal("[AM] callback download fail.");
#endif
		   g_VamTask.pDownloadingTask->eState = APPDLSTATE_FAIL;
		   vm_vam_download_app_fail(g_VamTask.pDownloadingTask, pError->code);
		}
	}
}

static VMINT vm_vam_get_task_save_path(Vam_Task_t * pTask, VMWCHAR * pFilename)
{
	//static VMCHAR pTempFilePath[MAX_LEN_FILE_NAME + 1], pTempFilename[MAX_LEN_FILE_NAME + 1];

	memset(g_VamTask.szFilePath, 0, sizeof(g_VamTask.szFilePath));
	memset(g_VamTask.szwFilePath, 0, sizeof(g_VamTask.szwFilePath));
	sprintf(g_VamTask.szFilePath, "%c:\\vre\\", pTask->nDriver);
	vm_ascii_to_ucs2(pFilename, sizeof(g_VamTask.szFilePath) * 2, g_VamTask.szFilePath);
	vm_wstrcat(pFilename, pTask->szFilename);

/*
	vm_log_debug("vm_vam_get_task_save_path");
	memset(pTempFilePath, 0, MAX_LEN_FILE_NAME  + 1);
	memset(pTempFilename, 0, MAX_LEN_FILE_NAME  + 1);


	vm_ucs2_to_ascii(pTempFilename, MAX_LEN_FILE_NAME, pTask->szFilename);
	sprintf(pTempFilePath, "%c:\\vre\\", pTask->nDriver);
	strcat(pTempFilePath, pTempFilename);
	
	vm_ascii_to_ucs2(pFilename, MAX_LEN_FILE_NAME * 2, pTempFilePath);
*/
	return VAM_DL_OK;
}

static VMINT vm_vam_get_temp_filename(VMWCHAR * szDesName, VMWCHAR * szSrcName, VMINT8 nDriver, VMINT8 nASFlag)
{
	//VMCHAR * pPos = NULL;
       //static VMCHAR pDesName[MAX_LEN_FILE_NAME  + 1], pSrcName[MAX_LEN_FILE_NAME  + 1], pTempPath[MAX_LEN_FILE_NAME  + 1];
       //static VMWCHAR szwTempFileName[MAX_LEN_FILE_NAME + 1];
       VMWCHAR * szwTempFileName = NULL;

	 VMCHAR szSuffix[8];
	 VMWCHAR szwSuffix[8];

	 if(vm_wstrlen(szSrcName) <= 4)
	   	return VAM_DL_ERR;

	 szwTempFileName = g_VamTask.vam_malloc(MAX_LEN_FILE_NAME * 2 + 1);
	 if(!szwTempFileName)
	 	return VAM_DL_ERR;
	 memset(szwTempFileName, 0, MAX_LEN_FILE_NAME * 2 + 1);

       
	memset(g_VamTask.szFilePath, 0, sizeof(g_VamTask.szFilePath));
	memset(g_VamTask.szwFilePath, 0, sizeof(g_VamTask.szwFilePath));
	sprintf(g_VamTask.szFilePath, "%c:\\vre\\", nDriver);
	vm_ascii_to_ucs2(g_VamTask.szwFilePath, sizeof(g_VamTask.szwFilePath), g_VamTask.szFilePath);
       vm_wstrcat(szDesName, g_VamTask.szwFilePath);
	//memset(szwTempFileName, 0, sizeof(szwTempFileName));
	memcpy(szwTempFileName, szSrcName, (vm_wstrlen(szSrcName) - 4) * 2);
	vm_wstrcat(szDesName, szwTempFileName);

	memset(szSuffix, 0, sizeof(szSuffix));
	memset(szwSuffix, 0, sizeof(szwSuffix));
	sprintf(szSuffix, ".");
	if(nASFlag)
		strcat(szSuffix, VAM_APPSTORE_SUFFIX);
	else
        	strcat(szSuffix, VAM_TASK_TEMP_SUFFIX);//添加上tmp后缀
       vm_ascii_to_ucs2(szwSuffix, sizeof(szwSuffix), szSuffix);
	vm_wstrcat(szDesName, szwSuffix);

	g_VamTask.vam_free(szwTempFileName);
	szwTempFileName = NULL;

	return VAM_DL_OK;
///////////////////////
/*
	memset(pDesName, 0, MAX_LEN_FILE_NAME  + 1);
	memset(pSrcName, 0, MAX_LEN_FILE_NAME  + 1);
	memset(pTempPath, 0, MAX_LEN_FILE_NAME  + 1);
#ifdef LOG_AM_DOWNLOAD
	vm_log_fatal("[AM] vm_vam_get_temp_filename");
#endif
	
	//将传入的宽字符文件名转换成gb2312
	vm_ucs2_to_ascii(pSrcName, MAX_LEN_FILE_NAME , szSrcName);
#ifdef LOG_AM_DOWNLOAD
	vm_log_fatal("[AM] pSrcName = %s", pSrcName);
#endif
	pPos = strchr(pSrcName, '.');
	
	if(pPos != NULL)
	{	
		strncpy(pDesName, pSrcName, pPos - pSrcName);
		
		strcat(pDesName, ".");
		if(nASFlag)
			strcat(pDesName, VAM_APPSTORE_SUFFIX);
		else
        	strcat(pDesName, VAM_TASK_TEMP_SUFFIX);//添加上tmp后缀
		
		//添加上路径
		
		memset(pTempPath, 0, MAX_LEN_FILE_NAME  + 1);
		sprintf(pTempPath, "%c:\\vre\\", nDriver);
		strcat(pTempPath, pDesName);
#ifdef LOG_AM_DOWNLOAD
		vm_log_fatal("[AM] pTempPath = %s", pTempPath);
#endif
		vm_ascii_to_ucs2(szDesName, MAX_LEN_FILE_NAME * 2, pTempPath);
		
		//释放掉为临时变量申请的空间
		
		return VAM_DL_OK;
	}
	else
	{
		
		return VAM_DL_ERR;
	}
*/
}

static VMINT vm_vam_delete_temp_file(Vam_Task_t * pTask)
{
	//static VMWCHAR pTempFilename[MAX_LEN_FILE_NAME + 1];
	VMWCHAR * pTempFilename = NULL;

	pTempFilename = g_VamTask.vam_malloc(MAX_LEN_FILE_NAME * 2 + 1);
	if(!pTempFilename)
		return VAM_DL_ERR;
	memset(pTempFilename, 0, MAX_LEN_FILE_NAME * 2 + 1);
	//memset(g_VamTask.szwFileName, 0, sizeof(g_VamTask.szwFileName));
	
	if(pTask->nFilehandle >= 0)
	{
		vm_file_close(pTask->nFilehandle);
		pTask->nFilehandle = -1;
	}
		
	//memset(pTempFilename, 0, sizeof(pTempFilename));
		
	if(vm_vam_get_temp_filename(pTempFilename, pTask->szFilename, (VMINT8)pTask->nDriver, FALSE) == VAM_DL_ERR)
	{
	       g_VamTask.vam_free(pTempFilename);
		pTempFilename = NULL;
		//SAFE_FREE(pTempFilename);
		return VAM_DL_ERR;
	}
		
	vm_file_delete(pTempFilename);

	g_VamTask.vam_free(pTempFilename);
	pTempFilename = NULL;
	return VAM_DL_OK;
}
static VMINT vm_vam_open_temp_file(Vam_Task_t * pTask)
{
       vm_log_debug("vm_vam_open_temp_file");
	if(pTask->nFilehandle < 0)
	{
		//临时文件句柄未打开，先将临时文件打开
		//static VMWCHAR pTempFilename[MAX_LEN_FILE_NAME  + 1];
		VMINT nFindHandle;
		//struct vm_fileinfo_t fileInfo;
		VMINT nOpenMode;
		VMWCHAR * pTempFilename = NULL;

		pTempFilename = g_VamTask.vam_malloc(MAX_LEN_FILE_NAME * 2 + 1);
		if(!pTempFilename)
			return VAM_DL_ERR;
		memset(pTempFilename, 0, MAX_LEN_FILE_NAME * 2 + 1);
		
		//memset(pTempFilename, 0, sizeof(pTempFilename));
		//memset(g_VamTask.szwFileName, 0, sizeof(g_VamTask.szwFileName));
        if(vm_vam_get_temp_filename(pTempFilename, pTask->szFilename, (VMINT8)pTask->nDriver, FALSE) == VAM_DL_ERR)
		{
		       vm_log_debug("get temp filename error.");
			g_VamTask.vam_free(pTempFilename);
	              pTempFilename = NULL;
			return VAM_DL_ERR;
		}


		if(vm_vam_is_file(pTempFilename))
			     nOpenMode = MODE_APPEND;
		else
		{
			    VMINT nDelRet;
			    vm_log_debug("tmp file is forder.");
			    nDelRet = vm_file_rmdir(pTempFilename);
			    vm_log_debug("nDelRet = %d", nDelRet);
			    nOpenMode = MODE_CREATE_ALWAYS_WRITE;
		}
			
		nFindHandle = vm_find_first(pTempFilename, &fileinfo);
		if(nFindHandle < 0)
			nOpenMode = MODE_CREATE_ALWAYS_WRITE;
		else
		{
			vm_find_close(nFindHandle);
#ifdef LOG_AM_DOWNLOAD
                     vm_log_fatal("[AM] open mode MODE_APPEND.");
#endif
			nOpenMode = MODE_APPEND;
		}

		pTask->nFilehandle = vm_file_open(pTempFilename, nOpenMode, TRUE);
		if(pTask->nFilehandle < 0)
		{
		       vm_log_debug("file open error.");
			g_VamTask.vam_free(pTempFilename);
	              pTempFilename = NULL;
			return VAM_DL_ERR;
		}
        
		g_VamTask.vam_free(pTempFilename);
	       pTempFilename = NULL;
	}

	
	return VAM_DL_OK;
}

static VMINT vm_vam_request_data(Vam_Task_t * pTask)
{
	VMUINT nTempFileSize;
  	VMINT nStartPos = 0, nStopPos = 0;
 	//static VMCHAR swURL[255];
  	//static VMCHAR szVersionID[MAX_LEN_APP_VERSIONID * 2 + 1];
	//static VMCHAR pDigest[VAM_LEN_MD5 * 2 + 1];
	//static VMWCHAR pwDigest[VAM_LEN_MD5 * 2 + 1];
	VMINT nReadRet;
	VMCHAR * swURL = NULL, * pDigest = NULL;
	VMWCHAR * pwDigest = NULL;

	swURL = g_VamTask.vam_malloc(255);
	if(!swURL)
		return VAM_DL_ERR;
	memset(swURL, 0, 255);

	pDigest = g_VamTask.vam_malloc(VAM_LEN_MD5 * 2 + 1);
	if(!pDigest)
	{
	    g_VamTask.vam_free(swURL);
	    return VAM_DL_ERR;
	}
	memset(pDigest, 0, VAM_LEN_MD5 * 2 + 1);

	pwDigest = g_VamTask.vam_malloc(VAM_LEN_MD5 * 4 + 1);
	if(!pwDigest)
	{
	    g_VamTask.vam_free(swURL);
	    g_VamTask.vam_free(pDigest);
	    return VAM_DL_ERR;
	}
	memset(pwDigest, 0, VAM_LEN_MD5 * 4 + 1);
  
 #ifdef LOG_AM_DOWNLOAD
	vm_log_fatal("[AM] vm_vam_request_data.");
 #endif
  	//打开临时文件，没有则创建
	if(vm_vam_open_temp_file(pTask) == VAM_DL_ERR)
	{
#ifdef LOG_AM_DOWNLOAD
	      vm_log_fatal("[AM] open temp file error.");
#endif
		//文件打开失败

              g_VamTask.vam_free(swURL);
              swURL = NULL;
		g_VamTask.vam_free(pDigest);
		pDigest = NULL;
		g_VamTask.vam_free(pwDigest);
		pwDigest = NULL;
		return VAM_DL_IO_ERROR;
	}	

	//获取文件大小
	vm_file_seek(pTask->nFilehandle, 0, BASE_BEGIN);
	if(vm_file_getfilesize(pTask->nFilehandle, &nTempFileSize))
	{
		//获取文件大小失败
#ifdef LOG_AM_DOWNLOAD
		vm_log_fatal("[AM] get filesize error.");
#endif
		vm_file_close(pTask->nFilehandle);
		pTask->nFilehandle = -1;
		pTask->eState = APPDLSTATE_FAIL;

		g_VamTask.vam_free(swURL);
              swURL = NULL;
		g_VamTask.vam_free(pDigest);
		pDigest = NULL;
		g_VamTask.vam_free(pwDigest);
		pwDigest = NULL;

		return VAM_DL_IO_ERROR;
	}
#ifdef LOG_AM_DOWNLOAD
	vm_log_fatal("[AM] filesize = %d, Task SIze = %d", nTempFileSize, pTask->nFilesize);
#endif
	//计算下载块的起始和结束位置
	if(nTempFileSize > 0 && pTask->nFilesize == 0)
	{
		vm_vam_delete_temp_file(pTask);
		nStartPos = 0;
		nStopPos = (VMINT)nStartPos + g_VamTask.nBlockSize ;
	}
	else
	{
	if(nTempFileSize == 0)
		nStartPos = 0;
	else if(pTask->nFilesize > 0 && (VMINT)nTempFileSize < pTask->nFilesize)
		nStartPos = (VMINT)nTempFileSize;
	else if(pTask->nFilesize != 0)
	{

		//rencai.xiao 2010/03/19
		if(nTempFileSize > pTask->nFilesize)
		{
		    vm_vam_delete_temp_file(pTask);
		    nStartPos = 0;
		    nTempFileSize = 0;
		    nStopPos = (VMINT)nStartPos + g_VamTask.nBlockSize ;
		}

	}
	if((VMINT)nTempFileSize <= pTask->nFilesize && (VMINT)nTempFileSize >= 0)
	{	
		if(((VMINT)nTempFileSize + g_VamTask.nBlockSize <= pTask->nFilesize) || pTask->nFilesize == 0)
			nStopPos = (VMINT)nTempFileSize + g_VamTask.nBlockSize ;
		else
			nStopPos = (VMINT)nTempFileSize + (pTask->nFilesize - (VMINT)nTempFileSize);
	}
	else
	{
	    //rencai.xiao 2010/03/19
		if(nTempFileSize > pTask->nFilesize)
		{
		    vm_vam_delete_temp_file(pTask);
		    nStartPos = 0;
		    nTempFileSize = 0;
		    nStopPos = (VMINT)nStartPos + g_VamTask.nBlockSize ;
		}
	 }
	}

	//读取MD5摘要
	if(vm_wstrlen(pTask->szVXPDigest) > 0 && nTempFileSize > 0)
	{
		vm_log_debug("get digest.");
	
       	//memset(pDigest, 0, sizeof(pDigest)/*VAM_LEN_MD5 * 4 + 1*/);
	   	//memset(pwDigest, 0, sizeof(pwDigest)/*VAM_LEN_MD5 * 2 + 1*/);

	   	//交换MD5字串的字节顺序
	   	vm_vam_string_byte_switch(pwDigest, pTask->szVXPDigest);
	   	vm_ucs2_to_ascii(pDigest, VAM_LEN_MD5 * 2/*VAM_LEN_MD5 * 4*/, pwDigest);
	}
	
	//memset(szVersionID, 0, sizeof(szVersionID));
	//vm_ucs2_to_ascii(szVersionID, MAX_LEN_APP_VERSIONID * 2, pTask->szVersionID);
	//发起网络下载
	//调用VIP接口注册下载回调
	  //memset(swURL, 0, sizeof(swURL));
      if(vm_wstrlen(pTask->szVXPDigest) > 0 && nTempFileSize > 0)
	  {
	         if(pTask->nAppid == 0)
			 	sprintf(swURL, "%s?appid=%s&range=%d-%d&md5=%s", VIP_VRE_EXECUTABLE_FILE_URL, SM_CHARGE_ID, nStartPos, nStopPos, pDigest);
	         else
	         {
			  if(g_VamTask.bAppStore)
				  sprintf(swURL, "%s?appid=%s&range=%d-%d&md5=%s", VIP_VRE_EXECUTABLE_FILE_URL, APPSTORE_ID, nStartPos, nStopPos, pDigest);
			  else
		              sprintf(swURL, "%s?appid=%d&range=%d-%d&md5=%s", VIP_VRE_EXECUTABLE_FILE_URL, (VMINT)pTask->nAppid, nStartPos, nStopPos, pDigest);
	         }
	  }
	  else
	  {
	         if(pTask->nAppid == 0)
			 sprintf(swURL, "%s?appid=%s&range=%d-%d&md5=0", VIP_VRE_EXECUTABLE_FILE_URL, SM_CHARGE_ID, nStartPos, nStopPos);
		  else
		  {
		         vm_log_fatal("[AM] appid not zero.");
			  if(g_VamTask.bAppStore)
				  sprintf(swURL, "%s?appid=%s&range=%d-%d&md5=0", VIP_VRE_EXECUTABLE_FILE_URL, APPSTORE_ID, nStartPos, nStopPos);
			  else
			         sprintf(swURL, "%s?appid=%d&range=%d-%d&md5=0", VIP_VRE_EXECUTABLE_FILE_URL, (VMINT)pTask->nAppid, nStartPos, nStopPos);
		  }
	  }

	  /*如果支持压缩，添加压缩请求.added by rencai.xiao 2010/07/22*/
	  #ifdef AM_SUPPORT_GZIP
	  {
	      VMCHAR szGzip[25];

	       memset(szGzip, 0, sizeof(szGzip));
		sprintf(szGzip, "&filename=1&gzip=1");
		strcat(swURL, szGzip);
	  }
	  #endif
#ifdef LOG_AM_DOWNLOAD
	  vm_log_fatal("[AM] swURL = %s", swURL);
#endif
	  g_VamTask.nStartPos = nStartPos;

//	  SAFE_FREE(pwDigest);
	//注册回调
	if(register_vip_callback_for_app(vm_vam_download_app_callback))
	{
		vm_file_close(pTask->nFilehandle);

#ifdef LOG_AM_DOWNLOAD
		vm_log_fatal("regiester cb error.");
#endif
             g_VamTask.vam_free(swURL);
		swURL = NULL;
		g_VamTask.vam_free(pDigest);
		pDigest = NULL;
		g_VamTask.vam_free(pwDigest);
		pwDigest = NULL;
		return VAM_DL_ERR;
	}

	nReadRet = vip_read_resource(swURL);
#ifdef LOG_AM_DOWNLOAD
	vm_log_fatal("[AM] nReadRet = %d", nReadRet);
#endif
	if(nReadRet != 0)
	{
#ifdef LOG_AM_DOWNLOAD
		vm_log_fatal("[AM] vip_read_resource error.");
#endif
		//联网失败
		vm_file_close(pTask->nFilehandle);

              g_VamTask.vam_free(swURL);
		swURL = NULL;
		g_VamTask.vam_free(pDigest);
		pDigest = NULL;
		g_VamTask.vam_free(pwDigest);
		pwDigest = NULL;

		return VAM_DL_ERR;
	}
    else
	{
		if(nStartPos == 0)
			g_VamTask.bFirstBlock = TRUE;
		else
			g_VamTask.bFirstBlock = FALSE;

		g_VamTask.pDownloadingTask = pTask;
#ifdef LOG_AM_DOWNLOAD
             vm_log_fatal("[AM] vip_read_resource done.");
#endif

              g_VamTask.vam_free(swURL);
		swURL = NULL;
		g_VamTask.vam_free(pDigest);
		pDigest = NULL;
		g_VamTask.vam_free(pwDigest);
		pwDigest = NULL;
              g_VamTask.nConnectTimer = vm_create_timer_ex(1, vm_vam_connect_done_proc);
		//通知VAM正在联网下载
		
	}

	return VAM_DL_OK;
}

static void vm_vam_connect_done_proc(VMINT nTimerID)
{
#ifdef LOG_AM_DOWNLOAD
    vm_log_fatal("[AM] vm_vam_connect_done_proc");
#endif
    if(g_VamTask.nConnectTimer >= 0)
    {
	    vm_delete_timer_ex(g_VamTask.nConnectTimer);
	    g_VamTask.nConnectTimer = -1;
    }

    if(g_VamTask.download_app_cb)
	 g_VamTask.download_app_cb(VAM_DL_OK, vm_vam_get_download_percent(g_VamTask.pDownloadingTask ));
}

static VMINT vm_vam_add_task_to_end(Vam_Task_t * pTask)
{
	Vam_Task_t * pTempTask = NULL, * pBefoTask = NULL;
	pTempTask = pTaskRoot;
	if(!pTaskRoot)
	{
		pTaskRoot = pTask;
		pTask->next = NULL;
		return VAM_DL_OK;
	}

	while(pTempTask)
	{
		if(pTempTask->nASFlag == pTask->nASFlag && pTempTask->nAppid == pTask->nAppid)
			return VAM_DL_OK;
		pBefoTask = pTempTask;
		pTempTask = pTempTask->next;
	}

	pBefoTask->next = pTask;
	pTask->next = NULL;
	return VAM_DL_OK;
}

static VMINT vm_vam_parse_task_list(VMCHAR * pTaskBuf)
{
       //rencai.xiao 2010/03/17 初始化nCount
	VMINT nCount = 0, nTaskIndex = 0, i;
	VMINT nStrLen;
	VMINT nRemoveDriver;

	#ifdef LOG_AM_DOWNLOAD
	vm_log_fatal("[AM] vm_vam_parse_task_list");
	#endif
	nRemoveDriver = vm_get_removable_driver();

	//任务个数
	memcpy(&nCount,pTaskBuf, VAM_INT_SIZE);
	nTaskIndex += VAM_INT_SIZE;

	#ifdef LOG_AM_DOWNLOAD
	vm_log_fatal("[AM] nCount = %d", nCount);
	#endif
	for(i = 0 ; i < nCount ; i ++)
	{
       Vam_Task_t * pTask = NULL;

	   pTask = /*vm_malloc*/g_VamTask.vam_malloc(sizeof(Vam_Task_t));
	   if(!pTask)
		   return VAM_DL_ERR;
	   #ifdef LOG_AM_DOWNLOAD
	   vm_log_fatal("[AM] pTask = %p", pTask);
	   #endif
	   memset(pTask, 0, sizeof(Vam_Task_t));

	   //任务状态
	   memcpy(&pTask->eState, pTaskBuf + nTaskIndex, VAM_INT_SIZE);
	   nTaskIndex += VAM_INT_SIZE;
	   //任务进度
	   memcpy(&pTask->nPercent, pTaskBuf + nTaskIndex, VAM_INT_SIZE);
	   nTaskIndex += VAM_INT_SIZE;
	   //临时文件句柄
	   memcpy(&pTask->nFilehandle, pTaskBuf + nTaskIndex, VAM_INT_SIZE);
	   nTaskIndex += VAM_INT_SIZE;
	   pTask->nFilehandle = -1;
	   //临时文件存放位置
	   memcpy(&pTask->nDriver, pTaskBuf + nTaskIndex, VAM_INT_SIZE);
	   nTaskIndex += VAM_INT_SIZE;
	   if(pTask->nDriver != vm_get_system_driver() && nRemoveDriver < 0)
	   	   pTask->nDriver = vm_get_system_driver();
	   //重试次数
	   memcpy(&pTask->nRetryCount, pTaskBuf + nTaskIndex, VAM_INT_SIZE);
	   nTaskIndex += VAM_INT_SIZE;
	   //文件大小
	   memcpy(&pTask->nFilesize, pTaskBuf + nTaskIndex, VAM_INT_SIZE);
	   nTaskIndex += VAM_INT_SIZE;
	   //标识
	   memcpy(&pTask->nASFlag, pTaskBuf + nTaskIndex, VAM_INT_SIZE);
	   nTaskIndex += VAM_INT_SIZE;
	   //AppID
	   memcpy(&pTask->nAppid, pTaskBuf + nTaskIndex, VAM_INT_SIZE);
	   nTaskIndex += VAM_INT_SIZE;
	   
	   //文件名长度
	   memcpy(&nStrLen, pTaskBuf + nTaskIndex, VAM_INT_SIZE);
	   nTaskIndex += VAM_INT_SIZE;
	   //文件名
	   memcpy(pTask->szFilename, pTaskBuf + nTaskIndex, nStrLen);
	   nTaskIndex += (nStrLen);
	   
	   //版本号ID长度
	   memcpy(&nStrLen, pTaskBuf + nTaskIndex, VAM_INT_SIZE);
	   nTaskIndex += VAM_INT_SIZE;
	   //版本号ID
	   memcpy(pTask->szVersionID, pTaskBuf + nTaskIndex, nStrLen);
	   nTaskIndex += (nStrLen);
	   
	   //任务名称长度
	   memcpy(&nStrLen, pTaskBuf + nTaskIndex, VAM_INT_SIZE);
	   nTaskIndex += VAM_INT_SIZE;
	   //任务名称
	   memcpy(pTask->szName, pTaskBuf + nTaskIndex, nStrLen);
	   nTaskIndex += (nStrLen);
	   
	   //摘要长度
	   memcpy(&nStrLen, pTaskBuf + nTaskIndex, VAM_INT_SIZE);
	   nTaskIndex += VAM_INT_SIZE;
	   //摘要
	   memcpy(pTask->szVXPDigest, pTaskBuf + nTaskIndex, nStrLen);
	   nTaskIndex += (nStrLen);

	   //时间
	   memcpy(&nStrLen, pTaskBuf + nTaskIndex, VAM_INT_SIZE);
	   nTaskIndex += VAM_INT_SIZE;
	   memcpy(pTask->szTime, pTaskBuf + nTaskIndex, nStrLen);
	   nTaskIndex += (nStrLen);

	   //添加到链表
		if(vm_vam_add_task_to_end(pTask) == VAM_DL_ERR)
		{
			g_VamTask.vam_free(pTask);
			pTask = NULL;
			//SAFE_FREE(pTask);
			return VAM_DL_ERR;
		}
	}
	#ifdef LOG_AM_DOWNLOAD
	vm_log_fatal("[AM] parse end.");
	#endif
	return VAM_DL_OK;
}

static VMINT vm_vam_check_task_file(void)
{
	//static VMCHAR szDmPath[80];
	//static VMWCHAR szwDmPath[80];
	VMINT nFileHandle/*, nDriver*/, nFindHandle;
	VMINT nDriver;
	VMUINT unRead;
	//struct vm_fileinfo_t fileInfo;

	VMUINT nFileSize;
	VMCHAR * pTaskData = NULL;
	md5_state_t md5State_temp;
	md5_byte_t md5Digest_temp[16], md5Digest_temp1[17], md5Digest_temp2[17]; 

#ifdef LOG_AM_DOWNLOAD
       vm_log_fatal("[AM] vm_vam_check_task_file");
#endif

	nDriver = vm_get_removeable_driver();
	if(nDriver < 0)
		nDriver = vm_get_system_driver();

	//初始化MD5

	//memset(szDmPath, 0, sizeof(szDmPath));
	//memset(szwDmPath, 0, sizeof(szwDmPath));
	memset(g_VamTask.szFilePath, 0, sizeof(g_VamTask.szFilePath));
	memset(g_VamTask.szwFilePath, 0, sizeof(g_VamTask.szwFilePath));
	//sprintf(szDmPath, "%c:\\vre\\%s", nDriver, VAM_TASK_FILENAME);
	//vm_ascii_to_ucs2(szwDmPath, sizeof(szwDmPath), szDmPath);
	sprintf(g_VamTask.szFilePath, "%c:\\vre\\%s", nDriver, VAM_TASK_FILENAME);
	vm_ascii_to_ucs2(g_VamTask.szwFilePath, sizeof(g_VamTask.szwFilePath), g_VamTask.szFilePath);
	nFindHandle = vm_find_first(g_VamTask.szwFilePath/*szwDmPath*/, &fileinfo);
	if(nFindHandle < 0)
		return VAM_DL_OK;
	vm_find_close(nFindHandle);

	if(!vm_vam_is_file(g_VamTask.szwFilePath/*szwDmPath*/))
	{
	   vm_file_delete(g_VamTask.szwFilePath/*szwDmPath*/);
	   return VAM_DL_OK;
	}
	if((nFileHandle = vm_file_open(g_VamTask.szwFilePath/*szwDmPath*/, MODE_READ, TRUE)) < 0)
		return VAM_DL_IO_ERROR;

	////////////////
	vm_file_getfilesize(nFileHandle, &nFileSize);
	#ifdef LOG_AM_DOWNLOAD
	  vm_log_fatal("[AM]  nFileSize = %d", nFileSize);
	#endif
	if(nFileSize == 0 || nFileSize > 45 * 1024)
	{
	#ifdef LOG_AM_DOWNLOAD
	vm_log_fatal("[AM] delete tmp file.");
	#endif
		vm_file_close(nFileHandle);
		vm_file_delete(g_VamTask.szwFilePath/*szwDmPath*/);
		return VAM_DL_OK;
	}
	pTaskData = g_VamTask.vam_malloc(nFileSize + 1);
	if(!pTaskData)
	{
		vm_file_close(nFileHandle);
		return VAM_DL_ERR;
	}
	memset(pTaskData, 0, nFileSize + 1);
	if(vm_file_read(nFileHandle, pTaskData, nFileSize , &unRead) != (VMINT)nFileSize)
	{
		g_VamTask.vam_free(pTaskData);
		pTaskData = NULL;
		vm_file_close(nFileHandle);
		return VAM_DL_IO_ERROR;
	}

	if(nFileSize < 20)
	{
		g_VamTask.vam_free(pTaskData);
		pTaskData = NULL;
		vm_file_close(nFileHandle);
		if(vm_file_delete(g_VamTask.szwFilePath/*szwDmPath*/) != 0)
			return VAM_DL_ERR;
		nFileHandle = vm_file_open(g_VamTask.szwFilePath/*szwDmPath*/, MODE_CREATE_ALWAYS_WRITE, TRUE);
		if(nFileHandle < 0)
			return VAM_DL_ERR;
		vm_file_close(nFileHandle);
		return VAM_DL_OK;
	}

	memset(md5Digest_temp, 0, sizeof(md5Digest_temp));
	md5_init(&md5State_temp);
	md5_append(&md5State_temp, (const md5_byte_t *)pTaskData, nFileSize - 20);
	md5_finish(&md5State_temp, md5Digest_temp);
    memset(md5Digest_temp1, 0, sizeof(md5Digest_temp1));
	memcpy(md5Digest_temp1, md5Digest_temp, 16);
	memset(md5Digest_temp2, 0, sizeof(md5Digest_temp2));
	memcpy(md5Digest_temp2, pTaskData + (nFileSize - 16), 16);
	if(strcmp((char*)md5Digest_temp1, (char*)md5Digest_temp2) != 0)
	{
		g_VamTask.vam_free(pTaskData);
		pTaskData = NULL;
		vm_file_close(nFileHandle);
		//校验未通过，将文件删除
		if(vm_file_delete(g_VamTask.szwFilePath/*szwDmPath*/) != 0)
			return VAM_DL_ERR;
		nFileHandle = vm_file_open(g_VamTask.szwFilePath/*szwDmPath*/, MODE_CREATE_ALWAYS_WRITE, TRUE);
		if(nFileHandle < 0)
			return VAM_DL_ERR;
		vm_file_close(nFileHandle);
		return VAM_DL_OK;
	}
	g_VamTask.vam_free(pTaskData);
	pTaskData = NULL;
	vm_file_close(nFileHandle);
	///////////////

	return VAM_DL_OK;
}

static VMINT vm_vam_read_task_list(void)
{
	VMINT nFileHandle, nFindHandle;
	VMINT nDriver;
	//static VMCHAR szFilePath[50];
	//static VMWCHAR szwFilePath[50];
	VMUINT nRead;
	//struct vm_fileinfo_t fileInfo;
	VMINT nTaskLen;
	VMCHAR * pTaskBuf = NULL;
	VMINT nCheckRet;
	VMUINT nFilesize;

  #ifdef LOG_AM_DOWNLOAD
       vm_log_fatal("[AM] vm_vam_read_task_list");
  #endif
	//校验文件是否合法
	nCheckRet = vm_vam_check_task_file();
	if(nCheckRet == VAM_DL_ERR || nCheckRet == VAM_DL_IO_ERROR)
	{
		vm_log_debug("vm_vam_check_task_file error.");
		return nCheckRet;
	}
	
	//memset(szFilePath, 0, sizeof(szFilePath));
	nDriver = vm_get_removable_driver();
	if(nDriver < 0)
		nDriver = vm_get_system_driver();
	
    	//memset(szFilePath, 0, sizeof(szFilePath));
	//sprintf(szFilePath, "%c:\\vre\\%s", nDriver, VAM_TASK_FILENAME);
	//memset(szwFilePath, 0, sizeof(szwFilePath));
	//vm_ascii_to_ucs2(szwFilePath, sizeof(szwFilePath), szFilePath);
	memset(g_VamTask.szFilePath, 0, sizeof(g_VamTask.szFilePath));
	memset(g_VamTask.szwFilePath, 0, sizeof(g_VamTask.szwFilePath));
	sprintf(g_VamTask.szFilePath, "%c:\\vre\\%s", nDriver, VAM_TASK_FILENAME);
	vm_ascii_to_ucs2(g_VamTask.szwFilePath, sizeof(g_VamTask.szwFilePath), g_VamTask.szFilePath);
	nFindHandle = vm_find_first(g_VamTask.szwFilePath/*szwFilePath*/, &fileinfo);
	if(nFindHandle < 0)
	{
		if(!g_VamTask.pHistoryList)
		{
			g_VamTask.pHistoryList = g_VamTask.vam_malloc(VAM_INT_SIZE + 1);
			g_VamTask.nHistoryLen = 0;
			if(!g_VamTask.pHistoryList)
				return VAM_DL_ERR;
			memset(g_VamTask.pHistoryList, 0, VAM_INT_SIZE + 1);
			memcpy(g_VamTask.pHistoryList, &g_VamTask.nHistoryLen, 0);
		}
		return VAM_DL_FILE_NOT_EXIST;
	}
	vm_find_close(nFindHandle);
	nFileHandle = vm_file_open(g_VamTask.szwFilePath/*szwFilePath*/, MODE_READ, TRUE);
	if(nFileHandle < 0)
		return VAM_DL_IO_ERROR;

	vm_file_getfilesize(nFileHandle, &nFilesize);
	if(nFilesize == 0)
	{
       g_VamTask.pHistoryList = g_VamTask.vam_malloc( VAM_INT_SIZE + 1);
	   if(!g_VamTask.pHistoryList)
	   {
		   vm_file_close(nFileHandle);
		   return VAM_DL_ERR;
	   }
	   vm_file_close(nFileHandle);
	   g_VamTask.nHistoryLen = 0;
	   return VAM_DL_OK;
	}

	//读取任务长度
	if(vm_file_read(nFileHandle, &nTaskLen, VAM_INT_SIZE, &nRead) != VAM_INT_SIZE)
	{
		vm_file_close(nFileHandle);
		return VAM_DL_IO_ERROR;
	}

       //rencai.xiao 2010/03/17 申请时增加4个字节
	pTaskBuf = g_VamTask.vam_malloc(nTaskLen + 1 + VAM_INT_SIZE);
	if(!pTaskBuf)
	{
		vm_file_close(nFileHandle);
		return VAM_DL_ERR;
	}
	memset(pTaskBuf, 0, nTaskLen + 1);

	if(vm_file_read(nFileHandle, pTaskBuf, nTaskLen, &nRead) != nTaskLen)
	{
		g_VamTask.vam_free(pTaskBuf);
		pTaskBuf = NULL;
	
		vm_file_close(nFileHandle);
		return VAM_DL_IO_ERROR;
	}

	#ifdef LOG_AM_DOWNLOAD
	vm_log_fatal("[AM] nTaskLen = %d", nTaskLen);
	#endif
       //rencai.xiao 2010/03/17  长度为0，不再走解析流程
       if(nTaskLen > 0)
       {
	if(vm_vam_parse_task_list(pTaskBuf) == VAM_DL_ERR)
	{
		
		g_VamTask.vam_free(pTaskBuf);

		g_VamTask.vam_free(g_VamTask.pHistoryList);
		g_VamTask.pHistoryList = NULL;
		pTaskBuf = NULL;
		return VAM_DL_ERR;
		}
	}

       g_VamTask.vam_free(pTaskBuf);
	pTaskBuf = NULL;
	
	//读取下载历史
	if(!g_VamTask.pHistoryList)
	{
		VMINT nHistyoryLen;
		vm_file_seek(nFileHandle, nTaskLen + VAM_INT_SIZE, BASE_BEGIN);
		if(vm_file_read(nFileHandle, &nHistyoryLen, VAM_INT_SIZE, &nRead) != VAM_INT_SIZE)
		{
			vm_file_close(nFileHandle);
			
			return VAM_DL_IO_ERROR;
		}
            g_VamTask.nHistoryLen = nHistyoryLen;
		if(g_VamTask.nHistoryLen > 0)
		{
			g_VamTask.pHistoryList = g_VamTask.vam_malloc(g_VamTask.nHistoryLen + VAM_INT_SIZE + 1);
			if(!g_VamTask.pHistoryList)
			{
				vm_file_close(nFileHandle);
				
				return VAM_DL_ERR;
			}
			memset(g_VamTask.pHistoryList, 0, g_VamTask.nHistoryLen + VAM_INT_SIZE + 1);
			if(vm_file_read(nFileHandle, g_VamTask.pHistoryList + VAM_INT_SIZE, g_VamTask.nHistoryLen, &nRead) != g_VamTask.nHistoryLen)
			{
				vm_file_close(nFileHandle);
				
				g_VamTask.vam_free(g_VamTask.pHistoryList);
				g_VamTask.pHistoryList = NULL;
				return VAM_DL_IO_ERROR;
			}

			memcpy(g_VamTask.pHistoryList, &g_VamTask.nHistoryLen, VAM_INT_SIZE);
		}
		else if(g_VamTask.nHistoryLen == 0)
		{
           g_VamTask.pHistoryList = g_VamTask.vam_malloc(g_VamTask.nHistoryLen + VAM_INT_SIZE + 1);
		   vm_log_debug("[VAM] vam_malloc g_VamTask.pHistoryList = %p", g_VamTask.pHistoryList);
		   if(!g_VamTask.pHistoryList)
		   {
			   vm_file_close(nFileHandle);
			   return VAM_DL_ERR;
		   }
		   memset(g_VamTask.pHistoryList, 0, g_VamTask.nHistoryLen + VAM_INT_SIZE + 1);
		   memcpy(g_VamTask.pHistoryList, &g_VamTask.nHistoryLen, VAM_INT_SIZE);
		}
	}

	vm_file_close(nFileHandle);

	
	
	return VAM_DL_OK;
}

void vm_vam_cancel_download(void)
{
#ifdef LOG_AM_DOWNLOAD
       vm_log_fatal("[AM] vm_vam_cancel_download");
#endif
	if(g_VamTask.pDownloadingTask)
	{
		if(g_VamTask.pDownloadingTask->nFilehandle > 0)
		{
			vm_file_close(g_VamTask.pDownloadingTask->nFilehandle);
			g_VamTask.pDownloadingTask->nFilehandle = -1;
		}
		g_VamTask.pDownloadingTask = NULL;	
		
		if(g_VamTask.nTimerID > 0)
		{
			//vm_delete_timer(g_VamTask.nTimerID);
			vm_delete_timer_ex(g_VamTask.nTimerID);
			g_VamTask.nTimerID = -1;
		}
		if(g_VamTask.nConnectTimer >= 0)
		{
			vm_delete_timer_ex(g_VamTask.nConnectTimer);
			g_VamTask.nConnectTimer = -1;
		}
	}

	//rencai.xiao 2010/03/18
	if(g_VamTask.nIsSave == FALSE && g_VamTask.bDlApp == TRUE)
	{
	   vm_vam_save_task_list();
	   g_VamTask.nIsSave = TRUE;
	}
	
	vm_log_debug("vip_cancel_request_and_finalize");
	vip_cancel_request_handle(VIP_APP_HANDLE);
	//vip_cancel_request_and_finalize();
	vm_log_debug("vm_vam_release_task_list");
	vm_vam_release_task_list();
	#ifdef LOG_AM_DOWNLOAD
	vm_log_fatal("vm_vam_cancel_download end");
	#endif
}

static VMINT vm_vam_is_vas(VMUINT32 nAppID)
{
	VMINT nHighValue;

	nHighValue = nAppID >> 16;
	if(nHighValue == 1)
		return TRUE;
	else
		return FALSE;
}

void vm_am_pre_download_app(void *(* mem_calloc_cb)(int size), void (* mem_free_cb)(void *ptr))
{
  
   g_VamTask.vam_malloc = mem_calloc_cb;
   g_VamTask.vam_free = mem_free_cb;
   
   return ;
}

/**
 * 判断是否存在.gz文件，如果存在则直接解压
 */
 #ifdef AM_SUPPORT_GZIP
 VMINT vm_vam_check_gz_file(Vam_Task_t * pTask, VMWCHAR * pFilename)
{
   VMWCHAR szwSuffix[8];
   VMINT nHandle;
   struct vm_fileinfo_t fileinfo;
   
   /*获取目标文件名*/
   if(g_VamTask.bAppStore)
   {
      /*当前下载的是AS*/
      if(vm_vam_get_temp_filename(pFilename, pTask->szFilename, (VMINT8)pTask->nDriver, TRUE) == VAM_DL_ERR)
	  	return -1;
   }
   else
   {
       if(vm_vam_get_task_save_path(pTask, pFilename) == VAM_DL_ERR)
	   	return -1;
   }

   memset(szwSuffix, 0, sizeof(szwSuffix));
   vm_chset_convert(VM_CHSET_ASCII, VM_CHSET_UCS2, VAM_GZIP_SUFFIX, (VMSTR)szwSuffix, sizeof(szwSuffix));

     /*追加.gz*/
   vm_wstrcat(pFilename, szwSuffix);

   /*搜索是否存在.gz文件*/
   nHandle = vm_find_first(pFilename, &fileinfo);
   if(nHandle < 0)
   	return -1;
   vm_find_close(nHandle);

   /*搜索到.gz文件，对其解压*/
   if(vm_vam_unpack_gzip(NULL, pFilename, FALSE))
	return -1;

   return 0;
}
 #endif
static VMINT vm_vam_check_temp_file_size(Vam_Task_t * pTask)
{
     VMUINT nFileSize;
     //static VMWCHAR /*szAsTempName[MAX_LEN_FILE_NAME + 1],*/ pFilename[MAX_LEN_FILE_NAME + 1];
     VMWCHAR * szAsTempName = NULL, *pFilename = NULL;

      szAsTempName = g_VamTask.vam_malloc(MAX_LEN_FILE_NAME * 2 + 1);
      if(!szAsTempName)
	  	return VAM_DL_ERR;
	memset(szAsTempName, 0, MAX_LEN_FILE_NAME * 2 + 1);
	pFilename = g_VamTask.vam_malloc(MAX_LEN_FILE_NAME * 2 + 1);
      if(!pFilename)
      	{
      	    g_VamTask.vam_free(szAsTempName);
	    szAsTempName = NULL;
	    return VAM_DL_ERR;
      	}
	memset(pFilename, 0, MAX_LEN_FILE_NAME * 2 + 1);

       vm_log_debug("vm_vam_check_temp_file_size");
	if(vm_vam_open_temp_file(pTask) == VAM_DL_ERR)
	{
	       #ifdef AM_SUPPORT_GZIP
		   VMINT nRet;
		   if(pTask->nFilehandle >= 0)
		   {
		      vm_file_close(pTask->nFilehandle);
		      pTask->nFilehandle = -1;
		   }

		   nRet = vm_vam_check_gz_file(pTask, pFilename);
		   
		   g_VamTask.vam_free(szAsTempName);
		   szAsTempName = NULL;
		   g_VamTask.vam_free(pFilename);
		   pFilename = NULL;

		   if(nRet)
		       return VAM_DL_ERR;
		   else
		   	return VAM_DL_OK;
		  
		#else
	       g_VamTask.vam_free(szAsTempName);
	       szAsTempName = NULL;
		g_VamTask.vam_free(pFilename);
	       pFilename = NULL;
		return VAM_DL_ERR;
		#endif
	}

	vm_file_seek(pTask->nFilehandle, 0, BASE_BEGIN);
	vm_file_getfilesize(pTask->nFilehandle, &nFileSize);

     vm_log_debug("nFileSize = %d, task size = %d", pTask->nFilesize);
     if((VMINT)nFileSize > 0 && (VMINT)nFileSize == pTask->nFilesize && !g_VamTask.bAppStore)
     	{
     	   /*已经下载完成而且非as*/
          if(vm_vam_get_temp_filename(szAsTempName, pTask->szFilename, (VMINT8)pTask->nDriver, FALSE) == VAM_DL_ERR)
	  {
	       g_VamTask.vam_free(szAsTempName);
	       szAsTempName = NULL;
		g_VamTask.vam_free(pFilename);
	       pFilename = NULL;
		return VAM_DL_ERR;
	  }
	  if(vm_vam_get_task_save_path(pTask, pFilename) == VAM_DL_ERR)
	  {
	       g_VamTask.vam_free(szAsTempName);
	       szAsTempName = NULL;
		g_VamTask.vam_free(pFilename);
	       pFilename = NULL;
	  	return VAM_DL_ERR;
	  }
	  if(pTask->nFilehandle > 0)
	  {
	     vm_file_close(pTask->nFilehandle);
	     pTask->nFilehandle = -1;
	  }
	  vm_file_delete(pFilename);
	  vm_file_rmdir(pFilename);

	  #ifdef AM_SUPPORT_GZIP
	  if(vm_vam_unpack_gzip(szAsTempName, pFilename, TRUE))
	  {
		g_VamTask.vam_free(pFilename);
		pFilename = NULL;
		g_VamTask.vam_free(szAsTempName);
		szAsTempName = NULL;
		   //重命名失败
		return VAM_DL_IO_ERROR;
	  }
	  g_VamTask.vam_free(pFilename);
		pFilename = NULL;
		g_VamTask.vam_free(szAsTempName);
		szAsTempName = NULL;
              return VAM_DL_OK;
	#endif
	  if(vm_file_rename(szAsTempName, pFilename) != 0)
	  {
	       g_VamTask.vam_free(szAsTempName);
	       szAsTempName = NULL;
		g_VamTask.vam_free(pFilename);
	       pFilename = NULL;
		return VAM_DL_IO_ERROR;
	  }
	  else
	  {
	       g_VamTask.vam_free(szAsTempName);
	       szAsTempName = NULL;
		g_VamTask.vam_free(pFilename);
	       pFilename = NULL;
	  	return VAM_DL_OK;
	  }
     	}
     else
     	{
     	       if((VMINT)nFileSize > 0 && (VMINT)nFileSize == pTask->nFilesize && g_VamTask.bAppStore)
     	       {
			if(vm_vam_get_temp_filename(szAsTempName, pTask->szFilename, (VMINT8)pTask->nDriver, FALSE) == VAM_DL_ERR)
			{
			       g_VamTask.vam_free(szAsTempName);
			       szAsTempName = NULL;
				g_VamTask.vam_free(pFilename);
			       pFilename = NULL;
				return VAM_DL_ERR;
			}
			if(vm_vam_get_temp_filename(pFilename, pTask->szFilename, (VMINT8)pTask->nDriver, TRUE) == VAM_DL_ERR)
			{
			      g_VamTask.vam_free(szAsTempName);
			       szAsTempName = NULL;
				g_VamTask.vam_free(pFilename);
			       pFilename = NULL;
				return VAM_DL_ERR;
			}
			if(pTask->nFilehandle > 0)
	              {
	                 vm_file_close(pTask->nFilehandle);
	                 pTask->nFilehandle = -1;
	               }
			vm_file_delete(pFilename);
	              vm_file_rmdir(pFilename);

			#ifdef AM_SUPPORT_GZIP
			  if(vm_vam_unpack_gzip(szAsTempName, pFilename, TRUE))
			  {
				g_VamTask.vam_free(pFilename);
				pFilename = NULL;
				g_VamTask.vam_free(szAsTempName);
				szAsTempName = NULL;
				   //重命名失败
				return VAM_DL_IO_ERROR;
			  }
			  g_VamTask.vam_free(pFilename);
				pFilename = NULL;
				g_VamTask.vam_free(szAsTempName);
				szAsTempName = NULL;
		              return VAM_DL_OK;
			#endif
	              if(vm_file_rename(szAsTempName, pFilename) != 0)
	              {
	                   g_VamTask.vam_free(szAsTempName);
			       szAsTempName = NULL;
				g_VamTask.vam_free(pFilename);
			       pFilename = NULL;
		            return VAM_DL_IO_ERROR;
	              }
	              else
	              {
	                  g_VamTask.vam_free(szAsTempName);
			       szAsTempName = NULL;
				g_VamTask.vam_free(pFilename);
			       pFilename = NULL;
	  	           return VAM_DL_OK;
	              }
     	              vm_log_debug("AS nFileSize .");
			return VAM_DL_OK;
     	       }
		else
		{
		      g_VamTask.vam_free(szAsTempName);
		       szAsTempName = NULL;
			g_VamTask.vam_free(pFilename);
		       pFilename = NULL;
	 	      return VAM_DL_ERR;
		}
     	}
}
VMINT vm_vam_download_app(void(*download_app_cb)(VMINT nResult, VMINT nPercent), 
	VMUINT32 nAppID, VMWSTR pszFileName, VMINT nBlockSize)
{
	Vam_Task_t * pTask = NULL;
	VMINT nRet;
	VMINT nReadRet, nReqRet, nCheckRet, nVreForder;
	if(g_VamTask.vam_malloc == NULL || g_VamTask.vam_free == NULL)
		return VAM_DL_ERR;

	g_VamTask.nIsSave = FALSE;
	g_VamTask.nRetryCount = 0;
	g_VamTask.nConnectTimer = -1;
#ifdef LOG_AM_DOWNLOAD
       vm_log_fatal("[AM] AM version = 20100517");
	vm_log_fatal("[AM] download_app nAppID = %d", nAppID);
#endif
       g_VamTask.pHistoryList = NULL;
       g_VamTask.nHistoryLen = 0;

	//rencai.xiao 2010/03/18
	g_VamTask.bDlApp = TRUE;
	
       //modified by rencai.xiao 10/01/25
	nVreForder = vm_vam_check_vre_folder();
#ifdef LOG_AM_DOWNLOAD
       vm_log_debug("[AM] nVreForder = %d", nVreForder);
#endif
       if(nVreForder == -2)
	   	return VAM_DL_SPACE_FULL;
	else if(nVreForder == -3)
		return VAM_DL_SPACE_FULL;
	//判断下载的是应用还是AS
	if(vm_vam_is_vas(nAppID))
		g_VamTask.bAppStore = TRUE;
	else
		g_VamTask.bAppStore = FALSE;

#ifdef LOG_AM_DOWNLOAD
    vm_log_fatal("[AM] isAS = %d", g_VamTask.bAppStore);
#endif
	g_VamTask.download_app_cb = download_app_cb;
	if(nBlockSize < 0)
		g_VamTask.nBlockSize = VAM_DOWNLOAD_DEFAULT_SIZE;
	else
		g_VamTask.nBlockSize = nBlockSize;
	
	//通过VersionID判断要下载的应用是否在任务列表中，需要解析任务列表，跟VS公用
	//读取task列表
	nReadRet = vm_vam_read_task_list();
#ifdef LOG_AM_DOWNLOAD
	vm_log_fatal("[AM] nReatRet = %d", nReadRet);
#endif
	if(nReadRet == VAM_DL_ERR || nReadRet == VAM_DL_IO_ERROR)
	{
	       g_VamTask.nIsSave = TRUE;

		//rencai.xiao 2010/03/18
		g_VamTask.bDlApp = FALSE;
		vm_log_debug("vm_vam_read_task_list error.");
		return nReadRet;
	}

	//添加到列表
	nRet = vm_vam_add_task(nAppID/*pszVersionID*/, pszFileName);
#ifdef LOG_AM_DOWNLOAD
	vm_log_fatal("add ret = %d", nRet);
#endif
	if(nRet == VAM_DL_ERR)
	{
	       g_VamTask.nIsSave = TRUE;
		//rencai.xiao 2010/03/18
		g_VamTask.bDlApp = FALSE;
		vm_vam_release_task_list();
		return VAM_DL_ERR;
	}
#ifdef LOG_AM_DOWNLOAD
	vm_log_fatal("get download task.");
#endif
	pTask = vm_vam_get_task(nAppID/*pszVersionID*/);
	if(!pTask)
	{
	       //rencai.xiao 2010/03/18
		g_VamTask.bDlApp = FALSE;
	       g_VamTask.nIsSave = TRUE;
		vm_vam_release_task_list();
		return VAM_DL_ERR;
	}

	//added by rencai.xiao 10/01/25`
	if(nVreForder == -1 && pTask->nDriver != vm_get_system_driver())
		pTask->nDriver = vm_get_system_driver();
	if(vm_wstrcmp(pTask->szFilename, pszFileName) != 0)
	{
	    memset(pTask->szFilename, 0, sizeof(pTask->szFilename));
	    vm_wstrcpy(pTask->szFilename, pszFileName);
	}

	nCheckRet = vm_vam_check_temp_file_size(pTask);
	if(nCheckRet == VAM_DL_OK)
	{
#ifdef LOG_AM_DOWNLOAD
	    vm_log_fatal("download done.");
#endif
	   //modified by rencai.xiao 10/01/18
	    if(g_VamTask.download_app_cb)
		g_VamTask.download_app_cb(VAM_DL_OK, 0);
	    vm_vam_download_finish(pTask);
	    return VAM_DL_OK;
	}
	else if(nCheckRet == VAM_DL_IO_ERROR)
	{
		pTask->eState = APPDLSTATE_FAIL;
		vm_vam_download_app_fail(pTask, -1);
		return VAM_DL_OK;
	}
#ifdef LOG_AM_DOWNLOAD
      vm_log_fatal("[AM]save task list. pTask = %p", pTask);
#endif
	//保存列表
	if(nRet != VAM_DL_DONE)
	{
		VMINT nSaveRet;
		nSaveRet = vm_vam_save_task_list();
#ifdef LOG_AM_DOWNLOAD
		vm_log_fatal("[AM] nSaveRet = %d", nSaveRet);
#endif
		if(nSaveRet == VAM_DL_ERR || nSaveRet == VAM_DL_IO_ERROR || nSaveRet == VAM_DL_SPACE_FULL)
		{
		      //deleted by rencai.xiao 10/01/25
		       //g_VamTask.nIsSave = TRUE;
			//vm_vam_release_task_list();
#ifdef LOG_AM_DOWNLOAD
			vm_log_fatal("[AM] vm_vam_save_task_list error.");
#endif
			//return nSaveRet;
		}
	}

    //如果不在任务列表中，将该应用添加到任务列表

	//vram中获取phone id 和user id
#ifndef _DEBUG
	if(vm_load_mobile_phone_id_record(&g_VamTask.nPhoneID) != VM_ADAPTER_NVRAM_SUCCESS)
		g_VamTask.nPhoneID = 0;
	if(vm_load_user_id_record(&g_VamTask.nUserID) != VM_ADAPTER_NVRAM_SUCCESS)
		g_VamTask.nUserID = 0;
#else
	g_VamTask.nPhoneID = 0;
	g_VamTask.nUserID = 0;
#endif
#ifdef LOG_AM_DOWNLOAD
       vm_log_fatal("[AM] vip_init");
#endif
	if(vip_init_ext(g_VamTask.nPhoneID, g_VamTask.nUserID, VIP_APP_HANDLE))
	{
	      g_VamTask.nIsSave = TRUE;
#ifdef LOG_AM_DOWNLOAD
		vm_log_fatal("vip_init error.");
#endif
              //rencai.xiao 2010/03/18
		g_VamTask.bDlApp = FALSE;
              vip_cancel_request_handle(VIP_APP_HANDLE);
		//vip_cancel_request_and_finalize();
		
		vm_vam_release_task_list();
		return VAM_DL_ERR;
	}
	
#ifdef LOG_AM_DOWNLOAD
	vm_log_fatal("start request data.");
#endif
	nReqRet = vm_vam_request_data(pTask);
#ifdef LOG_AM_DOWNLOAD
	vm_log_fatal("[AM] nReqRet = %d", nReqRet);
#endif
	if(nReqRet == VAM_DL_ERR || nReqRet == VAM_DL_IO_ERROR)
	{
	   //rencai.xiao 2010/03/18
	   g_VamTask.bDlApp = FALSE;
	   g_VamTask.nIsSave = TRUE;
	   //vip_cancel_request_and_finalize();
	   vip_cancel_request_handle(VIP_APP_HANDLE);
	   vm_vam_release_task_list();
#ifdef LOG_AM_DOWNLOAD
	   vm_log_fatal("[AM] request data error.");
#endif
	   return nReqRet;
	}
	
	return VAM_DL_OK;
}

VMINT vm_vam_check_tempfile(VMSHORT * filename, VMINT* progress)
{
	return 0;
}

VMINT vm_get_app_version(VMWSTR filename, VMINT * version)
{
		VMINT retval = VAM_DL_ERR, len = 4;
	VMUINT8 buf[4] = {0};
	VMUINT8 temp;
	
	if (filename == NULL || version == NULL)
	{
		return VAM_DL_ERR;
	}
	
	if (vm_get_vm_tag(filename,  VM_CE_INFO_VER,  (VMUINT8 *)buf,  &len) == GET_TAG_TRUE)
	{
		temp = buf[0];
		buf[0] = buf[3];
		buf[3] = temp;
		
		temp = buf[1];
		buf[1] = buf[2];
		buf[2] = temp;
		
		*version = *((VMINT *)buf);
		vm_log_debug("{ASL MODULE}Application version=%x", *version);
		retval = VAM_DL_OK;
	}
	
	return retval;

}

static VMINT vm_vam_get_task_size(Vam_Task_t * pTask, VMINT nSize)
{
	VMUINT nFileSize;

	if(vm_vam_open_temp_file(pTask) == VAM_DL_ERR)
		return 0;

	vm_file_seek(pTask->nFilehandle, 0, BASE_BEGIN);
	vm_file_getfilesize(pTask->nFilehandle, &nFileSize);

	if((VMINT)nFileSize > nSize)
		return 0;

	return nSize - nFileSize;
}
static VMINT dm_file_copy(VMWSTR pwFileName, VMWSTR pwNewFileName)
{
	VMINT nFileHandle, nNewFileHandle, nFindHandle;
	VMUINT nRead, nWritten;
	VMCHAR * pCopyBuf = NULL;
	VMUINT nFileSize;
	VMINT nCopyNum; //Copy 次数
	VMINT i;
	//struct vm_fileinfo_t fileinfo;

#ifdef LOG_AM_DOWNLOAD
      vm_log_debug("[AM] dm_file_copy");
#endif
       //added by rencai.xiao 10/01/25
       nFindHandle = vm_find_first(pwFileName, &fileinfo);
       if(nFindHandle < 0)
       {
          nNewFileHandle = vm_file_open(pwNewFileName, MODE_CREATE_ALWAYS_WRITE, TRUE);
	   if(nNewFileHandle < 0)
	   	return VAM_DL_ERR;
	   return VAM_DL_OK;
       }
	vm_find_close(nFindHandle);
	nFileHandle = vm_file_open(pwFileName, MODE_READ, TRUE);

	if(nFileHandle < 0)
		return VAM_DL_ERR;

       //added by rencai.xiao 10/01/25 
       vm_file_delete(pwNewFileName);
	nNewFileHandle = vm_file_open(pwNewFileName, MODE_CREATE_ALWAYS_WRITE, TRUE);

	if(nNewFileHandle < 0)
	{
		vm_file_close(nFileHandle);
		return VAM_DL_ERR;
	}

    pCopyBuf = vm_malloc(DM_COPY_SIZE + 1);
	if(!pCopyBuf)
	{
		vm_file_close(nFileHandle);
		vm_file_close(nNewFileHandle);
		return VAM_DL_ERR;
	}
	memset(pCopyBuf, 0, DM_COPY_SIZE + 1);

	vm_file_getfilesize(nFileHandle, &nFileSize);


	nCopyNum = nFileSize / DM_COPY_SIZE;
	if(nFileSize % DM_COPY_SIZE != 0)
		nCopyNum ++;

	vm_file_seek(nFileHandle, 0, BASE_BEGIN);
	vm_file_seek(nNewFileHandle, 0, BASE_BEGIN);
	for(i = 0 ; i < nCopyNum ; i ++)
	{
		VMINT nReadSize;

		if(i != nCopyNum - 1)
			nReadSize = DM_COPY_SIZE;
		else
			nReadSize = nFileSize - (nCopyNum - 1) * DM_COPY_SIZE;
		memset(pCopyBuf, 0, DM_COPY_SIZE + 1);
		
		if(vm_file_read(nFileHandle, pCopyBuf, nReadSize, &nRead) != nReadSize)
		{
			vm_file_close(nFileHandle);
			vm_file_close(nNewFileHandle);
			SAFE_FREE(pCopyBuf);
			return VAM_DL_ERR;
		}
		if(vm_file_write(nNewFileHandle, pCopyBuf, nReadSize, &nWritten) != nReadSize)
		{
			vm_file_close(nFileHandle);
			vm_file_close(nNewFileHandle);
			SAFE_FREE(pCopyBuf);
			return VAM_DL_ERR;
		}
	}


	vm_file_close(nFileHandle);
	vm_file_close(nNewFileHandle);
	SAFE_FREE(pCopyBuf);
	return VAM_DL_OK;
}

//rencai.xiao 2010/03/01 获取AS版本号
VMINT vm_vam_get_appstore_new_version(VMCHAR * pAsVersion)
{
	//static VMCHAR szFileName[MAX_LEN_FILE_NAME];
	//static VMWCHAR szExecFileName[MAX_LEN_FILE_NAME];
	VMCHAR szExecVersion[10];
	VMWCHAR * szExecFileName = NULL;

	
	
	if(!pAsVersion)
		return FALSE;

	szExecFileName = g_VamTask.vam_malloc_ex(MAX_LEN_FILE_NAME * 2 + 1);
	if(!szExecFileName)
		return FALSE;
	memset(szExecFileName, 0, MAX_LEN_FILE_NAME * 2 + 1);
	
	//memset(szFileName,0,sizeof(szFileName));
	
	//获取当前执行程序的版本号
	//memset(szExecFileName, 0, sizeof(szExecFileName));
	//memset(g_VamTask.szwFileName, 0, sizeof(g_VamTask.szwFileName));
	memset(szExecVersion, 0, sizeof(szExecVersion));
	
	if(vm_get_exec_filename(szExecFileName) == 0)
	{
		if(vm_vam_get_app_version(szExecFileName, szExecVersion))
		{
		       g_VamTask.vam_free_ex(szExecFileName);
			szExecFileName = NULL;
			memcpy(pAsVersion, szExecVersion, sizeof(szExecVersion));
			return TRUE;
		}
	}

	g_VamTask.vam_free_ex(szExecFileName);
       szExecFileName = NULL;
	return TRUE;
}


void vm_vam_cancel_sync_cdr(void)
{
    g_VamTask.bChannel = FALSE;
    g_VamTask.bChargeDetail = FALSE;
    g_VamTask.bSmsDetail = FALSE;
    g_VamTask.bPay = FALSE;
    //vip_cancel_request_and_finalize();

    if(sms_detail_list)
	{
	   vm_log_fatal("[AM] vam_free_ex sms_detail_list= %p", sms_detail_list);
	   g_VamTask.vam_free_ex(sms_detail_list);
	   sms_detail_list = NULL;
	}
   if(charge_detail_list)
   	{
   	   vm_log_fatal("[AM] vam_free_ex charge_detail_list= %p", charge_detail_list);
   	   g_VamTask.vam_free_ex(charge_detail_list);
	   charge_detail_list = NULL;
   	}
    vip_cancel_request_handle(VIP_OTHER_HANDLE);
}


//rencai.xiao 2010/03/15
VMINT vm_vam_get_charge_detail_list_count(void)
{
    VMINT nCount = 0;
    VMINT i;

    if(!charge_detail_list)
		return 0;

    for(i = 0 ; i < NVRAM_CHARGE_DETAIL_NUM ; i ++)
	{
	#ifdef AM_SUPPORT_EXTEND_PAY_CONFIG
	       if(charge_detail_list->charge_detail_ext[i].app_id == 0 && 
			   charge_detail_list->charge_detail_ext[i].local_payment_id == 0)
	#else
		if(charge_detail_list->charge_detail[i].app_id == 0 && 
			   charge_detail_list->charge_detail[i].local_payment_id == 0)
	#endif
		 break;
		else
			nCount ++;
    	}

	return nCount;
}

VMINT vm_vam_get_sms_detail_list_count(void)
{
    VMINT nCount = 0, i;
	VMCHAR * sms_access = NULL;

    if(!sms_detail_list)
		return 0;

	sms_access = g_VamTask.vam_malloc_ex(sizeof(sms_detail_list->charge_sms_detail[0].sms_access) + 1);
	if(!sms_access)
		return 0;

    for(i = 0 ; i < NVRAM_CHARGE_DETAIL_NUM ; i ++)
	{
		memset(sms_access, 0, sizeof(sms_detail_list->charge_sms_detail[0].sms_access) + 1);
		memcpy(sms_access, sms_detail_list->charge_sms_detail[i].sms_access, sizeof(sms_detail_list->charge_sms_detail[i].sms_access));
		   if(sms_detail_list->charge_sms_detail[i].seq_id == 0 && 
			  strlen(/*sms_detail_list->charge_sms_detail[i].sms_access*/sms_access) == 0)
			  break;
		   else
		   	nCount ++;
    	}

	g_VamTask.vam_free_ex(sms_access);
	sms_access = NULL;
	return nCount;
}
//rencai.xiao 2010/03/01
VMINT vm_vam_sync_cdr(void (*sync_cb)(VMINT nResult))
{
	static vm_time_t TimeStamps[VM_NVRAM_MAX_TIMESTAMP];
	vm_time_t CurTimeStamp;
	static VMCHAR szPerTime[20];
	static VMCHAR szCertTime[20];
	static VMCHAR szAppBlstTime[20];
	static VMCHAR szChannel[20];
	static VMCHAR szLocalVersion[20];
	//static VMCHAR szTempPath[100];
	VMCHAR * szTempPath = NULL;
	/*modified by rencai.xiao 2010/06/21 use extention interface*/
	#ifdef AM_SUPPORT_EXTEND_PAY_CONFIG
	static vm_pay_config_ext_t pay_config;
	#else
	static vm_pay_config_t pay_config;
	#endif
	VMINT nPos = 0;
	VMCHAR * res_path = NULL;
	//VMINT i;
	
#ifdef LOG_AM_DOWNLOAD
    vm_log_fatal("[AM] vm_vam_sync_cdr");
    vm_log_fatal("[AM] version : 20100517");
#endif
//for test
       g_VamTask.vam_malloc_ex = vm_malloc;
       g_VamTask.vam_free_ex = vm_free;
	if(!g_VamTask.vam_malloc_ex || !g_VamTask.vam_free_ex)
		return VAM_DL_ERR;

	szTempPath = g_VamTask.vam_malloc_ex(100);
	if(!szTempPath)
		return VAM_DL_ERR;
	memset(szTempPath, 0, 100);

	sms_detail_list = g_VamTask.vam_malloc_ex(sizeof(vm_nvram_charge_sms_detail_list_t) + 1);
	if(!sms_detail_list)
	{
	       g_VamTask.vam_free_ex(szTempPath);
		return VAM_DL_ERR;
	}
	memset(sms_detail_list, 0, sizeof(vm_nvram_charge_sms_detail_list_t) + 1);

#ifdef AM_SUPPORT_EXTEND_PAY_CONFIG
       charge_detail_list = g_VamTask.vam_malloc_ex(sizeof(vm_nvram_charge_detail_list_ext_t) + 1);//NVRAM中计费信息
#else
	charge_detail_list = g_VamTask.vam_malloc_ex(sizeof(vm_nvram_charge_detail_list_t) + 1);
#endif
	if(!charge_detail_list)
	{
	       g_VamTask.vam_free_ex(szTempPath);
		g_VamTask.vam_free_ex(sms_detail_list);
		return VAM_DL_ERR;
	}

	#ifdef AM_SUPPORT_EXTEND_PAY_CONFIG
	memset(charge_detail_list, 0, sizeof(vm_nvram_charge_detail_list_ext_t) + 1);
	#else
	memset(charge_detail_list, 0, sizeof(vm_nvram_charge_detail_list_t) + 1);
	#endif

	g_VamTask.sync_cb = sync_cb;
	g_VamTask.bChannel = FALSE;
	g_VamTask.bChargeDetail = FALSE;
	g_VamTask.bPay = FALSE;
	g_VamTask.bSmsDetail = FALSE;
	//rencai.xiao 2010/03/15
	//for(i = 0 ; i < NVRAM_CHARGE_DETAIL_NUM ;i++)
		//memset(&charge_detail_list.charge_detail[i], 0, sizeof(charge_detail_list.charge_detail[i]));
	//for(i = 0 ; i < NVRAM_CHARGE_DETAIL_NUM ; i ++)
		//memset(&sms_detail_list.charge_sms_detail[i], 0, sizeof(sms_detail_list.charge_sms_detail[i]));
	
	g_VamTask.nChargeDetailCount = 0;
	g_VamTask.nSmsDetailCount = 0;

	res_path = g_VamTask.vam_malloc_ex(VAM_RES_PATH_SIZE);
	if(!res_path)
	{
	       g_VamTask.vam_free_ex(szTempPath);
		g_VamTask.vam_free_ex(sms_detail_list);
		g_VamTask.vam_free_ex(charge_detail_list);
		return VAM_DL_ERR;
	}
	memset(res_path, 0, VAM_RES_PATH_SIZE/*sizeof(res_path)*/);
	
	memset(TimeStamps,0,sizeof(TimeStamps));
	memset(szPerTime,0,sizeof(szPerTime));
	memset(szCertTime,0,sizeof(szCertTime));
	memset(szAppBlstTime,0,sizeof(szAppBlstTime));
	memset(szChannel,0,sizeof(szChannel));
	memset(szLocalVersion,0,sizeof(szLocalVersion));
	

	//系统配置
	if (vm_load_timestamps_record(TimeStamps) == VM_ADAPTER_NVRAM_SUCCESS)
	{
		if (vm_split_timestamp(TimeStamps, &CurTimeStamp, VM_NVRAM_SYS_PERMISSION_TIMESTAMP))
		{
			memset(szPerTime, 0, sizeof(szPerTime));
			sprintf(szPerTime, "%04d%02d%02d%02d%02d%02d", CurTimeStamp.year, CurTimeStamp.mon, CurTimeStamp.day, 
				CurTimeStamp.hour, CurTimeStamp.min, CurTimeStamp.sec);
		}
		if (vm_split_timestamp(TimeStamps, &CurTimeStamp, VM_NVRAM_BAN_APP_LST_TIMESTAMP))
		{
			memset(szAppBlstTime, 0, sizeof(szAppBlstTime));
			sprintf(szAppBlstTime, "%04d%02d%02d%02d%02d%02d", CurTimeStamp.year, CurTimeStamp.mon, CurTimeStamp.day, 
				CurTimeStamp.hour, CurTimeStamp.min, CurTimeStamp.sec);
		}
		if (vm_split_timestamp(TimeStamps, &CurTimeStamp, VM_NVRAM_PUBLIC_CERT_LST_TIMESTAMP))
		{
			memset(szCertTime, 0, sizeof(szCertTime));
			sprintf(szCertTime, "%04d%02d%02d%02d%02d%02d", CurTimeStamp.year, CurTimeStamp.mon, CurTimeStamp.day, 
				CurTimeStamp.hour, CurTimeStamp.min, CurTimeStamp.sec);
		}
		if (vm_split_timestamp(TimeStamps, &CurTimeStamp, VM_NVRAM_CHARGE_CHANNEL_LST_TIMESTAMP))
		{
			memset(szChannel, 0, sizeof(szChannel));
			sprintf(szChannel, "%04d%02d%02d%02d%02d%02d", CurTimeStamp.year, CurTimeStamp.mon, CurTimeStamp.day, 
				CurTimeStamp.hour, CurTimeStamp.min, CurTimeStamp.sec);
		}
	}
	
	memset(szLocalVersion, 0, sizeof(szLocalVersion));
	vm_vam_get_appstore_new_version(szLocalVersion);
	sprintf(res_path,UPDATE_CONFIG_PATH,szPerTime, szCertTime, szAppBlstTime, szChannel, szLocalVersion);
#ifdef LOG_AM_DOWNLOAD
    vm_log_fatal("[AM] res_path = %s", res_path);
#endif
    g_VamTask.bChannel = TRUE;

	

  
	//计费信息同步
	//memset(szTempPath, 0, sizeof(szTempPath));

	
//modified by rencai.xiao 2010/06/19 if  AM_SUPPORT_EXTEND_PAY_CONFIG is defined , use extension interface.
#ifdef AM_SUPPORT_EXTEND_PAY_CONFIG
       if(vm_get_charge_detail_list_ext(charge_detail_list))
#else
	//获取计费信息的接口
	if(vm_get_charge_detail_list(charge_detail_list))
#endif
	{
		//static VMCHAR nvram_charge_detail[50];
		VMINT i;
		VMINT charge_detail_len = 0;
		VMINT nLenPos;
		VMCHAR * nvram_charge_detail = NULL;
		VMCHAR * ext_content = NULL;

		nvram_charge_detail = g_VamTask.vam_malloc_ex(50);
		if(!nvram_charge_detail)
		{
		   g_VamTask.vam_free_ex(res_path);
		   res_path = NULL;
		   g_VamTask.vam_free_ex(szTempPath);
		   g_VamTask.vam_free_ex(sms_detail_list);
		   g_VamTask.vam_free_ex(charge_detail_list);
		   return VAM_DL_ERR;
		}

#ifdef AM_SUPPORT_EXTEND_PAY_CONFIG
              ext_content = g_VamTask.vam_malloc_ex(sizeof(charge_detail_list->charge_detail_ext[0].ext_content) + 1);
#else
		ext_content = g_VamTask.vam_malloc_ex(sizeof(charge_detail_list->charge_detail[0].ext_content) + 1);
#endif
		if(!ext_content)
		{
		      g_VamTask.vam_free_ex(res_path);
		      res_path = NULL;
			g_VamTask.vam_free_ex(szTempPath);
			g_VamTask.vam_free_ex(sms_detail_list);
		    g_VamTask.vam_free_ex(charge_detail_list);
			g_VamTask.vam_free_ex(nvram_charge_detail);
			return VAM_DL_ERR;
		}
		memset(nvram_charge_detail, 0, 50);
		
        strcat(res_path, ";");
		sprintf(szTempPath, "%s", VIP_SYNC_FEEINFO_URL);
		strcat(res_path, szTempPath);
		vm_log_fatal("[AM] feeinfo path = %s", szTempPath);
		nLenPos = strlen(res_path);
		nPos += nLenPos;

		//rencai.xiao 2010/03/15
		g_VamTask.nChargeDetailCount = vm_vam_get_charge_detail_list_count();
		#ifdef LOG_AM_DOWNLOAD
		   vm_log_fatal("[AM] nChargeDetailCount = %d", g_VamTask.nChargeDetailCount);
		#endif
		
		for(i = 0 ; i < AM_NVRAM_READ_MAX_VALUE/*NVRAM_CHARGE_DETAIL_NUM*/ ; i ++)
		{
			memset(nvram_charge_detail, 0, 50);
			
#ifdef AM_SUPPORT_EXTEND_PAY_CONFIG
                      memset(ext_content, 0, sizeof(charge_detail_list->charge_detail_ext[0].ext_content) + 1);
                     if(charge_detail_list->charge_detail_ext[i].app_id == 0 && 
			   charge_detail_list->charge_detail_ext[i].local_payment_id == 0)
#else
                     memset(ext_content, 0, sizeof(charge_detail_list->charge_detail[0].ext_content) + 1);
			if(charge_detail_list->charge_detail[i].app_id == 0 && 
			   charge_detail_list->charge_detail[i].local_payment_id == 0)
#endif
		   break;

			
#ifdef AM_SUPPORT_EXTEND_PAY_CONFIG
                     memcpy(ext_content, charge_detail_list->charge_detail_ext[i].ext_content, sizeof(charge_detail_list->charge_detail_ext[i].ext_content));
                     sprintf(nvram_charge_detail, "%d,%s,%d,%d,%d,%d,%s", 
				                         charge_detail_list->charge_detail_ext[i].seq_id, 
				                         charge_detail_list->charge_detail_ext[i].mcc,
										 charge_detail_list->charge_detail_ext[i].app_id,
										 charge_detail_list->charge_detail_ext[i].local_payment_id,
										 charge_detail_list->charge_detail_ext[i].fee,
										 charge_detail_list->charge_detail_ext[i].source,
										 ext_content
										 );
#else
                     memcpy(ext_content, charge_detail_list->charge_detail[i].ext_content, sizeof(charge_detail_list->charge_detail[i].ext_content));
			sprintf(nvram_charge_detail, "%d,%d,%d,%d,%d,%s", 
				                         charge_detail_list->charge_detail[i].seq_id, 
	
									 charge_detail_list->charge_detail[i].app_id,
	
									 charge_detail_list->charge_detail[i].local_payment_id,
	
									 charge_detail_list->charge_detail[i].fee,
	
									 charge_detail_list->charge_detail[i].source,
	
									 /*charge_detail_list->charge_detail[i].ext_content*/ext_content);
#endif
		if(i > 0)
			{
				charge_detail_len += 1;
				//中间以换行符隔开
				strcat(res_path + nPos, "\n");
				nPos += 1;
			}
			charge_detail_len += strlen(nvram_charge_detail);

			
			strcpy(res_path + nPos, nvram_charge_detail);
			   
			nPos += strlen(nvram_charge_detail);

			
		}

		if(i > 0)
			//modified by rencai.xiao 2010/06/19
			#ifdef AM_SUPPORT_EXTEND_PAY_CONFIG
			g_VamTask.nChargeSeqID = charge_detail_list->charge_detail_ext[i - 1].seq_id;
			#else
			g_VamTask.nChargeSeqID = charge_detail_list->charge_detail[i - 1].seq_id;
			#endif
	else
			g_VamTask.nChargeSeqID = 0;
		g_VamTask.bChargeDetail = TRUE;

		g_VamTask.vam_free_ex(nvram_charge_detail);
		nvram_charge_detail = NULL;
	      g_VamTask.vam_free_ex(ext_content);
	      ext_content = NULL;

	}
 	else
 	{
#ifdef LOG_AM_DOWNLOAD
 
		vm_log_fatal("[AM] vm_get_charge_detail_list error.");

		#endif
		
	     g_VamTask.vam_free_ex(charge_detail_list);
	     charge_detail_list = NULL;
 
	}

	


	//短信信息同步
	memset(szTempPath, 0, 100);


	
	//获取短信信息的接口
	if(vm_get_charge_sms_detail_list(sms_detail_list))
	{
		//static VMCHAR nvram_sms_detail[50];
		VMINT i;
		VMINT sms_detail_len = 0;
		VMINT nLenPos;
		VMCHAR * nvram_sms_detail = NULL;
		VMCHAR * sms_access = NULL, * sms_command = NULL;

		nvram_sms_detail = g_VamTask.vam_malloc_ex(100);
		if(!nvram_sms_detail)
		{
		   g_VamTask.vam_free_ex(res_path);
		res_path = NULL;
		   g_VamTask.vam_free_ex(szTempPath);
		   g_VamTask.vam_free_ex(sms_detail_list);
		   g_VamTask.vam_free_ex(charge_detail_list);
		   return VAM_DL_ERR;
		}
		memset(nvram_sms_detail, 0, 100);

		strcat(res_path + nPos, ";");
	    nPos += 1;
		sprintf(szTempPath, "%s", VIP_SYNC_SMSINFO_URL);
		strcat(res_path, szTempPath);
		nPos += strlen(szTempPath);

	#ifdef LOG_AM_DOWNLOAD
	
	vm_log_fatal("[AM] smsinfo path = %s", szTempPath);

	#endif
	
	nLenPos = nPos;

              //rencai.xiao 2010/03/15
              g_VamTask.nSmsDetailCount = vm_vam_get_sms_detail_list_count();
		#ifdef LOG_AM_DOWNLOAD
		vm_log_fatal("[AM] SmsDetailCount = %d", g_VamTask.nSmsDetailCount);
		#endif
		sms_access = g_VamTask.vam_malloc_ex(sizeof(sms_detail_list->charge_sms_detail[0].sms_access) + 1);
		if(!sms_access)
		{
		       g_VamTask.vam_free_ex(res_path);
		      res_path = NULL;
			g_VamTask.vam_free_ex(szTempPath);
			g_VamTask.vam_free_ex(sms_detail_list);
			g_VamTask.vam_free_ex(charge_detail_list);
			g_VamTask.vam_free_ex(nvram_sms_detail);
		   return VAM_DL_ERR;
		}
		sms_command = g_VamTask.vam_malloc_ex(sizeof(sms_detail_list->charge_sms_detail[0].sms_command) + 1);
		if(!sms_command)
		{
		       g_VamTask.vam_free_ex(res_path);
		res_path = NULL;
			g_VamTask.vam_free_ex(szTempPath);
			g_VamTask.vam_free_ex(sms_detail_list);
			g_VamTask.vam_free_ex(charge_detail_list);
			g_VamTask.vam_free_ex(nvram_sms_detail);
			g_VamTask.vam_free_ex(sms_access);
			return VAM_DL_ERR;
		}
		
		for(i = 0 ; i < AM_NVRAM_READ_MAX_VALUE/*NVRAM_CHARGE_DETAIL_NUM*/ ; i ++)
		{
           memset(nvram_sms_detail, 0, 100);
		   memset(sms_access, 0, sizeof(sms_detail_list->charge_sms_detail[0].sms_access) + 1);
		   memset(sms_command, 0, sizeof(sms_detail_list->charge_sms_detail[0].sms_command) + 1);
		   if(sms_detail_list->charge_sms_detail[i].seq_id == 0 && 
			  strlen(sms_detail_list->charge_sms_detail[i].sms_access) == 0)
			  break;

		   memcpy(sms_access, sms_detail_list->charge_sms_detail[i].sms_access, sizeof(sms_detail_list->charge_sms_detail[i].sms_access));
		   memcpy(sms_command, sms_detail_list->charge_sms_detail[i].sms_command, sizeof(sms_detail_list->charge_sms_detail[i].sms_command));
		   sprintf(nvram_sms_detail, "%d,%s,%s", 
			                     sms_detail_list->charge_sms_detail[i].seq_id, 
								 /*sms_detail_list->charge_sms_detail[i].sms_access*/sms_access,
								 /*sms_detail_list->charge_sms_detail[i].sms_command*/sms_command);

		   if(i > 0)
		   {
			   sms_detail_len += 1;
			   //中间以换行符隔开
			   strcat(res_path + nPos, "\n");
			   nPos += 1;
		   }

		   sms_detail_len += strlen(nvram_sms_detail);
		   strcpy(res_path + nPos, nvram_sms_detail);
		   nPos += strlen(nvram_sms_detail);
			
		}
	

		if(i > 0)
			g_VamTask.nSmsSeqID = sms_detail_list->charge_sms_detail[i - 1].seq_id;
		else
			g_VamTask.nSmsSeqID = 0;
		g_VamTask.bSmsDetail = TRUE;

		g_VamTask.vam_free_ex(nvram_sms_detail);
		nvram_sms_detail = NULL;
		g_VamTask.vam_free_ex(sms_access);
		sms_access = NULL;
		g_VamTask.vam_free_ex(sms_command);
		sms_command = NULL;
	}
 	else
 	{

	#ifdef LOG_AM_DOWNLOAD
 
		vm_log_fatal("[AM] vm_get_charge_sms_detail_list error.");

		#endif

	 g_VamTask.vam_free_ex(sms_detail_list);
	 sms_detail_list = NULL;
 
	}

		
	/*modified by rencai.xiao 2010/06/21*/
	#ifdef AM_SUPPORT_EXTEND_PAY_CONFIG
	if(vm_get_pay_config_ext(&pay_config))
	#else
	//获取促销金额
	if(vm_get_pay_config(&pay_config))
	#endif
	{
	   strcat(res_path + nPos, ";");
	   nPos += 1;
       sprintf(szTempPath, "%s?value=%d", VIP_PROMOTION_UPDATE_URL, pay_config.user_balance);
#ifdef LOG_AM_DOWNLOAD
	   vm_log_fatal("[AM] szTempPath pay = %s", szTempPath);
#endif
	   strcat(res_path + nPos, szTempPath);
	   g_VamTask.bPay = TRUE;
	}
 	else
 	{
#ifdef LOG_AM_DOWNLOAD
 		vm_log_fatal("[AM] vm_get_apy_config error.");
#endif
 	}


       g_VamTask.vam_free_ex(szTempPath);
	szTempPath = NULL;

       if(vm_load_mobile_phone_id_record(&g_VamTask.nPhoneID) != VM_ADAPTER_NVRAM_SUCCESS)
		g_VamTask.nPhoneID = 0;
	if(vm_load_user_id_record(&g_VamTask.nUserID) != VM_ADAPTER_NVRAM_SUCCESS)
		g_VamTask.nUserID = 0;
	
	if(vip_init_ext(g_VamTask.nPhoneID, g_VamTask.nUserID, VIP_OTHER_HANDLE))
	{
		g_VamTask.vam_free_ex(res_path);
		res_path = NULL;
#ifdef LOG_AM_DOWNLOAD	
		vm_log_fatal("[AM] vip_init_ext error.");
#endif
              g_VamTask.vam_free_ex(sms_detail_list);
              sms_detail_list = NULL;
	
             g_VamTask.vam_free_ex(charge_detail_list);
	      charge_detail_list = NULL;
		return VAM_DL_ERR;
	}

	if(register_vip_callback(vm_vam_vip_syscfg_callback))
	{
	       g_VamTask.vam_free_ex(res_path);
		res_path = NULL;
		//SAFE_FREE(res_path);
#ifdef LOG_AM_DOWNLOAD
		vm_log_fatal("[AM] register callback error.");
#endif

              g_VamTask.vam_free_ex(sms_detail_list);
              sms_detail_list = NULL;
	
              g_VamTask.vam_free_ex(charge_detail_list);
	      charge_detail_list = NULL;
              vm_vam_cancel_sync_cdr();
		//vip_cancel_request_handle(VIP_OTHER_HANDLE);
		return VAM_DL_ERR;
	}

	if(vip_read_resource(res_path) == 0)
	{
#ifdef LOG_AM_DOWNLOAD
		vm_log_fatal("[AM] vip_read_resource done.");
#endif
	}
	else
	{
	    g_VamTask.vam_free_ex(res_path);
		res_path = NULL;
		//SAFE_FREE(res_path);
#ifdef LOG_AM_DOWNLOAD
		vm_log_fatal("[AM] vip_read_resource error.");
#endif	
	        g_VamTask.vam_free_ex(charge_detail_list);
	      charge_detail_list = NULL;
		  g_VamTask.vam_free_ex(sms_detail_list);
 
             sms_detail_list = NULL;
               vm_vam_cancel_sync_cdr();
		//vip_cancel_request_handle(VIP_OTHER_HANDLE);
		return VAM_DL_ERR;
	}

       g_VamTask.vam_free_ex(res_path);
		res_path = NULL;
	//SAFE_FREE(res_path);
	return VAM_DL_OK;
}

//rencai.xiao 2010/03/02
VMINT vm_vam_is_multi_res(VMCHAR * res, VMUINT size)
{
	VMINT8 bCmd;
	VMCHAR * pResponse = (VMCHAR*)res;
	//static error_t  pError = {0};
	//static VMCHAR szData[10];
//	VMUINT32 nstrlen;

	
	memcpy(&bCmd, pResponse, 1);
	pResponse ++;

	
    if(bCmd == RES_ERROR_CMD || bCmd == REQ_READRES_CMD || bCmd == REQ_POST_DATA_CMD)
	{
		return TRUE;
//        if(bCmd == RES_ERROR_CMD)
// 	   {
// 		   memcpy(&pError.code, pResponse, 4);
// 		   pResponse += 4;
// 		   memset(szData, 0, sizeof(szData));
// 		   memcpy(szData, pResponse, 4);
// 		   pResponse += 4;
// 		   vm_vam_int_byte_switch((VMCHAR*)szData, &nstrlen, NULL);
// 		   pResponse += (nstrlen * 2);
// 		   
// 		   if(nstrlen * 2 + 9 == size)
// 			   return FALSE;
// 		   else
// 			   return TRUE;
// 
// 	   }
// 	   else
// 	   {
//            memset(szData, 0, sizeof(szData));
// 		   memcpy(szData, pResponse, 4);
// 		   pResponse += 4;
// 		   vm_vam_int_byte_switch((VMCHAR*)szData, &nstrlen, NULL);
// 		   
// 		   if(nstrlen * 2 + 5 == size)
// 			   return FALSE;
// 		   else
// 			   return TRUE;
// 	   }
	}
	else
		return FALSE;
}
//rencai.xiao 2010/03/01
void vm_vam_vip_syscfg_callback(VMINT uid, VMINT mpi, VMINT vip_response_type, 
							 const void* vip_response, VMUINT response_size)
{
	VMUINT unOffset = 0;
	VMINT8 nUpdateNum = 0;
	VMINT8 nCntId = 0;
	VMUINT32 nCntOffset = 0;
	VMINT nIndex;
		//VMBYTE szLenByte[4];
	//VMINT nAsDldFlag = 0;
	//VMINT nSysTimFlag = 0;
	VMCHAR time_info[15];
	//static VMCHAR szData[8];
	static VMWCHAR wszData[8], wszTempData[8];
	VMINT8 bCmd;
	VMCHAR * pResponse = (VMCHAR*)vip_response;
	static error_t  pError = {0};
	VMUINT32 strlen;
	VMINT nMultiRes;
	static VMCHAR str_data[5];
	static vm_time_t system_time;

	#ifdef AM_SUPPORT_EXTEND_PAY_CONFIG
	static vm_pay_config_ext_t pay_config;
	#else
	static vm_pay_config_t pay_config;
	#endif
	//VMINT nDone = FALSE;

	{
	    static VMCHAR szFilename[80];
	    static VMWCHAR szwFilename[80];
	    VMINT nHandle;
	    VMUINT nWritten;

	    memset(szFilename, 0, sizeof(szFilename));
	    memset(szwFilename, 0, sizeof(szwFilename));
	    sprintf(szFilename, "%c:\\sysconfig.dat", vm_get_removable_driver());
	    vm_chset_convert(VM_CHSET_ASCII, VM_CHSET_UCS2, szFilename, (VMSTR)szwFilename, sizeof(szwFilename));
	    nHandle = vm_file_open(szwFilename, MODE_CREATE_ALWAYS_WRITE, TRUE);
	    if(nHandle >= 0)
	    	{
	    	   vm_file_write(nHandle, (VMCHAR*)vip_response, response_size, &nWritten);
		   vm_file_close(nHandle);
	    	}
	}

#ifdef LOG_AM_DOWNLOAD
    vm_log_fatal("[AM] vm_vam_vip_syscfg_callback vip_response_type = %d, response_size = %d", 
		vip_response_type, response_size);
#endif

	nMultiRes = vm_vam_is_multi_res((VMCHAR*)vip_response, response_size);

#ifdef LOG_AM_DOWNLOAD
       vm_log_fatal("[AM] nMultiRes = %d", nMultiRes);
#endif

	vm_save_mobile_phone_id_record(mpi);
    vm_save_user_id_record(uid);
	
	if(vip_response_type == RES_ERROR_CMD)//网络链接错误
	{
	       vm_vam_cancel_sync_cdr();
		//vip_cancel_request_handle(VIP_OTHER_HANDLE);
		if(g_VamTask.sync_cb)
			g_VamTask.sync_cb(VAM_DL_ERR);
		return;
	}
	else if (vip_response_type == RES_RESCONTENT_CMD)
	{
		if(g_VamTask.bChannel)
		{
		#ifdef LOG_AM_DOWNLOAD
		      vm_log_fatal("[AM] parse channel.");
		#endif
			if(nMultiRes)
			{
				memcpy(&bCmd, pResponse, 1);
				pResponse ++;
			}
			if(nMultiRes && bCmd == RES_ERROR_CMD)
			{
                            memcpy(&pError.code, pResponse, 4);
				pResponse += 4;
				memset(str_data/*szData*/, 0, sizeof(str_data/*szData*/));
				memcpy(str_data/*szData*/, pResponse, 4);
				pResponse += 4;
                            vm_vam_int_byte_switch((VMCHAR*)str_data/*szData*/, &strlen, NULL);
				pResponse += (strlen * 2);
			}
			else
			{
				if(nMultiRes)
				  pResponse += 4;

		memcpy(&nUpdateNum,(VMCHAR *)pResponse + unOffset,sizeof(VMCHAR));//更新个数
		unOffset ++;
#ifdef LOG_AM_DOWNLOAD
	    vm_log_fatal("[AM] nUpdateNum = %d", nUpdateNum);
#endif
		for (nIndex = 0; nIndex < nUpdateNum; nIndex ++)
		{
			memcpy(&nCntId,(VMCHAR *)pResponse + unOffset,sizeof(VMCHAR));
			unOffset ++;

			memset(str_data/*szLenByte*/, 0, sizeof(str_data/*szLenByte*/));
			memcpy(str_data/*szLenByte*/, (char*)pResponse + unOffset, 4);//更新数据偏移量
			
			vm_vam_int_byte_switch((VMCHAR*)str_data/*szLenByte*/, &nCntOffset, NULL);
			unOffset += 4;

			switch(nCntId)
			{
			case VRE_SYSTEM_TIME://系统时间
				{
					//vm_time_t system_time;
				    vm_time_t timestamps[5];
#ifdef LOG_AM_DOWNLOAD
					vm_log_fatal("[AM] get system time.");
#endif
					//nSysTimFlag = TRUE;
					if(vm_vam_parse_time_data(&system_time, (VMCHAR *)pResponse + nCntOffset) == 0)
					{
						if (vm_load_timestamps_record(timestamps) == VM_ADAPTER_NVRAM_SUCCESS)
						{
							if (vm_merge_timestamp(timestamps, &system_time, VM_NVRAM_SYSTEM_TIMESTAMP))
								vm_save_timestamps_record(timestamps);
						}
					}					
				}
				break;
			case VRE_PUBLIC_KEY://Public Key
				{
					VMUINT32 unKeyNum = 0;
					VMUINT32 unIndex = 0;
					//VMCHAR szKeyNum[5] = {0};
					//static vm_cert_record pkey_list[ROOT_PK_LIST_SIZE * 2];
					vm_cert_record * pkey_list = NULL;
					static VMCHAR stop_time[15];
					//static vm_time_t pkey_time; 

					pkey_list = g_VamTask.vam_malloc_ex(sizeof(vm_cert_record) * ROOT_PK_LIST_SIZE * 2);
					if(!pkey_list)
					{
					       vm_vam_cancel_sync_cdr();
						return;
					}
					memset(pkey_list, 0, sizeof(vm_cert_record) * ROOT_PK_LIST_SIZE * 2);
#ifdef LOG_AM_DOWNLOAD
					vm_log_fatal("[AM] get public key.");
#endif
					//memset(pkey_list, 0, sizeof(pkey_list));
					memset(time_info, 0, sizeof(time_info));
			        memcpy(time_info, (char*)pResponse  + nCntOffset, 14);
					nCntOffset += 14;
					
					memset(str_data/*szKeyNum*/, 0, sizeof(str_data/*szKeyNum*/)); //读入Public Key个数 
					memcpy(str_data/*szKeyNum*/, (char*)pResponse + nCntOffset, 4);
					vm_vam_int_byte_switch(str_data/*szKeyNum*/, &unKeyNum, NULL);
					nCntOffset += 4;
					
					for(unIndex = 0 ; unIndex < unKeyNum ; unIndex++)
					{
						VMINT cerd_id, mod_len, key_len;
						
						memset(str_data/*szKeyNum*/, 0, sizeof(str_data/*szKeyNum*/));  
						memcpy(str_data/*szKeyNum*/, (char*)pResponse + nCntOffset, 4);
						vm_vam_int_byte_switch(str_data/*szKeyNum*/, (VMUINT32 *)&cerd_id, NULL);
						nCntOffset += 4;
						pkey_list[unIndex].pKey.id = cerd_id;
											
						memset(str_data/*szKeyNum*/, 0, sizeof(str_data/*szKeyNum*/));  
						memcpy(str_data/*szKeyNum*/, (char*)pResponse + nCntOffset, 4);
						vm_vam_int_byte_switch(str_data/*szKeyNum*/, (VMUINT32 *)&mod_len, NULL);
						nCntOffset += 4;
						pkey_list[unIndex].pKey.modlen = mod_len;
						
						//memset(pkey_list[unIndex].pKey.mod, 0, sizeof(pkey_list[unIndex].pKey.mod));
						if(mod_len == 63)
							memcpy(pkey_list[unIndex].pKey.mod + 1, (char*)pResponse + nCntOffset, mod_len);
						else
							memcpy(pkey_list[unIndex].pKey.mod, (char*)pResponse + nCntOffset, mod_len);
						nCntOffset += mod_len;
						
						memset(str_data/*szKeyNum*/, 0, sizeof(str_data/*szKeyNum*/));  
						memcpy(str_data/*szKeyNum*/, (char*)pResponse + nCntOffset, 4);
						vm_vam_int_byte_switch(str_data/*szKeyNum*/, (VMUINT32 *)&key_len, NULL);
						nCntOffset += 4;
						pkey_list[unIndex].pKey.keylen = key_len;
						
						//memset(pkey_list[unIndex].pKey.key, 0, sizeof(pkey_list[unIndex].pKey.key));
						if(key_len == 2)
							memcpy(pkey_list[unIndex].pKey.key + 1, (char*)pResponse + nCntOffset, key_len);
						else
							memcpy(pkey_list[unIndex].pKey.key, (char*)pResponse + nCntOffset, key_len);
						nCntOffset += key_len;
						
						memset(stop_time, 0, sizeof(stop_time));
						memcpy(stop_time, (char*)pResponse + nCntOffset, 14);
					    vm_vam_parse_time_data(&pkey_list[unIndex].timestamp, stop_time);
						//过期时间
						nCntOffset += 14;
						
					}

					if(vm_vam_parse_time_data(&system_time/*pkey_time*/, time_info) == 0)
					{
						vm_time_t timestamps[5];
						if (vm_load_timestamps_record(timestamps) == VM_ADAPTER_NVRAM_SUCCESS)
						{
							if (vm_merge_timestamp(timestamps, &system_time/*pkey_time*/, VM_NVRAM_PUBLIC_CERT_LST_TIMESTAMP))
								vm_save_timestamps_record(timestamps);
						}
					}

					vm_save_cert_lst_records(pkey_list, unKeyNum);

					g_VamTask.vam_free_ex(pkey_list);
					pkey_list = NULL;
				}
					break;
			case VRE_PERMISSION_BLACK_LIST://Permission Black List
				{
					static VMINT8 op_value;
					VMUINT32 unPerBlkNum = 0;
					VMUINT32 unIndex = 0;
					//VMCHAR szPerBlkNum[5] = {0};
					//static sys_permission_record permission_list[SYM_PERMISSION_LEN];
					sys_permission_record * permission_list = NULL;
					//static vm_time_t permission_time;
					static VMUINT32  op_index;

					permission_list = g_VamTask.vam_malloc_ex(sizeof(sys_permission_record) * SYM_PERMISSION_LEN);
					if(!permission_list)
					{
					       vm_vam_cancel_sync_cdr();
						return;
					}
					memset(permission_list, 0, sizeof(sys_permission_record) * SYM_PERMISSION_LEN);
#ifdef LOG_AM_DOWNLOAD
					vm_log_fatal("[AM] get permission black list.");
#endif
					//memset(permission_list, 0, sizeof(permission_list));
                                   memcpy(&time_info, (char*)pResponse + nCntOffset, 14);
					nCntOffset += 14;
					
										
					memset(str_data/*szPerBlkNum*/, 0, sizeof(str_data/*szPerBlkNum*/));  
					memcpy(str_data/*szPerBlkNum*/, (char*)pResponse + nCntOffset, 4);
					vm_vam_int_byte_switch(str_data/*szPerBlkNum*/, &unPerBlkNum, NULL);
					nCntOffset += 4;

					for(unIndex = 0 ; unIndex < unPerBlkNum ; unIndex ++)
					{
						memset(str_data/*szPerBlkNum*/, 0, sizeof(str_data/*szPerBlkNum*/));  
						memcpy(str_data/*szPerBlkNum*/, (char*)pResponse + nCntOffset, 4);
						vm_vam_int_byte_switch(str_data/*szPerBlkNum*/,&op_index, NULL);
						permission_list[unIndex].operate_index = op_index;
						nCntOffset += 4;

						memcpy(&op_value, (char*)pResponse + nCntOffset, 1);
						permission_list[unIndex].permission = op_value;
						nCntOffset += 1;

					}
					
					if(vm_vam_parse_time_data(&system_time/*permission_time*/, time_info) == 0)
					{
						vm_time_t timestamps[5];
						if (vm_load_timestamps_record(timestamps) == VM_ADAPTER_NVRAM_SUCCESS)
						{
							if (vm_merge_timestamp(timestamps, &system_time/*permission_time*/, VM_NVRAM_SYS_PERMISSION_TIMESTAMP))
								vm_save_timestamps_record(timestamps);
						}
					}
					
					
 				  vm_save_sys_permission_lst_records(permission_list, unPerBlkNum);
				  g_VamTask.vam_free_ex(permission_list);
				  permission_list = NULL;
				}
				break;
			case VRE_APPLICATION_BLACK_LIST://Application Black List
				{
					VMUINT32 unAppBlkNum = 0;
					VMUINT32 unIndex = 0;
					//VMCHAR szAppBlkNum[5] = {0};
					//static VMUINT app_ban_list[BAN_LIST_SIZE];
					//static vm_time_t app_ban_time;
					static VMUINT ban_app_id;
					VMUINT * app_ban_list = NULL;

					app_ban_list = g_VamTask.vam_malloc_ex(sizeof(VMUINT32) * BAN_LIST_SIZE);
					if(!app_ban_list)
					{
					       vm_vam_cancel_sync_cdr();
						return;
					}
					memset(app_ban_list, 0, sizeof(VMUINT32) * BAN_LIST_SIZE);
#ifdef LOG_AM_DOWNLOAD
					vm_log_fatal("[AM] get application black list.");
#endif
					memset(app_ban_list, 0, sizeof(app_ban_list));
					memcpy(time_info, (char*)pResponse +  nCntOffset, 14);
				
					nCntOffset += 14;
					
					memset(str_data/*szAppBlkNum*/, 0, sizeof(str_data/*szAppBlkNum*/));  
					memcpy(str_data/*szAppBlkNum*/, (char*)pResponse + nCntOffset, 4);//黑名单个数
					vm_vam_int_byte_switch(str_data/*szAppBlkNum*/, &unAppBlkNum, NULL);
					nCntOffset += 4;
					
					for(unIndex = 0 ; unIndex < unAppBlkNum ; unIndex ++)
					{
						
						memset(str_data/*szAppBlkNum*/, 0, sizeof(str_data/*szAppBlkNum*/));  
						memcpy(str_data/*szAppBlkNum*/, (char*)pResponse + nCntOffset, 4);//黑名单应用id
						vm_vam_int_byte_switch(str_data/*szAppBlkNum*/, (VMUINT32 *)ban_app_id, NULL);
						app_ban_list[unIndex] = ban_app_id;
						nCntOffset += 4;
					}

					if(vm_vam_parse_time_data(&system_time/*app_ban_time*/, time_info) == 0)
					{
						vm_time_t timestamps[5];
						if (vm_load_timestamps_record(timestamps) == VM_ADAPTER_NVRAM_SUCCESS)
						{
							if (vm_merge_timestamp(timestamps, &system_time/*app_ban_time*/, VM_NVRAM_BAN_APP_LST_TIMESTAMP))
								vm_save_timestamps_record(timestamps);
						}
					}
					
				  vm_save_ban_app_lst_records(app_ban_list, unAppBlkNum);

				  g_VamTask.vam_free_ex(app_ban_list);
				  app_ban_list = NULL;
					
				}
				break;
			case VRE_PAYMENT_CHANNEL://计费通道
				{
					VMINT8 group_num;
					VMUINT16 group_id;
					VMUINT32 price;
					
					static VMWCHAR /*temp_sms_id[21], w_sms_id[21],*/ w_sms_content[70], temp_sms_content[70];
					VMINT j, k;
					//static vm_nvram_paychannel_list_ext_t paychannel_list_ext = {0};
					//static vm_nvram_operator_code_list_t operator_code_list = {0};	
					vm_nvram_paychannel_list_ext_t * paychannel_list_ext = NULL;
					vm_nvram_operator_code_list_t * operator_code_list = NULL;
					//rencai.xiao 2010/04/30
					#ifdef AM_DOWNLOAD_PAYMENT_NOTIFICATION
					//static vm_nvram_paychannel_a_list_ext_t paychannel_a_ext = {0};
					VMINT operator_count = 0, operator_index = 0;
					vm_nvram_paychannel_a_list_ext_t  * paychannel_a_ext = NULL; 
					#endif
					VMINT record_num = 0;
					//static vm_time_t paychannel_time;
					VMINT8 operator_num;
					#ifdef AM_SUPPORT_UTF_CHSET
				       static VMUINT8 szUtfContent[80];
					#endif
#ifdef LOG_AM_DOWNLOAD
					vm_log_fatal("[AM] vre payment channel.");
#endif

                                  paychannel_list_ext = g_VamTask.vam_malloc_ex(sizeof(vm_nvram_paychannel_list_ext_t));
                                  if(!paychannel_list_ext)
                                  	{
                                  	       vm_vam_cancel_sync_cdr();
						return;
                                  	}
				       memset(paychannel_list_ext, 0, sizeof(vm_nvram_paychannel_list_ext_t));

				       operator_code_list = g_VamTask.vam_malloc_ex(sizeof(vm_nvram_operator_code_list_t));
					if(!operator_code_list)
					{
					       g_VamTask.vam_free_ex(paychannel_list_ext);
						vm_vam_cancel_sync_cdr();
						return;
					}
					memset(operator_code_list, 0, sizeof(vm_nvram_operator_code_list_t));

				      #ifdef AM_DOWNLOAD_PAYMENT_NOTIFICATION
					  paychannel_a_ext = g_VamTask.vam_malloc_ex(sizeof(vm_nvram_paychannel_a_list_ext_t));
					  if(!paychannel_a_ext)
					  {
					       g_VamTask.vam_free_ex(paychannel_list_ext);
						g_VamTask.vam_free_ex(operator_code_list);
						vm_vam_cancel_sync_cdr();
					  	return;
					  }
					  memset(paychannel_a_ext, 0, sizeof(vm_nvram_paychannel_a_list_ext_t));
				      #endif
					//时间戳
					//memset(paychannel_list, 0, sizeof(paychannel_list));
					memset(time_info, 0, sizeof(time_info));
				    memcpy(time_info, (char*)pResponse +  nCntOffset, 14);
					nCntOffset += 14;
					
					memcpy(&group_num, (char*)pResponse + nCntOffset, 1);//计费通道组内通道的个数
					nCntOffset += 1;
					
					for(j = 0 ; j < group_num ; j ++)
					{
						memset(str_data, 0, sizeof(str_data));
						memcpy(&str_data, (char*)pResponse + nCntOffset, 2);//通道所在的通道组
						vm_vam_int_byte_switch(str_data, NULL, &group_id);
						nCntOffset += 2;
						paychannel_list_ext->paychannel_list_ext[record_num].org_id = group_id;

//						memcpy(&channel_num, (char*)vip_response + nCntOffset, 1);//通道个数
//						nCntOffset += 1;

//						for(k = 0 ; k < channel_num ; k ++)
						{
							VMUINT32 str_len;
							VMUINT32 nData;
							VMUINT8 bData;
														
							//表示通道支持的运营商
							memset(str_data, 0, sizeof(str_data));  
							memcpy(str_data, (char*)pResponse + nCntOffset, 4);
							vm_vam_int_byte_switch(str_data, &nData, NULL);
							paychannel_list_ext->paychannel_list_ext[record_num].operator_bitmap = nData;
							nCntOffset += 4;

                                                 //rencai.xiao 2010/04/30
							#ifdef AM_DOWNLOAD_PAYMENT_NOTIFICATION
							memset(str_data, 0, sizeof(str_data));  
							memcpy(str_data, (char*)pResponse + nCntOffset, 4);
							vm_vam_int_byte_switch(str_data, &nData, NULL);
							paychannel_a_ext->paychannel_a_list_ext[record_num].operator_bitmap2 = nData;
							//paychannel_list_ext.paychannel_list_ext[record_num].operator_bitmap = nData;
							nCntOffset += 4;
							#ifdef LOG_AM_DOWNLOAD
							vm_log_fatal("[AM] operator 1 = %d", nData);
							#endif

							memset(str_data, 0, sizeof(str_data));  
							memcpy(str_data, (char*)pResponse + nCntOffset, 4);
							vm_vam_int_byte_switch(str_data, &nData, NULL);
							paychannel_a_ext->paychannel_a_list_ext[record_num].operator_bitmap3 = nData;
							//paychannel_list_ext.paychannel_list_ext[record_num].operator_bitmap = nData;
							nCntOffset += 4;
							#ifdef LOG_AM_DOWNLOAD
							vm_log_fatal("[AM] operator 2 = %d", nData);
							#endif

							memset(str_data, 0, sizeof(str_data));  
							memcpy(str_data, (char*)pResponse + nCntOffset, 4);
							vm_vam_int_byte_switch(str_data, &nData, NULL);
							paychannel_a_ext->paychannel_a_list_ext[record_num].operator_bitmap4 = nData;
							//paychannel_list_ext.paychannel_list_ext[record_num].operator_bitmap = nData;
							nCntOffset += 4;
							#ifdef LOG_AM_DOWNLOAD
							vm_log_fatal("[AM] operator 3 = %d", nData);
							#endif
							#endif
							
				
							//modified by rencai.xiao 2010/06/03
							#ifdef AM_SUPPORT_TWICE_CONFIRM
							memset(str_data, 0, sizeof(str_data));  
							memcpy(str_data, (char*)pResponse + nCntOffset, 2);
							vm_vam_int_byte_switch(str_data, NULL, &paychannel_list_ext->paychannel_list_ext[record_num].sms_type);//接入号长度
							nCntOffset += 2;
							#else
							//计费通道的类型，1为精确指令，2为模糊指令
							memset(str_data, 0, sizeof(str_data));
							memcpy(&bData, (char*)pResponse + nCntOffset, 1);
							paychannel_list_ext->paychannel_list_ext[record_num].sms_type = bData;
							nCntOffset += 1;
							#endif
							#ifdef LOG_AM_DOWNLOAD
							vm_log_fatal("[AM] sms_type = %d", paychannel_list_ext->paychannel_list_ext[record_num].sms_type);
							#endif

							//表示计费通道的接入号
							memset(str_data, 0, sizeof(str_data));  
							memcpy(str_data, (char*)pResponse + nCntOffset, 4);
							vm_vam_int_byte_switch(str_data, &str_len, NULL);//接入号长度
							nCntOffset += 4;
							//memset(w_sms_id, 0, sizeof(w_sms_id));
							//memset(temp_sms_id, 0, sizeof(temp_sms_id));
							memset(w_sms_content, 0, sizeof(w_sms_content));
							memset(temp_sms_content, 0, sizeof(temp_sms_content));
							//memset(paychannel_list_ext->paychannel_list_ext[record_num].sms_id, 0, sizeof(paychannel_list_ext->paychannel_list_ext[record_num].sms_id));
							memcpy(temp_sms_content/*temp_sms_id*/, (char*)pResponse + nCntOffset, str_len * 2);//接入号
							vm_vam_string_byte_switch(w_sms_content/*w_sms_id*/, temp_sms_content/*temp_sms_id*/);
							vm_ucs2_to_ascii(paychannel_list_ext->paychannel_list_ext[record_num].sms_id ,sizeof(paychannel_list_ext->paychannel_list_ext[record_num].sms_id) ,w_sms_content/*w_sms_id*/);
							nCntOffset += (str_len * 2);

							//计费通道的接入命令
							memset(str_data, 0, sizeof(str_data));  
							memcpy(str_data, (char*)pResponse + nCntOffset, 4);
							vm_vam_int_byte_switch(str_data, &str_len, NULL);//接入命令长度
							nCntOffset += 4;
							memset(w_sms_content, 0, sizeof(w_sms_content));
							memset(temp_sms_content, 0, sizeof(temp_sms_content));
							//memset(paychannel_list_ext->paychannel_list_ext[record_num].sms_content, 0, sizeof(paychannel_list_ext->paychannel_list_ext[record_num].sms_content));
							memcpy(temp_sms_content, (char*)pResponse + nCntOffset, str_len * 2);//接入命令
							vm_vam_string_byte_switch(w_sms_content, temp_sms_content);
							//vm_ucs2_to_gb2312(paychannel_list_ext.paychannel_list_ext[record_num].sms_content, sizeof(paychannel_list_ext.paychannel_list_ext[record_num].sms_content), w_sms_content);
							vm_ucs2_to_ascii(paychannel_list_ext->paychannel_list_ext[record_num].sms_content, sizeof(paychannel_list_ext->paychannel_list_ext[record_num].sms_content), w_sms_content);
							nCntOffset += (str_len * 2);

							//计费通道价格
							memset(str_data, 0, sizeof(str_data));  
							memcpy(str_data, (char*)pResponse + nCntOffset, 4);//价格
							vm_vam_int_byte_switch(str_data, &price, NULL);
							paychannel_list_ext->paychannel_list_ext[record_num].fee = price;
							nCntOffset += 4;
							#ifdef LOG_AM_DOWNLOAD
							vm_log_fatal("[AM] price = %d", price);
							#endif

							//rencai.xiao 2010/04/30
							#ifdef AM_DOWNLOAD_PAYMENT_NOTIFICATION
							memset(str_data, 0, sizeof(str_data));  
							memcpy(str_data, (char*)pResponse + nCntOffset, 4);//价格
							vm_vam_int_byte_switch(str_data, &price, NULL);
							paychannel_a_ext->paychannel_a_list_ext[record_num].fee_actual = price;
							//paychannel_list_ext.paychannel_list_ext[record_num].fee = price;
							nCntOffset += 4;
							#ifdef LOG_AM_DOWNLOAD
							vm_log_fatal("[AM] real price = %d", price);
							#endif
							#endif

							//计费通道的SP的名称
							memset(str_data, 0, sizeof(str_data));  
							memcpy(str_data, (char*)pResponse + nCntOffset, 4);
							vm_vam_int_byte_switch(str_data, &str_len, NULL);//SP名称长度
							nCntOffset += 4;
							memset(w_sms_content, 0, sizeof(w_sms_content));
							memset(temp_sms_content, 0, sizeof(temp_sms_content));
							memset(paychannel_list_ext->paychannel_list_ext[record_num].sp_name, 0, sizeof(paychannel_list_ext->paychannel_list_ext[record_num].sp_name));

							#ifdef AM_SUPPORT_UTF_CHSET
							memset(szUtfContent, 0, sizeof(szUtfContent));
							memcpy(szUtfContent, (char*)pResponse + nCntOffset, str_len);//SP的名称
							vm_chset_convert(VM_CHSET_UTF8, VM_CHSET_UCS2, (VMSTR)szUtfContent, (VMSTR)paychannel_list_ext->paychannel_list_ext[record_num].sp_name, 
								                        sizeof(paychannel_list_ext->paychannel_list_ext[record_num].sp_name));
							nCntOffset += str_len;
							#else
							memcpy(temp_sms_content, (char*)pResponse + nCntOffset, str_len * 2);//SP的名称
							vm_vam_string_byte_switch(paychannel_list_ext->paychannel_list_ext[record_num].sp_name, temp_sms_content);
							nCntOffset += str_len * 2;
							#endif

							//计费通道对应的在移动注册的业务名称
							memset(str_data, 0, sizeof(str_data));  
							memcpy(str_data, (char*)pResponse + nCntOffset, 4);
							vm_vam_int_byte_switch(str_data, &str_len, NULL);//业务名称长度
							nCntOffset += 4;
							memset(w_sms_content, 0, sizeof(w_sms_content));
							memset(temp_sms_content, 0, sizeof(temp_sms_content));
							//memset(paychannel_list_ext->paychannel_list_ext[record_num].service_name, 0, sizeof(paychannel_list_ext->paychannel_list_ext[record_num].service_name));
							#ifdef AM_SUPPORT_UTF_CHSET
							memset(szUtfContent, 0, sizeof(szUtfContent));
							memcpy(szUtfContent, (char*)pResponse + nCntOffset, str_len);//业务名称
							vm_chset_convert(VM_CHSET_UTF8, VM_CHSET_UCS2, (VMSTR)szUtfContent, (VMSTR)paychannel_list_ext->paychannel_list_ext[record_num].service_name, 
								                        sizeof(paychannel_list_ext->paychannel_list_ext[record_num].service_name));
							nCntOffset += str_len;
							#else
							memcpy(temp_sms_content, (char*)pResponse + nCntOffset, str_len * 2);//业务名称
							vm_vam_string_byte_switch(paychannel_list_ext->paychannel_list_ext[record_num].service_name, temp_sms_content);
							nCntOffset += (str_len * 2);
							#endif

							//表示提供计费通道的SP的客服电话
							memset(str_data, 0, sizeof(str_data));  
							memcpy(str_data, (char*)pResponse + nCntOffset, 4);
							vm_vam_int_byte_switch(str_data, &str_len, NULL);//?长度
							nCntOffset += 4;
							memset(w_sms_content, 0, sizeof(w_sms_content));
							memset(temp_sms_content, 0, sizeof(temp_sms_content));
							//memset(paychannel_list_ext->paychannel_list_ext[record_num].customer_number, 0, sizeof(paychannel_list_ext->paychannel_list_ext[record_num].customer_number));
							memcpy(temp_sms_content, (char*)pResponse + nCntOffset, str_len * 2);//SP客服电话
							vm_vam_string_byte_switch(w_sms_content, temp_sms_content);
							//vm_ucs2_to_gb2312(paychannel_list_ext.paychannel_list_ext[record_num].customer_number, sizeof(paychannel_list_ext.paychannel_list_ext[record_num].customer_number), w_sms_content);
							vm_ucs2_to_ascii(paychannel_list_ext->paychannel_list_ext[record_num].customer_number, sizeof(paychannel_list_ext->paychannel_list_ext[record_num].customer_number), w_sms_content);
							nCntOffset += str_len * 2;

							//added by rencai.xiao 2010/06/03 
							#ifdef AM_SUPPORT_TWICE_CONFIRM
							memset(str_data, 0, sizeof(str_data));  
							memcpy(str_data, (char*)pResponse + nCntOffset, 4);
							vm_vam_int_byte_switch(str_data, &str_len, NULL);//?长度
							paychannel_a_ext->paychannel_a_list_ext[record_num].reserv1 = str_len;
							nCntOffset += 4;
							#ifdef LOG_AM_DOWNLOAD
							vm_log_fatal("[AM] day value = %d", strlen);
							#endif

							memset(str_data, 0, sizeof(str_data));  
							memcpy(str_data, (char*)pResponse + nCntOffset, 4);
							vm_vam_int_byte_switch(str_data, &str_len, NULL);//?长度
							paychannel_a_ext->paychannel_a_list_ext[record_num].reserv2 = str_len;
							nCntOffset += 4;
							#ifdef LOG_AM_DOWNLOAD
							vm_log_fatal("[AM] month value = %d", strlen);
							#endif
							#endif
							//rencai.xiao 2010/04/30
							#ifdef AM_DOWNLOAD_PAYMENT_NOTIFICATION
							memset(str_data, 0, sizeof(str_data));  
							memcpy(str_data, (char*)pResponse + nCntOffset, 4);
							vm_vam_int_byte_switch(str_data, &str_len, NULL);//?长度
							//paychannel_a_ext->paychannel_a_list_ext[record_num].reserv1 = str_len;
							nCntOffset += 4;
							#ifdef LOG_AM_DOWNLOAD
							vm_log_fatal("[AM] reserve = %d", strlen);
							#endif

							memset(str_data, 0, sizeof(str_data));  
							memcpy(str_data, (char*)pResponse + nCntOffset, 4);
							vm_vam_int_byte_switch(str_data, &str_len, NULL);//?长度
							//paychannel_a_ext->paychannel_a_list_ext[record_num].reserv2 = str_len;
							nCntOffset += 4;
							#ifdef LOG_AM_DOWNLOAD
							vm_log_fatal("[AM] reserve 1 = %d", strlen);
							#endif
							#endif

							record_num ++;
						}
					}

					if(vm_vam_parse_time_data(&system_time/*paychannel_time*/, time_info) == 0)
					{
						vm_time_t timestamps[5];
						if (vm_load_timestamps_record(timestamps) == VM_ADAPTER_NVRAM_SUCCESS)
						{
							if (vm_merge_timestamp(timestamps, &system_time/*paychannel_time*/, VM_NVRAM_CHARGE_CHANNEL_LST_TIMESTAMP))
								vm_save_timestamps_record(timestamps);
						}
					}

					//保存计费通道
					vm_set_pay_channel_list_ext(paychannel_list_ext);

					//rencai.xiao 2010/04/30
					#ifdef AM_DOWNLOAD_PAYMENT_NOTIFICATION
					vm_set_pay_channel_a_list_ext(paychannel_a_ext);
					#endif
					g_VamTask.vam_free_ex(paychannel_list_ext);
					paychannel_list_ext = NULL;
					#ifdef AM_DOWNLOAD_PAYMENT_NOTIFICATION
					g_VamTask.vam_free_ex(paychannel_a_ext);
					paychannel_a_ext = NULL;
					#endif

					//表示运营商的数量
					memset(str_data, 0, sizeof(str_data));  
					memcpy(&operator_num, (char*)pResponse + nCntOffset, 1);
					//vm_vam_int_byte_switch(str_data, &operator_num, NULL);//读取运营商数量
					#ifdef LOG_AM_DOWNLOAD
					vm_log_fatal("[AM] operator num = %d", operator_num);
					#endif
					nCntOffset += 1;

					//clean the operator code that save in NVRAM. added by rencai.xiao 2010/06/29
					if(operator_num > 0)
					{
					    					memset(operator_code_list, 0, sizeof(vm_nvram_operator_code_list_t));
					    #ifdef AM_DOWNLOAD_PAYMENT_NOTIFICATION
						for(k = 0 ; k < 4; k++)
						{
						   vm_set_operator_code_ext(k, operator_code_list);
						}
					    #else
						vm_set_operator_code(operator_code_list);
					    #endif
					}

					//表示运营商编码
					for(k = 0 ; k < operator_num ; k ++)
					{
						VMUINT32 operator_code_len;
						memset(str_data, 0, sizeof(str_data));  
						memcpy(str_data, (char*)pResponse + nCntOffset, 4);
						vm_vam_int_byte_switch(str_data, &operator_code_len, NULL);//code长度
					    nCntOffset += 4;

						//读取code 
						memset(w_sms_content, 0, sizeof(w_sms_content));
						memset(temp_sms_content, 0, sizeof(temp_sms_content));
						//memset(operator_code_list->operator_code_list[operator_count].operator_code, 0, sizeof(operator_code_list->operator_code_list[operator_count].operator_code));
						memcpy(temp_sms_content, (char*)pResponse + nCntOffset, operator_code_len * 2);//SP客服电话
						vm_vam_string_byte_switch(w_sms_content, temp_sms_content);
						//vm_ucs2_to_gb2312(operator_code_list.operator_code_list[k].operator_code, sizeof(operator_code_list.operator_code_list[k].operator_code), w_sms_content);
						vm_ucs2_to_ascii(operator_code_list->operator_code_list[operator_count].operator_code, sizeof(operator_code_list->operator_code_list[operator_count].operator_code), w_sms_content);
						nCntOffset += (operator_code_len * 2);

						//rencai.xiao 2010/04/30 
						#ifdef AM_DOWNLOAD_PAYMENT_NOTIFICATION
						operator_count ++;
						if(operator_count == NVRAM_OPERATE_CODE_LIST_NUM)
						{
						      VMINT ii;
						      
						      operator_count = 0;
						     vm_set_operator_code_ext(operator_index, operator_code_list);

						     memset(operator_code_list, 0, sizeof(vm_nvram_operator_code_list_t));

						     //for(ii = 0 ; ii < NVRAM_OPERATE_CODE_LIST_NUM ; ii ++)
							// 	memset(operator_code_list.operator_code_list[ii].operator_code, 0, sizeof(operator_code_list.operator_code_list[ii].operator_code));
							 	
						   operator_index++;
						} 
						#endif
					}		

					//rencai.xiao 2010/04/30 
					#ifndef AM_DOWNLOAD_PAYMENT_NOTIFICATION
					//保存运营商表到NVRAM
					vm_set_operator_code(operator_code_list);
					#else
					if(operator_num < NVRAM_OPERATE_CODE_LIST_NUM)
						{
							vm_log_fatal("[AM] vm_set_operator_code_ext operator_index2 = %d", operator_index);
							vm_set_operator_code_ext(operator_index, operator_code_list);
						  operator_index = 0;
						}
					else if((operator_num > NVRAM_OPERATE_CODE_LIST_NUM) && (operator_num % NVRAM_OPERATE_CODE_LIST_NUM) != 0)
					{
						vm_log_fatal("[AM] vm_set_operator_code_ext1 operator_index = %d", operator_index);
						vm_set_operator_code_ext(operator_index, operator_code_list);
						//operator_index ++;
					}
					#endif


					g_VamTask.vam_free_ex(operator_code_list);
					operator_code_list = NULL;

					//rencai.xiao 2010/04/28 download payment notification and rate.
					#ifdef AM_DOWNLOAD_PAYMENT_NOTIFICATION
					{
					   VMUINT32 unRate, unStrLen;
					   //static vm_pay_notification_t pay_notification = {0}; 
					   VMUINT8 * pUtfStr = NULL;
					   vm_pay_notification_t * pay_notification = NULL;
					   //static VMWCHAR szwMccTemp[10], szwMcc[10]; wszData[8], wszTempData
					   VMINT nSaveRet;

					   #ifdef LOG_AM_DOWNLOAD
					   vm_log_fatal("[AM] get payment notification msg.");
					   #endif

					   //rencai.xiao 2010/05/18
					   //memset(&pay_notification, 0, sizeof(pay_notification)); 
					   pay_notification = g_VamTask.vam_malloc_ex(sizeof(vm_pay_notification_t));
					   if(!pay_notification)
					   {
					       vm_vam_cancel_sync_cdr();
					   	return;
					   }
					   memset(pay_notification, 0, sizeof(vm_pay_notification_t));

					   pUtfStr = vm_malloc(AM_TEMP_BUFFER_SIZE);
					   
                                      if(pUtfStr)
                                      {
                                            //get mcc
						   memset(wszTempData/*szwMccTemp*/, 0, sizeof(wszTempData/*szwMccTemp*/));
						   memset(wszData/*szwMcc*/, 0, sizeof(wszData/*szwMcc*/));
						   memset(str_data, 0, sizeof(str_data));
						   memcpy(str_data, (char*)pResponse + nCntOffset, 4);
						   vm_vam_int_byte_switch(str_data, &unStrLen, NULL);
						   nCntOffset += 4;
						   memcpy(wszTempData/*szwMccTemp*/, (char*)pResponse + nCntOffset, unStrLen * 2);
						   vm_vam_string_byte_switch(wszData/*szwMcc*/, wszTempData/*szwMccTemp*/);
						   //memset(pay_notification->mcc, 0, sizeof(pay_notification->mcc));
						   vm_chset_convert(VM_CHSET_UCS2,VM_CHSET_ASCII,(VMCHAR*)wszData/*szwMcc*/,(VMCHAR*)pay_notification->mcc,sizeof(pay_notification->mcc));
						   nCntOffset += (unStrLen * 2);
						   #ifdef LOG_AM_DOWNLOAD
						   vm_log_fatal("[AM] mcc = %s", pay_notification->mcc);
						   #endif
						   
	                                      //get payment rate.
						   memset(str_data, 0, sizeof(str_data));  
						   memcpy(str_data, (char*)pResponse + nCntOffset, 4);
						   vm_vam_int_byte_switch(str_data, &unRate, NULL);//payment rate.
						   nCntOffset += 4;
						   pay_notification->rate = (VMINT)unRate;
						   #ifdef LOG_AM_DOWNLOAD
						   vm_log_fatal("[AM] rate = %d", pay_notification->rate);
						   #endif

						   //get hint title
						   memset(pUtfStr, 0, AM_TEMP_BUFFER_SIZE);
						   memset(str_data, 0, sizeof(str_data));
						   memcpy(str_data, (char*)pResponse + nCntOffset, 4);
						   vm_vam_int_byte_switch(str_data, &unStrLen, NULL);
						   nCntOffset += 4;
						   memcpy(pUtfStr, (char*)pResponse + nCntOffset, unStrLen);
						   //memset(pay_notification->title, 0, sizeof(pay_notification->title));
						   vm_chset_convert(VM_CHSET_UTF8,VM_CHSET_UCS2,(VMCHAR*)pUtfStr,(VMCHAR*)pay_notification->title,sizeof(pay_notification->title));
						   nCntOffset += unStrLen;
#ifdef LOG_AM_DOWNLOAD
			                        vm_log_fatal("[AM] hint title len = %d", unStrLen);
#endif
						   //get hint fee msg.
						   memset(pUtfStr, 0, AM_TEMP_BUFFER_SIZE);
						   memset(str_data, 0, sizeof(str_data));
						   memcpy(str_data, (char*)pResponse + nCntOffset, 4);
						   vm_vam_int_byte_switch(str_data, &unStrLen, NULL);
						   nCntOffset += 4;
						   memcpy(pUtfStr, (char*)pResponse + nCntOffset, unStrLen);
						   //memset(pay_notification->notification1, 0, sizeof(pay_notification->notification1));
						   vm_chset_convert(VM_CHSET_UTF8,VM_CHSET_UCS2,(VMCHAR*)pUtfStr,(VMCHAR*)pay_notification->notification1,sizeof(pay_notification->notification1));
						   nCntOffset += unStrLen;
#ifdef LOG_AM_DOWNLOAD
			                        vm_log_fatal("[AM] hint fee msg len = %d", unStrLen);
#endif

						   //get hint fee wait msg.
						   memset(pUtfStr, 0, AM_TEMP_BUFFER_SIZE);
						   memset(str_data, 0, sizeof(str_data));
						   memcpy(str_data, (char*)pResponse + nCntOffset, 4);
						   vm_vam_int_byte_switch(str_data, &unStrLen, NULL);
						   nCntOffset += 4;
						   memcpy(pUtfStr, (char*)pResponse + nCntOffset, unStrLen);
						   //memset(pay_notification->notification2, 0, sizeof(pay_notification->notification2));
						   vm_chset_convert(VM_CHSET_UTF8,VM_CHSET_UCS2,(VMCHAR*)pUtfStr,(VMCHAR*)pay_notification->notification2,sizeof(pay_notification->notification2));
						   nCntOffset += unStrLen;
#ifdef LOG_AM_DOWNLOAD
			                        vm_log_fatal("[AM] hint fee wait len = %d", unStrLen);
#endif

						   //get fee success msg.
						   memset(pUtfStr, 0, AM_TEMP_BUFFER_SIZE);
						   memset(str_data, 0, sizeof(str_data));
						   memcpy(str_data, (char*)pResponse + nCntOffset, 4);
						   vm_vam_int_byte_switch(str_data, &unStrLen, NULL);
						   nCntOffset += 4;
						   memcpy(pUtfStr, (char*)pResponse + nCntOffset, unStrLen);
						   //memset(pay_notification->notification3, 0, sizeof(pay_notification->notification3));
						   vm_chset_convert(VM_CHSET_UTF8,VM_CHSET_UCS2,(VMCHAR*)pUtfStr,(VMCHAR*)pay_notification->notification3,sizeof(pay_notification->notification3));
						   nCntOffset += unStrLen;
#ifdef LOG_AM_DOWNLOAD
			                        vm_log_fatal("[AM] fee success msg  len = %d", unStrLen);
#endif

						   //get fee failed msg.
						   memset(pUtfStr, 0, AM_TEMP_BUFFER_SIZE);
						   memset(str_data, 0, sizeof(str_data));
						   memcpy(str_data, (char*)pResponse + nCntOffset, 4);
						   vm_vam_int_byte_switch(str_data, &unStrLen, NULL);
						   nCntOffset += 4;
						   memcpy(pUtfStr, (char*)pResponse + nCntOffset, unStrLen);
						   //memset(pay_notification->notification4, 0, sizeof(pay_notification->notification4));
						   vm_chset_convert(VM_CHSET_UTF8,VM_CHSET_UCS2,(VMCHAR*)pUtfStr,(VMCHAR*)pay_notification->notification4,sizeof(pay_notification->notification4));
						   nCntOffset += unStrLen;
#ifdef LOG_AM_DOWNLOAD
			                        vm_log_fatal("[AM] fee failed len = %d", unStrLen);
#endif

						   //get left softkey msg.
						   memset(pUtfStr, 0, AM_TEMP_BUFFER_SIZE);
						   memset(str_data, 0, sizeof(str_data));
						   memcpy(str_data, (char*)pResponse + nCntOffset, 4);
						   vm_vam_int_byte_switch(str_data, &unStrLen, NULL);
						   nCntOffset += 4;
						   memcpy(pUtfStr, (char*)pResponse + nCntOffset, unStrLen);
						   //memset(pay_notification->ok, 0, sizeof(pay_notification->ok));
						   vm_chset_convert(VM_CHSET_UTF8,VM_CHSET_UCS2,(VMCHAR*)pUtfStr,(VMCHAR*)pay_notification->ok,sizeof(pay_notification->ok));
						   nCntOffset += unStrLen;
						   #ifdef LOG_AM_DOWNLOAD
						   	{
						   	   static VMCHAR szLogStr[50];

							   memset(szLogStr, 0, sizeof(szLogStr));
							   vm_chset_convert(VM_CHSET_UCS2, VM_CHSET_ASCII, (VMCHAR*)pay_notification->ok, szLogStr, sizeof(szLogStr));
							   vm_log_fatal("[AM] left softkey msg = %s", szLogStr);
						   	}
						   #endif

						   //get right softkey msg.
						   memset(pUtfStr, 0, AM_TEMP_BUFFER_SIZE);
						   memset(str_data, 0, sizeof(str_data));
						   memcpy(str_data, (char*)pResponse + nCntOffset, 4);
						   vm_vam_int_byte_switch(str_data, &unStrLen, NULL);
						   nCntOffset += 4;
						   memcpy(pUtfStr, (char*)pResponse + nCntOffset, unStrLen);
						   //memset(pay_notification->back, 0, sizeof(pay_notification->back));
						   vm_chset_convert(VM_CHSET_UTF8,VM_CHSET_UCS2,(VMCHAR*)pUtfStr,(VMCHAR*)pay_notification->back,sizeof(pay_notification->back));
						   nCntOffset += unStrLen;

						   #ifdef LOG_AM_DOWNLOAD
						   	{
						   	   static VMCHAR szLogStr[50];

							   memset(szLogStr, 0, sizeof(szLogStr));
							   vm_chset_convert(VM_CHSET_UCS2, VM_CHSET_ASCII, (VMCHAR*)pay_notification->back, szLogStr, sizeof(szLogStr));
							   vm_log_fatal("[AM] right softkey msg = %s", szLogStr);
						   	}
						   #endif

						   //get uint
						   memset(wszTempData/*szwMccTemp*/, 0, sizeof(wszTempData/*szwMccTemp*/));
						   memset(wszData/*szwMcc*/, 0, sizeof(wszData/*szwMcc*/));
						   memset(str_data, 0, sizeof(str_data));
						   memset(pay_notification->currency_unit, 0, sizeof(pay_notification->currency_unit));
						   memcpy(str_data, (char*)pResponse + nCntOffset, 4);
						   vm_vam_int_byte_switch(str_data, &unStrLen, NULL);
						   nCntOffset += 4;
						   memcpy(wszTempData/*szwMccTemp*/, (char*)pResponse + nCntOffset, unStrLen * 2);
						   vm_vam_string_byte_switch(pay_notification->currency_unit, wszTempData/*szwMccTemp*/);
						   
						   nCntOffset += (unStrLen * 2);
						   #ifdef LOG_AM_DOWNLOAD
						   vm_log_fatal("[AM] unit len= %d", unStrLen);
						   #endif

						   //save notification
						   nSaveRet = vm_set_pay_notification(pay_notification);
						   #ifdef LOG_AM_DOWNLOAD
						   vm_log_fatal("[AM] vm_set_pay_notification ret = %d", nSaveRet);
						   #endif
						   g_VamTask.vam_free_ex(pay_notification);
						   pay_notification = NULL;

						   vm_free(pUtfStr);
						   pUtfStr = NULL;
                                      }
					else
					 {
					     //rencai.xiao 2010/05/04
					     //vm_malloc error.
					     vm_vam_cancel_sync_cdr();
	       
		                         if(g_VamTask.sync_cb)
			                      g_VamTask.sync_cb(VAM_DL_ERR);
					    return;
					 }
					}
					#endif

                                  //added by rencai.xiao 2010/06/19 extend pay config.get pre_string and suff_string
					#ifdef AM_SUPPORT_EXTEND_PAY_CONFIG
					{
					     VMUINT8 * pUtfStr = NULL;//utf string buffer
					     VMUINT32 unStrLen;//string length
					     vm_pay_config_ext_t * pay_config_ext = NULL;/*pay config*/
                                        /*malloc memory for utf sting buffer*/
					     pUtfStr = vm_malloc(100);
					     if(!pUtfStr)
					     {
					         /*malloc fail*/

						 /*free memory*/
						 vm_vam_cancel_sync_cdr();
	       
		                             if(g_VamTask.sync_cb)
			                          g_VamTask.sync_cb(VAM_DL_ERR);

						 return;
					     }
					     memset(pUtfStr, 0, 100);

					     /*malloc memory for pay config*/
					     pay_config_ext = vm_malloc(sizeof(vm_pay_config_ext_t));
					     if(!pay_config_ext)
					     {
					         /*malloc fail*/
						 /*free memory*/
						 vm_free(pUtfStr);
						 vm_vam_cancel_sync_cdr();
	       
		                             if(g_VamTask.sync_cb)
			                          g_VamTask.sync_cb(VAM_DL_ERR);

						 return;
					     }
					     memset(pay_config_ext, 0, sizeof(vm_pay_config_ext_t));

					   /*get pay config from nvram*/
                                      if(vm_get_pay_config_ext(pay_config_ext) == TRUE)
                                      {
	                                        /*get pre string length*/
						     memset(str_data, 0, sizeof(str_data));
						     memcpy(str_data, (char*)pResponse + nCntOffset, 4);
						     vm_vam_int_byte_switch(str_data, &unStrLen, NULL);
						     nCntOffset += 4;
						     #ifdef LOG_AM_DOWNLOAD
							 vm_log_fatal("[AM] pre string len = %d", unStrLen);
						     #endif

						    /*get pre string*/
						    memcpy(pUtfStr, (char*)pResponse + nCntOffset, unStrLen);
						    vm_chset_convert(VM_CHSET_UTF8,VM_CHSET_UCS2,(VMCHAR*)pUtfStr,(VMCHAR*)pay_config_ext->pre_string,sizeof(pay_config_ext->pre_string));
						    nCntOffset += unStrLen;
                                              /*get suff string length*/
						     memset(str_data, 0, sizeof(str_data));
						     memcpy(str_data, (char*)pResponse + nCntOffset, 4);
						     vm_vam_int_byte_switch(str_data, &unStrLen, NULL);
						     nCntOffset += 4;
						     #ifdef LOG_AM_DOWNLOAD
							 vm_log_fatal("[AM] suff string len = %d", unStrLen);
						     #endif

						    /*get suff string*/
						    memset(pUtfStr, 0, 100);
						    memcpy(pUtfStr, (char*)pResponse + nCntOffset, unStrLen);
							
						    memset(pay_config_ext->suff_string, 0, sizeof(pay_config_ext->suff_string));
						    vm_chset_convert(VM_CHSET_UTF8,VM_CHSET_UCS2,(VMCHAR*)pUtfStr,(VMCHAR*)pay_config_ext->suff_string,sizeof(pay_config_ext->suff_string));
						    nCntOffset += unStrLen;
						   /*save pay config*/
						  vm_set_pay_config_ext(pay_config_ext);
                                      }
					   /*free memory*/
					   vm_free(pUtfStr);
					   vm_free(pay_config_ext);
					}
					#endif//#ifdef AM_SUPPORT_EXTEND_PAY_CONFIG

				}
				break;
			case VRE_APPSTORE_VERSION://更新标志
				{
					VMINT8 is_need_download;

					memcpy(&is_need_download, (char*)pResponse + nCntOffset, 1);
					nCntOffset ++;
					//nAsDldFlag = (VMINT)is_need_download;
#ifdef LOG_AM_DOWNLOAD
					//vm_log_fatal("[AM] APPSTORE_VERSION Flag = %d", nAsDldFlag);
#endif
				}
				break;
			case VRE_SHOW_FEE_HINT://计费提示标志
				{
				    VMINT8 show_fee_hint;
				    //vm_pay_config_t pay_config;

					memcpy(&show_fee_hint, (char*)pResponse + nCntOffset, 1);
					nCntOffset ++;
#ifdef LOG_AM_DOWNLOAD
					vm_log_fatal("[AM] VRE_SHOW_FEE_HINT show_fee_hint = %d", show_fee_hint);
#endif
                                   /*modified by rencai.xiao 2010/06/21 use extention interface*/
                                   #ifdef AM_SUPPORT_EXTEND_PAY_CONFIG
					if(vm_get_pay_config_ext(&pay_config))
					#else
					if(vm_get_pay_config(&pay_config))
					#endif
					{
						pay_config.sms_notification_flag = show_fee_hint;
						/*modified by rencai.xiao 2010/06/21 use extention interface*/
                                          #ifdef AM_SUPPORT_EXTEND_PAY_CONFIG
						vm_set_pay_config_ext(&pay_config);
						#else
						vm_set_pay_config(&pay_config);
						#endif
					}
				}
				break;

				//added by rencai.xiao 2010/06/03 twice confirm
#ifdef AM_SUPPORT_TWICE_CONFIRM
                   case VRE_TWICE_CONFIRM_INFO://二次确认信息
                   	{
				VMCHAR str_data[5];
				VMUINT32 unConfirmInfo;

				/*modified by rencai.xiao 2010/06/21*/
				#ifdef AM_SUPPORT_EXTEND_PAY_CONFIG
				vm_pay_config_ext_t pay_config;
				#else
				vm_pay_config_t pay_config;
				#endif
				
				memset(str_data, 0, sizeof(str_data));
				memcpy(str_data, (char*)pResponse + nCntOffset, 4);
				vm_vam_int_byte_switch(str_data, &unConfirmInfo, NULL);
				nCntOffset += 4;
				#ifdef LOG_AM_DOWNLOAD
				vm_log_fatal("[AM] unConfirmInfo = %d", unConfirmInfo);
				#endif

				/*modified by rencai.xiao 2010/06/21*/
				#ifdef AM_SUPPORT_EXTEND_PAY_CONFIG
				if(vm_get_pay_config_ext(&pay_config))
				#else
				if(vm_get_pay_config(&pay_config))
				#endif
				{
					pay_config.reserved = unConfirmInfo;
					/*modified by rencai.xiao 2010/06/21*/
				      #ifdef AM_SUPPORT_EXTEND_PAY_CONFIG
					vm_set_pay_config_ext(&pay_config);
				      #else
					vm_set_pay_config(&pay_config);
				      #endif
				}

				#ifdef LOG_AM_DOWNLOAD
					{
						  vm_get_pay_config_ext(&pay_config);
						  vm_log_fatal("[AM] read twice confirm info  from nvram = %d", pay_config.reserved);
					}
					#endif
                   	}
			break;
#endif
			}//switch
		}//nUpdateNum
		}//
}//g_VamTask.bChannel


		//判断有无其它内容
		if(g_VamTask.bChargeDetail)
		{
			VMUINT32 nRetLen;
			//static VMCHAR str_data[5];
#ifdef LOG_AM_DOWNLOAD
      vm_log_fatal("[AM] charge detail.");
#endif
            pResponse = pResponse + nCntOffset;
			nCntOffset = 0;
			if(nMultiRes)
			{
				memcpy(&bCmd, pResponse, 1);
				pResponse ++;
			}
			if(nMultiRes && bCmd == RES_ERROR_CMD)
			{
                memcpy(&pError.code, pResponse, 4);
				pResponse += 4;
				memset(str_data/*szData*/, 0, sizeof(str_data/*szData*/));
				memcpy(str_data/*szData*/, pResponse, 4);
				pResponse += 4;
                vm_vam_int_byte_switch((VMCHAR*)str_data/*szData*/, &strlen, NULL);
				pResponse += (strlen * 2);
			}
			else
			{
				if(nMultiRes)
				   pResponse += 4;

				memset(str_data, 0, sizeof(str_data));  
				memcpy(str_data, (char*)pResponse + nCntOffset, 4);
				vm_vam_int_byte_switch(str_data, &nRetLen, NULL);//code长度
				nCntOffset += 4;

				memset(str_data/*szData*/, 0, sizeof(str_data/*szData*/));
				memset(wszData, 0, sizeof(wszData));
				memset(wszTempData, 0, sizeof(wszTempData));
				memcpy(wszTempData, (char*)pResponse + nCntOffset, nRetLen * 2);
				vm_vam_string_byte_switch(wszData, wszTempData);
				//vm_ucs2_to_gb2312(szData, sizeof(szData), wszData);
				vm_ucs2_to_ascii(str_data/*szData*/, sizeof(/*szData*/str_data), wszData);
				nCntOffset += (nRetLen * 2);
				if(strcmp(str_data/*szData*/, "OK") == 0)
				{
	                            //modified by rencai.xiao 2010/06/19
	                            #ifdef AM_SUPPORT_EXTEND_PAY_CONFIG
					vm_nvram_charge_detail_list_ext_t  * charge_detail = NULL;
					#else
					vm_nvram_charge_detail_list_t * charge_detail = NULL;
					#endif

                                   #ifdef AM_SUPPORT_EXTEND_PAY_CONFIG
					charge_detail = g_VamTask.vam_malloc_ex(sizeof(vm_nvram_charge_detail_list_ext_t) + 1);
					#else
					charge_detail = g_VamTask.vam_malloc_ex(sizeof(vm_nvram_charge_detail_list_t) + 1);
					#endif
					if(!charge_detail)
					{
					   vm_vam_cancel_sync_cdr();
					   return;
					}
					#ifdef AM_SUPPORT_EXTEND_PAY_CONFIG
					memset(charge_detail, 0, sizeof(vm_nvram_charge_detail_list_ext_t) + 1);
					#else
					memset(charge_detail, 0, sizeof(vm_nvram_charge_detail_list_t) + 1);
					#endif

					//rencai.xiao 2010/03/15
					if(g_VamTask.nChargeDetailCount <= AM_NVRAM_READ_MAX_VALUE)
					     //modified by rencai.xiao 2010/06/19 use extention struct
					     #ifdef AM_SUPPORT_EXTEND_PAY_CONFIG
					     charge_detail->charge_detail_ext[0].seq_id = g_VamTask.nChargeSeqID;
					     #else
					     charge_detail->charge_detail[0].seq_id = g_VamTask.nChargeSeqID;
					     #endif
					else
					{
					    VMINT i, nCount = 0;
					    for(i = AM_NVRAM_READ_MAX_VALUE ; i < g_VamTask.nChargeDetailCount ; i ++)
					    {
					    //modified by rencai.xiao 2010/06/19 use extention struct
					     #ifdef AM_SUPPORT_EXTEND_PAY_CONFIG
						 memcpy(&charge_detail->charge_detail_ext[nCount], &charge_detail_list->charge_detail_ext[i], sizeof(charge_detail_list->charge_detail_ext[i]));
					      #else
					       memcpy(&charge_detail->charge_detail[nCount], &charge_detail_list->charge_detail[i], sizeof(charge_detail_list->charge_detail[i]));
					      #endif
						nCount ++;
					    }
					   #ifdef LOG_AM_DOWNLOAD
					   vm_log_fatal("[AM] nCount = %d", nCount);
					   #endif
					}
					//modified by rencai.xiao 2010/06/19 if AM_SUPPORT_EXTEND_PAY_CONFIG is defined, use extention interface.
					#ifdef AM_SUPPORT_EXTEND_PAY_CONFIG
					vm_set_charge_detail_list_ext(charge_detail);
					#else
					vm_set_charge_detail_list(charge_detail);
					#endif
					#ifdef LOG_AM_DOWNLOAD
					vm_log_fatal("[AM] charge detail ok.");
					#endif
					g_VamTask.vam_free_ex(charge_detail);
					charge_detail = NULL;
				}
			}
		}

		if(g_VamTask.bSmsDetail)
		{
			VMUINT32 nRetLen;
			//static VMCHAR str_data[5];
#ifdef LOG_AM_DOWNLOAD
                    vm_log_fatal("[AM] smsDetail.");
#endif
			pResponse = pResponse + nCntOffset;
			nCntOffset = 0;
			if(nMultiRes)
			{
				memcpy(&bCmd, pResponse, 1);
				pResponse ++;
			}
			if(nMultiRes && bCmd == RES_ERROR_CMD)
			{
                memcpy(&pError.code, pResponse, 4);
				pResponse += 4;
				memset(str_data/*szData*/, 0, sizeof(str_data/*szData*/));
				memcpy(str_data/*szData*/, pResponse, 4);
				pResponse += 4;
                vm_vam_int_byte_switch((VMCHAR*)str_data/*szData*/, &strlen, NULL);
				pResponse += (strlen * 2);
			}
			else
			{
				if(nMultiRes)
				   pResponse += 4;

				memset(str_data, 0, sizeof(str_data));  
				memcpy(str_data, (char*)pResponse + nCntOffset, 4);
				vm_vam_int_byte_switch(str_data, &nRetLen, NULL);//code长度
				nCntOffset += 4;
				
				memset(str_data/*szData*/, 0, sizeof(str_data/*szData*/));
				memset(wszData, 0, sizeof(wszData));
				memset(wszTempData, 0, sizeof(wszTempData));
				memcpy(wszTempData, (char*)pResponse + nCntOffset, nRetLen * 2);
				vm_vam_string_byte_switch(wszData, wszTempData);
				//vm_ucs2_to_gb2312(szData, sizeof(szData), wszData);
				vm_ucs2_to_ascii(str_data/*szData*/, sizeof(str_data/*szData*/), wszData);
				nCntOffset += (nRetLen * 2);
				if(strcmp(str_data/*szData*/, "OK") == 0)
				{
					//static vm_nvram_charge_sms_detail_list_t  sms_detail = {0};
					vm_nvram_charge_sms_detail_list_t * sms_detail = NULL;

                                   #ifdef LOG_AM_DOWNLOAD
					vm_log_fatal("[AM] bSmsDetail OK");
					#endif
					sms_detail = g_VamTask.vam_malloc_ex(sizeof(vm_nvram_charge_sms_detail_list_t) + 1);
					if(!sms_detail)
					{
					    vm_vam_cancel_sync_cdr();
					    return;
					}
					memset(sms_detail, 0, sizeof(vm_nvram_charge_sms_detail_list_t) + 1);

					//rencai.xiao 2010/03/15
					if(g_VamTask.nSmsDetailCount <= AM_NVRAM_READ_MAX_VALUE)
					    sms_detail->charge_sms_detail[0].seq_id = g_VamTask.nSmsSeqID;
					else
					{
					   VMINT i, nCount = 0;
					    for(i = AM_NVRAM_READ_MAX_VALUE ; i < g_VamTask.nSmsDetailCount ; i ++)
					    {
					       memcpy(&sms_detail->charge_sms_detail[nCount], &sms_detail_list->charge_sms_detail[i], sizeof(sms_detail_list->charge_sms_detail[i]));
						nCount ++;
					    }
					   #ifdef LOG_AM_DOWNLOAD
					   vm_log_fatal("[AM] nCount = %d", nCount);
					   #endif
					}
					vm_set_charge_sms_detail_list(sms_detail);
					#ifdef LOG_AM_DOWNLOAD
					vm_log_fatal("[AM] Sms detail ok.");
					#endif

					g_VamTask.vam_free_ex(sms_detail);
					sms_detail = NULL;
				}
			}
		}

		if(g_VamTask.bPay)
		{
			//static vm_pay_config_t pay_config;
			
                    VMUINT32 str_len;
			
                   //VMCHAR str_data[5];


#ifdef LOG_AM_DOWNLOAD
                    vm_log_fatal("[AM] pay.");
#endif
			pResponse = pResponse + nCntOffset;
			nCntOffset = 0;
			if(nMultiRes)
			{
				memcpy(&bCmd, pResponse, 1);
				pResponse ++;
			}
			if(nMultiRes && bCmd == RES_ERROR_CMD)
			{
                memcpy(&pError.code, pResponse, 4);
				pResponse += 4;
				memset(str_data/*szData*/, 0, sizeof(str_data/*szData*/));
				memcpy(str_data/*szData*/, pResponse, 4);
				pResponse += 4;
                vm_vam_int_byte_switch((VMCHAR*)str_data/*szData*/, &strlen, NULL);
				pResponse += (strlen * 2);
			}
			else
			{
				if(nMultiRes)
				  pResponse += 4;

				memset(str_data, 0, sizeof(str_data));  
				memcpy(str_data, (char*)pResponse + nCntOffset, 4);
				vm_vam_int_byte_switch(str_data, &str_len, NULL);//code长度
				nCntOffset += 4;
				 /*modified by rencai.xiao 2010/06/21*/
			       #ifdef AM_SUPPORT_EXTEND_PAY_CONFIG
				 if(vm_get_pay_config_ext(&pay_config))
				#else
				if(vm_get_pay_config(&pay_config))
				#endif
				{
					pay_config.user_balance = str_len;
					/*modified by rencai.xiao 2010/06/21*/
			             #ifdef AM_SUPPORT_EXTEND_PAY_CONFIG
					vm_set_pay_config_ext(&pay_config);
				      #else
					vm_set_pay_config(&pay_config);
				      #endif
				}
			}
		}

              //更改更新时间点
              {
                 //static vm_pay_config_t pay_config = {0};
				 
		  /*modified by rencai.xiao 2010/06/21*/
	          #ifdef AM_SUPPORT_EXTEND_PAY_CONFIG
		   if(vm_get_pay_config_ext(&pay_config))
		   #else
                if(vm_get_pay_config(&pay_config))
		   #endif
		 {
			pay_config.update_interval_days = vm_vam_get_today_from_2000() + AM_UPDATE_BILLING_INTERVAL;
			/*modified by rencai.xiao 2010/06/21*/
	              #ifdef AM_SUPPORT_EXTEND_PAY_CONFIG
			vm_set_pay_config_ext(&pay_config);
			#else
			vm_set_pay_config(&pay_config);
			#endif
		 }
              
              }

	#ifdef LOG_AM_DOWNLOAD
	  vm_log_fatal("[AM] VAM_DL_OK.");
	#endif
	       vm_vam_cancel_sync_cdr();
	       //vip_cancel_request_handle(VIP_OTHER_HANDLE);
		if(g_VamTask.sync_cb)
			g_VamTask.sync_cb(VAM_DL_OK);
		
	}//RES_RESCONTENT_CMD
}

//rencai.xiao 2010/03/01
VMINT vm_vam_is_sync_cdr(void)
{
   /*modified by rencai.xiao 2010/06/21*/
#ifdef AM_SUPPORT_EXTEND_PAY_CONFIG
   vm_pay_config_ext_t pay_config;
#else
   vm_pay_config_t pay_config;
#endif
   
#ifdef LOG_AM_DOWNLOAD
   vm_log_fatal("[AM] vm_vam_is_sync_cdr.");
#endif
   g_VamTask.vam_malloc_ex = vm_malloc;
   g_VamTask.vam_free_ex = vm_free;
    /*modified by rencai.xiao 2010/06/21*/
#ifdef AM_SUPPORT_EXTEND_PAY_CONFIG
   if(vm_get_pay_config_ext(&pay_config))
#else
    if(vm_get_pay_config(&pay_config))
#endif
    {
#ifdef LOG_AM_DOWNLOAD
			vm_log_fatal("[AM] update_interval_days = %d, today = %d", pay_config.update_interval_days, vm_vam_get_today_from_2000());
#endif
			if(pay_config.update_interval_days == 0)
				return VAM_RET_TIME_NEED_FOR_SYNC_CDR;
			if((VMUINT)vm_vam_get_today_from_2000() >= pay_config.update_interval_days)
 		   	return VAM_RET_TIME_NEED_FOR_SYNC_CDR;
 	   	else
 	   	{
 	   	   //modified by rencai.xiao 2010/06/19 use extention interface
#ifdef AM_SUPPORT_EXTEND_PAY_CONFIG
		   		vm_nvram_charge_detail_list_ext_t * charge_detail_list = NULL;
		   		charge_detail_list = g_VamTask.vam_malloc_ex(sizeof(vm_nvram_charge_detail_list_ext_t));
#else
 	   	   	vm_nvram_charge_detail_list_t * charge_detail_list = NULL;
 	   	   	charge_detail_list = g_VamTask.vam_malloc_ex(sizeof(vm_nvram_charge_detail_list_t));
#endif

					if(!charge_detail_list)
					{
		   			return VAM_RET_TIME_NEED_FOR_SYNC_CDR;
		   		}
#ifdef AM_SUPPORT_EXTEND_PAY_CONFIG
		   		memset(charge_detail_list, 0, sizeof(vm_nvram_charge_detail_list_ext_t));
#else
					memset(charge_detail_list, 0, sizeof(vm_nvram_charge_detail_list_t));
#endif

//modified by rencai.xiao 2010/06/19 use extention interface
#ifdef AM_SUPPORT_EXTEND_PAY_CONFIG
					if(vm_get_charge_detail_list_ext(charge_detail_list))
#else
					if(vm_get_charge_detail_list(charge_detail_list))
#endif
		   		{
						VMINT i, count = 0;

						for(i = 0 ; i < NVRAM_CHARGE_DETAIL_NUM ; i ++)
						{
							//modified by rencai.xiao 2010/06/19 use extention interface
#ifdef AM_SUPPORT_EXTEND_PAY_CONFIG
			    		if(charge_detail_list->charge_detail_ext[i].seq_id != 0)
#else
			    		if(charge_detail_list->charge_detail[i].seq_id != 0)
#endif
							count ++;
						}

						g_VamTask.vam_free_ex(charge_detail_list);
						charge_detail_list = NULL;
						if(count == NVRAM_CHARGE_DETAIL_NUM)//NVRAM满
							return VAM_RET_NVRAM_NEED_FOR_SYNC_CDR;
		   		}

		   		if(charge_detail_list)
		   		{
						g_VamTask.vam_free_ex(charge_detail_list);
						charge_detail_list = NULL;
		   		}
 		   		return VMM_RET_NO_SYSC_CDR;
 	   	}
    }

   return VMM_RET_NO_SYSC_CDR;
}

//rencai.xiao 2010/03/01
VMINT vm_vam_get_user_balance(VMUINT* user_balance)
{
       /*modified by rencai.xiao 2010/06/21*/
	#ifdef AM_SUPPORT_EXTEND_PAY_CONFIG
	vm_pay_config_ext_t pay_config;
	#else
 	vm_pay_config_t pay_config;
	#endif

	#ifdef LOG_AM_DOWNLOAD
	vm_log_fatal("[AM] vm_vam_get_user_balance");
	#endif
 	
	/*modified by rencai.xiao 2010/06/21*/
	#ifdef AM_SUPPORT_EXTEND_PAY_CONFIG
	if(vm_get_pay_config_ext(&pay_config))
	#else
 	if(vm_get_pay_config(&pay_config))
	#endif
 	{
 	#ifdef LOG_AM_DOWNLOAD
	       vm_log_fatal("[AM] user balance = %d", pay_config.user_balance);
	#endif
	    *user_balance = pay_config.user_balance;
	    return 0;
 		//return pay_config.user_balance;
 	}
 	else
		return -1;
}



/**
  * 解析字符串.并将解析后的字符串copy到新缓存中
  *
  * @param pBuf                    重新组织的新缓存指针
  * @param pData                  待解析的数据指针
  *
  * @return                            成功返回0, 否则返回-1
  */
static VMINT vm_vam_parse_string_data(VMUINT8 *pBuf, VMUINT8 * pData)
{
   VMWCHAR * pTempBuf1 = NULL, * pTempBuf2 = NULL;/*解析用的临时缓存*/
   VMCHAR szData[5];
   VMINT nOffset = 0;
   VMUINT32 nStrLen;

   #ifdef LOG_AM_DOWNLOAD
   vm_log_fatal("[AM] vm_vam_parse_string_data.");
   #endif

   if(!pBuf || !pData)
	   return -1;
	
    /*读取字符串长度*/
   memset(szData, 0, sizeof(szData));
   memcpy(szData, pData + nOffset, 4);
   vm_vam_int_byte_switch(szData, &nStrLen, NULL);
   memcpy(pBuf + nOffset, &nStrLen, 4);
   nOffset += 4;
   #ifdef 	LOG_AM_DOWNLOAD
   vm_log_fatal("[AM] string len = %d", nStrLen);
   #endif
	   
   /*读取字符串*/
   pTempBuf1 = vm_calloc(nStrLen * 2 + 1);
   if(!pTempBuf1)
	   return -1;
   pTempBuf2 = vm_calloc(nStrLen * 2 + 1);
   if(!pTempBuf2)
   {
	   vm_free(pTempBuf1);
	   return -1;
   }
   memcpy(pTempBuf1, pData + nOffset, nStrLen * 2);
   vm_vam_string_byte_switch_ex(pTempBuf2, pTempBuf1, nStrLen);
   memcpy(pBuf + nOffset, pTempBuf2, nStrLen * 2);
   vm_free(pTempBuf1);
   pTempBuf1 = NULL;
   vm_free(pTempBuf2);
   pTempBuf2 = NULL;
   nOffset += (nStrLen * 2);

   return nOffset;
}


/**
  * 解析一整形数据。并将解析的数据copy到新缓存中
  *
  * @param pBuf                       新缓存指针
  * @param pData                     待解析的数据指针
  * 
  * @return                               成功返回0，否则返回-1
  */
static VMINT vm_vam_parse_int_data(VMUINT8 * pBuf, VMUINT8 * pData)
{
	VMCHAR szData[5];
	VMUINT32 nValue;

	if(!pData || !pBuf)
		return -1;

	memset(szData, 0, sizeof(szData));
	memcpy(szData, pData, 4);
	vm_vam_int_byte_switch(szData, &nValue, NULL);
	memcpy(pBuf, &nValue, 4);
	
	return 4;
}


/**
  * 解析网络传下来的文件大小的数据,并将解析的数据copy到新缓存中
  *
  * @param  pBuf               新缓存指针
  * @param  pData             待解析的数据指针
  * @param  nDataLen        待解析的数据长度
  *
  * @return                        成功返回0, 否则返回-1
  */
static VMINT vm_vam_parse_filesize_data(VMUINT8 * pBuf, VMUINT8* pData, VMUINT nDataLen)
{
	VMUINT8 bCount;
	VMINT   nOffset = 0; /*偏移量*/ 
	VMINT i;
	   
	/*读取产品个数*/
    memcpy(&bCount, pData + nOffset, 1);
	memcpy(pBuf + nOffset, &bCount, 1);
	nOffset++;

	/*循环解析数据*/
	for(i = 0 ; i < bCount ; i ++)
	{
	   VMINT nTempOffset;
       /*读取产品编号*/
	   if((nTempOffset = vm_vam_parse_string_data(pBuf + nOffset, pData + nOffset)) < 0)
		   return -1;
	   nOffset += nTempOffset;
	   
	   /*读取产品文件大小*/
       if((nTempOffset = vm_vam_parse_int_data(pBuf + nOffset, pData + nOffset)) < 0)
		   return -1;
	   nOffset += nTempOffset;

	   /*读取文件名*/
	   if((nTempOffset = vm_vam_parse_string_data(pBuf + nOffset, pData + nOffset)) < 0)
		   return -1;
	   nOffset += nTempOffset;
	}

	return 0;
}

/**
 * 检测文件大小回调
 */
static void vm_vam_check_filesize_cb(VMINT uid, VMINT mpi, VMINT vip_response_type, 
						   const void* vip_response, VMUINT response_size)
{
   #ifdef LOG_AM_DOWNLOAD
   vm_log_fatal("[AM] vm_vam_check_filesize_cb vip_response_type = %d", vip_response_type);
   #endif
   if(vip_response_type == RES_RESCONTENT_CMD)
   {
	   /*下载成功*/
	   VMUINT8 * pResponseBuf = NULL; /*保存重新组织后的数据的缓存*/

	   vm_save_mobile_phone_id_record(mpi);
    	   vm_save_user_id_record(uid);

	   /*为缓存分配空间*/
	   pResponseBuf = vm_malloc(response_size + 1);
	   if(!pResponseBuf)
		   g_VamTask.check_size_cb(VAM_DL_ERR, NULL, 0);
	   memset(pResponseBuf, 0, response_size + 1);

	   if(vm_vam_parse_filesize_data(pResponseBuf, (VMUINT8*)vip_response, response_size) < 0)
	   {
		   /*解析数据失败*/
		   vm_free(pResponseBuf);
		   g_VamTask.check_size_cb(VAM_DL_ERR, NULL, 0);
		   return;
	   }   

	   /*将重新组织好的数据传递给调用者*/
	   g_VamTask.check_size_cb(VAM_DL_OK, pResponseBuf, response_size);
	   vm_free(pResponseBuf);
   }
   else
   {
	   /*下载失败*/
	   g_VamTask.check_size_cb(VAM_DL_ERR, (VMUINT8*)vip_response, response_size);
	   vip_cancel_request_handle(VIP_APP_HANDLE);
   }

   /*取消连接*/
   
}


VMINT vm_vam_check_filesize(check_filesize_cb check_cb, VMUINT8 * pCheckList)
{
   VMINT nListLen;
   VMUINT8 * pBuf = NULL;/*临时缓存*/
   VMINT userid, phoneid;/*User ID和Phone ID*/

   if(!check_cb || !pCheckList)
	   return VAM_DL_ERR;

   #ifdef LOG_AM_DOWNLOAD
   vm_log_fatal("[AM] vm_vam_check_filesize");
   #endif

   nListLen = strlen((VMSTR)pCheckList);

   /*长度为0直接返回*/
   if(nListLen == 0)
	   return VAM_DL_ERR;
   g_VamTask.check_size_cb = check_cb;

   /*获取user id 和phone id*/
   if(vm_load_mobile_phone_id_record(&phoneid) != VM_ADAPTER_NVRAM_SUCCESS)
	   phoneid = 0;
   if(vm_load_user_id_record(&userid) != VM_ADAPTER_NVRAM_SUCCESS)
		userid = 0;

   /*初始化VIP*/
   if(vip_init_ext(phoneid, userid, VIP_APP_HANDLE))
	   return VAM_DL_ERR;
   
   /*注册回调*/
   if(register_vip_callback_for_app(vm_vam_check_filesize_cb))
	   return VAM_DL_ERR;

   /*为临时缓存分配空间*/
   pBuf = vm_malloc(nListLen + strlen(VIP_GET_FILESIZE_URL) + 20);
   if(!pBuf)
	   return VAM_DL_ERR;
   memset(pBuf, 0, nListLen + strlen(VIP_GET_FILESIZE_URL) + 20);
   
   /*拼接资源*/
   #ifdef AM_SUPPORT_GZIP
   sprintf((VMSTR)pBuf, "%s?appid=%s&gzip=1", VIP_GET_FILESIZE_URL, pCheckList);
   #else
   sprintf((VMSTR)pBuf, "%s?appid=%s&gzip=0", VIP_GET_FILESIZE_URL, pCheckList);
   #endif
   #ifdef LOG_AM_DOWNLOAD
   vm_log_fatal("[AM] pBuf = %s", pBuf);
   #endif

   /*发起下载请求*/
   if(vip_read_resource((VMSTR)pBuf))
   {
	   /*发起请求失败*/
	   vm_free(pBuf);
	   return VAM_DL_ERR;
   }
   else
   {
	   /*请求成功*/
	   vm_free(pBuf);
	   return VAM_DL_OK;
   }
}


/**
  * 解析dll数据，并将解析数据copy到新缓存
  *
  * @param pBuf                新缓存指针
  * @param pData              待解析数据指针
  * @param nDataLen         待解析数据长度
  *
  * @return                        成功返回0，否则返回-1
  */
static VMINT vm_vam_parse_dll_data(VMUINT8 * pBuf, VMUINT8* pData, VMUINT nDataLen)
{
	VMUINT8 bCount;
	VMINT   nOffset = 0; /*偏移量*/ 
	VMINT i;
	   
	/*读取动态库个数*/
    memcpy(&bCount, pData + nOffset, 1);
	memcpy(pBuf + nOffset, &bCount, 1);
	nOffset++;
	
	/*循环解析数据*/
	for(i = 0 ; i < bCount ; i ++)
	{
		VMINT nTempOffset;
		/*读取动态库编号*/
		if((nTempOffset = vm_vam_parse_string_data(pBuf + nOffset, pData + nOffset)) < 0)
			return -1;
		nOffset += nTempOffset;
		
		/*判断是否需要更新*/
		memcpy(pBuf + nOffset, pData + nOffset, 1);
		nOffset ++;
	}
	
	return 0;
}
static void vm_vam_check_dll_cb(VMINT uid, VMINT mpi, VMINT vip_response_type, 
						   const void* vip_response, VMUINT response_size)
{
       #ifdef LOG_AM_DOWNLOAD
	   vm_log_fatal("[AM] vm_vam_check_dll_cb vip_response_type = %d", vip_response_type);
	#endif
	if(vip_response_type == RES_RESCONTENT_CMD)
	{
		/*下载成功*/
		VMUINT8 * pResponseBuf = NULL; /*保存重新组织后的数据的缓存*/

		vm_save_mobile_phone_id_record(mpi);
    	       vm_save_user_id_record(uid);
		
		/*为缓存分配空间*/
		pResponseBuf = vm_malloc(response_size + 1);
		if(!pResponseBuf)
			g_VamTask.check_dll_cb(VAM_DL_ERR, NULL, 0);
		memset(pResponseBuf, 0, response_size + 1);
		
		if(vm_vam_parse_dll_data(pResponseBuf, (VMUINT8*)vip_response, response_size) < 0)
		{
			/*解析数据失败*/
			vm_free(pResponseBuf);
			g_VamTask.check_dll_cb(VAM_DL_ERR, NULL, 0);
			return;
		}   
		
		/*将重新组织好的数据传递给调用者*/
		g_VamTask.check_dll_cb(VAM_DL_OK, pResponseBuf, response_size);
		vm_free(pResponseBuf);
	}
	else
	{
		/*下载失败*/
		g_VamTask.check_dll_cb(VAM_DL_ERR, (VMUINT8*)vip_response, response_size);
		vip_cancel_request_handle(VIP_APP_HANDLE);
	}
	
	/*取消连接*/
   
}
VMINT vm_vam_check_dll_version(check_dll_version_cb check_dll_cb, VMUINT8 * pCheckList)
{
	VMINT nListLen;
	VMUINT8 * pBuf = NULL;/*临时缓存*/
	VMINT userid, phoneid;/*User ID和Phone ID*/

	#ifdef LOG_AM_DOWNLOAD
	vm_log_fatal("[AM] vm_vam_check_dll_version");
	#endif
	
	if(!check_dll_cb || !pCheckList)
		return VAM_DL_ERR;
	
	nListLen = strlen((VMSTR)pCheckList);
	
	/*长度为0直接返回*/
	if(nListLen == 0)
		return VAM_DL_ERR;
	g_VamTask.check_dll_cb = check_dll_cb;
	
	/*获取user id 和phone id*/
	if(vm_load_mobile_phone_id_record(&phoneid) != VM_ADAPTER_NVRAM_SUCCESS)
		phoneid = 0;
	if(vm_load_user_id_record(&userid) != VM_ADAPTER_NVRAM_SUCCESS)
		userid = 0;
	
	/*初始化VIP*/
	if(vip_init_ext(phoneid, userid, VIP_APP_HANDLE))
		return VAM_DL_ERR;
	
	/*注册回调*/
	if(register_vip_callback_for_app(vm_vam_check_dll_cb))
		return VAM_DL_ERR;
	
	/*为临时缓存分配空间*/
	pBuf = vm_malloc(nListLen + strlen(VIP_CHECK_DLL_VERSION_URL) + 20);
	if(!pBuf)
		return VAM_DL_ERR;
	memset(pBuf, 0, nListLen + strlen(VIP_CHECK_DLL_VERSION_URL) + 20);
	
	/*拼接资源*/
	sprintf((VMSTR)pBuf, "%s?smversion=%s", VIP_CHECK_DLL_VERSION_URL, pCheckList);
	#ifdef LOG_AM_DOWNLOAD
	vm_log_fatal("[AM] pBuf = %s", pBuf);
	#endif
	
	/*发起下载请求*/
	if(vip_read_resource((VMSTR)pBuf))
	{
		/*发起请求失败*/
		vm_free(pBuf);
		return VAM_DL_ERR;
	}
	else
	{
		/*请求成功*/
		vm_free(pBuf);
		return VAM_DL_OK;
   }
}

void vm_vam_cancel_check(void)
{
    #ifdef LOG_AM_DOWNLOAD
	vm_log_fatal("[AM] vm_vam_cancel_check");
    #endif
    vip_cancel_request_handle(VIP_APP_HANDLE);
}

VMWSTR vm_vam_need_update(void)
{
	return NULL;
}

void vm_vam_clean_update(void)
{
	return;
}


void vm_get_buildin_app_array(VMINT** app_array_ptr, VMINT* app_array_len_ptr)
{
#ifdef WIN32
	*app_array_ptr = NULL;
	*app_array_len_ptr = 0;
#else
	int count = vm_init_default_game();
	
	vm_log_debug("vm_get_buildin_app_array game size = %d", count);

	
	if ( count > 0 )
	{
		*app_array_ptr = (VMINT*)vre_buildin_app_array;
		*app_array_len_ptr = count;
	}
	else
	{
		*app_array_ptr = NULL;
		*app_array_len_ptr = 0;
	}
#endif

}

/**
 *  提供给mtk native App 查询VRE是否正在使用MediaBuff。
 *
 *  @return 0=VRE没有使用MediaBuff ， 1=VRE正在运行，并使用了MediaBuff。
 */
VMINT mmi_vre_is_using_media_memory(void)
{
        if (sysconf.memory_provide == MMI_DEVCONFIG_MEMPEY_PROVIDER_MEDIA)
        {
                return vre_running;
        }
        else
        {
                return 0;
        }
}

void vm_release_app_running_infos(vm_running_app_info_t* app_infos)
{
	if (app_infos)
	{
		_vm_kernel_free(app_infos);
	}
}

VMINT vm_terminate_bg_app(VMWSTR filename)
{
	VMINT ret = VM_PMNG_NO_OP_IN_STATUS;

	if (!filename)
	{
		return VM_TERMINATE_ERROR_PARAM;
	}
	
	if ((ret = vm_pmng_destroy_bg_process(filename)) != VM_PMNG_OP_OK)
	{
		switch (ret)
		{
		case VM_PMNG_NO_OP_IN_STATUS:
			return VM_TERMINATE_ERROR_STATUS;
		case VM_PMNG_PROCESS_NO_EXISTS:
			return VM_TERMINATE_NOT_EXISTS;
		}
	}

	return VM_PMNG_OP_OK;
}


/*extern VMUINT8 vm_init_default_game(void);
extern VMUINT8 g_vre_default_game_size;
extern VMUINT8** vre_buildin_app_array;

void vm_get_buildin_app_array(VMINT** app_array_ptr, VMINT* app_array_len_ptr)
{
#ifdef WIN32
	*app_array_ptr = NULL;
	*app_array_len_ptr = 0;
#else
	vm_init_default_game();
	
	if (sysconf.memory_provide == MMI_DEVCONFIG_MEMPEY_PROVIDER_MEDIA)
	{
		*app_array_ptr = NULL;
		*app_array_len_ptr = 0;
	}
	else
	{
		*app_array_ptr = (VMINT*)vre_buildin_app_array;
		*app_array_len_ptr = g_vre_default_game_size;
		vm_log_fatal("g_vre_default_game_size = %d",g_vre_default_game_size);
	}
}	
#endif*/

/**
#if (!defined(__VRE_MEDIA_BUF__) && !defined(WIN32))
	*app_array_ptr = (VMINT*)vre_buildin_app_array;
	*app_array_len_ptr = VRE_BUILDIN_APP_COUNT;
#else
	*app_array_ptr = NULL;
	*app_array_len_ptr = 0;
#endif
*
}*/	


/***********************************************/

#define  VM_PAY_QUERY_OPERATOR_ERROR   -3
#define  VM_PAY_INTERNAL_ERROR   -2
#define  VM_PAY_NOT_FOUND   -1
#define  VM_PAY_DONT_SET   0
#define  VM_PAY_NO_ERROR   1

#define VRE_USE_NEW_APN_STRUCT 
/*
static vm_nvram_paychannel_list_ext_t  paychannel_list_ptr;
static vm_nvram_operator_code_list_t  operator_code_list_ptr;
static vm_pay_config_t  pay_config_ptr;
static vm_pay_notification_t pay_notification_ptr;
static vm_nvram_paychannel_a_list_ext_t  paychannel_a_list_ptr;
static vm_nvram_operator_code_list_t  operator_code_list_ptr2;
static vm_nvram_operator_code_list_t  operator_code_list_ptr3;
static vm_nvram_operator_code_list_t  operator_code_list_ptr4;
static vm_nvram_paychannel_usage_list_t  paychannel_usage_list_ptr;
*/

#define VM_COUNTRY_CHINA
#if defined(__VRE_OVERSEA_VERSION__)
#define VM_COUNTRY_SINGAPORE
#define VM_COUNTRY_GHANA 
#define VM_COUNTRY_INDIA 
#define VM_COUNTRY_MALAYSIA 
#define VM_COUNTRY_THAILAND 
#define VM_COUNTRY_INDONESIA 
#define VM_COUNTRY_VIETNAM 
#define VM_COUNTRY_TURKEY 
#define VM_COUNTRY_RUSSIAN 
#define VM_COUNTRY_UAE 
#define VM_COUNTRY_BANGLADESH 
#define VM_COUNTRY_PAKISTAN 
#define VM_COUNTRY_EGYPT 
#define VM_COUNTRY_IRAN 
#define VM_COUNTRY_NIGERIA 
#define VM_COUNTRY_BRAZIL 
#endif

#ifndef VRE_USE_NEW_APN_STRUCT 
#ifdef VM_COUNTRY_CHINA
	#define VM_CHINA_APN_COUNT 3
	#define VM_CHINA_LOCAL_SETTING 1
	#define VM_CHINA_PAYMENT_COUNT 1
#else
	#define VM_CHINA_APN_COUNT 0
	#define VM_CHINA_LOCAL_SETTING 0
	#define VM_CHINA_PAYMENT_COUNT 0
#endif

#ifdef VM_COUNTRY_SINGAPORE
	#define VM_SINGAPORE_APN_COUNT 4
	#define VM_SINGAPORE_LOCAL_SETTING 1
#else
	#define VM_SINGAPORE_APN_COUNT 0
	#define VM_SINGAPORE_LOCAL_SETTING 0
#endif


#ifdef VM_COUNTRY_GHANA
	#define VM_GHANA_APN_COUNT 0
	#define VM_GHANA_LOCAL_SETTING 1
#else
	#define VM_GHANA_APN_COUNT 0
	#define VM_GHANA_LOCAL_SETTING 0
#endif

#ifdef VM_COUNTRY_INDIA
	#define VM_INDIA_APN_COUNT 134
	#define VM_INDIA_LOCAL_SETTING 2
	#define VM_INDIA_PAYMENT_COUNT 1
#else
	#define VM_INDIA_APN_COUNT 0
	#define VM_INDIA_LOCAL_SETTING 0
	#define VM_INDIA_PAYMENT_COUNT 0
#endif


#ifdef VM_COUNTRY_MALAYSIA
	#define VM_MALAYSIA_APN_COUNT 4
	#define VM_MALAYSIA_LOCAL_SETTING 1
	#define VM_MALAYSIA_PAYMENT_COUNT 1
#else
	#define VM_MALAYSIA_APN_COUNT 0
	#define VM_MALAYSIA_LOCAL_SETTING 0
	#define VM_MALAYSIA_PAYMENT_COUNT 0
#endif


#ifdef VM_COUNTRY_THAILAND
	#define VM_THAILAND_APN_COUNT 4
	#define VM_THAILAND_LOCAL_SETTING 1
	#define VM_THAILAND_PAYMENT_COUNT 1
#else
	#define VM_THAILAND_APN_COUNT 0
	#define VM_THAILAND_LOCAL_SETTING 0
	#define VM_THAILAND_PAYMENT_COUNT 0
#endif


#ifdef VM_COUNTRY_INDONESIA
	#define VM_INDONESIA_APN_COUNT 6
	#define VM_INDONESIA_LOCAL_SETTING 1
	#define VM_INDONESIA_PAYMENT_COUNT 1
#else
	#define VM_INDONESIA_APN_COUNT 0
	#define VM_INDONESIA_LOCAL_SETTING 0
	#define VM_INDONESIA_PAYMENT_COUNT 0
#endif


#ifdef VM_COUNTRY_VIETNAM
	#define VM_VIETNAM_APN_COUNT 5
	#define VM_VIETNAM_LOCAL_SETTING 1
	#define VM_VIETNAM_PAYMENT_COUNT 1
#else
	#define VM_VIETNAM_APN_COUNT 0
	#define VM_VIETNAM_LOCAL_SETTING 0
	#define VM_VIETNAM_PAYMENT_COUNT 0
#endif


#ifdef VM_COUNTRY_TURKEY
	#define VM_TURKEY_APN_COUNT 3
	#define VM_TURKEY_LOCAL_SETTING 1
#else
	#define VM_TURKEY_APN_COUNT 0
	#define VM_TURKEY_LOCAL_SETTING 0
#endif


#ifdef VM_COUNTRY_RUSSIAN
	#define VM_RUSSIAN_APN_COUNT 4
	#define VM_RUSSIAN_LOCAL_SETTING 1
	#define VM_RUSSIAN_PAYMENT_COUNT 1
#else
	#define VM_RUSSIAN_APN_COUNT 0
	#define VM_RUSSIAN_LOCAL_SETTING 0
	#define VM_RUSSIAN_PAYMENT_COUNT 0
#endif


#ifdef VM_COUNTRY_UAE
	#define VM_UAE_APN_COUNT 2
	#define VM_UAE_LOCAL_SETTING 1
#else
	#define VM_UAE_APN_COUNT 0
	#define VM_UAE_LOCAL_SETTING 0
#endif


#ifdef VM_COUNTRY_BANGLADESH
	#define VM_BANGLADESH_APN_COUNT 1
	#define VM_BANGLADESH_LOCAL_SETTING 1
#else
	#define VM_BANGLADESH_APN_COUNT 0
	#define VM_BANGLADESH_LOCAL_SETTING 0
#endif


#ifdef VM_COUNTRY_PAKISTAN
	#define VM_PAKISTAN_APN_COUNT 0
	#define VM_PAKISTAN_LOCAL_SETTING 1
#else
	#define VM_PAKISTAN_APN_COUNT 0
	#define VM_PAKISTAN_LOCAL_SETTING 0
#endif


#ifdef VM_COUNTRY_EGYPT
	#define VM_EGYPT_APN_COUNT 3
	#define VM_EGYPT_LOCAL_SETTING 1
#else
	#define VM_EGYPT_APN_COUNT 0
	#define VM_EGYPT_LOCAL_SETTING 0
#endif


#ifdef VM_COUNTRY_IRAN
	#define VM_IRAN_APN_COUNT 1
	#define VM_IRAN_LOCAL_SETTING 1
#else
	#define VM_IRAN_APN_COUNT 0
	#define VM_IRAN_LOCAL_SETTING 0
#endif


#ifdef VM_COUNTRY_NIGERIA
	#define VM_NIGERIA_APN_COUNT 3
	#define VM_NIGERIA_LOCAL_SETTING 1
	#define VM_NIGERIA_PAYMENT_COUNT 1
#else
	#define VM_NIGERIA_APN_COUNT 0
	#define VM_NIGERIA_LOCAL_SETTING 0
	#define VM_NIGERIA_PAYMENT_COUNT 0
#endif


#ifdef VM_COUNTRY_BRAZIL
	#define VM_BRAZIL_APN_COUNT 9
	#define VM_BRAZIL_LOCAL_SETTING 1
#else
	#define VM_BRAZIL_APN_COUNT 0
	#define VM_BRAZIL_LOCAL_SETTING 0
#endif

#else/*========= Use New Struct============*/
#ifdef VM_COUNTRY_CHINA

	#define VM_CHINA_APN_COUNT 2
	#define VM_CHINA_LOCAL_SETTING 1
	#define VM_CHINA_PAYMENT_COUNT 1
#else
	#define VM_CHINA_APN_COUNT 0
	#define VM_CHINA_LOCAL_SETTING 0
	#define VM_CHINA_PAYMENT_COUNT 0
#endif

#ifdef VM_COUNTRY_SINGAPORE
	#define VM_SINGAPORE_APN_COUNT 2
	#define VM_SINGAPORE_LOCAL_SETTING 1
#else
	#define VM_SINGAPORE_APN_COUNT 0
	#define VM_SINGAPORE_LOCAL_SETTING 0
#endif


#ifdef VM_COUNTRY_GHANA
	#define VM_GHANA_APN_COUNT 0
	#define VM_GHANA_LOCAL_SETTING 1
#else
	#define VM_GHANA_APN_COUNT 0
	#define VM_GHANA_LOCAL_SETTING 0
#endif

#ifdef VM_COUNTRY_INDIA
	#define VM_INDIA_APN_COUNT 10
	#define VM_INDIA_LOCAL_SETTING 2
	#define VM_INDIA_PAYMENT_COUNT 1
#else
	#define VM_INDIA_APN_COUNT 0
	#define VM_INDIA_LOCAL_SETTING 0
	#define VM_INDIA_PAYMENT_COUNT 0
#endif


#ifdef VM_COUNTRY_MALAYSIA
	#define VM_MALAYSIA_APN_COUNT 3
	#define VM_MALAYSIA_LOCAL_SETTING 1
	#define VM_MALAYSIA_PAYMENT_COUNT 1
#else
	#define VM_MALAYSIA_APN_COUNT 0
	#define VM_MALAYSIA_LOCAL_SETTING 0
	#define VM_MALAYSIA_PAYMENT_COUNT 0
#endif


#ifdef VM_COUNTRY_THAILAND
	#define VM_THAILAND_APN_COUNT 3
	#define VM_THAILAND_LOCAL_SETTING 1
	#define VM_THAILAND_PAYMENT_COUNT 1
#else
	#define VM_THAILAND_APN_COUNT 0
	#define VM_THAILAND_LOCAL_SETTING 0
	#define VM_THAILAND_PAYMENT_COUNT 0
#endif


#ifdef VM_COUNTRY_INDONESIA
	#define VM_INDONESIA_APN_COUNT 5
	#define VM_INDONESIA_LOCAL_SETTING 1
	#define VM_INDONESIA_PAYMENT_COUNT 1
#else
	#define VM_INDONESIA_APN_COUNT 0
	#define VM_INDONESIA_LOCAL_SETTING 0
	#define VM_INDONESIA_PAYMENT_COUNT 0
#endif


#ifdef VM_COUNTRY_VIETNAM
	#define VM_VIETNAM_APN_COUNT 5
	#define VM_VIETNAM_LOCAL_SETTING 1
	#define VM_VIETNAM_PAYMENT_COUNT 1
#else
	#define VM_VIETNAM_APN_COUNT 0
	#define VM_VIETNAM_LOCAL_SETTING 0
	#define VM_VIETNAM_PAYMENT_COUNT 0
#endif


#ifdef VM_COUNTRY_TURKEY
	#define VM_TURKEY_APN_COUNT 3
	#define VM_TURKEY_LOCAL_SETTING 1
#else
	#define VM_TURKEY_APN_COUNT 0
	#define VM_TURKEY_LOCAL_SETTING 0
#endif


#ifdef VM_COUNTRY_RUSSIAN
	#define VM_RUSSIAN_APN_COUNT 3
	#define VM_RUSSIAN_LOCAL_SETTING 1
	#define VM_RUSSIAN_PAYMENT_COUNT 1
#else
	#define VM_RUSSIAN_APN_COUNT 0
	#define VM_RUSSIAN_LOCAL_SETTING 0
	#define VM_RUSSIAN_PAYMENT_COUNT 0
#endif


#ifdef VM_COUNTRY_UAE
	#define VM_UAE_APN_COUNT 2
	#define VM_UAE_LOCAL_SETTING 1
#else
	#define VM_UAE_APN_COUNT 0
	#define VM_UAE_LOCAL_SETTING 0
#endif


#ifdef VM_COUNTRY_BANGLADESH
	#define VM_BANGLADESH_APN_COUNT 1
	#define VM_BANGLADESH_LOCAL_SETTING 1
#else
	#define VM_BANGLADESH_APN_COUNT 0
	#define VM_BANGLADESH_LOCAL_SETTING 0
#endif


#ifdef VM_COUNTRY_PAKISTAN
	#define VM_PAKISTAN_APN_COUNT 0
	#define VM_PAKISTAN_LOCAL_SETTING 1
#else
	#define VM_PAKISTAN_APN_COUNT 0
	#define VM_PAKISTAN_LOCAL_SETTING 0
#endif


#ifdef VM_COUNTRY_EGYPT
	#define VM_EGYPT_APN_COUNT 3
	#define VM_EGYPT_LOCAL_SETTING 1
#else
	#define VM_EGYPT_APN_COUNT 0
	#define VM_EGYPT_LOCAL_SETTING 0
#endif


#ifdef VM_COUNTRY_IRAN
	#define VM_IRAN_APN_COUNT 1
	#define VM_IRAN_LOCAL_SETTING 1
#else
	#define VM_IRAN_APN_COUNT 0
	#define VM_IRAN_LOCAL_SETTING 0
#endif


#ifdef VM_COUNTRY_NIGERIA
	#define VM_NIGERIA_APN_COUNT 3
	#define VM_NIGERIA_LOCAL_SETTING 1
	#define VM_NIGERIA_PAYMENT_COUNT 1
#else
	#define VM_NIGERIA_APN_COUNT 0
	#define VM_NIGERIA_LOCAL_SETTING 0
	#define VM_NIGERIA_PAYMENT_COUNT 0
#endif


#ifdef VM_COUNTRY_BRAZIL
	#define VM_BRAZIL_APN_COUNT 4
	#define VM_BRAZIL_LOCAL_SETTING 1
#else
	#define VM_BRAZIL_APN_COUNT 0
	#define VM_BRAZIL_LOCAL_SETTING 0
#endif

#endif


#define VM_APN_ROM_RECORD_COUNT (VM_CHINA_APN_COUNT+VM_SINGAPORE_APN_COUNT+VM_GHANA_APN_COUNT+VM_INDIA_APN_COUNT+VM_MALAYSIA_APN_COUNT+VM_THAILAND_APN_COUNT\
+VM_INDONESIA_APN_COUNT+VM_VIETNAM_APN_COUNT+VM_TURKEY_APN_COUNT+VM_RUSSIAN_APN_COUNT+VM_UAE_APN_COUNT+VM_BANGLADESH_APN_COUNT+VM_PAKISTAN_APN_COUNT+VM_EGYPT_APN_COUNT\
+VM_IRAN_APN_COUNT+VM_NIGERIA_APN_COUNT+VM_BRAZIL_APN_COUNT)

#define VM_LOCAL_ROM_RECORD_COUNT (VM_CHINA_LOCAL_SETTING+VM_SINGAPORE_LOCAL_SETTING+VM_GHANA_LOCAL_SETTING+VM_INDIA_LOCAL_SETTING+VM_MALAYSIA_LOCAL_SETTING+VM_THAILAND_LOCAL_SETTING\
+VM_INDONESIA_LOCAL_SETTING+VM_VIETNAM_LOCAL_SETTING+VM_TURKEY_LOCAL_SETTING+VM_RUSSIAN_LOCAL_SETTING+VM_UAE_LOCAL_SETTING+VM_BANGLADESH_LOCAL_SETTING+VM_PAKISTAN_LOCAL_SETTING+VM_EGYPT_LOCAL_SETTING\
+VM_IRAN_LOCAL_SETTING+VM_NIGERIA_LOCAL_SETTING+VM_BRAZIL_LOCAL_SETTING)

#ifdef VRE_GLOBAL_VERSION
#ifndef VRE_USE_NEW_APN_STRUCT
#if (VM_APN_ROM_RECORD_COUNT == 0)
const vm_apn_info vm_apn_info_table[]={0} ;
#else
const vm_apn_info vm_apn_info_table[] =
{
#ifdef VM_COUNTRY_CHINA
	{1,80,"46000","China Mobile","10.0.0.172","CMWAP","CMNET","","","",""},
	{2,80,"46001","China Unicom","10.0.0.172","UNIWAP","UNINET","","","",""},
	{3,80,"46002","China Mobile","10.0.0.172","CMWAP","CMNET","","","",""},
#endif
#ifdef VM_COUNTRY_SINGAPORE
	{4,80,"52501","SingTel","165.21.42.84","e-ideas","internet","65IDEAS","","65IDEAS",""},
	{5,80,"52502","SingTel","165.21.42.84","e-ideas","internet","65IDEAS","","65IDEAS",""},
	{6,80,"52507","SingTel","165.21.42.84","e-ideas","internet","65IDEAS","","65IDEAS",""},
	{7,80,"52505","STARHUB","10.12.1.2","shwap","shwap","","","",""},
#endif
#ifdef VM_COUNTRY_GHANA
#endif
#ifdef VM_COUNTRY_INDIA
	{8,8080,"40551","AIRTEL","100.001.200.099","airtelfun.com","airtelgprs.com","","","",""},
	{9,8080,"40552","AIRTEL","100.001.200.099","airtelfun.com","airtelgprs.com","","","",""},
	{10,8080,"40553","AIRTEL","100.001.200.099","airtelfun.com","airtelgprs.com","","","",""},
	{11,8080,"40554","AIRTEL","100.001.200.099","airtelfun.com","airtelgprs.com","","","",""},
	{12,8080,"40555","AIRTEL","100.001.200.099","airtelfun.com","airtelgprs.com","","","",""},
	{13,8080,"40556","AIRTEL","100.001.200.099","airtelfun.com","airtelgprs.com","","","",""},
	{14,8080,"40402","AIRTEL","100.001.200.099","airtelfun.com","airtelgprs.com","","","",""},
	{15,8080,"40403","AIRTEL","100.001.200.099","airtelfun.com","airtelgprs.com","","","",""},
	{16,8080,"40410","AIRTEL","100.001.200.099","airtelfun.com","airtelgprs.com","","","",""},
	{17,8080,"40416","AIRTEL","100.001.200.099","airtelfun.com","airtelgprs.com","","","",""},
	{18,8080,"40431","AIRTEL","100.001.200.099","airtelfun.com","airtelgprs.com","","","",""},
	{19,8080,"40440","AIRTEL","100.001.200.099","airtelfun.com","airtelgprs.com","","","",""},
	{20,8080,"40445","AIRTEL","100.001.200.099","airtelfun.com","airtelgprs.com","","","",""},
	{21,8080,"40449","AIRTEL","100.001.200.099","airtelfun.com","airtelgprs.com","","","",""},
	{22,8080,"40470","AIRTEL","100.001.200.099","airtelfun.com","airtelgprs.com","","","",""},
	{23,8080,"40490","AIRTEL","100.001.200.099","airtelfun.com","airtelgprs.com","","","",""},
	{24,8080,"40492","AIRTEL","100.001.200.099","airtelfun.com","airtelgprs.com","","","",""},
	{25,8080,"40493","AIRTEL","100.001.200.099","airtelfun.com","airtelgprs.com","","","",""},
	{26,8080,"40494","AIRTEL","100.001.200.099","airtelfun.com","airtelgprs.com","","","",""},
	{27,8080,"40495","AIRTEL","100.001.200.099","airtelfun.com","airtelgprs.com","","","",""},
	{28,8080,"40496","AIRTEL","100.001.200.099","airtelfun.com","airtelgprs.com","","","",""},
	{29,8080,"40497","AIRTEL","100.001.200.099","airtelfun.com","airtelgprs.com","","","",""},
	{30,8080,"40498","AIRTEL","100.001.200.099","airtelfun.com","airtelgprs.com","","","",""},
	{31,8080,"405800","AIRCEL","172.017.083.069","aircelwap","aircelgprs","","","",""},
	{32,8080,"405801","AIRCEL","172.017.083.069","aircelwap","aircelgprs","","","",""},
	{33,8080,"405802","AIRCEL","172.017.083.069","aircelwap","aircelgprs","","","",""},
	{34,8080,"405803","AIRCEL","172.017.083.069","aircelwap","aircelgprs","","","",""},
	{35,8080,"405804","AIRCEL","172.017.083.069","aircelwap","aircelgprs","","","",""},
	{36,8080,"405805","AIRCEL","172.017.083.069","aircelwap","aircelgprs","","","",""},
	{37,8080,"405806","AIRCEL","172.017.083.069","aircelwap","aircelgprs","","","",""},
	{38,8080,"405807","AIRCEL","172.017.083.069","aircelwap","aircelgprs","","","",""},
	{39,8080,"405808","AIRCEL","172.017.083.069","aircelwap","aircelgprs","","","",""},
	{40,8080,"405809","AIRCEL","172.017.083.069","aircelwap","aircelgprs","","","",""},
	{41,8080,"405810","AIRCEL","172.017.083.069","aircelwap","aircelgprs","","","",""},
	{42,8080,"405811","AIRCEL","172.017.083.069","aircelwap","aircelgprs","","","",""},
	{43,8080,"405812","AIRCEL","172.017.083.069","aircelwap","aircelgprs","","","",""},
	{44,8080,"40429","AIRCEL","172.017.083.069","aircelwap","aircelgprs","","","",""},
	{45,8080,"40433","AIRCEL","172.017.083.069","aircelwap","aircelgprs","","","",""},
	{46,8080,"40435","AIRCEL","172.017.083.069","aircelwap","aircelgprs","","","",""},
	{47,8080,"40437","AIRCEL","172.017.083.069","aircelwap","aircelgprs","","","",""},
	{48,8080,"40441","AIRCEL","172.017.083.069","aircelwap","aircelgprs","","","",""},
	{49,8080,"40442","AIRCEL","172.017.083.069","aircelwap","aircelgprs","","","",""},
	{50,8080,"40491","AIRCEL","172.017.083.069","aircelwap","aircelgprs","","","",""},
	{51,8080,"40409","Reliance","010.239.221.005","rcomwap","SMARTNET","","","",""},
	{52,8080,"40418","Reliance","010.239.221.005","rcomwap","SMARTNET","","","",""},
	{53,8080,"40436","Reliance","010.239.221.005","rcomwap","SMARTNET","","","",""},
	{54,8080,"40450","Reliance","010.239.221.005","rcomwap","SMARTNET","","","",""},
	{55,8080,"40452","Reliance","010.239.221.005","rcomwap","SMARTNET","","","",""},
	{56,8080,"40467","Reliance","010.239.221.005","rcomwap","SMARTNET","","","",""},
	{57,8080,"40483","Reliance","010.239.221.005","rcomwap","SMARTNET","","","",""},
	{58,8080,"40485","Reliance","010.239.221.005","rcomwap","SMARTNET","","","",""},
	{59,8080,"40501","Reliance","010.239.221.005","rcomwap","SMARTNET","","","",""},
	{60,8080,"40505","Reliance","010.239.221.005","rcomwap","SMARTNET","","","",""},
	{61,8080,"40506","Reliance","010.239.221.005","rcomwap","SMARTNET","","","",""},
	{62,8080,"40507","Reliance","010.239.221.005","rcomwap","SMARTNET","","","",""},
	{63,8080,"40509","Reliance","010.239.221.005","rcomwap","SMARTNET","","","",""},
	{64,8080,"40510","Reliance","010.239.221.005","rcomwap","SMARTNET","","","",""},
	{65,8080,"40511","Reliance","010.239.221.005","rcomwap","SMARTNET","","","",""},
	{66,8080,"40513","Reliance","010.239.221.005","rcomwap","SMARTNET","","","",""},
	{67,8080,"40515","Reliance","010.239.221.005","rcomwap","SMARTNET","","","",""},
	{68,8080,"40518","Reliance","010.239.221.005","rcomwap","SMARTNET","","","",""},
	{69,8080,"40519","Reliance","010.239.221.005","rcomwap","SMARTNET","","","",""},
	{70,8080,"40520","Reliance","010.239.221.005","rcomwap","SMARTNET","","","",""},
	{71,8080,"40521","Reliance","010.239.221.005","rcomwap","SMARTNET","","","",""},
	{72,8080,"40522","Reliance","010.239.221.005","rcomwap","SMARTNET","","","",""},
	{73,9401,"40469","MTNL","172.016.039.010","gprsppsmum","gprsmtnldel","mtnl","mtnl123","mtnl","mtnl123"},
	{74,9201,"40468","MTNL","172.016.031.010","gprsppsmum","gprsmtnldel","mtnl","mtnl123","mtnl","mtnl123"},
	{75,9401,"40401","Vodafone","010.010.001.100","portalnmms","www","","","",""},
	{76,9401,"40405","Vodafone","010.010.001.100","portalnmms","www","","","",""},
	{77,9401,"40411","Vodafone","010.010.001.100","portalnmms","www","","","",""},
	{78,9401,"40413","Vodafone","010.010.001.100","portalnmms","www","","","",""},
	{79,9401,"40415","Vodafone","010.010.001.100","portalnmms","www","","","",""},
	{80,9401,"40420","Vodafone","010.010.001.100","portalnmms","www","","","",""},
	{81,9401,"40427","Vodafone","010.010.001.100","portalnmms","www","","","",""},
	{82,9401,"40443","Vodafone","010.010.001.100","portalnmms","www","","","",""},
	{83,9401,"40446","Vodafone","010.010.001.100","portalnmms","www","","","",""},
	{84,9401,"40460","Vodafone","010.010.001.100","portalnmms","www","","","",""},
	{85,9401,"40484","Vodafone","010.010.001.100","portalnmms","www","","","",""},
	{86,9401,"40486","Vodafone","010.010.001.100","portalnmms","www","","","",""},
	{87,9401,"40488","Vodafone","010.010.001.100","portalnmms","www","","","",""},
	{88,9401,"404030","Vodafone","010.010.001.100","portalnmms","www","","","",""},
	{89,9401,"40566","Vodafone","010.010.001.100","portalnmms","www","","","",""},
	{90,9401,"40567","Vodafone","010.010.001.100","portalnmms","www","","","",""},
	{91,9401,"405750","Vodafone","010.010.001.100","portalnmms","www","","","",""},
	{92,9401,"405751","Vodafone","010.010.001.100","portalnmms","www","","","",""},
	{93,9401,"405752","Vodafone","010.010.001.100","portalnmms","www","","","",""},
	{94,9401,"405753","Vodafone","010.010.001.100","portalnmms","www","","","",""},
	{95,9401,"405754","Vodafone","010.010.001.100","portalnmms","www","","","",""},
	{96,9401,"405755","Vodafone","010.010.001.100","portalnmms","www","","","",""},
	{97,9401,"405756","Vodafone","010.010.001.100","portalnmms","www","","","",""},
	{98,9401,"40414","SPICE","010.011.012.013","spice","","","","",""},
	{99,9401,"40444","SPICE","010.011.012.013","spiceexcite","","","","",""},
	{100,8080,"40404","IDEA","010.004.042.015","imis","internet","","","",""},
	{101,8080,"40407","IDEA","010.004.042.015","imis","internet","","","",""},
	{102,8080,"40412","IDEA","010.004.042.015","imis","internet","","","",""},
	{103,8080,"40419","IDEA","010.004.042.015","imis","internet","","","",""},
	{104,8080,"40422","IDEA","010.004.042.015","imis","internet","","","",""},
	{105,8080,"40424","IDEA","010.004.042.015","imis","internet","","","",""},
	{106,8080,"40456","IDEA","010.004.042.015","imis","internet","","","",""},
	{107,8080,"40478","IDEA","010.004.042.015","imis","internet","","","",""},
	{108,8080,"40482","IDEA","010.004.042.015","imis","internet","","","",""},
	{109,8080,"40487","IDEA","010.004.042.015","imis","internet","","","",""},
	{110,8080,"40489","IDEA","010.004.042.015","imis","internet","","","",""},
	{111,8080,"40570","IDEA","010.004.042.015","imis","internet","","","",""},
	{112,8080,"405799","IDEA","010.004.042.015","imis","internet","","","",""},
	{113,8080,"405845","IDEA","010.004.042.015","imis","internet","","","",""},
	{114,8080,"405846","IDEA","010.004.042.015","imis","internet","","","",""},
	{115,8080,"405848","IDEA","010.004.042.015","imis","internet","","","",""},
	{116,8080,"405849","IDEA","010.004.042.015","imis","internet","","","",""},
	{117,8080,"405850","IDEA","010.004.042.015","imis","internet","","","",""},
	{118,8080,"405852","IDEA","010.004.042.015","imis","internet","","","",""},
	{119,8080,"405853","IDEA","010.004.042.015","imis","internet","","","",""},
	{120,9209,"40434","BSNL","10.100.3.2","wapwest.cellone.in","gprsnorth.cellone.in","pp","pp123","pp","pp123"},
	{121,9209,"40438","BSNL","10.100.3.2","wapwest.cellone.in","gprsnorth.cellone.in","pp","pp123","pp","pp123"},
	{122,9209,"40451","BSNL","10.100.3.2","wapwest.cellone.in","gprsnorth.cellone.in","pp","pp123","pp","pp123"},
	{123,9209,"40453","BSNL","10.100.3.2","wapwest.cellone.in","gprsnorth.cellone.in","pp","pp123","pp","pp123"},
	{124,9209,"40454","BSNL","10.100.3.2","wapwest.cellone.in","gprsnorth.cellone.in","pp","pp123","pp","pp123"},
	{125,9209,"40455","BSNL","10.100.3.2","wapwest.cellone.in","gprsnorth.cellone.in","pp","pp123","pp","pp123"},
	{126,9209,"40457","BSNL","10.100.3.2","wapwest.cellone.in","gprsnorth.cellone.in","pp","pp123","pp","pp123"},
	{127,9209,"40458","BSNL","10.100.3.2","wapwest.cellone.in","gprsnorth.cellone.in","pp","pp123","pp","pp123"},
	{128,9209,"40459","BSNL","10.100.3.2","wapwest.cellone.in","gprsnorth.cellone.in","pp","pp123","pp","pp123"},
	{129,9209,"40462","BSNL","10.100.3.2","wapwest.cellone.in","gprsnorth.cellone.in","pp","pp123","pp","pp123"},
	{130,9209,"40464","BSNL","10.100.3.2","wapwest.cellone.in","gprsnorth.cellone.in","pp","pp123","pp","pp123"},
	{131,9209,"40466","BSNL","10.100.3.2","wapwest.cellone.in","gprsnorth.cellone.in","pp","pp123","pp","pp123"},
	{132,9209,"40471","BSNL","10.100.3.2","wapwest.cellone.in","gprsnorth.cellone.in","pp","pp123","pp","pp123"},
	{133,9209,"40472","BSNL","10.100.3.2","wapwest.cellone.in","gprsnorth.cellone.in","pp","pp123","pp","pp123"},
	{134,9209,"40473","BSNL","10.100.3.2","wapwest.cellone.in","gprsnorth.cellone.in","pp","pp123","pp","pp123"},
	{135,9209,"40474","BSNL","10.100.3.2","wapwest.cellone.in","gprsnorth.cellone.in","pp","pp123","pp","pp123"},
	{136,9209,"40475","BSNL","10.100.3.2","wapwest.cellone.in","gprsnorth.cellone.in","pp","pp123","pp","pp123"},
	{137,9209,"40476","BSNL","10.100.3.2","wapwest.cellone.in","gprsnorth.cellone.in","pp","pp123","pp","pp123"},
	{138,9209,"40477","BSNL","10.100.3.2","wapwest.cellone.in","gprsnorth.cellone.in","pp","pp123","pp","pp123"},
	{139,9209,"40479","BSNL","10.100.3.2","wapwest.cellone.in","gprsnorth.cellone.in","pp","pp123","pp","pp123"},
	{140,9209,"40480","BSNL","10.100.3.2","wapwest.cellone.in","gprsnorth.cellone.in","pp","pp123","pp","pp123"},
	{141,8080,"40421","BPL","10.0.0.10 ","mizone","","","","",""},
#endif
#ifdef VM_COUNTRY_MALAYSIA
	{142,80,"50212","MY MAXIS","202.075.133.049","net","","maxis","wap","",""},
	{143,80,"50213","MY CELCOM","010.128.001.242","celcom","","","","",""},
	{144,80,"50219","MY CELCOM","010.128.001.242","celcom","","","","",""},
	{145,80,"50216","DiGi","203.092.128.188","digiwap","","digi","digi","",""},
#endif
#ifdef VM_COUNTRY_THAILAND
	{146,8080,"52010","True","10.4.4.4","wap","internet","true","","true",""},
	{147,8080,"52099","True","10.4.4.4","wap","internet","true","","true",""},
	{148,8080,"52001","AIS GSM","203.170.229.34","wap","internet","","","",""},
	{149,8080,"52018","DTAC","203.155.200.133","wap.djuice.co.th","www.dtac.co.th","","","",""},
#endif
#ifdef VM_COUNTRY_INDONESIA
	{150,8080,"51011","Excelcom","202.152.240.050","www.xlgprs.net","www.xlgprs.net","","","",""},
	{151,9201,"51010","TELKOMSEL","10.1.89.130","telkomsel","telkomsel","","","",""},
	{152,8080,"51001","INDOSAT","10.19.19.19","indosatgprs","indosatgprs","","","",""},
	{153,8080,"51021","INDOSAT","10.19.19.19","indosatgprs","indosatgprs","","","",""},
	{154,3128,"51089","3","10.04.00.10","3gprs","3gprs","3gprs","3gprs","3gprs","3gprs"},
	{155,8080,"51008","axis","10.08.03.08","AXIS","AXIS","axis","123456","axis","123456"},
#endif
#ifdef VM_COUNTRY_VIETNAM
/*	{155,8080,"45201","Mobifone","203.162.021.107","m-wap","m-wap","",""},
	{156,8080,"45205","Vietnamobile","010.010.128.044","internet","internet","",""},
	{157,8000,"45202","Vinaphone","","m3-world","m3-world","",""},
	{158,8080,"45204","Viettel","192.168.233.010","v-internet","v-internet","",""},
	{159,8080,"45207","Beeline","10.16.70.199","internet","internet","",""},*/
	{156,8080,"45201","Mobifone","203.162.021.107","m-wap","m-wap","","","",""},
	{157,8080,"45205","Vietnamobile","010.010.128.044","wap","internet","","","",""},
	{158,8000,"45202","Vinaphone","010.001.010.46","wap","wap","","","",""},
	{159,8080,"45204","Viettel","192.168.233.010","v-wap","v-internet","","","",""},
	{160,8080,"45207","Beeline","010.016.070.199","wap","internet","wap","wap","",""},	
	
#endif
#ifdef VM_COUNTRY_TURKEY
	{161,8080,"28601","Turkcell","212.252.234.168","wap","internet","gprs","gprs","gprs","gprs"},
	{162,9401,"28602","Vodafone TR","212.65.136.226","vflive","internet","vodafone","vodafone","vodafone","vodafone"},
	{163,8080,"28603","AVEA","213.161.151.201","wap","internet","wap","wap","",""},
#endif
#ifdef VM_COUNTRY_RUSSIAN
	{164,8080,"25001","MTS","192.168.192.168","wap.mts.ru","internet.mts.ru","mts","mts","",""},
	{165,8080,"25028","Beeline","192.168.17.1","wap.beeline.ru","internet.beeline.ru","beeline","beeline","beeline","beeline"},
	{166,8080,"25099","Beeline","192.168.17.1","wap.beeline.ru","internet.beeline.ru","beeline","beeline","beeline","beeline"},
	{167,8080,"25002","Megafon","10.77.77.10","wap","internet","wap","wap","",""},
#endif
#ifdef VM_COUNTRY_UAE
	{168,80,"42402","ETISALAT","10.12.0.30","etisalat.ae","mnet","mnet","mnet","mnet","mnet"},
	{169,80,"42403","Du","<BLANK>","internet","du","",""},
#endif
#ifdef VM_COUNTRY_BANGLADESH
	{170,9201,"47001","Grameen Phone","192.168.123.123","Grameen Phone","","","","",""},
#endif
#ifdef VM_COUNTRY_PAKISTAN
#endif
#ifdef VM_COUNTRY_EGYPT
	{171,8080,"60202","Vodafone ","163.121.178.002","wap.vodafone.com.eg","internet.vodafone.net  ","wap","wap","",""},
	{172,8080,"60201","Mobinil","62.241.155.45","mobinilwap","mobinilweb","","","",""},
	{173,8080,"60203","Etisalat","010.071.130.029","etisalat","etisalat","","","",""},
#endif
#ifdef VM_COUNTRY_IRAN
	{174,80,"43235","MTN Irancell","10.131.26.138","mtnirancell","mtnirancell","","","",""},
#endif
#ifdef VM_COUNTRY_NIGERIA
    {175,9201,"62130","MTN","10.199.212.2","web.gprs.mtnnigeria.net","web.gprs.mtnnigeria.net","web","web","web","web"},
    {176,3130,"62150","GLO","10.100.92.22","glogwap","glosecure","wap","wap"},
    {177,9201,"62120","ZAIN","172.18.254.5","wap.ng.zain.com","internet.ng.zain.com","blank","blank","blank","blank"},
#endif
#ifdef VM_COUNTRY_BRAZIL
	{178,3128,"72431","oi","200.222.108.241","wapgprs.oi.com.br","gprs.oi.com.br","oiwap","oioioi","",""},
	{179,80,"72406","Vivo","200.142.130.104","wap.vivo.com.br","zap.vivo.com.br","vivo","vivo","",""},
	{180,80,"72410","Vivo","200.142.130.104","wap.vivo.com.br","zap.vivo.com.br","vivo","vivo","",""},
	{181,80,"72411","Vivo","200.142.130.104","wap.vivo.com.br","zap.vivo.com.br","vivo","vivo","",""},
	{182,80,"72423","Vivo","200.142.130.104","wap.vivo.com.br","zap.vivo.com.br","vivo","vivo","",""},
	{183,8080,"72402","TIM BRASIL","200.244.116.065","wap.tim.br","tim.br","tim","tim","",""},
	{184,8080,"72403","TIM BRASIL","200.244.116.065","wap.tim.br","tim.br","tim","tim","",""},
	{185,8080,"72404","TIM BRASIL","200.244.116.065","wap.tim.br","tim.br","tim","tim","",""},
	{186,8799,"72405","Claro","200.169.126.11","wap.claro.com.br","claro.com.br","claro","claro","",""}
#endif
};
#endif/*(VM_APN_ROM_RECORD_COUNT == 0)*/


//存放当前APN
vm_apn_info vm_current_apn_info ={-1,80,"46000","AM ACCOUNT","10.0.0.172","cmwap","cmnet","",""};

#else/*VRE_USE_NEW_APN_STRUCT*/

#if (VM_APN_ROM_RECORD_COUNT == 0)
const vm_apn_info_internal vm_apn_info_table_internal[]={0} ;
#else
const vm_apn_info_internal vm_apn_info_table_internal[] =
{
#ifdef VM_COUNTRY_CHINA
    {80,"46000,46002","China Mobile","10.0.0.172","CMWAP","CMNET","","","",""},
    {80,"46001","China Unicom","10.0.0.172","UNIWAP","UNINET","","","",""},
#endif
#ifdef VM_COUNTRY_SINGAPORE
	{80,"52501,52502,52507","SingTel","165.21.42.84","e-ideas","internet","65IDEAS","","65IDEAS",""},
	{80,"52505","STARHUB","10.12.1.2","shwap","shwap","","","",""},
#endif
#ifdef VM_COUNTRY_GHANA
#endif
#ifdef VM_COUNTRY_INDIA
	{8080,
	"40551,40552,40553,40554,40555,40556,40402,40403,40410,40416,40431,40440,40445,40449,40470,40490,40492,40493,40494,40495,40496,40497,40498",
	"AIRTEL","100.001.200.099","airtelfun.com","airtelgprs.com","","","",""},
	{8080,
	"405800,405801,405802,405803,405805,405806,405807,405808,405809,405810,405811,405812,40429,40433,40435,40437,40441,40442,40491",
	"AIRCEL","172.017.083.069","aircelwap","aircelgprs","","","",""},
	{8080,
	"40409,40418,40436,40450,40452,40467,40483,40485,40501,40505,40506,40507,40509,40510,40511,40513,40515,40518,40519,40520,40521,40522",
	"Reliance","010.239.221.005","rcomwap","SMARTNET","","","",""},
    {9401,
	"40469,40468",
	"MTNL","172.016.039.010","gprsppsmum","gprsmtnldel","mtnl","mtnl123","mtnl","mtnl123"},
	{9401,
	"40401,40405,40411,40413,40415,40420,40427,40443,40446,40460,40484,40486,40488,404030,40566,40567,405750,405751,405752,405753,405754,405755,405756",
	"Vodafone","010.010.001.100","portalnmms","www","","","",""},
	{9401,"40414","SPICE","010.011.012.013","spice","","","","",""},
	{9401,"40444","SPICE","010.011.012.013","spiceexcite","","","","",""},
	{8080,
	"40404,40407,40412,40419,40422,40424,40456,40478,40482,40487,40489,40570,405799,405845,405846,405848,405849,405850,405852,405853",
	"IDEA","010.004.042.015","imis","internet","","","",""},
	{9209,"40434,40438,40451,40453,40454,40455,40457,40458,40459,40462,40464,40466,40471,40472,40473,40474,40475,40476,40477,40479,40480",
	"BSNL","10.100.3.2","wapwest.cellone.in","gprsnorth.cellone.in","pp","pp123","pp","pp123"},
	{8080,"40421","BPL","10.0.0.10 ","mizone","","","","",""},
#endif
#ifdef VM_COUNTRY_MALAYSIA
	{80,"50212","MY MAXIS","202.075.133.049","net","","maxis","wap","",""},
	{80,"50213,50219","MY CELCOM","010.128.001.242","celcom","","","","",""},
	{80,"50216","DiGi","203.092.128.188","digiwap","","digi","digi","",""},
#endif
#ifdef VM_COUNTRY_THAILAND
	{8080,"52010,52099","True","10.4.4.4","wap","internet","true","","true",""},
	{8080,"52001","AIS GSM","203.170.229.34","wap","internet","","","",""},
	{8080,"52018","DTAC","203.155.200.133","wap.djuice.co.th","www.dtac.co.th","","","",""},
#endif
#ifdef VM_COUNTRY_INDONESIA
	{8080,"51011","Excelcom","202.152.240.050","www.xlgprs.net","www.xlgprs.net","","","",""},
	{8080,"51010","TELKOMSEL","10.1.89.130","telkomsel","telkomsel","","","",""},
	{8080,"51001,51021","INDOSAT","10.19.19.19","indosatgprs","indosatgprs","","","",""},
	{3128,"51089","3","10.04.00.10","3gprs","3gprs","3gprs","3gprs","3gprs","3gprs"},
	{8080,"51008","axis","10.08.03.08","AXIS","AXIS","axis","123456","axis","123456"},
#endif
#ifdef VM_COUNTRY_VIETNAM
	{8080,"45201","Mobifone","203.162.021.107","m-wap","m-wap","","","",""},
	{8080,"45205","Vietnamobile","010.010.128.044","wap","internet","","","",""},
	{8000,"45202","Vinaphone","010.001.010.46","wap","wap","","","",""},
	{8080,"45204","Viettel","192.168.233.010","v-wap","v-internet","","","",""},
	{8080,"45207","Beeline","010.016.070.199","wap","internet","wap","wap","",""},
#endif
#ifdef VM_COUNTRY_TURKEY
	{8080,"28601","Turkcell","212.252.234.168","wap","internet","gprs","gprs","gprs","gprs"},
	{9401,"28602","Vodafone TR","212.65.136.226","vflive","internet","vodafone","vodafone","vodafone","vodafone"},
	{8080,"28603","AVEA","213.161.151.201","wap","internet","wap","wap","",""},
#endif
#ifdef VM_COUNTRY_RUSSIAN
	{8080,"25001","MTS","192.168.192.168","wap.mts.ru","internet.mts.ru","mts","mts","",""},
	{8080,"25028,25099","Beeline","192.168.17.1","wap.beeline.ru","internet.beeline.ru","beeline","beeline","beeline","beeline"},
	{8080,"25002","Megafon","10.77.77.10","wap","internet","wap","wap","",""},
#endif
#ifdef VM_COUNTRY_UAE
	{80,"42402","ETISALAT","10.12.0.30","etisalat.ae","mnet","mnet","mnet","mnet","mnet"},
	{80,"42403","Du","<BLANK>","internet","du","",""},
#endif
#ifdef VM_COUNTRY_BANGLADESH
	{9201,"47001","Grameen Phone","192.168.123.123","Grameen Phone","","","","",""},
#endif
#ifdef VM_COUNTRY_PAKISTAN
#endif
#ifdef VM_COUNTRY_EGYPT
	{8080,"60202","Vodafone ","163.121.178.002","wap.vodafone.com.eg","internet.vodafone.net  ","wap","wap","",""},
	{8080,"60201","Mobinil","62.241.155.45","mobinilwap","mobinilweb","","","",""},
	{8080,"60203","Etisalat","010.071.130.029","etisalat","etisalat","","","",""},
#endif
#ifdef VM_COUNTRY_IRAN
	{80,"43235","MTN Irancell","10.131.26.138","mtnirancell","mtnirancell","","","",""},
#endif
#ifdef VM_COUNTRY_NIGERIA
    {9201,"62130","MTN","10.199.212.2","web.gprs.mtnnigeria.net","web.gprs.mtnnigeria.net","web","web","web","web"},
    {3130,"62150","GLO","10.100.92.22","glogwap","glosecure","wap","wap","",""},
    {9201,"62120","ZAIN","172.18.254.5","wap.ng.zain.com","internet.ng.zain.com","blank","blank","blank","blank"},
#endif
#ifdef VM_COUNTRY_BRAZIL
	{3128,"72431","oi","200.222.108.241","wapgprs.oi.com.br","gprs.oi.com.br","oiwap","oioioi","",""},
	{80,"72406,72410,72411,72423","Vivo","200.142.130.104","wap.vivo.com.br","zap.vivo.com.br","vivo","vivo","",""},
	{8080,"72402,72403,72404","TIM BRASIL","200.244.116.065","wap.tim.br","tim.br","tim","tim","",""},
	{8799,"72405","Claro","200.169.126.11","wap.claro.com.br","claro.com.br","claro","claro","",""}
#endif
};

#endif

#endif/*VRE_USE_NEW_APN_STRUCT*/

//存放当前APN
vm_apn_info vm_current_apn_info ={-1,80,"46000","AM ACCOUNT","10.0.0.172","cmwap","cmnet","","","",""};

//存放用户输入的APN
vm_apn_info vm_user_apn_info = {-1,0,"","","","","","","","",""};




#if  (VM_LOCAL_ROM_RECORD_COUNT == 0)
const vm_local_info vm_local_info_table[] = {0};
#else
const vm_local_info vm_local_info_table[] = 
{
#ifdef VM_COUNTRY_CHINA
#if defined(__VRE_OVERSEA_VERSION__)
    {0,
#if defined(__MMI_LANG_SM_CHINESE__)
    VM_CHINA_SIMPLE_LANGUAGE,
#else
    VM_ENGLISH_LANGUAGE,
#endif
    "460","http://gate.vspace.net.cn:9999/vresps/provision"},//China
#else
	{0,
#if defined(__MMI_LANG_SM_CHINESE__)
    VM_CHINA_SIMPLE_LANGUAGE,
#else
    VM_ENGLISH_LANGUAGE,
#endif
	"460","http://as.vspace.net.cn:9999/vresps/provision"},//China
#endif
#endif
#ifdef VM_COUNTRY_SINGAPORE
	{1,VM_ENGLISH_LANGUAGE,"525","http://gate.vspace.net.cn:9999/vresps/provision"},//Singapore
#endif
#ifdef VM_COUNTRY_GHANA
	{2,VM_ENGLISH_LANGUAGE,"620","http://gate.vspace.net.cn:9999/vresps/provision"},//Ghana
#endif
#ifdef VM_COUNTRY_INDIA
	{3,VM_HINDI_LANGUAGE,"404","http://gate.vspace.net.cn:9999/vresps/provision"},//India
#endif
#ifdef VM_COUNTRY_INDIA
	{4,VM_HINDI_LANGUAGE,"405","http://gate.vspace.net.cn:9999/vresps/provision"},//India
#endif
#ifdef VM_COUNTRY_MALAYSIA
	{5,VM_MALAYSIA_LANGUAGE,"502","http://gate.vspace.net.cn:9999/vresps/provision"},//Malaysia
#endif
#ifdef VM_COUNTRY_THAILAND
	{6,VM_THAILAND_LANGUAGE,"520","http://gate.vspace.net.cn:9999/vresps/provision"},//Thailand
#endif
#ifdef VM_COUNTRY_INDONESIA
	{7,VM_INDONESIA_LANGUAGE,"510","http://gate.vspace.net.cn:9999/vresps/provision"},//Indonesia
#endif
#ifdef VM_COUNTRY_VIETNAM
	{8,VM_VIETNAMESE_LANGUAGE,"452","http://gate.vspace.net.cn:9999/vresps/provision"},//Vietnam
#endif
#ifdef VM_COUNTRY_TURKEY
	{9,VM_TURKEY_LANGUAGE,"286","http://gate.vspace.net.cn:9999/vresps/provision"},//Turkey
#endif
#ifdef VM_COUNTRY_RUSSIAN
	{10,VM_RUSSIA_LANGUAGE,"250","http://gate.vspace.net.cn:9999/vresps/provision"},//Russian
#endif
#ifdef VM_COUNTRY_UAE
	{11,VM_ARABIAN_LANGUAGE,"424","http://gate.vspace.net.cn:9999/vresps/provision"},//United
#endif
#ifdef VM_COUNTRY_BANGLADESH
	{12,VM_ENGLISH_LANGUAGE,"470","http://gate.vspace.net.cn:9999/vresps/provision"},//Bangladesh
#endif
#ifdef VM_COUNTRY_PAKISTAN
	{13,VM_ENGLISH_LANGUAGE,"410","http://gate.vspace.net.cn:9999/vresps/provision"},//Pakistan
#endif
#ifdef VM_COUNTRY_EGYPT
	{14,VM_ARABIAN_LANGUAGE,"602","http://gate.vspace.net.cn:9999/vresps/provision"},//Egypt
#endif
#ifdef VM_COUNTRY_IRAN
	{15,VM_IRAN_LANGUAGE,"432","http://gate.vspace.net.cn:9999/vresps/provision"},//Iran
#endif
#ifdef VM_COUNTRY_NIGERIA
	{16,VM_ENGLISH_LANGUAGE,"621","http://gate.vspace.net.cn:9999/vresps/provision"},//Nigeria
#endif
#ifdef VM_COUNTRY_BRAZIL
	{17,VM_PORTUGUESE_LANGUAGE,"724","http://gate.vspace.net.cn:9999/vresps/provision"}//Brazil
#endif
};

#endif


const vm_local_info vm_default_local_info = 
#if defined(__VRE_OVERSEA_VERSION__)
{0,VM_DEFAULT_ENGLISH_LANGUAGE,"000","http://gate.vspace.net.cn:9999/vresps/provision"};
#else
{0,VM_DEFAULT_ENGLISH_LANGUAGE,"000","http://as.vspace.net.cn:9999/vresps/provision"};
#endif




#define  VM_PAY_INFO_LEN   (VM_VIETNAM_PAYMENT_COUNT+VM_NIGERIA_PAYMENT_COUNT+VM_THAILAND_PAYMENT_COUNT\
+VM_INDONESIA_PAYMENT_COUNT+VM_MALAYSIA_PAYMENT_COUNT+VM_RUSSIAN_PAYMENT_COUNT+VM_INDIA_PAYMENT_COUNT+VM_CHINA_PAYMENT_COUNT)

#if (VM_PAY_INFO_LEN == 0)
const vm_payment_info_t  vm_payment_info[]={0};
const vm_payment_info_csr_t vm_payment_info_csr[]={0};
#else

#ifdef VM_COUNTRY_VIETNAM

const vm_pay_notification_t vm_notification1=
	{
		0,
		{'4', '5', '2', 0},
		{
		0x0052, 0x0061, 0x0074, 0x0065, 0x0073, 0x0020, 0x0050, 0x0072, 0x006f, 0x006d, 0x0070, 0x0074, 0x0065, 0x0064, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x004f, 0x004b, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x0042, 0x0061, 0x0063, 0x006b, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x0059, 0x006f, 0x0075, 0x0020, 0x0077, 0x0069, 0x006c, 0x006c, 0x0020, 0x0070, 0x0075, 0x0072, 0x0063, 0x0068, 0x0061, 0x0073, 0x0065, 0x0020, 0x005f, 0x005f, 0x0067, 0x006f, 0x006f, 0x0064, 0x006e, 0x0061, 0x006d, 0x0065, 0x005f, 0x005f, 0x002c, 0x0020,
		0x0074, 0x0068, 0x0065, 0x0020, 0x0070, 0x0072, 0x0069, 0x0063, 0x0065, 0x0020, 0x0069, 0x0073, 0x0020, 0x005f, 0x0067, 0x006f, 0x006f, 0x0064, 0x0070, 0x0072, 0x0069, 0x0063, 0x0065, 0x005f, 0x0064, 0x006f, 0x006e, 0x0067, 0x002c, 0x0020, 0x0077, 0x006f,
		0x0075, 0x006c, 0x0064, 0x0020, 0x0079, 0x006f, 0x0075, 0x0020, 0x0062, 0x0075, 0x0079, 0x003f, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x0043, 0x0068, 0x0061, 0x0072, 0x0067, 0x0069, 0x006e, 0x0067, 0x002c, 0x0020, 0x0070, 0x006c, 0x0065, 0x0061, 0x0073, 0x0065, 0x0020, 0x0077, 0x0061, 0x0069, 0x0074, 0x0020, 0x002e, 0x002e, 0x002e, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x0043, 0x0068, 0x0061, 0x0072, 0x0067, 0x0069, 0x006e, 0x0067, 0x0020, 0x0073, 0x0075, 0x0063, 0x0065, 0x0073, 0x0073, 0x0066, 0x0075, 0x006c, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x0043, 0x0068, 0x0061, 0x0072, 0x0067, 0x0069, 0x006e, 0x0067, 0x0020, 0x0066, 0x0061, 0x0069, 0x006c, 0x0075, 0x0072, 0x0065, 0x002c, 0x0020, 0x0070, 0x006c, 0x0065, 0x0061, 0x0073, 0x0065, 0x0020, 0x0074, 0x0072, 0x0079, 0x0020, 0x0061, 0x0067, 0x0061,
		0x0069, 0x006e, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x0064, 0x006f, 0x006e, 0x0067, 0, 0, 0, 0, 0, 0
		}
	};
const vm_paychannel_ext_t vm_paychannel_info1[]=
	{
		{
		1,
		100,
		514,
		1,
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'8', '7', '4', '0', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'Z', 'F', 'V', 'N', 'V', 'T', 'L', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
		2,
		100,
		514,
		1,
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'8', '7', '4', '0', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'Z', 'F', 'V', 'N', 'M', 'B', 'F', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
		4,
		100,
		514,
		1,
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'8', '7', '4', '0', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'Z', 'F', 'V', 'N', 'V', 'N', 'P', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
		8,
		100,
		514,
		1,
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'8', '7', '4', '0', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'Z', 'F', 'V', 'N', 'S', 'F', 'N', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		}
	};
const	vm_paychannel_a_ext_t vm_paychannel_a_ext1[]=
	{
		{15000000, 0, 0, 0, 0, 0},
		{15000000, 0, 0, 0, 0, 0},
		{15000000, 0, 0, 0, 0, 0},
		{15000000, 0, 0, 0, 0, 0}
	};
const	vm_operator_code_t  vm_operator_info01[]=
	{
		{'4', '5', '2', '0', '4', 0, 0, 0},
		{'4', '5', '2', '0', '1', 0, 0, 0},
		{'4', '5', '2', '0', '2', 0, 0, 0},
		{'4', '5', '2', '0', '3', 0, 0, 0},
	};
//	vm_operator_code_t vm_operator_info11[]={0};
	//vm_operator_code_t vm_operator_info21[]={0};
//	vm_operator_code_t vm_operator_info31[]={0};
//	vm_pay_config_ext_t  vm_pay_config_info1 ={0};
#endif

#ifdef VM_COUNTRY_NIGERIA

const	vm_pay_notification_t vm_notification2=
	{
		0,
		{'6', '2', '1', 0},
		{
		0x0052, 0x0061, 0x0074, 0x0065, 0x0073, 0x0020, 0x0050, 0x0072, 0x006f, 0x006d, 0x0070, 0x0074, 0x0065, 0x0064, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x004f, 0x004b, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x0042, 0x0061, 0x0063, 0x006b, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x0059, 0x006f, 0x0075, 0x0020, 0x0077, 0x0069, 0x006c, 0x006c, 0x0020, 0x0070, 0x0075, 0x0072, 0x0063, 0x0068, 0x0061, 0x0073, 0x0065, 0x0020, 0x005f, 0x005f, 0x0067, 0x006f, 0x006f, 0x0064, 0x006e, 0x0061, 0x006d, 0x0065, 0x005f, 0x005f, 0x002c, 0x0020,
		0x0074, 0x0068, 0x0065, 0x0020, 0x0070, 0x0072, 0x0069, 0x0063, 0x0065, 0x0020, 0x0069, 0x0073, 0x0020, 0x005f, 0x0067, 0x006f, 0x006f, 0x0064, 0x0070, 0x0072, 0x0069, 0x0063, 0x0065, 0x005f, 0x004e, 0x002c, 0x0020, 0x0077, 0x006f, 0x0075, 0x006c, 0x0064,
		0x0020, 0x0079, 0x006f, 0x0075, 0x0020, 0x0062, 0x0075, 0x0079, 0x003f, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x0043, 0x0068, 0x0061, 0x0072, 0x0067, 0x0069, 0x006e, 0x0067, 0x002c, 0x0020, 0x0070, 0x006c, 0x0065, 0x0061, 0x0073, 0x0065, 0x0020, 0x0077, 0x0061, 0x0069, 0x0074, 0x0020, 0x002e, 0x002e, 0x002e, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x0043, 0x0068, 0x0061, 0x0072, 0x0067, 0x0069, 0x006e, 0x0067, 0x0020, 0x0073, 0x0075, 0x0063, 0x0065, 0x0073, 0x0073, 0x0066, 0x0075, 0x006c, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x0043, 0x0068, 0x0061, 0x0072, 0x0067, 0x0069, 0x006e, 0x0067, 0x0020, 0x0066, 0x0061, 0x0069, 0x006c, 0x0075, 0x0072, 0x0065, 0x002c, 0x0020, 0x0070, 0x006c, 0x0065, 0x0061, 0x0073, 0x0065, 0x0020, 0x0074, 0x0072, 0x0079, 0x0020, 0x0061, 0x0067, 0x0061,
		0x0069, 0x006e, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x004e, 0, 0, 0, 0, 0, 0, 0, 0, 0
		}
	};

const	vm_paychannel_ext_t vm_paychannel_info2[]=
	{
		{
		1,
		50,
		514,
		1,
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'3', '3', '2', '8', '2', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'Z', 'F', 'M', 'G', 'M', 'T', 'N', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
		2,
		50,
		514,
		1,
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'3', '3', '2', '8', '2', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'Z', 'F', 'M', 'G', 'G', 'L', 'O', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
		4,
		50,
		514,
		1,
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'3', '3', '2', '8', '2', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'Z', 'F', 'M', 'G', 'Z', 'A', 'N', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		}
	
	};

const	vm_paychannel_a_ext_t vm_paychannel_a_ext2[]=
	{
		{50000, 0, 0, 0, 0, 0},
		{50000, 0, 0, 0, 0, 0},
		{50000, 0, 0, 0, 0, 0}
	};

	vm_operator_code_t  vm_operator_info02[]=
	{
		{'6', '2', '1', '3', '0', 0, 0, 0},
		{'6', '2', '1', '5', '0', 0, 0, 0},
		{'6', '2', '1', '2', '0', 0, 0, 0}
	};
	
	//vm_operator_code_t vm_operator_info12[]={0};
	//vm_operator_code_t vm_operator_info22[]={0};
	//vm_operator_code_t vm_operator_info321[]={0};
	//vm_pay_config_ext_t  vm_pay_config_info2 ={0};

#endif

#ifdef VM_COUNTRY_THAILAND

const	vm_pay_notification_t vm_notification3=
	{
		0,
		{'5', '2', '0', 0},
		{
		0x0052, 0x0061, 0x0074, 0x0065, 0x0073, 0x0020, 0x0050, 0x0072, 0x006f, 0x006d, 0x0070, 0x0074, 0x0065, 0x0064, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x004f, 0x004b, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x0042, 0x0061, 0x0063, 0x006b, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x0059, 0x006f, 0x0075, 0x0020, 0x0077, 0x0069, 0x006c, 0x006c, 0x0020, 0x0070, 0x0075, 0x0072, 0x0063, 0x0068, 0x0061, 0x0073, 0x0065, 0x0020, 0x005f, 0x005f, 0x0067, 0x006f, 0x006f, 0x0064, 0x006e, 0x0061, 0x006d, 0x0065, 0x005f, 0x005f, 0x002c, 0x0020,
		0x0074, 0x0068, 0x0065, 0x0020, 0x0070, 0x0072, 0x0069, 0x0063, 0x0065, 0x0020, 0x0069, 0x0073, 0x0020, 0x005f, 0x0067, 0x006f, 0x006f, 0x0064, 0x0070, 0x0072, 0x0069, 0x0063, 0x0065, 0x005f, 0x0054, 0x0048, 0x0042, 0x002c, 0x0020, 0x0077, 0x006f, 0x0075,
		0x006c, 0x0064, 0x0020, 0x0079, 0x006f, 0x0075, 0x0020, 0x0062, 0x0075, 0x0079, 0x003f, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x0043, 0x0068, 0x0061, 0x0072, 0x0067, 0x0069, 0x006e, 0x0067, 0x002c, 0x0020, 0x0070, 0x006c, 0x0065, 0x0061, 0x0073, 0x0065, 0x0020, 0x0077, 0x0061, 0x0069, 0x0074, 0x0020, 0x002e, 0x002e, 0x002e, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x0043, 0x0068, 0x0061, 0x0072, 0x0067, 0x0069, 0x006e, 0x0067, 0x0020, 0x0073, 0x0075, 0x0063, 0x0065, 0x0073, 0x0073, 0x0066, 0x0075, 0x006c, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x0043, 0x0068, 0x0061, 0x0072, 0x0067, 0x0069, 0x006e, 0x0067, 0x0020, 0x0066, 0x0061, 0x0069, 0x006c, 0x0075, 0x0072, 0x0065, 0x002c, 0x0020, 0x0070, 0x006c, 0x0065, 0x0061, 0x0073, 0x0065, 0x0020, 0x0074, 0x0072, 0x0079, 0x0020, 0x0061, 0x0067, 0x0061,
		0x0069, 0x006e, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x0054, 0x0048, 0x0042, 0, 0, 0, 0, 0, 0, 0
		}
	};

const	vm_paychannel_ext_t vm_paychannel_info3[]=
	{
		{
		1,
		100,
		514,
		1,
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'4', '8', '9', '0', '0', '6', '7', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'Z', 'F', 'T', 'L', 'A', 'I', 'S', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
		2,
		100,
		514,
		1,
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'4', '8', '9', '0', '0', '6', '7', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'Z', 'F', 'T', 'L', 'D', 'T', 'A', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
		4,
		100,
		514,
		1,
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'4', '8', '9', '0', '0', '6', '7', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'Z', 'F', 'T', 'L', 'T', 'M', 'V', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		}
	};

const	vm_paychannel_a_ext_t vm_paychannel_a_ext3[]=
	{
		{30000, 0, 0, 0, 0, 0},
		{30000, 0, 0, 0, 0, 0},
		{30000, 0, 0, 0, 0, 0}
	};

const	vm_operator_code_t  vm_operator_info03[]=
	{
		{'5', '2', '0', '0', '1', 0, 0, 0},
		{'5', '2', '0', '1', '8', 0, 0, 0},
		{'5', '2', '0', '9', '9', 0, 0, 0}
	};
	
	//vm_operator_code_t vm_operator_info13[]={0};
	//vm_operator_code_t vm_operator_info23[]={0};
	//vm_operator_code_t vm_operator_info331[]={0};
	//vm_pay_config_ext_t  vm_pay_config_info3 ={0};
	
#endif

#ifdef VM_COUNTRY_INDONESIA

const	vm_pay_notification_t vm_notification4=
	{
		0,
		{'5', '1', '0', 0},
		{
		0x0048, 0x0061, 0x0072, 0x0067, 0x0061, 0x0020, 0x0064, 0x0069, 0x006d, 0x0069, 0x006e, 0x0074, 0x0061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x004f, 0x006b, 0x0065, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x0050, 0x0075, 0x006e, 0x0067, 0x0067, 0x0075, 0x006e, 0x0067, 0, 0, 0, 0, 0, 0, 0, 0
		},
		/*{
		0x0041, 0x006e, 0x0064, 0x0061, 0x0020, 0x0061, 0x006b, 0x0061, 0x006e, 0x0020, 0x006d, 0x0065, 0x006d, 0x0062, 0x0065, 0x006c, 0x0069, 0x0020, 0x005f, 0x005f, 0x0067, 0x006f, 0x006f, 0x0064, 0x006e, 0x0061, 0x006d, 0x0065, 0x005f, 0x005f, 0x002c, 0x0020,
		0x0068, 0x0061, 0x0072, 0x0067, 0x0061, 0x006e, 0x0079, 0x0061, 0x0020, 0x005f, 0x0067, 0x006f, 0x006f, 0x0064, 0x0070, 0x0072, 0x0069, 0x0063, 0x0065, 0x005f, 0x0052, 0x0070, 0x002c, 0x0020, 0x0061, 0x006b, 0x0061, 0x006e, 0x0020, 0x0041, 0x006e, 0x0064,
		0x0061, 0x0020, 0x0062, 0x0065, 0x006c, 0x0069, 0x003f, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},*/
		{
			0x005f, 0x005f, 0x0067, 0x006f, 0x006f, 0x0064, 0x006e, 0x0061, 0x006d, 0x0065, 0x005f, 0x005f, 0x0020, 0x006d, 0x0065, 0x006e, 0x0061, 0x0072, 0x0069, 0x006b, 0x0020, 0x0043, 0x0075, 0x006d, 0x0061, 0x0020, 0x0073, 0x0065, 0x0068, 0x0061, 0x0072, 0x0067,
			0x0061, 0x0020, 0x0052, 0x0070, 0x0020, 0x005f, 0x0067, 0x006f, 0x006f, 0x0064, 0x0070, 0x0072, 0x0069, 0x0063, 0x0065, 0x005f, 0x002c, 0x0020, 0x0042, 0x0065, 0x0072, 0x006d, 0x0069, 0x006e, 0x0061, 0x0074, 0x003f, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x0050, 0x0065, 0x006e, 0x0067, 0x0069, 0x0073, 0x0069, 0x0061, 0x006e, 0x002c, 0x0020, 0x0068, 0x0061, 0x0072, 0x0061, 0x0070, 0x0020, 0x0074, 0x0075, 0x006e, 0x0067, 0x0067, 0x0075, 0x0020, 0x002e, 0x002e, 0x002e, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x0050, 0x0065, 0x006e, 0x0067, 0x0069, 0x0073, 0x0069, 0x0061, 0x006e, 0x0020, 0x0073, 0x0075, 0x0063, 0x0065, 0x0073, 0x0073, 0x0066, 0x0075, 0x006c, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x0050, 0x0065, 0x006e, 0x0067, 0x0069, 0x0073, 0x0069, 0x0061, 0x006e, 0x0020, 0x0067, 0x0061, 0x0067, 0x0061, 0x006c, 0x002c, 0x0020, 0x0073, 0x0069, 0x006c, 0x0061, 0x006b, 0x0061, 0x006e, 0x0020, 0x0063, 0x006f, 0x0062, 0x0061, 0x0020, 0x006c, 0x0061,
		0x0067, 0x0069, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x0052, 0x0070, 0, 0, 0, 0, 0, 0, 0, 0
		}
	};

const	vm_paychannel_ext_t vm_paychannel_info4[]=
	{
		{
		1,
		50,
		514,
		1,
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'3', '7', '8', '9', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'Z', 'F', 'I', ' ', 'T', 'K', 'M', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
		2,
		50,
		514,
		1,
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'3', '7', '8', '9', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'Z', 'F', 'I', ' ', 'E', 'C', 'C', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
		4,
		50,
		514,
		1,
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'3', '7', '8', '9', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'Z', 'F', 'I', ' ', 'I', 'D', 'S', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
		8,
		50,
		514,
		1,
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'3', '7', '8', '9', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'Z', 'F', 'I', ' ', 'H', 'T', 'C', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
		16,
		50,
		514,
		1,
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'3', '7', '8', '9', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'Z', 'F', 'I', ' ', 'N', 'T', 'S', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
		31,
		50,
		513,
		2,
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		//TONE 2 wq001
		{'9', '3', '8', '8', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'T', 'O', 'N', 'E', ' ', '2', ' ', 'w', 'q', '0', '0', '1', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
		31,
		50,
		513,
		4,
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		//BALL wq001
		{'9', '3', '8', '8', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'B', 'A', 'L', 'L', ' ', 'w', ' q', '0', '0', '1', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		}
	};

const	vm_paychannel_a_ext_t vm_paychannel_a_ext4[]=
	{
		{2000000, 0, 0, 0, 0, 0},
		{2000000, 0, 0, 0, 0, 0},
		{2000000, 0, 0, 0, 0, 0},
		{2000000, 0, 0, 0, 0, 0},
		{2000000, 0, 0, 0, 0, 0},
		{2000000, 0, 0, 0, 0, 0},
		{2000000, 0, 0, 0, 0, 0}
	};

const	vm_operator_code_t  vm_operator_info04[]=
	{
		{'5', '1', '0', '1', '0', 0, 0, 0},
		{'5', '1', '0', '1', '1', 0, 0, 0},
		{'5', '1', '0', '0', '1', 0, 0, 0},
		{'5', '1', '0', '8', '9', 0, 0, 0},
		{'5', '1', '0', '0', '8', 0, 0, 0}
	};
	
	//vm_operator_code_t vm_operator_info14[]={0};
	//vm_operator_code_t vm_operator_info24[]={0};
	//vm_operator_code_t vm_operator_info341[]={0};
	//vm_pay_config_ext_t  vm_pay_config_info4 ={0};
	
#endif
	
#ifdef VM_COUNTRY_MALAYSIA

const  	vm_pay_notification_t vm_notification5=
	{
		0,
		{'5', '0', '2', 0},
		{
		0x0048, 0x0061, 0x0072, 0x0067, 0x0061, 0x0020, 0x0054, 0x0069, 0x0070, 0x0073, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x004f, 0x006b, 0x0065, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x004b, 0x0065, 0x006d, 0x0062, 0x0061, 0x006c, 0x0069, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x0041, 0x006e, 0x0064, 0x0061, 0x0020, 0x0061, 0x006b, 0x0061, 0x006e, 0x0020, 0x006d, 0x0065, 0x006d, 0x0062, 0x0065, 0x006c, 0x0069, 0x0020, 0x005f, 0x005f, 0x0067, 0x006f, 0x006f, 0x0064, 0x006e, 0x0061, 0x006d, 0x0065, 0x005f, 0x005f, 0x002c, 0x0020,
		0x0068, 0x0061, 0x0072, 0x0067, 0x0061, 0x006e, 0x0079, 0x0061, 0x0020, 0x005f, 0x0067, 0x006f, 0x006f, 0x0064, 0x0070, 0x0072, 0x0069, 0x0063, 0x0065, 0x005f, 0x0052, 0x004d, 0x002c, 0x0020, 0x0061, 0x006e, 0x0064, 0x0061, 0x0020, 0x0061, 0x006b, 0x0061,
		0x006e, 0x0020, 0x0062, 0x0065, 0x006c, 0x0069, 0x003f, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x0050, 0x0065, 0x006e, 0x0067, 0x0069, 0x0073, 0x0069, 0x0061, 0x006e, 0x002c, 0x0020, 0x0062, 0x0065, 0x0072, 0x0068, 0x0061, 0x0072, 0x0061, 0x0070, 0x0020, 0x0074, 0x0075, 0x006e, 0x0067, 0x0067, 0x0075, 0x0020, 0x002e, 0x002e, 0x002e, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x0050, 0x0065, 0x006e, 0x0067, 0x0069, 0x0073, 0x0069, 0x0061, 0x006e, 0x0020, 0x0073, 0x0075, 0x0063, 0x0065, 0x0073, 0x0073, 0x0066, 0x0075, 0x006c, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x004d, 0x0065, 0x006e, 0x0067, 0x0069, 0x0073, 0x0069, 0x0020, 0x006b, 0x0065, 0x0067, 0x0061, 0x0067, 0x0061, 0x006c, 0x0061, 0x006e, 0x002c, 0x0020, 0x0073, 0x0069, 0x006c, 0x0061, 0x0020, 0x0063, 0x0075, 0x0062, 0x0061, 0x0020, 0x006c, 0x0061, 0x0067,
		0x0069, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x0052, 0x004d, 0, 0, 0, 0, 0, 0, 0, 0
		}
	};

const	vm_paychannel_ext_t vm_paychannel_info5[]=
	{
		{
		1,
		100,
		514,
		1,
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'3', '2', '0', '8', '8', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'Z', 'F', 'M', ' ', 'C', 'E', 'L', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
		2,
		100,
		514,
		1,
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'3', '2', '0', '8', '8', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'Z', 'F', 'M', ' ', 'D', 'I', 'G', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
		4,
		100,
		514,
		1,
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'3', '2', '0', '8', '8', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'Z', 'F', 'M', ' ', 'M', 'A', 'X', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		}
	};

const	vm_paychannel_a_ext_t vm_paychannel_a_ext5[]=
	{
		{5000, 0, 0, 0, 0, 0},
		{5000, 0, 0, 0, 0, 0},
		{5000, 0, 0, 0, 0, 0}
	};

const	vm_operator_code_t  vm_operator_info05[]=
	{
		{'5', '0', '2', '1', '9', 0, 0, 0},
		{'5', '0', '2', '1', '6', 0, 0, 0},
		{'5', '0', '2', '1', '2', 0, 0, 0}
	};
	
	//vm_operator_code_t vm_operator_info15[]={0};
	//vm_operator_code_t vm_operator_info25[]={0};
	//vm_operator_code_t vm_operator_info351[]={0};
	//vm_pay_config_ext_t  vm_pay_config_info5 ={0};
	
#endif

#ifdef VM_COUNTRY_RUSSIAN

const	vm_pay_notification_t vm_notification6=
	{
		0,
		{'2', '5', '0', 0},
		{
		0x0052, 0x0061, 0x0074, 0x0065, 0x0073, 0x0020, 0x0050, 0x0072, 0x006f, 0x006d, 0x0070, 0x0074, 0x0065, 0x0064, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x004f, 0x004b, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x0042, 0x0061, 0x0063, 0x006b, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x0059, 0x006f, 0x0075, 0x0020, 0x0077, 0x0069, 0x006c, 0x006c, 0x0020, 0x0070, 0x0075, 0x0072, 0x0063, 0x0068, 0x0061, 0x0073, 0x0065, 0x0020, 0x005f, 0x005f, 0x0067, 0x006f, 0x006f, 0x0064, 0x006e, 0x0061, 0x006d, 0x0065, 0x005f, 0x005f, 0x002c, 0x0020,
		0x0074, 0x0068, 0x0065, 0x0020, 0x0070, 0x0072, 0x0069, 0x0063, 0x0065, 0x0020, 0x0069, 0x0073, 0x0020, 0x005f, 0x0067, 0x006f, 0x006f, 0x0064, 0x0070, 0x0072, 0x0069, 0x0063, 0x0065, 0x005f, 0x0072, 0x0075, 0x0062, 0x002c, 0x0020, 0x0077, 0x006f, 0x0075,
		0x006c, 0x0064, 0x0020, 0x0079, 0x006f, 0x0075, 0x0020, 0x0062, 0x0075, 0x0079, 0x003f, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x0043, 0x0068, 0x0061, 0x0072, 0x0067, 0x0069, 0x006e, 0x0067, 0x002c, 0x0020, 0x0070, 0x006c, 0x0065, 0x0061, 0x0073, 0x0065, 0x0020, 0x0077, 0x0061, 0x0069, 0x0074, 0x0020, 0x002e, 0x002e, 0x002e, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x0043, 0x0068, 0x0061, 0x0072, 0x0067, 0x0069, 0x006e, 0x0067, 0x0020, 0x0073, 0x0075, 0x0063, 0x0065, 0x0073, 0x0073, 0x0066, 0x0075, 0x006c, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x0043, 0x0068, 0x0061, 0x0072, 0x0067, 0x0069, 0x006e, 0x0067, 0x0020, 0x0066, 0x0061, 0x0069, 0x006c, 0x0075, 0x0072, 0x0065, 0x002c, 0x0020, 0x0070, 0x006c, 0x0065, 0x0061, 0x0073, 0x0065, 0x0020, 0x0074, 0x0072, 0x0079, 0x0020, 0x0061, 0x0067, 0x0061,
		0x0069, 0x006e, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x0072, 0x0075, 0x0062, 0, 0, 0, 0, 0, 0, 0
		}	
	};

const	vm_paychannel_ext_t vm_paychannel_info6[]=
	{
		{
		1,
		50,
		514,
		1,
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'7', '7', '1', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'Z', 'F', 'R', 'S', 'B', 'E', 'L', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
		2,
		50,
		514,
		1,
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'7', '7', '1', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'Z', 'F', 'R', 'S', 'M', 'G', 'F', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
		4,
		50,
		514,
		1,
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'7', '7', '1', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'Z', 'F', 'R', 'S', 'M', 'T', 'S', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		}
	};

const	vm_paychannel_a_ext_t vm_paychannel_a_ext6[]=
	{
		{13000, 0, 0, 0, 0, 0},
		{13000, 0, 0, 0, 0, 0},
		{13000, 0, 0, 0, 0, 0}
	};

const	vm_operator_code_t  vm_operator_info06[]=
	{
		{'2', '5', '0', '9', '9', 0, 0, 0},
		{'2', '5', '0', '0', '2', 0, 0, 0},
		{'2', '5', '0', '0', '1', 0, 0, 0}
	};
	
	//vm_operator_code_t vm_operator_info16[]={0};
	//vm_operator_code_t vm_operator_info26[]={0};
	//vm_operator_code_t vm_operator_info361[]={0};
	//vm_pay_config_ext_t  vm_pay_config_info6 ={0};
  
#endif

#ifdef VM_COUNTRY_INDIA

const	vm_pay_notification_t vm_notification7=
	{
		0,
		{'4', '0', '4', 0},
		{
		0x0052, 0x0061, 0x0074, 0x0065, 0x0073, 0x0020, 0x0050, 0x0072, 0x006f, 0x006d, 0x0070, 0x0074, 0x0065, 0x0064, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x004f, 0x004b, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x0042, 0x0061, 0x0063, 0x006b, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x0059, 0x006f, 0x0075, 0x0020, 0x0077, 0x0069, 0x006c, 0x006c, 0x0020, 0x0070, 0x0075, 0x0072, 0x0063, 0x0068, 0x0061, 0x0073, 0x0065, 0x0020, 0x005f, 0x005f, 0x0067, 0x006f, 0x006f, 0x0064, 0x006e, 0x0061, 0x006d, 0x0065, 0x005f, 0x005f, 0x002c, 0x0020,
		0x0074, 0x0068, 0x0065, 0x0020, 0x0070, 0x0072, 0x0069, 0x0063, 0x0065, 0x0020, 0x0069, 0x0073, 0x0020, 0x005f, 0x0067, 0x006f, 0x006f, 0x0064, 0x0070, 0x0072, 0x0069, 0x0063, 0x0065, 0x005f, 0x0052, 0x0073, 0x002c, 0x0020, 0x0077, 0x006f, 0x0075, 0x006c,
		0x0064, 0x0020, 0x0079, 0x006f, 0x0075, 0x0020, 0x0062, 0x0075, 0x0079, 0x003f, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x0043, 0x0068, 0x0061, 0x0072, 0x0067, 0x0069, 0x006e, 0x0067, 0x002c, 0x0020, 0x0070, 0x006c, 0x0065, 0x0061, 0x0073, 0x0065, 0x0020, 0x0077, 0x0061, 0x0069, 0x0074, 0x0020, 0x002e, 0x002e, 0x002e, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x0043, 0x0068, 0x0061, 0x0072, 0x0067, 0x0069, 0x006e, 0x0067, 0x0020, 0x0073, 0x0075, 0x0063, 0x0065, 0x0073, 0x0073, 0x0066, 0x0075, 0x006c, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x0043, 0x0068, 0x0061, 0x0072, 0x0067, 0x0069, 0x006e, 0x0067, 0x0020, 0x0066, 0x0061, 0x0069, 0x006c, 0x0075, 0x0072, 0x0065, 0x002c, 0x0020, 0x0070, 0x006c, 0x0065, 0x0061, 0x0073, 0x0065, 0x0020, 0x0074, 0x0072, 0x0079, 0x0020, 0x0061, 0x0067, 0x0061,
		0x0069, 0x006e, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0x0052, 0x0073, 0, 0, 0, 0, 0, 0, 0, 0
		}
	};

const	vm_paychannel_ext_t vm_paychannel_info7[]=
	{
		{
		15,
		50,
		514,
		1,
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'5', '7', '8', '8', '6', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'Z', 'F', 'P', ' ', 'A', 'I', 'C', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
		33554416,
		50,
		514,
		1,
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'5', '7', '8', '8', '6', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'Z', 'F', 'P', ' ', 'B', 'S', 'N', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
		4261412864,
		50,
		514,
		1,
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'5', '7', '8', '8', '6', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'Z', 'F', 'P', ' ', 'A', 'I', 'T', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
		0,
		50,
		514,
		1,
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'5', '7', '8', '8', '6', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'Z', 'F', 'P', ' ', 'T', 'A', 'T', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
		0,
		50,
		514,
		1,
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'5', '7', '8', '8', '6', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'Z', 'F', 'P', ' ', 'I', 'D', 'E', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
		0,
		50,
		514,
		1,
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'5', '7', '8', '8', '6', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'Z', 'F', 'P', ' ', 'S', 'P', 'P', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
		0,
		50,
		514,
		1,
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'5', '7', '8', '8', '6', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'Z', 'F', 'P', ' ', 'R', 'E', 'L', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
		0,
		50,
		514,
		1,
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'5', '7', '8', '8', '6', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'Z', 'F', 'P', ' ', 'T', 'E', 'L', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		}
	};

const	vm_paychannel_a_ext_t vm_paychannel_a_ext7[]=
	{
		{3000, 0, 0, 0, 0, 0},
		{3000, 0, 0, 0, 0, 0},
		{3000, 0, 0, 255, 0, 0},
		{3000, 0, 0, 256, 0, 0},
		{3000, 0, 0, 7680, 0, 0},
		{3000, 0, 0, 8192, 0, 0},
		{3000, 0, 0, 2080768, 0, 0},
		{3000, 0, 0, 31457280, 0, 0}
	};

const	vm_operator_code_t  vm_operator_info07[]=
	{
		{'4', '0', '4', '1', '5', 0, 0, 0},
		{'4', '0', '4', '6', '0', 0, 0, 0},
		{'4', '0', '4', '0', '1', 0, 0, 0},
		{'4', '0', '4', '4', '2', 0, 0, 0},
		{'4', '0', '4', '3', '4', 0, 0, 0},
		{'4', '0', '4', '3', '8', 0, 0, 0},
		{'4', '0', '4', '5', '1', 0, 0, 0},
		{'4', '0', '4', '5', '3', 0, 0, 0},
		{'4', '0', '4', '5', '4', 0, 0, 0},
		{'4', '0', '4', '5', '5', 0, 0, 0},
		{'4', '0', '4', '5', '7', 0, 0, 0},
		{'4', '0', '4', '5', '8', 0, 0, 0},
		{'4', '0', '4', '5', '9', 0, 0, 0},
		{'4', '0', '4', '6', '2', 0, 0, 0},
		{'4', '0', '4', '6', '4', 0, 0, 0},
		{'4', '0', '4', '6', '6', 0, 0, 0},
		{'4', '0', '4', '7', '1', 0, 0, 0},
		{'4', '0', '4', '7', '2', 0, 0, 0},
		{'4', '0', '4', '7', '3', 0, 0, 0},
		{'4', '0', '4', '7', '4', 0, 0, 0},
		{'4', '0', '4', '7', '5', 0, 0, 0},
		{'4', '0', '4', '7', '6', 0, 0, 0},
		{'4', '0', '4', '7', '7', 0, 0, 0},
		{'4', '0', '4', '7', '9', 0, 0, 0},
		{'4', '0', '4', '8', '0', 0, 0, 0},
		{'4', '0', '4', '1', '0', 0, 0, 0},
		{'4', '0', '4', '3', '1', 0, 0, 0},
		{'4', '0', '4', '9', '6', 0, 0, 0},
		{'4', '0', '4', '9', '5', 0, 0, 0},
		{'4', '0', '4', '9', '4', 0, 0, 0},
		{'4', '0', '4', '9', '7', 0, 0, 0},
		{'4', '0', '4', '9', '2', 0, 0, 0}
	};
	
const	vm_operator_code_t vm_operator_info17[]=
	{
		{'4', '0', '4', '9', '8', 0, 0, 0},
		{'4', '0', '4', '9', '0', 0, 0, 0},
		{'4', '0', '4', '9', '3', 0, 0, 0},
		{'4', '0', '4', '4', '5', 0, 0, 0},
		{'4', '0', '4', '4', '9', 0, 0, 0},
		{'4', '0', '4', '0', '2', 0, 0, 0},
		{'4', '0', '4', '4', '0', 0, 0, 0},
		{'4', '0', '4', '0', '3', 0, 0, 0},
		{'4', '0', '4', '0', '7', 0, 0, 0},
		{'4', '0', '4', '2', '2', 0, 0, 0},
		{'4', '0', '4', '2', '4', 0, 0, 0},
		{'4', '0', '4', '0', '4', 0, 0, 0},
		{'4', '0', '4', '7', '8', 0, 0, 0},
		{'4', '0', '4', '1', '4', 0, 0, 0},
		{'4', '0', '4', '0', '9', 0, 0, 0},
		{'4', '0', '4', '1', '8', 0, 0, 0},
		{'4', '0', '4', '3', '6', 0, 0, 0},
		{'4', '0', '4', '5', '0', 0, 0, 0},
		{'4', '0', '4', '5', '2', 0, 0, 0},
		{'4', '0', '4', '6', '7', 0, 0, 0},
		{'4', '0', '4', '8', '5', 0, 0, 0},
		{'4', '0', '4', '1', '3', 0, 0, 0},
		{'4', '0', '4', '1', '1', 0, 0, 0},
		{'4', '0', '4', '0', '5', 0, 0, 0},
		{'4', '0', '4', '8', '6', 0, 0, 0}
	};
	//vm_operator_code_t vm_operator_info27[]={0};
	//vm_operator_code_t vm_operator_info371[]={0};
	//vm_pay_config_ext_t  vm_pay_config_info7 ={0};
 
#endif

#ifdef VM_COUNTRY_CHINA

const	vm_pay_notification_t vm_notification8=
	{
		0,
		{'4', '6', '0', 0},
		{
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		},
		{
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		}
	};

const	vm_paychannel_ext_t vm_paychannel_info8[]=
	{
		/*test*/
		/*{
		5,
		100,
		257,
		1,
		{0x77ed, 0x4fe1, 0x4e50, 0x56ed, 0, 0, 0, 0, 0, 0, 0},
		{0x957f, 0x6c99, 0x638c, 0x8baf, 0x516c,0x53f8, 0, 0, 0},
		{'0', '1', '0', '-', '6', '4', '4', '6', '5', '9', '1', '5', 0, 0, 0, 0},
			//{'1', '0', '6', '6', '2', '5', '6', '6', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		//	{'1', '5', '2', '2', '1', '2', '8', '7', '8', '6', '5', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'1', '3', '8', '1', '7', '3', '2', '1', '9', '4', '6', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'E', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		}*/
		

		{
		5,
		100,
		513,
		1,
		{0x597d, 0x7ba1, 0x5bb6, 0, 0, 0, 0, 0, 0, 0, 0},
		{0x5317, 0x4eac, 0x8d5e, 0x6210, 0, 0, 0, 0, 0},
		{'0', '1', '0', '-', '6', '4', '4', '6', '5', '9', '1', '5', 0, 0, 0, 0},
		{'1', '0', '6', '6', '2', '5', '6', '6', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'E', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
		2,
		100,
		514,
		1,
		{0x56fd, 0x9645, 0x5929, 0x6c14, 0x9884, 0x62a5, 0, 0, 0, 0, 0},
		{0x957f, 0x6c99, 0x638c, 0x8baf, 0x002d, 0x8054, 0x901a, 0, 0},
		{'0', '1', '0', '-', '6', '2', '0', '4', '5', '6', '9', '9', 0, 0, 0, 0},
		{'1', '0', '6', '6', '7', '7', '6', '6', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{'G', 'J', 'T', 'Q', ' ', '1', '2', '4', ' ', '2', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		}
		
		
	};

const	vm_paychannel_a_ext_t vm_paychannel_a_ext8[]=
	{
		//{1000, 30, 50, 0, 0, 0},

		{1000, 0, 0, 0, 0, 0},
		{1000, 0, 0, 0, 0, 0}
	};

const	vm_operator_code_t  vm_operator_info08[]=
	{
		{'4', '6', '0', '0', '0', 0, 0, 0},
		{'4', '6', '0', '0', '1', 0, 0, 0},
		{'4', '6', '0', '0', '2', 0, 0, 0},
		{'4', '6', '0', '0', '3', 0, 0, 0},
		{'4', '6', '0', '0', '5', 0, 0, 0},
		{'4', '6', '0', '0', '6', 0, 0, 0}
	};
	
	//vm_operator_code_t vm_operator_info18[]={0};
	//vm_operator_code_t vm_operator_info28[]={0};
	//vm_operator_code_t vm_operator_info381[]={0};
const	vm_pay_config_ext_t  vm_pay_config_info8 =
	{0, 1, 0, 65541,
			{0x672c, 0x6b21, 0x5bc6, 0x7801, 0, 0, 0, 0, 0, 0, 0, 0},
			{0xff0c, 0}

	};

#endif
	
const vm_payment_info_csr_t vm_payment_info_csr[]=
{
	#ifdef VM_COUNTRY_VIETNAM
	{
		{'4', '5', '2', 0},
		(vm_pay_notification_t * )&vm_notification1,
		(vm_paychannel_ext_t * )vm_paychannel_info1,
		(sizeof(vm_paychannel_info1)/sizeof(vm_paychannel_ext_t)),
		(vm_paychannel_a_ext_t * )vm_paychannel_a_ext1,
		(sizeof(vm_paychannel_a_ext1)/sizeof(vm_paychannel_a_ext_t)),
		(vm_operator_code_t * )vm_operator_info01,
		(sizeof(vm_operator_info01)/sizeof(vm_operator_code_t)),
		NULL,
		0,
		NULL,
		0,
		NULL,
		0,
		NULL

	},
	#endif

	#ifdef VM_COUNTRY_NIGERIA
    {
		{'6', '2', '1', 0},
		(vm_pay_notification_t * )&vm_notification2,
		(vm_paychannel_ext_t * )vm_paychannel_info2,
		(sizeof(vm_paychannel_info2)/sizeof(vm_paychannel_ext_t)),
		(vm_paychannel_a_ext_t * )vm_paychannel_a_ext2,
		(sizeof(vm_paychannel_a_ext2)/sizeof(vm_paychannel_a_ext_t)),
		(vm_operator_code_t * )vm_operator_info02,
		(sizeof(vm_operator_info02)/sizeof(vm_operator_code_t)),
		NULL,
		0,
		NULL,
		0,
		NULL,
		0,
		NULL
	},
	#endif
	
	#ifdef VM_COUNTRY_THAILAND
    {
		{'5', '2', '0', 0},
		(vm_pay_notification_t * )&vm_notification3,
		(vm_paychannel_ext_t * )vm_paychannel_info3,
		(sizeof(vm_paychannel_info3)/sizeof(vm_paychannel_ext_t)),
		(vm_paychannel_a_ext_t * )vm_paychannel_a_ext3,
		(sizeof(vm_paychannel_a_ext3)/sizeof(vm_paychannel_a_ext_t)),
		(vm_operator_code_t * )vm_operator_info03,
		(sizeof(vm_operator_info03)/sizeof(vm_operator_code_t)),
		NULL,
		0,
		NULL,
		0,
		NULL,
		0,
		NULL
	},
	#endif

	#ifdef VM_COUNTRY_INDONESIA
    {
		{'5', '1', '0', 0},
		(vm_pay_notification_t * )&vm_notification4,
		(vm_paychannel_ext_t * )vm_paychannel_info4,
		(sizeof(vm_paychannel_info4)/sizeof(vm_paychannel_ext_t)),
		(vm_paychannel_a_ext_t * )vm_paychannel_a_ext4,
		(sizeof(vm_paychannel_a_ext4)/sizeof(vm_paychannel_a_ext_t)),
		(vm_operator_code_t * )vm_operator_info04,
		(sizeof(vm_operator_info04)/sizeof(vm_operator_code_t)),
		NULL,
		0,
		NULL,
		0,
		NULL,
		0,
		NULL
	},
	#endif
	
	#ifdef VM_COUNTRY_MALAYSIA
    {
		{'5', '0', '2', 0},
		(vm_pay_notification_t * )&vm_notification5,
		(vm_paychannel_ext_t * )vm_paychannel_info5,
		(sizeof(vm_paychannel_info5)/sizeof(vm_paychannel_ext_t)),
		(vm_paychannel_a_ext_t * )vm_paychannel_a_ext5,
		(sizeof(vm_paychannel_a_ext5)/sizeof(vm_paychannel_a_ext_t)),
		(vm_operator_code_t * )vm_operator_info05,
		(sizeof(vm_operator_info05)/sizeof(vm_operator_code_t)),
		NULL,
		0,
		NULL,
		0,
		NULL,
		0,
		NULL
	},
	#endif

	#ifdef VM_COUNTRY_RUSSIAN
    {
		{'2', '5', '0', 0},
		(vm_pay_notification_t * )&vm_notification6,
		(vm_paychannel_ext_t * )vm_paychannel_info6,
		(sizeof(vm_paychannel_info6)/sizeof(vm_paychannel_ext_t)),
		(vm_paychannel_a_ext_t * )vm_paychannel_a_ext6,
		(sizeof(vm_paychannel_a_ext6)/sizeof(vm_paychannel_a_ext_t)),
		(vm_operator_code_t * )vm_operator_info06,
		(sizeof(vm_operator_info06)/sizeof(vm_operator_code_t)),
		NULL,
		0,
		NULL,
		0,
		NULL,
		0,
		NULL
	},
	#endif

	#ifdef VM_COUNTRY_INDIA
    {
		{'4', '0', '4', 0},
		(vm_pay_notification_t * )&vm_notification7,
		(vm_paychannel_ext_t * )vm_paychannel_info7,
		(sizeof(vm_paychannel_info7)/sizeof(vm_paychannel_ext_t)),
		(vm_paychannel_a_ext_t * )vm_paychannel_a_ext7,
		(sizeof(vm_paychannel_a_ext7)/sizeof(vm_paychannel_a_ext_t)),
		(vm_operator_code_t * )vm_operator_info07,
		(sizeof(vm_operator_info07)/sizeof(vm_operator_code_t)),
		(vm_operator_code_t * )vm_operator_info17,
		(sizeof(vm_operator_info17)/sizeof(vm_operator_code_t)),
		NULL,
		0,
		NULL,
		0,
		NULL
	},
	#endif

	#ifdef VM_COUNTRY_CHINA
    {
		{'4', '6', '0', 0},
		(vm_pay_notification_t * )&vm_notification8,
		(vm_paychannel_ext_t * )vm_paychannel_info8,
		(sizeof(vm_paychannel_info8)/sizeof(vm_paychannel_ext_t)),
		(vm_paychannel_a_ext_t * )vm_paychannel_a_ext8,
		(sizeof(vm_paychannel_a_ext8)/sizeof(vm_paychannel_a_ext_t)),
		(vm_operator_code_t * )vm_operator_info08,
		(sizeof(vm_operator_info08)/sizeof(vm_operator_code_t)),
		NULL,
		0,
		NULL,
		0,
		NULL,
		0,
		(vm_pay_config_ext_t*)&vm_pay_config_info8
	}
	#endif
};

/*
const vm_payment_info_t  vm_payment_info[]=
{
	#ifdef VM_COUNTRY_VIETNAM
	{
		{'4', '5', '2', 0},
		{
			0,
			{'4', '5', '2', 0},
			{
			0x0052, 0x0061, 0x0074, 0x0065, 0x0073, 0x0020, 0x0050, 0x0072, 0x006f, 0x006d, 0x0070, 0x0074, 0x0065, 0x0064, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x004f, 0x004b, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x0042, 0x0061, 0x0063, 0x006b, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x0059, 0x006f, 0x0075, 0x0020, 0x0077, 0x0069, 0x006c, 0x006c, 0x0020, 0x0070, 0x0075, 0x0072, 0x0063, 0x0068, 0x0061, 0x0073, 0x0065, 0x0020, 0x005f, 0x005f, 0x0067, 0x006f, 0x006f, 0x0064, 0x006e, 0x0061, 0x006d, 0x0065, 0x005f, 0x005f, 0x002c, 0x0020,
			0x0074, 0x0068, 0x0065, 0x0020, 0x0070, 0x0072, 0x0069, 0x0063, 0x0065, 0x0020, 0x0069, 0x0073, 0x0020, 0x005f, 0x0067, 0x006f, 0x006f, 0x0064, 0x0070, 0x0072, 0x0069, 0x0063, 0x0065, 0x005f, 0x0064, 0x006f, 0x006e, 0x0067, 0x002c, 0x0020, 0x0077, 0x006f,
			0x0075, 0x006c, 0x0064, 0x0020, 0x0079, 0x006f, 0x0075, 0x0020, 0x0062, 0x0075, 0x0079, 0x003f, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x0043, 0x0068, 0x0061, 0x0072, 0x0067, 0x0069, 0x006e, 0x0067, 0x002c, 0x0020, 0x0070, 0x006c, 0x0065, 0x0061, 0x0073, 0x0065, 0x0020, 0x0077, 0x0061, 0x0069, 0x0074, 0x0020, 0x002e, 0x002e, 0x002e, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x0043, 0x0068, 0x0061, 0x0072, 0x0067, 0x0069, 0x006e, 0x0067, 0x0020, 0x0073, 0x0075, 0x0063, 0x0065, 0x0073, 0x0073, 0x0066, 0x0075, 0x006c, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x0043, 0x0068, 0x0061, 0x0072, 0x0067, 0x0069, 0x006e, 0x0067, 0x0020, 0x0066, 0x0061, 0x0069, 0x006c, 0x0075, 0x0072, 0x0065, 0x002c, 0x0020, 0x0070, 0x006c, 0x0065, 0x0061, 0x0073, 0x0065, 0x0020, 0x0074, 0x0072, 0x0079, 0x0020, 0x0061, 0x0067, 0x0061,
			0x0069, 0x006e, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x0064, 0x006f, 0x006e, 0x0067, 0, 0, 0, 0, 0, 0
			}
		},
		{
			{
			1,
			100,
			514,
			1,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'8', '7', '4', '0', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'Z', 'F', 'V', 'N', 'V', 'T', 'L', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			2,
			100,
			514,
			1,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'8', '7', '4', '0', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'Z', 'F', 'V', 'N', 'M', 'B', 'F', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			4,
			100,
			514,
			1,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'8', '7', '4', '0', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'Z', 'F', 'V', 'N', 'V', 'N', 'P', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			8,
			100,
			514,
			1,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'8', '7', '4', '0', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'Z', 'F', 'V', 'N', 'S', 'F', 'N', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			}
		},
		{
			{15000000, 0, 0, 0, 0, 0},
			{15000000, 0, 0, 0, 0, 0},
			{15000000, 0, 0, 0, 0, 0},
			{15000000, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0}
		},
		{
			{'4', '5', '2', '0', '4', 0, 0, 0},
			{'4', '5', '2', '0', '1', 0, 0, 0},
			{'4', '5', '2', '0', '2', 0, 0, 0},
			{'4', '5', '2', '0', '3', 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0}
		},
		{0, 0, 0, 0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0}
		}

	},
	#endif
	#ifdef VM_COUNTRY_NIGERIA
	{
		{'6', '2', '1', 0},
		{
			0,
			{'6', '2', '1', 0},
			{
			0x0052, 0x0061, 0x0074, 0x0065, 0x0073, 0x0020, 0x0050, 0x0072, 0x006f, 0x006d, 0x0070, 0x0074, 0x0065, 0x0064, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x004f, 0x004b, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x0042, 0x0061, 0x0063, 0x006b, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x0059, 0x006f, 0x0075, 0x0020, 0x0077, 0x0069, 0x006c, 0x006c, 0x0020, 0x0070, 0x0075, 0x0072, 0x0063, 0x0068, 0x0061, 0x0073, 0x0065, 0x0020, 0x005f, 0x005f, 0x0067, 0x006f, 0x006f, 0x0064, 0x006e, 0x0061, 0x006d, 0x0065, 0x005f, 0x005f, 0x002c, 0x0020,
			0x0074, 0x0068, 0x0065, 0x0020, 0x0070, 0x0072, 0x0069, 0x0063, 0x0065, 0x0020, 0x0069, 0x0073, 0x0020, 0x005f, 0x0067, 0x006f, 0x006f, 0x0064, 0x0070, 0x0072, 0x0069, 0x0063, 0x0065, 0x005f, 0x004e, 0x002c, 0x0020, 0x0077, 0x006f, 0x0075, 0x006c, 0x0064,
			0x0020, 0x0079, 0x006f, 0x0075, 0x0020, 0x0062, 0x0075, 0x0079, 0x003f, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x0043, 0x0068, 0x0061, 0x0072, 0x0067, 0x0069, 0x006e, 0x0067, 0x002c, 0x0020, 0x0070, 0x006c, 0x0065, 0x0061, 0x0073, 0x0065, 0x0020, 0x0077, 0x0061, 0x0069, 0x0074, 0x0020, 0x002e, 0x002e, 0x002e, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x0043, 0x0068, 0x0061, 0x0072, 0x0067, 0x0069, 0x006e, 0x0067, 0x0020, 0x0073, 0x0075, 0x0063, 0x0065, 0x0073, 0x0073, 0x0066, 0x0075, 0x006c, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x0043, 0x0068, 0x0061, 0x0072, 0x0067, 0x0069, 0x006e, 0x0067, 0x0020, 0x0066, 0x0061, 0x0069, 0x006c, 0x0075, 0x0072, 0x0065, 0x002c, 0x0020, 0x0070, 0x006c, 0x0065, 0x0061, 0x0073, 0x0065, 0x0020, 0x0074, 0x0072, 0x0079, 0x0020, 0x0061, 0x0067, 0x0061,
			0x0069, 0x006e, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x004e, 0, 0, 0, 0, 0, 0, 0, 0, 0
			}
		},
		{
			{
			1,
			50,
			514,
			1,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'3', '3', '2', '8', '2', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'Z', 'F', 'M', 'G', 'M', 'T', 'N', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			2,
			50,
			514,
			1,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'3', '3', '2', '8', '2', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'Z', 'F', 'M', 'G', 'G', 'L', 'O', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			4,
			50,
			514,
			1,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'3', '3', '2', '8', '2', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'Z', 'F', 'M', 'G', 'Z', 'A', 'N', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			}
		},
		{
			{50000, 0, 0, 0, 0, 0},
			{50000, 0, 0, 0, 0, 0},
			{50000, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0}
		},
		{
			{'6', '2', '1', '3', '0', 0, 0, 0},
			{'6', '2', '1', '5', '0', 0, 0, 0},
			{'6', '2', '1', '2', '0', 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0}
		},
		{0, 0, 0, 0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0}
		}

	},
	#endif
	#ifdef VM_COUNTRY_THAILAND
	{
		{'5', '2', '0', 0},
		{
			0,
			{'5', '2', '0', 0},
			{
			0x0052, 0x0061, 0x0074, 0x0065, 0x0073, 0x0020, 0x0050, 0x0072, 0x006f, 0x006d, 0x0070, 0x0074, 0x0065, 0x0064, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x004f, 0x004b, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x0042, 0x0061, 0x0063, 0x006b, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x0059, 0x006f, 0x0075, 0x0020, 0x0077, 0x0069, 0x006c, 0x006c, 0x0020, 0x0070, 0x0075, 0x0072, 0x0063, 0x0068, 0x0061, 0x0073, 0x0065, 0x0020, 0x005f, 0x005f, 0x0067, 0x006f, 0x006f, 0x0064, 0x006e, 0x0061, 0x006d, 0x0065, 0x005f, 0x005f, 0x002c, 0x0020,
			0x0074, 0x0068, 0x0065, 0x0020, 0x0070, 0x0072, 0x0069, 0x0063, 0x0065, 0x0020, 0x0069, 0x0073, 0x0020, 0x005f, 0x0067, 0x006f, 0x006f, 0x0064, 0x0070, 0x0072, 0x0069, 0x0063, 0x0065, 0x005f, 0x0054, 0x0048, 0x0042, 0x002c, 0x0020, 0x0077, 0x006f, 0x0075,
			0x006c, 0x0064, 0x0020, 0x0079, 0x006f, 0x0075, 0x0020, 0x0062, 0x0075, 0x0079, 0x003f, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x0043, 0x0068, 0x0061, 0x0072, 0x0067, 0x0069, 0x006e, 0x0067, 0x002c, 0x0020, 0x0070, 0x006c, 0x0065, 0x0061, 0x0073, 0x0065, 0x0020, 0x0077, 0x0061, 0x0069, 0x0074, 0x0020, 0x002e, 0x002e, 0x002e, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x0043, 0x0068, 0x0061, 0x0072, 0x0067, 0x0069, 0x006e, 0x0067, 0x0020, 0x0073, 0x0075, 0x0063, 0x0065, 0x0073, 0x0073, 0x0066, 0x0075, 0x006c, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x0043, 0x0068, 0x0061, 0x0072, 0x0067, 0x0069, 0x006e, 0x0067, 0x0020, 0x0066, 0x0061, 0x0069, 0x006c, 0x0075, 0x0072, 0x0065, 0x002c, 0x0020, 0x0070, 0x006c, 0x0065, 0x0061, 0x0073, 0x0065, 0x0020, 0x0074, 0x0072, 0x0079, 0x0020, 0x0061, 0x0067, 0x0061,
			0x0069, 0x006e, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x0054, 0x0048, 0x0042, 0, 0, 0, 0, 0, 0, 0
			}
		},
		{
			{
			1,
			100,
			514,
			1,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'4', '8', '9', '0', '0', '6', '7', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'Z', 'F', 'T', 'L', 'A', 'I', 'S', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			2,
			100,
			514,
			1,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'4', '8', '9', '0', '0', '6', '7', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'Z', 'F', 'T', 'L', 'D', 'T', 'A', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			4,
			100,
			514,
			1,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'4', '8', '9', '0', '0', '6', '7', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'Z', 'F', 'T', 'L', 'T', 'M', 'V', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			}
		},
		{
			{30000, 0, 0, 0, 0, 0},
			{30000, 0, 0, 0, 0, 0},
			{30000, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0}
		},
		{
			{'5', '2', '0', '0', '1', 0, 0, 0},
			{'5', '2', '0', '1', '8', 0, 0, 0},
			{'5', '2', '0', '9', '9', 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0}
		},
		{0, 0, 0, 0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0}
		}

	},
	#endif
	#ifdef VM_COUNTRY_INDONESIA
	{
		{'5', '1', '0', 0},
		{
			0,
			{'5', '1', '0', 0},
			{
			0x0048, 0x0061, 0x0072, 0x0067, 0x0061, 0x0020, 0x0064, 0x0069, 0x006d, 0x0069, 0x006e, 0x0074, 0x0061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x004f, 0x006b, 0x0065, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x0050, 0x0075, 0x006e, 0x0067, 0x0067, 0x0075, 0x006e, 0x0067, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x0041, 0x006e, 0x0064, 0x0061, 0x0020, 0x0061, 0x006b, 0x0061, 0x006e, 0x0020, 0x006d, 0x0065, 0x006d, 0x0062, 0x0065, 0x006c, 0x0069, 0x0020, 0x005f, 0x005f, 0x0067, 0x006f, 0x006f, 0x0064, 0x006e, 0x0061, 0x006d, 0x0065, 0x005f, 0x005f, 0x002c, 0x0020,
			0x0068, 0x0061, 0x0072, 0x0067, 0x0061, 0x006e, 0x0079, 0x0061, 0x0020, 0x005f, 0x0067, 0x006f, 0x006f, 0x0064, 0x0070, 0x0072, 0x0069, 0x0063, 0x0065, 0x005f, 0x0052, 0x0070, 0x002c, 0x0020, 0x0061, 0x006b, 0x0061, 0x006e, 0x0020, 0x0041, 0x006e, 0x0064,
			0x0061, 0x0020, 0x0062, 0x0065, 0x006c, 0x0069, 0x003f, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x0050, 0x0065, 0x006e, 0x0067, 0x0069, 0x0073, 0x0069, 0x0061, 0x006e, 0x002c, 0x0020, 0x0068, 0x0061, 0x0072, 0x0061, 0x0070, 0x0020, 0x0074, 0x0075, 0x006e, 0x0067, 0x0067, 0x0075, 0x0020, 0x002e, 0x002e, 0x002e, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x0050, 0x0065, 0x006e, 0x0067, 0x0069, 0x0073, 0x0069, 0x0061, 0x006e, 0x0020, 0x0073, 0x0075, 0x0063, 0x0065, 0x0073, 0x0073, 0x0066, 0x0075, 0x006c, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x0050, 0x0065, 0x006e, 0x0067, 0x0069, 0x0073, 0x0069, 0x0061, 0x006e, 0x0020, 0x0067, 0x0061, 0x0067, 0x0061, 0x006c, 0x002c, 0x0020, 0x0073, 0x0069, 0x006c, 0x0061, 0x006b, 0x0061, 0x006e, 0x0020, 0x0063, 0x006f, 0x0062, 0x0061, 0x0020, 0x006c, 0x0061,
			0x0067, 0x0069, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x0052, 0x0070, 0, 0, 0, 0, 0, 0, 0, 0
			}
		},
		{
			{
			1,
			50,
			514,
			1,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'3', '7', '8', '9', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'Z', 'F', 'I', ' ', 'T', 'K', 'M', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			2,
			50,
			514,
			1,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'3', '7', '8', '9', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'Z', 'F', 'I', ' ', 'E', 'C', 'C', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			4,
			50,
			514,
			1,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'3', '7', '8', '9', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'Z', 'F', 'I', ' ', 'I', 'D', 'S', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			8,
			50,
			514,
			1,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'3', '7', '8', '9', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'Z', 'F', 'I', ' ', 'H', 'T', 'C', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			16,
			50,
			514,
			1,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'3', '7', '8', '9', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'Z', 'F', 'I', ' ', 'N', 'T', 'S', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			31,
			50,
			513,
			2,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			//TONE 2 wq001
			{'9', '3', '8', '8', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'T', 'O', 'N', 'E', ' ', '2', ' ', 'w', 'q', '0', '0', '1', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			31,
			50,
			513,
			4,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			//BALL wq001
			{'9', '3', '8', '8', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'B', 'A', 'L', 'L', ' ', 'w', ' q', '0', '0', '1', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			}
		},
		{
			{2000000, 0, 0, 0, 0, 0},
			{2000000, 0, 0, 0, 0, 0},
			{2000000, 0, 0, 0, 0, 0},
			{2000000, 0, 0, 0, 0, 0},
			{2000000, 0, 0, 0, 0, 0},
			{2000000, 0, 0, 0, 0, 0},
			{2000000, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0}
		},
		{
			{'5', '1', '0', '1', '0', 0, 0, 0},
			{'5', '1', '0', '1', '1', 0, 0, 0},
			{'5', '1', '0', '0', '1', 0, 0, 0},
			{'5', '1', '0', '8', '9', 0, 0, 0},
			{'5', '1', '0', '0', '8', 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0}
		},
		{0, 0, 0, 0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0}
		}

	},
	#endif
	#ifdef VM_COUNTRY_MALAYSIA
	{
		{'5', '0', '2', 0},
		{
			0,
			{'5', '0', '2', 0},
			{
			0x0048, 0x0061, 0x0072, 0x0067, 0x0061, 0x0020, 0x0054, 0x0069, 0x0070, 0x0073, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x004f, 0x006b, 0x0065, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x004b, 0x0065, 0x006d, 0x0062, 0x0061, 0x006c, 0x0069, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x0041, 0x006e, 0x0064, 0x0061, 0x0020, 0x0061, 0x006b, 0x0061, 0x006e, 0x0020, 0x006d, 0x0065, 0x006d, 0x0062, 0x0065, 0x006c, 0x0069, 0x0020, 0x005f, 0x005f, 0x0067, 0x006f, 0x006f, 0x0064, 0x006e, 0x0061, 0x006d, 0x0065, 0x005f, 0x005f, 0x002c, 0x0020,
			0x0068, 0x0061, 0x0072, 0x0067, 0x0061, 0x006e, 0x0079, 0x0061, 0x0020, 0x005f, 0x0067, 0x006f, 0x006f, 0x0064, 0x0070, 0x0072, 0x0069, 0x0063, 0x0065, 0x005f, 0x0052, 0x004d, 0x002c, 0x0020, 0x0061, 0x006e, 0x0064, 0x0061, 0x0020, 0x0061, 0x006b, 0x0061,
			0x006e, 0x0020, 0x0062, 0x0065, 0x006c, 0x0069, 0x003f, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x0050, 0x0065, 0x006e, 0x0067, 0x0069, 0x0073, 0x0069, 0x0061, 0x006e, 0x002c, 0x0020, 0x0062, 0x0065, 0x0072, 0x0068, 0x0061, 0x0072, 0x0061, 0x0070, 0x0020, 0x0074, 0x0075, 0x006e, 0x0067, 0x0067, 0x0075, 0x0020, 0x002e, 0x002e, 0x002e, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x0050, 0x0065, 0x006e, 0x0067, 0x0069, 0x0073, 0x0069, 0x0061, 0x006e, 0x0020, 0x0073, 0x0075, 0x0063, 0x0065, 0x0073, 0x0073, 0x0066, 0x0075, 0x006c, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x004d, 0x0065, 0x006e, 0x0067, 0x0069, 0x0073, 0x0069, 0x0020, 0x006b, 0x0065, 0x0067, 0x0061, 0x0067, 0x0061, 0x006c, 0x0061, 0x006e, 0x002c, 0x0020, 0x0073, 0x0069, 0x006c, 0x0061, 0x0020, 0x0063, 0x0075, 0x0062, 0x0061, 0x0020, 0x006c, 0x0061, 0x0067,
			0x0069, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x0052, 0x004d, 0, 0, 0, 0, 0, 0, 0, 0
			}
		},
		{
			{
			1,
			100,
			514,
			1,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'3', '2', '0', '8', '8', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'Z', 'F', 'M', ' ', 'C', 'E', 'L', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			2,
			100,
			514,
			1,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'3', '2', '0', '8', '8', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'Z', 'F', 'M', ' ', 'D', 'I', 'G', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			4,
			100,
			514,
			1,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'3', '2', '0', '8', '8', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'Z', 'F', 'M', ' ', 'M', 'A', 'X', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			}
		},
		{
			{5000, 0, 0, 0, 0, 0},
			{5000, 0, 0, 0, 0, 0},
			{5000, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0}
		},
		{
			{'5', '0', '2', '1', '9', 0, 0, 0},
			{'5', '0', '2', '1', '6', 0, 0, 0},
			{'5', '0', '2', '1', '2', 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0}
		},
		{0, 0, 0, 0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0}
		}

	},
	#endif
	#ifdef VM_COUNTRY_RUSSIAN
	{
		{'2', '5', '0', 0},
		{
			0,
			{'2', '5', '0', 0},
			{
			0x0052, 0x0061, 0x0074, 0x0065, 0x0073, 0x0020, 0x0050, 0x0072, 0x006f, 0x006d, 0x0070, 0x0074, 0x0065, 0x0064, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x004f, 0x004b, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x0042, 0x0061, 0x0063, 0x006b, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x0059, 0x006f, 0x0075, 0x0020, 0x0077, 0x0069, 0x006c, 0x006c, 0x0020, 0x0070, 0x0075, 0x0072, 0x0063, 0x0068, 0x0061, 0x0073, 0x0065, 0x0020, 0x005f, 0x005f, 0x0067, 0x006f, 0x006f, 0x0064, 0x006e, 0x0061, 0x006d, 0x0065, 0x005f, 0x005f, 0x002c, 0x0020,
			0x0074, 0x0068, 0x0065, 0x0020, 0x0070, 0x0072, 0x0069, 0x0063, 0x0065, 0x0020, 0x0069, 0x0073, 0x0020, 0x005f, 0x0067, 0x006f, 0x006f, 0x0064, 0x0070, 0x0072, 0x0069, 0x0063, 0x0065, 0x005f, 0x0072, 0x0075, 0x0062, 0x002c, 0x0020, 0x0077, 0x006f, 0x0075,
			0x006c, 0x0064, 0x0020, 0x0079, 0x006f, 0x0075, 0x0020, 0x0062, 0x0075, 0x0079, 0x003f, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x0043, 0x0068, 0x0061, 0x0072, 0x0067, 0x0069, 0x006e, 0x0067, 0x002c, 0x0020, 0x0070, 0x006c, 0x0065, 0x0061, 0x0073, 0x0065, 0x0020, 0x0077, 0x0061, 0x0069, 0x0074, 0x0020, 0x002e, 0x002e, 0x002e, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x0043, 0x0068, 0x0061, 0x0072, 0x0067, 0x0069, 0x006e, 0x0067, 0x0020, 0x0073, 0x0075, 0x0063, 0x0065, 0x0073, 0x0073, 0x0066, 0x0075, 0x006c, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x0043, 0x0068, 0x0061, 0x0072, 0x0067, 0x0069, 0x006e, 0x0067, 0x0020, 0x0066, 0x0061, 0x0069, 0x006c, 0x0075, 0x0072, 0x0065, 0x002c, 0x0020, 0x0070, 0x006c, 0x0065, 0x0061, 0x0073, 0x0065, 0x0020, 0x0074, 0x0072, 0x0079, 0x0020, 0x0061, 0x0067, 0x0061,
			0x0069, 0x006e, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x0072, 0x0075, 0x0062, 0, 0, 0, 0, 0, 0, 0
			}
		},
		{
			{
			1,
			50,
			514,
			1,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'7', '7', '1', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'Z', 'F', 'R', 'S', 'B', 'E', 'L', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			2,
			50,
			514,
			1,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'7', '7', '1', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'Z', 'F', 'R', 'S', 'M', 'G', 'F', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			4,
			50,
			514,
			1,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'7', '7', '1', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'Z', 'F', 'R', 'S', 'M', 'T', 'S', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			}
		},
		{
			{13000, 0, 0, 0, 0, 0},
			{13000, 0, 0, 0, 0, 0},
			{13000, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0}
		},
		{
			{'2', '5', '0', '9', '9', 0, 0, 0},
			{'2', '5', '0', '0', '2', 0, 0, 0},
			{'2', '5', '0', '0', '1', 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0}
		},
		{0, 0, 0, 0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0}
		}

	},
	#endif
	#ifdef VM_COUNTRY_INDIA
	{
		{'4', '0', '4', 0},
		{
			0,
			{'4', '0', '4', 0},
			{
			0x0052, 0x0061, 0x0074, 0x0065, 0x0073, 0x0020, 0x0050, 0x0072, 0x006f, 0x006d, 0x0070, 0x0074, 0x0065, 0x0064, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x004f, 0x004b, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x0042, 0x0061, 0x0063, 0x006b, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x0059, 0x006f, 0x0075, 0x0020, 0x0077, 0x0069, 0x006c, 0x006c, 0x0020, 0x0070, 0x0075, 0x0072, 0x0063, 0x0068, 0x0061, 0x0073, 0x0065, 0x0020, 0x005f, 0x005f, 0x0067, 0x006f, 0x006f, 0x0064, 0x006e, 0x0061, 0x006d, 0x0065, 0x005f, 0x005f, 0x002c, 0x0020,
			0x0074, 0x0068, 0x0065, 0x0020, 0x0070, 0x0072, 0x0069, 0x0063, 0x0065, 0x0020, 0x0069, 0x0073, 0x0020, 0x005f, 0x0067, 0x006f, 0x006f, 0x0064, 0x0070, 0x0072, 0x0069, 0x0063, 0x0065, 0x005f, 0x0052, 0x0073, 0x002c, 0x0020, 0x0077, 0x006f, 0x0075, 0x006c,
			0x0064, 0x0020, 0x0079, 0x006f, 0x0075, 0x0020, 0x0062, 0x0075, 0x0079, 0x003f, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x0043, 0x0068, 0x0061, 0x0072, 0x0067, 0x0069, 0x006e, 0x0067, 0x002c, 0x0020, 0x0070, 0x006c, 0x0065, 0x0061, 0x0073, 0x0065, 0x0020, 0x0077, 0x0061, 0x0069, 0x0074, 0x0020, 0x002e, 0x002e, 0x002e, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x0043, 0x0068, 0x0061, 0x0072, 0x0067, 0x0069, 0x006e, 0x0067, 0x0020, 0x0073, 0x0075, 0x0063, 0x0065, 0x0073, 0x0073, 0x0066, 0x0075, 0x006c, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x0043, 0x0068, 0x0061, 0x0072, 0x0067, 0x0069, 0x006e, 0x0067, 0x0020, 0x0066, 0x0061, 0x0069, 0x006c, 0x0075, 0x0072, 0x0065, 0x002c, 0x0020, 0x0070, 0x006c, 0x0065, 0x0061, 0x0073, 0x0065, 0x0020, 0x0074, 0x0072, 0x0079, 0x0020, 0x0061, 0x0067, 0x0061,
			0x0069, 0x006e, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0x0052, 0x0073, 0, 0, 0, 0, 0, 0, 0, 0
			}
		},
		{
			{
			15,
			50,
			514,
			1,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'5', '7', '8', '8', '6', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'Z', 'F', 'P', ' ', 'A', 'I', 'C', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			33554416,
			50,
			514,
			1,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'5', '7', '8', '8', '6', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'Z', 'F', 'P', ' ', 'B', 'S', 'N', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			4261412864,
			50,
			514,
			1,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'5', '7', '8', '8', '6', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'Z', 'F', 'P', ' ', 'A', 'I', 'T', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			50,
			514,
			1,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'5', '7', '8', '8', '6', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'Z', 'F', 'P', ' ', 'T', 'A', 'T', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			50,
			514,
			1,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'5', '7', '8', '8', '6', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'Z', 'F', 'P', ' ', 'I', 'D', 'E', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			50,
			514,
			1,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'5', '7', '8', '8', '6', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'Z', 'F', 'P', ' ', 'S', 'P', 'P', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			50,
			514,
			1,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'5', '7', '8', '8', '6', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'Z', 'F', 'P', ' ', 'R', 'E', 'L', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			50,
			514,
			1,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'5', '7', '8', '8', '6', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'Z', 'F', 'P', ' ', 'T', 'E', 'L', 'G', 'M', '0', '3', '3', 'P', 'H', '0', '3', '3', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			}
		},
		{
			{3000, 0, 0, 0, 0, 0},
			{3000, 0, 0, 0, 0, 0},
			{3000, 0, 0, 255, 0, 0},
			{3000, 0, 0, 256, 0, 0},
			{3000, 0, 0, 7680, 0, 0},
			{3000, 0, 0, 8192, 0, 0},
			{3000, 0, 0, 2080768, 0, 0},
			{3000, 0, 0, 31457280, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0}
		},
		{
			{'4', '0', '4', '1', '5', 0, 0, 0},
			{'4', '0', '4', '6', '0', 0, 0, 0},
			{'4', '0', '4', '0', '1', 0, 0, 0},
			{'4', '0', '4', '4', '2', 0, 0, 0},
			{'4', '0', '4', '3', '4', 0, 0, 0},
			{'4', '0', '4', '3', '8', 0, 0, 0},
			{'4', '0', '4', '5', '1', 0, 0, 0},
			{'4', '0', '4', '5', '3', 0, 0, 0},
			{'4', '0', '4', '5', '4', 0, 0, 0},
			{'4', '0', '4', '5', '5', 0, 0, 0},
			{'4', '0', '4', '5', '7', 0, 0, 0},
			{'4', '0', '4', '5', '8', 0, 0, 0},
			{'4', '0', '4', '5', '9', 0, 0, 0},
			{'4', '0', '4', '6', '2', 0, 0, 0},
			{'4', '0', '4', '6', '4', 0, 0, 0},
			{'4', '0', '4', '6', '6', 0, 0, 0},
			{'4', '0', '4', '7', '1', 0, 0, 0},
			{'4', '0', '4', '7', '2', 0, 0, 0},
			{'4', '0', '4', '7', '3', 0, 0, 0},
			{'4', '0', '4', '7', '4', 0, 0, 0},
			{'4', '0', '4', '7', '5', 0, 0, 0},
			{'4', '0', '4', '7', '6', 0, 0, 0},
			{'4', '0', '4', '7', '7', 0, 0, 0},
			{'4', '0', '4', '7', '9', 0, 0, 0},
			{'4', '0', '4', '8', '0', 0, 0, 0},
			{'4', '0', '4', '1', '0', 0, 0, 0},
			{'4', '0', '4', '3', '1', 0, 0, 0},
			{'4', '0', '4', '9', '6', 0, 0, 0},
			{'4', '0', '4', '9', '5', 0, 0, 0},
			{'4', '0', '4', '9', '4', 0, 0, 0},
			{'4', '0', '4', '9', '7', 0, 0, 0},
			{'4', '0', '4', '9', '2', 0, 0, 0}
		},
		{
			{'4', '0', '4', '9', '8', 0, 0, 0},
			{'4', '0', '4', '9', '0', 0, 0, 0},
			{'4', '0', '4', '9', '3', 0, 0, 0},
			{'4', '0', '4', '4', '5', 0, 0, 0},
			{'4', '0', '4', '4', '9', 0, 0, 0},
			{'4', '0', '4', '0', '2', 0, 0, 0},
			{'4', '0', '4', '4', '0', 0, 0, 0},
			{'4', '0', '4', '0', '3', 0, 0, 0},
			{'4', '0', '4', '0', '7', 0, 0, 0},
			{'4', '0', '4', '2', '2', 0, 0, 0},
			{'4', '0', '4', '2', '4', 0, 0, 0},
			{'4', '0', '4', '0', '4', 0, 0, 0},
			{'4', '0', '4', '7', '8', 0, 0, 0},
			{'4', '0', '4', '1', '4', 0, 0, 0},
			{'4', '0', '4', '0', '9', 0, 0, 0},
			{'4', '0', '4', '1', '8', 0, 0, 0},
			{'4', '0', '4', '3', '6', 0, 0, 0},
			{'4', '0', '4', '5', '0', 0, 0, 0},
			{'4', '0', '4', '5', '2', 0, 0, 0},
			{'4', '0', '4', '6', '7', 0, 0, 0},
			{'4', '0', '4', '8', '5', 0, 0, 0},
			{'4', '0', '4', '1', '3', 0, 0, 0},
			{'4', '0', '4', '1', '1', 0, 0, 0},
			{'4', '0', '4', '0', '5', 0, 0, 0},
			{'4', '0', '4', '8', '6', 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0}
		},
		{0, 0, 0, 0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0}
		}

	},
	#endif
	#ifdef VM_COUNTRY_CHINA
	{
		{'4', '6', '0', 0},
		{
			0,
			{'4', '6', '0', 0},
			{
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			},
			{
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0
			}
		},
		{
			{
			5,
			100,
			513,
			1,
			{0x597d, 0x7ba1, 0x5bb6, 0, 0, 0, 0, 0, 0, 0, 0},
			{0x5317, 0x4eac, 0x8d5e, 0x6210, 0, 0, 0, 0, 0},
			{'0', '1', '0', '-', '6', '4', '4', '6', '5', '9', '1', '5', 0, 0, 0, 0},
			{'1', '0', '6', '6', '2', '5', '6', '6', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'E', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			2,
			100,
			514,
			1,
			{0x56fd, 0x9645, 0x5929, 0x6c14, 0x9884, 0x62a5, 0, 0, 0, 0, 0},
			{0x957f, 0x6c99, 0x638c, 0x8baf, 0x002d, 0x8054, 0x901a, 0, 0},
			{'0', '1', '0', '-', '6', '2', '0', '4', '5', '6', '9', '9', 0, 0, 0, 0},
			{'1', '0', '6', '6', '7', '7', '6', '6', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{'G', 'J', 'T', 'Q', ' ', '1', '2', '4', ' ', '2', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			},
			{
			0,
			0,
			0,
			0,
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			}
		},
		{
			{1000, 0, 0, 0, 0, 0},
			{1000, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0}
		},
		{
			{'4', '6', '0', '0', '0', 0, 0, 0},
			{'4', '6', '0', '0', '1', 0, 0, 0},
			{'4', '6', '0', '0', '2', 0, 0, 0},
			{'4', '6', '0', '0', '3', 0, 0, 0},
			{'4', '6', '0', '0', '5', 0, 0, 0},
			{'4', '6', '0', '0', '6', 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0}
		},
		{0, 1, 0, 65541,
			{0x672c, 0x6b21, 0x5bc6, 0x7801, 0, 0, 0, 0, 0, 0, 0, 0},
			{0xff0c, 0}

		}

	}
	#endif

};
*/
#endif

#endif


#define  GLOBAL_PAYMENT_TEST


VMINT vm_set_payment_info(void)
{
	#ifdef VRE_GLOBAL_VERSION
	VMINT i = 0;
	VMCHAR plmn[8]={0};
	VMCHAR mcc[4]={0};
	
	VMINT res = 0;
	vm_time_t time_stamps[5];
	vm_time_t pay_time;

	vm_pay_notification_t *pay_notification_ptr = NULL;
	
	vm_nvram_paychannel_list_ext_t * paychannel_list_ptr = NULL;
	vm_nvram_operator_code_list_t  *operator_code_list_ptr0 = NULL;
 	vm_pay_config_ext_t  *pay_config_ptr = NULL;
	vm_nvram_paychannel_a_list_ext_t  *paychannel_a_list_ptr = NULL;
	vm_nvram_operator_code_list_t  *operator_code_list_ptr1 = NULL;
	vm_nvram_operator_code_list_t  *operator_code_list_ptr2 = NULL;
	vm_nvram_operator_code_list_t  *operator_code_list_ptr3 = NULL;
	vm_nvram_paychannel_usage_list_t  *paychannel_usage_list_ptr = NULL;
	
	vm_log_warn("vm_set_payment_info start");

	if (vm_query_operator_code(plmn, sizeof(plmn))!= 0)
	{
		return VM_PAY_QUERY_OPERATOR_ERROR;
	}

	strncpy(mcc, plmn, 3);

	pay_notification_ptr = vm_calloc(sizeof(vm_pay_notification_t));
	if (pay_notification_ptr == NULL)
	{
		return VM_PAY_INTERNAL_ERROR;
	}
	vm_get_pay_notification(pay_notification_ptr);

	if (strncmp(pay_notification_ptr->mcc, mcc, 3) == 0)
	{
		vm_free(pay_notification_ptr);
		vm_log_warn("vm_set_payment_info: VM_PAY_DONT_SET,pay_notification_ptr->mcc=%s,mcc=%s",pay_notification_ptr->mcc, mcc);
		return VM_PAY_DONT_SET;
	}

	
	memset(&time_stamps, 0, sizeof(time_stamps));
	memset(&pay_time, 0, sizeof(pay_time));
					
	pay_config_ptr = vm_calloc(sizeof(vm_pay_config_ext_t));
	if(pay_config_ptr == NULL)
	{
		vm_free(pay_notification_ptr);
		return VM_PAY_INTERNAL_ERROR;
	}
			
	for (i=0; i< VM_PAY_INFO_LEN; i++)
	{
		
		if(strncmp(mcc, vm_payment_info_csr[i].mcc,3)==0)
		{
			paychannel_list_ptr = vm_calloc(sizeof(vm_nvram_paychannel_list_ext_t));
			if(paychannel_list_ptr == NULL)
			{
				vm_free(pay_notification_ptr);
				vm_free(pay_config_ptr);
				return VM_PAY_INTERNAL_ERROR;
			}
			
			operator_code_list_ptr0 = vm_calloc(sizeof(vm_nvram_operator_code_list_t));
			if(operator_code_list_ptr0 == NULL)
			{
				vm_free(pay_notification_ptr);
				vm_free(pay_config_ptr);
				vm_free(paychannel_list_ptr);
				return VM_PAY_INTERNAL_ERROR;
			}
					
		
			paychannel_a_list_ptr = vm_calloc(sizeof(vm_nvram_paychannel_a_list_ext_t));
			if(paychannel_a_list_ptr == NULL)
			{
				vm_free(pay_notification_ptr);
				vm_free(pay_config_ptr);
				vm_free(paychannel_list_ptr);
				vm_free(operator_code_list_ptr0);
				return VM_PAY_INTERNAL_ERROR;
			}
			
			operator_code_list_ptr1 = vm_calloc(sizeof(vm_nvram_operator_code_list_t));
			if(operator_code_list_ptr1 == NULL)
			{
				vm_free(pay_notification_ptr);
				vm_free(pay_config_ptr);
				vm_free(paychannel_list_ptr);
				vm_free(operator_code_list_ptr0);
				vm_free(paychannel_a_list_ptr);
				return VM_PAY_INTERNAL_ERROR;
			}
			
			operator_code_list_ptr2 = vm_calloc(sizeof(vm_nvram_operator_code_list_t));
			if(operator_code_list_ptr2 == NULL)
			{
				vm_free(pay_notification_ptr);
				vm_free(pay_config_ptr);
				vm_free(paychannel_list_ptr);
				vm_free(operator_code_list_ptr0);
				vm_free(paychannel_a_list_ptr);
				vm_free(operator_code_list_ptr1);
				return VM_PAY_INTERNAL_ERROR;
			}
			
			operator_code_list_ptr3 = vm_calloc(sizeof(vm_nvram_operator_code_list_t));
			if(operator_code_list_ptr3 == NULL)
			{
				vm_free(pay_notification_ptr);
				vm_free(pay_config_ptr);
				vm_free(paychannel_list_ptr);
				vm_free(operator_code_list_ptr0);	
				vm_free(paychannel_a_list_ptr);
				vm_free(operator_code_list_ptr1);
				vm_free(operator_code_list_ptr2);
				return VM_PAY_INTERNAL_ERROR;
			}

			paychannel_usage_list_ptr = vm_calloc(sizeof(vm_nvram_paychannel_usage_list_t));
			if(paychannel_usage_list_ptr == NULL)
			{
				vm_free(pay_notification_ptr);
				vm_free(pay_config_ptr);
				vm_free(paychannel_list_ptr);
				vm_free(operator_code_list_ptr0);
				vm_free(paychannel_a_list_ptr);
				vm_free(operator_code_list_ptr1);
				vm_free(operator_code_list_ptr2);
				vm_free(operator_code_list_ptr3);
				return VM_PAY_INTERNAL_ERROR;
			}
		

			memset(pay_notification_ptr, 0, sizeof(pay_notification_ptr));
			
			if(vm_payment_info_csr[i].vm_notification_p != NULL)
			{
				memcpy(pay_notification_ptr, vm_payment_info_csr[i].vm_notification_p, sizeof(vm_pay_notification_t));
			}

			if(vm_payment_info_csr[i].vm_paychannel_p != NULL)
			{
				memcpy(paychannel_list_ptr->paychannel_list_ext, vm_payment_info_csr[i].vm_paychannel_p, sizeof(vm_paychannel_ext_t) * vm_payment_info_csr[i].paychannel_len);
			}

			if(vm_payment_info_csr[i].vm_paychannel_a_ext_p != NULL)
			{
				memcpy(paychannel_a_list_ptr->paychannel_a_list_ext, vm_payment_info_csr[i].vm_paychannel_a_ext_p, sizeof(vm_paychannel_a_ext_t) * vm_payment_info_csr[i].paychannel_a_ext_len);
			}

			if(vm_payment_info_csr[i].vm_operator_info0_p != NULL)
			{
				memcpy(operator_code_list_ptr0->operator_code_list, vm_payment_info_csr[i].vm_operator_info0_p, sizeof(vm_operator_code_t) * vm_payment_info_csr[i].operator_info_len0);
			}

			if(vm_payment_info_csr[i].vm_operator_info1_p != NULL)
			{
				memcpy(operator_code_list_ptr1->operator_code_list, vm_payment_info_csr[i].vm_operator_info1_p, sizeof(vm_operator_code_t) * vm_payment_info_csr[i].operator_info_len1);
			}

			if(vm_payment_info_csr[i].vm_operator_info2_p != NULL)
			{
				memcpy(operator_code_list_ptr2->operator_code_list, vm_payment_info_csr[i].vm_operator_info2_p, sizeof(vm_operator_code_t) * vm_payment_info_csr[i].operator_info_len2);
			}

			if(vm_payment_info_csr[i].vm_operator_info2_p != NULL)
			{
				memcpy(operator_code_list_ptr3->operator_code_list, vm_payment_info_csr[i].vm_operator_info3_p, sizeof(vm_operator_code_t) * vm_payment_info_csr[i].operator_info_len3);
			}
		
					
			res = vm_set_pay_notification(pay_notification_ptr);
			if(res == FALSE)
				vm_log_error("vm_set_pay_notification error");
			
			res = vm_set_pay_channel_list_ext(paychannel_list_ptr);
			if(res == FALSE)
				vm_log_error("vm_set_pay_channel_list_ext error");

			res = vm_set_pay_channel_a_list_ext(paychannel_a_list_ptr);
			if(res == FALSE)
				vm_log_error("vm_set_pay_channel_a_list_ext error");

			res = vm_set_operator_code(operator_code_list_ptr0);
			if(res == FALSE)
				vm_log_error("vm_set_operator_code error 0");
						
			res = vm_set_operator_code_ext(1, operator_code_list_ptr1);
			if(res == FALSE)
				vm_log_error("vm_set_operator_code error 1");

			res = vm_set_operator_code_ext(2, operator_code_list_ptr2);
			if(res == FALSE)
				vm_log_error("vm_set_operator_code error 2");
		
			res = vm_set_operator_code_ext(3, operator_code_list_ptr3);
			if(res == FALSE)
				vm_log_error("vm_set_operator_code error 3");

			res = vm_get_pay_config_ext(pay_config_ptr);
			if(res != FALSE)		
			{
				if(vm_payment_info_csr[i].vm_pay_config_info != NULL)
				{
					pay_config_ptr->sms_notification_flag = vm_payment_info_csr[i].vm_pay_config_info->sms_notification_flag;
					pay_config_ptr->update_interval_days = vm_payment_info_csr[i].vm_pay_config_info->update_interval_days;
					pay_config_ptr->reserved = vm_payment_info_csr[i].vm_pay_config_info->reserved;
					vm_wstrcpy(pay_config_ptr->pre_string, (VMWSTR)vm_payment_info_csr[i].vm_pay_config_info->pre_string);
					vm_wstrcpy(pay_config_ptr->suff_string, (VMWSTR)vm_payment_info_csr[i].vm_pay_config_info->suff_string);
				}
				else
				{
					pay_config_ptr->update_interval_days = 0;
				}
				res = vm_set_pay_config_ext(pay_config_ptr);
				if(res == FALSE)
				vm_log_error("vm_set_pay_config error");
			}
		
		
			if (vm_load_timestamps_record(time_stamps) == VM_ADAPTER_NVRAM_SUCCESS)
			{
				if (vm_merge_timestamp(time_stamps, &pay_time, VM_NVRAM_CHARGE_CHANNEL_LST_TIMESTAMP))
					vm_save_timestamps_record(time_stamps);
			}
		
			res = vm_set_paychannel_usage_list(paychannel_usage_list_ptr);	
			if(res == FALSE)
				vm_log_error("vm_set_paychannel_usage_list error");

						
			#ifdef   GLOBAL_PAYMENT_TEST

	
			memset(pay_notification_ptr, 0, sizeof(vm_pay_notification_t));
			memset(paychannel_list_ptr, 0, sizeof(vm_nvram_paychannel_list_ext_t));
			memset(operator_code_list_ptr0, 0, sizeof(vm_nvram_operator_code_list_t));
			memset(pay_config_ptr, 0, sizeof(vm_pay_config_t));

			memset(paychannel_a_list_ptr, 0, sizeof(vm_nvram_paychannel_a_list_ext_t));
			memset(operator_code_list_ptr1, 0, sizeof(vm_nvram_operator_code_list_t));
			memset(operator_code_list_ptr2, 0, sizeof(vm_nvram_operator_code_list_t));
			memset(operator_code_list_ptr3, 0, sizeof(vm_nvram_operator_code_list_t));

			memset(paychannel_usage_list_ptr, 0, sizeof(vm_nvram_paychannel_usage_list_t));
			
			res = vm_get_pay_notification(pay_notification_ptr);
			if(res == FALSE)
				vm_log_error("vm_get_pay_notification error");
				
			vm_log_debug("pay_notification_ptr->rate=%d",pay_notification_ptr->rate);
			vm_log_debug("pay_notification_ptr->mcc=%s",pay_notification_ptr->mcc);
			vm_log_debug("pay_notification_ptr->title=%s",vm_gb2312_string((VMWSTR)pay_notification_ptr->title));
			vm_log_debug("pay_notification_ptr->OK=%s",vm_gb2312_string((VMWSTR)pay_notification_ptr->ok));
			vm_log_debug("pay_notification_ptr->back=%s",vm_gb2312_string((VMWSTR)pay_notification_ptr->back));
			vm_log_debug("pay_notification_ptr->notification1=%s",vm_gb2312_string((VMWSTR)pay_notification_ptr->notification1));
			vm_log_debug("pay_notification_ptr->notification2=%s",vm_gb2312_string((VMWSTR)pay_notification_ptr->notification2));
			vm_log_debug("pay_notification_ptr->notification3=%s",vm_gb2312_string((VMWSTR)pay_notification_ptr->notification3));
			vm_log_debug("pay_notification_ptr->notification4=%s",vm_gb2312_string((VMWSTR)pay_notification_ptr->notification4));
			vm_log_debug("pay_notification_ptr->currency_unit=%s\n",vm_gb2312_string((VMWSTR)pay_notification_ptr->currency_unit));

			res = vm_get_pay_channel_list_ext(paychannel_list_ptr);
			if(res == FALSE)
				vm_log_error("vm_get_pay_channel_list_ext error");

			res = vm_get_pay_channel_a_list_ext(paychannel_a_list_ptr);
			if(res == FALSE)
				vm_log_error("vm_get_pay_channel_a_list_ext error");
			
			for(i=0; i< NVRAM_PAYMENT_CHANNEL_EXT_NUM; i++)
			{
			  vm_log_debug("paychannel_list_ptr->paychannel_list_ext[%d].operator_bitmap=%u", i, paychannel_list_ptr->paychannel_list_ext[i].operator_bitmap);
			  vm_log_debug("paychannel_list_ptr->paychannel_list_ext[%d].fee=%u",i,paychannel_list_ptr->paychannel_list_ext[i].fee);
			  vm_log_debug("paychannel_list_ptr->paychannel_list_ext[%d].sms_type=%u",i,paychannel_list_ptr->paychannel_list_ext[i].sms_type);
			  vm_log_debug("paychannel_list_ptr->paychannel_list_ext[%d].org_id=%u",i,paychannel_list_ptr->paychannel_list_ext[i].org_id);
			  vm_log_debug("paychannel_list_ptr->paychannel_list_ext[%d].service_name=%s",i,vm_gb2312_string((VMWSTR)paychannel_list_ptr->paychannel_list_ext[i].service_name));
			  vm_log_debug("paychannel_list_ptr->paychannel_list_ext[%d].sp_name=%s",i,vm_gb2312_string((VMWSTR)paychannel_list_ptr->paychannel_list_ext[i].sp_name));
			  vm_log_debug("paychannel_list_ptr->paychannel_list_ext[%d].customer_number=%s",i,paychannel_list_ptr->paychannel_list_ext[i].customer_number);
			  vm_log_debug("paychannel_list_ptr->paychannel_list_ext[%d].sms_id=%s",i,paychannel_list_ptr->paychannel_list_ext[i].sms_id);
			  vm_log_debug("paychannel_list_ptr->paychannel_list_ext[%d].sms_content=%s",i,paychannel_list_ptr->paychannel_list_ext[i].sms_content);
			  
			  vm_log_debug("paychannel_a_list_ptr->paychannel_a_list_ext[%d].fee_actual=%u", i, paychannel_a_list_ptr->paychannel_a_list_ext[i].fee_actual);
			  vm_log_debug("paychannel_a_list_ptr->paychannel_a_list_ext[%d].reserv1=%d", i, paychannel_a_list_ptr->paychannel_a_list_ext[i].reserv1);
			  vm_log_debug("paychannel_a_list_ptr->paychannel_a_list_ext[%d].reserv2=%d", i, paychannel_a_list_ptr->paychannel_a_list_ext[i].reserv2);
			  vm_log_debug("paychannel_a_list_ptr->paychannel_a_list_ext[%d].operator_bitmap2=%u", i, paychannel_a_list_ptr->paychannel_a_list_ext[i].operator_bitmap2);
			  vm_log_debug("paychannel_a_list_ptr->paychannel_a_list_ext[%d].operator_bitmap3=%u", i, paychannel_a_list_ptr->paychannel_a_list_ext[i].operator_bitmap3);
			  vm_log_debug("paychannel_a_list_ptr->paychannel_a_list_ext[%d].operator_bitmap4=%u\n", i, paychannel_a_list_ptr->paychannel_a_list_ext[i].operator_bitmap4);

			}

			
			res = vm_get_operator_code(operator_code_list_ptr0);
			if(res == FALSE)
				vm_log_error("vm_get_operator_code error");
			for(i=0; i< NVRAM_OPERATE_CODE_LIST_NUM; i++)
			{
			  vm_log_debug("0operator_code_list_ptr->operator_code_list[%d].operator_code=%s",i, operator_code_list_ptr0->operator_code_list[i].operator_code);
			  
			}

			res = vm_get_operator_code_ext(1, operator_code_list_ptr1);
			if(res == FALSE)
				vm_log_error("vm_get_operator_code_ext error 1");
			
			for(i=0; i< NVRAM_OPERATE_CODE_LIST_NUM; i++)
			{
			  vm_log_debug("1operator_code_list_ptr2->operator_code_list[%d].operator_code=%s",i, operator_code_list_ptr1->operator_code_list[i].operator_code);
			  
			}

			res = vm_get_operator_code_ext(2, operator_code_list_ptr2);
			if(res == FALSE)
				vm_log_error("vm_get_operator_code_ext error 2");
			for(i=0; i< NVRAM_OPERATE_CODE_LIST_NUM; i++)
			{
			  vm_log_debug("2operator_code_list_ptr3->operator_code_list[%d].operator_code=%s",i, operator_code_list_ptr2->operator_code_list[i].operator_code);
			  
			}
				
			res = vm_get_operator_code_ext(3, operator_code_list_ptr3);
			if(res == FALSE)
				vm_log_error("vm_get_operator_code_ext error 3");
			
			for(i=0; i< NVRAM_OPERATE_CODE_LIST_NUM; i++)
			{
			  vm_log_debug("3operator_code_list_ptr4->operator_code_list[%d].operator_code=%s",i, operator_code_list_ptr3->operator_code_list[i].operator_code);
			  
			}
			
			res = vm_get_pay_config_ext(pay_config_ptr);
			if(res == FALSE)
				vm_log_error("vm_get_pay_config error");
			vm_log_debug("pay_config_ptr->update_interval_days=%d",pay_config_ptr->update_interval_days);
			vm_log_debug("pay_config_ptr->sms_notification_flag=%d",pay_config_ptr->sms_notification_flag);
			vm_log_debug("pay_config_ptr->user_balance=%d",pay_config_ptr->user_balance);
			vm_log_debug("pay_config_ptr->reserved=%d",pay_config_ptr->reserved);
			vm_log_debug("pay_config_ptr->pre_string=%s",vm_gb2312_string(pay_config_ptr->pre_string));
			vm_log_debug("pay_config_ptr->suff_string=%s",vm_gb2312_string(pay_config_ptr->suff_string));
			
		/*	res = vm_get_paychannel_usage_list(paychannel_usage_list_ptr);	
			if(res == FALSE)
				vm_log_error("vm_set_paychannel_usage_list error");

			for(i=0; i< NVRAM_PAYMENT_CHANNEL_EXT_NUM; i++)
			{
			  vm_log_debug("paychannel_usage_list_ptr->paychannel_usage_list_ext[%d].year=%u", i, paychannel_usage_list_ptr->paychannel_usage_list_ext[i].year);
			  vm_log_debug("paychannel_usage_list_ptr->paychannel_usage_list_ext[%d].month=%u",i,paychannel_usage_list_ptr->paychannel_usage_list_ext[i].month);
			  vm_log_debug("paychannel_usage_list_ptr->paychannel_usage_list_ext[%d].day=%u",i,paychannel_usage_list_ptr->paychannel_usage_list_ext[i].day);
			  vm_log_debug("paychannel_usage_list_ptr->paychannel_usage_list_ext[%d].daily_used_num=%u",i,paychannel_usage_list_ptr->paychannel_usage_list_ext[i].daily_used_num);
			  vm_log_debug("paychannel_usage_list_ptr->paychannel_usage_list_ext[%d].monthly_used_num=%u",i,paychannel_usage_list_ptr->paychannel_usage_list_ext[i].monthly_used_num);
			  vm_log_debug("paychannel_usage_list_ptr->paychannel_usage_list_ext[%d].reserv1=%d",i,paychannel_usage_list_ptr->paychannel_usage_list_ext[i].reserv1);
			  vm_log_debug("paychannel_usage_list_ptr->paychannel_usage_list_ext[%d].reserv2=%d",i,paychannel_usage_list_ptr->paychannel_usage_list_ext[i].reserv2);
				
			}*/

			
			#endif

			vm_free(pay_notification_ptr);
			vm_free(pay_config_ptr);
			vm_free(paychannel_list_ptr);
			vm_free(operator_code_list_ptr0);
			vm_free(paychannel_a_list_ptr);
			vm_free(operator_code_list_ptr1);
			vm_free(operator_code_list_ptr2);
			vm_free(operator_code_list_ptr3);
			vm_free(paychannel_usage_list_ptr);
		
			return VM_PAY_NO_ERROR;
		}
		
	}

	if(i == VM_PAY_INFO_LEN)
	{
		res = vm_get_pay_config_ext(pay_config_ptr);
		if(res != FALSE)		
		{
			pay_config_ptr->update_interval_days = 0;
			
			res = vm_set_pay_config_ext(pay_config_ptr);
			if(res == FALSE)
				vm_log_error("vm_set_pay_config error  VM_PAY_INFO_LEN");
		}

		if (vm_load_timestamps_record(time_stamps) == VM_ADAPTER_NVRAM_SUCCESS)
		{
			if (vm_merge_timestamp(time_stamps, &pay_time, VM_NVRAM_CHARGE_CHANNEL_LST_TIMESTAMP))
					vm_save_timestamps_record(time_stamps);
		}
	
	}
	
	vm_free(pay_notification_ptr);
	vm_free(pay_config_ptr);
	return VM_PAY_NOT_FOUND;
#else

	return VM_PAY_INTERNAL_ERROR;
#endif
}




/*
VMINT vm_set_payment_info(void)
{
	#ifdef VRE_GLOBAL_VERSION
	VMINT i = 0;
	VMCHAR plmn[8]={0};
	VMCHAR mcc[4]={0};
	//vm_pay_notification_t * pay_notification = NULL;
	VMINT res = 0;
	vm_time_t time_stamps[5];
	vm_time_t pay_time;

	vm_pay_notification_t *pay_notification_ptr = NULL;
	
	vm_nvram_paychannel_list_ext_t * paychannel_list_ptr = NULL;
	vm_nvram_operator_code_list_t  *operator_code_list_ptr = NULL;
 	vm_pay_config_ext_t  *pay_config_ptr = NULL;
	vm_nvram_paychannel_a_list_ext_t  *paychannel_a_list_ptr = NULL;
	vm_nvram_operator_code_list_t  *operator_code_list_ptr2 = NULL;
	vm_nvram_operator_code_list_t  *operator_code_list_ptr3 = NULL;
	vm_nvram_operator_code_list_t  *operator_code_list_ptr4 = NULL;
	vm_nvram_paychannel_usage_list_t  *paychannel_usage_list_ptr = NULL;
	
	vm_log_warn("vm_set_payment_info start");

	if (vm_query_operator_code(plmn, sizeof(plmn))!= 0)
	{
		return VM_PAY_QUERY_OPERATOR_ERROR;
	}

	strncpy(mcc, plmn, 3);

	pay_notification_ptr = vm_calloc(sizeof(vm_pay_notification_t));
	if (pay_notification_ptr == NULL)
	{
		return VM_PAY_INTERNAL_ERROR;
	}
	vm_get_pay_notification(pay_notification_ptr);

	if (strncmp(pay_notification_ptr->mcc, mcc, 3) == 0)
	{
		vm_free(pay_notification_ptr);
		vm_log_warn("vm_set_payment_info: VM_PAY_DONT_SET");
		return VM_PAY_DONT_SET;
	}

	
	memset(&time_stamps, 0, sizeof(time_stamps));
	memset(&pay_time, 0, sizeof(pay_time));
					
	pay_config_ptr = vm_calloc(sizeof(vm_pay_config_ext_t));
	if(pay_config_ptr == NULL)
	{
		vm_free(pay_notification_ptr);
		return VM_PAY_INTERNAL_ERROR;
	}
			
	for (i=0; i< VM_PAY_INFO_LEN; i++)
	{
		
		if(strncmp(mcc, vm_payment_info[i].mcc,3)==0)
		{
			paychannel_list_ptr = vm_calloc(sizeof(vm_nvram_paychannel_list_ext_t));
			if(paychannel_list_ptr == NULL)
			{
				vm_free(pay_notification_ptr);
				vm_free(pay_config_ptr);
				return VM_PAY_INTERNAL_ERROR;
			}
			
			operator_code_list_ptr = vm_calloc(sizeof(vm_nvram_operator_code_list_t));
			if(operator_code_list_ptr == NULL)
			{
				vm_free(pay_notification_ptr);
				vm_free(pay_config_ptr);
				vm_free(paychannel_list_ptr);
				return VM_PAY_INTERNAL_ERROR;
			}
					
			
			paychannel_a_list_ptr = vm_calloc(sizeof(vm_nvram_paychannel_a_list_ext_t));
			if(paychannel_a_list_ptr == NULL)
			{
				vm_free(pay_notification_ptr);
				vm_free(pay_config_ptr);
				vm_free(paychannel_list_ptr);
				vm_free(operator_code_list_ptr);
				return VM_PAY_INTERNAL_ERROR;
			}
			
			operator_code_list_ptr2 = vm_calloc(sizeof(vm_nvram_operator_code_list_t));
			if(operator_code_list_ptr2 == NULL)
			{
				vm_free(pay_notification_ptr);
				vm_free(pay_config_ptr);
				vm_free(paychannel_list_ptr);
				vm_free(operator_code_list_ptr);
				vm_free(paychannel_a_list_ptr);
				return VM_PAY_INTERNAL_ERROR;
			}
			
			operator_code_list_ptr3 = vm_calloc(sizeof(vm_nvram_operator_code_list_t));
			if(operator_code_list_ptr3 == NULL)
			{
				vm_free(pay_notification_ptr);
				vm_free(pay_config_ptr);
				vm_free(paychannel_list_ptr);
				vm_free(operator_code_list_ptr);
				vm_free(paychannel_a_list_ptr);
				vm_free(operator_code_list_ptr2);
				return VM_PAY_INTERNAL_ERROR;
			}
			
			operator_code_list_ptr4 = vm_calloc(sizeof(vm_nvram_operator_code_list_t));
			if(operator_code_list_ptr4 == NULL)
			{
				vm_free(pay_notification_ptr);
				vm_free(pay_config_ptr);
				vm_free(paychannel_list_ptr);
				vm_free(operator_code_list_ptr);	
				vm_free(paychannel_a_list_ptr);
				vm_free(operator_code_list_ptr2);
				vm_free(operator_code_list_ptr3);
				return VM_PAY_INTERNAL_ERROR;
			}

			paychannel_usage_list_ptr = vm_calloc(sizeof(vm_nvram_paychannel_usage_list_t));
			if(paychannel_usage_list_ptr == NULL)
			{
				vm_free(pay_notification_ptr);
				vm_free(pay_config_ptr);
				vm_free(paychannel_list_ptr);
				vm_free(operator_code_list_ptr);
				vm_free(paychannel_a_list_ptr);
				vm_free(operator_code_list_ptr2);
				vm_free(operator_code_list_ptr3);
				vm_free(operator_code_list_ptr4);
				return VM_PAY_INTERNAL_ERROR;
			}
		

			memset(pay_notification_ptr, 0, sizeof(pay_notification_ptr));
			
			memcpy(pay_notification_ptr, (void *)&vm_payment_info[i].vm_notification_info, sizeof(vm_pay_notification_t));
			memcpy(paychannel_list_ptr->paychannel_list_ext, (void *)vm_payment_info[i].vm_paychannel_info, sizeof(paychannel_list_ptr->paychannel_list_ext));
			memcpy(operator_code_list_ptr->operator_code_list, (void *)vm_payment_info[i].vm_operator_info, sizeof(operator_code_list_ptr->operator_code_list));
		

			memcpy(paychannel_a_list_ptr->paychannel_a_list_ext, (void *)vm_payment_info[i].vm_paychannel_a_ext, sizeof(paychannel_a_list_ptr->paychannel_a_list_ext));
			memcpy(operator_code_list_ptr2->operator_code_list, (void *)vm_payment_info[i].vm_operator_info2, sizeof(operator_code_list_ptr2->operator_code_list));
			memcpy(operator_code_list_ptr3->operator_code_list, (void *)vm_payment_info[i].vm_operator_info3, sizeof(operator_code_list_ptr3->operator_code_list));
			memcpy(operator_code_list_ptr4->operator_code_list, (void *)vm_payment_info[i].vm_operator_info4, sizeof(operator_code_list_ptr4->operator_code_list));

		//	memcpy(paychannel_usage_list_ptr->paychannel_usage_list_ext, (void *)vm_paychannel_usage_list[i].paychannel_usage_list_ext, sizeof(paychannel_usage_list_ptr->paychannel_usage_list_ext));

					
			res = vm_set_pay_notification(pay_notification_ptr);
			if(res == FALSE)
				vm_log_error("vm_set_pay_notification error");
			
			res = vm_set_pay_channel_list_ext(paychannel_list_ptr);
			if(res == FALSE)
				vm_log_error("vm_set_pay_channel_list_ext error");

			res = vm_set_pay_channel_a_list_ext(paychannel_a_list_ptr);
			if(res == FALSE)
				vm_log_error("vm_set_pay_channel_a_list_ext error");

			res = vm_set_operator_code(operator_code_list_ptr);
			if(res == FALSE)
				vm_log_error("vm_set_operator_code error 0");
						
			res = vm_set_operator_code_ext(1, operator_code_list_ptr2);
			if(res == FALSE)
				vm_log_error("vm_set_operator_code error 1");

			res = vm_set_operator_code_ext(2, operator_code_list_ptr3);
			if(res == FALSE)
				vm_log_error("vm_set_operator_code error 2");
		
			res = vm_set_operator_code_ext(3, operator_code_list_ptr4);
			if(res == FALSE)
				vm_log_error("vm_set_operator_code error 3");

			res = vm_get_pay_config_ext(pay_config_ptr);
			if(res != FALSE)		
			{
		
				pay_config_ptr->sms_notification_flag = vm_payment_info[i].vm_pay_config_info.sms_notification_flag;
				pay_config_ptr->update_interval_days = vm_payment_info[i].vm_pay_config_info.update_interval_days;
				pay_config_ptr->reserved = vm_payment_info[i].vm_pay_config_info.reserved;
				vm_wstrcpy(pay_config_ptr->pre_string, (VMWSTR)vm_payment_info[i].vm_pay_config_info.pre_string);
				vm_wstrcpy(pay_config_ptr->suff_string, (VMWSTR)vm_payment_info[i].vm_pay_config_info.suff_string);
				res = vm_set_pay_config_ext(pay_config_ptr);
				if(res == FALSE)
				vm_log_error("vm_set_pay_config error");
			}
		
		
			if (vm_load_timestamps_record(time_stamps) == VM_ADAPTER_NVRAM_SUCCESS)
			{
				if (vm_merge_timestamp(time_stamps, &pay_time, VM_NVRAM_CHARGE_CHANNEL_LST_TIMESTAMP))
					vm_save_timestamps_record(time_stamps);
			}
		
			res = vm_set_paychannel_usage_list(paychannel_usage_list_ptr);	
			if(res == FALSE)
				vm_log_error("vm_set_paychannel_usage_list error");

						
			#ifdef   GLOBAL_PAYMENT_TEST

	
			memset(pay_notification_ptr, 0, sizeof(vm_pay_notification_t));
			memset(paychannel_list_ptr, 0, sizeof(vm_nvram_paychannel_list_ext_t));
			memset(operator_code_list_ptr, 0, sizeof(vm_nvram_operator_code_list_t));
			memset(pay_config_ptr, 0, sizeof(vm_pay_config_t));

			memset(paychannel_a_list_ptr, 0, sizeof(vm_nvram_paychannel_a_list_ext_t));
			memset(operator_code_list_ptr2, 0, sizeof(vm_nvram_operator_code_list_t));
			memset(operator_code_list_ptr3, 0, sizeof(vm_nvram_operator_code_list_t));
			memset(operator_code_list_ptr4, 0, sizeof(vm_nvram_operator_code_list_t));

			memset(paychannel_usage_list_ptr, 0, sizeof(vm_nvram_paychannel_usage_list_t));
			
			res = vm_get_pay_notification(pay_notification_ptr);
			if(res == FALSE)
				vm_log_error("vm_get_pay_notification error");
				
			vm_log_debug("pay_notification_ptr->rate=%d",pay_notification_ptr->rate);
			vm_log_debug("pay_notification_ptr->mcc=%s",pay_notification_ptr->mcc);
			vm_log_debug("pay_notification_ptr->title=%s",vm_gb2312_string((VMWSTR)pay_notification_ptr->title));
			vm_log_debug("pay_notification_ptr->OK=%s",vm_gb2312_string((VMWSTR)pay_notification_ptr->ok));
			vm_log_debug("pay_notification_ptr->back=%s",vm_gb2312_string((VMWSTR)pay_notification_ptr->back));
			vm_log_debug("pay_notification_ptr->notification1=%s",vm_gb2312_string((VMWSTR)pay_notification_ptr->notification1));
			vm_log_debug("pay_notification_ptr->notification2=%s",vm_gb2312_string((VMWSTR)pay_notification_ptr->notification2));
			vm_log_debug("pay_notification_ptr->notification3=%s",vm_gb2312_string((VMWSTR)pay_notification_ptr->notification3));
			vm_log_debug("pay_notification_ptr->notification4=%s",vm_gb2312_string((VMWSTR)pay_notification_ptr->notification4));
			vm_log_debug("pay_notification_ptr->currency_unit=%s\n",vm_gb2312_string((VMWSTR)pay_notification_ptr->currency_unit));

			res = vm_get_pay_channel_list_ext(paychannel_list_ptr);
			if(res == FALSE)
				vm_log_error("vm_get_pay_channel_list_ext error");

			res = vm_get_pay_channel_a_list_ext(paychannel_a_list_ptr);
			if(res == FALSE)
				vm_log_error("vm_get_pay_channel_a_list_ext error");
			
			for(i=0; i< NVRAM_PAYMENT_CHANNEL_EXT_NUM; i++)
			{
			  vm_log_debug("paychannel_list_ptr->paychannel_list_ext[%d].operator_bitmap=%u", i, paychannel_list_ptr->paychannel_list_ext[i].operator_bitmap);
			  vm_log_debug("paychannel_list_ptr->paychannel_list_ext[%d].fee=%u",i,paychannel_list_ptr->paychannel_list_ext[i].fee);
			  vm_log_debug("paychannel_list_ptr->paychannel_list_ext[%d].sms_type=%u",i,paychannel_list_ptr->paychannel_list_ext[i].sms_type);
			  vm_log_debug("paychannel_list_ptr->paychannel_list_ext[%d].org_id=%u",i,paychannel_list_ptr->paychannel_list_ext[i].org_id);
			  vm_log_debug("paychannel_list_ptr->paychannel_list_ext[%d].service_name=%s",i,vm_gb2312_string((VMWSTR)paychannel_list_ptr->paychannel_list_ext[i].service_name));
			  vm_log_debug("paychannel_list_ptr->paychannel_list_ext[%d].sp_name=%s",i,vm_gb2312_string((VMWSTR)paychannel_list_ptr->paychannel_list_ext[i].sp_name));
			  vm_log_debug("paychannel_list_ptr->paychannel_list_ext[%d].customer_number=%s",i,paychannel_list_ptr->paychannel_list_ext[i].customer_number);
			  vm_log_debug("paychannel_list_ptr->paychannel_list_ext[%d].sms_id=%s",i,paychannel_list_ptr->paychannel_list_ext[i].sms_id);
			  vm_log_debug("paychannel_list_ptr->paychannel_list_ext[%d].sms_content=%s",i,paychannel_list_ptr->paychannel_list_ext[i].sms_content);
			  
			  vm_log_debug("paychannel_a_list_ptr->paychannel_a_list_ext[%d].fee_actual=%u", i, paychannel_a_list_ptr->paychannel_a_list_ext[i].fee_actual);
			  vm_log_debug("paychannel_a_list_ptr->paychannel_a_list_ext[%d].reserv1=%d", i, paychannel_a_list_ptr->paychannel_a_list_ext[i].reserv1);
			  vm_log_debug("paychannel_a_list_ptr->paychannel_a_list_ext[%d].reserv2=%d", i, paychannel_a_list_ptr->paychannel_a_list_ext[i].reserv2);
			  vm_log_debug("paychannel_a_list_ptr->paychannel_a_list_ext[%d].operator_bitmap2=%u", i, paychannel_a_list_ptr->paychannel_a_list_ext[i].operator_bitmap2);
			  vm_log_debug("paychannel_a_list_ptr->paychannel_a_list_ext[%d].operator_bitmap3=%u", i, paychannel_a_list_ptr->paychannel_a_list_ext[i].operator_bitmap3);
			  vm_log_debug("paychannel_a_list_ptr->paychannel_a_list_ext[%d].operator_bitmap4=%u\n", i, paychannel_a_list_ptr->paychannel_a_list_ext[i].operator_bitmap4);

			}

			
			res = vm_get_operator_code(operator_code_list_ptr);
			if(res == FALSE)
				vm_log_error("vm_get_operator_code error");
			for(i=0; i< NVRAM_OPERATE_CODE_LIST_NUM; i++)
			{
			  vm_log_debug("1operator_code_list_ptr->operator_code_list[%d].operator_code=%s",i, operator_code_list_ptr->operator_code_list[i].operator_code);
			  
			}

			res = vm_get_operator_code_ext(1, operator_code_list_ptr2);
			if(res == FALSE)
				vm_log_error("vm_get_operator_code_ext error 1");
			
			for(i=0; i< NVRAM_OPERATE_CODE_LIST_NUM; i++)
			{
			  vm_log_debug("2operator_code_list_ptr2->operator_code_list[%d].operator_code=%s",i, operator_code_list_ptr2->operator_code_list[i].operator_code);
			  
			}

			res = vm_get_operator_code_ext(2, operator_code_list_ptr3);
			if(res == FALSE)
				vm_log_error("vm_get_operator_code_ext error 2");
			for(i=0; i< NVRAM_OPERATE_CODE_LIST_NUM; i++)
			{
			  vm_log_debug("3operator_code_list_ptr3->operator_code_list[%d].operator_code=%s",i, operator_code_list_ptr3->operator_code_list[i].operator_code);
			  
			}
				
			res = vm_get_operator_code_ext(3, operator_code_list_ptr4);
			if(res == FALSE)
				vm_log_error("vm_get_operator_code_ext error 3");
			
			for(i=0; i< NVRAM_OPERATE_CODE_LIST_NUM; i++)
			{
			  vm_log_debug("4operator_code_list_ptr4->operator_code_list[%d].operator_code=%s",i, operator_code_list_ptr4->operator_code_list[i].operator_code);
			  
			}
			
			res = vm_get_pay_config_ext(pay_config_ptr);
			if(res == FALSE)
				vm_log_error("vm_get_pay_config error");
			vm_log_debug("pay_config_ptr->update_interval_days=%d",pay_config_ptr->update_interval_days);
			vm_log_debug("pay_config_ptr->sms_notification_flag=%d",pay_config_ptr->sms_notification_flag);
			vm_log_debug("pay_config_ptr->user_balance=%d",pay_config_ptr->user_balance);
			vm_log_debug("pay_config_ptr->reserved=%d",pay_config_ptr->reserved);
			vm_log_debug("pay_config_ptr->pre_string=%s",vm_gb2312_string(pay_config_ptr->pre_string));
			vm_log_debug("pay_config_ptr->suff_string=%s",vm_gb2312_string(pay_config_ptr->suff_string));
			
			res = vm_get_paychannel_usage_list(paychannel_usage_list_ptr);	
			if(res == FALSE)
				vm_log_error("vm_set_paychannel_usage_list error");

			for(i=0; i< NVRAM_PAYMENT_CHANNEL_EXT_NUM; i++)
			{
			  vm_log_debug("paychannel_usage_list_ptr->paychannel_usage_list_ext[%d].year=%u", i, paychannel_usage_list_ptr->paychannel_usage_list_ext[i].year);
			  vm_log_debug("paychannel_usage_list_ptr->paychannel_usage_list_ext[%d].month=%u",i,paychannel_usage_list_ptr->paychannel_usage_list_ext[i].month);
			  vm_log_debug("paychannel_usage_list_ptr->paychannel_usage_list_ext[%d].day=%u",i,paychannel_usage_list_ptr->paychannel_usage_list_ext[i].day);
			  vm_log_debug("paychannel_usage_list_ptr->paychannel_usage_list_ext[%d].daily_used_num=%u",i,paychannel_usage_list_ptr->paychannel_usage_list_ext[i].daily_used_num);
			  vm_log_debug("paychannel_usage_list_ptr->paychannel_usage_list_ext[%d].monthly_used_num=%u",i,paychannel_usage_list_ptr->paychannel_usage_list_ext[i].monthly_used_num);
			  vm_log_debug("paychannel_usage_list_ptr->paychannel_usage_list_ext[%d].reserv1=%d",i,paychannel_usage_list_ptr->paychannel_usage_list_ext[i].reserv1);
			  vm_log_debug("paychannel_usage_list_ptr->paychannel_usage_list_ext[%d].reserv2=%d",i,paychannel_usage_list_ptr->paychannel_usage_list_ext[i].reserv2);
		
		
			}

			
			#endif

			vm_free(pay_notification_ptr);
			vm_free(pay_config_ptr);
			vm_free(paychannel_list_ptr);
			vm_free(operator_code_list_ptr);
			vm_free(paychannel_a_list_ptr);
			vm_free(operator_code_list_ptr2);
			vm_free(operator_code_list_ptr3);
			vm_free(operator_code_list_ptr4);
			vm_free(operator_code_list_ptr4);
			vm_free(paychannel_usage_list_ptr);
		
			return VM_PAY_NO_ERROR;
		}
		
	}

	if(i == VM_PAY_INFO_LEN)
	{
		res = vm_get_pay_config_ext(pay_config_ptr);
		if(res != FALSE)		
		{
			pay_config_ptr->update_interval_days = 0;
			
			res = vm_set_pay_config_ext(pay_config_ptr);
			if(res == FALSE)
				vm_log_error("vm_set_pay_config error  VM_PAY_INFO_LEN");
		}

		if (vm_load_timestamps_record(time_stamps) == VM_ADAPTER_NVRAM_SUCCESS)
		{
			if (vm_merge_timestamp(time_stamps, &pay_time, VM_NVRAM_CHARGE_CHANNEL_LST_TIMESTAMP))
					vm_save_timestamps_record(time_stamps);
		}
	
	}
	
	vm_free(pay_notification_ptr);
	vm_free(pay_config_ptr);
	return VM_PAY_NOT_FOUND;
#else

	return VM_PAY_INTERNAL_ERROR;
#endif
}
*/



/************************************************/
#ifdef VRE_GLOBAL_VERSION/*Include all inner function*/

#define VM_APN_MCC_LEN 3
#define VM_APN_PLMN_MAX_LEN 7

void showapninfo(vm_apn_info *current_apn_info,VMINT id)
{
        vm_log_warn("[GLOBAL]showapninfo%d:apn_info_id = %d",id,current_apn_info->apn_info_id);
        vm_log_warn("[GLOBAL]showapninfo%d:account name = %s",id,current_apn_info->operator_name);
        vm_log_warn("[GLOBAL]showapninfo%d:plmn = %s",id,current_apn_info->operator_id);
        vm_log_warn("[GLOBAL]showapninfo%d:apn_proxy  = %s",id,current_apn_info->apn_proxy);
        vm_log_warn("[GLOBAL]showapninfo%d:apn_no_proxy  = %s",id,current_apn_info->apn_no_proxy);
        vm_log_warn("[GLOBAL]showapninfo%d:proxyip  = %s",id,current_apn_info->proxy_ip);
        vm_log_warn("[GLOBAL]showapninfo%d:port  = %d",id,current_apn_info->proxy_port);
        vm_log_warn("[GLOBAL]showapninfo%d:wapusername  = %s",id,current_apn_info->wap_user_name);
        vm_log_warn("[GLOBAL]showapninfo%d:wappassword  = %s",id,current_apn_info->wap_pass_word);        
        vm_log_warn("[GLOBAL]showapninfo%d:netusername  = %s",id,current_apn_info->net_user_name);
        vm_log_warn("[GLOBAL]showapninfo%d:netpassword  = %s",id,current_apn_info->net_pass_word); 

}


static VMINT vm_global_read_mcc_and_plmn_from_imsi(VMCHAR *mccstr,VMCHAR *plmnstr)
{
	
	VMCHAR *buf;
	if (!mccstr && !plmnstr)
		return VM_APN_INTERNAL_ERROR;

	if ((buf = vm_malloc(VM_APN_PLMN_MAX_LEN)) == NULL)
		return VM_APN_INTERNAL_ERROR;
	memset(buf, 0, VM_APN_PLMN_MAX_LEN);

	if (vm_query_operator_code(buf,VM_APN_PLMN_MAX_LEN) != 0) 
	{
		vm_free(buf);
		return VM_APN_NOT_FIND_SIM_CARD;
	}
	
	if (mccstr)
		strncpy(mccstr,buf,	VM_APN_MCC_LEN);
	if (plmnstr)
		strncpy(plmnstr,buf,VM_APN_PLMN_MAX_LEN);

	vm_free(buf);
	return VM_APN_OK;
}




static VMINT vm_local_read_setting_from_nvram(vm_local_info * local_info_ptr,VMCHAR *mccstr)
{
	vm_local_info * local_info;

	if (!mccstr && !local_info_ptr)
		return VM_APN_INTERNAL_ERROR;	
	vm_log_warn("[GLOBAL] vm_local_read_setting_from_nvram Begin");
	if ((local_info = vm_malloc(sizeof(vm_local_info))) == NULL)
		return VM_APN_INTERNAL_ERROR;
	vm_log_warn("[GLOBAL] vm_local_read_setting_from_nvram Read Begin");	
    memset(local_info,0,sizeof(vm_local_info));
	if (vm_get_local_apn_info(local_info) == FALSE)
	{
		vm_free(local_info);
		return VM_APN_READ_NVRAM_ERROR;

	}
	vm_log_warn("[GLOBAL] vm_local_read_setting_from_nvram Read End");	
	if (mccstr)
		strncpy(mccstr,local_info->mcc,VM_APN_MCC_LEN);

	if (local_info_ptr)
		memcpy(local_info_ptr,local_info,sizeof(vm_local_info));
	vm_free(local_info);
	return VM_APN_OK;
}



static VMINT vm_apn_read_setting_from_nvram(vm_apn_info * apn_info_ptr)
{
	vm_apn_info * apn_info;

	if (!apn_info_ptr)
		return VM_APN_INTERNAL_ERROR;	
	vm_log_warn("[GLOBAL] vm_apn_read_setting_from_nvram Begin");
	if ((apn_info = vm_malloc(sizeof(vm_apn_info))) == NULL)
		return VM_APN_INTERNAL_ERROR;
	vm_log_warn("[GLOBAL] vm_apn_read_setting_from_nvram Read Begin");	
    memset(apn_info,0,sizeof(vm_apn_info));
	if (vm_get_user_apn_info(apn_info) == FALSE)
	{
    	vm_log_warn("[GLOBAL] vm_apn_read_setting_from_nvram Read error");	
		vm_free(apn_info);
		return VM_APN_READ_NVRAM_ERROR;

	}
	vm_log_warn("[GLOBAL] vm_apn_read_setting_from_nvram Read End");	

	if (apn_info_ptr)
		memcpy(apn_info_ptr,apn_info,sizeof(vm_apn_info));
	vm_free(apn_info);
	return VM_APN_OK;
}




static VMINT vm_local_write_setting_to_nvram(vm_local_info *local_info)
{
	VMINT i;
	if (!local_info)
		return VM_APN_INTERNAL_ERROR;

	if (vm_set_local_apn_info(local_info) == FALSE)
		return VM_APN_WRITE_NVRAM_ERROR;
	return VM_APN_OK;
}


static VMINT vm_apn_write_setting_to_nvram(vm_apn_info *apn_info)
{
	VMINT i;
	if (!apn_info)
		return VM_APN_INTERNAL_ERROR;

	if (vm_set_user_apn_info(apn_info) == FALSE)
		return VM_APN_WRITE_NVRAM_ERROR;
	return VM_APN_OK;
}



static VMINT vm_apn_cmp_mcc(VMCHAR *mccstr1,VMCHAR *mccstr2)
{
	if ((!mccstr1) || (!mccstr2))
		return VM_APN_INTERNAL_ERROR;	
	
	if (vm_string_equals_ignore_case(mccstr1,mccstr2) == 0)
		return VM_APN_OK;
	return VM_APN_NOT_EQUAL;
}

static VMINT vm_apn_cmp_plmn(VMCHAR *plmnstr1,VMCHAR *plmnstr2)
{
	if ((!plmnstr1) || (!plmnstr2))
		return VM_APN_INTERNAL_ERROR;	
	
	if (vm_string_equals_ignore_case(plmnstr1,plmnstr2) == 0)
		return VM_APN_OK;
	return VM_APN_NOT_EQUAL;
}


static VMINT vm_apn_cmp_operator_id(VMCHAR *apn_operator_id,VMCHAR *plmnstr)
{
    VMCHAR plmnstr_short[VM_APN_PLMN_MAX_LEN-1];
    if ((!apn_operator_id) || (!plmnstr))
		return VM_APN_NOT_EQUAL;	
	
	if (vm_string_equals_ignore_case(apn_operator_id,plmnstr) == 0)
		return VM_APN_OK;
    else 
    {
        strncpy(plmnstr_short,plmnstr,VM_APN_PLMN_MAX_LEN-2);
	    if (vm_string_equals_ignore_case(apn_operator_id,plmnstr_short) == 0)
		    return VM_APN_OK;        
    }
	return VM_APN_NOT_EQUAL;
}






static VMINT vm_check_current_apn_info(vm_apn_info *current_apninfo,VMCHAR *plmnstr)
{
    if (current_apninfo->apn_info_id < 1)
        return VM_APN_INTERNAL_ERROR;
    if (vm_apn_cmp_operator_id(current_apninfo->operator_id,plmnstr) == VM_APN_OK)
        return VM_APN_OK;
    return VM_APN_INTERNAL_ERROR;
    
}



static VMINT vm_local_read_info_from_rom(vm_local_info *localinfo,VMCHAR *mccstr)
{
	VMINT i;
	if ((!mccstr) || (!localinfo))
		return VM_APN_INTERNAL_ERROR;
	for (i = 0; i< VM_LOCAL_ROM_RECORD_COUNT;i++)
	{
		if (vm_string_equals_ignore_case(mccstr,vm_local_info_table[i].mcc) == 0)
			break;
	}
	if (i == VM_LOCAL_ROM_RECORD_COUNT)
		memcpy(localinfo,&vm_default_local_info,sizeof(vm_local_info));
	else
		memcpy(localinfo,(vm_apn_info *)&vm_local_info_table[i],sizeof(vm_local_info));
	return VM_APN_OK;
}

static VMINT vm_local_read_default_from_rom(vm_local_info *localinfo)
{
	VMINT i;
	if (!localinfo)
		return VM_APN_INTERNAL_ERROR;
	memcpy(localinfo,&vm_default_local_info,sizeof(vm_local_info));
	return VM_APN_OK;
}

/*Use New APN structure*/
#ifndef VRE_USE_NEW_APN_STRUCT
static VMINT vm_apn_read_info_from_rom(vm_apn_info *apninfo,VMCHAR *plmnstr)
{
	VMINT i=0,j=0,table_index = 0;
	VMCHAR plmn_short[VM_APN_PLMN_MAX_LEN-1];
	if ((!plmnstr) || (!apninfo))
		return VM_APN_INTERNAL_ERROR;

	memset(plmn_short,0,VM_APN_PLMN_MAX_LEN-1);
    vm_log_warn("[GLOBAL] -vm_apn_read_apn_info_from_rom : plmnstr = %s",plmnstr);
	for (i = 0; i< VM_APN_ROM_RECORD_COUNT;i++)
	{
		//vm_log_warn("[GLOBAL] -vm_apn_read_apn_info_from_rom : vm_apn_info_table.operator_id = %s",vm_apn_info_table[i].operator_id);		
		if (vm_string_equals_ignore_case(plmnstr,vm_apn_info_table[i].operator_id) == 0)
		{
			table_index = i;
			break;
		}	
	}
	if (i == VM_APN_ROM_RECORD_COUNT)
	{
		strncpy(plmn_short,plmnstr,VM_APN_PLMN_MAX_LEN-2);
        vm_log_warn("[GLOBAL] -vm_apn_read_apn_info_from_rom : plmn_short = %s",plmn_short);
		for (j = 0; j< VM_APN_ROM_RECORD_COUNT;j++)
		{
			//vm_log_warn("[GLOBAL] -vm_apn_read_apn_info_from_rom : vm_apn_info_table.operator_id = %s",vm_apn_info_table[j].operator_id);		
			if (vm_string_equals_ignore_case(plmn_short,vm_apn_info_table[j].operator_id) == 0)
			{
				table_index = j;
				break;
			}	
		}
	}
	if (j == VM_APN_ROM_RECORD_COUNT)
		return 	VM_APN_NOT_FOUND_RECORD;	

	memcpy(apninfo,(vm_apn_info *)&vm_apn_info_table[table_index],sizeof(vm_apn_info));
	return VM_APN_OK;
}

#else

static void vm_apn_info_transfer_struct(vm_apn_info *apninfo,const vm_apn_info_internal *apninfoint,VMCHAR *plmnstr)
{
    VMINT len;
    apninfo->apn_info_id = 1;
    apninfo->proxy_port = apninfoint->proxy_port;
    
    strncpy(apninfo->operator_name,apninfoint->operator_name,strlen(apninfoint->operator_name));
    strncpy(apninfo->proxy_ip,apninfoint->proxy_ip,strlen(apninfoint->proxy_ip));
    strncpy(apninfo->operator_id,plmnstr,strlen(plmnstr));
    
    if (strlen(apninfoint->apn_proxy) > VRE_MAX_GPRS_APN_LEN-1)
        len = VRE_MAX_GPRS_APN_LEN - 1;
    else
        len = strlen(apninfoint->apn_proxy);
    strncpy(apninfo->apn_proxy,apninfoint->apn_proxy,len);

    if (strlen(apninfoint->apn_no_proxy) > VRE_MAX_GPRS_APN_LEN-1)
        len = VRE_MAX_GPRS_APN_LEN - 1;
    else
        len = strlen(apninfoint->apn_no_proxy);  
    strncpy(apninfo->apn_no_proxy,apninfoint->apn_no_proxy,len);

    if (strlen(apninfoint->wap_user_name) > VRE_MAX_GPRS_USER_NAME_LEN-1)
        len = VRE_MAX_GPRS_USER_NAME_LEN - 1;
    else
        len = strlen(apninfoint->wap_user_name);
    strncpy(apninfo->wap_user_name,apninfoint->wap_user_name,len);

    if (strlen(apninfoint->net_user_name) > VRE_MAX_GPRS_USER_NAME_LEN-1)
        len = VRE_MAX_GPRS_USER_NAME_LEN - 1;
    else
        len = strlen(apninfoint->net_user_name);    
    strncpy(apninfo->net_user_name,apninfoint->net_user_name,len);

    if (strlen(apninfoint->wap_pass_word) > VRE_MAX_GPRS_PASSWORD_LEN-1)
        len = VRE_MAX_GPRS_PASSWORD_LEN - 1;
    else
        len = strlen(apninfoint->wap_pass_word);    
    strncpy(apninfo->wap_pass_word,apninfoint->wap_pass_word,len);

    if (strlen(apninfoint->net_pass_word) > VRE_MAX_GPRS_PASSWORD_LEN-1)
        len = VRE_MAX_GPRS_PASSWORD_LEN - 1;
    else
        len = strlen(apninfoint->net_pass_word);    
    strncpy(apninfo->net_pass_word,apninfoint->net_pass_word,len);
}


static VMINT vm_apn_read_info_from_rom_ext(vm_apn_info *apninfo,VMCHAR *plmnstr)
{
	VMINT i=0,j=0,table_index = -1;
    VMSTR p,q;
	VMCHAR plmn_short[VM_APN_PLMN_MAX_LEN-1];
    VMCHAR plmn_long[VM_APN_PLMN_MAX_LEN];
	if ((!plmnstr) || (!apninfo))
		return VM_APN_INTERNAL_ERROR;

	memset(plmn_short,0,VM_APN_PLMN_MAX_LEN-1);
    memset(plmn_long,0,VM_APN_PLMN_MAX_LEN);
	vm_log_warn("[GLOBAL] -vm_apn_read_apn_info_from_rom : plmnstr = %s",plmnstr);
	for (i = 0; i< VM_APN_ROM_RECORD_COUNT;i++)
	{
		
		//vm_log_warn("[GLOBAL] -vm_apn_read_apn_info_from_rom : vm_apn_info_table.operator_id = %s",vm_apn_info_table_internal[i].operator_id);		
        if (vm_string_equals_ignore_case(plmnstr,vm_apn_info_table_internal[i].operator_id) == 0)
        {
  			table_index = i;
   			break;
   		}
        p = q = vm_apn_info_table_internal[i].operator_id;
        while(p[0])
        {
	
            if(p[0] == ',')
            {
                
                memset(plmn_long,0,VM_APN_PLMN_MAX_LEN);
				strncpy(plmn_long,q,p-q);
	
                if (vm_string_equals_ignore_case(plmnstr,plmn_long) == 0)
        		{
        			table_index = i;
        			break;
        		}
                p++;
                q = p;
            }
            p++;

        }
        if (table_index<0)
    	{
            memset(plmn_long,0,VM_APN_PLMN_MAX_LEN);
			strncpy(plmn_long,q,p-q);
            //vm_log_warn("[GLOBAL] -vm_apn_read_apn_info_from_rom : plmn_long = %s",plmn_long);
            if (vm_string_equals_ignore_case(plmnstr,plmn_long) == 0)
        	{
        		table_index = i;
        		break;
        	}
        }
        else
            break;
	}
	if (i == VM_APN_ROM_RECORD_COUNT)
	{
		strncpy(plmn_short,plmnstr,VM_APN_PLMN_MAX_LEN-2);
        //vm_log_warn("[GLOBAL] -vm_apn_read_apn_info_from_rom : plmn_short = %s",plmn_short);	
		for (j = 0; j< VM_APN_ROM_RECORD_COUNT;j++)
		{
            if (vm_string_equals_ignore_case(plmn_short,vm_apn_info_table_internal[j].operator_id) == 0)
            {
  			    table_index = j;
   			    break;
   		    }

            
    		//vm_log_warn("[GLOBAL] -vm_apn_read_apn_info_from_rom : vm_apn_info_table.operator_id = %s",vm_apn_info_table_internal[j].operator_id);		
            p = q = vm_apn_info_table_internal[j].operator_id;
            while(p[0])
            {
                //vm_log_warn("[GLOBAL] -vm_apn_read_apn_info_from_rom : p = %s",p);		
                if(p[0] == ',')
                {
                    memset(plmn_long,0,VM_APN_PLMN_MAX_LEN);
                    strncpy(plmn_long,q,p-q);
                    //vm_log_warn("[GLOBAL] -vm_apn_read_apn_info_from_rom : plmn_long = %s",plmn_long);		
                    if (vm_string_equals_ignore_case(plmn_short,plmn_long) == 0)
            		{
            			table_index = j;
            			break;
            		}
                    p++;
                    q = p;
                    
                }
                //vm_log_warn("[GLOBAL] -vm_apn_read_apn_info_from_rom : q = %s",q);
                p++;

            }
            if (table_index<0)
    		{
				memset(plmn_long,0,VM_APN_PLMN_MAX_LEN);
                strncpy(plmn_long,q,p-q);
                //vm_log_warn("[GLOBAL] -vm_apn_read_apn_info_from_rom : plmn_long = %s",plmn_long);
                if (vm_string_equals_ignore_case(plmn_short,plmn_long) == 0)
        		{
        			table_index = j;
        			break;
        		}
            }
            else
                break;
		}
	}
	if (j == VM_APN_ROM_RECORD_COUNT)
		return 	VM_APN_NOT_FOUND_RECORD;
	vm_log_warn("[GLOBAL] -vm_apn_read_apn_info_from_rom_ext:table_index=%d",table_index);
    vm_apn_info_transfer_struct(apninfo,&vm_apn_info_table_internal[table_index],strlen(plmn_short) == 0 ? plmnstr : plmn_short);
	return VM_APN_OK;
}

#endif/*VRE_USE_NEW_APN_STRUCT Function */

#endif/*VRE_GLOBAL_VERSION End*/




VMINT vm_get_local_setting(vm_local_info *current_local_info)
{
#ifdef VRE_GLOBAL_VERSION
	VMCHAR cur_mccstr[VM_APN_MCC_LEN] = {0};
	VMCHAR nvram_mccstr[VM_APN_MCC_LEN] = {0};
	VMCHAR cur_plmnstr[VM_APN_PLMN_MAX_LEN] = {0};
	VMINT ret;

	if (!current_local_info)
		return VM_APN_INTERNAL_ERROR;
	memset(current_local_info , 0, sizeof(vm_local_info));
	memset(cur_mccstr , 0, sizeof(cur_mccstr));
	memset(nvram_mccstr , 0, sizeof(nvram_mccstr));	
	memset(cur_plmnstr , 0, sizeof(cur_plmnstr));
	current_local_info ->local_info_id = -1;
	
	if ((ret = vm_global_read_mcc_and_plmn_from_imsi(cur_mccstr,cur_plmnstr)) < VM_APN_OK)
    {
        if(ret!=VM_APN_NOT_FIND_SIM_CARD)
            return VM_APN_INTERNAL_ERROR;
        vm_local_read_default_from_rom(current_local_info);
		vm_log_warn("[GLOBAL]vm_get_local_setting :(NOT FIND SIM)read default_local_info from rom  lang = %d",current_local_info->lang);
		vm_log_warn("[GLOBAL]vm_get_local_setting :(NOT FIND SIM)read default_local_info from rom  default_local_info addr= %s",current_local_info->provision_addr);				
		if (vm_local_write_setting_to_nvram(current_local_info)< VM_APN_OK)
			return VM_APN_WRITE_NVRAM_ERROR;  
        return VM_APN_OK;
    }   

	vm_log_warn("[GLOBAL]vm_get_local_setting :cur_mccstr = %s,cur_plmnstr=%s",cur_mccstr,cur_plmnstr);

    vm_local_read_setting_from_nvram(current_local_info,nvram_mccstr) ;
	vm_log_warn("[GLOBAL]vm_get_local_setting :nvram_mccstr = %s",nvram_mccstr);
	if (vm_apn_cmp_mcc(cur_mccstr,nvram_mccstr) == VM_APN_OK) 
	{
		vm_set_payment_info();
		return VM_APN_OK;
	}

	
	if  ((ret = vm_local_read_info_from_rom(current_local_info,cur_mccstr)) < VM_APN_OK)
	{
		vm_log_warn("[GLOBAL]vm_get_local_setting :read info from rom  current_local_info lang = %d",current_local_info->lang);
		vm_log_warn("[GLOBAL]vm_get_local_setting :read info from rom  current_local_info addr= %s",current_local_info->provision_addr);
		if (ret == VM_APN_NOT_FOUND_RECORD)
		{	
			vm_local_read_default_from_rom(current_local_info);
			vm_log_warn("[GLOBAL]vm_get_local_setting :read info from rom  default_local_info lang = %d",current_local_info->lang);
			vm_log_warn("[GLOBAL]vm_get_local_setting :read info from rom  default_local_info addr= %s",current_local_info->provision_addr);				
			if (vm_local_write_setting_to_nvram(current_local_info)< VM_APN_OK)
				return VM_APN_WRITE_NVRAM_ERROR;
		}
		else
			return VM_APN_INTERNAL_ERROR;
	}
	else
	{

		vm_log_warn("[GLOBAL]vm_get_local_setting :read info  current_local_info lang = %d,mcc = %s",current_local_info->lang,current_local_info->mcc);
		vm_log_warn("[GLOBAL]vm_get_local_setting :read info  current_local_info addr= %s",current_local_info->provision_addr);
		if (vm_local_write_setting_to_nvram(current_local_info)< VM_APN_OK)
			return VM_APN_WRITE_NVRAM_ERROR;	
		
		vm_set_payment_info();	
	}
    return VM_APN_OK;
#else
	return VM_APN_INTERNAL_ERROR;
#endif

}


VMINT vm_get_local_setting_for_app(vm_local_info  *current_local_info)
{
#ifdef VRE_GLOBAL_VERSION
	if (!current_local_info)
		return VM_APN_INTERNAL_ERROR;
	memset(current_local_info , 0, sizeof(vm_local_info));

	if (vm_local_read_setting_from_nvram(current_local_info,NULL) < VM_APN_OK)
		return VM_APN_READ_NVRAM_ERROR; 
	return VM_APN_OK;
#else
	return VM_APN_INTERNAL_ERROR;
#endif

}




/*VMINT vm_get_current_apn(vm_apn_info *current_apn_info)
{
#ifdef VRE_GLOBAL_VERSION	
	VMCHAR cur_mccstr[VM_APN_MCC_LEN] = {0};
	VMCHAR cur_plmnstr[VM_APN_PLMN_MAX_LEN] = {0};
	if (!current_apn_info)
		return VM_APN_INTERNAL_ERROR;
	memset(current_apn_info , 0, sizeof(vm_apn_info));
	vm_log_warn("[GLOBAL]vm_get_current_apn :Begin");	
	if (vm_global_read_mcc_and_plmn_from_imsi(cur_mccstr,cur_plmnstr) < VM_APN_OK)
		return VM_APN_INTERNAL_ERROR;
	vm_log_warn("[GLOBAL]vm_get_current_apn :cur_mccstr = %s,cur_plmnstr=%s",cur_mccstr,cur_plmnstr);
	
	if (vm_apn_read_info_from_rom(current_apn_info,cur_plmnstr)< VM_APN_OK)
		return VM_APN_NOT_FOUND_RECORD;
	vm_log_warn("[GLOBAL]vm_get_current_apn :read info  current_apn_info proxyapn  = %s",current_apn_info->apn_proxy);
	vm_log_warn("[GLOBAL]vm_get_current_apn :read info  current_apn_info noproxyapn = %s",current_apn_info->apn_no_proxy);
	vm_log_warn("[GLOBAL]vm_get_current_apn :read info  current_apn_info operator_id= %s",current_apn_info->operator_id);
	return VM_APN_OK;
#else
	return VM_APN_INTERNAL_ERROR;
#endif
}*/


VMINT vm_get_current_apn(vm_apn_info *current_apn_info)
{
#ifdef VRE_GLOBAL_VERSION	
	VMCHAR cur_mccstr[VM_APN_MCC_LEN] = {0};
	VMCHAR cur_plmnstr[VM_APN_PLMN_MAX_LEN] = {0};
	if (!current_apn_info)
		return VM_APN_INTERNAL_ERROR;
	memset(current_apn_info , 0, sizeof(vm_apn_info));
	vm_log_warn("[GLOBAL]vm_get_current_apn :Begin");

    //从IMSI号中读取PLMN号
	if (vm_global_read_mcc_and_plmn_from_imsi(cur_mccstr,cur_plmnstr) < VM_APN_OK)
		return VM_APN_INTERNAL_ERROR;
	vm_log_warn("[GLOBAL]vm_get_current_apn :cur_mccstr = %s,cur_plmnstr=%s",cur_mccstr,cur_plmnstr);
    
    //从NVRAM中读取apn_info
    if (vm_apn_read_setting_from_nvram(current_apn_info) == VM_APN_OK)
    {

        //比较NVRAM中的apn_info->operator_id和当前的PLMN是否一致
        //因为只有VRE内置列表没有，才会写到NVRAM中，所以如果一致，则不用再去找VRE内置列表。
        vm_log_warn("[GLOBAL]vm_get_current_apn :read nvram apn_info_id = %d",current_apn_info->apn_info_id);
        vm_log_warn("[GLOBAL]vm_get_current_apn :read nvram account name = %s",current_apn_info->operator_name);
        vm_log_warn("[GLOBAL]vm_get_current_apn :read nvram plmn = %s",current_apn_info->operator_id);
        vm_log_warn("[GLOBAL]vm_get_current_apn :read nvram apn_proxy  = %s",current_apn_info->apn_proxy);
        vm_log_warn("[GLOBAL]vm_get_current_apn :read nvram apn_no_proxy  = %s",current_apn_info->apn_no_proxy);
        vm_log_warn("[GLOBAL]vm_get_current_apn :read nvram proxyip  = %s",current_apn_info->proxy_ip);
        vm_log_warn("[GLOBAL]vm_get_current_apn :read nvram port  = %d",current_apn_info->proxy_port);
        vm_log_warn("[GLOBAL]vm_get_current_apn :read nvram wapusername  = %s",current_apn_info->wap_user_name);
        vm_log_warn("[GLOBAL]vm_get_current_apn :read nvram wappassword  = %s",current_apn_info->wap_pass_word);        
        vm_log_warn("[GLOBAL]vm_get_current_apn :read nvram netusername  = %s",current_apn_info->net_user_name);
        vm_log_warn("[GLOBAL]vm_get_current_apn :read nvram netpassword  = %s",current_apn_info->net_pass_word); 
        
        if (current_apn_info->apn_info_id > 0 )
        {
            if (vm_apn_cmp_operator_id(current_apn_info->operator_id,cur_plmnstr) == VM_APN_OK)
            {
                memcpy(&vm_current_apn_info,current_apn_info,sizeof(vm_apn_info));
                return VM_APN_USE_NVRAM_RECORD;
            }
        }
        
        memset(current_apn_info , 0, sizeof(vm_apn_info));
    }
   	
#ifndef VRE_USE_NEW_APN_STRUCT    
	if (vm_apn_read_info_from_rom(current_apn_info,cur_plmnstr)< VM_APN_OK)
		return VM_APN_NOT_FOUND_RECORD;
#else
	if (vm_apn_read_info_from_rom_ext(current_apn_info,cur_plmnstr)< VM_APN_OK)
		return VM_APN_NOT_FOUND_RECORD;
#endif 


	vm_log_warn("[GLOBAL]vm_get_current_apn :read info  current_apn_info proxyapn  = %s",current_apn_info->apn_proxy);
	vm_log_warn("[GLOBAL]vm_get_current_apn :read info  current_apn_info noproxyapn = %s",current_apn_info->apn_no_proxy);
	vm_log_warn("[GLOBAL]vm_get_current_apn :read info  current_apn_info operator_id= %s",current_apn_info->operator_id);
    memcpy(&vm_current_apn_info,current_apn_info,sizeof(vm_apn_info));
	return VM_APN_OK;
#else
	return VM_APN_INTERNAL_ERROR;
#endif
}



VMINT vm_get_nvram_apn(vm_apn_info *current_apn_info)
{
#ifdef VRE_GLOBAL_VERSION	

	if (!current_apn_info)
		return VM_APN_INTERNAL_ERROR;

    if (vm_apn_read_setting_from_nvram(current_apn_info) < VM_APN_OK)
        return VM_APN_READ_NVRAM_ERROR;

	return VM_APN_OK;
#else
	return VM_APN_INTERNAL_ERROR;
#endif
}





VMINT vm_set_current_apn(vm_apn_info *user_apn_info)
{
#ifdef VRE_GLOBAL_VERSION
    VMCHAR buf[8] = {0};
    vm_apn_info nvram_apn_info;
	if (!user_apn_info)
		return VM_APN_INTERNAL_ERROR;
    
    if (vm_query_operator_code(buf,VM_APN_PLMN_MAX_LEN) != 0) 
		return VM_APN_NOT_FIND_SIM_CARD;
    
    strncpy(user_apn_info->operator_id,buf,VM_APN_PLMN_MAX_LEN);
    

    if (vm_apn_read_setting_from_nvram(&nvram_apn_info) < VM_APN_OK)
    {
        if (vm_set_user_apn_info(user_apn_info) == FALSE)
            return VM_APN_WRITE_NVRAM_ERROR;

        memcpy(&vm_current_apn_info,user_apn_info,sizeof(vm_apn_info));
        return VM_APN_OK;
    }
        
    user_apn_info->apn_info_id = 1;
    if (vm_apn_cmp_plmn(nvram_apn_info.operator_id,user_apn_info->operator_id) == VM_APN_OK)
    {
      
        if (user_apn_info->proxy_port == 0)
            user_apn_info->proxy_port = nvram_apn_info.proxy_port;
        
        if (strlen(user_apn_info->proxy_ip) == 0)
            strncpy(user_apn_info->proxy_ip,nvram_apn_info.proxy_ip,16);
        
        if (strlen(user_apn_info->apn_proxy) == 0)
            strncpy(user_apn_info->apn_proxy,nvram_apn_info.apn_proxy,32);
        
        if (strlen(user_apn_info->apn_no_proxy) == 0)
            strncpy(user_apn_info->apn_no_proxy,nvram_apn_info.apn_no_proxy,32);
    }
    if (vm_set_user_apn_info(user_apn_info) == FALSE)
        return VM_APN_WRITE_NVRAM_ERROR;

    memcpy(&vm_current_apn_info,user_apn_info,sizeof(vm_apn_info));

    return VM_APN_OK;
#else
	return VM_APN_INTERNAL_ERROR;
#endif
}

VMINT vm_del_nvram_apn(void)
{
#ifdef VRE_GLOBAL_VERSION
    vm_apn_info nvram_apn_info;
    
	memset(&nvram_apn_info , 0, sizeof(vm_apn_info));
    if (vm_set_user_apn_info(&nvram_apn_info) == FALSE)
        return VM_APN_WRITE_NVRAM_ERROR;
    return VM_APN_OK;
#else
	return VM_APN_INTERNAL_ERROR;
#endif
}



VMINT vm_get_apn_info(vm_apn_info_ext *current_apn_info)
{
#ifdef VRE_GLOBAL_VERSION
    vm_apn_info *apn_info;
    if ((apn_info = vm_calloc(sizeof(vm_apn_info))) == NULL)
        return  VM_APN_INTERNAL_ERROR;
    
    vm_get_current_apn(apn_info);
    memcpy(current_apn_info,apn_info,sizeof(vm_apn_info_ext));
    vm_free(apn_info);
    return VM_APN_OK;
#else
	current_apn_info->apn_info_id = 0;
	current_apn_info->proxy_port = 80;
	current_apn_info->operator_id[0] = '\0';
	current_apn_info->operator_name[0]= '\0';
	memcpy(current_apn_info->proxy_ip,"10.0.0.172",16);
	current_apn_info->proxy_ip[10] = '\0';
	current_apn_info->apn_proxy[0] = '\0';
	current_apn_info->apn_no_proxy[0] = '\0';
	current_apn_info->wap_user_name[0] = '\0';
	current_apn_info->wap_pass_word[0] = '\0';
	current_apn_info->net_user_name[0] = '\0';
	current_apn_info->net_pass_word[0] = '\0';    

	return VM_APN_INTERNAL_ERROR;
#endif
}

#if 0
/*******************************************************************************************
 * Download Agent API
 * Provided by Micheal Li
 * Added by Daniel Lin
 * 2010-6-24
 *
void mmi_da_vre_am_download_file(VMINT32 ConnectType, VMUWCHAR *app_name, VMUINT32 app_id,
 VMINT8* ServerURL, VMINT8* URL, VMINT8* res_para, VMINT32 hide, dla_dl_app_cb_t dla_dl_app_cb)
{
	mmi_da_vre_download_file((E_ConnectType_t) ConnectType, (U16 *)app_name, (U32) app_id,
	(S8* )ServerURL,(S8*) URL, (S8*)res_para, (S32) hide, (MMI_DLA_DL_APP_CB_T) dla_dl_app_cb);
}

void mmi_da_vre_am_download_datablock(VMINT32 ConnectType, VMINT8* ServerURL, VMINT8*URL, dla_dl_data_cb_t dla_dl_data_cb)
{
	mmi_da_vre_download_datablock((E_ConnectType_t) ConnectType,  (S8* )ServerURL,(S8*)URL, (MMI_DLA_DL_DATA_CB_T) dla_dl_data_cb);
}
/*
 *******************************************************************************************/
#endif 
/*************************************************************************
 * 
 * AM与VRE内存分离的新接口。
 * 
 ************************************************************************/
VMINT vm_vam_load_resource(VMSHORT * filename, VMCHAR* res_name, 
	VMCHAR* res, VMUINT* res_size)
{
	extern VMINT vm_load_resource_from_file_provided_mem(VMSHORT * filename, VMCHAR* res_name, 
		VMCHAR* res, VMUINT* res_size);

	return vm_load_resource_from_file_provided_mem(filename, res_name, res, res_size);
}

VMINT vm_vam_get_tag(VMSHORT* filename, VMINT tag_id, void* buf , VMINT* buf_size)
{
	if (vm_get_vm_tag(filename , tag_id, buf, buf_size) == GET_TAG_TRUE)
	{
		return 0;
	}

	return -1;
}

VMINT vm_vam_get_tag_by_lang_id(VMSHORT* filename, VMINT tag_id, void* buf , VMINT* buf_size, VMINT lang_id)
{
	if (vm_get_tag_by_lang_id(filename, tag_id, buf, buf_size, lang_id) == GET_TAG_TRUE)
	{
		return 0;
	}

	return -1;
}

#endif

