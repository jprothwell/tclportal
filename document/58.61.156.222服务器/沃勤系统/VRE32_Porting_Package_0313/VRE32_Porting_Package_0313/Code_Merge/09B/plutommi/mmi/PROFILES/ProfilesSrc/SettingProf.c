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
 * SettingProf.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for profile API
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

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/***************** Settings Application implementation *********************/

/**************************************************************

   FILENAME : Profiles.c

   PURPOSE     : API's to all applications.

   REMARKS     : nil

   AUTHOR      : Ashima Bajaj, Deepali

   DATE     : 5/5/2003

**************************************************************/

#include "MMI_include.h"
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "SettingDefs.h"
#include "ProfileGprots.h"
#include "Profiles_prot.h"
#include "VolumeHandler.h"
#include "UserProfilesResDef.h"
#include "ProfilesGexdcl.h"
#include "gpioInc.h"
#include "AudioInc.h"
#include "mdi_audio.h"
#include "IdleAppDef.h"
#include "ProfilesGexdcl.h"
#ifdef __MMI_UCM__
#include "UCMGProt.h"
#else
#include "CallManagementGProt.h"
#endif
#include "Profiles_prot.h"
#include "ProfilesDefs.h"       /* MTK robin 1119, AT command set wallpaper and profile */
#include "ATHandlerProt.h"

#include "SimDetectionDef.h"
#include "SimDetectionGprot.h"
#include "SimDetectionGexdcl.h"
/* Leo end */
#ifdef __MMI_BT_PROFILE__
#include "BTMMICM.h"
#include "BTMMICMGprots.h"
#include "BTMMIScr.h"
#include "BTMMIScrGprots.h"
#ifdef __MMI_A2DP_SUPPORT__
#include "BTMMIA2DP.h"
extern void mmi_a2dp_bt_power_off_callback(BOOL success);
#endif
#endif /* __MMI_BT_PROFILE__ */ 

#ifdef __MMI_MEDIA_PLAYER__
#include "MediaPlayerGProt.h"
#endif

#ifdef __MMI_FM_RADIO__
#include "FMRadioProt.h"
#endif /* __MMI_FM_RADIO__ */ 

#ifdef __J2ME__
#include "jma_interface.h"
#endif

#ifdef __MMI_SOUND_RECORDER__
#include "SoundRecorderProt.h"
#endif

#ifdef __MMI_USB_SUPPORT__
#define MMI_PROF_GENERAL_KEYPAD_TIMER_DUR 15    /* sec */
extern kal_bool INT_USBBoot(void);
#endif /* __MMI_USB_SUPPORT__ */ 

#ifdef __MMI_AUDIO_PLAYER__
extern BOOL mmi_audply_save_volume(U8 volume);
extern BOOL mmi_audply_is_playing(void);
#endif /* __MMI_AUDIO_PLAYER__ */ 

#ifndef __MMI_MEDIA_PLAYER_AUDIO__
extern MMI_BOOL mmi_audply_is_single_play_activated(void);
#endif

#ifdef __MMI_FM_RADIO__
extern void mmi_fmrdo_power_on_main_screen(BOOL turn_on);
extern void mmi_fmrdo_power_on(BOOL turn_on);
#endif /* __MMI_FM_RADIO__ */ 

#ifdef __A8BOX_SUPPORT__
extern BOOL mmi_a8box_is_playing(void);
#endif /* __A8BOX_SUPPORT__ */

#if defined(__MMI_ALM_AUDIO_OPTIONS__) || defined(__MMI_ALM_CUSTOMIZE_TONE__)
#include "AlarmDef.h"
#include "AlarmProt.h"

extern alm_context_struct g_alm_cntx;
extern alm_framework_context_struct g_alm_frm_cntx;
#endif /* defined(__MMI_ALM_AUDIO_OPTIONS__) || defined(__MMI_ALM_CUSTOMIZE_TONE__) */ 

extern void mdi_audio_set_audio_mode(U8 mode);
extern void change_font(void);

extern void SetLSpkNowOff(pBOOL flag);

#ifdef __MMI_BT_PROFILE__
extern void mmi_bt_a2dp_deactivate_req(void);
U8 g_mmi_profiles_bt_reset_pending = 0;
BOOL g_mmi_profiles_bt_in_call = FALSE;
static U8 g_mmi_profiles_bt_disalbe_sco = 0; /* Disable SCO connection */
static MMI_BOOL g_mmi_profiles_bt_inquerying = MMI_FALSE; /* No SCO connection when inquerying */

#ifdef __MMI_HFP_SUPPORT__
BOOL g_mmi_profiles_bt_always_use_in_call = FALSE;
static void (*mmi_profiles_bt_connect_sco_app_callback) (void) = NULL;
BOOL g_mmi_profiles_bt_app_in_use = FALSE;
#endif /* __MMI_HFP_SUPPORT__ */ 
#endif /* __MMI_BT_PROFILE__ */ 

#if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
#include "mdi_video.h"
#include "mdi_bitstream.h"

#define BT_SCO_CONNECT_TIMEOUT_DURATION 4000 /* Timeout to disconnect duration */
#define BT_SCO_RECONNECT_TIMER_DURATION 3000 /* Timeout to disconnect duration */

static MMI_BOOL g_mmi_profiles_bt_sco_timeout = MMI_TRUE; /* Timeout mechanism */
static void (*g_mmi_profiles_bt_inquery_callback) (void) = NULL;
#endif /* #if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__) */

#ifdef __MMI_SUBLCD_MASTER_MODE__
#endif/*__MMI_SUBLCD_MASTER_MODE__*/

#if defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT)
#include "mmi_imps_gprot.h"
#endif   

#if defined(__MMI_MOBILE_TV_PLAYER__)
#include "mdi_mtv.h"
#endif
/* Vogins Start */
#ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
#include "ProfileMgr.h" 
#include "ProfileMgrGProt.h" 
#endif /* __MMI_PROFILE_EXTMELODY_SUPPORT__ */

#ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  SetFileAsActivateRingToneID
 * DESCRIPTION
 *  set file as incoming ring tone for current activated profile.
 * PARAMETERS
 *  pathfileName      [IN] 
 *  p_ringtoneid      [IN]
 * RETURNS
 *  result  : only PMG_ADDFILE_ERR_SUCCESS means success.
 *****************************************************************************/
S16 SetFileAsActivateRingToneID(S8 *pathfileName, U16 *p_ringtoneid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 slot = 0;
    PMG_ADDFILE_ERRNO err = PMG_ADDFILE_ERR_UNKNOWN;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pathfileName == NULL || *(U16*)pathfileName == 0 || p_ringtoneid == NULL)
    {
        return -1;
    }
    if (PmgCheckImyMidFileSize(pathfileName) == PMG_ADDFILE_ERR_FILE_TOO_LARGE)
    {
        err = PMG_ADDFILE_ERR_FILE_TOO_LARGE;
    }
    else
    {
        err = PmgAddExtMelodyByPathFileName(pathfileName);
    }

    if (err == PMG_ADDFILE_ERR_SUCCESS)
    {
        slot = PmgGetSlotByPathFileName(pathfileName);
        if (slot == PMG_INVAILD_SLOT)
        {
            return MMI_FALSE;
        }
        else
        {
            *p_ringtoneid = PMG_EXT_MELODY_BEGIN + slot;
            gprofiles[gactivatedprofile].toneSetup.ringTone = *p_ringtoneid;
            gcurrentprofile.toneSetup.ringTone = *p_ringtoneid;

            if(!mmi_profiles_write_cntx_to_nvram())
            {
                MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_ERR_SET_RING_TONE_ID); 
                return -1;
            }
        }
    }
    return err;
}
#endif
/* Vogins End */
/*****************************************************************************
 * FUNCTION
 *  initializeProfiles
 * DESCRIPTION
 *  Set default values in profiles structure.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void initializeProfiles(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_profiles_get_dynamic_tone_ids();
    /* Initialising General Profile */
    gprofiles[0].toneSetup.ringTone = gstartMidiId;
#ifdef __MMI_VIDEO_TELEPHONY__
    gprofiles[0].toneSetup.videoCallTone = gstartMidiId + 1;
#endif /*__MMI_VIDEO_TELEPHONY__*/
    gprofiles[0].toneSetup.alarmTone = (gstartMidiId + 2);
#ifndef __MMI_POWER_ON_OFF_MUTE__
    gprofiles[0].toneSetup.powerOnTone = (gstartGeneralToneId);
    gprofiles[0].toneSetup.powerOffTone = (gstartGeneralToneId + 1);
#endif /*__MMI_POWER_ON_OFF_MUTE__*/
#ifdef __MMI_CLAMSHELL__
    gprofiles[0].toneSetup.coverOpenTone = (gstartGeneralToneId + 2);
    gprofiles[0].toneSetup.coverCloseTone = (gstartGeneralToneId + 3);
#endif /* __MMI_CLAMSHELL__ */ 
#ifndef __MMI_PROF_SPLIT_MSG_TONES__
    gprofiles[0].toneSetup.messageTone = (gstartMiscToneId + 4);
#else
#ifdef MMS_SUPPORT
    gprofiles[0].toneSetup.mmsTone = (gstartMiscToneId);
#endif
    gprofiles[0].toneSetup.smsTone = (gstartMiscToneId + 1);
#ifdef __MMI_EMAIL__
    gprofiles[0].toneSetup.emailTone = (gstartMiscToneId + 2);
#endif
#ifdef __MMI_OP11_MMS_SUPPORT_AUDIO_MSG__
/* under construction !*/
#endif
#endif /*__MMI_PROF_SPLIT_MSG_TONES__*/

    gprofiles[0].toneSetup.keypadTone = KEYPAD_TONE;
    gprofiles[0].mtCallAlertTypeEnum = MMI_RING;
    gprofiles[0].ringTypeEnum = REPEAT;
    gprofiles[0].extraTone.connectTone = 0;
    gprofiles[0].extraTone.errorTone = 1;
    gprofiles[0].extraTone.campOnTone = 1;
    gprofiles[0].extraTone.warningTone = 1;
    /* MTK brian added to wrap cover open/close tone setup, 2003/10/18 */
#ifdef __MMI_CLAMSHELL__
    gprofiles[0].answeringMode.coverAnswer = 1;
#endif 
    /* MTK end */
    gprofiles[0].answeringMode.anyKey = 0;
    gprofiles[0].answeringMode.automatic = 1;
    gprofiles[0].light.timer.setsec = 15;
    gprofiles[0].light.status = COLOR_PATTERN1;
    gprofiles[0].fontSizeEnum = THEME_DEFAULT;
    gprofiles[0].keypadVolumeLevel = LEVEL2;
    gprofiles[0].ringVolumeLevel = LEVEL4;
    gprofiles[0].loudSpeakerVolumeLevel = LEVEL4;
    gprofiles[0].intelligentCallAlert = MMI_INTELLIGENT_CALL_ALERT_OFF;
#if defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT)    
    gprofiles[0].impsStatus = IMPS_PHB_PA_USER_AVAILABLE;
    gprofiles[0].toneSetup.IMPSChatroomNotificationTone = gstartMiscToneId + 5;
    gprofiles[0].toneSetup.IMPSContactOnlineTone = gstartMiscToneId + 6;
    gprofiles[0].toneSetup.IMPSNewInvitationTone = gstartMiscToneId + 7;
    gprofiles[0].toneSetup.IMPSNewMessageTone = gstartMiscToneId + 8;
#endif
#ifdef __MMI_DUAL_PROFILE_SUPPORT__
   gprofiles[0].toneSetup.card2_ringTone = gstartMidiId;
   gprofiles[0].toneSetup.card2_messageTone = (gstartMiscToneId + 4);
#endif	/* __MMI_DUAL_PROFILE_SUPPORT__ */

    gprofiles[1].toneSetup.ringTone = gstartMidiId;
#ifdef __MMI_VIDEO_TELEPHONY__
    gprofiles[1].toneSetup.videoCallTone = gstartMidiId + 1;    
#endif /*__MMI_VIDEO_TELEPHONY__*/
    gprofiles[1].toneSetup.alarmTone = (gstartMidiId + 2);
#ifndef __MMI_POWER_ON_OFF_MUTE__
    gprofiles[1].toneSetup.powerOnTone = (POWERON_SILENT);
    gprofiles[1].toneSetup.powerOffTone = (POWEROFF_SILENT);
#endif /*__MMI_POWER_ON_OFF_MUTE__*/
#ifdef __MMI_CLAMSHELL__
    gprofiles[1].toneSetup.coverOpenTone = (COVER_OPEN_SILENT);
    gprofiles[1].toneSetup.coverCloseTone = (COVER_CLOSE_SILENT);
#endif /* __MMI_CLAMSHELL__ */ 
#ifndef __MMI_PROF_SPLIT_MSG_TONES__
    gprofiles[1].toneSetup.messageTone = (MESSAGE_SILENT);
#else
#ifdef MMS_SUPPORT
    gprofiles[1].toneSetup.mmsTone = (MESSAGE_SILENT);
#endif
    gprofiles[1].toneSetup.smsTone = (MESSAGE_SILENT);
#ifdef __MMI_EMAIL__
    gprofiles[1].toneSetup.emailTone = (MESSAGE_SILENT);
#endif
#ifdef __MMI_OP11_MMS_SUPPORT_AUDIO_MSG__
/* under construction !*/
#endif
#endif /*__MMI_PROF_SPLIT_MSG_TONES__*/
    gprofiles[1].toneSetup.keypadTone = KEYPAD_SILENT;
    gprofiles[1].mtCallAlertTypeEnum = MMI_VIBRATION_ONLY;
    gprofiles[1].ringTypeEnum = SINGLE;
    gprofiles[1].extraTone.connectTone = 0;
    gprofiles[1].extraTone.errorTone = 0;
    gprofiles[1].extraTone.campOnTone = 0;
    gprofiles[1].extraTone.warningTone = 0;
    /* MTK brian added to wrap cover open/close tone setup, 2003/10/18 */
#ifdef __MMI_CLAMSHELL__
    gprofiles[1].answeringMode.coverAnswer = 1;
#endif 
    /* MTK end */
    gprofiles[1].answeringMode.anyKey = 0;
    gprofiles[1].answeringMode.automatic = 1;
    gprofiles[1].light.timer.setsec = 15;
    gprofiles[1].light.status = COLOR_PATTERN1;
    gprofiles[1].fontSizeEnum = THEME_DEFAULT;
    gprofiles[1].keypadVolumeLevel = LEVEL1;
    gprofiles[1].ringVolumeLevel = LEVEL4;
    gprofiles[1].loudSpeakerVolumeLevel = LEVEL4;
    gprofiles[1].intelligentCallAlert = MMI_INTELLIGENT_CALL_ALERT_OFF;
#if defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT)
    gprofiles[1].impsStatus = IMPS_PHB_PA_USER_DISCREET;
    gprofiles[1].toneSetup.IMPSChatroomNotificationTone = MESSAGE_SILENT;
    gprofiles[1].toneSetup.IMPSContactOnlineTone = MESSAGE_SILENT;
    gprofiles[1].toneSetup.IMPSNewInvitationTone = MESSAGE_SILENT;
    gprofiles[1].toneSetup.IMPSNewMessageTone = MESSAGE_SILENT;
#endif
#ifdef __MMI_DUAL_PROFILE_SUPPORT__
   gprofiles[1].toneSetup.card2_ringTone = gstartMidiId;
   gprofiles[1].toneSetup.card2_messageTone = (MESSAGE_SILENT);
#endif	/* __MMI_DUAL_PROFILE_SUPPORT__ */

    /* Initialising Outdoor Profile */
    gprofiles[2].toneSetup.ringTone = gstartMidiId;
#ifdef __MMI_VIDEO_TELEPHONY__
    gprofiles[2].toneSetup.videoCallTone = gstartMidiId + 1;    
#endif /*__MMI_VIDEO_TELEPHONY__*/
    gprofiles[2].toneSetup.alarmTone = (gstartMidiId + 2);
#ifndef __MMI_POWER_ON_OFF_MUTE__
    gprofiles[2].toneSetup.powerOnTone = (gstartGeneralToneId + 0);
    gprofiles[2].toneSetup.powerOffTone = (gstartGeneralToneId + 1);
#endif /*__MMI_POWER_ON_OFF_MUTE__*/
#ifdef __MMI_CLAMSHELL__
    gprofiles[2].toneSetup.coverOpenTone = (gstartGeneralToneId + 2);
    gprofiles[2].toneSetup.coverCloseTone = (gstartGeneralToneId + 3);
#endif /* __MMI_CLAMSHELL__ */ 
#ifndef __MMI_PROF_SPLIT_MSG_TONES__
    gprofiles[2].toneSetup.messageTone = (gstartMiscToneId + 4);
#else
#ifdef MMS_SUPPORT
    gprofiles[2].toneSetup.mmsTone = (gstartMiscToneId);
#endif
    gprofiles[2].toneSetup.smsTone = (gstartMiscToneId + 1);
#ifdef __MMI_EMAIL__
    gprofiles[2].toneSetup.emailTone = (gstartMiscToneId + 2);
#endif
#ifdef __MMI_OP11_MMS_SUPPORT_AUDIO_MSG__
/* under construction !*/
#endif
#endif /*__MMI_PROF_SPLIT_MSG_TONES__*/
    gprofiles[2].toneSetup.keypadTone = KEYPAD_TONE;
    gprofiles[2].mtCallAlertTypeEnum = MMI_VIBRATION_AND_RING;
    gprofiles[2].ringTypeEnum = REPEAT;
    gprofiles[2].extraTone.connectTone = 0;
    gprofiles[2].extraTone.errorTone = 1;
    gprofiles[2].extraTone.campOnTone = 1;
    gprofiles[2].extraTone.warningTone = 1;
    /* MTK brian added to wrap cover open/close tone setup, 2003/10/18 */
#ifdef __MMI_CLAMSHELL__
    gprofiles[2].answeringMode.coverAnswer = 1;
#endif 
    /* MTK end */
    gprofiles[2].answeringMode.anyKey = 0;
    gprofiles[2].answeringMode.automatic = 1;
    gprofiles[2].light.timer.setsec = 15;
    gprofiles[2].light.status = COLOR_PATTERN1;
    gprofiles[2].fontSizeEnum = THEME_DEFAULT;
    gprofiles[2].keypadVolumeLevel = LEVEL7;
    gprofiles[2].ringVolumeLevel = LEVEL7;
    gprofiles[2].loudSpeakerVolumeLevel = LEVEL4;
    gprofiles[2].intelligentCallAlert = MMI_INTELLIGENT_CALL_ALERT_OFF;
#if defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT)    
    gprofiles[2].impsStatus = IMPS_PHB_PA_USER_AVAILABLE;
    gprofiles[2].toneSetup.IMPSChatroomNotificationTone = gstartMiscToneId + 5;
    gprofiles[2].toneSetup.IMPSContactOnlineTone = gstartMiscToneId + 6;
    gprofiles[2].toneSetup.IMPSNewInvitationTone = gstartMiscToneId + 7;
    gprofiles[2].toneSetup.IMPSNewMessageTone = gstartMiscToneId + 8;

#endif
#ifdef __MMI_DUAL_PROFILE_SUPPORT__
   gprofiles[2].toneSetup.card2_ringTone = gstartMidiId;
   gprofiles[2].toneSetup.card2_messageTone = (gstartMiscToneId + 4);
#endif	/* __MMI_DUAL_PROFILE_SUPPORT__ */

    /* Initialising Indoor Profile */
    gprofiles[3].toneSetup.ringTone = gstartMidiId;
#ifdef __MMI_VIDEO_TELEPHONY__
    gprofiles[3].toneSetup.videoCallTone = gstartMidiId + 1;
#endif /*__MMI_VIDEO_TELEPHONY__*/
    gprofiles[3].toneSetup.alarmTone = (gstartMidiId + 2);
#ifndef __MMI_POWER_ON_OFF_MUTE__
    gprofiles[3].toneSetup.powerOnTone = (gstartGeneralToneId + 0);
    gprofiles[3].toneSetup.powerOffTone = (gstartGeneralToneId + 1);
#endif /*__MMI_POWER_ON_OFF_MUTE__*/
#ifdef __MMI_CLAMSHELL__
    gprofiles[3].toneSetup.coverOpenTone = (gstartGeneralToneId + 2);
    gprofiles[3].toneSetup.coverCloseTone = (gstartGeneralToneId + 3);
#endif /* __MMI_CLAMSHELL__ */ 
#ifndef __MMI_PROF_SPLIT_MSG_TONES__
    gprofiles[3].toneSetup.messageTone = (gstartMiscToneId + 4);
#else
#ifdef MMS_SUPPORT
    gprofiles[3].toneSetup.mmsTone = (gstartMiscToneId);
#endif
    gprofiles[3].toneSetup.smsTone = (gstartMiscToneId + 1);
#ifdef __MMI_EMAIL__
    gprofiles[3].toneSetup.emailTone = (gstartMiscToneId + 2);
#endif
#ifdef __MMI_OP11_MMS_SUPPORT_AUDIO_MSG__
/* under construction !*/
#endif
#endif /*__MMI_PROF_SPLIT_MSG_TONES__*/
    gprofiles[3].toneSetup.keypadTone = KEYPAD_TONE;
    gprofiles[3].mtCallAlertTypeEnum = MMI_RING;
    gprofiles[3].ringTypeEnum = ASCENDING;
    gprofiles[3].extraTone.connectTone = 0;
    gprofiles[3].extraTone.errorTone = 1;
    gprofiles[3].extraTone.campOnTone = 1;
    gprofiles[3].extraTone.warningTone = 1;
    /* MTK brian added to wrap cover open/close tone setup, 2003/10/18 */
#ifdef __MMI_CLAMSHELL__
    gprofiles[3].answeringMode.coverAnswer = 1;
#endif 
    /* MTK end */
    gprofiles[3].answeringMode.anyKey = 0;
    gprofiles[3].answeringMode.automatic = 1;
    gprofiles[3].light.timer.setsec = 15;
    gprofiles[3].light.status = COLOR_PATTERN1;
    gprofiles[3].fontSizeEnum = THEME_DEFAULT;
    gprofiles[3].keypadVolumeLevel = LEVEL1;
    gprofiles[3].ringVolumeLevel = LEVEL3;
    gprofiles[3].loudSpeakerVolumeLevel = LEVEL4;
    gprofiles[3].intelligentCallAlert = MMI_INTELLIGENT_CALL_ALERT_OFF;
#if defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT)
    gprofiles[3].impsStatus = IMPS_PHB_PA_USER_AVAILABLE;
    gprofiles[3].toneSetup.IMPSChatroomNotificationTone = gstartMiscToneId + 5;
    gprofiles[3].toneSetup.IMPSContactOnlineTone = gstartMiscToneId + 6;
    gprofiles[3].toneSetup.IMPSNewInvitationTone = gstartMiscToneId + 7;
    gprofiles[3].toneSetup.IMPSNewMessageTone = gstartMiscToneId + 8;
#endif
#ifdef __MMI_DUAL_PROFILE_SUPPORT__
   gprofiles[3].toneSetup.card2_ringTone = gstartMidiId;
   gprofiles[3].toneSetup.card2_messageTone = (gstartMiscToneId + 4);
#endif	/* __MMI_DUAL_PROFILE_SUPPORT__ */

    /* Initialising Headset Profile */
    gprofiles[4].toneSetup.ringTone = gstartMidiId;
#ifdef __MMI_VIDEO_TELEPHONY__
    gprofiles[4].toneSetup.videoCallTone = gstartMidiId + 1;
#endif /*__MMI_VIDEO_TELEPHONY__*/
    gprofiles[4].toneSetup.alarmTone = (gstartMidiId + 2);
#ifndef __MMI_POWER_ON_OFF_MUTE__
    gprofiles[4].toneSetup.powerOnTone = (gstartGeneralToneId + 0);
    gprofiles[4].toneSetup.powerOffTone = (gstartGeneralToneId + 1);
#endif /*__MMI_POWER_ON_OFF_MUTE__*/
#ifdef __MMI_CLAMSHELL__
    gprofiles[4].toneSetup.coverOpenTone = (gstartGeneralToneId + 2);
    gprofiles[4].toneSetup.coverCloseTone = (gstartGeneralToneId + 3);
#endif /* __MMI_CLAMSHELL__ */ 
#ifndef __MMI_PROF_SPLIT_MSG_TONES__
    gprofiles[4].toneSetup.messageTone = (gstartMiscToneId + 4);
#else
#ifdef MMS_SUPPORT
    gprofiles[4].toneSetup.mmsTone = (gstartMiscToneId);
#endif
    gprofiles[4].toneSetup.smsTone = (gstartMiscToneId + 1);
#ifdef __MMI_EMAIL__
    gprofiles[4].toneSetup.emailTone = (gstartMiscToneId + 2);
#endif
#ifdef __MMI_OP11_MMS_SUPPORT_AUDIO_MSG__
/* under construction !*/
#endif
#endif /*__MMI_PROF_SPLIT_MSG_TONES__*/
    gprofiles[4].toneSetup.keypadTone = KEYPAD_TONE;
    gprofiles[4].mtCallAlertTypeEnum = MMI_RING;
    gprofiles[4].ringTypeEnum = REPEAT;
    gprofiles[4].extraTone.connectTone = 0;
    gprofiles[4].extraTone.errorTone = 1;
    gprofiles[4].extraTone.campOnTone = 1;
    gprofiles[4].extraTone.warningTone = 1;
    /* MTK brian added to wrap cover open/close tone setup, 2003/10/18 */
#ifdef __MMI_CLAMSHELL__
    gprofiles[4].answeringMode.coverAnswer = 1;
#endif 
    /* MTK end */

    gprofiles[4].answeringMode.anyKey = 0;
    /* MTK: Brian added for KLM */
    gprofiles[4].answeringMode.automatic = 1;
    /* MTK end */
    gprofiles[4].light.timer.setsec = 15;
    gprofiles[4].light.status = COLOR_PATTERN1;
    gprofiles[4].fontSizeEnum = THEME_DEFAULT;
    gprofiles[4].keypadVolumeLevel = LEVEL2;
    gprofiles[4].ringVolumeLevel = LEVEL4;
    gprofiles[4].loudSpeakerVolumeLevel = LEVEL4;
    gprofiles[4].intelligentCallAlert = MMI_INTELLIGENT_CALL_ALERT_OFF;
#if defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT)
    gprofiles[4].impsStatus = IMPS_PHB_PA_USER_AVAILABLE;
    gprofiles[4].toneSetup.IMPSChatroomNotificationTone = gstartMiscToneId + 5;
    gprofiles[4].toneSetup.IMPSContactOnlineTone = gstartMiscToneId + 6;
    gprofiles[4].toneSetup.IMPSNewInvitationTone = gstartMiscToneId + 7;
    gprofiles[4].toneSetup.IMPSNewMessageTone = gstartMiscToneId + 8;
#endif
#ifdef __MMI_DUAL_PROFILE_SUPPORT__
   gprofiles[4].toneSetup.card2_ringTone = gstartMidiId;
   gprofiles[4].toneSetup.card2_messageTone = (gstartMiscToneId + 4);
#endif	/* __MMI_DUAL_PROFILE_SUPPORT__ */

    /* Initialising Silent Profile */
    gprofiles[5].toneSetup.ringTone = gstartMidiId;
#ifdef __MMI_VIDEO_TELEPHONY__
    gprofiles[5].toneSetup.videoCallTone = gstartMidiId + 1;
#endif /*__MMI_VIDEO_TELEPHONY__*/
    gprofiles[5].toneSetup.alarmTone = (gstartMidiId + 2);
#ifndef __MMI_POWER_ON_OFF_MUTE__
    gprofiles[5].toneSetup.powerOnTone = (POWERON_SILENT);
    gprofiles[5].toneSetup.powerOffTone = (POWEROFF_SILENT);
#endif /*__MMI_POWER_ON_OFF_MUTE__*/
#ifdef __MMI_CLAMSHELL__
    gprofiles[5].toneSetup.coverOpenTone = (COVER_OPEN_SILENT);
    gprofiles[5].toneSetup.coverCloseTone = (COVER_CLOSE_SILENT);
#endif /* __MMI_CLAMSHELL__ */ 
#ifndef __MMI_PROF_SPLIT_MSG_TONES__
    gprofiles[5].toneSetup.messageTone = (MESSAGE_SILENT);
#else
#ifdef MMS_SUPPORT
    gprofiles[5].toneSetup.mmsTone = (MESSAGE_SILENT);
#endif
    gprofiles[5].toneSetup.smsTone = (MESSAGE_SILENT);
#ifdef __MMI_EMAIL__
    gprofiles[5].toneSetup.emailTone = (MESSAGE_SILENT);
#endif
#ifdef __MMI_OP11_MMS_SUPPORT_AUDIO_MSG__
/* under construction !*/
#endif
#endif /*__MMI_PROF_SPLIT_MSG_TONES__*/
    gprofiles[5].toneSetup.keypadTone = KEYPAD_TONE;
    gprofiles[5].mtCallAlertTypeEnum = MMI_RING;
    gprofiles[5].ringTypeEnum = REPEAT;
    gprofiles[5].extraTone.connectTone = 0;
    gprofiles[5].extraTone.errorTone = 1;
    gprofiles[5].extraTone.campOnTone = 1;
    gprofiles[5].extraTone.warningTone = 1;
    /* MTK brian added to wrap cover open/close tone setup, 2003/10/18 */
#ifdef __MMI_CLAMSHELL__
    gprofiles[5].answeringMode.coverAnswer = 1;
#endif 
    /* MTK end */
    gprofiles[5].answeringMode.anyKey = 0;
    gprofiles[5].answeringMode.automatic = 1;
    gprofiles[5].light.timer.setsec = 15;
    gprofiles[5].light.status = COLOR_PATTERN1;
    gprofiles[5].fontSizeEnum = THEME_DEFAULT;
    gprofiles[5].keypadVolumeLevel = LEVEL5;
    gprofiles[5].ringVolumeLevel = LEVEL3;
    gprofiles[5].loudSpeakerVolumeLevel = LEVEL4;
    gprofiles[5].intelligentCallAlert = MMI_INTELLIGENT_CALL_ALERT_OFF;
#if defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT)
    gprofiles[5].impsStatus = IMPS_PHB_PA_USER_AVAILABLE;
    gprofiles[5].toneSetup.IMPSChatroomNotificationTone = MESSAGE_SILENT ;
    gprofiles[5].toneSetup.IMPSContactOnlineTone = MESSAGE_SILENT ;
    gprofiles[5].toneSetup.IMPSNewInvitationTone = MESSAGE_SILENT ;
    gprofiles[5].toneSetup.IMPSNewMessageTone = MESSAGE_SILENT ;
#endif
#ifdef __MMI_DUAL_PROFILE_SUPPORT__
   gprofiles[5].toneSetup.card2_ringTone = gstartMidiId;
   gprofiles[5].toneSetup.card2_messageTone = (MESSAGE_SILENT);
#endif	/* __MMI_DUAL_PROFILE_SUPPORT__ */

    /* Initialising LoudSpeaker Profile */
    gprofiles[6].toneSetup.ringTone = gstartMidiId;
#ifdef __MMI_VIDEO_TELEPHONY__
    gprofiles[6].toneSetup.videoCallTone = gstartMidiId + 1;
#endif /*__MMI_VIDEO_TELEPHONY__*/
    gprofiles[6].toneSetup.alarmTone = (gstartMidiId + 2);
#ifndef __MMI_POWER_ON_OFF_MUTE__
    gprofiles[6].toneSetup.powerOnTone = (gstartGeneralToneId + 0);
    gprofiles[6].toneSetup.powerOffTone = (gstartGeneralToneId + 1);
#endif /*__MMI_POWER_ON_OFF_MUTE__*/
#ifdef __MMI_CLAMSHELL__
    gprofiles[6].toneSetup.coverOpenTone = (gstartGeneralToneId + 2);
    gprofiles[6].toneSetup.coverCloseTone = (gstartGeneralToneId + 3);
#endif /* __MMI_CLAMSHELL__ */ 
#ifndef __MMI_PROF_SPLIT_MSG_TONES__
    gprofiles[6].toneSetup.messageTone = (gstartMiscToneId + 4);
#else
#ifdef MMS_SUPPORT
    gprofiles[6].toneSetup.mmsTone = (gstartMiscToneId);
#endif
    gprofiles[6].toneSetup.smsTone = (gstartMiscToneId + 1);
#ifdef __MMI_EMAIL__
    gprofiles[6].toneSetup.emailTone = (gstartMiscToneId + 2);
#endif
#ifdef __MMI_OP11_MMS_SUPPORT_AUDIO_MSG__
/* under construction !*/
#endif
#endif /*__MMI_PROF_SPLIT_MSG_TONES__*/
    gprofiles[6].toneSetup.keypadTone = KEYPAD_TONE;
    gprofiles[6].mtCallAlertTypeEnum = MMI_RING;
    gprofiles[6].ringTypeEnum = REPEAT;
    gprofiles[6].extraTone.connectTone = 0;
    gprofiles[6].extraTone.errorTone = 1;
    gprofiles[6].extraTone.campOnTone = 1;
    gprofiles[6].extraTone.warningTone = 1;
    /* MTK brian added to wrap cover open/close tone setup, 2003/10/18 */
#ifdef __MMI_CLAMSHELL__
    gprofiles[6].answeringMode.coverAnswer = 1;
#endif 
    /* MTK end */
    gprofiles[6].answeringMode.anyKey = 0;
    gprofiles[6].answeringMode.automatic = 1;
    gprofiles[6].light.timer.setsec = 15;
    gprofiles[6].light.status = COLOR_PATTERN1;
    gprofiles[6].fontSizeEnum = THEME_DEFAULT;
    gprofiles[6].keypadVolumeLevel = LEVEL5;
    gprofiles[6].ringVolumeLevel = LEVEL3;
    gprofiles[6].loudSpeakerVolumeLevel = LEVEL4;
    gprofiles[6].intelligentCallAlert = MMI_INTELLIGENT_CALL_ALERT_OFF;
#if defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT)
    gprofiles[6].impsStatus = IMPS_PHB_PA_USER_AVAILABLE;    
    gprofiles[6].toneSetup.IMPSChatroomNotificationTone = gstartMiscToneId + 5;
    gprofiles[6].toneSetup.IMPSContactOnlineTone = gstartMiscToneId + 6;
    gprofiles[6].toneSetup.IMPSNewInvitationTone = gstartMiscToneId + 7;
    gprofiles[6].toneSetup.IMPSNewMessageTone = gstartMiscToneId + 8;
#endif
#ifdef __MMI_DUAL_PROFILE_SUPPORT__
   gprofiles[6].toneSetup.card2_ringTone = gstartMidiId;
   gprofiles[6].toneSetup.card2_messageTone = (gstartMiscToneId + 4);
#endif	/* __MMI_DUAL_PROFILE_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  GetRingVolumeLevel
 * DESCRIPTION
 *  Setting Ring Volume Level for a Profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_VOLUME_LEVEL_ENUM GetRingVolumeLevel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_VOLUME_LEVEL_ENUM ringVolumeLevel;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ringVolumeLevel = gcurrentprofile.ringVolumeLevel;

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_TRC_GET_RING_VOL,ringVolumeLevel);
 
    return ringVolumeLevel;
}


/*****************************************************************************
 * FUNCTION
 *  GetLoudspkrVolumeLevel
 * DESCRIPTION
 *  Setting Ring Volume Level for a Profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_VOLUME_LEVEL_ENUM GetLoudspkrVolumeLevel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_VOLUME_LEVEL_ENUM loudspkr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    loudspkr = gprofiles[6].loudSpeakerVolumeLevel;

    return loudspkr;
}


/*****************************************************************************
 * FUNCTION
 *  GetKeypadVolumeLevel
 * DESCRIPTION
 *  Setting Keypad Volume Level for a Profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_VOLUME_LEVEL_ENUM GetKeypadVolumeLevel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_VOLUME_LEVEL_ENUM keypadVolumeLevel;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    keypadVolumeLevel = gcurrentprofile.keypadVolumeLevel;

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_TRC_GET_KEYPAD_VOL,keypadVolumeLevel);

    return keypadVolumeLevel;
}


/*****************************************************************************
 * FUNCTION
 *  GetMtCallAlertTypeEnum
 * DESCRIPTION
 *  Setting Call Alert type for a Profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_ALERT_TYPE GetMtCallAlertTypeEnum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ALERT_TYPE mtCallAlertTypeEnum;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mtCallAlertTypeEnum = gcurrentprofile.mtCallAlertTypeEnum;

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_TRC_GET_CALL_ALERT_TYPE,mtCallAlertTypeEnum);
 
    return mtCallAlertTypeEnum;
}


/*****************************************************************************
 * FUNCTION
 *  GetLightStatus
 * DESCRIPTION
 *  Setting Light for a Profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_LEDLIGHT_STATUS_ENUM GetLightStatus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    LIGHT templight;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    templight.status = gcurrentprofile.light.status;

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_TRC_GET_LIGHT_STATUS,templight.status);

    return templight.status;
}


/*****************************************************************************
 * FUNCTION
 *  GetRingTypeEnum
 * DESCRIPTION
 *  Setting Ring_Type for a Profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_RING_TYPE_ENUM GetRingTypeEnum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_RING_TYPE_ENUM ringType;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ringType = gcurrentprofile.ringTypeEnum;

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_TRC_GET_RING_TYPE,ringType);

    switch (ringType)
    {
        case SINGLE:
            return 2;
        case REPEAT:
            return 1;
        case ASCENDING:
            return 0;
        default:
            return 1;
    }
 
}

#ifdef __MMI_CONNECT_NOTICE__


/*****************************************************************************
 * FUNCTION
 *  GetConnectNoticeType
 * DESCRIPTION
 *  Setting Call Alert type for a Profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 GetConnectNoticeType(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_CONNECT_NOTICE_TYPE connectNotice;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    connectNotice = gcurrentprofile.extraTone.connectTone;

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_TRC_GET_CONNECT_NOTICE_TYPE,connectNotice);

    return (U16) connectNotice;
}
#endif /* __MMI_CONNECT_NOTICE__ */ 


/*****************************************************************************
 * FUNCTION
 *  GetAnsweringMode
 * DESCRIPTION
 *  Setting Answering mode for a Profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_profiles_answering_mode_struct *GetAnsweringMode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static mmi_profiles_answering_mode_struct answeringMode;
    MMI_BOOL is_test_sim1 = MMI_FALSE;
    MMI_BOOL is_test_sim2 = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __GEMINI__
    is_test_sim1 = is_test_sim(0x00) && mmi_ucm_app_incoming_call(MMI_UCM_VOICE_CALL_TYPE | MMI_UCM_VIDEO_CALL_TYPE) ;
    is_test_sim2 = is_test_sim(0x01) && mmi_ucm_app_incoming_call(MMI_UCM_VOICE_CALL_TYPE_SIM2) ;
#else
    is_test_sim1 = is_test_sim() && mmi_ucm_app_incoming_call(MMI_UCM_VOICE_CALL_TYPE | MMI_UCM_VIDEO_CALL_TYPE) ;
#endif


#ifdef __MMI_CLAMSHELL__
    answeringMode.coverAnswer = gcurrentprofile.answeringMode.coverAnswer;
#endif 

    if (gactivatedprofile == MMI_PROFILE_HEADSET || is_test_sim1 || is_test_sim2)
    {
        answeringMode.automatic = gcurrentprofile.answeringMode.automatic;
    }
    else
    {
        answeringMode.automatic = FALSE;
    }

    //answeringMode.automatic = gcurrentprofile.answeringMode.automatic;
    answeringMode.anyKey = gcurrentprofile.answeringMode.anyKey;

    return &answeringMode;
}


/*****************************************************************************
 * FUNCTION
 *  LoudSpeaker
 * DESCRIPTION
 *  Setting loud speaker for a Profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL LoudSpeaker(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    pBOOL loudSpeaker;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    loudSpeaker = gloudSpeaker;

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_TRC_LOUDSPKR,loudSpeaker);
 
    return loudSpeaker;

}


/*****************************************************************************
 * FUNCTION
 *  FontSizeEnum
 * DESCRIPTION
 *  Setting Font Size for a Profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_FONT_SIZE_ENUM FontSizeEnum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_FONT_SIZE_ENUM fontSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fontSize = gcurrentprofile.fontSizeEnum;

    return fontSize;
}


/*****************************************************************************
 * FUNCTION
 *  GetConnectToneStatus
 * DESCRIPTION
 *  Setting Extra Tone for a Profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL GetConnectToneStatus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EXTRA_TONE tempExtraTone;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tempExtraTone.connectTone = gcurrentprofile.extraTone.connectTone;

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_TRC_GET_CONNECT_TONE_STATUS,tempExtraTone.connectTone);
 
    return tempExtraTone.connectTone;
}


/*****************************************************************************
 * FUNCTION
 *  GetErrorToneStatus
 * DESCRIPTION
 *  Setting Extra Tone for a Profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL GetErrorToneStatus(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EXTRA_TONE tempExtraTone;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tempExtraTone.errorTone = gcurrentprofile.extraTone.errorTone;

    return tempExtraTone.errorTone;
}


/*****************************************************************************
 * FUNCTION
 *  GetRingToneID
 * DESCRIPTION
 *  Setting ringtone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 GetRingToneID(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_profiles_tone_struct temptoneSetup;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temptoneSetup.ringTone = gcurrentprofile.toneSetup.ringTone;


    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_TRC_GET_RING_TONE_ID,temptoneSetup.ringTone);

    return temptoneSetup.ringTone;
}

#ifdef __MMI_DUAL_PROFILE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  GetCard2RingToneID
 * DESCRIPTION
 *  Get card2 ring tone id of current profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 GetCard2RingToneID(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_profiles_tone_struct temptoneSetup;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temptoneSetup.card2_ringTone = gcurrentprofile.toneSetup.card2_ringTone;

    return temptoneSetup.card2_ringTone;
}
#endif /*__MMI_DUAL_PROFILE_SUPPORT__*/

#ifdef __MMI_VIDEO_TELEPHONY__

/*****************************************************************************
 * FUNCTION
 *  GetVideoCallToneID
 * DESCRIPTION
 *  Get video call tone id of current profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 GetVideoCallToneID(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_profiles_tone_struct temptoneSetup;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temptoneSetup.videoCallTone = gcurrentprofile.toneSetup.videoCallTone;

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_TRC_GET_VDO_CALL_TONE_ID,temptoneSetup.videoCallTone);
 
    return temptoneSetup.videoCallTone;
}
#endif /*__MMI_VIDEO_TELEPHONY__*/

#ifndef __MMI_POWER_ON_OFF_MUTE__
/*****************************************************************************
 * FUNCTION
 *  GetPowerOnToneType
 * DESCRIPTION
 *  Setting power tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
POWERON_TONE_ENUM GetPowerOnToneType(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_profiles_tone_struct temptoneSetup;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temptoneSetup.powerOnTone = gcurrentprofile.toneSetup.powerOnTone;

    return temptoneSetup.powerOnTone;
}


/*****************************************************************************
 * FUNCTION
 *  GetPowerOffToneType
 * DESCRIPTION
 *  Setting power tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
POWEROFF_TONE_ENUM GetPowerOffToneType(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_profiles_tone_struct temptoneSetup;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temptoneSetup.powerOffTone = gcurrentprofile.toneSetup.powerOffTone;

    return temptoneSetup.powerOffTone;
}
#endif /*__MMI_POWER_ON_OFF_MUTE__*/

#ifdef __MMI_CLAMSHELL__
/*****************************************************************************
 * FUNCTION
 *  GetCoverOpenToneType
 * DESCRIPTION
 *  Setting coveropentone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
COVER_OPEN_TONE_ENUM GetCoverOpenToneType(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_profiles_tone_struct temptoneSetup;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temptoneSetup.coverOpenTone = gcurrentprofile.toneSetup.coverOpenTone;


    return temptoneSetup.coverOpenTone;
}


/*****************************************************************************
 * FUNCTION
 *  GetCoverCloseToneType
 * DESCRIPTION
 *  Setting power tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
COVER_CLOSE_TONE_ENUM GetCoverCloseToneType(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_profiles_tone_struct temptoneSetup;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temptoneSetup.coverCloseTone = gcurrentprofile.toneSetup.coverCloseTone;

    return temptoneSetup.coverCloseTone;
}
#endif /* __MMI_CLAMSHELL__ */ 

/*****************************************************************************
 * FUNCTION
 *  GetKeypadToneType
 * DESCRIPTION
 *  Setting Keypad tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
KEYPAD_TONE_ENUM GetKeypadToneType(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_profiles_tone_struct temptoneSetup;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temptoneSetup.keypadTone = gcurrentprofile.toneSetup.keypadTone;

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_TRC_GET_KEYPAD_TONE_TYPE,temptoneSetup.keypadTone);
  
    return temptoneSetup.keypadTone;
}


/*****************************************************************************
 * FUNCTION
 *  GetWarningToneType
 * DESCRIPTION
 *  Setting warning tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL GetWarningToneType(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EXTRA_TONE temptoneSetup;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temptoneSetup.warningTone = gcurrentprofile.extraTone.warningTone;

    return temptoneSetup.warningTone;
}

/*****************************************************************************
 * FUNCTION
 *  GetAlarmToneType
 * DESCRIPTION
 *  Setting warning tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
ALARM_TONE_ENUM GetAlarmToneType(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_profiles_tone_struct temptoneSetup;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temptoneSetup.alarmTone = gcurrentprofile.toneSetup.alarmTone;

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_TRC_GET_ALARM_TONE_ID,temptoneSetup.alarmTone);
 
    return (ALARM_TONE_ENUM) (temptoneSetup.alarmTone);
}


/*****************************************************************************
 * FUNCTION
 *  get_lcdbacklighttimer
 * DESCRIPTION
 *  Setting lcdbacklight timer value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 get_lcdbacklighttimer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    LIGHT tempLight;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_USB_SUPPORT__
    if (INT_USBBoot())
    {
        return MMI_PROF_GENERAL_KEYPAD_TIMER_DUR;
    }
#endif /* __MMI_USB_SUPPORT__ */ 

    tempLight.timer.setsec = gcurrentprofile.light.timer.setsec;

    return tempLight.timer.setsec;
}


/*****************************************************************************
 * FUNCTION
 *  ActivateProfile
 * DESCRIPTION
 *  Activating a profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ActivateProfile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_PROFILES_ACTIVATED, &gactivatedprofile, DS_BYTE, &error);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_TRC_ACTIVATE_PROFILE,(int)gactivatedprofile); 

    if (gactivatedprofile == 0xff)
    {
        gactivatedprofile = 0;
        WriteValue(NVRAM_PROFILES_ACTIVATED, &gactivatedprofile, DS_BYTE, &error);
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(mmi_profiles_cntx_struct));

        /* SetRingerVolume(GetRingVolumeLevel()); */
        mdi_audio_set_volume_no_apply(MDI_VOLUME_MEDIA, GetRingVolumeLevel());

        SetKeyPadVolume(GetKeypadVolumeLevel());
    }
    else
    {
        memcpy(&gcurrentprofile, &gprofiles[gactivatedprofile], sizeof(mmi_profiles_cntx_struct));

        /* SetRingerVolume(GetRingVolumeLevel()); */
        mdi_audio_set_volume_no_apply(MDI_VOLUME_MEDIA, GetRingVolumeLevel());

        SetKeyPadVolume(GetKeypadVolumeLevel());
    }
    mdi_audio_set_mic_volume();
    mmi_profiles_show_alert_status_icon();
    change_font();

#if defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT)
    mmi_imps_set_presence_from_phnprof(gcurrentprofile.impsStatus);
#endif

#ifdef __MMI_PROF_MUTE_APP_ON_SILENT_MODE__
#ifdef __MMI_MEDIA_PLAYER__
    if(gactivatedprofile == MMI_PROFILE_SILENT || gactivatedprofile == MMI_PROFILE_MEETING)
    {
        mmi_medply_set_mute_callback();
    }
#endif
#endif

}


/*****************************************************************************
 * FUNCTION
 *  ActivatefirstProfile
 * DESCRIPTION
 *  Activating the profile first time bootup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ActivatefirstProfile()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gactivatedprofile = gprofileId;
    memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(mmi_profiles_cntx_struct));
}

/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_restore_activated_profile
 * DESCRIPTION
 *  restore audio mode & current activated profile after factory mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_restore_activated_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_gpio_is_earphone_plug_in())
    {
        /* enter headset mode */
        mdi_audio_set_audio_mode(AUD_MODE_HEADSET);
        SetModeSpeechVolume();
        mmi_profiles_headset_activate_profile();
    }
    else
    {
        /* enter non-headset mode */
        mdi_audio_set_audio_mode(AUD_MODE_NORMAL);
        SetModeSpeechVolume();
        ActivateProfile();
    }
}


/*****************************************************************************
 * FUNCTION
 *  ActivateSilentProfile
 * DESCRIPTION
 *  Silent Profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ActivateSilentProfile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    MMI_BOOL from_options = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(GetActiveScreenId() == SCR_PROFILES_OPTIONS)
    {
        from_options = MMI_TRUE;
    }

#ifdef __MMI_BT_PROFILE__
    if ((gprofileheadset != 1) && (gactivatedprofile != MMI_PROFILE_BT))
#else 
    if (gprofileheadset != 1)
#endif 
    {
        memcpy(&gcurrentprofile, &gprofiles[gactivatedprofile], sizeof(mmi_profiles_cntx_struct));
        /*in case user activate silent profile twice*/
        if(gactivatedprofile != MMI_PROFILE_SILENT)
        {
            glastactivatedprofile = gactivatedprofile;
        }
        gactivatedprofile = gprofileId = MMI_PROFILE_SILENT;
        WriteValue(NVRAM_PROFILES_ACTIVATED, &gactivatedprofile, DS_BYTE, &error);
        WriteValue(NVRAM_PROFILES_LASTACTIVATED, &glastactivatedprofile, DS_BYTE, &error);
        /* MTK brian modified to make it vibrate in silent mode, 2003/10/28 */
        gcurrentprofile.mtCallAlertTypeEnum = MMI_VIBRATION_ONLY;
        /* MTK brian added to wrap cover open/close tone setup, 2003/10/18 */
    #ifdef __MMI_CLAMSHELL__
        gcurrentprofile.toneSetup.coverCloseTone = COVER_CLOSE_SILENT;
        gcurrentprofile.toneSetup.coverOpenTone = COVER_OPEN_SILENT;
    #endif /* __MMI_CLAMSHELL__ */ 
        /* MTK end */
        gcurrentprofile.toneSetup.keypadTone = KEYPAD_SILENT;
    #ifndef __MMI_PROF_SPLIT_MSG_TONES__ 
        gcurrentprofile.toneSetup.messageTone = MESSAGE_SILENT;
    #else
    #ifdef MMS_SUPPORT
        gcurrentprofile.toneSetup.mmsTone = MESSAGE_SILENT;
    #endif
        gcurrentprofile.toneSetup.smsTone = MESSAGE_SILENT;
    #ifdef __MMI_EMAIL__
        gcurrentprofile.toneSetup.emailTone = MESSAGE_SILENT;
    #endif
    #ifdef __MMI_OP11_MMS_SUPPORT_AUDIO_MSG__
/* under construction !*/
    #endif

    #endif /*__MMI_PROF_SPLIT_MSG_TONES__*/
    #ifndef __MMI_POWER_ON_OFF_MUTE__        
        gcurrentprofile.toneSetup.powerOffTone = POWEROFF_SILENT;
        gcurrentprofile.toneSetup.powerOnTone = POWERON_SILENT;
    #endif /*__MMI_POWER_ON_OFF_MUTE__*/

    #if defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT)
        gcurrentprofile.toneSetup.IMPSContactOnlineTone= MESSAGE_SILENT;
        gcurrentprofile.toneSetup.IMPSNewMessageTone= MESSAGE_SILENT;
        gcurrentprofile.toneSetup.IMPSNewInvitationTone= MESSAGE_SILENT;
        gcurrentprofile.toneSetup.IMPSChatroomNotificationTone= MESSAGE_SILENT;
    #endif

        gcurrentprofile.extraTone.campOnTone = 0;
        gcurrentprofile.extraTone.errorTone = 0;
        gcurrentprofile.extraTone.connectTone = 0;
        gcurrentprofile.extraTone.warningTone = 0;

        gcurrentprofile.intelligentCallAlert = MMI_INTELLIGENT_CALL_ALERT_OFF;
#if defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT)        
        gcurrentprofile.impsStatus = IMPS_PHB_PA_USER_DISCREET ;
#endif

        memcpy(&gprofiles[gactivatedprofile], &gcurrentprofile, sizeof(mmi_profiles_cntx_struct));
        mmi_profiles_write_cntx_to_nvram();

        if(from_options)
        {
            mmi_display_popup((UI_string_type)GetString(STR_GLOBAL_ACTIVATED),MMI_EVENT_SUCCESS);
            DeleteNHistory(1);
        }
        else
        {
            mmi_display_popup((UI_string_type)GetString(STR_SILENT_ACTIVATE_MESSAGE),MMI_EVENT_SUCCESS);
        }
        DeleteScreenIfPresent(IDLE_SCREEN_DIGIT_HANDLER_ID);
        DeleteScreenIfPresent(SCR_DIAL_SOS_NUM); /* enable toggle profile from sim error screen */

        mmi_profiles_show_alert_status_icon();

#if defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT)
        mmi_imps_set_presence_from_phnprof(gcurrentprofile.impsStatus);
#endif

#ifdef __MMI_PROF_MUTE_APP_ON_SILENT_MODE__
#ifdef __MMI_MEDIA_PLAYER__
        mmi_medply_set_mute_callback();
#endif
#endif

        if(!from_options)
        {
            PlayVibratorOnce();
        }

    }

}


/*****************************************************************************
 * FUNCTION
 *  DeactivateSilentProfile
 * DESCRIPTION
 *  DeactivateSilent Profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void DeactivateSilentProfile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gactivatedprofile == MMI_PROFILE_SILENT)
    {
        gprofileId = 0;
        gactivatedprofile = glastactivatedprofile;
        memcpy(&gcurrentprofile, &gprofiles[gactivatedprofile], sizeof(mmi_profiles_cntx_struct));
        WriteValue(NVRAM_PROFILES_ACTIVATED, &gactivatedprofile, DS_BYTE, &error);

        /* SetRingerVolume(GetRingVolumeLevel()); */
        mdi_audio_set_volume_no_apply(MDI_VOLUME_MEDIA, GetRingVolumeLevel());

        SetKeyPadVolume(GetKeypadVolumeLevel());
        change_font();

        switch (gactivatedprofile)
        {
            case MMI_PROFILE_GENERAL:
                mmi_display_popup((UI_string_type)GetString(STR_GENERAL_RESTORED_MESSAGE),MMI_EVENT_SUCCESS);
                break;

            case MMI_PROFILE_MEETING:
                mmi_display_popup((UI_string_type)GetString(STR_MEETING_RESTORED_MESSAGE),MMI_EVENT_SUCCESS);
                break;

            case MMI_PROFILE_OUTDOOR:
                mmi_display_popup((UI_string_type)GetString(STR_OUTDOOR_RESTORED_MESSAGE),MMI_EVENT_SUCCESS);
                break;

            case MMI_PROFILE_INDOOR:
                mmi_display_popup((UI_string_type)GetString(STR_INDOOR_RESTORED_MESSAGE),MMI_EVENT_SUCCESS);
                break;

            case MMI_PROFILE_HEADSET:
                break;

            case MMI_PROFILE_SILENT:
                break;
        #ifdef __MMI_BT_PROFILE__
            case MMI_PROFILE_BT:
                break;
        #endif 
        }
        DeleteScreenIfPresent(IDLE_SCREEN_DIGIT_HANDLER_ID);
        DeleteScreenIfPresent(SCR_DIAL_SOS_NUM); /* enable toggle profile from sim error screen */

        mmi_profiles_show_alert_status_icon();

    #if defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT)
        mmi_imps_set_presence_from_phnprof(gcurrentprofile.impsStatus);
    #endif

    #ifdef __MMI_PROF_MUTE_APP_ON_SILENT_MODE__
    #ifdef __MMI_MEDIA_PLAYER__
        if(gactivatedprofile == MMI_PROFILE_MEETING)
        {
            mmi_medply_set_mute_callback();
        }
    #endif
    #endif

    }
}

/*************************************************************************
               Set Functions
**************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  SetRingVolumeLevel
 * DESCRIPTION
 *  Setting Ring Volume Level
 * PARAMETERS
 *  volumelevel     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetRingVolumeLevel(MMI_VOLUME_LEVEL_ENUM volumelevel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_VOLUME_LEVEL_ENUM ringVolumeLevel;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gprofileId].ringVolumeLevel = volumelevel;

    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(mmi_profiles_cntx_struct));
    }

    ringVolumeLevel = gprofiles[gactivatedprofile].ringVolumeLevel;

    SetRingerVolume(ringVolumeLevel);

    if(!mmi_profiles_write_cntx_to_nvram())
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_ERR_SET_RING_VOL); 
        return -1;
    }

    return 0;
}

/* MTK Brian added for setting activated ring tone volume, 2003/12/02 */


/*****************************************************************************
 * FUNCTION
 *  SetActivatedRingVolumeLevel
 * DESCRIPTION
 *  Setting Ring Volume Level of the Activated Profile
 * PARAMETERS
 *  volumelevel     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetActivatedRingVolumeLevel(MMI_VOLUME_LEVEL_ENUM volumelevel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gactivatedprofile].ringVolumeLevel = volumelevel;
    gcurrentprofile.ringVolumeLevel = volumelevel;

    SetRingerVolume(volumelevel);

    if(!mmi_profiles_write_cntx_to_nvram())
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_ERR_SET_ACTIVATED_RING_VOL); 
        return -1;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  SetKeypadVolumeLevel
 * DESCRIPTION
 *  Setting Keypad Volume Level
 * PARAMETERS
 *  volumelevel     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetKeypadVolumeLevel(MMI_VOLUME_LEVEL_ENUM volumelevel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_VOLUME_LEVEL_ENUM keypadVolumelevel;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gprofileId].keypadVolumeLevel = volumelevel;

    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(mmi_profiles_cntx_struct));
    }

    keypadVolumelevel = gprofiles[gactivatedprofile].keypadVolumeLevel;

    SetKeyPadVolume(keypadVolumelevel);

    if(!mmi_profiles_write_cntx_to_nvram())
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_ERR_SET_KEYPAD_VOL); 
        return -1;
    }

    return 0;
}

/* MTK Brian added for setting activated keypad volume, 2003/12/02 */


/*****************************************************************************
 * FUNCTION
 *  SetActivatedKeypadVolumeLevel
 * DESCRIPTION
 *  Setting Keypad Volume Level of the Activated Profile
 * PARAMETERS
 *  volumelevel     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetActivatedKeypadVolumeLevel(MMI_VOLUME_LEVEL_ENUM volumelevel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gactivatedprofile].keypadVolumeLevel = volumelevel;
    gcurrentprofile.keypadVolumeLevel = volumelevel;

    SetKeyPadVolume(volumelevel);

    if(!mmi_profiles_write_cntx_to_nvram())
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_ERR_SET_ACTIVATED_KEYPAD_VOL);
        return -1;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  SetMtCallAlertTypeEnum
 * DESCRIPTION
 *  Setting Call Alert Type
 * PARAMETERS
 *  callalerttype       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetMtCallAlertTypeEnum(MMI_ALERT_TYPE callalerttype)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MTK Brian modified to skip writing nvram if no change, 2003/11/26 */
    if (gprofiles[gprofileId].mtCallAlertTypeEnum != callalerttype)
    {
        gprofiles[gprofileId].mtCallAlertTypeEnum = callalerttype;

        if (gactivatedprofile == gprofileId)
        {
            memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(mmi_profiles_cntx_struct));
        }

        mmi_profiles_show_alert_status_icon();

        if(!mmi_profiles_write_cntx_to_nvram())
        {
            MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_ERR_SET_CALL_ALERT_TYPE);
            return -1;
        }

    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  SetRingToneID
 * DESCRIPTION
 *  Setting Ring tone ID.
 * PARAMETERS
 *  ringtoneid      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetRingToneID(U16 ringtoneid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gprofileId].toneSetup.ringTone = ringtoneid;

    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(mmi_profiles_cntx_struct));
    }

    if(!mmi_profiles_write_cntx_to_nvram())
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_ERR_SET_RING_TONE_ID); 
        return -1;
    }

    return 0;
}

#ifdef __MMI_DUAL_PROFILE_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  SetCard2RingToneID
 * DESCRIPTION
 *  Setting Card2 Ring tone ID.
 * PARAMETERS
 *  ringtoneid      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetCard2RingToneID(U16 ringtoneid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gprofiles[gprofileId].toneSetup.card2_ringTone = ringtoneid;

    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(mmi_profiles_cntx_struct));
    }

    if(!mmi_profiles_write_cntx_to_nvram())
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_ERR_SET_CARD2_RING_TONE_ID); 
        return -1;
    }

    return 0;
}

#endif /*__MMI_DUAL_PROFILE_SUPPORT__*/

#ifdef __MMI_VIDEO_TELEPHONY__
/*****************************************************************************
 * FUNCTION
 *  SetVideoCallToneID
 * DESCRIPTION
 *  Setting Video Call tone ID.
 * PARAMETERS
 *  ringtoneid      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetVideoCallToneID(U16 videocalltoneId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U16 j = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gprofileId].toneSetup.videoCallTone = videocalltoneId;

    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(mmi_profiles_cntx_struct));
    }

    if(!mmi_profiles_write_cntx_to_nvram())
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_ERR_SET_VDO_CALL_TONE_ID); 
        return -1;
    }

    return 0;
}
#endif

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  ThemeManagerSetRingTone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ringtoneid      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ThemeManagerSetRingTone(U16 ringtoneid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gactivatedprofile].toneSetup.ringTone = ringtoneid;
    mmi_profiles_write_cntx_to_nvram();
    memcpy(&gcurrentprofile, &gprofiles[gactivatedprofile], sizeof(mmi_profiles_cntx_struct));
}


/*****************************************************************************
 * FUNCTION
 *  ThemeManagerResetRingTone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ThemeManagerResetRingTone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 flag = 0, i;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_ELEMENTS; ++i)
    {
        if (gprofiles[i].toneSetup.ringTone == CURRENT_THEME_INCOMING_CALL_TONE)
        {
            flag = 1;
            gprofiles[i].toneSetup.ringTone = MIDI_1;
        }
    }
    if (flag)
    {
        mmi_profiles_write_cntx_to_nvram();
        memcpy(&gcurrentprofile, &gprofiles[gactivatedprofile], sizeof(mmi_profiles_cntx_struct));
    }
}

#ifdef __MMI_DUAL_PROFILE_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  ThemeManagerSetCard2RingTone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ringtoneid      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ThemeManagerSetCard2RingTone(U16 ringtoneid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gactivatedprofile].toneSetup.card2_ringTone = ringtoneid;
    mmi_profiles_write_cntx_to_nvram();
    memcpy(&gcurrentprofile, &gprofiles[gactivatedprofile], sizeof(mmi_profiles_cntx_struct));
}

/*****************************************************************************
 * FUNCTION
 *  ThemeManagerResetCard2RingTone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ThemeManagerResetCard2RingTone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 flag = 0, i;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_ELEMENTS; ++i)
    {
        if (gprofiles[i].toneSetup.card2_ringTone == CURRENT_THEME_INCOMING_CALL_TONE)
        {
            flag = 1;
            gprofiles[i].toneSetup.card2_ringTone = MIDI_1;
        }
    }
    if (flag)
    {
        mmi_profiles_write_cntx_to_nvram();
        memcpy(&gcurrentprofile, &gprofiles[gactivatedprofile], sizeof(mmi_profiles_cntx_struct));
    }
}
#endif /*__MMI_DUAL_PROFILE_SUPPORT__*/

#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  SetLightStatus
 * DESCRIPTION
 *  Setting Light status (Color)
 * PARAMETERS
 *  backlightstatus     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetLightStatus(MMI_LEDLIGHT_STATUS_ENUM backlightstatus)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gprofileId].light.status = backlightstatus;

    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(mmi_profiles_cntx_struct));
    }

    if(gactivatedprofile == MMI_PROFILE_SILENT && glastactivatedprofile == gprofileId)
    {
        gcurrentprofile.light.status = backlightstatus;
    }

    if(!mmi_profiles_write_cntx_to_nvram())
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_ERR_SET_LIGHT_STATUS);  
        return -1;
    }
    
    return 0;
}

#if defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT)
/*****************************************************************************
 * FUNCTION
 *  SetIMPSStatus
 * DESCRIPTION
 *  Setting IMPS Status
 * PARAMETERS
 *  impsStatus     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetIMPSStatus(U8 impsStatus)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U16 j = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gprofileId].impsStatus = impsStatus;

    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(mmi_profiles_cntx_struct));
        mmi_imps_set_presence_from_phnprof(gcurrentprofile.impsStatus);
    }

    if(!mmi_profiles_write_cntx_to_nvram())
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_ERR_SET_IMPS_STATUS);
        return -1;
    }

    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  SetIMPSContactOnlineToneType
 * DESCRIPTION
 *  Setting IMPS conatact online tone
 * PARAMETERS
 *  tone        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetIMPSContactOnlineToneType(mmi_profiles_tone_struct tone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U16 j = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gprofileId].toneSetup.IMPSContactOnlineTone = tone.IMPSContactOnlineTone;

    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(mmi_profiles_cntx_struct));
    }

    if(!mmi_profiles_write_cntx_to_nvram())
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_ERR_SET_IMPS_CONTACT_TONE);
        return -1;
    }

    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  SetIMPSNewMessageToneType
 * DESCRIPTION
 *  Setting IMPS new message tone
 * PARAMETERS
 *  tone        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetIMPSNewMessageToneType(mmi_profiles_tone_struct tone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U16 j = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gprofileId].toneSetup.IMPSNewMessageTone= tone.IMPSNewMessageTone;

    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(mmi_profiles_cntx_struct));
    }

    if(!mmi_profiles_write_cntx_to_nvram())
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_ERR_SET_IMPS_MESSAGE_TONE);
        return -1;
    }

    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  SetIMPSNewInvitationToneType
 * DESCRIPTION
 *  Setting IMPS new invitation tone
 * PARAMETERS
 *  tone        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetIMPSNewInvitationToneType(mmi_profiles_tone_struct tone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U16 j = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gprofileId].toneSetup.IMPSNewInvitationTone = tone.IMPSNewInvitationTone;

    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(mmi_profiles_cntx_struct));
    }

    if(!mmi_profiles_write_cntx_to_nvram())
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_ERR_SET_IMPS_INVITE_TONE);
        return -1;
    }

    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  SetIMPSChatroomNotificationToneType
 * DESCRIPTION
 *  Setting IMPS chatroom notification tone
 * PARAMETERS
 *  tone        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetIMPSChatroomNotificationToneType(mmi_profiles_tone_struct tone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U16 j = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gprofileId].toneSetup.IMPSChatroomNotificationTone= tone.IMPSChatroomNotificationTone;

    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(mmi_profiles_cntx_struct));
    }

    if(!mmi_profiles_write_cntx_to_nvram())
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_ERR_SET_IMPS_CHATROOM_TONE);
        return -1;
    }

    return 0;
}

#endif /* __MMI_IMPS__ && IMPS_WV13_ENHANCEMENT */

/*****************************************************************************
 * FUNCTION
 *  SetRingTypeEnum
 * DESCRIPTION
 *  Setting Ring Type
 * PARAMETERS
 *  ringtype        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetRingTypeEnum(MMI_RING_TYPE_ENUM ringtype)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gprofileId].ringTypeEnum = ringtype;

    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(mmi_profiles_cntx_struct));
    }

    if(!mmi_profiles_write_cntx_to_nvram())
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_ERR_SET_RING_TYPE); 
        return -1;
    }

    return 0;
}

#ifdef __MMI_CONNECT_NOTICE__


/*****************************************************************************
 * FUNCTION
 *  SetConnectNotice
 * DESCRIPTION
 *  Setting Connect Notice Type
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetConnectNotice(U16 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U16 j = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gprofileId].extraTone.connectTone = type;

    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(mmi_profiles_cntx_struct));
    }

    if(!mmi_profiles_write_cntx_to_nvram())
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_ERR_SET_CONNECT_NOTICE); 
        return -1;
    }

    return 0;
}
#endif /* __MMI_CONNECT_NOTICE__ */ 


/*****************************************************************************
 * FUNCTION
 *  SetAnsweringMode
 * DESCRIPTION
 *  Setting Answering Mode
 * PARAMETERS
 *  answeringmode       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetAnsweringMode(mmi_profiles_answering_mode_struct answeringmode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(&gprofiles[gprofileId].answeringMode, &answeringmode, sizeof(mmi_profiles_answering_mode_struct));

    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(mmi_profiles_cntx_struct));
    }

    if(gactivatedprofile == MMI_PROFILE_SILENT && glastactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile.answeringMode, &answeringmode, sizeof(mmi_profiles_answering_mode_struct));
    }

    if(!mmi_profiles_write_cntx_to_nvram())
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_ERR_SET_ANSERING_MODE); 
        return -1;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  SetLoudSpeaker
 * DESCRIPTION
 *  Setting Loud Speaker (On/Off)
 * PARAMETERS
 *  loudspeaker     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetLoudSpeaker(pBOOL loudspeaker)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (loudspeaker == 1)
    {
        gloudSpeaker = loudspeaker;
    }
    else
    {
        gloudSpeaker = loudspeaker;
    }

    SetRingerVolume(GetRingVolumeLevel());
    SetKeyPadVolume(GetKeypadVolumeLevel());

    return 0;

}


/*****************************************************************************
 * FUNCTION
 *  SetErrorToneStatus
 * DESCRIPTION
 *  Setting Error Tone status (On/Off)
 * PARAMETERS
 *  errortonestatus     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetErrorToneStatus(pBOOL errortonestatus)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gprofileId].extraTone.errorTone = errortonestatus;

    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(mmi_profiles_cntx_struct));
    }

    mmi_profiles_write_cntx_to_nvram();

    return 0;
}

#ifndef __MMI_POWER_ON_OFF_MUTE__
/*****************************************************************************
 * FUNCTION
 *  SetPowerOnToneType
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tone        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetPowerOnToneType(mmi_profiles_tone_struct tone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gprofileId].toneSetup.powerOnTone = tone.powerOnTone;

    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(mmi_profiles_cntx_struct));
    }

    if(!mmi_profiles_write_cntx_to_nvram())
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_ERR_SET_POWER_ON_TONE); 
        return -1;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  SetPowerOffToneType
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tone        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetPowerOffToneType(mmi_profiles_tone_struct tone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gprofileId].toneSetup.powerOffTone = tone.powerOffTone;

    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(mmi_profiles_cntx_struct));
    }

    if(!mmi_profiles_write_cntx_to_nvram())
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_ERR_SET_POWER_OFF_TONE); 
        return -1;
    }

    return 0;
}
#endif /*__MMI_POWER_ON_OFF_MUTE__*/


#ifdef __MMI_CLAMSHELL__
/*****************************************************************************
 * FUNCTION
 *  SetCoverOpenToneType
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tone        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetCoverOpenToneType(mmi_profiles_tone_struct tone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U16 j = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gprofileId].toneSetup.coverOpenTone = tone.coverOpenTone;

    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(mmi_profiles_cntx_struct));
    }

    if(!mmi_profiles_write_cntx_to_nvram())
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_ERR_SET_COVER_OPEN_TONE); 
        return -1;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  SetCoverCloseToneType
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tone        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetCoverCloseToneType(mmi_profiles_tone_struct tone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U16 j = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gprofileId].toneSetup.coverCloseTone = tone.coverCloseTone;

    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(mmi_profiles_cntx_struct));
    }

    if(!mmi_profiles_write_cntx_to_nvram())
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_ERR_SET_COVER_CLOSE_TONE); 
        return -1;
    }

    return 0;
}
#endif /* __MMI_CLAMSHELL__ */ 

/*****************************************************************************
 * FUNCTION
 *  SetKeypadToneType
 * DESCRIPTION
 *  
 * PARAMETERS
 *  keypadtone      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetKeypadToneType(KEYPAD_TONE_ENUM keypadtone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gprofileId].toneSetup.keypadTone = keypadtone;

    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(mmi_profiles_cntx_struct));
    }

    if(!mmi_profiles_write_cntx_to_nvram())
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_ERR_SET_KEYPAD_TONE); 
        return -1;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  GetIntelligentCallAert
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_INTELLIGENT_CALL_ALERT_TYPE
 *****************************************************************************/
MMI_INTELLIGENT_CALL_ALERT_TYPE GetIntelligentCallAert(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_INTELLIGENT_CALL_ALERT_TYPE intelligentCallAlert = gcurrentprofile.intelligentCallAlert;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_TRC_GET_INTEL_CALL_ALERT,intelligentCallAlert);
 
    return intelligentCallAlert;
}


/*****************************************************************************
 * FUNCTION
 *  SetIntelligentCallAert
 * DESCRIPTION
 *  
 * PARAMETERS
 *  intelligentCallAlert        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetIntelligentCallAert(MMI_INTELLIGENT_CALL_ALERT_TYPE intelligentCallAlert)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gprofileId].intelligentCallAlert = intelligentCallAlert;

    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(mmi_profiles_cntx_struct));
    }

    if(!mmi_profiles_write_cntx_to_nvram())
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_ERR_SET_INTEL_CALL_ALERT); 
        return -1;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  SetMessageToneType
 * DESCRIPTION
 *  Setting Message Tone
 * PARAMETERS
 *  tone        [IN]
 *  type        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetMessageToneType(mmi_profiles_tone_struct tone, mmi_profile_message_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(type)
    {
    #ifndef __MMI_PROF_SPLIT_MSG_TONES__
        case MMI_PROFILE_MESSAGE_TYPE_MESSAGE:
        {
            gprofiles[gprofileId].toneSetup.messageTone = tone.messageTone;
            break;
        }
    #else

        case MMI_PROFILE_MESSAGE_TYPE_SMS:
        {
            gprofiles[gprofileId].toneSetup.smsTone = tone.smsTone;        
            break;
        }
    #ifdef MMS_SUPPORT
        case MMI_PROFILE_MESSAGE_TYPE_MMS:
        {
            gprofiles[gprofileId].toneSetup.mmsTone = tone.mmsTone;
            break;
        }
        #endif
   #ifdef __MMI_EMAIL__
        case MMI_PROFILE_MESSAGE_TYPE_EMAIL:
        {
            gprofiles[gprofileId].toneSetup.emailTone = tone.emailTone;
            break;
        }
    #endif
    #ifdef __MMI_OP11_MMS_SUPPORT_AUDIO_MSG__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    #endif /*__MMI_PROF_SPLIT_MSG_TONES__*/
        default:
        {
            break;
        }
    }

    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(mmi_profiles_cntx_struct));
    }

    if(!mmi_profiles_write_cntx_to_nvram())
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_ERR_SET_MESSAGE_TONE); 
        return -1;
    }

    return 0;
}

#ifdef __MMI_DUAL_PROFILE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  SetCard2MessageToneType
 * DESCRIPTION
 *  Setting Card2 Message Tone
 * PARAMETERS
 *  tone        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetCard2MessageToneType(mmi_profiles_tone_struct tone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gprofileId].toneSetup.card2_messageTone = tone.card2_messageTone;

    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(mmi_profiles_cntx_struct));
    }

    if(!mmi_profiles_write_cntx_to_nvram())
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_ERR_SET_CARD2_MESSAGE_TONE);
        return -1;
    }

    return 0;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  SetAlarmToneID
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetAlarmToneID(U16 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gprofileId].toneSetup.alarmTone = id;

    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(mmi_profiles_cntx_struct));
    }

    if(!mmi_profiles_write_cntx_to_nvram())
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_ERR_SET_ALARM_TONE); 
        return -1;
    }

    return 0;
}

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__      /* ritesh */


/*****************************************************************************
 * FUNCTION
 *  ThemeManagerSetAlarmTone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ringtoneid      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ThemeManagerSetAlarmTone(U16 ringtoneid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* PMT SHARIQ DLT_PATCH 20060814 START */
#if 0
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
#endif /* 0 */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* PMT SHARIQ DLT_PATCH 20060814 END */
}


/*****************************************************************************
 * FUNCTION
 *  ThemeManagerResetAlarmTone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ThemeManagerResetAlarmTone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 flag = 0, i;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_ELEMENTS; ++i)
    {
        if (gprofiles[i].toneSetup.alarmTone == CURRENT_THEME_ALARM_EXPIRY_TONE)
        {
            flag = 1;
            gprofiles[i].toneSetup.alarmTone = MIDI_2;
        }
    }
#ifdef __MMI_ALM_AUDIO_OPTIONS__
    for (i = 0; i < NUM_OF_ALM; ++i)
    {
        if (g_alm_cntx.AlmList[i].AudioOptionValue == CURRENT_THEME_ALARM_EXPIRY_TONE)
        {
            g_alm_cntx.AlmList[i].AudioOption = ALM_AUDIO_OPTIONS_TONE;
            g_alm_cntx.AlmList[i].AudioOptionValue = (U16) (gstartMidiId + 1);
        }
    }
    AlmWriteToNvram();
#endif /* __MMI_ALM_AUDIO_OPTIONS__ */ 

    if (flag)
    {
        mmi_profiles_write_cntx_to_nvram();
        memcpy(&gcurrentprofile, &gprofiles[gactivatedprofile], sizeof(mmi_profiles_cntx_struct));
    }
}
#endif /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */ 


#if 0
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //0

/*****************************************************************************
 * FUNCTION
 *  SetProfileDefault
 * DESCRIPTION
 *  SetProfileDefault
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL SetProfileDefault(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gprofileheadset != 1)
    {
        mmi_profiles_read_cntx_from_nvram(2);
        gactivatedprofile = 0;
        memcpy(&gcurrentprofile, &gprofiles[gactivatedprofile], sizeof(mmi_profiles_cntx_struct));
        mmi_profiles_show_alert_status_icon(); /* function to show status icon on ilde screen */
        mmi_profiles_write_cntx_to_nvram();
        WriteValue(NVRAM_PROFILES_ACTIVATED, &gactivatedprofile, DS_BYTE, &error);

        mdi_audio_set_volume_no_apply(MDI_VOLUME_MEDIA, GetRingVolumeLevel());

        SetKeyPadVolume(GetKeypadVolumeLevel());
        change_font();
        if (error == NVRAM_WRITE_SUCCESS)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
    else
    {
        mmi_profiles_read_cntx_from_nvram(2);
        memcpy(&gcurrentprofile, &gprofiles[gactivatedprofile], sizeof(mmi_profiles_cntx_struct));
        mmi_profiles_show_alert_status_icon(); /* function to show status icon on ilde screen */
        mmi_profiles_write_cntx_to_nvram();
        WriteValue(NVRAM_PROFILES_ACTIVATED, &gactivatedprofile, DS_BYTE, &error);

        /*          
         * #ifdef __MMI_AUDIO_PLAYER__
         * mmi_audply_save_volume( gactivatedprofile );
         * #endif // __MMI_AUDIO_PLAYER__
         * 
         * SetRingerVolume(GetRingVolumeLevel());
         */
        mdi_audio_set_volume_no_apply(MDI_VOLUME_MEDIA, GetRingVolumeLevel());

        SetKeyPadVolume(GetKeypadVolumeLevel());
        change_font();
        if (error == NVRAM_WRITE_SUCCESS)
        {
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  SetExtraTone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  extraTone       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 SetExtraTone(EXTRA_TONE extraTone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofiles[gprofileId].extraTone.warningTone = extraTone.warningTone;
    gprofiles[gprofileId].extraTone.errorTone = extraTone.errorTone;
#ifndef __MMI_CONNECT_NOTICE__
    gprofiles[gprofileId].extraTone.connectTone = extraTone.connectTone;
#endif 
    gprofiles[gprofileId].extraTone.campOnTone = extraTone.campOnTone;

    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(mmi_profiles_cntx_struct));
    }

    if(!mmi_profiles_write_cntx_to_nvram())
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_ERR_SET_EXTRA_TONE); 
        return -1;
    }

    return 0;
}

#ifdef __BT_SPK_VOL_CONTROL__
/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_handfree_volume_sync_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
void mmi_profiles_handfree_volume_sync_callback(U8 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nextScrnId ;
    MMI_BOOL result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(volume <= LEVEL7);

    /*when result is MMI_FALSE, it means there is no other screen above SCR_PROFILES_VOLUME_LEVEL*/
    result = GetNextScrnIdOf(SCR_PROFILES_VOLUME_LEVEL, &nextScrnId);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_TRC_HFP_VOL_SYNC,volume,result,gcommonvolumehandler,gprofileId,gactivatedprofile);

    if( IsScreenPresent(SCR_PROFILES_VOLUME_LEVEL) && !result && GetActiveScreenId() == SCR_KEY_TONE_VOLUME && gcommonvolumehandler == 0)
    {
        /*in profiles volume tunning screen*/

        show_vertical_bar(volume);

        /* ring tone volume setting*/
        RingToneVolumeFunction();

    }
    else if(GetActiveScreenId() == SCR_PROFILES_VOLUME_LEVEL && gprofileId  == gactivatedprofile)
    {

        /*in profile volume setting screen*/
        SetRingVolumeLevel(volume);
        kal_wsprintf((PU16) hintData[0], "%d", (gprofiles[gprofileId].ringVolumeLevel + 1));

        Category52ChangeItemDescription(0, (U8*)hintData[0] );
        RedrawCategoryFunction();
    }
    else
    {
        /*normal screen*/
        gprofiles[gactivatedprofile].ringVolumeLevel = volume;
        memcpy(&gcurrentprofile, &gprofiles[gactivatedprofile], sizeof(mmi_profiles_cntx_struct));

        if(!IsScreenPresent(SCR_KEY_TONE_VOLUME))
        {
            SetRingerVolume(volume);
            mdi_audio_set_volume(MDI_VOLUME_FMR,(U8)(volume));
        }

        if(!mmi_profiles_write_cntx_to_nvram())
        {
            return;
        }

    }
    
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_check_set_mute
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
BOOL mmi_profiles_check_set_mute()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*Audio Player*/
#ifdef __MMI_AUDIO_PLAYER__
     if(mmi_audply_is_playing())
     {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_TRC_CHECK_SET_MUTE, 1);
        return MMI_FALSE;
     }
#endif
    
#ifndef __MMI_MEDIA_PLAYER_AUDIO__
     if(mmi_audply_is_single_play_activated())
     {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_TRC_CHECK_SET_MUTE, 7);
        return MMI_FALSE;
     }
#endif
    
#ifdef __MMI_MEDIA_PLAYER__
     if (mmi_medply_is_play_activated())
     {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_TRC_CHECK_SET_MUTE, 2);
        return MMI_FALSE;
     }
#endif

    /*Java Player*/
#ifdef __J2ME__
    if(jma_audio_player_is_really_active())
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_TRC_CHECK_SET_MUTE, 3);
        return MMI_FALSE;
    }
#endif

    /*FM Radio*/
#ifdef __MMI_FM_RADIO__
    if(mmi_fmrdo_is_power_on())
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_TRC_CHECK_SET_MUTE, 4);
        return MMI_FALSE;
    }
#endif

    /*Sound Recorder*/
#ifdef __MMI_SOUND_RECORDER__
    if(mmi_sndrec_record_is_on())
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_TRC_CHECK_SET_MUTE, 5);
        return MMI_FALSE;
    }
#endif

#if defined(__MMI_MOBILE_TV_PLAYER__)
    if(mdi_mtv_is_playing())
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_TRC_CHECK_SET_MUTE, 6);
        return MMI_FALSE;
    }
#endif

#ifdef __A8BOX_SUPPORT__
    if(mmi_a8box_is_playing())
    {
       MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_TRC_CHECK_SET_MUTE, 6);
       return MMI_FALSE;
    }
#endif
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_TRC_CHECK_SET_MUTE, 0);

    return MMI_TRUE;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_check_tone_playing
 * DESCRIPTION
 *  check if tone_id is currently playing
 * PARAMETERS
 *  ALL_TONE_ENUM
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_profiles_check_tone_playing(ALL_TONE_ENUM tone_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = (g_mmi_profiles_current_tone == tone_id);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_TRC_CHECK_TONE_PLAYING,(int)tone_id, result);

    return result ;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_set_current_tone
 * DESCRIPTION
 *  api to set current playing tone id for prevneting repeating the same tone
 * PARAMETERS
 *  ALL_TONE_ENUM
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_set_current_tone(ALL_TONE_ENUM tone_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_USER_PROF_TRC_SET_CURRENT_TONE,tone_id);        
    g_mmi_profiles_current_tone = tone_id;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_play_tone_callback
 * DESCRIPTION
 *  callback function of mdi to inform user profile of current play tone situation.
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_play_tone_callback(mdi_result result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_TRC_PLAY_TONE_CALLBACK,result);
    mmi_profiles_set_current_tone(NONE_TONE);

    if(g_mmi_profiles_play_tone_callback != NULL)
    {
        g_mmi_profiles_play_tone_callback(result);
        g_mmi_profiles_play_tone_callback = NULL;
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_play_requested_tone_with_callback
 * DESCRIPTION
 *  play requested tone with callback, when return MMI_FALSE, means we will not callback
 * PARAMETERS
 *  playtone            [IN]
 *  play_tone_callback [IN]
 * RETURNS
 *  MMI_BOOL            MMI_FALSE: not callabck since it is not played or its DTMF short tone
 *****************************************************************************/
MMI_BOOL mmi_profiles_play_requested_tone_with_callback(ALL_TONE_ENUM playtone, mmi_play_tone_callback play_tone_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    playRequestedTone(playtone);
    if(g_mmi_profiles_if_need_callback)
    {
        g_mmi_profiles_play_tone_callback = play_tone_callback;
        g_mmi_profiles_if_need_callback = MMI_FALSE;
        return MMI_TRUE;
    }

    return MMI_FALSE;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_check_if_need_callback
 * DESCRIPTION
 *  check if it's DTMF tone to set g_mmi_profiles_if_need_callback properly
 * PARAMETERS
 *  sound_id            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_check_if_need_callback(U16 sound_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(sound_id < MAX_TONE_ID)
    {
        g_mmi_profiles_if_need_callback = MMI_FALSE;
    }
    else
    {
        g_mmi_profiles_if_need_callback = MMI_TRUE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  playRequestedTone
 * DESCRIPTION
 *  API to all applications to play tone.
 * PARAMETERS
 *  playtone        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void playRequestedTone(ALL_TONE_ENUM playtone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL setFlag = FALSE; /*set the tone play flag only for non DTMF tone paly*/
    BOOL DataCallOnly = FALSE;    

#ifdef __MMI_OP11_PROF_SOUND__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    #ifdef __MMI_SUBLCD_MASTER_MODE__
    /*subLCD application requires short tone*/
    playtone = ChangeInterruptToneInMasterMode(playtone);
    #endif/*__MMI_SUBLCD_MASTER_MODE__*/
    g_mmi_profiles_if_need_callback = MMI_FALSE;

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_TRC_PLAY_REQUESTED_TONE,(int)playtone);
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_TRC_PLAY_REQUESTED_TONE_DETAILS,gcurrentprofile.extraTone.errorTone,
        gcurrentprofile.extraTone.connectTone,gcurrentprofile.extraTone.campOnTone,gcurrentprofile.extraTone.warningTone,
        g_mmi_profiles_current_tone,gactivatedprofile);

    switch (playtone)
    {
        case CONGESTION_TONE:
        {
        #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
            if(!mmi_profiles_check_set_mute())
            {
                AudioPlayReq(TONE_GENERAL_BEEP, DEVICE_AUDIO_PLAY_ONCE);
                mmi_profiles_check_if_need_callback(TONE_GENERAL_BEEP);
                return;
            }
        #endif
            AudioPlayReq(TONE_CONGESTION_GSM, DEVICE_AUDIO_PLAY_ONCE);
            mmi_profiles_check_if_need_callback(TONE_CONGESTION_GSM);
            return;
        }

        case AUTH_FAIL_TONE:
        {
        #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
            if(!mmi_profiles_check_set_mute())
            {
                AudioPlayReq(TONE_GENERAL_BEEP, DEVICE_AUDIO_PLAY_ONCE);
                mmi_profiles_check_if_need_callback(TONE_GENERAL_BEEP);
                return;
            }
        #endif
            AudioPlayReq(TONE_AUTH_ERROR, DEVICE_AUDIO_PLAY_ONCE);
            mmi_profiles_check_if_need_callback(TONE_AUTH_ERROR);
            return;
        }

        case NUM_UNOBTAIN_TONE:
        {
        #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
            if(!mmi_profiles_check_set_mute())
            {
                AudioPlayReq(TONE_GENERAL_BEEP, DEVICE_AUDIO_PLAY_ONCE);
                mmi_profiles_check_if_need_callback(TONE_GENERAL_BEEP);
                return;
            }
        #endif            
            AudioPlayReq(TONE_NUM_UNOBTAIN, DEVICE_AUDIO_PLAY_ONCE);
            mmi_profiles_check_if_need_callback(TONE_NUM_UNOBTAIN);
            return;
        }

        case CALL_DROP_TONE:
        {
        #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
            if(!mmi_profiles_check_set_mute())
            {
                AudioPlayReq(TONE_GENERAL_BEEP, DEVICE_AUDIO_PLAY_ONCE);
                mmi_profiles_check_if_need_callback(TONE_GENERAL_BEEP);
                return;
            }
        #endif    
            AudioPlayReq(TONE_RADIO_NA, DEVICE_AUDIO_PLAY_ONCE);
            mmi_profiles_check_if_need_callback(TONE_RADIO_NA);
            return;
        }
    }

#ifdef __MMI_UCM__
    if (mmi_ucm_app_total_call(MMI_UCM_CSD_CALL_TYPE_ALL) == mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_ALL))
#else /* __MMI_UCM__ */
    if (IsWapCallPresent() && GetTotalCallCount()==1)
#endif /* __MMI_UCM__ */
    {
        DataCallOnly = TRUE ;
    }
    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_TRC_IS_IN_CALL,isInCall(),DataCallOnly);
    
    if (!isInCall() || DataCallOnly)
    {
        switch (playtone)
        {
            case ERROR_TONE:
            {
                if (gcurrentprofile.extraTone.errorTone == 1)
                {
                #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
                    if(!mmi_profiles_check_set_mute())
                    {
                        AudioPlayReq(TONE_GENERAL_BEEP, DEVICE_AUDIO_PLAY_ONCE);
                        mmi_profiles_check_if_need_callback(TONE_GENERAL_BEEP);
                        return;
                    }
                #endif
                    AudioPlayReq(TONE_ERROR1, DEVICE_AUDIO_PLAY_ONCE);
                    mmi_profiles_check_if_need_callback(TONE_ERROR1);
                }
                break;
            }

            case CONNECT_TONE:
            {
            #ifndef __MMI_CONNECT_NOTICE__
                if (gcurrentprofile.extraTone.connectTone == 1)
            #endif 
                {
                #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
                    if(!mmi_profiles_check_set_mute())
                    {
                        AudioPlayReq(TONE_GENERAL_BEEP, DEVICE_AUDIO_PLAY_ONCE);
                        mmi_profiles_check_if_need_callback(TONE_GENERAL_BEEP);
                        return;
                    }
                #endif    
                    AudioPlayReq(TONE_CALL_CONNECT, DEVICE_AUDIO_PLAY_ONCE);
                    mmi_profiles_check_if_need_callback(TONE_CALL_CONNECT);
                }
                break;
            }

            case CAMP_ON_TONE:
            {
                if (gcurrentprofile.extraTone.campOnTone == 1)
                {
                #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
                    if(!mmi_profiles_check_set_mute())
                    {
                        AudioPlayReq(TONE_GENERAL_BEEP, DEVICE_AUDIO_PLAY_ONCE);
                        mmi_profiles_check_if_need_callback(TONE_GENERAL_BEEP);
                        return;
                    }
                #endif
                    AudioPlayReq(SOUND_3, DEVICE_AUDIO_PLAY_ONCE);
                    mmi_profiles_check_if_need_callback(SOUND_3);
                    setFlag = TRUE;
                }
                break;
            }

            case WARNING_TONE:
            {
                if (gcurrentprofile.extraTone.warningTone == 1)
                {
                #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
                    if(!mmi_profiles_check_set_mute())
                    {
                        AudioPlayReq(TONE_GENERAL_BEEP, DEVICE_AUDIO_PLAY_ONCE);
                        mmi_profiles_check_if_need_callback(TONE_GENERAL_BEEP);
                        return;
                    }
                #endif
                
                #ifdef __MMI_OP11_PROF_SOUND__
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #else
                    AudioPlayReq(TONE_WARNING1, DEVICE_AUDIO_PLAY_ONCE);
                    mmi_profiles_check_if_need_callback(TONE_WARNING1);
                #endif
                }
                break;
            }

            case INCOMING_CALL_TONE:
            {
                if (gactivatedprofile != MMI_PROFILE_SILENT)
                {
                #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
                    if(!mmi_profiles_check_set_mute())
                    {
                        AudioPlayReq(TONE_GENERAL_BEEP, DEVICE_AUDIO_PLAY_ONCE);
                        mmi_profiles_check_if_need_callback(TONE_GENERAL_BEEP);
                        return;
                    }
                #endif
                    AudioPlayToneWithCallBack(gcurrentprofile.toneSetup.ringTone, (U8) GetRingTypeEnum(), INCOMING_CALL_TONE);
                    g_mmi_profiles_if_need_callback = MMI_TRUE;
                    setFlag = TRUE;
                }
                break;
            }

            case ALARM_TONE:
            {
            #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
                if(!mmi_profiles_check_set_mute())
                {
                    AudioPlayReq(TONE_GENERAL_BEEP, DEVICE_AUDIO_PLAY_ONCE);
                    mmi_profiles_check_if_need_callback(TONE_GENERAL_BEEP);
                    return;
                }
            #endif                
            #ifdef __MMI_ALM_CUSTOMIZE_TONE__
                if (g_alm_frm_cntx.CurrAlmIndex >= ALM_ALM_START && g_alm_frm_cntx.CurrAlmIndex < ALM_SPOF_START)
                {
                    AudioPlayToneWithCallBack(
                        g_alm_cntx.AlmList[g_alm_frm_cntx.CurrAlmIndex - ALM_ALM_START].AudioOptionValue,
                        DEVICE_AUDIO_PLAY_CRESCENDO,
                        ALARM_TONE);
                }
                else
            #endif /* __MMI_ALM_CUSTOMIZE_TONE__ */ 
                    AudioPlayToneWithCallBack(gcurrentprofile.toneSetup.alarmTone, DEVICE_AUDIO_PLAY_CRESCENDO, ALARM_TONE);
                g_mmi_profiles_if_need_callback = MMI_TRUE;
                setFlag = TRUE;
                
                break;
            }
        #ifndef __MMI_POWER_ON_OFF_MUTE__
            case POWER_ON_TONE:
            {
                if (gcurrentprofile.toneSetup.powerOnTone != POWERON_SILENT)
                {
                #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
                    if(!mmi_profiles_check_set_mute())
                    {
                        AudioPlayReq(TONE_GENERAL_BEEP, DEVICE_AUDIO_PLAY_ONCE);
                        mmi_profiles_check_if_need_callback(TONE_GENERAL_BEEP);
                        return;
                    }
                #endif
                    AudioPlayReq(gcurrentprofile.toneSetup.powerOnTone, DEVICE_AUDIO_PLAY_ONCE);
                    mmi_profiles_check_if_need_callback(gcurrentprofile.toneSetup.powerOnTone);
                    setFlag = TRUE;
                }
                break;
            }

            case POWER_OFF_TONE:
            {
                if (gcurrentprofile.toneSetup.powerOffTone != POWEROFF_SILENT)
                {
                #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
                    if(!mmi_profiles_check_set_mute())
                    {
                        AudioPlayReq(TONE_GENERAL_BEEP, DEVICE_AUDIO_PLAY_ONCE);
                        mmi_profiles_check_if_need_callback(TONE_GENERAL_BEEP);
                        return;
                    }
                #endif
                    AudioPlayReq(gcurrentprofile.toneSetup.powerOffTone, DEVICE_AUDIO_PLAY_ONCE);
                    mmi_profiles_check_if_need_callback(gcurrentprofile.toneSetup.powerOffTone);
                    setFlag = TRUE;
                }
                break;
            }
        #endif /*__MMI_POWER_ON_OFF_MUTE__*/

            #ifdef __MMI_CLAMSHELL__
            case COVER_OPEN_TONE:
            {
                if (gcurrentprofile.toneSetup.coverOpenTone != COVER_OPEN_SILENT)
                {
                #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
                    if(!mmi_profiles_check_set_mute())
                    {
                        AudioPlayReq(TONE_GENERAL_BEEP, DEVICE_AUDIO_PLAY_ONCE);
                        mmi_profiles_check_if_need_callback(TONE_GENERAL_BEEP);
                        return;
                    }
                #endif                
                    AudioPlayReq(gcurrentprofile.toneSetup.coverOpenTone, DEVICE_AUDIO_PLAY_ONCE);
                    mmi_profiles_check_if_need_callback(gcurrentprofile.toneSetup.coverOpenTone);
                    setFlag = TRUE;
                }
                break;
            }

            case COVER_CLOSE_TONE:
            {
                if (gcurrentprofile.toneSetup.coverCloseTone != COVER_CLOSE_SILENT)
                {
                #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
                    if(!mmi_profiles_check_set_mute())
                    {
                        AudioPlayReq(TONE_GENERAL_BEEP, DEVICE_AUDIO_PLAY_ONCE);
                        mmi_profiles_check_if_need_callback(TONE_GENERAL_BEEP);
                        return;
                    }
                #endif
                    AudioPlayReq(gcurrentprofile.toneSetup.coverCloseTone, DEVICE_AUDIO_PLAY_ONCE);
                    mmi_profiles_check_if_need_callback(gcurrentprofile.toneSetup.coverCloseTone);
                    setFlag = TRUE;
                }
                break;
            }
            #endif /* __MMI_CLAMSHELL__ */ 

            case SMS_TONE:
            case WAP_PUSH_TONE:
            case MESSAGE_TONE:
            {                
            #ifdef __MMI_PROF_SPLIT_MSG_TONES__
                if(g_mmi_profiles_current_tone == SMS_TONE)
                {
                    break;
                }            
                if (gcurrentprofile.toneSetup.smsTone != MESSAGE_SILENT)
                {
                #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
                    if(!mmi_profiles_check_set_mute())
                    {
                        AudioPlayReq(TONE_GENERAL_BEEP, DEVICE_AUDIO_PLAY_ONCE);
                        mmi_profiles_check_if_need_callback(TONE_GENERAL_BEEP);
                        return;
                    }
                #endif
                    AudioPlayToneWithCallBack(
                        gcurrentprofile.toneSetup.smsTone,
                        DEVICE_AUDIO_PLAY_ONCE,
                        SMS_TONE);
                    setFlag = TRUE;
                    mmi_profiles_set_current_tone(SMS_TONE);
                    g_mmi_profiles_if_need_callback = MMI_TRUE;
                }
            #else
                if (gcurrentprofile.toneSetup.messageTone != MESSAGE_SILENT)
                {
                #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
                    if(!mmi_profiles_check_set_mute())
                    {
                        AudioPlayReq(TONE_GENERAL_BEEP, DEVICE_AUDIO_PLAY_ONCE);
                        mmi_profiles_check_if_need_callback(TONE_GENERAL_BEEP);
                        return;
                    }
                #endif
                    AudioPlayToneWithCallBack(
                        gcurrentprofile.toneSetup.messageTone,
                        DEVICE_AUDIO_PLAY_ONCE,
                        SMS_TONE);
                    g_mmi_profiles_if_need_callback = MMI_TRUE;
                    setFlag = TRUE;
                }                
            #endif                
                break;
            }

        #ifdef MMS_SUPPORT
            case MMS_TONE:
            {
            #ifdef __MMI_PROF_SPLIT_MSG_TONES__
                if(g_mmi_profiles_current_tone == MMS_TONE)
                {
                    break;
                }
                if(gcurrentprofile.toneSetup.mmsTone != MESSAGE_SILENT)
                {
                #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
                    if(!mmi_profiles_check_set_mute())
                    {
                        AudioPlayReq(TONE_GENERAL_BEEP, DEVICE_AUDIO_PLAY_ONCE);
                        mmi_profiles_check_if_need_callback(TONE_GENERAL_BEEP);
                        return;
                    }
                #endif
                    AudioPlayToneWithCallBack(
                        gcurrentprofile.toneSetup.mmsTone,
                        DEVICE_AUDIO_PLAY_ONCE,
                        MMS_TONE);
                    g_mmi_profiles_if_need_callback = MMI_TRUE;
                    setFlag = TRUE;
                    mmi_profiles_set_current_tone(MMS_TONE);
                }
            #else
                if (gcurrentprofile.toneSetup.messageTone != MESSAGE_SILENT)
                {
                #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
                    if(!mmi_profiles_check_set_mute())
                    {
                        AudioPlayReq(TONE_GENERAL_BEEP, DEVICE_AUDIO_PLAY_ONCE);
                        mmi_profiles_check_if_need_callback(TONE_GENERAL_BEEP);
                        return;
                    }
                #endif
                    AudioPlayToneWithCallBack(
                        gcurrentprofile.toneSetup.messageTone,
                        DEVICE_AUDIO_PLAY_ONCE,
                        MMS_TONE);
                    g_mmi_profiles_if_need_callback = MMI_TRUE;
                    setFlag = TRUE;
                }
            #endif /*__MMI_PROF_SPLIT_MSG_TONES__*/
                break;
            }
        #endif

        #ifdef __MMI_EMAIL__
            case EMAIL_TONE:
            {
            #ifdef __MMI_PROF_SPLIT_MSG_TONES__
                if(g_mmi_profiles_current_tone == EMAIL_TONE)
                {
                    break;
                }
                if(gcurrentprofile.toneSetup.emailTone != MESSAGE_SILENT)
                {
                #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
                    if(!mmi_profiles_check_set_mute())
                    {
                        AudioPlayReq(TONE_GENERAL_BEEP, DEVICE_AUDIO_PLAY_ONCE);
                        mmi_profiles_check_if_need_callback(TONE_GENERAL_BEEP);
                        return;
                    }
                #endif
                    AudioPlayToneWithCallBack(
                        gcurrentprofile.toneSetup.emailTone,
                        DEVICE_AUDIO_PLAY_ONCE,
                        EMAIL_TONE);
                    g_mmi_profiles_if_need_callback = MMI_TRUE;
                    setFlag = TRUE;
                    mmi_profiles_set_current_tone(EMAIL_TONE);
                }
            #else
                if (gcurrentprofile.toneSetup.messageTone != MESSAGE_SILENT)
                {
                #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
                    if(!mmi_profiles_check_set_mute())
                    {
                        AudioPlayReq(TONE_GENERAL_BEEP, DEVICE_AUDIO_PLAY_ONCE);
                        mmi_profiles_check_if_need_callback(TONE_GENERAL_BEEP);
                        return;
                    }
                #endif
                    AudioPlayToneWithCallBack(
                        gcurrentprofile.toneSetup.messageTone,
                        DEVICE_AUDIO_PLAY_ONCE,
                        EMAIL_TONE);
                    g_mmi_profiles_if_need_callback = MMI_TRUE;
                    setFlag = TRUE;
                }                
            #endif /*__MMI_PROF_SPLIT_MSG_TONES__*/
                break;
 
            }
        #endif

        #ifdef __MMI_OP11_MMS_SUPPORT_AUDIO_MSG__
/* under construction !*/
/* under construction !*/
            #ifdef __MMI_PROF_SPLIT_MSG_TONES__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
            #else
/* under construction !*/
/* under construction !*/
                #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /*__MMI_PROF_SPLIT_MSG_TONES__*/
/* under construction !*/
/* under construction !*/
        #endif

            case SUCCESS_TONE:
            {
                break;
            }

            case SAVE_TONE:  
            {
                break;
            }

            case EXPLICITLY_SAVE_TONE:
            {
            #ifdef __MMI_OP11_PROF_SOUND__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /*__MMI_OP11_PROF_SOUND__*/
                break;
            }

            case SMS_IN_CALL_TONE:
            {
            #ifndef __MMI_PROF_SPLIT_MSG_TONES__                
                if (gcurrentprofile.toneSetup.messageTone != MESSAGE_SILENT)
            #else
                if(gcurrentprofile.toneSetup.smsTone != MESSAGE_SILENT)
            #endif
                {
                #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
                    if(!mmi_profiles_check_set_mute())
                {
                        AudioPlayReq(TONE_GENERAL_BEEP, DEVICE_AUDIO_PLAY_ONCE);
                        mmi_profiles_check_if_need_callback(TONE_GENERAL_BEEP);
                        return;
                    }
                #endif
                    AudioPlayReq(TONE_MT_SMS_IN_CALL, DEVICE_AUDIO_PLAY_ONCE);
                    mmi_profiles_check_if_need_callback(TONE_MT_SMS_IN_CALL);
                }
                break;
            }

            case EMPTY_LIST_TONE:
            {
                if (gcurrentprofile.extraTone.warningTone == 1)
                {
                #ifdef __MMI_OP11_PROF_SOUND__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                    #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
                #else
                    #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
                    if(!mmi_profiles_check_set_mute())
                    {
                        AudioPlayReq(TONE_GENERAL_BEEP, DEVICE_AUDIO_PLAY_ONCE);
                        mmi_profiles_check_if_need_callback(TONE_GENERAL_BEEP);
                        return;
                    }
                    #endif
                    AudioPlayReq(TONE_WARNING1, DEVICE_AUDIO_PLAY_ONCE);
                    mmi_profiles_check_if_need_callback(TONE_WARNING1);
                #endif /*__MMI_OP11_PROF_SOUND__*/
                }
                break;
            }

            case GENERAL_TONE:
            {
                if (gcurrentprofile.extraTone.warningTone == 1)
                {
                    AudioPlayReq(TONE_GENERAL_BEEP, DEVICE_AUDIO_PLAY_ONCE);
                    mmi_profiles_check_if_need_callback(TONE_GENERAL_BEEP);
                }
                break;
            }
                
            case AUX_TONE:
            {
                if (gcurrentprofile.extraTone.warningTone == 1)
                {
                #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
                    if(!mmi_profiles_check_set_mute())
                    {
                        AudioPlayReq(TONE_GENERAL_BEEP, DEVICE_AUDIO_PLAY_ONCE);
                        mmi_profiles_check_if_need_callback(TONE_GENERAL_BEEP);
                        return;
                    }
                #endif
                    AudioPlayReq(TONE_AUX_IND, DEVICE_AUDIO_PLAY_ONCE);
                    mmi_profiles_check_if_need_callback(TONE_AUX_IND);
                }
                break;
            }

            case BATTERY_LOW_TONE:
            {
                if (gcurrentprofile.extraTone.warningTone == 1)
                {
                #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
                    if(!mmi_profiles_check_set_mute())
                    {
                        AudioPlayReq(TONE_GENERAL_BEEP, DEVICE_AUDIO_PLAY_ONCE);
                        mmi_profiles_check_if_need_callback(TONE_GENERAL_BEEP);
                        return;
                    }
                #endif
                    AudioPlayReq(TONE_BATTERY_LOW, DEVICE_AUDIO_PLAY_ONCE);
                    mmi_profiles_check_if_need_callback(TONE_BATTERY_LOW);
                }
                break;
            }
                
            case BATTERY_WARNING_TONE:
            {
                if (gcurrentprofile.extraTone.warningTone == 1)
                {
                #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
                    if(!mmi_profiles_check_set_mute())
                    {
                        AudioPlayReq(TONE_GENERAL_BEEP, DEVICE_AUDIO_PLAY_ONCE);
                        mmi_profiles_check_if_need_callback(TONE_GENERAL_BEEP);
                        return;
                    }
                #endif
                    AudioPlayReq(TONE_BATTERY_WARNING, DEVICE_AUDIO_PLAY_ONCE);
                    mmi_profiles_check_if_need_callback(TONE_BATTERY_WARNING);
                }
                break;
            }
                
            case WARNING_TONE_IN_CALL:
            {
                if (gcurrentprofile.extraTone.warningTone == 1)
                {
                    AudioPlayReq(TONE_WARNING2, DEVICE_AUDIO_PLAY_ONCE);
                    mmi_profiles_check_if_need_callback(TONE_WARNING2);
                }
                break;
            }
                
            case ERROR_TONE_IN_CALL:
            {
                if (gcurrentprofile.extraTone.errorTone == 1)
                {
                    AudioPlayReq(TONE_ERROR2, DEVICE_AUDIO_PLAY_ONCE);
                    mmi_profiles_check_if_need_callback(TONE_ERROR2);
                }
                break;
            }

    #if defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT)
            case IMPS_CONTACT_ONLINE_TONE:
            {
                if (gcurrentprofile.toneSetup.IMPSContactOnlineTone != MESSAGE_SILENT)
                {
                #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
                    if(!mmi_profiles_check_set_mute())
                    {
                        AudioPlayReq(TONE_GENERAL_BEEP, DEVICE_AUDIO_PLAY_ONCE);
                        mmi_profiles_check_if_need_callback(TONE_GENERAL_BEEP);
                        return;
                    }
                #endif
                    AudioPlayReq(gcurrentprofile.toneSetup.IMPSContactOnlineTone, DEVICE_AUDIO_PLAY_ONCE);
                    mmi_profiles_check_if_need_callback(gcurrentprofile.toneSetup.IMPSContactOnlineTone);
                    setFlag = TRUE;
                }
                break;
            }
                
            case IMPS_NEW_MESSAGE_TONE:
            {
                if (gcurrentprofile.toneSetup.IMPSNewMessageTone != MESSAGE_SILENT)
                {
                #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
                    if(!mmi_profiles_check_set_mute())
                    {
                        AudioPlayReq(TONE_GENERAL_BEEP, DEVICE_AUDIO_PLAY_ONCE);
                        mmi_profiles_check_if_need_callback(TONE_GENERAL_BEEP);
                        return;
                    }
                #endif
                    AudioPlayReq(gcurrentprofile.toneSetup.IMPSNewMessageTone, DEVICE_AUDIO_PLAY_ONCE);
                    mmi_profiles_check_if_need_callback(gcurrentprofile.toneSetup.IMPSNewMessageTone);
                    setFlag = TRUE;
                }                
                break;
            }
                
            case IMPS_CONTACT_INVITATION_TONE:
            {
                if (gcurrentprofile.toneSetup.IMPSNewInvitationTone != MESSAGE_SILENT)
                {
                #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
                    if(!mmi_profiles_check_set_mute())
                    {
                        AudioPlayReq(TONE_GENERAL_BEEP, DEVICE_AUDIO_PLAY_ONCE);
                        mmi_profiles_check_if_need_callback(TONE_GENERAL_BEEP);
                        return;
                    }
                #endif
                    AudioPlayReq(gcurrentprofile.toneSetup.IMPSNewInvitationTone, DEVICE_AUDIO_PLAY_ONCE);
                    mmi_profiles_check_if_need_callback(gcurrentprofile.toneSetup.IMPSNewInvitationTone);
                    setFlag = TRUE;
                }
                break;
            }
                
            case IMPS_CHATROOM_NOTIFICATION_TONE:
            {
                if (gcurrentprofile.toneSetup.IMPSChatroomNotificationTone != MESSAGE_SILENT)
                {
                #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
                    if(!mmi_profiles_check_set_mute())
                    {
                        AudioPlayReq(TONE_GENERAL_BEEP, DEVICE_AUDIO_PLAY_ONCE);
                        mmi_profiles_check_if_need_callback(TONE_GENERAL_BEEP);
                        return;
                    }
                #endif
                    AudioPlayReq(gcurrentprofile.toneSetup.IMPSChatroomNotificationTone, DEVICE_AUDIO_PLAY_ONCE);
                    mmi_profiles_check_if_need_callback(gcurrentprofile.toneSetup.IMPSChatroomNotificationTone);
                    setFlag = TRUE;
                }                
                break;
            }
    #endif /* __MMI_IMPS__ && IMPS_WV13_ENHANCEMENT */

        #ifdef __MMI_DUAL_PROFILE_SUPPORT__
            case CARD2_MESSAGE_TONE:
            {
                if(gcurrentprofile.toneSetup.card2_messageTone!= MESSAGE_SILENT)
                {
                #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
                    if(!mmi_profiles_check_set_mute())
                    {
                        AudioPlayReq(TONE_GENERAL_BEEP, DEVICE_AUDIO_PLAY_ONCE);
                        mmi_profiles_check_if_need_callback(TONE_GENERAL_BEEP);
                        return;
                    }
                #endif
                    AudioPlayToneWithCallBack(gcurrentprofile.toneSetup.card2_messageTone,
                                DEVICE_AUDIO_PLAY_ONCE, CARD2_MESSAGE_TONE);
                    g_mmi_profiles_if_need_callback = MMI_TRUE;
                    setFlag = TRUE;
                }
                break;
            }

            case CARD2_INCOMING_CALL_TONE:
            {
                if(gactivatedprofile!=MMI_PROFILE_SILENT)
                {
                #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
                    if(!mmi_profiles_check_set_mute())
                    {
                        AudioPlayReq(TONE_GENERAL_BEEP, DEVICE_AUDIO_PLAY_ONCE);
                        mmi_profiles_check_if_need_callback(TONE_GENERAL_BEEP);
                        return;
                    }
                #endif
                    AudioPlayToneWithCallBack(gcurrentprofile.toneSetup.card2_ringTone,
                                DEVICE_AUDIO_PLAY_ONCE, CARD2_INCOMING_CALL_TONE);
                    g_mmi_profiles_if_need_callback = MMI_TRUE;
                    setFlag = TRUE;
                }
                break;
            }
        #endif	/* __MMI_DUAL_PROFILE_SUPPORT__ */
            
            case FILE_ARRIVAL_TONE:
            {
                if(gcurrentprofile.extraTone.warningTone == 1)
                {
                #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
                    if(!mmi_profiles_check_set_mute())
                    {
                        AudioPlayReq(TONE_GENERAL_BEEP, DEVICE_AUDIO_PLAY_ONCE);
                        mmi_profiles_check_if_need_callback(TONE_GENERAL_BEEP);
                        return;
                    }
                #endif
                    AudioPlayReq(SOUND_4, DEVICE_AUDIO_PLAY_ONCE);
                    mmi_profiles_check_if_need_callback(SOUND_4);
                    setFlag = TRUE;
                }
                break;
            }

            case SENT_TONE:
            {
            #ifdef __MMI_OP11_PROF_SOUND__                
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /*__MMI_OP11_PROF_SOUND__*/    
                break;
            }

            case DELETED_TONE:
            {
            #ifdef __MMI_OP11_PROF_SOUND__                
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
           #endif /*__MMI_OP11_PROF_SOUND__*/                         
                break;
            }

            case PROBLEM_TONE:
            {    
            #ifdef __MMI_OP11_PROF_SOUND__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /*__MMI_OP11_PROF_SOUND__*/                
                break;
            }

            case CONFIRM_TONE:
            {
            #ifdef __MMI_OP11_PROF_SOUND__                
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /*__MMI_OP11_PROF_SOUND__*/                
                break;
            }

            case NOT_AVAILABLE_TONE:
            {
            #ifdef __MMI_OP11_PROF_SOUND__                
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /*__MMI_OP11_PROF_SOUND__*/                
                break;
            }

            case ANS_PHONE_TONE:
            {
            #ifdef __MMI_OP11_PROF_SOUND__                
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /*__MMI_OP11_PROF_SOUND__*/
                break;
            }

            case REMIND_TONE:
            {
            #if 0
            #ifdef __MMI_OP11_PROF_SOUND__                
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /*__MMI_OP11_PROF_SOUND__*/
            #endif /*0*/
                break;
            }
        }
    }
    else    /*in call*/
    {
        switch (playtone)
        {
            /* Shall play power off tone no matter in call or not */
            /* See CANNON+ SCR 3573, CSD connection, long press END key won't will power off first, then drop call */
        #ifndef __MMI_POWER_ON_OFF_MUTE__            
            case POWER_OFF_TONE:
            {
                if (gcurrentprofile.toneSetup.powerOffTone != POWEROFF_SILENT)
                {
                #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
                    if(!mmi_profiles_check_set_mute())
                    {
                        AudioPlayReq(TONE_GENERAL_BEEP, DEVICE_AUDIO_PLAY_ONCE);
                        mmi_profiles_check_if_need_callback(TONE_GENERAL_BEEP);
                        return;
                    }
                #endif
                    AudioPlayReq(gcurrentprofile.toneSetup.powerOffTone, DEVICE_AUDIO_PLAY_ONCE);
                    mmi_profiles_check_if_need_callback(gcurrentprofile.toneSetup.powerOffTone);
                    setFlag = TRUE;
                }
                break;
            }
        #endif /*__MMI_POWER_ON_OFF_MUTE__*/
            case SMS_IN_CALL_TONE:
            {
            #ifndef __MMI_PROF_SPLIT_MSG_TONES__
                if (gcurrentprofile.toneSetup.messageTone != MESSAGE_SILENT)
            #else
                if(gcurrentprofile.toneSetup.smsTone != MESSAGE_SILENT)
            #endif
                {
                    AudioPlayReq(TONE_MT_SMS_IN_CALL, DEVICE_AUDIO_PLAY_ONCE);
                    mmi_profiles_check_if_need_callback(TONE_MT_SMS_IN_CALL);
                }
                break;
            }

            case WARNING_TONE_IN_CALL:
            {
                if (gcurrentprofile.extraTone.warningTone == 1)
                {
                    AudioPlayReq(TONE_WARNING2, DEVICE_AUDIO_PLAY_ONCE);
                    mmi_profiles_check_if_need_callback(TONE_WARNING2);
                }
                break;
            }
            
            case ERROR_TONE_IN_CALL:
            {
                if (gcurrentprofile.extraTone.errorTone == 1)
                {
                    AudioPlayReq(TONE_ERROR2, DEVICE_AUDIO_PLAY_ONCE);
                    mmi_profiles_check_if_need_callback(TONE_ERROR2);
                }
                break;
            }
            
            case CONNECT_TONE_IN_CALL:
            {
                if (gcurrentprofile.extraTone.connectTone == 1)
                {
                    AudioPlayReq(TONE_CALL_CONNECT, DEVICE_AUDIO_PLAY_ONCE);
                    mmi_profiles_check_if_need_callback(TONE_CALL_CONNECT);
                }
                break;
            }
            case SUCCESS_TONE_IN_CALL:
            {
                break;
            }
            
            case BATTERY_LOW_TONE:
            {
                if (gcurrentprofile.extraTone.warningTone == 1)
                {
                    AudioPlayReq(TONE_WARNING2, DEVICE_AUDIO_PLAY_ONCE);
                    mmi_profiles_check_if_need_callback(TONE_WARNING2);
                }
                break;
            }
            
            case BATTERY_WARNING_TONE:
            {
                if (gcurrentprofile.extraTone.warningTone == 1)
                {
                    AudioPlayReq(TONE_WARNING2, DEVICE_AUDIO_PLAY_ONCE);
                    mmi_profiles_check_if_need_callback(TONE_WARNING2);
                }
                break;
            }
            
            case CONNECT_TONE:
            {
            #ifndef __MMI_CONNECT_NOTICE__
                if (gcurrentprofile.extraTone.connectTone == 1)
            #endif 
                {
                #ifdef __MMI_PROF_BEEP_WHEN_BGPLAYING__
                    if(!mmi_profiles_check_set_mute())
                    {
                        AudioPlayReq(TONE_GENERAL_BEEP, DEVICE_AUDIO_PLAY_ONCE);
                        mmi_profiles_check_if_need_callback(TONE_GENERAL_BEEP);
                        return;
                    }
                #endif    
                    AudioPlayReq(TONE_CALL_CONNECT, DEVICE_AUDIO_PLAY_ONCE);
                    mmi_profiles_check_if_need_callback(TONE_CALL_CONNECT);
                }
                break;
            }
            
            case CALL_REMINDER_TONE:
            case CCBS_TONE:
            {
                AudioPlayReq(TONE_WARNING2, DEVICE_AUDIO_PLAY_ONCE);
                mmi_profiles_check_if_need_callback(TONE_WARNING2);
                break;
            }

            case PROBLEM_TONE:
            {                
                if (gcurrentprofile.extraTone.errorTone == 1)
                {
                    AudioPlayReq(TONE_ERROR2, DEVICE_AUDIO_PLAY_ONCE);
                    mmi_profiles_check_if_need_callback(TONE_ERROR2);
                }
                break;
            }

        }
    }
    if(setFlag)
    {
        SetPlayReqToneFlag(TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  stopRequestedTone
 * DESCRIPTION
 *  eneral API to all applications to stop tone.
 * PARAMETERS
 *  playtone        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void stopRequestedTone(ALL_TONE_ENUM playtone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL resetFlag = FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    #ifdef __MMI_SUBLCD_MASTER_MODE__
    /*subLCD application requires short tone*/
    playtone = ChangeInterruptToneInMasterMode(playtone);
    #endif/*__MMI_SUBLCD_MASTER_MODE__*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_TRC_STOP_REQUESTED_TONE,(int)playtone);
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_TRC_PLAY_REQUESTED_TONE_DETAILS,gcurrentprofile.extraTone.errorTone,
            gcurrentprofile.extraTone.connectTone,gcurrentprofile.extraTone.campOnTone,gcurrentprofile.extraTone.warningTone,
            g_mmi_profiles_current_tone,gactivatedprofile);
    
    switch (playtone)
    {
        case ERROR_TONE:
        {
            if (gcurrentprofile.extraTone.errorTone == 1)
            {
                AudioStopReq(TONE_ERROR1);
            }
            break;
        }

        case CONNECT_TONE:
        {
            if (gcurrentprofile.extraTone.connectTone == 1)
            {
                AudioStopReq(TONE_CALL_CONNECT);
            }
            break;
        }

        case CAMP_ON_TONE:
        {
            if (gcurrentprofile.extraTone.campOnTone == 1 && GetPlayReqToneFlag())
            {
                resetFlag = TRUE;
                AudioStopReq(SOUND_3);
            }
            break;
        }

        case WARNING_TONE:
        {
            #ifdef __MMI_OP11_PROF_SOUND__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #else
                AudioStopReq(TONE_WARNING1);
            #endif
            break;
        }

        case ALARM_TONE:
        {
            if(GetPlayReqToneFlag())
            {
                resetFlag = TRUE;
                AudioStopReq(gcallbackToneId);
            }
            break;
        }
            
        case INCOMING_CALL_TONE:
        {
            if (GetPlayReqToneFlag())
            {
                resetFlag = TRUE;
                AudioStopReq(gcallbackToneId);
            }
            break;
        }
    #ifndef __MMI_POWER_ON_OFF_MUTE__
        case POWER_ON_TONE:
        {
            if (gcurrentprofile.toneSetup.powerOnTone != POWERON_SILENT && GetPlayReqToneFlag())
            {
                resetFlag = TRUE;
                AudioStopReq(gcurrentprofile.toneSetup.powerOnTone);
            }
            break;
        }

        case POWER_OFF_TONE:
        {
            if (gcurrentprofile.toneSetup.powerOffTone != POWEROFF_SILENT && GetPlayReqToneFlag())
            {
                resetFlag = TRUE;
                AudioStopReq(gcurrentprofile.toneSetup.powerOffTone);
            }
            break;
        }
    #endif /*__MMI_POWER_ON_OFF_MUTE__*/

        #ifdef __MMI_CLAMSHELL__
        case COVER_OPEN_TONE:
        {
            if (gcurrentprofile.toneSetup.coverOpenTone != COVER_OPEN_SILENT && GetPlayReqToneFlag())
            {
                resetFlag = TRUE;
                AudioStopReq(gcurrentprofile.toneSetup.coverOpenTone);
            }
            break;
        }

        case COVER_CLOSE_TONE:
        {
            if (gcurrentprofile.toneSetup.coverCloseTone != COVER_CLOSE_SILENT && GetPlayReqToneFlag())
            {
                resetFlag = TRUE;
                AudioStopReq(gcurrentprofile.toneSetup.coverCloseTone);
            }
            break;
        }
        #endif /* __MMI_CLAMSHELL__ */ 

        #if defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT)
        case IMPS_CONTACT_ONLINE_TONE:
        {
            if (gactivatedprofile != MMI_PROFILE_SILENT && GetPlayReqToneFlag())
            {
                resetFlag = TRUE;            
                AudioStopReq(gcurrentprofile.toneSetup.IMPSContactOnlineTone);
            }
            break;
        }
            
        case IMPS_NEW_MESSAGE_TONE:
        {
            if (gactivatedprofile != MMI_PROFILE_SILENT && GetPlayReqToneFlag())
            {
                resetFlag = TRUE;            
                AudioStopReq(gcurrentprofile.toneSetup.IMPSNewMessageTone);
            }                
            break;
        }
            
        case IMPS_CONTACT_INVITATION_TONE:
        {
            if (gactivatedprofile != MMI_PROFILE_SILENT && GetPlayReqToneFlag())
            {
                resetFlag = TRUE;
                AudioStopReq(gcurrentprofile.toneSetup.IMPSNewInvitationTone);
            }
            break;
        }
            
        case IMPS_CHATROOM_NOTIFICATION_TONE:
        {
            if (gactivatedprofile != MMI_PROFILE_SILENT && GetPlayReqToneFlag())
            {
                resetFlag = TRUE;
                AudioStopReq(gcurrentprofile.toneSetup.IMPSChatroomNotificationTone);
            }                
            break;
        }
        #endif /* __MMI_IMPS__ &&  IMPS_WV13_ENHANCEMENT */
        
        case SUCCESS_TONE:
        {
            break;
        }

        case SAVE_TONE:
        {
            break;
        }

        case EXPLICITLY_SAVE_TONE:
        {
        #ifdef __MMI_OP11_PROF_SOUND__            
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /*__MMI_OP11_PROF_SOUND__*/            
            break;
        }

        case EMPTY_LIST_TONE:
        {
            if (gcurrentprofile.extraTone.warningTone == 1)
            {
            #ifdef __MMI_OP11_PROF_SOUND__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #else
                AudioStopReq(TONE_WARNING1);
            #endif /*__MMI_OP11_PROF_SOUND__*/
            }
            break;
        }

        case GENERAL_TONE:
        {
            if (gcurrentprofile.extraTone.warningTone == 1)
            {
                AudioStopReq(TONE_GENERAL_BEEP);
            }
            break;
        }

        case SMS_IN_CALL_TONE:
        {
            AudioStopReq(TONE_MT_SMS_IN_CALL);
            break;
        }
            
        case BATTERY_LOW_TONE:
        {
            AudioStopReq(TONE_BATTERY_LOW);
            break;
        }
            
        case BATTERY_WARNING_TONE:
        {
            AudioStopReq(TONE_BATTERY_WARNING);
            break;
        }
            
        case CONGESTION_TONE:
        {
            AudioStopReq(TONE_CONGESTION_GSM);
            break;
        }
            
        case AUTH_FAIL_TONE:
        {
            AudioStopReq(TONE_AUTH_ERROR);
            break;
        }
            
        case NUM_UNOBTAIN_TONE:
        {
            AudioStopReq(TONE_NUM_UNOBTAIN);
            break;
        }
            
        case CALL_DROP_TONE:
        {
            AudioStopReq(TONE_RADIO_NA);
            break;
        }

    #ifdef __MMI_DUAL_PROFILE_SUPPORT__
        case CARD2_INCOMING_CALL_TONE:
        {
            if (GetPlayReqToneFlag())
            {
                resetFlag = TRUE;
                AudioStopReq(gcurrentprofile.toneSetup.card2_ringTone);
            }
            break;
        }

        case CARD2_MESSAGE_TONE:
        {
            if (gcurrentprofile.toneSetup.messageTone != MESSAGE_SILENT && GetPlayReqToneFlag())
            {
                resetFlag = TRUE;
                AudioStopReq(gcurrentprofile.toneSetup.card2_messageTone);
            }
            break;
        }
    #endif	/* __MMI_DUAL_PROFILE_SUPPORT__ */
            
        case FILE_ARRIVAL_TONE:
        {
            if (gcurrentprofile.extraTone.warningTone == 1 && GetPlayReqToneFlag())
            {
                resetFlag = TRUE;
                AudioStopReq(SOUND_4);
            }
            break;    
        }

        case SENT_TONE:
        {
        #ifdef __MMI_OP11_PROF_SOUND__            
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /*__MMI_OP11_PROF_SOUND__*/            
            break;
        }

        case DELETED_TONE:
        {
        #ifdef __MMI_OP11_PROF_SOUND__            
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /*__MMI_OP11_PROF_SOUND__*/            
            break;
        }

        case PROBLEM_TONE:
        {
        #ifdef __MMI_OP11_PROF_SOUND__            
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /*__MMI_OP11_PROF_SOUND__*/            
            break;
        }

        case CONFIRM_TONE:
        {
        #ifdef __MMI_OP11_PROF_SOUND__            
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /*__MMI_OP11_PROF_SOUND__*/            
            break;
        }

        case NOT_AVAILABLE_TONE:
        {
        #ifdef __MMI_OP11_PROF_SOUND__            
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /*__MMI_OP11_PROF_SOUND__*/            
            break;
        }
        
        case ANS_PHONE_TONE:
        {
        #ifdef __MMI_OP11_PROF_SOUND__            
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /*__MMI_OP11_PROF_SOUND__*/            
            break;
        }

        case SMS_TONE:
        case WAP_PUSH_TONE:
        case MESSAGE_TONE:
        {
        #ifdef __MMI_PROF_SPLIT_MSG_TONES__
            if(g_mmi_profiles_current_tone == SMS_TONE)
            {
                mmi_profiles_set_current_tone(NONE_TONE);
                AudioStopReq(gcallbackToneId);
                resetFlag = TRUE;                
                break;
            }
        #else
            if (gcurrentprofile.toneSetup.messageTone != MESSAGE_SILENT && GetPlayReqToneFlag())
            {
                resetFlag = TRUE;
                AudioStopReq(gcallbackToneId);
            }               
        #endif /*__MMI_PROF_SPLIT_MSG_TONES__*/
            break;
        }

    #ifdef MMS_SUPPORT
        case MMS_TONE:
        {
        #ifdef __MMI_PROF_SPLIT_MSG_TONES__
            if(g_mmi_profiles_current_tone == MMS_TONE)
            {
                mmi_profiles_set_current_tone(NONE_TONE);
                AudioStopReq(gcallbackToneId);
                resetFlag = TRUE;
                break;
            }
        #else
            if (gcurrentprofile.toneSetup.messageTone != MESSAGE_SILENT && GetPlayReqToneFlag())
            {
                resetFlag = TRUE;
                AudioStopReq(gcallbackToneId);
            }               
        #endif /*__MMI_PROF_SPLIT_MSG_TONES__*/       
            break;
        }
    #endif

    #ifdef __MMI_EMAIL__
        case EMAIL_TONE:
        {
        #ifdef __MMI_PROF_SPLIT_MSG_TONES__
            if(g_mmi_profiles_current_tone == EMAIL_TONE)
            {
                mmi_profiles_set_current_tone(NONE_TONE);
                AudioStopReq(gcallbackToneId);
                resetFlag = TRUE;
                break;
            }
        #else
            if (gcurrentprofile.toneSetup.messageTone != MESSAGE_SILENT && GetPlayReqToneFlag())
            {
                resetFlag = TRUE;
                AudioStopReq(gcallbackToneId);
            }               
        #endif /*__MMI_PROF_SPLIT_MSG_TONES__*/       
            break;
        }
    #endif

    #ifdef __MMI_OP11_MMS_SUPPORT_AUDIO_MSG__
/* under construction !*/
/* under construction !*/
        #ifdef __MMI_PROF_SPLIT_MSG_TONES__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /*__MMI_PROF_SPLIT_MSG_TONES__*/
/* under construction !*/
/* under construction !*/
    #endif

        case REMIND_TONE:
        {
        #if 0
        #ifdef __MMI_OP11_PROF_SOUND__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /*__MMI_OP11_PROF_SOUND__*/
        #endif /*0*/
            break;
        }

    }

    if(resetFlag)
    {
        SetPlayReqToneFlag(FALSE);
    }

}

/*****************************************************************************
 * FUNCTION
 *  playRequestedToneWithid
 * DESCRIPTION
 *  API to all applications to play tone with specific tone id.
 * PARAMETERS
 *  toneid          [IN]
 *  playtone        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void playRequestedToneWithId(U16 toneid ,ALL_TONE_ENUM playtone)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL DataCallOnly = FALSE;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_profiles_if_need_callback = MMI_FALSE;

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_TRC_PLAY_REQUESTED_TONE_ID,toneid,(int)playtone);

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_TRC_PLAY_REQUESTED_TONE_DETAILS,gcurrentprofile.extraTone.errorTone,
            gcurrentprofile.extraTone.connectTone,gcurrentprofile.extraTone.campOnTone,gcurrentprofile.extraTone.warningTone,
            g_mmi_profiles_current_tone,gactivatedprofile);
 
#ifdef __MMI_UCM__
    if (mmi_ucm_app_total_call(MMI_UCM_CSD_CALL_TYPE_ALL) == mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_ALL))
#else /* __MMI_UCM__ */
    if (IsWapCallPresent() && GetTotalCallCount()==1)
#endif /* __MMI_UCM__ */
    {
        DataCallOnly = TRUE ;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_TRC_IS_IN_CALL,isInCall(),DataCallOnly);
    
    if (isInCall())
    {
        SetPlayReqToneFlag(TRUE);
        switch (playtone)
        {
            case INCOMING_CALL_TONE:
            case CARD2_INCOMING_CALL_TONE:
                if (gactivatedprofile != MMI_PROFILE_SILENT)
                {
                    AudioPlayToneWithCallBack(toneid, (U8) GetRingTypeEnum(), INCOMING_CALL_TONE);
                    g_mmi_profiles_if_need_callback = MMI_TRUE;
                }
                break;
            default :
                break;
        }
    }
    
}

/*****************************************************************************
 * FUNCTION
 *  stopRequestedToneWithId
 * DESCRIPTION
 *  eneral API to all applications to stop tone with specific tone id.
 * PARAMETERS
 *  toneid          [IN]
 *  playtone        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void stopRequestedToneWithId(U16 toneid, ALL_TONE_ENUM playtone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_TRC_STOP_REQUESTED_TONE_ID,toneid,(int)playtone);

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_TRC_PLAY_REQUESTED_TONE_DETAILS,gcurrentprofile.extraTone.errorTone,
            gcurrentprofile.extraTone.connectTone,gcurrentprofile.extraTone.campOnTone,gcurrentprofile.extraTone.warningTone,
            g_mmi_profiles_current_tone,gactivatedprofile);
 
    if (GetPlayReqToneFlag() == TRUE)
    {   
        SetPlayReqToneFlag(FALSE);
        switch (playtone)
        {
            case INCOMING_CALL_TONE:
            case CARD2_INCOMING_CALL_TONE:
                {
                    AudioStopReq(gcallbackToneId);
                }
                break;
             default :
                break;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  SetPlayReqToneFlag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SetPlayReqToneFlag(pBOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_TRC_SET_PLAY_TONE_FLAG,flag);
    
    gPlayReqToneFlag = flag;
}


/*****************************************************************************
 * FUNCTION
 *  GetPlayReqToneFlag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL GetPlayReqToneFlag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_TRC_GET_PLAY_TONE_FLAG,gPlayReqToneFlag);
    return gPlayReqToneFlag;
}


/*****************************************************************************
 * FUNCTION
 *  UpdateDeleteDownloadedRingTone
 * DESCRIPTION
 *  set default tone when selected downloaded Ring tone is deleted.
 * PARAMETERS
 *  ToneId      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UpdateDeleteDownloadedRingTone(U16 ToneId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gcurrentprofile.toneSetup.ringTone == ToneId)
    {
        SetRingToneID(gstartMidiId);
    }
#ifdef __MMI_DUAL_PROFILE_SUPPORT__
    else if(gcurrentprofile.toneSetup.card2_ringTone==ToneId)
    {
	    SetCard2RingToneID(gstartMidiId);
    }
#endif	/* __MMI_DUAL_PROFILE_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  UpdateDeleteExtMldToneSetup
 * DESCRIPTION
 *  set default tone when selected extented Melody Ring tone is deleted.
 * PARAMETERS
 *  ToneId      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
void UpdateDeleteExtMldToneSetup(U16 ToneId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, dirtyFlag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Update alarm ring tone list */
#if defined(__MMI_ALM_AUDIO_OPTIONS__) && defined(__MMI_ALM_CUSTOMIZE_TONE__)
    mmi_alm_tone_setup_delete_ext_melody(ToneId);
#endif 

    for (i = 0; i < MAX_ELEMENTS; i++)
    {
        if (gprofiles[i].toneSetup.ringTone == ToneId)
        {
            gprofiles[i].toneSetup.ringTone = gstartMidiId;
            dirtyFlag = 1;
        }
    #ifdef __MMI_VIDEO_TELEPHONY__
        if(gprofiles[i].toneSetup.videoCallTone== ToneId)
        {
            gprofiles[i].toneSetup.ringTone = gstartMidiId + 1;
            dirtyFlag = 1;
        }
    #endif /*__MMI_VIDEO_TELEPHONY__*/
        if (gprofiles[i].toneSetup.alarmTone == ToneId)
        {
            gprofiles[i].toneSetup.alarmTone = gstartMidiId + 2;
            dirtyFlag = 1;
        }
#ifdef __MMI_DUAL_PROFILE_SUPPORT__
	if(gprofiles[i].toneSetup.card2_ringTone==ToneId)
        {
             gprofiles[i].toneSetup.card2_ringTone = gstartMidiId;
             dirtyFlag = 1;
        }
#endif	/*__MMI_DUAL_PROFILE_SUPPORT__*/

    }

    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(mmi_profiles_cntx_struct));
    }

    mmi_profiles_Ext_melody_delete_menu_screen(ToneId);

    if (dirtyFlag == 1)
    {
        if(!mmi_profiles_write_cntx_to_nvram())
        {
            MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_ERR_UPDTAE_DELETE_EXTMLD); 
            return;
        }
    }

}
#endif /* __MMI_PROFILE_EXTMELODY_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  UpdateDeleteDownloadedAlarmTone
 * DESCRIPTION
 *  set default tone when selected downloaded alarm tone is deleted.
 * PARAMETERS
 *  ToneId      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void UpdateDeleteDownloadedAlarmTone(U16 ToneId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gcurrentprofile.toneSetup.alarmTone == ToneId)
    {
        //tonesetup.alarmTone = gstartMidiId + 1;
        SetAlarmToneID(gstartMidiId + 1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  SetCurrentProfileAsActivatedProfile
 * DESCRIPTION
 *  Sets Current Profile As Activated Profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetCurrentProfileAsActivatedProfile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gprofileId = gactivatedprofile;
}


/*****************************************************************************
 * FUNCTION
 *  IsHeadsetModeActivated
 * DESCRIPTION
 *  Tells if headset mode is activated
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL IsHeadsetModeActivated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gactivatedprofile == MMI_PROFILE_HEADSET)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  IsSilentModeActivated
 * DESCRIPTION
 *  Tells if silent mode is activated
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL IsSilentModeActivated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gactivatedprofile == MMI_PROFILE_SILENT)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  IsMeetingModeActivated
 * DESCRIPTION
 *  Tells if meeting mode is activated
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *  
 *****************************************************************************/
BOOL IsMeetingModeActivated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gactivatedprofile == MMI_PROFILE_MEETING)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/* MTK robin 1119, AT command set wallpaper and profile */


/*****************************************************************************
 * FUNCTION
 *  AtSetProfileTone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  profileID       [IN]        
 *  tone_type       [IN]        
 *  tone_idx        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL AtSetProfileTone(U8 profileID, PROFILE_TONE_TYPE_ENUM tone_type, U8 tone_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (profileID >= MAX_PROFILE_NUM || tone_type >= TONE_MAX_TONE_TYPE || tone_idx > 10)
    {
        return MMI_FALSE;
    }

    switch (tone_type)
    {
    #ifndef __MMI_POWER_ON_OFF_MUTE__    
        case TONE_POWERONTONE:
        {
            if (tone_idx == 0)
            {
                gprofiles[profileID].toneSetup.powerOnTone = POWERON_SILENT;
            }
            else
            {
                gprofiles[profileID].toneSetup.powerOnTone = gstartGeneralToneId + tone_idx - 1;
            }
            break;
        }
    #endif

        default:
            return MMI_FALSE;
    }


    if (gactivatedprofile == gprofileId)
    {
        memcpy(&gcurrentprofile, &gprofiles[gprofileId], sizeof(mmi_profiles_cntx_struct));
    }

    if(!mmi_profiles_write_cntx_to_nvram())
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_USER_PROF_ERR_AT_SET_TONE); 
        return MMI_FALSE;
    }

    return MMI_TRUE;

}

/* MTK end */

/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_headset_activate_profile
 * DESCRIPTION
 *  Activating Headset profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_headset_activate_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_TRC_ACTIVATE_HEADSET_PROFILE,gactivatedprofile, glastactivatedprofile);

    gprofileheadset = 1;
    /* MTK Modified, Robin 1017, prevent activated profile and last actived profile become same one */
#ifdef __MMI_BT_PROFILE__
    if (gactivatedprofile != MMI_PROFILE_SILENT && gactivatedprofile != MMI_PROFILE_HEADSET &&
        gactivatedprofile != MMI_PROFILE_BT)
#else /* __MMI_BT_PROFILE__ */ 
    if (gactivatedprofile != MMI_PROFILE_SILENT && gactivatedprofile != MMI_PROFILE_HEADSET)
#endif /* __MMI_BT_PROFILE__ */ 
        glastactivatedprofile = gactivatedprofile;

    if(gactivatedprofile == MMI_PROFILE_SILENT)
    {
        if(mmi_profiles_check_set_mute())
        {
            mdi_audio_set_mute(MDI_VOLUME_MEDIA,FALSE);
        }
    }

    gactivatedprofile = MMI_PROFILE_HEADSET;
    memcpy(&gcurrentprofile, &gprofiles[gactivatedprofile], sizeof(mmi_profiles_cntx_struct));
    WriteValue(NVRAM_PROFILES_LASTACTIVATED, &glastactivatedprofile, DS_BYTE, &error);
    mmi_profiles_show_alert_status_icon();
    change_font();
    
#if defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT)
    mmi_imps_set_presence_from_phnprof(gcurrentprofile.impsStatus);
#endif    

#ifdef __MMI_PROF_MUTE_APP_ON_SILENT_MODE__
#ifdef __MMI_MEDIA_PLAYER__
    if(gactivatedprofile == MMI_PROFILE_SILENT || gactivatedprofile == MMI_PROFILE_MEETING)
    {
        mmi_medply_set_mute_callback();
    }
#endif
#endif

    /* SetRingerVolume(GetRingVolumeLevel()); */
    mdi_audio_set_volume_no_apply(MDI_VOLUME_MEDIA, GetRingVolumeLevel());

    SetKeyPadVolume(GetKeypadVolumeLevel());
    mdi_audio_set_mic_volume();
    if (gloudSpeaker == 1)
    {
        gloudSpeaker = 0;
        SetLSpkNowOff(TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_headset_deactivate_profile
 * DESCRIPTION
 *  Deactivate Headset profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_headset_deactivate_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_TRC_DEACTIVATE_HEADSET_PROFILE,gactivatedprofile, glastactivatedprofile);

    gprofileheadset = 0;
    ReadValue(NVRAM_PROFILES_LASTACTIVATED, &glastactivatedprofile, DS_BYTE, &error);
#ifdef __MMI_BT_PROFILE__
#endif 
    ReadValue(NVRAM_PROFILES_ACTIVATED, &gactivatedprofile, DS_BYTE, &error);
    memcpy(&gcurrentprofile, &gprofiles[gactivatedprofile], sizeof(mmi_profiles_cntx_struct));
    mmi_profiles_show_alert_status_icon();
    change_font();
    
#if defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT)
    mmi_imps_set_presence_from_phnprof(gcurrentprofile.impsStatus);
#endif   

#ifdef __MMI_PROF_MUTE_APP_ON_SILENT_MODE__
#ifdef __MMI_MEDIA_PLAYER__
    if(gactivatedprofile == MMI_PROFILE_SILENT || gactivatedprofile == MMI_PROFILE_MEETING)
    {
        mmi_medply_set_mute_callback();
    }
#endif
#endif

    if(gactivatedprofile == MMI_PROFILE_SILENT)
    {
        if(mmi_profiles_check_set_mute())
        {
            mdi_audio_set_mute(MDI_VOLUME_MEDIA,TRUE);
        }
    }

    /* SetRingerVolume(GetRingVolumeLevel()); */
    mdi_audio_set_volume_no_apply(MDI_VOLUME_MEDIA, GetRingVolumeLevel());

    SetKeyPadVolume(GetKeypadVolumeLevel());
    mdi_audio_set_mic_volume();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_earphone_plug_in_callback
 * DESCRIPTION
 *  invoke it when plug in earphone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_earphone_plug_in_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_TRC_EARPHONE_PLUGIN,gactivatedprofile,gprofilenvram);

    /*use gprofilenvram to distinguish if the plug out action is before profile application initialized*/
    if(gprofilenvram && (g_pwr_context.PowerOnMode == POWER_ON_KEYPAD || g_pwr_context.PowerOnMode == POWER_ON_EXCEPTION))
    {
        mdi_audio_set_audio_mode(AUD_MODE_HEADSET);
        SetModeSpeechVolume();
    #ifdef __MMI_BT_PROFILE__
        if (gactivatedprofile == MMI_PROFILE_BT)
        {
        #ifdef __MMI_HFP_SUPPORT__
            mmi_profiles_bt_disconnect_req(MMI_PROFILES_BT_HFP_SCO);
        #endif 
        }
    #endif /* __MMI_BT_PROFILE__ */ 
        /* bt_disconnect sco req will activate headset if earphone is connected*/
        if(gactivatedprofile != MMI_PROFILE_HEADSET)
        {
            mmi_profiles_headset_activate_profile();
        }
    #if defined(__MMI_FM_RADIO__) && defined(__MMI_FM_RADIO_BIND_EARPHONE__)
        mmi_fmrdo_power_on_main_screen(TRUE);
    #endif 
    }
    else if(gprofilenvram)
    {
        mdi_audio_set_audio_mode(AUD_MODE_HEADSET);
    #if defined(__MMI_FM_RADIO__) && defined(__MMI_FM_RADIO_BIND_EARPHONE__)
        mmi_fmrdo_power_on_main_screen(TRUE);
    #endif
    }
    else
    {
        mdi_audio_set_audio_mode(AUD_MODE_HEADSET);
    }
#if defined ( __MMI_DUAL_SIM_MASTER__ )&& defined ( __MMI_DUAL_SIM_DUAL_CALL__ )
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_earphone_plug_out_callback
 * DESCRIPTION
 *  invoke it when plug out earphone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_earphone_plug_out_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_TRC_EARPHONE_PLUGOUT,gactivatedprofile,gprofilenvram);
    
    /*use gprofilenvram to distinguish if the plug out action is before profile application initialized*/
    if(gprofilenvram && (g_pwr_context.PowerOnMode == POWER_ON_KEYPAD || g_pwr_context.PowerOnMode == POWER_ON_EXCEPTION))
    {
    #if defined(__MMI_FM_RADIO__) && defined(__MMI_FM_RADIO_BIND_EARPHONE__)
        mmi_fmrdo_power_on(FALSE);
    #endif 
    #ifdef __MMI_BT_PROFILE__
    #if 0 /* If in bluetooth profile, try to connect SCO back if in call */
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
    #ifdef __MMI_HFP_SUPPORT__
        if (mmi_profiles_bt_is_connected(MMI_PROFILES_BT_HFP_ACL))
        {
            mmi_profiles_bt_activate_profile();

    #ifdef __MMI_BT_AUDIO_VIA_SCO__
            /* Connect SCO according to HFP audio path setting */
            if (mmi_bt_is_aud2hf())
    #else /*__MMI_BT_AUDIO_VIA_SCO__*/
        #ifdef __MMI_BT_FM_VIA_SCO__
            /* Need to check FM radio if FM via SCO on  */
            if ((g_mmi_profiles_bt_in_call || mdi_audio_is_playing(MDI_AUDIO_PLAY_FM_RADIO)) &&
                (g_mmi_profiles_bt_always_use_in_call || mmi_bt_is_aud2hf()))
        #else
            if (g_mmi_profiles_bt_in_call && (g_mmi_profiles_bt_always_use_in_call || mmi_bt_is_aud2hf()))
        #endif
    #endif /*__MMI_BT_AUDIO_VIA_SCO__*/
            {
                mmi_profiles_bt_connect_req(MMI_PROFILES_BT_HFP_SCO);
            }
        }
    #endif /* __MMI_HFP_SUPPORT__ */ 
    #endif /* __MMI_BT_PROFILE__ */ 
        if (mdi_audio_get_audio_mode() != AUD_MODE_LOUDSPK)
        {
            mdi_audio_set_audio_mode(AUD_MODE_NORMAL);
            SetModeSpeechVolume();
        }
        if (gactivatedprofile == MMI_PROFILE_HEADSET)
        {
            mmi_profiles_headset_deactivate_profile();
        }
    }
    else if(gprofilenvram)
    {
    #if defined(__MMI_FM_RADIO__) && defined(__MMI_FM_RADIO_BIND_EARPHONE__)
        mmi_fmrdo_power_on(FALSE);
    #endif 
        if (mdi_audio_get_audio_mode() != AUD_MODE_LOUDSPK)
        {
            mdi_audio_set_audio_mode(AUD_MODE_NORMAL);
            SetModeSpeechVolume();
        }
    }
    else
    {
        mdi_audio_set_audio_mode(AUD_MODE_NORMAL);
    }
#if defined ( __MMI_DUAL_SIM_MASTER__ )&& defined ( __MMI_DUAL_SIM_DUAL_CALL__ )
/* under construction !*/
#endif
}

#ifdef __MMI_BT_PROFILE__


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_allow_popup
 * DESCRIPTION
 *  check is it allowed to popup
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_profiles_bt_allow_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_profiles_bt_in_call;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_connect_sco
 * DESCRIPTION
 *  connect sco link
 * PARAMETERS
 *  callback        [IN]        )(void)
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_profiles_bt_connect_sco(void (*callback) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL connect = FALSE;
    S32 connect_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_HFP_SUPPORT__
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_BT_CONNECT_SCO, g_mmi_profiles_bt_disalbe_sco, g_mmi_profiles_bt_inquerying);

    if(mmi_profiles_bt_is_sco_connect_allowed() &&
       gactivatedprofile == MMI_PROFILE_BT )
    {
    	if( mmi_bt_is_hs_connected() )
    	{
    		connect_id = mmi_bt_get_active_signal_connection_id( MMI_BT_HFG_PROFILE_UUID );
    		ASSERT( connect_id >= 0 );
    		connect = mdi_audio_bt_open_stream( BT_HFP, (U16)connect_id );
    		if( connect )
    		{
    			mmi_profiles_bt_connect_sco_app_callback = callback;
    		}
        #ifdef __MMI_BT_AUDIO_VIA_SCO__
            /* Already Connected, start a timeout timer */
            else if(g_mmi_profiles_bt_sco_timeout && 
                    mmi_profiles_bt_is_connected(MMI_PROFILES_BT_HFP_SCO))
            {
                StartTimer(BT_SCO_CONNECT_TIMER, BT_SCO_CONNECT_TIMEOUT_DURATION, mmi_profiles_bt_sco_timeout);
            }
        #endif /* __MMI_BT_AUDIO_VIA_SCO__ */
    	}

    	g_mmi_profiles_bt_app_in_use = TRUE;
    }
#endif /* __MMI_HFP_SUPPORT__ */ 
    return connect;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_disconnect_sco
 * DESCRIPTION
 *  disconnect sco link
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_profiles_bt_disconnect_sco(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL disconnect = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_HFP_SUPPORT__
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_BT_DISCONNECT_SCO,g_mmi_profiles_bt_in_call,g_mmi_profiles_bt_always_use_in_call,mmi_bt_is_aud2hf());

    if (!g_mmi_profiles_bt_in_call || !(g_mmi_profiles_bt_always_use_in_call || mmi_bt_is_aud2hf()))
    {
        disconnect = mdi_audio_bt_is_stream_open(BT_HFP);
        mdi_audio_bt_close_stream(BT_HFP);
        mmi_profiles_bt_connect_sco_app_callback = NULL;
    }
    g_mmi_profiles_bt_app_in_use = FALSE;
#endif /* __MMI_HFP_SUPPORT__ */ 
    return disconnect;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_deactivate_cnf_hdlr
 * DESCRIPTION
 *  the cnf handler for bt a2dp deactivate req
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_bt_deactivate_cnf_hdlr(void)
{
    if (g_mmi_profiles_bt_reset_pending != 0)
    {
        g_mmi_profiles_bt_reset_pending &= 0x0D;
        if (g_mmi_profiles_bt_reset_pending == 0)
        {
            mmi_bt_panic_ind_post_process();
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_reset
 * DESCRIPTION
 *  to reset bt profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_bt_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_BT_RESET,g_mmi_profiles_bt_reset_pending);

#if defined(__MMI_A2DP_SUPPORT__)
    mmi_a2dp_bt_power_off_callback(TRUE);
    mmi_bt_a2dp_deactivate_req();
    if (mmi_bt_a2dp_query_state() != MMI_A2DP_STATE_IDLE)
    {
        g_mmi_profiles_bt_reset_pending |= 2;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_BT_RESET,g_mmi_profiles_bt_reset_pending);
    }
#endif
#ifdef __MMI_HFP_SUPPORT__
    if (mmi_profiles_bt_is_connected(MMI_PROFILES_BT_HFP_SCO))
    {
        g_mmi_profiles_bt_reset_pending |= 1;
        mmi_profiles_bt_disconnect_req(MMI_PROFILES_BT_HFP_SCO);
    }
    mmi_profiles_bt_connect_sco_app_callback = NULL;
#endif /* __MMI_HFP_SUPPORT__ */ 
    if (gactivatedprofile == MMI_PROFILE_BT)
    {
        if (mmi_gpio_is_earphone_plug_in())
        {
            mdi_audio_set_audio_mode(AUD_MODE_HEADSET);
            SetModeSpeechVolume();
            mmi_profiles_headset_activate_profile();
      #if defined ( __MMI_DUAL_SIM_MASTER__ )&& defined ( __MMI_DUAL_SIM_DUAL_CALL__ )
/* under construction !*/
      #endif
        }
        else
        {
            mmi_profiles_bt_deactivate_profile();
        }
    }
    if (g_mmi_profiles_bt_reset_pending == 0)
    {
        mmi_bt_panic_ind_post_process();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_is_activated
 * DESCRIPTION
 *  to check if bt profile is activated
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_profiles_bt_is_activated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (gactivatedprofile == MMI_PROFILE_BT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_open_stream_callback
 * DESCRIPTION
 *  a callback function for open bt stream cnf
 * PARAMETERS
 *  profile     [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_bt_open_stream_callback(U8 profile, mdi_result result, U16 error_cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_BT_OPEN_STREAM_CALLBACK,profile, result);

    if (result == MDI_AUDIO_SUCCESS)
    {
        res = MMI_PROFILES_BT_OK;
    }
    else if (result == MDI_AUDIO_BUSY)
    {
        res = MMI_PROFILES_BT_BUSY;
    }
    else
    {
        res = MMI_PROFILES_BT_FAIL;
    }
    switch (profile)
    {
    #ifdef __MMI_HFP_SUPPORT__
        case BT_HFP:
            mmi_profiles_bt_connect_callback(MMI_PROFILES_BT_HFP_SCO, MMI_PROFILES_BT_RSP, res);
            if( result == MDI_AUDIO_SUCCESS )
            {
				mmi_bth_sco_connect_ind_hdler(mmi_bt_get_active_signal_connection_id(MMI_BT_HFG_PROFILE_UUID));

    #ifdef __MMI_BT_AUDIO_VIA_SCO__
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_BT_START_SCO_TIMER,g_mmi_profiles_bt_sco_timeout);
                if(g_mmi_profiles_bt_sco_timeout)
                {
                    StopTimer(BT_SCO_CONNECT_TIMER);
                    StartTimer(BT_SCO_CONNECT_TIMER, BT_SCO_CONNECT_TIMEOUT_DURATION, mmi_profiles_bt_sco_timeout);
                }
    #endif /* #ifdef __MMI_BT_AUDIO_VIA_SCO__ */
            }
            else
            {
                mmi_bth_sco_connect_cnf_hdler(error_cause, mmi_bt_get_active_signal_connection_id(MMI_BT_HFG_PROFILE_UUID));
            }

            if (mmi_profiles_bt_connect_sco_app_callback != NULL)
            {
                mmi_profiles_bt_connect_sco_app_callback();
                mmi_profiles_bt_connect_sco_app_callback = NULL;
            }
            break;
    #endif /* __MMI_HFP_SUPPORT__ */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_close_stream_callback
 * DESCRIPTION
 *  a callback function for close bt stream cnf
 * PARAMETERS
 *  profile     [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_bt_close_stream_callback(U8 profile, mdi_result result, U16 error_cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
    void (*inquery_callback) (void);
#endif    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_BT_CLOSE_STREAM_CALLBACK,profile, result);

    switch (profile)
    {
    #ifdef __MMI_HFP_SUPPORT__
        case BT_HFP:
            mmi_profiles_bt_disconnect_callback(MMI_PROFILES_BT_HFP_SCO, MMI_PROFILES_BT_RSP, MMI_PROFILES_BT_OK);
    		mmi_bth_sco_disconnect_ind_hdler(mmi_bt_get_active_signal_connection_id(MMI_BT_HFG_PROFILE_UUID));

    #if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
            /* Callback inquery function because the SCO disconnect is called by BT inquery */
            if(g_mmi_profiles_bt_inquery_callback)
            {
                inquery_callback = g_mmi_profiles_bt_inquery_callback;
                g_mmi_profiles_bt_inquery_callback = NULL;                
                inquery_callback();
            }
    #endif

            break;
    #endif /* __MMI_HFP_SUPPORT__ */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_is_connected
 * DESCRIPTION
 *  to check if bt is connected
 * PARAMETERS
 *  connect_type        [IN]        
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_profiles_bt_is_connected(U8 connect_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL bt_connect = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (connect_type)
    {
    #ifdef __MMI_HFP_SUPPORT__
        case MMI_PROFILES_BT_HFP_ACL:
            bt_connect = (BOOL) mmi_bt_is_hs_connected();
            break;
        case MMI_PROFILES_BT_HFP_SCO:
            bt_connect = mdi_audio_bt_is_stream_open(BT_HFP);
            break;
    #endif /* __MMI_HFP_SUPPORT__ */ 
        default:
            break;
//            ASSERT(0);
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_BT_IS_CONNECTED,connect_type, bt_connect);

    return bt_connect;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_is_sco_connect_allowed
 * DESCRIPTION
 *  check if bt sco connect request is allowed
 * PARAMETERS
 *  void
 * RETURNS
 *  TURE if allowed
 *****************************************************************************/
BOOL mmi_profiles_bt_is_sco_connect_allowed(void)
{
    /* Can not connect SCO while FM is recording */
#ifdef __MMI_BT_FM_VIA_SCO__
    if((mdi_audio_get_audio_mode() == MDI_AUDIO_RECORD_FM_RADIO) &&
       (mdi_audio_get_state()== MDI_AUDIO_RECORD))
    {
        return FALSE;
    }
#endif

    return (!g_mmi_profiles_bt_disalbe_sco && !g_mmi_profiles_bt_inquerying);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_connect_req
 * DESCRIPTION
 *  bt connect request
 * PARAMETERS
 *  connect_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_bt_connect_req(U8 connect_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 connect_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_BT_CONNECT_REQ,connect_type, g_mmi_profiles_bt_disalbe_sco, g_mmi_profiles_bt_inquerying);

    switch (connect_type)
    {
    #ifdef __MMI_HFP_SUPPORT__
        case MMI_PROFILES_BT_HFP_SCO:
            if(mmi_profiles_bt_is_sco_connect_allowed())
            {
                connect_id = mmi_bt_get_active_signal_connection_id(MMI_BT_HFG_PROFILE_UUID);
                ASSERT(connect_id >= 0);
                mdi_audio_bt_open_stream(BT_HFP, (U16) connect_id);
            }
            break;
    #endif /* __MMI_HFP_SUPPORT__ */ 
        default:
            ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_disconnect_req
 * DESCRIPTION
 *  bt disconnect request
 * PARAMETERS
 *  connect_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_bt_disconnect_req(U8 connect_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_BT_DISCONNECT_REQ,connect_type);

    switch (connect_type)
    {
    #ifdef __MMI_HFP_SUPPORT__
        case MMI_PROFILES_BT_HFP_SCO:
            mdi_audio_bt_close_stream(BT_HFP);
            mmi_profiles_bt_connect_sco_app_callback = NULL;
            break;
    #endif /* __MMI_HFP_SUPPORT__ */ 
        default:
            ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_call_start_callback
 * DESCRIPTION
 *  the call back function for call start
 * PARAMETERS
 *  void
 *  BOOL(?)     [IN]        Turn on
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_bt_call_start_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL speech_on = mdi_audio_is_speech_mode();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_BT_CALL_START_CALLBACK,g_mmi_profiles_bt_in_call,speech_on);

    if (!g_mmi_profiles_bt_in_call)
    {
        if (gactivatedprofile == MMI_PROFILE_BT)
        {
        #ifdef __MMI_HFP_SUPPORT__
            if (mmi_profiles_bt_is_connected(MMI_PROFILES_BT_HFP_ACL))
            {
            #ifdef __BT_SPK_VOL_CONTROL__
                SetModeSpeechVolume();
            #endif
                if (g_mmi_profiles_bt_always_use_in_call || mmi_bt_is_aud2hf())
                {
                    mmi_profiles_bt_connect_req(MMI_PROFILES_BT_HFP_SCO);
                #ifdef __MMI_BT_AUDIO_VIA_SCO__
                    /* Stop SCO timeout timer during call */
                    StopTimer(BT_SCO_CONNECT_TIMER);
                #endif /* #ifdef __MMI_BT_AUDIO_VIA_SCO__ */
                }
            }
        #endif /* __MMI_HFP_SUPPORT__ */  
        }
        g_mmi_profiles_bt_in_call = TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_call_end_callback
 * DESCRIPTION
 *  the call back function for call end
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_bt_call_end_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL speech_on = mdi_audio_is_speech_mode();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_BT_CALL_END_CALLBACK,g_mmi_profiles_bt_in_call,speech_on);

    if (g_mmi_profiles_bt_in_call)
    {
        if (gactivatedprofile == MMI_PROFILE_BT)
        {
        #ifdef __MMI_HFP_SUPPORT__
            if (mmi_profiles_bt_is_connected(MMI_PROFILES_BT_HFP_ACL))
            {
                #if defined(__MMI_BT_AUDIO_VIA_SCO__) && defined(__MMI_BT_SCO_KEY_TONE__)
                    if(mmi_bt_is_aud2hf())
                    {
                        /* Disconnect later if support audio via BT SCO */
                        if(g_mmi_profiles_bt_sco_timeout)
                        {
                            StartTimer(BT_SCO_CONNECT_TIMER, BT_SCO_CONNECT_TIMEOUT_DURATION, mmi_profiles_bt_sco_timeout);
                        }
                    }
                    else
                    {
                        mmi_profiles_bt_disconnect_req(MMI_PROFILES_BT_HFP_SCO);                    
                    }
                #else
                    /* Disconnect right away after call */
                    mmi_profiles_bt_disconnect_req(MMI_PROFILES_BT_HFP_SCO);
                #endif
            }
        #endif /* __MMI_HFP_SUPPORT__ */ 
        }
        g_mmi_profiles_bt_in_call = FALSE;
    #ifdef __MMI_HFP_SUPPORT__
        g_mmi_profiles_bt_always_use_in_call = FALSE;
    #endif 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_connect_callback
 * DESCRIPTION
 *  the call back function for bt connect indication
 * PARAMETERS
 *  connect_type        [IN]        
 *  callback_type       [IN]        
 *  result              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_bt_connect_callback(U8 connect_type, U8 callback_type, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_BT_CONNECT_CALLBACK,connect_type, callback_type, result);

    switch (connect_type)
    {
    #ifdef __MMI_HFP_SUPPORT__
        case MMI_PROFILES_BT_HFP_ACL:
            if (callback_type == MMI_PROFILES_BT_IND || callback_type == MMI_PROFILES_BT_RSP)
            {
                if (result == MMI_PROFILES_BT_OK)
                {
                    if (gactivatedprofile != MMI_PROFILE_BT)
                    {
                        mmi_profiles_bt_activate_profile();
                    }
                    
            #ifdef __MMI_BT_AUDIO_VIA_SCO__
                    /* Connect SCO according to HFP audio path setting */
                    if (mmi_bt_is_aud2hf())
            #else /*__MMI_BT_AUDIO_VIA_SCO__*/
                #ifdef __MMI_BT_FM_VIA_SCO__
                    /* Need to check FM radio if FM via SCO on  */
                    if ((g_mmi_profiles_bt_in_call || mdi_audio_is_playing(MDI_AUDIO_PLAY_FM_RADIO)) &&
                        (g_mmi_profiles_bt_always_use_in_call || mmi_bt_is_aud2hf()))
                #else
                    if (g_mmi_profiles_bt_in_call && (g_mmi_profiles_bt_always_use_in_call || mmi_bt_is_aud2hf()))
                #endif
            #endif /*__MMI_BT_AUDIO_VIA_SCO__*/
                    {
                        mmi_profiles_bt_connect_req(MMI_PROFILES_BT_HFP_SCO);
                    }
                }
            }
            break;
        case MMI_PROFILES_BT_HFP_SCO:
            if (callback_type == MMI_PROFILES_BT_IND || callback_type == MMI_PROFILES_BT_RSP)
            {
                if (result == MMI_PROFILES_BT_OK)
                {
                    /* add a condition check for SCO, if it's not allowed, then disconnect it */
            #if !defined(__MMI_BT_AUDIO_VIA_SCO__)
                #ifdef __MMI_BT_FM_VIA_SCO__
                    if( !g_mmi_profiles_bt_app_in_use && !g_mmi_profiles_bt_in_call && !mmi_bt_is_doing_far_end_loopback_test()
                        && !mdi_audio_is_playing(MDI_AUDIO_PLAY_FM_RADIO) )
                #else
                    if( !g_mmi_profiles_bt_app_in_use && !g_mmi_profiles_bt_in_call && !mmi_bt_is_doing_far_end_loopback_test())
                #endif            
                    {
                        mmi_profiles_bt_disconnect_req( MMI_PROFILES_BT_HFP_SCO );
                        return;
                    }
            #endif /* #if !defined(__MMI_BT_AUDIO_VIA_SCO__) */
                
                    if (gactivatedprofile != MMI_PROFILE_BT)
                    {
                        mmi_profiles_bt_activate_profile();
                    }
                    if (g_mmi_profiles_bt_in_call)
                    {
                        g_mmi_profiles_bt_always_use_in_call = TRUE;
                    }
                }
            }
            break;
    #endif /* __MMI_HFP_SUPPORT__ */ 
        default:
            ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_disconnect_callback
 * DESCRIPTION
 *  the call back function for bt disconnect indication
 * PARAMETERS
 *  connect_type        [IN]        
 *  callback_type       [IN]        
 *  result              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_bt_disconnect_callback(U8 connect_type, U8 callback_type, U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_BT_DISCONNECT_CALLBACK,connect_type, callback_type, result);

    switch (connect_type)
    {
    #ifdef __MMI_HFP_SUPPORT__
        case MMI_PROFILES_BT_HFP_ACL:
            if (callback_type == MMI_PROFILES_BT_IND || callback_type == MMI_PROFILES_BT_RSP)
            {
                mmi_profiles_bt_disconnect_req(MMI_PROFILES_BT_HFP_SCO);
                if (gactivatedprofile == MMI_PROFILE_BT)
                {
                    if (mmi_gpio_is_earphone_plug_in())
                    {
                        mdi_audio_set_audio_mode(AUD_MODE_HEADSET);
                    #if defined ( __MMI_DUAL_SIM_MASTER__ )&& defined ( __MMI_DUAL_SIM_DUAL_CALL__ )
/* under construction !*/
                    #endif
                        mmi_profiles_headset_activate_profile();
                    }
                    else
                    {
                        mmi_profiles_bt_deactivate_profile();
                    }
                }
            }
            /* Change audio path back to phone before disconnect HFP ACL link */
            else if (callback_type == MMI_PROFILES_BT_REQ)
            {
                mdi_audio_bt_hfp_turn_off();
            }
            /* Resume audio background play if HFP ACL disconnected while BT inquirying */
            if(g_mmi_profiles_bt_inquerying)
            {
                mdi_audio_resume_background_play();
            }
            break;
        case MMI_PROFILES_BT_HFP_SCO:
            if (callback_type == MMI_PROFILES_BT_IND || callback_type == MMI_PROFILES_BT_RSP)
            {
                if (g_mmi_profiles_bt_reset_pending != 0)
                {
                    g_mmi_profiles_bt_reset_pending &= 0x0E;
                    if (g_mmi_profiles_bt_reset_pending == 0)
                    {
                        mmi_bt_panic_ind_post_process();
                    }
                }
            }
            break;
    #endif /* __MMI_HFP_SUPPORT__ */ 
        default:
            ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_activate_profile
 * DESCRIPTION
 *  activate BT profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_bt_activate_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_BT_ACTIVATE_PROFILE,gactivatedprofile, glastactivatedprofile);

	gprofileheadset = 0;
    if (gactivatedprofile != MMI_PROFILE_SILENT && gactivatedprofile != MMI_PROFILE_HEADSET &&
        gactivatedprofile != MMI_PROFILE_BT)
    {
        glastactivatedprofile = gactivatedprofile;
    }
    gactivatedprofile = MMI_PROFILE_BT;
    memcpy(&gcurrentprofile, &gprofiles[gactivatedprofile], sizeof(mmi_profiles_cntx_struct));
    WriteValue(NVRAM_PROFILES_LASTACTIVATED, &glastactivatedprofile, DS_BYTE, &error);
    mmi_profiles_show_alert_status_icon();
    change_font();

#if defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT)
    mmi_imps_set_presence_from_phnprof(gcurrentprofile.impsStatus);
#endif   

    mdi_audio_set_volume_no_apply(MDI_VOLUME_MEDIA, GetRingVolumeLevel());
    SetKeyPadVolume(GetKeypadVolumeLevel());
    mdi_audio_set_mic_volume();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_deactivate_profile
 * DESCRIPTION
 *  deactivate BT profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_bt_deactivate_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_BT_DEACTIVATE_PROFILE,gactivatedprofile, glastactivatedprofile);

    ReadValue(NVRAM_PROFILES_ACTIVATED, &gactivatedprofile, DS_BYTE, &error);
    memcpy(&gcurrentprofile, &gprofiles[gactivatedprofile], sizeof(mmi_profiles_cntx_struct));
    mmi_profiles_show_alert_status_icon();
    change_font();

#if defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT)
    mmi_imps_set_presence_from_phnprof(gcurrentprofile.impsStatus);
#endif   

#ifdef __MMI_PROF_MUTE_APP_ON_SILENT_MODE__
#ifdef __MMI_MEDIA_PLAYER__
    if(gactivatedprofile == MMI_PROFILE_SILENT || gactivatedprofile == MMI_PROFILE_MEETING)
    {
        mmi_medply_set_mute_callback();
    }
#endif
#endif

    if(gactivatedprofile == MMI_PROFILE_SILENT)
    {
        if(mmi_profiles_check_set_mute())
        {
            mdi_audio_set_mute(MDI_VOLUME_MEDIA,TRUE);
        }
    }

    mdi_audio_set_volume_no_apply(MDI_VOLUME_MEDIA, GetRingVolumeLevel());
    SetKeyPadVolume(GetKeypadVolumeLevel());
    mdi_audio_set_mic_volume();
}


#if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_disable_sco_timeout
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_bt_disable_sco_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_BT_DISABLE_SCO_TIMEOUT);
    
    StopTimer(BT_SCO_CONNECT_TIMER);
    g_mmi_profiles_bt_sco_timeout = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_enable_sco_timeout
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_bt_enable_sco_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_BT_ENABLE_SCO_TIEMOUT);

    g_mmi_profiles_bt_sco_timeout = MMI_TRUE;

    if(mmi_profiles_bt_is_connected(MMI_PROFILES_BT_HFP_SCO))
    {
        StartTimer(BT_SCO_CONNECT_TIMER, BT_SCO_CONNECT_TIMEOUT_DURATION, mmi_profiles_bt_sco_timeout);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_is_sco_app_idle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_profiles_bt_is_sco_app_idle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if( mdi_audio_is_idle()
    #if defined(__MMI_VIDEO_PLAY_SUPPORT__)
        && !mdi_video_is_playing()
    #endif
    #if defined(__MMI_VIDEO_RECORDER__)
        && !mdi_video_is_recording()
    #endif
    #if defined(BGSND_ENABLE)
        && mdi_audio_snd_is_idle()
    #endif
    #if defined(__MMI_MOBILE_TV_PLAYER__)
        && (mdi_mtv_is_playing()==MMI_FALSE)
    #endif
    #if defined(__BITSTREAM_API_SUPPORT__)
        && (mdi_bitstream_audio_get_open_handle_count() == 0)
    #endif
        && !mdi_audio_mma_is_open() 
        )
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_enable_sco_connect_delay_timer_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_bt_enable_sco_connect_delay_timer_callback(void)
{
    /* Press key or play audio in call will not connect SCO,
    *   call setup may leave the voice in phone */
    if(!g_mmi_profiles_bt_in_call && mmi_bt_is_aud2hf())
    {
        mmi_profiles_bt_connect_sco(NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_disable_sco_connection
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_bt_disable_sco_connection(U8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_BT_DISABLE_SCO_CONNECTION, g_mmi_profiles_bt_disalbe_sco, app_id);
    
    StopTimer(BT_SCO_CONNECT_TIMER);
    StopTimer(BT_SCO_ENABLE_CONNECT_DELAY_TIMER);
    g_mmi_profiles_bt_disalbe_sco |= app_id;

    mmi_profiles_bt_disconnect_sco();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_enable_sco_connection
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_bt_enable_sco_connection(U8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_BT_ENABLE_SCO_CONNECTION, g_mmi_profiles_bt_disalbe_sco, app_id);

    g_mmi_profiles_bt_disalbe_sco &= ~app_id;

    if(!g_mmi_profiles_bt_disalbe_sco)
    {
        /* Connect SCO if the audio path is "forward to BT", or the application is runnung */
        if(mmi_bt_is_aud2hf() && !mmi_profiles_bt_is_sco_app_idle())
        {
            StartTimer(BT_SCO_ENABLE_CONNECT_DELAY_TIMER, BT_SCO_RECONNECT_TIMER_DURATION, mmi_profiles_bt_enable_sco_connect_delay_timer_callback);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_sco_timeout
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_bt_sco_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_BT_SCO_TIMEOUT,mmi_profiles_bt_is_connected(MMI_PROFILES_BT_HFP_SCO), g_mmi_profiles_bt_in_call);
    
    if(mmi_profiles_bt_is_connected(MMI_PROFILES_BT_HFP_SCO))
    {
        /* If audio/video is not playing or not in call */
        if(!g_mmi_profiles_bt_in_call && mmi_profiles_bt_is_sco_app_idle())
        {
            mmi_profiles_bt_disconnect_sco();
        }
        /* still using audio resource, disconnect later */
        else if(g_mmi_profiles_bt_sco_timeout && !g_mmi_profiles_bt_in_call)
        {
            StartTimer(BT_SCO_CONNECT_TIMER, BT_SCO_CONNECT_TIMEOUT_DURATION, mmi_profiles_bt_sco_timeout);
        }
    }
}
                
/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_inquery_start_callback
 * DESCRIPTION
 *  Callback function for BT inquery
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_profiles_bt_inquiry_error_enum mmi_profiles_bt_inquery_start_callback(void (*callback) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 sco_status;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sco_status = mdi_audio_bt_get_stream_status(BT_HFP);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_BT_INQUERY_START_CALLBACK,sco_status);

    g_mmi_profiles_bt_inquery_callback = NULL;
    g_mmi_profiles_bt_inquerying = MMI_TRUE;

    /* When HFP is connected, suspend audio background play */
    if(mmi_bt_is_hs_connected() && mmi_bt_is_aud2hf())
    {
        mdi_audio_suspend_background_play_by_app(MDI_AUD_SUSPEND_BG_SCO_INQ);
        
        switch(sco_status)
        {
            case MDI_AUDIO_BT_STATE_IDLE:
                return MMI_PROFILES_BT_INQ_SCO_DISCONNECTED;
                break;
                
            case MDI_AUDIO_BT_STATE_WAIT_CLOSE:
                g_mmi_profiles_bt_inquery_callback = callback;
                break;
                
            case MDI_AUDIO_BT_STATE_OPEN:
            case MDI_AUDIO_BT_STATE_WAIT_OPEN:
                if(g_mmi_profiles_bt_in_call)
                {
                    g_mmi_profiles_bt_inquerying = MMI_FALSE;

                    /* May let caller always call stop inquiry function to resume background play*/
                    mdi_audio_resume_background_play_by_app(MDI_AUD_SUSPEND_BG_SCO_INQ); 
                    return MMI_PROFILES_BT_INQ_SCO_CONNECTED_IN_CALL;
                }

                StopTimer(BT_SCO_CONNECT_TIMER);
                g_mmi_profiles_bt_inquery_callback = callback;    
                mmi_profiles_bt_disconnect_sco();
                break;

            default:
                ASSERT(0);
                break;
        }
    }
    else
    {
        return MMI_PROFILES_BT_INQ_SCO_DISCONNECTED;
    }

    return MMI_PROFILES_BT_INQ_SCO_CONNECTED_DISCONNECTABLE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_inquery_stop_callback
 * DESCRIPTION
 *  Callback function for BT inquery
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_profiles_bt_inquery_stop_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_BT_INQUERY_STOP_CALLBACK);

    g_mmi_profiles_bt_inquery_callback = NULL;

    /* Connect SCO after background play resume */
    g_mmi_profiles_bt_inquerying = MMI_FALSE;

    /* If HFP connect during inquiry and the audio is playing, then connect SCO */
    if(mmi_bt_is_hs_connected() && mmi_bt_is_aud2hf() && !mmi_profiles_bt_is_sco_app_idle())
    {
        /* not connect right away because it is not desire by the driver */
        StartTimer(BT_SCO_ENABLE_CONNECT_DELAY_TIMER, BT_SCO_RECONNECT_TIMER_DURATION, mmi_profiles_bt_enable_sco_connect_delay_timer_callback);    
    }

    mdi_audio_resume_background_play_by_app(MDI_AUD_SUSPEND_BG_SCO_INQ); 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_profiles_bt_connect_audio_via_sco
 * DESCRIPTION
 *  connect sco link
 * PARAMETERS
 *  void
 * RETURNS
 * void
 *****************************************************************************/
void mmi_profiles_bt_connect_audio_via_sco(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_BT_CONNECT_AUDIO_VIA_SCO,g_mmi_profiles_bt_in_call);

    /* Press key or play audio in call will not connect SCO,
    *   call setup may leave the voice in phone */
    if(!g_mmi_profiles_bt_in_call && mmi_bt_is_aud2hf())
    {
        mmi_profiles_bt_connect_sco(NULL);
    }
}

#endif /* #if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__) */

#endif /* __MMI_BT_PROFILE__ */ 

