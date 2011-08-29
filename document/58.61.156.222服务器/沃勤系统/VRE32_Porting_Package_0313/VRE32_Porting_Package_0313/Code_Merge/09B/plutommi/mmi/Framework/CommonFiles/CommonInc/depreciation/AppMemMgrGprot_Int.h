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
 *  AppMemMgrGprot_Int.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  MMI UI related functions for App-based ASM
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _APP_MEM_MGR_GPROT_INT_H_
#define _APP_MEM_MGR_GPROT_INT_H_


/***************************************************************************** 
 * Define
 *****************************************************************************/
/* Max number of applications shown in the "Stop Application" screen */
#define MMI_FRM_APPMEM_MAX_APP_PROMPTED     (10)
#define MMI_FRM_APPMEM_PROMPT_INFO_START_PIXEL_OFFSET  (4)

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
/* Vogins Start */
/*michael 0719 appid begin*/
/* ID of app */
#if defined(__VRE30_AM__)

#define MMI_FRM_APPMEM_MAX_HIDE_APP     (12)

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
/*vogins 0726 begin for native app must add it below*/
    MMI_AP_MED_CAMERA_ID,
    MMI_AP_MED_VIDEO_ID,
/*vogins 0726 begin for native app must add it above*/    
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
extern void mmi_frm_appmem_init(void);

extern void mmi_frm_appmem_prompt_to_release_mem(
                MMI_ID_TYPE app_name, 
                MMI_ID_TYPE app_icon, 
                U32 required_size,
                void (*success_callback)(void));

extern void mmi_frm_appmem_prompt_to_release_full_pool(
                MMI_ID_TYPE app_name, 
                MMI_ID_TYPE app_icon, 
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

extern applib_mem_ap_id_enum mmi_frm_appmem_check_prompt_screen(void);
/*****************************************************************************              
 * Extern Global Function                                                                    
 *****************************************************************************/

#ifdef APPLIB_MEM_UNIT_TEST
extern void mmi_frm_appmem_unit_test_setup_environment(MMI_BOOL stress_test);

extern void mmi_frm_appmem_unit_test_prepare_to_enter_test1(void (*run_callback)(void), MMI_BOOL clear_all);
extern void mmi_frm_appmem_unit_test_prepare_to_enter_test2(void (*run_callback)(void), MMI_BOOL clear_all);
extern void mmi_frm_appmem_unit_test_prepare_to_enter_test3(void (*run_callback)(void), MMI_BOOL clear_all);
extern void mmi_frm_appmem_unit_test_prepare_to_enter_test4(void (*run_callback)(void), MMI_BOOL clear_all);
extern void mmi_frm_appmem_unit_test_prepare_to_enter_test5(void (*run_callback)(void), MMI_BOOL clear_all);
#endif /* APPLIB_MEM_UNIT_TEST */

#endif /* _APP_MEM_MGR_GPROT_INT_H_ */ 

