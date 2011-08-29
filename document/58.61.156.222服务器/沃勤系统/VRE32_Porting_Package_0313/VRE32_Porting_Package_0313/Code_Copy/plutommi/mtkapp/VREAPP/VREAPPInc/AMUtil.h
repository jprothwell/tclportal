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
 *  AMUtil.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  AM Utility file.
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
#ifndef AM_UTIL_H
#define AM_UTIL_H
#ifdef __VRE_AM_08AB__
#include "MMI_include.h"
#include "MMI_include.h"
#else
#include "MMI_frm_gprot.h"
#endif
#include "MMIDataType.h"
#include "AMDef.h"
#include "gdi_include.h"

/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef enum
{
    VRE20_APP = 0,
    VRE30_APP,
    ILLEGAL_APP
} MMI_AM_VRE_APP_TYPE;

/****************************************************************************
* Extern Global Function                                                            
*****************************************************************************/
extern S8 mmi_am_get_home_driver(void);
extern S8 mmi_am_get_system_driver(void);
extern S8 mmi_am_get_removeable_driver(void);
extern void *mmi_am_malloc(int size);
extern void *mmi_am_calloc(int size);
extern void *mmi_am_realloc(void *p, int size);
extern void mmi_am_free(void *ptr);
extern U32 mmi_am_get_total_left_size(void);
extern S32 mmi_am_get_font_height(void);
extern MMI_BOOL mmi_am_app_is_bg_running(U16 *path);
extern MMI_BOOL mmi_am_get_app_version(U16 *full_path, S32 *version);
extern void mmi_am_get_rom_app_array(S32 **app_array_ptr, S32 *app_array_len_ptr);
extern MMI_BOOL mmi_am_get_gif_data(U8 *source, U8 **p_gif, U32 *icon_size);
extern MMI_BOOL mmi_am_get_zimo_string_data(U8 *source, U8 **p_str, S32 *font_size);
extern MMI_BOOL mmi_am_get_app_name(U16 *file_path, U8 *icon_src, void **des_buf, U32 *name_len);

/*michael 100415 begin*/
MMI_BOOL mmi_am_get_runing_app_name(U16 *file_path, U8 *icon_src, void **des_buf, U32 *name_len);
/*michael 100415 end*/
extern MMI_BOOL mmi_am_get_info_by_tag(U16 *file_path, MMI_AM_INFO_TYPE tag, void **des_buf, U32 *des_size);
extern S32 mmi_am_measure_zimo(U8 *zimo_buf, S32 str_len);
extern void mmi_am_draw_zimo(
                S32 x,
                S32 y,
                S32 start_idx,
                S32 out_str_len,
                U8 *src_buf,
                S32 str_len,
                S32 font,
                gdi_color color);
extern MMI_BOOL mmi_am_is_support_wifi(void);
extern MMI_BOOL mmi_am_set_sim_card(S32 choose_index);
extern MMI_BOOL mmi_am_set_net_type(S32 net_type);
extern S32 mmi_am_get_sim_card_num(void);
extern MMI_BOOL mmi_am_get_sim_card(mmi_am_sim_settings_enum *sim_index);
extern MMI_BOOL mmi_am_get_net_type(mmi_am_conn_settings_enum *net_type);
extern MMI_AM_VRE_APP_TYPE mmi_am_get_app_type_by_path(U16 *app_path);
extern MMI_BOOL mmi_am_is_appstore_in_rom(U16 *app_path);

#endif /* AM_UTIL_H */ 

