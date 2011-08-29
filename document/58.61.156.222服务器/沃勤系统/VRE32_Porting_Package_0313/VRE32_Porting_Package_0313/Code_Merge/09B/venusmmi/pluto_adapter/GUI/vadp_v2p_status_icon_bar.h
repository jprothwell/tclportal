/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_v2p_status_icon_bar.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file provides the adaptation functions from the Venus MMI to 
 *  the Pluto Inputbox components
 *
 *      Venus ---> v2p adaptor ---> Pluto 
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VADP_V2P_STATUS_ICON_BAR_H__
#define __VADP_V2P_STATUS_ICON_BAR_H__

#ifdef __cplusplus
extern "C"
{
#endif


/**********************************************************************
 * Structure Definitions
 **********************************************************************/


/**********************************************************************
 * External Interfaces
 **********************************************************************/

extern void vadp_v2p_show_icon(S32 iconId);

extern void vadp_v2p_blink_icon(S32 iconId);

extern void vadp_v2p_animate_icon(S32 iconId);
                
extern void vadp_v2p_change_icon_level(S32 iconId, U8 level_percentage);

extern void vadp_v2p_change_icon_image(S32 iconId, U16 image_id);

extern void vadp_v2p_create_status_icon_bar(
                   void (*update_screen_callback)(void *handle),
                   void *update_screen_handle, gdi_handle display_layer);

extern void vadp_v2p_close_status_icon_bar(void);

extern void vadp_v2p_show_status_icon_bar(void);

extern void vadp_v2p_get_prefered_size(S32 *width, S32 *height);

extern void vadp_v2p_status_icon_bar_set_backgroud(MMI_BOOL enable);

/* Vogins Start */
#ifdef __VRE__
extern void vadp_v2p_status_icon_bar_register_pen_event(S32 icon_id, FuncPtr handle);

extern void vadp_v2p_status_icon_bar_reset_all_pen_event_handler(void);

extern MMI_BOOL vadp_v2p_status_icon_bar_execute_pen_event_handler(S32 icon_id);

extern MMI_BOOL vadp_v2p_status_icon_bar_translate_pen_event(
            S32 pen_event,
            S32 x,
            S32 y,
            S32 *icon_id);

extern void vm_process_status_icon(void);
//extern void vm_register_status_icon_pen_event(void);
#endif
/* Vogins End */

#ifdef __cplusplus
}   /* extern "C" */
#endif

#endif /* __VADP_V2P_STATUS_ICON_BAR_H__ */


