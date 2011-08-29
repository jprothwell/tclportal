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
 * MainMenuDef.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for main menu defination 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**********************************************************************************
   Filename:      mainmenu_def.h
   Author:        
   Date Created:  September-07-2002
   Contains:      Main menu application
**********************************************************************************/

#ifndef MAINMENUDEF_H
#define MAINMENUDEF_H

#include "MMI_features.h"

#define MAX_MAIN_MENU_ITEMS                  20
#define MAIN_MENU_SCREENID             (MAIN_MENU_BASE+1)

/* Main menu string IDs */
#define MAIN_MENU_PHONEBOOK_TEXT          (PHONE_BOOK_BASE+0)
#define MAIN_MENU_MESSAGES_TEXT              (MESSAGES_BASE+0)
#define MAIN_MENU_FUNANDGAMES_TEXT           (FUN_GAMES_BASE+0)
#define MAIN_MENU_ORGANIZER_TEXT          (ORGANIZER_BASE+0)
#define MAIN_MENU_SETTINGS_TEXT              (SETTINGS_BASE+0)
#define MAIN_MENU_CONNECT_TEXT               (CONNECTS_BASE+0)
#define MAIN_MENU_SHORTCUTS_TEXT          (SHORTCUTS_BASE+0)
#define MAIN_MENU_SERVICES_TEXT              (SERVICES_BASE+0)
#define MAIN_MENU_CALL_HISTORY_TEXT          (CALL_HISTORY + 0)
#define MAIN_MENU_PROFILES_TEXT              (PROFILES_BASE+0)
#define MAIN_MENU_MONWAP_TEXT             (MONWAP_BASE + 0)
#define MAIN_MENU_CUST_SERVICE_TEXT       (CUSTOMER_SERVICE_BASE + 0)
#define MAIN_MENU_MY_FAVORITE_TEXT        (MY_FAVORITE_BASE + 0)
#define MAIN_MENU_OP_SERVICE_TEXT         (MOBILE_SERVICE_BASE + 0)
/* Vogins Start */
#ifdef __MMI_VRE_MAIN_MENU__
#define STR_VRE_TITLE                (VRE_BASE + 0)
#endif
/* Vogins End */

/* Max 0224 */
#define MAIN_MENU_FILE_MNGR_TEXT          (FILE_MANAGER_BASE+0)
#define MAIN_MENU_MMEDIA_TEXT             (MMEDIA_BASE+0)
/* Main menu image IDs     */

enum MAIN_MENU_TEXT_ID
{
    MAIN_MENU_TITLE_TEXT = MAIN_MENU_BASE + 1,
    MAIN_MENU_MENU_TEXT,
    MAIN_MENU_AVZONE_TEXT,
    MAIN_MENU_PIM_TEXT,
    MAIN_MENU_ENTERTAINMENT_TEXT,
    MAIN_MENU_SYSTEM_TEXT,
    MAIN_MENU_CAMERA_TEXT,
    MAIN_MENU_VDOREC_TEXT,
    MAIN_MENU_VDOPLY_TEXT,
    MAIN_MENU_AUDPLY_TEXT,
    MAIN_MENU_CAMCO_TEXT
};

#ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__

enum MAIN_MENU_IMG_ID
{
    IMG_SUBLCD_SYSTEM_SHUTDOWN = MAIN_MENU_BASE + 1,

    IMG_MAIN_MENU_BG,
    MAIN_MENU_TITLE_ICON,
#ifdef __MMI_MATRIX_MAIN_MENU_FULL_BACKGROUND__
    MAIN_MENU_MATRIX_SOFTKEY_BG,    /* 030705 Calvin add */
#endif 

    MAIN_MENU_MATRIX_ICON_IMGBASE,
    MAIN_MENU_MATRIX_PHONEBOOK_ICON,
    MAIN_MENU_MATRIX_MESSAGES_ICON,
/* Vogins Start */
#ifdef __MMI_VRE_MAIN_MENU__
    MAIN_MENU_MATRIX_VRE_ICON,
#endif
/* Vogins End */
    MAIN_MENU_MATRIX_FUNANDGAMES_ICON,
    MAIN_MENU_MATRIX_ORGANIZER_ICON,
    MAIN_MENU_MATRIX_SETTINGS_ICON,
    MAIN_MENU_MATRIX_PROFILES_ICON,
    MAIN_MENU_MATRIX_SHORTCUTS_ICON,
    MAIN_MENU_MATRIX_SERVICES_ICON,
    MAIN_MENU_MATRIX_CALL_HISTORY_ICON,
    MAIN_MENU_MATRIX_MULTIMEDIA_ICON,
    MAIN_MENU_MATRIX_FILEMNGR_ICON,
    MAIN_MENU_MATRIX_EXTRA_ICON,
    MAIN_MENU_MATRIX_MESSAGE_CLUB_ICON,
    MAIN_MENU_MATRIX_MULTICAMERA_ICON,
    MAIN_MENU_MATRIX_CAMERA_ICON,
    MAIN_MENU_MATRIX_ICON_IMGBASE_MAX,

    MAIN_MENU_MATRIX_ICON_ANI_IMGBASE,
    MAIN_MENU_MATRIX_PHONEBOOK_ANIMATION,
    MAIN_MENU_MATRIX_MESSAGES_ANIMATION,
/* Vogins Start */
#ifdef __MMI_VRE_MAIN_MENU__
    MAIN_MENU_MATRIX_VRE_ANIMATION,
#endif
/* Vogins End */
    MAIN_MENU_MATRIX_FUNANDGAMES_ANIMATION,
    MAIN_MENU_MATRIX_ORGANIZER_ANIMATION,
    MAIN_MENU_MATRIX_SETTINGS_ANIMATION,
    MAIN_MENU_MATRIX_PROFILES_ANIMATION,
    MAIN_MENU_MATRIX_SHORTCUTS_ANIMATION,
    MAIN_MENU_MATRIX_SERVICES_ANIMATION,
    MAIN_MENU_MATRIX_CALL_HISTORY_ANIMATION,
    MAIN_MENU_MATRIX_MULTIMEDIA_ANIMATION,
    MAIN_MENU_MATRIX_FILEMNGR_ANIMATION,
    MAIN_MENU_MATRIX_EXTRA_ANIMATION,
    MAIN_MENU_MATRIX_MESSAGE_CLUB_ANIMATION,
    MAIN_MENU_MATRIX_MULTICAMERA_ANIMATION,
    MAIN_MENU_MATRIX_CAMERA_ANIMATION,
    MAIN_MENU_MATRIX_ICON_ANI_IMGBASE_MAX,

    MAIN_MENU_PAGE_ICON_IMGBASE,
    MAIN_MENU_PAGE_PHONEBOOK_ICON,
    MAIN_MENU_PAGE_MESSAGES_ICON,
    MAIN_MENU_PAGE_FUNANDGAMES_ICON,
    MAIN_MENU_PAGE_ORGANIZER_ICON,
    MAIN_MENU_PAGE_SETTINGS_ICON,
    MAIN_MENU_PAGE_PROFILES_ICON,
    MAIN_MENU_PAGE_SHORTCUTS_ICON,
    MAIN_MENU_PAGE_SERVICES_ICON,
    MAIN_MENU_PAGE_CALL_HISTORY_ICON,
    MAIN_MENU_PAGE_MULTIMEDIA_ICON,
    MAIN_MENU_PAGE_FILEMNGR_ICON,
    MAIN_MENU_PAGE_EXTRA_ICON,
    MAIN_MENU_PAGE_ICON_IMGBASE_MAX,

    MAIN_MENU_LIST_ICON_IMGBASE,
    MAIN_MENU_LIST_PHONEBOOK_ICON,
    MAIN_MENU_LIST_MESSAGES_ICON,
    MAIN_MENU_LIST_FUNANDGAMES_ICON,
    MAIN_MENU_LIST_ORGANIZER_ICON,
    MAIN_MENU_LIST_SETTINGS_ICON,
    MAIN_MENU_LIST_PROFILES_ICON,
    MAIN_MENU_LIST_SHORTCUTS_ICON,
    MAIN_MENU_LIST_SERVICES_ICON,
    MAIN_MENU_LIST_CALL_HISTORY_ICON,
    MAIN_MENU_LIST_MULTIMEDIA_ICON,
    MAIN_MENU_LIST_FILEMNGR_ICON,
    MAIN_MENU_LIST_EXTRA_ICON,
    MAIN_MENU_LIST_ICON_IMGBASE_MAX,

    MAIN_MENU_CIRCULAR_ICON_IMGBASE,
    MAIN_MENU_CIRCULAR_PHONEBOOK_ICON,
    MAIN_MENU_CIRCULAR_MESSAGES_ICON,
    MAIN_MENU_CIRCULAR_FUNANDGAMES_ICON,
    MAIN_MENU_CIRCULAR_ORGANIZER_ICON,
    MAIN_MENU_CIRCULAR_SETTINGS_ICON,
    MAIN_MENU_CIRCULAR_PROFILES_ICON,
    MAIN_MENU_CIRCULAR_SHORTCUTS_ICON,
    MAIN_MENU_CIRCULAR_SERVICES_ICON,
    MAIN_MENU_CIRCULAR_CALL_HISTORY_ICON,
    MAIN_MENU_CIRCULAR_MULTIMEDIA_ICON,
    MAIN_MENU_CIRCULAR_FILEMNGR_ICON,
    MAIN_MENU_CIRCULAR_EXTRA_ICON,
    MAIN_MENU_CIRCULAR_ICON_IMGBASE_MAX,

    /* ////////ROTATE Main Menu////////////// */
    MAIN_MENU_ROTATE_ICON_IMGBASE,
    MAIN_MENU_ROTATE_PHONEBOOK_ICON,
    MAIN_MENU_ROTATE_MESSAGES_ICON,
    MAIN_MENU_ROTATE_FUNANDGAMES_ICON,
    MAIN_MENU_ROTATE_ORGANIZER_ICON,
    MAIN_MENU_ROTATE_SETTINGS_ICON,
    MAIN_MENU_ROTATE_PROFILES_ICON,
    MAIN_MENU_ROTATE_SHORTCUTS_ICON,
    MAIN_MENU_ROTATE_SERVICES_ICON,
    MAIN_MENU_ROTATE_CALL_HISTORY_ICON,
    MAIN_MENU_ROTATE_MULTIMEDIA_ICON,
    MAIN_MENU_ROTATE_FILEMNGR_ICON,
    MAIN_MENU_ROTATE_EXTRA_ICON,
    MAIN_MENU_ROTATE_ICON_IMGBASE_MAX,

    //PMT NEERAJ START 20050616     
    //////////TAB Main Menu//////////////
    MAIN_MENU_TAB_ICON_IMGBASE,
    MAIN_MENU_TAB_PHONEBOOK_ICON,
    MAIN_MENU_TAB_MESSAGES_ICON,
    MAIN_MENU_TAB_FUNANDGAMES_ICON,
    MAIN_MENU_TAB_ORGANIZER_ICON,
    MAIN_MENU_TAB_SETTINGS_ICON,
    MAIN_MENU_TAB_PROFILES_ICON,
    MAIN_MENU_TAB_SHORTCUTS_ICON,
    MAIN_MENU_TAB_SERVICES_ICON,
    MAIN_MENU_TAB_CALL_HISTORY_ICON,
    MAIN_MENU_TAB_MULTIMEDIA_ICON,
    MAIN_MENU_TAB_FILEMNGR_ICON,
    MAIN_MENU_TAB_EXTRA_ICON,
    MAIN_MENU_TAB_ICON_IMGBASE_MAX,
    //PMT NEERAJ END 20050616
    ////////////////////////////////////
    /* Default Icon is Matrix */
    MAIN_MENU_ICON_IMGBASE,
    MAIN_MENU_PHONEBOOK_ICON,
    MAIN_MENU_MESSAGES_ICON,
/* Vogins Start */
#ifdef __MMI_VRE_MAIN_MENU__
    MAIN_MENU_VRE_ICON,
#endif
/* Vogins End */
    MAIN_MENU_FUNANDGAMES_ICON,
    MAIN_MENU_ORGANIZER_ICON,
    MAIN_MENU_SETTINGS_ICON,
    MAIN_MENU_PROFILES_ICON,
    MAIN_MENU_SHORTCUTS_ICON,
    MAIN_MENU_SERVICES_ICON,
    MAIN_MENU_CALL_HISTORY_ICON,
    MAIN_MENU_MULTIMEDIA_ICON,
    MAIN_MENU_FILEMNGR_ICON,
    MAIN_MENU_EXTRA_ICON,
    MAIN_MENU_MESSAGE_CLUB_ICON,
    MAIN_MENU_MULTICAMERA_ICON,
    MAIN_MENU_CAMERA_ICON,
#ifdef __MMI_MY_FAVORITE__
/* under construction !*/
#endif


#ifdef __MMI_OP01_MENU_9MATRIX__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP01_MENU_9MATRIX__ */

    MAIN_MENU_ICON_IMGBASE_MAX,

    MAIN_MENU_ICON_ANI_IMGBASE,
    MAIN_MENU_PHONEBOOK_ANIMATION,
    MAIN_MENU_MESSAGES_ANIMATION,
/* Vogins Start */
#ifdef __MMI_VRE_MAIN_MENU__
    MAIN_MENU_VRE_ANIMATION,
#endif
/* Vogins End */
    MAIN_MENU_FUNANDGAMES_ANIMATION,
    MAIN_MENU_ORGANIZER_ANIMATION,
    MAIN_MENU_SETTINGS_ANIMATION,
    MAIN_MENU_PROFILES_ANIMATION,
    MAIN_MENU_SHORTCUTS_ANIMATION,
    MAIN_MENU_SERVICES_ANIMATION,
    MAIN_MENU_CALL_HISTORY_ANIMATION,
    MAIN_MENU_MULTIMEDIA_ANIMATION,
    MAIN_MENU_FILEMNGR_ANIMATION,
    MAIN_MENU_EXTRA_ANIMATION,
    MAIN_MENU_MESSAGE_CLUB_ANIMATION,
    MAIN_MENU_MULTICAMERA_ANIMATION,
    MAIN_MENU_CAMERA_ANIMATION,

#ifdef __MMI_MY_FAVORITE__
/* under construction !*/
#endif

#ifdef __MMI_OP01_MENU_9MATRIX__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP01_MENU_9MATRIX__ */

    MAIN_MENU_ICON_ANI_IMGBASE_MAX,

    MAIN_MENU_BG_IMAGE_BASE,
    MAIN_MENU_PHONEBOOK_BG_IMAGE,
    MAIN_MENU_MESSAGES_BG_IMAGE,
    MAIN_MENU_CALL_HISTORY_BG_IMAGE,
    MAIN_MENU_SETTINGS_BG_IMAGE,
    MAIN_MENU_FUNANDGAMES_BG_IMAGE,
    MAIN_MENU_PROFILES_BG_IMAGE,
    MAIN_MENU_ORGANIZER_BG_IMAGE,
    MAIN_MENU_SERVICES_BG_IMAGE,
    MAIN_MENU_SHORTCUTS_BG_IMAGE,

    MAIN_MENU_TITLE_ICON_BASE,
    MAIN_MENU_TITLE_PHONEBOOK_ICON,
    MAIN_MENU_TITLE_MESSAGES_ICON,
/* Vogins Start */
#ifdef __MMI_VRE_MAIN_MENU__
    MAIN_MENU_TITLE_VRE_ICON,
#endif
/* Vogins End */
    MAIN_MENU_TITLE_FUNANDGAMES_ICON,
    MAIN_MENU_TITLE_ORGANIZER_ICON,
    MAIN_MENU_TITLE_SETTINGS_ICON,
    MAIN_MENU_TITLE_PROFILES_ICON,
    MAIN_MENU_TITLE_SHORTCUTS_ICON,
    MAIN_MENU_TITLE_SERVICES_ICON,
    MAIN_MENU_TITLE_CALL_HISTORY_ICON,
    MAIN_MENU_TITLE_MULTIMEDIA_ICON,
    MAIN_MENU_TITLE_FILE_MNGR_ICON,
    MAIN_MENU_TITLE_EXTRA_APP_ICON,
    MAIN_MENU_TITLE_MESSAGE_CLUB_ICON,
    MAIN_MENU_TITLE_MULTICAMERA_ICON,
    MAIN_MENU_TITLE_CAMERA_ICON,
#ifdef __MMI_MY_FAVORITE__
/* under construction !*/
#endif

#ifdef __MMI_OP01_MENU_9MATRIX__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP01_MENU_9MATRIX__ */

    MAIN_MENU_TITLE_EMPTY_ICON,
    IMG_MAIN_MENU_PAGE_BG,
    IMG_MAIN_MENU_CIRCULAR_BG,
    IMG_MAIN_MENU_MATRIX_BG,//082806 240x320 matrix
    MAIN_MENU_MATRIX_TITLE_BG,
    MAIN_MENU_PAGE_TITLE_BG,
    MAIN_MENU_LIST_TITLE_BG
#if defined(__MMI_MAINLCD_240X400__)
    ,
    MAIN_MENU_CONTROLAREA_IMAGE_BASE,
    MAIN_MENU_CONTROLAREA_PHONEBOOK_ICON,
    MAIN_MENU_CONTROLAREA_MESSAGES_ICON,
    MAIN_MENU_CONTROLAREA_FUNANDGAMES_ICON,
    MAIN_MENU_CONTROLAREA_ORGANIZER_ICON,
    MAIN_MENU_CONTROLAREA_SETTINGS_ICON,
    MAIN_MENU_CONTROLAREA_PROFILES_ICON,
    MAIN_MENU_CONTROLAREA_SHORTCUTS_ICON,
    MAIN_MENU_CONTROLAREA_SERVICES_ICON,
    MAIN_MENU_CONTROLAREA_CALL_HISTORY_ICON,
    MAIN_MENU_CONTROLAREA_MULTIMEDIA_ICON,
    MAIN_MENU_CONTROLAREA_FILE_MNGR_ICON,
    MAIN_MENU_CONTROLAREA_EXTRA_APP_ICON,
    MAIN_MENU_CONTROLAREA_MESSAGE_CLUB_ICON
#endif
};

#else /* __MMI_MAINMENU_STYLE_CHANGE_EN__ */ 
/********************************************************
Note : __MMI_BI_DEGREE_MAIN_MENU_STYLE__ shall be enabled 
   only when __MMI_MAINMENU_STYLE_CHANGE_EN__ is disabled 
********************************************************/
enum MAIN_MENU_IMG_ID
{
    IMG_SUBLCD_SYSTEM_SHUTDOWN = MAIN_MENU_BASE + 1,

    IMG_MAIN_MENU_BG,
    MAIN_MENU_TITLE_ICON,
#ifdef __MMI_MATRIX_MAIN_MENU_FULL_BACKGROUND__
    MAIN_MENU_MATRIX_SOFTKEY_BG,    /* 030705 Calvin add */
#endif 

#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
    MAIN_MENU_AVZONE_ICON,
    MAIN_MENU_AVZONE_ICON_SELECTED,
    MAIN_MENU_AVZONE_TITLE,
    MAIN_MENU_PIM_ICON,
    MAIN_MENU_PIM_ICON_SELECTED,
    MAIN_MENU_ENTERTAINMENT_ICON,
    MAIN_MENU_ENTERTAINMENT_ICON_SELECTED,
    MAIN_MENU_SYSTEM_ICON,
    MAIN_MENU_SYSTEM_ICON_SELECTED,
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 
    MAIN_MENU_ICON_IMGBASE,
    MAIN_MENU_PHONEBOOK_ICON,
    MAIN_MENU_MESSAGES_ICON,
/* Vogins Start */
#ifdef __MMI_VRE_MAIN_MENU__
    MAIN_MENU_VRE_ICON,
#endif
/* Vogins End */
    MAIN_MENU_FUNANDGAMES_ICON,
    MAIN_MENU_ORGANIZER_ICON,
    MAIN_MENU_SETTINGS_ICON,
    MAIN_MENU_PROFILES_ICON,
    MAIN_MENU_SHORTCUTS_ICON,
    MAIN_MENU_SERVICES_ICON,
    MAIN_MENU_CALL_HISTORY_ICON,
    MAIN_MENU_MULTIMEDIA_ICON,
    MAIN_MENU_FILEMNGR_ICON,
    MAIN_MENU_EXTRA_ICON,
    MAIN_MENU_MESSAGE_CLUB_ICON,
    MAIN_MENU_MULTICAMERA_ICON,
    MAIN_MENU_CAMERA_ICON,
#ifdef __MMI_MY_FAVORITE__
/* under construction !*/
#endif


#ifdef __MMI_OP01_MENU_9MATRIX__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP01_MENU_9MATRIX__ */

#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
    MAIN_MENU_VDOREC_ICON,
    MAIN_MENU_VDOPLY_ICON,
    MAIN_MENU_AUDPLY_ICON,
    MAIN_MENU_CAMCO_ICON,
    MAIN_MENU_IMGVIEW_ICON,    
    MAIN_MENU_SNDREC_ICON,
    MAIN_MENU_BT_ICON,
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 

    MAIN_MENU_TITLE_ICON_BASE,
    MAIN_MENU_TITLE_PHONEBOOK_ICON,
    MAIN_MENU_TITLE_MESSAGES_ICON,
/* Vogins Start */
#ifdef __MMI_VRE_MAIN_MENU__
    MAIN_MENU_TITLE_VRE_ICON,
#endif
/* Vogins End */
    MAIN_MENU_TITLE_FUNANDGAMES_ICON,
    MAIN_MENU_TITLE_ORGANIZER_ICON,
    MAIN_MENU_TITLE_SETTINGS_ICON,
    MAIN_MENU_TITLE_PROFILES_ICON,
    MAIN_MENU_TITLE_SHORTCUTS_ICON,
    MAIN_MENU_TITLE_SERVICES_ICON,
    MAIN_MENU_TITLE_CALL_HISTORY_ICON,
    MAIN_MENU_TITLE_MULTIMEDIA_ICON,
    MAIN_MENU_TITLE_FILE_MNGR_ICON,
    MAIN_MENU_TITLE_EXTRA_APP_ICON,
    MAIN_MENU_TITLE_MESSAGE_CLUB_ICON,
    MAIN_MENU_TITLE_MULTICAMERA_ICON,
    MAIN_MENU_TITLE_CAMERA_ICON,

#ifdef __MMI_MY_FAVORITE__
/* under construction !*/
#endif

#ifdef __MMI_OP01_MENU_9MATRIX__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP01_MENU_9MATRIX__ */

#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
    MAIN_MENU_TITLE_VDOREC_ICON,
    MAIN_MENU_TITLE_VDOPLY_ICON,
    MAIN_MENU_TITLE_AUDPLY_ICON,
    MAIN_MENU_TITLE_CAMCO_ICON,
    MAIN_MENU_TITLE_IMGVIEW_ICON,    
    MAIN_MENU_TITLE_SNDREC_ICON,
    MAIN_MENU_TITLE_BT_ICON,
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 

    MAIN_MENU_BG_IMAGE_BASE,
    MAIN_MENU_PHONEBOOK_BG_IMAGE,
    MAIN_MENU_MESSAGES_BG_IMAGE,
    MAIN_MENU_CALL_HISTORY_BG_IMAGE,
    MAIN_MENU_SETTINGS_BG_IMAGE,
    MAIN_MENU_FUNANDGAMES_BG_IMAGE,
    MAIN_MENU_PROFILES_BG_IMAGE,
    MAIN_MENU_ORGANIZER_BG_IMAGE,
    MAIN_MENU_SERVICES_BG_IMAGE,
    MAIN_MENU_SHORTCUTS_BG_IMAGE,

    MAIN_MENU_ICON_ANI_IMGBASE,
    MAIN_MENU_PHONEBOOK_ANIMATION,
    MAIN_MENU_MESSAGES_ANIMATION,
/* Vogins Start */
#ifdef __MMI_VRE_MAIN_MENU__
    MAIN_MENU_VRE_ANIMATION,
#endif
/* Vogins End */
    MAIN_MENU_FUNANDGAMES_ANIMATION,
    MAIN_MENU_ORGANIZER_ANIMATION,
    MAIN_MENU_SETTINGS_ANIMATION,
    MAIN_MENU_PROFILES_ANIMATION,
    MAIN_MENU_SHORTCUTS_ANIMATION,
    MAIN_MENU_SERVICES_ANIMATION,
    MAIN_MENU_CALL_HISTORY_ANIMATION,
    MAIN_MENU_MULTIMEDIA_ANIMATION,
    MAIN_MENU_FILEMNGR_ANIMATION,
    MAIN_MENU_EXTRA_ANIMATION,
    MAIN_MENU_MESSAGE_CLUB_ANIMATION,
    MAIN_MENU_MULTICAMERA_ANIMATION,
    MAIN_MENU_CAMERA_ANIMATION,
#ifdef __MMI_MY_FAVORITE__
/* under construction !*/
#endif

#ifdef __MMI_OP01_MENU_9MATRIX__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP01_MENU_9MATRIX__ */

    MAIN_MENU_ICON_ANI_IMGBASE_MAX
        /* 070505 Calvin Start */
        , MAIN_MENU_MATRIX_TITLE_BG,
    MAIN_MENU_PAGE_TITLE_BG,
    MAIN_MENU_LIST_TITLE_BG,
        /* 070505 Calvin End */
    MAIN_MENU_TITLE_EMPTY_ICON,
    IMG_MAIN_MENU_PAGE_BG,
    IMG_MAIN_MENU_MATRIX_BG//082806 240x320 matrix
#if defined(__MMI_MAINLCD_240X400__)
    ,
    MAIN_MENU_CONTROLAREA_IMAGE_BASE,
    MAIN_MENU_CONTROLAREA_PHONEBOOK_ICON,
    MAIN_MENU_CONTROLAREA_MESSAGES_ICON,
    MAIN_MENU_CONTROLAREA_FUNANDGAMES_ICON,
    MAIN_MENU_CONTROLAREA_ORGANIZER_ICON,
    MAIN_MENU_CONTROLAREA_SETTINGS_ICON,
    MAIN_MENU_CONTROLAREA_PROFILES_ICON,
    MAIN_MENU_CONTROLAREA_SHORTCUTS_ICON,
    MAIN_MENU_CONTROLAREA_SERVICES_ICON,
    MAIN_MENU_CONTROLAREA_CALL_HISTORY_ICON,
    MAIN_MENU_CONTROLAREA_MULTIMEDIA_ICON,
    MAIN_MENU_CONTROLAREA_FILE_MNGR_ICON,
    MAIN_MENU_CONTROLAREA_EXTRA_APP_ICON,
    MAIN_MENU_CONTROLAREA_MESSAGE_CLUB_ICON
#endif
};

#endif /* __MMI_MAINMENU_STYLE_CHANGE_EN__ */ 

#ifdef __MMI_SUBLCD_MASTER_MODE__
#define SUB_MAIN_MENU_SCREENID             (MAIN_MENU_BASE+1)
typedef enum
{
#if defined(__MMI_AUDIO_PLAYER__)
    MMI_SUB_MAIN_ENUM_AUDPLY,
#endif
			
#if defined(__MMI_FM_RADIO__)
    MMI_SUB_MAIN_ENUM_FMRADIO,
#endif

    MMI_SUB_MAIN_ENUM_TOTAL
} mmi_sub_main_menu_enum;
#endif /*__MMI_SUBLCD_MASTER_MODE__*/


#endif /* MAINMENUDEF_H */ 

