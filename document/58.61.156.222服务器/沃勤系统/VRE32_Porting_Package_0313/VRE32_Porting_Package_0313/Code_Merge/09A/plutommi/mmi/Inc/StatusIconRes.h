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
 *  StatusIconRes.h
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
 *  
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

 /**************************************************************
   FILENAME : CustDataRes.h

      PURPOSE     : Image id definitions for status icons

   REMARKS     : nil

   AUTHOR      : Vijay

   DATE     : Dec-16-2002.

*************************************************************/

#ifndef STATUSICONSRES_H
#define STATUSICONSRES_H

#include "MMIDataType.h"

#if defined(__J2ME__)
#include "j2me_custom_option.h"
#endif /* defined(__J2ME__) */

enum STATUS_ICON_ID_LIST
{
    IMG_SI_SIGNAL_STRENGTH = STATUS_ICONS_BASE,
    IMG_SI_BATTERY_STRENGTH,
    IMG_SI_KEYPAD_LOCK,
    IMG_SI_VIBRATE,
    IMG_SI_SILENT,
    IMG_SI_RING,
    IMG_SI_VIBRATE_AND_RING,
    IMG_SI_VIBRATE_THEN_RING,
    IMG_SI_ALARM_ACTIVATED,
    IMG_SI_ROAMING_INDICATOR,
    IMG_SI_MISSED_CALL_INDICATOR,
    IMG_SI_LINE_L1,
    IMG_SI_LINE_L2,
    IMG_SI_3G, 
    IMG_SI_2G, 
    IMG_SI_ANY,
    IMG_SI_VOIP,
    IMG_SI_GPRS_INDICATOR,
    IMG_SI_IR_INDICATOR,
    IMG_SI_UNREAD_EMAIL,
    IMG_SI_UNREAD_VOICE_L1,
    IMG_SI_UNREAD_VOICE_L2,
    IMG_SI_UNREAD_VOICE_L1L2,
    IMG_SI_UNREAD_FAX_L1,
    IMG_SI_UNREAD_FAX_L2,
    IMG_SI_UNREAD_FAX_L1L2,
    IMG_SI_UNREAD_EMAIL_L1,
    IMG_SI_UNREAD_EMAIL_L2,
    IMG_SI_UNREAD_EMAIL_L1L2,
    IMG_SI_SMS_INDICATOR,
    IMG_SI_CALL_DIVERT_L1,
    IMG_SI_CALL_DIVERT_L2,
    IMG_SI_CALL_DIVERT_L1L2,
    IMG_SLSI_SIGNAL_STRENGTH,
    IMG_SLSI_BATTERY_STRENGTH,
    IMG_SLSI_SMS_INDICATOR,
    IMG_SLSI_RING,
    IMG_SLSI_VIBRATE,
    IMG_SLSI_VIBRATE_AND_RING,
    IMG_SLSI_VIBRATE_THEN_RING,
    IMG_SI_WMAL,
    IMG_SLSI_SILENT,
    IMG_SI_VOICE_RECORD,
    
#ifdef __MMI_DUAL_SIM_MASTER__
    IMG_SI_WAP1,
    IMG_SI_WAP2,
#else /* __MMI_DUAL_SIM_MASTER__ */
    IMG_SI_WAP,
#endif /* __MMI_DUAL_SIM_MASTER__ */

    IMG_SI_MUTE,
    IMG_SI_EARPHONE_INDICATOR,
    IMG_SI_GPRS_ATT_NO_PDP_INDICATOR,
    IMG_SI_MMS_UNREAD_INDICATOR,
    IMG_SI_MMS_BUSY_INDICATOR,
    IMG_SLSI_ALARM,
    IMG_SLSI_MISSED_CALL,
    IMG_SI_STOPWATCH,
    IMG_SI_BT,
    IMG_SI_BT_CON,
    IMG_SI_BT_ND,
    IMG_SI_NETWORK_CIPHER_GSM,
    IMG_SI_NETWORK_CIPHER_GPRS,
    IMG_SI_SIGNAL_STRENGTH_L1,
    IMG_SI_SIGNAL_STRENGTH_L2,
    IMG_SI_POC,
#if defined(__J2ME__) && defined(J2ME_SUPPORT_BACKGROUND)
    IMG_SI_JAVA_BG_VM,
    IMG_SI_JAVA_BG_VM_AUDIO,
#endif
		
#ifdef __MMI_AUTO_ANSWER_MACHINE__
		IMG_SI_AUTOAM_REC,
		IMG_SI_AUTOAM_UNREAD,
    IMG_SI_AUTOAM_ON,
#endif /* __MMI_AUTO_ANSWER_MACHINE__ */ 

    IMG_SI_IMPS_MSG,
    IMG_SI_IMPS_LOGIN,
    IMG_SI_IMPS_LOGIN_FAIL,
    IMG_SI_KEYPAD_UNLOCK,
#ifdef __MMI_BG_SOUND_EFFECT__
    IMG_SI_BGSND,
#endif /* __MMI_BG_SOUND_EFFECT__ */ 
#ifdef __MMI_AUDIO_REVERB_EFFECT__
    IMG_SI_REVERBSND,
#endif /* __MMI_AUDIO_REVERB_EFFECT__ */ 
#ifdef __MMI_AUDIO_SURROUND_EFFECT__
    IMG_SI_SURROUNDSND,
#endif    
#ifdef __MMI_HOMEZONE_STATUS_ICON__
    IMG_SI_HZONE,
    IMG_SI_CZONE,
#endif /* __MMI_HOMEZONE_STATUS_ICON__ */ 
#ifdef __CTM_SUPPORT__
    IMG_SI_TTY_INDICATOR,
#endif /* __CTM_SUPPORT__ */ 
    IMG_SI_JAVA_CONNECT,
    
#ifndef __MMI_DUAL_SIM_MASTER__
    IMG_SI_CSD,
#else /* __MMI_DUAL_SIM_MASTER__ */
    IMG_SI_CSD_SIM1,
    IMG_SI_CSD_SIM2,
#endif /* __MMI_DUAL_SIM_MASTER__ */

    IMG_SI_EDGE,
    IMG_SI_EDGEC,
#ifdef __MMI_PICT_BRIDGE_SUPPORT__
    IMG_SI_PRINT,
    IMG_SI_PRINT_FAIL,
#endif

#ifdef __MMI_CALL_INDICATOR__
    IMG_SI_CALL_INDICATOR_ACTIVE,
    IMG_SI_CALL_INDICATOR_HOLD,
#endif /* __MMI_CALL_INDICATOR__ */


#ifdef __MMI_MOBILE_TV_PLAYER__
    IMG_SI_MTV_SIGNAL,
#endif 

#if (defined(OBIGO_Q05A) || defined(JATAAYU_SUPPORT)) && defined(WAP_SUPPORT)
    IMG_SI_SECURITY,
#endif
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    IMG_SI_OUTBOX_INDICATOR,
#endif
	IMG_SI_SMS_SENDING,
#ifdef __MMI_AUDIO_PLAYER__
    IMG_SI_AUDPLY,
#endif

#ifdef __MMI_MEDIA_PLAYER__
    IMG_SI_MEDPLY,
#endif

    IMG_SI_UNREAD_NET_L1,
    IMG_SI_UNREAD_NET_L2,
    IMG_SI_UNREAD_NET_L1L2,
    IMG_SI_EMAIL_REF,
#if defined(__AGPS_SUPPORT__) && defined(__SUPL_SUPPORT__)
    IMG_SI_AGPS_STATE,
#endif
#ifdef __MMI_SYNCML_STATUS_ICON_SUPPORT__
    IMG_SI_SYNCML,
#endif

#ifdef __MMI_PROV_INBOX_SUPPORT__
    IMG_SI_PROVMSG,
#ifdef __MMI_DUAL_SIM_MASTER__
    IMG_SI_PROVMSG_SIM1,
    IMG_SI_PROVMSG_SIM2,
#endif
#endif
#ifdef __QQIM_SUPPORT__
    IMG_SI_QQIM_AWAY,
    IMG_SI_QQIM_INVISIBLE,
    IMG_SI_QQIM_MSG,
    IMG_SI_QQIM_OFFLINE,
    IMG_SI_QQIM_ONLINE,
#endif
/* Vogins Start */
#ifdef __VRE30_AM__
    IMG_SI_VRE_DEFAULT,
    IMG_SI_VRE_FETION,
    IMG_SI_VRE_MSN,
    IMG_SI_VRE_PUSHMAIL,
    IMG_SI_VRE_QQ,
#endif
/* Vogins End */
    IMG_SI_END
};

#ifdef __MMI_DUAL_SIM_MASTER__
#include "..\..\..\vendor\mercury_master\inc\MTPNP_AD_resdef.h"
#endif

#endif /* STATUSICONSRES_H */ 
