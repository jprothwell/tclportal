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
 *  AMResDef.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  AM resource header file.
 *
 * Author:
 * -------
 *  Keith Chen
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef AM_RES_DEF_H
#define AM_RES_DEF_H

#include "MMIDataType.h"
/*******************************************************************************/

/* Screen ID */
typedef enum
{
    GRP_ID_AM = (AM_BASE + 1),      /* Group ID */
    SCR_ID_AM_LOADING,              /* Loading screen */
    SCR_ID_AM_MAIN,                 /* Main screen */
    SCR_ID_AM_UPDATE_CDR,           /* CDR update screen */
    SCR_ID_AM_UPDATE_CDR_WAIT,      /* CDR update waiting screen */
    SCR_ID_AM_OPTIONS,              /* Option screen */
    SCR_ID_AM_DOWNLOAD_PROGRESS,    /* Progress screen for downloading app */
    SCR_ID_AM_SETTINGS,
    SCR_ID_AM_SETTINGS_SIM,
    SCR_ID_AM_SETTINGS_CONN,        /* Connection settings screen */
    SCR_ID_AM_DETAILS,
    SCR_ID_AM_DOWNLOAD_FROM_MM_ASK,
    SCR_ID_AM_DOWNLOAD_FROM_MM_CONFIRM,
    /*michael 100415 begin*/
    SCR_ID_AM_STOP_LIST,
    /*Vogins_20100625_start*/
    SCR_ID_AM_PROMPT,
    SCR_ID_AM_SC_PROMPT,
    SCR_ID_AM_DATA_ACCOUNT_OPT,
    SCR_ID_AM_DATA_ACCOUNT_EDIT,
/*Vogins_20100625_end*/
/*vogins_20100712_start*/
SCR_ID_AM_PROCESSES_MANAGER,
    SCR_ID_AM_PROCESSES_MANAGER_OS,
/*vogins_20100712_end*/
    SCR_ID_AM_DOWNLOADING_WAIT,

    SCR_ID_AM_LAST
} SCR_ID_AM_BASE_ENUM;

/* String ID */
typedef enum
{
    STR_ID_AM_INDEX = (AM_BASE + 1),
    /* AM name */
    STR_ID_AM_NAME,                         /* App Manager */
    /* AM start error */
    STR_ID_AM_FILE_OVERFLOW,                /* Number of files in VRE directory exceeds 5000. Can't startup. */
    STR_ID_AM_START_FAILURE,                /* AM start failure */
    STR_ID_AM_VRE_INIT_FAILURE,             /* Failed to initialize VRE */
    /* Loading Screen */
    STR_ID_AM_LOADING,                      /* Initialize */
    /* Main Screen */
    STR_ID_AM_MAIN_NO_DOWNLOAD,             /* Please insert a sim card. */
    /* Option Screen */
    STR_ID_AM_OPTION_LAUNCH,                /* Launch */
    STR_ID_AM_OPTION_CREATE_SHORTCUT,       /* Create shortcut */
    STR_ID_AM_OPTION_DELETE_SHORTCUT,       /* Delete shortcut */
    /* Details Screen */
    STR_ID_AM_DETAILS_INFO,                 /* Information */
    STR_ID_AM_DETAILS_SIZE,                 /* Size */
    STR_ID_AM_DETAILS_PATH,                 /* Storage */
    STR_ID_AM_DETAILS_DEVELOPER,            /* Developer name */
    STR_ID_AM_DETAILS_TEL,                  /* Tel */
    STR_ID_AM_DETAILS_STORAGE_PHONE,        /* Phone */
    STR_ID_AM_DETAILS_STORAGE_ROM,          /* ROM */
    STR_ID_AM_DETAILS_STORAGE_MEMORY_CARD,  /* Memory Card */
    /* Settings Screen */
    STR_ID_AM_SETTINGS_SIM,                 /* Select SIM */
    STR_ID_AM_SETTINGS_CONN,                /* Connection mode */
    /* SIM Settings Screen */
    STR_ID_AM_SIM_SETTINGS_TITLE,           /* Select SIM */
    STR_ID_AM_SIM_SETTINGS_SIM1,            /* SIM1 */
    STR_ID_AM_SIM_SETTINGS_SIM2,            /* SIM2 */
    /* Conn Settings Screen */
    STR_ID_AM_CONN_SETTINGS_TITLE,          /* Connection mode */
    STR_ID_AM_CONN_SETTINGS_GPRS,           /* GPRS conn. */
    STR_ID_AM_CONN_SETTINGS_WIFI,           /* WIFI conn. */
    /* Download Progress Screen */

    /* Popup Msg */
    STR_ID_AM_DOWNLOAD_CONTINUE,		/*continue to download? */	
    STR_ID_AM_DELETE_APP_QUERY,             /* Delete? */
    STR_ID_AM_DELETE_APP_FAILURE,           /* Delete failure */
    STR_ID_AM_SET_FAILURE,                  /* Failed to set */
    STR_ID_AM_CONNCT_FAILURE,               /* Connection failed */
    STR_ID_AM_DOWNLOAD_FAILURE,             /* Failed to download */
    STR_ID_AM_DOWNLOAD_CANCEL,              /* Download has been cancelled */
    STR_ID_AM_DOWNLOAD_DONE,                /* Download is complete, launch app now? */
    STR_ID_AM_SHORTCUT_SET_DONE,            /* Shortcut created in Home Screen. */
    STR_ID_AM_SHORTCUT_SET_DUPLICATE,       /* The same Application can only set one shortcut. */
    STR_ID_AM_SHORTCUT_OLD_VER_SET_FAILURE, /* It is an old version. Shortcut is not created. */
    STR_ID_AM_SHORTCUT_SET_FAILURE,         /* Application is illegal. Shortcut not created. */
    STR_ID_AM_SHORTCUT_SET_MAX,             /* Cannot create any more shortcuts. */
    STR_ID_AM_SHORTCUT_DEL_QUERY,           /* Remove the shortcut from Home Screen? */
    STR_ID_AM_SHORTCUT_DEL_DONE,            /* Shortcut Removed */
    STR_ID_AM_SHORTCUT_HS_DEL,
    STR_ID_AM_UPGRADE_QUERY,                /* Already have new version, whether to launch the application */
    STR_ID_AM_FILE_CORRUPT,                 /* File is corrupt */
    STR_ID_AM_FILE_NOT_EXIST,               /* File does not exist */

    /* VRE CDR update */
    STR_ID_AM_CDR_NEW_CONTENT,  /* New content was found, update now? */
    STR_ID_AM_CDR_NEW_VERSION,  /* New version was found, update now? */
    STR_ID_AM_CDR_UPDATE_SUCC,  /* Update successfully */
    STR_ID_AM_CDR_UPDATE_FAIL,  /* Failed to update */

    /* User balance */
    STR_ID_AM_USER_BALANCE, /* % RMB left, you can use for payment. */

    /* VRE App start failure message */
    STR_ID_AM_FAIL_TO_START,
    STR_ID_AM_TAG_ERR_FAIL_TO_START,
    STR_ID_AM_DATE_ERR_FAIL_TO_START,
    STR_ID_AM_CERT_ERR_FAIL_TO_START,
    STR_ID_AM_INVALID_SIM_FAIL_TO_START,
    STR_ID_AM_CERT_EXPIRED_FAIL_TO_START,

    STR_ID_AM_APP_NAME_DEFAULT, /* Damaged */
    STR_ID_AM_APP_NAME_VRE20,   /* VRE App */
    STR_ID_AM_APP_NAME_AS,      /* AppStore */
   	STR_ID_AM_APP_NAME_BH,
	STR_ID_AM_APP_NAME_MYLIVE,
	STR_ID_AM_APP_NAME_TSF,
	STR_ID_AM_APP_NAME_MT,
	STR_ID_AM_APP_NAME_PW,
    STR_ID_AM_APP_NAME_BA,
    STR_ID_AM_APP_NAME_FMS,
    STR_ID_AM_APP_NAME_QCS,
	STR_ID_AM_APP_NAME_YMD100F,
    STR_ID_AM_APP_NAME_VITTER,
    STR_ID_AM_APP_NAME_MOTALK,
    STR_ID_AM_APP_NAME_RAMBO,
    STR_ID_AM_APP_NAME_MAGNETICJOE2,
    STR_ID_AM_APP_NAME_PENGUINFERVER,
    STR_ID_AM_APP_NAME_ADVOFBUBBLE,
    STR_ID_AM_APP_NAME_RACING,
    STR_ID_AM_APP_NAME_TRANSFORMER,
    STR_ID_AM_APP_NAME_HAPPYBOBBLE,
    STR_ID_AM_APP_NAME_JEEP,
    STR_ID_AM_APP_NAME_KRJJH,
    STR_ID_AM_APP_NAME_SGGYZ,
    STR_ID_AM_APP_NAME_SMCL,
    STR_ID_AM_APP_NAME_WULINOL,
    STR_ID_AM_APP_NAME_BXJG,
    STR_ID_AM_APP_NAME_RETURNKING,
    STR_ID_AM_APP_NAME_WORLDWARCRAFT,
    STR_ID_AM_APP_NAME_RADIANTWOLF,
    STR_ID_AM_APP_NAME_QQBROWSER,
    STR_ID_AM_APP_NAME_QQ,
    STR_ID_AM_APP_NAME_KAIXIN,
    STR_ID_AM_APP_NAME_WLOL,
    STR_ID_AM_APP_NAME_MOBILEKK,
    STR_ID_AM_APP_NAME_STOCKSTAR,
    STR_ID_AM_APP_NAME_QQLANDLORD,
    STR_ID_AM_APP_NAME_MSN,
    STR_ID_AM_APP_NAME_FETION,
    STR_ID_AM_APP_NAME_OPERAMINI,
    STR_ID_AM_APP_NAME_BAIDU,
    STR_ID_AM_APP_NAME_OPERA,
    STR_ID_AM_APP_NAME_100TV,
    STR_ID_AM_APP_NAME_AIPIM,
    STR_ID_AM_APP_NAME_LUUTOO,
    STR_ID_AM_APP_NAME_PUSHMAIL,
    /*michael 100415 begin*/
    STR_ID_AM_SYS_NOT_ENOUGH_MEMORY,
    STR_ID_AM_PROMPT_APPLICATION,
    /*michael 100415 end*/
    STR_ID_AM_EXCEED_MAX_APP_NUM,
	STR_ID_AM_MEDIA_MEMORY_UNAVAIBLE,
/*Vogins_20100625_start*/
	STR_ID_AM_PROMPT_INFOMATION,
	STR_ID_AM_SC_PROMPT_INFOMATION,
    STR_ID_AM_DOWNLOAD_1302_ERR,
    STR_ID_AM_DOWNLOAD_1401_ERR,
    STR_ID_AM_DOWNLOAD_1402_ERR,
    STR_ID_AM_DOWNLOAD_1403_ERR,
    STR_ID_AM_DOWNLOAD_1404_ERR,
    STR_ID_AM_DOWNLOAD_1405_ERR,
    STR_ID_AM_DOWNLOAD_1406_ERR,
    STR_ID_AM_DOWNLOAD_1407_ERR,
/*Vogins_20100625_end*/
    //wei.xia add by 0624 for vre version information
    STR_ID_INFORMATION,
    //add end

STR_ID_AM_OPTION_DATA_ACCOUNT,
    STR_ID_AM_APN_NOT_EXIST,
    STR_ID_AM_DATA_ACCOUNT_INCORRECT,
    STR_ID_AM_DCNT_CAPTION_USE_PROXY ,
    STR_ID_AM_DCNT_CAPTION_IP_ADDRESS ,
    STR_ID_AM_DCNT_CAPTION_PORT ,
    STR_ID_AM_DTCNT_CAPTION_APN,
    STR_ID_AM_DTCNT_INPUT_LACK,
    
/*vogins_20100712_start*/
STR_ID_AM_STOP_FAILURE,
STR_ID_AM_PROCESSES_MANAGER,
/*vogins_20100712_end*/
    STR_ID_AM_LAST
} STR_ID_AM_ENUM;

/* Image ID */
typedef enum
{
    IMG_ID_AM_INDEX = (AM_BASE + 1),
    /* loading screen icon */
    IMG_ID_AM_LOADING,  /* show in the center of loading screen */
    /* titile icon */
    IMG_ID_AM_TITLE,    /* use in applib_mem_ap_register() */
    /* state icon */
    IMG_ID_AM_STATE_UNDOWNLOAD,
    IMG_ID_AM_STATE_BG,
    IMG_ID_AM_STATE_SHORTCUT,
    /* highlight icon */
    IMG_ID_AM_HIGHLIGHT,
    IMG_ID_AM_HIGHLIGHT_SCROLLBAR,
    /* AM Shortcut app icon */
    IMG_ID_AM_APP_DEFAULT,
    IMG_ID_AM_APP_AS,   /* AppStore */
    IMG_ID_AM_APP_QCS,
    IMG_ID_AM_APP_KRJJH,
    IMG_ID_AM_APP_SGGYZ,
    IMG_ID_AM_APP_SMCL,
    IMG_ID_AM_APP_WULINOL,
    IMG_ID_AM_APP_BXJG,
    IMG_ID_AM_APP_RETURNKING,
    IMG_ID_AM_APP_WORLDWARCRAFT,
    IMG_ID_AM_APP_RADIANTWOLF,
    IMG_ID_AM_APP_QQBROWSER,
    IMG_ID_AM_APP_QQ,
    IMG_ID_AM_APP_KAIXIN,
    IMG_ID_AM_APP_WLOL,
    IMG_ID_AM_APP_MOBILEKK,
    IMG_ID_AM_APP_STOCKSTAR,
    IMG_ID_AM_APP_QQLANDLORD,
    IMG_ID_AM_APP_MSN,
    IMG_ID_AM_APP_FETION,
    IMG_ID_AM_APP_OPERAMINI,
    IMG_ID_AM_APP_BAIDU,
    IMG_ID_AM_APP_OPERA,
    IMG_ID_AM_APP_100TV,
    IMG_ID_AM_APP_AIPIM,
    IMG_ID_AM_APP_LUUTOO,
    IMG_ID_AM_APP_PUSHMAIL,
   	IMG_ID_AM_APP_BH,
	IMG_ID_AM_APP_MYLIVE,
	IMG_ID_AM_APP_TSF,
	IMG_ID_AM_APP_MT,
	IMG_ID_AM_APP_PW,
	IMG_ID_AM_APP_BA,
	IMG_ID_AM_APP_FMS,
	IMG_ID_AM_APP_YMD100F,
	IMG_ID_AM_APP_VITTER,
	IMG_ID_AM_APP_MOTALK,
	IMG_ID_AM_APP_RAMBO,
    IMG_ID_AM_APP_MAGNETICJOE2,
    IMG_ID_AM_APP_PENGUINFERVER,
    IMG_ID_AM_APP_ADVOFBUBBLE,
    IMG_ID_AM_APP_RACING,
    IMG_ID_AM_APP_TRANSFORMER,
    IMG_ID_AM_APP_HAPPYBOBBLE,
    IMG_ID_AM_APP_JEEP,

    IMG_ID_AM_LAST
} IMG_ID_AM_ENUM;

#endif /* AM_RES_DEF_H */ 

