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
 *  vapp_v2p_status_icon_bar.c
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/* Pluto headers */
#include "MMI_features.h"
#include "MMI_include.h"
#include "wgui_status_icons.h"

/* Venus headers */
#include "GUI\vadp_v2p_status_icon_bar.h"



/**********************************************************************
 * Global Functions
 **********************************************************************/

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_show_icon
 * DESCRIPTION
 *  Adaption api of show an icon with icon ID
 * PARAMETERS
 *  iconId  [IN]    icon ID
 * RETURNS
 *  void 
 *****************************************************************************/
void vadp_v2p_show_icon(S32 iconId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    wgui_status_icon_show_status_icon((S16)iconId);
    wgui_status_icon_update_status_icons();
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_blink_icon
 * DESCRIPTION
 *  Adaption api of blink an icon with icon ID
 * PARAMETERS
 *  iconId  [IN]    icon ID
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_blink_icon(S32 iconId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    wgui_status_icon_blink_status_icon((S16)iconId);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_animate_icon
 * DESCRIPTION
 *  Adaption api of animate an icon with icon ID
 * PARAMETERS
 *  iconId  [IN]    icon ID
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_animate_icon(S32 iconId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    wgui_status_icon_animate_status_icon((S16)iconId);
    wgui_status_icon_update_status_icons();
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_change_icon_level
 * DESCRIPTION
 *  Adaption api of change an icon level with icon ID and level percentage
 * PARAMETERS
 *  iconId  [IN]    icon ID
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_change_icon_level(S32 iconId, U8 level_percentage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    wgui_status_icon_change_status_icon_level((S16)iconId, level_percentage);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_change_icon_image
 * DESCRIPTION
 *  Adaption api of change an icon image with icon ID and image ID
 * PARAMETERS
 *  iconId  [IN]    icon ID
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_change_icon_image(S32 iconId, U16 image_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    wgui_status_icon_change_status_icon_image((S16)iconId, image_id);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_create_status_icon_bar
 * DESCRIPTION
 *  Adaption api of initialize the update callback for c => c++
 * PARAMETERS
 *  update_screen_callback  [IN]    update callback for plutoMMI
 *  update_screen_handle    [IN]    update handle for plutoMMI
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_create_status_icon_bar(
          void (*update_screen_callback)(void *handle),
          void *update_screen_handle, gdi_handle display_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    wgui_status_icon_bar_set_venus_callback(update_screen_callback, update_screen_handle);

    wgui_status_icon_set_display_layer(display_layer);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_close_status_icon_bar
 * DESCRIPTION
 *  Adaption api of close the status icon bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_close_status_icon_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    wgui_status_icon_close_status_icons();

    wgui_status_icon_reset_display_layer();
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_show_status_icon_bar
 * DESCRIPTION
 *  Adaption api of show status icon bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_show_status_icon_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    wgui_set_wallpaper_on_bottom(MMI_TRUE);
    wgui_status_icon_show_status_icon_bar(0);
    wgui_status_icon_show_status_icons();
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_get_prefered_size
 * DESCRIPTION
 *  Adaption api of get prefered size
 * PARAMETERS
 *  width   [OUT]   width of size
 *  height  [OUT]   height of size
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_get_prefered_size(S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    *width = MAIN_LCD_DEVICE_WIDTH;
    *height = MMI_STATUS_BAR_HEIGHT;
}
/* Vogins Start */
#ifdef __VRE__
/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_status_icon_bar_register_pen_event
 * DESCRIPTION
 *  Adaption api of register pen event
 * PARAMETERS
 *  icon_id     [IN]    The id of status icon
 *  event_type  [IN]    The event to response
 *  handler     [IN]    The handler of pen event
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_status_icon_bar_register_pen_event(S32 icon_id, FuncPtr handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_SCREEN__

	//kal_prompt_trace(MOD_IDLE,"ltz.......vadp_v2p_status_icon_bar_register_pen_event.........");
	wgui_register_status_icon_pen_event_hdlr(icon_id,  WGUI_STATUS_ICON_BAR_PEN_SELECT_ICON, handler);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_status_icon_bar_reset_all_pen_event_handler
 * DESCRIPTION
 *  Reset all icon's pen event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_status_icon_bar_reset_all_pen_event_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_SCREEN__
   // wgui_status_icon_bar_reset_all_pen_event_handler();
   //kal_prompt_trace(MOD_IDLE,"ltz.......vadp_v2p_status_icon_bar_reset_all_pen_event_handler.........");
   wgui_reset_status_icon_pen_event_hdlr();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  wgui_status_icon_bar_execute_pen_event_handler
 * DESCRIPTION
 *  Execute the icon's pen event handler
 * PARAMETERS
 *  icon_id         [IN]    The id of status icon
 *  event_type      [IN]    The pen event type
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL vadp_v2p_status_icon_bar_execute_pen_event_handler(S32 icon_id)
{
	MMI_BOOL result = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_SCREEN__
    //return wgui_status_icon_bar_execute_pen_event_handler(icon_id, WGUI_STATUS_ICON_BAR_PEN_LONG_PRESS_ICON);
   //kal_prompt_trace(MOD_IDLE,"ltz.......vadp_v2p_status_icon_bar_execute_pen_event_handler.....icon_id:%d..",icon_id);

	result = wgui_execute_status_icon_pen_event_hdlr(icon_id, WGUI_STATUS_ICON_BAR_PEN_SELECT_ICON);
#endif
	return result;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_status_icon_bar_translate_pen_event
 * DESCRIPTION
 *  Translate pen event of status icon bar
 * PARAMETERS
 *  pen_event       [IN]    The pen event of response by status icon bar
 *  x               [IN]    X coordinate of pen event
 *  y               [IN]    Y coordinate of pen event
 *  icon_id         [OUT]   Pointer to restore the icon id of response the pen event
 *  event_type      [OUT]   Pointer to restoe the status icon bar's event
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL vadp_v2p_status_icon_bar_translate_pen_event(
            S32 pen_event,
            S32 x,
            S32 y,
            S32 *icon_id)
{
	MMI_BOOL result = MMI_FALSE;
#ifdef __MMI_TOUCH_SCREEN__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_pen_enum event_type;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/*
    return wgui_status_icon_bar_translate_pen_event(
            (mmi_pen_event_type_enum)pen_event, 
            x,
            y, 
            icon_id, 
            &event_type);
 */
   //kal_prompt_trace(MOD_IDLE,"ltz.......vadp_v2p_status_icon_bar_translate_pen_event.....pen_event:%d..",pen_event);

	result = wgui_status_icon_translate_pen_event(
            (mmi_pen_event_type_enum)pen_event, 
            x,
            y, 
            (S16*)icon_id, 
            &event_type);
   //kal_prompt_trace(MOD_IDLE,"ltz.......vadp_v2p_status_icon_bar_translate_pen_event.....*icon_id:%d..,event_type:%d",*icon_id,event_type);
	
#endif
	return result;

}
#endif
/* Vogins End */

