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
 *  AMScreens.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  AM Other Screens in addition to Main Screen.
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
#ifndef AM_SCREENS_H
#define AM_SCREENS_H

#include "MMIDataType.h"

#define MMI_AM_DETAILS_NEWLINE L"\n"
#define MMI_AM_DETAILS_SPACES L"  "     /* two spaces */
#define MMI_AM_DETAILS_SEMI L":"
#define MMI_AM_DETAILS_DESC L"VREDESC:"
#define MMI_AM_DETAILS_PHONE L"VREPHONE:"
#define MMI_AM_DETAILS_RANK L"VRERANK:"

#define MMI_AM_DETAILS_DEV_NAME_SIZE 20
#define MMI_AM_DL_MAX_APP_FILE_NAME    42       /* short file name use 8.3 format */
/*vogins_20100726_start*/
#define MMI_AM_SM_SUCCESS   (0)
#define MMI_AM_SM_FAILED   (-1)
/*vogins_20100726_end*/
/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef struct
{
    U32 app_id;
    U16 app_name[MMI_AM_DL_MAX_APP_FILE_NAME];
    MMI_BOOL is_start_download;
    S8 dl_app_driver;
    U32 download_progress;
/*Vogins_20100625_start*/
    MMI_BOOL is_start_downloading; //for waiting screen to process interrupt
	MMI_BOOL is_as_add;   //whether the as is added to download
	VMINT base_size;
	VMINT add_size;		//the app size, in order to calculate the precent
	VMINT download_size;	//the download as size
	MMI_BOOL is_limit_dl_size;
/*Vogins_20100625_end*/
} mmi_am_download_cntx_struct;

/****************************************************************************
* Extern Global Function                                                            
*****************************************************************************/
extern void mmi_am_entry_option_scrn(void);
extern void mmi_am_dl_init(void);
extern void mmi_am_dl_set_appid(U32 app_id);
extern U32 mmi_am_dl_get_appid(void);
extern void mmi_am_dl_set_app_name(U16 *app_name);
extern U16 *mmi_am_dl_get_app_name(void);
extern MMI_BOOL mmi_am_download_pre_check(void);
extern void mmi_am_download_app_cb(S32 nResult, S32 nPercent);
extern void mmi_am_os_app_launch(void);
extern void mmi_am_os_download(void);
extern void mmi_am_entry_update_cdr_scrn(void);
extern void mmi_am_os_download_accept(void);
/*Vogins_20100625_start*/
extern void mmi_am_download_prompt(void);
extern void mmi_am_cdr_update_accept(void);
extern void mmi_am_vre_release_net(void);
/*Vogins_20100625_end*/
//Vogins_ 0625
extern void mmi_am_goto_apn_incorrect_handle(void);
extern MMI_BOOL mmi_am_process_apn_incorrect_handle(MMI_AM_APN_RESULT result);
/*vogins_20100712_start*/
extern void mmi_am_entry_processes_manager_scrn(void);
extern void mmi_am_os_processes_manager(void);
/*vogins_20100712_end*/
/*vogins_20100726_start*/
extern void mmi_am_continue_download_app(void);
/*vogins_20100726_end*/
#endif /* AM_SCREENS_H */ 

