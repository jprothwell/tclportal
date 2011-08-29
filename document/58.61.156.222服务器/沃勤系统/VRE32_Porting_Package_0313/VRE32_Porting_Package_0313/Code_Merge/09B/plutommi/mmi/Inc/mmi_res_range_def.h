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
 *  mmi_res_range_def.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is for MMI App Resource Range Define
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef MMI_RES_REANGE_DEF_H
#define MMI_RES_REANGE_DEF_H



/****************************************************************************
*
* Resource Base ID
*
* Note: We define the the starting value of resource enum ID 
*       for each application instead of using one big enum definition.
*       As a result, we can avoid re-compile of the whole plutommi 
*       when add/remove string/image enum ID.
* 
* Note: The maximum value of resource ID is 65535 due to U16 datatype.
*
*****************************************************************************/

/*
 * Use these tow macro to get the resource base and resource end
 */
#define GET_RESOURCE_BASE(id)   RESOURCE_BASE_##id
#define GET_RESOURCE_MAX(id)    RESOURCE_BASE_##id##_END

/*
 * Use this macro two to declare resource id range between RESOURCE_BASE_ENUM_BEGIN()
 * and RESOURCE_BASE_ENUM_END()
 */
#define RESOURCE_BASE_RANGE(ap_id, count)    \
    ap_id,                                   \
    GET_RESOURCE_BASE(ap_id) = ap_id,        \
    GET_RESOURCE_MAX(ap_id) = ap_id + count - 1
    
/*
 * Because wap.lib will use resource, RESOURCE_BASE_APP_WAP need to be front of the table
 * to make sure resource id is fixed 
 */
#define RESOURCE_BASE_ENUM_BEGIN()      \
    typedef enum                                    \
    {/* reserve 0 to be string or img */            \
        RESOURCE_BASE_FIRST_VALUE = 0,              \
        RESOURCE_BASE_RANGE(APP_GLOBALDEFS,  299),  \
        RESOURCE_BASE_RANGE(APP_WAP,   1500),

/*
 * Because RESOURCE_BASE_APP_DEVAPP is defined for vendor developing and it has 
 * another resource table, "Resource" will search the different tables 
 * according to the resource base.
 * 
 * In general, the new resource base should be added before APP_DEVAPP.
 */
#define RESOURCE_BASE_ENUM_END()                    \
        RESOURCE_BASE_RANGE(APP_DEVAPP,    300),    \
        RESOURCE_BASE_RANGE(APP_DEFAULT_END, 1),    \
        RESOURCE_BASE_RANGE(END, 1)                 \
    } RESOURCE_BASE_ENUM;


/* 
 * Declare the range of resource ID of each application.
 *      RESOURCE_BASE_RANGE(<app id>, <resource range>),
 * Or Sevice without the concept of applicatioin
 *      RESOURCE_BASE_RANGE(<sevice id>, <resource range>)
 *
 * For example:
 *      For applications:
 *          RESOURCE_BASE_RANGE(APP_XXX1,   100),
 *          RESOURCE_BASE_RANGE(APP_XXX2,    50),
 *      For Services:
 *          RESOURCE_BASE_RANGE(SRV_XXX1,   200),
 *          RESOURCE_BASE_RANGE(SRV_XXX2,   100),
 */

RESOURCE_BASE_ENUM_BEGIN()
    /**************************************************************************************
     * Declare resource ID range below 
     **************************************************************************************/

    /* Part I : resource range for Service, SRV_XXX */

    RESOURCE_BASE_RANGE(FRAMEWORK_ASM,                  100),
    RESOURCE_BASE_RANGE(SRV_STATUS_ICONS,               300),
    RESOURCE_BASE_RANGE(SRV_INFO_NUM,                   100),
    RESOURCE_BASE_RANGE(SRV_CONNECTS,                   100),
    /* Common screen */
    RESOURCE_BASE_RANGE(SRV_COMMON_SCREENS,             300),
    RESOURCE_BASE_RANGE(SRV_SCREENSAVER,                100),
    RESOURCE_BASE_RANGE(SRV_WALLPAPER,                  100),
    RESOURCE_BASE_RANGE(SRV_SPOF,                       100),
    RESOURCE_BASE_RANGE(SRV_NITZ,                       20),
    RESOURCE_BASE_RANGE(SRV_LANG_SETTINGS,              10),
    RESOURCE_BASE_RANGE(SRV_HELP,                       100),
    RESOURCE_BASE_RANGE(SRV_PHNSET_ONOFF,               100),
    RESOURCE_BASE_RANGE(SRV_FLIGHT_MODE,                100),
    RESOURCE_BASE_RANGE(SRV_MMI_THEME,                	100),
    RESOURCE_BASE_RANGE(SRV_CTK,                        200),
    RESOURCE_BASE_RANGE(SRV_COMPOSE_RINGTONE,           100),
    RESOURCE_BASE_RANGE(SRV_NV_RAM_FILE_EXT_MELODY,     20),
    RESOURCE_BASE_RANGE(SRV_MMIAPI,                     100),
    RESOURCE_BASE_RANGE(SRV_VOBJECT,                    50),
    RESOURCE_BASE_RANGE(SRV_VCARD,                      50),
    RESOURCE_BASE_RANGE(SRV_VCALENDAR,                  50),
    RESOURCE_BASE_RANGE(SRV_VBOOKMARK,                  50),
    /* Voice Command - SD */
    RESOURCE_BASE_RANGE(SRV_VRSD,                       100),
    /* Voice Command - SI */
    RESOURCE_BASE_RANGE(SRV_VRSI,                       200),
    RESOURCE_BASE_RANGE(SRV_POC,                        200),
    RESOURCE_BASE_RANGE(SRV_SYNCML,                     300),
    RESOURCE_BASE_RANGE(SRV_PICT_BRIDGE,                100),
    RESOURCE_BASE_RANGE(SRV_VOIP,                       500),
    RESOURCE_BASE_RANGE(SRV_MONWAP,                     100),
    RESOURCE_BASE_RANGE(SRV_SOFTWARE_TRACER,            100),
    /*GPS*/
    RESOURCE_BASE_RANGE(SRV_GPS,                        100),
    RESOURCE_BASE_RANGE(SRV_MDI,                        1300),

    /* Part II: resource range for applications, APP_XXX */
    RESOURCE_BASE_RANGE(APP_MAINMENU,                   600),
    RESOURCE_BASE_RANGE(APP_PHONEBOOK,                  1000),
    RESOURCE_BASE_RANGE(APP_SHORTCUTS,                  50),
    RESOURCE_BASE_RANGE(APP_FUNANDGAMES,                200),
    /* Service */
    RESOURCE_BASE_RANGE(APP_SERVICES,                   100),
    RESOURCE_BASE_RANGE(APP_DATAACCOUNT,                300),
    /* Ipsec Settings */
    RESOURCE_BASE_RANGE(APP_IPSEC,                      50),
    /* Organizer */
    RESOURCE_BASE_RANGE(APP_ORGANIZER,                  100),
    RESOURCE_BASE_RANGE(APP_TODOLIST,                   200),
    RESOURCE_BASE_RANGE(APP_ALARM,                      50),
    RESOURCE_BASE_RANGE(APP_CALCULATOR,                 50),
    RESOURCE_BASE_RANGE(APP_UNITCONVETER,               100),
    RESOURCE_BASE_RANGE(APP_CURRENCYCONVERTER,          50),
    RESOURCE_BASE_RANGE(APP_WORLDCLOCK,                 200),
    RESOURCE_BASE_RANGE(APP_HEALTHCALORIE,              100),
    RESOURCE_BASE_RANGE(APP_HEALTHMENSTRUAL,            50),
    RESOURCE_BASE_RANGE(APP_HEALTHBMI,                  50), 
    RESOURCE_BASE_RANGE(APP_ECOMPASS,                   800),
    /* Message */
    RESOURCE_BASE_RANGE(APP_MESSAGES,                   1000),
    RESOURCE_BASE_RANGE(APP_CHAT,                       10),
    /* Unified Message */
    RESOURCE_BASE_RANGE(APP_UNIFIEDMESSAGE,             150),
    /* Unified Composer */
    RESOURCE_BASE_RANGE(APP_UNIFIEDCOMPOSER,            300),
    /* Setting */
    RESOURCE_BASE_RANGE(APP_SETTINGS,                   500),
    RESOURCE_BASE_RANGE(APP_SECURITY_SETUP,             300),
    /* Call Management */
    RESOURCE_BASE_RANGE(APP_CALLMANAGEMENT,             50),
    RESOURCE_BASE_RANGE(APP_CTM,                        20),
    RESOURCE_BASE_RANGE(SRV_CTM,                        10),
    RESOURCE_BASE_RANGE(SRV_GCALL,                      200),
    /* Idle App */
    RESOURCE_BASE_RANGE(APP_IDLEAPP,                    750),
    RESOURCE_BASE_RANGE(APP_UIFRAMEWORK,                700),
    RESOURCE_BASE_RANGE(APP_IDLE_FANCY_HANDSET_LOCK,     50),
    /* Demo App */
    RESOURCE_BASE_RANGE(APP_DEMOAPP,                    700),
    /* Phone Setup */
    RESOURCE_BASE_RANGE(APP_PHONESETUP,                 400),
    /* Misc */
    RESOURCE_BASE_RANGE(APP_BOOTUP,                     1000),
    RESOURCE_BASE_RANGE(APP_SIMTOOLKIT,                 100),
    RESOURCE_BASE_RANGE(APP_EMAIL,                      300),
    RESOURCE_BASE_RANGE(APP_IMPS,                       800),
    /* Used for FDL/BDL/SDL/Call fwd/call waiting*/
    RESOURCE_BASE_RANGE(APP_CALLSETUP,                  300),
    RESOURCE_BASE_RANGE(APP_CALLHISTORY,                150),
    RESOURCE_BASE_RANGE(APP_PROFILES,                   230),
    RESOURCE_BASE_RANGE(APP_CHARGER,                    30),
    RESOURCE_BASE_RANGE(APP_CALLBARRING,                100),
    RESOURCE_BASE_RANGE(APP_NETWORKSETUP,               100),
    RESOURCE_BASE_RANGE(APP_DOWNLOAD,                   100),
    RESOURCE_BASE_RANGE(APP_VOICEMEMO,                  200),
    RESOURCE_BASE_RANGE(APP_INPUTMETHOD,                200),
    RESOURCE_BASE_RANGE(APP_ENGINEERMODE,               880),
    RESOURCE_BASE_RANGE(APP_ENGINEERMODE_APP,           650),
    /* Calendar */
    RESOURCE_BASE_RANGE(APP_CALENDAR,                   300),
    RESOURCE_BASE_RANGE(APP_FACTORYMODE,                150),
    RESOURCE_BASE_RANGE(APP_RINGTONECOMPOSER,           200),
    RESOURCE_BASE_RANGE(APP_AUDIOPLAYER,                500),
    RESOURCE_BASE_RANGE(APP_SOUNDRECORDER,              300),
    RESOURCE_BASE_RANGE(APP_FILEMANAGER,                600),
    RESOURCE_BASE_RANGE(APP_JAVA,                       500),
    RESOURCE_BASE_RANGE(APP_EXTDEVICE,                  700),
    RESOURCE_BASE_RANGE(APP_MULTIMEDIA,                 100),
    RESOURCE_BASE_RANGE(APP_EXTRA,                      100),
    RESOURCE_BASE_RANGE(APP_EBOOK,                      200),
    RESOURCE_BASE_RANGE(APP_GAMES,                      2500),
    RESOURCE_BASE_RANGE(APP_STOPWATCH,                  100),
    RESOURCE_BASE_RANGE(APP_DICTIONARY,                 150),
    RESOURCE_BASE_RANGE(APP_PICTURE_EDITOR,             200),
    RESOURCE_BASE_RANGE(APP_CAMERA,                     600),
    RESOURCE_BASE_RANGE(APP_IMAGEVIEWER,                300),
    RESOURCE_BASE_RANGE(APP_VDOPLY,                     500),
    RESOURCE_BASE_RANGE(APP_VDOREC,                     400),
    RESOURCE_BASE_RANGE(APP_STREAMING,                  100),
    RESOURCE_BASE_RANGE(APP_FMRDO,                      300),
    RESOURCE_BASE_RANGE(APP_PHOEDT,                     300),
    RESOURCE_BASE_RANGE(APP_MESSAGE_CLUB,               10),
    RESOURCE_BASE_RANGE(APP_ABREPEATER,                 200),
    /*Schedule FM Radio Record*/
    RESOURCE_BASE_RANGE(APP_FMSCHEDULEREC,              200),
    /*Background Sound Effect*/
    RESOURCE_BASE_RANGE(APP_BGSOUND,                    200),
    RESOURCE_BASE_RANGE(APP_DOWNLOADAGENT,              100),
    RESOURCE_BASE_RANGE(APP_UMMS_MMS,                   500),
    RESOURCE_BASE_RANGE(APP_BROWSER,                    300),
    RESOURCE_BASE_RANGE(APP_JATAAYU_PROFILE,            100),
    RESOURCE_BASE_RANGE(APP_BARCODEREADER,              600),
    RESOURCE_BASE_RANGE(APP_SWFLASH,                    600),
    /* Language Learning */
    RESOURCE_BASE_RANGE(APP_LANGLN,                     1000),
    RESOURCE_BASE_RANGE(APP_VDOEDT,                     500),
    RESOURCE_BASE_RANGE(APP_CCA,                        100),
    RESOURCE_BASE_RANGE(APP_AVATAR,                     600),
    RESOURCE_BASE_RANGE(APP_CSB,                        100),
    RESOURCE_BASE_RANGE(APP_RMGR,                       200),
    RESOURCE_BASE_RANGE(APP_DMUI,                       200),
    /* My Favorite */
    RESOURCE_BASE_RANGE(APP_MYFAVORITE,                 100),
    /*Mobile Service*/
    RESOURCE_BASE_RANGE(APP_MOBILE_SERVICE,             100),
    /*Customer Service*/
    RESOURCE_BASE_RANGE(APP_CUSTOMER_SERVICE,           100),
    RESOURCE_BASE_RANGE(APP_UCM,                        200),
    RESOURCE_BASE_RANGE(SRV_UCM,                        30),
    RESOURCE_BASE_RANGE(APP_INDICAL,                    150),
    RESOURCE_BASE_RANGE(APP_MOBILE_TV_PLAYER,           500),
    RESOURCE_BASE_RANGE(APP_SLIDESHOW,                  100),
    RESOURCE_BASE_RANGE(APP_VT,                         1),
    RESOURCE_BASE_RANGE(APP_MMS_BGSR,                   100),
    RESOURCE_BASE_RANGE(APP_MMS_V01AGENT,               20),
    RESOURCE_BASE_RANGE(APP_MMI_CERTMAN,                120),
    /*DCD App*/
    RESOURCE_BASE_RANGE(APP_DCD,                        100),
    /*GIS*/
    RESOURCE_BASE_RANGE(APP_GIS,                        100),
    RESOURCE_BASE_RANGE(APP_CONNECTMANAGEMENT,          100),
    RESOURCE_BASE_RANGE(APP_CAMCO,                      1000),
    RESOURCE_BASE_RANGE(APP_MERCURY,                    1000),
    RESOURCE_BASE_RANGE(APP_MMI_WAP_PROF,               100),
    RESOURCE_BASE_RANGE(APP_AVK,                        300),
/* Vogins Start */
    RESOURCE_BASE_RANGE(APP_VRE,                        100),
    RESOURCE_BASE_RANGE(APP_AM,                        200),
/* Vogins End */
    RESOURCE_BASE_RANGE(APP_BCR,                        300),
    RESOURCE_BASE_RANGE(APP_AVBT,                       10),
    RESOURCE_BASE_RANGE(APP_MEDPLY,                     500),
    RESOURCE_BASE_RANGE(APP_AUTOAM,                     100),
    RESOURCE_BASE_RANGE(APP_MEDPLY_SINGLE,              1),
    RESOURCE_BASE_RANGE(APP_FTP,                        10),
    RESOURCE_BASE_RANGE(APP_SPA,                        1),
    RESOURCE_BASE_RANGE(APP_TTS_TEST,                   1),
    RESOURCE_BASE_RANGE(APP_SINGLE_AUDIO,               1),
    RESOURCE_BASE_RANGE(APP_BIP,                        10),
    RESOURCE_BASE_RANGE(APP_MMS_POSTCARD,               100),
    RESOURCE_BASE_RANGE(APP_UDX,                        100),
    RESOURCE_BASE_RANGE(APP_UCWEB,                      10),
    RESOURCE_BASE_RANGE(APP_QQIM,                       300),
    RESOURCE_BASE_RANGE(APP_HIJRI_CALENDAR,             150),
    RESOURCE_BASE_RANGE(APP_A8BOX, 		        200),
    RESOURCE_BASE_RANGE(APP_GGLIVE, 		        	300),
    RESOURCE_BASE_RANGE(APP_PROVBOXUI,                  100),
    RESOURCE_BASE_RANGE(APP_NOTE, 		                100),
    RESOURCE_BASE_RANGE(SRV_VIRTUAL_KEYBOARD,           2400),
    RESOURCE_BASE_RANGE(SRV_VIRTUAL_KEYBOARD_MISC,      300),
    RESOURCE_BASE_RANGE(APP_SEARCH_WEB,                 100),
    RESOURCE_BASE_RANGE(SRV_VENUS_COMPONENTS,         100),
    RESOURCE_BASE_RANGE(APP_ZAKAT_CALCULATOR,           100),
    RESOURCE_BASE_RANGE(APP_116114,                 10),
    RESOURCE_BASE_RANGE(APP_ONLINE_SALES,       10),
    RESOURCE_BASE_RANGE(APP_MOBILE_TV,            10),
    RESOURCE_BASE_RANGE(APP_PUSHMAIL,            10),
    RESOURCE_BASE_RANGE(APP_MOBILE_STOCK,              10),
    RESOURCE_BASE_RANGE(APP_QQ_MOVIE,                   100),
    RESOURCE_BASE_RANGE(APP_AZAAN_ALARM,                100),
    RESOURCE_BASE_RANGE(CUI_TONE_SELECTOR,         20),
    RESOURCE_BASE_RANGE(APP_MMI_WAP_PUSH,             150),
    RESOURCE_BASE_RANGE(SRV_VENUS_FW,         300),
    RESOURCE_BASE_RANGE(SRV_MMI_CHARSET,             50),
    RESOURCE_BASE_RANGE(APP_PBAP,             10),
    RESOURCE_BASE_RANGE(APP_OPP,             10),
    RESOURCE_BASE_RANGE(SRV_PLST,                       50),
    RESOURCE_BASE_RANGE(APP_MEDIAWALL,                  100),
    RESOURCE_BASE_RANGE(APP_VENUS_CUBE,                 100),
    RESOURCE_BASE_RANGE(APP_FONT_MANAGER,               50),

    /**************************************************************************************
     * Declare resource ID range above 
     **************************************************************************************/
RESOURCE_BASE_ENUM_END()

/*
 * Fill resouce table and define resouce base and max macro for each application
 * or service.
 *
 */

/*
 * Structure for resouce table element
 */
typedef struct 
{
	char *appname;        /* Application or service name. eg. APP_XXX or SRV_XXX */
	unsigned short min;   /* Resouce ID start position of an application or service */
	unsigned short max;   /* Resouce ID end position of an application or service */
} mmi_resource_base_struct;

#if defined(_POPULATE_RES_C) && !defined(PRODUCTION_RELEASE)

/* Table of resource base ID used for reference in debugging */
#define RESOURCE_BASE_TABLE_BEGIN()         \
    const	mmi_resource_base_struct g_mmi_resource_base_table[] = {

/* Use the Macro to insert an element to resouce table */
#define RESOURCE_BASE_TABLE_ITEM(ENUM_NAME) \
        {#ENUM_NAME, (U16) GET_RESOURCE_BASE(ENUM_NAME), (U16) GET_RESOURCE_MAX(ENUM_NAME)},

#define RESOURCE_BASE_TABLE_END()                                          \
        {"END", (U16) GET_RESOURCE_BASE(END), (U16) GET_RESOURCE_MAX(END)} \
    };

#else /* _POPULATE_RES_C */

#define RESOURCE_BASE_TABLE_BEGIN()

#define RESOURCE_BASE_TABLE_ITEM(ENUM_NAME)

#define RESOURCE_BASE_TABLE_END()

#endif /* _POPULATE_RES_C */

/* 
 * Fill resouce table and define XXX_BASE and XXX_BASE_XXX for each application
 * or service.
 * 
 * For application:
 *   #define XXX_BASE     ((U16) GET_RESOURCE_BASE(APP_XXX))
 *   #define XXX_BASE_MAX ((U16) GET_RESOURCE_MAX(APP_XXX))
 *   RESOURCE_BASE_TABLE_ITEM(APP_XXX)
 * For service:
 *   #define XXX_BASE     ((U16) GET_RESOURCE_BASE(SRV_XXX))
 *   #define XXX_BASE     ((U16) GET_RESOURCE_MAX(SRV_XXX))
 *   RESOURCE_BASE_TABLE_ITEM(SRV_XXX)
 */


/* Beginning of resource table */
RESOURCE_BASE_TABLE_BEGIN()

/****************************************************************************
* Global
*****************************************************************************/
#define GLOBAL_BASE                          (1)
#define GLOBAL_BASE_MAX                      ((U16) GET_RESOURCE_MAX(APP_GLOBALDEFS))
RESOURCE_BASE_TABLE_ITEM(APP_GLOBALDEFS)

/****************************************************************************
* Framework ASM
*****************************************************************************/
#define FRAMEWORK_ASM_BASE                   ((U16) GET_RESOURCE_BASE(FRAMEWORK_ASM))
#define FRAMEWORK_ASM_BASE_MAX               ((U16) GET_RESOURCE_MAX(FRAMEWORK_ASM))
RESOURCE_BASE_TABLE_ITEM(FRAMEWORK_ASM)

/****************************************************************************
* Main Menu
*****************************************************************************/
#define MAIN_MENU_BASE                       ((U16) GET_RESOURCE_BASE(APP_MAINMENU))
#define MAIN_MENU_BASE_MAX                   ((U16) GET_RESOURCE_MAX(APP_MAINMENU))
RESOURCE_BASE_TABLE_ITEM(APP_MAINMENU)

/****************************************************************************
* PhoneBook
*****************************************************************************/
#define PHONE_BOOK_BASE                      ((U16) GET_RESOURCE_BASE(APP_PHONEBOOK))
#define PHONE_BOOK_BASE_MAX                  ((U16) GET_RESOURCE_MAX(APP_PHONEBOOK))
RESOURCE_BASE_TABLE_ITEM(APP_PHONEBOOK)

/****************************************************************************
* Shortcut
*****************************************************************************/
#define SHORTCUTS_BASE                       ((U16) GET_RESOURCE_BASE(APP_SHORTCUTS))
#define SHORTCUTS_BASE_MAX                   ((U16) GET_RESOURCE_MAX(APP_SHORTCUTS))
RESOURCE_BASE_TABLE_ITEM(APP_SHORTCUTS)

/****************************************************************************
* Fun&Game
*****************************************************************************/
#define FUN_GAMES_BASE                       ((U16) GET_RESOURCE_BASE(APP_FUNANDGAMES))
#define FUN_GAMES_BASE_MAX                   ((U16) GET_RESOURCE_MAX(APP_FUNANDGAMES))
RESOURCE_BASE_TABLE_ITEM(APP_FUNANDGAMES)

/****************************************************************************
* Status icons
*****************************************************************************/
#define STATUS_ICONS_BASE                    ((U16) GET_RESOURCE_BASE(SRV_STATUS_ICONS))
#define STATUS_ICONS_BASE_MAX                ((U16) GET_RESOURCE_MAX(SRV_STATUS_ICONS))
RESOURCE_BASE_TABLE_ITEM(SRV_STATUS_ICONS)

/****************************************************************************
* Service
*****************************************************************************/
#define SERVICES_BASE                        ((U16) GET_RESOURCE_BASE(APP_SERVICES))
#define SERVICES_BASE_MAX                    ((U16) GET_RESOURCE_MAX(APP_SERVICES))
RESOURCE_BASE_TABLE_ITEM(APP_SERVICES)

#define INFO_NUM_BASE                        ((U16) GET_RESOURCE_BASE(SRV_INFO_NUM))
#define INFO_NUM_BASE_MAX                    ((U16) GET_RESOURCE_MAX(SRV_INFO_NUM))
RESOURCE_BASE_TABLE_ITEM(SRV_INFO_NUM)

#define DATA_ACCOUNT_BASE                    ((U16) GET_RESOURCE_BASE(APP_DATAACCOUNT))
#define DATA_ACCOUNT_BASE_MAX                ((U16) GET_RESOURCE_MAX(APP_DATAACCOUNT))
RESOURCE_BASE_TABLE_ITEM(APP_DATAACCOUNT)

#define IPSEC_BASE                           ((U16) GET_RESOURCE_BASE(APP_IPSEC))
#define IPSEC_BASE_MAX                       ((U16) GET_RESOURCE_MAX(APP_IPSEC))
RESOURCE_BASE_TABLE_ITEM(APP_IPSEC)

/****************************************************************************
* Organizer
*****************************************************************************/

#define ORGANIZER_BASE                       ((U16) GET_RESOURCE_BASE(APP_ORGANIZER))
#define ORGANIZER_BASE_MAX                   ((U16) GET_RESOURCE_MAX(APP_ORGANIZER))
RESOURCE_BASE_TABLE_ITEM(APP_ORGANIZER)

#define EBOOK_BASE                           ((U16) GET_RESOURCE_BASE(APP_EBOOK))
#define EBOOK_BASE_MAX                       ((U16) GET_RESOURCE_MAX(APP_EBOOK))
RESOURCE_BASE_TABLE_ITEM(APP_EBOOK)

#define TO_DO_LIST_BASE                      ((U16) GET_RESOURCE_BASE(APP_TODOLIST))
#define TO_DO_LIST_BASE_MAX                  ((U16) GET_RESOURCE_MAX(APP_TODOLIST))
RESOURCE_BASE_TABLE_ITEM(APP_TODOLIST)

#define ALARM_BASE                           ((U16) GET_RESOURCE_BASE(APP_ALARM))
#define ALARM_BASE_MAX                       ((U16) GET_RESOURCE_MAX(APP_ALARM))
RESOURCE_BASE_TABLE_ITEM(APP_ALARM)

#define CALCULATOR_BASE                      ((U16) GET_RESOURCE_BASE(APP_CALCULATOR))
#define CALCULATOR_BASE_MAX                  ((U16) GET_RESOURCE_MAX(APP_CALCULATOR))
RESOURCE_BASE_TABLE_ITEM(APP_CALCULATOR)

#define UNIT_CONVERTER_BASE                  ((U16) GET_RESOURCE_BASE(APP_UNITCONVETER))
#define UNIT_CONVERTER                       UNIT_CONVERTER_BASE /* Be backward compatible */
#define UNIT_CONVERTER_BASE_MAX              ((U16) GET_RESOURCE_MAX(APP_UNITCONVETER))
RESOURCE_BASE_TABLE_ITEM(APP_UNITCONVETER)

#define CURRENCY_CONVERTER_BASE              ((U16) GET_RESOURCE_BASE(APP_CURRENCYCONVERTER))
#define CURRENCY_CONVERTER                   CURRENCY_CONVERTER_BASE /* Be backward compatible */
#define CURRENCY_CONVERTER_BASE_MAX          ((U16) GET_RESOURCE_MAX(APP_CURRENCYCONVERTER))
RESOURCE_BASE_TABLE_ITEM(APP_CURRENCYCONVERTER)

#define WORLD_CLOCK_BASE                     ((U16) GET_RESOURCE_BASE(APP_WORLDCLOCK))
#define WORLD_CLOCK                          WORLD_CLOCK_BASE /* Be backward compatible */
#define WORLD_CLOCK_BASE_MAX                 ((U16) GET_RESOURCE_MAX(APP_WORLDCLOCK))
RESOURCE_BASE_TABLE_ITEM(APP_WORLDCLOCK)

#define HEALTH_CALORIE_BASE                  ((U16) GET_RESOURCE_BASE(APP_HEALTHCALORIE))
#define HEALTH_CALORIE                       HEALTH_CALORIE_BASE /* Be backward compatible */
#define HEALTH_CALORIE_BASE_MAX              ((U16) GET_RESOURCE_MAX(APP_HEALTHCALORIE))
RESOURCE_BASE_TABLE_ITEM(APP_HEALTHCALORIE)

#define HEALTH_MENSTRUAL_BASE                ((U16) GET_RESOURCE_BASE(APP_HEALTHMENSTRUAL))
#define HEALTH_MENSTRUAL                     HEALTH_MENSTRUAL_BASE /* Be backward compatible */
#define HEALTH_MENSTRUAL_BASE_MAX            ((U16) GET_RESOURCE_MAX(APP_HEALTHMENSTRUAL))
RESOURCE_BASE_TABLE_ITEM(APP_HEALTHMENSTRUAL)

#define HEALTH_BMI_BASE                      ((U16) GET_RESOURCE_BASE(APP_HEALTHBMI))
#define HEALTH_BMI                           HEALTH_BMI_BASE /* Be backward compatible */
#define HEALTH_BMI_BASE_MAX                  ((U16) GET_RESOURCE_MAX(APP_HEALTHBMI))
RESOURCE_BASE_TABLE_ITEM(APP_HEALTHBMI)
#define ECOMPASS_BASE                      ((U16) GET_RESOURCE_BASE(APP_ECOMPASS))
#define ECOMPASS                           ECOMPASS_BASE        /* Be backward compatible */
#define ECOMPASS_BASE_MAX                  ((U16) GET_RESOURCE_MAX(APP_ECOMPASS))
    RESOURCE_BASE_TABLE_ITEM(APP_ECOMPASS)
#define RMGR_BASE                            ((U16) GET_RESOURCE_BASE(APP_RMGR))
#define RMGR                                 RMGR_BASE
#define RMGR_BASE_MAX                        ((U16) GET_RESOURCE_MAX(APP_RMGR))
RESOURCE_BASE_TABLE_ITEM(APP_RMGR)

/****************************************************************************
* Message
*****************************************************************************/

#define MESSAGES_BASE                        ((U16) GET_RESOURCE_BASE(APP_MESSAGES))
#define MESSAGES_BASE_MAX                    ((U16) GET_RESOURCE_MAX(APP_MESSAGES))
RESOURCE_BASE_TABLE_ITEM(APP_MESSAGES)

#define CHAT_BASE                            ((U16) GET_RESOURCE_BASE(APP_CHAT))
#define CHAT_BASE_MAX                        ((U16) GET_RESOURCE_MAX(APP_CHAT))
RESOURCE_BASE_TABLE_ITEM(APP_CHAT)

/****************************************************************************
* Unified Message
*****************************************************************************/

#define UNIFIED_MESSAGE_BASE                 ((U16) GET_RESOURCE_BASE(APP_UNIFIEDMESSAGE))
#define UNIFIED_MESSAGE_BASE_MAX             ((U16) GET_RESOURCE_MAX(APP_UNIFIEDMESSAGE))
RESOURCE_BASE_TABLE_ITEM(APP_UNIFIEDMESSAGE)

/****************************************************************************
* Unified Composer
*****************************************************************************/

#define UNIFIED_COMPOSER_BASE                ((U16) GET_RESOURCE_BASE(APP_UNIFIEDCOMPOSER))
#define UNIFIED_COMPOSER_BASE_MAX            ((U16) GET_RESOURCE_MAX(APP_UNIFIEDCOMPOSER))
RESOURCE_BASE_TABLE_ITEM(APP_UNIFIEDCOMPOSER)


/****************************************************************************
* Connection
*****************************************************************************/
#define CONNECTS_BASE                        ((U16) GET_RESOURCE_BASE(SRV_CONNECTS))
#define CONNECTS_BASE_MAX                    ((U16) GET_RESOURCE_MAX(SRV_CONNECTS))
RESOURCE_BASE_TABLE_ITEM(SRV_CONNECTS)

/****************************************************************************
* Setting
*****************************************************************************/

#define SETTINGS_BASE                        ((U16) GET_RESOURCE_BASE(APP_SETTINGS))
#define SETTINGS_BASE_MAX                    ((U16) GET_RESOURCE_MAX(APP_SETTINGS))
RESOURCE_BASE_TABLE_ITEM(APP_SETTINGS)

#define SECURITY_SETUP_BASE                  ((U16) GET_RESOURCE_BASE(APP_SECURITY_SETUP))
#define SECURITY_SETUP_BASE_MAX              ((U16) GET_RESOURCE_MAX(APP_SECURITY_SETUP))
RESOURCE_BASE_TABLE_ITEM(APP_SECURITY_SETUP)

#define GPS_BASE                             ((U16) GET_RESOURCE_BASE(SRV_GPS))
#define GPS_BASE_MAX                         ((U16) GET_RESOURCE_MAX(SRV_GPS))
RESOURCE_BASE_TABLE_ITEM(SRV_GPS)

/****************************************************************************
* Call Management
*****************************************************************************/

#define CALL_MANAGEMENT_BASE                 ((U16) GET_RESOURCE_BASE(APP_CALLMANAGEMENT))
#define CALL_MANAGEMENT_BASE_MAX             ((U16) GET_RESOURCE_MAX(APP_CALLMANAGEMENT))
RESOURCE_BASE_TABLE_ITEM(APP_CALLMANAGEMENT)

#define CTM_BASE                             ((U16) GET_RESOURCE_BASE(APP_CTM))
#define CTM_BASE_MAX                         ((U16) GET_RESOURCE_MAX(APP_CTM))
RESOURCE_BASE_TABLE_ITEM(APP_CTM)


#define SRV_CTM_BASE                         ((U16) GET_RESOURCE_BASE(SRV_CTM))
#define SRV_CTM_BASE_MAX                     ((U16) GET_RESOURCE_MAX(SRV_CTM))
RESOURCE_BASE_TABLE_ITEM(SRV_CTM)


#define GCALL_BASE                 ((U16) GET_RESOURCE_BASE(SRV_GCALL))
#define GCALL_BASE_MAX             ((U16) GET_RESOURCE_MAX(SRV_GCALL))
RESOURCE_BASE_TABLE_ITEM(SRV_GCALL)


/****************************************************************************
* Idle App
*****************************************************************************/

#define IDLE_APP_BASE                        ((U16) GET_RESOURCE_BASE(APP_IDLEAPP))
#define IDLE_APP_BASE_MAX                    ((U16) GET_RESOURCE_MAX(APP_IDLEAPP))
RESOURCE_BASE_TABLE_ITEM(APP_IDLEAPP)

/****************************************************************************
* Idle Fancy Handset Lock
*****************************************************************************/
#define IDLE_FANCY_HANDSET_LOCK_BASE                      ((U16) GET_RESOURCE_BASE(APP_IDLE_FANCY_HANDSET_LOCK))
#define IDLE_FANCY_HANDSET_LOCK_BASE_MAX                  ((U16) GET_RESOURCE_MAX(APP_IDLE_FANCY_HANDSET_LOCK))
RESOURCE_BASE_TABLE_ITEM(APP_IDLE_FANCY_HANDSET_LOCK)

/****************************************************************************
* Category Screens
*****************************************************************************/

#define CATEGORY_SCREENS_BASE                ((U16) GET_RESOURCE_BASE(APP_UIFRAMEWORK))
#define CATEGORY_SCREENS_BASE_MAX            ((U16) GET_RESOURCE_MAX(APP_UIFRAMEWORK))
RESOURCE_BASE_TABLE_ITEM(APP_UIFRAMEWORK)

/****************************************************************************
* Demo App
*****************************************************************************/

#define DEMO_APP_BASE                        ((U16) GET_RESOURCE_BASE(APP_DEMOAPP))
#define DEMO_APP_BASE_MAX                    ((U16) GET_RESOURCE_MAX(APP_DEMOAPP))
RESOURCE_BASE_TABLE_ITEM(APP_DEMOAPP)

/****************************************************************************
* Common Screen 
*****************************************************************************/

#define COMMON_SCREENS_BASE                  ((U16) GET_RESOURCE_BASE(SRV_COMMON_SCREENS))
#define COMMON_SCREENS_BASE_MAX              ((U16) GET_RESOURCE_MAX(SRV_COMMON_SCREENS))
RESOURCE_BASE_TABLE_ITEM(SRV_COMMON_SCREENS)

/****************************************************************************
* Phone Setup
*****************************************************************************/

#define PHONE_SETUP_BASE                     ((U16) GET_RESOURCE_BASE(APP_PHONESETUP))
#define PHONE_SETUP_BASE_MAX                 ((U16) GET_RESOURCE_MAX(APP_PHONESETUP))
RESOURCE_BASE_TABLE_ITEM(APP_PHONESETUP)

#define SCREENSAVER_BASE                     ((U16) GET_RESOURCE_BASE(SRV_SCREENSAVER))
#define SCREENSAVER_BASE_MAX                 ((U16) GET_RESOURCE_MAX(SRV_SCREENSAVER))
RESOURCE_BASE_TABLE_ITEM(SRV_SCREENSAVER)

#define WALLPAPER_BASE                       ((U16) GET_RESOURCE_BASE(SRV_WALLPAPER))
#define WALLPAPER_BASE_MAX                   ((U16) GET_RESOURCE_MAX(SRV_WALLPAPER))
RESOURCE_BASE_TABLE_ITEM(SRV_WALLPAPER)

#define SPOF_BASE                            ((U16) GET_RESOURCE_BASE(SRV_SPOF))
#define SPOF_BASE_MAX                        ((U16) GET_RESOURCE_MAX(SRV_SPOF))
RESOURCE_BASE_TABLE_ITEM(SRV_SPOF)

#define NITZ_BASE                            ((U16) GET_RESOURCE_BASE(SRV_NITZ))
#define NITZ_BASE_MAX                        ((U16) GET_RESOURCE_MAX(SRV_NITZ))
RESOURCE_BASE_TABLE_ITEM(SRV_NITZ)

#define LANG_SETTINGS_BASE                   ((U16) GET_RESOURCE_BASE(SRV_LANG_SETTINGS))
#define LANG_SETTINGS_BASE_MAX               ((U16) GET_RESOURCE_MAX(SRV_LANG_SETTINGS))
RESOURCE_BASE_TABLE_ITEM(SRV_LANG_SETTINGS)

#define HELP_BASE                            ((U16) GET_RESOURCE_BASE(SRV_HELP))
#define HELP_BASE_MAX                        ((U16) GET_RESOURCE_MAX(SRV_HELP))
RESOURCE_BASE_TABLE_ITEM(SRV_HELP)

#define PHNSET_ONOFF_BASE                    ((U16) GET_RESOURCE_BASE(SRV_PHNSET_ONOFF))
#define PHNSET_ONOFF_BASE_MAX                ((U16) GET_RESOURCE_MAX(SRV_PHNSET_ONOFF))
RESOURCE_BASE_TABLE_ITEM(SRV_PHNSET_ONOFF)

#define FLIGHT_MODE_BASE                     ((U16) GET_RESOURCE_BASE(SRV_FLIGHT_MODE))
#define FLIGHT_MODE_BASE_MAX                 ((U16) GET_RESOURCE_MAX(SRV_FLIGHT_MODE))
RESOURCE_BASE_TABLE_ITEM(SRV_FLIGHT_MODE)

/* MMI Theme */
#define MMI_THEMES_BASE                      ((U16)GET_RESOURCE_BASE(SRV_MMI_THEME))
#define MMI_THEMES_BASE_MAX 			     ((U16)GET_RESOURCE_MAX(SRV_MMI_THEME))
RESOURCE_BASE_TABLE_ITEM(SRV_MMI_THEME)
/****************************************************************************
* Misc
*****************************************************************************/

#define SIM_DETECTION_BASE                   ((U16) GET_RESOURCE_BASE(APP_BOOTUP))
#define SIM_DETECTION_BASE_MAX               ((U16) GET_RESOURCE_MAX(APP_BOOTUP))
RESOURCE_BASE_TABLE_ITEM(APP_BOOTUP)

#define SAT_BASE                             ((U16) GET_RESOURCE_BASE(APP_SIMTOOLKIT))
#define SAT_BASE_MAX                         ((U16) GET_RESOURCE_MAX(APP_SIMTOOLKIT))
RESOURCE_BASE_TABLE_ITEM(APP_SIMTOOLKIT)

#define EMAIL_BASE                           ((U16) GET_RESOURCE_BASE(APP_EMAIL))
#define EMAIL_BASE_MAX                       ((U16) GET_RESOURCE_MAX(APP_EMAIL))
RESOURCE_BASE_TABLE_ITEM(APP_EMAIL)

#define IMPS_BASE                            ((U16) GET_RESOURCE_BASE(APP_IMPS))
#define IMPS_BASE_MAX                        ((U16) GET_RESOURCE_MAX(APP_IMPS))
RESOURCE_BASE_TABLE_ITEM(APP_IMPS)

#define CALL_NEW_BASE                        ((U16) GET_RESOURCE_BASE(APP_CALLSETUP))
#define CALL_BASE_NEW                        CALL_NEW_BASE /* Be backward compatible */
#define CALL_NEW_BASE_MAX                    ((U16) GET_RESOURCE_MAX(APP_CALLSETUP))
RESOURCE_BASE_TABLE_ITEM(APP_CALLSETUP)

#define CALL_HISTORY_BASE                    ((U16) GET_RESOURCE_BASE(APP_CALLHISTORY))
#define CALL_HISTORY                         CALL_HISTORY_BASE /* Be backward compatible */
#define CALL_HISTORY_BASE_MAX                ((U16) GET_RESOURCE_MAX(APP_CALLHISTORY))
RESOURCE_BASE_TABLE_ITEM(APP_CALLHISTORY)

#define PROFILES_BASE                        ((U16) GET_RESOURCE_BASE(APP_PROFILES))
#define PROFILES_BASE_MAX                    ((U16) GET_RESOURCE_MAX(APP_PROFILES))
RESOURCE_BASE_TABLE_ITEM(APP_PROFILES)

#define CHARGER_BASE                         ((U16) GET_RESOURCE_BASE(APP_CHARGER))
#define CHARGER_BASE_MAX                     ((U16) GET_RESOURCE_MAX(APP_CHARGER))
RESOURCE_BASE_TABLE_ITEM(APP_CHARGER)

#define CALL_BARRING_BASE                    ((U16) GET_RESOURCE_BASE(APP_CALLBARRING))
#define CALL_BARRING                         CALL_BARRING_BASE /* Be backward compatible */
#define CALL_BARRING_BASE_MAX                ((U16) GET_RESOURCE_MAX(APP_CALLBARRING))
RESOURCE_BASE_TABLE_ITEM(APP_CALLBARRING)

#define NETWORK_SETUP_BASE                   ((U16) GET_RESOURCE_BASE(APP_NETWORKSETUP))
#define NETWORK_SETUP_BASE_MAX               ((U16) GET_RESOURCE_MAX(APP_NETWORKSETUP))
RESOURCE_BASE_TABLE_ITEM(APP_NETWORKSETUP)

#define DOWNLOAD_BASE                        ((U16) GET_RESOURCE_BASE(APP_DOWNLOAD))
#define DOWNLOAD_BASE_MAX                    ((U16) GET_RESOURCE_MAX(APP_DOWNLOAD))
RESOURCE_BASE_TABLE_ITEM(APP_DOWNLOAD)

#define VOICE_MEMO_BASE                      ((U16) GET_RESOURCE_BASE(APP_VOICEMEMO))
#define VOICE_MEMO_BASE_MAX                  ((U16) GET_RESOURCE_MAX(APP_VOICEMEMO))
RESOURCE_BASE_TABLE_ITEM(APP_VOICEMEMO)

#define INPUT_METHOD_BASE                    ((U16) GET_RESOURCE_BASE(APP_INPUTMETHOD))
#define INPUT_METHOD_BASE_MAX                ((U16) GET_RESOURCE_MAX(APP_INPUTMETHOD))
RESOURCE_BASE_TABLE_ITEM(APP_INPUTMETHOD)

#define CTK_BASE                             ((U16) GET_RESOURCE_BASE(SRV_CTK))
#define CTK_BASE_MAX                         ((U16) GET_RESOURCE_MAX(SRV_CTK))
RESOURCE_BASE_TABLE_ITEM(SRV_CTK)

#define ENGINEER_MODE_BASE                   ((U16) GET_RESOURCE_BASE(APP_ENGINEERMODE))
#define ENGINEER_MODE_BASE_MAX               ((U16) GET_RESOURCE_MAX(APP_ENGINEERMODE))
RESOURCE_BASE_TABLE_ITEM(APP_ENGINEERMODE)

#define ENGINEER_MODE_APP_BASE               ((U16) GET_RESOURCE_BASE(APP_ENGINEERMODE_APP))
#define ENGINEER_MODE_APP_BASE_MAX           ((U16) GET_RESOURCE_MAX(APP_ENGINEERMODE_APP))
RESOURCE_BASE_TABLE_ITEM(APP_ENGINEERMODE_APP)

#define CAL_BASE                             ((U16) GET_RESOURCE_BASE(APP_CALENDAR))
#define CAL_BASE_MAX                         ((U16) GET_RESOURCE_MAX(APP_CALENDAR))
RESOURCE_BASE_TABLE_ITEM(APP_CALENDAR)

#define FACTORY_MODE_BASE                    ((U16) GET_RESOURCE_BASE(APP_FACTORYMODE))
#define FACTORY_MODE_BASE_MAX                ((U16) GET_RESOURCE_MAX(APP_FACTORYMODE))
RESOURCE_BASE_TABLE_ITEM(APP_FACTORYMODE)

#define COMPOSE_RING_TONE_ENGINE_BASE        ((U16) GET_RESOURCE_BASE(APP_RINGTONECOMPOSER))
#define COMPOSE_RING_TONE_ENGINE_BASE_MAX    ((U16) GET_RESOURCE_MAX(APP_RINGTONECOMPOSER))
RESOURCE_BASE_TABLE_ITEM(APP_RINGTONECOMPOSER)

#define COMPOSE_RINGTONE_BASE                ((U16) GET_RESOURCE_BASE(SRV_COMPOSE_RINGTONE))
#define COMPOSE_RINGTONE_BASE_MAX            ((U16) GET_RESOURCE_MAX(SRV_COMPOSE_RINGTONE))
RESOURCE_BASE_TABLE_ITEM(SRV_COMPOSE_RINGTONE)

#define WAP_BASE                             ((U16) GET_RESOURCE_BASE(APP_WAP))
#define WAP_BASE_MAX                         ((U16) GET_RESOURCE_MAX(APP_WAP))
RESOURCE_BASE_TABLE_ITEM(APP_WAP)

#define AUDIO_PLAYER_BASE                    ((U16) GET_RESOURCE_BASE(APP_AUDIOPLAYER))
#define AUDIO_PLAYER_BASE_MAX                ((U16) GET_RESOURCE_MAX(APP_AUDIOPLAYER))
RESOURCE_BASE_TABLE_ITEM(APP_AUDIOPLAYER)

#define AVBT_BASE                           ((U16) GET_RESOURCE_BASE(APP_AVBT))
#define AVBT_BASE_MAX                       ((U16) GET_RESOURCE_MAX(APP_AVBT))
RESOURCE_BASE_TABLE_ITEM(APP_AVBT)

#define SOUND_RECORDER_BASE                  ((U16) GET_RESOURCE_BASE(APP_SOUNDRECORDER))
#define SOUND_RECORDER_BASE_MAX              ((U16) GET_RESOURCE_MAX(APP_SOUNDRECORDER))
RESOURCE_BASE_TABLE_ITEM(APP_SOUNDRECORDER)

#define FILE_MANAGER_BASE                    ((U16) GET_RESOURCE_BASE(APP_FILEMANAGER))
#define FILE_MANAGER_BASE_MAX                ((U16) GET_RESOURCE_MAX(APP_FILEMANAGER))
RESOURCE_BASE_TABLE_ITEM(APP_FILEMANAGER)

#define JAVA_BASE                            ((U16) GET_RESOURCE_BASE(APP_JAVA))
#define JAVA_BASE_MAX                        ((U16) GET_RESOURCE_MAX(APP_JAVA))
RESOURCE_BASE_TABLE_ITEM(APP_JAVA)

#define EXT_DEVICE_BASE                      ((U16) GET_RESOURCE_BASE(APP_EXTDEVICE))
#define EXT_DEVICE_BASE_MAX                  ((U16) GET_RESOURCE_MAX(APP_EXTDEVICE))
RESOURCE_BASE_TABLE_ITEM(APP_EXTDEVICE)

#define MMEDIA_BASE                          ((U16) GET_RESOURCE_BASE(APP_MULTIMEDIA))
#define MMEDIA_BASE_MAX                      ((U16) GET_RESOURCE_MAX(APP_MULTIMEDIA))
RESOURCE_BASE_TABLE_ITEM(APP_MULTIMEDIA)

#define EXTRA_APP_BASE                       ((U16) GET_RESOURCE_BASE(APP_EXTRA))
#define EXTRA_APP_BASE_MAX                   ((U16) GET_RESOURCE_MAX(APP_EXTRA))
RESOURCE_BASE_TABLE_ITEM(APP_EXTRA)

#define NV_RAM_FILE_EXT_MELODY_BASE          ((U16) GET_RESOURCE_BASE(SRV_NV_RAM_FILE_EXT_MELODY))
#define NV_RAM_FILE_EXT_MELODY_ID_BASE       NV_RAM_FILE_EXT_MELODY_BASE
#define NV_RAM_FILE_EXT_MELODY_BASE_MAX      ((U16) GET_RESOURCE_MAX(SRV_NV_RAM_FILE_EXT_MELODY))
RESOURCE_BASE_TABLE_ITEM(SRV_NV_RAM_FILE_EXT_MELODY)

#define GAME_BASE                            ((U16) GET_RESOURCE_BASE(APP_GAMES))
#define GAME_BASE_MAX                        ((U16) GET_RESOURCE_MAX(APP_GAMES))
RESOURCE_BASE_TABLE_ITEM(APP_GAMES)

#define MMIAPI_BASE                          ((U16) GET_RESOURCE_BASE(SRV_MMIAPI))
#define MMIAPI_BASE_MAX                      ((U16) GET_RESOURCE_MAX(SRV_MMIAPI))
RESOURCE_BASE_TABLE_ITEM(SRV_MMIAPI)

#define VOBJECT_BASE                         ((U16) GET_RESOURCE_BASE(SRV_VOBJECT))
#define VOBJECT_BASE_MAX                     ((U16) GET_RESOURCE_MAX(SRV_VOBJECT))
RESOURCE_BASE_TABLE_ITEM(SRV_VOBJECT)

#define VCARD_BASE                           ((U16) GET_RESOURCE_BASE(SRV_VCARD))
#define VCARD_BASE_MAX                       ((U16) GET_RESOURCE_MAX(SRV_VCARD))
RESOURCE_BASE_TABLE_ITEM(SRV_VCARD)

#define VCALENDAR_BASE                       ((U16) GET_RESOURCE_BASE(SRV_VCALENDAR))
#define VCALENDAR_BASE_MAX                   ((U16) GET_RESOURCE_MAX(SRV_VCALENDAR))
RESOURCE_BASE_TABLE_ITEM(SRV_VCALENDAR)

 /*Added by shariq*/
#define VBOOKMARK_BASE                       ((U16) GET_RESOURCE_BASE(SRV_VBOOKMARK))
#define VBOOKMARK_BASE_MAX                   ((U16) GET_RESOURCE_MAX(SRV_VBOOKMARK))
RESOURCE_BASE_TABLE_ITEM(SRV_VBOOKMARK)

#define STOPWATCH_BASE                       ((U16) GET_RESOURCE_BASE(APP_STOPWATCH))
#define STOPWATCH_BASE_MAX                   ((U16) GET_RESOURCE_MAX(APP_STOPWATCH))
RESOURCE_BASE_TABLE_ITEM(APP_STOPWATCH)

#define DICTIONARY_BASE                      ((U16) GET_RESOURCE_BASE(APP_DICTIONARY))
#define DICTIONARY_BASE_MAX                  ((U16) GET_RESOURCE_MAX(APP_DICTIONARY))
RESOURCE_BASE_TABLE_ITEM(APP_DICTIONARY)

#define PICTURE_EDITOR_BASE                  ((U16) GET_RESOURCE_BASE(APP_PICTURE_EDITOR))
#define PICTURE_EDITOR_BASE_MAX              ((U16) GET_RESOURCE_MAX(APP_PICTURE_EDITOR))
RESOURCE_BASE_TABLE_ITEM(APP_PICTURE_EDITOR)

#define CAMERA_BASE                          ((U16) GET_RESOURCE_BASE(APP_CAMERA))
#define CAMERA_BASE_MAX                      ((U16) GET_RESOURCE_MAX(APP_CAMERA))
RESOURCE_BASE_TABLE_ITEM(APP_CAMERA)

#define BARCODEREADER_BASE                   ((U16) GET_RESOURCE_BASE(APP_BARCODEREADER))
#define BARCODEREADER_BASE_MAX               ((U16) GET_RESOURCE_MAX(APP_BARCODEREADER))
RESOURCE_BASE_TABLE_ITEM(APP_BARCODEREADER)

#define IMAGE_VIEWER_BASE                    ((U16) GET_RESOURCE_BASE(APP_IMAGEVIEWER))
#define IMAGE_VIEWER_BASE_MAX                ((U16) GET_RESOURCE_MAX(APP_IMAGEVIEWER))
RESOURCE_BASE_TABLE_ITEM(APP_IMAGEVIEWER)

#define VDOPLY_BASE                          ((U16) GET_RESOURCE_BASE(APP_VDOPLY))
#define VDOPLY_BASE_MAX                      ((U16) GET_RESOURCE_MAX(APP_VDOPLY))
RESOURCE_BASE_TABLE_ITEM(APP_VDOPLY)

#define VDOREC_BASE                          ((U16) GET_RESOURCE_BASE(APP_VDOREC))
#define VDOREC_BASE_MAX                      ((U16) GET_RESOURCE_MAX(APP_VDOREC))
RESOURCE_BASE_TABLE_ITEM(APP_VDOREC)

#define STREAMING_BASE                          ((U16) GET_RESOURCE_BASE(APP_STREAMING))
#define STREAMING_BASE_MAX                      ((U16) GET_RESOURCE_MAX(APP_STREAMING))
RESOURCE_BASE_TABLE_ITEM(APP_STREAMING)
#define FM_RADIO_BASE                        ((U16) GET_RESOURCE_BASE(APP_FMRDO))
#define FM_RADIO_BASE_MAX                    ((U16) GET_RESOURCE_MAX(APP_FMRDO))
RESOURCE_BASE_TABLE_ITEM(APP_FMRDO)

#define VRSD_BASE                            ((U16) GET_RESOURCE_BASE(SRV_VRSD))
#define VRSD_BASE_MAX                        ((U16) GET_RESOURCE_MAX(SRV_VRSD))
RESOURCE_BASE_TABLE_ITEM(SRV_VRSD)

#define VRSI_BASE                            ((U16) GET_RESOURCE_BASE(SRV_VRSI))
#define VRSI_BASE_MAX                        ((U16) GET_RESOURCE_MAX(SRV_VRSI))
RESOURCE_BASE_TABLE_ITEM(SRV_VRSI)

#define PHOEDT_BASE                          ((U16) GET_RESOURCE_BASE(APP_PHOEDT))
#define PHOEDT_BASE_MAX                      ((U16) GET_RESOURCE_MAX(APP_PHOEDT))
RESOURCE_BASE_TABLE_ITEM(APP_PHOEDT)

#define MESSAGE_CLUB_BASE                    ((U16) GET_RESOURCE_BASE(APP_MESSAGE_CLUB))
#define MESSAGE_CLUB_BASE_MAX                ((U16) GET_RESOURCE_MAX(APP_MESSAGE_CLUB))
RESOURCE_BASE_TABLE_ITEM(APP_MESSAGE_CLUB)

#define POC_BASE                             ((U16) GET_RESOURCE_BASE(SRV_POC))
#define POC_BASE_MAX                         ((U16) GET_RESOURCE_MAX(SRV_POC))
RESOURCE_BASE_TABLE_ITEM(SRV_POC)

#define AB_REPEATER_BASE                     ((U16) GET_RESOURCE_BASE(APP_ABREPEATER))
#define AB_REPEATER_BASE_MAX                 ((U16) GET_RESOURCE_MAX(APP_ABREPEATER))
RESOURCE_BASE_TABLE_ITEM(APP_ABREPEATER)

/****************************************************************************
* Schedule FM Radio Record
*****************************************************************************/
#define FM_SCHEDULE_REC_BASE                 ((U16) GET_RESOURCE_BASE(APP_FMSCHEDULEREC))
#define FM_SCHEDULE_REC_BASE_MAX             ((U16) GET_RESOURCE_MAX(APP_FMSCHEDULEREC))
RESOURCE_BASE_TABLE_ITEM(APP_FMSCHEDULEREC)

/****************************************************************************
* Background Sound Effect
*****************************************************************************/
#define BG_SOUND_BASE                        ((U16) GET_RESOURCE_BASE(APP_BGSOUND))
#define BG_SOUND_BASE_MAX                    ((U16) GET_RESOURCE_MAX(APP_BGSOUND))
RESOURCE_BASE_TABLE_ITEM(APP_BGSOUND)

#define DEVAPP_BASE                          ((U16) GET_RESOURCE_BASE(APP_DEVAPP))
#define DEVAPP_BASE_MAX                      ((U16) GET_RESOURCE_MAX(APP_DEVAPP))
RESOURCE_BASE_TABLE_ITEM(APP_DEVAPP)

/****************************************************************************
* Download Agent
*****************************************************************************/
#define DL_AGENT_BASE                        ((U16) GET_RESOURCE_BASE(APP_DOWNLOADAGENT))
#define DL_AGENT_BASE_MAX                    ((U16) GET_RESOURCE_MAX(APP_DOWNLOADAGENT))
RESOURCE_BASE_TABLE_ITEM(APP_DOWNLOADAGENT)

#define UMMS_MMS_BASE                        ((U16) GET_RESOURCE_BASE(APP_UMMS_MMS))
#define UMMS_MMS_BASE_MAX                    ((U16) GET_RESOURCE_MAX(APP_UMMS_MMS))
RESOURCE_BASE_TABLE_ITEM(APP_UMMS_MMS)
/****************************************************************************
* Porting Jataayu WAP/MMS
*****************************************************************************/
#define BROWSER_BASE                 ((U16) GET_RESOURCE_BASE(APP_BROWSER))
#define BROWSER_BASE_MAX             ((U16) GET_RESOURCE_MAX(APP_BROWSER))
RESOURCE_BASE_TABLE_ITEM(APP_BROWSER)

#define JATAAYU_PROFILE_BASE                 ((U16) GET_RESOURCE_BASE(APP_JATAAYU_PROFILE))
#define JATAAYU_PROFILE_BASE_MAX             ((U16) GET_RESOURCE_MAX(APP_JATAAYU_PROFILE))
RESOURCE_BASE_TABLE_ITEM(APP_JATAAYU_PROFILE)
/****************************************************************************
* SW Flash
*****************************************************************************/
#define SWFLASH_BASE                         ((U16) GET_RESOURCE_BASE(APP_SWFLASH))
#define SWFLASH_BASE_MAX                     ((U16) GET_RESOURCE_MAX(APP_SWFLASH))
RESOURCE_BASE_TABLE_ITEM(APP_SWFLASH)

/****************************************************************************
* SyncML
*****************************************************************************/
#define SYNCML_BASE                          ((U16) GET_RESOURCE_BASE(SRV_SYNCML))
#define SYNCML_BASE_MAX                      ((U16) GET_RESOURCE_MAX(SRV_SYNCML))
RESOURCE_BASE_TABLE_ITEM(SRV_SYNCML)

/****************************************************************************
* PictBridge
*****************************************************************************/
#define PICT_BRIDGE_BASE                     ((U16) GET_RESOURCE_BASE(SRV_PICT_BRIDGE))
#define PICT_BRIDGE_BASE_MAX                 ((U16) GET_RESOURCE_MAX(SRV_PICT_BRIDGE))
RESOURCE_BASE_TABLE_ITEM(SRV_PICT_BRIDGE)

#define VOIP_BASE                            ((U16) GET_RESOURCE_BASE(SRV_VOIP))
#define VOIP_BASE_MAX                        ((U16) GET_RESOURCE_MAX(SRV_VOIP))
RESOURCE_BASE_TABLE_ITEM(SRV_VOIP)

/*****************************************************************************
* CSB
******************************************************************************/
#define CSB_BASE                             ((U16) GET_RESOURCE_BASE(APP_CSB))
#define CSB_BASE_MAX                         ((U16) GET_RESOURCE_MAX(APP_CSB))
RESOURCE_BASE_TABLE_ITEM(APP_CSB)

RESOURCE_BASE_TABLE_ITEM(APP_DEFAULT_END)

#define VDOEDT_BASE                          ((U16) GET_RESOURCE_BASE(APP_VDOEDT))
#define VDOEDT_BASE_MAX                      ((U16) GET_RESOURCE_MAX(APP_VDOEDT))
RESOURCE_BASE_TABLE_ITEM(APP_VDOEDT)

/****************************************************************************
* MDI
*****************************************************************************/
#define MDI_BASE                          ((U16) GET_RESOURCE_BASE(SRV_MDI))
#define MDI_BASE_MAX                      ((U16) GET_RESOURCE_MAX(SRV_MDI))
RESOURCE_BASE_TABLE_ITEM(SRV_MDI)

/****************************************************************************
* Centralised Configuration Agent
*****************************************************************************/
#define CCA_BASE                             ((U16) GET_RESOURCE_BASE(APP_CCA))
#define CCA_BASE_MAX                         ((U16) GET_RESOURCE_MAX(APP_CCA))
RESOURCE_BASE_TABLE_ITEM(APP_CCA)

/****************************************************************************
* Avatar
*****************************************************************************/
#define AVATAR_BASE                          ((U16) GET_RESOURCE_BASE(APP_AVATAR))
#define AVATAR_BASE_MAX                      ((U16) GET_RESOURCE_MAX(APP_AVATAR))
RESOURCE_BASE_TABLE_ITEM(APP_AVATAR)

/****************************************************************************
* DM UI 
*****************************************************************************/
#define DMUI_BASE                            ((U16) GET_RESOURCE_BASE(APP_DMUI))
#define DMUI_BASE_MAX                        ((U16) GET_RESOURCE_MAX(APP_DMUI))
RESOURCE_BASE_TABLE_ITEM(APP_DMUI)

/****************************************************************************
* MONWAP
*****************************************************************************/
#define MONWAP_BASE                          ((U16) GET_RESOURCE_BASE(SRV_MONWAP))
#define MONWAP_BASE_MAX                      ((U16) GET_RESOURCE_MAX(SRV_MONWAP))
RESOURCE_BASE_TABLE_ITEM(SRV_MONWAP)

/****************************************************************************
* My favorite
*****************************************************************************/
#define MY_FAVORITE_BASE                     ((U16) GET_RESOURCE_BASE(APP_MYFAVORITE))
#define MY_FAVORITE_BASE_MAX                 ((U16) GET_RESOURCE_MAX(APP_MYFAVORITE))
RESOURCE_BASE_TABLE_ITEM(APP_MYFAVORITE)

/****************************************************************************
* Mobile Service
*****************************************************************************/
#define MOBILE_SERVICE_BASE                  ((U16) GET_RESOURCE_BASE(APP_MOBILE_SERVICE))
#define MOBILE_SERVICE_BASE_MAX              ((U16) GET_RESOURCE_MAX(APP_MOBILE_SERVICE))
RESOURCE_BASE_TABLE_ITEM(APP_MOBILE_SERVICE)

/****************************************************************************
* MMS BGSR
*****************************************************************************/
#define MMS_BGSR_BASE                        ((U16) GET_RESOURCE_BASE(APP_MMS_BGSR))
#define MMS_BGSR_BASE_MAX                    ((U16) GET_RESOURCE_MAX(APP_MMS_BGSR))
RESOURCE_BASE_TABLE_ITEM(APP_MMS_BGSR)

/****************************************************************************
* MMS V01 Agent
*****************************************************************************/
#define MMS_V01AGENT_BASE                        ((U16) GET_RESOURCE_BASE(APP_MMS_V01AGENT))
#define MMS_V01AGENT_BASE_MAX                    ((U16) GET_RESOURCE_MAX(APP_MMS_V01AGENT))
RESOURCE_BASE_TABLE_ITEM(APP_MMS_V01AGENT)


/****************************************************************************
* Customer Service
*****************************************************************************/
#define CUSTOMER_SERVICE_BASE                ((U16) GET_RESOURCE_BASE(APP_CUSTOMER_SERVICE))
#define CUSTOMER_SERVICE_BASE_MAX            ((U16) GET_RESOURCE_MAX(APP_CUSTOMER_SERVICE))
RESOURCE_BASE_TABLE_ITEM(APP_CUSTOMER_SERVICE)

/****************************************************************************
* UCM
*****************************************************************************/
#define UCM_BASE                             ((U16) GET_RESOURCE_BASE(APP_UCM))
#define UCM_BASE_MAX                         ((U16) GET_RESOURCE_MAX(APP_UCM))
RESOURCE_BASE_TABLE_ITEM(APP_UCM)

/****************************************************************************
* UCM service
*****************************************************************************/
#define SRV_UCM_BASE                             ((U16) GET_RESOURCE_BASE(SRV_UCM))
#define SRV_UCM_BASE_MAX                         ((U16) GET_RESOURCE_MAX(SRV_UCM))
RESOURCE_BASE_TABLE_ITEM(SRV_UCM)

/****************************************************************************
* Indian calendar application
*****************************************************************************/
#define INDICAL_BASE                         ((U16) GET_RESOURCE_BASE(APP_INDICAL))
#define INDICAL_BASE_MAX                     ((U16) GET_RESOURCE_MAX(APP_INDICAL))
RESOURCE_BASE_TABLE_ITEM(APP_INDICAL)

/****************************************************************************
* VT
*****************************************************************************/
#define VT_BASE                              ((U16) GET_RESOURCE_BASE(APP_VT))
#define VT_BASE_MAX                          ((U16) GET_RESOURCE_MAX(APP_VT))
RESOURCE_BASE_TABLE_ITEM(APP_VT)

/****************************************************************************
* Mobile TV Player 
*****************************************************************************/
#define MOBILE_TV_PLAYER_BASE                ((U16) GET_RESOURCE_BASE(APP_MOBILE_TV_PLAYER))
#define MOBILE_TV_PLAYER_BASE_MAX            ((U16) GET_RESOURCE_MAX(APP_MOBILE_TV_PLAYER))
RESOURCE_BASE_TABLE_ITEM(APP_MOBILE_TV_PLAYER)

/****************************************************************************
* Language Learning
*****************************************************************************/
#define LANGLN_BASE                          ((U16) GET_RESOURCE_BASE(APP_LANGLN))
#define LANGLN_BASE_MAX                      ((U16) GET_RESOURCE_MAX(APP_LANGLN))
RESOURCE_BASE_TABLE_ITEM(APP_LANGLN)

/****************************************************************************
* Slide Show
*****************************************************************************/
#define SLIDESHOW_BASE                       ((U16) GET_RESOURCE_BASE(APP_SLIDESHOW))
#define SLIDESHOW_BASE_MAX                   ((U16) GET_RESOURCE_MAX(APP_SLIDESHOW))
RESOURCE_BASE_TABLE_ITEM(APP_SLIDESHOW)

/****************************************************************************
* Certificate Manager
*****************************************************************************/
#define MMI_CERTMAN_BASE                     ((U16) GET_RESOURCE_BASE(APP_MMI_CERTMAN))
#define MMI_CERTMAN_BASE_MAX                 ((U16) GET_RESOURCE_MAX(APP_MMI_CERTMAN))
RESOURCE_BASE_TABLE_ITEM(APP_MMI_CERTMAN)

/****************************************************************************
* GIS
*****************************************************************************/
#define GIS_BASE                             ((U16) GET_RESOURCE_BASE(APP_GIS))
#define GIS_BASE_MAX                         ((U16) GET_RESOURCE_MAX(APP_GIS))
RESOURCE_BASE_TABLE_ITEM(APP_GIS)

/****************************************************************************
* Camcorder
*****************************************************************************/
#define CAMCORDER_BASE                       ((U16) GET_RESOURCE_BASE(APP_CAMCO))
#define CAMCORDER_BASE_MAX                   ((U16) GET_RESOURCE_MAX(APP_CAMCO))
RESOURCE_BASE_TABLE_ITEM(APP_CAMCO)

/****************************************************************************
* mercury module
*****************************************************************************/
//#ifdef __MMI_DUAL_SIM_MASTER__
#define MERCURY_BASE                         ((U16) GET_RESOURCE_BASE(APP_MERCURY))
#define MERCURY_BASE_MAX                     ((U16) GET_RESOURCE_MAX(APP_MERCURY))
RESOURCE_BASE_TABLE_ITEM(APP_MERCURY)
//#endif  /* __MMI_DUAL_SIM_MASTER__ */

/****************************************************************************
* DCD
*****************************************************************************/
#define DCD_BASE                             ((U16) GET_RESOURCE_BASE(APP_DCD))
#define DCD_BASE_MAX                         ((U16) GET_RESOURCE_MAX(APP_DCD))
RESOURCE_BASE_TABLE_ITEM(APP_DCD)

/****************************************************************************
* Software Tracer
*****************************************************************************/
#define SOFTWARE_TRACER_BASE                 ((U16) GET_RESOURCE_BASE(SRV_SOFTWARE_TRACER))
#define SOFTWARE_TRACER_BASE_MAX             ((U16) GET_RESOURCE_MAX(SRV_SOFTWARE_TRACER))
RESOURCE_BASE_TABLE_ITEM(SRV_SOFTWARE_TRACER)

/****************************************************************************
* Connection Management
*****************************************************************************/
#define CONNECT_MANAGE_BASE                  ((U16) GET_RESOURCE_BASE(APP_CONNECTMANAGEMENT))
#define CONNECT_MANAGE_BASE_MAX              ((U16) GET_RESOURCE_MAX(APP_CONNECTMANAGEMENT))
RESOURCE_BASE_TABLE_ITEM(APP_CONNECTMANAGEMENT)

/****************************************************************************
* Media Player
*****************************************************************************/
#define MEDPLY_BASE                          ((U16) GET_RESOURCE_BASE(APP_MEDPLY))
#define MEDPLY_BASE_MAX                      ((U16) GET_RESOURCE_MAX(APP_MEDPLY))
RESOURCE_BASE_TABLE_ITEM(APP_MEDPLY)

/****************************************************************************
* service play list
*****************************************************************************/
#define SRV_PLST_BASE                          ((U16) GET_RESOURCE_BASE(SRV_PLST))
#define SRV_PLST_BASE_MAX                      ((U16) GET_RESOURCE_MAX(SRV_PLST))
RESOURCE_BASE_TABLE_ITEM(SRV_PLST)

/****************************************************************************
* WAP PROF module
*****************************************************************************/
/* APP_MMI_WAP_PROF */
#define MMI_WAP_PROF_BASE                    ((U16) GET_RESOURCE_BASE(APP_MMI_WAP_PROF))
#define MMI_WAP_PROF_BASE_MAX                ((U16) GET_RESOURCE_MAX(APP_MMI_WAP_PROF))
RESOURCE_BASE_TABLE_ITEM(APP_MMI_WAP_PROF)

/****************************************************************************
* BCR
*****************************************************************************/
#define  BCR_BASE		                      ((U16) GET_RESOURCE_BASE(APP_BCR))
#define	 BCR_BASE_MAX	                      ((U16) GET_RESOURCE_MAX(APP_BCR))
RESOURCE_BASE_TABLE_ITEM(APP_BCR)

/****************************************************************************
* MMS Postcard
*****************************************************************************/
#define MMS_POSTCARD_BASE                    ((U16) GET_RESOURCE_BASE(APP_MMS_POSTCARD))
#define MMS_POSTCARD_MAX                     ((U16) GET_RESOURCE_MAX(APP_MMS_POSTCARD))
RESOURCE_BASE_TABLE_ITEM(APP_MMS_POSTCARD)

/****************************************************************************
* SDK Test module
*****************************************************************************/
#define AVK_BASE                              ((U16) GET_RESOURCE_BASE(APP_AVK))
#define AVK_BASE_MAX                          ((U16) GET_RESOURCE_MAX(APP_AVK))
RESOURCE_BASE_TABLE_ITEM(APP_AVK)

/* Vogins Start */
/****************************************************************************
* VRE module
*****************************************************************************/
#define VRE_BASE                              ((U16) GET_RESOURCE_BASE(APP_VRE))
#define VRE_BASE_MAX                          ((U16) GET_RESOURCE_MAX(APP_VRE))
RESOURCE_BASE_TABLE_ITEM(APP_VRE)


/****************************************************************************
* AM module
*****************************************************************************/
#define AM_BASE                              ((U16) GET_RESOURCE_BASE(APP_AM))
#define AM_BASE_MAX                          ((U16) GET_RESOURCE_MAX(APP_AM))
RESOURCE_BASE_TABLE_ITEM(APP_AM)
/* Vogins End */

/****************************************************************************
* Auto Answer Machine
*****************************************************************************/
#define AUTOAM_BASE                        ((U16) GET_RESOURCE_BASE(APP_AUTOAM))
#define AUTOAM_BASE_MAX                    ((U16) GET_RESOURCE_MAX(APP_AUTOAM))
RESOURCE_BASE_TABLE_ITEM(APP_AUTOAM)

/****************************************************************************
* UDX Machine
*****************************************************************************/
#define UDX_BASE                        ((U16) GET_RESOURCE_BASE(APP_UDX))
#define UDX_BASE_MAX                    ((U16) GET_RESOURCE_MAX(APP_UDX))
RESOURCE_BASE_TABLE_ITEM(APP_UDX)

/****************************************************************************
* UCWEB
*****************************************************************************/
#define UCWEB_BASE                             ((U16) GET_RESOURCE_BASE(APP_UCWEB))
#define UCWEB_BASE_MAX                         ((U16) GET_RESOURCE_MAX(APP_UCWEB))
RESOURCE_BASE_TABLE_ITEM(APP_UCWEB)

/****************************************************************************
* Provisioning Inbox UI
*****************************************************************************/
#define PROVBOXUI_BASE                        ((U16) GET_RESOURCE_BASE(APP_PROVBOXUI))
#define PROVBOXUI_BASE_MAX                    ((U16) GET_RESOURCE_MAX(APP_PROVBOXUI))
RESOURCE_BASE_TABLE_ITEM(APP_PROVBOXUI)

/****************************************************************************
* QQIM
*****************************************************************************/
#define QQ_BASE                        ((U16) GET_RESOURCE_BASE(APP_QQIM))
#define QQ_BASE_MAX                    ((U16) GET_RESOURCE_MAX(APP_QQIM))
RESOURCE_BASE_TABLE_ITEM(APP_QQIM)

/****************************************************************************
* QQ-Movie
*****************************************************************************/
#define QQ_MOVIE_BASE                        ((U16) GET_RESOURCE_BASE(APP_QQ_MOVIE))
#define QQ_MOVIE_BASE_MAX                    ((U16) GET_RESOURCE_MAX(APP_QQ_MOVIE))
RESOURCE_BASE_TABLE_ITEM(APP_QQ_MOVIE)

/****************************************************************************
* Hijri calendar application
*****************************************************************************/
#define HIJRI_BASE                         ((U16) GET_RESOURCE_BASE(APP_HIJRI_CALENDAR))
#define HIJRI_BASE_MAX                     ((U16) GET_RESOURCE_MAX(APP_HIJRI_CALENDAR))
RESOURCE_BASE_TABLE_ITEM(APP_HIJRI_CALENDAR)

/****************************************************************************
* Vendor A8Box
****************************************************************************/
    #define A8BOX_BASE                           ((U16) GET_RESOURCE_BASE(APP_A8BOX))
    #define A8BOX_BASE_MAX                       ((U16) GET_RESOURCE_MAX(APP_A8BOX))
    RESOURCE_BASE_TABLE_ITEM(APP_A8BOX)

/****************************************************************************
* Vendor GGLive
****************************************************************************/
    #define GGLIVE_BASE                           ((U16) GET_RESOURCE_BASE(APP_GGLIVE))
    #define GGLIVE_BASE_MAX                       ((U16) GET_RESOURCE_MAX(APP_GGLIVE))
    RESOURCE_BASE_TABLE_ITEM(APP_GGLIVE)

/****************************************************************************
* Note Application
****************************************************************************/
#define NOTE_APP_BASE                        ((U16) GET_RESOURCE_BASE(APP_NOTE))
#define NOTE_APP_BASE_MAX                    ((U16) GET_RESOURCE_MAX(APP_NOTE))
RESOURCE_BASE_TABLE_ITEM(APP_NOTE)

/****************************************************************************
* Virtual Keyboard
****************************************************************************/
#define VIRTUAL_KEYBOARD_IMG_BASE             ((U16) GET_RESOURCE_BASE(SRV_VIRTUAL_KEYBOARD))
#define VIRTUAL_KEYBOARD_IMG_BASE_MAX         ((U16) GET_RESOURCE_MAX(SRV_VIRTUAL_KEYBOARD))
RESOURCE_BASE_TABLE_ITEM(SRV_VIRTUAL_KEYBOARD)

#define VIRTUAL_KEYBOARD_MISC_IMG_BASE             ((U16) GET_RESOURCE_BASE(SRV_VIRTUAL_KEYBOARD_MISC))
#define VIRTUAL_KEYBOARD_MISC_IMG_BASE_MAX         ((U16) GET_RESOURCE_MAX(SRV_VIRTUAL_KEYBOARD_MISC))
RESOURCE_BASE_TABLE_ITEM(SRV_VIRTUAL_KEYBOARD_MISC)

/****************************************************************************
* Search-web Application
****************************************************************************/
#define SEARCH_WEB_BASE                      ((U16) GET_RESOURCE_BASE(APP_SEARCH_WEB))
#define SEARCH_WEB_BASE_MAX                  ((U16) GET_RESOURCE_MAX(APP_SEARCH_WEB))
RESOURCE_BASE_TABLE_ITEM(APP_SEARCH_WEB)

/****************************************************************************
* 116114 Application
****************************************************************************/
#define OP02_116114_BASE                      ((U16) GET_RESOURCE_BASE(APP_116114))
#define OP02_116114_BASE_MAX                  ((U16) GET_RESOURCE_MAX(APP_116114))
RESOURCE_BASE_TABLE_ITEM(APP_116114)

/****************************************************************************
* Online_Sales Application
****************************************************************************/
#define ONLINE_SALES_BASE                      ((U16) GET_RESOURCE_BASE(APP_ONLINE_SALES))
#define ONLINE_SALES_BASE_MAX                  ((U16) GET_RESOURCE_MAX(APP_ONLINE_SALES))
RESOURCE_BASE_TABLE_ITEM(APP_ONLINE_SALES)

/****************************************************************************
* Mobile_TV Application
****************************************************************************/
#define MOBILE_TV_BASE                      ((U16) GET_RESOURCE_BASE(APP_MOBILE_TV))
#define MOBILE_TV_BASE_MAX                  ((U16) GET_RESOURCE_MAX(APP_MOBILE_TV))
RESOURCE_BASE_TABLE_ITEM(APP_MOBILE_TV)

/****************************************************************************
* Pushmail Application
****************************************************************************/
#define PUSHMAIL_BASE                      ((U16) GET_RESOURCE_BASE(APP_PUSHMAIL))
#define PUSHMAIL_BASE_MAX                  ((U16) GET_RESOURCE_MAX(APP_PUSHMAIL))
RESOURCE_BASE_TABLE_ITEM(APP_PUSHMAIL)

/****************************************************************************
* Mobile_Stock Application
****************************************************************************/
#define MOBILE_STOCK_BASE                      ((U16) GET_RESOURCE_BASE(APP_MOBILE_STOCK))
#define MOBILE_STOCK_BASE_MAX                  ((U16) GET_RESOURCE_MAX(APP_MOBILE_STOCK))
RESOURCE_BASE_TABLE_ITEM(APP_MOBILE_STOCK)

/****************************************************************************
* Venus components
*****************************************************************************/
#define VENUS_COMPONENTS_BASE                    ((U16) GET_RESOURCE_BASE(SRV_VENUS_COMPONENTS))
#define VENUS_COMPONENTS_BASE_MAX                ((U16) GET_RESOURCE_MAX(SRV_VENUS_COMPONENTS))
RESOURCE_BASE_TABLE_ITEM(SRV_VENUS_COMPONENTS)

/****************************************************************************
* Zakat Calculator Application
****************************************************************************/ 
#define ZAKAT_CALCULATOR_BASE                      ((U16) GET_RESOURCE_BASE(APP_ZAKAT_CALCULATOR))
#define ZAKAT_CALCULATOR_BASE_MAX                  ((U16) GET_RESOURCE_MAX(APP_ZAKAT_CALCULATOR))
RESOURCE_BASE_TABLE_ITEM(APP_ZAKAT_CALCULATOR)

/****************************************************************************
* Azaan alarm application
*****************************************************************************/
#define AZAAN_ALARM_BASE                         ((U16) GET_RESOURCE_BASE(APP_AZAAN_ALARM))
#define AZAAN_ALARM_BASE_MAX                     ((U16) GET_RESOURCE_MAX(APP_AZAAN_ALARM))
RESOURCE_BASE_TABLE_ITEM(APP_AZAAN_ALARM)

/****************************************************************************
* Tone selector CUI
*****************************************************************************/
#define TONE_SELECTOR_BASE                         ((U16) GET_RESOURCE_BASE(CUI_TONE_SELECTOR))
#define TONE_SELECTOR_MAX                     ((U16) GET_RESOURCE_MAX(CUI_TONE_SELECTOR))
RESOURCE_BASE_TABLE_ITEM(CUI_TONE_SELECTOR)

/****************************************************************************
* Wap Push resources
*****************************************************************************/
#define MMI_WAP_PUSH_BASE                 ((U16) GET_RESOURCE_BASE(APP_MMI_WAP_PUSH))
#define MMI_WAP_PUSH_BASE_MAX             ((U16) GET_RESOURCE_MAX(APP_MMI_WAP_PUSH))
RESOURCE_BASE_TABLE_ITEM(APP_MMI_WAP_PUSH)

/****************************************************************************
* Venus FW
*****************************************************************************/
#define VENUS_FW_BASE                    ((U16) GET_RESOURCE_BASE(SRV_VENUS_FW))
#define VENUS_FW_BASE_MAX                ((U16) GET_RESOURCE_MAX(SRV_VENUS_FW))
RESOURCE_BASE_TABLE_ITEM(SRV_VENUS_FW)

/****************************************************************************
* Font manager
******************************************************************************/
/* Resource base for External Font support for vector font application */
#define FONT_MANAGER_BASE                     ((U16) GET_RESOURCE_BASE(APP_FONT_MANAGER))
#define FONT_MANAGER_BASE_MAX                 ((U16) GET_RESOURCE_MAX(APP_FONT_MANAGER))
RESOURCE_BASE_TABLE_ITEM(APP_FONT_MANAGER)
/*****************************************************************************/

/****************************************************************************
 * FTP application
 *****************************************************************************/
#define FTP_BASE                         ((U16) GET_RESOURCE_BASE(APP_FTP))
#define FTP_BASE_MAX                     ((U16) GET_RESOURCE_MAX(APP_FTP))
RESOURCE_BASE_TABLE_ITEM(APP_FTP)

/****************************************************************************
* Venus FW
*****************************************************************************/
#define MMI_CHARSET_BASE                    ((U16) GET_RESOURCE_BASE(SRV_MMI_CHARSET))
#define MMI_CHARSET_BASE_MAX                ((U16) GET_RESOURCE_MAX(SRV_MMI_CHARSET))
RESOURCE_BASE_TABLE_ITEM(SRV_MMI_CHARSET)

/****************************************************************************
* PBAP application
*****************************************************************************/
#define PBAP_BASE                         ((U16) GET_RESOURCE_BASE(APP_PBAP))
#define PBAP_BASE_MAX                     ((U16) GET_RESOURCE_MAX(APP_PBAP))
RESOURCE_BASE_TABLE_ITEM(APP_PBAP)

/****************************************************************************
* OPP application
*****************************************************************************/
#define OPP_BASE                         ((U16) GET_RESOURCE_BASE(APP_OPP))
#define OPP_BASE_MAX                     ((U16) GET_RESOURCE_MAX(APP_OPP))
RESOURCE_BASE_TABLE_ITEM(APP_OPP)

/****************************************************************************
* BIP application
*****************************************************************************/
#define BIP_BASE                         ((U16) GET_RESOURCE_BASE(APP_BIP))
#define BIP_BASE_MAX                     ((U16) GET_RESOURCE_MAX(APP_BIP))
RESOURCE_BASE_TABLE_ITEM(APP_BIP)

/****************************************************************************
* Media Wall application
*****************************************************************************/
#define MEDIAWALL_BASE                        ((U16) GET_RESOURCE_BASE(APP_MEDIAWALL))
#define MEDIAWALL_BASE_MAX                    ((U16) GET_RESOURCE_MAX(APP_MEDIAWALL))
RESOURCE_BASE_TABLE_ITEM(APP_MEDIAWALL)

/****************************************************************************
* 3D Cube Venus App
******************************************************************************/
#define VENUS_CUBE_APP_BASE                        ((U16) GET_RESOURCE_BASE(APP_VENUS_CUBE))
#define VENUS_CUBE_APP_BASE_MAX                    ((U16) GET_RESOURCE_MAX(APP_VENUS_CUBE))
RESOURCE_BASE_TABLE_ITEM(APP_VENUS_CUBE)

/*****************************************************************************/

/* please add new resource base table above this line */
/* End of resource table */
RESOURCE_BASE_TABLE_END()

#endif /* MMI_RES_REANGE_DEF_H */

