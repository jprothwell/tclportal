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
 *  vcp_status_icon_bar.cpp
 *
 * Project:
 * --------
 *  Venus UI Components
 *
 * Description:
 * ------------
 *  Status icon bar component (Adaptor to Pluto UI component )
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_uc_include.h"
#include "cp\vcp_pluto_control.h"
#include "cp\vcp_status_icon_bar.h"

extern "C"
{
    /* Pluto MMI headers */
    #include "MMI_features.h"
    #include "TouchScreenGprot.h"
    #include "gdi_include.h"
/* Vogins Start */
#ifdef __VRE__
    #include "gui_typedef.h"
#endif
/* Vogins End */

    /* Venus to pluto adaption layer header */
    #include "GUI\vadp_v2p_status_icon_bar.h"    
}

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("StatusIconBar", VcpStatusIconBar, VcpPlutoControl);


/***************************************************************************** 
 * Global function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  VcpStatusIconBar::VcpStatusIconBar
 * DESCRIPTION
 *  Constructor
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
VcpStatusIconBar::VcpStatusIconBar()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}


/*****************************************************************************
 * FUNCTION
 *  VcpStatusIconBar::showIcon
 * DESCRIPTION
 *  Show an icon with icon ID.
 * PARAMETERS
 *  iconId  [IN]    icon ID
 * RETURNS
 *  void
 *****************************************************************************/
void VcpStatusIconBar::showIcon(VfxS32 iconId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    vadp_v2p_show_icon(iconId);
}


/*****************************************************************************
 * FUNCTION
 *  VcpStatusIconBar::blinkIcon
 * DESCRIPTION
 *  Blink an icon with icon ID.
 * PARAMETERS
 *  iconId  [IN]    icon ID
 * RETURNS
 *  void
 *****************************************************************************/
void VcpStatusIconBar::blinkIcon(VfxS32 iconId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    vadp_v2p_blink_icon(iconId);
}


/*****************************************************************************
 * FUNCTION
 *  VcpStatusIconBar::animateIcon
 * DESCRIPTION
 *  Animate an icon with icon ID.
 * PARAMETERS
 *  iconId  [IN]    icon ID
 * RETURNS
 *  void
 *****************************************************************************/
void VcpStatusIconBar::animateIcon(VfxS32 iconId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    vadp_v2p_animate_icon(iconId);
}


/*****************************************************************************
 * FUNCTION
 *  VcpStatusIconBar::changeIconLevel
 * DESCRIPTION
 *  Change an icon level with icon ID and level percentage (0 ~ 100).
 * PARAMETERS
 *  iconId                  [IN]    icon ID
 *  level_percentage    [IN]    level percetage (0 ~ 100)
 * RETURNS
 *  void
 *****************************************************************************/
void VcpStatusIconBar::changeIconLevel(VfxS32 iconId, VfxU8 level_percentage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    vadp_v2p_change_icon_level(iconId, level_percentage);
}


/*****************************************************************************
 * FUNCTION
 *  VcpStatusIconBar::changeIconImage
 *  Change an icon's image with icon ID and image ID.
 * PARAMETERS
 *  iconId       [IN]    icon ID
 *  image_id    [IN]    image ID
 * RETURNS
 *  void
 *****************************************************************************/
void VcpStatusIconBar::changeIconImage(VfxS32 iconId, VfxU16 image_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    vadp_v2p_change_icon_image(iconId, image_id);
}


/*****************************************************************************
 * FUNCTION
 *  VcpStatusIconBar::enableBackground
 *  Enable background or disable
 * PARAMETERS
 *  enable       [IN]    Enable background or not.
 * RETURNS
 *  void
 *****************************************************************************/
void VcpStatusIconBar::enableBackground(VfxBool enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    vadp_v2p_status_icon_bar_set_backgroud((MMI_BOOL)enable);
}


/*****************************************************************************
 * FUNCTION
 *  VcpStatusIconBar::onPlutoCreate
 * DESCRIPTION
 *  Create the pluto control
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VcpStatusIconBar::onPlutoCreate()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    vadp_v2p_create_status_icon_bar(updateScreenForPluto,this, getLayerHandle());
/* Vogins Start */
#ifdef __VRE__
	//kal_prompt_trace(MOD_IDLE,"ltz...VcpStatusIconBar::onPlutoCreate.....");

	/*ltz 0612*/
	registerIconPenEvent(STATUS_ICON_VRE_1,(FuncPtr)vm_process_status_icon);
	registerIconPenEvent(STATUS_ICON_VRE_2,(FuncPtr)vm_process_status_icon);
	registerIconPenEvent(STATUS_ICON_VRE_3,(FuncPtr)vm_process_status_icon);
	registerIconPenEvent(STATUS_ICON_VRE_4,(FuncPtr)vm_process_status_icon);
	registerIconPenEvent(STATUS_ICON_VRE_DEFAULT,(FuncPtr)vm_process_status_icon);	
#endif
/* Vogins End */
}


/*****************************************************************************
 * FUNCTION
 *  VcpStatusIconBar::onPlutoClose
 * DESCRIPTION
 *  Close the pluto control
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VcpStatusIconBar::onPlutoClose()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    vadp_v2p_close_status_icon_bar();
}


/*****************************************************************************
 * FUNCTION
 *  VcpStatusIconBar::onPlutoDraw
 * DESCRIPTION
 *  Draw the pluto control
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VcpStatusIconBar::onPlutoDraw()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    vadp_v2p_show_status_icon_bar();
}


/*****************************************************************************
 * FUNCTION
 *  VcpStatusIconBar::onPlutoPenHandler
 * DESCRIPTION
 *  Handle pen event in pluto control way.
 * PARAMETERS
 *  plutoPenEvent   [IN]    Pen event
 *  x                    [IN]    Pen position
 *  y                    [IN]    Pen position
 * RETURNS
 *  Return VFX_TRUE if the event is handled
 *****************************************************************************/
VfxBool VcpStatusIconBar::onPlutoPenHandler(VfxS32 plutoPenEvent, VfxS16 x, VfxS16 y)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxBool ret = VFX_FALSE;
/* Vogins Start */
#ifdef __VRE__
    VfxS32 iconId;
    VfxBool plutoRet;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//kal_prompt_trace(MOD_IDLE,"ltz...onPlutoPenHandler...plutoPenEvent:%d, x:%d, y:%d.....",plutoPenEvent,x,y);

    if (plutoPenEvent == MMI_PEN_EVENT_DOWN)
    {
        plutoRet = vadp_v2p_status_icon_bar_translate_pen_event(
                    plutoPenEvent,
                    x,
                    y, 
                    &iconId);
        if (plutoRet)
        {
            vadp_v2p_status_icon_bar_execute_pen_event_handler(iconId);
            ret = VFX_TRUE;
        }
    }
#else
	VFX_UNUSED(plutoPenEvent);
    VFX_UNUSED(x);
    VFX_UNUSED(y);
#endif
/* Vogins End */

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  VcpStatusIconBar::onPlutoGetPreferredSize
 * DESCRIPTION
 *  Get the preferred size of pluto control
 * PARAMETERS
 *  void
 * RETURNS
 *  Return size of control
 *****************************************************************************/
VfxSize VcpStatusIconBar::onPlutoGetPreferredSize()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxS32 width, height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    vadp_v2p_get_prefered_size(&width, &height);

    return VfxSize(width, height);
}

/* Vogins Start */
#ifdef __VRE__
/*****************************************************************************
 * FUNCTION
 *  VcpStatusIconBar::registerIconPenEvent
 * DESCRIPTION
 *  Register icon pen event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VcpStatusIconBar::registerIconPenEvent(VfxS32 iconId, FuncPtr handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vadp_v2p_status_icon_bar_register_pen_event(iconId, handler);
}


/*****************************************************************************
 * FUNCTION
 *  VcpStatusIconBar::resetAllIconPenEvent
 * DESCRIPTION
 *  Reset all icon pen event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void VcpStatusIconBar::resetAllIconPenEvent()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vadp_v2p_status_icon_bar_reset_all_pen_event_handler();
}
#endif
/* Vogins End */

