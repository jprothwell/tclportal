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
 * med_global.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary global definitions of media task.
 *
 * Author:
 * -------
 * -------
 * -------
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef MED_NOT_PRESENT

#if !defined(MED_MEM_CHECK)
#include "kal_release.h"
#include "fs_type.h"
#endif

#include "lcd_Sw_inc.h"

#if defined(__J2ME__)
#include "j2me_custom_param.h"
#endif

#if defined (ISP_SUPPORT) || defined(__DIRECT_SENSOR_SUPPORT__)
//#include "image_sensor.h"
#endif

#ifndef _MED_GLOBAL_H
#define _MED_GLOBAL_H

/*======== CONSTANTS ==========*/
#if defined(OV9655)
#define YUV_130_SENSOR
#elif defined(MT9D112)
#define __IMAGE_SENSOR_2M__
#endif 

#if defined(MT6238) || defined(MT6239)
#define MT6217_SERIES  0
#define MT6219_SERIES  0
#define MT6228_SERIES  0
#define MT6225_SERIES  0
#define MT6238_SERIES  1
#elif defined(MT6217) || defined(MT6218B)
#define MT6217_SERIES  1
#define MT6219_SERIES  0
#define MT6228_SERIES  0
#define MT6225_SERIES  0
#define MT6238_SERIES  0
#elif defined(MT6219) || defined(MT6226) || defined(MT6226D) || defined(MT6226M) || defined(MT6227) || defined(MT6227D)
#define MT6217_SERIES  0
#define MT6219_SERIES  1
#define MT6228_SERIES  0
#define MT6238_SERIES  0
#define MT6225_SERIES  0
#elif defined(MT6228) || defined(MT6229) || defined(MT6230)
#define MT6217_SERIES  0
#define MT6219_SERIES  0
#define MT6228_SERIES  1
#define MT6238_SERIES  0
#define MT6225_SERIES  0
#elif defined(MT6225) || defined(MT6223P) || defined(MT6223P_S00) || defined(MT6223) || defined(MT6235) || defined(MT6235B)
#define MT6217_SERIES  0
#define MT6219_SERIES  0
#define MT6228_SERIES  0
#define MT6238_SERIES  0
#define MT6225_SERIES  1
#else
#define MT6217_SERIES  0
#define MT6219_SERIES  0
#define MT6228_SERIES  0
#define MT6238_SERIES  0
#define MT6225_SERIES  0
#endif 

/* for Catcher to inject test messages */
// #define TST_HANDLER
/* for vm logging */
// #define VM_LOG

#ifdef __3G_VIDEO_CALL__
/* under construction !*/
#endif

#if defined(__MTV_SUPPORT__)
#define __MED_MTV_MOD__
#endif

#ifdef __CTM_SUPPORT__
#define __MED_CTM_MOD__
#endif 

#if defined( __BT_HFG_PROFILE__ )
#define __MED_BT_HFP_MOD__

#if defined(__BT_AUDIO_VIA_SCO__)
#define __MED_BT_AUDIO_VIA_SCO__
#endif

#if defined(__BT_FM_VIA_SCO__)
#define __MED_BT_FM_VIA_SCO__
#endif

#endif /* #if defined( __BT_HFG_PROFILE__ ) */

#if defined(__BT_A2DP_PROFILE__)
#define __MED_BT_A2DP_MOD__
#endif 

#if defined(__MED_BT_HFP_MOD__) || defined(__MED_BT_A2DP_MOD__)
#define __MED_BT_MOD__
#endif 

#if defined(PLUTO_MMI)
#define __MMI_SUPPORT_BACKLIGHT_SYNC__
#define __MMI_SUPPORT_LED_SYNC__
#define __16_LEVEL_AUDIO_VOLUME__
#endif /* defined(PLUTO_MMI) */ 

#if defined(__POC__)
#define __MED_POC_MOD__
#endif 

#if !defined(MT6205B) && !defined(MT6208) && !defined(MT6223)
#define __RICH_AUDIO_PROFILE__  /* (1)Spectrum (2)Build Cache, (3)ID3 Parser */
#endif

#if !defined(MT6205B) && !defined(MT6208) && defined(AMR_CODEC)
#define AMR_DECODE
#endif /* !defined(MT6205B) && !defined(MT6208) */ 

#if defined(MED_LOW) || defined(MED_MODEM)
#define SLIM_AUDIO_PROFILE
#endif 

#if defined(PURE_AUDIO_SUPPORT)
#define MED_PURE_AUDIO
#endif

#if defined (ISP_SUPPORT) || defined(__DIRECT_SENSOR_SUPPORT__)
#define __MED_CAM_MOD__

#ifdef WEBCAM_SUPPORT
#define __MED_WEBCAM_MOD__
#endif 

#if defined(XENON_FLASHLIGHT) || defined(XENON_FLASHLIGHT_ANTI_RED_EYE)
#define __MED_CAM_XENON_FLASH_SUPPORT__
#endif

#if defined(__FACE_DETECTION_SUPPORT__)
#define __MED_CAM_FD_SUPPORT__
#endif

#if defined(AF_SUPPORT)
#define __CAM_AUTO_FOCUS__
#endif 
#endif /* defined (ISP_SUPPORT) || defined(__DIRECT_SENSOR_SUPPORT__) */ 

#if defined(TV_OUT_SUPPORT)
#define __MED_TVO_MOD__
#endif 

#if defined (JPG_DECODE) || defined (JPG_ENCODE) || defined (GIF_DECODE)
#define __MED_IMG_MOD__
#endif 

#if defined (MP4_DECODE) 
    #define __MED_VID_MOD__

    #if defined (MP4_ENCODE)
        #define __MED_VID_ENC_MOD__

        #if defined(VDOEDT_SUPPORT)
            #define __MED_VID_EDT_MOD__
        #endif        
    #endif

    #ifdef PGDL_SUPPORT
        #define __MED_VID_PDL_MOD__
    #endif 
    
#endif 


#if defined (MJPG_SUPPORT) 
    #define __MED_MJPG_MOD__ 

    #if defined (ISP_SUPPORT)
        #define __MED_MJPG_ENC_MOD__
    #elif defined(__DIRECT_SENSOR_SUPPORT__)
        #define __MED_MJPG_ENC_MOD__
        #define __MED_MJPG_ENC_UNSTABLE_FPS__
    #endif 
    
#endif 

#if defined(DSP_WT_SYN)
    /* For play midi, imelody after MT6218B chip */
    #define __MED_DSP_WT_SYN__

    /* Multiple player control, not used in neptune project */
    #if !defined(NEPTUNE_MMI)
        #define __MED_MMA_MOD__

        #if !defined(MT6205B) && !defined(MT6208) && !defined(MT6223) && !defined(MT6223P)
            #define __MED_MMA_JAVA_CTRL__ /* Advance MMA control */
        #endif
    #endif
#endif

#if defined (FM_RADIO_ENABLE)
#define __MED_FMR_MOD__
#endif 

#if defined(AUD_REC_ENABLE)
#define __MED_AUD_REC_MOD__
#endif 

#if defined(VR_ENABLE)
#define __MED_VR_MOD__
#endif 

#if defined(VRSI_ENABLE)
#define __MED_VRSI_MOD__
#endif 

#if defined(BGSND_ENABLE)
#define __MED_SND_MOD__
#endif 

#if defined(AUD_TIME_STRETCH)
#define __MED_AUD_TIME_STRETCH__
#endif

#if defined(AUD_REVERB)
#define __MED_AUD_REVERB__
#endif

#if defined(AUD_3D_SURROUND_LSPK) || defined(AUD_3D_SURROUND_EARP)
#define __MED_AUD_SURROUND__
#endif

#if defined(AUDIO_EQUALIZER_ENABLE)
#define __MED_AUD_EQUALIZER__
#endif

/* Either turn on (1)time stretch (2)reverb (3)3D surround (4)equalizer */
#if defined(AUD_TIME_STRETCH) || defined(AUD_REVERB) || defined(AUD_3D_SURROUND_LSPK) || defined(AUD_3D_SURROUND_EARP) || defined(AUDIO_EQUALIZER_ENABLE)
#define __MED_AUD_AUDIO_EFFECT__
#endif

#ifdef DEDI_AMR_REC
#define DEDI_AMR_REC_BUFFER
#endif 

#if defined (__POC__) || defined (STREAM_SUPPORT) || defined (__VOIP__)
#define __MED_RTP_MOD__
#endif 

#if defined(STREAM_SUPPORT)
#define __MED_STREAM_MOD__
#endif 

#if defined(__GENERAL_TTS__)
#define __MED_GENERAL_TTS__
#endif

#if !defined(__PRODUCTION_RELEASE__)
#define __MED_MEM_DEBUG_ON__
// Disable BSS snapshot since W08.28mp
//#define __CAM_BSS_DEBUG_MODE__
#endif


#define SET_VOLUME_WHEN_PLAY

#define  AUD_IDLE  0
#define  AUD_VM_IDLE                   0
#define  AUD_VM_RECORD                 1
#define  AUD_VM_RECORD_PAUSED          4
#define  AUD_VM_PLAY                      5
#define  AUD_VM_PLAY_PAUSED            6
#define  AUD_VM_PLAY_FINISH            7

/* audio state */
#define  AUD_MEDIA_IDLE             0
#define  AUD_MEDIA_PLAY             30
#define  AUD_MEDIA_PLAY_FINISH      31
#define  AUD_MEDIA_PLAY_PAUSED      32
#define  AUD_MEDIA_RECORD             33
#define  AUD_MEDIA_RECORD_PAUSED      34
#define  AUD_MEDIA_SEEK_PAUSED      35

#define  AUD_MEDIA_UNDERFLOW        36
#define  AUD_MEDIA_UNDERFLOW_PAUSE  37
#define  AUD_MEDIA_WRITE_DATA_PAUSE 38

/* audio post process state */
#define  AUD_EFFECT_UNSET     0 /* Parameter not set */
#define  AUD_EFFECT_OFF    1
#define  AUD_EFFECT_ON        2
//#define  AUD_EFFECT_INT       3 /* Interrupt */

/* camera state */
#define CAM_IDLE        0
#define CAM_READY      1
#define CAM_START_PREVIEW      2
#define CAM_PREVIEW      3
#define CAM_POWER_UP     4
#define CAM_CAPTURE      5
#define CAM_CAPTURE_BARCODE 6
#define CAM_CAPTURE_FINISHED 7

/* image state */
#define IMG_IDLE        0
#define IMG_JPG_DECODE      1
#define IMG_JPG_ENCODE      2
#define IMG_GIF_DECODE       3
#define IMG_GIF_V2_DECODE 4
#define IMG_PNG_DECODE     5

/* video state */
#define VID_IDLE                        0
#define VID_PREVIEW                     1
#define VID_RECORD                      2
#define VID_RECORD_FINISH               3
#define VID_RECORD_PAUSED               4
#define VID_OPEN_FILE                   5
#define VID_FILE_READY                  6
#define VID_PLAY_INIT                   7
#define VID_PLAY                        8
#define VID_AUDIO_PLAY_FINISH           9
#define VID_AUDIO_PLAY_ERROR            10
#define VID_VISUAL_PLAY_FINISH          11
#define VID_PLAY_PAUSED                 12
#define VID_FILE_MERGE                  13
#define VID_SEEK                        14
#define VID_GET_IFRAME                  15
#define VID_PLAY_STOP_VISUAL            16
#define VID_RECORD_STOP_VISUAL          17
#define VID_DELAY_OPEN                  18
#define VID_RECORD_ABORTING             19
#define VID_PLAY_ABORTING               20
#define VID_START_PREVIEW               21
#define VID_FILE_MERGE_STOPPING         22
#define VID_PDL_META_BUFFERING          23
#define VID_VIDEO_PLAY_UNDERFLOW        24
#define VID_PLAY_REACH_STOP_TIME        25
#define VID_EDITOR_FILE_MERGE           26
#define VID_EDITOR_MERGE_STOPPING       27
#define VID_RECORD_UPDATE_BLT_PAUSED    28

#define VID_AUD_IDLE              0
#define VID_AUD_PLAY_NORMAL       1
#define VID_AUD_PLAY_HIGH_SPEED   2
#define VID_AUD_PLAY_DUMMY        3
#define VID_AUD_RECORD            4
#define VID_AUD_RECORD_PAUSED     5
#define VID_AUD_PLAY_UNDERFLOW    6

/* Web camera state */
#define WEBCAM_IDLE             0
#define WEBCAM_START_PREVIEW    1
#define WEBCAM_PREVIEW          2
#define WEBCAM_CAPTURE          3
#define WEBCAM_PAUSING          4
#define WEBCAM_PAUSED           5
#define WEBCAM_STOPPING         6

/* TV output state */
#define TVO_IDLE        0
#define TVO_DETECTION  1
#define TVO_READY      2
#define TVO_UPDATE      3

#define INVALID_VM_ID      255
#define MAX_FILE_NAME_LEN  261
#define MAX_VM_LOG_LEN  (200*1024)
#define IMY_DEFAULT_INSTRUMENT   74     /* Flute */

/******************************************************
 * 1. Audio static ring buffer 
 ******************************************************/
#ifdef SLIM_AUDIO_PROFILE
    #ifdef AUD_REC_ENABLE
        #define AUD_RING_BUFFER_LEN     (1*1300)
    #else
        #define AUD_RING_BUFFER_LEN     (1*1024)
    #endif
#else /* SLIM_AUDIO_PROFILE */ 
    #ifdef MT6238
        #define AUD_RING_BUFFER_LEN     (32*1024)
    #else
        #define AUD_RING_BUFFER_LEN     (8*1024)
    #endif
#endif /* SLIM_AUDIO_PROFILE */

/******************************************************
 * 2. Audio Feature (No background play)
 ******************************************************/
/* VRSD */
#if defined(__MED_VR_MOD__)
    #define AUD_MED_VRSD_EXT_MEM_SIZE (19*1024) /* Actual 19232 bytes */
#else
    #define AUD_MED_VRSD_EXT_MEM_SIZE (0)
#endif

/* VRSI */
#if defined(VRSI_ENABLE)
    #define AUD_MED_VRSI_EXT_MEM_SIZE (400*1024)
#else
    #define AUD_MED_VRSI_EXT_MEM_SIZE (0)
#endif

/* CTM */
#if defined(__MED_CTM_MOD__)
    #define AUD_MED_CTM_EXT_MEM_SIZE (9*1024)  /* Actual: 8184(Driver) + 61(MED) bytes */
#else
    #define AUD_MED_CTM_EXT_MEM_SIZE (0)
#endif

/******************************************************
 * 3. Audio MED (Background Play)
 ******************************************************/
#if defined(LOW_COST_SUPPORT)
    #define AUD_PROC_BUF_SIZE  (512)
#else
    #define AUD_PROC_BUF_SIZE  (1024)	 /* It will use static buffer, except to get duration */
    #define AUD_PROC_USE_EXT_MEM
#endif

 /* Buffer for playing midi, imelody from file */
#if defined(SLIM_AUDIO_PROFILE)
    #define AUD_MELODY_BUFFER_LEN (512)
#else

    #ifdef __AUD_MELODY_BUFFER_300K__
        #define AUD_MELODY_BUFFER_LEN (300*1024)
    #else
        #define AUD_MELODY_BUFFER_LEN (100*1024)
    #endif
#endif

 /* Buffer for audio driver to process midi files */
#if defined(SLIM_AUDIO_PROFILE)
    #define AUD_SMF_BUFFER_LEN (0)  /* Use control buffer to get memory */
#else
    #if defined(__MED_MMA_MOD__)
        #define AUD_SMF_BUFFER_LEN (4*1600) /* Can play 4 midi at a time */
    #elif defined(__MED_DSP_WT_SYN__)
        #define AUD_SMF_BUFFER_LEN (1600)
    #else
        #define AUD_SMF_BUFFER_LEN (0)
    #endif
#endif

/* Depend on JWav_Load() */
#if defined(DSP_WT_SYN) && defined(__MED_MMA_MOD__)
    #define AUD_MED_MULTIPLE_WAV_EXT_MEM_SIZE  (7800) /* Actual: 48(K sampling rate) * 54 * 3 (concurrent mma) */
#else
    #define AUD_MED_MULTIPLE_WAV_EXT_MEM_SIZE  (0)
#endif

/* General TTS */
#if defined(IFLY_TTS)
    #define AUD_MED_TTS_EXT_MEM_SIZE (156*1024)
#elif defined(CYBERON_DIC_TTS)
    #define AUD_MED_TTS_EXT_MEM_SIZE (86*1024)
#else
    #define AUD_MED_TTS_EXT_MEM_SIZE (0)
#endif

/* To play pure audio 3GP, MP4 files */
#if defined(MED_PURE_AUDIO)
    #define AUD_MED_MP4_EXT_MEM_SIZE (13*1024)
#else
    #define AUD_MED_MP4_EXT_MEM_SIZE (0)
#endif

/******************************************************
 * 4. Audio Driver (Background Play)
 ******************************************************/
/* Will be concurrently used with audio codec */
#if defined(__BT_AUDIO_VIA_SCO__)
    #define AUD_DRV_BT_SCO_EXT_MEM_SIZE (17*1024) /* Actual: 16384 bytes */
#else
    #define AUD_DRV_BT_SCO_EXT_MEM_SIZE (0)
#endif

/* Currently only used in call, exclusively used with audio codec  */
#if defined(__MED_SND_MOD__)
    #define AUD_DRV_BGSND_EXT_MEM_SIZE (10*1024) /* Actual: 8321 bytes */
#else
    #define AUD_DRV_BGSND_EXT_MEM_SIZE (0)
#endif

#if defined(DAF_DECODE)
    #define AUD_DRV_DAF_EXT_MEM_SIZE (10*1024) /* Actual: 8192 bytes */
#else
    #define AUD_DRV_DAF_EXT_MEM_SIZE (0)
#endif

#if defined(AAC_DECODE)
    #define AUD_DRV_AAC_EXT_MEM_SIZE (25*1024 + 4*1024) /* Actual: 24568 bytes + 4k bbytes for M4A */
#else
    #define AUD_DRV_AAC_EXT_MEM_SIZE (0)
#endif

#if defined(AAC_PLUS_DECODE)
    #define AUD_DRV_AAC_PLUS_EXT_MEM_SIZE (25*1024) /* Actual: 24968 bytes */
#else
    #define AUD_DRV_AAC_PLUS_EXT_MEM_SIZE (0)
#endif

#if defined(AAC_PLUS_PS_DECODE)
    #define AUD_DRV_AAC_PLUS_PS_EXT_MEM_SIZE (27*1024) /* Actual: 27096 bytes */
#else
    #define AUD_DRV_AAC_PLUS_PS_EXT_MEM_SIZE (0)
#endif

#if defined(AWB_PLUS_DECODE)
    #define AUD_DRV_AWB_PLUS_EXT_MEM_SIZE (54*1024) /* Actual: 54328 bytes */
#else
    #define AUD_DRV_AWB_PLUS_EXT_MEM_SIZE (0)
#endif

/******************************************************
 * 5. Begin to count AUDIO EXT MEM size
 ******************************************************/
#define AUD_MED_OVERHEAD (4)
 
typedef union
{
    kal_uint8 aud_01[AUD_DRV_BT_SCO_EXT_MEM_SIZE + AUD_MED_VRSD_EXT_MEM_SIZE + AUD_MED_OVERHEAD];
    kal_uint8 aud_02[AUD_DRV_BT_SCO_EXT_MEM_SIZE + AUD_MED_VRSI_EXT_MEM_SIZE + AUD_MED_OVERHEAD];
    kal_uint8 aud_03[AUD_MED_CTM_EXT_MEM_SIZE + AUD_MED_OVERHEAD];
    kal_uint8 aud_04[AUD_DRV_BT_SCO_EXT_MEM_SIZE + AUD_MELODY_BUFFER_LEN + AUD_SMF_BUFFER_LEN + AUD_MED_OVERHEAD];
    kal_uint8 aud_05[AUD_DRV_BT_SCO_EXT_MEM_SIZE + AUD_MED_MULTIPLE_WAV_EXT_MEM_SIZE + AUD_MED_OVERHEAD];
    kal_uint8 aud_06[AUD_DRV_BT_SCO_EXT_MEM_SIZE + AUD_MED_TTS_EXT_MEM_SIZE + AUD_MED_OVERHEAD];
    kal_uint8 aud_07[AUD_DRV_BT_SCO_EXT_MEM_SIZE + AUD_DRV_BGSND_EXT_MEM_SIZE + AUD_MED_OVERHEAD];
    kal_uint8 aud_08[AUD_DRV_BT_SCO_EXT_MEM_SIZE + AUD_DRV_DAF_EXT_MEM_SIZE + AUD_MED_OVERHEAD];
    kal_uint8 aud_09[AUD_DRV_BT_SCO_EXT_MEM_SIZE + AUD_MED_MP4_EXT_MEM_SIZE + AUD_DRV_AAC_EXT_MEM_SIZE + AUD_DRV_AAC_PLUS_EXT_MEM_SIZE + AUD_DRV_AAC_PLUS_PS_EXT_MEM_SIZE + AUD_MED_OVERHEAD];
    kal_uint8 aud_10[AUD_DRV_BT_SCO_EXT_MEM_SIZE + AUD_DRV_AWB_PLUS_EXT_MEM_SIZE + AUD_MED_OVERHEAD];
    kal_uint8 aud_11[AUD_PROC_BUF_SIZE + AUD_MED_OVERHEAD];
} aud_ext_mem_union;

#define AUD_EXT_MEM_SIZE sizeof(aud_ext_mem_union)


/******************************************************
 * MED shared memory usage definition 
 ******************************************************/
#define MED_DIRECT_SENSOR_INT_SIZE (704)

#if defined(__MP4_ENC_SW_SUPPORT__) || defined(__H264_DEC_SW_SUPPORT__)
#define MED_INT_STACK_MEM_SIZE (4096)
#else
#define MED_INT_STACK_MEM_SIZE (2800)
#endif

#if defined(__MED_MEM_DEBUG_ON__)
/**
 * when turn on debug on, adm need around 200K to log some information, 
 * so we enlarge MEM_OVERHEAD to 384 bytes */
#define MEM_OVERHEAD  (384)
#define MEM_EXT_OVERHEAD (1024)
#else
#define MEM_OVERHEAD  (256)
#define MEM_EXT_OVERHEAD (256)
#endif

/******************************************************
 * 1. SWFlash 
 ******************************************************/
#if defined(SWFLASH_NEOMTEL)
#include "mmi_features.h"
    #if defined(__MMI_MOTION_MAINMENU__) || defined(__MMI_MOTION_DIAL__)
        #if defined(__MMI_MAINLCD_240X400__)
            #define SWFLASH_MEM_SIZE (4500*1024+(LCD_WIDTH * LCD_HEIGHT* 2))
        #elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__)
            #define SWFLASH_MEM_SIZE (2517*1024+(LCD_WIDTH * LCD_HEIGHT* 2))
        #else
            #define SWFLASH_MEM_SIZE (1500*1024+(LCD_WIDTH * LCD_HEIGHT* 2))
        #endif   
    #else
        #define SWFLASH_MEM_SIZE ((1000*1024)/*engine 600k + material 301k */+(LCD_WIDTH * LCD_HEIGHT* 2))
    #endif /* defined(__MMI_MOTION_MAIN_MENU__) || defined(__MMI_MOTION_DIAL__) */
#else
    #define SWFLASH_MEM_SIZE (0)
#endif
#define MAX_MED_SWFLASH_EXT_MEM_SIZE (SWFLASH_MEM_SIZE)


/******************************************************
 * 2. WEBCAM support
 ******************************************************/
#if defined(WEBCAM_SUPPORT)
    #if MT6238_SERIES
    #define MAX_WEBCAM_BUFFER_SIZE      (300*1024)       
    #else
    #define MAX_WEBCAM_BUFFER_SIZE      (145*1024)       /* (0xC000+12)*3 - Make sure sync with webcam */
    #endif
    #if defined(__SW_JPEG_CODEC_SUPPORT__)
    #define WEBCAM_JPEG_BUFFER_SIZE (640*480)
    #else
    #define WEBCAM_JPEG_BUFFER_SIZE (0)
    #endif
#else /* defined(WEBCAM_SUPPORT) */
    #define MAX_WEBCAM_BUFFER_SIZE      (0)
    #define WEBCAM_JPEG_BUFFER_SIZE     (0)
#endif /* defined(WEBCAM_SUPPORT) */

#define MAX_MED_WEBCAM_EXT_MEM_SIZE (WEBCAM_JPEG_BUFFER_SIZE+MAX_WEBCAM_BUFFER_SIZE)


/******************************************************
 * 3. JPEG DECODE
 ******************************************************/
#if defined(JPG_DECODE)
#if MT6225_SERIES
#define MAX_IMG_DEC_INT_MEM_SIZE   (45*1024)   /* Internal decode memory size for hardware engine buffer */
#define MAX_IMG_DEC_EXT_MEM_SIZE   (4096)      /* External decode memory size for hardware engine buffer */
#define MAX_IMG_DEC_FILE_BUFFER_LEN   (100*1024)        /* Buffer size for multi-run JPG decode. */
#elif MT6217_SERIES
#define MAX_IMG_DEC_INT_MEM_SIZE   (40320)     /* Internal decode memory size for hardware engine buffer */
#define MAX_IMG_DEC_EXT_MEM_SIZE   (4096)      /* External decode memory size for hardware engine buffer */
#define MAX_IMG_DEC_FILE_BUFFER_LEN   (100*1024)        /* Buffer size for multi-run JPG decode. */
#elif MT6219_SERIES
#define MAX_IMG_DEC_INT_MEM_SIZE   (150*1024)   /* Internal decode memory size for hardware engine buffer */
#define MAX_IMG_DEC_EXT_MEM_SIZE   (4096)       /* External decode memory size for hardware engine buffer */
#define MAX_IMG_DEC_FILE_BUFFER_LEN   (100*1024)        /* Buffer size for multi-run JPG decode. */
#else /* MT6228, MT6229, ... */
#define MAX_IMG_DEC_INT_MEM_SIZE   (64*1024)    /* Internal decode memory size for hardware engine buffer */
#define MAX_IMG_DEC_EXT_MEM_SIZE   (150*1024)   /* External decode memory size for hardware engine buffer */
#define MAX_IMG_DEC_FILE_BUFFER_LEN   (100*1024)        /* Buffer size for multi-run JPG decode. */
#endif 
#else /* JPG_DECODE */ 
#define MAX_IMG_DEC_INT_MEM_SIZE   (0)  /* Internal decode memory size for hardware engine buffer */
#define MAX_IMG_DEC_EXT_MEM_SIZE   (0)  /* External decode memory size for hardware engine buffer */
#define MAX_IMG_DEC_FILE_BUFFER_LEN   (0)       /* Buffer size for multi-run JPG decode. */
#endif /* JPG_DECODE */ 

#define MAX_MED_JPG_DEC_EXT_MEM_SIZE (MAX_IMG_DEC_EXT_MEM_SIZE+MAX_IMG_DEC_FILE_BUFFER_LEN)
#define MAX_MED_JPG_DEC_INT_MEM_SIZE (MAX_IMG_DEC_INT_MEM_SIZE)


/******************************************************
 * 4. JPEG ENCODE
 ******************************************************/
#if defined(JPG_ENCODE)
#if MT6225_SERIES
#define MAX_IMG_ENC_INT_MEM_SIZE   (3112)  /* Internal encode memory size for hardware engine buffer */
#define MAX_IMG_ENC_EXT_MEM_SIZE   (0)     /* External encode memory size for hardware engine buffer */
    #if defined(MT6223P) || defined(MT6223P_S00)
        #define MAX_IMG_ENC_FILE_BUFFER_LEN   (100*1024)    /* File buffer size for JPG encode. */
        #define MAX_SW_JPG_YUV_BUFFER_SIZE (352*288*3/2)
    #elif defined(MT6223)
        #define MAX_IMG_ENC_FILE_BUFFER_LEN   (0)           /* File buffer size for JPG encode. */
        #define MAX_SW_JPG_YUV_BUFFER_SIZE (0)
    #elif defined(YUV_130_SENSOR)
        #define MAX_IMG_ENC_FILE_BUFFER_LEN   (150*1024)    /* File buffer size for JPG encode. */
        #define MAX_SW_JPG_YUV_BUFFER_SIZE (1280*1024*3/2)
    #elif defined(MT6235) || defined(MT6235B)
        #if defined(__IMAGE_SENSOR_2M__)
        #define MAX_SW_JPG_YUV_BUFFER_SIZE (1600*1200*3/2)
        #elif defined(__IMAGE_SENSOR_1M__)
        #define MAX_SW_JPG_YUV_BUFFER_SIZE (1280*1024*3/2)
        #else
        #define MAX_SW_JPG_YUV_BUFFER_SIZE (640*480*3/2)  
        #endif
        #define MAX_IMG_ENC_FILE_BUFFER_LEN   (300*1024)    /* File buffer size for JPG encode. */
    #else
        #define MAX_IMG_ENC_FILE_BUFFER_LEN   (150*1024)    /* File buffer size for JPG encode. */
        #define MAX_SW_JPG_YUV_BUFFER_SIZE (640*480*3/2)
    #endif
#elif MT6219_SERIES
#define MAX_IMG_ENC_INT_MEM_SIZE   (49664)  /* Internal encode memory size for hardware engine buffer */
#define MAX_IMG_ENC_EXT_MEM_SIZE   (0)      /* External encode memory size for hardware engine buffer */
#define MAX_IMG_ENC_FILE_BUFFER_LEN   (150*1024)        /* File buffer size for JPG encode. */
#define MAX_SW_JPG_YUV_BUFFER_SIZE (0)
#else /* MT6228, MT6229, ... */
#define MAX_IMG_ENC_INT_MEM_SIZE   (0)    /* Internal encode memory size for hardware engine buffer */
#define MAX_IMG_ENC_EXT_MEM_SIZE   (41984)/* External encode memory size for hardware engine buffer */
/* 
 * it is a temp solution for this project. should be fixed before W08.16MP.
 **/
#if defined(A7510_DEMO_BB)
    #define MAX_IMG_ENC_FILE_BUFFER_LEN   (100*1024)        /* File buffer size for JPG encode. */
#else
    #define MAX_IMG_ENC_FILE_BUFFER_LEN   (300*1024)        /* File buffer size for JPG encode. */
#endif
#define MAX_SW_JPG_YUV_BUFFER_SIZE (0)
#endif /* MT6219_SERIES */ 

#else /* JPG_ENCODE */ 
#define MAX_IMG_ENC_INT_MEM_SIZE   (0)  /* Internal encode memory size for hardware engine buffer */
#define MAX_IMG_ENC_EXT_MEM_SIZE   (0)  /* External encode memory size for hardware engine buffer */
#define MAX_IMG_ENC_FILE_BUFFER_LEN   (0)       /* File buffer size for JPG encode. */
#define MAX_SW_JPG_YUV_BUFFER_SIZE (0)
#endif /* JPG_ENCODE */

#define MAX_MED_JPG_ENC_EXT_MEM_SIZE (MAX_IMG_ENC_EXT_MEM_SIZE+MAX_IMG_ENC_FILE_BUFFER_LEN+MAX_SW_JPG_YUV_BUFFER_SIZE)
#define MAX_MED_JPG_ENC_INT_MEM_SIZE (MAX_IMG_ENC_INT_MEM_SIZE)


/******************************************************
 * 5. Video Recorder/Player
 ******************************************************/
#if defined(MP4_DECODE) || defined(MP4_ENCODE)
    #if MT6219_SERIES
        #if defined(__TEARING_REDUCTION_FB_IN_INTSRAM__)
            /* internal memory - 5K video encode image datapath, 15K Jpeg encode */
            #define MAX_VID_DEC_INT_MEM_SIZE   (5*1024)           /* Internal decode memory size for hardware engine buffer, 
                                                                     enlarge this to support video decode+jpeg encode at QVGA LCD size */
            #define MAX_VID_DEC_EXT_MEM_SIZE   ((235+115)*1024)   /* External decode memory size for hardware engine buffer */
        #else /* __TEARING_REDUCTION_FB_IN_INTSRAM__ */
            #define MAX_VID_DEC_INT_MEM_SIZE   (115*1024)   /* Internal decode memory size for hardware engine buffer, 
                                                               enlarge this to support video decode+jpeg encode at QVGA LCD size */
            #define MAX_VID_DEC_EXT_MEM_SIZE   ((235+15)*1024)   /* External decode memory size for hardware engine buffer + jpeg encode hardware buffer */
        #endif /* __TEARING_REDUCTION_FB_IN_INTSRAM__ */

        #define MAX_VID_ENC_INT_MEM_SIZE   (158*1024)   /* Internal encode memory size for hardware engine buffer */
        #define MAX_VID_ENC_EXT_MEM_SIZE   (500*1024)   /* External encode memory size for hardware engine buffer */

    #else /* MT6219_SERIES */ 
        #if MT6238_SERIES
            #if defined(MT6238_PRES00) || defined(MT6239_PRES00) /* E2 version */
                #define MAX_VID_DEC_INT_MEM_SIZE   (95*1024+512)    /* Internal decode memory size for hardware engine buffer */         
            #else
                #define MAX_VID_DEC_INT_MEM_SIZE   (103*1024+512)    /* Internal decode memory size for hardware engine buffer */         
            #endif
                #define MAX_VID_DEC_EXT_MEM_SIZE   ((8000)*1024)    /* External decode memory size for hardware engine buffer */
        #else
            #define MAX_VID_DEC_INT_MEM_SIZE   (45*1024)    /* Internal decode memory size for hardware engine buffer */         
            #if defined(__H264_DEC_SW_SUPPORT__)
                #if defined(STREAM_SUPPORT)
/* under construction !*/
                #else
/* under construction !*/
                #endif
            #elif defined(__MP4_DEC_SW_SUPPORT__)
/* under construction !*/
            #else
                #define MAX_VID_DEC_EXT_MEM_SIZE   ((1510+150)*1024)    /* External decode memory size for hardware engine buffer */
            #endif
        #endif
        #if MT6238_SERIES
            #if defined(MT6238_PRES00) || defined(MT6239_PRES00) /* E2 version */
                #define MAX_VID_ENC_INT_MEM_SIZE   (25*1024 /*idp */ + 68*1024 /* mpeg4 */)       /* Internal encode memory size for hardware engine buffer */
            #else
                #define MAX_VID_ENC_INT_MEM_SIZE   (103*1024+512)       /* Internal encode memory size for hardware engine buffer */
            #endif
                #define MAX_VID_ENC_EXT_MEM_SIZE   (1520*1024 /* idp */ + 3392*1024)  /* External encode memory size for hardware engine buffer */
        #else
                #define MAX_VID_ENC_INT_MEM_SIZE   (45*1024)       /* Internal encode memory size for hardware engine buffer */
            #if defined(__H264_DEC_SW_SUPPORT__)
/* under construction !*/
            #elif defined(__MP4_DEC_SW_SUPPORT__)
/* under construction !*/
            #else
                #define MAX_VID_ENC_EXT_MEM_SIZE   (1500*1024)  /* External encode memory size for hardware engine buffer */
            #endif
        #endif
    #endif /* MT6219_SERIES */ 
    
#else /* MP4_CODEC */ 

    #define MAX_VID_DEC_INT_MEM_SIZE   (0)  /* Internal decode memory size for hardware engine buffer */
    #define MAX_VID_DEC_EXT_MEM_SIZE   (0)  /* External decode memory size for hardware engine buffer */

    #if defined(MT6225) || defined(MT6235) || defined(MT6235B)
    
        /* EXTERNAL MEMORY */
        /********************************************************
         * frame buffer :        176 x 144 x 2 = 50688
         * jpg file buffer    :  70 x 1024 = 71680    
         ********************************************************/
        #define MAX_VID_ENC_INT_MEM_SIZE   (15 * 1024)    /* this will not be the upper bound */
        
        /* INTERNAL MEMORY */
        /********************************************************
         * vid drv working buffer :  176 x 8(line) x 3 = 4224 
         * sw jpg working buffer : 3 x 1024 = 3072 
         * sw encode y buffer :  176 x 144 = 25344        
         * sw encode u buffer :  176 x 144 / 4 = 6336                
         * sw encode v buffer :  176 x 144 / 4 = 6336            
         ********************************************************/
        #define MAX_VID_ENC_EXT_MEM_SIZE   (45 * 1024)   
        
    #else /* defined(MT6225) || defined(MT6235) || defined(MT6235B) */
        #define MAX_VID_ENC_INT_MEM_SIZE   (0)          /* Internal encode memory size for hardware engine buffer */
        #define MAX_VID_ENC_EXT_MEM_SIZE   (0)          /* External encode memory size for hardware engine buffer */
    #endif /* defined(MT6225) || defined(MT6235) || defined(MT6235B) */
#endif /* defined(MP4_DECODE) || defined(MP4_ENCODE) */ 


#if MT6238_SERIES
#define MED_VID_DOUBLE_BUFFER_SIZE (320*480*2*2) /* VP7's double buffer */
#else
#define MED_VID_DOUBLE_BUFFER_SIZE (0)
#endif

#define MAX_MED_VID_ENC_INT_MEM_SIZE (MAX_VID_ENC_INT_MEM_SIZE)
#ifdef __DIRECT_SENSOR_SUPPORT__
#define MAX_MED_VID_ENC_EXT_MEM_SIZE (499*1024)
#else
#define MAX_MED_VID_ENC_EXT_MEM_SIZE (MAX_VID_ENC_EXT_MEM_SIZE+MED_VID_DOUBLE_BUFFER_SIZE)
#endif
#define MAX_MED_VID_DEC_INT_MEM_SIZE (MAX_VID_DEC_INT_MEM_SIZE)
#define MAX_MED_VID_DEC_EXT_MEM_SIZE (MAX_VID_DEC_EXT_MEM_SIZE+MED_VID_DOUBLE_BUFFER_SIZE)


/******************************************************
 * 6. Video Editor 
 ******************************************************/
#if defined(VDOEDT_SUPPORT)
    #if defined(MT6238_SERIES)
        #if defined(MT6238_PRES00) || defined(MT6239_PRES00) /* E2 version */
            #define MAX_VID_EDT_INT_MEM_SIZE   (94 * 1024)      /* Internal decode/encode memory size */
        #else
            #define MAX_VID_EDT_INT_MEM_SIZE   (103*1024+512)   /* Internal decode/encode memory size */
        #endif
    #else
        #define MAX_VID_EDT_INT_MEM_SIZE   (45 * 1024)      /* Internal decode/encode memory size */
    #endif /* defined(MT6238_SERIES) */
            
    #if MAX_VID_ENC_EXT_MEM_SIZE > MAX_MED_VID_DEC_EXT_MEM_SIZE
        #define MAX_VID_EDT_EXT_MEM_SIZE   (MAX_VID_ENC_EXT_MEM_SIZE + 191756 + 2 * (2 * 176 * 144))    /* External decode/encode memory size + cntx + aud working buffer + 2 * video size working buffer*/
    #else  /* MAX_VID_ENC_EXT_MEM_SIZE > MAX_MED_VID_DEC_EXT_MEM_SIZE */
        #define MAX_VID_EDT_EXT_MEM_SIZE   (MAX_MED_VID_DEC_EXT_MEM_SIZE + 191956 + 2 * (2 * 176 * 144))
    #endif /* MAX_VID_ENC_EXT_MEM_SIZE > MAX_MED_VID_DEC_EXT_MEM_SIZE */
#else /* VDOEDT_SUPPORT */
    #define MAX_VID_EDT_INT_MEM_SIZE   (0)              /* Internal decode/encode memory size */
    #define MAX_VID_EDT_EXT_MEM_SIZE   (0)              /* External decode/encode memory size */
#endif /* VDOEDT_SUPPORT */

#define MAX_MED_VDOEDT_EXT_MEM_SIZE (MAX_VID_EDT_EXT_MEM_SIZE)
#define MAX_MED_VDOEDT_INT_MEM_SIZE (MAX_VID_EDT_INT_MEM_SIZE)



/**************************************************************************************************************
 * 7. Camera capture 
 * External : MAX(MAX_CAM_FILE_BUFFER_LEN (isp),
                 (MAX_IMG_ENC_FILE_BUFFER_LEN + LCD_WIDTH*LCD_HEIGHT*2 + YUV_BUFFER | MAX_IMG_ENC_EXT_MEM_SIZE)
 * Internal : MAX(MAX_CAM_CAP_INT_MEM_SIZE,MAX_IMG_ENC_INT_MEM_SIZE)
 **************************************************************************************************************/
#if defined(ISP_SUPPORT) || defined(__DIRECT_SENSOR_SUPPORT__)

#if defined(MT6223P) || defined(MT6223P_S00)
#define MAX_CAM_FILE_BUFFER_LEN   (75*1024)    /* 75KB for 352x288 */
#define MAX_CAM_CAP_INT_MEM_SIZE   (352*2)   /* 352x288 */
#define MAX_CAM_CAP_EXT_MEM_SIZE   (0)
#define MAX_CAM_ENC_IMG_FILE_BUF_LEN (100*1024)
#define MAX_CAM_CAP_DIGITAL_ZOOM_WORKING_BUF_SIZE (0)
#elif defined(MT6225) || defined(MT6235) || defined(MT6235B)
    #if defined(__IMAGE_SENSOR_2M__)
        #define MAX_CAM_FILE_BUFFER_LEN   (1536*1024)   /* 1536KB for 1600x1200 */
    #elif defined(YUV_130_SENSOR)
        #define MAX_CAM_FILE_BUFFER_LEN   (650*1024)    /* 650KB for 1.3M */
    #else
        #define MAX_CAM_FILE_BUFFER_LEN   (300*1024)    /* 300KB for 640x480 */
    #endif
    #define MAX_CAM_CAP_INT_MEM_SIZE   (45*1024)   /* 1600x1200 */
    #define MAX_CAM_CAP_EXT_MEM_SIZE   (0)
    #define MAX_CAM_ENC_IMG_FILE_BUF_LEN (150*1024)
    #define MAX_CAM_CAP_DIGITAL_ZOOM_WORKING_BUF_SIZE (0)
#elif ( defined(MT6226) || defined(MT6226D) )
    #define MAX_CAM_FILE_BUFFER_LEN   (500*1024)    /* 500KB for 640x480 */
    #define MAX_CAM_CAP_INT_MEM_SIZE   (128*1024)   /* 1600x1200 */
    #define MAX_CAM_CAP_EXT_MEM_SIZE   (0)
    #define MAX_CAM_ENC_IMG_FILE_BUF_LEN (150*1024)
    #define MAX_CAM_CAP_DIGITAL_ZOOM_WORKING_BUF_SIZE (0)
#elif ( defined(MT6219) || defined(MT6226M)  )
    #define MAX_CAM_FILE_BUFFER_LEN   (750*1024)    /* 750KB for 1.3M */
    #define MAX_CAM_CAP_INT_MEM_SIZE   (128*1024)   /* 1600x1200 */
    #define MAX_CAM_CAP_EXT_MEM_SIZE   (0)
    #define MAX_CAM_ENC_IMG_FILE_BUF_LEN (150*1024)
    #define MAX_CAM_CAP_DIGITAL_ZOOM_WORKING_BUF_SIZE (0)
#elif (defined(MT6227)|| defined(MT6227D))
    #define MAX_CAM_FILE_BUFFER_LEN   (1000*1024)   /* 1000KB for 1600x1200 */
    #define MAX_CAM_CAP_INT_MEM_SIZE   (128*1024)   /* 1600x1200 */
    #define MAX_CAM_CAP_EXT_MEM_SIZE   (0)
    #define MAX_CAM_ENC_IMG_FILE_BUF_LEN (150*1024)
    #define MAX_CAM_CAP_DIGITAL_ZOOM_WORKING_BUF_SIZE (0)
#elif defined(MT6238) 
    #define MAX_CAM_FILE_BUFFER_LEN   (2048*1024)   /* 1536KB for 3M */
    #if defined(MT6238_PRES00) /* E2 version */
    #define MAX_CAM_CAP_INT_MEM_SIZE   (94*1024)
    #else
    #define MAX_CAM_CAP_INT_MEM_SIZE   (103*1024+512)
    #endif
    #define MAX_CAM_CAP_EXT_MEM_SIZE   (0)
    #define MAX_CAM_ENC_IMG_FILE_BUF_LEN (200*1024)
    #define MAX_CAM_CAP_DIGITAL_ZOOM_WORKING_BUF_SIZE ((2048+4)* (1536+6))
#elif defined(MT6239)
    #define MAX_CAM_FILE_BUFFER_LEN   (3072*1024)   /* 2560KB for 5M */
    #if defined(MT6239_PRES00) /* E2 version */
    #define MAX_CAM_CAP_INT_MEM_SIZE   (94*1024)
    #else
    #define MAX_CAM_CAP_INT_MEM_SIZE   (103*1024+512)
    #endif
    #define MAX_CAM_CAP_EXT_MEM_SIZE   (0)
    #define MAX_CAM_ENC_IMG_FILE_BUF_LEN (200*1024)
    #define MAX_CAM_CAP_DIGITAL_ZOOM_WORKING_BUF_SIZE ((2592+4)* (1944+6))
#else /* MT6228, MT6229, ... */
/* 
 * it is a temp solution for this project. should be fixed before W08.16MP.
 **/
    #if defined(A7510_DEMO_BB)
        #define MAX_CAM_FILE_BUFFER_LEN   (750*1024)   /* 1500KB for 2048x1536  */
    #else
        #define MAX_CAM_FILE_BUFFER_LEN   (1536*1024)   /* 1500KB for 2048x1536  */
    #endif
    #define MAX_CAM_CAP_INT_MEM_SIZE   (126*1024)   /* 2048x1536 */
    #define MAX_CAM_CAP_EXT_MEM_SIZE   (0)
    #define MAX_CAM_ENC_IMG_FILE_BUF_LEN (150*1024)        /* File buffer size for JPG encode. */
    #define MAX_CAM_CAP_DIGITAL_ZOOM_WORKING_BUF_SIZE (0)
#endif 

    /* compare capture from isp and capture from layer */
    #if MAX_CAM_FILE_BUFFER_LEN > (MAX_CAM_ENC_IMG_FILE_BUF_LEN + (LCD_WIDTH*LCD_HEIGHT*2) + MAX_IMG_ENC_EXT_MEM_SIZE)
        #define MAX_MED_CAM_CAP_EXT_MEM_SIZE (MAX_CAM_FILE_BUFFER_LEN  + MAX_SW_JPG_YUV_BUFFER_SIZE + MAX_CAM_CAP_DIGITAL_ZOOM_WORKING_BUF_SIZE)
    #else 
        #define MAX_MED_CAM_CAP_EXT_MEM_SIZE (MAX_CAM_ENC_IMG_FILE_BUF_LEN + (LCD_WIDTH*LCD_HEIGHT*2) + MAX_IMG_ENC_EXT_MEM_SIZE + MAX_SW_JPG_YUV_BUFFER_SIZE + MAX_CAM_CAP_DIGITAL_ZOOM_WORKING_BUF_SIZE)
    #endif


    #if MT6228_SERIES
        /* compare with BurstShot mode */
        #if MAX_MED_CAM_CAP_EXT_MEM_SIZE < (MAX_CAM_ENC_IMG_FILE_BUF_LEN * 9)
        #undef MAX_MED_CAM_CAP_EXT_MEM_SIZE
        #define MAX_MED_CAM_CAP_EXT_MEM_SIZE (MAX_CAM_ENC_IMG_FILE_BUF_LEN * 9)
        #endif
    #elif MT6238_SERIES
        /* compare with BestShotSelect mode */
        #if MAX_MED_CAM_CAP_EXT_MEM_SIZE < (MAX_CAM_FILE_BUFFER_LEN * 2 + MAX_CAM_CAP_DIGITAL_ZOOM_WORKING_BUF_SIZE)
        #undef MAX_MED_CAM_CAP_EXT_MEM_SIZE
        #define MAX_MED_CAM_CAP_EXT_MEM_SIZE (MAX_CAM_FILE_BUFFER_LEN * 2 + MAX_CAM_CAP_DIGITAL_ZOOM_WORKING_BUF_SIZE)
        #endif
    #endif

    #define MAX_MED_CAM_CAP_INT_MEM_SIZE MAX_CAM_CAP_INT_MEM_SIZE
    
#else /* no ISP */

#define MAX_CAM_FILE_BUFFER_LEN   (0)   /* Image file buffer size for camera capture */
#define MAX_CAM_CAP_INT_MEM_SIZE  (0)   /* 1600x1200 */
#define MAX_CAM_CAP_EXT_MEM_SIZE  (0)

#define MAX_MED_CAM_CAP_EXT_MEM_SIZE (0)
#define MAX_MED_CAM_CAP_INT_MEM_SIZE (0)

#endif


/**************************************************************
 * 8. MUST Put at the LAST. Java Shares Media External Buffer
 **************************************************************/
#if defined(__J2ME__) && defined(J2ME_SHARE_MED_EXT_MEM)
/* List concurrent features with Java */
#define MAX_J2ME_EXT_MEM_SIZE (DEFAULTHEAPSIZE + MAX_MED_JPG_DEC_EXT_MEM_SIZE + AUD_EXT_MEM_SIZE)
#else
#define MAX_J2ME_EXT_MEM_SIZE (0)
#endif

/**************************************************************
 * 9. MMS Resize image
 **************************************************************/
#if defined (MMS_SUPPORT)
#include "mmi_features.h"
#if defined(__MMI_MMS_MAX_IMAGE_RESIZING_RESOLUTION__) && (__MMI_MMS_MAX_IMAGE_RESIZING_RESOLUTION__ == __160x120__)
    #define MMS_RESIZE_BUF_SIZE (160*120*2)
    #if defined(__SW_JPEG_CODEC_SUPPORT__)
        #define MMS_ENCODE_YUV_SIZE (160*120*3/2)
    #else
        #define MMS_ENCODE_YUV_SIZE (0)
    #endif
#elif defined(__MMI_MMS_MAX_IMAGE_RESIZING_RESOLUTION__) && (__MMI_MMS_MAX_IMAGE_RESIZING_RESOLUTION__ == __320x240__)
    #define MMS_RESIZE_BUF_SIZE (320*240*2)
    #if defined(__SW_JPEG_CODEC_SUPPORT__)
        #define MMS_ENCODE_YUV_SIZE (320*240*3/2)
    #else
        #define MMS_ENCODE_YUV_SIZE (0)
    #endif
#else /* default: __640x480__ */
    #define MMS_RESIZE_BUF_SIZE (640*480*2)
    #if defined(__SW_JPEG_CODEC_SUPPORT__)
        #define MMS_ENCODE_YUV_SIZE (640*480*3/2)
    #else
        #define MMS_ENCODE_YUV_SIZE (0)
    #endif
#endif

    #define MMS_ENC_EXT_MEM_SIZE (MAX_IMG_ENC_EXT_MEM_SIZE+MAX_IMG_ENC_FILE_BUFFER_LEN+MMS_ENCODE_YUV_SIZE)
    
    #if MAX_MED_JPG_DEC_EXT_MEM_SIZE > MMS_ENC_EXT_MEM_SIZE
        #define MAX_MMS_RESIZE_IMAGE_BUF_SIZE (MMS_RESIZE_BUF_SIZE + MAX_MED_JPG_DEC_EXT_MEM_SIZE)
    #else
        #define MAX_MMS_RESIZE_IMAGE_BUF_SIZE (MMS_RESIZE_BUF_SIZE + MMS_ENC_EXT_MEM_SIZE)
    #endif
#else
#define MAX_MMS_RESIZE_IMAGE_BUF_SIZE (0)
#endif


/**************************************************************
 * 10. M3D 
 **************************************************************/
#if defined(M3D_SUPPORT)
    #if defined(MMI_MAIN_LCD_DEFAULT_FORMAT)
        #if (MMI_MAIN_LCD_DEFAULT_FORMAT == 24)
        #define M3D_BYTE_PER_PIXEL 3
        #define M3D_ONLY_SUPPORT_16BIT_BUFFER_SIZE (LCD_HEIGHT * LCD_HEIGHT* 3) 
        #elif (MMI_MAIN_LCD_DEFAULT_FORMAT == 32)
        #define M3D_BYTE_PER_PIXEL 4
        #define M3D_ONLY_SUPPORT_16BIT_BUFFER_SIZE (LCD_HEIGHT * LCD_HEIGHT* 4) 
        #elif (MMI_MAIN_LCD_DEFAULT_FORMAT == 16)
        #define M3D_BYTE_PER_PIXEL 2
        #define M3D_ONLY_SUPPORT_16BIT_BUFFER_SIZE 0
        #else
        #error "please check MMI_MAIN_LCD_DEFAULT_FORMAT value"
        #endif
    #else
    #define M3D_BYTE_PER_PIXEL 2
    #define M3D_ONLY_SUPPORT_16BIT_BUFFER_SIZE 0
    #endif

    #define M3D_GL_MEM_SIZE (5 * LCD_WIDTH * LCD_HEIGHT + 140*1024 /* sizeof(GLcontext) */ + 10 * 1024 + 4*256*256*3/* Texture */ )
    #define M3D_MEM_SIZE (LCD_HEIGHT * LCD_WIDTH * M3D_BYTE_PER_PIXEL + 450*1024 /* PARSER POOL */)

    #define MAX_M3D_TOTAL_MEM_SIZE (M3D_ONLY_SUPPORT_16BIT_BUFFER_SIZE+M3D_GL_MEM_SIZE+M3D_MEM_SIZE)
#else
    #define MAX_M3D_TOTAL_MEM_SIZE (0)
#endif


#if defined(SVG12_SUPPORT)
#define MAX_IMG_SVG12_WORKING_BUFFER_SIZE (2000*1024)
#else
#define MAX_IMG_SVG12_WORKING_BUFFER_SIZE (0)
#endif

#if MAX_M3D_TOTAL_MEM_SIZE > MAX_IMG_SVG12_WORKING_BUFFER_SIZE
    #define MAX_M3D_EXT_MEM_SIZE (MAX_M3D_TOTAL_MEM_SIZE)
#else
    #define MAX_M3D_EXT_MEM_SIZE (MAX_IMG_SVG12_WORKING_BUFFER_SIZE)
#endif
/**************************************************************
 * 11. Streaming 
 **************************************************************/
#if defined(STREAM_SUPPORT)

    #if defined(DRV_IDP_6238_SERIES)
      /* use idp rotate to eliminate tearing effect for horizontal playback  on MT6238 */
    	#if defined(TV_OUT_SUPPORT)
    	  /* require additional buffer for idp, worstcase == 320*480* 2 */  
	    #define STREAM_VP7_BUFFER_SIZE (320*480*2)     /* 320x480 (RGP565 buffer) */		    
	    #define MAX_STREAMING_EXT_MEM_SIZE (MAX_VID_DEC_EXT_MEM_SIZE + 216*1024 + STREAM_VP7_BUFFER_SIZE * 2)
	#else /* TV_OUT_SUPPORT */
        /* require additional buffer for idp, worstcase == LCD_WIDTH * LCD_HEIGHT * colorformat */
        /* 216K: AUDIO DL BUFFER */
	    #define MAX_STREAMING_EXT_MEM_SIZE (MAX_VID_DEC_EXT_MEM_SIZE + 216*1024 + LCD_WIDTH*LCD_HEIGHT*2)
	#endif /* TV_OUT_SUPPORT */
    #else
        #define MAX_STREAMING_EXT_MEM_SIZE (MAX_VID_DEC_EXT_MEM_SIZE + 216*1024 /* 216K: AUDIO DL BUFFER */)
    #endif
    
#else
#define MAX_STREAMING_EXT_MEM_SIZE (0)
#endif

/**************************************************************
 * 12. 3D game 
 **************************************************************/
#if defined(GAME_ENGINE)
#define MAX_3D_GAME_EXT_MEM_SIZE (1200*1024)
#else
#define MAX_3D_GAME_EXT_MEM_SIZE (0)
#endif

/**************************************************************
 * 13. Barcode 
 **************************************************************/
#if defined(BARCODE_SUPPORT)
#define MAX_BARCODE_EXT_MEM_SIZE (LCD_WIDTH*LCD_HEIGHT*2 + 200*1024) 
#else
#define MAX_BARCODE_EXT_MEM_SIZE (0)
#endif


/**************************************************************
 * 14. VOIP
 **************************************************************/
#if defined(VOIP_SUPPORT)
#define MAX_VOIP_EXT_MEM_SIZE (100)
#else
#define MAX_VOIP_EXT_MEM_SIZE (0)
#endif


/**************************************************************
 * 15. TDMB
 **************************************************************/
#if defined(__TDMB_SUPPORT__)
#define TDMB_BG_RECORD_MEM_SIZE (1024*1024)
#define MAX_TDMB_EXT_MEM_SIZE (MAX_VID_DEC_EXT_MEM_SIZE + TDMB_BG_RECORD_MEM_SIZE)
#else
#define TDMB_BG_RECORD_MEM_SIZE (0)
#define MAX_TDMB_EXT_MEM_SIZE (0)
#endif


/**************************************************************
 * 15. FS SORT SUPPORT
 **************************************************************/
#if !defined(MED_MEM_CHECK)
#if defined(__FS_SORT_SUPPORT__)
#ifndef FS_SORT_MAX_ENTRY 
#error "FS_SORT_MAX_ENTRY should be defined"
#endif
#define MAX_FS_SORT_MEM_SIZE FS_SORT_WORKING_BUFFER_SIZE_FOR_FILES(FS_SORT_MAX_ENTRY) + FS_SORT_SORTING_BUFFER_SIZE_FOR_FILES(FS_SORT_MAX_ENTRY)
#else
#define MAX_FS_SORT_MEM_SIZE (0)
#endif
#else
#define MAX_FS_SORT_MEM_SIZE (0)
#endif

/**************************************************************
 * 16. Camera Preview with Face Detection
 **************************************************************/
#if defined(ISP_SUPPORT)
    #if defined(__MED_CAM_FD_SUPPORT__)
    #define MAX_CAM_FD_IMAGE_BUFFER_SIZE (160*120*2)
    #define MAX_CAM_FD_INT_MEM_SIZE (0)
    #define MAX_CAM_FD_EXT_MEM_SIZE (113*1024)
    #else
    #define MAX_CAM_FD_IMAGE_BUFFER_SIZE (0)
    #define MAX_CAM_FD_INT_MEM_SIZE (0)
    #define MAX_CAM_FD_EXT_MEM_SIZE (0)
    #endif

    #if MT6219_SERIES
    #define MAX_CAM_PREVIEW_INT_MEM_SIZE (3840)
    #elif MT6238_SERIES
        #if defined(MT6238_PRES00) || defined(MT6239_PRES00) /* E2 version */
            #define MAX_CAM_PREVIEW_INT_MEM_SIZE (95*1024+512)
        #else
            #define MAX_CAM_PREVIEW_INT_MEM_SIZE (103*1024+512)
        #endif
    #else /* MT6219_SERIES */
    #define MAX_CAM_PREVIEW_INT_MEM_SIZE (46080)
    #endif /* MT6219_SERIES */

    #define MAX_CAM_PREVIEW_EXT_MEM_SIZE (0)    
#else
    #define MAX_CAM_PREVIEW_INT_MEM_SIZE (0)
    #define MAX_CAM_PREVIEW_EXT_MEM_SIZE (0)
    #define MAX_CAM_FD_IMAGE_BUFFER_SIZE (0)
    #define MAX_CAM_FD_INT_MEM_SIZE (0)
    #define MAX_CAM_FD_EXT_MEM_SIZE (0)
#endif

#define MAX_MED_CAM_PREVIEW_EXT_MEM_SIZE (MAX_CAM_PREVIEW_EXT_MEM_SIZE + MAX_CAM_FD_IMAGE_BUFFER_SIZE * 2 + MAX_CAM_FD_EXT_MEM_SIZE)
#define MAX_MED_CAM_PREVIEW_INT_MEM_SIZE (MAX_CAM_PREVIEW_INT_MEM_SIZE + MAX_CAM_FD_INT_MEM_SIZE)

/* Vogins Start */
/**************************************************************
 * 17. VRE(CVM) 
 **************************************************************/
#if (defined(__VRE__) && defined(__VRE_MEDIA_BUF__))
    #include "vmopt.h"
    #define MAX_VRE_EXT_MEM_SIZE    (VRE_SYS_MEMPOOL_SIZE)//(800*1024)
#else
    #define MAX_VRE_EXT_MEM_SIZE    (0)
#endif
/* Vogins End */

/**************************************************************
 * Internal Ram
 * 1. DEDI AMR REC.
 **************************************************************/
#if defined(DEDI_AMR_REC_BUFFER) 
#define MAX_DEDI_AMR_REC_BUFFER (6108)
#else
#define MAX_DEDI_AMR_REC_BUFFER (0)
#endif

#define MAX_PROG_JPG_DEC_EXT_MEM_SIZE   (MAX_CAM_FILE_BUFFER_LEN+MAX_IMG_DEC_EXT_MEM_SIZE-AUD_MELODY_BUFFER_LEN-MAX_IMG_DEC_FILE_BUFFER_LEN)


#include "med_mem.h"

/*==== MACROS ========*/

#ifdef PRODUCTION_RELEASE
#define MED_FUNC_ENTRY(X)
#define MED_MEM_INFO(v,w,x,y,z)
#define MED_FREE_MEM_INFO(x,y,z)
#define MED_MEM_FRAGMENTATION(x,y,z,a)
#define MED_MEM_CONCURRENT(x,y,z,a) 
#define MED_MEM_INFO_INT(v,w,x,y,z)    
#define MED_FREE_MEM_INFO_INT(x,y,z)   
#define MED_MEM_FRAGMENTATION_INT(x,y,z,a)
#define MED_MEM_CONCURRENT_INT(x,y,z,a)
#else /* PRODUCTION_RELEASE */ 
#define __AUD_TRACE_ON__
#define __CAM_TRACE_ON__
#define __IMG_TRACE_ON__
#define __VID_TRACE_ON__
#define __CTM_TRACE_ON__
#define __WEBCAM_TRACE_ON__
#define __TVO_TRACE_ON__
#define __BT_A2DP_TRACE_ON__
#define __BT_HFP_TRACE_ON__
#define __RTP_TRACE_ON__
#define __STREAM_TRACE_ON__
#define __MTV_TRACE_ON__
#define __VCALL_TRACE_ON__

#define MED_FUNC_ENTRY(X)    kal_trace(TRACE_FUNC, X);
#define MED_MEM_INFO(v,w,x,y,z)    kal_trace(TRACE_INFO, MEM_INFO, v, w, x, y, z);
#define MED_FREE_MEM_INFO(x,y,z)   kal_trace(TRACE_INFO, FREE_MEM_INFO, x, y, z);
#define MED_MEM_FRAGMENTATION(x,y,z,a) kal_trace(TRACE_INFO, MEM_INFO_FRAGMENTATION, x, y, z, a);
#define MED_MEM_CONCURRENT(x,y,z,a) kal_trace(TRACE_INFO, MEM_INFO_CONCURRENT, x, y, z, a);
#define MED_MEM_INFO_INT(v,w,x,y,z)    kal_trace(TRACE_INFO, MEM_INFO_INT, v, w, x, y, z);
#define MED_FREE_MEM_INFO_INT(x,y,z)   kal_trace(TRACE_INFO, FREE_MEM_INFO_INT, x, y, z);
#define MED_MEM_FRAGMENTATION_INT(x,y,z,a) kal_trace(TRACE_INFO, MEM_INFO_FRAGMENTATION_INT, x, y, z, a);
#define MED_MEM_CONCURRENT_INT(x,y,z,a) kal_trace(TRACE_INFO, MEM_INFO_CONCURRENT_INT, x, y, z, a);
#endif /* PRODUCTION_RELEASE */ 

#ifdef __AUD_TRACE_ON__
#define AUD_FUNC_ENTRY(X)    kal_trace(TRACE_GROUP_1, X);
#define AUD_FUNC_ENTRY1(F, x)    kal_trace(TRACE_GROUP_1, F, x);
#define AUD_FUNC_ENTRY2(F, x, y)    kal_trace(TRACE_GROUP_1, F, x, y);
#define AUD_FUNC_ENTRY3(F, x, y, z)    kal_trace(TRACE_GROUP_1, F, x, y, z);
#define AUD_STATE_TRACE(s)    kal_trace(TRACE_STATE, AUD_STATE, s);
#define AUD_VALUE_TRACE(x,y,z)    kal_trace(TRACE_GROUP_1, AUD_CHECK_VALUE, x, y, z);
#define AUD_TRACE_VOLUME(x,y,z)    kal_trace(TRACE_GROUP_1, AUD_CHECK_VOLUME, x, y, z);
#define AUD_TRACE_PATH(x,y,z)    kal_trace(TRACE_GROUP_1, AUD_CHECK_PATH, x, y, z);
#define AUD_WAIT_EVT(x,y)        kal_trace(TRACE_GROUP_1, AUD_WAIT_EVT_TRC, x, y);
#define AUD_SET_EVT(x,y)        kal_trace(TRACE_GROUP_1, AUD_SET_EVT_TRC, x, y);
#define AUD_RESULT_TRACE(x,y,z)    kal_trace(TRACE_INFO, AUD_RESULT, x, y, z);
#else /* __AUD_TRACE_ON__ */ 
#define AUD_FUNC_ENTRY(X)
#define AUD_FUNC_ENTRY1(F, x)
#define AUD_FUNC_ENTRY2(F, x, y)
#define AUD_FUNC_ENTRY3(F, x, y, z)
#define AUD_STATE_TRACE(s)
#define AUD_VALUE_TRACE(x,y,z)
#define AUD_TRACE_VOLUME(x,y,z)
#define AUD_TRACE_PATH(x,y,z)
#define AUD_WAIT_EVT(x,y)
#define AUD_SET_EVT(x,y)
#define AUD_RESULT_TRACE(x,y,z)
#endif /* __AUD_TRACE_ON__ */ 

#ifdef __CAM_TRACE_ON__
#define CAM_FUNC_ENTRY(X)    kal_trace(TRACE_GROUP_2, X);
#define CAM_STATE_TRACE(s)    kal_trace(TRACE_STATE, CAM_STATE, s);
#define CAM_VALUE_TRACE(x,y,z)    kal_trace(TRACE_GROUP_2, CAM_CHECK_VALUE, x, y, z);
#define CAM_WAIT_EVT(x,y)        kal_trace(TRACE_GROUP_2, CAM_WAIT_EVT_TRC, x, y);
#define CAM_SET_EVT(x,y)        kal_trace(TRACE_GROUP_2, CAM_SET_EVT_TRC, x, y);
#define CAM_RESULT_TRACE(x,y,z)    kal_trace(TRACE_INFO, CAM_RESULT, x, y, z);
#define CAM_BUFFER_TRACE(x)     kal_trace(TRACE_INFO,CAM_BUFFER,x);
#define CAM_QR_RESULT_TRACE(x)  kal_trace(TRACE_INFO,CAM_QR_RESULT,x);
#define CAM_CLOSE_IMAGE_RESULT_TRACE(x) kal_trace(TRACE_INFO,CAM_CLOSE_IMG_RESULT,x);
#else /* __CAM_TRACE_ON__ */ 
#define CAM_FUNC_ENTRY(X)
#define CAM_STATE_TRACE(s)
#define CAM_VALUE_TRACE(x,y,z)
#define CAM_WAIT_EVT(x,y)
#define CAM_SET_EVT(x,y)
#define CAM_RESULT_TRACE(x,y,z)
#define CAM_BUFFER_TRACE(x)     
#define CAM_QR_RESULT_TRACE(x)  
#define CAM_CLOSE_IMAGE_RESULT_TRACE(x) 
#endif /* __CAM_TRACE_ON__ */ 

#ifdef __IMG_TRACE_ON__
#define IMG_FUNC_ENTRY(X)    kal_trace(TRACE_GROUP_3, X);
#define IMG_STATE_TRACE(s)    kal_trace(TRACE_STATE, IMG_STATE, s);
#define IMG_VALUE_TRACE(x,y,z)    kal_trace(TRACE_GROUP_3, IMG_CHECK_VALUE, x, y, z);
#define IMG_WAIT_EVT(x,y)        kal_trace(TRACE_GROUP_3, IMG_WAIT_EVT_TRC, x, y);
#define IMG_SET_EVT(x,y)        kal_trace(TRACE_GROUP_3, IMG_SET_EVT_TRC, x, y);
#define IMG_RESULT_TRACE(x,y,z)    kal_trace(TRACE_INFO, IMG_RESULT, x, y, z);
#else /* __IMG_TRACE_ON__ */ 
#define IMG_FUNC_ENTRY(X)
#define IMG_STATE_TRACE(s)
#define IMG_VALUE_TRACE(x,y,z)
#define IMG_WAIT_EVT(x,y)
#define IMG_SET_EVT(x,y)
#define IMG_RESULT_TRACE(x,y,z)
#endif /* __IMG_TRACE_ON__ */ 

#ifdef __VID_TRACE_ON__
#define VID_FUNC_ENTRY(X)    kal_trace(TRACE_GROUP_4, X);
#define VID_STATE_TRACE(s)    kal_trace(TRACE_STATE, VID_STATE, s);
#define VID_VALUE_TRACE(x,y,z)    kal_trace(TRACE_GROUP_4, VID_CHECK_VALUE, x, y, z);
#define VID_FILE_TRACE(a,b,c,d,e,f)    kal_trace(TRACE_GROUP_4, VID_FILE_INFO, a, b, c, d, e, f);
#define VID_VIS_ERROR_TRACE(x,y)    {kal_trace(TRACE_INFO, VID_VIS_ERROR, x, y);                          \
                                                               { kal_uint32 d1, d2, d3, d4, d5;           \
                                                                  VIDEO_DbgInfo(&d1, &d2, &d3, &d4, &d5); \
                                                                  kal_trace(TRACE_INFO, VID_VIS_DBG_INFO, d1, d2, d3, d4, d5, __LINE__);}}
#define VID_AUD_ERROR_TRACE(x,y)    kal_trace(TRACE_INFO, VID_AUD_ERROR, x, y);
#define VID_PARSE_ERROR_TRACE(x,y)    {kal_trace(TRACE_INFO, VID_PARSE_ERROR, x, y);                      \
                                                               { kal_uint32 d1, d2, d3, d4, d5;           \
                                                                  VIDEO_DbgInfo(&d1, &d2, &d3, &d4, &d5); \
                                                                  kal_trace(TRACE_INFO, VID_VIS_DBG_INFO, d1, d2, d3, d4, d5, __LINE__);}}
#define VID_FSAL_ERROR_TRACE(x,y)    {kal_trace(TRACE_INFO, VID_FSAL_ERROR, x, y);                        \
                                                               { kal_uint32 d1, d2, d3, d4, d5;           \
                                                                  VIDEO_DbgInfo(&d1, &d2, &d3, &d4, &d5); \
                                                                  kal_trace(TRACE_INFO, VID_VIS_DBG_INFO, d1, d2, d3, d4, d5, __LINE__);}}
#define VID_RESULT_TRACE(x,y,z)    kal_trace(TRACE_INFO, VID_RESULT, x, y, z);
#define VID_WAIT_EVT(x,y)        kal_trace(TRACE_GROUP_4, VID_WAIT_EVT_TRC, x, y);
#define VID_SET_EVT(x,y)        kal_trace(TRACE_GROUP_4, VID_SET_EVT_TRC, x, y);
#else /* __VID_TRACE_ON__ */ 
#define VID_FUNC_ENTRY(X)
#define VID_STATE_TRACE(s)
#define VID_VALUE_TRACE(x,y,z)
#define VID_FILE_TRACE(a,b,c,d,e,f)
#define VID_VIS_ERROR_TRACE(x,y)
#define VID_AUD_ERROR_TRACE(x,y)
#define VID_PARSE_ERROR_TRACE(x,y)
#define VID_FSAL_ERROR_TRACE(x,y)
#define VID_RESULT_TRACE(x,y,z)
#define VID_WAIT_EVT(x,y)
#define VID_SET_EVT(x,y)
#endif /* __VID_TRACE_ON__ */ 

#ifdef __WEBCAM_TRACE_ON__
#define WEBCAM_FUNC_ENTRY(X)    kal_trace(TRACE_GROUP_6, X);
#define WEBCAM_STATE_TRACE(s)    kal_trace(TRACE_STATE, WEBCAM_STATE, s);
#define WEBCAM_VALUE_TRACE(x,y,z)    kal_trace(TRACE_GROUP_6, WEBCAM_CHECK_VALUE, x, y, z);
#define WEBCAM_WAIT_EVT(x,y)        kal_trace(TRACE_GROUP_6, WEBCAM_WAIT_EVT_TRC, x, y);
#define WEBCAM_SET_EVT(x,y)        kal_trace(TRACE_GROUP_6, WEBCAM_SET_EVT_TRC, x, y);
#define WEBCAM_RESULT_TRACE(x,y,z)    kal_trace(TRACE_INFO, WEBCAM_RESULT, x, y, z);
#else /* __WEBCAM_TRACE_ON__ */ 
#define WEBCAM_FUNC_ENTRY(X)
#define WEBCAM_STATE_TRACE(s)
#define WEBCAM_VALUE_TRACE(x,y,z)
#define WEBCAM_WAIT_EVT(x,y)
#define WEBCAM_SET_EVT(x,y)
#define WEBCAM_RESULT_TRACE(x,y,z)
#endif /* __WEBCAM_TRACE_ON__ */ 

#ifdef __TVO_TRACE_ON__
#define TVO_FUNC_ENTRY(X)    kal_trace(TRACE_GROUP_5, X);
#define TVO_STATE_TRACE(s)    kal_trace(TRACE_STATE, TVO_STATE, s);
#define TVO_VALUE_TRACE(x,y,z)    kal_trace(TRACE_GROUP_5, TVO_CHECK_VALUE, x, y, z);
#define TVO_WAIT_EVT(x,y)        kal_trace(TRACE_GROUP_5, TVO_WAIT_EVT_TRC, x, y);
#define TVO_SET_EVT(x,y)        kal_trace(TRACE_GROUP_5, TVO_SET_EVT_TRC, x, y);
#define TVO_RESULT_TRACE(x,y,z)    kal_trace(TRACE_INFO, TVO_RESULT, x, y, z);
#else /* __TVO_TRACE_ON__ */ 
#define TVO_FUNC_ENTRY(X)
#define TVO_STATE_TRACE(s)
#define TVO_VALUE_TRACE(x,y,z)
#define TVO_WAIT_EVT(x,y)
#define TVO_SET_EVT(x,y)
#define TVO_RESULT_TRACE(x,y,z)
#endif /* __TVO_TRACE_ON__ */ 

#ifdef __CTM_TRACE_ON__
#define CTM_FUNC_ENTRY(X)    kal_trace(TRACE_GROUP_1, X);
#define CTM_STATE_TRACE(s)    kal_trace(TRACE_STATE, CTM_STATE, s);
#define CTM_VALUE_TRACE(x)    kal_trace(TRACE_GROUP_1, CTM_CHECK_VALUE, x);
#define CTM_VALUES_TRACE(x,y,z)    kal_trace(TRACE_GROUP_1, CTM_CHECK_VALUES, x, y, z);
#define CTM_READ_TEXT_TRACE1(x,y,z)    kal_trace(TRACE_GROUP_1, CTM_CHECK_READ_TEXT_STEP_1, x, y, z);
#define CTM_READ_TEXT_TRACE2(x,y,z)    kal_trace(TRACE_GROUP_1, CTM_CHECK_READ_TEXT_STEP_2, x, y, z);
#else /* __CTM_TRACE_ON__ */ 
#define CTM_FUNC_ENTRY(X)
#define CTM_STATE_TRACE(s)
#define CTM_VALUE_TRACE(x)
#define CTM_VALUES_TRACE(x,y,z)
#define CTM_READ_TEXT_TRACE1(x,y,z)
#define CTM_READ_TEXT_TRACE2(x,y,z)
#endif /* __CTM_TRACE_ON__ */ 

#ifdef __BT_A2DP_TRACE_ON__
#define AUD_BT_A2DP_FUNC_ENTRY(X)    kal_trace(TRACE_GROUP_1, X);
#define AUD_BT_A2DP_FUNC_ENTRY1(F, x)    kal_trace(TRACE_GROUP_1, F, x);
#define AUD_BT_A2DP_FUNC_ENTRY2(F, x, y)    kal_trace(TRACE_GROUP_1, F, x, y);
#define AUD_BT_A2DP_STATE_TRACE(s)    kal_trace(TRACE_STATE, AUD_BT_A2DP_STATE, s);
#define AUD_BT_A2DP_VALUE_TRACE(x,y,z)    kal_trace(TRACE_GROUP_1, AUD_BT_A2DP_CHECK_VALUE, x, y, z);
#define AUD_BT_A2DP_FUNC_TRACE1(F,x)    kal_trace(TRACE_GROUP_1, F,x);
#define AUD_BT_A2DP_FUNC_TRACE2(F,x,y)    kal_trace(TRACE_GROUP_1, F,x,y);
#define AUD_BT_A2DP_FUNC_TRACE3(F,x,y,z)    kal_trace(TRACE_GROUP_1, F,x,y,z);
#else /* __BT_A2DP_TRACE_ON__ */ 
#define AUD_BT_A2DP_FUNC_ENTRY(X)
#define AUD_BT_A2DP_FUNC_ENTRY1(F,x)
#define AUD_BT_A2DP_FUNC_ENTRY2(F,x,y)
#define AUD_BT_A2DP_STATE_TRACE(s)
#define AUD_BT_A2DP_VALUE_TRACE(x,y,z)
#define AUD_BT_A2DP_FUNC_TRACE1(F,x)
#define AUD_BT_A2DP_FUNC_TRACE2(F,x,y)
#define AUD_BT_A2DP_FUNC_TRACE3(F,x,y,z)
#endif /* __BT_A2DP_TRACE_ON__ */ 

#ifdef __BT_HFP_TRACE_ON__
#define AUD_BT_HFP_FUNC_ENTRY(X)    kal_trace(TRACE_GROUP_1, X);
#define AUD_BT_HFP_FUNC_ENTRY1(F, x)    kal_trace(TRACE_GROUP_1, F, x);
#define AUD_BT_HFP_FUNC_ENTRY2(F, x, y)    kal_trace(TRACE_GROUP_1, F, x, y);
#define AUD_BT_HFP_FUNC_ENTRY3(F, x, y, z)    kal_trace(TRACE_GROUP_1, F, x, y, z);
#define AUD_BT_HFP_STATE_TRACE(s)    kal_trace(TRACE_STATE, AUD_BT_HFP_STATE, s);
#define AUD_BT_HFP_VALUE_TRACE(x,y,z)    kal_trace(TRACE_GROUP_1, AUD_BT_HFP_CHECK_VALUE, x, y, z);
#define AUD_BT_HFP_FUNC_TRACE1(F,x)    kal_trace(TRACE_GROUP_1, F,x);
#define AUD_BT_HFP_FUNC_TRACE2(F,x,y)    kal_trace(TRACE_GROUP_1, F,x,y);
#define AUD_BT_HFP_FUNC_TRACE3(F,x,y,z)    kal_trace(TRACE_GROUP_1, F,x,y,z);
#else /* __BT_HFP_TRACE_ON__ */ 
#define AUD_BT_HFP_FUNC_ENTRY(X)
#define AUD_BT_HFP_FUNC_ENTRY1(F,x)
#define AUD_BT_HFP_FUNC_ENTRY2(F,x,y)
#define AUD_BT_HFP_FUNC_ENTRY3(F, x, y, z)
#define AUD_BT_HFP_STATE_TRACE(s)
#define AUD_BT_HFP_VALUE_TRACE(x,y,z)
#define AUD_BT_HFP_FUNC_TRACE1(F,x)
#define AUD_BT_HFP_FUNC_TRACE2(F,x,y)
#define AUD_BT_HFP_FUNC_TRACE3(F,x,y,z)
#endif /* __BT_HFP_TRACE_ON__ */ 

#ifdef __RTP_TRACE_ON__
#define RTP_RETURN_TRACE(x)                     kal_trace(TRACE_GROUP_1, RTP_CHECK_RETURN, x)
#define RTP_VALUE_TRACE(x)                      kal_trace(TRACE_GROUP_1, RTP_CHECK_VALUE, x)
#define RTP_VALUES_TRACE(x,y,z)                 kal_trace(TRACE_GROUP_1, RTP_CHECK_VALUES, x, y, z)
#define RTP_GET_VALUE_TRACE(x,y)                kal_trace(TRACE_GROUP_1, RTP_CHECK_RTP_GET_VALUE, x, y)
#define RTP_CODEC_TRACE(a,b,c,d,e,f,g,h,i,j)    kal_trace(TRACE_GROUP_1, RTP_CHECK_CODEC, a, b, c, d, e, f, g, h, i, j)
#define RTP_PTIME_TRACE(x,y)                    kal_trace(TRACE_GROUP_1, RTP_CHECK_PTIME_MAXPTIME, x, y)
#define RTP_IDLE_TRACE                          kal_trace(TRACE_GROUP_1, RTP_CHECK_IDLE)
#define RTP_ENCODING_TRACE                      kal_trace(TRACE_GROUP_1, RTP_CHECK_ENCODE)
#define RTP_DECODING_TRACE                      kal_trace(TRACE_GROUP_1, RTP_CHECK_DECODE)
#define RTP_ENDECODING_TRACE                    kal_trace(TRACE_GROUP_1, RTP_CHECK_ENDECODE)
#define RTP_DATA_LOST_TRACE(x)                  kal_trace(TRACE_GROUP_1, RTP_ERROR_PACKET_LOST, x)
#define RTP_DATA_SEND_TRACE(x,y)                kal_trace(TRACE_GROUP_1, RTP_CHECK_SENT_PACKET, x, y)
#define RTP_DATA_RECV_TRACE(x,y)                kal_trace(TRACE_GROUP_1, RTP_CHECK_RECV_PACKET, x, y)
#define RTP_DATA_PLAY_TRACE(x,y,z)              kal_trace(TRACE_GROUP_1, RTP_CHECK_PLAY_PACKET, x, y, z)
#define RTP_DATA_RECORD_TRACE(x)                kal_trace(TRACE_GROUP_1, RTP_CHECK_RECORD_PACKET, x)
#else /* __RTP_TRACE_ON__ */ 
#define RTP_RETURN_TRACE(x)
#define RTP_VALUE_TRACE(x)
#define RTP_VALUES_TRACE(x,y,z)
#define RTP_GET_VALUE_TRACE(x,y)
#define RTP_CODEC_TRACE(a,b,c,d,e,f,g,h,i,j)
#define RTP_PTIME_TRACE(x,y)
#define RTP_IDLE_TRACE
#define RTP_ENCODING_TRACE
#define RTP_DECODING_TRACE
#define RTP_ENDECODING_TRACE
#define RTP_DATA_LOST_TRACE(x)
#define RTP_DATA_SEND_TRACE(x,y)
#define RTP_DATA_RECV_TRACE(x,y)
#define RTP_DATA_PLAY_TRACE(x,y,z)
#define RTP_DATA_RECORD_TRACE(x)
#endif /* __RTP_TRACE_ON__ */ 

#ifdef __STREAM_TRACE_ON__
#define STREAM_RETURN_TRACE(x)                      kal_trace(TRACE_GROUP_1, STREAM_CHECK_RETURN, x)
#define STREAM_VALUE_TRACE(x)                       kal_trace(TRACE_GROUP_1, STREAM_CHECK_VALUE, x)
#define STREAM_VALUES_TRACE(x,y,z)                  kal_trace(TRACE_GROUP_1, STREAM_CHECK_VALUES, x, y, z)
#define STREAM_FUNC_LOG(TAG)                        kal_trace(TRACE_FUNC, TAG)
#define STREAM_FUNC_LOG2(TAG,VAR)                   kal_trace(TRACE_FUNC, TAG, VAR)
#define STREAM_FUNC_LOG3(TAG,VAR1,VAR2)             kal_trace(TRACE_FUNC, TAG, VAR1,VAR2)
#define STREAM_FUNC_LOG4(TAG, VAR1, VAR2, VAR3)     kal_trace(TRACE_FUNC, TAG, VAR1, VAR2, VAR3)
#define STREAM_STATE_LOG(TAG, VAR)                  kal_trace(TRACE_STATE, TAG, VAR)
#define STREAM_INFO_LOG(TAG)                        kal_trace(TRACE_INFO, TAG)
#define STREAM_INFO_LOG2(TAG, VAR)                  kal_trace(TRACE_INFO, TAG, VAR)
#define STREAM_INFO_LOG3(TAG,VAR1,VAR2)             kal_trace(TRACE_FUNC, TAG, VAR1,VAR2)
#define STREAM_INFO_LOG4(TAG, VAR1, VAR2, VAR3)     kal_trace(TRACE_INFO, TAG, VAR1, VAR2, VAR3)
#define STREAM_INFO_LOG5(TAG, A, B, C, D)           kal_trace(TRACE_INFO, TAG, A, B, C, D)
#define STREAM_INFO_LOG6(TAG, A, B, C, D, E)        kal_trace(TRACE_INFO, TAG, A, B, C, D, E)
#define STREAM_INFO_LOG7(TAG, A, B, C, D, E, F)     kal_trace(TRACE_INFO, TAG, A, B, C, D, E, F)
#define STREAM_INFO_LOG8(TAG, A, B, C, D, E, F, G)  kal_trace(TRACE_INFO, TAG, A, B, C, D, E, F, G)
#define STREAM_INFO_LOG9(TAG, A, B, C, D, E, F, G, H)  \
                                                    kal_trace(TRACE_INFO, TAG, A, B, C, D, E, F, G, H)
#define STREAM_INFO_LOG10(TAG, A, B, C, D, E, F, G, H, I)  \
                                                    kal_trace(TRACE_INFO, TAG, A, B, C, D, E, F, G, H, I)
#define STREAM_INFO_LOG11(TAG, A, B, C, D, E, F, G, H, I, J)  \
                                                    kal_trace(TRACE_INFO, TAG, A, B, C, D, E, F, G, H, I, J)
#define STREAM_INFO_LOG12(TAG, A, B, C, D, E, F, G, H, I, J, K)  \
                                                    kal_trace(TRACE_INFO, TAG, A, B, C, D, E, F, G, H, I, J, K)
#define STREAM_INFO_LOG13(TAG, A, B, C, D, E, F, G, H, I, J, K, L)  \
                                                    kal_trace(TRACE_INFO, TAG, A, B, C, D, E, F, G, H, I, J, K, L)
#define STREAM_INFO_LOG14(TAG, A, B, C, D, E, F, G, H, I, J, K, L, M)  \
                                                    kal_trace(TRACE_INFO, TAG, A, B, C, D, E, F, G, H, I, J, K, L, M)
#define STREAM_INFO_LOG15(TAG, A, B, C, D, E, F, G, H, I, J, K, L, M, N)  \
                                                    kal_trace(TRACE_INFO, TAG, A, B, C, D, E, F, G, H, I, J, K, L, M, N)

#define STREAM_WARNING_LOG(TAG)                     kal_trace(TRACE_WARNING, TAG)
#define STREAM_WARNING_LOG2(TAG, VAR)               kal_trace(TRACE_WARNING, TAG, VAR)
#define STREAM_ERROR_LOG(TAG)                       kal_trace(TRACE_ERROR, TAG)
#define STREAM_ERROR_LOG2(TAG, VAR)                 kal_trace(TRACE_ERROR, TAG, VAR)
#define STREAM_ERROR_LOG3(TAG, VAR1,VAR2)           kal_trace(TRACE_ERROR, TAG, VAR1,VAR2)
#define STREAM_PROMPT_TRACE(x)                      kal_prompt_trace(MOD_MED,"%s,%d:%s",__FILE__,__LINE__,x)
#else /* __STREAM_TRACE_ON__ */ 
#define STREAM_RETURN_TRACE(x)
#define STREAM_VALUE_TRACE(x)
#define STREAM_VALUES_TRACE(x,y,z)
#define STREAM_FUNC_LOG(TAG)
#define STREAM_FUNC_LOG2(TAG,VAR)
#define STREAM_FUNC_LOG3(TAG,VAR1,VAR2)
#define STREAM_FUNC_LOG4(TAG, VAR1, VAR2, VAR3)
#define STREAM_STATE_LOG(TAG, VAR)
#define STREAM_INFO_LOG(TAG)
#define STREAM_INFO_LOG2(TAG, VAR)
#define STREAM_INFO_LOG3(TAG,VAR1,VAR2)
#define STREAM_INFO_LOG4(TAG, VAR1, VAR2, VAR3)
#define STREAM_INFO_LOG5(TAG, A, B, C, D)
#define STREAM_INFO_LOG6(TAG, A, B, C, D, E)
#define STREAM_INFO_LOG7(TAG, A, B, C, D, E, F)
#define STREAM_INFO_LOG8(TAG, A, B, C, D, E, F, G)
#define STREAM_INFO_LOG9(TAG, A, B, C, D, E, F, G, H)
#define STREAM_INFO_LOG10(TAG, A, B, C, D, E, F, G, H, I)
#define STREAM_INFO_LOG11(TAG, A, B, C, D, E, F, G, H, I, J)
#define STREAM_INFO_LOG12(TAG, A, B, C, D, E, F, G, H, I, J, K)
#define STREAM_INFO_LOG13(TAG, A, B, C, D, E, F, G, H, I, J, K, L)
#define STREAM_INFO_LOG14(TAG, A, B, C, D, E, F, G, H, I, J, K, L, M)
#define STREAM_INFO_LOG15(TAG, A, B, C, D, E, F, G, H, I, J, K, L, M, N)
#define STREAM_WARNING_LOG(TAG)
#define STREAM_WARNING_LOG2(TAG, VAR)
#define STREAM_ERROR_LOG(TAG)
#define STREAM_ERROR_LOG2(TAG, VAR)
#define STREAM_ERROR_LOG3(TAG, VAR1,VAR2)
#define STREAM_PROMPT_TRACE(x)
#endif /* __STREAM_TRACE_ON__ */ 

#ifdef __MTV_TRACE_ON__
#define MTV_TRACE kal_trace
#else /* __MTV_TRACE_ON__ */ 
#define MTV_TRACE if (0) kal_trace
#endif /* __MTV_TRACE_ON__ */ 
#define MTV_TRACE_GROUP_DEMOD   TRACE_INFO
#define MTV_TRACE_GROUP_DEMUX   TRACE_INFO
#define MTV_TRACE_GROUP_BE      TRACE_INFO

#ifndef MAX
#define MAX(a,b) (a>b)? a:b
#endif 
#ifndef MIN
#define MIN(a,b) (a<b)? a:b
#endif 

/* audio */
#define AUD_ENTER_STATE(_s_) AUD_STATE_TRACE(_s_)\
                              (aud_context_p->state = _s_)

#define AUD_IN_STATE(_s_) (aud_context_p->state == _s_)
#ifdef __MED_CAM_MOD__
/* camera */
#define CAM_ENTER_STATE(_s_) CAM_STATE_TRACE(_s_)\
                              (cam_context_p->state = _s_)

#define CAM_IN_STATE(_s_) (cam_context_p->state == _s_)
    #if defined(__MED_CAM_FD_SUPPORT__)
    #define CAM_FD_IN_STATE(_s_) (cam_context_p->fd_state == _s_)
    #define CAM_FD_ENTER_STATE(_s_) (cam_context_p->fd_state = _s_)

    #endif
#endif /* __MED_CAM_MOD__ */ 

#ifdef __MED_IMG_MOD__
/* image */
#define IMG_ENTER_STATE(_s_) IMG_STATE_TRACE(_s_)\
                              (img_context_p->state = _s_)

#define IMG_IN_STATE(_s_) (img_context_p->state == _s_)
#endif /* __MED_IMG_MOD__ */ 

#if defined(__MED_VID_MOD__) || defined(__MED_MJPG_MOD__)

#define VID_ENTER_STATE(_s_)                                        \
do {                                                                \
    kal_trace(TRACE_STATE, VID_TRC_ENTER_VID_STATE, _s_, __LINE__); \
    vid_context_p->state = _s_;                                     \
    vid_debug_print_cur_state(__LINE__);                            \
} while(0);

#define VID_AUD_ENTER_STATE(_s_)                                    \
do {                                                                \
    kal_trace(TRACE_STATE, VID_TRC_ENTER_AUD_STATE, _s_, __LINE__); \
    vid_context_p->aud_state = _s_;                                 \
    vid_debug_print_cur_state(__LINE__);                            \
} while(0);

#define VID_IN_STATE(_s_)       (vid_context_p->state == _s_)
#define VID_AUD_IN_STATE(_s_)   (vid_context_p->aud_state == _s_)

#define VID_RETURN(_return_)                        \
do {                                                \
    med_debug_print_result(_return_, __LINE__);     \
    return _return_;                                \
} while(0);

#endif /* defined (__MED_VID_MOD__) || defined(__MED_MJPG_MOD__) */ 

#if defined (__MED_WEBCAM_MOD__)
/* web camera */
#define WEBCAM_ENTER_STATE(_s_)  WEBCAM_STATE_TRACE(_s_)\
                              (webcam_context_p->state = _s_)

#define WEBCAM_IN_STATE(_s_) (webcam_context_p->state == _s_)
#endif /* defined (__MED_WEBCAM_MOD__) */ 

#if defined (__MED_TVO_MOD__)
/* tv output */
#define TVO_ENTER_STATE(_s_)  (tvo_context_p->state = _s_)

#define TVO_IN_STATE(_s_) (tvo_context_p->state == _s_)
#endif /* defined (__MED_TVO_MOD__) */ 

#ifdef __MED_CTM_MOD__
#define CTM_ENTER_STATE(_s_)  do { CTM_STATE_TRACE(_s_) \
                  aud_ctm_ctx.state = (_s_); } while(0)
#endif /* __MED_CTM_MOD__ */ 

#ifdef __MED_BT_A2DP_MOD__
#define AUD_BT_A2DP_ENTER_STATE(_s_) AUD_BT_A2DP_STATE_TRACE(_s_)\
                  (aud_bt_a2dp_ctx.state = _s_)

#define AUD_BT_A2DP_IN_STATE(_s_) (aud_bt_a2dp_ctx.state == _s_)
#endif /* __MED_BT_A2DP_MOD__ */ 

#ifdef __MED_BT_HFP_MOD__
#define AUD_BT_HFP_ENTER_STATE(_s_) AUD_BT_HFP_STATE_TRACE(_s_)\
                  (aud_bt_hfp_ctx.state = _s_)

#define AUD_BT_HFP_IN_STATE(_s_) (aud_bt_hfp_ctx.state == _s_)
#endif /* __MED_BT_HFP_MOD__ */ 
/*==== TYPES =========*/

typedef enum
{
    AUD_MEDIA_PLAY_MODE_NONE,
    AUD_VM_PLAY_AS_RING,
    AUD_VM_PLAY_AS_MEMO,
    AUD_MEDIA_PLAY_AS_RING,
    AUD_MEDIA_PLAY_AS_SONG,
    NUM_OF_MEDIA_PLAY_MODE
}
aud_media_play_mode_enum;

typedef enum
{
    AUD_ID,
    AUD_FILE,
    AUD_STRING,
    AUD_FM_RADIO,
    AUD_TTS,
    AUD_UNKNOWN_SOURCE_TYPE
}
aud_source_type_enum;

typedef enum
{
    MED_NVRAM_IDLE,
    MED_POWERON_READING_NVRAM,
    MED_POWERON_READING_NVRAM_FINISH
}
med_nvram_state_enum;

typedef enum
{
    MMA_PLAYER_IMY = 0,
    MMA_PLAYER_SMF_1,
    MMA_PLAYER_SMF_2,
    MMA_PLAYER_SMF_3,
    MMA_PLAYER_SMF_4,
    MMA_PLAYER_TONE_S1,
    MMA_PLAYER_TONE_S2,
    MMA_PLAYER_TONE_S3,
    MMA_PLAYER_TONE_S4,
    MMA_PLAYER_WAV_1,
    MMA_PLAYER_WAV_2,
    MMA_PLAYER_WAV_3,
    MMA_PLAYER_SINGLE,
    MMA_NO_OF_PLAYER
}
mma_player_enum;

#endif /* _MED_GLOBAL_H */ 

#endif /* MED_NOT_PRESENT */ 

