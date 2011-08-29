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
 *  AppMemMgr.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  App-Based Shared Memory Manager
 *
 *  App-based shared memory is allocated before entering an application, and 
 *  released when exiting an application. 
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
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#include "mmi_frm_gprot.h"
#include "GlobalDefs.h"
#include "app_mem.h"
#include "mmi_frm_prot.h"
#include "CommonScreensEnum.h"
#include "CommonScreens.h"
#include "SettingProfile.h"         /* for tone ID */
#include "wgui_categories_fmgr.h"   /* Category 212 */
#include "mmiapi_func.h"
#include "wgui_categories_popup.h"
#include "CallmanagementGprot.h"    /* Check incoming call */
#include "custom_events_notify.h"
#include "UCMGProt.h"
#include "UCMGAppProt.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/

/* States of mmi_frm_appmem_stop_confirm_screen_yes() */
typedef enum
{
    /* Normal case */
    MMI_FRM_APPMEM_STOP_STATE_IGNORE,
    /* Inside mmi_frm_appmem_stop_confirm_screen_yes() */
    MMI_FRM_APPMEM_STOP_STATE_WAITING,
    /* Stop operation finished inside mmi_frm_appmem_stop_confirm_screen_yes() */
    MMI_FRM_APPMEM_STOP_STATE_FINISHED
} mmi_frm_appmem_stop_state_enum;

/* Context of the prompt screen */
typedef struct 
{
    /* Properties of the application requesting to free up more memory */
    MMI_ID_TYPE app_name;
    MMI_ID_TYPE app_icon;
    /* Requested memory size */
    U32 required_size;
    MMI_BOOL require_full_pool;
    /* Used inside mmi_frm_appmem_stop_confirm_screen_yes() */
    mmi_frm_appmem_stop_state_enum stop_state;
    kal_uint32 app_id_confirm_to_stop;
    /* 
     * To indicate asm manager in working. 
     * Set TRUE when enter prompt screen, set FALSE when destroy prompt screen.
     */
    MMI_BOOL is_in_asm_manager;
    void (*success_callback)(void);
    mmi_frm_appmem_cb cancel_callback;
/* Vogins Start */
#if defined(__VRE30_AM__)
/* hild applicatin id in prompt list screen */
    U32 hide_appid[MMI_FRM_APPMEM_MAX_HIDE_APP];
#endif
/* Vogins End */
} mmi_frm_appmem_prompt_struct;

typedef struct 
{
    /* Number of applications using App-based ASM */
    S32 num_app;
    /* Detailed information */
    applib_mem_ap_usage_struct applist[MMI_FRM_APPMEM_MAX_APP_PROMPTED];
} mmi_frm_appmem_prompt_screen_struct;

/*****************************************************************************              
 * Local Variable                                                                    
 *****************************************************************************/

/* Life cycle: prompt user to stop applications -> successfully get the memory or cancelled */
static mmi_frm_appmem_prompt_struct g_mmi_frm_appmem_prompt;

/* Life cycle: inside the prompt screen only (SCR_APPMEM_STOP_PROMPT) */
static mmi_frm_appmem_prompt_screen_struct *g_mmi_frm_appmem_prompt_screen = NULL;

/*****************************************************************************              
 * Local Function                                                                    
 *****************************************************************************/

/* Prototype declarations: */
static void mmi_frm_appmem_entry_prompt_screen(void);
static void mmi_frm_appmem_entry_progressing_screen(void);
static void mmi_frm_appmem_invoke_release_mem_success_callback(void);
static void mmi_frm_appmem_stop_finished_handler(kal_uint32 app_id, kal_uint32 string_id, kal_bool result);
/* Vogins Start */
#ifdef __VRE30_AM__
static MMI_BOOL asm_mgr_check_hide_app(void);
#endif
/* Vogins End */
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_execute_cancel_callback
 * DESCRIPTION
 *  Notify application with cancel type if cancel callback is registered.
 *  This interface should be modify if app need more info for cancel callback in future.
 * PARAMETERS
 *  type        [IN]    cancel type
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_execute_cancel_callback(mmi_frm_appmem_event_type_enum type)
{
    if (g_mmi_frm_appmem_prompt.cancel_callback)
    {
        mmi_frm_appmem_evt_struct cancel_info;

        cancel_info.evt_type = type;
        g_mmi_frm_appmem_prompt.cancel_callback((void *)&cancel_info);
		g_mmi_frm_appmem_prompt.cancel_callback = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_delete_asm_screens
 * DESCRIPTION
 *  Delete all asm related screens.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_delete_asm_screens(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    DeleteScreenIfPresent(SCR_APPMEM_STOP_PROMPT);
    DeleteScreenIfPresent(SCR_APPMEM_STOP_PROGRESSING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_reset_asm_manager
 * DESCRIPTION
 *  Reset applicate asm environment including screen and global flag.
 *  Two case will invoke this function:
 *  1. After invoking success callback, exit asm manager;
 *  2. Call in incoming, prevent reentry problem;
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_reset_asm_manager(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * Won't invoke cancel callback if we delete asm screen in reset asm manager procedure
     */
    g_mmi_frm_appmem_prompt.cancel_callback = NULL;
    mmi_frm_appmem_delete_asm_screens();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_is_in_prompt_screens
 * DESCRIPTION
 *  Whether MMI is inside prompt screens (SCR_APPMEM_STOP_PROMPT and SCR_APPMEM_STOP_PROGRESSING)
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_frm_appmem_is_in_prompt_screens(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 curr_scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_scr_id = GetExitScrnID();
    return curr_scr_id == SCR_APPMEM_STOP_PROMPT || 
           curr_scr_id == SCR_APPMEM_STOP_PROGRESSING;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_is_prompt_screens_in_history
 * DESCRIPTION
 *  Whether a prompt screen (SCR_APPMEM_STOP_PROMPT or SCR_APPMEM_STOP_PROGRESSING)
 *  is inside history.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_frm_appmem_is_prompt_screens_in_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return IsScreenPresent(SCR_APPMEM_STOP_PROMPT) || 
           IsScreenPresent(SCR_APPMEM_STOP_PROGRESSING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_jump_to_prompt_screen
 * DESCRIPTION
 *  Go back to the prompt screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_jump_to_prompt_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsScreenPresent(SCR_APPMEM_STOP_PROMPT))
    {
        GoBackToHistory(SCR_APPMEM_STOP_PROMPT);
    }
    else
    {
        GoBackHistory();
    }
}
 

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_exit_progressing_screen
 * DESCRIPTION
 *  Exit function of progressing screen 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_exit_progressing_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (g_mmi_frm_appmem_prompt.is_in_asm_manager)
    {/* Won't add history if reset asm, e.g. incoming call interrupt */
        h.scrnID = SCR_APPMEM_STOP_PROGRESSING;
        h.entryFuncPtr = mmi_frm_appmem_entry_progressing_screen;
        mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) L"");
        GetCategoryHistory(h.guiBuffer);
    
        AddHistory(h);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_check_enough_memory
 * DESCRIPTION
 *  Check if the free memory is enough
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_frm_appmem_check_enough_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_frm_appmem_prompt.require_full_pool && applib_mem_ap_get_alloc_count() == 0)
    {
        return MMI_TRUE;
    }

    if (!g_mmi_frm_appmem_prompt.require_full_pool && 
         applib_mem_ap_get_max_alloc_size() >= g_mmi_frm_appmem_prompt.required_size)
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_end_key_hdlr
 * DESCRIPTION
 *  End key handler for ASM to invoke cancel callback then display idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_end_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_execute_cancel_callback(MMI_FRM_APPMEM_CANCEL_BY_END_KEY);

    DisplayIdleScreen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_entry_progressing_screen
 * DESCRIPTION
 *  Entry function of progressing screen when an application has not finished stopping
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_entry_progressing_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    MMI_BOOL bShowProgressScr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    bShowProgressScr = !mmi_frm_appmem_check_enough_memory() || 
                        mmi_is_redrawing_bk_screens() ||  /* redrawn by small screen */
                        (g_mmi_frm_appmem_prompt.stop_state == MMI_FRM_APPMEM_STOP_STATE_WAITING);     

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_ENTRY_PROGRESSING_SCREEN, bShowProgressScr);
    
    if (bShowProgressScr)
    {    
        EntryNewScreen(SCR_APPMEM_STOP_PROGRESSING, mmi_frm_appmem_exit_progressing_screen, NULL, NULL);     

        guiBuffer = GetCurrGuiBuffer(SCR_APPMEM_STOP_PROGRESSING);
        mmi_frm_block_general_interrupt_event(MMI_FRM_INT_TOTAL_INTERRUPT_EVENT);

		ShowCategory165Screen(
            0,                                  /* Left softkey */
            0,
            STR_GLOBAL_BACK,                    /* Right softkey */
            0,
			(UI_string_type)GetString(STR_GLOBAL_PLEASE_WAIT),
            mmi_get_event_based_image(MMI_EVENT_PROGRESS),
            guiBuffer);
 
        SetRightSoftkeyFunction(mmi_frm_appmem_jump_to_prompt_screen, KEY_EVENT_UP);
        SetKeyHandler(mmi_frm_appmem_end_key_hdlr, KEY_END, KEY_EVENT_DOWN);
    }
    else
    {
        mmi_display_popupcallback(
            (UI_string_type)GetString(STR_ID_APPMEM_NOTIFY_STARTING_NEW),
            MMI_EVENT_INFO,
            mmi_frm_appmem_invoke_release_mem_success_callback);
        SetKeyHandler(mmi_frm_appmem_end_key_hdlr, KEY_END, KEY_EVENT_DOWN);
		mmi_frm_block_general_interrupt_event(MMI_FRM_INT_TOTAL_INTERRUPT_EVENT);
    }        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_stop_confirm_screen_yes
 * DESCRIPTION
 *  User confirm to stop an application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_stop_confirm_screen_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_frm_appmem_prompt.stop_state = MMI_FRM_APPMEM_STOP_STATE_WAITING;

    applib_mem_ap_stop_app_by_MMI_task(g_mmi_frm_appmem_prompt.app_id_confirm_to_stop);

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_STOP_CONFIRM_YES, 
                g_mmi_frm_appmem_prompt.app_id_confirm_to_stop,
                g_mmi_frm_appmem_prompt.stop_state);
        
    if (g_mmi_frm_appmem_prompt.stop_state != MMI_FRM_APPMEM_STOP_STATE_FINISHED)
    {
        /* mmi_frm_appmem_stop_finished_handler() was not invoked inside
           applib_mem_ap_stop_app_by_MMI_task(), we display progressing
           screen to wait for mmi_frm_appmem_stop_finished_handler() */ 
        mmi_frm_appmem_entry_progressing_screen();
    }
    /* 
     * Don't reset stop state to nignore, make sure the condition in 
     * mmi_frm_appmem_stop_finished_handler could be satisfied when stopping 
     * application of non-mmi task
     */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_entry_stop_confirm_screen
 * DESCRIPTION
 *  Ask user to confirm to stop application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_entry_stop_confirm_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_display_popup_confirm(
        (UI_string_type) GetString(STR_GLOBAL_YES),
        (PU8)GetImage(IMG_GLOBAL_YES),
        (UI_string_type) GetString(STR_GLOBAL_NO),
        (PU8)GetImage(IMG_GLOBAL_NO),
        (UI_string_type) GetString(STR_ID_APPMEM_STOP),
        MMI_EVENT_QUERY);

    SetLeftSoftkeyFunction(mmi_frm_appmem_stop_confirm_screen_yes, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	SetKeyHandler(mmi_frm_appmem_end_key_hdlr, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_prompt_screen_get_item
 * DESCRIPTION
 *  Callback function to draw the info box of prompt screen
 * PARAMETERS
 *  item_index      [IN]        Index of menu item
 *  str_buff        [OUT]       Output text buffer
 *  img_buff_p      [OUT]       Output image buffer
 *  str_img_mask    [OUT]       (deprecated)
 * RETURNS
 *  Success or not
 *****************************************************************************/
static pBOOL mmi_frm_appmem_prompt_screen_get_item(
                S32 item_index, 
                UI_string_type str_buff, 
                PU8 *img_buff_p, 
                U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mem_ap_usage_struct *applist;
    S8 size_str[32];
    S8 size_str_ucs2[32 * 2];
    S32 app_name_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_mmi_frm_appmem_prompt_screen &&
               item_index < g_mmi_frm_appmem_prompt_screen->num_app);

    applist = g_mmi_frm_appmem_prompt_screen->applist;
/* Vogins Start */
#ifdef __VRE_V30__
    if (applist[item_index].app_id > APPLIB_MEM_AP_ID_VRE && applist[item_index].app_id <= APPLIB_MEM_AP_ID_VRE_APP16)
    {
        mmi_ucs2ncpy((S8*) str_buff, (S8*)mmi_am_vre_get_vreapp_name_by_id(applist[item_index].app_id), (MAX_SUB_MENU_SIZE / 2));
    }
    else
    {
    mmi_ucs2ncpy((S8*) str_buff, GetString((U16) applist[item_index].string_id), (MAX_SUB_MENU_SIZE / 2));
    }
#else
    mmi_ucs2ncpy((S8*) str_buff, GetString((U16) applist[item_index].string_id), (MAX_SUB_MENU_SIZE / 2));
#endif
/* Vogins End */
    app_name_len = mmi_ucs2strlen((S8*) str_buff);

    if (applist[item_index].is_stopping)
    {
        mmi_ucs2ncpy(
            (S8*) str_buff + (app_name_len * 2), 
            (S8*) GetString(STR_ID_APPMEM_ATTR_STOPPING),
            (MAX_SUB_MENU_SIZE / 2) - app_name_len);
    }
    else
    {
        sprintf((char*) size_str, " (%d K)", applist[item_index].mem_size / 1024);
        mmi_asc_to_ucs2(size_str_ucs2, size_str);
        
        mmi_ucs2ncpy(
            (S8*) str_buff + (app_name_len * 2), 
            size_str_ucs2, 
            (MAX_SUB_MENU_SIZE / 2) - app_name_len);
    }
    
    *img_buff_p = (PU8) GetImage((U16) applist[item_index].icon_id);

    return (pBOOL) MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_prompt_screen_draw_info
 * DESCRIPTION
 *  Callback function to draw the info box of prompt screen
 * PARAMETERS
 *  idx     [IN]    menu item index
 *  x1      [IN]    x of left-top point
 *  y1      [IN]    y of left-top point
 *  x2      [IN]    x of right-bottom point
 *  y2      [IN]    y of right-bottom point
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_prompt_screen_draw_info(S32 idx, S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 off_set_x;
    S32 off_set_y;
    S32 msg_height;
    S32 msg_width;
    S32 trucated_len;
    UI_string_type msg;   
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (UI_string_type) GetString(STR_ID_APPMEM_PROMPT_STOP_APP);
    gui_measure_string(msg, &msg_width, &msg_height);

    /* For language such as arabic, need display right to left */
    if (r2lMMIFlag)
    {
        off_set_x = x2 - MMI_FRM_APPMEM_PROMPT_INFO_START_PIXEL_OFFSET;
    }
    else
    {
        off_set_x = x1 + MMI_FRM_APPMEM_PROMPT_INFO_START_PIXEL_OFFSET;
    }
    off_set_y = y1 + (y2 - y1 + 1 - msg_height) / 2;
    trucated_len = UI_device_width - MMI_FRM_APPMEM_PROMPT_INFO_START_PIXEL_OFFSET;
    gui_set_text_color(current_header_information_text_theme->text_color);
    gui_print_truncated_text(off_set_x, off_set_y, trucated_len , msg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_prompt_screen_hide_info
 * DESCRIPTION
 *  Callback function to hide the info box of prompt screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_prompt_screen_hide_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_prompt_screen_stop_highlighted
 * DESCRIPTION
 *  Stop the current highlighted application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_prompt_screen_stop_highlighted(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 highlited_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_ASSERT(GetExitScrnID() == SCR_APPMEM_STOP_PROMPT &&
               g_mmi_frm_appmem_prompt_screen);

    highlited_item = GetHighlightedItem();
    MMI_ASSERT(highlited_item < g_mmi_frm_appmem_prompt_screen->num_app);

    g_mmi_frm_appmem_prompt.app_id_confirm_to_stop = 
        g_mmi_frm_appmem_prompt_screen->applist[highlited_item].app_id;

    mmi_frm_appmem_entry_stop_confirm_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_prompt_screen_wait_highlighted
 * DESCRIPTION
 *  Wait a stopping application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_prompt_screen_wait_highlighted(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_frm_appmem_entry_progressing_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_prompt_screen_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of prompt screen
 * PARAMETERS
 *  item_index  [IN]    currently highlighted menu index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_prompt_screen_highlight_hdlr(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_ASSERT(g_mmi_frm_appmem_prompt_screen);
    if (g_mmi_frm_appmem_prompt_screen->num_app == 0)
    {
        return;
    }
    
    MMI_ASSERT(item_index < g_mmi_frm_appmem_prompt_screen->num_app);
    
    if (!g_mmi_frm_appmem_prompt_screen->applist[item_index].is_stopping)
    {
        ChangeLeftSoftkey(STR_GLOBAL_STOP, 0);
        SetLeftSoftkeyFunction(mmi_frm_appmem_prompt_screen_stop_highlighted, KEY_EVENT_UP);
    }
    else
    {
        ChangeLeftSoftkey(STR_ID_APPMEM_WAIT, 0);
        SetLeftSoftkeyFunction(mmi_frm_appmem_prompt_screen_wait_highlighted, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_exit_prompt_screen
 * DESCRIPTION
 *  Exit function of prompt screen 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_exit_prompt_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (g_mmi_frm_appmem_prompt.is_in_asm_manager)
    {/* Won't add history if reset asm, e.g. incoming call interrupt */
        h.scrnID = SCR_APPMEM_STOP_PROMPT;
        h.entryFuncPtr = mmi_frm_appmem_entry_prompt_screen;
        mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) L"");
        GetCategoryHistory(h.guiBuffer);
    
        AddHistory(h);
    }
    if (g_mmi_frm_appmem_prompt_screen)
    {
        OslMfree(g_mmi_frm_appmem_prompt_screen);
        g_mmi_frm_appmem_prompt_screen = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_prompt_scrn_destroy_cb_hdlr
 * DESCRIPTION
 *  Delete callback function of prompt screen, execute cancel callback at first time
 *  means before delete other screen and destroy handler.
 *  MAUI_1606449: USB display idle, delete all screen, java del_cb return stop deleting,
 *  java wait mutex, wap set its cancel callback as NULL, if we want to invoke cancel callback
 *  in destroy callback, for this case, wap's cb can't be invoked. So we invoke cancel callback
 *  in delete callback which could be called in the earliest time.
 *
 * PARAMETERS
 *  arg     [IN]    application argument
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_frm_appmem_prompt_scrn_delete_cb_hdlr(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Some popup scrn will go back to idle, i.g. SIM card plug in, USB plug in */
    mmi_frm_appmem_execute_cancel_callback(MMI_FRM_APPMEM_CANCEL_DEL_BY_INTERRUPT);

    return MMI_HIST_ALLOW_DELETING;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_prompt_scrn_destroy_cb_hdlr
 * DESCRIPTION
 *  Destroy callback function of prompt screen, set flag to indicate asm manager
 *  is ended, then the success callback won't be invoked.
 * PARAMETERS
 *  arg     [IN]    application argument
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_frm_appmem_prompt_scrn_destroy_cb_hdlr(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_unreg_call_status_change_cb(MMI_UCM_CB_APP_ASM);
    g_mmi_frm_appmem_prompt.is_in_asm_manager = MMI_FALSE;

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_prompt_rsk_hdlr
 * DESCRIPTION
 *  RSK handler of prompt screen, notify application if cancel callback is registered.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_prompt_rsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_frm_appmem_execute_cancel_callback(MMI_FRM_APPMEM_CANCEL_BACK_FROM_PROMPT_SCRN);
    GoBackHistory();
}
/* Vogins Start */
#ifdef __VRE30_AM__
void mmi_frm_appmem_set_hide_list_screen(U32 hide_appid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i = 0; i < MMI_FRM_APPMEM_MAX_HIDE_APP; i++)
    {
        if(APPLIB_MEM_AP_ID_DUMMY == g_mmi_frm_appmem_prompt.hide_appid[i])
        {
            g_mmi_frm_appmem_prompt.hide_appid[i] = hide_appid;
            break;
        }       
    }
   // g_mmi_frm_asm_manager_cntx.hide_appid = hide_appid;
}

void mmi_frm_appmem_clear_hide_list_screen(U32 hide_appid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i = 0; i < MMI_FRM_APPMEM_MAX_HIDE_APP; i++)
    {
        if(hide_appid == g_mmi_frm_appmem_prompt.hide_appid[i])
        {
            g_mmi_frm_appmem_prompt.hide_appid[i] = APPLIB_MEM_AP_ID_DUMMY;
            break;
        } 
    }
    //g_mmi_frm_asm_manager_cntx.hide_appid = APPLIB_MEM_AP_ID_DUMMY;
}

static MMI_BOOL asm_mgr_check_hide_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i,j,count=0;
	MMI_BOOL ret = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((1 == g_mmi_frm_appmem_prompt_screen->num_app) && 
        ((APPLIB_MEM_AP_ID_VRE == g_mmi_frm_appmem_prompt_screen->applist[0].app_id)
         ||(APPLIB_MEM_AP_ID_AM == g_mmi_frm_appmem_prompt_screen->applist[0].app_id)))
    {
        return MMI_TRUE;
    }
    for(i = 0; i < g_mmi_frm_appmem_prompt_screen->num_app; i++)
    {
        for(j = 0; j < MMI_FRM_APPMEM_MAX_HIDE_APP; j++)
        {
            if ((g_mmi_frm_appmem_prompt.hide_appid[j] != APPLIB_MEM_AP_ID_DUMMY)
                && (g_mmi_frm_appmem_prompt.hide_appid[j] != 0)
                && g_mmi_frm_appmem_prompt_screen->applist[i].app_id ==  g_mmi_frm_appmem_prompt.hide_appid[j])
            {
                kal_prompt_trace(MOD_MMI,"hied1111:%d",g_mmi_frm_appmem_prompt.hide_appid[j]);
                   if(i < g_mmi_frm_appmem_prompt_screen->num_app -1)
            {
                memmove(&(g_mmi_frm_appmem_prompt_screen->applist[i]), 
                    &(g_mmi_frm_appmem_prompt_screen->applist[i + 1]), 
                    (sizeof(applib_mem_ap_usage_struct)*(g_mmi_frm_appmem_prompt_screen->num_app - (i+1))));
                   }
                memset(&(g_mmi_frm_appmem_prompt_screen->applist[g_mmi_frm_appmem_prompt_screen->num_app - 1]), 0,
                   sizeof(applib_mem_ap_usage_struct));
                count++;
                ret =  MMI_TRUE;
            }
        }
    }
    g_mmi_frm_appmem_prompt_screen->num_app= g_mmi_frm_appmem_prompt_screen->num_app - count;
    return ret;
}
/*vogins 100726 end */
#endif
/* Vogins End */
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_entry_prompt_screen
 * DESCRIPTION
 *  Entry function of prompt screen to stop other applications
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_entry_prompt_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 info_box_height;
    MMI_BOOL bShowPromptScr;
    MMI_BOOL bBackHistory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_mmi_frm_appmem_prompt_screen == NULL);

    bBackHistory = CheckIsBackHistory();

    bShowPromptScr = !mmi_frm_appmem_check_enough_memory() || 
                     mmi_is_redrawing_bk_screens() ||  /* redrawn by small screen */
                     (g_mmi_frm_appmem_prompt.stop_state == MMI_FRM_APPMEM_STOP_STATE_WAITING); 

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_ENTRY_PROMPT_SCREEN, bShowPromptScr);
    
    if (bShowPromptScr)
    {
        EntryNewScreen(SCR_APPMEM_STOP_PROMPT, mmi_frm_appmem_exit_prompt_screen, NULL, NULL);     

        /* Sometimes exit function of the previous screen will release the app ASM we need.
         * However, we cannot enter another screen when go back to history */
        if (!bBackHistory && mmi_frm_appmem_check_enough_memory())
        {         
            EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
            mmi_frm_appmem_invoke_release_mem_success_callback();
        }
        else
        {
            guiBuffer = GetCurrGuiBuffer(SCR_APPMEM_STOP_PROMPT);
            if (!g_mmi_frm_appmem_prompt_screen)
            {
                g_mmi_frm_appmem_prompt_screen = 
                    (mmi_frm_appmem_prompt_screen_struct*) OslMalloc(sizeof(mmi_frm_appmem_prompt_screen_struct));
            }
            g_mmi_frm_appmem_prompt_screen->num_app = 
                (S32) applib_mem_ap_get_current_usage(
                        g_mmi_frm_appmem_prompt_screen->applist,
                        MMI_FRM_APPMEM_MAX_APP_PROMPTED);
/* Vogins Start */
        #ifdef __VRE30_AM__
            asm_mgr_check_hide_app();
            MMI_ASSERT(g_mmi_frm_appmem_prompt_screen->num_app > 0);
        #endif
/* Vogins End */
            info_box_height = MMI_MENUITEM_HEIGHT + 4;        

            RegisterHighlightHandler(mmi_frm_appmem_prompt_screen_highlight_hdlr);
            
            ShowCategory211Screen(
                STR_GLOBAL_INSUFFICIENT_MEMORY,
                0, 
                STR_GLOBAL_STOP,
                0, 
                STR_GLOBAL_BACK, 
                0, 
                g_mmi_frm_appmem_prompt_screen->num_app, 
                mmi_frm_appmem_prompt_screen_get_item, 
                NULL, 
                mmi_frm_appmem_prompt_screen_draw_info,
                mmi_frm_appmem_prompt_screen_hide_info,
                info_box_height,            /* Info box height */
                0,                          /* Background image of info box */
                0,                          /* Highlight item index */
                guiBuffer);

           SetRightSoftkeyFunction(mmi_frm_appmem_prompt_rsk_hdlr, KEY_EVENT_UP);
           SetKeyHandler(mmi_frm_appmem_end_key_hdlr, KEY_END, KEY_EVENT_DOWN);

           SetDelScrnIDCallbackHandler(SCR_APPMEM_STOP_PROMPT, mmi_frm_appmem_prompt_scrn_delete_cb_hdlr);
           mmi_frm_set_destroy_scrn_callback(SCR_APPMEM_STOP_PROMPT, mmi_frm_appmem_prompt_scrn_destroy_cb_hdlr);
       }
    }
    else
    {
        mmi_display_popupcallback(
            (UI_string_type)GetString(STR_ID_APPMEM_NOTIFY_STARTING_NEW),
            MMI_EVENT_INFO,
            mmi_frm_appmem_invoke_release_mem_success_callback);                
        SetKeyHandler(mmi_frm_appmem_end_key_hdlr, KEY_END, KEY_EVENT_DOWN);
		mmi_frm_block_general_interrupt_event(MMI_FRM_INT_TOTAL_INTERRUPT_EVENT);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_invoke_release_mem_success_callback
 * DESCRIPTION
 *  Invoke the calling application there is enough memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_invoke_release_mem_success_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(mmi_frm_appmem_check_enough_memory());
    MMI_ASSERT(mmiapi_is_MMI_task());
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_INVOKE_SUCCESS_CB, 
                g_mmi_frm_appmem_prompt.app_name,
                g_mmi_frm_appmem_prompt.success_callback);

    /* Enter another screen by registered callback function */
    if (g_mmi_frm_appmem_prompt.is_in_asm_manager)
    {/* 
      * If press END key go back idle, we make the asm process ended and won't invoke success callback here.
      * Actually, mmi_display_popupcallback won't invoke callback if exit this popup screen.
      */
        mmi_frm_appmem_reset_asm_manager();
        g_mmi_frm_appmem_prompt.success_callback();
    }

    /* The callback function must enter new MMI screen */
    MMI_ASSERT(!mmi_frm_appmem_is_in_prompt_screens() &&
               !mmi_frm_appmem_is_prompt_screens_in_history());
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_stop_finished_handler
 * DESCRIPTION
 *  Callback handler when an application finished stop operation
 * PARAMETERS
 *  app_id      [IN]    ID of the application to be stopped
 *  string_id   [IN]    Name of the application to be stopped
 *  result      [IN]    whether the stop operation suceeds or not
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_stop_finished_handler(kal_uint32 app_id, kal_uint32 string_id, kal_bool result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_appmem_is_in_prompt_screens() ||
        g_mmi_frm_appmem_prompt.stop_state == MMI_FRM_APPMEM_STOP_STATE_WAITING) /* In confirm screen */
    {
        U32 msgId;

        mmi_event_notify_enum pop_event_id; 
        FuncPtr callback;
        if (mmi_frm_appmem_check_enough_memory())
        {
            msgId = STR_ID_APPMEM_NOTIFY_STARTING_NEW;
            pop_event_id = MMI_EVENT_INFO;
            callback = mmi_frm_appmem_invoke_release_mem_success_callback;
        }
        else if (result) 
        {
            msgId = STR_ID_APPMEM_NOTIFY_STOPPED;
            pop_event_id = MMI_EVENT_SUCCESS;
            callback = mmi_frm_appmem_jump_to_prompt_screen;
            DeleteScreenIfPresent(SCR_APPMEM_STOP_PROGRESSING);
        }
        else
        {
            msgId = STR_ID_APPMEM_NOTIFY_STOP_FAILED;
            pop_event_id = MMI_EVENT_FAILURE;
            callback = mmi_frm_appmem_jump_to_prompt_screen;
        }
        if (g_mmi_frm_appmem_prompt.is_in_asm_manager)
        {/* 
          * 1. Can't invoke success cb to launch app during incoming call since prompt screen will be destroyed.
          * 2. Can't invoke success cb if user press END key to go back to idle since prompt screen will be destroyed.
          */
            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_STOP_FINISHED_HANDLER, msgId, callback);
            /* If press END key to go back to idle, this popup interface won't invoke callback. */
            mmi_display_popupcallback(
                (UI_string_type)GetString((U16)msgId),
                pop_event_id,
                callback);
            SetKeyHandler(mmi_frm_appmem_end_key_hdlr, KEY_END, KEY_EVENT_DOWN);
			mmi_frm_block_general_interrupt_event(MMI_FRM_INT_TOTAL_INTERRUPT_EVENT);
        }
        if (g_mmi_frm_appmem_prompt.stop_state == MMI_FRM_APPMEM_STOP_STATE_WAITING)
        {
            g_mmi_frm_appmem_prompt.stop_state = MMI_FRM_APPMEM_STOP_STATE_FINISHED;
        }
    }
    else 
    {
        /* 
         * 1. If prompt screen is in history - it will be processed after goback to prompt screen 
         * 2. If prompt screen is not in history - silently ignore the result 
         *    (Maybe it goes back to idle screen)
         */
    }
}


/*****************************************************************************              
 * Extern Global Variable                                                                    
 *****************************************************************************/

/*****************************************************************************              
 * Extern Global Function                                                                    
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_check_prompt_screen
 * DESCRIPTION
 *  Check if prompt screen is current screen or in history
 * PARAMETERS
 *  void
 * RETURNS
 * applib_mem_ap_id_enum application id which invoke prompt screen
 *****************************************************************************/
applib_mem_ap_id_enum mmi_frm_appmem_check_prompt_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_appmem_is_in_prompt_screens() || mmi_frm_appmem_is_prompt_screens_in_history())
    {
        return (applib_mem_ap_id_enum)g_mmi_frm_appmem_prompt.app_name;
    }
    else
    {
        return APPLIB_MEM_AP_ID_DUMMY;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ucm_cb_hdlr
 * DESCRIPTION
 *  Callback handler of ucm incoming call to stop asm manager and notify application
 *  if cancel callback has been registered.
 * PARAMETERS
 *  void
 * RETURNS
 * applib_mem_ap_id_enum application id which invoke prompt screen
 *****************************************************************************/
static void mmi_frm_appmem_ucm_cb_hdlr(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if(mmi_ucm_app_incoming_call(MMI_UCM_CALL_TYPE_ALL) > 0)
    {
        mmi_frm_appmem_execute_cancel_callback(MMI_FRM_APPMEM_CANCEL_BY_UCM_CALL);
        if (!mmi_frm_appmem_is_prompt_screens_in_history())
        {/* When call coming, asm screen hasn't added into history, so we should add them to history firstly. */
            mmi_frm_entry_new_screen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
        }
        mmi_frm_appmem_reset_asm_manager();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_create_asm_manager_screen
 * DESCRIPTION
 *  Create asm manager screen.
 * PARAMETERS
 *  app_name            [IN]    String ID of the application 
 *  app_icon            [IN]    Image ID of the application 
 *  required_size       [IN]    Minimum required memory for the application
 *  success_callback    [IN]    Callback function when getting memory successfully
 *  require_full_pool   [IN]    If require full pool or not
 * RETURNS
 *  void
 **************************************************************************/
static void mmi_frm_create_asm_manager_screen(
        MMI_ID_TYPE app_name, 
        MMI_ID_TYPE app_icon, 
        U32 required_size,
        void (*success_callback)(void),
        MMI_BOOL require_full_pool)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Avoid reentrance of the prompt screen.
       Application developers should be careful on designing the screen flow */
    MMI_ASSERT(!mmi_frm_appmem_is_in_prompt_screens() && 
               !mmi_frm_appmem_is_prompt_screens_in_history());

    /* Register UCM callback, exit asm manager when call coming. */
    mmi_ucm_reg_call_status_change_cb(MMI_UCM_CB_APP_ASM, mmi_frm_appmem_ucm_cb_hdlr, NULL);

    /* Note the context g_mmi_frm_appmem_prompt is not reset  */
    g_mmi_frm_appmem_prompt.app_name = app_name;
    g_mmi_frm_appmem_prompt.app_icon = app_icon;
    /* Set required_size as 0 for full pool case, could use new interface to get full pool size in future. */
    g_mmi_frm_appmem_prompt.required_size = required_size;
    g_mmi_frm_appmem_prompt.success_callback = success_callback;
    g_mmi_frm_appmem_prompt.require_full_pool = require_full_pool;

    /* Init internal status */
    g_mmi_frm_appmem_prompt.stop_state = MMI_FRM_APPMEM_STOP_STATE_IGNORE;
    g_mmi_frm_appmem_prompt.is_in_asm_manager = MMI_TRUE;

    mmi_frm_appmem_entry_prompt_screen();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_prompt_to_release_mem
 * DESCRIPTION
 *  Show "out-of-memory" screen and prompt user to stop other applications in order 
 *  to release more memory.
 *
 *  Remark: 
 *  1. This function is not suggested to be used in "interrupt screens" 
 *     (e.g. MT call or USB plug-in indication)
 *     Otherwise, it might re-enter the prompt screen and confuse user.
 *  2. 'success_callback' needs to enter a new MMI screen!
 *  3. There is a "cancel callback" registered by mmi_frm_appmem_set_cancel_callback.
 *     asm manager 
 *     implicit "waiting" state for the result.
 *
 *     For example, user may press End key in the "out-of-memory" screen and
 *     try to enter the application again. 
 *
 *  Warning: This function can only be used in MMI task.
 * PARAMETERS
 *  app_name:            [IN]    Application ID
 *  app_icon:            [IN]    Image ID of the application 
 *  required_size:       [IN]    Minimum required memory for the application
 *  success_callback:    [IN]    Callback function when getting memory successfully 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_appmem_prompt_to_release_mem(
        MMI_ID_TYPE app_name, 
        MMI_ID_TYPE app_icon, 
        U32 required_size,
        void (*success_callback)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(required_size <= applib_mem_ap_get_pool_size());
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_PROMPT_TO_RELEASE_MEM, app_name, required_size);

    mmi_frm_create_asm_manager_screen(app_name, app_icon, required_size, success_callback, MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_prompt_to_release_full_pool
 * DESCRIPTION
 *  Show "out-of-memory" screen and prompt user to stop other applications in order 
 *  to release more memory.
 *  
 *  This function is similar to mmi_frm_appmem_prompt_to_release_mem
 *  but it requires the whole pool.
 *
 *  Warning: This function can only be used in MMI task.
 * PARAMETERS
 *  app_name:            [IN]    Application ID 
 *  app_icon:            [IN]    Image ID of the application 
 *  success_callback:    [IN]    Callback function when getting memory successfully 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_appmem_prompt_to_release_full_pool(
        MMI_ID_TYPE app_name, 
        MMI_ID_TYPE app_icon, 
        void (*success_callback)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_PROMPT_TO_RELEASE_FULL_POOL, app_name);

    mmi_frm_create_asm_manager_screen(app_name, app_icon, 0, success_callback, MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_set_cancel_callback
 * DESCRIPTION
 *  Cancel callback will be invoked to notify application when asm manager is cancel.
 *  E.g. user press back (RSK) in prompt screen, press END key in progressing screen or 
 *  start new application screen, which means asm manager can't launch new application
 *  due to some reasons.
 *  This api should be called after mmi_frm_appmem_prompt_to_release_mem.
 * PARAMETERS
 *  app_id              [IN]    application id
 *  cancel_callback     [IN]    Function pointer of cancel callback
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_appmem_set_cancel_callback(applib_mem_ap_id_enum app_id, mmi_frm_appmem_cb cancel_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_frm_appmem_prompt.app_name == app_id)
    {
        g_mmi_frm_appmem_prompt.cancel_callback = cancel_callback;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_init
 * DESCRIPTION
 *  Initialize app-based ASM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_appmem_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_mem_ap_init(mmi_frm_appmem_stop_finished_handler);
}


/***************************************************************************** 
 * Unit Test 
 *****************************************************************************/

#ifdef APPLIB_MEM_UNIT_TEST
#include "IdleAppProt.h"
#include "PsCallHelperDef.h"
#include "stdlib.h"

/***************************************************************************** 
 * Define 
 *****************************************************************************/
#define MMI_FRM_APPMEM_TEST1_SIZE   (10*1024)
#define MMI_FRM_APPMEM_TEST2_SIZE   (20*1024)
#define MMI_FRM_APPMEM_TEST3_SIZE   (30*1024)
#define MMI_FRM_APPMEM_TEST4_SIZE   (40*1024)
#define MMI_FRM_APPMEM_TEST5_SIZE   (50*1024)

/* start index of APPs */
#define TEST_ITEM_START     (2)
/* no. of unit-test menu items */
#define TEST_ITEM_NUM       (sizeof(g_appmem_ut_test_func)/sizeof(void*) + TEST_ITEM_START)
/* string length of menu items */
#define TEST_ITEM_STR_LEN   (30)
/* popup time for each APP */
#define TEST_APP_POPUP_TIME (500)   /* ms */

/* UT type */
#define UT_END_PROGRESS_SCRN    1
#define UT_UCM_PROGRESS_SCRN    2
#define UT_UCM_STARTNEW_SCRN    3

/***************************************************************************** 
 * Local function 
 *****************************************************************************/
static void mmi_frm_appmem_ut_2nd_entry(S32 selected_item);
static void mmi_frm_appmem_ut_hilight_hdlr(S32 index);
static void mmi_frm_appmem_ut_start(void);
static void mmi_frm_ut_app_entry(void *arg);
static void mmi_frm_appmem_ut_regress_test(void);
static void mmi_frm_appmem_ut_execute_key_hdlr(S16 key_code);

/***************************************************************************** 
 * Local variable 
 *****************************************************************************/
/* test function for each APP */
void (* const g_appmem_ut_test_func[])(void (*run_callback)(void *), MMI_BOOL) = {
    mmi_frm_appmem_unit_test_prepare_to_enter_test1,
    mmi_frm_appmem_unit_test_prepare_to_enter_test2,
    mmi_frm_appmem_unit_test_prepare_to_enter_test3,
    mmi_frm_appmem_unit_test_prepare_to_enter_test4,
    mmi_frm_appmem_unit_test_prepare_to_enter_test5};

/* mem. allocation size for each APP */
const U32 g_appmem_ut_allocate_size[] = {
    MMI_FRM_APPMEM_TEST1_SIZE,
    MMI_FRM_APPMEM_TEST2_SIZE,
    MMI_FRM_APPMEM_TEST3_SIZE,
    MMI_FRM_APPMEM_TEST4_SIZE,
    MMI_FRM_APPMEM_TEST5_SIZE};

/* structure for appmem unit-test variables */
typedef struct {
    S32 selected_item;
    S8 item_list_str[TEST_ITEM_NUM][TEST_ITEM_STR_LEN*ENCODING_LENGTH];
    S8 *item_list[TEST_ITEM_NUM];
} mmi_frm_appmem_ut_context_struct;

/* appmem unit-test context variable */
static mmi_frm_appmem_ut_context_struct g_appmem_ut_cntx = {
    /* selected_item */
    TEST_ITEM_START,
    /* item_list_str */
    {
    "",
    /* "Free All TEST Memory" */
    "F\0r\0e\0e\0 \0A\0l\0l\0 \0T\0E\0S\0T\0 \0M\0e\0m\0o\0r\0y\0\0\0"}
};

typedef struct
{
    applib_mem_ap_id_enum   app_id;
} mmi_frm_ut_app_entry_arg_struct;

static applib_mem_ap_id_enum g_current_running_app = APPLIB_MEM_AP_ID_DUMMY;
static MMI_BOOL g_mmi_frm_appmem_ut_regress = MMI_FALSE;
/* Some test case will start timer for async working flow, we have to break regress test flow. */
static MMI_BOOL g_mmi_frm_appmem_ut_break_flow = MMI_FALSE;
static S8 g_mmi_frm_appmem_ut_case_idx;
static U8 asm_ut_type;
static MMI_BOOL cancel_cb_is_called;

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_unit_test_stress_alloc
 * DESCRIPTION
 *  Unit test routine
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_unit_test_stress_alloc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 *ptr_list[100];
    kal_uint32 i, count, free_space_original, tmp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST1);
    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST2);
    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST3);
    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST4);
    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST5);    

    free_space_original = applib_mem_ap_get_total_left_size();

#define ALLOC_SIZE(_idx)    ((_idx) + (_idx) * 256)
#define PTR_LIST_SIZE       (sizeof(ptr_list) / sizeof(void*))

    for (i = 0; i < PTR_LIST_SIZE; i++)
    {
        if ((ptr_list[i] = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST1, ALLOC_SIZE(i))) == NULL)
        {
            MMI_ASSERT(applib_mem_ap_get_max_alloc_size() < ALLOC_SIZE(i));
            break;
        }
    }

    count = i;
    MMI_ASSERT(count > 0);
    MMI_ASSERT(applib_mem_ap_get_alloc_count() == count);

    applib_mem_ap_check_integrity();

    tmp = 0;
    for (i = 0; i < count; i++)
    {
        if (i & 0x01)
        {
            /* keep odd ones allocated */
            tmp += ALLOC_SIZE(i);
        }
        else
        {   /* free even ones */
            applib_mem_ap_free(ptr_list[i]);
        }
    }

    MMI_ASSERT(tmp < free_space_original - applib_mem_ap_get_total_left_size());

    applib_mem_ap_check_integrity();

    if (count >= 2)
    {
        for (i = 1; i < count; i += 2)
        {
            MMI_ASSERT(applib_mem_ap_is_valid_block(ptr_list[i]));
        }
    }

    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST2);

    applib_mem_ap_check_integrity();

    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST1);

    applib_mem_ap_check_integrity();

    MMI_ASSERT(free_space_original == applib_mem_ap_get_total_left_size());
    MMI_ASSERT(applib_mem_ap_get_alloc_count() == 0);    

    /* Random alloc/free */

    for (i = 0; i < PTR_LIST_SIZE; i++)
    {
        ptr_list[i] = NULL;
    }

    for (;;)
    {
        kal_int32 key = rand();
        if ((key % 1000) == 0)
        {
            break;
        }
        
        if (applib_mem_ap_get_alloc_count() == PTR_LIST_SIZE || key % 3 == 0)
        {
            i = ((key + 1) % PTR_LIST_SIZE);
            for (; i != key % PTR_LIST_SIZE; i++, i %= PTR_LIST_SIZE)
            {
                if (ptr_list[i])
                {
                    applib_mem_ap_free(ptr_list[i]);
                    ptr_list[i] = NULL;
                    break;
                }
            }
        }
        else
        {
            for (i = 0; i < PTR_LIST_SIZE; i++)
            {
                if (!ptr_list[i])
                {
                    kal_uint32 size = key % applib_mem_ap_get_pool_size();
                    ptr_list[i] = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST1 + (key % 5), size);
                    /* Test memory corruption detection */
                    // ptr_list[i][size/4] = 1;
                    // ptr_list[i][size/4 + 1] = 1;
                    // ptr_list[i][size/4 + 2] = 1;
                    break;
                }
            }
        }
        applib_mem_ap_check_integrity();
    }

    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST1);
    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST2);
    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST3);
    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST4);
    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST5);    
    MMI_ASSERT(free_space_original == applib_mem_ap_get_total_left_size());
    MMI_ASSERT(applib_mem_ap_get_alloc_count() == 0);
}


static void mmi_frm_appmem_unit_test_stop_1_timer_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST1);    
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_TEST1, KAL_TRUE);
}


static void mmi_frm_appmem_unit_test_stop_1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StartTimer(FM_AUTO_TEST_COMMNON_TIMER+APPLIB_MEM_AP_ID_TEST1, 10000, mmi_frm_appmem_unit_test_stop_1_timer_hdlr);
}


static void mmi_frm_appmem_unit_test_stop_2_timer_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST2);
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_TEST2, KAL_TRUE);
}


static void mmi_frm_appmem_unit_test_stop_2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StartTimer(FM_AUTO_TEST_COMMNON_TIMER+APPLIB_MEM_AP_ID_TEST2, 300, mmi_frm_appmem_unit_test_stop_2_timer_hdlr);
}


static void mmi_frm_appmem_unit_test_stop_3_timer_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST3);    
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_TEST3, KAL_TRUE);
}


static void mmi_frm_appmem_unit_test_stop_3(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StartTimer(FM_AUTO_TEST_COMMNON_TIMER+APPLIB_MEM_AP_ID_TEST3, 3000, mmi_frm_appmem_unit_test_stop_3_timer_hdlr);
}


static void mmi_frm_appmem_unit_test_stop_4(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST4);        
    /* Return immediately */   
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_TEST4, KAL_TRUE);
}


static void mmi_frm_appmem_unit_test_stop_5(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Return immediately */
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_TEST5, KAL_FALSE); /* Fail */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_unit_test_success_callback1
 * DESCRIPTION
 *  Callback function when memory was released.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void (*g_mmi_frm_appmem_unit_test_run_callback1)(void *);

static void mmi_frm_appmem_unit_test_success_callback1(void)
{
    mmi_frm_ut_app_entry_arg_struct arg;
    void *ptr = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST1, MMI_FRM_APPMEM_TEST1_SIZE);
    MMI_ASSERT(ptr);

    arg.app_id = APPLIB_MEM_AP_ID_TEST1;
    g_mmi_frm_appmem_unit_test_run_callback1((void *)&arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_unit_test_prepare_to_enter_test1
 * DESCRIPTION
 *  Simple program to test screen-based ASM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_appmem_unit_test_prepare_to_enter_test1(
    void (*run_callback)(void *),
    MMI_BOOL clear_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clear_all)
        applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST1);
    
    g_mmi_frm_appmem_unit_test_run_callback1 = run_callback;
    if (applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST1, MMI_FRM_APPMEM_TEST1_SIZE))
    {
        mmi_frm_ut_app_entry_arg_struct arg;
        arg.app_id = APPLIB_MEM_AP_ID_TEST1;
        run_callback((void *)&arg);
    }
    else
    {
        mmi_frm_appmem_prompt_to_release_mem(
            APPLIB_MEM_AP_ID_TEST1,
            IMG_GLOBAL_L1,
            MMI_FRM_APPMEM_TEST1_SIZE,
            mmi_frm_appmem_unit_test_success_callback1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_unit_test_success_callback2
 * DESCRIPTION
 *  Callback function when memory was released.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void (*g_mmi_frm_appmem_unit_test_run_callback2)(void *);

static void mmi_frm_appmem_unit_test_success_callback2(void)
{
    mmi_frm_ut_app_entry_arg_struct arg;
    void *ptr = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST2, MMI_FRM_APPMEM_TEST2_SIZE);
    MMI_ASSERT(ptr);
    
    arg.app_id = APPLIB_MEM_AP_ID_TEST2;
    g_mmi_frm_appmem_unit_test_run_callback2((void *)&arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_unit_test_prepare_to_enter_test2
 * DESCRIPTION
 *  Simple program to test screen-based ASM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_appmem_unit_test_prepare_to_enter_test2(
    void (*run_callback)(void *),
    MMI_BOOL clear_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clear_all)
        applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST2);

    g_mmi_frm_appmem_unit_test_run_callback2 = run_callback;    
    if (applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST2, MMI_FRM_APPMEM_TEST2_SIZE))
    {
        mmi_frm_ut_app_entry_arg_struct arg;
        arg.app_id = APPLIB_MEM_AP_ID_TEST2;
        run_callback((void *)&arg);

    }
    else
    {
        mmi_frm_appmem_prompt_to_release_mem(
            APPLIB_MEM_AP_ID_TEST2,
            IMG_GLOBAL_L2,
            MMI_FRM_APPMEM_TEST2_SIZE,
            mmi_frm_appmem_unit_test_success_callback2);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_unit_test_success_callback3
 * DESCRIPTION
 *  Callback function when memory was released.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void (*g_mmi_frm_appmem_unit_test_run_callback3)(void *);

static void mmi_frm_appmem_unit_test_success_callback3(void)
{
    mmi_frm_ut_app_entry_arg_struct arg;
    void *ptr = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST3, MMI_FRM_APPMEM_TEST3_SIZE);
    MMI_ASSERT(ptr);

    arg.app_id = APPLIB_MEM_AP_ID_TEST3;
    g_mmi_frm_appmem_unit_test_run_callback3((void *)&arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_unit_test_prepare_to_enter_test3
 * DESCRIPTION
 *  Simple program to test screen-based ASM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_appmem_unit_test_prepare_to_enter_test3(
    void (*run_callback)(void *),
    MMI_BOOL clear_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clear_all)
        applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST3);

    g_mmi_frm_appmem_unit_test_run_callback3 = run_callback;    
    if (applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST3, MMI_FRM_APPMEM_TEST3_SIZE))
    {
        mmi_frm_ut_app_entry_arg_struct arg;
        arg.app_id = APPLIB_MEM_AP_ID_TEST3;
        run_callback((void *)&arg);

    }
    else
    {
        mmi_frm_appmem_prompt_to_release_mem(
            APPLIB_MEM_AP_ID_TEST3,
            IMG_GLOBAL_L3,
            MMI_FRM_APPMEM_TEST3_SIZE,
            mmi_frm_appmem_unit_test_success_callback3);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_unit_test_success_callback4
 * DESCRIPTION
 *  Callback function when memory was released.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void (*g_mmi_frm_appmem_unit_test_run_callback4)(void *);

static void mmi_frm_appmem_unit_test_success_callback4(void)
{
    mmi_frm_ut_app_entry_arg_struct arg;
    void *ptr = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST4, MMI_FRM_APPMEM_TEST4_SIZE);
    MMI_ASSERT(ptr);

    arg.app_id = APPLIB_MEM_AP_ID_TEST4;
    g_mmi_frm_appmem_unit_test_run_callback4((void *)&arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_unit_test_prepare_to_enter_test4
 * DESCRIPTION
 *  Simple program to test screen-based ASM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_appmem_unit_test_prepare_to_enter_test4(
    void (*run_callback)(void *),
    MMI_BOOL clear_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clear_all)
        applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST4);

    g_mmi_frm_appmem_unit_test_run_callback4 = run_callback;    
    if (applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST4, MMI_FRM_APPMEM_TEST4_SIZE))
    {
        mmi_frm_ut_app_entry_arg_struct arg;
        arg.app_id = APPLIB_MEM_AP_ID_TEST4;
        run_callback((void *)&arg);
    }
    else
    {
        mmi_frm_appmem_prompt_to_release_mem(
            APPLIB_MEM_AP_ID_TEST4,
            IMG_GLOBAL_L4,
            MMI_FRM_APPMEM_TEST4_SIZE,
            mmi_frm_appmem_unit_test_success_callback4);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_unit_test_success_callback5
 * DESCRIPTION
 *  Callback function when memory was released.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void (*g_mmi_frm_appmem_unit_test_run_callback5)(void *);

static void mmi_frm_appmem_unit_test_success_callback5(void)
{
    mmi_frm_ut_app_entry_arg_struct arg;
    void *ptr = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST5, MMI_FRM_APPMEM_TEST5_SIZE);
    MMI_ASSERT(ptr);

    arg.app_id = APPLIB_MEM_AP_ID_TEST5;
    g_mmi_frm_appmem_unit_test_run_callback5((void *)&arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_unit_test_prepare_to_enter_test5
 * DESCRIPTION
 *  Simple program to test screen-based ASM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_appmem_unit_test_prepare_to_enter_test5(void (*run_callback)(void *), MMI_BOOL clear_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clear_all)
        applib_mem_ap_free_all(APPLIB_MEM_AP_ID_TEST5);

    g_mmi_frm_appmem_unit_test_run_callback5 = run_callback;    
    if (applib_mem_ap_alloc(APPLIB_MEM_AP_ID_TEST5, MMI_FRM_APPMEM_TEST5_SIZE))
    {
        mmi_frm_ut_app_entry_arg_struct arg;
        arg.app_id = APPLIB_MEM_AP_ID_TEST5;
        run_callback((void *)&arg);
    }
    else
    {
        mmi_frm_appmem_prompt_to_release_mem(
            APPLIB_MEM_AP_ID_TEST5,
            IMG_GLOBAL_L5,
            MMI_FRM_APPMEM_TEST5_SIZE,
            mmi_frm_appmem_unit_test_success_callback5);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_unit_test_setup_environment
 * DESCRIPTION
 *  Setup environment for unit test of app-based ASM 
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void mmi_frm_appmem_ut_register_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static MMI_BOOL first_time = MMI_TRUE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (first_time)
    {
        first_time = MMI_FALSE;
        
        applib_mem_ap_register(
            APPLIB_MEM_AP_ID_TEST1, 
            STR_GLOBAL_1, 
            IMG_GLOBAL_L1, 
            mmi_frm_appmem_unit_test_stop_1);
        applib_mem_ap_register(
            APPLIB_MEM_AP_ID_TEST2, 
            STR_GLOBAL_2, 
            IMG_GLOBAL_L2, 
            mmi_frm_appmem_unit_test_stop_2);
        applib_mem_ap_register(
            APPLIB_MEM_AP_ID_TEST3, 
            STR_GLOBAL_3, 
            IMG_GLOBAL_L3, 
            mmi_frm_appmem_unit_test_stop_3);
        applib_mem_ap_register(
            APPLIB_MEM_AP_ID_TEST4, 
            STR_GLOBAL_4, 
            IMG_GLOBAL_L4, 
            mmi_frm_appmem_unit_test_stop_4);
        applib_mem_ap_register(
            APPLIB_MEM_AP_ID_TEST5, 
            STR_GLOBAL_5, 
            IMG_GLOBAL_L5, 
            mmi_frm_appmem_unit_test_stop_5);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_unit_test_setup_environment
 * DESCRIPTION
 *  Setup unit test environment, register app and go back to idle screen.
 * PARAMETERS
 *  stress_test     [IN]    if need stress test
 * RETURNS
 *  none
 *****************************************************************************/
MMI_BOOL mmi_frm_appmem_unit_test_setup_environment(MMI_BOOL stress_test)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_ut_register_app();

    g_mmi_frm_appmem_ut_break_flow = MMI_FALSE;

    if (stress_test)
        mmi_frm_appmem_unit_test_stress_alloc();

	if (!mmi_idle_is_on_idle_screen())
	{
        mmi_frm_appmem_ut_execute_key_hdlr(KEY_END);
	    StartTimer(KEY_TIMER_ID_NONE+APPLIB_MEM_AP_ID_TEST5, 500, mmi_frm_appmem_ut_regress_test);
        return MMI_FALSE;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_ut_app_entry
 * DESCRIPTION
 *  entry function for APP N
 * PARAMETERS
 *  none
 * RETURNS
 *  none
 *****************************************************************************/
static void mmi_frm_ut_app_entry(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static U16 dynamic_str_idx = STR_GLOBAL_0;
    mmi_frm_ut_app_entry_arg_struct *data = (mmi_frm_ut_app_entry_arg_struct *)arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_entry_new_screen((U16)(GLOBAL_SCR_DUMMY + (dynamic_str_idx - (U16)STR_GLOBAL_0)), NULL, mmi_frm_ut_app_entry, NULL);
    ShowCategory53Screen(
        dynamic_str_idx,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        0,
        NULL,
        NULL,
        NULL,
        0, 0, NULL);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    
    if (dynamic_str_idx < STR_GLOBAL_10)
    {
        dynamic_str_idx++;
    }
    else
    {
        dynamic_str_idx = STR_GLOBAL_0;
    }
    if (!CheckIsBackHistory())
	{
		g_current_running_app = data->app_id;
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_start
 * DESCRIPTION
 *  key handler to start unit-test function
 * PARAMETERS
 *  none
 * RETURNS
 *  none
 *****************************************************************************/
static void mmi_frm_appmem_ut_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* execute selected item */
    if (g_appmem_ut_cntx.selected_item == 0)
    {
        /* update memory info., do nothing here */
    }
    else if (g_appmem_ut_cntx.selected_item == 1)
    {
        mmi_frm_appmem_unit_test_stress_alloc();
    }
    else if (g_appmem_ut_cntx.selected_item >= TEST_ITEM_START)
    {
        if (g_appmem_ut_test_func[g_appmem_ut_cntx.selected_item-TEST_ITEM_START])
        {
            g_appmem_ut_test_func[g_appmem_ut_cntx.selected_item-TEST_ITEM_START](
                    mmi_frm_ut_app_entry, MMI_FALSE);
        }
    }
    
    /* redraw screen to update display info */
    if (GetActiveScreenId() == SCR_FRM_UNIT_TEST)
        mmi_frm_appmem_ut_2nd_entry(g_appmem_ut_cntx.selected_item);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_hilight_hdlr
 * DESCRIPTION
 *  high light handler
 * PARAMETERS
 *  index   [IN]    high-lighted item
 * RETURNS
 *  none
 *****************************************************************************/
static void mmi_frm_appmem_ut_hilight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_appmem_ut_cntx.selected_item = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_2nd_entry
 * DESCRIPTION
 *  display main appmem unit-test screen
 * PARAMETERS
 *  selected_item   [IN]    selected item
 * RETURNS
 *  none
 *****************************************************************************/
static void mmi_frm_appmem_ut_2nd_entry(S32 selected_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 tmp_str[TEST_ITEM_STR_LEN*ENCODING_LENGTH];
    U16 icon_list[TEST_ITEM_NUM+1];
    S32 i;
    U8 *gui_buffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(TEST_ITEM_NUM < (IMG_GLOBAL_LEND-IMG_GLOBAL_LSTART));

    /* update memory info */
    sprintf(tmp_str, "Max. To Alloc: %d", applib_mem_ap_get_max_alloc_size());
    mmi_asc_to_ucs2(g_appmem_ut_cntx.item_list_str[0], tmp_str);

    /* initialize string data for each menu item */
    for (i=0; i<(TEST_ITEM_NUM-TEST_ITEM_START); i++)
    {
        sprintf(tmp_str, "APP %d (%d)", i+1, g_appmem_ut_allocate_size[i]);
        mmi_asc_to_ucs2(g_appmem_ut_cntx.item_list_str[i+TEST_ITEM_START], tmp_str);
        icon_list[TEST_ITEM_START+i] = IMG_GLOBAL_LSTART+(i+1);
    }
    icon_list[TEST_ITEM_NUM] = 0;

    gui_buffer = GetCurrGuiBuffer(SCR_FRM_UNIT_TEST);
    RegisterHighlightHandler(mmi_frm_appmem_ut_hilight_hdlr);

    ShowCategory53Screen(
        0,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        TEST_ITEM_NUM,
        (U8 **)g_appmem_ut_cntx.item_list,
        icon_list,
        NULL,
        0, g_appmem_ut_cntx.selected_item, gui_buffer);

    SetLeftSoftkeyFunction(mmi_frm_appmem_ut_start, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_entry
 * DESCRIPTION
 *  appmem unit-test screen entry function.
 * PARAMETERS
 *  none
 * RETURNS
 *  none
 *****************************************************************************/
void mmi_frm_appmem_ut_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_FRM_UNIT_TEST, NULL, mmi_frm_appmem_ut_entry, NULL);

    mmi_frm_appmem_ut_register_app();

    /* link item string data */
    for (i=0; i<TEST_ITEM_NUM; i++)
    {
        g_appmem_ut_cntx.item_list[i] = g_appmem_ut_cntx.item_list_str[i];
    }

    /* screen display */
    mmi_frm_appmem_ut_2nd_entry(g_appmem_ut_cntx.selected_item);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_execute_key_hdlr
 * DESCRIPTION
 *  Execute key handler with event down and up.
 * PARAMETERS
 *  key_code    [IN]    key code
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_execute_key_hdlr(S16 key_code)
{
    ExecuteCurrKeyHandler(key_code, KEY_EVENT_DOWN);
    ExecuteCurrKeyHandler(key_code, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_start_app
 * DESCRIPTION
 *  Start application registered app asm.
 * PARAMETERS
 *  app_id      [IN]    application id
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_start_app(applib_mem_ap_id_enum app_id)
{
    S32 app_idx = app_id - 1;
    
    if (g_appmem_ut_test_func[app_idx])
    {
        g_appmem_ut_test_func[app_idx](mmi_frm_ut_app_entry, MMI_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_check_app_in_list_int
 * DESCRIPTION
 *  Check if app has allocated app asm and in prompt screen list.
 * PARAMETERS
 *  app_id          [IN]    application id
 *  will_stop_app   [IN]    if need to stop application
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_frm_appmem_ut_check_app_in_list_int(applib_mem_ap_id_enum app_id, MMI_BOOL will_stop_app)
{
    S32 hilite_item, curr_hilit_item;
	curr_hilit_item = GetHighlightedItem();
	hilite_item = curr_hilit_item;
    do {
        if (g_mmi_frm_appmem_prompt_screen->applist[hilite_item].app_id == (kal_uint32)app_id)
        {
            if (will_stop_app)
            {
                /* Select application */
                mmi_frm_appmem_ut_execute_key_hdlr(KEY_LSK);
                /* Stop application */
                mmi_frm_appmem_ut_execute_key_hdlr(KEY_LSK);
            }
            return MMI_TRUE;
        }
        else
        {
            fixed_list_goto_next_item();
			hilite_item = GetHighlightedItem();
            if (curr_hilit_item == hilite_item) 
                break;
        }
    } while(hilite_item < MMI_FRM_APPMEM_MAX_APP_PROMPTED);

	return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_stop_app
 * DESCRIPTION
 *  Stop app which has allocated app asm and in prompt screen list.
 * PARAMETERS
 *  app_id          [IN]    application id
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_frm_appmem_ut_stop_app(applib_mem_ap_id_enum app_id)
{
    return mmi_frm_appmem_ut_check_app_in_list_int(app_id, MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_check_app_in_list
 * DESCRIPTION
 *  Check if app in prompt screen list.
 * PARAMETERS
 *  app_id          [IN]    application id
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_frm_appmem_ut_check_app_in_list(applib_mem_ap_id_enum app_id)
{
    return mmi_frm_appmem_ut_check_app_in_list_int(app_id, MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_app_is_running
 * DESCRIPTION
 *  Check if app is running.
 * PARAMETERS
 *  app_id          [IN]    application id
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_frm_appmem_ut_app_is_running(applib_mem_ap_id_enum app_id)
{
    return (g_current_running_app == app_id) ? MMI_TRUE : MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_go_back_to_idle
 * DESCRIPTION
 *  This api will make sure going back to idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_frm_appmem_ut_go_back_to_idle(void)
{
    mmi_frm_appmem_ut_execute_key_hdlr(KEY_END);

	if (!mmi_idle_is_on_idle_screen())
	{
		StartTimer(KEY_TIMER_ID_NONE, 500, (FuncPtr)mmi_frm_appmem_ut_go_back_to_idle);
        return MMI_FALSE;
    }
    else
    {
        StopTimer(KEY_TIMER_ID_NONE);
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_regress_test
 * DESCRIPTION
 *  If regress test has been broken, use this api to continue to test the following 
 *  test cases with g_mmi_frm_appmem_ut_case_idx.
 *  Moreover, this api will make sure the test case must be launched in idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_regress_test(void)
{
    if (MMI_FALSE == mmi_frm_appmem_ut_go_back_to_idle())
    {
		StartTimer(KEY_TIMER_ID_NONE+APPLIB_MEM_AP_ID_TEST5+1, 3000, mmi_frm_appmem_ut_regress_test);
        return;
    }
    g_mmi_frm_appmem_ut_break_flow = MMI_FALSE;
    mmi_frm_asm_test_case_entry(g_mmi_frm_appmem_ut_case_idx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_reset_context
 * DESCRIPTION
 *  Reset unit test context, free all memory, reset asm manager, go back to idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_reset_context(void)
{
    applib_mem_ap_id_enum app_id;
    
    for (app_id = APPLIB_MEM_AP_ID_TEST1; app_id <= APPLIB_MEM_AP_ID_TEST5; app_id++)
    {
        applib_mem_ap_free_all((kal_uint32)app_id);
    }
    mmi_frm_appmem_reset_asm_manager();

    /* Reset flag which used for each test case */
    g_current_running_app = APPLIB_MEM_AP_ID_DUMMY;
    cancel_cb_is_called = MMI_FALSE;

    if (isIncomingCall())
    {/* Make sure go back to idle from incoming call since it'll invoke some popup screens. */
        //g_mmi_frm_appmem_ut_break_flow = MMI_TRUE;
        StartTimer(KEY_TIMER_ID_NONE+APPLIB_MEM_AP_ID_TEST5+2, 5000, mmi_frm_appmem_ut_regress_test);
    }

    /* Make sure go back to idle screen. */
    mmi_frm_appmem_ut_execute_key_hdlr(KEY_END);
    mmi_frm_appmem_ut_execute_key_hdlr(KEY_END);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_behavior_timer_hdlr
 * DESCRIPTION
 *  Async test timer handler, to check the result of test cases.
 *  If regress test flow has been broken, start timer to continue the test flow.
 *  When the regression test end go back to idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_behavior_timer_hdlr(void)
{
    switch (asm_ut_type)
    {
        case UT_END_PROGRESS_SCRN:
        case UT_UCM_PROGRESS_SCRN:
        case UT_UCM_STARTNEW_SCRN:
        {
            MMI_ASSERT(!mmi_frm_appmem_ut_app_is_running(APPLIB_MEM_AP_ID_TEST4));
            MMI_ASSERT(cancel_cb_is_called);
            break;
        }
        default:
            break;
    }

    if (g_mmi_frm_appmem_ut_regress && g_mmi_frm_appmem_ut_break_flow)
    {
        StartTimer(KEY_TIMER_ID_NONE+APPLIB_MEM_AP_ID_TEST5+4, 100, mmi_frm_appmem_ut_regress_test);
        g_mmi_frm_appmem_ut_break_flow = MMI_FALSE;
    }

    /* Regression test: all cases have been tested, need to reset and go back to idle. */
    if (g_mmi_frm_appmem_ut_regress && g_mmi_frm_appmem_ut_case_idx == -1)
    {
        mmi_frm_appmem_ut_go_back_to_idle();
        g_mmi_frm_appmem_ut_regress = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_end_cancel_cb
 *  mmi_frm_appmem_ut_ucm_cancel_cb
 *  mmi_frm_appmem_ut_back_cancel_cb
 * DESCRIPTION
 * Cancel callback for each unit test.
 * PARAMETERS
 *  info        [IN]    cancel info
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_frm_appmem_ut_end_cancel_cb(mmi_frm_appmem_evt_struct *info)
{
    mmi_frm_appmem_evt_struct *p = info;

    cancel_cb_is_called = MMI_TRUE;
    MMI_ASSERT(p->evt_type == MMI_FRM_APPMEM_CANCEL_BY_END_KEY);
}

static void mmi_frm_appmem_ut_ucm_cancel_cb(mmi_frm_appmem_evt_struct *info)
{
    mmi_frm_appmem_evt_struct *p = info;

    cancel_cb_is_called = MMI_TRUE;
    MMI_ASSERT(p->evt_type == MMI_FRM_APPMEM_CANCEL_BY_UCM_CALL);
}

static mmi_frm_appmem_ut_back_cancel_cb(void *info)
{
    mmi_frm_appmem_evt_struct *p = (mmi_frm_appmem_evt_struct *)info;

    cancel_cb_is_called = MMI_TRUE;
    MMI_ASSERT(p->evt_type == MMI_FRM_APPMEM_CANCEL_BACK_FROM_PROMPT_SCRN);
}

static void mmi_frm_appmem_ut_interrupt_cancel_cb(mmi_frm_appmem_evt_struct *info)
{
    mmi_frm_appmem_evt_struct *p = info;
	
    cancel_cb_is_called = MMI_TRUE;
    MMI_ASSERT(p->evt_type == MMI_FRM_APPMEM_CANCEL_DEL_BY_INTERRUPT);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_end_key_behavior_progress_scrn
 *  mmi_frm_appmem_ut_end_key_behavior_startnew_scrn
 * DESCRIPTION
 * Test END key behavior in asm manager screen. Make sure pressing END key will
 * destroy asm manager at any time.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_appmem_ut_end_key_behavior_progress_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    asm_ut_type = UT_END_PROGRESS_SCRN;
    /* Press END key in progressing screen, app3 will start timer in stop cb to release memory. */

    /* 
     * Step 1: Enter application list screen where we could manipulate each app. 
     */
    mmi_frm_appmem_ut_entry();
    /* 
     * Step 2: Start application 3 which allocate 30k.
     */
    mmi_frm_appmem_ut_start_app(APPLIB_MEM_AP_ID_TEST3);
    MMI_ASSERT(mmi_frm_appmem_ut_app_is_running(APPLIB_MEM_AP_ID_TEST3));
    /* 
     * Step 3: Start application 4 which allocate 4k. The total asm memory is 50k,
     * so asm prompt screen will be showed.
     */
    mmi_frm_appmem_ut_start_app(APPLIB_MEM_AP_ID_TEST4);
    mmi_frm_appmem_set_cancel_callback(APPLIB_MEM_AP_ID_TEST4, mmi_frm_appmem_ut_end_cancel_cb);
    MMI_ASSERT(!cancel_cb_is_called);
    /* 
     * Step 4: Stop app 4 to release memory.
     */
    mmi_frm_appmem_ut_stop_app(APPLIB_MEM_AP_ID_TEST3);
    /* 
     * Step 5: Press END key in progressing screens.
     */
    mmi_frm_appmem_ut_execute_key_hdlr(KEY_END);
    MMI_ASSERT(mmi_idle_is_on_idle_screen());
    MMI_ASSERT(cancel_cb_is_called);
    /* 
     * Since app3 will start timer(3000ms) to launch so that we have to break function flow to check result. 
     * Start new app popup will start timer (2000ms) to invoke success cb.
     */
    g_mmi_frm_appmem_ut_break_flow = MMI_TRUE;
    StartTimer(KEY_TIMER_ID_NONE+APPLIB_MEM_AP_ID_TEST5+5, 2000+3500, mmi_frm_appmem_ut_behavior_timer_hdlr);
}


void mmi_frm_appmem_ut_end_key_behavior_startnew_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Press END key in starting new app screen, app4 will release memory in stop cb directly. */
    mmi_frm_appmem_ut_entry();
    MMI_ASSERT(!mmi_frm_appmem_ut_app_is_running(APPLIB_MEM_AP_ID_TEST4));
    mmi_frm_appmem_ut_start_app(APPLIB_MEM_AP_ID_TEST4);
    MMI_ASSERT(mmi_frm_appmem_ut_app_is_running(APPLIB_MEM_AP_ID_TEST4));
    mmi_frm_appmem_ut_start_app(APPLIB_MEM_AP_ID_TEST3);
    mmi_frm_appmem_set_cancel_callback(APPLIB_MEM_AP_ID_TEST3, mmi_frm_appmem_ut_end_cancel_cb);
    MMI_ASSERT(!cancel_cb_is_called);
    mmi_frm_appmem_ut_stop_app(APPLIB_MEM_AP_ID_TEST4);
    /* Popup timer will be stopped when exit screen, so could check result immediately */
    mmi_frm_appmem_ut_execute_key_hdlr(KEY_END);
    MMI_ASSERT(mmi_idle_is_on_idle_screen());
    MMI_ASSERT(cancel_cb_is_called);
    MMI_ASSERT(!mmi_frm_appmem_ut_app_is_running(APPLIB_MEM_AP_ID_TEST3));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_ut_ucm_behavior_progress_scrn
 *  mmi_frm_appmem_ut_ucm_behavior_startnew_scrn
 * DESCRIPTION
 * Test incoming call behavior in asm manager screen. Make sure incoming call will
 * destroy asm manager at any time to prevent reentry problem.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_appmem_ut_invoke_ucm_call(void)
{
    MYQUEUE Message;
	MMI_INCOMING *data;
	const U8 num_arr[] = {1,3,1,6,4,2,9,2,6,4,9};
	data = OslIntConstructDataPtr(sizeof(mmi_cc_call_ring_ind_struct));
    data->call_id = 1;
    memcpy(data->num.number, num_arr, sizeof(num_arr)/sizeof(num_arr[0]));
    strcpy((char *)data->name, "xiaodong");
    Message.oslMsgId = MSG_ID_MMI_CC_CALL_RING_IND;
    Message.oslDataPtr = (oslParaType*)data;
    Message.oslPeerBuffPtr = NULL;
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_MMI;
    OslMsgSendExtQueue(&Message);
}


void mmi_frm_appmem_ut_ucm_behavior_progress_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    asm_ut_type = UT_UCM_PROGRESS_SCRN;
    mmi_frm_appmem_ut_entry();
    mmi_frm_appmem_ut_start_app(APPLIB_MEM_AP_ID_TEST3);
    MMI_ASSERT(mmi_frm_appmem_ut_app_is_running(APPLIB_MEM_AP_ID_TEST3));
    mmi_frm_appmem_ut_start_app(APPLIB_MEM_AP_ID_TEST4);
    mmi_frm_appmem_set_cancel_callback(APPLIB_MEM_AP_ID_TEST4, mmi_frm_appmem_ut_ucm_cancel_cb);
    MMI_ASSERT(!cancel_cb_is_called);
    mmi_frm_appmem_ut_stop_app(APPLIB_MEM_AP_ID_TEST3);

    mmi_frm_appmem_ut_invoke_ucm_call();
    /* Since app3 will start timer(3000ms) to launch so that we have to break function flow to check result. */
    g_mmi_frm_appmem_ut_break_flow = MMI_TRUE;
    StartTimer(KEY_TIMER_ID_NONE+APPLIB_MEM_AP_ID_TEST5+5, 2000+3500, mmi_frm_appmem_ut_behavior_timer_hdlr);
}


void mmi_frm_appmem_ut_ucm_behavior_startnew_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    asm_ut_type = UT_UCM_STARTNEW_SCRN;
    mmi_frm_appmem_ut_entry();
    mmi_frm_appmem_ut_start_app(APPLIB_MEM_AP_ID_TEST3);
    MMI_ASSERT(mmi_frm_appmem_ut_app_is_running(APPLIB_MEM_AP_ID_TEST3));
    mmi_frm_appmem_ut_start_app(APPLIB_MEM_AP_ID_TEST4);
    mmi_frm_appmem_set_cancel_callback(APPLIB_MEM_AP_ID_TEST4, mmi_frm_appmem_ut_ucm_cancel_cb);
    MMI_ASSERT(!cancel_cb_is_called);
    mmi_frm_appmem_ut_stop_app(APPLIB_MEM_AP_ID_TEST3);
    /* Make incoming call when entering start new app screen. */
    StartTimer(KEY_TIMER_ID_NONE+APPLIB_MEM_AP_ID_TEST5+5, 3000, mmi_frm_appmem_ut_invoke_ucm_call);
    StartTimer(KEY_TIMER_ID_NONE+APPLIB_MEM_AP_ID_TEST5+6, 3000+2500, mmi_frm_appmem_ut_behavior_timer_hdlr);
}

/* MAUI_01606449 */
void mmi_frm_appmem_ut_interrupt_gobacktoidle_invoke_cancelcb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_appmem_ut_entry();
    mmi_frm_appmem_ut_start_app(APPLIB_MEM_AP_ID_TEST3);
    MMI_ASSERT(mmi_frm_appmem_ut_app_is_running(APPLIB_MEM_AP_ID_TEST3));
    mmi_frm_appmem_ut_start_app(APPLIB_MEM_AP_ID_TEST4);
    mmi_frm_appmem_set_cancel_callback(APPLIB_MEM_AP_ID_TEST4, mmi_frm_appmem_ut_interrupt_cancel_cb);
    MMI_ASSERT(!cancel_cb_is_called);
    DisplayPopup(
		(PU8) GetString(STR_GLOBAL_ERROR),
		IMG_GLOBAL_WARNING,
		1,
		1000,
        WARNING_TONE);
	ExecuteRootMainHistoryScreen(NULL);
    MMI_ASSERT(cancel_cb_is_called);
}


/*****************************************************************************  
 * Function for test case driven engine
 *****************************************************************************/
typedef void (*asm_ut_fp)(void);
typedef struct
{
    S8 index;
    asm_ut_fp ut_func;
} _asm_ut_struct;

#define ASM_UT_DB_SIZE  (sizeof(asm_ut_db) / sizeof(asm_ut_db[0]))

static const _asm_ut_struct asm_ut_db[] =
{
    /* Test all cases */
    {0, NULL},
    {1, mmi_frm_appmem_ut_entry},
    {2, mmi_frm_appmem_ut_end_key_behavior_progress_scrn},
    {3, mmi_frm_appmem_ut_end_key_behavior_startnew_scrn},
    {4, mmi_frm_appmem_ut_ucm_behavior_progress_scrn},
    {5, mmi_frm_appmem_ut_ucm_behavior_startnew_scrn},
	{6, mmi_frm_appmem_ut_interrupt_gobacktoidle_invoke_cancelcb},
};

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_asm_test_case_entry
 * DESCRIPTION
 * Asm test case entry function, could be invoked by catcher inject string
 * in mmi_proc_inject_string (events.c).
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_asm_test_case_entry(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    static U8 cur_ut_idx = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_frm_appmem_ut_case_idx = index;

    if (MMI_FALSE == mmi_frm_appmem_unit_test_setup_environment(MMI_FALSE))
    {/* Fail to setup environment - not in idle screen */
        return ;
    }

    if (0 == index)
    {
        /* Test all cases */
        g_mmi_frm_appmem_ut_regress = MMI_TRUE;
        while (cur_ut_idx < ASM_UT_DB_SIZE)
        {
            mmi_frm_appmem_ut_reset_context();
            asm_ut_db[cur_ut_idx].ut_func();
            cur_ut_idx++;
            if (g_mmi_frm_appmem_ut_break_flow)
            {
                break;
            }
        }
    }
    else
    {
        g_mmi_frm_appmem_ut_regress = MMI_FALSE;
        for (i = 1; i < ASM_UT_DB_SIZE; i++)
        {
            if (asm_ut_db[i].index == index && asm_ut_db[i].ut_func)
            {
                mmi_frm_appmem_ut_reset_context();
                if (!g_mmi_frm_appmem_ut_break_flow)
                {
                    asm_ut_db[i].ut_func();
                }
            }
        }
    }

    if (cur_ut_idx == ASM_UT_DB_SIZE && g_mmi_frm_appmem_ut_regress)
    {
        cur_ut_idx = 1;
        g_mmi_frm_appmem_ut_case_idx = -1;
    }
}

#endif /* APPLIB_MEM_UNIT_TEST */


