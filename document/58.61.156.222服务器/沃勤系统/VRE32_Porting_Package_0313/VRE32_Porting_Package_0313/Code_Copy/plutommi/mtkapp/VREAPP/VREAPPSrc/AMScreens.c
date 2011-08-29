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
#ifdef __VRE30_AM__

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   AMScreens.c
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   AM Other Screens in addition to Main Screen.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Include header files
*****************************************************************************/
    #ifdef __VRE_AM_08AB__
        #include "MMI_include.h"
    #else
        #include "MMI_frm_gprot.h"
    #endif
    #include "CommonScreens.h"
    #include "CustMenuRes.h"
    #include "Conversions.h"
    #ifdef __VRE_AM_08AB__
        #include "SettingProfile.h"
        #include "wgui_touch_screen.h"
        #include "wgui_categories_popup.h"
    #endif
/*Vogins_20100625_start*/
    #include "MainMenuDef.h"
/*Vogins_20100625_end*/

    #include "AMResDef.h"   /* Add AM head file */
    #include "AMDef.h"      /* Add AM head file */
    #include "AMGprot.h"    /* Add AM head file */
    #include "AMprot.h"     /* Add AM head file */
    #include "AMUtil.h"
    #include "AMShortcut.h"
    #include "AMMainScreen.h"
    #include "AMScreens.h"

/*****************************************************************************/
/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/
/* vogins 20100629 begin*/
    #define MMI_AM_MAX_APN_LEN  31
    #define MMI_AM_MAX_USER_LEN  15
    #define MMI_AM_MAX_PASSWD_LEN 15
    #define MMI_AM_MAX_IPADDRES_LEN 4
typedef enum
{
    AM_DATA_ACCOUNT_USE_PROXY_STR = 0,
    AM_DATA_ACCOUNT_USE_PROXY,    
    AM_DATA_ACCOUNT_APN_STR ,//= 0,
    AM_DATA_ACCOUNT_APN,
    AM_DATA_ACCOUNT_USER_NAME_STR,
    AM_DATA_ACCOUNT_USER_NAME,
    AM_DATA_ACCOUNT_PASSWD_STR,
    AM_DATA_ACCOUNT_PASSWD,
    //AM_DATA_ACCOUNT_USE_PROXY_STR,
    //AM_DATA_ACCOUNT_USE_PROXY,
    AM_DATA_ACCOUNT_IP_ADDRESS_STR,
    AM_DATA_ACCOUNT_IP_ADDRESS,
    AM_DATA_ACCOUNT_PORT_STR,
    AM_DATA_ACCOUNT_PORT,
    MAX_INLINE_ITEM_AM_DATA_ACCOUNT_LIST
} AM_DATA_ACCOUNT_INLINE;

typedef struct mmi_am_data_account_node_struct
{
    U8 APN[(MMI_AM_MAX_APN_LEN + 1) *ENCODING_LENGTH];
    U8 UserName[(MMI_AM_MAX_USER_LEN + 1) *ENCODING_LENGTH]; 
    U8 Passwd[(MMI_AM_MAX_PASSWD_LEN + 1) *ENCODING_LENGTH];
    U8 IsChangeProxy;
    S32 use_proxy;
    U8 *use_proxy_option_str[2];
    U8 GPRSIP1[MMI_AM_MAX_IPADDRES_LEN *ENCODING_LENGTH];
    U8 GPRSIP2[MMI_AM_MAX_IPADDRES_LEN *ENCODING_LENGTH];
    U8 GPRSIP3[MMI_AM_MAX_IPADDRES_LEN *ENCODING_LENGTH];
    U8 GPRSIP4[MMI_AM_MAX_IPADDRES_LEN *ENCODING_LENGTH];
    U8 proxy_port[(5 + 1) *ENCODING_LENGTH];
    U16 IconList[MAX_INLINE_ITEM_AM_DATA_ACCOUNT_LIST];
} mmi_am_data_account_node;

/* global variables */
static mmi_am_data_account_node g_mmi_am_display_dtcnt;
mmi_am_apn_info g_mmi_am_apn_info;
/*vogins 20100629 end*/
static U8 *g_ds_str_buf;
static mmi_am_download_cntx_struct g_am_dl_cntx;
extern mmi_am_ms_struct g_am_ms_cntx;
extern mmi_am_cntx_struct g_am_cntx;
extern mmi_am_quick_start_struct g_am_qs_cntx;
/*Vogins_20100625_start*/
extern U16 num_app_move;

extern am_prompt_struct is_prompt_rule_cdr;
/*Vogins_20100625_end*/
/*vogins_20100712_start*/
sml_list_t *g_run_app_list;
static S32 g_am_pro_mngr_highlight;
extern mmi_am_relaunch_struct g_am_relaunch_cntx;
/*vogins_20100712_end*/
/*vogins_20100726_start*/
mmi_am_dl_filesize_cntx_struct g_am_filesize_cntx;
mmi_am_check_dll_cntx_struct g_am_check_dll_cntx;
mmi_am_downlaod_list_cntx g_am_download_list_cntx;
/*vogins_20100726_end*/
/***************************************************************************** 
* Local Function
*****************************************************************************/
/* options screen */
static void mmi_am_eixt_option_scrn(void);
static void mmi_am_os_get_list(U16 *list, U16 *list_num);
static void mmi_am_os_highlight_hdlr(S32 idx);
static void mmi_am_os_lsk_hdlr(void);
/*Vogins_20100625_start*/
//static void mmi_am_os_download_accept(void);
/*Vogins_20100625_end*/
    #if defined (__MMI_VUI_HOMESCREEN__)
static void mmi_am_os_create_hs_shortcut(void);
static void mmi_am_os_delete_hs_shortcut(void);
static void mmi_am_os_delete_hs_shortcut_accept(void);
    #endif /* defined (__MMI_VUI_HOMESCREEN__) */ 
static void mmi_am_os_app_details(void);
static void mmi_am_os_app_delete(void);
static void mmi_am_os_app_delete_accept(void);
static void mmi_am_os_app_resume(void);

/* details screen */
static void mmi_am_entry_details_scrn(void);
static void mmi_am_eixt_details_scrn(void);

    #ifdef AM_09A
static U8 mmi_am_destroy_details_scrn(void *param);
    #else 
static mmi_ret mmi_am_leave_details_scrn(mmi_event_struct *evt);
    #endif 
static void mmi_am_ds_prepare_data(U8 **str_buf, S32 *buf_size);

/* settings screen */
static void mmi_am_entry_settings_scrn(void);
static void mmi_am_eixt_settings_scrn(void);
static void mmi_am_ss_get_list(U16 *list, U16 *list_num);
static void mmi_am_ss_highlight_hdlr(S32 index);
static void mmi_am_ss_lsk_hdlr(void);

/* sim settings screen */
static void mmi_am_entry_sim_settings_scrn(void);
static void mmi_am_eixt_sim_settings_scrn(void);
static void mmi_am_sss_highlight_hdlr(S32 index);
static void mmi_am_sss_lsk_hdlr(void);
static void mmi_am_sss_set_sim1(void);
static void mmi_am_sss_set_sim2(void);

/* connection settings screen */
static void mmi_am_entry_conn_settings_scrn(void);
static void mmi_am_eixt_conn_settings_scrn(void);
static void mmi_am_css_highlight_hdlr(S32 index);
static void mmi_am_css_lsk_hdlr(void);
static void mmi_am_css_set_gprs(void);
static void mmi_am_css_set_wifi(void);

/* downloading screen */
static void mmi_am_entry_downloading_scrn(void);
static void mmi_am_exit_downloading_scrn(void);

    #ifdef AM_09A
static U8 mmi_am_destroy_downloading_scrn(void *param);
    #else 
static mmi_ret mmi_am_leave_downloading_scrn(mmi_event_struct *evt);
    #endif 
static void mmi_am_dl_cancel(void);
static void mmi_am_download_app_done(void);
static void mmi_am_download_app_done_accept(void);
static void mmi_am_download_app_done_goback(void);
static void mmi_am_download_as_post_operation(void);

/* Update VRE CDR */
static void mmi_am_exit_update_cdr_scrn(void);
/*Vogins_20100625_start*/
//static void mmi_am_cdr_update_accept(void);
/*Vogins_20100625_end*/
static void mmi_am_entry_update_cdr_wait_scrn(void);
static void mmi_am_exit_update_cdr_wait_scrn(void);
static void mmi_am_cdr_update_cb(S32 nResult);

/* Download application from main menu */
static void mmi_am_download_from_mm_entry_confirm_scrn(void);
static void mmi_am_download_from_mm_exit_confirm_scrn(void);
static void mmi_am_download_app_from_mm_done_accept(void);
static void mmi_am_download_app_from_mm_done_close(void);
    #ifdef AM_09A
static U8 mmi_am_del_download_from_mm_scrn(void *param);
    #else
static mmi_ret mmi_am_leave_download_from_mm_scrn(mmi_event_struct *evt);
    #endif
/* vogins 20100629 begin*/
static void mmi_am_entry_dataaccount_screen(void);
static void mmi_am_entry_dataaccount_edit(void);
static void mmi_am_editor_highlight_hdlr(S32 nIndex);
static void mmi_am_data_account_fillInline_struct(void);
static void mmi_am_data_account_fullline_edit_screen(void);
static void mmi_am_prepared_IPAddress_string(U8 *string_buffer, U8 *IP1, U8 *IP2, U8 *IP3, U8 *IP4);
static void mmi_am_return_three_digit_string(PU8 StringVal, U8 DigitVal);
static U8 mmi_am_VerifyDataAcountChanges(void);
static void mmi_am_save_dcnt_changes(void);
static void mmi_goto_am_main_screen(void);
static void mmi_am_entry_save(void);
    #ifdef AM_09A
static U8 mmi_am_destroy_dcnt_scrn(void *param);
    #else 
static mmi_ret mmi_am_leave_dcnt_scrn(mmi_event_struct *evt);
    #endif
static void mmi_am_process_save_handle(void);
/* vogins 20100629 end*/

/*vogins_20100712_start*/
static void mmi_am_exit_processes_manager_scrn(void);
static void mmi_am_back_processes_manager_scrn(void);
static void mmi_am_processes_manager_os_resume(void);
static void mmi_am_processes_manager_os_stop(void);
static void mmi_am_processes_manager_os_stop_confrm();
static void mmi_am_processes_manager_os_highlight_hdlr(S32 index);
static void mmi_am_processes_manager_os_lsk_hdlr();
static void mmi_am_entry_processes_manager_os_screen(void);
static void mmi_am_processes_manager_screen_os_highlighted(void);
static void mmi_am_processes_manager_screen_highlight_hdlr(S32 item_index);
static pBOOL mmi_am_processes_mngr_screen_get_item(
                S32 item_index, 
                UI_string_type str_buff, 
                PU8 *img_buff_p, 
                U8 str_img_mask);
static void mmi_am_processes_mngr_screen_hide_info(void);
    #ifdef AM_09A
static U8 mmi_am_destroy_processes_manager_scrn(void *param);
    #else 
static mmi_ret mmi_am_leave_processes_manager_scrn(mmi_event_struct *evt);
    #endif
/*vogins_20100712_end*/
static void mmi_am_entry_dataaccount_opt_scrn(void);
static void mmi_am_dcnt_lsk_hdlr(void);
static void mmi_am_dcnt_highlight_hdlr(S32 index);
static void mmi_am_dcnt_get_list(U16 *list, U16 *list_num);
static void mmi_am_eixt_dataaccount_opt_scrn(void);
static void mmi_am_dcnt_delete_query(void);
static void mmi_am_delete_apn_from_nvram(void);
/*vogins_20100726_start*/
static void mmi_am_download_size_limit(void);
static VMINT mmi_am_get_dl_app_id_and_name(U32* dl_id, U16* file_name);
static void mmi_am_vre_start_download(void);
static void mmi_am_check_file_size_cb(VMINT nResult, VMUINT8 * pData, VMINT nDataLen);
static void mmi_am_check_appstore(void);
static void mmi_am_add_download_list(U8* pData, VMINT pDataLen);
static void mmi_am_check_dll_version_cb(VMINT nResult, VMUINT8 * pData, VMINT nDataLen);
static VMINT mmi_am_check_dll_parse(VMUINT8* pData, VMINT nDataLen);
static VMINT mmi_am_file_size_parse(VMUINT8* pData, VMINT nDataLen);
static void mmi_am_entry_downloading_wait_scrn(void);
static void mmi_am_exit_downloading_wait_scrn(void);
/*vogins_20100726_end*/
#ifdef AM_DOWNLOAD_CONFIRM
void mmi_am_dl_cancel_screen(void);
#endif
/***************************************************************************** 
* Extern Function
*****************************************************************************/
extern U8 PhnsetGetDefEncodingType(void);
extern void mmi_am_ms_update_cdr(void); //0714
extern void mmi_am_ms_release_run_app_list(void);
/*vogins_20100726_start*/
extern void mmi_am_release_download();
/*vogins_20100726_end*/
/*****************************************************************************
 * FUNCTION
 *  mmi_am_entry_option_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_entry_option_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    U8 *gui_buffer;
    U16 nitems;
/*vogins_20100712_start*/
    U16 itemlist[7];
/*vogins_20100712_end*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_frm_scrn_enter(GRP_ID_AM, SCR_ID_AM_OPTIONS, mmi_am_eixt_option_scrn, mmi_am_entry_option_scrn, NULL);

    if (ret == MMI_FALSE)
    {
        return;
    }

    mmi_am_ms_scrolling_text_stop();

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    /* regenerate list */
    mmi_am_os_get_list(itemlist, &nitems);
    RegisterHighlightHandler(mmi_am_os_highlight_hdlr);

    ShowCategory15Screen(STR_GLOBAL_OPTIONS,
#ifdef __MMI_FTE_SUPPORT__
                         0,
#else 
                         IMG_ID_AM_TITLE,
#endif 
                         STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, nitems, itemlist, (PU16) gIndexIconsImageList, LIST_MENU, 0,   /* default highlight item */
                         gui_buffer);

    SetLeftSoftkeyFunction(mmi_am_os_lsk_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_eixt_option_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_eixt_option_scrn(void)
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
 *  mmi_am_os_get_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  list            [IN]        
 *  list_num        [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_os_get_list(U16 *list, U16 *list_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    U16 item_num = 0;
    S32 idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = g_am_ms_cntx.hl_idx;
/*Vogins_20100625_start*/
    idx = mmi_am_ms_get_actual_index(index);
/*Vogins_20100625_end*/
    if (idx < g_am_cntx.shortcut_app_num)
    {
        if (!mmi_am_ms_is_app_download(index))
        {
            list[item_num++] = STR_GLOBAL_DOWNLOAD;
            if ((mmi_am_get_sim_card_num() == 2) || ((mmi_am_get_sim_card_num() == 1) && mmi_am_is_support_wifi()))
            {
                list[item_num++] = STR_GLOBAL_SETTINGS;
            }
            if (mmi_bootup_is_network_service_available() && !mmi_bootup_get_active_flight_mode() )
            {
                list[item_num++] = STR_ID_AM_OPTION_DATA_ACCOUNT; //michael 0625
            }
/*vogins_20100712_start*/
             list[item_num++] = STR_ID_AM_PROCESSES_MANAGER;
/*vogins_20100712_end*/
            *list_num = item_num;
            return;
        }
    }

    if (mmi_am_ms_is_app_bg_running(index))
    {
        list[item_num++] = STR_GLOBAL_OPEN; /* STR_GLOBAL_RESUME; */
    }
    else
    {
        list[item_num++] = STR_GLOBAL_OPEN; /* STR_ID_AM_OPTION_LAUNCH; */
    }

#ifdef __MMI_VUI_HOMESCREEN__
    if (mmi_am_is_shortcut_support())
    {
        if (mmi_am_ms_is_app_set_hs_shortcut(index))
        {
            list[item_num++] = STR_ID_AM_OPTION_DELETE_SHORTCUT;
        }
        else
        {
            list[item_num++] = STR_ID_AM_OPTION_CREATE_SHORTCUT;
        }
    }
#endif /* __MMI_VUI_HOMESCREEN__ */ 

    list[item_num++] = STR_GLOBAL_DETAILS;

    if (idx >= (g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num))
    {
        list[item_num++] = STR_GLOBAL_DELETE;
    }

    if ((mmi_am_get_sim_card_num() == 2) || ((mmi_am_get_sim_card_num() == 1) && mmi_am_is_support_wifi()))
    {
        list[item_num++] = STR_GLOBAL_SETTINGS;
    }
    if (mmi_bootup_is_network_service_available() && !mmi_bootup_get_active_flight_mode() )
    {
        list[item_num++] = STR_ID_AM_OPTION_DATA_ACCOUNT; //michael 0625
    }
/*vogins_20100712_start*/
     list[item_num++] = STR_ID_AM_PROCESSES_MANAGER;
/*vogins_20100712_end*/
    *list_num = item_num;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_os_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_os_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type item_text;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item_text = get_item_text(index);

    if (mmi_wcscmp((U16*) item_text, (U16*) GetString(STR_GLOBAL_DOWNLOAD)) == 0)
    {
        SetLeftSoftkeyFunction(mmi_am_os_download, KEY_EVENT_UP);
        SetKeyHandler(mmi_am_os_download, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#ifdef __MMI_TOUCH_SCREEN__
        wgui_register_list_item_selected_callback(mmi_am_os_download);
#endif 
    }
    else if (mmi_wcscmp((U16*) item_text, (U16*) GetString(STR_GLOBAL_SETTINGS)) == 0)
    {
        SetLeftSoftkeyFunction(mmi_am_entry_settings_scrn, KEY_EVENT_UP);
        SetKeyHandler(mmi_am_entry_settings_scrn, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#ifdef __MMI_TOUCH_SCREEN__
        wgui_register_list_item_selected_callback(mmi_am_entry_settings_scrn);
#endif 
    }
    else if (mmi_wcscmp((U16*) item_text, (U16*) GetString(STR_GLOBAL_OPEN)) == 0)
    {
        SetLeftSoftkeyFunction(mmi_am_os_app_launch, KEY_EVENT_UP);
        SetKeyHandler(mmi_am_os_app_launch, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#ifdef __MMI_TOUCH_SCREEN__
        wgui_register_list_item_selected_callback(mmi_am_os_app_launch);
#endif 
    }
#if defined (__MMI_VUI_HOMESCREEN__)
    else if (mmi_wcscmp((U16*) item_text, (U16*) GetString(STR_ID_AM_OPTION_CREATE_SHORTCUT)) == 0)
    {
        SetLeftSoftkeyFunction(mmi_am_os_create_hs_shortcut, KEY_EVENT_UP);
        SetKeyHandler(mmi_am_os_create_hs_shortcut, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#ifdef __MMI_TOUCH_SCREEN__
        wgui_register_list_item_selected_callback(mmi_am_os_create_hs_shortcut);
#endif 
    }
    else if (mmi_wcscmp((U16*) item_text, (U16*) GetString(STR_ID_AM_OPTION_DELETE_SHORTCUT)) == 0)
    {
        SetLeftSoftkeyFunction(mmi_am_os_delete_hs_shortcut, KEY_EVENT_UP);
        SetKeyHandler(mmi_am_os_delete_hs_shortcut, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#ifdef __MMI_TOUCH_SCREEN__
        wgui_register_list_item_selected_callback(mmi_am_os_delete_hs_shortcut);
#endif 
    }
#endif /* defined (__MMI_VUI_HOMESCREEN__) */ 
    else if (mmi_wcscmp((U16*) item_text, (U16*) GetString(STR_GLOBAL_DETAILS)) == 0)
    {
        SetLeftSoftkeyFunction(mmi_am_os_app_details, KEY_EVENT_UP);
        SetKeyHandler(mmi_am_os_app_details, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#ifdef __MMI_TOUCH_SCREEN__
        wgui_register_list_item_selected_callback(mmi_am_os_app_details);
#endif 
    }
    else if (mmi_wcscmp((U16*) item_text, (U16*) GetString(STR_GLOBAL_DELETE)) == 0)
    {
        SetLeftSoftkeyFunction(mmi_am_os_app_delete, KEY_EVENT_UP);
        SetKeyHandler(mmi_am_os_app_delete, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#ifdef __MMI_TOUCH_SCREEN__
        wgui_register_list_item_selected_callback(mmi_am_os_app_delete);
#endif 
    }
    else if (mmi_wcscmp((U16*) item_text, (U16*) GetString(STR_GLOBAL_RESUME)) == 0)
    {
        SetLeftSoftkeyFunction(mmi_am_os_app_resume, KEY_EVENT_UP);
        SetKeyHandler(mmi_am_os_app_resume, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#ifdef __MMI_TOUCH_SCREEN__
        wgui_register_list_item_selected_callback(mmi_am_os_app_resume);
#endif 
    }
    /* vogins 20100629 begin*/
    else if (mmi_wcscmp((U16*) item_text, (U16*) GetString(STR_ID_AM_OPTION_DATA_ACCOUNT)) == 0)//michael 0625
    {
        SetLeftSoftkeyFunction(mmi_am_entry_dataaccount_opt_scrn/*mmi_am_entry_dataaccount_screen*/, KEY_EVENT_UP);
        SetKeyHandler(mmi_am_entry_dataaccount_opt_scrn/*mmi_am_entry_dataaccount_screen*/, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#ifdef __MMI_TOUCH_SCREEN__
        wgui_register_list_item_selected_callback(mmi_am_entry_dataaccount_opt_scrn/*mmi_am_entry_dataaccount_screen*/);
#endif
    }
    /* vogins 20100629 end*/
/*vogins_20100712_start*/
    else if (mmi_wcscmp((U16*) item_text, (U16*) GetString(STR_ID_AM_PROCESSES_MANAGER)) == 0)
    {
        SetLeftSoftkeyFunction(mmi_am_os_processes_manager, KEY_EVENT_UP);
        SetKeyHandler(mmi_am_os_processes_manager, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    #ifdef __MMI_TOUCH_SCREEN__
        wgui_register_list_item_selected_callback(mmi_am_os_processes_manager);
    #endif 
    }
/*vogins_20100712_end*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_os_lsk_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_os_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    UI_string_type item_text;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetHighlightedItem();
    item_text = get_item_text(index);

    if (mmi_wcscmp((U16*) item_text, (U16*) GetString(STR_GLOBAL_DOWNLOAD)) == 0)
    /*Vogins_20100625_start*/
    {
#ifndef AM_GPRS_NOT_NOTICE    
	if (is_prompt_rule_cdr.sc_download_flag)
	{
	    mmi_am_os_download();
	}
	else
	{
	    mmi_am_download_prompt();
	}
#else
        mmi_am_os_download();	
#endif
    }
/*Vogins_20100625_end*/
    else if (mmi_wcscmp((U16*) item_text, (U16*) GetString(STR_GLOBAL_SETTINGS)) == 0)
    {
        mmi_am_entry_settings_scrn();
    }
    else if (mmi_wcscmp((U16*) item_text, (U16*) GetString(STR_GLOBAL_OPEN)) == 0)
    {
        mmi_am_os_app_launch();
    }
#if defined (__MMI_VUI_HOMESCREEN__)
    else if (mmi_wcscmp((U16*) item_text, (U16*) GetString(STR_ID_AM_OPTION_CREATE_SHORTCUT)) == 0)
    {
        mmi_am_os_create_hs_shortcut();
    }
    else if (mmi_wcscmp((U16*) item_text, (U16*) GetString(STR_ID_AM_OPTION_DELETE_SHORTCUT)) == 0)
    {
        mmi_am_os_delete_hs_shortcut();
    }
#endif /* defined (__MMI_VUI_HOMESCREEN__) */ 
    else if (mmi_wcscmp((U16*) item_text, (U16*) GetString(STR_GLOBAL_DETAILS)) == 0)
    {
        mmi_am_os_app_details();
    }
    else if (mmi_wcscmp((U16*) item_text, (U16*) GetString(STR_GLOBAL_DELETE)) == 0)
    {
        mmi_am_os_app_delete();
    }
    else if (mmi_wcscmp((U16*) item_text, (U16*) GetString(STR_GLOBAL_RESUME)) == 0)
    {
        mmi_am_os_app_resume();
    }
    /* vogins 20100629 begin*/
    else if (mmi_wcscmp((U16*) item_text, (U16*) GetString(STR_ID_AM_OPTION_DATA_ACCOUNT)) == 0)//michael 0625
    {
        mmi_am_entry_dataaccount_opt_scrn();
    }
    /* vogins 20100629 end*/
/*vogins_20100712_start*/
	else if (mmi_wcscmp((U16*) item_text, (U16*) GetString(STR_ID_AM_PROCESSES_MANAGER)) == 0)
    {
        mmi_am_os_processes_manager();
    }
/*vogins_20100712_end*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_os_download
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_os_download(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ask user if wish to download the app */
    mmi_display_popup_confirm_with_sg(
                                     GRP_ID_AM,
#ifdef __VRE_AM_08AB__
                                     STR_GLOBAL_YES,
                                     IMG_GLOBAL_YES,
                                     STR_GLOBAL_NO,
                                     IMG_GLOBAL_NO,
#else
                                     get_string(STR_GLOBAL_YES),
                                     get_image(IMG_GLOBAL_YES),
                                     get_string(STR_GLOBAL_NO),
                                     get_image(IMG_GLOBAL_NO),
#endif
                                     get_string(STR_GLOBAL_DOWNLOAD_ASK),
                                     MMI_EVENT_QUERY,
                                     0);

    /* delete Options Screen */
    mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_OPTIONS);

    SetLeftSoftkeyFunction(mmi_am_os_download_accept, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

}
/*Vogins_20100625_start*/
/*****************************************************************************
 * FUNCTION
 *  mmi_am_os_download_prompt_accept
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_os_download_prompt_accept(void)
{
    S16 error;
    is_prompt_rule_cdr.sc_download_flag = KAL_TRUE;

    WriteRecord(
               NVRAM_EF_AM_PROMPT_LID,
               (U16) (1),
               &is_prompt_rule_cdr,
               sizeof(am_prompt_struct),
               &error);

    mmi_am_os_download_accept();
    mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_SC_PROMPT);
}
static void mmi_am_exit_download_prompt(void)
{
}

/*****************************************************************************
 * FUNCTION
 *  mmi_am_download_prompt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_download_prompt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* notify user if wish to download the app */
    if (!is_prompt_rule_cdr.sc_download_flag)
    {
        MMI_BOOL ret;
        U8 *gui_buffer;

        ret = mmi_frm_scrn_enter(GRP_ID_AM, SCR_ID_AM_SC_PROMPT, mmi_am_exit_download_prompt, mmi_am_download_prompt, NULL);

        gui_buffer = mmi_frm_scrn_get_active_gui_buf();

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
                            (U8*) GetString(STR_ID_AM_SC_PROMPT_INFOMATION), 
                            mmi_ucs2strlen((S8*) GetString(STR_ID_AM_SC_PROMPT_INFOMATION)), gui_buffer);

        /* delete Options Screen */
        mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_OPTIONS);

        SetLeftSoftkeyFunction(mmi_am_os_download_prompt_accept, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    }
    else
        mmi_am_os_download_accept();
}
/*Vogins_20100726_start*/
/*****************************************************************************
 * FUNCTION
 *  mmi_am_entry_update_cdr_wait_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_entry_downloading_wait_scrn(void)
        {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_frm_scrn_enter(GRP_ID_AM, SCR_ID_AM_DOWNLOADING_WAIT, mmi_am_exit_downloading_wait_scrn, NULL, NULL);

    if (ret == MMI_FALSE)
            {
        return;
        }

    ShowCategory63Screen((U8*) GetString(STR_GLOBAL_PLEASE_WAIT), IMG_GLOBAL_PROGRESS, NULL);
    }


/*****************************************************************************
 * FUNCTION
 *  mmi_am_exit_downloading_wait_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_exit_downloading_wait_scrn(void)
    {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* cancel downloading */
    if(!g_am_dl_cntx.is_start_downloading)
    {
    mmi_am_downlaod_cancel_check();
         if(g_am_qs_cntx.is_quick_start == MMI_TRUE)
         {
			mmi_am_release_download();
         }
}
}
/******************0801**********************/

static void mmi_am_download_size_limit(void)
{
	S32 i;

	MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_download_size_limit  ----------------------[S]");
	for(i = 0; i < g_am_filesize_cntx.file_count; i++)
	{
		if(strcmp((PS8)g_am_filesize_cntx.dl_file_list[i].file_id, "appstore") == 0)
		{
			g_am_dl_cntx.is_limit_dl_size = MMI_TRUE;
			g_am_dl_cntx.add_size -= g_am_filesize_cntx.dl_file_list[i].file_size;			
		}
	}
	MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_download_size_limit  ----------------------[E]");
}

static VMINT mmi_am_get_dl_app_id_and_name(U32* dl_id, U16* file_name)
{
	S32 i, max;
	mmi_am_shortcut_info_struct *sc_info;
	
	MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_get_dl_app_id_and_name ---------------[S]");

	if(g_am_filesize_cntx.dl_index >= g_am_filesize_cntx.file_count)
	{
		MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_get_dl_app_id_and_name  dl_index error!");
		return -1;
	}
	
	if(g_am_qs_cntx.is_quick_start != MMI_TRUE)
	{
	sc_info = mmi_am_config_get_am_sc_list();
		max = mmi_am_config_get_am_sc_num();
	}
	else
	{
		sc_info = mmi_am_config_get_mm_sc_list();
		max = mmi_am_config_get_mm_sc_num();
	}
	if(strcmp((PS8)g_am_filesize_cntx.dl_file_list[g_am_filesize_cntx.dl_index].file_id, "appstore") == 0)
	{
		MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_get_dl_app_id_and_name  appstore");

		#ifdef AM_DOWNLOAD_SIZE_LIMIT
		if(g_am_dl_cntx.is_limit_dl_size)
		{
			g_am_filesize_cntx.dl_index++;
			return mmi_am_get_dl_app_id_and_name(dl_id, file_name);			
		}		
		#endif
		*dl_id = sc_info[0].dl_app_id;
		mmi_asc_to_wcs(file_name, sc_info[0].file_name);
		
		return 0;
	}
	else if(strcmp((PS8)g_am_filesize_cntx.dl_file_list[g_am_filesize_cntx.dl_index].file_id, "sm_billing") == 0)
	{
		S8 charge_name[MMI_AM_MAX_SHORTCUT_APP_NAME] = "sm_billing.vsm";
		MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_get_dl_app_id_and_name  sm_billing");
		*dl_id = 0;
		mmi_asc_to_wcs(file_name, charge_name);
		return 0;
	}
	else
	{
		MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_get_dl_app_id_and_name  app");
		*dl_id = atoi((char*)g_am_filesize_cntx.dl_file_list[g_am_filesize_cntx.dl_index].file_id);
		for(i = 0; i < max; i++)
		{
			if(*dl_id == sc_info[i].dl_app_id)
			{
				mmi_asc_to_wcs(file_name, sc_info[i].file_name);
				return 0;
			}
		}
	}
	MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_get_dl_app_id_and_name ---------------[E]");
	return -1;
	
}

static void mmi_am_vre_start_download(void)
{
	S32 i, ret, index;
	U32 dl_id;
       U16 file_name[MMI_AM_MAX_SHORTCUT_APP_NAME];
	   S32 num_sc_bg_run = 0, num_rom_bg_run = 0;

	MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_vre_start_download ---------------[S]");

	if(g_am_qs_cntx.is_quick_start != MMI_TRUE)
	{
	#ifdef AM_DOWNLOAD_SIZE_LIMIT
	if(g_am_dl_cntx.add_size >= MMI_AM_MAX_DOWNLOAD_LIMIT_SIZE)
	{
		mmi_am_download_size_limit();
	}
	#endif
	mmi_am_get_sc_and_rom_bg_num(&num_sc_bg_run, &num_rom_bg_run);
	index = g_am_ms_cntx.hl_idx;
	if (index > num_sc_bg_run)
	       index -= (num_app_move + num_rom_bg_run);
	
	/*the download list is NULL*/
	if(g_am_filesize_cntx.file_count == 0)
	{
		mmi_display_popup_with_sg(
                                     GRP_ID_AM,
                                     (UI_string_type) get_string(STR_ID_AM_DOWNLOAD_FAILURE),
                                     MMI_EVENT_FAILURE,
                                     0);
		mmi_am_release_download();
		return;
	}

	/*only sm_billing is allowed to download, fail.*/
	if(g_am_filesize_cntx.file_count == 1 && strcmp((PS8)g_am_filesize_cntx.dl_file_list[g_am_filesize_cntx.dl_index].file_id, "sm_billing") == 0
		|| (index != 0 && strcmp((char*)g_am_filesize_cntx.dl_file_list[g_am_filesize_cntx.file_count-1].file_id, "appstore") == 0))
	{
		mmi_display_popup_with_sg(
                                 GRP_ID_AM,
                                 (UI_string_type) get_string(STR_ID_AM_DOWNLOAD_FAILURE),
                                 MMI_EVENT_FAILURE,
                                 0);
		mmi_am_release_download();
		return;
	}
	}
	if(mmi_am_get_dl_app_id_and_name(&dl_id, file_name) != 0)
	{
		mmi_display_popup_with_sg(
                                     GRP_ID_AM,
                                     (UI_string_type) get_string(STR_ID_AM_DOWNLOAD_FAILURE),
                                     MMI_EVENT_FAILURE,
                                     0);         
		mmi_am_release_download();
		MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_get_dl_app_id_and_name  fail!");
        return;  //michael 0731
	}
	/*prepare and start to download*/
	mmi_am_vre_pre_download_app(mmi_am_calloc, mmi_am_free);
        ret = mmi_am_vre_download_app(mmi_am_download_app_cb, (U32) dl_id, (PU16) file_name, MMI_AM_DOWNLOAD_BLOCK_SIZE);
        MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_os_download_accept() -- ret:%d;dl_app_id:%d", ret, dl_id);
        if (ret == MMI_AM_DL_OK)
        {
            mmi_am_dl_set_appid(dl_id);
            mmi_am_dl_set_app_name(file_name);
        }
        else
        {
        	mmi_am_release_download();
            mmi_display_popup_with_sg(
                                     GRP_ID_AM,
                                     (UI_string_type) get_string(STR_ID_AM_DOWNLOAD_FAILURE),
                                     MMI_EVENT_FAILURE,
                                     0);
        }
	MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_vre_start_download ---------------[E]");
}

static void mmi_am_check_file_size_cb(VMINT nResult, VMUINT8 * pData, VMINT nDataLen)
{
	S32 ret;
	
	MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_check_file_size_cb ---------------[S]");
	MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_check_file_size_cb ----ret: %d", nResult);
	if(nResult == VAM_DL_OK)
	{
		/*get files' size*/
		ret = mmi_am_file_size_parse(pData, nDataLen);
		MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_check_file_size_cb  ret:%d", ret);
		if(ret != 0)
		{
			return;
		}
    
		mmi_am_vre_start_download();
	}
	else 
	{
		mmi_am_release_download();
		mmi_display_popup_with_sg(
                                     GRP_ID_AM,
                                     (UI_string_type) get_string(STR_ID_AM_DOWNLOAD_FAILURE),
                                     MMI_EVENT_FAILURE,
                                     0);         
		MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_check_file_size_cb  fail!");
	}
	MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_check_file_size_cb ---------------[E]");
	
}

static void mmi_am_check_appstore(void)
{
	S32 index, ret;
 	U32 dl_app_id;
 	mmi_am_shortcut_info_struct *sc_info;
    	S32 num_sc_bg_run = 0, num_rom_bg_run = 0;
    	S32 i = 0;

	MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_check_appstore ---------------[S]");	
    
	if(!mmi_am_ms_is_app_download(0))
	{
		U8 pAppStore[8] = "appstore";
		mmi_am_add_download_list(pAppStore, (VMINT)(strlen((char*)pAppStore)));
	}

	mmi_am_get_sc_and_rom_bg_num(&num_sc_bg_run, &num_rom_bg_run);
	index = g_am_ms_cntx.hl_idx;
	if (index > num_sc_bg_run)
	       index -= (num_app_move + num_rom_bg_run);

	if(index != 0)
	{
		U8 strVal[20];
		index--;
		sc_info = mmi_am_config_get_am_sc_list();
		while (sc_info[i].icon_id != g_am_cntx.shortcut_app_list[index].icon_id && i < g_am_cntx.shortcut_app_num)
           		i++;
        	dl_app_id = sc_info[i].dl_app_id;
		sprintf((char*)strVal, "%d", dl_app_id);

		mmi_am_add_download_list(strVal, (VMINT)((strlen((char*)strVal))));
	}

	if(g_am_download_list_cntx.strlength == 0)
	{
		MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "[AM] mmi_am_check_file_size fail!	g_am_download_list_cntx.strlength = 0");
		mmi_am_release_download();
		mmi_display_popup_with_sg(
                                     GRP_ID_AM,
                                     (UI_string_type) get_string(STR_ID_AM_DOWNLOAD_FAILURE),
                                     MMI_EVENT_FAILURE,
                                     0);
		return;
	}
	/*get the files' size*/
	if (mmi_am_check_file_size(mmi_am_check_file_size_cb, g_am_download_list_cntx.pDownloadList) != MMI_AM_DL_OK)
        {
            MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "[AM] mmi_am_check_file_size fail!");
            //联网失败
            mmi_am_release_download();
            mmi_display_popup_with_sg(
                                     GRP_ID_AM,
                                     (UI_string_type) get_string(STR_ID_AM_DOWNLOAD_FAILURE),
                                     MMI_EVENT_FAILURE,
                                     0);
        }
       MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_check_appstore ---------------[E]");	
}

static void mmi_am_add_download_list(U8* pData, VMINT pDataLen)
{
	MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_add_download_list ------------------[S] ");

	MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_add_download_list ---data: %s, Len: %d", pData, pDataLen);

	if(g_am_download_list_cntx.strlength != 0)
	{
		memset(g_am_download_list_cntx.pDownloadList + g_am_download_list_cntx.strlength, ',', 1);
		g_am_download_list_cntx.strlength += 1;
	}
	
	memcpy(g_am_download_list_cntx.pDownloadList + g_am_download_list_cntx.strlength, pData, pDataLen);
	g_am_download_list_cntx.strlength += pDataLen;
	
	MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_add_download_list ---data list: %s, total Len: %d", g_am_download_list_cntx.pDownloadList, g_am_download_list_cntx.strlength);
	MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_add_download_list ------------------[E] ");
}

static void mmi_am_check_dll_version_cb(VMINT nResult, VMUINT8 * pData, VMINT nDataLen)
{
	S32 ret, i;

	MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_check_dll_version_cb ---------------[S]");	
	if(nResult == VAM_DL_OK)
	{
		ret = mmi_am_check_dll_parse(pData, nDataLen);
		if(ret != 0)
		{
			MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_check_dll_version_cb parse dll version fail! ");
			return;
		}

		for(i = 0; i < g_am_check_dll_cntx.dll_count; i++)
		{
			if(g_am_check_dll_cntx.dll_list[i].update_flag)
			{
				mmi_am_add_download_list(g_am_check_dll_cntx.dll_list[i].dll_id, (VMINT)(strlen((char*)g_am_check_dll_cntx.dll_list[i].dll_id)));
			}
		}
		mmi_am_check_appstore();
	}
	else
	{
		mmi_display_popup_with_sg(
                                     GRP_ID_AM,
                                     (UI_string_type) get_string(STR_ID_AM_DOWNLOAD_FAILURE),
                                     MMI_EVENT_FAILURE,
                                     0);         
		MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_check_dll_version_cb  fail!");
	}

	MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_check_dll_version_cb ---------------[E]");	
}

static VMINT mmi_am_check_dll_parse(VMUINT8* pData, VMINT nDataLen)
{
	VMUINT32 strLength;
	VMINT nOffset = 0, i;	

	MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_check_dll_parse data ---------------[S]");
	if(pData == NULL || nDataLen == 0)
	{
		MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_check_dll_parse data null");
		return -1;
	}

	memcpy(&g_am_check_dll_cntx.dll_count, pData, 1);
	MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_check_dll_parse data num: %d", g_am_check_dll_cntx.dll_count);
	nOffset++;

	g_am_check_dll_cntx.dll_list= (mmi_am_check_dll_struct*)mmi_am_malloc(g_am_check_dll_cntx.dll_count* sizeof(mmi_am_check_dll_struct));

	if(!g_am_check_dll_cntx.dll_list)
	{
		MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_check_dll_parse data malloc memory fail");
		return -1;
	}
	for(i = 0; i < g_am_check_dll_cntx.dll_count; i++)
	{
		U16* pBUfTemp;
		/*get the dll id*/
		memcpy(&strLength, pData+nOffset, 4);
		nOffset += (4);
		pBUfTemp = mmi_am_malloc(strLength*2+2);
		memset(pBUfTemp, 0, strLength*2+2);
		memcpy(pBUfTemp, pData+nOffset, strLength*2);
		g_am_check_dll_cntx.dll_list[i].dll_id = mmi_am_malloc(strLength+1);
		mmi_wcs_to_asc((S8*)g_am_check_dll_cntx.dll_list[i].dll_id, pBUfTemp);
		mmi_am_free(pBUfTemp);
		
		nOffset += (strLength*2);
MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_check_dll_parse index: %d,  dll id: %s", i, g_am_check_dll_cntx.dll_list[i].dll_id);	

		/*get the update flag*/
		memcpy(&g_am_check_dll_cntx.dll_list[i].update_flag, pData+nOffset, 1);
		nOffset += (1);
MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_check_dll_parse index: %d,  update flag: %d", i, g_am_check_dll_cntx.dll_list[i].update_flag);	
	}

	MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_check_dll_parse data ---------------[E]");
	return 0;
}

static VMINT mmi_am_file_size_parse(VMUINT8* pData, VMINT nDataLen)
{
	VMUINT32 strLength;
	VMINT nOffset = 0, i;	
	 
	
	MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_size_parse data ---------------[S]");
	if(pData == NULL || nDataLen == 0)
	{
		MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_size_parse data null");
		return -1;
	}
	
	memcpy(&g_am_filesize_cntx.file_count, pData, 1);
	nOffset++;
	MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_size_parse need download files' number: %d", g_am_filesize_cntx.file_count);
	g_am_filesize_cntx.dl_file_list = (mmi_am_filesize_struct*)mmi_am_malloc(g_am_filesize_cntx.file_count * sizeof(mmi_am_filesize_struct));
	if(!g_am_filesize_cntx.dl_file_list)
	{
		MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_file_size_parse data malloc memory fail");
		return 0;
	}
	for(i = 0; i < g_am_filesize_cntx.file_count; i++)
	{
		U16* pDataTep;
 		   /*读取产品编号*/
		   memcpy(&strLength, pData+nOffset, 4);
MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_size_parse index: %d,  len: %d", i, strLength);	   		   
		   nOffset += (4);
		   pDataTep = mmi_am_malloc(strLength*2+2);
		    if(!pDataTep)
		   	{
		   		MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_size_parse mmi_am_malloc pDataTep fail!!!!");	  
				return -1;
		   	}
		   memset(pDataTep, 0, strLength*2+2);
		   memcpy(pDataTep, pData+nOffset, strLength*2);
		   g_am_filesize_cntx.dl_file_list[i].file_id = mmi_am_malloc(strLength+1);
		   if(!g_am_filesize_cntx.dl_file_list[i].file_id)
		   	{
		   		mmi_am_free(pDataTep);
		   		MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_size_parse mmi_am_malloc g_am_filesize_cntx.dl_file_list[i].file_id fail!!!!");	  
				return -1;
		   	}
		   memset(g_am_filesize_cntx.dl_file_list[i].file_id, 0, strLength+1);
		   mmi_wcs_to_asc((S8*)g_am_filesize_cntx.dl_file_list[i].file_id, pDataTep);		
		   nOffset += (strLength*2);
		   mmi_am_free(pDataTep);
		   
MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_size_parse index: %d,  file id: %s", i, g_am_filesize_cntx.dl_file_list[i].file_id);	

		   /*读取产品文件大小*/
	         memcpy(&g_am_filesize_cntx.dl_file_list[i].file_size, pData+nOffset, 4);
		   nOffset += (4);
		   g_am_dl_cntx.add_size += (g_am_filesize_cntx.dl_file_list[i].file_size);
MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_size_parse index: %d,  size: %d", i, g_am_filesize_cntx.dl_file_list[i].file_size);

		   /*读取文件名*/
		   memcpy(&strLength, pData+nOffset, 4);
MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_size_parse index: %d,  len: %d", i, strLength);	   		 		   
		   nOffset += (4);
		   pDataTep = mmi_am_malloc(strLength*2+2);
		   if(!pDataTep)
		   	{
		   		MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_size_parse mmi_am_malloc pDataTep fail!!!!");	  
				return -1;
		   	}
		   memset(pDataTep, 0, strLength*2+2);
		   memcpy(pDataTep, pData+nOffset, strLength*2);
		   g_am_filesize_cntx.dl_file_list[i].file_name= mmi_am_malloc(strLength+1);
		    if(!g_am_filesize_cntx.dl_file_list[i].file_name)
		   	{
		   		mmi_am_free(pDataTep);
		   		MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_size_parse mmi_am_malloc g_am_filesize_cntx.dl_file_list[i].file_name fail!!!!");	  
				return -1;
		   	}
		   memset(g_am_filesize_cntx.dl_file_list[i].file_name, 0, strLength+1);
		   mmi_wcs_to_asc((S8*)g_am_filesize_cntx.dl_file_list[i].file_name, pDataTep);		
		   nOffset += (strLength*2);
		   mmi_am_free(pDataTep);
MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_size_parse index: %d,  file_name: %s", i, g_am_filesize_cntx.dl_file_list[i].file_name);		   
	}
	MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_size_parse data  total size: %d", g_am_dl_cntx.add_size);
	MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_size_parse data ---------------[E]");
	return 0;
}

void mmi_am_release_download()
{
	S32 i;

	MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_release_download ---------------[S]");
	MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_release_download ---count: %d", g_am_filesize_cntx.file_count);
	if(g_am_filesize_cntx.dl_file_list  != NULL)
	{
		for(i = 0; i < g_am_filesize_cntx.file_count; i++)
		{
			MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_release_download --1---index: %d", i);
			mmi_am_free(g_am_filesize_cntx.dl_file_list[i].file_id);
			MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_release_download --2-index: %d", i);
			g_am_filesize_cntx.dl_file_list[i].file_id = NULL;
			mmi_am_free(g_am_filesize_cntx.dl_file_list[i].file_name);
			MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_release_download --3-index: %d", i);
			g_am_filesize_cntx.dl_file_list[i].file_name = NULL;
		}
		mmi_am_free(g_am_filesize_cntx.dl_file_list);
		g_am_filesize_cntx.dl_file_list = NULL;
		MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_release_download -----g_am_filesize_cntx----------[E]");
	}
	
	if(g_am_check_dll_cntx.dll_list != NULL)
	{
		for(i = 0; i < g_am_check_dll_cntx.dll_count; i ++)
		{
			mmi_am_free(g_am_check_dll_cntx.dll_list[i].dll_id);
			g_am_check_dll_cntx.dll_list[i].dll_id = NULL;
		}
		mmi_am_free(g_am_check_dll_cntx.dll_list);
		g_am_check_dll_cntx.dll_list = NULL;
	}

    if(g_am_qs_cntx.is_quick_start == MMI_TRUE)
    {
        mmi_am_download_app_from_mm_deinit();
    }

	MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_release_download ---------------[E]");
}


void mmi_am_os_download_accept(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U8 pCheckList[25] = "sm_billing";
    mmi_am_sm_cntx_struct version;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_os_download_accept_ex ---------------[S]");	
     if (!mmi_am_download_pre_check())
    {
        return;
    }
	 /* show network connection message */
    /*mmi_display_popup_confirm_with_sg(
         GRP_ID_AM,
         NULL,
         NULL,
         NULL,
         NULL,
         get_string(STR_GLOBAL_PLEASE_WAIT),
         MMI_EVENT_PROGRESS,
                                     0);*/
    mmi_am_entry_downloading_wait_scrn();
	 
        /* initialize */
        mmi_am_dl_init();
	 
	if(g_am_qs_cntx.is_quick_start != MMI_TRUE)
	{
    /*get dll id and version*/
	ret = mmi_am_query_info(pCheckList, &version);
	if(ret == MMI_AM_SM_SUCCESS)
	{
		memset(pCheckList+10, ':', 1);
		memcpy(pCheckList+11, version.dll_version, 6);
		
		MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_check_dll_version -- pCheckList: %s", pCheckList);

		/*check the dll versiton*/
		mmi_am_check_dll_version(mmi_am_check_dll_version_cb, pCheckList);
	}
	else
	{
		mmi_am_add_download_list(pCheckList, (VMINT)(strlen((char*)pCheckList)));
		mmi_am_check_appstore();
	}
	}
	else
	{
		MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_os_download_accept_ex quickstart id: %d", g_am_qs_cntx.app_id);	
		if(g_am_qs_cntx.app_id == APPID_VAS)
		{
			U8 pAppStore[9] = "appstore";
			MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_os_download_accept_ex APPID_VAS");	
			
			mmi_am_add_download_list(pAppStore, (VMINT)(strlen((char*)pAppStore)));
		}
		else
		{
			U8 strVal[20];
			U32 dl_app_id;
			mmi_am_shortcut_info_struct *p = mmi_am_config_get_mm_sc_info_by_appid(g_am_qs_cntx.app_id);
			MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_os_download_accept_ex not APPID_VAS");	
			
			if (p)
			{
			    dl_app_id = p->dl_app_id;
			}
			else
			{
			    dl_app_id = 0;
			}
			sprintf((char*)strVal, "%d", dl_app_id);
			mmi_am_add_download_list(strVal, (VMINT)((strlen((char*)strVal))));
		}

		if (mmi_am_check_file_size(mmi_am_check_file_size_cb, g_am_download_list_cntx.pDownloadList) != MMI_AM_DL_OK)
	        {
	            MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "[AM] mmi_am_check_file_size fail!");
	            //联网失败
	            mmi_am_release_download();
	            mmi_display_popup_with_sg(
	                                     GRP_ID_AM,
	                                     (UI_string_type) get_string(STR_ID_AM_DOWNLOAD_FAILURE),
	                                     MMI_EVENT_FAILURE,
	                                     0);
      	  	}
		DeleteScreenIfPresent(SCR_ID_AM_DOWNLOAD_FROM_MM_ASK);
	}
	
	MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_os_download_accept_ex ---------------[E]");	
	
}
/*Vogins_20100726_end*/

/*****************************************************************************
 * FUNCTION
 *  mmi_am_os_app_launch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_os_app_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_am_cntx.start_state = START_BEGIN;

#ifndef AM_09A
    if (mmi_frm_scrn_is_present(GRP_ID_AM, SCR_ID_AM_LOADING, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_LOADING);
    }
#endif /* AM_09A */ 

    mmi_am_entry_loading_scrn();

    /* delete Options Screen */
    mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_OPTIONS);
}

    #if defined (__MMI_VUI_HOMESCREEN__)


/*****************************************************************************
 * FUNCTION
 *  mmi_am_os_create_hs_shortcut
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_os_create_hs_shortcut(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U16 *app_path;
    U8 *p_icon;
    U32 icon_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_os_create_hs_shortcut() ------- [S]");

    app_path = mmi_am_ms_get_app_path_by_index(g_am_ms_cntx.hl_idx);
    p_icon = mmi_am_ms_get_app_icon_by_index(g_am_ms_cntx.hl_idx, &icon_size);

    ret = mmi_am_set_as_shortcut(app_path, p_icon, icon_size);
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_os_create_hs_shortcut() -- ret:%d", ret);
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_SCREENS_SET_SHORTCUT, ret);

    switch (ret)
    {
    case MMI_AM_SHORTCUT_SET_SUCCESS:
        mmi_display_popup_with_sg(
                                 GRP_ID_AM,
                                 (UI_string_type) get_string(STR_ID_AM_SHORTCUT_SET_DONE),
                                 MMI_EVENT_SUCCESS,
                                 0);
        mmi_am_ms_set_app_hs_shortcut(g_am_ms_cntx.hl_idx);
        break;
    case MMI_AM_SHORTCUT_OVER_NUMBER:
        mmi_display_popup_with_sg(
                                 GRP_ID_AM,
                                 (UI_string_type) get_string(STR_ID_AM_SHORTCUT_SET_MAX),
                                 MMI_EVENT_FAILURE,
                                 0);
        break;
    case MMI_AM_SHORTCUT_DUPLICATE_ID:
        mmi_display_popup_with_sg(
                                 GRP_ID_AM,
                                 (UI_string_type) get_string(STR_ID_AM_SHORTCUT_SET_DUPLICATE),
                                 MMI_EVENT_FAILURE,
                                 0);
        break;
    case MMI_AM_SHORTCUT_ICON_SIZE_FAIL:
        mmi_display_popup_with_sg(
                                 GRP_ID_AM,
                                 (UI_string_type) get_string(STR_ID_AM_SHORTCUT_OLD_VER_SET_FAILURE),
                                 MMI_EVENT_FAILURE,
                                 0);
        break;
    case MMI_AM_SHORTCUT_FILE_NOT_FOUND:
        mmi_display_popup_with_sg(
                                 GRP_ID_AM,
                                 (UI_string_type) get_string(STR_ID_AM_FILE_NOT_EXIST),
                                 MMI_EVENT_FAILURE,
                                 0);
        break;
    case MMI_AM_SHORTCUT_CERT_EXPIRED:
        mmi_display_popup_with_sg(
                                 GRP_ID_AM,
                                 (UI_string_type) get_string(STR_ID_AM_CERT_EXPIRED_FAIL_TO_START),
                                 MMI_EVENT_FAILURE,
                                 0);
        break;
    case MMI_AM_SHORTCUT_WRONG_DATE:
        mmi_display_popup_with_sg(
                                 GRP_ID_AM,
                                 (UI_string_type) get_string(STR_ID_AM_DATE_ERR_FAIL_TO_START),
                                 MMI_EVENT_FAILURE,
                                 0);
        break;
    case MMI_AM_SHORTCUT_IMSI_DISMATCH:
        mmi_display_popup_with_sg(
                                 GRP_ID_AM,
                                 (UI_string_type) get_string(STR_ID_AM_INVALID_SIM_FAIL_TO_START),
                                 MMI_EVENT_FAILURE,
                                 0);
        break;
    case MMI_AM_SHORTCUT_WRONG_PLATFORM:
        mmi_display_popup_with_sg(
                                 GRP_ID_AM,
                                 (UI_string_type) get_string(STR_ID_AM_TAG_ERR_FAIL_TO_START),
                                 MMI_EVENT_FAILURE,
                                 0);
        break;
    case MMI_AM_SHORTCUT_STRUCTURE_FAIL:
    case MMI_AM_SHORTCUT_FILE_FAIL:
        mmi_display_popup_with_sg(
                                 GRP_ID_AM,
                                 (UI_string_type) get_string(STR_ID_AM_SHORTCUT_SET_FAILURE),
                                 MMI_EVENT_FAILURE,
                                 0);
        break;
    default:
        mmi_display_popup_with_sg(
                                 GRP_ID_AM,
                                 (UI_string_type) get_string(STR_ID_AM_SHORTCUT_SET_FAILURE),
                                 MMI_EVENT_FAILURE,
                                 0);
        break;

    }

    /* delete Options Screen */
    mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_OPTIONS);

    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_os_create_hs_shortcut() ------- [E]");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_os_delete_hs_shortcut
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_os_delete_hs_shortcut(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ask user if wish to delete the home screen shortcut settings */
    mmi_display_popup_confirm_with_sg(
                                     GRP_ID_AM,
#ifdef __VRE_AM_08AB__
                                     STR_GLOBAL_YES,
                                     IMG_GLOBAL_YES,
                                     STR_GLOBAL_NO,
                                     IMG_GLOBAL_NO,
#else
                                     get_string(STR_GLOBAL_YES),
                                     get_image(IMG_GLOBAL_YES),
                                     get_string(STR_GLOBAL_NO),
                                     get_image(IMG_GLOBAL_NO),
#endif
                                     get_string(STR_ID_AM_SHORTCUT_DEL_QUERY),
                                     MMI_EVENT_QUERY,
                                     0);

    SetLeftSoftkeyFunction(mmi_am_os_delete_hs_shortcut_accept, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

    /* delete Options Screen */
    mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_OPTIONS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_os_delete_hs_shortcut_accept
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_os_delete_hs_shortcut_accept(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *app_path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    app_path = mmi_am_ms_get_app_path_by_index(g_am_ms_cntx.hl_idx);
    mmi_am_cancel_shortcut(app_path);

    mmi_display_popup_with_sg(
                             GRP_ID_AM,
                             (UI_string_type) get_string(STR_ID_AM_SHORTCUT_DEL_DONE),
                             MMI_EVENT_SUCCESS,
                             0);

    mmi_am_ms_remove_app_hs_shortcut(g_am_ms_cntx.hl_idx);
}
    #endif /* defined (__MMI_VUI_HOMESCREEN__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_am_os_app_details
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_os_app_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_am_entry_details_scrn();

    /* delete Options Screen */
    mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_OPTIONS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_os_app_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_os_app_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ask user if wish to delete the app */
    mmi_display_popup_confirm_with_sg(
                                     GRP_ID_AM,
#ifdef __VRE_AM_08AB__
                                     STR_GLOBAL_YES,
                                     IMG_GLOBAL_YES,
                                     STR_GLOBAL_NO,
                                     IMG_GLOBAL_NO,
#else
                                     get_string(STR_GLOBAL_YES),
                                     get_image(IMG_GLOBAL_YES),
                                     get_string(STR_GLOBAL_NO),
                                     get_image(IMG_GLOBAL_NO),
#endif
                                     get_string(STR_ID_AM_DELETE_APP_QUERY),
                                     MMI_EVENT_QUERY,
                                     0);

    SetLeftSoftkeyFunction(mmi_am_os_app_delete_accept, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

    /* delete Options Screen */
    mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_OPTIONS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_os_app_delete_accept
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_os_app_delete_accept(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = FS_Delete((const PU16)mmi_am_ms_get_app_path_by_index(g_am_ms_cntx.hl_idx));
    if (ret == FS_NO_ERROR)
    {
        mmi_am_ms_delete_node_from_applist_by_index(g_am_ms_cntx.hl_idx);
        mmi_am_delete_node_from_vxplist_by_index(g_am_ms_cntx.hl_idx);
        mmi_display_popup_with_sg(GRP_ID_AM, (UI_string_type) get_string(STR_GLOBAL_DELETED), MMI_EVENT_SUCCESS, 0);
    }
    else
    {
        mmi_display_popup_with_sg(
                                 GRP_ID_AM,
                                 (UI_string_type) get_string(STR_ID_AM_DELETE_APP_FAILURE),
                                 MMI_EVENT_FAILURE,
                                 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_os_app_resume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_os_app_resume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_am_cntx.start_state = START_BEGIN;

#ifndef AM_09A
    if (mmi_frm_scrn_is_present(GRP_ID_AM, SCR_ID_AM_LOADING, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_LOADING);
    }
#endif /* AM_09A */ 

    mmi_am_entry_loading_scrn();

    /* delete Options Screen */
    mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_OPTIONS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_entry_details_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_entry_details_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    U8 *gui_buffer;
    S32 buf_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_DETAILS_SCRN_ENTRY_S, g_ds_str_buf);

    if (g_ds_str_buf == NULL)
    {
        mmi_am_ds_prepare_data(&g_ds_str_buf, &buf_size);
        if (g_ds_str_buf == NULL)
        {
            return;
        }
    }

    ret = mmi_frm_scrn_enter(GRP_ID_AM, SCR_ID_AM_DETAILS, mmi_am_eixt_details_scrn, mmi_am_entry_details_scrn, NULL);

    if (ret == MMI_FALSE)
    {
        return;
    }

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

#ifdef AM_09A
#ifdef __VRE_AM_08AB__
    SetDelScrnIDCallbackHandler(SCR_ID_AM_DETAILS, (HistoryDelCBPtr) mmi_am_destroy_details_scrn);
#else
    mmi_frm_set_destroy_scrn_callback(SCR_ID_AM_DETAILS, (HistoryDelCBPtr) mmi_am_destroy_details_scrn);
#endif
#else /* AM_09A */ 
    /* set leave proc */
    mmi_frm_scrn_set_leave_proc(GRP_ID_AM, SCR_ID_AM_DETAILS, mmi_am_leave_details_scrn);
#endif /* AM_09A */ 

    ShowCategory74Screen(STR_GLOBAL_DETAILS,
#ifdef __MMI_FTE_SUPPORT__
                         0,
#else 
                         IMG_ID_AM_TITLE,
#endif 
                         0, 0, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, (U8*) g_ds_str_buf, buf_size, gui_buffer);

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_DETAILS_SCRN_ENTRY_E);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_eixt_details_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_eixt_details_scrn(void)
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
 *  mmi_am_destroy_details_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static U8 mmi_am_destroy_details_scrn(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_DETAILS_SCRN_DESTROY_S);

    mmi_am_free(g_ds_str_buf);
    g_ds_str_buf = NULL;

    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_DETAILS_SCRN_DESTROY_E);
    return MMI_FALSE;
}
    #else /* AM_09A */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_am_leave_details_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_am_leave_details_scrn(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_leave_details_scrn() ------- [S]");

    switch (evt->evt_id)
    {
    case EVT_ID_SCRN_DELETE_REQ:
        MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_leave_details_scrn() -- EVT_ID_SCRN_DELETE_REQ");
        break;

    case EVT_ID_SCRN_DEINIT:
        MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_leave_details_scrn() -- EVT_ID_SCRN_DELETE_REQ");
        mmi_am_free(g_ds_str_buf);
        g_ds_str_buf = NULL;
        break;
    }

    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_leave_details_scrn() ------- [E]");
    return ret;
}
    #endif /* AM_09A */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_am_ds_prepare_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  str_buf         [OUT]       
 *  buf_size        [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_ds_prepare_data(U8 **str_buf, S32 *buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    U16 app_name_temp[MMI_AM_MAX_APP_FILE_NAME];
    U16 app_file_name[MMI_AM_MAX_APP_FILE_NAME];
    U16 *desc_buf = NULL;
    U32 desc_size;
    U32 CRLF_size;
    U16 *app_path = NULL;
    U16 *temp_desc_buf = NULL, *p_desc = NULL, *p_phone = NULL, *p_rank = NULL;
    U32 temp_desc_size = 0;
    U16 *temp_developer_buf = NULL;
    U32 temp_developer_size = 0;
    FS_HANDLE file_hdl, findfirst_hdl;
    S32 file_result;
    U32 file_size;
    S8 file_size_buf[10];
    U16 file_size_buf_w[10];
    U16 semi[2];
    U16 semi_full[] = {0XFF1A, 0};
    FS_DOSDirEntry info;
    U8 *lang = NULL;

#ifdef AM_TEST
    S8 time_buf[40];
    U16 time_buf_w[40];
#endif /* AM_TEST */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_ds_prepare_data() ------- [S]");

    memset(app_name_temp, 0, sizeof(app_name_temp));
    memset(app_file_name, 0, sizeof(app_file_name));
    memset(file_size_buf, 0, sizeof(file_size_buf));
    memset(file_size_buf_w, 0, sizeof(file_size_buf_w));
    memset(semi, 0, sizeof(semi));

    lang = Get_Current_Lang_CountryCode();
    if (strcmp((PS8) lang, "en-US") == 0)   /* means english */
    {
        mmi_wcscpy(semi, (PU16) MMI_AM_DETAILS_SEMI);
    }
    else if (strcmp((PS8) lang, "zh-CN") == 0)
    {
        mmi_wcscpy(semi, (PU16) semi_full);
    }
    else if (strcmp((PS8) lang, "zh-TW") == 0)
    {
        mmi_wcscpy(semi, (PU16) semi_full);
    }

    CRLF_size = (mmi_ucs2strlen((PS8) semi)
                 + mmi_ucs2strlen((PS8) MMI_AM_DETAILS_NEWLINE) + mmi_ucs2strlen((PS8) MMI_AM_DETAILS_SPACES)) << 1;
    app_path = mmi_am_ms_get_app_path_by_index(g_am_ms_cntx.hl_idx);

    if (!mmi_am_ms_is_rom_app(g_am_ms_cntx.hl_idx))
    {
        /* get vxp file infomation */
        file_hdl = FS_Open(app_path, FS_OPEN_NO_DIR | FS_READ_ONLY);
        if (file_hdl < 0)
        {
            /* MMI_AM_ASSERT(0); */
            mmi_display_popup_with_sg(
                                     GRP_ID_AM,
                                     (UI_string_type) get_string(STR_ID_AM_FILE_NOT_EXIST),
                                     MMI_EVENT_FAILURE,
                                     0);
            return;
        }
        /* get file info */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* 0 */ 
        findfirst_hdl = FS_FindFirst(app_path, 0, FS_ATTR_DIR, &info, app_name_temp, MMI_AM_MAX_APP_FILE_NAME * ENCODE_BYTE);
        if (findfirst_hdl >= 0)
        {
            /* check short file name */
            if (info.NTReserved == FS_SFN_MATCH)
            {
                mmi_chset_mixed_text_to_ucs2_str(
                                                (PU8) app_file_name,
                                                MMI_AM_MAX_APP_FILE_NAME * ENCODING_LENGTH,
                                                (PU8) (app_path + MMI_AM_VRE_FOLDER_SIZE),
                                                PhnsetGetDefEncodingType());
            }
            else
            {
                mmi_wcscpy(app_file_name, (PU16) (app_path + MMI_AM_VRE_FOLDER_SIZE));
            }
            FS_FindClose(findfirst_hdl);
            findfirst_hdl = 0;
        }
#endif /* 0 */ 
#ifdef AM_TEST
        {
            memset(time_buf, 0, sizeof(time_buf));
            memset(time_buf_w, 0, sizeof(time_buf_w));
            sprintf(
                   time_buf,
                   "%d-%d-%d %d:%d:%d",
                   info.DateTime.Year1980 + 1980,
                   info.DateTime.Month,
                   info.DateTime.Day,
                   info.DateTime.Hour,
                   info.DateTime.Minute,
                   info.DateTime.Second2);
            mmi_asc_to_wcs(time_buf_w, (PS8) time_buf);
        }
#endif /* AM_TEST */ 
        file_result = FS_GetFileSize(file_hdl, &file_size);
        if (file_hdl < 0)
        {
            FS_Close(file_hdl);
            MMI_AM_ASSERT(0);
            return;
        }
        FS_Close(file_hdl);
        file_hdl = 0;
        file_size = file_size >> 10;    /* in KB as the unit */
        sprintf(file_size_buf, "%d k", file_size);
        mmi_asc_to_wcs(file_size_buf_w, (PS8) file_size_buf);

    }

    /* get desc info and phone number by vxp file */
    ret = mmi_am_get_info_by_tag(app_path, INFO_DESC, (void **)&temp_desc_buf, &temp_desc_size);
    if (!ret)
    {
        //mmi_display_popup_with_sg(GRP_ID_AM, (UI_string_type) get_string(STR_ID_AM_FILE_CORRUPT), MMI_EVENT_INFO, 0);
        //mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_DETAILS);
        //return;
    }

    /* get developer name by vxp file */
    ret = mmi_am_get_info_by_tag(app_path, INFO_DEV, (void **)&temp_developer_buf, &temp_developer_size);
    if (!ret)
    {
        //mmi_am_free(temp_desc_buf);
        //mmi_display_popup_with_sg(GRP_ID_AM, (UI_string_type) get_string(STR_ID_AM_FILE_CORRUPT), MMI_EVENT_INFO, 0);
        //mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_DETAILS);
        //return;
    }

    /* allocate memory using in details screen */
    desc_size =
    (mmi_ucs2strlen((PS8) GetString(STR_GLOBAL_FILENAME)) << 1) + CRLF_size
    + (mmi_ucs2strlen((PS8) app_file_name) << 1) + CRLF_size
#ifdef AM_TEST
    + (mmi_ucs2strlen((PS8) GetString(STR_GLOBAL_DATE)) << 1) + CRLF_size +
    (mmi_ucs2strlen((PS8) time_buf_w) << 1) + CRLF_size
#endif /* AM_TEST */ 
    + (mmi_ucs2strlen((PS8) GetString(STR_ID_AM_DETAILS_INFO)) << 1) + CRLF_size + temp_desc_size + CRLF_size + (mmi_ucs2strlen((PS8) GetString(STR_ID_AM_DETAILS_SIZE)) << 1) + CRLF_size + (mmi_ucs2strlen((PS8) file_size_buf_w) << 1) + CRLF_size + (mmi_ucs2strlen((PS8) GetString(STR_ID_AM_DETAILS_PATH)) << 1) + CRLF_size + (mmi_ucs2strlen((PS8) GetString(STR_ID_AM_DETAILS_STORAGE_MEMORY_CARD)) << 1) + CRLF_size + (mmi_ucs2strlen((PS8) GetString(STR_ID_AM_DETAILS_DEVELOPER)) << 1) + CRLF_size + temp_developer_size + CRLF_size  /* MMI_AM_DETAILS_DEV_NAME_SIZE + CRLF_size */
    + (mmi_ucs2strlen((PS8) GetString(STR_ID_AM_DETAILS_TEL)) << 1) + CRLF_size;
    desc_buf = (PU16) mmi_am_calloc(desc_size);
    if (!desc_buf)
    {
        mmi_am_free(temp_desc_buf);
        mmi_am_free(temp_developer_buf);
        MMI_AM_ASSERT(0);
        return;
    }

    if (!mmi_am_ms_is_rom_app(g_am_ms_cntx.hl_idx))
    {
        /* 1.1 build string - vxp file name title */
        mmi_wcscat(desc_buf, (PU16) GetString(STR_GLOBAL_FILENAME));
        mmi_wcscat(desc_buf, semi);
        mmi_wcscat(desc_buf, MMI_AM_DETAILS_NEWLINE);
        /* 1.2 build string - vxp file name content */
        mmi_wcscat(desc_buf, MMI_AM_DETAILS_SPACES);
        mmi_wcscat(desc_buf, app_file_name);
        mmi_wcscat(desc_buf, MMI_AM_DETAILS_NEWLINE);
#ifdef AM_TEST
        /* 1.2.1 build string - date title */
        mmi_wcscat(desc_buf, (PU16) GetString(STR_GLOBAL_DATE));
        mmi_wcscat(desc_buf, semi);
        mmi_wcscat(desc_buf, MMI_AM_DETAILS_NEWLINE);
        /* 1.2.2 build string - date content */
        mmi_wcscat(desc_buf, MMI_AM_DETAILS_SPACES);
        mmi_wcscat(desc_buf, time_buf_w);
        mmi_wcscat(desc_buf, MMI_AM_DETAILS_NEWLINE);
#endif /* AM_TEST */ 
    }
    /* 2.1 build string - App Info title */
    mmi_wcscat(desc_buf, (PU16) GetString(STR_ID_AM_DETAILS_INFO));
    mmi_wcscat(desc_buf, semi);
    mmi_wcscat(desc_buf, MMI_AM_DETAILS_NEWLINE);
    /* 2.2 build string - App Info content */
    if (temp_desc_buf)
    {
        p_desc = mmi_wcsstr(temp_desc_buf, MMI_AM_DETAILS_DESC);
        p_phone = mmi_wcsstr(temp_desc_buf, MMI_AM_DETAILS_PHONE);
        p_rank = mmi_wcsstr(temp_desc_buf, MMI_AM_DETAILS_RANK);
    }
    mmi_wcscat(desc_buf, MMI_AM_DETAILS_SPACES);
    if (p_desc && p_phone)
    {
        mmi_wcsncat(
                   desc_buf,
                   p_desc + mmi_ucs2strlen((PS8) MMI_AM_DETAILS_DESC),
                   p_phone - (p_desc + mmi_ucs2strlen((PS8) MMI_AM_DETAILS_DESC)) - 1);
    }
    mmi_wcscat(desc_buf, MMI_AM_DETAILS_NEWLINE);
    if (!mmi_am_ms_is_rom_app(g_am_ms_cntx.hl_idx))
    {
        /* 3.1 build string - App size title */
        mmi_wcscat(desc_buf, (PU16) GetString(STR_ID_AM_DETAILS_SIZE));
        mmi_wcscat(desc_buf, semi);
        mmi_wcscat(desc_buf, MMI_AM_DETAILS_NEWLINE);
        /* 3.2 build string - App size content */
        mmi_wcscat(desc_buf, MMI_AM_DETAILS_SPACES);
        mmi_wcscat(desc_buf, file_size_buf_w);
        mmi_wcscat(desc_buf, MMI_AM_DETAILS_NEWLINE);
    }
    /* 4.1 build string - App store path title */
    mmi_wcscat(desc_buf, (PU16) GetString(STR_ID_AM_DETAILS_PATH));
    mmi_wcscat(desc_buf, semi);
    mmi_wcscat(desc_buf, MMI_AM_DETAILS_NEWLINE);
    /* 4.2 build string - App store path content */
    mmi_wcscat(desc_buf, MMI_AM_DETAILS_SPACES);
    {
        if ((S8) (*app_path) == (S8) mmi_am_get_system_driver())
        {
            mmi_wcscat(desc_buf, (PU16) GetString(STR_ID_AM_DETAILS_STORAGE_PHONE));
        }
        else if ((S8) (*app_path) == (S8) mmi_am_get_removeable_driver())
        {
            mmi_wcscat(desc_buf, (PU16) GetString(STR_ID_AM_DETAILS_STORAGE_MEMORY_CARD));
        }
        else
        {
            mmi_wcscat(desc_buf, (PU16) GetString(STR_ID_AM_DETAILS_STORAGE_ROM));
        }
    }
    mmi_wcscat(desc_buf, MMI_AM_DETAILS_NEWLINE);
    /* 5.1 build string - Developer name title */
    mmi_wcscat(desc_buf, (PU16) GetString(STR_ID_AM_DETAILS_DEVELOPER));
    mmi_wcscat(desc_buf, semi);
    mmi_wcscat(desc_buf, MMI_AM_DETAILS_NEWLINE);
    /* 5.2 build string - Developer name content */
    mmi_wcscat(desc_buf, MMI_AM_DETAILS_SPACES);
    if (temp_developer_buf)
    {
        mmi_wcscat(desc_buf, temp_developer_buf);
    }
    mmi_wcscat(desc_buf, MMI_AM_DETAILS_NEWLINE);
    /* 6.1 build string - Developer tel title */
    mmi_wcscat(desc_buf, (PU16) GetString(STR_ID_AM_DETAILS_TEL));
    mmi_wcscat(desc_buf, semi);
    mmi_wcscat(desc_buf, MMI_AM_DETAILS_NEWLINE);
    /* 6.2 build string - Developer tel content */
    mmi_wcscat(desc_buf, MMI_AM_DETAILS_SPACES);
    if (p_phone && p_rank)
    {
        mmi_wcsncat(
                   desc_buf,
                   p_phone + mmi_ucs2strlen((PS8) MMI_AM_DETAILS_PHONE),
                   p_rank - (p_phone + mmi_ucs2strlen((PS8) MMI_AM_DETAILS_PHONE)) - 1);
    }
    mmi_wcscat(desc_buf, L"\0");

    /* release the temp memory */
    mmi_am_free(temp_desc_buf);
    mmi_am_free(temp_developer_buf);

    /* return buffer pointer and buffer size */
    *str_buf = (PU8) desc_buf;
    *buf_size = (S32) mmi_ucs2strlen((PS8) desc_buf);

    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_ds_prepare_data() ------- [E]");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_entry_settings_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_entry_settings_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    U8 *gui_buffer;
    U16 nitems;
    U16 itemlist[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_frm_scrn_enter(GRP_ID_AM, SCR_ID_AM_SETTINGS, mmi_am_eixt_settings_scrn, mmi_am_entry_settings_scrn, NULL);

    if (ret == MMI_FALSE)
    {
        return;
    }

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    /* regenerate list */
    mmi_am_ss_get_list(itemlist, &nitems);
    RegisterHighlightHandler(mmi_am_ss_highlight_hdlr);

    ShowCategory15Screen(STR_GLOBAL_SETTINGS,
#ifdef __MMI_FTE_SUPPORT__
                         0,
#else 
                         IMG_ID_AM_TITLE,
#endif 
                         STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, nitems, itemlist, (PU16) gIndexIconsImageList, LIST_MENU, 0,   /* default highlight item */
                         gui_buffer);

    /* delete Options Screen */
    mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_OPTIONS);

    SetLeftSoftkeyFunction(mmi_am_ss_lsk_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_eixt_settings_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_eixt_settings_scrn(void)
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
 *  mmi_am_ss_get_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  list            [OUT]       
 *  list_num        [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_ss_get_list(U16 *list, U16 *list_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* S32 index; */
    U16 item_num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_am_get_sim_card_num() == 2)
    {
        list[item_num++] = STR_ID_AM_SETTINGS_SIM;
    }

    if (mmi_am_is_support_wifi() && (mmi_am_get_sim_card_num() >= 1))
    {
        list[item_num++] = STR_ID_AM_SETTINGS_CONN;
    }

    *list_num = item_num;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_ss_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_ss_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type item_text;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item_text = get_item_text(index);

    if (mmi_wcscmp((U16*) item_text, (U16*) GetString(STR_ID_AM_SETTINGS_SIM)) == 0)
    {
        SetKeyHandler(mmi_am_entry_sim_settings_scrn, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#ifdef __MMI_TOUCH_SCREEN__
        wgui_register_list_item_selected_callback(mmi_am_entry_sim_settings_scrn);
#endif 
    }
    else if (mmi_wcscmp((U16*) item_text, (U16*) GetString(STR_ID_AM_SETTINGS_CONN)) == 0)
    {
        SetKeyHandler(mmi_am_entry_conn_settings_scrn, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#ifdef __MMI_TOUCH_SCREEN__
        wgui_register_list_item_selected_callback(mmi_am_entry_conn_settings_scrn);
#endif 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_ss_lsk_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_ss_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    UI_string_type item_text;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetHighlightedItem();
    item_text = get_item_text(index);

    if (mmi_wcscmp((U16*) item_text, (U16*) GetString(STR_ID_AM_SETTINGS_SIM)) == 0)
    {
        mmi_am_entry_sim_settings_scrn();
    }
    else if (mmi_wcscmp((U16*) item_text, (U16*) GetString(STR_ID_AM_SETTINGS_CONN)) == 0)
    {
        mmi_am_entry_conn_settings_scrn();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_entry_sim_settings_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_entry_sim_settings_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    U8 *gui_buffer;
    U16 highlight;
    U16 nitems = 2;
    U8 *itemlist[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_frm_scrn_enter(
                            GRP_ID_AM,
                            SCR_ID_AM_SETTINGS_SIM,
                            mmi_am_eixt_sim_settings_scrn,
                            mmi_am_entry_sim_settings_scrn,
                            NULL);

    if (ret == MMI_FALSE)
    {
        return;
    }

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    /* regenerate list */
    itemlist[0] = (U8*) GetString(STR_ID_AM_SIM_SETTINGS_SIM1);
    itemlist[1] = (U8*) GetString(STR_ID_AM_SIM_SETTINGS_SIM2);
    RegisterHighlightHandler(mmi_am_sss_highlight_hdlr);

    if (g_am_cntx.sim_settings == SIM_2)
    {
        highlight = 1;
    }
    else
    {
        highlight = 0;
    }

    ShowCategory36Screen(STR_ID_AM_SIM_SETTINGS_TITLE,
#ifdef __MMI_FTE_SUPPORT__
                         0,
#else 
                         IMG_ID_AM_TITLE,
#endif 
                         STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, nitems, itemlist, highlight,   /* default highlight item */
                         gui_buffer);

    SetLeftSoftkeyFunction(mmi_am_sss_lsk_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_eixt_sim_settings_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_eixt_sim_settings_scrn(void)
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
 *  mmi_am_sss_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_sss_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == 0)
    {
        SetKeyHandler(mmi_am_sss_set_sim1, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else if (index == 1)
    {
        SetKeyHandler(mmi_am_sss_set_sim2, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_sss_lsk_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_sss_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetHighlightedItem();

    if (index == 0)
    {
        mmi_am_sss_set_sim1();
    }
    else if (index == 1)
    {
        mmi_am_sss_set_sim2();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_sss_set_sim1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_sss_set_sim1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_am_set_sim_card(SIM_1))
    {
        mmi_display_popup_with_sg(GRP_ID_AM, (UI_string_type) get_string(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, 0);
        g_am_cntx.sim_settings = SIM_1;
    }
    else
    {
        mmi_display_popup_with_sg(GRP_ID_AM, (UI_string_type) get_string(STR_ID_AM_SET_FAILURE), MMI_EVENT_FAILURE, 0);
    }

    /* delete sim settings Screen */
    mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_SETTINGS_SIM);
    /* delete Settings Screen */
    mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_SETTINGS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_sss_set_sim2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_sss_set_sim2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_am_set_sim_card(SIM_2))
    {
        mmi_display_popup_with_sg(GRP_ID_AM, (UI_string_type) get_string(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, 0);
        g_am_cntx.sim_settings = SIM_2;
    }
    else
    {
        mmi_display_popup_with_sg(GRP_ID_AM, (UI_string_type) get_string(STR_ID_AM_SET_FAILURE), MMI_EVENT_FAILURE, 0);
    }

    /* delete sim settings Screen */
    mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_SETTINGS_SIM);
    /* delete Settings Screen */
    mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_SETTINGS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_entry_conn_settings_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_entry_conn_settings_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    U8 *gui_buffer;
    U16 highlight;
    U16 nitems = 2;
    U8 *itemlist[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_frm_scrn_enter(
                            GRP_ID_AM,
                            SCR_ID_AM_SETTINGS_CONN,
                            mmi_am_eixt_conn_settings_scrn,
                            mmi_am_entry_conn_settings_scrn,
                            NULL);

    if (ret == MMI_FALSE)
    {
        return;
    }

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    /* regenerate list */
    itemlist[0] = (U8*) GetString(STR_ID_AM_CONN_SETTINGS_GPRS);
    itemlist[1] = (U8*) GetString(STR_ID_AM_CONN_SETTINGS_WIFI);
    RegisterHighlightHandler(mmi_am_css_highlight_hdlr);

    if (g_am_cntx.conn_settings == WIFI)
    {
        highlight = 1;
    }
    else
    {
        highlight = 0;
    }

    ShowCategory36Screen(STR_ID_AM_CONN_SETTINGS_TITLE,
#ifdef __MMI_FTE_SUPPORT__
                         0,
#else 
                         IMG_ID_AM_TITLE,
#endif 
                         STR_GLOBAL_OK,
                         IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, nitems, itemlist, highlight, gui_buffer);

    SetLeftSoftkeyFunction(mmi_am_css_lsk_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_eixt_conn_settings_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_eixt_conn_settings_scrn(void)
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
 *  mmi_am_css_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_css_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == 0)
    {
        SetKeyHandler(mmi_am_css_set_gprs, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
    else if (index == 1)
    {
        SetKeyHandler(mmi_am_css_set_wifi, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_css_lsk_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_css_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetHighlightedItem();

    if (index == 0)
    {
        mmi_am_css_set_gprs();
    }
    else if (index == 1)
    {
        mmi_am_css_set_wifi();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_css_set_gprs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_css_set_gprs(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_am_set_net_type(GPRS))
    {
        mmi_display_popup_with_sg(GRP_ID_AM, (UI_string_type) get_string(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, 0);
        g_am_cntx.conn_settings = GPRS;
    }
    else
    {
        mmi_display_popup_with_sg(GRP_ID_AM, (UI_string_type) get_string(STR_ID_AM_SET_FAILURE), MMI_EVENT_FAILURE, 0);
    }

    /* delete conn settings Screen */
    mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_SETTINGS_CONN);
    /* delete Settings Screen */
    mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_SETTINGS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_css_set_wifi
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_css_set_wifi(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_am_set_net_type(WIFI))
    {
        mmi_display_popup_with_sg(GRP_ID_AM, (UI_string_type) get_string(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, 0);
        g_am_cntx.conn_settings = WIFI;
    }
    else
    {
        mmi_display_popup_with_sg(GRP_ID_AM, (UI_string_type) get_string(STR_ID_AM_SET_FAILURE), MMI_EVENT_FAILURE, 0);
    }

    /* delete conn settings Screen */
    mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_SETTINGS_CONN);
    /* delete Settings Screen */
    mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_SETTINGS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_entry_downloading_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_entry_downloading_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
/*Vogins_20100625_start*/
    U16 print_buf[20];
U8 temp_str[20];
/*Vogins_20100625_end*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
             MMI_FW_TRC_G1_FRM,
             TRC_MMI_AM_ENTRY_DOWNLOADING_SCRN_S,
             g_am_dl_cntx.is_start_download,
             g_am_dl_cntx.download_progress);

    if (g_am_dl_cntx.is_start_download)
    {
        S32 dl_ret;

        /* register memory api */
        mmi_am_vre_pre_download_app(mmi_am_calloc, mmi_am_free);

        dl_ret = mmi_am_vre_download_app(
                                        mmi_am_download_app_cb,
                                        (U32) g_am_dl_cntx.app_id,
                                        (PU16) g_am_dl_cntx.app_name,
                                        MMI_AM_DOWNLOAD_BLOCK_SIZE);
        MMI_AM_LOG(
                  MOD_MMI,
                  TRACE_GROUP_7,
                  "mmi_am_entry_downloading_scrn() -- dl_ret:%d;dl_app_id:%d",
                  dl_ret,
                  g_am_dl_cntx.app_id);

        if (dl_ret == MMI_AM_DL_OK)
        {
        	    VMUINT total_size = 0;
   			 VMUINT downloaded_size = 0;
		vm_get_total_and_downloaded_size(&total_size, &downloaded_size);    
            if (total_size != 0 && downloaded_size !=0)
            {
                g_am_dl_cntx.download_progress = (downloaded_size + g_am_dl_cntx.download_size) * 100/((VMUINT)g_am_dl_cntx.add_size);
                MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_download_app_cb() -- total_size:%d;downloaded_size:%d, precent:%d", total_size, downloaded_size, g_am_dl_cntx.download_progress);
                sprintf(
                       (char *)temp_str,
                       "%d K / %d K",
                       (downloaded_size+g_am_dl_cntx.download_size)/1024,
                       ((VMUINT)g_am_dl_cntx.add_size)/1024);
        	}
			//Shelley
		else if (g_am_dl_cntx.add_size!= 0)
		{
                g_am_dl_cntx.download_progress = (downloaded_size + g_am_dl_cntx.download_size) * 100/((VMUINT)g_am_dl_cntx.add_size);
                MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_download_app_cb() -have got all file sizes-- total_size:%d;downloaded_size:%d, precent:%d", total_size, downloaded_size, g_am_dl_cntx.download_progress);
                sprintf(
                       (char *)temp_str,
                       "%d K / %d K",
                       (downloaded_size+g_am_dl_cntx.download_size)/1024,
                       ((VMUINT)g_am_dl_cntx.add_size)/1024);
		}
		else if (downloaded_size == 0)
		{
                g_am_dl_cntx.download_progress = (downloaded_size + g_am_dl_cntx.download_size) * 100/((VMUINT)g_am_dl_cntx.add_size);
                MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_download_app_cb() -- total_size:%d;downloaded_size = 0 precent:%d", total_size, g_am_dl_cntx.download_progress);
                sprintf(
                       (char *)temp_str,
                       " waiting ... ");
		}
        }
        else
        {
            mmi_display_popup_with_sg(
                                     GRP_ID_AM,
                                     (UI_string_type) get_string(STR_ID_AM_DOWNLOAD_FAILURE),
                                     MMI_EVENT_FAILURE,
                                     0);

            MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_ENTRY_DOWNLOADING_SCRN_E1);
            return;
        }
    }
	else
	{
		sprintf(
                   (char *)temp_str,
                   "%d K / %d K",
                   0,
                   ((VMUINT)g_am_dl_cntx.add_size)/1024);
	}

    ret = mmi_frm_scrn_enter(
                            GRP_ID_AM,
                            SCR_ID_AM_DOWNLOAD_PROGRESS,
                            mmi_am_exit_downloading_scrn,
                            mmi_am_entry_downloading_scrn,
                            NULL);

    if (ret == MMI_FALSE)
    {
        mmi_am_vre_cancel_download();
        return;
    }

	mmi_asc_to_wcs(print_buf, (S8*)temp_str);
    /* gui_buffer = mmi_frm_scrn_get_active_gui_buf(); */
    ShowCategory402Screen((PU8) GetString(STR_GLOBAL_DOWNLOADING),
#ifdef __MMI_FTE_SUPPORT__
                          0,
#else 
                          IMG_ID_AM_TITLE,
#endif 
/*Vogins_20100625_start*/
                          0, 0, STR_GLOBAL_CANCEL, IMG_GLOBAL_BACK, NULL, (U16) g_am_dl_cntx.download_progress, (U8*)print_buf);
/*Vogins_20100625_end*/
#ifdef AM_09A
#ifdef __VRE_AM_08AB__
    SetDelScrnIDCallbackHandler(SCR_ID_AM_DOWNLOAD_PROGRESS, (HistoryDelCBPtr) mmi_am_destroy_downloading_scrn);
#else
    mmi_frm_set_destroy_scrn_callback(SCR_ID_AM_DOWNLOAD_PROGRESS, (HistoryDelCBPtr) mmi_am_destroy_downloading_scrn);
#endif
#else /* AM_09A */ 
    /* set leave proc */
    mmi_frm_scrn_set_leave_proc(GRP_ID_AM, SCR_ID_AM_DOWNLOAD_PROGRESS, mmi_am_leave_downloading_scrn);
#endif /* AM_09A */ 

	/*SZFAE*/
#ifdef AM_DOWNLOAD_CONFIRM
    SetRightSoftkeyFunction(mmi_am_dl_cancel_screen, KEY_EVENT_UP);
#else
    SetRightSoftkeyFunction(mmi_am_dl_cancel, KEY_EVENT_UP);
#endif
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_ENTRY_DOWNLOADING_SCRN_E2);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_exit_downloading_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_exit_downloading_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* when add downloading screen to history, cancel download, but save download progress */
    mmi_am_vre_cancel_download();
    //mmi_am_release_download(); //michael 0731

    //if (g_am_qs_cntx.is_download)
    //{
    //    mmi_am_download_app_from_mm_deinit();
    //}
}

    #ifdef AM_09A


/*****************************************************************************
 * FUNCTION
 *  mmi_am_destroy_downloading_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static U8 mmi_am_destroy_downloading_scrn(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_DOWNLOADING_SCRN_DESTROY_S);

    g_am_dl_cntx.is_start_download = MMI_FALSE;
    g_am_dl_cntx.is_start_downloading = MMI_FALSE;//michael 0731
    g_am_dl_cntx.download_progress = 0;
    mmi_am_vre_cancel_download();
    mmi_am_release_download(); //michael 0731
    if (g_am_qs_cntx.is_download)
    {
        mmi_am_download_app_from_mm_deinit();
    }

    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_DOWNLOADING_SCRN_DESTROY_E);
    return MMI_FALSE;
}
    #else /* AM_09A */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_am_leave_downloading_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_am_leave_downloading_scrn(mmi_event_struct *evt)
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
        g_am_dl_cntx.is_start_download = MMI_FALSE;
        g_am_dl_cntx.is_start_downloading = MMI_FALSE;//michael 0731
        g_am_dl_cntx.download_progress = 0;
        mmi_am_vre_cancel_download();
        mmi_am_release_download(); //michael 0731
        if (g_am_qs_cntx.is_download)
        {
            mmi_am_download_app_from_mm_deinit();
        }
        break;
    }

    return ret;
}
    #endif /* AM_09A */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_am_dl_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_dl_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_am_dl_cntx.app_id = 0;
    memset(g_am_dl_cntx.app_name, 0, sizeof(g_am_dl_cntx.app_name));
    g_am_dl_cntx.is_start_download = MMI_FALSE;
    g_am_dl_cntx.dl_app_driver = 0;
    g_am_dl_cntx.download_progress = 0;
/*Vogins_20100625_start*/
    g_am_dl_cntx.is_start_downloading = MMI_FALSE;//michael 0731
    g_am_dl_cntx.add_size = 0;
    g_am_dl_cntx.download_size = 0;
    g_am_dl_cntx.base_size = 0;
/*Vogins_20100625_end*/
/*Vogins_20100726_start*/
    g_am_filesize_cntx.dl_index = 0;
    g_am_download_list_cntx.strlength = 0;
    memset(g_am_download_list_cntx.pDownloadList, 0, sizeof(g_am_download_list_cntx.pDownloadList));
    g_am_dl_cntx.is_limit_dl_size = MMI_FALSE;
/*Vogins_20100726_end*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_dl_set_appid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_dl_set_appid(U32 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_am_dl_cntx.app_id = app_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_dl_get_appid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_am_dl_get_appid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_am_dl_cntx.app_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_dl_set_app_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_name        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_dl_set_app_name(U16 *app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_am_dl_cntx.app_name, 0, sizeof(g_am_dl_cntx.app_name));
    mmi_wcscpy(g_am_dl_cntx.app_name, app_name);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_dl_get_app_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 *mmi_am_dl_get_app_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_am_dl_cntx.app_name;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_am_dl_cancel_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 /*SZFAE*/	
#ifdef AM_DOWNLOAD_CONFIRM
void mmi_am_dl_cancel_screen(void)
{
	mmi_display_popup_confirm_with_sg(
	    GRP_ID_AM,
#ifdef __VRE_AM_08AB__
         STR_GLOBAL_YES,
         IMG_GLOBAL_YES,
         STR_GLOBAL_NO,
         IMG_GLOBAL_NO,
#else
         get_string(STR_GLOBAL_YES),
         get_image(IMG_GLOBAL_YES),
         get_string(STR_GLOBAL_NO),
         get_image(IMG_GLOBAL_NO),
#endif
		(UI_string_type) GetString(STR_ID_AM_DOWNLOAD_CONTINUE),
		MMI_EVENT_QUERY,
		0
		);
	
        SetRightSoftkeyFunction(mmi_am_dl_cancel, KEY_EVENT_UP);
	 SetLeftSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_am_dl_cancel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_dl_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_display_popup_with_sg(GRP_ID_AM, (UI_string_type) get_string(STR_ID_AM_DOWNLOAD_CANCEL), MMI_EVENT_INFO, 0);

    /* cancel download */
    mmi_am_vre_cancel_download();

    /* initialize download context */
/*Vogins_20100625_start*/
    mmi_am_release_download();
/*Vogins_20100625_end*/
    mmi_am_dl_init();
    mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_DOWNLOAD_PROGRESS);
/*SZFAE*/	
#ifdef AM_DOWNLOAD_CONFIRM
    GoBackHistory();	
#endif	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_download_pre_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_am_download_pre_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fs_ret = FS_NO_ERROR;
    FS_DiskInfo disk_info;
    U32 memory_card_free_space = 0, system_free_space = 0;
    S8 drv_asc[10];
    U16 drv_ucs[10];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(drv_asc, 0, sizeof(drv_asc));
    memset(drv_ucs, 0, sizeof(drv_ucs));

    /* check vre folder and create vre folder in Remove Drv and System Drv. */
    if (!mmi_am_check_vre_folder())
    {
        mmi_display_popup_with_sg(
                                 GRP_ID_AM,
                                 (UI_string_type) get_string(STR_GLOBAL_NOT_ENOUGH_MEMORY),
                                 MMI_EVENT_FAILURE,
                                 0);
        MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_download_pre_check() -- create vre folder failure");
        return MMI_FALSE;
    }

    /* check whether has enough space. */
    sprintf(drv_asc, "%c:\\", mmi_am_get_removeable_driver());
    mmi_asc_to_wcs(drv_ucs, (PS8) drv_asc);
    fs_ret = FS_GetDiskInfo((kal_uint16*) drv_ucs, &disk_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
    if (fs_ret >= FS_NO_ERROR)
    {
        memory_card_free_space = disk_info.FreeClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;
    }

    memset(drv_asc, 0, sizeof(drv_asc));
    memset(drv_ucs, 0, sizeof(drv_ucs));
    sprintf(drv_asc, "%c:\\", mmi_am_get_system_driver());
    mmi_asc_to_wcs(drv_ucs, (PS8) drv_asc);
    fs_ret = FS_GetDiskInfo((kal_uint16*) drv_ucs, &disk_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
    if (fs_ret >= FS_NO_ERROR)
    {
        system_free_space = disk_info.FreeClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;
    }

    MMI_AM_LOG(
              MOD_MMI,
              TRACE_GROUP_7,
              "memory_card_free_space:%dK, system_free_space:%dK",
              memory_card_free_space / 1024,
              system_free_space / 1024);

    /* popup "Not enough memory" */
    if (memory_card_free_space < MMI_AM_DOWNLOAD_BLOCK_SIZE && system_free_space < MMI_AM_DOWNLOAD_BLOCK_SIZE)
    {
        mmi_display_popup_with_sg(
                                 GRP_ID_AM,
                                 (UI_string_type) get_string(STR_GLOBAL_NOT_ENOUGH_MEMORY),
                                 MMI_EVENT_FAILURE,
                                 0);
        MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_download_pre_check() -- free space less than 25K");
        return MMI_FALSE;
    }

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_am_continue_download_app
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nResult         [IN]        
 *  nPercent        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_continue_download_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 ret, index;
    U32 dl_app_id;
    U16 file_name[MMI_AM_MAX_SHORTCUT_APP_NAME];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_am_filesize_cntx.dl_index++;
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_continue_download_app -------------------[S]");
    MMI_ASSERT(g_am_filesize_cntx.dl_index < g_am_filesize_cntx.file_count);
    mmi_am_get_dl_app_id_and_name(&dl_app_id, file_name);
    
    ret = mmi_am_vre_download_app(mmi_am_download_app_cb, (U32) dl_app_id, (PU16) file_name, MMI_AM_DOWNLOAD_BLOCK_SIZE);
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_download_app_cb() -- ret:%d;dl_app_id:%d", ret, dl_app_id);
    if (ret == MMI_AM_DL_OK)
    {
        mmi_am_dl_set_appid(dl_app_id);
        mmi_am_dl_set_app_name(file_name);
    }
    else
    {
        mmi_display_popup_with_sg(
                                 GRP_ID_AM,
                                 (UI_string_type) get_string(STR_ID_AM_DOWNLOAD_FAILURE),
                                 MMI_EVENT_FAILURE,
                                 0);
        mmi_am_vre_cancel_download();
	 mmi_am_release_download();
        mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_DOWNLOAD_PROGRESS);
    }

	MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_continue_download_app -------------------[E]");

}
/*****************************************************************************
 * FUNCTION
 *  mmi_am_download_app_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nResult         [IN]        
 *  nPercent        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_download_app_cb(S32 nResult, S32 nPercent)
{
/*Vogins_20100625_start*/
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp_str[20];
    U16 print_buf[20];
    VMUINT total_size = 0;
    VMUINT downloaded_size = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_download_app_cb() ------- [S]");

    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_SCREENS_DOWNLOAD_CB, nResult, nPercent, g_am_dl_cntx.is_start_download);
    switch (nResult)
    {
    case MMI_AM_DL_DONE:

            MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "VAM_DL_DONE - dl_app_driver:%d", nPercent);
            /* update progress*/
	     g_am_dl_cntx.download_size += (g_am_filesize_cntx.dl_file_list[g_am_filesize_cntx.dl_index].file_size);
            g_am_dl_cntx.download_progress = ((VMUINT)g_am_dl_cntx.download_size) * 100/((VMUINT)g_am_dl_cntx.add_size);     
            sprintf(
                   (char *)temp_str,
                   "%d K / %d K",
                   ((VMUINT)g_am_dl_cntx.download_size)/1024,
                   ((VMUINT)g_am_dl_cntx.add_size)/1024);
            mmi_asc_to_wcs(print_buf, (S8*)temp_str);
            UpdateCategory402Value((U16) g_am_dl_cntx.download_progress, (U8*)print_buf);

            /* get save driver */
            g_am_dl_cntx.dl_app_driver = (S8) nPercent;

            /* if downloaded app is AppStore, then delete phsh.vxp and modify phsh.pht to phsh.vxp */
            if (strcmp((PS8)g_am_filesize_cntx.dl_file_list[g_am_filesize_cntx.dl_index].file_id, "appstore") == 0)
            {
                mmi_am_download_as_post_operation();
            		if(g_am_filesize_cntx.dl_index != g_am_filesize_cntx.file_count - 1)
    			{
    				mmi_am_ms_set_app_download(0, g_am_dl_cntx.dl_app_driver);
    			}
            }
	     if(g_am_filesize_cntx.dl_index == g_am_filesize_cntx.file_count - 1)
	     {
	     	     if(strcmp((PS8)g_am_filesize_cntx.dl_file_list[g_am_filesize_cntx.dl_index].file_id, "sm_billing") != 0)
	     	     {
	     	     		//mmi_am_release_download();
            mmi_am_download_app_done();
        }
			else
			{
				 mmi_display_popup_with_sg(
                                     GRP_ID_AM,
                                     (UI_string_type) get_string(STR_GLOBAL_NOT_ENOUGH_MEMORY),
                                     MMI_EVENT_FAILURE,
                                     0);
				 mmi_am_release_download();
			}
	     }
        else
        {
            gui_start_timer(10, mmi_am_continue_download_app);
        }

        break;
    case MMI_AM_DL_OK:
        MMI_AM_LOG(
                  MOD_MMI,
                  TRACE_GROUP_7,
                  "MMI_AM_DL_OK -- is_start_download:%d;nPercent:%d",
                  g_am_dl_cntx.is_start_download,
                  nPercent);
        if (!g_am_dl_cntx.is_start_download)
        {
            g_am_dl_cntx.is_start_downloading = MMI_TRUE;//michael 0731
            mmi_am_entry_downloading_scrn();
            g_am_dl_cntx.is_start_download = MMI_TRUE;
        }
        else
        {
            vm_get_total_and_downloaded_size(&total_size, &downloaded_size);    
            if (total_size != 0 && downloaded_size !=0)
            {
                g_am_dl_cntx.download_progress = (downloaded_size + g_am_dl_cntx.download_size) * 100/((VMUINT)g_am_dl_cntx.add_size);
                MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_download_app_cb() -- total_size:%d;downloaded_size:%d, precent:%d", total_size, downloaded_size, g_am_dl_cntx.download_progress);
                sprintf(
                       (char *)temp_str,
                       "%d K / %d K",
                       (downloaded_size+g_am_dl_cntx.download_size)/1024,
                       ((VMUINT)g_am_dl_cntx.add_size)/1024);
                mmi_asc_to_wcs(print_buf, (S8*)temp_str);
                MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_download_app_cb() -- %s", temp_str);
                UpdateCategory402Value((U16) g_am_dl_cntx.download_progress, (U8*)print_buf);
            }
        
		//Shelley
		else if (g_am_dl_cntx.add_size!= 0)
		{
                g_am_dl_cntx.download_progress = (downloaded_size + g_am_dl_cntx.download_size) * 100/((VMUINT)g_am_dl_cntx.add_size);
                MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_download_app_cb() -have got all file sizes-- total_size:%d;downloaded_size:%d, precent:%d", total_size, downloaded_size, g_am_dl_cntx.download_progress);
                sprintf(
                       (char *)temp_str,
                       "%d K / %d K",
                       (downloaded_size+g_am_dl_cntx.download_size)/1024,
                       ((VMUINT)g_am_dl_cntx.add_size)/1024);
		}
		else if (downloaded_size == 0)
		{
                g_am_dl_cntx.download_progress = (downloaded_size + g_am_dl_cntx.download_size) * 100/((VMUINT)g_am_dl_cntx.add_size);
                MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_download_app_cb() -- total_size:%d;downloaded_size = 0 precent:%d", total_size, g_am_dl_cntx.download_progress);
                sprintf(
                       (char *)temp_str,
                       " waiting ... ");
		}
        }
/*Vogins_20100625_end*/
        break;
    case MMI_AM_DL_SPACE_FULL:
        MMI_AM_LOG(
                  MOD_MMI,
                  TRACE_GROUP_7,
                  "VAM_DL_SPACE_FULL -- is_start_download:%d;nPercent:%d",
                  g_am_dl_cntx.is_start_download,
                  nPercent);
        if (g_am_dl_cntx.is_start_download)
        {
            mmi_display_popup_with_sg(
                                     GRP_ID_AM,
                                     (UI_string_type) get_string(STR_GLOBAL_NOT_ENOUGH_MEMORY),
                                     MMI_EVENT_FAILURE,
                                     0);
            mmi_am_vre_cancel_download();
	     mmi_am_release_download();
            mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_DOWNLOAD_PROGRESS);
        }
        break;
    case MMI_AM_DL_IO_ERROR:
        MMI_AM_LOG(
                  MOD_MMI,
                  TRACE_GROUP_7,
                  "MMI_AM_DL_IO_ERROR -- is_start_download:%d;nPercent:%d",
                  g_am_dl_cntx.is_start_download,
                  nPercent);
        if (g_am_dl_cntx.is_start_download)
        {
            mmi_display_popup_with_sg(
                                     GRP_ID_AM,
                                     (UI_string_type) get_string(STR_ID_AM_DOWNLOAD_FAILURE),
                                     MMI_EVENT_FAILURE,
                                     0);
            mmi_am_vre_cancel_download();
		mmi_am_release_download();
            mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_DOWNLOAD_PROGRESS);
        }
        break;
    case MMI_AM_DL_ERR:
    case MMI_AM_DL_NET_ERR:
    case MMI_AM_DL_SAVE_ERR:
    case MMI_AM_DL_OTHER_ERR:
    case MMI_AM_DL_APP_NOT_EXIST:
    case MMI_AM_DL_FILE_NOT_EXIST:
        MMI_AM_LOG(
                  MOD_MMI,
                  TRACE_GROUP_7,
                  "VAM_DL_ -- is_start_download:%d;nResult:%d;nPercent:%d",
                  g_am_dl_cntx.is_start_download,
                  nResult,
                  nPercent);
        if (!g_am_dl_cntx.is_start_download)
        {
            mmi_display_popup_with_sg(
                                     GRP_ID_AM,
                                     (UI_string_type) get_string(STR_ID_AM_DOWNLOAD_FAILURE),
                                     MMI_EVENT_FAILURE,
                                     0);
        }
        else
        {
            mmi_display_popup_with_sg(
                                     GRP_ID_AM,
                                     (UI_string_type) get_string(STR_ID_AM_DOWNLOAD_FAILURE),
                                     MMI_EVENT_FAILURE,
                                     0);
        }
        mmi_am_vre_cancel_download();
	mmi_am_release_download();	
        mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_DOWNLOAD_PROGRESS);
        break;
/*Vogins_20100625_start*/
    case MMI_AM_DL_1302_ERR:
    case MMI_AM_DL_1401_ERR:
    case MMI_AM_DL_1402_ERR:
    case MMI_AM_DL_1403_ERR:
    case MMI_AM_DL_1404_ERR:
    case MMI_AM_DL_1405_ERR:
    case MMI_AM_DL_1406_ERR:
    case MMI_AM_DL_1407_ERR:
        MMI_AM_LOG(
                  MOD_MMI,
                  TRACE_GROUP_7,
                  "VAM_DL_ -- is_start_download:%d;nResult:%d;nPercent:%d",
                  g_am_dl_cntx.is_start_download,
                  nResult,
                  nPercent);
        if (!g_am_dl_cntx.is_start_download)
        {
            mmi_display_popup_with_sg(
                                     GRP_ID_AM,
                                     (UI_string_type) get_string(STR_ID_AM_DOWNLOAD_1302_ERR + nResult - MMI_AM_DL_1302_ERR),
                                     MMI_EVENT_FAILURE,
                                     0);
        }
        else
        {
            mmi_display_popup_with_sg(
                                     GRP_ID_AM,
                                     (UI_string_type) get_string(STR_ID_AM_DOWNLOAD_1302_ERR + nResult - MMI_AM_DL_1302_ERR),
                                     MMI_EVENT_FAILURE,
                                     0);
        }
        mmi_am_vre_cancel_download();
	mmi_am_release_download();	
        mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_DOWNLOAD_PROGRESS);
        break;
/*Vogins_20100625_end*/

    default:
        break;
    }

    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_download_app_cb() ------- [E]");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_download_app_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_download_app_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 temp_path[MMI_AM_MAX_SHORTCUT_APP_FILE_PATH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_DOWNLOAD_APP_DONE_S, g_am_qs_cntx.is_quick_start);

    memset(temp_path, 0, sizeof(temp_path));
    //mmi_am_release_download(); //michael 0731
    if (g_am_qs_cntx.is_quick_start)
    {
        /* Set app path */
        sprintf(
               temp_path,
               "%c:\\%s\\%s",
               g_am_dl_cntx.dl_app_driver,
               MMI_AM_VRE_HOME_DIR,
               mmi_am_config_get_mm_sc_name_by_appid(g_am_qs_cntx.app_id)
               );
        mmi_asc_to_wcs(g_am_qs_cntx.path, (PS8) temp_path);

        mmi_am_release_download(); //michael 0731
        mmi_am_download_from_mm_entry_confirm_scrn();

        /* close downloading screen */
        mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_DOWNLOAD_PROGRESS);
        return;
    }
    else
    {
        /* update App Status and set app path */
        mmi_am_ms_set_app_download(g_am_ms_cntx.hl_idx, g_am_dl_cntx.dl_app_driver);
    }

    mmi_am_release_download(); //michael 0731
    /* ask user if wish to launch the app */
    mmi_display_popup_confirm_with_sg(
                                     GRP_ID_AM,
#ifdef __VRE_AM_08AB__
                                     STR_GLOBAL_YES,
                                     IMG_GLOBAL_YES,
                                     STR_GLOBAL_NO,
                                     IMG_GLOBAL_NO,
#else
                                     get_string(STR_GLOBAL_YES),
                                     get_image(IMG_GLOBAL_YES),
                                     get_string(STR_GLOBAL_NO),
                                     get_image(IMG_GLOBAL_NO),
#endif
                                     get_string(STR_ID_AM_DOWNLOAD_DONE),
                                     MMI_EVENT_QUERY,
                                     0);

    SetLeftSoftkeyFunction(mmi_am_download_app_done_accept, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_am_download_app_done_goback, KEY_EVENT_UP);

    /* close downloading screen */
    mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_DOWNLOAD_PROGRESS);

    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_DOWNLOAD_APP_DONE_E);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_download_app_done_accept
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_download_app_done_accept(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_download_app_done_accept() ------- [S]");

    mmi_am_os_app_launch();

    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_download_app_done_accept() ------- [E]");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_download_app_done_goback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_download_app_done_goback(void)
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
 *  mmi_am_download_as_post_operation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_download_as_post_operation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fd = -1;
    S8 temp_path[MMI_AM_MAX_SHORTCUT_APP_FILE_PATH];
    U16 temp_path_w[MMI_AM_MAX_SHORTCUT_APP_FILE_PATH];
    S8 as_path[MMI_AM_MAX_SHORTCUT_APP_FILE_PATH];
    U16 as_path_w[MMI_AM_MAX_SHORTCUT_APP_FILE_PATH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_download_as_post_operation() ------- [S]");

    memset(temp_path, 0, sizeof(temp_path));
    memset(temp_path_w, 0, sizeof(temp_path_w));
    memset(as_path, 0, sizeof(as_path));
    memset(as_path_w, 0, sizeof(as_path_w));

    /* set phsh.pht path */
    sprintf(temp_path, "%c:\\%s\\%s", g_am_dl_cntx.dl_app_driver, MMI_AM_VRE_HOME_DIR, MMI_AM_AS_TEMP_FILE_NAME);
    mmi_asc_to_wcs(temp_path_w, (PS8) temp_path);

    /* set phsh.vxp path */
    sprintf(
           as_path,
           "%c:\\%s\\%s",
           g_am_dl_cntx.dl_app_driver,
           MMI_AM_VRE_HOME_DIR,
           mmi_am_config_get_am_sc_name_by_appid(APPID_VAS));
    mmi_asc_to_wcs(as_path_w, (PS8) as_path);

    /* delete folder named as phsh.vxp */
    if ((fd = FS_Open(as_path_w, FS_OPEN_DIR | FS_READ_ONLY)) >= FS_NO_ERROR)
    {
        MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_download_as_post_opeation() -- folder phsh.vxp is found");

        /* folder phsh.vxp exist */
        FS_Close(fd);
        FS_RemoveDir(as_path_w);
    }

    /* search phsh.pht */
    if ((fd = FS_Open(temp_path_w, FS_OPEN_NO_DIR | FS_READ_ONLY)) >= FS_NO_ERROR)
    {
        MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_download_as_post_opeation() -- phsh.pht is found");

        /* phsh.pht exist */
        FS_Close(fd);
        FS_Rename(temp_path_w, as_path_w);
    }

    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_download_as_post_operation() ------- [E]");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_entry_update_cdr_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_entry_update_cdr_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_frm_scrn_enter(GRP_ID_AM, SCR_ID_AM_UPDATE_CDR, mmi_am_exit_update_cdr_scrn, NULL, NULL);

    if (ret == MMI_FALSE)
    {
        return;
    }

    ShowCategory165Screen_ext(
                             STR_GLOBAL_OK,
                             IMG_GLOBAL_OK,
                             STR_GLOBAL_CANCEL,
                             IMG_GLOBAL_BACK,
                             get_string(STR_ID_AM_CDR_NEW_VERSION),
                             0,//IMG_GLOBAL_INFO,
                             5,
                             NULL);

    SetCat165TimerExpireFunc(mmi_am_cdr_update_accept);

    SetLeftSoftkeyFunction(mmi_am_cdr_update_accept, KEY_EVENT_UP);
    /* vogins 20100629 begin*/
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    /* vogins 20100629 end*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_exit_update_cdr_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_exit_update_cdr_scrn(void)
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
 *  mmi_am_cdr_update_accept
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/*Vogins_20100625_start*/
void mmi_am_cdr_update_accept(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_am_vre_sync_cdr(mmi_am_cdr_update_cb);
    /* vogins 20100629 begin*/
    /* vogins 20100629 end*/
    if (ret == MMI_AM_DL_OK)
    {
        //mmi_display_popup_confirm_with_sg(
        //    GRP_ID_AM,
        //    NULL,
        //    NULL,
        //    NULL,
        //    NULL,
        //    get_string(STR_GLOBAL_PLEASE_WAIT),
        //    MMI_EVENT_PROGRESS,
        //    0);
#ifdef AM_UPDATE_NOTIFY
         mmi_am_entry_update_cdr_wait_scrn();
#endif
    }
    else
    {
#ifdef AM_UPDATE_NOTIFY
        mmi_display_popup_with_sg(
            GRP_ID_AM,
            (UI_string_type) get_string(STR_ID_AM_CDR_UPDATE_FAIL),
            MMI_EVENT_FAILURE,
            0);
#endif
    }
}
/*Vogins_20100625_end*/

/*****************************************************************************
 * FUNCTION
 *  mmi_am_entry_update_cdr_wait_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_entry_update_cdr_wait_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_frm_scrn_enter(GRP_ID_AM, SCR_ID_AM_UPDATE_CDR_WAIT, mmi_am_exit_update_cdr_wait_scrn, NULL, NULL);

    if (ret == MMI_FALSE)
    {
        return;
    }

    ShowCategory63Screen((U8*) GetString(STR_GLOBAL_PLEASE_WAIT), IMG_GLOBAL_PROGRESS, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_exit_update_cdr_wait_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_exit_update_cdr_wait_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* cancel cdr update */
    mmi_am_vre_sync_cdr_cancel();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_cdr_update_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nResult     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_cdr_update_cb(S32 nResult)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_UPDATE_CDR_CB, nResult);
/*Vogins_20100625_start*/
    if (nResult == 0)
    {
#ifdef AM_UPDATE_NOTIFY
               mmi_display_popup_with_sg(
                   GRP_ID_AM,
                   (UI_string_type) get_string(STR_ID_AM_CDR_UPDATE_SUCC),
                   MMI_EVENT_SUCCESS,
                   0);
#endif          
    }
    else
    {
#ifdef AM_UPDATE_NOTIFY
            mmi_display_popup_with_sg(
                GRP_ID_AM,
                (UI_string_type) get_string(STR_ID_AM_CDR_UPDATE_FAIL),
                MMI_EVENT_FAILURE,
                0);
#endif 
    }
/*Vogins_20100625_end*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_download_from_mm_entry_confirm_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_download_from_mm_entry_confirm_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_DOWNLOAD_FROM_MM_ENTRY_CONFIRM_SCRN_S);

    ret = mmi_frm_scrn_enter(
                            GRP_ID_AM,
                            SCR_ID_AM_DOWNLOAD_FROM_MM_CONFIRM,
                            mmi_am_download_from_mm_exit_confirm_scrn,
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
                         (UI_string_type) GetString(STR_ID_AM_DOWNLOAD_DONE), 
                         (U16) IMG_GLOBAL_QUESTION, 
                         NULL);
#ifdef AM_09A
    SetDelScrnIDCallbackHandler(SCR_ID_AM_DOWNLOAD_FROM_MM_CONFIRM, (HistoryDelCBPtr) mmi_am_del_download_from_mm_scrn);
#else /* AM_09A */ 
    /* set leave proc */
    mmi_frm_scrn_set_leave_proc(GRP_ID_AM, SCR_ID_AM_DOWNLOAD_FROM_MM_CONFIRM, mmi_am_leave_download_from_mm_scrn);
#endif /* AM_09A */ 

    SetLeftSoftkeyFunction(mmi_am_download_app_from_mm_done_accept, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_am_download_app_from_mm_done_close, KEY_EVENT_UP);

    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_DOWNLOAD_FROM_MM_ENTRY_CONFIRM_SCRN_E);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_download_from_mm_exit_confirm_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_download_from_mm_exit_confirm_scrn(void)
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
 *  mmi_am_download_app_from_mm_done_accept
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_download_app_from_mm_done_accept(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    //g_am_cntx.start_state = START_BEGIN;
    g_am_qs_cntx.is_quick_start = MMI_TRUE;
    mmi_am_entry_loading_scrn();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_download_app_from_mm_done_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_download_app_from_mm_done_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_frm_scrn_close_active_id();
    //mmi_am_download_app_from_mm_deinit();
}

    #ifdef AM_09A


/*****************************************************************************
 * FUNCTION
 *  mmi_am_del_download_from_mm_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static U8 mmi_am_del_download_from_mm_scrn(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //mmi_am_download_app_from_mm_deinit();
    return MMI_FALSE;
}
    #else /* AM_09A */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_am_leave_download_from_mm_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_am_leave_download_from_mm_scrn(mmi_event_struct *evt)
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
        //mmi_am_download_app_from_mm_deinit();
        break;

    case EVT_ID_SCRN_DEINIT:
        break;
    }

    return ret;
}
    #endif /* AM_09A */ 
/*****************************************************************************
 * FUNCTION
 *  mmi_am_fill_data_into_item
 * DESCRIPTION
 *  Set account data to display
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_fill_data_into_item(mmi_am_apn_info *apn_info)
{
    U8 temp_port[4],i,j = 0,len,pos=0;
    S32 port;
    S8 *point = apn_info->proxy_ip;
    if (g_mmi_am_display_dtcnt.use_proxy == 0)
    {
        mmi_asc_to_ucs2((PS8) g_mmi_am_display_dtcnt.APN, (PS8) apn_info->apn_proxy);
        mmi_asc_to_ucs2((PS8) g_mmi_am_display_dtcnt.UserName, (PS8) apn_info->wap_user_name);
        mmi_asc_to_ucs2((PS8) g_mmi_am_display_dtcnt.Passwd, (PS8) apn_info->wap_pass_word);
    }
    else
    {
        mmi_asc_to_ucs2((PS8) g_mmi_am_display_dtcnt.APN, (PS8) apn_info->apn_no_proxy);
        mmi_asc_to_ucs2((PS8) g_mmi_am_display_dtcnt.UserName, (PS8) apn_info->net_user_name);
        mmi_asc_to_ucs2((PS8) g_mmi_am_display_dtcnt.Passwd, (PS8) apn_info->net_pass_word);
    }
    sprintf((S8*)temp_port,"%d",apn_info->proxy_port);
    mmi_asc_to_ucs2((PS8)g_mmi_am_display_dtcnt.proxy_port,(S8*)temp_port);
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "am proxy ip: %s",point);
    len = strlen(point);
    for (i=0; i < len; i++)
    {
        if (*point++ != '.')
        {
            if (*point == '\0' && j == 3)
            {
                strncpy((S8*)temp_port,apn_info->proxy_ip+pos,i-pos+1);
                temp_port[i-pos+1] = '\0';
                mmi_asc_to_ucs2((PS8) g_mmi_am_display_dtcnt.GPRSIP4,(S8*)temp_port);
            }
        }
        else
        {
            strncpy((S8*)temp_port,apn_info->proxy_ip+pos,i-pos);
            temp_port[i-pos] = '\0';
            if (j == 0)
            {
                mmi_asc_to_ucs2((PS8) g_mmi_am_display_dtcnt.GPRSIP1,(S8*)temp_port);
                pos = i+1;
            }
            else if (j==1)
            {
                mmi_asc_to_ucs2((PS8) g_mmi_am_display_dtcnt.GPRSIP2,(S8*)temp_port);
                pos = i+1;
            }
            else if (j==2)
            {
                mmi_asc_to_ucs2((PS8) g_mmi_am_display_dtcnt.GPRSIP3,(S8*)temp_port);
                pos = i+1;
            }
            j++;
        }
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_am_init_data_account
 * DESCRIPTION
 *  Set account data to display
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_init_data_account(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 port = 0;
    U8 i, ImageLocation = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_mmi_am_display_dtcnt.APN, 0, sizeof(g_mmi_am_display_dtcnt.APN));
    memset(g_mmi_am_display_dtcnt.UserName, 0, sizeof(g_mmi_am_display_dtcnt.UserName));
    memset(g_mmi_am_display_dtcnt.Passwd, 0, sizeof(g_mmi_am_display_dtcnt.Passwd));

    g_mmi_am_display_dtcnt.IsChangeProxy = 0;
    g_mmi_am_display_dtcnt.use_proxy = 0;
    g_mmi_am_display_dtcnt.use_proxy_option_str[0] = (U8*) GetString(STR_GLOBAL_YES);
    g_mmi_am_display_dtcnt.use_proxy_option_str[1] = (U8*) GetString(STR_GLOBAL_NO);

    ReturnThreeDigitString(g_mmi_am_display_dtcnt.GPRSIP1, 0);
    ReturnThreeDigitString(g_mmi_am_display_dtcnt.GPRSIP2, 0);
    ReturnThreeDigitString(g_mmi_am_display_dtcnt.GPRSIP3, 0);
    ReturnThreeDigitString(g_mmi_am_display_dtcnt.GPRSIP4, 0);

    for (i = 0; i < MAX_INLINE_ITEM_AM_DATA_ACCOUNT_LIST; i++)
    {
        if (i % 2)
        {
            g_mmi_am_display_dtcnt.IconList[i] = 0;
        }
        else
        {
            g_mmi_am_display_dtcnt.IconList[i] = IMG_GLOBAL_L1 + ImageLocation;
            ImageLocation++;
        }
    }    
}
/*****************************************************************************
 * FUNCTION
 *  mmi_am_exit_edit
 * DESCRIPTION
 *  exit handler for GPRS account edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_exit_edit(void)
{
#ifdef AM_09A
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    history h;
    U16 inputBufferSize;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CloseCategory57Screen();
    h.scrnID = SCR_ID_AM_DATA_ACCOUNT_EDIT;
    h.entryFuncPtr = mmi_am_entry_dataaccount_edit;
    GetCategoryHistory(h.guiBuffer);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);
#else
#endif
}
/*****************************************************************************
 * FUNCTION
 *  mmi_am_entry_dataaccount_screen
 * DESCRIPTION
 *  GPRS account editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_entry_dataaccount_screen_cb(S8 result)
{
    mmi_am_fill_data_into_item(&g_mmi_am_apn_info);
    mmi_am_entry_dataaccount_edit();
}
void mmi_am_entry_dataaccount_screen(void)
{
    mmi_am_init_data_account();
    mmi_am_check_apn_status(&g_mmi_am_apn_info,mmi_am_entry_dataaccount_screen_cb);
    //mmi_am_fill_data_into_item(&g_mmi_am_apn_info);
    //mmi_am_entry_dataaccount_edit();
}
/*****************************************************************************
 * FUNCTION
 *  mmi_am_entry_dataaccount_screen_auto
 * DESCRIPTION
 *  GPRS account editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_entry_dataaccount_screen_auto(void)
{
    mmi_am_init_data_account();    
    mmi_am_entry_dataaccount_edit();
}
/*****************************************************************************
 * FUNCTION
 *  mmi_am_backhistory_from_dcnt
 * DESCRIPTION
 *  free buffer and gobackhistory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_backhistory_from_dcnt(void)
{
    mmi_frm_scrn_close_active_id();
    mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_DATA_ACCOUNT_EDIT);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_am_entry_dataaccount_edit
 * DESCRIPTION
 *  GPRS account editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_entry_dataaccount_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *inputBuffer;    /* added for inline edit history */
    U8 *guiBuffer;      /* Buffer holding history data */
    U16 inputBufferSize;
    U16 title_id = STR_GLOBAL_EDIT;
    MMI_BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_frm_scrn_enter(GRP_ID_AM, SCR_ID_AM_DATA_ACCOUNT_EDIT, mmi_am_exit_edit, 
                             #ifdef AM_09A
                             NULL,
                             #else
                             mmi_am_entry_dataaccount_edit, 
                             #endif
                             NULL);

    if (ret == MMI_FALSE)
    {
        return;
    }

    InitializeCategory57Screen();

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    //guiBuffer = GetCurrGuiBuffer(SCR_ID_AM_DATA_ACCOUNT_EDIT);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_AM_DATA_ACCOUNT_EDIT, &inputBufferSize);        /* added for inline edit history */

    mmi_am_data_account_fillInline_struct();
    RegisterHighlightHandler(mmi_am_editor_highlight_hdlr);
    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, MAX_INLINE_ITEM_AM_DATA_ACCOUNT_LIST, inputBuffer);
    }

    if (mmi_am_VerifyDataAcountChanges() && GetInlineDoneFlag(guiBuffer) == 0)
    {
        SetInlineDoneFlag(guiBuffer);
    }

    ShowCategory57Screen(
                        title_id,
                        IMG_ID_AM_TITLE,
                        STR_GLOBAL_EDIT,
                        IMG_GLOBAL_OK,
                        STR_GLOBAL_BACK,
                        IMG_GLOBAL_BACK,
                        MAX_INLINE_ITEM_AM_DATA_ACCOUNT_LIST,
                        g_mmi_am_display_dtcnt.IconList,
                        wgui_inline_items,
                        0,
                        guiBuffer);
#ifdef AM_09A
#ifdef __VRE_AM_08AB__
    SetDelScrnIDCallbackHandler(SCR_ID_AM_DATA_ACCOUNT_EDIT, (HistoryDelCBPtr) mmi_am_destroy_dcnt_scrn);
#else
    mmi_frm_set_destroy_scrn_callback(SCR_ID_AM_DATA_ACCOUNT_EDIT, (HistoryDelCBPtr) mmi_am_destroy_dcnt_scrn);
#endif
#else /* AM_09A */ 
    /* set leave proc */
    mmi_frm_scrn_set_leave_proc(GRP_ID_AM, SCR_ID_AM_DATA_ACCOUNT_EDIT, mmi_am_leave_dcnt_scrn);
#endif /* AM_09A */
    /* delete Options Screen */
    mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_DATA_ACCOUNT_OPT/*SCR_ID_AM_OPTIONS*/);
    SetCategory57RightSoftkeyFunctions(mmi_am_entry_save, mmi_am_backhistory_from_dcnt);

} 
    #ifdef AM_09A


/*****************************************************************************
 * FUNCTION
 *  mmi_am_destroy_dcnt_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static U8 mmi_am_destroy_dcnt_scrn(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*if (g_mmi_am_display_dtcnt != NULL)
    {
        mmi_am_free((void*)g_mmi_am_display_dtcnt);
        g_mmi_am_display_dtcnt = NULL;
    }*/
    return MMI_FALSE;
}
    #else /* AM_09A */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_am_leave_dcnt_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_am_leave_dcnt_scrn(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_leave_dcnt_scrn() ------- [S]");

    switch (evt->evt_id)
    {
    case EVT_ID_SCRN_DELETE_REQ:
        MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_leave_dcnt_scrn() -- EVT_ID_SCRN_DELETE_REQ");
        break;

    case EVT_ID_SCRN_DEINIT:
        MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_leave_dcnt_scrn() -- EVT_ID_SCRN_DELETE_REQ");
        /*if (g_mmi_am_display_dtcnt != NULL)
        {
            mmi_am_free((void*)g_mmi_am_display_dtcnt);
            g_mmi_am_display_dtcnt = NULL;
        }*/
        break;
    }

    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_leave_dcnt_scrn() ------- [E]");
    return ret;
}
    #endif /* AM_09A */
/*****************************************************************************
 * FUNCTION
 *  mmi_am_entry_save
 * DESCRIPTION
 *  confirm window for saving account item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_entry_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((PS8) g_mmi_am_display_dtcnt.APN) == 0)
    {
        mmi_display_popup_confirm_with_sg(
                                         GRP_ID_AM,
#ifdef __VRE_AM_08AB__ //michael
                                         STR_GLOBAL_YES,
                                         IMG_GLOBAL_YES,
                                         STR_GLOBAL_NO,
                                         IMG_GLOBAL_NO,
#else
                                         get_string(STR_GLOBAL_YES),
                                         get_image(IMG_GLOBAL_YES),
                                         get_string(STR_GLOBAL_NO),
                                         get_image(IMG_GLOBAL_NO),
#endif
                                         get_string(STR_ID_AM_DTCNT_INPUT_LACK),
                                         MMI_EVENT_QUERY,
                                         0);

        SetLeftSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_goto_am_main_screen, KEY_EVENT_UP);
        return;
    }
    mmi_display_popup_confirm_with_sg(
                                     GRP_ID_AM,
#ifdef __VRE_AM_08AB__ //michael
                                     STR_GLOBAL_YES,
                                     IMG_GLOBAL_YES,
                                     STR_GLOBAL_NO,
                                     IMG_GLOBAL_NO,
#else
                                     get_string(STR_GLOBAL_YES),
                                     get_image(IMG_GLOBAL_YES),
                                     get_string(STR_GLOBAL_NO),
                                     get_image(IMG_GLOBAL_NO),
#endif
                                     get_string(STR_GLOBAL_SAVE_ASK),
                                     MMI_EVENT_QUERY,
                                     0);
    SetLeftSoftkeyFunction(mmi_am_save_dcnt_changes, KEY_EVENT_UP);

    SetRightSoftkeyFunction(mmi_goto_am_main_screen, KEY_EVENT_UP);

}
/*****************************************************************************
 * FUNCTION
 *  mmi_am_save_dcnt_changes
 * DESCRIPTION
 *  prepare GPRS data account content to be saved
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern vm_apn_info vm_user_apn_info;
void mmi_am_save_dcnt_done(void)
{
    mmi_display_popup_with_sg(GRP_ID_AM,
                              (UI_string_type) get_string(STR_GLOBAL_DONE),
                              MMI_EVENT_SUCCESS,
                              0);
    mmi_am_ms_update_cdr(); //0714
    mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_DATA_ACCOUNT_EDIT);
}
void mmi_am_save_dcnt_changes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 StrDigit1[4];
    U8 StrDigit2[4];
    U8 StrDigit3[4];
    U8 StrDigit4[4];
    //mmi_frm_scrn_close_active_id();
    stopRequestedTone(WARNING_TONE);
    vm_user_apn_info.apn_info_id = 1;
    if (g_mmi_am_display_dtcnt.use_proxy == 0)
    {
        vm_user_apn_info.proxy_port =  (S32) gui_atoi((UI_string_type)g_mmi_am_display_dtcnt.proxy_port);
        mmi_ucs2_to_asc((PS8) StrDigit1, (PS8) g_mmi_am_display_dtcnt.GPRSIP1);
        mmi_ucs2_to_asc((PS8) StrDigit2, (PS8) g_mmi_am_display_dtcnt.GPRSIP2);
        mmi_ucs2_to_asc((PS8) StrDigit3, (PS8) g_mmi_am_display_dtcnt.GPRSIP3);
        mmi_ucs2_to_asc((PS8) StrDigit4, (PS8) g_mmi_am_display_dtcnt.GPRSIP4);
        sprintf(vm_user_apn_info.proxy_ip,"%s.%s.%s.%s",StrDigit1,StrDigit2,StrDigit3,StrDigit4);
        mmi_ucs2_to_asc((PS8) vm_user_apn_info.apn_proxy, (PS8) g_mmi_am_display_dtcnt.APN);
        mmi_ucs2_to_asc((PS8) vm_user_apn_info.wap_user_name, (PS8) g_mmi_am_display_dtcnt.UserName);
        mmi_ucs2_to_asc((PS8) vm_user_apn_info.wap_pass_word, (PS8) g_mmi_am_display_dtcnt.Passwd);

        mmi_am_save_apn_nvram((mmi_am_apn_info *)&vm_user_apn_info);
        mmi_am_save_single_vre_dcnt((mmi_am_apn_info *)&vm_user_apn_info, MMI_AM_TCP_APN_CMWAP, mmi_am_save_dcnt_done);
    }
    else
    {
        mmi_ucs2_to_asc((PS8) vm_user_apn_info.apn_no_proxy, (PS8) g_mmi_am_display_dtcnt.APN);
        mmi_ucs2_to_asc((PS8) vm_user_apn_info.net_user_name, (PS8) g_mmi_am_display_dtcnt.UserName);
        mmi_ucs2_to_asc((PS8) vm_user_apn_info.net_pass_word, (PS8) g_mmi_am_display_dtcnt.Passwd);
        vm_user_apn_info.proxy_port = 0;
        vm_user_apn_info.proxy_ip[0] = '\0';
        mmi_am_save_apn_nvram((mmi_am_apn_info *)&vm_user_apn_info);
        mmi_am_save_single_vre_dcnt((mmi_am_apn_info *)&vm_user_apn_info, MMI_AM_TCP_APN_CMNET, mmi_am_save_dcnt_done);
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_goto_am_main_screen
 * DESCRIPTION
 *  Go back 2 history screens to  Main
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_goto_am_main_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stopRequestedTone(WARNING_TONE);
    //mmi_frm_scrn_close_active_id();
    mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_DATA_ACCOUNT_EDIT);
    mmi_frm_scrn_close_active_id();
}
/*****************************************************************************
 * FUNCTION
 *  mmi_am_editor_highlight_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_editor_highlight_hdlr(S32 nIndex)
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
 *  mmi_am_use_proxy_inline_item_select_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_use_proxy_inline_item_select_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_am_display_dtcnt.use_proxy != g_mmi_am_display_dtcnt.IsChangeProxy)
    {
        mmi_am_fill_data_into_item(&g_mmi_am_apn_info);
        Category57ChangeItemText(AM_DATA_ACCOUNT_APN, (U8*)g_mmi_am_display_dtcnt.APN);
        Category57ChangeItemText(AM_DATA_ACCOUNT_USER_NAME, (U8*)g_mmi_am_display_dtcnt.UserName);

        #ifdef __VRE_AM_08AB__
        ReConfigureInlineItemTextEdit((wgui_inline_items + AM_DATA_ACCOUNT_PASSWD), (U8*)g_mmi_am_display_dtcnt.Passwd, 
                                      MMI_AM_MAX_PASSWD_LEN + 1, IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD);
        #else
        ReConfigureInlineItemTextEdit((wgui_inline_items + AM_DATA_ACCOUNT_PASSWD), (U8*)g_mmi_am_display_dtcnt.Passwd, 
                                      MMI_AM_MAX_PASSWD_LEN + 1, IMM_INPUT_TYPE_ASCII_PASSWORD);
        #endif
    }
    if (g_mmi_am_display_dtcnt.use_proxy == 1)
    {
        g_mmi_am_display_dtcnt.IsChangeProxy = 1;
        DisableInlineItem(wgui_inline_items + AM_DATA_ACCOUNT_IP_ADDRESS, AM_DATA_ACCOUNT_IP_ADDRESS);
        DisableInlineItem(wgui_inline_items + AM_DATA_ACCOUNT_PORT, AM_DATA_ACCOUNT_PORT);
    }
    else
    {
        g_mmi_am_display_dtcnt.IsChangeProxy = 0;
        EnableInlineItem(wgui_inline_items + AM_DATA_ACCOUNT_IP_ADDRESS, AM_DATA_ACCOUNT_IP_ADDRESS);
        EnableInlineItem(wgui_inline_items + AM_DATA_ACCOUNT_PORT, AM_DATA_ACCOUNT_PORT);
    }
    RedrawCategory57Screen();
}
/*****************************************************************************
 * FUNCTION
 *  mmi_am_data_account_fillInline_struct
 * DESCRIPTION
 *  fill inline structure for GPRS edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_data_account_fillInline_struct(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 BufferSize = 0;
    S16 len_str = 0;
    U16 one_ucs2 = L'*';
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef AM_09A
    SetInlineItemActivation((wgui_inline_items + AM_DATA_ACCOUNT_APN), KEY_LSK, KEY_EVENT_UP);
    SetInlineItemActivation((wgui_inline_items + AM_DATA_ACCOUNT_USER_NAME), KEY_LSK, KEY_EVENT_UP);
    SetInlineItemActivation((wgui_inline_items + AM_DATA_ACCOUNT_PASSWD), KEY_LSK, KEY_EVENT_UP);
#else
    SetInlineItemActivation((wgui_inline_items + AM_DATA_ACCOUNT_APN), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemActivation((wgui_inline_items + AM_DATA_ACCOUNT_USER_NAME), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemActivation((wgui_inline_items + AM_DATA_ACCOUNT_PASSWD), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
#endif
    SetInlineItemActivation((wgui_inline_items + AM_DATA_ACCOUNT_USE_PROXY),INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,0);
    SetInlineItemActivation((wgui_inline_items + AM_DATA_ACCOUNT_IP_ADDRESS), INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemActivation((wgui_inline_items + AM_DATA_ACCOUNT_PORT),INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,0);

    SetInlineItemCaption((wgui_inline_items + AM_DATA_ACCOUNT_APN_STR), (U8*) GetString(STR_ID_AM_DTCNT_CAPTION_APN));
    SetInlineItemCaption(
                        (wgui_inline_items + AM_DATA_ACCOUNT_USER_NAME_STR),
                        (U8*) GetString(STR_GLOBAL_USERNAME));
    SetInlineItemCaption((wgui_inline_items + AM_DATA_ACCOUNT_PASSWD_STR), (U8*) GetString(STR_GLOBAL_PASSWORD));
    SetInlineItemCaption((wgui_inline_items + AM_DATA_ACCOUNT_IP_ADDRESS_STR),(U8*)GetString(STR_ID_AM_DCNT_CAPTION_IP_ADDRESS)); 
    SetInlineItemCaption((wgui_inline_items + AM_DATA_ACCOUNT_PORT_STR),(U8*) GetString(STR_ID_AM_DCNT_CAPTION_PORT));


    BufferSize = MMI_AM_MAX_APN_LEN + 1;
#ifdef AM_09A
#ifdef __VRE_AM_08AB__
    SetInlineItemFullScreenEdit_ext2(
                                    (wgui_inline_items + AM_DATA_ACCOUNT_APN),
                                    STR_ID_AM_DTCNT_CAPTION_APN,
                                    IMG_ID_AM_TITLE,
                                    (U8*) (g_mmi_am_display_dtcnt.APN),
                                    BufferSize,
                                    IMM_INPUT_TYPE_ENGLISH_SENTENCE,//IMM_INPUT_TYPE_ASCII_CHAR,
                                    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
                                    NULL);
#else
    SetInlineItemFullScreenEdit_ext2(
                                    (wgui_inline_items + AM_DATA_ACCOUNT_APN),
                                    STR_ID_AM_DTCNT_CAPTION_APN,
                                    IMG_ID_AM_TITLE,
                                    (U8*) (g_mmi_am_display_dtcnt.APN),
                                    BufferSize,
                                    IMM_INPUT_TYPE_ASCII_CHAR,
                                    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
                                    NULL);
#endif
    SetInlineFullScreenEditCustomFunction(wgui_inline_items + AM_DATA_ACCOUNT_APN, mmi_am_data_account_fullline_edit_screen);
#else
    SetInlineItemTextEdit(
                         (wgui_inline_items + AM_DATA_ACCOUNT_APN),
                         (U8*) (g_mmi_am_display_dtcnt.APN),
                         BufferSize,
                         IMM_INPUT_TYPE_ASCII_CHAR);
#endif
    BufferSize = MMI_AM_MAX_USER_LEN + 1;
#ifdef AM_09A
#ifdef __VRE_AM_08AB__
    SetInlineItemFullScreenEdit_ext2(
                                    (wgui_inline_items + AM_DATA_ACCOUNT_USER_NAME),
                                    STR_GLOBAL_USERNAME,
                                    IMG_ID_AM_TITLE,
                                    (U8*) (g_mmi_am_display_dtcnt.UserName),
                                    BufferSize,
                                    IMM_INPUT_TYPE_ENGLISH_SENTENCE,//IMM_INPUT_TYPE_ASCII_CHAR,
                                    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
                                    NULL);
#else
    SetInlineItemFullScreenEdit_ext2(
                                    (wgui_inline_items + AM_DATA_ACCOUNT_USER_NAME),
                                    STR_GLOBAL_USERNAME,
                                    IMG_ID_AM_TITLE,
                                    (U8*) (g_mmi_am_display_dtcnt.UserName),
                                    BufferSize,
                                    IMM_INPUT_TYPE_ASCII_CHAR,
                                    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
                                    NULL);
#endif
    SetInlineFullScreenEditCustomFunction(
                                         wgui_inline_items + AM_DATA_ACCOUNT_USER_NAME,
                                         mmi_am_data_account_fullline_edit_screen);
#else
    SetInlineItemTextEdit(
                         (wgui_inline_items + AM_DATA_ACCOUNT_USER_NAME),
                         (U8*) (g_mmi_am_display_dtcnt.UserName),
                         BufferSize,
                         IMM_INPUT_TYPE_ASCII_CHAR);
#endif


    BufferSize = MMI_AM_MAX_PASSWD_LEN + 1;
#ifdef AM_09A
#ifdef __VRE_AM_08AB__
    SetInlineItemFullScreenEdit_ext2(
                                    (wgui_inline_items + AM_DATA_ACCOUNT_PASSWD),
                                    STR_GLOBAL_PASSWORD,
                                    IMG_ID_AM_TITLE,
                                    (U8*) (g_mmi_am_display_dtcnt.Passwd),
                                    BufferSize,
                                    IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD,
                                    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
                                    NULL);
#else 
    SetInlineItemFullScreenEdit_ext2(
                                    (wgui_inline_items + AM_DATA_ACCOUNT_PASSWD),
                                    STR_GLOBAL_PASSWORD,
                                    IMG_ID_AM_TITLE,
                                    (U8*) (g_mmi_am_display_dtcnt.Passwd),
                                    BufferSize,
                                    IMM_INPUT_TYPE_ASCII_PASSWORD,
                                    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
                                    NULL);
#endif
    SetInlineFullScreenEditCustomFunction(wgui_inline_items + AM_DATA_ACCOUNT_PASSWD, mmi_am_data_account_fullline_edit_screen);
#else
    SetInlineItemTextEdit(
                         (wgui_inline_items + AM_DATA_ACCOUNT_PASSWD),
                         (U8*) (g_mmi_am_display_dtcnt.Passwd),
                         BufferSize,
                         IMM_INPUT_TYPE_ASCII_PASSWORD);
#endif

    SetInlineItemCaption(
                        (wgui_inline_items + AM_DATA_ACCOUNT_USE_PROXY_STR),
                        (U8*) GetString(STR_ID_AM_DCNT_CAPTION_USE_PROXY));

    SetInlineItemSelect(
                       (wgui_inline_items + AM_DATA_ACCOUNT_USE_PROXY),
                       (S32) 2,
                       (U8 **) g_mmi_am_display_dtcnt.use_proxy_option_str,
                       &g_mmi_am_display_dtcnt.use_proxy);

    RegisterInlineSelectHighlightHandler(
                                        (wgui_inline_items + AM_DATA_ACCOUNT_USE_PROXY),
                                        mmi_am_use_proxy_inline_item_select_hdlr);


    SetInlineItemIP4(
                    (wgui_inline_items + AM_DATA_ACCOUNT_IP_ADDRESS),
                    (U8*) g_mmi_am_display_dtcnt.GPRSIP1,
                    (U8*) g_mmi_am_display_dtcnt.GPRSIP2,
                    (U8*) g_mmi_am_display_dtcnt.GPRSIP3,
                    (U8*) g_mmi_am_display_dtcnt.GPRSIP4,
                    mmi_am_prepared_IPAddress_string);


    BufferSize = 6;
    SetInlineItemTextEdit(
                         (wgui_inline_items + AM_DATA_ACCOUNT_PORT),
                         (U8*) (g_mmi_am_display_dtcnt.proxy_port),
                         BufferSize,
                         IMM_INPUT_TYPE_NUMERIC);

    if (g_mmi_am_display_dtcnt.use_proxy == 1)
    {
        DisableInlineItem(wgui_inline_items + AM_DATA_ACCOUNT_IP_ADDRESS, AM_DATA_ACCOUNT_IP_ADDRESS);
        DisableInlineItem(wgui_inline_items + AM_DATA_ACCOUNT_PORT, AM_DATA_ACCOUNT_PORT);
    }

}
/*****************************************************************************
 * FUNCTION
 *  mmi_am_data_account_fullline_edit_screen
 * DESCRIPTION
 *  Data Account Name for Full Line Edit Screen.
 *  
 *  This is used to edit Data Account.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_data_account_fullline_edit_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);

    SetInputMethodAndDoneCaptionIcon(IMG_ID_AM_TITLE);

    SetLeftSoftkeyFunction(EntryScrForInputMethodAndDone, KEY_EVENT_UP);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_am_prepared_IPAddress_string
 * DESCRIPTION
 *  Prepared the Data Account IP Address to Show on Screen.
 * PARAMETERS
 *  string_buffer       [?]     
 *  IP1                 [?]     
 *  IP2                 [?]     
 *  IP3                 [?]     
 *  IP4                 [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_prepared_IPAddress_string(U8 *string_buffer, U8 *IP1, U8 *IP2, U8 *IP3, U8 *IP4)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 Point[20];
    S32 IPAddress[20];
    U8 LocalBuffer[8];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2((S8*) Point, (S8*) ".");

    IPAddress[0] = (S32) gui_atoi((UI_string_type) IP1);
    IPAddress[1] = (S32) gui_atoi((UI_string_type) IP2);
    IPAddress[2] = (S32) gui_atoi((UI_string_type) IP3);
    IPAddress[3] = (S32) gui_atoi((UI_string_type) IP4);

    mmi_am_return_three_digit_string(LocalBuffer, (U8) IPAddress[0]);
    mmi_ucs2cpy((PS8) string_buffer, (PS8) LocalBuffer);
    mmi_ucs2cat((PS8) string_buffer, (PS8) Point);

    mmi_am_return_three_digit_string(LocalBuffer, (U8) IPAddress[1]);
    mmi_ucs2cat((PS8) string_buffer, (PS8) LocalBuffer);
    mmi_ucs2cat((PS8) string_buffer, (PS8) Point);

    mmi_am_return_three_digit_string(LocalBuffer, (U8) IPAddress[2]);
    mmi_ucs2cat((PS8) string_buffer, (PS8) LocalBuffer);
    mmi_ucs2cat((PS8) string_buffer, (PS8) Point);

    mmi_am_return_three_digit_string(LocalBuffer, (U8) IPAddress[3]);
    mmi_ucs2cat((PS8) string_buffer, (PS8) LocalBuffer);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_am_return_three_digit_string
 * DESCRIPTION
 *  This Fun Convert the integer value to String with prefix zero.
 *  
 *  Works only for three digit integer.(0-256)
 * PARAMETERS
 *  StringVal       [IN]        
 *  DigitVal        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_return_three_digit_string(PU8 StringVal, U8 DigitVal)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 LocalBuffer[8];
    S8 StrVal[8];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (DigitVal == 0)
    {
        mmi_asc_to_ucs2((PS8) StrVal, (PS8) "000");
    }
    else if (DigitVal < 10)
    {
        sprintf(LocalBuffer, "00%d", DigitVal);
        mmi_asc_to_ucs2((PS8) StrVal, (PS8) LocalBuffer);
    }
    else if (DigitVal < 100)
    {
        sprintf(LocalBuffer, "0%d", DigitVal);
        mmi_asc_to_ucs2((PS8) StrVal, (PS8) LocalBuffer);
    }
    else
    {
        sprintf(LocalBuffer, "%d", DigitVal);
        mmi_asc_to_ucs2((PS8) StrVal, (PS8) LocalBuffer);
    }
    mmi_ucs2cpy((PS8) StringVal, (PS8) StrVal);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_am_VerifyDataAcountChanges
 * DESCRIPTION
 *  Verify the Data Account fields.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_am_VerifyDataAcountChanges(void)
{

}
/*****************************************************************************
 * FUNCTION
 *  mmi_am_process_apn_incorrect_handle
 * DESCRIPTION
 *  Verify the Data Account fields.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_am_process_apn_incorrect_handle(MMI_AM_APN_RESULT result)
{
    //MMI_AM_APN_RESULT result;
    MMI_BOOL ret = MMI_FALSE;
    //result = mmi_am_check_apn_status(&g_mmi_am_apn_info);
    //vm_log_warn("save data into nvram %d",result);
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "check apn result(); %d",result);
    switch (result)
    {
    case MMI_AM_APN_NOT_EQUAL:
        if (MMI_TRUE == mmi_am_check_isfirst_runing()) /*apn match, pswd and username mismatch*/
        {
            mmi_display_popup_confirm_with_sg(
                                             GRP_ID_AM,
#ifdef __VRE_AM_08AB__
                                             STR_GLOBAL_YES,
                                             IMG_GLOBAL_YES,
                                             STR_GLOBAL_NO,
                                             IMG_GLOBAL_NO,
#else
                                             get_string(STR_GLOBAL_YES),
                                             get_image(IMG_GLOBAL_YES),
                                             get_string(STR_GLOBAL_NO),
                                             get_image(IMG_GLOBAL_NO),
#endif
                                             get_string(STR_ID_AM_DATA_ACCOUNT_INCORRECT),
                                             MMI_EVENT_QUERY,
                                             0);
            SetLeftSoftkeyFunction(mmi_am_process_save_handle, KEY_EVENT_UP);
            SetRightSoftkeyFunction(mmi_goto_am_main_screen, KEY_EVENT_UP);
            ret = MMI_TRUE;
            //try vre tcp connect
        }
        else
        {
            //GoBackHistory();
        }
        break;
    case MMI_AM_APN_NOT_FOUND_RECORD:/*apn not exist*/
        {
            mmi_display_popup_confirm_with_sg(
                                             GRP_ID_AM,
#ifdef __VRE_AM_08AB__
                                             STR_GLOBAL_YES,
                                             IMG_GLOBAL_YES,
                                             STR_GLOBAL_NO,
                                             IMG_GLOBAL_NO,
#else
                                             get_string(STR_GLOBAL_YES),
                                             get_image(IMG_GLOBAL_YES),
                                             get_string(STR_GLOBAL_NO),
                                             get_image(IMG_GLOBAL_NO),
#endif
                                             get_string(STR_ID_AM_APN_NOT_EXIST),
                                             MMI_EVENT_QUERY,
                                             0);
            SetLeftSoftkeyFunction(mmi_am_entry_dataaccount_screen_auto, KEY_EVENT_UP);
            SetRightSoftkeyFunction(mmi_goto_am_main_screen, KEY_EVENT_UP);
            ret = MMI_TRUE;
            break;
        }
    case MMI_AM_APN_ONLY_NET_IN_NATIVE_LIST:
        if (g_mmi_am_apn_info.apn_proxy[0] !='\0')
        {
            ret = MMI_TRUE;
            mmi_am_save_single_vre_dcnt(&g_mmi_am_apn_info, MMI_AM_TCP_APN_CMWAP, mmi_am_ms_update_cdr);
        }
        break;
    case MMI_AM_APN_ONLY_WAP_IN_NATIVE_LIST:
        if (g_mmi_am_apn_info.apn_no_proxy[0] !='\0')
        {
            ret = MMI_TRUE;
            mmi_am_save_single_vre_dcnt(&g_mmi_am_apn_info, MMI_AM_TCP_APN_CMNET, mmi_am_ms_update_cdr);
        }
        break;
    case MMI_AM_APN_NO_IN_NATIVE_LIST:
        if ((g_mmi_am_apn_info.apn_no_proxy[0] !='\0') && (g_mmi_am_apn_info.apn_proxy[0] !='\0'))
        {
        mmi_am_process_save_handle();
        }
        else if ((g_mmi_am_apn_info.apn_no_proxy[0] =='\0') && (g_mmi_am_apn_info.apn_proxy[0] !='\0'))
        {
            mmi_am_save_single_vre_dcnt(&g_mmi_am_apn_info, MMI_AM_TCP_APN_CMWAP, mmi_am_ms_update_cdr);
        }
        else if ((g_mmi_am_apn_info.apn_no_proxy[0] !='\0') && (g_mmi_am_apn_info.apn_proxy[0] =='\0'))
        {
            mmi_am_save_single_vre_dcnt(&g_mmi_am_apn_info, MMI_AM_TCP_APN_CMNET, mmi_am_ms_update_cdr);
        }
        ret = MMI_TRUE;
        break;
    case MMI_AM_APN_ALL_IN_NATIVE_LIST:
    case MMI_AM_APN_OK:
        mmi_am_set_dcnt_ready_status(MMI_TRUE);
        break;
    default:
        //GoBackHistory();
        break;
    }
    return ret;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_am_process_save_handle
 * DESCRIPTION
 *  save apn data into nvram.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_process_save_handle(void)
{
    mmi_am_save_vre_dcnt(&g_mmi_am_apn_info,mmi_am_ms_update_cdr);
}
/*vogins_20100714_begin*/
/*****************************************************************************
 * FUNCTION
 *  mmi_am_entry_dataaccount_option_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_entry_dataaccount_opt_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    U8 *gui_buffer;
    U16 nitems;
    U16 itemlist[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_frm_scrn_enter(GRP_ID_AM, SCR_ID_AM_DATA_ACCOUNT_OPT, mmi_am_eixt_dataaccount_opt_scrn, mmi_am_entry_dataaccount_opt_scrn, NULL);

    if (ret == MMI_FALSE)
    {
        return;
    }

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    /* regenerate list */
    mmi_am_dcnt_get_list(itemlist, &nitems);
    RegisterHighlightHandler(mmi_am_dcnt_highlight_hdlr);

    ShowCategory15Screen(STR_ID_AM_OPTION_DATA_ACCOUNT,
#ifdef __MMI_FTE_SUPPORT__
                         0,
#else 
                         IMG_ID_AM_TITLE,
#endif 
                         STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, nitems, itemlist, (PU16) gIndexIconsImageList, LIST_MENU, 0,   /* default highlight item */
                         gui_buffer);

    /* delete Options Screen */
    mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_OPTIONS);

    SetLeftSoftkeyFunction(mmi_am_dcnt_lsk_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_eixt_settings_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_eixt_dataaccount_opt_scrn(void)
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
 *  mmi_am_dcnt_get_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  list            [OUT]       
 *  list_num        [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_dcnt_get_list(U16 *list, U16 *list_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* S32 index; */
    U16 item_num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list[item_num++] = STR_GLOBAL_EDIT;
    list[item_num++] = STR_GLOBAL_RESET;

    *list_num = item_num;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_am_dcnt_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_dcnt_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type item_text;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item_text = get_item_text(index);

    if (mmi_wcscmp((U16*) item_text, (U16*) GetString(STR_GLOBAL_EDIT)) == 0)
    {
    	  SetLeftSoftkeyFunction(mmi_am_dcnt_lsk_hdlr, KEY_EVENT_UP);
        SetKeyHandler(mmi_am_dcnt_lsk_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    #ifdef __MMI_TOUCH_SCREEN__
        wgui_register_list_item_selected_callback(mmi_am_dcnt_lsk_hdlr);
    #endif 
    }
    else if (mmi_wcscmp((U16*) item_text, (U16*) GetString(STR_GLOBAL_RESET)) == 0)
    {
    	  SetLeftSoftkeyFunction(mmi_am_dcnt_lsk_hdlr, KEY_EVENT_UP);
        SetKeyHandler(mmi_am_dcnt_lsk_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    #ifdef __MMI_TOUCH_SCREEN__
        wgui_register_list_item_selected_callback(mmi_am_dcnt_lsk_hdlr);
    #endif 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_dcnt_lsk_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_dcnt_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    UI_string_type item_text;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetHighlightedItem();
    item_text = get_item_text(index);

    if (mmi_wcscmp((U16*) item_text, (U16*) GetString(STR_GLOBAL_EDIT)) == 0)
    {
        mmi_am_entry_dataaccount_screen();
    }
    else if (mmi_wcscmp((U16*) item_text, (U16*) GetString(STR_GLOBAL_RESET)) == 0)
    {
        mmi_am_dcnt_delete_query();
    }
}
void mmi_am_dcnt_delete_query(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ask user if wish to download the app */
    mmi_display_popup_confirm_with_sg(
                                     GRP_ID_AM,
#ifdef __VRE_AM_08AB__
                                     STR_GLOBAL_YES,
                                     IMG_GLOBAL_YES,
                                     STR_GLOBAL_NO,
                                     IMG_GLOBAL_NO,
#else
                                     get_string(STR_GLOBAL_YES),
                                     get_image(IMG_GLOBAL_YES),
                                     get_string(STR_GLOBAL_NO),
                                     get_image(IMG_GLOBAL_NO),
#endif
                                     get_string(STR_GLOBAL_RESET),
                                     MMI_EVENT_QUERY,
                                     0);

    
    SetLeftSoftkeyFunction(mmi_am_delete_apn_from_nvram, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

}
void mmi_am_delete_apn_from_nvram(void)
{
	 mmi_am_delete_apn_nvram();
     memset(&vm_user_apn_info, 0 , sizeof(mmi_am_apn_info));
	 mmi_display_popup_with_sg(GRP_ID_AM,
                            (UI_string_type) get_string(STR_GLOBAL_DONE),
                            MMI_EVENT_SUCCESS,
                            0);
	/* delete Options Screen */
    mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_DATA_ACCOUNT_OPT);
}
/*vogins 20100714 end*/
/*vogins_20100712_start*/
/*****************************************************************************
 * FUNCTION
 *  mmi_am_exit_processes_manager_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_exit_processes_manager_scrn(void)
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
 *  mmi_am_back_processes_manager_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_back_processes_manager_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

   /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_am_ms_release_run_app_list();
    GoBackHistory();
	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_processes_manager_os_resume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_processes_manager_os_resume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_am_ms_app_struct *appinfo_p;
    U16 *app_path = NULL;	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    appinfo_p = sml_list_get(g_run_app_list, g_am_pro_mngr_highlight);
	app_path = appinfo_p->path;
	
		mmi_frm_scrn_close(GRP_ID_AM,  SCR_ID_AM_PROCESSES_MANAGER);	
  
	 if(app_path)
	    {
	        
	        if(g_am_qs_cntx.quick_start_flag == HS_SHORTCUT)
	        {
	            mmi_am_start_from_hs(app_path);
	        }
	        else if(g_am_qs_cntx.quick_start_flag == FILE_MGR)
	        {
	            mmi_am_start_from_fm(app_path);
	        }
	        else
	        {
	            if (g_am_qs_cntx.is_quick_start == MMI_TRUE)
			    {
			       g_am_cntx.start_state = START_NONE;
			    }
			    else
			    {
			       g_am_cntx.start_state = START_BEGIN;
			    }
				
				g_am_relaunch_cntx.am_relaunch_tag = MMI_TRUE;
				mmi_wcscpy(g_am_relaunch_cntx.path, app_path);
				
			    mmi_am_entry_loading_scrn();
				mmi_frm_scrn_close(GRP_ID_AM,  SCR_ID_AM_PROCESSES_MANAGER_OS);	  
	
	        }
	    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_am_processes_manager_os_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_processes_manager_os_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
       int ret = -1, i; 
	mmi_am_ms_app_struct *appinfo_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    


    appinfo_p = sml_list_get(g_run_app_list, g_am_pro_mngr_highlight);

    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "[AMVRE]Stop VRE handler");
    
    if (appinfo_p->path != NULL) 
    {
        ret = vm_terminate_bg_app((VMWSTR)appinfo_p->path);
    }
	
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "[AMVRE]Stop VRE handler ret:%d",ret);
	
    if(ret == VM_TERMINATE_SUCCESS)
    {  
          mmi_am_ms_set_app_bg_running_by_path(appinfo_p->path, MMI_FALSE);
         
        mmi_am_ms_release_run_app_list();        
      }
	else
	{
		mmi_display_popup_with_sg(
	            GRP_ID_AM,
	            (UI_string_type) get_string(STR_ID_AM_STOP_FAILURE),
	            MMI_EVENT_FAILURE,
	            0);	
	}
	GoBackHistory();
	
}

static void mmi_am_processes_manager_os_stop_confrm()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ask user if wish to stop the app */
    mmi_display_popup_confirm_with_sg(
        GRP_ID_AM,
        #ifdef __VRE_AM_08AB__
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        #else
        get_string(STR_GLOBAL_YES),
        get_image(IMG_GLOBAL_YES),
        get_string(STR_GLOBAL_NO),
        get_image(IMG_GLOBAL_NO),
        #endif
        get_string(STR_ID_APPMEM_STOP),
        MMI_EVENT_QUERY,
        0);
    SetLeftSoftkeyFunction(mmi_am_processes_manager_os_stop, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	mmi_frm_scrn_close(GRP_ID_AM,  SCR_ID_AM_PROCESSES_MANAGER_OS);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_am_processes_manager_os_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_processes_manager_os_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type item_text;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item_text = get_item_text(index);

    if (mmi_wcscmp((U16*) item_text, (U16*) GetString(STR_GLOBAL_RESUME)) == 0)
    {
        SetLeftSoftkeyFunction(mmi_am_processes_manager_os_resume, KEY_EVENT_UP);
        SetKeyHandler(mmi_am_processes_manager_os_resume, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    #ifdef __MMI_TOUCH_SCREEN__
        wgui_register_list_item_selected_callback(mmi_am_processes_manager_os_resume);
    #endif 
    }
    else if (mmi_wcscmp((U16*) item_text, (U16*) GetString(STR_GLOBAL_STOP)) == 0)
    {
        SetLeftSoftkeyFunction(mmi_am_processes_manager_os_stop_confrm, KEY_EVENT_UP);
        SetKeyHandler(mmi_am_processes_manager_os_stop_confrm, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    #ifdef __MMI_TOUCH_SCREEN__
        wgui_register_list_item_selected_callback(mmi_am_processes_manager_os_stop_confrm);
    #endif 
    }
}

static void mmi_am_processes_manager_os_lsk_hdlr()
{
   /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    UI_string_type item_text;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = GetHighlightedItem();
    item_text = get_item_text(index);

    if (mmi_wcscmp((U16*) item_text, (U16*) GetString(STR_GLOBAL_RESUME)) == 0)
    {
	mmi_am_processes_manager_os_resume();
    }
    else if (mmi_wcscmp((U16*) item_text, (U16*) GetString(STR_GLOBAL_STOP)) == 0)
    {
        mmi_am_processes_manager_os_stop_confrm();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_am_entry_processes_manager_os_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_entry_processes_manager_os_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    U8 *gui_buffer;
    U16 nitems;
    U16 itemlist[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "[AM] entry processes manager options screen begin---");
    ret = mmi_frm_scrn_enter(GRP_ID_AM, SCR_ID_AM_PROCESSES_MANAGER_OS, mmi_am_eixt_option_scrn, mmi_am_entry_processes_manager_os_screen, NULL);

    if (ret == MMI_FALSE)
    {
        return;
    }
    itemlist[0] = STR_GLOBAL_RESUME;
    itemlist[1] = STR_GLOBAL_STOP;
	
    mmi_am_ms_scrolling_text_stop();

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();


    RegisterHighlightHandler(mmi_am_processes_manager_os_highlight_hdlr);

    ShowCategory15Screen(STR_ID_AM_PROCESSES_MANAGER,
#ifdef __MMI_FTE_SUPPORT__
                         0,
#else 
                         IMG_ID_AM_TITLE,
#endif 
                         STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, 2, itemlist, (PU16) gIndexIconsImageList, LIST_MENU, 0,   /* default highlight item */
                         gui_buffer);

    SetLeftSoftkeyFunction(mmi_am_processes_manager_os_lsk_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
	MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "[AM] entry processes manager options screen end---");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_processes_manager_screen_os_highlighted
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_processes_manager_screen_os_highlighted(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    g_am_pro_mngr_highlight = GetHighlightedItem();
   
    mmi_am_entry_processes_manager_os_screen();
}
/*****************************************************************************
 * FUNCTION
 *  mmi_am_processes_manager_screen_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index  [IN]    currently highlighted menu index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_processes_manager_screen_highlight_hdlr(S32 item_index)
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
    
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
    SetLeftSoftkeyFunction(mmi_am_processes_manager_screen_os_highlighted, KEY_EVENT_UP);
}
#ifdef AM_09A
static U8 mmi_am_destroy_processes_manager_scrn(void *param)
{ 
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "[AM]mmi_am_destroy_processes_manager_scrn ---S");
    mmi_am_ms_release_run_app_list();    
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "[AM]mmi_am_destroy_processes_manager_scrn ---E");
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_am_leave_processes_manager_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_am_leave_processes_manager_scrn(mmi_event_struct *evt)
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
             mmi_am_ms_release_run_app_list();
             break;
    }

    return ret;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_am_processes_mngr_screen_get_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static pBOOL mmi_am_processes_mngr_screen_get_item(
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

/*****************************************************************************
 * FUNCTION
 *  mmi_am_processes_mngr_screen_hide_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_processes_mngr_screen_hide_info(void)
{
}

/*****************************************************************************
 * FUNCTION
 *  mmi_am_entry_processes_manager_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_entry_processes_manager_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 run_app_count=0;
   // S32 info_box_height;
    vm_running_app_info_t* am_running_app_infos = NULL;
    U16 am_running_app_num = 0;
    MMI_BOOL ret;
    U16 string_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "[AM] entry processes manager screen begin---");
    ret = mmi_frm_scrn_enter(GRP_ID_AM, SCR_ID_AM_PROCESSES_MANAGER, mmi_am_exit_processes_manager_scrn, mmi_am_entry_processes_manager_scrn, NULL);

    if (ret == MMI_FALSE)
    {
        return;
    }
	
     mmi_am_vre_get_process_list(&am_running_app_infos,&am_running_app_num);
    if(am_running_app_num != sml_list_size(g_run_app_list))
    	{
    		mmi_am_ms_release_run_app_list();
	        if(mmi_am_get_running_appinfo(am_running_app_infos, am_running_app_num) == MMI_TRUE)
		{
		       MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "[AM] mmi_am_get_running_appinfo -----");
			      if (am_running_app_infos !=NULL) 
				    {
				        vm_release_app_running_infos(am_running_app_infos);
				        am_running_app_infos =NULL;
				    }
		}
    	}
	MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "[AM] entry processes manager screen run app list num: %d---", sml_list_size(g_run_app_list));
        guiBuffer = mmi_frm_scrn_get_active_gui_buf();

       // info_box_height = MMI_MENUITEM_HEIGHT + 4;        
        run_app_count =  sml_list_size(g_run_app_list);
        if (run_app_count > 0)
        {
            string_id = STR_GLOBAL_OPTIONS;
        }
        else
        {
            string_id = 0;
        }
        RegisterHighlightHandler(mmi_am_processes_manager_screen_highlight_hdlr);
        ShowCategory284Screen(
            STR_ID_AM_PROCESSES_MANAGER,
#ifdef __MMI_FTE_SUPPORT__
            0,
#else 
            IMG_ID_AM_TITLE,
#endif
            string_id,
            0,
            STR_GLOBAL_BACK,
            0,
            (S32)run_app_count,
            mmi_am_processes_mngr_screen_get_item,
            NULL,
            0,
            guiBuffer);

#ifdef AM_09A
	  #ifdef __VRE_AM_08AB__
    SetDelScrnIDCallbackHandler(SCR_ID_AM_PROCESSES_MANAGER, (HistoryDelCBPtr) mmi_am_destroy_processes_manager_scrn);
	  #else
    mmi_frm_set_destroy_scrn_callback(SCR_ID_AM_PROCESSES_MANAGER, (HistoryDelCBPtr) mmi_am_destroy_processes_manager_scrn);
    #endif
#else /* AM_09A */ 
    /* set leave proc */
    mmi_frm_scrn_set_leave_proc(GRP_ID_AM, SCR_ID_AM_PROCESSES_MANAGER, mmi_am_leave_processes_manager_scrn);
#endif /* AM_09A */ 
        if (run_app_count > 0) 
        {
            SetLeftSoftkeyFunction(mmi_am_processes_manager_screen_os_highlighted, KEY_EVENT_UP);
        }
       SetRightSoftkeyFunction(mmi_am_back_processes_manager_scrn, KEY_EVENT_UP);
      MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "[AM] entry processes manager screen end---");
}

/*****************************************************************************
 * FUNCTION
 *  mmi_am_os_processes_manager
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_os_processes_manager(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_am_entry_processes_manager_scrn();

    /* delete Options Screen */
    mmi_frm_scrn_close(GRP_ID_AM, SCR_ID_AM_OPTIONS);	
}
/*vogins_20100712_end*/
#endif /* __VRE30_AM__ */ 

