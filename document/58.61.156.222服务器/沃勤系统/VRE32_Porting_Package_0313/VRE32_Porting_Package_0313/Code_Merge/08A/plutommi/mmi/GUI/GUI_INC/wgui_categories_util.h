/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 * Wgui_categories_util.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for common utilities for categoires.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *     HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef __WGUI_CATEGORIES_UTIL_H__
#define __WGUI_CATEGORIES_UTIL_H__

#include "MMI_features.h"
#include "CustMenuRes.h"
#include "gui_config.h"
#include "wgui.h"
#include "gui_menu_shortcut.h"
#include "gui_title.h"
#include "wgui_inputs.h"
#include "wgui_inline_edit.h"
#include "wgui_categories_defs.h"

#include "gui_typedef.h"

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
extern U8 *dummy_get_history(U8 *buffer);
extern S32 dummy_get_history_size(void);

extern PU8 get_image(MMI_ID_TYPE i);
extern U8 *get_audio(MMI_ID_TYPE i, U8 *type, U32 *filelen);  /* audio resource */
extern UI_string_type get_string(MMI_ID_TYPE i);

extern void initialize_category_screens(void);
extern void reset_category_functions(void);
extern void SetCategoryScreenLayout(U32 flags);

extern void wgui_show_animation(void);
extern void wgui_show_transparent_animation(void);
extern void wgui_set_animation(S32 x, S32 y, MMI_ID_TYPE img);
extern void wgui_set_animation_y(S32 x, S32 y, MMI_ID_TYPE img);
extern void wgui_set_animation_image(S32 x, S32 y, PU8 img);
extern void wgui_set_animation_image_y(S32 x, S32 y, PU8 img);
extern void wgui_measure_set_animation(S32 x, S32 y, S32 *width, S32 *height, MMI_ID_TYPE img);
extern void wgui_measure_set_animation_y(S32 x, S32 y, S32 *width, S32 *height, MMI_ID_TYPE img);
extern void wgui_measure_set_animation_image(S32 x, S32 y, S32 *width, S32 *height, PU8 img);
extern void wgui_measure_set_animation_image_y(S32 x, S32 y, S32 *width, S32 *height, PU8 img);
extern void wgui_hide_animation(void);

extern void wgui_fill_rectangle_clip(S32 x1, S32 y1, S32 x2, S32 y2, color c);
extern void clear_screen(void);
extern void clear_screen_with_color(color c);
extern void clear_buttonbar(void);
extern void set_button_bar_height(S32 height);
extern void clear_contentarea(void);
extern void draw_arrow_indication(S8 left, S8 right, S8 up, S8 down);
extern void SetHighlightedItem(S32 item_index);
extern S32 GetHighlightedItem(void);
extern UI_string_type get_item_text(S32 index);
extern UI_string_type get_dynamic_item_text(S32 index);

#ifdef ENABLE_BOTTOM_NAVIGATION_KEYS
extern void gui_show_key_navigation(S32 index);
extern void gui_show_navigation_keys(void);
#endif /* ENABLE_BOTTOM_NAVIGATION_KEYS */ 
extern void DisableCategoryScreenScrollBar(void);
extern void SetupCategoryKeyHandlers(void);

extern void wgui_set_java_screen(void); /* Java title */
extern void wgui_unset_java_screen(void);
extern void entry_full_screen(void);
extern void leave_full_screen(void);
extern void in_idle_screen(void);
extern void leave_idle_screen(void);
extern MMI_BOOL if_full_screen_hide_status_icons(void);
extern void reset_title_status_icon(void);
extern void close_title_status_icon(void);
extern void show_title_status_icon(void);

extern U8 history_valid(U16 history_ID, U16 category_screen_ID);
extern void wgui_cat_block_list_effect(void);
extern void change_list_menu_category_history(U8 *history_buffer, S32 new_highlighted_index, S32 new_n_items, U8 flag);
extern void create_list_menu_category_history(
                S32 history_ID,
                U8 *history_buffer,
                S32 new_highlighted_index,
                S32 new_n_items,
                U8 flag);
extern U8 set_list_menu_category_history(U16 history_ID, U8 *history_buffer);
extern void set_list_menu_category_history_state(U16 history_ID, U8 *history_buffer, S8 state);        
extern void change_cat184_list_menu_history_highlighted_item(S32 index, U8 *history_buffer);   /* for SMS updating list */
extern void get_list_menu_category_history(U16 history_ID, U8 *history_buffer);
extern S32 get_list_menu_category_history_size(void);
extern S8 get_list_menu_category_history_state(U16 history_ID, U8 *history_buffer);    
extern U8 set_matrix_menu_category_history(U16 history_ID, U8 *history_buffer);
extern void get_matrix_menu_category_history(U16 history_ID, U8 *history_buffer);
extern U8 set_object_list_category_history(U16 history_ID, U8 *history_buffer, S32 *index);
extern void get_object_list_category_history(U16 history_ID, U8 *history_buffer, S32 *index);
extern void get_slide_control_category_history(U16 history_ID, U8 *history_buffer);
extern U8 set_slide_control_category_history(U16 history_ID, U8 *history_buffer);

extern void wgui_fixed_list_register_get_flags_handler(GetMenuitemFlags get_flags_handler);

/* for new list_matrix menu style */
#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
extern U8 set_list_matrix_menu_category_history(U16 history_ID, U8 *history_buffer);
extern void get_list_matrix_menu_category_history(U16 history_ID, U8 *history_buffer);
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 

extern void wgui_save_key_handlers(void);
extern void wgui_execute_key_handler(S32 key_code, S32 key_event);
extern void wgui_restore_key_handlers(void);

/* support wallpaper ob bottom */
extern void hide_status_icons_bar0_by_transparent(void);
extern void wgui_set_wallpaper_on_bottom(MMI_BOOL state);
extern void wgui_reset_wallpaper_on_bottom(void);
extern MMI_BOOL wgui_is_wallpaper_on_bottom(void);


extern void ShowStatusIconsTitle(void);


extern void resize_fixed_list_to_content_height(void);
extern void toggle_check_list_handle_left_softkey_up(void);
extern void special_check_list_handle_left_softkey_up(void);
extern void toggle_check_list_handle_item_select(S32 h);
void SetCheckboxToggleRightSoftkeyFunctions(void (*done_function) (void), void (*back_function) (void));
extern void standard_check_list_handle_item_select(S32 h);
extern void standard_check_list_handle_left_softkey_up(void);
extern void standard_check_list_handle_left_softkey_up(void);

void RegisterHighlightHandler(void (*f) (S32 item_index));
extern void MMI_dummy_highlight_handler(S32 item_index);
extern void ClearHighlightHandler(void);

extern void wgui_override_list_menu_slim_style(wgui_list_menu_slim_style_enum style);
extern void wgui_restore_list_menu_slim_style(void);

extern void wgui_slide_control_set_focus(slide_control *s);
extern void wgui_show_slide_control(void);
extern void wgui_show_slide_control_focus(void);
extern void wgui_hide_slide_control_focus(void);
extern void wgui_slide_control_previous(void);
extern void wgui_slide_control_next(void);
extern void wgui_show_slide_control_value(S32 x1, S32 y1, S32 x2, S32 y2, S32 value);
extern void wgui_slide_control_set_value(S32 value);

extern U16 GetRootTitleIcon(U16 ItemId);

extern void MMI_apply_current_theme(void);

extern void show_vertical_bar(S32 volume_level);
extern void show_vertical_bar_previous(void);
extern void show_vertical_bar_next(void);

extern void set_multiline_inputbox_change(void);
extern S32 get_mutliline_inputbox_change_status(void);
extern void set_multiline_inputbox_change_callback(void);

#ifdef __MMI_UI_HINTS_IN_MENUITEM__
extern UI_string_type wgui_get_current_pop_up_description_string(void);

extern void set_force_all_hints_in_menuitem(void);
extern void reset_force_all_hints_in_menuitem(void);
extern S32 is_set_force_all_hints_in_menuitem(void);

extern void set_force_hints_on_highlight_in_menuitem(void);
extern void reset_force_hints_on_highlight_in_menuitem(void);
extern S32 is_set_force_hints_on_highlight_in_menuitem(void);

extern void set_force_icon_on_highlight_only_in_menuitem(void);
extern void reset_force_icon_on_highlight_only_in_menuitem(void);
extern S32 is_set_force_icon_on_highlight_only_in_menuitem(void);

extern void reset_all_force_flags_for_hints(void);
#endif /* __MMI_UI_HINTS_IN_MENUITEM__ */ 

extern MMI_BOOL wgui_is_display_medium_font_string(U8* string, S32 len);

/*--------------------------------------------------------------------------------------------*/
/* Title                                                                                      */
/*--------------------------------------------------------------------------------------------*/
extern void wgui_title_change(U16 icon_ID, U16 icon2_ID, U8 *text, U32 flag);
extern void wgui_title_set_thick(MMI_BOOL thick); 
extern void draw_title(void);
extern void wgui_stop_title_animation(void);
extern void draw_title_wap(void);
extern void ChangeTitleString(U8 *string);
extern void ChangeTitleIcon(U16 image_ID);
extern void ChangeTitle(U16 image_ID, U8 *string);

#if defined(__MMI_TOUCH_SCREEN__)
extern void register_touch_button_handlers(FuncPtr f1_up, FuncPtr f1_down, FuncPtr f2_up, FuncPtr f2_down);
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 

extern void wgui_set_touch_title_bar_buttons(void);
extern void wgui_reset_touch_title_bar_buttons(void);
extern MMI_BOOL wgui_is_touch_title_bar_buttons(void);


/*--------------------------------------------------------------------------------------------*/
/* Status icons                                                                               */
/*--------------------------------------------------------------------------------------------*/

/* Application specific APIs  */

extern void ShowStatusIcon(S16 icon_ID);
extern void HideStatusIcon(S16 icon_ID);
extern void UpdateStatusIcons(void);
extern void UpdateSubLCDStatusIcons(void);
extern void ChangeStatusIconLevel(S16 icon_ID, U8 level_percentage);
extern void ChangeStatusIconImage(S16 icon_ID, U16 image_ID);       
extern void AnimateStatusIcon(S16 icon_ID);
extern void BlinkStatusIcon(S16 icon_ID);

#ifdef __MMI_TOUCH_SCREEN__
extern void wgui_register_status_icon_pen_event_hdlr(
                S16 icon_id,
                wgui_status_icon_bar_pen_enum event_type,
                FuncPtr f);
extern MMI_BOOL wgui_execute_status_icon_pen_event_hdlr(S16 icon_id, wgui_status_icon_bar_pen_enum event_type);
extern void wgui_reset_status_icon_pen_event_hdlr(void);
extern BOOL wgui_status_icon_translate_pen_event(
                mmi_pen_event_type_enum pen_event,
                S16 x,
                S16 y,
                S16 *icon_id,
                wgui_status_icon_bar_pen_enum *event_type);
#endif /* __MMI_TOUCH_SCREEN__ */ 


/*--------------------------------------------------------------------------------------------*/
/* Menu                                                                                  */
/*--------------------------------------------------------------------------------------------*/

//wgui_dynamic_menus.h
extern void DynamicListIncreaseItem(S16 steps);
extern S32 DynamicListGetItems(U8 *string, U16 item_index);
extern S32 DynamicListGetHighlightedItem(U8 *string);
extern S32 DynamicGetFirstDisplayedItem(U8 *string);

#ifdef __MMI_UI_TWO_LINE_MENUITEM_STYLES__
extern void wgui_set_pfn_to_get_current_menu_item_properties(wgui_get_two_line_menu_item_properties pfn);
extern void wgui_set_pfn_to_get_display_style(wgui_get_display_style pfn);
#endif /* __MMI_UI_TWO_LINE_MENUITEM_STYLES__ */ 


/*--------------------------------------------------------------------------------------------*/
/* calendar                                                                                   */
/*--------------------------------------------------------------------------------------------*/
/* Calendar wrappers        */
extern void wgui_calendar_set_bg(UI_image_ID_type bg_id);
extern void wgui_calendar_set_select_horizontal1(
            UI_image_ID_type left_up,
            UI_image_ID_type left_down,
            UI_image_ID_type right_up,
            UI_image_ID_type right_down,
            U8 left_filler_index,
            U8 right_filler_index,
            U8 *string,
            U32 align_type);
extern void wgui_calendar_set_select_horizontal1_string(U8 *string);
extern void wgui_calendar_set_select_horizontal1_handler(
            GUICalendarV2EventFuncPtr left_handler,
            GUICalendarV2EventFuncPtr right_handler);
extern void wgui_calendar_set_select_horizontal2(
            UI_image_ID_type left_up,
            UI_image_ID_type left_down,
            UI_image_ID_type right_up,
            UI_image_ID_type right_down,
            U8 left_filler_index,
            U8 right_filler_index,
            U8 *string,
            U32 align_type);
extern void wgui_calendar_set_select_horizontal2_string(U8 *string);
extern void wgui_calendar_set_select_horizontal2_handler(
            GUICalendarV2EventFuncPtr left_handler,
            GUICalendarV2EventFuncPtr right_handler);
extern void wgui_calendar_set_select_vertical(
            UI_image_ID_type top_up,
            UI_image_ID_type top_down,
            UI_image_ID_type bottom_up,
            UI_image_ID_type bottom_down,
            U8 **string_list,
            U32 align_type);
extern void wgui_calendar_set_select_vertical_string(U8 **string_list);
extern void wgui_calendar_set_select_vertical_handler(
            GUICalendarV2EventFuncPtr top_handler,
            GUICalendarV2EventFuncPtr bottom_handler);
extern void wgui_calendar_set_normal_title(U8 *string);
extern void wgui_calendar_set_menstrual_title(U8 color_index1, U8 *string1, U8 color_index2, U8 *string2);
extern void wgui_calendar_set_horizontal_string(U8 **string_list, S32 underline_index);
extern void wgui_calendar_set_cell_array(
            gui_calendar_cell_struct *cell,
            U8 cell_bg_fill_type,
            U8 cell_text_display_type,
            U8 cell_icon_display_type);
extern void wgui_calendar_set_current(U32 current_row, U32 current_column);
extern void wgui_calendar_set_highlight(U32 highlighted_row, U32 highlighted_column);
extern void wgui_calendar_set_popup(U8 *message1, U8 *message2, U8 *message3);
#ifdef __MMI_UI_CALENDAR_WITH_INFO_BOX__
extern void wgui_calendar_set_infobox(UI_image_ID_type *icon_list, U8 **string_list, U8 entry_num);
#endif /*__MMI_UI_CALENDAR_WITH_INFO_BOX__*/
extern void wgui_calendar_register_cell_highlight_handler(MMI_BOOL (*app_cell_highlight_handler)(U32 highlighted_row, U32 highlighted_column));
extern void wgui_calendar_register_left_arrow_key_handler(MMI_BOOL (*app_left_arrow_key_handler)(U32 highlighted_row, U32 highlighted_column));
extern void wgui_calendar_register_right_arrow_key_handler(MMI_BOOL (*app_right_arrow_key_handler)(U32 highlighted_row, U32 highlighted_column));
extern void wgui_calendar_register_up_arrow_key_handler(MMI_BOOL (*app_up_arrow_key_handler)(U32 highlighted_row, U32 highlighted_column));
extern void wgui_calendar_register_down_arrow_key_handler(MMI_BOOL (*app_down_arrow_key_handler)(U32 highlighted_row, U32 highlighted_column));
extern void wgui_calendar_register_up_side_key_handler(MMI_BOOL (*app_up_side_key_handler)(U32 highlighted_row, U32 highlighted_column));
extern void wgui_calendar_register_down_side_key_handler(MMI_BOOL (*app_down_side_key_handler)(U32 highlighted_row, U32 highlighted_column));

/*--------------------------------------------------------------------------------------------*/
/* datetime                                                                                   */
/*--------------------------------------------------------------------------------------------*/
/* datetime */
extern void date_string(UI_time *t, UI_string_type s, U32 flags);
extern void time_string(UI_time *t, UI_string_type s, U32 flags);
extern void duration_string(UI_time *t, UI_string_type s, U32 flags);
extern void update_mainlcd_dt_display(void); /* this api will be moved in the future */
extern void update_sublcd_dt_display(void); /* this api will be moved in the future */
extern void wgui_datetime_update_mainlcd_cm_duration(void);
#ifdef __MMI_SOUND_RECORDER__
    extern void set_time_duration(UI_time *t, U32 duration);
    extern void get_time_duration(UI_time *t);
    extern void time_display_duration(void);
    extern void time_update_duration(void);
    extern void set_time_display(U32 flags, S32 x, S32 y, S32 width, S32 height);
    extern void close_main_LCD_time_display(void);
#endif /* __MMI_SOUND_RECORDER__ */

extern void Cat19UpdateDuration(MYTIME *t);

#ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
extern void wgui_set_clock_type(U8 clock_type);
#endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */

/*--------------------------------------------------------------------------------------------*/
/* softkey                                                                                    */
/*--------------------------------------------------------------------------------------------*/
/* softkey */
#define set_left_softkey_function(FUNC, KEY_TYPE)       set_softkey_function(FUNC, KEY_TYPE, MMI_LEFT_SOFTKEY)
#define set_right_softkey_function(FUNC, KEY_TYPE)      set_softkey_function(FUNC, KEY_TYPE, MMI_RIGHT_SOFTKEY)
#define get_left_softkey_function(KEY_TYPE)             get_softkey_function(KEY_TYPE, MMI_LEFT_SOFTKEY)
#define get_right_softkey_function(KEY_TYPE)            get_softkey_function(KEY_TYPE, MMI_RIGHT_SOFTKEY)
#define execute_left_softkey_function(KEY_TYPE)         execute_softkey_function(KEY_TYPE,MMI_LEFT_SOFTKEY)
#define execute_right_softkey_function(KEY_TYPE)        execute_softkey_function(KEY_TYPE,MMI_RIGHT_SOFTKEY)
#define redraw_left_softkey()                           redraw_softkey(MMI_LEFT_SOFTKEY)
#define redraw_right_softkey()                          redraw_softkey(MMI_RIGHT_SOFTKEY)
#ifdef __MMI_WGUI_CSK_ENABLE__
#define redraw_center_softkey()                         redraw_softkey(MMI_CENTER_SOFTKEY)
#endif

extern void set_softkey_function(void (*f) (void), MMI_key_event_type k, WGUI_SOFTKEY_ENUM key);
extern FuncPtr get_softkey_function(MMI_key_event_type k, WGUI_SOFTKEY_ENUM key);
extern void execute_softkey_function(MMI_key_event_type k, WGUI_SOFTKEY_ENUM key);
extern void redraw_softkey(WGUI_SOFTKEY_ENUM key);

extern void ChangeLeftSoftkey(U16 s, U16 i);
extern void ChangeRightSoftkey(U16 s, U16 i);
extern void EnableLeftSoftkey(U16 s, U16 i);
extern void DisableLeftSoftkey(U16 s, U16 i);
extern void EnableRightSoftkey(U16 s, U16 i);
extern void DisableRightSoftkey(U16 s, U16 i);
extern void SetLeftSoftkeyFunction(void (*f) (void), MMI_key_event_type k);
extern void SetRightSoftkeyFunction(void (*f) (void), MMI_key_event_type k);

#ifdef __MMI_WGUI_CSK_ENABLE__
    extern void EnableCenterSoftkey(U16 s, U16 i);
    extern void ResetCenterSoftkey(void);
    extern void SetCenterSoftkeyFunction(void (*f) (void), MMI_key_event_type k);
    extern void ChangeCenterSoftkey(U16 s, U16 i);

#endif /* __MMI_WGUI_CSK_ENABLE__ */

/* Vogins Start */
#ifdef __VRE_V30__
extern U16 GetIconImageId(S16 icon_ID);
extern void ChangeStatusIconImageData(S16 icon_ID, PU8 image_data);
#endif
/* Vogins End */

#endif /* __WGUI_CATEGORIES_UTIL_H__ */ 

