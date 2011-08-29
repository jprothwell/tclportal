#ifdef __VRE__
#include "vmsys.h"
#include "vmmm.h"
#include "vmlog.h"
#include "vmopt.h"
#include "vmio.h"
#include "vmchset.h"
#include "vmmod.h"
#include "vmopt.h"
#include "vmstdlib.h"
#include "vmdl.h"
#include "vmfilere.h"
#include "vmsalmm.h"
#include "vmpromng.h"
#include "vmresmng.h"

#define INIT_VALUE		(-1)
#define REG_AUDIO_MODULE_FAILED  (-2)
#define REPEAT_MAX 		(255)
#define MILLISECONDS	(1000)


/**************************************************************************/
/*                                                                        */
/* 全部全局变量引用。                                                        */
/*                                                                        */
/**************************************************************************/
#ifdef VRE_SUPPORT_SECURITY_FEATURE
extern VMINT _vm_remap_usr_disk(VMWSTR dest_filename, VMWSTR source_filename);
extern VMINT _vm_get_disk_permission(void);
#endif

/**************************************************************************/
/*                                                                        */
/* 模块变量声明。                                                         */
/*                                                                        */
/**************************************************************************/

static VMINT audio_res_handle = INIT_VALUE; 		/* audio 的资源句柄 */
static VMINT record_res_handle = INIT_VALUE;		/* record 的资源句柄 */
static VMINT audio_is_pause = FALSE;				/* audio 是否处于暂停*/

/**************************************************************************/
/*                                                                        */
/* 模块函数声明。                                                         */
/*                                                                        */
/**************************************************************************/
/* 
 * 音频播放之前的预处理。返回TRUE 表示已经处理，当前音频可用。返回FALSE 表示不可抢占当前使用音频。
 */
VMINT vm_audio_preprocess_play(void);

/* 
 * MIDI 播放之前的预处理。返回TRUE 表示已经处理，当前音频可用。返回FALSE 表示不可抢占当前使用音频。
 */
VMINT vm_midi_preprocess_play(void);

/* 
 * 录音之前的预处理。
 */
VMINT vm_record_preprocess(void);

/* 
 * 音频播放的用户回调函数指针。
 */
static void (*audio_callback)(VMINT result) = NULL;

/* 
 * AUDIO 的SAL层播放回调函数。
 */
static void vm_audio_callback(VMINT result);

/*
 * MIDI 的SAL 层播放回调函数。
 */
static void vm_midi_callback(VMINT handle, VMINT result);

/* ================= 多进程相关 ====================== */

/**
 * 获得当前占用音频资源的类型。
 *
 * @param used_handle		如果被占用，返回占用进程句柄。
 *
 * @return				返回NULL 表示未被占用，否则为vm_res_type_enum 中的枚举类型。
 */
VMINT vm_audio_get_used_res_type(VM_P_HANDLE *used_handle);

/**
 * 停止当前占用音频资源播放器。
 *
 * @return				返回TRUE 表示成功，FALSE 为失败。
 */
 VMINT vm_audio_stop_used_res_type(vm_res_type_enum res_type);

/**
 * 挂起auido 的背景播放。
 */
void vm_audio_suspend_background_play(void);

/**
 * 恢复被挂起的auido 的背景播放。
 */
void vm_audio_resume_background_play(void);


/**************************************************************************/
/*                                                                        								   */
/* 各个音频 状态的管理函数                                                         	   */
/*                                                                        								   */
/**************************************************************************/

/**
  *	audio 注册给资源管理器的状态处理函数。
  */
void vm_audio_notify_callback(VM_P_HANDLE process_handle, VMINT sys_state)
{
	int count;
	vm_log_debug(  "entry vm_audio_notify_callback, process_handle = %d, sys_state = %d", process_handle, sys_state);
	switch(sys_state)
	{
	case VM_PMNG_FOREGROUND:
	case VM_PMNG_BACKGROUND:
		break;
	case VM_PMNG_UNLOAD:
		if ((count = vm_res_get_data_list_count_by_type(VM_RES_TYPE_AUDIO_HANDLE)) > 0)
		{
			vm_res_node_t data;
			vm_res_get_data_list_by_type(VM_RES_TYPE_AUDIO_HANDLE, &data, 1);
			if (process_handle == data.phandle)
				vm_audio_stop(NULL);
		}
		reset_default_volume();
		break;
	}
}

/**
  *	midi 注册给资源管理器的状态处理函数。
  */
void vm_midi_notify_callback(VM_P_HANDLE process_handle, VMINT sys_state)
{
	vm_log_debug(  "entry vm_midi_notify_callback, process_handle = %d, sys_state = %d", process_handle, sys_state);
	switch(sys_state)
	{
	case VM_PMNG_FOREGROUND:
		break;
	case VM_PMNG_BACKGROUND:
	case VM_PMNG_UNLOAD:
		vm_midi_stop_all();
		break;
	}	
}

/**
  *	record 注册给资源管理器的状态处理函数。
  */
void vm_record_notify_callback(VM_P_HANDLE process_handle, VMINT sys_state)
{
	vm_log_debug(  "entry vm_record_notify_callback, process_handle = %d, sys_state = %d", process_handle, sys_state);
	switch(sys_state)
	{
	case VM_PMNG_FOREGROUND:
		break;
	case VM_PMNG_BACKGROUND:
	case VM_PMNG_UNLOAD:
		vm_record_stop(); 
		break;
	}
}

/**
  *	初始化VRE的音频模块。
  */
VMINT vm_init_audio_module(void)
{
	vm_log_debug(  "entry vm_init_audio_module.");
	audio_callback =  NULL;
	record_res_handle = INIT_VALUE;
	vm_res_type_set_notify_callback(VM_RES_TYPE_AUDIO_HANDLE, vm_audio_notify_callback);
	vm_res_type_set_notify_callback(VM_RES_TYPE_MIDI_HANDLE, vm_midi_notify_callback);
	vm_res_type_set_notify_callback(VM_RES_TYPE_RECORD_HANDLE, vm_record_notify_callback);
	return REG_VRE_MODULE_SUCCESS;
}

extern void vm_sal_vibrator_off(void);
/**
  *	终止VRE的音频模块。
  */
VMINT vm_finialize_audio_module(void)
{	
	vm_log_debug(  "entry vm_finialize_audio_module.");
	vm_sal_vibrator_off();
	vm_res_type_set_notify_callback(VM_RES_TYPE_AUDIO_HANDLE, NULL);
	vm_res_type_set_notify_callback(VM_RES_TYPE_MIDI_HANDLE, NULL);
	vm_res_type_set_notify_callback(VM_RES_TYPE_RECORD_HANDLE, NULL);	
	return REG_VRE_MODULE_SUCCESS;
}


/**
  *	VRE的音频模块时间处理。
  */
static VMINT vm_audio_mod_evt_proc(VRE_MOD_LIFECIRCLE_EVT event)
{
	vm_log_debug(  "entry vm_audio_mod_evt_proc, and event = %d", event);
	switch(event)
	{
	case EVT_MOD_INIT:
		vm_log_debug("entry vm_audio_mod_evt_proc, and event = EVT_MOD_INIT.");
		vm_init_audio_module();
		break;
	case EVT_MOD_INACTIVE:
		vm_sal_vibrator_off();
	case EVT_MOD_ACTIVE:		
		break;
	case EVT_MOD_RELEASE:
		vm_log_debug("entry vm_audio_mod_evt_proc, and event = EVT_MOD_RELEASE.");
		vm_finialize_audio_module();
		break;
	default:
		vm_log_debug(  "{AUDIO MODULE}Receive unkown [%d] event.", event);
		return REG_AUDIO_MODULE_FAILED;
	}
	
	return REG_VRE_MODULE_SUCCESS;
}

/**
  *	初始化时注册VRE的音频模块。
  */
VMINT _vm_reg_audio_module(void)
{
	int res = REG_VRE_MODULE_SUCCESS;
	
	if ((res = _vm_reg_module("AUDIO MODULE", (MOD_EVT_PROCESS)vm_audio_mod_evt_proc)) != REG_VRE_MODULE_SUCCESS)
	{
		vm_log_debug(  "_vm_reg_audio_module : Failed to regisiter audio module. Error Code : %d", res);
	}

	return res;
}


/**************************************************************************/
/*                                                                        								   */
/* Audio 接口                                                         	   						   */
/*                                                                        								   */
/**************************************************************************/
static void vm_release_audio_resource(void)
{
	vm_res_release_data(VM_RES_TYPE_AUDIO_HANDLE, audio_res_handle);
	audio_res_handle = INIT_VALUE;
}

VMINT vm_audio_play_file(VMWSTR filename, void (*f)(VMINT result)) 
{
	int result = VM_AUDIO_FAILED;	

	vm_log_debug( "entry vm_audio_play_file, and f = %d", f);

	if (vm_audio_preprocess_play() == FALSE)
		return result;

	audio_res_handle = vm_res_save_data(VM_RES_TYPE_AUDIO_HANDLE, NULL, 0, (void*)f, vm_pmng_get_current_handle());
	if (audio_res_handle > INIT_VALUE)
	{
		audio_callback = f;
		
		if (vm_sal_audio_play_file(filename, vm_audio_callback) == VM_AUDIO_SUCCEED)
		{
			result = VM_AUDIO_SUCCEED;
		}
		else
		{
			vm_release_audio_resource();
		}
	}
	vm_log_debug( "exit vm_audio_play_file, and result = %d", result);

	return result;
}

VMINT vm_audio_play_file_ex(VMWSTR filename, VMUINT start_time, VMUINT path, void (*f)(VMINT result))
{
	int duration = 0;
	int result = VM_AUDIO_FAILED;	

	vm_log_debug( "entry vm_audio_play_file_ex, start_time = %d, and f = %d", start_time, f);
	duration = vm_sal_audio_duration(filename);

	if (start_time >= duration || vm_audio_preprocess_play() == FALSE)
	{
		vm_log_debug("vm_audio_play_file_ex preprocess failed.");
		return result;
	}
	
	audio_res_handle = vm_res_save_data(VM_RES_TYPE_AUDIO_HANDLE, NULL, 0, (void*)f, vm_pmng_get_current_handle());
	vm_log_debug("vm_audio_play_file_ex, and audio_res_handle = %d", audio_res_handle);
	if (audio_res_handle > INIT_VALUE)
	{
		audio_callback = f;
		if (vm_sal_audio_play_file_ex(filename, start_time, path, vm_audio_callback) == VM_AUDIO_SUCCEED)
			result = VM_AUDIO_SUCCEED;
		else
		{
			vm_log_debug("vm_sal_audio_play_file_ex, play failed.");
			vm_release_audio_resource();
		}
	}
	vm_log_debug( "exit vm_audio_play_file_ex, and result = %d", result);

	return result;
}

VMINT vm_audio_play_bytes(void *audio_data, VMUINT len, VMUINT8 format, VMUINT start_time, VMUINT path, void (*f)(VMINT result))
{
	int duration = 0;
	int result = VM_AUDIO_FAILED;	

	if (!(format == VM_FORMAT_MP3 || format == VM_FORMAT_AAC))
	{
		vm_log_debug("entry vm_audio_play_bytes, but format not VM_FORMAT_MP3 or VM_FORMAT_AAC.");
		return result;
	}
	
	duration = vm_sal_audio_bytes_duration(audio_data, len, format);
	vm_log_debug("start_time = %d, duration = %d", start_time, duration);

	if (audio_data == NULL || len == 0 || start_time >= duration || vm_audio_preprocess_play() == FALSE)
	{
		vm_log_debug("vm_audio_play_bytes preprocess failed.");
		return result;
	}
	
	audio_res_handle = vm_res_save_data(VM_RES_TYPE_AUDIO_HANDLE, NULL, 0, (void*)f, vm_pmng_get_current_handle());
	if (audio_res_handle > INIT_VALUE)
	{
		audio_callback = f;
		if (vm_sal_audio_play_bytes(audio_data, len, format, start_time, path, vm_audio_callback) == VM_AUDIO_SUCCEED)
			result = VM_AUDIO_SUCCEED;
		else
		{
			vm_release_audio_resource();
		}
	}
	vm_log_debug( "exit vm_audio_play_bytes, and result = %d", result);

	return result;	
}

VMINT vm_audio_pause(void (*f)(VMINT result)) 
{
	int result = VM_AUDIO_FAILED;	

	if ((vm_res_get_data_list_count_by_type(VM_RES_TYPE_AUDIO_HANDLE) > 0) && audio_is_pause == FALSE)
	{
		audio_callback =f;
		result = vm_sal_audio_pause(vm_audio_callback);
		if (result == VM_AUDIO_SUCCEED)
			audio_is_pause = TRUE;
	}
	return result;
}

VMINT vm_audio_resume(void (*f)(VMINT result)) 
{
	int result = VM_AUDIO_FAILED;	

	if ((vm_res_get_data_list_count_by_type(VM_RES_TYPE_AUDIO_HANDLE) > 0) &&  audio_is_pause == TRUE)
	{
		audio_callback =f;
		result = vm_sal_audio_resume(vm_audio_callback);
		if (result == VM_AUDIO_SUCCEED)
			audio_is_pause = FALSE;		
	}
	return result;
}

VMINT vm_audio_stop(void (*f)(VMINT result)) 
{
	int audio_count = 0;
	int result = VM_AUDIO_FAILED;	

	vm_log_debug( "entry vm_audio_stop.");
	audio_count = vm_res_get_data_list_count_by_type(VM_RES_TYPE_AUDIO_HANDLE);
	vm_log_debug( "vm_res_get_data_list_count_by_type = %d", audio_count);
	if (audio_count > 0)
	{
		vm_log_debug( "vm_res_get_data_list_count_by_type > 0.");
		audio_callback =f;
		result = vm_sal_audio_stop(vm_audio_callback);
		if (result == VM_AUDIO_SUCCEED)
		{
			vm_log_debug( "vm_audio_stop SUCCEED, will vm_res_release_data = %d", audio_res_handle);
			audio_is_pause = FALSE;
		}
		
		vm_release_audio_resource();
	}
	vm_log_debug( "exit vm_audio_stop.");
	return result;
}

VMINT vm_audio_duration(VMWSTR filename) 
{
	int result = VM_AUDIO_FAILED;	

	/* 本函数可以在任何时候使用 */
	vm_log_debug( "vm_res_get_data_list_count_by_type > 0, and will vm_sal_audio_duration");
	result = vm_sal_audio_duration(filename) / MILLISECONDS;

	return result;
}

VMINT vm_audio_bytes_duration(void *audio_data, VMUINT len, VMUINT8 format)
{
	int result = VM_AUDIO_FAILED;	

	if (audio_data == NULL || len == 0)
	{
		vm_log_debug("audio_data or len = 0.");
		return result;
	}

	switch(format)
	{
		case VM_FORMAT_MP3:
		case VM_FORMAT_AAC:
		case VM_FORMAT_MIDI:
		case VM_FORMAT_AMR:
			/* 本函数可以在任何时候使用 */
			result = vm_sal_audio_bytes_duration(audio_data, len, format) / MILLISECONDS;
		break;
	}
	return result;
}

VMINT vm_audio_get_time(void)
{
	int result = VM_AUDIO_FAILED;	

	if (vm_res_get_data_list_count_by_type(VM_RES_TYPE_AUDIO_HANDLE) > 0)
	{
		result = vm_sal_audio_get_time();
	}

	return result;
}

void vm_audio_callback(VMINT result) 
{
	int count;
	VM_P_HANDLE use_audio_handle;
	vm_log_debug(  "vm_audio_callback 1 : result=%d", result);

	if (NULL == audio_callback)
	{
		vm_log_debug(  "vm_audio_callback == NULL, vm_audio_callback failed");
		return ;
	}	

	if ((count = vm_res_get_data_list_count_by_type(VM_RES_TYPE_AUDIO_HANDLE)) > 0)
	{
		vm_res_node_t data;
		vm_res_get_data_list_by_type(VM_RES_TYPE_AUDIO_HANDLE, &data, 1);
		use_audio_handle = data.phandle;
		vm_log_debug( "vm_res_get_data_list_count_by_type, and use_audio_handle = %d.", use_audio_handle);
	}
	else
	{
		vm_log_debug( "vm_res_get_data_list_count_by_type error, return.");
		return;
	}

	if (vm_pmng_set_ctx(use_audio_handle) == VM_PMNG_OP_OK)
	{
		vm_log_debug("audio_callback = %d", audio_callback);
		vm_log_debug(  "vm_audio_callback 2 : result=%d", result);
		switch (result) {
		case VM_AUDIO_RESULT_RESUME:
			audio_callback(VM_AUDIO_RESULT_RESUME);
			break;
		case VM_AUDIO_RESULT_PAUSE:
			audio_callback(VM_AUDIO_RESULT_PAUSE);
			break;
		case VM_AUDIO_RESULT_END_OF_FILE:
			if (vm_res_get_data_list_count_by_type(VM_RES_TYPE_AUDIO_HANDLE) > 0)
			{
				vm_release_audio_resource();
			}
			vm_log_debug( "audio callback = VM_AUDIO_RESULT_END_OF_FILE.");
			audio_callback(VM_AUDIO_RESULT_END_OF_FILE);
			break;
		case VM_AUDIO_RESULT_DEMO_END:
			vm_log_debug( "audio callback = VM_AUDIO_RESULT_DEMO_END.");			
			audio_callback(VM_AUDIO_RESULT_DEMO_END);
			break;
		case VM_AUDIO_RESULT_STOP:	
			vm_log_debug( "audio callback = VM_AUDIO_RESULT_STOP.");
			audio_callback(VM_AUDIO_RESULT_STOP);
			break;
		case VM_AUDIO_RESULT_INTERRUPT:
			vm_log_debug("audio callback = VM_AUDIO_RESULT_INTERRUPT.");
			audio_callback(VM_AUDIO_RESULT_INTERRUPT);
			break;
		case VM_AUDIO_RESULT_INTERRUPT_RESUME:
			if (vm_res_get_data_list_count_by_type(VM_RES_TYPE_AUDIO_HANDLE) > 0)
			{
				vm_release_audio_resource();
			}
			vm_log_debug("audio callback = VM_AUDIO_RESULT_INTERRUPT_RESUME.");
			audio_callback(VM_AUDIO_RESULT_INTERRUPT_RESUME);
			break;
		default:
			vm_log_debug( "audio callback, result = %d", result);
			audio_callback(VM_AUDIO_RESULT_STOP);					
			break;
		}
		
		vm_pmng_reset_ctx();
	}
}


/**************************************************************************/
/*                                                                        								   */
/* MIDI 接口                                                         	   						   */
/*                                                                        								   */
/**************************************************************************/
static void vm_release_midi_resource(VMINT *res_handle)
{
	vm_log_debug("entry vm_release_midi_resource, *res_handle = %d", *res_handle);
	vm_res_release_data(VM_RES_TYPE_MIDI_HANDLE, *res_handle);
	*res_handle = VM_MIDI_FAILED;
}

VMINT vm_midi_play(VMINT resid, VMINT repeat, void (*f)(VMINT handle, VMINT event)) 
{
	int res_handle = VM_MIDI_FAILED;
	int res = VM_MIDI_FAILED;

	if (repeat < 0 || repeat > REPEAT_MAX ||vm_midi_preprocess_play() == FALSE)
		return res;

	if ((res_handle = vm_res_save_data(VM_RES_TYPE_MIDI_HANDLE, NULL, 0, (void*)f, vm_pmng_get_current_handle())) >= 0)
	{
		//wei.xia add by 0507
		vm_audio_suspend_background_play();
		//add end
		res = vm_sal_midi_play(resid, repeat, vm_midi_callback);
		if (res == VM_MIDI_FAILED)
		{
			//wei.xia add by 0507
			vm_audio_resume_background_play();
			//add end
			vm_release_midi_resource(&res_handle);
		}
		else
		{
			//wei.xia delete by 0507
			//vm_audio_suspend_background_play();
			//delete end
			vm_res_set_mtk_reshandle(VM_RES_TYPE_MIDI_HANDLE, res_handle, res);
		}
	}
	
	return res_handle;
}

VMINT vm_midi_play_ex(VMINT resid, VMUINT start_time, VMINT repeat, VMUINT path, void (*f)(VMINT handle, VMINT event))
{
	int res_handle = VM_MIDI_FAILED;
	int res = VM_MIDI_FAILED;

	if (repeat < 0 || repeat > REPEAT_MAX ||vm_midi_preprocess_play() == FALSE)
		return res;

	if ((res_handle = vm_res_save_data(VM_RES_TYPE_MIDI_HANDLE, NULL, 0, (void*)f, vm_pmng_get_current_handle())) >= 0)
	{
		//wei.xia add by 0507
		vm_audio_suspend_background_play();
		//add end
		res = vm_sal_midi_play_ex(resid, start_time, repeat, path, vm_midi_callback);
		if (res == VM_MIDI_FAILED)
		{
			//wei.xia add by 0507
			vm_audio_resume_background_play();
			//add end
			vm_release_midi_resource(&res_handle);
		}
		else
		{
			//wei.xia delete by 0507
			//vm_audio_suspend_background_play();
			//delete end
			vm_res_set_mtk_reshandle(VM_RES_TYPE_MIDI_HANDLE, res_handle, res);
		}
	}

	return res_handle;
}


VMINT vm_midi_play_by_bytes( VMUINT8 * midibuf, VMINT len, VMINT repeat, void (*f)(VMINT handle, VMINT event) )
{
	int res_handle = VM_MIDI_FAILED;
	int res = VM_MIDI_FAILED;
	VM_P_HANDLE process_handle = vm_pmng_get_current_handle();
	
	vm_log_debug("entry vm_midi_play_by_bytes, and midibuf = %d, len = %d, repeat = %d, f = %d", midibuf, len, repeat, f);
	
	
	if (midibuf == NULL || len <= 0 || repeat < 0 || repeat > REPEAT_MAX ||vm_midi_preprocess_play() == FALSE)
	{
		//vm_log_debug("midibuf == NULL || len < 0 || repeat < 0 || repeat > REPEAT_MAX ||vm_midi_preprocess_play() == FALSE");
		return res;
	}
	
	if ((res_handle = vm_res_save_data(VM_RES_TYPE_MIDI_HANDLE, NULL, 0, (void*)f, process_handle))>= 0)
	{
		vm_log_debug("vm_res_save_data success, res_handle = %d", res_handle);
		//wei.xia add by 0507
		vm_audio_suspend_background_play();
		//add end
		res = vm_sal_midi_play_by_bytes(midibuf, len, repeat, vm_midi_callback);
		vm_log_debug("vm_midi_play_by_bytes = %d", res);
		if (res == VM_MIDI_FAILED)
		{
			//wei.xia add by 0507
			vm_audio_resume_background_play();
			//add end
			vm_release_midi_resource(&res_handle);
		}
		else
		{
			//wei.xia delete by 0507
			//vm_audio_suspend_background_play();
			//delete end
			vm_res_set_mtk_reshandle(VM_RES_TYPE_MIDI_HANDLE, res_handle, res);
			vm_log_debug("res = %d, (void*)f = %d", res, f);
		}
	}

	vm_log_debug("exit vm_midi_play_by_bytes, and result = %d", res_handle);
	return res_handle;
}

VMINT vm_midi_play_by_bytes_ex( VMUINT8 * midibuf, VMINT len, VMUINT start_time, VMINT repeat, VMUINT path, void (*f)(VMINT handle, VMINT event) )
{
	int res_handle = VM_MIDI_FAILED;
	int res = VM_MIDI_FAILED;
	
	vm_log_debug(  "entry vm_midi_play_by_bytes ");
	
	if (midibuf == NULL || len <= 0 || repeat < 0 || repeat > REPEAT_MAX ||vm_midi_preprocess_play() == FALSE)
		return res;
	
	if ((res_handle = vm_res_save_data(VM_RES_TYPE_MIDI_HANDLE, NULL, 0, (void*)f, vm_pmng_get_current_handle())) >= 0)
	{
		//wei.xia add by 0507
		vm_audio_suspend_background_play();
		//add end
		res = vm_sal_midi_play_by_bytes_ex(midibuf, len, start_time, repeat, path, vm_midi_callback);
		if (res == VM_MIDI_FAILED)
		{
			//wei.xia add by 0507
			vm_audio_resume_background_play();
			//add end
			vm_release_midi_resource(&res_handle);
		}
		else
		{
			//wei.xia delete by 0507
			//vm_audio_suspend_background_play();
			//delete end
			vm_res_set_mtk_reshandle(VM_RES_TYPE_MIDI_HANDLE, res_handle, res);
		}
	}

	return res_handle;

}

VMINT vm_midi_pause(VMINT handle)
{
	VMINT res, result = VM_MIDI_FAILED;

	VM_P_HANDLE res_handle = VM_MIDI_FAILED;		/* 拥有handle 的进程 */	
	VM_P_HANDLE pmng_handle = VM_MIDI_FAILED;		/* 当前进程 */	
	vm_log_debug(  "entry vm_midi_pause, and handle = %d", handle);

	res_handle = vm_res_get_process_handle(VM_RES_TYPE_MIDI_HANDLE, handle);
	pmng_handle = vm_pmng_get_current_handle();
	vm_log_debug(  "res_handle = %d, pmng_handle = %d", res_handle, pmng_handle);
	if (handle >= 0 && res_handle == pmng_handle)
	{
		if (vm_res_get_mtk_reshandle(VM_RES_TYPE_MIDI_HANDLE, handle, &res) == VM_RES_OK)
		{
			result = vm_sal_midi_pause(res);
		}
	}
	return result;
}

VMINT vm_midi_resume(VMINT handle)
{
	VMINT res, result = VM_MIDI_FAILED;

	VM_P_HANDLE res_handle = VM_MIDI_FAILED;		/* 拥有handle 的进程 */	
	VM_P_HANDLE pmng_handle = VM_MIDI_FAILED;		/* 当前进程 */	
	vm_log_debug(  "entry vm_midi_resume, and handle = %d", handle);

	res_handle = vm_res_get_process_handle(VM_RES_TYPE_MIDI_HANDLE, handle);
	pmng_handle = vm_pmng_get_current_handle();
	vm_log_debug(  "res_handle = %d, pmng_handle = %d", res_handle, pmng_handle);
	if (handle >= 0 && res_handle == pmng_handle)
	{
		if (vm_res_get_mtk_reshandle(VM_RES_TYPE_MIDI_HANDLE, handle, &res) == VM_RES_OK)
		{
			result = vm_sal_midi_resume(res);
		}
	}
	return result;	
}

VMINT vm_midi_get_time(VMINT handle, VMUINT *current_time)
{

	VMINT res, result = VM_MIDI_FAILED;
	VM_P_HANDLE res_handle = VM_MIDI_FAILED;		/* 拥有handle 的进程 */	
	VM_P_HANDLE pmng_handle = VM_MIDI_FAILED;		/* 当前进程 */	
	vm_log_debug(  "entry vm_midi_get_time, and handle = %d", handle);

	res_handle = vm_res_get_process_handle(VM_RES_TYPE_MIDI_HANDLE, handle);
	pmng_handle = vm_pmng_get_current_handle();
	vm_log_debug(  "res_handle = %d, pmng_handle = %d", res_handle, pmng_handle);
	if (handle >= 0 && res_handle == pmng_handle)
	{
		if (vm_res_get_mtk_reshandle(VM_RES_TYPE_MIDI_HANDLE, handle, &res) == VM_RES_OK)
		{
			//将当前时间置为零
			*current_time = 0;
			result = vm_sal_midi_get_time(res, current_time);
		}
	}
	return result;	
	
}

void vm_midi_stop(VMINT handle) 
{
	int res;
	VM_P_HANDLE res_handle = VM_MIDI_FAILED;		/* 拥有handle 的进程 */	
	VM_P_HANDLE pmng_handle = VM_MIDI_FAILED;		/* 当前进程 */	
	vm_log_debug(  "entry vm_midi_stop, and handle = %d", handle);

	res_handle = vm_res_get_process_handle(VM_RES_TYPE_MIDI_HANDLE, handle);
	pmng_handle = vm_pmng_get_current_handle();
	vm_log_debug(  "res_handle = %d, pmng_handle = %d", res_handle, pmng_handle);
	if (handle >= 0 && res_handle == pmng_handle)
	{
		vm_log_debug( "entry vm_midi_stop2.");
		if (vm_res_get_mtk_reshandle(VM_RES_TYPE_MIDI_HANDLE, handle, &res) == VM_RES_OK)
		{
			vm_log_debug( "res = %d", res);
			vm_sal_midi_stop(res);
			vm_res_release_data(VM_RES_TYPE_MIDI_HANDLE, handle);
		}
	}
	vm_audio_resume_background_play();
	vm_log_debug( "exit vm_midi_stop.");
}

void vm_midi_stop_all(void)
{
	VMINT res_handle = VM_RES_NOT_FIND, res = 0;
	vm_log_debug("entry vm_midi_stop_all.");
	
	/* 使用-1,说明检索该类所有资源 */
	while ((res_handle = vm_res_findfirst(-1, VM_RES_TYPE_MIDI_HANDLE)) != VM_RES_NOT_FIND)
	{
		if (vm_res_get_mtk_reshandle(VM_RES_TYPE_MIDI_HANDLE, res_handle, &res) == 0)
		{
			int r;
			vm_log_debug("stop midi, handle = %d", res);
			vm_sal_midi_stop(res);
			r = vm_res_release_data(VM_RES_TYPE_MIDI_HANDLE, res_handle);
			vm_log_debug("vm_res_release_data(%d) = %d", res_handle, r);
		}
		vm_res_findclose(VM_RES_TYPE_MIDI_HANDLE);
	}
	
	vm_audio_resume_background_play();
}


void vm_midi_callback(VMINT handle, VMINT result) 
{
	VMINT res_handle = VM_RES_NOT_FIND, res = 0;
	void (*midi_callback)(VMINT handle, VMINT result) = NULL;
	VM_P_HANDLE use_midi_handle = 0;

	vm_log_debug( "entry vm_midi_callback, handle = %d, result = %d", handle, result);

	if (result == VM_AUDIO_RESULT_INTERRUPT)
	{
		vm_log_debug("result = VM_AUDIO_RESULT_INTERRUPT, stop all and exit.");
		vm_midi_stop_all();		
		return; 
	}
	
	if ((res_handle = vm_res_findfirst(-1, VM_RES_TYPE_MIDI_HANDLE)) != VM_RES_NOT_FIND)
	{
		if ((vm_res_get_mtk_reshandle(VM_RES_TYPE_MIDI_HANDLE, res_handle, &res))== VM_RES_OK)
		{
			if (res == handle)
			{
				int i;
				vm_res_get_callback(VM_RES_TYPE_MIDI_HANDLE, res_handle, (void**)&midi_callback);
				use_midi_handle = vm_res_get_process_handle(VM_RES_TYPE_MIDI_HANDLE, res_handle);
				vm_log_debug( "vm_res_get_callback, midi_callback = %d, use_midi_handle = %d", midi_callback, use_midi_handle);
				// midi 音乐只有在音乐播放完成的情况下才有回调，所以收到回调即可删除 
				i = vm_res_release_data(VM_RES_TYPE_MIDI_HANDLE, res_handle);
				vm_log_debug("vm_res_release_data = %d", i);
			}
		}
		
		while ((res_handle = vm_res_findnext(-1, VM_RES_TYPE_MIDI_HANDLE)) != VM_RES_NOT_FIND)
		{		
			vm_res_get_mtk_reshandle(VM_RES_TYPE_MIDI_HANDLE, res_handle, &res);
			if (res == handle)
			{
				int i;
				vm_res_get_callback(VM_RES_TYPE_MIDI_HANDLE, res_handle, (void**)&midi_callback);
				use_midi_handle = vm_res_get_process_handle(VM_RES_TYPE_MIDI_HANDLE, res_handle);
				vm_log_debug( "vm_res_get_callback, midi_callback = %d, use_midi_handle = %d", midi_callback, use_midi_handle);
				// midi 音乐只有在音乐播放完成的情况下才有回调，所以收到回调即可删除 
				i = vm_res_release_data(VM_RES_TYPE_MIDI_HANDLE, res_handle);
				vm_log_debug("vm_res_release_data = %d", i);
				break;
			}
		}
		vm_res_findclose(VM_RES_TYPE_MIDI_HANDLE);
	}	

	vm_log_debug( "midi_callback = %d.", midi_callback);
	if (midi_callback == NULL)
		return;

	if (midi_callback) 
	{
		vm_log_debug(  "vm_midi_callback: handle=%d, result=%d, midi_callback = %d.", handle, result, midi_callback);

		if (vm_pmng_set_ctx(use_midi_handle) == VM_PMNG_OP_OK)
		{

			switch (result) 
			{
				case VM_AUDIO_RESULT_END_OF_FILE:
					vm_log_debug("callback  VM_AUDIO_RESULT_END_OF_FILE to app.");
					midi_callback((VMINT)handle, VM_AUDIO_RESULT_END_OF_FILE);
					vm_audio_resume_background_play();
					break;
				/*case MDI_AUDIO_DISC_FULL:
					midi_callback((VMINT)handle, VM_AUDIO_RESULT_END_OF_FILE);
					break;*/
				default:
					midi_callback((VMINT)handle, VM_FORMAT_OTHER);
					break;
			}

			vm_log_debug(  "switch over");
			vm_pmng_reset_ctx();
		}
	}
	vm_log_debug(  "vm_midi_callback over");
}

void vm_audio_suspend_background_play(void)
{
	/* 挂起 背景播放*/
	int midi_count = 0;
	VM_P_HANDLE current_handle = vm_pmng_get_current_handle();
	
	midi_count = vm_res_get_data_list_count_by_proecss(current_handle, VM_RES_TYPE_MIDI_HANDLE);
	if (midi_count == 1)
		vm_sal_audio_suspend_background_play();
}

void vm_audio_resume_background_play(void)
{
	/* 恢复被挂起 背景播放*/
	int midi_count = 0;
	VM_P_HANDLE current_handle = vm_pmng_get_current_handle();
	
	midi_count = vm_res_get_data_list_count_by_proecss(current_handle, VM_RES_TYPE_MIDI_HANDLE);
	if (midi_count == 0)
		vm_sal_audio_resume_background_play();
}

/**************************************************************************/
/*                                                                        								   */
/* 其它 接口(other)                                                         	   						   */
/*                                                                        								   */
/**************************************************************************/
void vm_set_volume(VMINT volume) 
{	
	//wei.xia add by 0624
	//当前占用音频的资源类型
	VMINT audio_type;		
	//使用audio 的进程句柄
	VM_P_HANDLE use_audio_handle = INIT_VALUE;
	//得到当前占用音频资源的类型
	
	audio_type = vm_audio_get_used_res_type(&use_audio_handle);
	if (audio_type > 0)
	{
		vm_log_debug("vm_set_volume = %d", volume);
		vm_sal_set_volume(volume);
	}
	else
	{
		vm_sal_set_current_volume(volume);
	}
	//add end
}

void vm_vibrator_once(void)
{
	vm_sal_vibrator_once();
}

void vm_set_key_tone_on(void)
{
	if (vm_pmng_is_fg(vm_pmng_get_current_handle()))
		vm_sal_set_key_tone_on();
}

void vm_set_key_tone_off(void)
{
	if (vm_pmng_is_fg(vm_pmng_get_current_handle()))
		vm_sal_set_key_tone_off();
}

vm_kbd_tone_state_enum vm_get_key_tone_state(void)
{
	return vm_sal_get_key_tone_state();
}

VMINT vm_set_key_tone_state(vm_kbd_tone_state_enum key_tone_state)
{
	VMINT result = FALSE;
	
	if (vm_pmng_is_fg(vm_pmng_get_current_handle()))
		result = vm_sal_set_key_tone_state(key_tone_state);

	return result;
}

VMINT vm_set_ringtone(VMWSTR filepath) 
{
	VMINT result = VM_KURO_FAILED;
	
	result = vm_sal_set_ringtone(filepath);

	return result;
}


/**************************************************************************/
/*                                                                        								   */
/* 录音 接口                                                         	   				          */
/*                                                                        								   */
/**************************************************************************/
#define VM_FILE_EXT_AMR (L".amr")
#define VM_FILE_EXT_WAV (L".wav")

typedef enum
{
   VM_RECORD_STATE_IDLE,
   VM_RECORD_STATE_RECORD,
   VM_RECORD_STATE_RECORD_PAUSED,
   VM_RECORD_NO_OF_STATE
} vm_recorder_state_enum;

static void vm_release_recode_resource(void)
{
	vm_res_release_data(VM_RES_TYPE_RECORD_HANDLE, record_res_handle);
	record_res_handle = INIT_VALUE;
}

void vm_record_event_response(VMINT result)
{
	vm_recorder_callback vm_record_cb;
	VM_P_HANDLE res_handle;

	vm_log_debug(  "vm_record_start_response :  get event=%d", result);

	/* 获取资源对应的进程句柄 */
	res_handle = vm_res_get_process_handle(VM_RES_TYPE_RECORD_HANDLE, record_res_handle);
	/* 获取资源的callback */
	vm_res_get_callback(VM_RES_TYPE_RECORD_HANDLE, record_res_handle, (void**)&vm_record_cb);
	vm_log_debug("vm_record_cb = %d", vm_record_cb);

	if (vm_record_cb != NULL)
	{
		vm_log_debug("vm_record_cb = %d, will callback app.", vm_record_cb);
		PMNG_WRAP_CALLBACK(res_handle, vm_record_cb(result));
	}
}

void vm_record_file_ext(VMWSTR file_name, VMUINT8 format)
{	
	switch(format)
      {
	case VM_FORMAT_AMR:
		vm_wstrcat(file_name, (VMWSTR)VM_FILE_EXT_AMR);
		break;
	case VM_FORMAT_WAV:
		vm_wstrcat(file_name, (VMWSTR)VM_FORMAT_WAV);
		break;
      }
}

VMINT vm_record_start(VMSTR drv_name, VMSTR dir_name, VMSTR rec_name, VMUINT8 format, VMWSTR full_rec_file_wname, vm_recorder_callback vm_record_cb)
{
#ifdef VRE_SUPPORT_SECURITY_FEATURE	
	VMWCHAR * full_temp_wname = NULL;
	VMCHAR usr_drv_name[DRV_NAME_LEN];
	VMWCHAR * app_wpath = NULL;
	VMCHAR * temp_fn = NULL;
#endif

	VMCHAR * full_file_name = NULL;
	VMWCHAR * full_file_wname = NULL;
	VMWCHAR drv_wname[DRV_NAME_LEN];
	VMINT returnval = VM_RECORD_FAILED;
	VMINT result ;

	//当前有电话操作
	if (vm_sal_query_calling() == TRUE)
		return returnval;


	/* 判断调用record 的程序是否在前台运行 */
	if (!vm_pmng_is_fg(vm_pmng_get_current_handle()))
	{
		return returnval;
	}

	//因为可用情况与audio 相同，所以直接用vm_audio_preprocess_play
	if (vm_audio_preprocess_play() == FALSE)
		return returnval;
	
	/*状态检测，录音资源是否可用*/
	//record_res_handle =  vm_res_save_data(VM_RES_TYPE_RECORD_HANDLE, NULL, 0, (void*)vm_record_event_response, vm_pmng_get_current_handle());
	record_res_handle =  vm_res_save_data(VM_RES_TYPE_RECORD_HANDLE, NULL, 0, (void*)vm_record_cb, vm_pmng_get_current_handle());	
	if (record_res_handle <= INIT_VALUE)
		return returnval;

	if (drv_name == NULL || dir_name == NULL || rec_name == NULL)
	{
		return returnval;
	}

	/*判断rec_name的长度(文件名长度范围为[1, REC_NAME_LEN])*/
	/*判断drv_name的长度是否为1*/
	if (strlen(rec_name) < 1 
		|| strlen(rec_name) >= REC_NAME_LEN 
		|| strlen(drv_name) != 1 
		|| strlen(dir_name) > DIR_NAME_LEN
	)
	{
		return returnval;
	}

	if ((drv_name[0] > 'a'  && drv_name[0]  < 'z' )||(drv_name[0] > 'A'  && drv_name[0]  < 'Z' ))
	{
		;
	}
	else
	{
		return returnval;
	}

#ifdef VRE_SUPPORT_SECURITY_FEATURE
	if (_vm_get_disk_permission() == VM_PERMISSION_SYS_DRV)
	{
#endif
		/*判断磁盘是否有空间*/
		//vm_gb2312_to_ucs2(drv_wname, DRV_NAME_LEN, drv_name);
		vm_default_to_ucs2(drv_wname, DRV_NAME_LEN, drv_name);
		if (vm_get_disk_free_space(drv_wname) < 1)
			return returnval; 
#ifdef VRE_SUPPORT_SECURITY_FEATURE
	}
	else
	{
		/*判断vre所在磁盘是否有空间*/
		/*申请空间*/
		if ((temp_fn = vm_calloc(MAX_NAME_LEN))== NULL)
		{
			vm_log_debug(  "vm_record_start_remap , malloc temp_fn no space");
			return returnval;
		}
		if ((app_wpath = vm_calloc(MAX_WNAME_LEN)) == NULL)
		{
			vm_log_debug(  "vm_record_start_remap , malloc app_wpath no space");
			vm_free(temp_fn);
			return returnval;
		}
		vm_log_debug(  "vm_record_start_remap , step 2.1");		
		
		if ((vm_get_exec_filename((VMWSTR)app_wpath)) != 0)
		{
			vm_log_debug(  "vm_record_start_remap , vm_get_exec_filename return 0");
			vm_free(temp_fn);
			vm_free(app_wpath);
			/*表示当前处于内核态*/
			return FALSE;
		}
		/*表示当前处于程序在运行*/
		//vm_ucs2_to_gb2312((VMSTR)temp_fn, MAX_NAME_LEN, (VMWSTR)app_wpath);
		vm_ucs2_to_default((VMSTR)temp_fn, MAX_NAME_LEN, (VMWSTR)app_wpath);
		memset(usr_drv_name, 0x00, DRV_NAME_LEN);
		sprintf(usr_drv_name, "%c", (VMCHAR)temp_fn[0]);

		vm_free(temp_fn);
		vm_free(app_wpath);
		
		//vm_gb2312_to_ucs2(drv_wname, DRV_NAME_LEN, usr_drv_name);
		vm_default_to_ucs2(drv_wname, DRV_NAME_LEN, usr_drv_name);
		if (vm_get_disk_free_space(drv_wname) < 1)
		{
			return returnval; 
		}	
	}

	full_temp_wname = vm_calloc(MAX_WNAME_LEN);
	if (full_temp_wname == NULL)
	{
		vm_free(full_file_name);
		return returnval;
	}
#endif

	/*分配空间*/
	full_file_name = vm_calloc(MAX_NAME_LEN);
	if (full_file_name == NULL)
	{
		return returnval;
	}

	full_file_wname = vm_calloc(MAX_WNAME_LEN);
	if (full_file_wname == NULL)
	{
		vm_free(full_file_name);
#ifdef VRE_SUPPORT_SECURITY_FEATURE
		vm_free(full_temp_wname);
#endif
		return FALSE;
	}
	/*判断目录是否存在*/
	if (strlen(dir_name) < 1)
	{
		sprintf(full_file_name, "%s:\\%s", drv_name, rec_name);
	}
	else if(strlen(dir_name) <= DIR_NAME_LEN)
	{
		sprintf(full_file_name, "%s:\\%s", drv_name, dir_name);

#ifdef VRE_SUPPORT_SECURITY_FEATURE
		vm_default_to_ucs2(full_temp_wname, MAX_WNAME_LEN, full_file_name);	
		_vm_remap_usr_disk((VMWSTR)full_file_wname, (VMWSTR)full_temp_wname);		
#else
		vm_default_to_ucs2(full_file_wname, MAX_WNAME_LEN, full_file_name);
#endif
		vm_file_mkdir(full_file_wname);

		memset(full_file_name, 0x00, MAX_NAME_LEN);
		sprintf(full_file_name, "%s:\\%s\\%s", drv_name, dir_name, rec_name);

	}
	else
	{
		return FALSE; /*目录名太长*/
	}

 	//mdi_audio_stop_all();
	vm_log_debug(  "vm_record_start_remap record file : %s", full_file_name);
	
	memset(full_file_wname, 0x00, MAX_WNAME_LEN);
#ifdef VRE_SUPPORT_SECURITY_FEATURE
	memset(full_temp_wname, 0x00, MAX_WNAME_LEN);
	
	//vm_gb2312_to_ucs2(full_temp_wname, MAX_WNAME_LEN, full_file_name);	
	vm_default_to_ucs2(full_temp_wname, MAX_WNAME_LEN, full_file_name);	
	vm_record_file_ext(full_temp_wname, format);	
	_vm_remap_usr_disk((VMWSTR)full_file_wname, (VMWSTR)full_temp_wname);
#else
	//vm_gb2312_to_ucs2(full_file_wname, MAX_WNAME_LEN, full_file_name);
	vm_default_to_ucs2(full_file_wname, MAX_WNAME_LEN, full_file_name);
	vm_record_file_ext(full_file_wname, format);
#endif
	
	if(full_rec_file_wname != NULL)
	{
		vm_wstrcat(full_rec_file_wname, full_file_wname);
	}
		
		
	vm_file_delete(full_file_wname);
	result = vm_sal_record_start(full_file_wname, format, (mdi_callback)vm_record_event_response);
       if (result == VM_AUDIO_SUCCEED)
       {
       	//vm_res_set_callback(VM_RES_TYPE_RECORD_HANDLE, record_res_handle, (void*)vm_record_cb);
       	vm_res_set_mtk_reshandle(VM_RES_TYPE_RECORD_HANDLE, record_res_handle, VM_RECORD_STATE_RECORD);
      		returnval = VM_RECORD_SUCCEED;
       }
       else
       {
		vm_release_recode_resource();
      		returnval = VM_RECORD_FAILED;
       }
	vm_free(full_file_name);
	vm_free(full_file_wname);
#ifdef VRE_SUPPORT_SECURITY_FEATURE
	vm_free(full_temp_wname);
#endif
       return returnval;
}



VMINT vm_record_pause(void)
{
	VMINT status = VM_RECORD_NO_OF_STATE; 
	VMINT returnval = VM_RECORD_FAILED;		//返回值
	VMINT result;				//过程中的零时结果值

	vm_log_debug(  "entry vm_record_pause.");
	if (vm_record_preprocess() == VM_RECORD_FAILED)
		return returnval;


	/*如果录音状态为空闲或者暂停时，返回结果错误*/
	result = vm_res_get_mtk_reshandle(VM_RES_TYPE_RECORD_HANDLE, record_res_handle, &status);
	vm_log_debug("vm_record_pause, and status = %d", status);
	if(status == VM_RECORD_STATE_RECORD_PAUSED || result  == VM_RES_OUT_OF_RESOURCE)
	{
		vm_log_debug(  "vm_record_pause : the record state is pause or leisure.");
		return returnval;
	}
	
       result = vm_sal_record_pause(vm_record_event_response);
	if (result == VM_AUDIO_SUCCEED)
       {
       	vm_res_set_mtk_reshandle(VM_RES_TYPE_RECORD_HANDLE, record_res_handle, VM_RECORD_STATE_RECORD_PAUSED);
      		returnval = VM_RECORD_SUCCEED;
		vm_log_debug(  "vm_record_pause : record pause success");
       }
       else
       {
      		returnval = VM_RECORD_FAILED;
		vm_log_debug(  "vm_record_pause : record pause fail");
       }
       return returnval;	   
}

VMINT vm_record_resume(void)
{
	VMINT status = VM_RECORD_NO_OF_STATE; 
	VMINT returnval = VM_RECORD_FAILED;		//返回值
	VMINT result;				//过程中的零时结果值

	vm_log_debug(  "entry vm_record_resume.");
	if (vm_record_preprocess() == FALSE)
		return returnval;

	/*如果录音状态为空闲或者录音时，返回结果错误*/
	vm_res_get_mtk_reshandle(VM_RES_TYPE_RECORD_HANDLE, record_res_handle, &status);
	if( status == VM_RECORD_STATE_RECORD)
	{
		vm_log_debug(  "vm_record_resume : the record state is idle or record");
		return returnval;
	}
       result = vm_sal_record_resume(vm_record_event_response);
	if (result == VM_AUDIO_SUCCEED)
       {
       	vm_res_set_mtk_reshandle(VM_RES_TYPE_RECORD_HANDLE, record_res_handle, VM_RECORD_STATE_RECORD);
      		returnval = VM_RECORD_SUCCEED;
		vm_log_debug(  "vm_record_resume : record resume success");
       }
       else
       {
      		returnval = VM_RECORD_FAILED;
		vm_log_debug(  "vm_record_resume : record resume fail");
       }

	vm_log_debug(  "exit vm_record_resume, and returnval = %d", returnval);
       return returnval;
}

VMINT vm_record_stop(void)
{
	VMINT returnval = VM_RECORD_FAILED;		//返回值
	VMINT result;				//过程中的零时结果值

	vm_log_debug("entry vm_record_stop.");
	if (vm_res_get_data_list_count_by_type(VM_RES_TYPE_RECORD_HANDLE) > 0)
	{
		result = vm_sal_record_stop();
		if (result == VM_AUDIO_SUCCEED)
	       {
	      		returnval = VM_RECORD_SUCCEED;
			vm_release_recode_resource();
			vm_log_debug(  "vm_record_stop : record stop success");
	       }
	       else
	       {
	      		returnval = VM_RECORD_FAILED;
			vm_log_debug(  "vm_record_stop : record stop fail");
	       }
	}
	vm_log_debug(  "exit vm_record_stop, and returnval = %d", returnval);
	return returnval;
}

/**************************************************************************/
/*                                                                        								   */
/* Kuro 接口                                                         	   						   */
/*                                                                        								   */
/**************************************************************************/
VMINT vm_audio_vocal_removal_turn_on(void)
{
	int result = VM_KURO_FAILED;
	if (vm_res_get_data_list_count_by_type(VM_RES_TYPE_AUDIO_HANDLE) > 0)
		result = vm_sal_audio_vocal_removal_turn_on();
	return result;
}

VMINT vm_audio_vocal_removal_turn_off(void)
{
	int result = VM_KURO_FAILED;
	if (vm_res_get_data_list_count_by_type(VM_RES_TYPE_AUDIO_HANDLE) > 0)
		result = vm_sal_audio_vocal_removal_turn_off();
	return result;
}


VMINT vm_audio_pitch_shifting_turn_on(void)
{
	int result = VM_KURO_FAILED;
	if (vm_res_get_data_list_count_by_type(VM_RES_TYPE_AUDIO_HANDLE) > 0)
		result = vm_sal_audio_pitch_shifting_turn_on();
	return result;
}

VMINT vm_audio_pitch_shifting_turn_off(void)
{
	int result = VM_KURO_FAILED;
	if (vm_res_get_data_list_count_by_type(VM_RES_TYPE_AUDIO_HANDLE) > 0)
		result = vm_sal_audio_pitch_shifting_turn_off();
	return result;
}

VMINT vm_audio_pitch_shifting_set_level(VMINT16 level)
{
	int result = VM_KURO_FAILED;
	if (vm_res_get_data_list_count_by_type(VM_RES_TYPE_AUDIO_HANDLE) > 0)
	{
		result = vm_sal_audio_pitch_shifting_set_level(level);
	}
	return result;
}

/**************************************************************************/
/*                                                                        								   */
/* 辅助函数                                                         	   						   */
/*                                                                        								   */
/**************************************************************************/
VMINT vm_audio_get_used_res_type(VM_P_HANDLE *used_handle)
{
	if (vm_res_get_data_list_count_by_type(VM_RES_TYPE_MIDI_HANDLE) > 0)
		return VM_RES_TYPE_MIDI_HANDLE;

	if ((vm_res_get_data_list_count_by_type(VM_RES_TYPE_AUDIO_HANDLE)) > 0)
	{
		vm_res_node_t data;
		vm_res_get_data_list_by_type(VM_RES_TYPE_AUDIO_HANDLE, &data, 1);
		*used_handle = data.phandle;
		return VM_RES_TYPE_AUDIO_HANDLE;
	}
	
	if (vm_res_get_data_list_count_by_type(VM_RES_TYPE_RECORD_HANDLE) > 0)
		return VM_RES_TYPE_RECORD_HANDLE;

	if (vm_res_get_data_list_count_by_type(VM_RES_TYPE_VIDEO_HANDLE) > 0)
		return VM_RES_TYPE_VIDEO_HANDLE;

	if (vm_res_get_data_list_count_by_type(VM_RES_TYPE_AUDIO_BIT_HANDLE) > 0)
		return VM_RES_TYPE_AUDIO_BIT_HANDLE;

	if (vm_res_get_data_list_count_by_type(VM_RES_TYPE_VIDEO_BIT_HANDLE) > 0)
		return VM_RES_TYPE_VIDEO_BIT_HANDLE;

	return NULL;
}

 VMINT vm_audio_stop_used_res_type(vm_res_type_enum res_type)
 {
 	VMINT result = FALSE;
	
	switch(res_type)
	{
	case VM_RES_TYPE_MIDI_HANDLE:
		vm_midi_stop_all();		
		result = TRUE;
		break;
	case VM_RES_TYPE_AUDIO_HANDLE:
		{
			int res;
			res = vm_audio_stop(NULL);
			result = ((res == VM_AUDIO_SUCCEED) ? TRUE : FALSE);
		}
		break;
	case VM_RES_TYPE_RECORD_HANDLE:
		result = vm_record_stop();
		break;
	case VM_RES_TYPE_VIDEO_HANDLE:
	case VM_RES_TYPE_AUDIO_BIT_HANDLE:
	case VM_RES_TYPE_VIDEO_BIT_HANDLE:
		break;
	}

	return result;
 }


VMINT vm_audio_preprocess_play(void)
{
	//当前占用音频的资源类型
	VMINT audio_type;		
	//使用audio 的进程句柄
	VM_P_HANDLE use_audio_handle = INIT_VALUE;
	int result = FALSE;	

	//当前有电话操作
	if (vm_sal_query_calling() == TRUE)
		return result;
	
	//得到当前占用音频资源的类型
	audio_type = vm_audio_get_used_res_type(&use_audio_handle);
	vm_log_debug(  "entry vm_audio_preprocess_play, and audio_type = %d", audio_type);
	switch(audio_type)
	{
	case NULL:
		//未有音频资源被占用
		result = TRUE;
		break;
	case VM_RES_TYPE_AUDIO_HANDLE:
		{
			//获得当前进程ID
			VM_P_HANDLE current_handle = vm_pmng_get_current_handle();
			//前后台audio 资源相互抢占的情况有以下四种：
			// 1. 占用audio 的进程为前台，申请 进程也为前台，可抢占(返回TRUE)。
			// 2. 占用audio 的进程为后台，申请 进程的为前台，可抢占(返回TRUE)。
			// 3. 占用audio 的进程为后台，申请 进程也为后台，可抢占(返回TRUE)。
			// 4. 占用audio 的进程为前台，申请 进程的为后台，不可抢占(返回FALSE)。
			if ((!vm_pmng_is_fg(current_handle)) && vm_pmng_is_fg(use_audio_handle))
			{
				//本情况为占用audio 的进程是前台，申请 进程的为后台
				vm_log_debug("current_handle is BG, use_audio_handle is FG.");
				result = FALSE;
			}
			else
			{
				//本情况为可抢占
				vm_log_debug("Can to loot.");
				//通知VRE 系统停止使用音频资源				
				vm_audio_stop(NULL);	
				result = TRUE;
			}
		}
		break;
	case VM_RES_TYPE_MIDI_HANDLE:
		vm_midi_stop_all();
		result = TRUE;
		break;
	case VM_RES_TYPE_VIDEO_HANDLE:
	case VM_RES_TYPE_VIDEO_BIT_HANDLE:
	case VM_RES_TYPE_AUDIO_BIT_HANDLE:
	case VM_RES_TYPE_RECORD_HANDLE:
		result = FALSE;
		break;
	}

	vm_log_debug(  "will exit vm_audio_preprocess_play, and result = %d", result);
	return result;
}

VMINT vm_midi_preprocess_play(void)
{
	VMINT midi_count;
	VMINT audio_type;
	VM_P_HANDLE use_audio_handle;
	int result = FALSE;	
	VM_P_HANDLE current_handle = vm_pmng_get_current_handle();

	//当前有电话操作
	if (vm_sal_query_calling() == TRUE)
		return result;

	//wei.xia add by 0623
	//当前进程在后台时，直接判定FLASE
	if (vm_pmng_is_fg(vm_pmng_get_current_handle()) == FALSE)
	{
		vm_log_debug( "current process is BG, return FALSE.");
		return result;
	}
	//add end
		

	//得到当前占用音频资源的类型
	audio_type = vm_audio_get_used_res_type(&use_audio_handle);
	vm_log_debug( "entry vm_midi_preprocess_play, and audio type = %d", audio_type);
	switch(audio_type)
	{
	case NULL:
		//未有音频资源被占用
		result = TRUE;
		break;
	case VM_RES_TYPE_AUDIO_HANDLE:
		{
			//判断当前进程是否在前台
			if (!vm_pmng_is_fg(current_handle))
			{
				//当前进程不在前台
				vm_log_debug("current process is BG.");
				result = FALSE;
			}
			else
			{
				//当前进程为前台时
				vm_log_debug("current process is FG.");
				//判断占用音频资源的进程在后台
				if (!vm_pmng_is_fg(use_audio_handle))
				{
					//通知VRE 系统停止使用音频资源
					vm_log_debug("use audio process is BG.");
					vm_sal_audio_suspend_background_play();
				}
				else
				{
					vm_log_debug("use audio process is FG.");
					vm_audio_stop(NULL);	
				}
				result = TRUE;
			}
		}
		break;
	case VM_RES_TYPE_MIDI_HANDLE:
		/* 要判断现在已打开几个midi 音频，未超过四个返回TRUE  */
		midi_count = vm_res_get_data_list_count_by_proecss(current_handle, VM_RES_TYPE_MIDI_HANDLE);
		vm_log_debug( "midi_count = %d", midi_count);
		if (midi_count < VM_MIDI_PLAY_MAX)
			result = TRUE;
		break;
	case VM_RES_TYPE_VIDEO_HANDLE:
	case VM_RES_TYPE_VIDEO_BIT_HANDLE:
	case VM_RES_TYPE_AUDIO_BIT_HANDLE:
	case VM_RES_TYPE_RECORD_HANDLE:
		result = FALSE;
		break;
	}

	vm_log_debug( "exit vm_midi_preprocess_play, and result = %d", result);
	return result;
}

VMINT vm_record_preprocess(void)
{
	/* 判断调用record 的程序是否在前台运行 */
	if (!vm_pmng_is_fg(vm_pmng_get_current_handle()))
	{
		vm_log_debug(  "Record is used, but  isn't FG.");
		return VM_RECORD_FAILED;
	}

	/* 判断record 的程序是否在运行 */
	if (vm_res_get_data_list_count_by_type(VM_RES_TYPE_RECORD_HANDLE) < 0)
	{
		vm_log_debug(  "Record isn't used,  the record resource is NULL.");
		return VM_RECORD_FAILED;
	}

	return VM_RECORD_SUCCEED;	
}



#endif /* __VRE__ */
