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
 * mainmenu.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for main menu
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
   Filename:      mainmenu.c
   Author:        manju, Vijay Vaidya
   Date Created:  September-07-2002
   Contains:      Main menu application
**********************************************************************************/
#include "MMI_include.h"

#include "AllAppGprot.h"
#include "mmiappfnptrs.h"
#include "PhoneBookDef.h"
#include "MainMenuDef.h"
#include "MainMenuProt.h"
#include "MiscFunctions.h"
#include "UserProfilesResDef.h"
#include "SettingGprots.h"
#include "FunAndGamesDefs.h"
#include "FunAndGamesProts.h"
#include "ExtraDef.h"
#include "CallHistoryMain.h"
#include "SettingDefs.h"
#include "SimDetectionGexdcl.h"
#include "SimDetectionGprot.h"
#include "MessagesExDcl.h"
#include "CommonScreens.h"
#include "IdleAppProt.h"
#include "IdleHomescreenGprot.h"

#include "Service.h"
#ifdef __SAT__
#include "SATGProts.h"
#endif 
#ifdef __MMI_FILE_MANAGER__
#include "FileMgr.h"
#endif 
#ifndef __DISABLE_SHORTCUTS_MENU__
#include "ShortcutsProts.h"
#endif 

#include "FunandGamesProts.h"
#include "wgui_status_icons.h"
#include "MainMenudef.h"
#include "ManageCallMain.h"
#include "IdleAppDef.h"

#include "CallSetUpEnum.h"

#include "OrganizerGProt.h"
#include "OrganizerDef.h"
#include "SettingProt.h"

#ifdef __MMI_MOBILE_SERVICE__
/* under construction !*/
#endif

#ifdef __MMI_CUSTOMER_SERVICE__
/* under construction !*/
#endif

#ifdef __MMI_MY_FAVORITE__
/* under construction !*/
#endif

#ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__
#include "gui_custom_menus.h"
#ifdef __MMI_WGUI_MINI_TAB_BAR__
#include "wgui_tab_bars.h"
#endif 

extern U8 PhnsetGetMainMenuStyle(void);
#endif /* __MMI_MAINMENU_STYLE_CHANGE_EN__ */ 

#if (defined(__MMI_IRDA_SUPPORT__) || defined(__MMI_USB_SUPPORT__) || defined(__MMI_BT_SUPPORT__))
#include "ExtDeviceDefs.h"
#endif 
#ifdef  __MMI_DUAL_SIM_MASTER__
#include "MTPNP_AD_master_header.h"
#endif  /*  __MMI_DUAL_SIM_MASTER__ */

#if defined (__MMI_MAINLCD_240X400__) && !defined(__MMI_BI_DEGREE_MAIN_MENU_STYLE__)
#define __MMI_MATRIX_MAIN_MENU_NO_TITLEBAR__
#endif

#ifdef __MMI_SUBLCD_MASTER_MODE__
#endif


extern void EntryIdleScreen(void);

extern void mmi_profiles_entry_main_screen(void);
extern void mmi_phb_reset_scr_id(void);

#ifdef __SAT__
extern void GoToSATMainMenu(void);
#endif

extern U16 gMainMenuTitleIcon[];

extern S32 main_menu_index;
extern S32 MMI_main_menu_type;
extern UI_3D_circular_menu wgui_CM3D_menu;

#ifdef __MMI_UI_DALMATIAN_SOFTKEYS__
extern void shuffle_draw_white(void);
#endif 

#if defined(__MMI_FM_RADIO__) && defined(__MMI_FM_RADIO_CHECK_CHIP_OR_HIDE__)
extern void mmi_fmrdo_skip_highlight_hdlr(S32 index);   /* defined in FMRadioSrc.c */
extern U16 mmi_fmrdo_check_chip_or_hide(U16 n_items, U16 *string_ids, U16 *icon_ids); /* defined in FMRadioSrc.c */
#endif /* defined(__MMI_FM_RADIO__) && defined(__MMI_FM_RADIO_CHECK_CHIP_OR_HIDE__) */ 

#ifdef WAP_SUPPORT
extern void goto_mobile_suite_screen(void);
#endif

#ifdef __MMI_UCM__
extern void mmi_ucm_entry_call_center(void);
#endif /* __MMI_UCM__ */


/*****************************************************************************
 * FUNCTION
 *  handle_mainmenu_right_softkey_up
 * DESCRIPTION
 *  Go to previous screen when rt soft key
 *  is released
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void handle_mainmenu_right_softkey_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_profiles
 * DESCRIPTION
 *  Associate the key handler
 *  with left and rt soft key
 *  
 *  AUTHOR            :Ashima
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_profiles(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_profiles_entry_main_screen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(handle_mainmenu_right_softkey_up, KEY_EVENT_UP);

#ifdef __MMI_OP01_MENU_9MATRIX__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __MMI_OP01_MENU_9MATRIX__ */
    if (GetActiveScreenId() == SCR_SIM_OPTION)
    {
        SetKeyHandler(mmi_profiles_entry_main_screen, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    }
#endif /* __MMI_OP01_MENU_9MATRIX__ */

}


/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_phonebook
 * DESCRIPTION
 *  Associate the key handler
 *  with left and rt soft key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_phonebook(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_phb_entry_main_menu, KEY_EVENT_UP);
    SetRightSoftkeyFunction(handle_mainmenu_right_softkey_up, KEY_EVENT_UP);

    if (GetActiveScreenId() == SCR_SIM_OPTION)
    {
        SetKeyHandler(mmi_phb_entry_main_menu, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_messages
 * DESCRIPTION
 *  Associate the key handler
 *  with left and rt soft key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_messages(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

#ifdef __MOD_SMSAL__
    SetLeftSoftkeyFunction(EntryScrMessagesMenuList, KEY_EVENT_UP);     /* sms-code */
#endif 
    SetRightSoftkeyFunction(handle_mainmenu_right_softkey_up, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_funandgames
 * DESCRIPTION
 *  Associate the key handler
 *  with left and rt soft key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_funandgames(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_fng_entry_screen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(handle_mainmenu_right_softkey_up, KEY_EVENT_UP);

    if (GetActiveScreenId() == SCR_SIM_OPTION)
    {
        SetKeyHandler(mmi_fng_entry_screen, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    }
}
/* Vogins Start */
#ifdef __MMI_VRE_MAIN_MENU__
void mmi_vre_start(void);

void highlight_mainmenu_vre(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_vre_start, KEY_EVENT_UP);
    SetRightSoftkeyFunction(handle_mainmenu_right_softkey_up, KEY_EVENT_UP);

    if (GetActiveScreenId() == SCR_SIM_OPTION)
    {
        SetKeyHandler(mmi_vre_start, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    }
}
#endif
/* Vogins End */
/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_organizer
 * DESCRIPTION
 *  Associate the key handler
 *  with left and rt soft key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_organizer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(EntryOrganizer, KEY_EVENT_UP);
    SetRightSoftkeyFunction(handle_mainmenu_right_softkey_up, KEY_EVENT_UP);

    if (GetActiveScreenId() == SCR_SIM_OPTION)
    {
        SetKeyHandler(EntryOrganizer, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_settings
 * DESCRIPTION
 *  Associate the key handler
 *  with left and rt soft key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    /* micha0420 */
    SetLeftSoftkeyFunction(EntryScrSettingMenu, KEY_EVENT_UP);
    SetRightSoftkeyFunction(handle_mainmenu_right_softkey_up, KEY_EVENT_UP);

    if (GetActiveScreenId() == SCR_SIM_OPTION)
    {
        SetKeyHandler(EntryScrSettingMenu, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    }
}

#ifdef __MMI_MESSAGES_CLUB__


/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_msgclub
 * DESCRIPTION
 *  Associate the key handler
 *  with left and rt soft key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_msgclub(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

#ifdef __MOD_SMSAL__
    SetLeftSoftkeyFunction(mmi_msg_club_entry_level_1, KEY_EVENT_UP);   /* sms-code */
#endif 
    SetRightSoftkeyFunction(handle_mainmenu_right_softkey_up, KEY_EVENT_UP);
}
#endif /* __MMI_MESSAGES_CLUB__ */ 


/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_shortcuts
 * DESCRIPTION
 *  Associate the key handler
 *  with left and rt soft key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __DISABLE_SHORTCUTS_MENU__
void highlight_mainmenu_shortcuts(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(EntryShctInMainMenu, KEY_EVENT_UP);
    SetRightSoftkeyFunction(handle_mainmenu_right_softkey_up, KEY_EVENT_UP);
#ifdef __MMI_OP11_MENU_12MATRIX__
/* under construction !*/
/* under construction !*/
#endif

#if defined(__MMI_VERSION_2__)
    if (GetActiveScreenId() == SCR_SIM_OPTION)
    {
        SetKeyHandler(EntryShctInMainMenu, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    }
#else
    SetKeyHandler(EntryShctInMainMenu, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

#endif /* defined(__MMI_VERSION_2__) */
}
#endif /* __DISABLE_SHORTCUTS_MENU__ */ 


/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_services
 * DESCRIPTION
 *  Associate the key handler
 *  with left and rt soft key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_services(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    /* micha1223 */
#ifdef __MMI_MERGE_SAT_TO_MAINMENU__
    /* micha1217 */
#ifndef WAP_SUPPORT
    /* micha0601 */
    if (IsSATPresent())
    {
        SetLeftSoftkeyFunction(GoToSATMainMenu, KEY_EVENT_UP);
    }
    else
    {
        SetLeftSoftkeyFunction(GoToServicesMenu, KEY_EVENT_UP);
    }
#else /* WAP_SUPPORT */ 
    SetLeftSoftkeyFunction(GoToServicesMenu, KEY_EVENT_UP);
#endif /* WAP_SUPPORT */ 

#else /* __MMI_MERGE_SAT_TO_MAINMENU__ */ 

    SetLeftSoftkeyFunction(GoToServicesMenu, KEY_EVENT_UP);

#endif /* __MMI_MERGE_SAT_TO_MAINMENU__ */ 

    SetRightSoftkeyFunction(handle_mainmenu_right_softkey_up, KEY_EVENT_UP);
}

#if defined(__MMI_OP01_MENU_9MATRIX__) && defined(WAP_SUPPORT)
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
#ifdef WAP_SUPPORT
/* under construction !*/
#else
/* under construction !*/
#endif /* WAP_SUPPORT */ 
/* under construction !*/
#endif /* __MMI_OP01_MENU_9MATRIX__ & WAP_SUPPORT */

#ifdef __MMI_CUSTOMER_SERVICE__
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
#endif /* __MMI_CUSTOMER_SERVICE__ */

#ifdef __MMI_MOBILE_SERVICE__
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
#endif /* __MMI_MOBILE_SERVICE__ */

#ifdef __MMI_MY_FAVORITE__
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
#endif /* __MMI_MY_FAVORITE__ */

#ifdef __MMI_OP01_MENU_NOSIM_LIST__
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
#endif /* __MMI_OP01_MENU_NOSIM_LIST__ */


/*****************************************************************************
 * FUNCTION
 *  initalize_main_menu_application
 * DESCRIPTION
 *  Set all highlte handler for main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void initalize_main_menu_application(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if !defined(__MTK_TARGET__) 
    S32 n_items, HighlightMenu, write_len;
    FS_HANDLE bmp_file_handle;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_highlight_handler();
    initialize_mainmenu_title_icons();
#if defined(__MMI_MAINLCD_240X400__)
    initialize_mainmenu_controlarea_image();
#endif
#if !defined(__MTK_TARGET__) 
    n_items = GetNumOfChild_Ext(IDLE_SCREEN_MENU_ID);
    bmp_file_handle = FS_Open((WCHAR*)L"C:\\defaultindex", FS_CREATE_ALWAYS);
    HighlightMenu = 0;
#ifdef __MMI_DEFAULT_MAIN_MENU_HIGHLIGHT_CENTER__
#ifdef __MMI_MAINLCD_320X240__
    if ((n_items / 4) % 2)
    {
        HighlightMenu = (n_items - 1) >> 1;
    }
    else
    {
        HighlightMenu = (n_items - 1 - 4) >> 1;
    }
#else
    if (((n_items + 2)/ 3) % 2)
    {
        HighlightMenu = ((((n_items + 2)/ 3) * 3) - 1) >> 1;
    }
    else
    {
        HighlightMenu = ((((n_items + 2)/ 3) * 3) - 1 - 3) >> 1;
    }
#endif
#endif
#ifdef __MMI_DEFAULT_MAIN_MENU_HIGHLIGHT_MESSAGE__
    HighlightMenu = (U8)GetChildMenuIDIndexByParentMenuID(IDLE_SCREEN_MENU_ID, MAIN_MENU_MESSAGES_MENUID);
#endif /* __MMI_DEFAULT_MAIN_MENU_HIGHLIGHT_MESSAGE__ */ 
    FS_Write(bmp_file_handle, (void*)&HighlightMenu, sizeof(S32), &write_len);
    FS_Close(bmp_file_handle);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  main_menu_shortcut_executer
 * DESCRIPTION
 *  Shortcut handler to main menu
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void main_menu_shortcut_executer(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 n_items = GetNumOfChild_Ext(IDLE_SCREEN_MENU_ID);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * When matrix item number > 9, the menu shortcut will fail when going
     * to an invalid index. See fixed_matrix_goto_item().
     */
    if (((MMI_current_menu_type == MATRIX_MENU) || (MMI_current_menu_type == MATRIX_PAGE_MENU) )&&
        (MMI_fixed_matrix_menu.last_highlighted_item == -2))
    {
        return;
    }
    if ((MMI_current_menu_type == LIST_MENU) || (MMI_current_menu_type == PAGE_MENU) )
    {
        return;
    }
    
    if (index >= 0 && index < n_items)
    {
        execute_left_softkey_function(KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  main_menu_custom_highlight_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void main_menu_custom_highlight_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined (__MMI_MAINLCD_240X400__) 
    dm_coordinates gui_control_area_get_coordinates;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_DALMATIAN_SOFTKEYS__
    gdi_layer_lock_frame_buffer();
#endif 

    ExecuteCurrHiliteHandler_Ext(index);

#ifdef __MMI_UI_DALMATIAN_SOFTKEYS__
    gdi_layer_unlock_frame_buffer();
    gui_BLT_double_buffer(0, UI_device_height - MMI_BUTTON_BAR_HEIGHT, UI_device_width - 1, UI_device_height - 1);
#endif /* __MMI_UI_DALMATIAN_SOFTKEYS__ */ 

#ifndef __MMI_MATRIX_MAIN_MENU_NO_TITLEBAR__    /* 030705 Calvin added */
    if (MMI_main_menu_type != ROTATE_MENU && MMI_main_menu_type != CIRCULAR_3D_MENU)    /* 113004 Calvin added if check */
    {
    #ifndef __MMI_MATRIX_MAIN_MENU_NO_TITLEBAR_ICON__
        ChangeTitleIcon((U16) gMainMenuTitleIcon[index]);
    #endif /* __MMI_MATRIX_MAIN_MENU_NO_TITLEBAR_ICON__ */

        draw_title();
    }
#endif /* __MMI_MATRIX_MAIN_MENU_NO_TITLEBAR__ */ 

    main_menu_index = index;
#if defined (__MMI_MAINLCD_240X400__) 
    if (MMI_main_menu_type == MATRIX_PAGE_MENU)
    {
        dm_get_control_coordinates_from_category(
            -1,
            MMI_CATEGORY14_MATRIX_PAGE_ID,
            DM_CATEGORY_CONTROLLED_AREA,
            -1,
            &gui_control_area_get_coordinates);
        category14_redraw_controlarea_callback(&gui_control_area_get_coordinates);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  EntryMainMenuFromIdleScreen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryMainMenuFromIdleScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_KEYPAD_LOCK_PATTERN_2__
    g_idle_context.ToMainMenuScrFromIdleApp = 1;
#endif 

#if defined(__MMI_KEYPAD_LOCK_PATTERN_1__) && defined(__MMI_OP11_HOMESCREEN__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    goto_main_menu();
}

#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
extern void ShowCategory414Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                U16 *list_of_items,
                U16 *list_of_icons,
                U16 *list_of_icons2,
                U16 *list_of_menuitem_id,
                S32 flags,
                S32 highlighted_item,
                U8 *history_buffer);


/*****************************************************************************
 * FUNCTION
 *  list_matrix_main_menu_highlight_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void list_matrix_main_menu_highlight_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 n_items;
    U16 nMenuItemList[MAX_SUB_MENUS];

    MMI_ID_TYPE mm_stringIDs[MAX_SUB_MENUS];
    MMI_ID_TYPE mm_iconIDs[MAX_SUB_MENUS];
    U8 *history_buffer;
    list_matrix_menu_category_history *h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetSequenceItemIds(IDLE_SCREEN_MENU_ID, nMenuItemList);
    if (nMenuItemList[index] == MAIN_MENU_FILE_MNGR_MENUID)
    {
        return;
    }
    history_buffer = GetCurrGuiBuffer(MAIN_MENU_SCREENID);
    GetSequenceStringIds_Ext(nMenuItemList[index], mm_stringIDs);
    GetSequenceImageIds_Ext(nMenuItemList[index], mm_iconIDs);
    SetParentHandler(nMenuItemList[index]);
    n_items = GetNumOfChild_Ext(nMenuItemList[index]);
    MMI_matrix_highlight_handler = ExecuteCurrHiliteHandler;
    ChangeTitleString((U8*) GetString(GetStringIdOfItem(nMenuItemList[index])));
    MMI_title_icon = NULL;
    draw_title();
    if (history_buffer != NULL)
    {
        h = (list_matrix_menu_category_history*) history_buffer;
        ShowCat414Matrix(n_items, mm_stringIDs, mm_iconIDs, MATRIX_MENU, 0, &(h->matrix_menu_history));
    }
    else
    {
        ShowCat414Matrix(n_items, mm_stringIDs, mm_iconIDs, MATRIX_MENU, 0, NULL);
    }
}
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 

#ifdef __MMI_WGUI_MINI_TAB_BAR__
extern U16 *GetSeqItems(U16 ParentItemId);
#endif 


#ifdef __MMI_MOTION_MAINMENU__
/*****************************************************************************
 * FUNCTION
 *  mmi_mainmenu_swflash_enter_app
 * DESCRIPTION
 *  Enter submenu from main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mainmenu_swflash_enter_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item = GetCategory14MotionHighlightItem();
    ExecuteCurrHiliteHandler(item);
    execute_left_softkey_function(KEY_EVENT_UP);
}
#endif /* __MMI_MOTION_MAINMENU__ */


/*****************************************************************************
 * FUNCTION
 *  goto_main_menu
 * DESCRIPTION
 *  Display the main menu.
 *  
 *  This a entry function for the main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void goto_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MMI_ID_TYPE mm_stringIDs[MAX_MAIN_MENU_ITEMS];
    MMI_ID_TYPE mm_iconIDs[MAX_MAIN_MENU_ITEMS];

#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
    MMI_ID_TYPE mm_iconID2[MAX_MAIN_MENU_ITEMS];
    U16 nMenuItemList[MAX_SUB_MENUS];
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 
    U8 *history_buffer;
    S32 n_items;
    S32 attributes;
    U8 HighlightMenu = 0;
    MMI_ID_TYPE *iconList;

#ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__
    U8 menu_style = 0;
    MMI_ID_TYPE mm_iconIDs_display[MAX_MAIN_MENU_ITEMS];
    U8 i = 0;
#endif /* __MMI_MAINMENU_STYLE_CHANGE_EN__ */ 

#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
    U8 j = 0;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_reset_scr_id();

    EntryNewScreen(MAIN_MENU_SCREENID, exit_main_menu, NULL, MMI_FULL_SCREEN);

    history_buffer = GetCurrGuiBuffer(MAIN_MENU_SCREENID);
    n_items = GetNumOfChild_Ext(IDLE_SCREEN_MENU_ID);
    GetSequenceStringIds_Ext(IDLE_SCREEN_MENU_ID, mm_stringIDs);
    GetSequenceImageIds_Ext(IDLE_SCREEN_MENU_ID, mm_iconIDs);
    SetParentHandler(IDLE_SCREEN_MENU_ID);
    attributes = GetDispAttributeOfItem(IDLE_SCREEN_MENU_ID);

#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
    GetSequenceItemIds(IDLE_SCREEN_MENU_ID, nMenuItemList);
#endif 
    /* MTK Leo add, for mini_tab_bar */
#ifdef __MMI_WGUI_MINI_TAB_BAR__
    wgui_setup_mini_tab_bar(
        MMI_content_x,
        MMI_content_y,
        MMI_content_width,
        20,
        UI_COLOR_BLACK,
        UI_COLOR_RED,
        UI_COLOR_GREY,
        9 /* n_items */ ,
        GetSeqItems(IDLE_SCREEN_MENU_ID),
        NULL);
    wgui_mini_tab_bar_set_flag_on(0x00000002 /* WGUI_MINI_TAB_BAR_IN_PARENT */ );
#endif /* __MMI_WGUI_MINI_TAB_BAR__ */ 
    /* MTK Leo end */

    /* RegisterHighlightHandler(main_menu_custom_highlight_handler); */

#ifdef __MMI_DEFAULT_MAIN_MENU_HIGHLIGHT_MESSAGE__
    /* Specify the highlight item to the message */
    HighlightMenu = (U8)GetChildMenuIDIndexByParentMenuID(IDLE_SCREEN_MENU_ID, MAIN_MENU_MESSAGES_MENUID);
#endif /* __MMI_DEFAULT_MAIN_MENU_HIGHLIGHT_MESSAGE__ */ 

#ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__
    menu_style = PhnsetGetMainMenuStyle();
    switch (menu_style)
    {
    #ifdef __MMI_MAINMENU_MATRIX_SUPPORT__  /* 071705 Calvin added */
        case PHNSET_MAINMENU_STYLE_MATRIX:
#if defined (__MMI_MAINLCD_240X400__)
            attributes = MATRIX_PAGE_MENU;
#else
            attributes = MATRIX_MENU;
#endif

#ifndef __MMI_DEFAULT_MAIN_MENU_HIGHLIGHT_MESSAGE__
#ifdef __MMI_DEFAULT_MAIN_MENU_HIGHLIGHT_CENTER__
#ifdef __MMI_MAINLCD_320X240__
            if ((n_items / 4) % 2)
            {
                HighlightMenu = (n_items - 1) >> 1;
            }
            else
            {
                HighlightMenu = (n_items - 1 - 4) >> 1;
            }
#else
            if (((n_items + 2)/ 3) % 2)
            {
                HighlightMenu = ((((n_items + 2)/ 3) * 3) - 1) >> 1;
            }
            else
            {
                HighlightMenu = ((((n_items + 2)/ 3) * 3) - 1 - 3) >> 1;
            }
#endif
#endif /* __MMI_DEFAULT_MAIN_MENU_HIGHLIGHT_CENTER__ */ 
#endif /* __MMI_DEFAULT_MAIN_MENU_HIGHLIGHT_MESSAGE__ */ 
            for (i = 0; i < (MAIN_MENU_MATRIX_ICON_IMGBASE_MAX - MAIN_MENU_MATRIX_ICON_IMGBASE); i++)
            {
                /* U16 a = mm_iconIDs[i];
                   U16 b = MAIN_MENU_ICON_IMGBASE;
                   U16 c = MAIN_MENU_MATRIX_ICON_IMGBASE;
                   U16 d = ( mm_iconIDs[i] -MAIN_MENU_ICON_IMGBASE  );
                   U16 e = MAIN_MENU_MATRIX_ICON_IMGBASE+( mm_iconIDs[i] -MAIN_MENU_ICON_IMGBASE  );
                   printf( "%d %d %d %d %d ", a, b, c, d, e ); */
                mm_iconIDs_display[i] = MAIN_MENU_MATRIX_ICON_IMGBASE + (mm_iconIDs[i] - MAIN_MENU_ICON_IMGBASE);
            }
            iconList = mm_iconIDs_display;
            break;
    #endif /* __MMI_MAINMENU_MATRIX_SUPPORT__ */ 

        #ifdef __MMI_MAINMENU_PAGE_SUPPORT__    /* 071705 Calvin added */
        case PHNSET_MAINMENU_STYLE_PAGE:
            attributes = PAGE_MENU;
            for (i = 0; i < (MAIN_MENU_PAGE_ICON_IMGBASE_MAX - MAIN_MENU_PAGE_ICON_IMGBASE); i++)
            {
                mm_iconIDs_display[i] = MAIN_MENU_PAGE_ICON_IMGBASE + (mm_iconIDs[i] - MAIN_MENU_ICON_IMGBASE);
            }
            iconList = mm_iconIDs_display;
            break;
        #endif /* __MMI_MAINMENU_PAGE_SUPPORT__ */ 

        #ifdef __MMI_MAINMENU_LIST_SUPPORT__    /* 071705 Calvin added */
        case PHNSET_MAINMENU_STYLE_LIST:
            attributes = LIST_MENU;
            for (i = 0; i < (MAIN_MENU_LIST_ICON_IMGBASE_MAX - MAIN_MENU_LIST_ICON_IMGBASE); i++)
            {
                mm_iconIDs_display[i] = MAIN_MENU_LIST_ICON_IMGBASE + (mm_iconIDs[i] - MAIN_MENU_ICON_IMGBASE);
            }
            iconList = mm_iconIDs_display;
            break;
        #endif /* __MMI_MAINMENU_LIST_SUPPORT__ */ 

        #ifdef __MMI_MAINMENU_CIRCULAR_SUPPORT__        /* 071705 Calvin modified */
        case PHNSET_MAINMENU_STYLE_CIRCULE:
            attributes = CIRCULAR_3D_MENU;
            for (i = 0; i < (MAIN_MENU_CIRCULAR_ICON_IMGBASE_MAX - MAIN_MENU_CIRCULAR_ICON_IMGBASE); i++)
            {
                mm_iconIDs_display[i] = MAIN_MENU_CIRCULAR_ICON_IMGBASE + (mm_iconIDs[i] - MAIN_MENU_ICON_IMGBASE);
            }
            iconList = mm_iconIDs_display;
            break;
        #endif /* __MMI_MAINMENU_CIRCULAR_SUPPORT__ */ 

        #ifdef __MMI_MAINMENU_ROTATE_SUPPORT__
        case PHNSET_MAINMENU_STYLE_ROTATE:
            attributes = ROTATE_MENU;
            for (i = 0; i < (MAIN_MENU_ROTATE_ICON_IMGBASE_MAX - MAIN_MENU_ROTATE_ICON_IMGBASE); i++)
            {
                mm_iconIDs_display[i] = MAIN_MENU_ROTATE_ICON_IMGBASE + (mm_iconIDs[i] - MAIN_MENU_ICON_IMGBASE);
            }
            iconList = mm_iconIDs_display;
            break;
        #endif /* __MMI_MAINMENU_ROTATE_SUPPORT__ */ 

        #ifdef __MMI_MOTION_MAINMENU__
        case PHNSET_MAINMENU_STYLE_MOTION:
        {
            attributes = MOTION_MENU;
        }
        #endif /* __MMI_MOTION_MAINMENU__ */
        default:
            iconList = mm_iconIDs;
            break;
    }
#else /* __MMI_MAINMENU_STYLE_CHANGE_EN__ */ 
    iconList = mm_iconIDs;
#endif /* __MMI_MAINMENU_STYLE_CHANGE_EN__ */ 
    /* 113004 Calvin removed if-else check */
    /*
     * if((attributes==CIRCULAR_3D_MENU)||(attributes==ROTATE_MENU))
     * RegisterHighlightHandler(ExecuteCurrHiliteHandler_Ext); //MTK JL add no key clear hilite
     * else
     * RegisterHighlightHandler(main_menu_custom_highlight_handler);
     */
#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
    RegisterHighlightHandler(list_matrix_main_menu_highlight_handler);
#else 
    RegisterHighlightHandler(main_menu_custom_highlight_handler);
#endif 
    /* Calvin end */
    /* PMT VIKAS START 20050707 */
#ifdef __MMI_UI_DALMATIAN_SOFTKEYS__
    gui_register_button_shuffle(shuffle_draw_white);
#endif 
    /* PMT VIKAS END 20050707 */
#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
    for (j = 0; j < 4; j++)
    {
        mm_iconID2[j] = mm_iconIDs[j] + 1;
    }
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 

#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
    ShowCategory414Screen(
        MAIN_MENU_TITLE_TEXT,
        MAIN_MENU_TITLE_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        n_items,
        mm_stringIDs,
        iconList,
        mm_iconID2,
        nMenuItemList,
        attributes,
        HighlightMenu,
        (U8*) history_buffer);
#else /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 
    ShowCategory14Screen(
        MAIN_MENU_TITLE_TEXT,
        MAIN_MENU_TITLE_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        n_items,
        mm_stringIDs,
        iconList,
        attributes,
        HighlightMenu,
        (U8*) history_buffer);
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 

#ifdef __MMI_MOTION_MAINMENU__
    if (attributes == MOTION_MENU)
    {
        SetCategoryMotionEnterApp(mmi_mainmenu_swflash_enter_app);
    }
#endif /* __MMI_MOTION_MAINMENU__ */

#if (defined(__MMI_KEYPAD_LOCK_PATTERN_2__) && !defined(__MMI_DISABLE_KEYPAD_LOCK__))
    if (g_idle_context.ToMainMenuScrFromIdleApp == 1)
    {
        StartTimer(KEYPAD_LOCK_TIMER, KEYPAD_LOCK_TIMEOUT, IdleHandleKeypadLockProcess);
        SetKeyHandler(IdleHandlePoundKeyForKeypadLock, KEY_STAR, KEY_EVENT_UP);
    }
#endif /* (defined(__MMI_KEYPAD_LOCK_PATTERN_2__) && !defined(__MMI_DISABLE_KEYPAD_LOCK__)) */ 

#if !defined(__MMI_DISABLE_KEYPAD_LOCK__) && defined(__MMI_KEYPAD_LOCK_PATTERN_1__) && defined(__MMI_OP11_HOMESCREEN__)
    if (g_idle_context.RskPressedFromIdleApp == 1 && mmi_hs_is_enable())
    {
        StartTimer(KEYPAD_LOCK_TIMER, KEYPAD_LOCK_TIMEOUT, IdleHandleKeypadLockProcess);
        SetKeyHandler(IdleHandlePoundKeyForKeypadLock, KEY_POUND, KEY_EVENT_UP);
    }
#endif /* !defined(__MMI_DISABLE_KEYPAD_LOCK__) && defined(__MMI_KEYPAD_LOCK_PATTERN_1__) && defined(__MMI_OP11_HOMESCREEN__) */

    register_menu_shortcut_selected(main_menu_shortcut_executer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
#ifdef __MMI_MOTION_MAINMENU__
    /* SWFlash main menu */
    if (attributes == MOTION_MENU)
    {
        SetLeftSoftkeyFunction(mmi_mainmenu_swflash_enter_app, KEY_EVENT_UP);
    }
#endif /*  __MMI_MOTION_MAINMENU__ */
}


/*****************************************************************************
 * FUNCTION
 *  exit_main_menu
 * DESCRIPTION
 *  Store the  snap shot
 *  before displaying next screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void exit_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history main_menu_history;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) main_menu_history.inputBuffer, (S8*) & nHistory);
    main_menu_history.scrnID = MAIN_MENU_SCREENID;
    main_menu_history.entryFuncPtr = goto_main_menu;
    GetCategoryHistory(main_menu_history.guiBuffer);
    AddHistory(main_menu_history);
#ifdef __MMI_WGUI_MINI_TAB_BAR__
    wgui_mini_tab_bar_set_flag_off(WGUI_MINI_TAB_BAR_IN_PARENT);
#endif 
#ifdef __MMI_KEYPAD_LOCK_PATTERN_2__    /* Robin 1223 */
    g_idle_context.ToMainMenuScrFromIdleApp = 0;
#endif 

    /* unhide possible hidden menus in order to keep compatibility to other screens */
    mmi_frm_unhide_menu_item(MAIN_MENU_EXTRA_MENUID);
    mmi_frm_unhide_menu_item(MAIN_MENU_MULTIMEDIA_MENUID);
    mmi_frm_unhide_menu_item(MAIN_MENU_FUNANDGAMES_MENUID);

    /* Re-initialize title icons since the MM category modifies gMainMenuTitleIcon[]. */
    // TODO: If items are different in selectable MMs, GetRootTitleIcon() may go wrong.
    initialize_mainmenu_title_icons();
}


#ifdef __MMI_UCM__
/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_callcenter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_callcenter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(mmi_ucm_entry_call_center, KEY_EVENT_UP);
    SetRightSoftkeyFunction(handle_mainmenu_right_softkey_up, KEY_EVENT_UP);

}

#endif /* __MMI_UCM__ */

/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_callhistory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_callhistory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(EntryCHISTMainMenu, KEY_EVENT_UP);
    SetRightSoftkeyFunction(handle_mainmenu_right_softkey_up, KEY_EVENT_UP);
}



#ifdef __MMI_OP11_MENU_12MATRIX__
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
#ifdef __MMI_OP01_MENU_9MATRIX__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __MMI_OP01_MENU_9MATRIX__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP01_MENU_9MATRIX__ */
/* under construction !*/
/* under construction !*/
#endif
/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_multimedia
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_multimedia(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(EntryMainMultimedia, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	
#ifdef __MMI_OP01_MENU_9MATRIX__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef WAP_SUPPORT
/* under construction !*/
#endif
#else /* __MMI_OP01_MENU_9MATRIX__ */
    if (GetActiveScreenId() == SCR_SIM_OPTION)
    {
        SetKeyHandler(EntryMainMultimedia, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    }
#endif /* __MMI_OP01_MENU_9MATRIX__ */
}

#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__


/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_avzone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_avzone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(EntryMainAVZone, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    if (GetActiveScreenId() == SCR_SIM_OPTION)
    {
        SetKeyHandler(EntryMainAVZone, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    }
}
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 


/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_filemngr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_filemngr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

#ifdef __MMI_FILE_MANAGER__
    SetLeftSoftkeyFunction(mmi_fmgr_launch, KEY_EVENT_UP);

#if defined(__MMI_VERSION_2__)
    if (GetActiveScreenId() == SCR_SIM_OPTION)
    {
        SetKeyHandler(mmi_fmgr_launch, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    }
    
#ifdef __MMI_OP11_MENU_12MATRIX__
/* under construction !*/
#endif
#else /* defined(__MMI_VERSION_2__) */ 
    SetKeyHandler(mmi_fmgr_launch, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
#endif /* defined(__MMI_VERSION_2__) */ 

#else /* __MMI_FILE_MANAGER__ */ 

    SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#endif /* __MMI_FILE_MANAGER__ */ 
}


#if defined(__MMI_VERSION_2__) || defined(__MMI_OP01_MENU_9MATRIX__) || defined(__MMI_OP01_MENU_NOSIM_LIST__)

/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_extra
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_extra(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    SetLeftSoftkeyFunction(EntryMainExtra, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

#ifdef __MMI_OP01_MENU_9MATRIX__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __MMI_OP01_MENU_9MATRIX__ */
    if (GetActiveScreenId() == SCR_SIM_OPTION)
    {
        SetKeyHandler(EntryMainExtra, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    }
#endif /* __MMI_OP01_MENU_9MATRIX__ */	
}
#endif /* defined(__MMI_VERSION_2__) || defined(__MMI_OP01_MENU_9MATRIX__) || defined(__MMI_OP01_MENU_NOSIM_LIST__) */ 

/* Max: temporary define here, shall be moved to each application file */
#define SCR_FILE_MANAGER   FILE_MANAGER_BASE
#define SCR_MMEDIA         MMEDIA_BASE
#define SCR_CAMERA         MMEDIA_BASE + 2 
#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
#define  SCR_AVZONE        MMEDIA_BASE+1
#endif 

#ifdef __MMI_OP01_MENU_NOSIM_LIST__
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
#if defined(__MMI_PHB_CALLER_RES_SETTING__)
/* under construction !*/
#if !defined( __MMI_DUAL_SIM_MASTER__)
/* under construction !*/
#else   /*  __MMI_DUAL_SIM_MASTER__ */
/* under construction !*/
#endif  /*  __MMI_DUAL_SIM_MASTER__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_PHB_CALLER_RES_SETTING__) */ 
/* under construction !*/
#if defined(__MMI_FM_RADIO__) && defined(__MMI_FM_RADIO_CHECK_CHIP_OR_HIDE__)
/* under construction !*/
/* under construction !*/
#else /* defined(__MMI_FM_RADIO__) && defined(__MMI_FM_RADIO_CHECK_CHIP_OR_HIDE__) */ 
/* under construction !*/
#endif /* defined(__MMI_FM_RADIO__) && defined(__MMI_FM_RADIO_CHECK_CHIP_OR_HIDE__) */ 
/* under construction !*/
#ifdef __MMI_WGUI_MINI_TAB_BAR__
/* under construction !*/
#endif 
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
#endif /* __MMI_OP01_MENU_NOSIM_LIST__ */

/*****************************************************************************
 * FUNCTION
 *  EntryMainMultimedia
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryMainMultimedia(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[MAX_SUB_MENUS];
    U16 ItemIcons[MAX_SUB_MENUS];
    U16 nItems;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_MMEDIA, NULL, EntryMainMultimedia, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_MMEDIA);
    nItems = GetNumOfChild_Ext(MAIN_MENU_MULTIMEDIA_MENUID);
    GetSequenceStringIds_Ext(MAIN_MENU_MULTIMEDIA_MENUID, ItemList);
    GetSequenceImageIds_Ext(MAIN_MENU_MULTIMEDIA_MENUID, ItemIcons);
    SetParentHandler(MAIN_MENU_MULTIMEDIA_MENUID);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

#if defined(__MMI_PHB_CALLER_RES_SETTING__)
    /* No SIM, remove caller picture menu items */
#if !defined(__MMI_DUAL_SIM_MASTER__)
    if (mmi_bootup_is_sim_valid() == MMI_FALSE)
#else   /*  __MMI_DUAL_SIM_MASTER__ */
    if (mmi_bootup_is_sim_valid() == MMI_FALSE && MTPNP_PFAL_Is_Card2Absent())
#endif  /*  __MMI_DUAL_SIM_MASTER__ */
    {
        S32 MenuItemId;

        MenuItemId = GetChildMenuIDIndexByParentMenuID(MAIN_MENU_MULTIMEDIA_MENUID, MENU_ID_PHB_CALLER_PIC_1);
        if (MenuItemId != -1)   /* Menu Exists. */
        {
            nItems -= 1;
        }
    }
#endif /* defined(__MMI_PHB_CALLER_RES_SETTING__) */ 

#if defined(__MMI_FM_RADIO__) && defined(__MMI_FM_RADIO_CHECK_CHIP_OR_HIDE__)
    RegisterHighlightHandler(mmi_fmrdo_skip_highlight_hdlr);
    nItems = mmi_fmrdo_check_chip_or_hide(nItems, ItemList, ItemIcons);
#else /* defined(__MMI_FM_RADIO__) && defined(__MMI_FM_RADIO_CHECK_CHIP_OR_HIDE__) */ 
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
#endif /* defined(__MMI_FM_RADIO__) && defined(__MMI_FM_RADIO_CHECK_CHIP_OR_HIDE__) */ 
    /* MTK Leo add, mini_tab_bar */
#ifdef __MMI_WGUI_MINI_TAB_BAR__
    wgui_enable_mini_tab_bar(MAIN_MENU_MULTIMEDIA_MENUID);
#endif 
    /* MTK Leo end */

    ShowCategory52Screen(
        MAIN_MENU_MMEDIA_TEXT,
        GetRootTitleIcon(MAIN_MENU_MULTIMEDIA_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        ItemIcons,
        0,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


#ifdef __MMI_OP11_MENU_12MATRIX__
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
#if defined(__MMI_PHB_CALLER_RES_SETTING__)
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
#endif /* defined(__MMI_PHB_CALLER_RES_SETTING__) */ 
/* under construction !*/
#if defined(__MMI_FM_RADIO__) && defined(__MMI_FM_RADIO_CHECK_CHIP_OR_HIDE__)
/* under construction !*/
/* under construction !*/
#else /* defined(__MMI_FM_RADIO__) && defined(__MMI_FM_RADIO_CHECK_CHIP_OR_HIDE__) */ 
/* under construction !*/
#endif /* defined(__MMI_FM_RADIO__) && defined(__MMI_FM_RADIO_CHECK_CHIP_OR_HIDE__) */ 
/* under construction !*/
#ifdef __MMI_WGUI_MINI_TAB_BAR__
/* under construction !*/
#endif 
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

/*****************************************************************************
 * FUNCTION
 *  EntryMainFileMngr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryMainFileMngr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* shall be implemented later */
}


/*****************************************************************************
 * FUNCTION
 *  ExitMainFileMngr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitMainFileMngr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* shall be implemented later */
}


#if defined(__MMI_VERSION_2__) || defined(__MMI_OP01_MENU_9MATRIX__) || defined(__MMI_OP01_MENU_NOSIM_LIST__)
/*****************************************************************************
 * FUNCTION
 *  EntryMainExtra
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryMainExtra(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[MAX_SUB_MENUS];
    U16 ItemIcons[MAX_SUB_MENUS];
    U16 nItems;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_EXTRA, NULL, EntryMainExtra, NULL);
#ifdef  __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    guiBuffer = GetCurrGuiBuffer(SCR_EXTRA);
    nItems = GetNumOfChild_Ext(MAIN_MENU_EXTRA_MENUID);
    GetSequenceStringIds_Ext(MAIN_MENU_EXTRA_MENUID, ItemList);
    GetSequenceImageIds_Ext(MAIN_MENU_EXTRA_MENUID, ItemIcons);
    SetParentHandler(MAIN_MENU_EXTRA_MENUID);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        MAIN_MENU_EXTRA_TEXT,
        GetRootTitleIcon(MAIN_MENU_EXTRA_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        ItemIcons,
        0,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

#endif /* defined(__MMI_VERSION_2__) || defined(__MMI_OP01_MENU_9MATRIX__) || defined(__MMI_OP01_MENU_NOSIM_LIST__) */

#if defined(__MMI_VERSION_2__)

#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__

/*****************************************************************************
 * FUNCTION
 *  EntryMainAVZone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryMainAVZone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[MAX_SUB_MENUS];
    U16 ItemIcons[MAX_SUB_MENUS];
    U16 nItems;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_AVZONE, NULL, EntryMainAVZone, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_AVZONE);
    nItems = GetNumOfChild_Ext(MAIN_MENU_OPTION_AVZONE_MENUID);
    GetSequenceStringIds_Ext(MAIN_MENU_OPTION_AVZONE_MENUID, ItemList);
    GetSequenceImageIds_Ext(MAIN_MENU_OPTION_AVZONE_MENUID, ItemIcons);
    SetParentHandler(MAIN_MENU_OPTION_AVZONE_MENUID);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

#if defined(__MMI_FM_RADIO__) && defined(__MMI_FM_RADIO_CHECK_CHIP_OR_HIDE__)
    RegisterHighlightHandler(mmi_fmrdo_skip_highlight_hdlr);
    nItems = mmi_fmrdo_check_chip_or_hide(nItems, ItemList, ItemIcons);
#else /* defined(__MMI_FM_RADIO__) && defined(__MMI_FM_RADIO_CHECK_CHIP_OR_HIDE__) */ 
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
#endif /* defined(__MMI_FM_RADIO__) && defined(__MMI_FM_RADIO_CHECK_CHIP_OR_HIDE__) */ 
    /*
     * //MTK Leo add, mini_tab_bar
     * #ifdef __MMI_WGUI_MINI_TAB_BAR__
     * wgui_enable_mini_tab_bar(MAIN_MENU_AVZONE_MENU_ID);
     * #endif
     * //MTK Leo end
     */
    ShowCategory52Screen(
        MAIN_MENU_AVZONE_TEXT,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        ItemIcons,
        0,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 

#endif /* defined(__MMI_VERSION_2__) */ 


#ifdef __MMI_SUBLCD_MASTER_MODE__
static U16	main_menu_hilited_index = 0;

/*****************************************************************************
 * FUNCTION
 *  ExitSubLCDMainMenuScreen
 * DESCRIPTION
 *  Exit SubLCD MainMenu Screen
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSubLCDMainMenuScreen()
{
    main_menu_hilited_index = 0;
    ForceEntrySubLCDSlave();
    GoBackHistory();
    /*
     * At the function EntrySubLCDMasterFromIdle(), we may freeze subLCD to avoid update subLCD when interrupt occurs.
     * When exit subLCD main menu screen, we will unfreeze the subLCD.
     */
    UI_set_sub_LCD_graphics_context();
    gdi_lcd_freeze(FALSE);
    UI_set_main_LCD_graphics_context();
}


/*****************************************************************************
 * FUNCTION
 *  EntrySubLCDMainMenuScreen
 * DESCRIPTION
 *  Entry SubLCD MainMenu Screen
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void SubLCDMainMenuScreenHiliteHandler(S32 index)
{
    main_menu_hilited_index = index;
    ExecuteCurrHiliteHandler(index);
}


/*****************************************************************************
 * FUNCTION
 *  EntrySubLCDMainMenuScreen
 * DESCRIPTION
 *  Entry SubLCD MainMenu Screen
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySubLCDMainMenuScreen()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 numOfItems = 0;
    U16 itemList[MAX_SUB_MENUS];
    U16 itemIcon[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
    DinitSubLCDHistory();
	ClearAllKeyHandler();
	
    SetParentHandler(MENU_ID_SUB_MAIN_MENU);

    numOfItems = GetNumOfChild_Ext(MENU_ID_SUB_MAIN_MENU);

    GetSequenceStringIds_Ext(MENU_ID_SUB_MAIN_MENU, itemList);
    GetSequenceImageIds_Ext(MENU_ID_SUB_MAIN_MENU, itemIcon);

    RegisterHighlightHandler(SubLCDMainMenuScreenHiliteHandler);

	
    ShowCategory314Screen(
        (U8*)GetString(MAIN_MENU_MENU_TEXT),
        0, 
        numOfItems,
        itemList,
        itemIcon,
        NULL, 
        main_menu_hilited_index,
        NULL);

    SetKeyHandler( ExitSubLCDMainMenuScreen, KEY_FWD, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntrySubLCDMainMenu
 * DESCRIPTION
 *  Entry SubLCD MainMenu
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
U8 EntrySubLCDMainMenu()
{
    if (SetSubLCDInMasterMode())
    {
        DisplaySubLCDScreen(SUB_MAIN_MENU_SCREENID, EntrySubLCDMainMenuScreen, TRUE);
    	return TRUE;		
    }
    return FALSE;	
}

#endif /* __MMI_SUBLCD_MASTER_MODE__ */

