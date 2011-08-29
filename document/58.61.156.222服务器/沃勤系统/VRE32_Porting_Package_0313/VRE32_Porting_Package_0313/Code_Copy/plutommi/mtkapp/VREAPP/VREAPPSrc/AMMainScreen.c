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
 *   AMMainScreen.c
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   AM Main Screen Src
 *
 * Author:
 * -------
 *  Keith Chen
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __VRE30_AM__

/***************************************************************************** 
* Include header files
*****************************************************************************/
    #ifdef __VRE_AM_08AB__
        #include "MMI_include.h"
    #else
        #include "MMI_frm_gprot.h"
    #endif
    #include "Conversions.h"        // TODO: delete
    #include "CommonScreens.h"
    #include "MainMenuDef.h"
    #ifdef __VRE_AM_08AB__
        #include "wgui_categories_fmgr.h"
    #endif
    #include "AMResDef.h"   /* Add AM head file */
    #include "AMDef.h"      /* Add AM head file */
    #include "AMGprot.h"    /* Add AM head file */
    #include "AMprot.h"     /* Add AM head file */
    #include "AMUtil.h"
    #include "AMShortcut.h"
    #include "AMConfig.h"
    #include "AMMainScreen.h"
    #include "AMScreens.h"
    #include "liblist.h"

/*****************************************************************************/
/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/

/* global variables */
mmi_am_ms_struct g_am_ms_cntx;
extern mmi_am_cntx_struct g_am_cntx;
extern MMI_theme *current_MMI_theme;
extern const U8 AM_App_Default[];
extern char AM_App_VRE20[];
U16 num_app_move;
MMI_BOOL key_event_tag = MMI_FALSE;
/***************************************************************************** 
* Local Function
*****************************************************************************/
static void mmi_am_eixt_main_scrn(void);

    #ifdef __MMI_FTE_SUPPORT__
static void mmi_am_intuitive_cb(mmi_tap_type_enum tap_type, S32 index);
    #endif 

    #ifdef AM_09A
static U8 mmi_am_destroy_main_scrn(void *param);
    #else 
static mmi_ret mmi_am_leave_main_scrn(mmi_event_struct *evt);
    #endif 
static mmi_ret mmi_am_ms_deinit(void);
static void mmi_am_ms_release_applist_node(mmi_am_ms_app_struct *p_node);
static void mmi_am_ms_release_applist_node_ex(S32 idx);
static void mmi_am_ms_download_prompt(void);
static void mmi_am_ms_draw_cb(
                             S32 idx,
                             S32 page_start_idx,
                             S32 page_end_idx,
                             BOOL is_hilighted,
                             BOOL is_need_update,
                             BOOL is_new_page,
                             S32 x1,
                             S32 y1,
                             S32 x2,
                             S32 y2);
static void mmi_am_ms_draw_app_icon(S32 idx, S32 page_start_idx, S32 x1, S32 y1, S32 x2, S32 y2);
static void mmi_am_ms_draw_status_icon(S32 idx, S32 x1, S32 y1, S32 x2, S32 y2);
static void mmi_am_ms_draw_app_name(S32 idx, BOOL is_hilighted, S32 x1, S32 y1, S32 x2, S32 y2);
static void mmi_am_ms_get_app_name_size(S32 idx, S32 *str_w, S32 *str_h);
static void mmi_am_ms_draw_default_app_name(S32 x, S32 y);
static void mmi_am_ms_draw_app_name_int(S32 idx, S32 x, S32 y, S32 str_w, S32 str_h);
static U16 *mmi_am_ms_get_app_name_by_idx(S32 idx);
static U8 *mmi_am_ms_get_app_zimo_by_idx(S32 idx, S32 *str_len);       // TODO: modify
static void mmi_am_ms_draw_app_name_scrolling(S32 idx, S32 x, S32 y, S32 width, S32 height);
static void mmi_am_ms_scroll_handler(void);
static void mmi_am_ms_scroll_draw_bg(S32 x1, S32 y1, S32 x2, S32 y2);
static void mmi_am_ms_zimo_scroll_cb(void);
static void mmi_am_ms_hide_cb(S32 index);
static U16 mmi_am_ms_get_icon_resid(S32 idx);
static U8 *mmi_am_ms_get_icon_ptr(S32 idx, S32 page_start_idx, U32 *icon_size);

/* Update App list */
static MMI_BOOL mmi_am_ms_update_app_list(S32 page_start_idx, S32 page_end_idx);
static mmi_am_ms_app_struct *mmi_am_ms_get_appinfo_from_vxplist(mmi_am_vxp_file_struct *vxp_p);

/* Update VRE CDR */
void mmi_am_ms_update_cdr(void);
static void mmi_am_ms_netconnection_check(void);
//michael
void mmi_am_ms_set_app_bg_running_by_path(U16 *app_path, MMI_BOOL is_bg_running);
/*Vogins_20100625_start*/
static void mmi_am_ms_bg_update(S32 page_start_idx, S32 page_end_idx);
/*Vogins_20100625_end*/
/*Vogins_20100710_start*/
static void mmi_am_rom_app_reorder(S32 index);
/*Vogins_20100710_end*/
/*****************************************************************************
 * FUNCTION
 *  mmi_am_entry_main_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_entry_main_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    U16 num_of_items;
    U8 *gui_buffer;
    U16 left_softkey, left_softkey_icon;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_ENTRY_MAIN_SCRN_S);

    ret = mmi_frm_scrn_enter(GRP_ID_AM, SCR_ID_AM_MAIN, mmi_am_eixt_main_scrn, mmi_am_entry_main_scrn, NULL);

    if (ret == MMI_FALSE)
    {
        return;
    }

    mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_LOADING);

    num_of_items = sml_list_size(g_am_cntx.vxp_file_list) + g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num;
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_MS_ENTRY_SCREEN, num_of_items);

    if ((!g_am_ms_cntx.is_able_to_download) && (g_am_cntx.shortcut_app_num > 0) && !mmi_am_ms_is_app_download(0))
    {
        left_softkey = STR_GLOBAL_OK;
        left_softkey_icon = IMG_GLOBAL_OK;
    }
    else
    {
        left_softkey = STR_GLOBAL_OPTIONS;
        left_softkey_icon = IMG_GLOBAL_OPTIONS;
    }

    if (g_am_cntx.is_card_plug_in || g_am_cntx.is_card_plug_out)
    {
        g_am_cntx.is_card_plug_in = MMI_FALSE;
        g_am_cntx.is_card_plug_out = MMI_FALSE;
        g_am_cntx.is_app_in_card = MMI_FALSE;
        gui_buffer = NULL;
        g_am_ms_cntx.hl_idx = 0;
    }

    wgui_cat214_disable_draw_highlight();
    ShowCategory214Screen(
#ifdef __VRE_AM_08AB__
                         STR_ID_AM_NAME,
#else
                         MAIN_MENU_VRE_TEXT,   /* STR_ID_AM_NAME, */
#endif
#ifdef __MMI_FTE_SUPPORT__
                         0,
#else 
                         IMG_ID_AM_TITLE,
#endif 
                         left_softkey, left_softkey_icon, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, num_of_items,      /* num of item */
                         mmi_am_ms_draw_cb,    /* draw color callback */
                         mmi_am_ms_hide_cb,    /* hide color callback */
                         g_am_ms_cntx.cfg->app_num_per_col,    /* number of app per col */
                         g_am_ms_cntx.cfg->app_num_per_row,    /* number of app per row */
                         0,                    /* hilighted item */
                         (U8*) gui_buffer);

#ifdef AM_09A
#ifdef __VRE_AM_08AB__
    SetDelScrnIDCallbackHandler(SCR_ID_AM_MAIN, (HistoryDelCBPtr) mmi_am_destroy_main_scrn);
#else
    mmi_frm_set_destroy_scrn_callback(SCR_ID_AM_MAIN, (HistoryDelCBPtr) mmi_am_destroy_main_scrn);
#endif
#else /* AM_09A */ 
    /* set leave proc */
    mmi_frm_scrn_set_leave_proc(GRP_ID_AM, SCR_ID_AM_MAIN, mmi_am_leave_main_scrn);
#endif /* AM_09A */ 

#ifdef __MMI_FTE_SUPPORT__
    wgui_register_tap_callback(mmi_am_intuitive_cb);
#endif 

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

#ifdef MMI_AM_SUPPORT_UPDATE_CDR
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_MS_ENTRY_SCREEN_CDR, g_am_cntx.is_prompt_update_cdr);
    /* Update VRE CDR */
    if (mmi_am_is_network_service_available() && !g_am_cntx.is_prompt_update_cdr)
    {
        /*vogins 20100714 begin*/
        gui_start_timer(1, mmi_am_ms_netconnection_check/*mmi_am_ms_update_cdr*/);   /* For 09B FW issue */
    }
#endif

    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_ENTRY_MAIN_SCRN_E);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_eixt_main_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_eixt_main_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_am_ms_update_cdr);

    mmi_am_ms_scrolling_text_stop();
}

    #ifdef __MMI_FTE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_am_intuitive_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  tap_type        [IN]        
 *  index           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_intuitive_cb(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
    {
        if ((!g_am_ms_cntx.is_able_to_download) && !mmi_am_ms_is_app_download(index))
        {
            mmi_am_ms_download_prompt();
        }
        else if ((g_am_ms_cntx.is_able_to_download) && !mmi_am_ms_is_app_download(index))
        {
            mmi_am_os_download();
        }
        else
        {
            mmi_am_os_app_launch();
        }
    }
}
    #endif /* __MMI_FTE_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_ms_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_am_ms_cntx.hl_idx = 0;
    /* g_am_ms_cntx.app_list = NULL; */
    g_am_ms_cntx.sc_app_num = 0;
    g_am_ms_cntx.rom_app_num = 0;

    /* check if it can download app */
    if (!mmi_am_is_network_service_available())
    {
        g_am_ms_cntx.is_able_to_download = MMI_FALSE;
    }
    else
    {
        g_am_ms_cntx.is_able_to_download = MMI_TRUE;
    }

    /* get Main Screen configure data */
    g_am_ms_cntx.cfg = mmi_am_config_get_ms_info();

    /* new list */
    if (g_am_ms_cntx.app_list == NULL)
    {
        g_am_ms_cntx.app_list = sml_list_new();
    }

    memset(&g_am_ms_cntx.scrolling_app_name, 0, sizeof(g_am_ms_cntx.scrolling_app_name));
}

    #ifdef AM_09A


/*****************************************************************************
 * FUNCTION
 *  mmi_am_destroy_main_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static U8 mmi_am_destroy_main_scrn(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_MS_DESTROY_S);
    mmi_am_ms_deinit();

    mmi_am_grp_deinit();

    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_MS_DESTROY_E);
    return MMI_FALSE;
}
    #else /* AM_09A */ 


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
static mmi_ret mmi_am_leave_main_scrn(mmi_event_struct *evt)
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
        /* mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_MAIN); */
        break;

    case EVT_ID_SCRN_DEINIT:
        mmi_am_ms_deinit();
        break;
    }

    return ret;
}
    #endif /* AM_09A */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_deinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_am_ms_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_am_ms_update_cdr);

    mmi_am_ms_scrolling_text_stop();

    mmi_am_ms_release_app_list();

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_release_applist_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p_node      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_ms_release_applist_node(mmi_am_ms_app_struct *p_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!p_node)
    {
        return;
    }

    /* delete the node */
    if (p_node->p_icon)
    {
        mmi_am_free(p_node->p_icon);
        p_node->p_icon = NULL;
    }

    if ((p_node->p_name) &&
        mmi_wcscmp((PU16) p_node->p_name, (PU16) GetString(STR_ID_AM_APP_NAME_VRE20)) &&
        mmi_wcscmp((PU16) p_node->p_name, (PU16) GetString(STR_ID_AM_APP_NAME_DEFAULT)))
    {
        mmi_am_free(p_node->p_name);
        p_node->p_name = NULL;
    }

    mmi_am_free(p_node);

    p_node = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_release_applist_node_ex
 * DESCRIPTION
 *  release node and update idx after this node in app_list
 * PARAMETERS
 *  idx     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_ms_release_applist_node_ex(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_am_ms_app_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = sml_list_get(g_am_ms_cntx.app_list, idx);

    mmi_am_ms_release_applist_node(p);
    sml_list_remove(g_am_ms_cntx.app_list, idx);

    /* update index of every app_list node after deleted node */
    for (i = idx; i < sml_list_size(g_am_ms_cntx.app_list); i++)
    {
        mmi_am_ms_app_struct *q = sml_list_get(g_am_ms_cntx.app_list, i);

        q->idx--;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_release_app_list_all_nodes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_ms_release_app_list_all_nodes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_am_ms_cntx.app_list)
    {
        while (sml_list_size(g_am_ms_cntx.app_list))
        {
            mmi_am_ms_app_struct *p = sml_list_get(g_am_ms_cntx.app_list, 0);

            mmi_am_ms_release_applist_node(p);
            sml_list_remove(g_am_ms_cntx.app_list, 0);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_release_app_list_nodes_in_memory_card
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_ms_release_app_list_nodes_in_memory_card(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 num_of_app_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_am_ms_cntx.app_list)
    {
        num_of_app_list = sml_list_size(g_am_ms_cntx.app_list);

        for (i = num_of_app_list - 1; i >= 0; i--)
        {
            mmi_am_ms_app_struct *p = sml_list_get(g_am_ms_cntx.app_list, i);

            if (((S8) (*(p->path)) != (S8) mmi_am_get_system_driver()) && ((S8) (*(p->path)) != (S8) MMI_AM_ROM_DIR))
            {
                if (p->is_bg_started && num_app_move > 0)
                    num_app_move--;
                if (p->idx <= g_am_ms_cntx.hl_idx)
                {
                    g_am_ms_cntx.hl_idx--;
                }
                MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_RELEASE_APP_LIST_NODE, g_am_ms_cntx.hl_idx);
                mmi_am_ms_release_applist_node_ex(i);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_release_app_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_ms_release_app_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_am_ms_cntx.app_list)
    {
        mmi_am_ms_release_app_list_all_nodes();
        sml_list_free(g_am_ms_cntx.app_list);
        g_am_ms_cntx.app_list = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_download_prompt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_ms_download_prompt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_display_popup_with_sg(
                             GRP_ID_AM,
                             (UI_string_type) get_string(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE),
                             MMI_EVENT_FAILURE,
                             0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_scrolling_text_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_ms_scrolling_text_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_am_cntx.has_small_font)
    {
        gui_scrolling_text_stop(&g_am_ms_cntx.scrolling_app_name);
    }
    else
    {
        gui_cancel_timer(mmi_am_ms_zimo_scroll_cb);
    }
}
/*Vogins_20100625_start*/
/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_bg_update
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_ms_bg_update(S32 page_start_idx, S32 page_end_idx)
{

    S32 i, j, k;
    S32 vxp_list_idx, app_list_idx; /*  */
    mmi_am_ms_app_struct *p;
    mmi_am_ms_app_struct *app_p;
    mmi_am_vxp_file_struct *vxp_p;
    S32 position;
    S32 start_idx;

    S32 num_sc_bg_run = 0,  num_rom_bg_run = 0;

    mmi_am_get_sc_and_rom_bg_num(&num_sc_bg_run, &num_rom_bg_run);

    start_idx = page_start_idx + g_am_ms_cntx.sc_app_num + g_am_ms_cntx.rom_app_num;

    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_ms_bg_update  ------------------[S]"); 
    for (i = 0, k = 0; i < num_app_move && k < num_app_move; i++, k++)
    {
        vxp_p = sml_list_get(g_am_cntx.vxp_file_list, k);
        if (!vxp_p)
        	{
        		num_app_move = k;
            return;
          }
        if (mmi_am_app_is_bg_running(vxp_p->path))
        {
            app_p = sml_list_get(g_am_ms_cntx.app_list, i);
            if (app_p == NULL)
            {
                if (page_start_idx <= num_sc_bg_run + num_rom_bg_run + k + 1)
                {
                    app_p = mmi_am_ms_get_appinfo_from_vxplist(vxp_p);
                    if (app_p)
                    {
                        /* set display index */
                        app_p->idx = i + g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num;

                        /* add the app to app_list */
                        sml_list_add(g_am_ms_cntx.app_list, app_p, i);
                    }
                }
            }
            else if (mmi_wcscmp(vxp_p->path, app_p->path) == 0)
            {
                if (page_start_idx > num_sc_bg_run + num_rom_bg_run + k + 1)
                {
                    p = sml_list_get(g_am_ms_cntx.app_list, i);
                    mmi_am_ms_release_applist_node(p);
                    sml_list_remove(g_am_ms_cntx.app_list, i);
                    i--;
                }
            }
            else if (page_start_idx <= num_sc_bg_run + num_rom_bg_run + k + 1)
            {
                app_p = mmi_am_ms_get_appinfo_from_vxplist(vxp_p);
                if (app_p)
                {
                    /* set display index */
                    app_p->idx = i + g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num;

                    /* add the app to app_list */
                    sml_list_add(g_am_ms_cntx.app_list, app_p, i);
                }
            }
            else
                i--;
            MMI_AM_LOG(
                      MOD_MMI,
                      TRACE_GROUP_7,
                      "mmi_am_ms_bg_update() --  background running index: %d", k);
        }
        else
        {
            int ret;
            if (num_app_move == sml_list_size(g_am_cntx.vxp_file_list))
                position = num_app_move;
            else
                position = mmi_am_binary_search(num_app_move, sml_list_size(g_am_cntx.vxp_file_list)-1, &vxp_p->time);
            if (position == -1)
                position = sml_list_size(g_am_cntx.vxp_file_list);
            ret = sml_list_insert_to_position(g_am_cntx.vxp_file_list, k, position);

            if ((position -1 < start_idx - g_am_cntx.shortcut_app_num - g_am_cntx.rom_app_num + sml_list_size(g_am_ms_cntx.app_list))&& (position-1 >= start_idx - g_am_cntx.shortcut_app_num - g_am_cntx.rom_app_num))
            {
                if (page_start_idx <= num_sc_bg_run + num_rom_bg_run + k + 1)
                {
                    //		if(position != num_app_move)
                    //		position--;
                    p = sml_list_get(g_am_ms_cntx.app_list, i);
                    if (!p)
                        return;
                    p->idx = position - 1 + g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num;
                    if (page_start_idx > 0)
                        position = position - (page_start_idx - (g_am_cntx.shortcut_app_num - g_am_ms_cntx.sc_app_num) - (g_am_cntx.rom_app_num- g_am_ms_cntx.rom_app_num));
                    sml_list_insert_to_position(g_am_ms_cntx.app_list, i, position);
                }
                else
                {
                    app_p = mmi_am_ms_get_appinfo_from_vxplist(vxp_p);
                    if (app_p)
                    {
                        /* set display index */
                        app_p->idx = position - 1 + g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num;

                        if (page_start_idx > 0)
                            position = position - (page_start_idx - (g_am_cntx.shortcut_app_num - g_am_ms_cntx.sc_app_num) - (g_am_cntx.rom_app_num- g_am_ms_cntx.rom_app_num));
                        /* add the app to app_list */
                        if (position == i + 1)
                            position = 0;
                        else if (position == sml_list_size(g_am_cntx.vxp_file_list) && mmi_am_binary_search(num_app_move, sml_list_size(g_am_cntx.vxp_file_list)-1, &vxp_p->time) != -1 && position != 0)
                            position--;
                        sml_list_add(g_am_ms_cntx.app_list, app_p, position);
                    }
                }
                if (page_start_idx <= num_sc_bg_run + num_rom_bg_run + k + 1)
                    j = i;
                else
                    j = 0;
                for (; j < position - 1;j++)
                {
                    p = sml_list_get(g_am_ms_cntx.app_list, j);
                    if (p)
                        p->idx--;
                }
                MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_ms_bg_update  -- stoped app insert to screen: pos %d", position); 
            }
            else if (sml_list_size(g_am_ms_cntx.app_list) == num_app_move && (g_am_cntx.shortcut_app_num + num_app_move > page_end_idx))
            {
                mmi_am_ms_release_applist_node_ex(i);
            }
            else if ((position-1 == start_idx - g_am_cntx.shortcut_app_num - g_am_cntx.rom_app_num -1) && page_start_idx > 0)
            {
                position = position - (page_start_idx - (g_am_cntx.shortcut_app_num - g_am_ms_cntx.sc_app_num));
                if (position == i + 1)
                {
                    app_p = mmi_am_ms_get_appinfo_from_vxplist(vxp_p);
                    if (app_p)
                    {
                        app_p->idx = position - 1 + g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num;
                        sml_list_add(g_am_ms_cntx.app_list, app_p, position);
                    }
                }
                MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_ms_bg_update  -- stoped app insert to the first of app list");   
            }
            else if (position -1 > start_idx - g_am_cntx.shortcut_app_num - g_am_cntx.rom_app_num -1)
                mmi_am_ms_release_applist_node_ex(i);
            num_app_move--;
            i--;
            k--;
            MMI_AM_LOG(
                      MOD_MMI,
                      TRACE_GROUP_7,
                      "mmi_am_ms_bg_update() -- background running app num at this time:%d",
                      num_app_move);
        }
    } 
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_ms_bg_update  ------------------[E]"); 
}
static void mmi_am_os_center_key_tag(void)
{
    key_event_tag = MMI_TRUE;
}

static void mmi_am_os_center_key_hdlr(void)
{
    if (key_event_tag)
    {
        key_event_tag = MMI_FALSE;
        mmi_am_os_app_launch();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_draw_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx                 [IN]        
 *  page_start_idx      [IN]        
 *  page_end_idx        [IN]        
 *  is_hilighted        [IN]        
 *  is_need_update      [IN]        
 *  is_new_page         [IN]        
 *  x1                  [IN]        
 *  y1                  [IN]        
 *  x2                  [IN]        
 *  y2                  [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_ms_draw_cb(
                             S32 idx,
                             /* start from 0 */ S32 page_start_idx,
                             S32 page_end_idx,
                             BOOL is_hilighted,
                             BOOL is_need_update,
                             /* invalid */ BOOL is_new_page,
                             /* invalid */ S32 x1,
                             S32 y1,
                             S32 x2,
                             S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    S32 num_sc_bg_run = 0;
    S32 i;
    S32 num_rom_bg_run = 0;

    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_MS_DRAW_CB_S);
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_MS_DRAW_CB, idx, page_start_idx, page_end_idx, is_hilighted);
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_MS_DRAW_CB_POS, x1, y1, x2, y2);

    g_am_ms_cntx.page_start_idx = page_start_idx;
    g_am_ms_cntx.page_end_idx = page_end_idx;


    mmi_am_get_sc_and_rom_bg_num(&num_sc_bg_run, &num_rom_bg_run);
    /* if the idx is the first index on the current screen */
    if (idx == page_start_idx)
    {
    	/*udpate shortcut and rom apps' status*/
	mmi_am_ms_app_status_update(g_am_ms_cntx.hl_idx);
	
        /*update the background running app */
        mmi_am_ms_bg_update(page_start_idx, page_end_idx);
		
        /* update Shortcut_App_num and Rom_App_num */
        if (idx <= num_sc_bg_run)
        {
            g_am_ms_cntx.sc_app_num = g_am_cntx.shortcut_app_num - idx;
            g_am_ms_cntx.rom_app_num = g_am_cntx.rom_app_num;
        }
        else if (idx <= num_sc_bg_run + num_rom_bg_run)
        {
            g_am_ms_cntx.sc_app_num = g_am_cntx.shortcut_app_num - num_sc_bg_run -1;
            g_am_ms_cntx.rom_app_num = g_am_cntx.rom_app_num - (idx - num_sc_bg_run -1);
        }
        /* update Shortcut_App_num and Rom_App_num */
        else if (idx <= num_sc_bg_run + num_rom_bg_run + num_app_move)
        {
            g_am_ms_cntx.sc_app_num = g_am_cntx.shortcut_app_num - num_sc_bg_run -1;
            g_am_ms_cntx.rom_app_num = g_am_cntx.rom_app_num - num_rom_bg_run;
        }
        /* update Shortcut_App_num and Rom_App_num */
        else if (idx < g_am_cntx.shortcut_app_num + num_app_move)
        {
            /* update Shortcut_App_num and Rom_App_num */
            g_am_ms_cntx.sc_app_num = g_am_cntx.shortcut_app_num - idx + num_app_move + num_rom_bg_run;
            g_am_ms_cntx.rom_app_num = g_am_cntx.rom_app_num - idx + num_app_move + (g_am_cntx.shortcut_app_num - g_am_ms_cntx.sc_app_num);
        }
        else
        {
            g_am_ms_cntx.sc_app_num = 0;
            if (idx< (g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num + num_app_move))
            {
                /* update Shortcut_App_num and Rom_App_num */
                g_am_ms_cntx.rom_app_num = (g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num + num_app_move) - idx;
            }
            else
            {
                g_am_ms_cntx.rom_app_num = 0;
            }
        }
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_MS_DRAW_CB_APP_NUM, g_am_ms_cntx.sc_app_num, g_am_ms_cntx.rom_app_num);

        // update app_list
        //page_end = page_start_idx + (g_am_ms_cntx.cfg->app_num_per_col * g_am_ms_cntx.cfg->app_num_per_row) -1;
        if (mmi_am_ms_update_app_list(page_start_idx, page_end_idx) == MMI_FALSE)
        {
            mmi_frm_scrn_close_active_id();
            return;
        }
    }

    /*************************************************************
        * draw Highlight ICON
        *************************************************************/
    if (is_hilighted)
    {
        g_am_ms_cntx.hl_x1 = x1;
        g_am_ms_cntx.hl_y1 = y1;
        g_am_ms_cntx.hl_x2 = x2;
        g_am_ms_cntx.hl_y2 = y2;

        /* change left soft key */
        if ((!g_am_ms_cntx.is_able_to_download) && !mmi_am_ms_is_app_download(idx))
        {
            ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
            SetLeftSoftkeyFunction(mmi_am_ms_download_prompt, KEY_EVENT_UP);
            SetKeyHandler(mmi_am_ms_download_prompt, KEY_ENTER, KEY_EVENT_UP);
        }
        else
        {
            ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);
            SetLeftSoftkeyFunction(mmi_am_entry_option_scrn, KEY_EVENT_UP);
            if (mmi_am_ms_is_app_download(idx))
            {
                SetKeyHandler(mmi_am_os_center_key_hdlr, KEY_ENTER, KEY_EVENT_UP);
                SetKeyHandler(mmi_am_os_center_key_tag, KEY_ENTER, KEY_EVENT_DOWN);
            }
            else
            {
#if defined(AM_DOWNLOAD_QUERY) && (!defined(AM_GPRS_NOT_NOTICE))
                SetKeyHandler(mmi_am_download_prompt, KEY_ENTER, KEY_EVENT_UP);
                SetKeyHandler(NULL, KEY_ENTER, KEY_EVENT_DOWN);
#else
                SetKeyHandler(mmi_am_os_download, KEY_ENTER, KEY_EVENT_UP);
                SetKeyHandler(NULL, KEY_ENTER, KEY_EVENT_DOWN);
#endif
            }
        }

        /* update highlight icon */
        mmi_am_config_update_ms_info();

        /* draw highlight image */
        gdi_image_draw_id(x1, y1, g_am_ms_cntx.cfg->hl_icon_id);

        mmi_am_ms_scrolling_text_stop();

        g_am_ms_cntx.hl_idx = idx;
    }

    /*************************************************************
        * draw App ICON
        *************************************************************/
    mmi_am_ms_draw_app_icon(idx, page_start_idx, x1, y1, x2, y2);

    /*************************************************************
        * draw Status ICON
        *************************************************************/
    mmi_am_ms_draw_status_icon(idx, x1, y1, x2, y2);

    /*************************************************************
        * draw App Name
        *************************************************************/
    mmi_am_ms_draw_app_name(idx, is_hilighted, x1, y1, x2, y2);

    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_MS_DRAW_CB_E);
}
/*Vogins_20100625_end*/

/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_hide_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_ms_hide_cb(S32 index)
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
 *  mmi_am_ms_draw_app_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx                 [IN]        
 *  page_start_idx      [IN]        
 *  x1                  [IN]        
 *  y1                  [IN]        
 *  x2                  [IN]        
 *  y2                  [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_ms_draw_app_icon(S32 idx, S32 page_start_idx, S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_HANDLE dest_layer_hdl;
    S32 grid_w; /* grid width */
    S32 grid_h; /* grid height */
    S32 img_w;  /* image width */
    S32 img_h;  /* image width */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_ms_draw_app_icon() ------- [S]");

    /* get and set source layer */
    gdi_layer_get_active(&dest_layer_hdl);
    gdi_push_and_set_alpha_blending_source_layer(dest_layer_hdl);

    grid_w = (x2 - x1) + 1;
    grid_h = (y2 - y1) + 1;
/*Vogins_20100625_start*/
    idx = mmi_am_ms_get_actual_index(idx);
/*Vogins_20100625_end*/
    if (idx < g_am_cntx.shortcut_app_num)   /* Shortcut app */
    {
        U16 res_id;

        res_id = mmi_am_ms_get_icon_resid(idx);

        /* draw ICON */
        gdi_image_get_dimension_id(res_id, &img_w, &img_h);
        if ((img_w == MMI_AM_APP_ICON_W) && (img_h == MMI_AM_APP_ICON_H))       /* 45*45 */
        {
            gdi_image_draw_id(x1 + ((grid_w - img_w) >> 1), y1 + g_am_ms_cntx.cfg->icon_top_size, res_id);
        }
        else
        {
            /* use default icon */
            gdi_image_draw_id(
                             x1 + ((grid_w - MMI_AM_APP_ICON_W) >> 1),
                             y1 + g_am_ms_cntx.cfg->icon_top_size,
                             IMG_ID_AM_APP_DEFAULT);
        }
    }
    /* is not shortcut app */
    else
    {
        U8 *res_ptr;
        U32 icon_size;

        res_ptr = mmi_am_ms_get_icon_ptr(idx, page_start_idx, &icon_size);

        gdi_image_get_dimension_mem(GDI_IMAGE_TYPE_GIF, res_ptr, icon_size, &img_w, &img_h);
        MMI_AM_LOG(
                  MOD_MMI,
                  TRACE_GROUP_7,
                  "mmi_am_ms_draw_app_icon() --res_ptr:%d, icon_size:%d, img_w:%d, img_h:%d",
                  res_ptr,
                  icon_size,
                  img_w,
                  img_h);
        if ((img_w == MMI_AM_APP_ICON_W) && (img_h == MMI_AM_APP_ICON_H))       /* 45*45 */
        {
            MMI_AM_ASSERT(res_ptr != NULL);
            gdi_image_draw_mem(
                              x1 + ((grid_w - img_w) >> 1),
                              y1 + g_am_ms_cntx.cfg->icon_top_size,
                              res_ptr,
                              GDI_IMAGE_TYPE_GIF,
                              icon_size);
        }
        else
        {
            /* use default icon */
            gdi_image_draw_id(
                             x1 + ((grid_w - MMI_AM_APP_ICON_W) >> 1),
                             y1 + g_am_ms_cntx.cfg->icon_top_size,
                             IMG_ID_AM_APP_DEFAULT);
        }
    }

    /* restore source layer */
    gdi_pop_and_restore_alpha_blending_source_layer();

    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_ms_draw_app_icon() ------- [E]");

}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_draw_status_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_ms_draw_status_icon(S32 idx, S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_HANDLE base_layer_hdl;              /* base layer */
    GDI_HANDLE scr_bg_layer;                /* background image layer */
    S32 index = idx;
    S32 shortcut_icon_w, shortcut_icon_h;   /* shortcut status icon dimension */
    S32 status_icon_w, status_icon_h;       /* BG running status and download status icon dimension */
    S32 grid_w, grid_h;                     /* grid dimension */
    S32 shortcut_icon_x, shortcut_icon_y;
    S32 status_icon_x, status_icon_y;
/*Vogins_20100625_start*/
    index = mmi_am_ms_get_actual_index(idx);
/*Vogins_20100625_end*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_ms_draw_status_icon() ------- [S]");

    gdi_layer_get_base_handle(&base_layer_hdl);
    scr_bg_layer = dm_get_scr_bg_layer();

    /* get and set source layer */
    gdi_push_and_set_alpha_blending_source_layer(base_layer_hdl);

    /* Flatten: bottom-to-up order 1. background layer; 2. base layer */
    gdi_layer_flatten_with_clipping(scr_bg_layer, base_layer_hdl, 0, 0);

    /* get icon dimension */
    gdi_image_get_dimension_id(IMG_ID_AM_STATE_SHORTCUT, &shortcut_icon_w, &shortcut_icon_h);
    gdi_image_get_dimension_id(IMG_ID_AM_STATE_BG, &status_icon_w, &status_icon_h);
    grid_w = x2 - x1 + 1;
    grid_h = y2 - y1 + 1;

    /* get draw x and y */
    shortcut_icon_x = x1 + ((grid_w - MMI_AM_APP_ICON_W) >> 1);
    shortcut_icon_y = y1 + g_am_ms_cntx.cfg->icon_top_size + MMI_AM_APP_ICON_H - shortcut_icon_h;
    status_icon_x = x1 + ((grid_w - MMI_AM_APP_ICON_W) >> 1) + MMI_AM_APP_ICON_W - status_icon_w + 5;
    status_icon_y = y1 + g_am_ms_cntx.cfg->icon_top_size + MMI_AM_APP_ICON_H - status_icon_h + 8;

    if (index < g_am_cntx.shortcut_app_num)
    {
        /*-------------------------------------------------------------------
            - draw undownload status icon
            --------------------------------------------------------------------*/
        if (!mmi_am_ms_is_app_download(idx))
        {
#ifdef __VRE_AM_08AB__
            gdi_image_draw_id(status_icon_x, status_icon_y, IMG_ID_AM_STATE_UNDOWNLOAD);
#else
            gdi_image_draw_id_blend2layers(status_icon_x, status_icon_y, IMG_ID_AM_STATE_UNDOWNLOAD);
#endif
            /* restore source layer */
            gdi_pop_and_restore_alpha_blending_source_layer();

            MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_ms_draw_status_icon() ------- [E1]");
            return;
        }
    }

    /*************************************************************
        * draw bg_running & hs_shortcut status icon
        *************************************************************/
#ifdef __MMI_VUI_HOMESCREEN__
    if (mmi_am_ms_is_app_set_hs_shortcut(idx))
    {
        gdi_image_draw_id(shortcut_icon_x, shortcut_icon_y, IMG_ID_AM_STATE_SHORTCUT);
    }
#endif /* __MMI_VUI_HOMESCREEN__ */ 

    if (mmi_am_ms_is_app_bg_running(idx))
    {
#ifdef __VRE_AM_08AB__
        gdi_image_draw_id(status_icon_x, status_icon_y, IMG_ID_AM_STATE_BG);
#else
        gdi_image_draw_id_blend2layers(status_icon_x, status_icon_y, IMG_ID_AM_STATE_BG);
#endif
    }

    /* restore source layer */
    gdi_pop_and_restore_alpha_blending_source_layer();

    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_ms_draw_status_icon() ------- [E2]");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_draw_app_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx                 [IN]        
 *  is_hilighted        [IN]        
 *  x1                  [IN]        
 *  y1                  [IN]        
 *  x2                  [IN]        
 *  y2                  [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_ms_draw_app_name(S32 idx, BOOL is_hilighted, S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* GDI_HANDLE src_layer_hdl, dest_layer_hdl; */
    S32 grid_w, grid_h; /* grid dimension */
    S32 str_w, str_h, disp_zone_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_ms_draw_app_name() ------- [S]");

    grid_w = x2 - x1 + 1;
    grid_h = y2 - y1 + 1;
    disp_zone_size = grid_w - (g_am_ms_cntx.cfg->name_indent << 1);

    mmi_am_ms_get_app_name_size(idx, &str_w, &str_h);
    MMI_AM_LOG(
              MOD_MMI,
              TRACE_GROUP_7,
              "mmi_am_ms_draw_app_name() -- is_hilighted:%d;str_w:%d;str_h:%d;disp_zone_size:%d",
              is_hilighted,
              str_w,
              str_h,
              disp_zone_size);

    gdi_layer_push_clip();
    gdi_layer_set_clip(
                      x1 + g_am_ms_cntx.cfg->name_indent,
                      y2 - g_am_ms_cntx.cfg->name_below_size - str_h,
                      x2 - g_am_ms_cntx.cfg->name_indent,
                      y2 - g_am_ms_cntx.cfg->name_below_size);

    if (str_w == 0 && g_am_cntx.has_small_font) /* get app name failure, use default name */
    {
        gui_set_font(&MMI_small_font);
        gui_measure_string((UI_string_type) GetString(STR_ID_AM_APP_NAME_DEFAULT), &str_w, &str_h);
        mmi_am_ms_draw_default_app_name(
                                       x1 + ((grid_w - disp_zone_size) >> 1),
                                       y2 - g_am_ms_cntx.cfg->name_below_size - str_h);
        gui_set_font(&MMI_medium_font);
        gdi_layer_pop_clip();

        MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_ms_draw_app_name() ------- [E1]");
        return;
    }

    if (str_w <= disp_zone_size)    /* be able to show all */
    {
        mmi_am_ms_draw_app_name_int(
                                   idx,
                                   x1 + ((grid_w - str_w) >> 1),
                                   y2 - g_am_ms_cntx.cfg->name_below_size - str_h,
                                   str_w,
                                   str_h);
    }
    else    /* cant show all */
    {
        if (!is_hilighted)  /* show app name in the order */
        {
            mmi_am_ms_draw_app_name_int(
                                       idx,
                                       x1 + g_am_ms_cntx.cfg->name_indent,
                                       y2 - g_am_ms_cntx.cfg->name_below_size - str_h,
                                       str_w,
                                       str_h);
        }
        else    /* scrolling */
        {
            mmi_am_ms_draw_app_name_scrolling(
                                             idx,
                                             x1 + g_am_ms_cntx.cfg->name_indent,
                                             y2 - g_am_ms_cntx.cfg->name_below_size - str_h,
                                             disp_zone_size,
                                             str_h);
        }
    }

    gdi_layer_pop_clip();

    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_ms_draw_app_name() ------- [E2]");

}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_get_app_name_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx         [IN]        
 *  str_w       [OUT]       
 *  str_h       [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_ms_get_app_name_size(S32 idx, S32 *str_w, S32 *str_h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*************************************************************
        * Support small font
        *************************************************************/
/*Vogins_20100625_start*/
    idx = index = mmi_am_ms_get_actual_index(idx);
/*Vogins_20100625_end*/     
    *str_w = 0;
    *str_h = 0;
    if (g_am_cntx.has_small_font)
    {
        gui_set_font(&MMI_small_font);
        if (index < g_am_cntx.shortcut_app_num) /* AM Shortcut app */
        {
            if (mmi_am_config_get_am_sc_info_by_appid(APPID_VAS))       /* AppStore Support */
            {
                if (index == 0) /* AppStore */
                {
                    gui_measure_string((UI_string_type) GetString(g_am_cntx.appstore_list.name_id), str_w, str_h);
                }
                else    /* Other AM Shortcut App */
                {
                    index--;
                    gui_measure_string(
                                      (UI_string_type) GetString(g_am_cntx.shortcut_app_list[index].name_id),
                                      str_w,
                                      str_h);
                }
            }
            else    /* AppStore dont support */
            {
                gui_measure_string(
                                  (UI_string_type) GetString(g_am_cntx.shortcut_app_list[index].name_id),
                                  str_w,
                                  str_h);
            }
            /* gui_measure_string(GetString(shortcut_info_list[idx].name_id), &str_w, &str_h); */
        }
        else if (idx < (g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num))    /* Rom app */
        {
            index = idx - g_am_cntx.shortcut_app_num;
            gui_measure_string((UI_string_type) g_am_cntx.rom_app_list[index].p_name, str_w, str_h);
        }
        else    /* download app */
        {
            /* gui_measure_string(g_am_ms_cntx.app_list[index], &str_w, &str_h); */
            mmi_am_ms_app_struct *p;

            index = idx - (g_am_ms_cntx.page_start_idx + g_am_ms_cntx.sc_app_num + g_am_ms_cntx.rom_app_num);
            p = sml_list_get(g_am_ms_cntx.app_list, index);
            if (p)
            {
                gui_measure_string((UI_string_type) p->p_name, str_w, str_h);
            }
        }
        gui_set_font(&MMI_medium_font);

        if (*str_h == 0)
        {
            *str_h = MMI_AM_APP_NAME_H;
        }

    }
    /*************************************************************
        * Support ZiMo
        *************************************************************/
    else
    {
        if (index < g_am_cntx.shortcut_app_num) /* AM Shortcut app */
        {
            if (mmi_am_config_get_am_sc_info_by_appid(APPID_VAS))       /* AppStore Support */
            {
                if (index == 0) /* AppStore */
                {
                    *str_w = mmi_am_measure_zimo(g_am_cntx.appstore_list.p_name, g_am_cntx.appstore_list.name_len);
                }
                else    /* Other AM Shortcut App */
                {
                    index--;
                    *str_w = mmi_am_measure_zimo(
                                                g_am_cntx.shortcut_app_list[index].p_name,
                                                g_am_cntx.shortcut_app_list[index].name_len);
                }
            }
            else    /* AppStore dont support */
            {
                *str_w = mmi_am_measure_zimo(
                                            g_am_cntx.shortcut_app_list[index].p_name,
                                            g_am_cntx.shortcut_app_list[index].name_len);
            }
        }
        else if (idx < (g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num))    /* Rom app */
        {
            index = idx - g_am_cntx.shortcut_app_num;
            *str_w = mmi_am_measure_zimo(g_am_cntx.rom_app_list[index].p_name, g_am_cntx.rom_app_list[index].name_len);
        }
        else    /* download app */
        {
            mmi_am_ms_app_struct *p;

            index = idx - (g_am_ms_cntx.page_start_idx + g_am_ms_cntx.sc_app_num + g_am_ms_cntx.rom_app_num);
            p = sml_list_get(g_am_ms_cntx.app_list, index);
            if (p)
            {
                *str_w = mmi_am_measure_zimo(p->p_name, p->name_len);
            }
        }

        *str_h = MMI_AM_APP_NAME_H;

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_draw_default_app_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x       [IN]        
 *  y       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_ms_draw_default_app_name(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*************************************************************
        * Support small font
        *************************************************************/
    if (g_am_cntx.has_small_font)
    {
        /* draw */
        gui_set_text_color(*current_MMI_theme->list_normal_text_color);
        gui_move_text_cursor(x, y);
        gui_print_text((UI_string_type) GetString(STR_ID_AM_APP_NAME_DEFAULT));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_draw_app_name_int
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx         [IN]        
 *  x           [IN]        
 *  y           [IN]        
 *  str_w       [IN]        
 *  str_h       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_ms_draw_app_name_int(S32 idx, S32 x, S32 y, S32 str_w, S32 str_h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *p;
    S32 str_len;
    gdi_color font_color;
    color cur_color = *current_MMI_theme->list_normal_text_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*************************************************************
        * Support small font
        *************************************************************/
    if (g_am_cntx.has_small_font)
    {
        gui_set_font(&MMI_small_font);

        /* draw */
        gui_set_text_color(cur_color);
        gui_move_text_cursor(x, y);
        gui_print_text(mmi_am_ms_get_app_name_by_idx(idx));

        gui_set_font(&MMI_medium_font);
    }
    /*************************************************************
        * Support ZiMo
        *************************************************************/
    else
    {
        p = mmi_am_ms_get_app_zimo_by_idx(idx, &str_len);
        font_color = gdi_act_color_from_rgb(255, cur_color.r, cur_color.g, cur_color.b);
        mmi_am_draw_zimo(x, y, 0, str_len, p, str_len, MMI_AM_APP_NAME_H, font_color);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_get_app_name_by_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static U16 *mmi_am_ms_get_app_name_by_idx(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = idx;
    U16 res_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*************************************************************
        * Support small font
        *************************************************************/
/*Vogins_20100625_start*/
    idx = index = mmi_am_ms_get_actual_index(idx);
/*Vogins_20100625_end*/
    if (g_am_cntx.has_small_font)
    {
        if (index < g_am_cntx.shortcut_app_num) /* AM Shortcut app */
        {
            if (mmi_am_config_get_am_sc_info_by_appid(APPID_VAS))       /* AppStore Support */
            {
                if (index == 0) /* AppStore */
                {
                    res_id = g_am_cntx.appstore_list.name_id;
                }
                else    /* Other AM Shortcut App */
                {
                    index--;
                    res_id = g_am_cntx.shortcut_app_list[index].name_id;
                }
            }
            else    /* AppStore dont support */
            {
                res_id = g_am_cntx.shortcut_app_list[index].name_id;
            }
            return(PU16) GetString(res_id);
        }
        else if (idx < (g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num))    /* Rom app */
        {
            index = idx - g_am_cntx.shortcut_app_num;

            return(PU16) g_am_cntx.rom_app_list[index].p_name;
        }
        else    /* download app */
        {
            mmi_am_ms_app_struct *p;

            index = idx - (g_am_ms_cntx.page_start_idx + g_am_ms_cntx.sc_app_num + g_am_ms_cntx.rom_app_num);
            p = sml_list_get(g_am_ms_cntx.app_list, index);

            if (p)
            {
                return(PU16) p->p_name;
            }
            else
            {
                return NULL;
            }
        }
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_get_app_zimo_by_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx         [IN]        
 *  str_len     [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
static U8 *mmi_am_ms_get_app_zimo_by_idx(S32 idx, S32 *str_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*************************************************************
        * Support ZiMo
        *************************************************************/
/*Vogins_20100625_start*/
    idx = index = mmi_am_ms_get_actual_index(idx);
/*Vogins_20100625_end*/
    if (!g_am_cntx.has_small_font)
    {
        if (index < g_am_cntx.shortcut_app_num) /* AM Shortcut app */
        {
            if (mmi_am_config_get_am_sc_info_by_appid(APPID_VAS))       /* AppStore Support */
            {
                if (index == 0) /* AppStore */
                {
                    *str_len = (S32) g_am_cntx.appstore_list.name_len;
                    return g_am_cntx.appstore_list.p_name;
                }
                else    /* Other AM Shortcut App */
                {
                    index--;
                    *str_len = (S32) g_am_cntx.shortcut_app_list[index].name_len;
                    return g_am_cntx.shortcut_app_list[index].p_name;
                }
            }
            else    /* AppStore dont support */
            {
                *str_len = (S32) g_am_cntx.shortcut_app_list[index].name_len;
                return g_am_cntx.shortcut_app_list[index].p_name;
            }
        }
        else if (idx < (g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num))    /* Rom app */
        {
            index = idx - g_am_cntx.shortcut_app_num;

            *str_len = g_am_cntx.rom_app_list[index].name_len;
            return g_am_cntx.rom_app_list[index].p_name;
        }
        else    /* download app */
        {
            mmi_am_ms_app_struct *p;

            index = idx - (g_am_ms_cntx.page_start_idx + g_am_ms_cntx.sc_app_num + g_am_ms_cntx.rom_app_num);
            p = sml_list_get(g_am_ms_cntx.app_list, index);

            if (p)
            {
                *str_len = p->name_len;
                return p->p_name;
            }
            else
            {
                return NULL;
            }
        }
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_draw_app_name_scrolling
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx         [IN]        
 *  x           [IN]        
 *  y           [IN]        
 *  width       [IN]        
 *  height      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_ms_draw_app_name_scrolling(S32 idx, S32 x, S32 y, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color border_color = gui_color(0, 0, 0);
    color cur_clor = *current_MMI_theme->list_normal_text_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*************************************************************
        * Support small font
        *************************************************************/
    if (g_am_cntx.has_small_font)
    {
        /* create scrolling text */
        gui_create_scrolling_text(
                                 &g_am_ms_cntx.scrolling_app_name,
                                 x,
                                 y,
                                 width,
                                 height,
                                 (UI_string_type) mmi_am_ms_get_app_name_by_idx(idx),
                                 mmi_am_ms_scroll_handler,
                                 mmi_am_ms_scroll_draw_bg,
                                 cur_clor,
                                 border_color);

        g_am_ms_cntx.scrolling_app_name.text_font = MMI_small_font;
        gui_show_scrolling_text(&g_am_ms_cntx.scrolling_app_name);
    }
    /*************************************************************
        * Support ZiMo
        *************************************************************/
    else
    {
        U8 *p;
        S32 str_len;
        gdi_color color;

        g_am_ms_cntx.scroll_x = 0;
        g_am_ms_cntx.scroll_zone_x1 = x;
        g_am_ms_cntx.scroll_zone_y1 = y;
        g_am_ms_cntx.scroll_zone_x2 = x + width - 1;
        g_am_ms_cntx.scroll_zone_y2 = y + height - 1;
        g_am_ms_cntx.scroll_counter = MMI_AM_MS_TEXT_SCROLL_PAUSE;
        color = gdi_act_color_from_rgb(255, cur_clor.r, cur_clor.g, cur_clor.b);

        p = mmi_am_ms_get_app_zimo_by_idx(idx, &str_len);
        gdi_layer_set_clip(
                          g_am_ms_cntx.scroll_zone_x1,
                          g_am_ms_cntx.scroll_zone_y1,
                          g_am_ms_cntx.scroll_zone_x2,
                          g_am_ms_cntx.scroll_zone_y2);
        mmi_am_draw_zimo(x, y, 0, str_len, p, str_len, MMI_AM_APP_NAME_H, color);
        gdi_layer_reset_clip();

        /* start scroll timer */
        gui_start_timer(MMI_AM_MS_SCROLL_TIME, mmi_am_ms_zimo_scroll_cb);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_scroll_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_ms_scroll_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_handle_scrolling_text(&g_am_ms_cntx.scrolling_app_name);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_scroll_draw_bg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1      [IN]        
 *  y1      [IN]        
 *  x2      [IN]        
 *  y2      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_ms_scroll_draw_bg(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_image_draw_id(g_am_ms_cntx.hl_x1, g_am_ms_cntx.hl_y1, g_am_ms_cntx.cfg->hl_icon_id);
    mmi_am_ms_draw_app_icon(
                           g_am_ms_cntx.hl_idx,
                           g_am_ms_cntx.page_start_idx,
                           g_am_ms_cntx.hl_x1,
                           g_am_ms_cntx.hl_y1,
                           g_am_ms_cntx.hl_x2,
                           g_am_ms_cntx.hl_y2);
    mmi_am_ms_draw_status_icon(
                              g_am_ms_cntx.hl_idx,
                              g_am_ms_cntx.hl_x1,
                              g_am_ms_cntx.hl_y1,
                              g_am_ms_cntx.hl_x2,
                              g_am_ms_cntx.hl_y2);
    gdi_layer_blt_previous(g_am_ms_cntx.hl_x1, g_am_ms_cntx.hl_y1, g_am_ms_cntx.hl_x2, g_am_ms_cntx.hl_y2);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_zimo_scroll_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_ms_zimo_scroll_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 text_width = g_am_ms_cntx.scroll_zone_x2 - g_am_ms_cntx.scroll_zone_x1 + 1;
    color cur_color = *current_MMI_theme->list_normal_text_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_am_ms_cntx.scroll_counter)
    {
        g_am_ms_cntx.scroll_counter--;
    }
    else
    {
        g_am_ms_cntx.scroll_x -= MMI_AM_MS_TEXT_SCROLL_SIZE;
        if (g_am_ms_cntx.scroll_x <= -(text_width + MMI_AM_MS_TEXT_SCROLL_GAP))
        {
            g_am_ms_cntx.scroll_x = text_width;
        }

        /* draw highlight icon */
        gdi_image_draw_id(g_am_ms_cntx.hl_x1, g_am_ms_cntx.hl_y1, g_am_ms_cntx.cfg->hl_icon_id);
        /* draw app icon */
        mmi_am_ms_draw_app_icon(
                               g_am_ms_cntx.hl_idx,
                               g_am_ms_cntx.page_start_idx,
                               g_am_ms_cntx.hl_x1,
                               g_am_ms_cntx.hl_y1,
                               g_am_ms_cntx.hl_x2,
                               g_am_ms_cntx.hl_y2);

        /* draw status icon */
        mmi_am_ms_draw_status_icon(
                                  g_am_ms_cntx.hl_idx,
                                  g_am_ms_cntx.hl_x1,
                                  g_am_ms_cntx.hl_y1,
                                  g_am_ms_cntx.hl_x2,
                                  g_am_ms_cntx.hl_y2);

        /* draw zimo */
        {
            U8 *p;
            S32 str_len;
            gdi_color color;

            color = gdi_act_color_from_rgb(255, cur_color.r, cur_color.g, cur_color.b);
            p = mmi_am_ms_get_app_zimo_by_idx(g_am_ms_cntx.hl_idx, &str_len);
            gdi_layer_set_clip(
                              g_am_ms_cntx.scroll_zone_x1,
                              g_am_ms_cntx.scroll_zone_y1,
                              g_am_ms_cntx.scroll_zone_x2,
                              g_am_ms_cntx.scroll_zone_y2);
            mmi_am_draw_zimo(
                            g_am_ms_cntx.scroll_zone_x1 + g_am_ms_cntx.scroll_x,
                            g_am_ms_cntx.scroll_zone_y1,
                            0,
                            str_len,
                            p,
                            str_len,
                            MMI_AM_APP_NAME_H,
                            color);
            gdi_layer_reset_clip();
        }

        /* blt */
        gdi_layer_blt_previous(g_am_ms_cntx.hl_x1, g_am_ms_cntx.hl_y1, g_am_ms_cntx.hl_x2, g_am_ms_cntx.hl_y2);
    }
    /* start scroll timer */
    gui_start_timer(MMI_AM_MS_SCROLL_TIME, mmi_am_ms_zimo_scroll_cb);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_get_icon_resid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static U16 mmi_am_ms_get_icon_resid(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* AppStore support */
    if (mmi_am_config_get_am_sc_info_by_appid(APPID_VAS))
    {
        if (idx == 0)
        {
            return g_am_cntx.appstore_list.icon_id;
        }
        else
        {
            idx--;
            return g_am_cntx.shortcut_app_list[idx].icon_id;
        }
    }
    else
    {
        return g_am_cntx.shortcut_app_list[idx].icon_id;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_get_icon_ptr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx                 [IN]        
 *  page_start_idx      [IN]        
 *  icon_size           [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
static U8 *mmi_am_ms_get_icon_ptr(S32 idx, S32 page_start_idx, U32 *icon_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (idx < g_am_cntx.shortcut_app_num)
    {
        return NULL;
    }

    /* Rom App */
    if (idx < g_am_cntx.rom_app_num + g_am_cntx.shortcut_app_num)
    {
        mmi_am_rom_app_struct *p = mmi_am_get_rom_appinfo_by_idx(idx);

        if (p)
        {
            *icon_size = p->icon_size;
            return p->p_icon;
        }
    }
    /* Download App */
    else
    {
        mmi_am_ms_app_struct *p;

        index = idx - (page_start_idx + g_am_ms_cntx.rom_app_num + g_am_ms_cntx.sc_app_num);
        p = sml_list_get(g_am_ms_cntx.app_list, index);
        if (p)
        {
            *icon_size = p->icon_size;
            return p->p_icon;
        }
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_build_app_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_am_ms_build_app_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, num;
    S32 n_per_row;
    S32 n_per_col;
    mmi_am_vxp_file_struct *vxp_p;
    mmi_am_ms_app_struct *app_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_ms_build_app_list() ------- [S]");

    n_per_row = g_am_ms_cntx.cfg->app_num_per_row;
    n_per_col = g_am_ms_cntx.cfg->app_num_per_col;

    /* get the number of apps which need to add to app list */
    num = (n_per_row * n_per_col)       /* number per screen */
          - g_am_cntx.shortcut_app_num    /* number of shortcut apps displayed on the cur screen */
          - g_am_cntx.rom_app_num         /* number of rom apps */
#ifdef AM_MS_CACHE
          + n_per_row;                    /* cache one row */
#else 
          ;
#endif 

    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_ms_build_app_list() -- num:%d", num);

    for (i = 0; (i < num) && (i < sml_list_size(g_am_cntx.vxp_file_list)); i++)
    {
        S8 vxp_path_log[MMI_AM_MAX_APP_FILE_PATH];

        memset(vxp_path_log, 0, sizeof(vxp_path_log));
        vxp_p = sml_list_get(g_am_cntx.vxp_file_list, i);
        mmi_wcs_to_asc((PS8) vxp_path_log, (PU16) vxp_p->path);
        MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "vxp_file_list[%d] -- path:%s", i, vxp_path_log);

        app_p = mmi_am_ms_get_appinfo_from_vxplist(vxp_p);
        if (app_p)
        {
            /* set display index */
            app_p->idx = i + (g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num);

            /* add the app to app_list */
            if (g_am_ms_cntx.app_list)
            {
                sml_list_add(g_am_ms_cntx.app_list, app_p, -1);
            }
            else
            {
                mmi_am_ms_release_applist_node(app_p);
            }

            MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "app_list[%d] -- idx:%d", i, app_p->idx);
            MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "app_list[%d] -- is_hs_shortcut:%d", i, app_p->is_hs_shortcut);
            MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "app_list[%d] -- is_bg_started:%d", i, app_p->is_bg_started);
            MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "app_list[%d] -- p_icon:0x%08x", i, app_p->p_icon);
            MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "app_list[%d] -- icon_size:%d", i, app_p->icon_size);
            MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "app_list[%d] -- p_name:0x%08x", i, app_p->p_name);
            MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "app_list[%d] -- name_size:%d", i, app_p->name_size);
            MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "app_list[%d] -- name_len:%d", i, app_p->name_len);

        }
        else
        {
            return MMI_FALSE;
        }
    }

    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_ms_build_app_list() ------- [E]");

    return MMI_TRUE;
}

/*Vogins_20100625_start*/
/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_update_app_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  page_start_idx      [IN]        
 *  page_end_idx        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_am_ms_update_app_list(S32 page_start_idx, S32 page_end_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    S32 first_idx;                  /* the 1st index should be in app_list */
    S32 disp_num_max;               /* the max number of download app displayed on the current screen */
    MMI_BOOL is_first_idx_exist;    /* is the first index (first_idx) in the app_list */
    S32 vxp_list_idx, app_list_idx; /*  */
    mmi_am_ms_app_struct *p;
    mmi_am_ms_app_struct *app_p;
    mmi_am_vxp_file_struct *vxp_p;
    S32 position;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_MS_UPDATE_APP_LIST_S);

    first_idx = page_start_idx + g_am_ms_cntx.sc_app_num + g_am_ms_cntx.rom_app_num;
    disp_num_max = page_end_idx - first_idx + 1;

    /* all the app on the current screen are shortcut app or rom app */
    if (first_idx >= page_start_idx + (g_am_ms_cntx.cfg->app_num_per_col * g_am_ms_cntx.cfg->app_num_per_row))
    {
        while (sml_list_size(g_am_ms_cntx.app_list) > num_app_move)
        {
            p = sml_list_get(g_am_ms_cntx.app_list, num_app_move);
            if (p)
            {
                mmi_am_ms_release_applist_node(p);
                sml_list_remove(g_am_ms_cntx.app_list, num_app_move);
            }
            else
            {
                break;
            }
        }
        return MMI_TRUE;
    }

    /* check if first_idx in the app_list */
    is_first_idx_exist = MMI_FALSE;
    for (i = 0; i < sml_list_size(g_am_ms_cntx.app_list); i++)
    {
        p = sml_list_get(g_am_ms_cntx.app_list, i);
        if (!p)
        {
            MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_MS_UPDATE_APP_LIST_E1);
            return MMI_FALSE;
        }
        if (p->idx == first_idx)
        {
            if (!p->is_bg_started)
            {
                is_first_idx_exist = MMI_TRUE;
                break;
            }
            else
                first_idx++;
        }
    }

    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_MS_UPDATE_APP_LIST_1, first_idx, is_first_idx_exist);

    if (is_first_idx_exist)
    {
        /* 1. delete the nodes which are not displayed on the screen (from front to back) */
        i = 0;
        while (sml_list_size(g_am_ms_cntx.app_list))
        {
            p = sml_list_get(g_am_ms_cntx.app_list, i);
            if (p && (p->idx != first_idx))
            {
                if (p->is_bg_started)
                {
                    i++;
                    continue;
                }
                MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_MS_UPDATE_APP_LIST_2, p->idx);
                /* delete the node */
                mmi_am_ms_release_applist_node(p);
                sml_list_remove(g_am_ms_cntx.app_list, i);
            }
            else
            {
                break;
            }
        }

        /* 2. delete the nodes which are not displayed on the screen (from back to front) */
        while (sml_list_size(g_am_ms_cntx.app_list) > disp_num_max)
        {
            p = sml_list_get(g_am_ms_cntx.app_list, sml_list_size(g_am_ms_cntx.app_list) - 1);
            if (p)
            {
                MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_MS_UPDATE_APP_LIST_3, sml_list_size(g_am_ms_cntx.app_list) - 1);
                /* delete the last node */
                mmi_am_ms_release_applist_node(p);
                sml_list_remove(g_am_ms_cntx.app_list, sml_list_size(g_am_ms_cntx.app_list) - 1);
            }
        }

        /* 3. add new node to end of the app_list, i is the index added to end of the app_list */
        for (i = (page_start_idx + g_am_ms_cntx.sc_app_num + g_am_ms_cntx.rom_app_num + sml_list_size(g_am_ms_cntx.app_list)); i <= page_end_idx; i++)
        {
#ifdef __VRE_AM_08AB__
            if (i >= g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num + sml_list_size(g_am_cntx.vxp_file_list))
                break;
#endif
            vxp_list_idx = i - g_am_cntx.shortcut_app_num - g_am_cntx.rom_app_num;
            vxp_p = sml_list_get(g_am_cntx.vxp_file_list, vxp_list_idx);
            MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_MS_UPDATE_APP_LIST_4, i, vxp_list_idx);

            app_p = mmi_am_ms_get_appinfo_from_vxplist(vxp_p);
            if (app_p)
            {
                /* set display index */
                app_p->idx = i;

                /* add the app to app_list */
                sml_list_add(g_am_ms_cntx.app_list, app_p, -1);
            }
            else
            {
                MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_MS_UPDATE_APP_LIST_E1);
                return MMI_FALSE;
            }
        }
    }
    else
    {
        for (i = first_idx; i <= page_end_idx; i++)
        {
            app_list_idx = i - (page_start_idx + g_am_ms_cntx.sc_app_num + g_am_ms_cntx.rom_app_num);
            p = sml_list_get(g_am_ms_cntx.app_list, app_list_idx);
            if (p && (p->idx == i))
            {
                continue;
            }

            /* 1. add a new node in front of app_list */
            vxp_list_idx = i - g_am_cntx.shortcut_app_num - g_am_cntx.rom_app_num;
            vxp_p = sml_list_get(g_am_cntx.vxp_file_list, vxp_list_idx);
            MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_MS_UPDATE_APP_LIST_5, i, vxp_list_idx);

            app_p = mmi_am_ms_get_appinfo_from_vxplist(vxp_p);
            if (app_p)
            {
                /* set display index */
                app_p->idx = i;

                /* add the app to app_list */
                sml_list_add(g_am_ms_cntx.app_list, app_p, app_list_idx);
            }
            else
            {
                MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_MS_UPDATE_APP_LIST_E2);
                return MMI_FALSE;
            }

            /* 2. delete a node from back of the app_list */
            p = sml_list_get(g_am_ms_cntx.app_list, sml_list_size(g_am_ms_cntx.app_list) - 1);
            if ((p) && ((p->idx < page_start_idx) || (p->idx > page_end_idx)))
            {
                MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_MS_UPDATE_APP_LIST_6, p->idx);
                mmi_am_ms_release_applist_node(p);
                sml_list_remove(g_am_ms_cntx.app_list, sml_list_size(g_am_ms_cntx.app_list) - 1);
            }
        }

        /* delete node which dont display on the current screen (from back to front) */
        while (sml_list_size(g_am_ms_cntx.app_list) > disp_num_max)
        {
            p = sml_list_get(g_am_ms_cntx.app_list, sml_list_size(g_am_ms_cntx.app_list) - 1);
            if (p && (p->idx != page_end_idx))
            {
                /* delete the node */
                MMI_TRACE(
                         MMI_FW_TRC_G1_FRM,
                         TRC_MMI_AM_MS_UPDATE_APP_LIST_7,
                         p->idx,
                         sml_list_size(g_am_ms_cntx.app_list) - 1);
                mmi_am_ms_release_applist_node(p);
                sml_list_remove(g_am_ms_cntx.app_list, sml_list_size(g_am_ms_cntx.app_list) - 1);
            }
            else
            {
                break;
            }
        }

    }
#ifdef __VRE_AM_08AB__
    while ( sml_list_size(g_am_ms_cntx.app_list))
    {
        p = sml_list_get(g_am_ms_cntx.app_list, sml_list_size(g_am_ms_cntx.app_list) - 1);
        if (p->idx >= g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num + sml_list_size(g_am_cntx.vxp_file_list))
        {
            /* delete the node */
            MMI_TRACE(
                     MMI_FW_TRC_G1_FRM,
                     TRC_MMI_AM_MS_UPDATE_APP_LIST_7,
                     p->idx,
                     sml_list_size(g_am_ms_cntx.app_list) - 1);
            mmi_am_ms_release_applist_node(p);
            sml_list_remove(g_am_ms_cntx.app_list, sml_list_size(g_am_ms_cntx.app_list) - 1);
        }
        else
        {
            break;
        }
    }
#endif
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_MS_UPDATE_APP_LIST_E3);

    return MMI_TRUE;
}
/*Vogins_20100625_end*/

/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_get_appinfo_from_vxplist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vxp_p       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mmi_am_ms_app_struct *mmi_am_ms_get_appinfo_from_vxplist(mmi_am_vxp_file_struct *vxp_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    S32 cache_size = MMI_AM_LOAD_RES_BUF_SIZE;
    S8 *cache_buf = NULL;
    mmi_am_ms_app_struct *app_p;
    S32 res_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_ms_get_appinfo_from_vxplist() ------- [S]");

    /* allocate cache buffer */
    cache_buf = mmi_am_calloc(cache_size);
    if (!cache_buf)
    {
        MMI_AM_ASSERT(cache_buf != NULL);
        return NULL;
    }

    app_p = mmi_am_calloc(sizeof(mmi_am_ms_app_struct));
    if (!app_p)
    {
        MMI_AM_ASSERT(app_p != NULL);
        mmi_am_free(cache_buf);
        return NULL;
    }

    /* set app full path */
    mmi_wcscpy(app_p->path, vxp_p->path);

    /* get icon and name */
    if (mmi_am_vre_load_resource_from_file((PU16) app_p->path, MMI_AM_APP_LOGO, &res_size, cache_buf, cache_size))
    {
        MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_ms_get_appinfo_from_vxplist() -- res_size:%d", res_size);
        /* get app ICON */
        ret = mmi_am_get_gif_data((PU8) cache_buf, &app_p->p_icon, &app_p->icon_size);
        MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "icon_size:%d", app_p->icon_size);
        MMI_AM_ASSERT(app_p->p_icon != NULL);
        if (!ret)
        {
            mmi_am_free(cache_buf);
            mmi_am_ms_release_applist_node(app_p);
            return NULL;
        }

        /* get app name */
        ret = mmi_am_get_app_name(app_p->path, (PU8) cache_buf, (void **)&app_p->p_name, &app_p->name_len);
        MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "name_len:%d", app_p->name_len);
        MMI_AM_ASSERT(app_p->p_name != NULL);
        if (!ret)
        {
            mmi_am_free(cache_buf);
            mmi_am_ms_release_applist_node(app_p);
            return NULL;
        }
    }
    else if (mmi_am_vre_load_resource_from_file
             ((PU16) app_p->path, MMI_AM_APP_V20_LOGO, &res_size, cache_buf, cache_size))
    {
        /* support small font */
        if (g_am_cntx.has_small_font)
        {
            app_p->p_name = (PU8) GetString(STR_ID_AM_APP_NAME_VRE20);
            app_p->name_len = mmi_wcslen((PU16) GetString(STR_ID_AM_APP_NAME_VRE20));
        }
        else
        {
            mmi_am_get_zimo_string_data((PU8) AM_App_VRE20, &app_p->p_name, (PS32) & app_p->name_len);
        }
    }
    else    /* Use default ICON and Zimo */
    {
        /* support small font */
        if (g_am_cntx.has_small_font)
        {
            app_p->p_name = (PU8) GetString(STR_ID_AM_APP_NAME_DEFAULT);        /* NULL; */
            app_p->name_len = mmi_wcslen((PU16) GetString(STR_ID_AM_APP_NAME_DEFAULT)); /* NULL; */
        }
        else
        {
            mmi_am_get_zimo_string_data((PU8) AM_App_Default, &app_p->p_name, (PS32) & app_p->name_len);
        }
    }

    /* Whether the application is set to HS shortcut. */
#ifdef __MMI_VUI_HOMESCREEN__
    if (mmi_am_is_set_as_shortcut(app_p->path))
    {
        app_p->is_hs_shortcut = MMI_TRUE;
    }
    else
#endif /* __MMI_VUI_HOMESCREEN__ */ 
    {
        app_p->is_hs_shortcut = MMI_FALSE;
    }

    /* Whether the application is running in the background. */
    if (mmi_am_app_is_bg_running(app_p->path))
    {
        app_p->is_bg_started = MMI_TRUE;
    }
    else
    {
        app_p->is_bg_started = MMI_FALSE;
    }

    /* release cache buffer */
    mmi_am_free(cache_buf);

    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_ms_get_appinfo_from_vxplist() ------- [E]");
    return app_p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_is_app_download
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_am_ms_is_app_download(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_download = MMI_FALSE;
    S32 index = idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*************************************************************
        * AM Shortcut app
        *************************************************************/
/*Vogins_20100625_start*/
    idx = index = mmi_am_ms_get_actual_index(idx);
/*Vogins_20100625_end*/
    if (index < g_am_cntx.shortcut_app_num)
    {
        if (mmi_am_config_get_am_sc_info_by_appid(APPID_VAS))   /* AppStore support */
        {
            /*-------------------------------------------------------------------
                    - AppStore
                    --------------------------------------------------------------------*/
            if (index == 0)
            {
                if (g_am_cntx.appstore_list.is_downloaded)  /* AppStore downloaded */
                {
                    is_download = MMI_TRUE;
                }
                else    /* AppStore dont download */
                {
                    is_download = MMI_FALSE;
                }
            }
            /*-------------------------------------------------------------------
                    - other AM Shortcut app
                    --------------------------------------------------------------------*/
            else
            {
                index--;
                if (g_am_cntx.shortcut_app_list[index].is_downloaded)   /* shortcut app downloaded */
                {
                    is_download = MMI_TRUE;
                }
                else    /* shortcut app dont download */
                {
                    is_download = MMI_FALSE;
                }
            }
        }
        else    /* dont support AppStore */
        {
            if (g_am_cntx.shortcut_app_list[index].is_downloaded)       /* shortcut app downloaded */
            {
                is_download = MMI_TRUE;
            }
            else    /* shortcut app dont download */
            {
                is_download = MMI_FALSE;
            }
        }
    }
    else
    {
        is_download = MMI_TRUE;
    }

    return is_download;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_is_app_bg_running
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_am_ms_is_app_bg_running(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_bg_running = MMI_FALSE;
    S32 index = idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/*Vogins_20100625_start*/
    idx = index = mmi_am_ms_get_actual_index(idx);
/*Vogins_20100625_end*/
    /*************************************************************
        * AM Shortcut app
        *************************************************************/
    if (index < g_am_cntx.shortcut_app_num)
    {
        if (mmi_am_config_get_am_sc_info_by_appid(APPID_VAS))   /* AppStore support */
        {
            /*-------------------------------------------------------------------
                    - AppStore
                    --------------------------------------------------------------------*/
            if (index == 0)
            {
                if (g_am_cntx.appstore_list.is_downloaded)  /* AppStore downloaded */
                {
                    /*Vogins Michael 100427 begin*/
                    if (g_am_cntx.appstore_list.is_bg_started 
                        && mmi_am_app_is_bg_running(g_am_cntx.appstore_list.path[0]))  /* BG running? */
                    /*Vogins Michael 100427 end*/
                    {
                        is_bg_running = MMI_TRUE;
                    }
                    else
                    {
                        is_bg_running = MMI_FALSE;
                    }
                }
                else    /* AppStore dont download */
                {
                    is_bg_running = MMI_FALSE;
                }
            }
            /*-------------------------------------------------------------------
                    - other AM Shortcut app
                    --------------------------------------------------------------------*/
            else
            {
                index--;
                if (g_am_cntx.shortcut_app_list[index].is_downloaded)   /* shortcut app downloaded */
                {
                    /*Vogins Michael 100427 begin*/
                    if (g_am_cntx.shortcut_app_list[index].is_bg_started
                        && mmi_am_app_is_bg_running(g_am_cntx.shortcut_app_list[index].path))       /* BG running? */
                    /*Vogins Michael 100427 end*/
                    {
                        is_bg_running = MMI_TRUE;
                    }
                    else
                    {
                        is_bg_running = MMI_FALSE;
                    }
                }
                else    /* shortcut app dont download */
                {
                    is_bg_running = MMI_FALSE;
                }
            }
        }
        /* dont support AppStore */
        else
        {
            if (g_am_cntx.shortcut_app_list[index].is_downloaded)       /* shortcut app downloaded */
            {
                /*Vogins Michael 100427 begin*/
                if (g_am_cntx.shortcut_app_list[index].is_bg_started 
                    && mmi_am_app_is_bg_running(g_am_cntx.shortcut_app_list[index].path))   /* BG running? */
                /*Vogins Michael 100427 end*/
                {
                    is_bg_running = MMI_TRUE;
                }
                else
                {
                    is_bg_running = MMI_FALSE;
                }
            }
            else    /* shortcut app dont download */
            {
                is_bg_running = MMI_FALSE;
            }
        }
    }
    /*************************************************************
        * Rom app
        *************************************************************/
    else if (idx < (g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num))
    {
        /*Vogins Michael 100427 begin*/
        if (g_am_cntx.rom_app_list[idx - g_am_cntx.shortcut_app_num].is_bg_started
            && mmi_am_app_is_bg_running(g_am_cntx.rom_app_list[idx - g_am_cntx.shortcut_app_num].path))     /* BG running? */ //michael
        /*Vogins Michael 100427 end*/
        {
            is_bg_running = MMI_TRUE;
        }
        else
        {
            is_bg_running = MMI_FALSE;
        }
    }
    /*************************************************************
        * download app
        *************************************************************/
    else
    {
        mmi_am_ms_app_struct *p;

        index = idx - (g_am_ms_cntx.page_start_idx + g_am_ms_cntx.sc_app_num + g_am_ms_cntx.rom_app_num);
        p = sml_list_get(g_am_ms_cntx.app_list, index);
        if (!p)
        {
            MMI_AM_ASSERT(0);
        }
        /*Vogins Michael 100427 begin*/
        if (p->is_bg_started && mmi_am_app_is_bg_running(p->path))   /* BG running? */
        /*Vogins Michael 100427 end*/
        {
            is_bg_running = MMI_TRUE;
        }
        else
        {
            is_bg_running = MMI_FALSE;
        }
    }

    return is_bg_running;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_is_rom_app
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_am_ms_is_rom_app(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/*Vogins_20100710_start*/
    idx = mmi_am_ms_get_actual_index(idx);
/*Vogins_20100710_end*/
    if (idx >= g_am_cntx.shortcut_app_num && idx < (g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num))
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}
/*Vogins_20100710_start*/
/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_is_rom_app
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_am_ms_is_rom_app_by_path(U16 *app_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
    idx = mmi_am_ms_get_actual_index(idx);
    if (idx >= g_am_cntx.shortcut_app_num && idx < (g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num))
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;*/


    for (i = 0; i < g_am_cntx.rom_app_num; i++)
    {
        if (mmi_wcscmp(g_am_cntx.rom_app_list[i].path, app_path) == 0)
            return MMI_TRUE;
    }
    return MMI_FALSE;
}
/*Vogins_20100710_end*/
    #ifdef __MMI_VUI_HOMESCREEN__


/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_is_app_set_hs_shortcut
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_am_ms_is_app_set_hs_shortcut(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_hs_shortcut = MMI_FALSE;
    S32 index = idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*************************************************************
        * AM Shortcut app
        *************************************************************/
    /*Vogins_20100625_start*/
    idx = index = mmi_am_ms_get_actual_index(idx);
/*Vogins_20100625_end*/
    if (index < g_am_cntx.shortcut_app_num)
    {
        if (mmi_am_config_get_am_sc_info_by_appid(APPID_VAS))   /* AppStore support */
        {
            /*-------------------------------------------------------------------
                    - AppStore
                    --------------------------------------------------------------------*/
            if (index == 0)
            {
                if (g_am_cntx.appstore_list.is_downloaded)  /* AppStore downloaded */
                {
                    if (g_am_cntx.appstore_list.is_hs_shortcut) /* HS shortcut? */
                    {
                        is_hs_shortcut = MMI_TRUE;
                    }
                    else
                    {
                        is_hs_shortcut = MMI_FALSE;
                    }
                }
                else    /* AppStore dont download */
                {
                    is_hs_shortcut = MMI_FALSE;
                }
            }
            /*-------------------------------------------------------------------
                    - other AM Shortcut app
                    --------------------------------------------------------------------*/
            else
            {
                index--;
                if (g_am_cntx.shortcut_app_list[index].is_downloaded)   /* shortcut app downloaded */
                {
                    if (g_am_cntx.shortcut_app_list[index].is_hs_shortcut)      /* HS shortcut? */
                    {
                        is_hs_shortcut = MMI_TRUE;
                    }
                    else
                    {
                        is_hs_shortcut = MMI_FALSE;
                    }
                }
                else    /* shortcut app dont download */
                {
                    is_hs_shortcut = MMI_FALSE;
                }
            }
        }
        else    /* dont support AppStore */
        {
            if (g_am_cntx.shortcut_app_list[index].is_downloaded)       /* shortcut app downloaded */
            {
                if (g_am_cntx.shortcut_app_list[index].is_hs_shortcut)  /* HS shortcut? */
                {
                    is_hs_shortcut = MMI_TRUE;
                }
                else
                {
                    is_hs_shortcut = MMI_FALSE;
                }
            }
            else    /* shortcut app dont download */
            {
                is_hs_shortcut = MMI_FALSE;
            }
        }
    }
    /*************************************************************
        * Rom app
        *************************************************************/
    else if (idx < (g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num))
    {
        if (g_am_cntx.rom_app_list[idx - g_am_cntx.shortcut_app_num].is_hs_shortcut)    /* HS shortcut? */
        {
            is_hs_shortcut = MMI_TRUE;
        }
        else
        {
            is_hs_shortcut = MMI_FALSE;
        }
    }
    /*************************************************************
        * download app
        *************************************************************/
    else
    {
        mmi_am_ms_app_struct *p;

        index = idx - (g_am_ms_cntx.page_start_idx + g_am_ms_cntx.sc_app_num + g_am_ms_cntx.rom_app_num);
        p = sml_list_get(g_am_ms_cntx.app_list, index);
        if (!p)
        {
            MMI_AM_ASSERT(0);
        }

        if (p->is_hs_shortcut)  /* HS shortcut? */
        {
            is_hs_shortcut = MMI_TRUE;
        }
        else
        {
            is_hs_shortcut = MMI_FALSE;
        }
    }

    return is_hs_shortcut;
}
    #endif /* __MMI_VUI_HOMESCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_get_app_path_by_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 *mmi_am_ms_get_app_path_by_index(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/*Vogins_20100625_start*/
    idx = index = mmi_am_ms_get_actual_index(idx);
/*Vogins_20100625_end*/
    /*************************************************************
        * AM Shortcut app
        *************************************************************/
    if (index < g_am_cntx.shortcut_app_num)
    {
        if (mmi_am_config_get_am_sc_info_by_appid(APPID_VAS))   /* AppStore support */
        {
            /*-------------------------------------------------------------------
                    - AppStore
                    --------------------------------------------------------------------*/
            if (index == 0)
            {
                if (g_am_cntx.appstore_list.is_downloaded)
                {
                    return g_am_cntx.appstore_list.path[0];
                }
                else
                {
                    return NULL;
                }
            }
            /*-------------------------------------------------------------------
                    - other AM Shortcut app
                    --------------------------------------------------------------------*/
            else
            {
                index--;
                if (g_am_cntx.shortcut_app_list[index].is_downloaded)   /* shortcut app downloaded */
                {
                    return g_am_cntx.shortcut_app_list[index].path;
                }
                else    /* shortcut app dont download */
                {
                    /* MMI_AM_ASSERT(0); */
                    return NULL;
                }
            }
        }
        else    /* dont support AppStore */
        {
            if (g_am_cntx.shortcut_app_list[index].is_downloaded)       /* shortcut app downloaded */
            {
                return g_am_cntx.shortcut_app_list[index].path;
            }
            else    /* shortcut app dont download */
            {
                /* MMI_AM_ASSERT(0); */
                return NULL;
            }
        }
    }
    /*************************************************************
        * Rom app
        *************************************************************/
    else if (idx < (g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num))
    {
        return g_am_cntx.rom_app_list[idx - g_am_cntx.shortcut_app_num].path;
    }
    /*************************************************************
        * download app
        *************************************************************/
    else
    {
        mmi_am_ms_app_struct *p;

        index = idx - (g_am_ms_cntx.page_start_idx + g_am_ms_cntx.sc_app_num + g_am_ms_cntx.rom_app_num);
        p = sml_list_get(g_am_ms_cntx.app_list, index);
        if (!p)
        {
            /* MMI_AM_ASSERT(0); */
            return NULL;
        }

        return p->path;
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_get_app_icon_by_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx             [IN]        
 *  icon_size       [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
U8 *mmi_am_ms_get_app_icon_by_index(S32 idx, U32 *icon_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/*Vogins_20100625_start*/
    idx = index = mmi_am_ms_get_actual_index(idx);
/*Vogins_20100625_end*/
    /*************************************************************
        * AM Shortcut app
        *************************************************************/
    if (index < g_am_cntx.shortcut_app_num)
    {
        if (mmi_am_config_get_am_sc_info_by_appid(APPID_VAS))   /* AppStore support */
        {
            /*-------------------------------------------------------------------
                    - AppStore
                    --------------------------------------------------------------------*/
            if (index == 0)
            {
                *icon_size = (U32) gdi_image_get_buf_len((PU8) GetImage(g_am_cntx.appstore_list.icon_id));
                return(PU8) gdi_image_get_buf_ptr((U8*) GetImage(g_am_cntx.appstore_list.icon_id));
            }
            /*-------------------------------------------------------------------
                    - other AM Shortcut app
                    --------------------------------------------------------------------*/
            else
            {
                index--;
                if (g_am_cntx.shortcut_app_list[index].is_downloaded)   /* shortcut app downloaded */
                {
                    *icon_size =
                    (U32) gdi_image_get_buf_len((PU8) GetImage(g_am_cntx.shortcut_app_list[index].icon_id));
                    return(PU8) gdi_image_get_buf_ptr((U8*) GetImage(g_am_cntx.shortcut_app_list[index].icon_id));
                }
                else    /* shortcut app dont download */
                {
                    MMI_AM_ASSERT(0);
                    return NULL;
                }
            }
        }
        else    /* dont support AppStore */
        {
            if (g_am_cntx.shortcut_app_list[index].is_downloaded)       /* shortcut app downloaded */
            {
                *icon_size = (U32) gdi_image_get_buf_len((PU8) GetImage(g_am_cntx.shortcut_app_list[index].icon_id));
                return(PU8) gdi_image_get_buf_ptr((U8*) GetImage(g_am_cntx.shortcut_app_list[index].icon_id));
            }
            else    /* shortcut app dont download */
            {
                MMI_AM_ASSERT(0);
                return NULL;
            }
        }
    }
    /*************************************************************
        * Rom app
        *************************************************************/
    else if (idx < (g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num))
    {
        *icon_size = (U32) g_am_cntx.rom_app_list[idx - g_am_cntx.shortcut_app_num].icon_size;
        return g_am_cntx.rom_app_list[idx - g_am_cntx.shortcut_app_num].p_icon;
    }
    /*************************************************************
        * download app
        *************************************************************/
    else
    {
        mmi_am_ms_app_struct *p;

        index = idx - (g_am_ms_cntx.page_start_idx + g_am_ms_cntx.sc_app_num + g_am_ms_cntx.rom_app_num);
        p = sml_list_get(g_am_ms_cntx.app_list, index);
        if (!p)
        {
            MMI_AM_ASSERT(0);
            return NULL;
        }

        *icon_size = (U32) p->icon_size;
        return p->p_icon;
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_delete_node_from_applist_by_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_ms_delete_node_from_applist_by_index(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/*Vogins_20100625_start*/
    idx = index = mmi_am_ms_get_actual_index(idx);
/*Vogins_20100625_end*/
    if (idx < (g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num))
    {
        return;
    }
    else
    {
        index = idx - (g_am_ms_cntx.page_start_idx + g_am_ms_cntx.sc_app_num + g_am_ms_cntx.rom_app_num);

        /* delete the node */
        mmi_am_ms_release_applist_node_ex(index);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_set_app_download
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx         [IN]        
 *  driver      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_ms_set_app_download(S32 idx, S8 driver)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = idx, i;
    S8 temp_path[MMI_AM_MAX_SHORTCUT_APP_FILE_PATH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/*Vogins_20100625_start*/
    idx = index = mmi_am_ms_get_actual_index(idx);
/*Vogins_20100625_end*/
    memset(temp_path, 0, sizeof(temp_path));

    /*************************************************************
        * AM Shortcut app
        *************************************************************/
    if (index < g_am_cntx.shortcut_app_num)
    {
/*Vogins_20100625_start*/
        if (mmi_am_config_get_am_sc_info_by_appid(APPID_VAS))   /* AppStore support */
        {
            /*-------------------------------------------------------------------
                    - AppStore
                    --------------------------------------------------------------------*/
            if (index == 0)
            {
                /* AppStore downloaded */
                g_am_cntx.appstore_list.is_downloaded = MMI_TRUE;

                /* Set app path */
                sprintf(temp_path, "%c:\\%s\\%s", driver, MMI_AM_VRE_HOME_DIR, MMI_AM_AS_FILE_NAME);
                mmi_asc_to_wcs(g_am_cntx.appstore_list.path[0], (PS8) temp_path);
            }
            /*-------------------------------------------------------------------
                    - other AM Shortcut app
                    --------------------------------------------------------------------*/
            else
            {
                /* shortcut app downloaded */
                mmi_am_shortcut_info_struct *sc_info;
                index--;
                g_am_cntx.shortcut_app_list[index].is_downloaded = MMI_TRUE;
                sc_info = mmi_am_config_get_am_sc_list();
                /* Set app path */
                for (i = 0; i < g_am_cntx.shortcut_app_num; i++)
                {
                    if (g_am_cntx.shortcut_app_list[index].icon_id == sc_info[i].icon_id)
                    {
                        break;
                    }
                }
                sprintf(
                       temp_path,
                       "%c:\\%s\\%s",
                       driver,
                       MMI_AM_VRE_HOME_DIR,
                       mmi_am_config_get_am_sc_name_by_idx(i));
                mmi_asc_to_wcs(g_am_cntx.shortcut_app_list[index].path, (PS8) temp_path);
            }
        }
        else    /* dont support AppStore */
        {
            /* shortcut app downloaded */
            mmi_am_shortcut_info_struct *sc_info;
            g_am_cntx.shortcut_app_list[index].is_downloaded = MMI_TRUE;
            sc_info = mmi_am_config_get_am_sc_list();
            /* Set app path */
            for (i = 0; i < g_am_cntx.shortcut_app_num; i++)
            {
                if (g_am_cntx.shortcut_app_list[index].icon_id == sc_info[i].icon_id)
                {
                    break;
                }
            }   
            sprintf(temp_path, "%c:\\%s\\%s", driver, MMI_AM_VRE_HOME_DIR, mmi_am_config_get_am_sc_name_by_idx(i));
            mmi_asc_to_wcs(g_am_cntx.shortcut_app_list[index].path, (PS8) temp_path);
        }
/*Vogins_20100625_end*/
    }
    /*************************************************************
        * Rom app or download app
        *************************************************************/
    else
    {
        MMI_AM_ASSERT(0);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_set_app_hs_shortcut
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_ms_set_app_hs_shortcut(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*************************************************************
        * AM Shortcut app
        *************************************************************/
/*Vogins_20100625_start*/
    idx = index = mmi_am_ms_get_actual_index(idx);
/*Vogins_20100625_end*/
    if (index < g_am_cntx.shortcut_app_num)
    {
        if (mmi_am_config_get_am_sc_info_by_appid(APPID_VAS))   /* AppStore support */
        {
            /*-------------------------------------------------------------------
                    - AppStore
                    --------------------------------------------------------------------*/
            if (index == 0)
            {
                g_am_cntx.appstore_list.is_hs_shortcut = MMI_TRUE;
            }
            /*-------------------------------------------------------------------
                    - other AM Shortcut app
                    --------------------------------------------------------------------*/
            else
            {
                index--;
                g_am_cntx.shortcut_app_list[index].is_hs_shortcut = MMI_TRUE;
            }
        }
        else    /* dont support AppStore */
        {
            g_am_cntx.shortcut_app_list[index].is_hs_shortcut = MMI_TRUE;
        }
    }
    /*************************************************************
        * Rom app
        *************************************************************/
    else if (idx < (g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num))
    {
        g_am_cntx.rom_app_list[idx - g_am_cntx.shortcut_app_num].is_hs_shortcut = MMI_TRUE;
    }
    /*************************************************************
        * download app
        *************************************************************/
    else
    {
        mmi_am_ms_app_struct *p;

        index = idx - (g_am_ms_cntx.page_start_idx + g_am_ms_cntx.sc_app_num + g_am_ms_cntx.rom_app_num);
        p = sml_list_get(g_am_ms_cntx.app_list, index);
        if (!p)
        {
            MMI_AM_ASSERT(0);
        }

        p->is_hs_shortcut = MMI_TRUE;
    }

}

/*Vogins_20100625_start*/
/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_set_app_bg_running
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx                 [IN]        
 *  is_bg_running       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_ms_set_app_bg_running(S32 idx, MMI_BOOL is_bg_running)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = idx, k;
    mmi_am_shortcut_info_struct *sc_info;
    mmi_am_vxp_file_struct *vxp_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*************************************************************
        * AM Shortcut app
        *************************************************************/
    S32 num_sc_bg_run = 0, num_rom_bg_run = 0;
    S32 i;

    mmi_am_get_sc_and_rom_bg_num(&num_sc_bg_run, &num_rom_bg_run);
    sc_info = mmi_am_config_get_am_sc_list();   
    if (index < g_am_cntx.shortcut_app_num + num_rom_bg_run + num_app_move && !(index > num_sc_bg_run && index <= num_sc_bg_run + num_rom_bg_run + num_app_move))
    {
        if (index > num_sc_bg_run)
            index -= (num_app_move + num_rom_bg_run);

        if (mmi_am_config_get_am_sc_info_by_appid(APPID_VAS))   /* AppStore support */
        {
            /*-------------------------------------------------------------------
                    - AppStore
                    --------------------------------------------------------------------*/
            if (index == 0)
            {
                g_am_cntx.appstore_list.is_bg_started = is_bg_running;
            }
            /*-------------------------------------------------------------------
                    - other AM Shortcut app
                    --------------------------------------------------------------------*/
            else
            {
                index--;
                g_am_cntx.shortcut_app_list[index].is_bg_started = is_bg_running;
                if (!is_bg_running)
                {
                    if (index < num_sc_bg_run)
                    {
                        mmi_am_shortcut_reorder(index);
                    }
                }
            }
        }
        else    /* dont support AppStore */
        {
            g_am_cntx.shortcut_app_list[index].is_bg_started = is_bg_running;
        }
    }
    else if (index > num_sc_bg_run && index <= num_sc_bg_run + num_rom_bg_run)
    {
        g_am_cntx.rom_app_list[idx - num_sc_bg_run - 1].is_bg_started = is_bg_running;
        if (!is_bg_running)
        {
            mmi_am_rom_app_reorder(index - num_sc_bg_run - 1 );
        }
    }
    else if (index > num_sc_bg_run + num_rom_bg_run && index <= num_sc_bg_run + num_rom_bg_run + num_app_move)
    {
    		if(idx >= g_am_ms_cntx.page_start_idx && idx <= g_am_ms_cntx.page_end_idx)
	    {	

        mmi_am_ms_app_struct *p;
        index = idx - num_sc_bg_run - num_rom_bg_run - 1 + ( g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num) - (g_am_ms_cntx.sc_app_num + g_am_ms_cntx.rom_app_num + g_am_ms_cntx.page_start_idx);
        p = sml_list_get(g_am_ms_cntx.app_list, index);
        if (!p)
        {
            MMI_AM_ASSERT(0);
        }
        p->is_bg_started = is_bg_running;
      }
        if (!is_bg_running)
        {
            mmi_am_ms_bg_update(g_am_ms_cntx.page_start_idx, g_am_ms_cntx.page_end_idx);
        }
    }
    /*************************************************************
        * Rom app
        *************************************************************/
    else if (idx < (g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num + num_app_move))
    {
        g_am_cntx.rom_app_list[idx - g_am_cntx.shortcut_app_num - num_app_move].is_bg_started = is_bg_running;
    }
    /*************************************************************
        * download app
        *************************************************************/
    else
    {
        mmi_am_ms_app_struct *p;

        index = idx - (g_am_ms_cntx.page_start_idx + g_am_ms_cntx.sc_app_num + g_am_ms_cntx.rom_app_num);
        p = sml_list_get(g_am_ms_cntx.app_list, index);
        if (!p)
        {
            MMI_AM_ASSERT(0);
        }

        p->is_bg_started = is_bg_running;
    }

}
/*Vogins_20100625_end*/

/*Vogins_20100625_start*/
/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_set_app_bg_running_by_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx                 [IN]        
 *  is_bg_running       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_ms_set_app_bg_running_by_path(U16 *app_path, MMI_BOOL is_bg_running)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    U16 *get_path;
    S32 num_sc_bg_run = 0;
    S32 i;
    S32 max = g_am_cntx.shortcut_app_num;
    S32 num_rom_bg_run = 0;

    mmi_am_get_sc_and_rom_bg_num(&num_sc_bg_run, &num_rom_bg_run);
    for (i = 1; i <= num_sc_bg_run+num_rom_bg_run +num_app_move; i++)
    {
        get_path = mmi_am_ms_get_app_path_by_index(i);
        if (get_path != NULL)
        {
            if (mmi_wcscmp(get_path, app_path) == 0)
            {
                mmi_am_ms_set_app_bg_running(i, is_bg_running);

            }
        }
    }
/*
    for (index = g_am_ms_cntx.page_start_idx;index < g_am_ms_cntx.hl_idx; index++) 
    {
        get_path = mmi_am_ms_get_app_path_by_index(index);
         if (get_path != NULL) 
            {	           
            if(mmi_wcscmp(get_path, app_path) == 0)
                {
               break;		
                    }
            }
    }
   if(index == g_am_ms_cntx.hl_idx && index != 0)
     g_am_ms_cntx.hl_idx--;
     */
}
/*Vogins_20100625_end*/
/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_app_status_update
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_ms_app_status_update(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 num_sc_bg_run = 0, num_rom_bg_run = 0;
	S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_am_get_sc_and_rom_bg_num(&num_sc_bg_run, &num_rom_bg_run);
	for(i = 1; i <= num_sc_bg_run+num_rom_bg_run; i++)
	{
		 if (mmi_am_app_is_bg_running(mmi_am_ms_get_app_path_by_index(i)))
		    {
		       // mmi_am_ms_set_app_bg_running(idx, MMI_TRUE);
		    }
		    else
		    {
		        mmi_am_ms_set_app_bg_running(i, MMI_FALSE);
		    }
	}

    /* Whether the application is running in the background. */
 /*   if (mmi_am_app_is_bg_running(mmi_am_ms_get_app_path_by_index(idx)))
    {
        mmi_am_ms_set_app_bg_running(idx, MMI_TRUE);
    }
    else
    {
        mmi_am_ms_set_app_bg_running(idx, MMI_FALSE);
    }*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_remove_app_hs_shortcut
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_ms_remove_app_hs_shortcut(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*************************************************************
        * AM Shortcut app
        *************************************************************/
/*Vogins_20100625_start*/
    idx = index = mmi_am_ms_get_actual_index(idx);
/*Vogins_20100625_end*/
    if (index < g_am_cntx.shortcut_app_num)
    {
        if (mmi_am_config_get_am_sc_info_by_appid(APPID_VAS))   /* AppStore support */
        {
            /*-------------------------------------------------------------------
                    - AppStore
                    --------------------------------------------------------------------*/
            if (index == 0)
            {
                g_am_cntx.appstore_list.is_hs_shortcut = MMI_FALSE;
            }
            /*-------------------------------------------------------------------
                    - other AM Shortcut app
                    --------------------------------------------------------------------*/
            else
            {
                index--;
                g_am_cntx.shortcut_app_list[index].is_hs_shortcut = MMI_FALSE;
            }
        }
        else    /* dont support AppStore */
        {
            g_am_cntx.shortcut_app_list[index].is_hs_shortcut = MMI_FALSE;
        }
    }
    /*************************************************************
        * Rom app
        *************************************************************/
    else if (idx < (g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num))
    {
        g_am_cntx.rom_app_list[idx - g_am_cntx.shortcut_app_num].is_hs_shortcut = MMI_FALSE;
    }
    /*************************************************************
        * download app
        *************************************************************/
    else
    {
        mmi_am_ms_app_struct *p;

        index = idx - (g_am_ms_cntx.page_start_idx + g_am_ms_cntx.sc_app_num + g_am_ms_cntx.rom_app_num);
        p = sml_list_get(g_am_ms_cntx.app_list, index);
        if (!p)
        {
            MMI_AM_ASSERT(0);
        }

        p->is_hs_shortcut = MMI_FALSE;
    }

}
/*vogins 20100714 begin*/
static void mmi_am_ms_netconnection_check(void)
{
    MMI_BOOL ret;
    if(g_am_cntx.is_vre_init)
    {
    g_am_cntx.is_prompt_update_cdr = MMI_TRUE;

    ret = mmi_am_process_apn_incorrect_handle(g_am_cntx.apn_check_ret);
    if (ret != MMI_TRUE)
    {
        mmi_am_ms_update_cdr();
    }
}
}
 
/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_update_cdr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_ms_update_cdr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_AM_UPDATE_CDR_STATE state;
    U32 balance;
    static U32 last_balance;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if(!g_am_cntx.is_vre_init)
    {
    	return;
    }
    
    g_am_cntx.is_prompt_update_cdr = MMI_TRUE;

    state = mmi_am_vre_get_sync_cdr_state();
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_UPDATE_CDR_STATE, state);

    switch (state)
    {
    case MMI_AM_NO_SYSC_CDR:
        mmi_am_vre_get_user_balance(&balance);
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_UPDATE_CDR_BALANCE, balance);
        if (balance > 0 && balance != last_balance)
        {
            S8 balance_str[10];
            U16 balance_str_w[10];
            U16 *res_str_ptr;
            U32 balance_yuan, balance_jiao, balance_fen;
            U16 temp_char_w;
            WCHAR *search_ptr;
            U16 string_buf_w[70];

            last_balance = balance;
            memset(balance_str, 0, sizeof(balance_str));
            memset(balance_str_w, 0, sizeof(balance_str_w));
            memset(string_buf_w, 0, sizeof(string_buf_w));
            *((S8*) & temp_char_w) = 37;
            *((S8*) (&temp_char_w) + 1) = 0;

            /* get Yuan.JiaoFen */
            balance_yuan = balance / 100;
            balance_jiao = (balance % 100) / 10;
            balance_fen = balance % 10;

            sprintf(balance_str, "%d.%d%d", balance_yuan, balance_jiao, balance_fen);
            mmi_asc_to_wcs(balance_str_w, (PS8) balance_str);

            res_str_ptr = (PU16) GetString(STR_ID_AM_USER_BALANCE);
            search_ptr = mmi_wcschr(res_str_ptr, (WCHAR) temp_char_w);
            if (search_ptr)
            {
                mmi_wcsncat(string_buf_w, res_str_ptr, search_ptr - res_str_ptr);
                mmi_wcscat(string_buf_w, balance_str_w);
                mmi_wcscat(string_buf_w, search_ptr + 1);
            }

            mmi_display_popup_confirm_with_sg(
                                             GRP_ID_AM,
                                             NULL,
                                             NULL,
#ifdef __VRE_AM_08AB__
                                             STR_GLOBAL_BACK,
                                             IMG_GLOBAL_BACK,
#else
                                             get_string(STR_GLOBAL_BACK),
                                             get_image(IMG_GLOBAL_BACK),
#endif
                                             (UI_string_type) string_buf_w,
                                             MMI_EVENT_INFO,
                                             0);
            SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
        }
        return;

    case MMI_AM_NVRAM_NEED_FOR_SYNC_CDR:
    case MMI_AM_TIME_NEED_FOR_SYNC_CDR:
/*Vogins_20100625_start*/
#ifdef AM_UPDATE_NOTIFY
        mmi_am_entry_update_cdr_scrn();
#else
        mmi_am_cdr_update_accept();
#endif
/*Vogins_20100625_end*/
        return;

    default:
        return;
    }
}

/*Vogins_20100625_start*/
/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_get_actual_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

S32 mmi_am_ms_get_actual_index(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = idx;
    S32 num_sc_bg_run = 0, num_rom_bg_run = 0;
    S32 i, max = g_am_cntx.shortcut_app_num;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*************************************************************
        * AM Shortcut app
        *************************************************************/
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_ms_get_actual_index() -- before index: %d", idx); 

    mmi_am_get_sc_and_rom_bg_num(&num_sc_bg_run, &num_rom_bg_run);
    if (index < g_am_cntx.shortcut_app_num + num_app_move + num_rom_bg_run && !(index > num_sc_bg_run && index <= num_sc_bg_run + num_app_move +num_rom_bg_run))
    {
        if (index > num_sc_bg_run)
        {
            index -= (num_app_move + num_rom_bg_run);
    }
    }
    else if (index > num_sc_bg_run && index <= num_sc_bg_run + num_rom_bg_run)
    {
        index = idx - num_sc_bg_run - 1 + (g_am_cntx.shortcut_app_num);
    }
    else if (index > num_sc_bg_run  + num_rom_bg_run&& index <= num_sc_bg_run + num_app_move+num_rom_bg_run)
    {
        index = idx - num_sc_bg_run - num_rom_bg_run - 1 + ( g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num);
    }
    else if (index < (g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num + num_app_move))
    {
        index = idx - num_app_move;
    }
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_ms_get_actual_index() -- after index: %d", index); 
    return index;

}
/*Vogins_20100625_end*/
/*Vogins_20100710_start*/
/*****************************************************************************
 * FUNCTION
 *  mmi_am_shortcut_reorder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_shortcut_reorder(S32 index)
{
/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 num_sc_bg_run = 0, num_rom_bg_run = 0;
    S32 i, k;
    mmi_am_shortcut_info_struct *sc_info;

    MMI_BOOL tag;
    mmi_am_shortcut_app_struct sc;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*************************************************************
        * AM Shortcut app
        *************************************************************/
    sc_info = mmi_am_config_get_am_sc_list();

    mmi_am_get_sc_and_rom_bg_num(&num_sc_bg_run, &num_rom_bg_run);
    i = 1;
    while (g_am_cntx.shortcut_app_list[index].icon_id != sc_info[i].icon_id && i < g_am_cntx.shortcut_app_num && index < g_am_cntx.shortcut_app_num)
    {
        if (g_am_cntx.shortcut_app_list[index+1].is_bg_started)
        {
            sc = g_am_cntx.shortcut_app_list[index+1];
            g_am_cntx.shortcut_app_list[index+1] = g_am_cntx.shortcut_app_list[index];
            g_am_cntx.shortcut_app_list[index] = sc;
            index++;
        }
        else
        {
            tag = MMI_FALSE;
            for (k = 0; k < num_sc_bg_run; k++)
            {
                if (sc_info[i].icon_id == g_am_cntx.shortcut_app_list[k].icon_id)
                {
                    tag = MMI_TRUE;
                    break;
                }
            }
            if (!tag)
            {
                sc = g_am_cntx.shortcut_app_list[index+1];
                g_am_cntx.shortcut_app_list[index+1] = g_am_cntx.shortcut_app_list[index];
                g_am_cntx.shortcut_app_list[index] = sc;
                index++;
            }
            i++;    
        }

    }
}

void mmi_am_rom_app_reorder(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 i;
    S32 *app_array;
    S32 app_array_len = 0;
    mmi_am_rom_app_struct rom;

    S8 rom_app_path[MMI_AM_MAX_APP_FILE_PATH];
    U16 rom_app_path_w[MMI_AM_MAX_APP_FILE_PATH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_rom_app_reorder() ---------[S]");     
    mmi_am_get_rom_app_array(&app_array, &app_array_len);
    for (i = 0; i < g_am_cntx.rom_app_num; i++)
    {
        sprintf(rom_app_path, "%c:\\%s\\%u.rom", MMI_AM_ROM_DIR, MMI_AM_VRE_HOME_DIR, *(app_array + i));

        mmi_asc_to_wcs((PU16) rom_app_path_w, rom_app_path);

        if (mmi_wcscmp(rom_app_path_w, g_am_cntx.rom_app_list[index].path) == 0)
            break;
        else if (!mmi_am_app_is_bg_running(rom_app_path_w) && i + 1 <g_am_cntx.rom_app_num && index + 1< g_am_cntx.rom_app_num)
        {
            S32 temp;
            rom = g_am_cntx.rom_app_list[index];
            g_am_cntx.rom_app_list[index] = g_am_cntx.rom_app_list[index+1];
            g_am_cntx.rom_app_list[index +1] = rom;
            temp = g_am_cntx.rom_app_list[index].idx;
            g_am_cntx.rom_app_list[index].idx = g_am_cntx.rom_app_list[index+1].idx;
            g_am_cntx.rom_app_list[index+1].idx = temp;
            index++;
        }
    }
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_rom_app_reorder() ---------[E]");    
}

void mmi_am_get_sc_and_rom_bg_num(S32* num_sc_bg_run, S32* num_rom_bg_run)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_am_shortcut_info_struct *sc_info;
    S32 max = g_am_cntx.shortcut_app_num;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *num_sc_bg_run = 0;
    *num_rom_bg_run = 0;
    sc_info = mmi_am_config_get_am_sc_list();

    if (mmi_am_config_get_am_sc_info_by_appid(APPID_VAS))
        max = g_am_cntx.shortcut_app_num -1;
    for (i = 0; i < max; i++)
    {
        if (g_am_cntx.shortcut_app_list[i].is_bg_started)
        {
            (*num_sc_bg_run)++;
        }
        else
            break;
    }
    for (i = 0; i < g_am_cntx.rom_app_num; i++)
    {
        if (g_am_cntx.rom_app_list[i].is_bg_started)
        {
            (*num_rom_bg_run)++;
        }
        else
            break;
    }

}
/*Vogins_20100710_end*/
#endif /* __VRE30_AM__ */ 

