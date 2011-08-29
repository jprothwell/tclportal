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
 *  AMPromptScreen.c
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
#include "MMI_features.h"
//#include "mmi_frm_gprot.h"
#include "GlobalDefs.h"
#include "app_mem.h"
//#include "mmi_frm_prot.h"
#include "DebugInitDef.h"
#include "CommonScreensEnum.h"
#include "CommonScreens.h"
#include "SettingProfile.h"         /* for tone ID */
#include "wgui_categories_fmgr.h"   /* Category 212 */
#include "mmiapi_func.h"
#include "wgui_categories_popup.h"
#include "CallmanagementGprot.h"    /* Check incoming call */
/* VRE Core Header File */
#include "vmenv.h"
#include "vmsys.h"
#include "vmcert.h"
#include "vmmullang.h"
#include "vmgettag.h"

#include "AMResDef.h"   /* Add AM head file */
#include "AMDef.h"      /* Add AM head file */
#include "AMGprot.h"    /* Add AM head file */
#include "AMprot.h"     /* Add AM head file */
#include "AMUtil.h"
#include "AMMainScreen.h"
/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MMI_AM_MAX_APP_PROMPTED     (5)
#ifdef __VRE_AM_08AB__
#define MMI_PROMPT_SCREEN_08A
#endif
//#define QUICK_START_MEM_MALLOC
/***************************************************************************** 
 * Typedef 
 *****************************************************************************/

/* States of mmi_frm_appmem_stop_confirm_screen_yes() */
typedef enum
{
    /* Normal case */
    MMI_AM_STOP_STATE_IGNORE,
    /* Inside mmi_am_stop_confirm_screen_yes() */
    MMI_AM_STOP_STATE_WAITING,
    /* Stop operation finished inside mmi_am_stop_confirm_screen_yes() */
    MMI_AM_STOP_STATE_FINISHED
} mmi_am_stop_state_enum;

/* Context of the prompt screen */
typedef struct 
{
    /* Used inside mmi_am_stop_confirm_screen_yes() */
    mmi_am_stop_state_enum stop_state;
    U32 app_id_confirm_to_stop;
    /* Keep SCR_ID_AM_STOP_LIST in history 
       at its exit function. */
    MMI_BOOL keep_prompt_screen_in_history;
    void (*success_callback)(void);
} mmi_am_prompt_struct;

/*****************************************************************************              
 * Local Variable                                                                    
 *****************************************************************************/

/* Life cycle: prompt user to stop applications -> successfully get the memory or cancelled */
static mmi_am_prompt_struct g_mmi_am_prompt;
static MMI_BOOL g_is_out_of_memory_flag = MMI_TRUE;
extern sml_list_t *g_run_app_list;
extern mmi_am_quick_start_struct g_am_qs_cntx;
extern mmi_am_cntx_struct g_am_cntx;
MMI_BOOL g_is_delete_deinit = MMI_TRUE;
/*vogins_20100721_start*/
extern mmi_am_relaunch_struct g_am_relaunch_cntx;
/*****************************************************************************              
 * Local Function                                                                    
 *****************************************************************************/

/* Prototype declarations: */
static void mmi_am_entry_prompt_screen(void);
static void mmi_am_back_prompt_screen(void);
#ifdef AM_09A
static void mmi_am_invoke_release_mem_success_callback(void);
#else
static mmi_ret mmi_am_invoke_release_mem_success_callback(mmi_event_struct *param);
#endif
static void mmi_am_stop_finished_handler(MMI_BOOL result);
static void mmi_am_stop_app_by_highlight_idx(U32 idx);
#ifdef AM_09A
static U8 mmi_am_destroy_prompt_scrn(void *param);
#else 
static mmi_ret mmi_am_leave_prompt_scrn(mmi_event_struct *evt);
#endif
#ifdef QUICK_START_MEM_MALLOC
extern void mmi_am_free_app_running_infos(void);
#endif
extern void mmi_am_ms_set_app_bg_running_by_path(U16 *app_path, MMI_BOOL is_bg_running);
/*****************************************************************************
 * FUNCTION
 *  mmi_am_is_in_prompt_screens
 * DESCRIPTION
 *  Whether MMI is inside prompt screens (SCR_ID_AM_STOP_LIST)
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_am_is_in_prompt_screens(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 curr_scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_scr_id = GetExitScrnID();
    return curr_scr_id == SCR_ID_AM_STOP_LIST;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_is_prompt_screens_in_history
 * DESCRIPTION
 *  Whether a prompt screen (SCR_ID_AM_STOP_LIST)
 *  is inside history.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_am_is_prompt_screens_in_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return IsScreenPresent(SCR_ID_AM_STOP_LIST);
} 
/*****************************************************************************
 * FUNCTION
 *  mmi_am_stop_confirm_screen_yes
 * DESCRIPTION
 *  User confirm to stop an application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_stop_app_by_highlight_idx(U32 idx)
{
    /*michael stop function*/
    int ret = -1, i;
    mmi_am_ms_app_struct *applistinfo;

    g_is_delete_deinit = MMI_TRUE;		
    applistinfo = sml_list_get(g_run_app_list, idx);

    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "[AMVRE]Stop VRE handler");
    
    if (applistinfo->path != NULL) 
    {
        ret = vm_terminate_bg_app((VMWSTR)applistinfo->path);
    }
    

    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "[AMVRE]Stop VRE handler ret:%d",ret);
    if(ret == VM_TERMINATE_SUCCESS)
    {  
          g_is_delete_deinit = MMI_FALSE;
          mmi_am_ms_set_app_bg_running_by_path(applistinfo->path, MMI_FALSE);
          mmi_am_stop_finished_handler(MMI_TRUE);
        
        #ifdef QUICK_START_MEM_MALLOC
        mmi_am_free_app_running_infos();
        #else
        mmi_am_ms_release_run_app_list();
        #endif
      }
	else
	{
        #ifdef AM_09A
        if(!IsScreenPresent(SCR_ID_AM_MAIN))
        {
             g_am_qs_cntx.is_quick_start = MMI_FALSE;
             g_am_qs_cntx.quick_start_flag = START_FROM_NONE;
             mmi_am_grp_deinit();
        }
        #endif
		mmi_display_popup((UI_string_type) GetString(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE);
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_am_stop_confirm_screen_yes
 * DESCRIPTION
 *  User confirm to stop an application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_stop_confirm_screen_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_am_prompt.stop_state = MMI_AM_STOP_STATE_WAITING;
    g_am_relaunch_cntx.am_relaunch_tag = MMI_TRUE;
	mmi_am_stop_app_by_highlight_idx(g_mmi_am_prompt.app_id_confirm_to_stop);

    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_STOP_CONFIRM_YES, 
                g_mmi_am_prompt.app_id_confirm_to_stop,
                g_mmi_am_prompt.stop_state);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_entry_stop_confirm_screen
 * DESCRIPTION
 *  Ask user to confirm to stop application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_entry_stop_confirm_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MMI_PROMPT_SCREEN_08A
    mmi_display_popup_confirm_with_sg(
        GRP_ID_AM,
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        get_string(STR_ID_APPMEM_STOP),
        MMI_EVENT_QUERY,
        0);
#else
    mmi_display_popup_confirm_with_sg(
        GRP_ID_AM,
        get_string(STR_GLOBAL_YES),
        get_image(IMG_GLOBAL_YES),
        get_string(STR_GLOBAL_NO),
        get_image(IMG_GLOBAL_NO),
        get_string(STR_ID_APPMEM_STOP),
        MMI_EVENT_QUERY,
        0);
#endif
    SetLeftSoftkeyFunction(mmi_am_stop_confirm_screen_yes, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_prompt_screen_get_item
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
static pBOOL mmi_am_prompt_screen_get_item(
                S32 item_index, 
                UI_string_type str_buff, 
                PU8 *img_buff_p, 
                U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_am_ms_app_struct *applist = NULL;
    S8 size_str[32];
    S8 size_str_ucs2[32 * 2];
    S32 app_name_len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "[AM]prompt screen getitem ---S");
    applist = sml_list_get(g_run_app_list, item_index);
    if (applist == NULL) 
    {
        return (pBOOL) MMI_FALSE;
    }

    if (applist->p_name == NULL) 
    {
        mmi_ucs2ncpy((S8*) str_buff, GetString(STR_ID_AM_APP_NAME_DEFAULT), 
                 (MAX_SUB_MENU_SIZE / 2));
    }
    else
    {
        mmi_ucs2ncpy((S8*) str_buff, (S8*)applist->p_name, 
                 (MAX_SUB_MENU_SIZE / 2));
    }
    app_name_len = mmi_ucs2strlen((S8*) str_buff);

    sprintf((char*) size_str, " (%d K)", applist->bg_memory_size);
    mmi_asc_to_ucs2(size_str_ucs2, size_str);
    mmi_ucs2ncpy(
            (S8*) str_buff + (app_name_len * 2), 
            size_str_ucs2, 
            (MAX_SUB_MENU_SIZE / 2) - app_name_len);

    /*if (applist->p_icon == NULL) 
    {
        *img_buff_p = (PU8) GetImage(IMG_ID_AM_APP_DEFAULT);
    }
    else*/
    {
        *img_buff_p = (PU8) GetImage(IMG_GLOBAL_L1 + item_index);
    }
	MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "[AM]prompt screen get item---E");
    return (pBOOL) MMI_TRUE;
}
#ifdef MMI_PROMPT_SCREEN_08A
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_am_prompt_screen_init_info
 * DESCRIPTION
 *  Initialize the info box
 * PARAMETERS
 *  void
 * RETURNS
 *  The minimum height of info box
 *****************************************************************************/
static S32 mmi_frm_am_prompt_screen_init_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 msg_length;
    UI_string_type msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (UI_string_type) GetString(STR_ID_AM_PROMPT_APPLICATION);
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
 *  mmi_am_prompt_screen_draw_info
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
static void mmi_am_prompt_screen_draw_info(S32 idx, S32 x1, S32 y1, S32 x2, S32 y2)
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

static void mmi_am_prompt_screen_draw_info(S32 idx, S32 x1, S32 y1, S32 x2, S32 y2)
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
    msg = (UI_string_type) GetString(STR_ID_AM_PROMPT_APPLICATION/*STR_ID_APPMEM_PROMPT_STOP_APP*/);
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
 *  mmi_am_prompt_screen_hide_info
 * DESCRIPTION
 *  Callback function to hide the info box of prompt screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_prompt_screen_hide_info(void)
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
 *  mmi_am_prompt_screen_stop_highlighted
 * DESCRIPTION
 *  Stop the current highlighted medlication
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_prompt_screen_stop_highlighted(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 highlited_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    
    highlited_item = GetHighlightedItem();
    g_mmi_am_prompt.app_id_confirm_to_stop = highlited_item;
    
    mmi_am_entry_stop_confirm_screen();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_am_prompt_screen_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of prompt screen
 * PARAMETERS
 *  item_index  [IN]    currently highlighted menu index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_prompt_screen_highlight_hdlr(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (sml_list_size(g_run_app_list) == 0)//(g_running_app_num == 0)
    {
        return;
    }
    
    ChangeLeftSoftkey(STR_GLOBAL_STOP, 0);
    SetLeftSoftkeyFunction(mmi_am_prompt_screen_stop_highlighted, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_exit_prompt_screen
 * DESCRIPTION
 *  Exit function of prompt screen 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_exit_prompt_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (g_mmi_am_prompt.keep_prompt_screen_in_history)
    {
        h.scrnID = SCR_ID_AM_STOP_LIST;
        h.entryFuncPtr = mmi_am_entry_prompt_screen;
        mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) L"");
        GetCategoryHistory(h.guiBuffer);
    
        AddHistory(h);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_entry_prompt_screen
 * DESCRIPTION
 *  Entry function of prompt screen to stop other applications
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_eixt_prompt_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}
static void mmi_am_entry_prompt_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 info_box_height;
    MMI_BOOL bShowPromptScr;
    MMI_BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_ENTRY_PROMPT_SCREEN, bShowPromptScr);
    g_is_delete_deinit = MMI_TRUE;
    //bShowPromptScr = mmi_is_redrawing_bk_screens();
    //if (bShowPromptScr)
    {
        #ifdef AM_09A
        ret = mmi_frm_scrn_enter(GRP_ID_AM, SCR_ID_AM_STOP_LIST, mmi_am_exit_prompt_screen, NULL, NULL);
        #else
        ret = mmi_frm_scrn_enter(GRP_ID_AM, SCR_ID_AM_STOP_LIST, mmi_am_eixt_prompt_scrn, mmi_am_entry_prompt_screen, NULL);
        #endif
        if (ret == MMI_FALSE)
        {
            return;
        }
        guiBuffer = mmi_frm_scrn_get_active_gui_buf();

#ifdef MMI_PROMPT_SCREEN_08A
        info_box_height = mmi_frm_am_prompt_screen_init_info();     
#else
        info_box_height = MMI_MENUITEM_HEIGHT + 4;        
#endif   

        RegisterHighlightHandler(mmi_am_prompt_screen_highlight_hdlr);
        
        ShowCategory211Screen(
            (g_is_out_of_memory_flag == MMI_TRUE
            	? STR_GLOBAL_INSUFFICIENT_MEMORY : STR_ID_AM_EXCEED_MAX_APP_NUM),
            0, 
            STR_GLOBAL_STOP,
            0, 
            STR_GLOBAL_BACK, 
            0, 
            sml_list_size(g_run_app_list),//g_running_app_num, 
            mmi_am_prompt_screen_get_item, 
            NULL, 
            mmi_am_prompt_screen_draw_info,
            mmi_am_prompt_screen_hide_info,
            info_box_height,            /* Info box height */
            0,                          /* Background image of info box */
            0,                          /* Highlight item index */
            guiBuffer);
#ifdef AM_09A
    #ifdef MMI_PROMPT_SCREEN_08A
    SetDelScrnIDCallbackHandler(SCR_ID_AM_STOP_LIST, (HistoryDelCBPtr) mmi_am_destroy_prompt_scrn);
    #else
    mmi_frm_set_destroy_scrn_callback(SCR_ID_AM_STOP_LIST, (HistoryDelCBPtr) mmi_am_destroy_prompt_scrn);
    #endif
#else /* AM_09A */ 
    /* set leave proc */
    mmi_frm_scrn_set_leave_proc(GRP_ID_AM, SCR_ID_AM_STOP_LIST, mmi_am_leave_prompt_scrn);
#endif /* AM_09A */

       SetRightSoftkeyFunction(mmi_am_back_prompt_screen, KEY_EVENT_UP);
    }
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "[AM] entry prompt screen end---");;
}
#ifdef AM_09A
/*****************************************************************************
 * FUNCTION
 *  mmi_am_destroy_prompt_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_am_destroy_prompt_scrn(void *param)
{
    #ifdef QUICK_START_MEM_MALLOC
    mmi_am_free_app_running_infos();
    #else
    mmi_am_ms_release_run_app_list();
    #endif
    if(!IsScreenPresent(SCR_ID_AM_MAIN) && g_is_delete_deinit != MMI_FALSE)
    {
        MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "[AMVRE11]deinit test");
        g_am_qs_cntx.is_quick_start = MMI_FALSE;
        g_am_qs_cntx.quick_start_flag = START_FROM_NONE;
        mmi_am_grp_deinit();
    }
}
#else
/*****************************************************************************
 * FUNCTION
 *  mmi_am_leave_main_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_am_leave_prompt_scrn(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_MS_LEAVE_SCREEN, evt->evt_id);

    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_DELETE_REQ:
            break;

        case EVT_ID_SCRN_DEINIT:
             #ifdef QUICK_START_MEM_MALLOC
             mmi_am_free_app_running_infos();
             #else
             mmi_am_ms_release_run_app_list();
             #endif
            break;
    }

    return ret;
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_am_back_prompt_screen
 * DESCRIPTION
 *  Entry function of prompt screen to stop other applications
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_back_prompt_screen(void)
{
    #ifdef QUICK_START_MEM_MALLOC
    mmi_am_free_app_running_infos();
    #else
    mmi_am_ms_release_run_app_list();
    #endif
    #ifdef AM_09A
    if(!IsScreenPresent(SCR_ID_AM_MAIN))
    { 
        MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "[AMVRE11]deinit test");
        g_am_qs_cntx.is_quick_start = MMI_FALSE;
        g_am_qs_cntx.quick_start_flag = START_FROM_NONE;
        mmi_am_grp_deinit();
    }
    #endif
    GoBackHistory();
}
/*****************************************************************************
 * FUNCTION
 *  mmi_am_invoke_release_mem_success_callback
 * DESCRIPTION
 *  Invoke the calling medlication there is enough memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef AM_09A
static void mmi_am_invoke_release_mem_success_callback(void)
#else
static mmi_ret mmi_am_invoke_release_mem_success_callback(mmi_event_struct *param)
#endif
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "[VRE]success callback function");
	/* Enter another screen by registered callback function */
    g_mmi_am_prompt.keep_prompt_screen_in_history = MMI_FALSE;
    g_mmi_am_prompt.success_callback();

    #ifdef AM_09A
    DeleteScreenIfPresent(SCR_ID_AM_STOP_LIST);
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_stop_finished_handler
 * DESCRIPTION
 *  Callback handler when an medlication finished stop operation
 * PARAMETERS
 *  med_id      [IN]    ID of the medlication to be stopped
 *  string_id   [IN]    Name of the medlication to be stopped
 *  result      [IN]    whether the stop operation suceeds or not
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_stop_finished_handler(MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_am_is_in_prompt_screens() ||
        g_mmi_am_prompt.stop_state == MMI_AM_STOP_STATE_WAITING) /* In confirm screen */
    {
        U32 msgId;
        U16 icon;
        U8 tone;
        FuncPtr callback;
        
		msgId = STR_ID_APPMEM_NOTIFY_STARTING_NEW;
        icon = IMG_GLOBAL_INFO;
        tone = SUCCESS_TONE;        
        //callback = mmi_am_invoke_release_mem_success_callback;
        //if (!isIncomingCall())
        {
            MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_ASM_STOP_FINISHED_HANDLER, msgId, callback);
            ClearAllKeyHandler();
            #ifdef AM_09A
            #ifdef MMI_PROMPT_SCREEN_08A
            DisplayPopupCallBack((U8*)GetString(STR_ID_APPMEM_NOTIFY_STARTING_NEW), 
                    icon, 0, UI_POPUP_NOTIFYDURATION_TIME_2000, tone, mmi_am_invoke_release_mem_success_callback);
            #else
            mmi_display_popupcallback(
            (UI_string_type)GetString(STR_ID_APPMEM_NOTIFY_STARTING_NEW),
            MMI_EVENT_INFO,
                mmi_am_invoke_release_mem_success_callback);
            #endif
            #else
            mmi_display_popupcallback_with_sg(
                        GRP_ID_AM,
                        (UI_string_type)GetString(STR_ID_APPMEM_NOTIFY_STARTING_NEW),
                        MMI_EVENT_INFO,
                        mmi_am_invoke_release_mem_success_callback,
                        NULL,
                        0);
            #endif
            mmi_frm_block_general_interrupt_event(MMI_FRM_INT_TOTAL_INTERRUPT_EVENT);
        }
        if (g_mmi_am_prompt.stop_state == MMI_AM_STOP_STATE_WAITING)
        {
            g_mmi_am_prompt.stop_state = MMI_AM_STOP_STATE_FINISHED;
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
 *  mmi_am_prompt_to_release_mem
 * DESCRIPTION
 *  Show "out-of-memory" or "exceed-max_app_num" screen and prompt user to stop other medlications in order 
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
void mmi_am_prompt_to_release_mem(void (*success_callback)(void), MMI_BOOL is_out_of_memory_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Avoid reentrance of the prompt screen.
       Application developers should be careful on designing the screen flow */
    /* Temp solution to display error popup screen when reentrance happens, need to improve!!! */
    if (mmi_am_is_in_prompt_screens() || mmi_am_is_prompt_screens_in_history())
    {
    	 if (is_out_of_memory_flag)
        	DisplayPopup((PU8) GetString(STR_GLOBAL_INSUFFICIENT_MEMORY), IMG_GLOBAL_WARNING, 0, 1000, (U8) WARNING_TONE);
	 else
	 	DisplayPopup((PU8) GetString(STR_ID_AM_EXCEED_MAX_APP_NUM), IMG_GLOBAL_WARNING, 0, 1000, (U8) WARNING_TONE);
	return;
    }

    g_is_out_of_memory_flag = is_out_of_memory_flag;

    g_mmi_am_prompt.stop_state = MMI_AM_STOP_STATE_IGNORE;
    g_mmi_am_prompt.keep_prompt_screen_in_history = MMI_TRUE;
    g_mmi_am_prompt.success_callback = success_callback;
    
    mmi_am_entry_prompt_screen();
}

#endif
