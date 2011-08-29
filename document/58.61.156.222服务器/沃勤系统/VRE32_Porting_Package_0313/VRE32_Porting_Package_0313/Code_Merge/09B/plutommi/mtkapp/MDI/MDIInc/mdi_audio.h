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
 * mdi_audio.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Audio interfce header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MDI_AUDIO_H_
#define _MDI_AUDIO_H_

#ifndef _MDI_DATATYPE_H_
#error "Must include mdi_datatype.h before include this file"
#endif 

/* add for event type */
#include "custom_events_notify.h"

/* Audio volume level enum for 7 level volume */
typedef enum
{
    MDI_AUD_VOL_0,  /* Volume level 0 (Not mute) */
    MDI_AUD_VOL_1,  /* Volume level 1 */
    MDI_AUD_VOL_2,  /* Volume level 2 */
    MDI_AUD_VOL_3,  /* Volume level 3 */
    MDI_AUD_VOL_4,  /* Volume level 4 */
    MDI_AUD_VOL_5,  /* Volume level 5 */
    MDI_AUD_VOL_6,  /* Volume level 6 */
    MDI_AUD_VOL_NUM /* Total volume level */
} MDI_AUD_VOL_ENUM;

/* Audio volume level enum for 16 level volume */
typedef enum
{
    MDI_AUD_VOL_EX_0,   /* Volume level 0 (Not mute) */
    MDI_AUD_VOL_EX_1,   /* Volume level 1 */
    MDI_AUD_VOL_EX_2,   /* Volume level 2 */
    MDI_AUD_VOL_EX_3,   /* Volume level 3 */
    MDI_AUD_VOL_EX_4,   /* Volume level 4 */
    MDI_AUD_VOL_EX_5,   /* Volume level 5 */
    MDI_AUD_VOL_EX_6,   /* Volume level 6 */
    MDI_AUD_VOL_EX_7,   /* Volume level 7 */
    MDI_AUD_VOL_EX_8,   /* Volume level 8 */
    MDI_AUD_VOL_EX_9,   /* Volume level 9 */
    MDI_AUD_VOL_EX_10,  /* Volume level 10 */
    MDI_AUD_VOL_EX_11,  /* Volume level 11 */
    MDI_AUD_VOL_EX_12,  /* Volume level 12 */
    MDI_AUD_VOL_EX_13,  /* Volume level 13 */
    MDI_AUD_VOL_EX_14,  /* Volume level 14 */
    MDI_AUD_VOL_EX_15,  /* Volume level 15 */
    MDI_AUD_VOL_EX_NUM  /* Total volume level */
} MDI_AUD_VOL_EX_ENUM;

/* The minimum volume of 16 level volume + mute level (mute) */
#define MDI_AUD_VOL_EX_MUTE_MIN 0
/* The maximum volume of 16 level volume + mute level (mute) */
#define MDI_AUD_VOL_EX_MUTE_MAX 16

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

/* Audio state enum */
typedef enum
{
    MDI_AUDIO_IDLE,         /* Idle state */
    MDI_AUDIO_PLAY,         /* Play state */
    MDI_AUDIO_PLAY_PAUSED,  /* Play paused state */
    MDI_AUDIO_RECORD,       /* Record state */
    MDI_AUDIO_RECORD_PAUSED,/* Record paused state */
    MDI_AUDIO_SPEECH_ON,    /* Speech mode on state */
    MDI_AUDIO_VRSI_PROCESS, /* VRSI processing state */
    MDI_AUDIO_POC_ON,       /* POC on state */
    MDI_NO_AUDIO_STATE      /* Total state number */
} MDI_AUDIO_STATE_ENUM;

/* Audio mode enum */
typedef enum
{
    MDI_AUDIO_PLAY_KT,              /* Play a keytone */
    MDI_AUDIO_PLAY_TONE,            /* Play a DTMF tone */
    MDI_AUDIO_PLAY_ID,              /* Play an audio resource ID */
    MDI_AUDIO_PLAY_STRING,          /* Play an audio from memory */
    MDI_AUDIO_PLAY_FILE,            /* Play an audio from file */
    MDI_AUDIO_RECORD_FILE,          /* Record audio to file */
    MDI_AUDIO_RECORD_FM_RADIO,      /* Record audio to file from FM radio */
    MDI_AUDIO_PLAY_FM_RADIO,        /* Play FM Radio */
    MDI_AUDIO_RECORD_VR_VOICE,      /* Receive voice for VR */
    MDI_AUDIO_VRSI_PLAY_TTS,        /* Play TTS for VRSI */
    MDI_AUDIO_VRSI_PLAY_TAG,        /* Play voice tag for VRSI */
    MDI_AUDIO_VRSI_RECORD,          /* Receive voice for VRSI */
    MDI_AUDIO_POC_ENCODE,           /* POC encode on */
    MDI_AUDIO_POC_DECODE,           /* POC decode on*/
    MDI_AUDIO_PLAY_TTS,             /* Play a general TTS */
    MDI_AUDIO_PLAY_IN_OTHER_TASK,   /* Play request by other task (not MMI) */
    MDI_NO_AUDIO_MODE               /* Total audio mode */
} MDI_AUDIO_PLAY_MODE_ENUM;

/* Audio type enum */
enum
{
    MDI_FORMAT_NONE = -1,       /* Not a supported audio type */
    MDI_FORMAT_GSM_FR,          /* 0  : GSM full rate */
    MDI_FORMAT_GSM_HR,          /* 1  : GSM half rate*/
    MDI_FORMAT_GSM_EFR,         /* 2  : GSM enhance full rate */
    MDI_FORMAT_AMR,             /* 3  : AMR */
    MDI_FORMAT_AMR_WB,          /* 4  : Wideband AMR */
    MDI_FORMAT_DAF,             /* 5  : Digital audio format */
    MDI_FORMAT_AAC,             /* 6  : AAC */
    MDI_FORMAT_PCM_8K,          /* 7  : PCM 8K data */
    MDI_FORMAT_PCM_16K,         /* 8  : PCM 17K data */
    MDI_FORMAT_G711_ALAW,       /* 9  : G711 A-Law data */
    MDI_FORMAT_G711_ULAW,       /* 10 : G711 Mu-law data */
    MDI_FORMAT_DVI_ADPCM,       /* 11 : DVI-ADPCM data */
    MDI_FORMAT_VR,              /* 12 : Voice Recognition tag format */
    MDI_FORMAT_WAV,             /* 13 : WAV */
    MDI_FORMAT_WAV_ALAW,        /* 14 : WAV A-law */
    MDI_FORMAT_WAV_ULAW,        /* 15 : WAV Mu-law */
    MDI_FORMAT_WAV_DVI_ADPCM,   /* 16 : WAV DVI-ADPCM */
    MDI_FORMAT_SMF,             /* 17 : MIDI */
    MDI_FORMAT_IMELODY,         /* 18 : IMELODY */
    MDI_FORMAT_SMF_SND,         /* 19 : MIDI sound */
    MDI_FORMAT_MMF,             /* 20 : MMF */
    MDI_FORMAT_AU,              /* 21 : AU */
    MDI_FORMAT_AIFF,            /* 22 : AIFF */
    MDI_FORMAT_VRSI,            /* 23 : VRSI tage format */
    MDI_FORMAT_WMA,             /* 24 : WMA */
    MDI_FORMAT_M4A,             /* 25 : M4A */
    MDI_FORMAT_3GP,             /* 26 : 3GP */
    MDI_FORMAT_MP4,             /* 27 : MP4 */
    MDI_FORMAT_JPG,             /* 28 : JPG */
    MDI_FORMAT_GIF,             /* 29 : GIF image */
    MDI_FORMAT_MJPG,            /* 30 : Motion JPEG */
    MDI_FORMAT_PNG,             /* 31 : PNG image */
    MDI_FORMAT_MUSICAM,         /* 32 : MUSICAM */
    MDI_FORMAT_BSAC,            /* 33 : BSAC */
    MDI_FORMAT_KURO,            /* 34 : Proprierary kuro format */
    MDI_FORMAT_KURO_AAC,        /* 35 : Proprierary kuro AAC format */
    MDI_NO_OF_FORMAT            /* Total format number */
};

/* Background play audio application enum */
typedef enum
{
    MDI_BACKGROUND_APP_FMR,     /* FM radio */
#ifdef __MMI_AUDIO_PLAYER__
    MDI_BACKGROUND_APP_AUDPLY,  /* Audio player */
#endif
#ifdef __MMI_MEDIA_PLAYER__
    MDI_BACKGROUND_APP_MEDPLY,  /* Media player */
#endif
#ifdef __J2ME__
    MDI_BACKGROUND_APP_JAVA,    /* JAVA */
#endif
#ifdef __A8BOX_SUPPORT__
	MDI_BACKGROUND_APP_A8BOX,   /* A8 box player */
#endif
/* Vogins Start */
#ifdef __VRE__
    MDI_BACKGROUND_APP_VRE,     /* For VRE applications */
#endif
/* Vogins End */
    /* New background application enum shall add before here */
    MDI_BACKGROUND_APP_TOTAL,   /* Total background application number */
    MDI_BACKGROUND_APP_POC      /* POC is the highest priority and handle differently */
} MDI_BACKGROUND_APP;

/* Application that will suspend background enum */
typedef enum
{
    MDI_AUD_SUSPEND_BG_JAVA,    /* JAVA */
    MDI_AUD_SUSPEND_BG_UCM,     /* Unified call management */
    MDI_AUD_SUSPEND_BG_SCO_INQ, /* BT HFP SCO link */
    MDI_AUD_SUSPEND_BG_FMGR,    /* FMGR */
    MDI_AUD_SUSPEND_BG_TOTAL    /* Total application */
} MDI_AUD_SUSPEND_BG_APP;

/* Bluetooth audio path state */
typedef enum
{
    MDI_AUDIO_BT_STATE_IDLE,        /* Idle state */
    MDI_AUDIO_BT_STATE_WAIT_OPEN,   /* Wait open response state */
    MDI_AUDIO_BT_STATE_OPEN,        /* Open state */
    MDI_AUDIO_BT_STATE_WAIT_CLOSE   /* Wait close response state */
} MDI_AUDIO_BT_STATE_ENUM;

/* Speech type enum */
typedef enum
{
    MDI_AUDIO_SPEECH_APP_ID_NONE,   /* No type */
    MDI_AUDIO_SPEECH_APP_ID_GSM,    /* GSM */
    MDI_AUDIO_SPEECH_APP_ID_WCDMA,  /* WCDMA */
    MDI_AUDIO_SPEECH_APP_ID_SIM2,   /* Dual SIM 2 */
    MDI_AUDIO_SPEECH_APP_ID_VOIP,   /* VoIP Call */
    MDI_AUDIO_SPEECH_APP_ID_3G324M  /* 3G324M video call */
} MDI_AUDIO_SPEECH_APP_ID_ENUM;

/* Audio record quality enum */
typedef enum
{
    MDI_AUDIO_REC_QUALITY_LOW,  /* Low quality */
    MDI_AUDIO_REC_QUALITY_MED,  /* Medium quality */
    MDI_AUDIO_REC_QUALITY_HIGH, /* High quality */
    MDI_AUDIO_REC_QUALITY_BEST  /* Best quality */
} MDI_AUDIO_REC_QUALITY_ENUM;

#ifdef __GENERAL_TTS__
/* General TTS input text type enum */
typedef enum
{
    MDI_TTS_STR_TEXT,   /*Regard input as normal text */
    MDI_TTS_STR_PHN_SBL,/*Regard input as phonetic symbol */
    MDI_TTS_STR_CHAR    /*Regard input as character set */
} MDI_AUD_TTS_STR_TYPE;

/* General TTS data structure */
typedef struct {
    U16 *text_string;   /* Data string pointer */
    U16 str_type;       /* String Type */
    U16 lang;           /* Language */
    U16 app_type;       /* Application Type */
    U16 gander;         /* Gender */
    U8 volume;          /* Volume, from 0~6 */
    U8 path;            /* Audio Path */
    U8 pitch;           /* Audio Pitch, from 0~100 */
    U8 speed;           /* Audio Speed, from 0~100 */
    mdi_callback callback;
} mdi_audio_tts_struct;
#endif /*__GENERAL_TTS__*/

/* Normal Mode */
#define MDI_AUD_MODE_NORMAL     0
/* HeadSet (Earphone) Mode */
#define MDI_AUD_MODE_HEADSET    1
/* Loudspeaker Mode */
#define MDI_AUD_MODE_LOUDSPK    2
#define MDI_MAX_AUD_MODE_NUM    3

/* MMI can apply to associate volume; call tone attribute */
#define MDI_VOLUME_CTN          0
/* MMI can apply to associate volume; keypad tone attribute */
#define MDI_VOLUME_KEY          1
/* Microphone attribute */
#define MDI_VOLUME_MIC          2
/* MMI can apply to FM radio attribute */
#define MDI_VOLUME_FMR          3
/* MMI can apply to associate volume; speech sound attribute */
#define MDI_VOLUME_SPH          4
/* side tone attribute */
#define MDI_VOLUME_SID          5
/* MMI can apply to associate volume; As MP3, Wave,... attribute */
#define MDI_VOLUME_MEDIA        6
/* Max volume type */
#define MDI_MAX_VOLUME_TYPE     7
/* Max volume level */
#define MDI_MAX_VOLUME_LEVEL    7

/* Tone, Keypad sound to play on audio device. */
#define MDI_DEVICE_SPEAKER      0
/* Microphone sound to send on audio device. */
#define MDI_DEVICE_MICROPHONE   1
/* Earphone, carkit */
#define MDI_DEVICE_SPEAKER2     4
/* Loudspeaker for free sound */
#define MDI_DEVICE_LOUDSPEAKER  5
/* Output from earphone and loud speaker */
#define MDI_DEVICE_SPEAKER_BOTH 6
/* Used to be OR bitwise with above audio output devices */
#define MDI_DEVICE_BT_HEADSET   8

/* Play sound for crescendo. */
#define MDI_AUDIO_PLAY_CRESCENDO    0
/* Play sound for infinite. */
#define MDI_AUDIO_PLAY_INFINITE     1
/* Play sound for once. */
#define MDI_AUDIO_PLAY_ONCE         2
/* Play sound for descendo. */
#define MDI_AUDIO_PLAY_DESCENDO     3

/* Input from mic1 */
#define MDI_INPUT_MIC1  0
/* Input from mic2 */
#define MDI_INPUT_MIC2  1
/* Input from FM radio */
#define MDI_INPUT_FMRR  2

/* Audio time stretch speed type number */
#define MDI_AUDIO_MAX_SPEED_NUM     5
/* Slowest speed */
#define MDI_AUDIO_SPEED_SLOW2       50
/* Slow speed */
#define MDI_AUDIO_SPEED_SLOW1       80
/* Normal Speed */
#define MDI_AUDIO_SPEED_NORMAL      100
/* Fast speed */
#define MDI_AUDIO_SPEED_FAST1       125
/* Fastest speed */
#define MDI_AUDIO_SPEED_FAST2       160

/* Exclude 1st(16-level) and 2nd(Mute) bit to get actual volume level*/
#define MDI_AUD_VOL_GET_EX_LEVEL(x)     ((x) & 0x3F)
/* Is 16 Level*/
#define MDI_AUD_VOL_IS_EX_LEVEL(x)      ((x) & 0x80)
/* Is Level 0 is mute */
#define MDI_AUD_VOL_IS_MUTE_LEVEL(x)    ((x) & 0x40)

/* 16 Level*/
#define MDI_AUD_VOL_EX(x)       ((x) | 0x80)
/* 7 Level, Level 0 is mute (2nd bit on), the volume level is 0 ~ 7 */
#define MDI_AUD_VOL_MUTE(x)     ((x) | 0x40)
/* 16 Level, Level 0 is mute(1st , 2nd bit on), the volume level is total 0 ~ 16 */
#define MDI_AUD_VOL_EX_MUTE(x)  ((x) | 0xC0)
/* Audio path macro */
#define MDI_AUD_PTH_EX(x) (x)

/* 7 Level */
#define MDI_AUD_VOL_LEVEL_NORMAL        1
/* 7 Level + Level 0 mute */
#define MDI_AUD_VOL_LEVEL_NORMAL_MUTE   2
/* 16 Level */
#define MDI_AUD_VOL_LEVEL_EXTEND        3
/* 16 Level + Level 0 mute */
#define MDI_AUD_VOL_LEVEL_EXTEND_MUTE   4

/*
*  TTS defines
*/
#ifdef __GENERAL_TTS__
/* English */
#define	MDI_TTS_LANG_ENG    0x1;
/* Taiwan-accent Chinese */
#define	MDI_TTS_LANG_TWN    0x2;
/* Mandarin */
#define	MDI_TTS_LANG_MDN    0x4;

/* General Purpose TTS */
#define	MDI_TTS_TYPE_GENERAL    0x1;
/* Dictionary */
#define	MDI_TTS_TYPE_DIC        0x2;
/* Name */
#define	MDI_TTS_TYPE_NAME       0x4;
/* GPS, traffic guiding */
#define	MDI_TTS_TYPE_GPS        0x8;
/* Weather report */
#define	MDI_TTS_TYPE_WEATHER    0x10;
/* Stock report */
#define	MDI_TTS_TYPE_STOCK      0x20;

/* Male */
#define	MDI_TTS_GENDER_MALE     0x1;
/* Female */
#define	MDI_TTS_GENDER_FEMALE   0x2;
/* Boy */
#define	MDI_TTS_GENDER_BOY      0x4
/* Girl */
#define	MDI_TTS_GENDER_GIRL     0x8;

/* TTS attribute enum */
typedef enum
{
    MDI_TTS_ATTR_INPUT_CODEPAGE,    /* Input code page, e.g. GBK */
    MDI_TTS_ATTR_TEXT_SCOPE,        /* Text scope, e.g. number */
    MDI_TTS_ATTR_INPUT_MODE,        /* Input mode, e.g. from fixed buffer, from callback */
    MDI_TTS_ATTR_PROGRESS_CALLBACK, /* Progress callback entry */
    MDI_TTS_ATTR_READ_DIGIT,        /* How to read digit, e.g. read as number, read as value  */
    MDI_TTS_ATTR_CHINESE_NUMBER_1,  /* How to read number "1" in Chinese */
    MDI_TTS_ATTR_PHONEME_WATCH,     /* How to watch phoneme, e.g. Chinese Pin-Yin */
    MDI_TTS_ATTR_WATCH_CALLBACK,    /* Watch callback entry */
    MDI_TTS_ATTR_SPEAK_STYLE,       /* Speak style */
    MDI_TTS_ATTR_TOTAL
}MDI_TTS_ATTR_ENUM;

/* GBK (default) */
#define MDI_TTS_VALUE_CODEPAGE_GBK         936
/* Big5 */
#define MDI_TTS_VALUE_CODEPAGE_BIG5        950
/* UTF-16 little-endian */
#define MDI_TTS_VALUE_CODEPAGE_UTF16LE     1200
/* UTF-16 big-endian */
#define MDI_TTS_VALUE_CODEPAGE_UTF16BE     1201

#endif /*__GENERAL_TTS__*/

/* MDI Audio Mutex */
#if defined(__J2ME__)
#define MDI_AUDIO_LOCK          mdi_audio_mutex_lock(basename(__FILE__),__LINE__)
#define MDI_AUDIO_LOCK_NO_WAIT  mdi_audio_mutex_lock_no_wait(basename(__FILE__),__LINE__)
#define MDI_AUDIO_UNLOCK        mdi_audio_mutex_unlock(basename(__FILE__),__LINE__)
#else
#define MDI_AUDIO_LOCK
#define MDI_AUDIO_LOCK_NO_WAIT
#define MDI_AUDIO_UNLOCK
#endif /*#if defined(__J2ME__)*/

/************ function prototype ***************/

extern void mdi_audio_init(void);
extern void mdi_audio_init_event_hdlrs(void);
extern void mdi_audio_start_background_timer(void);

#ifdef VR_ENABLE
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_voice_tag
 * DESCRIPTION
 *  This function is to play vr voice tag
 * PARAMETERS
 *  mode        : [IN] VR engine mode
 *  lang        : [IN] VR language
 *  group_id    : [IN] VR group id
 *  word_id     : [IN] VR tag id
 *  handle_p    : [IN] Reserved
 *  handler     : [IN] Callback handler
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS   : Start to play successfully
 *  MDI_AUDIO_FAIL      : Play fail
 *****************************************************************************/
extern mdi_result mdi_audio_play_voice_tag(
                    U8 mode,
                    U8 lang,
                    U8 group_id,
                    U16 word_id,
                    mdi_handle *handle_p,
                    mdi_callback handler);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_start_vr_voice_record
 * DESCRIPTION
 *  This function is to start vr voice record
 * PARAMETERS
 *  session_id      : [IN] VR session id
 *  seq_no          : [IN] VR sqeuence number, need to train twice
 *  handle_p        : [IN] Reserved
 *  handler         : [IN] Callback handler
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS   : Start to record successfully
 *  MDI_AUDIO_FAIL      : Record fail
 *****************************************************************************/
extern mdi_result mdi_audio_start_vr_voice_record(
                    U32 session_id,
                    U8 seq_no,
                    mdi_handle *handle_p,
                    mdi_callback handler);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_vr_voice_record
 * DESCRIPTION
 *  This function is to stop vr voice record.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS   : Stop successfully
 *****************************************************************************/
extern mdi_result mdi_audio_stop_vr_voice_record(void);
extern U32 mdi_audio_vr_rcg_session_id(void);
extern U32 mdi_audio_vr_trn_session_id(void);
extern U16 mdi_audio_vr_rcg_result_id_length(void);
extern U16 *mdi_audio_vr_rcg_result_id_array(void);
extern void mdi_audio_vr_rcg_result_ind(void *inMsg);
extern void mdi_audio_vr_trn_result_ind(void *inMsg);
extern void mdi_audio_vr_abort(void);
#endif /* VR_ENABLE */ 

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_id
 * DESCRIPTION
 *  This function is to play audio id.
 * PARAMETERS
 *  audio_id        : [IN] Audio resource id
 *  play_style      : [IN] Play style
 *  handle_p        : [IN] Reserved
 *  handler         : [IN] Callback handler
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS   : Starts to play successfully
 *  MDI_AUDIO_BUSY      : The audio resource is occupied by recording
 *  MDI_AUDIO_FAIL      : Play resource fail
 *****************************************************************************/
extern mdi_result mdi_audio_play_id(U16 audio_id, U8 play_style, mdi_handle *handle_p, mdi_callback handler);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_id_with_vol_path
 * DESCRIPTION
 *  This function is to play audio id along with volume and output path.
 * PARAMETERS
 *  audio_id        : [IN] Audio resource id
 *  play_style      : [IN] Play style
 *  handle_p        : [IN] Reserved
 *  handler         : [IN] Callback handler
 *  volume          : [IN] Audio volume
 *  path            : [IN] Audio output path
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS   : Starts to play successfully
 *  MDI_AUDIO_BUSY      : The audio resource is occupied by recording
 *  MDI_AUDIO_FAIL      : Play resource fail
 *****************************************************************************/
extern mdi_result mdi_audio_play_id_with_vol_path(
                    U16 audio_id,
                    U8 play_style,
                    mdi_handle *handle_p,
                    mdi_callback handler,
                    U8 volume,
                    U8 path);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_string
 * DESCRIPTION
 *  This function is to play audio string.
 * PARAMETERS
 *  audio_data      : [IN] Buffer pointer for audio data
 *  len             : [IN] Audio data length
 *  format          : [IN] Audio data format
 *  play_style      : [IN] Play style
 *  handle_p        : [IN] Reserved
 *  handler         : [IN] Callback handler
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS       : Starts to play successfully
 *  MDI_AUDIO_BUSY          : The audio resource is occupied by recording
 *  MDI_AUDIO_FAIL          : Play audio buffer data fail
 *  MDI_AUDIO_BAD_FORMAT    : Driver can not decode audio buffer
 *****************************************************************************/
extern mdi_result mdi_audio_play_string(
                    void *audio_data,
                    U32 len,
                    U8 format,
                    U8 play_style,
                    mdi_handle *handle_p,
                    mdi_callback handler);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_string_with_vol_path
 * DESCRIPTION
 *  This function is to play audio string along with volume and output path.
 * PARAMETERS
 *  audio_data      : [IN] Buffer pointer for audio data
 *  len             : [IN] Audio data length
 *  format          : [IN] Audio data format
 *  play_style      : [IN] Play style
 *  handle_p        : [IN] Reserved
 *  handler         : [IN] Callback handler
 *  volume          : [IN] Audio volume
 *  path            : [IN] Audio output path
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS       : Starts to play successfully
 *  MDI_AUDIO_BUSY          : The audio resource is occupied by recording
 *  MDI_AUDIO_FAIL          : Play audio buffer data fail
 *  MDI_AUDIO_BAD_FORMAT    : Driver can not decode audio buffer
 *****************************************************************************/
extern mdi_result mdi_audio_play_string_with_vol_path(
                    void *audio_data,
                    U32 len,
                    U8 format,
                    U8 play_style,
                    mdi_handle *handle_p,
                    mdi_callback handler,
                    U8 volume,
                    U8 path);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_string_portion_with_vol_path
 * DESCRIPTION
 *  This function is to play partial audio string along with volume and output path.
 * PARAMETERS
 *  audio_data      : [IN] Buffer pointer for audio data
 *  len             : [IN] Audio data length
 *  start_offset    : [IN] Start time offset (in ms)
 *  end_offset      : [IN] End time offset (in ms)
 *  format          : [IN] Audio data format
 *  play_style      : [IN] Play style
 *  handle_p        : [IN] Reserved
 *  handler         : [IN] Callback handler
 *  volume          : [IN] Audio volume
 *  path            : [IN] Audio output path
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS       : Starts to play successfully
 *  MDI_AUDIO_BUSY          : The audio resource is occupied by recording
 *  MDI_AUDIO_FAIL          : Play audio buffer data fail
 *  MDI_AUDIO_BAD_FORMAT    : Driver can not decode audio buffer
 *****************************************************************************/
extern mdi_result mdi_audio_play_string_portion_with_vol_path(
       			    void *audio_data,
		            U32 len,
		            U8 format,
					U32 start_offset,
					U32 end_offset,
		            U8 play_style,
		            mdi_handle *handle_p,
		            mdi_callback handler,
		            U8 volume,
		            U8 path);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_string_with_vol_path_non_block
 * DESCRIPTION
 *  This function is to play audio string along with volume and output path.
 *  The function will not block waiting for MED event, usually used for very quick and short sound play.
 * PARAMETERS
 *  audio_data      : [IN] Buffer pointer for audio data
 *  len             : [IN] Audio data length
 *  format          : [IN] Audio data format
 *  play_style      : [IN] Play style
 *  handle_p        : [IN] Reserved
 *  handler         : [IN] Callback handler
 *  volume          : [IN] Audio volume
 *  path            : [IN] Audio output path
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS       : Starts to play successfully
 *  MDI_AUDIO_BUSY          : The audio resource is occupied by recording
 *  MDI_AUDIO_FAIL          : Play audio buffer data fail
 *  MDI_AUDIO_BAD_FORMAT    : Driver can not decode audio buffer
 *****************************************************************************/
extern mdi_result mdi_audio_play_string_with_vol_path_non_block(
                    void *audio_data,
                    U32 len,
                    U8 format,
                    U8 play_style,
                    mdi_handle *handle_p,
                    mdi_callback handler,
                    U8 volume,
                    U8 path);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_file
 * DESCRIPTION
 *  This function is to play audio file.
 * PARAMETERS
 *  file_name       : [IN] Full file path and name
 *  play_style      : [IN] Play style
 *  cache_p         : [IN] Data cache buffer pointer to enhance seek speed for VBR files
 *  handler         : [IN] Callback handler
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS           : Starts to play successfully
 *  MDI_AUDIO_FAIL              : Play audio buffer data fail
 *  MDI_AUDIO_BUSY              : The audio resource is occupied by recording
 *  MDI_AUDIO_OPEN_FILE_FAIL    : Open file fail
 *  MDI_AUDIO_END_OF_FILE       : Play till end of file
 *  MDI_AUDIO_BAD_FORMAT        : Driver can not decode audio buffer
 *  MDI_AUDIO_INVALID_FORMAT    : Not support format
 *  MDI_AUDIO_MEM_INSUFFICIENT  : Memory not enough to play
 *  MDI_AUDIO_DRM_PROHIBIT      : DRM protect and prohibit to play
 *****************************************************************************/
extern mdi_result mdi_audio_play_file(void *file_name, U8 play_style, void *cache_p, mdi_callback handler);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_file_with_vol_path
 * DESCRIPTION
 *  This function is to play audio file along with volume and output path.
 * PARAMETERS
 *  file_name       : [IN] Full file path and name
 *  play_style      : [IN] Play style
 *  cache_p         : [IN] Data cache buffer pointer to enhance seek speed for VBR files
 *  handler         : [IN] Callback handler
 *  volume          : [IN] Audio volume
 *  path            : [IN] Audio output path
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS           : Starts to play successfully
 *  MDI_AUDIO_FAIL              : Play audio buffer data fail
 *  MDI_AUDIO_BUSY              : The audio resource is occupied by recording
 *  MDI_AUDIO_OPEN_FILE_FAIL    : Open file fail
 *  MDI_AUDIO_END_OF_FILE       : Play till end of file
 *  MDI_AUDIO_BAD_FORMAT        : Driver can not decode audio buffer
 *  MDI_AUDIO_INVALID_FORMAT    : Not support format
 *  MDI_AUDIO_MEM_INSUFFICIENT  : Memory not enough to play
 *  MDI_AUDIO_DRM_PROHIBIT      : DRM protect and prohibit to play
 *****************************************************************************/
extern mdi_result mdi_audio_play_file_with_vol_path(
                    void *file_name,
                    U8 play_style,
                    void *cache_p,
                    mdi_callback handler,
                    U8 volume,
                    U8 path);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_file_portion_with_vol_path
 * DESCRIPTION
 *  This function is to play audio file portion with volume and output path.
 * PARAMETERS
 *  file_name       : [IN] Full file path and name
 *  start_offset    : [IN] Start time offset (in ms)
 *  end_offset      : [IN] End time offset (in ms)
 *  play_style      : [IN] Play style
 *  cache_p         : [IN] Data cache buffer pointer to enhance seek speed for VBR files
 *  handler         : [IN] Callback handler
 *  volume          : [IN] Audio volume
 *  path            : [IN] Audio output path
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS           : Starts to play successfully
 *  MDI_AUDIO_FAIL              : Play audio buffer data fail
 *  MDI_AUDIO_BUSY              : The audio resource is occupied by recording
 *  MDI_AUDIO_OPEN_FILE_FAIL    : Open file fail
 *  MDI_AUDIO_END_OF_FILE       : Play till end of file
 *  MDI_AUDIO_BAD_FORMAT        : Driver can not decode audio buffer
 *  MDI_AUDIO_INVALID_FORMAT    : Not support format
 *  MDI_AUDIO_MEM_INSUFFICIENT  : Memory not enough to play
 *  MDI_AUDIO_DRM_PROHIBIT      : DRM protect and prohibit to play
 *****************************************************************************/
extern mdi_result mdi_audio_play_file_portion_with_vol_path(
                    void *file_name,
                    U32 start_offset,
                    U32 end_offset,
                    U8 play_style,
                    void *cache_p,
                    mdi_callback handler,
                    U8 volume,
                    U8 path);

#if defined(DIGIT_TONE_SUPPORT) || defined(SIMPLE_TTS)
extern void mdi_audio_play_text_event_handler(mdi_result result);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_play_text_with_vol_path
 * DESCRIPTION
 *  This function is to play text (number or words)
 * PARAMETERS
 *  words           : [IN] Words buffer to be played
 *  len             : [IN] Total buffer length
 *  msecs           : [IN] The interval for each word
 *  handle_p        : [IN] Reserved
 *  handler         : [IN] Callback handler
 *  volume          : [IN] Audio volume
 *  path            : [IN] Audio output path
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS       : Starts to play successfully
 *  MDI_AUDIO_BUSY          : The audio resource is occupied by recording
 *  MDI_AUDIO_FAIL          : Play audio buffer data fail
 *****************************************************************************/
extern mdi_result mdi_audio_play_text_with_vol_path(
                    U8 *words,
                    S32 len,
                    S32 msecs,
                    mdi_handle *handle_p,
                    mdi_callback handler,
                    U8 volume,
                    U8 path);
#endif /* defined(DIGIT_TONE_SUPPORT) || defined(SIMPLE_TTS) */ 

extern mdi_result mdi_audio_store_file(mdi_handle audio_handle);
extern mdi_result mdi_audio_restore_file_with_vol_path(
                    void *file_name,
                    U8 play_style,
                    void *cache_p,
                    mdi_callback handler,
                    U8 volume,
                    U8 path);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_id
 * DESCRIPTION
 *  This function is to stop audio id.
 * PARAMETERS
 *  audio_id    : [IN] Audio id
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS       : Stops successfully
 *****************************************************************************/
extern mdi_result mdi_audio_stop_id(U16 audio_id);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_string
 * DESCRIPTION
 *  This function is to stop audio string.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS       : Stops successfully
 *****************************************************************************/
extern mdi_result mdi_audio_stop_string(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_file
 * DESCRIPTION
 *  This function is to stop audio file.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS       : Stops successfully
 *****************************************************************************/
extern mdi_result mdi_audio_stop_file(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_all
 * DESCRIPTION
 *  This function is to stop all audio id, string, file, FM radio, VR, TTS, ...
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS       : Stops successfully
 *****************************************************************************/
extern mdi_result mdi_audio_stop_all(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_fmr
 * DESCRIPTION
 *  This function is to stop FM radio playing/recording
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS       : Stops successfully
 *****************************************************************************/
extern mdi_result mdi_audio_stop_fmr(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_pause
 * DESCRIPTION
 *  This function is to pause audio play/record.
 * PARAMETERS
 *  audio_handle    : [IN] Audio handle, currently not used
 *  handler         : [IN] Callback handler
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS               : Pause successfully
 *  MDI_AUDIO_UNSUPPORTED_OPERATION : Do not support pause function, will continue play
 *  MDI_AUDIO_DISC_FULL             : For record pause, disk is full while pause
 *  MDI_AUDIO_FAIL                  : Pause fail
 *****************************************************************************/
extern mdi_result mdi_audio_pause(mdi_handle audio_handle, mdi_callback handler);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_resume
 * DESCRIPTION
 *  This function is to resume audio play/record.
 * PARAMETERS
 *  audio_handle    : [IN] Audio handle, currently not used
 *  handler         : [IN] Callback handler        
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS   : Resume successfully
 *  MDI_AUDIO_FAIL      : Resume fail
 *****************************************************************************/
extern mdi_result mdi_audio_resume(mdi_handle audio_handle, mdi_callback handler);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_start_record
 * DESCRIPTION
 *  This function is to start audio record.
 * PARAMETERS
 *  file_name       : [IN] Full file path and name
 *  format          : [IN] Record format
 *  handle_p        : [IN] Reserved
 *  handler         : [IN] Callback function
 * RETURNS
 *  Refer to mdi_audio_start_record_with_limit()
 *****************************************************************************/
extern mdi_result mdi_audio_start_record(void *file_name, U8 format, U8 quality, mdi_handle *handle_p, mdi_callback handler);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_start_record_with_limit
 * DESCRIPTION
 *  This function is to start audio record with time or size limited
 * PARAMETERS
 *  file_name       : [IN] Full file path and name
 *  format          : [IN] Record format
 *  handle_p        : [IN] Reserved
 *  handler         : [IN] Callback function
 *  size_limit      : [IN] Max record size in byte.   0: Unlimited
 *  time_limit      : [IN] Max record time in second. 0: Unlimited
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS           : Start record successfully
 *  MDI_AUDIO_FAIL              : Start record fail
 *  MDI_AUDIO_DISC_FULL         : Disk full
 *  MDI_AUDIO_OPEN_FILE_FAIL    : Can not open record file
 *  MDI_AUDIO_BAD_FORMAT        : Not support format (check by MED)
 *  MED_RES_INVALID_FORMAT      : Not support format (check by Driver)
 *  MDI_AUDIO_WRITE_PROTECTION  : Card has write protection
 *****************************************************************************/
extern mdi_result mdi_audio_start_record_with_limit(
                    void *file_name,
                    U8 format,
                    U8 quality,
                    mdi_handle *handle_p,
                    mdi_callback handler,
                    U32 size_limit,
                    U32 time_limit);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_record
 * DESCRIPTION
 *  This function is to stop audio record.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS   : Stop successfully
 *****************************************************************************/
extern mdi_result mdi_audio_stop_record(void);

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
extern void mdi_audio_resume_background_play(void);
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
extern void mdi_audio_suspend_background_play(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_resume_background_play_by_app
 * DESCRIPTION
 *  This function is to resume background play by an application
 * PARAMETERS
 *  app_id      : [IN] Application id in MDI_AUD_SUSPEND_BG_APP
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_audio_resume_background_play_by_app(MDI_AUD_SUSPEND_BG_APP app_id);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_suspend_background_play_by_app
 * DESCRIPTION
 *  This function is to suspend background play by application.
 *  If the application does not call resume, the background play will keep suspended
 * PARAMETERS
 *  app_id      : [IN] Application id in MDI_AUD_SUSPEND_BG_APP
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_audio_suspend_background_play_by_app(MDI_AUD_SUSPEND_BG_APP app_id);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_set_background_handler
 * DESCRIPTION
 *  This function is to set background play timeout handler.
 *  Besides POC, the latest register callback will be called first.
 *
 * PARAMETERS
 *  app_level   : [IN] Application in MDI_BACKGROUND_APP
 *  handler     : [IN] Callback handler
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS   : Set successfully
 *  MDI_AUDIO_FAIL      : Set fail
 *****************************************************************************/
extern mdi_result mdi_audio_set_background_handler(U8 app_level, mdi_bg_callback handler);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_clear_background_handler
 * DESCRIPTION
 *  This function is to reset background play timeout handler.
 * PARAMETERS
 *  app_level   : [IN] Application in MDI_BACKGROUND_APP
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS   : Clear successfully
 *  MDI_AUDIO_FAIL      : Clear fail
 *****************************************************************************/
extern mdi_result mdi_audio_clear_background_handler(U8 app_level);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_clear_other_background_handler
 * DESCRIPTION
 *  This function is to clear other application's background handler except current application
 * PARAMETERS
 *  app_level   : [IN] Application in MDI_BACKGROUND_APP
 * RETURNS
 *  MDI_AUDIO_SUCCESS   : Clear successfully
 *****************************************************************************/
extern mdi_result mdi_audio_clear_other_background_handler(U8 app_level);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_background_callback_order
 * DESCRIPTION
 *  This function is to get application sequence in the callback stack
 * PARAMETERS
 *  app_level   : [IN] Application in MDI_BACKGROUND_APP
 * RETURNS
 *  The position in the callback stack
 *****************************************************************************/
extern S32 mdi_audio_get_background_callback_order(U8 app_level);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_background_callback_register_app_num
 * DESCRIPTION
 *  This function is to get total callback number in the stack
 * PARAMETERS
 *  void
 * RETURNS
 *  Total callback number
 *****************************************************************************/
extern U8 mdi_audio_get_background_callback_register_app_num(void);

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_set_volume
 * DESCRIPTION
 *  This function is to set the volume with the given type and volume.
 * PARAMETERS
 *  type        [IN] : Audio type
 *  volume      [IN] : Volume
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_audio_set_volume(U8 type, U8 volume);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_set_volume_no_apply
 * DESCRIPTION
 *  This function is to set the volume with the given type and volume
 *  but this value will not apply to HW.
 * PARAMETERS
 *  type        [IN] : Audio type
 *  volume      [IN] : Volume
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_audio_set_volume_no_apply(U8 type, U8 volume);
extern void mdi_audio_set_mic_volume(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_set_mute
 * DESCRIPTION
 *  This function is to set mute on the given volume type.
 * PARAMETERS
 *  vol_type        [IN] : Audio type
 *  mute            [IN] : Mute on/off
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_audio_set_mute(U8 vol_type, BOOL mute);
extern void mdi_audio_set_pseudo_play_file_callback(mdi_callback callback);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_midi_size_limit
 * DESCRIPTION
 *  This function is to get the MED buffer size for playing midi or imelody
 * PARAMETERS
 *  void
 * RETURNS
 *  Size of MED buffer
 *****************************************************************************/
extern U32 mdi_audio_get_midi_size_limit(void);

extern void mdi_audio_bt_init(U8 profile, mdi_bt_callback open_handler, mdi_bt_callback close_handler);
extern U8 mdi_audio_bt_get_stream_status(U8 profile);
extern void mdi_audio_bt_close_stream_ind(void *msg);
extern void mdi_audio_bt_close_stream_cnf(void *msg);
extern void mdi_audio_bt_open_stream_ind(void *msg);
extern void mdi_audio_bt_open_stream_cnf(void *msg);
extern BOOL mdi_audio_bt_open_stream(U8 profile, U16 connect_id);
extern BOOL mdi_audio_bt_close_stream(U8 profile);
extern BOOL mdi_audio_bt_is_stream_open(U8 profile);
extern void mdi_audio_bt_hfp_turn_on(void);
extern void mdi_audio_bt_hfp_turn_off(void);
extern MMI_BOOL mdi_audio_bt_is_a2dp_codec_open(void);

#ifdef __BT_SPK_VOL_CONTROL__
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_bt_register_volume_sync_callback
 * DESCRIPTION
 *  This function is to register volume value callback from BT headset
 * PARAMETERS
 *   app_id         : [IN] Use APPLICATION_DEPLOY enum in MMIDataType.h
 *   volume_type    : [IN] 16-level or 7-level volume (MDI_AUD_VOL_LEVEL_NORMAL ~ MDI_AUD_VOL_LEVEL_EXTEND_MUTE)
 *   callback       : [IN] Return true if application is running
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_audio_bt_register_volume_sync_callback(U32 app_id, U8 volume_lvl_type, MMI_BOOL (*callback)(U8 volume, MMI_BOOL is_mute));
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_clear_volume_sync_callback
 * DESCRIPTION
 *  This function is to clear volume value callback from BT headset
 * PARAMETERS
 *   app_id         : [IN] Use APPLICATION_DEPLOY enum in MMIDataType.h
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_audio_bt_clear_volume_sync_callback(U32 app_id);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_sync_volume_from_bt
 * DESCRIPTION
 *  This function is to synchronize current application volume to BT headset
 * PARAMETERS
 *   bt_volume      : [IN] Bluetooth volume from 0 ~ 15
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_audio_sync_volume_from_bt(U8 bt_volume);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_set_volume_to_bt
 * DESCRIPTION
 *  This function is to set volume to bluetooth, use the following mapping
 *  7-Level -> 16 Level Mapping 
 *    0 ->    0
 *    1 ->    2
 *    2 ->    5
 *    3 ->    7
 *    4 ->   10
 *    5 ->   13
 *    6 ->   15
 *
 * PARAMETERS
 *   volume     : [IN] 7-level or 16-level volume from application
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_audio_set_volume_to_bt(U8 volume);
#endif /* __BT_SPK_VOL_CONTROL__ */

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_set_headset_mode_output_path
 * DESCRIPTION
 *  This function is to set headset mode output path.
 * PARAMETERS
 *  device      : [IN] Output device
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_audio_set_headset_mode_output_path(unsigned char device);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_set_vibrator_enabled
 * DESCRIPTION
 *  This function is to set vibrator enabled
 * PARAMETERS
 *  enable      : [IN] Enable/disable the vibrator
 * RETURN VALUES
 *  MDI_AUDIO_SUCCESS   : Set successfully
 *****************************************************************************/
extern mdi_result mdi_audio_set_vibrator_enabled(BOOL enable);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_state
 * DESCRIPTION
 *  This function is to get the audio state.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_AUDIO_IDLE          : Idle state
 *  MDI_AUDIO_PLAY          : Play state
 *  MDI_AUDIO_PLAY_PAUSED   : Play paused state
 *  MDI_AUDIO_RECORD        : Record state
 *  MDI_AUDIO_RECORD_PAUSED : Record paused state
 *****************************************************************************/
extern mdi_state mdi_audio_get_state(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_audio_mode
 * DESCRIPTION
 *  This function is to get the audio mode (normal, headset, loudspk).
 * PARAMETERS
 *  void
 * RETURNS
 *  AUD_MODE_NORMAL     : Normal Mode
 *  AUD_MODE_HEADSET    : HeadSet (Earphone) Mode
 *  AUD_MODE_LOUDSPK    : Loudspeaker Mode
 *****************************************************************************/
extern U8 mdi_audio_get_audio_mode(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_set_audio_mode
 * DESCRIPTION
 *  This function is to set the audio mode (normal, headset, loudspk).
 * PARAMETERS
 *  mode        [IN] : Audio mode
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_audio_set_audio_mode(U8 mode);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_is_background_play_suspended
 * DESCRIPTION
 *  This function is to check if background play suspended.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL mdi_audio_is_background_play_suspended(void);
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
extern BOOL mdi_audio_is_idle(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_is_idle
 * DESCRIPTION
 *  This function is to check if audio is playing in specific audio mode
 * PARAMETERS
 *  audio_mode [IN] : Mode in MDI_AUDIO_PLAY_MODE_ENUM
 * RETURNS
 * BOOL
 *****************************************************************************/
extern MMI_BOOL mdi_audio_is_playing(U16 audio_mode);
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
extern BOOL mdi_audio_is_speech_mode(void);
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
extern mdi_result mdi_audio_start_calc_spectrum(void);
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
extern mdi_result mdi_audio_stop_calc_spectrum(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_spectrum
 * DESCRIPTION
 *  This function is to get the audio spectrum tops & vals.
 * PARAMETERS
 *  top_p      : [IN] Spectrum tops
 *  val_p      : [IN] Spectrum values
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_get_spectrum(U8 *top_p, U8 *val_p);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_is_pure_audio
 * DESCRIPTION
 *  This function is to check if a file is pure audio file
 * PARAMETERS
 *  file_name      : [IN] File name
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL mdi_audio_is_pure_audio(void *file_name);
#if defined(AAC_DECODE)
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_is_seekable
 * DESCRIPTION
 *  This function is to check if a aac file seekable. (AAC ADIF is not seekable)
 * PARAMETERS
 *  file_name      : [IN] File name
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL mdi_audio_is_aac_file_seekable(void *file_name);
#endif
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_duration
 * DESCRIPTION
 *  This function is to get the duration of a audio file.
 * PARAMETERS
 *  file_name       : [IN]  Full file path
 *  time_p          : [OUT] Duration in milliseconds
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_get_duration(void *file_name, U32 *time_p);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_mp4_duration
 * DESCRIPTION
 *  This function is to get the total duration of a mp4 file, it will return longer
 *  time in audio or video track.
 * PARAMETERS
 *  file_name       : [IN]  Full file path
 *  time_p          : [OUT] Duration in milliseconds
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_get_mp4_duration(void *file_name, U32 *time_p);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_duration_by_string
 * DESCRIPTION
 *  This function is to get the duration of a audio file.
 * PARAMETERS
 *  audio_data  : [IN]  Audio data pointer
 *  len         : [IN]  Data length
 *  format      : [IN]  Data format
 *  time_p      : [OUT] Duration in milliseconds
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_get_duration_by_string(kal_uint8 *audio_data, U32 len, U8 format, U32 *time_p);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_get_progress_time
 * DESCRIPTION
 *  This function is to get the progress of file playing
 * PARAMETERS
 *  progress_time_p : [IN] Current time
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_get_progress_time(U32 *progress_time_p);
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
extern mdi_result mdi_audio_set_progress_time(U32 progress);

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_start_build_cache
 * DESCRIPTION
 *  This function is to start build cache
 * PARAMETERS
 *  filename        : [IN] Full file path
 *  cache_p         : [IN] Cache buffer pointer
 *  cache_size      : [IN] Cache buffer size
 *  file_buf_p      : [IN] File cache buffer pointer
 *  file_buf_size   : [IN] File cache size
 *  proc_buf_p      : [IN] Driver process buffer pointer
 *  proc_buf_size   : [IN] Driver process buffer size
 *  handler         : [IN] Call back hanlder when build cache fail
 *  build_cache_progress    : [OUT] Process percentage
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_audio_start_build_cache(
                    kal_wchar *filename,
                    U8 *cache_p, 
                    U32 cache_size,
                    U8 *file_buf_p,
                    U32 file_buf_size,
                    U8 *proc_buf_p,
                    U32 proc_buf_size,
                    void (*handler)(void*),
                    U32 *build_cache_progress);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_stop_build_cache
 * DESCRIPTION
 *  This function is to stop build cache
 * PARAMETERS
 * void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_audio_stop_build_cache(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_close_build_cache
 * DESCRIPTION
 *  This function is to close build cache
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_audio_close_build_cache(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_reset_build_cache_variables
 * DESCRIPTION
 *  This function is to reset build cache variables
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_audio_reset_build_cache_variables(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_build_cache_get_cache_duration
 * DESCRIPTION
 *  This function is to get current cached duration
 * PARAMETERS
 * duration_p     : [OUT] Duration
 * RETURNS
 *  BOOL
 *****************************************************************************/
extern BOOL mdi_audio_build_cache_get_cache_duration(kal_uint32 *duration_p);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_reset_build_cache_variables
 * DESCRIPTION
 *  This function is to get total duration from build cache
 * PARAMETERS
 * duration_p     : [OUT] Duration
 * RETURNS
 *  BOOL
 *****************************************************************************/
extern BOOL mdi_audio_build_cache_get_total_duration(kal_uint32 *duration_p);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_regisiter_auto_update_duration_handler
 * DESCRIPTION
 *  This function is to regisiter auto update time duration
 * PARAMETERS
 * duration_p     : [OUT] Total duration
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_audio_regisiter_auto_update_duration_handler(void(*handler)(U32 duration));
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_is_duration_need_build_cache
 * DESCRIPTION
 *  This function is to check if we need to build cache to get precise duration
 * PARAMETERS
 *  filename     : [IN] Fule file path
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL mdi_audio_is_duration_need_build_cache(void *filename);

extern void mdi_audio_mma_init(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_open_file
 * DESCRIPTION
 *  This function is to open file with mma interface
 * PARAMETERS
 *  file_name    : [IN] Fule file path
 *  repeats      : [IN] Repeat times
 *  is_pdl       : [IN] Is progressive download
 *  callback     : [IN] Callback function
 * RETURNS
 *  mdi_handle, handle of the player
 *****************************************************************************/
extern mdi_handle mdi_audio_mma_open_file(void *file_name, U8 repeats, MMI_BOOL is_pdl, mdi_mma_callback callback);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_open_string
 * DESCRIPTION
 *  This function is to open audio buffer with mma interface
 * PARAMETERS
 *  audio_data   : [IN] Data pointer
 *  len          : [IN] Data length
 *  mdi_format   : [IN] Format
 *  repeats      : [IN] Repeat times
 *  callback     : [IN] Callback function
 * RETURNS
 *  mdi_handle, handle of the player
 *****************************************************************************/
extern mdi_handle mdi_audio_mma_open_string(void *audio_data, U32 len, U8 mdi_format, U8 repeats, mdi_mma_callback callback);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_set_cache_table
 * DESCRIPTION
 *  This function is to set cache table to driver for faster seek in VBR file
 * PARAMETERS
 *  handle      : [IN] Player handle
 *  cache_tbl   : [IN] Cache table buffer
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_mma_set_cache_table(mdi_handle handle, U8 *cache_tbl);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_play
 * DESCRIPTION
 *  This function is to start player
 * PARAMETERS
 *  handle      : [IN] Player handle
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_mma_play(mdi_handle handle);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_pause
 * DESCRIPTION
 *  This function is to pause player
 * PARAMETERS
 *  handle      : [IN] Player handle
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_mma_pause(mdi_handle handle);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_resume
 * DESCRIPTION
 *  This function is to resume player
 * PARAMETERS
 *  handle      : [IN] Player handle
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_mma_resume(mdi_handle handle);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_stop
 * DESCRIPTION
 *  This function is to stop player
 * PARAMETERS
 *  handle      : [IN] Player handle
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_mma_stop(mdi_handle handle);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_close
 * DESCRIPTION
 *  This function is to close player
 * PARAMETERS
 *  handle      : [IN] Player handle
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_mma_close(mdi_handle handle);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_is_idle
 * DESCRIPTION
 *  This function is to check if all mma player is idle
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
extern kal_bool mdi_audio_mma_is_idle(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_is_open
 * DESCRIPTION
 *  This function is to check if any mma player is open
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
extern kal_bool mdi_audio_mma_is_open(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_set_start_time
 * DESCRIPTION
 *  This function is to set start time
 * PARAMETERS
 *  handle      : [IN] Player handle
 *  start_time  : [IN] Start time
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_mma_set_start_time(mdi_handle handle, U32 start_time);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_get_current_time
 * DESCRIPTION
 *  This function is to get current playing time
 * PARAMETERS
 *  handle        : [IN] Player handle
 *  current_time  : [OUT] Current time
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_mma_get_current_time(mdi_handle handle, U32 *current_time);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_pdl_write_data_ind
 * DESCRIPTION
 *  This function is to inform MED if the PDL is download finish
 * PARAMETERS
 *  handle      : [IN] Player handle
 *  is_finish   : [IN] Is download finish
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_mma_pdl_write_data_ind(mdi_handle handle, MMI_BOOL is_finish);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_mma_pdl_get_buf_percent
 * DESCRIPTION
 *  This function is to get current pdl buffering status
 * PARAMETERS
 *  handle      : [IN] Player handle
 *  percent     : [OUT] Percentage
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_audio_mma_pdl_get_buf_percent(mdi_handle handle, U32 cache_sec, U32* percent);

extern mdi_handle mdi_audio_mma_open_midi(void *audio_data, U32 len, U8 repeats, mdi_mma_callback handler);
extern mdi_result mdi_audio_mma_close_midi(mdi_handle handle);
extern mdi_result mdi_audio_mma_play_midi(mdi_handle handle);
extern mdi_result mdi_audio_mma_stop_midi(mdi_handle handle);

extern mdi_handle mdi_audio_mma_open_wav(void *audio_data, U32 len, U8 repeats, mdi_mma_callback handler);
extern mdi_result mdi_audio_mma_close_wav(mdi_handle handle);
extern mdi_result mdi_audio_mma_play_wav(mdi_handle handle);
extern mdi_result mdi_audio_mma_stop_wav(mdi_handle handle);

/* FM Radio Begin */
/* functions in blocking mode */

/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_power_on_with_path
 * DESCRIPTION
 *  This function is to turn on FM radio with specific output path
 * PARAMETERS
 *  path        : [IN] FM output path
 *  handler     : [IN] Callback handler
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_fmr_power_on_with_path(U8 path, mdi_callback handler);
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
extern void mdi_fmr_power_off(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_set_freq
 * DESCRIPTION
 *  This function is to set the frequency of FM radio.
 * PARAMETERS
 *  freq        : [IN] FM frequency
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_fmr_set_freq(U16 freq);
/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_mute
 * DESCRIPTION
 *  This function is to mute the FM radio
 * PARAMETERS
 *  mute        : [IN] Mute on or off
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_fmr_mute(U8 mute);

/* functions in non-blocking mode */

/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_check_is_valid_stop
 * DESCRIPTION
 *  This function is to check if a frequency is valid stop
 * PARAMETERS
 *  freq                : [IN] FM frequency
 *  is_step_up          : [IN] Step up or down
 *  callback_func       : [IN] Callback function
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_check_is_valid_stop(U16 freq, BOOL is_step_up, void (*callback_func) (BOOL is_valid));
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
extern void mdi_fmr_cancel_checking_is_valid_stop(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_get_signal_level
 * DESCRIPTION
 *  This function is to get the signal level of a frequency
 * PARAMETERS
 *  freq                : [IN] FM frequency
 *  is_step_up          : [IN] Step up or down
 *  callback_func       : [IN] Callback function
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_fmr_get_signal_level(U16 freq, BOOL is_step_up, void (*callback_func) (U8 sig_lvl));
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
extern void mdi_fmr_cancel_getting_signal_level(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_evaluate_threshold
 * DESCRIPTION
 *  This function is to re-evaluate valid channel threshould
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_fmr_evaluate_threshold(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_set_channel
 * DESCRIPTION
 *  This API is to set mono or stereo channel
 * PARAMETERS
 *  is_mono     : [IN] Is mono channel
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_fmr_set_channel(MMI_BOOL is_mono);
/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_freq_seek_start
 * DESCRIPTION
 *   Start to seek
 * PARAMETERS
 *  start_freq      : [IN]    start frequency
 *  is_step_up      : [IN]    seek direction
 *  is_preset       : [IN]    it will not wrap around if it is preset auto search
 *  space           : [IN]    minimum space between two frequency. 200: 200KHz, 100: 100KHz
 *  callback_func   : [IN]    callback function when found a valid freq or user abortion
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_fmr_freq_seek_start(U16 start_freq, MMI_BOOL is_step_up, MMI_BOOL is_preset, S16 space,
                                    void (*callback_func) (U16 stop_freq, U8 signal_level, MMI_BOOL is_valid)) ;
/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_freq_seek_abort
 * DESCRIPTION
 *  Abort FM Radio seek.
 *  After abortion, it will call the callback function register in mdi_fmr_freq_seek_start.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_fmr_freq_seek_abort(void);
/* FM Radio End */

/* FM Radio Record Begin */
#if 1   /* FM_RADIO_RECORD */

/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_start_record
 * DESCRIPTION
 *  This function is to start record for FM radio
 * PARAMETERS
 *  file_name       : [IN] Full filename
 *  format          : [IN] Record format
 *  handle_p        : [IN] Reserved
 *  handler         : [IN] Callback handler
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_fmr_start_record(void *file_name, U8 format, U8 quality, mdi_handle *handle_p, mdi_callback handler);
extern void mdi_fmr_record_finish_ind(void *inMsg);
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
extern mdi_result mdi_audio_stop_fmr_record_only(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_stop_record
 * DESCRIPTION
 *  This function is to stop FM recording in media task
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mdi_fmr_stop_record(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_fmr_pause_record
 * DESCRIPTION
 *  This function is to pause FM radio record
 * PARAMETERS
 *  handler     : [IN] Callback handler
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_fmr_pause_record(mdi_callback handler);
/*****************************************************************************
 * FUNCTION
 *  mdi_frm_resume_record
 * DESCRIPTION
 *  This function is to resume FM radio record
 * PARAMETERS
 *  handler     : [IN] Callback handler
 * RETURNS
 *  mdi_result
 *****************************************************************************/
extern mdi_result mdi_frm_resume_record(mdi_callback handler);
#endif /* 1 */ 
/* FM Radio Record END */

#ifdef VRSI_ENABLE

extern void mdi_audio_vrsi_trn_prompt_req_hdlr(void *inMsg);
extern void mdi_audio_vrsi_trn_result_ind(void *inMsg);
extern void mdi_audio_vrsi_rcg_prompt_req_hdlr(void *inMsg);
extern void mdi_audio_vrsi_rcg_result_ind(void *inMsg);
extern void mdi_audio_vrsi_err_ind(void *inMsg);
extern mdi_result mdi_audio_vrsi_init(mdi_callback handler);
extern U32 mdi_audio_vrsi_new_session_id(void);
extern void mdi_audio_vrsi_stop(U32 session_id);
extern void mdi_audio_vrsi_close(void);
extern void mdi_audio_vrsi_play_tag_finish_ind(void *inMsg);
extern mdi_result mdi_audio_vrsi_play_tag(U32 session_id, U8 *grammar, U16 tag_id, U8 volume, U8 output_path);
extern void mdi_audio_vrsi_play_tts_finish_ind(void *inMsg);
extern mdi_result mdi_audio_vrsi_play_TTS(U32 session_id, U16 *text, U8 volume, U8 output_path, U8 lang);
extern void mdi_audio_vrsi_register_record(void);
extern void mdi_audio_vrsi_unregister_record(void);

#endif /* VRSI_ENABLE */ 

#if defined(__MMI_POC__)
extern mdi_result mdi_audio_poc_start_encode(mdi_callback handler);
extern mdi_result mdi_audio_poc_stop_encode(void);
extern mdi_result mdi_audio_poc_start_decode(mdi_callback handler);
extern mdi_result mdi_audio_poc_stop_decode(void);
#endif /* defined(__MMI_POC__) */ 

#if defined(BGSND_ENABLE)
extern MMI_BOOL mdi_audio_snd_is_idle(void);
extern mdi_result mdi_audio_snd_check_string_format(void *audio_data, U32 len);
extern mdi_result mdi_audio_snd_check_file_format(void *file_name);
extern mdi_result mdi_audio_snd_play_string_with_vol_path(
                    void *audio_data,
                    U32 len,
                    U16 repeat,
                    mdi_handle *handle_p,
                    mdi_callback handler,
                    U8 volume,
                    U8 path);
extern mdi_result mdi_audio_snd_play_file_with_vol_path(
                    void *file_name,
                    U16 repeat,
                    mdi_handle *handle_p,
                    mdi_callback handler,
                    U8 volume,
                    U8 path);
extern void mdi_audio_snd_play_finish_ind(void *inMsg);
extern mdi_result mdi_audio_snd_stop(void);
extern mdi_result mdi_audio_snd_set_volume(U8 volume);
#endif /* defined(BGSND_ENABLE) */ 

#if defined(AUD_TIME_STRETCH)
extern mdi_result mdi_audio_stretch_check_string_format(void *audio_data, U32 len, U16 format);
extern mdi_result mdi_audio_stretch_check_file_format(void *file_name);
extern mdi_result mdi_audio_stretch_set_speed(U16 speed);
extern void mdi_audio_stretch_close(void);
#endif /* #if defined(AUD_TIME_STRETCH) */

#if defined(AUD_REVERB)
extern mdi_result mdi_audio_reverb_set_mode(U16 mode);
extern mdi_result mdi_audio_reverb_turn_on(void);
extern mdi_result mdi_audio_reverb_turn_off(void);
#endif /* #if defined(AUD_REVERB) */

#if defined(AUD_3D_SURROUND_LSPK) || defined(AUD_3D_SURROUND_EARP)
extern mdi_result mdi_audio_surround_turn_on(U8 mode);
extern mdi_result mdi_audio_surround_turn_off(void);
#endif /* #if defined(AUD_3D_SURROUND_LSPK) || defined(AUD_3D_SURROUND_EARP) */

#if defined(AUDIO_EQUALIZER_ENABLE)
extern mdi_result mdi_audio_eq_set_magnitude(S8 *magnitude);
extern mdi_result mdi_audio_eq_turn_on(void);
extern mdi_result mdi_audio_eq_turn_off(void);
#endif /* #if defined(AUDIO_EQUALIZER_ENABLE) */

#if defined(AUD_BASS_ENHANCEMENT)
extern mdi_result mdi_audio_bass_enhance_turn_on(void);
extern mdi_result mdi_audio_bass_enhance_turn_off(void);
#endif /*#if defined(AUD_BASS_ENHANCEMENT)*/

#if defined(AUD_LOUDNESS_ENABLE)
extern mdi_result mdi_audio_loudness_turn_on(void);
extern mdi_result mdi_audio_loudness_turn_off(void);
#endif /*#if defined(AUD_LOUDNESS_ENABLE)*/

#if defined(AUD_VOCAL_REMOVAL)
extern mdi_result mdi_audio_vocal_removal_turn_on(void);
extern mdi_result mdi_audio_vocal_removal_turn_off(void);
#endif /*#if defined(AUD_VOCAL_REMOVAL)*/

#if defined(AUD_PITCH_SHIFTING)
extern mdi_result mdi_audio_pitch_shifting_turn_on(void);
extern mdi_result mdi_audio_pitch_shifting_turn_off(void);
extern mdi_result mdi_audio_pitch_shifting_set_level(S16 level);
#endif

extern void mdi_audio_set_hw_mute(MMI_BOOL set_mute);

/* Speech for All apps */

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_session_start
 * DESCRIPTION
 *  start speech session (for All apps)
 * PARAMETERS
 *  app_id       : [IN] Application ID in MDI_AUDIO_SPEECH_APP_ID_ENUM
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_speech_session_start(MDI_AUDIO_SPEECH_APP_ID_ENUM app_id);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_session_stop
 * DESCRIPTION
 *  stop speech session (for All apps)
 * PARAMETERS
 *  app_id       : [IN] Application ID in MDI_AUDIO_SPEECH_APP_ID_ENUM
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_speech_session_stop(MDI_AUDIO_SPEECH_APP_ID_ENUM app_id);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_get_app_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MDI_AUDIO_SPEECH_APP_ID_ENUM
 *****************************************************************************/
MDI_AUDIO_SPEECH_APP_ID_ENUM mdi_audio_speech_get_app_id(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_set_app_id
 * DESCRIPTION
 *  This function is to change the current application ID
 * PARAMETERS
 *  app_id       : [IN] Application ID in MDI_AUDIO_SPEECH_APP_ID_ENUM
 * RETURNS
 *  mdi_result
 *****************************************************************************/
void mdi_audio_speech_set_app_id(MDI_AUDIO_SPEECH_APP_ID_ENUM app_id);

/* Speech for GSM & WCDMA apps */

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_codec_start
 * DESCRIPTION
 *  This function is to turn on speech codec
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_speech_codec_start(void);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_codec_stop
 * DESCRIPTION
 *  This function is to turn off speech codec
 * PARAMETERS
 *  void
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_speech_codec_stop(void);

/* Speech for VoIP */

/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_encode_start
 * DESCRIPTION
 *  This function is to start speech encode process (for VoIP)
 * PARAMETERS
 *  rtp_handle      : [IN] RTP handle
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_speech_encode_start(kal_int8 rtp_handle);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_encode_stop
 * DESCRIPTION
 *  This function is to stop speech encode process (for VoIP)
 * PARAMETERS
 *  rtp_handle      : [IN] RTP handle
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_speech_encode_stop(kal_int8 rtp_handle);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_decode_start
 * DESCRIPTION
 *  This function is to start speech decode process (for VoIP)
 * PARAMETERS
 *  rtp_handle      : [IN] RTP handle
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_speech_decode_start(kal_int8 rtp_handle);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_decode_stop
 * DESCRIPTION
 *  This function is to stop speech decode process (for VoIP)
 * PARAMETERS
 *  rtp_handle      : [IN] RTP handle
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_speech_decode_stop(kal_int8 rtp_handle);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_mixer_add
 * DESCRIPTION
 *  This function is to add speech mixer (for VoIP)
 * PARAMETERS
 *  rtp_handle      : [IN] RTP handle
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_speech_mixer_add(kal_int8 rtp_handle);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_mixer_remove
 * DESCRIPTION
 *  This function is to remove speech mixer (for VoIP)
 * PARAMETERS
 *  rtp_handle      : [IN] RTP handle
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_speech_mixer_remove(kal_int8 rtp_handle);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_dtmf_start
 * DESCRIPTION
 *  This function is to start speech DTMF tone (for VoIP)
 * PARAMETERS
 *  rtp_handle      : [IN] RTP handle
 *  code            : [IN] Key code
 *  type            : [IN] Inband or outband tone
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_speech_dtmf_start(kal_int8 rtp_handle, kal_uint8 code, kal_uint8 type);
/*****************************************************************************
 * FUNCTION
 *  mdi_audio_speech_dtmf_stop
 * DESCRIPTION
 *  This function is to stop speech DTMF tone (for VoIP)
 * PARAMETERS
 *  rtp_handle      : [IN] RTP handle
 * RETURNS
 *  mdi_result
 *****************************************************************************/
mdi_result mdi_audio_speech_dtmf_stop(kal_int8 rtp_handle);

/* General purpose TTS */
#ifdef __GENERAL_TTS__
extern mdi_result mdi_audio_tts_set_attr(U32 attr_id, U32 attr_value);
extern mdi_result mdi_audio_tts_play(mdi_audio_tts_struct tts_param);
extern mdi_result mdi_audio_tts_stop(void);
extern mdi_result mdi_audio_tts_pause(void);
extern mdi_result mdi_audio_tts_resume(void);
#endif /*__GENERAL_TTS__*/

//!ignore me! /* For auto answer machine now */
#if defined(__UCM_SUPPORT__) /* && defined(__KEY_TONE_DETECT__) */ 
extern mdi_result mdi_audio_start_keytone_detect(void (*callback)(S16 key_ascii));
extern void mdi_audio_stop_keytone_detect(void);
#endif /*__KEY_TONE_DETECT__*/

//!ignore me! /* Functions that provide MDI to other task */
extern MMI_BOOL mdi_audio_message_dispatcher(void *ilm_ptr);

#if defined(__J2ME__)
extern MMI_BOOL mdi_audio_is_able_to_use_by_other_task(void);
extern void mdi_audio_start_use_by_other_task(mdi_callback handler);
extern void mdi_audio_stop_use_by_other_task(void);
extern void mdi_audio_terminate_use_by_other_task(void);
#endif /*#if defined(__J2ME__)*/

extern void mdi_audio_register_interrupt_callback(mdi_callback handler);
extern void mdi_audio_clear_interrupt_callback(void);
extern MMI_BOOL mdi_audio_mutex_lock_no_wait(S8 *file_p, U32 line_p);
extern void mdi_audio_mutex_lock(S8 *file_p, U32 line_p);
extern void mdi_audio_mutex_unlock(S8 *file_p, U32 line_p);

/* For DRM */
#ifdef __DRM_SUPPORT__
extern void mdi_audio_drm_disable_consume_count(void);
extern void mdi_audio_drm_disable_consume_all(void);
#endif /*__DRM_SUPPORT__*/

extern MMI_ID_TYPE mdi_audio_get_error_info(MDI_RESULT error_code, mmi_event_notify_enum* popup_type);

#endif /* _MDI_AUDIO_H_ */ 

