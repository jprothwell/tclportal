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
 *  wgui_categories_fmgr.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  File Manager related categories.
 *
 *  [Category212]       Info Style Dynamic List Menu 
 *  [Category213]       Thick Style Dynamic List Menu 
 *  [Category214]       Matrix Style Dynamic Image Menu 
 *
 * Author:
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef __WGUI_CATEGORIES_FMGR_H__
#define __WGUI_CATEGORIES_FMGR_H__

#include "FileMgrGProt.h"

/***************************************************************************** 
* Define
*****************************************************************************/
#define CAT213_ARROW_UP    0x1
#define CAT213_ARROW_DOWN  0x2
#define CAT213_ARROW_LEFT  0x4
#define CAT213_ARROW_RIGHT 0x8
#define CAT213_ARROW_ALL   0xf

/***************************************************************************** 
* Typedef
*****************************************************************************/
typedef void (*Cat212DrawInfoFuncPtr) (S32 idx, S32 x1, S32 y1, S32 x2, S32 y2);
typedef void (*Cat212HideInfoFuncPtr) (void);

typedef void (*Cat213DrawMenuItemFuncPtr) (S32 idx, BOOL is_hilighted, S32 x1, S32 y1, S32 x2, S32 y2);
typedef void (*Cat213HideMenuItemFuncPtr) (void);

typedef void (*Cat214DrawImageFuncPtr) (S32 idx, S32 page_star_idx, S32 page_end_idx, BOOL is_hilighted,
                                        BOOL is_need_update, BOOL is_new_page, S32 x1, S32 y1, S32 x2, S32 y2);
typedef void (*Cat214HideImageFuncPtr) (S32 idx);

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/
extern S32 MMI_thick_menuitem_height;

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

extern void ShowCategory211Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 num_of_items,
                GetItemFuncPtr get_item_func,
                GetHintFuncPtr get_hint_func,
                Cat212DrawInfoFuncPtr draw_info_callback,
                Cat212HideInfoFuncPtr hide_info_callback,
                S32 info_box_height,
                U16 info_bg_img_id,
                S32 highlighted_item,
                U8 *history_buffer);

/* Info style dynamic list category */
extern void ShowCategory212Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 num_of_items,
                GetItemFuncPtr get_item_func,
                GetHintFuncPtr get_hint_func,
                Cat212DrawInfoFuncPtr draw_info_callback,
                Cat212HideInfoFuncPtr hide_info_callback,
                U16 num_of_info_box_rows,
                U16 info_bg_img_id,
                S32 highlighted_item,
                U8 *history_buffer);

extern void Cat212ShortCutHdlr(S32 item_index);
extern void DrawTextAreaBackground(S32 x1, S32 y1, S32 x2, S32 y2);
extern void FillFullTextBackground(S32 x1, S32 y1, S32 x2, S32 y2);

/* Thick style dynamic list category */
extern void ShowCategory213Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 num_of_items,
                Cat213DrawMenuItemFuncPtr draw_menuitem_callback,
                Cat213HideMenuItemFuncPtr hide_menuitem_callback,
                S32 highlighted_item,
                U8 arrow_flag,
                U8 *history_buffer);

/* Matrix style dynamic image category */
extern void ShowCategory214Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U16 num_of_items,
                Cat214DrawImageFuncPtr draw_image_callback,
                Cat214HideImageFuncPtr hide_image_callback,
                U8 num_per_row,
                U8 num_per_col,
                S32 highlighted_item,
                U8 *history_buffer);

extern void GetCategory214BoxSize(S32 num_per_row, S32 num_per_col, S32 *box_width_ptr, S32 *box_height_ptr);
/* Vogins Start */
#ifdef __VRE__
extern void wgui_cat214_disable_draw_highlight(void);
#endif
/* Vogins End */

//#define mmi_fmgr_draw_hilight_menuitem_bg(x1, y1, x2 ,y2)   wgui_fmgr_draw_hilight_menuitem_bg(x1, y1, x2, y2)

#if defined(FMGR_USING_CACHE)
#define FMGR_THUMB_IMAGE_CACHE_MAX_COUNT        (50)    /* may cache up to 30 images */
#define FMGR_THUMB_IMAGE_HANDLE_MAX_COUNT       (16)    /* may decode up to 12 images on a screen at a time */
#define FMGR_DELAY_DECODER_COUNT                (16)
#endif



#ifdef __MMI_TOUCH_SCREEN__
#define FMGR_UI_DELAY_DECODE_DURATION  (1000)
#else 
#define FMGR_UI_DELAY_DECODE_DURATION  (100)
#endif 
#define FMGR_UI_IMAGE_BOX_SPACING      (2)
#define FMGR_UI_TEXT_SPACING           (4)


typedef enum
{
    WGUI_CAT21X_INFO_TYPE_DRV,
    WGUI_CAT21X_INFO_TYPE_FILE
}wgui_fmgr_info_type;

typedef enum
{
    MMI_FMGR_GUI_LIST_STYLE,
    MMI_FMGR_GUI_INFO_STYLE,
    MMI_FMGR_GUI_MATRIX_STYLE
}wgui_fmgr_style_enum;

typedef struct
{
    UI_string_type info_text_l1_s1;
    UI_character_type info_text_l1_s2[128];
    UI_string_type info_text_l2_s1;
    UI_character_type info_text_l2_s2[128];
    MMI_BOOL is_show_thumb;
    wgui_fmgr_info_type info_type;
    U32 drv_ratio;
    PU8 file_icon_ptr;  
} wgui_fmgr_info_struct;

#if defined(FMGR_USING_CACHE)

typedef struct
{
    BOOL is_used;
    U16 unused_duration;    /* unused counter larger means has not been used for longer time */
    U16 seq_number;
    U16 menuitem_idx;
    S32 resized_offset_x;
    S32 resized_offset_y;
    S32 resized_width;
    S32 resized_height;
    gdi_image_cache_bmp_struct bmp;
} wgui_fmgr_thumb_image_cache_struct;

typedef struct
{
    BOOL is_used;
    gdi_handle handle;  /* decoder handle */
    U16 menuitem_idx;
    S32 draw_pos_x;
    S32 draw_pos_y;
    S32 resized_offset_x;
    S32 resized_offset_y;
    S32 resized_width;
    S32 resized_height;
    S32 box_offset_x;
    S32 box_offset_y;
    S32 box_width;
    S32 box_height;
    S32 icon_offset_x;
    S32 icon_offset_y;
    S32 icon_width;
    S32 icon_height;
    PU8 icon_ptr;
    BOOL is_hilighted;
    U16 ui_style;
}wgui_fmgr_thumb_image_handle_struct;

typedef struct
{
    wgui_fmgr_thumb_image_cache_struct *image_cache_list[FMGR_THUMB_IMAGE_CACHE_MAX_COUNT];
    wgui_fmgr_thumb_image_handle_struct *image_handle_list[FMGR_THUMB_IMAGE_HANDLE_MAX_COUNT];

    S32 image_size;             /* image widht, image height */
    U32 image_decode_seq_num;
    U16 image_cache_item_count; /* may cache how many images */
} wgui_fmgr_image_cache_struct;

typedef struct
{
    S32 item_idx;
    S32 menuitem_offset_x;
    S32 menuitem_offset_y;
    S32 box_offset_x;
    S32 box_offset_y;
    S32 box_width;
    S32 box_height;
    S32 icon_offset_x;
    S32 icon_offset_y;
    S32 icon_width;
    S32 icon_height;
    PU8 icon_ptr;
    BOOL is_hilighted;
    U16 ui_style;
} wgui_fmgr_delay_decode_struct;

#endif /* defined(FMGR_USING_CACHE) */ 

typedef struct
{
#if defined(FMGR_USING_CACHE)
    wgui_fmgr_image_cache_struct image_cache;
    wgui_fmgr_delay_decode_struct delay_decoder[FMGR_DELAY_DECODER_COUNT];
    BOOL is_decoder_create;
    U16 decoding_count;
#endif /* defined(FMGR_USING_CACHE) */ 

    scrolling_text scroll_text;
    S8 scroll_text_buf[(FMGR_MAX_FILE_LEN + 1) *ENCODING_LENGTH];
    
    /* UI use */
    U16 delay_decode_index;
} wgui_fmgr_category_struct;

typedef struct
{
    UI_character_type menu_text_l1_s1[128];
    UI_character_type menu_text_l2_s1[128];
    UI_character_type menu_text_l2_s2[128];
    S32 info_type;
    U32 drv_ratio;
    PU8 file_icon_ptr;  
    MMI_BOOL is_show_thumb;
} wgui_fmgr_menuitem_data_struct;

typedef void (*Cat212GetInfoData)(S32 item_idx, wgui_fmgr_info_struct *fmgr_info);
typedef void (*Cat212HideInfoData)(void);

typedef void (*CatFmgrGetFileData)(S32 item_idx, BOOL is_hilighted, wgui_fmgr_menuitem_data_struct *menuitem_data);
typedef void (*CatFmgrHideFileData)(void);

#define SET_UCS2STR_EMPTY(x) x[0]='\0';x[1]='\0';
#define CHECK_UCS2STR_EMPTY(x) (x[0]=='\0' && x[1]=='\0')

typedef void (*wgui_fmgr_set_displayable_func)(S32 index, MMI_BOOL displayable);
typedef MMI_BOOL (*wgui_fmgr_get_displayable_func)(S32 item_idx);
typedef MMI_BOOL (*wgui_fmgr_get_thumb_image_func)(S32 item_idx, S8 *file_path);



extern void ShowCategory212FmgrScreen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 num_of_items,
        GetItemFuncPtr get_item_func,
        GetHintFuncPtr get_hint_func,
        Cat212GetInfoData get_info_data,
        Cat212HideInfoData hide_info_data,
        U16 num_of_info_box_rows,
        U16 info_bg_img_id,
        S32 highlighted_item,
        U8 *history_buffer);
        
extern void ShowCategory212FmgrMarkScreen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 num_of_items,
        GetItemFuncPtr get_item_func,
        GetHintFuncPtr get_hint_func,
        Cat212GetInfoData get_info_data,
        Cat212HideInfoData hide_info_data,
        checkbox_get_image_funcptr_type get_image_func,
        checkbox_clicked_funcptr_type set_state_func,
        U16 num_of_info_box_rows,
        U16 info_bg_img_id,
        U8* info_message,
        S32 highlighted_item,
        U8 *history_buffer);
        
extern void ShowCategory213FmgrScreen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 num_of_items,
        CatFmgrGetFileData get_menuitem_data,
        CatFmgrHideFileData hide_menuitem_data,
        S32 highlighted_item,
        U8 arrow_flag,
        U8 *history_buffer);

extern void ShowCategory214FmgrScreen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U16 num_of_items,
        CatFmgrGetFileData get_menuitem_data,
        CatFmgrHideFileData hide_menuitem_data,
        U8 num_per_row,
        U8 num_per_col,
        S32 highlighted_item,
        U8 *history_buffer);

extern void wgui_cat21x_register_set_displayable(wgui_fmgr_set_displayable_func set_displayable);
extern void wgui_cat21x_register_get_displayable(wgui_fmgr_get_displayable_func get_displayable);
extern void wgui_cat21x_register_get_thumb_image(wgui_fmgr_get_thumb_image_func get_thumb_image);

extern void wgui_cat212_fmgr_draw_info(S32 item_idx, S32 x1, S32 y1, S32 x2, S32 y2);
extern void wgui_cat212_fmgr_hide_info(void);

extern void wgui_cat213_fmgr_draw_menuitem(S32 item_idx, BOOL is_hilighted, S32 x1, S32 y1, S32 x2, S32 y2);
extern void wgui_cat213_fmgr_hide_menuitem(void);

extern void wgui_cat214_fmgr_draw_menuitem_matrix(S32 idx, S32 page_start_idx, S32 page_end_idx,
                                             BOOL is_hilighted, BOOL is_need_update, BOOL is_new_page,
                                             S32 x1, S32 y1, S32 x2, S32 y2);
extern void wgui_cat214_fmgr_hide_menuitem_matrix(S32 idx);

extern void wgui_fmgr_draw_free_space_icon(S32 box_x1, S32 box_y1, S32 box_height, U32 drv_ratio, PU8 file_icon_ptr);


extern void wgui_fmgr_create_thumb_image_cache(S32 image_size);
extern void wgui_fmgr_free_thumb_image_cache(void);
extern void wgui_fmgr_cache_stop_decoder(void);

#if defined(FMGR_USING_CACHE)

extern void wgui_fmgr_decode_thumb_image_after_frame(GDI_RESULT result,gdi_handle handle);
extern void wgui_fmgr_decode_thumb_image_result_hdlr(GDI_RESULT decode_result, gdi_handle handle);

extern void wgui_fmgr_delay_decode_image(S32 item_idx, S32 menuitem_offset_x, S32 menuitem_offset_y,
                                             S32 box_offset_x, S32 box_offset_y, S32 box_width,
                                             S32 box_height, S32 icon_offset_x, S32 icon_offset_y,
                                             S32 icon_width, S32 icon_height, PU8 icon_ptr,
                                             BOOL is_hilighted, U16 ui_style);

extern void wgui_fmgr_delay_decode_0(void);
extern void wgui_fmgr_delay_decode_1(void);
extern void wgui_fmgr_delay_decode_2(void);
extern void wgui_fmgr_delay_decode_3(void);
extern void wgui_fmgr_delay_decode_4(void);
extern void wgui_fmgr_delay_decode_5(void);
extern void wgui_fmgr_delay_decode_6(void);
extern void wgui_fmgr_delay_decode_7(void);
extern void wgui_fmgr_delay_decode_8(void);
extern void wgui_fmgr_delay_decode_9(void);

#endif /* defined(FMGR_USING_CACHE) */ 

extern void wgui_fmgr_get_fmgr_cache_struct (void** image_cache_list_buffer_p,
                                     void** image_handle_list_buffer_p,
                                     void** image_cache_p,
                                     void** delay_decoder_p);

extern void wgui_fmgr_draw_hilight_menuitem_timer_callback(void);
extern void wgui_fmgr_draw_hilight_menuitem_bg_callback(S32 x1, S32 y1, S32 x2, S32 y2);
extern BOOL wgui_fmgr_show_thumb_image(S32 item_idx, S32 menuitem_offset_x, S32 menuitem_offset_y, S32 box_offset_x,
                                           S32 box_offset_y, S32 box_width, S32 box_height, PU8 icon_ptr, BOOL is_hilighted,
                                           U16 ui_style);

extern void ShowCategory266Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U8 *message,
        U16 message_icon,
		U16 num_of_info_box_rows,
		U16 info_icon_id,
        U8 *history_buffer);
extern void ExitCategory266Screen(void);
#endif /* __WGUI_CATEGORIES_FMGR_H__ */ 

