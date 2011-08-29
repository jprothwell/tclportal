/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*****************************************************************************/
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  Mediamemmgr.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *
 * Author:
 * -------
 * -------
 *                      
 ****************************************************************************/
#ifdef __VRE30_AM__
/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifdef __VRE_AM_08AB__
#define MMI_AP_PROMPT_SCREEN_08A
#endif
#include "MMI_features.h"
#include "GlobalDefs.h"
#include "app_mem.h"
#ifdef MMI_AP_PROMPT_SCREEN_08A
#include "FrameworkGprot.h"
#include "FrameworkProt.h"
#else
#include "mmi_frm_gprot.h"
#include "mmi_frm_prot.h"
#endif
#include "DebugInitDef.h"
#include "CommonScreensEnum.h"
#include "CommonScreens.h"
#include "SettingProfile.h"         /* for tone ID */
#include "mmiapi_func.h"
#include "wgui_categories_popup.h"
#include "CallmanagementGprot.h"    /* Check incoming call */
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
    MMI_AP_STOP_STATE_IGNORE,
    /* Inside mmi_ap_stop_confirm_screen_yes() */
    MMI_AP_STOP_STATE_WAITING,
    /* Stop operation finished inside mmi_ap_stop_confirm_screen_yes() */
    MMI_AP_STOP_STATE_FINISHED
} mmi_ap_stop_state_enum;

/* Context of the prompt screen */
typedef struct 
{
    U16 launchapp_id;
    U16 string_id;
    /* Used inside mmi_ap_stop_confirm_screen_yes() */
    mmi_ap_stop_state_enum stop_state;
    U8 app_id_confirm_to_stop;
    /* Keep SCR_MEDMEM_STOP_PROMPT in history 
       at its exit function. */
    MMI_BOOL keep_prompt_screen_in_history;
    void (*success_callback)(void);
} mmi_ap_prompt_struct;

typedef struct {
    U8 app_id;
    U16 string_id;
    MMI_BOOL ishide;
    //kal_uint32 icon_id;
    U32 mem_size;
    MMI_BOOL is_stopping;
    void (*stop_callback)(void);
} med_mem_ap_usage_struct;

typedef struct 
{
    /* Number of applications using App-based ASM */
    U8 num_app;
    /* Detailed information */
    med_mem_ap_usage_struct applist[MMI_AP_APP_MAX_COUNT_ID];
} mmi_frm_medmem_prompt_screen_struct;

typedef struct{
    KAL_ADM_ID  ext_mem_pool_id;
    kal_uint32   ext_mem_alloc_count;
    kal_uint32   ext_mem_left_size;
}med_ext_mem_struct;
extern med_ext_mem_struct g_med_ext_mem_cntx;

/*****************************************************************************              
 * Local Variable                                                                    
 *****************************************************************************/

/* Life cycle: prompt user to stop applications -> successfully get the memory or cancelled */
static mmi_ap_prompt_struct g_mmi_ap_prompt;
static mmi_frm_medmem_prompt_screen_struct g_applist_info;
static mmi_frm_medmem_prompt_screen_struct *g_applist_info_screen_p;
/*****************************************************************************              
 * Local Function                                                                    
 *****************************************************************************/

/* Prototype declarations: */
static void mmi_ap_entry_prompt_screen(void);
static void mmi_ap_invoke_release_mem_success_callback(void);
static void mmi_ap_stop_finished_handler(MMI_BOOL result);
static void mmi_ap_stop_app_by_highlight_idx(U32 idx);
static U8 med_mem_ap_get_current_usage(med_mem_ap_usage_struct *applist);
/*****************************************************************************
 * FUNCTION
 *  mmi_ap_is_in_prompt_screens
 * DESCRIPTION
 *  Whether MMI is inside prompt screens (SCR_MEDMEM_STOP_PROMPT)
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_ap_is_in_prompt_screens(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 curr_scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_scr_id = GetExitScrnID();
    return curr_scr_id == SCR_MEDMEM_STOP_PROMPT;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ap_is_prompt_screens_in_history
 * DESCRIPTION
 *  Whether a prompt screen (SCR_MEDMEM_STOP_PROMPT)
 *  is inside history.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_ap_is_prompt_screens_in_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return IsScreenPresent(SCR_MEDMEM_STOP_PROMPT);
} 
/*****************************************************************************
 * FUNCTION
 *  mmi_ap_stop_confirm_screen_yes
 * DESCRIPTION
 *  User confirm to stop an application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ap_stop_app_by_highlight_idx(U32 idx)
{
    /*michael stop function*/
    U16 i, highlidx = 0;

    if (g_applist_info.applist[idx].stop_callback) 
    {
        g_applist_info.applist[idx].stop_callback();
    }
    mmi_ap_stop_finished_handler(MMI_TRUE);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ap_stop_confirm_screen_yes
 * DESCRIPTION
 *  User confirm to stop an application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ap_stop_confirm_screen_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_ap_prompt.stop_state = MMI_AP_STOP_STATE_WAITING;

	mmi_ap_stop_app_by_highlight_idx(g_mmi_ap_prompt.app_id_confirm_to_stop);

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_STOP_CONFIRM_YES, 
                g_mmi_ap_prompt.app_id_confirm_to_stop,
                g_mmi_ap_prompt.stop_state);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ap_entry_stop_confirm_screen
 * DESCRIPTION
 *  Ask user to confirm to stop application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ap_entry_stop_confirm_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (UI_string_type) GetString(STR_ID_APPMEM_STOP),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    SetLeftSoftkeyFunction(mmi_ap_stop_confirm_screen_yes, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ap_prompt_screen_get_item
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
#ifdef __VRE_V30__
extern U8 * mmi_am_vre_get_vreapp_name_by_id(U8 native_appid);
#endif
static pBOOL mmi_ap_prompt_screen_get_item(
                S32 item_index, 
                UI_string_type str_buff, 
                PU8 *img_buff_p, 
                U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 size_str[32];
    S8 size_str_ucs2[32 * 2];
    S32 app_name_len;
    U16 display_id;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __VRE_V30__
    if (g_applist_info_screen_p->applist[item_index].app_id >= MMI_AP_VRE_APP1_ID
         && g_applist_info_screen_p->applist[item_index].app_id <= MMI_AP_VRE_APP16_ID)
    {
        mmi_ucs2ncpy((S8*) str_buff, (S8*)mmi_am_vre_get_vreapp_name_by_id(g_applist_info_screen_p->applist[item_index].app_id), 
                 (MAX_SUB_MENU_SIZE / 2));
    }
    else
    #endif
    {
        mmi_ucs2ncpy((S8*) str_buff, GetString(g_applist_info_screen_p->applist[item_index].string_id), 
                 (MAX_SUB_MENU_SIZE / 2));
    }
    
    app_name_len = mmi_ucs2strlen((S8*) str_buff);

    sprintf((char*) size_str, " (%d K)", g_applist_info_screen_p->applist[item_index].mem_size);//g_applist_info.applist[i].mem_size);
    mmi_asc_to_ucs2(size_str_ucs2, size_str);
    mmi_ucs2ncpy(
            (S8*) str_buff + (app_name_len * 2), 
            size_str_ucs2, 
            (MAX_SUB_MENU_SIZE / 2) - app_name_len);

    
    *img_buff_p = (PU8) GetImage(IMG_GLOBAL_L1 + item_index);
    
	return (pBOOL) MMI_TRUE;
}
#ifdef MMI_AP_PROMPT_SCREEN_08A
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_ap_prompt_screen_init_info
 * DESCRIPTION
 *  Initialize the info box
 * PARAMETERS
 *  void
 * RETURNS
 *  The minimum height of info box
 *****************************************************************************/
static S32 mmi_frm_ap_prompt_screen_init_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 msg_length;
    UI_string_type msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (UI_string_type) GetString(STR_ID_APPMEM_PROMPT_STOP_APP);
    msg_length = gui_strlen(msg);

    create_multiline_inputbox_set_buffer(msg, msg_length, msg_length, 0);
    resize_multiline_inputbox(UI_device_width, UI_device_height);
    
    MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW | 
        UI_MULTI_LINE_INPUT_BOX_VIEW_MODE | UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR;

    show_multiline_inputbox_no_draw();

    /* Add (get_multiline_inputbox_line_height() / 4) for extra spacing */
    return get_multiline_inputbox_line_height() * MMI_multiline_inputbox.n_lines +
           MMI_multiline_inputbox.text_y + (get_multiline_inputbox_line_height() / 4);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_ap_prompt_screen_draw_info
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
static void mmi_ap_prompt_screen_draw_info(S32 idx, S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    move_multiline_inputbox(x1, y1);
    resize_multiline_inputbox(x2 - x1 + 1, y2 - y1 + 1);
    show_multiline_inputbox_no_draw();

    show_multiline_inputbox();
}
#else
static void mmi_ap_prompt_screen_draw_info(S32 idx, S32 x1, S32 y1, S32 x2, S32 y2)
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
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_ap_prompt_screen_hide_info
 * DESCRIPTION
 *  Callback function to hide the info box of prompt screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ap_prompt_screen_hide_info(void)
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
 *  mmi_ap_prompt_screen_stop_highlighted
 * DESCRIPTION
 *  Stop the current highlighted medlication
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ap_prompt_screen_stop_highlighted(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 highlited_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_ASSERT(GetExitScrnID() == SCR_MEDMEM_STOP_PROMPT);

    highlited_item = GetHighlightedItem();
    g_mmi_ap_prompt.app_id_confirm_to_stop = g_applist_info_screen_p->applist[highlited_item].app_id;//highlited_item;
    
    mmi_ap_entry_stop_confirm_screen();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ap_prompt_screen_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of prompt screen
 * PARAMETERS
 *  item_index  [IN]    currently highlighted menu index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ap_prompt_screen_highlight_hdlr(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (g_applist_info.num_app == 0)
    {
        return;
    }
    
    ChangeLeftSoftkey(STR_GLOBAL_STOP, 0);
    SetLeftSoftkeyFunction(mmi_ap_prompt_screen_stop_highlighted, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ap_exit_prompt_screen
 * DESCRIPTION
 *  Exit function of prompt screen 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ap_exit_prompt_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (g_mmi_ap_prompt.keep_prompt_screen_in_history)
    {
        h.scrnID = SCR_MEDMEM_STOP_PROMPT;
        h.entryFuncPtr = mmi_ap_entry_prompt_screen;
        mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) L"");
        GetCategoryHistory(h.guiBuffer);
    
        AddHistory(h);
    }
    if (g_applist_info_screen_p)
    {
        OslMfree(g_applist_info_screen_p);
        g_applist_info_screen_p = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ap_entry_prompt_screen
 * DESCRIPTION
 *  Entry function of prompt screen to stop other applications
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ap_entry_prompt_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 info_box_height;
    MMI_BOOL bShowPromptScr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_ENTRY_PROMPT_SCREEN, bShowPromptScr);

    //bShowPromptScr = mmi_is_redrawing_bk_screens();
    //if (bShowPromptScr)
    if(g_applist_info.num_app > 0)
    {

        g_applist_info_screen_p = OslMalloc(sizeof(mmi_frm_medmem_prompt_screen_struct));

        g_applist_info_screen_p->num_app = med_mem_ap_get_current_usage(g_applist_info_screen_p->applist);

        if (g_applist_info_screen_p->num_app == 0) 
        {
            if (g_applist_info_screen_p)
            {
                OslMfree(g_applist_info_screen_p);
                g_applist_info_screen_p = NULL;
            }
            DisplayPopup(
                		(PU8) GetString(STR_GLOBAL_INSUFFICIENT_MEMORY),
                		IMG_GLOBAL_WARNING,
                		1,
                		1000,
                        WARNING_TONE);
            return;
        }
        EntryNewScreen(SCR_MEDMEM_STOP_PROMPT, mmi_ap_exit_prompt_screen, NULL, NULL);     

        guiBuffer = GetCurrGuiBuffer(SCR_MEDMEM_STOP_PROMPT);

        //g_applist_info_screen_p = OslMalloc(sizeof(mmi_frm_medmem_prompt_screen_struct));

        //g_applist_info_screen_p->num_app = med_mem_ap_get_current_usage(g_applist_info_screen_p->applist);

#ifdef MMI_AP_PROMPT_SCREEN_08A
        info_box_height = mmi_frm_ap_prompt_screen_init_info();    
#else
        info_box_height = MMI_MENUITEM_HEIGHT + 4;        
#endif    

        RegisterHighlightHandler(mmi_ap_prompt_screen_highlight_hdlr);
        
        ShowCategory211Screen(
            STR_GLOBAL_INSUFFICIENT_MEMORY,
            0, 
            STR_GLOBAL_STOP,
            0, 
            STR_GLOBAL_BACK, 
            0, 
            g_applist_info_screen_p->num_app,//g_applist_info.num_app, 
            mmi_ap_prompt_screen_get_item, 
            NULL, 
            mmi_ap_prompt_screen_draw_info,
            mmi_ap_prompt_screen_hide_info,
            info_box_height,            /* Info box height */
            0,                          /* Background image of info box */
            0,                          /* Highlight item index */
            guiBuffer);

       SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
    else
    {
        DisplayPopup(
		(PU8) GetString(STR_GLOBAL_INSUFFICIENT_MEMORY),
		IMG_GLOBAL_WARNING,
		1,
		1000,
        WARNING_TONE);
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_ap_invoke_release_mem_success_callback
 * DESCRIPTION
 *  Invoke the calling medlication there is enough memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ap_invoke_release_mem_success_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* Enter another screen by registered callback function */
    g_mmi_ap_prompt.keep_prompt_screen_in_history = MMI_FALSE;
    g_mmi_ap_prompt.success_callback();
    /*#ifndef __VRE_AM_09A__
    if(g_mmi_ap_prompt.launchapp_id >= MMI_AP_VRE_APP1_ID && g_mmi_ap_prompt.launchapp_id <= MMI_AP_VRE_APP16_ID)
    {
        GoBackHistory();
    }
    #endif*/
    //DeleteScreenIfPresent(SCR_MEDMEM_STOP_PROMPT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ap_stop_finished_handler
 * DESCRIPTION
 *  Callback handler when an medlication finished stop operation
 * PARAMETERS
 *  med_id      [IN]    ID of the medlication to be stopped
 *  string_id   [IN]    Name of the medlication to be stopped
 *  result      [IN]    whether the stop operation suceeds or not
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_ap_stop_finished_handler(MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ap_is_in_prompt_screens() ||
        g_mmi_ap_prompt.stop_state == MMI_AP_STOP_STATE_WAITING) /* In confirm screen */
    {
        U32 msgId;
        U16 icon;
        U8 tone;
        FuncPtr callback;
        
		msgId = STR_ID_APPMEM_NOTIFY_STARTING_NEW;
        icon = IMG_GLOBAL_INFO;
        tone = SUCCESS_TONE;        
        callback = mmi_ap_invoke_release_mem_success_callback;
        if (g_mmi_ap_prompt.success_callback == NULL)
        {
#ifdef MMI_AP_PROMPT_SCREEN_08A
              DisplayPopupCallBack((U8*)GetString(STR_GLOBAL_PLEASE_WAIT), 
                    icon, 0, UI_POPUP_NOTIFYDURATION_TIME_2000, tone, GoBackHistory); 
#else
            mmi_display_popupcallback(
            (UI_string_type)GetString(STR_GLOBAL_PLEASE_WAIT),
            MMI_EVENT_INFO,
            GoBackHistory);
#endif           
        }
        else
        {
            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_STOP_FINISHED_HANDLER, msgId, callback);
#ifdef MMI_AP_PROMPT_SCREEN_08A
            DisplayPopupCallBack((U8*)GetString(STR_ID_APPMEM_NOTIFY_STARTING_NEW), 
                    icon, 0, UI_POPUP_NOTIFYDURATION_TIME_2000, tone, callback);
#else
            mmi_display_popupcallback(
            (UI_string_type)GetString(STR_ID_APPMEM_NOTIFY_STARTING_NEW),
            MMI_EVENT_INFO,
            callback);
#endif 
            mmi_frm_block_general_interrupt_event(MMI_FRM_INT_TOTAL_INTERRUPT_EVENT);
        }
        DeleteScreenIfPresent(SCR_MEDMEM_STOP_PROMPT);
        if (g_mmi_ap_prompt.stop_state == MMI_AP_STOP_STATE_WAITING)
        {
            g_mmi_ap_prompt.stop_state = MMI_AP_STOP_STATE_FINISHED;
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
 * FUNCTION
 *  mmi_ap_prompt_to_release_mem
 * DESCRIPTION
 *  Show "out-of-memory" screen and prompt user to stop other medlications in order 
 *  to release more memory.
 *
 *  Remark: 
 *  1. This function is not suggested to be used in "interrupt screens" 
 *     (e.g. MT call or USB plug-in indication)
 *     Otherwise, it might re-enter the prompt screen and confuse user.
 *  2. 'success_callback' needs to enter a new MMI screen!
 *  3. There is no "failure callback" due to complex interaction of MMI screens.
 *     Applications that use this function should never adopt any explicit or 
 *     implicit "waiting" state for the result.
 *
 *     For example, user may press End key in the "out-of-memory" screen and
 *     try to enter the medlication again. 
 *
 *  Warning: This function can only be used in MMI task.
 * PARAMETERS
 *  app_name            [IN]    String ID of the application 
 *  app_icon            [IN]    Image ID of the application 
 *  required_size       [IN]    Minimum required memory for the application
 *  success_callback    [IN]    Callback function when getting memory successfully 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ap_prompt_to_release_mem(U8 app_id, U16 string_id, U32 req_buffer_size, void (*success_callback)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //if(!med_check_memory_is_enough(req_buffer_size))
    {
        g_mmi_ap_prompt.launchapp_id = app_id;
        g_mmi_ap_prompt.stop_state = MMI_AP_STOP_STATE_IGNORE;
        g_mmi_ap_prompt.keep_prompt_screen_in_history = MMI_TRUE;
        g_mmi_ap_prompt.success_callback = success_callback;
        
        mmi_ap_entry_prompt_screen();
    }
}
/*****************************************************************************
 * FUNCTION
 *  med_mem_ap_register
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p_node      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef WIN32
kal_uint32 g_ext_mem_left_size = 3500*1024;
#endif
MMI_BOOL med_check_memory_is_enough(U32 req_buffer_size)
{
    MMI_BOOL result = MMI_TRUE;
    kal_uint32 ext_mem_left_size;
    kal_char test[100];
    #ifdef WIN32
    ext_mem_left_size = g_ext_mem_left_size;//3500*1024;
    #else
    ext_mem_left_size = kal_adm_get_total_left_size(g_med_ext_mem_cntx.ext_mem_pool_id);
    #endif
    kal_sprintf(test,"size:%d", ext_mem_left_size/1024);
    kal_print(test);
    if (req_buffer_size > ext_mem_left_size) 
    {
        result = MMI_FALSE;  
    }
    if(g_applist_info.num_app==0)
    {
    		result = MMI_TRUE;
    }
    return result;
}
/*****************************************************************************
 * FUNCTION
 *  med_mem_ap_register
 * DESCRIPTION
 *    register the running app infomation(stringid, memory size, stop callback function), 
 * when start the new app using media buffer
 * PARAMETERS
 *  p_node      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
/*michael 100415 begin*/
void med_mem_ap_register(U8 app_id, U16 app_string_id, U32 mem_size, void (*reg_stop_callback)(void))
{
    U16 i;
    
     g_applist_info.applist[app_id].mem_size       = mem_size/1024;
     g_applist_info.applist[app_id].string_id      = app_string_id;
     g_applist_info.applist[app_id].stop_callback  = reg_stop_callback;
     g_applist_info.num_app++;
}
/*****************************************************************************
 * FUNCTION
 *  med_mem_ap_deregister
 * DESCRIPTION
 * deregister the runing app infomation when exit the last runing app 
 * PARAMETERS
 *  p_node      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void med_mem_ap_deregister(U8 app_id)
{
    U16 i;
    
    g_applist_info.applist[app_id].string_id      = 0;
    g_applist_info.applist[app_id].mem_size       = 0;
    g_applist_info.applist[app_id].stop_callback  = NULL;
    g_applist_info.num_app--;
    #ifdef WIN32
    g_ext_mem_left_size = 4000*1024;
    #endif
}
void med_mem_ap_set_hide_list_screen(U8 hide_appid)
{
    g_applist_info.applist[hide_appid].ishide  = MMI_TRUE;
}

void med_mem_ap_clear_hide_list_screen(U8 hide_appid)
{
    g_applist_info.applist[hide_appid].ishide  = MMI_FALSE;
}
/*****************************************************************************
 * FUNCTION
 *  med_mem_ap_get_current_usage
 * DESCRIPTION
 *  List memory consumption by current applications 
 *  (The API is used by MMI framework only) 
 * PARAMETERS
 *  applist     [OUT]    List of applications and its memory consumption
 *  max_items   [IN]     The maximum size of 'applist'
 * RETURNS
 *  the number of applications listed
 *****************************************************************************/
U8 med_mem_ap_get_current_usage(med_mem_ap_usage_struct *applist)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 item_count = 0, app_id = MMI_AP_DUMMY_ID;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (app_id = 0; app_id < MMI_AP_APP_MAX_COUNT_ID; app_id++)
    {
         if (g_applist_info.applist[app_id].string_id != 0 && g_applist_info.applist[app_id].ishide != MMI_TRUE)
         {
              applist[item_count].app_id =  app_id;
              applist[item_count].string_id = g_applist_info.applist[app_id].string_id;
              applist[item_count].mem_size = g_applist_info.applist[app_id].mem_size;
              applist[item_count++].stop_callback = g_applist_info.applist[app_id].stop_callback;
        }
    }
    return  item_count;
}
#endif
