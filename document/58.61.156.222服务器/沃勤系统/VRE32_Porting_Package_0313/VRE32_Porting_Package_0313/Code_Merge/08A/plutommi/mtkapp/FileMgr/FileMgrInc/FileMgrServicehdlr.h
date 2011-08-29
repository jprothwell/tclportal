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
 *  FileManagerDef.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  File Manager internal prototype header.
 *
 * Author:
 * -------
 * -------
 * -------
 *
 *==============================================================================
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#if defined (__MMI_FILE_MANAGER__)

#ifndef _FMGR_SERVICE_HDLR_H_
#define _FMGR_SERVICE_HDLR_H_



/****************************************************************************
* Include Files                                                                
*****************************************************************************/


/****************************************************************************
* Define
*****************************************************************************/


/********************************** Macro **********************************/


/********************************** Enum  **********************************/


/********************************* Typedef ********************************/


/****************************************************************************
* Global variable
*****************************************************************************/


/****************************************************************************
* Internal Function
*****************************************************************************/

extern U16 mmi_fmgr_query_custom_icon(BOOL is_large, U16 filetype, U16 grouptype, S8* filepath);

extern void mmi_fmgr_forward_2d_media_enabler(U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo);
extern void mmi_fmgr_forward_phb_enabler(U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo);
extern void mmi_fmgr_forward_profile_enabler(U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo);
extern void mmi_fmgr_forward_bgsound_enabler(U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo);
extern void mmi_fmgr_forward_totolist_enabler(U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo);
extern void mmi_fmgr_forward_sms_enabler(U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo);
extern void mmi_fmgr_forward_ems_enabler(U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo);
extern void mmi_fmgr_forward_mms_enabler(U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo);
extern void mmi_fmgr_forward_email_enabler(U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo);
extern void mmi_fmgr_forward_peripheral_enabler(U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo);

extern void mmi_fmgr_option_image_enabler(U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo);
extern void mmi_fmgr_option_imgviewer_enabler(U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo);
extern void mmi_fmgr_option_bookmark_enabler(U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo);
extern void mmi_fmgr_option_vbookmark_enabler(U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo);

#ifdef __MMI_AUDIO_PLAYER__
extern BOOL mmi_fmgr_audio_player_notify_hdlr(U32 notify_flag, void* para1);
#endif

#if defined(__J2ME__)
extern BOOL mmi_fmgr_jma_notify_hdlr(U32 notify_flag, void* para);
#endif

#if defined(__J2ME__)
extern BOOL mmi_fmgr_java_notify_hdlr(U32 notify_flag, void* para);
#endif

#ifdef __MMI_BG_SOUND_EFFECT__
extern BOOL mmi_fmgr_bgsound_notify_hdlr(U32 notify_flag, void* para);
#endif

#if defined(__MMI_BROWSER_2__) || defined(OBIGO_Q03C)
extern BOOL mmi_fmgr_wap_notify_hdlr(U32 notify_flag, void* para);
#endif



#ifdef __MMI_EBOOK_READER__
extern BOOL mmi_fmgr_ebook_notify_hdlr(U32 notify_flag, void* para);
#endif

#ifdef __MMI_EMAIL__
extern BOOL mmi_fmgr_email_notify_hdlr(U32 notify_flag, void* para);
#endif

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
extern BOOL mmi_fmgr_um_archive_notify_hdlr(U32 notify_flag, void* para);
#endif

#ifdef __MMI_LANGLN__
extern BOOL mmi_fmgr_langln_notify_hdlr(U32 notify_flag, void* para);
#endif

#ifdef __MMI_MMS_BGSR_SUPPORT__
extern BOOL mmi_fmgr_mms_bgsr_notify_hdlr(U32 notify_flag, void* para);
#endif

#ifdef __MMI_SWFLASH__
extern BOOL mmi_fmgr_swflash_notify_hdlr(U32 notify_flag, void* para);
#endif
/* Vogins Start */
#ifdef __VRE__
extern BOOL mmi_fmgr_vre_notify_hdlr(U32 notify_flag, void* para);
#endif
/* Vogins End */
#ifdef __MMI_THEMES_V2_SUPPORT__
extern BOOL mmi_fmgr_theme_v2_notify_hdlr(U32 notify_flag, void* para);
#endif

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
extern BOOL mmi_fmgr_theme_notify_hdlr(U32 notify_flag, void* para);
#endif

#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))
extern BOOL mmi_fmgr_uc_notify_hdlr(U32 notify_flag, void* para);
#endif

#ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
extern BOOL mmi_fmgr_setting_notify_hdlr(U32 notify_flag, void* para);
#endif

#if defined(__MMI_MY_FAVORITE_SWFLASH_HYPERLINK__)
extern BOOL mmi_swflash_hyperlink_callback(U16 app_id, S8* path, fmgr_hyperlink_action_enum action, S32 para, S32* result);
#endif

#if defined(__MMI_FMGR_MULTI_SELECT_SUPPORT__) && defined(__MMI_PICT_BRIDGE_SUPPORT__) && !defined(__MMI_PICT_BRIDGE_MULTI_FILE_PRINT__)
extern void fmgr_main_pict_bridge_mark_print(U8 *full_path, FMGR_FILE_INFO_STRUCT file_info, U8 total_count, U8 callback_index);
#endif

/****************************************************************************
* Global Function
*****************************************************************************/

#ifdef __MMI_IMAGE_VIEWER__
void mmi_fmgr_image_print_by_imgviewer(S8* filepath, U16 icon_id);
#endif


#endif /* _FMGR_SERVICE_HDLR_H_ */

#endif /* #if defined (__MMI_FILE_MANAGER__) */

