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
 * Keybrd.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for keypad processing
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
 * removed!
 * removed!
 *
 * removed!
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

/*****************************************************************************
* Include                                                                     
*****************************************************************************/

#include "MMI_features.h"
#include "mmi_frm_gprot.h"
#include "mmi_frm_prot.h"
#include "AudioInc.h"                    /* For AudioPlayReq and AudioStopReq */
#include "SettingProfile.h"              /* For key tone enum like KEYPAD_TONE_HUMAN_VOICE_1 */
#include "ProfileGprots.h"               /* For GetKeypadToneType */
#include "VolumeHandler.h"               /* For SetDefaultVolumeKeyHandlers */
#include "IdleAppDef.h"
#include "IdleAppProt.h"
#include "SimDetectionResDef.h"
#include "SettingDefs.h"
#include "SettingsGdcl.h"
#ifdef __MMI_EMAIL__
#include "EmailAppGProt.h"
#endif /* __MMI_EMAIL__ */

#ifdef __MMI_VOIP__
#include "VoIPGProt.h"
#endif
#include "UCMGProt.h"
#include "UcmSrvGprot.h"

#include "kbd_table.h"
#include "keypad_sw.h"
#include "gpioInc.h"
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
#include "wgui_touch_screen.h"
#endif 
#include "ScreenRotationGprot.h"
#include "kbd_table.h"
#include "ProfilingEngine.h"
#include "SimDetectionGprot.h"


#include "L4c_eq_msg.h"     /* for l4c_kbd_getkeydata */
#include "rmmi_custom_inc.h"

#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_AVRCP_SUPPORT__)
#include "BtcmSrvGprot.h"
#include "BTMMIAVRCPGProt.h"
#endif /* defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_AVRCP_SUPPORT__) */

#ifdef __LSK_KEYSEND2_IN_ONE__
/* under construction !*/
#endif/*__LSK_KEYSEND2_IN_ONE__*/

#ifdef __MMI_DUAL_SIM_MASTER__
#include "MTPNP_AD_resdef.h"
#include "MTPNP_AD_master_if.h"
#endif /* __MMI_DUAL_SIM_MASTER__ */

#ifdef __MMI_MEMORY_MONITOR__
#include "EngineerModeFrmProfiling.h"
#endif


/***************************************************************************** 
* Define
*****************************************************************************/
//#define __MMI_FRM_KEY_EVENT_UT__

/* Element number of g_key_code_map[] */
#define KEY_CODE_MAP_TBL_NUM    sizeof(g_key_code_map)/sizeof(g_key_code_map[0])

/* Element number of g_key_tone[] */
#define KEY_TONE_MAP_TBL_NUM    sizeof(g_key_tone)/sizeof(g_key_tone[0])

/* Element number of g_key_type_map[] */
#define KEY_TYPE_MAP_TBL_NUM    sizeof(g_key_type_map) / sizeof(g_key_type_map[0])

/* Element number of g_key_type_trans */
#define KEY_TYPE_TRANS_TBL_NUM  sizeof(g_key_type_trans) / sizeof(g_key_type_trans[0])

/* Element number of g_key_cntx.buffer[], which depends on the max key detection mode supported by driver */
#if defined(__TWO_KEY_DETECTION_SWITCHABLE__)
#define MAX_DECT_KEY_NUM            (2) /* driver support 1 & 2 key detection mode */
#elif defined( __THREE_KEY_DETECTION_SWITCHABLE__)
#define MAX_DECT_KEY_NUM            (3) /* driver support 1 & 2 & 3 key detection mode */
#else
#ifndef __MMI_FRM_KEY_EVENT_UT__
#define MAX_DECT_KEY_NUM            (1) /* driver only support 1 key detection */
#else
#define MAX_DECT_KEY_NUM            (2)
#endif
#endif

#ifdef __MMI_FRM_KEY_EVENT_UT__
#define LOOK_AHEAD_BUF_LEN          (10)
#else
#define LOOK_AHEAD_BUF_LEN          (MAX_DECT_KEY_NUM + 3)
#endif


/* Key code number of mmi key code */
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
#define MAX_KEY_NUM  MAX_QWERTY_KEYS    /* qwerty keypad */
#else
#define MAX_KEY_NUM  MAX_KEYS           /* number keypad */
#endif

/* Function to get key event from key buffer */
#define KBD_ATCMD_GET_KEY_FUNC   (l4c_kbd_getkeydata) /* AT Command key buffer */
#define KBD_DRVIER_GET_KEY_FUNC  (Kbd_GetKeyData)     /* hard key buffer */

/* Macro to judge whether in call or not. */
#define IS_IN_CALL() (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)

/* Error Code for MMI Key event, which are used as the return value of the function get_key_events */
#define KEY_EVENT_DECT     (MAX_KEY_TYPE)         /* detection event */
#define ERR_KEY_EVT_TRANS  (MAX_KEY_TYPE + 1)     /* wrong event flow */
#define ERR_KEY_EVENT      (MAX_KEY_TYPE + 2)     /* wrong event */
#define ERR_KEY_CODE       (MAX_KEY_TYPE + 3)     /* wrong key code */

/* dummy key tone id value */
#define DUMMY_KEY_TONE (0xFFFF)
#define INSERT_SAME_KEY_CODE    (-1000)                /* Insert a key code that is in g_key_cntx.buffer[] */
#define INSERT_CODE_BEYOND_DECT (-1001)                /* Insert a key code that beyond driver detection mode */
#define REMOVE_BUT_NOT_FOUND    (-1002)                /* remove a key code but not found */
#define LOOK_AHEAD_BUF_FULL     (-1003)
/********************************************************************************************************************
 * Content:  keypad state
 * Variable: g_key_cntx.keypad_status (8bit)
 *===============================================================
 * Init state: 
 *     For Qwerty Keypad: 0b 01 0 0 1 000  = 0x48
 *                        
 *     For Number Keypad: 0b 00 0 0 0 000  = 0x00
 * State after screen switch:
 *     For Qwerty Keypad: 0b 01 x x 1 000
 *             
 *     For Number Keypad: 0b 00 x x 0 000
 *                    x - changed when runtime
 *===============================================================
 * Bit0-Bit2: keypad mode
 *            000 - KEYPAD_1KEY_NUMBER
 *            001 - KEYPAD_2KEY_NUMBER
 *            010 - KEYPAD_3KEY_NUMBER
 *            011 - KEYPAD_1KEY_QWERTY
 *            100 - KEYPAD_2KEY_QWERTY
 *            101 - KEYPAD_3KEY_QWERTY
 *            110 - reserved
 *            111 - reserved
 * -----------------------------------------
 * Bit3: key 0-9 *# tone mode 
 *            0 - DTMF tone (see table g_key_tone[])
 *            1 - normal key tone(TONE_KEY_NORMAL, DEVICE_AUDIO_PLAY_ONCE)
 * -----------------------------------------
 * Bit4: flag of suspend key events handle
 *            0 - not suspend key processing
 *            1 - suspend key processing
 * -----------------------------------------
 * Bit5: reserved
 *
 * -----------------------------------------
 * Bit6-7: key detection mode of driver
 *            00 - kbd_1_key_det_mode
 *            01 - kbd_2_keys_det_mode
 *            10 - kbd_3_keys_det_mode
 *            11 - reserved
 * 
 ********************************************************************************************************************/
#define SET_KPD_MODE(word, mode)            ((word) = ((((U8)(word)) & ~0x07) | ((U8)(mode) & 0x7)))
#define GET_KPD_MODE(word)                  (((word)) & 0x07)
#define KPD_NUM_KEY_TONE_MOD_FLAG           (3)
#define KPD_SUSPEND_FLAG                    (4)
#define SET_KEY_DET_MODE(word, mode)        ((word) = ((((U8)(word)) & ~0xC0) | (((U8)((mode) << 6) & 0xC0))))
#define GET_KEY_DET_MODE(word)              (((((word)) & 0xC0) >> 6))

/* keypad state initial value */
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
#define KPD_STATE_PREDEFINE_VAL             (0x48) /* see upper comment */
#else
#define KPD_STATE_PREDEFINE_VAL             (0x00) /* see upper comment */
#endif

/* Full controll key number(KEY_END, KEY_VOL_UP, KEY_VOL_DOWN) */
#define FULL_CTRL_KEY_NUM                   (3) 


/*********************************************************************************************************************
 * The following value is used to construct key type mapping and key type transform table
 * ---------------------------------
 * g_key_type_map[] 
 *     bit7-5 device key type
 *     bit4-2 mmi key type, 
 *     bit1-0  01-2step key
 *             10-non 2step key
 *             11-both
 *             00-reserved
 * ---------------------------------
 * g_key_type_trans[]
 *     Bit7-5  previous key type
 *     Bit4-2  current key type
 *     Bit1-0  01-2step key
 *             10-non 2step key
 *             11-both
 *             00-reserved
 *********************************************************************************************************************/
#define SET_DEV_KEY_TYPE(type)                   (((type) << 5) & 0xE0)
#define SET_MMI_KEY_TYPE(type)                   (((type) << 2) & 0x1C)
#define SET_PRE_KEY_TYPE(type)                   (((type) << 5) & 0xE0)
#define SET_CUR_KEY_TYPE(type)                   (((type) << 2) & 0x1C)
#define GET_DEV_KEY_TYPE(val)                    (((val) & 0xE0) >> 5)
#define GET_MMI_KEY_TYPE(val)                    (((val) & 0x1C) >> 2)
#define GET_PRE_KEY_TYPE(val)                    (((val) & 0xE0) >> 5)
#define GET_CUR_KEY_TYPE(val)                    (((val) & 0x1C) >> 2)
#define SET_CAT(cat)                             ((cat) & 0x03)
#define GET_CAT(val)                             ((val) & 0x03)
#define KEY_TYPE_MAP(dev_type, mmi_type, cat)    SET_DEV_KEY_TYPE(dev_type) | SET_MMI_KEY_TYPE(mmi_type) | SET_CAT(cat)
#define KEY_TYPE_TRANS(pre_type, cur_type, cat)  SET_PRE_KEY_TYPE(pre_type) | SET_CUR_KEY_TYPE(cur_type) | SET_CAT(cat)

/* Get key category(key_type_cat_enum) by mmi key code */
#ifdef __KBD_2STEP_KEY_SUPPORT__
#define GET_KEY_CAT(key_code)  (U8)((is_2step_key(key_code) == MMI_TRUE) ? TWO_STEP_KEY : NON_TWO_STEP_KEY)
#else
#define GET_KEY_CAT(key_code)  NON_TWO_STEP_KEY
#endif

#ifdef __MMI_SCREEN_ROTATE__
/* Entry number of g_kpd_rot_data[] */
#define KPD_ROT_DAT_TBL_NUM  sizeof(g_kpd_rot_data) / sizeof(g_kpd_rot_data[0])

/* 4 direction key UP, DOWN, LEFT, RIGHT */
#define DIR_KEY_NUM          (4)
#endif 

/* Entry number of g_key_code_cvt_tbl[] */
#define KEY_CODE_CVT_TBL_NUM sizeof(g_key_code_cvt_tbl) / sizeof(g_key_code_cvt_tbl[0])

/* Entry number of g_check[] */
#define CHK_FUNC_TBL_NUM     sizeof(g_check) / sizeof(g_check[0])

/* Entry number of g_key_pre_handle_table[] */
#define KEY_PRE_HDL_TBL_NUM  sizeof(g_key_pre_handle_table)/sizeof(g_key_pre_handle_table[0])

/* Entry number of g_key_post_handle_table[] */
#define KEY_POST_HDL_TBL_NUM sizeof(g_key_post_handle_table)/sizeof(g_key_post_handle_table[0])

/* Entry number of g_key_handler */
#define SPE_KEY_HDL_TBL_NUM  sizeof(g_key_handler) / sizeof(g_key_handler[0])

/* key event report mode */
#define  KEY_EVT_REPORT_NONE        (0)
#define  KEY_EVT_REPORT_HW_ONLY     (1)
#define  KEY_EVT_REPORT_HW_AT       (2)

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/* 
 * 2step key state, this state is used to judge if we need to send half press up only or 
 * we need to send both half press up and full press up.
 */
typedef enum
{
    HALF_DOWN,
    FULL_DOWN,
    FULL_UP,
    STATE_END    
} _2step_state_enum;

/*
 * 2 step key and non-2step have different key type flow
 * we use this enum to distingush
 */

typedef enum
{
    TWO_STEP_KEY = 0x1,
    NON_TWO_STEP_KEY = 0x2,
    ALL_TYPE = 0x3
} key_type_cat_enum;

/* 
 * key code convert function pointer type
 * we group all key code converted functions as a table
 */
typedef S16 (*key_code_cvt_func_ptr)(S16 mmi_key_code);

/* 
 * check function pointer type
 * check function means the function will be invoked before
 * execute key event handler. For example, backlight check 
 * or touch screen check.
 */
typedef MMI_BOOL (* chk_func_ptr)(void);

/*
 * static pre and post key handler type
 * we design 2 table to manage the things that will always be done
 * before and after key handler
 */
typedef void (*key_pre_post_func_ptr)(S16 mmi_key_code, S16 mmi_key_type);

/*
 * get key handler function pointer type
 * we design a table to manage all functions that get key handler.
 */
typedef FuncPtr (* get_func_ptr)(S16 mmi_key_code, S16 mmi_key_type);


#ifdef __MMI_SCREEN_ROTATE__
/* keypad rotate struct */
typedef struct
{
    U8 rot_degree;           /* rotate degree enum [mmi_frm_screen_rotate_enum] */
    S8 step;                 /* jump step for dir key table */ 
} kpd_rot_struct;
#endif

/* device key code and mmi key code mapping table */
typedef struct
{
    U8 device_key_code;     /* Device key code, see kbd_table.h */
    U8 mmi_key_code;        /* mmi key code, see GlobalConstants.h mmi_keypads_enum */
} key_code_map_struct;

/* key tone table */    
typedef struct
{
    U8 mmi_key_code;     /* mmi key code, see GlobalConstants.h mmi_keypads_enum */
    U8 mmi_key_tone;     /* Tone id see Resource_audio.h audio_id_enum */
} key_tone_struct;

/* device key event */
typedef struct
{
    U8 device_key_code;    /* device key code, see kbd_table.h */
    U8 device_key_type;    /* device key type, see keypad_sw.h */
    MMI_BOOL is_clear;
} dev_key_evt_struct;

/* mmi key event */
typedef struct
{
    S16 mmi_key_code;     /* mmi key code, see GlobalConstants.h mmi_keypads_enum */
    S16 mmi_key_type;     /* mmi key type, see GlobalConstants,h mmi_key_types_enum */
    S16 cvt_code;
    MMI_BOOL is_clear;
} mmi_key_evt_struct;

/* Full ctrl key cntx */
typedef struct
{
    U8 mmi_key_code;
    MMI_BOOL state;
} full_ctrl_struct;

/* 2step key cntx */
typedef struct
{
    U8 mmi_key_code;
    U8 state;
} _2step_key_struct;

/* key date */
typedef struct
{
    U8 mmi_key_code;       /* mmi key code */
    U8 mmi_key_type;       /* mmi key type */
    U8 cvt_code;
    MMI_BOOL is_clear;     /* This flag is used to record if ClearKeyEvent happen when this key code is in active*/
    MMI_BOOL is_combo;     /* like SHIFT FN */
    MMI_BOOL is_2step;     /* like CAMERA */
    MMI_BOOL is_full_ctrl; /* like END, VOL_UP, VOL_DOWN */
} key_data_struct;

/* key cntx */
typedef struct
{
    drv_get_key_func keypad_ptr;

    /* key event report mode */
    U8  key_event_report_mode;  /* 0 no report, 1, report hardware key only, 2 report hareware + AT */
    
    U8 keypad_status;  /* State of keypad, please see comment in Define section for detail */
    /* 
     * bit0-2    keypad mode            
     * bit3      key 0-9 *# tone mode      
     * bit4      flag of suspend key events handle     
     * bit5      reserved
     * bit6-7    key detection mode of driver
     */
    key_data_struct buffer[MAX_DECT_KEY_NUM];       /* key data buffer */
    U8 buf_len;                                     /* valid element number in key data buffer */
#ifdef __KBD_2STEP_KEY_SUPPORT__    
    _2step_key_struct _2step_key;                   /* 2step key cntx */
#endif /* __KBD_2STEP_KEY_SUPPORT__ */    
    full_ctrl_struct  full_ctrl[FULL_CTRL_KEY_NUM]; /* full control key context */
    U16 curr_keypad_tone;                       /* current key tone id */
    MMI_BOOL is_key_event;                      /* execute current key handler is invoke by key procedure */
    PsKeyProcessCBPtr kbd_pre_func;             /* function to be executed before general keypad handler */
    PsKeyProcessCBPtr kbd_post_func;            /* function to be executed after general keypad handler */
    U8 curr_key_code;                           /* Keep the current key code */
    U8 curr_key_type;                           /* Keep the current key type */
    U16 key_tone_id;
    U8 key_tone_duration;
    mmi_frm_kbd_tone_state_enum key_tone_state; /* state of keypad tone */ 
    dev_key_evt_struct look_ahead[LOOK_AHEAD_BUF_LEN];
    U8 num_look_ahead;
	U8 r_look_ahead;
	U8 w_look_ahead;
} key_cntx_struct;
/*****************************************************************************
* Local Function                                                              
*****************************************************************************/
static void mmi_secset_goto_puk1(void);
#ifdef __MMI_DUAL_SIM_MASTER__
static void mmi_secset_goto_sim2_pin1(void);
static void mmi_secset_goto_sim2_puk1(void);
#endif /* __MMI_DUAL_SIM_MASTER__ */
static void set_end_key_handler_in_call(void);
static void get_mmi_key_events(dev_key_evt_struct *dev_evt_p, mmi_key_evt_struct *mmi_evt_p);
static void get_exec_key_evt(key_data_struct *data_p, mmi_key_evt_struct *exec_evt_p, U32 *evt_num_p);
static void dev_key_handle(dev_key_evt_struct *dev_evt_p);
static void mmi_key_handle(mmi_key_evt_struct *mmi_evt_p);
static MMI_BOOL is_full_ctrl_key(U16 mmi_key_code);
static MMI_BOOL is_combo_key(S16 mmi_key_code);
static MMI_BOOL set_full_ctrl_key_state(S16 mmi_key_code, MMI_BOOL state);
static MMI_BOOL is_full_ctrled(S16 mmi_key_code);
static mmi_frm_num_key_tone_mode_enum get_default_num_tone_mode(void);
static MMI_BOOL default_sys_level_trans_key_hdlr(S16 mmi_key_code, S16 mmi_key_type, U16 ucs2_value, U32 special_key_flag);
static void init_key_data_buf(void);
static mmi_ret insert_key_data(key_data_struct * data_p);
static S32 search_key_data(S16 mmi_key_code);
static MMI_BOOL update_key_data(key_data_struct *data_ptr);
static mmi_ret remove_key_data(S16 mmi_key_code);
static S16 get_key_state(S16 mmi_key_code);
static U8 get_data_buf_len(void);
static void get_key_data(key_data_struct *data_p, U8 index);
static void  get_mmi_key_codes_in_data_buf(U8 *mmi_key_code_p, U8 *num);
static void pre_update_key_data_buf(key_data_struct *data_p);
static void post_update_key_data_buf(void);
static void gen_key_data(mmi_key_evt_struct *evt, key_data_struct *data_p);
#ifdef __KBD_2STEP_KEY_SUPPORT__
static MMI_BOOL is_2step_key(S16 mmi_key_code);
static U8 get_2step_key_state(S16 mmi_key_code);
static void pre_update_2step_key_state(S16 mmi_key_code, S16 mmi_key_type);
static void post_update_2step_key_state(S16 mmi_key_code, S16 mmi_key_type);
#endif /* __KBD_2STEP_KEY_SUPPORT__ */
static S16 get_mmi_key_type(U8 device_key_type, U8 cat);
static MMI_BOOL is_legal_key_type(S16 curr_mmi_key_type, S16 pre_mmi_key_type, U8 cat);
static S16 get_mmi_key_code(U8 device_key_code);
static U8 get_device_key_code(U8 mmi_key_code);
static MMI_BOOL get_dev_key_evt(dev_key_evt_struct *dev_evt_p);
#ifdef __MMI_SCREEN_ROTATE__ 
static S16 get_rotated_mmi_key_code(S16 mmi_key_code);
#endif
static S16 enter_to_lsk(S16 mmi_key_code);
static S16 mmi_key_code_convert(S16 mmi_key_code, U8 dev_key_type);
#if defined(__MMI_SLEEP_OUT_BACKLIGHT_ON__) 
static MMI_BOOL backlight_check(void);
#endif
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__) 
static MMI_BOOL pen_check(void);
#endif
static MMI_BOOL exec_check_func(key_data_struct *data_p);
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__) 
static void pen_pre_key_handler(S16 mmi_key_code, S16 mmi_key_type);
#endif
#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_AVRCP_SUPPORT__) 
static void bt_pre_key_handler(S16 mmi_key_code, S16 mmi_key_type);
#endif
#ifdef __MMI_INTERACTIVE_PROFILNG__ 
static void profiling_pre_key_handler(S16 mmi_key_code, S16 mmi_key_type);
#endif
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__ 
static void special_keys_pre_key_handler(S16 mmi_key_code, S16 mmi_key_type);
#endif
static void backlight_pre_key_handler(S16 mmi_key_code, S16 mmi_key_type);
static void keypad_lock_pre_key_handler(S16 mmi_key_code, S16 mmi_key_type);
static void screen_saver_pre_key_handler(S16 mmi_key_code, S16 mmi_key_type);
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__) 
static void pen_post_key_handler(S16 mmi_key_code, S16 mmi_key_type);
#endif
#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_AVRCP_SUPPORT__) 
static void bt_post_key_handler(S16 mmi_key_code, S16 mmi_key_type);
#endif
#ifdef __MMI_INTERACTIVE_PROFILNG__ 
static void profiling_post_key_handler(S16 mmi_key_code, S16 mmi_key_type);
#endif
#ifdef __MMI_MEMORY_MONITOR__ 
static void mem_monitor_post_key_handler(S16 mmi_key_code, S16 mmi_key_type);
#endif
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__ 
static void special_keys_post_key_handler(S16 mmi_key_code, S16 mmi_key_type);
#endif
static void exec_static_pre_key_handler(mmi_key_evt_struct *evt_p);
static void exec_static_post_key_handler(mmi_key_evt_struct *evt_p);
static void exec_dynamic_post_key_handler(mmi_key_evt_struct *evt_p);
static void exec_key_handler(mmi_key_evt_struct *evt_p);
static MMI_BOOL exec_dynamic_pre_key_handler(mmi_key_evt_struct *evt_p);
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__ 
static FuncPtr get_any_key_handler(S16 mmi_key_code, S16 mmi_key_type);
#endif
static FuncPtr get_repeat_key_handler(S16 mmi_key_code, S16 mmi_key_type);
#ifdef __MMI_WGUI_MINI_TAB_BAR__  
static FuncPtr get_mini_tab_bar_key_handler(S16 mmi_key_code, S16 mmi_key_type);
#endif
#ifdef __MMI_SCREEN_SNAPSHOT__ 
static FuncPtr get_screen_snapshot_key_handler(S16 mmi_key_code, S16 mmi_key_type);
#endif
#ifdef __LSK_KEYSEND2_IN_ONE__ 
/* under construction !*/
#endif
static FuncPtr get_default_key_handler(S16 mmi_key_code, S16 mmi_key_type);
static FuncPtr get_key_handler(S16 mmi_key_code, S16 mmi_key_type);
#if defined (__MMI_SUBLCD_MASTER_MODE__)
static MMI_BOOL clam_check(S16 mmi_key_code, S16 mmi_key_type);
#endif
static void set_all_key_data_clear(void);
static void update_clear_state(mmi_key_evt_struct *evt);
static void process_key_ptr_change(void * para_buff);
static U16 get_key_tone(S16 mmi_key_code);
#if defined(__MMI_CUST_KEYPAD_TONE__)
static S16 get_cust_key_tone_id(S16 MMIKeyCode);
#endif /* __MMI_CUST_KEYPAD_TONE__ */
#if defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__)
static S16 get_human_voice_key_tone_id(S16 MMIKeyCode);
#endif /* __MMI_CUST_KEYPAD_TONE__ */
static void mmi_frm_key_handle_before_poweron(void *paraBuff);
static U8 mmi_frm_key_tone_duration(S16 mmi_key_code);
static void mmi_secset_goto_pin1(void);
static void key_event_notification(S16 key_code, S16 key_type);
/*
 * look ahead buffer related
 */
static MMI_BOOL is_need_write_back(dev_key_evt_struct *dev_p, dev_key_evt_struct *buf, U8 len);
static MMI_BOOL write_look_ahead_buffer(dev_key_evt_struct *dev_evt_p);
static MMI_BOOL read_look_ahead_buffer(dev_key_evt_struct *dev_evt_p);

#ifdef __MMI_FRM_KEY_EVENT_UT__
static S16 key_code_convert_test1(S16 mmi_key_code);
static S16 key_code_convert_test2(S16 mmi_key_code);
#endif
static void report_key_evt(U8 dev_key_code, U8 dev_key_type);
static MMI_BOOL is_need_report_to_l4(U8 dev_key_type);
/*****************************************************************************
* static Global Variable
*****************************************************************************/

/* key event context */
static key_cntx_struct g_key_cntx;

#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
/* 
 * In qwerty project, there are no key handlers for KEY_A.., So in order that
 * application do not need to modify more codes, Any key handler is implemented
 * for the case that application wants handle all keys in one key handler like
 * the following 
 *       SetGroupKeyHandler(XXX, PresentAllKeys, TOTAL_KEYS, XXX)
 * please see SetGroupKeyHandler for more information.
 * The any key handler will also record the dial key for P & W in qwerty project
 * The usage is SetGroupKeyHandler(XXX, PresentAllDialerKeys, TOTAL_DIALER_KEYS, XXX)
 * 
 */
static FuncPtr anyKeyFuncPtrs[MAX_KEY_TYPE] = {0};    
#endif

/***************************************************************************** 
* External Global Variable Declaration
*****************************************************************************/
   
#if defined(__DIRECT_ENTRY_FACTORY_MODE_ON_BOOTUP__)
/* 
 * This value is defined in MiscFunction.c, 
 * If it is set, the cell phone will entry factory mode directly
 */
extern BOOL DirectMode;                               
#endif /* defined(__DIRECT_ENTRY_FACTORY_MODE_ON_BOOTUP__) */

/*****************************************************************************
* Global Variable
*****************************************************************************/

/*
 * Key Event Handler Table
 */
 
#ifdef __MMI_SUBLCD_MASTER_MODE__

/* available slave mode key func ptrs to current screen  */
FuncPtr currKeyFuncPtrs_slave[MAX_KEYS][MAX_KEY_TYPE];

/* available master mode key func ptrs to current screen  */
FuncPtr currKeyFuncPtrs_master[MAX_KEYS][MAX_KEY_TYPE];

/* available key func ptrs to current screen  */
FuncPtr currKeyFuncPtrs[MAX_KEYS][MAX_KEY_TYPE];

#else

/* available key func ptrs to current screen  */
FuncPtr currKeyFuncPtrs[MAX_KEYS][MAX_KEY_TYPE];

#endif /* __MMI_SUBLCD_MASTER_MODE__ */

/***************************************************************************** 
* Const Global Variable
*****************************************************************************/

/* 
 * This table is designed to distinguish the app's codes and framework's tricky codes
 * that change the key handler before key handlr is invoked directly.
 * 1. any key handler
 *    In qwerty project, more key code like A, B, C is invoked in our system, 
 *    However, the key handler table is not enlarged because we design translate key 
 *    handler that will receive all key codes and we believe the translate key handler
 *    will be the further way to handle key events. In order to
 *    let application suffer little, we design the any key handler to handle the 
 *    case - applications invoke SetGroupKeyHandler(XXX, PresentAllKeys, TOTAL_KEYS, XXX)
 *    and he wants to handle all keys in one key handler, such as keypad lock in ilde
 * 2. repeat to down handler
 *    This is the framework's tricky codes, framework assume that if applications do not
 *    register key repeat handler, they take key handler handler as the key repeat handler
 *    so when receiving key repeat, framework will check this condition and get the down
 *    handler for repeat event, such as in list keep pressing down key.
 * 3. mini tab bar special case
 *    This case should confirm with tab bar's own to see if these code can be removed
 * 4. screen snap shot special case
 *    This case should confirm with camera's own to see if these code can be removed.
 * 5. lsk get send key handler
 *    This case should confirm with owner to see if these code can be removed.
 */
const static get_func_ptr g_key_handler[] = 
{
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)    
    get_any_key_handler,
#endif
#ifndef __MMI_FRM_KEY_RULE__
    get_repeat_key_handler,
#endif /* __MMI_FRM_KEY_RULE__ */    
#ifdef __MMI_WGUI_MINI_TAB_BAR__    
    get_mini_tab_bar_key_handler,
#endif
#ifdef __MMI_SCREEN_SNAPSHOT__    
    get_screen_snapshot_key_handler, 
#endif
#ifdef __LSK_KEYSEND2_IN_ONE__       
/* under construction !*/
#endif
    get_default_key_handler   
};

/* 
 * static pre key handler table
 * 
 * static is corresponding to the dynamic pre key handler.
 * we design this table to group all the things that will always be done
 * before we invoke the key handler. such as
 * 1. Disable touch screen
 * 2. Disable BT key pad
 * 3. profiling
 * 4. update special key's flag before key handler is invoked
 * 5. backlight
 * 6. keypad lock
 * 7. screen saver
 * The reason we group them together is
 *    1. seperate app's code from framework's code and make the architecture more clearly
 *    2. easy to add new function that will always be invoked before key handler is called.
 */
const static key_pre_post_func_ptr g_key_pre_handle_table[] = 
{
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)     
    pen_pre_key_handler,
#endif
#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_AVRCP_SUPPORT__)     
    bt_pre_key_handler,
#endif
#if defined(__MMI_INTERACTIVE_PROFILNG__)     
    profiling_pre_key_handler,
#endif
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)    
    special_keys_pre_key_handler,
#endif    
    backlight_pre_key_handler,
    screen_saver_pre_key_handler,
    keypad_lock_pre_key_handler
};

/* 
 * static post key handler table
 *
 * static is corresponding to the dynamic post key handler.
 * we design this table to group all the things that will always be done
 * after key handle is invoked. such as,
 * 1. Enable pen
 * 2. Enable BT key pad
 * 3. profiling
 * 4. memory monitor
 * 5. special key handler
 * The reason we designt this table is the same as we design the static 
 * pre key handler table
 */
const static key_pre_post_func_ptr g_key_post_handle_table[] = 
{
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
    pen_post_key_handler,
#endif
#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_AVRCP_SUPPORT__)    
    bt_post_key_handler,
#endif
#ifdef __MMI_INTERACTIVE_PROFILNG__    
    profiling_post_key_handler,
#endif
#ifdef __MMI_MEMORY_MONITOR__    
    mem_monitor_post_key_handler,
#endif
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__     
    special_keys_post_key_handler,
#endif
    NULL
};

/* 
 * check function table
 *
 * we design this table group the things that will be check
 * before keypad can response, for example, we must check
 * backlight/pen and so on. In furthe we may need to check
 * keypad lock.
 * Pay attention that this check is done at receiving down
 * for non-2step key and half down for 2 step key, if the check
 * function return true, the keypad refuse to action this time.
 */
const static chk_func_ptr g_check[] = 
{
#if defined(__MMI_SLEEP_OUT_BACKLIGHT_ON__)
    backlight_check,
#endif
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
    pen_check,
#endif
    NULL    
};

#ifdef __MMI_SCREEN_ROTATE__
/*
 * we design this 2 table to handle direction key change
 * when screen rotation.
 * 1. direction key is managed in clockwise sequency in table
 *  g_dir_key[]
 * 2. the element of the rotation table has 2 member.
 *    rotation degree, step in g_dir_key[]
 *    For example, 270, -1
 *    if right is recevied, we find it in g_dir_key[]
 *    it's index is 1, so 1 + (-1), we will get UP,
 *    it is the key code we will get
 *    if we support 90 , 180, we will add them to rotation
 *    table.
 *    MMI_FRM_SCREEN_ROTATE_90,  1
 *    MMI_FRM_SCREEN_ROTATE_180, 2
 */
/* keypad rotate data table */
const static kpd_rot_struct g_kpd_rot_data[] =
{
/* Vogins Start */
#ifdef __VRE_V30__
    {MMI_FRM_SCREEN_ROTATE_90, (S8)1},
    {MMI_FRM_SCREEN_ROTATE_180, (S8)2},
#endif
/* Vogins End */
    {MMI_FRM_SCREEN_ROTATE_270, (S8)-1}
};

/* direction key table clockwise */
const U8 g_dir_key[] = {KEY_UP_ARROW, KEY_RIGHT_ARROW, KEY_DOWN_ARROW, KEY_LEFT_ARROW};
#endif

/* 
 * key code convert function table 
 *
 *  In our platform, we get device key event from driver and
 *  change it to MMI key event. This change has 2 category
 *  static and dynamic.
 *  static is: getting from mapping table
 *  dynamic is: getting by the following function
 *  1. In QWERTY project, KEY_1 and KEY_E may corresponse to
 *     the same device key code, DEVICE_KEY_1 or DEVICE_KEY_E
 *     if the driver map the DEVICE_KEY_E to the hard key
 *     we will get KEY_E from the mapping table, however whether to
 *     send KEY_1 or KEY_E to application that dependency on the current
 *     keypad mode, mmi_frm_qwerty_convert_key_code will do this convert
 *  2. when screen rotation, the direction key will be rotated also
 *  3. if no one register KEY_ENTER's handler, we will mapping KEY_ENTER
 *     to KEY_LSK
 */
const static key_code_cvt_func_ptr g_key_code_cvt_tbl[] = 
{
#ifdef __MMI_FRM_KEY_EVENT_UT__
    key_code_convert_test1,
    key_code_convert_test2,
#endif
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    mmi_frm_qwerty_convert_key_code,
#endif
#ifdef __MMI_SCREEN_ROTATE__
    get_rotated_mmi_key_code,
#endif
#ifndef __MMI_FRM_KEY_RULE__
    enter_to_lsk,
#endif /* __MMI_FRM_KEY_RULE__ */
    NULL
};

/*
 * device key event to MMI key event mapping table
 * 
 *   Bit7-5(3bit) device key type
 *   Bit4-2(3bit) mmi key type
 *   Bit1-0(2bit) if normal event, 2 step key's mapping or non-step key's mapping or both
 *                if detection event, detection mode
 * 
 *   we design this table to reduce the switch case and if statement in codes
 */
const static U8 g_key_type_map[] = 
{
#ifdef __KBD_2STEP_KEY_SUPPORT__
    KEY_TYPE_MAP(DRV_WM_KEYPRESS,                   KEY_HALF_PRESS_DOWN, TWO_STEP_KEY),
    KEY_TYPE_MAP(DRV_WM_KEYFULLPRESS,               KEY_FULL_PRESS_DOWN, TWO_STEP_KEY),
#endif /* __KBD_2STEP_KEY_SUPPORT__ */    
    KEY_TYPE_MAP(DRV_WM_KEYPRESS,                   KEY_EVENT_DOWN,      NON_TWO_STEP_KEY), 
    KEY_TYPE_MAP(DRV_WM_KEYRELEASE,                 KEY_EVENT_UP,        ALL_TYPE),
    KEY_TYPE_MAP(DRV_WM_KEYLONGPRESS,               KEY_LONG_PRESS,      ALL_TYPE),
    KEY_TYPE_MAP(DRV_WM_KEYREPEATED,                KEY_REPEAT,          ALL_TYPE),
#if  defined(__TWO_KEY_DETECTION_SWITCHABLE__) || defined(__THREE_KEY_DETECTION_SWITCHABLE__)    
    KEY_TYPE_MAP(DRV_WM_ENABLE_TWOKEY_DETECTION,    MAX_KEY_TYPE,        kbd_2_keys_det_mode),
#ifdef __THREE_KEY_DETECTION_SWITCHABLE__    
    KEY_TYPE_MAP(DRV_WM_ENABLE_THREEKEY_DETECTION,  MAX_KEY_TYPE,        kbd_3_keys_det_mode),
#endif /* __THREE_KEY_DETECTION_SWITCHABLE__ */   
#endif /*__TWO_KEY_DETECTION_SWITCHABLE__ */ 
    KEY_TYPE_MAP(DRV_WM_DISABLE_MULTIKEY_DETECTION, MAX_KEY_TYPE,        kbd_1_key_det_mode)  
};

/*
 * MMI key event transition table
 *
 *   Bit7-5(3bit) previous MMI key event
 *   Bit4-2(3Bit) possible current key event
 *   Bit1-0(2bit) 2step, non-2step or both
 *
 *   we design this table to reduce the switch case and if statement in codes
 */
const static U8 g_key_type_trans[] =
{
#ifdef __KBD_2STEP_KEY_SUPPORT__
    KEY_TYPE_TRANS(KEY_EVENT_UP,        KEY_HALF_PRESS_DOWN, TWO_STEP_KEY),
#endif /* __KBD_2STEP_KEY_SUPPORT__ */    
    KEY_TYPE_TRANS(KEY_HALF_PRESS_DOWN, KEY_EVENT_DOWN,      TWO_STEP_KEY),
    KEY_TYPE_TRANS(KEY_HALF_PRESS_DOWN, KEY_EVENT_UP,        TWO_STEP_KEY),   
    KEY_TYPE_TRANS(KEY_EVENT_UP,        KEY_EVENT_DOWN,      NON_TWO_STEP_KEY),
    KEY_TYPE_TRANS(KEY_EVENT_DOWN,      KEY_LONG_PRESS,      ALL_TYPE),
    KEY_TYPE_TRANS(KEY_LONG_PRESS,      KEY_REPEAT,          ALL_TYPE),
    KEY_TYPE_TRANS(KEY_REPEAT,          KEY_REPEAT,          ALL_TYPE),
    KEY_TYPE_TRANS(KEY_REPEAT,          KEY_EVENT_UP,        ALL_TYPE),
    KEY_TYPE_TRANS(KEY_LONG_PRESS,      KEY_EVENT_UP,        ALL_TYPE),
    KEY_TYPE_TRANS(KEY_EVENT_DOWN,      KEY_EVENT_UP,        ALL_TYPE),
}; 

/*
 * All mmi keys except KEY_CSK & QWERTY keys like KEY_A...
 * are listed in this table. However, in QWERTY project,
 * the array has special means when use it at SetGroupKeyHandler: 
 * even though it does not contain qwerty keys, but it means all keys in the keypad.
 * So any key handler is implemented for this. Please see SetGroupKeyHandler for
 * details.
 * This array is mainly used for SetGroupKeyhandler
 */
 
const U16 PresentAllKeys[] = 
{
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
    KEY_LSK,
    KEY_RSK,
    KEY_UP_ARROW,
    KEY_DOWN_ARROW,
    KEY_LEFT_ARROW,
    KEY_RIGHT_ARROW,
    KEY_SEND,
    KEY_POWER,
    KEY_END,
#ifdef __MMI_WITH_C_KEY__    
    KEY_CLEAR,
#endif    
    KEY_VOL_UP,
    KEY_VOL_DOWN,
    KEY_CAMERA,
    KEY_ENTER,
#ifdef __MMI_KLG__    
    KEY_EXTRA_1,
    KEY_EXTRA_2,
#endif    
#ifdef __SUBLCD_DEDICATED_KEYS_SUPPORT__
    KEY_PLAY_STOP,
    KEY_FWD,
    KEY_BACK,
#endif
#ifdef __POWERONOFF_BY_POWERKEY__
    KEY_POWER,
#endif
#ifdef __EXTRA_A_B_KEY_SUPPORT__
    KEY_EXTRA_A,
    KEY_EXTRA_B,
#endif    
#ifdef __SENDKEY2_SUPPORT__
    KEY_SEND1,
    KEY_SEND2,
#endif  /* __SENDKEY2_SUPPORT__ */
};

/*
 *  We add this array for UCM and video call
 *  They will handle key 0~9 8#  in number key pad
 *  handle 0~9 *# PW in QWERTY project
 *  They using SetGroupKeyHandler(XXX, PresentAllDialerKeys, TOTAL_DIALER_KEYS, XXX)
 *  in qwert project, we will record P and W' handler in any key handler
 *  The application should skip other keys.
 *  Please see SetGroupKeyHandler for detail
 *
 */
const U16 PresentAllDialerKeys[] =
{
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
    KEY_POUND
};

/* 
 * Driver key code to MMI key code mapping table
 * We will list all device key code here.
 * accurate device key code for specific project, please
 * look at the table keypad_custom_def in keypad_def.c and keypad_drv.h
 * Moreover, in this table one device key code is mapped to
 * one mmi key code but one device key code may correspond to 
 * two mmi key code in qwerty project.
 * eg. character E & number 1 may appear in one hard key.
 *     The device key code will be DEVICE_KEY_E (character first when mapping device key code in qwerty project)
 *     The mmi key code will be KEY_E or KEY_1 depends on the keypad mode
 *     (see GlobalConstants.h mmi_frm_keypad_mode_enum)
 */
const static key_code_map_struct g_key_code_map[] = 
{
    {DEVICE_KEY_0             , KEY_0},
    {DEVICE_KEY_1             , KEY_1},
    {DEVICE_KEY_2             , KEY_2},
    {DEVICE_KEY_3             , KEY_3},
    {DEVICE_KEY_4             , KEY_4},
    {DEVICE_KEY_5             , KEY_5},
    {DEVICE_KEY_6             , KEY_6},
    {DEVICE_KEY_7             , KEY_7},
    {DEVICE_KEY_8             , KEY_8},
    {DEVICE_KEY_9             , KEY_9},
    {DEVICE_KEY_STAR          , KEY_STAR},
    {DEVICE_KEY_HASH          , KEY_POUND},
    {DEVICE_KEY_VOL_UP        , KEY_VOL_UP},
    {DEVICE_KEY_VOL_DOWN      , KEY_VOL_DOWN},
    {DEVICE_KEY_UP            , KEY_UP_ARROW},
    {DEVICE_KEY_DOWN          , KEY_DOWN_ARROW},
    {DEVICE_KEY_LEFT          , KEY_LEFT_ARROW},
    {DEVICE_KEY_RIGHT         , KEY_RIGHT_ARROW},
    {DEVICE_KEY_MENU          , KEY_ENTER},
    {DEVICE_KEY_FUNCTION      , KEY_QUICK_ACS},
    {DEVICE_KEY_SK_LEFT       , KEY_LSK},
    {DEVICE_KEY_SK_RIGHT      , KEY_RSK},
    {DEVICE_KEY_SEND          , KEY_SEND},
    {DEVICE_KEY_END           , KEY_END},   
    {DEVICE_KEY_POWER         , KEY_POWER},  
#ifdef __MMI_WITH_C_KEY__     
    {DEVICE_KEY_CLEAR         , KEY_CLEAR},
#endif    
#ifdef __MMI_KLG__    
    {DEVICE_KEY_EXT_FUNC1     , KEY_EXTRA_1},
    {DEVICE_KEY_EXT_FUNC2     , KEY_EXTRA_2},
#endif    
#ifdef __SUBLCD_DEDICATED_KEYS_SUPPORT__
    {DEVICE_KEY_MP3_PLAY_STOP , KEY_PLAY_STOP},
    {DEVICE_KEY_MP3_FWD       , KEY_FWD},
    {DEVICE_KEY_MP3_BACK      , KEY_BACK},
#endif
#ifdef __EXTRA_A_B_KEY_SUPPORT__
    {DEVICE_KEY_EXT_A         , KEY_EXTRA_A},
    {DEVICE_KEY_EXT_B         , KEY_EXTRA_B},
#endif    
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__    
    {DEVICE_KEY_A             , KEY_A},
    {DEVICE_KEY_B             , KEY_B},
    {DEVICE_KEY_C             , KEY_C},
    {DEVICE_KEY_D             , KEY_D},
    {DEVICE_KEY_E             , KEY_E},
    {DEVICE_KEY_F             , KEY_F},
    {DEVICE_KEY_G             , KEY_G},
    {DEVICE_KEY_H             , KEY_H},
    {DEVICE_KEY_I             , KEY_I},
    {DEVICE_KEY_J             , KEY_J},
    {DEVICE_KEY_K             , KEY_K},
    {DEVICE_KEY_L             , KEY_L},
    {DEVICE_KEY_M             , KEY_M},
    {DEVICE_KEY_N             , KEY_N},
    {DEVICE_KEY_O             , KEY_O},
    {DEVICE_KEY_P             , KEY_P},
    {DEVICE_KEY_Q             , KEY_Q},
    {DEVICE_KEY_R             , KEY_R},
    {DEVICE_KEY_S             , KEY_S},
    {DEVICE_KEY_T             , KEY_T},
    {DEVICE_KEY_U             , KEY_U},
    {DEVICE_KEY_V             , KEY_V},
    {DEVICE_KEY_W             , KEY_W},
    {DEVICE_KEY_X             , KEY_X},
    {DEVICE_KEY_Y             , KEY_Y},
    {DEVICE_KEY_Z             , KEY_Z},
    {DEVICE_KEY_SPACE         , KEY_SPACE},
    {DEVICE_KEY_TAB           , KEY_TAB},
    {DEVICE_KEY_DEL           , KEY_DEL},
    {DEVICE_KEY_ALT           , KEY_ALT},
    {DEVICE_KEY_CTRL          , KEY_CTRL},
    {DEVICE_KEY_WIN           , KEY_WIN},
    {DEVICE_KEY_SHIFT         , KEY_SHIFT},
    {DEVICE_KEY_QUESTION      , KEY_QUESTION},
    {DEVICE_KEY_PERIOD        , KEY_PERIOD},
    {DEVICE_KEY_COMMA         , KEY_COMMA},
    {DEVICE_KEY_EXCLAMATION   , KEY_EXCLAMATION},
    {DEVICE_KEY_APOSTROPHE    , KEY_APOSTROPHE},
    {DEVICE_KEY_AT            , KEY_AT},
    {DEVICE_KEY_BACKSPACE     , KEY_BACKSPACE},
    {DEVICE_KEY_ENTER         , KEY_QWERTY_ENTER},
    {DEVICE_KEY_FN            , KEY_FN},
    {DEVICE_KEY_SYMBOL        , KEY_SYMBOL},
    {DEVICE_KEY_NUM_LOCK      , KEY_NUM_LOCK},
    {DEVICE_KEY_QWERTY_MENU   , KEY_QWERTY_MENU},
    {DEVICE_KEY_OK            , KEY_OK},
#endif /* __MMI_QWERTY_KEYPAD_SUPPORT__ */

#ifdef __SENDKEY2_SUPPORT__
    {DEVICE_KEY_SEND2         , KEY_SEND2},
#endif /* __SENDKEY2_SUPPORT__ */
};

/* 
 * Only 0~9 *# has special key key tone. its duration is DEVICE_AUDIO_PLAY_INFINITE
 * For other keys, their tone is TONE_KEY_NORMAL, duration is DEVICE_AUDIO_PLAY_ONCE
 */
const static key_tone_struct g_key_tone[] = 
{
   {KEY_0,     TONE_DTMF_0  },
   {KEY_1,     TONE_DTMF_1  },
   {KEY_2,     TONE_DTMF_2  },
   {KEY_3,     TONE_DTMF_3  },
   {KEY_4,     TONE_DTMF_4  },
   {KEY_5,     TONE_DTMF_5  },
   {KEY_6,     TONE_DTMF_6  },
   {KEY_7,     TONE_DTMF_7  },
   {KEY_8,     TONE_DTMF_8  },
   {KEY_9,     TONE_DTMF_9  },
   {KEY_STAR,  TONE_KEY_STAR},
   {KEY_POUND, TONE_KEY_HASH},
};


/*****************************************************************************
* Extern Global Function
*****************************************************************************/
extern void ShutdownSystemOperation(void);
extern void kbd_find_2step(kal_uint32 *number, kal_uint8 *two_step);
extern kal_bool Kbd_GetKeyData(kbd_data *keydata);
extern kal_bool w32_key_det_mode_switch( unsigned char keymode_num_to_switch);
#if defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__)
extern U8 CanPlayHumanVoiceKeyTone(void);
#endif
#if defined(__MMI_CUST_KEYPAD_TONE__)
extern U8 CanPlayCustKeyTone(void);
#endif
#if defined(__DIRECT_ENTRY_FACTORY_MODE_ON_BOOTUP__)
extern void CallBackPowerOnAnimationCompleteWrapper(void);
#endif /* defined(__DIRECT_ENTRY_FACTORY_MODE_ON_BOOTUP__) */

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_init_key_event
 * DESCRIPTION
 *  This function is used for key event handle module, which is only used in
 *  MMITask.c task init function
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_init_key_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __KBD_2STEP_KEY_SUPPORT__    
    kal_uint8 _2step_key;
    kal_uint32 _2step_key_num = 0;
#endif /* __KBD_2STEP_KEY_SUPPORT__ */    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_key_cntx.curr_keypad_tone      = DUMMY_KEY_TONE;
    g_key_cntx.keypad_status         = KPD_STATE_PREDEFINE_VAL;
    g_key_cntx.is_key_event          = MMI_TRUE;
    init_key_data_buf();
    g_key_cntx.full_ctrl[0].mmi_key_code = KEY_END;
    g_key_cntx.full_ctrl[1].mmi_key_code = KEY_VOL_UP;
    g_key_cntx.full_ctrl[2].mmi_key_code = KEY_VOL_DOWN;
    g_key_cntx.full_ctrl[0].state = MMI_FALSE;
    g_key_cntx.full_ctrl[1].state = MMI_FALSE;
    g_key_cntx.full_ctrl[2].state = MMI_FALSE;
    g_key_cntx.curr_key_code = KEY_INVALID;
    g_key_cntx.curr_key_type = MAX_KEY_TYPE;
    g_key_cntx.num_look_ahead = 0;
    g_key_cntx.r_look_ahead = g_key_cntx.w_look_ahead = 0;
#ifdef __KBD_2STEP_KEY_SUPPORT__    
    g_key_cntx._2step_key.state = FULL_UP;
    kbd_find_2step(&_2step_key_num, &_2step_key);
    g_key_cntx._2step_key.mmi_key_code = (U8)get_mmi_key_code(_2step_key);
    MMI_ASSERT(_2step_key_num < 2);
#endif /* __KBD_2STEP_KEY_SUPPORT__ */
    mmi_frm_set_translate_key_handler(MMI_FRM_TRANS_KEY_SYS, default_sys_level_trans_key_hdlr);
    mmi_frm_set_keypad_mode(KEYPAD_1KEY_NUMBER);
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
	/* Init framework qwerty module */
    mmi_frm_qwerty_init();
#endif
}
   

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_key_event_screen_switch_action
 * DESCRIPTION
 *  The things need to be done by key event handle when screen switch
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_key_event_screen_switch_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    mmi_frm_set_default_num_key_tone_mode(MMI_FRM_NUM_KEY_TONE_NORMAL);
#else
    mmi_frm_set_default_num_key_tone_mode(MMI_FRM_NUM_KEY_TONE_DTMF);
#endif
    mmi_frm_set_keypad_mode(KEYPAD_1KEY_NUMBER);
    /* reset full control key state */
    g_key_cntx.full_ctrl[0].state = MMI_FALSE;
    g_key_cntx.full_ctrl[1].state = MMI_FALSE;
    g_key_cntx.full_ctrl[2].state = MMI_FALSE;     
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_key_evt_report_ind
 * DESCRIPTION
 *  protocol event handler of MSG_ID_MMI_AT_KEYPAD_EVENT_ACT_IND
 *
 * PARAMETERS
 *  para       : [IN] local parameter of MSG_ID_MMI_AT_KEYPAD_EVENT_ACT_IND
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_key_evt_report_ind(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_at_keypad_event_act_ind_struct *p = (mmi_at_keypad_event_act_ind_struct *)para;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (p != NULL)
    {
        g_key_cntx.key_event_report_mode = p->mode;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_kbd_is_key_supported
 * DESCRIPTION
 *  query if specified mmi key code is supported
 * PARAMETERS
 *  mmi_key_code    :[IN]    mmi key code (mmi_keypads_enum) to query
 * RETURNS
 *  key is supported or not
 *****************************************************************************/
MMI_BOOL mmi_frm_kbd_is_key_supported(S16 mmi_key_code)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	MMI_BOOL ret;
	MMI_BOOL ret1;
	MMI_BOOL ret2;
	S16 op_code = mmi_key_code;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	MMI_ASSERT((mmi_key_code >= 0) && (mmi_key_code < MAX_KEY_NUM));
	
#ifndef __MTK_TARGET__
	/* No power key on Modis */
	if (mmi_key_code == KEY_POWER)
	{
		ret = MMI_FALSE;
		MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_KEY_MMI_KEY_CODE_SUPPORTED, mmi_key_code, ret);    
		return ret; 	
	}
#endif
	/* 
	* 1 driver key code may mapped to 2 mmi key code in qwerty project.
	* eg. DEVICE_KEY_E	=> KEY_E & KEY_1, or DEVICE_KEY_1 => KEY_E & KEY_1
	* in this case if mmi_key_code = KEY_E, the opposite_mmi_key_code = KEY_1
	* if mmi_key_code = KEY_1, the opposite_mmi_key_code = KEY_E
	*
	* However, in key mapping table, DEVICE_KEY_E => KEY_E, DEVICE_KEY_1 => KEY_1
	* Whether KEY_E is supported or not is determinded by either DEVICE_KEY_E or DEVICE_KEY_1
	* is supported. Pay attention: they cannot be both valid or both invalid, if this happen, Please check 
	* key layout in keypad_def.c
	*/	
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__	
	op_code = mmi_frm_qwerty_get_opposite_key_code(mmi_key_code);
#endif /* __MMI_QWERTY_KEYPAD_SUPPORT__ */
	if (op_code == mmi_key_code)
	{
		ret = kbd_IsKeyButtonSupported(get_device_key_code((U8)mmi_key_code));
	}
	else
	{
		ret1 = kbd_IsKeyButtonSupported(get_device_key_code((U8)mmi_key_code));
		ret2 = kbd_IsKeyButtonSupported(get_device_key_code((U8)op_code));
		MMI_ASSERT((!ret1 && ret2) || (ret1 && (!ret2)));
		ret = ret1 || ret2; 	
	}
	MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_KEY_MMI_KEY_CODE_SUPPORTED, mmi_key_code, ret);   
	return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_key_info
 * DESCRIPTION
 *  This function is used for querying key code & key type of last key event.
 *  This function is mainly used with group key handler.
 *  Because the application cannot get the key code and key type in his group
 *  key handler, so it needs this interface to get the key code and key type.
 *  
 *  Typically,
 *    mmi_frm_set_group_key_handler(xxx_hdr, xxx_array, xxx_num, xxx_type);
 *    in xxx_hdlr
 *    void xxx_hdlr()
 *    {
 *        mmi_frm_get_key_info(&key_code, &key_type);
 *        switch(key_code)
 *        {
 *           case KEY_0:
 *               // do the thing you want
 *               break;
 *               ...
 *        }
 *    }
 *  Notes: 
 *      1. The key info is update before invoke translate key handler and key handler.
 *      2. It's safe to use it in translate key handler and key handler
 *      3. Don't use this in pre and post key handler.
 *      4. Don't use this in some timer's callback
 *      5. It's safe to use it in translate key handler and key handler.
 *      6. Don't this API to judge if the key handle is finished or no key is pressed.
 *      
 * PARAMETERS
 *  mmi_key_code     :[OUT]  The pointer to the Key Code.
 *  mmi_key_type     :[OUT]  The pointer to the Key type.       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_get_key_info(PU16 keyCode, PU16 keyType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((keyCode != NULL) && (keyType != NULL));
    *keyCode = g_key_cntx.curr_key_code;
    *keyType = g_key_cntx.curr_key_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_key_info
 * DESCRIPTION
 *  This function is used to set the key info.
 *  some applications may simulate the key process but don't use mmi_frm_exec_key_handler
 *  he may use the following case:
 *   FuncPtr key_handler = mmi_frm_get_key_handler(KEY_0, KEY_EVENT_DOWN);
 *   mmi_frm_set_key_info(KEY_0, KEY_EVENT_DOWN);
 *   if (key_handler)
 *   {
 *      key_handler();
 *   }
 *   here to set key info because the key_handler may be the group key handler it may use
 *   get key info to get corrent key code. Because it simulates key, framework doesn't know this
 *   it needs the application to set key info by himself.
 *  
 * PARAMETERS
 *  mmi_key_code     :[IN]  Key to which this event is associated         
 *  mmi_key_type     :[IN]  KEY_EVENT_UP, KEY_EVENT_DOWN, event occurs when the key 
 *                    is pressed or released      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_set_key_info(U16 keyCode, U16 keyType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_key_cntx.curr_key_code = (U8)keyCode;
    g_key_cntx.curr_key_type = (U8)keyType;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_key_handler
 * DESCRIPTION
 *  This function is used for gets the key event handler for key handler table
 *  
 *  Note:
 *    1. App may use this interface to get the key handler and then invoke the key handler
 *    2. App may use this interface to save some key handler and then to restore them
 *    3. App may use this interface to get the key handler to judge something.
 *    4. In QWERTY project, key code >= MAX_KEYES do not have key handler
 *       eg, mmi_frm_get_key_handler(KEY_A, KEY_EVENT_DOWN) will always return NULL
 * PARAMETERS
 *  mmi_key_code     :[IN]  Key to which this event is associated.       
 *  mmi_key_type     :[IN]  What key type is wanted to query.       
 * RETURNS
 *  void
 *****************************************************************************/
FuncPtr mmi_frm_get_key_handler(U16 keyCode, U16 keyType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FuncPtr ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(keyType < MAX_KEY_TYPE);
#ifndef __MMI_QWERTY_KEYPAD_SUPPORT__
    MMI_ASSERT(keyCode < MAX_KEYS);
#else
    MMI_ASSERT(keyCode < MAX_QWERTY_KEYS);
    if (keyCode >= MAX_KEYS)
	{
        /* There are no key handlers for qwerty keys, so NULL is returned */
		ptr = NULL;
	}
    else
#endif    
	{
		ptr = (currKeyFuncPtrs[keyCode][keyType]);
	}
    return ptr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_key_handler
 * DESCRIPTION
 *  This is used to sets the key event handler that corresponse to one [key_code, key_type].
 *  
 *  Notes:
 *       1. The life cycle of the key handler is within a screen. When screen switch,
 *          END/VOL_UP/VOL_DOWN will be reset to their's default key handler
 *       2. There is only one entry for a [key_code, key_type] pair, overwriten may happen.
 *          
 * PARAMETERS
 *  funcPtr     :[IN] Function to be executed on occurrence of the event.
 *  keyCode     :[IN] Key to which this event is associated.
 *  keyType     :[IN] KEY_EVENT_UP, KEY_EVENT_DOWN, event occurs when the key
 *                   is pressed or released
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_set_key_handler(FuncPtr funcPtr,U16 keyCode,U16 keyType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_KEY_SET_KEY_HDLR, keyCode, keyType, funcPtr);

    MMI_ASSERT((keyCode < MAX_KEYS) && (keyType < MAX_KEY_TYPE));

#ifndef __SENDKEY2_SUPPORT__
    currKeyFuncPtrs[keyCode][keyType] = funcPtr;
#else
	/*
	 * KEY_SEND means KEY_SEND1 and KEY_SEND2
	 * But the application could set the individual key handler in using KEY_SEND1 and KEY_SEND2
	 */
    if (keyCode == KEY_SEND1)
    {
        currKeyFuncPtrs[KEY_SEND][keyType] = funcPtr;
        currKeyFuncPtrs[KEY_SEND1][keyType] = funcPtr;
    }
    else if (keyCode == KEY_SEND2)
    {
        currKeyFuncPtrs[KEY_SEND2][keyType] = funcPtr;
    }
    else if (keyCode == KEY_SEND)
    {
        currKeyFuncPtrs[KEY_SEND][keyType] = funcPtr;
        currKeyFuncPtrs[KEY_SEND1][keyType] = funcPtr;
        currKeyFuncPtrs[KEY_SEND2][keyType] = funcPtr;
    }
    else
    {
        currKeyFuncPtrs[keyCode][keyType] = funcPtr;
    }
#endif /* __SENDKEY2_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_key_handler_ex
 * DESCRIPTION
 *  If the handset is in background call, framework will force the END/VOL_UP/VOL_DOWN
 *  's hander as background call needed. If the application wants to handle
 *  these key codes, it may use this interface to register the key handler.
 *  Example:
 *    mmi_frm_set_key_handler_ex(xxx_hdlr, KEY_END, xxx_type, MMI_FRM_APP_FULL_CONTROL);
 *  If application uses this interface like the above one, KEY_END will be full control
 *  by this application that means framework will not change the END' key handler.
 *
 * PARAMETERS
 *  funcPtr     :[IN] Function to be executed on occurrence of the event.
 *  keyCode     :[IN] Key to which this event is associated.      
 *  keyType     :[IN] KEY_EVENT_UP, KEY_EVENT_DOWN, event occurs when the key
 *                   is pressed or released
 *  flag        :[IN] flag of full control or not
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_set_key_handler_ex(FuncPtr funcPtr,U16 keyCode,U16 keyType,U16 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_full_ctrl_key(keyCode) && flag == MMI_FRM_APP_FULL_CONTROL)
    {
        /* KEY_END, KEY_VOL_UP, KEY_VOL_DOWN is supported */
        set_full_ctrl_key_state(keyCode, MMI_TRUE);
    }
    mmi_frm_set_key_handler(funcPtr, keyCode, keyType);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_group_key_handler
 * DESCRIPTION
 *  This is used to sets the same key handler for a group of keycodes.
 *  For example
 *      1. U16 keys[4] = {KEY_1, KEY_2, KEY_3, KEY_4};
 *         mmi_frm_set_group_key_handler(xxx_hdlr, keys, 4, KEY_EVENT_DOWN);
 *      2. using PresentAllKeys as the array
 *         If applications needs all keys have the same key handler, he may use
 *         mmi_frm_set_group_key_handler(xxx_hdlr, PresentAllKeys, KEY_EVENT_DOWN);
 *         It is needed to pay attention in QWERTY project, in order to make the 
 *         modification of application as little as possible when implement qwerty key pad
 *         framework cover the case if application wants to handle all keys in one key handler
 *         in qwerty project even though keys like KEY_A has not the key handler in fact.
 *         Application uses this mmi_frm_set_group_key_handler(xxx_hdlr, PresentAllKeys, KEY_EVENT_DOWN);
 *         he will receive KEY_A's down in xxx_hdlr.
 *    
 *      3. using PresentAllDialerKeys as array
 *         This is the special implementation for UCM/video call in QWERTY project.
 *         Because in QWERTY project, there is KEY_W. So the UCM/Video call needs to
 *         handle KEY_W, but the app owner don't want to use translate key handler
 *         So we implement this.
 *         app uses this interface as the following,
 *         mmi_frm_set_group_key_handler(xxx_hdlr, PresentAllDialerKeys, TOTAL_DIALER_KEYS, KEY_EVENT_DOWN);
 *         In xxx_hdlr, app should filter the key he doesn't interest Because we will give all the keys
 *         that doesn't has key handler.
 *     
 * PARAMETERS
 *  funcPtr         :[IN] Function to be executed on occurrence of the event.
 *  keyCodes        :[IN] Key array to which these events are associated.
 *  len             :[IN] The keyCodes array size.
 *  keyType         :[IN] KEY_EVENT_UP, KEY_EVENT_DOWN, event occurs when the 
 *                       key is pressed or released.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_set_group_key_handler(FuncPtr funcPtr, PU16 keyCodes, U8 len, U16 keyType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((len <= MAX_KEYS) && (keyType < MAX_KEY_TYPE));
    
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    if (keyCodes == PresentAllKeys || keyCodes == PresentAllDialerKeys)
    {
        anyKeyFuncPtrs[keyType] = funcPtr;
    }
#endif
    for (count = 0; count < len; count++)
    {
        mmi_frm_set_key_handler(funcPtr, keyCodes[count], keyType);
    }
  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_clear_key_handler
 * DESCRIPTION
 *  This function is used to set the key handler as NULL.
 * PARAMETERS
 *  keyCode     :[IN] Key to which this event is associated.
 *  keyType     :[IN] KEY_EVENT_UP, KEY_EVENT_DOWN, free the event associated
 *                   with press or released state.       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_clear_key_handler(U16 keyCode, U16 keyType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_key_handler(NULL, keyCode, keyType);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_clear_all_key_handler
 * DESCRIPTION
 *  This function is used for clears all the key handlers associated with
 *  current screen.
 *  
 * Note: 1.This API will set END/VOL_UP/VOL_DOWN to their's default key handler
 *       set all other key handler as NULL, clear any key handler and translate key handler.
 *       2.This API is always be invoked when screen switch.
 *       3.This API is different with mmi_frm_clear_key_events. invoke this events can also
 *         be received but do nothing.
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_clear_all_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_KEY_CLRALLKEY_HDLR);

    /* clear key handler */
    memset(currKeyFuncPtrs, 0, sizeof(currKeyFuncPtrs));
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__

    /* clear any key handler */
    memset(anyKeyFuncPtrs, 0, sizeof(anyKeyFuncPtrs));
#endif

    /* clear translate key handler */
    mmi_frm_clear_all_translate_key_handler();
    mmi_frm_set_translate_key_handler(MMI_FRM_TRANS_KEY_SYS, default_sys_level_trans_key_hdlr);
    mmi_frm_set_power_end_key_handler();

    SetDefaultVolumeKeyHandlers();
#ifdef __MMI_SUBLCD_MASTER_MODE__
    SetSubLCDMasterKeyHandler();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_query_mmi_key_state
 * DESCRIPTION
 *  This API is used to query mmi key state in MMI level
 *  only for dial to query mmi key state now.
 * PARAMETERS
 *  mmi_key_code :[IN] mmi key code
 * RETURNS
 *  mmi key type
 *****************************************************************************/
U8 mmi_frm_query_mmi_key_state(S16 mmi_key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U8)get_key_state(mmi_key_code);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_is_key_event
 * DESCRIPTION
 *  This function is used to judge if key handler is triggered by key or touch
 *  
 *  Notes:
 *    1. provide this API because dialer need to judge if the key handler is triggered
 *       by pen or by key. If trigger by pen, the PW+ is input by multi-tap of *
 *       If triggered by key, the PW+ is input by KEY_W/shift + W/KEY_p.
 *    2. If the key handler is not invoked by mmi_frm_exec_key_handler, please don't use 
 *       this interface.
 *       
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_frm_is_key_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return   g_key_cntx.is_key_event;  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_exec_key_handler
 * DESCRIPTION
 *  Because of history reason, applications may call this function directly to
 *  invoke current key handler.
 *  There are mainly 2 kinds of using cases.
 *    1. Call this function in Pen down and pen up handler
 *    2. press key, then in key handler entry new screen, show category and record the key code
 *       then use this key code to call this function.
 * 
 *  If you use it, pay attention that 
 *      This interface will update key info 
 *      will call translate key handler and key handler
 *  If the translate key handler and key handler are changed by someone else,
 *  applications should cover this case.
 *
 *  This interface will happen to filter some key event, for example
 *  mmi_frm_exec_key_handler(XXX_CODE, KEY_EVENT_UP);
 *  mmi_frm_exec_key_handler(XXX_CODE, KEY_REPEAT);
 *  KEY_REPEAT will be filtered. It is for MAUI_01882849
 *
 *  However: mmi_frm_exec_key_handler(XXX_CODE, KEY_EVENT_DOWN);
 *           mmi_frm_exec_key_handler(XXX_CODE, KEY_EVENT_DOWN);
 *           The second down should not be filtered for the using case 2 above.
 *
 *   
 *  If we design multiple key handler in the future, this function should be considered
 *  because in one of the multiple key handler, application may call this function,
 *  it will make the code hard to maintain.
 *
 *  It is hard to remove this interface.
 * 
 * PARAMETERS
 *  mmi_key_code    :[IN]  mmi key code such as KEY_0, KEY_1...                             
 *  mmi_key_type    :[IN]  mmi key type such as KEY_EVENT_UP, KEY_EVENT_DOWN... 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_exec_key_handler(S16 mmi_key_code, S16 mmi_key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_key_evt_struct evt;
    static MMI_BOOL is_key_down = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* 
     * For MAUI_01882849 
     * This interface is invoked directly by other module.
     * For example, some soft button is triggered by pen down, but it has the same action
     * as key down, so the soft button may call this interface directly.
     * The issue is in dialer screen, touch 0, then move out 0 than move back to 0
     * the 0 soft button has no pressed effect but can in put 0;
     * So framework help to filter some key events.
     * But these method is temp.
     */
    switch (mmi_key_type)
    {
        case KEY_EVENT_DOWN:
            is_key_down = MMI_TRUE;
            break;
        
        case KEY_LONG_PRESS:
        case KEY_REPEAT:
        {
            if (is_key_down == MMI_FALSE)
            {
                return;
            }
            break;
        }            

        case KEY_EVENT_UP:
        {
            if (is_key_down == MMI_TRUE)
            {
                is_key_down = MMI_FALSE;
            }
            else
            {
                return;
            }
            break;
        }

        default:
            break;
    }
    evt.cvt_code = mmi_key_code;
    evt.mmi_key_type = mmi_key_type;
    g_key_cntx.is_key_event = MMI_FALSE;    
    exec_key_handler(&evt);
    g_key_cntx.is_key_event = MMI_TRUE;     

}


#ifdef __MMI_SUBLCD_MASTER_MODE__
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_switch_key_func_ptr
 * DESCRIPTION
 *  This function is used for switch KeyFuncPtrs for sublcd master mode.
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_switch_key_func_ptr(void) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_sublcd_master_cntx.state == SUBLCD_MODE_S2M)
    {
        for (i = 0; i < MAX_KEYS; i++)
        {
            for (j = 0; j < MAX_KEY_TYPE; j++)
            {
                currKeyFuncPtrs_slave[i][j] = currKeyFuncPtrs[i][j];
                currKeyFuncPtrs[i][j] = currKeyFuncPtrs_master[i][j];
            }
        }
    }
    else if (g_sublcd_master_cntx.state == SUBLCD_MODE_M2S)
    {
        for (i = 0; i < MAX_KEYS; i++)
        {
            for (j = 0; j < MAX_KEY_TYPE; j++)
            {
                currKeyFuncPtrs_master[i][j] = currKeyFuncPtrs[i][j];
                currKeyFuncPtrs[i][j] = currKeyFuncPtrs_slave[i][j];
            }
        }
    }
    else
    {
        ASSERT(0);
    }
}
#endif /* __MMI_SUBLCD_MASTER_MODE__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_init_kpd_bf_pwon
 * DESCRIPTION
 *  This function is used for initializes keypad before power on.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_init_kpd_bf_pwon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_frm_key_handle_before_poweron, MSG_ID_MMI_EQ_KEYPAD_DETECT_IND);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_key_handle_before_poweron
 * DESCRIPTION
 *  This function is used for detects key presses before power on.
 * PARAMETERS
 *  paraBuff        :[IN]   The pointer to the parameter buffer.     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_key_handle_before_poweron(void *paraBuff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_keypad_detect_ind_struct *p;
    kbd_data k;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = (mmi_eq_keypad_detect_ind_struct*) paraBuff;

    while ((*(p->func)) (&k) == KAL_TRUE);

}


#ifdef __MMI_HANDWRITING_PAD__
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_convert_pen_event_to_key_event
 * DESCRIPTION
 *  This function is only used in mmi_general_pen_handler in touchscreen.c.
 * PARAMETERS
 *  is_enable       :[IN]   Is enable high frequency mode or not.      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_convert_pen_event_to_key_event(S16 mmi_key_type, U8 device_key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_key_evt_struct evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    evt.mmi_key_code= get_mmi_key_code(device_key_code);
    evt.mmi_key_type = mmi_key_type;
    evt.is_clear = MMI_FALSE;
    if (exec_dynamic_pre_key_handler(&evt) == MMI_TRUE)
    {
        update_clear_state(&evt);
        if (evt.is_clear == MMI_FALSE)
        {
            MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_KEY_KEY_EVENT_INFO, evt.cvt_code, evt.mmi_key_type);
            exec_key_handler(&evt);
        }else
        {
            MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_KEY_DISABLE_KEY_ACTION_BY_PRE_KEY_HDLR, evt.cvt_code, evt.mmi_key_type);
        }
    }
    else
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_KEY_DISABLE_KEY_ACTION_BY_PRE_KEY_HDLR, evt.cvt_code, evt.mmi_key_type);
    }

}
#endif /* __MMI_HANDWRITING_PAD__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_process_key_in_nvarm
 * DESCRIPTION
 *  This function is used to process key message in NVRAM procedure
 * PARAMETERS
 *  paraBuff        :[IN]  The pointer to the parameter buffer.        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_process_key_in_nvarm(void * para_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (para_buff != NULL)
    {
        PsFuncPtr func;
        mmi_frm_get_protocol_event_handler(MSG_ID_MMI_EQ_KEYPAD_DETECT_IND, &func);
        if (func == mmi_frm_key_handle_before_poweron)
        {
            mmi_frm_key_handle_before_poweron(para_buff);
        }
        else
        {
            process_key_ptr_change(para_buff);
            g_keypad_flag = MMI_TRUE;
            SetBit(g_input_msg_in_queue, MMI_DEVICE_KEY); 
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_key_handle
 * DESCRIPTION
 *  This function is used for process the keypad handler.
 * PARAMETERS
 *  paraBuff        :[IN]  The pointer to the parameter buffer.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_key_handle(void *paraBuff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 msg_count;
    dev_key_evt_struct dev_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_KEY_HANDLE_BEGIN);
    process_key_ptr_change(paraBuff);
    while (1)
    {
        if ((IsBitReset(g_key_cntx.keypad_status, KPD_SUSPEND_FLAG)) &&
            (get_dev_key_evt(&dev_evt) == MMI_TRUE))
        {
            dev_key_handle(&dev_evt);

            /* Invoke post event */
            mmi_frm_invoke_post_event();

            msg_get_ext_queue_info(mmi_ext_qid, &msg_count);
            if (msg_count > 0 || OslNumOfCircularQMsgs() > 0)
            {
                g_keypad_flag = MMI_TRUE;
                SetBit(g_input_msg_in_queue, MMI_DEVICE_KEY);
                break;
            }
        }
        else
        {
            if (IsBitSet(g_key_cntx.keypad_status, KPD_SUSPEND_FLAG))
            {
                MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_KEY_HANDLE_SUSPEND);
            }
            g_keypad_flag = MMI_FALSE;
            ResetBit(g_input_msg_in_queue, MMI_DEVICE_KEY);
            break;
        }
    }   /* while(1) */
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_KEY_HANDLE_END);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_suspend_handle_key_process
 * DESCRIPTION
 *  This function is used to suspend key process.
 * PARAMETERS
 *  enable     :[IN] MMI_TRUE enable, MMI_FALSE disable
 *
 * RETURNS
 *  Always return MMI_TRUE now 
 *****************************************************************************/
MMI_BOOL mmi_frm_suspend_handle_key_process(MMI_BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (enable == MMI_TRUE)
    {
        SetBit(g_key_cntx.keypad_status, KPD_SUSPEND_FLAG);
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_KEY_SUSPEND_KEY_FLOW);
    }
    else
    {
        MYQUEUE Message;
        ResetBit(g_key_cntx.keypad_status, KPD_SUSPEND_FLAG);
        Message.oslMsgId = MSG_ID_MMI_EQ_KEYPAD_DETECT_IND;
        Message.oslDataPtr = (oslParaType*)NULL;
        Message.oslPeerBuffPtr = NULL;
        Message.oslSrcId = MOD_MMI;
        Message.oslDestId = MOD_MMI;
        OslMsgSendExtQueue(&Message);
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_KEY_RESUME_KEY_FLOW);
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_key_event_count
 * DESCRIPTION
 *  This function is used to get the pending key events' number
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  pending key events number
 *****************************************************************************/
U32 mmi_frm_get_key_event_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return Kbd_GetKeyEventCount();    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_clear_key_events
 * DESCRIPTION
 *  This function is used to clear key events buffer including look ahead buffer and
 *  driver's buffer
 *   
 *  1. If END Key's DOWN/LONGPRESS/UP is received in this API, we will make sure 1
 *     END key's DOWN/LONGPRESS/UP is written back to look ahead buffer make sure the handset 
 *     can be shut down properly.
 *  2. When mmi_frm_clear_key_events is invoked, all keys that is in pressing is changed to 
 *     clear state.
 *     That means
 *         Example, Invoking this API in KEY1's DOWN handler we will not send KEY1's long press repeat and KEY1' UP.
 *         Even though KEY1's UP is not in the keyboard buffer now. We will drop it when it is received in
 *         future.
 *  3. If application use this interface in KEY down' handler, it will not receive this key's up. 
 *  4. Framework will not invoke this interface when screen switch because the delay action effect of key needed by
 *     BD team.
 *
 *   [UT_function]: ut_mmi_frm_clear_key_events
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_clear_key_events(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dev_key_evt_struct dev_evt;
    dev_key_evt_struct temp[LOOK_AHEAD_BUF_LEN];
    U8 len = 0;
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_KEY_CLEAR_KEY_EVENTS_BEGIN);
    set_all_key_data_clear();
    while (get_dev_key_evt(&dev_evt) == MMI_TRUE)
    {
        if (is_need_write_back(&dev_evt, temp, len) == MMI_TRUE)
        {
            MMI_ASSERT(len < LOOK_AHEAD_BUF_LEN);
            temp[len] = dev_evt;
            len++;
        }  
    };
    for (i = 0; i < len; i++)
    {
        write_look_ahead_buffer(&temp[i]);
    }
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_KEY_CLEAR_KEY_EVENTS_END);
}





/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_dev_key_code
 * DESCRIPTION
 *  This function is used for reversly get the driver key code.
 * PARAMETERS
 *  mmi_key_code        :[IN]        Key code of MMI
 * RETURNS
 *  driver key code
 *****************************************************************************/
S16 mmi_frm_get_dev_key_code(S16 mmi_key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_QWERTY_KEYPAD_SUPPORT__

    /* check mmi key code */
    MMI_ASSERT((mmi_key_code >= 0) && (mmi_key_code < MAX_KEYS));
    
    if (mmi_key_code == KEY_CSK)
    {
        /* no device key is mapped to CSK */
        ret = DEVICE_KEY_NONE;
    }
    else
    {
        U8 device_key_code;

        /* get device key code from mapping table */
        device_key_code = get_device_key_code((U8)mmi_key_code);
        
        ret = (kbd_IsKeyButtonSupported(device_key_code)) ? device_key_code : DEVICE_KEY_NONE;
    }
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_KEY_REVERSE_CODE, mmi_key_code, ret);
    return ret;
#else /* __MMI_QWERTY_KEYPAD_SUPPORT__ */
    /* check mmi key code */
    MMI_ASSERT((mmi_key_code >= 0) && (mmi_key_code < MAX_QWERTY_KEYS));
    if (mmi_key_code == KEY_CSK)
    {
        /* no device key is mapped to CSK */
        return DEVICE_KEY_NONE;
    }
    else
    {
        S16 opposite_mmi_key_code;
        U8 device_key_code1;
        U8 device_key_code2;
        kal_bool ret1;
        kal_bool ret2;
        /* 
         * 1 driver key code may mapped to 2 mmi key code in qwerty project.
         * eg. DEVICE_KEY_E  => KEY_E & KEY_1, or DEVICE_KEY_1 => KEY_E & KEY_1
         * in this case if mmi_key_code = KEY_E, the opposite_mmi_key_code = KEY_1
         * if mmi_key_code = KEY_1, the opposite_mmi_key_code = KEY_E
         *
         * However, in key mapping table, DEVICE_KEY_E => KEY_E, DEVICE_KEY_1 => KEY_1
         * Whether KEY_E is supported or not is determinded by either DEVICE_KEY_E or DEVICE_KEY_1
         * is supported. Pay attention: they cannot be both valid, if this happen, Please check 
         * key layout in keypad_def.c
         */
        opposite_mmi_key_code = mmi_frm_qwerty_get_opposite_key_code(mmi_key_code);

        if (opposite_mmi_key_code == mmi_key_code) /* not 0~ 9 *# key */
        {
            device_key_code1 = get_device_key_code((U8)mmi_key_code);
            ret =  (kbd_IsKeyButtonSupported(device_key_code1)) ? device_key_code1 : DEVICE_KEY_NONE;
        }
        else /* may 0~ 9 * # key */
        {
            device_key_code1 = get_device_key_code((U8)mmi_key_code);
            device_key_code2 = get_device_key_code((U8)opposite_mmi_key_code);
            ret1 = kbd_IsKeyButtonSupported(device_key_code1);
            ret2 = kbd_IsKeyButtonSupported(device_key_code2);
            MMI_ASSERT((ret1 && !ret2) || (!ret1 && ret2));
            ret =  ret1 ? device_key_code1 : device_key_code2; 
        }         
    }
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_KEY_REVERSE_CODE, mmi_key_code, ret);
    return ret;
#endif /* __MMI_QWERTY_KEYPAD_SUPPORT__ */  
}


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + pre and post key handler related API
 +      1. mmi_frm_kbd_get_pre_key_hdlr
 +      2. mmi_frm_kbd_reg_pre_key_hdlr
 +      3. mmi_frm_kbd_reg_post_key_hdlr
 +      4. mmi_frm_kbd_reg_post_key_hdlr
 +  
 +   TODO: know application how to use pre key handler and post key handler
 +         the limitation to use pre and post key handler
 +
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_kbd_get_pre_key_hdlr
 * DESCRIPTION
 *  This function is used for get framework pre-key handler
 *  keypad handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  PsKeyProcessCBPtr
 *****************************************************************************/
PsKeyProcessCBPtr mmi_frm_kbd_get_pre_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_key_cntx.kbd_pre_func;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_kbd_reg_pre_key_hdlr
 * DESCRIPTION
 *  This function is used for regiester function to execute before general 
 *  keypad handler.
 * PARAMETERS
 *  func        :[IN]  Pre-Key handler      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_kbd_reg_pre_key_hdlr(PsKeyProcessCBPtr func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_key_cntx.kbd_pre_func = func;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_kbd_reg_post_key_hdlr
 * DESCRIPTION
 *  This function is used for register function to execute after general 
 *  keypad handler.
 * PARAMETERS
 *  func        :[IN]  Post-Key handler     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_kbd_reg_post_key_hdlr(PsKeyProcessCBPtr func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_key_cntx.kbd_post_func = func;
}


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + Keypad mode related API
 +      1. mmi_frm_set_keypad_mode
 +      2. mmi_frm_get_keypad_mode
 +
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_keypad_mode
 * DESCRIPTION
 *  This function is used to set keypad mode
 * PARAMETERS
 *  mode        :[IN]   see mmi_frm_keypad_mode_enum
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_set_keypad_mode(U8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kbd_key_det_mode det_mode = kbd_1_key_det_mode;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    switch(mode)
    {
        case KEYPAD_1KEY_NUMBER:
            {
            #ifndef __MMI_QWERTY_KEYPAD_SUPPORT__
                det_mode = kbd_1_key_det_mode;
            #else
                det_mode = kbd_2_keys_det_mode;
                mmi_frm_qwerty_set_keypad_mode(MMI_FRM_QWERTY_MODE_NUMBER);
            #endif
            }
            break;
            
        case KEYPAD_2KEY_NUMBER:
            {
                det_mode = kbd_2_keys_det_mode;
            #ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
                mmi_frm_qwerty_set_keypad_mode(MMI_FRM_QWERTY_MODE_NUMBER);
            #endif
            }
            break;
            
        case KEYPAD_3KEY_NUMBER:
            {
                det_mode = kbd_3_keys_det_mode;
            #ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
                mmi_frm_qwerty_set_keypad_mode(MMI_FRM_QWERTY_MODE_NUMBER);
            #endif
            }
            break;
            
        case KEYPAD_1KEY_QWERTY:
            {
                det_mode = kbd_2_keys_det_mode;
            #ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
                mmi_frm_qwerty_set_keypad_mode(MMI_FRM_QWERTY_MODE_STANDARD);
            #endif
            }
            break;
            
        case KEYPAD_2KEY_QWERTY:
            {
                det_mode = kbd_2_keys_det_mode;
            #ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
                mmi_frm_qwerty_set_keypad_mode(MMI_FRM_QWERTY_MODE_STANDARD);
            #endif
            }
            break;
            
        case KEYPAD_3KEY_QWERTY:
            {
                det_mode = kbd_3_keys_det_mode;
            #ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
                mmi_frm_qwerty_set_keypad_mode(MMI_FRM_QWERTY_MODE_STANDARD);
            #endif
            }
            break;
            
        default:
            MMI_ASSERT(0);
            break;
    }
    
    /* updated keypad mode */
    SET_KPD_MODE(g_key_cntx.keypad_status, mode);
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_KEY_KEYPAD_MODE, mode);
    /* updated key detection mode of driver */

#ifdef __MTK_TARGET__
    if(kbd_key_det_mode_switch(det_mode))
    {

    }
#else
    SET_KEY_DET_MODE(g_key_cntx.keypad_status, det_mode);
    if (w32_key_det_mode_switch((U8)(det_mode + 1)))
    {
        
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_keypad_mode
 * DESCRIPTION
 *  This function is used to get keypad mode
 * PARAMETERS
 *  mode        :[IN]   see mmi_frm_keypad_mode_enum
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_frm_get_keypad_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return GET_KPD_MODE(g_key_cntx.keypad_status);
}


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + Set Power Key and End key Handler
 +      1. mmi_frm_set_default_power_onoff_key
 +      2. mmi_frm_set_power_end_key_handler
 +
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_default_power_onoff_key
 * DESCRIPTION
 *  This function is used for set power on/off key to default handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_set_default_power_onoff_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   

    if (mmi_frm_kbd_is_key_supported(KEY_POWER) == MMI_TRUE)
    {
        mmi_frm_set_key_handler(NULL, KEY_END, KEY_LONG_PRESS);
        mmi_frm_set_key_handler(ShutdownSystemOperation, KEY_POWER, KEY_LONG_PRESS);
    }
    else
    {
        mmi_frm_set_key_handler(ShutdownSystemOperation, KEY_END, KEY_LONG_PRESS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_power_end_key_handler
 * DESCRIPTION
 *  This function is used for sets power key & end key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_set_power_end_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FuncPtr end_key_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /*
    * The end key must not be registered to
    * Go to IDle screen in case any call exists on the phone.
    */
    if (IS_IN_CALL())
    {
        set_end_key_handler_in_call();
    }
    else
    {
    #ifdef __MMI_DUAL_SIM_MASTER__
        if (mmi_bootup_is_in_security_check() == MMI_FALSE && mmi_bootup_is_in_sim2_security_check() == MMI_FALSE)
    #else
        if (mmi_bootup_is_in_security_check() == MMI_FALSE)
    #endif
        {
            /**
            * The end key should end all the existing calls
            *  and screen should be the last screen thru call menu.
            */
        #ifdef __MMI_EMAIL__
            if (mmi_email_util_get_stop_cause() == EMAIL_MODULE_ACTIVE_NOW)
            {
                end_key_ptr = mmi_email_main_goto_idle;
            }
            else
        #endif /* __MMI_EMAIL__ */ 
        #ifdef __MMI_DUAL_SIM_MASTER__
            if (!gSecuritySetupContext.PINBlocked && !gSecuritySetupContext.PINBlocked_2)
        #else
            if (!gSecuritySetupContext.PINBlocked)
        #endif /* __MMI_DUAL_SIM_MASTER__ */
            {
                end_key_ptr = DisplayIdleScreen;
            }
        #ifdef __MMI_DUAL_SIM_MASTER__
            else if (gSecuritySetupContext.PINBlocked && !gSecuritySetupContext.PINBlocked_2)
            {
                end_key_ptr = mmi_secset_goto_puk1;
            }
            else if (!gSecuritySetupContext.PINBlocked && gSecuritySetupContext.PINBlocked_2)
            {
                end_key_ptr = mmi_secset_goto_sim2_puk1;
            }
        #else /* __MMI_DUAL_SIM_MASTER__ */
            else
            {
                end_key_ptr = mmi_secset_goto_puk1;
            }
        #endif /* __MMI_DUAL_SIM_MASTER__ */
        }
        else if (mmi_bootup_is_in_security_check() == MMI_TRUE)
        {
            if (!gSecuritySetupContext.PINBlocked)
            {
                end_key_ptr = mmi_secset_goto_pin1;
            }
            else
            {
                end_key_ptr = mmi_secset_goto_puk1;
            }
        }    
    #ifdef __MMI_DUAL_SIM_MASTER__
        else if (mmi_bootup_is_in_security_check() == MMI_FALSE && mmi_bootup_is_in_sim2_security_check() == MMI_TRUE)
        {
            if (!gSecuritySetupContext.PINBlocked_2)
            {
                end_key_ptr = mmi_secset_goto_sim2_pin1;
            }
            else
            {
                end_key_ptr = mmi_secset_goto_sim2_puk1;
            }
        }
    #endif /* __MMI_DUAL_SIM_MASTER__ */
    }

#if defined(__DIRECT_ENTRY_FACTORY_MODE_ON_BOOTUP__)
    if (DirectMode)
    {
        end_key_ptr = CallBackPowerOnAnimationCompleteWrapper;
    }
#endif /* defined(__DIRECT_ENTRY_FACTORY_MODE_ON_BOOTUP__) */ 

    if (end_key_ptr != NULL)
    {
        mmi_frm_set_key_handler(end_key_ptr, KEY_END, KEY_EVENT_DOWN);
    }
    if (!g_keylock_context.gKeyPadLockFlag)
    {
        mmi_frm_set_default_power_onoff_key();
    }
}


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + key tone related function
 +    1. mmi_frm_set_default_num_key_tone_mode(External API)
 +    2. mmi_frm_kbd_is_tone_enabled(E)
 +    3. mmi_frm_key_tone_hdlr
 +    4. mmi_frm_play_keypad_tone
 +    5. mmi_frm_stop_keypad_tone
 +    6. mmi_frm_kbd_set_tone_state
 +    7. mmi_frm_kbd_get_key_tone_state(void)
 +    8. get_human_voice_key_tone_id
 +    9. get_cust_key_tone_id
 +    10.get_key_tone
 +    11.mmi_frm_get_curr_key_tone
 +    12.mmi_frm_set_curr_key_tone
 +    13.mmi_frm_key_tone_duration
 +    14.mmi_frm_stop_curr_key_tone 
 +
 +   There are tow many key tone functions here, but we don't know it well.
 +   TODO: revise key tone functions
 +
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_default_num_key_tone_mode
 * DESCRIPTION
 *  This function is used to set num key (0~9 *#) tone mode.
 *  In non-qwerty project, DTMF mode is default mode for 0~9 *#.So application
 *  do not need to call this interface to change the number key tone mode
 *  In qwerty project, Normal mode is default mode for 0~9 *#. So the application which
 *  is related dial a phone number, who should use this interface to set the num key tone
 *  mode as DTMF mode.
 *  
 * PARAMETERS
 *  mode      :[IN]   DTMF tone or Normal tone from enum(mmi_frm_num_tone_mode_enum)
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * 
 * </code>
 *****************************************************************************/
void mmi_frm_set_default_num_key_tone_mode(mmi_frm_num_key_tone_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(mode)
    {
        case MMI_FRM_NUM_KEY_TONE_DTMF:
            ResetBit(g_key_cntx.keypad_status, KPD_NUM_KEY_TONE_MOD_FLAG);
            break;
        case MMI_FRM_NUM_KEY_TONE_NORMAL:
            SetBit(g_key_cntx.keypad_status, KPD_NUM_KEY_TONE_MOD_FLAG);
            break;
        default:
            MMI_ASSERT(0);
            break;
    }
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_KEY_TONE_MODE, mode);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_kbd_is_tone_enabled
 * DESCRIPTION
 *  This function is used for checks if keypad tone can be played or not.
 * PARAMETERS
 *  key_code        :[IN]   Key to which this event is associated.
 *  key_type        :[IN]   KEY_EVENT_UP, KEY_EVENT_DOWN, event occurs when the 
 *                         key is pressed or released.
 * RETURNS
 *  TRUE if the keypad tone shall be played by framework; otherwise, FALSE.
 *****************************************************************************/
MMI_BOOL mmi_frm_kbd_is_tone_enabled(S16 key_code, S16 key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tone_type = GetKeypadToneType();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tone_type == KEYPAD_SILENT  /* silent profile */
        || g_key_cntx.key_tone_state == MMI_KEY_TONE_DISABLED)
    {
        return MMI_FALSE;
    }
    else if (g_key_cntx.key_tone_state == MMI_KEY_VOL_TONE_DISABLED)
    {
        /* disable volume keypad tone */
        if (key_code == KEY_VOL_UP || key_code == KEY_VOL_DOWN)
        {
            return MMI_FALSE;
        }
    }
    else if (g_key_cntx.key_tone_state == MMI_KEY_VOL_UP_DOWN_TONE_DISABLED)
    {
        /* disable volume keypad tone */
        if (key_code == KEY_VOL_UP || key_code == KEY_VOL_DOWN || 
            key_code == KEY_UP_ARROW || key_code == KEY_DOWN_ARROW)
        {
            return MMI_FALSE;
        }
    }
    else if (g_key_cntx.key_tone_state == MMI_KEY_RIGHT_LEFT_ARROW_TONE_DISABLED)
    {
        if (key_code == KEY_RIGHT_ARROW || key_code == KEY_LEFT_ARROW)
        {
            return MMI_FALSE;
        }
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_key_tone_hdlr
 * DESCRIPTION
 *  This function is used to play & stop key tone
 * PARAMETERS
 *  eventKey        :[IN]  The Key event.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_key_tone_hdlr(KEYBRD_MESSAGE *eventKey)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (eventKey->nKeyCode >= MAX_KEY_NUM)
    {
        return;
    }

    /* Play key tone when key down */
    if (eventKey->nMsgType == KEY_EVENT_DOWN)
    {
        if (mmi_frm_kbd_is_tone_enabled(eventKey->nKeyCode, eventKey->nMsgType))
        {
            mmi_frm_play_keypad_tone(eventKey->nKeyCode);
            MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_KEY_PLAY_KEY_TONE, eventKey->nKeyCode);
        }
    }
    /* Stop key tone when key up */
    else if (eventKey->nMsgType == KEY_EVENT_UP)
    {
        mmi_frm_stop_keypad_tone(eventKey->nKeyCode);
        MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_KEY_STOP_KEY_TONE, eventKey->nKeyCode);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_play_keypad_tone
 * DESCRIPTION
 *  This function is used for plays corresponding keypad tone.
 * PARAMETERS
 *  key_code        :[IN]     Key to which this event is associated.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_play_keypad_tone(S16 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tone_type = GetKeypadToneType();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tone_type == KEYPAD_CLICK)
    {
        AudioPlayReq(TONE_KEY_CLICK, DEVICE_AUDIO_PLAY_ONCE);
    }
    else
    {
        mmi_frm_set_curr_key_tone(get_key_tone(key_code));
        g_key_cntx.key_tone_id = mmi_frm_get_curr_key_tone();
        g_key_cntx.key_tone_duration = mmi_frm_key_tone_duration(key_code);
        AudioPlayReq(g_key_cntx.key_tone_id, g_key_cntx.key_tone_duration);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_stop_keypad_tone
 * DESCRIPTION
 *  This function is used for stops corresponding keypad tone.
 * PARAMETERS
 *  key_code        :[IN]        Key code
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_stop_keypad_tone(S16 key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tone_type = GetKeypadToneType();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tone_type == KEYPAD_TONE)
    {
        mmi_frm_set_curr_key_tone(0xFFFF);
        if (g_key_cntx.key_tone_duration == DEVICE_AUDIO_PLAY_INFINITE)
        {
            AudioStopReq(g_key_cntx.key_tone_id);
        }
    }
#if defined(__MMI_CUST_KEYPAD_TONE__)
    else if (tone_type >= KEYPAD_TONE_CUST_1 
        && tone_type <= KEYPAD_TONE_CUST_6
#if defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__)
        && g_key_cntx.key_tone_id < MIN_HUMAN_VOICE_ID)    /* MIN_KEYPAD_TONE_ID > MIN_HUMAN_VOICE_ID */
#else 
        && g_key_cntx.key_tone_id < MIN_KEYPAD_TONE_ID)
#endif 
    {
        mmi_frm_set_curr_key_tone(0xFFFF);
        if (g_key_cntx.key_tone_duration == DEVICE_AUDIO_PLAY_INFINITE)
        {
            AudioStopReq(g_key_cntx.key_tone_id);
        }
    }
#endif /* defined(__MMI_CUST_KEYPAD_TONE__) */ 

#if defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__)
    else if (tone_type >= KEYPAD_TONE_HUMAN_VOICE_1 
        && tone_type <= KEYPAD_TONE_HUMAN_VOICE_6 
        && g_key_cntx.key_tone_id < MIN_HUMAN_VOICE_ID)       
    {
        mmi_frm_set_curr_key_tone(0xFFFF);
        if (g_key_cntx.key_tone_duration == DEVICE_AUDIO_PLAY_INFINITE)
        {
            AudioStopReq(g_key_cntx.key_tone_id);
        }
    }
#endif /* defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_kbd_set_tone_state
 * DESCRIPTION
 *  This function is used for chages the state of keypad tone.
 *
 * PARAMETERS
 *  state       :[IN]  Keypad tone state that want to be changed      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_kbd_set_tone_state(mmi_frm_kbd_tone_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_key_cntx.key_tone_state = state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_kbd_get_key_tone_state
 * DESCRIPTION
 *  This function is used for gets the state to see if keypad tone is disabled.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return the key pad tone state. Refer mmi_frm_kbd_tone_state_enum.
 *****************************************************************************/
mmi_frm_kbd_tone_state_enum mmi_frm_kbd_get_key_tone_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_key_cntx.key_tone_state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_curr_key_tone
 * DESCRIPTION
 *  This function is used for queries the current keypad tone.
 * PARAMETERS
 *  void
 * RETURNS
 *  Returns the keypad tone enum. Refer audio_id_enum.
 *****************************************************************************/
U16 mmi_frm_get_curr_key_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_key_cntx.curr_keypad_tone;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_curr_key_tone
 * DESCRIPTION
 *  This function is used for sets the current keypad tone.
 * PARAMETERS
 *  KeyTone     :[IN]  the keypad tone enum. Refer audio_id_enum.      
 * RETURNS
 *  Always returns MMI_TURE.  
 *****************************************************************************/
U8 mmi_frm_set_curr_key_tone(U16 KeyTone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_key_cntx.curr_keypad_tone = KeyTone;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_key_tone_duration
 * DESCRIPTION
 *  This function is used for queries the current keypad duration.
 * PARAMETERS
 *  MMIKeyCode      :[IN]    Key code of MMI    
 * RETURNS
 *  The current keypad duration.
 *****************************************************************************/
static U8 mmi_frm_key_tone_duration(S16 mmi_key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_CUST_KEYPAD_TONE__) || defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__)
    U16 i;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_CUST_KEYPAD_TONE__)
    if (get_cust_key_tone_id(mmi_key_code) >= 0)
    {
        return DEVICE_AUDIO_PLAY_ONCE;
    }
#endif /* defined(__MMI_CUST_KEYPAD_TONE__) */ 

#if defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__)
    /* MTK added by Tim for human voice keypad tone */
    if (get_human_voice_key_tone_id(mmi_key_code) >= 0)
    {
        return DEVICE_AUDIO_PLAY_ONCE;
    }
#endif /* defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__) */ 

    /* num key (0~9 *#) in DTMF mode has special key tone duration */
    if (get_default_num_tone_mode() == MMI_FRM_NUM_KEY_TONE_DTMF)
    {
        if ((mmi_key_code <= KEY_9) || (mmi_key_code == KEY_STAR) || (mmi_key_code == KEY_POUND))
        {
            return (U8)DEVICE_AUDIO_PLAY_INFINITE;
        }
    }
    return (U8)DEVICE_AUDIO_PLAY_ONCE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_stop_curr_key_tone
 * DESCRIPTION
 *  This function is used for stops current keypad tone.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_stop_curr_key_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_key_cntx.curr_keypad_tone!= 0xFFFF)
    {
        AudioStopReq(g_key_cntx.curr_keypad_tone);
        g_key_cntx.curr_keypad_tone = 0xFFFF;
    }
}


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 +   Misc.
 +      1.mmi_frm_get_present_all_key_num
 +      2.mmi_frm_get_all_dial_key_num
 +     
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_present_all_key_num
 * DESCRIPTION
 *  This function is used to get the elment number of PresentAllKeys
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_frm_get_present_all_key_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return sizeof(PresentAllKeys)/sizeof(PresentAllKeys[0]);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_present_all_key_num
 * DESCRIPTION
 *  This function is used to get the element number of PresentAllDialerKeys
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_frm_get_all_dial_key_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return sizeof(PresentAllDialerKeys)/sizeof(PresentAllDialerKeys[0]);
}


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + Internal function of key event handler
 +
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + The following function is key handler registered in keybrd.c not belong to key handle mechanism
 +      1. mmi_secset_goto_puk1(key handler)
 +      2. mmi_secset_goto_sim2_pin1(key handler)
 +      3. mmi_secset_goto_sim2_puk1(key handler)
 +      4. set_end_key_handler_in_call(set key handler)
 +
 +    Remark: do not know the 1.2.3 's concrete function.
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*****************************************************************************
 * FUNCTION
 *  mmi_secset_goto_pin1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_secset_goto_pin1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackToHistory(SCR_ENTER_PIN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_secset_goto_puk1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_secset_goto_puk1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_ID_SECSET_PUK_CONFIRM_PIN1))
    {
        DeleteUptoScrID(SCR_ID_SECSET_PUK_CONFIRM_PIN1);
    }
    else if (IsScreenPresent(SCR_ID_SECSET_PUK_NEW_PIN1))
    {
        DeleteUptoScrID(SCR_ID_SECSET_PUK_NEW_PIN1);
    }
    else
    {
        DeleteUptoScrID(SCR_ID_SECSET_PUK1);
    }
    GoBackHistory();
}


#ifdef __MMI_DUAL_SIM_MASTER__
/*****************************************************************************
 * FUNCTION
 *  mmi_secset_goto_sim2_pin1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_secset_goto_sim2_pin1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeleteUptoScrID(SCR_ENTERSLAVEPIN);
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_secset_goto_sim2_puk1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_secset_goto_sim2_puk1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_CARD2_ENTER_CONFIRM_PIN))
    {
        DeleteUptoScrID(SCR_CARD2_ENTER_CONFIRM_PIN);
    }
    else if (IsScreenPresent(SCR_CARD2_ENTER_NEW_PIN))
    {
        DeleteUptoScrID(SCR_CARD2_ENTER_NEW_PIN);
    }
    else
    {
        DeleteUptoScrID(SCR_CARD2_ENTER_PUK);
    }
    GoBackHistory();
}
#endif /* __MMI_DUAL_SIM_MASTER__ */


/*****************************************************************************
 * FUNCTION
 *  set_end_key_handler_in_call
 * DESCRIPTION
 *  This function is used for executes current key function handler only. 
 *  This function won't execute pre key handler and post key handler.
 * PARAMETERS
 *  keyCode     :[IN]    Key to which this event is associated.     
 *  keyType     :[IN]    KEY_EVENT_UP, KEY_EVENT_DOWN, event occurs when the 
 *                      key is pressed or released.      
 * RETURNS
 *  void
 *****************************************************************************/
static void set_end_key_handler_in_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IS_IN_CALL())
    {
        SetKeyHandler(mmi_ucm_end_key, KEY_END, KEY_EVENT_DOWN);
    }
}


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + Static pre handler and post key handler.
 *   static pre key handler and post key handler will be always invoked before and after key handler
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + Misc
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*****************************************************************************
 * FUNCTION
 *  default_sys_level_trans_key_hdlr
 * DESCRIPTION
 *  This function is default sys level translate key handler
 *  we will set the sys level translate key handler as the default one
 *  when key pad init, and when screen switch
 *
 * PARAMETERS
 *  mmi_key_code       :[IN]   mmi key code      
 *  mmi_key_type       :[IN]   mmi key type
 *  ucs2_value         :[IN]   ucs2 value
 *  special_key_flag   :[IN]   special key flag
 *
 * RETURNS
 *  MMI_TRUE  - stop key routing
 *  MMI_FALSE - continue key routing
 * EXAMPLE
 * <code>
 *
 * </code>
 *****************************************************************************/
static MMI_BOOL default_sys_level_trans_key_hdlr(S16 mmi_key_code, S16 mmi_key_type, U16 ucs2_value, U32 special_key_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FuncPtr func_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IS_IN_CALL() && !is_full_ctrled(mmi_key_code))
    {
        if (mmi_key_code == KEY_END && mmi_key_type == KEY_EVENT_DOWN)
        {
            set_end_key_handler_in_call();
            func_ptr = currKeyFuncPtrs[KEY_END][KEY_EVENT_DOWN];
            MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_KEY_EXECUTE_KEY_HANDLER, mmi_key_code, mmi_key_type, func_ptr);
            if (func_ptr)
            {
                (* func_ptr)();
            }
            return MMI_TRUE;
        }
        else if ((mmi_key_code == KEY_VOL_UP || mmi_key_code == KEY_VOL_DOWN) &&
            (mmi_key_type == KEY_EVENT_DOWN || mmi_key_type == KEY_LONG_PRESS || mmi_key_type == KEY_REPEAT))
        {
            SetDefaultVolumeKeyHandlers();
            func_ptr = currKeyFuncPtrs[mmi_key_code][mmi_key_type];
            MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_KEY_EXECUTE_KEY_HANDLER, mmi_key_code, mmi_key_type, func_ptr);
            if (func_ptr)
            {
                (* func_ptr)();
            }
            return MMI_TRUE;
        }

        if (mmi_key_code == KEY_END && mmi_key_type == KEY_EVENT_DOWN)
        {
            MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_KEY_END_FULL_CTRL_BY_APP);
        }
        if ((mmi_key_code == KEY_VOL_UP || mmi_key_code == KEY_VOL_DOWN) &&
            (mmi_key_type == KEY_EVENT_DOWN || mmi_key_type == KEY_LONG_PRESS || mmi_key_type == KEY_REPEAT))
        {
            MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_KEY_VOL_FULL_CTRL_BY_APP);
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  process_key_ptr_change
 * DESCRIPTION
 *  Process the action of changing key function pointer.
 *  Make sure the final processed key event is event up for each key func pointer, 
 *  otherwise we clear all key events in the buffer belong to new key func pointer.
 * PARAMETERS
 *  paraBuff        :[IN]  The pointer to the parameter buffer.        
 * RETURNS
 *  void
 *****************************************************************************/
static void process_key_ptr_change(void * para_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_keypad_detect_ind_struct *p = (mmi_eq_keypad_detect_ind_struct*) para_buff;
    kbd_data k;        
    drv_get_key_func new_key_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (p != NULL)
    {
        new_key_ptr = (drv_get_key_func) (p->func);
		MMI_ASSERT(new_key_ptr != NULL);
    #ifndef __MMI_FRM_KEY_EVENT_UT__
        MMI_ASSERT(new_key_ptr == KBD_ATCMD_GET_KEY_FUNC || new_key_ptr == KBD_DRVIER_GET_KEY_FUNC);
    #endif

        if (g_key_cntx.keypad_ptr != new_key_ptr)
        {/* g_key_cntx.keypad_ptr == NULL or g_key_cntx.keypad_ptr != new_key_ptr */
            if (g_key_cntx.buf_len !=0 )
            {/* 
              * Make sure the key data buffer is empty, 
              * otherwise we clear all key events in the buffer belong to new key func pointer.
              */
                while(((drv_get_key_func)new_key_ptr)(&k) == MMI_TRUE);
            }
            else
            {/* g_key_cntx.keypad_ptr == NULL or processed final key event is event up. */
                
                /* clear the previous key buffer, make sure it can send primitive to replace the new one */
                if (g_key_cntx.keypad_ptr != NULL)
                {
                    while(((drv_get_key_func)g_key_cntx.keypad_ptr)(&k) == MMI_TRUE);
                }                
    		    g_key_cntx.keypad_ptr = new_key_ptr;
                MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_KEY_PTR_CHANGE_SUCCESS, new_key_ptr == KBD_ATCMD_GET_KEY_FUNC);  		    
    		}
		}
    }
}

/*****************************************************************************
 * FUNCTION
 *  is_combo_key
 * DESCRIPTION
 *  This function is used to judge the mmi key code is combo key or not,
 *  like SHIFT FN..., The combo key means for example shift + A.
 *  Pay attention that there is no combo key in non-qwerty project.
 * 
 * PARAMETERS
 *  mmi_key_code  :[IN] mmi_key_code
 * RETURNS
 *  MMI_TRUE if combo key like SHIFT or not combo key
 *****************************************************************************/
static MMI_BOOL is_combo_key(S16 mmi_key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    return mmi_frm_qwerty_is_special_key(mmi_key_code);
#else
    return MMI_FALSE;
#endif
}


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + The following function is key tone related
 +    1. get_default_num_tone_mode
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*****************************************************************************
 * FUNCTION
 *  get_default_num_tone_mode
 * DESCRIPTION
 *  This function is used to get current num key (0~9 *#) tone mode.
 *  in non-qwerty project DTMF mode will be got. In qwerty project
 *  when user input the number to dial a phone DTMF tone will be got, otherwise
 *  normal tone will be got.
 *
 * PARAMETERS
 *  void    
 * RETURNS
 *  num key tone mode, DTMF or NORMAL, see mmi_frm_num_key_tone_mode_enum
 *****************************************************************************/
static mmi_frm_num_key_tone_mode_enum get_default_num_tone_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    ret = (IsBitReset(g_key_cntx.keypad_status, KPD_NUM_KEY_TONE_MOD_FLAG)) 
           ? MMI_FRM_NUM_KEY_TONE_DTMF : MMI_FRM_NUM_KEY_TONE_NORMAL;
    return ret;
}


#if defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__)
/*****************************************************************************
 * FUNCTION
 *  get_human_voice_key_tone_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  MMIKeyCode      :[IN]   Key code of MMI
 * RETURNS
 *  
 *****************************************************************************/
static S16 get_human_voice_key_tone_id(S16 MMIKeyCode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    U8 keypad_tone_type = GetKeypadToneType();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (keypad_tone_type >= KEYPAD_TONE_HUMAN_VOICE_1 && keypad_tone_type <= KEYPAD_TONE_HUMAN_VOICE_6)
    {
        if (!CanPlayHumanVoiceKeyTone())
        {
            return -1;
        }
        if (MMIKeyCode >= KEY_0 && MMIKeyCode <= KEY_9)
        {
            i = MMIKeyCode - KEY_0;
        }
        else if (MMIKeyCode == KEY_STAR)
        {
            i = 10;
        }
        else if (MMIKeyCode == KEY_POUND)
        {
            i = 11;
        }
        else
        {
            i = -1;
        }

        if (i >= 0)
        {
            return (S16) ((keypad_tone_type - KEYPAD_TONE_HUMAN_VOICE_1) * 13 + i + MIN_HUMAN_VOICE_ID);
        }
    }
    return -1;
}
#endif /* defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__) */


#if defined(__MMI_CUST_KEYPAD_TONE__)
/*****************************************************************************
 * FUNCTION
 *  get_cust_key_tone_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  MMIKeyCode      :[IN]  Key code of MMI      
 * RETURNS
 *  
 *****************************************************************************/
static S16 get_cust_key_tone_id(S16 MMIKeyCode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 keypad_tone_type = GetKeypadToneType();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (keypad_tone_type >= KEYPAD_TONE_CUST_1 && keypad_tone_type <= KEYPAD_TONE_CUST_6)
    {
        if (!CanPlayCustKeyTone())
        {
            return -1;
        }
        return (S16) (keypad_tone_type - KEYPAD_TONE_CUST_1 + MIN_KEYPAD_TONE_ID);
    }
    return -1;
}
#endif /* defined(__MMI_CUST_KEYPAD_TONE__) */ 


/*****************************************************************************
 * FUNCTION
 *  get_key_tone
 * DESCRIPTION
 *  This function is used to get key tone id
 * PARAMETERS
 *  mmi_key_code      :[IN]    Key code of MMI    
 * RETURNS
 *  the ID of key tone.
 *****************************************************************************/
static U16 get_key_tone(S16 mmi_key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_CUST_KEYPAD_TONE__) || defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__)
    S16 i = 0;
#endif
    S32 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_CUST_KEYPAD_TONE__)
    if ((i = get_cust_key_tone_id(mmi_key_code)) >= 0)
    {
        return (U16) i;
    }
#endif /* defined(__MMI_CUST_KEYPAD_TONE__) */ 

#if defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__)
    /* MTK added by Tim for human voice keypad tone */
    if ((i = get_human_voice_key_tone_id(mmi_key_code)) >= 0)
    {
        return (U16) i;
    }
#endif /* defined(__MMI_HUMAN_VOICE_KEYPAD_TONE__) */ 

    /* num key (0~9 *#) in DTMF mode has special key tone */
    if (get_default_num_tone_mode() == MMI_FRM_NUM_KEY_TONE_DTMF)
    {
        if ((mmi_key_code <= KEY_9) || (mmi_key_code == KEY_STAR) || (mmi_key_code == KEY_POUND))
        {
            for (j = 0; j < KEY_TONE_MAP_TBL_NUM; j++)
            {
                if (g_key_tone[j].mmi_key_code == mmi_key_code)
                {
                    return (U16)g_key_tone[j].mmi_key_tone;
                }
            }
        }
    }
    return (U16)TONE_KEY_NORMAL;
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + The following function is full control key related
 +    2. set_full_ctrl_key_state
 +    3. is_full_ctrled
 +    4. is_full_ctrl_key
 +   
 +    Remark: Full control key is KEY_END, KEY_VOL_UP, KEY_VOL_DOWN
 +            Full control means handler these key in voice call by application itself
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*****************************************************************************
 * FUNCTION
 *  set_full_ctrl_key_state
 * DESCRIPTION
 *  This function is used to set full ctrl key state. Full contrl key is
 *  KEY_END, KEY_VOL_UP, KEY_VOL_DOWN. make sure the input is full ctrl key
 *  or assert will happen
 * 
 * PARAMETERS
 *  mmi_key_code :[IN] mmi key code
 *  state        :[IN] full control MMI_TRUE or MMI_FALSE
 * RETURNS
 *  MMI_TRUE if the key is full ctrl key, MMI_FALSE if the key is not full ctrl key
 *****************************************************************************/
static MMI_BOOL set_full_ctrl_key_state(S16 mmi_key_code, MMI_BOOL state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < FULL_CTRL_KEY_NUM; i++)
    {
        if (g_key_cntx.full_ctrl[i].mmi_key_code  == mmi_key_code)
        {
            g_key_cntx.full_ctrl[i].state = state;
            return MMI_TRUE;
        }
    }
    MMI_ASSERT(0);
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  is_full_ctrled
 * DESCRIPTION
 *  This function is used to get full ctrl key state. The full control key
 *  include KEY_END, KEY_VOL_UP & KEY_VOL_DOWN. If the mmi key code is not
 *  full ctrl key, MMI_FALSE will be returned.
 *  [UT function]: ut_is_full_ctrled
 * 
 * PARAMETERS
 *  mmi_key_code    : [IN] mmi key code
 * RETURNS
 *  MMI_TRUE if full controlled by application or MMI_FALSE
 *****************************************************************************/
static MMI_BOOL is_full_ctrled(S16 mmi_key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < FULL_CTRL_KEY_NUM; i++)
    {
        if (g_key_cntx.full_ctrl[i].mmi_key_code  == mmi_key_code)
        {
            return g_key_cntx.full_ctrl[i].state;
        }       
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  is_full_ctrl_key
 * DESCRIPTION
 *  This is used to check if the key is full control by the applications
 *  We will central control KEY_END, KEY_VOL_UP, KEY_VOL_DOWN behavior in the voice call.
 *  If the applications want to full control these keys, should use mmi_frm_set_key_handler_ex()
 * PARAMETERS
 *  mmi_key_code     :[IN] mmi key code
 * RETURNS
 *  MMI_TRUE if supported full control
 *****************************************************************************/
static MMI_BOOL is_full_ctrl_key(U16 mmi_key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_key_code == KEY_END || mmi_key_code == KEY_VOL_UP || mmi_key_code == KEY_VOL_DOWN)
    {
        ret =  MMI_TRUE;
    }    
    return ret;
}


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + The following function is key event handle flow
 +    1. dev_key_handle
 +    2. mmi_key_handle
 +    3. exec_key_handler
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*****************************************************************************
 * FUNCTION
 *  dev_key_handle
 * DESCRIPTION
 *  This function is used to handle device key event.
 *
 * PARAMETERS
 *  dev_evt_p        :[IN]   device key event see dev_key_evt
 * RETURNS
 *  void
 *****************************************************************************/
static void dev_key_handle(dev_key_evt_struct *dev_evt_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_key_evt_struct  mmi_key_event_frm;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_KEY_DEVICE_KEY_INFO, dev_evt_p->device_key_code, dev_evt_p->device_key_type);
    /* Init the local date */
    mmi_key_event_frm.mmi_key_code = KEY_INVALID;
    mmi_key_event_frm.mmi_key_type = MAX_KEY_TYPE;
    mmi_key_event_frm.cvt_code  = KEY_INVALID;
    mmi_key_event_frm.is_clear = MMI_FALSE;
     
    /* get framework level mmi key events */
    get_mmi_key_events(dev_evt_p, &mmi_key_event_frm);
    if ((mmi_key_event_frm.mmi_key_code != KEY_INVALID) && 
        (mmi_key_event_frm.mmi_key_type >= KEY_EVENT_DOWN && 
        mmi_key_event_frm.mmi_key_type < MAX_KEY_TYPE))
    {
        mmi_key_handle(&mmi_key_event_frm);
    }
}


/*****************************************************************************
 * FUNCTION
 *  key_event_notification
 * DESCRIPTION
 *  This function is  used to notify L4C to send AT command
 *  
 * PARAMETERS
 *  key_code    : [IN]  mmi key code
 *  key_type    : [IN]  mmi key type
 * RETURNS
 *  void
 *****************************************************************************/
static void key_event_notification(S16 key_code, S16 key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __TC01__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif            
}


/*****************************************************************************
 * FUNCTION
 *  mmi_key_handle
 * DESCRIPTION
 *  This function is used to handle framework level key event.
 *  The basic logic is:
 *      [1]pre update framework level key cntx
 *      [2]get application level key event
 *      [3]do application level key handle
 *      [4]post update framework level key cntx
 *  
 * PARAMETERS
 *  mmi_evt_p     :[IN] frm level key events pointer
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_key_handle(mmi_key_evt_struct *mmi_evt_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    key_data_struct key_data;
    mmi_key_evt_struct exec_evt[2];
    U32 evt_num;
    U8 i;
    KEYBRD_MESSAGE msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gen_key_data(mmi_evt_p, &key_data);
    pre_update_key_data_buf(&key_data);
#ifdef __KBD_2STEP_KEY_SUPPORT__    
    pre_update_2step_key_state(mmi_evt_p->cvt_code, mmi_evt_p->mmi_key_type);
#endif /* __KBD_2STEP_KEY_SUPPORT__ */    
    get_exec_key_evt(&key_data, exec_evt, &evt_num);
    for (i = 0; i < evt_num; i++)
    {
        key_event_notification(exec_evt[i].cvt_code, exec_evt[i].mmi_key_type);
        if (MMI_FALSE == exec_check_func(&key_data))
        {
            msg.nKeyCode = exec_evt[i].cvt_code;
            msg.nMsgType = exec_evt[i].mmi_key_type;
            mmi_kbn_key_tone_hdlr(&msg);
            
            exec_static_pre_key_handler(&exec_evt[i]);
            if (exec_dynamic_pre_key_handler(&exec_evt[i]) == MMI_TRUE)
            {
                update_clear_state(&exec_evt[i]);
                if (((exec_evt[i].mmi_key_code == KEY_END) && (exec_evt[i].mmi_key_type == KEY_LONG_PRESS)) || 
                    (exec_evt[i].is_clear == MMI_FALSE))
                {
                    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_KEY_KEY_EVENT_INFO, exec_evt[i].cvt_code, exec_evt[i].mmi_key_type);
                    exec_key_handler(&exec_evt[i]);
                }else
                {
                    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_KEY_DISABLE_KEY_ACTION_BY_PRE_KEY_HDLR, exec_evt[i].cvt_code, exec_evt[i].mmi_key_type);
                }
            }
            else
            {
                MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_KEY_DISABLE_KEY_ACTION_BY_PRE_KEY_HDLR, exec_evt[i].cvt_code, exec_evt[i].mmi_key_type);
            }
            exec_dynamic_post_key_handler(&exec_evt[i]);
            exec_static_post_key_handler(&exec_evt[i]);
        }
        else
        {
            init_key_data_buf();
        }
    }
#ifdef __KBD_2STEP_KEY_SUPPORT__    
    post_update_2step_key_state(mmi_evt_p->cvt_code, mmi_evt_p->mmi_key_type);
#endif /* __KBD_2STEP_KEY_SUPPORT__ */    
    post_update_key_data_buf();
}


/*****************************************************************************
 * FUNCTION
 *  exec_key_handler
 * DESCRIPTION
 *  This function is used for executes current key function handler only. 
 *  This function won't execute pre key handler and post key handler.
 * PARAMETERS
 *  keyCode     :[IN]    Key to which this event is associated.     
 *  keyType     :[IN]    KEY_EVENT_UP, KEY_EVENT_DOWN, event occurs when the 
 *                      key is pressed or released.      
 * RETURNS
 *  void
 *****************************************************************************/
static void exec_key_handler(mmi_key_evt_struct *evt_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ucs2_value = 0;
    U32 special_key_flag = 0;
    FuncPtr curr_func_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    evt_p->cvt_code = mmi_frm_qwerty_convert_key_code(evt_p->cvt_code);
#endif

    /* Set key Info */
    mmi_frm_set_key_info(evt_p->cvt_code, evt_p->mmi_key_type);
    
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    mmi_frm_qwerty_get_translated_code_and_special_key_flag(evt_p->cvt_code, &ucs2_value, &special_key_flag);
#endif
    if (mmi_frm_dispatch_key_event(evt_p->cvt_code, evt_p->mmi_key_type, ucs2_value, special_key_flag) == MMI_FALSE)
    {                
        /* get the key handler */
        curr_func_ptr = get_key_handler(evt_p->cvt_code, evt_p->mmi_key_type);
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_KEY_EXECUTE_KEY_HANDLER, evt_p->cvt_code, evt_p->mmi_key_type, curr_func_ptr);
    
        /* invoke the key handler */
        if (curr_func_ptr)
        {
        #ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
            g_mmi_frm_cntx.dump_screen_info.allow_dump_screen_str = MMI_TRUE;
        #endif    
            (*curr_func_ptr)();    
        }
     }
  
    /* If finish the key up handler, we reset the current key info. */
    if (evt_p->mmi_key_type == KEY_EVENT_UP)
    {    
        mmi_frm_set_key_info(evt_p->cvt_code, MAX_KEY_TYPE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  pen_pre_key_handler
 * DESCRIPTION
 *  This function is pen pre key handler.
 * PARAMETERS
 *  mmi_key_code  :[IN] mmi key code
 *  mmi_key_type  :[IN] mmi key type
 *
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__) 
static void pen_pre_key_handler(S16 mmi_key_code, S16 mmi_key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mmi_key_type == KEY_EVENT_DOWN) && g_key_cntx.buf_len == 1)
    {
        mmi_pen_disable();
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  bt_pre_key_handler
 * DESCRIPTION
 *  This function is bt pre key handler.
 * PARAMETERS
 *  mmi_key_code  :[IN] mmi key code
 *  mmi_key_type  :[IN] mmi key type
 *
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_AVRCP_SUPPORT__) 
static void bt_pre_key_handler(S16 mmi_key_code, S16 mmi_key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /* keypad is pressed, disable BT key processing */
    if ((mmi_key_type == KEY_EVENT_DOWN) && g_key_cntx.buf_len == 1)
    {    
        mmi_bt_avrcp_frm_sync_calllback(MMI_TRUE);
    }
}
#endif /* defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_AVRCP_SUPPORT__) */


/*****************************************************************************
 * FUNCTION
 *  profiling_pre_key_handler
 * DESCRIPTION
 *  This function is profiling pre key handler.
 * PARAMETERS
 *  mmi_key_code  :[IN] mmi key code
 *  mmi_key_type  :[IN] mmi key type
 *
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_INTERACTIVE_PROFILNG__ 
static void profiling_pre_key_handler(S16 mmi_key_code, S16 mmi_key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_key_type == KEY_EVENT_DOWN)
    {
        mmi_frm_profiling_interactive_start3();
    }
    else if (mmi_key_type == KEY_EVENT_UP)
    {
        mmi_frm_profiling_interactive_start2();
    }        
}
#endif /* __MMI_INTERACTIVE_PROFILNG__ */


/*****************************************************************************
 * FUNCTION
 *  special_keys_pre_key_handler
 * DESCRIPTION
 *  This function is special keys pre key handler.
 * PARAMETERS
 *  mmi_key_code  :[IN] mmi key code
 *  mmi_key_type  :[IN] mmi key type
 *
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__ 
static void special_keys_pre_key_handler(S16 mmi_key_code, S16 mmi_key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    mmi_frm_qwerty_update_key_status_pre_key_event(mmi_key_code, mmi_key_type);         
}
#endif


/*****************************************************************************
 * FUNCTION
 *  backlight_pre_key_handler
 * DESCRIPTION
 *  This function is special keys pre key handler.
 * PARAMETERS
 *  mmi_key_code  :[IN] mmi key code
 *  mmi_key_type  :[IN] mmi key type
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void backlight_pre_key_handler(S16 mmi_key_code, S16 mmi_key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_shutdown_is_in_power_off_period())
    {
        mmi_idle_key_event_backlight_check();
    }         
}


/*****************************************************************************
 * FUNCTION
 *  keypad_lock_pre_key_handler
 * DESCRIPTION
 *  This function is keypad lock pre key handler.
 * PARAMETERS
 *  mmi_key_code  :[IN] mmi key code
 *  mmi_key_type  :[IN] mmi key type
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void keypad_lock_pre_key_handler(S16 mmi_key_code, S16 mmi_key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    KEYBRD_MESSAGE key_msg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    key_msg.nMsgType = mmi_key_type;
    key_msg.nKeyCode = mmi_key_code;
    mmi_idle_key_event_keypad_lock_check(&key_msg);
    mmi_idle_restart_keypad_lock_timer();        
}


/*****************************************************************************
 * FUNCTION
 *  screen_saver_pre_key_handler
 * DESCRIPTION
 *  This function is screen saver pre key handler.
 * PARAMETERS
 *  mmi_key_code  :[IN] mmi key code
 *  mmi_key_type  :[IN] mmi key type
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void screen_saver_pre_key_handler(S16 mmi_key_code, S16 mmi_key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_idle_restart_screensaver_timer();        
}


/*****************************************************************************
 * FUNCTION
 *  pen_post_key_handler
 * DESCRIPTION
 *  This function is pen post key handler.
 * PARAMETERS
 *  mmi_key_code  :[IN] mmi key code
 *  mmi_key_type  :[IN] mmi key type
 *
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__) 
static void pen_post_key_handler(S16 mmi_key_code, S16 mmi_key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_key_type == KEY_EVENT_UP && g_key_cntx.buf_len == 1)
    {
        mmi_pen_enable();
    }
}
#endif
    

/*****************************************************************************
 * FUNCTION
 *  bt_post_key_handler
 * DESCRIPTION
 *  This function is bt post key handler.
 * PARAMETERS
 *  mmi_key_code  :[IN] mmi key code
 *  mmi_key_type  :[IN] mmi key type
 *
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_AVRCP_SUPPORT__) 
static void bt_post_key_handler(S16 mmi_key_code, S16 mmi_key_type)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /* keypad is released, enable BT key processing */
    if (mmi_key_type == KEY_EVENT_UP && g_key_cntx.buf_len == 1)
    {    
        mmi_bt_avrcp_frm_sync_calllback(MMI_FALSE);
    }
}
#endif /* defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_AVRCP_SUPPORT__) */


/*****************************************************************************
 * FUNCTION
 *  profiling_post_key_handler
 * DESCRIPTION
 *  This function is profiling post key handler.
 * PARAMETERS
 *  mmi_key_code  :[IN] mmi key code
 *  mmi_key_type  :[IN] mmi key type
 *
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_INTERACTIVE_PROFILNG__ 
static void profiling_post_key_handler(S16 mmi_key_code, S16 mmi_key_type)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (mmi_key_type == KEY_EVENT_DOWN)
    {
        mmi_frm_profiling_interactive_end3();
    }
    else if (mmi_key_type == KEY_EVENT_UP)
    {
        mmi_frm_profiling_interactive_end2();
        mmi_frm_profiling_interactive_show((U8*) L"K", MMI_FRM_PROFILING_MASK_2 | MMI_FRM_PROFILING_MASK_3);
    }
}
#endif /* __MMI_INTERACTIVE_PROFILNG__ */


/*****************************************************************************
 * FUNCTION
 *  mem_monitor_post_key_handler
 * DESCRIPTION
 *  This function is memory monitor post key handler.
 * PARAMETERS
 *  mmi_key_code  :[IN] mmi key code
 *  mmi_key_type  :[IN] mmi key type
 *
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_MEMORY_MONITOR__ 
static void mem_monitor_post_key_handler(S16 mmi_key_code, S16 mmi_key_type)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (mmi_key_type == KEY_EVENT_UP)
    {
        mmi_mem_monitor_type_enum type = mmi_mem_mon_profiling_get_enable();

        if (MMI_EM_MEMORY_MONITOR_OFF != type)
        {    
            mmi_mem_mon_profiling_memory_monitor(type, NULL);
        }
    } 
}
#endif /* __MMI_MEMORY_MONITOR__ */


/*****************************************************************************
 * FUNCTION
 *  special_keys_post_key_handler
 * DESCRIPTION
 *  This function is special keys post key handler.
 * PARAMETERS
 *  mmi_key_code  :[IN] mmi key code
 *  mmi_key_type  :[IN] mmi key type
 *
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__ 
static void special_keys_post_key_handler(S16 mmi_key_code, S16 mmi_key_type)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_frm_qwerty_update_key_status_post_key_event(mmi_key_code, mmi_key_type);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  exec_static_pre_key_handler
 * DESCRIPTION
 *  This function is execute static pre key handler.
 * PARAMETERS
 *  mmi_key_code  :[IN] mmi key code
 *  mmi_key_type  :[IN] mmi key type
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void exec_static_pre_key_handler(mmi_key_evt_struct *evt_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < KEY_PRE_HDL_TBL_NUM; i++)
    {
        if (g_key_pre_handle_table[i] != NULL)
        {
            (* g_key_pre_handle_table[i])(evt_p->cvt_code, evt_p->mmi_key_type);
        }
    }    
}


/*****************************************************************************
 * FUNCTION
 *  exec_static_post_key_handler
 * DESCRIPTION
 *  This function is used to execute post key handler.
 * PARAMETERS
 *  mmi_key_code  :[IN] mmi key code
 *  mmi_key_type  :[IN] mmi key type
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void exec_static_post_key_handler(mmi_key_evt_struct *evt_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < KEY_POST_HDL_TBL_NUM; i++)
    {
        if (g_key_post_handle_table[i] != NULL)
        {
            (* g_key_post_handle_table[i])(evt_p->cvt_code, evt_p->mmi_key_type);
        }
    }    
}


/*****************************************************************************
 * FUNCTION
 *  exec_dynamic_post_key_handler
 * DESCRIPTION
 *  This function is used to get any key handler.
 * PARAMETERS
 *  evt_p       :[IN] mmi key event
 *
 * RETURNS
 *  void
 *****************************************************************************/ 
static void exec_dynamic_post_key_handler(mmi_key_evt_struct *evt_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    KEYBRD_MESSAGE key_msg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_KEY_EXECUTE_POST_KEY_HANDLER, g_key_cntx.kbd_post_func);
    key_msg.nMsgType = evt_p->mmi_key_type;
    key_msg.nKeyCode = evt_p->cvt_code;        
    if (g_key_cntx.kbd_post_func)
    {
        g_key_cntx.kbd_post_func(&key_msg);
    }    
}


/*****************************************************************************
 * FUNCTION
 *  exec_dynamic_pre_key_handler
 * DESCRIPTION
 *  This function is used to execute dynamic pre key handler
 * PARAMETERS
 *  evt_p       :[IN] mmi key event
 *
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/ 
static MMI_BOOL exec_dynamic_pre_key_handler(mmi_key_evt_struct *evt_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    KEYBRD_MESSAGE key_msg;
    MMI_BOOL ret = MMI_TRUE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_KEY_EXECUTE_PRE_KEY_HANDLER, g_key_cntx.kbd_pre_func);    
    key_msg.nMsgType = evt_p->mmi_key_type;
    key_msg.nKeyCode = evt_p->cvt_code;       

    if (g_key_cntx.kbd_pre_func)
    {
        ret = g_key_cntx.kbd_pre_func(&key_msg);
    } 
    return ret; 
}


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + The following function is key event generation
 +    1. get_mmi_key_events
 +    2. get_exec_key_evt
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*****************************************************************************
 * FUNCTION
 *  get_mmi_key_events
 * DESCRIPTION
 *  get mmi key event from device key event
 *  [UT function]: ut_get_mmi_key_events
 * PARAMETERS
 *  dev_evt_p      :[IN]   pointer to 1 device key event
 *  mmi_evt_p      :[OUT]  pointer to 1 mmi key event 
 * RETURNS
 *  void
 *****************************************************************************/
static void get_mmi_key_events(dev_key_evt_struct *dev_evt_p, mmi_key_evt_struct *mmi_evt_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 mmi_key_code;
    S16 mmi_key_type;
    S16 prev_mmi_key_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_key_code = get_mmi_key_code(dev_evt_p->device_key_code);
    mmi_evt_p->cvt_code = mmi_key_code_convert(mmi_key_code, dev_evt_p->device_key_type);

    if ((mmi_key_code == KEY_INVALID) && 
        (dev_evt_p->device_key_type != DRV_WM_ENABLE_TWOKEY_DETECTION) &&
        (dev_evt_p->device_key_type != DRV_WM_ENABLE_THREEKEY_DETECTION) &&
        (dev_evt_p->device_key_type != DRV_WM_DISABLE_MULTIKEY_DETECTION))
    {
        mmi_evt_p->mmi_key_code = KEY_INVALID;
        mmi_evt_p->mmi_key_type = ERR_KEY_CODE;
        return;
    }
    mmi_key_type = get_mmi_key_type(dev_evt_p->device_key_type, GET_KEY_CAT(mmi_key_code));
    if ((mmi_key_type < MAX_KEY_TYPE) && (mmi_key_type >=0))
    {
        prev_mmi_key_type = get_key_state(mmi_key_code);
        if (is_legal_key_type(mmi_key_type, prev_mmi_key_type, GET_KEY_CAT(mmi_key_code)) == MMI_FALSE)
        {
            mmi_key_type =  ERR_KEY_EVT_TRANS;
        }
    }
    mmi_evt_p->mmi_key_code = mmi_key_code;
    mmi_evt_p->mmi_key_type = mmi_key_type;
    mmi_evt_p->is_clear = dev_evt_p->is_clear;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  get_exec_key_evt
 * DESCRIPTION
 *  This function is used to get executable key event
 *  [UT function]: ut_get_exec_key_evt
 * PARAMETERS
 *  data_p        :[IN]  key data 
 *  exec_evt_p    :[OUT] executable key events buffer
 *  evt_num_p     :[OUT] executable key events number
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void get_exec_key_evt(key_data_struct *data_p, mmi_key_evt_struct *exec_evt_p, U32 *evt_num_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __KBD_2STEP_KEY_SUPPORT__    
    U8 state;
#endif /* __KBD_2STEP_KEY_SUPPORT__ */    
    U8 mode;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    exec_evt_p[0].mmi_key_code = data_p->mmi_key_code;
    exec_evt_p[0].mmi_key_type = data_p->mmi_key_type;
    exec_evt_p[0].cvt_code = data_p->cvt_code;
    exec_evt_p[0].is_clear = data_p->is_clear;
    *evt_num_p = 1;
 #ifdef __KBD_2STEP_KEY_SUPPORT__   
    if (data_p->is_2step == MMI_TRUE)
    {
        if (data_p->mmi_key_type == KEY_EVENT_UP)
        {
            state = get_2step_key_state(data_p->mmi_key_code);
            if (state == FULL_DOWN)
            {
                exec_evt_p[0].mmi_key_type = KEY_HALF_PRESS_UP;
                exec_evt_p[1].mmi_key_code = data_p->mmi_key_code;
                exec_evt_p[1].cvt_code = data_p->cvt_code;
                exec_evt_p[1].is_clear = data_p->is_clear;
                exec_evt_p[1].mmi_key_type = KEY_EVENT_UP;
                *evt_num_p = 2;
            }
            else if (state == HALF_DOWN)
            {
                exec_evt_p[0].mmi_key_type = KEY_HALF_PRESS_UP;
            }
            else
            {
                MMI_ASSERT(0);
            } 
        }
    }
    else
#endif /* __KBD_2STEP_KEY_SUPPORT__ */    
    {
        mode = GET_KPD_MODE(g_key_cntx.keypad_status);
        if (mode == KEYPAD_1KEY_NUMBER || mode == KEYPAD_1KEY_QWERTY)
        {
            if (get_data_buf_len() == 2)
            {
                key_data_struct data1;
                key_data_struct data2;                
                get_key_data(&data1, 0);
                get_key_data(&data2, 1);
                if (data2.mmi_key_code == data_p->mmi_key_code)
                {
                    if (!is_combo_key(data1.mmi_key_code) && !is_combo_key(data2.mmi_key_code))
                    {
                        if (data1.mmi_key_type != KEY_EVENT_UP && data2.mmi_key_type == KEY_EVENT_DOWN)
                        {
                            MMI_ASSERT(data_p->mmi_key_type == KEY_EVENT_DOWN);
                            data1.mmi_key_type = KEY_EVENT_UP;
                            update_key_data(&data1);
                            exec_evt_p[0].mmi_key_code = data1.mmi_key_code;
                            exec_evt_p[0].mmi_key_type = data1.mmi_key_type;
                            exec_evt_p[0].cvt_code = data1.cvt_code;
                            exec_evt_p[0].is_clear = data1.is_clear;
                            exec_evt_p[1].mmi_key_code = data_p->mmi_key_code;
                            exec_evt_p[1].mmi_key_type = data_p->mmi_key_type;
                            exec_evt_p[1].cvt_code = data_p->cvt_code;
                            exec_evt_p[1].is_clear = data_p->is_clear;
                            *evt_num_p = 2;                                
                        }
                    }
                }           
            }
        }
    }
}


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + The following function is key context related functions:
 +    1. init_key_data_buf
 +    2. insert_key_data
 +    3. search_key_data
 +    4. update_key_data
 +    5. remove_key_data
 +    6. mmi_frm_get_mmi_key_state
 + description:
 +    1. structure - array 
 +     ###############################
 +     # entry 0 # entry 1 # entry2  #
 +     ###############################
 +    2.Operation
 +       Init, Insert, Search, Update, Remove, Get
 +    
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
 /*****************************************************************************
 * FUNCTION
 *  init_key_data_buf
 * DESCRIPTION
 *  This function is used to init key data buffer.
 *  After init for each entry like the following:
 *     ++++++++++++++++
 *     + KEY_INVALID  +
 *     ++++++++++++++++
 *     + KEY_EVENT_UP +
 *     ++++++++++++++++
 *     +     00       +
 *     ++++++++++++++++
 *  [UT function:] ut_init_key_data_buf
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void init_key_data_buf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    memset(g_key_cntx.buffer, 0x00, sizeof(key_data_struct));
    g_key_cntx.buf_len = 0;
    for (j = 0; j < MAX_DECT_KEY_NUM; j++)
    {
        g_key_cntx.buffer[j].mmi_key_code = KEY_INVALID;
        g_key_cntx.buffer[j].cvt_code = KEY_INVALID;
        g_key_cntx.buffer[j].mmi_key_type = KEY_EVENT_UP;
    }
} 


/*****************************************************************************
 * FUNCTION
 *  insert_key_data
 * DESCRIPTION
 *  This function is used to insert mmi key code to active key cntx.
 *  The basic logic is insert the data to the first KEY_INVALID in the table
 *  e.g. Entry number is 2
 *  insert KEY0 
 *                +++++++++++++++++++++++++++++               +++++++++++++++++++++++++++++
 *  before insert + KEY_INVALID + KEY_INVALID + after insert  +   KEY_0     + KEY_INVALID +
 *                +++++++++++++++++++++++++++++               +++++++++++++++++++++++++++++
 *  insert KEY0
 *                +++++++++++++++++++++++++++++               
 *  before insert + KEY_0       + KEY_INVALID + after insert  Assert happen
 *                +++++++++++++++++++++++++++++
 *  insert KEY1
 *                +++++++++++++++++++++++++++++               +++++++++++++++++++++++++++++
 *  before insert + KEY_0       + KEY_INVALID + after insert  +   KEY_0     + KEY_1       +
 *                +++++++++++++++++++++++++++++               +++++++++++++++++++++++++++++
 *  insert KEY3
 *                +++++++++++++++++++++++++++++               
 *  before insert + KEY_0       + KEY_1       + after insert assert happen
 *                +++++++++++++++++++++++++++++               
 *  insert KEY0(This case is not implement, should make sure this case not happen when remove)
 *                +++++++++++++++++++++++++++++               
 *  before insert + KEY_INVALID + KEY_1       +
 *                +++++++++++++++++++++++++++++
 *  [UT function]:ut_insert_key_data
 *
 * PARAMETERS
 *  data_p     :[IN]   key data see key_data_struct
 *
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret insert_key_data(key_data_struct * data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 det_num;
    key_data_struct *buffer_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    det_num = GET_KEY_DET_MODE(g_key_cntx.keypad_status) + 1;
    buffer_p = g_key_cntx.buffer;
    for(i = 0; i < det_num; i++)
    {
        /*
         * if we find mmi_key_code already exists in key data buffer,
         * we assert here because we should not get down, down for same key
         */

        if (buffer_p[i].mmi_key_code == data_p->mmi_key_code)
        {
		#ifndef __MMI_FRM_KEY_EVENT_UT__	
            MMI_ASSERT(0);
		#endif /* __MMI_FRM_KEY_EVENT_UT__ */
            return INSERT_SAME_KEY_CODE;
        }

        /*
         * we will find the first empty entry for the new pressing mmi key code
         */
        if (buffer_p[i].mmi_key_code == KEY_INVALID)
        {
            buffer_p[i].mmi_key_code = data_p->mmi_key_code;
            buffer_p[i].mmi_key_type = data_p->mmi_key_type;
            buffer_p[i].cvt_code    = data_p->cvt_code;
            buffer_p[i].is_combo   = data_p->is_combo;
            buffer_p[i].is_2step     = data_p->is_2step;
            buffer_p[i].is_clear     = data_p->is_clear;
            buffer_p[i].is_full_ctrl = data_p->is_full_ctrl;
            g_key_cntx.buf_len++;
            return MMI_RET_OK;
        }
    }
    /*
     * Multi-key behavior is wrong
     * So we assert here and ask driver to check.
     */
#ifndef  __MMI_FRM_KEY_EVENT_UT__    
    MMI_ASSERT(0);
#endif /* __MMI_FRM_KEY_EVENT_UT__ */
    return INSERT_CODE_BEYOND_DECT;
}


/*****************************************************************************
 * FUNCTION
 *  search_key_data
 * DESCRIPTION
 *  This function is used to find the key context index for mmi_key_code
 *  [UT function]: ut_search_key_data
 * PARAMETERS
 *  mmi_key_code     :[IN]   mmi key code
 *
 * RETURNS
 *  index if found, or -1
 *****************************************************************************/
static S32 search_key_data(S16 mmi_key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = -1;
    S32 i;
    S32 det_num;
    key_data_struct *buffer_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    det_num = GET_KEY_DET_MODE(g_key_cntx.keypad_status) + 1;
    buffer_p = g_key_cntx.buffer;

    for(i = 0; i < det_num; i++)
    {
        if ((U16)buffer_p[i].mmi_key_code == mmi_key_code || (U16)buffer_p[i].cvt_code == mmi_key_code)
        {
            index = i;
            break;
        }
    }
    return index;
}


/*****************************************************************************
 * FUNCTION
 *  update_key_data
 * DESCRIPTION
 *  This function is used to update key data buffer
 *  [UT function:]ut_update_key_data
 * PARAMETERS 
 *  data_ptr     :[IN]   key data  
 *
 * RETURNS
 *  MMI_TRUE if changed, or MMI_FALSE
 *****************************************************************************/
static MMI_BOOL update_key_data(key_data_struct *data_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    key_data_struct *buffer_p;
    S32 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    buffer_p = g_key_cntx.buffer;
    if ((index = search_key_data((S16)data_ptr->mmi_key_code)) != -1)
    {
        buffer_p[index].mmi_key_type = data_ptr->mmi_key_type;
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  remove_key_data
 * DESCRIPTION
 *  This function is used to delete mmi key code from active key cntx
 *  remove KEY0
 *                +++++++++++++++++++++++++++++               +++++++++++++++++++++++++++++
 *  before remove + KEY_0       + KEY_INVALID + after remove  + KEY_INVALID + KEY_INVALID +
 *                +++++++++++++++++++++++++++++               +++++++++++++++++++++++++++++
 *
 *  remove KEY0
 *                +++++++++++++++++++++++++++++               +++++++++++++++++++++++++++++
 *  before remove + KEY_0       + KEY_1       + after remove  + KEY_1       + KEY_INVALID +
 *                +++++++++++++++++++++++++++++               +++++++++++++++++++++++++++++
 *
 *  remove KEY1
 *                +++++++++++++++++++++++++++++               +++++++++++++++++++++++++++++
 *  before remove + KEY_0       + KEY_1       + after remove  + KEY_0       + KEY_INVALID +
 *                +++++++++++++++++++++++++++++               +++++++++++++++++++++++++++++
 *  [UT Function]: ut_remove_key_data
 * PARAMETERS
 *  mmi_key_code     :[IN]   mmi key code
 *
 *
 * RETURNS
 *  void 
 *****************************************************************************/
static mmi_ret remove_key_data(S16 mmi_key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32             index;
    S32             i;
    key_data_struct *buffer_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    buffer_p = g_key_cntx.buffer;
    if ((index = search_key_data(mmi_key_code)) != -1)
    {
        for (i = index; i < MAX_DECT_KEY_NUM - 1; i++)
        {
            buffer_p[i] = buffer_p[i + 1];
        }
        buffer_p[MAX_DECT_KEY_NUM - 1].mmi_key_code = KEY_INVALID;
        buffer_p[MAX_DECT_KEY_NUM - 1].cvt_code = KEY_INVALID;
        MMI_ASSERT(g_key_cntx.buf_len > 0);
        g_key_cntx.buf_len--;
		return MMI_RET_OK;
    }
    return REMOVE_BUT_NOT_FOUND;
}


/*****************************************************************************
 * FUNCTION
 *  get_key_state
 * DESCRIPTION
 *  This function is used to get mmi key state.
 *  [UT function]:ut_get_key_state
 *
 * PARAMETERS
 *  mmi_key_code     :[IN] mmi_key code
 *
 * RETURNS
 *  mmi key type see mmi_key_types_enum
 *****************************************************************************/
static S16 get_key_state(S16 mmi_key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((index = search_key_data(mmi_key_code)) != -1)
    {
        return (S16)g_key_cntx.buffer[index].mmi_key_type;
    }
    else
    {       
        /* 
         * If we cannot find the mmi_key_code in key data buffer, the key should be in up
         * status for both normal key and 2step key. 
         */
        return (S16)KEY_EVENT_UP;        
    }
}


/*****************************************************************************
 * FUNCTION
 *  get_data_buf_len
 * DESCRIPTION
 *  This function is used to get key data buffer length
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
static U8 get_data_buf_len(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_key_cntx.buf_len;
}


/*****************************************************************************
 * FUNCTION
 *  get_key_data
 * DESCRIPTION
 *  This function is used to get key data from data buffer by index
 *  [UT function]: ut_get_key_data
 * PARAMETERS
 *  index     :[IN] data buffer index
 *  data_p    :[OUT] key data 
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void get_key_data(key_data_struct *data_p, U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(index < MAX_DECT_KEY_NUM);
    memcpy(data_p, &g_key_cntx.buffer[index], sizeof(key_data_struct));
}


/*****************************************************************************
 * FUNCTION
 *  get_mmi_key_codes_in_data_buf
 * DESCRIPTION
 *  This function is used to get all mmi key codes in key data buffer
 *  [UT function]: ut_get_mmi_key_codes_in_data_buf
 * PARAMETERS
 *  mmi_key_code_p     :[OUT] mmi key code array
 *  num                :[OUT] key data 
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void  get_mmi_key_codes_in_data_buf(U8 *mmi_key_code_p, U8 *num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_key_cntx.buf_len; i++)
    {
        mmi_key_code_p[i] = g_key_cntx.buffer[i].mmi_key_code;
    }
    *num = g_key_cntx.buf_len;
}


/*****************************************************************************
 * FUNCTION
 *  set_all_key_data_clear
 * DESCRIPTION
 *  This function is used to all key data in data buffer as clear state
 *  [UT function:]ut_set_all_key_data_clear
 * PARAMETERS 
 *  void 
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void set_all_key_data_clear(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_key_cntx.buf_len; i++)
    {
        g_key_cntx.buffer[i].is_clear = MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  update_clear_state
 * DESCRIPTION
 *  This function is used to update clear state of a execute event
 *  [UT function:]ut_update_clear_state
 * PARAMETERS 
 *  void 
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void update_clear_state(mmi_key_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((index = search_key_data(evt->mmi_key_code)) != -1)
    {
        evt->is_clear = g_key_cntx.buffer[index].is_clear;
    }
}


/*****************************************************************************
 * FUNCTION
 *  pre_update_key_data_buf
 * DESCRIPTION
 *  This function is used to update key data buffer before key handler
 *  [UT function]: ut_pre_update_key_data_buf
 *
 * PARAMETERS
 *  data_p     :[IN] key data pointer
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void pre_update_key_data_buf(key_data_struct *data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __KBD_2STEP_KEY_SUPPORT__    
    if (data_p->is_2step == MMI_TRUE)
    {
        MMI_ASSERT(data_p->is_combo == MMI_FALSE);
        if (data_p->mmi_key_type == KEY_HALF_PRESS_DOWN)
        {
            insert_key_data(data_p);
        }
        else
        {
            MMI_ASSERT(data_p->mmi_key_type != KEY_HALF_PRESS_UP)
            update_key_data(data_p);
        }
    }
    else
#endif /* __KBD_2STEP_KEY_SUPPORT__ */    
    {
        if (data_p->mmi_key_type == KEY_EVENT_DOWN)
        {
            insert_key_data(data_p);
        }
        else
        {
            MMI_ASSERT(data_p->mmi_key_type != KEY_HALF_PRESS_DOWN)
            MMI_ASSERT(data_p->mmi_key_type != KEY_HALF_PRESS_UP);
            update_key_data(data_p);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  post_update_key_data_buf
 * DESCRIPTION
 *  This function is used to update key data buffer after key handler
 *  remove all key data that is in UP state
 *  [UT function]: ut_post_update_key_data_buf
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void post_update_key_data_buf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U8  rm_code[MAX_DECT_KEY_NUM];
    U8  rm_count = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    for (i = 0; i < g_key_cntx.buf_len; i++)
    {
        if (g_key_cntx.buffer[i].mmi_key_type == KEY_EVENT_UP)
        {
            rm_code[rm_count] = g_key_cntx.buffer[i].mmi_key_code;
            rm_count++;
        }
    }
    for (i = 0; i < rm_count; i++)
    {
        remove_key_data(rm_code[i]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gen_key_data
 * DESCRIPTION
 *  This function is used to generate key data for one key event from driver
 *  [UT function]: ut_gen_key_data
 *
 * PARAMETERS
 *  mmi_key_evt_struct  :[IN] mmi key event
 *  data_p              :[OUT] key data pointer
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void gen_key_data(mmi_key_evt_struct *evt, key_data_struct *data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data_p->mmi_key_code = (U8)evt->mmi_key_code;
    data_p->mmi_key_type = (U8)evt->mmi_key_type;
    data_p->cvt_code    = (U8)evt->cvt_code;
#ifdef __KBD_2STEP_KEY_SUPPORT__    
    data_p->is_2step = is_2step_key(evt->mmi_key_code);
#else /* __KBD_2STEP_KEY_SUPPORT__ */
    data_p->is_2step = MMI_FALSE;
#endif
    data_p->is_clear = evt->is_clear;
    data_p->is_combo = is_combo_key(evt->mmi_key_code);
    data_p->is_full_ctrl = is_full_ctrled(evt->mmi_key_code);
}


#ifdef __KBD_2STEP_KEY_SUPPORT__
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + The following function is 2 step key related function:
 +    1. is_2step_key
 +    2. get_2step_key_state
 +    remark: what is 2step key, the 2step means key down has 2step, half down and full down
 +    like camera key, half down to focus, full down to take a picture
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

 /*****************************************************************************
 * FUNCTION
 *  is_2step_key
 * DESCRIPTION
 *  This function is used to judge if the key is 2step key or not
 *  [UT function]:ut_is_2step_key
 * PARAMETERS
 *  mmi_key_code   :[IN]  mmi_key_code
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL is_2step_key(S16 mmi_key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((S16)g_key_cntx._2step_key.mmi_key_code == mmi_key_code);
}


/*****************************************************************************
 * FUNCTION
 *  get_2step_key_state
 * DESCRIPTION
 *  This function is used to get 2step key state, make sure the mmi key code 
 *  is 2step key or assert will happen.
 *  [UT function]:ut_get_2step_key_state
 *
 * PARAMETERS
 *  mmi_key_code   :[IN]  mmi_key_code
 * RETURNS
 *  _2step_state_enum
 *****************************************************************************/
static U8 get_2step_key_state(S16 mmi_key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(is_2step_key(mmi_key_code) == MMI_TRUE)
    {
        return g_key_cntx._2step_key.state;
    }
    else
    {
        return (U8)STATE_END;
    }
}


/*****************************************************************************
 * FUNCTION
 *  pre_update_2step_key_state
 * DESCRIPTION
 *  This function is used to update 2step key state before key handler
 *
 *  [UT function]:ut_pre_update_2step_key_state
 *
 * PARAMETERS
 *  mmi_key_code   :[IN]  mmi_key_code
 *  mmi_key_type   :[IN]  mmi_key_type
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void pre_update_2step_key_state(S16 mmi_key_code, S16 mmi_key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == is_2step_key(mmi_key_code))
    {
        if (mmi_key_type == KEY_HALF_PRESS_DOWN)
        {
            g_key_cntx._2step_key.state = HALF_DOWN;
        }
        else if (mmi_key_type == KEY_FULL_PRESS_DOWN)
        {
            g_key_cntx._2step_key.state = FULL_DOWN;
        }        
    }
}


/*****************************************************************************
 * FUNCTION
 *  post_update_2step_key_state
 * DESCRIPTION
 *  This function is used to update 2step key state after key handler
 *
 *  [UT function]:ut_post_update_2step_key_state
 *
 * PARAMETERS
 *  mmi_key_code   :[IN]  mmi_key_code
 * RETURNS
 *  void
 *****************************************************************************/
static void post_update_2step_key_state(S16 mmi_key_code, S16 mmi_key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == is_2step_key(mmi_key_code))
    {
        if (mmi_key_type == KEY_EVENT_UP)
        {
            g_key_cntx._2step_key.state = FULL_UP;
        }     
    }
}
#endif /* __KBD_2STEP_KEY_SUPPORT__ */

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + The following function is the operation for key type transformation and check:
 +    1.get_mmi_key_type
 +    2.is_legal_key_type  
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

 /*****************************************************************************
 * FUNCTION
 *  get_mmi_key_type
 * DESCRIPTION
 *  This function is used to get mmi key type from device level to framework level
 *    1. Detection event   
 *      DRV_WM_ENABLE_TWOKEY_DETECTION
 *      DRV_WM_ENABLE_THREEKEY_DETECTION
 *      DRV_WM_DISABLE_MULTIKEY_DETECTION
 *   all mapping to KEY_EVENT_DECT
 *   when we get detection event from driver, it means the key detection mode has been changed by driver.
 *   so we update key detection mode when receive these kinds of event
 *    2. Non-2step key type mapping
 *       DRV_WM_KEYPRESS     -> KEY_EVENT_DOWN
 *       DRV_WM_KEYRELEASE   -> KEY_EVENT_UP
 *       DRV_WM_KEYLONGPRESS -> KEY_LONG_PRESS
 *       DRV_WM_KEYREPEATED  -> KEY_REPEAT
 *    3. 2tep key type mapping
 *       DRV_WM_KEYPRESS     -> KEY_HALF_PRESS_DOWN
 *       DRV_WM_KEYRELEASE   -> KEY_EVENT_UP
 *       DRV_WM_KEYLONGPRESS -> KEY_LONG_PRESS
 *       DRV_WM_KEYREPEATED  -> KEY_REPEAT
 *       DRV_WM_KEYFULLPRESS -> KEY_FULL_PRESS_DOWN
 *  [Attention Point]:
 *    1. invalid device key type, assert.
 *    2. DRV_WM_KEYFULLPRESS for non-2step key, assert.
 *  [UT function]:ut_get_mmi_key_type
 * PARAMETERS
 *  device_key_type   :[IN]  device key type
 *  cat               :[IN]  TWO_STEP_KEY or NON_TWO_STEP_KEY
 * RETURNS
 *  mmi_key_type
 *****************************************************************************/
static S16 get_mmi_key_type(U8 device_key_type, U8 cat)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < KEY_TYPE_MAP_TBL_NUM; i++)
    {
        if (GET_DEV_KEY_TYPE(g_key_type_map[i]) == device_key_type)
        {
            if (GET_MMI_KEY_TYPE(g_key_type_map[i]) == MAX_KEY_TYPE)
            {
                SET_KEY_DET_MODE(g_key_cntx.keypad_status, GET_CAT(g_key_type_map[i]));
                return (S16)KEY_EVENT_DECT;
            }
            if (GET_CAT(g_key_type_map[i]) & cat)
            {
                return (S16)GET_MMI_KEY_TYPE(g_key_type_map[i]);
            }
        }
    }
#ifndef __MMI_FRM_KEY_EVENT_UT__
    MMI_ASSERT(0);
#endif
    return ERR_KEY_EVENT;
}


/*****************************************************************************
 * FUNCTION
 *  is_legal_key_type
 * DESCRIPTION
 *  This function is used to check if the current mmi key type of the specific key
 *  is legal or not, according to its previous mmi key type in framework key event level
 *  or application key event level. If the check is ok we will update active key cntx
 *  The basic checking logic is:
 *  Framework level - 2step key
 *        [current key type]        [possible pre key type]
 *        KEY_HALF_PRESS_DOWN       KEY_EVENT_UP
 *        KEY_FULL_PRESS_DOWN       KEY_HALF_PRESS_DOWN
 *        KEY_LONG_PRESS            KEY_FULL_PRESS_DOWN
 *        KEY_REPEAT                KEY_REPEAT or KEY_LONG_PRESS
 *        KEY_EVENT_UP              KEY_HALF_PRESS_DOWN, KEY_FULL_PRESS_DOWN, KEY_LONG_PRESS, KEY_REPEAT
 *
 *  Framework level - non - 2step key
 *        [current key type]        [possible pre key type]
 *        KEY_EVENT_DOWN            KEY_EVENT_UP
 *        KEY_LONG_PRESS            KEY_EVENT_DOWN
 *        KEY_REPEAT                KEY_REPEAT or KEY_LONG_PRESS
 *        KEY_EVENT_UP              KEY_EVENT_DOWN KEY_LONG_PRESS, KEY_REPEAT
 *  [UT function]:ut_is_legal_key_type
 *
 * PARAMETERS
 *  curr_mmi_key_type     :[IN]  curr_mmi_key_type
 *  pre_mmi_key_type      :[IN]  pre_mmi_key_type
 *  cat                   :[IN]  TWO_STEP_KEY or NON_TWO_STEP_KEY
 * RETURNS
 *  MMI_TRUE if legal mmi key type input or MMI_FALSE
 *****************************************************************************/
static MMI_BOOL is_legal_key_type(S16 curr_mmi_key_type, S16 pre_mmi_key_type, U8 cat)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < KEY_TYPE_TRANS_TBL_NUM; i++)
    {
        if (GET_CAT(g_key_type_trans[i]) & cat)
        {
            if (curr_mmi_key_type == GET_CUR_KEY_TYPE(g_key_type_trans[i]) &&
                pre_mmi_key_type == GET_PRE_KEY_TYPE(g_key_type_trans[i]))
            {
                return MMI_TRUE;
            }
        }
    }
    return MMI_FALSE;
}


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + The following function is the operation for key code mapping table:
 +    1.get_mmi_key_code
 +    2.get_device_key_code
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

 /*****************************************************************************
 * FUNCTION
 *  get_mmi_key_code
 * DESCRIPTION
 *  This function is used to get the mmi key code that correspond to device_key_code 
 *  in g_mmi_frm_key_mapp_table.
 *  [Attention point]:
 *      1. if device_key_code is not in mapping table, KEY_INVALID will be got.
 *  [UT function]: ut_get_mmi_key_code
 *
 * PARAMETERS
 *  device_key_code     :[IN] device key code
 * RETURNS
 *  mmi key code
 *****************************************************************************/
static S16 get_mmi_key_code(U8 device_key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < KEY_CODE_MAP_TBL_NUM; i++)
    {
        if (device_key_code == g_key_code_map[i].device_key_code)
        {
            return g_key_code_map[i].mmi_key_code;
        }
    }
    return KEY_INVALID;
}


/*****************************************************************************
 * FUNCTION
 *  get_device_key_code
 * DESCRIPTION
 *  This function is used to get device key code by mmi key code from key map table
 *  [Attention point]:
 *     1. if the mmi key code is not in the mapping table, DEVICE_KEY_NONE will be got
 *
 *  [UT function]: ut_get_device_key_code
 * PARAMETERS
 *  mmi_key_code       :[IN]  mmi key code
 *
 * RETURNS
 *  device key code
 *****************************************************************************/
static U8 get_device_key_code(U8 mmi_key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < KEY_CODE_MAP_TBL_NUM; i++)
    {
        if (mmi_key_code == g_key_code_map[i].mmi_key_code)
        {
            return g_key_code_map[i].device_key_code;
        }
    }
    return DEVICE_KEY_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  write_look_ahead_buffer
 * DESCRIPTION
 *  This function is used to write device key events to look ahead buffer
 *  
 *
 *  [UT function]: ut_write_look_ahead_buffer
 * PARAMETERS
 *  dev_evt_p       :[IN] device key event 
 *
 * RETURNS
 *  MMI_TRUE if write a device key event to look ahead buffer successfully
 *****************************************************************************/
static MMI_BOOL write_look_ahead_buffer(dev_key_evt_struct *dev_evt_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_key_cntx.num_look_ahead == LOOK_AHEAD_BUF_LEN)
    {
    #ifndef __MMI_FRM_KEY_EVENT_UT__
        MMI_ASSERT(0);
    #endif
        return MMI_FALSE;
    }
	memcpy(&g_key_cntx.look_ahead[g_key_cntx.w_look_ahead],
        dev_evt_p,
		sizeof(dev_key_evt_struct));
	++g_key_cntx.w_look_ahead;
	g_key_cntx.w_look_ahead %= LOOK_AHEAD_BUF_LEN;
    g_key_cntx.num_look_ahead++;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  read_look_ahead_buffer
 * DESCRIPTION
 *  This function is used to get device key events from look ahead buffer
 *  
 *
 *  [UT function]: ut_read_look_ahead_buffer
 * PARAMETERS
 *  dev_evt_p       :[OUT] device key event 
 *
 * RETURNS
 *  MMI_TRUE if get a device key event
 *****************************************************************************/
static MMI_BOOL read_look_ahead_buffer(dev_key_evt_struct *dev_evt_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (g_key_cntx.num_look_ahead == 0)
    {
        return MMI_FALSE;
    }
	memcpy(dev_evt_p, 
		&g_key_cntx.look_ahead[g_key_cntx.r_look_ahead],
		sizeof(dev_key_evt_struct));
	++g_key_cntx.r_look_ahead;
	g_key_cntx.r_look_ahead %= LOOK_AHEAD_BUF_LEN;
    g_key_cntx.num_look_ahead--;
	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  is_need_write_back
 * DESCRIPTION
 *  This function is used to check if the device key event should be write
 *  back to look ahead buffer when clear key events
 *  
 *  Events need to be write back
 *     1. UP event if the key is exist in key data buffer
 *     2. END key's down/longpress/up
 *  Only on instance can be exist in the write back event set.
 *
 *  [UT function]: ut_is_need_write_back
 * PARAMETERS
 *  dev_p       :[IN] device key event
 *  buf         :[IN] temp buffer which store write back events
 *  len         :[IN] temp buffer len
 *
 * RETURNS
 *  MMI_TRUE if this event should be write back to look ahead buffer
 *****************************************************************************/
static MMI_BOOL is_need_write_back(dev_key_evt_struct *dev_p, dev_key_evt_struct *buf, U8 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL r = MMI_FALSE;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dev_p->device_key_code == DEVICE_KEY_END)
    {
        if (dev_p->device_key_type == DRV_WM_KEYPRESS ||
            dev_p->device_key_type == DRV_WM_KEYLONGPRESS ||
            dev_p->device_key_type == DRV_WM_KEYRELEASE)
        {
            r = MMI_TRUE;
        }        
    }
    else
    {
        if ((dev_p->device_key_type == DRV_WM_KEYRELEASE) &&
            (search_key_data(get_mmi_key_code(dev_p->device_key_code)) != -1))
        {
            r = MMI_TRUE;
        }
    }

    if (r == MMI_TRUE)
    {
        for (i = len - 1; i >= 0; i--)
        {
            if ((dev_p->device_key_code == buf[i].device_key_code) &&
                (dev_p->device_key_type == buf[i].device_key_type))
            {
                if (dev_p->device_key_code == DEVICE_KEY_END)
                {
                    /* for the case END UP/END DOWN/END UP in key buffer */
                    if ((dev_p->device_key_type == DRV_WM_KEYRELEASE) && (i == 0))
                    {
                        r = MMI_TRUE;
                    }
                    else
                    {
                        r = MMI_FALSE;
                    }    
                }
                else
                {
                    r = MMI_FALSE;
                }    
                break;
            }
        }
    }
    return r;
}

/*****************************************************************************
 * FUNCTION
 *  get_dev_key_evt
 * DESCRIPTION
 *  This function is used to get device key events from look ahead buffer or key buffer.
 *  
 *
 *  [UT function]: ut_get_dev_key_evt
 * PARAMETERS
 *  dev_evt_p       :[IN]  mmi key code
 *
 * RETURNS
 *  MMI_TRUE if get a device key event
 *****************************************************************************/
static MMI_BOOL get_dev_key_evt(dev_key_evt_struct *dev_evt_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_FRM_KEY_EVENT_UT__
    kbd_data k;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (read_look_ahead_buffer(dev_evt_p) == MMI_TRUE)
    {
        return MMI_TRUE;
    }
#ifndef __MMI_FRM_KEY_EVENT_UT__
    else if (g_key_cntx.keypad_ptr && ((*(g_key_cntx.keypad_ptr))(&k) == MMI_TRUE))
    {
        dev_evt_p->device_key_code = k.Keydata[0];
        dev_evt_p->device_key_type = k.Keyevent;
        dev_evt_p->is_clear = MMI_FALSE;
        report_key_evt(k.Keydata[0], k.Keyevent);
        return MMI_TRUE;
    }
#endif    
    return MMI_FALSE;
}



/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + key code convert functions:
 +  1.get_rotated_mmi_key_code
 +  2.enter_to_lsk
 +
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*****************************************************************************
 * FUNCTION
 *  get_rotated_mmi_key_code
 * DESCRIPTION
 *  This function is used to get rotated mmi key code
 *  [UT function]: ut_get_rotated_mmi_key_code
 * PARAMETERS
 *  mmi_key_code  :[IN] mmi key code
 *
 * RETURNS
 *  rotate mmi key code
 *****************************************************************************/
#ifdef __MMI_SCREEN_ROTATE__ 
static S16 get_rotated_mmi_key_code(S16 mmi_key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 j;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < KPD_ROT_DAT_TBL_NUM; i++)
    {
        if (g_kpd_rot_data[i].rot_degree == mmi_frm_get_screen_rotate())
        {
            for (j = 0; j < DIR_KEY_NUM; j++)
            {
                if (g_dir_key[j] == mmi_key_code)
                {
                    return (S16)g_dir_key[(j + g_kpd_rot_data[i].step + DIR_KEY_NUM) % DIR_KEY_NUM];
                }
            }
        }
    }
    return mmi_key_code;    
}
#endif


/*****************************************************************************
 * FUNCTION
 *  enter_to_lsk
 * DESCRIPTION
 *  This function is used to change KEY_ENTER to KEY_LSK
 *  [UT function]: ut_enter_to_lsk 
 * PARAMETERS
 *  mmi_key_code  :[IN] mmi key code
 *
 * RETURNS
 *  mmi key code
 *****************************************************************************/
static S16 enter_to_lsk(S16 mmi_key_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_key_code == KEY_ENTER &&
        currKeyFuncPtrs[KEY_ENTER][KEY_EVENT_UP] == NULL &&
        currKeyFuncPtrs[KEY_ENTER][KEY_EVENT_DOWN] == NULL &&
        currKeyFuncPtrs[KEY_ENTER][KEY_HALF_PRESS_DOWN] == NULL &&
        currKeyFuncPtrs[KEY_ENTER][KEY_REPEAT] == NULL && 
        currKeyFuncPtrs[KEY_ENTER][KEY_LONG_PRESS] == NULL)
    {
        return KEY_LSK;
    }
    else
    {
        return mmi_key_code;
    }        
} 


/*****************************************************************************
 * FUNCTION
 *  mmi_key_code_convert
 * DESCRIPTION
 *  This function is used to do mmi key code conversion
 *
 * PARAMETERS
 *  mmi_key_code     :[IN] mmi key code
 *
 * RETURNS
 *  mmi key code
 *****************************************************************************/
static S16 mmi_key_code_convert(S16 mmi_key_code, U8 dev_key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 convert_key_code = mmi_key_code;
    S32 i;
    S32 index;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dev_key_type == DRV_WM_KEYPRESS)
    {
        for (i = 0; i < KEY_CODE_CVT_TBL_NUM; i++)
        {
            if (g_key_code_cvt_tbl[i] != NULL)
            { 
                convert_key_code = (* g_key_code_cvt_tbl[i])(mmi_key_code);
                if (convert_key_code != mmi_key_code)
                {
                    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_KEY_CONVERT_KEY_CODE, mmi_key_code, convert_key_code);            
                    break;
                }
            }    
        }
    }
    else
    {
        if ((index = search_key_data(mmi_key_code)) != -1)
        {
            key_data_struct data;
            get_key_data(&data, (U8)index);
            convert_key_code = data.cvt_code;
        }
    }
    return  convert_key_code; 
}


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + check function
 +
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*****************************************************************************
 * FUNCTION
 *  backlight_check
 * DESCRIPTION
 *  This function is use to check backlight state
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_SLEEP_OUT_BACKLIGHT_ON__) 
static MMI_BOOL backlight_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if ((IsBacklightOn() == MMI_FALSE))
    {
        mmi_idle_key_event_backlight_check();
        /* only allow key action when backlight is controlled by AP */
        if (!(mmi_gpio_get_backlight_timer_state() == MMI_GPIO_BACKLIGHT_TIMER_STATE_NO_TIMER))
        {
            ret = MMI_TRUE;
            MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_KEY_DISABLE_ACTION_BY_BACKLIGTH);
        }
    }
    return ret;    
}
#endif /* defined(__MMI_SLEEP_OUT_BACKLIGHT_ON__) */


/*****************************************************************************
 * FUNCTION
 *  pen_check
 * DESCRIPTION
 *  This function is use to check pen state
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__) 
static MMI_BOOL pen_check()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool is_pen_enabled, is_pen_down;
               
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pen_get_state(&is_pen_enabled, &is_pen_down);
    return  (is_pen_down == KAL_TRUE) ? MMI_TRUE : MMI_FALSE;  
}
#endif /* defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__) */


/*****************************************************************************
 * FUNCTION
 *  exec_check_func
 * DESCRIPTION
 *  This function is use to execute check functions
 * PARAMETERS
 *  void
 *
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL exec_check_func(key_data_struct *data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    S32 i;
    MMI_BOOL is_check = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __KBD_2STEP_KEY_SUPPORT__    
    if (data_p->is_2step == MMI_TRUE)
    {
        if (data_p->mmi_key_type == KEY_HALF_PRESS_DOWN)
        {
            is_check = MMI_TRUE;
        }
    }
    else
#endif /* __KBD_2STEP_KEY_SUPPORT__ */    
    {
        if (data_p->mmi_key_type == KEY_EVENT_DOWN)
        {
            is_check = MMI_TRUE;
        }
    }
    if (is_check == MMI_TRUE)
    {
        for (i = 0; i < CHK_FUNC_TBL_NUM; i++)
        {
            if ((g_check[i] != NULL) && ((* g_check[i])() == MMI_TRUE))
            {
                init_key_data_buf();
                return MMI_TRUE;
            }
        }
    }
    return MMI_FALSE;
}


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + get key handler functions
 +
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


/*****************************************************************************
 * FUNCTION
 *  get_any_key_handler
 * DESCRIPTION
 *  This function is used to get any key handler.
 * PARAMETERS
 *  mmi_key_code  :[IN] mmi key code
 *  mmi_key_type  :[IN] mmi key type
 *
 * RETURNS
 *  key handler pointer
 *****************************************************************************/
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__ 
static FuncPtr get_any_key_handler(S16 mmi_key_code, S16 mmi_key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FuncPtr currFuncPtr = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_key_code >= MAX_KEYS)
    {
        currFuncPtr = anyKeyFuncPtrs[mmi_key_type];
        if ((mmi_key_type == KEY_REPEAT) && (currFuncPtr == NULL))
        {
            currFuncPtr = anyKeyFuncPtrs[KEY_EVENT_DOWN];
            MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_KEY_ANY_KEY_REPEAT_TO_DOWN, mmi_key_code, mmi_key_type, currFuncPtr);
        }
        else
        {
            MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_KEY_GET_ANY_KEY_HDLR, mmi_key_code, mmi_key_type, currFuncPtr);
        }
    }
    return  currFuncPtr;       
}
#endif


/*****************************************************************************
 * FUNCTION
 *  get_repeat_key_handler
 * DESCRIPTION
 *  This function is used to get repeat key handler
 * PARAMETERS
 *  mmi_key_code  :[IN] mmi key code
 *  mmi_key_type  :[IN] mmi key type
 *
 * RETURNS
 *  key handler pointer
 *****************************************************************************/
static FuncPtr get_repeat_key_handler(S16 mmi_key_code, S16 mmi_key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FuncPtr currFuncPtr = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if ((mmi_key_type == KEY_REPEAT) && 
        (currKeyFuncPtrs[mmi_key_code][KEY_REPEAT] == NULL) && 
        (mmi_key_code != KEY_RSK) && 
        (mmi_key_code != KEY_LSK) &&
        (mmi_key_code != KEY_ENTER) && (mmi_key_code < MAX_KEYS))
    {
            currFuncPtr = currKeyFuncPtrs[mmi_key_code][KEY_EVENT_DOWN];
            MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_KEY_REPEAT_TO_DOWN);
    }
    return currFuncPtr;
}


/*****************************************************************************
 * FUNCTION
 *  get_mini_tab_bar_key_handler
 * DESCRIPTION
 *  This function is used to mini tab bar key handler
 * PARAMETERS
 *  mmi_key_code  :[IN] mmi key code
 *  mmi_key_type  :[IN] mmi key type
 *
 * RETURNS
 *  key handler pointer
 *****************************************************************************/
#ifdef __MMI_WGUI_MINI_TAB_BAR__  
static FuncPtr get_mini_tab_bar_key_handler(S16 mmi_key_code, S16 mmi_key_type) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FuncPtr currFuncPtr = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/      
    if (wgui_if_mini_tab_bar_enable() == MMI_TRUE && mmi_key_code == KEY_LEFT_ARROW && mmi_key_type == KEY_EVENT_DOWN)
    {
        if (mmi_key_code == KEY_LEFT_ARROW && mmi_key_type == KEY_EVENT_DOWN)
        {
            currFuncPtr = wgui_mini_tab_bar_goto_prev;
            MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_KEY_TAB_BAR_HDLR);
        }
        else if (mmi_key_code == KEY_RIGHT_ARROW && mmi_key_type == KEY_EVENT_DOWN)
        {
            currFuncPtr = wgui_mini_tab_bar_goto_next;
            MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_KEY_TAB_BAR_HDLR);            
        }            
    }   
    return  currFuncPtr;  
}
#endif /* __MMI_WGUI_MINI_TAB_BAR__ */ 


/*****************************************************************************
 * FUNCTION
 *  get_screen_snapshot_key_handler
 * DESCRIPTION
 *  This function is used to screen snapshot key handler
 * PARAMETERS
 *  mmi_key_code  :[IN] mmi key code
 *  mmi_key_type  :[IN] mmi key type
 *
 * RETURNS
 *  key handler pointer
 *****************************************************************************/
#ifdef __MMI_SCREEN_SNAPSHOT__ 
static FuncPtr get_screen_snapshot_key_handler(S16 mmi_key_code, S16 mmi_key_type) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FuncPtr currFuncPtr = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/      
    if ((mmi_key_type == KEY_LONG_PRESS) && (mmi_key_code == KEY_CAMERA) && (currKeyFuncPtrs[KEY_CAMERA][KEY_LONG_PRESS] == NULL))
    {
        currFuncPtr = mmi_camera_scr_snapshot;
        MMI_TRACE(MMI_FW_TRC_G6_FRM_DETAIL, TRC_MMI_FRM_KEY_CAMERA_SNAP);
    }   
    return  currFuncPtr;  
}
#endif /* __MMI_SCREEN_SNAPSHOT__ */


/*****************************************************************************
 * FUNCTION
 *  get_lsk_send2_key_handler
 * DESCRIPTION
 *  This function is used to lsk send2 key handler
 * PARAMETERS
 *  mmi_key_code  :[IN] mmi key code
 *  mmi_key_type  :[IN] mmi key type
 *
 * RETURNS
 *  key handler pointer
 *****************************************************************************/
#ifdef __LSK_KEYSEND2_IN_ONE__ 
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
#endif /* __LSK_KEYSEND2_IN_ONE__ */


/*****************************************************************************
 * FUNCTION
 *  get_default_key_handler
 * DESCRIPTION
 *  This function is used to default key handler
 * PARAMETERS
 *  mmi_key_code  :[IN] mmi key code
 *  mmi_key_type  :[IN] mmi key type
 *
 * RETURNS
 *  key handler pointer
 *****************************************************************************/
static FuncPtr get_default_key_handler(S16 mmi_key_code, S16 mmi_key_type) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (mmi_key_code < MAX_KEYS)
    {
        return currKeyFuncPtrs[mmi_key_code][mmi_key_type];
    }
    else
    {
        return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  get_key_handler
 * DESCRIPTION
 *  This function is used to get the final key handler
 * PARAMETERS
 *  mmi_key_code  :[IN] mmi key code
 *  mmi_key_type  :[IN] mmi key type
 *
 * RETURNS
 *  key handler pointer
 *****************************************************************************/ 
static FuncPtr get_key_handler(S16 mmi_key_code, S16 mmi_key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FuncPtr currFuncPtr = NULL;
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SPE_KEY_HDL_TBL_NUM; i++)
    {
        if ((currFuncPtr = (* g_key_handler[i])(mmi_key_code, mmi_key_type)) != NULL)
        {
            break;
        }
    }
    return currFuncPtr;     
}


/*****************************************************************************
 * FUNCTION
 *  is_need_report_to_l4
 * DESCRIPTION
 *  This function is used to judge if we need to report key event to L4.
 *
 * PARAMETERS
 *  dev_key_type       : [IN] device key type
 * RETURNS
 *  MMI_TRUE if need to report
 *****************************************************************************/
static MMI_BOOL is_need_report_to_l4(U8 dev_key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dev_key_type == DRV_WM_KEYPRESS || dev_key_type == DRV_WM_KEYRELEASE)
    {
        if ((g_key_cntx.key_event_report_mode == KEY_EVT_REPORT_HW_AT) || 
            (g_key_cntx.key_event_report_mode == KEY_EVT_REPORT_HW_ONLY) && (g_key_cntx.keypad_ptr == KBD_DRVIER_GET_KEY_FUNC))
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  report_key_evt
 * DESCRIPTION
 *  This function is used to report key event to L4C
 *
 * PARAMETERS
 *  dev_key_code       : [IN] device key code
 *  dev_key_type       : [IN] device key type
 * RETURNS
 *  void
 *****************************************************************************/
static void report_key_evt(U8 dev_key_code, U8 dev_key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_at_keypad_event_output_req_struct *local_data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == is_need_report_to_l4(dev_key_type))
    {
        Message.oslSrcId = MOD_MMI;
        Message.oslDestId = MOD_L4C;
        Message.oslMsgId = MSG_ID_MMI_AT_KEYPAD_EVENT_OUTPUT_REQ;
    
        local_data = (mmi_at_keypad_event_output_req_struct*) OslConstructDataPtr(sizeof(mmi_at_keypad_event_output_req_struct));
        local_data->keypad_status = dev_key_type;
        local_data->keypad_code = dev_key_code;
    
        Message.oslDataPtr = (oslParaType*) local_data;
        Message.oslPeerBuffPtr = NULL;
        OslMsgSendExtQueue(&Message);         
    }           
}


/*****************************************************************************
 * FUNCTION
 *  clam_check
 * DESCRIPTION
 *  This function is used to get the final key handler
 * PARAMETERS
 *  mmi_key_code  :[IN] mmi key code
 *  mmi_key_type  :[IN] mmi key type
 *
 * RETURNS
 *  key handler pointer
 *****************************************************************************/ 
#if defined (__MMI_SUBLCD_MASTER_MODE__)
static MMI_BOOL clam_check(S16 mmi_key_code, S16 mmi_key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static U16 CurrSubLCDScrnID = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsClamClose() && mmi_key_code == KEY_END)
    {
        if (mmi_key_code == KEY_END)
        {
            /*
             * When the clam is closed, the users should not press KEY_END.
             * If hardware mechanism is not good enough, we discard KEY_END here.
             */
             return MMI_TRUE
        }
        if (IsSubLCDInMasterMode())
        {
            if (mmi_key_type > KEY_EVENT_DOWN)
            {
                if (CurrSubLCDScrnID != GetSubLCActiveScreenId())
                {
                    return MMI_TRUE;
                }
            }
            else
            {
                CurrSubLCDScrnID = GetSubLCActiveScreenId();
            }
        }
        else
        {
            CurrSubLCDScrnID = 0;
        }

    }
    return MMI_FALSE;           
}
#endif

/* compatible for vendor */
void ExecuteCurrKeyHandler(S16 keyCode, S16 keyType)
{
    mmi_frm_exec_key_handler(keyCode, keyType);
}
void GetkeyInfo(U16 *keyCode, U16 *keyType)
{
    mmi_frm_get_key_info(keyCode, keyType);
}
FuncPtr GetKeyHandler(U16 keyCode, U16 keyType)
{
    return mmi_frm_get_key_handler(keyCode, keyType);
}
 
void SetGroupKeyHandler(FuncPtr funcPtr, PU16 keyCodes, U8 len, U16 keyType)
{
    mmi_frm_set_group_key_handler(funcPtr, keyCodes, len, keyType);
}
void ClearKeyHandler(U16 keyCode, U16 keyType)
{
    mmi_frm_clear_key_handler(keyCode, keyType);
}
void PowerAndEndKeyHandler(void)
{
    mmi_frm_set_power_end_key_handler();
}
void ClearKeyEvents(void)
{
    mmi_frm_clear_key_events();
}
void SetKeyHandler(FuncPtr funcPtr, U16 keyCode, U16 keyType)
{
    mmi_frm_set_key_handler(funcPtr, keyCode, keyType);
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + The following part is the unit test of key event handler
 +
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#ifdef __MMI_FRM_KEY_EVENT_UT__
extern MMI_BOOL key_data_cmp(key_data_struct *p, key_data_struct *q);
/*****************************************************************************
* FUNCTION
*  save_key_data
* DESCRIPTION
*  This function is used to save the key data buffer to another place
*
* PARAMETERS
*  buf_p    :[IN] memory to store key data
*  len_p    :[IN] memory to store buffer length
* RETURNS
*  void
*****************************************************************************/
void save_key_data(key_data_struct *buf_p, U8 *len_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 j;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *len_p = g_key_cntx.buf_len;
    for (j = 0; j < MAX_DECT_KEY_NUM; j++)
    {
        buf_p[j] = g_key_cntx.buffer[j];
    }
}


/*****************************************************************************
* FUNCTION
*  restore_key_data
* DESCRIPTION
*  This function is used to restore the key data buffer
*
* PARAMETERS
*  buf_p    :[IN] memory to store key data
*  len_p    :[IN] memory to store buffer length
* RETURNS
*  void
*****************************************************************************/
void restore_key_data(key_data_struct *buf_p, U8 *len_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    S32 j;
    
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    g_key_cntx.buf_len = *len_p;
    for (j = 0; j < MAX_DECT_KEY_NUM; j++)
    {
        g_key_cntx.buffer[j] = buf_p[j];
    }
}


/*****************************************************************************
 * FUNCTION
 *  ut_get_mmi_key_events
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0017
 * <Test Case Content> get frm level key event
 * <Test Case Number> 31
 * <Scenario>
 *    case1: detection event input
 *    case2: key code no mapping
 *    case3: 2step key, press -> release
 *    case4: 2step key, press -> full press
 *    case5: 2step key, full press->longpress
 *    case6: 2step key, longpress->repeat
 *    case7: 2step key, repeat-> repeat
 *    case8: 2step key, repeat->release
 *    case9: 2step key, longpress->release
 *    case10:2step key, full press -> release
 *    case11:2step key, release -> release
 *    case12:2step key, full press->half press
 *    case13:2step key, half press->half press
 *    case14:2step key, release -> longpress
 *    case15:2step key, release -> repeat
 *    case16:2step key, release -> full press
 *    case17:2step key, release->press
 *    case18:non-2step, release->press
 *    case19:non-2step, press->release
 *    case20:non-2step, press->longpress
 *    case21:non-2step, longpress -> repeat
 *    case22:non-2step, repeat->repeat
 *    case23:non-2step, longpress->release
 *    case24:non-2step, repeat->release
 *    case25:non-2step, release->release
 *    case26:non-2step, release->longpress
 *    case27:non-2step, release->repeat
 *    case28:non-2step, press-> press
 *    case29:non-2step, repeat->longpress
 *    case30:non-2step, press->repeat
 *    case31:non-2step, full press
 * <Expected Result>
 *    case1: get KEY_EVENT_DECT
 *    case2: get KEY_INVALID, ERR_KEY_CODE  
 *    case3: get up
 *    case4: get full down
 *    case5: get long press
 *    case6: get repeat
 *    case7: get repeat
 *    case8: get release
 *    case9: get release
 *    case10:get release
 *    case11:get ERR_KEY_EVT_TRANS
 *    case12:get ERR_KEY_EVT_TRANS
 *    case13:get ERR_KEY_EVT_TRANS
 *    case14:get ERR_KEY_EVT_TRANS
 *    case15:get ERR_KEY_EVT_TRANS
 *    case16:get ERR_KEY_EVT_TRANS
 *    case17:get half down
 *    case18:get down
 *    case19:get up
 *    case20:get long press
 *    case21:get repeat
 *    case22:get repeat
 *    case23:get up
 *    case24:get up
 *    case25:get up
 *    case26:get ERR_KEY_EVT_TRANS
 *    case27:get ERR_KEY_EVT_TRANS
 *    case28:get ERR_KEY_EVT_TRANS
 *    case29:get ERR_KEY_EVT_TRANS
 *    case30:get ERR_KEY_EVT_TRANS
 *    case31:get ERR_KEY_EVENT
 *
 * </test case description>
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret  ut_get_mmi_key_events(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dev_key_evt_struct  device_key;
    mmi_key_evt_struct     mmi_key;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* case 1 */
#if defined(__TWO_KEY_DETECTION_SWITCHABLE__) || defined(__THREE_KEY_DETECTION_SWITCHABLE__)
    device_key.device_key_type = DRV_WM_ENABLE_TWOKEY_DETECTION;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_type == KEY_EVENT_DECT);
#endif

#if defined(__THREE_KEY_DETECTION_SWITCHABLE__)
    device_key.device_key_type = DRV_WM_ENABLE_THREEKEY_DETECTION;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_type == KEY_EVENT_DECT);
#endif
    device_key.device_key_type = DRV_WM_DISABLE_MULTIKEY_DETECTION;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_type == KEY_EVENT_DECT);

    /* case 2 */
    device_key.device_key_code = DEVICE_KEY_EMAIL;
    device_key.device_key_type = DRV_WM_KEYPRESS;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_type == ERR_KEY_CODE);

    /* case 3 */
#ifdef __KBD_2STEP_KEY_SUPPORT__
    g_key_cntx._2step_key.mmi_key_code = KEY_CAMERA;
    g_key_cntx.buffer[0].mmi_key_code = KEY_CAMERA;
    g_key_cntx.buffer[0].mmi_key_type = KEY_HALF_PRESS_DOWN;
    device_key.device_key_code = DEVICE_KEY_FUNCTION;
    device_key.device_key_type = DRV_WM_KEYRELEASE;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_code == KEY_CAMERA);
    MMI_ASSERT(mmi_key.mmi_key_type == KEY_EVENT_UP);

    /* case 4 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_CAMERA;
    g_key_cntx.buffer[0].mmi_key_type = KEY_HALF_PRESS_DOWN;    
    device_key.device_key_code = DEVICE_KEY_FUNCTION;
    device_key.device_key_type = DRV_WM_KEYFULLPRESS;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_code == KEY_CAMERA);
    MMI_ASSERT(mmi_key.mmi_key_type == KEY_FULL_PRESS_DOWN);

    /* case 5 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_CAMERA;
    g_key_cntx.buffer[0].mmi_key_type = KEY_FULL_PRESS_DOWN; 
    device_key.device_key_code = DEVICE_KEY_FUNCTION;
    device_key.device_key_type = DRV_WM_KEYLONGPRESS;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_code == KEY_CAMERA);
    MMI_ASSERT(mmi_key.mmi_key_type == KEY_LONG_PRESS);

    /* case 6 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_CAMERA;
    g_key_cntx.buffer[0].mmi_key_type = KEY_LONG_PRESS;     
    device_key.device_key_code = DEVICE_KEY_FUNCTION;
    device_key.device_key_type = DRV_WM_KEYREPEATED;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_code == KEY_CAMERA);
    MMI_ASSERT(mmi_key.mmi_key_type == KEY_REPEAT);

    /* case 7 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_CAMERA;
    g_key_cntx.buffer[0].mmi_key_type = KEY_REPEAT;     
    device_key.device_key_code = DEVICE_KEY_FUNCTION;
    device_key.device_key_type = DRV_WM_KEYREPEATED;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_code == KEY_CAMERA);
    MMI_ASSERT(mmi_key.mmi_key_type == KEY_REPEAT);    

    /* case 8 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_CAMERA;
    g_key_cntx.buffer[0].mmi_key_type = KEY_REPEAT;     
    device_key.device_key_code = DEVICE_KEY_FUNCTION;
    device_key.device_key_type = DRV_WM_KEYRELEASE;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_code == KEY_CAMERA);
    MMI_ASSERT(mmi_key.mmi_key_type == KEY_EVENT_UP);

    /* case 9 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_CAMERA;
    g_key_cntx.buffer[0].mmi_key_type = KEY_LONG_PRESS;     
    device_key.device_key_code = DEVICE_KEY_FUNCTION;
    device_key.device_key_type = DRV_WM_KEYRELEASE;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_code == KEY_CAMERA);
    MMI_ASSERT(mmi_key.mmi_key_type == KEY_EVENT_UP);

    /* case 10 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_CAMERA;
    g_key_cntx.buffer[0].mmi_key_type = KEY_FULL_PRESS_DOWN;     
    device_key.device_key_code = DEVICE_KEY_FUNCTION;
    device_key.device_key_type = DRV_WM_KEYRELEASE;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_code == KEY_CAMERA);
    MMI_ASSERT(mmi_key.mmi_key_type == KEY_EVENT_UP);

    /* case 11 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_CAMERA;
    g_key_cntx.buffer[0].mmi_key_type = KEY_EVENT_UP;     
    device_key.device_key_code = DEVICE_KEY_FUNCTION;
    device_key.device_key_type = DRV_WM_KEYRELEASE;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_type == ERR_KEY_EVT_TRANS);

    /* case 12 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_CAMERA;
    g_key_cntx.buffer[0].mmi_key_type = KEY_FULL_PRESS_DOWN;     
    device_key.device_key_code = DEVICE_KEY_FUNCTION;
    device_key.device_key_type = DRV_WM_KEYPRESS;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_type == ERR_KEY_EVT_TRANS);

    /* case 13 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_CAMERA;
    g_key_cntx.buffer[0].mmi_key_type = KEY_HALF_PRESS_DOWN;     
    device_key.device_key_code = DEVICE_KEY_FUNCTION;
    device_key.device_key_type = DRV_WM_KEYPRESS;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_type == ERR_KEY_EVT_TRANS);

    /* case 14 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_CAMERA;
    g_key_cntx.buffer[0].mmi_key_type = KEY_EVENT_UP;     
    device_key.device_key_code = DEVICE_KEY_FUNCTION;
    device_key.device_key_type = DRV_WM_KEYLONGPRESS;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_type == ERR_KEY_EVT_TRANS);

    /* case 15 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_CAMERA;
    g_key_cntx.buffer[0].mmi_key_type = KEY_EVENT_UP;     
    device_key.device_key_code = DEVICE_KEY_FUNCTION;
    device_key.device_key_type = DRV_WM_KEYREPEATED;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_type == ERR_KEY_EVT_TRANS);

    /* case 16 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_CAMERA;
    g_key_cntx.buffer[0].mmi_key_type = KEY_EVENT_UP;     
    device_key.device_key_code = DEVICE_KEY_FUNCTION;
    device_key.device_key_type = DRV_WM_KEYFULLPRESS;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_type == ERR_KEY_EVT_TRANS);

    /* case 17 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_CAMERA;
    g_key_cntx.buffer[0].mmi_key_type = KEY_EVENT_UP;     
    device_key.device_key_code = DEVICE_KEY_FUNCTION;
    device_key.device_key_type = DRV_WM_KEYPRESS;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_code == KEY_CAMERA);
    MMI_ASSERT(mmi_key.mmi_key_type == KEY_HALF_PRESS_DOWN);
#endif
    /* case 18 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_0;
    g_key_cntx.buffer[0].mmi_key_type = KEY_EVENT_UP;     
    device_key.device_key_code = DEVICE_KEY_0;
    device_key.device_key_type = DRV_WM_KEYPRESS;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_code == KEY_0);
    MMI_ASSERT(mmi_key.mmi_key_type == KEY_EVENT_DOWN);

    /* case 19 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_0;
    g_key_cntx.buffer[0].mmi_key_type = KEY_EVENT_DOWN;     
    device_key.device_key_code = DEVICE_KEY_0;
    device_key.device_key_type = DRV_WM_KEYRELEASE;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_code == KEY_0);
    MMI_ASSERT(mmi_key.mmi_key_type == KEY_EVENT_UP);

    /* case 20 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_0;
    g_key_cntx.buffer[0].mmi_key_type = KEY_EVENT_DOWN;     
    device_key.device_key_code = DEVICE_KEY_0;
    device_key.device_key_type = DRV_WM_KEYLONGPRESS;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_code == KEY_0);
    MMI_ASSERT(mmi_key.mmi_key_type == KEY_LONG_PRESS);

    /* case 21 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_0;
    g_key_cntx.buffer[0].mmi_key_type = KEY_LONG_PRESS;     
    device_key.device_key_code = DEVICE_KEY_0;
    device_key.device_key_type = DRV_WM_KEYREPEATED;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_code == KEY_0);
    MMI_ASSERT(mmi_key.mmi_key_type == KEY_REPEAT); 

    /* case 22 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_0;
    g_key_cntx.buffer[0].mmi_key_type = KEY_REPEAT;     
    device_key.device_key_code = DEVICE_KEY_0;
    device_key.device_key_type = DRV_WM_KEYREPEATED;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_code == KEY_0);
    MMI_ASSERT(mmi_key.mmi_key_type == KEY_REPEAT);

    /* case 23 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_0;
    g_key_cntx.buffer[0].mmi_key_type = KEY_LONG_PRESS;     
    device_key.device_key_code = DEVICE_KEY_0;
    device_key.device_key_type = DRV_WM_KEYRELEASE;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_code == KEY_0);
    MMI_ASSERT(mmi_key.mmi_key_type == KEY_EVENT_UP);

    /* case 24 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_0;
    g_key_cntx.buffer[0].mmi_key_type = KEY_REPEAT;     
    device_key.device_key_code = DEVICE_KEY_0;
    device_key.device_key_type = DRV_WM_KEYRELEASE;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_code == KEY_0);
    MMI_ASSERT(mmi_key.mmi_key_type == KEY_EVENT_UP);

    /* case 25 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_0;
    g_key_cntx.buffer[0].mmi_key_type = KEY_EVENT_UP;     
    device_key.device_key_code = DEVICE_KEY_0;
    device_key.device_key_type = DRV_WM_KEYRELEASE;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_type == ERR_KEY_EVT_TRANS);


    /* case 26 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_0;
    g_key_cntx.buffer[0].mmi_key_type = KEY_EVENT_UP;     
    device_key.device_key_code = DEVICE_KEY_0;
    device_key.device_key_type = DRV_WM_KEYLONGPRESS;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_type == ERR_KEY_EVT_TRANS);

    /* case 27 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_0;
    g_key_cntx.buffer[0].mmi_key_type = KEY_EVENT_UP;     
    device_key.device_key_code = DEVICE_KEY_0;
    device_key.device_key_type = DRV_WM_KEYREPEATED;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_type == ERR_KEY_EVT_TRANS);

    /* case 28 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_0;
    g_key_cntx.buffer[0].mmi_key_type = KEY_EVENT_DOWN;     
    device_key.device_key_code = DEVICE_KEY_0;
    device_key.device_key_type = DRV_WM_KEYPRESS;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_type == ERR_KEY_EVT_TRANS);

    /* case 29 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_0;
    g_key_cntx.buffer[0].mmi_key_type = KEY_REPEAT;     
    device_key.device_key_code = DEVICE_KEY_0;
    device_key.device_key_type = DRV_WM_KEYLONGPRESS;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_type == ERR_KEY_EVT_TRANS);

    /* case 30 */
    g_key_cntx.buffer[0].mmi_key_code = KEY_0;
    g_key_cntx.buffer[0].mmi_key_type = KEY_EVENT_DOWN;     
    device_key.device_key_code = DEVICE_KEY_0;
    device_key.device_key_type = DRV_WM_KEYREPEATED;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_type == ERR_KEY_EVT_TRANS);

    /* case 31 */
    device_key.device_key_code = DEVICE_KEY_0;
    device_key.device_key_type = DRV_WM_KEYFULLPRESS;
    get_mmi_key_events(&device_key, &mmi_key);
    MMI_ASSERT(mmi_key.mmi_key_type == ERR_KEY_EVENT);
    kal_prompt_trace(MOD_MMI, "[UT_KEY] test get_mmi_key_events PASS");
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  ut_post_update_key_data_buf
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0016
 * <Test Case Content> post update key cntx
 * <Test Case Number> 6
 * <Scenario>
 *    case1: 2 key in buffer, receive 2 up
 *    case2: 2 key in buffer, receive 1 up
 *    case3: 1 key in buffer, receive 1 up
 *    case4: 2 key in buffer, receive, other event
 *    case5: 1 key in buffer, receive, other event
 *    case6: no key in buffer, receive some key code up
 *    case7: no key in buffer, receive some key other event 
 *
 * <Expected Result>
 *    case1: 2 remove
 *    case2: 1 remove 
 *    case3: 1 remove
 *    case4: no change
 *    case5: no change
 *    case6: no change
 *    case7: no change
 *
 * </test case description>
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 static mmi_ret ut_post_update_key_data_buf(void *para)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     key_data_struct data[MAX_DECT_KEY_NUM];
     U8 len;
     U8 keypad_status;    
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     keypad_status = g_key_cntx.keypad_status;
     save_key_data(data, &len);
     
     init_key_data_buf();
     SET_KEY_DET_MODE(g_key_cntx.keypad_status, (U8)kbd_2_keys_det_mode);
     g_key_cntx.buffer[0].mmi_key_code = KEY_1;
     g_key_cntx.buffer[1].mmi_key_code = KEY_2;
     g_key_cntx.buffer[0].mmi_key_type = KEY_EVENT_UP;
     g_key_cntx.buffer[1].mmi_key_type = KEY_EVENT_UP;
     g_key_cntx.buf_len = 2;
     post_update_key_data_buf();
     MMI_ASSERT(g_key_cntx.buffer[0].mmi_key_code == KEY_INVALID);
     MMI_ASSERT(g_key_cntx.buffer[1].mmi_key_code == KEY_INVALID);
     
     g_key_cntx.buffer[0].mmi_key_code = KEY_1;
     g_key_cntx.buffer[1].mmi_key_code = KEY_2;
     g_key_cntx.buffer[0].mmi_key_type = KEY_EVENT_UP;
     g_key_cntx.buffer[1].mmi_key_type = KEY_EVENT_DOWN;
     g_key_cntx.buf_len = 2;
     post_update_key_data_buf();
     MMI_ASSERT(g_key_cntx.buffer[0].mmi_key_code == KEY_2);
     MMI_ASSERT(g_key_cntx.buffer[1].mmi_key_code == KEY_INVALID);
     
     g_key_cntx.buffer[0].mmi_key_code = KEY_1;
     g_key_cntx.buffer[1].mmi_key_code = KEY_2;
     g_key_cntx.buffer[0].mmi_key_type = KEY_EVENT_DOWN;
     g_key_cntx.buffer[1].mmi_key_type = KEY_EVENT_UP;
     g_key_cntx.buf_len = 2;
     post_update_key_data_buf();
     MMI_ASSERT(g_key_cntx.buffer[0].mmi_key_code == KEY_1);
     MMI_ASSERT(g_key_cntx.buffer[1].mmi_key_code == KEY_INVALID);  
     
     
     g_key_cntx.buffer[0].mmi_key_code = KEY_1;
     g_key_cntx.buffer[1].mmi_key_code = KEY_INVALID;
     g_key_cntx.buffer[0].mmi_key_type = KEY_EVENT_UP;
     g_key_cntx.buf_len = 1;
     post_update_key_data_buf();
     MMI_ASSERT(g_key_cntx.buffer[0].mmi_key_code == KEY_INVALID);
     MMI_ASSERT(g_key_cntx.buffer[1].mmi_key_code == KEY_INVALID);
     
     g_key_cntx.buffer[0].mmi_key_code = KEY_1;
     g_key_cntx.buffer[1].mmi_key_code = KEY_2;
     g_key_cntx.buffer[0].mmi_key_type = KEY_REPEAT;
     g_key_cntx.buffer[1].mmi_key_type = KEY_REPEAT;
     g_key_cntx.buf_len = 2;
     post_update_key_data_buf();
     MMI_ASSERT(g_key_cntx.buffer[0].mmi_key_code == KEY_1);
     MMI_ASSERT(g_key_cntx.buffer[1].mmi_key_code == KEY_2);
     
     restore_key_data(data, &len);
     g_key_cntx.keypad_status = keypad_status;
     kal_prompt_trace(MOD_MMI, "[UT_KEY] test post_update_key_data_buf PASS");
     return MMI_RET_OK;	
}


/*****************************************************************************
 * FUNCTION
 *  ut_pre_update_key_data_buf
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0015
 * <Test Case Content> pre update key cntx
 * <Test Case Number> 5
 * <Scenario>
 *    case1: 2step key, half down, full down, long press, repeat, up
 *    case2: 2step key, special key
 *    case3: non-2step key, down, long press, repeat, up
 *    case4: non-2step key, half up, half down
 * <Expected Result>
 *    case1: update key code data
 *    case2: assert
 *    case3: update key code data
 *    case4: assert
 *
 * </test case description>
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret ut_pre_update_key_data_buf(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    key_data_struct data1;
    key_data_struct data2;
    S32 i;
    S16 key_type1[5] = {KEY_HALF_PRESS_DOWN, KEY_FULL_PRESS_DOWN, KEY_LONG_PRESS, KEY_REPEAT, KEY_EVENT_UP}; 
    S16 key_type2[4] = {KEY_EVENT_DOWN, KEY_LONG_PRESS, KEY_REPEAT, KEY_EVENT_UP};
 	key_data_struct data[MAX_DECT_KEY_NUM];
	U8 len;
	U8 keypad_status;	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	keypad_status = g_key_cntx.keypad_status;
	save_key_data(data, &len);
	
    init_key_data_buf();
    SET_KEY_DET_MODE(g_key_cntx.keypad_status, (U8)kbd_2_keys_det_mode);
#ifdef __KBD_2STEP_KEY_SUPPORT__
	data1.mmi_key_code = KEY_CAMERA;

    for (i = 0; i < 5; i++)
    {
        data1.mmi_key_type = (U8)key_type1[i];
        pre_update_key_data_buf(&data1);
        MMI_ASSERT(key_data_cmp(&data1, &g_key_cntx.buffer[0]));
        MMI_ASSERT(g_key_cntx.buffer[1].mmi_key_code == KEY_INVALID);
    }
#else
    data1.mmi_key_code = KEY_1;
    
    for (i = 0; i < 4; i++)
    {
        data1.mmi_key_type = (U8)key_type2[i];
        pre_update_key_data_buf(&data1);
        MMI_ASSERT(key_data_cmp(&data1, &g_key_cntx.buffer[0]));
        MMI_ASSERT(g_key_cntx.buffer[1].mmi_key_code == KEY_INVALID);
    }
#endif
    data2.mmi_key_code  = KEY_0;
    for (i = 0; i < 4; i++)
    {
        data2.mmi_key_type = (U8)key_type2[i];
        pre_update_key_data_buf(&data2);
        MMI_ASSERT(key_data_cmp(&data2, &g_key_cntx.buffer[1]));
        MMI_ASSERT(key_data_cmp(&data1, &g_key_cntx.buffer[0]));    
    }

	restore_key_data(data, &len);
	g_key_cntx.keypad_status = keypad_status;
	kal_prompt_trace(MOD_MMI, "[UT_KEY] test pre_update_key_data_buf PASS");
	return MMI_RET_OK;		
}


 /*****************************************************************************
 * FUNCTION
 *  ut_get_2step_key_state
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0013
 * <Test Case Content> get 2step key state
 * <Test Case Number> 6
 * <Scenario>
 *    case1: set KEY_CAMERA as 2 step key, FULL_DOWN
 *    case2: set KEY_CAMERA as 2 step key, HALF DOWN
 *    case3: set KEY_CAMERA as 2 step key, FULL UP
 *    case4: non-2step eky
 * 
 * <Expected Result>
 *    case1: FULL_DOWN
 *    case2: HALF DOWN 
 *    case3: FULL UP
 *    case4: STATE_END
 *
 * </test case description>
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret ut_get_2step_key_state(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __KBD_2STEP_KEY_SUPPORT__
	U8 key_code;
    U8 state;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	key_code = g_key_cntx._2step_key.mmi_key_code;
	state = g_key_cntx._2step_key.state;
    g_key_cntx._2step_key.mmi_key_code = KEY_CAMERA;
    g_key_cntx._2step_key.state = FULL_DOWN;
    MMI_ASSERT(get_2step_key_state(KEY_CAMERA) == FULL_DOWN);

    g_key_cntx._2step_key.state = HALF_DOWN;
    MMI_ASSERT(get_2step_key_state(KEY_CAMERA) == HALF_DOWN);

    g_key_cntx._2step_key.state= FULL_UP;
    MMI_ASSERT(get_2step_key_state(KEY_CAMERA) == FULL_UP);

    MMI_ASSERT(get_2step_key_state(KEY_1) == STATE_END);
    g_key_cntx._2step_key.mmi_key_code = key_code;
    g_key_cntx._2step_key.state = state;
    kal_prompt_trace(MOD_MMI, "[UT_KEY] teset ut_get_2step_key_state PASS");
#endif
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  ut_get_key_state
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0012
 * <Test Case Content> get key state
 * <Test Case Number> 4
 * <Scenario>
 *    case1: not active key
 *    case2: active key down,
 *    case3: active key up
 *    case4: active key half up
 * 
 * <Expected Result>
 *    case1: up
 *    case2: down 
 *    case3: up 
 *    case4: half up
 *
 * </test case description>
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret ut_get_key_state(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    key_data_struct data1;
    key_data_struct data2;
    U8 key_type;
 	key_data_struct data[MAX_DECT_KEY_NUM];
	U8 len;
	U8 keypad_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	keypad_status = g_key_cntx.keypad_status;
	save_key_data(data, &len);
	
    SET_KEY_DET_MODE(g_key_cntx.keypad_status, (U8)kbd_2_keys_det_mode);
    init_key_data_buf();
    data1.mmi_key_code = KEY_0;
    data2.mmi_key_code = KEY_1;

    insert_key_data(&data1);
    insert_key_data(&data2);
    for (key_type = KEY_EVENT_DOWN;  key_type < MAX_KEY_TYPE; key_type++)
    {
        data1.mmi_key_type = key_type;
        data2.mmi_key_type = key_type;
        update_key_data(&data1);
        update_key_data(&data2);
        MMI_ASSERT((U8)get_key_state(KEY_0) == key_type);
        MMI_ASSERT((U8)get_key_state(KEY_1) == key_type);
    }
    restore_key_data(data, &len);
    g_key_cntx.keypad_status = keypad_status;
    kal_prompt_trace(MOD_MMI, "[UT_KEY] test get key state PASS");
    return MMI_RET_OK;	
}


/*****************************************************************************
 * FUNCTION
 *  ut_remove_key_data
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0011
 * <Test Case Content> remove multi-key data
 * <Test Case Number> 2
 * <Scenario>
 *    case1: 2 key detection mode, code1, code2 in table, remove code1
 *    case2: 2 key detection mode, code1, code2 in table, remove code2
 *    case3: 2 key detection mode, code1, code2 in table, remove code3
 *    case4: 2 key detection mode, code1, in table, remove code1
 * 
 * <Expected Result>
 *    case1: success, [code2, invalid]
 *    case2: success, [code1, invalid] 
 *    case3: fail 
 *    case4: success, [invalid, invalid]
 * </test case description>
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret ut_remove_key_data(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    key_data_struct data1;
    key_data_struct data2;
 	key_data_struct data[MAX_DECT_KEY_NUM];
	U8 len;
	U8 keypad_status;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	keypad_status = g_key_cntx.keypad_status;
	save_key_data(data, &len);	
    SET_KEY_DET_MODE(g_key_cntx.keypad_status, (U8)kbd_2_keys_det_mode);
    init_key_data_buf();
    data1.mmi_key_code = KEY_0;
    data2.mmi_key_code = KEY_1;
    insert_key_data(&data1);
    insert_key_data(&data2); 

    MMI_ASSERT(remove_key_data(KEY_0) == MMI_RET_OK);
    MMI_ASSERT(g_key_cntx.buf_len == 1);
    MMI_ASSERT(g_key_cntx.buffer[0].mmi_key_code == KEY_1);
    MMI_ASSERT(g_key_cntx.buffer[1].mmi_key_code == KEY_INVALID);

    MMI_ASSERT(remove_key_data(KEY_1) == MMI_RET_OK);
    MMI_ASSERT(g_key_cntx.buffer[0].mmi_key_code == KEY_INVALID);
    MMI_ASSERT(g_key_cntx.buffer[1].mmi_key_code == KEY_INVALID);
    MMI_ASSERT(g_key_cntx.buf_len == 0);

    init_key_data_buf();
    data1.mmi_key_code = KEY_0;
    data2.mmi_key_code = KEY_1;
    insert_key_data(&data1);
    insert_key_data(&data2); 

    MMI_ASSERT(remove_key_data(KEY_1) == MMI_RET_OK);
    MMI_ASSERT(g_key_cntx.buffer[0].mmi_key_code == KEY_0);
    MMI_ASSERT(g_key_cntx.buffer[1].mmi_key_code == KEY_INVALID);

    init_key_data_buf();
    data1.mmi_key_code = KEY_0;
    data2.mmi_key_code = KEY_1;
    insert_key_data(&data1);
    insert_key_data(&data2);
    MMI_ASSERT(remove_key_data(KEY_3) == REMOVE_BUT_NOT_FOUND);
    
    restore_key_data(data, &len);
    g_key_cntx.keypad_status = keypad_status;
    kal_prompt_trace(MOD_MMI, "[UT_KEY] test remove key data PASS");
    return MMI_RET_OK;		
}


/*****************************************************************************
 * FUNCTION
 *  ut_update_key_data
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0010
 * <Test Case Content> change multi-key data
 * <Test Case Number> 3
 * <Scenario>
 *    case1: 2 key detection mode, code1, code2 in table, change code1 state
 *    case2: 2 key detection mode, code1, code2 in table, change code2 state
 *    case3: 2 key detection mode, code1, code2 in table, change code3 state 
 * 
 * <Expected Result>
 *    case1: success
 *    case2: success
 *    case3: fail 
 * </test case description>
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret ut_update_key_data(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    key_data_struct data1;
    key_data_struct data2;
    key_data_struct data3;
	key_data_struct data[MAX_DECT_KEY_NUM];
	U8 len;
	U8 keypad_status;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	keypad_status = g_key_cntx.keypad_status;
	save_key_data(data, &len);
	
    SET_KEY_DET_MODE(g_key_cntx.keypad_status, (U8)kbd_2_keys_det_mode);
    init_key_data_buf();
    data1.mmi_key_code = KEY_0;
    data2.mmi_key_code = KEY_1;
    insert_key_data(&data1);
    insert_key_data(&data2);

    data3.mmi_key_code = KEY_0;
    data3.mmi_key_type = KEY_REPEAT;

    MMI_ASSERT(update_key_data(&data3) == MMI_TRUE);
    MMI_ASSERT(key_data_cmp(&data3, &g_key_cntx.buffer[0]) == MMI_TRUE);
    
    data3.mmi_key_code = KEY_1;
    data3.mmi_key_type = KEY_REPEAT;
    MMI_ASSERT(update_key_data(&data3) == MMI_TRUE);
    MMI_ASSERT(key_data_cmp(&data3, &g_key_cntx.buffer[1]) == MMI_TRUE);

    data3.mmi_key_code = KEY_3;
    MMI_ASSERT(update_key_data(&data3) == MMI_FALSE);

	restore_key_data(data, &len);
	g_key_cntx.keypad_status = keypad_status;
    kal_prompt_trace(MOD_MMI, "[UT_KEY] test update key data PASS");
    return MMI_RET_OK;	
}


/*****************************************************************************
 * FUNCTION
 *  ut_search_key_data
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0009
 * <Test Case Content> get index of specific mmi key code in key cntx
 * <Test Case Number> 3
 * <Scenario>
 *    case1: 2 key detection mode, code1, code2 in table, find code1
 *    case2: 2 key detection mode, code1, code2 in table, find code2
 *    case3: 2 key detection mode, code1, code2 in table, find code3
 * 
 * <Expected Result>
 *    case1: find
 *    case2: find
 *    case3: not find
 * </test case description>
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret ut_search_key_data(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    key_data_struct data1;
    key_data_struct data2;
	key_data_struct data[MAX_DECT_KEY_NUM];
	U8 len;
	U8 keypad_status;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	keypad_status = g_key_cntx.keypad_status;
	save_key_data(data, &len);
    SET_KEY_DET_MODE(g_key_cntx.keypad_status, (U8)kbd_2_keys_det_mode);
    init_key_data_buf();
    data1.mmi_key_code = KEY_0;
    data2.mmi_key_code = KEY_1;
    insert_key_data(&data1);
    insert_key_data(&data2);    
    MMI_ASSERT(search_key_data(KEY_0) == 0);    
    MMI_ASSERT(search_key_data(KEY_1) == 1);
    MMI_ASSERT(search_key_data(KEY_3) == -1);
    restore_key_data(data, &len);
    g_key_cntx.keypad_status = keypad_status;
    kal_prompt_trace(MOD_MMI, "[UT_KEY] test search key data PASS");
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  key_data_cmp
 * DESCRIPTION
 *  This function is used to cmp tow key_data_struct
 *
 * PARAMETERS
 *  p    :[IN] key_data structure 1
 *  q    :[IN] key_data structure 2
 * RETURNS
 *  equal return MMI_TRUE or return MMI_FALSE
 *****************************************************************************/
MMI_BOOL key_data_cmp(key_data_struct *p, key_data_struct *q)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (p->mmi_key_code == q->mmi_key_code) &&
           (p->mmi_key_type == q->mmi_key_type) &&
           (p->is_2step == q->is_2step) &&
           (p->is_clear == q->is_clear) &&
           (p->is_full_ctrl == q->is_full_ctrl) &&
           (p->is_combo == q->is_combo);
}


/*****************************************************************************
 * FUNCTION
 *  write_key_data
 * DESCRIPTION
 *  This function is used to write data to key data buffer
 *
 * PARAMETERS
 *  indx    :[IN] key data buffer index
 *  data_p  :[IN] data that will be writen to key data buffer.
 * RETURNS
 *  void
 *****************************************************************************/
void write_key_data(S32 index, key_data_struct *data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_FRM_UT_ASSERT(index < MAX_DECT_KEY_NUM, MMI_FALSE, GET_RES_MEM());
    g_key_cntx.buffer[index].mmi_key_code = data_p->mmi_key_code;
    g_key_cntx.buffer[index].mmi_key_type = data_p->mmi_key_type;
    g_key_cntx.buffer[index].is_2step     = data_p->is_2step;
    g_key_cntx.buffer[index].is_clear     = data_p->is_clear;
    g_key_cntx.buffer[index].is_full_ctrl = data_p->is_full_ctrl;
    g_key_cntx.buffer[index].is_combo   = data_p->is_combo;

}

void set_key_data(key_data_struct *data,
                  U8 code,
                  U8 cvt_code,
                  U8 type, 
                  MMI_BOOL is_2step,
                  MMI_BOOL is_combo,
                  MMI_BOOL is_clear)
{
    data->mmi_key_code = code;
    data->cvt_code = cvt_code;
    data->mmi_key_type = type;
    data->is_2step = is_2step;
    data->is_combo = is_combo;
    data->is_clear = is_clear;
}

/*****************************************************************************
 * FUNCTION
 *  ut_insert_key_data
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0008
 * <Test Case Content> add multi key date to key cntx
 * <Test Case Number> 5
 * <Scenario>
 *    case1: detection mode is 2key, add code1 to [INVALID, INVALID]
 *    case2: detection mode is 2key, add code2 to [code1,   INVALID]
 *    case3: detection mode is 2key, add code1 to [code1,   INVALID]
 *    case4: detection mode is 2key, add code1 to [code1,   code2]
 *    case5: detection mode is 2key, add code2 to [code1,   code2]
 *    case6: detection mode is 2key, add code3 to [code1,   code2]
 * <Expected Result>
 *    case1: [code1, INVALID]
 *    case2: [code1, code2]
 *    case3: assert
 *    case4: assert
 *    case5: assert
 * </test case description>
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret ut_insert_key_data(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    key_data_struct data1;
    key_data_struct data2;
	key_data_struct data3;
	key_data_struct data[MAX_DECT_KEY_NUM];
	U8 len;
	U8 key_pad_status;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	save_key_data(data, &len);
	key_pad_status = g_key_cntx.keypad_status;
    init_key_data_buf();
    SET_KEY_DET_MODE(g_key_cntx.keypad_status, (U8)kbd_2_keys_det_mode);
	set_key_data(&data1, KEY_0, KEY_0, KEY_EVENT_DOWN, MMI_FALSE, MMI_TRUE, MMI_FALSE);
    insert_key_data(&data1);
    MMI_ASSERT(g_key_cntx.buf_len == 1);
    MMI_ASSERT(key_data_cmp(&data1, &g_key_cntx.buffer[0]) == MMI_TRUE);
    MMI_ASSERT(g_key_cntx.buffer[1].mmi_key_code == KEY_INVALID);
	set_key_data(&data2, KEY_1, KEY_1, KEY_EVENT_DOWN, MMI_FALSE, MMI_TRUE, MMI_FALSE);

    insert_key_data(&data2);    
    MMI_ASSERT(key_data_cmp(&data1, &g_key_cntx.buffer[0]) == MMI_TRUE);
    MMI_ASSERT(key_data_cmp(&data2, &g_key_cntx.buffer[1]) == MMI_TRUE);
    MMI_ASSERT(g_key_cntx.buf_len == 2);

	MMI_ASSERT(insert_key_data(&data1) == INSERT_SAME_KEY_CODE);
	MMI_ASSERT(insert_key_data(&data2) == INSERT_SAME_KEY_CODE);
	set_key_data(&data3, KEY_3, KEY_3, KEY_EVENT_DOWN, MMI_FALSE, MMI_TRUE, MMI_FALSE);
	MMI_ASSERT(insert_key_data(&data3) == INSERT_CODE_BEYOND_DECT);
	g_key_cntx.keypad_status = key_pad_status;
	restore_key_data(data, &len);
	kal_prompt_trace(MOD_MMI, "[UT_KEY] test insert_key_data PASS");
	return MMI_RET_OK;  
}


/*****************************************************************************
* FUNCTION
*  ut_init_key_data_buf
* DESCRIPTION
* <test case description>
* <Test Case Group> KEY_EVENT
* <Test Case ID>    KEY_EVENT_0007
* <Test Case Content> init state of key data buffer
* <Test Case Number> 2
* <Scenario>
 *    case1: call init multi key data
 * <Expected Result>
 *    case1: key code should be KEY_INVALID, key type should be KEY_EVENT_UP, others should 0
 * </test case description>
 *
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret ut_init_key_data_buf(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 j;
	key_data_struct data[MAX_DECT_KEY_NUM];
	U8 len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    save_key_data(data, &len);
	init_key_data_buf();
    MMI_ASSERT(g_key_cntx.buf_len == 0);
    for (j = 0; j < MAX_DECT_KEY_NUM; j++)
    {
        MMI_ASSERT(g_key_cntx.buffer[j].mmi_key_code == KEY_INVALID);
        MMI_ASSERT(g_key_cntx.buffer[j].mmi_key_type == KEY_EVENT_UP);
        MMI_ASSERT(g_key_cntx.buffer[j].cvt_code == KEY_INVALID);
        MMI_ASSERT(g_key_cntx.buffer[j].is_clear == 0);
        MMI_ASSERT(g_key_cntx.buffer[j].is_2step== 0);
        MMI_ASSERT(g_key_cntx.buffer[j].is_full_ctrl == 0);
        MMI_ASSERT(g_key_cntx.buffer[j].is_combo== 0);
    }
    restore_key_data(data, &len);
    kal_prompt_trace(MOD_MMI, "[UT_KEY] test init_key_data_buf PASS!");
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  ut_is_2step_key
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0006
 * <Test Case Content> judge a key is 2step key or not
 * <Test Case Number> 2
 * <Scenario>
 *    case1: set KEY CAMERA as 2step key, judge KEY_CAMERA
 *    case2: set KEY_CAMERA as 2step key, judge other keys
 * <Expected Result>
 *    case1: MMI_TRUE
 *    case2: MMI_FALSE
 * </test case description>
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret ut_is_2step_key(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __KBD_2STEP_KEY_SUPPORT__
    MMI_BOOL ret = MMI_FALSE;
    S16 i;
	U8 key_code;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	key_code = g_key_cntx._2step_key.mmi_key_code;
    g_key_cntx._2step_key.mmi_key_code = KEY_CAMERA;
    MMI_ASSERT(is_2step_key(KEY_CAMERA) == MMI_TRUE);
    for (i = KEY_0; i < MAX_KEY_NUM; i++)
    {
        if (i != KEY_CAMERA)
        {
            MMI_ASSERT(is_2step_key(i) == MMI_FALSE);
        }
    }
    g_key_cntx._2step_key.mmi_key_code = key_code;
    kal_prompt_trace(MOD_MMI, "[UT_KEY] test is_2step_key PASS");
#endif
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  ut_is_legal_key_type
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0005
 * <Test Case Content> mmi key type transform flow
 * <Test Case Number> 26
 * <Scenario>
 *    case1: Non-2step key, framework or app level, curr key type = down, pre key type = up
 *    case2: Non-2step key, framework or app level, curr key type = down, pre key type = all but up
 *    case3: Non-2step key, framework or app level, curr key type = longpress, pre key type = down
 *    case4: Non-2step key, framework or app level, curr key type = longpress, pre key type = all but down
 *    case5: Non-2step key, framework or app level, curr key type = repeat, pre key type = repeat or longpress
 *    case6: Non-2step key, framework or app level, curr key type = repeat, pre key type = all but repeat and longpress
 *    case7: Non-2step key, framework or app level, curr key type = up, pre key type = down or repeat or longpress
 *    case8: Non-2step key, framework or app level, curr key type = up, pre key type = all but down ,repeat and longpress
 *    case9: 2step key, framework level, curr key type = half down, pre key type = up
 *    case10:2step key, framework level, curr key type = half down, pre key type = all but up
 *    case11:2step key, app level, curr key type = half down, pre key type = up or half up
 *    case12:2step key, app level, curr key type = half down, pre key type = all but up and half up
 *    case13:2step key, frm or app level, curr key type = full down, pre key type = half press down
 *    case14:2step key, frm or app level, curr key type = full down, pre key type = all but half press down
 *    case15:2step key, frm or app level, curr key type = longpress, pre key type = full down
 *    case16:2step key, frm or app level, curr key type = longpress, pre key type = all but full down
 *    case17:2step key, frm or app level, curr key type = repeat, pre key type = repeat or long press
 *    case18:2step key, frm or app level, curr key type = repeat, pre key type = all but repeat and long press
 *    case19:2step key, frm level, curr key type = half down
 *    case20:2step key, app level, curr key type = half up, pre key type = half down, full down, long press, repeat
 *    case21:2step key, app level, curr key type = half up, pre key type = all but half down, full down, long press, repeat
 *    case22:2step key, frm level, curr key type = up, pre key type = half down, full down, long press repeat
 *    case24:2step key, app level, curr key type = up, pre key type = half up, 2step key state = full down
 *    case25:2step key, app level, curr key type = up, pre key type = all but half up
 *    case26:2step key, app level, curr key type = up, pre key type = half up, 2step key state = half down
 * <Expected Result>
 *    case1: legal key type
 *    case2: illegal key type
 *    case3: legal key type
 *    case4: illegal key type
 *    case5: legal key type
 *    case6: illegal key type
 *    case7: legal key type
 *    case8: illegal key type
 *    case9: legal type
 *    case10:illegal key type
 *    case11:legal key type
 *    case12:illegal key type
 *    case13:legal key type
 *    case14:illegal key type
 *    case15:legal key type
 *    case16:illegal key type
 *    case17:legal key type
 *    case18:illegal key type
 *    case19:illegal key type
 *    case20:legal key type
 *    case21:illegal key type
 *    case22:legal key type
 *    case24:legal key type
 *    case25:illegal key type
 *    case26:illegal key type
 * </test case description>
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret ut_is_legal_key_type(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(is_legal_key_type(KEY_EVENT_DOWN, KEY_EVENT_DOWN, NON_TWO_STEP_KEY) == MMI_FALSE);
    MMI_ASSERT(is_legal_key_type(KEY_EVENT_DOWN, KEY_LONG_PRESS, NON_TWO_STEP_KEY) == MMI_FALSE);
    MMI_ASSERT(is_legal_key_type(KEY_EVENT_DOWN, KEY_REPEAT, NON_TWO_STEP_KEY) == MMI_FALSE);
    MMI_ASSERT(is_legal_key_type(KEY_EVENT_DOWN, KEY_EVENT_UP, NON_TWO_STEP_KEY) == MMI_TRUE);

    MMI_ASSERT(is_legal_key_type(KEY_LONG_PRESS, KEY_EVENT_DOWN, NON_TWO_STEP_KEY) == MMI_TRUE);
    MMI_ASSERT(is_legal_key_type(KEY_LONG_PRESS, KEY_LONG_PRESS, NON_TWO_STEP_KEY) == MMI_FALSE);
    MMI_ASSERT(is_legal_key_type(KEY_LONG_PRESS, KEY_REPEAT, NON_TWO_STEP_KEY) == MMI_FALSE);
    MMI_ASSERT(is_legal_key_type(KEY_LONG_PRESS, KEY_EVENT_UP, NON_TWO_STEP_KEY) == MMI_FALSE);    

    MMI_ASSERT(is_legal_key_type(KEY_REPEAT, KEY_EVENT_DOWN, NON_TWO_STEP_KEY) == MMI_FALSE);
    MMI_ASSERT(is_legal_key_type(KEY_REPEAT, KEY_LONG_PRESS, NON_TWO_STEP_KEY) == MMI_TRUE);
    MMI_ASSERT(is_legal_key_type(KEY_REPEAT, KEY_REPEAT, NON_TWO_STEP_KEY) == MMI_TRUE);
    MMI_ASSERT(is_legal_key_type(KEY_REPEAT, KEY_EVENT_UP, NON_TWO_STEP_KEY) == MMI_FALSE);

    MMI_ASSERT(is_legal_key_type(KEY_REPEAT, KEY_EVENT_DOWN, NON_TWO_STEP_KEY) == MMI_FALSE);
    MMI_ASSERT(is_legal_key_type(KEY_REPEAT, KEY_LONG_PRESS, NON_TWO_STEP_KEY) == MMI_TRUE);
    MMI_ASSERT(is_legal_key_type(KEY_REPEAT, KEY_REPEAT, NON_TWO_STEP_KEY) == MMI_TRUE);
    MMI_ASSERT(is_legal_key_type(KEY_REPEAT, KEY_EVENT_UP, NON_TWO_STEP_KEY) == MMI_FALSE); 

    MMI_ASSERT(is_legal_key_type(KEY_EVENT_UP, KEY_EVENT_DOWN, NON_TWO_STEP_KEY) == MMI_TRUE);
    MMI_ASSERT(is_legal_key_type(KEY_EVENT_UP, KEY_LONG_PRESS, NON_TWO_STEP_KEY) == MMI_TRUE);
    MMI_ASSERT(is_legal_key_type(KEY_EVENT_UP, KEY_REPEAT, NON_TWO_STEP_KEY) == MMI_TRUE);
    MMI_ASSERT(is_legal_key_type(KEY_EVENT_UP, KEY_EVENT_UP, NON_TWO_STEP_KEY) == MMI_FALSE);

#ifdef __KBD_2STEP_KEY_SUPPORT__
    MMI_ASSERT(is_legal_key_type(KEY_FULL_PRESS_DOWN, KEY_HALF_PRESS_DOWN, TWO_STEP_KEY) == MMI_TRUE);
    MMI_ASSERT(is_legal_key_type(KEY_FULL_PRESS_DOWN, KEY_FULL_PRESS_DOWN, TWO_STEP_KEY) == MMI_FALSE);
    MMI_ASSERT(is_legal_key_type(KEY_FULL_PRESS_DOWN, KEY_LONG_PRESS, TWO_STEP_KEY) == MMI_FALSE);
    MMI_ASSERT(is_legal_key_type(KEY_FULL_PRESS_DOWN, KEY_REPEAT, TWO_STEP_KEY) == MMI_FALSE);
    MMI_ASSERT(is_legal_key_type(KEY_FULL_PRESS_DOWN, KEY_EVENT_UP, TWO_STEP_KEY) == MMI_FALSE);

    MMI_ASSERT(is_legal_key_type(KEY_HALF_PRESS_DOWN, KEY_HALF_PRESS_DOWN, TWO_STEP_KEY) == MMI_FALSE);
    MMI_ASSERT(is_legal_key_type(KEY_HALF_PRESS_DOWN, KEY_FULL_PRESS_DOWN, TWO_STEP_KEY) == MMI_FALSE);
    MMI_ASSERT(is_legal_key_type(KEY_HALF_PRESS_DOWN, KEY_LONG_PRESS, TWO_STEP_KEY) == MMI_FALSE);
    MMI_ASSERT(is_legal_key_type(KEY_HALF_PRESS_DOWN, KEY_REPEAT, TWO_STEP_KEY) == MMI_FALSE);
    MMI_ASSERT(is_legal_key_type(KEY_HALF_PRESS_DOWN, KEY_EVENT_UP, TWO_STEP_KEY) == MMI_TRUE); 

    MMI_ASSERT(is_legal_key_type(KEY_LONG_PRESS, KEY_HALF_PRESS_DOWN, TWO_STEP_KEY) == MMI_FALSE);
    MMI_ASSERT(is_legal_key_type(KEY_LONG_PRESS, KEY_FULL_PRESS_DOWN, TWO_STEP_KEY) == MMI_TRUE);
    MMI_ASSERT(is_legal_key_type(KEY_LONG_PRESS, KEY_LONG_PRESS, TWO_STEP_KEY) == MMI_FALSE);
    MMI_ASSERT(is_legal_key_type(KEY_LONG_PRESS, KEY_REPEAT, TWO_STEP_KEY) == MMI_FALSE);
    MMI_ASSERT(is_legal_key_type(KEY_LONG_PRESS, KEY_EVENT_UP, TWO_STEP_KEY) == MMI_FALSE); 

    MMI_ASSERT(is_legal_key_type(KEY_REPEAT, KEY_HALF_PRESS_DOWN, TWO_STEP_KEY) == MMI_FALSE);
    MMI_ASSERT(is_legal_key_type(KEY_REPEAT, KEY_FULL_PRESS_DOWN, TWO_STEP_KEY) == MMI_FALSE);
    MMI_ASSERT(is_legal_key_type(KEY_REPEAT, KEY_LONG_PRESS, TWO_STEP_KEY) == MMI_TRUE);
    MMI_ASSERT(is_legal_key_type(KEY_REPEAT, KEY_REPEAT, TWO_STEP_KEY) == MMI_TRUE);
    MMI_ASSERT(is_legal_key_type(KEY_REPEAT, KEY_EVENT_UP, TWO_STEP_KEY) == MMI_FALSE); 

    MMI_ASSERT(is_legal_key_type(KEY_EVENT_UP, KEY_HALF_PRESS_DOWN, TWO_STEP_KEY) == MMI_TRUE);
    MMI_ASSERT(is_legal_key_type(KEY_EVENT_UP, KEY_FULL_PRESS_DOWN, TWO_STEP_KEY) == MMI_TRUE);
    MMI_ASSERT(is_legal_key_type(KEY_EVENT_UP, KEY_LONG_PRESS, TWO_STEP_KEY) == MMI_TRUE);
    MMI_ASSERT(is_legal_key_type(KEY_EVENT_UP, KEY_REPEAT, TWO_STEP_KEY) == MMI_TRUE);
    MMI_ASSERT(is_legal_key_type(KEY_EVENT_UP, KEY_EVENT_UP, TWO_STEP_KEY) == MMI_FALSE);
#endif
    kal_prompt_trace(MOD_MMI, "[UT_KEY] test is_legal_key_type PASS");
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  ut_get_mmi_key_code
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0001
 * <Test Case Content> get mmi key code by device key code from key mapping table
 * <Test Case Number> 2
 * <Scenario>
 *    case1: Input normal device key code
 *    case2: Input device key code that is not in the mapping table
 * <Expected Result>
 *    case1: get the normal mmi key code
 *    case2: get KEY_INVALID
 * </test case description>
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret ut_get_mmi_key_code(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(get_mmi_key_code(DEVICE_KEY_0) == KEY_0);
    MMI_ASSERT(get_mmi_key_code(DEVICE_KEY_1) == KEY_1);
    MMI_ASSERT(get_mmi_key_code(DEVICE_KEY_FUNCTION) == KEY_CAMERA);
    MMI_ASSERT(get_mmi_key_code(DEVICE_KEY_MENU) == KEY_ENTER);
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    MMI_ASSERT(get_mmi_key_code(DEVICE_KEY_A) == KEY_A);
#endif
    MMI_ASSERT(get_mmi_key_code(DEVICE_KEY_EMAIL) == KEY_INVALID);
    MMI_ASSERT(get_mmi_key_code(MAX_DEVICE_KEYS) == KEY_INVALID);
    MMI_ASSERT(get_mmi_key_code(MAX_DEVICE_KEYS + 1) == KEY_INVALID);
#ifdef __SENDKEY2_SUPPORT__
    MMI_ASSERT(get_mmi_key_code(DEVICE_KEY_SEND2) == KEY_SEND);
#endif /* __SENDKEY2_SUPPORT__ */
    kal_prompt_trace(MOD_MMI, "[UT_KEY] test get_mmi_key_code PASS");
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  ut_get_device_key_code
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0003
 * <Test Case Content> get device key code by mmi key code from key mapping table
 * <Test Case Number> 3
 * <Scenario>
 *    case1: Input normal mmi key code
 *    case2: Input mmi key code that is not in the mapping table(KEY_CSK)
 *    case3: Input illegal mmi key code
 *
 * <Expected Result>
 *    case1: get normal device key code
 *    case2: get DEVICE_KEY_NONE
 *    case3: get DEVICE_KEY_NONE
 *
 * </test case description>
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret ut_get_device_key_code(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(get_device_key_code(KEY_0) == DEVICE_KEY_0);
	MMI_ASSERT(get_device_key_code(KEY_ENTER) == DEVICE_KEY_MENU);
	MMI_ASSERT(get_device_key_code(KEY_SEND) == DEVICE_KEY_SEND);
    MMI_ASSERT(get_device_key_code(KEY_CSK) == DEVICE_KEY_NONE);
    MMI_ASSERT(get_device_key_code(KEY_LSK) == DEVICE_KEY_SK_LEFT);
    MMI_ASSERT(get_device_key_code(KEY_INVALID) == DEVICE_KEY_NONE);
    kal_prompt_trace(MOD_MMI, "[UT_KEY] test get_device_key_code PASS");
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  ut_get_mmi_key_type
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0004
 * <Test Case Content> mapping device key event to framework level mmi key event
 * <Test Case Number> 5
 * <Scenario>
 *    case1: Input detection event
 *    case2: 2 step key, input: press, full press, longpress, repeat, release
 *    case3: non-2step key, input: press, longpress, repeat, release
 *    case4: input invalid key event
 *    case5: non-2step key, input full press
 *
 * <Expected Result>
 *    case1: get detection event type and key detection mode updated
 *    case2: get half down, full down, longpress, repeat, up
 *    case3: get down, longpress, repeat, up
 *    case4: assert
 *    case5: assert
 *
 * </test case description>
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret ut_get_mmi_key_type(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 keypad_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	keypad_status = g_key_cntx.keypad_status;
#if defined(__TWO_KEY_DETECTION_SWITCHABLE__) || defined(__THREE_KEY_DETECTION_SWITCHABLE__)	
    MMI_ASSERT(get_mmi_key_type(DRV_WM_ENABLE_TWOKEY_DETECTION, 0) == KEY_EVENT_DECT);
    MMI_ASSERT(GET_KEY_DET_MODE(g_key_cntx.keypad_status) == kbd_2_keys_det_mode);
#endif

#if defined(__THREE_KEY_DETECTION_SWITCHABLE__)
    MMI_ASSERT(get_mmi_key_type(DRV_WM_ENABLE_THREEKEY_DETECTION, 0) == KEY_EVENT_DECT);
    MMI_ASSERT(GET_KEY_DET_MODE(g_key_cntx.keypad_status) == kbd_3_keys_det_mode);
#endif	
    MMI_ASSERT(get_mmi_key_type(DRV_WM_DISABLE_MULTIKEY_DETECTION, MMI_FALSE) == KEY_EVENT_DECT);
    MMI_ASSERT(GET_KEY_DET_MODE(g_key_cntx.keypad_status) == kbd_1_key_det_mode)
#ifdef __KBD_2STEP_KEY_SUPPORT__
    MMI_ASSERT(get_mmi_key_type(DRV_WM_KEYPRESS, TWO_STEP_KEY) == KEY_HALF_PRESS_DOWN);
    MMI_ASSERT(get_mmi_key_type(DRV_WM_KEYRELEASE, TWO_STEP_KEY) == KEY_EVENT_UP);
    MMI_ASSERT(get_mmi_key_type(DRV_WM_KEYLONGPRESS, TWO_STEP_KEY) == KEY_LONG_PRESS);
    MMI_ASSERT(get_mmi_key_type(DRV_WM_KEYREPEATED, TWO_STEP_KEY) == KEY_REPEAT);
    MMI_ASSERT(get_mmi_key_type(DRV_WM_KEYFULLPRESS, TWO_STEP_KEY) == KEY_FULL_PRESS_DOWN);
#endif
    MMI_ASSERT(get_mmi_key_type(DRV_WM_KEYPRESS, NON_TWO_STEP_KEY) == KEY_EVENT_DOWN);
    MMI_ASSERT(get_mmi_key_type(DRV_WM_KEYRELEASE, NON_TWO_STEP_KEY) == KEY_EVENT_UP);
    MMI_ASSERT(get_mmi_key_type(DRV_WM_KEYLONGPRESS, NON_TWO_STEP_KEY) == KEY_LONG_PRESS);
    MMI_ASSERT(get_mmi_key_type(DRV_WM_KEYREPEATED, NON_TWO_STEP_KEY) == KEY_REPEAT);
    
    MMI_ASSERT(get_mmi_key_type(DRV_WM_KEYFULLPRESS, NON_TWO_STEP_KEY) == ERR_KEY_EVENT);
    MMI_ASSERT(get_mmi_key_type(50, NON_TWO_STEP_KEY) == ERR_KEY_EVENT);
    g_key_cntx.keypad_status = keypad_status;
    kal_prompt_trace(MOD_MMI, "[UT_KEY] test get_mmi_key_type PASS");
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  ut_is_full_ctrled
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0004
 * <Test Case Content> judge is full ctrl key
 * <Test Case Number> 5
 * <Scenario>
 *    case 1: full ctrl key, full ctrl
 *    case 2: full ctrl key, not full ctrl
 *    case 3: not full ctrl key
 * <Expected Result>
 *    case 1: TRUE 
 *    case 2: FALSE
 *    case 3: FALSE
 * </test case description>
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret ut_is_full_ctrled(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_key_cntx.full_ctrl[0].mmi_key_code = KEY_END;
    g_key_cntx.full_ctrl[1].mmi_key_code = KEY_VOL_DOWN;
    g_key_cntx.full_ctrl[2].mmi_key_code = KEY_VOL_UP;

    g_key_cntx.full_ctrl[0].state = MMI_TRUE;
    g_key_cntx.full_ctrl[1].state = MMI_TRUE;
    g_key_cntx.full_ctrl[2].state = MMI_TRUE;
    MMI_ASSERT(is_full_ctrled(KEY_END) == MMI_TRUE);
    MMI_ASSERT(is_full_ctrled(KEY_VOL_DOWN) == MMI_TRUE);
    MMI_ASSERT(is_full_ctrled(KEY_VOL_UP) == MMI_TRUE);

    g_key_cntx.full_ctrl[0].state = MMI_FALSE;
    g_key_cntx.full_ctrl[1].state = MMI_FALSE;
    g_key_cntx.full_ctrl[2].state = MMI_FALSE;
    MMI_ASSERT(is_full_ctrled(KEY_END) == MMI_FALSE);
    MMI_ASSERT(is_full_ctrled(KEY_VOL_DOWN) == MMI_FALSE);
    MMI_ASSERT(is_full_ctrled(KEY_VOL_UP) == MMI_FALSE);

    MMI_ASSERT(is_full_ctrled(KEY_0) == MMI_FALSE);
    kal_prompt_trace(MOD_MMI, "[UT_KEY] test is_full_ctrled PASS");
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  ut_is_full_ctrled
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0004
 * <Test Case Content> judge is full ctrl key
 * <Test Case Number> 5
 * <Scenario>
 *    case 1: full ctrl key, full ctrl
 *    case 2: full ctrl key, not full ctrl
 *    case 3: not full ctrl key
 * <Expected Result>
 *    case 1: TRUE 
 *    case 2: FALSE
 *    case 3: FALSE
 * </test case description>
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret ut_gen_key_data(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_key_evt_struct evt;
	key_data_struct data;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	evt.mmi_key_code = KEY_0;
    evt.cvt_code = KEY_0;
	evt.mmi_key_type = KEY_EVENT_DOWN;
	evt.is_clear = MMI_FALSE;
	gen_key_data(&evt, &data);
	MMI_ASSERT(data.mmi_key_code == KEY_0);
    MMI_ASSERT(data.cvt_code == KEY_0);
	MMI_ASSERT(data.mmi_key_type == KEY_EVENT_DOWN);
	MMI_ASSERT(data.is_clear == MMI_FALSE);
	kal_prompt_trace(MOD_MMI, "[UT_KEY] test gen_key_data PASS");
	return MMI_RET_OK;
}

/*****************************************************************************
* FUNCTION
*  ut_get_rotated_mmi_key_code
* DESCRIPTION
* <test case description>
* <Test Case Group> KEY_EVENT
* <Test Case ID>    KEY_EVENT_0004
* <Test Case Content> judge is full ctrl key
* <Test Case Number> 5
* <Scenario>
*    case 1: input KEY_UP_ARROW
*    case 2: input KEY_DOWN_ARROW
*    case 3: input KEY_LEFT_ARROW
*    case 4: input KEY_RIGHT_ARROW
*    case 5: input KEY_0
* <Expected Result>
*    case 1: output KEY_LEFT_ARROW
*    case 2: output KEY_RIGHT_ARROW
*    case 3: output KEY_DOWN_ARROW
*    case 4: output KEY_UP_ARROW
*    case 5: output KEY_0
* </test case description>
*
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret ut_get_rotated_mmi_key_code(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 rotate;;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SCREEN_ROTATE__
    rotate = mmi_frm_get_screen_rotate();
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
    MMI_ASSERT(get_rotated_mmi_key_code(KEY_UP_ARROW) == KEY_LEFT_ARROW);
    MMI_ASSERT(get_rotated_mmi_key_code(KEY_DOWN_ARROW) == KEY_RIGHT_ARROW);
    MMI_ASSERT(get_rotated_mmi_key_code(KEY_LEFT_ARROW) == KEY_DOWN_ARROW);
    MMI_ASSERT(get_rotated_mmi_key_code(KEY_RIGHT_ARROW) == KEY_UP_ARROW);
    MMI_ASSERT(get_rotated_mmi_key_code(KEY_0) == KEY_0);
    mmi_frm_screen_rotate(rotate);
#endif /* __MMI_SCREEN_ROTATE__ */
    kal_prompt_trace(MOD_MMI, "[UT_KEY] test get_rotated_mmi_key_code PASS");
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  ut_enter_to_lsk
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0004
 * <Test Case Content> judge is full ctrl key
 * <Test Case Number> 5
 * <Scenario>
 *    case 1:  input Enter, all Enter's handler is NULL
 *    case 2:  input Enter, not all enter's handler is NULL
 *    case 3:  input key0
 * <Expected Result>
 *    case 1:  lsk
 *    case 2:  enter
 *    case 3:  key0
 *
 * </test case description>
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret ut_enter_to_lsk(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MAX_KEY_TYPE; i++)
    {
        currKeyFuncPtrs[KEY_ENTER][i] = NULL;
    }
    MMI_ASSERT(enter_to_lsk(KEY_ENTER) == KEY_LSK);

    currKeyFuncPtrs[KEY_ENTER][KEY_EVENT_DOWN] = (FuncPtr)1;
    MMI_ASSERT(enter_to_lsk(KEY_ENTER) == KEY_ENTER);
    MMI_ASSERT(enter_to_lsk(KEY_0) == KEY_0);
    kal_prompt_trace(MOD_MMI, "[UT_KEY] test enter to lsk PASS");
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  ut_mmi_key_code_convert
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0004
 * <Test Case Content> judge is full ctrl key
 * <Test Case Number> 5
 * <Scenario>
 *
 * <Expected Result>
 *
 *
 * </test case description>
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* This variable is used to enable key code convert */
MMI_BOOL g_convert = MMI_FALSE;

/* key code convert test function 1*/
static S16 key_code_convert_test1(S16 mmi_key_code)
{
    if (g_convert == MMI_TRUE)
    {
        if (mmi_key_code == KEY_UP_ARROW)    return KEY_LEFT_ARROW;
        if (mmi_key_code == KEY_DOWN_ARROW)  return KEY_RIGHT_ARROW;
        if (mmi_key_code == KEY_LEFT_ARROW)  return KEY_DOWN_ARROW;
        if (mmi_key_code == KEY_RIGHT_ARROW) return KEY_UP_ARROW;
    }
    return mmi_key_code;
}

/* key code convert test function 2*/
static S16 key_code_convert_test2(S16 mmi_key_code)
{
    return KEY_INVALID;
}
mmi_ret ut_mmi_key_code_convert(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    key_data_struct buf[MAX_DECT_KEY_NUM];
    U8 len;
    key_data_struct data;
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    save_key_data(buf, &len);
    init_key_data_buf();
    MMI_ASSERT(mmi_key_code_convert(KEY_UP_ARROW, DRV_WM_KEYPRESS) == KEY_INVALID);
    g_convert = MMI_TRUE;
    MMI_ASSERT(mmi_key_code_convert(KEY_UP_ARROW, DRV_WM_KEYPRESS) == KEY_LEFT_ARROW);
    data.mmi_key_code = KEY_UP_ARROW;
    data.cvt_code = KEY_LEFT_ARROW;
    insert_key_data(&data);
    g_convert = MMI_FALSE;
    MMI_ASSERT(mmi_key_code_convert(KEY_UP_ARROW, DRV_WM_KEYLONGPRESS) == KEY_LEFT_ARROW);
    MMI_ASSERT(mmi_key_code_convert(KEY_UP_ARROW, DRV_WM_KEYREPEATED) == KEY_LEFT_ARROW);
    MMI_ASSERT(mmi_key_code_convert(KEY_UP_ARROW, DRV_WM_KEYRELEASE) == KEY_LEFT_ARROW);
    remove_key_data(KEY_UP_ARROW);
    MMI_ASSERT(mmi_key_code_convert(KEY_UP_ARROW, DRV_WM_KEYPRESS) == KEY_INVALID);
    restore_key_data(buf, &len);
    kal_prompt_trace(MOD_MMI, "[UT_KEY] test mmi_key_code_convert PASS");
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  ut_get_key_data
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0004
 * <Test Case Content> judge is full ctrl key
 * <Test Case Number> 5
 * <Scenario>
 *
 * <Expected Result>
 *
 *
 * </test case description>
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret ut_get_key_data(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    key_data_struct data;
	key_data_struct buffer[MAX_DECT_KEY_NUM];
	U8 len;
	U8 keypad_status;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	save_key_data(buffer, &len);
	keypad_status = g_key_cntx.keypad_status;
	SET_KEY_DET_MODE(g_key_cntx.keypad_status, (U8)kbd_2_keys_det_mode);
    g_key_cntx.buffer[0].mmi_key_code = 1;
    g_key_cntx.buffer[0].mmi_key_type = 15;
    g_key_cntx.buffer[0].is_2step     = 0;
    g_key_cntx.buffer[0].is_clear     = 1;
    g_key_cntx.buffer[0].is_combo     = 0;
    g_key_cntx.buffer[1].mmi_key_code = 18;
    g_key_cntx.buffer[1].mmi_key_type = 25;
    g_key_cntx.buffer[1].is_2step     = 0;
    g_key_cntx.buffer[1].is_clear     = 1;
    g_key_cntx.buffer[1].is_combo     = 0;
    get_key_data(&data, 0);
    MMI_ASSERT(key_data_cmp(&data, &g_key_cntx.buffer[0]));
    get_key_data(&data, 1);
    MMI_ASSERT(key_data_cmp(&data, &g_key_cntx.buffer[1]));
    
    restore_key_data(buffer, &len);
    g_key_cntx.keypad_status = keypad_status;
    kal_prompt_trace(MOD_MMI, "[UT_KEY] test get key data PASS");
    return MMI_RET_OK;	
}

/*****************************************************************************
 * FUNCTION
 *  ut_post_update_2step_key_state
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0004
 * <Test Case Content> judge is full ctrl key
 * <Test Case Number> 5
 * <Scenario>
 *     1. 2step key, up
 *     2. 2step key, other key event
 *     3. non-2step key
 * <Expected Result>
 *     1. FULL_UP
 *     2. no change
 *     3. no change
 * </test case description>
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret ut_post_update_2step_key_state(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __KBD_2STEP_KEY_SUPPORT__
    S32 i;
	U8 key_code;
	U8 state;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	key_code = g_key_cntx._2step_key.mmi_key_code;
	state = g_key_cntx._2step_key.state;	
    g_key_cntx._2step_key.mmi_key_code = KEY_CAMERA;
    g_key_cntx._2step_key.state = 255;
    for (i = 0; i < MAX_KEY_TYPE; i++)
    {
        if (i != KEY_EVENT_UP)
        {
            post_update_2step_key_state(KEY_CAMERA, (U8)i);
            MMI_ASSERT(g_key_cntx._2step_key.state == 255);
        }
        post_update_2step_key_state(KEY_0, (U8)i);
        MMI_ASSERT(g_key_cntx._2step_key.state == 255);
    }
    post_update_2step_key_state(KEY_CAMERA, KEY_EVENT_UP);
    MMI_ASSERT(g_key_cntx._2step_key.state == FULL_UP);
    g_key_cntx._2step_key.mmi_key_code = key_code;
    g_key_cntx._2step_key.state = state;
    kal_prompt_trace(MOD_MMI, "[UT_KEY] test post_update_2step_key_state PASS");
#endif
    return MMI_RET_OK;	
}


/*****************************************************************************
 * FUNCTION
 *  ut_pre_update_2step_key_state
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0004
 * <Test Case Content> judge is full ctrl key
 * <Test Case Number> 5
 * <Scenario>
 *     1. 2step key, half down
 *     2. 2step key, full down
 *     3. 2step key, other key event
 *     4. non-2step key
 * <Expected Result>
 *     1. HALF_DOWN
 *     2. FULL_DOWN
 *     3. no change
 *     4. no change
 * </test case description>
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret ut_pre_update_2step_key_state(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __KBD_2STEP_KEY_SUPPORT__
    U8 i;
	U8 key_code;
	U8 state;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	key_code = g_key_cntx._2step_key.mmi_key_code;
	state = g_key_cntx._2step_key.state;
    g_key_cntx._2step_key.mmi_key_code = KEY_CAMERA;
    g_key_cntx._2step_key.state = 255;
    for (i = 0; i < MAX_KEY_TYPE; i++)
    {
        if (i != KEY_HALF_PRESS_DOWN && i != KEY_FULL_PRESS_DOWN)
        {
            pre_update_2step_key_state(KEY_CAMERA, i);
            MMI_ASSERT(g_key_cntx._2step_key.state == 255);
        }
        pre_update_2step_key_state(KEY_0, i);
        MMI_ASSERT(g_key_cntx._2step_key.state == 255);        
    }
    pre_update_2step_key_state(KEY_CAMERA, KEY_HALF_PRESS_DOWN);
    MMI_ASSERT(g_key_cntx._2step_key.state == HALF_DOWN);

    pre_update_2step_key_state(KEY_CAMERA, KEY_FULL_PRESS_DOWN);
    MMI_ASSERT(g_key_cntx._2step_key.state == FULL_DOWN);
    g_key_cntx._2step_key.mmi_key_code = key_code;
    g_key_cntx._2step_key.state = state;
    kal_prompt_trace(MOD_MMI, "[UT_KEY] test pre_update_2step_key_state PASS");
#endif
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  ut_get_exec_key_evt
 * DESCRIPTION
 * <test case description>
 * <Test Case Group> KEY_EVENT
 * <Test Case ID>    KEY_EVENT_0004
 * <Test Case Content> judge is full ctrl key
 * <Test Case Number> 5
 * <Scenario>
 *     1. 2step key, half down
 *     2. 2step key, full down
 *     3. 2step key, other key event
 *     4. non-2step key
 * <Expected Result>
 *     1. HALF_DOWN
 *     2. FULL_DOWN
 *     3. no change
 *     4. no change
 * </test case description>
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret ut_get_exec_key_evt(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_key_evt_struct exec_evt[2];
    key_data_struct    data;
    U32 evt_num = 255;
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data.is_2step = MMI_TRUE;
    data.is_combo = MMI_FALSE;
#ifdef __KBD_2STEP_KEY_SUPPORT__
    data.mmi_key_code = KEY_CAMERA;
    g_key_cntx._2step_key.mmi_key_code = KEY_CAMERA;
    g_key_cntx._2step_key.state = HALF_DOWN;
    data.mmi_key_type = KEY_EVENT_UP;
    get_exec_key_evt(&data, exec_evt, &evt_num);
    MMI_ASSERT(exec_evt[0].mmi_key_code == KEY_CAMERA);
    MMI_ASSERT(exec_evt[0].mmi_key_type == KEY_HALF_PRESS_UP);
    MMI_ASSERT(evt_num == 1);

    g_key_cntx._2step_key.state = FULL_DOWN;
    get_exec_key_evt(&data, exec_evt, &evt_num);
    MMI_ASSERT(exec_evt[0].mmi_key_code == KEY_CAMERA);
    MMI_ASSERT(exec_evt[0].mmi_key_type == KEY_HALF_PRESS_UP);
    MMI_ASSERT(exec_evt[1].mmi_key_code == KEY_CAMERA);
    MMI_ASSERT(exec_evt[1].mmi_key_type == KEY_EVENT_UP);    
    MMI_ASSERT(evt_num == 2); 

    for (i = 0; i < MAX_KEY_TYPE; i++)
    {
        if (i != KEY_EVENT_UP)
        {
            data.mmi_key_type = i;
            get_exec_key_evt(&data, exec_evt, &evt_num);
            MMI_ASSERT(exec_evt[0].mmi_key_code == KEY_CAMERA);
            MMI_ASSERT(exec_evt[0].mmi_key_type == i);
            MMI_ASSERT(evt_num == 1);           
        }
    }
#endif
    data.is_2step = MMI_FALSE;
    data.mmi_key_code = KEY_0;
    SET_KPD_MODE(g_key_cntx.keypad_status, KEYPAD_2KEY_NUMBER);

    for (i = 0; i < MAX_KEY_TYPE; i++)
    {
        data.mmi_key_type = i;
        get_exec_key_evt(&data, exec_evt, &evt_num);
        MMI_ASSERT(exec_evt[0].mmi_key_code == KEY_0);
        MMI_ASSERT(exec_evt[0].mmi_key_type == i);
        MMI_ASSERT(evt_num == 1);      

    }
    SET_KPD_MODE(g_key_cntx.keypad_status, KEYPAD_2KEY_QWERTY);

    for (i = 0; i < MAX_KEY_TYPE; i++)
    {
        data.mmi_key_type = i;
        get_exec_key_evt(&data, exec_evt, &evt_num);
        MMI_ASSERT(exec_evt[0].mmi_key_code == KEY_0);
        MMI_ASSERT(exec_evt[0].mmi_key_type == i);
        MMI_ASSERT(evt_num == 1);      

    }

    SET_KPD_MODE(g_key_cntx.keypad_status, KEYPAD_3KEY_QWERTY);

    for (i = 0; i < MAX_KEY_TYPE; i++)
    {
        data.mmi_key_type = i;
        get_exec_key_evt(&data, exec_evt, &evt_num);
        MMI_ASSERT(exec_evt[0].mmi_key_code == KEY_0);
        MMI_ASSERT(exec_evt[0].mmi_key_type == i);
        MMI_ASSERT(evt_num == 1);      

    }

    SET_KPD_MODE(g_key_cntx.keypad_status, KEYPAD_3KEY_NUMBER);

    for (i = 0; i < MAX_KEY_TYPE; i++)
    {
        data.mmi_key_type = i;
        get_exec_key_evt(&data, exec_evt, &evt_num);
        MMI_ASSERT(exec_evt[0].mmi_key_code == KEY_0);
        MMI_ASSERT(exec_evt[0].mmi_key_type == i);
        MMI_ASSERT(evt_num == 1);      

    }
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    SET_KPD_MODE(g_key_cntx.keypad_status, KEYPAD_1KEY_NUMBER);
    g_key_cntx.buf_len = 2;
    g_key_cntx.buffer[0].mmi_key_code = KEY_SHIFT;
    g_key_cntx.buffer[1].mmi_key_code = KEY_FN;

    data.is_2step = MMI_FALSE;
    data.mmi_key_code = KEY_FN;

    for (data.mmi_key_type = 0; data.mmi_key_type < MAX_KEY_TYPE; data.mmi_key_type++)
    {
        get_exec_key_evt(&data, exec_evt, &evt_num);
        MMI_ASSERT(evt_num == 1);
        MMI_ASSERT(exec_evt[0].mmi_key_code == KEY_FN);
        MMI_ASSERT(exec_evt[0].mmi_key_type == data.mmi_key_type);        
    }
    data.mmi_key_code = KEY_SHIFT;

    for (data.mmi_key_type = 0; data.mmi_key_type < MAX_KEY_TYPE; data.mmi_key_type++)
    {
        get_exec_key_evt(&data, exec_evt, &evt_num);
        MMI_ASSERT(evt_num == 1);
        MMI_ASSERT(exec_evt[0].mmi_key_code == KEY_SHIFT);
        MMI_ASSERT(exec_evt[0].mmi_key_type == data.mmi_key_type);        
    }

    g_key_cntx.buffer[0].mmi_key_code = KEY_1;
    g_key_cntx.buffer[1].mmi_key_code = KEY_FN; 

    data.mmi_key_code = KEY_FN;

    for (data.mmi_key_type = 0; data.mmi_key_type < MAX_KEY_TYPE; data.mmi_key_type++)
    {
        get_exec_key_evt(&data, exec_evt, &evt_num);
        MMI_ASSERT(evt_num == 1);
        MMI_ASSERT(exec_evt[0].mmi_key_code == KEY_FN);
        MMI_ASSERT(exec_evt[0].mmi_key_type == data.mmi_key_type);        
    }
    data.mmi_key_code = KEY_1;

    for (data.mmi_key_type = 0; data.mmi_key_type < MAX_KEY_TYPE; data.mmi_key_type++)
    {
        get_exec_key_evt(&data, exec_evt, &evt_num);
        MMI_ASSERT(evt_num == 1);
        MMI_ASSERT(exec_evt[0].mmi_key_code == KEY_1);
        MMI_ASSERT(exec_evt[0].mmi_key_type == data.mmi_key_type);        
    }  

    g_key_cntx.buffer[0].mmi_key_code = KEY_FN;
    g_key_cntx.buffer[1].mmi_key_code = KEY_1; 

    data.mmi_key_code = KEY_1;

    for (data.mmi_key_type = 0; data.mmi_key_type < MAX_KEY_TYPE; data.mmi_key_type++)
    {
        get_exec_key_evt(&data, exec_evt, &evt_num);
        MMI_ASSERT(evt_num == 1);
        MMI_ASSERT(exec_evt[0].mmi_key_code == KEY_1);
        MMI_ASSERT(exec_evt[0].mmi_key_type == data.mmi_key_type);        
    }  

    data.mmi_key_code = KEY_FN;

    for (data.mmi_key_type = 0; data.mmi_key_type < MAX_KEY_TYPE; data.mmi_key_type++)
    {
        get_exec_key_evt(&data, exec_evt, &evt_num);
        MMI_ASSERT(evt_num == 1);
        MMI_ASSERT(exec_evt[0].mmi_key_code == KEY_FN);
        MMI_ASSERT(exec_evt[0].mmi_key_type == data.mmi_key_type);        
    }   

    g_key_cntx.buffer[0].mmi_key_code = KEY_0;
    g_key_cntx.buffer[0].mmi_key_type = KEY_EVENT_DOWN;
    g_key_cntx.buffer[1].mmi_key_code = KEY_1; 
    g_key_cntx.buffer[1].mmi_key_type = KEY_EVENT_DOWN;
    data.mmi_key_code = KEY_1;
    data.mmi_key_type = KEY_EVENT_DOWN;
    get_exec_key_evt(&data, exec_evt, &evt_num);
    MMI_ASSERT(evt_num == 2);
    MMI_ASSERT(exec_evt[0].mmi_key_code == KEY_0);
    MMI_ASSERT(exec_evt[0].mmi_key_type == KEY_EVENT_UP);
    MMI_ASSERT(exec_evt[1].mmi_key_code == KEY_1);
    MMI_ASSERT(exec_evt[1].mmi_key_type == KEY_EVENT_DOWN);
    MMI_ASSERT(g_key_cntx.buffer[0].mmi_key_type == KEY_EVENT_UP);
#endif
    kal_prompt_trace(MOD_MMI, "[UT_KEY] test get_exec_key_evt PASS");
    return MMI_RET_OK;
}

/****************************************************************
 *  Unit test for is_need_write_back
 ****************************************************************/
typedef struct
{
    dev_key_evt_struct  test_evt;
    MMI_BOOL is_active;
    U8 len;
    dev_key_evt_struct  temp_buffer[2];
    MMI_BOOL res;
} test_write_back_data;

test_write_back_data _wb_data[] =
{
    {
        {DEVICE_KEY_1, DRV_WM_KEYRELEASE, MMI_FALSE},
        MMI_TRUE,  
        0,
        {
            {0,0,MMI_FALSE}, 
            {0,0, MMI_FALSE}
        },
        MMI_TRUE
    },
    {
        {DEVICE_KEY_1, DRV_WM_KEYRELEASE, MMI_FALSE},
        MMI_FALSE,  
        0,
        {
            {0,0,MMI_FALSE}, 
            {0,0, MMI_FALSE}
        },
        MMI_FALSE
    },    
    {
        {DEVICE_KEY_END, DRV_WM_KEYPRESS, MMI_FALSE},
        MMI_FALSE,    
        1,
        {
            {DEVICE_KEY_1, DRV_WM_KEYRELEASE, MMI_FALSE},
            {0, 0, MMI_FALSE}
        },    
        MMI_TRUE
    },
    {
        {DEVICE_KEY_END, DRV_WM_KEYLONGPRESS, MMI_FALSE},
        MMI_FALSE,    
        2,
        {
            {DEVICE_KEY_1, DRV_WM_KEYRELEASE, MMI_FALSE},
            {DEVICE_KEY_END, DRV_WM_KEYLONGPRESS, MMI_FALSE}
        },    
        MMI_FALSE
    },
    {
        {DEVICE_KEY_END, DRV_WM_KEYLONGPRESS, MMI_FALSE},
        MMI_FALSE,    
        2,
        {
            {DEVICE_KEY_1, DRV_WM_KEYRELEASE, MMI_FALSE},
            {DEVICE_KEY_2, DRV_WM_KEYLONGPRESS, MMI_FALSE}
        },    
        MMI_TRUE
    },
    {
        {DEVICE_KEY_END, DRV_WM_KEYRELEASE, MMI_FALSE},
        MMI_FALSE,    
        2,
        {
            {DEVICE_KEY_1, DRV_WM_KEYRELEASE, MMI_FALSE},
            {DEVICE_KEY_2, DRV_WM_KEYLONGPRESS, MMI_FALSE}
        },    
        MMI_TRUE
    },
    {
        {DEVICE_KEY_END, DRV_WM_KEYRELEASE, MMI_FALSE},
        MMI_FALSE,    
        2,
        {
            {DEVICE_KEY_END, DRV_WM_KEYRELEASE, MMI_FALSE},
            {DEVICE_KEY_2, DRV_WM_KEYLONGPRESS, MMI_FALSE}
        },    
        MMI_TRUE
    }      
};   
mmi_ret ut_is_need_write_back(void *para)
{
    S32 i;
    key_data_struct data;

    for (i = 0; i < sizeof (_wb_data)/sizeof(_wb_data[0]); i++)
    {
        init_key_data_buf();
        if (_wb_data[i].is_active == MMI_TRUE)
        {
            data.mmi_key_code = (U8)get_mmi_key_code(_wb_data[i].test_evt.device_key_code);
            insert_key_data(&data);
        }    
        MMI_ASSERT(is_need_write_back(&_wb_data[i].test_evt,
                    _wb_data[i].temp_buffer, _wb_data[i].len) == _wb_data[i].res);
    }
    kal_prompt_trace(MOD_MMI, "[UT_KEY] test is_need_write_back PASS");
    return MMI_RET_OK;
}


void save_look_ahead_buffer(dev_key_evt_struct *p, U8* r, U8* w, U8 *n)
{
    memcpy(p, g_key_cntx.look_ahead, sizeof(g_key_cntx.look_ahead));
    *r = g_key_cntx.r_look_ahead;
    *w = g_key_cntx.w_look_ahead;
    *n = g_key_cntx.num_look_ahead;
}
void restore_look_ahead_buffer(dev_key_evt_struct *p, U8 *r, U8* w, U8 *n)
{
    memcpy(g_key_cntx.look_ahead, p, sizeof(g_key_cntx.look_ahead));
    g_key_cntx.r_look_ahead = *r;
    g_key_cntx.w_look_ahead = *w;
    g_key_cntx.num_look_ahead = *n;
}
mmi_ret ut_read_look_ahead_buffer(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dev_key_evt_struct buf[LOOK_AHEAD_BUF_LEN];
    U8 r;
    U8 w;
    U8 n;
    S32 i;
    U8 *rp = &g_key_cntx.r_look_ahead;
    U8 *wp = &g_key_cntx.w_look_ahead;
    U8 *np = &g_key_cntx.num_look_ahead;
    dev_key_evt_struct dev;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    save_look_ahead_buffer(buf, &r, &w, &n);
    for (i = 0; i < LOOK_AHEAD_BUF_LEN; i++)
    {
        g_key_cntx.look_ahead[i].device_key_code = i;
    }
    for (*rp = 0; *rp < LOOK_AHEAD_BUF_LEN; (*rp)++)
    {
        for (*wp = 0; *wp < LOOK_AHEAD_BUF_LEN; (*wp)++)
        {
            U8 temp_r = *rp;
            if (*wp > *rp)
            {
                *np = *wp - *rp;

                MMI_ASSERT(read_look_ahead_buffer(&dev) == MMI_TRUE);
                MMI_ASSERT(dev.device_key_code == temp_r);
                MMI_ASSERT(g_key_cntx.r_look_ahead == ((++temp_r) % LOOK_AHEAD_BUF_LEN));
            }
            else if (*wp < *rp)
            {
                *np = LOOK_AHEAD_BUF_LEN - (*rp - *wp);

                MMI_ASSERT(read_look_ahead_buffer(&dev) == MMI_TRUE);
                MMI_ASSERT(dev.device_key_code == temp_r);
                MMI_ASSERT(g_key_cntx.r_look_ahead == ((++temp_r) % LOOK_AHEAD_BUF_LEN));
            }
            else
            {
                *np = 0;

                MMI_ASSERT(read_look_ahead_buffer(&dev) == MMI_FALSE);
                MMI_ASSERT(g_key_cntx.r_look_ahead == temp_r);
                *np = LOOK_AHEAD_BUF_LEN;
                MMI_ASSERT(read_look_ahead_buffer(&dev) == MMI_TRUE);
                MMI_ASSERT(dev.device_key_code == temp_r);
                MMI_ASSERT(g_key_cntx.r_look_ahead == ((++temp_r) % LOOK_AHEAD_BUF_LEN));
            }
             *rp = temp_r;
        }
    }
    restore_look_ahead_buffer(buf, &r, &w, &n);
    kal_prompt_trace(MOD_MMI, "[UT_KEY] test read_look_ahead_buffer PASS");
    return MMI_RET_OK;
}

mmi_ret ut_write_look_ahead_buffer(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dev_key_evt_struct buf[LOOK_AHEAD_BUF_LEN];
    U8 r;
    U8 w;
    U8 n;
    U8 *rp = &g_key_cntx.r_look_ahead;
    U8 *wp = &g_key_cntx.w_look_ahead;
    U8 *np = &g_key_cntx.num_look_ahead;
    dev_key_evt_struct dev;    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    save_look_ahead_buffer(buf, &r, &w, &n);
    
    for (*rp = 0; *rp < LOOK_AHEAD_BUF_LEN; (*rp)++)
    {
        for (*wp = 0; *wp < LOOK_AHEAD_BUF_LEN; (*wp)++)
        {
            U8 temp_w = *wp;
            if (*wp > *rp)
            {
                *np = *wp - *rp;
                dev.device_key_code = *wp;
                MMI_ASSERT(write_look_ahead_buffer(&dev) == MMI_TRUE);
                MMI_ASSERT(g_key_cntx.look_ahead[temp_w].device_key_code == temp_w);
                MMI_ASSERT(g_key_cntx.w_look_ahead == (++temp_w) % LOOK_AHEAD_BUF_LEN);       
            } 
            else if (*wp < *rp)
            {
                *np = LOOK_AHEAD_BUF_LEN - (*rp - *wp);
                dev.device_key_code = *wp;
                MMI_ASSERT(write_look_ahead_buffer(&dev) == MMI_TRUE);
                MMI_ASSERT(g_key_cntx.look_ahead[temp_w].device_key_code == temp_w);
                MMI_ASSERT(g_key_cntx.w_look_ahead == (++temp_w) % LOOK_AHEAD_BUF_LEN);
            }
            else
            {
                *np = LOOK_AHEAD_BUF_LEN;
                MMI_ASSERT(write_look_ahead_buffer(&dev) == MMI_FALSE);
                *np = 0;
                dev.device_key_code = *wp;
                MMI_ASSERT(write_look_ahead_buffer(&dev) == MMI_TRUE);
                MMI_ASSERT(g_key_cntx.look_ahead[temp_w].device_key_code == temp_w);
                MMI_ASSERT(g_key_cntx.w_look_ahead == (++temp_w) % LOOK_AHEAD_BUF_LEN);

            }    
            *wp = temp_w;
        }
    }
    restore_look_ahead_buffer(buf, &r, &w, &n);
    kal_prompt_trace(MOD_MMI, "[UT_KEY] test write_look_ahead_buffer PASS");
    return MMI_RET_OK;    
}

/*************************************************************************************
 * Unit test for mmi_frm_clear_key_events
 *************************************************************************************/
const dev_key_evt_struct  clear_event_in_data1[] =
{
    {DEVICE_KEY_END, DRV_WM_KEYPRESS,     MMI_FALSE},
    {DEVICE_KEY_END, DRV_WM_KEYLONGPRESS, MMI_FALSE},
    {DEVICE_KEY_END, DRV_WM_KEYRELEASE,   MMI_FALSE},
    {DEVICE_KEY_END, DRV_WM_KEYPRESS,     MMI_FALSE},
    {DEVICE_KEY_END, DRV_WM_KEYLONGPRESS, MMI_FALSE},
    {DEVICE_KEY_END, DRV_WM_KEYRELEASE,   MMI_FALSE},
    {DEVICE_KEY_END, DRV_WM_KEYPRESS,     MMI_FALSE},
    {DEVICE_KEY_END, DRV_WM_KEYLONGPRESS, MMI_FALSE},
    {DEVICE_KEY_END, DRV_WM_KEYRELEASE,   MMI_FALSE},
    {DEVICE_KEY_NONE, 0, 0}
};

const dev_key_evt_struct clear_event_out_data1[] =
{
    {DEVICE_KEY_END, DRV_WM_KEYPRESS,     MMI_FALSE},
    {DEVICE_KEY_END, DRV_WM_KEYLONGPRESS, MMI_FALSE},
    {DEVICE_KEY_END, DRV_WM_KEYRELEASE,   MMI_FALSE},
    {DEVICE_KEY_NONE, 0, 0}
};

const U8 active_key_codes1[] = {KEY_1, KEY_INVALID};

const dev_key_evt_struct  clear_event_in_data2[] =
{
    {DEVICE_KEY_1, DRV_WM_KEYRELEASE,     MMI_FALSE},
    {DEVICE_KEY_2, DRV_WM_KEYRELEASE,     MMI_FALSE},   
    {DEVICE_KEY_NONE, 0, 0}
};

const dev_key_evt_struct clear_event_out_data2[] =
{
    {DEVICE_KEY_1, DRV_WM_KEYRELEASE,     MMI_FALSE},
    {DEVICE_KEY_2, DRV_WM_KEYRELEASE,     MMI_FALSE},      
    {DEVICE_KEY_NONE, 0, 0}
};

const U8 active_key_codes2[] = {KEY_1, KEY_2, KEY_INVALID};

const dev_key_evt_struct  clear_event_in_data3[] =
{
    {DEVICE_KEY_1, DRV_WM_KEYRELEASE,     MMI_FALSE},
    {DEVICE_KEY_2, DRV_WM_KEYRELEASE,     MMI_FALSE},   
    {DEVICE_KEY_NONE, 0, 0}
};

const dev_key_evt_struct clear_event_out_data3[] =
{
    {DEVICE_KEY_1, DRV_WM_KEYRELEASE,     MMI_FALSE},
    {DEVICE_KEY_2, DRV_WM_KEYRELEASE,     MMI_FALSE},      
    {DEVICE_KEY_NONE, 0, 0}
};

const U8 active_key_codes3[] = {KEY_1, KEY_2, KEY_INVALID};
const dev_key_evt_struct  clear_event_in_data4[] =
{
    {DEVICE_KEY_NONE, 0, 0}
};

const dev_key_evt_struct clear_event_out_data4[] =
{
    {DEVICE_KEY_NONE, 0, 0}
};

const U8 active_key_codes4[] = {KEY_1, KEY_2, KEY_INVALID};
const dev_key_evt_struct  clear_event_in_data5[] =
{
    {DEVICE_KEY_1, DRV_WM_KEYPRESS,     MMI_FALSE},    
    {DEVICE_KEY_1, DRV_WM_KEYRELEASE,     MMI_FALSE}, 
    {DEVICE_KEY_2, DRV_WM_KEYPRESS,     MMI_FALSE},    
    {DEVICE_KEY_2, DRV_WM_KEYRELEASE,     MMI_FALSE},     
    {DEVICE_KEY_NONE, 0, 0}
};

const dev_key_evt_struct clear_event_out_data5[] =
{
    {DEVICE_KEY_NONE, 0, 0}
};
const U8 active_key_codes5[] = {KEY_INVALID};


const dev_key_evt_struct  clear_event_in_data6[] =
{
    {DEVICE_KEY_1,  DRV_WM_KEYRELEASE,     MMI_FALSE},    
    {DEVICE_KEY_END, DRV_WM_KEYPRESS,     MMI_FALSE}, 
    {DEVICE_KEY_END, DRV_WM_KEYLONGPRESS,     MMI_FALSE},    
    {DEVICE_KEY_END, DRV_WM_KEYREPEATED,     MMI_FALSE},     
    {DEVICE_KEY_NONE, 0, 0}
};

const dev_key_evt_struct clear_event_out_data6[] =
{
    {DEVICE_KEY_1, DRV_WM_KEYRELEASE,     MMI_FALSE},
    {DEVICE_KEY_END, DRV_WM_KEYPRESS,     MMI_FALSE}, 
    {DEVICE_KEY_END, DRV_WM_KEYLONGPRESS,     MMI_FALSE},
    {DEVICE_KEY_NONE, 0, 0}
};

const U8 active_key_codes6[] = {KEY_1, KEY_INVALID};


const dev_key_evt_struct  clear_event_in_data7[] =
{
    {DEVICE_KEY_END,  DRV_WM_KEYRELEASE,     MMI_FALSE},    
    {DEVICE_KEY_END, DRV_WM_KEYPRESS,     MMI_FALSE}, 
    {DEVICE_KEY_END, DRV_WM_KEYLONGPRESS,     MMI_FALSE},    
    {DEVICE_KEY_END, DRV_WM_KEYRELEASE,     MMI_FALSE},
    {DEVICE_KEY_END, DRV_WM_KEYPRESS,     MMI_FALSE}, 
    {DEVICE_KEY_END, DRV_WM_KEYLONGPRESS,     MMI_FALSE},    
    {DEVICE_KEY_END, DRV_WM_KEYRELEASE,     MMI_FALSE},   
    {DEVICE_KEY_NONE, 0, 0}
};

const dev_key_evt_struct clear_event_out_data7[] =
{
    {DEVICE_KEY_END, DRV_WM_KEYRELEASE,     MMI_FALSE},
    {DEVICE_KEY_END, DRV_WM_KEYPRESS,     MMI_FALSE}, 
    {DEVICE_KEY_END, DRV_WM_KEYLONGPRESS,     MMI_FALSE},
    {DEVICE_KEY_END, DRV_WM_KEYRELEASE,     MMI_FALSE}, 
    {DEVICE_KEY_NONE, 0, 0}
};

const U8 active_key_codes7[] = {KEY_END, KEY_INVALID};

typedef struct
{
    const dev_key_evt_struct *in;
    const dev_key_evt_struct *out;
    const U8* active_key_code;
} test_clear_event_data;


const test_clear_event_data clear_evt_data[] =
{
    {clear_event_in_data1, clear_event_out_data1, active_key_codes1},
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__    
    {clear_event_in_data2, clear_event_out_data2, active_key_codes2},
    {clear_event_in_data3, clear_event_out_data3, active_key_codes3},
    {clear_event_in_data4, clear_event_out_data4, active_key_codes4},
    {clear_event_in_data5, clear_event_out_data5, active_key_codes5},
#endif
    {clear_event_in_data6, clear_event_out_data6, active_key_codes6},
    {clear_event_in_data7, clear_event_out_data7, active_key_codes7}
};

#define CLEAR_KEY_EVENT_TEST_CASE_NUM sizeof(clear_evt_data) / sizeof(clear_evt_data[0])
mmi_ret ut_mmi_frm_clear_key_events(void *para)
{
    U32 i;
    U32 j;
    dev_key_evt_struct dev;
    key_data_struct data;
    for (i = 0; i < CLEAR_KEY_EVENT_TEST_CASE_NUM; i++)
    {
        init_key_data_buf();
        j = 0;
        while(clear_evt_data[i].in[j].device_key_code != DEVICE_KEY_NONE)
        {
            write_look_ahead_buffer((dev_key_evt_struct *)&(clear_evt_data[i].in[j]));
            j++;
        }
        j = 0;
        while (clear_evt_data[i].active_key_code && clear_evt_data[i].active_key_code [j] != KEY_INVALID)
        {
            data.mmi_key_code = clear_evt_data[i].active_key_code[j];
            data.is_clear = MMI_FALSE;
            insert_key_data(&data);
            j++;
        }
        MMI_ASSERT(g_key_cntx.buf_len == j);
        mmi_frm_clear_key_events();
        j = 0;
        while(clear_evt_data[i].out[j].device_key_code != DEVICE_KEY_NONE)
        {
            MMI_ASSERT(read_look_ahead_buffer(&dev) == MMI_TRUE);
            MMI_ASSERT(dev.device_key_code == clear_evt_data[i].out[j].device_key_code);
            MMI_ASSERT(dev.device_key_type == clear_evt_data[i].out[j].device_key_type);
            MMI_ASSERT(dev.is_clear == clear_evt_data[i].out[j].is_clear);
            j++;
        }
        MMI_ASSERT(read_look_ahead_buffer(&dev) == MMI_FALSE);
        for (j = 0; j < g_key_cntx.buf_len;j++)
        {
            MMI_ASSERT(g_key_cntx.buffer[j].is_clear == MMI_TRUE);
        }
   
    }    
    kal_prompt_trace(MOD_MMI, "[UT_KEY] test mmi_frm_clear_key_events PASS");
    return MMI_RET_OK;
}

/************************************************************************/
/* Test for keypad pointer change                                       */
/************************************************************************/
typedef struct
{
    drv_get_key_func old_ptr;
    drv_get_key_func new_ptr;
    MMI_BOOL is_keypad_busy;
} key_ptr_change;
U8 buffer1_data_num;
kal_bool drv_buffer1(kbd_data *p)
{
    buffer1_data_num = 0;
    return KAL_FALSE;
}
U8 buffer2_data_num; 
kal_bool drv_buffer2(kbd_data *p)
{
    buffer2_data_num = 0;
    return KAL_FALSE;
}
const key_ptr_change ptr_change_data[] = 
{
    {NULL, drv_buffer1, MMI_FALSE},
    {drv_buffer1, drv_buffer1, MMI_TRUE},
    {drv_buffer1, drv_buffer1, MMI_FALSE},
    {drv_buffer1, drv_buffer2, MMI_TRUE},
    {drv_buffer1, drv_buffer2, MMI_FALSE},
};

mmi_ret ut_process_key_ptr_change(void *para)
{
    U32 i;
    mmi_eq_keypad_detect_ind_struct k;
    process_key_ptr_change(NULL);
    for (i = 0; i < sizeof(ptr_change_data) / sizeof(ptr_change_data[0]); i++)
    {        
        k.func = ptr_change_data[i].new_ptr;
        g_key_cntx.keypad_ptr = ptr_change_data[i].old_ptr;
        if (ptr_change_data[i].is_keypad_busy == MMI_TRUE)
        {
            g_key_cntx.buf_len = 1;
            buffer2_data_num = 15;
        }
        else
        {
            buffer1_data_num = 15;
            g_key_cntx.buf_len = 0;
        }    
        process_key_ptr_change(&k);
        if (g_key_cntx.keypad_ptr != ptr_change_data[i].old_ptr &&
            ptr_change_data[i].is_keypad_busy == MMI_FALSE)
        {
            MMI_ASSERT(g_key_cntx.keypad_ptr  == ptr_change_data[i].new_ptr);
            if (ptr_change_data[i].old_ptr != NULL)
            MMI_ASSERT(buffer1_data_num == 0);
        }
        else
        {
            MMI_ASSERT( g_key_cntx.keypad_ptr == ptr_change_data[i].old_ptr);
            if (ptr_change_data[i].old_ptr != ptr_change_data[i].new_ptr)
            {
                MMI_ASSERT(buffer2_data_num == 0);
            }
        }
    }
    kal_prompt_trace(MOD_MMI, "[UT_KEY] test process_key_ptr_change PASS");
    return MMI_RET_OK;
}

/************************************************************************/
/* Unit Test for is_combo_key                                           */
/************************************************************************/
mmi_ret ut_is_combo_key(void *para)
{
    U32 i;
#ifndef __MMI_QWERTY_KEYPAD_SUPPORT__
    for (i = 0; i < MAX_KEY_NUM; i++)
    {
        MMI_ASSERT(is_combo_key((S16)i) == MMI_FALSE);
    }
#else
    for (i = 0; i < MAX_KEY_NUM; i++)
    {
        if (i == KEY_FN || i == KEY_SHIFT || i == KEY_CTRL || i == KEY_ALT)
        {
            MMI_ASSERT(is_combo_key((S16)i) == MMI_TRUE);
        }
        else
        {
            MMI_ASSERT(is_combo_key((S16)i) == MMI_FALSE);
        }
    }
#endif
    kal_prompt_trace(MOD_MMI, "[UT_KEY] test is_combo_key PASS");
    return MMI_RET_OK;
}


/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 +
 + key event unit test framework
 +
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/* key unit test table size */
#define KEY_UT_TABLE_ENTRY  sizeof(g_key_ut_table) / sizeof(g_key_ut_table[0])

/* unit test function */
typedef mmi_ret (*unit_test_func)(void *para);

/* unit test struct */
typedef struct
{
    U8 index;
    unit_test_func test;
} mmi_unit_test_struct;


/* key event unit test table */
const static mmi_unit_test_struct g_key_ut_table[] = 
{
    {1, ut_is_need_write_back},
    {2, ut_read_look_ahead_buffer},
    {3, ut_write_look_ahead_buffer},
    {4, ut_mmi_frm_clear_key_events},
    {5, ut_process_key_ptr_change},
    {6, ut_is_combo_key},
    {7, ut_get_mmi_key_events},
    {8, ut_post_update_key_data_buf},
    {9, ut_pre_update_key_data_buf},
    {10, ut_get_2step_key_state},
    {11, ut_get_key_state},
    {12, ut_remove_key_data},
    {13, ut_update_key_data},
    {14, ut_search_key_data},
    {15, ut_insert_key_data},
    {16, ut_init_key_data_buf},
    {17, ut_is_2step_key},
    {18, ut_is_legal_key_type},
    {19, ut_get_mmi_key_code},
    {20, ut_get_device_key_code},
    {21, ut_get_mmi_key_type},
    {22, ut_is_full_ctrled},
    {23, ut_gen_key_data},
    {24, ut_get_rotated_mmi_key_code},
    {25, ut_enter_to_lsk},
    {26, ut_mmi_key_code_convert},
    {27, ut_get_key_data},
    {28, ut_post_update_2step_key_state},
    {29, ut_pre_update_2step_key_state},
    {30, ut_get_exec_key_evt}
};
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_key_event_ut
 * DESCRIPTION
 *  This function is key event unit test external interface.
 *  It is invoked in events.c (mmi_proc_inject_string)
 * 
 * PARAMETERS
 *  index         :[IN]  test item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_key_event_ut(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == 0)
    {
        for (i = 0; i < KEY_UT_TABLE_ENTRY; i++)
        {
            g_key_ut_table[i].test(NULL);
        }
    }
    else
    {
        for (i = 0; i < KEY_UT_TABLE_ENTRY; i++)
        {
            if (g_key_ut_table[i].index == index)
            {
                g_key_ut_table[i].test(NULL);
            }
        }
    }
}
#endif /* MMI_FRM_KEY_EVENT_UT */