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
 *  
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Internal UI componets of home screen
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN__

/*
 * Should define WIDGET_DEFINE_IN_SCR and include vapp_hs_widget_cfg.h at first 
 * for the widget creation function table.
 *
 * Should define SHORTCUT_DEFINE_IN_SCR and include vapp_hs_shortcut_cfg.h at 
 * first for the shortcut configuration function table.
 */
#define WIDGET_DEFINE_IN_SCR
#define SHORTCUT_DEFINE_IN_SCR
#include "vapp_hs_widget_cfg.h"
#include "vapp_hs_shortcut_cfg.h"


#include "vfx_uc_include.h"
#include "vapp_hs_res.h"
#include "vapp_hs_scr.h"
#include "vapp_hs_cp.h"
#include "trc/vadp_app_trc.h"


/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

#include "CustThemesRes.h"  /* UI_filled_area */
#include "fat_fs.h"         /* file system */
#include "DRM_gprot.h"

#ifdef __cplusplus
}
#endif


/***************************************************************************** 
 * Home screen app category
 *****************************************************************************/

// transparent while dragging widget or shortcut
const VfxFloat VappHsScr::s_moveOpacity = 0.65f;

// background is at most 1.5 of the desktop page
#if !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
const VfxFloat VappHsScr::s_backgroundScale = 1.5f;
#else
const VfxFloat VappHsScr::s_backgroundScale = 1.0f;
#endif /* !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__) */

// Delayed widget creation duration
#if !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
const VfxS32 VappHsScr::s_createDelayedDuration = 80;
#else
const VfxS32 VappHsScr::s_createDelayedDuration = 150;
#endif /* !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__) */

// Timer to close the widget bar if there is no user input.
const VfxS32 VappHsScr::s_closeWidgetBarDelay = 15000;

// Max widget on desktop
#if !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
const VfxS32 VappHsScr::s_maxDeskTopWidget = 10;
#else
const VfxS32 VappHsScr::s_maxDeskTopWidget = 10;
#endif /* !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__) */

// DRM right consumer
VfxS32 VappHsScr::s_drmConsumer = -1;


VappHsScr::VappHsScr(VfxU8 *setting, VfxU8 *history) :
    m_setting(NULL),
    m_history(NULL),
    m_settingCbf(NULL),
    m_imgBg(NULL),
    m_ni(NULL),
    m_ni2(NULL),
    m_idleModeText(NULL),
    m_widgetBar(NULL),
    m_blackScreen(NULL),
    m_shortcutBar(NULL),
    m_imageShortcutBarLeftArrow(NULL),
    m_imageShortcutBarRightArrow(NULL),
    m_shortcutPool(NULL),
    m_desktop(NULL),
    m_desktopIndicator(NULL),
    m_movingFrameS(NULL),
    m_movingFrameL(NULL),
    m_movingFrameOriParent(NULL),
    m_timerAddWidget(NULL),
    m_timerAddShortcut(NULL),
    m_timerCreateWidget(NULL),
    m_timerCloseWidgetBar(NULL)
{
    VfxS32 i;

    for (i = 0; i < TOTAL_WIDGET; i++)
    {
        m_widget[i]     = NULL;
        m_widgetIcon[i] = NULL;
    }

    for (i = 0; i < TOTAL_SHORTCUT; i++)
    {
        m_shortcut[i] = NULL;
    }

    m_setting = (Setting *)setting;
    m_history = (History *)history;
}


void VappHsScr::initWidget()
{
    VFX_LOG(VFX_STATE, VAPP_HS_INIT_WIDGET_MSG);

    const vapp_hs_widget_create_funcptr_type *tbl = g_vapp_hs_widget_create_tbl;
    
    for (VfxS32 i = 0; i < TOTAL_WIDGET; i++)
    {
        m_widget[i] = tbl[i](NULL);
        m_widget[i]->setIsCached(VFX_TRUE);
        m_widget[i]->m_signalDrag.connect(this, &VappHsScr::onControlDesktopDrag);
        m_widget[i]->m_signalMove.connect(this, &VappHsScr::onControlDesktopMove);
        m_widget[i]->m_signalDrop.connect(this, &VappHsScr::onControlDesktopDrop);

        // set widget icon for widget bar
        VFX_OBJ_CREATE(m_widgetIcon[i], VappHsDndImage, NULL);
        m_widgetIcon[i]->setIsCached(VFX_TRUE);
        m_widgetIcon[i]->setImageId(m_widget[i]->getIcon());
        m_widgetIcon[i]->m_scrollWay = VappHsDndImage::VERT_SCROLL;
        m_widgetIcon[i]->m_signalDrag.connect(this, &VappHsScr::onControlWidgetBarDrag);
        m_widgetIcon[i]->m_signalMove.connect(this, &VappHsScr::onControlWidgetBarMove);
        m_widgetIcon[i]->m_signalDrop.connect(this, &VappHsScr::onControlWidgetBarDrop);
        m_widgetIcon[i]->m_signalAbort.connect(this, &VappHsScr::onControlWidgetBarAbort);
    }
}


void VappHsScr::initShortcut()
{
    VFX_LOG(VFX_STATE, VAPP_HS_INIT_SHORTCUT_MSG);

    const VappHsShortcutCfg *tbl = g_vapp_hs_shortcut_tbl;
    
    for (VfxS32 i = 0; i < TOTAL_SHORTCUT; i++)
    {
        VFX_OBJ_CREATE(m_shortcut[i], VappHsDndImage, NULL);

        m_shortcut[i]->setImageId(tbl[i].iconId);
        m_shortcut[i]->m_signalDrag.connect(this, &VappHsScr::onControlShortcutDrag);
        m_shortcut[i]->m_signalMove.connect(this, &VappHsScr::onControlShortcutMove);
        m_shortcut[i]->m_signalDrop.connect(this, &VappHsScr::onControlShortcutDrop);
        m_shortcut[i]->m_signalAbort.connect(this, &VappHsScr::onControlShortcutAbort);
    }
}


VfxSize VappHsScr::getScreenSize()
{
    vrt_size_struct main_screen_size;
    vrt_color_type_enum main_screen_color_format;
    
    vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

    return VfxSize(main_screen_size.width, main_screen_size.height);
}


void VappHsScr::tuneWallpaper()
{
    VfxSize screenSize, imgSize;
    
    screenSize = getScreenSize();
    imgSize = m_imgBg->getBounds().size;

    if ((screenSize.width >= imgSize.width) &&
        (screenSize.height >= imgSize.height))
    {
        // Background image is smaller than the screen size. Centralize the 
        // image in both vertical and horizontal direction.
        VfxPoint p;

        p.x = (screenSize.width - imgSize.width) >> 1;
        p.y = (screenSize.height - imgSize.height) >> 1;

        VFX_LOG(VFX_INFO, VAPP_HS_DUMP_WALLPAPER_TUNING_MSG, 
                                100, p.x, p.y, imgSize.width, imgSize.height);

        m_imgBg->setPos(p);
    }
    else
    {
        // Background is larger than the screen size. 

        VfxS32 maxWidth;
        VfxFloat sx = 1.0, sy = 1.0, sMin;

        // Find the scaling ratio in the y-direction.
        if (imgSize.height > screenSize.height)
        {
            sy = (VfxFloat)screenSize.height / imgSize.height;
        }

        // Find the scaling ratio in the x-direction. The max. width is the 
        // controlled by the s_backgroundScale parameter.
        maxWidth = (VfxS32)(screenSize.width * s_backgroundScale);
        
        if (imgSize.width > maxWidth)
        {
            sx = (VfxFloat)maxWidth / imgSize.width;
        }

        sMin = (sx < sy? sx: sy);

        VfxRect rect = m_imgBg->getBounds();

        // Calculate the resized width (plus 0.5 to round to the nearest 
        // number).
        rect.size.width = (VfxS32)(sMin * rect.size.width + 0.5);

        if (rect.size.width <= 0)
        {
            rect.size.width = 1;
        }

        if (rect.size.width > maxWidth)
        {
            rect.size.width = maxWidth;
        }
        
        // Calculate the resized height (plus 0.5 to round to the nearest 
        // number).        
        rect.size.height = (VfxS32)(sMin * rect.size.height + 0.5);

        if (rect.size.height <= 0)
        {
            rect.size.height = 1;
        }

        if (rect.size.height > screenSize.height)
        {
            rect.size.height = screenSize.height;
        }

        // Set up the content placement & resize property.        
        m_imgBg->setBounds(rect);
        m_imgBg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

        imgSize = rect.size; // re-get the new image bounds
        
        // Vertical: alway central-alignment.
        //
        // Horizontal: 
        //      1) small than screen width: left-alignment
        //      2) otherwise, central-alignment
        
        VfxPoint p;

        p.y = (screenSize.height - imgSize.height) >> 1;

        if (imgSize.width > screenSize.width)
        {
            p.x = 0;
        }
        else
        {
            p.x = (screenSize.width - imgSize.width) >> 1;
        }

        VFX_LOG(VFX_INFO, VAPP_HS_DUMP_WALLPAPER_TUNING_MSG, 
                                200, p.x, p.y, imgSize.width, imgSize.height);

        m_imgBg->setPos(p);
    }
}


void VappHsScr::stopDrmRight(VfxS32 result, VfxS32 id)
{
    VFX_UNUSED(result);
    VFX_UNUSED(id);
    
#ifdef __DRM_SUPPORT__
    VFX_LOG(VFX_WARNING, VAPP_HS_STOP_DRM_RIGHT_MSG);

    // This function is the callback when DRM grants the right, but some error
    // happens during the usage of the content. For example, the error might be 
    // the DRM right expires.
    if (s_drmConsumer >= DRM_RESULT_OK)
    {
        DRM_stop_consume(s_drmConsumer);
        s_drmConsumer = -1; // reset
    }
#endif /* __DRM_SUPPORT__ */
}


VfxBool VappHsScr::getWallpaperDRMRight(
    VfxWChar *filename, 
    VfxBool &isProhibited)
{
    FS_HANDLE handle;
    VfxBool ret = VFX_TRUE; // default

    VFX_LOG(VFX_STATE, VAPP_HS_GET_WALLPAPER_DRM_RIGHT_MSG);

    isProhibited = VFX_FALSE;

    handle = DRM_open_file(filename, FS_READ_ONLY, DRM_PERMISSION_DISPLAY);
    
    VFX_LOG(VFX_INFO, VAPP_HS_DUMP_WALLPAPER_DRM_RESULT_MSG, 100, (VfxS32)handle);

    if (handle >= FS_NO_ERROR)
    {
    #ifdef __DRM_SUPPORT__
        // Check DRM right is granted or not.
        if (DRM_validate_forward_rule(handle, DRM_PERMISSION_DISPLAY))
        {
            VFX_LOG(VFX_INFO, VAPP_HS_DUMP_WALLPAPER_DRM_RESULT_MSG, 200, 0);
            
            s_drmConsumer = DRM_consume_rights(
                                handle, 
                                DRM_PERMISSION_DISPLAY, 
                                VappHsScr::stopDrmRight);
            ret = VFX_TRUE;
        }
        else
        {
            VFX_LOG(VFX_INFO, VAPP_HS_DUMP_WALLPAPER_DRM_RESULT_MSG, 201, 0);
            
            isProhibited = VFX_TRUE; // failed because of DRM prohibited
            ret = VFX_FALSE;
        }
    #endif /* __DRM_SUPPORT__ */
    
        VFX_LOG(VFX_INFO, VAPP_HS_DUMP_WALLPAPER_DRM_RESULT_MSG, 203, 0);

        DRM_close_file(handle);
    }
    else
    {
        VFX_LOG(VFX_INFO, VAPP_HS_DUMP_WALLPAPER_DRM_RESULT_MSG, 300, 0);

        ret = VFX_FALSE;
    }

    return ret;
}


void VappHsScr::initWallpaper()
{
    VfxU16 id;
    VfxWChar* filename;
    VfxBool isProhibited, isSuccess;

    VFX_LOG(VFX_STATE, VAPP_HS_INIT_WALLPAPER_MSG);

    isProhibited = VFX_FALSE;
    isSuccess = VFX_FALSE;

    // Priority 1: 
    // Take the wallpaper from the image resource or from the theme.

    id = vadp_v2p_hs_get_wallpaper_id();
    
    if (!isSuccess && id != 0)
    {
        if (!vadp_v2p_hs_phnset_check_themeid_wallpaper(id))
        {
            VFX_LOG(VFX_INFO, VAPP_HS_DUMP_WALLPAPER_SRC_RESULT_MSG, 100, id);
            
            // from image resource
            VfxImageFrame *imgBg;
            
            VFX_OBJ_CREATE(imgBg, VfxImageFrame, this);
            imgBg->setResId(id);

            m_imgBg = imgBg; // save
        }
        else
        {
            VFX_LOG(VFX_INFO, VAPP_HS_DUMP_WALLPAPER_SRC_RESULT_MSG, 101, 0);
            
            // from theme
            VfxRectFrame *imgBg;
            
            VFX_OBJ_CREATE(imgBg, VfxRectFrame, this);
            imgBg->setBounds(VfxRect(VfxPoint(0, 0), getScreenSize()));
            imgBg->setFilledArea(vadp_v2p_hs_get_theme_bg_filled_area());

            m_imgBg = imgBg; // save
        }
        
        isSuccess = VFX_TRUE;
    }

    // Priority 2: 
    // From image file in ME. We should use the original wallpaper file to 
    // check whether the file is present and whether the DRM is granted. Use 
    // the cached file for display alternatively.
    
    filename = vadp_v2p_hs_get_wallpaper_filename_original();
    
    if (!isSuccess && filename)
    {
        VfxBool is_granted = getWallpaperDRMRight(filename, isProhibited);

        VFX_LOG(VFX_INFO, VAPP_HS_DUMP_WALLPAPER_SRC_RESULT_MSG, 200, (VfxS32)is_granted);
        
        if (is_granted)
        {
            VfxImageFrame *imgBg;
            
            VFX_OBJ_CREATE(imgBg, VfxImageFrame, this);

            filename = vadp_v2p_hs_get_wallpaper_filename_cached();
            
            imgBg->setSrc(VFX_WSTR_MEM(filename));

            m_imgBg = imgBg; // save
            
            isSuccess = VFX_TRUE;
        }
    }

    // Priority 3: 
    // Error. Callback to phone setup. It will display a popup and reset the 
    // wallpaper to the default one. After the popup disappears, the idle screen 
    // will be redrawed.

    if (!isSuccess)
    {
        VFX_LOG(VFX_INFO, VAPP_HS_DUMP_WALLPAPER_SRC_RESULT_MSG, 300, 0);
        
        vadp_v2p_hs_phnset_wallpaper_bad_file_callback(isProhibited);
    }

    // Finally:
    // If the wallpaper is present, set the property and tune the size and
    // position. 
    // 
    // The default background color should be the same as the background color 
    // of App category such that if the wallpaper is translucent, the colors are
    // the same.
    
    if (m_imgBg)
    {
        m_imgBg->setAutoAnimate(VFX_TRUE);
        m_imgBg->setBgColor(VFX_COLOR_BLACK);
        m_imgBg->setIsCached(VFX_TRUE);
        m_imgBg->setIsOpaque(VFX_TRUE);

        tuneWallpaper();
    }
}
    

void VappHsScr::onInit()
{
    VFX_LOG(VFX_STATE, VAPP_HS_ON_INIT_MSG);

    VcpAppScr::onInit();

    // background color
    setBgColor(VFX_COLOR_BLACK);

    // init wallpaper
    initWallpaper();
//vogins begin
    #ifndef __VRE30_AM__
    //init status icon
    VappHsStatusIcon *statusIcon;
    VFX_OBJ_CREATE(statusIcon, VappHsStatusIcon, this);
   #endif
//vogins end
    // network operator name and status
    VFX_OBJ_CREATE(m_ni, VappHsNetworkInfo, this);
    m_ni->setPos(VfxPoint(NET_INFO_X, NET_INFO_Y));
    m_ni->setBounds(VfxRect(0, 0, NET_INFO_WIDTH, NET_INFO_HEIGHT));

    VFX_OBJ_CREATE(m_ni2, VappHsNetworkInfo, this);
    m_ni2->setPos(VfxPoint(NET_INFO_X, NET_INFO_Y + NET_INFO_HEIGHT + NET_INFO_GAP));
    m_ni2->setBounds(VfxRect(0, 0, NET_INFO_WIDTH, NET_INFO_HEIGHT));
    
    VdatNetworkInfo *networkSrv = VFX_OBJ_GET_INSTANCE(VdatNetworkInfo);
    
    networkSrv->m_signalNameChanged.connect(this, &VappHsScr::onNetworkNameChanged);
    networkSrv->m_signalStatusChanged.connect(this, &VappHsScr::onNetworkStatusChanged);
    
    networkSrv->m_signalNameChanged2.connect(this, &VappHsScr::onNetworkNameChanged2);
    networkSrv->m_signalStatusChanged2.connect(this, &VappHsScr::onNetworkStatusChanged2);

    // init idle mode text
    VFX_OBJ_CREATE(m_idleModeText, VappHsIdleModeText, this);
    
    networkSrv->m_signalIdleModeTextChanged.connect(this, &VappHsScr::onIdleModeTextChanged);
    networkSrv->m_signalIdleModeIconChanged.connect(this, &VappHsScr::onIdleModeIconChanged);

    // Update here; or the text will appear later when the home screen is shown.
    onNetworkNameChanged(networkSrv);
    onNetworkStatusChanged(networkSrv);
    onNetworkNameChanged2(networkSrv);
    onNetworkStatusChanged2(networkSrv);
    onIdleModeTextChanged(networkSrv);
    onIdleModeIconChanged(networkSrv);

    // init desktop
    VFX_OBJ_CREATE(m_desktop, VappHsDesktop, this);
    VFX_OBJ_CREATE(m_desktopIndicator, VappHsDesktopIndicator, this);
    m_desktop->m_signalBoundsChanged.connect(this, &VappHsScr::onDesktopBoundsChanged);

    setHistoryDesktop();

//vogins begin
#if defined(__VRE30_AM__)
       // init status icon
    VappHsStatusIcon *statusIcon;
    VFX_OBJ_CREATE(statusIcon, VappHsStatusIcon, this);
#endif
//vogins end

	
    // init widget bar
    VFX_OBJ_CREATE(m_widgetBar, VappHsWidgetBar, this);

    m_widgetBar->m_signalUpdateFolding.connect(this, &VappHsScr::onWidgetBarUpdateFolding);

    VFX_OBJ_CREATE(m_timerCloseWidgetBar, VfxTimer, this);
    m_timerCloseWidgetBar->setStartDelay(s_closeWidgetBarDelay);
    m_timerCloseWidgetBar->m_signalTick.connect(this, &VappHsScr::onCloseWidgetBar);
    
    // init widget
    initWidget();

    VFX_OBJ_CREATE(m_timerCreateWidget, VfxTimer, this);
    
    setSettingWidget();
    setHistoryWidget();

    // init black screen
    VFX_OBJ_CREATE(m_blackScreen, VappHsBlackScreen, this);
    m_blackScreen->setHidden(VFX_TRUE);
    m_blackScreen->m_signalDown.connect(this, &VappHsScr::onBlackScreenDown);

    // init shortcut bar background image
    VfxImageFrame *shortcutBgImage;
    VFX_OBJ_CREATE(shortcutBgImage, VfxImageFrame, this);
    shortcutBgImage->setResId(VAPP_HS_IMG_SC_BAR_BG);
    shortcutBgImage->setPos(VfxPoint(VappHsShortcutBar::X_POS, VappHsShortcutBar::Y_POS));
    shortcutBgImage->setIsCached(VFX_TRUE);
#if defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
    shortcutBgImage->setIsOpaque(VFX_TRUE);
#endif

    VFX_OBJ_CREATE(m_imageShortcutBarLeftArrow, VfxImageFrame, this);
    m_imageShortcutBarLeftArrow->setResId(VAPP_HS_IMG_SC_BAR_LEFT_ARROW);
    m_imageShortcutBarLeftArrow->setAnchor(VfxFPoint(0.0, 0.5));
    m_imageShortcutBarLeftArrow->setPos(VfxPoint(VappHsShortcutBar::X_POS, VappHsShortcutBar::Y_POS + VappHsShortcutBar::Y_OFFSET));
    m_imageShortcutBarLeftArrow->setOpacity(0.0f);
    m_imageShortcutBarLeftArrow->setAutoAnimate(VFX_TRUE);

    VFX_OBJ_CREATE(m_imageShortcutBarRightArrow, VfxImageFrame, this);
    m_imageShortcutBarRightArrow->setResId(VAPP_HS_IMG_SC_BAR_RIGHT_ARROW);
    m_imageShortcutBarRightArrow->setAnchor(VfxFPoint(1.0, 0.5));
    m_imageShortcutBarRightArrow->setPos(VfxPoint(VappHsShortcutBar::X_POS + shortcutBgImage->getBounds().getWidth(), VappHsShortcutBar::Y_POS + VappHsShortcutBar::Y_OFFSET));
    m_imageShortcutBarRightArrow->setOpacity(0.0f);
    m_imageShortcutBarRightArrow->setAutoAnimate(VFX_TRUE);

    // init shortcut
    initShortcut();

    // init shortcut bar and shortcut pool
    VFX_OBJ_CREATE(m_shortcutBar, VappHsShortcutBar, this);
    VFX_OBJ_CREATE(m_shortcutPool, VappHsShortcutPool, this);

    m_shortcutBar->m_signalUpdateIndicator.connect(this, &VappHsScr::onShortcutBarUpdateIndicators);

    setSettingShortcut();
    setHistoryShortcut();

    // Timer to add widget to the widget bar.
    VFX_OBJ_CREATE(m_timerAddWidget, VfxTimer, this);
    m_timerAddWidget->setStartDelay(DEFAULT_AUTO_ANIMATE_TIME);
    m_timerAddWidget->m_signalTick.connect(this, &VappHsScr::onTimerAddWidget);

    VFX_OBJ_CREATE(m_timerAddShortcut, VfxTimer, this);
    m_timerAddShortcut->setStartDelay(DEFAULT_AUTO_ANIMATE_TIME);
    m_timerAddShortcut->m_signalTick.connect(this, &VappHsScr::onTimerAddShortcut);
}


void VappHsScr::onDeinit()
{
    VFX_LOG(VFX_STATE, VAPP_HS_ON_DEINIT_MSG);

#ifdef __DRM_SUPPORT__
    if (s_drmConsumer >= DRM_RESULT_OK)
    {
        DRM_stop_consume(s_drmConsumer);
        s_drmConsumer = -1; // reset
    }
#endif /* __DRM_SUPPORT__ */

    // In case that the widget is on the dropping animation when the App
    // category is deleted, immeidately emit the signal such that the widget is
    // put into the widget bar and the widget setting can be updated.
    if (m_timerAddWidget->getIsEnabled())
    {
        onTimerAddWidget(m_timerAddWidget);
    }

    // Similar reason as the above. Let the shortcut put into the shortcut pool
    // or shortcut bar and the shortcut setting can be updated.
    if (m_timerAddShortcut->getIsEnabled())
    {
        onTimerAddShortcut(m_timerAddShortcut);
    }

    // Disconnect signal for network operator name and status
    VdatNetworkInfo *networkSrv = VFX_OBJ_GET_INSTANCE(VdatNetworkInfo);
    
    networkSrv->m_signalNameChanged.disconnect(this, &VappHsScr::onNetworkNameChanged);
    networkSrv->m_signalStatusChanged.disconnect(this, &VappHsScr::onNetworkStatusChanged);
    
    networkSrv->m_signalNameChanged2.disconnect(this, &VappHsScr::onNetworkNameChanged2);
    networkSrv->m_signalStatusChanged2.disconnect(this, &VappHsScr::onNetworkStatusChanged2);

    networkSrv->m_signalIdleModeTextChanged.disconnect(this, &VappHsScr::onIdleModeTextChanged);
    networkSrv->m_signalIdleModeIconChanged.disconnect(this, &VappHsScr::onIdleModeIconChanged);

    for (VfxS32 i = 0 ; i < TOTAL_WIDGET ; i ++)
    {
        m_widget[i]->releaseView();
        VFX_OBJ_CLOSE(m_widget[i]);
        VFX_OBJ_CLOSE(m_widgetIcon[i]);
    }

    VcpAppScr::onDeinit();
}


VfxBool VappHsScr::onPreviewPenInput(VfxPenEvent &event)
{
    VFX_LOG(VFX_INFO3, VAPP_HS_ON_PREVIEW_PEN_INPUT_MSG, 0, event.pos.x, event.pos.y);

    // If some widget is during the dropping animation, drop it immediately such
    // that the state of the widget DnD mechanism can be reset, e.g., the 
    // m_movingFrameS, m_movingFrameL variables and etc.
    if (m_timerAddWidget->getIsEnabled())
    {
        VFX_LOG(VFX_INFO, VAPP_HS_ON_PREVIEW_PEN_INPUT_MSG, 1, event.pos.x, event.pos.y);
        
        m_timerAddWidget->m_signalTick.emit(m_timerAddWidget);
        m_timerAddWidget->stop();
    }

    // If some shortcut is during the dropping animation, drop it immediately
    // such that the state of the shortcut DnD mechanism can be reset.
    if (m_timerAddShortcut->getIsEnabled())
    {
        VFX_LOG(VFX_INFO, VAPP_HS_ON_PREVIEW_PEN_INPUT_MSG, 2, event.pos.x, event.pos.y);
        
        m_timerAddShortcut->m_signalTick.emit(m_timerAddShortcut);
        m_timerAddShortcut->stop();
    }

    if (m_timerCloseWidgetBar->getIsEnabled())
    {
        VFX_LOG(VFX_INFO, VAPP_HS_ON_PREVIEW_PEN_INPUT_MSG, 3, event.pos.x, event.pos.y);

        if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
        {
            // For pen event down, start a infinite timer such that the widget 
            // bar is not close during a pen event cycle, i.e. DOWN, MOVE, UP or 
            // ABORT. (0xFFFFFFFF is about 49 days.)
            m_timerCloseWidgetBar->setStartDelay(0xFFFFFFFF);
            m_timerCloseWidgetBar->start(); // will stop and restart
        }
        else if (event.type == VFX_PEN_EVENT_TYPE_UP ||
                 event.type == VFX_PEN_EVENT_TYPE_ABORT)
        {
            // After the pen event cycle finishes, restart the timer with
            // the pre-defined delayed time.
            m_timerCloseWidgetBar->setStartDelay(s_closeWidgetBarDelay);
            m_timerCloseWidgetBar->start(); // will stop and restart
        }
    }
    
    return VFX_FALSE;
}


void VappHsScr::onTimerAddWidget(VfxTimer *timer)
{
    VFX_UNUSED(timer);
    
    VFX_LOG(VFX_STATE, VAPP_HS_ON_TIMER_ADD_WIDGET_MSG, 0);
    
    if (m_movingFrameS) 
    {
        VFX_LOG(VFX_STATE, VAPP_HS_ON_TIMER_ADD_WIDGET_MSG, 1);

        m_movingFrameS->removeFromParent();

        m_movingFrameOriParent->restoreImage(
            m_movingFrameS,
            VFX_FALSE,      // do not blink the image icon
            VFX_FALSE);     // do not re-arrange the widget bar
        
        m_movingFrameS = NULL;
    }
    
    if (m_movingFrameL) 
    {
        VFX_LOG(VFX_STATE, VAPP_HS_ON_TIMER_ADD_WIDGET_MSG, 2);

        // TODO: comment
        m_movingFrameL->setHidden(VFX_FALSE);
        
        // Do not need widget view
        m_movingFrameL->removeFromParent();
        m_movingFrameL->releaseView();
        m_movingFrameL = NULL;
    }

    if (m_settingCbf)
    {
        m_settingCbf();
    }
}


void VappHsScr::onTimerAddShortcut(VfxTimer *timer)
{
    VFX_UNUSED(timer);

    VFX_LOG(VFX_STATE, VAPP_HS_ON_TIMER_ADD_SHORTCUT_MSG, 0);
    
    if (m_movingFrameS) 
    {
        VFX_LOG(VFX_STATE, VAPP_HS_ON_TIMER_ADD_SHORTCUT_MSG, 1);

        m_movingFrameS->removeFromParent();
        
        m_movingFrameOriParent->restoreImage(
            m_movingFrameS, 
            VFX_FALSE,      // do not blink the image icon
            VFX_FALSE);     // do not re-arrange the widget bar
            
        m_movingFrameS = NULL;
    }

    if (m_settingCbf)
    {
        m_settingCbf();
    }
}


void VappHsScr::previewDrop(
    VappHsInteractiveImageArray *dst, 
    VfxPenEvent &event,
    VfxPoint &currentPos, 
    VfxPoint &finalPos)
{
    currentPos = m_movingFrameS->getPos();
    
    dst->insertImage(m_movingFrameS, event);

    VfxRect bounds = m_movingFrameS->getBounds();
    VfxPoint midPoint = VfxPoint(bounds.getMidX(), bounds.getMidY());
    
    finalPos = m_movingFrameS->convertPointTo(midPoint, this);
    
    // Re-add the icon view to the APP category.
    dst->backupImage(m_movingFrameS);
    dst->removeImage(m_movingFrameS, VFX_FALSE);

    m_movingFrameOriParent = dst;
    
    addChild(m_movingFrameS);
}


void VappHsScr::previewDropExt(VfxPoint &currentPos, VfxPoint &finalPos)
{
    currentPos = m_movingFrameS->getPos();

    m_movingFrameOriParent->restoreImage(m_movingFrameS, VFX_FALSE);
    
    VfxRect bounds = m_movingFrameS->getBounds();
    VfxPoint midPoint = VfxPoint(bounds.getMidX(), bounds.getMidY());
    
    finalPos = m_movingFrameS->convertPointTo(midPoint, this);
    
    // Re-add the icon view to the APP category.
    m_movingFrameOriParent->backupImage(m_movingFrameS);
    m_movingFrameOriParent->removeImage(m_movingFrameS, VFX_FALSE);
    
    addChild(m_movingFrameS);
}


VfxS32 VappHsScr::getActiveWidgetNum()
{
    const VfxFrame *iter;
    VfxS32 i, count = 0;
    
    // in desktop widget
    for (iter = m_desktop->getFirstChildFrame(); 
         iter != NULL; 
         iter = iter->getNextFrame())
    {
        // skip non-widget frame
        for (i = 0; i < TOTAL_WIDGET; i++)
        {
            if (iter == m_widget[i])
            {
                break;
            }
        }

        if (i == TOTAL_WIDGET)
        {
            continue; // this is a non-widget frame
        }

        ++count;
    }

    return count;
}


void VappHsScr::resetAnchor(VfxFrame *frame, VfxPoint &offset)
{
    VfxPoint pos = frame->getPos();
    pos.x -= offset.x;
    pos.y -= offset.y;
    
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    frame->setPos(pos);
    frame->setAnchor(VfxFPoint(0.5f, 0.5f));
    VfxAutoAnimate::commit();
}


void VappHsScr::setAnchor(VfxFrame *frame, VfxPoint &offset)
{
    VfxRect rect = frame->getBounds();

    // TODO: getMidX and getMidY does not round to the nearest number. Plus 0.5
    // here by ourself.
    VfxFloat x = (VfxFloat)(offset.x + rect.getMidX() + 0.5f) / rect.getWidth();
    VfxFloat y = (VfxFloat)(offset.y + rect.getMidY() + 0.5f) / rect.getHeight();

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    frame->setAnchor(VfxFPoint(x, y));
    VfxAutoAnimate::commit();
}


void VappHsScr::getScaleRatio(
    VfxFrame *to, 
    VfxFrame *from, 
    VfxFloat &x, 
    VfxFloat &y)
{
    VfxSize toSize = to->getBounds().size;
    VfxSize fromSize = from->getBounds().size;

    x = (VfxFloat)toSize.width / fromSize.width;
    y = (VfxFloat)toSize.height / fromSize.height;
}


void VappHsScr::getOffset(
    VfxControl *frame,
    VfxPenEvent &event,
    VfxPoint &offset)
{
    VfxRect bounds = frame->getBounds();
    VfxPoint penPos = event.getRelPos(frame);
    
    offset.x = penPos.x - bounds.getMidX();
    offset.y = penPos.y - bounds.getMidY();
}


void VappHsScr::setWidgetDrag(
    VappHsDndImage *image, 
    VappHsWidget *widget,
    VfxPenEvent &event, 
    VfxBool isFromImage)
{
    m_movingFrameS = image;
    m_movingFrameL = widget;

    // Set icon to widget transform matrix.
    m_trS2l.init(VRT_TRANSFORM_TYPE_AFFINE);
    getScaleRatio(
        m_movingFrameL,             // to
        m_movingFrameS,             // from
        m_trS2l.data.affine.sx, 
        m_trS2l.data.affine.sy);

    // Set widget to icon transform matrix.
    m_trL2s.init(VRT_TRANSFORM_TYPE_AFFINE);
    getScaleRatio(
        m_movingFrameS,             // to
        m_movingFrameL,             // from
        m_trL2s.data.affine.sx, 
        m_trL2s.data.affine.sy);

    if (isFromImage)
    {
        // Calculate the widget pen offset (from middle point to the pen point).
        m_penPointOffsetL.x = (VfxS32)(m_penPointOffsetS.x * m_trS2l.data.affine.sx);
        m_penPointOffsetL.y = (VfxS32)(m_penPointOffsetS.y * m_trS2l.data.affine.sy);
    }
    else
    {
        // Calculate the icon pen offset (from middle point to the pen point).
        m_penPointOffsetS.x = (VfxS32)(m_penPointOffsetL.x * m_trL2s.data.affine.sx);
        m_penPointOffsetS.y = (VfxS32)(m_penPointOffsetL.y * m_trL2s.data.affine.sy);
    }

    // Initialization (disable auto. animation during initialization)

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);

    setAnchor(m_movingFrameS, m_penPointOffsetS);
    setAnchor(m_movingFrameL, m_penPointOffsetL);
    
    m_movingFrameS->setPos(event.getRelPos(this));
    m_movingFrameL->setPos(m_movingFrameS->getPos());

    if (isFromImage)
    {   
        // drag from widge bar
    #if !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)    
        m_movingFrameS->setTransform(VFX_TRANSFORM_IDENTITY);
        m_movingFrameL->setTransform(m_trL2s);
    #endif /* !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__) */

        m_movingFrameS->setOpacity(1.0f);
        m_movingFrameL->setOpacity(0.0f);
    }
    else
    {   
    #if !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
        m_movingFrameS->setTransform(m_trS2l);
        m_movingFrameL->setTransform(VFX_TRANSFORM_IDENTITY);
    #endif /* !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__) */

        m_movingFrameS->setOpacity(0.0f);
        m_movingFrameL->setOpacity(1.0f);
    }

    VfxAutoAnimate::commit();

    // Use auto animation for the opacity of the active item.
    
    if (isFromImage)
    {   
        m_movingFrameS->setOpacity(s_moveOpacity);
    }
    else
    {   
        m_movingFrameL->setOpacity(s_moveOpacity);
    }
    
    // Add icon and widget in the App category.
    addChild(m_movingFrameS);
    addChild(m_movingFrameL);
}


void VappHsScr::setWidgetMove(VfxPenEvent &event)
{
    if (m_movingFrameS && m_movingFrameL)
    {
        VfxRect barBounds = m_widgetBar->getBounds();

        if ((m_widgetBar->isUnfold() && m_widgetBar->containPoint(event.getRelPos(m_widgetBar))) ||
            (!m_widgetBar->isUnfold() && barBounds.contains(event.getRelPos(m_widgetBar))))
        {   
            // Inside widget bar.

            if (!m_widgetBar->isUnfold())
            {
                m_widgetBar->unfold();
            }

        #if !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
            m_movingFrameS->setTransform(VFX_TRANSFORM_IDENTITY);
            m_movingFrameL->setTransform(m_trL2s);
        #endif /* !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__) */

            m_movingFrameS->setOpacity(s_moveOpacity);
            m_movingFrameL->setOpacity(0.0f);

            m_widgetBar->cross(event);
        }
        else
        {   
            // Outside widget bar.
            
        #if !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
            m_movingFrameS->setTransform(m_trS2l);
            m_movingFrameL->setTransform(VFX_TRANSFORM_IDENTITY);
        #endif /* !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__) */

            m_movingFrameS->setOpacity(0.0f);
            m_movingFrameL->setOpacity(s_moveOpacity);

            m_widgetBar->arrange(-1);
        }

        // Force the position to make the moving smooth and real-time.
        VfxPoint pos = event.getRelPos(this);
        m_movingFrameS->forcePos(pos);
        m_movingFrameL->forcePos(pos);
    }
}


void VappHsScr::setWidgetDrop(VfxPenEvent &event, VfxBool isRestore)
{
    if (m_movingFrameS && m_movingFrameL)
    {
        resetAnchor(m_movingFrameS, m_penPointOffsetS);
        resetAnchor(m_movingFrameL, m_penPointOffsetL);
        
        if (isRestore)
        {
            // Scenario: 
            //  Abort the dragging operation. 
            //
            //  This happens when the user intends to scroll the widget bar, 
            //  rather than drag the widget.
            //
            // Icon view: 
            //  Set to the original size and opacity. Restore to previous 
            //  position for scrolling.
            //
            // Widget view:
            //  It is not needed. Release widget view.
            
        #if !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
            m_movingFrameS->setTransform(VFX_TRANSFORM_IDENTITY);
        #endif
            m_movingFrameS->setOpacity(1.0f);
        
            m_movingFrameS->removeFromParent();
            m_movingFrameOriParent->restoreImage(m_movingFrameS);
            m_movingFrameS = NULL;
            
            m_movingFrameL->removeFromParent();
            m_movingFrameL->releaseView();
            m_movingFrameL = NULL;
        }
        else if (m_widgetBar->containPoint(event.getRelPos(m_widgetBar)))
        {
            // THIS PART IS COMPLICATED. BE PATIENT.
            //
            // Scenario:
            //  Drop on the widget bar.
            //
            // Problem: 
            //  If we directly add the icon view to the widget bar, the icon
            //  view might be cutted by the bounds of the widget bar.
            //
            // Solution:
            //  1) Preview the final position of the icon
            //  2) Add the icon back to the App category
            //  3) Animate the icon to its final position
            //  4) Start a timer to callback when the animation completes
            //  5) When timer fires, add the widget to the widget bar
            
        #if !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
            m_movingFrameS->setTransform(VFX_TRANSFORM_IDENTITY);
        #endif
            m_movingFrameS->setOpacity(1.0f);

            VfxPoint currentPos, finalPos;

            previewDrop(m_widgetBar, event, currentPos, finalPos);
            
            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDisable(VFX_TRUE);
            m_movingFrameS->setPos(currentPos);
            VfxAutoAnimate::commit();
            
            m_movingFrameS->setPos(finalPos);

            // TODO: add comment
            m_movingFrameL->setHidden(VFX_TRUE);

            m_timerAddWidget->start();
        }
        else if (getActiveWidgetNum() >= s_maxDeskTopWidget)
        {
            // THIS PART IS COMPLICATED. BE PATIENT.
            //
            // Scenario:
            //  Drop on the desktop. But #widget exceeds the max number.
            //
            // Problem and Solution:
            //  Similar as the above one. But, we let the widget view directly
            //  change to the icon view at the begining.
            
            VfxPoint currentPos, finalPos;
            
            previewDropExt(currentPos, finalPos);
            
            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDisable(VFX_TRUE);
            
        #if !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
            m_movingFrameS->setTransform(VFX_TRANSFORM_IDENTITY);
        #endif
            m_movingFrameS->setPos(currentPos);
            m_movingFrameS->setOpacity(1.0f);
            
            VfxAutoAnimate::commit();
            
            m_movingFrameS->setPos(finalPos);

            // TODO: add comment
            m_movingFrameL->setHidden(VFX_TRUE);

            m_timerAddWidget->start();
        }
        else
        {
            // Scenario: 
            //  Drop on the desktop.
            //
            // Icon View:
            //  It isn't needed. Remove it from App category.
            //
            // Widget view:
            //  Set to the original size and opacity. Put it on the desktop.

            m_movingFrameS->removeFromParent();
            m_movingFrameS = NULL;
            
        #if !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
            m_movingFrameL->setTransform(VFX_TRANSFORM_IDENTITY);
        #endif
            m_movingFrameL->setOpacity(1.0f);

            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDisable(VFX_TRUE);
            VfxPoint pos = m_movingFrameL->getPos();
            m_movingFrameL->setPos(convertPointTo(pos, m_desktop));
            VfxAutoAnimate::commit();
        
            m_desktop->addWidget(m_movingFrameL);
            m_movingFrameL = NULL;

            // Handle the case that pen-up comes without any pen-move thus the 
            // widget bar is never re-arranged. (MAUI_01758400)
            m_widgetBar->arrange(-1);

            if (m_settingCbf)
            {
                m_settingCbf();
            }
        }
    }
}


void VappHsScr::onControlWidgetBarDrag(
    VappHsDndImage *image, 
    VfxPenEvent &event)
{
    VappHsWidget *widget = NULL;

    VFX_LOG(VFX_STATE, VAPP_HS_ON_CONTROL_WIDGET_BAR_DRAG_MSG, image->getImageId(), event.pos.x, event.pos.y);

    // backup original image info for restore
    m_movingFrameOriParent = m_widgetBar;
    m_movingFrameOriParent->backupImage(image);

    // Get the icon pen offset (from middle point to the pen point).
    getOffset(image, event, m_penPointOffsetS);

    // remvoe image from widget bar
    m_widgetBar->removeImage(image, VFX_FALSE);

    // find widget
    for (VfxS32 i = 0 ; i < TOTAL_WIDGET ; i++)
    {
        if (m_widgetIcon[i] == image)
        {
            widget = m_widget[i];
            break;
        }
    }
    VFX_ASSERT(widget);

    // create widget view
    widget->createView();

    setWidgetDrag(image, widget, event, VFX_TRUE);
}


void VappHsScr::onControlWidgetBarMove(
    VappHsDndImage *image, 
    VfxPenEvent &event)
{
    VFX_LOG(VFX_STATE, VAPP_HS_ON_CONTROL_WIDGET_BAR_MOVE_MSG, image->getImageId(), event.pos.x, event.pos.y);

    setWidgetMove(event);
}


void VappHsScr::onControlWidgetBarDrop(
    VappHsDndImage *image,
    VfxPenEvent &event)
{
    VFX_LOG(VFX_STATE, VAPP_HS_ON_CONTROL_WIDGET_BAR_DROP_MSG, image->getImageId(), event.pos.x, event.pos.y);

    setWidgetDrop(event, VFX_FALSE);
}


void VappHsScr::onControlWidgetBarAbort(
    VappHsDndImage *image, 
    VfxPenEvent &event)
{
    VFX_LOG(VFX_STATE, VAPP_HS_ON_CONTROL_WIDGET_BAR_ABORT_MSG, image->getImageId(), event.pos.x, event.pos.y);

    setWidgetDrop(event, VFX_TRUE);
}


void VappHsScr::onControlDesktopDrag(
    VappHsWidget *widget, 
    VfxPenEvent &event)
{
    VappHsDndImage *image = NULL;
    
    VFX_LOG(VFX_STATE, VAPP_HS_ON_CONTROL_DESKTOP_DRAG_MSG, widget->getIcon(), event.pos.x, event.pos.y);

    // Get the widget pen offset (from middle point to the pen point).
    getOffset(widget, event, m_penPointOffsetL);

    // remove widget from desktop
    m_desktop->removeWidget(widget);

    // create image frame
    for (VfxS32 i = 0 ; i < TOTAL_WIDGET ; i ++)
    {
        if (m_widget[i] == widget)
        {
            image = m_widgetIcon[i];
        }
    }
    VFX_ASSERT(image);

    setWidgetDrag(image, widget, event, VFX_FALSE);
}


void VappHsScr::onControlDesktopMove(
    VappHsWidget *widget,
    VfxPenEvent &event)
{
    VFX_LOG(VFX_STATE, VAPP_HS_ON_CONTROL_DESKTOP_MOVE_MSG, widget->getIcon(), event.pos.x, event.pos.y);

    setWidgetMove(event);
}


void VappHsScr::onControlDesktopDrop(
    VappHsWidget *widget,
    VfxPenEvent &event)
{
    VFX_LOG(VFX_STATE, VAPP_HS_ON_CONTROL_DESKTOP_DROP_MSG, widget->getIcon(), event.pos.x, event.pos.y);

    setWidgetDrop(event, VFX_FALSE);
}


void VappHsScr::foldShortcutPool(VfxBool isFold)
{
    if (isFold)
    {
        m_blackScreen->setHidden(VFX_TRUE);
        m_shortcutPool->fold();
    }
    else
    {
        m_blackScreen->setHidden(VFX_FALSE);
        m_shortcutPool->unfold();
    }

    // If the shortcut pool is open, cache all shortcut images for DnD.
    for (VfxS32 i = 0; i < TOTAL_SHORTCUT; i++)
    {
        if (isFold)
        {
            m_shortcut[i]->setIsCached(VFX_FALSE); /* close, no cache */
        }
        else
        {
            m_shortcut[i]->setIsCached(VFX_TRUE);  /* open, cache */
        }
    }
}


void VappHsScr::launchShortcut(VappHsDndImage *image)
{
    const VappHsShortcutCfg *tbl = g_vapp_hs_shortcut_tbl;
    VfxS32 iconId = image->getImageId();

    VFX_LOG(VFX_FUNC, VAPP_HS_LAUNCH_SHORTCUT, iconId);

    for (VfxS32 i = 0; i < TOTAL_SHORTCUT; i++)
    {
        if (tbl[i].iconId == iconId && tbl[i].cbf)
        {
            tbl[i].cbf();
            break;
        }
    }
}


void VappHsScr::setShortcutDrop(
    VappHsDndImage *image,
    VfxPenEvent &event,
    VfxBool isRestore)
{
    VfxBool isUnfold = m_shortcutPool->isUnfold();

    if (image->getImageId() == VAPP_HS_IMG_SC_SETTING || !isUnfold)
    {
        // The selected shortcut is the shortcut setting icon. Or the shortcut
        // pool is close.
        m_shortcutBar->highlightImage(image, VFX_FALSE);

        // isRestore should be false here. Still check it for fail-safe.
        if (!isRestore && image->containPoint(event.getRelPos(image)))
        {
            if (image->getImageId() == VAPP_HS_IMG_SC_SETTING)
            {
                // Toggle the shortcut pool folding.
                foldShortcutPool(isUnfold);
            }
            else
            {   
                // TODO: async. launch has some problem if the user quickly 
                // clicks two shortcut icons. Should be fixed later.
                // (MAUI_01606012)
                //
                // vfxPostInvoke(this, &VappHsScr::launchShortcut, image);
                //
                launchShortcut(image);
            }
        }
    }
    else
    {   
        if (m_movingFrameS)
        {
            resetAnchor(m_movingFrameS, m_penPointOffsetS);
            
            m_movingFrameS->setOpacity(1.0f);

            if (isRestore)
            {
                // Scenario: 
                //  Abort the dragging operation. 
                //
                //  This happens when the user intends to scroll the shortcut
                //  bar, rather than drag the shortcut.
                //
                // Icon View: 
                //  Restore to previous position for scrolling.
                
                m_movingFrameS->removeFromParent();
                m_movingFrameOriParent->restoreImage(m_movingFrameS);
                m_movingFrameS = NULL;
            }
            else
            {
                VfxPoint currentPos, finalPos;

                if (m_shortcutBar->containPoint(event.getRelPos(m_shortcutBar)))
                {
                    // THIS PART IS COMPLICATED. BE PATIENT.
                    //
                    // Scenario: 
                    //  Drop on the shortcut bar.
                    //
                    // Problem: 
                    //  If we directly add the icon to the shortcut bar, the 
                    //  icon might be cutted by the bounds of the shortcut bar.
                    //
                    // Solution:
                    //  1) Preview the final position of the icon
                    //  2) Add the icon back to the App category
                    //  3) Animate the icon to its final position
                    //  4) Start a timer to callback when the animation completes
                    //  5) When timer fires, add the widget to the widget bar

                    m_movingFrameS->m_scrollWay = VappHsDndImage::HORI_SCROLL;
                    
                    m_shortcutPool->arrange(-1);
                    previewDrop(m_shortcutBar, event, currentPos, finalPos);
                }
                else if (m_shortcutPool->containPoint(event.getRelPos(m_shortcutPool)))
                {
                    // THIS PART IS COMPLICATED. BE PATIENT.
                    //
                    // Scenario: 
                    //  Drop on the shortcut pool.
                    //
                    // Problem and Solution: 
                    //  Similar as the above one.

                    m_movingFrameS->m_scrollWay = VappHsDndImage::NONE_SCROLL;

                    m_shortcutBar->arrange(-1);
                    previewDrop(m_shortcutPool, event, currentPos, finalPos);
                }
                else
                {
                    // THIS PART IS COMPLICATED. BE PATIENT.
                    //
                    // Scenario: 
                    //  Drop on the other region. Animate the icon to its
                    //  previous position.
                    //
                    // Problem and Solution: 
                    //  Similar as the above one.
                    
                    previewDropExt(currentPos, finalPos);
                }
                
                // Restore the icon to its previous position. Then, auto animate
                // to its final position.
                VfxAutoAnimate::begin();
                VfxAutoAnimate::setDisable(VFX_TRUE);
                m_movingFrameS->setPos(currentPos);
                VfxAutoAnimate::commit();
                
                m_movingFrameS->setPos(finalPos);
                
                m_timerAddShortcut->start();
            }
        }
    }
}


void VappHsScr::onControlShortcutDrag(
    VappHsDndImage *image,
    VfxPenEvent &event)
{
    VFX_LOG(VFX_STATE, VAPP_HS_ON_CONTROL_SHORTCUT_DRAG_MSG, image->getImageId(), event.pos.x, event.pos.y);

    if (image->getImageId() == VAPP_HS_IMG_SC_SETTING || !m_shortcutPool->isUnfold())
    {
        m_shortcutBar->highlightImage(image, VFX_TRUE);
    }
    else
    {
        // backup original image info for restore
        m_movingFrameOriParent = (VappHsInteractiveImageArray *)image->getParentFrame();
        m_movingFrameOriParent->backupImage(image);
        
        // Get the icon pen offset (from middle point to the pen point).
        getOffset(image, event, m_penPointOffsetS);

        // remove from original parent
        m_movingFrameOriParent->removeImage(image, VFX_FALSE);

        m_movingFrameS = image;

        // Initialization (disable auto. animation during initialization)
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);

        setAnchor(m_movingFrameS, m_penPointOffsetS);
        m_movingFrameS->setOpacity(1.0f);
        m_movingFrameS->setPos(event.getRelPos(this));
    
        VfxAutoAnimate::commit();

        // Use auto animation for the opacity of the active item.
        m_movingFrameS->setOpacity(s_moveOpacity);

        // Add icon in the App category.
        addChild(m_movingFrameS);
    }
}


void VappHsScr::onControlShortcutMove(
    VappHsDndImage *image,
    VfxPenEvent &event)
{
    VFX_LOG(VFX_STATE, VAPP_HS_ON_CONTROL_SHORTCUT_MOVE_MSG, image->getImageId(), event.pos.x, event.pos.y);

    if (image->getImageId() == VAPP_HS_IMG_SC_SETTING || !m_shortcutPool->isUnfold())
    {
        if (image->containPoint(event.getRelPos(image)))
        {
            m_shortcutBar->highlightImage(image, VFX_TRUE);
        }
        else
        {
            m_shortcutBar->highlightImage(image, VFX_FALSE);
        }
    }
    else
    {
        if (m_movingFrameS)
        {
            // Force the position to make the moving smooth and real-time.
            m_movingFrameS->forcePos(event.getRelPos(this));

            // On lite-version, the animation on the shortcut pool is not
            // active (i.e., arrange and cross effects are disable).
            if (m_shortcutBar->containPoint(event.getRelPos(m_shortcutBar)))
            {   
                // inside shortcut bar
                m_shortcutBar->cross(event);
            #if !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
                m_shortcutPool->arrange(-1);
            #endif
            }
            else if (m_shortcutPool->containPoint(event.getRelPos(m_shortcutPool)))
            {   
                // inside shortcut pool
                m_shortcutBar->arrange(-1);
            #if !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
                m_shortcutPool->cross(event);
            #endif
            }
            else
            {    
                // invalid region, restore shortcut bar and pool
                m_shortcutBar->arrange(-1);
            #if !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
                m_shortcutPool->arrange(-1);
            #endif
            }
        }
    }
}


void VappHsScr::onControlShortcutDrop(
    VappHsDndImage *image,
    VfxPenEvent &event)
{
    VFX_LOG(VFX_STATE, VAPP_HS_ON_CONTROL_SHORTCUT_DROP_MSG, image->getImageId(), event.pos.x, event.pos.y);

    setShortcutDrop(image, event, VFX_FALSE);
}


void VappHsScr::onControlShortcutAbort(
    VappHsDndImage *image,
    VfxPenEvent &event)
{
    VFX_LOG(VFX_STATE, VAPP_HS_ON_CONTROL_SHORTCUT_ABORT_MSG, image->getImageId(), event.pos.x, event.pos.y);

    setShortcutDrop(image, event, VFX_TRUE);
}


void VappHsScr::onBlackScreenDown()
{
    if (m_shortcutPool->isUnfold())
    {
        foldShortcutPool(VFX_TRUE);
    }
}


void VappHsScr::onDesktopBoundsChanged(VfxFrame *soruce, const VfxRect &oldBounds)
{
    VFX_UNUSED(soruce);
    VFX_UNUSED(oldBounds);

    VfxS32 x = m_desktop->getBounds().origin.x;
    
    if (m_imgBg)
    {
        VfxSize size = m_imgBg->getBounds().size;
        VfxPoint pos = m_imgBg->getPos();
        VfxS32 a, b, m;

        /*
         * Change the wallpaper position:
         *
         *               page width   page width   page width
         *   desktop   |------------|------------|------------|
         *
         *                 wallpaper width
         *   wallpaper |----------------------|
         *
         *                          |<---------- A ---------->|
         *
         *                          |<-- B -->|
         *
         * If the desktop moves X, the wallpaper should move M = X * (B / A).
         */
        a = (VappHsDesktop::TOTAL_PAGE - 1) * VappHsDesktop::PAGE_WIDTH;
        b = size.width - VappHsDesktop::PAGE_WIDTH;

        if (a > 0 && b > 0)
        {
            // calculate the bounds of the wallpaper
            m = x * b / a;

            // Check x value for fail-safe
            m = (m < 0) ? (0) : (m); 
            m = (m > b) ? (b) : (m);

            // Change wallpaper position
            pos.x = -m;

            VfxAutoAnimate::begin();
            VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
        
            m_imgBg->setPos(pos);
        
            VfxAutoAnimate::commit();
        }
    }
    
    // change desktop indicator
    m_desktopIndicator->highlight(x);
}


void VappHsScr::onShortcutBarUpdateIndicators(
    VfxS32 type,
    VfxBool isHidden)
{
    switch (type)
    {
        case VappHsShortcutBar::LEFT_IND:
            m_imageShortcutBarLeftArrow->setOpacity((isHidden) ? (0.0f) : (1.0f));
            break;

        case VappHsShortcutBar::RIGHT_IND:
            m_imageShortcutBarRightArrow->setOpacity((isHidden) ? (0.0f) : (1.0f));
            break;

        default:
            break;
    }
}


void VappHsScr::onWidgetBarUpdateFolding(VfxBool isFold)
{
    if (isFold)
    {
        VFX_LOG(VFX_STATE, VAPP_HS_ON_WIDGET_BAR_UPDATE_FOLDING_MSG, 1);
        
        m_timerCloseWidgetBar->stop();
    }
    else
    {
        VFX_LOG(VFX_STATE, VAPP_HS_ON_WIDGET_BAR_UPDATE_FOLDING_MSG, 0);
        
        // If the widget bar is open because the user is dragging the widget and
        // moving the widget in the bounds of the widget bar, the timer value
        // should be large such that it will not close during the DnD period.
        // Please refer to the onPreviewPenInput. (MAUI_01881649).
        if (m_movingFrameS)
        {
            m_timerCloseWidgetBar->setStartDelay(0xFFFFFFFF);
        }
        
        m_timerCloseWidgetBar->start();
    }
}


void VappHsScr::onCloseWidgetBar(VfxTimer *timer)
{
    VFX_UNUSED(timer);

    VFX_LOG(VFX_STATE, VAPP_HS_ON_CLOSE_WIDGET_BAR_MSG);

    m_widgetBar->fold();
}


void VappHsScr::onNetworkNameChanged(VdatNetworkInfo *networkSrv)
{
    VFX_LOG(VFX_STATE, VAPP_HS_ON_NETWORK_NAME_CHANGED_MSG);

    m_ni->setNetname(networkSrv->getName());
}


void VappHsScr::onNetworkStatusChanged(VdatNetworkInfo *networkSrv)
{
    VFX_LOG(VFX_STATE, VAPP_HS_ON_NETWORK_STATUS_CHANGED_MSG);

    m_ni->setNetstat(networkSrv->getStatus());
}


void VappHsScr::onNetworkNameChanged2(VdatNetworkInfo *networkSrv)
{
    VFX_LOG(VFX_STATE, VAPP_HS_ON_NETWORK_NAME_CHANGED_2_MSG);

    m_ni2->setNetname(networkSrv->getName2());
}


void VappHsScr::onNetworkStatusChanged2(VdatNetworkInfo *networkSrv)
{
    VFX_LOG(VFX_STATE, VAPP_HS_ON_NETWORK_STATUS_CHANGED_2_MSG);

    m_ni2->setNetstat(networkSrv->getStatus2());
}

    
void VappHsScr::onIdleModeTextChanged(VdatNetworkInfo *networkSrv)
{
    VFX_LOG(VFX_STATE, VAPP_HS_ON_SET_IDLE_MODE_TEXT_MSG);

    m_idleModeText->setText(networkSrv->getIdleModeText());
}


void VappHsScr::onIdleModeIconChanged(VdatNetworkInfo *networkSrv)
{
    VFX_LOG(VFX_STATE, VAPP_HS_ON_SET_IDLE_MODE_ICON_MSG);
    
    m_idleModeText->setIcon(networkSrv->getIdleModeIcon());
}


void VappHsScr::createAllDelayedWidget()
{
    const VfxFrame *iter;
    VfxS32 i;
    
    for (iter = m_desktop->getFirstChildFrame(); 
         iter != NULL; 
         iter = iter->getNextFrame())
    {
        // skip non-widget frame
        for (i = 0; i < TOTAL_WIDGET; i++)
        {
            if (iter == m_widget[i])
            {
                break;
            }
        }

        if (i == TOTAL_WIDGET)
        {
            continue; // this is a non-widget frame
        }

        VfxBool isCreated = m_widget[i]->isCreated();

        // TODO: the story of 0.9f
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);
        if (!isCreated)
        {
            m_widget[i]->createView();
        }
        m_widget[i]->setOpacity(0.9f);
        m_widget[i]->setOpacity(1.0f);
        VfxAutoAnimate::commit();

        // Add to the desktop formally.
        if (!isCreated)
        {
            m_desktop->addWidgetFromHistory(m_widget[i]);
        }
    }
}


void VappHsScr::onTimerCreateWidget(VfxTimer *timer)
{
    const VfxFrame *iter;
    VfxS32 i;

    VFX_LOG(VFX_STATE, VAPP_HS_ON_TIMER_CREATE_WIDGET_MSG, 0, -1);

    for (iter = m_desktop->getFirstChildFrame(); 
         iter != NULL; 
         iter = iter->getNextFrame())
    {
        // skip non-widget frame
        for (i = 0; i < TOTAL_WIDGET; i++)
        {
            if (iter == m_widget[i])
            {
                break;
            }
        }

        if (i == TOTAL_WIDGET)
        {
            continue; // this is a non-widget frame
        }

        if (!m_widget[i]->isCreated())
        {
            VFX_LOG(VFX_STATE, VAPP_HS_ON_TIMER_CREATE_WIDGET_MSG, 1, i);
            
            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDisable(VFX_TRUE);
            m_widget[i]->createView();
        #if !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
            m_widget[i]->setOpacity(0.0f);
        #endif
            VfxAutoAnimate::commit();

        #if !defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
            m_widget[i]->setOpacity(1.0f);
        #endif

            // Add to the desktop formally.
            m_desktop->addWidgetFromHistory(m_widget[i]);

            // Start the timer to create the next widget later.
            timer->start();
            
            return;
        }
    }

    VFX_LOG(VFX_STATE, VAPP_HS_ON_TIMER_CREATE_WIDGET_MSG, 2, -1);
}


void VappHsScr::setSettingWidget()
{
    VappHsDndImage *widgetIcon[TOTAL_WIDGET];
    VfxBool isOrphan[TOTAL_WIDGET];
    VfxS32 i, j, count;

    if (!m_setting)
    {
        // If the setting is provided, all widgets are put in the widget bar.
        m_widgetBar->initImage(TOTAL_WIDGET, m_widgetIcon);
    }
    else
    {
        for (i = 0; i < TOTAL_WIDGET; i++)
        {
            isOrphan[i] = VFX_TRUE;
        }

        count = 0;

        for (i = 0; i < TOTAL_WIDGET; i++)
        {
            j = m_setting->widget[i].id;
            
            // Skip invalid widget setting.
            if (j < 0 || j >= TOTAL_WIDGET || !isOrphan[j])
            {
                continue; // skip this one
            }

            isOrphan[j] = VFX_FALSE;
            
            if (i >= m_setting->n_active_widget)
            {
                // Widget is in the bar.
                widgetIcon[count++] = m_widgetIcon[j];
            }
            else
            {
                // Widget is in the desktop.
                // Use the delayed widget creation mechanism. Here, only set its
                // position and add it into the desktop, but the widget view 
                // will be created later to quickly launch the idle screen.
                VfxPoint p;
                p.x = m_setting->widget[i].x;
                p.y = m_setting->widget[i].y;

                m_widget[j]->setPos(p);

                // Prevent the widget from being clicked.
                m_widget[j]->setBounds(VfxRect(0, 0, 0, 0));
                
                m_desktop->addChild(m_widget[j]);
            }
        }

        // For fail-safe. Because the setting might be corrupted, add the orphan
        // widget in the bar.
        for (i = 0; i < TOTAL_WIDGET; i++)
        {
            if (isOrphan[i])
            {
                widgetIcon[count++] = m_widgetIcon[i];
            }
        }

        // If this is not the "small go back" case, start the timer for the 
        // delayed widget creation mechanism. Otherwise, we shall create all the
        // widgets immediately for the background of "small go back".
        if (m_isRedrawingBkScreens)
        {
            createAllDelayedWidget();
        }
        else
        {
            m_timerCreateWidget->setStartDelay(s_createDelayedDuration);
            m_timerCreateWidget->m_signalTick.connect(this, &VappHsScr::onTimerCreateWidget);
            m_timerCreateWidget->start();
        }
        
        // Should always call initImage to init the state of the widget bar even
        // if the number of widgets is 0 such that the state of widget bar can
        // be initialized.
        m_widgetBar->initImage(count, widgetIcon);
    }
}


void VappHsScr::setSettingShortcutDefault()
{
    const VappHsShortcutCfg *tbl = g_vapp_hs_shortcut_tbl;
    VappHsDndImage *inBarImg[TOTAL_SHORTCUT];
    VappHsDndImage *inPoolImg[TOTAL_SHORTCUT];
    VfxS32 inBarCount, inPoolCount;
    
    inBarCount = 0;
    inPoolCount = 0;
    
    for (VfxS32 i = 0 ; i < TOTAL_SHORTCUT; i++)
    {
        if ((tbl[i].option & VAPP_HS_SHORTCUT_OPTION_IN_BAR))
        {
            inBarImg[inBarCount++] = m_shortcut[i];
            
            // DnD can be aborted to become horizontal scrolling.
            m_shortcut[i]->m_scrollWay = VappHsDndImage::HORI_SCROLL;
        }
        else
        {
            inPoolImg[inPoolCount++] = m_shortcut[i];

            // No scrolling. DnD will not be aborted to become scrolling.
            m_shortcut[i]->m_scrollWay = VappHsDndImage::NONE_SCROLL;
        }
    }
    
    m_shortcutBar->initImage(inBarCount, inBarImg);
    m_shortcutPool->initImage(inPoolCount, inPoolImg);
}


void VappHsScr::setSettingShortcut()
{
    VappHsDndImage *inBarImg[TOTAL_SHORTCUT];
    VappHsDndImage *inPoolImg[TOTAL_SHORTCUT];
    VfxS32 inBarCount, inPoolCount;
    VfxS32 i, j;

    // If the setting is absent, use the default shortcut layout.
    if (!m_setting)
    {
        setSettingShortcutDefault();
        return;
    }
    
    inBarCount = 0;
    inPoolCount = 0;

    for (i = 0; i < TOTAL_SHORTCUT; i++)
    {
        // Find the shortcut
        for (j = 0; j < TOTAL_SHORTCUT; j++)
        {
            if (m_setting->shortcut[i].id == m_shortcut[j]->getImageId())
            {
                break;
            }
        }

        // If the layout in the setting is invalid, use default shortcut layout
        //
        // TODO: do not directly reset to default. Try to recover it, like 
        //       the widget.
        if (j == TOTAL_SHORTCUT)
        {
            setSettingShortcutDefault();
            return;
        }

        if (i >= m_setting->n_active_shortcut)
        {
            // Shortcut is in the pool.
            inPoolImg[inPoolCount++] = m_shortcut[j];

            // No scrolling. DnD will not be aborted to become scrolling.
            m_shortcut[j]->m_scrollWay = VappHsDndImage::NONE_SCROLL;
        }
        else
        {
            // Shortcut is in the bar.
            inBarImg[inBarCount++] = m_shortcut[j];

            // DnD can be aborted to become horizontal scrolling.
            m_shortcut[j]->m_scrollWay = VappHsDndImage::HORI_SCROLL;
        }
    }

    if (inBarCount > 0)
    {
        m_shortcutBar->initImage(inBarCount, inBarImg);
    }

    if (inPoolCount > 0)
    {
        m_shortcutPool->initImage(inPoolCount, inPoolImg);
    }
}


VfxBool VappHsScr::getSettingWidget(VappHsScr::Setting *rec)
{    
    const VfxFrame *iter;
    VappHsDndImage **img;
    VfxS32 imgCount, count;

    VFX_LOG(VFX_FUNC, VAPP_HS_GET_SETTING_WIDGET_MSG);

    count = 0;

    // In desktop widget. Find the assoicated widget and store the setting.
    for (iter = m_desktop->getFirstChildFrame(); 
         iter != NULL; 
         iter = iter->getNextFrame())
    {
        for (VfxS32 j = 0; j < TOTAL_WIDGET; j++)
        {
            if (iter == m_widget[j])        // m_widget: full view array
            {
                rec->widget[count].id = j;
                rec->widget[count].x  = m_widget[j]->getPos().x;
                rec->widget[count].y  = m_widget[j]->getPos().y;
                ++count;

                break; // check the next one
            }
        }
    }

    rec->n_active_widget = count;
    
    // In bar widget. Find the assoicated widget and store the setting.
    img      = m_widgetBar->getImageArray();
    imgCount = m_widgetBar->getImageNumber();
    
    for (VfxS32 i = 0; i < imgCount; i++)
    {
        for (VfxS32 j = 0; j < TOTAL_WIDGET; j++)
        {
            if (img[i] == m_widgetIcon[j])  // m_widgetIcon: icon view array
            {
                rec->widget[count].id = j;
                rec->widget[count].x  = 0;  // dummy
                rec->widget[count].y  = 0;  // dummy
                ++count;
                
                break; // check the next one
            }
        }
    }

    // Check whether the widget setting is reliable.
    if (count == TOTAL_WIDGET)
    {
        return VFX_TRUE;  // reliable
    }
    else
    {
        return VFX_FALSE; // unreliable
    }
}


VfxBool VappHsScr::getSettingShortcut(VappHsScr::Setting *rec)
{    
    VappHsDndImage **img;
    VfxS32 i, count = 0;

    VFX_LOG(VFX_FUNC, VAPP_HS_GET_SETTING_SHORTCUT_MSG);

    // number of the active shortcuts
    rec->n_active_shortcut = m_shortcutBar->getImageNumber();

    // in bar shortuct
    img = m_shortcutBar->getImageArray();

    for (i = 0; i < m_shortcutBar->getImageNumber(); i++)
    {
        rec->shortcut[count++].id = img[i]->getImageId();
    }

    // in pool shortcut
    img = m_shortcutPool->getImageArray();

    for (i = 0; i < m_shortcutPool->getImageNumber(); i++)
    {
        rec->shortcut[count++].id = img[i]->getImageId();
    }

    // Check whether the shortcut setting is reliable.
    if (count == TOTAL_SHORTCUT)
    {
        return VFX_TRUE;    // reliable
    }
    else
    {
        return VFX_FALSE;   // unreliable
    }
}


VfxU32 VappHsScr::getSetting(VfxU8 *buf, VfxS32 size)
{
    Setting *setting;
    VfxBool isReliable;

    VFX_LOG(VFX_FUNC, VAPP_HS_GET_SETTING_MSG, size);

    VFX_ASSERT(buf && size >= sizeof(Setting))

    setting = (Setting *)buf;

    isReliable = getSettingWidget(setting);
    VFX_DEV_ASSERT(isReliable);

    isReliable = getSettingShortcut(setting);
    VFX_DEV_ASSERT(isReliable);
    
    return sizeof(Setting);
}


VfxBool VappHsScr::isSettingReliable()
{
    Setting dummy;
    VfxBool isReliable;

    // Evaluate whether the widget setting is reliable.
    isReliable = getSettingWidget(&dummy);
    if (!isReliable)
    {
        return VFX_FALSE;
    }

    // Evaluate whether the shortcut setting is reliable.
    isReliable = getSettingShortcut(&dummy);
    if (!isReliable)
    {
        return VFX_FALSE;
    }

    return VFX_TRUE;
}


void VappHsScr::registerSettingChangedHandler(vapp_hs_setting_cbf_t cbf)
{
    m_settingCbf = cbf;
}


void VappHsScr::setHistoryDesktop()
{
    if (m_history)
    {
        // desktop position
        VfxRect bounds = m_desktop->getBounds();
        bounds.origin.x = m_history->desktop_pos;
        m_desktop->setBounds(bounds);
        m_desktop->alignment();
        
        // indicator position
        m_desktopIndicator->highlight(bounds.origin.x);
    }
}


void VappHsScr::setHistoryShortcut()
{
    if (m_history)
    {
        if (m_history->is_shortcut_pool_opened)
        {
            foldShortcutPool(VFX_FALSE);
        }
        else
        {
            foldShortcutPool(VFX_TRUE);
        }
        
        // shortcut bar position
        VfxRect bounds = m_shortcutBar->getBounds();
        bounds.origin.x = m_history->shortcut_bar_pos;
        m_shortcutBar->setBounds(bounds);
        m_shortcutBar->alignment();
    }
}


void VappHsScr::setHistoryWidget()
{
    if (m_history)
    {
        if (m_history->is_widget_bar_opened)
        {
            m_widgetBar->unfold();
        }
        else
        {
            m_widgetBar->fold();
        }

        // widget bar position
        VfxRect bounds = m_widgetBar->m_controlPanel->getBounds();
        bounds.origin.y = m_history->widget_bar_pos;
        m_widgetBar->m_controlPanel->setBounds(bounds);
        m_widgetBar->alignment();
    }
}


VfxU32 VappHsScr::getHistory(VfxU8 *buf, VfxS32 size)
{
    History *history;

    VFX_LOG(VFX_FUNC, VAPP_HS_GET_HISTORY_MSG, size);

    VFX_ASSERT(buf && size >= sizeof(History))

    history = (History *)buf;

    // widget bar
    if (m_widgetBar->isUnfold())
    {
        history->is_widget_bar_opened = VFX_TRUE;
    }
    else
    {
        history->is_widget_bar_opened = VFX_FALSE;
    }

    // shortcut pool
    if (m_shortcutPool->isUnfold())
    {
        history->is_shortcut_pool_opened = VFX_TRUE;
    }
    else
    {
        history->is_shortcut_pool_opened = VFX_FALSE;
    }

    // position of desktop, widget bar, and shortcut bar
    history->desktop_pos = m_desktop->getBounds().origin.x;
    history->widget_bar_pos = m_widgetBar->m_controlPanel->getBounds().origin.y;
    history->shortcut_bar_pos = m_shortcutBar->getBounds().origin.x;
    
    return sizeof(History);
}


VfxBool VappHsScr::isFoldAll()
{
    if (!m_widgetBar->isUnfold() && !m_shortcutPool->isUnfold())
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}


void VappHsScr::foldAll()
{
    VFX_LOG(VFX_FUNC, VAPP_HS_FOLD_ALL_MSG, 0);

    // If widget bar is unfold, fold the widget bar.
    if (m_widgetBar->isUnfold())
    {
        // If some widget is during the dropping animation, drop it immediately.
        // Or, the widget might be animated to a weird position because the
        // widget bar is closed. (MAUI_01775646)
        if (m_timerAddWidget->getIsEnabled())
        {
            VFX_LOG(VFX_FUNC, VAPP_HS_FOLD_ALL_MSG, 1);
            
            m_timerAddWidget->m_signalTick.emit(m_timerAddWidget);
            m_timerAddWidget->stop();
        }

        m_widgetBar->fold();
    }

    // If shortcut pool is unfold, fold the shortcut pool.
    if (m_shortcutPool->isUnfold())
    {
        // If some shortcut is during the dropping animation, drop it 
        // immediately. Or the shortcut might be animated to a weird position
        // because the shortcut pool is closed. (MAUI_01775646)
        if (m_timerAddShortcut->getIsEnabled())
        {
            VFX_LOG(VFX_FUNC, VAPP_HS_FOLD_ALL_MSG, 2);
            
            m_timerAddShortcut->m_signalTick.emit(m_timerAddShortcut);
            m_timerAddShortcut->stop();
        }

        foldShortcutPool(VFX_TRUE);
    }
}


void VappHsScr::foldAllByBuffer(VfxU8 *buf)
{
    History *history = (History *)buf;

    if (history)
    {
        history->is_widget_bar_opened = VFX_FALSE;
        history->is_shortcut_pool_opened = VFX_FALSE;
    }
}


void VappHsScr::rotateDesktop()
{
    VFX_LOG(VFX_FUNC, VAPP_HS_ROTATE_DESKTOP_MSG, 0);

    // If the "close widget bar" timer is active, restart it because the user 
    // has interacted with the home screen.
    if (m_timerCloseWidgetBar->getIsEnabled())
    {
        m_timerCloseWidgetBar->start(); // will stop and restart
    }

    // Behavior:
    //  - If the shortcut pool is open, close it first.
    //  - Otherwise, rotate the desktop.
    if (m_shortcutPool->isUnfold())
    {
        foldShortcutPool(VFX_TRUE);
    }
    else
    {
        VfxRect bounds;
        VfxS32 idx;
        
        bounds = m_desktop->getBounds();

        idx = (bounds.origin.x + VappHsDesktop::PAGE_WIDTH) / VappHsDesktop::PAGE_WIDTH;
        idx = (idx < 1 ? 1 : idx);
        idx = (idx > VappHsDesktop::TOTAL_PAGE ? VappHsDesktop::TOTAL_PAGE : idx);

        if (idx == VappHsDesktop::TOTAL_PAGE)
        {
            bounds.origin.x = 0;
        }
        else
        {
            bounds.origin.x = idx * VappHsDesktop::PAGE_WIDTH;
        }
        
        m_desktop->setBounds(bounds);
    }
}

#endif /* __MMI_VUI_HOMESCREEN__ */

