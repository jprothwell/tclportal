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
 *   mdi_audio.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Audio interfce source file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#include "stdC.h"
#include "L4Dr1.h"
#include "MMIDataType.h"
#include "kal_trace.h"  /* Debug Info */
#include "DebugInitDef.h"       /* Debug Info */
#include "mmi_trc.h"    /* Debug Info */
#include "ProtocolEvents.h"
#include "EventsGprot.h"
#include "QueueGprot.h"
#include "TimerEvents.h"
#include "ProfileGProts.h"
#include "stack_config.h"

#include "mdi_datatype.h"
#include "mdi_include.h"
#include "mdi_audio.h"
#include "resource_audio.h"
#include "aud_defs.h"
#include "aud_build_cache.h"
#include "med_global.h"
#include "med_struct.h"
#include "med_v_struct.h"
#include "med_api.h"
#include "med_main.h"
#ifdef __MMI_POC__
#include "mmi2poc_struct.h"
#include "mmi2poc_enums.h"
#endif /* __MMI_POC__ */
#include "SoundEffect.h"
#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__)
#include "av_bt.h"
#endif
#if defined(__MMI_BT_PROFILE__)
#include "CallManagementGProt.h"
#include "BTMMIScrGProts.h"
#endif
#ifdef __DRM_SUPPORT__
#include "DRM_gprot.h"
#endif

#define SRC_LMMI 0
#ifdef __MMI_POC__
static mdi_bg_callback background_poc_handler;
#endif
static U8 background_handler_app[MDI_BACKGROUND_APP_TOTAL];
static mdi_bg_callback background_handler[MDI_BACKGROUND_APP_TOTAL];
static mdi_callback currentHandler;
static mdi_callback previousHandler;
static mdi_callback pseudo_play_file_callback;
/* Vogins Start */
#ifdef __VRE__
static mdi_callback g_mdi_aud_int_callback;
#endif
/* Vogins End */
static void(*updateDurHandler)(U32 duration);

static U16 mdi_audio_state;
static U16 mdi_audio_mode;
static U16 mdi_audio_id;
static BOOL mdi_speech_session_on;
static MMI_BOOL mdi_speech_codec_on; /* Check if GSM/WCDMA speech on */
static BOOL backgroud_enabled;
static U16 identifier;
static U8 audio_mode = 0;

#ifdef FM_RADIO_HW_SEARCH
static void (*mdi_fmr_seek_result_hdlr) (U16 stop_freq, U8 signal_level, MMI_BOOL is_valid);
#else
static void (*mdi_fmr_check_is_valid_stop_hdlr) (BOOL is_valid);
static void (*mdi_fmr_get_signal_level_hdlr) (U8 sig_lvl);
#endif /*FM_RADIO_HW_SEARCH*/

#if defined(DIGIT_TONE_SUPPORT) || defined(SIMPLE_TTS)
#define MDI_MAX_PLAY_TEXT_LEN 60

typedef enum
{
    MDI_AUDIO_PLAY_TEXT_IDLE_STATE,
    MDI_AUDIO_PLAY_TEXT_PLAY_STATE,
    MDI_AUDIO_PLAY_TEXT_WAIT_STATE
} mdi_audio_play_text_state_enum;

typedef struct
{
    U16 identifier;
    U16 words[MDI_MAX_PLAY_TEXT_LEN];
    S32 len;
    S32 cursor;
    S32 msecs;
    mdi_callback handler;
    mdi_audio_play_text_state_enum state;   /* 0: idle, 1: playing, 2: waiting for time out to play */
    U8 volume;
    U8 path;
} mdi_audio_play_text_struct;
mdi_audio_play_text_struct mdi_audio_play_text_context;
#endif /* defined(DIGIT_TONE_SUPPORT) || defined(SIMPLE_TTS) */ 

#ifdef VR_ENABLE
media_vr_rcg_result_ind_struct *mdi_audio_vr_rcg_result_msg = NULL;
media_vr_trn_result_ind_struct *mdi_audio_vr_trn_result_msg = NULL;
#endif /* VR_ENABLE */ 

#ifdef VRSI_ENABLE
static mdi_callback vrsiHandler;
#endif 

#ifdef __MMI_POC__
extern kal_uint8 poc_result_g;
#endif 

#if defined(BGSND_ENABLE)
static U16 snd_audio_state = MDI_AUDIO_IDLE;
static mdi_callback snd_currentHandler = NULL;
static mdi_callback snd_prevHandler = NULL;
#endif /* defined(BGSND_ENABLE) */ 

#if defined(AUD_TIME_STRETCH)
static BOOL mdi_aud_stretch_on;
#endif 

extern audio_mic_volume_struct g_settings_audio_mic_volume;

/*========= static function prototype ===========*/
void mdi_audio_play_string_cnf(void *inMsg);
void mdi_audio_play_finish_ind(void *inMsg);
void mdi_audio_play_finish_ind1(void *inMsg);
void mdi_audio_update_dur_ind(void *inMsg);
void mdi_audio_record_finish_ind(void *inMsg);
void mdi_audio_background_timeout_handler(void);
void mdi_send_msg(U16 msg_id, void *local_param_ptr, void *peer_buf_ptr);
void mdi_audio_play_timeout_handler(void);
mdi_result mdi_audio_play_current_word(void);

#ifdef __MMI_BT_PROFILE__
typedef struct
{
    mdi_bt_callback open_hdlr[2];
    mdi_bt_callback close_hdlr[2];
    U8 state[2];
    BOOL pending_connect[2];
    U16 connect_id[2];
} mdi_audio_bt_cntx_struct;
mdi_audio_bt_cntx_struct mdi_audio_bt_cntx;
extern U8 g_ssc_bt_a2dp_mode;   /* defined in SSCStringHandle.c */
extern void aud_send_bt_audio_open_req(
                module_type src_mod_id,
                kal_uint8 profile,
                kal_uint8 mode,
                kal_uint16 connect_id);
extern void aud_send_bt_audio_close_req(module_type src_mod_id, kal_uint8 profile);
extern void aud_send_bt_audio_turn_on_req(module_type src_mod_id, kal_uint8 profile);
extern void aud_send_bt_audio_turn_off_req(module_type src_mod_id, kal_uint8 profile);
#endif /* __MMI_BT_PROFILE__ */ 

extern void aud_send_stop_build_cache_req(module_type src_id);
extern kal_int16 med_get_media_type(kal_wchar *file_name);

extern kal_int8 voip_encoding_start(kal_int8 rtp_handle);
extern kal_int8 voip_encoding_stop(kal_int8 rtp_handle);
extern kal_int8 voip_decoding_start(kal_int8 rtp_handle);
extern kal_int8 voip_decoding_stop(kal_int8 rtp_handle);
extern kal_int8 rtp_send_dtmf_start(kal_int8 rtp_handle, kal_uint8 dtmf_code, kal_uint8 send_type);
extern kal_int8 rtp_send_dtmf_stop(kal_int8 rtp_handle);
extern kal_int8 voip_mixer_add(kal_int8 rtp_handle);
extern kal_int8 voip_mixer_remove(kal_int8 rtp_handle);

typedef struct
{
    MDI_AUDIO_SPEECH_APP_ID_ENUM app_id;
} mdi_audio_speech_cntx_struct;

mdi_audio_speech_cntx_struct mdi_audio_speech_cntx;

/* MMA */
typedef struct
{
    mdi_handle handle;
    mdi_mma_callback callback;
    U16 state;
    U16 format;
    U16 player_id;  /* Increase for each open request */
    U16 seq_id;     /* Increase for each stop request */
}mdi_audio_mma_player_struct;

#ifndef __MTK_TARGET__
#define MMA_NO_OF_PLAYER 13 /* For PC simulator */
#endif

static mdi_audio_mma_player_struct mdi_audio_mma_player[MMA_NO_OF_PLAYER];
static U16 mdi_audio_mma_player_id;

#ifdef __DRM_SUPPORT__
static MMI_BOOL mdi_audio_drm_consume_count;
static S32 mdi_audio_drm_id;
#endif /*__DRM_SUPPORT__*/

/* For JAVA background play - MDI AUDIO mutex */
#ifdef __J2ME__
volatile S16 g_mdi_audio_mutex_cnt = 0;
volatile module_type g_mdi_audio_mutex_tid = MOD_NIL;
kal_semid g_mdi_audio_sem;
#endif

/*========= functions =====================*/
#ifdef __DRM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_drm_timeout_callback
 * DESCRIPTION
 *  This is the callback function when DRM timeout
 * PARAMETERS
 *  kal_int32 result    [IN]
 *  kal_uint32 id       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_drm_timeout_callback(kal_int32 result, kal_int32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_DRM_TIMEOUT_CALLBACK, result, id, mdi_audio_drm_id);

    if(id == mdi_audio_drm_id)
    {
        if (currentHandler)
        {
            previousHandler = currentHandler;
            currentHandler = NULL;
            previousHandler(MDI_AUDIO_DRM_TIMEOUT);
        }
        else /* Stop playing if app does not provide callback */
        {
            mdi_audio_stop_file();        
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_drm_validate_right
 * DESCRIPTION
 *  This function is to valdate DRM right before play
 * PARAMETERS
 *  U16 filename    [IN]    file to be played
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_drm_validate_right(U16* filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle;
    mdi_result result = MDI_AUDIO_DRM_PROHIBIT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_DRM_VALIDATE_RIGHT, mdi_audio_drm_consume_count);

    if((handle = DRM_open_file((U16*)filename, FS_READ_ONLY, DRM_PERMISSION_PLAY)) >= FS_NO_ERROR)
    {
        if (DRM_get_object_method(handle, NULL) == DRM_METHOD_NONE)
        {
            DRM_close_file(handle);
            return MDI_AUDIO_SUCCESS;
        }
    
        /* Consume count and time */
        if(mdi_audio_drm_consume_count)
        {
            if(DRM_validate_permission(handle, NULL, DRM_PERMISSION_PLAY))
            {
                result = MDI_AUDIO_SUCCESS;
            }
            DRM_close_file(handle);
            return result;
        }
        /* Consume time only */
        else
        {
            if(DRM_validate_timed_permission(handle, DRM_PERMISSION_PLAY))
            {
                result = MDI_AUDIO_SUCCESS;
            }
            DRM_close_file(handle);
            return result;
        }
    }
    else if (handle == DRM_RESULT_NO_PERMISSION)
    {
        return MDI_AUDIO_DRM_PROHIBIT;
    }
    else   /* file open error, but not DRM related problem */
    {
        return MDI_AUDIO_OPEN_FILE_FAIL;
    }

    return MDI_AUDIO_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_drm_consume_right
 * DESCRIPTION
 *  This function is to consume DRM right after play
 * PARAMETERS
 *  U16 filename    [IN]    file to be played
 * RETURNS
 *  mdi_result
 *****************************************************************************/
void mdi_audio_drm_consume_right(U16* filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle = FS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_DRM_COSUME_RIGHT, mdi_audio_drm_consume_count);

    mdi_audio_drm_id = -1;

    if((handle = DRM_open_file((U16*)filename, FS_READ_ONLY, DRM_PERMISSION_PLAY)) >= FS_NO_ERROR)
    {
        if (DRM_get_object_method(handle, NULL) != DRM_METHOD_NONE)
        {
            /* Consume count and time */
            if(mdi_audio_drm_consume_count)
            {
                mdi_audio_drm_id = DRM_consume_rights(handle, DRM_PERMISSION_PLAY, mdi_audio_drm_timeout_callback);
            }
            /* Consume time only */
            else
            {
                mdi_audio_drm_id = DRM_consume_timed_rights(handle, DRM_PERMISSION_PLAY, mdi_audio_drm_timeout_callback);
            }
        }

        DRM_close_file(handle);
    }

    mdi_audio_drm_consume_count = MMI_TRUE; /* Clear this flag for each consume request */

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_DRM_COSUME_RIGHT_RESULT, handle, mdi_audio_drm_id);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_drm_disable_consume_count
 * DESCRIPTION
 *  This function is to disable DRM right consume when play file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_drm_disable_consume_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_DRM_DISABLE_CONSUME_COUNT);

    mdi_audio_drm_consume_count = MMI_FALSE;
}

#endif /* __DRM_SUPPORT__ */ 

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_init_state
 * DESCRIPTION
 *  This function is to initialize the mdi audio variables
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_init_variable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_state = MDI_AUDIO_IDLE;
    identifier = 0;
    currentHandler = NULL;

#if defined(DIGIT_TONE_SUPPORT) || defined(SIMPLE_TTS)
    mdi_audio_play_text_context.identifier = 0;
    mdi_audio_play_text_context.state = MDI_AUDIO_PLAY_TEXT_IDLE_STATE;
    mdi_audio_play_text_context.len = 0;
    mdi_audio_play_text_context.cursor = -1;
    mdi_audio_play_text_context.msecs = 0;
    mdi_audio_play_text_context.handler = NULL;
    mdi_audio_play_text_context.volume = 0;
    mdi_audio_play_text_context.path = MDI_DEVICE_SPEAKER;
    memset(mdi_audio_play_text_context.words, 0, sizeof(mdi_audio_play_text_context.words));
#endif /* defined(DIGIT_TONE_SUPPORT) || defined(SIMPLE_TTS) */ 

#if defined(AUD_TIME_STRETCH)
    mdi_aud_stretch_on = FALSE;
#endif 

    /* Init speech context */
    mdi_audio_speech_cntx.app_id = MDI_AUDIO_SPEECH_APP_ID_NONE;

    /* Init mma context */
    mdi_audio_mma_init();
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_init
 * DESCRIPTION
 *  This function is to initialize the mdi audio interface.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_INIT);

#ifdef __J2ME__
    /* Create Mutex */
    g_mdi_audio_sem = kal_create_sem("MDI AUDIO SEMAPHORE", 1);
#endif /*__J2ME__*/

    /* stop all audio if someone still playing while re-init */
    if(!mdi_audio_is_idle())
    {
        mdi_audio_stop_all();
    }

    /* Init MDI variables */
    mdi_audio_init_variable();

    /* Init background play */
    backgroud_enabled = TRUE;
#ifdef __MMI_POC__
    background_poc_handler = NULL;
#endif
    for (i = 0; i < MDI_BACKGROUND_APP_TOTAL; i++)
    {
        background_handler[i] = NULL;
        background_handler_app[i] = MDI_BACKGROUND_APP_TOTAL;
    }

    /* Init bluetooth profile */
#ifdef __MMI_BT_PROFILE__
    for (i = 0; i < 2; i++)
    {
        mdi_audio_bt_cntx.open_hdlr[i] = mdi_audio_bt_cntx.close_hdlr[i] = NULL;
        mdi_audio_bt_cntx.state[i] = MDI_AUDIO_BT_STATE_IDLE;
        mdi_audio_bt_cntx.pending_connect[i] = FALSE;
    }
#endif /* __MMI_BT_PROFILE__ */ 

#ifdef __DRM_SUPPORT__
    mdi_audio_drm_consume_count = MMI_TRUE;
    mdi_audio_drm_id = -1;
#endif /*__DRM_SUPPORT__*/
/* Vogins Start */
#ifdef __VRE__
    g_mdi_aud_int_callback = NULL;
#endif
/* Vogins End */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_init_event_hdlrs
 * DESCRIPTION
 *  This function is to set event hdlrs.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_init_event_hdlrs(void)
{
#ifdef __MMI_BT_PROFILE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mdi_audio_bt_close_stream_cnf, MSG_ID_MEDIA_BT_AUDIO_CLOSE_CNF);
    SetProtocolEventHandler(mdi_audio_bt_close_stream_ind, MSG_ID_MEDIA_BT_AUDIO_CLOSE_IND);
    SetProtocolEventHandler(mdi_audio_bt_open_stream_cnf, MSG_ID_MEDIA_BT_AUDIO_OPEN_CNF);
    SetProtocolEventHandler(mdi_audio_bt_open_stream_ind, MSG_ID_MEDIA_BT_AUDIO_OPEN_IND);

    #if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__)
    av_bt_init();
    #endif
#endif /* __MMI_BT_PROFILE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_event
 * DESCRIPTION
 *  This function is to convert event to mdi result.
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_get_event(U8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (mdi_result) result;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_start_background_timer
 * DESCRIPTION
 *  This function is to start timer for background play.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_start_background_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    if (mdi_check_device_ownership() && backgroud_enabled && !mdi_speech_session_on)
    {
        StartTimer(TIMER_PROFILES_ALERT_PLAY, 3000, mdi_audio_background_timeout_handler);
    }
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_background_timer
 * DESCRIPTION
 *  This function is to stop timer for background play.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_stop_background_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(TIMER_PROFILES_ALERT_PLAY);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_check_states_and_handlers
 * DESCRIPTION
 *  This function is to check states and handlers before play or record request is executed
 * PARAMETERS
 *  result_p        [?]     
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mdi_audio_check_states_and_handlers(mdi_result *result_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    if (!mdi_check_device_ownership())
    {
        *result_p = MDI_AUDIO_BLOCKED;
        MDI_AUDIO_UNLOCK;
        return FALSE;
    }
    else if (mdi_audio_state == MDI_AUDIO_RECORD || mdi_audio_state == MDI_AUDIO_RECORD_PAUSED ||
             mdi_audio_state == MDI_AUDIO_VRSI_PROCESS || mdi_speech_session_on)
    {
        *result_p = MDI_AUDIO_BUSY;
        MDI_AUDIO_UNLOCK;
        return FALSE;
    }
    else
    {
        /* Stop previous DRM file consume */
#ifdef __DRM_SUPPORT__
        if(mdi_audio_drm_id >= 0)
        {
            DRM_stop_consume(mdi_audio_drm_id);
            mdi_audio_drm_id = -1;
        }
#endif /*__DRM_SUPPORT__*/

        /*
         * set pseudo play file callback to NULL before callback
         * bcoz we could set another callback during callback
         */
        if (pseudo_play_file_callback)
        {
            mdi_callback old_pseudo_play_file_callback = pseudo_play_file_callback;
            pseudo_play_file_callback = NULL;
            old_pseudo_play_file_callback(MDI_AUDIO_TERMINATED);
        }
/* Vogins End */
#ifdef __VRE__
    	if (g_mdi_aud_int_callback)
    	{
            mdi_callback old_int_callback = g_mdi_aud_int_callback;
            g_mdi_aud_int_callback = NULL;
            old_int_callback(MDI_AUDIO_TERMINATED);
        }
#endif
/* Vogins End */
        if (mdi_audio_state == MDI_AUDIO_PLAY || mdi_audio_state == MDI_AUDIO_PLAY_PAUSED
#if defined(DIGIT_TONE_SUPPORT) || defined(SIMPLE_TTS)
            || mdi_audio_play_text_context.state == MDI_AUDIO_PLAY_TEXT_WAIT_STATE
#endif 
            )
        {
        	if (currentHandler)
        	{
            	currentHandler(MDI_AUDIO_TERMINATED);
        	}
            if (mdi_audio_state == MDI_AUDIO_PLAY && mdi_audio_mode == MDI_AUDIO_PLAY_FM_RADIO)
            {
                mdi_fmr_power_off();
            }
        }
    }

    /* *result_p = MDI_AUDIO_SUCCESS; */
    MDI_AUDIO_UNLOCK;
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_id
 * DESCRIPTION
 *  This function is to play audio id.
 * PARAMETERS
 *  audio_id        [IN]        U8 play_style, mdi_handle* handle_p, mdi_callback handler
 *  play_style      [IN]        
 *  handle_p        [?]         
 *  handler         [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_play_id(U16 audio_id, U8 play_style, mdi_handle *handle_p, mdi_callback handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_PLAY_ID, audio_id, mdi_audio_state);

    return mdi_audio_play_id_with_vol_path(
            audio_id,
            play_style,
            handle_p,
            handler,
            GetRingVolumeLevel(),
            MDI_DEVICE_SPEAKER2);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_id_with_vol_path
 * DESCRIPTION
 *  This function is to play audio id along with volume and output path.
 * PARAMETERS
 *  audio_id        [IN]        U8 play_style, mdi_handle* handle_p, mdi_callback handler
 *  play_style      [IN]        
 *  handle_p        [?]         
 *  handler         [IN]        
 *  volume          [IN]        U8 path
 *  path            [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_play_id_with_vol_path(
            U16 audio_id,
            U8 play_style,
            mdi_handle *handle_p,
            mdi_callback handler,
            U8 volume,
            U8 path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_play_id_struct id_param;
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_PLAY_ID_WITH_VOL_PATH, audio_id, mdi_audio_state);

    if (!mdi_check_device_ownership())
    {
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_BLOCKED;
    }

    if (audio_id > MAX_TONE_ID)
    {
        if (!mdi_audio_check_states_and_handlers(&result))
        {
            MDI_AUDIO_UNLOCK;
            return result;
        }

        currentHandler = handler;
        mdi_audio_state = MDI_AUDIO_PLAY;
        mdi_audio_mode = MDI_AUDIO_PLAY_ID;
        mdi_audio_id = audio_id;
        ++identifier;
        mdi_audio_stop_background_timer();
    }

    /* All sound shall go through bluetooth earphone. (Except keypad tone) */
#ifdef __MMI_BT_AUDIO_VIA_SCO__
#ifndef __MMI_BT_SCO_KEY_TONE__
    if(audio_id > TONE_KEY_CLICK) /* Key tone does not go to BT headset */
#endif
    {
        mmi_profiles_bt_connect_audio_via_sco();
    }
#endif /*__MMI_BT_AUDIO_VIA_SCO__*/

    id_param.audio_id = (U8) audio_id;
    id_param.play_style = play_style;
    id_param.volume = volume;
    id_param.output_path = path;
    id_param.identifier = (U16) (identifier);
    if ((result = media_aud_play_id(MOD_MMI, &id_param)) == MED_RES_OK)
    {
        SetProtocolEventHandler(mdi_audio_play_finish_ind, MSG_ID_L4AUD_AUDIO_PLAY_FINISH_IND);
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        currentHandler = NULL;
        mdi_audio_state = MDI_AUDIO_IDLE;
        mdi_audio_start_background_timer();
        MDI_AUDIO_UNLOCK;
        return mdi_audio_get_event((U8) result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_string
 * DESCRIPTION
 *  This function is to play audio string.
 * PARAMETERS
 *  audio_data      [?]         U32 len, U8 format, U8 play_style, mdi_handle* handle_p, mdi_callback handler
 *  len             [IN]        
 *  format          [IN]        
 *  play_style      [IN]        
 *  handle_p        [?]         
 *  handler         [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_play_string(
            void *audio_data,
            U32 len,
            U8 format,
            U8 play_style,
            mdi_handle *handle_p,
            mdi_callback handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_PLAY_STRING, format, mdi_audio_state);

    return mdi_audio_play_string_portion_with_vol_path(
                audio_data,
                len,
                format,
                0,
                0,
                play_style,
                handle_p,
                handler,
                GetRingVolumeLevel(),
                MDI_DEVICE_SPEAKER2);

}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_string_with_vol_path
 * DESCRIPTION
 *  This function is to play audio string along with volume and output path.
 * PARAMETERS
 *  audio_data      [?]         U32 len, U8 format, U8 play_style, mdi_handle* handle_p, mdi_callback handler
 *  len             [IN]        
 *  format          [IN]        
 *  play_style      [IN]        
 *  handle_p        [?]         
 *  handler         [IN]        
 *  volume          [IN]        U8 path
 *  path            [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_play_string_with_vol_path(
            void *audio_data,
            U32 len,
            U8 format,
            U8 play_style,
            mdi_handle *handle_p,
            mdi_callback handler,
            U8 volume,
            U8 path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_PLAY_STRING_WITH_VOL_PATH, format, mdi_audio_state);

    return mdi_audio_play_string_portion_with_vol_path(
                audio_data,
                len,
                format,
                0,
                0,
                play_style,
                handle_p,
                handler,
                volume,
                path);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_string_portion_with_vol_path
 * DESCRIPTION
 *  This function is to play audio string along with volume and output path.
 * PARAMETERS
 *  audio_data      [?]         U32 len, U8 format, U8 play_style, mdi_handle* handle_p, mdi_callback handler
 *  len             [IN]        
 *  format          [IN]        
 *  play_style      [IN]        
 *  handle_p        [?]         
 *  handler         [IN]        
 *  volume          [IN]        U8 path
 *  path            [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_play_string_portion_with_vol_path(
            void *audio_data,
            U32 len,
            U8 format,
            U32 start_offset,
            U32 end_offset,
            U8 play_style,
            mdi_handle *handle_p,
            mdi_callback handler,
            U8 volume,
            U8 path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_play_string_struct string_param;
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_PLAY_STRING_PORTION_WITH_VOL_PATH, format, mdi_audio_state);

    if (!mdi_audio_check_states_and_handlers(&result))
    {
        MDI_AUDIO_UNLOCK;
        return result;
    }

    mdi_audio_stop_background_timer();
    ++identifier;

    /* All sound shall go through bluetooth earphone */
#ifdef __MMI_BT_AUDIO_VIA_SCO__
    mmi_profiles_bt_connect_audio_via_sco();
#endif

    string_param.data_p = (U8*) audio_data;
    string_param.len = len;
    string_param.format = format;
    string_param.play_style = play_style;
    string_param.volume = volume;
    string_param.output_path = path;
    string_param.identifier = (U16) identifier;
    string_param.blocking = TRUE;
    string_param.start_offset = start_offset;
    string_param.end_offset = end_offset;
    if ((result = media_aud_play_string(MOD_MMI, &string_param)) == MED_RES_OK)
    {
        currentHandler = handler;
        mdi_audio_state = MDI_AUDIO_PLAY;
        mdi_audio_mode = MDI_AUDIO_PLAY_STRING;
        SetProtocolEventHandler(mdi_audio_play_finish_ind, MSG_ID_L4AUD_AUDIO_PLAY_FINISH_IND);
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        currentHandler = NULL;
        mdi_audio_state = MDI_AUDIO_IDLE;
        mdi_audio_start_background_timer();
        MDI_AUDIO_UNLOCK;
        return mdi_audio_get_event((U8) result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_string_with_vol_path_non_block
 * DESCRIPTION
 *  This function is to play audio string along with volume and output path.
 * PARAMETERS
 *  audio_data      [?]         U32 len, U8 format, U8 play_style, mdi_handle* handle_p, mdi_callback handler
 *  len             [IN]        
 *  format          [IN]        
 *  play_style      [IN]        
 *  handle_p        [?]         
 *  handler         [IN]        
 *  volume          [IN]        U8 path
 *  path            [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_play_string_with_vol_path_non_block(
            void *audio_data,
            U32 len,
            U8 format,
            U8 play_style,
            mdi_handle *handle_p,
            mdi_callback handler,
            U8 volume,
            U8 path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_play_string_struct string_param;
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_PLAY_STRING_PORTION_WITH_VOL_PATH_NON_BLOCK, format, mdi_audio_state);

    if (!mdi_audio_check_states_and_handlers(&result))
    {
        MDI_AUDIO_UNLOCK;
        return result;
    }

    mdi_audio_stop_background_timer();
    ++identifier;

    /* All sound shall go through bluetooth earphone */
#ifdef __MMI_BT_AUDIO_VIA_SCO__
    mmi_profiles_bt_connect_audio_via_sco();
#endif

    string_param.data_p = (U8*) audio_data;
    string_param.len = len;
    string_param.format = format;
    string_param.play_style = play_style;
    string_param.volume = volume;
    string_param.output_path = path;
    string_param.identifier = (U16) identifier;
    string_param.blocking = FALSE;
    string_param.start_offset = 0;
    string_param.end_offset = 0;
    if ((result = media_aud_play_string(MOD_MMI, &string_param)) == MED_RES_OK)
    {
        currentHandler = handler;
        mdi_audio_state = MDI_AUDIO_PLAY;
        mdi_audio_mode = MDI_AUDIO_PLAY_STRING;
        SetProtocolEventHandler(mdi_audio_play_finish_ind, MSG_ID_L4AUD_AUDIO_PLAY_FINISH_IND);
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        currentHandler = NULL;
        mdi_audio_state = MDI_AUDIO_IDLE;
        mdi_audio_start_background_timer();
        MDI_AUDIO_UNLOCK;
        return mdi_audio_get_event((U8) result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_file_check_state
 * DESCRIPTION
 *  This function is to check state before play a file
 * PARAMETERS
 *  file_name       [?]
 * RETURNS
 *  mdi_result
 *****************************************************************************/
static mdi_result mdi_audio_play_file_check_state(U16 *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;
#ifdef __DRM_SUPPORT__
    MMI_BOOL drm_fail_stop = MMI_FALSE;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_PLAY_FILE_CHECK_STATE, mdi_audio_state);

#ifdef __DRM_SUPPORT__
    if (mdi_audio_state == MDI_AUDIO_PLAY
        || mdi_audio_state == MDI_AUDIO_PLAY_PAUSED
#if defined(DIGIT_TONE_SUPPORT) || defined(SIMPLE_TTS)
        || mdi_audio_play_text_context.state == MDI_AUDIO_PLAY_TEXT_WAIT_STATE
#endif 
       )
    {
        drm_fail_stop = MMI_TRUE;
    }
#endif

    if (!mdi_audio_check_states_and_handlers(&result))
    {
#ifdef __DRM_SUPPORT__
        mdi_audio_drm_consume_count = MMI_TRUE;
#endif        
        MDI_AUDIO_UNLOCK;
        return result;
    }

#ifdef __DRM_SUPPORT__
    result = mdi_audio_drm_validate_right((U16*)file_name);

    if(result != MDI_AUDIO_SUCCESS)
    {
        mdi_audio_drm_consume_count = MMI_TRUE;
        if(drm_fail_stop)
        {
            mdi_audio_stop_all();
        }
        MDI_AUDIO_UNLOCK;
        return result;
    }
#endif /* #ifdef __DRM_SUPPORT__ */

    MDI_AUDIO_UNLOCK;
    return MDI_AUDIO_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_file
 * DESCRIPTION
 *  This function is to play audio file.
 * PARAMETERS
 *  file_name       [?]
 *  play_style      [IN]        
 *  cache_p         [IN]         
 *  handler         [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_play_file(void *file_name, U8 play_style, void *cache_p, mdi_callback handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_PLAY_FILE, mdi_audio_state);

    return mdi_audio_play_file_portion_with_vol_path(
            file_name,
            0,
            0,
            play_style,
            cache_p,
            handler,
            GetRingVolumeLevel(),
            MDI_DEVICE_SPEAKER2);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_file_with_vol_path
 * DESCRIPTION
 *  This function is to play audio file along with volume and output path.
 * PARAMETERS
 *  file_name       [?]         U8 play_style, mdi_handle* handle_p, mdi_callback handler
 *  play_style      [IN]        
 *  cache_p         [IN]         
 *  handler         [IN]        
 *  volume          [IN]        U8 path
 *  path            [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_play_file_with_vol_path(
            void *file_name,
            U8 play_style,
            void *cache_p,
            mdi_callback handler,
            U8 volume,
            U8 path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_PLAY_FILE_WITH_VOL_PATH, mdi_audio_state);

    return mdi_audio_play_file_portion_with_vol_path(
            file_name,
            0,
            0,
            play_style,
            cache_p,
            handler,
            volume,
            path);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_file_portion_with_vol_path
 * DESCRIPTION
 *  This function is to play audio file portion with volume and output path.
 * PARAMETERS
 *  file_name           [IN]
 *  start_offset        [IN]        
 *  end_offset          [IN]        
 *  play_style          [IN]        
 *  cache_p             [IN]         
 *  handler             [IN]
 *  volume              [IN]        
 *  path                [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_play_file_portion_with_vol_path(
            void *file_name,
            U32 start_offset,
            U32 end_offset,
            U8 play_style,
            void *cache_p,
            mdi_callback handler,
            U8 volume,
            U8 path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_play_file_struct file_param;
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_PLAY_FILE_PORTION_WITH_VOL_PATH, mdi_audio_state, start_offset,end_offset,cache_p);

    result = mdi_audio_play_file_check_state((U16*)file_name);
    if(result != MDI_AUDIO_SUCCESS)
    {
        mdi_audio_start_background_timer();
        MDI_AUDIO_UNLOCK;
        return result;
    }

    mdi_audio_stop_background_timer();
    ++identifier;

    /* All sound shall go through bluetooth earphone */
#ifdef __MMI_BT_AUDIO_VIA_SCO__
    mmi_profiles_bt_connect_audio_via_sco();
#endif

    file_param.file_name_p = (UI_string_type) file_name;
    file_param.play_style = play_style;
    file_param.volume = volume;
    file_param.output_path = path;
    file_param.identifier = (U16) identifier;
    file_param.start_offset = start_offset;
    file_param.end_offset = end_offset;
    file_param.cache_p = cache_p;
    if ((result = media_aud_play_file(MOD_MMI, &file_param)) == MED_RES_OK)
    {
#ifdef __DRM_SUPPORT__
        mdi_audio_drm_consume_right((U16*)file_name);
#endif /*__DRM_SUPPORT__*/

        currentHandler = handler;
        mdi_audio_state = MDI_AUDIO_PLAY;
        mdi_audio_mode = MDI_AUDIO_PLAY_FILE;
        SetProtocolEventHandler(mdi_audio_play_finish_ind1, MSG_ID_L4AUD_MEDIA_PLAY_FINISH_IND);
        SetProtocolEventHandler(mdi_audio_update_dur_ind, MSG_ID_L4AUD_MEDIA_UPDATE_DUR_IND);
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
#ifdef __DRM_SUPPORT__
        mdi_audio_drm_consume_count = MMI_TRUE; /* Clear this flag for each consume request */
#endif /*__DRM_SUPPORT__*/

        currentHandler = NULL;
        updateDurHandler = NULL;
        mdi_audio_state = MDI_AUDIO_IDLE;
        mdi_audio_start_background_timer();
        MDI_AUDIO_UNLOCK;
        return mdi_audio_get_event((U8) result);
    }
}

#ifdef __MMI_AUDIO_SPECTRUM_DISPLAY__


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_start_calc_spectrum
 * DESCRIPTION
 *  This function is to start to calculate the audio spectrum tops & vals.
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_start_calc_spectrum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result = (mdi_result) media_aud_start_calc_spectrum(MOD_MMI);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_START_CALC_SPECTRUM);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_calc_spectrum
 * DESCRIPTION
 *  This function is to stop calculating the audio spectrum tops & vals.
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_stop_calc_spectrum(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result = (mdi_result) media_aud_stop_calc_spectrum(MOD_MMI);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_STOP_CALC_SPECTRUM);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_spectrum
 * DESCRIPTION
 *  This function is to get the audio spectrum tops & vals.
 * PARAMETERS
 *  top_p       [?]     
 *  val_p       [?]     
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_get_spectrum(U8 *top_p, U8 *val_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result = (mdi_result) media_aud_get_spectrum(MOD_MMI, top_p, val_p);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_GET_SPECTRUM_TOP, top_p[0], top_p[1], top_p[2], top_p[3], top_p[4], top_p[5], top_p[6], top_p[7], top_p[8], top_p[9], top_p[10], top_p[11], top_p[12], top_p[13], top_p[14], top_p[15]);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_GET_SPECTRUM_VAL, val_p[0], val_p[1], val_p[2], val_p[3], val_p[4], val_p[5], val_p[6], val_p[7], val_p[8], val_p[9], val_p[10], val_p[11], val_p[12], val_p[13], val_p[14], val_p[15]);

    return result;
}
#endif /* __MMI_AUDIO_SPECTRUM_DISPLAY__ */ 


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_is_pure_audio
 * DESCRIPTION
 *  This function is to check if a file is pure audio file
 * PARAMETERS
 *  file_name       [IN]     NULL means using current play file handler to update time
 *                           (only for need build cache file type)
 *
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mdi_audio_is_pure_audio(void *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    result = media_aud_check_is_pure_audio(MOD_MMI, file_name);
#endif

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_IS_PURE_AUDIO, result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_duration
 * DESCRIPTION
 *  This function is to get the duration of a audio file.
 * PARAMETERS
 *  file_name       [IN]     NULL means using current play file handler to update time
 *                           (only for need build cache file type)
 *                           Otherwise, open file and call GetContentDescInfo
 *  time_p          [OUT]    (milliseconds)
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_get_duration(void *file_name, U32 *time_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result = (mdi_result) media_aud_get_duration(MOD_MMI, file_name, NULL, 0, 0, time_p);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_GET_DURATION, result, *time_p);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_duration_by_string
 * DESCRIPTION
 *  This function is to get the duration of a audio file.
 * PARAMETERS
 *  time_p          [OUT]    (milliseconds)
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_get_duration_by_string(kal_uint8 *audio_data, U32 len, U8 format, U32 *time_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result = (mdi_result) media_aud_get_duration(MOD_MMI, NULL, audio_data, len, format, time_p);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_GET_DURATION_BY_STRING, result, *time_p);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_progress_time
 * DESCRIPTION
 *  This function is to get the progress of file playing
 * PARAMETERS
 *  progress        [?]     
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_get_progress_time(U32 *progress)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    if ((mdi_audio_state == MDI_AUDIO_PLAY || mdi_audio_state == MDI_AUDIO_PLAY_PAUSED) &&
        mdi_audio_mode == MDI_AUDIO_PLAY_FILE)
    {
        result = (mdi_result) media_aud_get_progress_time(MOD_MMI, progress);
    }
    else
    {
        result = MDI_AUDIO_FAIL;
        *progress = 0;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_GET_PROGRESS_TIME, result, *progress);

    MDI_AUDIO_UNLOCK;
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_set_progress_time
 * DESCRIPTION
 *  This function is to seek file playing offset when it's playing a file.
 * PARAMETERS
 *  progress        [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_set_progress_time(U32 progress)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    if (mdi_audio_state == MDI_AUDIO_PLAY && mdi_audio_mode == MDI_AUDIO_PLAY_FILE)
    {
        result = (mdi_result) media_aud_set_progress_time(MOD_MMI, progress);
    }
    else
    {
        result = MDI_AUDIO_FAIL;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SET_PROGRESS_TIME, result, progress);

    MDI_AUDIO_UNLOCK;
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_start_build_cache
 * DESCRIPTION
 *  This function is to start build cache
 * PARAMETERS
 *  filename        [IN]
 *  cache_p         [IN]
 *  cache_size      [IN]
 *  file_buf_p      [IN]
 *  file_buf_size   [IN]
 *  proc_buf_p      [IN]
 *  proc_buf_size   [IN]
 *  handler         [IN]    call back hanlder when build cache fail
 *  build_cache_progress    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_start_build_cache(
            kal_wchar *filename,
            U8 *cache_p, 
            U32 cache_size,
            U8 *file_buf_p,
            U32 file_buf_size,
            U8 *proc_buf_p,
            U32 proc_buf_size,
            void (*handler)(void*),
            U32 *build_cache_progress)
{
#ifndef MED_V_NOT_PRESENT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_visual_audio_cache_req_struct *cache_parm = (media_visual_audio_cache_req_struct*)
           construct_local_para(sizeof(media_visual_audio_cache_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(file_buf_p!=NULL);
    ASSERT(proc_buf_p!=NULL);

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_START_BUILD_CACHE);

    cache_parm->filename = filename;
    cache_parm->cache_p = cache_p;
    cache_parm->cache_size = cache_size ;
    cache_parm->file_buf_p = file_buf_p;
    cache_parm->file_buf_size = file_buf_size;
    cache_parm->proc_buf_p = proc_buf_p ;
    cache_parm->proc_buf_size = proc_buf_size;
    cache_parm->build_cache_progress = build_cache_progress ;

    media_aud_start_build_cache(MOD_MMI,cache_parm);
    SetProtocolEventHandler(handler, MSG_ID_MEDIA_AUDIO_BUILD_CACHE_FAIL_IND);
#endif
    return;
    
}

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_build_cache
 * DESCRIPTION
 *  This function is to stop build cache
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_stop_build_cache()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef MED_V_NOT_PRESENT
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_STOP_BUILD_CACHE);
    aud_send_stop_build_cache_req(MOD_MMI);
#endif
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_close_build_cache
 * DESCRIPTION
 *  This function is to close build cache
 * PARAMETERS
 *
 * RETURNS
 *  mdi_result
 *****************************************************************************/
void mdi_audio_close_build_cache()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef MED_V_NOT_PRESENT
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_CLOSE_BUILD_CACHE);
    media_aud_close_build_cache(MOD_MMI);
#endif
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_reset_build_cache_variables
 * DESCRIPTION
 *  This function is to reset build cache variables
 * PARAMETERS
 *
 * RETURNS
 *  mdi_result
 *****************************************************************************/
void mdi_audio_reset_build_cache_variables()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef MED_V_NOT_PRESENT
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_RESET_BUILD_CACHE_VAR);
    media_aud_reset_build_cache_variables(MOD_MMI);
#endif
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_build_cache_get_cache_duration
 * DESCRIPTION
 *  This function is to get current cached duration
 * PARAMETERS
 * duration_p     [OUT]
 * RETURNS
 *  BOOL
 *****************************************************************************/
BOOL mdi_audio_build_cache_get_cache_duration(kal_uint32 *duration_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef MED_V_NOT_PRESENT
    if(medv_audio_get_cache_duration(duration_p))
    {
        return TRUE;
    }
    else
#endif
    {
        return FALSE;
    }
    
}

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_reset_build_cache_variables
 * DESCRIPTION
 *  This function is to get total duration from build cache
 * PARAMETERS
 * duration_p     [OUT]
 * RETURNS
 *  BOOL
 *****************************************************************************/
BOOL mdi_audio_build_cache_get_total_duration(kal_uint32 *duration_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef MED_V_NOT_PRESENT
    if(medv_audio_get_total_duration(duration_p))
    {
        return TRUE;
    }
    else
#endif
    {
        return FALSE;
    }
    
}

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_regisiter_auto_update_duration_handler
 * DESCRIPTION
 *  This function is to regisiter auto update time duration
 * PARAMETERS
 * handler     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_regisiter_auto_update_duration_handler(void(*handler)(U32 duration))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    updateDurHandler = handler;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_is_duration_need_build_cache
 * DESCRIPTION
 *  This function is to check if we need to build cache to get precise duration
 * PARAMETERS
 * handler     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mdi_audio_is_duration_need_build_cache(void *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 type;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Get media type from filename extension */
    type = med_get_media_type( filename );

    if(type == MED_TYPE_AMR ||
       type == MED_TYPE_DAF ||
       type == MED_TYPE_MUSICAM ||
       type == MED_TYPE_AAC)
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


#if defined(DIGIT_TONE_SUPPORT) || defined(SIMPLE_TTS)
#if defined(SIMPLE_TTS)

/*****************************************************************************
 * FUNCTION
 *  BinarySearch
 * DESCRIPTION
 *  This function is to perform a binary search in a index sorted table
 * PARAMETERS
 *  key                 [IN]        
 *  lookup_table        [IN]        
 *  start               [IN]        
 *  end                 [IN]        
 * RETURNS
 *  short
 *****************************************************************************/
static short BinarySearch(const unsigned char key, const unsigned char *lookup_table, short start, short end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (start <= end)
    {
        short mid = (start + end) / 2;

        if (key > lookup_table[mid])
        {
            start = mid + 1;
        }
        else if (key < lookup_table[mid])
        {
            end = mid - 1;
        }
        else    /* key == target */
        {
            return mid;
        }
    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  LookupTTS
 * DESCRIPTION
 *  This function is to lookup the sound index from TTS database
 * PARAMETERS
 *  ucs2        [IN]        
 * RETURNS
 *  short
 *****************************************************************************/
static short LookupTTS(unsigned short ucs2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    unsigned char key_MSB = (unsigned char)(ucs2 >> 8);
    unsigned char key_LSB;
    short start = TTS_UCS2_MSB_index[key_MSB].start;
    short end;
    short index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (start < 0)  /* key MSB not found in index table */
    {
        return -1;
    }

    key_LSB = (unsigned char)(ucs2 & 0xff);
    end = TTS_UCS2_MSB_index[key_MSB].end;
    if ((index = BinarySearch(key_LSB, TTS_UCS2_LSB, start, end)) < 0)  /* key LSB not found */
    {
        return -1;
    }

    return TTS_index_table[index];
}
#endif /* defined(SIMPLE_TTS) */ 


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_word_resource
 * DESCRIPTION
 *  This function is to get the associated audio resource with the given word, which is a UCS2 char
 * PARAMETERS
 *  U16     [IN]        Word
 * RETURNS
 *  audio_resource_struct*
 *****************************************************************************/
audio_resource_struct *mdi_audio_get_word_resource(U16 U16)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(DIGIT_TONE_SUPPORT)
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (U16 >= L'0' && U16 <= L'9')
    {
        i = (S32) (U16 - L'0');
    }
    else if (U16 == L'*')
    {
        i = 10;
    }
    else if (U16 == L'#')
    {
        i = 11;
    }
    else if (U16 == L'+')
    {
        i = 12;
    }
    else
    {
        i = -1;
    }
    if (i >= 0)
    {
        U8 keypad_tone_type = GetKeypadToneType();

        if (keypad_tone_type < KEYPAD_TONE_HUMAN_VOICE_1 || keypad_tone_type > KEYPAD_TONE_HUMAN_VOICE_6)
        {
            keypad_tone_type = KEYPAD_TONE_HUMAN_VOICE_1;
        }
        return &resource_human_voice_tones[((keypad_tone_type - KEYPAD_TONE_HUMAN_VOICE_1) * 13 + i)];
    }
    else
#endif /* defined(DIGIT_TONE_SUPPORT) */ 
    {
    #if defined(SIMPLE_TTS)
        S16 tts_index = LookupTTS(U16);

        if (tts_index < 0)
        {
            return NULL;
        }
        return &resource_tts_sounds[tts_index];
    #else /* defined(SIMPLE_TTS) */ 
        return NULL;
    #endif /* defined(SIMPLE_TTS) */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_handle_play_text_internal_callback
 * DESCRIPTION
 *  This function handle the play text internal callback
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  mdi_result(?)
 *****************************************************************************/
void mdi_audio_handle_play_text_internal_callback(mdi_result result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_callback prev_handler;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_audio_play_text_context.state = MDI_AUDIO_PLAY_TEXT_IDLE_STATE;
    //StopTimer(MDI_AUDIO_PLAYER_TEXT_TIMER);
    gui_cancel_timer(mdi_audio_play_timeout_handler);
    prev_handler = mdi_audio_play_text_context.handler;
    if (prev_handler != NULL)
    {
        mdi_audio_play_text_context.handler = NULL;
        prev_handler(result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_current_word
 * DESCRIPTION
 *  This function play the word indicated by cursor
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_play_current_word(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;
    audio_resource_struct *audio_resource_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    if (mdi_audio_play_text_context.len <= 0)
    {
        result = MDI_AUDIO_FAIL;
    }
    else
    {
        do
        {
            audio_resource_p = mdi_audio_get_word_resource(mdi_audio_play_text_context.words[++mdi_audio_play_text_context.cursor]);
        } while (audio_resource_p == NULL && mdi_audio_play_text_context.cursor < mdi_audio_play_text_context.len - 1);
        if (audio_resource_p == NULL)
        {
            /* pretend it's playing */
            currentHandler = mdi_audio_play_text_event_handler; /* we hook up current handler to keep ourself being notified when other requests come */
            mdi_audio_state = MDI_AUDIO_PLAY;
            mdi_audio_mode = MDI_AUDIO_PLAY_STRING;
            //StartTimer(MDI_AUDIO_PLAYER_TEXT_TIMER, 40, mdi_audio_play_timeout_handler);
            gui_start_timer(40, mdi_audio_play_timeout_handler);
            result = MDI_AUDIO_SUCCESS;
        }
        else
        {
            result = mdi_audio_play_string_with_vol_path(
                        (void*)audio_resource_p->data,
                        audio_resource_p->len,
                        (U8) audio_resource_p->format,
                        DEVICE_AUDIO_PLAY_ONCE,
                        NULL,
                        mdi_audio_play_text_event_handler,
                        mdi_audio_play_text_context.volume,
                        mdi_audio_play_text_context.path);
            mdi_audio_play_text_context.identifier = identifier;
        }
    }
    if (result == MDI_AUDIO_SUCCESS)
    {
        mdi_audio_play_text_context.state = MDI_AUDIO_PLAY_TEXT_PLAY_STATE;
    }
    else
    {
        mdi_audio_handle_play_text_internal_callback(result);
    }

    MDI_AUDIO_UNLOCK;
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_timeout_handler
 * DESCRIPTION
 *  time expired event handler for a short period of time after finish playing a number or word
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_play_timeout_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    currentHandler = NULL;  /* clear the hook up */
    if (mdi_audio_play_text_context.cursor < mdi_audio_play_text_context.len - 1)
    {
        mdi_audio_play_current_word();
    }
    else
    {
        mdi_audio_state = MDI_AUDIO_IDLE;
        mdi_audio_play_text_event_handler(MDI_AUDIO_END_OF_FILE);
        mdi_audio_start_background_timer();
    }
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_text_event_handler
 * DESCRIPTION
 *  This function is to handle events during playing text
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_play_text_event_handler(mdi_result result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_audio_play_text_context.state == MDI_AUDIO_PLAY_TEXT_PLAY_STATE)
    {
        if (result == MDI_AUDIO_END_OF_FILE && mdi_audio_play_text_context.cursor < mdi_audio_play_text_context.len - 1)
        {
            /* need to play more words */
            mdi_audio_play_text_context.state = MDI_AUDIO_PLAY_TEXT_WAIT_STATE;
            currentHandler = mdi_audio_play_text_event_handler; /* we hook up current handler to keep ourself being notified when other requests come */
            //StartTimer(MDI_AUDIO_PLAYER_TEXT_TIMER, mdi_audio_play_text_context.msecs, mdi_audio_play_timeout_handler);
            gui_start_timer(mdi_audio_play_text_context.msecs, mdi_audio_play_timeout_handler);
        }
        else
        {
            mdi_audio_handle_play_text_internal_callback(result);
        }
    }
    else if (mdi_audio_play_text_context.state == MDI_AUDIO_PLAY_TEXT_WAIT_STATE)
    {
        mdi_audio_handle_play_text_internal_callback(result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_text_with_vol_path
 * DESCRIPTION
 *  This function is to play text (number or words)
 * PARAMETERS
 *  words           [?]         
 *  len             [IN]        
 *  msecs           [IN]        
 *  handle_p        [?]         
 *  handler         [IN]        
 *  volume          [IN]        
 *  path            [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_play_text_with_vol_path(
            U8 *words,
            S32 len,
            S32 msecs,
            mdi_handle *handle_p,
            mdi_callback handler,
            U8 volume,
            U8 path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mdi_audio_check_states_and_handlers(&result))
    {
        return result;
    }
    mdi_audio_play_text_context.cursor = -1;
    mdi_audio_play_text_context.len = len;
    mdi_audio_play_text_context.msecs = (msecs > 0) ? msecs : 10;
    /* to avoid 2 bytes alignment issue, copy text to the internal buffer, which is 2 bytes alignment */
    if (len > MDI_MAX_PLAY_TEXT_LEN)
    {
        len = MDI_MAX_PLAY_TEXT_LEN;
    }
    memcpy(mdi_audio_play_text_context.words, words, len << 1);
    mdi_audio_play_text_context.volume = volume;
    mdi_audio_play_text_context.path = path;
    result = mdi_audio_play_current_word();
    if (result == MDI_AUDIO_SUCCESS)
    {
        mdi_audio_play_text_context.handler = handler;
    }
    return result;
}
#endif /* defined(DIGIT_TONE_SUPPORT) || defined(SIMPLE_TTS) */ 


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_finish_ind
 * DESCRIPTION
 *  This function is to handle the play finish indication for id and string.
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_play_finish_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_audio_play_finish_ind_struct *msg_p = (l4aud_audio_play_finish_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_PLAY_FINISH_IND, mdi_audio_state);
    
    if ((mdi_audio_state == MDI_AUDIO_PLAY || mdi_audio_state == MDI_AUDIO_PLAY_PAUSED)
        && msg_p->identifier == identifier)
    {
        mdi_audio_state = MDI_AUDIO_IDLE;
        if (currentHandler)
        {
            previousHandler = currentHandler;
            currentHandler = NULL;
            previousHandler(mdi_audio_get_event(msg_p->result));        /* mdi_audio_play_text handler could set currentHandler to itself here */
        }
        mdi_audio_start_background_timer();
    }
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_finish_ind1
 * DESCRIPTION
 *  This function is to handle the play finish indication for file.
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_play_finish_ind1(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_media_play_finish_ind_struct *msg_p = (l4aud_media_play_finish_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_PLAY_FINISH_IND1, mdi_audio_state);

#ifdef __DRM_SUPPORT__
    if(mdi_audio_drm_id >= 0)
    {
        DRM_stop_consume(mdi_audio_drm_id);
        mdi_audio_drm_id = -1;
    }
#endif /*__DRM_SUPPORT__*/

    if ((mdi_audio_state == MDI_AUDIO_PLAY || mdi_audio_state == MDI_AUDIO_PLAY_PAUSED)
        && msg_p->identifier == identifier)
    {
        mdi_audio_state = MDI_AUDIO_IDLE;        
        if (currentHandler)
        {
            previousHandler = currentHandler;
            currentHandler = NULL;
            previousHandler(mdi_audio_get_event(msg_p->result));
        }
        mdi_audio_start_background_timer();
        
        updateDurHandler = NULL;
    }
    MDI_AUDIO_UNLOCK;
}

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_update_dur_ind
 * DESCRIPTION
 *  This function is to handle the update duration indication.
 * PARAMETERS
 *  inMsg       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_update_dur_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_media_play_update_dur_ind_struct *msg_p = (l4aud_media_play_update_dur_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_UPDATE_DUR_IND, msg_p->duration,msg_p->identifier,identifier);
    if ( updateDurHandler != NULL && msg_p->identifier == identifier)
    {       
        updateDurHandler(msg_p->duration);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_id
 * DESCRIPTION
 *  This function is to stop audio id.
 * PARAMETERS
 *  audio_id        [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_stop_id(U16 audio_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_STOP_ID, audio_id, mdi_audio_state, mdi_audio_mode);
    if (!mdi_check_device_ownership())
    {
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_BLOCKED;
    }

    if (audio_id > MAX_TONE_ID && !((mdi_audio_state == MDI_AUDIO_PLAY || mdi_audio_state == MDI_AUDIO_PLAY_PAUSED)
                                    && mdi_audio_mode == MDI_AUDIO_PLAY_ID))
    {
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }

    media_aud_stop_id(MOD_MMI, (U8) audio_id);

    if (audio_id > MAX_TONE_ID)
    {
        if (currentHandler)
        {
            previousHandler = currentHandler;
            currentHandler = NULL;
            previousHandler(MDI_AUDIO_TERMINATED);
        }
        mdi_audio_state = MDI_AUDIO_IDLE;
        SetProtocolEventHandler(NULL, MSG_ID_L4AUD_AUDIO_PLAY_FINISH_IND);
        mdi_audio_start_background_timer();
    }

    MDI_AUDIO_UNLOCK;
    return MDI_AUDIO_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_string
 * DESCRIPTION
 *  This function is to stop audio string.
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_stop_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_STOP_STRING, mdi_audio_state, mdi_audio_mode);
    if (!mdi_check_device_ownership())
    {
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_BLOCKED;
    }

    if (!((mdi_audio_state == MDI_AUDIO_PLAY || mdi_audio_state == MDI_AUDIO_PLAY_PAUSED)
          && mdi_audio_mode == MDI_AUDIO_PLAY_STRING))
    {
    #if defined(DIGIT_TONE_SUPPORT) || defined(SIMPLE_TTS)
        if (mdi_audio_play_text_context.state == MDI_AUDIO_PLAY_TEXT_IDLE_STATE)
    #endif
        {
            MDI_AUDIO_UNLOCK;
            return MDI_AUDIO_SUCCESS;
        }
    }

    SetProtocolEventHandler(NULL, MSG_ID_L4AUD_AUDIO_PLAY_FINISH_IND);
    media_aud_stop_string(MOD_MMI, SRC_LMMI);

    if (currentHandler)
    {
        previousHandler = currentHandler;
        currentHandler = NULL;
        previousHandler(MDI_AUDIO_TERMINATED);
    }
    mdi_audio_state = MDI_AUDIO_IDLE;
    mdi_audio_start_background_timer();

    MDI_AUDIO_UNLOCK;
    return MDI_AUDIO_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_file
 * DESCRIPTION
 *  This function is to stop audio file.
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_stop_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_STOP_FILE, mdi_audio_state, mdi_audio_mode);
    if (!mdi_check_device_ownership())
    {
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_BLOCKED;
    }

#ifdef __DRM_SUPPORT__
    if(mdi_audio_drm_id >= 0)
    {
        DRM_stop_consume(mdi_audio_drm_id);
        mdi_audio_drm_id = -1;
    }
#endif /*__DRM_SUPPORT__*/

    /*
     * set pseudo play file callback to NULL before callback
     * bcoz we could set another callback during callback
     */
    if (pseudo_play_file_callback)
    {
        mdi_callback old_pseudo_play_file_callback = pseudo_play_file_callback;
        pseudo_play_file_callback = NULL;
        old_pseudo_play_file_callback(MDI_AUDIO_TERMINATED);
    }

    if (!((mdi_audio_state == MDI_AUDIO_PLAY || mdi_audio_state == MDI_AUDIO_PLAY_PAUSED)
          && mdi_audio_mode == MDI_AUDIO_PLAY_FILE))
    {
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }

    SetProtocolEventHandler(NULL, MSG_ID_L4AUD_MEDIA_PLAY_FINISH_IND);
    SetProtocolEventHandler(NULL, MSG_ID_L4AUD_MEDIA_UPDATE_DUR_IND);
    media_aud_stop_file(MOD_MMI, SRC_LMMI);

    if (currentHandler)
    {
        previousHandler = currentHandler;
        currentHandler = NULL;
        previousHandler(MDI_AUDIO_TERMINATED);
    }
    updateDurHandler = NULL;

    mdi_audio_state = MDI_AUDIO_IDLE;
    mdi_audio_start_background_timer();

    MDI_AUDIO_UNLOCK;
    return MDI_AUDIO_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_all
 * DESCRIPTION
 *  This function is to stop all audio id/string/file.
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_stop_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_STOP_ALL, mdi_audio_state, mdi_audio_mode);

    if (!mdi_check_device_ownership())
    {
        MDI_AUDIO_UNLOCK;    
        return MDI_AUDIO_BLOCKED;
    }

    /*
     * set pseudo play file callback to NULL before callback
     * bcoz we could set another callback during callback
     */
    if (pseudo_play_file_callback)
    {
        mdi_callback old_pseudo_play_file_callback = pseudo_play_file_callback;
        pseudo_play_file_callback = NULL;
        old_pseudo_play_file_callback(MDI_AUDIO_TERMINATED);
    }
/* Vogins Start */
#ifdef __VRE__
    if (g_mdi_aud_int_callback)
    {
        mdi_callback old_int_callback = g_mdi_aud_int_callback;
        g_mdi_aud_int_callback = NULL;
        old_int_callback(MDI_AUDIO_TERMINATED);
    }
#endif
/* Vogins End */
    // to avoid the case that play finish indication of previous request is treat as the one of current request
    //if (mdi_audio_state!=MDI_AUDIO_IDLE)
    {
        switch (mdi_audio_mode)
        {
            case MDI_AUDIO_PLAY_ID:
                mdi_audio_stop_id(mdi_audio_id);
                break;
            case MDI_AUDIO_PLAY_STRING:
                mdi_audio_stop_string();
                break;
            case MDI_AUDIO_PLAY_FILE:
                mdi_audio_stop_file();
                break;
            case MDI_AUDIO_RECORD_FILE:
                mdi_audio_stop_record();
                break;
            case MDI_AUDIO_PLAY_FM_RADIO:
            case MDI_AUDIO_RECORD_FM_RADIO:
                mdi_audio_stop_fmr();
                break;
        #ifdef VR_ENABLE
            case MDI_AUDIO_RECORD_VR_VOICE:
                if (mdi_audio_state == MDI_AUDIO_RECORD)
                {
                    mdi_audio_stop_vr_voice_record();
                }
                break;
        #endif /* VR_ENABLE */ 
        #ifdef VRSI_ENABLE
            case MDI_AUDIO_VRSI_PLAY_TTS:
            case MDI_AUDIO_VRSI_PLAY_TAG:
            case MDI_AUDIO_VRSI_RECORD:
                if (mdi_audio_state == MDI_AUDIO_VRSI_PROCESS)
                {
                    mdi_audio_vrsi_stop(identifier);
                }
                break;
        #endif /* VRSI_ENABLE */ 
        #ifdef __MMI_POC__
            case MDI_AUDIO_POC_ENCODE:
                mdi_audio_poc_stop_encode();
                break;
            case MDI_AUDIO_POC_DECODE:
                mdi_audio_poc_stop_decode();
                break;
        #endif /* __MMI_POC__ */ 
        #ifdef __GENERAL_TTS__
            case MDI_AUDIO_PLAY_TTS:
                mdi_audio_tts_stop();
                break;
        #endif /* __GENERAL_TTS__ */
        #ifdef __J2ME__
            case MDI_AUDIO_PLAY_IN_OTHER_TASK:
                mdi_audio_terminate_use_by_other_task();
                break;
        #endif /* __J2ME__ */
            default:
                break;

        }

    }

    MDI_AUDIO_UNLOCK;    
    return MDI_AUDIO_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_pause
 * DESCRIPTION
 *  This function is to pause audio play/record.
 * PARAMETERS
 *  audio_handle        [IN]        mdi_callback handler
 *  handler             [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_pause(mdi_handle audio_handle, mdi_callback handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_PAUSE, mdi_audio_state);
    if (!mdi_check_device_ownership())
    {
        MDI_AUDIO_UNLOCK;    
        return MDI_AUDIO_BLOCKED;
    }

    if ((result = media_aud_pause(stack_int_get_active_module_id(), SRC_LMMI)) == MED_RES_OK)
    {
        if (mdi_audio_state == MDI_AUDIO_PLAY)
        {
        #ifdef __DRM_SUPPORT__
            if(mdi_audio_drm_id >= 0)
            {
                DRM_pause_consume(mdi_audio_drm_id);
            }                
        #endif /*__DRM_SUPPORT__*/
            mdi_audio_state = MDI_AUDIO_PLAY_PAUSED;
        }
        else
        {
            mdi_audio_state = MDI_AUDIO_RECORD_PAUSED;
        }
        currentHandler = handler;
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else if (result == MED_RES_UNSUPPORTED_OPERATION)
    {
        MDI_AUDIO_UNLOCK;    
        return MDI_AUDIO_UNSUPPORTED_OPERATION;
    }
    else
    {
        currentHandler = NULL;
        mdi_audio_state = MDI_AUDIO_IDLE;
        mdi_audio_start_background_timer();
        MDI_AUDIO_UNLOCK;
        return mdi_audio_get_event((U8) result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_store_file
 * DESCRIPTION
 *  This function is to store audio play state for restore it later
 * PARAMETERS
 *  audio_handle        [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_store_file(mdi_handle audio_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_STORE_FILE, mdi_audio_state);
    if (!mdi_check_device_ownership())
    {
        return MDI_AUDIO_BLOCKED;
    }

    if ((result = media_aud_store(MOD_MMI, SRC_LMMI)) == MED_RES_OK)
    {
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        return mdi_audio_get_event((U8) result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_restore_file_with_vol_path
 * DESCRIPTION
 *  This function is to restore audio file along with volume and output path.
 * PARAMETERS
 *  file_name       [?]         U8 play_style, mdi_handle* handle_p, mdi_callback handler
 *  play_style      [IN]        
 *  handle_p        [?]         
 *  handler         [IN]        
 *  volume          [IN]        U8 path
 *  path            [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_restore_file_with_vol_path(
            void *file_name,
            U8 play_style,
            void *cache_p,
            mdi_callback handler,
            U8 volume,
            U8 path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_play_file_struct file_param;
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_RESTORE_FILE_WITH_VOL_PATH, mdi_audio_state);

#ifdef __DRM_SUPPORT__
    /* Do not consume count in restore action */
    mdi_audio_drm_consume_count = MMI_FALSE;
#endif
    result = mdi_audio_play_file_check_state((U16*)file_name);
    if(result != MDI_AUDIO_SUCCESS)
    {
        MDI_AUDIO_UNLOCK;    
        return result;
    }

    mdi_audio_stop_background_timer();
    ++identifier;

    /* All sound shall go through bluetooth earphone */
#ifdef __MMI_BT_AUDIO_VIA_SCO__
    mmi_profiles_bt_connect_audio_via_sco();
#endif
    file_param.file_name_p = (UI_string_type) file_name;
    file_param.play_style = play_style;
    file_param.volume = volume;
    file_param.output_path = path;
    file_param.identifier = (U16) identifier;
    /* set both start_offset and end_offset to 0 for backward compatible */
    file_param.start_offset = file_param.end_offset = 0;
    file_param.cache_p = cache_p;
    if ((result = media_aud_restore(MOD_MMI, &file_param)) == MED_RES_OK)
    {
#ifdef __DRM_SUPPORT__
        mdi_audio_drm_consume_right((U16*)file_name);
#endif /*__DRM_SUPPORT__*/

        currentHandler = handler;
        mdi_audio_state = MDI_AUDIO_PLAY;
        mdi_audio_mode = MDI_AUDIO_PLAY_FILE;
        SetProtocolEventHandler(mdi_audio_play_finish_ind1, MSG_ID_L4AUD_MEDIA_PLAY_FINISH_IND);
        SetProtocolEventHandler(mdi_audio_update_dur_ind, MSG_ID_L4AUD_MEDIA_UPDATE_DUR_IND);
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
#ifdef __DRM_SUPPORT__
        mdi_audio_drm_consume_count = MMI_TRUE; /* Clear this flag for each consume request */
#endif /*__DRM_SUPPORT__*/

        currentHandler = NULL;
        updateDurHandler = NULL;
        mdi_audio_state = MDI_AUDIO_IDLE;
        mdi_audio_start_background_timer();
        MDI_AUDIO_UNLOCK;
        return mdi_audio_get_event((U8) result);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_resume
 * DESCRIPTION
 *  This function is to resume audio play/record.
 * PARAMETERS
 *  audio_handle        [IN]        mdi_callback handler
 *  handler             [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_resume(mdi_handle audio_handle, mdi_callback handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_RESUME, mdi_audio_state);
    if (!mdi_check_device_ownership())
    {
        MDI_AUDIO_UNLOCK;    
        return MDI_AUDIO_BLOCKED;
    }

    if ((result = media_aud_resume(stack_int_get_active_module_id(), SRC_LMMI)) == MED_RES_OK)
    {
        if (mdi_audio_state == MDI_AUDIO_PLAY_PAUSED)
        {
        #ifdef __DRM_SUPPORT__
            if(mdi_audio_drm_id >= 0)
            {
                DRM_resume_consume(mdi_audio_drm_id);
            }
        #endif /*__DRM_SUPPORT__*/
            mdi_audio_state = MDI_AUDIO_PLAY;
        }
        else
        {
            mdi_audio_state = MDI_AUDIO_RECORD;
        }
        currentHandler = handler;
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        currentHandler = NULL;
        mdi_audio_state = MDI_AUDIO_IDLE;
        mdi_audio_start_background_timer();
        MDI_AUDIO_UNLOCK;
        return mdi_audio_get_event((U8) result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_start_record
 * DESCRIPTION
 *  This function is to start audio record.
 * PARAMETERS
 *  file_name       [?]         U8 format, mdi_handle* handle_p, mdi_callback handler
 *  format          [IN]        
 *  handle_p        [?]         
 *  handler         [IN]        
 * RETURNS
 *  mdi_handle
 *****************************************************************************/
mdi_result mdi_audio_start_record(void *file_name, U8 format, U8 quality, mdi_handle *handle_p, mdi_callback handler)
{
    return mdi_audio_start_record_with_limit(file_name, format, quality, handle_p, handler, 0, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_start_record_with_limit
 * DESCRIPTION
 *  This function is to start audio record.
 * PARAMETERS
 *  file_name       [?]         U8 format, mdi_handle* handle_p, mdi_callback handler
 *  format          [IN]        
 *  handle_p        [?]         
 *  handler         [IN]        
 *  size_limit      [IN]        Max record size in byte.   0: Unlimited
 *  time_limit      [IN]        Max record time in second. 0: Unlimited
 * RETURNS
 *  mdi_handle
 *****************************************************************************/
mdi_result mdi_audio_start_record_with_limit(void *file_name, U8 format, U8 quality, mdi_handle *handle_p, mdi_callback handler, U32 size_limit, U32 time_limit)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_START_RECORD_WITH_LIMIT, mdi_audio_state, size_limit, time_limit);

    if (!mdi_check_device_ownership())
    {
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_BLOCKED;
    }
    else if (mdi_audio_state == MDI_AUDIO_RECORD || mdi_audio_state == MDI_AUDIO_RECORD_PAUSED)
    {
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_BUSY;
    }
    else
    {
    #ifdef __DRM_SUPPORT__
        if(mdi_audio_drm_id >= 0)
        {
            DRM_stop_consume(mdi_audio_drm_id);
            mdi_audio_drm_id = -1;
        }
    #endif /*__DRM_SUPPORT__*/
   
        /*
         * set pseudo play file callback to NULL before callback
         * bcoz we could set another callback during callback
         */
        if (pseudo_play_file_callback)
        {
            mdi_callback old_pseudo_play_file_callback = pseudo_play_file_callback;
            pseudo_play_file_callback = NULL;
            old_pseudo_play_file_callback(MDI_AUDIO_TERMINATED);
        }

        if (mdi_audio_state == MDI_AUDIO_PLAY || mdi_audio_state == MDI_AUDIO_PLAY_PAUSED
#if defined(DIGIT_TONE_SUPPORT) || defined(SIMPLE_TTS)
            || mdi_audio_play_text_context.state == MDI_AUDIO_PLAY_TEXT_WAIT_STATE
#endif 
            )
        {
        	if (currentHandler)
        	{
            	currentHandler(MDI_AUDIO_TERMINATED);
        	}
            if (mdi_audio_state == MDI_AUDIO_PLAY && mdi_audio_mode == MDI_AUDIO_PLAY_FM_RADIO)
            {
                mdi_fmr_power_off();
            }
        }
    }

    /* All sound shall go through bluetooth earphone */
#ifdef __MMI_BT_AUDIO_VIA_SCO__
    mmi_profiles_bt_connect_audio_via_sco();
#endif

    mdi_audio_stop_background_timer();

    if ((result = media_aud_start_record(stack_int_get_active_module_id(), (kal_wchar*) file_name, format, quality, TRUE, 0, size_limit, time_limit)) == MED_RES_OK)
    {
        currentHandler = handler;
        mdi_audio_state = MDI_AUDIO_RECORD;
        mdi_audio_mode = MDI_AUDIO_RECORD_FILE;
        SetProtocolEventHandler(mdi_audio_record_finish_ind, MSG_ID_L4AUD_MEDIA_RECORD_FINISH_IND);
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        currentHandler = NULL;
        mdi_audio_state = MDI_AUDIO_IDLE;
        mdi_audio_start_background_timer();
        MDI_AUDIO_UNLOCK;
        return mdi_audio_get_event((U8) result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_record_finish_ind
 * DESCRIPTION
 *  This function is to handle audio record finish indication.
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_record_finish_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_media_record_finish_ind_struct *msg_p = (l4aud_media_record_finish_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_RECORD_FINISH_IND, mdi_audio_state);
    if (mdi_audio_state == MDI_AUDIO_RECORD)
    {
        mdi_audio_state = MDI_AUDIO_IDLE;
        if (currentHandler)
        {
            previousHandler = currentHandler;
            currentHandler = NULL;
            previousHandler(mdi_audio_get_event(msg_p->result));
        }
        mdi_audio_start_background_timer();
    }
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_record
 * DESCRIPTION
 *  This function is to stop audio record.
 * PARAMETERS
 *  void
 *  void* inMsg(?)
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result mdi_audio_stop_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_STOP_RECORD, mdi_audio_state);
    if (!mdi_check_device_ownership())
    {
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_BLOCKED;
    }

    SetProtocolEventHandler(NULL, MSG_ID_L4AUD_MEDIA_RECORD_FINISH_IND);
    media_aud_stop_record(stack_int_get_active_module_id(), SRC_LMMI);

    mdi_audio_state = MDI_AUDIO_IDLE;
    if (currentHandler)
    {
        previousHandler = currentHandler;
        currentHandler = NULL;
        previousHandler(MDI_AUDIO_TERMINATED);
    }

    mdi_audio_start_background_timer();

    MDI_AUDIO_UNLOCK;
    return MDI_AUDIO_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_background_timeout_handler
 * DESCRIPTION
 *  This function is to handle background timeout.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_background_timeout_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_BG_TIMEOUT, backgroud_enabled, mdi_audio_state, mdi_speech_session_on);

    if (!mdi_check_device_ownership() || !backgroud_enabled || (mdi_audio_state != MDI_AUDIO_IDLE) || mdi_speech_session_on)
    {
        MDI_AUDIO_UNLOCK;
        return;
    }

#ifdef __MMI_POC__
    /* The POC is the highest priority, always callback it first */
    if(background_poc_handler)
    {
        if(background_poc_handler(MDI_AUDIO_RESUME))
        {
            MDI_AUDIO_UNLOCK;
            return;
        }
    }
#endif /*__MMI_POC__*/

    /* Only callback the first background handler */
    if (background_handler[0])
    {
        if (!background_handler[0] (MDI_AUDIO_RESUME))
        {
            /* If application does not use background play, it shall deregister the handler */
            ASSERT(0);
        }
    }

    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_resume_background_play
 * DESCRIPTION
 *  This function is to resume background play.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_resume_background_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_RESUME_BG_PLAY, mdi_audio_state);
    backgroud_enabled = TRUE;
    mdi_audio_start_background_timer();
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_suspend_background_play
 * DESCRIPTION
 *  This function is to suspend background play.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_suspend_background_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SUSPEND_BG_PLAY, mdi_audio_state);
    backgroud_enabled = FALSE;
    mdi_audio_stop_all();
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_disable_background_play
 * DESCRIPTION
 *  This function is to suspend background play without stop current audio
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_disable_background_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_DISABLE_BG_PLAY, mdi_audio_state);
    backgroud_enabled = FALSE;
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_is_background_play_suspended
 * DESCRIPTION
 *  This function is to check if background play suspended.
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mdi_audio_is_background_play_suspended(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL is_suspend;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    is_suspend = !backgroud_enabled;
    MDI_AUDIO_UNLOCK;
    return is_suspend;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_is_idle
 * DESCRIPTION
 *  This function is to check if audio is in idle state.
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mdi_audio_is_idle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL is_idle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    is_idle = (mdi_audio_state == MDI_AUDIO_IDLE);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_IS_IDLE, mdi_audio_state);
    MDI_AUDIO_UNLOCK;
    return is_idle;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_is_idle
 * DESCRIPTION
 *  This function is to check if audio is in idle state.
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
MMI_BOOL mdi_audio_is_playing(U16 audio_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_playing;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_IS_PLAYING, mdi_audio_state, mdi_audio_mode);
    is_playing = (mdi_audio_state == MDI_AUDIO_PLAY) && (mdi_audio_mode == audio_mode);
    MDI_AUDIO_UNLOCK;
    return is_playing;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_is_speech_mode
 * DESCRIPTION
 *  This function is to check is in speech mode
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mdi_audio_is_speech_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL is_speech_on;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    is_speech_on = mdi_speech_session_on;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_IS_SPEECH_MODE, is_speech_on);
    MDI_AUDIO_UNLOCK;
    return is_speech_on;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_set_headset_mode_output_path
 * DESCRIPTION
 *  This function is to set headset mode output path.
 * PARAMETERS
 *  device      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_set_headset_mode_output_path(unsigned char device)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_aud_set_headset_mode_output_path(MOD_MMI, device);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_set_vibrator_enabled
 * DESCRIPTION
 *  This function is to set vibrator enabled
 * PARAMETERS
 *  enable      [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_set_vibrator_enabled(BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return media_aud_set_vibrator_enabled(MOD_MMI, (kal_uint8) enable);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_set_background_handler
 * DESCRIPTION
 *  This function is to set background play timeout handler.
 *  Besides POC, the latest register callback will be called first.
 *
 * PARAMETERS
 *  level       [IN]        mdi_bg_callback handler
 *  handler     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result mdi_audio_set_background_handler(U8 app_level, mdi_bg_callback handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;
    S16 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SET_BACKGROUND_HANDLER, app_level);
    result = MDI_AUDIO_ERROR;

#ifdef __MMI_POC__
    /* POC is always the highest priority */
    if(app_level == MDI_BACKGROUND_APP_POC)
    {
        background_poc_handler = handler;
        result = MDI_AUDIO_SUCCESS;
    }
    else
#endif /* __MMI_POC__ */
    {
        /* Set the latest callback to the top of callback stack */
        if (app_level < MDI_BACKGROUND_APP_TOTAL)
        {
            for(i = 0 ; i < MDI_BACKGROUND_APP_TOTAL ; i++)
            {
                /* Matched or the first empty item */
                if((background_handler_app[i] == app_level) || (background_handler_app[i] == MDI_BACKGROUND_APP_TOTAL))
                {
                    j = i;
                    while(j > 0)
                    {
                        background_handler_app[j] = background_handler_app[j-1];
                        background_handler[j] = background_handler[j-1];
                        j--;
                    }
                    background_handler_app[0] = app_level;
                    background_handler[0] = handler;
                    break;
                }
            }

            result = MDI_AUDIO_SUCCESS;
        }

        for(i = 0 ; i < MDI_BACKGROUND_APP_TOTAL ; i++)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_BACKGROUND_HANDLER, i, background_handler_app[i]);
        }
    }

    MDI_AUDIO_UNLOCK;
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_clear_background_handler
 * DESCRIPTION
 *  This function is to reset background play timeout handler.
 * PARAMETERS
 *  level       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result mdi_audio_clear_background_handler(U8 app_level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;
    U16 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_CLEAR_BACKGROUND_HANDLER, app_level);
    result = MDI_AUDIO_ERROR;

#ifdef __MMI_POC__
    /* POC is always the highest priority */
    if(app_level == MDI_BACKGROUND_APP_POC)
    {
        background_poc_handler = NULL;
        result = MDI_AUDIO_SUCCESS;
    }
    else
#endif /*__MMI_POC__*/
    {
        if (app_level < MDI_BACKGROUND_APP_TOTAL)
        {
            /* Find the callback function and move the next element forward */
            for(i = 0 ; i < MDI_BACKGROUND_APP_TOTAL ; i++)
            {
                if(background_handler_app[i] == app_level)
                {
                    j = i;
                    while(j < (MDI_BACKGROUND_APP_TOTAL - 1))
                    {
                        background_handler_app[j] = background_handler_app[j+1];
                        background_handler[j] = background_handler[j+1];
                        j++;
                    }

                    background_handler_app[j] = MDI_BACKGROUND_APP_TOTAL;
                    background_handler[j] = NULL;

                    mdi_audio_start_background_timer();
                    break;
                }
            }
            result = MDI_AUDIO_SUCCESS;
        }

        for(i = 0 ; i < MDI_BACKGROUND_APP_TOTAL ; i++)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_BACKGROUND_HANDLER, i, background_handler_app[i]);
        }
    }
    MDI_AUDIO_UNLOCK;
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_clear_other_background_handler
 * DESCRIPTION
 *  This function is to 
 * PARAMETERS
 *  level       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result mdi_audio_clear_other_background_handler(U8 app_level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Do nothing in multi-stack background */
#ifdef __MDI_AUDIO_MULTIPLE_LAYER_BACKGROUND_PLAY__
    return MDI_AUDIO_SUCCESS;
#else
    U16 i;

    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_FINISH_BACKGROUND_PLAY, app_level);

    /* The request app must on the top level of stack */
    ASSERT(background_handler_app[0] == app_level);

    /* clear all application background play except request application itself and POC */
    for(i = 1 ; i < MDI_BACKGROUND_APP_TOTAL ; i++)
    {
        if(background_handler[i] != NULL)
        {
            background_handler[i](MDI_AUDIO_TERMINATED);
        }

        background_handler_app[i] = MDI_BACKGROUND_APP_TOTAL;
        background_handler[i] = NULL;
    }
    mdi_audio_start_background_timer();
    MDI_AUDIO_UNLOCK;
    return MDI_AUDIO_SUCCESS;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_finish_background_handler
 * DESCRIPTION
 *  This function is to 
 * PARAMETERS
 *  level       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 mdi_audio_get_background_callback_order(U8 app_level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    for(i = 0 ; i < MDI_BACKGROUND_APP_TOTAL ; i++)
    {
        if(background_handler_app[i] == app_level)
        {
            MDI_AUDIO_UNLOCK;
            return i;
        }
    }
    MDI_AUDIO_UNLOCK;
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_background_callback_register_app_num
 * DESCRIPTION
 *  This function is to 
 * PARAMETERS
 *  level       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U8 mdi_audio_get_background_callback_register_app_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j =0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    for(i = 0 ; i < MDI_BACKGROUND_APP_TOTAL ; i++)
    {
        if(background_handler_app[i] < MDI_BACKGROUND_APP_TOTAL)
        {
            j++;
        }
    }
    MDI_AUDIO_UNLOCK;
    return j;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_set_volume
 * DESCRIPTION
 *  This function is to set the volume with the given type and volume.
 * PARAMETERS
 *  type        [IN]        
 *  volume      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_set_volume(U8 type, U8 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_audio_set_volume_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = OslConstructDataPtr(sizeof(l4aud_audio_set_volume_req_struct));
    msg_p->audio_type = type;
    msg_p->volume = volume;
    msg_p->aux_volume = volume;
    msg_p->apply = TRUE;
    mdi_send_msg(MSG_ID_L4AUD_AUDIO_SET_VOLUME_REQ, msg_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_set_volume_no_apply
 * DESCRIPTION
 *  This function is to set the volume with the given type and volume
 *  but this value will not apply to HW.
 * PARAMETERS
 *  type        [IN]        
 *  volume      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_set_volume_no_apply(U8 type, U8 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_audio_set_volume_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = OslConstructDataPtr(sizeof(l4aud_audio_set_volume_req_struct));
    msg_p->audio_type = type;
    msg_p->volume = volume;
    msg_p->aux_volume = volume;
    msg_p->apply = FALSE;
    mdi_send_msg(MSG_ID_L4AUD_AUDIO_SET_VOLUME_REQ, msg_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_set_mic_volume
 * DESCRIPTION
 *  This function is to set microphone volume level
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_set_mic_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 set_index;
    U8 volume_level;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    if (mdi_speech_session_on)
    {
        set_index = AUDIO_MIC_IN_CALL;
    }
    else
    {
        set_index = AUDIO_MIC_APP;
    }

    /* Get value from setting and do range check here */
    volume_level = g_settings_audio_mic_volume.levels[set_index];
    if(volume_level >= MDI_AUD_VOL_NUM)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VALUE, volume_level, -1, -1, __LINE__);
        volume_level = 3;
    }
    mdi_audio_set_volume(MDI_VOLUME_MIC, volume_level);
    
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_state
 * DESCRIPTION
 *  This function is to get the audio state.
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_state
 *****************************************************************************/
mdi_state mdi_audio_get_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_state state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK; 
    state = mdi_audio_state;
    MDI_AUDIO_UNLOCK;
    return state;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_audio_mode
 * DESCRIPTION
 *  This function is to get the audio mode (normal, headset, loudspk).
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mdi_audio_get_audio_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return audio_mode;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_set_audio_mode
 * DESCRIPTION
 *  This function is to set the audio mode (normal, headset, loudspk).
 * PARAMETERS
 *  mode        [IN]        
 *  U8(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_set_audio_mode(U8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    mmi_eq_set_audio_mode_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    audio_mode = mode;

    myMsgPtr = (mmi_eq_set_audio_mode_req_struct*) OslConstructDataPtr(sizeof(mmi_eq_set_audio_mode_req_struct));
    myMsgPtr->mode = mode;  /* AUD_MODE_LOUDSPK, AUD_MODE_NORMAL, AUD_MODE_HEADSET  audio_mode_enum */
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = MSG_ID_MMI_EQ_SET_AUDIO_MODE_REQ;
    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_set_pseudo_play_file_callback
 * DESCRIPTION
 *  This function is to set the interrupt handler such that it will be called back
 *  before a audio play file, stop file or record action take place
 * PARAMETERS
 *  callback      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_set_pseudo_play_file_callback(mdi_callback callback)
{
    pseudo_play_file_callback = callback;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_midi_size_limit
 * DESCRIPTION
 *
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U32 mdi_audio_get_midi_size_limit(void)
{
#ifndef MED_NOT_PRESENT
    return AUD_MELODY_BUFFER_LEN;
#else
    return 500;
#endif
}


#ifdef __MMI_BT_PROFILE__


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_bt_init
 * DESCRIPTION
 *  This function is to init bluetooth open & close cnf/ind handlers.
 * PARAMETERS
 *  profile             [IN]        
 *  open_handler        [IN]        
 *  close_handler       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_bt_init(U8 profile, mdi_bt_callback open_handler, mdi_bt_callback close_handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(profile < 2);
    mdi_audio_bt_cntx.open_hdlr[profile] = open_handler;
    mdi_audio_bt_cntx.close_hdlr[profile] = close_handler;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_bt_get_stream_status
 * DESCRIPTION
 *  This function is to get the bt stream state.
 * PARAMETERS
 *  profile     [IN]        
 * RETURNS
 * BOOL
 *****************************************************************************/
U8 mdi_audio_bt_get_stream_status(U8 profile)
{
    return mdi_audio_bt_cntx.state[profile];
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_bt_close_stream_ind
 * DESCRIPTION
 *  This function is to indicate bluetooth audio stream close.
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_bt_close_stream_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bt_audio_close_ind_struct *msg_p = (media_bt_audio_close_ind_struct*) msg;
    U8 profile;
    U16 cause;
    mdi_bt_callback handler;
    U8 state;
    U8 mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    profile = msg_p->profile;
    ASSERT(profile < 2);
    cause = msg_p->cause;
    state = mdi_audio_bt_cntx.state[profile];
    handler = mdi_audio_bt_cntx.close_hdlr[profile];

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_BT_CLOSE_STREAM_IND, profile, state, cause, handler);

    if (state == MDI_AUDIO_BT_STATE_OPEN || state == MDI_AUDIO_BT_STATE_WAIT_CLOSE)
    {
        mdi_audio_bt_cntx.state[profile] = MDI_AUDIO_BT_STATE_IDLE;
        if (profile == BT_A2DP)
        {
            ASSERT(0); /* MTK A2DP should not come to here */
        }
        /* execute pending connect req */
        if( mdi_audio_bt_cntx.pending_connect[profile] )
        {
            mdi_audio_bt_cntx.pending_connect[profile] = FALSE;
            mdi_audio_bt_cntx.state[profile] = MDI_AUDIO_BT_STATE_WAIT_OPEN;

            if(profile == BT_HFP)
            {
                if(mmi_bt_is_hf_car_kit_connected())
                {
                    mode = BT_HFP_CARKIT_MODE;
                }
                else
                {
                    mode = BT_HFP_EARPHONE_MODE;
                }
            }
            else
            {
                mode = g_ssc_bt_a2dp_mode;
            }
            aud_send_bt_audio_open_req( MOD_MMI, profile, mode, 
                mdi_audio_bt_cntx.connect_id[profile] );
        }
        if (handler != NULL)
        {
            handler(profile, cause, 0);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_bt_close_stream_cnf
 * DESCRIPTION
 *  This function is to response bluetooth audio stream close.
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_bt_close_stream_cnf(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bt_audio_close_cnf_struct *msg_p = (media_bt_audio_close_cnf_struct*) msg;
    U8 profile;
    U16 result;
    mdi_bt_callback handler;
    U8 state;
    U8 mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    profile = msg_p->profile;
    ASSERT(profile < 2);
    result = msg_p->result;
    state = mdi_audio_bt_cntx.state[profile];
    handler = mdi_audio_bt_cntx.close_hdlr[profile];

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_BT_CLOSE_STREAM_CNF, profile, state, result, handler);

    if (state == MDI_AUDIO_BT_STATE_WAIT_CLOSE)
    {
        mdi_audio_bt_cntx.state[profile] = MDI_AUDIO_BT_STATE_IDLE;
        if (profile == BT_A2DP)
        {
            ASSERT(0); /* MTK A2DP should not come to here */
        }
        /* execute pending connect req */
        if( mdi_audio_bt_cntx.pending_connect[profile] )
        {
            mdi_audio_bt_cntx.pending_connect[profile] = FALSE;
            mdi_audio_bt_cntx.state[profile] = MDI_AUDIO_BT_STATE_WAIT_OPEN;
            if(profile == BT_HFP)
            {
                if(mmi_bt_is_hf_car_kit_connected())
                {
                    mode = BT_HFP_CARKIT_MODE;
                }
                else
                {
                    mode = BT_HFP_EARPHONE_MODE;
                }
            }
            else
            {
                mode = g_ssc_bt_a2dp_mode;
            }
            aud_send_bt_audio_open_req( MOD_MMI, profile, mode, 
                mdi_audio_bt_cntx.connect_id[profile] );
        }
        if (handler != NULL)
        {
            handler(profile, result, 0);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_bt_open_stream_ind
 * DESCRIPTION
 *  This function is to indicate bluetooth audio open.
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_bt_open_stream_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bt_audio_open_ind_struct *msg_p = (media_bt_audio_open_ind_struct*) msg;
    U8 profile;
    mdi_bt_callback handler;
    U8 state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    profile = msg_p->profile;
    ASSERT(profile < 2);
    state = mdi_audio_bt_cntx.state[profile];
    handler = mdi_audio_bt_cntx.open_hdlr[profile];

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_BT_OPEN_STREAM_IND, profile, state, handler);

    if (state == MDI_AUDIO_BT_STATE_IDLE || state == MDI_AUDIO_BT_STATE_WAIT_OPEN)
    {
        mdi_audio_bt_cntx.state[profile] = MDI_AUDIO_BT_STATE_OPEN;
        mdi_audio_bt_cntx.pending_connect[profile] = FALSE;
        if (handler != NULL)
        {
            handler(profile, MDI_AUDIO_SUCCESS, 0);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_bt_open_stream_cnf
 * DESCRIPTION
 *  This function is to indicate bluetooth audio stream close.
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_bt_open_stream_cnf(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bt_audio_open_cnf_struct *msg_p = (media_bt_audio_open_cnf_struct*) msg;
    U8 profile;
    U16 result;
    mdi_bt_callback handler;
    U8 state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    profile = msg_p->profile;
    ASSERT(profile < 2);
    result = msg_p->result;
    state = mdi_audio_bt_cntx.state[profile];
    handler = mdi_audio_bt_cntx.open_hdlr[profile];

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_BT_OPEN_STREAM_CNF, profile, state, result, handler);

    if (state == MDI_AUDIO_BT_STATE_WAIT_OPEN)
    {
        if (result == MDI_AUDIO_SUCCESS)
        {
            mdi_audio_bt_cntx.state[profile] = MDI_AUDIO_BT_STATE_OPEN;
        }
        else
        {
            mdi_audio_bt_cntx.state[profile] = MDI_AUDIO_BT_STATE_IDLE;
        }
        if (handler != NULL)
        {
            handler(profile, result, msg_p->error_cause);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_bt_open_stream
 * DESCRIPTION
 *  This function is to turn on bluetooth audio stream.
 * PARAMETERS
 *  profile         [IN]        
 *  connect_id      [IN]        
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mdi_audio_bt_open_stream(U8 profile, U16 connect_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 state = mdi_audio_bt_cntx.state[profile];
    U8 mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_BT_OPEN_STREAM, profile, state);

    ASSERT(profile < 2);
    if (state == MDI_AUDIO_BT_STATE_IDLE)
    {
        if(profile == BT_HFP)
        {
            if(mmi_bt_is_hf_car_kit_connected())
            {
                mode = BT_HFP_CARKIT_MODE;
            }
            else
            {
                mode = BT_HFP_EARPHONE_MODE;
            }
        }
        else
        {
            mode = g_ssc_bt_a2dp_mode;
        }
        aud_send_bt_audio_open_req(MOD_MMI, profile, mode, connect_id);
        mdi_audio_bt_cntx.state[profile] = MDI_AUDIO_BT_STATE_WAIT_OPEN;

        return TRUE;
    }
    else if( state == MDI_AUDIO_BT_STATE_WAIT_CLOSE )
    {
        /* postpond thie connect req to disconnect ind or cnf */
        mdi_audio_bt_cntx.pending_connect[profile] = TRUE;
        mdi_audio_bt_cntx.connect_id[profile] = connect_id;

        return TRUE;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_bt_close_stream
 * DESCRIPTION
 *  This function is to turn off bluetooth audio stream.
 * PARAMETERS
 *  profile     [IN]        
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mdi_audio_bt_close_stream(U8 profile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 state = mdi_audio_bt_cntx.state[profile];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_BT_CLOSE_STREAM, profile, state);

    ASSERT(profile < 2);

    /* clean up pending connect req */
    if( mdi_audio_bt_cntx.pending_connect[profile] )
    {
        mdi_audio_bt_cntx.pending_connect[profile] = FALSE;
        mdi_audio_bt_cntx.open_hdlr[profile]( profile, MDI_AUDIO_FAIL, 0);
    }

    if (state == MDI_AUDIO_BT_STATE_OPEN || state == MDI_AUDIO_BT_STATE_WAIT_OPEN)
    {
        if(profile == BT_A2DP)
        {
            ASSERT(0); /* MTK A2DP should not come to here */
        }
        else /* BT_HFP */
        {
            /* Use blocking mode request function for HFP profile */
            /* To make sure MED will send message to BT before MMI continues */
            media_aud_bt_audio_close(profile);
        }
        mdi_audio_bt_cntx.state[profile] = MDI_AUDIO_BT_STATE_WAIT_CLOSE;

        return TRUE;
    }
    else if (profile == BT_A2DP && state == MDI_AUDIO_BT_STATE_IDLE)
    {
        ASSERT(0); /* MTK A2DP should not come to here */
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_bt_is_stream_open
 * DESCRIPTION
 *  This function is to check the state to know if bt audio is open.
 * PARAMETERS
 *  profile     [IN]        
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mdi_audio_bt_is_stream_open(U8 profile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 state = mdi_audio_bt_cntx.state[profile];
    BOOL result = (state == MDI_AUDIO_BT_STATE_OPEN) || (state == MDI_AUDIO_BT_STATE_WAIT_CLOSE);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_BT_IS_STREAM_OPEN, profile, state, result);

    ASSERT(profile < 2);
    return result;
}


/******************************************************************
* FUNCTION
*    mdi_audio_bt_hfp_turn_on
* DESCRIPTION
*    This function is to change audio path to SCO
* PARAMETERS
*    void
* RETURNS
*    void
* GLOBALS AFFECTED
*  
******************************************************************/
void mdi_audio_bt_hfp_turn_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 state = mdi_audio_bt_cntx.state[BT_HFP];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_BT_HFP_TURN_ON, state);

    if(mdi_audio_bt_is_stream_open(BT_HFP))
    {
        aud_send_bt_audio_turn_on_req( MOD_MMI, BT_HFP );
    }
}


/******************************************************************
* FUNCTION
*    mdi_audio_bt_hfp_turn_off
* DESCRIPTION
*    This function is to change audio path to mobile device
* PARAMETERS
*    void
* RETURNS
*    void
* GLOBALS AFFECTED
*  
******************************************************************/
void mdi_audio_bt_hfp_turn_off(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 state = mdi_audio_bt_cntx.state[BT_HFP];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_BT_HFP_TURN_OFF, state);

    if(mdi_audio_bt_is_stream_open(BT_HFP))
    {
        /* Use blocking mode request function for HFP profile */
        /* To make sure MED will send message to BT before MMI continues */    
        media_aud_bt_turn_off_audio(BT_HFP );
    }        
}
#endif /* __MMI_BT_PROFILE__ */ 

#ifdef __MMI_A2DP_SUPPORT__
/******************************************************************
* FUNCTION
*    mdi_audio_bt_is_a2dp_codec_open
* DESCRIPTION
*    This function is to check if a2dp is under streaming state or codec
*    is open. For performance tuning querying.
* PARAMETERS
*    void
* RETURNS
*    BOOL
* GLOBALS AFFECTED
*  
******************************************************************/
BOOL mdi_audio_bt_is_a2dp_codec_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_A2DP_SUPPORT__)
    result = av_bt_is_codec_open();
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_BT_IS_A2DP_CODEC_ON, result);
#endif

    return result ;
}
#endif /*__MMI_A2DP_SUPPORT__*/

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_set_mute
 * DESCRIPTION
 *  This function is to set mute on the given volume type.
 * PARAMETERS
 *  vol_type        [IN]        
 *  mute            [IN]        
 *  BOOL on(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_set_mute(U8 vol_type, BOOL mute)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_set_mute_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = OslConstructDataPtr(sizeof(media_aud_set_mute_req_struct));

    msg_p->vol_type = vol_type;
    msg_p->mute = mute;

    mdi_send_msg(MSG_ID_MEDIA_AUD_SET_MUTE_REQ, msg_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_send_msg
 * DESCRIPTION
 *  This function is to send message to MED task.
 * PARAMETERS
 *  msg_id              [IN]        void *local_param_ptr, void *peer_buf_ptr
 *  local_param_ptr     [?]         
 *  peer_buf_ptr        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_send_msg(U16 msg_id, void *local_param_ptr, void *peer_buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->src_mod_id = MOD_MMI;
    ilm_ptr->sap_id = MED_SAP;      /* MMI_L4C_SAP; */
    ilm_ptr->dest_mod_id = MOD_MED; /* MOD_L4C; */

    ilm_ptr->msg_id = (kal_uint16) msg_id;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) peer_buf_ptr;

    msg_send_ext_queue(ilm_ptr);
}

/******** For multiple players ****************/

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_covert_data_format
 * DESCRIPTION
 *  This function is to...
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
static S16 mdi_audio_mma_covert_data_format(U8 mdi_format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 mma_format = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(mdi_format)
    {
#ifdef __MTK_TARGET__    
        case MDI_FORMAT_SMF:
            mma_format = MMA_TYPE_MIDI;
            break;
        case MDI_FORMAT_WAV:
            mma_format = MMA_TYPE_WAV;
            break;
        case MDI_FORMAT_IMELODY:
            mma_format = MMA_TYPE_IMY;
            break;
        case MDI_FORMAT_AMR:
            mma_format = MMA_TYPE_AMR;
            break;
        case MDI_FORMAT_DAF:
            mma_format = MMA_TYPE_DAF;
            break;
        case MDI_FORMAT_MUSICAM:
            mma_format = MMA_TYPE_MUSICAM;
            break;
        case MDI_FORMAT_AAC:
            mma_format = MMA_TYPE_AAC;
            break;
        case MDI_FORMAT_AU:
            mma_format = MMA_TYPE_AU;
            break;
        case MDI_FORMAT_AMR_WB:
            mma_format = MMA_TYPE_AWB;
            break;
        case MDI_FORMAT_WMA:
            mma_format = MMA_TYPE_WMA;
            break;
#endif /*__MTK_TARGET__*/
        default:
            break;
    }

    return mma_format;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_find_empty_player
 * DESCRIPTION
 *  This function is to...
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
static S16 mdi_audio_mma_find_player(mdi_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i = 0 ; i < MMA_NO_OF_PLAYER ; i++)
    {
        if(mdi_audio_mma_player[i].handle == handle)
        {
            return i;
        }
    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_med_direct_callback
 * DESCRIPTION
 *  This function is the callback function from MED. 
 *  It will send message from MED to MMI
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_audio_mma_med_direct_callback(kal_int32 handle, kal_int32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_callback_ind_struct *ind_p;
    ilm_struct *ilm_ptr = NULL;
    S16 curr_player;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_MMA_MED_DIRECT_CALLBACK, handle, result);

    curr_player = mdi_audio_mma_find_player(handle);

    if(curr_player >= 0)
    {
        ind_p = (media_mma_callback_ind_struct*)
            construct_local_para(sizeof(media_mma_callback_ind_struct), TD_CTRL);
        ind_p->handle = handle;
        ind_p->result = result;
        ind_p->player_id = mdi_audio_mma_player[curr_player].player_id;
        ind_p->seq_id = mdi_audio_mma_player[curr_player].seq_id;

        ilm_ptr = allocate_ilm(MOD_MED);
        ilm_ptr->src_mod_id = MOD_MED;
        ilm_ptr->dest_mod_id = MOD_MMI;    
        ilm_ptr->sap_id = MED_SAP;

        ilm_ptr->msg_id = MSG_ID_MEDIA_MMA_CALLBACK_IND;
        ilm_ptr->local_para_ptr = (local_para_struct*) ind_p;
        ilm_ptr->peer_buff_ptr = NULL;

        msg_send_ext_queue(ilm_ptr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_callback_hdlr
 * DESCRIPTION
 *  This function is to...
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_audio_mma_callback_hdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_mma_callback_ind_struct *msg_p = (media_mma_callback_ind_struct*) inMsg;
    S16 curr_player;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    curr_player = mdi_audio_mma_find_player(msg_p->handle);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_MMA_CALLBACK_HDLR, curr_player);

    if((curr_player >= 0) &&
       (msg_p->player_id == mdi_audio_mma_player[curr_player].player_id)&&
       (msg_p->seq_id == mdi_audio_mma_player[curr_player].seq_id))
    {
        /* Set start time to 0 for next play request */
        media_mma_aud_set_start_time(stack_int_get_active_module_id(), mdi_audio_mma_player[curr_player].handle, mdi_audio_mma_player[curr_player].format, 0);
    
        if(mdi_audio_mma_player[curr_player].callback)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_MMA_CALLBACK_APP);
            mdi_audio_mma_player[curr_player].callback(msg_p->handle, msg_p->result);
        }

        mdi_audio_mma_player[curr_player].state = MDI_AUDIO_IDLE;
    }
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_init
 * DESCRIPTION
 *  This function is to...
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_mma_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i = 0 ; i < MMA_NO_OF_PLAYER ; i++)
    {
        memset(&mdi_audio_mma_player[i], 0, sizeof(mdi_audio_mma_player_struct));
    }

    mdi_audio_mma_player_id = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_open_file
 * DESCRIPTION
 *  This function is to...
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
mdi_handle mdi_audio_mma_open_file(void *file_name, U8 repeats, mdi_mma_callback callback)
{
#if defined(__MTK_TARGET__) && defined(DSP_WT_SYN)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_player_struct param;
    mdi_handle handle = 0;
    kal_int32 result, empty_player;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_MMA_OPEN_FILE);

    if (currentHandler)
    {
        currentHandler(MDI_AUDIO_TERMINATED);
    }

    SetProtocolEventHandler(mdi_audio_mma_callback_hdlr, MSG_ID_MEDIA_MMA_CALLBACK_IND);

    param.handler = mdi_audio_mma_med_direct_callback;
    param.media_type = 0; //Don't Care. MED will parse file extension to get file type.
    param.data = NULL;
    param.size = 0;
    param.file_path = (kal_wchar*)file_name;
    param.repeats = repeats;
    param.progressive_dl = 0;

    handle = media_mma_aud_open(stack_int_get_active_module_id(), &param, &result);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_MMA_OPEN_FILE_RESULT, handle, result);
    
    if(handle != 0)
    {
        empty_player = mdi_audio_mma_find_player(NULL);
        ASSERT(empty_player >= 0);

        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VALUE, empty_player, -1, -1, __LINE__);

        mdi_audio_mma_player[empty_player].handle = handle;
        mdi_audio_mma_player[empty_player].callback = callback;        
        mdi_audio_mma_player[empty_player].state = MDI_AUDIO_IDLE;
        mdi_audio_mma_player[empty_player].format = MMA_NO_OF_AUDIO_TYPE; /* Don't care format */
        mdi_audio_mma_player[empty_player].player_id = mdi_audio_mma_player_id;
        mdi_audio_mma_player[empty_player].seq_id = 0;
        mdi_audio_mma_player_id++;
    }

    MDI_AUDIO_UNLOCK;
    return handle;
#else  /* #if defined(__MTK_TARGET__) && defined(DSP_WT_SYN) */
    return 0;
#endif /* #if defined(__MTK_TARGET__) && defined(DSP_WT_SYN) */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_open_string
 * DESCRIPTION
 *  This function is to...
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
mdi_handle mdi_audio_mma_open_string(void *audio_data, U32 len, U8 mdi_format, U8 repeats, mdi_mma_callback callback)
{
#if defined(__MTK_TARGET__) && defined(DSP_WT_SYN)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_player_struct param;
    mdi_handle handle = 0;
    kal_int32 result, empty_player;
    S16 mma_type;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_MMA_OPEN_STRING, mdi_format);

    if (currentHandler)
    {
        currentHandler(MDI_AUDIO_TERMINATED);
    }

    SetProtocolEventHandler(mdi_audio_mma_callback_hdlr, MSG_ID_MEDIA_MMA_CALLBACK_IND);

    /* Convert MDI type to MMA type */
    mma_type = mdi_audio_mma_covert_data_format(mdi_format);
    if(mma_type < 0)
    {
        MDI_AUDIO_UNLOCK;
        return 0;
    }
    
    /* Fill up MMA player structure */
    param.handler = mdi_audio_mma_med_direct_callback;
    param.media_type = mma_type;
    param.data = (kal_uint8*) audio_data;
    param.size = len;
    param.file_path = NULL;
    param.repeats = repeats;
    param.progressive_dl = 0;
    
    handle = media_mma_aud_open(stack_int_get_active_module_id(), &param, &result);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_MMA_OPEN_STRING_RESULT, handle, result);

    if(handle != 0)
    {
        empty_player = mdi_audio_mma_find_player(NULL);
        ASSERT(empty_player >= 0);

        MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VALUE, empty_player, -1, -1, __LINE__);
        
        mdi_audio_mma_player[empty_player].handle = handle;
        mdi_audio_mma_player[empty_player].callback = callback;        
        mdi_audio_mma_player[empty_player].state = MDI_AUDIO_IDLE;
        mdi_audio_mma_player[empty_player].format = mma_type;
        mdi_audio_mma_player[empty_player].player_id = mdi_audio_mma_player_id;
        mdi_audio_mma_player[empty_player].seq_id = 0;        
        mdi_audio_mma_player_id++;
    }

    MDI_AUDIO_UNLOCK;
    return handle;
#else /* #if defined(__MTK_TARGET__) && defined(DSP_WT_SYN) */
    return 0;
#endif /* #if defined(__MTK_TARGET__) && defined(DSP_WT_SYN)*/

}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_play
 * DESCRIPTION
 *  This function is to...
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result mdi_audio_mma_play(mdi_handle handle)
{
#if defined(__MTK_TARGET__) && defined(DSP_WT_SYN)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 curr_player;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    curr_player = mdi_audio_mma_find_player(handle);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_MMA_PLAY, handle, curr_player);
    
    /* All sound shall go through bluetooth earphone */
#ifdef __MMI_BT_AUDIO_VIA_SCO__
    mmi_profiles_bt_connect_audio_via_sco();
#endif

    result = media_mma_aud_play(stack_int_get_active_module_id(), handle, mdi_audio_mma_player[curr_player].format);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VALUE, result, mdi_audio_mma_player[curr_player].state, -1, __LINE__);

    if(result == MED_RES_OK)
    {
        mdi_audio_mma_player[curr_player].state = MDI_AUDIO_PLAY;
    }

    MDI_AUDIO_UNLOCK;
    return result;
#else /* defined(__MTK_TARGET__) && defined(DSP_WT_SYN) */ 
    return 0;
#endif /* defined(__MTK_TARGET__) && defined(DSP_WT_SYN) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_pause
 * DESCRIPTION
 *  This function is to...
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result mdi_audio_mma_pause(mdi_handle handle)
{
#if defined(__MTK_TARGET__) && defined(DSP_WT_SYN)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 curr_player;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    curr_player = mdi_audio_mma_find_player(handle);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_MMA_PAUSE, handle, curr_player);

    result = media_mma_aud_pause(stack_int_get_active_module_id(), handle, mdi_audio_mma_player[curr_player].format);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VALUE, result, mdi_audio_mma_player[curr_player].state, -1, __LINE__);

    if(result == MED_RES_OK)
    {
        mdi_audio_mma_player[curr_player].state = MDI_AUDIO_PLAY_PAUSED;
    }

    MDI_AUDIO_UNLOCK;
    return result;
#else /* defined(__MTK_TARGET__) && defined(DSP_WT_SYN) */ 
    return 0;
#endif /* defined(__MTK_TARGET__) && defined(DSP_WT_SYN) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_resume
 * DESCRIPTION
 *  This function is to...
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result mdi_audio_mma_resume(mdi_handle handle)
{
#if defined(__MTK_TARGET__) && defined(DSP_WT_SYN)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 curr_player;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    curr_player = mdi_audio_mma_find_player(handle);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_MMA_RESUME, handle, curr_player);
    
    result = media_mma_aud_resume(stack_int_get_active_module_id(), handle, mdi_audio_mma_player[curr_player].format);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VALUE, result, mdi_audio_mma_player[curr_player].state, -1, __LINE__);

    if(result == MED_RES_OK)
    {
        mdi_audio_mma_player[curr_player].state = MDI_AUDIO_PLAY;
    }

    MDI_AUDIO_UNLOCK;
    return result;
#else /* defined(__MTK_TARGET__) && defined(DSP_WT_SYN) */ 
    return 0;
#endif /* defined(__MTK_TARGET__) && defined(DSP_WT_SYN) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_stop
 * DESCRIPTION
 *  This function is to...
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result mdi_audio_mma_stop(mdi_handle handle)
{
#if defined(__MTK_TARGET__) && defined(DSP_WT_SYN)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 curr_player;
    S32 result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    curr_player = mdi_audio_mma_find_player(handle);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_MMA_STOP, handle, curr_player);

    result = media_mma_aud_stop(stack_int_get_active_module_id(), handle, mdi_audio_mma_player[curr_player].format);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VALUE, result, mdi_audio_mma_player[curr_player].state, -1, __LINE__);

    mdi_audio_mma_player[curr_player].state = MDI_AUDIO_IDLE;
    mdi_audio_mma_player[curr_player].seq_id++;

    /* Set start time to 0 for next play request */
    media_mma_aud_set_start_time(stack_int_get_active_module_id(), handle, mdi_audio_mma_player[curr_player].format, 0);

    MDI_AUDIO_UNLOCK;
    return result;
#else /* defined(__MTK_TARGET__) && defined(DSP_WT_SYN) */ 
    return 0;
#endif /* defined(__MTK_TARGET__) && defined(DSP_WT_SYN) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_close
 * DESCRIPTION
 *  This function is to...
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result mdi_audio_mma_close(mdi_handle handle)
{
#if defined(__MTK_TARGET__) && defined(DSP_WT_SYN)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 curr_player;
    S32 result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    curr_player = mdi_audio_mma_find_player(handle);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_MMA_CLOSE, handle, curr_player);

    result = media_mma_aud_close(stack_int_get_active_module_id(), handle, mdi_audio_mma_player[curr_player].format);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VALUE, result, mdi_audio_mma_player[curr_player].state, -1, __LINE__);

    memset(&mdi_audio_mma_player[curr_player], 0, sizeof(mdi_audio_mma_player_struct));

    MDI_AUDIO_UNLOCK;
    return result;
#else /* defined(__MTK_TARGET__) && defined(DSP_WT_SYN) */ 
    return 0;
#endif /* defined(__MTK_TARGET__) && defined(DSP_WT_SYN) */ 
}



/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_close_all
 * DESCRIPTION
 *  This function is to...
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_mma_close_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    for(i = 0 ; i < MMA_NO_OF_PLAYER ; i++)
    {
        if(mdi_audio_mma_player[i].state != MDI_AUDIO_IDLE)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VALUE, i, -1, -1, __LINE__);

            /* Inform Application that MMA is being terminated */
            if(mdi_audio_mma_player[i].callback)
            {
                mdi_audio_mma_player[i].callback(mdi_audio_mma_player[i].handle, MDI_AUDIO_TERMINATED);
            }
            
            /* Stop then close the mma */
            mdi_audio_mma_stop(mdi_audio_mma_player[i].handle);
            mdi_audio_mma_close(mdi_audio_mma_player[i].handle);
        }
    }
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_is_idle
 * DESCRIPTION
 *  This function is to...
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool mdi_audio_mma_is_idle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    for(i = 0 ; i < MMA_NO_OF_PLAYER ; i++)
    {
        if(mdi_audio_mma_player[i].state != MDI_AUDIO_IDLE)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_MMA_IS_IDLE, 0);
            MDI_AUDIO_UNLOCK;
            return KAL_FALSE;
        }
    }

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_MMA_IS_IDLE, 1);
    MDI_AUDIO_UNLOCK;
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_is_open
 * DESCRIPTION
 *  This function is to...
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool mdi_audio_mma_is_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    for(i = 0 ; i < MMA_NO_OF_PLAYER ; i++)
    {
        // TODO: Add trace
        if(mdi_audio_mma_player[i].handle != NULL)
        {
            MDI_AUDIO_UNLOCK;
            return KAL_TRUE;
        }
    }

    MDI_AUDIO_UNLOCK;
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_set_start_time
 * DESCRIPTION
 *  This function is to...
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result mdi_audio_mma_set_start_time(mdi_handle handle, S32 start_time)
{
#if defined(__MTK_TARGET__) && defined(DSP_WT_SYN)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 curr_player;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_player = mdi_audio_mma_find_player(handle);
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VALUE, handle, curr_player, -1, __LINE__);

    result = media_mma_aud_set_start_time(stack_int_get_active_module_id(), handle, mdi_audio_mma_player[curr_player].format, start_time);

    return result;
#else /* defined(__MTK_TARGET__) && defined(DSP_WT_SYN) */ 
    return 0;
#endif /* defined(__MTK_TARGET__) && defined(DSP_WT_SYN) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_open_midi
 * DESCRIPTION
 *  This function is to open one midi player. Currently one player is supported.
 * PARAMETERS
 *  audio_data      [?]         
 *  len             [IN]        
 *  repeats         [IN]        
 *  handler         [IN]        
 * RETURNS
 *  mdi_handle
 *****************************************************************************/
mdi_handle mdi_audio_mma_open_midi(void *audio_data, U32 len, U8 repeats, mdi_mma_callback handler)
{
    return mdi_audio_mma_open_string(audio_data,len, MDI_FORMAT_SMF, repeats, handler);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_close_midi
 * DESCRIPTION
 *  This function is to close midi player.
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_mma_close_midi(mdi_handle handle)
{
    return mdi_audio_mma_close(handle);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_play_midi
 * DESCRIPTION
 *  This function is to play midi.
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_mma_play_midi(mdi_handle handle)
{
    return mdi_audio_mma_play(handle);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_stop_midi
 * DESCRIPTION
 *  This function is to stop midi.
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_mma_stop_midi(mdi_handle handle)
{
    return mdi_audio_mma_stop(handle);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_open_wav
 * DESCRIPTION
 *  This function is to open one wav player. Currently 3 players is supported.
 * PARAMETERS
 *  audio_data      [?]         
 *  len             [IN]        
 *  repeats         [IN]        
 *  handler         [IN]        
 * RETURNS
 *  mdi_handle
 *****************************************************************************/
mdi_handle mdi_audio_mma_open_wav(void *audio_data, U32 len, U8 repeats, mdi_mma_callback handler)
{
    return mdi_audio_mma_open_string(audio_data, len, MDI_FORMAT_WAV, repeats, handler);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_close_wav
 * DESCRIPTION
 *  This function is to close wav player.
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_mma_close_wav(mdi_handle handle)
{
    return mdi_audio_mma_close(handle); 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_play_wav
 * DESCRIPTION
 *  This function is to play wav.
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_mma_play_wav(mdi_handle handle)
{
    return mdi_audio_mma_play(handle);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_stop_wav
 * DESCRIPTION
 *  This function is to stop wav.
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_mma_stop_wav(mdi_handle handle)
{
    return mdi_audio_mma_stop(handle);
}


/* FM Radio Begin */

/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_power_on_with_path
 * DESCRIPTION
 *  This function is to turn on FM radio with specific output path
 * PARAMETERS
 *  path        [IN]        
 *  handler     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_power_on_with_path(U8 path, mdi_callback handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    if (!mdi_check_device_ownership() ||
        (mdi_audio_state == MDI_AUDIO_PLAY && mdi_audio_mode == MDI_AUDIO_PLAY_FM_RADIO))
    {
        MDI_AUDIO_UNLOCK;
        return;
    }

/* Vogins Start */
#ifdef __VRE__
    if ((mdi_audio_state != MDI_AUDIO_IDLE) || (g_mdi_aud_int_callback != NULL))
#else
    if (mdi_audio_state != MDI_AUDIO_IDLE)
#endif
/* Vogins End */
    {
        mdi_audio_stop_all();
    }

    mdi_audio_stop_background_timer();
    media_aud_fmr_power_on(MOD_MMI, path);

    /* Combinations to connect SCO */
#if defined(__MMI_BT_FM_VIA_SCO__)
    #ifdef __MMI_BT_AUDIO_VIA_SCO__
        if(mdi_audio_bt_cntx.state[BT_HFP] == MDI_AUDIO_BT_STATE_OPEN)
        {
            mmi_profiles_bt_disable_sco_timeout();        
            /* Just change path to FM when SCO connected */
            mdi_audio_bt_hfp_turn_off();
            mdi_audio_bt_hfp_turn_on();
        }
        else
    #endif        
        {
            mmi_profiles_bt_connect_audio_via_sco();        
        }
#elif defined(__MMI_BT_AUDIO_VIA_SCO__)
    mmi_profiles_bt_disable_sco_connection(MMI_PROFILE_BT_SCO_INT_FMRADIO);
#endif

    currentHandler = handler;
    mdi_audio_state = MDI_AUDIO_PLAY;
    mdi_audio_mode = MDI_AUDIO_PLAY_FM_RADIO;

    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_fmr
 * DESCRIPTION
 *  This function is to stop FM radio playing/recording
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_stop_fmr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_STOP_FMR, mdi_audio_state, mdi_audio_mode);

    if (mdi_audio_state == MDI_AUDIO_PLAY && mdi_audio_mode == MDI_AUDIO_PLAY_FM_RADIO)
    {
        if (currentHandler)
        {
            currentHandler(MDI_AUDIO_TERMINATED);
        }
        mdi_fmr_power_off();
    }
#ifdef FM_RADIO_RECORD
    /* Stop FM Record and Turn off FM Radio */
    else if ((mdi_audio_state == MDI_AUDIO_RECORD || mdi_audio_state == MDI_AUDIO_RECORD_PAUSED) &&
             mdi_audio_mode == MDI_AUDIO_RECORD_FM_RADIO)
    {
        mdi_fmr_stop_record();  /* Stop before callback because need to handle record file in MMI */
        if (currentHandler)
        {
            currentHandler(MDI_AUDIO_TERMINATED);
        }
        mdi_fmr_power_off();
    }
#endif /* FM_RADIO_RECORD */

    MDI_AUDIO_UNLOCK;
    return MDI_AUDIO_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_power_off
 * DESCRIPTION
 *  This function is to turn off FM radio
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_power_off(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    if (mdi_audio_state == MDI_AUDIO_IDLE)
    {
        MDI_AUDIO_UNLOCK;
        return;
    }

    media_aud_fmr_power_off(MOD_MMI);

    /* Combinations to connect SCO */
#if defined(__MMI_BT_FM_VIA_SCO__)
    #ifdef __MMI_BT_AUDIO_VIA_SCO__
        mmi_profiles_bt_enable_sco_timeout();
        if(mdi_audio_bt_cntx.state[BT_HFP] == MDI_AUDIO_BT_STATE_OPEN)
        {
            /* Just change path to FM when SCO connected */
            mdi_audio_bt_hfp_turn_off();
            mdi_audio_bt_hfp_turn_on();
        }
    #else
        mmi_profiles_bt_disconnect_sco();
    #endif        
#elif defined(__MMI_BT_AUDIO_VIA_SCO__)
    mmi_profiles_bt_enable_sco_connection(MMI_PROFILE_BT_SCO_INT_FMRADIO);
#endif  

    mdi_audio_state = MDI_AUDIO_IDLE;
    mdi_audio_start_background_timer();

    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_set_freq
 * DESCRIPTION
 *  This function is to set the frequency of FM radio.
 * PARAMETERS
 *  freq        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_set_freq(U16 freq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    if (mdi_audio_state != MDI_AUDIO_IDLE)
    {
        media_aud_fmr_set_freq(MOD_MMI, freq);
    }
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_mute
 * DESCRIPTION
 *  This function is to mute the FM radio
 * PARAMETERS
 *  mute        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_mute(U8 mute)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    if (mdi_audio_state != MDI_AUDIO_IDLE)
    {
        media_aud_fmr_mute(MOD_MMI, mute);
    }
    MDI_AUDIO_UNLOCK;
}


#ifdef FM_RADIO_HW_SEARCH
/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_freq_seek_result_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_freq_seek_result_ind(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_seek_result_ind_struct *msg_p = (media_fmr_seek_result_ind_struct*) in_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_fmr_seek_result_hdlr != NULL)
    {
        mdi_fmr_seek_result_hdlr(msg_p->stop_freq, msg_p->signal_level, msg_p->is_valid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_freq_seek_start
 * DESCRIPTION
 *   Start to seek
 * PARAMETERS
 *  start_freq      [IN]    start frequency
 *  is_step_up      [IN]    seek direction
 *  is_preset       [IN]    it will not wrap around if it is preset auto search
 *  space           [IN]    minimum space between two frequency. 200: 200KHz, 100: 100KHz
 *  callback_func   [IN]    callback function when found a valid freq or user abortion
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_freq_seek_start(U16 start_freq, MMI_BOOL is_step_up, MMI_BOOL is_preset, S16 space, void (*callback_func) (U16 stop_freq, U8 signal_level, MMI_BOOL is_valid)) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_seek_start_req_struct *msg_p = OslConstructDataPtr(sizeof(media_fmr_seek_start_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->start_freq = start_freq;
    msg_p->is_step_up = is_step_up;
    msg_p->is_preset = is_preset;
    msg_p->space = space;
    
    mdi_fmr_seek_result_hdlr = callback_func;
    SetProtocolEventHandler(mdi_fmr_freq_seek_result_ind, MSG_ID_MEDIA_FMR_SEEK_RESULT_IND);
    mdi_send_msg(MSG_ID_MEDIA_FMR_SEEK_START_REQ, msg_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_freq_seek_abort
 * DESCRIPTION
 *  Abort seek. After abortion, it will call the callback function register 
 *  in mdi_fmr_freq_seek_start.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_freq_seek_abort(void) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_send_msg(MSG_ID_MEDIA_FMR_SEEK_ABORT_REQ, NULL, NULL);
}

#else /* FM_RADIO_HW_SEARCH */


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_check_is_valid_stop_cnf
 * DESCRIPTION
 *  This function is the callback function of check valid stop
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_check_is_valid_stop_cnf(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_check_is_valid_stop_cnf_struct *msg_p = (media_fmr_check_is_valid_stop_cnf_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_fmr_check_is_valid_stop_hdlr != NULL)
    {
        mdi_fmr_check_is_valid_stop_hdlr(msg_p->is_valid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_check_is_valid_stop
 * DESCRIPTION
 *  This function is to check if a frequency is valid stop
 * PARAMETERS
 *  freq                [IN]        
 *  is_step_up          [IN]        
 *  callback_func       [IN]        
 *  BOOL is_set_up,(?)
 *  void (*callback_func)(BOOL is_valid)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_check_is_valid_stop(U16 freq, BOOL is_step_up, void (*callback_func) (BOOL is_valid))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_check_is_valid_stop_req_struct *msg_p = OslConstructDataPtr(sizeof(media_fmr_check_is_valid_stop_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->freq = freq;
    msg_p->is_step_up = is_step_up;
    mdi_fmr_check_is_valid_stop_hdlr = callback_func;
    SetProtocolEventHandler(mdi_fmr_check_is_valid_stop_cnf, MSG_ID_MEDIA_FMR_CHECK_IS_VALID_STOP_CNF);
    mdi_send_msg(MSG_ID_MEDIA_FMR_CHECK_IS_VALID_STOP_REQ, msg_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_cancel_checking_is_valid_stop
 * DESCRIPTION
 *  This function is to cancel check valid stop
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_cancel_checking_is_valid_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(NULL, MSG_ID_MEDIA_FMR_CHECK_IS_VALID_STOP_CNF);
    mdi_fmr_check_is_valid_stop_hdlr = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_get_signal_level_cnf
 * DESCRIPTION
 *  Thsi function is the callback function of get signal level
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_get_signal_level_cnf(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_get_signal_level_cnf_struct *msg_p = (media_fmr_get_signal_level_cnf_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_fmr_get_signal_level_hdlr != NULL)
    {
        mdi_fmr_get_signal_level_hdlr(msg_p->signal_level);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_get_signal_level
 * DESCRIPTION
 *  This function is to get the signal level of a frequency
 * PARAMETERS
 *  freq                [IN]        
 *  is_step_up          [IN]        
 *  callback_func       [IN]        
 *  void (*callback_func)(U8 sig_lvl)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_get_signal_level(U16 freq, BOOL is_step_up, void (*callback_func) (U8 sig_lvl))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_fmr_get_signal_level_req_struct *msg_p = OslConstructDataPtr(sizeof(media_fmr_get_signal_level_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->freq = freq;
    msg_p->is_step_up = is_step_up;
    mdi_fmr_get_signal_level_hdlr = callback_func;
    SetProtocolEventHandler(mdi_fmr_get_signal_level_cnf, MSG_ID_MEDIA_FMR_GET_SIGNAL_LEVEL_CNF);
    mdi_send_msg(MSG_ID_MEDIA_FMR_GET_SIGNAL_LEVEL_REQ, msg_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_cancel_getting_signal_level
 * DESCRIPTION
 *  This fuction is to cancel get signal level request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_cancel_getting_signal_level(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(NULL, MSG_ID_MEDIA_FMR_GET_SIGNAL_LEVEL_CNF);
    mdi_fmr_get_signal_level_hdlr = NULL;
}
#endif /* FM_RADIO_HW_SEARCH */


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_evaluate_threshold
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_evaluate_threshold(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    if (mdi_audio_state != MDI_AUDIO_IDLE)
    {
        media_aud_fmr_evaluate_threshold(MOD_MMI);
    }
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_set_channel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_set_channel(MMI_BOOL is_mono)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_aud_fmr_set_channel(MOD_MMI, is_mono);
}
/* FM Radio End */

/* FM Radio Record Begin */
#ifdef FM_RADIO_RECORD
/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_start_record
 * DESCRIPTION
 *  This function is to start record for FM radio
 * PARAMETERS
 *  file_name       [?]         
 *  format          [IN]        
 *  handle_p        [?]         
 *  handler         [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_fmr_start_record(void *file_name, U8 format, U8 quality, mdi_handle *handle_p, mdi_callback handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MTK_TARGET__)
    mdi_result result;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_FMR_START_RECORD, mdi_audio_state, mdi_audio_mode);

    if (!mdi_check_device_ownership())
    {
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_BLOCKED;
    }
    else if (mdi_audio_state == MDI_AUDIO_RECORD || mdi_audio_state == MDI_AUDIO_RECORD_PAUSED)
    {
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_BUSY;
    }
#ifdef __MMI_BT_FM_VIA_SCO__
    else if(mdi_audio_bt_cntx.state[BT_HFP] != MDI_AUDIO_BT_STATE_IDLE) /* Can not record while BT SCO is open */
    {
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_HFP_SCO_CONNECTED;
    }
#endif /* __MMI_BT_FM_VIA_SCO__ */
    else
    {
    #ifdef __DRM_SUPPORT__
        if(mdi_audio_drm_id >= 0)
        {
            DRM_stop_consume(mdi_audio_drm_id);
            mdi_audio_drm_id = -1;
        }
    #endif /*__DRM_SUPPORT__*/

        /*
         * set pseudo play file callback to NULL before callback
         * bcoz we could set another callback during callback
         */
        if (pseudo_play_file_callback)
        {
            mdi_callback old_pseudo_play_file_callback = pseudo_play_file_callback;
            pseudo_play_file_callback = NULL;
            old_pseudo_play_file_callback(MDI_AUDIO_TERMINATED);
        }
        if (currentHandler && (mdi_audio_state == MDI_AUDIO_PLAY 
            || mdi_audio_state == MDI_AUDIO_PLAY_PAUSED
#if defined(DIGIT_TONE_SUPPORT) || defined(SIMPLE_TTS)
            || mdi_audio_play_text_context.state == MDI_AUDIO_PLAY_TEXT_WAIT_STATE
#endif 
        ))
        {
            /* Don't turn off FM radio */
            if (!(mdi_audio_state == MDI_AUDIO_PLAY && mdi_audio_mode == MDI_AUDIO_PLAY_FM_RADIO))
            {
                currentHandler(MDI_AUDIO_TERMINATED);
            }
        }
    }

    /* Must turn on FM radio first */
    if (!(mdi_audio_state == MDI_AUDIO_PLAY && mdi_audio_mode == MDI_AUDIO_PLAY_FM_RADIO))
    {
        MDI_AUDIO_UNLOCK;    
        return MDI_AUDIO_FAIL;
    }

    mdi_audio_stop_background_timer();

#if defined(__MTK_TARGET__)

    if ((result = media_aud_start_record(MOD_MMI, (kal_wchar*) file_name, format, quality, FALSE, MDI_INPUT_FMRR, 0, 0)) == MED_RES_OK)
    {
        currentHandler = handler;
        mdi_audio_state = MDI_AUDIO_RECORD;
        mdi_audio_mode = MDI_AUDIO_RECORD_FM_RADIO;
        SetProtocolEventHandler(mdi_fmr_record_finish_ind, MSG_ID_L4AUD_MEDIA_RECORD_FINISH_IND);
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        //currentHandler=NULL;
        //mdi_audio_state=MDI_AUDIO_IDLE;
        //mdi_audio_start_background_timer();
        MDI_AUDIO_UNLOCK;
        return mdi_audio_get_event((U8) result);
    }
#else /* defined(__MTK_TARGET__) */ 
    currentHandler = handler;
    mdi_audio_state = MDI_AUDIO_RECORD;
    mdi_audio_mode = MDI_AUDIO_RECORD_FM_RADIO;
    MDI_AUDIO_UNLOCK;
    return MDI_AUDIO_SUCCESS;
#endif /* defined(__MTK_TARGET__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_record_finish_ind
 * DESCRIPTION
 *  This function is the callback function of finish FM radio record
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_record_finish_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_media_record_finish_ind_struct *msg_p = (l4aud_media_record_finish_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_FMR_RECORD_FINISH_IND, mdi_audio_state);
    if (mdi_audio_state == MDI_AUDIO_RECORD)
    {
        /* Go back to FM radio playing state */
        mdi_audio_state = MDI_AUDIO_PLAY;
        mdi_audio_mode = MDI_AUDIO_PLAY_FM_RADIO;

        if (currentHandler)
        {
            previousHandler = currentHandler;
            // currentHandler=NULL; /* Clear at stop FM radio time.*/
            previousHandler(mdi_audio_get_event(msg_p->result));
        }
        /* mdi_audio_start_background_timer(); */
    }
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_fmr_record_only
 * DESCRIPTION
 *  This function is to stop FM recording and call back to MMI.
 *  After calling this function, FM radio will still playing
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_stop_fmr_record_only(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_STOP_FMR_RECORD_ONLY, mdi_audio_state);

    if (!mdi_check_device_ownership())
    {
        MDI_AUDIO_UNLOCK;    
        return MDI_AUDIO_BLOCKED;
    }

    /* Need to chceck is recording before stop it ??? */
    mdi_fmr_stop_record();

    if (currentHandler)
    {
        /* Still keep callback for playing */
        currentHandler(MDI_AUDIO_STOP_FM_RECORD);
    }

    /* mdi_audio_start_background_timer(); */
    MDI_AUDIO_UNLOCK;
    return MDI_AUDIO_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_stop_record
 * DESCRIPTION
 *  This function is to stop FM recording in media task
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result(?)
 *****************************************************************************/
void mdi_fmr_stop_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    if (mdi_audio_state == MDI_AUDIO_IDLE)
    {
        MDI_AUDIO_UNLOCK;    
        return;
    }

    /* Stop FM record */
    SetProtocolEventHandler(NULL, MSG_ID_L4AUD_MEDIA_RECORD_FINISH_IND);
    media_aud_stop_record(MOD_MMI, SRC_LMMI);

    /* Remain in playing state */
    mdi_audio_state = MDI_AUDIO_PLAY;
    mdi_audio_mode = MDI_AUDIO_PLAY_FM_RADIO;

    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_pause_record
 * DESCRIPTION
 *  This function is to pause FM radio record
 * PARAMETERS
 *  handler     [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_fmr_pause_record(mdi_callback handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_FMR_PAUSE_RECORD, mdi_audio_state);
    if (!mdi_check_device_ownership())
    {
        MDI_AUDIO_UNLOCK;    
        return MDI_AUDIO_BLOCKED;
    }

#if defined(__MTK_TARGET__)
    if ((result = media_aud_pause(MOD_MMI, SRC_LMMI)) == MED_RES_OK)
    {
        mdi_audio_state = MDI_AUDIO_RECORD_PAUSED;
        currentHandler = handler;
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        /* currentHandler=NULL; */
        mdi_audio_state = MDI_AUDIO_PLAY;
        mdi_audio_mode = MDI_AUDIO_PLAY_FM_RADIO;
        /* mdi_audio_start_background_timer(); */
        MDI_AUDIO_UNLOCK;
        return mdi_audio_get_event((U8) result);
    }
#else /* defined(__MTK_TARGET__) */ 
    result = MDI_AUDIO_SUCCESS;
    mdi_audio_state = MDI_AUDIO_RECORD_PAUSED;
    currentHandler = handler;
    MDI_AUDIO_UNLOCK;
    return result;
#endif /* defined(__MTK_TARGET__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_frm_resume_record
 * DESCRIPTION
 *  This function is to resume FM radio record
 * PARAMETERS
 *  handler     [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_frm_resume_record(mdi_callback handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_FMR_RESUME_RECORD, mdi_audio_state);
    if (!mdi_check_device_ownership())
    {
        MDI_AUDIO_UNLOCK;    
        return MDI_AUDIO_BLOCKED;
    }

#if defined(__MTK_TARGET__)
    if ((result = media_aud_resume(MOD_MMI, SRC_LMMI)) == MED_RES_OK)
    {
        mdi_audio_state = MDI_AUDIO_RECORD;
        mdi_audio_mode = MDI_AUDIO_RECORD_FM_RADIO;
        currentHandler = handler;
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        currentHandler = NULL;
        mdi_audio_state = MDI_AUDIO_PLAY;
        mdi_audio_mode = MDI_AUDIO_PLAY_FM_RADIO;
        /* mdi_audio_start_background_timer(); */
        MDI_AUDIO_UNLOCK;
        return mdi_audio_get_event((U8) result);
    }
#else /* defined(__MTK_TARGET__) */ 
    result = MDI_AUDIO_SUCCESS;
    mdi_audio_state = MDI_AUDIO_RECORD;
    mdi_audio_mode = MDI_AUDIO_RECORD_FM_RADIO;
    currentHandler = handler;
    MDI_AUDIO_UNLOCK;
    return result;
#endif /* defined(__MTK_TARGET__) */ 
}

#endif /* FM Record Enable */
/* FM Radio Record END */

#ifdef VR_ENABLE


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_voice_tag
 * DESCRIPTION
 *  This function is to play vr voice tag
 * PARAMETERS
 *  mode            [IN]        
 *  lang            [IN]        
 *  group_id        [IN]        
 *  word_id         [IN]        
 *  handle_p        [?]         
 *  handler         [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_play_voice_tag(
            U8 mode,
            U8 lang,
            U8 group_id,
            U16 word_id,
            mdi_handle *handle_p,
            mdi_callback handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_PLAY_VOICE_TAG, mode, lang, group_id, word_id, mdi_audio_state);

    if (!mdi_audio_check_states_and_handlers(&result))
    {
        MDI_AUDIO_UNLOCK;    
        return result;
    }

    ++identifier;
    mdi_audio_stop_background_timer();

    if ((result = media_aud_vr_play_tag(MOD_MMI, mode, lang, group_id, word_id, identifier)) == MED_RES_OK)
    {
        currentHandler = handler;
        mdi_audio_state = MDI_AUDIO_PLAY;
        mdi_audio_mode = MDI_AUDIO_PLAY_FILE;
        SetProtocolEventHandler(mdi_audio_play_finish_ind1, MSG_ID_L4AUD_MEDIA_PLAY_FINISH_IND);
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        currentHandler = NULL;
        mdi_audio_state = MDI_AUDIO_IDLE;
        mdi_audio_start_background_timer();
        MDI_AUDIO_UNLOCK;
        return mdi_audio_get_event((U8) result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vr_rcg_result_ind
 * DESCRIPTION
 *  This function is to handle vr recognition result indication
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_vr_rcg_result_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vr_rcg_result_ind_struct *msg_p = (media_vr_rcg_result_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VR_RCG_RESULT_IND, msg_p->result, mdi_audio_state);
    if (mdi_audio_state == MDI_AUDIO_RECORD)
    {
        mdi_audio_state = MDI_AUDIO_IDLE;
        if (currentHandler)
        {
            previousHandler = currentHandler;
            currentHandler = NULL;
            mdi_audio_vr_rcg_result_msg = msg_p;
            previousHandler(mdi_audio_get_event(msg_p->result));
            mdi_audio_vr_rcg_result_msg = NULL;
        }
        mdi_audio_start_background_timer();
    }
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vr_trn_result_ind
 * DESCRIPTION
 *  This function is to handle vr training result indication
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_vr_trn_result_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vr_trn_result_ind_struct *msg_p = (media_vr_trn_result_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VR_TRN_RESULT_IND, msg_p->result, mdi_audio_state);
    if (mdi_audio_state == MDI_AUDIO_RECORD)
    {
        mdi_audio_state = MDI_AUDIO_IDLE;
        if (currentHandler)
        {
            previousHandler = currentHandler;
            currentHandler = NULL;
            mdi_audio_vr_trn_result_msg = msg_p;
            previousHandler(mdi_audio_get_event(msg_p->result));
            mdi_audio_vr_trn_result_msg = NULL;
        }
        mdi_audio_start_background_timer();
    }
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vr_rcg_session_id
 * DESCRIPTION
 *  This function is to get vr rcg session id
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U32 mdi_audio_vr_rcg_session_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_audio_vr_rcg_result_msg != NULL)
    {
        return mdi_audio_vr_rcg_result_msg->session_id;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vr_trn_session_id
 * DESCRIPTION
 *  This function is to get vr trn session id
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U32 mdi_audio_vr_trn_session_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_audio_vr_trn_result_msg != NULL)
    {
        return mdi_audio_vr_trn_result_msg->session_id;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vr_rcg_result_id_length
 * DESCRIPTION
 *  This function is to get vr rcg result id length
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mdi_audio_vr_rcg_result_id_length(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_audio_vr_rcg_result_msg != NULL)
    {
        return mdi_audio_vr_rcg_result_msg->id_length;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vr_rcg_result_id_array
 * DESCRIPTION
 *  This function is to get vr rcg result id array
 * PARAMETERS
 *  void
 * RETURNS
 *  U16*
 *****************************************************************************/
U16 *mdi_audio_vr_rcg_result_id_array(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_audio_vr_rcg_result_msg != NULL)
    {
        return mdi_audio_vr_rcg_result_msg->id_array;
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_start_vr_voice_record
 * DESCRIPTION
 *  This function is to start vr voice record
 * PARAMETERS
 *  session_id      [IN]        
 *  seq_no          [IN]        
 *  handle_p        [?]         
 *  handler         [IN]        
 *  U8 mode(?)
 *  U8 lang(?)
 *  U8 group_id(?)
 *  U16 word_id(?)
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_start_vr_voice_record(U32 session_id, U8 seq_no, mdi_handle *handle_p, mdi_callback handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_START_VR_VOICE_RECORD, session_id, seq_no, mdi_audio_state);

    if (!mdi_audio_check_states_and_handlers(&result))
    {
        MDI_AUDIO_UNLOCK;    
        return result;
    }

    mdi_audio_stop_background_timer();

    if ((result = media_aud_vr_voice_in(MOD_MMI, session_id, seq_no)) == MED_RES_OK)
    {
        currentHandler = handler;
        mdi_audio_state = MDI_AUDIO_RECORD;
        mdi_audio_mode = MDI_AUDIO_RECORD_VR_VOICE;
        SetProtocolEventHandler(mdi_audio_vr_rcg_result_ind, MSG_ID_MEDIA_VR_RCG_RESULT_IND);
        SetProtocolEventHandler(mdi_audio_vr_trn_result_ind, MSG_ID_MEDIA_VR_TRN_RESULT_IND);
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        currentHandler = NULL;
        mdi_audio_state = MDI_AUDIO_IDLE;
        mdi_audio_start_background_timer();
        MDI_AUDIO_UNLOCK;
        return mdi_audio_get_event((U8) result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_vr_voice_record
 * DESCRIPTION
 *  This function is to stop vr voice record.
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_stop_vr_voice_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_STOP_VR_VOICE_RECORD, mdi_audio_state);
    media_aud_vr_abort(MOD_MMI);

    if (!mdi_check_device_ownership())
    {
        MDI_AUDIO_UNLOCK;    
        return MDI_AUDIO_BLOCKED;
    }

    SetProtocolEventHandler(NULL, MSG_ID_MEDIA_VR_RCG_RESULT_IND);
    SetProtocolEventHandler(NULL, MSG_ID_MEDIA_VR_TRN_RESULT_IND);

    mdi_audio_state = MDI_AUDIO_IDLE;
    if (currentHandler)
    {
        previousHandler = currentHandler;
        currentHandler = NULL;
        previousHandler(MDI_AUDIO_TERMINATED);
    }
    mdi_audio_start_background_timer();

    MDI_AUDIO_UNLOCK;
    return MDI_AUDIO_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vr_abort
 * DESCRIPTION
 *  This function is to abort vr.
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result(?)
 *****************************************************************************/
void mdi_audio_vr_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    if (mdi_audio_state == MDI_AUDIO_RECORD && mdi_audio_mode == MDI_AUDIO_RECORD_VR_VOICE)
    {
        mdi_audio_stop_vr_voice_record();
    }
    else
    {
        media_aud_vr_abort(MOD_MMI);
    }
    MDI_AUDIO_UNLOCK;
}

#endif /* VR_ENABLE */ 

#ifdef VRSI_ENABLE


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vrsi_trn_prompt_req_hdlr
 * DESCRIPTION
 *  This function is to inform MMI to prompt user training stage.
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_vrsi_trn_prompt_req_hdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vrsi_trn_prompt_req_struct *msg_p = (media_vrsi_trn_prompt_req_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VRSI_TRN_PROMPT_REQ_HDLR, mdi_audio_state);

    switch (msg_p->pmp_mode)
    {
        case MED_VRSI_1ST_TRN_PROMPT:
            vrsiHandler(MED_VRSI_TRAIN_TAG_1ST_MPR);
            break;
        case MED_VRSI_2ND_TRN_PROMPT:
            vrsiHandler(MED_VRSI_TRAIN_TAG_2ND_MPR);
            break;
        case MED_VRSI_1ST_DGT_ADP_PROMPT:
        case MED_VRSI_2ND_DGT_ADP_PROMPT:
            vrsiHandler(MED_VRSI_DIGIT_ADAPT_MPR);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vrsi_trn_result_ind
 * DESCRIPTION
 *  This function is to inform MMI train result.
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_vrsi_trn_result_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vrsi_trn_result_ind_struct *msg_p = (media_vrsi_trn_result_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VRSI_TRN_RESULT_IND, mdi_audio_state);

    if (msg_p->tag_id == 0)
    {
        vrsiHandler(MED_VRSI_DIGIT_ADAPT_OK);
    }
    else
    {
        vrsiHandler(MED_VRSI_TRAIN_TAG_OK);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vrsi_rcg_prompt_req_hdlr
 * DESCRIPTION
 *  This function is to inform MMI to prompt user recognition stage.
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_vrsi_rcg_prompt_req_hdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vrsi_rcg_prompt_req_struct *msg_p = (media_vrsi_rcg_prompt_req_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VRSI_RCG_PROMPT_REQ_HDLR, mdi_audio_state);

    switch (msg_p->pmp_mode)
    {
        case MED_VRSI_CMD_RCG_PROMPT:
            vrsiHandler(MED_VRSI_RECOG_MPR);
            break;
        case MED_VRSI_DGT_RCG_PROMPT:
            vrsiHandler(MED_VRSI_DIGIT_RECOG_MPR);
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vrsi_rcg_result_ind
 * DESCRIPTION
 *  This function is to inform MMI recognition result.
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_vrsi_rcg_result_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vrsi_rcg_result_ind_struct *msg_p = (media_vrsi_rcg_result_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VRSI_RCG_RESULT_IND, mdi_audio_state);

    if (msg_p->res_type == 0)
    {
        vrsiHandler(MED_VRSI_DIGIT_RECOG_OK);
    }
    else
    {
        vrsiHandler(MED_VRSI_RECOG_OK);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vrsi_err_ind
 * DESCRIPTION
 *  This function is the error indication.
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_vrsi_err_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* media_vrsi_err_ind_struct* msg_p=(media_vrsi_err_ind_struct*)inMsg; */

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VRSI_ERR_IND, mdi_audio_state);

    vrsiHandler(MED_VRSI_ERROR);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vrsi_init
 * DESCRIPTION
 *  This function is to init vrsi engine.
 * PARAMETERS
 *  handler     [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_vrsi_init(mdi_callback handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VRSI_INIT);

    if ((result = media_aud_vrsi_init(MOD_MMI)) == MED_RES_OK)
    {
        vrsiHandler = handler;
        SetProtocolEventHandler(mdi_audio_vrsi_trn_prompt_req_hdlr, MSG_ID_MEDIA_VRSI_TRN_PROMPT_REQ);
        SetProtocolEventHandler(mdi_audio_vrsi_trn_result_ind, MSG_ID_MEDIA_VRSI_TRN_RESULT_IND);
        SetProtocolEventHandler(mdi_audio_vrsi_rcg_prompt_req_hdlr, MSG_ID_MEDIA_VRSI_RCG_PROMPT_REQ);
        SetProtocolEventHandler(mdi_audio_vrsi_rcg_result_ind, MSG_ID_MEDIA_VRSI_RCG_RESULT_IND);
        SetProtocolEventHandler(mdi_audio_vrsi_err_ind, MSG_ID_MEDIA_VRSI_ERR_IND);
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        mdi_audio_state = MDI_AUDIO_IDLE;
        mdi_audio_start_background_timer();
        MDI_AUDIO_UNLOCK;
        return mdi_audio_get_event((U8) result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vrsi_new_session_id
 * DESCRIPTION
 *  This function is to get a new session id.
 * PARAMETERS
 *  void
 * RETURNS
 *  U32
 *****************************************************************************/
U32 mdi_audio_vrsi_new_session_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return media_aud_vrsi_new_session_id();
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vrsi_stop
 * DESCRIPTION
 *  This function is to stop a vrsi action.
 * PARAMETERS
 *  session_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_vrsi_stop(U32 session_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VRSI_STOP, session_id, mdi_audio_state);
    media_aud_vrsi_abort(MOD_MMI, session_id);
    if (mdi_audio_state == MDI_AUDIO_VRSI_PROCESS)
    {
        mdi_audio_state = MDI_AUDIO_IDLE;
    }
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vrsi_close
 * DESCRIPTION
 *  This function is to close vrsi engine.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_vrsi_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VRSI_CLOSE, mdi_audio_state);
    media_aud_vrsi_close(MOD_MMI);
    if (mdi_audio_state == MDI_AUDIO_VRSI_PROCESS)
    {
        mdi_audio_state = MDI_AUDIO_IDLE;
    }
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vrsi_play_tag_finish_ind
 * DESCRIPTION
 *  This function is the play tag finish indication.
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_vrsi_play_tag_finish_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vrsi_play_tag_finish_ind_struct *msg_p = (media_vrsi_play_tag_finish_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VRSI_PLAY_TAG_FINISH_IND, mdi_audio_state);
    if ((mdi_audio_state == MDI_AUDIO_VRSI_PROCESS && mdi_audio_mode == MDI_AUDIO_VRSI_PLAY_TAG)
        && msg_p->session_id == identifier)
    {
        mdi_audio_state = MDI_AUDIO_IDLE;
        vrsiHandler(MED_VRSI_PLAY_TAG_OK);
        mdi_audio_start_background_timer();
    }
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vrsi_play_tag
 * DESCRIPTION
 *  This function is to play vrsi pre-record tag.
 * PARAMETERS
 *  session_id      [IN]        
 *  grammar         [?]         
 *  tag_id          [IN]        
 *  volume          [IN]        
 *  output_path     [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_vrsi_play_tag(U32 session_id, U8 *grammar, U16 tag_id, U8 volume, U8 output_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VRSI_PLAY_TAG, session_id, tag_id, mdi_audio_state);

    if (!mdi_audio_check_states_and_handlers(&result))
    {
        MDI_AUDIO_UNLOCK;    
        return result;
    }

    identifier = session_id;
    mdi_audio_stop_background_timer();

    if ((result = media_aud_vrsi_play_tag(MOD_MMI, session_id, grammar, tag_id, volume, output_path)) == MED_RES_OK)
    {
        mdi_audio_state = MDI_AUDIO_VRSI_PROCESS;
        mdi_audio_mode = MDI_AUDIO_VRSI_PLAY_TAG;
        SetProtocolEventHandler(mdi_audio_vrsi_play_tag_finish_ind, MSG_ID_MEDIA_VRSI_PLAY_TAG_FINISH_IND);
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        mdi_audio_state = MDI_AUDIO_IDLE;
        mdi_audio_start_background_timer();
        MDI_AUDIO_UNLOCK;
        return mdi_audio_get_event((U8) result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vrsi_play_tts_finish_ind
 * DESCRIPTION
 *  This function is the play TTS finish indication.
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_vrsi_play_tts_finish_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vrsi_play_tts_finish_ind_struct *msg_p = (media_vrsi_play_tts_finish_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VRSI_PLAY_TTS_FINISH_IND, mdi_audio_state);
    if ((mdi_audio_state == MDI_AUDIO_VRSI_PROCESS && mdi_audio_mode == MDI_AUDIO_VRSI_PLAY_TTS)
        && msg_p->session_id == identifier)
    {
        mdi_audio_state = MDI_AUDIO_IDLE;
        vrsiHandler(MED_VRSI_TTS_OK);
        mdi_audio_start_background_timer();
    }
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vrsi_play_TTS
 * DESCRIPTION
 *  This function is to play vrsi TTS.
 * PARAMETERS
 *  session_id      [IN]        
 *  text            [?]         
 *  volume          [IN]        
 *  output_path     [IN]        
 *  lang            [IN]        
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_vrsi_play_TTS(U32 session_id, U16 *text, U8 volume, U8 output_path, U8 lang)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VRSI_PLAY_TTS, session_id, mdi_audio_state);

    if (!mdi_audio_check_states_and_handlers(&result))
    {
        MDI_AUDIO_UNLOCK;    
        return result;
    }

    identifier = session_id;
    mdi_audio_stop_background_timer();

    if ((result = media_aud_vrsi_play_TTS(MOD_MMI, session_id, text, volume, output_path, lang)) == MED_RES_OK)
    {
        mdi_audio_state = MDI_AUDIO_VRSI_PROCESS;
        mdi_audio_mode = MDI_AUDIO_VRSI_PLAY_TTS;
        SetProtocolEventHandler(mdi_audio_vrsi_play_tts_finish_ind, MSG_ID_MEDIA_VRSI_PLAY_TTS_FINISH_IND);
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        mdi_audio_state = MDI_AUDIO_IDLE;
        mdi_audio_start_background_timer();
        MDI_AUDIO_UNLOCK;
        return mdi_audio_get_event((U8) result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vrsi_register_record
 * DESCRIPTION
 *  This function is to change vrsi state to record state.
 *  Note: the function is called by L1Audio task, shall modify it!!
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_vrsi_register_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Do not add LOCK here or it will dead lock due to this function called by L1audio task */
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VRSI_REGISTER_RECORD, mdi_audio_state);
    mdi_audio_state = MDI_AUDIO_VRSI_PROCESS;
    mdi_audio_mode = MDI_AUDIO_VRSI_RECORD;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_vrsi_unregister_record
 * DESCRIPTION
 *  This function is to change vrsi state to idle state.
 *  Note: the function is called by L1Audio task, shall modify it!!
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_vrsi_unregister_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Do not add LOCK here or it will dead lock due to this function called by L1audio task */
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_VRSI_UNREGISTER_RECORD, mdi_audio_state);
    mdi_audio_state = MDI_AUDIO_IDLE;
    mdi_audio_mode = MDI_AUDIO_VRSI_RECORD;
}

#endif /* VRSI_ENABLE */ 

#ifdef __MMI_POC__


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_poc_start_encode
 * DESCRIPTION
 *  start poc encode
 * PARAMETERS
 *  handler     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mdi_result mdi_audio_poc_start_encode(mdi_callback handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_POC_START_ENCODE, mdi_audio_state, mdi_audio_mode);

    if (!mdi_check_device_ownership())
    {
        MDI_AUDIO_UNLOCK;    
        return MDI_AUDIO_BLOCKED;
    }

    if (mdi_audio_state != MDI_AUDIO_IDLE)
    {
        mdi_audio_stop_all();
    }

    /* Send Message */
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_POC;
    Message.oslMsgId = PRT_POC_MEDIA_START_ENCODE_REQ;
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

    POC_WAIT_EVENT(POC_EVT_START_ENCODE);

    if (poc_result_g == POC_OK)
    {
        currentHandler = handler;
        mdi_audio_state = MDI_AUDIO_POC_ON;
        mdi_audio_mode = MDI_AUDIO_POC_ENCODE;
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_FAIL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_poc_stop_encode
 * DESCRIPTION
 *  stop poc encoding
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mdi_result mdi_audio_poc_stop_encode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_POC_STOP_ENCODE, mdi_audio_state, mdi_audio_mode);

    if (!mdi_check_device_ownership())
    {
        MDI_AUDIO_UNLOCK;    
        return MDI_AUDIO_BLOCKED;
    }

    if (!((mdi_audio_state == MDI_AUDIO_POC_ON) && (mdi_audio_mode == MDI_AUDIO_POC_ENCODE)))
    {
        MDI_AUDIO_UNLOCK;    
        return MDI_AUDIO_SUCCESS;
    }

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_POC;
    Message.oslMsgId = PRT_POC_MEDIA_STOP_ENCODE_REQ;
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

    POC_WAIT_EVENT(POC_EVT_STOP_ENCODE);

    mdi_audio_state = MDI_AUDIO_IDLE;
    if (currentHandler)
    {
        previousHandler = currentHandler;
        currentHandler = NULL;
        previousHandler(MDI_AUDIO_TERMINATED);
    }

    mdi_audio_start_background_timer();

    MDI_AUDIO_UNLOCK;
    return MDI_AUDIO_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_poc_start_decode
 * DESCRIPTION
 *  start poc decode
 * PARAMETERS
 *  handler     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mdi_result mdi_audio_poc_start_decode(mdi_callback handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_POC_START_DECODE, mdi_audio_state, mdi_audio_mode);

    if (!mdi_check_device_ownership())
    {
        MDI_AUDIO_UNLOCK;    
        return MDI_AUDIO_BLOCKED;
    }

    if (mdi_audio_state != MDI_AUDIO_IDLE)
    {
        mdi_audio_stop_all();
    }

    /* Send Message */
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_POC;
    Message.oslMsgId = PRT_POC_MEDIA_START_DECODE_REQ;
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

    POC_WAIT_EVENT(POC_EVT_START_DECODE);

    if (poc_result_g == POC_OK)
    {
        currentHandler = handler;
        mdi_audio_state = MDI_AUDIO_POC_ON;
        mdi_audio_mode = MDI_AUDIO_POC_DECODE;
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        MDI_AUDIO_UNLOCK;    
        return MDI_AUDIO_FAIL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_poc_stop_decode
 * DESCRIPTION
 *  stop poc decode
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mdi_result mdi_audio_poc_stop_decode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_POC_STOP_DECODE, mdi_audio_state, mdi_audio_mode);

    if (!mdi_check_device_ownership())
    {
        MDI_AUDIO_UNLOCK;    
        return MDI_AUDIO_BLOCKED;
    }

    if (!((mdi_audio_state == MDI_AUDIO_POC_ON) && (mdi_audio_mode == MDI_AUDIO_POC_DECODE)))
    {
        MDI_AUDIO_UNLOCK;    
        return MDI_AUDIO_SUCCESS;
    }

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_POC;
    Message.oslMsgId = PRT_POC_MEDIA_STOP_DECODE_REQ;
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

    POC_WAIT_EVENT(POC_EVT_STOP_DECODE);

    mdi_audio_state = MDI_AUDIO_IDLE;
    if (currentHandler)
    {
        previousHandler = currentHandler;
        currentHandler = NULL;
        previousHandler(MDI_AUDIO_TERMINATED);
    }

    mdi_audio_start_background_timer();

    MDI_AUDIO_UNLOCK;
    return MDI_AUDIO_SUCCESS;
}

#endif /* __MMI_POC__ */ 

#if defined(BGSND_ENABLE)
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_snd_is_idle
 * DESCRIPTION
 *  This function is to check if the background sound playing
 * PARAMETERS
 *
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mdi_audio_snd_is_idle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_idle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    is_idle = (snd_audio_state == MDI_AUDIO_IDLE);
    MDI_AUDIO_UNLOCK;
    return is_idle;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_snd_check_string_format
 * DESCRIPTION
 *  This function is to check if the audio string resource fit the background sound format
 * PARAMETERS
 *  audio_data      [?]         audio resource data pointer
 *  len             [IN]        audio resource data length
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_snd_check_string_format(void *audio_data, U32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = media_aud_snd_check_byte_stream_format(MOD_MMI, (kal_uint8*) audio_data, len);
    return mdi_audio_get_event((U8) result);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_snd_check_file_format
 * DESCRIPTION
 *  This function is to check if the external file fit the background sound format
 * PARAMETERS
 *  file_name       [?]     external file path
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_snd_check_file_format(void *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = media_aud_snd_check_file_format(MOD_MMI, (kal_wchar*) file_name);
    return mdi_audio_get_event((U8) result);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_snd_play_string_with_vol_path
 * DESCRIPTION
 *  This function is to play audio string with volume and path
 * PARAMETERS
 *  audio_data      [?]         audio data pointer
 *  len             [IN]        audio data length
 *  repeat          [IN]        repeat times. (0: infinite)
 *  handle_p        [?]         reserved
 *  handler         [IN]        play finish callback function
 *  volume          [IN]        output volume
 *  path            [IN]        output path
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_snd_play_string_with_vol_path(
            void *audio_data,
            U32 len,
            U16 repeat,
            mdi_handle *handle_p,
            mdi_callback handler,
            U8 volume,
            U8 path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SND_PLAY_STRING_WITH_VOL_PATH, snd_audio_state);

    if (snd_audio_state != MDI_AUDIO_IDLE)
    {
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_BUSY;
    }

    if ((result = media_aud_snd_play_byte_stream(
                    MOD_MMI,
                    (kal_uint8*) audio_data,
                    len,
                    repeat,
                    volume,
                    path)) == MED_RES_OK)
    {
        snd_currentHandler = handler;
        snd_audio_state = MDI_AUDIO_PLAY;
        SetProtocolEventHandler(mdi_audio_snd_play_finish_ind, MSG_ID_MEDIA_SND_PLAY_FINISH_IND);
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        snd_currentHandler = NULL;
        snd_audio_state = MDI_AUDIO_IDLE;
        MDI_AUDIO_UNLOCK;
        return mdi_audio_get_event((U8) result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_snd_play_file_with_vol_path
 * DESCRIPTION
 *  This function is to play external file with volume and path
 * PARAMETERS
 *  file_name       [?]         external file
 *  repeat          [IN]        repeat times. (0: infinite)
 *  handle_p        [?]         reserved
 *  handler         [IN]        play finish callback function
 *  volume          [IN]        output volume
 *  path            [IN]        output path
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_snd_play_file_with_vol_path(
            void *file_name,
            U16 repeat,
            mdi_handle *handle_p,
            mdi_callback handler,
            U8 volume,
            U8 path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SND_PLAY_FILE_WITH_VOL_PATH, snd_audio_state);

    if (snd_audio_state != MDI_AUDIO_IDLE)
    {
        MDI_AUDIO_UNLOCK;    
        return MDI_AUDIO_BUSY;
    }

    if ((result = media_aud_snd_play_file(MOD_MMI, (kal_wchar*) file_name, repeat, volume, path)) == MED_RES_OK)
    {
        snd_currentHandler = handler;
        snd_audio_state = MDI_AUDIO_PLAY;
        SetProtocolEventHandler(mdi_audio_snd_play_finish_ind, MSG_ID_MEDIA_SND_PLAY_FINISH_IND);
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        snd_currentHandler = NULL;
        snd_audio_state = MDI_AUDIO_IDLE;
        MDI_AUDIO_UNLOCK;
        return mdi_audio_get_event((U8) result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_snd_play_finish_ind
 * DESCRIPTION
 *  This function is the callback funtion when play finish
 * PARAMETERS
 *  inMsg       [?]     result indication message
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_snd_play_finish_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_snd_play_finish_ind_struct *msg_p = (media_snd_play_finish_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SND_PLAY_FINISH_IND, snd_audio_state);

    if (snd_audio_state == MDI_AUDIO_PLAY)
    {
        snd_audio_state = MDI_AUDIO_IDLE;
        if (snd_currentHandler)
        {
            snd_prevHandler = snd_currentHandler;
            snd_currentHandler = NULL;
            snd_prevHandler(mdi_audio_get_event(msg_p->result));        /* mdi_audio_play_text handler could set currentHandler to itself here */
        }
    }
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_snd_stop
 * DESCRIPTION
 *  This function is stop background sound play
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_snd_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SND_STOP, snd_audio_state);

    if (snd_audio_state == MDI_AUDIO_IDLE)
    {
        MDI_AUDIO_UNLOCK;    
        return MDI_AUDIO_SUCCESS;
    }

    ClearProtocolEventHandler(MSG_ID_MEDIA_SND_PLAY_FINISH_IND);
    media_aud_snd_stop_play(MOD_MMI);

    if (snd_currentHandler)
    {
        snd_prevHandler = snd_currentHandler;
        snd_currentHandler = NULL;
        snd_prevHandler(MDI_AUDIO_TERMINATED);
    }

    snd_audio_state = MDI_AUDIO_IDLE;

    MDI_AUDIO_UNLOCK;
    return MDI_AUDIO_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_snd_set_volume
 * DESCRIPTION
 *  This function is to change the volume of background play
 * PARAMETERS
 *  volume      [IN]        volume level (0~100, 0: mute)
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_snd_set_volume(U8 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    if (snd_audio_state != MDI_AUDIO_IDLE)
    {
        return MDI_AUDIO_FAIL;
    }

    /* Range is 0~100 */
    if (volume > 100)
    {
        volume = 100;
    }

    media_aud_snd_set_volume(MOD_MMI, volume);

    MDI_AUDIO_UNLOCK;
    return MDI_AUDIO_SUCCESS;
}

#endif /* defined(BGSND_ENABLE) */ 


#if defined(AUD_TIME_STRETCH)
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stretch_check_string_format
 * DESCRIPTION
 *  This function is to check if the audio data spported in time stretch
 * PARAMETERS
 *  audio_data      [?]         audio data pointer
 *  len             [IN]        audio data length
 *  format          [IN]        audio data fomrat
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_stretch_check_string_format(void *audio_data, U32 len, U16 format)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = media_stretch_check_stream_format(MOD_MMI, (kal_uint8*) audio_data, len, format);
    return mdi_audio_get_event((U8) result);

#else /* __MTK_TARGET__ */ 
    return MDI_AUDIO_SUCCESS;
#endif /* __MTK_TARGET__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stretch_check_file_format
 * DESCRIPTION
 *  This function is to check if the audio file spported in time stretch
 * PARAMETERS
 *  file_name       [?]     file name pointer
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_stretch_check_file_format(void *file_name)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = media_stretch_check_file_format(MOD_MMI, (kal_wchar*) file_name);
    return mdi_audio_get_event((U8) result);

#else /* __MTK_TARGET__ */ 
    return MDI_AUDIO_SUCCESS;
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stretch_set_speed
 * DESCRIPTION
 *  This function is to set audio time stretch speed
 * PARAMETERS
 *  speed       [IN]        Time stretch speed
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_stretch_set_speed(U16 speed)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_STRETCH_SET_SPEED, speed, mdi_aud_stretch_on);

    /* Set time stretch only when speed is not normal */
    if (speed != MDI_AUDIO_SPEED_NORMAL)
    {
        result = media_stretch_set_speed(MOD_MMI, speed);

        if (result == MDI_AUDIO_SUCCESS)
        {
            mdi_aud_stretch_on = TRUE;
        }
        else
        {
            mdi_aud_stretch_on = FALSE;
        }

        return result;
    }
    else    /* Normal Speed */
    {
        mdi_audio_stretch_close();

        return MDI_AUDIO_SUCCESS;
    }

#else /* __MTK_TARGET__ */ 
    mdi_aud_stretch_on = TRUE;
    return MDI_AUDIO_SUCCESS;
#endif /* __MTK_TARGET__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stretch_close
 * DESCRIPTION
 *  This function is to close audio time stretch
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result(?)
 *****************************************************************************/
void mdi_audio_stretch_close(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_aud_stretch_on)
    {
        media_stretch_close(MOD_MMI);
    }
#endif /* __MTK_TARGET__ */ 

    mdi_aud_stretch_on = FALSE;
}
#endif /* #if defined(AUD_TIME_STRETCH) */


#if defined(AUD_REVERB)
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_reverb_set_coeff
 * DESCRIPTION
 *  This function is to set 3D coefficient
 * PARAMETERS
 *  coeff_table     [?]     3D coefficient table pointer
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_reverb_set_coeff(S16 *coeff_table)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = media_aud_reverb_set_coeff(coeff_table);
    return result;
#else /* __MTK_TARGET__ */ 
    return MDI_AUDIO_SUCCESS;
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_reverb_turn_on
 * DESCRIPTION
 *  This function is to turn on audio 3d effect
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_reverb_turn_on(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = media_aud_reverb_turn_on_effect();
    return result;
#else /* __MTK_TARGET__ */ 
    return MDI_AUDIO_SUCCESS;
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_reverb_turn_off
 * DESCRIPTION
 *  This function is to turn off audio 3d effect
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_reverb_turn_off(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = media_aud_reverb_turn_off_effect();
    return result;
#else /* __MTK_TARGET__ */ 
    return MDI_AUDIO_SUCCESS;
#endif /* __MTK_TARGET__ */ 
}

#endif /* #if defined(AUD_REVERB) */ 

#if defined(AUD_3D_SURROUND_LSPK) || defined(AUD_3D_SURROUND_EARP)
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_surround_turn_on
 * DESCRIPTION
 *  This function is to turn on audio 3d effect
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_surround_turn_on(U8 mode)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = media_aud_surround_turn_on_effect(mode);
    return result;
#else /* __MTK_TARGET__ */ 
    return MDI_AUDIO_SUCCESS;
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_surround_turn_off
 * DESCRIPTION
 *  This function is to turn off audio 3d effect
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_surround_turn_off(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = media_aud_surround_turn_off_effect();
    return result;
#else /* __MTK_TARGET__ */ 
    return MDI_AUDIO_SUCCESS;
#endif /* __MTK_TARGET__ */ 
}
#endif /*#if defined(AUD_3D_SURROUND_LSPK) || defined(AUD_3D_SURROUND_EARP)*/


#if defined(AUDIO_EQUALIZER_ENABLE)
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_eq_set_magnitude
 * DESCRIPTION
 *  This function is to set equalizer magnitude
 * PARAMETERS
 *  magnitude     [?]     magnitude table pointer
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_eq_set_magnitude(S8 *magnitude)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = media_aud_eq_set_magnitude((kal_int8*)magnitude);
    return result;
#else /* __MTK_TARGET__ */ 
    return MDI_AUDIO_SUCCESS;
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_eq_turn_on
 * DESCRIPTION
 *  This function is to turn on equalizer effect
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_eq_turn_on(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = media_aud_eq_turn_on_effect();
    return result;
#else /* __MTK_TARGET__ */ 
    return MDI_AUDIO_SUCCESS;
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_eq_turn_off
 * DESCRIPTION
 *  This function is to turn off equalizer effect
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_eq_turn_off(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = media_aud_eq_turn_off_effect();
    return result;
#else /* __MTK_TARGET__ */ 
    return MDI_AUDIO_SUCCESS;
#endif /* __MTK_TARGET__ */ 
}
#endif /* #if defined(AUDIO_EQUALIZER_ENABLE) */ 


#define speech_interface_begin
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_session_start
 * DESCRIPTION
 *  start speech session (for All apps)
 * PARAMETERS
 *  app_id       [IN]
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_speech_session_start(MDI_AUDIO_SPEECH_APP_ID_ENUM app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SP_SESSION_START, app_id);

    /* Avoid the same session start twice */
    ASSERT(mdi_audio_speech_cntx.app_id != app_id);

    /* Stop GSM/WCDMA speech because it may still on after disconnect signal */
    if(mdi_speech_codec_on)
    {
        mdi_audio_speech_codec_stop();
    }

    /* Switch to new session */
    mdi_audio_speech_cntx.app_id = app_id;

    mdi_audio_stop_all();
    mdi_audio_mma_close_all();
    mdi_audio_state = MDI_AUDIO_IDLE;

    mdi_speech_session_on = TRUE;
    mdi_audio_stop_background_timer();

    MDI_AUDIO_UNLOCK;
    return MDI_AUDIO_SUCCESS; // media_aud_speech_session_start(MOD_MMI, app_id);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_session_stop
 * DESCRIPTION
 *  stop speech session (for All apps)
 * PARAMETERS
 *  app_id       [IN]
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_speech_session_stop(MDI_AUDIO_SPEECH_APP_ID_ENUM app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SP_SESSION_STOP, app_id);

    if (mdi_audio_speech_cntx.app_id == app_id)
    {
        /* Stop GSM/WCDMA speech because it may still on after disconnect signal */
        if(mdi_speech_codec_on)
        {
            mdi_audio_speech_codec_stop();
        }
    
        mdi_audio_speech_cntx.app_id = MDI_AUDIO_SPEECH_APP_ID_NONE;

        mdi_audio_stop_all();
        mdi_audio_mma_close_all();
        mdi_audio_state = MDI_AUDIO_IDLE;

        mdi_speech_session_on = FALSE;
        mdi_audio_start_background_timer();

        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS; //media_aud_speech_session_stop(MOD_MMI, app_id);
    }
    else
    {
        ASSERT(0);
        MDI_AUDIO_UNLOCK;        
        return MDI_AUDIO_FAIL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_get_app_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
MDI_AUDIO_SPEECH_APP_ID_ENUM mdi_audio_speech_get_app_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SP_GET_APP_ID, mdi_audio_speech_cntx.app_id);

    return mdi_audio_speech_cntx.app_id;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_set_app_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
void mdi_audio_speech_set_app_id(MDI_AUDIO_SPEECH_APP_ID_ENUM app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SP_SET_APP_ID, mdi_audio_speech_cntx.app_id);

    mdi_audio_speech_cntx.app_id = app_id;
}


/* for GSM & WCDMA apps */
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_codec_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_speech_codec_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_sp_set_mode_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SP_CODEC_START, mdi_speech_codec_on);

    ASSERT( mdi_audio_speech_cntx.app_id == MDI_AUDIO_SPEECH_APP_ID_GSM ||
            mdi_audio_speech_cntx.app_id == MDI_AUDIO_SPEECH_APP_ID_WCDMA ||
            mdi_audio_speech_cntx.app_id == MDI_AUDIO_SPEECH_APP_ID_3G324M  ||
            mdi_audio_speech_cntx.app_id == MDI_AUDIO_SPEECH_APP_ID_SIM2);
    msg_p = OslConstructDataPtr(sizeof(l4aud_sp_set_mode_req_struct));

    mdi_audio_set_mic_volume();

    mdi_speech_codec_on = MMI_TRUE;
    msg_p->speech_on = KAL_TRUE;

    switch (mdi_audio_speech_cntx.app_id)
    {
        case MDI_AUDIO_SPEECH_APP_ID_GSM:
        case MDI_AUDIO_SPEECH_APP_ID_SIM2:  /* The same to MDI_AUDIO_SPEECH_APP_ID_GSM */
            msg_p->rat_mode = 0;
            break;
        case MDI_AUDIO_SPEECH_APP_ID_WCDMA:
            msg_p->rat_mode = 1;
            break;
        case MDI_AUDIO_SPEECH_APP_ID_3G324M:
            msg_p->rat_mode = 2;
            break;
        default:
            ASSERT(0);
    }

    mdi_send_msg(MSG_ID_L4AUD_SP_SET_MODE_REQ, msg_p, NULL);

#ifdef __MMI_BT_PROFILE__
    mmi_profiles_bt_call_start_callback();
#endif /* __MMI_BT_PROFILE__ */ 

    return MDI_AUDIO_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_codec_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_speech_codec_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4aud_sp_set_mode_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SP_CODEC_STOP, mdi_speech_codec_on);

    ASSERT( mdi_audio_speech_cntx.app_id == MDI_AUDIO_SPEECH_APP_ID_GSM ||
            mdi_audio_speech_cntx.app_id == MDI_AUDIO_SPEECH_APP_ID_WCDMA ||
            mdi_audio_speech_cntx.app_id == MDI_AUDIO_SPEECH_APP_ID_3G324M ||
            mdi_audio_speech_cntx.app_id == MDI_AUDIO_SPEECH_APP_ID_SIM2);

    msg_p = OslConstructDataPtr(sizeof(l4aud_sp_set_mode_req_struct));

    mdi_audio_set_mic_volume();

    mdi_speech_codec_on = MMI_FALSE;
    msg_p->speech_on = KAL_FALSE;

    switch (mdi_audio_speech_cntx.app_id)
    {
        case MDI_AUDIO_SPEECH_APP_ID_GSM:
         case MDI_AUDIO_SPEECH_APP_ID_SIM2: /* The same to MDI_AUDIO_SPEECH_APP_ID_GSM */
            msg_p->rat_mode = 0;
            break;
        case MDI_AUDIO_SPEECH_APP_ID_WCDMA:
            msg_p->rat_mode = 1;
            break;
        case MDI_AUDIO_SPEECH_APP_ID_3G324M:
            msg_p->rat_mode = 2;
            break;
        default:
            ASSERT(0);
    }
 
    mdi_send_msg(MSG_ID_L4AUD_SP_SET_MODE_REQ, msg_p, NULL);

    return MDI_AUDIO_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_encode_start
 * DESCRIPTION
 *  start speech encode process (for VoIP)
 * PARAMETERS
 *  rtp_handle       [IN]
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_speech_encode_start(kal_int8 rtp_handle)
{
#if defined(__MED_RTP_MOD__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SP_ENCODE_START, rtp_handle);

    ASSERT( mdi_audio_speech_cntx.app_id == MDI_AUDIO_SPEECH_APP_ID_VOIP );

    return (mdi_result) voip_encoding_start(rtp_handle);
#else
    return MDI_AUDIO_SUCCESS;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_encode_stop
 * DESCRIPTION
 *  stop speech encode process (for VoIP)
 * PARAMETERS
 *  rtp_handle       [IN]
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_speech_encode_stop(kal_int8 rtp_handle)
{
#if defined(__MED_RTP_MOD__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SP_ENCODE_STOP, rtp_handle);

    ASSERT( mdi_audio_speech_cntx.app_id == MDI_AUDIO_SPEECH_APP_ID_VOIP );

    return (mdi_result) voip_encoding_stop(rtp_handle);
#else
    return MDI_AUDIO_SUCCESS;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_decode_start
 * DESCRIPTION
 *  start speech decode process (for VoIP)
 * PARAMETERS
 *  rtp_handle       [IN]
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_speech_decode_start(kal_int8 rtp_handle)
{
#if defined(__MED_RTP_MOD__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SP_DECODE_START, rtp_handle);

    ASSERT( mdi_audio_speech_cntx.app_id == MDI_AUDIO_SPEECH_APP_ID_VOIP );

    return (mdi_result) voip_decoding_start(rtp_handle);
#else
    return MDI_AUDIO_SUCCESS;
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_decode_stop
 * DESCRIPTION
 *  stop speech decode process (for VoIP)
 * PARAMETERS
 *  rtp_handle       [IN]
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_speech_decode_stop(kal_int8 rtp_handle)
{
#if defined(__MED_RTP_MOD__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SP_DECODE_STOP, rtp_handle);

    ASSERT( mdi_audio_speech_cntx.app_id == MDI_AUDIO_SPEECH_APP_ID_VOIP );

    return (mdi_result) voip_decoding_stop(rtp_handle);
#else
    return MDI_AUDIO_SUCCESS;
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_mixer_add
 * DESCRIPTION
 *  add speech mixer (for VoIP)
 * PARAMETERS
 *  rtp_handle       [IN]
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_speech_mixer_add(kal_int8 rtp_handle)
{
#if defined(__MED_RTP_MOD__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SP_MIXER_ADD, rtp_handle);

    ASSERT( mdi_audio_speech_cntx.app_id == MDI_AUDIO_SPEECH_APP_ID_VOIP );

    return (mdi_result) voip_mixer_add(rtp_handle);
#else
    return MDI_AUDIO_SUCCESS;
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_mixer_remove
 * DESCRIPTION
 *  remove speech mixer (for VoIP)
 * PARAMETERS
 *  rtp_handle       [IN]
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_speech_mixer_remove(kal_int8 rtp_handle)
{
#if defined(__MED_RTP_MOD__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SP_MIXER_REMOVE, rtp_handle);

    ASSERT( mdi_audio_speech_cntx.app_id == MDI_AUDIO_SPEECH_APP_ID_VOIP );

    return (mdi_result) voip_mixer_remove(rtp_handle);
#else
    return MDI_AUDIO_SUCCESS;
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_dtmf_start
 * DESCRIPTION
 *  start speech DTMF tone (for VoIP)
 * PARAMETERS
 *  rtp_handle       [IN]
 *  code             [IN]
 *  type             [IN]
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_speech_dtmf_start(kal_int8 rtp_handle, kal_uint8 code, kal_uint8 type)
{
#if defined(__MED_RTP_MOD__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SP_DTMF_START, rtp_handle,code,type);

    ASSERT( mdi_audio_speech_cntx.app_id == MDI_AUDIO_SPEECH_APP_ID_VOIP );

    return (mdi_result) rtp_send_dtmf_start(rtp_handle, code, type);
#else
    return MDI_AUDIO_SUCCESS;
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_dtmf_stop
 * DESCRIPTION
 *  stop speech DTMF tone (for VoIP)
 * PARAMETERS
 *  rtp_handle       [IN]
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_speech_dtmf_stop(kal_int8 rtp_handle)
{
#if defined(__MED_RTP_MOD__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_SP_DTMF_STOP, rtp_handle);

    ASSERT( mdi_audio_speech_cntx.app_id == MDI_AUDIO_SPEECH_APP_ID_VOIP );

    return (mdi_result) rtp_send_dtmf_stop(rtp_handle);
#else
    return MDI_AUDIO_SUCCESS;
#endif    
}

#define speech_interface_end

#ifdef __GENERAL_TTS__
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_tts_set_attr
 * DESCRIPTION
 *  This function is to set tts play attribute. 
 *  Note: This function need to call immediately before each play request.
 * PARAMETERS
 *  attr_id       [IN]  attribute id
 *  attr_value    [IN]  attribute value
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_tts_set_attr(U32 attr_id, U32 attr_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_TTS_SET_ATTR, mdi_audio_state, attr_id, attr_value);

    result = media_aud_tts_set_attr_req(MOD_MMI, attr_id, attr_value);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_tts_play_update_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  attr_id       [IN]  attribute id
 *  attr_value    [IN]  attribute value
 * RETURNS
 *  mdi_result
 *****************************************************************************/
void mdi_audio_tts_play_update_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //media_aud_tts_update_info_ind_struct *msg_p = (media_aud_tts_update_info_ind_struct*) inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_TTS_PLAY_UPDATE_IND);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_tts_play
 * DESCRIPTION
 *  This function is to request TTS string.
 * PARAMETERS
 *  tts_param       [IN]
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_tts_play(mdi_audio_tts_struct tts_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    aud_tts_struct aud_tts;
    mdi_result result;
#ifdef IFLY_TTS
    kal_wchar debug_print[22];
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_TTS_PLAY, mdi_audio_state);

    /* Print 20 characters for GIS debug in IFLY engine */
#ifdef IFLY_TTS
    kal_wstrncpy(debug_print, tts_param.text_string, 20);
    mmi_wprintf(MOD_MMI_MEDIA_APP, MMI_MEDIA_TRC_G10_MMI_PRINT, debug_print);
#endif

    if (!mdi_audio_check_states_and_handlers(&result))
    {
        MDI_AUDIO_UNLOCK;    
        return result;
    }

    mdi_audio_stop_background_timer();
    ++identifier;

    /* All sound shall go through bluetooth earphone */
#ifdef __MMI_BT_AUDIO_VIA_SCO__
    mmi_profiles_bt_connect_audio_via_sco();
#endif

    aud_tts.text_string = tts_param.text_string;
    aud_tts.str_type = tts_param.str_type;
    aud_tts.lang = tts_param.lang;
    aud_tts.app_type = tts_param.app_type;
    aud_tts.gander = tts_param.gander;
    aud_tts.volume = tts_param.volume;
    aud_tts.path = tts_param.path;
    aud_tts.pitch = tts_param.pitch;
    aud_tts.speed = tts_param.speed;
    aud_tts.identifier = identifier;
    
    if ((result = media_aud_tts_play_req(MOD_MMI, &aud_tts)) == MED_RES_OK)
    {
        currentHandler = tts_param.callback;
        mdi_audio_state = MDI_AUDIO_PLAY;
        mdi_audio_mode = MDI_AUDIO_PLAY_TTS;
        SetProtocolEventHandler(mdi_audio_play_finish_ind1, MSG_ID_L4AUD_MEDIA_PLAY_FINISH_IND);
        SetProtocolEventHandler(mdi_audio_tts_play_update_ind, MSG_ID_MEDIA_AUD_TTS_UPDATE_INFO_IND);
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        currentHandler = NULL;
        mdi_audio_state = MDI_AUDIO_IDLE;
        mdi_audio_start_background_timer();
        MDI_AUDIO_UNLOCK;
        return mdi_audio_get_event((U8) result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_tts_stop
 * DESCRIPTION
 *  This function is to stop playing TTS string.
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_tts_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_TTS_STOP, mdi_audio_state, mdi_audio_mode);
    if (!mdi_check_device_ownership())
    {
        MDI_AUDIO_UNLOCK;    
        return MDI_AUDIO_BLOCKED;
    }

    /*
     * set pseudo play file callback to NULL before callback
     * bcoz we could set another callback during callback
     */
    if (pseudo_play_file_callback)
    {
        mdi_callback old_pseudo_play_file_callback = pseudo_play_file_callback;
        pseudo_play_file_callback = NULL;
        old_pseudo_play_file_callback(MDI_AUDIO_TERMINATED);
    }

    if (!((mdi_audio_state == MDI_AUDIO_PLAY || mdi_audio_state == MDI_AUDIO_PLAY_PAUSED)
          && mdi_audio_mode == MDI_AUDIO_PLAY_TTS))
    {
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }

    SetProtocolEventHandler(NULL, MSG_ID_L4AUD_MEDIA_PLAY_FINISH_IND);
    SetProtocolEventHandler(NULL, MSG_ID_MEDIA_AUD_TTS_UPDATE_INFO_IND);
    media_aud_tts_stop_req(MOD_MMI);

    if (currentHandler)
    {
        previousHandler = currentHandler;
        currentHandler = NULL;
        previousHandler(MDI_AUDIO_TERMINATED);
    }
    updateDurHandler = NULL;

    mdi_audio_state = MDI_AUDIO_IDLE;
    mdi_audio_start_background_timer();

    MDI_AUDIO_UNLOCK;
    return MDI_AUDIO_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_tts_pause
 * DESCRIPTION
 *  This function is to pause playing TTS string.
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_tts_pause(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_TTS_PAUSE, mdi_audio_state);
    if (!mdi_check_device_ownership())
    {
        MDI_AUDIO_UNLOCK;    
        return MDI_AUDIO_BLOCKED;
    }

    if ((result = media_aud_tts_pause_req(MOD_MMI)) == MED_RES_OK)
    {
        if (mdi_audio_state == MDI_AUDIO_PLAY)
        {
            mdi_audio_state = MDI_AUDIO_PLAY_PAUSED;
        }
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        currentHandler = NULL;
        mdi_audio_state = MDI_AUDIO_IDLE;
        mdi_audio_start_background_timer();
        MDI_AUDIO_UNLOCK;
        return mdi_audio_get_event((U8) result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_tts_resume
 * DESCRIPTION
 *  This function is to resume playing TTS string.
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_tts_resume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_TTS_RESUME, mdi_audio_state);
    if (!mdi_check_device_ownership())
    {
        MDI_AUDIO_UNLOCK;    
        return MDI_AUDIO_BLOCKED;
    }

    if ((result = media_aud_tts_resume_req(MOD_MMI)) == MED_RES_OK)
    {
        if (mdi_audio_state == MDI_AUDIO_PLAY_PAUSED)
        {
            mdi_audio_state = MDI_AUDIO_PLAY;
        }
        MDI_AUDIO_UNLOCK;
        return MDI_AUDIO_SUCCESS;
    }
    else
    {
        currentHandler = NULL;
        mdi_audio_state = MDI_AUDIO_IDLE;
        mdi_audio_start_background_timer();
        MDI_AUDIO_UNLOCK;
        return mdi_audio_get_event((U8) result);
    }
}
#endif /*__GENERAL_TTS__*/


#ifdef __KEY_TONE_DETECT__
static void (*mdi_keytone_detect_callback)(S16);
static MMI_BOOL mdi_keytone_detect_on;

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_keytone_detect_ind
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
void mdi_audio_keytone_detect_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    media_aud_kt_detect_ind_struct *msg_p = (media_aud_kt_detect_ind_struct*) msg;
    
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_KEYTONE_DETECT_IND, mdi_keytone_detect_on, msg_p->key);

    if(mdi_keytone_detect_on)
    {
        mdi_keytone_detect_callback(msg_p->key);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_start_keytone_detect
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_start_keytone_detect(void (*callback)(S16 key_ascii) )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_START_KEYTONE_DETECT);

    /* Need to turn on in speech mode and can not use while recording */
    if(!mdi_audio_is_speech_mode() || (mdi_audio_state == MDI_AUDIO_RECORD)|| (mdi_audio_state == MDI_AUDIO_RECORD_PAUSED))
    {
        return MDI_AUDIO_FAIL;
    }

    if(media_aud_start_keytone_detect_req(MOD_MMI) == MDI_AUDIO_SUCCESS)
    {
        mdi_keytone_detect_on = MMI_TRUE;
        mdi_keytone_detect_callback = callback;
        SetProtocolEventHandler(mdi_audio_keytone_detect_ind, MSG_ID_MEDIA_AUD_KT_DETECT_IND);
        return MDI_AUDIO_SUCCESS;    
    }
    else
    {
        mdi_keytone_detect_on = MMI_FALSE;
        mdi_keytone_detect_callback = NULL;
        SetProtocolEventHandler(NULL, MSG_ID_MEDIA_AUD_KT_DETECT_IND);
        return MDI_AUDIO_FAIL;    
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_keytone_detect
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_stop_keytone_detect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_STOP_KEYTONE_DETECT);

    media_aud_stop_keytone_detect_req(MOD_MMI);
    mdi_keytone_detect_on = MMI_FALSE;
    mdi_keytone_detect_callback = NULL;
    SetProtocolEventHandler(NULL, MSG_ID_MEDIA_AUD_KT_DETECT_IND);
}

#endif /*__KEY_TONE_DETECT__*/


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_blocked_recovery
 * DESCRIPTION
 *  This function will be called by mdi_switch_device_ownership when someone
 *  switch device ownership.
 *  When switching ownership, we will force media task to termiate all action
 *  and back to idle. MDI also need restore state to idle.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_blocked_recovery(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Call init function to clear all state, keep background play handler */
    mdi_audio_init_variable();
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_message_dispatcher()
 * DESCRIPTION
 *  Message dispatcher of MDI_AUDIO
 * PARAMETERS
 *  ilm_ptr             [IN]    ilm pointer
 * RETURNS
 *  MMI_BOOL: MDI_AUDIO consume the message or not 
 *****************************************************************************/
MMI_BOOL mdi_audio_message_dispatcher(void *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_p = ilm_ptr;
    MMI_BOOL handle_msg = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    switch(ilm_p->msg_id)
    {
    	case MSG_ID_L4AUD_MEDIA_RECORD_FINISH_IND:
    	    mdi_audio_record_finish_ind((void*)ilm_p->local_para_ptr);
    		break;

        default:
            handle_msg = MMI_FALSE;
            break;
    }

    return handle_msg;
}
/* Vogins Start */
#ifdef __VRE__
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_register_interrupt_callback()
 * DESCRIPTION
 *  Register mdi audio interrupt callback. Application will receive callback
 *  when mdi audio recive a new play request or stop requst
 *
 *  !!!Be sure to clear this hanlder when not used. Only one instance currently
 *   
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_register_interrupt_callback(mdi_callback handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MDI_AUDIO_LOCK;
    //MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_REG_INT_CALLBACK, mdi_audio_state);

    /* Only allow one application in a time */
    MMI_ASSERT(g_mdi_aud_int_callback == NULL);

    mdi_audio_stop_background_timer();
    g_mdi_aud_int_callback = handler;

    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_clear_interrupt_callback()
 * DESCRIPTION
 *  clear interrupt callback handler
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
void mdi_audio_clear_interrupt_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MDI_AUDIO_LOCK;
    //MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_CLEAR_INT_CALLBACK);

    g_mdi_aud_int_callback = NULL;
    mdi_audio_start_background_timer();

    MDI_AUDIO_UNLOCK;
}
#endif
/* Vogins End */
/* JAVA audio background play */
#ifdef __J2ME__
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_is_able_to_background_play()
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
MMI_BOOL mdi_audio_is_able_to_use_by_other_task(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MDI_AUDIO_LOCK;
    if (!mdi_audio_is_speech_mode() &&
        (mdi_audio_is_idle() || (mdi_audio_state == MDI_AUDIO_PLAY && mdi_audio_mode == MDI_AUDIO_PLAY_IN_OTHER_TASK)) &&
    #if defined(BGSND_ENABLE)
        mdi_audio_snd_is_idle() &&
    #endif
        mdi_audio_mma_is_idle())
    {
        MDI_AUDIO_UNLOCK;
        return MMI_TRUE;
    }

    MDI_AUDIO_UNLOCK;
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_set_play_interrupt_and_state_hdlr()
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
void mdi_audio_start_use_by_other_task(mdi_callback handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_START_USE_BY_OTHER_TASK, mdi_audio_state);

    mdi_audio_state = MDI_AUDIO_PLAY;
    mdi_audio_mode = MDI_AUDIO_PLAY_IN_OTHER_TASK;
    currentHandler = handler;
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_play_in_other_task()
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
void mdi_audio_stop_use_by_other_task(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_STOP_USE_BY_OTHER_TASK);

    currentHandler = NULL;
    mdi_audio_state = MDI_AUDIO_IDLE;
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_terminate_use_by_other_task
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_terminate_use_by_other_task(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MDI_AUDIO_LOCK;
    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_AUDIO_TRC_TERMINATE_USE_BY_OTHER_TASK);

    if (currentHandler)
    {
        previousHandler = currentHandler;
        currentHandler = NULL;
        previousHandler(MDI_AUDIO_TERMINATED);
    }
    mdi_audio_state = MDI_AUDIO_IDLE;
    MDI_AUDIO_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mutex_lock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_mutex_lock(S8 *file_p, U32 line_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_PRINT(MOD_MMI_MEDIA_APP, MMI_MEDIA_TRC_G10_MMI_PRINT,"[MDI][AUD] LOCK: cnt=[%d] [%s,%d]\n", g_mdi_audio_mutex_cnt, file_p, line_p);
    MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, MDI_AUDIO_TRC_MUTEX_LOCK, g_mdi_audio_mutex_cnt, line_p);

    if (stack_int_get_active_module_id() != g_mdi_audio_mutex_tid)
    {
        kal_take_sem(g_mdi_audio_sem, KAL_INFINITE_WAIT);
        g_mdi_audio_mutex_tid = stack_int_get_active_module_id();
    }
    ++g_mdi_audio_mutex_cnt;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mutex_lock_no_wait
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mdi_audio_mutex_lock_no_wait(S8 *file_p, U32 line_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    //MMI_PRINT(MOD_MMI_MEDIA_APP, MMI_MEDIA_TRC_G10_MMI_PRINT,"[MDI][AUD] LOCK_NO_WAIT: cnt=[%d] [%s,%d]\n", g_mdi_audio_mutex_cnt, file_p, line_p);
    MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, MDI_AUDIO_TRC_MUTEX_LOCK_NO_WAIT, g_mdi_audio_mutex_cnt, line_p);

    if (stack_int_get_active_module_id() != g_mdi_audio_mutex_tid)
    {
        if (kal_take_sem(g_mdi_audio_sem, KAL_NO_WAIT) == KAL_SEM_NOT_AVAILABLE)
        {       
            return MMI_FALSE;
        }
        g_mdi_audio_mutex_tid = stack_int_get_active_module_id();
       
    }
    ++g_mdi_audio_mutex_cnt;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mutex_unlock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_audio_mutex_unlock(S8 *file_p, U32 line_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_PRINT(MOD_MMI_MEDIA_APP, MMI_MEDIA_TRC_G10_MMI_PRINT,"[MDI][AUD] UNLOCK: cnt=[%d] [%s,%d]\n", g_mdi_audio_mutex_cnt, file_p, line_p);
    MMI_TRACE(MMI_MEDIA_TRC_G10_MMI_PRINT, MDI_AUDIO_TRC_MUTEX_UNLOCK, g_mdi_audio_mutex_cnt, line_p);

    ASSERT(g_mdi_audio_mutex_tid == stack_int_get_active_module_id());

    --g_mdi_audio_mutex_cnt;

    if (g_mdi_audio_mutex_cnt == 0)
    {
        g_mdi_audio_mutex_tid = MOD_NIL;
        kal_give_sem(g_mdi_audio_sem);
    }
}
#endif /* __J2ME__ */

