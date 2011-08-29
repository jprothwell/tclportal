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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef _FMGR_TABLE_H_
#define _FMGR_TABLE_H_

#ifndef _FMGR_TABLE_CONTENT_C_
#error "This file can only be included by FileMgrTable.c"
#endif

/****************************************************************************
* Include Files
*****************************************************************************/
#include "FileMgrGProt.h"
#include "FileMgrServiceHdlr.h"

/* include App's resource/callback prototype here */
#include "ImageViewerResDef.h"
#include "ComposeRingToneDefs.h"
#include "ABRepeaterResDef.h"
#include "VdoPlyResDef.h"
#include "EbookResDef.h"
#include "SWFlashResDef.h"
#include "CatScreenBrowserResDef.h"
#include "JavaAgencyGProt.h"
#include "MobileTVPlayerGprot.h"
#include "PhoneSetupGprots.h"

#if defined(__MMI_SNDREC_NEW__)
    #include "SndrecResdef.h"
#elif defined(__MMI_SNDREC_OLD__)
    #include "SoundRecorderResDef.h"
#endif

#ifdef __MMI_DOWNLOAD_AGENT__
#include "DLAgentDef.h"
#include "DLAgentGProt.h"
#endif
/* Vogins Start */
#ifdef __VRE__
#include "VREDef.h"
#endif
/* Vogins End */
#ifdef __MMI_BARCODEREADER__
#include "MMI_features_barcodereader.h"
    #ifdef __MMI_OP01_BARCODEREADER__
/* under construction !*/
    #endif
#endif

#if defined(__MMI_FILE_MANAGER__)
extern void mmi_sndrec_option_enabler(U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo);
extern void mmi_ebook_option_enabler(U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo);
extern void mmi_rngc_option_enabler(U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo);
extern void mmi_swflash_option_enabler(U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo);
#endif

/****************************************************************************
* Define
*****************************************************************************/

/***** Macro *****/

/****************************************************************************/
/*
 *  Detail filetype, record all information
 */
#define FT_INFO_D(type, ext, large_icon, small_icon, opt_menu, use_menu, send_menu, folder_id, DRM_permision)

/*
 *  simple file type, record only necessary information, other information are from belonged group
 */
#define FT_INFO(type, ext, large_icon)

/*
 *  File group information
 */
#define FG_INFO(type, small_icon, opt_menu, use_menu, send_menu, folder_id, DRM_permision)


/*  
 *  type:       file type enum (see FileMgrType.h)
 *  large_icon: image id of large_icon
 *  small_icon: image id of small_icon
 *  opt_menu:   option menu in FmgrApp  (if 0, use default <MENU_ID_FMGR_GEN_TYPE_OPTIONS>)
 *  use_menu:   "use as" forward menu   (if 0, this option is hidden)
 *  send_menu:  "send via" forward menu (if 0, use default <MENU_ID_FMGR_GEN_SEND_OPTION>)
 *                                      (this optin is hidden if use <MENU_ID_FMGR_EMPTY_SEND_OPTION>)
 *  folder_id:  default folder
 *  DRM_permission: 
 */

/****************************************************************************/

#define FMGR_FILE_TABLE_COL \
    FT_INFO_D(FMGR_TYPE_FOLDER, NULL,           IMG_ID_FMGR_FILE_TYPE_FOLDER, IMG_ID_FMGR_ICON_FILE_TYPE_FOLDER, MENU_ID_FMGR_FOLDER_OPTIONS, 0, 0, 0, 0) \
    /* Image */ \
    FG_INFO(FMGR_TYPE_GRP_IMAGE, IMG_ID_FMGR_ICON_FILE_TYPE_IMG, MENU_ID_FMGR_IMG_TYPE_OPTIONS, MENU_ID_FMGR_IMG_FWD_USE_OPTION, MENU_ID_FMGR_IMG_FWD_SEND_OPTION, MMI_FMGR_IMAGE_FOLDER, DRM_PERMISSION_DISPLAY) \
    FT_INFO(FMGR_TYPE_BMP,      "BMP",          IMG_ID_FMGR_FILE_TYPE_BMP) \
    FT_INFO_JPG \
    FT_INFO(FMGR_TYPE_GIF,      "GIF",          IMG_ID_FMGR_FILE_TYPE_GIF) \
    FT_INFO_PNG \
    FT_INFO(FMGR_TYPE_WBMP,     "WBMP",         IMG_ID_FMGR_FILE_TYPE_WBMP) \
    FT_INFO(FMGR_TYPE_WBM,      "WBM",          IMG_ID_FMGR_FILE_TYPE_WBMP) \
    FT_INFO_M3D \
    FT_INFO(FMGR_TYPE_EMS,      "EMS",          IMG_ID_FMGR_FILE_TYPE_EMS) \
    FT_INFO(FMGR_TYPE_ANM,      "ANM",          IMG_ID_FMGR_FILE_TYPE_ANM) \
    FT_INFO_SVG \
    /* Audio */ \
    FG_INFO(FMGR_TYPE_GRP_AUDIO, IMG_ID_FMGR_ICON_FILE_TYPE_AUD, MENU_ID_FMGR_AUD_TYPE_OPTIONS, MENU_ID_FMGR_AUD_FWD_USE_OPTION, MENU_ID_FMGR_AUD_FWD_SEND_OPTION, MMI_FMGR_AUDIO_FOLDER, DRM_PERMISSION_PLAY) \
    FT_INFO(FMGR_TYPE_IMY,      "IMY",          IMG_ID_FMGR_FILE_TYPE_IMY) \
    FT_INFO(FMGR_TYPE_MID,      "MID",          IMG_ID_FMGR_FILE_TYPE_MID) \
    FT_INFO(FMGR_TYPE_MIDI,     "MIDI",         IMG_ID_FMGR_FILE_TYPE_MID) \
    FT_INFO(FMGR_TYPE_WAV,      "WAV",          IMG_ID_FMGR_FILE_TYPE_WAV) \
    FT_INFO(FMGR_TYPE_AMR,      "AMR",          IMG_ID_FMGR_FILE_TYPE_AMR) \
    FT_INFO_AAC \
    FT_INFO_DAF \
    FT_INFO(FMGR_TYPE_VM,       "VM",           IMG_ID_FMGR_FILE_TYPE_VM) \
    FT_INFO_AWB \
    FT_INFO_AIFF \
    FT_INFO_AU \
    FT_INFO_MMF \
    FT_INFO_WMA \
    FT_INFO_BSAC \
    /* Video */ \
    FG_INFO(FMGR_TYPE_GRP_VIDEO, IMG_ID_FMGR_ICON_FILE_TYPE_VDO, MENU_ID_FMGR_VID_TYPE_OPTIONS, MENU_ID_FMGR_VID_FWD_USE_OPTION, MENU_ID_FMGR_VID_FWD_SEND_OPTION, MMI_FMGR_VIDEO_FOLDER, DRM_PERMISSION_PLAY) \
    FT_INFO_3GP \
    FT_INFO_MPG \
    FT_INFO_AVI \
    FT_INFO_SDP \
    /* Certman */ \
    FT_INFO_CERTMAN \
    /* swFlash */ \
    FT_INFO_SWF \
    /* Bookmark */ \
    FT_INFO_BOOKMARK \
/* Vogins Start */ \
    FT_INFO_VRE \
/* Vogins End */ \
    /* Other - DO NOT USE FT_INFO below this line */ \
    FG_INFO(FMGR_TYPE_GRP_NO_GROUP, 0, 0, 0, 0, 0, 0) \
    FT_INFO_JAVA \
    FT_INFO_VCARD \
    FT_INFO_VCAL \
    FT_INFO_D(FMGR_TYPE_LRC,      "LRC",          0, 0, 0, 0, MENU_ID_FMGR_GEN_SEND_OPTION, 0, 0) \
    FT_INFO_THEME \
    FT_INFO_EBOOK \
    FT_INFO_FOTA \
    FT_INFO_D(FMGR_TYPE_DCF,      "DCF",          0, 0, 0, 0, MENU_ID_FMGR_GEN_SEND_OPTION, 0, 0)\
    FT_INFO_D(FMGR_TYPE_DM,       "DM",           0, 0, 0, 0, MENU_ID_FMGR_GEN_SEND_OPTION, 0, 0)\
    FT_INFO_VBM \
    FT_INFO_BARCODE \
    FT_INFO_ODF \


/*
#ifdef
#define FT_INFO_
#else
#define FT_INFO_
#endif
*/

/*****************************IMAGE******************************************/

#ifdef JPG_DECODE
#define FT_INFO_JPG \
    FT_INFO(FMGR_TYPE_JPG,      "JPG",          IMG_ID_FMGR_FILE_TYPE_JPG) \
    FT_INFO(FMGR_TYPE_JPEG,     "JPEG",         IMG_ID_FMGR_FILE_TYPE_JPG) 
#else
#define FT_INFO_JPG
#endif

#ifdef GDI_USING_PNG
#define FT_INFO_PNG \
    FT_INFO(FMGR_TYPE_PNG,      "PNG",          IMG_ID_FMGR_FILE_TYPE_PNG)
#else
#define FT_INFO_PNG
#endif

#ifdef M3D_MMI_SUPPORT
#define FT_INFO_M3D \
    FT_INFO(FMGR_TYPE_M3D,      "M3D",          IMG_ID_FMGR_FILE_TYPE_M3D)
#else
#define FT_INFO_M3D
#endif

/*****************************AUDIO******************************************/

#ifdef AAC_DECODE
#define FT_INFO_AAC \
    FT_INFO(FMGR_TYPE_AAC,      "AAC",          IMG_ID_FMGR_FILE_TYPE_AAC) \
    FT_INFO(FMGR_TYPE_M4A,      "M4A",          IMG_ID_FMGR_FILE_TYPE_M4A)
#else
#define FT_INFO_AAC
#endif

#if defined(DAF_DECODE) && defined(MUSICAM_DECODE)
#define FT_INFO_DAF \
    FT_INFO(FMGR_TYPE_DAF,      "MP3",          IMG_ID_FMGR_FILE_TYPE_DAF) \
    FT_INFO(FMGR_TYPE_MP2,      "MP2",          IMG_ID_FMGR_FILE_TYPE_DAF)
#elif defined(DAF_DECODE)
#define FT_INFO_DAF \
    FT_INFO(FMGR_TYPE_DAF,      "MP3",          IMG_ID_FMGR_FILE_TYPE_DAF)
#else
#define FT_INFO_DAF
#endif

#ifdef AMRWB_DECODE
#define FT_INFO_AWB \
    FT_INFO(FMGR_TYPE_AWB,      "AWB",          IMG_ID_FMGR_FILE_TYPE_AWB)
#else
#define FT_INFO_AWB
#endif

#ifdef AIFF_DECODE
#define FT_INFO_AIFF \
    FT_INFO(FMGR_TYPE_AIF,      "AIF",          IMG_ID_FMGR_FILE_TYPE_AIF) \
    FT_INFO(FMGR_TYPE_AIFF,     "AIFF",         IMG_ID_FMGR_FILE_TYPE_AIF) \
    FT_INFO(FMGR_TYPE_AIFC,     "AIFC",         IMG_ID_FMGR_FILE_TYPE_AIF)
#else
#define FT_INFO_AIFF
#endif

#ifdef AU_DECODE
#define FT_INFO_AU \
    FT_INFO(FMGR_TYPE_AU,       "AU",           IMG_ID_FMGR_FILE_TYPE_AU ) \
    FT_INFO(FMGR_TYPE_SND,      "SND",          IMG_ID_FMGR_FILE_TYPE_SND)
#else
#define FT_INFO_AU
#endif

#ifdef YAMAHA_MA3
#define FT_INFO_MMF \
    FT_INFO(FMGR_TYPE_MMF,      "MMF",          IMG_ID_FMGR_FILE_TYPE_DAF)
#else
#define FT_INFO_MMF
#endif

#ifdef WMA_DECODE
#define FT_INFO_WMA \
    FT_INFO(FMGR_TYPE_WMA,      "WMA",          IMG_ID_FMGR_FILE_TYPE_DAF)
#else
#define FT_INFO_WMA
#endif

#ifdef BSAC_DECODE
/* under construction !*/
/* under construction !*/
#else
#define FT_INFO_BSAC
#endif

/*****************************VIDEO******************************************/

#if defined(MP4_DECODE) || defined(__MMI_PURE_AUDIO__)
#define FT_INFO_3GP \
    FT_INFO(FMGR_TYPE_3GP,      "3GP",          IMG_ID_FMGR_FILE_TYPE_3GP) \
    FT_INFO(FMGR_TYPE_MP4,      "MP4",          IMG_ID_FMGR_FILE_TYPE_MP4) 
#else
#define FT_INFO_3GP
#endif

#ifdef MP4_DECODE
#define FT_INFO_MPG \
    FT_INFO(FMGR_TYPE_MPG,      "MPG",          IMG_ID_FMGR_FILE_TYPE_MP4) \
    FT_INFO(FMGR_TYPE_3G2,      "3G2",          IMG_ID_FMGR_FILE_TYPE_3GP)
#else
#define FT_INFO_MPG
#endif

#ifdef MJPG_SUPPORT
#define FT_INFO_AVI \
    FT_INFO(FMGR_TYPE_AVI,      "AVI",          IMG_ID_FMGR_FILE_TYPE_AVI)
#else
#define FT_INFO_AVI
#endif


/*****************************OTHER******************************************/

#ifdef __J2ME__
#define FT_INFO_JAVA \
    FT_INFO_D(FMGR_TYPE_JAD,    "JAD",          IMG_ID_FMGR_FILE_TYPE_JAD, IMG_ID_FMGR_ICON_FILE_TYPE_JAVA, MENU_ID_FMGR_JAVA_TYPE_OPTIONS, 0, MENU_ID_FMGR_GEN_SEND_OPTION, 0, 0) \
    FT_INFO_D(FMGR_TYPE_JAR,    "JAR",          IMG_ID_FMGR_FILE_TYPE_JAR, IMG_ID_FMGR_ICON_FILE_TYPE_JAVA, MENU_ID_FMGR_JAVA_TYPE_OPTIONS, 0, MENU_ID_FMGR_GEN_SEND_OPTION, 0, 0)
#else
#define FT_INFO_JAVA
#endif

#ifdef __MMI_VCARD__
#define FT_INFO_VCARD \
    FT_INFO_D(FMGR_TYPE_VCF,      "VCF",          IMG_ID_FMGR_FILE_TYPE_VCF, IMG_ID_FMGR_ICON_FILE_TYPE_VCF, 0, MENU_ID_FMGR_VCARD_FWD_USE_OPTION, MENU_ID_FMGR_VCARD_FWD_SEND_OPTION, 0, 0)
#else
#define FT_INFO_VCARD
#endif

#ifdef __MMI_VCALENDAR__
#define FT_INFO_VCAL \
    FT_INFO_D(FMGR_TYPE_VCS,      "VCS",          IMG_ID_FMGR_FILE_TYPE_VCS, IMG_ID_FMGR_ICON_FILE_TYPE_VCS, 0, MENU_ID_FMGR_VCAL_FWD_USE_OPTION, MENU_ID_FMGR_VCAL_FWD_SEND_OPTION, 0, 0) 
#else
#define FT_INFO_VCAL
#endif

#ifdef __MMI_SVG__
/* under construction !*/
/* under construction !*/
#else
#define FT_INFO_SVG
#endif

#ifdef __MMI_EBOOK_READER__
#define FT_INFO_EBOOK \
    FT_INFO_D(FMGR_TYPE_EBOOK_TXT,"TXT",          IMG_EBOOK_FMGR_TXT_LARGE_TYPE, IMG_EBOOK_FMGR_TXT_SMALL_TYPE, MENU_ID_FMGR_EBOOK_TYPE_OPTIONS, 0, MENU_ID_FMGR_GEN_SEND_OPTION, 0, 0) \
    FT_INFO_D(FMGR_TYPE_EBOOK_PDB,"PDB",          IMG_EBOOK_FMGR_PDB_LARGE_TYPE, IMG_EBOOK_FMGR_PDB_SMALL_TYPE, MENU_ID_FMGR_EBOOK_TYPE_OPTIONS, 0, MENU_ID_FMGR_GEN_SEND_OPTION, 0, 0)
#else
#define FT_INFO_EBOOK
#endif

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
#define FT_INFO_THEME \
    FT_INFO_D(FMGR_TYPE_THEME,    "MED",          IMG_ID_FMGR_FILE_TYPE_THEME, IMG_ID_FMGR_ICON_FILE_TYPE_THEME, MENU_ID_FMGR_THEME_TYPE_OPTIONS, 0, MENU_ID_FMGR_GEN_SEND_OPTION, 0, 0)
#else
#define FT_INFO_THEME
#endif

#if defined(__MMI_OP00_BARCODEREADER__)
#define FT_INFO_BARCODE \
    FT_INFO_D(FMGR_TYPE_MBC,      "MBC",          IMG_ID_FMGR_FILE_TYPE_MBC, IMG_ID_FMGR_ICON_FILE_TYPE_MBC, MENU_ID_BARCODEREADER_FILE_OPTION, 0, MENU_ID_FMGR_GEN_SEND_OPTION, 0, 0)
#elif defined(__MMI_OP01_BARCODEREADER__)
/* under construction !*/
/* under construction !*/
#else
#define FT_INFO_BARCODE
#endif

#ifdef __MMI_SWFLASH__
#define FT_INFO_SWF \
    FG_INFO(FMGR_TYPE_GRP_SWFLASH, 0xFFFF, MENU_ID_SWFLASH_OPTION, MENU_ID_FMGR_MFH_FWD_USE_OPTION, MENU_ID_FMGR_MFH_FWD_SEND_OPTION, 0, 0) \
    /* FT_INFO_D(FMGR_TYPE_CMP,    "CMP",          IMG_ID_FMGR_FILE_TYPE_UNKNOWN, 0xFFFF, MENU_ID_SWFLASH_OPTION, 0, MENU_ID_FMGR_GEN_SEND_OPTION, 0, 0) */ \
    FT_INFO(FMGR_TYPE_ZDD,      "ZDD",          IMG_ID_FMGR_FILE_TYPE_ZDD) \
    FT_INFO(FMGR_TYPE_VIS,      "VIS",          IMG_ID_FMGR_FILE_TYPE_VIS) \
    FT_INFO(FMGR_TYPE_IVIS,     "IVIS",         IMG_ID_FMGR_FILE_TYPE_IVIS) \
    FT_INFO(FMGR_TYPE_KVIS,     "KVIS",         IMG_ID_FMGR_FILE_TYPE_KVIS) \
    FT_INFO(FMGR_TYPE_MVIS,     "MVIS",         IMG_ID_FMGR_FILE_TYPE_MVIS)
#else
#define FT_INFO_SWF
#endif

#ifdef __MMI_VIDEO_STREAM__
#define FT_INFO_SDP \
    FT_INFO_D(FMGR_TYPE_SDP,      "SDP",          IMG_ID_FMGR_FILE_TYPE_SDP, 0, 0, 0xFFFF, 0, 0, 0) \
    FT_INFO_D(FMGR_TYPE_RAM,      "RAM",          IMG_ID_FMGR_FILE_TYPE_RAM, 0, 0, 0xFFFF, 0, 0, 0)
#else
#define FT_INFO_SDP
#endif

#ifdef __MMI_VBOOKMARK__ 
#define FT_INFO_VBM \
    FT_INFO_D(FMGR_TYPE_URL,      "URL",          IMG_ID_FMGR_FILE_TYPE_URL, IMG_ID_FMGR_ICON_FILE_TYPE_VBOOKMARK, MENU_ID_FMGR_VBOOKMARK_TYPE_OPTIONS, 0, MENU_ID_FMGR_VBOOKMARK_FWD_SEND_OPTION, 0, 0) \
    FT_INFO_D(FMGR_TYPE_VBM,      "VBM",          IMG_ID_FMGR_FILE_TYPE_VBM, IMG_ID_FMGR_ICON_FILE_TYPE_VBOOKMARK, MENU_ID_FMGR_VBOOKMARK_TYPE_OPTIONS, 0, MENU_ID_FMGR_VBOOKMARK_FWD_SEND_OPTION, 0, 0)
#else
#define FT_INFO_VBM
#endif

#ifdef __MMI_BROWSER_2__
#define FT_INFO_BOOKMARK \
    FG_INFO(FMGR_TYPE_GRP_BOOKMARK, IMG_ID_FMGR_FILE_TYPE_HTM, MENU_ID_FMGR_BOOKMARK_TYPE_OPTIONS, 0, MENU_ID_FMGR_GEN_SEND_OPTION, 0, 0) \
    FT_INFO(FMGR_TYPE_WML,      "WML",          IMG_ID_FMGR_BRW_WML_LARGE_TYPE) \
    FT_INFO(FMGR_TYPE_HTML,     "HTML",         IMG_ID_FMGR_BRW_HTML_LARGE_TYPE) \
    FT_INFO(FMGR_TYPE_HTM,      "HTM",          IMG_ID_FMGR_BRW_HTML_LARGE_TYPE) \
    FT_INFO(FMGR_TYPE_XHTML,    "XHTML",        IMG_ID_FMGR_BRW_XHTML_LARGE_TYPE) 
#else
#define FT_INFO_BOOKMARK
#endif
/* Vogins Start */
#ifdef __VRE__
#define FT_INFO_VRE \
    FT_INFO_D(FMGR_TYPE_VXP,    "VXP",          IMAGE_VRE_LARGE_ICON, IMAGE_VRE_SMALL_ICON, MENU_ID_FMGR_VRE_TYPE_OPTIONS, 0, MENU_ID_FMGR_GEN_SEND_OPTION, 0, 0)
#else
#define FT_INFO_VRE
#endif
/* Vogins End */
#ifdef __CERTMAN_SUPPORT__
#define FT_INFO_CERTMAN \
    FG_INFO(FMGR_TYPE_GRP_CERT, IMG_ID_FMGR_FILE_TYPE_CER, MENU_ID_FMGR_CERT_TYPE_OPTIONS, 0, MENU_ID_FMGR_GEN_SEND_OPTION, 0, 0) \
    FT_INFO(FMGR_TYPE_P12,      "P12",          IMG_ID_FMGR_CER_P12_LARGE_TYPE) \
    FT_INFO(FMGR_TYPE_CER,      "CER",          IMG_ID_FMGR_CER_CER_LARGE_TYPE) \
    FT_INFO(FMGR_TYPE_PFX,      "PFX",          IMG_ID_FMGR_CER_PFX_LARGE_TYPE) \
    FT_INFO(FMGR_TYPE_DER,      "DER",          IMG_ID_FMGR_CER_DER_LARGE_TYPE) \
    FT_INFO(FMGR_TYPE_PEM,      "PEM",          IMG_ID_FMGR_CER_PEM_LARGE_TYPE) \
    FT_INFO(FMGR_TYPE_P7B,      "P7B",          IMG_ID_FMGR_CER_P7B_LARGE_TYPE) \
    FT_INFO(FMGR_TYPE_CRT,      "CRT",          IMG_ID_FMGR_CER_CRT_LARGE_TYPE) \
    FT_INFO(FMGR_TYPE_SPC,      "SPC",          IMG_ID_FMGR_CER_SPC_LARGE_TYPE)
#else
#define FT_INFO_CERTMAN
#endif

#ifdef __MMI_FWU_VIA_FILE__
#define FT_INFO_FOTA \
    FT_INFO_D(FMGR_TYPE_FOTA_FULL,"", 0, 0, 0, 0, MENU_ID_FMGR_GEN_SEND_OPTION, 0, 0)
#else
#define FT_INFO_FOTA
#endif

#ifdef __DRM_V02__
#define FT_INFO_ODF \
    FT_INFO_D(FMGR_TYPE_ODF,      "ODF",          IMG_ID_FMGR_FILE_TYPE_ODF_MULTI_PART, IMG_ID_FMGR_ICON_FILE_TYPE_ODF, MENU_ID_FMGR_DRM_ODF_TYPE_OPTIONS, 0, MENU_ID_FMGR_GEN_SEND_OPTION, 0, 0)
#else
#define FT_INFO_ODF
#endif


/****************************************************************************/
/*
 *  File type defaul folder information
 */

#define FOLDER_INFO(type, path) type,

#ifdef __MMI_EBOOK_READER__
    #define FOLDER_INFO_EBOOK   FOLDER_INFO(MMI_FMGR_EBOOK_FOLDER, FMGR_DEFAULT_FOLDER_EBOOKS)
#else
    #define FOLDER_INFO_EBOOK
#endif

#define FMGR_FOLDER_TABLE_COL \
    FOLDER_INFO(MMI_FMGR_RECEIVED_FOLDER,   FMGR_DEFAULT_FOLDER_RECEIVED) \
    FOLDER_INFO(MMI_FMGR_TEMP_FOLDER,       FMGR_DEFAULT_FOLDER_TEMP) \
    FOLDER_INFO(MMI_FMGR_IMAGE_FOLDER,      FMGR_DEFAULT_FOLDER_IMAGES) \
    FOLDER_INFO(MMI_FMGR_AUDIO_FOLDER,      FMGR_DEFAULT_FOLDER_AUDIO) \
    FOLDER_INFO(MMI_FMGR_VIDEO_FOLDER,      FMGR_DEFAULT_FOLDER_VIDEO) \
    FOLDER_INFO_EBOOK \
    FOLDER_INFO(MMI_FMGR_PHOTO_FOLDER,      FMGR_DEFAULT_FOLDER_PHOTOS) \
    FOLDER_INFO(MMI_FMGR_SWFLASH_FOLDER,    FMGR_DEFAULT_FOLDER_SWFLASH) \
    FOLDER_INFO(MMI_FMGR_LANGLN_FOLDER,     FMGR_DEFAULT_FOLDER_LANGLN) \
    FOLDER_INFO(MMI_FMGR_THEMES_FOLDER,     FMGR_DEFAULT_FOLDER_THEMES) \
    FOLDER_INFO(MMI_FMGR_BARCODE_FOLDER,    FMGR_DEFAULT_FOLDER_BARCODE) \

typedef enum 
{
    FMGR_FOLDER_TABLE_COL
    MMI_FMGR_FOLDER_NUM
} mmi_fmgr_folder_enum;

#if defined(__MMI_FILE_MANAGER__)

/****************************************************************************/
/*
 *  App type information
 */
#define APP_INFO(app_id, string_id, root_menu_id)

#ifdef __MMI_SOUND_RECORDER_STYLE_X__
#define APP_INFO_SOUND_REC \
    APP_INFO(APP_SOUNDRECORDER,    STR_ID_SNDREC_LIST,                  MENU_ID_SNDREC_MAIN         ) 
#elif (defined(__MMI_SOUND_RECORDER__) && defined(__MMI_SNDREC_OLD__))
#define APP_INFO_SOUND_REC \
    APP_INFO(APP_SOUNDRECORDER,    STR_ID_SNDREC_MAIN,                  MENU_ID_SNDREC_MAIN         )
#elif (defined(__MMI_SOUND_RECORDER__) && defined(__MMI_SNDREC_NEW__))/* For new sound recorder */
#define APP_INFO_SOUND_REC \
    APP_INFO(APP_SOUNDRECORDER,    STR_ID_SNDREC_MAIN,                  MENU_ID_SNDREC_MAIN         )
#else
#define APP_INFO_SOUND_REC
#endif

#ifdef __MMI_OP01_BARCODEREADER__
/* under construction !*/
/* under construction !*/
#else
#define APP_INFO_BARCODE_OP01
#endif

#ifdef __MMI_SWFLASH__
#define APP_INFO_SWFLASH \
    APP_INFO(APP_SWFLASH,          STR_ID_SWFLASH_APP,                  0                           )
#else
#define APP_INFO_SWFLASH 
#endif

#ifdef __MMI_CSB_BROWSER__
#define APP_INFO_CSB \
    APP_INFO(APP_CSB,              STR_ID_CSB_TEXT,                     0                           )
#else
#define APP_INFO_CSB 
#endif

#ifdef __MMI_AB_REPEATER__
#define APP_INFO_ABREPEATER \
    APP_INFO(APP_ABREPEATER,       STR_ID_ABREPEAT_TITLE,               MENU_ID_ABREPEAT_APP_MENU_ITEM    )
#else
#define APP_INFO_ABREPEATER
#endif

#if defined(__MMI_RING_COMPOSER__) && defined(__MMI_IMELODY_SUPPORT__)
#define APP_INFO_COMPOSER \
    APP_INFO(APP_RINGTONECOMPOSER, STR_MENU3103_RINGTONE_COMPOSER,          MENU3103_RINGTONE_COMPOSER  )
#else
#define APP_INFO_COMPOSER
#endif

#ifdef __MMI_BG_SOUND_EFFECT__
#ifdef __UCM_SUPPORT__
#define APP_INFO_BGSOUND \
    APP_INFO(APP_BGSOUND,          0,                                   MENU_ID_UCM_CALL_SETTING    )
#else
#define APP_INFO_BGSOUND \
    APP_INFO(APP_BGSOUND,          0,                                   MENU_SETTING_SOUND_EFFECT   )
#endif
#else
#define APP_INFO_BGSOUND
#endif

#if defined(__MMI_FWU_VIA_FILE__)
#define APP_INFO_FWU \
    APP_INFO(APP_DEVICE_MANAGEMENT,0,                                   SERVICES_FWU_MENU_ID        )
#else
#define APP_INFO_FWU
#endif


#define FMGR_APP_TABLE_COL \
    APP_INFO(APP_FILEMANAGER,      STR_FMGR_TITLE,                      MAIN_MENU_FILE_MNGR_MENUID  ) \
    APP_INFO(APP_DOWNLOADAGENT,    STR_FMGR_TITLE,                      MAIN_MENU_FILE_MNGR_MENUID  ) \
    APP_INFO(APP_PHONEBOOK,        0,                                   MAIN_MENU_PHONEBOOK_MENUID  ) \
    APP_INFO(APP_SETTINGS,         0,                                   MAIN_MENU_SETTINGS_MENUID   ) \
    APP_INFO(APP_PROFILES,         0,                                   MAIN_MENU_PROFILES_MENUID   ) \
    APP_INFO(APP_MESSAGES,         0,                                   MAIN_MENU_MESSAGES_MENUID   ) \
    APP_INFO(APP_WAP,              0,                                   SERVICES_WAP_MENU_ID        ) \
    APP_INFO(APP_IMAGEVIEWER,      STR_ID_IMGVIEW_NAME,                 MENU_ID_IMGVIEW_APP         ) \
    APP_INFO(APP_CAMERA,           0,                                   MENU_ID_CAMERA_APP          ) \
    APP_INFO_COMPOSER \
    APP_INFO(APP_PHOEDT,           0,                                   MENU_ID_PHOEDT_APP          ) \
    APP_INFO_SOUND_REC \
    APP_INFO_ABREPEATER \
    APP_INFO(APP_AUDIOPLAYER,      0,                                   AUDIO_PLAYER_MAIN_MENUID    ) \
    APP_INFO(APP_VDOPLY,           STR_ID_VDOPLY_APP_NAME,              MENU_ID_VDOPLY_APP          ) \
    APP_INFO(APP_VDOREC,           0,                                   MENU_ID_VDOPLY_APP          ) \
    APP_INFO(APP_VDOEDT,           0,                                   MENU_ID_VDOEDT_APP          ) \
    APP_INFO(APP_SLIDESHOW,        0,                                   MENU_ID_SLIDSHOW_APP        ) \
    APP_INFO_BARCODE_OP01 \
    APP_INFO(APP_EMAIL,            0,                                   MENU_ID_EMAIL_MAIN          ) \
    APP_INFO(APP_TODOLIST,         0,                                   ORGANIZER_TODOLIST_MENU     ) \
    APP_INFO(APP_EXTDEVICE,        0,                                   MAIN_MENU_FILE_MNGR_MENUID  ) \
    APP_INFO(APP_IMPS,             0,                                   MENU_ID_IMPS_MAIN           ) \
    APP_INFO(APP_FTP,              0,                                   MENU_CONN_FTP_SETTING       ) \
    APP_INFO(APP_BIP,              0,                                   MENU_CONN_BIP_SETTING       ) \
    APP_INFO(APP_EBOOK,            EBOOK_TITLE_BOOKSHELF,               MAIN_MENU_EBOOK_MENUID      ) \
    APP_INFO(APP_MYFAVORITE,       0,                                   0                           ) \
    APP_INFO(APP_FMRDO,            0,                                   MENU_ID_FMRDO_MAIN          ) \
    APP_INFO(APP_FMSCHEDULEREC,    0,                                   MENU_ID_FMSR_MAIN           ) \
    APP_INFO(APP_JAVA,             0,                                   0                           ) \
    APP_INFO(APP_GAMES,            0,                                   MENU_ID_MOTION_APP          ) \
    APP_INFO(APP_LANGLN,           0,                                   MENU_ID_LANGLN              ) \
    APP_INFO_BGSOUND \
    APP_INFO(APP_RMGR,             0,                                   MENU_ID_RMGR                ) \
    APP_INFO_SWFLASH \
    APP_INFO_CSB \
    APP_INFO(APP_DCD,              0,                                   0                           ) \
    APP_INFO_FWU \

/****************************************************************************/
/*
 *
 */
#define FN_INFO(callback, wanted_flag)

#define FMGR_NOTIFY_COL \
    FN_INFO_AUDIO_PLAYER \
    FN_INFO_JMA \
    FN_INFO_JAVA \
    FN_INFO_BGSOUND \
    FN_INFO_WAP \
    FN_INFO_EMAIL \
    FN_INFO_SMS_ARCHIVE \
    FN_INFO_LANGLN \
    FN_INFO_MMS_BGSR \
    FN_INFO_SWFLASH \
    FN_INFO_THEME_V2 \
    FN_INFO_THEME \
    FN_INFO_UC \
    FN_INFO_SETTING \
    FN_INFO_EBOOK \
    FN_INFO_MOBILE_TV_PLAYER \
    FN_INFO_DLA \
    FN_INFO_PHNSET \
/* Vogins Start */ \
    FN_INFO_VRE \
/* Vogins End */ \

#ifdef __MMI_AUDIO_PLAYER__
#define FN_INFO_AUDIO_PLAYER \
    FN_INFO(mmi_fmgr_audio_player_notify_hdlr, MMI_FMGR_NOTIFY_ALL)
#else
#define FN_INFO_AUDIO_PLAYER
#endif

#if defined(__J2ME__)
#define FN_INFO_JMA \
    FN_INFO(mmi_fmgr_jma_notify_hdlr, MMI_FMGR_NOTIFY_PRE_COPY | MMI_FMGR_NOTIFY_PRE_MOVE | MMI_FMGR_NOTIFY_PRE_DELETE | MMI_FMGR_NOTIFY_PRE_DEL_ALL)
#else
#define FN_INFO_JMA
#endif

#if defined(__J2ME__)
#define FN_INFO_JAVA \
    FN_INFO(mmi_fmgr_java_notify_hdlr, MMI_FMGR_NOTIFY_DRV_PRE_FORMAT)
#else
#define FN_INFO_JAVA
#endif

#ifdef __MMI_BG_SOUND_EFFECT__
#define FN_INFO_BGSOUND \
    FN_INFO(mmi_fmgr_bgsound_notify_hdlr, MMI_FMGR_NOTIFY_DRV_POST_UNMOUNT)
#else
#define FN_INFO_BGSOUND
#endif

#if defined(__MMI_BROWSER_2__) || defined(OBIGO_Q03C)
#define FN_INFO_WAP \
    FN_INFO(mmi_fmgr_wap_notify_hdlr, MMI_FMGR_NOTIFY_DRV_POST_UNMOUNT)
#else
#define FN_INFO_WAP
#endif



#ifdef __MMI_EBOOK_READER__
#define FN_INFO_EBOOK \
    FN_INFO(mmi_fmgr_ebook_notify_hdlr, MMI_FMGR_NOTIFY_POST_DELETE | MMI_FMGR_NOTIFY_DRV_POST_UNMOUNT)

#else
#define FN_INFO_EBOOK
#endif

#ifdef __MMI_MOBILE_TV_PLAYER__
#define FN_INFO_MOBILE_TV_PLAYER \
    FN_INFO(mmi_mtv_player_fmgr_notify_callback, MMI_FMGR_NOTIFY_DRV_PRE_FORMAT)
#else
#define FN_INFO_MOBILE_TV_PLAYER
#endif


#ifdef __MMI_EMAIL__
#define FN_INFO_EMAIL \
    FN_INFO(mmi_fmgr_email_notify_hdlr, MMI_FMGR_NOTIFY_DRV_POST_FORMAT)
#else
#define FN_INFO_EMAIL
#endif

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
#define FN_INFO_SMS_ARCHIVE \
    FN_INFO(mmi_fmgr_um_archive_notify_hdlr, MMI_FMGR_NOTIFY_DRV_POST_FORMAT)
#else
#define FN_INFO_SMS_ARCHIVE
#endif

#ifdef __MMI_LANGLN__
#define FN_INFO_LANGLN \
    FN_INFO(mmi_fmgr_langln_notify_hdlr, MMI_FMGR_NOTIFY_DRV_POST_UNMOUNT)
#else
#define FN_INFO_LANGLN
#endif

#ifdef __MMI_MMS_BGSR_SUPPORT__
#define FN_INFO_MMS_BGSR \
    FN_INFO(mmi_fmgr_mms_bgsr_notify_hdlr, MMI_FMGR_NOTIFY_DRV_POST_FORMAT)
#else
#define FN_INFO_MMS_BGSR
#endif

#ifdef __MMI_SWFLASH__
#define FN_INFO_SWFLASH \
    FN_INFO(mmi_fmgr_swflash_notify_hdlr, MMI_FMGR_NOTIFY_DRV_POST_UNMOUNT)
#else
#define FN_INFO_SWFLASH
#endif
/* Vogins Start */
#ifdef __VRE__
#define FN_INFO_VRE \
    FN_INFO(mmi_fmgr_vre_notify_hdlr, MMI_FMGR_NOTIFY_DRV_POST_UNMOUNT | MMI_FMGR_NOTIFY_DRV_POST_MOUNT | MMI_FMGR_NOTIFY_DRV_PRE_FORMAT)
#else
#define FN_INFO_VRE
#endif
/* Vogins End */
#ifdef __MMI_THEMES_V2_SUPPORT__
#define FN_INFO_THEME_V2 \
    FN_INFO(mmi_fmgr_theme_v2_notify_hdlr, MMI_FMGR_NOTIFY_DRV_PRE_FORMAT | MMI_FMGR_NOTIFY_DRV_POST_FORMAT | MMI_FMGR_NOTIFY_DRV_POST_UNMOUNT)
#else
#define FN_INFO_THEME_V2
#endif

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
#define FN_INFO_THEME \
    FN_INFO(mmi_fmgr_theme_notify_hdlr, MMI_FMGR_NOTIFY_DRV_POST_FORMAT | MMI_FMGR_NOTIFY_PRE_MOVE | MMI_FMGR_NOTIFY_PRE_COPY | MMI_FMGR_NOTIFY_PRE_DELETE | MMI_FMGR_NOTIFY_POST_MOVE | MMI_FMGR_NOTIFY_POST_DELETE)
#else
#define FN_INFO_THEME
#endif

#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))
#define FN_INFO_UC \
    FN_INFO(mmi_fmgr_uc_notify_hdlr, MMI_FMGR_NOTIFY_DRV_POST_UNMOUNT)
#else
#define FN_INFO_UC
#endif

#ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
#define FN_INFO_SETTING \
    FN_INFO(mmi_fmgr_setting_notify_hdlr, MMI_FMGR_NOTIFY_POST_MOVE | MMI_FMGR_NOTIFY_POST_DELETE | MMI_FMGR_NOTIFY_POST_DEL_ALL | MMI_FMGR_NOTIFY_DRV_POST_FORMAT)
#else
#define FN_INFO_SETTING
#endif

#ifdef __MMI_DOWNLOAD_AGENT__
#define FN_INFO_DLA \
    FN_INFO(mmi_fmgr_dla_notify_hdlr, MMI_FMGR_NOTIFY_DRV_POST_UNMOUNT)
#else
#define FN_INFO_DLA
#endif

#define FN_INFO_PHNSET \
    FN_INFO(mmi_fmgr_phnset_notify_hdlr, MMI_FMGR_NOTIFY_DRV_POST_UNMOUNT)


/****************************************************************************/
/*  menu_id:    forward(use or send) menuitem id
 *  enabler:    mmi_fmgr_enabler_callback, enable logic handler
 */
#define FE_INFO(menu_id, enabler)

#define FMGR_FWD_ENABLER_COL \
    /* Use - Image/Video */ \
    FE_INFO(MENU_ID_FMGR_FWD_WALLPAPER,         mmi_fmgr_forward_2d_media_enabler) \
    FE_INFO_SUB_WALLPAPER \
    FE_INFO(MENU_ID_FMGR_FWD_SCREENSAVER,       mmi_fmgr_forward_2d_media_enabler) \
    FE_INFO_POWER_ON_OFF \
    FE_INFO(MENU_ID_FMGR_FWD_PHB,               mmi_fmgr_forward_phb_enabler) \
    /* Use - Audio */ \
    FE_INFO_BG_SOUND \
    /* Send */ \
    FE_INFO_SMS \
    FE_INFO_EMS \
    FE_INFO_MMS \
    FE_INFO_EMAIL \
    FE_INFO_IRDA \
    FE_INFO_BT \


#ifdef __MMI_SUB_WALLPAPER__		
#define FE_INFO_SUB_WALLPAPER \
    FE_INFO(MENU_ID_FMGR_FWD_SUB_WALLPAPER,     mmi_fmgr_forward_2d_media_enabler)
#else
#define FE_INFO_SUB_WALLPAPER
#endif

#ifdef __MMI_POWER_ON_OFF_DISPLAY__
#define FE_INFO_POWER_ON_OFF \
    FE_INFO(MENU_ID_FMGR_FWD_POWER_ON,          mmi_fmgr_forward_2d_media_enabler) \
    FE_INFO(MENU_ID_FMGR_FWD_POWER_OFF,         mmi_fmgr_forward_2d_media_enabler)
#else
#define FE_INFO_POWER_ON_OFF
#endif

#ifdef __MMI_BG_SOUND_EFFECT__		
#define FE_INFO_BG_SOUND \
    FE_INFO(MENU_ID_FMGR_FWD_BGSOUND,           mmi_fmgr_forward_bgsound_enabler)
#else
#define FE_INFO_BG_SOUND
#endif

#if !defined (__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
#define FE_INFO_SMS \
    FE_INFO(MENU_ID_FMGR_FWD_SMS,               mmi_fmgr_forward_sms_enabler)
#else
#define FE_INFO_SMS
#endif

#if (defined( __MMI_MESSAGES_EMS__) && !defined (__MMI_FMGR_NO_FWD_SMS__))
#define FE_INFO_EMS \
    FE_INFO(MENU_ID_FMGR_FWD_EMS,               mmi_fmgr_forward_ems_enabler)
#else
#define FE_INFO_EMS
#endif

#ifdef __MMI_MMS__
#define FE_INFO_MMS \
    FE_INFO(MENU_ID_FMGR_FWD_MMS,               mmi_fmgr_forward_mms_enabler)
#else
#define FE_INFO_MMS
#endif

#ifdef __MMI_EMAIL__
#define FE_INFO_EMAIL \
    FE_INFO(MENU_ID_FMGR_FWD_EMAIL,             mmi_fmgr_forward_email_enabler)
#else
#define FE_INFO_EMAIL
#endif

#ifdef __MMI_IRDA_SUPPORT__
#define FE_INFO_IRDA \
    FE_INFO(MENU_ID_FMGR_FWD_IRDA,              mmi_fmgr_forward_peripheral_enabler)
#else
#define FE_INFO_IRDA
#endif

/* Bluetooth sending API revise */
#ifdef __MMI_BT_SEND_SUPPORT__
#define FE_INFO_BT \
    FE_INFO(MENU_ID_FMGR_FWD_BT,                mmi_fmgr_forward_peripheral_enabler)
#else
#define FE_INFO_BT
#endif


/****************************************************************************/
/*  menu_id:    Application menuitem id
 *  enabler:    mmi_fmgr_enabler_callback, enable logic handler
 */

#define FMGR_APP_ENABLER_COL \
    FE_INFO(MENU_ID_FMGR_IMG_TYPE_OPTIONS,          mmi_fmgr_option_image_enabler) \
    FE_INFO(MENU_ID_IMGVIEW_FILE_OPTION,            mmi_fmgr_option_imgviewer_enabler) \
    FE_INFO_BOOKMARK \
    FE_INFO_VBOOKMARK \
    FE_INFO_SNDREC \
    FE_INFO_EBOOK \
    FE_INFO_RNGC \
    FE_INFO_SWFLASH \


#if defined(__MMI_BROWSER_2__)
#define FE_INFO_BOOKMARK \
    FE_INFO(MENU_ID_FMGR_BOOKMARK_TYPE_OPTIONS,     mmi_fmgr_option_bookmark_enabler)
#else
#define FE_INFO_BOOKMARK
#endif

#ifdef __MMI_VBOOKMARK__ 
#define FE_INFO_VBOOKMARK \
    FE_INFO(MENU_ID_FMGR_VBOOKMARK_TYPE_OPTIONS,    mmi_fmgr_option_vbookmark_enabler)
#else
#define FE_INFO_VBOOKMARK
#endif

#ifdef __MMI_SOUND_RECORDER__
	#ifdef __MMI_SNDREC_NEW__
	#define FE_INFO_SNDREC \
	    FE_INFO(MENU_ID_SNDREC_REC_OPTION,              mmi_sndrec_option_enabler)
    #else
	#define FE_INFO_SNDREC \
		FE_INFO(MENU_ID_SNDREC_OPTION,                  mmi_sndrec_option_enabler)
	#endif
#else
#define FE_INFO_SNDREC
#endif

#ifdef __MMI_EBOOK_READER__
#define FE_INFO_EBOOK \
    FE_INFO(MENU_ID_EBK_BOOKSHELF_OPTION,           mmi_ebook_option_enabler)
#else
#define FE_INFO_EBOOK
#endif

#ifdef __MMI_RING_COMPOSER__
#define FE_INFO_RNGC \
    FE_INFO(MENU_COMP_RINGTONE_COMP_SELMENU_1,      mmi_rngc_option_enabler)
#else
#define FE_INFO_RNGC
#endif

#ifdef __MMI_SWFLASH__
#define FE_INFO_SWFLASH \
    FE_INFO(MENU_ID_SWFLASH_OPTION,                 mmi_swflash_option_enabler)
#else
#define FE_INFO_SWFLASH
#endif

#ifdef __FMGR_HYPERLINK_SUPPORT__

/****************************************************************************/
/*  app_id:     application id that hyper link is enabled
 *  path:       folder path that hyper link is enabled, Ex: "SWFlash\", drive path is not supported yet.
 *  callback:   query hyperlink detail information, see mmi_fmgr_hyperlink_callback
 */
#define HL_INFO(app_id, path, callback)

#define FMGR_HYPERLINK_COL \
    HL_INFO_MYFAVORITE \


#if defined(__MMI_MY_FAVORITE_SWFLASH_HYPERLINK__)
#define HL_INFO_MYFAVORITE \
    HL_INFO(APP_MYFAVORITE,     FMGR_DEFAULT_FOLDER_SWFLASH,    mmi_swflash_hyperlink_callback)
#else
#define HL_INFO_MYFAVORITE
#endif

#endif

#endif
/****************************************************************************
* Global variable
*****************************************************************************/


/****************************************************************************
* Global Function
*****************************************************************************/


#endif /* _FMGR_TABLE_H_ */


