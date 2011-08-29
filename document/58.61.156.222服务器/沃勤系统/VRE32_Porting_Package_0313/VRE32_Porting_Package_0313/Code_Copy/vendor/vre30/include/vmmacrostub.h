#ifndef VMMACROSTUB_H_
#define VMMACROSTUB_H_

#include "mmi_include.h"
#include "DevConfigGprot.h"
#include "kal_non_specific_general_types.h"
#include "stack_config.h"
#include "kal_trace.h"
#include "SST_secure.h"
#include "MMI_features.h"

#include "vmsys.h"

#include "vmsalvideo.h"
#include "vmsalbitstream.h"


#ifdef __cplusplus
extern "C" {
#endif

/**
 * 系统配置用于Compile Option
 */
extern mmi_devconfig_system_config_struct sysconf;

/**
 * tcp支持wifi返回TRUE，否则返回FALSE。
 */
VMINT stub_tcp_is_support_wifi(void);

/**
 * 是否在存储模式。
 */
VMINT stub_mmi_usb_is_in_mass_storage_mode(void);

/**
 * 得到电量。
 */
VMINT stub_vm_get_battery_level(void);


/* BitStream Audio */
VMINT stub_bitstream_audio_open(VMINT* handle, vm_bitstream_audio_cfg_struct *audio_type, vm_bitstream_audio_result_callback callback);
VMINT stub_bitstream_audio_close(VMINT handle);
VMINT stub_bitstream_audio_get_buffer_status(	VMINT handle, vm_bitstream_audio_buffer_status *status);	
VMINT stub_bitstream_audio_put_data(
	VMINT 		handle,
	VMUINT8*	buffer,
	VMUINT 		buffer_size,
	VMUINT* 	written);
VMINT stub_bitstream_audio_put_frame(
	VMINT 		handle,
	VMUINT8*	buffer,
	VMUINT		buffer_size,
	VMUINT 		timestamp);
VMINT stub_bitstream_audio_start(VMINT handle, 	vm_bitstream_audio_start_param  *para);
VMINT stub_bitstream_audio_stop(VMINT handle);
VMINT stub_bitstream_audio_get_play_time(VMINT handle, VMUINT* current_time);

/* Kuro */
VMINT stub_audio_vocal_removal_turn_on(void);
VMINT stub_audio_vocal_removal_turn_off(void);
VMINT stub_audio_pitch_shifting_turn_on(void);
VMINT stub_audio_pitch_shifting_turn_off(void);
VMINT stub_audio_pitch_shifting_set_level(VMINT16 level);
VMINT stub_encrypt_kak(VMINT8* pKakDat, VMINT nLength, VMINT8 bEncrypt);
VMINT stub_RegisterAlbumKey(VMINT nAlbumKey, VMINT bTemp, VMINT wValidPeriod);
VMINT stub_UnRegisterAlbumKey(VMINT nAlbumKey);
VMINT stub_GetAlbumKeyStatus(VMINT nAlbumKey);
/*
 * GPS Mod Function From vmsalgps.c start
 */
VMINT vm_sal_stub_gps_uart_open(VMUINT16 port);
void vm_sal_stub_gps_uart_close(VMUINT16 port);
VMINT vm_sal_gps_is_parser_enabled(void);
void vm_sal_gps_enable_parser(void);
void vm_sal_gps_disable_parser(void);
VMINT16 vm_sal_gps_get_port(void);
void vm_sal_gps_set_work_port(VMUINT8 port);
/*
 * GPS Mod Function From vmsalgps.c end
 */

/*
 * MMS Mod Function From vmsalmms.c start
 */
#include "vmmms.h"
VMINT vm_sal_mms_create_req(vm_send_mms_req_t * req);
void vm_sal_stub_mms_cancel_send_mms(void);
/*
 * MMS Mod Function From vmsalmms.c end
 */

/*
 * CELL Mod Function From vmsalcell.c start
 */
VMINT vm_sal_stub_cell_reg_req(void);
VMINT vm_sal_stub_cell_dereg_req(void);
/*
 * CELL Mod Function From vmsalcell.c end
 */


/* bitstream h264 start*/
/*
VMINT stub_bitstream_video_open(
        VMINT* handle,
        vm_bitstream_video_h264_cfg* cfg,
        vm_bitstream_video_result_callback callback);

VMINT stub_bitstream_video_close(VMINT handle);    

VMINT stub_bitstream_video_get_buffer_status(VMINT handle, vm_bitstream_video_buffer_status* status);

VMINT stub_bitstream_video_put_frame(VMINT handle, VMUSTR buffer, VMUINT buffer_size, VMUINT timestamp);

VMINT stub_bitstream_video_start(VMINT handle, vm_bitstream_video_start_param* para);

VMINT stub_bitstream_video_stop(VMINT handle);

VMINT stub_bitstream_video_get_play_time(VMINT handle, VMUINT* ms_current_time);

VMINT stub_bitstream_video_switchscreenstop(VMINT handle);

VMINT stub_bitstream_video_switchscreenstart(VMINT handle, vm_bitstream_video_start_param* p_para);
*/
/* video start*/
/*
VMINT stub_video_open_file( const VMWSTR filename, vm_video_open_result_callback open_result_callback);

VMINT stub_video_close_file(void);

VMINT stub_video_open_buffer( const VMUSTR buffer,  const VMUINT buffer_len, vm_video_info_struct *info);

VMINT stub_video_close_buffer(void);

VMINT stub_video_play(
                    VMUINT player_layer_handle,
                    VMUINT base_layer_handle,
                    VMUINT16 repeat_count, 
                    VMINT is_visual_update,
                    VMINT is_play_audio,
                    VMINT audio_path, 
                    VMUINT16 rotate, 
                    VMUINT16 play_speed,
                    vm_video_finish_callback play_finish_callback);

VMINT stub_video_stop(void);

VMINT stub_video_seek_and_getframe(VMUINT64 time, VMUINT player_layer_handle);

VMINT stub_video_snapshot(VMUINT player_layer_handle, VMWSTR file_name);

VMINT stub_video_set_brightness(VMUINT16 brightness);

VMINT stub_video_set_contrast(VMUINT16 contrast);

VMINT stub_video_get_cur_play_time(VMUINT64 *cur_play_time); 
*/

#if !defined(__VRE_RB_09A__)
#include "PhbSrvGprot.h"
#include "vmcontact.h"

void  vm_phb_build_contact_ptr(vm_phb_contact_struct* contact, srv_phb_sdk_contact_struct * contact_ptr);
void  vm_phb_build_contact(srv_phb_sdk_contact_struct * contact ,  vm_phb_contact_struct* contact_ptr);
#endif

#ifdef __cplusplus
}
#endif

#endif