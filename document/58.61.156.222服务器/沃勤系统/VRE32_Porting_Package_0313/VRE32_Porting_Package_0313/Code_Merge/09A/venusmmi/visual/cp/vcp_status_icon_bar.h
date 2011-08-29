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
 *  vcp_status_icon_bar.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VCP_STATUS_ICON_BAR_H__
#define __VCP_STATUS_ICON_BAR_H__

#ifndef __cplusplus
// If you don't allow C to include this file, remove following //
// #error "This header file can be used in C++ only."
#endif

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "cp\vcp_pluto_control.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
/* Vogins Start */
#ifdef __VRE__
 typedef void (*FuncPtr) (void);
#endif
/* Vogins End */
 
/***************************************************************************** 
 * Class VcpStatusIconBar
 *****************************************************************************/

/*
 * The description of this class
 *
 * EXAMPLE
 * <code>
 *   VcpStatusIconBar *icon_bar;
 *   VFX_OBJ_CREATE(icon_bar, VcpStatusIconBar, this);
 * </code>
 */
class VcpStatusIconBar : public VcpPlutoControl
{
    VFX_DECLARE_CLASS(VcpStatusIconBar);

// Constructor / Destructor
public:
    // Default constructor.
    VcpStatusIconBar();

// Method
public:
    //Show an icon with icon ID.
    void showIcon(
        VfxS32 iconId // [IN] Is the icon ID
    );

    //Blink an icon with icon ID.
    void blinkIcon(
        VfxS32 iconId // [IN] Is the icon ID
    );

    //Animate an icon with icon ID.
    void animateIcon(
        VfxS32 iconId // [IN] Is the icon ID
    );

    //Change an icon level with icon ID and level percentage (0 ~ 100).
    void changeIconLevel(
        VfxS32 iconId,  // [IN] Is the icon ID
        VfxU8 level_percentage // [IN] Is the level percetage (0 ~ 100)
    );

    //Change an icon's image with icon ID and image ID.
    void changeIconImage(
        VfxS32 iconId, // [IN] Is the icon ID
        VfxU16 image_id // [IN] Is the image ID
    );


/* Vogins Start */
#ifdef __VRE__
    //Register status icon pen event handler.
    void registerIconPenEvent(
        VfxS32 iconId,  // [IN] Enabel background or not.
        FuncPtr handler // [IN] The icon's pen handler 
    );
    
    //Reset all icon pen event handler.
    void resetAllIconPenEvent();
#endif
/* Vogins End */

// Override
protected:
    virtual void onPlutoCreate();

    virtual void onPlutoClose();

    virtual void onPlutoDraw();
/* Vogins Start */
#ifdef __VRE__
    virtual VfxBool onPlutoAcceptPenEvents() {return VFX_TRUE;}
#endif
/* Vogins End */
    
    virtual VfxBool onPlutoPenHandler(VfxS32 plutoPenEvent, VfxS16 x, VfxS16 y);

    virtual VfxBool onPlutoNeedDoubleBuffer() {return VFX_TRUE;}

    virtual VfxSize onPlutoGetPreferredSize();

};


#endif /* __VCP_STATUS_ICON_BAR_H__ */
