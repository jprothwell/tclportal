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

/*******************************************************************************
 * Filename:
 * ---------
 *  AMProxy.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  Keith Chen
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
* $ Log $
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef AM_PROXY_H
#define AM_PROXY_H
#ifdef __VRE_AM_08AB__
#include "gui_data_types.h"
#endif

#ifdef __VRE_RB_09A__
#define AM_09A
#endif

#define AM_POPUP_DISABLE_SHOW_ICON

#include "vmenv.h"

/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef enum
{
    MMI_AM_VLC_START_SUCCESS = 0,
    MMI_AM_VLC_ASYN_ALLOC_ASM,
    MMI_AM_VLC_MASS_STORAGE,
    MMI_AM_VLC_MEDIA_BUFFER_ALLOC_ERROR,
    MMI_AM_VLC_INTERNEL_ERROR
} MMI_AM_LOAD_VRE_CORE;

typedef enum
{
    MMI_AM_IN_USE = 0,
    MMI_AM_OUT_OF_USE
} MMI_AM_STATES;

typedef enum
{
    MMI_AM_VRE_START_SUCCESS = 0,
    MMI_AM_VRE_START_INTERNEL_ERROR,
    MMI_AM_VRE_QUIT
} MMI_AM_START_VRE_EVT;

typedef void (*MMI_AM_VRE_EVT_CB_T) (MMI_AM_START_VRE_EVT evt);
/*vogins 100726 begin*/
typedef void (*MMI_AM_VRE_APP_EVT_CB_T) (void);

typedef enum
{
    INFO_DEV,       /* developer */
    INFO_APP_ID,    /* app id */
    INFO_NAME,      /* app name */
    INFO_DESC,      /* app introduction, including tel */
    INFO_BG_RUN     /* wether support bg run */
} MMI_AM_INFO_TYPE;

typedef enum
{
    MMI_AM_ENG = 0,
    MMI_AM_CHS,
    MMI_AM_CHT
} MMI_AM_LANGUAGE_TYPE;

/* App start result */
typedef enum
{
    MMI_AM_EXECUTE_APP_SUCCESS = 0,
    MMI_AM_EXECUTE_APP_ILLEGAL,
    MMI_AM_EXECUTE_APP_NOT_ENOUGH_MEMORY,
    /*michael 0415 begin */
    MMI_AM_EXECUTE_SYS_NOT_ENOUGH_MEMORY,
    /*michael 0415 end */
    /* jie.chen 06/02/2010 begin */
    MMI_AM_EXECUTE_EXCEED_MAX_APP_NUM,
    /* jie.chen 06/02/2010 end */
    MMI_AM_EXECUTE_APP_CALL_STACK_FULL,
    MMI_AM_EXECUTE_INTERNAL_ERROR,
    MMI_AM_EXECUTE_PLATFORM_PARAM_DISMATCH,
    MMI_AM_EXECUTE_TIMESTAMP_ERROR,
    MMI_AM_EXECUTE_BANNED_APP,
    MMI_AM_EXECUTE_IMSI_DISMATCH,
    MMI_AM_EXECUTE_CERT_OVERDUE,
    MMI_AM_EXECUTE_EXCEED_FILE_IN_VRE_DIRECTORY
} MMI_AM_START_RESULT;

typedef void (*MMI_AM_DL_APP_CB_T) (S32 nResult, S32 nPercent);
typedef void (*MMI_AM_SYNC_CDR_CB_T) (S32 nResult);

/* Download app result */
typedef enum
{
    MMI_AM_DL_DONE,
    MMI_AM_DL_OK,
    MMI_AM_DL_ERR,
    MMI_AM_DL_NET_ERR,
    MMI_AM_DL_SAVE_ERR,
    MMI_AM_DL_APP_NOT_EXIST,
    MMI_AM_DL_SPACE_FULL,
    MMI_AM_DL_OTHER_ERR,
    MMI_AM_DL_FILE_NOT_EXIST,
    MMI_AM_DL_IO_ERROR,
    /* Dan 0528 begin*/
    MMI_AM_DL_1302_ERR,
    MMI_AM_DL_1401_ERR,
    MMI_AM_DL_1402_ERR,
    MMI_AM_DL_1403_ERR,
    MMI_AM_DL_1404_ERR,
    MMI_AM_DL_1405_ERR,
    MMI_AM_DL_1406_ERR,
    MMI_AM_DL_1407_ERR
    /* Dan 0528 end*/
} MMI_AM_DOWNLOAD_APP_RESULT;

/* Update CDR states */
typedef enum
{
    MMI_AM_NO_SYSC_CDR,
    MMI_AM_NVRAM_NEED_FOR_SYNC_CDR,
    MMI_AM_TIME_NEED_FOR_SYNC_CDR
} MMI_AM_UPDATE_CDR_STATE;

typedef enum
{
    MMI_AM_APN_NOT_FIND_SIM_CARD = -6,
	MMI_AM_APN_NOT_FOUND_RECORD = -5,
	MMI_AM_APN_WRITE_NVRAM_ERROR,
	MMI_AM_APN_READ_NVRAM_ERROR,
	MMI_AM_APN_NOT_EQUAL,
	MMI_AM_APN_INTERNAL_ERROR,
	MMI_AM_APN_OK,
	MMI_AM_APN_USE_NVRAM_RECORD,
	MMI_AM_APN_NO_IN_NATIVE_LIST,
	MMI_AM_APN_ONLY_WAP_IN_NATIVE_LIST,
	MMI_AM_APN_ONLY_WAP_IN_NATIVE_LIST_LAST,
	MMI_AM_APN_ONLY_NET_IN_NATIVE_LIST,
	MMI_AM_APN_ONLY_NET_IN_NATIVE_LIST_LAST,
	MMI_AM_APN_ALL_IN_NATIVE_LIST,
	MMI_AM_APN_INIT
}MMI_AM_APN_RESULT;

typedef struct  
{
	S32		apn_info_id;
	S32		proxy_port;
	S8     operator_id[8];
	S8     operator_name[64];
	S8     proxy_ip[16];
	S8     apn_proxy[32];
	S8     apn_no_proxy[32];
	S8     wap_user_name[16];
	S8     wap_pass_word[16];
    S8     net_user_name[16];
	S8     net_pass_word[16];
}mmi_am_apn_info;
#define MMI_AM_TCP_APN_CMNET		(1)
#define MMI_AM_TCP_APN_CMWAP		(2)

#ifdef __VRE_AM_08AB__
typedef void (*FuncPtr) (void);
#endif
/****************************************************************************
* Extern Global Function                                                            
*****************************************************************************/
extern MMI_AM_LOAD_VRE_CORE mmi_am_vre_load_core(MMI_AM_VRE_EVT_CB_T am_cb);
extern void mmi_am_vre_unload_core(void);
extern void mmi_am_vre_set_am_state(MMI_AM_STATES state);
extern MMI_AM_START_RESULT mmi_am_vre_execute(U16 *app_path, MMI_AM_VRE_APP_EVT_CB_T app_cb);
extern MMI_BOOL mmi_am_vre_app_is_running(U16 *app_path);
extern MMI_BOOL mmi_am_vre_load_resource_from_file(
                    U16 *app_path,
                    S8 *res_name,
                    S32 *res_size,
                    S8 *cache_buf,
                    S32 cache_size);
extern MMI_BOOL mmi_am_vre_get_gif_data(S8 *gifzm, U8 **data_buf, S32 *data_len);
extern MMI_BOOL mmi_am_vre_get_string_data(
                    S8 *gifzm,
                    U8 **data_buf,
                    MMI_AM_LANGUAGE_TYPE lan,
                    S32 *str_len,
                    S32 *font,
                    S32 *data_size);
extern S32 mmi_am_vre_measure_zimo_string(S8 *zimo_buf, S32 str_len);
extern void mmi_am_vre_cancel_download(void);
extern MMI_BOOL mmi_am_vre_set_sim_card(S32 choose_index);
extern MMI_BOOL mmi_am_vre_set_net_type(S32 net_type);
extern MMI_BOOL mmi_am_vre_get_sim_card(S32 *sim_index);
extern MMI_BOOL mmi_am_vre_get_net_type(S32 *net_type);
extern void mmi_am_vre_pre_download_app(void *(*mem_calloc_cb) (int size), void (*mem_free_cb) (void *ptr));
extern S32 mmi_am_vre_download_app(MMI_AM_DL_APP_CB_T dl_app_cb, U32 app_id, U16 *app_name, S32 block_size);
extern void mmi_am_vre_get_buildin_app_array(S32 **app_array_ptr, S32 *app_array_len_ptr);
extern MMI_BOOL mmi_am_vre_get_app_version(U16 *filename, S32 *version);
extern MMI_BOOL mmi_am_vre_get_vm_tag(U16 *app_path, MMI_AM_INFO_TYPE tag_num, void *buf, S32 *buf_size);
extern MMI_BOOL mmi_am_vre_get_vm_tag_by_lang(
                    U16 *app_path,
                    MMI_AM_INFO_TYPE tag_num,
                    void *buf,
                    S32 *buf_size,
                    MMI_AM_LANGUAGE_TYPE lang);
extern void *mmi_am_vre_malloc(S32 size);
extern void mmi_am_vre_free(void *p);
extern MMI_AM_UPDATE_CDR_STATE mmi_am_vre_get_sync_cdr_state(void);
extern S32 mmi_am_vre_sync_cdr(MMI_AM_SYNC_CDR_CB_T sync_cdr_cb);
extern void mmi_am_vre_sync_cdr_cancel(void);
extern MMI_BOOL mmi_am_vre_get_user_balance(U32 *user_balance);
extern MMI_BOOL mmi_am_is_network_service_available(void);
extern int mmi_am_vre_terminate_bg_app(U16 *app_path);
//vogins 0625
extern void mmi_am_delete_apn_nvram(void);
extern void mmi_am_save_apn_nvram(mmi_am_apn_info *apn_info);
extern void mmi_am_save_vre_dcnt(mmi_am_apn_info *apn_info,void(*save_dcnt_cb)(void));
extern void mmi_am_save_single_vre_dcnt(mmi_am_apn_info *apn_info, U8 apn, void(*save_single_dcnt_cb)(void));
extern void mmi_am_check_apn_status(mmi_am_apn_info *apn_info, void(*check_dcnt_cb)(S8 result_value));
extern MMI_BOOL mmi_am_check_isfirst_runing(void);
extern void mmi_am_set_dcnt_ready_status(MMI_BOOL status);
/*vogins_20100712_start*/
extern void mmi_am_vre_get_process_list(vm_running_app_info_t** bg_app_infos, U16* app_info_num);
/*vogins_20100712_end*/
#ifdef AM_09A
#ifndef __VRE_AM_08AB__
#include "custom_events_notify.h"
#endif
typedef S32 mmi_ret;

#define MMI_RET_OK      (0)     /* the return value of mmi_ret */
#define MMI_RET_ERR     (-500)  /* the return value of mmi_ret */

#define MMI_FRM_NODE_SMART_CLOSE_FLAG 1
#define GRP_ID_ROOT 1
#define MMI_FRM_NODE_ALL_FLAG 1

enum
{
    EVT_ID_GROUP_FIRST_ENTRY,
    EVT_ID_GROUP_ACTIVE,
    EVT_ID_GROUP_INACTIVE,
    EVT_ID_GROUP_DEINIT,
    EVT_ID_SCRN_DELETE_REQ,
    EVT_ID_SCRN_DEINIT
};
#ifdef __VRE_AM_08AB__
typedef enum
{
    MMI_FRM_UNKNOW_SCREEN,
    MMI_FRM_FULL_SCREEN,
    MMI_FRM_SMALL_SCREEN,
    MMI_FRM_TAB_PAGE		
}mmi_frm_scrn_type_enum;

typedef enum
{
    MMI_EVENT_FAILURE,   /* Basic popup failure type */
    MMI_EVENT_INFO,      /* Basic popup infomation type */
    MMI_EVENT_WARNING,   /* Basic popup warning type */
    MMI_EVENT_SUCCESS,   /* Basic popup success type */
    MMI_EVENT_PROGRESS,  /* Basic popup progress type */
    MMI_EVENT_QUERY,     /* Basic popup query type */
    MMI_EVENT_TOTAL_NUM							/* total event*/
} mmi_event_notify_enum;
#endif
typedef struct
{
    /* Event id */
    U16 evt_id;
    /* Event structure size */
    U16 size;
    /* User data pointer */
    void *user_data;
} mmi_event_struct;
typedef mmi_ret(*mmi_proc_func) (mmi_event_struct *param);

/****************************************************************************
* Extern Global Function                                                            
*****************************************************************************/
extern U16 mmi_frm_group_enter_ex(U16 parent_id, U16 group_id, mmi_proc_func proc, void *user_data, S16 flag);
extern MMI_BOOL mmi_frm_scrn_enter(
                    U16 parent_id,
                    U16 scrn_id,
                    FuncPtr exit_proc,
                    FuncPtr entry_proc,
                    mmi_frm_scrn_type_enum scrn_type);
extern void mmi_frm_scrn_close_active_id(void);
extern U8 *mmi_frm_scrn_get_active_gui_buf(void);
extern mmi_ret mmi_frm_scrn_close(U16 parent_id, U16 scrn_id);
extern mmi_ret mmi_frm_group_close(U16 group_id);
extern MMI_BOOL mmi_frm_scrn_is_present(U16 parent_id, U16 scrn_id, S16 flag);
extern MMI_BOOL mmi_display_popup_with_sg(
                    U16 parent_id,
                    UI_string_type string,
                    mmi_event_notify_enum event_id,
                    U32 flags);
#ifdef __VRE_AM_08AB__
extern MMI_BOOL mmi_display_popup_confirm_with_sg(
                    U16 parent_id,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    UI_string_type message,
                    mmi_event_notify_enum event_id,
                    U32 flags);
extern void mmi_display_popup(UI_string_type string, mmi_event_notify_enum event_id);
#else
extern MMI_BOOL mmi_display_popup_confirm_with_sg(
                    U16 parent_id,
                    UI_string_type left_softkey,
                    PU8 left_softkey_icon,
                    UI_string_type right_softkey,
                    PU8 right_softkey_icon,
                    UI_string_type message,
                    mmi_event_notify_enum event_id,
                    U32 flags);
#endif

#endif /* AM_09A */ 

#endif /* AM_PROXY_H */ 

