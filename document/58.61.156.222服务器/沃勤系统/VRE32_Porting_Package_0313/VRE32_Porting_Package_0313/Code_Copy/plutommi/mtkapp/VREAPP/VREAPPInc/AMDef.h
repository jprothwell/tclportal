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
 *  AMDef.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  AM header file.
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
#ifndef AM_DEF_H
#define AM_DEF_H

// #define AM_TEST

#include "MMIDataType.h"
#include "liblist.h"
#include "AMGprot.h"
#include "AMProxy.h"

#define MMI_AM_VERSION "2010/7/12 base on MTK4/30 code"

#define MMI_AM_ASSERT ASSERT
#define MMI_AM_LOG kal_wap_trace
/*vogins AM/VRE memory independed 20100712 move it to amgprot.h*/
//#define MMI_AM_USING_VRE_MEM ///
////////////////////////////////////
//**define for AM update notyfy user feature /////////
#define AM_UPDATE_NOTIFY
#define AM_DOWNLOAD_CONFIRM
#define AM_DOWNLOAD_SIZE_LIMIT
#ifdef __VRE_OVERSEA_VERSION__
#define  AM_GPRS_NOT_NOTICE
#endif
/////////////////////////////////

#define MMI_AM_LOAD_RES_BUF_SIZE    (4*1024)    /* mmi_am_vre_load_resource_from_file() buffer size */
#define MMI_AM_MAX_APP_FILE_NAME    42  /* short file name use 8.3 format , the same to FMGR_MAX_FILE_LEN */
#define MMI_AM_MAX_APP_FILE_PATH               52       /* ex: C:\vre\app1.vxp */
#define MMI_AM_MAX_APP_QUICK_START_PATH              260
#define MMI_AM_SEARCH_APP_TIMER_DELAY             10    /* search app timer delay */
#define MMI_AM_MAX_SHORTCUT_APP_FILE_PATH         60    /* shortcut app file name */
#define MMI_AM_VRE_FOLDER_SIZE 7        /* Ex: c:/vre/ */

#define MMI_AM_ASYN_SEARCH_NUM 25       /* The number of applications for each search */
#define MMI_AM_MAX_APP_NUM 200  /* the max value of am can display */
#define MMI_AM_VXP_MAX_FILE_NUM 5000    /* the max value of vxp files in vre folder */

#define MMI_AM_APP_ICON_W 45    /* app icon width */
#define MMI_AM_APP_ICON_H 45    /* app icon height */

#define MMI_AM_ROM_DIR   64     /* @ */
#define MMI_AM_VRE_HOME_DIR    "vre"
#define MMI_AM_AS_FILE_NAME    "phsh.vxp"       /* AppStore file name */
#define MMI_AM_AS_TEMP_FILE_NAME    "phsh.pht"  /* AppStore temp file name */
#define MMI_AM_APP_LOGO    "_VREApplogo30.img"
#define MMI_AM_APP_V20_LOGO    "_VREApplogo.img"
#define MMI_AM_TEMP_SUFFIX  "tmp"       /* download temp file suffix */
#define MMI_AM_SEARCH_PATTERN  "*.vxp"  /* vre app file suffix */
#define MMI_AM_DOWNLOAD_LIST  "download_list.dat"       /* downloaded app list writed by AS */

#define MMI_AM_ICON_SIZE    4*1024      /* the maximum size of a icon */
#define MMI_AM_DOWNLOAD_BLOCK_SIZE    20*1024   /* 20K for VIP */
/*vogins_20100726_start*/
#define MMI_AM_SM_CHARGE_FILE_NAME "sm_charge.vsm" /*charge file name*/
/*vogins_20100726_end*/
/***************************************************************************** 
* Typedef 
*****************************************************************************/

/* Driver */
typedef enum
{
    NO_DRV,
    REMOVE_DRV,
    SYSTEM_DRV
} mmi_am_driver_enum;

/* App Type */
typedef enum
{
    SHORTCUT_APP,
    ROM_APP,
    DOWNLOAD_APP
} mmi_am_app_type_enum;

/* Search vxp files states */
typedef enum
{
    SEARCH_NONE,
    SEARCHING,
    SEARCHING_CARD, /* Searching for plug in memory card */
    SEARCH_DONE
} mmi_am_search_state_enum;

/* Launch application states */
typedef enum
{
    START_NONE,
    START_BEGIN,
    STARTING,
    START_SUCCESS,
    START_FAILURE
} mmi_am_app_start_state_enum;

/* where the app start from */
typedef enum
{
    START_FROM_NONE,
    FILE_MGR,       /* start from file manager */
    HS_SHORTCUT,    /* start from home screen shortcut */
    MAIN_MENU       /* start from main menu */
} mmi_am_quick_start_enum;

/* sim card settings */
typedef enum
{
    NO_SIM, /* no sim card */
    SIM_1,  /* the current settings is SIM 1 */
    SIM_2   /* the current settings is SIM 1 */
} mmi_am_sim_settings_enum;

/* connection settings */
typedef enum
{
    NO_ANY_CONN,    /* no gprs and wifi connection */
    GPRS,           /* gprs connection */
    WIFI            /* wifi connection */
} mmi_am_conn_settings_enum;

/* AM Shortcut App struct, excluding AppStore */
typedef struct
{
    MMI_BOOL is_downloaded;     /* is the app downloaded */
    MMI_BOOL is_hs_shortcut;    /* is the app set as home screen shortcut */
    MMI_BOOL is_bg_started;     /* is the app background start */

    U16 icon_id;                                    /* app icon resource id */
    U16 name_id;                                    /* app name resource id */
    U8 *p_name;                                     /* app name pointer (ZiMo) */
    U32 name_size;
    U32 name_len;
    U16 path[MMI_AM_MAX_SHORTCUT_APP_FILE_PATH];    /* app full path */
} mmi_am_shortcut_app_struct;

/* AM AppStore struct */
typedef struct
{
    MMI_BOOL is_downloaded;     /* is the app downloaded */
    MMI_BOOL is_hs_shortcut;    /* is the app set as home screen shortcut */
    MMI_BOOL is_bg_started;     /* is the app background start */

    U16 icon_id;                                    /* app icon resource id */
    U16 name_id;                                    /* app name resource id */
    U8 *p_name;                                     /* app name pointer (ZiMo) */
    U32 name_size;
    U32 name_len;
    U16 path[3][MMI_AM_MAX_SHORTCUT_APP_FILE_PATH]; /* app full path */
} mmi_am_appstore_struct;

/* AM Rom App struct */
typedef struct
{
    S32 idx;                    /* display index in Category214 (rom app arrange after shortcup app) */
    MMI_BOOL is_hs_shortcut;    /* is the app set as home screen shortcut */
    MMI_BOOL is_bg_started;     /* is the app background start */

    U8 *p_icon;                         /* app icon pointer (gif) */
    U32 icon_size;
    U8 *p_name;                         /* app name pointer */
    U32 name_size;
    U32 name_len;
    U16 path[MMI_AM_MAX_APP_FILE_PATH]; /* app full path, Ex: C:\vre\0X12345678.rom */
} mmi_am_rom_app_struct;

/* filename and modify time struct */
typedef struct
{
    U16 path[MMI_AM_MAX_APP_FILE_PATH]; /* app full path */
    FS_DOSDateTime time;                /* app file modify time */
} mmi_am_vxp_file_struct;
/*Vogins_20100625_start*/
typedef struct 
{
	kal_bool am_entry_flag;
	kal_bool sc_download_flag;	
}am_prompt_struct;
/*Vogins_20100625_end*/
/*vogins_20100707_start*/
typedef struct
{
	kal_bool am_relaunch_tag;
	U16 path[MMI_AM_MAX_APP_FILE_PATH];
}mmi_am_relaunch_struct;
/*vogins_20100707_end*/
/* AM context struct */
typedef struct
{
    void *dyn_mem_pool;
    MMI_BOOL has_small_font;                    /* Are there Chinese small fonts(14 pixels). */
    mmi_am_sim_settings_enum sim_settings;      /* sim card settings */
    mmi_am_conn_settings_enum conn_settings;    /* connection settings */
    MMI_BOOL is_vre_init;                       /* is vre core initial success */
    MMI_BOOL is_goback;                         /* is go back from app */
    mmi_am_app_start_state_enum start_state;    /* application start state */
    KAL_ADM_ID adm_pool_id;                     /* ADM pool id */

    MMI_BOOL is_launch_vas;         /* is launch AppStore */
    MMI_BOOL is_card_plug_in;       /* is memory card plug in */
    MMI_BOOL is_card_plug_out;      /* is memory card plug out */
    MMI_BOOL is_app_update;         /* is app update */
    MMI_BOOL is_app_in_card;        /* using for memory card plug out */
    MMI_BOOL is_alloc_asm_fail;     /* allocate memory fail */
    MMI_BOOL is_prompt_update_cdr;  /* prompt user to update cdr */
    S8 apn_check_ret; //20100714

    /* AM app lists */
    mmi_am_appstore_struct appstore_list;   /* AppStore list */
    mmi_am_shortcut_app_struct *shortcut_app_list;
    S32 shortcut_app_num;                   /* include AppStore */
    mmi_am_rom_app_struct *rom_app_list;
    S32 rom_app_num;

    /* vxp file info list */
    sml_list_t *vxp_file_list;  /* all download app file info - mmi_am_vxp_file_struct */

    /* vre folder handle */
    FS_HANDLE card_vre_folder_hdl;
    FS_HANDLE phone_vre_folder_hdl;

    U16 *app_launch_path;
} mmi_am_cntx_struct;

/* AM quick start struct */
typedef struct
{
    mmi_am_shortcut_id_enum app_id;
    MMI_BOOL is_quick_start;                    /* is app quick start */
    MMI_BOOL is_download;                    /* if the app does not exist, then need to download it */
    /*vogins 100726 begin*/
    MMI_BOOL is_not_enough_memory;   /* when launch app, can not get enough memory */
    mmi_am_quick_start_enum quick_start_flag;   /* where the app start from */
    U16 path[MMI_AM_MAX_APP_QUICK_START_PATH];  /* app full path */
} mmi_am_quick_start_struct;

/* AM async search struct */
typedef struct
{
    S32 search_hdl;                         /* current search file handle */
    mmi_am_search_state_enum search_state;  /* state of search vxp files */
    S8 cur_driver;                          /* current search driver */
} mmi_am_async_search_struct;

/*vogins_20100726_start*/
typedef struct
{
	U8* file_id;
	S32 file_size;
	U8* file_name;
}mmi_am_filesize_struct;

typedef struct
{
	U8 file_count;
	S32 dl_index;
	mmi_am_filesize_struct* dl_file_list;
}mmi_am_dl_filesize_cntx_struct;

typedef struct
{
	U8* dll_id;
	U8 update_flag;
}mmi_am_check_dll_struct;

typedef struct
{
	U8 dll_count;
	mmi_am_check_dll_struct* dll_list;
}mmi_am_check_dll_cntx_struct;

typedef struct
{
	S32 strlength;
	U8 pDownloadList[30];
}mmi_am_downlaod_list_cntx;

typedef struct
{
	U8 dll_version[6];
}mmi_am_sm_cntx_struct;
/*vogins_20100726_end*/
extern mmi_am_rom_app_struct *mmi_am_get_rom_appinfo_by_idx(S32 idx);
extern void mmi_am_entry_loading_scrn(void);
extern void mmi_am_delete_node_from_vxplist_by_index(S32 idx);
extern MMI_BOOL mmi_am_app_launch(U16 *app_path);
extern MMI_BOOL mmi_am_check_vre_folder(void);
extern void mmi_am_download_app_from_mm_deinit(void);

#endif /* AM_DEF_H */ 

