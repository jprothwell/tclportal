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
 *  wgui_categories_fmgr.c
 *
 * Project:
 * --------
 *  MAUI
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
#include "MMI_features.h"

/* framework related include */
#include "EventsGprot.h"
#include "CustDataProts.h"
#include "CustMenuRes.h"
#include "GlobalDefs.h"
#include "FrameworkStruct.h"
#include "EventsDef.h"
#include "Unicodexdcl.h"
#include "DebugInitDef.h"
#include "ScrMemMgrGprot.h"     /* screen memeory manager */

/* gui related include */
#include "gdi_include.h"        /* include for graphic lib */
#include "kal_non_specific_general_types.h"     /* include this for kal data type */
#include "lcd_sw_rnd.h"
#include "gui_themes.h"
#include "wgui.h"
#include "wgui_categories.h"
#include "wgui_categories_fmgr.h"
#include "wgui_draw_manager.h"
#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
#endif 
#include "ScreenRotationGprot.h"

#include "FileMgr.h"    /* file Utility functions */
#include "FileManagerDef.h"     /* String ID define */

#include "gdi_lcd_config.h"     /* include this for LCD_HEIGHT */
#include "wgui_include.h"
#include "wgui_fixed_menus.h"
#include "wgui_fixed_menuitems.h"
#include "gui_dynamic_menus.h"
#include "wgui_dynamic_menus.h"

/***************************************************************************** 
* Define
*****************************************************************************/

#if defined(__MMI_MAINLCD_128X128__)
#define MMI_THICK_MENUITEM_HEIGHT   (30)
#elif defined(__MMI_MAINLCD_128X160__)
#define MMI_THICK_MENUITEM_HEIGHT   (30)
#elif defined(__MMI_MAINLCD_176X220__)
#define MMI_THICK_MENUITEM_HEIGHT   (39)
#elif defined(__MMI_MAINLCD_240X320__)
#define MMI_THICK_MENUITEM_HEIGHT   (60)
#elif defined(__MMI_MAINLCD_320X240__)
#define MMI_THICK_MENUITEM_HEIGHT   (44)
#elif defined(__MMI_MAINLCD_240X400__)
#define MMI_THICK_MENUITEM_HEIGHT   (76)
#else 
#define MMI_THICK_MENUITEM_HEIGHT   (30)
#endif 

#define CAT214_INSIDE_SPACING          (4)      /* spacing include photo style frame */
#define CAT214_OUTSIDE_SPACING         (4)

/***************************************************************************** 
* Golbal Variable
*****************************************************************************/
S32 MMI_thick_menuitem_height = MMI_THICK_MENUITEM_HEIGHT;  /* this shall move to other customizable place */

extern gdi_handle wgui_layer_1;
extern gdi_handle wgui_base_layer;
extern BOOL r2lMMIFlag;
/* x1 and y1 of the highlight menuitem */
extern S32 GUI_current_fixed_icontext_menuitem_x, GUI_current_fixed_icontext_menuitem_y;

/***************************************************************************** 
* Golbal Function
*****************************************************************************/
extern S32 wgui_current_pop_up_description_index;
extern void reset_pop_up_descriptions(void);
extern void set_dynamic_pop_up_descriptions(S32 highlighted_item);
extern void (*MMI_matrix_highlight_handler) (S32 item_index);
extern void draw_wallpaper(void);
extern void wgui_title_set_no_icon_shct(MMI_BOOL no_icon_shct);
extern void ShowListCategoryScreen_ext(
                UI_string_type title,
                PU8 title_icon,
                UI_string_type left_softkey,
                PU8 left_softkey_icon,
                UI_string_type right_softkey,
                PU8 right_softkey_icon);

/***************************************************************************** 
* Local Variable
*****************************************************************************/
/* [Category212] */
static Cat212DrawInfoFuncPtr cat212_draw_info_callback = NULL;
static Cat212HideInfoFuncPtr cat212_hide_info_callback = NULL;
static U16 cat212_info_box_height = 0;
static UI_string_type   g_cat212_info = NULL;
static scrolling_text scroll_text_cat212;

/* [Category213] */
static Cat213DrawMenuItemFuncPtr cat213_draw_menuitem_callback = NULL;
static Cat213HideMenuItemFuncPtr cat213_hide_menuitem_callback = NULL;
static U16 cat213_menuitem_per_screen;

/* [Category214] */
static Cat214DrawImageFuncPtr cat214_draw_image_callback = NULL;
static Cat214HideImageFuncPtr cat214_hide_image_callback = NULL;
static U8 cat214_num_per_row;
static U8 cat214_num_per_col;
static U16 cat214_hilighted_index;

#if defined(__MMI_TOUCH_SCREEN__)
static S16 cat214_pen_down_index;
static U16 cat214_pen_down_on_scroll;
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 
static U16 cat214_prev_hilighted_index;
static U16 cat214_item_count;
static S16 cat214_page_index;
/* Vogins Start */
#ifdef __VRE__
static MMI_BOOL g_wgui_cat214_disable_highlgiht = MMI_FALSE;
#endif
/* Vogins End */

/***************************************************************************** 
* Local Function
*****************************************************************************/
/* [Category212] */
static void ExitCategory212Screen(void);
void DrawCate212CategoryControlArea(dm_coordinates *coordinate);
static void DrawCate212CategoryControlArea2(dm_coordinates *coordinate);

static void ShowCategory212InfoArea(S32 item_idx);

/* [Category213] */
static void ExitCategory213Screen(void);

static pBOOL Cat213GetItemCallback(S32 item_idx, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
static S32 Cat213GetHintCallback(S32 item_idx, UI_string_type *hint_array);
static void Cat213RedrawDynamicList(void);
static void Cat213KeyUpHdlr(void);
static void Cat213KeyDownHdlr(void);
static void Cat213ShortCutHdlr(S32 item_index);

/* [Category214] */
static void ExitCategory214Screen(void);
static U8 *GetCategory214History(U8 *history_buffer);
static void Cat214KeyUpHdlr(void);
static void Cat214KeyDownHdlr(void);
static void Cat214KeyLeftHdlr(void);
static void Cat214KeyRightHdlr(void);
static void Cat214RedrawMatrix(void);
static void Cat214ShortCutHdlr(S32 item_index);

#if defined(__MMI_TOUCH_SCREEN__)
static MMI_BOOL Cat214CategoryControlAreaPenDownHdlr(mmi_pen_point_struct pos);
static MMI_BOOL Cat214CategoryControlAreaPenMoveHdlr(mmi_pen_point_struct pos);
static MMI_BOOL Cat214CategoryControlAreaPenUpHdlr(mmi_pen_point_struct pos);
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 

static void DrawCate214CategoryControlArea(dm_coordinates *coordinate);

static Cat212GetInfoData wgui_cat212_fmgr_get_info_ptr = NULL;
static Cat212HideInfoData wgui_cat212_fmgr_hide_data_info_ptr = NULL;

static wgui_fmgr_category_struct fmgr_cat_context;

static CatFmgrGetFileData wgui_cat_fmgr_get_menuitem;
static CatFmgrHideFileData wgui_cat_fmgr_hide_menuitem;

#if defined(FMGR_USING_CACHE)
/* cache structure */
wgui_fmgr_thumb_image_cache_struct image_cache_list_buffer[FMGR_THUMB_IMAGE_CACHE_MAX_COUNT];
wgui_fmgr_thumb_image_handle_struct image_handle_list_buffer[FMGR_THUMB_IMAGE_HANDLE_MAX_COUNT];

wgui_fmgr_image_cache_struct *fmgr_image_cache_p = &fmgr_cat_context.image_cache;
wgui_fmgr_delay_decode_struct *fmgr_delay_decoder_p = &fmgr_cat_context.delay_decoder[0];

wgui_fmgr_set_displayable_func wgui_cat21x_set_displayable = NULL;
wgui_fmgr_get_displayable_func wgui_cat21x_get_displayable = NULL;
wgui_fmgr_get_thumb_image_func wgui_cat21x_get_image_path_callback = NULL;

#endif /* defined(FMGR_USING_CACHE) */ 


/*****************************************************************************
* [Category212]
*
* This category is for File Manager to display drive info.
*
*  **********************
*  *                    *
*  *                  ----------- info box   
*  **********************
*  *  # Folder          *
*  *  # File A          *
*  *  # File B          *
*  *                    *
*  *                    *
*  *                 -------------- Fix List 
*  *                    *
*  *                    *
*  **********************
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ShowCategory211Screen
 * DESCRIPTION
 *  Show sategory 211 screen.
 * PARAMETERS
 *  title                       [IN]        Title string id
 *  title_icon                  [IN]        Title image id
 *  left_softkey                [IN]        Lsk string id
 *  left_softkey_icon           [IN]        Lsk image id
 *  right_softkey               [IN]        Rsk string id
 *  right_softkey_icon          [IN]        Rsk image id
 *  num_of_items                [IN]        How many items
 *  get_item_func               [IN]        Callback function to get item string
 *  get_hint_func               [IN]        Callback function to get item hint
 *  draw_info_callback          [IN]        Callback function to draw info
 *  hide_info_callback          [IN]        Callback function to hide info
 *  info_box_height             [IN]        Height of info box
 *  info_bg_img_id              [IN]        (unused)
 *  highlighted_item            [IN]        Highlighted item
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory211Screen(
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
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
	U8 h_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Show shortcut when fullscreen backgournd */
    wgui_title_set_no_icon_shct(MMI_TRUE);

    cat212_draw_info_callback = draw_info_callback;
    cat212_hide_info_callback = hide_info_callback;

    cat212_info_box_height = (U16) info_box_height;

    /* lock */
    gui_lock_double_buffer();
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_block_list_effect();
#endif 
    ShowListCategoryScreen_ext(
        get_string(title),
        get_image(title_icon),
        get_string(left_softkey),
        get_image(left_softkey_icon),
        get_string(right_softkey),
        get_image(right_softkey_icon));

    wgui_dynamic_list_create_icontext_menu(
        num_of_items,
        get_item_func,
        get_hint_func,
        WGUI_LIST_INVALID_HIGHLIGHT,
        MMI_FALSE,
        UI_dummy_function,
        0,
        0,
        NULL);

    wgui_dynamic_list_override_icontext_shortcut_handler(Cat212ShortCutHdlr);

    resize_fixed_icontext_menuitems(0, MMI_MENUITEM_HEIGHT);
	h_flag = set_list_menu_category_history(MMI_CATEGORY212_ID, history_buffer);
	if (!h_flag)
    {
        MMI_fixed_list_menu.highlighted_item = highlighted_item;
    }
    
    set_dynamic_pop_up_descriptions(highlighted_item);
    wgui_dynamic_list_move_icontext_menu(0, (MMI_SUBMENU_CONTENT_Y) + cat212_info_box_height);  /* use two menuitem height to draw drive info */
    wgui_dynamic_list_resize_icontext_menu(MMI_content_width, MMI_content_height - cat212_info_box_height);

    /* when hilight, will update info area */
    wgui_dynamic_list_override_icontext_highlight_handler(ShowCategory212InfoArea);

    resize_dynamic_icontext_menuitems_to_list_width();

    gui_unlock_double_buffer();

    ExitCategoryFunction = ExitCategory212Screen;
    dm_setup_category_functions(dm_redraw_category_screen, dm_get_category_history, dm_get_category_history_size);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY212_ID;
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    dm_setup_data(&dm_data);
    dm_register_category_controlled_callback(DrawCate212CategoryControlArea);
    dm_redraw_category_screen();

}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory211InternalScreen
 * DESCRIPTION
 *  Show sategory 211Internalscreen.
 * PARAMETERS
 *  title                       [IN]        Title string id
 *  title_icon                  [IN]        Title image id
 *  left_softkey                [IN]        Lsk string id
 *  left_softkey_icon           [IN]        Lsk image id
 *  right_softkey               [IN]        Rsk string id
 *  right_softkey_icon          [IN]        Rsk image id
 *  num_of_items                [IN]        How many items
 *  get_item_func               [IN]        Callback function to get item string
 *  get_hint_func               [IN]        Callback function to get item hint
 *  draw_info_callback          [IN]        Callback function to draw info
 *  hide_info_callback          [IN]        Callback function to hide info
 *  get_image_func              [IN]        Get state of check-box function pointer
 *  set_state_func              [IN]        Set state of check-box function pointer
 *  info_box_height             [IN]        Height of info box
 *  info_bg_img_id              [IN]        (unused)
 *  info_message                [IN]        Show info message in bottom
 *  highlighted_item            [IN]        Highlighted item
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory211InternalScreen(
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
        checkbox_get_image_funcptr_type get_image_func,
        checkbox_clicked_funcptr_type set_state_func,
        S32 info_box_height,
        U16 info_bg_img_id,
        U8* info_message,
        S32 highlighted_item,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    U8 h_flag;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Show shortcut when fullscreen backgournd */
    wgui_title_set_no_icon_shct(MMI_TRUE);
    
    cat212_draw_info_callback = draw_info_callback;
    cat212_hide_info_callback = hide_info_callback;
    
    cat212_info_box_height = (U16) info_box_height;
    g_cat212_info = (UI_string_type)info_message;
    /* lock */
    gui_lock_double_buffer();
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_block_list_effect();
#endif 
    ShowListCategoryScreen_ext(
            get_string(title),
            get_image(title_icon),
            get_string(left_softkey),
            get_image(left_softkey_icon),
            get_string(right_softkey),
            get_image(right_softkey_icon));
    
    wgui_dynamic_list_create_icontext_menu(
            num_of_items,
            get_item_func,
            get_hint_func,
            WGUI_LIST_INVALID_HIGHLIGHT,
            MMI_FALSE,
            UI_dummy_function,
            0,
            0,
            NULL);
    
    wgui_dynamic_list_override_icontext_shortcut_handler(Cat212ShortCutHdlr);
    
    /* adjust list */
    resize_fixed_icontext_menuitems(0, MMI_MENUITEM_HEIGHT);
    set_fixed_icontext_positions(2*MMI_ICONTEXT_MENUITEM_HEIGHT + 3, 0, MMI_ICONTEXT_MENUITEM_HEIGHT + 2, 0);

    /* set check-box */
    wgui_menuitem_set_icontext_checkbox_position(1, 0);
    wgui_menuitem_register_icontext_checkbox_callback(set_state_func, get_image_func);

    h_flag = set_list_menu_category_history(MMI_CATEGORY210_ID, history_buffer);
    if (!h_flag)
    {
        MMI_fixed_list_menu.highlighted_item = highlighted_item;
    }
        
    set_dynamic_pop_up_descriptions(highlighted_item);
    wgui_dynamic_list_move_icontext_menu(0, (MMI_SUBMENU_CONTENT_Y) + cat212_info_box_height);  /* use two menuitem height to draw drive info */
    wgui_dynamic_list_resize_icontext_menu(MMI_content_width, MMI_content_height - cat212_info_box_height);
    
    /* when hilight, will update info area */
    wgui_dynamic_list_override_icontext_highlight_handler(ShowCategory212InfoArea);
    
    resize_dynamic_icontext_menuitems_to_list_width();
    
    gui_unlock_double_buffer();
    
    ExitCategoryFunction = ExitCategory212Screen;
    dm_setup_category_functions(dm_redraw_category_screen, dm_get_category_history, dm_get_category_history_size);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY211_ID;
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    dm_setup_data(&dm_data);
    dm_register_category_controlled_callback(DrawCate212CategoryControlArea);
    dm_register_category_controlled2_callback(DrawCate212CategoryControlArea2);
    dm_redraw_category_screen();

}


void ShowCategory212FmgrMarkScreen(
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
        U8 *history_buffer)
{
    wgui_cat212_fmgr_get_info_ptr = get_info_data;
    wgui_cat212_fmgr_hide_data_info_ptr = hide_info_data;

    ShowCategory211InternalScreen(
        title,
        title_icon,
        left_softkey,
        left_softkey_icon,
        right_softkey,
        right_softkey_icon,
        num_of_items,
        get_item_func,
        get_hint_func,
        wgui_cat212_fmgr_draw_info,
        wgui_cat212_fmgr_hide_info,
        get_image_func,
        set_state_func,
        (S32) num_of_info_box_rows * MMI_ICONTEXT_MENUITEM_HEIGHT - 1, /* need 1 pixel between info and list */
        info_bg_img_id,
        info_message,
        highlighted_item,
        history_buffer);
}


void ShowCategory212FmgrScreen(
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
        U8 *history_buffer)
{
    wgui_cat212_fmgr_get_info_ptr = get_info_data;
    wgui_cat212_fmgr_hide_data_info_ptr = hide_info_data;
    
    ShowCategory211Screen(
        title,
        title_icon,
        left_softkey,
        left_softkey_icon,
        right_softkey,
        right_softkey_icon,
        num_of_items,
        get_item_func,
        get_hint_func,
        wgui_cat212_fmgr_draw_info,
        wgui_cat212_fmgr_hide_info,
        (S32) num_of_info_box_rows * MMI_ICONTEXT_MENUITEM_HEIGHT - 1, /* need 1 pixel between info and list */
        info_bg_img_id,
        highlighted_item,
        history_buffer);
}

/*****************************************************************************
 * FUNCTION
 *  ShowCategory212Screen
 * DESCRIPTION
 *  Show sategory 212 screen.
 * PARAMETERS
 *  title                       [IN]        Title string id
 *  title_icon                  [IN]        Title image id
 *  left_softkey                [IN]        Lsk string id
 *  left_softkey_icon           [IN]        Lsk image id
 *  right_softkey               [IN]        Rsk string id
 *  right_softkey_icon          [IN]        Rsk image id
 *  num_of_items                [IN]        How many items
 *  get_item_func               [IN]        Callback function to get item string
 *  get_hint_func               [IN]        Callback function to get item hint
 *  draw_info_callback          [IN]        Callback function to draw info
 *  hide_info_callback          [IN]        Callback function to hide info
 *  num_of_info_box_rows        [IN]        How many row (height) for info box
 *  info_bg_img_id              [IN]        (unused)
 *  highlighted_item            [IN]        Highlighted item
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory212Screen(
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
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory211Screen(
        title, 
        title_icon,
        left_softkey,
        left_softkey_icon,
        right_softkey,
        right_softkey_icon,
        num_of_items,
        get_item_func,
        get_hint_func,
        draw_info_callback,
        hide_info_callback,
        (S32) num_of_info_box_rows * MMI_ICONTEXT_MENUITEM_HEIGHT - 1, /* need 1 pixel between info and list */
        info_bg_img_id,
        highlighted_item,
        history_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory212Screen
 * DESCRIPTION
 *  Exit category 212 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitCategory212Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cat212_hide_info_callback != NULL)
    {
        cat212_hide_info_callback();
    }
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_unblock_list_effect();
#endif 
    ClearHighlightHandler();
    reset_softkeys();
    reset_menu_shortcut_handler();
    reset_dynamic_list();
    reset_pop_up_descriptions();
    gui_scrolling_text_stop(&scroll_text_cat212);

    /* reset cat212 related golbal var */
    cat212_info_box_height = 0;

    cat212_draw_info_callback = NULL;
    cat212_hide_info_callback = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  DrawCate212CategoryControlArea
 * DESCRIPTION
 *  This function is used to draw the category controlled area of category212 screen
 * PARAMETERS
 *  coordinate      [IN/OUT]        Coordinates of category controlled area.
 * RETURNS
 *  void
 *****************************************************************************/
void DrawCate212CategoryControlArea(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory212InfoArea(MMI_fixed_list_menu.highlighted_item);
    coordinate->s16X = 0;
    coordinate->s16Y = MMI_SUBMENU_CONTENT_Y;
    coordinate->s16Height = cat212_info_box_height + 1; /* need 1 pixel between info and list */
    coordinate->s16Width = MMI_content_width;
}

/*****************************************************************************
 * FUNCTION
 *  wgui_cat212_scrolling_timer
 * DESCRIPTION
 *  category 212 scrolling timer handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat212_scrolling_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_handle_scrolling_text(&scroll_text_cat212);
}

/*****************************************************************************
 * FUNCTION
 *  wgui_cat212_scrolling_text_draw_background
 * DESCRIPTION
 *  Draw category 212 scrolling text draw background
 * PARAMETERS
 *  x1      [IN]        Start x posityion
 *  y1      [IN]        Start y position
 *  x2      [IN]        End x position
 *  y2      [IN]        End y position
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat212_scrolling_text_draw_background(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
}

/*****************************************************************************
 * FUNCTION
 *  DrawCate212CategoryControlArea2
 * DESCRIPTION
 *  This function is used to draw the category controlled area of category212 screen
 * PARAMETERS
 *  coordinate      [IN/OUT]        Coordinates of category controlled area.
 * RETURNS
 *  void
 *****************************************************************************/
void DrawCate212CategoryControlArea2(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 y1, w1, h1, y = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_cat212_info == NULL)
        return;
    y1 = MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - MMI_MENUITEM_HEIGHT - 1;
	gui_measure_string(g_cat212_info, &w1, &h1);
	if(h1 < MMI_MENUITEM_HEIGHT)
	{
		y = (MMI_MENUITEM_HEIGHT - h1)>>1;
	}
    gui_reset_clip();
    gui_lock_double_buffer();
    gui_create_scrolling_text(
            &scroll_text_cat212,
            5,
            y1 + y,
            (UI_device_width - 10),
            MMI_MENUITEM_HEIGHT - y,
            g_cat212_info,
            wgui_cat212_scrolling_timer,
            wgui_cat212_scrolling_text_draw_background,
            *current_MMI_theme->list_normal_text_color,
            gui_color(255, 255, 255));
    gui_show_scrolling_text(&scroll_text_cat212);
    gui_unlock_double_buffer();
}


/*****************************************************************************
 * FUNCTION
 *  DrawTextAreaBackground
 * DESCRIPTION
 *  Show the background of text area
 * PARAMETERS
 *  x1              [IN]        x1
 *  y1              [IN]        y1
 *  x2              [IN]        x2
 *  y2              [IN]        y2
 * RETURNS
 *  void
 *****************************************************************************/
void DrawTextAreaBackground(S32 x1, S32 y1, S32 x2, S32 y2)
{
    S32 info_bg_y,info_bg_bottom_y;
    S32 image_width, image_height;
    
    /* Draw top area */
    info_bg_y = y1;
    gdi_image_get_dimension_id(WGUI_IMG_TEXT_BG_TOP, &image_width, &image_height);
    gdi_image_draw_id(x1, info_bg_y, WGUI_IMG_TEXT_BG_TOP);
    info_bg_y += image_height;

    /* Draw bottom area */
    gdi_image_get_dimension_id(WGUI_IMG_TEXT_BG_BOTTOM, &image_width, &image_height);
    info_bg_bottom_y = (y2 - image_height + 1);
    gdi_image_draw_id(x1, info_bg_bottom_y, WGUI_IMG_TEXT_BG_BOTTOM);

    /* Draw middle area */
    gui_push_clip();
    gui_set_clip(
        x1,
        info_bg_y,
        x2,
        info_bg_bottom_y - 1);

    gdi_image_get_dimension_id(WGUI_IMG_TEXT_BG_MID, &image_width, &image_height);
    do
    {
        gdi_image_draw_id(x1, info_bg_y, WGUI_IMG_TEXT_BG_MID);
        info_bg_y += image_height;
    }while ((info_bg_y < info_bg_bottom_y) && (image_height != 0));
    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  FillFullTextBackground
 * DESCRIPTION
 *  fill full area with text background image
 * PARAMETERS
 *  x1              [IN]        x1
 *  y1              [IN]        y1
 *  x2              [IN]        x2
 *  y2              [IN]        y2
 * RETURNS
 *  void
 *****************************************************************************/
void FillFullTextBackground(S32 x1, S32 y1, S32 x2, S32 y2)
{
    S32 info_bg_y;
    S32 image_width, image_height;
    
    /* Draw middle area */
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
    
    info_bg_y = y1;
    gdi_image_get_dimension_id(WGUI_IMG_TEXT_BG_PREVIEW, &image_width, &image_height);
    do
    {
        gdi_image_draw_id(x1, info_bg_y, WGUI_IMG_TEXT_BG_PREVIEW);
        info_bg_y += image_height;
    }while ((info_bg_y <= y2) && (image_height != 0));
    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory212InfoArea
 * DESCRIPTION
 *  Show the info area for category212
 * PARAMETERS
 *  item_idx        [IN]        Item_index
 * RETURNS
 *  void
 *****************************************************************************/
static void ShowCategory212InfoArea(S32 item_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;
    S32 str_width;
    S32 str_height;
    S8 *str_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* call dynamic list's hilight handler */
    dynamic_list_highlight_handler(item_idx);

    gdi_layer_lock_frame_buffer();

    /* drive info block */
    gui_reset_clip();

    /* stop previous action, such as gif animation, decoder, timer etc. */
    if (cat212_hide_info_callback != NULL)
    {
        cat212_hide_info_callback();
    }

    gdi_image_cache_reset();

#if defined(__MMI_MAINLCD_128X128__)  
    gui_fill_rectangle(
        0,
        (MMI_SUBMENU_CONTENT_Y),
        UI_device_width - 1,
        (MMI_SUBMENU_CONTENT_Y) + cat212_info_box_height - 1,
        gui_color(255, 255, 255));
    gui_draw_rectangle(
        0,
        (MMI_SUBMENU_CONTENT_Y),
        UI_device_width - 1,
        (MMI_SUBMENU_CONTENT_Y) + cat212_info_box_height - 1,
        gui_color(0, 0, 0));
#else
    DrawTextAreaBackground(
        0,
        (MMI_SUBMENU_CONTENT_Y),
        UI_device_width - 1, 
        (MMI_SUBMENU_CONTENT_Y) + cat212_info_box_height - 1);
#endif

    /* if is emtpty folder, show a empty string */
    if (MMI_fixed_list_menu.n_items == 0)
    {
        gui_set_font(&MMI_medium_font);
        gui_set_text_color(*current_MMI_theme->list_normal_text_color);

#if defined(__MMI_FILE_MANAGER__)
        str_ptr = GetString(STR_ID_FMGR_EMPTY_FOLDER);
#else /* defined(__MMI_FILE_MANAGER__) */
        str_ptr = GetString(STR_GLOBAL_EMPTY_LIST);
#endif /* defined(__MMI_FILE_MANAGER__) */

        gui_measure_string((UI_string_type) str_ptr, &str_width, &str_height);
        offset_x = (UI_device_width - str_width) >> 1;
        offset_y = (UI_device_height - str_height) >> 1;

        if (r2lMMIFlag)
        {
            gui_move_text_cursor(offset_x + str_width, offset_y);
        }
        else
        {
            gui_move_text_cursor(offset_x, offset_y);
        }

        gui_print_text((UI_string_type) str_ptr);
    }

    if (cat212_draw_info_callback != NULL)
    {
        cat212_draw_info_callback(
            MMI_fixed_list_menu.highlighted_item,   /* idx */
            0,                                      /* x1 */
            (MMI_SUBMENU_CONTENT_Y),       /* y1 */
            UI_device_width - 1,                    /* x2 */
            (MMI_SUBMENU_CONTENT_Y) + cat212_info_box_height - 1);       /* y2 */
    }

    /* 
     * lock then blt, will not update to lcm directly, but will force next blt function 
     * also update this region 
     */
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    gdi_layer_unlock_frame_buffer();

}


/*****************************************************************************
 * FUNCTION
 *  Cat212ShortCutHdlr
 * DESCRIPTION
 *  Category 212 short cut goto item hdlr
 * PARAMETERS
 *  item_index      [IN]        Goto item's index
 * RETURNS
 *  void
 *****************************************************************************/
void Cat212ShortCutHdlr(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_list_menu.n_items <= 0)
    {
        return;
    }
    if (item_index == MMI_fixed_list_menu.highlighted_item)
    {
        return;
    }

    gui_dynamic_list_menu_goto_item(&MMI_fixed_list_menu, item_index);

    if (item_index == MMI_fixed_list_menu.highlighted_item)
    {
        RedrawCategoryFunction();
    }
}


/*****************************************************************************
 * FUNCTION
 *  DrawCate213CategoryControlArea
 * DESCRIPTION
 *  draw control area
 * PARAMETERS
 *  coordinate      [IN]        Coordinate
 * RETURNS
 *  void
 *****************************************************************************/
void DrawCate213CategoryControlArea(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;
    S32 str_width;
    S32 str_height;
    S8 *str_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_list_menu.n_items == 0)
    {
        show_dynamic_list();
        gui_reset_text_clip();
        gui_set_font(&MMI_medium_font);
        gui_set_text_color(*current_MMI_theme->list_normal_text_color);

#if defined(__MMI_FILE_MANAGER__)
        str_ptr = GetString(STR_ID_FMGR_EMPTY_FOLDER);
#else /* defined(__MMI_FILE_MANAGER__) */
        str_ptr = GetString(STR_GLOBAL_EMPTY_LIST);
#endif /* defined(__MMI_FILE_MANAGER__) */

        gui_measure_string((UI_string_type) str_ptr, &str_width, &str_height);
        offset_x = (UI_device_width - str_width) >> 1;
        offset_y = (UI_device_height - str_height) >> 1;

        if (r2lMMIFlag)
        {
            gui_move_text_cursor(offset_x + str_width, offset_y);
        }
        else
        {
            gui_move_text_cursor(offset_x, offset_y);
        }

        gui_print_text((UI_string_type) str_ptr);
    }
    else
    {
        Cat213RedrawDynamicList();
    }
}

#ifdef __MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  category213_control_area_pen_handler
 * DESCRIPTION
 *  pen handler
 * PARAMETERS
 *  point           [IN]        pen event position
 *  pen_event       [IN]        pen event type
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL category213_control_area_pen_handler(mmi_pen_point_struct point, mmi_pen_event_type_enum pen_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Display prompt string instead of menu */
    if (MMI_fixed_list_menu.n_items == 0)
    {
        return MMI_FALSE;
    }

    if (pen_event == MMI_PEN_EVENT_DOWN)
    {
        MMI_fixed_list_menu.pen_redraw_menu_function = Cat213RedrawDynamicList;
        gui_vertical_scrollbar_set_pen_self_scroll(&MMI_fixed_list_menu.vbar, MMI_TRUE);
        gui_fixed_list_menu_set_pen_scroll_delay(&MMI_fixed_list_menu, GUI_DYNAMIC_LIST_PEN_SCROLL_DELAY);
    }

    return wgui_general_pen_dynamic_list_menu_hdlr(point, pen_event);
}


/*****************************************************************************
 * FUNCTION
 *  category213_control_area_pen_down_handler
 * DESCRIPTION
 *  pen down handler
 * PARAMETERS
 *  point       [IN]        pen down position
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL category213_control_area_pen_down_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return category213_control_area_pen_handler(point, MMI_PEN_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  category213_control_area_pen_move_handler
 * DESCRIPTION
 *  pen move handler
 * PARAMETERS
 *  point       [IN]        pen move position
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL category213_control_area_pen_move_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return category213_control_area_pen_handler(point, MMI_PEN_EVENT_MOVE);
}


/*****************************************************************************
 * FUNCTION
 *  category213_control_area_pen_longtap_handler
 * DESCRIPTION
 *  pen longtap handler
 * PARAMETERS
 *  point       [IN]        pen longtap handler
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL category213_control_area_pen_longtap_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return category213_control_area_pen_handler(point, MMI_PEN_EVENT_LONG_TAP);
}


/*****************************************************************************
 * FUNCTION
 *  category213_control_area_pen_repeat_handler
 * DESCRIPTION
 *  pen repeat handler
 * PARAMETERS
 *  point       [IN]        pen repeat position
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL category213_control_area_pen_repeat_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return category213_control_area_pen_handler(point, MMI_PEN_EVENT_REPEAT);
}


/*****************************************************************************
 * FUNCTION
 *  category213_control_area_pen_up_handler
 * DESCRIPTION
 *  pen up handler
 * PARAMETERS
 *  point       [IN]        pen up position
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL category213_control_area_pen_up_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return category213_control_area_pen_handler(point, MMI_PEN_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  category213_control_area_pen_abort_handler
 * DESCRIPTION
 *  pen abourt handler
 * PARAMETERS
 *  point       [IN]        pen abort position
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL category213_control_area_pen_abort_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return category213_control_area_pen_handler(point, MMI_PEN_EVENT_ABORT);
}

#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
* FUNCTION
*  GetCategory213HistorySize
* DESCRIPTION
*  Gets the history buffer size of category 213
* PARAMETERS
*  void
* RETURNS
*  size in U8s of the history buffer
*****************************************************************************/
S32 GetCategory213HistorySize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return sizeof(list_menu_category_history);
}


/*****************************************************************************
* FUNCTION
*  GetCategory213History
* DESCRIPTION
*  Gets the history buffer of category213
* PARAMETERS
*  history_buffer      [OUT]        Is the buffer into which the history data is stored
* RETURNS
*  return history buffer
*****************************************************************************/
U8 *GetCategory213History(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_list_menu_category_history(MMI_CATEGORY213_ID, history_buffer);
    return (history_buffer);
}

void ShowCategory213FmgrScreen(
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
        U8 *history_buffer)    
{
    wgui_cat_fmgr_get_menuitem = get_menuitem_data;
    wgui_cat_fmgr_hide_menuitem = hide_menuitem_data;

    ShowCategory213Screen(
        title,
        title_icon,
        left_softkey,
        left_softkey_icon,
        right_softkey,
        right_softkey_icon,
        num_of_items,
        wgui_cat213_fmgr_draw_menuitem,
        wgui_cat213_fmgr_hide_menuitem,
        highlighted_item,
        arrow_flag,
        history_buffer);
}

/*****************************************************************************
* [Category213]
*
* This category is for ImageViewer to display drive info.
*
*  **********************
*  *  ####  FileName    *
*  *  ####  Res    Size *  
*  **********************
*  *  ####  FileName    *
*  *  ####  Res    Size *  
*  **********************
*  *  ####  FileName    *
*  *  ####  Res    Size *  
*  **********************
*  *  ####  FileName    *
*  *  ####  Res    Size *  
*  **********************
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ShowCategory213Screen
 * DESCRIPTION
 *  Show sategory 223 screen.
 * PARAMETERS
 *  title                       [IN]        Title string id
 *  title_icon                  [IN]        Title image id
 *  left_softkey                [IN]        Lsk string id
 *  left_softkey_icon           [IN]        Lsk image id
 *  right_softkey               [IN]        Rsk string id
 *  right_softkey_icon          [IN]        Rsk image id
 *  num_of_items                [IN]        How many items
 *  draw_menuitem_callback      [IN]        Callback function to draw menuitem
 *  hide_menuitem_callback      [IN]        Callback function to hide menuitem
 *  highlighted_item            [IN]        Highlighted item index
 *  arrow_flag                  [IN]        Arrow on buttom bar
 *  history_buffer              [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory213Screen(
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
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    U8 h_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    cat213_draw_menuitem_callback = draw_menuitem_callback;
    cat213_hide_menuitem_callback = hide_menuitem_callback;

    cat213_menuitem_per_screen = MMI_content_height / (MMI_thick_menuitem_height - 1);

    /* lock */
    gui_lock_double_buffer();

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_block_list_effect();
#endif 
    ShowListCategoryScreen_ext(
        get_string(title),
        get_image(title_icon),
        get_string(left_softkey),
        get_image(left_softkey_icon),
        get_string(right_softkey),
        get_image(right_softkey_icon));
    wgui_dynamic_list_create_icontext_menu(
        num_of_items,
        Cat213GetItemCallback,
        Cat213GetHintCallback,
        WGUI_LIST_INVALID_HIGHLIGHT,
        MMI_FALSE,
        UI_dummy_function,
        0,
        0,
        NULL);

#ifdef __MMI_UI_TRANSPARENT_EFFECT__
    disable_fixed_icontext_menuitem_transparent_effect();
#endif 

#ifdef __MMI_SCREEN_ROTATE__
     if (!mmi_frm_is_screen_width_height_swapped())
#endif /* __MMI_SCREEN_ROTATE__ */
    {
        MMI_fixed_icontext_menuitem.focussed_filler = current_MMI_theme->menuitem_thick_highlight_filler;
        MMI_fixed_icontext_menuitem.selected_filler = current_MMI_theme->menuitem_thick_highlight_filler;
    }
    

    /* register shortcut */
    wgui_dynamic_list_override_icontext_shortcut_handler(Cat213ShortCutHdlr);

    clear_keyboard_key_handler();
    SetKeyHandler(Cat213KeyUpHdlr, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(Cat213KeyDownHdlr, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(Cat213KeyUpHdlr, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(Cat213KeyDownHdlr, KEY_VOL_DOWN, KEY_EVENT_DOWN);


    //resize_menu_shortcut_handler(shortcut_width, MMI_title_height);
    //move_menu_shortcut_handler(UI_device_width - MMI_menu_shortcut_box.width, MMI_title_y);
    //register_hide_menu_shortcut(draw_title);

    resize_fixed_icontext_menuitems(0, MMI_thick_menuitem_height);

    //set_fixed_icontext_positions(MMI_ICONTEXT_MENUITEM_HEIGHT, 0, 1, 0);

    /* change menuitem's height */
    move_fixed_list(0, (MMI_SUBMENU_CONTENT_Y));
    resize_fixed_list(MMI_SUBMENU_CONTENT_WIDTH, MMI_SUBMENU_CONTENT_HEIGHT);


    /* if caller wish to use gui buffer as histoy */
    h_flag = set_list_menu_category_history(MMI_CATEGORY213_ID, history_buffer);

    if (h_flag)
    {
        highlighted_item = MMI_fixed_list_menu.highlighted_item;
    }

    if (num_of_items < cat213_menuitem_per_screen)
    {
        MMI_fixed_list_menu.first_displayed_item = 0;
        MMI_fixed_list_menu.last_displayed_item = num_of_items - 1;
    }
    else
    {
        if ((num_of_items - highlighted_item) < cat213_menuitem_per_screen)
        {
            
            MMI_fixed_list_menu.first_displayed_item = num_of_items - cat213_menuitem_per_screen;
            MMI_fixed_list_menu.last_displayed_item = num_of_items - 1;
        }
        else
        {
            MMI_fixed_list_menu.first_displayed_item = highlighted_item;
            MMI_fixed_list_menu.last_displayed_item = num_of_items - 1;
        }
    }
    set_dynamic_pop_up_descriptions(highlighted_item);

    dynamic_list_goto_item_no_redraw(highlighted_item);

    /* adjust hilight - since its is thick menu and previous function will not calc correclty */
    MMI_fixed_list_menu.highlighted_item = highlighted_item;

    if (num_of_items < cat213_menuitem_per_screen)
    {
        MMI_fixed_list_menu.first_displayed_item = 0;
        MMI_fixed_list_menu.last_displayed_item = num_of_items - 1;
    }
    else
    {
        if ((num_of_items - highlighted_item) < cat213_menuitem_per_screen)
        {
            
            MMI_fixed_list_menu.first_displayed_item = num_of_items - cat213_menuitem_per_screen;
            MMI_fixed_list_menu.last_displayed_item = num_of_items - 1;
        }
        else
        {
            MMI_fixed_list_menu.first_displayed_item = highlighted_item;
            MMI_fixed_list_menu.last_displayed_item = num_of_items - 1;
        }
    }

    resize_dynamic_icontext_menuitems_to_list_width();
    resize_fixed_icontext_menuitems(0, MMI_thick_menuitem_height);


    gui_unlock_double_buffer();

    ExitCategoryFunction = ExitCategory213Screen;
    dm_setup_category_functions(dm_redraw_category_screen, GetCategory213History, GetCategory213HistorySize);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY213_ID;
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_category_screen_control_area_pen_handlers(
        category213_control_area_pen_down_handler,
        MMI_PEN_EVENT_DOWN);
    wgui_register_category_screen_control_area_pen_handlers(category213_control_area_pen_up_handler, MMI_PEN_EVENT_UP);
    wgui_register_category_screen_control_area_pen_handlers(
        category213_control_area_pen_move_handler,
        MMI_PEN_EVENT_MOVE);
    wgui_register_category_screen_control_area_pen_handlers(
        category213_control_area_pen_repeat_handler,
        MMI_PEN_EVENT_REPEAT);
    wgui_register_category_screen_control_area_pen_handlers(
        category213_control_area_pen_longtap_handler,
        MMI_PEN_EVENT_LONG_TAP);
    wgui_register_category_screen_control_area_pen_handlers(
        category213_control_area_pen_abort_handler,
        MMI_PEN_EVENT_ABORT);
#endif /* __MMI_TOUCH_SCREEN__ */ 
    dm_setup_data(&dm_data);
    dm_register_category_controlled_callback(DrawCate213CategoryControlArea);
    dm_redraw_category_screen();

}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory213Screen
 * DESCRIPTION
 *  Exit category 213 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitCategory213Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearHighlightHandler();
    reset_softkeys();
    reset_menu_shortcut_handler();
    reset_dynamic_list();
    reset_pop_up_descriptions();
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_unblock_list_effect();
#endif 
#ifdef __MMI_UI_TRANSPARENT_EFFECT__
    enable_fixed_icontext_menuitem_transparent_effect();
#endif 

    if (cat213_hide_menuitem_callback != NULL)
    {
        cat213_hide_menuitem_callback();
    }

    cat213_draw_menuitem_callback = NULL;
    cat213_hide_menuitem_callback = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  Cat213GetItemCallback
 * DESCRIPTION
 *  Get category 213 get item callback function
 * PARAMETERS
 *  item_idx            [IN]        
 *  str_buff            [IN]        
 *  img_buff_p          [?]         
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static pBOOL Cat213GetItemCallback(S32 item_idx, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((PS8) str_buff, (PS8) L"");
    *img_buff_p = NULL;;

    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  Cat213GetHintCallback
 * DESCRIPTION
 *  Get category 213 get hint callback function
 * PARAMETERS
 *  item_idx        [IN]        
 *  hint_array      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static S32 Cat213GetHintCallback(S32 item_idx, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* do nothing */
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  Cat213RedrawDynamicList
 * DESCRIPTION
 *  Redraw category 213 dynamic list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat213RedrawDynamicList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    BOOL is_done;
    S32 item_width, item_height;
    S32 offset_y;
    S32 total_height;
    S32 counter;
    S32 list_height;
    BOOL is_hilighted;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* hide previous menuitems, usually stop animation and some off-line decoder */
    if (cat213_hide_menuitem_callback != NULL)
    {
        cat213_hide_menuitem_callback();
    }

    gui_lock_double_buffer();

    /* show list, only show the frame - content will be draw by callback function */
    show_dynamic_list();

    list_height = MMI_fixed_list_menu.height;
    is_done = FALSE;
    total_height = 0;
    counter = 0;

    MMI_fixed_list_menu.item_measure_function(
                            MMI_fixed_list_menu.items[0],
                            MMI_fixed_list_menu.common_item_data,
                            &item_width,
                            &item_height);
    item_height = MMI_thick_menuitem_height;

    for (i = MMI_fixed_list_menu.first_displayed_item; (i < MMI_fixed_list_menu.n_items && !is_done); i++)
    {
        if (i == MMI_fixed_list_menu.highlighted_item)
        {
        #ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
            g_mmi_frm_cntx.dump_screen_info.hightlight_type = MMI_SCREEN_HIGHLIGHT_FOR_CAR213_DYNAMIC_LIST;
        #endif

            is_hilighted = TRUE;
        }
        else
        {
            is_hilighted = FALSE;
        }

        if (i == MMI_fixed_list_menu.highlighted_item)
        {
            current_fixed_list_menuitem_display_index = -1;
        }
        else
        {
            current_fixed_list_menuitem_display_index = i;
        }

        offset_y = total_height;
        total_height += item_height;

        if (total_height > list_height + 1)
        {
            is_done = TRUE;
            if (counter == 0)
            {
                if (cat213_draw_menuitem_callback != NULL)
                {
                    if (r2lMMIFlag)
                    {
                        cat213_draw_menuitem_callback(
                            i,
                            is_hilighted,
                            MMI_fixed_list_menu.x + MMI_fixed_list_menu.vbar.width + 1,
                            MMI_fixed_list_menu.y + offset_y + MMI_fixed_list_menu.top,
                            MMI_fixed_list_menu.x + MMI_fixed_list_menu.vbar.width + item_width + 1,
                            MMI_fixed_list_menu.y + offset_y + item_height + MMI_fixed_list_menu.top);
                    }
                    else
                    {
                        cat213_draw_menuitem_callback(
                            i,
                            is_hilighted,
                            MMI_fixed_list_menu.x + 1,
                            MMI_fixed_list_menu.y + offset_y + MMI_fixed_list_menu.top,
                            MMI_fixed_list_menu.x + item_width + 1,
                            MMI_fixed_list_menu.y + offset_y + item_height + MMI_fixed_list_menu.top);
                    }
                }
            }
        }
        else
        {
            if (cat213_draw_menuitem_callback != NULL)
            {
                if (r2lMMIFlag)
                {
                    cat213_draw_menuitem_callback(
                        i,
                        is_hilighted,
                        MMI_fixed_list_menu.x + MMI_fixed_list_menu.vbar.width + 1,
                        MMI_fixed_list_menu.y + offset_y + MMI_fixed_list_menu.top,
                        MMI_fixed_list_menu.x + MMI_fixed_list_menu.vbar.width + item_width + 1,
                        MMI_fixed_list_menu.y + offset_y + item_height + MMI_fixed_list_menu.top);
                }
                else
                {
                    cat213_draw_menuitem_callback(
                        i,
                        is_hilighted,
                        MMI_fixed_list_menu.x + 1,
                        MMI_fixed_list_menu.y + offset_y + MMI_fixed_list_menu.top,
                        MMI_fixed_list_menu.x + item_width + 1,
                        MMI_fixed_list_menu.y + offset_y + item_height + MMI_fixed_list_menu.top);
                }

            }
            counter++;
        }
    }

    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  Cat213KeyUpHdlr
 * DESCRIPTION
 *  Category 213 key up handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat213KeyUpHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hilight_idx = MMI_fixed_list_menu.highlighted_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_list_menu.n_items <= 0)
    {
        return;
    }
    if ((MMI_fixed_list_menu.n_items == 1) && (MMI_fixed_list_menu.highlighted_item == 0))
    {
        return;
    }

    if (hilight_idx - 1 >= 0)
    {
        hilight_idx--;
    }
    else
    {
        hilight_idx = MMI_fixed_list_menu.n_items - 1;
    }

    gui_lock_double_buffer();

    /* goto prev item */
    gui_dynamic_list_menu_goto_item(&MMI_fixed_list_menu, hilight_idx);

    /* redraw dynamic list */
    Cat213RedrawDynamicList();

    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  Cat213KeyDownHdlr
 * DESCRIPTION
 *  Category 213 key down handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat213KeyDownHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hilight_idx = MMI_fixed_list_menu.highlighted_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_list_menu.n_items <= 0)
    {
        return;
    }
    if ((MMI_fixed_list_menu.n_items == 1) && (MMI_fixed_list_menu.highlighted_item == 0))
    {
        return;
    }

    if (hilight_idx + 1 < MMI_fixed_list_menu.n_items)
    {
        hilight_idx++;
    }
    else
    {
        hilight_idx = 0;
    }

    gui_lock_double_buffer();

    /* goto next item */
    gui_dynamic_list_menu_goto_item(&MMI_fixed_list_menu, hilight_idx);

    /* redraw dynamic list */
    Cat213RedrawDynamicList();

    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  Cat213ShortCutHdlr
 * DESCRIPTION
 *  Category 213 shot cut key press handler
 * PARAMETERS
 *  item_index      [IN]        Item index
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat213ShortCutHdlr(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_fixed_list_menu.n_items <= 0)
    {
        return;
    }
    if (item_index == MMI_fixed_list_menu.highlighted_item)
    {
        return;
    }

    gui_dynamic_list_menu_goto_item(&MMI_fixed_list_menu, item_index);

    if (item_index == MMI_fixed_list_menu.highlighted_item)
    {
        RedrawCategoryFunction();
    }
}

/*****************************************************************************
* [Category214]
*
* This category is for File Manager to display drive info.
*
*  *********************
*  *                  ----------- Title
*  *********************
*  *  ******* *******  *
*  *  *     * *     *  *
*  *  *     * *     ----------- Matrix Images
*  *  ******* *******  *
*  *  ******* *******  *
*  *  *     * *     *  *
*  *  *     * *     *  *
*  *  ******* *******  *
*  *********************
*
*****************************************************************************/

void ShowCategory214FmgrScreen(
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
        U8 *history_buffer)
{
    wgui_cat_fmgr_get_menuitem = get_menuitem_data;
    wgui_cat_fmgr_hide_menuitem = hide_menuitem_data; 

    ShowCategory214Screen(
            title,
            title_icon,
            left_softkey,
            left_softkey_icon,
            right_softkey,
            right_softkey_icon,
            num_of_items,
            wgui_cat214_fmgr_draw_menuitem_matrix,
            wgui_cat214_fmgr_hide_menuitem_matrix,
            num_per_row,
            num_per_col,
            highlighted_item,
            history_buffer);
}

/*****************************************************************************
 * FUNCTION
 *  ShowCategory214Screen
 * DESCRIPTION
 *  Show sategory 214 screen.
 * PARAMETERS
 *  title                   [IN]        Title string id
 *  title_icon              [IN]        Title image id
 *  left_softkey            [IN]        Lsk string id
 *  left_softkey_icon       [IN]        Lsk image id
 *  right_softkey           [IN]        Rsk string id
 *  right_softkey_icon      [IN]        Rsk image id
 *  num_of_items            [IN]        How many items
 *  draw_image_callback     [IN]        Callback function to draw image
 *  hide_image_callback     [IN]        Callback function to hide
 *  num_per_row             [IN]        Num of image pre row
 *  num_per_col             [IN]        Num of image pre col
 *  highlighted_item        [IN]        Highlighted item
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory214Screen(
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
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;

#ifndef __MMI_WALLPAPER_ON_BOTTOM__
    GDI_HANDLE cat214_bg_layer;
#endif 

    S32 num_of_page;
    S32 item_per_page;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* arg checking */
    MMI_ASSERT(num_per_row != 0);
    MMI_ASSERT(num_per_col != 0);

    /* Show shortcut when fullscreen backgournd */
    wgui_title_set_no_icon_shct(MMI_TRUE);

    gui_setup_submenu_layout();

    cat214_draw_image_callback = draw_image_callback;
    cat214_hide_image_callback = hide_image_callback;
    cat214_num_per_row = num_per_row;
    cat214_num_per_col = num_per_col;
    cat214_hilighted_index = (U16) highlighted_item;
    cat214_prev_hilighted_index = (U16) highlighted_item;
    cat214_item_count = num_of_items;
    cat214_page_index = -1; /* this will force to redraw whole matrix */

    MMI_menu_shortcut_number = -1;

    /* init highligthed item idx */
    MMI_fixed_list_menu.highlighted_item = 0;
    MMI_fixed_list_menu.n_items = num_of_items;

    item_per_page = num_per_row * num_per_col;
    num_of_page = num_of_items / (item_per_page);

    if (num_of_items % item_per_page != 0)
    {
        num_of_page++;
    }

    /* use MMI_fixed_list_menu's history */
    if (set_list_menu_category_history(MMI_CATEGORY214_ID, history_buffer))
    {
/* Vogins Start */
#ifdef __VRE__
		if(MMI_fixed_list_menu.highlighted_item > (num_of_items - 1))
		{
			MMI_fixed_list_menu.highlighted_item = num_of_items - 1;
		}
#endif
/* Vogins End */
        cat214_hilighted_index = (U16) MMI_fixed_list_menu.highlighted_item;
    }

    /* create layer */
#ifdef __GDI_MEMORY_PROFILE_2__
    gdi_layer_multi_layer_enable();
#endif
    
    gdi_layer_lock_frame_buffer();

    if (num_of_items != 0)
    {
        /* use fixed list menu's scroll bar to save memory */
        if (r2lMMIFlag)
        {
            gui_create_vertical_scrollbar(
                &MMI_fixed_list_menu.vbar,
                0,
                (MMI_SUBMENU_CONTENT_Y),
                current_MMI_theme->scrollbar_size,
                MMI_content_height);

        }
        else
        {
            gui_create_vertical_scrollbar(
                &MMI_fixed_list_menu.vbar,
                UI_device_width - current_MMI_theme->scrollbar_size,
                (MMI_SUBMENU_CONTENT_Y),
                current_MMI_theme->scrollbar_size,
                MMI_content_height);
        }

        gui_set_vertical_scrollbar_range(&MMI_fixed_list_menu.vbar, num_of_page);
        gui_set_vertical_scrollbar_scale(&MMI_fixed_list_menu.vbar, 1);
        gui_set_vertical_scrollbar_value(&MMI_fixed_list_menu.vbar, highlighted_item / item_per_page);
        gui_show_vertical_scrollbar(&MMI_fixed_list_menu.vbar);
    }

    gdi_layer_get_base_handle(&wgui_base_layer);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_set_opacity(TRUE, UI_SUBMENU_OPACITY_BASED_LAYER);

#if !(defined(__MMI_WALLPAPER_ON_BOTTOM__)) && defined(__GDI_MEMORY_PROFILE_2__)
    /* dm will draw a wallpaper bg on extra layer */

    dm_create_layer(0, 0, UI_device_width, UI_device_height, &cat214_bg_layer, DM_LAYER_BOTTOM);
    gdi_layer_push_and_set_active(cat214_bg_layer);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_reset_clip();
    /* draw fix list backgroud */
    gui_draw_filled_area(
        0,
        MMI_content_y,
        UI_device_width - 1,
        MMI_content_y + MMI_content_height - 1,
        current_MMI_theme->list_background_filler);

    gdi_layer_pop_and_restore_active();

#endif /* !(defined(__MMI_WALLPAPER_ON_BOTTOM__)) && defined(__GDI_MEMORY_PROFILE_2__) */ 

    /* shortcut */
    register_menu_shortcut_keys();
    register_menu_shortcut_selected_only(Cat214ShortCutHdlr);

    set_menu_item_count(num_of_items);
    //resize_menu_shortcut_handler(set_menu_item_count(num_of_items) + 7, MMI_title_height);
    //move_menu_shortcut_handler(UI_device_width - MMI_menu_shortcut_box.width, MMI_title_y);
    //register_hide_menu_shortcut(draw_title);

    if (cat214_item_count != 0)
    {
        MMI_menu_shortcut_number = cat214_hilighted_index + 1;
    }

    MMI_disable_title_shortcut_display = FALSE;

    change_left_softkey(left_softkey, left_softkey_icon);
    change_right_softkey(right_softkey, right_softkey_icon);
    SetupCategoryKeyHandlers();

    SetKeyHandler(Cat214KeyUpHdlr, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(Cat214KeyDownHdlr, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(Cat214KeyUpHdlr, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(Cat214KeyDownHdlr, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    SetKeyHandler(Cat214KeyLeftHdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(Cat214KeyRightHdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    /* init title */
    MMI_title_string = (UI_string_type) get_string(title);
    MMI_title_icon = (PU8) get_image(title_icon);

    /* call highlight handler */
    if ((MMI_list_highlight_handler != NULL) && (num_of_items != 0))
    {
        MMI_list_highlight_handler(cat214_hilighted_index);
    }

    gdi_layer_unlock_frame_buffer();

    ExitCategoryFunction = ExitCategory214Screen;
    dm_setup_category_functions(dm_redraw_category_screen, GetCategory214History, get_list_menu_category_history_size);

#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_category_screen_control_area_pen_handlers(Cat214CategoryControlAreaPenDownHdlr, MMI_PEN_EVENT_DOWN);
    wgui_register_category_screen_control_area_pen_handlers(Cat214CategoryControlAreaPenMoveHdlr, MMI_PEN_EVENT_MOVE);
    wgui_register_category_screen_control_area_pen_handlers(Cat214CategoryControlAreaPenUpHdlr, MMI_PEN_EVENT_UP);
#endif /* __MMI_TOUCH_SCREEN__ */ 

    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY214_ID;
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    dm_setup_data(&dm_data);
    dm_register_category_controlled_callback(DrawCate214CategoryControlArea);
    dm_redraw_category_screen();

}
/* Vogins Start */
#ifdef __VRE__
void wgui_cat214_disable_draw_highlight(void)
{
    g_wgui_cat214_disable_highlgiht = MMI_TRUE;
}
#endif
/* Vogins End */
/*****************************************************************************
 * FUNCTION
 *  ExitCategory214Screen
 * DESCRIPTION
 *  Exit category 214
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitCategory214Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearHighlightHandler();
    reset_menu_shortcut_handler();
    reset_softkeys();

    /* hide image callback */
    if (cat214_hide_image_callback != NULL)
    {
        cat214_hide_image_callback(cat214_prev_hilighted_index);
    }
/* Vogins Start */
#ifdef __VRE__
    g_wgui_cat214_disable_highlgiht = MMI_FALSE;
#endif
/* Vogins End */
#ifdef __GDI_MEMORY_PROFILE_2__
    /* flatten layer */
    gdi_layer_flatten_previous_to_base();

    gdi_layer_set_blt_layer(wgui_base_layer, 0, 0, 0);
    gdi_layer_multi_layer_disable();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  GetCategory214History
 * DESCRIPTION
 *  Get category214 history.
 * PARAMETERS
 *  history_buffer      [OUT]        History buffer
 * RETURNS
 *  hitsory buffer
 *****************************************************************************/
static U8 *GetCategory214History(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_list_menu_category_history(MMI_CATEGORY214_ID, history_buffer);
    return (history_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  Cat214RedrawMatrix
 * DESCRIPTION
 *  Redraw Category 214 Matrix
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* Vogins Start */
static void Cat214RedrawMatrix(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 content_offset_x;
    S32 content_offset_y;
    S32 content_width;
    S32 content_height;
    S32 box_offset_x;
    S32 box_offset_y;
    S32 box_width;
    S32 box_height;
    S32 i, j;
    S32 index;
    S32 cur_page_index;
#ifdef __VRE__
    S32 cur_page_last_index;
#endif
    BOOL is_redraw_all;
    BOOL is_hilighted;
    S32 item_per_page;
#ifdef __MMI_MAINLCD_128X128__
    color *color_ptr;
    gdi_color box_bg_color;
#endif
    gdi_color box_frame_color;
    gdi_color box_hilight_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    gdi_layer_push_clip();

    gdi_layer_set_clip(
        0,
        MMI_SUBMENU_CONTENT_Y,
        UI_device_width - 1,
        (MMI_SUBMENU_CONTENT_Y) + MMI_SUBMENU_CONTENT_HEIGHT - 1);

    box_frame_color = gdi_act_color_from_rgb(255,150, 150, 150);
    box_hilight_color = gdi_act_color_from_rgb(255,255, 0, 0);

    /* prepare parameters */
    if (r2lMMIFlag)
    {
        content_offset_x = current_MMI_theme->scrollbar_size;
    }
    else
    {
        content_offset_x = 0;
    }

    content_width = UI_device_width - current_MMI_theme->scrollbar_size;
    content_offset_y = MMI_SUBMENU_CONTENT_Y;
    content_height = MMI_content_height;

    box_width = content_width - CAT214_OUTSIDE_SPACING * 2 - CAT214_INSIDE_SPACING * (cat214_num_per_col - 1);
    box_width /= cat214_num_per_col;

    box_height = content_height - CAT214_OUTSIDE_SPACING * 2 - CAT214_INSIDE_SPACING * (cat214_num_per_row - 1);
    box_height /= cat214_num_per_row;

    item_per_page = cat214_num_per_row * cat214_num_per_col;
    cur_page_index = (cat214_hilighted_index / item_per_page) * item_per_page;

    /* page changed, redraw whole page */
    is_redraw_all = (cur_page_index != cat214_page_index) ? TRUE : FALSE;
    cat214_page_index = (U16) cur_page_index;
#ifdef __VRE__
    cur_page_last_index = cur_page_index + item_per_page - 1;
    if (cat214_item_count - 1 < cur_page_last_index)
    {
        cur_page_last_index = cat214_item_count - 1;
    }
#endif

    /* clear whole content background */
    if (is_redraw_all)
    {
        if (r2lMMIFlag)
        {
            gdi_draw_solid_rect(
                current_MMI_theme->scrollbar_size,
                MMI_SUBMENU_CONTENT_Y,
                UI_device_width - 1,
                (MMI_SUBMENU_CONTENT_Y) + MMI_content_height - 1,
                GDI_COLOR_TRANSPARENT);
        }
        else
        {
            gdi_draw_solid_rect(
                0,
                MMI_SUBMENU_CONTENT_Y,
                UI_device_width - current_MMI_theme->scrollbar_size - 1,
                (MMI_SUBMENU_CONTENT_Y) + MMI_content_height - 1,
                GDI_COLOR_TRANSPARENT);
        }

        if (cat214_item_count != 0)
        {
            gui_set_vertical_scrollbar_value(&MMI_fixed_list_menu.vbar, cat214_hilighted_index / item_per_page);
            gui_show_vertical_scrollbar(&MMI_fixed_list_menu.vbar);
        }
    }

    /* empty category */
    if (cat214_item_count == 0)
    {
        gdi_layer_pop_clip();
        gdi_layer_unlock_frame_buffer();
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
        return;
    }

    /* draw each item */
    for (i = 0; i < cat214_num_per_row; i++)
    {
        for (j = 0; j < cat214_num_per_col; j++)
        {
            index = (cat214_page_index) + i * cat214_num_per_col + j;

            if (index < cat214_item_count)
            {
                is_hilighted = (index == cat214_hilighted_index) ? TRUE : FALSE;

                box_offset_x = box_width * j + CAT214_OUTSIDE_SPACING + CAT214_INSIDE_SPACING * j + content_offset_x;
                box_offset_y = box_height * i + CAT214_OUTSIDE_SPACING + CAT214_INSIDE_SPACING * i + content_offset_y;

                if (is_redraw_all || (index == cat214_hilighted_index) || (index == cat214_prev_hilighted_index))       /* draw all or changed */
                {
                    /* clear item's background */
                    gdi_draw_solid_rect(
                        box_offset_x - 3,
                        box_offset_y - 3,
                        box_offset_x + box_width + 2,
                        box_offset_y + box_height + 2,
                        GDI_COLOR_TRANSPARENT);

            #ifdef __MMI_MAINLCD_128X128__
                    if (is_hilighted)
                    {
                        color_ptr = &(current_MMI_theme->list_selected_item_filler->c);
                        box_bg_color = gdi_act_color_from_rgb(255,color_ptr->r, color_ptr->g, color_ptr->b);
                    }
                    else
                    {
                        color_ptr = &(current_MMI_theme->list_background_filler->c);
                        box_bg_color = gdi_act_color_from_rgb(255,color_ptr->r, color_ptr->g, color_ptr->b);
                    }

                    /* draw box */
                    gdi_draw_solid_rect(
                        box_offset_x,
                        box_offset_y,
                        box_offset_x + box_width - 1,
                        box_offset_y + box_height - 1,
                        box_bg_color);
            #else
#ifdef __VRE__
					if(!g_wgui_cat214_disable_highlgiht)
					{
#endif
                    FillFullTextBackground(box_offset_x,
                                           box_offset_y,
                                           box_offset_x + box_width - 1,
                                           box_offset_y + box_height - 1);
#ifdef __VRE__
					}
#endif
            #endif
#ifdef __VRE__
                    if(!g_wgui_cat214_disable_highlgiht)
                    {
#endif
                    if (index == cat214_hilighted_index)
                    {
                        /* highlight frame */
                        gdi_draw_rect(
                            box_offset_x - 1,
                            box_offset_y - 1,
                            box_offset_x + box_width,
                            box_offset_y + box_height,
                            box_hilight_color);
                    }
                    else
                    {
                        /* draw frame */
                        gdi_draw_rect(
                            box_offset_x - 1,
                            box_offset_y - 1,
                            box_offset_x + box_width,
                            box_offset_y + box_height,
                            box_frame_color);
                    }
#ifdef __VRE__
                    }
#endif
                    /* call draw image callback function */
                    if (cat214_draw_image_callback != NULL)
                    {
                        cat214_draw_image_callback(
                            index,
                            cur_page_index,
#ifdef __VRE__
                            cur_page_last_index,
#else
                            cur_page_index + item_per_page - 1,
#endif
                            is_hilighted,
                            TRUE,           /* need update */
                            is_redraw_all,  /* new page */
                            box_offset_x,
                            box_offset_y,
                            box_offset_x + box_width - 1,
                            box_offset_y + box_height - 1);

                    }

                }
                else
                {
#ifdef __VRE__
                    if(!g_wgui_cat214_disable_highlgiht)
                    {
#endif
                    if (index == cat214_hilighted_index)
                    {
                        /* highlight frame */
                        gdi_draw_rect(
                            box_offset_x - 1,
                            box_offset_y - 1,
                            box_offset_x + box_width,
                            box_offset_y + box_height,
                            box_hilight_color);
                    }
                    else
                    {
                        if (index == cat214_prev_hilighted_index)
                        {
                            /* clear highlight frame with transparent color */
                            gdi_draw_rect(
                                box_offset_x - 1,
                                box_offset_y - 1,
                                box_offset_x + box_width,
                                box_offset_y + box_height,
                                box_frame_color);
                        }
                    }
#ifdef __VRE__
                    }
#endif
                    /* call draw image callback function */
                    if (cat214_draw_image_callback != NULL)
                    {
                        cat214_draw_image_callback(
                            index,
                            cur_page_index,
#ifdef __VRE__
                            cur_page_last_index,
#else
                            cur_page_index + item_per_page - 1,
#endif
                            is_hilighted,
                            FALSE,  /* not need update */
                            FALSE,  /* not new page */
                            box_offset_x,
                            box_offset_y,
                            box_offset_x + box_width - 1,
                            box_offset_y + box_height - 1);

                    }
                }

            }
        }
    }

    gdi_layer_pop_clip();
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}
/* Vogins End */

/*****************************************************************************
 * FUNCTION
 *  GetCategory214BoxSize
 * DESCRIPTION
 *  Get 214 box size
 * PARAMETERS
 *  num_per_row         [IN]        N     number per row
 *  num_per_col         [IN]        Number per column
 *  box_width_ptr       [OUT]       Box width ptr
 *  box_height_ptr      [OUT]       Box height ptr
 * RETURNS
 *  void
 *****************************************************************************/
void GetCategory214BoxSize(S32 num_per_row, S32 num_per_col, S32 *box_width_ptr, S32 *box_height_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *box_width_ptr = MMI_content_height - CAT214_OUTSIDE_SPACING * 2 - CAT214_INSIDE_SPACING * (num_per_col - 1);
    *box_width_ptr /= num_per_col;

    *box_height_ptr = MMI_content_height - CAT214_OUTSIDE_SPACING * 2 - CAT214_INSIDE_SPACING * (num_per_row - 1);
    *box_height_ptr /= num_per_row;
}


/*****************************************************************************
 * FUNCTION
 *  Cat214KeyUpHdlr
 * DESCRIPTION
 *  Category 214 key up handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat214KeyUpHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 moved_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cat214_item_count == 0)
    {
        return;
    }

    cat214_prev_hilighted_index = cat214_hilighted_index;
    moved_index = cat214_hilighted_index - cat214_num_per_col;

    /* move to last if needed */
    if (moved_index < 0)
    {
        S32 last_line_items, cur_line_offset;
        
        last_line_items = cat214_item_count%cat214_num_per_col;
        cur_line_offset = (cat214_prev_hilighted_index + 1)%cat214_num_per_col;
        if (cur_line_offset == 0)
        {
/* Vogins Start */
        #ifdef __VRE_V30__
            cur_line_offset = cat214_num_per_col;
        #else
            cur_line_offset = 3;
        #endif
        }
        if (last_line_items == 0)
        {
        #ifdef __VRE_V30__
            last_line_items = cat214_num_per_col;
        #else
            last_line_items = 3;
        #endif
/* Vogins End */
        }
        
        if ((cat214_item_count - last_line_items + cur_line_offset) > cat214_item_count)
        {
            cat214_hilighted_index = cat214_item_count - 1;
        }
        else
        {
            cat214_hilighted_index = cat214_item_count - last_line_items + (cat214_prev_hilighted_index%cat214_num_per_col);
        }
    }
    else
    {
        cat214_hilighted_index = (U16) moved_index;
    }

    MMI_menu_shortcut_number = cat214_hilighted_index + 1;

    /* assign to fixed list menu - for history */
    MMI_fixed_list_menu.highlighted_item = cat214_hilighted_index;

    /* call hilight handler callback */
    if (MMI_list_highlight_handler != NULL)
    {
        MMI_list_highlight_handler(cat214_hilighted_index);
    }

    /* hide image callback */
    if (cat214_hide_image_callback != NULL)
    {
        cat214_hide_image_callback(cat214_prev_hilighted_index);
    }

    gdi_layer_lock_frame_buffer();
    draw_title();
    Cat214RedrawMatrix();
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

}


/*****************************************************************************
 * FUNCTION
 *  Cat214KeyDownHdlr
 * DESCRIPTION
 *  Category 214 key down handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat214KeyDownHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 moved_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cat214_item_count == 0)
    {
        return;
    }

    cat214_prev_hilighted_index = cat214_hilighted_index;
    moved_index = cat214_hilighted_index + cat214_num_per_col;
    
    /* move to first if needed */
    if (moved_index >= cat214_item_count)
    {
        if (((cat214_hilighted_index)%(cat214_num_per_col*cat214_num_per_row))>(cat214_num_per_col*cat214_num_per_row - cat214_num_per_col -1)
            && ((cat214_item_count-1)%(cat214_num_per_col*cat214_num_per_row))<(cat214_num_per_col*cat214_num_per_row - cat214_num_per_col - 1))
            cat214_hilighted_index = cat214_item_count - 1;
        else
            cat214_hilighted_index = (cat214_prev_hilighted_index%cat214_num_per_col);
    }
    else
    {
        cat214_hilighted_index = (U16) moved_index;
    }

    MMI_menu_shortcut_number = cat214_hilighted_index + 1;

    /* assign to fixed list menu - for history */
    MMI_fixed_list_menu.highlighted_item = cat214_hilighted_index;

    /* call hilight handler callback */
    if (MMI_list_highlight_handler != NULL)
    {
        MMI_list_highlight_handler(cat214_hilighted_index);
    }

    /* hide image callback */
    if (cat214_hide_image_callback != NULL)
    {
        cat214_hide_image_callback(cat214_prev_hilighted_index);
    }

    gdi_layer_lock_frame_buffer();
    draw_title();
    Cat214RedrawMatrix();
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  Cat214KeyLeftHdlr
 * DESCRIPTION
 *  Category 214 key left handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat214KeyLeftHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 moved_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cat214_item_count == 0)
    {
        return;
    }

    cat214_prev_hilighted_index = cat214_hilighted_index;
    moved_index = cat214_hilighted_index - 1;

    /* move to last if needed */
    if (moved_index < 0)
    {
        cat214_hilighted_index = cat214_item_count - 1;
    }
    else
    {
        cat214_hilighted_index = (U16) moved_index;
    }

    MMI_menu_shortcut_number = cat214_hilighted_index + 1;

    /* assign to fixed list menu - for history */
    MMI_fixed_list_menu.highlighted_item = cat214_hilighted_index;

    /* call hilight handler callback */
    if (MMI_list_highlight_handler != NULL)
    {
        MMI_list_highlight_handler(cat214_hilighted_index);
    }

    /* hide image callback */
    if (cat214_hide_image_callback != NULL)
    {
        cat214_hide_image_callback(cat214_prev_hilighted_index);
    }

    gdi_layer_lock_frame_buffer();
    draw_title();
    Cat214RedrawMatrix();
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  Cat214KeyRightHdlr
 * DESCRIPTION
 *  Category 214 key right handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat214KeyRightHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 moved_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cat214_item_count == 0)
    {
        return;
    }

    cat214_prev_hilighted_index = cat214_hilighted_index;
    moved_index = cat214_hilighted_index + 1;

    /* move to first if needed */
    if (moved_index >= cat214_item_count)
    {
        cat214_hilighted_index = 0;
    }
    else
    {
        cat214_hilighted_index = (U16) moved_index;
    }

    MMI_menu_shortcut_number = cat214_hilighted_index + 1;

    /* assign to fixed list menu - for history */
    MMI_fixed_list_menu.highlighted_item = cat214_hilighted_index;

    /* call hilight handler callback */
    if (MMI_list_highlight_handler != NULL)
    {
        MMI_list_highlight_handler(cat214_hilighted_index);
    }

    /* hide image callback */
    if (cat214_hide_image_callback != NULL)
    {
        cat214_hide_image_callback(cat214_prev_hilighted_index);
    }

    gdi_layer_lock_frame_buffer();
    draw_title();
    Cat214RedrawMatrix();
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  Cat214ShortCutHdlr
 * DESCRIPTION
 *  Category 214 shot cut key press handler
 * PARAMETERS
 *  item_index      [IN]        Item index
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat214ShortCutHdlr(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cat214_item_count == 0)
    {
        return;
    }

    if (item_index < cat214_item_count)
    {
        cat214_prev_hilighted_index = cat214_hilighted_index;
        cat214_hilighted_index = (U16) item_index;
    }

    MMI_menu_shortcut_number = cat214_hilighted_index + 1;

    /* assign to fixed list menu - for history */
    MMI_fixed_list_menu.highlighted_item = cat214_hilighted_index;

    /* call hilight handler callback */
    if (MMI_list_highlight_handler != NULL)
    {
        MMI_list_highlight_handler(cat214_hilighted_index);
    }

    /* hide image callback */
    if (cat214_hide_image_callback != NULL)
    {
        cat214_hide_image_callback(cat214_prev_hilighted_index);
    }

    gdi_layer_lock_frame_buffer();
    draw_title();
    Cat214RedrawMatrix();
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  DrawCate214CategoryControlArea
 * DESCRIPTION
 *  Draw category 214 control area
 * PARAMETERS
 *  coordinate      [IN]        Cooridinate
 * RETURNS
 *  void
 *****************************************************************************/
static void DrawCate214CategoryControlArea(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;
    S32 str_width;
    S32 str_height;
    S8 *str_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clear background */
    if (r2lMMIFlag)
    {
        gdi_draw_solid_rect(
            current_MMI_theme->scrollbar_size,
            MMI_SUBMENU_CONTENT_Y,
            UI_device_width - 1,
            (MMI_SUBMENU_CONTENT_Y) + MMI_content_height - 1,
            GDI_COLOR_TRANSPARENT);

    }
    else
    {
        gdi_draw_solid_rect(
            0,
            MMI_SUBMENU_CONTENT_Y,
            UI_device_width - current_MMI_theme->scrollbar_size - 1,
            (MMI_SUBMENU_CONTENT_Y) + MMI_content_height - 1,
            GDI_COLOR_TRANSPARENT);
    }

    Cat214RedrawMatrix();

    /* if is emtpty folder, show a empty string */
    if (cat214_item_count == 0)
    {
        gui_reset_clip();
        gui_set_font(&MMI_medium_font);
        //gui_set_text_color(gui_color(0, 0, 0));
        gui_set_text_color(*current_MMI_theme->list_normal_text_color);

#if defined(__MMI_FILE_MANAGER__)
        str_ptr = GetString(STR_ID_FMGR_EMPTY_FOLDER);
#else /* defined(__MMI_FILE_MANAGER__) */
        str_ptr = GetString(STR_GLOBAL_EMPTY_LIST);
#endif /* defined(__MMI_FILE_MANAGER__) */

        gui_measure_string((UI_string_type) str_ptr, &str_width, &str_height);
        offset_x = (UI_device_width - str_width) >> 1;
        offset_y = (UI_device_height - str_height) >> 1;

        if (r2lMMIFlag)
        {
            gui_move_text_cursor(offset_x + str_width, offset_y);
        }
        else
        {
            gui_move_text_cursor(offset_x, offset_y);
        }

        gui_print_text((UI_string_type) str_ptr);
    }

}


/*****************************************************************************
 * FUNCTION
 *  Cat214CategoryControlAreaPenDownHdlr
 * DESCRIPTION
 *  Cat 214 pen down hdlr
 * PARAMETERS
 *  pos     [IN]        Position
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_TOUCH_SCREEN__)
static MMI_BOOL Cat214CategoryControlAreaPenDownHdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 content_offset_x;
    S32 content_offset_y;
    S32 content_width;
    S32 content_height;
    S32 image_offset_x;
    S32 image_offset_y;
    S32 image_width;
    S32 image_height;
    S32 i, j;
    S32 index;
    S32 cur_page_index;
    BOOL is_redraw_all;
    S32 item_per_page;
    gui_scrollbar_pen_enum scrollbar_event;
    gui_pen_event_param_struct scrollbar_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* prepare parameters */
    if (r2lMMIFlag)
    {
        content_offset_x = current_MMI_theme->scrollbar_size;
    }
    else
    {
        content_offset_x = 0;
    }

    item_per_page = cat214_num_per_row * cat214_num_per_col;

    cat214_pen_down_on_scroll = FALSE;

    /* Scroll bar */
    if (gui_vertical_scrollbar_translate_pen_event(
            &MMI_fixed_list_menu.vbar,
            MMI_PEN_EVENT_DOWN,
            pos.x,
            pos.y,
            &scrollbar_event,
            &scrollbar_param))
    {
        cat214_pen_down_on_scroll = TRUE;

        if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
        {
            index = cat214_hilighted_index + ((scrollbar_param._u.i) * item_per_page - cat214_page_index);

            if (index >= cat214_item_count)
            {
                index = cat214_item_count - 1;
            }

            Cat214ShortCutHdlr(index);
        }
        return MMI_TRUE;
    }

    /* image matrix */
    content_width = UI_device_width - current_MMI_theme->scrollbar_size;
    content_offset_y = MMI_SUBMENU_CONTENT_Y;
    content_height = MMI_content_height;

    image_width = content_width - CAT214_OUTSIDE_SPACING * 2 - CAT214_INSIDE_SPACING * (cat214_num_per_col - 1);
    image_width /= cat214_num_per_col;

    image_height = content_height - CAT214_OUTSIDE_SPACING * 2 - CAT214_INSIDE_SPACING * (cat214_num_per_row - 1);
    image_height /= cat214_num_per_row;

    item_per_page = cat214_num_per_row * cat214_num_per_col;
    cur_page_index = (cat214_hilighted_index / item_per_page) * item_per_page;

    /* page changed, redraw whole page */
    is_redraw_all = (cur_page_index != cat214_page_index) ? TRUE : FALSE;
    cat214_page_index = (U16) cur_page_index;

    for (i = 0; i < cat214_num_per_row; i++)
    {
        for (j = 0; j < cat214_num_per_col; j++)
        {
            index = (cat214_page_index) + i * cat214_num_per_col + j;

            if (index < cat214_item_count)  /* within valid index range */
            {
                image_offset_x =
                    image_width * j + CAT214_OUTSIDE_SPACING + CAT214_INSIDE_SPACING * j + content_offset_x;
                image_offset_y =
                    image_height * i + CAT214_OUTSIDE_SPACING + CAT214_INSIDE_SPACING * i + content_offset_y;
                if (pos.x >= image_offset_x && pos.x < image_offset_x + image_width && pos.y >= image_offset_y &&
                    pos.y < image_offset_y + image_height)
                {
                    Cat214ShortCutHdlr(index);
                    cat214_pen_down_index = index;
                    return MMI_TRUE;
                }
            }
        }
    }

    cat214_pen_down_index = -1;
    return MMI_FALSE;
}
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 


/*****************************************************************************
 * FUNCTION
 *  Cat214CategoryControlAreaPenMoveHdlr
 * DESCRIPTION
 *  Cat 214 pen move hdlr
 * PARAMETERS
 *  pos     [IN]        Position
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_TOUCH_SCREEN__)
static MMI_BOOL Cat214CategoryControlAreaPenMoveHdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 content_offset_x;
    S32 content_offset_y;
    S32 content_width;
    S32 content_height;
    S32 image_offset_x;
    S32 image_offset_y;
    S32 image_width;
    S32 image_height;
    S32 i, j;
    S32 index;
    S32 cur_page_index;
    BOOL is_redraw_all;
    S32 item_per_page;
    gui_scrollbar_pen_enum scrollbar_event;
    gui_pen_event_param_struct scrollbar_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* prepare parameters */
    if (r2lMMIFlag)
    {
        content_offset_x = current_MMI_theme->scrollbar_size;
    }
    else
    {
        content_offset_x = 0;
    }

    item_per_page = cat214_num_per_row * cat214_num_per_col;

    if (cat214_pen_down_on_scroll)
    {
        /* Scroll bar */
        if (gui_vertical_scrollbar_translate_pen_event(
                &MMI_fixed_list_menu.vbar,
                MMI_PEN_EVENT_MOVE,
                pos.x,
                pos.y,
                &scrollbar_event,
                &scrollbar_param))
        {
            if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
            {
                index = cat214_hilighted_index + ((scrollbar_param._u.i) * item_per_page - cat214_page_index);

                if (index >= cat214_item_count)
                {
                    index = cat214_item_count - 1;
                }

                Cat214ShortCutHdlr(index);
            }
        }
        return MMI_TRUE;
    }

    /* image matrix */
    content_width = UI_device_width - current_MMI_theme->scrollbar_size;
    content_offset_y = MMI_SUBMENU_CONTENT_Y;
    content_height = MMI_content_height;

    image_width = content_width - CAT214_OUTSIDE_SPACING * 2 - CAT214_INSIDE_SPACING * (cat214_num_per_col - 1);
    image_width /= cat214_num_per_col;

    image_height = content_height - CAT214_OUTSIDE_SPACING * 2 - CAT214_INSIDE_SPACING * (cat214_num_per_row - 1);
    image_height /= cat214_num_per_row;

    item_per_page = cat214_num_per_row * cat214_num_per_col;
    cur_page_index = (cat214_hilighted_index / item_per_page) * item_per_page;

    /* page changed, redraw whole page */
    is_redraw_all = (cur_page_index != cat214_page_index) ? TRUE : FALSE;
    cat214_page_index = (U16) cur_page_index;

    for (i = 0; i < cat214_num_per_row; i++)
    {
        for (j = 0; j < cat214_num_per_col; j++)
        {
            index = (cat214_page_index) + i * cat214_num_per_col + j;

            if (index < cat214_item_count)  /* within valid index range */
            {
                image_offset_x =
                    image_width * j + CAT214_OUTSIDE_SPACING + CAT214_INSIDE_SPACING * j + content_offset_x;
                image_offset_y =
                    image_height * i + CAT214_OUTSIDE_SPACING + CAT214_INSIDE_SPACING * i + content_offset_y;
                if (pos.x >= image_offset_x && pos.x < image_offset_x + image_width && pos.y >= image_offset_y &&
                    pos.y < image_offset_y + image_height)
                {
                    Cat214ShortCutHdlr(index);
                    return MMI_TRUE;
                }
            }
        }
    }
    return MMI_FALSE;
}
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 


/*****************************************************************************
 * FUNCTION
 *  Cat214CategoryControlAreaPenUpHdlr
 * DESCRIPTION
 *  Cat 214 pen down hdlr
 * PARAMETERS
 *  pos     [IN]        Position
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_TOUCH_SCREEN__)
static MMI_BOOL Cat214CategoryControlAreaPenUpHdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 content_offset_x;
    S32 content_offset_y;
    S32 content_width;
    S32 content_height;
    S32 image_offset_x;
    S32 image_offset_y;
    S32 image_width;
    S32 image_height;
    S32 i, j;
    S32 index;
    S32 cur_page_index;
    S32 item_per_page;
    gui_scrollbar_pen_enum scrollbar_event;
    gui_pen_event_param_struct scrollbar_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* prepare parameters */
    if (r2lMMIFlag)
    {
        content_offset_x = current_MMI_theme->scrollbar_size;
    }
    else
    {
        content_offset_x = 0;
    }

    item_per_page = cat214_num_per_row * cat214_num_per_col;

    if (cat214_pen_down_on_scroll)
    {
        if (gui_vertical_scrollbar_translate_pen_event(
                &MMI_fixed_list_menu.vbar,
                MMI_PEN_EVENT_UP,
                pos.x,
                pos.y,
                &scrollbar_event,
                &scrollbar_param))

        {
            cat214_pen_down_on_scroll = FALSE;
        }
        if (scrollbar_event == GUI_SCROLLBAR_PEN_JUMP_TO_I)
        {
            index = cat214_hilighted_index + ((scrollbar_param._u.i) * item_per_page - cat214_page_index);

            if (index >= cat214_item_count)
            {
                index = cat214_item_count - 1;
            }

            Cat214ShortCutHdlr(index);
        }

        return MMI_TRUE;
    }

    /* image matrix */
    content_width = UI_device_width - current_MMI_theme->scrollbar_size;
    content_offset_y = MMI_SUBMENU_CONTENT_Y;
    content_height = MMI_content_height;

    image_width = content_width - CAT214_OUTSIDE_SPACING * 2 - CAT214_INSIDE_SPACING * (cat214_num_per_col - 1);
    image_width /= cat214_num_per_col;

    image_height = content_height - CAT214_OUTSIDE_SPACING * 2 - CAT214_INSIDE_SPACING * (cat214_num_per_row - 1);
    image_height /= cat214_num_per_row;

    item_per_page = cat214_num_per_row * cat214_num_per_col;
    cur_page_index = (cat214_hilighted_index / item_per_page) * item_per_page;

    cat214_page_index = (U16) cur_page_index;

    for (i = 0; i < cat214_num_per_row; i++)
    {
        for (j = 0; j < cat214_num_per_col; j++)
        {
            index = (cat214_page_index) + i * cat214_num_per_col + j;

            if (index < cat214_item_count)  /* within valid index range */
            {
                image_offset_x =
                    image_width * j + CAT214_OUTSIDE_SPACING + CAT214_INSIDE_SPACING * j + content_offset_x;
                image_offset_y =
                    image_height * i + CAT214_OUTSIDE_SPACING + CAT214_INSIDE_SPACING * i + content_offset_y;
                if (pos.x >= image_offset_x && pos.x < image_offset_x + image_width && pos.y >= image_offset_y &&
                    pos.y < image_offset_y + image_height)
                {
                    if (cat214_pen_down_index == index)
                    {
                        execute_softkey_function(KEY_EVENT_UP, MMI_LEFT_SOFTKEY);
                    }

                    cat214_pen_down_index = -1;
                    return MMI_TRUE;
                }
            }
        }
    }
    return MMI_FALSE;
}

#endif /* defined(__MMI_TOUCH_SCREEN__) */ 


/*************************************************File manager Function********************************************************/
/*****************************************************************************
 * FUNCTION
 *  wgui_fmgr_draw_hilight_menuitem_bg
 * DESCRIPTION
 *  call back function for draw hilight menuitem, used by scrolling text
 * PARAMETERS
 *  x1      [IN]        X1
 *  y1      [IN]        Y1
 *  x2      [IN]        X2
 *  y2      [IN]        Y2
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_fmgr_draw_hilight_menuitem_bg(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if background decoding finish: yes then start to scroll */
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
    gui_draw_filled_area(
        GUI_current_fixed_icontext_menuitem_x,
        GUI_current_fixed_icontext_menuitem_y,
        x2,
        y2,
        MMI_fixed_icontext_menuitem.selected_filler);
    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_fmgr_draw_hilight_menuitem_bg_callback
 * DESCRIPTION
 *  call back function for draw hilight menuitem, used by scrolling text
 * PARAMETERS
 *  x1      [IN]        X1
 *  y1      [IN]        Y1
 *  x2      [IN]        X2
 *  y2      [IN]        Y2
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_fmgr_draw_hilight_menuitem_bg_callback(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if background decoding finish: yes then start to scroll */
#if defined(FMGR_USING_CACHE)
    if (fmgr_cat_context.decoding_count == 0)
#endif
    {
        gui_push_clip();
        gui_set_clip(x1, y1, x2, y2);
        gui_draw_filled_area(
            GUI_current_fixed_icontext_menuitem_x,
            GUI_current_fixed_icontext_menuitem_y,
            x2,
            y2,
            MMI_fixed_icontext_menuitem.selected_filler);
        gui_pop_clip();
    }
}




/*****************************************************************************
 * FUNCTION
 *  wgui_fmgr_draw_hilight_menuitem_timer_callback
 * DESCRIPTION
 *  draw hilight menuitem text, callback function for scrolling text
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_fmgr_draw_hilight_menuitem_timer_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(FMGR_USING_CACHE)
    /* check if background decoding finish: yes then start to scroll */
    if (fmgr_cat_context.decoding_count == 0)
        gui_handle_scrolling_text(&fmgr_cat_context.scroll_text);
    else
        gui_start_timer(350, wgui_fmgr_draw_hilight_menuitem_timer_callback);
#else
    gui_handle_scrolling_text(&fmgr_cat_context.scroll_text);
#endif
}


static void wgui_fmgr_redraw_image_background(BOOL is_hilighted, U16 ui_style, 
                                             gdi_color bg_color, S32 x1, S32 y1, S32 x2, S32 y2)
{
    if (is_hilighted && (ui_style == MMI_FMGR_GUI_LIST_STYLE))
    {   /* support image highlight only in the list style */
        wgui_fmgr_draw_hilight_menuitem_bg(x1, y1, x2, y2);
    }
    else if (ui_style == MMI_FMGR_GUI_LIST_STYLE)
    {
        gdi_draw_solid_rect(x1, y1, x2, y2, bg_color);
    }
    else if (ui_style == MMI_FMGR_GUI_MATRIX_STYLE)
    {
#ifdef __MMI_MAINLCD_128X128__
        gdi_draw_solid_rect(x1, y1, x2, y2, bg_color);
#else
        FillFullTextBackground(x1, y1, x2, y2);
#endif
    }
    else
    {
#ifdef __MMI_MAINLCD_128X128__
        gdi_draw_solid_rect(x1, y1, x2, y2, bg_color);
#else
        FillFullTextBackground(x1, y1, x2, y2);
#endif
        
    }
}

static gdi_color wgui_fmgr_get_bg_color(BOOL is_hilighted, U16 ui_style)
{
    gdi_color bg_color = GDI_COLOR_BLACK;
    color *color_ptr;
    
    if (ui_style == MMI_FMGR_GUI_LIST_STYLE)
    {
        /* get color from theme */
        if (is_hilighted)
        {
            color_ptr = &(current_MMI_theme->list_selected_item_filler->c);
            bg_color = gdi_act_color_from_rgb(255,color_ptr->r, color_ptr->g, color_ptr->b);
        }
        else
        {
#if defined(__MMI_WALLPAPER_ON_BOTTOM__) || defined(__MMI_UI_LIST_CACHE_BACKGROUND__)
            bg_color = GDI_COLOR_TRANSPARENT;
#else /* defined(__MMI_WALLPAPER_ON_BOTTOM__) || defined(__MMI_UI_LIST_CACHE_BACKGROUND__) */ /* __MMI_MAINLCD_240X320__ */
            color_ptr = &(current_MMI_theme->list_background_filler->c);
            bg_color = gdi_act_color_from_rgb(255,color_ptr->r, color_ptr->g, color_ptr->b);
#endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) || defined(__MMI_UI_LIST_CACHE_BACKGROUND__) */ /* __MMI_MAINLCD_240X320__ */
        }
    }
    else if (ui_style == MMI_FMGR_GUI_INFO_STYLE)
    {
        /* this bg color is the same in wgui_categories_fmgr.c's RedrawCategory212Screen() */
        bg_color = gdi_act_color_from_rgb(255,255, 255, 255);
    }
    else if (ui_style == MMI_FMGR_GUI_MATRIX_STYLE)
    {
        if (is_hilighted)
        {
            color_ptr = &(current_MMI_theme->list_selected_item_filler->c);
            bg_color = gdi_act_color_from_rgb(255,color_ptr->r, color_ptr->g, color_ptr->b);
        }
        else
        {
            color_ptr = &(current_MMI_theme->list_background_filler->c);
            bg_color = gdi_act_color_from_rgb(255,color_ptr->r, color_ptr->g, color_ptr->b);
        }
    }
    
    return bg_color;
}




void wgui_cat21x_register_set_displayable(wgui_fmgr_set_displayable_func set_displayable)
{
#if defined(FMGR_USING_CACHE)    
    wgui_cat21x_set_displayable = set_displayable;
#endif /* defined(FMGR_USING_CACHE) */ 
}

void wgui_cat21x_register_get_displayable(wgui_fmgr_get_displayable_func get_displayable)
{
#if defined(FMGR_USING_CACHE)    
    wgui_cat21x_get_displayable = get_displayable;
#endif /* defined(FMGR_USING_CACHE) */ 
}

void wgui_cat21x_register_get_thumb_image(wgui_fmgr_get_thumb_image_func get_thumb_image)
{
#if defined(FMGR_USING_CACHE)
    wgui_cat21x_get_image_path_callback = get_thumb_image;
#endif /* defined(FMGR_USING_CACHE) */ 
}

void wgui_cat212_fmgr_hide_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(FMGR_USING_CACHE)
    S32 i;
    gdi_color bg_color = GDI_COLOR_BLACK;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_cat212_fmgr_hide_data_info_ptr();

#if defined(FMGR_USING_CACHE)
    for (i = 0; i < FMGR_THUMB_IMAGE_HANDLE_MAX_COUNT; i++)
    {
        if ((fmgr_image_cache_p->image_handle_list[i]->is_hilighted == TRUE) && 
            (fmgr_image_cache_p->image_handle_list[i]->is_used == TRUE))
        {
            bg_color = wgui_fmgr_get_bg_color(
                fmgr_image_cache_p->image_handle_list[i]->is_hilighted, 
                fmgr_image_cache_p->image_handle_list[i]->ui_style);
            
            wgui_fmgr_redraw_image_background(                
                fmgr_image_cache_p->image_handle_list[i]->is_hilighted, 
                fmgr_image_cache_p->image_handle_list[i]->ui_style,
                bg_color,
                fmgr_image_cache_p->image_handle_list[i]->draw_pos_x,
                fmgr_image_cache_p->image_handle_list[i]->draw_pos_y,
                fmgr_image_cache_p->image_handle_list[i]->draw_pos_x + fmgr_image_cache_p->image_handle_list[i]->resized_width,
                fmgr_image_cache_p->image_handle_list[i]->draw_pos_y + fmgr_image_cache_p->image_handle_list[i]->resized_height); 
            
            gdi_image_draw(fmgr_image_cache_p->image_handle_list[i]->icon_offset_x,
                fmgr_image_cache_p->image_handle_list[i]->icon_offset_y,
                fmgr_image_cache_p->image_handle_list[i]->icon_ptr);   
            break;
        }
    }

    /* stop all decoding jpeg files */
    gdi_image_decoder_stop_all();

    /* reset delay decoder */
    fmgr_cat_context.delay_decode_index = 0;

    if(fmgr_cat_context.decoding_count>0)
    {
        fmgr_cat_context.decoding_count=0;
        //wgui_status_icon_unlock_redrawing();
    }

    StopTimer(FMGR_DELAY_DECODE_0);
    StopTimer(FMGR_DELAY_DECODE_1);
    StopTimer(FMGR_DELAY_DECODE_2);
    StopTimer(FMGR_DELAY_DECODE_3);
    StopTimer(FMGR_DELAY_DECODE_4);
    StopTimer(FMGR_DELAY_DECODE_5);
    StopTimer(FMGR_DELAY_DECODE_6);
    StopTimer(FMGR_DELAY_DECODE_7);
    StopTimer(FMGR_DELAY_DECODE_8);
    StopTimer(FMGR_DELAY_DECODE_9);

    /* clear image cache handle entries */
    for (i = 0; i < FMGR_THUMB_IMAGE_HANDLE_MAX_COUNT; i++)
    {
        fmgr_image_cache_p->image_handle_list[i]->is_used = FALSE;
    }

    /* free jpeg decoder */
    if (fmgr_cat_context.is_decoder_create)
    {
        gdi_image_decoder_free();
        fmgr_cat_context.is_decoder_create = FALSE;
    }

#endif /* defined(FMGR_USING_CACHE) */ 

    /* stop all animations */
    /* gdi_image_stop_animation_all(); */
    
}


void wgui_cat212_fmgr_draw_info(S32 item_idx, S32 x1, S32 y1, S32 x2, S32 y2)
{
    S32 image_width;
    S32 image_height;
    S32 char_height;
    S32 str_width, str_height;
    S32 box_width = 0, box_height = 0;
    S32 box_offset_x = 0, box_offset_y = 0;
   
    S32 spacing;
    S32 line1_size_str_offset_y = 0;
    S32 line2_size_str_offset_y = 0;
    S32 line1_size_offset_y = 0;
    S32 line2_size_offset_y = 0;
    S32 left_align_offset_x = 0;
    S32 right_align_offset_x = 0;    

    wgui_fmgr_info_struct fmgr_info;

    memset(&fmgr_info, 0, sizeof(wgui_fmgr_info_struct));
    wgui_cat212_fmgr_get_info_ptr(item_idx, &fmgr_info);

    /* lock and push clip */
    gui_lock_double_buffer();
    gui_push_text_clip();
    gui_push_clip();
    
    gui_reset_clip();
    gui_reset_text_clip();

    if (fmgr_info.info_type == WGUI_CAT21X_INFO_TYPE_DRV)
    {
        /*----------------------------------------------------------------*/
        /* Calcuate text position                                         */
        /*----------------------------------------------------------------*/
        box_height = y2 - y1 + 1;
        box_width = x2 - x1 + 1;

        gui_set_font(&MMI_medium_font);

        spacing = box_height;
        gui_measure_string((UI_string_type) GetString(STR_ID_FMGR_DRV_FREE_SPACE), &str_width, &char_height);
        spacing -= char_height;
        gui_measure_string((UI_string_type) GetString(STR_ID_FMGR_DRV_TOTAL_SPACE), &str_width, &char_height);
        spacing -= char_height;
        if(spacing < 0)
            spacing = 0;
        str_height = spacing % 3;
        spacing = spacing / 3;

        line1_size_str_offset_y = str_height + spacing + MMI_title_height + MMI_title_y;
        line2_size_str_offset_y = str_height + spacing * 2 + char_height + MMI_title_height + MMI_title_y;

        char_height = gui_get_string_height((UI_string_type) L"1");
        str_height = (box_height - char_height * 2) % 3;
        spacing = (box_height - char_height * 2) / 3;

        line1_size_offset_y = str_height + spacing + MMI_title_height + MMI_title_y;
        line2_size_offset_y = str_height + spacing * 2 + char_height + MMI_title_height + MMI_title_y;

        
#if 0      
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if !defined(__MMI_SLIM_FILE_MANAGER__)
        gdi_image_get_dimension(fmgr_info.file_icon_ptr, &image_width, &image_height);

        left_align_offset_x = x1 + image_width + 8;
        right_align_offset_x = x2 - image_width - 8;
#else /* !defined(__MMI_SLIM_FILE_MANAGER__) */ 
        left_align_offset_x = x1 + box_height + 8;
        right_align_offset_x = x2 - box_height - 8;
#endif /* !defined(__MMI_SLIM_FILE_MANAGER__) */     
    }
    else if (fmgr_info.info_type == WGUI_CAT21X_INFO_TYPE_FILE)
    {
        /*-------------------------*/
        /* Calculate text position */
        /*-------------------------*/
        box_height = y2 - y1 - FMGR_UI_IMAGE_BOX_SPACING * 2 + 1;
        box_width = box_height;

        box_offset_y = FMGR_UI_IMAGE_BOX_SPACING;

        if (r2lMMIFlag)
        {
            box_offset_x = x2 - box_width - FMGR_UI_IMAGE_BOX_SPACING;
        }
        else
        {
            box_offset_x = FMGR_UI_IMAGE_BOX_SPACING;
        }

        gui_set_text_color(gui_color(0, 0, 0));
        gui_set_font(&MMI_medium_font);

        char_height = gui_get_string_height((UI_string_type) GetString(STR_ID_FMGR_FILE_DATE));
        spacing = (y2 - y1 - 1 - char_height * 2) / 3;

        line1_size_str_offset_y = spacing + MMI_title_height + MMI_title_y + 1;   /* +1 make it looks better */
        line2_size_str_offset_y = spacing * 2 + char_height + MMI_title_height + MMI_title_y + 1; /* +1 make it looks better */

        char_height = gui_get_string_height((UI_string_type) L"1");
        spacing = (y2 - y1 - 1 - char_height * 2) / 3;

        line1_size_offset_y = spacing + MMI_title_height + MMI_title_y + 1;       /* +1 make it looks better */
        line2_size_offset_y = spacing * 2 + char_height + MMI_title_height + MMI_title_y + 1;     /* +1 make it looks better */

        left_align_offset_x = x1 + box_width + FMGR_UI_TEXT_SPACING;
        right_align_offset_x = x2 - box_width - FMGR_UI_TEXT_SPACING;
    }
    else
    {
        ASSERT(0);
    }

    /*----------------------------------------------------------------*/
    /* Draw Total Size                                                */
    /*----------------------------------------------------------------*/
    if (fmgr_info.info_text_l1_s1 != NULL)
    {
        gui_reset_text_clip();
        gui_set_text_color(gui_color(0, 0, 0));

        if (r2lMMIFlag)
        {
            gui_move_text_cursor(right_align_offset_x, line1_size_str_offset_y);
        }
        else
        {
            gui_move_text_cursor(left_align_offset_x, line1_size_str_offset_y);
        }
        gui_print_text(fmgr_info.info_text_l1_s1);

        gui_measure_string(fmgr_info.info_text_l1_s2, &str_width, &str_height);
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(x1 + str_width + 2, line1_size_offset_y);
        }
        else
        {
            gui_move_text_cursor(x2 - str_width - 2, line1_size_offset_y);
        }
        gui_print_text(fmgr_info.info_text_l1_s2);

    }


    /*----------------------------------------------------------------*/
    /* Draw Free Size                                                 */
    /*----------------------------------------------------------------*/
    if (fmgr_info.info_text_l2_s1 != NULL)
    {
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(right_align_offset_x, line2_size_str_offset_y);
        }
        else
        {
            gui_move_text_cursor(left_align_offset_x, line2_size_str_offset_y);
        }
        gui_print_text(fmgr_info.info_text_l2_s1);


        gui_measure_string((UI_string_type) fmgr_info.info_text_l2_s2, &str_width, &str_height);
        if (r2lMMIFlag)
        {
            gui_move_text_cursor(x1 + str_width + 2, line2_size_offset_y);
        }
        else
        {
            gui_move_text_cursor(x2 - str_width - 2, line2_size_offset_y);
        }
        gui_print_text(fmgr_info.info_text_l2_s2);
    }
    
    /*----------------------------------------------------------------*/
    /* Draw Icon                                                      */
    /*----------------------------------------------------------------*/
    if (fmgr_info.info_type == WGUI_CAT21X_INFO_TYPE_FILE && fmgr_info.is_show_thumb == MMI_TRUE)
    {
        /* type is file, and thumb image is right. */
        wgui_fmgr_show_thumb_image(
            item_idx,
            x1,
            y1,
            box_offset_x,
            box_offset_y,
            box_height,
            box_height,
            fmgr_info.file_icon_ptr,
            TRUE,
            MMI_FMGR_GUI_INFO_STYLE);        
    }
    else
    {
        if (fmgr_info.info_type == WGUI_CAT21X_INFO_TYPE_DRV)
        {
            if (r2lMMIFlag)
            {
                wgui_fmgr_draw_free_space_icon(right_align_offset_x + 4, y1, box_height, fmgr_info.drv_ratio, fmgr_info.file_icon_ptr);
            }
            else
            {
                wgui_fmgr_draw_free_space_icon(x1 + 4, y1, box_height, fmgr_info.drv_ratio, fmgr_info.file_icon_ptr);
            }
        }
        else if (fmgr_info.info_type == WGUI_CAT21X_INFO_TYPE_FILE)
        {
            S32 icon_offset_x, icon_offset_y;

            gui_measure_image(fmgr_info.file_icon_ptr, &image_width, &image_height);
            icon_offset_x = ((box_width - image_width) >> 1) + x1 + box_offset_x;
            icon_offset_y = ((box_height - image_height) >> 1) + y1 + box_offset_y;
            gdi_image_draw(icon_offset_x, icon_offset_y, fmgr_info.file_icon_ptr);
        }
    }

    /* pop clip , unlock and blt */
    gui_pop_clip();
    gui_pop_text_clip();
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
}



void wgui_cat213_fmgr_hide_menuitem(void)
{
   /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(FMGR_USING_CACHE)
    S32 i;
    gdi_color bg_color = GDI_COLOR_BLACK;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop scroll text */
    gui_scrolling_text_stop(&fmgr_cat_context.scroll_text);


#if defined(FMGR_USING_CACHE)
    /* clear image cache handle entries */
    for (i = 0; i < FMGR_THUMB_IMAGE_HANDLE_MAX_COUNT; i++)
    {
        if (fmgr_image_cache_p->image_handle_list[i]->is_used == TRUE)
        {
            bg_color = wgui_fmgr_get_bg_color(
                fmgr_image_cache_p->image_handle_list[i]->is_hilighted, 
                fmgr_image_cache_p->image_handle_list[i]->ui_style);
            
            wgui_fmgr_redraw_image_background(                
                fmgr_image_cache_p->image_handle_list[i]->is_hilighted, 
                fmgr_image_cache_p->image_handle_list[i]->ui_style,
                bg_color,
                fmgr_image_cache_p->image_handle_list[i]->draw_pos_x,
                fmgr_image_cache_p->image_handle_list[i]->draw_pos_y,
                fmgr_image_cache_p->image_handle_list[i]->draw_pos_x + fmgr_image_cache_p->image_handle_list[i]->resized_width,
                fmgr_image_cache_p->image_handle_list[i]->draw_pos_y + fmgr_image_cache_p->image_handle_list[i]->resized_height); 
            
            gdi_image_draw(fmgr_image_cache_p->image_handle_list[i]->icon_offset_x,
                fmgr_image_cache_p->image_handle_list[i]->icon_offset_y,
                fmgr_image_cache_p->image_handle_list[i]->icon_ptr);   
            break;
        }
    }

    /* stop all decoding jpeg files */
    gdi_image_decoder_stop_all();

    /* reset delay decoder */
    fmgr_cat_context.delay_decode_index = 0;

    /* check if background decoding finish: yes then unlock wgui status icon */
    if(fmgr_cat_context.decoding_count>0)
    {
        fmgr_cat_context.decoding_count=0;
        //wgui_status_icon_unlock_redrawing();
    }
    
    StopTimer(FMGR_DELAY_DECODE_0);
    StopTimer(FMGR_DELAY_DECODE_1);
    StopTimer(FMGR_DELAY_DECODE_2);
    StopTimer(FMGR_DELAY_DECODE_3);
    StopTimer(FMGR_DELAY_DECODE_4);
    StopTimer(FMGR_DELAY_DECODE_5);
    StopTimer(FMGR_DELAY_DECODE_6);
    StopTimer(FMGR_DELAY_DECODE_7);
    StopTimer(FMGR_DELAY_DECODE_8);
    StopTimer(FMGR_DELAY_DECODE_9);

    /* clear image cache handle entries */
    for (i = 0; i < FMGR_THUMB_IMAGE_HANDLE_MAX_COUNT; i++)
    {
        fmgr_image_cache_p->image_handle_list[i]->is_used = FALSE;
    }

    /* free jpeg decoder */
    if (fmgr_cat_context.is_decoder_create)
    {
        gdi_image_decoder_free();
        fmgr_cat_context.is_decoder_create = FALSE;
    }

#endif /* defined(FMGR_USING_CACHE) */ 

    wgui_cat_fmgr_hide_menuitem();
}


/*****************************************************************************
 * FUNCTION
 *  fmgr_gui_draw_drv_menuitem_callback
 * DESCRIPTION
 *  draw drv menitem callback function
 * PARAMETERS
 *  item_idx            [IN]        Index
 *  is_hilighted        [IN]        Hilight flag
 *  x1                  [IN]        X1
 *  y1                  [IN]        Y1
 *  x2                  [IN]        X2
 *  y2                  [IN]        Y2
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat213_fmgr_draw_menuitem(S32 item_idx, BOOL is_hilighted, S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 left_align_offset_x;
    S32 right_align_offset_x;
    S32 str_width, str_height;
    S32 small_font_height;
    S32 medium_font_height;
    S32 menuitem_height;
    S32 text_spacing;
    S32 r2l_x1;
    S32 r2l_x2;
    S32 filename_offset_y;    
    S32 drv_name_offset_y;
    S32 date_size_offset_y;
    color text_color;
    color text_shadow_color;
    S32 text_box_y1;
    S32 text_box_y2;
    S32 box_offset_x;
    S32 box_offset_y;
    S32 box_width;
    S32 box_height;
    S32 image_offset_x;
    S32 image_offset_y;

    S32 image_width;
    S32 image_height;

    wgui_fmgr_menuitem_data_struct menuitem_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    wgui_cat_fmgr_get_menuitem(item_idx, is_hilighted, &menuitem_data);

    /* lock and push clip */
    gui_lock_double_buffer();
    gui_push_clip();

    gui_reset_clip();
    gui_reset_text_clip();

    if (menuitem_data.info_type == WGUI_CAT21X_INFO_TYPE_DRV)
    {
        /*----------------------------------------------------------------*/
        /* Calcuate text position                                         */
        /*----------------------------------------------------------------*/
        text_box_y1 = y1 + 3;
        text_box_y2 = y2 - 1;

        menuitem_height = text_box_y2 - text_box_y1 + 1;

        small_font_height = Get_CharHeightOfAllLang(MMI_small_font.size);
        gui_set_font(&MMI_medium_font);
        medium_font_height = Get_CharHeightOfAllLang(MMI_medium_font.size);

        text_spacing = (menuitem_height - medium_font_height - small_font_height) / 3;

        if (text_spacing < 0)
        {
            text_spacing = 0;
        }

#if !defined(__MMI_SLIM_FILE_MANAGER__)
        gdi_image_get_dimension_id(IMG_ID_FMGR_DRIVE_SPACE_0, &image_width, &image_height);

        left_align_offset_x = x1 + (image_width) + 2;
        right_align_offset_x = x2 - (image_width) - 2;
#else /* !defined(__MMI_SLIM_FILE_MANAGER__) */ 
        left_align_offset_x = x1 + (y2 - y1 + 1) + 2;
        right_align_offset_x = x2 - (y2 - y1 + 1) - 2;
#endif /* !defined(__MMI_SLIM_FILE_MANAGER__) */ 

        drv_name_offset_y = text_box_y1 + text_spacing - 1;
        date_size_offset_y = text_box_y1 + text_spacing * 2 + medium_font_height;

        if (is_hilighted)
        {
            text_color = current_UI_theme->fixed_text_menuitem_theme->selected_text_color;
            text_shadow_color = current_UI_theme->fixed_text_menuitem_theme->normal_text_color;
        }
        else
        {
            text_color = current_UI_theme->fixed_text_menuitem_theme->normal_text_color;
            text_shadow_color = current_UI_theme->fixed_text_menuitem_theme->selected_text_color;
        }

        /*----------------------------------------------------------------*/
        /* Draw Drvie Name                                                */
        /*----------------------------------------------------------------*/
        gui_set_font(&MMI_medium_font);

        /* set text clip, avoid draw to overlap scroll bar */
        if (r2lMMIFlag)
        {
            gui_set_text_clip(x1 + 1, y1, right_align_offset_x, y2);
        }
        else
        {
            gui_set_text_clip(left_align_offset_x, y1, x2 - 1, y2);
        }

        gui_set_text_color(text_shadow_color);

        if (is_hilighted)
        {
            /* scrolling text has to be stored in global variable */
            /* we use new_file_name buffer since it is not used in this scenario */
            mmi_ucs2cpy((PS8) fmgr_cat_context.scroll_text_buf, (PS8) menuitem_data.menu_text_l1_s1);

            if (r2lMMIFlag)
            {
                gui_create_scrolling_text(
                    &fmgr_cat_context.scroll_text,
                    x1 ,                                 /* x */
                    drv_name_offset_y ,                           /* y */
                    right_align_offset_x - x1 ,                            /* width */
                    medium_font_height ,                     /* height */
                    (UI_string_type) fmgr_cat_context.scroll_text_buf,     /* string */
                    wgui_fmgr_draw_hilight_menuitem_timer_callback,    /* timer hdlr */
                    wgui_fmgr_draw_hilight_menuitem_bg_callback, /* draw background hdlr */
                    text_color,                                 /* text color */
                    MMI_fixed_icontext_menuitem.selected_filler->c);     /* bg */
            }
            else
            {
                gui_create_scrolling_text(
                    &fmgr_cat_context.scroll_text,
                    left_align_offset_x,                        /* x */
                    drv_name_offset_y ,                          /* y */
                    x2 - left_align_offset_x - 1,               /* width */
                    medium_font_height ,                     /* height */
                    (UI_string_type) fmgr_cat_context.scroll_text_buf,     /* string */
                    wgui_fmgr_draw_hilight_menuitem_timer_callback,    /* timer hdlr */
                    wgui_fmgr_draw_hilight_menuitem_bg_callback, /* draw background hdlr */
                    text_color,                                 /* text color */
                    MMI_fixed_icontext_menuitem.selected_filler->c);     /* bg */
            }
            fmgr_cat_context.scroll_text.text_font = MMI_medium_font;
            gui_show_scrolling_text(&fmgr_cat_context.scroll_text);

        }
        else
        {
            gui_set_text_color(text_color);

            if (r2lMMIFlag)
            {
                gui_move_text_cursor(right_align_offset_x, drv_name_offset_y);
            }
            else
            {
                gui_move_text_cursor(left_align_offset_x, drv_name_offset_y);
            }

            gui_print_text((UI_string_type) menuitem_data.menu_text_l1_s1);
        }

        /*----------------------------------------------------------------*/
        /* Draw size                                                      */
        /*----------------------------------------------------------------*/

        gui_set_font(&MMI_small_font);
        gui_measure_string((UI_string_type) menuitem_data.menu_text_l2_s1, &str_width, &str_height);

        if (r2lMMIFlag)
        {
            gui_move_text_cursor(x1 + str_width + 4, date_size_offset_y);   /* 4 spacing from boundry */
        }
        else
        {
            gui_move_text_cursor(x2 - str_width - 4, date_size_offset_y);   /* 4 spacing from boundry */
        }

        gui_print_text((UI_string_type) menuitem_data.menu_text_l2_s1);

        /* restore default font size */
        gui_set_font(&MMI_medium_font);
        gui_reset_text_clip();

        /*----------------------------------------------------------------*/
        /* Draw Icon                                                      */
        /*----------------------------------------------------------------*/

        if (r2lMMIFlag)
        {
            wgui_fmgr_draw_free_space_icon(right_align_offset_x + 1, y1, y2 - y1 + 1, menuitem_data.drv_ratio, menuitem_data.file_icon_ptr);
        }
        else
        {
            wgui_fmgr_draw_free_space_icon(x1 + 1, y1, y2 - y1 + 1, menuitem_data.drv_ratio, menuitem_data.file_icon_ptr);
        }
    }
    else /* (menuitem_data.info_type == WGUI_CAT21X_INFO_TYPE_DRV) */
    {
        /*
         * this function will draw thumb image menuitem .
         *
         * --------------------------------------
         * | ##### FILENAME_HERE.EXT             |    <--- Medium Font
         * | #####                               |
         * | ##### Date                  Size    |    <--- Small Font
         * --------------------------------------
         * Info. (1) Image, it will be the dimension(ex: 640x480) of the file.
         *       (2) Video, Audio. it will be duration of the file.
         */

        box_height = y2 - y1 - FMGR_UI_IMAGE_BOX_SPACING * 2 + 1;
        box_width = box_height;

        box_offset_y = FMGR_UI_IMAGE_BOX_SPACING;

        if (r2lMMIFlag)
        {
            box_offset_x = x2 - box_width - FMGR_UI_IMAGE_BOX_SPACING;
        }
        else
        {
            box_offset_x = FMGR_UI_IMAGE_BOX_SPACING;
        }

        /*----------------------------------------------------------------*/
        /* Calcuate text position here                                    */
        /*----------------------------------------------------------------*/
        small_font_height = Get_CharHeightOfAllLang(MMI_small_font.size);
        
        gui_set_font(&MMI_medium_font);
        medium_font_height = Get_CharHeightOfAllLang(MMI_medium_font.size);

        text_spacing = ((y2 - y1 + 1) - medium_font_height - small_font_height) / 3;

        if (text_spacing < 0)
        {
            text_spacing = 0;
        }

        left_align_offset_x = x1 + box_width + FMGR_UI_TEXT_SPACING;

        r2l_x1 = x1 + MMI_fixed_list_menu.vbar.width + 2;
        r2l_x2 = x2 - (y2 - y1 + 1) - text_spacing;

        filename_offset_y = y1 + text_spacing;
        date_size_offset_y = y1 + text_spacing * 2 + medium_font_height;

        if (is_hilighted)
        {
            text_color = current_UI_theme->fixed_text_menuitem_theme->selected_text_color;
            text_shadow_color = current_UI_theme->fixed_text_menuitem_theme->normal_text_color;
        }
        else
        {
            text_color = current_UI_theme->fixed_text_menuitem_theme->normal_text_color;
            text_shadow_color = current_UI_theme->fixed_text_menuitem_theme->selected_text_color;
        }

        /*----------------------------------------------------------------*/
        /* Draw File Name                                                 */
        /*----------------------------------------------------------------*/
        if (is_hilighted)
        {
            /* scrolling text has to be stored in global variable */
            /* we use new_file_name buffer since it is not used in this scenario */
            mmi_ucs2cpy((PS8) fmgr_cat_context.scroll_text_buf, (PS8) menuitem_data.menu_text_l1_s1);

            if (r2lMMIFlag)
            {
                gui_create_scrolling_text(
                    &fmgr_cat_context.scroll_text,
                    r2l_x1 + 4,                                 /* x */
                    filename_offset_y,                          /* y */
                    r2l_x2 - r2l_x1 - 4,                        /* width */
                    medium_font_height ,                     /* height */
                    (UI_string_type) fmgr_cat_context.scroll_text_buf,     /* string */
                    wgui_fmgr_draw_hilight_menuitem_timer_callback,    /* timer hdlr */
                    wgui_fmgr_draw_hilight_menuitem_bg_callback, /* draw background hdlr */
                    text_color,                                 /* text color */
                    MMI_fixed_icontext_menuitem.selected_filler->c);     /* bg */
            }
            else
            {
                gui_create_scrolling_text(
                    &fmgr_cat_context.scroll_text,
                    left_align_offset_x,                        /* x */
                    filename_offset_y,                          /* y */
                    x2 - left_align_offset_x - 1,               /* width */
                    medium_font_height ,                     /* height */
                    (UI_string_type) fmgr_cat_context.scroll_text_buf,     /* string */
                    wgui_fmgr_draw_hilight_menuitem_timer_callback,    /* timer hdlr */
                    wgui_fmgr_draw_hilight_menuitem_bg_callback, /* draw background hdlr */
                    text_color,                                 /* text color */
                    MMI_fixed_icontext_menuitem.selected_filler->c);     /* bg */
            }

            fmgr_cat_context.scroll_text.text_font = MMI_medium_font;
            gui_show_scrolling_text(&fmgr_cat_context.scroll_text);
        }
        else
        {
            S32 sw = 0, sh = 0;

            gui_set_font(&MMI_medium_font);

            /* set text clip, avoid draw to overlap scroll bar */
            gui_set_text_color(text_color);

            if (r2lMMIFlag)
            {
                gui_set_text_clip(r2l_x1, filename_offset_y, r2l_x2, filename_offset_y + medium_font_height + 1);

                gui_move_text_cursor(r2l_x2, filename_offset_y);
            }
            else
            {
                gui_set_text_clip(
                    left_align_offset_x,
                    filename_offset_y,
                    x2 - 1,
                    filename_offset_y + medium_font_height + 1);

                gui_move_text_cursor(left_align_offset_x, filename_offset_y);
            }

            gui_measure_string((UI_string_type) menuitem_data.menu_text_l1_s1, &sw, &sh);
            gui_set_line_height(sh);
            gui_print_text((UI_string_type) menuitem_data.menu_text_l1_s1);
        }

        /*----------------------------------------------------------------*/
        /* Draw File Creation Date                                        */
        /*----------------------------------------------------------------*/
        /* if is directory or is file but lcd is large enough to fit date and size on one line  */
        if (!CHECK_UCS2STR_EMPTY(menuitem_data.menu_text_l2_s1))
        {
            gui_set_font(&MMI_small_font);
            gui_reset_text_clip();
            gui_set_text_color(text_color);

            if (r2lMMIFlag)
            {
                gui_move_text_cursor(r2l_x2, date_size_offset_y);
            }
            else
            {
                gui_move_text_cursor(left_align_offset_x, date_size_offset_y);
            }

            gui_print_text((UI_string_type) menuitem_data.menu_text_l2_s1);
        }

        /*----------------------------------------------------------------*/
        /* Draw File Size                                                 */
        /*----------------------------------------------------------------*/
        if (!CHECK_UCS2STR_EMPTY(menuitem_data.menu_text_l2_s2))
        {
            gui_reset_text_clip();
            gui_set_text_color(text_color);
            gui_set_font(&MMI_small_font);

            gui_measure_string((UI_string_type) menuitem_data.menu_text_l2_s2, &str_width, &str_height);

            if (r2lMMIFlag)
            {
                gui_move_text_cursor(r2l_x1 + str_width, date_size_offset_y);
            }
            else
            {
                gui_move_text_cursor(x2 - str_width - 4, date_size_offset_y);
            }

            gui_print_text((UI_string_type) menuitem_data.menu_text_l2_s2);
        }

        /* restore font to default size */
        gui_set_font(&MMI_medium_font);

        /*----------------------------------------------------------------*/
        /* Draw Large Icon                                                */
        /*----------------------------------------------------------------*/
        if (menuitem_data.is_show_thumb == MMI_TRUE)
        {
            if (r2lMMIFlag)
                x1 = 0;
            wgui_fmgr_show_thumb_image(
                item_idx,
                x1,
                y1,
                box_offset_x,
                box_offset_y,
                box_width,
                box_height,
                menuitem_data.file_icon_ptr,
                is_hilighted,
                MMI_FMGR_GUI_LIST_STYLE);
        }
        else
        {
            gui_measure_image( menuitem_data.file_icon_ptr, &image_width, &image_height);

            image_offset_x = (box_width - image_width) >> 1;
            image_offset_y = (box_height - image_height) >> 1;

            gdi_image_draw(box_offset_x + image_offset_x, y1 + box_offset_y + image_offset_y, menuitem_data.file_icon_ptr);
        }

    }
    
    /* pop clip , unlock and blt */
    gui_pop_clip();
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);
}



/*****************************************************************************
 * FUNCTION
 *  wgui_cat214_fmgr_draw_menuitem_matrix
 * DESCRIPTION
 *  draw matrix file item
 * PARAMETERS
 *  idx                     [IN]        Selected index
 *  page_start_idx          [IN]        Page's start index
 *  page_end_idx            [IN]        Page's end index
 *  is_hilighted            [IN]        
 *  is_need_update          [IN]        Is thie item need update
 *  is_new_page             [IN]        Is first time draw this page
 *  x1                      [IN]        Draw region's x1
 *  y1                      [IN]        Draw region's y1
 *  x2                      [IN]        Draw region's x2
 *  y2                      [IN]        Draw region's y2
 *  is_highlghted(?)        [IN]        Is this selection highlighted
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat214_fmgr_draw_menuitem_matrix(S32 idx, S32 page_start_idx, S32 page_end_idx,
                                             BOOL is_hilighted, BOOL is_need_update, BOOL is_new_page,
                                             S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 box_width;
    S32 box_height;
    S32 box_offset_x;
    S32 box_offset_y;
    S32 image_width;
    S32 image_height;
    BOOL is_image_in_cache;
    BOOL is_prev_image_in_cache;

#if defined(FMGR_USING_CACHE)
    S32 prev_idx;
    S32 prev_cache_index;
    S32 cache_index;
#endif /* defined(FMGR_USING_CACHE) */ 

    wgui_fmgr_menuitem_data_struct menuitem_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    wgui_cat_fmgr_get_menuitem(idx, is_hilighted, &menuitem_data);
   
    is_image_in_cache = FALSE;
    is_prev_image_in_cache = FALSE;

#if defined(FMGR_USING_CACHE)

    /* if not need update, and it is not jpeg, the icon shall already draw */
    if ((!is_need_update) && (menuitem_data.is_show_thumb != MMI_TRUE))
    {
        return;
    }

    for (cache_index = 0; cache_index < fmgr_image_cache_p->image_cache_item_count; cache_index++)
    {
        if ((fmgr_image_cache_p->image_cache_list[cache_index]->is_used == TRUE) &&
            (fmgr_image_cache_p->image_cache_list[cache_index]->menuitem_idx == idx))
        {
            is_image_in_cache = TRUE;
            break;
        }
    }

    /* if this item no need update and is already in cache, no need draw */
    /* if is is_need_update, means hilight is changed or page is changed in cat224 */
    if (!is_need_update && is_image_in_cache)
    {
        return;
    }

    /* if not need update, and it the file is corrupted, the icon shall already draw */
    if (!is_need_update && !wgui_cat21x_get_displayable(idx))
    {
        return;
    }

    /* check if previous image is in cache or not */
    /* if previous image not in cache, will remove this image from cache */
    /* 
     * this is used to avoid showing images on a page, some images with larger idx 
     * are decoded aready, and some image with smaller idx are not decoded 
     * 
     * if is_need_update == TRUE, means first time show the matrix page.
     */
    if ((idx > 0) && (idx != page_start_idx) && is_new_page)
    {
        prev_idx = idx - 1;
        for (prev_cache_index = 0; prev_cache_index < fmgr_image_cache_p->image_cache_item_count; prev_cache_index++)
        {
            if ((fmgr_image_cache_p->image_cache_list[prev_cache_index]->is_used == TRUE) &&
                (fmgr_image_cache_p->image_cache_list[prev_cache_index]->menuitem_idx == prev_idx))
            {
                is_prev_image_in_cache = TRUE;
                break;
            }
        }

        if (!is_prev_image_in_cache && is_image_in_cache)
        {
            /* if previous not in cache */
            /* remove this from cache */
            fmgr_image_cache_p->image_cache_list[cache_index]->is_used = FALSE;
        }
    }
#endif /* defined(FMGR_USING_CACHE) */ 

    /* lock and push clip */
    gdi_layer_lock_frame_buffer();
    gdi_layer_push_clip();
    gdi_layer_reset_clip();

    /* spare 1 pixel with boundry */
    box_offset_x = x1;
    box_offset_y = y1;
    box_width = x2 - x1 + 1;
    box_height = y2 - y1 + 1;

#if defined(FMGR_USING_CACHE)
    if ( box_width > fmgr_image_cache_p->image_size )
    {
        box_offset_x += ((box_width - fmgr_image_cache_p->image_size)>>1);
        box_width = fmgr_image_cache_p->image_size;
    }
    
    if ( box_height > fmgr_image_cache_p->image_size )
    {
        box_offset_y += ((box_height - fmgr_image_cache_p->image_size)>>1);
        box_height = fmgr_image_cache_p->image_size;
    }
#endif /* defined(FMGR_USING_CACHE) */

    gdi_image_get_dimension(menuitem_data.file_icon_ptr, &image_width, &image_height);

#if defined(FMGR_USING_CACHE)
    /* draw thumb image */
    if (menuitem_data.is_show_thumb == MMI_TRUE)
    {
        wgui_fmgr_show_thumb_image(
            idx,
            box_offset_x,
            box_offset_y,
            0,
            0,
            box_width,
            box_height,
            menuitem_data.file_icon_ptr,
            is_hilighted,
            MMI_FMGR_GUI_MATRIX_STYLE);
    }
    else
    {
        gdi_image_draw(
            box_offset_x + ((box_width - image_width) >> 1),
            box_offset_y + ((box_height - image_height) >> 1),
            menuitem_data.file_icon_ptr);
    }
#else /* defined(FMGR_USING_CACHE) */
    gdi_image_draw(
        box_offset_x + ((box_width - image_width) >> 1),
        box_offset_y + ((box_height - image_height) >> 1),
        menuitem_data.file_icon_ptr);
#endif /* defined(FMGR_USING_CACHE) */

    gdi_layer_pop_clip();
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat214_fmgr_hide_menuitem_matrix
 * DESCRIPTION
 *  hide matrix file item
 * PARAMETERS
 *  idx     [IN]        Selected index
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat214_fmgr_hide_menuitem_matrix(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(FMGR_USING_CACHE)
    S32 i;
    gdi_color bg_color = GDI_COLOR_BLACK;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(FMGR_USING_CACHE)
    for (i = 0; i < FMGR_THUMB_IMAGE_HANDLE_MAX_COUNT; i++)
    {
        if (fmgr_image_cache_p->image_handle_list[i]->is_used == TRUE)
        {
            bg_color = wgui_fmgr_get_bg_color(
                fmgr_image_cache_p->image_handle_list[i]->is_hilighted, 
                fmgr_image_cache_p->image_handle_list[i]->ui_style);
            
            wgui_fmgr_redraw_image_background(                
                fmgr_image_cache_p->image_handle_list[i]->is_hilighted, 
                fmgr_image_cache_p->image_handle_list[i]->ui_style,
                bg_color,
                fmgr_image_cache_p->image_handle_list[i]->draw_pos_x,
                fmgr_image_cache_p->image_handle_list[i]->draw_pos_y,
                fmgr_image_cache_p->image_handle_list[i]->draw_pos_x + fmgr_image_cache_p->image_handle_list[i]->resized_width,
                fmgr_image_cache_p->image_handle_list[i]->draw_pos_y + fmgr_image_cache_p->image_handle_list[i]->resized_height); 
            
            gdi_image_draw(fmgr_image_cache_p->image_handle_list[i]->icon_offset_x,
                fmgr_image_cache_p->image_handle_list[i]->icon_offset_y,
                fmgr_image_cache_p->image_handle_list[i]->icon_ptr);   
            break;
        }
    }

    /* stop all decoding jpeg files */
    gdi_image_decoder_stop_all();

    /* reset delay decoder */
    fmgr_cat_context.delay_decode_index = 0;

    /* check if background decoding finish: yes then unlock wgui status icon */
    if(fmgr_cat_context.decoding_count>0)
    {
        fmgr_cat_context.decoding_count=0;
        //wgui_status_icon_unlock_redrawing();
    }

    StopTimer(FMGR_DELAY_DECODE_0);
    StopTimer(FMGR_DELAY_DECODE_1);
    StopTimer(FMGR_DELAY_DECODE_2);
    StopTimer(FMGR_DELAY_DECODE_3);
    StopTimer(FMGR_DELAY_DECODE_4);
    StopTimer(FMGR_DELAY_DECODE_5);
    StopTimer(FMGR_DELAY_DECODE_6);
    StopTimer(FMGR_DELAY_DECODE_7);
    StopTimer(FMGR_DELAY_DECODE_8);
    StopTimer(FMGR_DELAY_DECODE_9);

    /* clear image cache handle entries */
    for (i = 0; i < FMGR_THUMB_IMAGE_HANDLE_MAX_COUNT; i++)
    {
        fmgr_image_cache_p->image_handle_list[i]->is_used = FALSE;
    }

    /* free jpeg decoder */
    if (fmgr_cat_context.is_decoder_create)
    {
        gdi_image_decoder_free();
        fmgr_cat_context.is_decoder_create = FALSE;
    }

#endif /* defined(FMGR_USING_CACHE) */ 
    wgui_cat_fmgr_hide_menuitem();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_fmgr_draw_free_space_icon
 * DESCRIPTION
 *  draw free space icon
 * PARAMETERS
 *  box_x1          [IN]        Bounding box offset x
 *  box_y1          [IN]        Bounding box offset y
 *  box_height      [IN]        Bounding box's height
 *  ratio           [IN]        Free space %
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_fmgr_draw_free_space_icon(S32 box_x1, S32 box_y1, S32 box_height, U32 drv_ratio, PU8 file_icon_ptr)
{
#if defined(__MMI_SLIM_FILE_MANAGER__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x_spacing;
    S32 y_spacing;
    S32 offset_x;
    S32 offset_y;
    S32 width;
    S32 height;
    gdi_color green_start_color;
    gdi_color green_end_color;
    gdi_color red_start_color;
    gdi_color red_end_color;
    S32 green_width;
    S32 red_width;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x_spacing = 1;
    y_spacing = 8;
    offset_x = box_x1 + x_spacing;
    offset_y = box_y1 + y_spacing;
    width = box_height - 2 * x_spacing;
    height = box_height - 2 * y_spacing;

    green_width = width * drv_ratio / 10;
    red_width = width - green_width;

    green_start_color = gdi_act_color_from_rgb(255,30, 255, 30);
    green_end_color = gdi_act_color_from_rgb(255,200, 255, 200);

    red_start_color = gdi_act_color_from_rgb(255,255, 30, 30);
    red_end_color = gdi_act_color_from_rgb(255,255, 200, 200);

    gdi_draw_gradient_rect(
        offset_x,
        offset_y,
        offset_x + red_width,
        offset_y + height,
        red_start_color,
        red_end_color,
        GDI_COLOR_BLACK,
        1,
        GDI_GRADIENT_RECT_VER);

    gdi_draw_gradient_rect(
        offset_x + red_width,
        offset_y,
        offset_x + width,
        offset_y + height,
        green_start_color,
        green_end_color,
        GDI_COLOR_BLACK,
        1,
        GDI_GRADIENT_RECT_VER);

#else /* defined(__MMI_SLIM_FILE_MANAGER__) */ 
    S32 img_width, img_height;
    S32 spacing_y;

    gui_measure_image(file_icon_ptr, &img_width, &img_height);
    /* because of box's height == box's width */
    spacing_y = (box_height - img_height) >> 1;

    gui_show_transparent_image(box_x1, box_y1 + spacing_y + 1, file_icon_ptr, 0);

#endif /* defined(__MMI_SLIM_FILE_MANAGER__) */ 
}









/*****************************************************************************
 * FUNCTION
 *  wgui_fmgr_create_thumb_image_cache
 * DESCRIPTION
 *  create thumb image cache resource.
 * PARAMETERS
 *  image_size      [IN]        Menuitem height, this is used to caculate image resource.
 * RETURNS
 *  void
 * BOOL
 *****************************************************************************/
void wgui_fmgr_create_thumb_image_cache(S32 image_size)
{
#if defined(FMGR_USING_CACHE)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 cache_size;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* calcuate thumb image size */
    fmgr_image_cache_p->image_size = image_size;
    cache_size = (fmgr_image_cache_p->image_size * fmgr_image_cache_p->image_size * GDI_LAYER.act_bit_per_pixel) >> 3;
    ASSERT(cache_size > 0);

    /* sub 1 for overhead usage */
    fmgr_image_cache_p->image_cache_item_count = (U16) (mmi_frm_scrmem_get_available_size() / cache_size) - 1;

    if (fmgr_image_cache_p->image_cache_item_count > FMGR_THUMB_IMAGE_CACHE_MAX_COUNT)
    {
        fmgr_image_cache_p->image_cache_item_count = FMGR_THUMB_IMAGE_CACHE_MAX_COUNT;
    }

    /* init seq number */
    fmgr_image_cache_p->image_decode_seq_num = 0;

    /* allocate buffer for list data */
    for (i = 0; i < fmgr_image_cache_p->image_cache_item_count; i++)
    {
        fmgr_image_cache_p->image_cache_list[i] = &image_cache_list_buffer[i];
        fmgr_image_cache_p->image_cache_list[i]->is_used = FALSE;
        fmgr_image_cache_p->image_cache_list[i]->unused_duration = 0;
        fmgr_image_cache_p->image_cache_list[i]->bmp.buf_ptr = (U8*)mmi_frm_scrmem_alloc(cache_size);
    }

    for (i = 0; i < FMGR_THUMB_IMAGE_HANDLE_MAX_COUNT; i++)
    {
        fmgr_image_cache_p->image_handle_list[i] = &image_handle_list_buffer[i];
        fmgr_image_cache_p->image_handle_list[i]->is_used = FALSE;
    }

#endif /* defined(FMGR_USING_CACHE) */ 
}


/*****************************************************************************
 * FUNCTION
 *  wgui_fmgr_cache_stop_decoder
 * DESCRIPTION
 *  stop thumb image caching 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * BOOL
 *****************************************************************************/
void wgui_fmgr_cache_stop_decoder(void)
{
#if defined(FMGR_USING_CACHE)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;   
    gdi_color bg_color = GDI_COLOR_BLACK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Close all decode handle, so that GDI will release file handle */
    for (i = 0; i < FMGR_THUMB_IMAGE_HANDLE_MAX_COUNT; i++)
    {
        if (fmgr_image_cache_p->image_handle_list[i] &&
            fmgr_image_cache_p->image_handle_list[i]->is_used &&
            fmgr_image_cache_p->image_handle_list[i]->handle)
        {
            bg_color = wgui_fmgr_get_bg_color(
                fmgr_image_cache_p->image_handle_list[i]->is_hilighted, 
                fmgr_image_cache_p->image_handle_list[i]->ui_style);  
            
            wgui_fmgr_redraw_image_background(                
                fmgr_image_cache_p->image_handle_list[i]->is_hilighted, 
                fmgr_image_cache_p->image_handle_list[i]->ui_style,
                bg_color,
                fmgr_image_cache_p->image_handle_list[i]->draw_pos_x,
                fmgr_image_cache_p->image_handle_list[i]->draw_pos_y,
                fmgr_image_cache_p->image_handle_list[i]->draw_pos_x + fmgr_image_cache_p->image_handle_list[i]->resized_width,
                fmgr_image_cache_p->image_handle_list[i]->draw_pos_y + fmgr_image_cache_p->image_handle_list[i]->resized_height); 
            
            gdi_image_draw(fmgr_image_cache_p->image_handle_list[i]->icon_offset_x,
                fmgr_image_cache_p->image_handle_list[i]->icon_offset_y,
                fmgr_image_cache_p->image_handle_list[i]->icon_ptr);                  

            gdi_image_decoder_stop(fmgr_image_cache_p->image_handle_list[i]->handle);
            fmgr_image_cache_p->image_handle_list[i]->handle = 0;
            fmgr_image_cache_p->image_handle_list[i]->is_used = FALSE;
        }
    }
#endif    
}

/*****************************************************************************
 * FUNCTION
 *  wgui_fmgr_free_thumb_image_cache
 * DESCRIPTION
 *  free thumb image cache resource.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * BOOL
 *****************************************************************************/
void wgui_fmgr_free_thumb_image_cache(void)
{
#if defined(FMGR_USING_CACHE)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset delay decoder */
    fmgr_cat_context.delay_decode_index = 0;
    StopTimer(FMGR_DELAY_DECODE_0);
    StopTimer(FMGR_DELAY_DECODE_1);
    StopTimer(FMGR_DELAY_DECODE_2);
    StopTimer(FMGR_DELAY_DECODE_3);
    StopTimer(FMGR_DELAY_DECODE_4);
    StopTimer(FMGR_DELAY_DECODE_5);
    StopTimer(FMGR_DELAY_DECODE_6);
    StopTimer(FMGR_DELAY_DECODE_7);
    StopTimer(FMGR_DELAY_DECODE_8);
    StopTimer(FMGR_DELAY_DECODE_9);

    /* free all allocated memory */
    for (i = 0; i < fmgr_image_cache_p->image_cache_item_count; i++)
    {
        if (fmgr_image_cache_p->image_cache_list[i]->bmp.buf_ptr != NULL)
        {
            mmi_frm_scrmem_free(fmgr_image_cache_p->image_cache_list[i]->bmp.buf_ptr);
            fmgr_image_cache_p->image_cache_list[i]->bmp.buf_ptr = NULL;
        }
        else
        {
            MMI_ASSERT(0);
        }
    }
	fmgr_image_cache_p->image_cache_item_count = 0;

    wgui_fmgr_cache_stop_decoder();
#endif /* defined(FMGR_USING_CACHE) */ 
}


/*****************************************************************************
* FUNCTION
*   wgui_fmgr_delay_decode_x()
* DESCRIPTION
*   delay decode callback function for timer expire
* PARAMETERS
*   void
* RETURNS
*   BOOL
* GLOBALS AFFECTED
*   nil
*****************************************************************************/
#if defined(FMGR_USING_CACHE)

/* start of delay decoder function macro */
#define FMGR_DELAY_DECODE_FUNCTION(_idx_)                                                     \
void wgui_fmgr_delay_decode_##_idx_##(void)                                          \
{                                                                                          \
     wgui_fmgr_delay_decode_image(  fmgr_cat_context.delay_decoder[##_idx_##].item_idx,         \
                                   fmgr_cat_context.delay_decoder[##_idx_##].menuitem_offset_x,\
                                   fmgr_cat_context.delay_decoder[##_idx_##].menuitem_offset_y,\
                                   fmgr_cat_context.delay_decoder[##_idx_##].box_offset_x,     \
                                   fmgr_cat_context.delay_decoder[##_idx_##].box_offset_y,     \
                                   fmgr_cat_context.delay_decoder[##_idx_##].box_width,        \
                                   fmgr_cat_context.delay_decoder[##_idx_##].box_height,       \
                                   fmgr_cat_context.delay_decoder[##_idx_##].icon_offset_x,    \
                                   fmgr_cat_context.delay_decoder[##_idx_##].icon_offset_y,    \
                                   fmgr_cat_context.delay_decoder[##_idx_##].icon_width,       \
                                   fmgr_cat_context.delay_decoder[##_idx_##].icon_height,      \
                                   fmgr_cat_context.delay_decoder[##_idx_##].icon_ptr,         \
                                   fmgr_cat_context.delay_decoder[##_idx_##].is_hilighted,     \
                                   fmgr_cat_context.delay_decoder[##_idx_##].ui_style);        \
}
/* end of macro */

/* delay decode function */
FMGR_DELAY_DECODE_FUNCTION(0)
FMGR_DELAY_DECODE_FUNCTION(1)
FMGR_DELAY_DECODE_FUNCTION(2)
FMGR_DELAY_DECODE_FUNCTION(3)
FMGR_DELAY_DECODE_FUNCTION(4)
FMGR_DELAY_DECODE_FUNCTION(5)
FMGR_DELAY_DECODE_FUNCTION(6) 
FMGR_DELAY_DECODE_FUNCTION(7) 
FMGR_DELAY_DECODE_FUNCTION(8) 
FMGR_DELAY_DECODE_FUNCTION(9)
#endif /* defined(FMGR_USING_CACHE) */ 



/*****************************************************************************
 * FUNCTION
 *  wgui_fmgr_delay_decode_image
 * DESCRIPTION
 *  decode image for delay decoder, avoid UI hang too long
 * PARAMETERS
 *  item_idx                [IN]        Item index
 *  menuitem_offset_x       [IN]        Menu item's offset x
 *  menuitem_offset_y       [IN]        Menu item's offset y
 *  box_offset_x            [IN]        Image box's offset x
 *  box_offset_y            [IN]        Image box's offset y
 *  box_width               [IN]        Image box's width
 *  box_height              [IN]        Image box's height
 *  icon_offset_x           [IN]        Icon's offset x
 *  icon_offset_y           [IN]        Icon's offset y
 *  icon_width              [IN]        Icon's width
 *  icon_height             [IN]        Icon's height
 *  icon_ptr                [IN]        Image ptr
 *  is_hilighted            [IN]        Is highlight flag
 *  ui_style                [IN]        UI style
 * RETURNS
 *  void
 * BOOL
 *****************************************************************************/
#if defined(FMGR_USING_CACHE)
void wgui_fmgr_delay_decode_image(S32 item_idx, S32 menuitem_offset_x, S32 menuitem_offset_y, S32 box_offset_x,
                                      S32 box_offset_y, S32 box_width, S32 box_height,
                                      S32 icon_offset_x, S32 icon_offset_y, S32 icon_width,
                                      S32 icon_height, PU8 icon_ptr, BOOL is_hilighted, U16 ui_style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buffer_UCS2[FMGR_PATH_BUFFER_SIZE];
    GDI_RESULT ret;
    S32 img_width, img_height;
    S32 resized_width, resized_height;
    S32 resized_offset_x, resized_offset_y;
    S32 handle_idx;
    S32 draw_pos_x, draw_pos_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!wgui_cat21x_get_image_path_callback(item_idx, buffer_UCS2))
    {
        /* gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1); */
        return;
    }

    /* check if background decoding finish: yes then start to scroll */    
    /*if (fmgr_cat_context.decoding_count == 0)
        wgui_status_icon_lock_redrawing();    */

    fmgr_cat_context.decoding_count++;

    gdi_layer_push_clip();
    gdi_layer_reset_clip();

    /* find a vlid decode handle slot */
    for (handle_idx = 0; handle_idx < FMGR_THUMB_IMAGE_HANDLE_MAX_COUNT; handle_idx++)
    {
        if (fmgr_image_cache_p->image_handle_list[handle_idx]->is_used == FALSE)
        {
            break;
        }
    }

    /* valid handle chcek */
    ASSERT(handle_idx < FMGR_THUMB_IMAGE_HANDLE_MAX_COUNT);


    /* get jpeg width and height */
    ret = gdi_image_get_dimension_file((PS8) buffer_UCS2, &img_width, &img_height);

    /* check if is a valid image or not */
    /* TODO: Adapt to File limit */
    if ((ret < 0) || (img_width <= 0) || (img_height <= 0))   /* invalid image size */
    {
        wgui_cat21x_set_displayable(item_idx, MMI_FALSE);
        //gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
        goto end_decode;
    }

    /* can get dimesion from file, must be a valid jpeg file, then draw it */



    if ( (img_width + 4 < box_width) && (img_height +4 < box_height))
    {
        resized_width = img_width;
        resized_height = img_height;
        resized_offset_x = ((box_width-4-img_width)>>1);
        resized_offset_y = ((box_height-4-img_height)>>1);           
        draw_pos_x = box_offset_x + 2 + resized_offset_x;
        draw_pos_y = box_offset_y + 2 + resized_offset_y;

    }
    else
    {
        /* fit it into a bounding box */
        if (ui_style == MMI_FMGR_GUI_MATRIX_STYLE)
        {
            /* reserver 2 pixel at each side to draw boundry and highlight rectangle */
            gdi_image_util_fit_bbox(
                box_width - 4,
                box_height - 4,
                img_width,
                img_height,
                &resized_offset_x,
                &resized_offset_y,
                &resized_width,
                &resized_height);

            draw_pos_x = box_offset_x + 2 + resized_offset_x;
            draw_pos_y = box_offset_y + 2 + resized_offset_y;
        }
        else
        {
            /* reserver 1 pixel at each side to draw boundry */
            gdi_image_util_fit_bbox(
                box_width - 2,
                box_height - 2,
                img_width,
                img_height,
                &resized_offset_x,
                &resized_offset_y,
                &resized_width,
                &resized_height);

            draw_pos_x = box_offset_x + 1 + resized_offset_x;
            draw_pos_y = box_offset_y + 1 + resized_offset_y;
            resized_height--;
        }
    }    



    ret = gdi_image_decoder_decode_file(
            draw_pos_x,
            draw_pos_y,
            resized_width,
            resized_height,
            FALSE,
            (PS8) buffer_UCS2,
            &(fmgr_image_cache_p->image_handle_list[handle_idx]->handle));

    if (ret >= 0)
    {
        fmgr_image_cache_p->image_handle_list[handle_idx]->is_used = TRUE;
        fmgr_image_cache_p->image_handle_list[handle_idx]->draw_pos_x = draw_pos_x;
        fmgr_image_cache_p->image_handle_list[handle_idx]->draw_pos_y = draw_pos_y;
        fmgr_image_cache_p->image_handle_list[handle_idx]->resized_offset_x = resized_offset_x;
        fmgr_image_cache_p->image_handle_list[handle_idx]->resized_offset_y = resized_offset_y;
        fmgr_image_cache_p->image_handle_list[handle_idx]->resized_width = resized_width;
        fmgr_image_cache_p->image_handle_list[handle_idx]->resized_height = resized_height;
        fmgr_image_cache_p->image_handle_list[handle_idx]->box_offset_x = box_offset_x;
        fmgr_image_cache_p->image_handle_list[handle_idx]->box_offset_y = box_offset_y;
        fmgr_image_cache_p->image_handle_list[handle_idx]->box_width = box_width;
        fmgr_image_cache_p->image_handle_list[handle_idx]->box_height = box_height;
        fmgr_image_cache_p->image_handle_list[handle_idx]->icon_offset_x = icon_offset_x;
        fmgr_image_cache_p->image_handle_list[handle_idx]->icon_offset_y = icon_offset_y;
        fmgr_image_cache_p->image_handle_list[handle_idx]->icon_width = icon_width;
        fmgr_image_cache_p->image_handle_list[handle_idx]->icon_height = icon_height;
        fmgr_image_cache_p->image_handle_list[handle_idx]->icon_ptr = icon_ptr;
        fmgr_image_cache_p->image_handle_list[handle_idx]->menuitem_idx = (U16) item_idx;
        fmgr_image_cache_p->image_handle_list[handle_idx]->is_hilighted = is_hilighted;
        fmgr_image_cache_p->image_handle_list[handle_idx]->ui_style = ui_style;
    }
    else
    {
        wgui_cat21x_set_displayable(item_idx, MMI_FALSE);
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
    }

end_decode:
    gdi_layer_pop_clip();
    return;

}
#endif /* defined(FMGR_USING_CACHE) */ 


/*****************************************************************************
 * FUNCTION
 *  wgui_fmgr_show_thumb_image
 * DESCRIPTION
 *  show thumb image
 * PARAMETERS
 *  item_idx                [IN]        Item index
 *  menuitem_offset_x       [IN]        Menu item's offset x
 *  menuitem_offset_y       [IN]        Menu item's offset y
 *  box_offset_x            [IN]        Image box offset x
 *  box_offset_y            [IN]        Image box offset y
 *  box_width               [IN]        Image box width
 *  box_height              [IN]        Image box height
 *  icon_ptr                [IN]        Icon's image ptr
 *  is_hilighted            [IN]        Is highlight flag
 *  ui_style                [IN]        
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL wgui_fmgr_show_thumb_image(
                S32 item_idx,
                S32 menuitem_offset_x,
                S32 menuitem_offset_y,
                S32 box_offset_x,
                S32 box_offset_y,
                S32 box_width,
                S32 box_height,
                PU8 icon_ptr,
                BOOL is_hilighted,
                U16 ui_style)
{
#if defined(FMGR_USING_CACHE)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL is_image_in_cache;
    S32 icon_offset_x, icon_offset_y;
    S32 icon_width, icon_height;
    S32 cache_index;
    S32 draw_pos_x, draw_pos_y;
    S32 i;
    gdi_color bg_color = GDI_COLOR_BLACK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* create jpeg decoder */
    if (!fmgr_cat_context.is_decoder_create)
    {
        /* max image size is 100x100 */
        gdi_image_decoder_create(100, 100, wgui_fmgr_decode_thumb_image_result_hdlr);
        gdi_nb_set_anim_after_frame_callback(wgui_fmgr_decode_thumb_image_after_frame);
        fmgr_cat_context.is_decoder_create = TRUE;
    }

    gdi_layer_push_clip();
    gdi_layer_reset_clip();

    gdi_image_get_dimension((PU8) icon_ptr, &icon_width, &icon_height);

    icon_offset_x = ((box_width - icon_width) >> 1) + menuitem_offset_x + box_offset_x;
    icon_offset_y = ((box_height - icon_height) >> 1) + menuitem_offset_y + box_offset_y;

    box_offset_x += menuitem_offset_x;
    box_offset_y += menuitem_offset_y;

    if (wgui_cat21x_get_displayable(item_idx) == MMI_FALSE)
    {
        if (is_hilighted)
        {
            gdi_image_draw(icon_offset_x, icon_offset_y, icon_ptr);
        }
        else
        {
            gdi_image_draw(icon_offset_x, icon_offset_y, icon_ptr);
        }

        /* corrupted file */
        gdi_layer_pop_clip();
        return FALSE;
    }

    /* test if is in the cache */
    is_image_in_cache = FALSE;

    for (cache_index = 0; cache_index < fmgr_image_cache_p->image_cache_item_count; cache_index++)
    {
        if ((fmgr_image_cache_p->image_cache_list[cache_index]->is_used == TRUE) &&
            (fmgr_image_cache_p->image_cache_list[cache_index]->menuitem_idx == item_idx))
        {
            is_image_in_cache = TRUE;
            break;
        }
    }

    /* if can find image in cache, draw it from cache */
    if (is_image_in_cache == TRUE)
    {
        if (ui_style == MMI_FMGR_GUI_MATRIX_STYLE)
        {
            draw_pos_x = box_offset_x + fmgr_image_cache_p->image_cache_list[cache_index]->resized_offset_x + 2;
            draw_pos_y = box_offset_y + fmgr_image_cache_p->image_cache_list[cache_index]->resized_offset_y + 2;

            /* draw frame */
            gdi_draw_rect(
                draw_pos_x - 1,
                draw_pos_y - 1,
                draw_pos_x + fmgr_image_cache_p->image_cache_list[cache_index]->resized_width,
                draw_pos_y + fmgr_image_cache_p->image_cache_list[cache_index]->resized_height,
                GDI_COLOR_BLACK);

            gdi_image_cache_bmp_draw(draw_pos_x, draw_pos_y, &fmgr_image_cache_p->image_cache_list[cache_index]->bmp);

        }
        else
        {
            draw_pos_x = box_offset_x + fmgr_image_cache_p->image_cache_list[cache_index]->resized_offset_x + 1;
            draw_pos_y = box_offset_y + fmgr_image_cache_p->image_cache_list[cache_index]->resized_offset_y + 1;

            /* draw frame */
            gdi_draw_rect(
                draw_pos_x - 1,
                draw_pos_y - 1,
                draw_pos_x + fmgr_image_cache_p->image_cache_list[cache_index]->resized_width,
                draw_pos_y + fmgr_image_cache_p->image_cache_list[cache_index]->resized_height,
                GDI_COLOR_BLACK);

            gdi_image_cache_bmp_draw(draw_pos_x, draw_pos_y, &fmgr_image_cache_p->image_cache_list[cache_index]->bmp);
        }

        /* make other unused duration increase one */
        for (i = 0; i < fmgr_image_cache_p->image_cache_item_count; i++)
        {
            fmgr_image_cache_p->image_cache_list[i]->unused_duration++;
        }

        fmgr_image_cache_p->image_cache_list[cache_index]->unused_duration = 0;

    }
    else
    {
        /* not in cache */
        bg_color = wgui_fmgr_get_bg_color(is_hilighted, ui_style);

        wgui_fmgr_redraw_image_background(
            is_hilighted, ui_style, bg_color, 
            box_offset_x + 1, 
            box_offset_y + 1, 
            box_offset_x + box_width - 1, 
            box_offset_y + box_height - 1);

        gdi_image_draw(icon_offset_x, icon_offset_y, icon_ptr);

        /* Start of Marco for switch case */
#define FMGR_DELAY_DECODER_SWITCH(_idx_)                                                                    \
         case _idx_:                                                                                              \
        {                                                                                                        \
        StartTimer(FMGR_DELAY_DECODE_##_idx_, FMGR_UI_DELAY_DECODE_DURATION, wgui_fmgr_delay_decode_##_idx_##);\
        fmgr_cat_context.delay_decoder[##_idx_##].item_idx            = item_idx;                               \
        fmgr_cat_context.delay_decoder[##_idx_##].menuitem_offset_x   = menuitem_offset_x;                      \
        fmgr_cat_context.delay_decoder[##_idx_##].menuitem_offset_y   = menuitem_offset_y;                      \
        fmgr_cat_context.delay_decoder[##_idx_##].box_offset_x        = box_offset_x;                           \
        fmgr_cat_context.delay_decoder[##_idx_##].box_offset_y        = box_offset_y;                           \
        fmgr_cat_context.delay_decoder[##_idx_##].box_width           = box_width;                              \
        fmgr_cat_context.delay_decoder[##_idx_##].box_height          = box_height;                             \
        fmgr_cat_context.delay_decoder[##_idx_##].icon_offset_x       = icon_offset_x;                          \
        fmgr_cat_context.delay_decoder[##_idx_##].icon_offset_y       = icon_offset_y;                          \
        fmgr_cat_context.delay_decoder[##_idx_##].icon_width          = icon_width;                             \
        fmgr_cat_context.delay_decoder[##_idx_##].icon_height         = icon_height;                            \
        fmgr_cat_context.delay_decoder[##_idx_##].icon_ptr            = icon_ptr;                               \
        fmgr_cat_context.delay_decoder[##_idx_##].is_hilighted        = is_hilighted;                           \
        fmgr_cat_context.delay_decoder[##_idx_##].ui_style            = ui_style;                               \
        break;                                                                                                \
        }
        /* end of Macro */
        
        /* start delay decode timer */
        switch (fmgr_cat_context.delay_decode_index)
        {
            FMGR_DELAY_DECODER_SWITCH(0);
            FMGR_DELAY_DECODER_SWITCH(1);
            FMGR_DELAY_DECODER_SWITCH(2);
            FMGR_DELAY_DECODER_SWITCH(3);
            FMGR_DELAY_DECODER_SWITCH(4);
            FMGR_DELAY_DECODER_SWITCH(5);
            FMGR_DELAY_DECODER_SWITCH(6);
            FMGR_DELAY_DECODER_SWITCH(7);
            FMGR_DELAY_DECODER_SWITCH(8);
            FMGR_DELAY_DECODER_SWITCH(9);
        default:
            MMI_ASSERT(0);
        }

        fmgr_cat_context.delay_decode_index++;

    }

    gui_pop_clip();
#endif /* defined(FMGR_USING_CACHE) */ 

    return TRUE;
}



#if defined(FMGR_USING_CACHE)
/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_decode_thumb_image_reulst_hdlr
 * DESCRIPTION
 *  decode image result handler
 * PARAMETERS
 *  decode_result       [IN]        Return cause
 *  handle              [IN]        Image's handle
 * RETURNS
 *  void
 * BOOL
 *****************************************************************************/
void wgui_fmgr_get_fmgr_cache_struct (void** image_cache_list_buffer_p,
                                     void** image_handle_list_buffer_p,
                                     void** image_cache_p,
                                     void** delay_decoder_p)
{
   *image_cache_list_buffer_p = (void*) &image_cache_list_buffer[0];
   *image_handle_list_buffer_p = (void*) &image_handle_list_buffer[0];
   *image_cache_p = (void*) fmgr_image_cache_p;
   *delay_decoder_p = (void*) fmgr_delay_decoder_p;
}
#endif /* #if defined(FMGR_USING_CACHE) */


#if defined(FMGR_USING_CACHE)
/*****************************************************************************
 * FUNCTION
 *  wgui_fmgr_decode_thumb_image_after_frame
 * DESCRIPTION
 *  decode image after frame handler
 * PARAMETERS
 *  result              [IN]        Return cause
 *  handle              [IN]        Image's handle
 * RETURNS
 *  void
 * BOOL
 *****************************************************************************/
void wgui_fmgr_decode_thumb_image_after_frame(GDI_RESULT result,gdi_handle handle)
{
    S32 i;
    gdi_color bg_color = GDI_COLOR_BLACK;
    wgui_fmgr_thumb_image_handle_struct *handle_ptr;
    
    if (fmgr_cat_context.is_decoder_create == FALSE || fmgr_cat_context.decoding_count == 0)
    {
        return;
    }
    
    gui_push_clip();
    gui_reset_clip();

    if (result != GDI_JPEG_SUCCEED)
    {
        for (i = 0; i < FMGR_THUMB_IMAGE_HANDLE_MAX_COUNT; i++)
        {
            if ((fmgr_image_cache_p->image_handle_list[i]->is_used == TRUE) &&
                (fmgr_image_cache_p->image_handle_list[i]->handle == handle))
            {
                /* decode failed */
                handle_ptr = fmgr_image_cache_p->image_handle_list[i];

                bg_color = wgui_fmgr_get_bg_color(
                    handle_ptr->is_hilighted, 
                    handle_ptr->ui_style);
                
                wgui_fmgr_redraw_image_background(                
                    handle_ptr->is_hilighted, 
                    handle_ptr->ui_style,
                    bg_color,
                    handle_ptr->draw_pos_x,
                    handle_ptr->draw_pos_y,
                    handle_ptr->draw_pos_x + handle_ptr->resized_width,
                    handle_ptr->draw_pos_y + handle_ptr->resized_height); 
                
                gdi_image_draw(handle_ptr->icon_offset_x,
                               handle_ptr->icon_offset_y,
                               handle_ptr->icon_ptr);                
                break;  /* break the loop */
            }
        }
    }
    gui_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_fmgr_decode_thumb_image_result_hdlr
 * DESCRIPTION
 *  decode image result handler
 * PARAMETERS
 *  decode_result       [IN]        Return cause
 *  handle              [IN]        Image's handle
 * RETURNS
 *  void
 * BOOL
 *****************************************************************************/
void wgui_fmgr_decode_thumb_image_result_hdlr(GDI_RESULT decode_result, gdi_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    S32 cache_entry_idx = 0;
    S32 max_unused_duration = 0;
    S32 unused_duration;
    S32 min_seq_number;
    BOOL has_cache_entry;
    gdi_color bg_color = GDI_COLOR_BLACK;
    S32 image_x1, image_y1, image_x2, image_y2;
    S32 clear_x1, clear_y1, clear_x2, clear_y2; /* previous region need to clear */
    S32 blt_x1, blt_y1, blt_x2, blt_y2;

    wgui_fmgr_thumb_image_handle_struct *handle_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* if decoder is deinited, ignore the decode result hdlr */
    if (fmgr_cat_context.is_decoder_create == FALSE || fmgr_cat_context.decoding_count == 0)
    {
        return;
    }
    
    gui_push_clip();
    gui_reset_clip();

    if (decode_result != GDI_JPEG_SUCCEED)
    {
        for (i = 0; i < FMGR_THUMB_IMAGE_HANDLE_MAX_COUNT; i++)
        {
            if ((fmgr_image_cache_p->image_handle_list[i]->is_used == TRUE) &&
                (fmgr_image_cache_p->image_handle_list[i]->handle == handle))
            {
                /* decode failed */
                handle_ptr = fmgr_image_cache_p->image_handle_list[i];

                wgui_cat21x_set_displayable(handle_ptr->menuitem_idx, MMI_FALSE);
                fmgr_image_cache_p->image_handle_list[i]->is_used = FALSE;

                bg_color = wgui_fmgr_get_bg_color(
                    fmgr_image_cache_p->image_handle_list[i]->is_hilighted, 
                    fmgr_image_cache_p->image_handle_list[i]->ui_style);
                
                wgui_fmgr_redraw_image_background(                
                    fmgr_image_cache_p->image_handle_list[i]->is_hilighted, 
                    fmgr_image_cache_p->image_handle_list[i]->ui_style,
                    bg_color,
                    fmgr_image_cache_p->image_handle_list[i]->draw_pos_x,
                    fmgr_image_cache_p->image_handle_list[i]->draw_pos_y,
                    fmgr_image_cache_p->image_handle_list[i]->draw_pos_x + fmgr_image_cache_p->image_handle_list[i]->resized_width,
                    fmgr_image_cache_p->image_handle_list[i]->draw_pos_y + fmgr_image_cache_p->image_handle_list[i]->resized_height); 
                
                gdi_image_draw(fmgr_image_cache_p->image_handle_list[i]->icon_offset_x,
                               fmgr_image_cache_p->image_handle_list[i]->icon_offset_y,
                               fmgr_image_cache_p->image_handle_list[i]->icon_ptr);                
                break;  /* break the loop */
            }
        }
    }
    else
    {
        for (i = 0; i < FMGR_THUMB_IMAGE_HANDLE_MAX_COUNT; i++)
        {
            if ((fmgr_image_cache_p->image_handle_list[i]->is_used == TRUE) &&
                (fmgr_image_cache_p->image_handle_list[i]->handle == handle))
            {
                /* 
                 * decode success,
                 * (1) Stop animated icon
                 * (1) Wipe out icon by backgroup color.
                 * (2) Draw photo frame.
                 * (3) Find an oldest image cache, and cache the image. 
                 */

                handle_ptr = fmgr_image_cache_p->image_handle_list[i];

                image_x1 = handle_ptr->draw_pos_x;
                image_y1 = handle_ptr->draw_pos_y;
                image_x2 = handle_ptr->draw_pos_x + handle_ptr->resized_width - 1;
                image_y2 = handle_ptr->draw_pos_y + handle_ptr->resized_height - 1;

                /* clear icon by bg color */
                /* since photo is already draw, only draw region not coverd by photo */
                if ((handle_ptr->ui_style == MMI_FMGR_GUI_LIST_STYLE) || (handle_ptr->ui_style == MMI_FMGR_GUI_INFO_STYLE))
                {
                    clear_x1 = handle_ptr->icon_offset_x;
                    clear_y1 = handle_ptr->icon_offset_y;
                    clear_x2 = handle_ptr->icon_offset_x + handle_ptr->icon_width - 1;
                    clear_y2 = handle_ptr->icon_offset_y + handle_ptr->icon_height - 1;
                }
                else    /* matrix */
                {
                    clear_x1 = handle_ptr->box_offset_x;
                    clear_y1 = handle_ptr->box_offset_y;
                    clear_x2 = handle_ptr->box_offset_x + handle_ptr->box_width - 1;
                    clear_y2 = handle_ptr->box_offset_y + handle_ptr->box_height - 1;
                }

                /* stop animated icon */
                //                              if(handle_ptr->is_hilighted)
                //                              {
                //                                      gdi_image_stop_animation_all();
                //                              }

                /* clear icon by bg color */
                /* since photo is already draw, only draw region not coverd by photo */
                bg_color = wgui_fmgr_get_bg_color(handle_ptr->is_hilighted, handle_ptr->ui_style);
                
                /* left region */
                if (clear_x1 < image_x1 - 1)
                {
                    
                    wgui_fmgr_redraw_image_background(
                        handle_ptr->is_hilighted, handle_ptr->ui_style, bg_color,
                        clear_x1, clear_y1, image_x1 - 1, clear_y2);
                }
                
                /* right region */
                if (clear_x2 > image_x2 + 1)
                {
                    wgui_fmgr_redraw_image_background(
                        handle_ptr->is_hilighted, handle_ptr->ui_style, bg_color,
                        image_x2 + 1, clear_y1, clear_x2, clear_y2);
                }
                
                /* up region */
                if (clear_y1 < image_y1 - 1)
                {
                    wgui_fmgr_redraw_image_background(
                        handle_ptr->is_hilighted, handle_ptr->ui_style, bg_color,
                        clear_x1, clear_y1, clear_x2, image_y1 - 1);
                }
                
                /* down region */
                if (clear_y2 > image_y2 + 1)
                {
                    wgui_fmgr_redraw_image_background(
                        handle_ptr->is_hilighted, handle_ptr->ui_style, bg_color,
                        clear_x1, image_y2 + 1, clear_x2, clear_y2);
                }
                
                /* draw frame */
                gdi_draw_rect(image_x1 - 1, image_y1 - 1, image_x2 + 1, image_y2 + 1, GDI_COLOR_BLACK);

                if (handle_ptr->ui_style == MMI_FMGR_GUI_MATRIX_STYLE)
                {
                    /* 2 pixels . 1 for border, 1 for spacing */
                    blt_x1 = (image_x1 - 2 > clear_x1) ? clear_x1 : image_x1 - 2;
                    blt_y1 = (image_y1 - 2 > clear_y1) ? clear_y1 : image_y1 - 2;
                    blt_x2 = (image_x2 + 2 > clear_x2) ? image_x2 + 2 : clear_x2;
                    blt_y2 = (image_y2 + 2 > clear_y2) ? image_y2 + 2 : clear_y2;
                }
                else
                {
                    /* calc max blt region (+1 for photo frame) */
                    blt_x1 = (image_x1 - 1 > clear_x1) ? clear_x1 : image_x1 - 1;
                    blt_y1 = (image_y1 - 1 > clear_y1) ? clear_y1 : image_y1 - 1;
                    blt_x2 = (image_x2 + 1 > clear_x2) ? image_x2 + 1 : clear_x2;
                    blt_y2 = (image_y2 + 1 > clear_y2) ? image_y2 + 1 : clear_y2;
                }

                gdi_layer_blt_previous(blt_x1, blt_y1, blt_x2, blt_y2);

                /* check if has valid cache index */
                has_cache_entry = FALSE;
                for (j = 0; j < fmgr_image_cache_p->image_cache_item_count; j++)
                {
                    if (fmgr_image_cache_p->image_cache_list[j]->is_used == FALSE)
                    {
                        has_cache_entry = TRUE;
                        cache_entry_idx = j;
                        break;
                    }
                }

                /* if not in cache, we will replace the oldest one in cache */
                if (!has_cache_entry)
                {
                    /* find max unused counter */
                    max_unused_duration = 0;
                    for (j = 0; j < fmgr_image_cache_p->image_cache_item_count; j++)
                    {
                        if (fmgr_image_cache_p->image_cache_list[j]->is_used == TRUE)
                        {
                            unused_duration = fmgr_image_cache_p->image_cache_list[j]->unused_duration;
                            max_unused_duration =
                                (max_unused_duration > unused_duration) ? max_unused_duration : unused_duration;
                        }
                    }

                    min_seq_number = 65535;
                    /* find the one with max unused duration will the smallest decode seq number */
                    for (j = 0; j < fmgr_image_cache_p->image_cache_item_count; j++)
                    {
                        if ((fmgr_image_cache_p->image_cache_list[j]->is_used == TRUE) &&
                            (fmgr_image_cache_p->image_cache_list[j]->unused_duration == max_unused_duration))
                        {
                            /* find the one with smallest seq number, which means is the oldest */
                            if (fmgr_image_cache_p->image_cache_list[j]->seq_number < min_seq_number)
                            {
                                cache_entry_idx = j;
                                min_seq_number = fmgr_image_cache_p->image_cache_list[j]->seq_number;
                            }
                        }
                    }
                }

                /* increase decode seq number */
                if (fmgr_image_cache_p->image_decode_seq_num >= 65534)
                {
                    fmgr_image_cache_p->image_decode_seq_num = 0;
                }
                else
                {
                    fmgr_image_cache_p->image_decode_seq_num++;
                }

                gdi_image_cache_bmp_get(
                    handle_ptr->draw_pos_x,
                    handle_ptr->draw_pos_y,
                    handle_ptr->draw_pos_x + handle_ptr->resized_width - 1,
                    handle_ptr->draw_pos_y + handle_ptr->resized_height - 1,
                    &fmgr_image_cache_p->image_cache_list[cache_entry_idx]->bmp);

                fmgr_image_cache_p->image_cache_list[cache_entry_idx]->is_used = TRUE;
                fmgr_image_cache_p->image_cache_list[cache_entry_idx]->unused_duration = 0;
                fmgr_image_cache_p->image_cache_list[cache_entry_idx]->menuitem_idx = handle_ptr->menuitem_idx;
                fmgr_image_cache_p->image_cache_list[cache_entry_idx]->resized_offset_x = handle_ptr->resized_offset_x;
                fmgr_image_cache_p->image_cache_list[cache_entry_idx]->resized_offset_y = handle_ptr->resized_offset_y;
                fmgr_image_cache_p->image_cache_list[cache_entry_idx]->resized_width = handle_ptr->resized_width;
                fmgr_image_cache_p->image_cache_list[cache_entry_idx]->resized_height = handle_ptr->resized_height;
                fmgr_image_cache_p->image_cache_list[cache_entry_idx]->seq_number =
                    fmgr_image_cache_p->image_decode_seq_num;

                fmgr_image_cache_p->image_handle_list[i]->is_used = FALSE;

                break;  /* break the for loop */
            }           /* if */
        }               /* for */
    }                   /* if */

    gui_pop_clip();
    
    ASSERT(fmgr_cat_context.decoding_count>0);

    fmgr_cat_context.decoding_count--;

    /* check if background decoding finish: unlock wgui status icon*/
    /*if(fmgr_cat_context.decoding_count==0)
        wgui_status_icon_unlock_redrawing();*/

}
#endif /* defined(FMGR_USING_CACHE) */ 

static PU8 cat266_file_icon_ptr;

/*****************************************************************************
 * FUNCTION
 *  wgui_cat266_draw_controlarea
 * DESCRIPTION
 *  Draw title and status, and flattern to scr bg layer.
 * PARAMETERS
 *  coordinate          [IN]    Useless, we have pre-defined area
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat266_draw_controlarea(dm_coordinates *coordinate)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 image_width;
    S32 image_height;
    S32 box_width, box_height;
    S32 box_offset_x, box_offset_y;
	S32 icon_offset_x, icon_offset_y;
	S32 x1, y1, x2, y2;
	GDI_HANDLE handle0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	handle0 = dm_get_layer_handle(0);

	gdi_layer_push_and_set_active(handle0);

	gdi_layer_lock_frame_buffer();

	x1 = 0;
	x2 = UI_device_width - 1;
	y1 = MMI_SUBMENU_CONTENT_Y;
	y2 = (MMI_SUBMENU_CONTENT_Y) + cat212_info_box_height - 1;

#if defined(__MMI_MAINLCD_128X128__)  
    gui_fill_rectangle(
        0,
        (MMI_SUBMENU_CONTENT_Y),
        UI_device_width - 1,
        (MMI_SUBMENU_CONTENT_Y) + cat212_info_box_height - 1,
        gui_color(255, 255, 255));
    gui_draw_rectangle(
        0,
        (MMI_SUBMENU_CONTENT_Y),
        UI_device_width - 1,
        (MMI_SUBMENU_CONTENT_Y) + cat212_info_box_height - 1,
        gui_color(0, 0, 0));
#else
    DrawTextAreaBackground(
        0,
        (MMI_SUBMENU_CONTENT_Y),
        UI_device_width - 1, 
        (MMI_SUBMENU_CONTENT_Y) + cat212_info_box_height - 1);
#endif
    box_height = y2 - y1 - FMGR_UI_IMAGE_BOX_SPACING * 2 + 1;
    box_width = box_height;

    box_offset_y = FMGR_UI_IMAGE_BOX_SPACING;

    if (r2lMMIFlag)
    {
        box_offset_x = x2 - box_width - FMGR_UI_IMAGE_BOX_SPACING;
    }
    else
    {
        box_offset_x = FMGR_UI_IMAGE_BOX_SPACING;
    }

    gui_measure_image(cat266_file_icon_ptr, &image_width, &image_height);
    icon_offset_x = ((box_width - image_width) >> 1) + x1 + box_offset_x;
    icon_offset_y = ((box_height - image_height) >> 1) + y1 + box_offset_y;
    gdi_image_draw(icon_offset_x, icon_offset_y, cat266_file_icon_ptr);

	gdi_layer_unlock_frame_buffer();
	gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
	gdi_layer_pop_and_restore_active();
}

/*****************************************************************************
 * FUNCTION
 *  ExitCategory266Screen
 * DESCRIPTION
 *  Exits the category266 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory266Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_hide_animations();
    wgui_category_screen_no_buttons = 0;
    category_screen_layout_flags = 0;
	cat212_info_box_height = 0;
	cat266_file_icon_ptr = NULL;
}   /* end of ExitCategory66Screen */


/*****************************************************************************
 * FUNCTION
 *  ShowCategory266Screen
 * DESCRIPTION
 *  Displays the category266 screen
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon shown with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Icon for the left softkey
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Icon for the right softkey
 *  message                 [IN]        Notification message
 *  message_icon            [IN]        Message icon
 *  num_of_info_box_rows    [IN]        How many row (height) for info box
 *  info_icon_id            [IN]        Icon id of info box
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory266Screen(
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
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    S32 l = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	cat212_info_box_height = num_of_info_box_rows * MMI_ICONTEXT_MENUITEM_HEIGHT - 1;
	cat266_file_icon_ptr = get_image(info_icon_id);
    gdi_layer_lock_frame_buffer();

    dm_data.s32flags = 0;
	dm_add_softkey(
		get_string(left_softkey),
		get_image(left_softkey_icon),
		get_string(right_softkey),
		get_image(right_softkey_icon));

    if ((left_softkey == 0) && (left_softkey_icon == 0) && (right_softkey == 0) && (right_softkey_icon == 0))
    {
        dm_data.s32flags |= DM_NO_SOFTKEY;
    }
        
    MMI_title_string = (UI_string_type) get_string(title);
    MMI_title_icon = (PU8) get_image(title_icon);

    MMI_message_string = (UI_string_type) message;
    l = gui_strlen(MMI_message_string);
    create_multiline_inputbox_set_buffer(MMI_message_string, l, l, 0);
	MMI_multiline_inputbox.normal_text_color = *current_MMI_theme->popup_text_color;
    MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW
        | UI_MULTI_LINE_INPUT_BOX_CENTER_JUSTIFY
        | UI_MULTI_LINE_INPUT_BOX_DISABLE_BACKGROUND
        | UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR | UI_MULTI_LINE_INPUT_BOX_VIEW_MODE;
    MMI_multiline_inputbox.ext_flags |= GUI_MULTI_LINE_INPUT_BOX_TRUNCATE_CONTENT;
        
    if (message_icon)
    {
        dm_add_image(get_image(message_icon), NULL, NULL);
    }

    gdi_layer_unlock_frame_buffer();

    ExitCategoryFunction = ExitCategory266Screen;
    dm_setup_category_functions(dm_redraw_category_screen, dm_get_category_history, dm_get_category_history_size);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY266_ID;
    dm_data.s32flags |= DM_CLEAR_SCREEN_BACKGROUND;
	dm_register_category_controlled_callback(wgui_cat266_draw_controlarea);
    dm_setup_data(&dm_data);
    dm_redraw_category_screen();

}   /* end of ShowCategory266Screen */



