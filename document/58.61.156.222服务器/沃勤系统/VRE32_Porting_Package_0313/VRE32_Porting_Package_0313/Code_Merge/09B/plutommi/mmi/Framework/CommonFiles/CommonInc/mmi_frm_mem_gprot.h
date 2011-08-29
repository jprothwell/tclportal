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
 *  mmi_frm_mem_gprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  MMI UI related functions for App-based, Screen-based ASM and Resource Memroy Manager
 *
 *  (Other API are declared in app_mem.h)
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef MMI_FRM_MEM_GPROT_H
#define MMI_FRM_MEM_GPROT_H

#ifdef __cplusplus
extern "C"
{
#endif


#include "mmu.h"    /* for kal_adm_alloc_noncacheable() */
#include "app_mem.h"
#include "mmidatatype.h"

/* DOM-NOT_FOR_SDK-BEGIN */
typedef void*   (*MemAlloc) (U32);
typedef void    (*MemFree) (void *);
typedef void*   (*mmi_malloc_func_ptr) (U32 size, void *arg);
typedef void    (*mmi_mfree_func_ptr) (void *ptr, void *arg);
/* DOM-NOT_FOR_SDK-END */

#ifndef OSL_MEMORY_INT_H
#define OSL_MEMORY_INT_H
/*----------------------------------------------------------------*
  General Memory
 *----------------------------------------------------------------*/
/***************************************************************************** 
 * Define
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  MMI_FRM_ADM_ALLOC_FRAMEBUFFER
 * DESCRIPTION
 *  This function is to allocate non-cacheable memory, it also can switch cacheable memory
 *  to noncacheable. Should pay attention to the memory size, this size may be required to 32 bytes align.
 * PARAMETERS
 *  adm_id   : [IN]   KAL ADM id.
 *  size     : [IN]   Memory size need to allocate. 
 * RETURNS
 *  Address of allocated memory with noncacheable setting.
 * EXAMPLE
 * <code>
 * KAL_ADM_ID adm_id;
 * void *buff_ptr;
 * adm_id = kal_adm_create(buffer_pool,sizeof(buffer_pool), chunk, MMI_FALSE);
 * buff_ptr = MMI_FRM_ADM_ALLOC_FRAMEBUFFER(adm_id, size);
 * ..................
 * kal_adm_free(adm_id, buff_ptr);
 * </code>
 *****************************************************************************/
#define MMI_FRM_ADM_ALLOC_FRAMEBUFFER(adm_id, size)   kal_adm_alloc_nc_align(adm_id, size, __MMI_GDI_LAYER_FRAMEBUF_ALIGNMENT__)
 
/*****************************************************************************
 * FUNCTION
 *  mmi_malloc
 * DESCRIPTION
 *  This function is to allocate memory from control buffer. Applications should
 *  use this carefully. If the size is larger than 512B, we suggest application
 *  not use control buffer.
 * PARAMETERS
 *  size     : [IN]   Memory size need to allocate from control buffer. 
 * RETURNS
 *  Address of allocated memory.
 * EXAMPLE
 * <code>
 * U32 buffer_size;
 * void *ptr = mmi_malloc(buffer_size);
 * </code>
 *****************************************************************************/
#define mmi_malloc(size)    get_ctrl_buffer(size)

/*****************************************************************************
 * FUNCTION
 *  mmi_mfree
 * DESCRIPTION
 *  This function is to release memory from control buffer.
 * PARAMETERS
 *  buff     : [IN]   The memory pointer that need to be free. 
 * RETURNS
 *  void
 *****************************************************************************/
#define mmi_mfree(ptr)      free_ctrl_buffer(ptr)

/* DOM-NOT_FOR_SDK-BEGIN */
#define OslMalloc(size)     mmi_malloc(size)
#define OslMfree(ptr)       mmi_mfree(ptr)
/* DOM-NOT_FOR_SDK-END */
#endif /* OSL_MEMORY_INT_H */



#ifndef _APP_MEM_MGR_GPROT_INT_H_
#define _APP_MEM_MGR_GPROT_INT_H_
/*----------------------------------------------------------------*
  App-based ASM
 *----------------------------------------------------------------*/
/***************************************************************************** 
 * ASM manager description:
 * To make asm manager mechanism easy to use and maitain, we decide not to
 * support reentry function of asm screens. There are some mechanism to prevent reentry
 * case and make asm manager simple:
 *
 * 1. Press END key will delete asm screens and won't invoke success callback;
 * 2. Callback of incoming call (mmi_frm_appmem_ucm_cb_hdlr) will also delete asm 
 *    screens to prevent reentry and won't invoke success callback;
 * 3. Provide cancel callback to notify application when asm manager is terminated
 *    without invoking success callback and launching new application;
 * 
 * Please refer the test cases mmi_frm_appmem_ut_end_key_behavior_progress_scrn, mmi_frm_appmem_ut_end_key_behavior_startnew_scrn
 * mmi_frm_appmem_ut_ucm_behavior_progress_scrn, mmi_frm_appmem_ut_ucm_behavior_startnew_scrn for
 * the detail work flow of previous description.
 *
 ****************************************************************************/

/***************************************************************************** 
 * Define
 *****************************************************************************/
/* DOM-NOT_FOR_SDK-BEGIN */
/* Max number of applications shown in the "Stop Application" screen */
#define MMI_FRM_APPMEM_MAX_APP_PROMPTED     (10)
#define MMI_FRM_APPMEM_PROMPT_INFO_START_PIXEL_OFFSET  (4)

#define APPMEM_STR_NON_DEFINED     STR_GLOBAL_END
/* DOM-NOT_FOR_SDK-END */

/* The return value of event "EVT_ID_MEM_FREE_ASM", the event should be processed in 
   root screen group applications */
typedef enum {
    /* Notify framework the memory is freed */
    MMI_MEM_FREED = MMI_RET_OK + 1,
    /* Notify framework the memory is waiting to free */
    MMI_MEM_WAITING_TO_FREE,
    /* Notify framework the memory can not be freed */
    MMI_MEM_FREE_FAIL,
    /* enum end */
    MMI_MEM_END
} mmi_frm_appmem_result_enum;

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/


/* This enum is for app-based ASM cancel callback event type */
typedef enum
{
    /* cancel callback event type start */
    MMI_FRM_APPMEM_CANCEL_BACK_FROM_PROMPT_SCRN,
    /* cancel callback by UCM Call */
    MMI_FRM_APPMEM_CANCEL_BY_UCM_CALL,
    /* cancel callback by user press end key */
    MMI_FRM_APPMEM_CANCEL_BY_END_KEY,
    /* cancel callback by interrupt, some interrupt will goback to idle,such as usb plug in, sim card plug in */
    MMI_FRM_APPMEM_CANCEL_DEL_BY_INTERRUPT,
    /* cancel callback event total num */
    MMI_FRM_APPMEM_CANCEL_TYPE_TOTAL
} mmi_frm_appmem_event_type_enum;


/* This struct is for app-based ASM cancel callback event */
typedef struct
{
    /* cancel callback event type */
    mmi_frm_appmem_event_type_enum evt_type;
    /* the app id that ask for release memory */
    mmi_id app_id;
} mmi_frm_appmem_evt_struct;



/*****************************************************************************
 * CALLBACK
 *  translate key handler
 * DESCRIPTION
 * This is cancel callback function type, when prompt release screen is canceled
 ******************************************************************************/
typedef void (*mmi_frm_appmem_cb)(mmi_frm_appmem_evt_struct*);

/* This is success callback function type, when app can get enough memory */
typedef void (*mmi_frm_appmem_success_cb)(void *userdata);

/******************************************************
  The cancel callback event send to app proc. Because DOM cannot
  identify Macros in the struct, please see the whole members as follow:
  
  typedef struct {
      //event header
      MMI_EVT_PARAM_HEADER
      //app id which need to be sent 
      mmi_id app_id;
      //cancel event type 
      union {
              mmi_frm_appmem_event_type_enum cancel_reason;
            } arg;
   } mmi_frm_appmem_asm_evt_struct;
 ******************************************************/
typedef struct {
    /* DOM-NOT_FOR_SDK-BEGIN */
    /* event header */
    MMI_EVT_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */
    /* app id which need to be sent */
    mmi_id app_id;
    /* DOM-NOT_FOR_SDK-BEGIN */
    /* cancel event type */
    union {
    mmi_frm_appmem_event_type_enum cancel_reason;
    } arg;
    /* DOM-NOT_FOR_SDK-END */
} mmi_frm_appmem_asm_evt_struct;


/* This enum is for event type of screen group proc. */
typedef enum {
    /* Event ID start */
    EVT_ID_MEM_BASE = RESOURCE_BASE_FRAMEWORK_ASM,
    /* Event ID that is free ASM now */
    EVT_ID_MEM_FREE_ASM,
    /* Event ID that if memory is enough */
    EVT_ID_MEM_IS_ENOUGH,
    /* Event ID that release prompt screen is canceled */
    EVT_ID_MEM_CANCELED,
    /* Event ID end */
    EVT_ID_MEM_END
} mmi_frm_appmem_evt_enum;

/* Vogins Start */
#if defined(__VRE30_AM__)
/*michael 0719 appid begin*/
#define MMI_FRM_APPMEM_MAX_HIDE_APP     (12)
/* ID of app */
typedef enum
{
    /* Normal case */
    MMI_AP_DUMMY_ID,
    MMI_AP_VRE_ID,
    MMI_AP_VRE_APP1_ID,
    MMI_AP_VRE_APP2_ID,
    MMI_AP_VRE_APP3_ID,
    MMI_AP_VRE_APP4_ID,
    MMI_AP_VRE_APP5_ID,
    MMI_AP_VRE_APP6_ID,
    MMI_AP_VRE_APP7_ID,
    MMI_AP_VRE_APP8_ID,
    MMI_AP_VRE_APP9_ID,
    MMI_AP_VRE_APP10_ID,
    MMI_AP_VRE_APP11_ID,
    MMI_AP_VRE_APP12_ID,
    MMI_AP_VRE_APP13_ID,
    MMI_AP_VRE_APP14_ID,
    MMI_AP_VRE_APP15_ID,
    MMI_AP_VRE_APP16_ID,
    MMI_AP_MED_CAMERA_ID,
    MMI_AP_MED_VIDEO_ID,
    
    MMI_AP_APP_MAX_COUNT_ID
} mmi_med_ap_appid_enum;
/*michael 0719 end*/
#endif
/* Vogins End */
/*****************************************************************************
 * Extern Global Variable 
 *****************************************************************************/


/*****************************************************************************
 * Extern Global Function 
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_init
 * DESCRIPTION
 *  Initialize app-based ASM. This is called at boot up and create ADM pool.
 *  Applications should not call this.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_appmem_init(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_prompt_to_release_mem
 * DESCRIPTION
 *  Show "insufficient memory" screen and prompt user to stop other applications in order 
 *  to release more memory.
 *  Remark: 
 *  1. This function is not suggested to be used in "interrupt screens" 
 *     (e.g. MT call or USB plug-in indication)
 *     Otherwise, it might re-enter the prompt screen and confuse user.
 *  2. 'success_callback' needs to enter a new MMI screen!
 *  3. There is a "cancel callback" registered by mmi_frm_appmem_set_cancel_callback.
 *  4. If the application is original screen based, when allocate fail, it should call
 *     this function to show "insufficient meomory" screen. The success callback must 
 *     be registered, to make framework know what to do next when the memory is enough.
 *  5. When screen group allocate ASM and don't register stop callback, 
 *     it is no need to call this function when allocate memory fail. But in group proc, 
 *     it should handle EVT_ID_MEM_IS_ENOUGH. The group that doesn't use ASM is no need to handle this.
 *
 *  Warning: This function can only be used in MMI task.
 * PARAMETERS
 *  app_name          : [IN]    Application ID
 *  app_icon          : [IN]    Image ID of the application 
 *  required_size     : [IN]    Minimum required memory for the application
 *  success_callback  : [IN]    Callback function when getting memory successfully 
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * 1. The application is screen based.
 *    applib_mem_ap_register(
 *         APPLIB_MEM_AP_ID_TEST1, 
 *         STR_GLOBAL_1, 
 *         IMG_GLOBAL_L1, 
 *         mmi_frm_appmem_unit_test_stop_1);
 *    .............
 *    mem_ptr = applib_mem_ap_alloc(...);
 *    if (mem_ptr == NULL)
 *    {
 *        mmi_frm_appmem_prompt_to_release_mem(app_name, app_icon, size, entryfunction);
 *        mmi_frm_appmem_set_cancel_callback(..);
 *    }
 * 2. If screen group allcoate App-based ASM(such as CUI).
 *    mmi_frm_group_create(parent_sg, cui_sg_id, cui_asm_test_proc, NULL);
 *    mem_ptr = applib_mem_ap_alloc(cui_sg_id, size);
 *    if (!mem_ptr)
 *        return;
 *    else
 *        cui_asm_test_run();
 *    ..........
 *    mmi_ret cui_asm_test_proc(mmi_event_struct *evt)
 *    {
 *        switch(evt->evt_id)
 *        {
 *          case EVT_ID_GROUP_DEINIT:
 *               applib_mem_ap_free(cntx_ptr->mem_ptr);
 *               break;
 *          case EVT_ID_MEM_IS_ENOUGH:
 *               mem_ptr = applib_mem_ap_alloc(cntx_ptr->asm_id, cntx_ptr->asm_size);
 *               cui_asm_test_run();
 *               break;
 *          case EVT_ID_MEM_CANCELED:
 *               cui_asm_test_close();
 *               break;
 *         }
 *       return MMI_RET_OK;
 *    }
 * </code>
 *****************************************************************************/
extern void mmi_frm_appmem_prompt_to_release_mem(
                MMI_ID_TYPE app_name, 
                MMI_ID_TYPE app_icon, 
                U32 required_size,
                void (*success_callback)(void));

/* Vogins Start */
#if defined(__VRE30_AM__)
/*michael 0719 begin*/
/*****************************************************************************
 * check memory size whether can be allocate, usually it use in the native app, ex:camerapp.c 
 *****************************************************************************/
extern MMI_BOOL med_check_memory_is_enough(U32 req_buffer_size);
/*****************************************************************************
 * clear the register appid callback and info when exit the VRE app or stop by user 
 *****************************************************************************/
extern void med_mem_ap_deregister(U8 app_id);
/*****************************************************************************
 * register the app info(appid, stringid, occupy memory size, stop callback) after media buffer malloc success 
 *****************************************************************************/
extern void med_mem_ap_register(U8 app_id, U16 app_string_id, U32 mem_size, void (*reg_stop_callback)(void));
/*****************************************************************************
 * when memory is not enough will invoke this function to enttry stop list,if stop success, it will call scuccess_callback function 
 *****************************************************************************/
extern void mmi_ap_prompt_to_release_mem(U8 app_id, U16 string_id, U32 req_buffer_size, void (*success_callback)(void));
/*****************************************************************************
 * hide the app from the memory not enough screen, it will set a hide attribute by appid 
 *****************************************************************************/
extern void med_mem_ap_set_hide_list_screen(U8 hide_appid);
/*****************************************************************************
 * retrive the app from the memory not enough screen, it will reset a hide attribute by appid 
 *****************************************************************************/
extern void med_mem_ap_clear_hide_list_screen(U8 hide_appid);
extern void mmi_frm_appmem_set_hide_list_screen(U32 hide_appid);

extern void mmi_frm_appmem_clear_hide_list_screen(U32 hide_appid);
/*michael 0719 end*/
#endif
/* Vogins End */

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_prompt_to_release_full_pool
 * DESCRIPTION
 *  Show "insufficient memory" screen and prompt user to stop other applications in order 
 *  to release more memory.
 *  This function is similar to mmi_frm_appmem_prompt_to_release_mem
 *  but it requires the whole pool.
 *
 *  Warning: This function can only be used in MMI task.
 * PARAMETERS
 *  app_name           : [IN]    Application ID 
 *  app_icon           : [IN]    Image ID of the application 
 *  success_callback   : [IN]    Callback function when getting memory successfully 
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_appmem_prompt_to_release_full_pool(
                MMI_ID_TYPE app_name, 
                MMI_ID_TYPE app_icon, 
                void (*success_callback)(void));


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_check_prompt_screen
 * DESCRIPTION
 *  if ordinary screen based app invoke asm manager just return app id, else if the app is
 *  screen group return root app id.
 * PARAMETERS
 *  void 
 * RETURNS
 *  Root app id which invoke asm manager.
 *****************************************************************************/
extern applib_mem_ap_id_enum mmi_frm_appmem_check_prompt_screen(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_set_cancel_callback
 * DESCRIPTION
 *  Cancel callback will be invoked to notify application when asm manager is cancel.
 *  E.g. user press back (RSK) in prompt screen, press END key in progressing screen or 
 *  start new application screen, interrupt goback to idle, and UCM call at any screen,
 *  which means asm manager can't launch new application due to some reasons. All cancel
 *  callback types are defined in mmi_frm_appmem_event_type_enum.
 *  1. If the application is original screen based allocate ASM fail, This api should be called after 
 *  mmi_frm_appmem_prompt_to_release_mem.
 *  2. If screen group allocate fail, just handle EVT_ID_MEM_CANCELED in group proc. It's no need to
 *  call this function.
 *  Example code please see mmi_frm_appmem_prompt_to_release_mem.
 * PARAMETERS
 *  app_id            : [IN]    application id
 *  cancel_callback   : [IN]    Function pointer of cancel callback
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_appmem_set_cancel_callback(applib_mem_ap_id_enum app_id, mmi_frm_appmem_cb cancel_callback);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_disable_auto_prompt_screen
 * DESCRIPTION
 *  disable auto-prompt when app-ASM allocation failed. Application needs to call
 *  mmi_frm_appmem_prompt_to_release_mem directly.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_appmem_disable_auto_prompt_screen(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_appmem_enable_auto_prompt_screen
 * DESCRIPTION
 *  re-enable auto-prompt when app-ASM allocation failed. Application is no need
 *  to call mmi_frm_appmem_prompt_to_release_mem, just handle events in proc.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_appmem_enable_auto_prompt_screen(void);

/* DOM-NOT_FOR_SDK-BEGIN */
#ifdef APPLIB_MEM_UNIT_TEST
extern void mmi_frm_asm_test_case_entry(U8 index);
extern MMI_BOOL mmi_frm_appmem_unit_test_setup_environment(MMI_BOOL stress_test);
extern void mmi_frm_appmem_unit_test_prepare_to_enter_test1(void (*run_callback)(void *arg), MMI_BOOL clear_all);
extern void mmi_frm_appmem_unit_test_prepare_to_enter_test2(void (*run_callback)(void *arg), MMI_BOOL clear_all);
extern void mmi_frm_appmem_unit_test_prepare_to_enter_test3(void (*run_callback)(void *arg), MMI_BOOL clear_all);
extern void mmi_frm_appmem_unit_test_prepare_to_enter_test4(void (*run_callback)(void *arg), MMI_BOOL clear_all);
extern void mmi_frm_appmem_unit_test_prepare_to_enter_test5(void (*run_callback)(void *arg), MMI_BOOL clear_all);
#endif /* APPLIB_MEM_UNIT_TEST */
/* DOM-NOT_FOR_SDK-END */

#endif /* _APP_MEM_MGR_GPROT_INT_H_ */



#ifndef _SCR_MEM_MGR_GPROT_INT_H_
#define _SCR_MEM_MGR_GPROT_INT_H_
/*----------------------------------------------------------------*
  Screen-based ASM
 *----------------------------------------------------------------*/
/***************************************************************************** 
 * Define
 *****************************************************************************/


/***************************************************************************** 
 * Typedef 
 *****************************************************************************/


/*****************************************************************************
 * Extern Global Variable 
 *****************************************************************************/


/*****************************************************************************
 * Extern Global Function 
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_scrmem_init
 * DESCRIPTION
 *  Initialize screen-based memory, create ADM pool. This function is called during
 *  power on procedure. Applications should not call this function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_scrmem_init(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_scrmem_alloc
 * DESCRIPTION
 *  Allocate screen-based ASM for the general buffer
 *  Remark:
 *  1. It might return NULL if the allocate failed.
 *  2. Please keep allocation count as few as possible; for example, allocate an
 *     array with 100 elements instead of using mmi_frm_scrmem_alloc() 100 times.
 *     Reason A: the space overheads is hard to estimate when 
 *               underlying implementation is changed.
 *     Reason B: performance is better when there are fewer allocations
 *  We suggest application allocate a total size once, and use ADM to manage the return
 *  memory pool, other than allocate many times.
 *  This function can be only used in MMI task. 
 * PARAMETERS
 *  mem_size       : [IN]        Memory size
 * RETURNS
 *  Allocated memory address
 * EXAMPLE
 * <code>
 * U32 total_size;
 * void *ptr = mmi_frm_scrmem_alloc(total_size);
 * KAL_ADM_ID adm_id = kal_adm_create(ptr, sizeof(ptr), chunk, MMI_FALSE);
 * g_buff = kal_adm_alloc(adm_id);
 * </code>
 *****************************************************************************/
#define mmi_frm_scrmem_alloc(mem_size)              mmi_frm_scrmem_alloc_int(mem_size, __LINE__)

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_scrmem_alloc_framebuffer
 * DESCRIPTION
 *  Allocate screen-based ASM for the frame buffer(noncacheable)
 *  Remark:
 *  1. It might return NULL if the allocate failed.
 *  2. Please keep allocation count as few as possible; for example, allocate an
 *     array with 100 elements instead of using mmi_frm_scrmem_alloc_framebuffer() 100 times
 * PARAMETERS
 *  mem_size       : [IN]        Memory size
 * RETURNS
 *  Allocated memory address.
 *****************************************************************************/
#define mmi_frm_scrmem_alloc_framebuffer(mem_size)  mmi_frm_scrmem_alloc_framebuffer_int(mem_size, __LINE__)

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_scrmem_free
 * DESCRIPTION
 *  Free screen-based shared memory
 * PARAMETERS
 *  mem_ptr   : [IN]      The memory block need to be free.
 * RETURNS
 *  void
 *****************************************************************************/
#define mmi_frm_scrmem_free(mem_ptr)                mmi_frm_scrmem_free_int(mem_ptr, __LINE__)
    

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_scrmem_get_available_size
 * DESCRIPTION
 *  Get total left size of screen-based memory
 * PARAMETERS
 *  void
 * RETURNS
 *  Total left memory size.
 *****************************************************************************/
extern U32 mmi_frm_scrmem_get_available_size(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_scrmem_is_all_free
 * DESCRIPTION
 *  Check if the screen-based memory is all free.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return MMI_TRUE if all memory are released.
 *****************************************************************************/
extern MMI_BOOL mmi_frm_scrmem_is_all_free(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_scrmem_is_valid_block
 * DESCRIPTION
 *  Check if a memory block is valid. In other words, it should belong to the
 *  current screen. And the memory header/footer should also be valid.
 * PARAMETERS
 *  mem_ptr    : [IN]        Memory block to check.
 * RETURNS
 *  Return MMI_TRUE if the momery block is valid.
 *****************************************************************************/
extern MMI_BOOL mmi_frm_scrmem_is_valid_block(void *mem_ptr);

/* DOM-NOT_FOR_SDK-BEGIN */
extern void *mmi_frm_scrmem_alloc_int(U32 mem_size, U32 line);
extern void *mmi_frm_scrmem_alloc_framebuffer_int(U32 mem_size, U32 line);
extern void mmi_frm_scrmem_free_int(void *mem_ptr, U32 line);
/* DOM-NOT_FOR_SDK-END */
#endif /* _SCR_MEM_MGR_GPROT_INT_H_ */


/* DOM-NOT_FOR_SDK-BEGIN */
#ifndef _RES_MEM_MGR_GPROT_INT_H_
#define _RES_MEM_MGR_GPROT_INT_H_
/*----------------------------------------------------------------*
  Resource Memroy Manager
 *----------------------------------------------------------------*/
/***************************************************************************** 
 * Define
 *****************************************************************************/
/*-- Image resource --*/
#define MMI_FRM_RESMEM_SCATTER_MAX_NUMBER   128


/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
/*-- Image resource --*/
/* strucutre to receieve information passing from resource-generated table */
typedef struct
{
    U16 id;
    U32 offset;
    U32 size;
} mmi_frm_resmem_res_info_struct;

typedef enum
{
    MMI_FRM_RESMEM_TYPE_LOD_ON_DEMAND = 0x00000001,
    MMI_FRM_RESMEM_TYPE_ALWAYS_EXIST = 0x00000002,

    MMI_FRM_RESMEM_TYPE_EOE
} mmi_frm_resmem_enum;


/*****************************************************************************
 * Extern Global Variable 
 *****************************************************************************/


/*****************************************************************************
 * Extern Global Function 
 *****************************************************************************/
/*-- Image resource --*/
extern void mmi_frm_resmem_init(void);
extern U8 *mmi_frm_resmem_if_ramed(U16 id);
extern U8 *mmi_frm_resmem_load_single_image(U16 id, U32 offset, U32 size);
extern U8 *mmi_frm_resmem_load_multi_image(U16 id, const mmi_frm_resmem_res_info_struct *info_array, U32 res_cnt);
extern void mmi_frm_resmem_reset(U32 flag);
extern void mmi_frm_resmem_reg_retain(U16 id);
extern void mmi_frm_resmem_dereg_retain(U16 id);

/*-- String resource --*/
extern void mmi_frm_resmem_load_str_suite(U8 **ptr_ary, U32 *offset_ary, U32 *size_ary, U32 ary_count);
extern void mmi_frm_resmem_load_data(U32 offset,U8* buffer, U32 size);


#endif /* _RES_MEM_MGR_GPROT_INT_H_ */



#ifndef MMI_MEM_MONITOR_H
#define MMI_MEM_MONITOR_H
/*----------------------------------------------------------------*
  Memory Monitor
 *----------------------------------------------------------------*/
#ifdef __MMI_MEMORY_MONITOR__
/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MMI_MEM_MON_PROFILING_PERIOD    (200)

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
typedef struct
{
    U32 block_size;     /* dynamic */
    U32 block_num;      /* dynamic */
#if defined(DEBUG_KAL) && defined(DEBUG_BUF) && defined(DEBUG_BUF2)
    U32 used_num;       /* dynamic */
#endif
} partition_mem_info_struct;

typedef struct
{
    U32 maximal_alloc_size;
    U32 current_alloc_size;
    U32 total_alloc_count;
    U32 total_alloc_size;
} partition_mem_alloc_struct;

typedef struct
{
    U32 register_scr_mem_size;
    U32 current_scr_alloc_size;
    U32 maximal_scr_alloc_size;
    U32 scr_alloc_count;
    U32 register_app_mem_size;
    U32 current_app_alloc_size;
    U32 maximal_app_alloc_size;
    U32 app_alloc_count;
} asm_mem_alloc_info_struct;

typedef enum
{
    MEM_MON_DYNAMIC_DATA,
    MEM_MON_STATIC_DATA,
    MEM_MON_DATA_TYPE_TOTAL
} mmi_mem_monitor_data_type;

typedef enum
{
    MMI_EM_MEMORY_MONITOR_OFF = 0,
    MMI_EM_MEMORY_MONITOR_OSL,
    MMI_EM_MEMORY_MONITOR_ASM,
    #ifdef __MMI_VUI_ENGINE__
    MMI_EM_MEMORY_MONITOR_VUI,
    #endif /* __MMI_VUI_ENGINE__ */
    MMI_EM_MEMORY_MONITOR_TOTAL
} mmi_mem_monitor_type_enum;

/* which area is mem. monitor displaying on */
typedef struct {
    S32 x1;
    S32 y1;
    S32 x_offset;
    S32 y_offset;
} mmi_mem_mon_canvas_type;

typedef void (*mmi_mem_mon_info_str_cb_type)(PU8 unicode_str, U32 str_len, mmi_mem_mon_canvas_type *canvas_p);

typedef struct {
    PU8 str;
    mmi_mem_mon_info_str_cb_type info_str_cb;
} mmi_mem_mon_list_struct;


/* type of string drawing function */
typedef void (*mmi_mem_mon_string_drawing_func_type)(PU16 unicode_str, S32 x1, S32 y1, S32 x2, S32 y2);


/*****************************************************************************
 * Extern Global Variable 
 *****************************************************************************/


/*****************************************************************************
 * Extern Global Function 
 *****************************************************************************/
extern void mmi_mem_mon_profiling_memory_monitor(mmi_mem_monitor_type_enum mem_type, mmi_mem_mon_canvas_type *canvas_p);
extern mmi_mem_monitor_type_enum mmi_mem_mon_profiling_get_enable(void);
extern void mmi_mem_mon_profiling_set_enable(mmi_mem_monitor_type_enum enable);
extern void mmi_mem_mon_construct_static_statistic(U16 *unicode_buff, U32 buff_size);

extern void mmi_mem_mon_start_periodic_profiling(U32 interval_in_ms);

extern void mmi_mem_mon_update_detail_info(mmi_frm_mem_type monitor_type);

extern void mmi_mem_mon_print_string(mmi_mem_mon_canvas_type *canvas_p, PU16 unicode_str);

extern PU8 mmi_mem_mon_get_list_str(mmi_mem_monitor_type_enum idx);

extern void mmi_mem_mon_set_string_drawing_function(mmi_mem_mon_string_drawing_func_type func_ptr);

#endif /* #ifdef __MMI_MEMORY_MONITOR__ */

#endif /* MMI_MEM_MONITOR_H */

/* DOM-NOT_FOR_SDK-END */

#ifdef __cplusplus
}   /* extern "C" */
#endif

#endif /* MMI_FRM_MEM_GPROT_H */ 

