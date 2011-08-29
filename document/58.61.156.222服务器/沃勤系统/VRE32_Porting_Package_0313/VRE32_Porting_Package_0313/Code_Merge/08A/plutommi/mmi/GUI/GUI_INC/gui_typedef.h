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
 *  gui_typedef.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*
 * This file contains internal UI component API, and is intended to be used by category screen module only. 
 * It's not recommended to be included in application code directly. 
 * For application developers, please include category screen header files instead (e.g., wgui_categories.h).
*/


#ifndef __GUI_TYPEDEF_H__
#define __GUI_TYPEDEF_H__
#include "mmi_features.h"
#include "gdi_include.h"
#include "GlobalConstants.h"
#include "wgui_categories_defs.h"
#include "wgui.h"

#if defined(__J2ME__)
#include "j2me_custom_option.h"
#endif /* defined(__J2ME__) */


/*--------------------------------------------------------------------------------------------*/
/* Menu                                                                                       */
/*--------------------------------------------------------------------------------------------*/

/***************************************************************************** 
 * Include 
 *****************************************************************************/


/***************************************************************************** 
 * Define
 *****************************************************************************/
//gui_fixed_menus.h
#define UI_DROP_DOWN_CONTROL_STATE_NORMAL               0x00000000
#define UI_DROP_DOWN_CONTROL_STATE_FOCUSSED             0x00000001
#define UI_DROP_DOWN_CONTROL_STATE_CLICKED              0x00000002
#define UI_DROP_DOWN_CONTROL_STATE_DISABLED             0x00000004
#define UI_DROP_DOWN_CONTROL_STATE_SELECTED             0x00000008
#define UI_DROP_DOWN_CONTROL_TEXT_LEFT_JUSTIFY          0x00000010
#define UI_DROP_DOWN_CONTROL_TEXT_RIGHT_JUSTIFY         0x00000020
#define UI_DROP_DOWN_CONTROL_TEXT_CENTER_JUSTIFY        0x00000040
#define UI_DROP_DOWN_CONTROL_DISABLE_BACKGROUND         0x00000100
#define UI_DROP_DOWN_CONTROL_DISABLE_DRAW               0x00000200
#define UI_DROP_DOWN_CONTROL_SHOW_BUTTON_ON_FOCUS       0x00000400


//guI_common_menus.h
/* common menu item flags */
#define UI_MENUITEM_STATE_NORMAL                0x00000000
#define UI_MENUITEM_STATE_FOCUSSED              0x00000001
#define UI_MENUITEM_STATE_SELECTED              0x00000002
#define UI_MENUITEM_STATE_DISABLED              0x00000004
#define UI_MENUITEM_STATE_ANIMATE               0x00000008
#define UI_MENUITEM_CENTER_TEXT_X               0x00000010
#define UI_MENUITEM_CENTER_TEXT_Y               0x00000020
#define UI_MENUITEM_FOCUSSED_SHIFT1             0x00000040
#define UI_MENUITEM_FOCUSSED_SHIFT2             0x00000080
#define UI_MENUITEM_CENTER_ICON_X               0x00000100
#define UI_MENUITEM_CENTER_ICON_Y               0x00000200
#define UI_MENUITEM_DISABLE_TEXT_DISPLAY        0x00000400
#define UI_MENUITEM_PEN_USE_LONGPRESS           0x00000800
#define UI_MENUITEM_ICONTEXT_LIST_ALL_TEXT_VERTICAL_ALIGN_CENTER 0x00000800
#define UI_MENUITEM_FOCUSSED_ANIMATE            0x00001000
#define UI_MENUITEM_SELECTED_ANIMATE            0x00002000
#define UI_MENUITEM_DISABLE_HIGHLIGHT           0x00004000
#define UI_MENUITEM_DISABLE_BACKGROUND          0x00008000
#define UI_MENUITEM_RIGHT_JUSTIFY               0x00010000
#define UI_MENUITEM_LEFT_JUSTIFY                0x00020000
#define UI_MENUITEM_MARQUEE_SCROLL              0x00040000
#define UI_MENUITEM_TWO_DIRECTION_SCROLL        0x00080000
#define UI_MENUITEM_DISABLE_BACKGROUND_ALWAYS   0x00100000
#define UI_MENUITEM_DISABLE_TEXT_CLIP           0x00200000
#define UI_MENUITEM_INLINE_EDIT_OBJECT          0x00400000
#define UI_MENUITEM_TEXT_COL1_IS_NUMBER         0x00400000 /* display "1." as ".1" in Arabic for category 89 */
#define UI_MENUITEM_FILL_COL1                   0x00800000
/* fill column 2 (icontext-list menuitem) */
#define UI_MENUITEM_FILL_COL2                   0x01000000
/* for new mainmenu category (icontext menuitem) */
#define UI_MENUITEM_DISABLE_HIGHLIGHT_DISPLAY   0x01000000
#define UI_MENUITEM_RIGHT_JUSTIFY_COL2          0x02000000
#define UI_MENUITEM_DISABLE_ICON                0x04000000
/* trucate too long number/name in call list */
#define UI_MENUITEM_TRUNCATE_CONTENT            0x08000000
/* to check the existance of multi-row menu list */
#define MENU_MUTLIROW_ICON_LIST                 0x10000000
#define UI_MENUITEM_DOTTED_UNDERLINE            0x20000000
/* for bi-degree main menu */
#define UI_MENUITEM_HIGHLIGHT_SWITCH_ICON       0x40000000
/* 
 * for icontext-list with multiple text columns. 
 * Scroll the first column that contains long text. 
 */
#define UI_MENUITEM_AUTO_CHOOSE_MARQUEE         0x80000000

/* 
 * extended menu-item flags in addition to 32 standard menuitem flags.
 */

/* item display function invoked from marquee */
#define UI_MENUITEM_EXT_SHOW_IN_MARQUEE         0x00000001
#define UI_MENUITEM_EXT_SHOW_IN_ROUNDED_RECT    0x00000002
#define UI_MENUITEM_SHOW_ALL_HINTS              0x00000004
#define UI_MENUITEM_SHOW_HIGHLIGHTED_HINT       0x00000008
#define UI_MENUITEM_SHOW_ICON_ONLY_ON_HIGHLIGHT 0x00000010
#define UI_MENUITEM_EXT_SHOW_TWO_LINE_SELECT    0x00000020
#define UI_MENUITEM_EXT_DISABLE_FOCUSSED_TEXT_DISPLAY   0x00000040
#define UI_MENUITEM_EXT_SHOW_ICONTEXT_CHECKBOX      0x00000080
#define UI_MENUITEM_EXT_CONTAIN_TWO_LINE_MENU_ITEM 0x00000100
#define UI_MENUITEM_EXT_SHOW_TIME                  0x00000200
#define UI_MENUITEM_EXT_SHOW_DATA                  0x00000400
#define UI_MENUITEM_EXT_SHOW_DISABLED              0x00000800
#define UI_MENUITEM_EXT_SHOW_UNDERLINE             0x00001000
#define UI_MENUITEM_EXT_SHOW_SEPARATORLINE         0x00002000
#define UI_MENUITEM_EXT_DISABLED_SCROLL            0x00004000

/* 
 * List menu flags 
 */
#define UI_LIST_MENU_STATE_NORMAL                  0x00000000
#define UI_LIST_MENU_STATE_FOCUSSED                0x00000001
#define UI_LIST_MENU_DISABLE_SCROLLBAR             0x00000002
#define UI_LIST_MENU_LOOP                          0x00000004
#define UI_LIST_MENU_DISABLE_BACKGROUND            0x00000008
#define UI_LIST_MENU_AUTO_DISABLE_SCROLLBAR        0x00000010
#define UI_LIST_MENU_DISABLE_DRAW                  0x00000020
#define UI_LIST_MENU_FIRST_SHIFT_HIGHLIGHTED_ITEM  0x00000040
#define UI_LIST_MENU_CENTER_HIGHLIGHTED            0x00000080
#define UI_LIST_MENU_LAST_SHIFT_HIGHLIGHTED_ITEM   0x00000100
#define UI_LIST_MENU_ENABLE_TRANSITION             0x00000200
#define UI_LIST_MENU_ALIGN_TO_TOP                  0x00000400
#define UI_LIST_MENU_DISABLE_CACHE_DYNAMIC_DATA    0x00000800
#define UI_LIST_MENU_DISABLE_BKGRND_IN_LAYER       0x00001000
#define UI_LIST_MENU_DISABLE_PEN                   0x00002000
#define UI_LIST_MENU_DISABLE_MENUITEM_GAP          0x00004000
#define UI_LIST_MENU_TRUNCATED_MENUITEM            0x00008000

/* 
 * Matrix menu flags 
 */
#define UI_MATRIX_MENU_STATE_NORMAL                0x00000000
#define UI_MATRIX_MENU_STATE_FOCUSSED              0x00000001
#define UI_MATRIX_MENU_DISABLE_SCROLLBAR           0x00000002
#define UI_MATRIX_MENU_AUTO_DISABLE_SCROLLBAR      0x00000010
#define UI_MATRIX_MENU_LOOP                        0x00000004
/* For matrix mainmenu vertical loop 1<->4<->7<->2<->5<->8... */
#define UI_MATRIX_MENU_VERTICAL_LOOP               0x00000008
#define UI_MATRIX_MENU_SHOW_VERTICAL_SCROLLBAR     0x00000100
#define UI_MATRIX_MENU_SHOW_HORIZONTAL_SCROLLBAR   0x00000200
/* For matrix mainmenu optimize */
#define UI_MATRIX_MENU_FOR_MAINMENU                0x00000400
#define UI_MATRIX_MENU_DISABLE_BACKGROUND          0x00000800
#define UI_MATRIX_MENU_FIRST_SHIFT_HIGHLIGHTED_ROW 0x00001000
#define UI_MATRIX_MENU_LAST_SHIFT_HIGHLIGHTED_ROW  0x00002000
#define UI_MATRIX_MENU_FIRST_SHIFT_HIGHLIGHTED_COL 0x00004000
#define UI_MATRIX_MENU_LAST_SHIFT_HIGHLIGHTED_COL  0x00008000
#define UI_MATRIX_MENU_SHOW_IND_AREA               0x00010000
/* Use callback function instead of looping on vertical highlight switching */
#define UI_MATRIX_MENU_VERTICAL_TRIGGER            0x00020000
#define UI_MATRIX_MENU_DISABLE_PEN                 0x00040000
/* 
 * Align menu items to left-top instead of scattered evenly in the center of the menu.
 * Typically used when menu item count < total row * column. 
 */
#define UI_MATRIX_MENU_ALIGN_LEFT_TOP              0x00080000
/* 
 * Horizontal selection
 */
#define UI_HORIZONTAL_SELECT_LOOP                  0x00010000
#define UI_HORIZONTAL_SELECT_NO_ITEM_HIGHLIGHTED   0x00020000


//wgui_fixed_menuitems.h
/* Limit the number of menu items by MAX_SUB_MENUS without wasting RAM. */
#define MAX_FIXED_TEXT_MENU_ITEMS           LIMIT_MENU_ITEM_NUMBER(100)
#define MAX_FIXED_ICONTEXT_MENU_ITEMS       LIMIT_MENU_ITEM_NUMBER(90)
#define MAX_FIXED_ICONTEXT_LIST_MENU_ITEMS  LIMIT_MENU_ITEM_NUMBER(72)
#define MAX_FIXED_TWOSTATE_MENU_ITEMS       LIMIT_MENU_ITEM_NUMBER(60)

#define TWO_LINE_MENUITEM_STYLE_DISPLAY_LEVEL_SELECT        1
#define TWO_LINE_MENUITEM_STYLE_DISPLAY_HORIZONTAL_SELECT   2

#define UI_TWO_LINE_MENUITEM_NO_THUMBNAIL           0x00
#define UI_TWO_LINE_MENUITEM_LEFT_ALIGN_THUMBNAIL   0x01
#define UI_TWO_LINE_MENUITEM_RIGHT_ALIGN_THUMBNAIL  0x02
#define UI_TWO_LINE_MENUITEM_THUMBNAIL_IS_FILE      0x04
#define UI_TWO_LINE_MENUITEM_THUMBNAIL_IS_ID        0x08
#define UI_TWO_LINE_TOGGLE_THUMBNAIL_DIRECTION_MASK 0x03



extern void (*wgui_text_menuitem_reset_scrolling)(void);
extern void (*wgui_text_menuitem_restart_scrolling)(void);


//wgui_fixed_menus.h
#define LIMIT_MENU_ITEM_NUMBER(n)      ((n) > (MAX_SUB_MENUS) ? (MAX_SUB_MENUS) : (n))



//wgui_asyncdynamic_menuitems.h
#define MAX_ASYNCHINT_NUM                   5
#define MAX_ASYNCDYNAMIC_ITEM_TEXT_SIZE     MAX_SUB_MENU_SIZE
#define MAX_ASYNCDYNAMIC_ITEMS_BUFF         16
#define MASK_ASYNCDYNAMIC_ITEMS_BUFF        15

    
#define FIXED_ICONLIST_MAX_TEXT_COLUMNS     3
#define FIXED_ICONLIST_MAX_ICON_COLUMNS     4



//wgui_dynamic_menuitems.h
#define MAX_HINT_NUM                    5
#define MAX_DYNAMIC_ITEM_TEXT_SIZE      MAX_SUB_MENU_SIZE
#define MAX_DYNAMIC_ITEMS_BUFF          32
#define MASK_DYNAMIC_ITEMS_BUFF         31


/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
//gui_fixed_menus.h
typedef enum
{
    GUI_HORIZONTAL_SELECT_PEN_NONE,
        GUI_HORIZONTAL_SELECT_PEN_PREV,
        GUI_HORIZONTAL_SELECT_PEN_NEXT
} gui_horizontal_select_pen_enum;

//gui_fixed_menuitems.h
typedef enum
{
    MMI_UI_LIST_HIGHLIGHT_EFFECT_NONE = 0,          /* No Effect */
        MMI_UI_LIST_HIGHLIGHT_EFFECT_TRANSPARENCY = 1,  /* Transparent with increasing opacity */
        MMI_UI_LIST_HIGHLIGHT_EFFECT_FLASH_FEELING = 2, /* Flash effect with increase in Filler area */
        MMI_UI_LIST_HIGHLIGHT_EFFECT_ANIMATION = 3,     /* Animatian with gif */
        MMI_UI_LIST_HIGHLIGHT_EFFECT_SLIDE = 4          /* Sliding highlight effect */
} gui_list_effect_styles;


typedef enum
{
    GUI_LIST_EFFECT_FLASH_FEELING_STOP,
        GUI_LIST_EFFECT_FLASH_FEELING_LAST_FRAME,
        GUI_LIST_EFFECT_FLASH_FEELING_RUNNING
} gui_flash_feel_state_enum;

typedef MMI_BOOL (*GetUnderLineFuncPtr)(S32 item_index, S32 *underline_index, S32 *count);
typedef MMI_BOOL (*PreKeyHandler)(MMI_key_code_type key_code);

typedef MMI_BOOL  (*GetMenuitemFlags)(S32 index, S32* flag, S32* flag_ext);


/* checkbox callback function typedef */
typedef S32 (*checkbox_clicked_funcptr_type)(S32 item_index);
typedef S32 (*checkbox_get_image_funcptr_type)(S32 item_index, PU8 *checkbox_image);

typedef enum
{
    GUI_MENU_TYPE_INVALID,
    GUI_MENU_TYPE_FIXED,
    GUI_MENU_TYPE_DYNAMIC,
    GUI_MENU_TYPE_ASYNCDYNAMIC,
    GUI_MENU_TYPE_END
} gui_menu_type_enum;

//wgui_fixed_menuitems.h

typedef enum
{
    GUI_SLIDE_CONTROL_PEN_STATE_INVALID,
    GUI_SLIDE_CONTROL_PEN_STATE_AREA1,
    GUI_SLIDE_CONTROL_PEN_STATE_AREA2,
    GUI_SLIDE_CONTROL_PEN_STATE_SLIDE
} gui_slide_control_pen_state_enum;

typedef union _thumbnail_image
{
    S8 *path;
    U16 id;
} wgui_thumbnail_image_union;


typedef S32 (*wgui_two_line_menuitem_get_default_callback)(S32 menuitem_index);
typedef pBOOL (*wgui_two_line_get_level_select_data_callback)(S32 menuitem_index, S32 item_index);
typedef pBOOL (*wgui_two_line_get_horizontal_select_data_callback)(S32 menuitem_index, S32 item_index,
                                                                   UI_string_type str_buff, PU8 *img_buff_p,
                                                                   wgui_thumbnail_image_union *thumbnail);
typedef void (*wgui_two_line_menuitem_complete_callback)(S32 menuitem_index, S32 selected_index);

typedef union _wgui_two_line_menuitem_data_union
{
    wgui_two_line_get_level_select_data_callback get_data_for_level_select;
    wgui_two_line_get_horizontal_select_data_callback get_data_for_horizontal_select;
} wgui_two_line_menuitem_data_union;

typedef struct _wgui_two_line_menuitem_struct
{
    U8 image_flags;
    S32 num_of_items;
    wgui_two_line_menuitem_get_default_callback defualt_value_callback;
    wgui_two_line_menuitem_complete_callback complete_callback;
    wgui_two_line_menuitem_data_union two_line_data_callback;
} wgui_two_line_menuitem_struct;

typedef void (*wgui_get_two_line_menu_item_properties)(int index,
                                                       wgui_two_line_menuitem_struct *
                                                       current_menuitem_properties);
typedef U8 (*wgui_get_display_style)(S32 absolute_index);
typedef pBOOL (*two_line_dynamic_menuitem_style)(S32 item_index, S32 menuitem_index);

//wgui_fixed_menus.h
typedef struct _slide_control
{
    S32 x, y;                                       /* position of background image */
    PU8 background_image;
    PU8 slide_image;
    U32 flags;
    S32 bg_image_width;
    S32 bg_image_height;
    S32 slide_image_width;
    S32 slide_image_height;
    S32 width;
    S32 lower_limit;
    S32 upper_limit;
    S32 current_value;
    S32 value_string_width, value_string_height;    /* position of value string */
    S32 value_string_gap;
    U8 *label_string;                               /* label string is always above the background image */
    void (*change_callback) (S32);
#ifdef GDI_USING_LAYER
    gdi_handle display_layer;
#endif 
#ifdef __MMI_TOUCH_SCREEN__
    gui_slide_control_pen_state_enum pen_state;
#endif 
} slide_control;

#define WGUI_LIST_MENU_DISABLE_SHORTCUT         0x00000001
#define WGUI_LIST_MENU_MULTIROW                 0x00000002
#define WGUI_LIST_MENU_DISABLE_KEY_HANDLE       0x00000004
#define WGUI_LIST_MENU_DISABLE_VOL_KEY          0x00000008
#define WGUI_LIST_INVALID_HIGHLIGHT             -1


//wgui_asyncdynamic_menuitems.h
typedef struct
{
    UI_string_type item_list[FIXED_ICONLIST_MAX_TEXT_COLUMNS];
    PU8 image_list[FIXED_ICONLIST_MAX_ICON_COLUMNS];
} gui_iconlist_menu_item;

typedef S32 (*GetAsyncItemFuncPtr)(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size);
typedef S32 (*GetAsyncHintFuncPtr)(S32 start_index, UI_string_type *hint_array);

//wgui_dynamic_menuitems.h
typedef pBOOL (*GetItemFuncPtr)(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
typedef S32 (*GetHintFuncPtr)(S32 item_index, UI_string_type *hint_array);


/*--------------------------------------------------------------------------------------------*/
/* Title                                                                                      */
/*--------------------------------------------------------------------------------------------*/

/***************************************************************************** 
 * Include 
 *****************************************************************************/


/***************************************************************************** 
 * Define
 *****************************************************************************/
#ifdef __MMI_UI_TITLE_TRANSITION__
#define TITLE_TRANSITION_STYLE_NON_BLOCKING 1
#define TITLE_TRANSITION_NON_BLOCKING_TIMER 10
    
#else /* __MMI_UI_TITLE_TRANSITION__ */ 
#define TITLE_TRANSITION_STYLE_NON_BLOCKING 0
#define TITLE_TRANSITION_NON_BLOCKING_TIMER 10
#endif /* __MMI_UI_TITLE_TRANSITION__ */ 

#ifdef __MMI_UI_TITLE_TRANSITION__

    #if(TITLE_TRANSITION_STYLE_NON_BLOCKING)
    #define TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT

        #ifdef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
        #define MAX_TITLE_AREA_HEIGHT_FOR_TRANSITION (MMI_TITLE_HEIGHT + MMI_MENUITEM_HEIGHT)
        #endif /*TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT*/

    #endif /* (TITLE_TRANSITION_STYLE_NON_BLOCKING) */ 

#endif /* __MMI_UI_TITLE_TRANSITION__ */ 


/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
 
/* TRANSITION_STYLES */
typedef enum
{
    WGUI_TRANSITION_NONE = 0,   /* No Transition */
    WGUI_TRANSITION_L2R,        /* Lef to Right */
    WGUI_TRANSITION_R2L,        /* Right to Left */
    WGUI_TRANSITION_T2D,        /* Top To Down */
    WGUI_TRANSITION_D2T,        /* Down To Top */
    WGUI_TRANSITION_END,
    WGUI_TRANSITION_OEM_STRAT
} gui_title_transition_enum;

#define wgui_transition_styles  gui_title_transition_enum
/* TRANSITION_STYLES */

/*--------------------------------------------------------------------------------------------*/
/* Status icons                                                                               */
/*--------------------------------------------------------------------------------------------*/

/***************************************************************************** 
 * Include 
 *****************************************************************************/


/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MAX_STATUS_ICON_BARS           3        /* 1 to ?         */


#define STATUS_ICON_BAR_DISPLAY           0x00000001
#define STATUS_ICON_BAR_ARRANGE_VERTICAL  0x00000002
#define STATUS_ICON_BAR_ARRANGE_HORIZONTAL   0x00000004
#define STATUS_ICON_BAR_ARRANGE_ASCENDING 0x00000000
#define STATUS_ICON_BAR_ARRANGE_DESCENDING   0x00000008
#define STATUS_ICON_BAR_ARRANGE_PRIORITY  0x00000010
#define STATUS_ICON_BAR_DISABLE_BACKGROUND   0x00000020
#define STATUS_ICON_BAR_ENABLE_DOUBLE_BUFFER   0x00000040

/* Distance in pixels between a status icon and its adjacent status icons  */
#define STATUS_ICON_X_GAP              2
#define STATUS_ICON_Y_GAP              2
#define SUBLCD_STATUS_ICON_X_GAP       1



/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
     enum STATUS_ICON_FORCE_DISPLAY
    {
        DEFAULT_BOTH,
        MAINLCD_ONLY,
        SUBLCD_ONLY
    };
/* Icon names that the applications must use when they call                                  
   ShowStatusIcon or HideStatusIcon                   */
enum STATUS_ICON_LIST
{
    STATUS_ICON_SIGNAL_STRENGTH = 0,
    STATUS_ICON_BATTERY_STRENGTH,
#ifdef __MMI_DUAL_SIM_MASTER__
STATUS_ICON_SLAVE_SIGNAL_STRENGTH,
#endif  /* __MMI_DUAL_SIM_MASTER__ */

#ifdef __MMI_MOBILE_TV_PLAYER__
    STATUS_ICON_MTV_SIGNAL,
#endif 
 

#ifdef __MMI_WLAN_FEATURES__
    STATUS_ICON_WLAN_SIGNAL,
#endif
#ifndef __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__     
    STATUS_ICON_ALTERNATE_LINE_L1,
    STATUS_ICON_ALTERNATE_LINE_L2,
#endif /* __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__ */ 
#if defined(__GSM_RAT__) && defined(__WCDMA_RAT__) 
/* under construction !*/
/* under construction !*/
#endif /* defined(__GSM_RAT__) && defined(__WCDMA_RAT__) */ 
#ifdef __MMI_VOIP__
    STATUS_ICON_VOIP,
#endif /* __MMI_VOIP__ */ 
#ifdef __MMI_AUDIO_PLAYER__
    STATUS_ICON_AUDPLY,
#endif
    STATUS_ICON_ROAMING,
#ifdef __MMI_DUAL_SIM_MASTER__
    STATUS_ICON_SLAVE_ROAMING,
#endif  /* __MMI_DUAL_SIM_MASTER__ */
    STATUS_ICON_CALL_DIVERT_L1L2,
    STATUS_ICON_CALL_DIVERT_L1,
    STATUS_ICON_CALL_DIVERT_L2,
#ifdef __MMI_DUAL_SIM_MASTER__
    STATUS_ICON_SLAVE_CALLFORWARD,
    STATUS_ICON_SLAVE_CALLFORWARD_L1,
    STATUS_ICON_SLAVE_CALLFORWARD_L2,
#endif  /* __MMI_DUAL_SIM_MASTER__ */
    STATUS_ICON_MUTE,
    STATUS_ICON_INCOMING_SMS,
#ifdef __MMI_DUAL_SIM_MASTER__
STATUS_ICON_SLAVE_INCOMING_SMS,
#endif  /* __MMI_DUAL_SIM_MASTER__ */
    STATUS_ICON_MMS_UNREAD,
    STATUS_ICON_MMS_BUSY,        
#ifdef __MMI_DUAL_SIM_MASTER__
    STATUS_ICON_MMS_UNREAD_SIM_1,
    STATUS_ICON_MMS_UNREAD_SIM_2,
    STATUS_ICON_MMS_BUSY_SIM_1,
    STATUS_ICON_MMS_BUSY_SIM_2,
#endif  /* __MMI_DUAL_SIM_MASTER__ */
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    STATUS_ICON_OUTBOX_INDICATOR,
#endif /*  __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
    STATUS_ICON_VIBRATION,
    STATUS_ICON_SILENT,
    STATUS_ICON_RING,
    STATUS_ICON_VIBRATE_AND_RING,
    STATUS_ICON_VIBRATE_THEN_RING,
    STATUS_ICON_EDGE,
    STATUS_ICON_GPRS_SERVICE,
    STATUS_ICON_EDGEC,
    STATUS_ICON_GPRS_ATT_NO_PDP_INDICATOR,  
#ifdef __MMI_DUAL_SIM_MASTER__
    STATUS_ICON_SLAVE_EDGE, // for SIM2
    STATUS_ICON_SLAVE_GPRS_SERVICE,
    STATUS_ICON_SLAVE_EDGEC,
    STATUS_ICON_SLAVE_GPRS_ATT_NO_PDP_INDICATOR,
#endif

#if (defined(OBIGO_Q05A) || defined(JATAAYU_SUPPORT)) && defined(WAP_SUPPORT)
    STATUS_ICON_SECURITY,
#endif
    STATUS_ICON_EARPHONE_INDICATOR,
    STATUS_ICON_ALARM,
    STATUS_ICON_VOICE_RECORD,
    STATUS_ICON_KEYPAD_LOCK,
    STATUS_ICON_MISSED_CALL,
#ifdef __MMI_DUAL_SIM_MASTER__
    STATUS_ICON_CARD2MISSED_CALL,
#endif  /*__MMI_DUAL_SIM_MASTER__*/

    STATUS_ICON_UNREAD_EMAIL,

    STATUS_ICON_UNREAD_VOICE_L1L2,
    STATUS_ICON_UNREAD_VOICE_L1,
    STATUS_ICON_UNREAD_VOICE_L2,
    STATUS_ICON_UNREAD_FAX_L1L2,
    STATUS_ICON_UNREAD_FAX_L1,
    STATUS_ICON_UNREAD_FAX_L2,
    STATUS_ICON_UNREAD_EMAIL_L1L2,
    STATUS_ICON_UNREAD_EMAIL_L1,
    STATUS_ICON_UNREAD_EMAIL_L2,
    
    STATUS_ICON_UNREAD_NET_L1,
    STATUS_ICON_UNREAD_NET_L2,
    STATUS_ICON_UNREAD_NET_L1L2,
    
#ifdef __MMI_DUAL_SIM_MASTER__
    STATUS_ICON_UNREAD_VOICE_L1_MASTER,
    STATUS_ICON_UNREAD_VOICE_L2_MASTER,
    STATUS_ICON_UNREAD_VOICE_L1L2_MASTER,
    STATUS_ICON_UNREAD_FAX_L1_MASTER,
    STATUS_ICON_UNREAD_FAX_L2_MASTER,
    STATUS_ICON_UNREAD_FAX_L1L2_MASTER,
    STATUS_ICON_UNREAD_EMAIL_L1_MASTER,
    STATUS_ICON_UNREAD_EMAIL_L2_MASTER,
    STATUS_ICON_UNREAD_EMAIL_L1L2_MASTER,
    STATUS_ICON_UNREAD_NET_L1_MASTER,
    STATUS_ICON_UNREAD_NET_L2_MASTER,
    STATUS_ICON_UNREAD_NET_L1L2_MASTER,
    
    STATUS_ICON_UNREAD_VOICE_L1_SLAVE,
    STATUS_ICON_UNREAD_VOICE_L2_SLAVE,
    STATUS_ICON_UNREAD_VOICE_L1L2_SLAVE,
    STATUS_ICON_UNREAD_FAX_L1_SLAVE,
    STATUS_ICON_UNREAD_FAX_L2_SLAVE,
    STATUS_ICON_UNREAD_FAX_L1L2_SLAVE,
    STATUS_ICON_UNREAD_EMAIL_L1_SLAVE,
    STATUS_ICON_UNREAD_EMAIL_L2_SLAVE,
    STATUS_ICON_UNREAD_EMAIL_L1L2_SLAVE,
    STATUS_ICON_UNREAD_NET_L1_SLAVE,
    STATUS_ICON_UNREAD_NET_L2_SLAVE,
    STATUS_ICON_UNREAD_NET_L1L2_SLAVE,
#endif  /*__MMI_DUAL_SIM_MASTER__*/

    STATUS_ICON_IMPS_MSG,
    STATUS_ICON_IMPS_LOGIN,
    STATUS_ICON_WAP,
    STATUS_ICON_POC,                        
    STATUS_ICON_BT,
    STATUS_ICON_BT_CON,
    STATUS_ICON_BT_ND,
    STATUS_ICON_IR,
    STATUS_ICON_STOP_WATCH,
    STATUS_ICON_CHAT_INDICATION_ROOM1,
    STATUS_ICON_CHAT_INDICATION_ROOM2,
    STATUS_ICON_NETWORK_CIPHER_GSM,    
#ifdef __MMI_DUAL_SIM_MASTER__
    STATUS_ICON_SLAVE_NETWORK_CIPHER_GSM,
#endif
    STATUS_ICON_NETWORK_CIPHER_GPRS,        
#if defined(__J2ME__) && defined(J2ME_SUPPORT_BACKGROUND)
    STATUS_ICON_JAVA_BG_VM,                 
    STATUS_ICON_JAVA_BG_VM_AUDIO,
#endif
#ifdef __MMI_BG_SOUND_EFFECT__
    STATUS_ICON_BG_SOUND,
#endif 
#ifdef __MMI_AUDIO_REVERB_EFFECT__
    STATUS_ICON_REVERB_SOUND,
#endif 
#ifdef __MMI_AUDIO_SURROUND_EFFECT__
    STATUS_ICON_AUD_SURROUND,
#endif
#ifdef __MMI_HOMEZONE_STATUS_ICON__
    STATUS_ICON_HOMEZONE,
#ifdef __MMI_DUAL_SIM_MASTER__
    STATUS_ICON_SLAVE_HOMEZONE,
#endif
    STATUS_ICON_CITYZONE,
#endif /* __MMI_HOMEZONE_STATUS_ICON__ */ 
#ifdef __CTM_SUPPORT__
    STATUS_ICON_TTY_INDICATOR,
#endif 
    STATUS_ICON_EMAIL_REF,
#ifdef __MMI_PICT_BRIDGE_SUPPORT__
    STATUS_ICON_PRINT,
    STATUS_ICON_PRINT_FAIL,
#endif /* __MMI_PICT_BRIDGE_SUPPORT__ */

#ifdef __AGPS_SUPPORT__
    STATUS_ICON_AGPS_STATE,
#endif
/* Vogins Start */
#ifdef __VRE30_AM__
    /* Icon of VRE default */
    STATUS_ICON_VRE_DEFAULT,
    /* Icon of VRE for fetion */
    STATUS_ICON_VRE_1,
    /* Icon of VRE for MSN */
    STATUS_ICON_VRE_2,
    /* Icon of VRE for push mail */
    STATUS_ICON_VRE_3,
    /* Icon of VRE for QQ */
    STATUS_ICON_VRE_4,
#endif
/* Vogins End */

    STATUS_ICON_SUBLCD_SIGNAL_STRENGTH,
    STATUS_ICON_SUBLCD_BATTERY_STRENGTH,
    STATUS_ICON_SUBLCD_SMS,
    STATUS_ICON_SUBLCD_RING,
    STATUS_ICON_SUBLCD_VIBRATE,
    STATUS_ICON_SUBLCD_VIBRATE_AND_RING,
    STATUS_ICON_SUBLCD_VIBRATE_THEN_RING,
    STATUS_ICON_SUBLCD_SILENT,
    STATUS_ICON_SUBLCD_ALARM,
    STATUS_ICON_SUBLCD_MISSED_CALL,
    MAX_STATUS_ICONS
};


#ifdef __MMI_TOUCH_SCREEN__
typedef enum
{
    WGUI_STATUS_ICON_BAR_PEN_SELECT_ICON,
    WGUI_STATUS_ICON_BAR_PEN_LONG_PRESS_ICON,
    WGUI_STATUS_ICON_BAR_PEN_EVENT_MAX,
    WGUI_STATUS_ICON_BAR_PEN_NONE
} wgui_status_icon_bar_pen_enum;
#endif /* __MMI_TOUCH_SCREEN__ */ 

/*--------------------------------------------------------------------------------------------*/
/* Scrollbar                                                                                  */
/*--------------------------------------------------------------------------------------------*/

/***************************************************************************** 
 * Include 
 *****************************************************************************/


/***************************************************************************** 
 * Define
 *****************************************************************************/


/***************************************************************************** 
 * Typedef 
 *****************************************************************************/

/*--------------------------------------------------------------------------------------------*/
/* Shortcut                                                                                   */
/*--------------------------------------------------------------------------------------------*/

/***************************************************************************** 
 * Include 
 *****************************************************************************/


/***************************************************************************** 
 * Define
 *****************************************************************************/
#ifdef __MMI_UI_ICON_BAR__

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/

typedef enum
{
    GUI_ICON_BAR_ALIGN_START = 1,
    GUI_ICON_BAR_ALIGN_LEFT,
    GUI_ICON_BAR_ALIGN_CENTER,
    GUI_ICON_BAR_ALIGN_EQUIDISTANCE,
    GUI_ICON_BAR_ALIGN_END
} gui_icon_bar_align_enum;

#endif /* __MMI_UI_ICON_BAR__ */

/*--------------------------------------------------------------------------------------------*/
/* button                                                                                     */
/*--------------------------------------------------------------------------------------------*/

/***************************************************************************** 
 * Include 
 *****************************************************************************/


/***************************************************************************** 
 * Define
 *****************************************************************************/


/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
#ifdef __MMI_TOUCH_SCREEN__
typedef enum
{
    GUI_BUTTON_PEN_NONE,            /* No event is generated. (but the low-level pen events might be still accepted) */
    GUI_BUTTON_PEN_DOWN,            /* Pen down on button */
    GUI_BUTTON_PEN_REPEAT,          /* Pen Repeat inside button */
    GUI_BUTTON_PEN_LONGTAP,         /* Pen LongTap inside button */
    GUI_BUTTON_PEN_UP_INSIDE,       /* Pen down on button */
    GUI_BUTTON_PEN_UP_OUTSIDE,      /* Pen up outside button */
    GUI_BUTTON_PEN_MOVE_OUTSIDE,    /* Pen is moved outside button */
    GUI_BUTTON_PEN_MOVE_INSIDE      /* Pen is moved into the button  */
    } gui_button_pen_enum;
#endif /* __MMI_TOUCH_SCREEN__ */ 
/*--------------------------------------------------------------------------------------------*/
/* Calendar                                                                                   */
/*--------------------------------------------------------------------------------------------*/

/***************************************************************************** 
 * Include 
 *****************************************************************************/


/***************************************************************************** 
 * Define
 *****************************************************************************/
#define GUI_CALENDAR_MAX_CELL_TEXT                     3
#if defined (__MMI_MAINLCD_320X240__)
    #define GUI_CALENDAR_FRAME_WIDTH                   316
    #define GUI_CALENDAR_FRAME_HEIGHT                  160
#elif defined (__MMI_MAINLCD_240X320__)
    #define GUI_CALENDAR_FRAME_WIDTH                   221
    #define GUI_CALENDAR_FRAME_HEIGHT                  199
#elif defined (__MMI_MAINLCD_240X400__)
    #define GUI_CALENDAR_FRAME_WIDTH                   230
    #define GUI_CALENDAR_FRAME_HEIGHT                  240
#elif defined (__MMI_MAINLCD_176X220__)
    #define GUI_CALENDAR_FRAME_WIDTH                   164
    #define GUI_CALENDAR_FRAME_HEIGHT                  157
#elif defined (__MMI_MAINLCD_128X160__)
    #define GUI_CALENDAR_FRAME_WIDTH                   128
    #define GUI_CALENDAR_FRAME_HEIGHT                  120
#elif defined (__MMI_MAINLCD_128X128__)
    #define GUI_CALENDAR_FRAME_WIDTH                   128
    #define GUI_CALENDAR_FRAME_HEIGHT                  92
#endif /* __MMI_MAINLCD_320X240__ */
#define GUI_CALENDAR_CACHE_WIDTH                   (GUI_CALENDAR_FRAME_WIDTH/5)
#define GUI_CALENDAR_CACHE_HEIGHT                  (GUI_CALENDAR_FRAME_HEIGHT/5)

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
typedef MMI_BOOL (*GUICalendarV2EventFuncPtr) (U32 highlighted_row, U32 highlighted_column);
typedef void (*GUICalendarV2FuncPtr) (void);

typedef struct
{
    U8 bg_index;
    UI_image_ID_type icon_id;
    UI_character_type text[GUI_CALENDAR_MAX_CELL_TEXT];
    MMI_BOOL valid;
} gui_calendar_cell_struct;


/*--------------------------------------------------------------------------------------------*/
/* Clock                                                                                      */
/*--------------------------------------------------------------------------------------------*/

/***************************************************************************** 
 * Include 
 *****************************************************************************/


/***************************************************************************** 
 * Define
 *****************************************************************************/
/* id of clock */
#ifdef __LOW_COST_PROJECT__
#define WGUI_CLOCK_MAX_ITEMS_MAIN_LCD       5
#else
#define WGUI_CLOCK_MAX_ITEMS_MAIN_LCD       6
#endif
#define WGUI_CLOCK_MAX_ITEMS_SUB_LCD        2
#define WGUI_CLOCK_MAX_ITEMS                (WGUI_CLOCK_MAX_ITEMS_MAIN_LCD + WGUI_CLOCK_MAX_ITEMS_SUB_LCD)
#define WGUI_CLOCK_START_ID_MAIN_LCD        0
#define WGUI_CLOCK_MAINLCD_CLOCK1           WGUI_CLOCK_START_ID_MAIN_LCD
#define WGUI_CLOCK_MAINLCD_CLOCK2           (WGUI_CLOCK_START_ID_MAIN_LCD + 1)
#define WGUI_CLOCK_MAINLCD_CLOCK3           (WGUI_CLOCK_START_ID_MAIN_LCD + 2)
#define WGUI_CLOCK_MAINLCD_CLOCK4           (WGUI_CLOCK_START_ID_MAIN_LCD + 3)
#define WGUI_CLOCK_MAINLCD_CLOCK5           (WGUI_CLOCK_START_ID_MAIN_LCD + 4)

#ifndef __LOW_COST_PROJECT__
#define WGUI_CLOCK_MAINLCD_LIST_CLOCK       (WGUI_CLOCK_START_ID_MAIN_LCD + 5)
#endif
#define WGUI_CLOCK_START_ID_SUB_LCD         WGUI_CLOCK_MAX_ITEMS_MAIN_LCD
#define WGUI_CLOCK_SUBLCD_CLOCK1            WGUI_CLOCK_START_ID_SUB_LCD
#define WGUI_CLOCK_SUBLCD_CLOCK2            (WGUI_CLOCK_START_ID_SUB_LCD + 1)

#ifdef __MMI_MAINLCD_240X400__
#define WGUI_CLOCK_SMALL_WIDTH              46
#else
#define WGUI_CLOCK_SMALL_WIDTH              46
#endif

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
/*type of different clocks*/
typedef enum 
{
    GUI_CLOCK_TYPE_ANALOG,
    GUI_CLOCK_TYPE_DIGITAL_TIME_DATE_TWO_LINE,
    GUI_CLOCK_TYPE_DIGITAL_TIME_DATE_ONE_LINE, 
    GUI_CLOCK_TYPE_DIGILTAL_DAY_DATE_ONE_LINE,
    GUI_CLOCK_TYPE_DIGITAL_TIME,
    GUI_CLOCK_TYPE_DIGITAL_DAY,
    GUI_CLOCK_TYPE_DIGITAL_DATE,
    GUI_CLOCK_TYPE_DIGITAL_TIME_SMALL,
#ifdef __MMI_SUBLCD__
    GUI_CLOCK_SUBLCD_TYPE1,
    GUI_CLOCK_SUBLCD_TYPE2,
    GUI_CLOCK_SUBLCD_TYPE3,
    GUI_CLOCK_SUBLCD_TYPE4,
    GUI_CLOCK_SUBLCD_ANALOG_CLOCK,
#endif/*__MMI_SUBLCD__*/
    GUI_CLOCK_TYPE_END_OF_ENUM /* Last dummy enum item */
} gui_clock_type_enum;

typedef enum
{
    GUI_CLOCK_DIGITAL_ALIGN_CENTER,
    GUI_CLOCK_DIGITAL_ALIGN_LEFT,
    GUI_CLOCK_DIGITAL_ALIGN_RIGHT,
    GUI_CLOCK_DIGITAL_ALIGN_TOTAL    
} gui_clock_digital_align_enum;

/*--------------------------------------------------------------------------------------------*/
/* Date time                                                                                  */
/*--------------------------------------------------------------------------------------------*/

/***************************************************************************** 
 * Include 
 *****************************************************************************/


/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
    typedef enum _DT_DISPLAY_TYPE
    {
        DT_IDLE_SCREEN,
        DT_IDLE_SCREEN_2,
        DT_MO_CALL_SCREEN,
        DT_MO_CALLING_SCREEN,
        DT_ACTIVE_CALL_SCREEN,
        DT_TABBED_CALL_SCREEN,
        DT_MT_CALL_SCREEN,
        DT_NETWORK_SEARCH,
        DT_SUBLCD_IDLE_SCREEN1,
        DT_SUBLCD_IDLE_SCREEN2,
        DT_SUBLCD_IDLE_SCREEN3,
        DT_SUBLCD_IDLE_SCREEN4,
        DT_DIGITAL_CLOCK_SC1,
        DT_DIGITAL_CLOCK_SC2,
        DT_DIGITAL_CLOCK_SC3,
        DT_ANALOG_CLOCK_SC,
        DT_AUDIO_PLAY_DURATION,
        DT_GPRS_ACTIVE_CALL,
        DT_GPRS_CONF_CALL,
        DT_FILEMANAGER,
        DT_SUBLCD_ANALOG_CLOCK,
        DT_IDLE_SCREEN_ENGLISH_ONLY,
        DT_VOIP_CALL_SCREEN
    } DT_DISPLAY_TYPE;

#ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
typedef enum
{
    ANALOG,
    DIGITAL
} MMI_CLOCK_TYPE;
#endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */


/*--------------------------------------------------------------------------------------------*/
/* virtual keyboard                                                                           */
/*--------------------------------------------------------------------------------------------*/

/***************************************************************************** 
 * Include 
 *****************************************************************************/


/***************************************************************************** 
 * Define
 *****************************************************************************/


/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
/*--------------------------------------------------------------------------------------------*/
/* text label                                                                                 */
/*--------------------------------------------------------------------------------------------*/
/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
typedef enum
{
    GUI_TEXT_LABEL_H_ALIGN_START,
    GUI_TEXT_LABEL_H_ALIGN_LEFT,
    GUI_TEXT_LABEL_H_ALIGN_CENTER,
    GUI_TEXT_LABEL_H_ALIGN_RIGHT,
    GUI_TEXT_LABEL_H_ALIGN_LANG_DEP,
    GUI_TEXT_LABEL_H_ALIGN_END,
    GUI_TEXT_LABEL_V_ALIGN_START,
    GUI_TEXT_LABEL_V_ALIGN_TOP,
    GUI_TEXT_LABEL_V_ALIGN_CENTER,
    GUI_TEXT_LABEL_V_ALIGN_BOTTOM,
    GUI_TEXT_LABEL_V_ALIGN_END
} gui_text_label_align_enum;

/*--------------------------------------------------------------------------------------------*/
/* softkey                                                                                    */
/*--------------------------------------------------------------------------------------------*/
/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
typedef enum
{
    MMI_LEFT_SOFTKEY,
        MMI_RIGHT_SOFTKEY,
#ifdef __MMI_WGUI_CSK_ENABLE__
        MMI_CENTER_SOFTKEY,
#endif 
        WGUI_MAX_SOFTKEYS
} WGUI_SOFTKEY_ENUM;


/*--------------------------------------------------------------------------------------------*/
/* Tab bar                                                                                   */
/*--------------------------------------------------------------------------------------------*/
/***************************************************************************** 
 * Typedef 
 *****************************************************************************/

typedef struct
{
    U32 flags;
    S8 first_displayed_item;
    S8 last_displayed_item;
    S8 focused_item;
} wgui_tab_bar_history_struct;

typedef struct _tab_bar_item_type
{
    PU8 icon;
    UI_string_type text;
    U32 flags;
#ifdef GUI_TAB_BAR_ORANGE
    S32 blink_duration;
#endif
} tab_bar_item_type;


/*--------------------------------------------------------------------------------------------*/
/* icon_bar                                                                                   */
/*--------------------------------------------------------------------------------------------*/
/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
#ifdef __MMI_UI_ICON_BAR__
typedef struct
{
    S8 first_displayed_item;
    S8 focused_item;
    MMI_BOOL active;
} wgui_icon_bar_history_struct;

#endif /* __MMI_UI_ICON_BAR__ */

/*--------------------------------------------------------------------------------------------*/
/* Image component                                                                            */
/*--------------------------------------------------------------------------------------------*/
/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
typedef enum
{
    GUI_IMAGE_H_ALIGN_START,
    GUI_IMAGE_H_ALIGN_LEFT,
    GUI_IMAGE_H_ALIGN_CENTER,
    GUI_IMAGE_H_ALIGN_RIGHT,
    GUI_IMAGE_H_ALIGN_END,
    GUI_IMAGE_V_ALIGN_START,
    GUI_IMAGE_V_ALIGN_TOP,
    GUI_IMAGE_V_ALIGN_CENTER,
    GUI_IMAGE_V_ALIGN_BOTTOM,
    GUI_IMAGE_V_ALIGN_END
} gui_image_align_enum;


/*--------------------------------------------------------------------------------------------*/
/* Video component                                                                            */
/*--------------------------------------------------------------------------------------------*/
/***************************************************************************** 
 * Typedef 
 *****************************************************************************/

typedef struct
{
    U16 volume;
    U64 current_play_time;
} wgui_video_history_struct;


/***************************************************************************** 
* Utility
*****************************************************************************/
typedef enum
{CONF_NONE = 0,
    CONF_ACTIVE = 1,
    CONF_HOLD = 2
} CATEGORY_CM_CONFERENCE_STATES;

typedef struct _list_menu_category_history
{
    U16 history_ID;
    S32 highlighted_item;
    S32 first_displayed_item;
    S32 last_displayed_item;
    S32 displayed_items;
    U32 flags;
    S8 state;
    S32 num_items;              /* Number of menu items*/
} list_menu_category_history;

typedef struct _list_menu_category_history140
{
    U16 history_ID;
    S16 highlighted_item;
    S16 first_displayed_item;
    S16 last_displayed_item;
    S16 displayed_items;
    U32 flags;
    S32 no_of_items;
    S8 state;   /* To keep current screen state in history buffer. */
    U8 list_of_states[MAX_FIXED_TWOSTATE_MENU_ITEMS];
} list_menu_category_history_cat140;

typedef struct _matrix_menu_category_history
{
    U16 history_ID;
    S16 highlighted_item;
    S16 highlighted_column;
    S16 highlighted_row;
    S16 displayed_columns;
    S16 displayed_rows;
    S16 first_displayed_column;
    S16 first_displayed_row;
    U32 flags;
} matrix_menu_category_history;

typedef struct _object_list_category_history
{
    U16 history_ID;
    S16 index;
} object_list_category_history;

typedef struct _list_matrix_menu_category_history
{
    list_menu_category_history list_menu_history;
    matrix_menu_category_history matrix_menu_history;
} list_matrix_menu_category_history;

#define MMI_MAX_SLIDE_CONTROL 3
typedef struct _slide_control_category_history
{
    U16 n_items;
    U16 history_ID;
    S32 value[MMI_MAX_SLIDE_CONTROL];
    U16 current_focus;
} slide_control_category_history;

#define MMI_MAX_PANEL 1

typedef struct _panel_category_history
{
    U16 history_ID;  
    U16 focused_panel;
    S32 n_items;  
    S32 focused_element[MMI_MAX_PANEL];
} panel_category_history;

/* SLIM Version Menu Style */
typedef enum
{
    WGUI_LIST_MENU_SLIM_STYLE_DEFAULT,  /* By system setting */
    WGUI_LIST_MENU_SLIM_STYLE_NO_ICON,  /* Disable icon display */
    WGUI_LIST_MENU_SLIM_STYLE_NUMBER,   /* Auto numbering */
    WGUI_LIST_MENU_SLIM_STYLE_DRAW_ICON
} wgui_list_menu_slim_style_enum;

/*   Animted title effect   */
#ifdef __MMI_UI_ANIMATED_TITLE_EFFECT__
#define TITLE_IMAGE_ANIMATION_TIMER 50
#define SHIFT_TITLE_IMAGE 5

#endif /* __MMI_UI_ANIMATED_TITLE_EFFECT__ */ 

#define WGUI_ORDER_TEXT_IMAGE 0x00000000
#define WGUI_ORDER_IMAGE_TEXT 0x00000001

#define WGUI_MAX_POP_UP_DESCRIPTION_STRINGS      MAX_FIXED_ICONTEXT_MENU_ITEMS
#define GDI_TRANSFORM_GRADIENT_COLOR(Color)  gdi_act_color_from_rgb(255,Color.r,Color.g,Color.b),gdi_act_color_from_rgb(255,(Color.r>>1),(Color.g>>1),(Color.b>>1))

#define MMI_BEFORE_SCREEN                             0x00000000
#define MMI_LEAVE_FULL_SCREEN                         0x00000001
#define MMI_LEAVE_FULL_IDLE_SCREEN                    0x00000002
#define MMI_IN_FULL_SCREEN                            0x00000004
#define MMI_IN_NORMAL_SCREEN                          0x00000008
#define MMI_IN_NORMAL_SCREEN_WITHOUT_STATUSBAR        0x00000010
#define MMI_IN_IDLE_SCREEN                            0x00000020
#define MMI_LEAVE_BG_ON_BOTTOM_SCREEN                 0x00000040        /* redraw status */
#define MMI_IN_JAVA_SCREEN                            0x00000080        /* Java title */

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/
extern U32 category_screen_layout_flags;
extern S32 MMI_matrix_bar_height;
extern S32 MMI_matrix_bar_width;
extern S32 MMI_matrix_bar_x;
extern S32 MMI_matrix_bar_y;
extern S32 MMI_title_height;
extern S32 MMI_title_width;
extern S32 MMI_title_x;
extern S32 MMI_title_y;
extern S32 MMI_button_bar_height;
extern S32 MMI_thick_menuitem_height;
extern S32 MMI_menuitem_height;
extern void (*UI_hide_animation_frame_function) (void);

/* high level wrappers  */
extern UI_string_type MMI_message_string;
extern PU8 MMI_message_icon;
extern S32 MMI_menu_shortcut_number;
extern UI_string_type MMI_highlighted_item_text;

extern S32 MMI_current_menu_type;

/* extern S32 MMI_main_menu_type; */
extern S16 MMI_current_input_type;

/* extern S16 MMI_saved_input_type; */
extern U8 flag_scroll;
extern U8 MMI_english_input_mode_flag;
extern stFontAttribute UI_DEFAULT_FONT;
extern void (*MMI_list_highlight_handler) (S32 item_index);
extern void (*MMI_matrix_highlight_handler) (S32 item_index);
extern void (*MMI_circular_3D_highlight_handler) (S32 item_index);

extern void (*wgui_inputbox_RSK_function) (void);

extern void (*ExitCategoryFunction) (void);
extern void (*RedrawCategoryFunction) (void);
extern void (*RedrawSpellingOrCandidateBoxesFunction) (void);
extern U8 *(*GetCategoryHistory) (U8 *history_buffer);
extern S32(*GetCategoryHistorySize) (void);

/* Globals  */
extern gdi_handle animation_handle;

/*** Store the value of height, width , x, y position of title bar ,status icons
popup dialog in global variables these valeu r also #define in wgui.h */

/* move init value to wgui.c */
extern S32 MMI_matrix_bar_height;
extern S32 MMI_matrix_bar_x;
extern S32 MMI_matrix_bar_y;
extern S32 MMI_matrix_bar_width;
extern S32 MMI_title_height;
extern S32 MMI_title_width;
extern S32 MMI_title_x;
extern S32 MMI_title_y;
extern S32 MMI_button_bar_height;
extern S32 MMI_menuitem_height;

extern S32 MMI_pop_up_dialog_x;
extern S32 MMI_pop_up_dialog_y;
extern S32 MMI_pop_up_dialog_width;
extern S32 MMI_pop_up_dialog_height;
extern S32 MMI_pop_up_dialog_full_height;

extern U8 wgui_switch_title_with_status_bar;    /* 0: Title, 1: Status icons  */
extern U8 wgui_category_screen_no_buttons;

/* Store the clipping value of current image */
extern S32 wgui_image_clip_x1;
extern S32 wgui_image_clip_y1;
extern S32 wgui_image_clip_x2;
extern S32 wgui_image_clip_y2;

/* Support for displaying animations in Category screens:
   These functions allow the display of a single animated
   icon in any category screen. The position of the icon
   is decided by the category screen                  */
extern PU8 _MMI_animated_icon;
extern U8 *_MMI_animated_icon_name;
extern S32 _MMI_animated_icon_x;
extern S32 _MMI_animated_icon_y;
extern UI_animated_image_handle _MMI_animated_icon_handle;

extern UI_pop_up_description wgui_pop_up_description;

/* store number of strigs of pop up */
extern S32 wgui_pop_up_descriptions_n_strings;

/* store current index of popup */
extern S32 wgui_current_pop_up_description_index;

/* store number of popup */
extern S32 wgui_pop_up_descriptions_n_items;

/* store flag of popup */
extern U8 wgui_pop_up_description_flag;

extern wgui_pop_up_description_string_type wgui_pop_up_description_strings[WGUI_MAX_POP_UP_DESCRIPTION_STRINGS];

extern U8 *checklist_category_menu_item_states;
extern S32 item_checked;
extern void (*checkbox_toggle_DONE_RSK_function) (void);
extern void (*checkbox_toggle_BACK_RSK_function) (void);

/** Store the title string of current main lcd scrren */
extern UI_string_type MMI_title_string;

/** Store the address of title icon display on current main lcd scrren title bar */
extern PU8 MMI_title_icon;

/** Store the address of title icon display on current main lcd scrren title bar */
extern PU8 MMI_title_icon2;


/* Store the message of current multibox dispaly on main lcd */
extern UI_string_type MMI_message_string;
extern UI_string_type MMI_message_string2;

/** Store the address of icon display on content area of current main lcd scrren */
extern PU8 MMI_message_icon;
extern PU8 MMI_message_icon2;

/* store teh current shorcut number display on right side of title bar in case of menu screen */
extern S32 MMI_menu_shortcut_number;

/* Store the text of current highlighted item in menu */
extern UI_string_type MMI_highlighted_item_text;

/* high level wrappers  */
extern PU8 MMI_mm_animation;

extern U8 gMMI_UI_U8_flag_1, gMMI_UI_U8_flag_2;
extern U16 gMMI_UI_U16_var_1, gMMI_UI_U16_var_2;
extern S32 gMMI_UI_S32_var_1, gMMI_UI_S32_var_2, gMMI_UI_S32_var_3, gMMI_UI_S32_var_4;
extern void *gMMI_UI_ptr_1, *gMMI_UI_ptr_2, *gMMI_UI_ptr_3, *gMMI_UI_ptr_4;

/* varbale of type slide_control used in slide control screen */
extern slide_control *MMI_current_slide_control;

/* extern slide_control MMI_slide_control1,MMI_slide_control2; */
extern slide_control MMI_slide_control[MMI_MAX_SLIDE_CONTROL];

/* store current slide control value */
extern S32 *MMI_current_slide_control_value;

extern S32 *MMI_slide_control_value[MMI_MAX_SLIDE_CONTROL];

extern S32 gOnFullScreen;

/* Add for Draw Manager */
extern S32 g_gui_current_catid;


#endif /* __GUI_TYPEDEF_H__ */


