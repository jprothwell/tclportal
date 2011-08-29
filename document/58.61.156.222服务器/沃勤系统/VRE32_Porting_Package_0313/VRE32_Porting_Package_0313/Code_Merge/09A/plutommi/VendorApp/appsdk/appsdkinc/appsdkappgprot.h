/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  SDKMisc.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _SDKMISC_H_
#define _SDKMISC_H_

#include "MMI_features.h"

#include "browser_api.h"

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

/****************************************************************************
 * SmsApi.h
 ****************************************************************************/
#include "SmsApi.h"

extern void mmi_frm_sms_api_entry_write_msg(mmi_frm_sms_api_entry_write_struct *data);
/* this interface is only used by other mudule to send sms */
extern void mmi_frm_sms_send_sms_for_other_app(
                PsFuncPtrU16 callback,
                module_type mod_src,
                mmi_frm_sms_send_struct *sendData);


/****************************************************************************
 * CallManagementGprot.h
 ****************************************************************************/
#include "CallManagementGprot.h"

extern void MakeCall(PS8 strNumber);


/****************************************************************************
 * Ucmgprot.h
 ****************************************************************************/
#include "Ucmgprot.h"

extern void mmi_ucm_app_make_call(mmi_ucm_call_type_enum call_type, U8 *num_uri);


/****************************************************************************
 * gpioInc.h
 ****************************************************************************/
#include "gpioInc.h"
#include "GeneralDeviceGprot.h"

extern void TurnOnBacklight(gpio_backlight_time_enum time_enum);
extern void TurnOffBacklight(void);

/* A macro to play vibration */
#define VibratorOn() mmi_gpio_post_vib_req(KAL_TRUE)

/* A macro to stop vibration */
#define VibratorOff()  mmi_gpio_post_vib_req(KAL_FALSE)

extern U8 mmi_gpio_get_current_backlight_level(MMI_GPIO_LCD_TYPE lcd_type);
extern MMI_BOOL mmi_gpio_get_current_backlight_status(MMI_GPIO_LCD_TYPE lcd_type);


/****************************************************************************
 * Mms_api.h
 ****************************************************************************/
#include "Mms_api.h"
extern void mms_text_insert_hdlr(char * subject, unsigned int subject_len, char * text, unsigned int text_len);


/****************************************************************************
 * App_datetime.h
 ****************************************************************************/
#include "App_datetime.h"

extern void applib_dt_get_date_time(applib_time_struct *t);
extern void applib_dt_get_rtc_time(applib_time_struct *t);
extern kal_uint32 applib_dt_mytime_2_utc_sec(applib_time_struct *currTime, kal_bool daylightSaving);
extern kal_int64 applib_dt_mytime_2_utc_sec_ext(applib_time_struct *currTime, kal_bool daylightSaving);


/****************************************************************************
 * che_api.h
 ****************************************************************************/
#include "che_api.h"

void che_init(STCHE* che_context, kal_uint32 type);
void che_deinit(STCHE* che_context);

#define che_key_action(che_context, key_act, key, key_len)                 \
                                                                           \
   ((void)TRICK_##key_act, run_##key_act##_process(che_context, key, key_len))
void che_set_iv(STCHE* che_context, kal_uint8 *iv, kal_uint32 iv_len);
/* Vogins Start */
#define che_process(che_context, type, mode, act, source, dest, source_length, final)                             \
                                                                                                                  \
   ((void)TRICK_##type, run_##type##_process(che_context, type, mode, act, source, dest, source_length, final, 0))
/* Vogins End */
#define che_process_from_file(che_context, type, mode, act, pstFSAL, dest)                                      \
																													\
	   ((void)TRICK_##type, run_##type##_process(che_context, type, mode, act, 0, dest, 0, 0, pstFSAL)) 				   



/****************************************************************************
 * HistoryGprot_Int.h
 ****************************************************************************/
#include "HistoryGprot_Int.h"

extern void DisplayIdleScreen(void);

/****************************************************************************
 * USBDeviceGprot.h
 ****************************************************************************/
#include "USBDeviceGprot.h"

extern pBOOL mmi_usb_is_in_mass_storage_mode(void);
extern pBOOL mmi_usb_check_path_exported(S8 *path);
void mmi_usb_app_unavailable_popup(U16 stringID);

/****************************************************************************
 * IdleAppProt.h
 ****************************************************************************/
#include "IdleAppProt.h"

extern void mmi_idle_get_dual_sim_status(U8 *sim_status, U8* mode_status);

/****************************************************************************
 * SimDetectionGprot.h
 ****************************************************************************/
#include "SimDetectionGprot.h"

extern pBOOL mmi_bootup_get_active_flight_mode(void);
extern pBOOL mmi_bootup_is_network_service_available(void);

/****************************************************************************
 * Mtpnp_ad_master_common_def.h
 ****************************************************************************/
#ifdef __MMI_DUAL_SIM_MASTER__
#include "Mtpnp_ad_master_common_def.h"

extern E_MTPNP_AD_SIMCARD_USABLE_SIDE MTPNP_AD_Get_UsableSide(void);
#endif

#endif /* _SDKMISC_H_ */ 

