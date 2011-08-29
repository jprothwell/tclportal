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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * wgui_status_icon_bar.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for status icon bars control.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_features.h"
#include "StatusIconRes.h"
#include "WguiCategoryGprot.h"
#include "CustDataRes.h"
#include "wgui_status_icon_bar.h"


#ifdef __MMI_WLAN_FEATURES__
#include "DataAccountResDef.h"
#endif /* __MMI_WLAN_FEATURES__ */

extern S32 MAIN_LCD_device_width;
extern S32 MAIN_LCD_device_height;
extern S32 SUB_LCD_device_width;
extern S32 Sub_lcd_title_height;
extern MMI_BOOL mmi_flight_mode_is_status_icon_visible(S16 icon_ID, U32 icon_flag);

/****************************************************************************
 * Global variable
 ****************************************************************************/

/* The array of status icon */
gui_status_icon_bar_icon_struct wgui_status_icon_bar_icons[MAX_STATUS_ICONS];
/* The array of status icon bar */
gui_status_icon_bar_struct wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_TOTAL_BAR];
/* The array of status icon bar's element */
gui_status_icon_bar_element_struct wgui_status_icon_bar_elements[WGUI_STATUS_ICON_BAR_ELEMENT_NUM];

/* save the icon id of mainlcd horizontal status icon bar */
S32 wgui_status_icon_bar_horizontal_icon_list[WGUI_STATUS_ICON_BAR_MAINLCD_H_ICON_LIST_NUM];
/* save the icon id of mainlcd vertical status icon bar */
S32 wgui_status_icon_bar_vertical_icon_list[WGUI_STATUS_ICON_BAR_MAINLCD_V_ICON_LIST_NUM];
/* save the icon id of sublcd horizontal status icon bar */
S32 wgui_status_icon_bar_sublcd_horizontal_icon_list[WGUI_STATUS_ICON_BAR_SUBLCD_ICON_LIST_NUM];
/* save the element id of mainlcd horizontal status icon bar */
S32 wgui_status_icon_bar_mainlcd_horizontal_element_list[WGUI_STATUS_ICON_BAR_ELEMENT_MAINLCD_H_LIST_NUM];

#ifdef __MMI_LCD_PARTIAL_ON__
S32 wgui_status_icon_bar_partial_list_display[WGUI_STATUS_ICON_BAR_PARTIAL_ICON_LIST_NUM];
S16 wgui_status_icon_bar_partial_display_icon_number;
#endif


/****************************************************************************
 * Local variable
 ****************************************************************************/

/* The array of status icon and image map */
static const wgui_status_icon_bar_icon_image_map_struct wgui_status_icon_bar_icon_image_maps[MAX_STATUS_ICONS]=
{
#ifndef __MMI_DUAL_SIM_MASTER__
    {STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_SIGNAL_STRENGTH, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#else
    {STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_CLOSED, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

    {STATUS_ICON_BATTERY_STRENGTH, IMG_SI_BATTERY_STRENGTH, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},

#ifdef __MMI_DUAL_SIM_MASTER__
    {STATUS_ICON_SLAVE_SIGNAL_STRENGTH, IMG_SI_SLAVE_SIGNAL_CLOSED, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

#ifdef __MMI_CALL_INDICATOR__
    {STATUS_ICON_CALL_INDICATOR, IMG_SI_CALL_INDICATOR_ACTIVE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

#ifdef __MMI_MOBILE_TV_PLAYER__
    {STATUS_ICON_MTV_SIGNAL, IMG_SI_MTV_SIGNAL, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

#ifdef __MMI_WLAN_FEATURES__
    {STATUS_ICON_WLAN_SIGNAL, IMG_ID_DTCNT_WLAN_STATUS_DISCONNECT, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

#ifndef __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__
    {STATUS_ICON_ALTERNATE_LINE_L1, IMG_SI_LINE_L1, GUI_STATUS_ICON_BAR_ICON_LINE_SWITCH_GROUP},
    {STATUS_ICON_ALTERNATE_LINE_L2, IMG_SI_LINE_L2, GUI_STATUS_ICON_BAR_ICON_LINE_SWITCH_GROUP},
#endif

#if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
/* under construction !*/
/* under construction !*/
#endif

#ifdef __MMI_VOIP__
    {STATUS_ICON_VOIP, IMG_SI_VOIP, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif
#ifdef __MMI_AUDIO_PLAYER__
    {STATUS_ICON_AUDPLY, IMG_SI_AUDPLY, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

#ifdef __MMI_MEDIA_PLAYER__
    {STATUS_ICON_MEDPLY, IMG_SI_MEDPLY, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

    {STATUS_ICON_ROAMING, IMG_SI_ROAMING_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#ifdef __MMI_DUAL_SIM_MASTER__
    {STATUS_ICON_SLAVE_ROAMING, IMG_SI_SLAVE_ROAMING_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

    {STATUS_ICON_CALL_DIVERT_L1L2, IMG_SI_CALL_DIVERT_L1L2, GUI_STATUS_ICON_BAR_ICON_CALL_GROUP},
    {STATUS_ICON_CALL_DIVERT_L1, IMG_SI_CALL_DIVERT_L1, GUI_STATUS_ICON_BAR_ICON_CALL_GROUP},
    {STATUS_ICON_CALL_DIVERT_L2, IMG_SI_CALL_DIVERT_L2, GUI_STATUS_ICON_BAR_ICON_CALL_GROUP},
#ifdef __MMI_DUAL_SIM_MASTER__
    {STATUS_ICON_SLAVE_CALLFORWARD, IMG_SLAVE_CALL_FORWARD, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_SLAVE_CALLFORWARD_L1, IMG_SLAVE_CALL_FORWARD_L1, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_SLAVE_CALLFORWARD_L2, IMG_SLAVE_CALL_FORWARD_L2, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

    {STATUS_ICON_MUTE, IMG_SI_MUTE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},

    {STATUS_ICON_INCOMING_SMS, IMG_SI_SMS_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#ifdef __MMI_DUAL_SIM_MASTER__
    {STATUS_ICON_SLAVE_INCOMING_SMS, IMG_SI_SLAVE_SMS_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

    {STATUS_ICON_MMS_UNREAD, IMG_SI_MMS_UNREAD_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_MMS_BUSY, IMG_SI_MMS_BUSY_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#ifdef __MMI_DUAL_SIM_MASTER__
    {STATUS_ICON_MMS_UNREAD_SIM_1, IMG_SI_MMS_UNREAD_INDICATOR_SIM1, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_MMS_UNREAD_SIM_2, IMG_SI_MMS_UNREAD_INDICATOR_SIM2, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_MMS_BUSY_SIM_1, IMG_SI_MMS_BUSY_INDICATOR_SIM1, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_MMS_BUSY_SIM_2, IMG_SI_MMS_BUSY_INDICATOR_SIM2, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    {STATUS_ICON_OUTBOX_INDICATOR, IMG_SI_OUTBOX_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

    {STATUS_ICON_SMS_SENDING, IMG_SI_SMS_SENDING, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},

    {STATUS_ICON_VIBRATION, IMG_SI_VIBRATE, GUI_STATUS_ICON_BAR_ICON_RING_GROUP},
    {STATUS_ICON_SILENT, IMG_SI_SILENT, GUI_STATUS_ICON_BAR_ICON_RING_GROUP},
    {STATUS_ICON_RING, IMG_SI_RING, GUI_STATUS_ICON_BAR_ICON_RING_GROUP},
    {STATUS_ICON_VIBRATE_AND_RING, IMG_SI_VIBRATE_AND_RING, GUI_STATUS_ICON_BAR_ICON_RING_GROUP},
    {STATUS_ICON_VIBRATE_THEN_RING, IMG_SI_VIBRATE_THEN_RING, GUI_STATUS_ICON_BAR_ICON_RING_GROUP},

#ifndef __MMI_DUAL_SIM_MASTER__
    {STATUS_ICON_CSD, IMG_SI_CSD, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_EDGE, IMG_SI_EDGE, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_GPRS_SERVICE, IMG_SI_GPRS_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_EDGEC, IMG_SI_EDGEC, GUI_STATUS_ICON_BAR_ICON_NETWORK1_GROUP},
    {STATUS_ICON_GPRS_ATT_NO_PDP_INDICATOR, IMG_SI_GPRS_ATT_NO_PDP_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NETWORK1_GROUP},
#else
    {STATUS_ICON_CSD, IMG_SI_CSD_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_EDGE, IMG_SI_EDGE_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_GPRS_SERVICE, IMG_SI_GPRS_SERVICE_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_EDGEC, IMG_SI_EDGEC_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK1_GROUP},
    {STATUS_ICON_GPRS_ATT_NO_PDP_INDICATOR, IMG_SI_GPRS_ATT_NO_PDP_INDICATOR_SIM1, GUI_STATUS_ICON_BAR_ICON_NETWORK1_GROUP},

    {STATUS_ICON_SLAVE_CSD, IMG_SI_CSD_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SLAVE_EDGE, IMG_SI_EDGE_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SLAVE_GPRS_SERVICE, IMG_SI_GPRS_SERVICE_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK_GROUP},
    {STATUS_ICON_SLAVE_EDGEC, IMG_SI_EDGEC_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK1_GROUP},
    {STATUS_ICON_SLAVE_GPRS_ATT_NO_PDP_INDICATOR, IMG_SI_GPRS_ATT_NO_PDP_INDICATOR_SIM2, GUI_STATUS_ICON_BAR_ICON_NETWORK1_GROUP},
#endif

#if (defined(OBIGO_Q05A) || defined(JATAAYU_SUPPORT)) && defined(WAP_SUPPORT)
    {STATUS_ICON_SECURITY, IMG_SI_SECURITY, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

    {STATUS_ICON_EARPHONE_INDICATOR, IMG_SI_EARPHONE_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_ALARM, IMG_SI_ALARM_ACTIVATED, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_VOICE_RECORD, IMG_SI_VOICE_RECORD, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_KEYPAD_LOCK, IMG_SI_KEYPAD_LOCK, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},

#ifndef __MMI_DUAL_SIM_MASTER__
    {STATUS_ICON_MISSED_CALL, IMG_SI_MISSED_CALL_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#else
    {STATUS_ICON_MISSED_CALL, IMG_SI_CARD1MISSED_CALL_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_CARD2MISSED_CALL, IMG_SI_CARD2MISSED_CALL_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

    {STATUS_ICON_UNREAD_EMAIL, IMG_SI_UNREAD_EMAIL, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},

    {STATUS_ICON_UNREAD_VOICE_L1L2,IMG_SI_UNREAD_VOICE_L1L2, GUI_STATUS_ICON_BAR_ICON_VOICE_GROUP},
    {STATUS_ICON_UNREAD_VOICE_L1, IMG_SI_UNREAD_VOICE_L1, GUI_STATUS_ICON_BAR_ICON_VOICE_GROUP},
    {STATUS_ICON_UNREAD_VOICE_L2, IMG_SI_UNREAD_VOICE_L2, GUI_STATUS_ICON_BAR_ICON_VOICE_GROUP},
    {STATUS_ICON_UNREAD_FAX_L1L2, IMG_SI_UNREAD_FAX_L1L2, GUI_STATUS_ICON_BAR_ICON_FAX_GROUP},
    {STATUS_ICON_UNREAD_FAX_L1, IMG_SI_UNREAD_FAX_L1, GUI_STATUS_ICON_BAR_ICON_FAX_GROUP},
    {STATUS_ICON_UNREAD_FAX_L2, IMG_SI_UNREAD_FAX_L2, GUI_STATUS_ICON_BAR_ICON_FAX_GROUP},
    {STATUS_ICON_UNREAD_EMAIL_L1L2, IMG_SI_UNREAD_EMAIL_L1L2, GUI_STATUS_ICON_BAR_ICON_EMAIL_GROUP},
    {STATUS_ICON_UNREAD_EMAIL_L1, IMG_SI_UNREAD_EMAIL_L1, GUI_STATUS_ICON_BAR_ICON_EMAIL_GROUP},
    {STATUS_ICON_UNREAD_EMAIL_L2, IMG_SI_UNREAD_EMAIL_L2, GUI_STATUS_ICON_BAR_ICON_EMAIL_GROUP},
    {STATUS_ICON_UNREAD_NET_L1, IMG_SI_UNREAD_NET_L1, GUI_STATUS_ICON_BAR_ICON_NET_GROUP},
    {STATUS_ICON_UNREAD_NET_L2, IMG_SI_UNREAD_NET_L2, GUI_STATUS_ICON_BAR_ICON_NET_GROUP},
    {STATUS_ICON_UNREAD_NET_L1L2, IMG_SI_UNREAD_NET_L1L2, GUI_STATUS_ICON_BAR_ICON_NET_GROUP},
    {STATUS_ICON_UNREAD_VIDEO_L1, IMG_SI_UNREAD_VIDEO_L1, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_VIDEO_L2, IMG_SI_UNREAD_VIDEO_L2, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_VIDEO_L1L2, IMG_SI_UNREAD_VIDEO_L1L2, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#ifdef __MMI_DUAL_SIM_MASTER__
    {STATUS_ICON_UNREAD_VOICE_L1_MASTER, IMG_SI_UNREAD_VOICE_L1_MASTER, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_VOICE_L2_MASTER, IMG_SI_UNREAD_VOICE_L2_MASTER, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_VOICE_L1L2_MASTER, IMG_SI_UNREAD_VOICE_L1L2_MASTER, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_FAX_L1_MASTER, IMG_SI_UNREAD_FAX_L1_MASTER, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_FAX_L2_MASTER, IMG_SI_UNREAD_FAX_L2_MASTER, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_FAX_L1L2_MASTER, IMG_SI_UNREAD_FAX_L1L2_MASTER, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_EMAIL_L1_MASTER, IMG_SI_UNREAD_EMAIL_L1_MASTER, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_EMAIL_L2_MASTER, IMG_SI_UNREAD_EMAIL_L2_MASTER, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_EMAIL_L1L2_MASTER, IMG_SI_UNREAD_EMAIL_L1L2_MASTER, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_NET_L1_MASTER, IMG_SI_UNREAD_NET_L1_MASTER, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_NET_L2_MASTER, IMG_SI_UNREAD_NET_L2_MASTER, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_NET_L1L2_MASTER, IMG_SI_UNREAD_NET_L1L2_MASTER, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_VIDEO_L1_MASTER, IMG_SI_UNREAD_VIDEO_L1_MASTER, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_VIDEO_L2_MASTER, IMG_SI_UNREAD_VIDEO_L2_MASTER, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_VIDEO_L1L2_MASTER, IMG_SI_UNREAD_VIDEO_L1L2_MASTER, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},

    {STATUS_ICON_UNREAD_VOICE_L1_SLAVE, IMG_SI_UNREAD_VOICE_L1_SLAVE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_VOICE_L2_SLAVE, IMG_SI_UNREAD_VOICE_L2_SLAVE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_VOICE_L1L2_SLAVE, IMG_SI_UNREAD_VOICE_L1L2_SLAVE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_FAX_L1_SLAVE, IMG_SI_UNREAD_FAX_L1_SLAVE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_FAX_L2_SLAVE, IMG_SI_UNREAD_FAX_L2_SLAVE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_FAX_L1L2_SLAVE, IMG_SI_UNREAD_FAX_L1L2_SLAVE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_EMAIL_L1_SLAVE, IMG_SI_UNREAD_EMAIL_L1_SLAVE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_EMAIL_L2_SLAVE, IMG_SI_UNREAD_EMAIL_L2_SLAVE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_EMAIL_L1L2_SLAVE, IMG_SI_UNREAD_EMAIL_L1L2_SLAVE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_NET_L1_SLAVE, IMG_SI_UNREAD_NET_L1_SLAVE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_NET_L2_SLAVE, IMG_SI_UNREAD_NET_L2_SLAVE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_NET_L1L2_SLAVE, IMG_SI_UNREAD_NET_L1L2_SLAVE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_VIDEO_L1_SLAVE, IMG_SI_UNREAD_VIDEO_L1_SLAVE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_VIDEO_L2_SLAVE, IMG_SI_UNREAD_VIDEO_L2_SLAVE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_UNREAD_VIDEO_L1L2_SLAVE, IMG_SI_UNREAD_VIDEO_L1L2_SLAVE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

#ifdef __MMI_AUTO_ANSWER_MACHINE__
    {STATUS_ICON_AUTOAM_REC, IMG_SI_AUTOAM_REC, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_AUTOAM_UNREAD, IMG_SI_AUTOAM_UNREAD, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_AUTOAM_ON, IMG_SI_AUTOAM_ON, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

    {STATUS_ICON_IMPS_MSG, IMG_SI_IMPS_MSG, GUI_STATUS_ICON_BAR_ICON_IMPS_GROUP},
    {STATUS_ICON_IMPS_LOGIN, IMG_SI_IMPS_LOGIN, GUI_STATUS_ICON_BAR_ICON_IMPS_GROUP},

#ifdef __MMI_DUAL_SIM_MASTER__
    {STATUS_ICON_WAP1, IMG_SI_WAP1, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_WAP2, IMG_SI_WAP2, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#else
    {STATUS_ICON_WAP, IMG_SI_WAP, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

    {STATUS_ICON_POC, IMG_SI_POC, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_BT, IMG_SI_BT, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_BT_CON, IMG_SI_BT_CON, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_BT_ND, IMG_SI_BT_ND, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_IR, IMG_SI_IR_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_STOP_WATCH, IMG_SI_STOPWATCH, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},

#ifdef __MMI_DUAL_SIM_MASTER__
    {STATUS_ICON_NETWORK_CIPHER_GSM, IMG_SI_MASTER_NETWORK_CIPHER_GSM, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_SLAVE_NETWORK_CIPHER_GSM, IMG_SI_SLAVE_NETWORK_CIPHER_GSM, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#else
    {STATUS_ICON_NETWORK_CIPHER_GSM, IMG_SI_NETWORK_CIPHER_GSM, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

    {STATUS_ICON_NETWORK_CIPHER_GPRS, IMG_SI_NETWORK_CIPHER_GPRS, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},

#if defined(__J2ME__) && defined(J2ME_SUPPORT_BACKGROUND)
    {STATUS_ICON_JAVA_BG_VM, IMG_SI_JAVA_BG_VM, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_JAVA_BG_VM_AUDIO, IMG_SI_JAVA_BG_VM_AUDIO, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

#ifdef __MMI_BG_SOUND_EFFECT__
    {STATUS_ICON_BG_SOUND, IMG_SI_BGSND, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

#ifdef __MMI_AUDIO_REVERB_EFFECT__
    {STATUS_ICON_REVERB_SOUND, IMG_SI_REVERBSND, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

#ifdef __MMI_AUDIO_SURROUND_EFFECT__
    {STATUS_ICON_AUD_SURROUND, IMG_SI_SURROUNDSND, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

#ifdef __MMI_HOMEZONE_STATUS_ICON__
    {STATUS_ICON_HOMEZONE, IMG_SI_HZONE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#ifdef __MMI_DUAL_SIM_MASTER__
    {STATUS_ICON_SLAVE_HOMEZONE, IMG_SI_HZONE_SLAVE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif
    {STATUS_ICON_CITYZONE, IMG_SI_CZONE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif /* __MMI_HOMEZONE_STATUS_ICON__ */

#ifdef __CTM_SUPPORT__
    {STATUS_ICON_TTY_INDICATOR, IMG_SI_TTY_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

    {STATUS_ICON_EMAIL_REF, IMG_SI_EMAIL_REF, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},

#ifdef __MMI_PICT_BRIDGE_SUPPORT__
    {STATUS_ICON_PRINT, IMG_SI_PRINT, GUI_STATUS_ICON_BAR_ICON_PRINT_GROUP},
    {STATUS_ICON_PRINT_FAIL, IMG_SI_PRINT_FAIL, GUI_STATUS_ICON_BAR_ICON_PRINT_GROUP},
#endif

#if defined(__AGPS_SUPPORT__) && defined(__SUPL_SUPPORT__)
    {STATUS_ICON_AGPS_STATE, IMG_SI_AGPS_STATE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

#ifdef __MMI_SYNCML_STATUS_ICON_SUPPORT__
    {STATUS_ICON_SYNCML, IMG_SI_SYNCML, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif

#ifdef __MMI_PROV_MESSAGE_SUPPORT__
    {STATUS_ICON_PROVMSG_STATE, IMG_SI_PROVMSG, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#ifdef __MMI_DUAL_SIM_MASTER__
    {STATUS_ICON_PROVMSG_SIM1, IMG_SI_PROVMSG_SIM1, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_PROVMSG_SIM2, IMG_SI_PROVMSG_SIM2, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif
#endif

#if defined(__QQIM_SUPPORT__)
    {STATUS_ICON_QQIM_AWAY, IMG_SI_QQIM_AWAY, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_QQIM_INVISIBLE, IMG_SI_QQIM_INVISIBLE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_QQIM_MSG, IMG_SI_QQIM_MSG, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_QQIM_OFFLINE, IMG_SI_QQIM_OFFLINE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_QQIM_ONLINE, IMG_SI_QQIM_ONLINE, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif
/* Vogins Start */
#ifdef __VRE30_AM__
    {STATUS_ICON_VRE_DEFAULT, IMG_SI_VRE_DEFAULT, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_VRE_1, IMG_SI_VRE_DEFAULT, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_VRE_2, IMG_SI_VRE_DEFAULT, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_VRE_3, IMG_SI_VRE_DEFAULT, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_VRE_4, IMG_SI_VRE_DEFAULT, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
#endif
/* Vogins End */
    /* Sublcd start */
    {STATUS_ICON_SUBLCD_SIGNAL_STRENGTH, IMG_SLSI_SIGNAL_STRENGTH, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_SUBLCD_BATTERY_STRENGTH, IMG_SLSI_BATTERY_STRENGTH, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_SUBLCD_SMS, IMG_SLSI_SMS_INDICATOR, GUI_STATUS_ICON_BAR_ICON_NO_GROUP},
    {STATUS_ICON_SUBLCD_RING, IMG_SLSI_RING, GUI_STATUS_ICON_BAR_ICON_SUBLCD_RING_GROUP},
    {STATUS_ICON_SUBLCD_VIBRATE, IMG_SLSI_VIBRATE, GUI_STATUS_ICON_BAR_ICON_SUBLCD_RING_GROUP},
    {STATUS_ICON_SUBLCD_VIBRATE_AND_RING, IMG_SLSI_VIBRATE_AND_RING, GUI_STATUS_ICON_BAR_ICON_SUBLCD_RING_GROUP},
    {STATUS_ICON_SUBLCD_VIBRATE_THEN_RING, IMG_SLSI_VIBRATE_THEN_RING, GUI_STATUS_ICON_BAR_ICON_SUBLCD_RING_GROUP},
    {STATUS_ICON_SUBLCD_SILENT, IMG_SLSI_SILENT, GUI_STATUS_ICON_BAR_ICON_SUBLCD_RING_GROUP},
    {STATUS_ICON_SUBLCD_ALARM, IMG_SLSI_ALARM, GUI_STATUS_ICON_BAR_ICON_CALL_GROUP},
    {STATUS_ICON_SUBLCD_MISSED_CALL, IMG_SLSI_MISSED_CALL, GUI_STATUS_ICON_BAR_ICON_CALL_GROUP}
};


static MMI_BOOL wgui_status_icon_bar_integrated_enable = MMI_FALSE;
static void (*wgui_status_icon_bar_integrated_redraw)(void) = NULL;
static MMI_BOOL wgui_status_icon_bar_need_arrange = MMI_TRUE;
static MMI_BOOL wgui_status_icon_bar_need_initialize = MMI_TRUE;
static S32 wgui_status_icon_bar_clock_element_id = WGUI_STATUS_ICON_BAR_INVALID_ELEMENT_ID;
static U32 wgui_status_icon_bar_clock_index = WGUI_CLOCK_INVALID_INDEX;
static void (*wgui_status_icon_bar_update_callback)(void);


/****************************************************************************
 * Local function
 ****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_whether_have_blink_or_animate_icon
 * DESCRIPTION
 *  To check whether there are some icon set blink or animate flag
 * PARAMETERS
 *  void
 * RETURNS
 *  Whether have some icon set blink or animate flag
 *****************************************************************************/
static MMI_BOOL wgui_status_icon_bar_whether_have_blink_or_animate_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 bar_id;
    gui_status_icon_bar_struct *bar;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (bar_id = WGUI_STATUS_ICON_BAR_H_BAR;
         bar_id < WGUI_STATUS_ICON_BAR_TOTAL_BAR;
         bar_id++)
    {
        bar = &wgui_status_icon_bar_bars[bar_id];
        for (i = 0; i < bar->n_icons; i++)
        {
            if ((wgui_status_icon_bar_icons[bar->icon_list[i]].flags & GUI_STATUS_ICON_BAR_ICON_ANIMATE) ||
                (wgui_status_icon_bar_icons[bar->icon_list[i]].flags & GUI_STATUS_ICON_BAR_ICON_BLINK))
            {
                return MMI_TRUE;
            }
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_icon_blink_and_animate_timer_callback
 * DESCRIPTION
 *  The timer callback function of status icon blink and animate
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_status_icon_bar_icon_blink_and_animate_timer_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_STATUS_ICONS; i++)
    {
        if (wgui_status_icon_bar_icons[i].flags & GUI_STATUS_ICON_BAR_ICON_ANIMATE)
        {
            wgui_status_icon_bar_icons[i].current_frame++;
            if (wgui_status_icon_bar_icons[i].current_frame >= wgui_status_icon_bar_icons[i].n_frames)
            {
                wgui_status_icon_bar_icons[i].current_frame = 0;
            }
        }
        else if (wgui_status_icon_bar_icons[i].flags & GUI_STATUS_ICON_BAR_ICON_BLINK)
        {
            wgui_status_icon_bar_icons[i].flags ^= GUI_STATUS_ICON_BAR_ICON_BLINK_ON;
        }
    }

#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
    if (!((wgui_status_icon_bar_get_flag(WGUI_STATUS_ICON_BAR_H_BAR) & WGUI_STATUS_ICON_BAR_FLAG_BAR_DISPLAY))&&
        wgui_status_icon_bar_integrated_enable)
    {
        if (wgui_status_icon_bar_integrated_redraw)
        {
            wgui_status_icon_bar_integrated_redraw();
        }
        gui_start_timer(WGUI_STATUS_ICON_BAR_TIMER_RATE, wgui_status_icon_bar_icon_blink_and_animate_timer_callback);
    }
    else
#endif
    {
        wgui_status_icon_bar_update();
        gui_start_timer(
            WGUI_STATUS_ICON_BAR_TIMER_RATE,
            wgui_status_icon_bar_icon_blink_and_animate_timer_callback);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_setup_blink_animate
 * DESCRIPTION
 *  Start or stop the timer for blinking or animating icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_status_icon_bar_setup_blink_animate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_status_icon_bar_whether_have_blink_or_animate_icon())
    {
        gui_start_timer(
            WGUI_STATUS_ICON_BAR_TIMER_RATE,
            wgui_status_icon_bar_icon_blink_and_animate_timer_callback);
    }
    else
    {
        gui_cancel_timer(wgui_status_icon_bar_icon_blink_and_animate_timer_callback);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_refresh_fixed_icon
 * DESCRIPTION
 *  Refresh the fixed icon in status icon bar, only for signal or battery icon
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 *  icon_id         [IN]        The id of status icon
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_status_icon_bar_refresh_fixed_icon(wgui_status_icon_bar_enum bar_id, S32 icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y, width, height;
    S32 x1, y1, x2, y2;
    S32 old_x1, old_y1, old_x2, old_y2;
    gui_status_icon_bar_struct *bar;
    gui_status_icon_bar_icon_struct *icon;
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bar = &wgui_status_icon_bar_bars[bar_id];
    icon = &wgui_status_icon_bar_icons[icon_id];
    if (bar->flags & WGUI_STATUS_ICON_BAR_FLAG_BAR_DISPLAY)
    {
        gui_status_icon_bar_get_icon_size(icon, &width, &height);
        gui_status_icon_bar_get_icon_position(icon, &x, &y);
        x1 = bar->x + x;
        y1 = bar->y + y;
        x2 = x1 + width - 1;
        y2 = y1 + height - 1;
        old_lcd_handle = gui_status_icon_bar_setup_target_lcd_and_layer(bar);
        wgui_status_icon_bar_get_clip(bar_id, &old_x1, &old_y1, &old_x2, &old_y2);
        wgui_status_icon_bar_set_clip(bar_id, x1, y1, x2, y2);
        if(gui_status_icon_bar_hide)
        {
            gui_status_icon_bar_hide(&wgui_status_icon_bar_bars[bar_id]);
        }
        wgui_status_icon_bar_set_clip(bar_id, old_x1, old_y1, old_x2, old_y2);
        gdi_layer_push_clip();
        gdi_layer_set_clip(x1, y1, x2, y2);
        if(gui_status_icon_bar_show_icon)
        {
            gui_status_icon_bar_show_icon(bar, icon);
        }
        gdi_layer_pop_clip();

    #ifdef __MMI_VUI_ENGINE__
        if ((bar_id == WGUI_STATUS_ICON_BAR_H_BAR)
            &&(wgui_status_icon_bar_bars[bar_id].venus_update_screen_callback != NULL))
        {
            wgui_status_icon_bar_bars[bar_id].venus_update_screen_callback(wgui_status_icon_bar_bars[bar_id].venus_update_screen_handle);
        }
        else
        {
    #endif
            gdi_layer_blt_previous(x1, y1, x2, y2);
    #ifdef __MMI_VUI_ENGINE__
        }
    #endif

        if (wgui_status_icon_bar_whether_double_buffer(bar_id))
        {
            gdi_layer_push_and_set_active(wgui_status_icon_bar_get_target_layer(bar_id));
            gdi_layer_toggle_double();
            gdi_layer_copy_double();
            gdi_layer_pop_and_restore_active();
        }
        gui_status_icon_bar_restore_target_lcd_and_layer(bar, old_lcd_handle);
    }
}


#ifdef WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT

/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_time_small_hide_callback
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_status_icon_bar_time_small_hide_callback(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cx1, cy1, cx2, cy2;
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    old_lcd_handle =
        gui_status_icon_bar_setup_target_lcd_and_layer(
            &wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR]);
    wgui_status_icon_bar_get_clip(WGUI_STATUS_ICON_BAR_H_BAR, &cx1, &cy1, &cx2, &cy2);
    wgui_status_icon_bar_set_clip(WGUI_STATUS_ICON_BAR_H_BAR, x1, y1, x2, y2);
    if(gui_status_icon_bar_hide)
    {
        gui_status_icon_bar_hide(&wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR]);
    }
    wgui_status_icon_bar_set_clip(WGUI_STATUS_ICON_BAR_H_BAR, cx1, cy1, cx2, cy2);
    gui_status_icon_bar_restore_target_lcd_and_layer(
        &wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR],
        old_lcd_handle);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_close_clock_callback
 * DESCRIPTION
 *  When other application close status icon bar's clock, this function will be call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_status_icon_bar_close_clock_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_clock_index = WGUI_CLOCK_INVALID_INDEX;
}


#endif /* WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT */


/****************************************************************************
 * Global function
 ****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_set_rotate_for_wap
 * DESCRIPTION
 *  Set the mainlcd horizontal status icon bar's rotate for wap
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_set_rotate_for_wap(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_enable_rotate_for_wap(
        &wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR],
        MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_reset_rotate_for_wap
 * DESCRIPTION
 *  Reset the mainlcd horizontal status icon bar's rotate flag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_reset_rotate_for_wap(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_enable_rotate_for_wap(
        &wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR],
        MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_set_display
 * DESCRIPTION
 *  Set the status icon bar's display flag
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_set_display(wgui_status_icon_bar_enum bar_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
    if (bar_id == WGUI_STATUS_ICON_BAR_SUBLCD_H_BAR)
    {
        return;
    }
#endif

    gui_status_icon_bar_enable_display(
        &wgui_status_icon_bar_bars[bar_id],
        MMI_TRUE);
#ifdef WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT
    if ((bar_id == WGUI_STATUS_ICON_BAR_H_BAR) &&
        (wgui_status_icon_bar_clock_element_id != WGUI_STATUS_ICON_BAR_INVALID_ELEMENT_ID) &&
        (wgui_status_icon_bar_clock_index == WGUI_CLOCK_INVALID_INDEX))
    {
        wgui_clock_create(
            &wgui_status_icon_bar_clock_index,
            wgui_status_icon_bar_elements[wgui_status_icon_bar_clock_element_id].x + wgui_status_icon_bar_bars[bar_id].x,
            wgui_status_icon_bar_elements[wgui_status_icon_bar_clock_element_id].y + wgui_status_icon_bar_bars[bar_id].y,
            wgui_status_icon_bar_elements[wgui_status_icon_bar_clock_element_id].width,
            wgui_status_icon_bar_elements[wgui_status_icon_bar_clock_element_id].height,
            GUI_CLOCK_MAINLCD_TYPE_DIGITAL_TIME_SMALL);
        wgui_clock_set_hide_function(wgui_status_icon_bar_clock_index, wgui_status_icon_bar_time_small_hide_callback);
        wgui_clock_set_close_callback(wgui_status_icon_bar_clock_index, wgui_status_icon_bar_close_clock_callback);
    }
#endif /* WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_reset_display
 * DESCRIPTION
 *  Reset the status icon bar's display flag
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_reset_display(wgui_status_icon_bar_enum bar_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_enable_display(
        &wgui_status_icon_bar_bars[bar_id],
        MMI_FALSE);

#ifdef WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT
    if ((bar_id == WGUI_STATUS_ICON_BAR_H_BAR) &&
        (wgui_status_icon_bar_clock_index != WGUI_CLOCK_INVALID_INDEX))
    {
        wgui_clock_close(wgui_status_icon_bar_clock_index);
        wgui_status_icon_bar_clock_index = WGUI_CLOCK_INVALID_INDEX;
    }
#endif /* WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_set_background
 * DESCRIPTION
 *  Set the status icon bar background eanble
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_set_background(wgui_status_icon_bar_enum bar_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_enable_background(
        &wgui_status_icon_bar_bars[bar_id],
        MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_reset_background
 * DESCRIPTION
 *  Reset the status icon bar background eanble
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_reset_background(wgui_status_icon_bar_enum bar_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_enable_background(
        &wgui_status_icon_bar_bars[bar_id],
        MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_set_double_buffer
 * DESCRIPTION
 *  Set the status icon bar's double buffer flag
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 * RETURNS
 *
 *****************************************************************************/
void wgui_status_icon_bar_set_double_buffer(wgui_status_icon_bar_enum bar_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_enable_double_buffer(
        &wgui_status_icon_bar_bars[bar_id],
        MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_reset_double_buffer
 * DESCRIPTION
 *  Set the status icon bar's double buffer flag
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 * RETURNS
 *
 *****************************************************************************/
void wgui_status_icon_bar_reset_double_buffer(wgui_status_icon_bar_enum bar_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_enable_double_buffer(
        &wgui_status_icon_bar_bars[bar_id],
        MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_whether_double_buffer
 * DESCRIPTION
 *  To check the status icon bar's double buffer flag set or not
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 * RETURNS
 *
 *****************************************************************************/
MMI_BOOL wgui_status_icon_bar_whether_double_buffer(wgui_status_icon_bar_enum bar_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gui_status_icon_bar_whether_double_buffer(&wgui_status_icon_bar_bars[bar_id]);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_set_flag
 * DESCRIPTION
 *  Set status icon bar's flag
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 *  flag            [IN]        New flag of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_set_flag(wgui_status_icon_bar_enum bar_id, U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
    if (bar_id == WGUI_STATUS_ICON_BAR_SUBLCD_H_BAR)
    {
        return;
    }
#endif

    gui_status_icon_bar_set_flag(
        &wgui_status_icon_bar_bars[bar_id],
        flag);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_get_flag
 * DESCRIPTION
 *  Get status icon bar's flag
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 * RETURNS
 *  The flag of status icon bar
 *****************************************************************************/
U32 wgui_status_icon_bar_get_flag(wgui_status_icon_bar_enum bar_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gui_status_icon_bar_get_flag(&wgui_status_icon_bar_bars[bar_id]);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_set_clip
 * DESCRIPTION
 *  Set the clip of status icon bar
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 *  x1              [IN]        The x coordinate of left-top corner
 *  y1              [IN]        The y coordinate of left-top corner
 *  x2              [IN]        The x coordinate of right-bottom corner
 *  y2              [IN]        The y coordinate of right-bottom corner
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_set_clip(wgui_status_icon_bar_enum bar_id, S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_set_clip(
        &wgui_status_icon_bar_bars[bar_id], x1, y1, x2, y2);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_get_clip
 * DESCRIPTION
 *  Get the clip of status icon bar
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 *  x1              [OUT]       Pointer to restore the x coordinate of left-top corner
 *  y1              [OUT]       Pointer to restore the y coordinate of left-top corner
 *  x2              [OUT]       Pointer to restore the x coordinate of right-bottom corner
 *  y2              [OUT]       Pointer to restore the y coordinate of right-bottom corner
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_get_clip(wgui_status_icon_bar_enum bar_id, S32 *x1, S32 *y1, S32 *x2, S32 *y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_get_clip(
        &wgui_status_icon_bar_bars[bar_id],
        x1, y1, x2, y2);

}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_set_target_layer
 * DESCRIPTION
 *  Set the status icon bar's target layer
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 *  target_layer    [IN]        New target layer of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_set_target_layer(wgui_status_icon_bar_enum bar_id, gdi_handle target_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_set_target_layer(
        &wgui_status_icon_bar_bars[bar_id],
        target_layer);

#ifdef WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT
    if ((bar_id == WGUI_STATUS_ICON_BAR_H_BAR) &&
        (wgui_status_icon_bar_clock_index != WGUI_CLOCK_INVALID_INDEX))
    {
        wgui_clock_set_target_layer(wgui_status_icon_bar_clock_index, target_layer);
    }
#endif /* WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_get_target_layer
 * DESCRIPTION
 *  Get the target layer of status icon bar
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 * RETURNS
 *  The target layer of status icon bar
 *****************************************************************************/
gdi_handle wgui_status_icon_bar_get_target_layer(wgui_status_icon_bar_enum bar_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gui_status_icon_bar_get_target_layer(&wgui_status_icon_bar_bars[bar_id]);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_reset_target_layer
 * DESCRIPTION
 *  Reset the status icon bar target layer
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_reset_target_layer(wgui_status_icon_bar_enum bar_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_set_target_layer(&wgui_status_icon_bar_bars[bar_id], GDI_NULL_HANDLE);

#ifdef WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT
    if ((bar_id == WGUI_STATUS_ICON_BAR_H_BAR) &&
        (wgui_status_icon_bar_clock_index != WGUI_CLOCK_INVALID_INDEX))
    {
        wgui_clock_set_target_layer(wgui_status_icon_bar_clock_index, GDI_NULL_HANDLE);
    }
#endif /* WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_set_alpha_blend_layer
 * DESCRIPTION
 *  Set the alpha blending(abm) layer of status icon bar
 * PARAMETERS
 *  bar_id              [IN]        The id of status icon bar
 *  alpha_blend_layer   [IN]        New alpha blending(abm) layer of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_set_alpha_blend_layer(wgui_status_icon_bar_enum bar_id, gdi_handle alpha_blend_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_set_alpha_blend_layer(
        &wgui_status_icon_bar_bars[bar_id],
        alpha_blend_layer);

#ifdef WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT
    if ((bar_id == WGUI_STATUS_ICON_BAR_H_BAR) &&
        (wgui_status_icon_bar_clock_index != WGUI_CLOCK_INVALID_INDEX))
    {
        wgui_clock_set_abm_layer(wgui_status_icon_bar_clock_index, alpha_blend_layer);
    }
#endif /* WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_stats_icon_bar_get_alpha_blend_layer
 * DESCRIPTION
 *  Get the status icon bar's alpha blending(abm) layer
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 * RETURNS
 *  The alpha blending(abm) layer of status icon bar
 *****************************************************************************/
gdi_handle wgui_status_icon_bar_get_alpha_blend_layer(wgui_status_icon_bar_enum bar_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gui_status_icon_bar_get_alpha_blend_layer(&wgui_status_icon_bar_bars[bar_id]);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_reset_alpha_blend_layer
 * DESCRIPTION
 *  Reset the alpha blending(abm) layer of status icon bar
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_reset_alpha_blend_layer(wgui_status_icon_bar_enum bar_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_set_alpha_blend_layer(
        &wgui_status_icon_bar_bars[bar_id],
        GDI_NULL_HANDLE);

#ifdef WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT
    if ((bar_id == WGUI_STATUS_ICON_BAR_H_BAR) &&
        (wgui_status_icon_bar_clock_index != WGUI_CLOCK_INVALID_INDEX))
    {
        wgui_clock_set_abm_layer(wgui_status_icon_bar_clock_index, GDI_NULL_HANDLE);
    }
#endif /* WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_move
 * DESCRIPTION
 *  Move the status icon bar and set the clip of status icon bar
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 *  x               [IN]        The x coordinate of status icon bar
 *  y               [IN]        The y coordinate of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_move(wgui_status_icon_bar_enum bar_id, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_move(&wgui_status_icon_bar_bars[bar_id], x, y);
    wgui_status_icon_bar_set_clip(
        bar_id,
        x,
        y,
        x + wgui_status_icon_bar_bars[bar_id].width - 1,
        y + wgui_status_icon_bar_bars[bar_id].height - 1);
    wgui_status_icon_bar_need_arrange = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_resize
 * DESCRIPTION
 *  Resize the status icon bar
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 *  width           [IN]        The width coordinate of status icon bar
 *  height          [IN]        The height coordinate of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_resize(wgui_status_icon_bar_enum bar_id, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_resize(&wgui_status_icon_bar_bars[bar_id], width, height);
    wgui_status_icon_bar_set_clip(
        bar_id,
        wgui_status_icon_bar_bars[bar_id].x,
        wgui_status_icon_bar_bars[bar_id].y,
        wgui_status_icon_bar_bars[bar_id].x + width - 1,
        wgui_status_icon_bar_bars[bar_id].y + height - 1);
    wgui_status_icon_bar_need_arrange = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_register_hide_callback
 * DESCRIPTION
 *  Register the hide callback of status icon bar
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 *  hide_callback   [IN]        The new hide callback function of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_register_hide_callback(wgui_status_icon_bar_enum bar_id, void (*hide_callback)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_register_hide_callback(&wgui_status_icon_bar_bars[bar_id], hide_callback);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_initialize
 * DESCRIPTION
 *  Initialize all status icon bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_initialize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 icon_id;
    gui_status_icon_bar_struct *bar;
    wgui_status_icon_bar_enum bar_id;
#ifdef WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT
    S32 clock_width, clock_height;
    U32 temp_clock_id;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_initialize();

    /* Main lcd horizontal status icon bar */
    bar_id = WGUI_STATUS_ICON_BAR_H_BAR;
    bar = &wgui_status_icon_bar_bars[bar_id];
    bar->x = 0;
    bar->y = 0;
    bar->width = MAIN_LCD_device_width;
    bar->height = MMI_status_bar_height;
    bar->x1 = 0;
    bar->y1 = 0;
    bar->x2 = MAIN_LCD_device_width - 1;
    bar->y2 = MMI_status_bar_height - 1;
    gui_status_icon_bar_set_target_lcd(bar, GDI_LCD_MAIN_LCD_HANDLE);
#ifdef WGUI_STATUS_ICON_ALIGN_RIGHT
    wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR].flags |= WGUI_STATUS_ICON_BAR_ALIGN_BAR_RIGHT;
#endif

    /* Main lcd vertical status icon bar */
    bar_id = WGUI_STATUS_ICON_BAR_V_BAR;
    bar = &wgui_status_icon_bar_bars[bar_id];
    bar->x = MAIN_LCD_device_width - 17;
    bar->y = MMI_status_bar_height;
    bar->width = 17;
    bar->height = MAIN_LCD_device_height - MMI_status_bar_height - MMI_button_bar_height;
    bar->x1 = MAIN_LCD_device_width - 17;
    bar->y1 = MMI_status_bar_height;
    bar->x2 = MAIN_LCD_device_width;
#ifdef __MMI_KLG__
    bar->y2 = MAIN_LCD_device_height >> 1;
#else
    bar->y2 = MAIN_LCD_device_height - MMI_button_bar_height - 1;
#endif
    gui_status_icon_bar_set_target_lcd(bar, GDI_LCD_MAIN_LCD_HANDLE);

    /* Sub lcd status icon bar */
    bar_id = WGUI_STATUS_ICON_BAR_SUBLCD_H_BAR;
    bar = &wgui_status_icon_bar_bars[bar_id];
#ifdef __MMI_SUBLCD__
    bar->x = 0;
    bar->y = 0;
    bar->width = SUB_LCD_device_width;
    bar->height = 14;
    bar->x1 = 0;
    bar->y1 = 0;
    bar->x2 = SUB_LCD_device_width - 1;
    bar->y2 = 14;
#endif
    gui_status_icon_bar_set_target_lcd(bar, GDI_LCD_SUB_LCD_HANDLE);

    for (i = WGUI_STATUS_ICON_BAR_H_BAR;
         i < WGUI_STATUS_ICON_BAR_TOTAL_BAR;
         i++)
    {
        wgui_status_icon_bar_bars[i].rotate_flag_for_wap = MMI_FALSE;
        wgui_status_icon_bar_bars[i].alpha_blend_layer = GDI_NULL_HANDLE;
        wgui_status_icon_bar_bars[i].target_layer = GDI_NULL_HANDLE;
    }

    for (i = STATUS_ICON_MAINLCD_START; i < MAX_STATUS_ICONS; i++)
    {
        icon_id = wgui_status_icon_bar_icon_image_maps[i].icon_id;
        if(wgui_status_icon_bar_need_initialize)
        {
            wgui_status_icon_bar_icons[icon_id].image_id =
                wgui_status_icon_bar_icon_image_maps[i].image_id;
            wgui_status_icon_bar_icons[icon_id].group =
                wgui_status_icon_bar_icon_image_maps[i].group;
        }

        wgui_status_icon_bar_icons[icon_id].image_data =
            get_image((MMI_ID_TYPE)(wgui_status_icon_bar_icons[icon_id].image_id));
        wgui_status_icon_bar_icons[icon_id].n_frames =
            (S16)gui_image_n_frames(wgui_status_icon_bar_icons[icon_id].image_data);
        gui_measure_image(
            wgui_status_icon_bar_icons[icon_id].image_data,
            &wgui_status_icon_bar_icons[icon_id].width,
            &wgui_status_icon_bar_icons[icon_id].height);
    }

    wgui_status_icon_bar_need_arrange = MMI_TRUE;
    wgui_status_icon_bar_need_initialize = MMI_FALSE;
#ifdef WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT
    wgui_clock_create(
        &temp_clock_id,
        0,
        0,
        0,
        0,
        GUI_CLOCK_MAINLCD_TYPE_DIGITAL_TIME_SMALL);
    wgui_clock_measure_digital_small_clock(
        temp_clock_id,
        &clock_width,
        &clock_height);
    wgui_clock_close(temp_clock_id);
    if(wgui_status_icon_bar_clock_element_id == WGUI_STATUS_ICON_BAR_INVALID_ELEMENT_ID)
    {
        wgui_status_icon_bar_clock_element_id =
            wgui_status_icon_bar_create_element(
                clock_width,
                MMI_status_bar_height,
                wgui_status_icon_bar_show_clock,
                WGUI_STATUS_ICON_BAR_ELEMENT_ALIGN_RIGHT);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_redraw
 * DESCRIPTION
 *  Register the hide callback of status icon bar
 * PARAMETERS
 *  bar_id          [IN]        The id of status icon bar
 *  hide_callback   [IN]        The new hide callback function of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_redraw(wgui_status_icon_bar_enum bar_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_status_icon_bar_bars[bar_id].flags & WGUI_STATUS_ICON_BAR_FLAG_BAR_DISPLAY)
    {
        if (gui_status_icon_bar_show != NULL)
        {
            gui_status_icon_bar_show(&wgui_status_icon_bar_bars[bar_id]);
        }

    #ifdef __MMI_VUI_ENGINE__
        if ((bar_id == WGUI_STATUS_ICON_BAR_H_BAR) &&
            (wgui_status_icon_bar_bars[bar_id].venus_update_screen_callback != NULL))
        {
            wgui_status_icon_bar_bars[bar_id].venus_update_screen_callback(wgui_status_icon_bar_bars[bar_id].venus_update_screen_handle);
        }
        else
        {
    #endif
            gdi_layer_blt_previous(
                wgui_status_icon_bar_bars[bar_id].x,
                wgui_status_icon_bar_bars[bar_id].y,
                wgui_status_icon_bar_bars[bar_id].x + wgui_status_icon_bar_bars[bar_id].width - 1,
                wgui_status_icon_bar_bars[bar_id].y + wgui_status_icon_bar_bars[bar_id].height - 1);
    #ifdef __MMI_VUI_ENGINE__
        }
    #endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_show_horizontal_bar
 * DESCRIPTION
 *  Show status icon bar for video player
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_show_horizontal_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_status_icon_bar_need_arrange && (gui_status_icon_bar_arrange != NULL))
    {
        gui_status_icon_bar_arrange();
        wgui_status_icon_bar_need_arrange = MMI_FALSE;
    }

    old_lcd_handle = gui_status_icon_bar_setup_target_lcd_and_layer(&wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR]);

#ifdef WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT
    if ((wgui_status_icon_bar_clock_element_id != WGUI_STATUS_ICON_BAR_INVALID_ELEMENT_ID) &&
        (wgui_status_icon_bar_clock_index == WGUI_CLOCK_INVALID_INDEX))
    {
        wgui_clock_create(
            &wgui_status_icon_bar_clock_index,
            wgui_status_icon_bar_elements[wgui_status_icon_bar_clock_element_id].x + wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR].x,
            wgui_status_icon_bar_elements[wgui_status_icon_bar_clock_element_id].y + wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR].y,
            wgui_status_icon_bar_elements[wgui_status_icon_bar_clock_element_id].width,
            wgui_status_icon_bar_elements[wgui_status_icon_bar_clock_element_id].height,
            GUI_CLOCK_MAINLCD_TYPE_DIGITAL_TIME_SMALL);
        wgui_clock_set_hide_function(wgui_status_icon_bar_clock_index, wgui_status_icon_bar_time_small_hide_callback);
        wgui_clock_set_close_callback(wgui_status_icon_bar_clock_index, wgui_status_icon_bar_close_clock_callback);
    }

    if (wgui_status_icon_bar_clock_index != WGUI_CLOCK_INVALID_INDEX)
    {
        wgui_clock_move(
            wgui_status_icon_bar_clock_index,
            wgui_status_icon_bar_elements[wgui_status_icon_bar_clock_element_id].x + wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR].x,
            wgui_status_icon_bar_elements[wgui_status_icon_bar_clock_element_id].y + wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR].y);
        wgui_clock_set_target_layer(
            wgui_status_icon_bar_clock_index,
            wgui_status_icon_bar_get_target_layer(WGUI_STATUS_ICON_BAR_H_BAR));
        wgui_clock_set_abm_layer(
            wgui_status_icon_bar_clock_index,
            wgui_status_icon_bar_get_alpha_blend_layer(WGUI_STATUS_ICON_BAR_H_BAR));
    }
#endif /* WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT */

    if (gui_status_icon_bar_show != NULL)
    {
        gui_status_icon_bar_show(&wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR]);
    }

    gui_status_icon_bar_restore_target_lcd_and_layer (&wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR], old_lcd_handle);
    if (wgui_status_icon_bar_whether_double_buffer(WGUI_STATUS_ICON_BAR_H_BAR))
    {
        gdi_layer_push_and_set_active(wgui_status_icon_bar_get_target_layer(WGUI_STATUS_ICON_BAR_H_BAR));
        gdi_layer_toggle_double();
        gdi_layer_copy_double();
        gdi_layer_pop_and_restore_active();
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_update
 * DESCRIPTION
 *  Update all display status icon bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_update(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 bar_id;
    gdi_handle old_lcd_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_status_icon_bar_update_callback)
    {
        /* this update callback for java to update status icon in java screen */
        wgui_status_icon_bar_update_callback();
    }

    if (wgui_status_icon_bar_need_arrange && (gui_status_icon_bar_arrange != NULL))
    {
        gui_status_icon_bar_arrange();
        wgui_status_icon_bar_need_arrange = MMI_FALSE;
    }

    for (bar_id = WGUI_STATUS_ICON_BAR_H_BAR;
         bar_id < WGUI_STATUS_ICON_BAR_TOTAL_BAR;
         bar_id++)
    {
        if (wgui_status_icon_bar_bars[bar_id].flags & WGUI_STATUS_ICON_BAR_FLAG_BAR_DISPLAY)
        {
            old_lcd_handle = gui_status_icon_bar_setup_target_lcd_and_layer(&wgui_status_icon_bar_bars[bar_id]);

        #ifdef WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT
            if ((bar_id == WGUI_STATUS_ICON_BAR_H_BAR) &&
                 (wgui_status_icon_bar_clock_element_id != WGUI_STATUS_ICON_BAR_INVALID_ELEMENT_ID) &&
                 (wgui_status_icon_bar_clock_index == WGUI_CLOCK_INVALID_INDEX))
            {
                wgui_clock_create(
                    &wgui_status_icon_bar_clock_index,
                    wgui_status_icon_bar_elements[wgui_status_icon_bar_clock_element_id].x + wgui_status_icon_bar_bars[bar_id].x,
                    wgui_status_icon_bar_elements[wgui_status_icon_bar_clock_element_id].y + wgui_status_icon_bar_bars[bar_id].y,
                    wgui_status_icon_bar_elements[wgui_status_icon_bar_clock_element_id].width,
                    wgui_status_icon_bar_elements[wgui_status_icon_bar_clock_element_id].height,
                    GUI_CLOCK_MAINLCD_TYPE_DIGITAL_TIME_SMALL);
                wgui_clock_set_hide_function(wgui_status_icon_bar_clock_index, wgui_status_icon_bar_time_small_hide_callback);
                wgui_clock_set_close_callback(wgui_status_icon_bar_clock_index, wgui_status_icon_bar_close_clock_callback);
            }
            if ((bar_id == WGUI_STATUS_ICON_BAR_H_BAR) &&
                (wgui_status_icon_bar_clock_index != WGUI_CLOCK_INVALID_INDEX))
            {
                wgui_clock_move(
                    wgui_status_icon_bar_clock_index,
                    wgui_status_icon_bar_elements[wgui_status_icon_bar_clock_element_id].x + wgui_status_icon_bar_bars[bar_id].x,
                    wgui_status_icon_bar_elements[wgui_status_icon_bar_clock_element_id].y + wgui_status_icon_bar_bars[bar_id].y);
                wgui_clock_set_target_layer(
                    wgui_status_icon_bar_clock_index,
                    wgui_status_icon_bar_get_target_layer(bar_id));
                wgui_clock_set_abm_layer(
                    wgui_status_icon_bar_clock_index,
                    wgui_status_icon_bar_get_alpha_blend_layer(bar_id));
            }
        #endif /* WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT */

            if (gui_status_icon_bar_show != NULL)
            {
                gui_status_icon_bar_show(&wgui_status_icon_bar_bars[bar_id]);
            }

        #ifdef __MMI_VUI_ENGINE__
            if ((bar_id == WGUI_STATUS_ICON_BAR_H_BAR) &&
                (wgui_status_icon_bar_bars[bar_id].venus_update_screen_callback != NULL))
            {
                wgui_status_icon_bar_bars[bar_id].venus_update_screen_callback(wgui_status_icon_bar_bars[bar_id].venus_update_screen_handle);
            }
            else
            {
        #endif
                gdi_layer_blt_previous(
                    wgui_status_icon_bar_bars[bar_id].x,
                    wgui_status_icon_bar_bars[bar_id].y,
                    wgui_status_icon_bar_bars[bar_id].x + wgui_status_icon_bar_bars[bar_id].width - 1,
                    wgui_status_icon_bar_bars[bar_id].y + wgui_status_icon_bar_bars[bar_id].height - 1);
        #ifdef __MMI_VUI_ENGINE__
            }
        #endif
            gui_status_icon_bar_restore_target_lcd_and_layer (&wgui_status_icon_bar_bars[bar_id], old_lcd_handle);
            if (wgui_status_icon_bar_whether_double_buffer(bar_id))
            {
                if(wgui_status_icon_bar_get_target_layer(bar_id) != GDI_NULL_HANDLE)
                {
                    gdi_layer_push_and_set_active(wgui_status_icon_bar_get_target_layer(bar_id));
                    gdi_layer_toggle_double();
                    gdi_layer_copy_double();
                    gdi_layer_pop_and_restore_active();
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_hide
 * DESCRIPTION
 *  Hide the status icon bar, show the background of status icon bar
 * PARAMETERS
 *  bar_id      [IN]    The Id of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_hide(wgui_status_icon_bar_enum bar_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_struct *bar;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bar = &wgui_status_icon_bar_bars[bar_id];
    gdi_layer_push_clip();
    gdi_layer_set_clip(bar->x1, bar->y1, bar->x2, bar->y2);
    if(gui_status_icon_bar_hide)
    {
        gui_status_icon_bar_hide(bar);
    }
    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_close
 * DESCRIPTION
 *  Close all status icon bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    MMI_BOOL flag = MMI_TRUE;
    gdi_handle current_lcd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return;
#if 0    
#if defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_240X400__) || defined (__MMI_MAINLCD_320X240__) || defined (__MMI_MAINLCD_320X480__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif     
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_reset
 * DESCRIPTION
 *  reset all status icon bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 bar_id;
    gdi_handle active_lcd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_lcd_get_active(&active_lcd);
    for (bar_id = WGUI_STATUS_ICON_BAR_H_BAR;
         bar_id < WGUI_STATUS_ICON_BAR_TOTAL_BAR;
         bar_id++)
    {

        if (wgui_status_icon_bar_bars[bar_id].target_lcd == active_lcd)
        {
            wgui_status_icon_bar_reset_display(bar_id);
            wgui_status_icon_bar_reset_double_buffer(bar_id);
            wgui_status_icon_bar_reset_target_layer(bar_id);
            wgui_status_icon_bar_reset_alpha_blend_layer(bar_id);
            wgui_status_icon_bar_register_venus_update_callback(NULL, NULL);
            wgui_status_icon_bar_register_hide_callback(bar_id, NULL);
            wgui_status_icon_bar_set_background(bar_id);
            wgui_status_icon_bar_reset_IME_callback(bar_id);
        }
    }

    if (active_lcd == GDI_LCD_MAIN_LCD_HANDLE)
    {
        wgui_status_icon_bar_reset_update_callback();
        wgui_status_icon_bar_reset_rotate_for_wap();
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_register_update_callback
 * DESCRIPTION
 *  Register the update callback function, this callback function used by java,
 *  When update status icon bar, will invoke the update callback function for java
 * PARAMETERS
 *  update_callback     [IN]        The register update callback function
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_register_update_callback(void (*update_callback)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_update_callback = update_callback;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_register_update_callback
 * DESCRIPTION
 *  Register the update callback function, this callback function used by java,
 *  When update status icon bar, will invoke the update callback function for java
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_reset_update_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_update_callback = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_get_clock
 * DESCRIPTION
 *  Get the clock in status icon bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U32 wgui_status_icon_bar_get_clock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return wgui_status_icon_bar_clock_index;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_change_timer_format_callback
 * DESCRIPTION
 *  When change timer format, this callback function will be invoke to resize element and clock
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_change_timer_format_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT
    S32 clock_width, clock_height;
    U32 temp_clock_id;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT
    wgui_clock_create(
        &temp_clock_id,
        0,
        0,
        0,
        0,
        GUI_CLOCK_MAINLCD_TYPE_DIGITAL_TIME_SMALL);
    wgui_clock_measure_digital_small_clock(
        temp_clock_id,
        &clock_width,
        &clock_height);
    wgui_clock_close(temp_clock_id);
    if(wgui_status_icon_bar_clock_element_id != WGUI_STATUS_ICON_BAR_INVALID_ELEMENT_ID)
    {
        wgui_status_icon_bar_resize_element(
            wgui_status_icon_bar_clock_element_id,
            clock_width,
            clock_height);
        if(wgui_status_icon_bar_clock_index != WGUI_CLOCK_INVALID_INDEX)
        {
            if (wgui_status_icon_bar_need_arrange && (gui_status_icon_bar_arrange != NULL))
            {
                gui_status_icon_bar_arrange();
                wgui_status_icon_bar_need_arrange = MMI_FALSE;
            }
            wgui_clock_move(
                wgui_status_icon_bar_clock_index,
                wgui_status_icon_bar_elements[wgui_status_icon_bar_clock_element_id].x + wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR].x,
                wgui_status_icon_bar_elements[wgui_status_icon_bar_clock_element_id].y+ wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR].y);
        }
    }
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_register_venus_update_callback
 * DESCRIPTION
 *  Register the venus update callback and handle
 * PARAMETERS
 *  update_screen_callback      [IN]        venus update callback
 *  update_screen_handle        [IN]        venus update handle
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_register_venus_update_callback(
        void (*update_screen_callback)(void *handle),
        void *update_screen_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VUI_ENGINE__
    gui_status_icon_bar_register_venus_update(
        &wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR],
        update_screen_callback,
        update_screen_handle);
#endif /* __MMI_VUI_ENGINE__ */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_register_IME_callback
 * DESCRIPTION
 *  Register IME callback of status icon bar
 * PARAMETERS
 *  bar_id          [IN]        Id of status icon bar
 *  IME_callback    [IN]        The new IME callback of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_register_IME_callback(wgui_status_icon_bar_enum bar_id, void (*IME_callback)(S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_register_IME_callback(
        &wgui_status_icon_bar_bars[bar_id],
        IME_callback);
#ifdef WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT
    if ((bar_id == WGUI_STATUS_ICON_BAR_H_BAR) &&
        (wgui_status_icon_bar_clock_index != WGUI_CLOCK_INVALID_INDEX))
    {
         wgui_clock_set_post_display_callback(
             wgui_status_icon_bar_clock_index,
             IME_callback);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_reset_IME_callback
 * DESCRIPTION
 *  Reset IME callback of status icon bar
 * PARAMETERS
 *  bar_id             [IN]        Id of status icon bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_reset_IME_callback(wgui_status_icon_bar_enum bar_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_reset_IME_callback(&wgui_status_icon_bar_bars[bar_id]);
#ifdef WGUI_STATUS_ICON_SHOW_TIME_IN_RIGHT
    if ((bar_id == WGUI_STATUS_ICON_BAR_H_BAR) &&
        (wgui_status_icon_bar_clock_index != WGUI_CLOCK_INVALID_INDEX))
    {
         wgui_clock_set_post_display_callback(
             wgui_status_icon_bar_clock_index,
             NULL);
    }
#endif
}


/****************************************************************************
 * Status icon function
 ****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_set_icon_display
 * DESCRIPTION
 *  Set the status icon's display flag
 * PARAMETERS
 *  icon_id         [IN]    The id of status icon
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_set_icon_display(S32 icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((icon_id < 0) || (icon_id >= MAX_STATUS_ICONS))
    {
        return;
    }

    if (!mmi_flight_mode_is_status_icon_visible(icon_id, wgui_status_icon_bar_icons[icon_id].flags | GUI_STATUS_ICON_BAR_ICON_DISPLAY))
    {
        return;
    }

    gui_status_icon_bar_enable_icon_display(&wgui_status_icon_bar_icons[icon_id], MMI_TRUE);
    wgui_status_icon_bar_need_arrange = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_reset_icon_display
 * DESCRIPTION
 *  Reset status icon's display flag
 * PARAMETERS
 *  icon_id         [IN]    The id of status icon
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_reset_icon_display(S32 icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((icon_id < 0) || (icon_id >= MAX_STATUS_ICONS))
    {
        return;
    }

    gui_status_icon_bar_enable_icon_display(&wgui_status_icon_bar_icons[icon_id], MMI_FALSE);
    gui_status_icon_bar_enable_icon_blink(&wgui_status_icon_bar_icons[icon_id], MMI_FALSE);
    gui_status_icon_bar_enable_icon_animate(&wgui_status_icon_bar_icons[icon_id], MMI_FALSE);
    wgui_status_icon_bar_need_arrange = MMI_TRUE;
    mmi_flight_mode_is_status_icon_visible(icon_id, 0);
    wgui_status_icon_bar_setup_blink_animate();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_set_icon_animate
 * DESCRIPTION
 *  Set status icon's animate flag
 * PARAMETERS
 *  icon_id         [IN]    The id of status icon
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_set_icon_animate(S32 icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((icon_id < 0) || (icon_id >= MAX_STATUS_ICONS))
    {
        return;
    }

    gui_status_icon_bar_enable_icon_animate(&wgui_status_icon_bar_icons[icon_id], MMI_TRUE);
    wgui_status_icon_bar_need_arrange = MMI_TRUE;
    wgui_status_icon_bar_setup_blink_animate();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_reset_icon_animate
 * DESCRIPTION
 *  Reset status icon's animate flag
 * PARAMETERS
 *  icon_id         [IN]    The id of status icon
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_reset_icon_animate(S32 icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((icon_id < 0) || (icon_id >= MAX_STATUS_ICONS))
    {
        return;
    }
    gui_status_icon_bar_enable_icon_animate(&wgui_status_icon_bar_icons[icon_id], MMI_FALSE);
    wgui_status_icon_bar_need_arrange = MMI_TRUE;
    wgui_status_icon_bar_setup_blink_animate();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_show_icon
 * DESCRIPTION
 *  Show the status icon
 * PARAMETERS
 *  icon_id         [IN]    The id of status icon
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_show_icon(S32 icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((icon_id < 0) || (icon_id >= MAX_STATUS_ICONS))
    {
        return;
    }

    wgui_status_icon_bar_set_icon_display(icon_id);
    wgui_status_icon_bar_update();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_hide_icon
 * DESCRIPTION
 *  Hide the status icon
 * PARAMETERS
 *  icon_id         [IN]    The id of status icon
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_hide_icon(S32 icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_reset_icon_display (icon_id);
    wgui_status_icon_bar_update();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_animate_icon
 * DESCRIPTION
 *  animate status icon
 * PARAMETERS
 *  icon_id         [IN]    The id of status icon
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_animate_icon(S32 icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((icon_id < 0) || (icon_id >= MAX_STATUS_ICONS))
    {
        return;
    }

    wgui_status_icon_bar_set_icon_animate(icon_id);
    wgui_status_icon_bar_update();
}

/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_blink_icon
 * DESCRIPTION
 *  Blinking status icon
 * PARAMETERS
 *  icon_id         [IN]    The id of status icon
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_blink_icon(S32 icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((icon_id < 0) || (icon_id >= MAX_STATUS_ICONS))
    {
        return;
    }

    if (!mmi_flight_mode_is_status_icon_visible(icon_id, wgui_status_icon_bar_icons[icon_id].flags | GUI_STATUS_ICON_BAR_ICON_BLINK))
    {
        return;
    }

    gui_status_icon_bar_enable_icon_blink(&wgui_status_icon_bar_icons[icon_id], MMI_TRUE);
    wgui_status_icon_bar_need_arrange = MMI_TRUE;
    wgui_status_icon_bar_update();
    wgui_status_icon_bar_setup_blink_animate();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_set_icon_flag
 * DESCRIPTION
 *  Set status icon's flag
 * PARAMETERS
 *  icon_id         [IN]    The id of status icon
 *  flag            [IN]    New flag of status icon
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_set_icon_flag(S32 icon_id, U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((icon_id < 0) || (icon_id >= MAX_STATUS_ICONS))
    {
        return;
    }
    gui_status_icon_bar_set_icon_flag(&wgui_status_icon_bar_icons[icon_id], flag);
    wgui_status_icon_bar_need_arrange = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_get_icon_flag
 * DESCRIPTION
 *  Get status icon's flag
 * PARAMETERS
 *  icon_id         [IN]    The id of status icon
 * RETURNS
 *  void
 *****************************************************************************/
U32 wgui_status_icon_bar_get_icon_flag(S32 icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gui_status_icon_bar_get_icon_flag(&wgui_status_icon_bar_icons[icon_id]);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_whether_icon_display
 * DESCRIPTION
 *  To check whether icon display or not
 * PARAMETERS
 *  icon_id         [IN]    The id of status icon
 * RETURNS
 *  MMI_TRUE    :   The status icon display
 *  MMI_FALSE   :   The status icon not display
 *****************************************************************************/
MMI_BOOL wgui_status_icon_bar_whether_icon_display(S32 icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gui_status_icon_bar_whether_icon_display(&wgui_status_icon_bar_icons[icon_id]);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_change_icon_level
 * DESCRIPTION
 *  Change status icon level, usually for battery or signal to change strength
 * PARAMETERS
 *  icon_id         [IN]    The id of status icon
 *  level           [IN]    The new level of status icon
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_change_icon_level(S32 icon_id, S32 level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((icon_id < 0) || (icon_id >= MAX_STATUS_ICONS))
    {
        return;
    }
    gui_status_icon_bar_change_icon_level(&wgui_status_icon_bar_icons[icon_id], level);

    if ((icon_id == STATUS_ICON_SIGNAL_STRENGTH) 
        ||(icon_id == STATUS_ICON_BATTERY_STRENGTH)
    #ifdef __MMI_DUAL_SIM_MASTER__
        ||(icon_id == STATUS_ICON_SLAVE_SIGNAL_STRENGTH)
    #endif    
        )
    {
#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
        if (!(wgui_status_icon_bar_get_flag(WGUI_STATUS_ICON_BAR_H_BAR) & WGUI_STATUS_ICON_BAR_FLAG_BAR_DISPLAY) &&
            wgui_status_icon_bar_integrated_enable)
        {
            if (wgui_status_icon_bar_integrated_redraw)
            {
                wgui_status_icon_bar_integrated_redraw();
            }
        }
        else
#endif
        {
            wgui_status_icon_bar_refresh_fixed_icon(WGUI_STATUS_ICON_BAR_H_BAR, icon_id);
        }
    }
    else if ((icon_id == STATUS_ICON_SUBLCD_SIGNAL_STRENGTH) || (icon_id == STATUS_ICON_SUBLCD_BATTERY_STRENGTH))
    {
        wgui_status_icon_bar_refresh_fixed_icon(WGUI_STATUS_ICON_BAR_SUBLCD_H_BAR, icon_id);
    }
    else
    {
        wgui_status_icon_bar_update();
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_change_icon_image
 * DESCRIPTION
 *  Change status icon image
 * PARAMETERS
 *  icon_id         [IN]    The id of status icon
 *  image_id        [IN]    New image of status icon
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_change_icon_image(S32 icon_id, S32 image_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_change_icon_image(&wgui_status_icon_bar_icons[icon_id], image_id);
    wgui_status_icon_bar_need_arrange = MMI_TRUE;
    wgui_status_icon_bar_update();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_get_icon_image_id
 * DESCRIPTION
 *  Get status icon image id
 * PARAMETERS
 *  icon_id         [IN]    The id of status icon
 * RETURNS
 *  The image id of status icon
 *****************************************************************************/
S32 wgui_status_icon_bar_get_icon_image_id(S32 icon_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gui_status_icon_bar_get_icon_image_id(&wgui_status_icon_bar_icons[icon_id]);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_get_integrated_icon_size
 * DESCRIPTION
 *  Get the status icon's size for integrated title
 * PARAMETERS
 *  icon_id         [IN]    The id of status icon
 *  width           [OUT]   Pointer to restore the width of status icon
 *  height          [OUT]   Pointer to restore the height of status icon
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_get_integrated_icon_size(S32 icon_id, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
    if (!(wgui_status_icon_bar_get_flag(WGUI_STATUS_ICON_BAR_H_BAR) & WGUI_STATUS_ICON_BAR_FLAG_BAR_DISPLAY) &&
        (wgui_status_icon_bar_integrated_enable))
    {
        gui_status_icon_bar_get_icon_size(
            &wgui_status_icon_bar_icons[icon_id],
            width,
            height);
    }
    else
#endif
    {
        *width = 0;
        *height = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_show_integrated_icon
 * DESCRIPTION
 *  Show status icon for integrated title
 * PARAMETERS
 *  icon_id         [IN]    The id of status icon
 *  x               [IN]    X coordinate of show
 *  y               [IN]    Y coordinate of show
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_show_integrated_icon(S32 icon_id, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
    if (!(wgui_status_icon_bar_get_flag(WGUI_STATUS_ICON_BAR_H_BAR) & WGUI_STATUS_ICON_BAR_FLAG_BAR_DISPLAY) &&
        (wgui_status_icon_bar_integrated_enable))
    {
        gui_status_icon_bar_show_integrated_icon(
            &wgui_status_icon_bar_icons[icon_id],
            x,
            y);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_register_integrated_redraw
 * DESCRIPTION
 *  Register redraw status icon bar redraw function for integrated
 * PARAMETERS
 *  redraw          [IN]    The new redraw function of integrated title
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_register_integrated_redraw(void (*redraw)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_status_icon_bar_integrated_enable)
    {
        wgui_status_icon_bar_integrated_redraw = redraw;
    }
    else if(redraw == NULL)
    {
        wgui_status_icon_bar_integrated_redraw = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_integrated_enable
 * DESCRIPTION
 *  Enable integrated title or not
 * PARAMETERS
 *  enable          [IN]    Enable integrated title or not
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_enable_integrated(MMI_BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_integrated_enable = enable;
    if (wgui_status_icon_bar_integrated_enable)
    {
        if (wgui_status_icon_bar_whether_have_blink_or_animate_icon())
        {
            gui_start_timer(WGUI_STATUS_ICON_BAR_TIMER_RATE, wgui_status_icon_bar_icon_blink_and_animate_timer_callback);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_whether_integrated_enable
 * DESCRIPTION
 *  To check integrated title enable or not
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_status_icon_bar_whether_integrated_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return wgui_status_icon_bar_integrated_enable;
}


#ifdef __MMI_TOUCH_SCREEN__

static MMI_BOOL wgui_status_icon_bar_enable_pen_event = MMI_FALSE;
static FuncPtr wgui_status_icon_bar_pen_event_handler[MAX_STATUS_ICONS][WGUI_STATUS_ICON_BAR_PEN_EVENT_MAX];
static S32 wgui_status_icon_bar_pen_icon_id = STATUS_ICON_INVALID_ID;


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_register_pen_event_handler
 * DESCRIPTION
 *  Register status icon's pen event handler
 * PARAMETERS
 *  icon_id         [IN]    The id of status icon
 *  event_type      [IN]    The pen event of handler
 *  f               [IN]    The pointer of register handler
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_register_pen_event_handler(
        S32 icon_id,
        wgui_status_icon_bar_pen_enum event_type,
        FuncPtr handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_pen_event_handler[icon_id][event_type] = handler;
#ifdef __LOW_COST_SUPPORT_COMMON__
    if(event_type == WGUI_STATUS_ICON_BAR_PEN_LONG_PRESS_ICON)
    {
        wgui_status_icon_bar_pen_event_handler[icon_id][WGUI_STATUS_ICON_BAR_PEN_SELECT_ICON] = handler;
    }
#endif
    wgui_status_icon_bar_enable_pen_event = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_reset_all_pen_event_handler
 * DESCRIPTION
 *  Reset all icon's pen event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* Vogins Start */
#if defined(__VRE_V30__) && defined(__MMI_TOUCH_SCREEN__) /*&& !defined(__MMI_VUI_HOMESCREEN__)*/
extern int vm_vre_is_running(void);
#endif
/* Vogins End */
 
void wgui_status_icon_bar_reset_all_pen_event_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 icon_id;
    S32 event_index;
/* Vogins Start */
#if defined(__VRE_V30__) && defined(__MMI_TOUCH_SCREEN__) /*&& !defined(__MMI_VUI_HOMESCREEN__)*/
    U8 in_check= MMI_FALSE;
#endif
/* Vogins End */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (icon_id = 0; icon_id < MAX_STATUS_ICONS; icon_id++)
    {
        for (event_index = 0; event_index < WGUI_STATUS_ICON_BAR_PEN_EVENT_MAX; event_index++)
        {
/* Vogins Start */
#if defined(__VRE_V30__) && defined(__MMI_TOUCH_SCREEN__) /*&& !defined(__MMI_VUI_HOMESCREEN__)*/
            if (vm_vre_is_running())
            {
                switch (icon_id)
                {
                    case STATUS_ICON_VRE_1:
                    case STATUS_ICON_VRE_2:
                    case STATUS_ICON_VRE_3:
                    case STATUS_ICON_VRE_4:
                    case STATUS_ICON_VRE_DEFAULT:
                        in_check= MMI_TRUE;
                        continue;				
                }
            }
#else
            wgui_status_icon_bar_pen_event_handler[icon_id][event_index] = NULL;
#endif
/* Vogins End */
        }
    }
/* Vogins Start */
#if defined(__VRE_V30__) && defined(__MMI_TOUCH_SCREEN__) /*&& !defined(__MMI_VUI_HOMESCREEN__)*/
    if (in_check)
        wgui_status_icon_bar_enable_pen_event = MMI_TRUE;
    else
        wgui_status_icon_bar_enable_pen_event = MMI_FALSE;
#else
    wgui_status_icon_bar_enable_pen_event = MMI_FALSE;
#endif
/* Vogins End */
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_execute_pen_event_handler
 * DESCRIPTION
 *  Execute the icon's pen event handler
 * PARAMETERS
 *  icon_id         [IN]    The id of status icon
 *  event_type      [IN]    The pen event type
 * RETURNS
 *  void
 *****************************************************************************/
/* Vogins Start */
/*ltz 0613*/
#if  defined(__VRE__) && defined(__MMI_TOUCH_SCREEN__) //&& defined(__MMI_VUI_HOMESCREEN__)
extern signed int g_statusicon_id;
#endif
/* Vogins End */
MMI_BOOL wgui_status_icon_bar_execute_pen_event_handler(S32 icon_id, wgui_status_icon_bar_pen_enum event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wgui_status_icon_bar_pen_event_handler[icon_id][event_type] != NULL)
    {
/* Vogins Start */
/*ltz 0613*/
#if  defined(__VRE__) && defined(__MMI_TOUCH_SCREEN__) //&& defined(__MMI_VUI_HOMESCREEN__)
		g_statusicon_id = icon_id;
#endif
/* Vogins End */
        wgui_status_icon_bar_pen_event_handler[icon_id][event_type]();
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_translate_pen_position
 * DESCRIPTION
 *  Translate the pen event position to icon's id
 * PARAMETERS
 *  x           [IN]    x coordinate of pen event
 *  y           [IN]    y coordinate of pen event
 * RETURNS
 *  Id of status icon to reponse the pen event
 *****************************************************************************/
static S32 wgui_status_icon_bar_translate_pen_position(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 icon_id;
    S32 x1, y1, x2, y2;
    S32 bar_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (bar_id = 0; bar_id < WGUI_STATUS_ICON_BAR_TOTAL_BAR; bar_id++)
    {
        if ((wgui_status_icon_bar_bars[bar_id].flags & WGUI_STATUS_ICON_BAR_FLAG_BAR_DISPLAY) &&
            (wgui_status_icon_bar_bars[bar_id].icon_list != NULL))
        {
            x1 = wgui_status_icon_bar_bars[bar_id].x1;
            y1 = wgui_status_icon_bar_bars[bar_id].y1;
            x2 = wgui_status_icon_bar_bars[bar_id].x2;
            y2 = wgui_status_icon_bar_bars[bar_id].y2;
            if (x >= x1 && x <= x2 && y >= y1 && y <= y2)
            {
                for (i = 0; i < wgui_status_icon_bar_bars[bar_id].n_icons; i++)
                {
                    icon_id = wgui_status_icon_bar_bars[bar_id].icon_list[i];
                    if ((wgui_status_icon_bar_icons[icon_id].flags & GUI_STATUS_ICON_BAR_ICON_DISPLAY)
                    /* Vogins Start */
                    #if defined(__VRE_V30__)
                        || (wgui_status_icon_bar_icons[icon_id].flags & GUI_STATUS_ICON_BAR_ICON_BLINK)
                    #endif
                    /* Vogins End */
                        && (wgui_status_icon_bar_icons[icon_id].image_id != IMAGE_ID_NULL))
                    {
                        x1 = wgui_status_icon_bar_bars[bar_id].x + wgui_status_icon_bar_icons[icon_id].x;
                        x2 = x1 + wgui_status_icon_bar_icons[icon_id].width - 1;
                        y1 = wgui_status_icon_bar_bars[bar_id].y + wgui_status_icon_bar_icons[icon_id].y;
                        y2 = y1 + wgui_status_icon_bar_icons[icon_id].height - 1;
                        if (x >= x1 && x <= x2 && y >= y1 && y <= y2)
                        {
                            return icon_id;
                        }
                    }
                }
            }
        }
    }
    return STATUS_ICON_INVALID_ID;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_translate_pen_event
 * DESCRIPTION
 *  Translate pen event of status icon bar
 * PARAMETERS
 *  pen_event       [IN]    The pen event of response by status icon bar
 *  x               [IN]    X coordinate of pen event
 *  y               [IN]    Y coordinate of pen event
 *  icon_id         [OUT]   Pointer to restore the icon id of response the pen event
 *  event_type      [OUT]   Pointer to restoe the status icon bar's event
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_status_icon_bar_translate_pen_event(
            mmi_pen_event_type_enum pen_event,
            S32 x,
            S32 y,
            S32 *icon_id,
            wgui_status_icon_bar_pen_enum *event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_wait_longpress_enum w;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *event_type = WGUI_STATUS_ICON_BAR_PEN_NONE;
    *icon_id = STATUS_ICON_INVALID_ID;

    if (wgui_status_icon_bar_enable_pen_event == MMI_FALSE)
    {
        return MMI_FALSE;
    }

    if (wgui_status_icon_bar_pen_icon_id < 0 && pen_event != MMI_PEN_EVENT_DOWN)
    {
        return MMI_FALSE;
    }

    if (pen_event == MMI_PEN_EVENT_DOWN)
    {
        wgui_status_icon_bar_pen_icon_id = wgui_status_icon_bar_translate_pen_position(x, y);
        if (wgui_status_icon_bar_pen_icon_id < 0)
        {
            return MMI_FALSE;
        }
    }

    *icon_id = wgui_status_icon_bar_pen_icon_id;
    if (wgui_status_icon_bar_pen_event_handler[wgui_status_icon_bar_pen_icon_id][WGUI_STATUS_ICON_BAR_PEN_LONG_PRESS_ICON] != NULL)
    {
        w = gui_pen_wait_longpress(pen_event, (S16)x, (S16)y);
        if (w == GUI_WAIT_LONGPRESS_READY)
        {
         #ifndef __LOW_COST_SUPPORT_COMMON__
            *event_type = WGUI_STATUS_ICON_BAR_PEN_LONG_PRESS_ICON;
         #else
            *event_type = WGUI_STATUS_ICON_BAR_PEN_NONE;
         #endif
        }
    }

    if (pen_event == MMI_PEN_EVENT_UP && *event_type == WGUI_STATUS_ICON_BAR_PEN_NONE)
    {
        if (wgui_status_icon_bar_pen_icon_id == wgui_status_icon_bar_translate_pen_position(x, y))
        {
            *event_type = WGUI_STATUS_ICON_BAR_PEN_SELECT_ICON;
        }
    }

    return MMI_TRUE;
}

#endif /* __MMI_TOUCH_SCREEN__ */


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_show_sublcd_background
 * DESCRIPTION
 *  Displays the SUBLCD background screen
 * PARAMETERS
 *  start_x             [IN]        Left top position
 *  start_y             [IN]        Left top position
 *  end_x               [IN]        Right bottom position
 *  end_y               [IN]        Right bottom position
 *  is_status_bar       [IN]        Is status bar to draw or not.
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_show_sublcd_background(S32 x1, S32 y1, S32 x2, S32 y2, U8 is_status_bar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* draw all screen of background display. */

    if (!is_status_bar)
    {
    #if defined(__MMI_SUBLCD_COLOR__)
        y1 = (U16) Sub_lcd_title_height;
    #endif
    }

    if(gui_status_icon_bar_show_sublcd_horizontal_background)
    {
        gui_status_icon_bar_show_sublcd_horizontal_background(x1, y1, x2, y2);
    }
}


/*****************************************************************************
 * Element functions
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_create_element
 * DESCRIPTION
 *  Create a element
 * PARAMETERS
 *  width       [IN]    The width of element
 *  height      [IN]    The height of element
 *  show        [IN]    The show function of element
 * RETURNS
 *  void
 *****************************************************************************/
S32 wgui_status_icon_bar_create_element(S32 width, S32 height, void(* show)(S32 x1, S32 y1, S32 x2, S32 y2), U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    gui_status_icon_bar_struct *bar;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Only support element in mainlcd horizontal status icon bar currently,
    if want to support in sublcd horizontal status icon bar,should be process
    the element range in arrange function*/
    wgui_status_icon_bar_need_arrange = MMI_TRUE;
    bar = &wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR];
    for (i = 0; i < WGUI_STATUS_ICON_BAR_ELEMENT_NUM; i++)
    {
        if (wgui_status_icon_bar_elements[i].active == MMI_FALSE)
        {
            gui_status_icon_bar_create_element(
                &wgui_status_icon_bar_elements[i],
                width,
                height,
                show,
                flag);
            bar->element_list[bar->n_elements] = i;
            bar->n_elements++;
            return i;
        }
    }

    return WGUI_STATUS_ICON_BAR_INVALID_ELEMENT_ID;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_resize_element
 * DESCRIPTION
 *  Resize the element
 * PARAMETERS
 *  element_id          [IN]    The id of element
 *  width               [IN]    The new width of element
 *  height              [IN]    The new height of element
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_resize_element(S32 element_id, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (element_id < 0)
    {
        return;
    }
    MMI_ASSERT(element_id < WGUI_STATUS_ICON_BAR_ELEMENT_NUM);
    gui_status_icon_bar_resize_element(&wgui_status_icon_bar_elements[element_id], width, height);
    wgui_status_icon_bar_need_arrange = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_register_element_show
 * DESCRIPTION
 *  Register element's show function
 * PARAMETERS
 *  element_id          [IN]    The id of element
 *  show                [IN]    New show function of element
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_register_element_show(S32 element_id, void (*show)(S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (element_id < 0)
    {
        return;
    }
    MMI_ASSERT(element_id < WGUI_STATUS_ICON_BAR_ELEMENT_NUM);
    gui_status_icon_bar_register_element_show(&wgui_status_icon_bar_elements[element_id], show);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_close_element
 * DESCRIPTION
 *  Close the element
 * PARAMETERS
 *  element_id         [IN]    The id of element
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_close_element(S32 element_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_struct *bar;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (element_id < 0)
    {
        return;
    }    
    MMI_ASSERT(element_id < WGUI_STATUS_ICON_BAR_ELEMENT_NUM);
    gui_status_icon_bar_close_element(&wgui_status_icon_bar_elements[element_id]);
    bar = &wgui_status_icon_bar_bars[WGUI_STATUS_ICON_BAR_H_BAR];

    for (i = 0; i < bar->n_elements; i++)
    {
        if (bar->element_list[i] == element_id)
        {
            break;
        }
    }

    for (; i < bar->n_elements - 1; i++)
    {
        bar->element_list[i] = bar->element_list[i + 1];
    }
    bar->n_elements--;
    wgui_status_icon_bar_need_arrange = MMI_TRUE;
}


/*****************************************************************************
 * Partial function
 ****************************************************************************/
#ifdef __MMI_LCD_PARTIAL_ON__

#define WGUI_STATUS_ICON_BAR_PARTIAL_POOL_NUM (sizeof(wgui_status_icon_bar_partial_display_pool)/sizeof(wgui_status_icon_bar_partial_display_pool[1]))
const S16 wgui_status_icon_bar_partial_display_pool[] =
{
    STATUS_ICON_INCOMING_SMS,
#ifdef __MMI_DUAL_SIM_MASTER__
    STATUS_ICON_SLAVE_INCOMING_SMS,
#endif /* __MMI_DUAL_SIM_MASTER__ */
    STATUS_ICON_MMS_UNREAD,

#ifdef __MMI_DUAL_SIM_MASTER__
    STATUS_ICON_MMS_UNREAD_SIM_1,
    STATUS_ICON_MMS_UNREAD_SIM_2,
#endif  /* __MMI_DUAL_SIM_MASTER__ */

    STATUS_ICON_MISSED_CALL,
#ifdef __MMI_DUAL_SIM_MASTER__
    STATUS_ICON_CARD2MISSED_CALL,
#endif/*__MMI_DUAL_SIM_MASTER__*/

    STATUS_ICON_UNREAD_EMAIL,

    STATUS_ICON_UNREAD_VOICE_L1L2,
    STATUS_ICON_UNREAD_VOICE_L1,
    STATUS_ICON_UNREAD_VOICE_L2,
    STATUS_ICON_UNREAD_EMAIL_L1L2,
    STATUS_ICON_UNREAD_EMAIL_L1,
    STATUS_ICON_UNREAD_EMAIL_L2,
    STATUS_ICON_UNREAD_NET_L1,
    STATUS_ICON_UNREAD_NET_L2,
    STATUS_ICON_UNREAD_NET_L1L2,
    STATUS_ICON_UNREAD_VIDEO_L1,
    STATUS_ICON_UNREAD_VIDEO_L2,
    STATUS_ICON_UNREAD_VIDEO_L1L2,

#ifdef __MMI_DUAL_SIM_MASTER__
    STATUS_ICON_UNREAD_VOICE_L1_MASTER,
    STATUS_ICON_UNREAD_VOICE_L2_MASTER,
    STATUS_ICON_UNREAD_VOICE_L1L2_MASTER,
    STATUS_ICON_UNREAD_FAX_L1_MASTER,
    STATUS_ICON_UNREAD_FAX_L2_MASTER,
    STATUS_ICON_UNREAD_FAX_L1L2_MASTER,
    STATUS_ICON_UNREAD_EMAIL_L1_MASTER,
    STATUS_ICON_UNREAD_EMAIL_L2_MASTER,
    STATUS_ICON_UNREAD_EMAIL_L1L2_MASTER,
    STATUS_ICON_UNREAD_NET_L1_MASTER,
    STATUS_ICON_UNREAD_NET_L2_MASTER,
    STATUS_ICON_UNREAD_NET_L1L2_MASTER,
    STATUS_ICON_UNREAD_VIDEO_L1_MASTER,
    STATUS_ICON_UNREAD_VIDEO_L2_MASTER,
    STATUS_ICON_UNREAD_VIDEO_L1L2_MASTER,

    STATUS_ICON_UNREAD_VOICE_L1_SLAVE,
    STATUS_ICON_UNREAD_VOICE_L2_SLAVE,
    STATUS_ICON_UNREAD_VOICE_L1L2_SLAVE,
    STATUS_ICON_UNREAD_FAX_L1_SLAVE,
    STATUS_ICON_UNREAD_FAX_L2_SLAVE,
    STATUS_ICON_UNREAD_FAX_L1L2_SLAVE,
    STATUS_ICON_UNREAD_EMAIL_L1_SLAVE,
    STATUS_ICON_UNREAD_EMAIL_L2_SLAVE,
    STATUS_ICON_UNREAD_EMAIL_L1L2_SLAVE,
    STATUS_ICON_UNREAD_NET_L1_SLAVE,
    STATUS_ICON_UNREAD_NET_L2_SLAVE,
    STATUS_ICON_UNREAD_NET_L1L2_SLAVE,
    STATUS_ICON_UNREAD_VIDEO_L1_SLAVE,
    STATUS_ICON_UNREAD_VIDEO_L2_SLAVE,
    STATUS_ICON_UNREAD_VIDEO_L1L2_SLAVE,
#endif  /*__MMI_DUAL_SIM_MASTER__*/

#ifdef __MMI_AUTO_ANSWER_MACHINE__
    STATUS_ICON_AUTOAM_REC,
    STATUS_ICON_AUTOAM_UNREAD,
#endif /* __MMI_AUTO_ANSWER_MACHINE__ */

    STATUS_ICON_IMPS_MSG,
#ifdef __MMI_PROV_MESSAGE_SUPPORT__
    STATUS_ICON_PROVMSG_STATE,
#ifdef __MMI_DUAL_SIM_MASTER__
    STATUS_ICON_PROVMSG_SIM1,
    STATUS_ICON_PROVMSG_SIM2,
#endif
#endif

#ifdef __MMI_DUAL_SIM_MASTER__
    STATUS_ICON_WAP1,
    STATUS_ICON_WAP2
#else /* __MMI_DUAL_SIM_MASTER__ */
    STATUS_ICON_WAP
#endif /* __MMI_DUAL_SIM_MASTER__ */

};


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_arrange_partial
 * DESCRIPTION
 *  Arrange status icon for partial display
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_status_icon_bar_arrange_partial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    S32 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_partial_display_icon_number = 0;
    while (i < WGUI_STATUS_ICON_BAR_PARTIAL_POOL_NUM)
    {
        j = wgui_status_icon_bar_partial_display_pool[i];
        if (GUI_STATUS_ICON_BAR_ICON_DISPLAY_ON(wgui_status_icon_bar_icons[j].flags))
        {
            wgui_status_icon_bar_partial_list_display[wgui_status_icon_bar_partial_display_icon_number] = j;
            wgui_status_icon_bar_partial_display_icon_number++;
            if (wgui_status_icon_bar_partial_display_icon_number >= WGUI_STATUS_ICON_BAR_PARTIAL_ICON_LIST_NUM)
            {
                break;
            }
        }
        i++;
    }
}


#endif /* __MMI_LCD_PARTIAL_ON__ */


/* Vogins Start */
#ifdef __VRE_V30__
void wgui_status_icon_bar_change_icon_image_data(S32 icon_id, PU8 image_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_status_icon_bar_change_icon_image_data(&wgui_status_icon_bar_icons[icon_id], image_data);
    wgui_status_icon_bar_need_arrange = MMI_TRUE;
    wgui_status_icon_bar_update();
}
#endif
/* Vogins End */
