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
 *  FileManagerDef.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  File Manager internal prototype header.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef _FMGR_TYPE_H_
#define _FMGR_TYPE_H_

/****************************************************************************
* Include Files
*****************************************************************************/

/****************************************************************************
* Define
*****************************************************************************/

/* 
 * Rule 1: DO NOT use compile option in this enum
 *
 * Rule 2: Put enum in CORRECT Order/Group
 */
typedef enum _mmi_fmgr_filetype_enum
{
    FMGR_TYPE_ALL,      /* this type represent all files (included not supported types, like *.doc */
    FMGR_TYPE_UNKNOWN,
    FMGR_TYPE_UNKNOW = FMGR_TYPE_UNKNOWN,   /* Backward compatible */
    FMGR_TYPE_FOLDER,
    FMGR_TYPE_FOLDER_DOT,

    // Image type
    FMGR_TYPE_GRP_IMAGE,
    FMGR_TYPE_BMP,
    FMGR_TYPE_JPG,
    FMGR_TYPE_JPEG,    
    FMGR_TYPE_GIF,
    FMGR_TYPE_PNG,
    FMGR_TYPE_WBMP,
    FMGR_TYPE_WBM,
    FMGR_TYPE_M3D,
    FMGR_TYPE_EMS,
    FMGR_TYPE_ANM,
    FMGR_TYPE_SVG,

    // Audio type
    FMGR_TYPE_GRP_AUDIO,
    FMGR_TYPE_IMY,
    FMGR_TYPE_MID,
    FMGR_TYPE_MIDI,
    FMGR_TYPE_WAV,
    FMGR_TYPE_AMR,
    FMGR_TYPE_AAC,
    FMGR_TYPE_DAF,
    FMGR_TYPE_MP2,
    FMGR_TYPE_VM,
    FMGR_TYPE_AWB,
    FMGR_TYPE_AIF,
    FMGR_TYPE_AIFF,
    FMGR_TYPE_AIFC,
    FMGR_TYPE_AU,
    FMGR_TYPE_SND,
    FMGR_TYPE_M4A,
    FMGR_TYPE_MMF,
    FMGR_TYPE_WMA,
    FMGR_TYPE_BSAC,
    FMGR_TYPE_3GP_AUDIO,
    FMGR_TYPE_MP4_AUDIO,

    // Video type
    FMGR_TYPE_GRP_VIDEO,
    FMGR_TYPE_3GP_VIDEO,
    FMGR_TYPE_MP4_VIDEO,
    FMGR_TYPE_MPG,
    FMGR_TYPE_AVI,
    FMGR_TYPE_3G2,
    FMGR_TYPE_SDP,
    FMGR_TYPE_RAM,
    
    // Certman type
    FMGR_TYPE_GRP_CERT,
    FMGR_TYPE_P12,
    FMGR_TYPE_CER,
    FMGR_TYPE_PFX,
    FMGR_TYPE_DER,
    FMGR_TYPE_PEM,
    FMGR_TYPE_P7B,
    FMGR_TYPE_CRT,
    FMGR_TYPE_SPC,

    // SWFlash group
    FMGR_TYPE_GRP_SWFLASH,
    FMGR_TYPE_CMP,
    FMGR_TYPE_ZDD,
    FMGR_TYPE_VIS,
    FMGR_TYPE_IVIS,
    FMGR_TYPE_KVIS,
    FMGR_TYPE_MVIS,

    // Bookmark group
    FMGR_TYPE_GRP_BOOKMARK,
    FMGR_TYPE_WML,
    FMGR_TYPE_HTML,
    FMGR_TYPE_HTM,
    FMGR_TYPE_XHTML,
    
    /* Note: any group type should be placed above this line */
    // No type, 
    FMGR_TYPE_GRP_NO_GROUP,
    FMGR_TYPE_JAD,
    FMGR_TYPE_JAR,
    FMGR_TYPE_VCF,
    FMGR_TYPE_VCS,
    FMGR_TYPE_LRC,
    FMGR_TYPE_THEME,
    FMGR_TYPE_EBOOK_TXT,
    FMGR_TYPE_EBOOK_PDB,
    FMGR_TYPE_FOTA_FULL,
    FMGR_TYPE_DCF,
/* Vogins Start */
#ifdef __VRE__
    FMGR_TYPE_VXP,
#endif
/* Vogins End */
    FMGR_TYPE_DM,
    FMGR_TYPE_URL,
    FMGR_TYPE_VBM,
    FMGR_TYPE_MBC,

    // DRM special type
    FMGR_TYPE_ODF,

    FMGR_TYPE_HYPER_LINK,
    
    FMGR_TYPE_COUNT

} mmi_fmgr_filetype_enum;

enum {
#if !defined(MP4_DECODE) && defined(__MMI_PURE_AUDIO__)
    FMGR_TYPE_3GP = FMGR_TYPE_3GP_AUDIO,
    FMGR_TYPE_MP4 = FMGR_TYPE_MP4_AUDIO
#else
    FMGR_TYPE_3GP = FMGR_TYPE_3GP_VIDEO,
    FMGR_TYPE_MP4 = FMGR_TYPE_MP4_VIDEO
#endif
};

typedef enum
{
    FMGR_GROUP_IMAGE    = FMGR_TYPE_GRP_IMAGE,
    FMGR_GROUP_AUDIO    = FMGR_TYPE_GRP_AUDIO,
    FMGR_GROUP_VIDEO    = FMGR_TYPE_GRP_VIDEO,
    FMGR_GROUP_SWFLASH  = FMGR_TYPE_GRP_SWFLASH,
    FMGR_GROUP_UNKNOWN  = FMGR_TYPE_COUNT,
    
    FMGR_GROUP_AVATAR = FMGR_TYPE_COUNT+1   // This is used by Avatar app only...
} fmgr_file_group_enum;

#define FMGR_MAX_FILTER_COUNT       (FMGR_TYPE_COUNT-5)

typedef struct
{
    unsigned int mask[(FMGR_TYPE_COUNT+31)/32];
} fmgr_filter_mask_struct;

typedef fmgr_filter_mask_struct FMGR_FILTER;

#define FMGR_FILTER_INIT(f)             ( memset((f)->mask, 0, sizeof((f)->mask)) )

#define FMGR_FILTER_SET(f,b)            ( ((f)->mask[b/32]) |= (((unsigned int)1)<<(b%32)) )
#define FMGR_FILTER_IS_SET(f,b)         ( ((f)->mask[b/32]) &  (((unsigned int)1)<<(b%32)) )
#define FMGR_FILTER_CLEAR(f,b)          ( (f)->mask[b/32] &= (~(((unsigned int)1)<<(b%32))) )

#define FMGR_FILTER_SET_ALL(a) \
    do { \
        memset((a)->mask, 0xff, sizeof((a)->mask)); \
    } while(0)

/*  To Use following macro, please #include "FileMgrGProt.h"
 */
#define FMGR_FILTER_SET_AUDIO(f)        mmi_fmgr_filter_set_group(f, FMGR_TYPE_GRP_AUDIO)
#define FMGR_FILTER_IS_SET_AUDIO(f)     mmi_fmgr_filter_check_group(f, FMGR_TYPE_GRP_AUDIO)

#define FMGR_FILTER_SET_IMAGE(f)        mmi_fmgr_filter_set_group(f, FMGR_TYPE_GRP_IMAGE)
#define FMGR_FILTER_IS_SET_IMAGE(f)     mmi_fmgr_filter_check_group(f, FMGR_TYPE_GRP_IMAGE)

#define FMGR_FILTER_SET_VIDEO(f)        mmi_fmgr_filter_set_group(f, FMGR_TYPE_GRP_VIDEO)
#define FMGR_FILTER_IS_SET_VIDEO(f)     mmi_fmgr_filter_check_group(f, FMGR_TYPE_GRP_VIDEO)

#define FMGR_FILTER_SET_SWFLASH(f)      mmi_fmgr_filter_set_group(f, FMGR_TYPE_GRP_SWFLASH)
#define FMGR_FILTER_IS_SET_SWFLASH(f)   mmi_fmgr_filter_check_group(f, FMGR_TYPE_GRP_SWFLASH)

/****************************************************************************/
/*
 *  File type defaul folder information
 */

#ifdef __MMI_MY_FAVORITE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
#define FMGR_DEFAULT_FOLDER_EBOOKS      L"Ebook\\"
#define FMGR_DEFAULT_FOLDER_PHOTOS      L"Photos\\"
#define FMGR_DEFAULT_FOLDER_RECEIVED    L"Received\\"
#endif 

#define FMGR_DEFAULT_FOLDER_PHBIMAGES   "Phbimage"
#define FMGR_DEFAULT_FILE_PHBVIDEO      L"phb_video.dat"

/* default path */
extern kal_wchar CUSTOM_AT_AUDIO_DOWNLOAD_FOLDER_NAME[];
extern kal_wchar CUSTOM_AT_IMAGE_DOWNLOAD_FOLDER_NAME[];

#define FMGR_DEFAULT_FOLDER_IMAGES      CUSTOM_AT_IMAGE_DOWNLOAD_FOLDER_NAME
#define FMGR_DEFAULT_FOLDER_AUDIO       CUSTOM_AT_AUDIO_DOWNLOAD_FOLDER_NAME
#define FMGR_DEFAULT_FOLDER_VIDEO       L"Videos\\"  
#define FMGR_DEFAULT_FOLDER_SWFLASH     L"SWFlash\\"
#define FMGR_DEFAULT_FOLDER_LANGLN      L"Englishto\\"
#define FMGR_DEFAULT_FOLDER_TEMP        L"Download\\"
#define FMGR_DEFAULT_FOLDER_THEMES      L"Themes\\"
#define FMGR_DEFAULT_FOLDER_BARCODE     L"DATA\\"
#define FMGR_DEFAULT_FOLDER_MMSBOX      L"MMSBox\\"

/****************************************************************************/
/*
 *  File type limit infomrmation
 */
/* file limit */
#define FMGR_LIMIT_IMAGE_VIEWER         g_fmgr_image_viewer_limit_arry
#define FMGR_LIMIT_SCREEN_SAVER         g_fmgr_screensaver_limit_arry
#define FMGR_LIMIT_WALLPAPER            g_fmgr_wallpaper_limit_arry
#ifdef __MMI_SUB_WALLPAPER__
#define FMGR_LIMIT_SUB_WALLPAPER        g_fmgr_sub_wallpaper_limit_arry
#endif 
#define FMGR_LIMIT_POWER_ON_OFF_DSPL    g_fmgr_power_on_off_disp_limit_arry
#define FMGR_LIMIT_CALLER_PICTURE       g_fmgr_caller_picture_limit_arry
#define FMGR_LIMIT_CALLER_VIDEO         g_fmgr_caller_video_limit_arry
#define FMGR_LIMIT_MMS_CATEGORY         g_fmgr_mms_category_limit_arry

extern const int g_fmgr_image_viewer_limit_arry[];
extern const int g_fmgr_wallpaper_limit_arry[];
extern const int g_fmgr_sub_wallpaper_limit_arry[];
extern const int g_fmgr_screensaver_limit_arry[];
extern const int g_fmgr_power_on_off_disp_limit_arry[];
extern const int g_fmgr_caller_picture_limit_arry[];
extern const int g_fmgr_caller_video_limit_arry[];
extern const int g_fmgr_mms_category_limit_arry[];


/****************************************************************************/
/*
 *  File type temp filename
 */
/* temp filename */
#define FMGR_TEMP_FILE_IRDA                  L"~received.tmp"
#define FMGR_TEMP_FILE_JAVA                  L"~java.tmp"
#define FMGR_TEMP_FILE_VCARD                 L"~vcard.tmp"
#define FMGR_TEMP_FILE_VCALENDAR             L"~vcalendar.tmp"
#define FMGR_TEMP_FILE_CAMERA                L"~camera.jpg"
#define FMGR_TEMP_FILE_MELODY                L"~rngc.imy"
#define FMGR_TEMP_FILE_EMAIL_NEW             L"~email.tmp"
#define FMGR_TEMP_FILE_EMAIL_SMTP            L"~smtp.tmp"
#define FMGR_TEMP_FILE_VIDEO_AUD             L"~video_aud.tmp"
#define FMGR_TEMP_FILE_VIDEO_AUD_SAMPLE      L"~video_aud_sample.tmp"
#define FMGR_TEMP_FILE_VIDEO_AUD_REAL        L"~video_aud_real.tmp"
#define FMGR_TEMP_FILE_VIDEO_VISUAL          L"~video_aud.tmp"
#define FMGR_TEMP_FILE_VIDEO_VISUAL_SAMPLE   L"~video_aud_sample.tmp"
#define FMGR_TEMP_FILE_VIDEO_VISUAL_REAL     L"~video_aud_real.tmp"
#define FMGR_TEMP_FILE_SWFLASH               L"~swflash.tmp"

/****************************************************************************/
/*
 * Notice. This enum must be sync with the size with the LID size in nvram_common_defs.h.
 * They must be wrapped with same compile options.
 *
 * "\mcu\custom\common\PLUTO_MMI\nvram_common_defs.h"
 */

typedef enum
{
#if defined (__MMI_CAMERA__) || defined(__MMI_CAMCORDER__)
    FMGR_PATH_ID_CAMERA,
#endif

#if defined(__MMI_VIDEO_PLAYER__) || (defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_CAMCORDER__))
    FMGR_PATH_ID_VIDEO,
#endif 

#ifdef __MMI_PHOTOEDITOR__
    FMGR_PATH_ID_PHOTO_EDITOR,
#endif

#ifdef __MMI_SLIDESHOW__
    FMGR_PATH_ID_SLIDE_SHOW_AUDIO,
    FMGR_PATH_ID_SLIDE_SHOW_PLAY,
#endif

#ifdef __MMI_VIDEO_STREAM__
    FMGR_PATH_ID_VIDEO_STREAM,
#endif 

#ifdef __MMI_VIDEO_EDITOR__
    FMGR_PATH_ID_VIDEO_EDITOR,
#endif

#if defined(__MMI_IMAGE_VIEWER__) || defined(__MMI_FILE_MANAGER__)
    FMGR_PATH_ID_IMAGE_VIEWER,
#endif
    /* number of id */
    FMGR_PATH_ID_COUNT
} FMGR_PATH_ID_ENUM;


/****************************************************************************
* Global variable
*****************************************************************************/


/****************************************************************************
* Global Function
*****************************************************************************/


#endif /* _FMGR_TABLE_H_ */


