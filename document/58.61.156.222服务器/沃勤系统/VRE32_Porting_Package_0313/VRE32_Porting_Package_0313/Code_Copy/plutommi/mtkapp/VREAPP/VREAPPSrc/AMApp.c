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
 *   AMApp.c
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   AM App Src
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
    #include "CommonScreens.h"      /* for mmi_display_popup */
    #include "App_mem.h"
    #include "USBDeviceGprot.h"
    #include "MainMenuDef.h"
    #ifdef __VRE_AM_08AB__
        #include "wgui_categories_popup.h"
        #include "wgui_categories_multimedia.h"
    #endif
    #include "AMResDef.h"   /* Add AM head file */
    #include "AMDef.h"      /* Add AM head file */
    #include "AMGprot.h"    /* Add AM head file */
    #include "AMprot.h"     /* Add AM head file */
    #include "AMShortcut.h"
    #include "AMMainScreen.h"
    #include "AMUtil.h"
    #include "AMScreens.h"
    #ifndef __VRE_AM_08AB__
        //#undef MMI_TRACE
        //#define MMI_TRACE(...)	
    #endif
//wei.xia add by 0624 for vre information 
    #include "vmopt.h"
    #include "amdef.h"
    #include "vmua.h"
//add end

/*****************************************************************************/
/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/

/* global variables */
mmi_am_cntx_struct g_am_cntx;
mmi_am_quick_start_struct g_am_qs_cntx;
mmi_am_async_search_struct g_am_search_cntx;
extern mmi_am_ms_struct g_am_ms_cntx;
extern const U8 AM_App_Default[];
extern char AM_App_VRE20[];
/*michael 100415 begin*/
extern sml_list_t *g_run_app_list;
MMI_BOOL g_is_denint = MMI_TRUE;
/*michael 100415 end*/
/*Vogins_20100625_start*/
extern U16 num_app_move;
am_prompt_struct is_prompt_rule_cdr;
/*Vogins_20100625_end*/
/*Vogins_20100707_start*/
mmi_am_relaunch_struct g_am_relaunch_cntx;
MMI_BOOL IsQuickStart = MMI_FALSE;
extern mmi_am_apn_info g_mmi_am_apn_info;
/*vogins_20100707_end*/
MMI_BOOL IsDownload = MMI_FALSE; /* Dan 0730 */
/***************************************************************************** 
* Local Function
*****************************************************************************/
static MMI_BOOL mmi_am_start_int(void);
static mmi_ret mmi_am_grp_proc(mmi_event_struct *evt);
static mmi_ret mmi_am_grp_inactive(void);
static mmi_ret mmi_am_grp_active(void);
static mmi_ret mmi_am_grp_first_entry(void);
static MMI_BOOL mmi_am_pre_start_check(void);
static void mmi_am_vre_cb(MMI_AM_START_VRE_EVT evt);

    #ifdef AM_09A
static U8 mmi_am_destroy_loading_scrn(void *param);
    #else 
static mmi_ret mmi_am_leave_loading_scrn(mmi_event_struct *evt);
    #endif 
static void mmi_am_ls_app_launch(void);
static void mmi_am_redraw_content_cb(void);
static void mmi_am_eixt_loading_scrn(void);
static void mmi_am_close_loading_scrn(void);
static void mmi_am_close_group_by_too_many_files(void);
static void mmi_am_cntx_init(void);
    #ifndef MMI_AM_USING_VRE_MEM
static void mmi_am_asm_stop_cb(void);
static void mmi_am_alloc_mem_cb(void);
    #endif
static void mmi_am_app_init(void);
static void mmi_am_hold_vre_folder(void);

/* search vxp files */
static void mmi_am_search(void);
static void mmi_am_search_shortcut_apps(void);
static void mmi_am_search_appstore(void);
static void mmi_am_search_appstore_in_rom(void);

    #ifdef MMI_AM_APP_CHECK_NEW_VERSION
static void mmi_am_add_appstore_list(U16 *full_path, S32 len);
    #endif 
static MMI_BOOL mmi_am_search_rom_apps(void);
static MMI_BOOL mmi_am_search_vxp_files(void);
static void mmi_am_search_vxp_cb(void);
static MMI_BOOL mmi_am_add_vxp_file_list(U16 *app_name, FS_DOSDateTime date_time);
/*Vogins_20100625_start*/
//static U32 mmi_am_binary_search(FS_DOSDateTime *modify_time);
/*Vogins_20100625_end*/
static S32 mmi_am_search_same_time_pos(FS_DOSDateTime *modify_time, S32 pos);
static S32 mmi_am_compare_time(FS_DOSDateTime *time1, FS_DOSDateTime *time2);
static MMI_BOOL mmi_am_search_app_by_appid(mmi_am_shortcut_id_enum appid, U16 *path, U32 size);
static MMI_BOOL mmi_am_check_downloaded_app_by_as(void);

/* release operation */
static void mmi_am_release_shortcut_list_all_nodes(void);
static void mmi_am_release_shortcut_list(void);
static void mmi_am_release_rom_list(void);
static void mmi_am_release_vxp_list_all_nodes(void);
static void mmi_am_release_vxp_list(void);

/* app launch */
static void mmi_am_app_launch_cb(void);
static MMI_BOOL mmi_am_app_launch_int(U16 *app_path);

static void mmi_am_delete_node_from_vxplist_by_path(U16 *app_path);
static MMI_BOOL mmi_am_is_too_many_files_in_vre_folder(void);

/* download application from main menu */
static void mmi_am_download_from_mm_entry_ask_scrn(void);
static void mmi_am_download_from_mm_exit_ask_scrn(void);
    #ifdef AM_09A
static U8 mmi_am_del_download_from_mm_ask_scrn(void *param);
    #else
static mmi_ret mmi_am_leave_download_from_mm_ask_scrn(mmi_event_struct *evt);
    #endif
static void mmi_am_download_app_from_mm_close(void);
static void mmi_am_download_app_from_mm(void);
/*michael 100415 begin*/
static void mmi_am_app_relaunch(void);
extern void mmi_am_prompt_to_release_mem(void (*success_callback)(void), MMI_BOOL is_out_of_memory_flag);
void mmi_am_free_app_running_infos(void);
void mmi_am_ms_release_run_app_list(void);
static void mmi_am_ms_release_run_app_list_all_nodes(void);
static void mmi_am_ms_release_run_applist_node(mmi_am_ms_app_struct *p_node);
mmi_am_ms_app_struct *mmi_am_ms_get_runing_appinfo_from_vxplist(mmi_am_vxp_file_struct *vxp_p);

static void mmi_am_release_app_running_infos(vm_running_app_info_t *app_info);
MMI_BOOL mmi_am_get_running_appinfo(vm_running_app_info_t *app_info, U16 app_num);
/*Vogins_20100625_start*/
static void mmi_am_exit_prompt_Consume_Info_scrn(void);
static void mmi_am_entry_prompt_Consume_Info_scrn(void);
/*Vogins_20100625_end*/
/*michael 100415 end*/
/*Vogins_20100707_start*/
static void mmi_am_close_loading_srn_e(void);
static void mmi_am_close_acitve_loading_srn(void);
/*Vogins_20100707_end*/
static void mmi_am_check_apn_status_cb(S8 result);//0714
/***************************************************************************** 
* Extern Function
*****************************************************************************/
    #ifndef AM_09A
extern MMI_ID mmi_frm_group_enter_ex(
                                    MMI_ID parent_id,
                                    MMI_ID group_id,
                                    mmi_proc_func proc,
                                    void *user_data,
                                    mmi_group_enter_flag flag);
    #endif /* AM_09A */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_am_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
             MMI_FW_TRC_G1_FRM,
             TRC_MMI_AM_START_S,
             g_am_qs_cntx.is_quick_start,
             g_am_cntx.dyn_mem_pool,
             g_am_cntx.adm_pool_id,
             g_am_cntx.is_vre_init);

    IsDownload = MMI_FALSE;

    if (IsScreenPresent(GRP_ID_AM))
    {
        mmi_frm_group_close(GRP_ID_AM);
    }

    /* Check before AM start */
    if (!mmi_am_pre_start_check())
    {
        return;
    }

    /* enter screen group */
    mmi_frm_group_enter_ex(GRP_ID_ROOT, GRP_ID_AM, mmi_am_grp_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    /* enter loading screen */
    mmi_am_entry_loading_scrn();

    MMI_TRACE(
             MMI_FW_TRC_G1_FRM,
             TRC_MMI_AM_START_E,
             g_am_qs_cntx.is_quick_start,
             g_am_cntx.dyn_mem_pool,
             g_am_cntx.adm_pool_id,
             g_am_cntx.is_vre_init);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_start_int
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_am_start_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_START_INT_S);

    /* AM context init */
    mmi_am_cntx_init();

    /* VRE Core init */
    if (!g_am_cntx.is_vre_init)
    {
        MMI_AM_LOAD_VRE_CORE load_vre_core_ret = mmi_am_vre_load_core(mmi_am_vre_cb);

        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_VRE_LOAD_RESULT, load_vre_core_ret);
        if (load_vre_core_ret == MMI_AM_VLC_START_SUCCESS)
        {
            g_am_cntx.is_vre_init = MMI_TRUE;   /* VRE Core has already done */
        }
        else if (load_vre_core_ret == MMI_AM_VLC_ASYN_ALLOC_ASM)
        {
            /* VRE Core failed to initialize */
            g_am_cntx.is_alloc_asm_fail = MMI_TRUE;
            return MMI_FALSE;
        }
        else
        {
            /* VRE failed to initialize */
            mmi_display_popup((UI_string_type) GetString(STR_ID_AM_VRE_INIT_FAILURE), MMI_EVENT_FAILURE);
            return MMI_FALSE;
        }
    }

    /* is quick start */
    //michael 100415 begin
    if ((!g_am_qs_cntx.is_quick_start || g_am_qs_cntx.is_download) && (g_am_cntx.is_vre_init))
    {
#ifndef MMI_AM_USING_VRE_MEM
        /* application registeration & stop callback */
        applib_mem_ap_register(
                              APPLIB_MEM_AP_ID_AM,
#ifdef __VRE_AM_08AB__
                        STR_ID_AM_NAME,
#else
                        MAIN_MENU_VRE_TEXT,
#endif
                              /* STR_ID_AM_NAME, */ IMG_ID_AM_TITLE,
                              mmi_am_asm_stop_cb);
        MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_start_int() -- dyn_mem_pool:%d", g_am_cntx.dyn_mem_pool);

        /* allocate memory */
        if (g_am_cntx.dyn_mem_pool == NULL)
        {
#ifdef WIN32
            g_am_cntx.dyn_mem_pool = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_AM, MMI_AM_MAX_DYN_MEM_SIZE);
#else
						#ifdef __VRE_AM_08AB__ 
						g_am_cntx.dyn_mem_pool = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_AM, MMI_AM_MAX_DYN_MEM_SIZE);
						#else
            g_am_cntx.dyn_mem_pool = applib_mem_ap_alloc_framebuffer(APPLIB_MEM_AP_ID_AM, MMI_AM_MAX_DYN_MEM_SIZE);
            #endif
#endif 
            if (g_am_cntx.dyn_mem_pool == NULL)
            {
                MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_ALLOCATE_MEM_FAIL);

                /* register callback */
                mmi_frm_appmem_prompt_to_release_mem(
                                                    APPLIB_MEM_AP_ID_AM,
                                                    0,
                                                    MMI_AM_MAX_DYN_MEM_SIZE,
                                                    mmi_am_alloc_mem_cb);

                /* Unload VRE Core */
                g_am_cntx.is_vre_init = MMI_FALSE;
                mmi_am_vre_unload_core();

                return MMI_FALSE;
            }
	    mmi_frm_appmem_set_hide_list_screen(APPLIB_MEM_AP_ID_AM); //michael 100725
        }
#else /* MMI_AM_USING_VRE_MEM */ 
        /* allocate memory */
        if (g_am_cntx.dyn_mem_pool == NULL)
        {
            g_am_cntx.dyn_mem_pool = mmi_am_vre_malloc(MMI_AM_MAX_DYN_MEM_SIZE);
            MMI_AM_ASSERT(g_am_cntx.dyn_mem_pool != NULL)
        }
#endif /* MMI_AM_USING_VRE_MEM */ 
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_DYN_MEM_POOL, g_am_cntx.dyn_mem_pool);
        memset(g_am_cntx.dyn_mem_pool, 0, MMI_AM_MAX_DYN_MEM_SIZE);
    }

    mmi_am_app_init();

    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_START_INT_E);

    return MMI_TRUE;
}
/*Vogins_20100625_start*/
/*****************************************************************************
 * FUNCTION
 *  mmi_am_exit_prompt_Consume_Info_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_exit_prompt_Consume_Info_scrn(void)
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
 *  mmi_am_restart
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void mmi_am_restart()
{
    S16 error;
    is_prompt_rule_cdr.am_entry_flag = KAL_TRUE;

    WriteRecord(
               NVRAM_EF_AM_PROMPT_LID,
               (U16) (1),
               &is_prompt_rule_cdr,
               sizeof(am_prompt_struct),
               &error);
     if (IsDownload)
     {
         mmi_am_start_from_mm(g_am_qs_cntx.app_id);
     }
     else
     {
    mmi_vre_start();
     }
    DeleteScreenIfPresent(SCR_ID_AM_PROMPT);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_am_prompt_Consume_Info_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_entry_prompt_Consume_Info_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ret = mmi_frm_scrn_enter(GRP_ID_AM, SCR_ID_AM_PROMPT, mmi_am_exit_prompt_Consume_Info_scrn, mmi_am_entry_prompt_Consume_Info_scrn, NULL);
    EntryNewScreen(SCR_ID_AM_PROMPT, mmi_am_exit_prompt_Consume_Info_scrn, mmi_am_entry_prompt_Consume_Info_scrn, NULL);
    gui_buffer =GetCurrGuiBuffer(GetActiveScreenId());// mmi_frm_scrn_get_active_gui_buf();

    ShowCategory74Screen(
#ifdef __VRE_AM_08AB__
                        STR_ID_AM_NAME,
#else
                        MAIN_MENU_VRE_TEXT,
#endif
#ifdef __MMI_FTE_SUPPORT__
                        0,
#else 
                        IMG_ID_AM_TITLE,
#endif 
                        STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
                        (U8*) GetString(STR_ID_AM_PROMPT_INFOMATION), 
                        mmi_ucs2strlen((S8*) GetString(STR_ID_AM_PROMPT_INFOMATION)), gui_buffer);

    SetLeftSoftkeyFunction(mmi_am_restart, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

}
/*Vogins_20100625_end*/
/*****************************************************************************
 * FUNCTION
 *  mmi_am_pre_start_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_am_pre_start_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_PRE_START_CHECK_S);

    if (g_am_cntx.is_alloc_asm_fail)
    {
        g_am_qs_cntx.is_quick_start = MMI_FALSE;
        g_am_qs_cntx.is_download = MMI_FALSE;
    }
/*vogins 100726 begin*/
    if (g_am_qs_cntx.is_not_enough_memory)
    {
        g_am_qs_cntx.is_quick_start = MMI_FALSE;
        g_am_qs_cntx.is_not_enough_memory = MMI_FALSE;
    }
/*vogins 100726 end*/

    /* whether it can get system drvier */
    if (mmi_am_get_system_driver() == 0)
    {
        mmi_display_popup((UI_string_type) GetString(STR_ID_AM_START_FAILURE), MMI_EVENT_FAILURE);
        return MMI_FALSE;
    }

    /* whether the files more than 5000 in vre folder */
    if (!g_am_qs_cntx.is_quick_start)
    {
        if (mmi_am_is_too_many_files_in_vre_folder())
        {
            mmi_display_popup((UI_string_type) GetString(STR_ID_AM_FILE_OVERFLOW), MMI_EVENT_FAILURE);
            MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_PRE_START_CHECK_E1);
            return MMI_FALSE;
        }
    }

#ifdef __USB_IN_NORMAL_MODE__
    /* is in storage mode */
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* phone drive is exported, can't use this app */
        mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_PRE_START_CHECK_E2);
        return MMI_FALSE;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    /* check vre folder and create vre folder in Remove Drv and System Drv. */
    //if (!mmi_am_check_vre_folder())
    //{
    //mmi_display_popup((UI_string_type) GetString(STR_ID_AM_FILE_OVERFLOW), MMI_EVENT_FAILURE);
    //   MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_pre_start_check() -- create vre folder failure");
    //}

/*Vogins_20100625_start*/
#ifndef AM_GPRS_NOT_NOTICE	
    ReadRecord(
              NVRAM_EF_AM_PROMPT_LID,
              (U16) (1),
              &is_prompt_rule_cdr,
              sizeof(am_prompt_struct),
              &error);

    if (!is_prompt_rule_cdr.am_entry_flag)
    {
        mmi_am_entry_prompt_Consume_Info_scrn();
        return MMI_FALSE;
    }
#endif	
/*Vogins_20100625_end*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_PRE_START_CHECK_E3);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_vre_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_vre_cb(MMI_AM_START_VRE_EVT evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
             MMI_FW_TRC_G1_FRM,
             TRC_MMI_AM_VRE_CB_S,
             evt,
             g_am_qs_cntx.is_quick_start,
             g_am_cntx.is_app_update,
             g_am_cntx.dyn_mem_pool);

    switch (evt)
    {
    case MMI_AM_VRE_START_SUCCESS:
        if (g_am_cntx.is_app_update)
        {
            mmi_am_app_update(mmi_am_dl_get_appid(), mmi_am_dl_get_app_name());
        }
        else if (g_am_qs_cntx.is_quick_start)
        {
            if (g_am_qs_cntx.quick_start_flag == FILE_MGR)
            {
                mmi_am_start_from_fm(g_am_qs_cntx.path);
            }
            else if (g_am_qs_cntx.quick_start_flag == HS_SHORTCUT)
            {
                mmi_am_start_from_hs(g_am_qs_cntx.path);
            }
            else if (g_am_qs_cntx.quick_start_flag == MAIN_MENU)
            {
                mmi_am_start_from_mm(g_am_qs_cntx.app_id);
            }
        }
        else
        {
            mmi_am_start();
        }

        break;

    case MMI_AM_VRE_START_INTERNEL_ERROR:
        break;

    case MMI_AM_VRE_QUIT:
        if (g_am_cntx.dyn_mem_pool)
        {
            mmi_frm_group_close(GRP_ID_AM);
        }
        break;

    default:
        break;
    }

    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_VRE_CB_E);
}

    #ifndef MMI_AM_USING_VRE_MEM
/*****************************************************************************
 * FUNCTION
 *  mmi_am_alloc_mem_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_alloc_mem_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
             MMI_FW_TRC_G1_FRM,
             TRC_MMI_AM_ALLOC_MEM_CB_S,
             g_am_qs_cntx.is_quick_start,
             g_am_cntx.is_app_update,
             g_am_cntx.dyn_mem_pool);

#ifdef WIN32
    g_am_cntx.dyn_mem_pool = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_AM, MMI_AM_MAX_DYN_MEM_SIZE);
#else 
    #ifdef __VRE_AM_08AB__ 
    g_am_cntx.dyn_mem_pool = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_AM, MMI_AM_MAX_DYN_MEM_SIZE);
    #else
    g_am_cntx.dyn_mem_pool = applib_mem_ap_alloc_framebuffer(APPLIB_MEM_AP_ID_AM, MMI_AM_MAX_DYN_MEM_SIZE);
    #endif
#endif 
    MMI_AM_ASSERT(g_am_cntx.dyn_mem_pool != NULL);  /* It should provide enough memory */
    memset(g_am_cntx.dyn_mem_pool, 0, MMI_AM_MAX_DYN_MEM_SIZE);

    /* Restart AM */
    if (g_am_cntx.is_app_update)
    {
        mmi_am_app_update(mmi_am_dl_get_appid(), mmi_am_dl_get_app_name());
    }
    else if (g_am_qs_cntx.is_quick_start)
    {
        mmi_am_download_app_from_mm();
    }
    else
    {
        mmi_am_start();
    }

    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_ALLOC_MEM_CB_E, g_am_cntx.dyn_mem_pool);
}
    #endif


/*****************************************************************************
 * FUNCTION
 *  mmi_am_start_from_fm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_start_from_fm(U16 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_START_FROM_FM_S);

    if (path != NULL)
    {
        IsQuickStart = MMI_TRUE;  //voigns 0711
        g_am_qs_cntx.is_quick_start = MMI_TRUE;
        g_am_qs_cntx.quick_start_flag = FILE_MGR;

        if (g_am_qs_cntx.path != path)
        {
            memset(g_am_qs_cntx.path, 0, sizeof(g_am_qs_cntx.path));
            mmi_wcscpy(g_am_qs_cntx.path, path);
        }

        g_am_cntx.is_alloc_asm_fail = MMI_FALSE;
/*vogins 100726 begin*/
        g_am_qs_cntx.is_not_enough_memory = MMI_FALSE;
/*vogins 100726 end*/

        mmi_am_start();
    }

    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_START_FROM_FM_E);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_start_from_hs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_start_from_hs(U16 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_START_FROM_HS_S);

    if (path != NULL)
    {
        IsQuickStart = MMI_TRUE;  //voigns 0711
        g_am_qs_cntx.is_quick_start = MMI_TRUE;
        g_am_qs_cntx.quick_start_flag = HS_SHORTCUT;

        if (g_am_qs_cntx.path != path)
        {
            memset(g_am_qs_cntx.path, 0, sizeof(g_am_qs_cntx.path));
            mmi_wcscpy(g_am_qs_cntx.path, path);
        }

        g_am_cntx.is_alloc_asm_fail = MMI_FALSE;
/*vogins 100726 begin*/
        g_am_qs_cntx.is_not_enough_memory = MMI_FALSE;
/*vogins 100726 end*/

        mmi_am_start();
    }

    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_START_FROM_HS_E);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_start_from_mm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  appid       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_start_from_mm(mmi_am_shortcut_id_enum appid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_START_FROM_MM_S, appid);

    g_am_qs_cntx.app_id = appid;
    g_am_qs_cntx.quick_start_flag = MAIN_MENU;
    g_am_cntx.is_alloc_asm_fail = MMI_FALSE;
    g_am_qs_cntx.is_not_enough_memory = MMI_FALSE;
    IsDownload = MMI_FALSE;

    /* Whether the application has been downloaded */
    if (mmi_am_search_app_by_appid(appid, g_am_qs_cntx.path, MMI_AM_MAX_APP_QUICK_START_PATH * 2))
    {
        IsQuickStart = MMI_TRUE;  //voigns 0711
        g_am_qs_cntx.is_quick_start = MMI_TRUE;
        mmi_am_start();
    }
    else
    {
        /* check if it can download app */
        if (!mmi_am_is_network_service_available())
        {
            mmi_display_popup(
                             (UI_string_type) get_string(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE),
                             MMI_EVENT_FAILURE);
            return;
        }

        IsDownload = MMI_TRUE;
        /* Check before AM start */
        if (!mmi_am_pre_start_check())
        {
            MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_START_FROM_MM_E1);
            return;
        }

        /* enter screen group */
        mmi_frm_group_enter_ex(GRP_ID_ROOT, GRP_ID_AM, mmi_am_grp_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

        if (g_am_qs_cntx.is_download)
        {
            mmi_am_download_app_from_mm();
        }
        else
        {
            mmi_am_download_from_mm_entry_ask_scrn();
        }
    }

    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_START_FROM_MM_E3, g_am_qs_cntx.is_quick_start, g_am_qs_cntx.is_download);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_download_from_mm_entry_ask_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_download_from_mm_entry_ask_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_DL_FROM_MM_ENTRY_ASK_SCRN_S);

    ret = mmi_frm_scrn_enter(
                            GRP_ID_AM,
                            SCR_ID_AM_DOWNLOAD_FROM_MM_ASK,
                            mmi_am_download_from_mm_exit_ask_scrn,
                            NULL,
                            NULL);

    if (ret == MMI_FALSE)
    {
        return;
    }

    ShowCategory165Screen(
                         STR_GLOBAL_YES, 
                         IMG_GLOBAL_YES, 
                         STR_GLOBAL_NO, 
                         IMG_GLOBAL_NO, 
                         (UI_string_type) GetString(STR_GLOBAL_DOWNLOAD_ASK), 
                         (U16) IMG_GLOBAL_QUESTION, 
                         NULL);
#ifdef AM_09A
    SetDelScrnIDCallbackHandler(SCR_ID_AM_DOWNLOAD_FROM_MM_ASK, (HistoryDelCBPtr) mmi_am_del_download_from_mm_ask_scrn);
#else /* AM_09A */ 
    /* set leave proc */
    mmi_frm_scrn_set_leave_proc(GRP_ID_AM, SCR_ID_AM_DOWNLOAD_FROM_MM_ASK, mmi_am_leave_download_from_mm_ask_scrn);
#endif /* AM_09A */ 

    SetLeftSoftkeyFunction(mmi_am_download_app_from_mm, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_am_download_app_from_mm_close, KEY_EVENT_UP);

    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_DL_FROM_MM_ENTRY_ASK_SCRN_E);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_download_from_mm_exit_ask_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_download_from_mm_exit_ask_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


    #ifdef AM_09A


/*****************************************************************************
 * FUNCTION
 *  mmi_am_del_download_from_mm_ask_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static U8 mmi_am_del_download_from_mm_ask_scrn(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_DEL_DL_FROM_MM_ASK_SCRN_S, g_am_qs_cntx.is_download); 

    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_DEL_DL_FROM_MM_ASK_SCRN_E, g_am_qs_cntx.is_download);
    return MMI_FALSE;
}
    #else /* AM_09A */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_am_leave_download_from_mm_ask_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_am_leave_download_from_mm_ask_scrn(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_LEAVE_DL_FROM_MM_ASK_SCRN_S, g_am_qs_cntx.is_download);

    switch (evt->evt_id)
    {
    case EVT_ID_SCRN_DELETE_REQ:
        break;

    case EVT_ID_SCRN_DEINIT:
        break;
    }

    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_LEAVE_DL_FROM_MM_ASK_SCRN_E, g_am_qs_cntx.is_download);
    return ret;
}
    #endif /* AM_09A */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_am_grp_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_am_grp_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_GROUP_PROC_EVT_S, evt->evt_id, g_am_qs_cntx.is_quick_start, g_am_qs_cntx.is_download);

#ifndef AM_09A
    if (evt->evt_id == EVT_ID_GROUP_ACTIVE && g_am_cntx.start_state == START_NONE)
    {
        if (mmi_frm_scrn_get_count(GRP_ID_AM) == 0 && mmi_frm_is_in_backward_scenario())
        {
            mmi_frm_group_close(GRP_ID_AM);
        }
        return MMI_RET_OK;
    }
#endif

    if (g_am_qs_cntx.is_download)
    {
        return MMI_RET_OK;
    }

    if (g_am_qs_cntx.is_quick_start)
    {
        if (evt->evt_id == EVT_ID_GROUP_DEINIT && !g_am_cntx.is_alloc_asm_fail)
        {
/*vogins 100726 begin*/
            if (!g_am_qs_cntx.is_not_enough_memory)
            {
                g_am_qs_cntx.is_quick_start = MMI_FALSE;
            }
/*vogins 100726 end*/

            /* Unload VRE Core */
            mmi_am_vre_unload_core();

            /* set VRE Core flag */
            g_am_cntx.is_vre_init = MMI_FALSE;
        }

        return MMI_RET_OK;
    }

    switch (evt->evt_id)
    {
    case EVT_ID_GROUP_FIRST_ENTRY:
        ret = mmi_am_grp_first_entry();
        break;

    case EVT_ID_GROUP_ACTIVE:
        ret = mmi_am_grp_active();
        break;

    case EVT_ID_GROUP_INACTIVE:
        ret = mmi_am_grp_inactive();
        break;

    case EVT_ID_GROUP_DEINIT:
        ret = mmi_am_grp_deinit();
        break;
    }

    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_GROUP_PROC_EVT_E);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_cntx_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_cntx_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* init context struct */
    g_am_cntx.has_small_font = MMI_FALSE;
    g_am_cntx.sim_settings = NO_SIM;
    g_am_cntx.conn_settings = NO_ANY_CONN;
    g_am_cntx.is_goback = MMI_FALSE;
    g_am_cntx.start_state = START_NONE;
    g_am_cntx.adm_pool_id = NULL;

    g_am_cntx.is_launch_vas = MMI_FALSE;
    g_am_cntx.is_card_plug_in = MMI_FALSE;
    g_am_cntx.is_card_plug_out = MMI_FALSE;
    g_am_cntx.is_app_update = MMI_FALSE;
    g_am_cntx.is_app_in_card = MMI_FALSE;
    g_am_cntx.is_alloc_asm_fail = MMI_FALSE;
    g_am_cntx.is_prompt_update_cdr = MMI_FALSE;

    /* g_am_cntx.dyn_mem_pool = NULL; */
    memset(&g_am_cntx.appstore_list, 0, sizeof(g_am_cntx.appstore_list));
    g_am_cntx.shortcut_app_list = NULL;
    g_am_cntx.rom_app_list = NULL;
    g_am_cntx.vxp_file_list = NULL;

    /* initialize am_search context */
    g_am_search_cntx.search_hdl = -1;
    g_am_search_cntx.search_state = SEARCH_NONE;
    g_am_search_cntx.cur_driver = mmi_am_get_home_driver();

    /* initialize vre folder file handle */
    g_am_cntx.card_vre_folder_hdl = -1;
    g_am_cntx.phone_vre_folder_hdl = -1;

    g_am_cntx.app_launch_path = NULL;
    /*Vogins_20100707_start*/
    g_am_relaunch_cntx.am_relaunch_tag = MMI_FALSE;
    //g_am_relaunch_cntx.path = NULL;
    /*Vogins_20100707_end*/
}


    #ifndef MMI_AM_USING_VRE_MEM
/*****************************************************************************
 * FUNCTION
 *  mmi_am_asm_stop_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_asm_stop_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_ASM_STOP_CB_S);

    mmi_frm_group_close(GRP_ID_AM);
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_AM, KAL_TRUE);

    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_ASM_STOP_CB_E);
}
    #endif


/*****************************************************************************
 * FUNCTION
 *  mmi_am_app_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_app_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 *app_array;
    S32 app_array_len = 0;
    kal_uint32 applib_mem_pool_chunk_size[13] = {16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 5120, 0xffffffff, 0};   /* for KAL ADM */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
             MMI_FW_TRC_G1_FRM,
             TRC_MMI_AM_APP_INIT_S,
             g_am_cntx.dyn_mem_pool,
             g_am_qs_cntx.is_quick_start,
             g_am_cntx.is_app_update);

    /* Create ADM */
    if (g_am_cntx.dyn_mem_pool != NULL)
    {
        g_am_cntx.adm_pool_id = kal_adm_create(
                                              (void*)g_am_cntx.dyn_mem_pool,
                                              MMI_AM_MAX_DYN_MEM_SIZE,
                                              applib_mem_pool_chunk_size,
                                              KAL_TRUE);
        MMI_AM_ASSERT(g_am_cntx.adm_pool_id != NULL);
    }

    if (g_am_qs_cntx.is_quick_start || g_am_cntx.is_app_update)
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_APP_INIT_E1);
        return;
    }

    /* allocate AM Shortcut App list memory */
    g_am_cntx.shortcut_app_num = mmi_am_config_get_am_sc_num();
    if (g_am_cntx.shortcut_app_num != 0
        && !(mmi_am_config_get_am_sc_info_by_appid(APPID_VAS) && g_am_cntx.shortcut_app_num == 1))
    {
        S32 sc_num;

        if (mmi_am_config_get_am_sc_info_by_appid(APPID_VAS))
        {
            sc_num = g_am_cntx.shortcut_app_num - 1;
        }
        else
        {
            sc_num = g_am_cntx.shortcut_app_num;
        }
        g_am_cntx.shortcut_app_list =
        (mmi_am_shortcut_app_struct*) mmi_am_calloc(sc_num * sizeof(mmi_am_shortcut_app_struct));
        if (!g_am_cntx.shortcut_app_list)
        {
            MMI_AM_ASSERT(g_am_cntx.shortcut_app_list != NULL);
            return;
        }
    }

    /* allocate Rom App list memory */
    mmi_am_get_rom_app_array(&app_array, &app_array_len);
    g_am_cntx.rom_app_num = app_array_len;
    if (g_am_cntx.rom_app_num)
    {
        g_am_cntx.rom_app_list =
        (mmi_am_rom_app_struct*) mmi_am_calloc(g_am_cntx.rom_app_num * sizeof(mmi_am_rom_app_struct));
        if (!g_am_cntx.rom_app_list)
        {
            MMI_AM_ASSERT(g_am_cntx.rom_app_list != NULL);
            return;
        }
    }

    /* new list */
    g_am_cntx.vxp_file_list = sml_list_new();

    /* check whether the system have small fonts */
    if (mmi_am_get_font_height() == MMI_AM_APP_NAME_H)
    {
        g_am_cntx.has_small_font = MMI_TRUE;
    }
    else
    {
        g_am_cntx.has_small_font = MMI_FALSE;
    }

    /* read SIM Card & Conn. settings */
    mmi_am_get_sim_card(&g_am_cntx.sim_settings);
    mmi_am_get_net_type(&g_am_cntx.conn_settings);

    /* delete download_list.dat which created by AS */
    {
        S32 file_drv;
        S8 dl_app_list_path[30];
        U16 dl_app_list_path_w[30];

        memset(dl_app_list_path, 0, sizeof(dl_app_list_path));
        memset(dl_app_list_path_w, 0, sizeof(dl_app_list_path_w));

        /* memory card */
        file_drv = mmi_am_get_removeable_driver();
        sprintf(dl_app_list_path, "%c:\\%s\\%s", file_drv, MMI_AM_VRE_HOME_DIR, MMI_AM_DOWNLOAD_LIST);
        mmi_asc_to_wcs(dl_app_list_path_w, (PS8) dl_app_list_path);
        FS_Delete(dl_app_list_path_w);

        memset(dl_app_list_path, 0, sizeof(dl_app_list_path));
        memset(dl_app_list_path_w, 0, sizeof(dl_app_list_path_w));

        /* system driver */
        file_drv = mmi_am_get_system_driver();
        sprintf(dl_app_list_path, "%c:\\%s\\%s", file_drv, MMI_AM_VRE_HOME_DIR, MMI_AM_DOWNLOAD_LIST);
        mmi_asc_to_wcs(dl_app_list_path_w, (PS8) dl_app_list_path);
        FS_Delete(dl_app_list_path_w);
    }

    /* hold vre folder handle */
    mmi_am_hold_vre_folder();

    MMI_TRACE(
             MMI_FW_TRC_G1_FRM,
             TRC_MMI_AM_APP_INIT_E2,
             g_am_cntx.adm_pool_id,
             g_am_qs_cntx.is_quick_start,
             g_am_cntx.is_app_update,
             g_am_cntx.shortcut_app_num,
             g_am_cntx.rom_app_num,
             g_am_cntx.has_small_font,
             g_am_cntx.sim_settings,
             g_am_cntx.conn_settings);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_search
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_search(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_SEARCH_S);

    /* search shortcut apps */
    mmi_am_search_shortcut_apps();

    /* search rom apps */
    if (!mmi_am_search_rom_apps())
    {
        mmi_frm_group_close(GRP_ID_AM);
        return;
    }

    /* search vxp file and buile vxp list */
    if (!mmi_am_search_vxp_files())
    {
        mmi_frm_group_close(GRP_ID_AM);
        return;
    }

    /* Notify VRE Core */
    mmi_am_vre_set_am_state(MMI_AM_IN_USE);

    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_SEARCH_E);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_grp_deinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_am_grp_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_status ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
             MMI_FW_TRC_G1_FRM,
             TRC_MMI_AM_DEINIT_S,
             g_am_search_cntx.search_hdl,
             g_am_cntx.card_vre_folder_hdl,
             g_am_cntx.phone_vre_folder_hdl,
             g_am_cntx.adm_pool_id,
             g_am_cntx.dyn_mem_pool,
             g_am_cntx.is_vre_init);

    /* cancel vxp files search timer */
    gui_cancel_timer(mmi_am_search_vxp_cb);

    /* cancel app launch timer */
    gui_cancel_timer(mmi_am_app_launch_cb);

    /* cancel download */
    mmi_am_vre_cancel_download();
/*Vogins_20100726_start*/
    mmi_am_release_download();
    gui_cancel_timer(mmi_am_continue_download_app);
/*Vogins_20100726_end*/
    /* cancel cdr update */
    mmi_am_vre_sync_cdr_cancel();

    /* close vxp search file handle */
    if (g_am_search_cntx.search_hdl >= 0)
    {
        FS_FindClose(g_am_search_cntx.search_hdl);
        g_am_search_cntx.search_hdl = -1;
    }

    /* close vre folder file handle */
    if (g_am_cntx.card_vre_folder_hdl >= 0)
    {
        FS_Close(g_am_cntx.card_vre_folder_hdl);
        g_am_cntx.card_vre_folder_hdl = -1;
    }

    if (g_am_cntx.phone_vre_folder_hdl >= 0)
    {
        FS_Close(g_am_cntx.phone_vre_folder_hdl);
        g_am_cntx.phone_vre_folder_hdl = -1;
    }

    /* release lists */
    mmi_am_release_shortcut_list();
    mmi_am_release_rom_list();
    mmi_am_release_vxp_list();
    mmi_am_ms_release_app_list();
    /*michael 100415 begin*/
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "[AMVRE11]function denint point NULL");
    mmi_am_ms_release_run_app_list();
    mmi_frm_appmem_clear_hide_list_screen(APPLIB_MEM_AP_ID_AM); //michael 100725
    /*Michael 100415 end*/
    /* Delete ADM */
    if (g_am_cntx.adm_pool_id)
    {
        ret = kal_adm_delete(g_am_cntx.adm_pool_id);

        MMI_AM_ASSERT(ret == KAL_SUCCESS);
        g_am_cntx.adm_pool_id = NULL;
    }

    /* release dynamic memory */
    if (g_am_cntx.dyn_mem_pool != NULL)
    {
#ifndef MMI_AM_USING_VRE_MEM
        applib_mem_ap_free(g_am_cntx.dyn_mem_pool);
#else 
        mmi_am_vre_free(g_am_cntx.dyn_mem_pool);
#endif 
        g_am_cntx.dyn_mem_pool = NULL;
    }

    /* Notify VRE Core */
    mmi_am_vre_set_am_state(MMI_AM_OUT_OF_USE);

    /* Unload VRE Core */
    mmi_am_vre_unload_core();

    /* deinit AM context */
    mmi_am_cntx_init();

	if(g_am_qs_cntx.is_download)
	{
		mmi_am_download_app_from_mm_deinit();
	}
	
    /* set VRE Core flag */
    g_am_cntx.is_vre_init = MMI_FALSE;
    g_am_relaunch_cntx.am_relaunch_tag = MMI_FALSE;
    MMI_TRACE(
             MMI_FW_TRC_G1_FRM,
             TRC_MMI_AM_DEINIT_E,
             g_am_search_cntx.search_hdl,
             g_am_cntx.card_vre_folder_hdl,
             g_am_cntx.phone_vre_folder_hdl,
             g_am_cntx.adm_pool_id,
             g_am_cntx.dyn_mem_pool,
             g_am_cntx.is_vre_init);
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_grp_inactive
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_am_grp_inactive(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_grp_active
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_am_grp_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_grp_first_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_am_grp_first_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_am_config_init();

    /* AM context init */
    /* mmi_am_cntx_init(); */

    //mmi_am_app_init();

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_release_shortcut_list_all_nodes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_release_shortcut_list_all_nodes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, max;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_am_config_get_am_sc_info_by_appid(APPID_VAS))
    {
        if (g_am_cntx.appstore_list.p_name != NULL)
        {
            mmi_am_free(g_am_cntx.appstore_list.p_name);
            g_am_cntx.appstore_list.p_name = NULL;
        }

        max = g_am_cntx.shortcut_app_num - 1;
    }
    else
    {
        max = g_am_cntx.shortcut_app_num;
    }

    /* release every member */
    for (i = 0; i < max; i++)
    {
        if (g_am_cntx.shortcut_app_list[i].p_name != NULL)
        {
            /* 1. release app name */
            mmi_am_free(g_am_cntx.shortcut_app_list[i].p_name);
            g_am_cntx.shortcut_app_list[i].p_name = NULL;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_release_shortcut_list_nodes_in_memory_card
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_release_shortcut_list_nodes_in_memory_card(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, max;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_am_config_get_am_sc_info_by_appid(APPID_VAS))
    {
        if (((S8) (*g_am_cntx.appstore_list.path[0]) != (S8) mmi_am_get_system_driver()) &&
            ((S8) (*g_am_cntx.appstore_list.path[0]) != (S8) MMI_AM_ROM_DIR))
        {
            //if (g_am_cntx.appstore_list.p_name != NULL)
            //{
            //    mmi_am_free(g_am_cntx.appstore_list.p_name);
            //    g_am_cntx.appstore_list.p_name = NULL;
            //}
            MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_RELEASE_APPSTORE);

            g_am_cntx.appstore_list.is_downloaded = MMI_FALSE;
            g_am_cntx.appstore_list.is_hs_shortcut = MMI_FALSE;
            g_am_cntx.appstore_list.is_bg_started = MMI_FALSE;
        }

        max = g_am_cntx.shortcut_app_num - 1;
    }
    else
    {
        max = g_am_cntx.shortcut_app_num;
    }

    /* release app name buffer */
    for (i = 0; i < max; i++)
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_RELEASE_SHORTCUT_PATH, i, (S8) (*g_am_cntx.shortcut_app_list[i].path));
        if (((S8) (*g_am_cntx.shortcut_app_list[i].path) != (S8) mmi_am_get_system_driver()) &&
            ((S8) (*g_am_cntx.shortcut_app_list[i].path) != (S8) MMI_AM_ROM_DIR))
        {
            //if (g_am_cntx.shortcut_app_list[i].p_name != NULL)
            //{
            //  /* 1. release app name */
            //    mmi_am_free(g_am_cntx.shortcut_app_list[i].p_name);
            //    g_am_cntx.shortcut_app_list[i].p_name = NULL;
            //}
            MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_RELEASE_SHORTCUT, i);
            /*vogins_20100707_start*/
		if(g_am_cntx.shortcut_app_list[i].is_bg_started && mmi_am_app_is_bg_running(g_am_cntx.shortcut_app_list[i].path))
            {
                mmi_am_shortcut_reorder(i);
            }
            /*vogins_20100707_end*/
            g_am_cntx.shortcut_app_list[i].is_downloaded = MMI_FALSE;
            g_am_cntx.shortcut_app_list[i].is_hs_shortcut = MMI_FALSE;
            g_am_cntx.shortcut_app_list[i].is_bg_started = MMI_FALSE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_release_shortcut_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_release_shortcut_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* release appstore name */
    if (g_am_cntx.appstore_list.p_name)
    {
        mmi_am_free(g_am_cntx.appstore_list.p_name);
        g_am_cntx.appstore_list.p_name = NULL;
    }

    /* release list */
    if (g_am_cntx.shortcut_app_list)
    {
        mmi_am_release_shortcut_list_all_nodes();

        mmi_am_free(g_am_cntx.shortcut_app_list);
        g_am_cntx.shortcut_app_list = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_release_rom_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_release_rom_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* release list */
    if (g_am_cntx.rom_app_list)
    {
        /* release every member */
        for (i = 0; i < g_am_cntx.rom_app_num; i++)
        {
            /* release icon */
            if (g_am_cntx.rom_app_list[i].p_icon != NULL)
            {
                mmi_am_free(g_am_cntx.rom_app_list[i].p_icon);
                g_am_cntx.rom_app_list[i].p_icon = NULL;
            }

            /* release ZiMo */
            if (g_am_cntx.rom_app_list[i].p_name &&
                mmi_wcscmp((PU16) g_am_cntx.rom_app_list[i].p_name, (PU16) GetString(STR_ID_AM_APP_NAME_VRE20)) &&
                mmi_wcscmp((PU16) g_am_cntx.rom_app_list[i].p_name, (PU16) GetString(STR_ID_AM_APP_NAME_DEFAULT)))
            {
                mmi_am_free(g_am_cntx.rom_app_list[i].p_name);
                g_am_cntx.rom_app_list[i].p_name = NULL;
            }
        }

        mmi_am_free(g_am_cntx.rom_app_list);
        g_am_cntx.rom_app_list = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_release_vxp_list_all_nodes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_release_vxp_list_all_nodes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_am_cntx.vxp_file_list)
    {
        while (sml_list_size(g_am_cntx.vxp_file_list))
        {
            mmi_am_vxp_file_struct *p = sml_list_get(g_am_cntx.vxp_file_list, 0);

            mmi_am_free(p);
            p = NULL;
            sml_list_remove(g_am_cntx.vxp_file_list, 0);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_release_vxp_list_nodes_in_memory_card
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_release_vxp_list_nodes_in_memory_card(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 num_of_vxp_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_am_cntx.vxp_file_list)
    {
        num_of_vxp_list = sml_list_size(g_am_cntx.vxp_file_list);

        for (i = num_of_vxp_list - 1; i >= 0; i--)
        {
            mmi_am_vxp_file_struct *p = sml_list_get(g_am_cntx.vxp_file_list, i);

            if (((S8) (*(p->path)) != (S8) mmi_am_get_system_driver()) && ((S8) (*(p->path)) != (S8) MMI_AM_ROM_DIR))
            {
                MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_RELEASE_VXP_NODE);
                mmi_am_free(p);
                p = NULL;
                sml_list_remove(g_am_cntx.vxp_file_list, i);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_release_vxp_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_release_vxp_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_am_cntx.vxp_file_list)
    {
        mmi_am_release_vxp_list_all_nodes();

        sml_list_free(g_am_cntx.vxp_file_list);
        g_am_cntx.vxp_file_list = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_search_app_by_appid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  appid       [IN]        
 *  path        [OUT]       
 *  size        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_am_search_app_by_appid(mmi_am_shortcut_id_enum appid, U16 *path, U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 file_drv;
    S8 *file_name = NULL;
    S8 temp_path[MMI_AM_MAX_SHORTCUT_APP_FILE_PATH];
    U16 temp_path_w[MMI_AM_MAX_SHORTCUT_APP_FILE_PATH];
    FS_HANDLE fd = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_search_app_by_appid() ------- [S]");

    memset(temp_path, 0, sizeof(temp_path));
    memset(temp_path_w, 0, sizeof(temp_path_w));
    memset(path, 0, size);

    /* get app file name by appid */
    if (g_am_qs_cntx.quick_start_flag == MAIN_MENU)
    {
        file_name = mmi_am_config_get_mm_sc_name_by_appid(appid);
    }
    else
    {
        file_name = mmi_am_config_get_am_sc_name_by_appid(appid);
    }
    /* search app in system driver */
    file_drv = mmi_am_get_system_driver();
    sprintf(temp_path, "%c:\\%s\\%s", file_drv, MMI_AM_VRE_HOME_DIR, file_name);
    mmi_asc_to_wcs(temp_path_w, (PS8) temp_path);
    if ((fd = FS_Open(temp_path_w, FS_OPEN_NO_DIR | FS_READ_ONLY)) >= FS_NO_ERROR)
    {
        MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_search_app_by_appid() -- in system driver");
        /* app exist */
        mmi_wcscpy(path, temp_path_w);
        FS_Close(fd);
        return MMI_TRUE;
    }

    memset(temp_path, 0, sizeof(temp_path));
    memset(temp_path_w, 0, sizeof(temp_path_w));

    /* search app in remove driver */
    file_drv = mmi_am_get_removeable_driver();
    if (file_drv)
    {
        sprintf(temp_path, "%c:\\%s\\%s", file_drv, MMI_AM_VRE_HOME_DIR, file_name);
        mmi_asc_to_wcs((PU16) temp_path_w, (PS8) temp_path);
        if ((fd = FS_Open(temp_path_w, FS_OPEN_NO_DIR | FS_READ_ONLY)) >= FS_NO_ERROR)
        {
            MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_search_app_by_appid() -- in memory card");
            /* app exist */
            mmi_wcscpy(path, temp_path_w);
            FS_Close(fd);
            return MMI_TRUE;
        }
    }
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_search_app_by_appid() ------- [E]");

    return MMI_FALSE;
}
/*Shelley 20100730 start*/
/*****************************************************************************
 * FUNCTION
 *  mmi_am_close_loading_srn_e
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_close_acitve_loading_srn(void)
{
    if (GetActiveScreenId() == SCR_ID_AM_LOADING)
        mmi_am_close_loading_scrn();
}

/*Shelley 20100730 start*/
/*****************************************************************************
 * FUNCTION
 *  mmi_am_close_loading_srn_e
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_close_loading_srn_e(void)
{
    if (GetActiveScreenId() == SCR_ID_AM_LOADING)
        mmi_am_close_loading_scrn();
    else
        mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_LOADING);
}
/*vogins_20100707_end*/

static void mmi_am_check_apn_status_cb(S8 result)
{

MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_check_apn_status_cb() ------- [S]");
    if (g_am_cntx.is_vre_init)
    {
        g_am_cntx.apn_check_ret = result;
        /* start AM from main menu */
        mmi_am_search();
    }
MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_check_apn_status_cb() ------- [E]");

}
/*****************************************************************************
 * FUNCTION
 *  mmi_am_entry_loading_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_entry_loading_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
             MMI_FW_TRC_G1_FRM,
             TRC_MMI_AM_ENTRY_LOADING_SCRN_S,
             g_am_qs_cntx.is_quick_start,
             g_am_qs_cntx.is_download,
             g_am_cntx.adm_pool_id,
             g_am_cntx.start_state,
             g_am_cntx.is_card_plug_in,
             g_am_cntx.is_card_plug_out,
             g_am_cntx.is_launch_vas);

    /* mmi_frm_scrn_enter */
    if (!g_am_qs_cntx.is_quick_start)
    {
        ret = mmi_frm_scrn_enter(
                                GRP_ID_AM,
                                SCR_ID_AM_LOADING,
                                mmi_am_eixt_loading_scrn,
                                mmi_am_entry_loading_scrn,
                                NULL);
    }
    else
    {
        ret = mmi_frm_scrn_enter(GRP_ID_AM, SCR_ID_AM_LOADING, mmi_am_eixt_loading_scrn, NULL, NULL);
    }

    if (ret == MMI_FALSE)
    {
        return;
    }

    /* show category */
    ShowCategory221Screen(0, 0, 0, 0, 0, 0, GDI_COLOR_BLACK, mmi_am_redraw_content_cb);

#ifdef AM_09A
#ifdef __VRE_AM_08AB__
    SetDelScrnIDCallbackHandler(SCR_ID_AM_LOADING, (HistoryDelCBPtr) mmi_am_destroy_loading_scrn);
#else
    mmi_frm_set_destroy_scrn_callback(SCR_ID_AM_LOADING, (HistoryDelCBPtr) mmi_am_destroy_loading_scrn);
#endif
    if (!g_am_qs_cntx.is_quick_start && g_am_cntx.adm_pool_id == NULL)
    {
        mmi_am_grp_first_entry();
    }
#else /* AM_09A */ 
    /* set leave proc */
    mmi_frm_scrn_set_leave_proc(GRP_ID_AM, SCR_ID_AM_LOADING, mmi_am_leave_loading_scrn);
#endif /* AM_09A */ 

    /* AM init */
    if (g_am_cntx.adm_pool_id == NULL)
    {
        if (!mmi_am_start_int())
        {
            mmi_frm_group_close(GRP_ID_AM);
            MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_ENTRY_LOADING_SCRN_E1);
            return;
        }
    }

    if (g_am_qs_cntx.is_quick_start)
    {
        mmi_am_vre_set_am_state(MMI_AM_OUT_OF_USE);
        g_am_cntx.start_state = STARTING;

        /* quick start, call start function directly. */
        mmi_am_app_launch(g_am_qs_cntx.path);

        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_ENTRY_LOADING_SCRN_E5);
        return;
    }

    switch (g_am_cntx.start_state)
    {
    case START_NONE:
        break;

    case START_BEGIN:
        g_am_cntx.start_state = STARTING;
#ifdef AM_09A
        if (g_am_cntx.is_card_plug_in)
        {
            mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_LOADING);
        }
#else
//Shelley 20100730
        if (g_am_cntx.is_card_plug_in)
	{
                gui_start_timer(500, /*mmi_am_close_loading_scrn*/mmi_am_close_acitve_loading_srn);      /* For 09B FW issue */
		//mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_LOADING);
	}
#endif /* AM_09A */ 

	if(g_am_cntx.is_app_in_card)
	{
		MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_launch_app_async_cb() ------- [S]");
		g_am_cntx.is_app_in_card = MMI_FALSE;
		g_am_cntx.start_state = START_FAILURE;
             mmi_display_popup_with_sg(
                         GRP_ID_AM,
                         (UI_string_type) get_string(STR_ID_AM_FILE_NOT_EXIST),
                         MMI_EVENT_FAILURE,
                         0);
		  MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_launch_app_async_cb() ------- [E]");
		  return;
	}
	
        mmi_am_ls_app_launch();

        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_ENTRY_LOADING_SCRN_E2);
        return;

    case STARTING:
        return;

    case START_SUCCESS:
        g_am_cntx.start_state = START_NONE;

        /* update app status */
		/*
        if (!g_am_cntx.is_app_in_card)
        {
            mmi_am_ms_app_status_update(g_am_ms_cntx.hl_idx);
        }
        g_am_cntx.is_app_in_card = MMI_FALSE;
*/
        /* check if there are downloaded apps from AS */
        if (g_am_cntx.is_launch_vas)
        {
            g_am_cntx.is_launch_vas = MMI_FALSE;
            if (mmi_am_check_downloaded_app_by_as())
            {
                /* Search shortcut apps */
                mmi_am_search_shortcut_apps();

                /* release all nodes in app_list */
                mmi_am_ms_release_app_list_all_nodes();
            }

            /* downloading AS -> plug in memory card -> launch AS -> download some app from AS -> return to AM */
            //if (g_am_cntx.is_card_plug_in)
            //{
            //    mmi_am_release_vxp_list_nodes_in_memory_card();
            //}
        }

        if (g_am_cntx.is_card_plug_in)
        {
            if (mmi_am_is_too_many_files_in_vre_folder())
            {
                gui_start_timer(1, mmi_am_close_group_by_too_many_files);

                MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_ENTRY_LOADING_SCRN_E3);
                return;
            }
            mmi_am_search();
        }
        else
        {
            /* Enter Main Screen */
            if (mmi_frm_scrn_is_present(GRP_ID_AM, SCR_ID_AM_MAIN, MMI_FRM_NODE_ALL_FLAG))
            {
                /*vogins_20100707_start*/
                gui_start_timer(1, /*mmi_am_close_loading_scrn*/mmi_am_close_loading_srn_e);      /* For 09B FW issue */
                /*vogins_20100707_end*/
            }
            else
            {
                mmi_am_entry_main_scrn();
            }
        }

        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_ENTRY_LOADING_SCRN_E4);
        return;

    case START_FAILURE:
        g_am_cntx.start_state = START_NONE;

        if (g_am_cntx.is_card_plug_in)
        {
            if (mmi_am_is_too_many_files_in_vre_folder())
            {
                gui_start_timer(1, mmi_am_close_group_by_too_many_files);

                MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_ENTRY_LOADING_SCRN_E3);
                return;
            }
            mmi_am_search();
        }
        else
        {
            /* Enter Main Screen */
            if (mmi_frm_scrn_is_present(GRP_ID_AM, SCR_ID_AM_MAIN, MMI_FRM_NODE_ALL_FLAG))
            {
                gui_start_timer(1, mmi_am_close_loading_scrn);      /* For 09B FW issue */
            }
            else
            {
                mmi_am_entry_main_scrn();
            }
        }
        return;

    default:
        break;
    }

    if (g_am_cntx.is_card_plug_out)
    {
        /* close loading screen */
        //mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_LOADING);
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_ENTRY_LOADING_SCRN_E6);
        return;
    }

    //if (g_am_cntx.is_card_plug_in && !g_am_cntx.is_card_plug_out)
    {
        if (mmi_am_is_too_many_files_in_vre_folder())
        {
            gui_start_timer(1, mmi_am_close_group_by_too_many_files);
            MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_ENTRY_LOADING_SCRN_E7);
            return;
        }

        #if 1
        mmi_am_vre_set_am_state(MMI_AM_IN_USE);
	g_am_cntx.apn_check_ret = MMI_AM_APN_INIT;
        mmi_am_check_apn_status(&g_mmi_am_apn_info,mmi_am_check_apn_status_cb);
        #else
        /* start AM from main menu */
        mmi_am_search();
        #endif
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_ENTRY_LOADING_SCRN_E8);
        return;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_redraw_content_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_redraw_content_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 img_width, img_height, str_width;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str_width = 0;

    /* draw background */
    gdi_draw_solid_rect(0, 0, UI_device_width, UI_device_height, GDI_COLOR_BLACK);

    /* get image width and height */
    gdi_image_get_dimension_id(IMG_ID_AM_LOADING, &img_width, &img_height);

    /* draw vre icon in the center of screen */
    gdi_image_draw_id((UI_device_width - img_width) >> 1, (UI_device_height - img_height) >> 1, IMG_ID_AM_LOADING);

#if MMI_AM_LOADING_TEXT
    if (!g_am_qs_cntx.is_quick_start)
    {
        if (!g_am_cntx.is_goback)
        {
            /* display 'Loading' on screen */
            gui_set_font(&MMI_medium_font);
            gui_set_text_color(gui_color(0XFF, 0XFF, 0XFF));    /* white */
            str_width = gui_get_string_width((UI_string_type) GetString(STR_ID_AM_LOADING));
            gui_move_text_cursor((UI_device_width - str_width) >> 1, ((UI_device_height + img_height) >> 1) + 40);
            gui_print_text((UI_string_type) GetString(STR_ID_AM_LOADING));
        }
    }
#endif /* MMI_AM_LOADING_TEXT */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_eixt_loading_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_eixt_loading_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* free resource */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_close_loading_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_close_loading_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_close_group_by_too_many_files
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_close_group_by_too_many_files(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_display_popup((UI_string_type) GetString(STR_ID_AM_FILE_OVERFLOW), MMI_EVENT_FAILURE);
    mmi_frm_group_close(GRP_ID_AM);
}

    #ifdef AM_09A


/*****************************************************************************
 * FUNCTION
 *  mmi_am_destroy_loading_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static U8 mmi_am_destroy_loading_scrn(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_LS_DESTROY_S);

    if (!IsScreenPresent(SCR_ID_AM_MAIN) && g_am_cntx.start_state != STARTING && g_am_ms_cntx.app_list == NULL)
    {
        mmi_am_grp_deinit();
    }

    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_LS_DESTROY_E);
    return MMI_FALSE;
}
    #else /* AM_09A */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_am_leave_loading_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_am_leave_loading_scrn(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
    case EVT_ID_SCRN_DELETE_REQ:
        break;

    case EVT_ID_SCRN_DEINIT:
        break;
    }

    return ret;
}
    #endif /* AM_09A */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_am_ls_app_launch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_ls_app_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef MMI_AM_APP_CHECK_NEW_VERSION
    S32 i;
#endif 
    S32 index;
    U16 *app_path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_LS_APP_LAUNCH_S, g_am_ms_cntx.hl_idx);

    index = g_am_ms_cntx.hl_idx;

    /* launch AppStore */
    if ((index == 0) && (mmi_am_config_get_am_sc_info_by_appid(APPID_VAS)) && !(g_am_relaunch_cntx.am_relaunch_tag))
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_LS_APP_LAUNCH_AS);
#ifdef MMI_AM_APP_CHECK_NEW_VERSION
        for (i = 0; i < 3; i++)
        {
            app_path = g_am_cntx.appstore_list.path[i];

            if (app_path && app_path[0] && mmi_am_app_launch(app_path))
            {
                g_am_cntx.is_launch_vas = MMI_TRUE;
                return;
            }
        }
#else /* MMI_AM_APP_CHECK_NEW_VERSION */ 
        app_path = g_am_cntx.appstore_list.path[0];
        if (app_path && app_path[0] && mmi_am_app_launch(app_path))
        {
            g_am_cntx.is_launch_vas = MMI_TRUE;
            MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_LS_APP_LAUNCH_E1);
            return;
        }
#endif /* MMI_AM_APP_CHECK_NEW_VERSION */ 

        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_LS_APP_LAUNCH_E2);
        return;
    }

    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_LS_APP_LAUNCH_OTHER_APP);
    app_path = mmi_am_ms_get_app_path_by_index(index);
/*vogins_20100716_start*/
    if (app_path || g_am_relaunch_cntx.am_relaunch_tag)
/*vogins_20100716_end*/
    {
        mmi_am_app_launch(app_path);
    }
    else
    {
        mmi_display_popup_with_sg( GRP_ID_AM,
                                  (UI_string_type) get_string(STR_ID_AM_FILE_NOT_EXIST),
                                  MMI_EVENT_FAILURE,
                                  0);

        g_am_cntx.start_state = START_FAILURE;
    }
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_LS_APP_LAUNCH_E3, g_am_ms_cntx.hl_idx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_hold_vre_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_hold_vre_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 vre_path[20];
    U16 vre_path_w[20];
    FS_HANDLE fd = -1;
    S8 file_drv;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
             MMI_FW_TRC_G1_FRM,
             TRC_MMI_AM_HOLD_VRE_FOLDER_S,
             g_am_cntx.card_vre_folder_hdl,
             g_am_cntx.phone_vre_folder_hdl);

    /* Firstly, search vre folder in remove driver */
    file_drv = mmi_am_get_removeable_driver();
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_hold_vre_folder() -- remove_driver:%d", file_drv);
    if (file_drv != 0 && g_am_cntx.card_vre_folder_hdl < 0)
    {
        memset(vre_path, 0, sizeof(vre_path));
        memset(vre_path_w, 0, sizeof(vre_path_w));
        sprintf(vre_path, "%c:\\%s", file_drv, MMI_AM_VRE_HOME_DIR);
        mmi_asc_to_wcs(vre_path_w, vre_path);

        /* search vre folder, if it exists, hold it. */
        if ((fd = FS_Open(vre_path_w, FS_OPEN_NO_DIR | FS_READ_ONLY)) >= FS_NO_ERROR)   /* vre is not folder */
        {
            FS_Close(fd);
        }
        else if ((fd = FS_Open(vre_path_w, FS_OPEN_DIR | FS_READ_ONLY)) >= FS_NO_ERROR)
        {
            g_am_cntx.card_vre_folder_hdl = fd;
        }

        fd = -1;
    }

    /* Secondly, search vre folder in system driver */
    file_drv = mmi_am_get_system_driver();
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_hold_vre_folder() -- system_driver:%d", file_drv);
    if (file_drv != 0 && g_am_cntx.phone_vre_folder_hdl < 0)
    {
        memset(vre_path, 0, sizeof(vre_path));
        memset(vre_path_w, 0, sizeof(vre_path_w));
        sprintf(vre_path, "%c:\\%s", file_drv, MMI_AM_VRE_HOME_DIR);
        mmi_asc_to_wcs(vre_path_w, vre_path);

        /* search vre folder, if it exists, hold it. */
        if ((fd = FS_Open(vre_path_w, FS_OPEN_NO_DIR | FS_READ_ONLY)) >= FS_NO_ERROR)   /* vre is not folder */
        {
            FS_Close(fd);
        }
        else if ((fd = FS_Open(vre_path_w, FS_OPEN_DIR | FS_READ_ONLY)) >= FS_NO_ERROR)
        {
            g_am_cntx.phone_vre_folder_hdl = fd;
        }
    }

    MMI_TRACE(
             MMI_FW_TRC_G1_FRM,
             TRC_MMI_AM_HOLD_VRE_FOLDER_E,
             g_am_cntx.card_vre_folder_hdl,
             g_am_cntx.phone_vre_folder_hdl);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_check_vre_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_am_check_vre_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE memory_card_hdl = -1, system_hdl = -1;    /* create vre folder return value */
    S8 vre_path[20];
    U16 vre_path_w[20];
    FS_HANDLE fd = -1;
    S8 file_drv;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_check_vre_folder() ------- [S]");

    /* Firstly, create a vre folder in remove driver */
    file_drv = mmi_am_get_removeable_driver();
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_check_vre_folder() -- remove_driver:%d", file_drv);
    if (g_am_cntx.card_vre_folder_hdl > 0)  /* vre folder has already been holded */
    {
        memory_card_hdl = FS_NO_ERROR;
    }
    else if (file_drv != 0)
    {
        memset(vre_path, 0, sizeof(vre_path));
        memset(vre_path_w, 0, sizeof(vre_path_w));
        sprintf(vre_path, "%c:\\%s", file_drv, MMI_AM_VRE_HOME_DIR);
        mmi_asc_to_wcs(vre_path_w, vre_path);

        if ((fd = FS_Open(vre_path_w, FS_OPEN_NO_DIR | FS_READ_ONLY)) >= 0)     /* vre is not folder */
        {
            MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_check_vre_folder() -- vre is not folder");

            FS_Close(fd);
            FS_Delete(vre_path_w);
        }

        memory_card_hdl = FS_CreateDir(vre_path_w);
        MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_check_vre_folder() -- memory_card_hdl:%d", memory_card_hdl);
        if (memory_card_hdl == FS_NO_ERROR || memory_card_hdl == FS_FILE_EXISTS)
        {
            g_am_cntx.card_vre_folder_hdl = FS_Open(vre_path_w, FS_OPEN_DIR | FS_READ_ONLY);
            memory_card_hdl = FS_NO_ERROR;
        }

        fd = -1;
    }

    /* Secondly, create a vre folder in system driver */
    file_drv = mmi_am_get_system_driver();
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_check_vre_folder() -- system_driver:%d", file_drv);
    if (g_am_cntx.phone_vre_folder_hdl > 0) /* vre folder has already been holded */
    {
        system_hdl = FS_NO_ERROR;
    }
    else if (file_drv != 0)
    {
        memset(vre_path, 0, sizeof(vre_path));
        memset(vre_path_w, 0, sizeof(vre_path_w));
        sprintf(vre_path, "%c:\\%s", file_drv, MMI_AM_VRE_HOME_DIR);
        mmi_asc_to_wcs(vre_path_w, vre_path);

        if ((fd = FS_Open(vre_path_w, FS_OPEN_NO_DIR | FS_READ_ONLY)) >= 0)     /* vre is not folder */
        {
            MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_check_vre_folder() -- vre is not folder");

            FS_Close(fd);
            FS_Delete(vre_path_w);
        }

        system_hdl = FS_CreateDir(vre_path_w);
        MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_check_vre_folder() -- system_hdl:%d", system_hdl);
        if (system_hdl == FS_NO_ERROR || system_hdl == FS_FILE_EXISTS)
        {
            g_am_cntx.phone_vre_folder_hdl = FS_Open(vre_path_w, FS_OPEN_DIR | FS_READ_ONLY);
            system_hdl = FS_NO_ERROR;
        }
    }

    MMI_AM_LOG(
              MOD_MMI,
              TRACE_GROUP_7,
              "mmi_am_check_vre_folder() --memory_card_hdl:%d system_hdl:%d",
              memory_card_hdl,
              system_hdl);
    if (memory_card_hdl < FS_NO_ERROR && system_hdl < FS_NO_ERROR)
    {
        MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_check_vre_folder() ------- [E1]");
        return MMI_FALSE;
    }

    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_check_vre_folder() ------- [E2]");
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_search_shortcut_apps
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_search_shortcut_apps(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j, max;

    /* S32 str_len; */

    mmi_am_shortcut_info_struct *sc_list = mmi_am_config_get_am_sc_list();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_SEARCH_SHORTCUT_APPS_S);

    if (mmi_am_config_get_am_sc_info_by_appid(APPID_VAS))
    {
        /* search AppStore */
        mmi_am_search_appstore();
    }

    max = g_am_cntx.shortcut_app_num;

    /* other shortcut apps exluding AppStore */
    for (i = 0, j = 0; i < max; i++)
    {
        if (sc_list[i].app_id == APPID_VAS) /* exlude AppStore */
        {
            continue;
        }
        g_am_cntx.shortcut_app_list[j].icon_id = sc_list[i].icon_id;
        g_am_cntx.shortcut_app_list[j].name_id = sc_list[i].name_id;
        g_am_cntx.shortcut_app_list[j].name_size = sc_list[i].name_size;

        if ((!g_am_cntx.has_small_font) && (sc_list[i].p_name))
        {
            // get ZiMo data
            //g_am_cntx.shortcut_app_list[j].p_name = sc_list[i].p_name;
            mmi_am_get_zimo_string_data(
                                       sc_list[i].p_name,
                                       &g_am_cntx.shortcut_app_list[j].p_name,
                                       (PS32) & g_am_cntx.shortcut_app_list[j].name_len);
        }

        /* Whether the application has been downloaded */
        if (mmi_am_search_app_by_appid(
                                      sc_list[i].app_id,
                                      g_am_cntx.shortcut_app_list[j].path,
                                      MMI_AM_MAX_SHORTCUT_APP_FILE_PATH * 2))
        {
            g_am_cntx.shortcut_app_list[j].is_downloaded = MMI_TRUE;

            /* Whether the application is set to HS shortcut. */
#ifdef __MMI_VUI_HOMESCREEN__
            if (mmi_am_is_set_as_shortcut(g_am_cntx.shortcut_app_list[j].path))
            {
                g_am_cntx.shortcut_app_list[j].is_hs_shortcut = MMI_TRUE;
            }
            else
#endif /* __MMI_VUI_HOMESCREEN__ */ 
            {
                g_am_cntx.shortcut_app_list[j].is_hs_shortcut = MMI_FALSE;
            }

            /* Whether the application is running in the background. */
            if (mmi_am_app_is_bg_running(g_am_cntx.shortcut_app_list[j].path))
            {
                g_am_cntx.shortcut_app_list[j].is_bg_started = MMI_TRUE;
            }
            else
            {
                g_am_cntx.shortcut_app_list[j].is_bg_started = MMI_FALSE;
            }

        }
        else
        {
            g_am_cntx.shortcut_app_list[j].is_downloaded = MMI_FALSE;
            g_am_cntx.shortcut_app_list[j].is_hs_shortcut = MMI_FALSE;
            g_am_cntx.shortcut_app_list[j].is_bg_started = MMI_FALSE;
        }
/*Vogins_20100625_start*/
        if (g_am_cntx.shortcut_app_list[j].is_bg_started)
        {
            S32 k;
            mmi_am_shortcut_app_struct sc;
            k = j - 1;
            while (g_am_cntx.shortcut_app_list[k].is_bg_started == 0 && k >= 0)
            {
                sc = g_am_cntx.shortcut_app_list[k];
                g_am_cntx.shortcut_app_list[k] = g_am_cntx.shortcut_app_list[k+1];
                g_am_cntx.shortcut_app_list[k+1] = sc;
                k--;
            }
        }
/*Vogins_20100625_end*/

        MMI_AM_LOG(
                  MOD_MMI,
                  TRACE_GROUP_7,
                  "shortcut_app_list[%d] -- is_downloaded:%d",
                  j,
                  g_am_cntx.shortcut_app_list[j].is_downloaded);
        MMI_AM_LOG(
                  MOD_MMI,
                  TRACE_GROUP_7,
                  "shortcut_app_list[%d] -- is_hs_shortcut:%d",
                  j,
                  g_am_cntx.shortcut_app_list[j].is_hs_shortcut);
        MMI_AM_LOG(
                  MOD_MMI,
                  TRACE_GROUP_7,
                  "shortcut_app_list[%d] -- is_bg_started:%d",
                  j,
                  g_am_cntx.shortcut_app_list[j].is_bg_started);
        MMI_AM_LOG(
                  MOD_MMI,
                  TRACE_GROUP_7,
                  "shortcut_app_list[%d] -- icon_id:%d",
                  j,
                  g_am_cntx.shortcut_app_list[j].icon_id);
        MMI_AM_LOG(
                  MOD_MMI,
                  TRACE_GROUP_7,
                  "shortcut_app_list[%d] -- name_id:%d",
                  j,
                  g_am_cntx.shortcut_app_list[j].name_id);
        MMI_AM_LOG(
                  MOD_MMI,
                  TRACE_GROUP_7,
                  "shortcut_app_list[%d] -- p_name:0x%08x",
                  j,
                  g_am_cntx.shortcut_app_list[j].p_name);
        MMI_AM_LOG(
                  MOD_MMI,
                  TRACE_GROUP_7,
                  "shortcut_app_list[%d] -- name_size:%d",
                  j,
                  g_am_cntx.shortcut_app_list[j].name_size);
        MMI_AM_LOG(
                  MOD_MMI,
                  TRACE_GROUP_7,
                  "shortcut_app_list[%d] -- name_len:%d",
                  j,
                  g_am_cntx.shortcut_app_list[j].name_len);

        j++;
    }

    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_SEARCH_SHORTCUT_APPS_E);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_search_appstore
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_search_appstore(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 file_drv;
    S8 temp_path[MMI_AM_MAX_SHORTCUT_APP_FILE_PATH];    /* appstore temp file full  path */
    U16 temp_path_w[MMI_AM_MAX_SHORTCUT_APP_FILE_PATH];
    S8 as_path[MMI_AM_MAX_SHORTCUT_APP_FILE_PATH];      /* appstore file full  path */
    U16 as_path_w[MMI_AM_MAX_SHORTCUT_APP_FILE_PATH];
    FS_HANDLE fd = -1;
    mmi_am_shortcut_info_struct *sc_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_SEARCH_APPSTORE_S);

    memset(temp_path, 0, sizeof(temp_path));
    memset(temp_path_w, 0, sizeof(temp_path_w));
    memset(as_path, 0, sizeof(as_path));
    memset(as_path_w, 0, sizeof(as_path_w));

    /* set icon and name info */
    sc_info = mmi_am_config_get_am_sc_info_by_appid(APPID_VAS);
    if (sc_info == NULL)
    {
        return;
    }
    /*vgoins_20100722_start*/
    if(g_am_cntx.is_card_plug_out)
    	{
    		if (((S8) (*g_am_cntx.appstore_list.path[0]) != (S8) mmi_am_get_system_driver()) &&
            		((S8) (*g_am_cntx.appstore_list.path[0]) != (S8) MMI_AM_ROM_DIR))
	        {
	            //if (g_am_cntx.appstore_list.p_name != NULL)
	            //{
	            //    mmi_am_free(g_am_cntx.appstore_list.p_name);
	            //    g_am_cntx.appstore_list.p_name = NULL;
	            //}
	            MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_RELEASE_APPSTORE);

	            g_am_cntx.appstore_list.is_downloaded = MMI_FALSE;
	            g_am_cntx.appstore_list.is_hs_shortcut = MMI_FALSE;
	            g_am_cntx.appstore_list.is_bg_started = MMI_FALSE;
	        }
					else
					{
						return;
					}
    	}
    	/*vogins_20100722_end*/
    g_am_cntx.appstore_list.icon_id = sc_info->icon_id;
    g_am_cntx.appstore_list.name_id = sc_info->name_id;
    g_am_cntx.appstore_list.name_size = sc_info->name_size;

    if ((!g_am_cntx.has_small_font) && (sc_info->p_name))
    {
        /* get ZiMo data */
        mmi_am_get_zimo_string_data(
                                   sc_info->p_name,
                                   &g_am_cntx.appstore_list.p_name,
                                   (PS32) & g_am_cntx.appstore_list.name_len);
    }

    /* Search remove driver */
    file_drv = mmi_am_get_removeable_driver();
    if (file_drv)
    {
        /* set phsh.pht path */
        sprintf(temp_path, "%c:\\%s\\%s", file_drv, MMI_AM_VRE_HOME_DIR, MMI_AM_AS_TEMP_FILE_NAME);
        mmi_asc_to_wcs(temp_path_w, (PS8) temp_path);

        /* set phsh.vxp path */
        sprintf(
               as_path,
               "%c:\\%s\\%s",
               file_drv,
               MMI_AM_VRE_HOME_DIR,
               mmi_am_config_get_am_sc_name_by_appid(APPID_VAS));
        mmi_asc_to_wcs(as_path_w, (PS8) as_path);

        /* search phsh.pht */
        if ((fd = FS_Open(temp_path_w, FS_OPEN_NO_DIR | FS_READ_ONLY)) >= FS_NO_ERROR)
        {
            MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_search_appstore() -- phsh.pht in memory card");

            /* phsh.pht exist */
            FS_Close(fd);

            /* search phsh.vxp */
            if ((fd = FS_Open(as_path_w, FS_OPEN_NO_DIR | FS_READ_ONLY)) >= FS_NO_ERROR)
            {
                /* phsh.vxp exist */
                FS_Close(fd);
                FS_Delete(as_path_w);
                FS_Rename(temp_path_w, as_path_w);
            }
            else
            {
                FS_Rename(temp_path_w, as_path_w);
            }
        }

        /* search phsh.vxp */
        if ((fd = FS_Open(as_path_w, FS_OPEN_NO_DIR | FS_READ_ONLY)) >= FS_NO_ERROR)
        {
            /* app exist */
            FS_Close(fd);

#ifdef MMI_AM_APP_CHECK_NEW_VERSION
            /* add to appstore_list */
            mmi_am_add_appstore_list(as_path_w, MMI_AM_MAX_SHORTCUT_APP_FILE_PATH);
#else /* MMI_AM_APP_CHECK_NEW_VERSION */ 
            mmi_wcscpy(g_am_cntx.appstore_list.path[0], as_path_w);
            g_am_cntx.appstore_list.is_downloaded = MMI_TRUE;

            /* Whether the application is set to HS shortcut. */
#ifdef __MMI_VUI_HOMESCREEN__
            if (mmi_am_is_set_as_shortcut(g_am_cntx.appstore_list.path[0]))
            {
                g_am_cntx.appstore_list.is_hs_shortcut = MMI_TRUE;
            }
#endif /* __MMI_VUI_HOMESCREEN__ */ 

            /* Whether the application is running in the background. */
            if (mmi_am_app_is_bg_running(g_am_cntx.appstore_list.path[0]))
            {
                g_am_cntx.appstore_list.is_bg_started = MMI_TRUE;
            }

            MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_SEARCH_APPSTORE_E1);
            return;
#endif /* MMI_AM_APP_CHECK_NEW_VERSION */ 
        }
    }

    /**********************************************************************/

    memset(temp_path, 0, sizeof(temp_path));
    memset(temp_path_w, 0, sizeof(temp_path_w));
    memset(as_path, 0, sizeof(as_path));
    memset(as_path_w, 0, sizeof(as_path_w));

    /* Search system driver */
    file_drv = mmi_am_get_system_driver();

    /* set phsh.pht path */
    sprintf(temp_path, "%c:\\%s\\%s", file_drv, MMI_AM_VRE_HOME_DIR, MMI_AM_AS_TEMP_FILE_NAME);
    mmi_asc_to_wcs(temp_path_w, (PS8) temp_path);

    /* set phsh.vxp path */
    sprintf(as_path, "%c:\\%s\\%s", file_drv, MMI_AM_VRE_HOME_DIR, mmi_am_config_get_am_sc_name_by_appid(APPID_VAS));
    mmi_asc_to_wcs(as_path_w, (PS8) as_path);

    /* search phsh.pht */
    if ((fd = FS_Open(temp_path_w, FS_OPEN_NO_DIR | FS_READ_ONLY)) >= FS_NO_ERROR)
    {
        MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_search_appstore() -- phsh.pht in system driver");

        /* phsh.pht exist */
        FS_Close(fd);

        /* search phsh.vxp */
        if ((fd = FS_Open(as_path_w, FS_OPEN_NO_DIR | FS_READ_ONLY)) >= FS_NO_ERROR)
        {
            /* phsh.vxp exist */
            FS_Close(fd);
            FS_Delete(as_path_w);
            FS_Rename(temp_path_w, as_path_w);
        }
        else
        {
            FS_Rename(temp_path_w, as_path_w);
        }
    }

    /* search phsh.vxp */
    if ((fd = FS_Open(as_path_w, FS_OPEN_NO_DIR | FS_READ_ONLY)) >= FS_NO_ERROR)
    {
        /* app exist */
        FS_Close(fd);

#ifdef MMI_AM_APP_CHECK_NEW_VERSION
        /* add to appstore_list */
        mmi_am_add_appstore_list(as_path_w, MMI_AM_MAX_SHORTCUT_APP_FILE_PATH);
#else /* MMI_AM_APP_CHECK_NEW_VERSION */ 
        mmi_wcscpy(g_am_cntx.appstore_list.path[0], as_path_w);
        g_am_cntx.appstore_list.is_downloaded = MMI_TRUE;

        /* Whether the application is set to HS shortcut. */
#ifdef __MMI_VUI_HOMESCREEN__
        if (mmi_am_is_set_as_shortcut(g_am_cntx.appstore_list.path[0]))
        {
            g_am_cntx.appstore_list.is_hs_shortcut = MMI_TRUE;
        }
#endif /* __MMI_VUI_HOMESCREEN__ */ 

        /* Whether the application is running in the background. */
        if (mmi_am_app_is_bg_running(g_am_cntx.appstore_list.path[0]))
        {
            g_am_cntx.appstore_list.is_bg_started = MMI_TRUE;
        }

        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_SEARCH_APPSTORE_E2);
        return;
#endif /* MMI_AM_APP_CHECK_NEW_VERSION */ 
    }

    /**********************************************************************/

    /* Search rom */
    mmi_am_search_appstore_in_rom();

    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_SEARCH_APPSTORE_E3);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_search_appstore_in_rom
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_search_appstore_in_rom(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S8 rom_app_path[MMI_AM_MAX_APP_FILE_PATH];
    U16 rom_app_path_w[MMI_AM_MAX_APP_FILE_PATH];
    S32 *app_array;
    S32 app_array_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_search_appstore_in_rom() ------- [S]");

    mmi_am_get_rom_app_array(&app_array, &app_array_len);

    for (i = 0; i < g_am_cntx.rom_app_num; i++)
    {
        memset(rom_app_path, 0, sizeof(rom_app_path));
        memset(rom_app_path_w, 0, sizeof(rom_app_path_w));

        sprintf(rom_app_path, "%c:\\%s\\%u.rom", MMI_AM_ROM_DIR, MMI_AM_VRE_HOME_DIR, *(app_array + i));
        mmi_asc_to_wcs((PU16) rom_app_path_w, rom_app_path);

        /* check if the application is AppStore */
        if (!mmi_am_is_appstore_in_rom((PU16) rom_app_path_w))
        {
            continue;
        }

        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_SEARCH_APPSTORE_IN_ROM);

#ifdef MMI_AM_APP_CHECK_NEW_VERSION
        /* add to appstore_list */
        mmi_am_add_appstore_list(as_path_w, MMI_AM_MAX_SHORTCUT_APP_FILE_PATH);
#else /* MMI_AM_APP_CHECK_NEW_VERSION */ 
        mmi_wcscpy(g_am_cntx.appstore_list.path[0], rom_app_path_w);
        g_am_cntx.appstore_list.is_downloaded = MMI_TRUE;

        /* Whether the application is set to HS shortcut. */
#ifdef __MMI_VUI_HOMESCREEN__
        if (mmi_am_is_set_as_shortcut(g_am_cntx.appstore_list.path[0]))
        {
            g_am_cntx.appstore_list.is_hs_shortcut = MMI_TRUE;
        }
#endif /* __MMI_VUI_HOMESCREEN__ */ 

        /* Whether the application is running in the background. */
        if (mmi_am_app_is_bg_running(g_am_cntx.appstore_list.path[0]))
        {
            g_am_cntx.appstore_list.is_bg_started = MMI_TRUE;
        }
#endif /* MMI_AM_APP_CHECK_NEW_VERSION */ 
    }

    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_search_appstore_in_rom() ------- [E]");

    return;
}

    #ifdef MMI_AM_APP_CHECK_NEW_VERSION


/*****************************************************************************
 * FUNCTION
 *  mmi_am_add_appstore_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  full_path       [IN]        
 *  len             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_add_appstore_list(U16 *full_path, S32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    S32 version_1, version_2;
    S32 i, position = 0;    /* AppStore insert position */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_add_appstore_list() ------- [S]");

    if (full_path == NULL)
    {
        return;
    }

    g_am_cntx.appstore_list.is_downloaded = MMI_TRUE;

    /* get insert position */
    for (i = 0; i < 3; i++)
    {
        if ((g_am_cntx.appstore_list.path[i][0] == 0) && (g_am_cntx.appstore_list.path[i][1] == 0))
        {
            position = i;
            break;
        }

        ret = mmi_am_get_app_version(g_am_cntx.appstore_list.path[i], &version_1);
        MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_add_appstore_list() -- version_1:%d", version_1);
        if (!ret)
        {
            return;
        }

        ret = mmi_am_get_app_version(full_path, &version_2);
        MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_add_appstore_list() -- version_2:%d", version_2);
        if (!ret)
        {
            return;
        }

        /* compare */
        if (version_1 == version_2)
        {
            /* dont need to insert */
            return;
        }
        else if (version_1 < version_2)
        {
            /* inserted AppStore is newer */
            position = i;
            break;
        }
        else
        {
            /* inserted AppStore is older */
            continue;
        }
    }

    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_add_appstore_list() -- position:%d", position);

    /* insert operation */
    if (position == 0)
    {
        mmi_wcscpy(g_am_cntx.appstore_list.path[2], g_am_cntx.appstore_list.path[1]);
        mmi_wcscpy(g_am_cntx.appstore_list.path[1], g_am_cntx.appstore_list.path[0]);
        mmi_wcscpy(g_am_cntx.appstore_list.path[0], full_path);
    }
    else if (position == 1)
    {
        mmi_wcscpy(g_am_cntx.appstore_list.path[2], g_am_cntx.appstore_list.path[1]);
        mmi_wcscpy(g_am_cntx.appstore_list.path[1], full_path);
    }
    else if (position == 2)
    {
        mmi_wcscpy(g_am_cntx.appstore_list.path[2], full_path);
    }

    /* Whether the application is set to HS shortcut. */
#ifdef __MMI_VUI_HOMESCREEN__
    if (mmi_am_is_set_as_shortcut(g_am_cntx.appstore_list.path[position]))
    {
        g_am_cntx.appstore_list.is_hs_shortcut = MMI_TRUE;
    }
    MMI_AM_LOG(
              MOD_MMI,
              TRACE_GROUP_7,
              "mmi_am_add_appstore_list() -- is_hs_shortcut:%d",
              g_am_cntx.appstore_list.is_hs_shortcut);
#endif /* __MMI_VUI_HOMESCREEN__ */ 

    /* Whether the application is running in the background. */
    if (mmi_am_app_is_bg_running(g_am_cntx.appstore_list.path[position]))
    {
        g_am_cntx.appstore_list.is_bg_started = MMI_TRUE;
    }
    MMI_AM_LOG(
              MOD_MMI,
              TRACE_GROUP_7,
              "mmi_am_add_appstore_list() -- is_bg_started:%d",
              g_am_cntx.appstore_list.is_bg_started);

    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_add_appstore_list() ------- [E]");
}
    #endif /* MMI_AM_APP_CHECK_NEW_VERSION */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_am_search_rom_apps
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_am_search_rom_apps(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 ret;
    S32 res_size;
    S32 cache_size = MMI_AM_LOAD_RES_BUF_SIZE;
    S8 *cache_buf = NULL;
    S8 rom_app_path[MMI_AM_MAX_APP_FILE_PATH];
    U16 rom_app_path_w[MMI_AM_MAX_APP_FILE_PATH];
    S32 *app_array;
    S32 app_array_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_SEARCH_ROM_APPS_S);
    
/*vogins_20100716_start*/
	if(g_am_cntx.is_card_plug_in)
	      return MMI_TRUE;
/*vogins_20100716_end*/

    cache_buf = mmi_am_calloc(cache_size);
    MMI_AM_ASSERT(cache_buf != NULL);
    if (!cache_buf)
    {
        return MMI_FALSE;
    }

    mmi_am_get_rom_app_array(&app_array, &app_array_len);
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_search_rom_apps() -- app_array_len:%d", app_array_len);

    for (i = 0; i < g_am_cntx.rom_app_num; i++)
    {
        memset(rom_app_path, 0, sizeof(rom_app_path));
        memset(rom_app_path_w, 0, sizeof(rom_app_path_w));
        memset(cache_buf, 0, cache_size);

        sprintf(rom_app_path, "%c:\\%s\\%u.rom", MMI_AM_ROM_DIR, MMI_AM_VRE_HOME_DIR, *(app_array + i));

        mmi_asc_to_wcs((PU16) rom_app_path_w, rom_app_path);

        /* check if the application is AppStore */
        if (mmi_am_is_appstore_in_rom((PU16) rom_app_path_w))
        {
            continue;
        }

        /* set rom app full path */
        mmi_wcscpy(g_am_cntx.rom_app_list[i].path, rom_app_path_w);

        /* get icon and name */
        if (mmi_am_vre_load_resource_from_file
            ((PU16) rom_app_path_w, MMI_AM_APP_LOGO, &res_size, cache_buf, cache_size))
        {
            MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_search_rom_apps() -- res_size:%d", res_size);
            /* get app ICON */
            ret = mmi_am_get_gif_data(
                                     (PU8) cache_buf,
                                     &g_am_cntx.rom_app_list[i].p_icon,
                                     &g_am_cntx.rom_app_list[i].icon_size);
            MMI_AM_LOG(
                      MOD_MMI,
                      TRACE_GROUP_7,
                      "rom_app_list[%d] -- icon_size:%d",
                      i,
                      g_am_cntx.rom_app_list[i].icon_size);
            MMI_AM_ASSERT(g_am_cntx.rom_app_list[i].p_icon != NULL);
            if (!ret)
            {
                mmi_am_free(cache_buf);
                return MMI_FALSE;
            }

            /* get app name */
            ret = mmi_am_get_app_name(
                                     rom_app_path_w,
                                     (PU8) cache_buf,
                                     (void **)&g_am_cntx.rom_app_list[i].p_name,
                                     &g_am_cntx.rom_app_list[i].name_len);
            MMI_AM_LOG(
                      MOD_MMI,
                      TRACE_GROUP_7,
                      "rom_app_list[%d] -- name_len:%d",
                      i,
                      g_am_cntx.rom_app_list[i].name_len);
            MMI_AM_ASSERT(g_am_cntx.rom_app_list[i].p_name != NULL);
            if (!ret)
            {
                mmi_am_free(cache_buf);
                return MMI_FALSE;
            }
        }
        else if (mmi_am_vre_load_resource_from_file
                 ((PU16) rom_app_path_w, MMI_AM_APP_V20_LOGO, &res_size, cache_buf, cache_size))
        {
            /* support small font */
            if (g_am_cntx.has_small_font)
            {
                g_am_cntx.rom_app_list[i].p_name = (PU8) GetString(STR_ID_AM_APP_NAME_VRE20);
                g_am_cntx.rom_app_list[i].name_len = mmi_wcslen((PU16) GetString(STR_ID_AM_APP_NAME_VRE20));
            }
            else
            {
                mmi_am_get_zimo_string_data(
                                           (PU8) AM_App_VRE20,
                                           &g_am_cntx.rom_app_list[i].p_name,
                                           (PS32) & g_am_cntx.rom_app_list[i].name_len);
            }
        }
        else    /* Use default ICON and Zimo */
        {
            /* support small font */
            if (g_am_cntx.has_small_font)
            {
                g_am_cntx.rom_app_list[i].p_name = (PU8) GetString(STR_ID_AM_APP_NAME_DEFAULT); /* NULL; */
                g_am_cntx.rom_app_list[i].name_len = mmi_wcslen((PU16) GetString(STR_ID_AM_APP_NAME_DEFAULT));  /* NULL; */
            }
            else
            {
                mmi_am_get_zimo_string_data(
                                           (PU8) AM_App_Default,
                                           &g_am_cntx.rom_app_list[i].p_name,
                                           (PS32) & g_am_cntx.rom_app_list[i].name_len);
            }
        }

        /* Whether the application is set to HS shortcut. */
#ifdef __MMI_VUI_HOMESCREEN__
        if (mmi_am_is_set_as_shortcut(g_am_cntx.rom_app_list[i].path))
        {
            g_am_cntx.rom_app_list[i].is_hs_shortcut = MMI_TRUE;
        }
        else
#endif /* __MMI_VUI_HOMESCREEN__ */ 
        {
            g_am_cntx.rom_app_list[i].is_hs_shortcut = MMI_FALSE;
        }

        /* Whether the application is running in the background. */
        if (mmi_am_app_is_bg_running(g_am_cntx.rom_app_list[i].path))
        {
            g_am_cntx.rom_app_list[i].is_bg_started = MMI_TRUE;
        }
        else
        {
            g_am_cntx.rom_app_list[i].is_bg_started = MMI_FALSE;
        }
/*Vogins_20100710_start*/
        g_am_cntx.rom_app_list[i].idx = g_am_cntx.shortcut_app_num + i;
        if (g_am_cntx.rom_app_list[i].is_bg_started)
        {
            S32 k;
            mmi_am_rom_app_struct rom;  
            k = i - 1;
            while ((g_am_cntx.rom_app_list[k].is_bg_started == 0)&& k >= 0)
            {
                S32 temp;
                rom = g_am_cntx.rom_app_list[k];
                g_am_cntx.rom_app_list[k] = g_am_cntx.rom_app_list[k+1];
                g_am_cntx.rom_app_list[k+1] = rom;
                temp = g_am_cntx.rom_app_list[k].idx;
                g_am_cntx.rom_app_list[k].idx = g_am_cntx.rom_app_list[k+1].idx;
                g_am_cntx.rom_app_list[k+1].idx = temp;
                k--;
            }
        }

/*Vogins_20100710_end*/
        MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "rom_app_list[%d] -- idx:%d", i, g_am_cntx.rom_app_list[i].idx);
        MMI_AM_LOG(
                  MOD_MMI,
                  TRACE_GROUP_7,
                  "rom_app_list[%d] -- is_hs_shortcut:%d",
                  i,
                  g_am_cntx.rom_app_list[i].is_hs_shortcut);
        MMI_AM_LOG(
                  MOD_MMI,
                  TRACE_GROUP_7,
                  "rom_app_list[%d] -- is_bg_started:%d",
                  i,
                  g_am_cntx.rom_app_list[i].is_bg_started);
        MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "rom_app_list[%d] -- p_icon:0x%08x", i, g_am_cntx.rom_app_list[i].p_icon);
        MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "rom_app_list[%d] -- icon_size:%d", i, g_am_cntx.rom_app_list[i].icon_size);
        MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "rom_app_list[%d] -- p_name:0x%08x", i, g_am_cntx.rom_app_list[i].p_name);
        MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "rom_app_list[%d] -- name_size:%d", i, g_am_cntx.rom_app_list[i].name_size);
        MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "rom_app_list[%d] -- name_len:%d", i, g_am_cntx.rom_app_list[i].name_len);

    }

    /* release cache_buf */
    mmi_am_free(cache_buf);

    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_SEARCH_ROM_APPS_E);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_get_rom_appinfo_by_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mmi_am_rom_app_struct *mmi_am_get_rom_appinfo_by_idx(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_am_cntx.rom_app_num; i++)
    {
        if (g_am_cntx.rom_app_list[i].idx == idx)
        {
            return &g_am_cntx.rom_app_list[i];
        }
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_search_vxp_files
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_am_search_vxp_files(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 vxp_path[MMI_AM_MAX_APP_FILE_PATH];
    U16 vxp_path_w[MMI_AM_MAX_APP_FILE_PATH];
    U16 app_name_w[MMI_AM_MAX_APP_FILE_NAME];
    FS_DOSDirEntry de;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_SEARCH_VXP_FILES_S, g_am_cntx.is_card_plug_in, g_am_cntx.is_card_plug_out);

    memset(vxp_path, 0, sizeof(vxp_path));
    memset(vxp_path_w, 0, sizeof(app_name_w));
    memset(app_name_w, 0, sizeof(app_name_w));


    if (g_am_cntx.is_card_plug_in)
    {
        g_am_search_cntx.cur_driver = mmi_am_get_removeable_driver();
        g_am_search_cntx.search_state = SEARCHING_CARD;
        mmi_am_release_vxp_list_nodes_in_memory_card();
    }
    else if (g_am_cntx.is_card_plug_out)
    {
        g_am_search_cntx.cur_driver = mmi_am_get_system_driver();
        mmi_am_release_vxp_list_all_nodes();
        g_am_search_cntx.search_state = SEARCHING;
    }
    else
    {
        /*Vogins_20100625_start*/
        num_app_move = 0;
/*Vogins_20100625_end*/
        g_am_search_cntx.cur_driver = mmi_am_get_home_driver();
        g_am_search_cntx.search_state = SEARCHING;

	/*vogins_20100727_start*/
	if(g_am_cntx.vxp_file_list->nb_elt != 0)
	{
		mmi_am_release_vxp_list();
		g_am_cntx.vxp_file_list = sml_list_new();
	}
	/*vogins_20100727_end*/
    }

    sprintf(vxp_path, "%c:\\%s\\%s", g_am_search_cntx.cur_driver, MMI_AM_VRE_HOME_DIR, MMI_AM_SEARCH_PATTERN);
    mmi_asc_to_wcs(vxp_path_w, vxp_path);

    g_am_search_cntx.search_hdl = FS_FindFirst(vxp_path_w, 0, FS_ATTR_DIR, &de, app_name_w, MMI_AM_MAX_APP_FILE_NAME * ENCODE_BYTE);
    if (g_am_search_cntx.search_hdl >= 0)
    {
        MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "FS_FindFirst -- cur_driver:%d", g_am_search_cntx.cur_driver);
        if (!mmi_am_add_vxp_file_list(app_name_w, de.DateTime))
        {
            FS_FindClose(g_am_search_cntx.search_hdl);
            g_am_search_cntx.search_hdl = -1;
            return MMI_FALSE;
        }
    }

    /* start a timer to search more vxp files */
    gui_start_timer(MMI_AM_SEARCH_APP_TIMER_DELAY, mmi_am_search_vxp_cb);

    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_SEARCH_VXP_FILES_E, g_am_search_cntx.search_state);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_search_vxp_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_search_vxp_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 vxp_path[MMI_AM_MAX_APP_FILE_PATH];
    U16 vxp_path_w[MMI_AM_MAX_APP_FILE_PATH];
    U16 app_name_w[MMI_AM_MAX_APP_FILE_NAME];
    FS_DOSDirEntry de;
    S32 ret, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
             MMI_FW_TRC_G1_FRM,
             TRC_MMI_AM_SEARCH_VXP_CB_S,
             g_am_cntx.is_card_plug_in,
             g_am_cntx.is_card_plug_out,
             g_am_search_cntx.search_hdl,
             g_am_search_cntx.search_state,
             g_am_search_cntx.cur_driver);

    memset(vxp_path, 0, sizeof(vxp_path));
    mmi_asc_to_wcs(vxp_path_w, vxp_path);

    sprintf(vxp_path, "%c:\\%s\\%s", g_am_search_cntx.cur_driver, MMI_AM_VRE_HOME_DIR, MMI_AM_SEARCH_PATTERN);
    for (i = 0; i < MMI_AM_ASYN_SEARCH_NUM; i++)
    {
        memset(app_name_w, 0, sizeof(app_name_w));
        ret = FS_FindNext(g_am_search_cntx.search_hdl, &de, app_name_w, MMI_AM_MAX_APP_FILE_NAME * ENCODE_BYTE);
        if (ret == FS_NO_ERROR)
        {
            MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_SEARCH_VXP_CB_FINDNEXT, g_am_search_cntx.cur_driver);
            if (!mmi_am_add_vxp_file_list(app_name_w, de.DateTime))
            {
                FS_FindClose(g_am_search_cntx.search_hdl);
                g_am_search_cntx.search_hdl = -1;
                MMI_AM_ASSERT(0);
                return;
            }
        }
        else    /* not find */
        {
            /* close file handle */
            FS_FindClose(g_am_search_cntx.search_hdl);
            g_am_search_cntx.search_hdl = -1;

            /* If it is not plug in memory card, then switch to system driver */
            if (g_am_search_cntx.cur_driver != mmi_am_get_system_driver() && g_am_search_cntx.search_state == SEARCHING)
            {
                memset(vxp_path, 0, sizeof(vxp_path));
                mmi_asc_to_wcs(vxp_path_w, vxp_path);
                memset(app_name_w, 0, sizeof(app_name_w));

                /* switch to System Driver */
                g_am_search_cntx.cur_driver = mmi_am_get_system_driver();

                sprintf(
                       vxp_path,
                       "%c:\\%s\\%s",
                       g_am_search_cntx.cur_driver,
                       MMI_AM_VRE_HOME_DIR,
                       MMI_AM_SEARCH_PATTERN);

                mmi_asc_to_wcs(vxp_path_w, vxp_path);

                g_am_search_cntx.search_hdl = FS_FindFirst(vxp_path_w, 0, FS_ATTR_DIR, &de, app_name_w, MMI_AM_MAX_APP_FILE_NAME * ENCODE_BYTE);
                if (g_am_search_cntx.search_hdl >= 0)
                {
                    MMI_TRACE(
                             MMI_FW_TRC_G1_FRM,
                             TRC_MMI_AM_SEARCH_VXP_CB_FINDFIRST_IN_PHONE,
                             g_am_search_cntx.cur_driver);
                    if (!mmi_am_add_vxp_file_list(app_name_w, de.DateTime))
                    {
                        FS_FindClose(g_am_search_cntx.search_hdl);
                        g_am_search_cntx.search_hdl = -1;
                        MMI_AM_ASSERT(0);
                        return;
                    }
                    continue;
                }
                else
                {
                    FS_FindClose(g_am_search_cntx.search_hdl);
                    g_am_search_cntx.search_hdl = -1;

                    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_SEARCH_VXP_CB_DONE_IN_PHONE);

                    /* no vxp files in System Driver, search done */
                    g_am_search_cntx.search_state = SEARCH_DONE;
                    break;
                }
            }
            /* plug in memory card in loading screen */
            else if ((g_am_search_cntx.cur_driver == mmi_am_get_system_driver()) && (g_am_cntx.is_card_plug_in))
            {
                memset(vxp_path, 0, sizeof(vxp_path));
                mmi_asc_to_wcs(vxp_path_w, vxp_path);
                memset(app_name_w, 0, sizeof(app_name_w));

                /* switch to Memory Card Driver */
                g_am_search_cntx.cur_driver = mmi_am_get_removeable_driver();
                g_am_search_cntx.search_state = SEARCHING_CARD;
                mmi_am_release_vxp_list_nodes_in_memory_card();

                sprintf(
                       vxp_path,
                       "%c:\\%s\\%s",
                       g_am_search_cntx.cur_driver,
                       MMI_AM_VRE_HOME_DIR,
                       MMI_AM_SEARCH_PATTERN);

                mmi_asc_to_wcs(vxp_path_w, vxp_path);

                g_am_search_cntx.search_hdl = FS_FindFirst(vxp_path_w, 0, FS_ATTR_DIR, &de, app_name_w, MMI_AM_MAX_APP_FILE_NAME * ENCODE_BYTE);
                if (g_am_search_cntx.search_hdl >= 0)
                {
                    MMI_TRACE(
                             MMI_FW_TRC_G1_FRM,
                             TRC_MMI_AM_SEARCH_VXP_CB_FINDFIRST_PLUG_IN_CARD,
                             g_am_search_cntx.cur_driver);
                    if (!mmi_am_add_vxp_file_list(app_name_w, de.DateTime))
                    {
                        FS_FindClose(g_am_search_cntx.search_hdl);
                        g_am_search_cntx.search_hdl = -1;
                        MMI_AM_ASSERT(0);
                        return;
                    }
                }
                else
                {
                    FS_FindClose(g_am_search_cntx.search_hdl);
                    g_am_search_cntx.search_hdl = -1;

                    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_SEARCH_VXP_CB_DONE_PLUG_IN_CARD);

                    /* no vxp files in Memory Card, search done */
                    g_am_search_cntx.search_state = SEARCH_DONE;
                    break;
                }
            }
            else
            {
                MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_SEARCH_VXP_CB_DONE);
                /* search done */
                g_am_search_cntx.search_state = SEARCH_DONE;
                break;
            }
        }
    }

    if (g_am_search_cntx.search_state == SEARCHING || g_am_search_cntx.search_state == SEARCHING_CARD)
    {
        /* continue to search */
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_SEARCH_VXP_CB_CONTINUE);
        gui_start_timer(MMI_AM_SEARCH_APP_TIMER_DELAY, mmi_am_search_vxp_cb);
    }
    else if (g_am_search_cntx.search_state == SEARCH_DONE)
    {
        /* init */
        g_am_search_cntx.search_hdl = -1;
        g_am_search_cntx.search_state = SEARCH_NONE;
        g_am_search_cntx.cur_driver = mmi_am_get_home_driver();

        //if (g_am_cntx.is_card_plug_out)
        //{
        //    return;
        //}

        // search done, then
        // build app list displayed on Main Screen
        if (g_am_cntx.is_card_plug_in)
        {
            /* has not yet enter main screen */
            //if (!mmi_frm_scrn_is_present(GRP_ID_AM, SCR_ID_AM_MAIN, MMI_FRM_NODE_ALL_FLAG))
            //{
            //  /* continue to search */
            //    mmi_am_search_vxp_files();
            //    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_search_vxp_cb() ------- [E1]");
            //    return;
            //}

            /* release app_list */
            mmi_am_ms_release_app_list_all_nodes();

            mmi_am_ms_init();

            if (mmi_am_ms_build_app_list() == MMI_FALSE)
            {
                mmi_frm_group_close(GRP_ID_AM);
                return;
            }

            if (mmi_frm_scrn_is_present(GRP_ID_AM, SCR_ID_AM_MAIN, MMI_FRM_NODE_ALL_FLAG))
            {
                mmi_frm_scrn_close_active_id();
            }
            else
            {
#ifdef AM_09A
                if (GetActiveScreenId() == SCR_ID_AM_LOADING)
                {
                    mmi_am_entry_main_scrn();
                }
                else
                {
#ifdef __VRE_AM_08AB__
                    history new_screen;
                    new_screen.scrnID = SCR_ID_AM_MAIN;
                    new_screen.entryFuncPtr = (FuncPtr) mmi_am_entry_main_scrn;
                    memset(new_screen.guiBuffer, 0, MAX_GUI_BUFFER);
                    InsertHistoryAfterThisScrnReference(SCR_ID_AM_LOADING, &new_screen);
#else
                    mmi_frm_screen_struct new_screen;

                    mmi_frm_init_screen_struct(&new_screen);
                    new_screen.scrnID = SCR_ID_AM_MAIN;
                    new_screen.entryFuncPtr = (entry_func_ptr) mmi_am_entry_main_scrn;
                    mmi_frm_insert_screen(SCR_ID_AM_LOADING, &new_screen, MMI_FRM_INSERT_AFTER_SCRN);
#endif
                }
#else /* AM_09A */ 
                mmi_am_entry_main_scrn();
#endif /* AM_09A */ 
            }
        }
        else
        {
            mmi_am_ms_init();

            if (mmi_am_ms_build_app_list() == MMI_FALSE)
            {
                mmi_frm_group_close(GRP_ID_AM);
                return;
            }

            /* enter Main Screen */
            if (mmi_frm_scrn_is_present(GRP_ID_AM, SCR_ID_AM_MAIN, MMI_FRM_NODE_ALL_FLAG))
            {
                mmi_frm_scrn_close_active_id();
            }
            else
            {
#ifdef AM_09A
                if (GetActiveScreenId() == SCR_ID_AM_LOADING)
                {
                    mmi_am_entry_main_scrn();
                }
                else    /* avoid interrupt screen coverd by AM Main Screen */
                {
#ifdef __VRE_AM_08AB__
                    history new_screen;
                    new_screen.scrnID = SCR_ID_AM_MAIN;
                    new_screen.entryFuncPtr = (FuncPtr) mmi_am_entry_main_scrn;
                    memset(new_screen.guiBuffer, 0, MAX_GUI_BUFFER);
                    InsertHistoryAfterThisScrnReference(SCR_ID_AM_LOADING, &new_screen);
#else
                    mmi_frm_screen_struct new_screen;

                    mmi_frm_init_screen_struct(&new_screen);
                    new_screen.scrnID = SCR_ID_AM_MAIN;
                    new_screen.entryFuncPtr = (entry_func_ptr) mmi_am_entry_main_scrn;
                    mmi_frm_insert_screen(SCR_ID_AM_LOADING, &new_screen, MMI_FRM_INSERT_AFTER_SCRN);
#endif
                }
#else /* AM_09A */ 
                mmi_am_entry_main_scrn();
#endif /* AM_09A */ 
            }
        }

    }

    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_SEARCH_VXP_CB_E);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_add_vxp_file_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_name        [IN]        
 *  date_time       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_am_add_vxp_file_list(U16 *app_name, FS_DOSDateTime date_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 app_path[MMI_AM_MAX_APP_FILE_PATH];
    U16 app_path_w[MMI_AM_MAX_APP_FILE_PATH];
    mmi_am_vxp_file_struct *p;
    S32 position;
    S32 vxp_num_max;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_add_vxp_file_list() ------- [S]");

    memset(app_path, 0, sizeof(app_path));
    memset(app_path_w, 0, sizeof(app_path_w));
    vxp_num_max = MMI_AM_MAX_APP_NUM - g_am_cntx.shortcut_app_num - g_am_cntx.rom_app_num;

    /* shortcut app dont add to vxp file list */
    if (mmi_am_config_is_shortcut_app(app_name, g_am_search_cntx.cur_driver) == MMI_TRUE)
    {
        MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_add_vxp_file_list() -- shortcut app");
        return MMI_TRUE;
    }

    /* allocate memory */
    p = mmi_am_calloc(sizeof(mmi_am_vxp_file_struct));
    if (p == NULL)
    {
        MMI_AM_ASSERT(p != NULL);
        return MMI_FALSE;
    }

    /* get app path from app name */
    sprintf(app_path, "%c:\\%s\\", g_am_search_cntx.cur_driver, MMI_AM_VRE_HOME_DIR);
    mmi_asc_to_wcs(app_path_w, app_path);
    mmi_wcscat(app_path_w, app_name);

    /* set path and modify_time */
    mmi_wcscpy(p->path, app_path_w);
    memcpy((void*)&(p->time), (void*)&date_time, sizeof(FS_DOSDateTime));

    /* get insert position */
/*Vogins_20100625_start*/
    position = mmi_am_binary_search(num_app_move, sml_list_size(g_am_cntx.vxp_file_list) - 1, &date_time);

    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_ADD_VXP_FILE_LIST_POSTION, position);

    if (position < vxp_num_max)
    {
        if (mmi_am_app_is_bg_running(p->path))
        {
            S16 i, ret;
            mmi_am_vxp_file_struct *vxp_p;
            for (i = 0; i < num_app_move; i++)
            {
                vxp_p = sml_list_get(g_am_cntx.vxp_file_list, i);
                ret = mmi_am_compare_time(&p->time, &vxp_p->time);
                if (ret == 1)
                    break;
            }
            num_app_move++;
            sml_list_add(g_am_cntx.vxp_file_list, p, i);
        }
        else
        {
            if (num_app_move == sml_list_size(g_am_cntx.vxp_file_list))
                position = num_app_move;
            sml_list_add(g_am_cntx.vxp_file_list, p, position);
        }
/*Vogins_20100625_end*/
        if (sml_list_size(g_am_cntx.vxp_file_list) > vxp_num_max)
        {
            mmi_am_vxp_file_struct *q = sml_list_get(g_am_cntx.vxp_file_list, vxp_num_max);

            mmi_am_free(q);
            sml_list_remove(g_am_cntx.vxp_file_list, vxp_num_max);
        }
    }
    else
    {
        mmi_am_free(p);
    }

    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_add_vxp_file_list() ------- [E]");

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_binary_search
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modify_time     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
/*Vogins_20100625_start*/
U32 mmi_am_binary_search(S32 low, S32 high, FS_DOSDateTime *modify_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//    S32 low = 0;
//    S32 high = sml_list_size(g_am_cntx.vxp_file_list) - 1;
/*Vogins_20100625_end*/
    S32 mid = (low + high) >> 2;
    mmi_am_vxp_file_struct *p;
    S32 ret_cmp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* search axis value */
    while (low <= high)
    {
        mid = (low + high) / 2;

        p = sml_list_get(g_am_cntx.vxp_file_list, mid);

        ret_cmp = mmi_am_compare_time(modify_time, &p->time);

        if (ret_cmp == -1)  /* modify_time < p->time */
        {
            low = mid + 1;
        }
        else if (ret_cmp == 1)  /* modify_time > p->time */
        {
            high = mid - 1;
        }
        else    /* modify_time = p->time */
        {
            if (mid == sml_list_size(g_am_cntx.vxp_file_list) - 1)
            {
                return mid + 1;
            }
            else
            {
                return mmi_am_search_same_time_pos(modify_time, mid + 1);
            }
        }
    }

    // TODO: Verify
    if (mid < 0)
    {
        return 0;
    }

    p = sml_list_get(g_am_cntx.vxp_file_list, mid);
    ret_cmp = mmi_am_compare_time(modify_time, &p->time);

    if (ret_cmp == -1)  /* modify_time < p->time */
    {
        if (mid != (sml_list_size(g_am_cntx.vxp_file_list) - 1))
        {
            return mid + 1;
        }
        else
        {
            return -1;
        }
    }
    else if (ret_cmp == 1)  /* modify_time > p->time */
    {
        return mid;
    }

    return mid;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_search_same_time_pos
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modify_time     [IN]        
 *  pos             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_am_search_same_time_pos(FS_DOSDateTime *modify_time, S32 pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cur_pos = pos;
    S32 cmp_ret;
    mmi_am_vxp_file_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (cur_pos < sml_list_size(g_am_cntx.vxp_file_list))
    {
        p = sml_list_get(g_am_cntx.vxp_file_list, cur_pos);

        cmp_ret = mmi_am_compare_time(modify_time, &p->time);
        if (cmp_ret == 0)
        {
            cur_pos++;
            if (cur_pos == sml_list_size(g_am_cntx.vxp_file_list))
            {
                return -1;
            }
        }
        else
        {
            return cur_pos;
        }
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_compare_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  time1       [IN]        
 *  time2       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_am_compare_time(FS_DOSDateTime *time1, FS_DOSDateTime *time2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (time1->Year1980 > time2->Year1980)
        return 1;
    else if (time1->Year1980 < time2->Year1980)
        return -1;

    if (time1->Month > time2->Month)
        return 1;
    else if (time1->Month < time2->Month)
        return -1;

    if (time1->Day > time2->Day)
        return 1;
    else if (time1->Day < time2->Day)
        return -1;

    if (time1->Hour > time2->Hour)
        return 1;
    else if (time1->Hour < time2->Hour)
        return -1;

    if (time1->Minute > time2->Minute)
        return 1;
    else if (time1->Minute < time2->Minute)
        return -1;

    if (time1->Second2 > time2->Second2)
        return 1;
    else if (time1->Second2 < time2->Second2)
        return -1;

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_download_app_from_mm_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_download_app_from_mm_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_am_qs_cntx.quick_start_flag = START_FROM_NONE;
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_download_app_from_mm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_download_app_from_mm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U16 temp_file_path[MMI_AM_MAX_APP_FILE_PATH];
    U32 dl_app_id;
    mmi_am_shortcut_info_struct *mm_sc_info;
    U16 file_name[MMI_AM_MAX_SHORTCUT_APP_NAME];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_DL_APP_FROM_MM_S);

    memset(temp_file_path, 0, sizeof(temp_file_path));

    g_am_qs_cntx.is_quick_start = MMI_TRUE;
    g_am_qs_cntx.is_download = MMI_TRUE;
    /*vogins 100726 begin*/
    g_am_qs_cntx.is_not_enough_memory = MMI_FALSE;
/*vogins 100726 end*/

    //mmi_frm_group_enter_ex(GRP_ID_ROOT, GRP_ID_AM, mmi_am_grp_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    /* AM init */
    if (g_am_cntx.adm_pool_id == NULL)
    {
        if (!mmi_am_start_int())
        {
            mmi_frm_group_close(GRP_ID_AM);
            MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_START_FROM_MM_E2);
            return;
        }
    }

	//SZFE
    //mmi_am_set_dcnt_ready_status(MMI_TRUE);

    /* Notify VRE Core */
    mmi_am_vre_set_am_state(MMI_AM_IN_USE);


	mmi_am_os_download_accept();

    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_DL_APP_FROM_MM_E2);
}


void mmi_am_download_app_from_mm_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_status ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, 
              TRC_MMI_AM_DL_APP_FROM_MM_DEINIT_S, 
              g_am_cntx.adm_pool_id, 
              g_am_cntx.dyn_mem_pool,
              g_am_qs_cntx.is_quick_start,
              g_am_qs_cntx.is_download,
              g_am_qs_cntx.quick_start_flag,
              g_am_cntx.is_vre_init);

    /* close vre folder file handle */
    if (g_am_cntx.card_vre_folder_hdl >= 0)
    {
        FS_Close(g_am_cntx.card_vre_folder_hdl);
        g_am_cntx.card_vre_folder_hdl = -1;
    }

    if (g_am_cntx.phone_vre_folder_hdl >= 0)
    {
        FS_Close(g_am_cntx.phone_vre_folder_hdl);
        g_am_cntx.phone_vre_folder_hdl = -1;
    }

    /* Delete ADM */
    if (g_am_cntx.adm_pool_id)
    {
        ret = kal_adm_delete(g_am_cntx.adm_pool_id);

        MMI_AM_ASSERT(ret == KAL_SUCCESS);
        g_am_cntx.adm_pool_id = NULL;
    }

    /* release dynamic memory */
    if (g_am_cntx.dyn_mem_pool != NULL)
    {
#ifndef MMI_AM_USING_VRE_MEM
        applib_mem_ap_free(g_am_cntx.dyn_mem_pool);
#else 
        mmi_am_vre_free(g_am_cntx.dyn_mem_pool);
#endif 
        g_am_cntx.dyn_mem_pool = NULL;
    }

    /* Notify VRE Core */
    mmi_am_vre_set_am_state(MMI_AM_OUT_OF_USE);

    /* Unload VRE Core */
    mmi_am_vre_unload_core();

    /* deinit quick download context */
    g_am_qs_cntx.app_id = 0;
    g_am_qs_cntx.is_quick_start = MMI_FALSE;
    g_am_qs_cntx.is_download = MMI_FALSE;
    g_am_qs_cntx.quick_start_flag = START_FROM_NONE;

    /* set VRE Core flag */
    g_am_cntx.is_vre_init = MMI_FALSE;

    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_DL_APP_FROM_MM_DEINIT_E);
}

    #if 0
/*****************************************************************************
 * FUNCTION
 *  mmi_am_search_temp_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name           [IN]        
 *  temp_file_path      [OUT]       
 *  size                [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_am_search_temp_file(S8 *file_name, U16 *temp_file_path, U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 temp_file[MMI_AM_MAX_APP_FILE_NAME << 1];
    S8 temp_path[MMI_AM_MAX_APP_FILE_PATH];
    S32 file_drv;
    FS_HANDLE fd = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(temp_file, 0, sizeof(temp_file));
    memset(temp_path, 0, sizeof(temp_path));
    memset(temp_file_path, 0, size);

    if (mmi_am_get_file_name(file_name, temp_file))
    {
        return -1;
    }

    strcat(temp_file, ".");
    strcat(temp_file, MMI_AM_TEMP_SUFFIX);

    /* search temp file in memory card */
    file_drv = mmi_am_get_removeable_driver();
    if (file_drv)
    {
        sprintf(temp_path, "%c:\\%s\\%s", file_drv, MMI_AM_VRE_HOME_DIR, temp_file);
        mmi_asc_to_wcs(temp_file_path, (PS8) temp_path);
        if ((fd = FS_Open(temp_file_path, FS_OPEN_NO_DIR | FS_READ_ONLY)) >= FS_NO_ERROR)
        {
            /* app exist */
            FS_Close(fd);
            return MMI_TRUE;
        }
    }

    memset(temp_path, 0, sizeof(temp_path));
    memset(temp_file_path, 0, size);

    /* search app in system driver */
    file_drv = mmi_am_get_system_driver();
    sprintf(temp_path, "%c:\\%s\\%s", file_drv, MMI_AM_VRE_HOME_DIR, temp_file);
    mmi_asc_to_wcs(temp_file_path, (PS8) temp_path);
    if ((fd = FS_Open(temp_file_path, FS_OPEN_NO_DIR | FS_READ_ONLY)) >= FS_NO_ERROR)
    {
        /* app exist */
        FS_Close(fd);
        return MMI_TRUE;
    }

    /* app does not exist */
    memset(temp_file_path, 0, size);

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_get_file_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_name        [IN]        
 *  des_name        [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_am_get_file_name(S8 *src_name, S8 *des_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *pos = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pos = strchr(src_name, '.');

    if (pos != NULL)
    {
        strncpy(des_name, src_name, pos - src_name);
        return 0;
    }
    else
    {
        return -1;
    }

}
    #endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_am_launch_app_async_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_path     [IN]       
 *  evt     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_launch_app_async_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_am_qs_cntx.is_quick_start)
    {
            if (g_am_qs_cntx.quick_start_flag == FILE_MGR)
            {
                  mmi_am_start_from_fm(g_am_qs_cntx.path);
             }
            else if (g_am_qs_cntx.quick_start_flag == HS_SHORTCUT)
            {
                 mmi_am_start_from_hs(g_am_qs_cntx.path);
            }
            else if (g_am_qs_cntx.quick_start_flag == MAIN_MENU)
            {
                  mmi_am_start_from_mm(g_am_qs_cntx.app_id);
            }
     }
     else
     {
            g_am_cntx.start_state = START_BEGIN;
            mmi_am_entry_loading_scrn();
            #ifndef AM_09A
            mmi_frm_scrn_close_active_id();
            #endif
     }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_app_launch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_path        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_am_app_launch(U16 *app_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_app_launch() ------- [S]");
/*vogins_20100716_start*/
	if(g_am_relaunch_cntx.am_relaunch_tag)
	{
		g_am_relaunch_cntx.am_relaunch_tag = MMI_FALSE;
		g_am_cntx.app_launch_path = g_am_relaunch_cntx.path;
	}
	else
/*vogins_20100716_end*/
	{
               g_am_cntx.app_launch_path = app_path;
	}
    gui_start_timer(1, mmi_am_app_launch_cb);   /* For 09B FW issue */

    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_app_launch() ------- [E]");
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_app_launch_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_app_launch_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_APP_LAUNCH_CB_S, g_am_qs_cntx.is_quick_start);

    ret = mmi_am_app_launch_int(g_am_cntx.app_launch_path);

    if (g_am_qs_cntx.is_quick_start)
    {
/*michael 100430 begin*/
        g_am_cntx.start_state = START_NONE;
        if (!g_am_qs_cntx.is_not_enough_memory)
        {
            g_am_qs_cntx.quick_start_flag = START_FROM_NONE;
        }

        /* not fail popup, then close the screen group directly; or allocate memory failed, close screen group. */
        if (ret || g_am_qs_cntx.is_not_enough_memory)
        {
            mmi_frm_group_close(GRP_ID_AM);
        }

#ifdef AM_09A
        if (!g_am_qs_cntx.is_not_enough_memory)//if (g_is_denint != MMI_FALSE)
        {
            mmi_am_grp_deinit();
            g_am_qs_cntx.is_quick_start = MMI_FALSE;
        }
        mmi_am_vre_unload_core();
        g_am_cntx.is_vre_init = MMI_FALSE;
#endif /* AM_09A */
/*michael 100430 end*/ 
    }

    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_APP_LAUNCH_CB_E, g_am_cntx.is_launch_vas);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_app_launch_int
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_path        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_am_app_launch_int(U16 *app_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = MMI_FALSE, result;
    FS_HANDLE fd = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_app_launch_int() ------- [S]");
    if (!app_path)
    {
        g_am_cntx.start_state = START_FAILURE;
        return MMI_FALSE;
    }

    if (g_am_qs_cntx.is_quick_start)
    {
        if ((S8) (*app_path) != (S8) MMI_AM_ROM_DIR)
        {
            /* check the file exists */
            if ((fd = FS_Open(app_path, FS_OPEN_NO_DIR | FS_READ_ONLY)) < FS_NO_ERROR)
            {
                /* app is not exist */
                mmi_display_popup_with_sg(
                                         GRP_ID_AM,
                                         (UI_string_type) get_string(STR_ID_AM_FILE_NOT_EXIST),
                                         MMI_EVENT_FAILURE,
                                         0);

                g_am_cntx.start_state = START_FAILURE;
                return MMI_FALSE;
            }
            FS_Close(fd);
        }
    }
    else if (!mmi_am_ms_is_rom_app_by_path(app_path))
    {
        /* check the file exists */
        if ((fd = FS_Open(app_path, FS_OPEN_NO_DIR | FS_READ_ONLY)) < FS_NO_ERROR)
        {
            /* app is not exist */
            mmi_display_popup_with_sg(
                                     GRP_ID_AM,
                                     (UI_string_type) get_string(STR_ID_AM_FILE_NOT_EXIST),
                                     MMI_EVENT_FAILURE,
                                     0);

            g_am_cntx.start_state = START_FAILURE;
            return MMI_FALSE;
        }
        FS_Close(fd);
    }
	{
		S8 path[60];
		mmi_wcs_to_asc(path, app_path);
		MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_app_launch_int() ----path: %s", path);
	}
    /*michael begin 0415*/
    result = mmi_am_vre_execute(app_path, mmi_am_launch_app_async_cb);
    /*michael end 0415*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_APP_LAUNCH_RESULT, result);
    g_am_cntx.start_state = START_FAILURE;

	MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_app_launch_int() ----ret: %d", ret);
    switch (result)
    {
    case MMI_AM_EXECUTE_APP_SUCCESS:
        /* launch AppStore from AM */
        if (!g_am_qs_cntx.is_quick_start
            && g_am_cntx.adm_pool_id
            && (g_am_ms_cntx.hl_idx == 0) && (mmi_am_config_get_am_sc_info_by_appid(APPID_VAS)))
        {
            g_am_cntx.is_launch_vas = MMI_TRUE;
        }
        g_am_cntx.start_state = START_SUCCESS;
        ret = MMI_TRUE;
        break;
    case MMI_AM_EXECUTE_APP_ILLEGAL:
        mmi_display_popup_with_sg(
                                 GRP_ID_AM,
                                 (UI_string_type) get_string(STR_ID_AM_FAIL_TO_START),
                                 MMI_EVENT_FAILURE,
                                 0);
        break;
    case MMI_AM_EXECUTE_APP_NOT_ENOUGH_MEMORY:
		/*vogins 100726 begin */
         if (!g_am_qs_cntx.is_quick_start)   /* launch app inside of AM */
            {
                g_am_cntx.start_state = START_NONE;
                mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_LOADING);
            }
            else
            {
                g_am_qs_cntx.is_not_enough_memory = MMI_TRUE;
            }
            break;
    case MMI_AM_EXECUTE_EXCEED_MAX_APP_NUM:
                    mmi_display_popup_with_sg(
                                             GRP_ID_AM,
                                             (UI_string_type) get_string(STR_ID_AM_EXCEED_MAX_APP_NUM),
                                             MMI_EVENT_FAILURE,
                                             0);
        break;
    case MMI_AM_EXECUTE_SYS_NOT_ENOUGH_MEMORY:
        mmi_display_popup_with_sg(
                                 GRP_ID_AM,
                                 (UI_string_type) get_string(STR_ID_AM_SYS_NOT_ENOUGH_MEMORY),
                                 MMI_EVENT_FAILURE,
                                 0);
        break;
        /*michael end 0415*/
    case MMI_AM_EXECUTE_APP_CALL_STACK_FULL:
        mmi_display_popup_with_sg(
                                 GRP_ID_AM,
                                 (UI_string_type) get_string(STR_ID_AM_FAIL_TO_START),
                                 MMI_EVENT_FAILURE,
                                 0);
        break;
    case MMI_AM_EXECUTE_INTERNAL_ERROR:
        mmi_display_popup_with_sg(
                                 GRP_ID_AM,
                                 (UI_string_type) get_string(STR_ID_AM_FAIL_TO_START),
                                 MMI_EVENT_FAILURE,
                                 0);
        break;
    case MMI_AM_EXECUTE_PLATFORM_PARAM_DISMATCH:
        mmi_display_popup_with_sg(
                                 GRP_ID_AM,
                                 (UI_string_type) get_string(STR_ID_AM_TAG_ERR_FAIL_TO_START),
                                 MMI_EVENT_FAILURE,
                                 0);
        break;
    case MMI_AM_EXECUTE_TIMESTAMP_ERROR:
        mmi_display_popup_with_sg(
                                 GRP_ID_AM,
                                 (UI_string_type) get_string(STR_ID_AM_DATE_ERR_FAIL_TO_START),
                                 MMI_EVENT_FAILURE,
                                 0);
        break;
    case MMI_AM_EXECUTE_BANNED_APP:
        mmi_display_popup_with_sg(
                                 GRP_ID_AM,
                                 (UI_string_type) get_string(STR_ID_AM_FAIL_TO_START),
                                 MMI_EVENT_FAILURE,
                                 0);
        break;
    case MMI_AM_EXECUTE_IMSI_DISMATCH:
        mmi_display_popup_with_sg(
                                 GRP_ID_AM,
                                 (UI_string_type) get_string(STR_ID_AM_INVALID_SIM_FAIL_TO_START),
                                 MMI_EVENT_FAILURE,
                                 0);
        break;
    case MMI_AM_EXECUTE_CERT_OVERDUE:
        mmi_display_popup_with_sg(
                                 GRP_ID_AM,
                                 (UI_string_type) get_string(STR_ID_AM_CERT_EXPIRED_FAIL_TO_START),
                                 MMI_EVENT_FAILURE,
                                 0);
        break;
    case MMI_AM_EXECUTE_EXCEED_FILE_IN_VRE_DIRECTORY:
        mmi_display_popup_with_sg(
                                 GRP_ID_AM,
                                 (UI_string_type) get_string(STR_ID_AM_FILE_OVERFLOW),
                                 MMI_EVENT_FAILURE,
                                 0);

        /* if it is not quick start, then close AM */
        if (!g_am_qs_cntx.is_quick_start)
        {
#ifdef AM_09A
            mmi_frm_group_close(GRP_ID_AM);
#else /* AM_09A */ 
            /* avoid popup disappear immediately */
            mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_LOADING);
            mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_OPTIONS);
            mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_MAIN);
#endif /* AM_09A */ 
        }
        break;
    }

    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_app_launch_int() ------- [E]");
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_is_appstore_launch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_path        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_am_is_appstore_launch(U16 *app_path)   /* check app start from filemgr or hs_shortcut */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (app_path == NULL)
    {
        return MMI_FALSE;
    }

    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_card_plug_in_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_card_plug_in_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrn_id;

#ifdef AM_09A
#ifdef __VRE_AM_08AB__
    history new_screen;
#else
    mmi_frm_screen_struct new_screen;
#endif
#else 
    mmi_frm_node_struct new_node = {0};
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
             MMI_FW_TRC_G1_FRM,
             TRC_MMI_AM_PLUG_IN_S,
             g_am_cntx.adm_pool_id,
             g_am_cntx.start_state,
             g_am_cntx.is_card_plug_out,
             g_am_search_cntx.search_state,
             g_am_qs_cntx.is_download);

    if (g_am_cntx.adm_pool_id && !g_am_qs_cntx.is_download&& !g_am_qs_cntx.is_quick_start)
    {
        /* hold vre folder handle */
        mmi_am_hold_vre_folder();

        g_am_cntx.is_card_plug_out = MMI_FALSE;
        g_am_cntx.is_card_plug_in = MMI_TRUE;

#ifdef AM_09A
        GetNextScrnIdOf(SCR_ID_AM_MAIN, &scrn_id);
#else 
        scrn_id = mmi_frm_scrn_get_neighbor_id(GRP_ID_AM, SCR_ID_AM_MAIN, MMI_FRM_NODE_AFTER_FLAG);
#endif 

        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_PLUG_IN_SCRN_ID, scrn_id);

        if (scrn_id != SCR_ID_AM_LOADING && g_am_cntx.start_state == START_NONE
            && g_am_search_cntx.search_state == SEARCH_NONE && g_am_cntx.apn_check_ret != MMI_AM_APN_INIT)
        {
            /* close loading screen firstly, ex: loading screen is loacte below of main screen */
            mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_LOADING);

            /* insert a loading screen */
#ifdef AM_09A
#ifdef __VRE_AM_08AB__
            //mmi_frm_init_screen_struct(&new_screen);
            new_screen.scrnID = SCR_ID_AM_LOADING;
            new_screen.entryFuncPtr = (FuncPtr) mmi_am_entry_loading_scrn;
            //mmi_frm_insert_screen(SCR_ID_AM_MAIN, &new_screen, MMI_FRM_INSERT_AFTER_SCRN);
            InsertHistoryAfterThisScrnReference(SCR_ID_AM_MAIN, &new_screen);

#else
            mmi_frm_init_screen_struct(&new_screen);
            new_screen.scrnID = SCR_ID_AM_LOADING;
            new_screen.entryFuncPtr = (entry_func_ptr) mmi_am_entry_loading_scrn;
            mmi_frm_insert_screen(SCR_ID_AM_MAIN, &new_screen, MMI_FRM_INSERT_AFTER_SCRN);
#endif
#else /* AM_09A */ 
            new_node.id = SCR_ID_AM_LOADING;
            new_node.entry_proc = (mmi_proc_func) mmi_am_entry_loading_scrn;
            mmi_frm_scrn_insert(GRP_ID_AM, SCR_ID_AM_MAIN, &new_node, MMI_FRM_NODE_AFTER_FLAG);
#endif /* AM_09A */ 

            /* stop scrolling text */
            mmi_am_ms_scrolling_text_stop();
        }
    }

    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_PLUG_IN_E);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_card_plug_out_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_card_plug_out_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *app_path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
             MMI_FW_TRC_G1_FRM,
             TRC_MMI_AM_PLUG_OUT_S,
             g_am_cntx.adm_pool_id,
             g_am_cntx.start_state,
             g_am_cntx.is_card_plug_in,
             g_am_ms_cntx.hl_idx,
             g_am_cntx.is_app_in_card,
             g_am_qs_cntx.is_download);

    if (g_am_cntx.adm_pool_id && !g_am_qs_cntx.is_download &&!g_am_qs_cntx.is_quick_start)
    {
        /* close vre folder file handle */
        if (g_am_cntx.card_vre_folder_hdl >= 0)
        {
            FS_Close(g_am_cntx.card_vre_folder_hdl);
            g_am_cntx.card_vre_folder_hdl = -1;
        }

        if (g_am_cntx.is_card_plug_in && g_am_cntx.start_state == START_NONE)
        {
            mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_LOADING);
        }
        g_am_cntx.is_card_plug_in = MMI_FALSE;
        g_am_cntx.is_card_plug_out = MMI_TRUE;

        app_path = mmi_am_ms_get_app_path_by_index(g_am_ms_cntx.hl_idx);

        if (app_path)
            MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_PLUG_OUT_PATH, ((S8) * app_path));

        if (app_path && (((S8) * app_path) != (S8) mmi_am_get_system_driver()) &&
            (((S8) * app_path) != (S8) MMI_AM_ROM_DIR))
        {
            MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_PLUG_OUT_IN_MEMORY_CARD);

            g_am_cntx.is_app_in_card = MMI_TRUE;

            if (g_am_cntx.start_state == START_NONE && g_am_search_cntx.search_state == SEARCH_NONE)    /* is not in the search vxp files */
            {
                mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_LOADING);
            }
            mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_OPTIONS);
            mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_DOWNLOAD_PROGRESS);
            mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_SETTINGS);
            mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_SETTINGS_SIM);
            mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_SETTINGS_CONN);
            mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_DETAILS);
/*vogins_20100716_start*/
		mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_PROCESSES_MANAGER);
		mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_PROCESSES_MANAGER_OS);
/*vogins_20100716_end*/
        }

        /* mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_LOADING); */

        /* release lists */
        /*vogins_20100716_start*/
        //mmi_am_release_shortcut_list_nodes_in_memory_card();
        mmi_am_search_shortcut_apps();
        /*vogins_20100716_end*/
        mmi_am_release_vxp_list_nodes_in_memory_card();
        /* mmi_am_release_vxp_list_all_nodes(); */
        mmi_am_ms_release_app_list_nodes_in_memory_card();

        /* search vxp files in system disk */
        /* mmi_am_search_vxp_files(); */

        /* update main screen highlight item */
        /* g_am_ms_cntx.hl_idx = 0; */
    }

    /*close memory not enough screen when plug out card 100728 begin*/
    DeleteScreenIfPresent(SCR_MEDMEM_STOP_PROMPT);
    DeleteScreenIfPresent(SCR_APPMEM_STOP_PROMPT);
    /*close memory not enough screen when plug out card 100728 end*/

    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_PLUG_OUT_E, g_am_ms_cntx.hl_idx, g_am_cntx.is_app_in_card);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_enter_usb_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_enter_usb_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_ENTER_USB_MODE_S, g_am_cntx.adm_pool_id);

    if (g_am_cntx.adm_pool_id)
    {
#if defined(__USB_IN_NORMAL_MODE__)
        if (mmi_usb_is_in_mass_storage_mode())
        {
            mmi_frm_group_close(GRP_ID_AM);
            MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_ENTER_USB_MODE_CLOSE_AM);
        }
#endif /* defined(__USB_IN_NORMAL_MODE__) */ 
    }

    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_ENTER_USB_MODE_E);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_delete_node_from_vxplist_by_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_delete_node_from_vxplist_by_index(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    mmi_am_vxp_file_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (idx < (g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num))
    {
        return;
    }
    else
    {
        index = idx - (g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num);
        p = sml_list_get(g_am_cntx.vxp_file_list, index);
        if (p)
        {
            /* delete the node */
            mmi_am_free(p);
            p = NULL;
            sml_list_remove(g_am_cntx.vxp_file_list, index);
        }
        else
        {
            MMI_AM_ASSERT(0);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_delete_node_from_vxplist_by_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_path        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_delete_node_from_vxplist_by_path(U16 *app_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cur_pos;
    mmi_am_vxp_file_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!app_path)
    {
        return;
    }

    for (cur_pos = 0; cur_pos < sml_list_size(g_am_cntx.vxp_file_list); cur_pos++)
    {
        p = sml_list_get(g_am_cntx.vxp_file_list, cur_pos);

        if (p && mmi_wcscmp(app_path, p->path) == 0)
        {
            /* delete the node */
            mmi_am_free(p);
            p = NULL;
            sml_list_remove(g_am_cntx.vxp_file_list, cur_pos);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_get_status_bar_icon_resid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_name        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_am_get_status_bar_icon_resid(U16 *app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_am_config_get_status_bar_resid(app_name);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_get_status_bar_icon_resid_by_appid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_am_get_status_bar_icon_resid_by_appid(U32 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_am_config_get_status_bar_resid_by_appid(app_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_app_update
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_id          [IN]        
 *  app_name        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_am_app_update(U32 app_id, U16 *app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_app_update() ------- [S]");

    /* Check before AM start */
    if (!mmi_am_pre_start_check())
    {
        return MMI_FALSE;
    }

    /* set app_id and app_name */
    mmi_am_dl_set_appid(app_id);
    mmi_am_dl_set_app_name(app_name);

    g_am_cntx.is_app_update = MMI_TRUE;

    /* enter screen group */
    mmi_frm_group_enter_ex(GRP_ID_ROOT, GRP_ID_AM, mmi_am_grp_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    /* show network connection message */
    mmi_display_popup_confirm_with_sg(
                                     GRP_ID_AM,
                                     NULL,
                                     NULL,
#ifdef __VRE_AM_08AB__
                                     STR_GLOBAL_CANCEL,
                                     IMG_GLOBAL_BACK,
#else
                                     get_string(STR_GLOBAL_CANCEL),
                                     get_image(IMG_GLOBAL_BACK),
#endif
                                     get_string(STR_GLOBAL_PLEASE_WAIT),
                                     MMI_EVENT_PROGRESS,
                                     0);

    /* initialize */
    mmi_am_dl_init();

    /* register memory api */
    mmi_am_vre_pre_download_app(mmi_am_calloc, mmi_am_free);

    /* AM init */
    if (g_am_cntx.adm_pool_id == NULL)
    {
        if (!mmi_am_start_int())
        {
            mmi_frm_group_close(GRP_ID_AM);
            g_am_cntx.is_app_update = MMI_FALSE;
            return MMI_FALSE;
        }
    }

    /* do some check before download */
    if (!mmi_am_download_pre_check())
    {
        mmi_frm_group_close(GRP_ID_AM);
        g_am_cntx.is_app_update = MMI_FALSE;
        return MMI_FALSE;
    }

    ret = mmi_am_vre_download_app(mmi_am_download_app_cb, (U32) app_id, (PU16) app_name, MMI_AM_DOWNLOAD_BLOCK_SIZE);
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_app_update() -- ret:%d;dl_app_id:%d", ret, app_id);

    if (ret == MMI_AM_DL_OK)
    {
        mmi_am_dl_set_appid(app_id);
        mmi_am_dl_set_app_name(app_name);
    }
    else
    {
        mmi_display_popup_with_sg(
                                 GRP_ID_AM,
                                 (UI_string_type) get_string(STR_ID_AM_CONNCT_FAILURE),
                                 MMI_EVENT_FAILURE,
                                 0);

        mmi_frm_group_close(GRP_ID_AM);
        g_am_cntx.is_app_update = MMI_FALSE;

        return MMI_FALSE;
    }

    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_app_update() ------- [E]");
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_check_downloaded_app_by_as
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_am_check_downloaded_app_by_as(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 file_drv;
    FS_HANDLE fd = -1, app_fd = -1;
    FS_HANDLE fs_result;
    S8 dl_app_list_path[30];
    U16 dl_app_list_path_w[30];
    U16 app_path_w[MMI_AM_MAX_APP_FILE_PATH];   /* downloaded app file path */
    S32 i, num_of_list;
    U32 read_size;
    U32 app_path_len;
    FS_FileInfo info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_CHECK_DL_BY_AS_S, g_am_cntx.is_card_plug_in);
    memset(dl_app_list_path, 0, sizeof(dl_app_list_path));
    memset(dl_app_list_path_w, 0, sizeof(dl_app_list_path_w));

    /* search list */
    if (g_am_cntx.is_card_plug_in)
    {
        /* search memory card firstly */
        file_drv = mmi_am_get_removeable_driver();
        sprintf(dl_app_list_path, "%c:\\%s\\%s", file_drv, MMI_AM_VRE_HOME_DIR, MMI_AM_DOWNLOAD_LIST);
        mmi_asc_to_wcs(dl_app_list_path_w, (PS8) dl_app_list_path);
        if ((fd = FS_Open(dl_app_list_path_w, FS_OPEN_NO_DIR | FS_READ_ONLY)) < FS_NO_ERROR)
        {
            MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_CHECK_DL_BY_AS_PLUG_IN_1);

            /* search phone */
            memset(dl_app_list_path, 0, sizeof(dl_app_list_path));
            memset(dl_app_list_path_w, 0, sizeof(dl_app_list_path_w));
            file_drv = mmi_am_get_system_driver();
            sprintf(dl_app_list_path, "%c:\\%s\\%s", file_drv, MMI_AM_VRE_HOME_DIR, MMI_AM_DOWNLOAD_LIST);
            mmi_asc_to_wcs(dl_app_list_path_w, (PS8) dl_app_list_path);
            if ((fd = FS_Open(dl_app_list_path_w, FS_OPEN_NO_DIR | FS_READ_ONLY)) < FS_NO_ERROR)
            {
                MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_CHECK_DL_BY_AS_PLUG_IN_2);

                return MMI_FALSE;
            }
        }
    }
    else
    {
        file_drv = mmi_am_get_home_driver();
        sprintf(dl_app_list_path, "%c:\\%s\\%s", file_drv, MMI_AM_VRE_HOME_DIR, MMI_AM_DOWNLOAD_LIST);
        mmi_asc_to_wcs(dl_app_list_path_w, (PS8) dl_app_list_path);
        if ((fd = FS_Open(dl_app_list_path_w, FS_OPEN_NO_DIR | FS_READ_ONLY)) < FS_NO_ERROR)
        {
            MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_CHECK_DL_BY_AS_E1);
            /* list does not exist */
            return MMI_FALSE;
        }
    }

    /* Read app list to vxp_list */
    if ((fs_result = FS_Read(fd, &num_of_list, 4, &read_size)) == FS_NO_ERROR && read_size == 4)
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_CHECK_DL_BY_AS_LIST_NUM, num_of_list);
        for (i = 0; i < num_of_list; i++)
        {
            app_path_len = 0;
            read_size = 0;
            memset(app_path_w, 0, sizeof(app_path_w));
            memset(&info, 0, sizeof(info));
            if ((fs_result = FS_Read(fd, &app_path_len, 4, &read_size)) == FS_NO_ERROR && read_size == 4)
            {
                if ((fs_result = FS_Read(fd, &app_path_w, app_path_len << 1, &read_size)) == FS_NO_ERROR &&
                    read_size == (app_path_len << 1))
                {
                    /* check if the app_path has been in vxp_list, if exist, then delet it */
                    mmi_am_delete_node_from_vxplist_by_path(app_path_w);

                    /* open the downloaded app file */
                    if ((app_fd = FS_Open(app_path_w, FS_OPEN_NO_DIR | FS_READ_ONLY)) < FS_NO_ERROR)
                    {
                        break;
                    }
                    /* get file info */
                    if (FS_GetFileInfo(app_fd, &info) < 0)
                    {
                        FS_Close(app_fd);
                        break;
                    }

                    g_am_search_cntx.cur_driver = (S8) (*app_path_w);
                    if (!mmi_am_add_vxp_file_list(app_path_w + MMI_AM_VRE_FOLDER_SIZE, info.DirEntry->DateTime))
                    {
                        /* close app file */
                        FS_Close(app_fd);
                        break;
                    }

                    /* close app file */
                    FS_Close(app_fd);
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }

    /* delete the file */
    FS_Close(fd);
    FS_Delete(dl_app_list_path_w);
    g_am_search_cntx.cur_driver = mmi_am_get_home_driver();

    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_CHECK_DL_BY_AS_E2);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_is_too_many_files_in_vre_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_am_is_too_many_files_in_vre_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 vre_folder[8];
    U16 vre_folder_w[8];
    S32 vxp_num, temp_vxp_num;
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_is_too_many_files_in_vre_folder() ------- [S]");
    memset(vre_folder, 0, sizeof(vre_folder));
    memset(vre_folder_w, 0, sizeof(vre_folder_w));
    vxp_num = 0;
    temp_vxp_num = 0;

    if (mmi_am_get_removeable_driver())
    {
        sprintf(vre_folder, "%c:\\%s", (S8) mmi_am_get_removeable_driver(), MMI_AM_VRE_HOME_DIR);
        mmi_asc_to_wcs((PU16) vre_folder_w, (PS8) vre_folder);
        vxp_num = FS_Count((WCHAR*) vre_folder_w, FS_FILE_TYPE | FS_DIR_TYPE, NULL, 0);
    }

    /* if vre folder does not exist, then vxp_num will be less than 0 */
    if (vxp_num < 0)
    {
        vxp_num = 0;
    }

    if (mmi_am_get_system_driver())
    {
        memset(vre_folder, 0, sizeof(vre_folder));
        memset(vre_folder_w, 0, sizeof(vre_folder_w));
        sprintf(vre_folder, "%c:\\%s", (S8) mmi_am_get_system_driver(), MMI_AM_VRE_HOME_DIR);
        mmi_asc_to_wcs((PU16) vre_folder_w, (PS8) vre_folder);
        temp_vxp_num = FS_Count((WCHAR*) vre_folder_w, FS_FILE_TYPE | FS_DIR_TYPE, NULL, 0);
    }

    /* if vre folder does not exist, then vxp_num will be less than 0 */
    if (temp_vxp_num < 0)
    {
        temp_vxp_num = 0;
    }

    vxp_num = vxp_num + temp_vxp_num;

    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_CHECK_FILE_NUMBER, vxp_num);
    if (vxp_num > MMI_AM_VXP_MAX_FILE_NUM)
    {
        ret = MMI_TRUE;
    }

    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_is_too_many_files_in_vre_folder() ------- [E]");
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_is_using_media_memory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  VRE is using media memory or not
 *****************************************************************************/
S32 mmi_am_is_using_media_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_vre_is_using_media_memory();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_am_media_memory_unavailable_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_media_memory_unavailable_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_display_popup((UI_string_type)GetString(STR_ID_AM_MEDIA_MEMORY_UNAVAIBLE), MMI_EVENT_FAILURE);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_am_error_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  VRE running string id
 *****************************************************************************/
U16 mmi_am_get_error_info(S32 error_result, S32* popup_type)
{
    if (error_result == MMI_VRE_ERR_IS_UNAVAILABLE)
    {
        return STR_ID_AM_MEDIA_MEMORY_UNAVAIBLE;
    }
    else
    {
        return 0;
    }
}
/*michael 100415 begin*/
MMI_BOOL mmi_am_get_running_appinfo(vm_running_app_info_t *app_info, U16 app_num)
{
    U16 i = 0;
    mmi_am_vxp_file_struct vxp_s;
    mmi_am_ms_app_struct *appinfo_p;
    if (g_run_app_list == NULL)
    {
        g_run_app_list = sml_list_new();
    }
    for (i = 0; i < app_num; i++)
    {
        /* set app full path */
        memset(vxp_s.path, 0, MMI_AM_MAX_APP_FILE_PATH);
        mmi_wcscpy(vxp_s.path, (U16*)app_info[i].app_filename);

        appinfo_p = mmi_am_ms_get_runing_appinfo_from_vxplist(&vxp_s);
        if (appinfo_p)
        {
            /* set app full path */
            mmi_wcscpy(appinfo_p->path, (U16*)app_info[i].app_filename);
            /*set app background memory size*/
            appinfo_p->bg_memory_size = app_info[i].alloc_mem;
            sml_list_add(g_run_app_list, appinfo_p, -1);
        }
        else
        {
            return MMI_FALSE;
        }
    }
    return MMI_TRUE;

} 
static void mmi_am_release_app_running_infos(vm_running_app_info_t *app_info)
{
    if (app_info !=NULL)
    {
        vm_release_app_running_infos(app_info);
        app_info =NULL;
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_release_run_app_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_ms_release_run_app_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (g_run_app_list)
    {
    	mmi_am_ms_release_run_app_list_all_nodes();
        sml_list_free(g_run_app_list);
        g_run_app_list = NULL;
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_am_ms_release_run_app_list_all_nodes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_ms_release_run_app_list_all_nodes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_run_app_list)
    {
        while (sml_list_size(g_run_app_list))
        {
            mmi_am_ms_app_struct *p = sml_list_get(g_run_app_list, 0);
            mmi_am_ms_release_run_applist_node(p);
            sml_list_remove(g_run_app_list, 0);
        }
    }
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
static void mmi_am_ms_release_run_applist_node(mmi_am_ms_app_struct *p_node)
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
 *  mmi_am_ms_get_runing_appinfo_from_vxplist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p_node      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
/*michael 100415 begin*/
mmi_am_ms_app_struct *mmi_am_ms_get_runing_appinfo_from_vxplist(mmi_am_vxp_file_struct *vxp_p)
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

    app_p = mmi_am_calloc(sizeof(mmi_am_ms_app_struct));
    if (!app_p)
    {
        MMI_AM_ASSERT(app_p != NULL);
        //mmi_am_free(cache_buf);
        return NULL;
    }
    /* set app full path */
    mmi_wcscpy(app_p->path, vxp_p->path);
    
    /* get app name */
    ret = mmi_am_get_runing_app_name(app_p->path, NULL, (void **)&app_p->p_name, &app_p->name_len);
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "name_len:%d", app_p->name_len);
    //MMI_AM_ASSERT(app_p->p_name != NULL);
    if (!ret)
    {
        mmi_am_ms_release_run_applist_node(app_p);
        return NULL;
    }
    return app_p;
}
void mmi_am_free_app_running_infos(void)
{
    mmi_am_ms_release_run_app_list();
}
/*Michael 100415 end*/

//wei.xia add by 0624 for vre version information
    #define MAX_STRING_BUF 80
S8 UnicodeDisBuf[MAX_STRING_BUF * 5];
void mmi_am_show_vre_information(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 tempbuf[MAX_STRING_BUF * 2];
    U8 AsciiDisplayBuf[MAX_STRING_BUF];
    int memery_size;

    S16 ErrorCode, Ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_AM_LOADING, NULL, mmi_am_show_vre_information, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_AM_LOADING);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    memset(UnicodeDisBuf, 0, sizeof(UnicodeDisBuf));
    memset(AsciiDisplayBuf, 0, sizeof(AsciiDisplayBuf));
    mmi_asc_to_ucs2((S8*) AsciiDisplayBuf, "[VRE VERSION]:");
    mmi_ucs2cpy((S8*) UnicodeDisBuf, (const S8*)AsciiDisplayBuf);

    memset(AsciiDisplayBuf, 0, sizeof(AsciiDisplayBuf));
    sprintf((S8*) AsciiDisplayBuf, "\n%s\n", (S8*) VRE_SYS_VRESION_NUMBER);
    memset(tempbuf, 0, sizeof(tempbuf));
    mmi_asc_to_ucs2((S8*) tempbuf, (S8*) AsciiDisplayBuf);
    mmi_ucs2cat((S8*) UnicodeDisBuf, (const S8*)tempbuf);

    //show am version
    memset(AsciiDisplayBuf, 0, sizeof(AsciiDisplayBuf));
    mmi_asc_to_ucs2((S8*) AsciiDisplayBuf, "[AM VERSION]:");
    mmi_ucs2cat((S8*) UnicodeDisBuf, (const S8*)AsciiDisplayBuf);

    memset(AsciiDisplayBuf, 0, sizeof(AsciiDisplayBuf));
#ifdef MMI_AM_VERSION
    sprintf((S8*) AsciiDisplayBuf, "\n%s\n", (S8*) MMI_AM_VERSION);
#else
    sprintf((S8*) AsciiDisplayBuf, "\nNULL\n");
#endif
    memset(tempbuf, 0, sizeof(tempbuf));
    mmi_asc_to_ucs2((S8*) tempbuf, (S8*) AsciiDisplayBuf);
    mmi_ucs2cat((S8*) UnicodeDisBuf, (const S8*)tempbuf);

    //show vre memery type
    memset(AsciiDisplayBuf, 0, sizeof(AsciiDisplayBuf));
    mmi_asc_to_ucs2((S8*) AsciiDisplayBuf, "[MEM TYPE]:");
    mmi_ucs2cat((S8*) UnicodeDisBuf, (const S8*)AsciiDisplayBuf);

    memset(AsciiDisplayBuf, 0, sizeof(AsciiDisplayBuf));
#ifdef VRE_SUPPORT_ASM_MEMPOOL
    sprintf((S8*) AsciiDisplayBuf, "\nASM\n");
#else
    sprintf((S8*) AsciiDisplayBuf, "\nMEDIA BUFFER\n");
#endif
    memset(tempbuf, 0, sizeof(tempbuf));
    mmi_asc_to_ucs2((S8*) tempbuf, (S8*) AsciiDisplayBuf);
    mmi_ucs2cat((S8*) UnicodeDisBuf, (const S8*)tempbuf);   

    //show vre memery size
    memery_size = VRE_SYS_MEMPOOL_SIZE / 1024;
    memset(AsciiDisplayBuf, 0, sizeof(AsciiDisplayBuf));
    sprintf((S8*) AsciiDisplayBuf, "[MEM SIZE]: \n");
    memset(tempbuf, 0, sizeof(tempbuf));
    mmi_asc_to_ucs2((S8*) tempbuf, (S8*) AsciiDisplayBuf);
    mmi_ucs2cat((S8*) UnicodeDisBuf, (const S8*)tempbuf);

    memset(AsciiDisplayBuf, 0, sizeof(AsciiDisplayBuf));
    sprintf((S8*) AsciiDisplayBuf, "%dK\n", (S8*) memery_size);
    memset(tempbuf, 0, sizeof(tempbuf));
    mmi_asc_to_ucs2((S8*) tempbuf, (S8*) AsciiDisplayBuf);
    mmi_ucs2cat((S8*) UnicodeDisBuf, (const S8*)tempbuf);   

    //show build time
    memset(AsciiDisplayBuf, 0, sizeof(AsciiDisplayBuf));
    sprintf((S8*) AsciiDisplayBuf, "[BUILD TIME] \n");
    memset(tempbuf, 0, sizeof(tempbuf));
    mmi_asc_to_ucs2((S8*) tempbuf, (S8*) AsciiDisplayBuf);
    mmi_ucs2cat((S8*) UnicodeDisBuf, (const S8*)tempbuf);

    memset(AsciiDisplayBuf, 0, sizeof(AsciiDisplayBuf));
    sprintf((S8*) AsciiDisplayBuf, "%s\n", (S8*) build_date_time());
    memset(tempbuf, 0, sizeof(tempbuf));
    mmi_asc_to_ucs2((S8*) tempbuf, (S8*) AsciiDisplayBuf);
    mmi_ucs2cat((S8*) UnicodeDisBuf, (const S8*)tempbuf);

    ShowCategory74Screen(
                        STR_ID_INFORMATION,
                        0,
                        (U16) NULL,
                        0,
                        STR_GLOBAL_BACK,
                        0,
                        (PU8) UnicodeDisBuf,
                        sizeof(UnicodeDisBuf),
                        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
//add end

MMI_BOOL mmi_am_check_is_quick_start(void)
{
    return IsQuickStart;
}
#endif /* __VRE30_AM__ */ 

