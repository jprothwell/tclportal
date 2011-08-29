#ifdef __VRE__
#include "mmi_include.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "gpioInc.h"
#if defined(__VRE_RB_09A__)
#include "ProfileGprots.h"
#include "ProfileMgrGProt.h"
#endif
#include "MMI_features.h"
#if defined(__VRE_RB_09A__)
#include "UCMGProt.h"
#else
#include "UcmSrvGprot.h"
#endif

//wei.xia add by 0621
#include "AudioPlayerDef.h"
#include "AudioPlayerType.h"
//add end

//wei.xia add by 0329
//#include "GeneralDeviceGprot.h"
//add end

#include "vmsys.h"
#include "vmsalmm.h"
#include "vmlog.h"
#include "vmopt.h"
#include "vmio.h"
#include "vmchset.h"
#include "vmmod.h"
#include "vmopt.h"
#include "vmstdlib.h"
#include "vmdl.h"
#include "vmfilere.h"
#include "vmmacrostub.h"



/**************************************************************************/
/*                                                                        */
/* 全部局变量引用                                                        */
/*                                                                        */
/**************************************************************************/
extern VMINT vre_running;
extern VMUINT8* (*user_get_resource_fp)(VMINT resid, VMINT* len);

/**************************************************************************/
/*                                                                        */
/* 全部局函数引用                                                        */
/*                                                                        */
/**************************************************************************/
extern mmi_frm_kbd_tone_state_enum mmi_frm_kbd_get_key_tone_state(void);
extern void mmi_frm_kbd_set_tone_state(mmi_frm_kbd_tone_state_enum state);

#ifdef VRE_SUPPORT_SECURITY_FEATURE
extern VMINT _vm_remap_usr_disk(VMWSTR dest_filename, VMWSTR source_filename);
extern VMINT _vm_get_disk_permission(void);
#endif

#if defined(__VRE_RB_09A__)
extern S16 SetFileAsActivateRingToneID(S8 *pathfileName, U16 *p_ringtoneid);
#endif


/**************************************************************************/
/*                                                                        */
/* 模块变量声明。                                                         */
/*                                                                        */
/**************************************************************************/

/* 震动一次的时间 */
#define ONCE_VIBRATOR_TIME		1000  

/* 上次震动时的毫秒数 */
VMINT g_vibrator_time = 0;


typedef enum
{
	VM_KURO_NO_EFFECT = -5,
		
	/* pitch shifting effect */
     	VM_KURO_PITCH_SHIFTING_N4,
     	VM_KURO_PITCH_SHIFTING_N3,
     	VM_KURO_PITCH_SHIFTING_N2,
     	VM_KURO_PITCH_SHIFTING_N1,
     	VM_KURO_PITCH_SHIFTING_0,
     	VM_KURO_PITCH_SHIFTING_P1,
     	VM_KURO_PITCH_SHIFTING_P2,
     	VM_KURO_PITCH_SHIFTING_P3,
     	VM_KURO_PITCH_SHIFTING_P4,
     	
	/* vocal removal effect */
	VM_KURO_VOCAL_REMOVAL_ON,
	VM_KURO_VOCAL_REMOVAL_OFF,	
	
	VM_KURO_PITCH_SHIFTING_END_OF_ENUM	
}VM_KURO_EFFECT_ENUM;
static VM_KURO_EFFECT_ENUM vm_kuro_effect_flag = VM_KURO_NO_EFFECT;


/**
 * AUDIO类型的标志。
 */typedef enum
{
	VM_AUDIO_NONE,
	VM_AUDIO_FILE,
	VM_AUDIO_STRING,
	VM_AUDIO_MAX
}VM_AUDIO_TYPE_ENUM;
static VM_AUDIO_TYPE_ENUM vm_audio_type = VM_AUDIO_NONE;

/**
 * 当前音量。
 */
static VMINT current_volume = DEFAULT_VOLUME;

/**
 * 震动的标志位。
 */
static VMINT vibrator_flag = FALSE;

/**
 * midi interrupt register 的标志位。
 */
 static VMINT midi_interrupt_register = FALSE;
 
/**************************************************************************/
/*                                                                        */
/* 模块函数声明。                                                         */
/*                                                                        */
/**************************************************************************/
/* 
 * 音频播放的用户回调函数指针。
 */
static void (*audio_callback)(VMINT result) = NULL;

/*
 * MIDI播放的用户回调函数。
 */
static void (*sal_midi_callback)(VMINT handle, VMINT result) = NULL;

/*
 * Record回调函数。
 */
static vm_recorder_callback sal_record_cb = NULL;

/* 
 * MTK音频播放回调函数。
 */
static void vm_sal_audio_callback(VMINT result);

/* 
 * MTK音频外部中断audio 回调函数。
 */
static void vm_sal_audio_interrupt_callback(VMINT result);

/* 
 * MTK音频背景播放回调函数。
 */
static VMINT vm_sal_audio_background_callback(VMINT result);

/* 
 * MTK音频外部中断midi 回调函数。
 */
static void vm_sal_midi_interrupt_callback(VMINT result);

/*
 * MTK MIDI播放回调函数。
 */
static void vm_sal_midi_callback(VMINT handle, VMINT result);

/* 
 * MTK音频kuro 音效关闭函数。
 */
static void vm_sal_kuro_effect_off(void);

/* 
 * MTK音频kuro 音效恢复函数。
 */
static void vm_sal_kuro_effect_resume(void);


/**************************************************************************/
/*                                                                        								   */
/* Audio 接口                                                         	   						   */
/*                                                                        								   */
/**************************************************************************/
static void vm_auido_func_after_play_successed(void)
{
	vm_sal_set_volume(current_volume);	
	mdi_audio_set_background_handler(MDI_BACKGROUND_APP_VRE, (mdi_bg_callback)vm_sal_audio_background_callback);	
	mdi_audio_register_interrupt_callback((mdi_callback)vm_sal_audio_interrupt_callback);
	vm_sal_kuro_effect_resume();
}

static void vm_auido_func_after_stop_successed(void)
{
	vm_audio_type = VM_AUDIO_NONE;
	vm_sal_kuro_effect_off();
	vm_kuro_effect_flag = VM_KURO_NO_EFFECT;
	mdi_audio_clear_interrupt_callback();
	mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_VRE);
}

VMINT vm_sal_audio_play_file(VMWSTR filename, void (*f)(VMINT result)) 
{
	VMINT retcode = VM_AUDIO_FAILED;
#ifdef VRE_SUPPORT_SECURITY_FEATURE
	VMWCHAR* remap_file_wname = NULL;
#endif

	vm_log_debug("entry vm_sal_audio_play_file.");

	/*检测音频文件名*/
	if (filename == NULL)
	{
		vm_log_debug("vm_sal_audio_play_file : the ptr of filename is NULL");
		return VM_AUDIO_FAILED;
	}
	if (vm_wstrlen(filename) <= 0 || vm_wstrlen(filename) > MAX_WNAME_LEN)
	{
		vm_log_debug("vm_sal_audio_play_file : the length of filename is error");
		return VM_AUDIO_FAILED;
	}
	
#ifdef VRE_SUPPORT_SECURITY_FEATURE
	/*文件重定向*/
	if ((remap_file_wname = vm_calloc(MAX_WNAME_LEN)) == NULL)
	{
		vm_log_debug(  "vm_sal_audio_play_file : malloc the remap_file_name fail");
		return VM_AUDIO_FAILED; 
	}

	if (_vm_remap_usr_disk((VMWSTR)remap_file_wname, (VMWSTR)filename) == FALSE)
	{
		vm_free(remap_file_wname);
		vm_log_debug(  "vm_sal_audio_play_file : _vm_remap_usr_disk error");
		return VM_AUDIO_FAILED;
	}
#endif

	 vm_audio_type = VM_AUDIO_FILE;
	
	/*设置回调函数*/
	audio_callback = f;
	
	/*播放音频文件*/
#ifdef VRE_SUPPORT_SECURITY_FEATURE
	retcode = mdi_audio_play_file_portion_with_vol_path(remap_file_wname, 0, 0, DEVICE_AUDIO_PLAY_ONCE, NULL, 
		vm_sal_audio_callback, current_volume, MDI_DEVICE_SPEAKER2);
	vm_free(remap_file_wname);
#else
	retcode = mdi_audio_play_file_portion_with_vol_path(filename, 0, 0, DEVICE_AUDIO_PLAY_ONCE, NULL, 
		vm_sal_audio_callback, current_volume, MDI_DEVICE_SPEAKER2);
#endif
	vm_log_debug(  "vm_sal_audio_play_file : reture value of mdi_audio_play_file_portion_with_vol_path is %d", retcode);
	if(retcode == MDI_AUDIO_SUCCESS)
	{
		vm_auido_func_after_play_successed();
	}
	
	return retcode == MDI_AUDIO_SUCCESS ? VM_AUDIO_SUCCEED : VM_AUDIO_FAILED;
}

VMINT vm_sal_audio_play_file_ex(VMWSTR filename, VMUINT start_time, VMUINT path, void (*f)(VMINT result))
{
	VMINT retcode = VM_AUDIO_FAILED;
#ifdef VRE_SUPPORT_SECURITY_FEATURE
	VMWCHAR * remap_file_wname = NULL;
#endif

	/*检测音频文件名*/
	if (filename == NULL)
	{
		vm_log_debug(  "vm_sal_audio_play_file_ex : the ptr of filename is NULL");
		return VM_AUDIO_FAILED;
	}
	if (vm_wstrlen(filename) <= 0 || vm_wstrlen(filename) > MAX_NAME_LEN)
	{
		vm_log_debug(  "vm_sal_audio_play_file_ex : the length of filename is error");
		return VM_AUDIO_FAILED;
	}

#ifdef VRE_SUPPORT_SECURITY_FEATURE
	/*文件重定向*/
	if ((remap_file_wname = vm_malloc(MAX_WNAME_LEN)) == NULL)
	{
		vm_log_debug(  "vm_sal_audio_play_file_ex : malloc the remap_file_name fail");
		return VM_AUDIO_FAILED; 
	}
	memset(remap_file_wname, 0x00, MAX_WNAME_LEN);
	if (_vm_remap_usr_disk((VMWSTR)remap_file_wname, (VMWSTR)filename) == FALSE)
	{
		vm_free(remap_file_wname);
		vm_log_debug(  "vm_sal_audio_play_file_ex : _vm_remap_usr_disk error");
		return VM_AUDIO_FAILED;
	}
#endif

	vm_audio_type = VM_AUDIO_FILE;
	
	/*设置回调函数*/
	audio_callback = f;
	
	/*播放音频文件*/
#ifdef VRE_SUPPORT_SECURITY_FEATURE
	retcode = mdi_audio_play_file_portion_with_vol_path(
				remap_file_wname,
				start_time,
				0, 
				DEVICE_AUDIO_PLAY_ONCE,
				NULL,
				vm_sal_audio_callback,
		              current_volume,
		              path);		
	vm_free(remap_file_wname);
#else
	retcode = mdi_audio_play_file_portion_with_vol_path(
				filename,
				start_time,
				0, 
				DEVICE_AUDIO_PLAY_ONCE,
				NULL,
				vm_sal_audio_callback,
		              current_volume,
		              path);	
#endif
	
	vm_log_debug(  "vm_sal_audio_play_file_ex : reture value of mdi_audio_play_file_portion_with_vol_path is %d", retcode);
	if(retcode == MDI_AUDIO_SUCCESS)
	{
		vm_auido_func_after_play_successed();	
	}
	
	return retcode == MDI_AUDIO_SUCCESS ? VM_AUDIO_SUCCEED : VM_AUDIO_FAILED;
}


VMINT vm_sal_audio_play_bytes(void *audio_data, VMUINT len, VMUINT8 format, VMUINT start_time, VMUINT path, void (*f)(VMINT result))
{
	VMINT retcode = VM_AUDIO_FAILED;
	vm_audio_type = VM_AUDIO_STRING;

	vm_log_debug("entry vm_sal_audio_play_bytes.");
	
	/*设置回调函数*/
	audio_callback = f;

	/*播放音频文件*/
	retcode = mdi_audio_play_string_portion_with_vol_path(
		audio_data, 
		len, 
		format, 
		start_time, 
		0, 
		DEVICE_AUDIO_PLAY_ONCE, 
		NULL, 
		vm_sal_audio_callback, 
		current_volume,
		path);

	vm_log_debug(  "vm_sal_audio_play_bytes : reture value of mdi_audio_play_string_portion_with_vol_path is %d", retcode);
	if(retcode == MDI_AUDIO_SUCCESS)
		vm_auido_func_after_play_successed();

	return retcode == MDI_AUDIO_SUCCESS ? VM_AUDIO_SUCCEED : VM_AUDIO_FAILED;
}

VMINT vm_sal_audio_pause(void (*f)(VMINT result)) 
{
	VMINT retcode;

	vm_log_debug(  "entry vm_sal_audio_pause.");
	
	//wei.xia add by 0713
	if (vm_audio_type == VM_AUDIO_STRING)
		return VM_AUDIO_FAILED;
	//add end
	
	audio_callback = f;
	retcode = mdi_audio_pause(0, vm_sal_audio_callback);

	vm_log_debug(  "mdi_audio_pause = %d.", retcode);
	if(retcode != MDI_AUDIO_SUCCESS)
	{
		vm_log_debug(  "vm_sal_audio_pause : mdi_audio_pause error  retcode=%d", retcode);
	}
	
	return retcode == MDI_AUDIO_SUCCESS ? VM_AUDIO_SUCCEED : VM_AUDIO_FAILED;
}

VMINT vm_sal_audio_resume(void (*f)(VMINT result)) 
{
	VMINT retcode;

	vm_log_debug(  "entry vm_sal_audio_resume.");
	
	//wei.xia add by 0713
	if (vm_audio_type == VM_AUDIO_STRING)
		return VM_AUDIO_FAILED;
	//add end
	
	audio_callback = f;
	retcode = mdi_audio_resume(0, vm_sal_audio_callback);

	vm_log_debug(  "mdi_audio_resume = %d.", retcode);
	if(retcode != MDI_AUDIO_SUCCESS)
	{
		vm_log_debug(  "vm_sal_audio_resume : mdi_audio_resume error retcode=%d", retcode);
	}
	
	return retcode == MDI_AUDIO_SUCCESS ? VM_AUDIO_SUCCEED : VM_AUDIO_FAILED;
}

VMINT vm_sal_audio_stop(void (*f)(VMINT result)) 
{
	VMINT retcode;

	if (vm_audio_type == VM_AUDIO_FILE)
	{
		vm_log_debug("entry mdi_audio_stop_file");
		retcode = mdi_audio_stop_file();
	}
	else if (vm_audio_type == VM_AUDIO_STRING)
	{
		vm_log_debug("entry mdi_audio_stop_string");
		retcode = mdi_audio_stop_string();
	}
	else
	{
		vm_log_debug("not stop");
		retcode = VM_AUDIO_FAILED;
	}
	
	if( retcode == MDI_AUDIO_SUCCESS)
	{
		vm_log_debug("vm_sal_audio_stop = %d", retcode);
		vm_auido_func_after_stop_successed();
		return VM_AUDIO_SUCCEED;
	}
	else
	{
		vm_log_debug("vm_sal_audio_stop : mdi_audio_stop error retcode: %d", retcode);
		return VM_AUDIO_FAILED;
	}
}

VMINT vm_sal_audio_duration(VMWSTR filename) 
{
	VMINT result, duration;

#ifdef VRE_SUPPORT_SECURITY_FEATURE
	VMWCHAR * remap_file_wname = NULL;
#endif

	vm_log_debug(  "entry vm_sal_audio_duration");

	if (filename == NULL)
	{
		vm_log_debug(  "vm_sal_audio_duration : the ptr of filename is NULL");
		return VM_AUDIO_FAILED;
	}

	if (vm_wstrlen(filename) == 0 || vm_wstrlen(filename) > MAX_NAME_LEN)
	{
		vm_log_debug(  "vm_sal_audio_duration : the length of filename is error");
		return VM_AUDIO_FAILED;
	}
	
#ifdef VRE_SUPPORT_SECURITY_FEATURE
	/*文件重定向*/
	if ((remap_file_wname = vm_calloc(MAX_WNAME_LEN)) == NULL)
	{
		vm_log_debug(  "vm_sal_audio_duration : malloc the remap_file_name fail");
		return VM_AUDIO_FAILED;
	}

	//memset(remap_file_wname, 0x00, MAX_WNAME_LEN);
	if (_vm_remap_usr_disk((VMWSTR)remap_file_wname, (VMWSTR)filename) == FALSE)
	{
		vm_free(remap_file_wname);
		vm_log_debug(  "vm_sal_audio_duration : _vm_remap_usr_disk error");
		return VM_AUDIO_FAILED;
	}
#endif

	duration = VM_AUDIO_FAILED;
#ifdef VRE_SUPPORT_SECURITY_FEATURE
	result = mdi_audio_get_duration(remap_file_wname, (U32*)&duration);
	vm_free(remap_file_wname);
#else
	result = mdi_audio_get_duration(filename, (U32*)&duration);
#endif

	vm_log_debug(  "exit vm_sal_audio_duration, and result = %d, duration = %d", result, duration);
	return result == MDI_AUDIO_SUCCESS ? (duration) : VM_AUDIO_FAILED;
}

VMINT vm_sal_audio_bytes_duration(void *audio_data, VMUINT len, VMUINT8 format)
{
	VMINT result, duration;
	
	result = mdi_audio_get_duration_by_string(audio_data, len, format, (U32*)&duration);

	return result == MDI_AUDIO_SUCCESS ? (duration) : VM_AUDIO_FAILED;
}

VMINT vm_sal_audio_get_time(void)
{
	VMINT result;
	VMUINT offset;
	
	result =  mdi_audio_get_progress_time(&offset);

	return result == MDI_AUDIO_SUCCESS ? (offset) : VM_AUDIO_FAILED;
}

void vm_sal_audio_interrupt_callback(VMINT result)
{
	vm_log_debug("entry vm_sal_audio_interrupt_callback, and result = %d", result);
	 if(result == MDI_AUDIO_TERMINATED)	
	 {
	 	vm_log_debug("entry vm_sal_audio_interrupt_callback, and callback VM_AUDIO_RESULT_INTERRUPT.");
		vm_sal_audio_callback(VM_AUDIO_RESULT_INTERRUPT);
	 }
}

VMINT vm_sal_audio_background_callback(VMINT result)
{
	vm_log_debug("entry vm_sal_audio_background_callback, and result = %d", result);
	mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_VRE);
	 if(result == MDI_AUDIO_TERMINATED)	
	 {
	 	vm_log_debug("entry vm_sal_audio_background_callback, and callback VM_AUDIO_RESULT_INTERRUPT.");
		vm_sal_audio_callback(VM_AUDIO_RESULT_INTERRUPT);
	 }
	 else
	 {
		vm_sal_audio_callback(VM_AUDIO_RESULT_INTERRUPT_RESUME);
	 }
	  return TRUE;
}

void vm_sal_audio_callback(VMINT result) 
{
	vm_log_debug("entry vm_sal_audio_callback.");

      	if (vre_running == FALSE)return;
	
	if (NULL == audio_callback)
	{
		vm_log_debug(  "NULL == audio_callback");
		return ;
	}	

	vm_log_debug(  "sal audio callback: result=%d", result);
	switch (result) {
	case MDI_AUDIO_SUCCESS:
		break;
	case MDI_AUDIO_RESUME:
		audio_callback(VM_AUDIO_RESULT_RESUME);
		break;
	case MDI_AUDIO_BLOCKED:
		audio_callback(VM_AUDIO_RESULT_PAUSE);
		break;
	case MDI_AUDIO_TERMINATED:	
		vm_audio_type = VM_AUDIO_NONE;
		vm_sal_kuro_effect_off();
		audio_callback(VM_AUDIO_RESULT_STOP);
		break;
	case MDI_AUDIO_END_OF_FILE:
		vm_auido_func_after_stop_successed();
		audio_callback(VM_AUDIO_RESULT_END_OF_FILE);
		break;
#if defined(__VRE_RB_08A__) || defined(__VRE_RB_08B__)
#else
	case MDI_AUDIO_DEMO_END:
			audio_callback(VM_AUDIO_RESULT_DEMO_END);	
			break; 
#endif
	case VM_AUDIO_RESULT_INTERRUPT:
		vm_audio_type = VM_AUDIO_NONE;
		audio_callback(VM_AUDIO_RESULT_INTERRUPT);
		break;
	case VM_AUDIO_RESULT_INTERRUPT_RESUME:
		audio_callback(VM_AUDIO_RESULT_INTERRUPT_RESUME);
		break;
	default:
		audio_callback(VM_AUDIO_RESULT_STOP);
		break;
	}
}

/**************************************************************************/
/*                                                                        								   */
/* Midi 接口                                                         	   						   */
/*                                                                        								   */
/**************************************************************************/
VMINT vm_sal_midi_play(VMINT resid, VMINT repeat, void (*f)(VMINT handle, VMINT event)) 
{
	S32 handle;
	VMUINT8* rawdata = NULL;
	VMINT len =0;
	mdi_result play_result;

	if ((rawdata = vm_sal_midi_get_resource(resid, &len)) == NULL)
	{
		vm_log_debug(  "vm_sal_midi_play : vm_sal_midi_get_resource rawdata is NULL." );
		if (user_get_resource_fp)
		{
			rawdata = user_get_resource_fp(resid, &len);
			if (!rawdata)
			{
				vm_log_debug(  "vm_midi_play : user_get_resource_fp rawdata is NULL." );
				return VM_MIDI_FAILED;
			}
		}
		else
		{
			vm_log_debug(  "vm_midi_play : user_get_resource_fp no define." );
			return VM_MIDI_FAILED;
		}
	}
	
	sal_midi_callback = f;	
	if ((handle = mdi_audio_mma_open_string(rawdata, len, MDI_FORMAT_SMF, (VMUINT8)repeat, vm_sal_midi_callback)) != 0)   
	{
		/*设置播放路径*/
		mdi_audio_set_headset_mode_output_path(VM_DEVICE_SPEAKER2);		
		
		play_result = mdi_audio_mma_play(handle);
		vm_log_debug(  "vm_sal_midi_play : return value of mdi_audio_mma_open_string is %d", play_result);
		if (play_result != MDI_AUDIO_SUCCESS)
    		{
    			mdi_audio_mma_close(handle);
    			return VM_MIDI_FAILED;
		}
		else
		{
			vm_log_debug(  "vm_sal_midi_play return handle = %d", handle);
			/*设置音量*/
			vm_sal_set_volume(current_volume);			
			return handle;
		}
	}
	else 
	{
		vm_log_debug(  "vm_sal_midi_play error : return value of mdi_audio_mma_open_string is %d", handle);
	}
	return VM_MIDI_FAILED;
}

VMINT vm_sal_midi_play_ex(VMINT resid, VMUINT start_time, VMINT repeat, VMUINT path, void (*f)(VMINT handle, VMINT event))
{
	S32 handle;
	VMUINT8* rawdata = NULL;
	VMINT len =0;
	mdi_result play_result;

	
	if ((rawdata = vm_sal_midi_get_resource(resid, &len)) == NULL)
	{
		vm_log_debug(  "vm_midi_play : vm_sal_midi_get_resource rawdata is NULL." );
		if (user_get_resource_fp)
		{
			rawdata = user_get_resource_fp(resid, &len);
			if (!rawdata)
			{
				vm_log_debug(  "vm_midi_play : user_get_resource_fp rawdata is NULL." );
				return VM_MIDI_FAILED;
			}
		}
		else
		{
			vm_log_debug(  "vm_midi_play : user_get_resource_fp no define." );
			return VM_MIDI_FAILED;
		}
	}
	
	sal_midi_callback = f;	
	if ((handle = mdi_audio_mma_open_string(rawdata, len, MDI_FORMAT_SMF, (VMUINT8)repeat, vm_sal_midi_callback)) != 0)   
	{
		/*设置播放路径*/
		mdi_audio_set_headset_mode_output_path(path);
		/*设置起始时间*/
		vm_sal_midi_set_time(handle, start_time);
		
		play_result = mdi_audio_mma_play(handle);
		vm_log_debug(  "vm_midi_play : return value of mdi_audio_mma_open_string is %d", play_result);
		if (play_result != MDI_AUDIO_SUCCESS)
    		{
    			mdi_audio_mma_close(handle);
    			return VM_MIDI_FAILED;
		}
		else
		{
			vm_log_debug(  "vm_sal_midi_play_ex return handle = %d", handle);
			/*设置音量*/
			vm_sal_set_volume(current_volume);
			return handle;
		}
	}
	else 
	{
		vm_log_debug(  "vm_midi_play error : return value of mdi_audio_mma_open_string is %d", handle);
	}
	return VM_MIDI_FAILED;
}


VMINT vm_sal_midi_play_by_bytes( VMUINT8 * midibuf, VMINT len, VMINT repeat, void (*f)(VMINT handle, VMINT event) )
{
	mdi_result play_result;
	mdi_handle handle = 0;

	sal_midi_callback = f;
	vm_log_debug("sal_midi_callback = %d", sal_midi_callback);
	if ((handle = mdi_audio_mma_open_string(midibuf, len, MDI_FORMAT_SMF, (VMUINT8)repeat, vm_sal_midi_callback)) != 0)   
	{
		/*设置播放路径*/
		mdi_audio_set_headset_mode_output_path(VM_DEVICE_SPEAKER2);		
		
		play_result = mdi_audio_mma_play(handle);
		vm_log_debug(   "vm_sal_midi_play_by_bytes : return value of mdi_audio_mma_open_string is %d", play_result);
		if (play_result != MDI_AUDIO_SUCCESS)
    		{
    			mdi_audio_mma_close(handle);
    			return VM_MIDI_FAILED;
		}
		else
		{
			vm_log_debug(  "vm_sal_midi_play_by_bytes return handle = %d", handle);
			/*设置音量*/
			vm_sal_set_volume(current_volume);
			return handle;
		}
	}
	else 
	{
		vm_log_debug(  "vm_midi_play_by_bytes error: return value of mdi_audio_mma_open_string is %d", handle);
	}
	return VM_MIDI_FAILED;
}

VMINT vm_sal_midi_play_by_bytes_ex( VMUINT8 * midibuf, VMINT len, VMUINT start_time, VMINT repeat, VMUINT path, void (*f)(VMINT handle, VMINT event))
{
	VMINT handle;
	mdi_result play_result;

	if (midibuf == NULL || len <= 0 || f == NULL)
		return VM_MIDI_FAILED;
	
	sal_midi_callback = f;
	if ((handle = mdi_audio_mma_open_string(midibuf, len, MDI_FORMAT_SMF, (VMUINT8)repeat, vm_sal_midi_callback)) != 0)   
	{
		/*设置播放路径*/
		mdi_audio_set_headset_mode_output_path(path);
		/*设置起始时间*/
		vm_sal_midi_set_time(handle, start_time);

		play_result = mdi_audio_mma_play(handle);
		vm_log_debug(  "vm_midi_play_by_bytes : return value of mdi_audio_mma_open_string is %d", play_result);
		if (play_result != MDI_AUDIO_SUCCESS)
    		{
    			mdi_audio_mma_close(handle);
    			return VM_MIDI_FAILED;
		}
		else
		{
			vm_log_debug(  "vm_sal_midi_play_by_bytes_ex return handle = %d", handle);
			/*设置音量*/
			vm_sal_set_volume(current_volume);
			return handle;
		}
	}
	else 
	{
		vm_log_debug(  "vm_midi_play_by_bytes error: return value of mdi_audio_mma_open_string is %d", handle);
	}
	return VM_MIDI_FAILED;
}

VMINT vm_sal_midi_pause(VMINT handle)
{
	return mdi_audio_mma_pause(handle);
}

VMINT vm_sal_midi_resume(VMINT handle)
{
	return mdi_audio_mma_resume(handle);
}

VMINT vm_sal_midi_get_time(VMINT handle, VMUINT *current_time)
{
#if defined(__VRE_RB_08A__) || defined(__VRE_RB_08B__)
	return VM_MIDI_FAILED;
#else
	return mdi_audio_mma_get_current_time(handle, current_time);
#endif
}

VMINT vm_sal_midi_set_time(VMINT handle, VMUINT current_time)
{
	return mdi_audio_mma_set_start_time(handle, current_time);
}

VMINT vm_sal_midi_stop(VMINT handle) 
{
	int ret;
	vm_log_debug(  "vm_sal_midi_stop will stop midi play, handle=%d", handle);

	ret = mdi_audio_mma_stop(handle);
	vm_log_debug(  "mdi_audio_mma_stop = %d", ret);
	ret = mdi_audio_mma_close(handle);
	vm_log_debug(  "mdi_audio_mma_close = %d", ret);
	vm_log_debug(  "vm_sal_midi_stop over, handle=%d", handle);

	return VM_MIDI_SUCCEED;
}

void vm_sal_midi_callback(VMINT handle, VMINT result) 
{
	mdi_result res;

	vm_log_debug(  "vm_sal_midi_callback: handle=%d, result=%d.", handle, result);
	vm_log_debug(  "sal_midi_callback = %d", sal_midi_callback);

      	if (vre_running == FALSE)return;
	
	switch (result) 
	{
		case MDI_AUDIO_END_OF_FILE:
			res = mdi_audio_mma_close(handle);
			vm_log_debug("mdi_audio_mma_close(%d) = %d", handle, res);
			sal_midi_callback((VMINT)handle, VM_AUDIO_RESULT_END_OF_FILE);
			break;
		case MDI_AUDIO_TERMINATED:
			sal_midi_callback((VMINT)handle, VM_AUDIO_RESULT_STOP);
			break;
		//wei.xia add by 0329
		case VM_AUDIO_RESULT_INTERRUPT:
			sal_midi_callback((VMINT)handle, VM_AUDIO_RESULT_INTERRUPT);
			break;
		//add end
		default:
			sal_midi_callback((VMINT)handle, VM_FORMAT_OTHER);
			break;
	}	
	vm_log_debug(   "sal_midi_callback over");
}

//wei.xia add by 0329
void vm_sal_midi_interrupt_callback(VMINT result)
{
	vm_log_debug("entry vm_sal_midi_interrupt_callback, and result = %d", result);
	 if(result == MDI_AUDIO_TERMINATED)	
	 {
	 	vm_log_debug("entry vm_sal_midi_interrupt_callback, and callback VM_AUDIO_RESULT_INTERRUPT.");
		vm_sal_midi_callback(NULL, VM_AUDIO_RESULT_INTERRUPT);
	 }
}
//add end

void vm_sal_set_volume(VMINT volume) 
{	
	vm_log_debug("current_volume = %d, vm_sal_set_volume = %d", current_volume, volume);
	 if (volume < MDI_AUD_VOL_NUM && volume >= 0)
	 {
	 	 current_volume = volume;
		 if (volume == 0)
	        {
	            mdi_audio_set_mute(MDI_VOLUME_MEDIA, TRUE);
	        }
	        else
	        {
	            mdi_audio_set_mute(MDI_VOLUME_MEDIA, FALSE);
	            mdi_audio_set_volume(MDI_VOLUME_MEDIA, (VMUINT8)volume);
	        }
	 }
}

//wei.xia add by 0624
void vm_sal_set_current_volume(VMINT volume)
{
	vm_log_debug("change current volume =  %d", volume);
	current_volume = volume;
}
//add end

void vm_sal_audio_suspend_background_play(void)
{
	/* 挂起 背景播放*/
	if (mdi_audio_is_background_play_suspended() == MMI_FALSE)
	{
		vm_log_debug("suspend background play.");
		mdi_audio_suspend_background_play();
	}
	//wei.xia add by 0329
	if (midi_interrupt_register == FALSE)
	{
		mdi_audio_register_interrupt_callback((mdi_callback)vm_sal_midi_interrupt_callback);
		vm_log_debug("register midi interrupt callback.");
		midi_interrupt_register = TRUE;
	}
	//add end
}

void vm_sal_audio_resume_background_play(void)
{
	/* 恢复被挂起 背景播放*/
	if (mdi_audio_is_background_play_suspended() == MMI_TRUE)
	{
		vm_log_debug("resume background play.");
		mdi_audio_resume_background_play();
	}
	//wei.xia add by 0329
	if (midi_interrupt_register == TRUE)
	{
		mdi_audio_clear_interrupt_callback();
		vm_log_debug("clear midi interrupt callback.");
		midi_interrupt_register = FALSE;
	}
	//add end
}

void vm_sal_vibrator_on(void)
{
	VibratorOn();
}

void vm_sal_vibrator_off(void)
{
	VibratorOff();
}

static void _vm_sal_vibrator_timer(VMINT timeid)
{
	vm_delete_timer(timeid);
	vm_sal_vibrator_off();
	vibrator_flag = FALSE;
}

void vm_sal_vibrator_once(void)
{
	VMINT current_time = vm_get_tick_count();
	if (current_time - g_vibrator_time > ONCE_VIBRATOR_TIME)
	{
		g_vibrator_time = current_time;
	PlayVibratorOnce();
	}
}
void vm_sal_set_key_tone_on(void)
{
	mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);
}

void vm_sal_set_key_tone_off(void)
{
	mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
}

vm_kbd_tone_state_enum vm_sal_get_key_tone_state(void)
{
	vm_kbd_tone_state_enum retval = VM_KEY_TONE_INVALID;
	switch(mmi_frm_kbd_get_key_tone_state())
	{
		case MMI_KEY_TONE_ENABLED:
			retval = VM_KEY_TONE_ENABLED;
			break;
		case MMI_KEY_VOL_TONE_DISABLED:
			retval = VM_KEY_VOL_TONE_DISABLED;
			break;
		case MMI_KEY_VOL_UP_DOWN_TONE_DISABLED:
			retval = VM_KEY_VOL_UP_DOWN_TONE_DISABLED;
			break;
		case MMI_KEY_RIGHT_LEFT_ARROW_TONE_DISABLED:
			retval = VM_KEY_RIGHT_LEFT_ARROW_TONE_DISABLED;
			break;
		case MMI_KEY_TONE_DISABLED:
			retval = VM_KEY_TONE_DISABLED;
			break;
		default :
			retval = VM_KEY_TONE_INVALID;
			break;
	}

	return retval;
}

VMINT vm_sal_set_key_tone_state(vm_kbd_tone_state_enum key_tone_state)
{
	mmi_frm_kbd_tone_state_enum setval = MMI_KEY_TONE_INVALID;
	if (key_tone_state > VM_KEY_TONE_INVALID || key_tone_state < VM_KEY_TONE_ENABLED)
	{
		vm_log_debug(  "vm_set_key_tone_state : ken_tone_state is error");
		return FALSE;
	}

	switch(key_tone_state)
	{
		case VM_KEY_TONE_ENABLED:
			setval = MMI_KEY_TONE_ENABLED;
			break;
		case VM_KEY_VOL_TONE_DISABLED:
			setval = MMI_KEY_VOL_TONE_DISABLED;
			break;
		case VM_KEY_VOL_UP_DOWN_TONE_DISABLED:
			setval = MMI_KEY_VOL_UP_DOWN_TONE_DISABLED;
			break;
		case VM_KEY_RIGHT_LEFT_ARROW_TONE_DISABLED:
			setval = MMI_KEY_RIGHT_LEFT_ARROW_TONE_DISABLED;
			break;
		case VM_KEY_TONE_DISABLED:
			setval = MMI_KEY_TONE_DISABLED;
			break;
		default :
			setval = MMI_KEY_TONE_INVALID;
			break;
	}
	
	mmi_frm_kbd_set_tone_state((mmi_frm_kbd_tone_state_enum)setval);
	return TRUE;
}



void vm_sal_record_callback(VMINT result)
{
	vm_log_debug("entry vm_sal_record_callback, and result = %d", result);

      	if (vre_running == FALSE)return;
	
	if (result == MDI_AUDIO_TERMINATED 
		|| result == MDI_AUDIO_END_OF_FILE
		|| result == MDI_AUDIO_DISC_FULL
		|| result == MDI_AUDIO_NO_SPACE)
	{
		vm_log_debug("will sal_record_cb(%d)", result);
		sal_record_cb(result);
	}
}


VMINT vm_sal_record_start(VMWCHAR *file_name, VMUINT8 format, mdi_callback cb_handler)
{
	VMUINT8 file_format = MDI_FORMAT_WAV_DVI_ADPCM;

	switch(format)
       {
	case VM_FORMAT_AMR:
		file_format = MDI_FORMAT_AMR;
	       break;
	case VM_FORMAT_WAV:
	       file_format = MDI_FORMAT_WAV_DVI_ADPCM;
	       break;
      }

	vm_log_debug("file_format = %d", file_format);
	
	sal_record_cb = cb_handler;
	return mdi_audio_start_record_with_limit(file_name, file_format, 0, NULL, (mdi_callback)vm_sal_record_callback, 0, 0);
}

VMINT vm_sal_record_pause(mdi_callback cb_handler)
{
	sal_record_cb = cb_handler;
	return mdi_audio_pause(0, vm_sal_record_callback);
}

VMINT vm_sal_record_resume(mdi_callback cb_handler)
{
	sal_record_cb = cb_handler;
	return mdi_audio_resume(0, vm_sal_record_callback);
}

VMINT vm_sal_record_stop(void)
{
	return mdi_audio_stop_record();
}


VMINT vm_get_vocal_removal_feature(void)
{
	if (sysconf.multimedia.audio_vocal_removal == MMI_TRUE)
		return TRUE;
	else 
		return FALSE;
/*#ifdef __MMI_AUDIO_VOCAL_REMOVAL__		
	return TRUE;
#else 
	return FALSE;
#endif*/
}

VMINT vm_get_pitch_shifting_feature(void)
{
	if (sysconf.multimedia.audio_pitch_shifting == MMI_TRUE)
		return TRUE;
	else 
		return FALSE;
/*#ifdef __MMI_AUDIO_PITCH_SHIFTING__		
	return TRUE;
#else 
	return FALSE;
#endif	*/	
}

VMINT vm_sal_audio_vocal_removal_turn_on(void)
{
	int result = VM_KURO_FAILED;

	if (vm_get_vocal_removal_feature())
	{
		if (vm_get_pitch_shifting_feature())
			if (vm_kuro_effect_flag >= VM_KURO_PITCH_SHIFTING_N4 && vm_kuro_effect_flag <= VM_KURO_PITCH_SHIFTING_P4) /* pitch shifting on */
				stub_audio_pitch_shifting_turn_off();

		if (vm_kuro_effect_flag != VM_KURO_VOCAL_REMOVAL_ON)
		{
			if ((result = stub_audio_vocal_removal_turn_on()) == MDI_AUDIO_SUCCESS)
			{
				vm_kuro_effect_flag = VM_KURO_VOCAL_REMOVAL_ON;
				vm_log_debug("vocal_removal turn_on.");
			}
		}
		vm_log_debug(  "vm_sal_audio_vocal_removal_turn_on, result = %d", result);
	}
	return result;
}

VMINT vm_sal_audio_vocal_removal_turn_off(void)
{
	int result = VM_KURO_FAILED;

	if (vm_get_vocal_removal_feature())
	{
		if (vm_get_pitch_shifting_feature())
		{
			if (vm_kuro_effect_flag >= VM_KURO_PITCH_SHIFTING_N4 && vm_kuro_effect_flag <=  VM_KURO_PITCH_SHIFTING_P4)
			{
				return  result;
			}
		}	

		if (vm_kuro_effect_flag == VM_KURO_VOCAL_REMOVAL_ON)
		{
			result = stub_audio_vocal_removal_turn_off();
			vm_kuro_effect_flag = VM_KURO_NO_EFFECT;
		}
		vm_log_debug(  "vm_sal_audio_vocal_removal_turn_off, result = %d", result);
	}
	return result;
}

VMINT vm_sal_audio_pitch_shifting_turn_on(void)
{
	int result = VM_KURO_FAILED;

	if (vm_get_pitch_shifting_feature())
	{
		if (vm_get_vocal_removal_feature())
			if (vm_kuro_effect_flag == VM_KURO_VOCAL_REMOVAL_ON)
				stub_audio_vocal_removal_turn_off();
		
		if (vm_kuro_effect_flag >= VM_KURO_PITCH_SHIFTING_N4 && vm_kuro_effect_flag <=  VM_KURO_PITCH_SHIFTING_P4)
		{
			result = VM_KURO_FAILED;
		}
		else
		{
			if ((result = stub_audio_pitch_shifting_turn_on()) == VM_KURO_SUCCEED)
			{
				stub_audio_pitch_shifting_set_level(VM_KURO_PITCH_SHIFTING_0);
				vm_kuro_effect_flag = VM_KURO_PITCH_SHIFTING_0;
			}
		}
		vm_log_debug(  "vm_sal_audio_pitch_shifting_turn_on, result = %d", result);
	}
	return result;
}

VMINT vm_sal_audio_pitch_shifting_turn_off(void)
{
	int result = VM_KURO_FAILED;

	if (vm_get_pitch_shifting_feature())
	{
		if (vm_kuro_effect_flag != VM_KURO_NO_EFFECT)
		{
			if (vm_get_vocal_removal_feature())
				if (vm_kuro_effect_flag == VM_KURO_VOCAL_REMOVAL_ON)
					return result;
		
			if((result = stub_audio_pitch_shifting_turn_off()) == VM_KURO_SUCCEED)
			{
				int temp = stub_audio_pitch_shifting_set_level(VM_KURO_PITCH_SHIFTING_0);
				vm_log_debug("stub_audio_pitch_shifting_set_level = %d", temp);
				vm_kuro_effect_flag = VM_KURO_NO_EFFECT;	
			}
		}
		
		vm_log_debug(  "vm_sal_audio_pitch_shifting_turn_off, result = %d", result);
	}
	return result;
}

VMINT vm_sal_audio_pitch_shifting_set_level(VMINT16 level)
{
	int result = VM_KURO_FAILED;

	if (level < VM_KURO_PITCH_SHIFTING_N4)level = VM_KURO_PITCH_SHIFTING_N4;
	if (level > VM_KURO_PITCH_SHIFTING_P4)level = VM_KURO_PITCH_SHIFTING_P4;

	if (vm_get_pitch_shifting_feature())
	{	
		if (VM_KURO_NO_EFFECT == vm_kuro_effect_flag)
			return result;
		
		if (vm_get_vocal_removal_feature())
			if (VM_KURO_VOCAL_REMOVAL_ON == vm_kuro_effect_flag)
				stub_audio_vocal_removal_turn_off();

		if (!(vm_kuro_effect_flag >= VM_KURO_PITCH_SHIFTING_N4 && vm_kuro_effect_flag <=  VM_KURO_PITCH_SHIFTING_P4))
		{
			stub_audio_pitch_shifting_turn_on();
			vm_kuro_effect_flag = VM_KURO_PITCH_SHIFTING_0;
		}
		
		result = stub_audio_pitch_shifting_set_level(level);
		if (MDI_AUDIO_SUCCESS == result)
			vm_kuro_effect_flag = level;

		vm_log_debug(  "vm_sal_audio_pitch_shifting_set_level, result = %d, level = %d", result, level);
	}
	return result;
}

void vm_sal_kuro_effect_off(void)
{
	vm_log_debug(  "entry vm_sal_kuro_effect_off, vm_kuro_effect_flag = %d.", vm_kuro_effect_flag);

	if (vm_get_pitch_shifting_feature())
	{
		if (vm_kuro_effect_flag >= VM_KURO_PITCH_SHIFTING_N4 && vm_kuro_effect_flag <=  VM_KURO_PITCH_SHIFTING_P4)
		{
			stub_audio_pitch_shifting_set_level(VM_KURO_PITCH_SHIFTING_0);
			stub_audio_pitch_shifting_turn_off();
		}
	}

	if (vm_get_vocal_removal_feature())
		if (VM_KURO_VOCAL_REMOVAL_ON == vm_kuro_effect_flag)
			stub_audio_vocal_removal_turn_off();

	vm_log_debug(  "exit vm_sal_kuro_effect_off, vm_kuro_effect_flag = %d.", vm_kuro_effect_flag);
}

void vm_sal_kuro_effect_resume(void)
{
	vm_log_debug("entry vm_sal_kuro_effect_resume, and vm_kuro_effect_flag = %d", vm_kuro_effect_flag);
	if (VM_KURO_NO_EFFECT == vm_kuro_effect_flag)
		return;

	if (vm_get_pitch_shifting_feature())
		if (vm_kuro_effect_flag >= VM_KURO_PITCH_SHIFTING_N4 && vm_kuro_effect_flag <=  VM_KURO_PITCH_SHIFTING_P4)
			if (stub_audio_pitch_shifting_set_level(vm_kuro_effect_flag) == MDI_AUDIO_SUCCESS)
				stub_audio_pitch_shifting_turn_on();

	if (vm_get_vocal_removal_feature())
		if (VM_KURO_VOCAL_REMOVAL_ON == vm_kuro_effect_flag)
			stub_audio_pitch_shifting_turn_on();

	vm_log_debug(  "exit vm_sal_kuro_effect_resume, and vm_kuro_effect_flag = %d", vm_kuro_effect_flag);
}

VMUINT8* vm_sal_midi_get_resource(VMINT resid,VMINT *len)
{
	return NULL;
}


VMINT vm_sal_query_calling(void)
{
#if defined(__VRE_RB_09A__)
	int callcount = 0;
	callcount = mmi_ucm_app_incoming_call(MMI_UCM_CALL_TYPE_ALL) + 
	                 mmi_ucm_app_outgoing_call(MMI_UCM_CALL_TYPE_ALL) + 
	                 mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_NO_CSD) ;

	//wei.xia add by 0623
	#if defined(__MMI_VIDEO_RECORDER__) && !defined(__MMI_CAMCORDER__)
	if (mmi_vdorec_is_in_app())
		callcount = 1;
	#endif
	#ifdef __MMI_VIDEO_PLAYER__
	if (mmi_vdoply_is_in_app())
		callcount = 1;
	#endif
	//add end
	
	//当前有电话操作
	if (callcount > 0)
#else
	if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0
	#if defined(__MMI_VIDEO_RECORDER__) && !defined(__MMI_CAMCORDER__)
	|| mmi_vdorec_is_in_app()
	#endif
	#ifdef __MMI_VIDEO_PLAYER__
	|| mmi_vdoply_is_in_app()
	#endif	
	)
#endif
		return TRUE;
	else
		return FALSE;
}

void reset_default_volume(void)
{
//wei.xia modify by 0624
/*#if defined(__MMI_AUDIO_PLAYER__)
	extern audply_struct g_audply;
	if (g_audply.volume == 0)
		vm_sal_set_volume(DEFAULT_VOLUME);
	else
		vm_sal_set_volume(g_audply.volume);
#else
	if (current_volume == 0)
	{
		vm_log_debug("reset_default_volume.");
		current_volume = DEFAULT_VOLUME;
		vm_sal_set_volume(current_volume);
	}
#endif*/
	if (current_volume == 0)
	{
		vm_log_debug("reset_default_volume.");
		current_volume = DEFAULT_VOLUME;
	}
//modify end
}

#endif /* __VRE__ */
