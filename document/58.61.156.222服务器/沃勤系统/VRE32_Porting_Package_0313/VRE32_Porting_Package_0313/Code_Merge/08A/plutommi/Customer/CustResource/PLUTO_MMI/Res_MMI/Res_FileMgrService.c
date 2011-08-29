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
#include "MMI_features.h" 

#if defined(__MMI_FILE_MANAGER__)
#include "MMIDataType.h"    /* for resource base */

#include "CustResDef.h"         /* for image/audio path */
#include "CustDataProts.h"      /* for resource generator API */
#include "GlobalMenuItems.h"    /* for menu resource */

/****************************************************************************/

#include "FileMgrServiceResDef.h"

/****************************************************************************/
/* include your OWN RESOURCE ID here. */

#include "FunAndGamesResDef.h"
#ifdef __MMI_EBOOK_READER__
#include "EbookResDef.h"
#endif

/****************************************************************************/

#ifdef __MMI_SUB_WALLPAPER__
#define FMGR_COMMON_FWD_IMAGE_SUB_WALLPAPER \
    MENU_ID_FMGR_FWD_SUB_WALLPAPER,
#else
#define FMGR_COMMON_FWD_IMAGE_SUB_WALLPAPER
#endif

#ifdef __MMI_POWER_ON_OFF_DISPLAY__
#define FMGR_COMMON_FWD_IMAGE_POWER_ONOFF \
    MENU_ID_FMGR_FWD_POWER_ON, \
    MENU_ID_FMGR_FWD_POWER_OFF,
#else
#define FMGR_COMMON_FWD_IMAGE_POWER_ONOFF
#endif

/****************************************************************************/





/****************************************************************************/

#if !defined (__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
#define FMGR_COMMON_FWD_SMS     MENU_ID_FMGR_FWD_SMS,
#else
#define FMGR_COMMON_FWD_SMS
#endif

#if (defined( __MMI_MESSAGES_EMS__) && !defined (__MMI_FMGR_NO_FWD_SMS__))
#define FMGR_COMMON_FWD_EMS     MENU_ID_FMGR_FWD_EMS,
#else
#define FMGR_COMMON_FWD_EMS
#endif

#ifdef __MMI_MMS__
#define FMGR_COMMON_FWD_MMS     MENU_ID_FMGR_FWD_MMS,
#else
#define FMGR_COMMON_FWD_MMS
#endif

#if defined(__MMI_MMS_2__) && defined(__MMI_OP11_MMS_SEND_TO_PHOTO_BLOG__)
/* under construction !*/
#else
#define FMGR_COMMON_FWD_TO_BLOG
#endif

#ifdef __MMI_EMAIL__
#define FMGR_COMMON_FWD_EMAIL   MENU_ID_FMGR_FWD_EMAIL,
#else
#define FMGR_COMMON_FWD_EMAIL
#endif

#ifdef __MMI_IRDA_SUPPORT__
#define FMGR_COMMON_FWD_IRDA    MENU_ID_FMGR_FWD_IRDA,
#else
#define FMGR_COMMON_FWD_IRDA
#endif

/* Bluetooth sending API revise */
#ifdef __MMI_BT_SEND_SUPPORT__
#define FMGR_COMMON_FWD_BT      MENU_ID_FMGR_FWD_BT,
#else
#define FMGR_COMMON_FWD_BT
#endif

/****************************************************************************/

//#ifdef DEVELOPER_BUILD_FIRST_PASS
#include "PopulateRes.h"

void PopulateFileMgrServMenuRes(void)
{
    /************************************************************/
    /*                                                          */
    /*          Forward Option                                  */
    /*                                                          */
    /************************************************************/

    ADD_FMGR_MENUITEM((MENU_ID_FMGR_GEN_SEND_OPTION, 0,
        FMGR_COMMON_FWD_MMS
        FMGR_COMMON_FWD_EMAIL
        FMGR_COMMON_FWD_IRDA
        FMGR_COMMON_FWD_BT
        MENU_ITEM_END,
        SHOW, MOVEABLEWITHINPARENT|INSERTABLE, DISP_LIST, STR_GLOBAL_SEND,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_FWD_WALLPAPER,       0, 0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_FMGR_WALLPAPER,0));
#ifdef __MMI_SUB_WALLPAPER__		
    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_FWD_SUB_WALLPAPER,   0, 0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_FMGR_SUB_WALLPAPER,0));
#endif		
    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_FWD_SCREENSAVER,     0, 0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_FMGR_SCREENSAVER,0));
#ifdef __MMI_POWER_ON_OFF_DISPLAY__
    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_FWD_POWER_ON,        0, 0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_FMGR_POWER_ON,0));
    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_FWD_POWER_OFF,       0, 0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_FMGR_POWER_OFF,0));
#endif
    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_FWD_PHB,             0, 0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_FMGR_PHB,0));
    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_FWD_TODOLIST,        0, 0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_FMGR_TODOLIST,0));
#ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_FWD_PROFILE,         0, 0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_FMGR_PROFILE,0));
#endif
#ifdef __MMI_BG_SOUND_EFFECT__
    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_FWD_BGSOUND,         0, 0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_FMGR_BGSOUND,0));
#endif

    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_FWD_SMS,             0, 0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_FMGR_SMS,0));
#ifdef __MMI_MESSAGES_EMS__
    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_FWD_EMS,             0, 0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_FMGR_EMS,0));
#endif
#ifdef __MMI_MMS__
    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_FWD_MMS,             0, 0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_FMGR_MMS,0));
#ifdef __MMI_MMS_2__
#ifdef __MMI_OP11_MMS_SEND_TO_PHOTO_BLOG__
/* under construction !*/
#endif
#endif
#endif
#ifdef __MMI_IRDA_SUPPORT__
    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_FWD_IRDA,            0, 0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_FMGR_IRDA,0));
#endif
#ifdef __MMI_BT_SUPPORT__
    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_FWD_BT,              0, 0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_FMGR_BT,0));
#endif
#ifdef __MMI_EMAIL__
    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_FWD_EMAIL,           0, 0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_FMGR_EMAIL,0));
#endif


#if defined(__MMI_PICT_BRIDGE_SUPPORT__) || defined(__MMI_BPP_SUPPORT__)
    ADD_APPLICATION_MENUITEM2((MENU_ID_FMGR_IMG_OPTION_PRINT,0,
#if defined(__MMI_PICT_BRIDGE_SUPPORT__)
        MENU_ID_FMGR_PRINT_PICTBRIGE,
#endif
#if defined(__MMI_BPP_SUPPORT__)
        MENU_ID_FMGR_PRINT_BLUETOOTH,
#endif
        MENU_ITEM_END,
        SHOW, MOVEABLEWITHINPARENT|INSERTABLE, DISP_LIST, STR_ID_FMGR_PRINT,0));
#endif

#if defined(__MMI_PICT_BRIDGE_SUPPORT__)
    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_PRINT_PICTBRIGE,     0, 0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_ID_FMGR_TO_PICTBRIGE,0));
#endif
#if defined(__MMI_BPP_SUPPORT__)
    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_PRINT_BLUETOOTH,     0, 0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_FMGR_BT,           0));
#endif

    /************************************************************/
    /*                                                          */
    /*          File Type Option                                */
    /*                                                          */
    /************************************************************/

    /********************* Image files *********************************/

    ADD_FMGR_MENUITEM((MENU_ID_FMGR_IMG_TYPE_OPTIONS,0,
        MENU_ID_FMGR_IMG_OPTION_VIEW, 
#if defined(__MMI_BPP_SUPPORT__) || defined(__MMI_PICT_BRIDGE_SUPPORT__)
        MENU_ID_FMGR_IMG_OPTION_PRINT,
#endif
        MENU_ID_FMGR_IMG_OPTION_JPG_DETAIL, 
#ifdef __MMI_PHOTOEDITOR__
        MENU_ID_FMGR_IMG_OPTION_EDIT,
#endif
        FMGR_GENERAL_OPTION
        MENU_ITEM_END,
        SHOW, NONMOVEABLE|INSERTABLE, DISP_LIST, STR_FMGR_GEN_OPTION,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_IMG_OPTION_VIEW,     0, 0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_GLOBAL_VIEW, 0));
    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_IMG_OPTION_JPG_DETAIL,0,0, SHOW, NONMOVEABLE,          DISP_LIST, STR_FMGR_VIEW_IMG_JPG_DETAIL,0));
#ifdef __MMI_PHOTOEDITOR__
    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_IMG_OPTION_EDIT,     0, 0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_GLOBAL_EDIT,   0));
#endif

    ADD_FMGR_MENUITEM((MENU_ID_FMGR_IMG_FWD_USE_OPTION,0,       
#if !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)
        MENU_ID_FMGR_FWD_WALLPAPER,
        FMGR_COMMON_FWD_IMAGE_SUB_WALLPAPER
        MENU_ID_FMGR_FWD_SCREENSAVER,
        FMGR_COMMON_FWD_IMAGE_POWER_ONOFF
        MENU_ID_FMGR_FWD_PHB,
#endif
        MENU_ITEM_END,
        SHOW, MOVEABLEWITHINPARENT|INSERTABLE, DISP_LIST, STR_FMGR_USE,0));

    ADD_FMGR_MENUITEM((MENU_ID_FMGR_IMG_FWD_SEND_OPTION,0,       
        FMGR_COMMON_FWD_EMS
        FMGR_COMMON_FWD_MMS
        FMGR_COMMON_FWD_TO_BLOG
        FMGR_COMMON_FWD_EMAIL
        FMGR_COMMON_FWD_IRDA
        FMGR_COMMON_FWD_BT
        MENU_ITEM_END,
        SHOW, MOVEABLEWITHINPARENT|INSERTABLE, DISP_LIST, STR_GLOBAL_SEND,0));

    /********************* Audio files *********************************/

    ADD_FMGR_MENUITEM((MENU_ID_FMGR_AUD_TYPE_OPTIONS,0,
        MENU_ID_FMGR_AUD_OPTION_PLAY, 
        FMGR_GENERAL_OPTION
        MENU_ITEM_END,
        SHOW, NONMOVEABLE|INSERTABLE, DISP_LIST, STR_FMGR_GEN_OPTION,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_AUD_OPTION_PLAY,     0, 0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_FMGR_PLAY_AUDIO,0));

    ADD_APPLICATION_MENUITEM2((MENU_ID_FMGR_AUD_FWD_USE_OPTION,0,
#ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
        MENU_ID_FMGR_FWD_PROFILE,  
#endif
#ifdef __MMI_BG_SOUND_EFFECT__      
        MENU_ID_FMGR_FWD_BGSOUND,      
#endif      
        MENU_ITEM_END,
        SHOW, MOVEABLEWITHINPARENT|INSERTABLE, DISP_LIST, STR_FMGR_USE,0));

    ADD_FMGR_MENUITEM((MENU_ID_FMGR_AUD_FWD_SEND_OPTION,0,
        FMGR_COMMON_FWD_EMS
        FMGR_COMMON_FWD_MMS
        FMGR_COMMON_FWD_TO_BLOG
        FMGR_COMMON_FWD_EMAIL
        FMGR_COMMON_FWD_IRDA
        FMGR_COMMON_FWD_BT
        MENU_ITEM_END,
        SHOW, MOVEABLEWITHINPARENT|INSERTABLE, DISP_LIST, STR_GLOBAL_SEND,0));


    /********************* Video files *********************************/

    ADD_FMGR_MENUITEM((MENU_ID_FMGR_VID_TYPE_OPTIONS,0,
        MENU_ID_FMGR_VID_OPTION_PLAY, 
        FMGR_GENERAL_OPTION
        MENU_ITEM_END,
        SHOW, NONMOVEABLE|INSERTABLE, DISP_LIST, STR_FMGR_GEN_OPTION,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_VID_OPTION_PLAY,     0, 0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_FMGR_PLAY_VIDEO,0));
    
    ADD_APPLICATION_MENUITEM2((MENU_ID_FMGR_VID_FWD_USE_OPTION,0,
#if !defined(__MMI_DISPLAY_CHAR_HIDE_MENU_FROM_FILE__)
    #ifdef __MMI_SCREENSAVER_DISPLAY_VIDEO__
        MENU_ID_FMGR_FWD_SCREENSAVER,
    #endif
    #ifdef __MMI_POWER_ON_OFF_DISPLAY_VIDEO__
        MENU_ID_FMGR_FWD_POWER_ON,
        MENU_ID_FMGR_FWD_POWER_OFF,
    #endif
    #ifdef __MMI_INCOMING_CALL_VIDEO__
        MENU_ID_FMGR_FWD_PHB,
    #endif         
#endif
        MENU_ITEM_END,
        SHOW, MOVEABLEWITHINPARENT|INSERTABLE, DISP_LIST, STR_FMGR_USE,0));

    ADD_FMGR_MENUITEM((MENU_ID_FMGR_VID_FWD_SEND_OPTION,0,
        FMGR_COMMON_FWD_MMS
        FMGR_COMMON_FWD_TO_BLOG
        FMGR_COMMON_FWD_EMAIL
        FMGR_COMMON_FWD_IRDA
        FMGR_COMMON_FWD_BT
        MENU_ITEM_END,
        SHOW, MOVEABLEWITHINPARENT|INSERTABLE, DISP_LIST, STR_GLOBAL_SEND,0));

#if defined ( __J2ME__ ) 
/********************* Java files *********************************/

    ADD_FMGR_MENUITEM((MENU_ID_FMGR_JAVA_TYPE_OPTIONS,0,
    #if !defined (__MMI_FMGR_DISABLE_JAVA_INSTALL__)
        MENU_ID_FMGR_JAVA_OPTION_EXECUTE, 
    #endif
        FMGR_GENERAL_OPTION
        MENU_ITEM_END,
        SHOW, NONMOVEABLE|INSERTABLE, DISP_LIST, STR_FMGR_GEN_OPTION,0));

    #if !defined (__MMI_FMGR_DISABLE_JAVA_INSTALL__)
    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_JAVA_OPTION_EXECUTE, 0, 0, SHOW, MOVEABLEWITHINPARENT, DISP_LIST, STR_FMGR_EXECUTE,0));
    #endif
#endif

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
/********************* Theme files *********************************/

    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_THEME_ACTIVATE,      0, 0, SHOW, NONMOVEABLE, DISP_LIST, STR_THEMES_ACTIVATE,0));

    ADD_FMGR_MENUITEM((MENU_ID_FMGR_THEME_TYPE_OPTIONS, 0,
        MENU_ID_FMGR_THEME_ACTIVATE, 
        FMGR_GENERAL_OPTION
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, DISP_LIST, STR_FMGR_THEME_OPTION,0));

#endif


#ifdef __CERTMAN_SUPPORT__
/********************* CERT files *********************************/

    ADD_APPLICATION_MENUITEM((MENU_FMGR_CER_OPTION_INSTALL,     0, 0, SHOW, NONMOVEABLE, DISP_LIST, STR_FMGR_EXECUTE,0));

    ADD_FMGR_MENUITEM((MENU_ID_FMGR_CERT_TYPE_OPTIONS,0,
        MENU_FMGR_CER_OPTION_INSTALL, 
        FMGR_GENERAL_OPTION
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, DISP_LIST, STR_FMGR_GEN_OPTION,0));
#endif

#ifdef __MMI_EBOOK_READER__
/********************* Ebook files *********************************/

    ADD_FMGR_MENUITEM((MENU_ID_FMGR_EBOOK_TYPE_OPTIONS,0,
        MENU_ID_FMGR_EBOOK_OPTION_OPEN, 
        FMGR_GENERAL_OPTION
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, DISP_LIST, STR_FMGR_GEN_OPTION,0));

    ADD_APPLICATION_MENUITEM2((MENU_ID_FMGR_EBOOK_NFO_TYPE_OPTIONS,0,
        MENU_ID_FMGR_EBOOK_OPTION_OPEN, 
        MENU_ID_FMGR_GEN_OPTION_DETAIL, 
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, DISP_LIST, STR_FMGR_GEN_OPTION,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_EBOOK_OPTION_OPEN,   0, 0, SHOW, NONMOVEABLE, DISP_LIST, STR_OPEN_EBOOK,0));
#endif


#if defined(__MMI_BROWSER_2__)
/********************* bookmark files *********************************/

    ADD_FMGR_MENUITEM((MENU_ID_FMGR_BOOKMARK_TYPE_OPTIONS,0,
        MENU_ID_FMGR_BOOKMARK_FILE_OPEN, 
        FMGR_GENERAL_OPTION
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, DISP_LIST, STR_FMGR_GEN_OPTION,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_BOOKMARK_FILE_OPEN,  0, 0, SHOW, NONMOVEABLE, DISP_LIST, STR_GLOBAL_GO_TO,0));
#endif

/* Vogins Start */
#if defined(__VRE__)
/********************* vre *********************************/

    ADD_FMGR_MENUITEM((MENU_ID_FMGR_VRE_TYPE_OPTIONS,0,
        MENU_ID_FMGR_VRE_FILE_OPEN, 
        FMGR_GENERAL_OPTION
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, DISP_LIST, STR_GLOBAL_OPTIONS,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_VRE_FILE_OPEN,  0, 0, SHOW, NONMOVEABLE, DISP_LIST, STR_GLOBAL_OPEN,0));
#endif
/* Vogins End */

#ifdef __MMI_VCARD__
/********************* vcard files *********************************/

    ADD_APPLICATION_MENUITEM2((MENU_ID_FMGR_VCARD_FWD_USE_OPTION,0,
        MENU_ID_FMGR_FWD_PHB,
        MENU_ITEM_END,
        SHOW, MOVEABLEWITHINPARENT|INSERTABLE, DISP_LIST, STR_FMGR_USE,0));

    ADD_FMGR_MENUITEM((MENU_ID_FMGR_VCARD_FWD_SEND_OPTION,0,
        FMGR_COMMON_FWD_SMS
        FMGR_COMMON_FWD_MMS
        FMGR_COMMON_FWD_EMAIL
        FMGR_COMMON_FWD_IRDA
        FMGR_COMMON_FWD_BT
        MENU_ITEM_END,
        SHOW, MOVEABLEWITHINPARENT|INSERTABLE, DISP_LIST, STR_GLOBAL_SEND,0));
#endif

#ifdef __MMI_VCALENDAR__
/********************* vcalendar files *********************************/
    ADD_APPLICATION_MENUITEM2((MENU_ID_FMGR_VCAL_FWD_USE_OPTION,0,
        MENU_ID_FMGR_FWD_TODOLIST,
        MENU_ITEM_END,
        SHOW, MOVEABLEWITHINPARENT|INSERTABLE, DISP_LIST, STR_FMGR_USE,0));

    ADD_FMGR_MENUITEM((MENU_ID_FMGR_VCAL_FWD_SEND_OPTION,0,
        FMGR_COMMON_FWD_SMS
        FMGR_COMMON_FWD_MMS
        FMGR_COMMON_FWD_EMAIL
        FMGR_COMMON_FWD_IRDA
        FMGR_COMMON_FWD_BT
        MENU_ITEM_END,
        SHOW, MOVEABLEWITHINPARENT|INSERTABLE, DISP_LIST, STR_GLOBAL_SEND,0));
#endif

#ifdef __MMI_SWFLASH__
/********************* MFH files *********************************/

    ADD_FMGR_MENUITEM((MENU_ID_FMGR_MFH_FWD_USE_OPTION,0,
        MENU_ID_FMGR_FWD_WALLPAPER,
        MENU_ID_FMGR_FWD_SCREENSAVER,
        FMGR_COMMON_FWD_IMAGE_POWER_ONOFF
    #ifdef __MMI_INCOMING_CALL_VIDEO__
        MENU_ID_FMGR_FWD_PHB,
    #endif
        MENU_ITEM_END,
        SHOW, MOVEABLEWITHINPARENT|INSERTABLE, DISP_LIST, STR_FMGR_USE,0));

    ADD_FMGR_MENUITEM((MENU_ID_FMGR_MFH_FWD_SEND_OPTION,0,
        FMGR_COMMON_FWD_MMS
        FMGR_COMMON_FWD_EMAIL
        FMGR_COMMON_FWD_IRDA
        FMGR_COMMON_FWD_BT
        MENU_ITEM_END,
        SHOW, MOVEABLEWITHINPARENT|INSERTABLE, DISP_LIST, STR_GLOBAL_SEND,0));
#endif

#ifdef __MMI_VBOOKMARK__ 
/********************* vbookmark files *********************************/

    ADD_FMGR_MENUITEM((MENU_ID_FMGR_VBOOKMARK_TYPE_OPTIONS,0,
        MENU_ID_FMGR_VBOOKMARK_OPTION_GOTO, 
        MENU_ID_FMGR_VBOOKMARK_OPTION_OPEN,
        FMGR_GENERAL_OPTION
        MENU_ITEM_END,
        SHOW, NONMOVEABLE, DISP_LIST, STR_FMGR_GEN_OPTION,0));

    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_VBOOKMARK_OPTION_GOTO, 0, 0, SHOW, NONMOVEABLE, DISP_LIST, STR_GLOBAL_GO_TO, 0));
    ADD_APPLICATION_MENUITEM((MENU_ID_FMGR_VBOOKMARK_OPTION_OPEN, 0, 0, SHOW, NONMOVEABLE, DISP_LIST, STR_FMGR_OPEN,    0));

    ADD_FMGR_MENUITEM((MENU_ID_FMGR_VBOOKMARK_FWD_SEND_OPTION,0,
        FMGR_COMMON_FWD_SMS
        FMGR_COMMON_FWD_MMS
        FMGR_COMMON_FWD_EMAIL
        FMGR_COMMON_FWD_IRDA
        FMGR_COMMON_FWD_BT
        MENU_ITEM_END,
        SHOW, MOVEABLEWITHINPARENT|INSERTABLE, DISP_LIST, STR_GLOBAL_SEND,0));
#endif




// Template, insert above this line.
#if 0 //def __YOUR_FEATURE__ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
}

void PopulateFileMgrServImgRes(void)
{
    /********* small icon *********/
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_ICON_FILE_TYPE_IMG,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIIMAGE.pbm", "image icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_ICON_FILE_TYPE_MSG,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIMSG.pbm", "message icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_ICON_FILE_TYPE_AUD,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIAUDIO.pbm", "audio icon" );

#ifdef __MMI_VIDEO_PLAYER__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_ICON_FILE_TYPE_VDO,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIVIDEO.pbm", "video icon" );
#endif

#ifdef __J2ME__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_ICON_FILE_TYPE_JAVA,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIJAVA.pbm", "java icon" );
#endif

#ifdef __MMI_VCARD__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_ICON_FILE_TYPE_VCF,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIVCF.pbm", "vcf icon" );
#endif

#ifdef __MMI_VCALENDAR__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_ICON_FILE_TYPE_VCS,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIVCS.pbm", "vcs icon" );
#endif

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_ICON_FILE_TYPE_THEME,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIIMAGE.pbm", "theme icon" );
#endif

#ifdef __MMI_SVG__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_ICON_FILE_TYPE_SVG,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SISVG.pbm", "SVG icon" );
#endif


#ifdef __MMI_BARCODEREADER__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_ICON_FILE_TYPE_MBC,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIQRV.pbm", "MBC icon" );
#endif

#ifdef __MMI_SWFLASH__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_ICON_FILE_TYPE_SWFLASH,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_Sianimation.pbm", "swflash icon" );
#endif

    /********* large icon **********/

    /* image */
#ifdef __MMI_SLIM_FILE_MANAGER__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_BMP,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIIMAGE.gif", "bmp large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_JPG,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIIMAGE.gif", "jpg large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_GIF,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIIMAGE.gif", "gif large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_PNG,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIIMAGE.gif", "png large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_WBMP,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIIMAGE.gif", "wbmp large icon" );

    #ifdef M3D_MMI_SUPPORT
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_M3D,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIIMAGE.gif", "m3d large icon" );
    #endif /* M3D_MMI_SUPPORT */

    /* message */
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_EMS,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIIMAGE.gif", "ems large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_ANM,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIIMAGE.gif", "anm large icon" );

#else
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_BMP,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIBMP.gif", "bmp large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_JPG,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIJPG.gif", "jpg large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_GIF,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIGIF.gif", "gif large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_PNG,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIPNG.gif", "png large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_WBMP,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIWBMP.gif", "wbmp large icon" );

    #ifdef M3D_MMI_SUPPORT
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_M3D,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIM3D.gif", "m3d large icon" );
    #endif /* M3D_MMI_SUPPORT */

    /* message */
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_EMS,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIEMS.gif", "ems large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_ANM,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIANM.gif", "anm large icon" );
#endif


    /* audio */
#ifdef __MMI_SLIM_FILE_MANAGER__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_DAF,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.gif", "daf large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_IMY,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.gif", "imy large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_MID,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.gif", "midi large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_WAV,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.gif", "wav large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_AMR,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.gif", "amr large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_AAC,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.gif", "aac large icon" );
    
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_VM,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.gif", "vm large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_AWB,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.gif", "awb large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_AIF,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.gif", "aif large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_AU,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.gif", "au large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_SND,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.gif", "snd large icon" );

    #ifdef AAC_DECODE
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_M4A,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAUDIO.gif", "m4a large icon" );
    #endif

    #ifdef BSAC_DECODE
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_BSAC,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIBSAC.gif", "bsac large icon" );
    #endif 


#else
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_DAF,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIDAF.gif", "daf large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_IMY,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIIMY.gif", "imy large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_MID,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIMIDI.gif", "midi large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_WAV,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIWAV.gif", "wav large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_AMR,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAMR.gif", "amr large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_AAC,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAAC.gif", "aac large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_VM,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIVM.gif", "vm large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_AWB,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAWB.gif", "awb large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_AIF,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAIF.gif", "aif large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_AU,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAU.gif", "au large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_SND,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LISND.gif", "snd large icon" );


    #ifdef AAC_DECODE
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_M4A,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIM4A.gif", "m4a large icon" );
    #endif 

    #ifdef BSAC_DECODE
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_BSAC,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIBSAC.gif", "bsac large icon" );
    #endif 
#endif


#if defined(MP4_DECODE) || defined(__MMI_PURE_AUDIO__)
    /* video */
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_3GP,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LI3GP.gif", "large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_MP4,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIMP4.gif", "large icon" );
#endif 

#ifdef __MMI_VIDEO_PLAYER__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_AVI,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIAVI.gif", "large icon" );  
#endif

    /* others */
   
#ifdef __J2ME__ 
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_JAD,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIJAD.gif", "jad large icon" );
    
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_JAR,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIJAR.gif", "jar large icon" );
#endif

#ifdef __MMI_VCARD__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_VCF,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIVCF.gif", "vcf large icon" );
#endif
                                                                
#ifdef __MMI_VCALENDAR__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_VCS,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIVCS.gif", "vcs large icon" );
#endif

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_THEME,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LITHM.gif", "theme large icon" );
#endif

#ifdef __MMI_SVG__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_SVG,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LISVG.gif", "SVG icon" );
#endif

#ifdef __MMI_BARCODEREADER__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_MBC,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIMBC.gif", "MBC icon" );
#endif

#ifdef __MMI_EBOOK_READER__ //Rajat
    ADD_APPLICATION_IMAGE2(IMG_EBOOK_FMGR_TXT_LARGE_TYPE,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\EBOOK_TXT.gif", "Text icon" );

    ADD_APPLICATION_IMAGE2(IMG_EBOOK_FMGR_PDB_LARGE_TYPE,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\EBOOK_PDB.gif", "PDB icon" );

    ADD_APPLICATION_IMAGE2(IMG_EBOOK_FMGR_TXT_SMALL_TYPE,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\EBOOK_SMALL_TXT.pbm", "Text icon" );

    ADD_APPLICATION_IMAGE2(IMG_EBOOK_FMGR_PDB_SMALL_TYPE,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\EBOOK_SMALL_PDB.pbm", "PDB icon" );
#endif

#ifdef __MMI_SWFLASH__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_CMP,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LICMP.gif", "cmp large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_VIS,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIVIS.gif", "cmp large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_IVIS,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIIVIS.gif", "cmp large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_ZDD,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIZDD.gif", "cmp large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_KVIS,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIKVIS.gif", "cmp large icon" );

    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_MVIS,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIMVIS.gif", "cmp large icon" );

#endif

#ifdef __MMI_VIDEO_STREAM__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_SDP,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LISDP.gif", "SDP large icon" );    
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_RAM,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIRAM.gif", "RAM large icon" );    
#endif

#if defined(__MMI_BROWSER_2__)
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_HTM,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SIWEB.PBM", "Brower HTML small icon" );    
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_BRW_HTM_LARGE_TYPE,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_HTM.gif", "HTM large icon" );    
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_BRW_HTML_LARGE_TYPE,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_HTML.gif", "HTML large icon" );    
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_BRW_WML_LARGE_TYPE,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_WML.gif", "WML large icon" );    
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_BRW_XHTML_LARGE_TYPE,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_XHTML.gif", "XHTML large icon" );    
#endif

#ifdef __MMI_VBOOKMARK__ 
//    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_ICON_FILE_TYPE_VBOOKMARK,
//      CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LISDP.gif", "SDP small icon" );    
//    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_VBOOKMARK,
//      CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LISDP.gif", "SDP large icon" );    
#endif /* #ifdef __MMI_VBOOKMARK__ */

#ifdef __MMI_VBOOKMARK__ 
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_ICON_FILE_TYPE_VBOOKMARK,
        CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Bookmark\\\\BM_PDefine.pbm", "Vbookmark small icon" );    
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_URL,
        CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Bookmark\\\\BM_URL.pbm", "URL large icon" );    
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_VBM,
        CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Bookmark\\\\BM_VBM.pbm", "VBM large icon" );    
#endif /* __MMI_VBOOKMARK__  */


#ifdef __CERTMAN_SUPPORT__
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_FILE_TYPE_CER,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_SICER.pbm", "cer small icon" );    
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_CER_CER_LARGE_TYPE,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIcer.gif", "cer large icon" );    
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_CER_PFX_LARGE_TYPE,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIpfx.gif", "pfx large icon" );    
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_CER_DER_LARGE_TYPE,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIder.gif", "der large icon" );    
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_CER_PEM_LARGE_TYPE,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIpem.gif", "pem large icon" );    
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_CER_P7B_LARGE_TYPE,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIp7b.gif", "p7b large icon" );    
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_CER_CRT_LARGE_TYPE,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIcrt.gif", "crt large icon" );    
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_CER_SPC_LARGE_TYPE,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIspc.gif", "spc large icon" );    
    ADD_APPLICATION_IMAGE2(IMG_ID_FMGR_CER_P12_LARGE_TYPE,
        CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\FM_LIp12.gif", "p12 large icon" );    

#endif /* #ifdef __CERTMAN_SUPPORT__ */

}

void PopulateFileMgrServStrRes(void)
{
    /************************************************************/
    /*                                                          */
    /*              exif strings                                */
    /*                                                          */
    /************************************************************/

    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_MAKE,              "Make",                 "STR_ID_FMGR_EXIF_MAKE");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_MODEL,             "Model",                "STR_ID_FMGR_EXIF_MODEL");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_ORIENTATION,       "Orientation",          "STR_ID_FMGR_EXIF_ORIENTATION");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_X_RESOLUTION,      "X Resolution",         "STR_ID_FMGR_EXIF_X_RESOLUTION");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_Y_RESOLUTION,      "Y Resolution",         "STR_ID_FMGR_EXIF_Y_RESOLUTION");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_RESOLUTION_UNIT,   "Resolution Unit",      "STR_ID_FMGR_EXIF_RESOLUTION_UNIT");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_SOFTWARE,          "Software",             "STR_ID_FMGR_EXIF_SOFTWARE");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_DATE_TIME,         "Date Time",            "STR_ID_FMGR_EXIF_DATE_TIME");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_YCBCR_POSITIONING, "YCbCr Position",       "STR_ID_FMGR_EXIF_YCBCR_POSITIONING");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_EXIF_IFD,          "EXIF IFD",             "STR_ID_FMGR_EXIF_EXIF_IFD");

    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_EXPOSURE_TIME,     "Exposure Time",        "STR_ID_FMGR_EXIF_EXPOSURE_TIME");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_FNUMBER,           "F Number",             "STR_ID_FMGR_EXIF_FNUMBER");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_EXPOSURE_PROGRAM,  "Exposure Program",     "STR_ID_FMGR_EXIF_EXPOSURE_PROGRAM");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_ISO_SPEED_RATINGS, "ISO Speed Ratings",    "STR_ID_FMGR_EXIF_ISO_SPEED_RATINGS");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_EXIF_VERSION,      "EXIF Version",         "STR_ID_FMGR_EXIF_EXIF_VERSION");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_DATE_TIME_ORIGINAL,"Date Time Original",   "STR_ID_FMGR_EXIF_DATE_TIME_ORIGINAL");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_DATE_TIME_DIGITIZED,"Date Time Digitized", "STR_ID_FMGR_EXIF_DATE_TIME_DIGITIZED");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_COMPONENTS_CONFIG, "Components Config",    "STR_ID_FMGR_EXIF_COMPONENTS_CONFIG");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_EXPOSURE_BIAS_VALUE,"Exposure Bias Value", "STR_ID_FMGR_EXIF_EXPOSURE_BIAS_VALUE");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_METERING_MODE,     "Metering Mode",        "STR_ID_FMGR_EXIF_METERING_MODE");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_LIGHT_SOURCE,      "Light Source",         "STR_ID_FMGR_EXIF_LIGHT_SOURCE");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_FLASH,             "Flash",                "STR_ID_FMGR_EXIF_FLASH");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_MAKER_NOTE,        "Maker Note",           "STR_ID_FMGR_EXIF_MAKER_NOTE");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_FLASHPIX_VERSION,  "Flashpix Version",     "STR_ID_FMGR_EXIF_FLASHPIX_VERSION");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_COLOR_SPACE,       "Color Space",          "STR_ID_FMGR_EXIF_COLOR_SPACE");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_PIXEL_X_DIMENSION, "X Dimension",          "STR_ID_FMGR_EXIF_PIXEL_X_DIMENSION");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_PIXEL_Y_DIMENSION, "Y Dimension",          "STR_ID_FMGR_EXIF_PIXEL_Y_DIMENSION");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_EXPOSURE_MODE,     "Exposure Mode",        "STR_ID_FMGR_EXIF_EXPOSURE_MODE");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_DIGITAL_ZOOM_RATIO,"Digital Zoom Ratio",   "STR_ID_FMGR_EXIF_DIGITAL_ZOOM_RATIO");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_SCENE_CAPTURE_TYPE,"Scene Capture Type",   "STR_ID_FMGR_EXIF_SCENE_CAPTURE_TYPE");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_EXIF_NO_INFORMATION,    "No Information",       "STR_ID_FMGR_EXIF_NO_INFORMATION");    

    ADD_APPLICATION_STRING2(STR_ID_FMGR_FILE_LIMIT_IMAGE_TOO_LARGE, "Image too large\nLimit", "STR_ID_FMGR_FILE_LIMIT_IMAGE_TOO_LARGE" );
    ADD_APPLICATION_STRING2(STR_ID_FMGR_FILE_LIMIT_VIDEO_TOO_LARGE, "Video too large\nLimit", "STR_ID_FMGR_FILE_LIMIT_VIDEO_TOO_LARGE" );
    ADD_APPLICATION_STRING2(STR_ID_FMGR_FILE_LIMIT_VIDEO_TOO_LONG, "Video too long\nLimit", "STR_ID_FMGR_FILE_LIMIT_VIDEO_TOO_LONG" );
    ADD_APPLICATION_STRING2(STR_ID_FMGR_FILE_LIMIT_FILE_TOO_LARGE, "File too large\nLimit", "STR_ID_FMGR_FILE_LIMIT_FILE_TOO_LARGE" );

    ADD_APPLICATION_STRING2(STR_ID_FMGR_IMAGE_TOO_LARGE_NO_DISPLAY, "Image too large\nUnable to decode", "STR_ID_FMGR_IMAGE_TOO_LARGE_NO_DISPLAY" );
    ADD_APPLICATION_STRING2(STR_ID_FMGR_FILE_TOO_LARGE_NO_DISPLAY, "File too large\nUnable to decode", "STR_ID_FMGR_FILE_TOO_LARGE_NO_DISPLAY" );

    
#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__ 
    ADD_APPLICATION_STRING2(STR_FMGR_THEME_OPTION,              "Theme",                "THEME String");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_THEME_INCORRECT_LOCATION,"Theme File Location Incorrect. Do You Want To Move?","THEME warning String");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_ACTIVE_THEME_DELETE,    "Active Theme Cant Be Deleted","THEME Delete warning String");

    ADD_APPLICATION_STRING2(STR_ID_THEME_ERROR_FAILURE,         "Theme Error",          "Theme Error String");
    
    ADD_APPLICATION_STRING2(STR_ID_FMGR_SPACE_NOT_AVAILABLE,    "Full Space",           "Theme space not available");
    ADD_APPLICATION_STRING2(STR_ID_FMGR_MAX_COUNT_REACHED,      "Maximum Count Reached","THEME max count String");
#endif
#ifdef __MMI_THEMES_V2_SUPPORT__ 
    ADD_APPLICATION_STRING2(STR_ID_FMGR_ALREADY_ACTIVE,         "Theme Already Active", "THEME already active String");
#endif

//  ADD_APPLICATION_STRING2(STR_FMGR_VIEW_IMG,                  "View",                 "STR_FMGR_VIEW_IMG");
    ADD_APPLICATION_STRING2(STR_FMGR_VIEW_IMG_JPG_DETAIL,       "Image Info",           "STR_FMGR_VIEW_IMG_JPG_DETAIL");
    ADD_APPLICATION_STRING2(STR_FMGR_PLAY_AUDIO,                "Play",                 "STR_FMGR_PLAY_AUDIO");
    ADD_APPLICATION_STRING2(STR_FMGR_PLAY_VIDEO,                "Play",                 "STR_FMGR_PLAY_VIDEO");
    ADD_APPLICATION_STRING2(STR_FMGR_EXECUTE,                   "Install",              "STR_FMGR_EXECUTE");

    /* Use as */
    ADD_APPLICATION_STRING2(STR_FMGR_WALLPAPER,                 "To Wallpaper",         "STR_FMGR_WALLPAPER" );
    ADD_APPLICATION_STRING2(STR_FMGR_SUB_WALLPAPER,             "To Sub Wallpaper",     "STR_FMGR_SUB_WALLPAPER" );
    ADD_APPLICATION_STRING2(STR_FMGR_SCREENSAVER,               "To Screen Saver",      "STR_FMGR_SCREENSAVER" );
    ADD_APPLICATION_STRING2(STR_FMGR_POWER_ON,                  "To Power On Display",  "STR_FMGR_POWER_ON" );
    ADD_APPLICATION_STRING2(STR_FMGR_POWER_OFF,                 "To Power Off Display", "STR_FMGR_POWER_OFF" ); 
    ADD_APPLICATION_STRING2(STR_FMGR_PHB,                       "To PhoneBook",         "STR_FMGR_PHB" );
    ADD_APPLICATION_STRING2(STR_FMGR_PROFILE,                   "To User Profile",      "STR_FMGR_PROFILE" );
#ifdef __MMI_BG_SOUND_EFFECT__
    ADD_APPLICATION_STRING2(STR_FMGR_BGSOUND,                   "To Backgound Sound",   "STR_FMGR_BGSOUND" );
#endif
    ADD_APPLICATION_STRING2(STR_FMGR_TODOLIST,                  "To To Do List",        "STR_FMGR_TODOLIST" );

    /* Send via */
    ADD_APPLICATION_STRING2(STR_FMGR_SMS,                       "To SMS",               "STR_FMGR_SMS" );
#if (defined( __MMI_MESSAGES_EMS__) && !defined (__MMI_FMGR_NO_FWD_SMS__))
    ADD_APPLICATION_STRING2(STR_FMGR_EMS,                       "To EMS",               "STR_FMGR_EMS" );
#endif
#ifdef __MMI_MMS__
    ADD_APPLICATION_STRING2(STR_FMGR_MMS,                       "To MMS",               "STR_FMGR_MMS");
#ifdef __MMI_MMS_2__
#ifdef __MMI_OP11_MMS_SEND_TO_PHOTO_BLOG__
/* under construction !*/
#endif
#endif
#endif
#ifdef __MMI_EMAIL__
    ADD_APPLICATION_STRING2(STR_FMGR_EMAIL,                     "To Email",             "STR_FMGR_EMAIL" );
#endif
#ifdef __MMI_IRDA_SUPPORT__
    ADD_APPLICATION_STRING2(STR_FMGR_IRDA,                      "To Irda",              "STR_FMGR_IRDA" );
#endif

/* Bluetooth sending API revise */
#if defined(__MMI_BT_SEND_SUPPORT__) || defined(__MMI_BPP_SUPPORT__)
    ADD_APPLICATION_STRING2(STR_FMGR_BT,                        "To Bluetooth",         "STR_FMGR_BT" );
#endif

    /* Print */
#if defined(__MMI_PICT_BRIDGE_SUPPORT__) || defined(__MMI_BPP_SUPPORT__)
    ADD_APPLICATION_STRING2(STR_ID_FMGR_PRINT,                  "Print",                "STR_ID_FMGR_PRINT" );
#endif

#if defined(__MMI_PICT_BRIDGE_SUPPORT__)
    ADD_APPLICATION_STRING2(STR_ID_FMGR_TO_PICTBRIGE,           "To PictBridge",        "STR_ID_FMGR_FORWARD_TO_PICTBRIGE" );
#endif

}

void PopulateFileMgrServiceResource(void)
{
    PopulateFileMgrServImgRes();
    PopulateFileMgrServStrRes();
    PopulateFileMgrServMenuRes();
    
    /*----------------------------------------------------------------*/
    /*  Forward options 
     */
    /* Use as - image / video */
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_FWD_WALLPAPER,       mmi_fmgr_highlight_to_wallpaper);
#ifdef __MMI_SUB_WALLPAPER__		
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_FWD_SUB_WALLPAPER,   mmi_fmgr_highlight_to_sub_wallpaper);
#endif
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_FWD_SCREENSAVER,     mmi_fmgr_highlight_to_screensaver);
#ifdef __MMI_POWER_ON_OFF_DISPLAY__
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_FWD_POWER_ON,        mmi_fmgr_highlight_to_power_on_display);
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_FWD_POWER_OFF,       mmi_fmgr_highlight_to_power_off_display);
#endif
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_FWD_PHB,             mmi_fmgr_highlight_to_phb);
    /* Use as - audio */
#ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_FWD_PROFILE,         mmi_fmgr_highlight_to_profile);
#endif
#ifdef __MMI_BG_SOUND_EFFECT__		
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_FWD_BGSOUND,         mmi_fmgr_highlight_to_bgsound);
#endif
    /* Use as - todolist */
#ifdef __MMI_VCALENDAR__
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_FWD_TODOLIST,        mmi_fmgr_highlight_to_todolist);
#endif
    /* Send via */
#if !defined (__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_FWD_SMS,             mmi_fmgr_highlight_to_sms);
#endif
#if (defined( __MMI_MESSAGES_EMS__) && !defined (__MMI_FMGR_NO_FWD_SMS__))
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_FWD_EMS,             mmi_fmgr_highlight_to_ems);
#endif
#ifdef __MMI_MMS__
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_FWD_MMS,             mmi_fmgr_highlight_to_mms);
#ifdef __MMI_MMS_2__
#ifdef __MMI_OP11_MMS_SEND_TO_PHOTO_BLOG__
/* under construction !*/
#endif
#endif
#endif
#ifdef __MMI_EMAIL__
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_FWD_EMAIL,           mmi_fmgr_highlight_to_email);
#endif
#ifdef __MMI_IRDA_SUPPORT__
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_FWD_IRDA,            mmi_fmgr_highlight_to_irda);
#endif
/* Bluetooth sending API revise */
#ifdef __MMI_BT_SEND_SUPPORT__
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_FWD_BT,              mmi_fmgr_highlight_to_bt);
#endif

    /*----------------------------------------------------------------*/
    /*  Image option
     */
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_IMG_OPTION_VIEW,      mmi_fmgr_highlight_image_view);
#ifdef __MMI_PHOTOEDITOR__
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_IMG_OPTION_EDIT,      mmi_fmgr_highlight_image_edit);
#endif
#ifdef __MMI_EXIF__
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_IMG_OPTION_JPG_DETAIL, mmi_fmgr_highlight_image_jpg_detail);
#endif 

#if defined(__MMI_PICT_BRIDGE_SUPPORT__) || defined(__MMI_BPP_SUPPORT__)
    /* Print options */
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_IMG_OPTION_PRINT,     mmi_fmgr_highlight_image_print);
#ifdef __MMI_PICT_BRIDGE_SUPPORT__
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_PRINT_PICTBRIGE,      mmi_fmgr_highlight_image_print_to_pictbridge);
#endif
#ifdef __MMI_BPP_SUPPORT__
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_PRINT_BLUETOOTH,      mmi_fmgr_highlight_image_print_to_bluetooth);
#endif
#endif /* defined(__MMI_PICT_BRIDGE_SUPPORT__) || defined(__MMI_BPP_SUPPORT__) */

    /*----------------------------------------------------------------*/
    /*  Other option
     */
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_AUD_OPTION_PLAY,      mmi_fmgr_highlight_audio_play);
#ifdef __MMI_VIDEO_PLAYER__
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_VID_OPTION_PLAY,      mmi_fmgr_highlight_video_play);
#endif
#ifdef __J2ME__
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_JAVA_OPTION_EXECUTE,  mmi_fmgr_highlight_java_execute);
#endif

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_THEME_ACTIVATE,       mmi_fmgr_highlight_theme_activate);
//    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_THEME_DELETE,        mmi_fmgr_highlight_theme_delete); // TODO: not necessary
#endif

#ifdef __MMI_EBOOK_READER__
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_EBOOK_OPTION_OPEN,    mmi_fmgr_highlight_ebook_open);
#endif 
#ifdef __CERTMAN_SUPPORT__
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_FMGR_CER_OPTION_INSTALL,      mmi_certman_highlight_install);
#endif
#if defined(__MMI_BROWSER_2__)
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_BOOKMARK_FILE_OPEN,   mmi_fmgr_highlight_bookmark_goto);
#endif

/* Vogins Start */
#ifdef __VRE__
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_VRE_FILE_OPEN,    mmi_fmgr_highlight_vre_open);
#endif 
/* Vogins End */

#ifdef __MMI_SWFLASH__
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_SWFLASH_OPTION_PLAY,       mmi_fmgr_highlight_swflash_play);
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_SWFLASH_OPTION_INFO,       mmi_fmgr_highlight_swflash_info);
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_SWFLASH_OPTION_DOWNLOAD,   mmi_fmgr_highlight_swflash_download);
#endif
#ifdef __MMI_VBOOKMARK__
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_VBOOKMARK_OPTION_GOTO, mmi_fmgr_highlight_vbookmark_goto);
    ADD_APPLICATION_MENUITEM_HILITE_HANDLER(MENU_ID_FMGR_VBOOKMARK_OPTION_OPEN, mmi_fmgr_highlight_vbookmark_open);
#endif
    
}

#endif /* __MMI_FILE_MANAGER__ */


