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
 *   AMProxy.c
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   
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
        #include "GlobalDefs.h"
        #include "SettingProfile.h"
    #else
        #include "MMI_frm_gprot.h"
    #endif
    #ifdef __MMI_DUAL_SIM_MASTER__
        #include "MTPNP_AD_master_if.h"
    #endif  /* __MMI_DUAL_SIM_MASTER__ */
    #ifdef __MMI_WLAN_FEATURES__
        #include "NetworkSetupDefs.h"
    #endif

    #include "CommonScreens.h"

/* VRE Core Header File */
    #include "vmenv.h"
    #include "vmsys.h"
    #include "vmcert.h"
    #include "vmmullang.h"
    #include "vmgettag.h"
    /*Vogins_20100726_start*/
    #include "vmsm.h"
    /*Vogins_20100726_end*/
    #include "AMGprot.h"
    #include "AMProxy.h"
    #include "AMUtil.h"
#define RUN_WITH_PARAM_TEST
/*****************************************************************************/

/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/
static MMI_AM_VRE_EVT_CB_T g_am_load_core_cb;
/*vogins 0726 begin*/
static MMI_AM_VRE_APP_EVT_CB_T g_am_launch_app_cb;

static MMI_AM_DL_APP_CB_T g_am_dl_app_cb;
static MMI_AM_SYNC_CDR_CB_T g_am_sync_cdr_cb;
extern mmi_am_quick_start_struct g_am_qs_cntx;
extern mmi_am_cntx_struct g_am_cntx;

/***************************************************************************** 
* Extern Function
*****************************************************************************/
extern pBOOL mmi_bootup_is_network_service_available(void);
    #ifdef AM_09A
extern pBOOL mmi_bootup_get_active_flight_mode(void);
    #endif

/*****************************************************************************
 * FUNCTION
 *  mmi_am_vre_load_core_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_vre_load_core_cb(MMI_AM_START_VRE_EVT evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt)
    {
    case VRE_EVT_START_SUCCESS:
        g_am_load_core_cb(MMI_AM_VRE_START_SUCCESS);
        break;

    case VRE_EVT_START_INTERNEL_ERROR:
        g_am_load_core_cb(MMI_AM_VRE_START_INTERNEL_ERROR);
        break;

    case VRE_EVT_QUIT:
        g_am_load_core_cb(MMI_AM_VRE_QUIT);
        break;

    default:
        break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_vre_load_core
 * DESCRIPTION
 *  
 * PARAMETERS
 *  am_cb       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_AM_LOAD_VRE_CORE mmi_am_vre_load_core(MMI_AM_VRE_EVT_CB_T am_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    MMI_AM_LOAD_VRE_CORE load_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_am_load_core_cb = am_cb;
    ret = vm_vam_load_core((vm_vre_evt_cb_t) mmi_am_vre_load_core_cb);

    switch (ret)
    {
    case VM_VLC_START_SUCCESS:
        load_ret = MMI_AM_VLC_START_SUCCESS;
        break;
    case VM_VLC_ASYN_ALLOC_ASM:
        load_ret = MMI_AM_VLC_ASYN_ALLOC_ASM;
        break;
    case VM_VLC_MASS_STORAGE:
        load_ret = MMI_AM_VLC_MASS_STORAGE;
        break;
    case VM_VLC_MEDIA_BUFFER_ALLOC_ERROR:
        load_ret = MMI_AM_VLC_MEDIA_BUFFER_ALLOC_ERROR;
        break;
    case VM_VLC_INTERNEL_ERROR:
        load_ret = MMI_AM_VLC_INTERNEL_ERROR;
        break;
    default:
        load_ret = MMI_AM_VLC_INTERNEL_ERROR;
        break;
    }

    return load_ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_vre_unload_core
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_vre_unload_core(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vm_vam_unload_core();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_vre_set_am_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_vre_set_am_state(MMI_AM_STATES state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (state)
    {
    case MMI_AM_IN_USE:
        vm_vam_set_vam_state(VAM_IN_USE);
        break;
    case MMI_AM_OUT_OF_USE:
        vm_vam_set_vam_state(VAM_OUT_OF_USE);
        break;
    default:
        break;
    }
}

#ifndef WIN32

/*****************************************************************************
 * FUNCTION
 *  mmi_am_vre_launch_app_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_path     [IN]    
 *  evt     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_vre_launch_app_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_am_launch_app_cb();    
}
/*****************************************************************************
 * FUNCTION
 *  mmi_am_vre_execute
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_path        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_AM_START_RESULT mmi_am_vre_execute(U16 *app_path, MMI_AM_VRE_APP_EVT_CB_T app_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    MMI_AM_START_RESULT start_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 

/*vogins_20100714_start*/
#ifdef RUN_WITH_PARAM_TEST
	/* add by zaiping.chen, 2010.6.29, just for test run with param, start */
	VMINT8 path[50];
	VMWCHAR file[100];
	vm_fileinfo_ext direntry;
	VMINT handle;
    
	sprintf(path, "C:\\vre\\para.vxp");
	vm_gb2312_to_ucs2(file, 100, path);
	handle = vm_find_first_ext(file, &direntry);
	if (handle >= 0)
	{
		vm_find_close_ext(handle);
		ret = vm_execute_ex(file, (VMWSTR) app_path);
	}
	else
	{
	/* add by zaiping.chen, 2010.06.29, just for test run with param, end */
#endif
    g_am_launch_app_cb = app_cb;
    ret = vm_execute((VMWSTR) app_path,  g_am_launch_app_cb);
#ifdef RUN_WITH_PARAM_TEST
	}
#endif
/*vogins_20100714_end*/

    switch (ret)
    {
    case VM_EXECUTE_APP_SUCCESS:
        start_ret = MMI_AM_EXECUTE_APP_SUCCESS;
        break;
    case VM_EXECUTE_APP_ILLEGAL:
        start_ret = MMI_AM_EXECUTE_APP_ILLEGAL;
        break;
    case VM_EXECUTE_APP_NOT_ENOUGH_MEMORY:
        start_ret = MMI_AM_EXECUTE_APP_NOT_ENOUGH_MEMORY;
        break;
        /* jie.chen 06/02/2010 begin */
    case VM_EXECUTE_EXCEED_MAX_APP_NUM:
        start_ret = MMI_AM_EXECUTE_EXCEED_MAX_APP_NUM;
        break;
        /* jie.chen 06/02/2010 end */
        /*michael 100415 begin*/
    case VM_EXECUTE_SYS_NOT_ENOUGH_MEMORY:
        start_ret = MMI_AM_EXECUTE_SYS_NOT_ENOUGH_MEMORY;
        break;
        /*michael 100415 end*/
    case VM_EXECUTE_APP_CALL_STACK_FULL:
        start_ret = MMI_AM_EXECUTE_APP_CALL_STACK_FULL;
        break;
    case VM_EXECUTE_INTERNAL_ERROR:
        start_ret = MMI_AM_EXECUTE_INTERNAL_ERROR;
        break;
    case VM_EXECUTE_PLATFORM_PARAM_DISMATCH:
        start_ret = MMI_AM_EXECUTE_PLATFORM_PARAM_DISMATCH;
        break;
    case VM_EXECUTE_TIMESTAMP_ERROR:
        start_ret = MMI_AM_EXECUTE_TIMESTAMP_ERROR;
        break;
    case VM_EXECUTE_BANNED_APP:
        start_ret = MMI_AM_EXECUTE_BANNED_APP;
        break;
    case VM_EXECUTE_IMSI_DISMATCH:
        start_ret = MMI_AM_EXECUTE_IMSI_DISMATCH;
        break;
    case VM_EXECUTE_CERT_OVERDUE:
        start_ret = MMI_AM_EXECUTE_CERT_OVERDUE;
        break;
    case VM_EXECUTE_EXCEED_FILE_IN_VRE_DIRECTORY:
        start_ret = MMI_AM_EXECUTE_EXCEED_FILE_IN_VRE_DIRECTORY;
        break;
    default:
        start_ret = MMI_AM_EXECUTE_APP_ILLEGAL;
        break;
    }

    return start_ret;
}
#else /* WIN32 */ 
#include "vredef.h"


/*****************************************************************************
 * FUNCTION
 *  mmi_am_vre_execute_exit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_vre_execute_exit(void)
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
 *  mmi_am_vre_execute_del_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static U8 mmi_am_vre_execute_del_scrn(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_FALSE;
}
#else /* AM_09A */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_am_vre_execute_leave_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_am_vre_execute_leave_scrn(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_RET_OK;
}
#endif /* AM_09A */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_am_vre_execute_enter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_vre_execute_enter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_enter(
                      GRP_ID_VRE,
                      VRE_SCREEN_ID,
                      (FuncPtr) mmi_am_vre_execute_exit,
                      (FuncPtr) mmi_am_vre_execute_enter,
                      NULL);

#ifdef AM_09A
#ifdef __VRE_AM_08AB__
    SetDelScrnIDCallbackHandler(VRE_SCREEN_ID, (HistoryDelCBPtr) mmi_am_vre_execute_del_scrn);
#else
    mmi_frm_set_destroy_scrn_callback(VRE_SCREEN_ID, (HistoryDelCBPtr) mmi_am_vre_execute_del_scrn);
#endif
#else /* AM_09A */ 
    /* set leave proc */
    mmi_frm_scrn_set_leave_proc(GRP_ID_VRE, VRE_SCREEN_ID, mmi_am_vre_execute_leave_scrn);
#endif /* AM_09A */ 

    ShowCategory65Screen(NULL, NULL, NULL);

    for (i = 0; i < 3000000000; i++);

    SetKeyHandler(GoBackHistory, KEY_RSK, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_vre_execute_grp_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_am_vre_execute_grp_proc(mmi_event_struct *evt)
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
 *  mmi_am_vre_execute
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_path        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_AM_START_RESULT mmi_am_vre_execute(U16 *app_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_enter_ex(GRP_ID_ROOT, GRP_ID_VRE, mmi_am_vre_execute_grp_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_am_vre_execute_enter();

    return MMI_AM_EXECUTE_APP_SUCCESS;
}
#endif /* WIN32 */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_am_vre_app_is_running
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_path        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_am_vre_app_is_running(U16 *app_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = vm_vam_app_is_running((VMWSTR) app_path);

    if (ret == 1)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_vre_load_resource_from_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_path        [IN]        
 *  res_name        [IN]        
 *  res_size        [OUT]       
 *  cache_buf       [IN]        
 *  cache_size      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_am_vre_load_resource_from_file(
                                           U16 *app_path,
                                           S8 *res_name,
                                           S32 *res_size,
                                           S8 *cache_buf,
                                           S32 cache_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef MMI_AM_USING_VRE_MEM
    ret = vm_vam_load_resource(
                        (short*)app_path,
                        (char*)res_name,
                        (char*)cache_buf,
                        (unsigned int*)&cache_size);
#else
    ret = vm_vam_load_resource_from_file(
                                        (short*)app_path,
                                        (char*)res_name,
                                        (int*)res_size,
                                        (char*)cache_buf,
                                        (int)cache_size);
#endif
    if (ret == 0)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_vre_get_gif_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gifzm           [IN]        
 *  data_buf        [OUT]       
 *  data_len        [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_am_vre_get_gif_data(S8 *gifzm, U8 **data_buf, S32 *data_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = vm_vam_get_gif_data((VMUINT8*) gifzm, (VMUINT8 **) data_buf, (VMINT*) data_len);

    if (ret == 0)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_vre_get_string_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gifzm           [IN]        
 *  data_buf        [IN]        
 *  lan             [IN]        
 *  str_len         [OUT]       
 *  font            [OUT]       
 *  data_size       [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_am_vre_get_string_data(
                                   S8 *gifzm,
                                   U8 **data_buf,
                                   MMI_AM_LANGUAGE_TYPE lan,
                                   S32 *str_len,
                                   S32 *font,
                                   S32 *data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    LANGUAGE_TYPE lan_vre;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (lan)
    {
    case MMI_AM_ENG:
        lan_vre = ENG;
        break;
    case MMI_AM_CHS:
        lan_vre = CHS;
        break;
    case MMI_AM_CHT:
        lan_vre = CHT;
        break;
    default:
        lan_vre = CHS;
        break;
    }

    ret = vm_vam_get_string_data(
                                (VMUINT8*) gifzm,
                                (VMUINT8 **) data_buf,
                                (LANGUAGE_TYPE) lan_vre,
                                (VMINT*) str_len,
                                (VMINT*) font,
                                (VMINT*) data_size);

    if (ret == 0)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_vre_measure_zimo_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  zimo_buf        [IN]        
 *  str_len         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_am_vre_measure_zimo_string(S8 *zimo_buf, S32 str_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 zimo_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    zimo_len = vm_vam_measure_zimo_string((VMUINT8*) zimo_buf, (VMINT) str_len);
    if (zimo_len == -1)
    {
        zimo_len = 0;
    }

    return zimo_len;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_vre_cancel_download
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_vre_cancel_download(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vm_vam_cancel_download();
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_PROXY_CANCEL_DOWNLOAD, mmi_am_get_total_left_size());
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_vre_set_sim_card
 * DESCRIPTION
 *  
 * PARAMETERS
 *  choose_index        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_am_vre_set_sim_card(S32 choose_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = vm_vam_set_sim_card(choose_index);

    if (ret == 0)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_vre_set_net_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  net_type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_am_vre_set_net_type(S32 net_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = vm_vam_set_net_type(net_type);

    if (ret == 0)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_vre_get_sim_card
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_index       [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_am_vre_get_sim_card(S32 *sim_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = vm_vam_get_sim_card(sim_index);

    if (ret == 1)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_vre_get_net_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  net_type        [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_am_vre_get_net_type(S32 *net_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = vm_vam_get_net_type(net_type);

    if (ret == 1)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_vre_pre_download_app
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mem_calloc_cb       [IN]        
 *  mem_free_cb         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_vre_pre_download_app(void *(*mem_calloc_cb) (int size), void (*mem_free_cb) (void *ptr))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_vre_pre_download_app() -- free mem:%d", mmi_am_get_total_left_size());
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_PROXY_PRE_DOWNLOAD, mmi_am_get_total_left_size());
    vm_am_pre_download_app(mem_calloc_cb, mem_free_cb);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_vre_download_app_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nResult         [IN]        
 *  nPercent        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_vre_download_app_cb(S32 nResult, S32 nPercent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_AM_DOWNLOAD_APP_RESULT dl_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (nResult)
    {
    case VAM_DL_DONE:
        dl_ret = MMI_AM_DL_DONE;
        break;
    case VAM_DL_OK:
        dl_ret = MMI_AM_DL_OK;
        break;
    case VAM_DL_ERR:
        dl_ret = MMI_AM_DL_ERR;
        break;
    case VAM_DL_NET_ERR:
        dl_ret = MMI_AM_DL_NET_ERR;
        break;
    case VAM_DL_SAVE_ERR:
        dl_ret = MMI_AM_DL_SAVE_ERR;
        break;
    case VAM_DL_APP_NOT_EXIST:
        dl_ret = MMI_AM_DL_APP_NOT_EXIST;
        break;
    case VAM_DL_SPACE_FULL:
        dl_ret = MMI_AM_DL_SPACE_FULL;
        break;
    case VAM_DL_OTHER_ERR:
        dl_ret = MMI_AM_DL_OTHER_ERR;
        break;
    case VAM_DL_FILE_NOT_EXIST:
        dl_ret = MMI_AM_DL_FILE_NOT_EXIST;
        break;
    case VAM_DL_IO_ERROR:
        dl_ret = MMI_AM_DL_IO_ERROR;
        break;
        /* Vogins 0528 begin */
    case VAM_DL_1302_ERR:
        dl_ret = MMI_AM_DL_1302_ERR;
        break;
    case VAM_DL_1401_ERR:
        dl_ret = MMI_AM_DL_1401_ERR;
        break;
    case VAM_DL_1402_ERR:
        dl_ret = MMI_AM_DL_1402_ERR;
        break;
    case VAM_DL_1403_ERR:
        dl_ret = MMI_AM_DL_1403_ERR;
        break;
    case VAM_DL_1404_ERR:
        dl_ret = MMI_AM_DL_1404_ERR;
        break;
    case VAM_DL_1405_ERR:
        dl_ret = MMI_AM_DL_1405_ERR;
        break;
    case VAM_DL_1406_ERR:
        dl_ret = MMI_AM_DL_1406_ERR;
        break;
    case VAM_DL_1407_ERR:
        dl_ret = MMI_AM_DL_1407_ERR;
        break;
        /* Vogins 0528 end */
    default:
        dl_ret = MMI_AM_DL_ERR;
        break;
    }

    g_am_dl_app_cb(dl_ret, nPercent);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_vre_download_app
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dl_app_cb       [IN]        
 *  app_id          [IN]        
 *  app_name        [IN]        
 *  block_size      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_am_vre_download_app(MMI_AM_DL_APP_CB_T dl_app_cb, U32 app_id, U16 *app_name, S32 block_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_am_dl_app_cb = dl_app_cb;
    ret = vm_vam_download_app(mmi_am_vre_download_app_cb, (VMUINT32) app_id, (VMWSTR) app_name, block_size);
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_7, "mmi_am_vre_download_app() -- ret:%d", ret);
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_AM_PROXY_DOWNLOAD_APP, ret);

    if (ret == VAM_DL_OK)
    {
        return MMI_AM_DL_OK;
    }
    else
    {
        return MMI_AM_DL_ERR;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_vre_get_buildin_app_array
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_array_ptr           [OUT]       
 *  app_array_len_ptr       [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_vre_get_buildin_app_array(S32 **app_array_ptr, S32 *app_array_len_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vm_get_buildin_app_array((VMINT **) app_array_ptr, (VMINT*) app_array_len_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_vre_get_app_version
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 *  version         [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_am_vre_get_app_version(U16 *filename, S32 *version)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return vm_get_app_version((VMWSTR) filename, version);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_vre_get_vm_tag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_path        [IN]        
 *  tag_num         [IN]        
 *  buf             [OUT]       
 *  buf_size        [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_am_vre_get_vm_tag(U16 *app_path, MMI_AM_INFO_TYPE tag_num, void *buf, S32 *buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    S32 tag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (tag_num)
    {
    case INFO_DEV:
        tag = VM_CE_INFO_DEV;
        break;

    case INFO_APP_ID:
        tag = VM_CE_INFO_APP_ID;
        break;

    case INFO_NAME:
        tag = VM_CE_INFO_NAME;
        break;

    case INFO_DESC:
        tag = VM_CE_INFO_DESC;
        break;

    case INFO_BG_RUN:
        tag = VM_CE_INFO_SUPPORT_BG_RUN;
        break;

    default:
        tag = -1;
        break;
    }
#ifndef MMI_AM_USING_VRE_MEM
    ret = vm_vam_get_tag((short*)app_path, tag, buf, buf_size);
    if (ret == 0)
#else
    ret = vm_get_vm_tag((short*)app_path, tag, buf, buf_size);    
    if (ret == GET_TAG_TRUE)
#endif
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_vre_get_vm_tag_by_lang
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_path        [IN]        
 *  tag_num         [IN]        
 *  buf             [OUT]       
 *  buf_size        [OUT]       
 *  lang            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_am_vre_get_vm_tag_by_lang(
                                      U16 *app_path,
                                      MMI_AM_INFO_TYPE tag_num,
                                      void *buf,
                                      S32 *buf_size,
                                      MMI_AM_LANGUAGE_TYPE lang)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    S32 lang_id;
    S32 tag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (tag_num)
    {
    case INFO_DEV:
        tag = VM_CE_INFO_DEV;
        break;

    case INFO_NAME:
        tag = VM_CE_INFO_NAME_LIST; /* VM_CE_INFO_NAME; */
        break;

    case INFO_DESC:
        tag = VM_CE_INFO_DESC_LIST; /* VM_CE_INFO_DESC; */
        break;

    default:
        tag = -1;
        break;
    }

    switch (lang)
    {
    case MMI_AM_ENG:
        lang_id = VM_LANG_ENG;
        break;

    case MMI_AM_CHS:
        lang_id = VM_LANG_CHS;
        break;

    case MMI_AM_CHT:
        lang_id = VM_LANG_CHT;
        break;

    default:
        lang_id = VM_LANG_ENG;
        break;
    }
#ifndef MMI_AM_USING_VRE_MEM
    ret = vm_vam_get_tag_by_lang_id((short*)app_path, tag, buf, buf_size, lang_id);
    if (ret == 0)
#else
    ret = vm_get_tag_by_lang_id((short*)app_path, tag, buf, buf_size, lang_id);
    if (ret == GET_TAG_TRUE)
#endif    
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_vre_malloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *mmi_am_vre_malloc(S32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return vm_vam_malloc(size);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_vre_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  p       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_vre_free(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vm_vam_free(p);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_vre_get_sync_cdr_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_AM_UPDATE_CDR_STATE mmi_am_vre_get_sync_cdr_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    MMI_AM_UPDATE_CDR_STATE state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = vm_vam_is_sync_cdr();

    switch (ret)
    {
    case VMM_RET_NO_SYSC_CDR:
        state = MMI_AM_NO_SYSC_CDR;
        break;

    case VAM_RET_NVRAM_NEED_FOR_SYNC_CDR:
        state = MMI_AM_NVRAM_NEED_FOR_SYNC_CDR;
        break;

    case VAM_RET_TIME_NEED_FOR_SYNC_CDR:
        state = MMI_AM_TIME_NEED_FOR_SYNC_CDR;
        break;

    default:
        state = MMI_AM_NO_SYSC_CDR;
        break;
    }

    return state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_vre_sync_cdr_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nResult     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_am_vre_sync_cdr_cb(S32 nResult)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_am_sync_cdr_cb(nResult);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_vre_sync_cdr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sync_cdr_cb     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_am_vre_sync_cdr(MMI_AM_SYNC_CDR_CB_T sync_cdr_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_am_sync_cdr_cb = sync_cdr_cb;
    ret = vm_vam_sync_cdr(mmi_am_vre_sync_cdr_cb);

    if (ret == VAM_DL_OK)
    {
        return MMI_AM_DL_OK;
    }
    else
    {
        return MMI_AM_DL_ERR;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_vre_sync_cdr_cancel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_vre_sync_cdr_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vm_vam_cancel_sync_cdr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_vre_get_user_balance
 * DESCRIPTION
 *  
 * PARAMETERS
 *  user_balance        [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_am_vre_get_user_balance(U32 *user_balance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = vm_vam_get_user_balance(user_balance);

    if (ret == 0)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


MMI_BOOL mmi_am_is_network_service_available(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef AM_09A
    /* 
     * If flight mode is on, the network is always unavailable. 
     */
#ifdef __MMI_DUAL_SIM_MASTER__
    if (mmi_bootup_get_active_flight_mode() == FLIGHTMODE_SILENT && 
        MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_FLIGHT)
    {
        return MMI_FALSE;
    }
#else
    if (mmi_bootup_get_active_flight_mode() == FLIGHTMODE_SILENT)
    {
        return MMI_FALSE;
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */

    /*
     * On WLAN project, if WLAN is not GSM only, network is always available.
     */
#ifdef __MMI_WLAN_FEATURES__
    if (mmi_netset_get_active_preferred_mode() != P_GSM_ONLY)
    {
        return MMI_TRUE;
    }
#endif /* __MMI_WLAN_FEATURES__ */

    /*
     * Then, check the SIM status.
     */
#ifndef __MMI_DUAL_SIM_MASTER__
    if (mmi_bootup_is_sim_valid())
    {
        return MMI_TRUE;
    }
#else
    if (MTPNP_AD_Get_UsableSide() == MTPNP_AD_SIMCARD1_USABLE ||
        MTPNP_AD_Get_UsableSide() == MTPNP_AD_SIMCARD2_USABLE ||
        MTPNP_AD_Get_UsableSide() == MTPNP_AD_DUALSIM_USABLE)
    {
        return MMI_TRUE;
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */

    return MMI_FALSE;
#else
    return mmi_bootup_is_network_service_available();
#endif
}

#ifdef AM_09A
#include "AMResDef.h"
#include "AMProt.h"


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_group_enter_ex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_id       [IN]        
 *  group_id        [IN]        
 *  proc            [IN]        
 *  user_data       [IN]        
 *  flag            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_frm_group_enter_ex(U16 parent_id, U16 group_id, mmi_proc_func proc, void *user_data, S16 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_scrn_enter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_id       [IN]        
 *  scrn_id         [IN]        
 *  exit_proc       [IN]        
 *  entry_proc      [IN]        
 *  scrn_type       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_frm_scrn_enter(
                           U16 parent_id,
                           U16 scrn_id,
                           FuncPtr exit_proc,
                           FuncPtr entry_proc,
                           mmi_frm_scrn_type_enum scrn_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(scrn_id, exit_proc, entry_proc, NULL);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_scrn_close_active_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_scrn_close_active_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetActiveScreenId() == SCR_ID_AM_MAIN)
    {
        GoBackHistory();
        mmi_frm_group_close(GRP_ID_AM);
    }
    else
    {
        GoBackHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_scrn_get_active_gui_buf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 *mmi_frm_scrn_get_active_gui_buf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return GetCurrGuiBuffer(GetActiveScreenId());
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_scrn_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_id       [IN]        
 *  scrn_id         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_frm_scrn_close(U16 parent_id, U16 scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* return DeleteScreens(scrn_id, scrn_id); */
    return DeleteScreenIfPresent(scrn_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_group_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  group_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_frm_group_close(U16 group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_am_qs_cntx.is_quick_start && !g_am_cntx.is_alloc_asm_fail)
    {
        if (!g_am_qs_cntx.is_not_enough_memory)
        {
            g_am_qs_cntx.is_quick_start = MMI_FALSE;
        }
        /* Unload VRE Core */
        mmi_am_vre_unload_core();

        /* set VRE Core flag */
        g_am_cntx.is_vre_init = MMI_FALSE;

        ret = MMI_RET_OK;
    }
    else if (!g_am_qs_cntx.is_quick_start)
    {
        /* ret = DeleteScreens(SCR_ID_AM_LOADING, SCR_ID_AM_DETAILS); */
        DeleteScreenIfPresent(SCR_ID_AM_SETTINGS);
        DeleteScreenIfPresent(SCR_ID_AM_SETTINGS_SIM);
        DeleteScreenIfPresent(SCR_ID_AM_SETTINGS_CONN);
        DeleteScreenIfPresent(SCR_ID_AM_DETAILS);
        DeleteScreenIfPresent(SCR_ID_AM_DOWNLOAD_PROGRESS);
        DeleteScreenIfPresent(SCR_ID_AM_OPTIONS);
        DeleteScreenIfPresent(SCR_ID_AM_LOADING);
        DeleteScreenIfPresent(SCR_ID_AM_MAIN);
        /* mmi_am_grp_deinit(); */
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_scrn_is_present
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_id       [IN]        
 *  scrn_id         [IN]        
 *  flag            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_frm_scrn_is_present(U16 parent_id, U16 scrn_id, S16 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return IsScreenPresent(scrn_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_display_popup_with_sg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_id       [IN]        
 *  string          [IN]        
 *  event_id        [IN]        
 *  flags           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_display_popup_with_sg(U16 parent_id, UI_string_type string, mmi_event_notify_enum event_id, U32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __VRE_AM_08AB__
    MMI_ID_TYPE message_image;
    U8 toneId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event_id)
    {
    case MMI_EVENT_FAILURE:
        message_image = IMG_GLOBAL_ERROR;
        toneId = ERROR_TONE;
        break;

    case MMI_EVENT_INFO:
        message_image = IMG_GLOBAL_INFO;
        toneId = WARNING_TONE;
        break;

    case MMI_EVENT_WARNING:
        message_image = IMG_GLOBAL_WARNING;
        toneId = WARNING_TONE;
        break;

    case MMI_EVENT_SUCCESS:
        message_image = IMG_GLOBAL_ACTIVATED;
        toneId = SUCCESS_TONE;
        break;

    case MMI_EVENT_QUERY:
        message_image = IMG_GLOBAL_QUESTION;
        toneId = WARNING_TONE;
        break;

    default:
        message_image = IMG_GLOBAL_INFO;
        toneId = WARNING_TONE;
        break;
    }

    //mmi_display_popup(string, event_id);
    DisplayPopup((U8*) string, message_image, 0, 2000, toneId);
#else
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_display_popup(string, event_id);
#endif
    return MMI_TRUE;
}
        #ifdef __VRE_AM_08AB__
void mmi_display_popup(UI_string_type string, mmi_event_notify_enum event_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID_TYPE message_image;
    U8 toneId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event_id)
    {
    case MMI_EVENT_FAILURE:
        message_image = IMG_GLOBAL_ERROR;
        toneId = ERROR_TONE;
        break;

    case MMI_EVENT_INFO:
        message_image = IMG_GLOBAL_INFO;
        toneId = WARNING_TONE;
        break;

    case MMI_EVENT_WARNING:
        message_image = IMG_GLOBAL_WARNING;
        toneId = WARNING_TONE;
        break;

    case MMI_EVENT_SUCCESS:
        message_image = IMG_GLOBAL_ACTIVATED;
        toneId = SUCCESS_TONE;
        break;

    case MMI_EVENT_QUERY:
        message_image = IMG_GLOBAL_QUESTION;
        toneId = WARNING_TONE;
        break;

    default:
        message_image = IMG_GLOBAL_INFO;
        toneId = WARNING_TONE;
        break;
    }

    DisplayPopup((U8*) string, message_image, 0, 2000, toneId);
}
        #endif

/*****************************************************************************
 * FUNCTION
 *  mmi_display_popup_confirm_with_sg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  parent_id               [IN]        
 *  left_softkey            [IN]        
 *  left_softkey_icon       [IN]        
 *  right_softkey           [IN]        
 *  right_softkey_icon      [IN]        
 *  message                 [IN]        
 *  event_id                [IN]        
 *  flags                   [IN]        
 * RETURNS
 *  
 *****************************************************************************/
        #ifdef __VRE_AM_08AB__
MMI_BOOL mmi_display_popup_confirm_with_sg(
                                          U16 parent_id,
                                          U16 left_softkey,
                                          U16 left_softkey_icon,
                                          U16 right_softkey,
                                          U16 right_softkey_icon,
                                          UI_string_type message,
                                          mmi_event_notify_enum event_id,
                                          U32 flags)
        #else
MMI_BOOL mmi_display_popup_confirm_with_sg(
                                          U16 parent_id,
                                          UI_string_type left_softkey,
                                          PU8 left_softkey_icon,
                                          UI_string_type right_softkey,
                                          PU8 right_softkey_icon,
                                          UI_string_type message,
                                          mmi_event_notify_enum event_id,
                                          U32 flags)
        #endif
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __VRE_AM_08AB__
    MMI_ID_TYPE message_image;
    U8 toneId;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //mmi_display_popup_confirm(left_softkey, left_softkey_icon, right_softkey, right_softkey_icon, message, event_id);

    switch (event_id)
    {
    case MMI_EVENT_FAILURE:
        message_image = IMG_GLOBAL_ERROR;
        toneId = ERROR_TONE;
        break;

    case MMI_EVENT_INFO:
        message_image = IMG_GLOBAL_INFO;
        toneId = WARNING_TONE;
        break;

    case MMI_EVENT_WARNING:
        message_image = IMG_GLOBAL_WARNING;
        toneId = WARNING_TONE;
        break;

    case MMI_EVENT_SUCCESS:
        message_image = IMG_GLOBAL_ACTIVATED;
        toneId = SUCCESS_TONE;
        break;

    case MMI_EVENT_QUERY:
        message_image = IMG_GLOBAL_QUESTION;
        toneId = WARNING_TONE;
        break;

    default:
        message_image = IMG_GLOBAL_INFO;
        toneId = WARNING_TONE;
        break;
    }


    DisplayConfirm(
                  left_softkey,
                  left_softkey_icon,
                  right_softkey,
                  right_softkey_icon,
                  message,
                  message_image,
                  toneId);
#else
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(AM_POPUP_DISABLE_SHOW_ICON)
    mmi_display_popup_confirm_with_flag(left_softkey, left_softkey_icon, right_softkey, right_softkey_icon, message, event_id, MMI_POPUP_DISABLE_SHOW_ICON);
#else
    mmi_display_popup_confirm(left_softkey, left_softkey_icon, right_softkey, right_softkey_icon, message, event_id);
#endif
#endif
    return MMI_TRUE;
}

#endif /* AM_09A */ 
void mmi_am_delete_apn_nvram(void)
{
    vm_del_nvram_apn();
}
void mmi_am_save_apn_nvram(mmi_am_apn_info *apn_info)
{
    vm_set_current_apn((vm_apn_info *)apn_info);
}
void mmi_am_save_single_vre_dcnt(mmi_am_apn_info *apn_info, U8 apn, void(*save_single_dcnt_cb)(void))
{
    vm_tcp_add_single_gprs_account(apn_info,apn,(void*)save_single_dcnt_cb);
}
void mmi_am_save_vre_dcnt(mmi_am_apn_info *apn_info, void(*save_dcnt_cb)(void))
{
    vm_tcp_add_gprs_account(apn_info,(void*)save_dcnt_cb);//vm_tcp_add_gprs_account();
}
void  mmi_am_check_apn_status(mmi_am_apn_info *apn_info, void(*check_dcnt_cb)(S8 result_value))
{
    vm_global_check_apn_status((vm_apn_info *)apn_info,check_dcnt_cb);// vm_get_current_apn((vm_apn_info *)apn_info);
}
MMI_BOOL mmi_am_check_isfirst_runing(void)
{
    MMI_BOOL ret = MMI_FALSE;
    if (vm_nvram_get_firstflag() == 0xff)
        ret = MMI_TRUE;
    return ret;
}
void mmi_am_set_dcnt_ready_status(MMI_BOOL status)
{
    vm_set_dataaccount_done((VMINT)status);
}
/*vogins_20100712_start*/
void mmi_am_vre_get_process_list(vm_running_app_info_t** bg_app_infos, U16* app_info_num)
{
	*app_info_num = vm_get_bg_app_infos(bg_app_infos);
}
/*vogins_20100712_end*/
/*vogins_20100726_start*/
U8 * mmi_am_vre_get_vreapp_name_by_id(U8 native_appid)
{
	LANGUAGE_TYPE lan_vre;
	U8 *lang = NULL;
    MMI_AM_LANGUAGE_TYPE language = MMI_AM_CHS;

	lang = Get_Current_Lang_CountryCode();
    if (strcmp((PS8) lang, "en-US") == 0)   /* means english */
    {
        language = MMI_AM_ENG;
    }
    else if (strcmp((PS8) lang, "zh-CN") == 0)
    {
        language = MMI_AM_CHS;
    }
    else if (strcmp((PS8) lang, "zh-TW") == 0)
    {
        language = MMI_AM_CHT;
    }

	switch (language)
    {
    case MMI_AM_ENG:
        lan_vre = ENG;
        break;
    case MMI_AM_CHS:
        lan_vre = CHS;
        break;
    case MMI_AM_CHT:
        lan_vre = CHT;
        break;
    default:
        lan_vre = CHS;
        break;
    }
    return (U8*)_vm_get_mem_app_name(native_appid,lan_vre);
}
/*vogins_20100712_end*/
VMINT mmi_am_check_dll_version(void(* check_dll_cb)(VMINT nResult, VMUINT8* pData, VMINT nDataLen), VMUINT8 * pCheckList)
{
	vm_vam_check_dll_version(check_dll_cb, pCheckList);
}

VMINT mmi_am_check_file_size(void(* check_cb)(VMINT nResult, VMUINT8* pData, VMINT nDataLen), VMUINT8 * pCheckList)
{
	mmi_ret ret;
	ret = vm_vam_check_filesize(check_cb, pCheckList);
	if (ret == VAM_DL_OK)
	    {
	        return MMI_AM_DL_OK;
	    }
	    else
	    {
	        return MMI_AM_DL_ERR;
	    }
}

VMINT mmi_am_query_info(VMSTR sm_name, mmi_am_sm_cntx_struct * sm_info)
{
	return vm_sm_query_info(sm_name, (vm_sm_info_t*)sm_info);
}
void mmi_am_downlaod_cancel_check(void)
{
	vm_vam_cancel_check();
}
/*Vogins_20100726_start*/

/*Vogins_20100726_end*/
#endif /* __VRE30_AM__ */ 

