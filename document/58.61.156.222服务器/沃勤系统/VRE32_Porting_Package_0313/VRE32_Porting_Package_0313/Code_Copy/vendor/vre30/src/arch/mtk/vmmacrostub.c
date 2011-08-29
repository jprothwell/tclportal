#ifdef __VRE__
#include "mmi_include.h"
#include "FileMgrGProt.h"
#include "DataAccountGProt.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "gpioInc.h"
#include "SimDetectionGexdcl.h"
#include "DevConfigGprot.h"

#if (!defined(__VRE_RB_08A__) && !defined(__VRE_RB_08B__))
#include "mdi_bitstream.h"
#endif

#include "mdi_audio.h"
#include "Browser_api.h"

#include "custom_data_account.h"
#include "soc_api.h"
#include "DataAccountDef.h"
#include "SimDetectionGprot.h"
#include "DataAccountGProt.h"

#include "ABM_SOC_ENUMS.H"
#include "abm_api.h"
#include "cbm_api.h"
#include "mdi_video.h"
#include "MMI_features.h"
#include "MMI_features_video.h"
#include "ProfileGprots.h"
#include "ProfileMgrGProt.h"

#include "vmsys.h"
#include "vmmacrostub.h"

#include "vmstdlib.h"
#include "vmlog.h"
#include "vmchset.h"
#include "vmpromng.h"
#include "vmresmng.h"
#include "vmopt.h"

#define CHIPID_LENGTH		16


/*
 * GRAPHIC MOD FUNCTION From vmgraph.c
 */
VMINT  vm_graphic_sal_flatten_layer(gdi_handle handle1,gdi_handle handle2,gdi_handle handle3,gdi_handle handle4,gdi_handle handle5,gdi_handle handle6)
{
	
	return gdi_layer_flatten_ext(handle1,handle2,handle3,handle4
#ifdef GDI_6_LAYERS
		,handle5,handle6
#endif
	);
}

VMINT vm_graphic_sal_flush_layer(gdi_handle handle1,gdi_handle handle2,gdi_handle handle3,gdi_handle handle4,gdi_handle handle5,gdi_handle handle6,VMINT w,VMINT h)
{
	return gdi_layer_blt_ext(handle1,handle2, handle3, handle4, 
#ifdef GDI_6_LAYERS					
				handle5,handle6,
#endif
		0,0,w,h);
                               

}

/*
 * GRAPHIC MOD FUNCTION END
 */


/**
 * SOC MOD FUNCTION
 */
VMINT stub_tcp_is_support_wifi(void)
{
#ifdef __MMI_WLAN_FEATURES__
	return TRUE;
#else
	return FALSE;
#endif
}

/* add by zaiping.chen, 2010.07.23, begin */
#ifdef __MMI_WLAN_FEATURES__
extern VMINT wifi_connectted_flag;
static VMINT wifi_notify_register_flag = 0;

static void vm_wlan_event_notify_cb(VMUINT16 event)
{
	if (DTCNT_BEARER_STATE_CONNECTED == event)
	{
		wifi_connectted_flag = TRUE;
	}
	else
	{
		wifi_connectted_flag = FALSE;
	}
}
#endif

void vm_wlan_event_notify_set(void)
{
#ifdef __MMI_WLAN_FEATURES__
	if (0 == wifi_notify_register_flag)
	{
		wifi_notify_register_flag = 1;
		mmi_wlan_add_event_notify_hdlr(vm_wlan_event_notify_cb);
	}
#endif
}
/* add by zaiping.chen, 2010.07.23, end */

/**
 * SOC MOD FUNCTION END
 */
 
#if defined(__USB_IN_NORMAL_MODE__)
extern kal_bool mmi_usb_is_in_mass_storage_mode(void);
#endif
VMINT stub_mmi_usb_is_in_mass_storage_mode(void)
{
#ifdef __USB_IN_NORMAL_MODE__
	return mmi_usb_is_in_mass_storage_mode();
#else
	return FALSE;
#endif
}

extern U8 mmi_gpio_get_current_battery_level(void);
VMINT stub_vm_get_battery_level(void)
{
if((mmi_gpio_get_current_battery_level()-BATTERY_LEVEL_0) < 0)
	{
		return 0;
		}
#ifdef BAT_4_LEVEL_
	return (mmi_gpio_get_current_battery_level()  - BATTERY_LEVEL_0) * 25;
#else
	if ((mmi_gpio_get_current_battery_level()  - BATTERY_LEVEL_0) * 33 == 99)
		return 100;
	else
		return (mmi_gpio_get_current_battery_level()  - BATTERY_LEVEL_0) * 33;
#endif
}

/**
 * TOUCH PAD FUNCTION MOD
 */
#ifndef __MMI_TOUCH_SCREEN__
void mmi_pen_reset(void)
{
	return;
}
void mmi_pen_register_down_handler(mmi_pen_hdlr pen_fp)
{
	return;
}
void mmi_pen_register_up_handler(mmi_pen_hdlr pen_fp)
{
	return;
}
void mmi_pen_register_move_handler(mmi_pen_hdlr pen_fp)
{
	return;
}
void mmi_pen_register_long_tap_handler(mmi_pen_hdlr pen_fp)
{
	return;
}
void mmi_pen_register_double_click_handler(mmi_pen_hdlr pen_fp)
{
	return;
}
void mmi_pen_register_repeat_handler(mmi_pen_hdlr pen_fp)
{
	return;
}
#endif
/**
 * TOUCH PAD FUNCTION MOD END
 */


/*
 * BITSTREAM AUDIO MOD FUNCTION START (vmsalbitstream.c)
 */
VMINT stub_bitstream_audio_open(VMINT* handle, vm_bitstream_audio_cfg_struct *audio_type, vm_bitstream_audio_result_callback callback)
{
#if defined(__BITSTREAM_API_SUPPORT__)
	mdi_bitstream_audio_cfg_struct cfg;
	cfg.codec_type = audio_type->vm_codec_type;
	return mdi_bitstream_audio_open_handle(handle, &cfg, callback);
#else
	return VM_BITSTREAM_FAILED;
#endif
}

VMINT stub_bitstream_audio_close(VMINT handle)
{
#if defined(__BITSTREAM_API_SUPPORT__)
	return mdi_bitstream_audio_close(handle);
#else
	return VM_BITSTREAM_FAILED;
#endif
}

VMINT stub_bitstream_audio_get_buffer_status(	VMINT handle, vm_bitstream_audio_buffer_status *status)
{
#if defined(__BITSTREAM_API_SUPPORT__)
	return mdi_bitstream_audio_get_buffer_status( handle, (mdi_bitstream_audio_buffer_status *)status);
#else
	return VM_BITSTREAM_FAILED;
#endif
}

VMINT stub_bitstream_audio_put_data(
	VMINT 		handle,
	VMUINT8*	buffer,
	VMUINT 		buffer_size,
	VMUINT* 	written)
{
#if defined(__BITSTREAM_API_SUPPORT__)
	return mdi_bitstream_audio_put_data(handle, buffer, buffer_size, written);
#else
	return VM_BITSTREAM_FAILED;
#endif
}

VMINT stub_bitstream_audio_put_frame(
	VMINT 		handle,
	VMUINT8*	buffer,
	VMUINT		buffer_size,
	VMUINT 		timestamp)
{
#if defined(__BITSTREAM_API_SUPPORT__)
	return mdi_bitstream_audio_put_frame(handle, buffer, buffer_size, timestamp);
#else
	return VM_BITSTREAM_FAILED;
#endif
}

VMINT stub_bitstream_audio_start(VMINT handle, 	vm_bitstream_audio_start_param  *para)
{
#if defined(__BITSTREAM_API_SUPPORT__)
	return mdi_bitstream_audio_start(handle, (mdi_bitstream_audio_start_param*)para);
#else
	return VM_BITSTREAM_FAILED;
#endif
}

VMINT stub_bitstream_audio_stop(VMINT handle)
{
#if defined(__BITSTREAM_API_SUPPORT__)
	return mdi_bitstream_audio_stop(handle);
#else
	return VM_BITSTREAM_FAILED;
#endif
}

VMINT stub_bitstream_audio_get_play_time(VMINT handle, VMUINT* current_time)
{
#if defined(__BITSTREAM_API_SUPPORT__)
	return mdi_bitstream_audio_get_play_time(handle, current_time);
#else
	return VM_BITSTREAM_FAILED;
#endif
}
/*
 * BITSTREAM AUDIO MOD FUNCTION END
 */


/*
 * Kuro Audio effect FUNCTION START (vmsalmm.c)
 */
VMINT stub_audio_vocal_removal_turn_on(void)
{
#if defined(__MMI_AUDIO_VOCAL_REMOVAL__)
	return mdi_audio_vocal_removal_turn_on();
#else
	return VM_KURO_FAILED;
#endif
}

VMINT stub_audio_vocal_removal_turn_off(void)
{
#if defined(__MMI_AUDIO_VOCAL_REMOVAL__)
	return mdi_audio_vocal_removal_turn_off();
#else
	return VM_KURO_FAILED;
#endif
}

VMINT stub_audio_pitch_shifting_turn_on(void)
{
#if defined(__MMI_AUDIO_PITCH_SHIFTING__)
	return mdi_audio_pitch_shifting_turn_on();
#else
	return VM_KURO_FAILED;
#endif
}

VMINT stub_audio_pitch_shifting_turn_off(void)
{
#if defined(__MMI_AUDIO_PITCH_SHIFTING__)
	return mdi_audio_pitch_shifting_turn_off();
#else
	return VM_KURO_FAILED;
#endif
}

VMINT stub_audio_pitch_shifting_set_level(VMINT16 level)
{
#if defined(__MMI_AUDIO_PITCH_SHIFTING__)
	return mdi_audio_pitch_shifting_set_level(level);
#else
	return VM_KURO_FAILED;
#endif
}

extern int KURO_encrypt_kak(char* pKakDat, int nLength, int bEncrypt, char* pChipId);
extern int KURO_RegisterAlbumKey(int nAlbumKey, int bTemp, int wValidPeriod);
extern int KURO_UnRegisterAlbumKey(int nAlbumKey);
extern int KURO_GetAlbumKeyStatus(int nAlbumKey);

VMINT stub_encrypt_kak(VMINT8* pKakDat, VMINT nLength, VMINT8 bEncrypt)
{
#if (defined __MMI_AUDIO_VOCAL_REMOVAL__  ) || (defined __MMI_AUDIO_PITCH_SHIFTING__)
	 char chipid[CHIPID_LENGTH];
	 int nResult;

	/* 获取chipID */
	SST_Get_ChipUID(chipid, CHIPID_LENGTH * 8);

	nResult = KURO_encrypt_kak(pKakDat, nLength, bEncrypt, chipid);

	if (nResult == 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
#else
	return FALSE;
#endif
}


VMINT stub_RegisterAlbumKey(VMINT nAlbumKey, VMINT bTemp, VMINT wValidPeriod)
{
#if (defined __MMI_AUDIO_VOCAL_REMOVAL__  ) || (defined __MMI_AUDIO_PITCH_SHIFTING__)
	return KURO_RegisterAlbumKey(nAlbumKey, bTemp, wValidPeriod);
#else
	return NULL;
#endif
}

VMINT stub_UnRegisterAlbumKey(VMINT nAlbumKey)
{
#if (defined __MMI_AUDIO_VOCAL_REMOVAL__  ) || (defined __MMI_AUDIO_PITCH_SHIFTING__)
	return KURO_UnRegisterAlbumKey(nAlbumKey);
#else
	return NULL;
#endif
}

VMINT stub_GetAlbumKeyStatus(VMINT nAlbumKey)
{
#if (defined __MMI_AUDIO_VOCAL_REMOVAL__  ) || (defined __MMI_AUDIO_PITCH_SHIFTING__)
	return KURO_GetAlbumKeyStatus(nAlbumKey);
#else
	return NULL;
#endif
}
#if defined(__VRE_RB_09A__)
extern S16 SetFileAsActivateRingToneID(S8 *pathfileName, U16 *p_ringtoneid);
#endif

VMINT vm_sal_set_ringtone(VMWSTR filepath) 
{
	U16 position;
	VMCHAR fn[255];

	vm_ucs2_to_gb2312(fn, 255, filepath);
	vm_log_debug(  "Setup ringtone: %s.", fn);

#ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
	if (SetFileAsActivateRingToneID((S8*)filepath, &position) == PMG_ADDFILE_ERR_SUCCESS)
	{
		vm_log_debug(  "Setup ringtone success, and position = %d.", position);
		return position;
	}
	else
	{
		vm_log_debug(  "Setup ringtone failed.");
		return VM_KURO_FAILED;
	}
#else
	vm_log_error("This version can't suppurt this API.");
	return VM_KURO_FAILED;
#endif
}


/*
 * Kuro Audio effect FUNCTION END
 */

#if defined(__VRE_RB_08A__) || defined(__VRE_RB_08B__) /*Version control*/
/* XML MOD FUNCTION for vmxml.c */
#ifndef __XML_SUPPORT__
void va_xml_register_doctype_handler(
                VA_XML_PARSER_STRUCT *parser,
                VA_XML_start_doctype_hdlr start_hdlr,
                VA_XML_end_doctype_hdlr end_hdlr)
{
	return;
}

void va_xml_register_element_handler(
                VA_XML_PARSER_STRUCT *parser,
                VA_XML_start_elem_hdlr start_hdlr,
                VA_XML_end_elem_hdlr end_hdlr)
{
	return;
}

void va_xml_register_data_handler(VA_XML_PARSER_STRUCT *parser, VA_XML_data_hdlr data_hdlr)
{
	return;
}

VMINT va_xml_parse(VA_XML_PARSER_STRUCT *parser, kal_wchar *file_name)
{
	return -1;
}

VMINT va_xml_parse_buffer(
                    VA_XML_PARSER_STRUCT *parser,
                    const kal_char *xmltext,
                    kal_int32 length)
{
	return -1;
}

void va_xml_close_parser(VA_XML_PARSER_STRUCT *parser)
{
	return;
}
#endif	/*__XML_SUPPORT__*/
/* XML MOD FUNCTION for vmxml.c */

#else /*Version control*/
/* XML MOD FUNCTION for vmxml.c */
#ifndef __XML_SUPPORT__
void xml_register_doctype_handler(
                XML_PARSER_STRUCT *parser,
                XML_start_doctype_hdlr start_hdlr,
                XML_end_doctype_hdlr end_hdlr)
{
	return;
}

void xml_register_element_handler(
                XML_PARSER_STRUCT *parser,
                XML_start_elem_hdlr start_hdlr,
                XML_end_elem_hdlr end_hdlr)
{
	return;
}

void xml_register_data_handler(XML_PARSER_STRUCT *parser, XML_data_hdlr data_hdlr)
{
	return;
}

VMINT xml_parse(XML_PARSER_STRUCT *parser, kal_wchar *file_name)
{
	return -1;
}

VMINT xml_parse_buffer(
                    XML_PARSER_STRUCT *parser,
                    const kal_char *xmltext,
                    kal_int32 length)
{
	return -1;
}

void xml_close_parser(XML_PARSER_STRUCT *parser)
{
	return;
}
#endif	/*__XML_SUPPORT__*/
/* XML MOD FUNCTION for vmxml.c */

#endif /*Version control*/

/*
 * GPS Mod Function From vmsalgps.c start
 */
#ifdef __GPS_SUPPORT__
#include "mdi_datatype.h"
#include "Mdi_gps.h"
#endif
#include "vmsalgps.h"

extern vm_gps_info_struct *s_vm_sal_gps_info;
extern VMINT vre_running;

#ifdef __GPS_SUPPORT__
static void vm_sal_gps_nmea_callback(mdi_gps_parser_info_enum type, void *buffer, U32 length);
static void vm_sal_gps_nmea_gga_callback(mdi_gps_nmea_gga_struct *param);
static void vm_sal_gps_nmea_rmc_callback(mdi_gps_nmea_rmc_struct *param);
static void vm_sal_gps_nmea_vtg_callback(mdi_gps_nmea_vtg_struct *param);
static void vm_sal_gps_nmea_gsa_callback(mdi_gps_nmea_gsa_struct *param);
static void vm_sal_gps_nmea_gsv_callback(mdi_gps_nmea_gsv_struct *param);
static void vm_sal_gps_nmea_gll_callback(mdi_gps_nmea_gll_struct *param);
#endif

VMINT vm_sal_stub_gps_uart_open(VMUINT16 port)
{
	#ifdef __GPS_SUPPORT__
		return mdi_gps_uart_open(port,MDI_GPS_UART_MODE_LOCATION,vm_sal_gps_nmea_callback);
	#else
		return VM_SAL_GPS_NO_GPS;
	#endif
}

void vm_sal_stub_gps_uart_close(VMUINT16 port)
{
	#ifdef __GPS_SUPPORT__
		mdi_gps_uart_close(port,MDI_GPS_UART_MODE_LOCATION,vm_sal_gps_nmea_callback);
	#endif
}

VMINT vm_sal_gps_is_parser_enabled(void)
{
	#ifdef __GPS_SUPPORT__
		return mdi_gps_is_parser_enabled();
	#else
		return VM_SAL_GPS_NO_GPS;
	#endif
}

void vm_sal_gps_enable_parser(void)
{
	#ifdef __GPS_SUPPORT__
		mdi_gps_enable_parser();
	#endif
}

void vm_sal_gps_disable_parser(void)
{
	#ifdef __GPS_SUPPORT__
		mdi_gps_disable_parser();
	#endif
}

VMINT16 vm_sal_gps_get_port(void)
{
	#ifdef __GPS_SUPPORT__
		return mdi_get_gps_port();
	#else
		return VM_SAL_GPS_NO_GPS;
	#endif
}

void vm_sal_gps_set_work_port(VMUINT8 port)
{
	#ifdef __GPS_SUPPORT__
		mdi_gps_set_work_port(port);
	#endif
}

#ifdef __GPS_SUPPORT__
static void vm_sal_gps_nmea_callback(mdi_gps_parser_info_enum type, void *buffer, U32 length)
{
	if (vre_running == FALSE)
	{
     		return;
  	}
	if(buffer)
	{
		switch(type)
		{
			case MDI_GPS_PARSER_NMEA_GGA:
				vm_sal_gps_nmea_gga_callback((mdi_gps_nmea_gga_struct *)buffer);
				break;
			case MDI_GPS_PARSER_NMEA_RMC:
				vm_sal_gps_nmea_rmc_callback((mdi_gps_nmea_rmc_struct *)buffer);
				break;
			case MDI_GPS_PARSER_NMEA_GSA:
				vm_sal_gps_nmea_gsa_callback((mdi_gps_nmea_gsa_struct *)buffer);
				break;
			case MDI_GPS_PARSER_NMEA_GSV:
				vm_sal_gps_nmea_gsv_callback((mdi_gps_nmea_gsv_struct *)buffer);
				break;    
			case MDI_GPS_PARSER_NMEA_VTG:
				vm_sal_gps_nmea_vtg_callback((mdi_gps_nmea_vtg_struct *)buffer);
				break;        
			case MDI_GPS_PARSER_NMEA_GLL:
				vm_sal_gps_nmea_gll_callback((mdi_gps_nmea_gll_struct *)buffer);
				break;                                   
		}
	}
}

static void vm_sal_gps_nmea_gga_callback(mdi_gps_nmea_gga_struct *param)
{
	if(param)
	{
		//memcpy(&(s_vm_sal_gps_info->gga_data), ((mdi_gps_nmea_gga_struct*)param),sizeof(mdi_gps_nmea_gga_struct));
		s_vm_sal_gps_info->gga_data.gga_latitude = param->latitude;
		s_vm_sal_gps_info->gga_data.gga_longitude = param->longitude;
		s_vm_sal_gps_info->gga_data.gga_h_precision = param->h_precision;
		s_vm_sal_gps_info->gga_data.gga_altitude = param->altitude;
		s_vm_sal_gps_info->gga_data.gga_unit_of_altitude = param->unit_of_altitude;
		s_vm_sal_gps_info->gga_data.gga_geoidal = param->geoidal;
		s_vm_sal_gps_info->gga_data.gga_unit_of_geoidal = param->unit_of_geoidal;
		s_vm_sal_gps_info->gga_data.gga_gps_age = param->gps_age;
		s_vm_sal_gps_info->gga_data.gga_station_id = param->station_id;
		s_vm_sal_gps_info->gga_data.gga_sat_in_view = param->sat_in_view;
		memcpy(&(s_vm_sal_gps_info->gga_data.gga_utc_time), &(param->utc_time),sizeof(mdi_gps_nmea_utc_time_struct));
		s_vm_sal_gps_info->gga_data.gga_north_south = param->north_south;
		s_vm_sal_gps_info->gga_data.gga_east_west = param->east_west;
		s_vm_sal_gps_info->gga_data.gga_quality = param->quality;
	}
}
static void vm_sal_gps_nmea_rmc_callback(mdi_gps_nmea_rmc_struct *param)
{
	if(param)
	{
		//memcpy(&(s_vm_sal_gps_info->rmc_data), ((mdi_gps_nmea_rmc_struct*)param),sizeof(mdi_gps_nmea_rmc_struct));
		s_vm_sal_gps_info->rmc_data.rmc_latitude = param->latitude;
		s_vm_sal_gps_info->rmc_data.rmc_longitude = param->longitude;
		s_vm_sal_gps_info->rmc_data.rmc_ground_speed = param->ground_speed;
		s_vm_sal_gps_info->rmc_data.rmc_trace_degree = param->trace_degree;
		s_vm_sal_gps_info->rmc_data.rmc_magnetic = param->magnetic;
		memcpy(&(s_vm_sal_gps_info->rmc_data.rmc_utc_time), &(param->utc_time),sizeof(mdi_gps_nmea_utc_time_struct));
		memcpy(&(s_vm_sal_gps_info->rmc_data.rmc_utc_date), &(param->utc_date),sizeof(mdi_gps_nmea_utc_date_struct));
		s_vm_sal_gps_info->rmc_data.rmc_status = param->status;
		s_vm_sal_gps_info->rmc_data.rmc_north_south = param->north_south;
		s_vm_sal_gps_info->rmc_data.rmc_east_west = param->east_west;
		s_vm_sal_gps_info->rmc_data.rmc_magnetic_e_w = param->magnetic_e_w;
		s_vm_sal_gps_info->rmc_data.rmc_cmode = param->cmode;
	}
}
static void vm_sal_gps_nmea_vtg_callback(mdi_gps_nmea_vtg_struct *param)
{
	if(param)
	{
		//memcpy(&(s_vm_sal_gps_info->vtg_data), (mdi_gps_nmea_vtg_struct *)param,sizeof(mdi_gps_nmea_vtg_struct));
		s_vm_sal_gps_info->vtg_data.vtg_hspeed_knot = param->hspeed_knot;
		s_vm_sal_gps_info->vtg_data.vtg_hspeed_km = param->hspeed_km;
		s_vm_sal_gps_info->vtg_data.vtg_true_heading = param->true_heading;
		s_vm_sal_gps_info->vtg_data.vtg_mag_heading = param->mag_heading;
		s_vm_sal_gps_info->vtg_data.vtg_mode = param->mode;
	}
}
static void vm_sal_gps_nmea_gsa_callback(mdi_gps_nmea_gsa_struct *param)
{
	VMINT i;
	if(param)
	{
		//memcpy(&(s_vm_sal_gps_info->gsa_data), ((mdi_gps_nmea_gsa_struct *)param),sizeof(mdi_gps_nmea_gsa_struct));
		s_vm_sal_gps_info->gsa_data.gsa_pdop = param->pdop;
		s_vm_sal_gps_info->gsa_data.gsa_hdop = param->hdop;
		s_vm_sal_gps_info->gsa_data.gsa_vdop = param->vdop;
		for(i=0;i<VM_GPS_GSA_SATE_MAX;i++)
		{
			s_vm_sal_gps_info->gsa_data.gsa_sate_id[i] = param->sate_id[i];
		}
		s_vm_sal_gps_info->gsa_data.gsa_op_mode = param->op_mode;
		s_vm_sal_gps_info->gsa_data.gsa_fix_mode = param->fix_mode;
	}
	
}
static void vm_sal_gps_nmea_gsv_callback(mdi_gps_nmea_gsv_struct *param)
{
	VMINT i;
	if(param)
	{
		//memcpy(&(s_vm_sal_gps_info->gsv_data), ((mdi_gps_nmea_gsv_struct *)param),sizeof(mdi_gps_nmea_gsv_struct));
		s_vm_sal_gps_info->gsv_data.gsv_msg_sum = param->msg_sum;
		s_vm_sal_gps_info->gsv_data.gsv_msg_index = param->msg_index;
		s_vm_sal_gps_info->gsv_data.gsv_sates_in_view = param->sates_in_view;
		s_vm_sal_gps_info->gsv_data.gsv_max_snr = param->max_snr;
		s_vm_sal_gps_info->gsv_data.gsv_min_snr = param->min_snr;
		s_vm_sal_gps_info->gsv_data.gsv_num_sv_trk = param->num_sv_trk;
		for(i=0;i<MDI_GPS_NMEA_MAX_SVVIEW;i++)
		{
			s_vm_sal_gps_info->gsv_data.gsv_rsv[i].sate_id = param->rsv[i].sate_id;
			s_vm_sal_gps_info->gsv_data.gsv_rsv[i].elevation = param->rsv[i].elevation;
			s_vm_sal_gps_info->gsv_data.gsv_rsv[i].azimuth = param->rsv[i].azimuth;
			s_vm_sal_gps_info->gsv_data.gsv_rsv[i].snr = param->rsv[i].snr;
		}
	}
	
}
static void vm_sal_gps_nmea_gll_callback(mdi_gps_nmea_gll_struct *param)
{
	if(param)
	{
		//memcpy(&(s_vm_sal_gps_info->gll_data), ((mdi_gps_nmea_gll_struct *)param),sizeof(mdi_gps_nmea_gll_struct));
		s_vm_sal_gps_info->gll_data.gll_latitude = param->latitude;
		s_vm_sal_gps_info->gll_data.gll_longitude = param->longitude;
		memcpy(&(s_vm_sal_gps_info->gll_data.gll_utc_time), &(param->utc_time),sizeof(mdi_gps_nmea_utc_time_struct));
		s_vm_sal_gps_info->gll_data.gll_north_south = param->north_south;
		s_vm_sal_gps_info->gll_data.gll_east_west = param->east_west;
		s_vm_sal_gps_info->gll_data.gll_status = param->status;
		s_vm_sal_gps_info->gll_data.gll_mode = param->mode;
	}
	
}
#endif

/*
 * GPS Mod Function From vmsalgps.c end
 */

/*
 * MMS Mod Function From vmsalmms.c start
 */
#ifdef __MMI_MMS_VENDOR_APP_SUPPORT__
#include "mms_sap_struct.h"
#include "mms_sap.h"
#endif
#include "vmlog.h"
#include "vmstdlib.h"

extern  vm_mms_callback_type  vm_sal_mms_user_callback;
extern VMINT s_vm_sal_mms_sendstate;
extern VMUINT s_vm_sal_sim_id;
extern VMINT s_vm_sal_send_mms_cancel;
extern VMINT s_vm_sal_create_mms_success;
extern VMUINT s_vm_sal_cur_mms_msg_id;

 #ifdef __MMI_MMS_VENDOR_APP_SUPPORT__
static void vm_sal_mms_process_create_res(mmi_mms_vendor_create_rsp_struct * res);
static VMINT vm_sal_mms_send_req(VMUINT8 app_id, VMUINT msg_id);
static void vm_sal_mms_process_send_res(mmi_mms_vendor_send_rsp_struct * res);
static VMINT vm_sal_delete_mms_req(VMUINT msg_id);
static void vm_sal_mms_process_delete_res(mmi_mms_vendor_delete_rsp_struct * res);
#endif


VMINT vm_sal_mms_create_req(vm_send_mms_req_t * req)
{
#ifdef __MMI_MMS_VENDOR_APP_SUPPORT__
	mmi_mms_vendor_create_req_struct *vendor_req;
    	ilm_struct  message;
    	VMUINT8 ref_count;
	
    	vm_log_debug("vm_sal_mms_create_req:start");
    	if(req == NULL)
    	{
       	vm_log_error("vm_sal_mms_create_req:req == NULL");
		return VM_MMS_FAIL;
     	}	
    	vendor_req = (mmi_mms_vendor_create_req_struct*)mmi_construct_msg_local_para(sizeof(mmi_mms_vendor_create_req_struct));
    	if(vendor_req == NULL)
    	{
       	vm_log_error("vm_sal_mms_create_req:vendor_req == NULL");
		return VM_MMS_FAIL;
     	}
   
    	vendor_req->app_id = MMI_MMS_VENDOR_CVM_APP_ID;
    	vendor_req->xml_size= req->xml_size;
    	vm_wstrncpy((VMWSTR)vendor_req->xml_filepath, (VMWSTR)req->xml_filepath, MMS_VENDOR_MAX_INTERNAL_FILENAME_LENGTH);
    	vendor_req->mms_type = req->mms_type;
    	vendor_req->sim_id = req->sim_id;
 
    	SetProtocolEventHandler(vm_sal_mms_process_create_res, MSG_ID_MMI_MMS_VENDOR_CREATE_RSP);	
    
   	message.src_mod_id = MOD_MMI;
    	message.dest_mod_id = MOD_MMI;
    	message.sap_id = 0;
    	message.msg_id = MSG_ID_MMI_MMS_VENDOR_CREATE_REQ;
    	message.local_para_ptr = (local_para_struct *)vendor_req;
    	message.peer_buff_ptr =  NULL;
	
   	ref_count = message.local_para_ptr->ref_count; 
  	vm_log_debug("vm_sal_mms_create_req:ref_count=%d,message.src_mod_id=%d message.dest_mod_id=%d", 
		 message.local_para_ptr->ref_count,message.src_mod_id,message.dest_mod_id);
   
    	mmi_msg_send_ext_queue(&message);
   
   	vm_log_debug("vm_sal_mms_create_req:end!");
    	return VM_MMS_SUCCESS;
#else
	vm_log_error("vm_sal_mms_create_req:mms is not valid");
	return VM_MMS_FAIL;
#endif

}

#ifdef __MMI_MMS_VENDOR_APP_SUPPORT__
static void vm_sal_mms_process_create_res(mmi_mms_vendor_create_rsp_struct * res)
{
	VMINT create_result;

	vm_log_debug("vm_sal_mms_process_create_res:start!");
	vm_log_debug("vm_sal_mms_process_create_res:res->result = %d", res->result);
	
	if(vre_running == FALSE)
	{
		return;
	}
     	switch(res->result )
     	{
       	case MMI_MMS_VENDOR_FAIL:
			create_result = VM_MMS_FAIL;
		   	break;
	 	case MMI_MMS_VENDOR_PASS:
	 	  	create_result = VM_MMS_SUCCESS;  
		   	vm_log_debug("vm_sal_mms_process_create_res: res->app_id=%d, res->msg_id=%d", res->app_id, res->msg_id);
			s_vm_sal_create_mms_success = TRUE;
			s_vm_sal_cur_mms_msg_id = res->msg_id;
			if(s_vm_sal_send_mms_cancel == TRUE)
			{
				create_result = VM_MMS_CANCEL;  
				if(vm_sal_delete_mms_req(res->msg_id) < 0)
                         	{
	                     	vm_log_error("vm_sal_mms_process_create_res:cancel msg fail !");
	                  	}
			}
			else
			{
				if(vm_sal_mms_send_req(res->app_id, res->msg_id) < 0)
		     		{
		     			create_result = VM_MMS_FAIL; 	
			    		if(vm_sal_delete_mms_req(res->msg_id) < 0)
                         		{
	                     		vm_log_error("vm_sal_mms_process_create_res:cancel msg fail !");
	                  		}
		     		}	 
			}
		  	break;
	 	case MMI_MMS_VENDOR_MEMORY_NOT_ENOUGH:
	         	create_result = VM_MMS_MEMORY_NOT_ENOUGH;
		  	break;
	 	default:
		   	create_result = VM_MMS_FAIL;
		   	break;
	}
		
	if(create_result != VM_MMS_SUCCESS)
  	{        
  		if(vm_sal_mms_user_callback != NULL)
		{
			s_vm_sal_create_mms_success = FALSE;
			s_vm_sal_send_mms_cancel = FALSE;
			vm_sal_mms_user_callback(create_result);
		}
	     	s_vm_sal_mms_sendstate = FALSE;
  	}

    	if(res != NULL)
	{
		mmi_free_msg_local_para(res);
	}
   	vm_log_debug("vm_sal_mms_process_create_res:end!");
}

static VMINT vm_sal_mms_send_req(VMUINT8 app_id, VMUINT msg_id)
{
	mmi_mms_vendor_send_req_struct *vendor_req ;
     	ilm_struct  message;
		
    	vm_log_debug("vm_sal_mms_send_req:start!");
    	vendor_req = (mmi_mms_vendor_send_req_struct*)mmi_construct_msg_local_para(sizeof(mmi_mms_vendor_send_req_struct));
    	if(vendor_req == NULL)
    	{
       	vm_log_error("vm_sal_mms_send_req:vendor_req == NULL");
		return VM_MMS_FAIL;
     	}
  
    	vendor_req->app_id = MMI_MMS_VENDOR_CVM_APP_ID;
    	vendor_req->msg_id = msg_id;
    	vendor_req->sim_id = s_vm_sal_sim_id;
    	
    	SetProtocolEventHandler(vm_sal_mms_process_send_res, MSG_ID_MMI_MMS_VENDOR_SEND_RSP);	
 
    	message.src_mod_id =MOD_MMI;
    	message.dest_mod_id = MOD_MMI;
    	message.sap_id = 0;
    	message.msg_id = MSG_ID_MMI_MMS_VENDOR_SEND_REQ;
    	message.local_para_ptr = (local_para_struct *)vendor_req;
    	message.peer_buff_ptr =  NULL;

	vm_log_debug("vm_sal_mms_send_req:ref_count=%d,message.src_mod_id=%d message.dest_mod_id=%d", 
		 message.local_para_ptr->ref_count,message.src_mod_id,message.dest_mod_id);
	
   	mmi_msg_send_ext_queue(&message);
	
   	vm_log_debug("vm_sal_mms_send_req:end!");
    	return VM_MMS_SUCCESS;
}


static void vm_sal_mms_process_send_res(mmi_mms_vendor_send_rsp_struct * res)
{
	VMINT send_result;
     	VMUINT msg_id;

	vm_log_debug("vm_sal_mms_process_send_res:start!");
	vm_log_debug("vm_sal_mms_process_send_res:start res->result=%d", res->result); 
	if(vre_running == FALSE)
	{
		return;
	}
     	switch(res->result )
     	{
     		case MMI_MMS_VENDOR_FAIL:
			send_result = VM_MMS_FAIL;
		   	break;
	 	case MMI_MMS_VENDOR_PASS:
	          	send_result = res->msg_id;
			vm_log_debug("vm_sal_mms_process_send_res: res->msg_id=%d", res->msg_id); 
		   	break;
		case MMI_MMS_VENDOR_USER_CANCEL:
			send_result = VM_MMS_CANCEL;
			vm_log_debug("vm_sal_mms_process_send_res: user cancel send"); 
			break;
	 	case MMI_MMS_VENDOR_MEMORY_NOT_ENOUGH:
	         	send_result = VM_MMS_MEMORY_NOT_ENOUGH;
		   	break;
		default:
		   	send_result = VM_MMS_FAIL;
		   	break;
	} 
	msg_id = res->msg_id;
	if(vm_sal_delete_mms_req(msg_id) < 0)
     	{
     		vm_log_error("vm_sal_mms_process_send_res:vm_sal_delete_mms_req fail !");
     	}
 
     	if(res != NULL)
	{
		mmi_free_msg_local_para(res);
	}
		
    	if(vm_sal_mms_user_callback != NULL)
	{
		s_vm_sal_create_mms_success = FALSE;
		s_vm_sal_send_mms_cancel = FALSE;
		vm_sal_mms_user_callback(send_result);
	}
     	s_vm_sal_mms_sendstate = FALSE;
    	vm_log_debug("vm_sal_mms_process_send_res:end!"); 
}

static VMINT vm_sal_delete_mms_req(VMUINT msg_id)
{
	mmi_mms_vendor_delete_req_struct * vendor_req;
     	ilm_struct  message;
	 
    	vm_log_debug("vm_sal_delete_mms_req:start!"); 
     	vendor_req = (mmi_mms_vendor_delete_req_struct*)mmi_construct_msg_local_para(sizeof(mmi_mms_vendor_delete_req_struct));
     	if(vendor_req == NULL)
     	{
       	vm_log_error("vm_sal_delete_mms_req:vendor_req == NULL");
		return VM_MMS_FAIL;
      	}
	 
     	vendor_req->app_id = MMI_MMS_VENDOR_CVM_APP_ID;
     	vendor_req->msg_id = msg_id;
   
     	SetProtocolEventHandler(vm_sal_mms_process_delete_res, MSG_ID_MMI_MMS_VENDOR_DELETE_RSP);	
	
     	message.src_mod_id = MOD_MMI;
    	message.dest_mod_id = MOD_MMI;
    	message.sap_id = 0;
    	message.msg_id = MSG_ID_MMI_MMS_VENDOR_DELETE_REQ;
    	message.local_para_ptr = (local_para_struct *)vendor_req;
    	message.peer_buff_ptr =  NULL;
	
	vm_log_debug("vm_sal_delete_mms_req:ref_count=%d,message.src_mod_id=%d message.dest_mod_id=%d", 
		 message.local_para_ptr->ref_count,message.src_mod_id,message.dest_mod_id);
	 
     	mmi_msg_send_ext_queue(&message);
	vm_log_debug("vm_sal_delete_mms_req:end!"); 
	return VM_MMS_SUCCESS;

}

static void vm_sal_mms_process_delete_res(mmi_mms_vendor_delete_rsp_struct * res)
{
	VMINT delete_result;

	vm_log_debug("vm_sal_mms_process_delete_res:start!");
	vm_log_debug("vm_sal_mms_process_delete_res:start res->result=%d", res->result); 
	if(vre_running == FALSE)
	{
		return;
	}
     	switch(res->result )
     	{
     		case MMI_MMS_VENDOR_FAIL:
			delete_result = VM_MMS_FAIL;
		   	break;
		case MMI_MMS_VENDOR_PASS:
	         	delete_result = res->msg_id;
			vm_log_debug("vm_sal_mms_process_delete_res:res->msg_id=%d",  res->msg_id); 
		   	break;
	 	case MMI_MMS_VENDOR_MEMORY_NOT_ENOUGH:
	         	delete_result = VM_MMS_MEMORY_NOT_ENOUGH;
		   	break;
		default:
		   	delete_result = VM_MMS_FAIL;
		   	break;
	   
     	}
   	 
     	if(res != NULL)
	{
		mmi_free_msg_local_para(res);
	}
 	vm_log_debug("vm_sal_mms_process_delete_res:end!"); 
}
#endif/*__MMI_MMS_VENDOR_APP_SUPPORT__*/
void vm_sal_stub_mms_cancel_send_mms(void)
{
#ifdef __MMI_MMS_VENDOR_APP_SUPPORT__
	vm_log_debug("vm_sal_stub_mms_cancel_send_mms:start!");
	vm_log_debug("vm_sal_stub_mms_cancel_send_mms:s_vm_sal_mms_sendstate = %d",s_vm_sal_mms_sendstate);
	if (s_vm_sal_mms_sendstate == TRUE)
	{
		s_vm_sal_send_mms_cancel = TRUE;
		vm_log_debug("vm_sal_stub_mms_cancel_send_mms:s_vm_sal_create_mms_success = %d",s_vm_sal_create_mms_success);
		if (s_vm_sal_create_mms_success == TRUE)
		{
			mmi_mms_vendor_cancel_send_req_struct *vendor_req ;
     			ilm_struct  message;

			vm_log_debug("vm_sal_stub_mms_cancel_send_mms:send cancel msg start");
    			vendor_req = (mmi_mms_vendor_cancel_send_req_struct*)mmi_construct_msg_local_para(sizeof(mmi_mms_vendor_cancel_send_req_struct));
    			if(vendor_req == NULL)
    			{
       			vm_log_error("vm_sal_stub_mms_cancel_send_mms:vendor_req == NULL");
     			}
  
    			vendor_req->app_id = MMI_MMS_VENDOR_CVM_APP_ID;
    			vendor_req->msg_id = s_vm_sal_cur_mms_msg_id;
    	
    			SetProtocolEventHandler(vm_sal_mms_process_send_res, MSG_ID_MMI_MMS_VENDOR_SEND_RSP);	
 
    			message.src_mod_id =MOD_MMI;
    			message.dest_mod_id = MOD_MMI;
    			message.sap_id = 0;
    			message.msg_id = MSG_ID_MMI_MMS_VENDOR_CANCEL_SEND_REQ;
    			message.local_para_ptr = (local_para_struct *)vendor_req;
    			message.peer_buff_ptr =  NULL;

			vm_log_debug("vm_sal_stub_mms_cancel_send_mms:ref_count=%d,message.src_mod_id=%d message.dest_mod_id=%d", 
				 message.local_para_ptr->ref_count,message.src_mod_id,message.dest_mod_id);
	
   			mmi_msg_send_ext_queue(&message);
	
   			vm_log_debug("vm_sal_stub_mms_cancel_send_mms:send cancel msg end!");
		}
	}
	vm_log_debug("vm_sal_stub_mms_cancel_send_mms:send cancel msg end!");
#endif
}
/*
 * MMS Mod Function From vmsalmms.c end
 */

/*
 * CELL Mod Function From vmsalcell.c start
 */
 #ifdef __NBR_CELL_INFO__
#include "CommonScreens.h"
#include "conversions.h"
#include "As2l4c_struct.h"
#endif
#include "vmsalcell.h"
#ifdef __NBR_CELL_INFO__
static void vm_sal_cell_reg_rsp(l4c_nbr_cell_info_ind_struct *msg_ptr);
static VMINT vm_sal_stub_cell_send_msg(msg_type msg_id);
#endif
extern vm_cell_info_struct* s_vm_sal_cur_cell_info;
extern vm_cell_info_struct* s_vm_sal_nbr_cell_info[VM_SAL_CELL_NBR_MAX];
extern VMINT s_vm_sal_cell_nbr_num;
VMINT vm_sal_stub_cell_reg_req(void)
{
#ifdef __NBR_CELL_INFO__
	
	SetProtocolEventHandler(vm_sal_cell_reg_rsp, MSG_ID_L4C_NBR_CELL_INFO_REG_CNF);
	SetProtocolEventHandler(vm_sal_cell_reg_rsp, MSG_ID_L4C_NBR_CELL_INFO_IND);

	if (vm_sal_stub_cell_send_msg(MSG_ID_L4C_NBR_CELL_INFO_REG_REQ))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
#endif
	return FALSE;

}
VMINT vm_sal_stub_cell_dereg_req(void)
{
#ifdef __NBR_CELL_INFO__
	
	ClearProtocolEventHandler(MSG_ID_L4C_NBR_CELL_INFO_IND);
	ClearProtocolEventHandler(MSG_ID_L4C_NBR_CELL_INFO_REG_CNF);

	if (vm_sal_stub_cell_send_msg(MSG_ID_L4C_NBR_CELL_INFO_DEREG_REQ))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
#endif
	return FALSE;

}

#ifdef __NBR_CELL_INFO__

static VMINT vm_sal_stub_cell_send_msg(msg_type msg_id)
{
	ilm_struct *ilm_ptr = NULL;
	ilm_ptr = (ilm_struct*)mmi_construct_msg_local_para(sizeof(ilm_struct));
	if(ilm_ptr)
	{
		ilm_ptr->src_mod_id  = MOD_MMI;
		ilm_ptr->dest_mod_id = MOD_L4C;
		ilm_ptr->sap_id = MMI_L4C_SAP;
		ilm_ptr->msg_id = msg_id;
		ilm_ptr->local_para_ptr = (local_para_struct *) NULL;
		ilm_ptr->peer_buff_ptr = (peer_buff_struct *) NULL;
		mmi_msg_send_ext_queue(ilm_ptr);
		return TRUE;
	}
	return FALSE;
}

static void vm_sal_cell_reg_rsp(l4c_nbr_cell_info_ind_struct *msg_ptr)
{
	gas_nbr_cell_info_struct cell_info;
	VMINT i;

	vm_log_debug("vm_sal_cell_reg_rsp");
	if (vre_running == FALSE)
	{
     		return;
  	}
	if(msg_ptr)
	{
		if (KAL_TRUE == msg_ptr->is_nbr_info_valid)
		{
			memcpy((void *)&cell_info, (void *)(&(msg_ptr->ps_nbr_cell_info_union.gas_nbr_cell_info)), sizeof(gas_nbr_cell_info_struct));
		}
		else
		{
			memset((void *)&cell_info, 0, sizeof(gas_nbr_cell_info_struct));    
		}
	
		s_vm_sal_cur_cell_info->arfcn = cell_info.nbr_meas_rslt.nbr_cells[cell_info.serv_info.nbr_meas_rslt_index].arfcn;
		s_vm_sal_cur_cell_info->bsic = cell_info.nbr_meas_rslt.nbr_cells[cell_info.serv_info.nbr_meas_rslt_index].bsic;
		s_vm_sal_cur_cell_info->rxlev = cell_info.nbr_meas_rslt.nbr_cells[cell_info.serv_info.nbr_meas_rslt_index].rxlev;
		s_vm_sal_cur_cell_info->mcc = cell_info.serv_info.gci.mcc;
		s_vm_sal_cur_cell_info->mnc = cell_info.serv_info.gci.mnc;
		s_vm_sal_cur_cell_info->lac = cell_info.serv_info.gci.lac;
		s_vm_sal_cur_cell_info->ci = cell_info.serv_info.gci.ci;
		s_vm_sal_cell_nbr_num = cell_info.nbr_cell_num;
		vm_log_debug("vm_sal_cell_reg_rsp s_vm_sal_cell_nbr_num = %d",s_vm_sal_cell_nbr_num);

		for(i = 0; i < cell_info.nbr_cell_num; i++)
		{
			s_vm_sal_nbr_cell_info[i]->arfcn = cell_info.nbr_meas_rslt.nbr_cells[cell_info.nbr_cell_info[i].nbr_meas_rslt_index].arfcn;
			s_vm_sal_nbr_cell_info[i]->bsic = cell_info.nbr_meas_rslt.nbr_cells[cell_info.nbr_cell_info[i].nbr_meas_rslt_index].bsic;
			s_vm_sal_nbr_cell_info[i]->rxlev = cell_info.nbr_meas_rslt.nbr_cells[cell_info.nbr_cell_info[i].nbr_meas_rslt_index].rxlev;
			s_vm_sal_nbr_cell_info[i]->mcc = cell_info.nbr_cell_info[i].gci.mcc;
			s_vm_sal_nbr_cell_info[i]->mnc = cell_info.nbr_cell_info[i].gci.mnc;
			s_vm_sal_nbr_cell_info[i]->lac = cell_info.nbr_cell_info[i].gci.lac;
			s_vm_sal_nbr_cell_info[i]->ci = cell_info.nbr_cell_info[i].gci.ci;
		}
		mmi_free_msg_local_para(msg_ptr);
	}
}
#endif/*__NBR_CELL_INFO__*/
/*
 * CELL Mod Function From vmsalcell.c end
 */

/* Bitstream h264 && VIDEO BEGIN*/ 

void stub_audio_suspend_background_play(void)
{
	/* 挂起 背景播放*/
	vm_log_debug("stub_audio_suspend_background_play....");
	if (mdi_audio_is_background_play_suspended() == MMI_FALSE)
	{
		vm_log_debug("mdi_audio_suspend_background_play....");
		mdi_audio_suspend_background_play();
	}
}


void stub_audio_resume_background_play(void)
{
	vm_log_warn("stub_audio_resume_background_play...");
	if (mdi_audio_is_background_play_suspended() == MMI_TRUE)
	{
		vm_log_debug("resume background play.");
		mdi_audio_resume_background_play();
	}
}



#if (defined(__MDI_BITSTREAM_VIDEO_SUPPORT__)  || defined(__MMI_VIDEO_PLAY_SUPPORT__)) 
static VMINT stub_get_layer_flag(VMUINT blthanlde,VMUINT playhandle,VMUINT * gdi_play_layer_handle,VMUINT *gdi_base_layer_handle, VMUINT *bltflag,VMUINT *playflag);
#endif
/*
*	Bitstream Video STUB FUNCTION BEGIN
*/
extern VMUINT vm_graphic_get_trans_handle(VMINT handle);
#if defined(__MDI_BITSTREAM_VIDEO_SUPPORT__)
static vm_bitstream_video_result_callback stub_bitstream_video_result_callback;
static void   stub_mdi_bitstream_video_result_callback(MDI_HANDLE handle, MDI_RESULT result);
static VMINT stub_bitstream_start_param_convert(mdi_bitstream_video_start_param* p_mdi_param,vm_bitstream_video_start_param* p_para);
#endif

#if (defined(__MDI_BITSTREAM_VIDEO_SUPPORT__)  || defined(__MMI_VIDEO_PLAY_SUPPORT__)) 
static VMINT stub_get_layer_flag(VMUINT blthanlde,VMUINT playhandle,VMUINT * gdi_play_layer_handle,VMUINT *gdi_base_layer_handle, VMUINT *bltflag,VMUINT *playflag)
{

/*	方式一(调用前需已经set blt layer)*/
	VMUINT i=0;
	VMUINT gdi_handle[4]={0};
	VMUINT flag[4]={GDI_LAYER_ENABLE_LAYER_0,GDI_LAYER_ENABLE_LAYER_1,GDI_LAYER_ENABLE_LAYER_2,GDI_LAYER_ENABLE_LAYER_3};

	if (!gdi_play_layer_handle || !gdi_base_layer_handle || !bltflag || !playflag)
		return FALSE;

	*gdi_play_layer_handle=vm_graphic_get_trans_handle(playhandle);
	*gdi_base_layer_handle=vm_graphic_get_trans_handle(blthanlde);

	if (!(*gdi_play_layer_handle) ||  !(*gdi_base_layer_handle))
		return FALSE;

	gdi_layer_get_blt_layer(&gdi_handle[0],&gdi_handle[1],&gdi_handle[2],&gdi_handle[3]);
	for(i=0;i<4;i++)
	{
		if(gdi_handle[i]==(*gdi_play_layer_handle)) 
		{
			(*bltflag)|=flag[i];
			(*playflag)|=flag[i];
			break;
		}
		if(gdi_handle[i]==(*gdi_base_layer_handle))
			(*bltflag)|=flag[i];
	}
/*使用base 层做底层和播放层方式*/
/*
	if (!gdi_play_layer_handle || !gdi_base_layer_handle || !bltflag || !playflag)
		return FALSE;

	*gdi_play_layer_handle=vm_graphic_get_trans_handle(playhandle);
	*gdi_base_layer_handle=vm_graphic_get_trans_handle(blthanlde);

	if (!(*gdi_play_layer_handle) ||  !(*gdi_base_layer_handle))
		return FALSE;

	if (*gdi_play_layer_handle==*gdi_base_layer_handle)
	{
		////只使用了播放层
		gdi_layer_set_blt_layer(*gdi_play_layer_handle,0,0,0);
		(*bltflag)=GDI_LAYER_ENABLE_LAYER_0;
		(*playflag)=GDI_LAYER_ENABLE_LAYER_0;
	} else
	{
		gdi_layer_set_blt_layer(*gdi_play_layer_handle,*gdi_base_layer_handle,0,0);
		(*bltflag)=GDI_LAYER_ENABLE_LAYER_0|GDI_LAYER_ENABLE_LAYER_1;
		(*playflag)=GDI_LAYER_ENABLE_LAYER_0;
	}
*/

	return TRUE;
}
#endif

#ifdef __MDI_BITSTREAM_VIDEO_SUPPORT__
static void   stub_mdi_bitstream_video_result_callback(MDI_HANDLE handle, MDI_RESULT result)
{

	VMINT ret;
	//vm_log_warn("stub_mdi_bitstream_video_result_callback ,result:%d, stub_bitstream_video_result_callback:%p",result,stub_bitstream_video_result_callback);
	if (stub_bitstream_video_result_callback){
		switch(result)
		{
			case MDI_RES_BITSTREAM_BUFFER_OVERFLOW:
				ret=VM_BITSTREAM_BUFFER_OVERFLOW;
				break;
			case MDI_RES_BITSTREAM_BUFFER_UNDERFLOW:
				ret=VM_BITSTREAM_BUFFER_UNDERFLOW;
				break;
			case MDI_RES_BITSTREAM_RECOVER:
				ret=VM_BITSTREAM_RECOVER;
				break;
			case MDI_RES_BITSTREAM_ERR_FAILED:
				ret=VM_BITSTREAM_FAILED;
				break;
			case MDI_RES_BITSTREAM_ERR_INVALID_RESOULTION:
				ret=VM_BITSTREAM_ERR_INVALID_RESOULTION	;	
				break;
			case MDI_RES_BITSTREAM_ERR_INVALID_BITSTREAM:
 				ret=VM_BITSTREAM_ERR_INVALID_BITSTREAM;
				break;
			case MDI_RES_BITSTREAM_ERR_MEMORY_INSUFFICIENT:
				ret=VM_BITSTREAM_ERR_MEMORY_INSUFFICIENT;
				break;
			default:
				ret=VM_BITSTREAM_FAILED;
		}
		stub_bitstream_video_result_callback(handle,ret);
	}

}
#endif


#ifdef __MDI_BITSTREAM_VIDEO_SUPPORT__
static VMINT stub_bitstream_start_param_convert(mdi_bitstream_video_start_param* p_mdi_param,vm_bitstream_video_start_param* p_para)
{

	VMUINT blt_layer_flag=0,play_layer_flag=0,gdi_base_layer_handle=0,gdi_play_layer_handle=0; 
	if (!p_mdi_param || !p_para)
		return VM_BITSTREAM_FAILED;

	if (!stub_get_layer_flag(p_para->base_layer,p_para->h_layer,&gdi_play_layer_handle,&gdi_base_layer_handle,&blt_layer_flag,&play_layer_flag))
		return VM_BITSTREAM_FAILED;
	
	p_mdi_param->ms_start_time=p_para->ms_start_time;
	p_mdi_param->h_layer=gdi_play_layer_handle; 
	p_mdi_param->blt_layer_flag=blt_layer_flag;
	p_mdi_param->play_layer_flag=play_layer_flag;
	p_mdi_param->rotate=p_para->rotate;
	p_mdi_param->is_visual_update=TRUE;
	return VM_BITSTREAM_SUCCEED;
}
#endif

#ifdef __MDI_BITSTREAM_VIDEO_SUPPORT__
//将vm_bitstream_video_h264_cfg结构进行转换
VMINT stub_bitstream_cfg_param_convert(mdi_bitstream_cfg_struct *p_mdi_cfg_struct,vm_bitstream_video_h264_cfg* cfg)
{

	if (!p_mdi_cfg_struct && !cfg)
		return VM_BITSTREAM_FAILED;
	//vm_log_warn(" stub_bitstream_cfg_param_convert.....");

	memset(p_mdi_cfg_struct,0x00,sizeof(mdi_bitstream_cfg_struct));

	p_mdi_cfg_struct->codec_type=MDI_BITSTREAM_CODEC_TYPE_H264;
	p_mdi_cfg_struct->codec_cfg.h264.audio_type=cfg->audio_type;
	p_mdi_cfg_struct->codec_cfg.h264.AVC_config_record_size=cfg->AVC_config_record_size;
	p_mdi_cfg_struct->codec_cfg.h264.is_ps_oob=cfg->is_ps_oob;
	p_mdi_cfg_struct->codec_cfg.h264.level_idc=cfg->level_idc;
	p_mdi_cfg_struct->codec_cfg.h264.packetization_mode=cfg->packetization_mode;
	p_mdi_cfg_struct->codec_cfg.h264.profile_idc=cfg->profile_idc;
	p_mdi_cfg_struct->codec_cfg.h264.p_AVC_config_record=cfg->p_AVC_config_record;
	p_mdi_cfg_struct->codec_cfg.h264.sampling_rate=cfg->sampling_rate;
	p_mdi_cfg_struct->codec_cfg.h264.timescale=cfg->timescale;

	return VM_BITSTREAM_SUCCEED;
}
#endif

VMINT stub_bitstream_video_open(
        VMINT* handle,
        vm_bitstream_video_h264_cfg* cfg,
        vm_bitstream_video_result_callback callback)
{
	VMINT ret=VM_BITSTREAM_FAILED;
#ifdef __MDI_BITSTREAM_VIDEO_SUPPORT__
	mdi_bitstream_cfg_struct cfg_struct;

	if (stub_bitstream_cfg_param_convert(&cfg_struct,cfg)!=VM_BITSTREAM_SUCCEED)
		return VM_BITSTREAM_FAILED;

	//vm_log_warn("stub_bitstream_video_open....");
	if (mdi_bitstream_video_open_handle(handle, &cfg_struct, stub_mdi_bitstream_video_result_callback)==MDI_RES_BITSTREAM_SUCCEED)
	{
		stub_bitstream_video_result_callback=callback;
		ret=VM_BITSTREAM_SUCCEED;
	}
	else{
		//vm_log_warn(" mdi_bitstream_video_open_handle if FAILED....");
		ret=VM_BITSTREAM_FAILED;
	}
#endif
	return ret;
}



VMINT stub_bitstream_video_close(VMINT handle)
 {
#ifdef __MDI_BITSTREAM_VIDEO_SUPPORT__
		return mdi_bitstream_video_close(handle);
#else
		return VM_BITSTREAM_FAILED;
#endif
 }
 

VMINT stub_bitstream_video_get_buffer_status(VMINT handle, vm_bitstream_video_buffer_status* status)
{
	VMINT ret=VM_BITSTREAM_FAILED;
#ifdef __MDI_BITSTREAM_VIDEO_SUPPORT__
	mdi_bitstream_video_buffer_status buffer_status;	

	if (!status)
		return VM_BITSTREAM_FAILED;

	if (mdi_bitstream_video_get_buffer_status(handle, &buffer_status)==MDI_RES_BITSTREAM_SUCCEED)
	{
		//回填vm_bitstream_video_buffer_status
		status->buffer_duration=buffer_status.buffer_duration;
		status->percentage_used=buffer_status.percentage_used;
		status->free_space=buffer_status.free_space;
		status->current_frame_count=buffer_status.current_frame_count;
		status->required_frame_count=buffer_status.required_frame_count;
		ret= VM_BITSTREAM_SUCCEED;
	} else
		ret=VM_BITSTREAM_FAILED;

#endif
	return ret;
}


VMINT stub_bitstream_video_put_frame(VMINT handle, VMUSTR buffer, VMUINT buffer_size, VMUINT timestamp)
{
 	VMINT ret=VM_BITSTREAM_FAILED;
#ifdef __MDI_BITSTREAM_VIDEO_SUPPORT__
	 {
		if ( !buffer  )
			return VM_BITSTREAM_FAILED;
		
		if (mdi_bitstream_video_put_frame(handle, buffer,buffer_size,timestamp)==MDI_RES_BITSTREAM_SUCCEED)
			ret=VM_BITSTREAM_SUCCEED;
		else
			ret=VM_BITSTREAM_FAILED;
	 }
#endif
	return ret;
 } 


VMINT stub_bitstream_video_start(VMINT handle, vm_bitstream_video_start_param* para)
{
 	VMINT ret=VM_BITSTREAM_FAILED;
#ifdef __MDI_BITSTREAM_VIDEO_SUPPORT__
	{
		mdi_bitstream_video_start_param start_param;

		if ((!para) || (stub_bitstream_start_param_convert(&start_param,para)!=VM_BITSTREAM_SUCCEED))
			return VM_BITSTREAM_FAILED;

		if (mdi_bitstream_video_start(handle, &start_param)==MDI_RES_BITSTREAM_SUCCEED)
			ret=VM_BITSTREAM_SUCCEED;
		else
			ret=VM_BITSTREAM_FAILED;
	}
#endif
	return ret;
	
}



VMINT stub_bitstream_video_stop(VMINT handle)
{
 	VMINT ret=VM_BITSTREAM_FAILED;
#ifdef __MDI_BITSTREAM_VIDEO_SUPPORT__
	{
		if (mdi_bitstream_video_stop(handle)==MDI_RES_BITSTREAM_SUCCEED)
			ret=VM_BITSTREAM_SUCCEED;
		else
			ret=VM_BITSTREAM_FAILED;
	}
#endif
	return ret;
}


VMINT stub_bitstream_video_get_play_time(VMINT handle, VMUINT* ms_current_time)
{
 	VMINT ret=VM_BITSTREAM_FAILED;
#ifdef __MDI_BITSTREAM_VIDEO_SUPPORT__
	{
		if (!ms_current_time)
			return VM_BITSTREAM_FAILED;

		if (mdi_bitstream_video_get_play_time(handle,ms_current_time)==MDI_RES_BITSTREAM_SUCCEED)
			ret=VM_BITSTREAM_SUCCEED;
		else
			ret=VM_BITSTREAM_FAILED;
	}
#endif
	return ret;
}



VMINT stub_bitstream_video_switchscreenstop(VMINT handle)
 {
 	VMINT ret=VM_BITSTREAM_FAILED;
#ifdef __MDI_BITSTREAM_VIDEO_SUPPORT__
	{
		if (mdi_bitstream_video_switchscreenstop(handle)==MDI_RES_BITSTREAM_SUCCEED)
			ret=VM_BITSTREAM_SUCCEED;
		else
			ret=VM_BITSTREAM_FAILED;
	}
#endif
	return ret;
 }




VMINT stub_bitstream_video_switchscreenstart(VMINT handle, vm_bitstream_video_start_param* p_para)
{
	VMINT ret=VM_BITSTREAM_FAILED;
#ifdef __MDI_BITSTREAM_VIDEO_SUPPORT__
	{
		mdi_bitstream_video_start_param start_param;
		
		if ((!p_para ) || (stub_bitstream_start_param_convert(&start_param,p_para)!=VM_BITSTREAM_SUCCEED))
			return VM_BITSTREAM_FAILED;
		
		if (mdi_bitstream_video_switchscreenstart(handle, &start_param)==MDI_RES_BITSTREAM_SUCCEED)
			ret=VM_BITSTREAM_SUCCEED;
		else
			ret=VM_BITSTREAM_FAILED;
	}
#endif
	return ret;
}
/* BITSTREAM H264 END*/

/*VIDEO BEGIN*/
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
static vm_video_info_struct vm_video_info;
static vm_video_open_result_callback stub_video_open_result_callback;
static vm_video_finish_callback stub_video_finish_callback;
static void stub_mdi_open_result_callback( MDI_RESULT ret, mdi_video_info_struct *video_info);
static void stub_mdi_play_finish_callback(MDI_RESULT ret);
static void stub_videoinfo_getvalues(vm_video_info_struct *toinfo,const mdi_video_info_struct *frominfo);
#endif

extern VMINT vm_wstrncpy(VMWSTR dst, const VMWSTR src, VMINT length) ;
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
static void stub_videoinfo_getvalues(vm_video_info_struct *toinfo,const mdi_video_info_struct *frominfo)
{
	if (toinfo && frominfo)
	{
		toinfo->width=frominfo->width;
		toinfo->height=frominfo->height;
		toinfo->total_frame_count=frominfo->total_frame_count;
		toinfo->total_time_duration=frominfo->total_time_duration;
		toinfo->track=frominfo->track;
		toinfo->handle=frominfo->handle;
		toinfo->is_seekable=frominfo->is_seekable;
		toinfo->aud_channel_no=frominfo->aud_channel_no;
		toinfo->aud_sample_rate=frominfo->aud_sample_rate;
		toinfo->is_drm_streaming=frominfo->is_drm_streaming;
		toinfo->drm_handle=frominfo->drm_handle;
		
		vm_wstrncpy((VMWSTR)toinfo->title_desc, (VMWSTR)frominfo->title_desc,VM_VIDEO_MAX_CONTENT_INFO_LEN);
		vm_wstrncpy((VMWSTR)toinfo->artist_desc, (VMWSTR)frominfo->artist_desc,VM_VIDEO_MAX_CONTENT_INFO_LEN);
		vm_wstrncpy((VMWSTR)toinfo->album_desc, (VMWSTR)frominfo->album_desc,VM_VIDEO_MAX_CONTENT_INFO_LEN);
		vm_wstrncpy((VMWSTR)toinfo->author_desc, (VMWSTR)frominfo->author_desc,VM_VIDEO_MAX_CONTENT_INFO_LEN);
		vm_wstrncpy((VMWSTR)toinfo->copyright_desc, (VMWSTR)frominfo->copyright_desc,VM_VIDEO_MAX_CONTENT_INFO_LEN);
		vm_wstrncpy((VMWSTR)toinfo->date_desc, (VMWSTR)frominfo->date_desc,VM_VIDEO_MAX_CONTENT_INFO_LEN);

	}

}
#endif

#ifdef __MMI_VIDEO_PLAY_SUPPORT__
static void stub_mdi_open_result_callback( MDI_RESULT ret, mdi_video_info_struct *video_info) 
{
	/* changed by zaiping.chen, 2010.07.12, static memory optimize, begin */
#if 0
	if (ret>=0)
	{
		stub_videoinfo_getvalues(&vm_video_info,video_info);
	}

	if (stub_video_open_result_callback)
		stub_video_open_result_callback(ret,&vm_video_info);

	memset(&vm_video_info,0x00,sizeof(vm_video_info_struct));
#endif

	vm_video_info_struct *info;
	
	if (ret>=0)
	{
		vm_log_debug("static memory optimize: stub_mdi_open_result_callback");
		info = vm_malloc(sizeof(mdi_video_info_struct));
		if (NULL == info)
		{
			vm_log_error("stub_mdi_open_result_callback vm_malloc fail");
			return;
		}
		stub_videoinfo_getvalues(info,video_info);
	}

	if (stub_video_open_result_callback)
		stub_video_open_result_callback(ret,info);
		
	if (NULL != info)
	{
		vm_free(info);
	}
	/* changed by zaiping.chen, 2010.07.12, static memory optimize, end */
}



static void stub_mdi_play_finish_callback(MDI_RESULT ret)
{
	if (stub_video_finish_callback)
		stub_video_finish_callback(ret);

}
#endif

extern VMINT vm_wstrlen(VMWSTR s);
 VMINT stub_video_open_file(
                    const VMWSTR filename,
                    vm_video_open_result_callback open_result_callback)
{
	
	VMINT ret=VM_VIDEO_ERR_OPEN_FILE_FAILED;
#ifdef __MMI_VIDEO_PLAY_SUPPORT__

	if ((NULL==filename) 	|| (vm_wstrlen(filename)<=0))
		return VM_VIDEO_ERR_OPEN_FILE_FAILED;

	//kal_prompt_trace(MOD_IDLE,"vm_sal_video_open_file:vm_wstrlen(filename):%d",vm_wstrlen(filename));
	ret=mdi_video_ply_open_file((S8*)filename,stub_mdi_open_result_callback);
	//kal_prompt_trace(MOD_IDLE,"mdi_video_ply_open_file: ret:%d",ret);
	switch (ret)
	{
		case MDI_RES_VDOPLY_SUCCEED:
			ret=VM_VIDEO_SUCCESS;
			stub_video_open_result_callback=open_result_callback;
			break;
		case MDI_RES_VDOPLY_ERR_MEMORY_INSUFFICIENT:	
			ret=VM_VIDEO_ERR_MEMORY_INSUFFICIENT;
			break;
        	case MDI_RES_VDOPLY_ERR_FILE_TOO_LARGE:
			ret=VM_VIDEO_ERR_FILE_TOO_LARGE;
			break;
        	case MDI_RES_VDOPLY_ERR_FRAMERATE_TOO_HIGH:
			ret=VM_VIDEO_ERR_FRAMERATE_TOO_HIGH;
			break;
        	case MDI_RES_VDOPLY_ERR_INVALID_RESOULTION:
			ret=VM_VIDEO_ERR_INVALID_RESOULTION;
			break;
		default:
			ret=VM_VIDEO_ERR_OPEN_FILE_FAILED;
        }
#endif

	return	ret;     
	
}


 VMINT stub_video_close_file(void)
 {
        VMINT ret=VM_VIDEO_FAILED;
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
	if ((mdi_video_ply_close_file())==MDI_RES_VDOPLY_SUCCEED)
		ret=VM_VIDEO_SUCCESS;
	else
		ret=VM_VIDEO_FAILED;
#endif
	return ret;
 }


 VMINT stub_video_open_buffer(
                    const VMUSTR buffer,
                    const VMUINT buffer_len,
                    vm_video_info_struct *info)
 {
 	
       VMINT ret=VM_VIDEO_FAILED;
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
	mdi_video_info_struct video_info;

	if ((NULL==info) || (NULL==buffer) )
		return VM_VIDEO_FAILED;

	memset(&video_info,0x00,sizeof(mdi_video_info_struct));
	
	ret=mdi_video_ply_open_clip_buffer(buffer, buffer_len, &video_info);
	switch (ret)
	{
		case MDI_RES_VDOPLY_SUCCEED:
			ret=VM_VIDEO_SUCCESS;
			//给结构体赋值
			/* changed by zaiping.chen, 2010.07.12, static memory optimize, begin */
			//stub_videoinfo_getvalues(&vm_video_info,&video_info);
			stub_videoinfo_getvalues(info, &video_info);
			/* changed by zaiping.chen, 2010.07.12, static memory optimize, end */
			break;
		case MDI_RES_VDOPLY_ERR_MEMORY_INSUFFICIENT:	
			ret=VM_VIDEO_ERR_MEMORY_INSUFFICIENT;
			break;
        	case MDI_RES_VDOPLY_ERR_FRAMERATE_TOO_HIGH:
			ret=VM_VIDEO_ERR_FRAMERATE_TOO_HIGH;
			break;
		default:
			ret=VM_VIDEO_FAILED;
        }
#endif
	return	ret; 
 }
                    

 VMINT stub_video_close_buffer(void)
 {
 	VMINT ret=VM_VIDEO_FAILED;
 #ifdef __MMI_VIDEO_PLAY_SUPPORT__
	if (mdi_video_ply_close_clip_buffer()==MDI_RES_VDOPLY_SUCCEED)
		ret=VM_VIDEO_SUCCESS;
	else
		ret=VM_VIDEO_FAILED;
 #endif
 	return ret ;
 }

 VMINT stub_video_play(
                    VMUINT player_layer_handle,
                    VMUINT base_layer_handle,
                    VMUINT16 repeat_count, 
                    VMINT is_visual_update,
                    VMINT is_play_audio,
                    VMINT audio_path, 
                    VMUINT16 rotate, 
                    VMUINT16 play_speed,
                    vm_video_finish_callback play_finish_callback)
{
 	VMINT ret=VM_VIDEO_ERR_PLAY_FAILED;
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
	VMUINT blt_layer_flag=0,play_layer_flag=0,gdi_base_layer_handle=0,gdi_play_layer_handle=0; 
	VMUINT16 mdi_rotate=MDI_LCD_ROTATE_0;
	VMINT mdi_audio_path=MDI_DEVICE_SPEAKER2;

	if (!stub_get_layer_flag(base_layer_handle,player_layer_handle,&gdi_play_layer_handle,&gdi_base_layer_handle,&blt_layer_flag,&play_layer_flag))
		return VM_VIDEO_ERR_PLAY_FAILED;
	

	switch(rotate)
	{
		case VM_VIDEO_LCD_ROTATE_0:
			mdi_rotate=MDI_LCD_ROTATE_0;
			break;
		case VM_VIDEO_LCD_ROTATE_90:
			mdi_rotate=MDI_LCD_ROTATE_90;
			break;
		case VM_VIDEO_LCD_ROTATE_180:
			mdi_rotate=MDI_LCD_ROTATE_180;
			break;
		case VM_VIDEO_LCD_ROTATE_270:
			mdi_rotate=MDI_LCD_ROTATE_270;
			break;
		default:
			mdi_rotate=MDI_LCD_ROTATE_0;	
	}


	switch (audio_path)
	{
		case VM_DEVICE_SPEAKER:
			mdi_audio_path=MDI_DEVICE_SPEAKER;
			break;
		case VM_DEVICE_MICROPHONE:
			mdi_audio_path=MDI_DEVICE_MICROPHONE;
			break;
		case VM_DEVICE_SPEAKER2:
			mdi_audio_path=MDI_DEVICE_SPEAKER2;
			break;
		case VM_DEVICE_LOUDSPEAKER:
			mdi_audio_path=MDI_DEVICE_LOUDSPEAKER;
			break;
		case VM_DEVICE_SPEAKER_BOTH:
			mdi_audio_path=MDI_DEVICE_SPEAKER_BOTH;
			break;
		case VM_DEVICE_BT_HEADSET:
			mdi_audio_path=MDI_DEVICE_BT_HEADSET;
			break;	
		default:
			mdi_audio_path=MDI_DEVICE_SPEAKER2;
	}
	
	ret=mdi_video_ply_play((gdi_handle)gdi_play_layer_handle,blt_layer_flag,play_layer_flag,repeat_count,(BOOL)is_visual_update,(BOOL)is_play_audio,(U8)mdi_audio_path,mdi_rotate, play_speed, stub_mdi_play_finish_callback);
	//kal_prompt_trace(MOD_IDLE,"mdi_video_ply_play: ret:%d,gdi_play_layer_handle:%d,blt_layer_flag:%d,play_layer_flag:%d",ret,gdi_play_layer_handle,blt_layer_flag,play_layer_flag);
	//kal_prompt_trace(MOD_IDLE,"repeat_count:%d,is_visual_update:%d,is_play_audio:%d,mdi_audio_path:%d,mdi_rotate:%d, play_speed:%d",repeat_count,is_visual_update,is_play_audio,mdi_audio_path,mdi_rotate, play_speed);
	
	switch (ret)
	{
		case MDI_RES_VDOPLY_SUCCEED:
			ret=VM_VIDEO_SUCCESS;
			stub_video_finish_callback=play_finish_callback;
			break;
		case MDI_RES_VDOPLY_ERR_DRM_PROHIBITED:	
			ret=VM_VIDEO_ERR_DRM_PROHIBITED;
			break;
        	case MDI_RES_VDOPLY_PROGRESSIVE_FILE_NOT_ENOUGH:
			ret=VM_VIDEO_PROGRESSIVE_FILE_NOT_ENOUGH;
			break;
        	case MDI_RES_VDOPLY_ERR_INVALID_RESOULTION:
			ret=VM_VIDEO_ERR_INVALID_RESOULTION;
			break;
		default:
			ret=VM_VIDEO_ERR_PLAY_FAILED;		
        }
#endif

	return	ret;     
 }


 VMINT stub_video_stop(void)
 {
 	VMINT ret=VM_VIDEO_FAILED;
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
	if (mdi_video_ply_stop()==MDI_RES_VDOPLY_SUCCEED)
		ret=VM_VIDEO_SUCCESS;
	else
		ret=VM_VIDEO_FAILED;
#endif

	return ret;
}


 VMINT stub_video_seek_and_getframe(VMUINT64 time, VMUINT player_layer_handle)
 {
	VMINT ret=VM_VIDEO_FAILED;
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
	VMUINT gdi_player_layer_handle=0;
	gdi_player_layer_handle=vm_graphic_get_trans_handle(player_layer_handle);
	 if ((gdi_player_layer_handle!=0) && (mdi_video_ply_seek_and_get_frame(time,gdi_player_layer_handle)>=MDI_RES_VDOPLY_SUCCEED))
		ret=VM_VIDEO_SUCCESS;
	else
		ret=VM_VIDEO_FAILED;
#endif

	return ret;
 }

 
 VMINT stub_video_snapshot(VMUINT layer_handle, VMWSTR file_name)
 {
    	VMINT ret=VM_VIDEO_ERR_SNAPSHOT_FAILED;	
#ifdef __VDOPLY_FEATURE_SNAPSHOT__
	VMUINT gdi_layer_handle=0;
	if (!file_name || (vm_wstrlen(file_name)<=0))
		return VM_VIDEO_ERR_SNAPSHOT_FAILED;

	gdi_layer_handle=vm_graphic_get_trans_handle(layer_handle);

	if (gdi_layer_handle!=0)
		ret=mdi_video_ply_snapshot(gdi_layer_handle,(PS8)file_name);
	else
		return VM_VIDEO_ERR_SNAPSHOT_FAILED;
	
	switch (ret)
	{
		case MDI_RES_VDOPLY_SUCCEED:
			ret=VM_VIDEO_SUCCESS;
			break;
		case MDI_RES_VDOPLY_ERR_SNAPSHOT_DISK_FULL:	
			ret=VM_VIDEO_ERR_SNAPSHOT_DISK_FULL;
			break;
        	case MDI_RES_VDOPLY_ERR_SNAPSHOT_WRITE_PROTECTION:
			ret=VM_VIDEO_ERR_SNAPSHOT_WRITE_PROTECTION;
			break;
		default:
			ret=VM_VIDEO_ERR_SNAPSHOT_FAILED;
        }
#endif
	return	ret;  
 }



 VMINT stub_video_set_brightness(VMUINT16 brightness)
 {
	VMINT ret=VM_VIDEO_FAILED;

#ifdef __VDOPLY_FEATURE_VIDEO_ADJUSTMENT__
	VMUINT16 brightvalue;
	switch (brightness)
	{
		case VM_VIDEO_BRIGHTNESS_0:
			brightvalue=MDI_VIDEO_BRIGHTNESS_0;
			break;
		case VM_VIDEO_BRIGHTNESS_N1:
			brightvalue=MDI_VIDEO_BRIGHTNESS_N1;
			break;
		case VM_VIDEO_BRIGHTNESS_N2:
			brightvalue=MDI_VIDEO_BRIGHTNESS_N2;			
			break;
		case VM_VIDEO_BRIGHTNESS_N3:
			brightvalue=MDI_VIDEO_BRIGHTNESS_N3;		
			break;
		case VM_VIDEO_BRIGHTNESS_N4:
			brightvalue=MDI_VIDEO_BRIGHTNESS_N4;
			break;
		case VM_VIDEO_BRIGHTNESS_N5:
			brightvalue=MDI_VIDEO_BRIGHTNESS_N5;
			break;
		case VM_VIDEO_BRIGHTNESS_P1:
			brightvalue=MDI_VIDEO_BRIGHTNESS_P1;
			break;
		case VM_VIDEO_BRIGHTNESS_P2:
			brightvalue=MDI_VIDEO_BRIGHTNESS_P2;			
			break;
		case VM_VIDEO_BRIGHTNESS_P3:
			brightvalue=MDI_VIDEO_BRIGHTNESS_P3;		
			break;
		case VM_VIDEO_BRIGHTNESS_P4:
			brightvalue=MDI_VIDEO_BRIGHTNESS_P4;
			break;
		case VM_VIDEO_BRIGHTNESS_P5:
			brightvalue=MDI_VIDEO_BRIGHTNESS_P5;
			break;
		default:
			brightvalue=MDI_VIDEO_BRIGHTNESS_0;
	}
		
	if (mdi_video_ply_set_brightness(brightvalue)==MDI_RES_VDOPLY_SUCCEED)
		ret=VM_VIDEO_SUCCESS;
	else
		ret=VM_VIDEO_FAILED;
#endif

	return ret;
 }

 
 VMINT stub_video_set_contrast(VMUINT16 contrast)
 {
	VMINT ret=VM_VIDEO_FAILED;
#ifdef __VDOPLY_FEATURE_VIDEO_ADJUSTMENT__
	VMUINT16 contrastvalue;
	switch (contrast)
	{
		case VM_VIDEO_CONTRAST_0:
			contrastvalue=MDI_VIDEO_CONTRAST_0;
			break;
		case VM_VIDEO_CONTRAST_N1:
			contrastvalue=MDI_VIDEO_CONTRAST_N1;
			break;
		case VM_VIDEO_CONTRAST_N2:
			contrastvalue=MDI_VIDEO_CONTRAST_N2;			
			break;
		case VM_VIDEO_CONTRAST_N3:
			contrastvalue=MDI_VIDEO_CONTRAST_N3;		
			break;
		case VM_VIDEO_CONTRAST_N4:
			contrastvalue=MDI_VIDEO_CONTRAST_N4;
			break;
		case VM_VIDEO_CONTRAST_N5:
			contrastvalue=MDI_VIDEO_CONTRAST_N5;
			break;
		case VM_VIDEO_CONTRAST_P1:
			contrastvalue=MDI_VIDEO_CONTRAST_P1;
			break;
		case VM_VIDEO_CONTRAST_P2:
			contrastvalue=MDI_VIDEO_CONTRAST_P2;			
			break;
		case VM_VIDEO_CONTRAST_P3:
			contrastvalue=MDI_VIDEO_CONTRAST_P3;		
			break;
		case VM_VIDEO_CONTRAST_P4:
			contrastvalue=MDI_VIDEO_CONTRAST_P4;
			break;
		case VM_VIDEO_CONTRAST_P5:
			contrastvalue=MDI_VIDEO_CONTRAST_P5;
			break;
		default:
			contrastvalue=MDI_VIDEO_CONTRAST_0;
	}
		
	if (mdi_video_ply_set_contrast(contrastvalue)==MDI_RES_VDOPLY_SUCCEED)
		ret=VM_VIDEO_SUCCESS;
	else
		ret=VM_VIDEO_FAILED;
#endif

	return ret;
 }



 VMINT stub_video_get_cur_play_time(VMUINT64 *cur_play_time)
 {
 	VMINT ret=VM_VIDEO_FAILED;
 #ifdef __MMI_VIDEO_PLAY_SUPPORT__
 	if (!cur_play_time)
		ret= VM_VIDEO_FAILED;
	else
	{
 		mdi_video_ply_get_cur_play_time(cur_play_time);
		ret= VM_VIDEO_SUCCESS;
	}
#endif
	return ret;
 }

 /**
 *	根据URL 来打开流媒体视频(将把调用的VREAPP 切到后台，新开SCREEN 调用MTK 的视频播放器)。
 *    @param url			要打开的视频URL。
 */
#if (defined __MMI_VIDEO_STREAM__ && defined __MMI_VIDEO_PLAYER__)
extern void mmi_vdoply_entry_player_screen_from_rtsp_link(PS8 rtsp_url);
#endif
#ifdef __MMI_MEDIA_PLAYER_STREAM__
extern void mmi_medply_single_play_stream_from_rtsp_link(UI_string_type rtsp_url);
#endif
VMINT vm_sal_video_play_stream_from_rtsp_link(VMWSTR url)
{
#if (defined __MMI_VIDEO_STREAM__ && defined __MMI_VIDEO_PLAYER__)
	mmi_vdoply_entry_player_screen_from_rtsp_link((PS8)url);
	return VM_VIDEO_SUCCESS;
#elif defined(__MMI_MEDIA_PLAYER_STREAM__)
	mmi_medply_single_play_stream_from_rtsp_link((UI_string_type)url);
	return VM_VIDEO_SUCCESS;
#else
	return VM_VIDEO_FAILED;
#endif
}


 /**
 *	根据SDP文件 来打开流媒体视频(将把调用的VREAPP 切到后台，新开SCREEN 调用MTK 的视频播放器)。
 *    @param filename			要打开的SDP 视频流文件。
 *    @param is_short			打开的是否是8.3 格式的短文件名(TRUE 为8.3 格式的短文件名，FLASE 不是)。
 */
#if (defined __MMI_VIDEO_STREAM__ && defined __MMI_VIDEO_PLAYER__)
extern void mmi_vdoply_entry_player_screen_from_sdp_file(PS8 sdp_filename, BOOL is_short);
#endif
#ifdef __MMI_MEDIA_PLAYER_STREAM__
extern void mmi_medply_single_play_stream_from_sdp_file(UI_string_type sdp_file, MMI_BOOL is_short);
 #endif
VMINT vm_sal_video_play_stream_from_sdp_file(VMWSTR filename, VMUCHAR is_short)
{ 
#if (defined __MMI_VIDEO_STREAM__ && defined __MMI_VIDEO_PLAYER__)
	mmi_vdoply_entry_player_screen_from_sdp_file((PS8)filename, (BOOL)is_short);
	return VM_VIDEO_SUCCESS;
#elif defined(__MMI_MEDIA_PLAYER_STREAM__)
	mmi_medply_single_play_stream_from_sdp_file((UI_string_type)filename, (MMI_BOOL)is_short);
	return VM_VIDEO_SUCCESS;
#else
	return VM_VIDEO_FAILED;
#endif
 }
 

/*VIDEO END*/

#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
/*SMS START*/

#include "vmsms.h"
#include "vmsim.h"

#if defined(__VRE_RB_08A__ ) || defined(__VRE_RB_08B__ )
#include "SMSApi.h"//ltz
#include "MessagesMiscell.h"
#include "SMSStruct.h"
#elif defined(__VRE_RB_09A__)
#include "SMSStruct.h"
#include "SMSFunc.h"
#endif



extern  void vm_sms_delete_msg_list_callback(void *data, module_type mod, U16 result);
extern  void vm_sms_get_sc_address_callback(void *data, module_type mod, U16 result);
extern VMINT vm_selected_simcard;

void vm_sal_sms_select_simcard( mmi_frm_sms_send_struct * sendData)
{
	 #ifdef VRE_DUAL_SIM    	
	//vm_log_debug("vm_send_sms_request : set sendrequire");
	
		if (vm_selected_simcard == 1)
		{
			vm_log_debug("vm_send_sms_request : set sendrequire 1");
			sendData->sendrequire |= MMI_FRM_SMS_SEND_BY_SIM1; /* send by SIM1*/
		}
		else if  (vm_selected_simcard == 2)
		{
			vm_log_debug("vm_send_sms_request : set sendrequire 2");
    			sendData->sendrequire |= MMI_FRM_SMS_SEND_BY_SIM2; /* send by SIM2*/
		}
		else
		{
			vm_log_debug("vm_send_sms_request : set sendrequire 1");
			sendData->sendrequire |= MMI_FRM_SMS_SEND_BY_SIM1;  /* display option screen for user to select SIM */
		}
	
#endif /*VRE_DUAL_SIM */
	
}

VMINT vm_sal_sms_delete_msg_list(vm_sms_box_enum box_type,  vm_sms_sim_enum sim_id, VmSmsCallbackFunc callback_func,  void* user_data, VMINT * cause)
{
	
//	VMUINT16 index = 0;
	VMUINT16 type = 0;
	
	vm_log_debug("vm_sal_sms_delete_msg_list:start box_type=%d",box_type);
		
	if((box_type <= 0) || box_type >= 0x80)
	{
		vm_log_error("vm_sal_sms_delete_msg_list : type == VM_SMS_REQ_ERROR");
		return VM_SMS_REQ_ERROR;
	}
	if(box_type & VM_SMS_BOX_INBOX)
		type |= MMI_FRM_SMS_APP_INBOX;
	
	if(box_type & VM_SMS_BOX_OUTBOX)
		type |= MMI_FRM_SMS_APP_OUTBOX;
	
	if(box_type & VM_SMS_BOX_DRAFTS)
		type |= MMI_FRM_SMS_APP_DRAFTS;

/*ltz*/
#ifdef __MMI_UNIFIED_MESSAGE__
	if(box_type & VM_SMS_BOX_UNSENT)
		type |= MMI_FRM_SMS_APP_UNSENT;
#endif

	#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__  
	if(box_type && VM_SMS_BOX_SIM)
		type |= MMI_FRM_SMS_APP_SIM;
	#endif

	#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
	if(box_type && VM_SMS_BOX_ARCHIVE)
		type |= MMI_FRM_SMS_APP_ARCHIVE;
	#endif

	vm_log_debug("vm_sal_sms_delete_msg_list:start type=%x",type);
	
	mmi_frm_sms_delete_sms(vm_sms_delete_msg_list_callback, MOD_MMI, type, MMI_FRM_SMS_INVALID_INDEX);
	vm_log_debug("vm_sal_sms_delete_msg_list:end");
	
	return VM_SMS_REQ_NO_ERROR;
}

VMINT vm_sal_sms_get_msg_id_list(vm_sms_query_t* query_data,  VmSmsCallbackFunc callback_func,  void* user_data,VMINT * cause)
{
	VMUINT16 num;
	VMUINT16 type;
	VMUINT16 * msg_id_list = NULL;
	vm_sms_query_msg_cb_t sms_query;
	vm_sms_callback_t callback_data;
	VMINT i = 0;

	if(query_data == NULL)
	{
		vm_log_error("vm_sal_sms_get_msg_id_list: query_data == NULL");
		return VM_SMS_REQ_ERROR;
	}
	vm_log_debug("vm_sal_sms_get_msg_id_list:query_data->status=%d",query_data->status);
	switch(query_data->status)
	{
		case VM_SMS_STATUS_UNREAD:
		//	type = MMI_FRM_SMS_APP_UNREAD;
		//	break;
			
		case VM_SMS_STATUS_READ:
			type = MMI_FRM_SMS_APP_INBOX;
			break;
			
		case VM_SMS_STATUS_SENT:
		#ifndef __MMI_UNIFIED_MESSAGE__              
		case VM_SMS_STATUS_UNSENT:
		#endif
			type = MMI_FRM_SMS_APP_OUTBOX;
			break;
				
		 #ifdef __MMI_MESSAGES_DRAFT_BOX__
		case VM_SMS_STATUS_DRAFT:
			type = MMI_FRM_SMS_APP_DRAFTS;
			break;
		#endif	
		
		#ifdef __MMI_UNIFIED_MESSAGE__
		case VM_SMS_STATUS_UNSENT:
			type = MMI_FRM_SMS_APP_UNSENT;
			break;
		#endif

		default:
			vm_log_error("vm_sal_sms_get_msg_id_list : query_data->status=%d",query_data->status);
			return VM_SMS_REQ_ERROR;
			
	}
	vm_log_debug("vm_sal_sms_get_msg_id_list:type=%d",type);
	num =  mmi_frm_sms_get_sms_list_size(type);
	if(num == 0 || num == MMI_FRM_SMS_INVALID_INDEX)
	{
		vm_log_error("vm_sal_sms_get_msg_id_list :num = =0 || num == MMI_FRM_SMS_INVALID_INDEX");
		return VM_SMS_REQ_ERROR;
	}
	memset(&sms_query, 0, sizeof(vm_sms_query_msg_cb_t));
	sms_query.msg_id_list = (VMUINT16 *)_vm_kernel_calloc(sizeof(VMUINT16)*num);
	if(sms_query.msg_id_list == NULL)
	{
		vm_log_error("vm_sal_sms_get_msg_id_list:sms_query.msg_id_list == NULL");
		return VM_SMS_REQ_ERROR;
	}

	msg_id_list =(VMUINT16 *) _vm_kernel_calloc(sizeof(VMUINT16)*num);
	if(msg_id_list == NULL)
	{
		vm_log_error("vm_sal_sms_get_msg_id_list:msg_id_list == NULL");
		_vm_kernel_free(sms_query.msg_id_list );
		return VM_SMS_REQ_ERROR;
	}
	
	sms_query.msg_num = num;
	
	for(i=0; i<num; i++)
	{
		msg_id_list[i]  = mmi_frm_sms_get_msg_index(type, i);
		vm_log_debug("vm_sms_get_msg_id_list:msg_id_list[%d]=%d", i, msg_id_list[i]);
	}
	
	if(query_data->sort_flag == VM_SMS_SORT_TIMESTAMP && query_data->order_flag == VM_SMS_ORDER_ASC)
	{
	
		for(i=0; i<num; i++)
		{
			sms_query.msg_id_list[i]  = msg_id_list[num-i-1];		
		}
		
	}
	else
	{
   		memcpy(sms_query.msg_id_list , msg_id_list, sizeof(VMUINT16)*num);
	}
	callback_data.result = TRUE;
	callback_data.cause = VM_SMS_CAUSE_NO_ERROR;
	callback_data.action = VM_SMS_ACTION_QUERY;
	callback_data.action_data = &sms_query;
	callback_data.user_data = user_data;
	
	callback_func(&callback_data);
	_vm_kernel_free(sms_query.msg_id_list);
	_vm_kernel_free(msg_id_list);
	return VM_SMS_REQ_NO_ERROR;
}


VMINT16 vm_sal_sms_get_msg_id(vm_sms_box_enum box_type, VMUINT16 msg_index)
{
	VMINT16 msg_id = -1;
	VMUINT16 type = 0;
	
	vm_log_debug("vm_sal_sms_get_msg_id:start, box_type=%x,index=%d", box_type, msg_index);
	switch (box_type)
	{        
	
		case VM_SMS_BOX_INBOX:
			type = MMI_FRM_SMS_APP_INBOX;
			break;
			
		case VM_SMS_BOX_OUTBOX:
			type = MMI_FRM_SMS_APP_OUTBOX;
			break;
			
		#ifdef __MMI_MESSAGES_DRAFT_BOX__
		case VM_SMS_BOX_DRAFTS:
			type = MMI_FRM_SMS_APP_DRAFTS;
			break;
		#endif 	
		
   		#ifdef __MMI_UNIFIED_MESSAGE__
		case VM_SMS_BOX_UNSENT:
			type = MMI_FRM_SMS_APP_UNSENT;
			break;
        	#endif 
			
		#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
		case VM_SMS_BOX_SIM:
			type = MMI_FRM_SMS_APP_SIM;
			break;
		#endif 
					
		 default:
		 	vm_log_error("vm_sal_sms_get_msg_id:ERROR type=%d",type);
			return VM_SMS_REQ_ERROR;
           
	}
	vm_log_debug("vm_sal_sms_get_msg_id:start, type=%x", type);
	msg_id = mmi_frm_sms_get_msg_index(type, msg_index);
	if(msg_id == MMI_FRM_SMS_INVALID_INDEX)
		msg_id = -1;
	vm_log_debug("vm_sal_sms_get_msg_id:msg_id=%d, type=%d, index=%d", msg_id, type, msg_index);
	return msg_id;

}


 VMINT vm_sms_convert_box(vm_sms_box_enum box_type)
{
	VMINT type = 0;

	switch (box_type)
	{
		case VM_SMS_BOX_INBOX:
			type = MMI_FRM_SMS_APP_INBOX;
			break;
			
  		case VM_SMS_BOX_OUTBOX:
			
		#ifndef __MMI_MESSAGES_DRAFT_BOX__
		case VM_SMS_BOX_DRAFTS:
		#endif 
			type = MMI_FRM_SMS_APP_OUTBOX;
			break;
			
		#ifdef __MMI_MESSAGES_DRAFT_BOX__
		case VM_SMS_BOX_DRAFTS:
			type = MMI_FRM_SMS_APP_DRAFTS;
			break;
		 #endif 
		 
       	#ifdef __MMI_UNIFIED_MESSAGE__          
		case VM_SMS_BOX_UNSENT:
			type = MMI_FRM_SMS_APP_UNSENT;
			break;
         	#endif 
			
		#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__      
			type = MMI_FRM_SMS_APP_ARCHIVE;
			break;
       	#endif 
		
		#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__       
		case VM_SMS_BOX_SIM:
			type = MMI_FRM_SMS_APP_SIM;
			break;
        	#endif 
			
		default:
		 	type = VM_SMS_REQ_ERROR;
			vm_log_error("vm_sms_get_box_size:ERROR box_type=%d",box_type);
			break;
	}

	return type;
}

void vm_sms_read_msg_callback(void *data, module_type mod, U16 result)
{
	vm_sms_callback_t callback_data;
	vm_sms_read_msg_cb_t   msg_ptr;
	vm_sms_msg_data_t * read_msg = NULL;
	VMINT8 *content = NULL;
		 

	VMUINT16 type;
	VMUINT16 sms_frm_type;
		
	vm_log_debug("vm_sms_read_sms_callback:result=%d", result);

	if(vre_running == FALSE)
	{
		return;
	}
	
	memset(&callback_data, 0, sizeof(vm_sms_callback_t));

	if (result != MMI_FRM_SMS_OK)
	{
      
		callback_data.result = FALSE;
		callback_data.cause = VM_SMS_CAUSE_DATA_INVALID;
	}
	else
	{
		EMSData *pEms;
 		
		type = *(U16*)data;
		vm_log_debug("vm_sms_read_sms_callback:type=%d", type);
		GetEMSDataForView(&pEms, 0);
		read_msg = _vm_kernel_calloc(sizeof(vm_sms_msg_data_t));
		if(read_msg == NULL)
		{
			callback_data.result = FALSE;
			callback_data.cause = VM_SMS_CAUSE_DATA_INVALID;
			vm_sms_callback(&callback_data);
			return;
			
		}
		msg_ptr.msg_data = read_msg;
		
		sms_frm_type = type & 0x0FFF;
		vm_log_debug("vm_sms_read_sms_callback:sms_frm_type=%d", sms_frm_type);
		switch (sms_frm_type)
		{
			case MMI_FRM_SMS_APP_UNREAD:
			case MMI_FRM_SMS_APP_INBOX:
			                       
				if (sms_frm_type == MMI_FRM_SMS_APP_UNREAD)
                            {
 					read_msg->status = VM_SMS_STATUS_UNREAD;
                            }
                            else
                            {
					read_msg->status  = VM_SMS_STATUS_READ;
                            }
                   
				break;
                    

			case MMI_FRM_SMS_APP_OUTBOX:
				 read_msg->status  = VM_SMS_STATUS_SENT;
				break;

			case MMI_FRM_SMS_APP_DRAFTS:
				 read_msg->status  = VM_SMS_STATUS_DRAFT;
				break;

#ifdef __MMI_UNIFIED_MESSAGE__
			case MMI_FRM_SMS_APP_UNSENT:	
				 read_msg->status  = VM_SMS_STATUS_UNSENT;
				break;
#endif
                
			default:
				 read_msg->status  = VM_SMS_STATUS_UNSUPPORTED;
				 callback_data.result = FALSE;
				callback_data.cause = VM_SMS_CAUSE_DATA_INVALID;
                        break;
		}
		
		if(read_msg->status != VM_SMS_STATUS_UNSUPPORTED)
		{
			content =  _vm_kernel_calloc(pEms->textLength+2);
			if(content == NULL)
			{
				callback_data.result = FALSE;
				callback_data.cause = VM_SMS_CAUSE_DATA_INVALID;
				vm_sms_callback(&callback_data);
				_vm_kernel_free(read_msg);
				return;
			}
			read_msg->content_buff = content;
		//read_msg->number
		//read_msg->mti
		//read_msg->tp_st
		//read_msg->folder_id
		//read_msg->para_flag
		//read_msg->storage_type
		//read_msg->sim_id
		//read_msg->timestamp
		//read_msg->sc_address
		//read_msg->pid
		//read_msg->vp
		//read_msg->status_report
		//read_msg->reply_path
		read_msg->src_port = pEms->PortNum.src_port;
		read_msg->dest_port = pEms->PortNum.dst_port;
		read_msg->dcs = pEms->dcs;
	
		read_msg->content_buff_size = pEms->textLength + 2;
		vm_wstrncpy((VMWSTR)read_msg->content_buff, (VMWSTR)pEms->textBuffer, (read_msg->content_buff_size-2)/2);
		
		read_msg->dcs = pEms->dcs;
		vm_log_debug("vm_sms_read_sms_callback:read_msg->dcs = %d", read_msg->dcs);
		
		vm_log_debug("vm_sms_read_sms_callback:vm_gb2312_string((VMWSTR)read_msg->content_buff) =%s", vm_gb2312_string((VMWSTR)read_msg->content_buff));
		vm_log_debug("vm_sms_read_sms_callback: vm_gb2312_string((VMWSTR)pEms->textBuffer) =%s", vm_gb2312_string((VMWSTR)pEms->textBuffer));
		vm_log_debug("vm_sms_read_sms_callback:pEms->textBuffer =%s", pEms->textBuffer);
		
		vm_log_debug("vm_sms_read_sms_callback:pEms->textLength = %d", pEms->textLength);

		callback_data.result = TRUE;
		callback_data.cause = VM_SMS_CAUSE_NO_ERROR;
			
		}
	}
              
    
	callback_data.action = VM_SMS_ACTION_READ;
	callback_data.user_data = NULL;
	callback_data.action_data = &msg_ptr;
	
	vm_sms_callback(&callback_data);
	
	_vm_kernel_free(read_msg);
	_vm_kernel_free(content);
		

}

#define vm_sms_event_registered_by_process(PHANDLE) (vm_res_get_data_list_count_by_proecss((PHANDLE), VM_RES_TYPE_SMS_INTERRUPT) > 0)
VMUINT8 vm_sms_interrupt_action(void *data, int withobject, void *content)
{
	mmi_frm_sms_deliver_msg_struct *delivermsg = (mmi_frm_sms_deliver_msg_struct*) data;
	mmi_frm_sms_concat_struct *concatinfo = (mmi_frm_sms_concat_struct*) & (delivermsg->concat_info);
	
	vm_sms_event_t  vm_sms_event_ptr;
	vm_sms_event_new_sms_t  vm_event_new_msg;
	vm_sms_new_msg_t * vm_new_msg = NULL;
    
    
	VMUINT8 * vm_event_new_msg_content;
    VMINT user_res = FALSE;
    VM_P_HANDLE *phandle_lst = NULL;
    VMUINT process_num = 0;
    VMINT i;
    VM_P_HANDLE cur_p_handle;
    vm_res_node_t res_node;
    VMUINT16 msg_id;
    
	if(!vre_running || withobject || !data|| !content)
		return FALSE;

	if((vm_new_msg = _vm_kernel_calloc(sizeof(vm_sms_new_msg_t))) == NULL)
		return FALSE;

    memset(&vm_sms_event_ptr,0,sizeof(vm_sms_event_t));
    memset(&vm_event_new_msg,0,sizeof(vm_sms_event_new_sms_t));  

	vm_sms_event_ptr.event_info = &vm_event_new_msg;
    vm_sms_event_ptr.event_id = VM_EVT_ID_SMS_NEW_MSG;
    vm_sms_event_ptr.user_data= NULL;
    
	vm_event_new_msg.msg_data = vm_new_msg;
	vm_new_msg->message_len = (U16) mmi_ucs2strlen(content) * 2;
  // vm_new_msg->message_len = delivermsg->no_msg_data;
    vm_log_debug("[SMS]-vm_new_msg message_len=%d,%d",vm_new_msg->message_len,mmi_ucs2strlen(content) * 2);
    
	vm_event_new_msg_content = _vm_kernel_calloc(vm_new_msg->message_len+2);
	if(vm_event_new_msg_content == NULL)
	{
		_vm_kernel_free(vm_new_msg);
		return TRUE;
	}	
	vm_event_new_msg.content = vm_event_new_msg_content;
	memcpy(vm_event_new_msg_content, content, vm_new_msg->message_len);
    
    /*if ((msg_id = vm_sms_get_msg_id(VM_SMS_BOX_INBOX, delivermsg->index)) < 0) 
    {
        if(vm_new_msg)
            _vm_kernel_free(vm_new_msg);
        if(vm_event_new_msg_content)
            _vm_kernel_free(vm_event_new_msg_content);
        vm_log_debug("[SMS]-vm_sms_interrupt_event_callback:msg_id error =%d",msg_id);
        return FALSE;
    }*/
    vm_event_new_msg.msg_id = delivermsg->index;   



    
	vm_new_msg->msg_id = delivermsg->index;
    vm_new_msg->dest_port = delivermsg->dest_port;
    vm_new_msg->src_port = delivermsg->src_port;   
 
	vm_new_msg->dcs = delivermsg->dcs;
	vm_new_msg->fo = delivermsg->fo;
    vm_new_msg->storage_type = delivermsg->storageType;
    strncpy((char*)vm_new_msg->data, (char*)delivermsg->msg_data,1);
    vm_new_msg->mti = delivermsg->mti;
    vm_new_msg->pid = delivermsg->pid;

#ifdef __MMI_DUAL_SIM_MASTER__
	if (delivermsg->display_type == MMI_FRM_SMS_TYPE_CLASS0)
	{
		vm_new_msg->sim_id= VM_SMS_SIM_1;
	}
	else
	{
		vm_new_msg->sim_id= VM_SMS_SIM_2;
	}
#endif

	mmi_frm_sms_convert_l4_num_to_ascii_num(vm_new_msg->number, &delivermsg->addr_number, MAX_DIGITS_SMS);
	mmi_frm_sms_convert_l4_num_to_ascii_num(vm_new_msg->sc_number, &(delivermsg->sca_number), MAX_DIGITS_SMS);
    
	vm_new_msg->total_seg = concatinfo->total_seg;
	vm_new_msg->ref = concatinfo->ref;
    vm_new_msg->seg = concatinfo->seg;


    vm_log_debug("[SMS]-vm_new_msg msg_id=%d",vm_new_msg->msg_id);
    vm_log_debug("[SMS]-vm_new_msg dest_port=%d",vm_new_msg->dest_port);
    vm_log_debug("[SMS]-vm_new_msg src_port=%d",vm_new_msg->src_port);
    
    vm_log_debug("[SMS]-vm_new_msg message_len=%d",vm_new_msg->message_len);
    vm_log_debug("[SMS]-vm_new_msg ref=%d",vm_new_msg->ref);
    
    vm_log_debug("[SMS]-vm_new_msg number=%s",vm_new_msg->number);
    vm_log_debug("[SMS]-vm_new_msg sc_number=%s",vm_new_msg->sc_number);
    
   
    vm_log_debug("[SMS]-vm_new_msg total_seg=%d",vm_new_msg->total_seg);    
    vm_log_debug("[SMS]-vm_new_msg seg=%d",vm_new_msg->seg); 
    vm_log_debug("[SMS]-vm_new_msg dcs=%d",vm_new_msg->dcs);     
    vm_log_debug("[SMS]-vm_new_msg mti=%d",vm_new_msg->mti); 
    vm_log_debug("[SMS]-vm_new_msg pid=%d",vm_new_msg->pid);
    vm_log_debug("[SMS]-vm_new_msg fo=%d",vm_new_msg->fo);   
    vm_log_debug("[SMS]-vm_new_msg data=%c",vm_new_msg->data);     
    vm_log_debug("[SMS]-vm_new_msg sim_id=%d",vm_new_msg->sim_id);
    vm_log_debug("[SMS]-vm_new_msg storage_type=%d",vm_new_msg->storage_type);     


    vm_log_debug("[SMS]- vm_sms_interrupt_action - begin");
	{/* SMS interuption by daniel.lin */
		VMINT p_state;
		for (p_state=VM_PMNG_FOREGROUND; p_state<=VM_PMNG_BACKGROUND; p_state++)
		{
			VMINT res_size;
			VMINT res_handle = vm_res_findfirst(-1, VM_RES_TYPE_SMS_INTERRUPT);
            vm_log_debug("[SMS]- vm_sms_interrupt_action - p_state:%d, res_handle=%d", p_state, res_handle);
			while ( VM_RES_NOT_FIND != res_handle )
			{
				VmSmsEventFunc cb = NULL;
	            vm_log_debug("[SMS]- vm_sms_interrupt_action - 2 p_state:%d, res_handle=%d", p_state, res_handle);
				if (VM_RES_OK == vm_res_get_data(VM_RES_TYPE_SMS_INTERRUPT, res_handle, (void **)&cb, &res_size) )
				{
					VMINT p_handle = vm_res_get_process_handle(VM_RES_TYPE_SMS_INTERRUPT, res_handle);
	            	vm_log_debug("[SMS]- vm_sms_interrupt_action - 2 p_state:%d, res_handle=%d, p_handle:%d", p_state, res_handle, p_handle);
					if (vm_pmng_state(p_handle) == p_state)
					{
	            		vm_log_debug("[SMS]- vm_sms_interrupt_action - 3 p_state:%d, res_handle=%d, p_handle:%d", p_state, res_handle, p_handle);
				        if (cb && vm_pmng_set_ctx(p_handle) == VM_PMNG_OP_OK)
				        {
				            vm_log_debug("[SMS]- vm_sms_interrupt_action - p_state=%d, cb=%x", p_state, cb);
			                user_res = ((VmSmsEventFunc)cb)(&vm_sms_event_ptr);
				            vm_pmng_reset_ctx();
				        }  
						
				        if (user_res)
				        {
				            if(vm_new_msg)
				                _vm_kernel_free(vm_new_msg);
				            if(vm_event_new_msg_content)
				                _vm_kernel_free(vm_event_new_msg_content);            
				            vm_log_debug("[SMS]- interupted: cb=%x", cb);
							vm_res_findclose(VM_RES_TYPE_SMS_INTERRUPT);
				            return TRUE;                
				        }
					}
				}
				res_handle = vm_res_findnext(-1, VM_RES_TYPE_SMS_INTERRUPT);
			}
			vm_res_findclose(VM_RES_TYPE_SMS_INTERRUPT);
		}
	}
    vm_log_debug("[SMS]- vm_sms_interrupt_action - end");
    
#if 0  
    if (vm_pmng_get_process_lst(VM_PMNG_FOREGROUND, &phandle_lst, &process_num) < 0)
    {
        if(vm_new_msg)
            _vm_kernel_free(vm_new_msg);
        if(vm_event_new_msg_content)
            _vm_kernel_free(vm_event_new_msg_content);
        vm_log_debug("[SMS]-vm_sms_interrupt_event_callback:vm_pmng_get_process_lst VM_PMNG_FOREGROUND error");
        return FALSE;
    }     
    for (i = 0; i < process_num; i++)
    {
        cur_p_handle = (VM_P_HANDLE)*(phandle_lst + i);
        vm_log_debug("[SMS]-vm_sms_interrupt_event_callback:cur_p_handle = %d",cur_p_handle);
        if (!vm_sms_event_registered_by_process(cur_p_handle))
            continue;
        if (vm_res_get_data_list_by_proecss(cur_p_handle, VM_RES_TYPE_SMS_INTERRUPT, &res_node, 1) < 0)
            continue;
        if (vm_pmng_set_ctx(cur_p_handle) == VM_PMNG_OP_OK)
        {
            vm_log_debug("[SMS]-vm_sms_interrupt_event_callback:res_node=%d,%x,%x,size=%d",res_node.res_id,res_node.data_content,res_node.data_content,res_node.data_size);
            if (res_node.data_content)
            {
                user_res = ((VmSmsEventFunc)(res_node.data_content))(&vm_sms_event_ptr);
            }
            vm_pmng_reset_ctx();
        }  
        
        if (user_res)
        {
            if(vm_new_msg)
                _vm_kernel_free(vm_new_msg);
            if(phandle_lst)
                _vm_kernel_free(phandle_lst);
            if(vm_event_new_msg_content)
                _vm_kernel_free(vm_event_new_msg_content);            
            return TRUE;                
        }           
    }
    
    if (phandle_lst)
        _vm_kernel_free(phandle_lst);
    phandle_lst = NULL;
    process_num = 0;
    
    if (vm_pmng_get_process_lst(VM_PMNG_BACKGROUND, &phandle_lst, &process_num) < 0)
    {
        if(vm_new_msg)
            _vm_kernel_free(vm_new_msg);
        if(vm_event_new_msg_content)
            _vm_kernel_free(vm_event_new_msg_content);        
        vm_log_debug("[SMS]-vm_sms_interrupt_event_callback:vm_pmng_get_process_lst VM_PMNG_BACKGROUND error");
        return FALSE;
    } 

    
    for (i = 0; i < process_num; i++)
    {
        cur_p_handle = (VM_P_HANDLE)*(phandle_lst + i);
        if (!vm_sms_event_registered_by_process(cur_p_handle))
            continue;
        if (vm_res_get_data_list_by_proecss(cur_p_handle, VM_RES_TYPE_SMS_INTERRUPT, &res_node, 1) < 0)
            continue;
        if (vm_pmng_set_ctx(cur_p_handle) == VM_PMNG_OP_OK)
        {
            vm_log_debug("[SMS]-vm_sms_interrupt_event_callback:res_node.data_content=%x",res_node.data_content);
            if (res_node.data_content)
            {
                user_res = ((VmSmsEventFunc)(res_node.data_content))(&vm_sms_event_ptr);
            }
            vm_pmng_reset_ctx();
        }  
        
        if (user_res)
        {
            if(vm_new_msg)
                _vm_kernel_free(vm_new_msg);
            if (phandle_lst)
                _vm_kernel_free(phandle_lst);
            if(vm_event_new_msg_content)
                _vm_kernel_free(vm_event_new_msg_content);            
            return TRUE;                
        }           
    }
#endif        
        
    if(vm_new_msg)
        _vm_kernel_free(vm_new_msg);
    if (phandle_lst)
        _vm_kernel_free(phandle_lst);
    if(vm_event_new_msg_content)
        _vm_kernel_free(vm_event_new_msg_content);    
    return FALSE;
}


VMUINT8 vm_sms_interrupt_callback(void *data, void *content)
{
    return FALSE;
}



#ifdef __MMI_DUAL_SIM_MASTER__
#include "mtpnp_ad_master_common_def.h"
#include "mtpnp_ad_master_if.h"
#endif /* __MMI_DUAL_SIM_MASTER__ */ 

#if (defined(__VRE_RB_08A__) || defined(__VRE_RB_08B__))

#include "SmsGuiInterfaceProt.h"//ltz
#endif

 extern VMINT8 sim1_sc_addr[VM_SMS_MAX_ADDR_LEN + 1];
 extern VMINT8 sim2_sc_addr[VM_SMS_MAX_ADDR_LEN + 1];

void vm_sms_sim2_sc_addr_callback(void *data, module_type mod, U16 result);

void vm_sms_sim1_sc_addr_callback(void *data, module_type mod, U16 result)
{

	#ifdef __MMI_DUAL_SIM_MASTER__
#if (defined(__VRE_RB_09A__))
	VMINT16 errorCode2 = 0;
	VMINT8 ProfileIndex2 = 0;
#endif
	#endif
	
	if(vre_running == FALSE)
	{
		return;
	}
	
	switch(result)
	{
		case MMI_FRM_SMS_OK:
	 					
			if(data)
			{
//#if (defined(__VRE_RB_09A__))
#if (defined(__VRE_RB_08B__) || defined(__VRE_RB_08A__))
		
		vm_log_debug("vm_sms_sim1_sc_addr_callback: vm_gb2312_string((VMWSTR)data)=%s", vm_gb2312_string((VMWSTR)((msg_profile_edit_struct *)data)->scAddress));//ltz
			
		vm_ucs2_to_default((VMSTR)sim1_sc_addr, VM_SMS_MAX_ADDR_LEN, (VMWSTR)((msg_profile_edit_struct *)data)->scAddress);//ltz

#else
		vm_log_debug("vm_sms_sim1_sc_addr_callback: vm_gb2312_string((VMWSTR)data)=%s", vm_gb2312_string((VMWSTR)data));
			
		vm_ucs2_to_default((VMSTR)sim1_sc_addr, VM_SMS_MAX_ADDR_LEN, (VMWSTR)data);
				
#endif
			
		vm_log_debug("sim1_sc_addr=%s, strlen(sc_addr)=%d",sim1_sc_addr, strlen(sim1_sc_addr));
		}
		
			break;			        
		default:
			vm_log_error("get sim1_sc_addr fail !");
		   	break;		
		
		
	 }

	#ifdef __MMI_DUAL_SIM_MASTER__

        	MTPNP_AD_Set_Channel(MTPNP_AD_SMS_CHANNEL, MTPNP_AD_CHANNEL_SLAVE);
  		
//#if (defined(__VRE_RB_09A__))
#if (defined(__VRE_RB_08B__) || defined(__VRE_RB_08A__))
		mmi_frm_sms_get_profile_detail(vm_sms_sim2_sc_addr_callback, MOD_MMI, 0);//ltz
#else
		ReadValue(NVRAM_SLAVE_ACTIVE_PROFILE_IDX, &ProfileIndex2, 1, &errorCode2);  
		vm_log_debug("vm_sms_init_sc_addr:ProfileIndex=%d",ProfileIndex2);
		mmi_frm_sms_get_sc_addr(vm_sms_sim2_sc_addr_callback, MOD_MMI,  ProfileIndex2);
#endif
		
	#endif
			
}

void vm_sms_sim2_sc_addr_callback(void *data, module_type mod, U16 result)
{

	if(vre_running == FALSE)
	{
		return;
	}
	
	switch(result)
	{
		case MMI_FRM_SMS_OK:
	 					
			if(data)
			{
//#if (defined(__VRE_RB_09A__))
#if (defined(__VRE_RB_08B__) || defined(__VRE_RB_08A__))
	
		vm_log_debug("vm_sms_sim2_sc_addr_callback: vm_gb2312_string((VMWSTR)data)=%s", vm_gb2312_string((VMWSTR)((msg_profile_edit_struct *)data)->scAddress));//ltz
			
		vm_ucs2_to_default((VMSTR)sim2_sc_addr, VM_SMS_MAX_ADDR_LEN, (VMWSTR)((msg_profile_edit_struct *)data)->scAddress);//ltz
#else
		vm_log_debug("vm_sms_sim2_sc_addr_callback: vm_gb2312_string((VMWSTR)data)=%s", vm_gb2312_string((VMWSTR)data));
			
		vm_ucs2_to_default((VMSTR)sim2_sc_addr, VM_SMS_MAX_ADDR_LEN, (VMWSTR)data);

#endif
			
				vm_log_debug("sim2_sc_addr=%s, strlen(sc_addr)=%d",sim2_sc_addr, strlen(sim2_sc_addr));
		}
		
			break;			        
		default:
			vm_log_error("get sim2_sc_addr fail !");
		   	break;		
		
		
	 }
	
}

void vm_sms_init_sc_addr(void)
{
#if (defined(__VRE_RB_09A__))
	VMINT16 errorCode1 = 0;
	VMINT8 ProfileIndex1 = 0;
#endif
	
	vm_log_debug("vm_sms_init_sc_addr");
	
	#ifdef __MMI_DUAL_SIM_MASTER__

	MTPNP_AD_Set_Channel(MTPNP_AD_SMS_CHANNEL, MTPNP_AD_CHANNEL_MASTER);
	
	#endif
	
//#if (defined(__VRE_RB_09A__))
#if (defined(__VRE_RB_08B__) || defined(__VRE_RB_08A__))
	mmi_frm_sms_get_profile_detail(vm_sms_sim1_sc_addr_callback, MOD_MMI, 0);//ltz
#else
	ReadValue(NVRAM_SMS_ACTIVE_PROFILE_INDEX, &ProfileIndex1, 1, &errorCode1);
	vm_log_debug("vm_sms_init_sc_addr:ProfileIndex=%d",ProfileIndex1);
	mmi_frm_sms_get_sc_addr(vm_sms_sim1_sc_addr_callback, MOD_MMI,  ProfileIndex1);

#endif
   	

}

extern void vm_sms_get_sc_address_callback(void *data, module_type mod, U16 result);
VMINT vm_sal_sms_get_sc_address(vm_sms_sim_enum sim_id, VmSmsCallbackFunc callback)
{	
	VMINT16 errorCode = 0;
	VMINT8 ProfileIndex = 0;
	
	vm_log_debug("vm_sal_sms_get_sc_address:start");
	
	if (mmi_bootup_get_active_flight_mode() == TRUE)
	{
		vm_log_error("vm_sal_sms_get_sc_address: flight mode");
		return VM_SMS_REQ_ERROR;
	}
	
	if (vm_sim_card_count() <= 0)
	{
		vm_log_error("vm_sal_sms_get_sc_address: no sim card");
		return VM_SMS_REQ_ERROR;
	}
 	
    
	#ifdef __MMI_DUAL_SIM_MASTER__
	if (sim_id == VM_SMS_SIM_2)
	{		
		MTPNP_AD_Set_Channel(MTPNP_AD_SMS_CHANNEL, MTPNP_AD_CHANNEL_SLAVE);
//#if (defined(__VRE_RB_09A__))
#if (!defined(__VRE_RB_08A__) && !defined(__VRE_RB_08B__))
		ReadValue(NVRAM_SLAVE_ACTIVE_PROFILE_IDX, &ProfileIndex, 1, &errorCode);  
#endif

		vm_log_debug("vm_sal_sms_get_sc_address:ProfileIndex=%d",ProfileIndex);
	}
	else if(sim_id == VM_SMS_SIM_1)
	{
		MTPNP_AD_Set_Channel(MTPNP_AD_SMS_CHANNEL, MTPNP_AD_CHANNEL_MASTER);
//#if (defined(__VRE_RB_09A__))
#if (!defined(__VRE_RB_08A__) && !defined(__VRE_RB_08B__))
        	ReadValue(NVRAM_SMS_ACTIVE_PROFILE_INDEX, &ProfileIndex, 1, &errorCode);
#endif
		vm_log_debug("vm_sal_sms_get_sc_address:ProfileIndex=%d",ProfileIndex);
	}
	else
	{
		vm_log_error("vm_sal_sms_get_sc_address: sim_id=%d",sim_id);
		return VM_SMS_REQ_ERROR;
	}
	#endif 
	{
		if(sim_id == VM_SMS_SIM_1)
    		{
#if (!defined(__VRE_RB_08A__) && !defined(__VRE_RB_08B__))
    			ReadValue(NVRAM_SMS_ACTIVE_PROFILE_INDEX, &ProfileIndex, 1, &errorCode);
#endif
			vm_log_debug("vm_sal_sms_get_sc_address:ProfileIndex=%d",ProfileIndex);
   	 	}
		else
		{
			vm_log_error("vm_sal_sms_get_sc_address: sim_id=%d",sim_id);
			return VM_SMS_REQ_ERROR;
		}
	}
//#if (defined(__VRE_RB_09A__))
#if (!defined(__VRE_RB_08A__) && !defined(__VRE_RB_08B__))

	mmi_frm_sms_get_sc_addr(vm_sms_get_sc_address_callback, MOD_MMI,  ProfileIndex);
#else
	mmi_frm_sms_get_profile_detail(vm_sms_get_sc_address_callback, MOD_MMI, 0);//ltz

#endif

	vm_log_debug("vm_sal_sms_get_sc_address:end");
	return VM_SMS_REQ_NO_ERROR;
}


/*SMS END*/
#else
/* PHB START*/

#include "vmcontact.h"
#include "PhbSrvGprot.h"

void  vm_phb_build_contact_ptr(vm_phb_contact_struct* contact, srv_phb_sdk_contact_struct * contact_ptr)	
{
	if(contact == NULL || contact_ptr == NULL)
	{
		vm_log_error("vm_phb_build_contact_ptr:contact == NULL || contact_ptr == NULL");        
		return;
	}
	contact->pos.index =contact_ptr->pos.index;
	contact->pos.storage = contact_ptr->pos.storage;
		 
	vm_wstrncpy((VMWSTR)contact->name, (VMWSTR)contact_ptr->name, VM_MAX_PHB_NAME_LENGTH);
	vm_wstrncpy((VMWSTR)contact->number, (VMWSTR)contact_ptr->number, VM_MAX_PHB_NUMBER_LENGTH + 1);
		 
	#if (!defined(__MMI_PHB_NO_OPTIONAL_FIELD__))
	vm_wstrncpy((VMWSTR)contact->home_number, (VMWSTR)contact_ptr->home_number, VM_MAX_PHB_NUMBER_LENGTH + 1);
	vm_wstrncpy((VMWSTR)contact->office_number, (VMWSTR)contact_ptr->office_number, VM_MAX_PHB_NUMBER_LENGTH + 1);
	vm_wstrncpy((VMWSTR)contact->fax_number, (VMWSTR)contact_ptr->fax_number, VM_MAX_PHB_NUMBER_LENGTH + 1);
	vm_wstrncpy((VMWSTR)contact->email_address, (VMWSTR)contact_ptr->email_address, VM_MAX_PHB_EMAIL_LENGTH );
	//vm_log_debug("vm_phb_build_contact_ptr:contact->office_number=%s", vm_gb2312_string((VMWSTR)contact->office_number));
	//vm_log_debug("vm_phb_build_contact_ptr:contact->fax_number=%s", vm_gb2312_string((VMWSTR)contact->fax_number));
		 
	#ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__
	vm_wstrncpy((VMWSTR)contact->email_address2, (VMWSTR)contact_ptr->email_address2, VM_MAX_PHB_EMAIL_LENGTH );
	#endif
		 
	vm_wstrncpy((VMWSTR)contact->company_name, (VMWSTR)contact_ptr->company_name, VM_MAX_PHB_COMPANY_LENGTH);
	#endif

	#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
	contact->birth_day = contact_ptr->birth_day;
	contact->birth_mon = contact_ptr->birth_mon;
	contact->birth_year = contact_ptr->birth_year;
	//vm_log_debug("vm_phb_build_contact_ptr:contact->birth_day=%d, contact->birth_mon=%d, contact->birth_year=%d",contact->birth_day, contact->birth_mon, contact->birth_year);
	#endif
		 
	#if defined(__MMI_PHB_INFO_FIELD__)
	vm_wstrncpy((VMWSTR)contact->title, (VMWSTR)contact_ptr->title, VM_MAX_PHB_TITLE_LENGTH); 
	vm_wstrncpy((VMWSTR)contact->url, (VMWSTR)contact_ptr->url, VM_MAX_PHB_URL_LENGTH); 
	vm_wstrncpy((VMWSTR)contact->adr_pobox, (VMWSTR)contact_ptr->adr_pobox, VM_MAX_PHB_ADDRESS_LENGTH);
	vm_wstrncpy((VMWSTR)contact->adr_extension, (VMWSTR)contact_ptr->adr_extension, VM_MAX_PHB_ADDRESS_LENGTH);
	vm_wstrncpy((VMWSTR)contact->adr_street, (VMWSTR)contact_ptr->adr_street, VM_MAX_PHB_ADDRESS_LENGTH);
	vm_wstrncpy((VMWSTR)contact->adr_city, (VMWSTR)contact_ptr->adr_city, VM_MAX_PHB_ADDRESS_LENGTH);
	vm_wstrncpy((VMWSTR)contact->adr_state, (VMWSTR)contact_ptr->adr_state, VM_MAX_PHB_ADDRESS_LENGTH);
	vm_wstrncpy((VMWSTR)contact->adr_postal_code, (VMWSTR)contact_ptr->adr_postal_code, VM_MAX_PHB_ADDRESS_LENGTH);
	vm_wstrncpy((VMWSTR)contact->adr_country, (VMWSTR)contact_ptr->adr_country, VM_MAX_PHB_ADDRESS_LENGTH);
	vm_wstrncpy((VMWSTR)contact->note, (VMWSTR)contact_ptr->note, VM_MAX_PHB_NOTE_LENGTH);
	#endif
		 
	contact->group_mask = contact_ptr->group_mask;
		 

	vm_log_debug("vm_phb_build_contact_ptr:user_phb_contact->pos.index =%d",contact->pos.index);
	vm_log_debug("vm_phb_build_contact_ptr:user_phb_contact->pos.storage=%d",contact->pos.storage);
	//vm_log_debug("vm_phb_build_contact_ptr:user_phb_contact->name=%s", vm_gb2312_string((VMWSTR)contact->name));
	//vm_log_debug("vm_phb_build_contact_ptr:user_phb_contact->num=%s", vm_gb2312_string((VMWSTR)contact->number));
	   
}

void  vm_phb_build_contact(srv_phb_sdk_contact_struct * contact ,  vm_phb_contact_struct* contact_ptr)	
{
        if(contact == NULL || contact_ptr == NULL)
        {
                vm_log_error("vm_phb_build_contact:contact == NULL || contact_ptr == NULL");        
		  return;
        }
       vm_wstrncpy((VMWSTR)contact->name, (VMWSTR)contact_ptr->name, MMI_PHB_NAME_LENGTH);
	vm_wstrncpy((VMWSTR)contact->number, (VMWSTR)contact_ptr->number, MMI_PHB_NUMBER_PLUS_LENGTH);
	#if (!defined(__MMI_PHB_NO_OPTIONAL_FIELD__))
	vm_wstrncpy((VMWSTR)contact->home_number, (VMWSTR)contact_ptr->home_number, MMI_PHB_NUMBER_PLUS_LENGTH);
	vm_wstrncpy((VMWSTR)contact->office_number, (VMWSTR)contact_ptr->office_number, MMI_PHB_NUMBER_PLUS_LENGTH);
	vm_wstrncpy((VMWSTR)contact->fax_number, (VMWSTR)contact_ptr->fax_number,MMI_PHB_NUMBER_PLUS_LENGTH);
	vm_wstrncpy((VMWSTR)contact->email_address, (VMWSTR)contact_ptr->email_address, MMI_PHB_EMAIL_LENGTH);
	//vm_log_debug("vm_phb_build_contact:contact->office_number=%s", vm_gb2312_string((VMWSTR)contact->office_number));
	//vm_log_debug("vm_phb_build_contact:contact->fax_number=%s", vm_gb2312_string((VMWSTR)contact->fax_number));
	
	#ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__
       vm_wstrncpy((VMWSTR)contact->email_address2, (VMWSTR)contact_ptr->email_address2, MMI_PHB_EMAIL_LENGTH);
	#endif
	
	vm_wstrncpy((VMWSTR)contact->company_name, (VMWSTR)contact_ptr->company_name, MMI_PHB_COMPANY_LENGTH);
	#endif	

	#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
  	contact->birth_day = contact_ptr->birth_day;
	contact->birth_mon = contact_ptr->birth_mon;
	contact->birth_year = contact_ptr->birth_year;
	//vm_log_debug("vm_phb_build_contact:contact->birth_day=%d, contact->birth_mon=%d, contact->birth_year=%d",contact->birth_day, contact->birth_mon, contact->birth_year);
	#endif
	
       #if defined(__MMI_PHB_INFO_FIELD__)
	vm_wstrncpy((VMWSTR)contact->title, (VMWSTR)contact_ptr->title, MMI_PHB_TITLE_LENGTH);
	vm_wstrncpy((VMWSTR)contact->url, (VMWSTR)contact_ptr->url, MMI_PHB_URL_LENGTH);
	vm_wstrncpy((VMWSTR)contact->adr_pobox, (VMWSTR)contact_ptr->adr_pobox, MMI_PHB_ADDRESS_LENGTH);
	vm_wstrncpy((VMWSTR)contact->adr_extension, (VMWSTR)contact_ptr->adr_extension, MMI_PHB_ADDRESS_LENGTH);
	vm_wstrncpy((VMWSTR)contact->adr_street, (VMWSTR)contact_ptr->adr_street, MMI_PHB_ADDRESS_LENGTH);
	vm_wstrncpy((VMWSTR)contact->adr_city, (VMWSTR)contact_ptr->adr_city, MMI_PHB_ADDRESS_LENGTH);
	vm_wstrncpy((VMWSTR)contact->adr_state, (VMWSTR)contact_ptr->adr_state, MMI_PHB_ADDRESS_LENGTH);
	vm_wstrncpy((VMWSTR)contact->adr_postal_code, (VMWSTR)contact_ptr->adr_postal_code, MMI_PHB_ADDRESS_LENGTH);
	vm_wstrncpy((VMWSTR)contact->adr_country, (VMWSTR)contact_ptr->adr_country, MMI_PHB_ADDRESS_LENGTH);
	vm_wstrncpy((VMWSTR)contact->note, (VMWSTR)contact_ptr->note, MMI_PHB_NOTE_LENGTH);
	#endif
	contact->group_mask = contact_ptr->group_mask;

	// vm_log_debug("vm_phb_build_contact:contact->name=%s", vm_gb2312_string((VMWSTR)contact->name));
	 //vm_log_debug("vm_phb_build_contact:contact->number=%s", vm_gb2312_string((VMWSTR)contact->number));

	return;

}

/* PHB END*/
#endif /*#if defined(__VRE_RB_09B__)*/


#include "vmio.h"
/**********chenkang 20100203add for qwerty keypad begin***********/
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
#define VM_SUPPORT_KEY_CODE_NUM			(68)
#else
#define VM_SUPPORT_KEY_CODE_NUM			(22)
#endif
/**********chenkang 20100203add for qwerty keypad end***********/

/* changed by zaiping.chen, 2010.07.12, static memory optimize */
//static short vmtransSysKey2vre [2][VM_SUPPORT_KEY_CODE_NUM] = {
const short vmtransSysKey2vre [2][VM_SUPPORT_KEY_CODE_NUM] = {
	{
		KEY_LEFT_ARROW, 
		KEY_RIGHT_ARROW, 
		KEY_UP_ARROW, 
		KEY_DOWN_ARROW,
		KEY_ENTER, 
		KEY_LSK, 
		KEY_RSK, 
		KEY_0, 
		KEY_1, 
		KEY_2, 
		KEY_3, 
		KEY_4, 
		KEY_5, 
		KEY_6, 
		KEY_7, 
		KEY_8, 
		KEY_9, 
		KEY_STAR, 
		KEY_POUND,
		KEY_VOL_UP, 
		KEY_VOL_DOWN,
		KEY_CLEAR
		/**********chenkang 20100203add for qwerty keypad begin***********/
		#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    		,KEY_A ,
    		KEY_B,
    		KEY_C,
    		KEY_D,
    		KEY_E,
    		KEY_F,
    		KEY_G,
    		KEY_H,
    		KEY_I,
    		KEY_J,
    		KEY_K,
    		KEY_L,
    		KEY_M,
    		KEY_N,
    		KEY_O,
    		KEY_P,
    		KEY_Q,
    		KEY_R,
    		KEY_S,
    		KEY_T,
    		KEY_U,
    		KEY_V,
    		KEY_W,
    		KEY_X,
    		KEY_Y,
    		KEY_Z,
    		KEY_SPACE,
    		KEY_TAB,
    		KEY_DEL,
    		KEY_ALT,
    		KEY_CTRL,
    		KEY_WIN,
    		KEY_SHIFT,
    		KEY_QUESTION,
    		KEY_PERIOD,
    		KEY_COMMA,
    		KEY_EXCLAMATION,
    		KEY_APOSTROPHE,
    		KEY_AT,
    		KEY_BACKSPACE,
    		KEY_QWERTY_ENTER,
    		KEY_FN,
    		KEY_SYMBOL,
    		KEY_NUM_LOCK,
    		KEY_QWERTY_MENU,
    		KEY_OK,
		#endif /* __QWERTY_KEYPAD_SUPPORT__ */
/**********chenkang 20100203add for qwerty keypad end***********/
	},
	{
		VM_KEY_LEFT,
		VM_KEY_RIGHT,
		VM_KEY_UP,
		VM_KEY_DOWN,
		VM_KEY_OK,
		VM_KEY_LEFT_SOFTKEY,
		VM_KEY_RIGHT_SOFTKEY,
		VM_KEY_NUM0,
		VM_KEY_NUM1,
		VM_KEY_NUM2,
		VM_KEY_NUM3,
		VM_KEY_NUM4,
		VM_KEY_NUM5,
		VM_KEY_NUM6,
		VM_KEY_NUM7,
		VM_KEY_NUM8,
		VM_KEY_NUM9,
		VM_KEY_STAR,
		VM_KEY_POUND,
		VM_KEY_VOL_UP,
		VM_KEY_VOL_DOWN,
		VM_KEY_CLEAR
/**********chenkang 20100203add for qwerty keypad begin***********/
		#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    		,VM_KEY_A ,
    		VM_KEY_B,
    		VM_KEY_C,
    		VM_KEY_D,
    		VM_KEY_E,
    		VM_KEY_F,
    		VM_KEY_G,
    		VM_KEY_H,
    		VM_KEY_I,
    		VM_KEY_J,
    		VM_KEY_K,
    		VM_KEY_L,
    		VM_KEY_M,
    		VM_KEY_N,
    		VM_KEY_O,
    		VM_KEY_P,
    		VM_KEY_Q,
    		VM_KEY_R,
    		VM_KEY_S,
    		VM_KEY_T,
    		VM_KEY_U,
    		VM_KEY_V,
    		VM_KEY_W,
    		VM_KEY_X,
    		VM_KEY_Y,
    		VM_KEY_Z,
    		VM_KEY_SPACE,
    		VM_KEY_TAB,
    		VM_KEY_DEL,
    		VM_KEY_ALT,
    		VM_KEY_CTRL,
    		VM_KEY_WIN,
    		VM_KEY_SHIFT,
    		VM_KEY_QUESTION,
    		VM_KEY_PERIOD,
    		VM_KEY_COMMA,
    		VM_KEY_EXCLAMATION,
    		VM_KEY_APOSTROPHE,
    		VM_KEY_AT,
    		VM_KEY_BACKSPACE,
    		VM_KEY_QWERTY_ENTER,
    		VM_KEY_FN,
    		VM_KEY_SYMBOL,
    		VM_KEY_NUM_LOCK,
    		VM_KEY_QWERTY_MENU,
    		VM_KEY_OK,
		#endif /* __QWERTY_KEYPAD_SUPPORT__ */
/**********chenkang 20100203add for qwerty keypad end***********/
	}
};
extern VMINT vm_pmng_deal_key_event(VMINT vmKeyCode, VMINT vmKeyEvent);
static void vm_transfer_sys_2_vre_key(void) 
{
	VMUSHORT sys_keycode, sys_keytype;
	VMINT keycode = 0, keyevent = 0, i = 0;

	GetkeyInfo(&sys_keycode, &sys_keytype);

	/* 先转换KeyEvent */
	switch (sys_keytype)
	{
	case KEY_EVENT_DOWN:
		keyevent = VM_KEY_EVENT_DOWN;
		break;
	case KEY_EVENT_UP:
		keyevent = VM_KEY_EVENT_UP;
		break;
	case KEY_LONG_PRESS:
		keyevent = VM_KEY_EVENT_LONG_PRESS;
		break;
	case KEY_REPEAT:
		keyevent = VM_KEY_EVENT_REPEAT;
		break;
	default:
		// do nothing.
		break;
	}

	for (i = 0; i < VM_SUPPORT_KEY_CODE_NUM; i++)
	{
		if (sys_keycode == vmtransSysKey2vre[0][i])
		{
			keycode = vmtransSysKey2vre[1][i];
			break;
		}
	}

	if (keycode && keyevent)
	{
		vm_pmng_deal_key_event(keycode, keyevent);
	}

}

/**********chenkang 20100203add for qwerty keypad begin***********/
#if !defined(__VRE_RB_08B__)&&!defined(__VRE_RB_08A__) // defined(__VRE_RB_09B__) /*Version control*/
#include "mmi_frm_input_gprot.h"
#endif /*Version control*/
static VMINT16 s_vm_usc2_value;
static VMINT s_vm_special_key_flag;

VMINT vm_sys_qwerty_keypad_is_open(void)
{
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
	return TRUE;
#else
	return FALSE;
#endif
}
void vm_sys_get_usc2_and_special_key(VMINT16* ucs2_value,VMINT* special_key_flag )
{
	if (ucs2_value==NULL || special_key_flag==NULL)
	{
		return;
	}
	*ucs2_value = s_vm_usc2_value;
	*special_key_flag = s_vm_special_key_flag;
}
MMI_BOOL vm_transfer_sys_2_vre_qwerty_key( S16 mmi_key_code,  S16 mmi_key_type, U16 ucs2_value, U32 special_key_flag)
{
	/*
	s_vm_usc2_value = ucs2_value;
	s_vm_special_key_flag = special_key_flag;

	vm_transfer_sys_2_vre_key();
	s_vm_usc2_value = 0;
	s_vm_special_key_flag = 0;
	return TRUE; 
	*/
	VMINT keycode = 0, keyevent = 0, i = 0;

	s_vm_usc2_value = ucs2_value;
	s_vm_special_key_flag = special_key_flag;

	if (mmi_key_code == KEY_END)
	{
		return FALSE;
	}

	/* ?è×a??KeyEvent */
	switch (mmi_key_type)
	{
	case KEY_EVENT_DOWN:
		keyevent = VM_KEY_EVENT_DOWN;
		break;
	case KEY_EVENT_UP:
		keyevent = VM_KEY_EVENT_UP;
		break;
	case KEY_LONG_PRESS:
		keyevent = VM_KEY_EVENT_LONG_PRESS;
		break;
	case KEY_REPEAT:
		keyevent = VM_KEY_EVENT_REPEAT;
		break;
	default:
		// do nothing.
		break;
	}

	for (i = 0; i < VM_SUPPORT_KEY_CODE_NUM; i++)
	{
		if (mmi_key_code == vmtransSysKey2vre[0][i])
		{
			keycode = vmtransSysKey2vre[1][i];
			break;
		}
	}
	vm_log_debug("qwerty key test: sys_keycode=%d,sys_keytype=%d",mmi_key_code,mmi_key_type);
	vm_log_debug("qwerty key test: keycode=%d,keyevent=%d",keycode,keyevent);
	if (keycode && keyevent)
	{
		vm_pmng_deal_key_event(keycode, keyevent);
	}
	s_vm_usc2_value = 0;
	s_vm_special_key_flag = 0;
	return TRUE; 
}
/**********chenkang 20100203add for qwerty keypad end***********/

static void vm_dummy(void)
{
}
void vm_reg_key_handler(void)
{
	/**********chenkang 20100301add for qwerty keypad begin***********/
	#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
	SetKeyHandler((FuncPtr)vm_dummy, KEY_ENTER, KEY_EVENT_DOWN);
	mmi_frm_set_app_translate_key_handler(vm_transfer_sys_2_vre_qwerty_key);
	#else
	/**********chenkang 20100301add for qwerty keypad end***********/
	SetGroupKeyHandler(vm_transfer_sys_2_vre_key, (VMUINT16*)vmtransSysKey2vre[0], 
		VM_SUPPORT_KEY_CODE_NUM, KEY_EVENT_DOWN);
	SetGroupKeyHandler(vm_transfer_sys_2_vre_key, (VMUINT16*)vmtransSysKey2vre[0], 
		VM_SUPPORT_KEY_CODE_NUM, KEY_EVENT_UP);
	SetGroupKeyHandler(vm_transfer_sys_2_vre_key, (VMUINT16*)vmtransSysKey2vre[0], 
		VM_SUPPORT_KEY_CODE_NUM, KEY_LONG_PRESS);
	SetGroupKeyHandler(vm_transfer_sys_2_vre_key, (VMUINT16*)vmtransSysKey2vre[0], 
		VM_SUPPORT_KEY_CODE_NUM, KEY_REPEAT);
#endif
	
}


/*wap start*****************/

extern pBOOL mmi_bootup_get_active_flight_mode(void);
VMINT vm_open_wap_url(VMWSTR url) 
{
#ifdef WAP_SUPPORT
	if (vm_pmng_is_fg(VM_PMNG_CUR_HANDLE))
	{
		if (url == NULL || url[0] == 0) 
		{
			vm_log_debug("[IME MODULE]The ptr of url's string is NULL.");
			return VM_OPEN_WAP_URL_ERROR_PARAM;
		}

		if (mmi_bootup_get_active_flight_mode() == MMI_TRUE)
		{
			vm_log_debug("[IME MODULE]Phone is in flight mode.");
			return VM_OPEN_WAP_URL_NO_SERVICE;
		}

		if (wap_start_browser(WAP_BROWSER_GOTO_URL, (kal_uint8 *)url) != 0)
		{
			vm_log_error("[IME MODULE]open the browser is fail.");
			return VM_OPEN_WAP_URL_NO_SERVICE;
		}

		return VM_OPEN_WAP_URL_SUCCESS;
	}
	
#endif     
	vm_log_warn("[IME MODULE] Current process is not allow to open wap browser.");
	return VM_OPEN_WAP_URL_ERROR_STATUS;
}

/*wap end*****************/

VMINT vm_is_support_camera_sensor(void)
{
	return FALSE;
}

VMUINT vm_get_memory_size(void)
{
	 return sysconf.memory_size ;
}

#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
#include "vmmod.h"
#include "vmcontact.h"
VMINT _vm_reg_phb_module(void)
{
	return REG_VRE_MODULE_SUCCESS;
}
vm_phb_req_error_enum vm_phb_search_contact_syn(vm_phb_search_req_struct* req_info)
{
	return VM_PHB_REQ_NO_ERROR;
}
vm_phb_req_error_enum vm_phb_delete_contact(vm_phb_delete_req_struct* req_info,   vm_phb_callback_type cb)
{
	return VM_PHB_REQ_NO_ERROR;
}
vm_phb_req_error_enum vm_phb_get_contact_syn(vm_phb_get_req_struct* req_info)
{
	return VM_PHB_REQ_NO_ERROR;
}
VMINT vm_phb_get_group_list_count(void)
{
	return 0;
}
vm_phb_req_error_enum vm_phb_search_contact(vm_phb_search_req_struct* req_info,   vm_phb_callback_type cb)
{
	return VM_PHB_REQ_NO_ERROR;
}
VMINT vm_phb_get_total_contacts(vm_phb_storage_loc_enum storage)
{
	return 0;
}
vm_phb_req_error_enum vm_phb_get_contact(vm_phb_get_req_struct* req_info,    vm_phb_callback_type cb)
{
	return VM_PHB_REQ_NO_ERROR;
}
vm_phb_req_error_enum vm_phb_add_contact(vm_phb_add_req_struct* req_info,  vm_phb_callback_type cb)
{
	return VM_PHB_REQ_NO_ERROR;
}
VMINT vm_phb_get_used_contacts(vm_phb_contact_pos_struct* pos_array,  vm_phb_storage_loc_enum storage)
{
	return VM_PHB_REQ_NO_ERROR;
}
VMINT vm_phb_get_used_contacts_count(vm_phb_storage_loc_enum storage)
{
	return 0;
}
VMINT vm_phb_get_group_name_by_id(VMUINT group_id, VMWCHAR*  group_name, VMINT len)
{
	return VM_PHB_REQ_NO_ERROR;
}
vm_phb_req_error_enum vm_phb_update_contact(vm_phb_update_req_struct* req_info,  vm_phb_callback_type cb)
{
	return VM_PHB_REQ_NO_ERROR;
}
VMINT vm_phb_search_contact_list(vm_phb_search_list_req_struct* req_info, vm_phb_contact_pos_struct* pos_array, VMINT post_array_len)
{
	return 0;
}
VMINT vm_phb_get_group_list(vm_phb_group_struct* group_array, VMINT  group_array_len)
{
	return 0;
}

#endif

#endif
