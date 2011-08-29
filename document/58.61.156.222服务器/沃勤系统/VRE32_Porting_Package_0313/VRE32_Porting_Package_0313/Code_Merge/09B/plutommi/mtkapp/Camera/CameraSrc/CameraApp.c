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
*  CameraApp.c
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  Camera Applications v0.3
*
* Author:
* -------
*  Bear (MTK00612)
*                      
*============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*------------------------------------------------------------------------------
* $Log$
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
*
* Mar 17 2009 mtk80018
* [MAUI_01409525] [Popup rule]MDI and camera popup rule check in
* 
*
* Mar 13 2009 mtk80018
* [MAUI_01724488] Java_wap connect fail
* 
*
* Mar 2 2009 mtk01166
* [MAUI_01635781] MT6253 check in
* 
*
* Feb 18 2009 mtk80018
* [MAUI_01391449] [Camera]popup 'Camera error' is not reasonable.
* 
*
* Feb 18 2009 mtk80018
* [MAUI_01487421] [Camera]The "95%" will flash sometimes.
* 
*
* Feb 17 2009 mtk80140
* [MAUI_01394662] change mmi_frm_get_screen_rotate design
* 
*
* Feb 3 2009 mtk80018
* [MAUI_01507459] [Camera] RSK cut a little
* 
*
* Jan 20 2009 mtk80018
* [MAUI_01499813] [BC]_should't popup camera error
* 
*
* Jan 16 2009 mtk80018
* [MAUI_01366209] [Camera]Camera check in SoftKey funciton change
* 
*
* Jan 12 2009 mtk80018
* [MAUI_01495225] [BC]_should't popup camera error
* 
*
* Jan 9 2009 mtk80018
* [MAUI_01495334] Camera_icon be cut
* 
*
* Jan 9 2009 mtk80018
* [MAUI_01360805] [Camera] It display a white screen
* 
*
* Jan 9 2009 mtk80018
* [MAUI_01360255] [Camera] There is black screen when press option
* 
*
* Jan 8 2009 mbj06018
* [MAUI_01494475] Camera: the background screen is blue
* 
*
* Jan 7 2009 mbj06018
* [MAUI_01310468] [BC] Assert fail: gdi_layer.c 969 - MMI
* 
*
* Dec 29 2008 mtk01166
* [MAUI_01307582] fix stage 2 error..
* 
*
* Dec 28 2008 mtk01166
* [MAUI_01486512] Camera_The handset is hang
* 
*
* Dec 26 2008 mbj06018
* [MAUI_01357976] [Camera]modify string id of background call part
* 
*
* Dec 26 2008 mbj06018
* [MAUI_01356924] [Camera] The shutter sound and the popup sound ring abnormal
* 
*
* Dec 22 2008 mtk01166
* [MAUI_01301679] [patch] sublcd camera open/close shell problem interacted by interrupt event hdlr ch
* 
*
* Dec 18 2008 mbj06018
* [MAUI_01297152] [Low memory] there should not has Undefined in Image size item
* 
*
* Dec 12 2008 mbj06018
* [MAUI_01476895] [Camera]press icon, no animation effect
* 
*
* Dec 9 2008 mbj06018
* [MAUI_01244608] [Camera]set burst shot then press side key, screen flicker
* 
*
* Dec 9 2008 mbj06018
* [MAUI_01349035] [Fancy UI] popup no sliding down
* 
*
* Dec 9 2008 mbj06018
* [MAUI_01477916] [Camera] the Send option cannot work
* 
*
* Dec 9 2008 mbj06018
* [MAUI_01349238] [ Camera] the  pupop should be same
* 
*
* Dec 7 2008 mtk01166
* [MAUI_01429688] [Test case fail] Image Size 014,Image Size 013
* 
*
* Dec 4 2008 mbj06018
* [MAUI_01347027] [Camera] they should be accordant
* 
*
* Dec 3 2008 mtk01166
* [MAUI_01476017] [DLT]Soft key Text Down color can not display in Camera.
* 
*
* Dec 2 2008 mbj06018
* [MAUI_01345822] [Camera ] the words show abnormal
* 
*
* Nov 27 2008 mtk01166
* [MAUI_01280858] LIBRA35 08B.W08.46 Camera Capture Performance degrade 0.7~1.2 s
* 
*
* Nov 27 2008 mbj06018
* [MAUI_01335036] [camera]should can not switch to video recorder screen in step2.
* 
*
* Nov 27 2008 mbj06018
* [MAUI_01342884] [Camera] should restore Cont.shot as Off
* 
*
* Nov 24 2008 mtk01166
* [MAUI_01340020] [1] Assert fail: gdi_layer.c 970 - MMI
* 
*
* Nov 21 2008 mtk01166
* [MAUI_01223603] [video recorder] the flow of send via Email is wrong
* 
*
* Nov 19 2008 mtk01166
* [MAUI_01425612] [camara] screen display abnormal
* 
*
* Nov 16 2008 mtk01166
* [MAUI_01333432] [Camera ] the third item show error in the options list .
* 
*
* Nov 7 2008 mtk01166
* [MAUI_01332646] [camera]3 key and * key function duplicated
* 
*
* Nov 7 2008 mtk01166
* [MAUI_01221767] Camera_the option should change
* 
*
* Nov 3 2008 mtk01166
* [MAUI_01219837] Camera_Some time it display camera error
* 
*
* Nov 1 2008 mtk01166
* [MAUI_01219701] [camera] the picture still display in camera screen when the file do not exist.
* 
*
* Oct 31 2008 mtk01166
* [MAUI_01330562] [camera] the popup is not proper
* 
*
* Oct 27 2008 mtk01166
* [MAUI_01327602] [Camera]Pressing button OK should enter Sending Options
* 
*
* Oct 22 2008 mtk01166
* [MAUI_01214912] [1] Assert fail: kal_adm.c 1354 - MMI
* 
*
* Oct 22 2008 mtk01166
* [MAUI_01325349] [BT]Always remind "Initializing bluetooth now,wait..."
* 
*
* Oct 21 2008 mtk01166
* [MAUI_01214970] [Camera] restore is error
* 
*
* Oct 21 2008 mtk01166
* [MAUI_01214725] [1] Fatal Error (1, 28d40d8) - MMI
* 
*
* Oct 21 2008 mtk01166
* [MAUI_01324580] [Camera]The screen display mess
* 
*
* Oct 20 2008 mtk01166
* [MAUI_01258101] [LD-English] The string should be add "?"
* 
*
* Oct 17 2008 mtk01166
* [MAUI_01122224] [Java]When launch a Java,Popup"Insufficient memory"
* 
*
* Oct 14 2008 mtk01429
* [MAUI_01255154] fix camera app compile error on MT6223
* 
*
* Oct 14 2008 mtk01429
* [MAUI_01255154] fix camera app compile error on MT6223
* 
*
* Oct 14 2008 mtk01429
* [MAUI_01254723] [fix daily build compile error] Cameraapp
* 
*
* Oct 8 2008 mtk01166
* [MAUI_01250083] [Vodafone] check in.
* 
*
* Oct 6 2008 mtk01166
* [MAUI_01250083] [Vodafone] check in.
* 
*
* Oct 3 2008 MTK01166
* [MAUI_01248817] [1] Assert fail: wkal_adm.c 735- MMI
* 
*
* Sep 16 2008 mtk01166
* [MAUI_01237286] [MoDIS]can't change auto/night icon immediately when click scene mode icon
* 
*
* Sep 5 2008 mtk01166
* [MAUI_00818303] D-cache check in 623x
* 
*
* Sep 2 2008 mtk01166
* [MAUI_00793312] remove warning.
* 
*
* Sep 1 2008 mtk01166
* [MAUI_00793312] remove warning.
* 
*
* Aug 29 2008 mtk01166
* [MAUI_00806227] [MT6223C][MMI] disable Camera + BT SCO.
* 
*
* Aug 22 2008 mtk01166
* [MAUI_01197294] [Camera] display abnormal screen while reenter camera
* 
*
* Aug 22 2008 mtk01166
* [MAUI_01103710] [Camera] frame disappear and appear unreasonable after shot
* 
*
* Aug 22 2008 mtk01166
* [MAUI_01196956] [LD_SC] string issue
* 
*
* Aug 21 2008 mtk01166
* [MAUI_01103078] [OTG_image viewer]it will popup "fiel(folder) exists"
* 
*
* Aug 19 2008 mtk01166
* [MAUI_01224988] [mmi][camera] improve camera performance.
* 
*
* Aug 1 2008 mtk01166
* [MAUI_01097415] [camera]press back on storage screen, should not auto change storage to phone.
* 
*
* Jul 23 2008 mtk01166
* [MAUI_01090252] [Camera ] the size can't change after press the size icon .
* 
*
* Jul 23 2008 mtk01166
* [MAUI_01177720] [icamera] different operations
* 
*
* Jul 23 2008 mtk01166
* [MAUI_00809388] [W0829] remove warning.
* 
*
* Jul 13 2008 mtk01166
* [MAUI_00803983] [MMI][Camera] Add sla and trace camera operation time consumption log.
* 
*
* Jul 11 2008 mtk01166
* [MAUI_00797988] Camera HVGA Support
* 
*
* Jul 9 2008 mtk01166
* [MAUI_00791677] Camera -Camera preview 640x480 tearing effect during moving
* 
*
* Jul 4 2008 mtk01166
* [MAUI_01177655] [camera] the screen should be cut
* 
*
* Jul 4 2008 mtk01166
* [MAUI_01176850] [1] Assert fail: cameraapp.c 3713 - MMI
* 
*
* Jun 24 2008 mtk01166
* [MAUI_00793312] remove warning.
* 
*
* Jun 21 2008 mtk01166
* [MAUI_01168828] [Camera] the back screen is wrong
* 
*
* Jun 18 2008 mbj06076
* [MAUI_01072096] SDK layer : menu short cut global variables remove and structure revise
* 
*
* Jun 15 2008 mtk01166
* [MAUI_00787429] [ImageViewer] split file.
* 
*
* Jun 12 2008 mtk01166
* [MAUI_00786166] [BT] revise api sap
* 
*
* Jun 10 2008 mtk01166
* [MAUI_00455214] [Camera] couldn't standby or shut down automatically
* 
*
* Jun 5 2008 mtk01166
* [MAUI_00976334] MMS_take photo send to mms,insert pic from camera error
* 
*
* Jun 4 2008 mtk01166
* [MAUI_00778186] When file name too long ,it overlap RSK text
* 
*
* May 28 2008 mtk01166
* [MAUI_01149699] [Camera] [1] Assert fail: aud_mma.c 2336 - MED
* 
*
* May 27 2008 mtk01166
* [MAUI_01049168] [Multimedia] the "Email" options should be hiden
* 
*
* May 22 2008 mtk01166
* [MAUI_00775776] [mmi][cam] fix BT link erorr problem [interaction]
* 
*
* May 19 2008 mtk01166
* [MAUI_00774193] IDP Rotator Support
* 
*
* May 18 2008 mtk01166
* [MAUI_00759628] [OP SUPPORT]
* 
*
* May 16 2008 mtk01166
* [MAUI_01040283] [Camera ] press arrow key ,the response abnormal .
* 
*
* May 15 2008 mtk01166
* [MAUI_01037982] [Multimedia] user can not insert the video to the mms
* 
*
* May 14 2008 mbj06032
* [MAUI_01037962] [BT-PUSH] BT PUSH API revisement
* 
*
* May 14 2008 mbj06032
* [MAUI_01037962] [BT-PUSH] BT PUSH API revisement
* for BT PUSH API revisement
*
* May 13 2008 mtk01166
* [MAUI_00975199] Camera_flight mode,go to camera,press ok,the ms hang
* 
*
* May 7 2008 mtk01166
* [MAUI_00972773] [Camera] there is not forward to BT option
* 
*
* May 2 2008 mtk01166
* [MAUI_00765155] [MT6235] Tearing effect improvement.
* 
*
* Apr 28 2008 mtk01166
* [MAUI_00677784] [Camera ] press MSK should have not response in flight mode .
* 
*
* Apr 28 2008 mtk01166
* [MAUI_00312117] Camera: LSK and RSK button abnormal
* 
*
* Apr 26 2008 mtk01166
* [MAUI_00669617] [Camera ] should not show the message icon when enter Camera from IMPS .
* 
*
* Apr 26 2008 mtk01166
* [MAUI_00763042] [Camera]US_1316.Camcorder show zoom in number show problem
* 
*
* Apr 22 2008 mtk01166
* [MAUI_00665425] [Camcorder]the deleted icon use error
* 
*
* Apr 21 2008 mtk01166
* [MAUI_00759628] [OP SUPPORT]
* 
*
* Apr 21 2008 mtk01166
* [MAUI_00759628] [OP SUPPORT]
* 
*
* Apr 8 2008 mtk01166
* [MAUI_00749775] [MT6223C] [MMI] preview size config by image_sensor.h
* 
*
* Apr 2 2008 mtk01166
* [MAUI_00289392] Camera: Burst shot preview screen error
* 
*
* Apr 1 2008 mtk01166
* [MAUI_00289867] MODIS Assert Fail:mdi_camera.c 1302 - JVM
* 
*
* Mar 27 2008 mtk01166
* [MAUI_00740162] [fix camera build error]
* 
*
* Mar 26 2008 mtk01166
* [MAUI_00735400] [LD_SC]_"Storage" translate incorrect in SC mode.
* 
*
* Mar 25 2008 mtk01166
* [MAUI_00728632] [Camera]US_1119.Set the reszie pic in camera menu list.zip
* 
*
* Mar 23 2008 mtk01166
* [MAUI_00729427] [MT6235B][MT6239] check in.
* 
*
* Mar 13 2008 mtk01166
* [MAUI_00731836] Add compile option , W08.11
* 
*
* Mar 11 2008 mtk01166
* [MAUI_00730259] Check in W08.11
* 
*
* Mar 8 2008 mtk01166
* [MAUI_00729427] [MT6235B][MT6239] check in.
* 
*
* Mar 7 2008 mtk01166
* [MAUI_00729345] [Reduce Memory] move hili & hint to RES_xxx
* 
*
* Mar 3 2008 mtk01166
* [MAUI_00726524] [LD-English] It should popup "Deleted" when capture finished then select "Delete"
* 
*
* Feb 29 2008 mtk01166
* [MAUI_00278242] [IMPS] while view the picture, display File not foud
* 
*
* Feb 25 2008 mtk01166
* [MAUI_00621045] [MT6223C] Direct Sensor Support ,  MMI/MDI/MED Modification.
* 
*
* Feb 21 2008 mtk01166
* [MAUI_00276007] Assert Fail: 0 jpeg_encoder.c 1200-MED
* 
*
* Feb 1 2008 mtk01166
* [MAUI_00615603] [LD-SC]1063.Album in Camera menu list
* 
*
* Jan 31 2008 mtk01166
* [MAUI_00520127] [Multimedia] the frame still shows  when  burst shot
* 
*
* Jan 27 2008 mtk01166
* [MAUI_00078557] Strings are overlapping
* 
*
* Jan 24 2008 mtk01166
* [MAUI_00611630] [mdi][cam] Revise
* 
*
* Jan 5 2008 mtk01166
* [MAUI_00600286] [1] Assert fail: ret == MED_RES_OK mdi_mtv.c 1280 0x0 0x0 0x0 - MMI
* 
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "MMI_include.h"

#if defined(__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__)

#include "lcd_if.h"                     /* LCD layer enable flag */
#include "lcd_sw_rnd.h"                 /* for LCD size */
#define __MMI_CAMERA_ONLY__
/* gdi, mid, camera app headers */
#include "gdi_image_jpeg.h"             /* jpeg decoder */
#include "mdi_datatype.h"
#include "mdi_camera.h"
#include "mdi_audio.h"

#include "MMI_features_camera.h"        /* features */


#include "nvram_data_items.h"           /* ID to store file path */
#include "custom_nvram_extra.h"

/* framework related headers */
#include "SettingDefs.h"                /* ST_NOTIFYDURATION define */
#include "SettingProfile.h"             /* SUCCESS_TONE define */
#include "CommonScreens.h"              /* DisplayPopup() */
#include "gpioInc.h"                    /* LED */
#include "SettingProfile.h"
#include "wgui_status_icons.h"
#include "wgui_softkeys.h"
#include "FileManagerDef.h"
#include "FileManagerGProt.h"           /* file path */
#include "FileMgr.h"
#include "mmiapi_enum.h"                /* Stop LED */
#include "MainMenuDef.h"                /* Multimedia icon */
#include "ProfileGprots.h"              /* playRequestedTone */
#include "SimDetectionGprot.h"
#include "gpioinc.h"
#include "UCMGProt.h"
#include "PhotoEditorGProt.h"

#if defined(__MMI_CAMERA_DIRECT_SENSOR_SUPPORT__)
#include "image_sensor.h"

#define CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH      (IMAGE_SENSOR_PREVIEW_WIDTH)
#define CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT     (IMAGE_SENSOR_PREVIEW_HEIGHT)

#define CAMERA_FEATURE_PREVIEW_SIZE_SS_WIDTH    (IMAGE_SENSOR_PREVIEW_WIDTH)
#define CAMERA_FEATURE_PREVIEW_SIZE_SS_HEIGHT   (IMAGE_SENSOR_PREVIEW_HEIGHT)

#define CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH       (IMAGE_SENSOR_FULLSIZE_WIDTH)
#define CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT      (IMAGE_SENSOR_FULLSIZE_HEIGHT)

#define CAMERA_FEATURE_PREVIEW_SIZE_S_WIDTH     (IMAGE_SENSOR_PREVIEW_WIDTH)
#define CAMERA_FEATURE_PREVIEW_SIZE_S_HEIGHT    (IMAGE_SENSOR_PREVIEW_HEIGHT)
#endif

#if ((LCD_WIDTH == 240) && (LCD_HEIGHT == 320))
    #if (IMAGE_SENSOR_PREVIEW_HEIGHT == 288)
        #undef __MMI_CAMERA_TOP_ALIGN__
        #define __MMI_CAMERA_TOP_ALIGN__
    #endif
#endif

#ifdef __SW_JPEG_CODEC_SUPPORT__
#include "jpeg.h"
#endif

#ifdef EXIF_SUPPORT
#include "exif.h"
#endif 
#ifdef __MMI_AUDIO_REVERB_EFFECT__
#include "SoundEffect.h"
#endif

#ifdef __MMI_TVOUT__
#include "mdi_tv.h"
#endif 

#include "ConnectManageGprot.h"

#ifdef __CAMERA_FEATURE_TOUCH_SCREEN__
#endif 
#include "mdi_include.h"

#include "resource_camera_skins.h"      /* UI custom config */
#include "CameraGprot.h"
#include "CameraApp.h"                  /* camera app data */
#include "CameraMenu.h"                 /* function declare */
#include "CameraResDef.h"              /* resource ID def */
#include "ImageViewerGprot.h"
#include "sw_rotator_common_api.h"


#ifdef __MMI_SUBLCD_CAMERA__
#include "IdleAppProt.h"
#endif

#include "BTMMIScrGprots.h"

#if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
#include "ProfileGprots.h"
#endif

/* Bluetooth sending API revise */
#ifdef __MMI_BT_SUPPORT__
#include "BTMMIObexGprots.h"
#endif

#ifdef __MMI_BIP_SUPPORT__
#include "BTMMIBipGprot.h"
#endif

#if defined(__CAMERA_OSD_HORIZONTAL__)
#include "ScreenRotationGprot.h"
#endif 


/* TURN OFF EMAIL UNTIL IT GETS READY */
#ifdef __MMI_EMAIL__
#include "EmailAppGProt.h"
#endif

#ifdef __MMI_IRDA_SUPPORT__
#include "ConnectivityResDef.h"
#include "IrdaMMIGprots.h"
#endif

#if defined(__MMI_CAMERA_RECORDER_ONE_KEY_TOGGLE__) || defined(__DIRECT_SENSOR_SUPPORT__)
#include "VdoRecGprot.h"
#endif

#if defined(__MMI_CAMERA_MMS_SUPPORT__) || defined(__MMI_MMS__)
#include "wapadp.h"
#include "mmsadp.h"
#endif 

#include "USBDeviceGprot.h"

#if (MDI_CAMERA_MT6227_SERIES || MDI_CAMERA_MT6225_SERIES ||MDI_CAMERA_MT6223_SERIES)
#define MMI_CAMERA_CHECK_CONCURRENCY
#endif 

#if defined(__MTK_INTERNAL__)
/* under construction !*/
#endif

#define __MMI_CAMERA_SILENT_MODE_SUPPORT__
#if defined(__MMI_CAMERA_SILENT_MODE_SUPPORT__)
#define MMI_CAMERA_IS_SILENT_MODE() (TRUE==IsSilentModeActivated())
#else
#define MMI_CAMERA_IS_SILENT_MODE() (1==0)
#endif

#if defined(__MM_DEBUG_MEASURE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
#define MMI_CAMERA_START_MEASURE(_symbol_)
#define MMI_CAMERA_STOP_MEASURE(_symbol_)
#endif 

#if defined(__MMI_CAMERA_DEBUG_ON__) && defined(__MTK_TARGET__) && !defined(WIN32)
U32 g_mmi_cam_start_time;
U32 g_mmi_cam_end_time;
U32 g_mmi_cam_duration;
#define MMI_CAMERA_GET_START_TIME(_trace_) \
    do{\
    kal_get_time(&g_mmi_cam_start_time);\
    }while(0)
#define MMI_CAMERA_GET_STOP_TIME_AND_PRINT_TRACE(_trace_)\
    do{\
    kal_get_time(&g_mmi_cam_end_time);\
    g_mmi_cam_duration = kal_ticks_to_milli_secs(g_mmi_cam_end_time - g_mmi_cam_start_time);\
    kal_trace(MMI_MEDIA_TRC_G2_APP,_trace_, g_mmi_cam_duration,__LINE__);\
    }while(0)
#else
#define MMI_CAMERA_GET_START_TIME(_trace_)
#define MMI_CAMERA_GET_STOP_TIME_AND_PRINT_TRACE(_trace_) 
#endif


#if defined(__CAMERA_OSD_HORIZONTAL__)
#define MMI_CAMERA_DISPLAY_POPUP(v,w)  mmi_display_popup_rotated((UI_string_type)v,w,g_camera_cntx.osd_rotate);
#else /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
#define MMI_CAMERA_DISPLAY_POPUP(v,w)  mmi_display_popup((UI_string_type)v,w);
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 

#define UPDATE_IMAGE_SIZE(_SIZE_) \
    do{\
    if (g_camera_cntx.setting.image_size == CAMERA_SETTING_IMAGE_SIZE_##_SIZE_##)\
{\
    g_camera_cntx.preview_width = CAMERA_FEATURE_PREVIEW_SIZE_##_SIZE_##_WIDTH;\
    g_camera_cntx.preview_height = CAMERA_FEATURE_PREVIEW_SIZE_##_SIZE_##_HEIGHT;\
    g_camera_cntx.image_width = CAMERA_FEATURE_IMAGE_SIZE_##_SIZE_##_WIDTH;\
    g_camera_cntx.image_height = CAMERA_FEATURE_IMAGE_SIZE_##_SIZE_##_HEIGHT;\
}\
    }while(0)

/***************************************************************************** 
* Define
*****************************************************************************/
#define DUMMY_COMMAND                  (0)
#define HINT_POPUP_FADE_TIME           (1200)
#define TOGGLE_POPUP_FADE_TIME         (800)
#define DONE_POPUP_FADE_TIME           (1000)
#define CAMERA_ERR_CORRUPT_FAT         (-2001)
#define CAMERA_ERR_PHONE_DISK_FULL     (-2002)
#define CAMERA_ERR_CARD_DISK_FULL      (-2003)
#define CAMERA_ERR_WRITE_PROTECT       (-2004)
#define CAMERA_ERR_ROOT_DIR_FULL       (-2005)
#define CAMERA_ERR_SAVE_FAIL           (-2006)
#define CAMERA_ERR_BT_IS_WORKING       (-2007)
#define CAMERA_ERR_BEARER_IS_ACTIVE    (-2008)


#define POPLIST_LIST_SPACING           (1)

#define CAMERA_AF_LARGE_WIDTH             (32)
#define CAMERA_AF_NORMAL_WIDTH            (32)
#define CAMERA_AF_SMALL_WIDTH             (32)

#if defined(VC0558)
#define CAMEAR_BG_TRASN_COLOR       (0x0821)
#else 
#define CAMEAR_BG_TRASN_COLOR       (GDI_COLOR_TRANSPARENT)
#endif 

#define TRANSLATE_COORDINATE_TO_270(X,Y,TMP)\
    TMP=X;                          \
    X=Y;                            \
Y=(LCD_WIDTH-1)-TMP;

#define BEFORE_PLAY_AUDIO()\
g_camera_cntx.is_audio_finished=FALSE;
/***************************************************************************** 
* Typedef 
*****************************************************************************/
/* camera application state */
typedef enum
{
    CAMERA_STATE_EXIT = 0,                  /* 0 */
        
        /* main lcd */
        CAMERA_STATE_PREVIEW,                   /* 1 */
        CAMERA_STATE_COUNTDOWN,                 /* 2 */
        CAMERA_STATE_CONTSHOT,                  /* 3 */
        CAMERA_STATE_BURSTSHOT,                 /* 4 */
        CAMERA_STATE_BURSTSHOT_SAVE_CONFIRM,    /* 5 */
        CAMERA_STATE_BURSTSHOT_SAVING,          /* 6 */
        CAMERA_STATE_DELETE_DONE,                 /* 7 */
        CAMERA_STATE_DELETE_CONFIRM,              /* 8 */
        
        /* toggle popup */
        CAMERA_STATE_TOGGLE_TO_SUB,             /* 10 */
        CAMERA_STATE_TOGGLE_TO_MAIN,            /* 11 */
        
        /* sub lcd */
        CAMERA_STATE_SUB_PREVIEW,               /* 12 */
        CAMERA_STATE_SUB_COUNTDOWN,             /* 13 */
        CAMERA_STATE_SUB_CONTSHOT,              /* 14 */
        CAMERA_STATE_SUB_BURSTSHOT,             /* 15 */
        CAMERA_STATE_SUB_BURSTSHOT_SAVING,      /* 16 */
        
        /* forward */
        CAMERA_STATE_FORWARD_TO                 /* 17 */
        
} camera_state_enum;

#ifdef __MMI_SUBLCD_CAMERA__
typedef enum
{
    SUB_CAMERA_STATE_EXIT = 0,                  /* 0 */
        
        /* main lcd */
        SUB_CAMERA_STATE_PREVIEW,                   /* 1 */
        SUB_CAMERA_STATE_COUNTDOWN,                 /* 2 */
        SUB_CAMERA_STATE_CONTSHOT,                  /* 3 */
        SUB_CAMERA_STATE_BURSTSHOT,                 /* 4 */
        SUB_CAMERA_STATE_BURSTSHOT_SAVE_CONFIRM,    /* 5 */
        SUB_CAMERA_STATE_BURSTSHOT_SAVING,          /* 6 */
        SUB_CAMERA_STATE_SAVE_DONE,                 /* 7 */
        SUB_CAMERA_STATE_SAVE_CONFIRM,              /* 8 */
        
} sublcd_camera_state_enum;
#endif


/****************************************************************************
* Setting command map                                                                
*****************************************************************************/
/* mapping mmi settings to mdi command. */
/*********** EV ***********/
const U8 camera_ev_command_map[CAMERA_SETTING_EV_COUNT + 1] = 
{
#ifdef __CAMERA_FEATURE_EV_4__
    MDI_CAMERA_EV_N4,   /* CAMERA_SETTING_EV_N4 */
#endif 
        
#ifdef __CAMERA_FEATURE_EV_3__
        MDI_CAMERA_EV_N3,   /* CAMERA_SETTING_EV_N3 */
#endif 
        
#ifdef __CAMERA_FEATURE_EV_2__
        MDI_CAMERA_EV_N2,   /* CAMERA_SETTING_EV_N2 */
#endif 
        
        MDI_CAMERA_EV_N1,   /* CAMERA_SETTING_EV_N1 */
        MDI_CAMERA_EV_0,    /* CAMERA_SETTING_EV_0 */
        MDI_CAMERA_EV_P1,   /* CAMERA_SETTING_EV_P1 */
        
#ifdef __CAMERA_FEATURE_EV_2__
        MDI_CAMERA_EV_P2,   /* CAMERA_SETTING_EV_P2 */
#endif 
        
#ifdef __CAMERA_FEATURE_EV_3__
        MDI_CAMERA_EV_P3,   /* CAMERA_SETTING_EV_P3 */
#endif 
        
#ifdef __CAMERA_FEATURE_EV_4__
        MDI_CAMERA_EV_P4,   /* CAMERA_SETTING_EV_P4 */
#endif 
        
        DUMMY_COMMAND
};

/*********** EFFECT ***********/
const U8 camera_effect_command_map[CAMERA_SETTING_EFFECT_COUNT + 1] = 
{
#ifdef __CAMERA_FEATURE_EFFECT_NORMAL__
    MDI_CAMERA_EFFECT_NOMRAL,   /* CAMERA_SETTING_EFFECT_NOMRAL */
#endif 
        
#ifdef __CAMERA_FEATURE_EFFECT_GRAYSCALE__
        MDI_CAMERA_EFFECT_GRAYSCALE,    /* CAMERA_SETTING_EFFECT_GRAYSCALE */
#endif 
        
#ifdef __CAMERA_FEATURE_EFFECT_SEPIA__
        MDI_CAMERA_EFFECT_SEPIA,    /* CAMERA_SETTING_EFFECT_SEPIA */
#endif 
        
#ifdef __CAMERA_FEATURE_EFFECT_SEPIA_GREEN__
        MDI_CAMERA_EFFECT_SEPIA_GREEN,  /* CAMERA_SETTING_EFFECT_SEPIA_GREEN */
#endif 
        
#ifdef __CAMERA_FEATURE_EFFECT_SEPIA_BLUE__
        MDI_CAMERA_EFFECT_SEPIA_BLUE,   /* CAMERA_SETTING_EFFECT_SEPIA_BLUE */
#endif 
        
#ifdef __CAMERA_FEATURE_EFFECT_COLOR_INVERT__
        MDI_CAMERA_EFFECT_COLOR_INVERT, /* CAMERA_SETTING_EFFECT_COLOR_INVERT */
#endif 
        
#ifdef __CAMERA_FEATURE_EFFECT_GRAY_INVERT__
        MDI_CAMERA_EFFECT_GRAY_INVERT,  /* CAMERA_SETTING_EFFECT_GRAY_INVERT */
#endif 
        
#ifdef __CAMERA_FEATURE_EFFECT_BLACKBOARD__
        MDI_CAMERA_EFFECT_BLACKBOARD,   /* CAMERA_SETTING_EFFECT_BLACKBOARD */
#endif 
        
#ifdef __CAMERA_FEATURE_EFFECT_WHITEBOARD__
        MDI_CAMERA_EFFECT_WHITEBOARD,   /* CAMERA_SETTING_EFFECT_WHITEBOARD */
#endif 
        
#ifdef __CAMERA_FEATURE_EFFECT_COPPER_CARVING__
        MDI_CAMERA_EFFECT_COPPER_CARVING,   /* CAMERA_SETTING_EFFECT_COPPER_CARVING */
#endif 
        
#ifdef __CAMERA_FEATURE_EFFECT_BLUE_CARVING__
        MDI_CAMERA_EFFECT_BLUE_CARVING, /* CAMERA_SETTING_EFFECT_BLUE_CARVING */
#endif 
        
#ifdef __CAMERA_FEATURE_EFFECT_EMBOSSMENT__
        MDI_CAMERA_EFFECT_EMBOSSMENT,   /* CAMERA_SETTING_EFFECT_EMBOSSMENT */
#endif 
        
#ifdef __CAMERA_FEATURE_EFFECT_CONTRAST__
        MDI_CAMERA_EFFECT_CONTRAST, /* CAMERA_SETTING_EFFECT_CONTRAST */
#endif 
        
#ifdef __CAMERA_FEATURE_EFFECT_JEAN__
        MDI_CAMERA_EFFECT_JEAN, /* CAMERA_SETTING_EFFECT_JEAN */
#endif 
        
#ifdef __CAMERA_FEATURE_EFFECT_SKETCH__
        MDI_CAMERA_EFFECT_SKETCH,   /* CAMERA_SETTING_EFFECT_SKETCH */
#endif 
        
#ifdef __CAMERA_FEATURE_EFFECT_OIL__
        MDI_CAMERA_EFFECT_OIL,  /* CAMERA_SETTING_EFFECT_OIL */
#endif 
        
        DUMMY_COMMAND
};

/*********** WB ***********/
const U8 camera_wb_command_map[CAMERA_SETTING_WB_COUNT + 1] = 
{
#ifdef __CAMERA_FEATURE_WB_AUTO__
    MDI_CAMERA_WB_AUTO, /* CAMREA_SETTING_WB_AUTO */
#endif 
        
#ifdef __CAMERA_FEATURE_WB_DAYLIGHT__
        MDI_CAMERA_WB_DAYLIGHT, /* CAMERA_SETTING_WB_DAYLIGHT */
#endif 
        
#ifdef __CAMERA_FEATURE_WB_TUNGSTEN__
        MDI_CAMERA_WB_TUNGSTEN, /* CAMERA_SETTING_WB_TUNGSTEN */
#endif 
        
#ifdef __CAMERA_FEATURE_WB_FLUORESCENT__
        MDI_CAMERA_WB_FLUORESCENT,  /* CAMERA_SETTING_WB_FLUORESCENT */
#endif 
        
#ifdef __CAMERA_FEATURE_WB_CLOUD__
        MDI_CAMERA_WB_CLOUD,    /* CAMERA_SETTING_WB_CLOUD */
#endif 
        
#ifdef __CAMERA_FEATURE_WB_INCANDESCENCE__
        MDI_CAMERA_WB_INCANDESCENCE,    /* CAMERA_SETTING_WB_INCANDESCENCE */
#endif 
        
#ifdef __CAMERA_FEATURE_WB_MANUAL__
        MDI_CAMERA_WB_MANUAL,   /* MDI_CAMERA_WB_MANUAL */
#endif 
        
        DUMMY_COMMAND
};

/*********** Image Qty ***********/
const U8 camera_image_qty_command_map[CAMERA_SETTING_IMAGE_QTY_COUNT + 1] = 
{
#ifdef __CAMERA_FEATURE_IMAGE_QTY_LOW__
    MDI_CAMERA_JPG_QTY_LOW, /* CAMERA_SETTING_IMAGE_QTY_LOW */
#endif 
        
#ifdef __CAMERA_FEATURE_IMAGE_QTY_NORMAL__
        MDI_CAMERA_JPG_QTY_NORMAL,  /* CAMERA_SETTING_IMAGE_QTY_NORMAL */
#endif 
        
#ifdef __CAMERA_FEATURE_IMAGE_QTY_HIGH__
        MDI_CAMERA_JPG_QTY_HIGH,    /* CAMERA_SETTING_IMAGE_QTY_HIGH */
#endif 
        
#ifdef __CAMERA_FEATURE_IMAGE_QTY_FINE__
        MDI_CAMERA_JPG_QTY_FINE,    /* CAMREA_SETTING_IMAGE_QTY_FINE */
#endif 
        
        DUMMY_COMMAND
};

/*********** Banding ***********/
const U8 camera_banding_command_map[CAMERA_SETTING_BANDING_COUNT + 1] = 
{
    MDI_CAMERA_BANDING_50HZ,
        MDI_CAMERA_BANDING_60HZ,
        DUMMY_COMMAND
};

/*********** AE meter ***********/
const U8 camera_ae_meter_command_map[CAMERA_SETTING_AE_METER_COUNT + 1] = 
{
#ifdef __CAMERA_FEATURE_AE_METER_AUTO__
    MDI_CAMERA_AE_METER_AUTO,   /* CAMERA_SETTING_AE_METER_AUTO */
#endif 
        
#ifdef __CAMERA_FEATURE_AE_METER_SPOT__
        MDI_CAMERA_AE_METER_SPOT,   /* CAMERA_SETTING_AE_METER_SPOT */
#endif 
        
#ifdef __CAMERA_FEATURE_AE_METER_CENTER__
        MDI_CAMERA_AE_METER_CENTER, /* CAMERA_SETTING_AE_METER_CENTER */
#endif 
        
#ifdef __CAMERA_FEATURE_AE_METER_AVERAGE__
        MDI_CAMERA_AE_METER_AVERAGE,    /* CAMERA_SETTING_AE_METER_AVERAGE */
#endif 
        
        DUMMY_COMMAND
};

/*********** Flash ***********/
const U8 camera_flash_command_map[CAMERA_SETTING_FLASH_COUNT + 1] = 
{
    MDI_CAMERA_FLASH_OFF,   /* CAMERA_SETTING_FLASH_OFF */
        MDI_CAMERA_FLASH_ON,    /* CAMERA_SETTING_FLASH_ON */
        
#ifdef __CAMERA_FEATURE_FLASH_AUTO__
        MDI_CAMERA_FLASH_AUTO,  /* CAMERA_SETTING_FLASH_AUTO */
#endif 
        
#ifdef __CAMERA_FEATURE_FLASH_REDEYE__
        MDI_CAMERA_FLASH_REDEYE,    /* CAMERA_SETTING_FLASH_REDEYE */
#endif 
        
        DUMMY_COMMAND
};

/*********** ISO ***********/
const U8 camera_iso_command_map[CAMERA_SETTING_ISO_COUNT + 1] = 
{
#ifdef __CAEMRA_FEATURE_ISO_AUTO__
    MDI_CAMERA_ISO_AUTO,    /* CAMERA_SETTING_ISO_AUTO */
#endif 
        
#ifdef __CAEMRA_FEATURE_ISO_100__
        MDI_CAMERA_ISO_100, /* CAMERA_SETTING_ISO_100 */
#endif 
        
#ifdef __CAEMRA_FEATURE_ISO_200__
        MDI_CAMERA_ISO_200, /* CAMERA_SETTING_ISO_200 */
#endif 
        
#ifdef __CAEMRA_FEATURE_ISO_400__
        MDI_CAMERA_ISO_400, /* CAMERA_SETTING_ISO_400 */
#endif 
        
        DUMMY_COMMAND
};

const U8 camera_autofocus_command_map[CAMERA_SETTING_AUTOFOCUS_COUNT + 1] = 
{
#ifdef __CAMERA_AUTOFOCUS_1_ZONE__
    MDI_CAMERA_AUTOFOCUS_1_ZONE,
#endif 
#ifdef __CAMERA_AUTOFOCUS_3_ZONE__
        MDI_CAMERA_AUTOFOCUS_3_ZONE,
#endif 
#ifdef __CAMERA_AUTOFOCUS_5_ZONE__
        MDI_CAMERA_AUTOFOCUS_5_ZONE,
#endif 
        DUMMY_COMMAND
};

const U8 camera_autofocus_mode_command_map[CAMERA_SETTING_AUTOFOCUS_MODE_COUNT + 1] = 
{
#ifdef __CAMERA_AUTOFOCUS_MODE_AUTO__
    MDI_CAMERA_AUTOFOCUS_MODE_AUTO,
#endif 
#ifdef __CAMERA_AUTOFOCUS_MODE_MACRO__
        MDI_CAMERA_AUTOFOCUS_MODE_MACRO,
#endif 
#ifdef __CAMERA_AUTOFOCUS_MODE_INFINITE__
        MDI_CAMERA_AUTOFOCUS_MODE_INFINITE,
#endif 
        DUMMY_COMMAND
};

/*********** Shot Mode ***********/
const U8 camera_dsc_mode_command_map[CAMERA_SETTING_DSC_MODE_COUNT + 1] = 
{
#ifdef __CAMERA_DSC_MODE_AUTO__
    MDI_CAMERA_DSC_MODE_AUTO,           /* CAMERA_SETTING_DSC_MODE_AUTO */
#endif 
#ifdef __CAMERA_DSC_MODE_PORTRAIT__
        MDI_CAMERA_DSC_MODE_PORTRAIT,       /* CAMERA_SETTING_DSC_MODE_PORTRAIT */
#endif 
#ifdef __CAMERA_DSC_MODE_LANDSCAPE__
        MDI_CAMERA_DSC_MODE_LANDSCAPE,      /* CAMERA_SETTING_DSC_MODE_LANDSCAPE */
#endif 
#ifdef __CAMERA_DSC_MODE_SPORT__
        MDI_CAMERA_DSC_MODE_SPORT,          /* CAMERA_SETTING_DSC_MODE_SPORT */
#endif 
#ifdef __CAMERA_DSC_MODE_FLOWER__
        MDI_CAMERA_DSC_MODE_FLOWER,         /* CAMERA_SETTING_DSC_MODE_FLOWER */
#endif 
#ifdef __CAMERA_DSC_MODE_NIGHT__
        MDI_CAMERA_DSC_MODE_NIGHT,          /* CAMERA_SETTING_DSC_MODE_NIGHT */
#endif 
        
        DUMMY_COMMAND
};

/****************************************************************************
* Global Variable - Extern                                                                 
*****************************************************************************/
extern BOOL r2lMMIFlag;

/****************************************************************************
* Global Function                                                           
*****************************************************************************/
extern void custom_start_flashlight(kal_uint8 red_level, kal_uint8 green_level, kal_uint8 blue_level, kal_uint8 duty);
extern void custom_stop_flashlight(void);

extern void SetClamState(U16 clam_state);
extern void AudioStopReq(U16 soundId);
extern U16 GetCurKeypadTone(void);


#ifdef __MMI_TOUCH_SCREEN__
MMI_BOOL wgui_test_lsk_position(mmi_pen_point_struct pos);
#endif 

#if defined(__MTK_INTERNAL__)// && defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/***************************************************************************** 
* Local Variable
*****************************************************************************/
/* camera contex */
camera_context_struct g_camera_cntx;


/*****************************************************************************
* Local Function 
*****************************************************************************/
#ifdef __CAMERA_FEATURE_XENON_FLASH__
static void mmi_camera_xenon_flash_callback(mdi_result result);
#endif

static U8 mmi_camera_del_scr_callback(void* ptr);

/* setting / path / stroage */
static BOOL mmi_camera_get_storage_disk_path(PS8 drv_buf);
static void mmi_camera_restore_filename_seq_no(void);
static void mmi_camera_get_next_filename(PS8 file_buf_p);
static void mmi_camera_display_error_popup(void);

#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_display_sublcd_error_popup(void);
#endif 

static void mmi_camera_dummy_func(void);

/* app */
void mmi_camera_hilight_app(void);
static U16 mmi_camera_get_img_size_str_id(S32 image_width, S32 image_height);
static void mmi_camera_exit_app_screen(void);
static void mmi_camera_enter_state(camera_state_enum state);
static void mmi_camera_exit_current_state(void);
U8 mmi_camera_clam_close_event_hdlr(mmi_frm_int_event_type interrupt_event);
static void mmi_camera_calc_remain_storage(void);

#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_toggle_self_capture(void);
#endif 

static void mmi_camera_toggle_hide_osd(void);

static void mmi_camera_turn_on_preview_led_highlight(void);
static void mmi_camera_turn_on_capture_led_highlight(void);
static void mmi_camera_turn_off_led_highlight(void);

/* mainlcd preview state */
static void mmi_camera_entry_preview_state(void);
static void mmi_camera_exit_preview_state(void);
#if defined(__MMI_CAMERA_BG_CALL__)
static void mmi_camera_incall_popup_error(void);
static void mmi_camera_incall_set_key_hdlr(void);
#endif
static void mmi_camera_preview_set_key_hdlr(void);
static void mmi_camera_preview_create_resource(void);
static void mmi_camera_preview_free_resource(void);
#if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
static void mmi_camera_create_osd_layer(void);
static void mmi_camera_free_osd_layer(void);
static void mmi_camera_init_osd_icon_layer_position(void);
#endif /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 

void mmi_camera_preview_create_preview_resource(S32 offset_x, S32 offset_y, S32 width, S32 height, U8 rotate);
void mmi_camera_preview_free_preview_resource(void);

static void mmi_camera_preview_start(void);
static void mmi_camera_preview_stop(void);
static void mmi_camera_preview_set_blt_layer(BOOL is_previewing);
static void mmi_camera_preview_clear_background(void);

static void mmi_camera_preview_flatten_layer(BOOL is_previewing);

static void mmi_camera_preview_draw_osd(void);
static void mmi_camera_preview_draw_title(void);
static void mmi_camera_preview_draw_softkey(void);
static void mmi_camera_preview_draw_hint(void);
static void mmi_camera_preview_draw_icon(void);

static void mmi_camera_preview_draw_osd_timer(void);
static void mmi_camera_commit_filename_seq_no(void);
static S32 mmi_camera_get_zoom_total_level_cnt(void);
static U16 mmi_camera_get_zoom_limit(U16 capture_size_enum);

#ifdef __CAMERA_FAST_ZOOM_SUPPORT__
static U16 mmi_camera_get_zoom_level_idx(S32 factor);
static void mmi_camera_start_fast_zoom_in(void);
static void mmi_camera_start_fast_zoom_out(void);
static void mmi_camera_stop_fast_zoom(void);
#endif /* __CAMERA_FAST_ZOOM_SUPPORT__ */ 

#ifdef __CAMERA_FEATURE_CONT_SHOT_DRAW_COUNTBAR__
static void mmi_camera_preview_draw_contshot_countbar(void);
#endif 

static void mmi_camera_preview_set_hint(PS8 hint_str1, PS8 hint_str2, U16 fade_time);
static void mmi_camera_preview_hide_hint(void);

static U16 mmi_camera_preview_get_zoom_factor(void);
static void mmi_camera_preview_ev_inc_key_press(void);
static void mmi_camera_preview_ev_inc_key_release(void);
static void mmi_camera_preview_ev_dec_key_press(void);
static void mmi_camera_preview_ev_dec_key_release(void);

mmi_event_notify_enum mmi_camera_get_error_type_by_error_enum(S32 err_code);

#ifdef __CAMERA_FEATURE_ZOOM__
static void mmi_camera_preview_zoom_in(void);
static void mmi_camera_preview_zoom_out(void);
static void mmi_camera_preview_up_arrow_press(void);
static void mmi_camera_preview_up_arrow_release(void);
static void mmi_camera_preview_down_arrow_press(void);
static void mmi_camera_preview_down_arrow_release(void);
#endif /* __CAMERA_FEATURE_ZOOM__ */ 

/* hotkeys */
#ifdef __CAMERA_FEATURE_EFFECT__
static void mmi_camera_preview_effect_hotkey_press(void);
#endif 

#ifdef __CAMERA_FEATURE_WB__
static void mmi_camera_preview_wb_hotkey_press(void);
#endif 

#ifdef __CAMERA_FEATURE_LED_HIGHLIGHT__
static void mmi_camera_preview_led_highlight_hotkey_press(void);
#endif 

#ifdef __CAMERA_FEATURE_FLASH__
static void mmi_camera_preview_flash_hotkey_press(void);
#endif 

#ifdef __CAMERA_FEATURE_NIGHT__
static void mmi_camera_preview_night_hotkey_press(void);
#endif 

#ifdef __CAMERA_FEATURE_CONT_SHOT__
static void mmi_camera_preview_cont_shot_hotkey_press(void);
#endif 

#ifdef __CAMERA_FEATURE_DELAY_TIMER__
static void mmi_camera_preview_delay_timer_hotkey_press(void);
#endif 

static void mmi_camera_preview_image_qty_hotkey_press(void);
static void mmi_camera_preview_image_size_hotkey_press(void);

#ifdef __CAMERA_FEATURE_STORAGE__
static void mmi_camera_preview_storage_hotkey_press(void);
#endif 

#ifdef __CAMERA_AUTOFOCUS_MODE__
static void mmi_camera_preview_af_mode_hotkey_press(void);
#endif 

#ifdef __CAMERA_AUTOFOCUS_METERING__
static void mmi_camera_preview_af_meter_hotkey_press(void);
#endif 

#ifdef __CAMERA_DSC_MODE__
static void mmi_camera_preview_dsc_mode_hotkey_press(void);
#endif 

#ifdef __CAMERA_FEATURE_ISO_SUPPORT__
static void mmi_camera_preview_iso_hotkey_press(void);
#endif 

#ifdef __CAMERA_FEATURE_AE_METER__
static void mmi_camera_preview_ae_meter_hotkey_press(void);
#endif 


#ifdef __MMI_CAMERA_AF_TEST__
static void mmi_camera_af_test(void);
static void mmi_camera_af_test_start(void);
#endif /* __MMI_CAMERA_AF_TEST__ */ 

#if defined(__AF_SUPPORT_ONE_KEY__) || defined(__MMI_CAMERA_AF_TEST__)
static void mmi_camera_af_and_capture(void);
#endif
#ifdef __CAMERA_AUTOFOCUS_MODE__
static void mmi_camera_preview_af_mode_change(BOOL is_next);
#endif 

#ifdef __CAMERA_AUTOFOCUS_METERING__
static void mmi_camera_preview_af_meter_change(BOOL is_next);
#endif 

#ifdef __CAMERA_DSC_MODE__
static void mmi_camera_preview_dsc_mode_change(BOOL is_next);
#endif /* __CAMERA_DSC_MODE__ */ 


#ifdef __CAMERA_FEATURE_EFFECT__
static void mmi_camera_preview_effect_change(BOOL is_next);
#endif 

#ifdef __CAMERA_FEATURE_WB__
static void mmi_camera_preview_wb_change(BOOL is_next);
#endif 

#ifdef __CAMERA_FEATURE_LED_HIGHLIGHT__
static void mmi_camera_preview_led_highlight_change(BOOL is_next);
#endif 

#ifdef __CAMERA_FEATURE_FLASH__
static void mmi_camera_preview_flash_change(BOOL is_next);
#endif 

#ifdef __CAMERA_FEATURE_NIGHT__
static void mmi_camera_preview_night_change(BOOL is_next);
#endif 

#ifdef __CAMERA_FEATURE_CONT_SHOT__
static void mmi_camera_preview_cont_shot_change(BOOL is_next);
#endif 

#ifdef __CAMERA_FEATURE_DELAY_TIMER__
static void mmi_camera_preview_delay_timer_change(BOOL is_next);
#endif 

static void mmi_camera_preview_image_size_change(BOOL is_next);

static void mmi_camera_preview_image_qty_change(BOOL is_next);

#ifdef __CAMERA_FEATURE_STORAGE__
static void mmi_camera_preview_storage_change(BOOL is_next);
#endif 

#ifdef __CAMERA_FEATURE_ISO_SUPPORT__
static void mmi_camera_preview_iso_change(BOOL is_next);
#endif 

#ifdef __CAMERA_FEATURE_AE_METER__
static void mmi_camera_preview_ae_meter_change(BOOL is_next);
#endif 

#ifdef __CAMERA_FEATURE_ADD_FRAME__
static void mmi_camera_create_add_frame_layer(void);
static void mmi_camera_free_add_frame_layer(void);
static void mmi_camera_draw_add_frame(void);
static void mmi_camera_preview_change_frame_up(void);
static void mmi_camera_preview_change_frame_down(void);
#endif /* __CAMERA_FEATURE_ADD_FRAME__ */ 


static void mmi_camera_preview_lsk_press(void);
static void mmi_camera_preview_lsk_release(void);
static void mmi_camera_preview_rsk_press(void);
static void mmi_camera_preview_rsk_release(void);

/* countdown state */
static void mmi_camera_entry_countdown_state(void);
static void mmi_camera_exit_countdown_state(void);
static void mmi_camera_countdown_cyclic(void);
static void mmi_camera_countdown_stop_LED(void);

#ifdef __COUNTDOWN_USING_MMA__
static void mmi_camera_init_countdown_mma(void);
static void mmi_camera_deinit_countdown_mma(void);
#endif

/* contshot state */
static void mmi_camera_entry_contshot_state(void);
static void mmi_camera_exit_contshot_state(void);
static void mmi_camera_contshot_cyclic(void);

#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
/* burstshot state */
static void mmi_camera_entry_burstshot_capture_state(void);
static void mmi_camera_exit_burstshot_capture_state(void);

#if defined(__CAMERA_FEATURE_CONT_SHOT_BURST__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__)
static void mmi_camera_burstshot_capture_result_hdlr(MDI_RESULT ret, U16 captured_count);
static void mmi_camera_burstshot_close_multi_sound(void);
#endif /* defined(__CAMERA_FEATURE_CONT_SHOT_BURST__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__) */ 

/* burstshot save confirm state */
static void mmi_camera_entry_burstshot_save_confirm_state(void);
static void mmi_camera_exit_burstshot_save_confirm_state(void);
static void mmi_camera_burstshot_save_confirm_lsk_press(void);
static void mmi_camera_burstshot_save_confirm_lsk_release(void);
static void mmi_camera_burstshot_save_confirm_rsk_press(void);
static void mmi_camera_burstshot_save_confirm_rsk_release(void);

/* burstshot saving state */
static void mmi_camera_entry_burstshot_saving_state(void);
static void mmi_camera_exit_burstshot_saving_state(void);
static void mmi_camera_burstshot_saving_cyclic(void);
#endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 

/* save confirm state */
static void mmi_camera_entry_delete_confirm_state(void);
static void mmi_camera_exit_delete_confirm_state(void);
static void mmi_camera_delete_confirm_lsk_press(void);
static void mmi_camera_delete_confirm_lsk_release(void);
static void mmi_camera_delete_confirm_rsk_press(void);
static void mmi_camera_delete_confirm_rsk_release(void);
static void mmi_camera_delete_confirm_delete_file(void);
#if defined(__MMI_CAMERA_FORWARD_SUPPORT__)
static void mmi_camera_forward_icon_press(void);
static void mmi_camera_forward_icon_release(void);
#endif /* __MMI_CAMERA_FORWARD_SUPPORT__ */ 

static void mmi_camera_update_osd_touch_icon(void);

/* capture */
static void mmi_camera_capture(void);
static void mmi_camera_capture_button_press(void);
static void mmi_camera_capture_button_release(void);

#ifdef __CAMERA_AUTOFOCUS__
static void mmi_camera_capture_button_autofocus_pressed(void);
static void mmi_camera_capture_button_autofocus_released(void);
static void mmi_camera_autofocus_callback(mdi_camera_af_result_struct pMsg);
static void mmi_camera_play_af_succeed_finished(void);
static void mmi_camera_draw_autofocus_process(void);
static void mmi_camera_preview_draw_osd_timer(void);
static void mmi_camera_draw_bolder_rect(S32 x1, S32 y1, S32 x2, S32 y2, S32 bolder_width, gdi_color frame_color);
#endif /* __CAMERA_AUTOFOCUS__ */ 


#if defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__)
static void mmi_camera_capture_play_multi_channel_sound(void);
#endif 

/* save done */
static void mmi_camera_entry_delete_done_state(void);
static void mmi_camera_exit_delete_done_state(void);
static void mmi_camera_delete_done_timeout(void);

#ifdef __MMI_SUBLCD__
/* sub screen */
void mmi_camera_entry_sublcd_screen(void);
void mmi_camera_exit_sublcd_screen(void);
static void mmi_camera_sublcd_capture(void);
#endif /* __MMI_SUBLCD__ */ 

#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
/* toggle to sub state */
static void mmi_camera_entry_toggle_to_sub_state(void);
static void mmi_camera_exit_toggle_to_sub_state(void);
static void mmi_camera_toggle_to_sub_timeout(void);

/* toggle to main state */
static void mmi_camera_entry_toggle_to_main_state(void);
static void mmi_camera_exit_toggle_to_main_state(void);
static void mmi_camera_toggle_to_main_timeout(void);

/* sublcd preview state */
static void mmi_camera_entry_sublcd_preview_state(void);
static void mmi_camera_exit_sublcd_preview_state(void);
static void mmi_camera_sublcd_preview_set_key_hdlr(void);
static void mmi_camera_sublcd_preview_start(void);
static void mmi_camera_sublcd_preview_stop(void);
static void mmi_camera_sublcd_preview_set_blt_layer(BOOL is_previewing);
static void mmi_camera_sublcd_preview_lsk_press(void);
static void mmi_camera_sublcd_preview_rsk_press(void);
static void mmi_camera_sublcd_preview_lsk_release(void);
static void mmi_camera_sublcd_preview_rsk_release(void);

/* sublcd countdown state */
static void mmi_camera_entry_sublcd_countdown_state(void);
static void mmi_camera_exit_sublcd_countdown_state(void);
static void mmi_camera_sublcd_countdown_cyclic(void);
static void mmi_camera_sublcd_countdown_stop_LED(void);

/* sublcd contshot state */
static void mmi_camera_entry_sublcd_contshot_state(void);
static void mmi_camera_exit_sublcd_contshot_state(void);
static void mmi_camera_sublcd_contshot_cyclic(void);

#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
/* sublcd burstshot state */
static void mmi_camera_entry_sublcd_burstshot_state(void);
static void mmi_camera_exit_sublcd_burstshot_state(void);

#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__
static void mmi_camera_sublcd_burstshot_capture_result_hdlr(MDI_RESULT ret, U16 captured_count);
#endif 

#endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 

/* sublcd burstshot saving state */
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
static void mmi_camera_entry_sublcd_burstshot_saving_state(void);
static void mmi_camera_exit_sublcd_burstshot_saving_state(void);
static void mmi_camera_sublcd_burstshot_saving_cyclic(void);
#endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 

/* sublcd capture */
static void mmi_camera_sublcd_capture_button_press(void);
static void mmi_camera_sublcd_capture(void);


#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 

/* util draw */
static void mmi_camera_initilize_zoom_factor(void);

#if defined(__CAMERA_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_camera_touch_scr_pen_down_hdlr(mmi_pen_point_struct pos);
static void mmi_camera_touch_scr_pen_up_hdlr(mmi_pen_point_struct pos);
static void mmi_camera_touch_scr_pen_move_hdlr(mmi_pen_point_struct pos);
static BOOL mmi_camera_touch_scr_hit_test(S32 pos_x, S32 pos_y, camera_ui_touch_struct *touch_obj);
#endif /* defined(__CAMERA_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__) */ 

#ifdef __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__
void mmi_camera_restart_app_watchdog(void);
void mmi_camera_stop_app_watchdog(void);
void mmi_camera_app_watchdog_callback(void);
void mmi_camera_stop_delete_confirm_watchdog(void);
void mmi_camera_delete_confirm_watchdog_timer_callback(void);
void mmi_camera_start_delete_confirm_watchdog(void);
static void mmi_camera_start_all_watchdog(void);
static void mmi_camera_stop_all_watchdog(void);
#endif /* __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__ */

/* screen snapshot */
#ifdef __MMI_SCREEN_SNAPSHOT__
static void mmi_camera_entry_scr_snapshot_screen(void);
static void mmi_camera_exit_scr_snapshot_screen(void);
#endif /* __MMI_SCREEN_SNAPSHOT__ */ 
#if defined(__CAMERA_OSD_HORIZONTAL__)
static void mmi_camera_config_layer_orientation(void);
static void mmi_camera_check_osd_orientation(void);
#endif
static void mmi_camera_free_app_mem(void);
static void mmi_camera_app_mem_stop_callback(void);
static void mmi_camera_app_mem_success_callback(void);
static void mmi_camera_pre_init_app(void);
static void mmi_camera_post_init_app(void);
static void mmi_camera_init_framework(void);
static void mmi_camera_entry_app_screen_internal(void);
static void mmi_camera_app_screen(void);
#ifndef GDI_USING_2D_ENGINE_V3 
void mmi_camera_sw_rotate(
                          U8* pDst,
                          U8* pSrc,
                          U32 const src_width,
                          U32 const src_height);
#endif

                          /**
                          * Adding functions for operatoer 
****/
#ifdef __MMI_CAMERA_RECORDER_ONE_KEY_TOGGLE__
void mmi_camera_switch_to_vdorec_app(void);
void mmi_camera_highlight_to_vdorec_app(void);
#endif /* __MMI_CAMERA_RECORDER_ONE_KEY_TOGGLE__ */

void mmi_camera_entry_forward_menu_screen(void);
MMI_BOOL mmi_camera_is_forward_function_ready(void);
void mmi_camera_hilight_forward_to_bt(void);
void mmi_camera_hilight_forward_to_email(void);
void mmi_camera_hilight_forward_to_mms(void);
void mmi_camera_forward_to_hdlr(void);


#if defined(__MMI_SUBLCD_CAMERA__)
static void mmi_sublcd_camera_exit_option_screen(void);
static void mmi_sublcd_camera_entry_preview_screen(void);
static void mmi_sublcd_camera_entry_flash_screen(void);
static void mmi_sublcd_camera_flash_highlight_hdlr(S32 idx);
static void mmi_sublcd_camera_exit_flash_screen(void);
static void mmi_sublcd_camera_exit(void);
static void mmi_sublcd_camera_set_flash(void);
void mmi_sublcd_camera_hilight_preview(void);
void mmi_sublcd_camera_hilight_flash(void);
void mmi_sublcd_camera_hilight_flash_option(void);
void mmi_sublcd_camera_hilight_exit(void);
U8 mmi_sublcd_camera_clam_close_event_hdlr(void *ptr);
static void mmi_sublicd_camera_display_error_screen(void);
static void mmi_sublcd_camera_capture(void);
static void mmi_sublcd_camera_preview_start(void);
static void mmi_sublcd_camera_entry_flash_screen_ex(void);
static void mmi_sublcd_camera_entry_preview_screen_ex(void);
static void mmi_sublcd_camera_entry_option_screen_ex(void);
#endif /* __MMI_SUBLCD_CAMERA */


static void mmi_camera_reentry_preview_state(void);
static void mmi_camera_reset_osd_layer(void);
static void mmi_camera_reset_base_layer(void);
static MMI_BOOL mmi_camera_delete_confirm_option_cmd_hdlr(U16 menu_id);
void mmi_camera_change_to_largest_img_size(void);
static void mmi_camera_app_reset_state(void);

#if defined(__MMI_SUBLCD_CAMERA__)
static void mmi_sublcd_camera_capture(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filename[FMGR_PATH_BUFFER_SIZE];
    U32 ticks = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* this function has nvram access */
    mmi_camera_get_next_filename(buf_filename);
    
    mmi_camera_commit_filename_seq_no();
    
    mmi_camera_turn_on_capture_led_highlight();
    
    g_camera_cntx.is_continue_capture = FALSE;
    g_camera_cntx.last_error = mdi_camera_capture_to_file(buf_filename, g_camera_cntx.is_continue_capture);
    
    /* play capture sound after capture */
    mmi_camera_capture_play_sound();
    
    /* restore black background */
#ifdef CAMERA_MODULE_WITH_LCD
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
#endif /* CAMERA_MODULE_WITH_LCD */ 
    
    mmi_camera_turn_off_led_highlight();
    
    /* captured, previwing is stopped, change blt layer */
    mmi_camera_sublcd_preview_set_blt_layer(FALSE);
    
    ClearKeyEvents();
    if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
    {
        FS_Delete((U16*) buf_filename);
        kal_get_time(&ticks);
        while (ticks - g_camera_cntx.multi_sound_tick < 100 || g_camera_cntx.multi_sound_tick - ticks < 100)
        {
            kal_get_time(&ticks);
        }
        mmi_camera_restore_filename_seq_no();
        DisplaySubLcdPopup(IMG_GLOBAL_ERROR);
        DeleteSubLCDScreen(SCR_ID_CAMERA_SUBLCD_APP);
        ClearInputEventHandler(MMI_DEVICE_KEY);
        return;
    }
    mmi_sublcd_camera_preview_start();
    
}

static void mmi_sublcd_camera_preview_start(void)
{
    mdi_camera_setting_struct camera_setting_data;
    mdi_camera_preview_struct camera_preview_data;
    S32 sublcd_width;
    S32 sublcd_height;
    
#if defined(ISP_SUPPORT)
    /* set correct lcm rotate && config rotate of preview layer, only ISP_SUPPORT need */
    gdi_layer_push_and_set_active(g_camera_cntx.sublcd_base_layer_handle);
    gdi_layer_set_rotate(CAMERA_LCM_SUBLCD_CLAM_CLOSE_ROTATE);
    gdi_layer_pop_and_restore_active();
#endif /* defined(ISP_SUPPORT) */ 
    
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_layer_get_dimension(&sublcd_width, &sublcd_height);
    gdi_layer_set_blt_layer(g_camera_cntx.sublcd_base_layer_handle, 0, 0, 0);
    
#ifdef CAMERA_MODULE_WITH_LCD
    gdi_layer_clear(CAMEAR_BG_TRASN_COLOR);
#endif 
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
    
    /* turn on led highlight */
    mmi_camera_turn_on_preview_led_highlight();
    
    
    mdi_camera_load_default_setting(&camera_setting_data);
    camera_setting_data.lcm = MDI_CAMERA_PREVIEW_LCM_SUBLCD;
    
    camera_setting_data.preview_width = SUBLCD_CAMERA_PREVIEW_WIDTH;
    camera_setting_data.preview_height = SUBLCD_CAMERA_PREVIEW_HEIGHT;
    camera_setting_data.preview_rotate = CAMERA_PREVIEW_SUBLCD_CLAM_CLOSE_ROTATE;
    camera_setting_data.lcm_rotate = CAMERA_LCM_SUBLCD_CLAM_CLOSE_ROTATE;
    
    camera_setting_data.image_width = SUBLCD_CAMERA_CAPTURE_WIDTH;
    camera_setting_data.image_height = SUBLCD_CAMERA_CAPTURE_HEIGHT;
    
    camera_setting_data.continue_capture = g_camera_cntx.is_continue_capture;
    camera_setting_data.xenon_flash_status_callback = NULL;
    /* preview data for preview start */
    camera_preview_data.preview_layer_handle = g_camera_cntx.sublcd_base_layer_handle;
    camera_preview_data.preview_wnd_offset_x = 0;
    camera_preview_data.preview_wnd_offset_y = 0;
    camera_preview_data.preview_wnd_width = sublcd_width;
    camera_preview_data.preview_wnd_height = sublcd_height;
    camera_preview_data.blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0;
    camera_preview_data.preview_layer_flag = GDI_LAYER_ENABLE_LAYER_0;
    camera_preview_data.is_lcd_update = TRUE;
    camera_preview_data.src_key_color = CAMEAR_BG_TRASN_COLOR;/* this value is use only CAMERA_MODULE_WITH_LCD */
    camera_preview_data.is_tvout = FALSE;
    
    /* start preview */
    g_camera_cntx.last_error = mdi_camera_preview_start(
        &camera_preview_data,
        &camera_setting_data);
    
}
BOOL mmi_sublcd_camera_delete_screen_if_present(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrnid;
    BOOL ret = FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(scrnid= SCR_ID_CAMERA_SUBLCD_APP; scrnid <= SCR_ID_CAMERA_SUBLCD_OPTION_FLASH; scrnid++)
    {
        if (IsSubLCDScreenPresent(scrnid))
        {
            DeleteSubLCDScreen(scrnid);
            ret = TRUE;
        }
        else if (GetSubLCActiveScreenId()==scrnid)
            ret = TRUE;
    }
    
    return ret;
}
static void mmi_sublicd_camera_display_error_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 ticks = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    kal_get_time(&ticks);
    while (ticks - g_camera_cntx.multi_sound_tick < 100 || g_camera_cntx.multi_sound_tick - ticks < 100)
    {
        kal_get_time(&ticks);
    }
    DisplaySubLcdPopup(IMG_GLOBAL_ERROR);
    mmi_sublcd_camera_delete_screen_if_present();
}


U8 mmi_sublcd_camera_clam_close_event_hdlr(void *ptr)
{
    return FALSE;
}


static void mmi_sublcd_camera_set_flash(void)
{
    /* off */
    if(g_camera_cntx.cur_select_flash_idx == 1) 
    {
#ifdef __CAMERA_FEATURE_FLASH__
        g_camera_cntx.setting.flash = CAMERA_SETTING_FLASH_OFF;
#endif
#ifdef __CAMERA_FEATURE_LED_HIGHLIGHT_ON_OFF__
        g_camera_cntx.setting.led_highlight = CAMERA_SETTING_LED_HIGHLIGHT_OFF;
#endif
    }
    else
    {
#ifdef __CAMERA_FEATURE_FLASH__
        g_camera_cntx.setting.flash = CAMERA_SETTING_FLASH_ON;
#endif
#ifdef __CAMERA_FEATURE_LED_HIGHLIGHT_ON_OFF__
        g_camera_cntx.setting.led_highlight = CAMERA_SETTING_LED_HIGHLIGHT_ON;
#endif
    }
    mmi_camera_store_setting();
    ClearKeyEvents();
    ClearInputEventHandler(MMI_DEVICE_KEY);
    GoBackSubLCDHistory();
}
static void mmi_sublcd_camera_entry_preview_screen(void)
{
    DisplaySubLCDScreen(SCR_ID_CAMERA_SUBLCD_APP, mmi_sublcd_camera_entry_preview_screen_ex, 1);
}
static void mmi_sublcd_camera_entry_preview_screen_ex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 cur_storage = 0;
    S32 create_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
    ClearInputEventHandler(MMI_DEVICE_KEY);
    
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        
        if (mmi_usb_check_path_exported((PS8) MMI_IMGVIEW_STORAGE_FILEPATH_PHONE))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

#if defined(__CAMERA_FEATURE_STORAGE__)
    /*No phone storage*/
    if (MMI_PUBLIC_DRV == MMI_CARD_DRV || MMI_PUBLIC_DRV == FS_DRIVE_NOT_FOUND)
    {
        /* only memory card but plugout, need show popup*/
        if (FS_NO_ERROR != FS_GetDevStatus(MMI_CARD_DRV ,FS_MOUNT_STATE_ENUM))
        {
            MMI_CAMERA_DISPLAY_POPUP((PU8)GetString(STR_GLOBAL_INSERT_MEMORY_CARD), MMI_EVENT_FAILURE);
            mmi_camera_app_reset_state();
            return;
        }
    }
#endif

    g_camera_cntx.is_sublcd_previewing = TRUE;
    
    /* turn off 3D sound */
#ifdef __MMI_AUDIO_REVERB_EFFECT__
    g_camera_cntx.is_3d_sound_on = mmi_settings_audio_reverb_get_status();
    if (g_camera_cntx.is_3d_sound_on == TRUE)
    {
        mdi_audio_reverb_turn_off();
    }
#endif /* __MMI_AUDIO_REVERB_EFFECT__ */ 
    
    /************ init/config framework's environment  ************/
    
    /* entry full screen app */
    entry_full_screen();
    
    /* 
    * This is used to solve a very rare situation. When playing a IMELODY 
    * with backlight on/off, and the screen previous to this screen is a 
    * horizontal screen. Before enter this screen, the IMELODY turn off the
    * backlight. While exit previous screen, the layer rotate back to normal
    * size and the content is not correct. So when calling TurnOnBacklight, 
    * LCD is in sleepin state and draw wrong content to LCD.
    * So we need to clear the buffer first to avoid this situation.
    */
    gdi_layer_clear(GDI_COLOR_BLACK);
    
    /* stop MMI sleep */
    TurnOnBacklight(0);
    
    /* force all playing keypad tone off */
    AudioStopReq(GetCurKeypadTone());
    
    /* disable key pad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
    
    /* disalbe align timer  */
    UI_disable_alignment_timers();
    
    /* stop LED patten */
    StopLEDPatternBackGround();
    
    /* get sublcd base layer handle */
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_layer_get_base_handle(&g_camera_cntx.sublcd_base_layer_handle);
    gdi_layer_clear(GDI_COLOR_BLACK);
#ifndef __MTK_TARGET__
    {
        S32 lcd_width;
        S32 lcd_height;
        gdi_lcd_get_dimension(&lcd_width, &lcd_height);
        gdi_layer_blt_base_layer(0, 0, lcd_width - 1, lcd_height - 1);
    }
#endif    
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
    
    gdi_lcd_freeze(TRUE);
    /************ init camera app environment ************/
    
    /* init some flags */
    g_camera_cntx.last_error = MDI_RES_CAMERA_SUCCEED;
    g_camera_cntx.lcm_rotate = CAMERA_LCM_MAINLCD_ROTATE;
    
    /* load Setting */
    mmi_camera_load_setting();
    
    /* allocate storage path buffer */
    g_camera_cntx.storage_filepath = gui_malloc(FMGR_PATH_BUFFER_SIZE);
    memset(g_camera_cntx.storage_filepath, 0, FMGR_PATH_BUFFER_SIZE);
    
    if (mmi_camera_check_and_restore_valid_drv())
    {
        /* drv is valid, create directory */
        mmi_imgview_get_storage_file_path(g_camera_cntx.storage_filepath);
        create_result = mmi_imgview_create_file_dir(g_camera_cntx.storage_filepath);
        
        /* create directory failed */
        if (create_result == FS_WRITE_PROTECTION)
        {
            g_camera_cntx.last_error = CAMERA_ERR_WRITE_PROTECT;
            
            /* has error - restore to phone */
            mmi_imgview_set_storage((U16)MMI_PUBLIC_DRV);
        }
        else if (create_result == FS_DISK_FULL)
        {
            if (cur_storage == MMI_PUBLIC_DRV)
            {
                g_camera_cntx.last_error = CAMERA_ERR_PHONE_DISK_FULL;
            }
            else
            {
                /* storage is card */
                g_camera_cntx.last_error = CAMERA_ERR_CARD_DISK_FULL;
                
                /* has error - restore to phone */
                mmi_imgview_set_storage((U16)MMI_PUBLIC_DRV);
            }
        }
        else if (create_result == FS_ROOT_DIR_FULL)
        {
            if (cur_storage == MMI_PUBLIC_DRV)
            {
                g_camera_cntx.last_error = CAMERA_ERR_ROOT_DIR_FULL;
            }
            else
            {
                /* storage is card */
                g_camera_cntx.last_error = CAMERA_ERR_ROOT_DIR_FULL;
                
                /* has error - restore to phone */
                mmi_imgview_set_storage((U16)MMI_PUBLIC_DRV);
            }
        }
    }
    else
    {
        g_camera_cntx.last_error = MDI_RES_CAMERA_ERR_NO_DISK;
        mmi_imgview_set_storage_not_ready();
    }
    
    /* each time newly enter camera, zoom will be reset to default */
    if (guiBuffer == NULL)
    {
        g_camera_cntx.setting.zoom_idx = CAMERA_DEFAULT_SETTING_ZOOM_IDX;
    }
    
    /* power on and init hardware module */
    if (g_camera_cntx.last_error == MDI_RES_CAMERA_SUCCEED)
    {
        g_camera_cntx.last_error = mdi_camera_power_on();
    }
    
    
    /************ enter next state ************/
    /* entry preview */
    if (g_camera_cntx.last_error == MDI_RES_CAMERA_SUCCEED)  /* no error, if has error, will enter main then show error popup */
    {
        /* set key handler */
        
        /* preview start */
        mmi_sublcd_camera_preview_start();
        
        /* check if preview function has error */
        if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
        {
            mmi_sublicd_camera_display_error_screen();
            return;
        }
    }
    else
    {
        mmi_sublicd_camera_display_error_screen();
        return;
    }
    
    SetKeyHandler(mmi_sublcd_camera_capture, KEY_CAMERA, KEY_EVENT_UP);
    SetKeyHandler(GoBackSubLCDHistory, KEY_CAMERA, KEY_EVENT_LONG_PRESS);
    SetSubLCDExitHandler(mmi_sublcd_camera_exit_preview_screen);
    ClearKeyEvents();
}


BOOL mmi_sublcd_camera_is_previewing(void)
{
    return g_camera_cntx.is_sublcd_previewing;
}
void mmi_sublcd_camera_exit_preview_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (!IsSubLCDScreenPresent(SCR_ID_CAMERA_SUBLCD_APP))
    {
        SubLCDHistoryNode SubLCDHistory;
        
        SubLCDHistory.entryFuncPtr = mmi_sublcd_camera_entry_preview_screen_ex;
        AddSubLCDHistoryWithScrID(&SubLCDHistory, SCR_ID_CAMERA_SUBLCD_APP);
    }
    
    
    /* turn off led highlight */
    mmi_camera_turn_off_led_highlight();
    
    /* stop previewing */
    mmi_camera_sublcd_preview_stop();
    
    /* turn on/of 3D sound */
#ifdef __MMI_AUDIO_REVERB_EFFECT__
    if (g_camera_cntx.is_3d_sound_on == TRUE)
    {
        mdi_audio_reverb_turn_on();
    }
#endif /* __MMI_AUDIO_REVERB_EFFECT__ */ 
    
    /* shut down camera */
    mdi_camera_power_off();
    
    /* resume alignment timer */
    UI_enable_alignment_timers();
    
    /* resume LED patten */
    StartLEDPatternBackGround();
    
    /* let MMI can sleep */
    TurnOffBacklight();
    
    
    /* re-enable keypad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);
    
    /* free buffer */
    gui_free(g_camera_cntx.storage_filepath);
    g_camera_cntx.storage_filepath = NULL;
    
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
    
    gdi_lcd_freeze(FALSE);
    
    gdi_layer_push_and_set_active(g_camera_cntx.sublcd_base_layer_handle);
    gdi_layer_set_rotate(CAMERA_LCM_ROTATE_0);
    gdi_layer_pop_and_restore_active();
    
    /* store camera setting back to NVRAM */
    mmi_camera_store_setting();
    
    g_camera_cntx.is_sublcd_previewing = FALSE;
}
/*****************************************************************************
* FUNCTION
*  mmi_camera_add_frame_highlight_hdlr
* DESCRIPTION
*  add frame highlight handler
* PARAMETERS
*  idx     [IN]        Highlight index
* RETURNS
*  void
*****************************************************************************/
static void mmi_sublcd_camera_flash_highlight_hdlr(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.cur_select_flash_idx= idx;
}

static void mmi_sublcd_camera_entry_flash_screen(void)
{
    DisplaySubLCDScreen(SCR_ID_CAMERA_SUBLCD_OPTION_FLASH, mmi_sublcd_camera_entry_flash_screen_ex, 1);
}
static void mmi_sublcd_camera_entry_flash_screen_ex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[16];
    U16 ItemIcons[16];
    U16 nItems;
    U8 *guiBuffer;
    U8 *PopUpList[32];
    S32 i;
    S32 hilight_item = 0;
    BOOL is_hide = TRUE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
    
    mmi_camera_load_setting();
#if defined(__CAMERA_FEATURE_FLASH__) 
    if (g_camera_cntx.setting.flash == CAMERA_SETTING_FLASH_OFF)
        hilight_item = 1;
    else 
        hilight_item = 0;
#elif defined(__CAMERA_FEATURE_LED_HIGHLIGHT__)
    if (g_camera_cntx.setting.led_highlight == CAMERA_SETTING_LED_HIGHLIGHT_OFF )
        hilight_item = 1;
    else 
        hilight_item = 0;
#endif
    
    ClearInputEventHandler(MMI_DEVICE_KEY);
    
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CAMERA_SUBLCD_OPTION_FLASH);
    nItems = GetNumOfChild_Ext(MENU_ID_CAMERA_SUBLCD_FLASH);
    GetSequenceStringIds_Ext(MENU_ID_CAMERA_SUBLCD_FLASH, ItemList);
    SetParentHandler(MENU_ID_CAMERA_SUBLCD_FLASH);
    
    RegisterHighlightHandler(mmi_sublcd_camera_flash_highlight_hdlr);
    
    for (i = 0; i < nItems; i++)
    {
        PopUpList[i] = NULL;
        ItemIcons[i] = IMG_GLOBAL_L1 + i;
    }
    
    ConstructHintsList(MENU_ID_CAMERA_SUBLCD_FLASH, PopUpList);
    
    /* need to register clam open/close handler */
    
    ShowCategory314Screen(
        (U8*) GetString(STR_ID_CAMERA_FLASH),
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        nItems,
        ItemList,
        ItemIcons,
        (U8 **) PopUpList,
        hilight_item,
        guiBuffer);
    
    SetKeyHandler(mmi_sublcd_camera_set_flash, KEY_CAMERA, KEY_EVENT_UP);
    SetSubLCDExitHandler(mmi_sublcd_camera_exit_flash_screen);
    
}
static void mmi_sublcd_camera_exit(void)
{
    GoBackHistory();
    ClearKeyEvents();
}

static void mmi_sublcd_camera_exit_flash_screen(void)
{
    if (!IsSubLCDScreenPresent(SCR_ID_CAMERA_SUBLCD_OPTION_FLASH))
    {
        SubLCDHistoryNode SubLCDHistory;
        
        SubLCDHistory.entryFuncPtr = mmi_sublcd_camera_entry_flash_screen_ex;
        AddSubLCDHistoryWithScrID(&SubLCDHistory, SCR_ID_CAMERA_SUBLCD_OPTION_FLASH);
    }
    ExitCategory314Screen();
}


void mmi_sublcd_camera_hilight_preview(void)
{
    SetKeyHandler(mmi_camera_dummy_func, KEY_CAMERA, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_sublcd_camera_entry_preview_screen, KEY_CAMERA, KEY_EVENT_UP);
}


void mmi_sublcd_camera_hilight_flash(void)
{
    SetKeyHandler(mmi_camera_dummy_func, KEY_CAMERA, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_sublcd_camera_entry_flash_screen, KEY_CAMERA, KEY_EVENT_UP);
}


void mmi_sublcd_camera_hilight_flash_option(void)
{
    SetKeyHandler(mmi_camera_dummy_func, KEY_CAMERA, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_sublcd_camera_set_flash, KEY_CAMERA, KEY_EVENT_UP);
}


void mmi_sublcd_camera_hilight_exit(void)
{
    SetKeyHandler(mmi_camera_dummy_func, KEY_CAMERA, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_sublcd_camera_exit, KEY_CAMERA, KEY_EVENT_UP);
}

static void mmi_sublcd_camera_event_handler(void)
{
    if (mmi_sublcd_camera_is_previewing())
        mmi_sublcd_camera_exit_preview_screen();
    
    /* resume background audio */
    mdi_audio_resume_background_play();
    
    ForceSubLCDScreen(ShowIdleAppSubLcd);
}

void mmi_sublcd_camera_entry_option_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* stop bg music */
    mdi_audio_suspend_background_play();
    
    /* for hiding audioplayr title */
    if (mmi_idle_is_on_idle_screen()==TRUE)
        EntryIdleScreen();
    
    EntryNewScreen(SCR_ID_CAMERA_SUBLCD_OPTION, mmi_sublcd_camera_event_handler, NULL, NULL);
    
    ShowCategoryDummyScreen();
    DisplaySubLCDScreen(SCR_ID_CAMERA_SUBLCD_OPTION, mmi_sublcd_camera_entry_option_screen_ex, 1);
}

void mmi_sublcd_camera_entry_option_screen_ex(void)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[16];
    U16 ItemIcons[16];
    U16 nItems;
    U8 *guiBuffer;
    U8 *PopUpList[32];
    S32 i;
    BOOL is_hide = TRUE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
    
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CAMERA_SUBLCD_OPTION);
    nItems = GetNumOfChild_Ext(MENU_ID_CAMERA_SUBLCD_OPTION);
    GetSequenceStringIds_Ext(MENU_ID_CAMERA_SUBLCD_OPTION, ItemList);
    GetSequenceImageIds_Ext(MENU_ID_CAMERA_SUBLCD_OPTION, ItemIcons);
    SetParentHandler(MENU_ID_CAMERA_SUBLCD_OPTION);
    
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    
    for (i = 0; i < nItems; i++)
    {
        PopUpList[i] = NULL;
        ItemIcons[i] = IMG_GLOBAL_L1 + i;
    }
    
    ConstructHintsList(MENU_ID_CAMERA_SUBLCD_OPTION, PopUpList);
    
    /* need to register clam open/close handler */
    
    ShowCategory314Screen(
        (U8*) GetString(STR_GLOBAL_OPTIONS),
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        nItems,
        ItemList,
        ItemIcons,
        (U8 **) PopUpList,
        0,
        guiBuffer);
    
    SetKeyHandler(mmi_sublcd_camera_exit, KEY_CAMERA, KEY_LONG_PRESS);
    ClearKeyEvents();    
    SetSubLCDExitHandler(mmi_sublcd_camera_exit_option_screen);
    
}

static void mmi_sublcd_camera_exit_option_screen(void)
{
    if (!IsSubLCDScreenPresent(SCR_ID_CAMERA_SUBLCD_OPTION))
    {
        SubLCDHistoryNode SubLCDHistory;
        
        SubLCDHistory.entryFuncPtr = mmi_sublcd_camera_entry_option_screen_ex;
        AddSubLCDHistoryWithScrID(&SubLCDHistory, SCR_ID_CAMERA_SUBLCD_OPTION);
    }
    ExitCategory314Screen();
}
#endif /* __MMI_CAMERA_SUBLCD__ */


/***************************************************************************
*
*  Settings / File Path / Storage handling                                                     
*
***************************************************************************/
/*****************************************************************************
* FUNCTION
*  mmi_camera_reset_key_press_state
* DESCRIPTION
*  Check if desired path is ready or not. If not, will restore to valid path.
* PARAMETERS
*  void
* RETURNS
* BOOL
*****************************************************************************/
void mmi_camera_reset_key_press_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.is_rsk_pressed = FALSE;
    g_camera_cntx.is_lsk_pressed = FALSE;
}

    

/*****************************************************************************
* FUNCTION
*  mmi_camera_check_and_restore_valid_drv
* DESCRIPTION
*  Check if desired path is ready or not. If not, will restore to valid path.
* PARAMETERS
*  void
* RETURNS
* BOOL
*****************************************************************************/
BOOL mmi_camera_check_and_restore_valid_drv(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 storage;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    storage = mmi_imgview_get_storage();
    
    if (FS_NO_ERROR == FS_GetDevStatus(storage ,FS_MOUNT_STATE_ENUM))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_get_storage_disk_path
* DESCRIPTION
*  get current active storage disk path.
* PARAMETERS
*  drv_buf     [IN]        
*  a(?)        [OUT]       Fill disk's name string.
* RETURNS
*  void
*****************************************************************************/
static BOOL mmi_camera_get_storage_disk_path(PS8 drv_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf[64];
    U16 storage;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    storage = mmi_imgview_get_storage();
    
    if (FS_NO_ERROR == FS_GetDevStatus(storage ,FS_MOUNT_STATE_ENUM))
    {
        sprintf(buf, "%c:\\", (U8)storage );
        mmi_asc_to_ucs2(drv_buf, buf);
        return TRUE;
    }
    else
    {
        return FALSE;
    }   
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_load_setting
* DESCRIPTION
*  load camera settings from NVRAM
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_camera_load_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if setting is already loaded from NVRAM, it is already exist in memory, do not loaded again */
    if (!g_camera_cntx.is_setting_loaded)
    {
        U16 old_storage;
        ReadRecord(
            NVRAM_EF_CAMERA_SETTING_LID,
            1,
            (void*)&g_camera_cntx.setting,
            NVRAM_EF_CAMERA_SETTING_SIZE,
            &error);
        
        /* first time init */
        if (g_camera_cntx.setting.wb == 0xffff)
        {
            mmi_camera_restore_setting();
        }
        
        g_camera_cntx.setting.preview_led_value = CAMERA_DEFAULT_PREVIEW_LED_VALUE;
        g_camera_cntx.setting.capture_led_value = CAMERA_DEFAULT_CAPTURE_LED_VALUE;
        
        /* init preview size based on LCD size */
        mmi_camera_preview_update_capture_size();
        
        /* load image viewer setting - for storage path */
        mmi_imgview_load_setting();
        
        ReadValue(NVRAM_CAM_FILENAME_SEQ_NO, &g_camera_cntx.filename_seq_no, DS_SHORT, &error);
        
        g_camera_cntx.is_setting_loaded = TRUE;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_store_setting
* DESCRIPTION
*  store camera settings to NVRAM
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_camera_store_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteRecord(NVRAM_EF_CAMERA_SETTING_LID, 1, (void*)&g_camera_cntx.setting, NVRAM_EF_CAMERA_SETTING_SIZE, &error);
    WriteValue(NVRAM_CAM_FILENAME_SEQ_NO, &g_camera_cntx.filename_seq_no, DS_SHORT, &error);
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_restore_factory
* DESCRIPTION
*  restore camera setting to default value
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_camera_restore_factory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mmi_restore_app_data(NVRAM_APP_CAMERAPP,NULL);
    g_camera_cntx.is_setting_loaded = MMI_FALSE;
    mmi_camera_load_setting();
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_restore_setting
* DESCRIPTION
*  restore camera setting to default value
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_camera_restore_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.setting.wb = CAMERA_DEFAULT_SETTING_WB;
    g_camera_cntx.setting.flash = CAMERA_DEFAULT_SETTING_FLASH;
    g_camera_cntx.setting.led_highlight = CAMERA_DEFAULT_SETTING_LED_HIGHLIGHT;
#ifdef __CAMERA_FEATURE_SHUTTER_SOUND__
    g_camera_cntx.setting.shutter_sound = CAMERA_DEFAULT_SETTING_SHUTTER_SOUND;
#endif    
    g_camera_cntx.setting.ev = CAMERA_DEFAULT_SETTING_EV;
    g_camera_cntx.setting.night = CAMERA_DEFAULT_SETTING_NIGHT;
    g_camera_cntx.setting.closeup = CAMERA_DEFAULT_SETTING_CLOSEUP;
    g_camera_cntx.setting.banding = CAMERA_DEFAULT_SETTING_BANDING;
    g_camera_cntx.setting.image_size = CAMERA_DEFAULT_SETTING_IMAGE_SIZE;
    g_camera_cntx.setting.image_qty = CAMERA_DEFAULT_SETTING_IMAGE_QTY;
    g_camera_cntx.setting.contrast = CAMERA_DEFAULT_SETTING_CONTRAST;
    
    g_camera_cntx.setting.zoom_idx = CAMERA_DEFAULT_SETTING_ZOOM_IDX;
    g_camera_cntx.setting.effect = CAMERA_DEFAULT_SETTING_EFFECT;
    g_camera_cntx.setting.add_frame = CAMERA_DEFAULT_SETTING_ADD_FRAME;
    g_camera_cntx.setting.add_frame_tileshot = CAMERA_DEFAULT_SETTING_ADD_FRAME;
    g_camera_cntx.setting.add_frame_color_idx = CAMERA_DEFAULT_SETTING_ADD_FRAME;
    g_camera_cntx.setting.cont_shot = CAMERA_DEFAULT_SETTING_CONT_SHOT;
    g_camera_cntx.contshot_backup = g_camera_cntx.setting.cont_shot;
    g_camera_cntx.setting.delay_timer = CAMERA_DEFAULT_SETTING_DELAY_TIMER;
    
    g_camera_cntx.setting.iso = CAMERA_DEFAULT_SETTING_ISO;
    g_camera_cntx.setting.ae_meter = CAMERA_DEFAULT_SETTING_AE_METER;
    g_camera_cntx.setting.af_meter = CAMERA_DEFAULT_SETTING_AUTOFOCUS;
    g_camera_cntx.setting.af_mode = 0;
    g_camera_cntx.setting.dsc_mode = CAMERA_DEFAULT_SETTING_DSC_MODE;
    
    g_camera_cntx.setting.fx_brightness[0] = CAMERA_DEFAULT_SETTING_BRIGHTNESS;
    g_camera_cntx.setting.fx_brightness[1] = CAMERA_DEFAULT_SETTING_BRIGHTNESS;
    g_camera_cntx.setting.fx_brightness[2] = CAMERA_DEFAULT_SETTING_BRIGHTNESS;
    g_camera_cntx.setting.fx_saturation[0] = CAMERA_DEFAULT_SETTING_SATURATION;
    g_camera_cntx.setting.fx_saturation[1] = CAMERA_DEFAULT_SETTING_SATURATION;
    g_camera_cntx.setting.fx_saturation[2] = CAMERA_DEFAULT_SETTING_SATURATION;
    g_camera_cntx.setting.fx_contrast[0] = CAMERA_DEFAULT_SETTING_CONTRAST;
    g_camera_cntx.setting.fx_contrast[1] = CAMERA_DEFAULT_SETTING_CONTRAST;
    g_camera_cntx.setting.fx_contrast[2] = CAMERA_DEFAULT_SETTING_CONTRAST;
    g_camera_cntx.setting.fx_hue[0] = CAMERA_DEFAULT_SETTING_HUE;
    g_camera_cntx.setting.fx_hue[1] = CAMERA_DEFAULT_SETTING_HUE;
    g_camera_cntx.setting.fx_hue[2] = CAMERA_DEFAULT_SETTING_HUE;
    
    g_camera_cntx.is_hide_osd = FALSE;
    
#if defined(__CAMERA_OSD_HORIZONTAL__)
    if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270)
    {
        g_camera_cntx.osd_rotate = CAMERA_DISPLAY_ROTATE_0;
        g_camera_cntx.previous_osd_rotate = CAMERA_DISPLAY_ROTATE_RESET;
    }
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
    
#ifdef __CAMERA_FEATURE_XENON_FLASH__
    g_camera_cntx.setting.flash = CAMERA_SETTING_FLASH_OFF;
    g_camera_cntx.xenon_flash_state = MMI_CAMERA_XENON_FLASH_OFF;    
#endif
    
#if defined(__MMI_OP12_CAMERA_VDOREC_CUSTOMIZE__)
    mmi_camera_change_to_largest_img_size();
#if defined(__CAMERA_OSD_HORIZONTAL__)
    g_camera_cntx.previous_osd_rotate = CAMERA_DISPLAY_ROTATE_RESET;
    g_camera_cntx.osd_rotate = CAMERA_DISPLAY_ROTATE_270;
    g_camera_cntx.capture_path = CAPTURE_FROM_MEMORY;
    g_camera_cntx.img_size_backup = g_camera_cntx.setting.image_size;
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST__) */ 
#endif
    
    mmi_camera_preview_update_capture_size();
    
    mmi_camera_store_setting();
}

/*****************************************************************************
* FUNCTION
*  mmi_camera_restore_filename_seq_no
* DESCRIPTION
*  restore seq no when capture fail
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_restore_filename_seq_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S16 error = 0;
    //U16 filename_seq_no;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ReadValue(NVRAM_CAM_FILENAME_SEQ_NO, &filename_seq_no, DS_SHORT, &error);
    
    //if (g_camera_cntx.filename_seq_no == 1)
    //    g_camera_cntx.filename_seq_no = 9999;
    //else 
    //    g_camera_cntx.filename_seq_no--;
    
    //WriteValue(NVRAM_CAM_FILENAME_SEQ_NO, &filename_seq_no, DS_SHORT, &error);
}

static void mmi_camera_commit_filename_seq_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S16 error = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.is_filename_committed = TRUE;
}

/*****************************************************************************
* FUNCTION
*  mmi_camera_get_next_filename
* DESCRIPTION
*  get next file name for jpeg image
* PARAMETERS
*  file_buf_p      [IN]        
*  a(?)            [OUT]       Next filename
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_get_next_filename(PS8 file_buf_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_CAMERA_RECORDER_ONE_KEY_TOGGLE__)
    S8 buffer[25];
    S8 UCS2_buffer[50];
    S8 UCS2_testname[50];
    S8 UCS2_alpha[10];
    U16 filename_seq_no;
    U16 alpha_count;
    U16 alpha_index;
    FS_HANDLE file_handle;
    U16 file_check = 0;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CAMERA_RECORDER_ONE_KEY_TOGGLE__
    mdi_get_ucs2_filename(file_buf_p,FMGR_MAX_PATH_LEN,g_camera_cntx.storage_filepath,MDI_NAMING_TYPE_DDMMYY_HHMM,FMGR_TYPE_JPG);
#else
    /* get/store sequentail number */
    //ReadValue(NVRAM_CAM_FILENAME_SEQ_NO, &filename_seq_no, DS_SHORT, &error);
    filename_seq_no = g_camera_cntx.filename_seq_no;
    
    if (filename_seq_no == 0xffff)
    {
        filename_seq_no = 1;    /* init value */
    }
    else
    {
        if (g_camera_cntx.is_filename_committed == TRUE)
            filename_seq_no++;
        
        g_camera_cntx.is_filename_committed = FALSE;
        
        if (filename_seq_no > 9999) /* more than 4 digits */
        {
            filename_seq_no = 1;
        }
    }
    
    alpha_count = 'Z' - 'A' + 1;
    alpha_index = 0;
    
    sprintf((PS8) buffer, "IMG%04d", filename_seq_no);
    mmi_asc_to_ucs2((PS8) UCS2_buffer, (PS8) buffer);
    
    while (1)
    {
        sprintf((PS8) buffer, "%c", 'A' + alpha_index);
        mmi_asc_to_ucs2((PS8) UCS2_alpha, (PS8) buffer);
        
        mmi_ucs2cpy(UCS2_testname, UCS2_buffer);
        mmi_ucs2cat(UCS2_testname, UCS2_alpha);
        mmi_ucs2cat(UCS2_testname, (PS8) L".jpg");
        
        mmi_ucs2cpy((PS8) file_buf_p, (PS8) g_camera_cntx.storage_filepath);
        mmi_ucs2cat((PS8) file_buf_p, (PS8) UCS2_testname);
        
        file_handle = FS_Open((U16*) file_buf_p, FS_READ_ONLY);
        
        if (file_handle >= 0)
        {
            /* file exist */
            FS_Close(file_handle);
            alpha_index++;
        }
        else
        {
            /* file not exit. return */
            g_camera_cntx.filename_seq_no = filename_seq_no;
            //WriteValue(NVRAM_CAM_FILENAME_SEQ_NO, &filename_seq_no, DS_SHORT, &error);
            return;
        }
        
        /* exit condition - will get a IMGXXXXZ.jpg as file name */
        if (alpha_index >= alpha_count )
        {
            alpha_count = 'Z' - 'A' + 1;
            alpha_index = 0;
            filename_seq_no++;
            file_check++;
            if (filename_seq_no > 9999) /* more than 4 digits */
            {
                filename_seq_no = 1;
            }
            sprintf((PS8) buffer, "IMG%04d", filename_seq_no);
            mmi_asc_to_ucs2((PS8) UCS2_buffer, (PS8) buffer);
            
            /* check if number of files are > 9999 * 26*/
            if (file_check >= 9999)
                return;
        }
    }
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_display_error_popup
* DESCRIPTION
*  display a popup error message
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_display_error_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID_TYPE string_id = 0;
    mmi_event_notify_enum event_id = 0;
    U32 ticks;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if has error */
    if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
    {
        /* wait a short while, let sound finish play, aviod sound cover with popup sound */
        kal_get_time(&ticks);
        while (ticks - g_camera_cntx.multi_sound_tick < 100 || g_camera_cntx.multi_sound_tick - ticks < 100)
        {
            kal_get_time(&ticks);
        }
        ClearInputEventHandler(MMI_DEVICE_KEY);
        
        /* temperary solution for MT6225 hot sensor key */
        if (CAMERA_CAPTURE_EXTRA_KEY2 != -1)
        {
            SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_REPEAT);
            SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_LONG_PRESS);
        }        
        
        string_id = mmi_camera_get_error_string_by_error_enum((S32)g_camera_cntx.last_error);
        event_id = mmi_camera_get_error_type_by_error_enum((S32)g_camera_cntx.last_error);
        
        MMI_CAMERA_DISPLAY_POPUP(GetString(string_id), event_id);
        
        if ((g_camera_cntx.last_error == CAMERA_ERR_PHONE_DISK_FULL)
            || (g_camera_cntx.last_error == CAMERA_ERR_CARD_DISK_FULL)
            || (g_camera_cntx.last_error == CAMERA_ERR_CORRUPT_FAT)
            || (g_camera_cntx.last_error == CAMERA_ERR_ROOT_DIR_FULL)
            || (g_camera_cntx.last_error == MDI_RES_CAMERA_ERR_NO_DISK))
        {
        /* if there is only phone storage, we will delete camera screen,
            else we will popup select storage screen for user */
#if defined(__CAMERA_FEATURE_STORAGE__)
            return;
#else
            mmi_imgview_set_storage_ready();
            DeleteNHistory(1);                
#endif
        }
        else if (g_camera_cntx.last_error == MDI_RES_CAMERA_ERR_HW_NOT_READY)
        {
            DeleteNHistory(1);
        }
        g_camera_cntx.last_error = MDI_RES_CAMERA_SUCCEED;
        /* for External Request */
        if (g_camera_cntx.external_request_mode != MMI_CAMERA_EXTERNAL_MODE_OFF)
        {
            g_camera_cntx.callback_ptr(MMI_FALSE,NULL);
            return;
        }       
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_get_error_string_by_error_enum
* DESCRIPTION
*  Get error string by error code.
* PARAMETERS
*  err_code
* RETURNS
*  error string id
*****************************************************************************/
mmi_event_notify_enum mmi_camera_get_error_type_by_error_enum(S32 err_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_notify_enum event_id = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    switch (err_code)
    {
    default:
        event_id = MMI_EVENT_FAILURE;
        break;
    }
    
    return event_id;
    
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_get_error_string_by_error_enum
* DESCRIPTION
*  Get error string by error code.
* PARAMETERS
*  err_code
* RETURNS
*  error string id
*****************************************************************************/
MMI_ID_TYPE mmi_camera_get_error_string_by_error_enum(S32 err_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID_TYPE string_id = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    switch (err_code)
    {
    case CAMERA_ERR_BEARER_IS_ACTIVE:
        string_id = STR_ID_CAMERA_NOTIFY_BEARER_IS_ACTIVE;
        break;
    case CAMERA_ERR_BT_IS_WORKING:
        string_id = STR_ID_CAMERA_NOTIFY_BT_IS_WORKING;
        break;
    case MDI_RES_CAMERA_ERR_DISK_FULL:
        string_id = FMGR_FS_DISK_FULL_TEXT;
        break;
    case MDI_RES_CAMERA_ERR_NO_DISK:
        string_id = STR_ID_CAMERA_NOTIFY_NO_MEMORY_CARD;
        break;
    case MDI_RES_CAMERA_ERR_WRITE_PROTECTION:
        string_id = STR_ID_CAMERA_NOTIFY_WRITE_PROTECTION;
        break;
    case MDI_RES_CAMERA_ERR_CAPTURE_FAILED:
        string_id = STR_ID_CAMERA_NOTIFY_CAPTURE_FAILED;
        break;
    case CAMERA_ERR_CARD_DISK_FULL:
        string_id = FMGR_FS_DISK_FULL_TEXT;
        break;
    case CAMERA_ERR_ROOT_DIR_FULL:
        string_id = FMGR_FS_ROOT_DIR_FULL_TEXT;
        break;
    case CAMERA_ERR_WRITE_PROTECT:
        string_id = FMGR_FS_WRITE_PROTECTION_TEXT;
        break;
    case MDI_RES_CAMERA_ERR_HW_NOT_READY:
        string_id = STR_ID_CAMERA_NOTIFY_HW_NOT_READY;
        break;
    case CAMERA_ERR_CORRUPT_FAT:
        string_id = FMGR_FS_FAT_ALLOC_ERROR_TEXT;
        break;
    case CAMERA_ERR_PHONE_DISK_FULL:
        /* phone disk full, cant create "Photos" folder */
        string_id = FMGR_FS_DISK_FULL_TEXT;
        break;
    case CAMERA_ERR_SAVE_FAIL:
        string_id = STR_ID_CAMERA_NOTIFY_SAVING_FAIL;
        break;
    case MDI_RES_CAMERA_ERR_XENONFLASH_TIMEOUT:
        string_id = STR_ID_CAMERA_NOTIFY_XENON_TIMEOUT;
        break;
    case MDI_RES_CAMERA_ERR_XENONFLASH_LOW_BATTERY:
        string_id = STR_ID_CAMERA_NOTIFY_XENON_LOW_BATTERY;
        break;
    default:
        string_id = STR_ID_CAMERA_NOTIFY_ERROR;
        break;
    }
    
    return string_id;
    
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_display_sublcd_error_popup
* DESCRIPTION
*  display a popup error message
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_display_sublcd_error_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_gpio_detect_ind_struct clam_event;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if has error */
    if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
    {
        ClearInputEventHandler(MMI_DEVICE_KEY);
        switch (g_camera_cntx.last_error)
        {
            /* these are recoverable errors */
            /* show on sublcd screen and keep previewing */
        case MDI_RES_CAMERA_ERR_DISK_FULL:
        case MDI_RES_CAMERA_ERR_NO_DISK:
        case MDI_RES_CAMERA_ERR_WRITE_PROTECTION:
        case MDI_RES_CAMERA_ERR_CAPTURE_FAILED:
        case CAMERA_ERR_SAVE_FAIL:
            /* play warning tone and re-entry preview state */
            playRequestedTone(ERROR_TONE);
            CAMERA_ENTER_STATE(CAMERA_STATE_SUB_PREVIEW);
            break;
            
        default:
            /* serious error, will exit camera app */
            GoBackHistory();
            
            /* 
            * since clam close if aready intercept by camera app,
            * we shall notify framework (gpio.c) to process clam close action 
            */
            if (g_camera_cntx.is_clam_close)
            {
                clam_event.gpio_device = EXT_DEV_CLAM_CLOSE;
                GpioDetectInd(&clam_event);
            }
            
            break;
        }
    }
    
}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_dummy_func
* DESCRIPTION
*  dummy function
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_dummy_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* empty function */
}

/****************************************************************************
*
*  Camera App                                                   
*
****************************************************************************/
/*****************************************************************************
* FUNCTION
*  mmi_camera_blt
* DESCRIPTION
*  blt api.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_camera_blt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*@ Add by Vincent */
#if defined(__CAMERA_OSD_HORIZONTAL__)
    gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_height - 1, g_camera_cntx.base_UI_device_width - 1);
#else
    gdi_layer_blt_previous(0, 0, g_camera_cntx.base_UI_device_width - 1, g_camera_cntx.base_UI_device_height - 1);
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_hilight_app
* DESCRIPTION
*  app menu item hilight hdlr
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_camera_hilight_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_camera_entry_app_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_camera_entry_app_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_get_img_size_img_id
* DESCRIPTION
*  get image string id based on customization
* PARAMETERS
*  image_width         [IN]        Capture image width
*  image_height        [IN]        Capture image height
* RETURNS
*  void
*****************************************************************************/
static U16 mmi_camera_get_img_size_img_id(S32 image_width, S32 image_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (image_width == 2048 && image_height == 1536)
    {
        return IMG_ID_CAMERA_IMAGE_SIZE_2048x1536;
    }
    else if (image_width == 1600 && image_height == 1200)
    {
        return IMG_ID_CAMERA_IMAGE_SIZE_1600x1200;
    }
    else if (image_width == 1200 && image_height == 900)
    {
        return IMG_ID_CAMERA_IMAGE_SIZE_1200x900;
    }
    else if (image_width == 1280 && image_height == 1024)
    {
        return IMG_ID_CAMERA_IMAGE_SIZE_1280x1024;
    }
    else if (image_width == 1280 && image_height == 960)
    {
        return IMG_ID_CAMERA_IMAGE_SIZE_1280x960;
    }
    else if (image_width == 800 && image_height == 600)
    {
        return IMG_ID_CAMERA_IMAGE_SIZE_800x600;
    }
    else if (image_width == 640 && image_height == 480)
    {
        return IMG_ID_CAMERA_IMAGE_SIZE_640x480;
    }
    else if (image_width == 320 && image_height == 240)
    {
        return IMG_ID_CAMERA_IMAGE_SIZE_320x240;
    }
    else if (image_width == 160 && image_height == 120)
    {
        return IMG_ID_CAMERA_IMAGE_SIZE_160x120;
    }
    else if (image_width == 80 && image_height == 60)
    {
        return IMG_ID_CAMERA_IMAGE_SIZE_80x60;
    }
    else if (image_width == 80 && image_height == 56)
    {
        return IMG_ID_CAMERA_IMAGE_SIZE_80x56;
    }
    else if (image_width == 240 && image_height == 320)
    {
        return IMG_ID_CAMERA_IMAGE_SIZE_240x320;
    }
    else if (image_width == 240 && image_height == 400)
    {
        return IMG_ID_CAMERA_IMAGE_SIZE_240x400;
    }
    else if ((image_width == 176 && image_height == 220) || (image_width == 220 && image_height == 176))
    {
        return IMG_ID_CAMERA_IMAGE_SIZE_176x220;
    }
    else if (image_width == 128 && image_height == 160)
    {
        return IMG_ID_CAMERA_IMAGE_SIZE_128x160;
    }
    else if (image_width == 128 && image_height == 128)
    {
        return IMG_ID_CAMERA_IMAGE_SIZE_128x128;
    }
    else if (image_width == 96 && image_height == 64)
    {
        return IMG_ID_CAMERA_IMAGE_SIZE_96x64;
    }
    else if (image_width == 128 && image_height == 85)
    {
        return IMG_ID_CAMERA_IMAGE_SIZE_128x85;
    }
    else if (image_width == 128 && image_height == 104)
    {
        return IMG_ID_CAMERA_IMAGE_SIZE_128x104;
    }
    else if (image_width == 352 && image_height == 288)
    {
        return IMG_ID_CAMERA_IMAGE_SIZE_352x288;
    }
    else if (image_width == 176 && image_height == 144)
    {
        return IMG_ID_CAMERA_IMAGE_SIZE_176x144;
    }
    else if (image_width == 128 && image_height == 96)
    {
        return IMG_ID_CAMERA_IMAGE_SIZE_128x96;
    }
    else if (image_width == 240 && image_height == 196)
    {
        return IMG_ID_CAMERA_IMAGE_SIZE_240x196;
    }
    else if (image_width == 240 && image_height == 288)
    {
        return IMG_ID_CAMERA_IMAGE_SIZE_240x288;
    }
    else
    {
        return IMG_ID_CAMERA_IMAGE_SIZE_UNDEFINE;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_get_img_size_str_id
* DESCRIPTION
*  get image string id based on customization
* PARAMETERS
*  image_width         [IN]        Capture image width
*  image_height        [IN]        Capture image height
* RETURNS
*  void
*****************************************************************************/
static U16 mmi_camera_get_img_size_str_id(S32 image_width, S32 image_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (image_width == 2048 && image_height == 1536)
    {
        return STR_ID_CAMERA_IMAGE_SIZE_2048x1536;
    }
    else if (image_width == 1600 && image_height == 1200)
    {
        return STR_ID_CAMERA_IMAGE_SIZE_1600x1200;
    }
    else if (image_width == 1200 && image_height == 900)
    {
        return STR_ID_CAMERA_IMAGE_SIZE_1200x900;
    }
    else if (image_width == 1280 && image_height == 1024)
    {
        return STR_ID_CAMERA_IMAGE_SIZE_1280x1024;
    }
    else if (image_width == 1280 && image_height == 960)
    {
        return STR_ID_CAMERA_IMAGE_SIZE_1280x960;
    }
    else if (image_width == 800 && image_height == 600)
    {
        return STR_ID_CAMERA_IMAGE_SIZE_800x600;
    }
    else if (image_width == 640 && image_height == 480)
    {
        return STR_ID_CAMERA_IMAGE_SIZE_640x480;
    }
    else if (image_width == 320 && image_height == 240)
    {
        return STR_ID_CAMERA_IMAGE_SIZE_320x240;
    }
    else if (image_width == 160 && image_height == 120)
    {
        return STR_ID_CAMERA_IMAGE_SIZE_160x120;
    }
    else if (image_width == 80 && image_height == 60)
    {
        return STR_ID_CAMERA_IMAGE_SIZE_80x60;
    }
    else if (image_width == 80 && image_height == 56)
    {
        return STR_ID_CAMERA_IMAGE_SIZE_80x56;
    }
    else if (image_width == 240 && image_height == 320)
    {
        return STR_ID_CAMERA_IMAGE_SIZE_240x320;
    }
    else if (image_width == 240 && image_height == 400)
    {
        return STR_ID_CAMERA_IMAGE_SIZE_240x400;
    }
    else if (image_width == 176 && image_height == 220)
    {
        return STR_ID_CAMERA_IMAGE_SIZE_176x220;
    }
    else if (image_width == 128 && image_height == 160)
    {
        return STR_ID_CAMERA_IMAGE_SIZE_128x160;
    }
    else if (image_width == 128 && image_height == 128)
    {
        return STR_ID_CAMERA_IMAGE_SIZE_128x128;
    }
    else if (image_width == 128 && image_height == 104)
    {
        return STR_ID_CAMERA_IMAGE_SIZE_128x104;
    }
    else if (image_width == 96 && image_height == 64)
    {
        return STR_ID_CAMERA_IMAGE_SIZE_96x64;
    }
    else if (image_width == 128 && image_height == 85)
    {
        return STR_ID_CAMERA_IMAGE_SIZE_128x85;
    }
    else if (image_width == 352 && image_height == 288)
    {
        return STR_ID_CAMERA_IMAGE_SIZE_352x288;
    }
    else if (image_width == 176 && image_height == 144)
    {
        return STR_ID_CAMERA_IMAGE_SIZE_176x144;
    }
    else if (image_width == 128 && image_height == 96)
    {
        return STR_ID_CAMERA_IMAGE_SIZE_128x96;
    }
    else if (image_width == 240 && image_height == 196)
    {
        return STR_ID_CAMERA_IMAGE_SIZE_240x196;
    }
    else if (image_width == 240 && image_height == 288)
    {
        return STR_ID_CAMERA_IMAGE_SIZE_240x288;
    }
    else
    {
        return STR_ID_CAMERA_IMAGE_SIZE_UNDEFINE;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_update_osd_touch_icon
* DESCRIPTION
*  update osd touch icons' positions
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_update_osd_touch_icon()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CAMERA_FEATURE_TOUCH_CLICKICON__
#define INIT_OSD_TOUCH_ICON(a,A)                                                               \
    do {                                                                                           \
    if(g_camera_cntx.active_camera_osd_ptr->##a##.is_show)                                      \
    {                                                                                           \
    gdi_image_get_dimension_id((U16)(IMG_ID_CAMERA_OSD_##A##_START+1),                       \
    &g_camera_cntx.touch_##a##.width,                             \
    &g_camera_cntx.touch_##a##.height);                           \
    g_camera_cntx.touch_##a##.offset_x = g_camera_cntx.active_camera_osd_ptr->##a##.offset_x;\
    g_camera_cntx.touch_##a##.offset_y = g_camera_cntx.active_camera_osd_ptr->##a##.offset_y;\
    g_camera_cntx.touch_##a##.is_press = FALSE;                                              \
}                                                                                           \
    } while(0);
#else /* __CAMERA_FEATURE_TOUCH_CLICKICON__ */ 
    
    /* 
    * if touch screen is enable, but do not want to enable icon click, 
    * set icon offset to -1 and size to 0 
    */
#define INIT_OSD_TOUCH_ICON(a,A)                         \
    do {                                                     \
    if(g_camera_cntx.active_camera_osd_ptr->##a##.is_show)\
    {                                                     \
    g_camera_cntx.touch_##a##.width     = 0;           \
    g_camera_cntx.touch_##a##.height    = 0;           \
    g_camera_cntx.touch_##a##.offset_x  = -1;          \
    g_camera_cntx.touch_##a##.offset_y  = -1;          \
    g_camera_cntx.touch_##a##.is_press  = FALSE;       \
}                                                     \
    } while(0);
#endif /* __CAMERA_FEATURE_TOUCH_CLICKICON__ */ 
    
    /* draw icon */
    INIT_OSD_TOUCH_ICON(effect, EFFECT);
    INIT_OSD_TOUCH_ICON(wb, WB);
    INIT_OSD_TOUCH_ICON(flash, FLASH);
    INIT_OSD_TOUCH_ICON(led_highlight, LED_HIGHLIGHT);
    INIT_OSD_TOUCH_ICON(night, NIGHT);
    if (g_camera_cntx.active_camera_osd_ptr->image_size.is_show)
    {
        gdi_image_get_dimension_id(
            (U16) (IMG_ID_CAMERA_IMAGE_SIZE_320x240),
            &g_camera_cntx.touch_image_size.width,
            &g_camera_cntx.touch_image_size.height);
        g_camera_cntx.touch_image_size.offset_x = g_camera_cntx.active_camera_osd_ptr->image_size.offset_x;
        g_camera_cntx.touch_image_size.offset_y = g_camera_cntx.active_camera_osd_ptr->image_size.offset_y;
        g_camera_cntx.touch_image_size.is_press = FALSE;
    }
    
    INIT_OSD_TOUCH_ICON(image_qty, IMAGE_QTY);
    INIT_OSD_TOUCH_ICON(cont_shot, CONT_SHOT);
    INIT_OSD_TOUCH_ICON(delay_timer, DELAY_TIMER);
    INIT_OSD_TOUCH_ICON(dsc_mode, DSC_MODE);
    INIT_OSD_TOUCH_ICON(af_mode, FOCUS_MODE);
    INIT_OSD_TOUCH_ICON(af_meter, FOCUS_METER);
    if (g_camera_cntx.active_camera_osd_ptr->zoom_mf_toggle.is_show)
    {
        gdi_image_get_dimension_id(
            (U16) (IMG_ID_CAMERA_OSD_ZOOM_MF_TOGGLE),
            &g_camera_cntx.touch_zoom_mf_toggle.width,
            &g_camera_cntx.touch_zoom_mf_toggle.height);
        g_camera_cntx.touch_zoom_mf_toggle.offset_x = g_camera_cntx.active_camera_osd_ptr->zoom_mf_toggle.offset_x;
        g_camera_cntx.touch_zoom_mf_toggle.offset_y = g_camera_cntx.active_camera_osd_ptr->zoom_mf_toggle.offset_y;
        g_camera_cntx.touch_zoom_mf_toggle.is_press = FALSE;
    }
    INIT_OSD_TOUCH_ICON(iso, ISO);
    INIT_OSD_TOUCH_ICON(ae_meter, AE_METER);
    INIT_OSD_TOUCH_ICON(storage, STORAGE);
    
    /* ev inc */
    gdi_image_get_dimension_id(
        (U16) (IMG_ID_CAMERA_OSD_EV_INC),
        &g_camera_cntx.touch_ev_inc.width,
        &g_camera_cntx.touch_ev_inc.height);
    
    g_camera_cntx.touch_ev_inc.offset_x = g_camera_cntx.active_camera_osd_ptr->ev_inc.offset_x;
    g_camera_cntx.touch_ev_inc.offset_y = g_camera_cntx.active_camera_osd_ptr->ev_inc.offset_y;
    g_camera_cntx.touch_ev_inc.is_press = FALSE;
    
    /* ev dec */
    gdi_image_get_dimension_id(
        (U16) (IMG_ID_CAMERA_OSD_EV_DEC),
        &g_camera_cntx.touch_ev_dec.width,
        &g_camera_cntx.touch_ev_dec.height);
    
    g_camera_cntx.touch_ev_dec.offset_x = g_camera_cntx.active_camera_osd_ptr->ev_dec.offset_x;
    g_camera_cntx.touch_ev_dec.offset_y = g_camera_cntx.active_camera_osd_ptr->ev_dec.offset_y;
    g_camera_cntx.touch_ev_dec.is_press = FALSE;
    
    /* zoom inc */
    gdi_image_get_dimension_id(
        (U16) (IMG_ID_CAMERA_OSD_ZOOM_INC),
        &g_camera_cntx.touch_zoom_inc.width,
        &g_camera_cntx.touch_zoom_inc.height);
    
    g_camera_cntx.touch_zoom_inc.offset_x = g_camera_cntx.active_camera_osd_ptr->zoom_inc.offset_x;
    g_camera_cntx.touch_zoom_inc.offset_y = g_camera_cntx.active_camera_osd_ptr->zoom_inc.offset_y;
    g_camera_cntx.touch_zoom_inc.is_press = FALSE;
    
    /* zoom dec */
    gdi_image_get_dimension_id(
        (U16) (IMG_ID_CAMERA_OSD_ZOOM_DEC),
        &g_camera_cntx.touch_zoom_dec.width,
        &g_camera_cntx.touch_zoom_dec.height);
    
    g_camera_cntx.touch_zoom_dec.offset_x = g_camera_cntx.active_camera_osd_ptr->zoom_dec.offset_x;
    g_camera_cntx.touch_zoom_dec.offset_y = g_camera_cntx.active_camera_osd_ptr->zoom_dec.offset_y;
    g_camera_cntx.touch_zoom_dec.is_press = FALSE;
    
    /* capture */
    gdi_image_get_dimension_id(
        (U16) (IMG_ID_CAMERA_OSD_CAPTURE),
        &g_camera_cntx.touch_capture.width,
        &g_camera_cntx.touch_capture.height);
    
    g_camera_cntx.touch_capture.offset_x = g_camera_cntx.active_camera_osd_ptr->capture.offset_x;
    g_camera_cntx.touch_capture.offset_y = g_camera_cntx.active_camera_osd_ptr->capture.offset_y;
    g_camera_cntx.touch_capture.is_press = FALSE;
    
#if defined(__MMI_CAMERA_FORWARD_SUPPORT__) && defined(__MMI_OP11_CAMERA_VDOREC_CUSTOMIZE__)
    gdi_image_get_dimension_id(
        (U16) (IMG_ID_CAMERA_FORWARD_TO_MMS),
        &g_camera_cntx.touch_mms_icon.width,
        &g_camera_cntx.touch_mms_icon.height);
    g_camera_cntx.touch_mms_icon.offset_x = g_camera_cntx.active_camera_osd_ptr->mms_icon.offset_x;
    g_camera_cntx.touch_mms_icon.offset_y = g_camera_cntx.active_camera_osd_ptr->mms_icon.offset_y;
    g_camera_cntx.touch_mms_icon.is_press = FALSE;
#endif /* defined(__MMI_CAMERA_FORWARD_SUPPORT__) */ 
    
#undef INIT_OSD_TOUCH_ICON
    
}


#if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
/*****************************************************************************
* FUNCTION
*  mmi_camera_create_osd_layer
* DESCRIPTION
*  create main lcd's preview layer resource
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_create_osd_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 buf_size, width, height, offset_x, offset_y, buffer_size_total;
    camera_osd_layeout_struct *active_camera_osd_ptr;
    
#if defined(__CAMERA_OSD_HORIZONTAL__)
    camera_osd_layeout_struct *active_camera_osd_ptr_270;
#endif 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__CAMERA_OSD_HORIZONTAL__)
#define CREATE_OSD_LAYER(__a__, __A__,__L__)                                                 \
    do {                                                                                         \
    if(active_camera_osd_ptr->##__a__##.width*active_camera_osd_ptr->##__a__##.height >       \
    active_camera_osd_ptr_270->##__a__##.width*active_camera_osd_ptr_270->##__a__##.height)\
    {                                                                                         \
    width = active_camera_osd_ptr->##__a__##.width;                                        \
    height = active_camera_osd_ptr->##__a__##.height;                                      \
    offset_x = active_camera_osd_ptr->##__a__##.offset_x;                                  \
    offset_y = active_camera_osd_ptr->##__a__##.offset_y;                                  \
    }                                                                                         \
    else                                                                                      \
    {                                                                                         \
    width = active_camera_osd_ptr_270->##__a__##.width;                                    \
    height = active_camera_osd_ptr_270->##__a__##.height;                                  \
    offset_x = active_camera_osd_ptr_270->##__a__##.offset_x;                              \
    offset_y = active_camera_osd_ptr_270->##__a__##.offset_y;                              \
    }                                                                                         \
    buf_size = (((width*height*GDI_MAINLCD_BIT_PER_PIXEL)>>3));                             \
    g_camera_cntx.##__A__##= mmi_frm_scrmem_alloc_framebuffer(buf_size);                                  \
    ASSERT(g_camera_cntx.##__A__##!=NULL);                                                    \
    gdi_layer_create_cf_double_using_outside_memory(                                    \
    GDI_COLOR_FORMAT_16,                         \
    offset_x,                                    \
    offset_y,                                    \
    width,                                       \
    height,                                      \
    &g_camera_cntx.##__L__##,                    \
    (PU8)g_camera_cntx.##__A__##,                \
    (S32)buf_size,                              \
    (PU8)(g_camera_cntx.gdi_layer_buffer_ptr + buffer_size_total),  \
    (S32)buf_size);                              \
    gdi_layer_push_and_set_active(g_camera_cntx.##__L__##);                                   \
    buffer_size_total += buf_size;                                                 \
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);                                        \
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);                                    \
    gdi_layer_pop_and_restore_active();                                                       \
    } while(0);
#else /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
#define CREATE_OSD_LAYER(__a__, __A__,__L__)                                 \
    do {                                                                         \
    width = active_camera_osd_ptr->##__a__##.width;                           \
    height = active_camera_osd_ptr->##__a__##.height;                         \
    offset_x = active_camera_osd_ptr->##__a__##.offset_x;                     \
    offset_y = active_camera_osd_ptr->##__a__##.offset_y;                     \
    buf_size = (((width*height*GDI_MAINLCD_BIT_PER_PIXEL)>>3));             \
    g_camera_cntx.##__A__##= mmi_frm_scrmem_alloc_framebuffer(buf_size);                  \
    ASSERT(g_camera_cntx.##__A__##!=NULL);                                    \
    gdi_layer_create_cf_double_using_outside_memory(                               \
    GDI_COLOR_FORMAT_16,                         \
    offset_x,                    \
    offset_y,                    \
    width,                       \
    height,                      \
    &g_camera_cntx.##__L__##,    \
    (PU8)g_camera_cntx.##__A__##,\
    (S32)buf_size,                              \
    (PU8)(g_camera_cntx.gdi_layer_buffer_ptr + buffer_size_total),  \
    (S32) buf_size);                                                \
    gdi_layer_push_and_set_active(g_camera_cntx.##__L__##);                   \
    buffer_size_total += buf_size;                                   \
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);                        \
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);                    \
    gdi_layer_pop_and_restore_active();                                       \
    } while(0);
    
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
    if (g_camera_cntx.is_single_osd_layer)
    {
        g_camera_cntx.osd_layer_buf_ptr0 = mmi_frm_scrmem_alloc_framebuffer(CAMERA_OSD_BUFFER_SIZE);
        ASSERT(g_camera_cntx.osd_layer_buf_ptr0 != NULL);
        
        /*gdi_layer_create_double_using_outside_memory(
            0,
            0,
            LCD_WIDTH,
            LCD_HEIGHT,
            &g_camera_cntx.osd_layer_handle0,
            (PU8) g_camera_cntx.osd_layer_buf_ptr0,
            (S32) (CAMERA_OSD_BUFFER_SIZE));*/
        
        gdi_layer_create_cf_double_using_outside_memory(
            GDI_COLOR_FORMAT_16,
            0,
            0,
            LCD_WIDTH,
            LCD_HEIGHT,
            &g_camera_cntx.osd_layer_handle0,
            (PU8) g_camera_cntx.osd_layer_buf_ptr0,
            (S32) (CAMERA_OSD_BUFFER_SIZE),
            (PU8) g_camera_cntx.gdi_layer_buffer_ptr, 
            (S32) (CAMERA_OSD_BUFFER_SIZE));

        gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle0);
        gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();
    }
    else
    {
        /*@ Add by Vincent */
#if defined(__MDI_CAMERA_HW_ROTATOR_SUPPORT__) && defined(__CAMERA_OSD_HORIZONTAL__)
        ASSERT(0); /* Should not reach here ! */
#endif
        buffer_size_total = 0;

        active_camera_osd_ptr = &g_camera_osd_cntx;
#if defined(__CAMERA_OSD_HORIZONTAL__)
        active_camera_osd_ptr_270 = &g_camera_osd_cntx_270;
#endif 
        /* layer 0 */
        CREATE_OSD_LAYER(osd_region0, osd_layer_buf_ptr0, osd_layer_handle0);
        /* layer 1 */
        CREATE_OSD_LAYER(osd_region1, osd_layer_buf_ptr1, osd_layer_handle1);
        /* layer 2 */
        CREATE_OSD_LAYER(osd_region2, osd_layer_buf_ptr2, osd_layer_handle2);
        
#ifdef __MMI_CAMERA_5_OSD_LAYER__
        /* layer 3 */
        CREATE_OSD_LAYER(osd_region3, osd_layer_buf_ptr3, osd_layer_handle3);
        /* layer 4 */
        CREATE_OSD_LAYER(osd_region4, osd_layer_buf_ptr4, osd_layer_handle4);
#endif        
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_free_osd_layer
* DESCRIPTION
*  free main lcd's preview layer resource
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_free_osd_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /****** free osd layer ******/
    if (g_camera_cntx.osd_layer_handle0 != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(g_camera_cntx.osd_layer_handle0);
        g_camera_cntx.osd_layer_handle0 = GDI_LAYER_EMPTY_HANDLE;
        
        mmi_frm_scrmem_free((void*)g_camera_cntx.osd_layer_buf_ptr0);
        g_camera_cntx.osd_layer_buf_ptr0 = NULL;
    }
    
    /****** free osd layer ******/
    if (g_camera_cntx.osd_layer_handle1 != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(g_camera_cntx.osd_layer_handle1);
        g_camera_cntx.osd_layer_handle1 = GDI_LAYER_EMPTY_HANDLE;
        
        mmi_frm_scrmem_free((void*)g_camera_cntx.osd_layer_buf_ptr1);
        g_camera_cntx.osd_layer_buf_ptr1 = NULL;
    }
    /****** free osd layer ******/
    if (g_camera_cntx.osd_layer_handle2 != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(g_camera_cntx.osd_layer_handle2);
        g_camera_cntx.osd_layer_handle2 = GDI_LAYER_EMPTY_HANDLE;
        
        mmi_frm_scrmem_free((void*)g_camera_cntx.osd_layer_buf_ptr2);
        g_camera_cntx.osd_layer_buf_ptr2 = NULL;
    }
#ifdef __MMI_CAMERA_5_OSD_LAYER__    
    /****** free osd layer ******/
    if (g_camera_cntx.osd_layer_handle3 != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(g_camera_cntx.osd_layer_handle3);
        g_camera_cntx.osd_layer_handle3 = GDI_LAYER_EMPTY_HANDLE;
        
        mmi_frm_scrmem_free((void*)g_camera_cntx.osd_layer_buf_ptr3);
        g_camera_cntx.osd_layer_buf_ptr3 = NULL;
    }
    /****** free osd layer ******/
    if (g_camera_cntx.osd_layer_handle4 != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(g_camera_cntx.osd_layer_handle4);
        g_camera_cntx.osd_layer_handle4 = GDI_LAYER_EMPTY_HANDLE;
        
        mmi_frm_scrmem_free((void*)g_camera_cntx.osd_layer_buf_ptr4);
        g_camera_cntx.osd_layer_buf_ptr4 = NULL;
    }
#endif    
}

/*****************************************************************************
* FUNCTION
*  mmi_camera_init_osd_icon_layer_position
* DESCRIPTION
*  update osd touch icons' positions
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_init_osd_icon_layer_position()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    camera_osd_layeout_struct *active_camera_osd_ptr;
    
    active_camera_osd_ptr = &g_camera_osd_cntx;
#if defined(__MMI_CAMERA_5_OSD_LAYER__)
#define INIT_OSD_ICON(a)                                                                                                                  \
    do {                                                                                                                                      \
    if(active_camera_osd_ptr->##a##.is_show)                                                                                               \
    {                                                                                                                                      \
    if((active_camera_osd_ptr->##a##.offset_x >= active_camera_osd_ptr->osd_region0.offset_x)&&                                         \
    (active_camera_osd_ptr->##a##.offset_y >= active_camera_osd_ptr->osd_region0.offset_y)&&                                         \
    (active_camera_osd_ptr->##a##.offset_x <= active_camera_osd_ptr->osd_region0.offset_x+active_camera_osd_ptr->osd_region0.width)&&\
    (active_camera_osd_ptr->##a##.offset_y <= active_camera_osd_ptr->osd_region0.offset_y+active_camera_osd_ptr->osd_region0.height))\
    active_camera_osd_ptr->##a##.group_id = 0;                                                                                       \
    else if((active_camera_osd_ptr->##a##.offset_x >= active_camera_osd_ptr->osd_region1.offset_x)&&                                    \
    (active_camera_osd_ptr->##a##.offset_y >= active_camera_osd_ptr->osd_region1.offset_y)&&                                         \
    (active_camera_osd_ptr->##a##.offset_x <= active_camera_osd_ptr->osd_region1.offset_x+active_camera_osd_ptr->osd_region1.width)&&\
    (active_camera_osd_ptr->##a##.offset_y <= active_camera_osd_ptr->osd_region1.offset_y+active_camera_osd_ptr->osd_region1.height))\
    active_camera_osd_ptr->##a##.group_id = 1;                                                                                       \
    else if((active_camera_osd_ptr->##a##.offset_x >= active_camera_osd_ptr->osd_region2.offset_x)&&                                    \
    (active_camera_osd_ptr->##a##.offset_y >= active_camera_osd_ptr->osd_region2.offset_y)&&                                         \
    (active_camera_osd_ptr->##a##.offset_x <= active_camera_osd_ptr->osd_region2.offset_x+active_camera_osd_ptr->osd_region2.width)&&\
    (active_camera_osd_ptr->##a##.offset_y <= active_camera_osd_ptr->osd_region2.offset_y+active_camera_osd_ptr->osd_region2.height))\
    active_camera_osd_ptr->##a##.group_id = 2;                                                                                       \
    else if((active_camera_osd_ptr->##a##.offset_x >= active_camera_osd_ptr->osd_region3.offset_x)&&                                    \
    (active_camera_osd_ptr->##a##.offset_y >= active_camera_osd_ptr->osd_region3.offset_y)&&                                         \
    (active_camera_osd_ptr->##a##.offset_x <= active_camera_osd_ptr->osd_region3.offset_x+active_camera_osd_ptr->osd_region3.width)&&\
    (active_camera_osd_ptr->##a##.offset_y <= active_camera_osd_ptr->osd_region3.offset_y+active_camera_osd_ptr->osd_region3.height))\
    active_camera_osd_ptr->##a##.group_id = 3;                                                                                       \
    else if((active_camera_osd_ptr->##a##.offset_x >= active_camera_osd_ptr->osd_region4.offset_x)&&                                    \
    (active_camera_osd_ptr->##a##.offset_y >= active_camera_osd_ptr->osd_region4.offset_y)&&                                         \
    (active_camera_osd_ptr->##a##.offset_x <= active_camera_osd_ptr->osd_region4.offset_x+active_camera_osd_ptr->osd_region4.width)&&\
    (active_camera_osd_ptr->##a##.offset_y <= active_camera_osd_ptr->osd_region4.offset_y+active_camera_osd_ptr->osd_region4.height))\
    active_camera_osd_ptr->##a##.group_id = 4;                                                                                       \
    }                                                                                                                                      \
    } while(0)
#elif defined(__MMI_CAMERA_3_OSD_LAYER__)
#define INIT_OSD_ICON(a)                                                                                                                           \
    do {                                                                                                                                      \
    if(active_camera_osd_ptr->##a##.is_show)                                                                                               \
    {                                                                                                                                      \
    if((active_camera_osd_ptr->##a##.offset_x >= active_camera_osd_ptr->osd_region0.offset_x)&&                                         \
    (active_camera_osd_ptr->##a##.offset_y >= active_camera_osd_ptr->osd_region0.offset_y)&&                                         \
    (active_camera_osd_ptr->##a##.offset_x <= active_camera_osd_ptr->osd_region0.offset_x+active_camera_osd_ptr->osd_region0.width)&&\
    (active_camera_osd_ptr->##a##.offset_y <= active_camera_osd_ptr->osd_region0.offset_y+active_camera_osd_ptr->osd_region0.height))\
    active_camera_osd_ptr->##a##.group_id = 0;                                                                                       \
    else if((active_camera_osd_ptr->##a##.offset_x >= active_camera_osd_ptr->osd_region1.offset_x)&&                                    \
    (active_camera_osd_ptr->##a##.offset_y >= active_camera_osd_ptr->osd_region1.offset_y)&&                                         \
    (active_camera_osd_ptr->##a##.offset_x <= active_camera_osd_ptr->osd_region1.offset_x+active_camera_osd_ptr->osd_region1.width)&&\
    (active_camera_osd_ptr->##a##.offset_y <= active_camera_osd_ptr->osd_region1.offset_y+active_camera_osd_ptr->osd_region1.height))\
    active_camera_osd_ptr->##a##.group_id = 1;                                                                                       \
    else if((active_camera_osd_ptr->##a##.offset_x >= active_camera_osd_ptr->osd_region2.offset_x)&&                                    \
    (active_camera_osd_ptr->##a##.offset_y >= active_camera_osd_ptr->osd_region2.offset_y)&&                                         \
    (active_camera_osd_ptr->##a##.offset_x <= active_camera_osd_ptr->osd_region2.offset_x+active_camera_osd_ptr->osd_region2.width)&&\
    (active_camera_osd_ptr->##a##.offset_y <= active_camera_osd_ptr->osd_region2.offset_y+active_camera_osd_ptr->osd_region2.height))\
    active_camera_osd_ptr->##a##.group_id = 2;                                                                                       \
    }                                                                                                                                      \
    } while(0)
#endif
    /* draw icon */
    
    INIT_OSD_ICON(effect);
    INIT_OSD_ICON(lsk);
    INIT_OSD_ICON(rsk);
    INIT_OSD_ICON(wb);
    INIT_OSD_ICON(flash);
    INIT_OSD_ICON(led_highlight);
    INIT_OSD_ICON(night);
    INIT_OSD_ICON(image_size);
    INIT_OSD_ICON(image_qty);
    INIT_OSD_ICON(cont_shot);
    INIT_OSD_ICON(delay_timer);
    INIT_OSD_ICON(dsc_mode);
    INIT_OSD_ICON(af_mode);
    INIT_OSD_ICON(af_meter);
    
    INIT_OSD_ICON(zoom_mf_toggle);
    INIT_OSD_ICON(iso);
    INIT_OSD_ICON(ae_meter);
    INIT_OSD_ICON(storage);
    INIT_OSD_ICON(ev);
    INIT_OSD_ICON(ev_inc);
    INIT_OSD_ICON(ev_dec);
    INIT_OSD_ICON(zoom);
    INIT_OSD_ICON(zoom_inc);
    INIT_OSD_ICON(zoom_dec);
    /* capture */
    
    INIT_OSD_ICON(capture);
    INIT_OSD_ICON(mms_icon);
    INIT_OSD_ICON(zoom_mf_toggle);
    INIT_OSD_ICON(add_frame);
    INIT_OSD_ICON(closeup);
    INIT_OSD_ICON(remain_storage);
    INIT_OSD_ICON(flash_charge_status);
    
#if defined(__CAMERA_OSD_HORIZONTAL__)
    active_camera_osd_ptr = &g_camera_osd_cntx_270;
    
    INIT_OSD_ICON(effect);
    INIT_OSD_ICON(lsk);
    INIT_OSD_ICON(rsk);
    INIT_OSD_ICON(wb);
    INIT_OSD_ICON(flash);
    INIT_OSD_ICON(led_highlight);
    INIT_OSD_ICON(night);
    INIT_OSD_ICON(image_size);
    INIT_OSD_ICON(image_qty);
    INIT_OSD_ICON(cont_shot);
    INIT_OSD_ICON(delay_timer);
    INIT_OSD_ICON(dsc_mode);
    INIT_OSD_ICON(af_mode);
    INIT_OSD_ICON(af_meter);
    
    INIT_OSD_ICON(zoom_mf_toggle);
    INIT_OSD_ICON(iso);
    INIT_OSD_ICON(ae_meter);
    INIT_OSD_ICON(storage);
    INIT_OSD_ICON(ev);
    INIT_OSD_ICON(ev_inc);
    INIT_OSD_ICON(ev_dec);
    INIT_OSD_ICON(zoom);
    INIT_OSD_ICON(zoom_inc);
    INIT_OSD_ICON(zoom_dec);
    /* capture */
    
    INIT_OSD_ICON(capture);
    INIT_OSD_ICON(mms_icon);
    INIT_OSD_ICON(zoom_mf_toggle);
    INIT_OSD_ICON(add_frame);
    INIT_OSD_ICON(closeup);
    INIT_OSD_ICON(remain_storage);    
    INIT_OSD_ICON(flash_charge_status);
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
    
}
#endif /* #if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)*/ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_init_app
* DESCRIPTION
*  nit camera application
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_camera_init_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    U16 str_id;
    U16 img_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* print trace Info */
    CAMERA_TRACE_FUNC_INIT();
    /* initialize camera app-based memory */
    applib_mem_ap_register(APPLIB_MEM_AP_ID_CAMERA,STR_ID_CAMERA_APP_NAME 
        ,IMG_ID_CAMERA_APP_ICON ,mmi_camera_app_mem_stop_callback);
    
    
    /* init Option Menu */
    mmi_camera_init_option_menu();
    
    /* init context */
    g_camera_cntx.app_state = CAMERA_STATE_EXIT;
    g_camera_cntx.app_prev_state = CAMERA_STATE_EXIT;
    g_camera_cntx.app_next_state = CAMERA_STATE_EXIT;
    
    g_camera_cntx.tmp_callback_ptr = NULL;
    g_camera_cntx.tmp_external_request_mode = MMI_CAMERA_EXTERNAL_MODE_OFF;
    
    g_camera_cntx.is_force_self_capture = FALSE;
    g_camera_cntx.is_setting_loaded = FALSE;
    g_camera_cntx.is_mainlcd_resource = FALSE;
    g_camera_cntx.is_sublcd_resource = FALSE;
    g_camera_cntx.is_sublcd_display = FALSE;
    g_camera_cntx.is_tileshot = FALSE;
    g_camera_cntx.is_fullscreen = FALSE;
    g_camera_cntx.is_dis_clam_open = FALSE;
    g_camera_cntx.is_cat65_show = FALSE;
    g_camera_cntx.is_multi_sound_open = FALSE;
    g_camera_cntx.is_continue_capture = FALSE;
    g_camera_cntx.has_camera_previewed = FALSE;
    g_camera_cntx.is_manual_autofocus = FALSE;
    g_camera_cntx.is_audio_finished = TRUE;
    g_camera_cntx.is_hide_osd = FALSE;
    /* for External Request */
    g_camera_cntx.external_request_mode = MMI_CAMERA_EXTERNAL_MODE_OFF;
    g_camera_cntx.is_in_fast_forward = FALSE;
    
    g_camera_cntx.base_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    g_camera_cntx.add_frame_layer_handle = GDI_LAYER_EMPTY_HANDLE;
#if defined(__MMI_CAMERA_3_OSD_LAYER__)    
    g_camera_cntx.osd_layer_handle0 = GDI_LAYER_EMPTY_HANDLE;
    g_camera_cntx.osd_layer_handle1 = GDI_LAYER_EMPTY_HANDLE;
    g_camera_cntx.osd_layer_handle2 = GDI_LAYER_EMPTY_HANDLE;
#elif defined(__MMI_CAMERA_5_OSD_LAYER__)
    g_camera_cntx.osd_layer_handle0 = GDI_LAYER_EMPTY_HANDLE;
    g_camera_cntx.osd_layer_handle1 = GDI_LAYER_EMPTY_HANDLE;
    g_camera_cntx.osd_layer_handle2 = GDI_LAYER_EMPTY_HANDLE;
    g_camera_cntx.osd_layer_handle3 = GDI_LAYER_EMPTY_HANDLE;
    g_camera_cntx.osd_layer_handle4 = GDI_LAYER_EMPTY_HANDLE;
#else /* __MMI_CAMERA_3_OSD_LAYER__ */ 
    g_camera_cntx.osd_layer_handle0 = GDI_LAYER_EMPTY_HANDLE;
#endif /* __MMI_CAMERA_3_OSD_LAYER__ */ 
    g_camera_cntx.sublcd_base_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    g_camera_cntx.tileshot_result_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    g_camera_cntx.tileshot_preview_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    g_camera_cntx.preview_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    
    g_camera_cntx.tile_cur_num = 0;
    
#if defined(__CAMERA_OSD_HORIZONTAL__)
    g_camera_cntx.osd_rotate = CAMERA_DISPLAY_ROTATE_270;
    g_camera_cntx.base_UI_device_width = LCD_HEIGHT;
    g_camera_cntx.base_UI_device_height = LCD_WIDTH;
#else /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
    g_camera_cntx.osd_rotate = CAMERA_DISPLAY_ROTATE_0;
    g_camera_cntx.base_UI_device_width = LCD_WIDTH;
    g_camera_cntx.base_UI_device_height = LCD_HEIGHT;
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
    
    g_camera_cntx.capture_path = CAPTURE_FROM_MEMORY;
    g_camera_cntx.active_camera_osd_ptr = &g_camera_osd_cntx;
    
#if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
    mmi_camera_init_osd_icon_layer_position();
#endif 
    g_camera_cntx.osd_UI_device_width = LCD_WIDTH;
    g_camera_cntx.osd_UI_device_height = LCD_HEIGHT;
    
    mmi_camera_preview_update_capture_size();
    g_camera_cntx.multi_sound_dummy_bg = 0;
    g_camera_cntx.multi_sound_capture0 = 0;
    g_camera_cntx.multi_sound_capture1 = 0;
    g_camera_cntx.multi_sound_capture2 = 0;
    
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
    g_camera_cntx.image_size_before_burst = CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX;
#endif 
    
    memset(g_camera_cntx.hint1_buf, 0, CAMERA_HINT_BUF_SIZE);
    memset(g_camera_cntx.hint2_buf, 0, CAMERA_HINT_BUF_SIZE);
    
    /* init image size string */
    index = 0;
    
#ifdef __CAMERA_FEATURE_IMAGE_SIZE_SS__
    str_id = mmi_camera_get_img_size_str_id(CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH, CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT);
    img_id = mmi_camera_get_img_size_img_id(CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH, CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT);
    g_camera_cntx.image_size_img_id[index] = img_id;
    g_camera_cntx.image_size_str_id[index++] = str_id;
    
#endif /* __CAMERA_FEATURE_IMAGE_SIZE_SS__ */ 
    
#ifdef __CAMERA_FEATURE_IMAGE_SIZE_S__
    str_id = mmi_camera_get_img_size_str_id(CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH, CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT);
    img_id = mmi_camera_get_img_size_img_id(CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH, CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT);
    g_camera_cntx.image_size_img_id[index] = img_id;
    g_camera_cntx.image_size_str_id[index++] = str_id;
#endif /* __CAMERA_FEATURE_IMAGE_SIZE_S__ */ 
    
#ifdef __CAMERA_FEATURE_IMAGE_SIZE_M__
    str_id = mmi_camera_get_img_size_str_id(CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH, CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT);
    img_id = mmi_camera_get_img_size_img_id(CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH, CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT);
    g_camera_cntx.image_size_img_id[index] = img_id;
    g_camera_cntx.image_size_str_id[index++] = str_id;
#endif /* __CAMERA_FEATURE_IMAGE_SIZE_M__ */ 
    
#ifdef __CAMERA_FEATURE_IMAGE_SIZE_L__
    str_id = mmi_camera_get_img_size_str_id(CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH, CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT);
    img_id = mmi_camera_get_img_size_img_id(CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH, CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT);
    g_camera_cntx.image_size_img_id[index] = img_id;
    g_camera_cntx.image_size_str_id[index++] = str_id;
#endif /* __CAMERA_FEATURE_IMAGE_SIZE_L__ */ 
    
#ifdef __CAMERA_FEATURE_IMAGE_SIZE_LL__
    str_id = mmi_camera_get_img_size_str_id(CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH, CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT);
    img_id = mmi_camera_get_img_size_img_id(CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH, CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT);
    
    g_camera_cntx.image_size_img_id[index] = img_id;
    g_camera_cntx.image_size_str_id[index++] = str_id;
#endif /* __CAMERA_FEATURE_IMAGE_SIZE_LL__ */ 
    
    mmi_camera_update_osd_touch_icon();
    
#ifdef __MMI_SCREEN_SNAPSHOT__
    g_camera_cntx.is_screen_snapshot = FALSE;
#endif 
    
#ifdef __CAMERA_FEATURE_XENON_FLASH__
    g_camera_cntx.xenon_flash_state = MMI_CAMERA_XENON_FLASH_OFF;
#endif
    
    g_camera_cntx.app_mem_pool = NULL;
}

#if defined(__CAMERA_FEATURE_XENON_FLASH__)
/*****************************************************************************
* FUNCTION
*  mmi_camera_xenon_flash_callback
* DESCRIPTION
*  xenon flash light indicator (from MED) hdlr
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_xenon_flash_callback(mdi_result result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (CAMERA_STATE_IN(CAMERA_STATE_PREVIEW)||CAMERA_STATE_IN(CAMERA_STATE_SUB_PREVIEW))
    {
        switch(result)
        {
        case MDI_RES_CAMERA_SUCCEED:
            g_camera_cntx.xenon_flash_state = MMI_CAMERA_XENON_FLASH_READY;
            mmi_camera_preview_draw_osd();
            mmi_camera_blt();
            break;
        case MDI_RES_CAMERA_XENONFLASH_CHARGING:
            if (g_camera_cntx.xenon_flash_state == MMI_CAMERA_XENON_FLASH_CHARGING)
                g_camera_cntx.xenon_flash_state = MMI_CAMERA_XENON_FLASH_CHARGING_1;
            else
                g_camera_cntx.xenon_flash_state = MMI_CAMERA_XENON_FLASH_CHARGING;
            
            mmi_camera_preview_draw_osd();
            mmi_camera_blt();
            break;
        case MDI_RES_CAMERA_ERR_XENONFLASH_TIMEOUT:
            g_camera_cntx.last_error = MDI_RES_CAMERA_ERR_XENONFLASH_TIMEOUT;
            g_camera_cntx.setting.flash = CAMERA_SETTING_FLASH_OFF;
            g_camera_cntx.xenon_flash_state = MMI_CAMERA_XENON_FLASH_OFF;
            mmi_camera_display_error_popup();                
            break;
        case MDI_RES_CAMERA_ERR_XENONFLASH_LOW_BATTERY:
            g_camera_cntx.last_error = MDI_RES_CAMERA_ERR_XENONFLASH_LOW_BATTERY;
            g_camera_cntx.setting.flash = CAMERA_SETTING_FLASH_OFF;
            g_camera_cntx.xenon_flash_state = MMI_CAMERA_XENON_FLASH_OFF;
            mmi_camera_display_error_popup();                
            break;
        }
    }
}
#endif

/*****************************************************************************
* FUNCTION
*  mmi_camera_del_scr_callback
* DESCRIPTION
*  camera delete screen callback handler
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static U8 mmi_camera_del_scr_callback(void* ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* exit camera state */
    if (CAMERA_STATE_IN(CAMERA_STATE_FORWARD_TO))
    {
        CAMERA_ENTER_STATE(CAMERA_STATE_EXIT);
    }
    
    mmi_camera_free_app_mem();
    
    mmi_imgview_del_scr_callback(NULL);    
    
    /* for External Request */
    if (g_camera_cntx.external_request_mode != MMI_CAMERA_EXTERNAL_MODE_OFF)
    {
        if(g_camera_cntx.external_request_mode == MMI_CAMERA_EXTERNAL_MODE_LARGEST_RESOLUTION)
            g_camera_cntx.setting.image_size = g_camera_cntx.img_size_backup;
        
        g_camera_cntx.setting.cont_shot = g_camera_cntx.contshot_backup;
        g_camera_cntx.external_request_mode = MMI_CAMERA_EXTERNAL_MODE_OFF;
    }
    
    /* to rsolve reentry issue of camera -> mms -> camera -> captuer -> back -> back to camera, we need to reserve the last capture file name */
    if (GetActiveScreenId()!=SCR_ID_CAMERA_EXTERNAL_REQUESET_SCREEN && IsScreenPresent(SCR_ID_CAMERA_APP)==TRUE)
    {
        /* free buffer */
        if (g_camera_cntx.storage_filepath != NULL)
        {
            gui_free(g_camera_cntx.storage_filepath);
            g_camera_cntx.storage_filepath = NULL;
        }
        if (g_camera_cntx.captured_filepath != NULL)
        {
            gui_free(g_camera_cntx.captured_filepath);
            g_camera_cntx.captured_filepath = NULL;
        }
    }
    return 0;
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_free_app_mem
* DESCRIPTION
*  This function is called to free camera app-based memory
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_free_app_mem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_camera_cntx.app_mem_pool != NULL)
    {
        applib_mem_ap_free((void*)g_camera_cntx.app_mem_pool);
        g_camera_cntx.app_mem_pool = NULL;
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_camera_app_mem_stop_callback
* DESCRIPTION
*  callback function used by applib to free APP-Based Memory
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_app_mem_stop_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 screen_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Free Memory */
    mmi_camera_free_app_mem();
    
    /*Notify MMI that this application is already stopped */
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_CAMERA,KAL_TRUE);
    
    for (screen_id = SCR_ID_CAMERA_APP; screen_id <= SCR_ID_CAMERA_FORWARD_OPTION; screen_id++)
    {
        DeleteScreenIfPresent(screen_id);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_app_mem_success_callback
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_app_mem_success_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DIRECT_SENSOR_SUPPORT__
    g_camera_cntx.app_mem_pool 
        = applib_mem_ap_alloc_framebuffer(APPLIB_MEM_AP_ID_CAMERA, CAMERA_DIRECT_COUPLE_BUFFER_SIZE);
#else
    g_camera_cntx.app_mem_pool 
        = applib_mem_ap_alloc_framebuffer(APPLIB_MEM_AP_ID_CAMERA, CAMERA_HW_ROTATE_TMP_BUFFER);
#endif
    
    ASSERT(g_camera_cntx.app_mem_pool!=NULL); /* It should provide enough memory */
    
    if (g_camera_cntx.tmp_external_request_mode != MMI_CAMERA_EXTERNAL_MODE_OFF)
    {
        mmi_camera_load_setting();
        g_camera_cntx.callback_ptr = g_camera_cntx.tmp_callback_ptr;
        g_camera_cntx.external_request_mode = g_camera_cntx.tmp_external_request_mode;
        g_camera_cntx.contshot_backup = g_camera_cntx.setting.cont_shot;
        g_camera_cntx.setting.cont_shot = 0;
        
        if (CAMERA_STATE_IN(CAMERA_STATE_FORWARD_TO))
        {
            g_camera_cntx.is_in_fast_forward = TRUE;
            CAMERA_ENTER_STATE(CAMERA_STATE_EXIT);
        }    
        
        switch(g_camera_cntx.external_request_mode)
        {
        case MMI_CAMERA_EXTERNAL_MODE_LARGEST_RESOLUTION:
            g_camera_cntx.img_size_backup = g_camera_cntx.setting.image_size;
            mmi_camera_change_to_largest_img_size();
            break;
        default:
            break;
        }
        
        /* reset parameters of appmem callback  */
        g_camera_cntx.tmp_callback_ptr = NULL;
        g_camera_cntx.tmp_external_request_mode = MMI_CAMERA_EXTERNAL_MODE_OFF;        
    }
    
    mmi_camera_app_screen();
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_app_reset_state
* DESCRIPTION
*  reset camera application screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_app_reset_state(void)
{
    /* reset camera's state */
    if (!CAMERA_STATE_IN(CAMERA_STATE_EXIT))
        CAMERA_ENTER_STATE(CAMERA_STATE_EXIT);

    /* if return from history with error, we should call del scr callback hdlr to free memory */
    if (CheckIsBackHistory()==TRUE)
        mmi_camera_del_scr_callback((void*)0);

    /* for External Request */
    if (g_camera_cntx.external_request_mode != MMI_CAMERA_EXTERNAL_MODE_OFF)
    {
        g_camera_cntx.callback_ptr(MMI_FALSE,NULL);
        g_camera_cntx.external_request_mode = MMI_CAMERA_EXTERNAL_MODE_OFF;
        return;
    }
}
/*****************************************************************************
* FUNCTION
*  mmi_camera_app_screen
* DESCRIPTION
*  entry camera application screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_camera_app_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filepath[FMGR_PATH_BUFFER_SIZE];
    MMI_ID_TYPE string_id = 0;
    mmi_event_notify_enum event_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camera_load_setting();
    
#ifdef __USB_IN_NORMAL_MODE__
    mmi_imgview_get_storage_file_path(buf_filepath);
    
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        
        if (mmi_usb_check_path_exported((PS8) buf_filepath))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            mmi_camera_app_reset_state();
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 
#if defined(__CAMERA_FEATURE_STORAGE__)
    /*No phone storage*/
    if (MMI_PUBLIC_DRV == MMI_CARD_DRV || MMI_PUBLIC_DRV == FS_DRIVE_NOT_FOUND)
    {
        /* only memory card but plugout, need show popup*/
        if (FS_NO_ERROR != FS_GetDevStatus(MMI_CARD_DRV ,FS_MOUNT_STATE_ENUM))
        {
            MMI_CAMERA_DISPLAY_POPUP((PU8)GetString(STR_GLOBAL_INSERT_MEMORY_CARD), MMI_EVENT_FAILURE);
            mmi_camera_app_reset_state();
            return;
        }
    }
#endif
#if defined(__MMI_BT_SUPPORT__) && defined(MMI_CAMERA_CHECK_CONCURRENCY)
    if (mmi_bt_is_receiving())
    {
        g_camera_cntx.last_error = CAMERA_ERR_BT_IS_WORKING;
        goto entry_app_error_hdlr;
    }
#endif
    
    /* user press camera key when clam close in Idle screen, ignore it */
#if defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) && defined(__MTK_TARGET__)
    if (IsClamClose())
    {
        if (GetActiveScreenId() == IDLE_SCREEN_ID)
        {
            return;
        }
        else
        {
            DisplayIdleScreen();
            return;
        }
    }
    else if (GetActiveScreenId() != SCR_ID_CAMERA_OPTION)
    {
        g_camera_cntx.is_clam_close = FALSE;
    }
#endif /* defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) && defined(__MTK_TARGET__) */ 
    
#if defined(__DIRECT_SENSOR_SUPPORT__) && defined(__MMI_VIDEO_RECORDER__)
    /***********************************************************************************************
    * In MT6223P projects, Camera and Video Recorder should not exist concurrently.
    * because video recorder will allocated 320KB memory when it is in the history,
    * so before entering camera application, we should delete video recorder's screen from history.
    ***********************************************************************************************/
    mmi_vdorec_delete_all_from_history();
#endif /* defined(__DIRECT_SENSOR_SUPPORT__) && defined(__MMI_VIDEO_RECORDER__) */
    
    /* allocate memory from App-Based ASM */
    //if (g_camera_cntx.app_mem_pool==NULL && CAMERA_DIRECT_COUPLE_BUFFER_SIZE >0)
#if defined(__MDI_CAMERA_HW_ROTATOR_SUPPORT__) && defined(__CAMERA_OSD_HORIZONTAL__)
    if (g_camera_cntx.app_mem_pool==NULL)
    {
        /* reset parameters of appmem callback  */
        g_camera_cntx.tmp_callback_ptr = NULL;
        g_camera_cntx.tmp_external_request_mode = MMI_CAMERA_EXTERNAL_MODE_OFF;        
        
        g_camera_cntx.app_mem_pool 
            = applib_mem_ap_alloc_framebuffer(APPLIB_MEM_AP_ID_CAMERA, CAMERA_HW_ROTATE_TMP_BUFFER);
        
        if (g_camera_cntx.app_mem_pool == NULL)
        {
            mmi_frm_appmem_prompt_to_release_mem(
                APPLIB_MEM_AP_ID_CAMERA,
                IMG_ID_CAMERA_APP_ICON,
                CAMERA_HW_ROTATE_TMP_BUFFER ,
                mmi_camera_app_mem_success_callback);
            return;
        }       
    }
#endif

#if defined(__DIRECT_SENSOR_SUPPORT__)
    if (g_camera_cntx.app_mem_pool==NULL)
    {
        /* reset parameters of appmem callback  */
        g_camera_cntx.tmp_callback_ptr = NULL;
        g_camera_cntx.tmp_external_request_mode = MMI_CAMERA_EXTERNAL_MODE_OFF;        
        
        g_camera_cntx.app_mem_pool 
            = applib_mem_ap_alloc_framebuffer(APPLIB_MEM_AP_ID_CAMERA, CAMERA_DIRECT_COUPLE_BUFFER_SIZE);
        
        if (g_camera_cntx.app_mem_pool == NULL)
        {
            mmi_frm_appmem_prompt_to_release_mem(
                APPLIB_MEM_AP_ID_CAMERA,
                IMG_ID_CAMERA_APP_ICON,
                CAMERA_DIRECT_COUPLE_BUFFER_SIZE ,
                mmi_camera_app_mem_success_callback);
            return;
        }       
    }
#endif
    
#if defined(__MMI_CAMERA_DIRECT_SENSOR_SUPPORT__)
    if (cbm_disallow_bearer_activation() == FALSE)
    {
        cbm_disallow_bearer_error_popup();
        mmi_camera_app_reset_state();
        return;
    }
#endif

    /* Pass pre-check, enter Camera Application */
    mmi_camera_entry_app_screen_internal();
    return;
    
entry_app_error_hdlr:
    
    string_id = mmi_camera_get_error_string_by_error_enum((S32)g_camera_cntx.last_error);
    event_id = mmi_camera_get_error_type_by_error_enum((S32)g_camera_cntx.last_error);
    MMI_CAMERA_DISPLAY_POPUP((PU8)GetString(string_id), event_id);
    mmi_camera_app_reset_state();
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_entry_app_screen
* DESCRIPTION
*  entry camera application screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_camera_entry_app_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_CAMERA_BG_CALL__)
    if (mmi_ucm_is_background_call()==TRUE)
    {
        mmi_camera_incall_popup_error();
        return;
    }
#endif
    
    mmi_camera_app_screen();
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_pre_init_app
* DESCRIPTION
*  entry camera application screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_pre_init_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 cur_storage;
    S32 create_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* init some flags */
    g_camera_cntx.last_error = MDI_RES_CAMERA_SUCCEED;
    g_camera_cntx.is_dis_clam_open = FALSE;
    g_camera_cntx.tile_cur_num = 0;
    g_camera_cntx.lcm_rotate = CAMERA_LCM_MAINLCD_ROTATE;
    g_camera_cntx.is_continue_capture = FALSE;
    
    /* set default up/down key functions */
    if (g_camera_cntx.app_prev_state == CAMERA_STATE_EXIT)
    {
        g_camera_cntx.up_key = CAMERA_ZOOMIN;
        g_camera_cntx.down_key = CAMERA_ZOOMOUT;
        g_camera_cntx.toggle_updown_key = TRUE;
    }
    
#ifdef __CAMERA_AUTOFOCUS__
    g_camera_cntx.af_state = AF_CANCEL;
    g_camera_cntx.is_af_capture = FALSE;
#endif /* __CAMERA_AUTOFOCUS__ */ 
    
    if (!g_camera_cntx.is_force_self_capture)
    {
        g_camera_cntx.is_clam_close = FALSE;
    }
    
    memset(g_camera_cntx.hint1_buf, 0, CAMERA_HINT_BUF_SIZE);
    memset(g_camera_cntx.hint2_buf, 0, CAMERA_HINT_BUF_SIZE);
    
    /* allocate storage path buffer */
    if (g_camera_cntx.storage_filepath == NULL)
    {
        g_camera_cntx.storage_filepath = gui_malloc(FMGR_PATH_BUFFER_SIZE);
        memset(g_camera_cntx.storage_filepath, 0, FMGR_PATH_BUFFER_SIZE);
    }
    
    if (g_camera_cntx.captured_filepath == NULL)
    {
        g_camera_cntx.captured_filepath = gui_malloc(FMGR_PATH_BUFFER_SIZE);
        memset(g_camera_cntx.captured_filepath , 0, FMGR_PATH_BUFFER_SIZE);
    }
    
    /* check if path is valid or not. if not will pop up a screen after the preview screen is show */
    cur_storage = mmi_imgview_get_storage();
    
    if (mmi_camera_check_and_restore_valid_drv())
    {
        /* drv is valid, create directory */
        mmi_imgview_get_storage_file_path(g_camera_cntx.storage_filepath);
        create_result = mmi_imgview_create_file_dir(g_camera_cntx.storage_filepath);
        
        /* create directory failed */
        if (create_result == FS_WRITE_PROTECTION)
        {
            g_camera_cntx.last_error = CAMERA_ERR_WRITE_PROTECT;
            mmi_imgview_set_storage_not_ready();
        }
        else if (create_result == FS_DISK_FULL)
        {
            g_camera_cntx.last_error = CAMERA_ERR_CARD_DISK_FULL;
            mmi_imgview_set_storage_not_ready();
        }
        else if (create_result == FS_ROOT_DIR_FULL)
        {
            g_camera_cntx.last_error = CAMERA_ERR_ROOT_DIR_FULL;
            mmi_imgview_set_storage_not_ready();
        }
        else
            mmi_imgview_set_storage_ready();
    }
    else
    {
        g_camera_cntx.last_error = MDI_RES_CAMERA_ERR_NO_DISK;
        mmi_imgview_set_storage_not_ready();
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_post_init_app
* DESCRIPTION
*  init camera after camera power on
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_post_init_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_CAMERA_BG_CALL__) || defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) 
    pBOOL is_in_bg_call = FALSE;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* init advanced dsc mode */
    mmi_camera_preview_update_capture_size();
    
#if defined(__MMI_CAMERA_BG_CALL__)
    is_in_bg_call = mmi_ucm_is_background_call();
#endif
    
#if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) 
    if ((g_camera_cntx.is_fullscreen && g_camera_cntx.setting.add_frame != 0)||is_in_bg_call==TRUE)
    {
        g_camera_cntx.is_single_osd_layer = TRUE;
    }
    else
    {
        g_camera_cntx.is_single_osd_layer = FALSE;
    }
#endif /* #if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 
    
    /* create preview resource */
    mmi_camera_preview_create_resource();
    
    /* config layer/lcd orientation if HORIZONTAL_CAMERA */
#if defined(__CAMERA_OSD_HORIZONTAL__)
    mmi_camera_config_layer_orientation();
#endif 
}

/*****************************************************************************
* FUNCTION
*  mmi_camera_init_framework
* DESCRIPTION
*  entry camera application screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_init_framework(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* turn off 3D sound */
#ifdef __MMI_AUDIO_REVERB_EFFECT__
    g_camera_cntx.is_3d_sound_on = mmi_settings_audio_reverb_get_status();
    if (g_camera_cntx.is_3d_sound_on == TRUE)
    {
        mdi_audio_reverb_turn_off();
    }
#endif /* __MMI_AUDIO_REVERB_EFFECT__ */ 
    
    /* entry full screen app */
    entry_full_screen();
    
    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();
    
    /* stop bg music */
    mdi_audio_suspend_background_play();
    
    /* 
    * This is used to solve a very rare situation. When playing a IMELODY 
    * with backlight on/off, and the screen previous to this screen is a 
    * horizontal screen. Before enter this screen, the IMELODY turn off the
    * backlight. While exit previous screen, the layer rotate back to normal
    * size and the content is not correct. So when calling TurnOnBacklight, 
    * LCD is in sleepin state and draw wrong content to LCD.
    * So we need to clear the buffer first to avoid this situation.
    */
    gdi_layer_clear(GDI_COLOR_BLACK);
    
    /* stop MMI sleep */
    TurnOnBacklight(0);
    
    /* force all playing keypad tone off */
    AudioStopReq(GetCurKeypadTone());
    
    /* disable key pad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
    
    /* disalbe align timer  */
    UI_disable_alignment_timers();
    
    /* stop LED patten */
    StopLEDPatternBackGround();
    
    /* enable multi-layer */
    gdi_layer_multi_layer_enable();
    
    /*********** init layer var ************/
    /* get mainlcd based layer handle */
    gdi_layer_get_base_handle(&g_camera_cntx.base_layer_handle);
    
    /* get sublcd base layer handle */
#ifdef __MMI_SUBLCD__
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_layer_get_base_handle(&g_camera_cntx.sublcd_base_layer_handle);
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
    
    /************ draw sublcd and hook msg hdlr ************/
    /* entry sublcd */
    if (!g_camera_cntx.is_sublcd_display)
    {
        ForceSubLCDScreen(mmi_camera_entry_sublcd_screen);
    }
#endif /* __MMI_SUBLCD__ */ 
    
#if defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) 
    /* register event hdlr */
    mmi_frm_block_interrupt_event_handler(
        MMI_FRM_INT_CLAM,
        mmi_camera_clam_close_event_hdlr,
        NULL);
#endif /* defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) */ 
}


#ifdef __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__
/*****************************************************************************
* FUNCTION
*  mmi_camera_pre_key_hdlr_callback
* DESCRIPTION
*  entry camera pre key hdlr
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static U8 mmi_camera_pre_key_hdlr_callback(KEYBRD_MESSAGE *key_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camera_stop_all_watchdog();
    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_pre_key_hdlr_callback
* DESCRIPTION
*  entry camera pre key hdlr
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static U8 mmi_camera_post_key_hdlr_callback(KEYBRD_MESSAGE *key_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camera_restart_app_watchdog();
    if (g_camera_cntx.app_state == CAMERA_STATE_DELETE_CONFIRM)
    {
        mmi_camera_start_delete_confirm_watchdog();
    }
    return MMI_TRUE;
}
#endif    

/*****************************************************************************
* FUNCTION
*  mmi_camera_entry_app_screen_internal
* DESCRIPTION
*  entry camera application screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_entry_app_screen_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 ret;
    PU8 buf_ptr;
    U16 scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_camera_cntx.captured_filepath != NULL && CAMERA_STATE_IN(CAMERA_STATE_FORWARD_TO))
    {
        ret = FS_Open((const WCHAR *)g_camera_cntx.captured_filepath, FS_READ_ONLY);
        if (ret < 0)
        {
            CAMERA_ENTER_STATE(CAMERA_STATE_EXIT);
        }
        FS_Close(ret);
    }
    
    /* debug info */
    CAMERA_TRACE_FUNC_ENTER_APP();
    if (!CAMERA_STATE_IN(CAMERA_STATE_FORWARD_TO))
        CAMERA_CHECK_STATE(CAMERA_STATE_EXIT);
    
    
    /* if clam is opened and not enter from camera option menu */
    if (GetActiveScreenId() != SCR_ID_CAMERA_OPTION && g_camera_cntx.is_clam_close == FALSE)
    {
        /* reset force enter sub flag */
        g_camera_cntx.is_force_self_capture = FALSE;
    }
    
    /************ entry screen ************/
    if (g_camera_cntx.external_request_mode == MMI_CAMERA_EXTERNAL_MODE_OFF)
    {
        EntryNewScreen(SCR_ID_CAMERA_APP, mmi_camera_exit_app_screen, mmi_camera_app_screen, MMI_FULL_SCREEN);
        guiBuffer = GetCurrGuiBuffer(SCR_ID_CAMERA_APP);
        SetDelScrnIDCallbackHandler(SCR_ID_CAMERA_APP, mmi_camera_del_scr_callback);
    }
    else
    {
        /* for External Request */
        EntryNewScreen(SCR_ID_CAMERA_EXTERNAL_REQUESET_SCREEN, mmi_camera_exit_app_screen, mmi_camera_app_screen, MMI_FULL_SCREEN);
        guiBuffer = GetCurrGuiBuffer(SCR_ID_CAMERA_EXTERNAL_REQUESET_SCREEN);    
        SetDelScrnIDCallbackHandler(SCR_ID_CAMERA_EXTERNAL_REQUESET_SCREEN, mmi_camera_del_scr_callback);
    }

#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) */

#if defined(__MMI_BT_SUPPORT__) && defined(MMI_CAMERA_CHECK_CONCURRENCY)
    mmi_bt_disable_receiving();    
#endif

#ifdef __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__
    mmi_frm_kbd_reg_pre_key_hdlr(mmi_camera_pre_key_hdlr_callback);
    mmi_frm_kbd_reg_post_key_hdlr(mmi_camera_post_key_hdlr_callback);
#endif    
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    mmi_fe_set_antialias(MMI_FALSE);
#endif

    /* check if there is small screen above camera */
#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    if (mmi_is_redrawing_bk_screens() == TRUE && CAMERA_STATE_IN(CAMERA_STATE_FORWARD_TO) && (GetCurrSmallScrnID()==SCR_ID_CASCADING_MENU_BASE))
    {
        /* only when cascading menu is current screen and in forward state, we will need to draw bg for small screen*/
        mmi_camera_preview_free_resource();
        mmi_camera_preview_create_resource();
        mmi_camera_entry_delete_confirm_state();
        return;
    }
    else if (mmi_is_redrawing_bk_screens() == TRUE)
    {
        
        gdi_layer_push_and_set_active(g_camera_cntx.base_layer_handle);
        gdi_layer_set_rotate(CAMERA_LCM_ROTATE_0);
        gdi_layer_resize(LCD_WIDTH,LCD_HEIGHT);
        /* clear fullscreen */
        gdi_layer_clear(GDI_COLOR_WHITE);
        gdi_layer_pop_and_restore_active();
        return;
    }
#endif /* __MMI_UI_SMALL_SCREEN_SUPPORT__ */ 
    
    
#if defined(__CAMERA_FEATURE_STORAGE__)
    /*No phone storage*/
    if (MMI_PUBLIC_DRV == MMI_CARD_DRV || MMI_PUBLIC_DRV == FS_DRIVE_NOT_FOUND)
    {
        /* only memory card but plugout, need show popup*/
        if (FS_NO_ERROR != FS_GetDevStatus(MMI_CARD_DRV ,FS_MOUNT_STATE_ENUM))
        {
            MMI_CAMERA_DISPLAY_POPUP((PU8)GetString(STR_GLOBAL_INSERT_MEMORY_CARD), MMI_EVENT_FAILURE);
            for (scr_id = SCR_ID_CAMERA_APP; scr_id < SCR_ID_CAMERA_END; scr_id ++)
            {
                DeleteScreenIfPresent(scr_id);
            }
            return;
        }
    }
    /* if storage is not ready, entry select storage screen */
    if (mmi_imgview_is_storage_ready() == FALSE)
    {
        S8 buf_filepath[FMGR_PATH_BUFFER_SIZE];
        S32 create_result;
        MMI_ID_TYPE error_str_id;
        mmi_frm_screen_struct storage_screen_struct;
        U16 scrn_id;

        if (g_camera_cntx.last_error != 0)
        {
            mmi_camera_entry_storage_screen();
            return;
        }
        mmi_imgview_get_storage_file_path(buf_filepath);
        create_result = mmi_imgview_create_file_dir(buf_filepath);
        if (create_result < 0)
        {
            error_str_id = GetFileSystemErrorString(create_result);
        
            gdi_layer_get_base_handle(&g_camera_cntx.base_layer_handle);
            gdi_layer_push_and_set_active(g_camera_cntx.base_layer_handle);
            gdi_layer_clear(GDI_COLOR_BLACK);
            gdi_layer_pop_and_restore_active();

            MMI_CAMERA_DISPLAY_POPUP((PU8) GetString(error_str_id), mmi_fmgr_util_get_fs_error_popup_type(create_result));
        
            mmi_frm_init_screen_struct(&storage_screen_struct);
            if (g_camera_cntx.external_request_mode == MMI_CAMERA_EXTERNAL_MODE_OFF)
            {
                scrn_id = SCR_ID_CAMERA_APP;
            }
            else
            {
                scrn_id = SCR_ID_CAMERA_EXTERNAL_REQUESET_SCREEN;
            }
        
            storage_screen_struct.scrnID = SCR_ID_CAMERA_STORAGE;
            storage_screen_struct.entryFuncPtr = (entry_func_ptr)mmi_camera_entry_storage_screen;
            mmi_frm_insert_screen(scrn_id, &storage_screen_struct, MMI_FRM_INSERT_AFTER_SCRN);
            return;
        }
    }
#endif
    
#if defined(__MMI_CAMERA_DIRECT_SENSOR_SUPPORT__) && (defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__))
    mmi_profiles_bt_disable_sco_connection((U8)MMI_PROFILE_BT_SCO_INT_CAMERA);
#endif
    
    /* Disable HW mute for capture performance degrate issues: MAUI_01280858 */
    mdi_audio_set_hw_mute(MMI_FALSE);
    
    /* each time newly enter camera, zoom will be reset to default */
    if (guiBuffer == NULL)
    {
        g_camera_cntx.setting.zoom_idx = CAMERA_DEFAULT_SETTING_ZOOM_IDX;
    }
    
    /************ init/config framework's environment  ************/
    mmi_camera_init_framework();

#ifdef __MMI_CAMERA_DIRECT_COUPLE__
#ifdef __DIRECT_SENSOR_SUPPORT__
    g_camera_cntx.direct_couple_buffer = g_camera_cntx.app_mem_pool;
    g_camera_cntx.is_direct_couple = FALSE;    
#else
    gdi_layer_push_and_set_active(g_camera_cntx.base_layer_handle);
    gdi_layer_get_buffer_ptr(&buf_ptr);
    gdi_layer_pop_and_restore_active();
    g_camera_cntx.direct_couple_buffer = (PU8) buf_ptr;
    g_camera_cntx.is_direct_couple = FALSE;
#endif
#endif

    /************ pre-init camera app environment ************
    * 1. init some flag before power on camera
    * 2. check storage 
    ********************************************************/
    mmi_camera_pre_init_app();
    
    
    if (g_camera_cntx.last_error == MDI_RES_CAMERA_SUCCEED 
#if defined(__MMI_CAMERA_BG_CALL__)
        && mmi_ucm_is_background_call()==FALSE
#endif
        )
    {
        /* Power on and init hardware module */
        g_camera_cntx.last_error = mdi_camera_power_on();
    }
    
    /************ post-init camera app environment ************
    * no matter power on success or not, have to do post init
    *********************************************************/
    mmi_camera_post_init_app();
    
    /************ enter next state ************/
    if (CAMERA_STATE_IN(CAMERA_STATE_FORWARD_TO))
    {
        CAMERA_ENTER_STATE(CAMERA_STATE_DELETE_CONFIRM);
        
        /* if there is error happend before entering delete confirm state from forward to, 
        popup error and reset camera state */
        if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
        {
            mmi_camera_preview_flatten_layer(FALSE);
            mmi_camera_display_error_popup();
            CAMERA_ENTER_STATE(CAMERA_STATE_EXIT);
            return;
        }
        
    }
#if defined(__MMI_CAMERA_BG_CALL__)
    else if (mmi_ucm_is_background_call() == TRUE)
    {
        /* draw osd with hint */
#ifndef __CAMERA_FEATURE_HIDE_HINT__
        mmi_camera_preview_set_hint(
            (PS8) GetString((U16)STR_GLOBAL_NOT_AVAILABLE),
            NULL,
            0);
#endif /* __CAMERA_FEATURE_HIDE_HINT__ */ 
        mmi_camera_preview_draw_osd();
        gdi_layer_set_blt_layer(g_camera_cntx.base_layer_handle, g_camera_cntx.osd_layer_handle0, 0, 0);
        mmi_camera_blt();
        
        /* register key */
        mmi_camera_incall_set_key_hdlr();
    }
#endif /* __MMI_CAMERA_BG_CALL__ */
    else if ((g_camera_cntx.is_force_self_capture) && (g_camera_cntx.last_error == MDI_RES_CAMERA_SUCCEED))  /* no error, if has error, will enter main then show error popup */
    {
        /* force to enter sublcd preview from option menu */
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
        g_camera_cntx.is_force_self_capture = FALSE;
        CAMERA_ENTER_STATE(CAMERA_STATE_SUB_PREVIEW);
#else 
        MMI_ASSERT(0);
#endif
    }
    else
    {
        /* entry preview */
        CAMERA_ENTER_STATE(CAMERA_STATE_PREVIEW);
    }
    
    if (g_camera_cntx.app_state != CAMERA_STATE_EXIT)
    {
#if defined(__CAMERA_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_pen_down_handler(mmi_camera_touch_scr_pen_down_hdlr);
    wgui_register_pen_up_handler(mmi_camera_touch_scr_pen_up_hdlr);
    wgui_register_pen_move_handler(mmi_camera_touch_scr_pen_move_hdlr);
#endif /* defined(__CAMERA_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__) */ 
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_exit_app_screen
* DESCRIPTION
*  exit camera application screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_exit_app_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* print debug info */
    CAMERA_TRACE_FUNC_EXIT_APP();
    mmi_camera_reset_key_press_state();
    
    /* exit camera state */
    if (!CAMERA_STATE_IN(CAMERA_STATE_FORWARD_TO))
    {
        CAMERA_ENTER_STATE(CAMERA_STATE_EXIT);
    }    
    
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    mmi_fe_set_antialias(MMI_TRUE);
#endif

#if defined(__MMI_BT_SUPPORT__) && defined(MMI_CAMERA_CHECK_CONCURRENCY)
    mmi_bt_enable_receiving();
#endif

#ifdef __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__
    mmi_frm_kbd_reg_pre_key_hdlr(NULL);
    mmi_frm_kbd_reg_post_key_hdlr(NULL);
#endif    

#if defined(__MMI_CAMERA_DIRECT_SENSOR_SUPPORT__)
    cbm_allow_bearer_activation();
#endif
    
#if defined(__MMI_CAMERA_DIRECT_SENSOR_SUPPORT__) && (defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__))
    mmi_profiles_bt_enable_sco_connection((U8)MMI_PROFILE_BT_SCO_INT_CAMERA);
#endif
    
    /* Enable HW mute when exiting camera application: MAUI_01280858 */
    mdi_audio_set_hw_mute(MMI_TRUE);
    
    /* stop capture and stop dummy bg midi for multi-channel sound */
#if defined(__CAMERA_FEATURE_CONT_SHOT_BURST__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__)
    mmi_camera_burstshot_close_multi_sound();
    gui_cancel_timer(mmi_camera_burstshot_close_multi_sound);
#endif /* defined(__CAMERA_FEATURE_CONT_SHOT_BURST__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__) */ 
    
    /* reset af related var */
#if defined(__CAMERA_AUTOFOCUS__)
    /* !IMPORTANT! Manual focus should not be turned on, it is not a matual function */
    if (g_camera_cntx.af_state != AF_CANCEL)
    {
        mdi_camera_stop_autofocus_process();
        g_camera_cntx.af_state = AF_CANCEL;
    }
#endif /* defined(__CAMERA_AUTOFOCUS__) */ 
    
    /* stop hide hint timer */
    gui_cancel_timer(mmi_camera_preview_hide_hint);
    
#ifdef __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__
    mmi_camera_stop_app_watchdog();
    mmi_camera_stop_delete_confirm_watchdog();
#endif /* __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__ */
    
    /* turn on/of 3D sound */
#ifdef __MMI_AUDIO_REVERB_EFFECT__
    if (g_camera_cntx.is_3d_sound_on == TRUE)
    {
        mdi_audio_reverb_turn_on();
    }
#endif /* __MMI_AUDIO_REVERB_EFFECT__ */ 
    
    /* shut down camera */
    mdi_camera_power_off();
    
    /* resume alignment timer */
    UI_enable_alignment_timers();
    
    /* resume LED patten */
    StartLEDPatternBackGround();
    
    /* let MMI can sleep */
    TurnOffBacklight();
    
    /* enable multi-layer */
    gdi_layer_multi_layer_disable();
    
    /* resume background audio */
    mdi_audio_resume_background_play();
    
    /* re-enable keypad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);
    
#ifdef __MMI_SUBLCD__
    if (g_camera_cntx.sublcd_base_layer_handle != NULL)
    {
        gdi_layer_push_and_set_active(g_camera_cntx.sublcd_base_layer_handle);
        gdi_layer_set_rotate(CAMERA_LCM_ROTATE_0);
        gdi_layer_pop_and_restore_active();
    }
    /* exit sublcd */
    if (g_camera_cntx.is_sublcd_display)
    {
        GoBackSubLCDHistory();
        g_camera_cntx.is_sublcd_display = FALSE;
    }
#endif /* __MMI_SUBLCD__ */ 
    
    
#if defined(__CAMERA_OSD_HORIZONTAL__)
    if (CAMERA_STATE_IN(CAMERA_STATE_FORWARD_TO))
    {
        // do nothing for this state, we reserve baselayer as background.
        if (g_camera_cntx.base_layer_handle != NULL)
        {
            gdi_layer_push_and_set_active(g_camera_cntx.base_layer_handle);
            gdi_layer_set_rotate(GDI_LAYER_ROTATE_0);            
            gdi_layer_pop_and_restore_active();
        }
    }
    else
    {
        if (g_camera_cntx.base_layer_handle != NULL)
        {
            gdi_layer_push_and_set_active(g_camera_cntx.base_layer_handle);
            gdi_layer_resize(LCD_WIDTH, LCD_HEIGHT);
            gdi_layer_set_rotate(GDI_LAYER_ROTATE_0);            
            /* ONLY WHEN NOT IN DELETE CONFIRM STATE , WE WILL CLEAR BASE LAYER */
            if (!CAMERA_STATE_IN(CAMERA_STATE_DELETE_CONFIRM))
            {
                gdi_layer_clear(GDI_COLOR_WHITE);
            }
            
            gdi_layer_pop_and_restore_active();
        }
    }
    
    /* reset lcd set by layer flag */
    gdi_lcd_set_rotate_by_layer(FALSE);
    
#ifdef __MMI_TVOUT__
    if (mdi_tvout_is_enable())
    {
        mdi_tvout_set_mode(MDI_TV_MODE_LCD_SCR, 0, 0);
    }
#endif /* __MMI_TVOUT__ */ 
    
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
    mmi_camera_preview_free_preview_resource();
    
    /* free preview resource */
    mmi_camera_preview_free_resource();
    
    /* store camera setting back to NVRAM */
    mmi_camera_store_setting();
    
    if (g_camera_cntx.gdi_layer_handle != GDI_NULL_HANDLE)
    {
        gdi_layer_free(g_camera_cntx.gdi_layer_handle);
        g_camera_cntx.gdi_layer_handle = GDI_NULL_HANDLE;
        g_camera_cntx.gdi_layer_buffer_ptr = NULL;
    }
    
    /* this will force title status to redraw */
    entry_full_screen();
    
#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) */

}


/*****************************************************************************
* FUNCTION
*  mmi_camera_enter_state
* DESCRIPTION
*  enter next state
* PARAMETERS
*  state       [IN]        State to enter
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_enter_state(camera_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.app_prev_state = g_camera_cntx.app_state;
    g_camera_cntx.app_state = state;
    mmi_camera_reset_key_press_state();
    switch (state)
    {
    case CAMERA_STATE_EXIT:
        /* do nothing */
        break;
        
        /* main lcd */
    case CAMERA_STATE_PREVIEW:
        mmi_camera_entry_preview_state();
        break;
        
    case CAMERA_STATE_COUNTDOWN:
        mmi_camera_entry_countdown_state();
        break;
        
    case CAMERA_STATE_CONTSHOT:
        mmi_camera_entry_contshot_state();
        break;
        
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
        
    case CAMERA_STATE_BURSTSHOT:
        mmi_camera_entry_burstshot_capture_state();
        break;
        
    case CAMERA_STATE_BURSTSHOT_SAVE_CONFIRM:
        mmi_camera_entry_burstshot_save_confirm_state();
        break;
        
    case CAMERA_STATE_BURSTSHOT_SAVING:
        mmi_camera_entry_burstshot_saving_state();
        break;
        
#endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 
        
    case CAMERA_STATE_DELETE_DONE:
        mmi_camera_entry_delete_done_state();
        break;
        
    case CAMERA_STATE_DELETE_CONFIRM:
        mmi_camera_entry_delete_confirm_state();
        break;
        
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
        
        /* toggle popup */
    case CAMERA_STATE_TOGGLE_TO_SUB:
        mmi_camera_entry_toggle_to_sub_state();
        break;
        
    case CAMERA_STATE_TOGGLE_TO_MAIN:
        mmi_camera_entry_toggle_to_main_state();
        break;
        
        /* sub lcd */
    case CAMERA_STATE_SUB_PREVIEW:
        mmi_camera_entry_sublcd_preview_state();
        break;
        
    case CAMERA_STATE_SUB_COUNTDOWN:
        mmi_camera_entry_sublcd_countdown_state();
        break;
        
    case CAMERA_STATE_SUB_CONTSHOT:
        mmi_camera_entry_sublcd_contshot_state();
        break;
        
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
    case CAMERA_STATE_SUB_BURSTSHOT:
        mmi_camera_entry_sublcd_burstshot_state();
        break;
        
    case CAMERA_STATE_SUB_BURSTSHOT_SAVING:
        mmi_camera_entry_sublcd_burstshot_saving_state();
        break;
#endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 
        
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 
        
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_exit_current_state
* DESCRIPTION
*  exit camera current state
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_exit_current_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_camera_cntx.app_state)
    {
    case CAMERA_STATE_EXIT:
        /* do nothing */
        break;
        
        /* main lcd */
    case CAMERA_STATE_PREVIEW:
        mmi_camera_exit_preview_state();
        break;
        
    case CAMERA_STATE_COUNTDOWN:
        mmi_camera_exit_countdown_state();
        break;
        
    case CAMERA_STATE_CONTSHOT:
        mmi_camera_exit_contshot_state();
        break;
        
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
        
    case CAMERA_STATE_BURSTSHOT:
        mmi_camera_exit_burstshot_capture_state();
        break;
        
    case CAMERA_STATE_BURSTSHOT_SAVE_CONFIRM:
        mmi_camera_exit_burstshot_save_confirm_state();
        break;
        
    case CAMERA_STATE_BURSTSHOT_SAVING:
        mmi_camera_exit_burstshot_saving_state();
        break;
        
#endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 
        
    case CAMERA_STATE_DELETE_DONE:
        mmi_camera_exit_delete_done_state();
        break;
        
    case CAMERA_STATE_DELETE_CONFIRM:
        mmi_camera_exit_delete_confirm_state();
        break;
        
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
        
        /* toggle popup */
    case CAMERA_STATE_TOGGLE_TO_SUB:
        mmi_camera_exit_toggle_to_sub_state();
        break;
        
    case CAMERA_STATE_TOGGLE_TO_MAIN:
        mmi_camera_exit_toggle_to_main_state();
        break;
        
        /* sub lcd */
    case CAMERA_STATE_SUB_PREVIEW:
        mmi_camera_exit_sublcd_preview_state();
        break;
        
    case CAMERA_STATE_SUB_COUNTDOWN:
        mmi_camera_exit_sublcd_countdown_state();
        break;
        
    case CAMERA_STATE_SUB_CONTSHOT:
        mmi_camera_exit_sublcd_contshot_state();
        break;
        
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
    case CAMERA_STATE_SUB_BURSTSHOT:
        mmi_camera_exit_sublcd_burstshot_state();
        break;
        
    case CAMERA_STATE_SUB_BURSTSHOT_SAVING:
        mmi_camera_exit_sublcd_burstshot_saving_state();
        break;
#endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 
        
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 
        
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_clam_close_event_hdlr
* DESCRIPTION
*  handle clam close event
* PARAMETERS
*  ptr     [IN]        Message data ptr
* RETURNS
*  void
*****************************************************************************/
#if defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__)
U8 mmi_camera_clam_close_event_hdlr(mmi_frm_int_event_type interrupt_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 digua_gpio_device;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if(interrupt_event == MMI_FRM_INT_CLAM_CLOSE)
    {
        digua_gpio_device = EXT_DEV_CLAM_CLOSE;
    }
    else if(interrupt_event == MMI_FRM_INT_CLAM_OPEN)
    {
        digua_gpio_device = EXT_DEV_CLAM_OPEN;
    }
    
    if (interrupt_event == MMI_FRM_INT_CLAM_CLOSE)
    {
        g_camera_cntx.is_clam_close = TRUE;
        SetClamState(EXT_DEV_CLAM_CLOSE);
        
        /* print debug info */
        CAMERA_TRACE_CLAM_CLOSE_EVENT();
        
        switch (g_camera_cntx.app_state)
        {
            /* main lcd */
        case CAMERA_STATE_PREVIEW:
        case CAMERA_STATE_COUNTDOWN:
        case CAMERA_STATE_CONTSHOT:
        case CAMERA_STATE_BURSTSHOT:
        case CAMERA_STATE_BURSTSHOT_SAVE_CONFIRM:
        case CAMERA_STATE_BURSTSHOT_SAVING:
        case CAMERA_STATE_DELETE_DONE:
        case CAMERA_STATE_DELETE_CONFIRM:
        case CAMERA_STATE_TOGGLE_TO_MAIN:
        case CAMERA_STATE_TOGGLE_TO_SUB:
            /* if clam close will not back to idle, goback to previous screen */
#ifndef __MMI_CLAMCLOSE_BACK2IDLE__
            GoBackHistory();
#endif 
            
            return FALSE;   /* pass this interrupt to framwork's handler */
            break;
            /* sub lcd */
        case CAMERA_STATE_SUB_COUNTDOWN:
        case CAMERA_STATE_SUB_CONTSHOT:
        case CAMERA_STATE_SUB_BURSTSHOT:
        case CAMERA_STATE_SUB_BURSTSHOT_SAVING:
            CAMERA_ENTER_STATE(CAMERA_STATE_SUB_PREVIEW);
            mmi_gpio_detect_send_ack(digua_gpio_device);
            return TRUE;    /* block this event - do not call default handler */
            break;
            
        case CAMERA_STATE_SUB_PREVIEW:
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
            /* stop and restart sublcd preview, will display correcly according to clam close/open */
            mmi_camera_sublcd_preview_stop();
            
            /* config rotate of preview layer, only ISP_SUPPORT need */
#if defined(ISP_SUPPORT)
            gdi_layer_push_and_set_active(g_camera_cntx.sublcd_base_layer_handle);
            gdi_layer_set_rotate(CAMERA_LCM_SUBLCD_CLAM_CLOSE_ROTATE);
            gdi_layer_pop_and_restore_active();
#endif /* defined(ISP_SUPPORT) */ 
            
            mmi_camera_sublcd_preview_start();
            mmi_gpio_detect_send_ack(digua_gpio_device);
            return TRUE;    /* block this event - do not call default handler */
#else /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 
            MMI_ASSERT(0);
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 
            break;
            
        default:
            MMI_ASSERT(0);  /* make sure all state is handled */
            break;
        }
    }
    else if (interrupt_event == EXT_DEV_CLAM_OPEN)
    {
        g_camera_cntx.is_clam_close = FALSE;
        SetClamState(EXT_DEV_CLAM_OPEN);
        
        /* print debug info */
        CAMERA_TRACE_CLAM_OPEN_EVENT();
        
        switch (g_camera_cntx.app_state)
        {
            /* main lcd */
        case CAMERA_STATE_PREVIEW:
        case CAMERA_STATE_COUNTDOWN:
        case CAMERA_STATE_CONTSHOT:
        case CAMERA_STATE_BURSTSHOT:
        case CAMERA_STATE_BURSTSHOT_SAVING:
        case CAMERA_STATE_DELETE_DONE:
        case CAMERA_STATE_TOGGLE_TO_MAIN:
        case CAMERA_STATE_TOGGLE_TO_SUB:
            /* clam open do nothing */
            return FALSE;   /* pass this interrupt to framwork's handler */
            break;
            
        case CAMERA_STATE_DELETE_CONFIRM:
        /* 
        * this may happened when user capture tile image on sub. and all images
        * are captured and enter save confirm state 
            */
            if (g_camera_cntx.is_dis_clam_open)
            {
                /* block this event - do not call default handler */
                g_camera_cntx.is_dis_clam_open = FALSE;
                mmi_gpio_detect_send_ack(digua_gpio_device);
                return TRUE;
            }
            else
            {
                return FALSE;
            }
            break;
            
            /* sub lcd */
        case CAMERA_STATE_SUB_COUNTDOWN:
        case CAMERA_STATE_SUB_CONTSHOT:
        case CAMERA_STATE_SUB_BURSTSHOT:
        case CAMERA_STATE_SUB_BURSTSHOT_SAVING:
            CAMERA_ENTER_STATE(CAMERA_STATE_SUB_PREVIEW);
            mmi_gpio_detect_send_ack(digua_gpio_device);
            return TRUE;    /* block this event - do not call default handler */
            break;
            
        case CAMERA_STATE_SUB_PREVIEW:
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
            /* stop and restart sublcd preview, will display correcly according to clam close/open */
            mmi_camera_sublcd_preview_stop();
            
            /* config rotate of preview layer, only ISP_SUPPORT need */
#if defined(ISP_SUPPORT)
            gdi_layer_push_and_set_active(g_camera_cntx.sublcd_base_layer_handle);
            gdi_layer_set_rotate(CAMERA_LCM_SUBLCD_CLAM_OPEN_ROTATE);
            gdi_layer_pop_and_restore_active();
#endif /* defined(ISP_SUPPORT) */ 
            
            mmi_camera_sublcd_preview_start();
            mmi_gpio_detect_send_ack(digua_gpio_device);
            return TRUE;    /* block this event - do not call default handler */
#else /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 
            MMI_ASSERT(0);
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 
            break;
            
        default:
            MMI_ASSERT(0);  /* make sure all state is handled */
            break;
        }
    }
    
    
    /* return false means will pass this interrut to default handler */
    return FALSE;
}
#endif /* defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_calc_remain_storage
* DESCRIPTION
*  calculate remain storage precent
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_calc_remain_storage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_DiskInfo disk_info;
    S8 disk_path[10];
    U32 disk_free_space;
    U32 disk_total_space;
    S32 fs_ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Get disk name, calculate available disk space */
    memset(disk_path, 0, sizeof(disk_path));
    
    if (FALSE == mmi_camera_get_storage_disk_path(disk_path))
    {
        g_camera_cntx.remain_percent = 0;
    }
    else
    {
        fs_ret = FS_GetDiskInfo((kal_uint16*) disk_path, &disk_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
        
        g_camera_cntx.remain_percent = 0;
        
        if (fs_ret >= 0)
        {
            disk_free_space = disk_info.FreeClusters;
            disk_total_space = disk_info.TotalClusters;
            
            if (disk_total_space > 0)
            {
                g_camera_cntx.remain_percent = (U8) (disk_free_space * 100 / disk_total_space);
            }
            else
            {
                g_camera_cntx.remain_percent = 0;
            }
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_toggle_hide_osd
* DESCRIPTION
*  toggle hide osd
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_toggle_hide_osd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.is_hide_osd = (g_camera_cntx.is_hide_osd) ? FALSE : TRUE;
    mmi_camera_preview_draw_osd();
    mmi_camera_blt();
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_toggle_self_capture
* DESCRIPTION
*  toggle self capture (Main/Sub)
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_toggle_self_capture(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_camera_cntx.app_state == CAMERA_STATE_PREVIEW)
    {
        CAMERA_ENTER_STATE(CAMERA_STATE_TOGGLE_TO_SUB);
    }
    else if (g_camera_cntx.app_state == CAMERA_STATE_SUB_PREVIEW)
    {
        /* only when clam is open may toggle to main */
        if (!g_camera_cntx.is_clam_close)
        {
            CAMERA_ENTER_STATE(CAMERA_STATE_TOGGLE_TO_MAIN);
        }
    }
}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_turn_on_preview_led_highlight
* DESCRIPTION
*  turn on preview led highlght
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_turn_on_preview_led_highlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 duty;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    duty = (U8) g_camera_cntx.setting.preview_led_value;
    
    if (duty == 0)
    {
        custom_stop_flashlight();
        return;
    }
    
#ifdef __CAMERA_FEATURE_LED_HIGHLIGHT_7_COLOR__
    switch (g_camera_cntx.setting.led_highlight)
    {
    case CAMERA_SETTING_LED_HIGHLIGHT_WHITE:
        custom_start_flashlight(1, 1, 1, duty);
        break;
        
    case CAMERA_SETTING_LED_HIGHLIGHT_RED:
        custom_start_flashlight(1, 0, 0, duty);
        break;
        
    case CAMERA_SETTING_LED_HIGHLIGHT_GREEN:
        custom_start_flashlight(0, 1, 0, duty);
        break;
        
    case CAMERA_SETTING_LED_HIGHLIGHT_BLUE:
        custom_start_flashlight(0, 0, 1, duty);
        break;
        
    case CAMERA_SETTING_LED_HIGHLIGHT_YELLOW:
        custom_start_flashlight(1, 1, 0, duty);
        break;
        
    case CAMERA_SETTING_LED_HIGHLIGHT_PURPLE:
        custom_start_flashlight(1, 0, 1, duty);
        break;
        
    case CAMERA_SETTING_LED_HIGHLIGHT_CYAN:
        custom_start_flashlight(0, 1, 1, duty);
        break;
        
    case CAMERA_SETTING_LED_HIGHLIGHT_OFF:
        custom_stop_flashlight();
        break;
        
    default:
        /* restore default value */
        mmi_camera_restore_setting();
        break;
    }
#endif /* __CAMERA_FEATURE_LED_HIGHLIGHT_7_COLOR__ */ 
    
#ifdef __CAMERA_FEATURE_LED_HIGHLIGHT_ON_OFF__
    switch (g_camera_cntx.setting.led_highlight)
    {
    case CAMERA_SETTING_LED_HIGHLIGHT_ON:
        custom_start_flashlight(1, 1, 1, duty);
        break;
        
    case CAMERA_SETTING_LED_HIGHLIGHT_OFF:
        custom_stop_flashlight();
        break;
        
    default:
        /* restore default value */
        mmi_camera_restore_setting();
        break;
    }
#endif /* __CAMERA_FEATURE_LED_HIGHLIGHT_ON_OFF__ */ 
    
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_turn_on_capture_led_highlight
* DESCRIPTION
*  turn on preview led highlght
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_turn_on_capture_led_highlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 duty;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    duty = (U8) g_camera_cntx.setting.capture_led_value;
    
    if (duty == 0)
    {
        custom_stop_flashlight();
        return;
    }
    
#ifdef __CAMERA_FEATURE_LED_HIGHLIGHT_7_COLOR__
    switch (g_camera_cntx.setting.led_highlight)
    {
    case CAMERA_SETTING_LED_HIGHLIGHT_WHITE:
        custom_start_flashlight(1, 1, 1, duty);
        break;
        
    case CAMERA_SETTING_LED_HIGHLIGHT_RED:
        custom_start_flashlight(1, 0, 0, duty);
        break;
        
    case CAMERA_SETTING_LED_HIGHLIGHT_GREEN:
        custom_start_flashlight(0, 1, 0, duty);
        break;
        
    case CAMERA_SETTING_LED_HIGHLIGHT_BLUE:
        custom_start_flashlight(0, 0, 1, duty);
        break;
        
    case CAMERA_SETTING_LED_HIGHLIGHT_YELLOW:
        custom_start_flashlight(1, 1, 0, duty);
        break;
        
    case CAMERA_SETTING_LED_HIGHLIGHT_PURPLE:
        custom_start_flashlight(1, 0, 1, duty);
        break;
        
    case CAMERA_SETTING_LED_HIGHLIGHT_CYAN:
        custom_start_flashlight(0, 1, 1, duty);
        break;
        
    case CAMERA_SETTING_LED_HIGHLIGHT_OFF:
        custom_stop_flashlight();
        break;
        
    default:
        /* restore default value */
        mmi_camera_restore_setting();
        break;
    }
#endif /* __CAMERA_FEATURE_LED_HIGHLIGHT_7_COLOR__ */ 
    
#ifdef __CAMERA_FEATURE_LED_HIGHLIGHT_ON_OFF__
    switch (g_camera_cntx.setting.led_highlight)
    {
    case CAMERA_SETTING_LED_HIGHLIGHT_ON:
        custom_start_flashlight(1, 1, 1, duty);
        break;
        
    case CAMERA_SETTING_LED_HIGHLIGHT_OFF:
        custom_stop_flashlight();
        break;
        
    default:
        /* restore default value */
        mmi_camera_restore_setting();
        break;
    }
#endif /* __CAMERA_FEATURE_LED_HIGHLIGHT_ON_OFF__ */ 
    
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_turn_off_led_highlight
* DESCRIPTION
*  turn off preview led highlght
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_turn_off_led_highlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    custom_stop_flashlight();
}

/*****************************************************************************
*
*  Camera Main LCD Preview State
*
*****************************************************************************/


/*****************************************************************************
* FUNCTION
*  mmi_camera_entry_preview_state
* DESCRIPTION
*  entry mainlcd preview state
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_entry_preview_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /************ init global var ************/
    g_camera_cntx.is_clam_close = FALSE;
    g_camera_cntx.is_lsk_pressed = FALSE;
    g_camera_cntx.is_rsk_pressed = FALSE;
    g_camera_cntx.is_ev_inc_pressed = FALSE;
    g_camera_cntx.is_ev_dec_pressed= FALSE;
    g_camera_cntx.is_up_arrow_pressed = FALSE;
    g_camera_cntx.is_down_arrow_pressed = FALSE;
    g_camera_cntx.is_capturing = FALSE;
    g_camera_cntx.is_fast_zoom = FALSE;
    g_camera_cntx.is_draw_timer_on = FALSE;
    /* for remove focus zone */
#ifdef __CAMERA_AUTOFOCUS__
    g_camera_cntx.is_autofocus_pressed = FALSE;
#endif
    g_camera_cntx.touch_effect.is_press = FALSE;
    g_camera_cntx.touch_wb.is_press = FALSE;
    g_camera_cntx.touch_flash.is_press = FALSE;
    g_camera_cntx.touch_led_highlight.is_press = FALSE;
    g_camera_cntx.touch_night.is_press = FALSE;
    g_camera_cntx.touch_image_size.is_press = FALSE;
    g_camera_cntx.touch_image_qty.is_press = FALSE;
    g_camera_cntx.touch_cont_shot.is_press = FALSE;
    g_camera_cntx.touch_delay_timer.is_press = FALSE;
    g_camera_cntx.touch_storage.is_press = FALSE;
    g_camera_cntx.touch_ev_inc.is_press = FALSE;
    g_camera_cntx.touch_ev_dec.is_press = FALSE;
    g_camera_cntx.touch_zoom_inc.is_press = FALSE;
    g_camera_cntx.touch_zoom_dec.is_press = FALSE;
    g_camera_cntx.touch_capture.is_press = FALSE;
    g_camera_cntx.touch_mms_icon.is_press = FALSE;
    g_camera_cntx.touch_dsc_mode.is_press = FALSE;
    g_camera_cntx.touch_af_mode.is_press = FALSE;
    g_camera_cntx.touch_af_meter.is_press = FALSE;
    g_camera_cntx.touch_zoom_mf_toggle.is_press = FALSE;
    
    /************ osd layer ************/
    /*currently in order to save memory, we will steal GDI memory, 
    NOTE : we only use the memory, but do not use the handle */
    if (g_camera_cntx.gdi_layer_handle == GDI_NULL_HANDLE)
    {
        gdi_layer_create(
            0,
            0,
            LCD_WIDTH,
            LCD_HEIGHT,
            &g_camera_cntx.gdi_layer_handle);
        gdi_layer_push_and_set_active(g_camera_cntx.gdi_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_get_buffer_ptr(&g_camera_cntx.gdi_layer_buffer_ptr);
        gdi_layer_pop_and_restore_active();

#if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
        mmi_camera_free_osd_layer();
        mmi_camera_create_osd_layer();
#else /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 
        if (g_camera_cntx.osd_layer_handle0 != NULL)
        {
            gdi_layer_free(g_camera_cntx.osd_layer_handle0);
            g_camera_cntx.osd_layer_handle0 = NULL;

            mmi_frm_scrmem_free((void*)g_camera_cntx.osd_layer_buf_ptr0);
            g_camera_cntx.osd_layer_buf_ptr0 = NULL;
        }
#endif

    }
    /* steal done */

    if (g_camera_cntx.osd_layer_handle0 == NULL)
    {   
#if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
        mmi_camera_create_osd_layer();
        g_camera_cntx.is_mainlcd_resource = TRUE;
#else /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 
        /* create a double layer frame from outside memory */
        g_camera_cntx.osd_layer_buf_ptr0 = mmi_frm_scrmem_alloc_framebuffer(CAMERA_OSD_BUFFER_SIZE);
        ASSERT(g_camera_cntx.osd_layer_buf_ptr0 != NULL);
        
        gdi_layer_create_cf_double_using_outside_memory(
            GDI_COLOR_FORMAT_16,
            0,
            0,
            LCD_WIDTH,
            LCD_HEIGHT,
            &g_camera_cntx.osd_layer_handle0,
            (PU8) g_camera_cntx.osd_layer_buf_ptr0,
            (S32) CAMERA_OSD_BUFFER_SIZE,
            (PU8) g_camera_cntx.gdi_layer_buffer_ptr, 
            (S32) CAMERA_OSD_BUFFER_SIZE);
        
        gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle0);
        gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();
#endif
    }
    
    /* calculate remain storage */
    mmi_camera_calc_remain_storage();
    
    /* update preview/capture size para */
    mmi_camera_preview_update_capture_size();
    
#if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) 
    if ((g_camera_cntx.is_fullscreen && g_camera_cntx.setting.add_frame != 0))
    {
        if (g_camera_cntx.is_single_osd_layer != TRUE)
        {
            g_camera_cntx.is_single_osd_layer = TRUE;
            mmi_camera_free_osd_layer();
            mmi_camera_create_osd_layer();
            /* update osd layers */
            g_camera_cntx.previous_osd_rotate = CAMERA_DISPLAY_ROTATE_RESET;
        }
    }
    else
    {
        if (g_camera_cntx.is_single_osd_layer != FALSE)
        {
            g_camera_cntx.is_single_osd_layer = FALSE;
            mmi_camera_free_osd_layer();
            mmi_camera_create_osd_layer();
            /* update osd layers */
            g_camera_cntx.previous_osd_rotate = CAMERA_DISPLAY_ROTATE_RESET;
        }
    }
#endif /* #if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 
    
    
#if defined(__CAMERA_OSD_HORIZONTAL__)
    g_camera_cntx.previous_osd_rotate = CAMERA_DISPLAY_ROTATE_RESET;
    mmi_camera_check_osd_orientation();
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
    
#ifdef CAMERA_MODULE_WITH_LCD
    gdi_layer_set_source_key(FALSE, GDI_COLOR_TRANSPARENT);
#endif 
    
#ifdef __MMI_SUBLCD__
    /* draw sublcd icon */
    mmi_camera_sublcd_draw_icon();
#endif /* __MMI_SUBLCD__ */ 
    
    
    if (g_camera_cntx.app_prev_state != CAMERA_STATE_CONTSHOT)
    {
        S32 offset_x = 0;
        S32 offset_y = 0;
        
#ifdef HORIZONTAL_CAMERA
#ifndef __MMI_CAMERA_QVGA_WALLPAPER_ON_WQVGA_LCM__
        offset_x = (LCD_HEIGHT - g_camera_cntx.preview_width) >>1 ;
        offset_y = (LCD_WIDTH - g_camera_cntx.preview_height) >> 1;
#endif
#else 
        offset_x = (LCD_WIDTH - g_camera_cntx.preview_width) >> 1;
        offset_y = (LCD_HEIGHT - g_camera_cntx.preview_height) >> 1;
#endif 
#ifdef __MMI_CAMERA_TOP_ALIGN__
        offset_x = 0;
        offset_y = 0;
#endif
        mmi_camera_preview_free_preview_resource();
        mmi_camera_preview_create_preview_resource(
            offset_x,
            offset_y,
            g_camera_cntx.preview_width,
            g_camera_cntx.preview_height,
            g_camera_cntx.lcm_rotate);
    }
    
    /* init title bar */
    if (g_camera_cntx.active_camera_osd_ptr->title.is_draw_mmi_title_bar)
    {
#if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)
        reset_title_status_icon();
        show_status_icon_bar(0);
#endif /* defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) */ 
        
        /* hide short cut */
        wgui_title_set_menu_shortcut_number(-1);
        
        if (g_camera_cntx.active_camera_osd_ptr->title.is_draw_mmi_caption)
        {
            ChangeTitle(MAIN_MENU_TITLE_MULTIMEDIA_ICON, (PU8) GetString(STR_ID_CAMERA_APP_NAME));
        }
        else
        {
            ChangeTitle(0, (PU8) GetString(STR_ID_CAMERA_APP_NAME));
        }
    }
    else
    {
#if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)
        hide_status_icon_bar(0);
#endif 
    }
    
    /* register keys */
    mmi_camera_preview_set_key_hdlr();
    
    /* clear base layer bg */
    if (g_camera_cntx.app_prev_state != CAMERA_STATE_CONTSHOT)
    {
        mmi_camera_preview_clear_background();
    }
    
    
#ifdef __CAMERA_FEATURE_ADD_FRAME__
    mmi_camera_create_add_frame_layer();
#endif /* __CAMERA_FEATURE_ADD_FRAME__ */ 
    
    /* draw panel and softkey */
    mmi_camera_preview_set_hint(NULL, NULL, 0);
    mmi_camera_preview_draw_osd();
    
    /* set blt layer for non-previwing, and blt first skin */
    mmi_camera_preview_set_blt_layer(FALSE);
    mmi_camera_blt();
    
    /* check if any error occurs in mmi_camera_app_screen function */
    if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
    {
        mmi_camera_display_error_popup();
        return;
    }
    else
    {
        /* if no error occurs, start preview */
        mmi_camera_preview_set_blt_layer(TRUE);
        mmi_camera_preview_start();
    }
    
    /* check if preview success */
    if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
    {
        mmi_camera_display_error_popup();
        return;
    }
    
    /*
    * added the following code here for the max zoom factor can be retrieved correctly 
    * * only when camera has started preview at least once. So the following code is for 
    * * camera to get the correct max zoom factor and redraw the osd in case there should 
    * * be a zoom in/out bar.
    */
    
#if !defined(__VGA_8XZOOM__) && defined(ISP_SUPPORT) && defined(__MTK_TARGET__)
    /* get zoom_limit from sensor driver */
    if ((g_camera_cntx.last_error == MDI_RES_CAMERA_SUCCEED)&&(g_camera_cntx.has_camera_previewed == FALSE))
    {
        g_camera_cntx.has_camera_previewed = TRUE;
        mmi_camera_initilize_zoom_factor();
    }
#endif /* defined(ISP_SUPPORT) && defined(__MTK_TARGET__) */ 
    
    
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_exit_preview_state
* DESCRIPTION
*  exit preview state
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_exit_preview_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop timer */
    if (g_camera_cntx.app_next_state != CAMERA_STATE_COUNTDOWN)
    {
        gui_cancel_timer(mmi_camera_preview_hide_hint);
    }
    
#ifdef __CAMERA_FEATURE_ZOOM__
    gui_cancel_timer(mmi_camera_preview_zoom_out);
    gui_cancel_timer(mmi_camera_preview_zoom_in);
#endif /* __CAMERA_FEATURE_ZOOM__ */ 
    
#ifdef __CAMERA_FEATURE_EV__
    gui_cancel_timer(mmi_camera_preview_ev_inc_key_press);
    gui_cancel_timer(mmi_camera_preview_ev_dec_key_press);
#endif
    
#ifdef __CAMERA_FAST_ZOOM_SUPPORT__
    mmi_camera_stop_fast_zoom();
    
    gui_cancel_timer(mmi_camera_start_fast_zoom_out);
    gui_cancel_timer(mmi_camera_start_fast_zoom_in);
#endif /* __CAMERA_FAST_ZOOM_SUPPORT__ */ 
    
    gui_cancel_timer(mmi_camera_preview_draw_osd_timer);
    g_camera_cntx.is_draw_timer_on = FALSE;
    
    /* there are some setting changed by using hotkey or preview panel, save them to NVRAM */
    // remove for performance enhancement W08.34 mmi_camera_store_setting();
    
    /* exit app */
    if (g_camera_cntx.app_next_state == CAMERA_STATE_EXIT)
    {
        /* stop previewing */
        mmi_camera_preview_stop();
        
        /* turn off led highlight */
        mmi_camera_turn_off_led_highlight();
        
        
        /* flatten layer */
        mmi_camera_preview_flatten_layer(TRUE);
    }
    
    /* toggle to sub */
    if (g_camera_cntx.app_next_state == CAMERA_STATE_TOGGLE_TO_SUB)
    {
        /* stop previewing */
        mmi_camera_preview_stop();
        
        /* turn off led highlight */
        mmi_camera_turn_off_led_highlight();
        
        
        mmi_camera_preview_free_preview_resource();
        
        if (g_camera_cntx.is_fullscreen)
        {
            gdi_layer_set_blt_layer(g_camera_cntx.base_layer_handle, g_camera_cntx.add_frame_layer_handle, 0, 0);
        }
        else
        {
            gdi_layer_set_blt_layer(g_camera_cntx.base_layer_handle, 0, 0, 0);
        }
        
#if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)
        hide_status_icon_bar(0);
#endif 
    }
    
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_set_key_hdlr
* DESCRIPTION
*  set key handler
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_preview_set_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_KEY);
    ClearKeyEvents();
    /* register soft keys */
    SetKeyHandler(mmi_camera_preview_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_preview_lsk_release, KEY_LSK, KEY_EVENT_UP);
    
    SetKeyHandler(mmi_camera_preview_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_preview_rsk_release, KEY_RSK, KEY_EVENT_UP);
    
#ifdef __CAMERA_AUTOFOCUS__
    SetKeyHandler(mmi_camera_capture_button_autofocus_pressed, CAMERA_CAPTURE_KEY, KEY_HALF_PRESS_DOWN);
    SetKeyHandler(mmi_camera_capture_button_autofocus_released, CAMERA_CAPTURE_KEY, KEY_HALF_PRESS_UP);
#ifdef __MMI_CAMERA_AF_TEST__
    /* 50 cont shot */
    SetKeyHandler(mmi_camera_af_test, KEY_9, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_capture_button_autofocus_pressed, KEY_1, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_dummy_func, KEY_1, KEY_EVENT_REPEAT);
    SetKeyHandler(mmi_camera_capture_button_autofocus_released, KEY_1, KEY_EVENT_UP);
    SetKeyHandler(mmi_camera_af_and_capture, KEY_0, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_dummy_func, KEY_0, KEY_EVENT_REPEAT);
    SetKeyHandler(mmi_camera_capture_button_autofocus_released, KEY_0, KEY_EVENT_UP);
#endif /* __MMI_CAMERA_AF_TEST__ */ 
#endif /* __CAMERA_AUTOFOCUS__ */ 
    
    /*************************************/
    /* Normal Key                        */
    /*************************************/
    
    /* change add frame hotkey - side keys */
#ifdef __CAMERA_FEATURE_ADD_FRAME__
    SetKeyHandler(mmi_camera_preview_change_frame_up, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_preview_change_frame_down, KEY_VOL_DOWN, KEY_EVENT_DOWN);
#endif /* __CAMERA_FEATURE_ADD_FRAME__ */ 
    
    /* register capture and control keys */
    if (CAMERA_CAPTURE_KEY != -1)
    {
#ifdef __AF_SUPPORT_ONE_KEY__
        SetKeyHandler(mmi_camera_af_and_capture, CAMERA_CAPTURE_KEY, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_dummy_func, CAMERA_CAPTURE_KEY, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_camera_capture_button_autofocus_released, CAMERA_CAPTURE_KEY, KEY_EVENT_UP);
#else
        SetKeyHandler(mmi_camera_capture_button_press, CAMERA_CAPTURE_KEY, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_dummy_func, CAMERA_CAPTURE_KEY, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_camera_capture_button_release, CAMERA_CAPTURE_KEY, KEY_EVENT_UP);
#endif
    }
    
    if (CAMERA_CAPTURE_EXTRA_KEY1 != -1)
    {
        SetKeyHandler(mmi_camera_capture_button_press, (U16)CAMERA_CAPTURE_EXTRA_KEY1, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY1, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_camera_capture_button_release, (U16)CAMERA_CAPTURE_EXTRA_KEY1, KEY_EVENT_UP);
    }
    
    if (CAMERA_CAPTURE_EXTRA_KEY2 != -1)
    {
        SetKeyHandler(mmi_camera_capture_button_press, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_LONG_PRESS);
        SetKeyHandler(mmi_camera_capture_button_release, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_UP);
    }
    
    
    
#if !defined(__MMI_CAMERA_DIRECT_SENSOR_SUPPORT__)
    /* ev / zooming */
    if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_90 || g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270)
    {
        SetKeyHandler(mmi_camera_preview_ev_inc_key_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_preview_ev_inc_key_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
        
        SetKeyHandler(mmi_camera_preview_ev_dec_key_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_preview_ev_dec_key_release, KEY_UP_ARROW, KEY_EVENT_UP);
    }
    else
    {
        SetKeyHandler(mmi_camera_preview_ev_inc_key_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_preview_ev_inc_key_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
        
        SetKeyHandler(mmi_camera_preview_ev_dec_key_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_preview_ev_dec_key_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
    }
#endif
    
#ifdef __CAMERA_FEATURE_ZOOM__
    if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_90 || g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270)
    {
        SetKeyHandler(mmi_camera_preview_down_arrow_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_preview_down_arrow_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
        
        SetKeyHandler(mmi_camera_preview_up_arrow_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_preview_up_arrow_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    }
    else
    {
        SetKeyHandler(mmi_camera_preview_down_arrow_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_preview_down_arrow_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
        
        SetKeyHandler(mmi_camera_preview_up_arrow_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_preview_up_arrow_release, KEY_UP_ARROW, KEY_EVENT_UP);
    }
#endif /* __CAMERA_FEATURE_ZOOM__ */ 
    
    /* hot keys */
#ifdef __CAMERA_FEATURE_EFFECT__
    if (CAMERA_EFFECT_KEY != -1)
    {
        SetKeyHandler(mmi_camera_preview_effect_hotkey_press, (U16) CAMERA_EFFECT_KEY, KEY_EVENT_DOWN);
    }
#endif /* __CAMERA_FEATURE_EFFECT__ */ 
    
#ifdef __CAMERA_FEATURE_WB__
    if (CAMERA_WB_KEY != -1)
    {
        SetKeyHandler(mmi_camera_preview_wb_hotkey_press, (U16) CAMERA_WB_KEY, KEY_EVENT_DOWN);
    }
#endif /* __CAMERA_FEATURE_WB__ */ 
    
#ifdef __CAMERA_FEATURE_NIGHT__
    if (CAMERA_NIGHT_KEY != -1)
    {
        SetKeyHandler(mmi_camera_preview_night_hotkey_press, (U16) CAMERA_NIGHT_KEY, KEY_EVENT_DOWN);
    }
#endif /* __CAMERA_FEATURE_NIGHT__ */ 
    
#ifdef __CAMERA_FEATURE_LED_HIGHLIGHT__
    if (CAMERA_LED_HIGHLIGHT_KEY != -1)
    {
        SetKeyHandler(mmi_camera_preview_led_highlight_hotkey_press, (U16) CAMERA_LED_HIGHLIGHT_KEY, KEY_EVENT_DOWN);
    }
#endif /* __CAMERA_FEATURE_LED_HIGHLIGHT__ */ 
    
#ifdef __CAMERA_FEATURE_FLASH__
    if (CAMERA_FLASH_KEY != -1)
    {
        SetKeyHandler(mmi_camera_preview_flash_hotkey_press, (U16) CAMERA_FLASH_KEY, KEY_EVENT_DOWN);
    }
#endif /* __CAMERA_FEATURE_FLASH__ */ 
    
#ifdef __CAMERA_FEATURE_CONT_SHOT__
    if (g_camera_cntx.external_request_mode == MMI_CAMERA_EXTERNAL_MODE_OFF)
    {
        if (CAMERA_CONT_SHOT_KEY != -1)
        {
            SetKeyHandler(mmi_camera_preview_cont_shot_hotkey_press, (U16) CAMERA_CONT_SHOT_KEY, KEY_EVENT_DOWN);
        }
    }
#endif /* __CAMERA_FEATURE_CONT_SHOT__ */ 
    
#ifdef __CAMERA_FEATURE_DELAY_TIMER__
    if (CAMERA_DELAY_TIMER_KEY != -1)
    {
        SetKeyHandler(mmi_camera_preview_delay_timer_hotkey_press, (U16) CAMERA_DELAY_TIMER_KEY, KEY_EVENT_DOWN);
    }
#endif /* __CAMERA_FEATURE_DELAY_TIMER__ */ 
    
    if (g_camera_cntx.external_request_mode != MMI_CAMERA_EXTERNAL_MODE_LARGEST_RESOLUTION)
    {
        if (CAMERA_IMAGE_SIZE_KEY != -1)
        {
            SetKeyHandler(mmi_camera_preview_image_size_hotkey_press, (U16) CAMERA_IMAGE_SIZE_KEY, KEY_EVENT_DOWN);
        }
    }
    
    if (CAMERA_IMAGE_QTY_KEY != -1)
    {
        SetKeyHandler(mmi_camera_preview_image_qty_hotkey_press, (U16) CAMERA_IMAGE_QTY_KEY, KEY_EVENT_DOWN);
    }
    
#ifdef __CAMERA_DSC_MODE__
    if (CAMERA_DSC_MODE_KEY != -1)
    {
        SetKeyHandler(mmi_camera_preview_dsc_mode_hotkey_press, (U16) CAMERA_DSC_MODE_KEY, KEY_EVENT_DOWN);
    }
#endif /* __CAMERA_DSC_MODE__ */ 
    
#ifdef __CAMERA_FEATURE_ISO_SUPPORT__
    if (CAMERA_ISO_KEY != -1)
    {
        SetKeyHandler(mmi_camera_preview_iso_hotkey_press, (U16) CAMERA_ISO_KEY, KEY_EVENT_DOWN);
    }
#endif /* __CAMERA_FEATURE_ISO_SUPPORT__ */ 
    
#ifdef __CAMERA_FEATURE_AE_METER__
    if (CAMERA_AE_METER_KEY != -1)
    {
        SetKeyHandler(mmi_camera_preview_ae_meter_hotkey_press, (U16) CAMERA_AE_METER_KEY, KEY_EVENT_DOWN);
    }
#endif /* __CAMERA_FEATURE_AE_METER__ */ 
    
#ifdef __CAMERA_FEATURE_STORAGE__
    if (CAMERA_STORAGE_KEY != -1)
    {
        SetKeyHandler(mmi_camera_preview_storage_hotkey_press, (U16) CAMERA_STORAGE_KEY, KEY_EVENT_DOWN);
    }
#endif /* __CAMERA_FEATURE_STORAGE__ */ 
    
#ifdef __CAMERA_AUTOFOCUS_METERING__
    if (CAMERA_AF_METER_KEY != -1)
    {
        SetKeyHandler(mmi_camera_preview_af_meter_hotkey_press, (U16) CAMERA_AF_METER_KEY, KEY_EVENT_DOWN);
    }
#endif 
    
#ifdef __CAMERA_AUTOFOCUS_MODE__
    if (CAMERA_AF_MODE_KEY != -1)
    {
        SetKeyHandler(mmi_camera_preview_af_mode_hotkey_press, (U16) CAMERA_AF_MODE_KEY, KEY_EVENT_DOWN);
    }
#endif
    
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
    SetKeyHandler(mmi_camera_toggle_self_capture, (U16) CAMERA_TOGGLE_SELF_CAPTURE_KEY, KEY_EVENT_DOWN);
#endif 
    
    if (CAMERA_TOGGLE_HIDE_OSD_KEY != -1)
    {
        /* toggle hide OSD */
        SetKeyHandler(mmi_camera_toggle_hide_osd, (U16) CAMERA_TOGGLE_HIDE_OSD_KEY, KEY_EVENT_DOWN);
    }
    
#ifdef __MMI_CAMERA_RECORDER_ONE_KEY_TOGGLE__
    if (CAMERA_SWITCH_TO_VDOREC_KEY != -1 && g_camera_cntx.external_request_mode == MMI_CAMERA_EXTERNAL_MODE_OFF)
    {
        SetKeyHandler(mmi_camera_switch_to_vdorec_app, CAMERA_SWITCH_TO_VDOREC_KEY, KEY_EVENT_DOWN);
    }
#endif /* #ifdef __MMI_CAMERA_RECORDER_ONE_KEY_TOGGLE__ */
}

#if defined(__MMI_CAMERA_BG_CALL__)
/*****************************************************************************
* FUNCTION
*  mmi_camera_incall_set_key_hdlr
* DESCRIPTION
*  set key handler
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_incall_popup_error(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_CAMERA_DISPLAY_POPUP((PU8) GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL), MMI_EVENT_FAILURE);
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_incall_set_key_hdlr
* DESCRIPTION
*  set key handler
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_incall_set_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_KEY);
    ClearKeyEvents();
    /* register soft keys */
    SetKeyHandler(mmi_camera_preview_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_preview_lsk_release, KEY_LSK, KEY_EVENT_UP);
    
    SetKeyHandler(mmi_camera_preview_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_preview_rsk_release, KEY_RSK, KEY_EVENT_UP);
    
    SetKeyHandler(mmi_camera_incall_popup_error, CAMERA_CAPTURE_KEY, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_dummy_func, CAMERA_CAPTURE_KEY, KEY_EVENT_UP);    
    
    SetKeyHandler(mmi_camera_incall_popup_error, KEY_ENTER, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_dummy_func, KEY_ENTER, KEY_EVENT_UP);    
    
    if (CAMERA_CAPTURE_EXTRA_KEY1 != -1)
    {
        SetKeyHandler(mmi_camera_incall_popup_error, (U16)CAMERA_CAPTURE_EXTRA_KEY1, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY1, KEY_EVENT_UP);    
    }
    
    if (CAMERA_CAPTURE_EXTRA_KEY2 != -1)
    {
        SetKeyHandler(mmi_camera_incall_popup_error, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_UP);        
    }
}
#endif /* __MMI_CAMERA_BG_CALL__ */

#ifdef __CAMERA_AUTOFOCUS__

/*****************************************************************************
* FUNCTION
*  mmi_camera_play_af_succeed_finished
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_play_af_succeed_finished(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.is_audio_finished = TRUE;
    
    /* check if af is calculating by user half press soon after af callback,
    if no, reset is_autofocus_pressed flag , 2007/10/31 */
    if (g_camera_cntx.af_state != AF_CALCULATE)
        g_camera_cntx.is_autofocus_pressed = FALSE;    
    
    if (g_camera_cntx.is_af_capture == TRUE)
    {
        g_camera_cntx.is_af_capture = FALSE;
        mmi_camera_capture_button_press();
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_autofocus_callback
* DESCRIPTION
*  callback while AF is succeed/fail
* PARAMETERS
*  result      [IN]        
*  void(?)     [OUT]       PMsg
* RETURNS
*  void
*****************************************************************************/
void mmi_camera_autofocus_callback(mdi_camera_af_result_struct result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* parse pMsg to get result */
    /* and response to osd layer */
    if (g_camera_cntx.af_state == AF_CANCEL)
    {
        return;
    }
    
#if !defined(MT6238) && !defined(MT6239)
    g_camera_cntx.af_result = (U8) result;
#else
    g_camera_cntx.af_result = (U8) result.af_result;
#endif
    if (g_camera_cntx.app_state != CAMERA_STATE_EXIT)
    {
        if (g_camera_cntx.af_result == 0xFF)
        {
            g_camera_cntx.af_state = AF_FAIL;
            /* send cancel command to driver to stop cal focus */
            gui_cancel_timer(mmi_camera_preview_draw_osd_timer);
            
            mmi_camera_preview_draw_osd();
            mmi_camera_blt();
            
            if (g_camera_cntx.is_af_capture == TRUE)
            {
                g_camera_cntx.is_af_capture = FALSE;
                mmi_camera_capture_button_press();
            }
            
            /* reset is_autofocus_pressed flag */
            g_camera_cntx.is_autofocus_pressed = FALSE;
            
        }
        else
        {
            g_camera_cntx.af_state = AF_SUCCEED;
            
            /* send cancel command to driver to stop cal focus */
            gui_cancel_timer(mmi_camera_preview_draw_osd_timer);
            mmi_camera_preview_draw_osd();
            mmi_camera_blt();
            
            {   /* play sound tmp */
                
                BEFORE_PLAY_AUDIO();
                if (!MMI_CAMERA_IS_SILENT_MODE() && g_camera_cntx.setting.shutter_sound != CAMERA_SETTING_SHUTTER_SOUND_OFF)
                {
#if defined(__MMI_CAMERA_HIGH_END__)
                    mdi_audio_play_string_with_vol_path(
                        (void*)camera_af_succeed,
                        (U32) CAMERA_SOUND_AF_SUCCEED_LEN,
                        MDI_FORMAT_WAV,
                        DEVICE_AUDIO_PLAY_ONCE,
                        NULL,
                        (mdi_callback) mmi_camera_play_af_succeed_finished,
                        CAMERA_SHUTTER_SOUND_VOLUMN,
                        MDI_DEVICE_SPEAKER_BOTH);
#else /* __MMI_CAMERA_HIGH_END__ */ 
                    mdi_audio_play_string_with_vol_path(
                        (void*)camera_sound_shutter_3,
                        (U32) CAMERA_SOUND_SHUTTER_3_LEN,
                        MDI_FORMAT_DVI_ADPCM,
                        DEVICE_AUDIO_PLAY_ONCE,
                        NULL,
                        (mdi_callback) mmi_camera_play_af_succeed_finished,
                        CAMERA_SHUTTER_SOUND_VOLUMN,
                        MDI_DEVICE_SPEAKER_BOTH);
#endif /* __MMI_CAMERA_HIGH_END__ */ 
                }
                else
                {
                    mmi_camera_play_af_succeed_finished();
                }
            }
        }
    }
}

#ifdef __MMI_CAMERA_AF_TEST__


/*****************************************************************************
* FUNCTION
*  mmi_camera_af_test
* DESCRIPTION
*  press AF button
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_af_test()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.setting.cont_shot = CAMERA_SETTING_CONT_SHOT_1;
    g_camera_cntx.cont_shot_total_count = 50;
    g_camera_cntx.cont_shot_count = 0;
    g_camera_cntx.is_af_test = TRUE;
    
    mmi_camera_af_test_start();
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_af_test_start
* DESCRIPTION
*  press AF button
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_af_test_start()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.is_autofocus_pressed = TRUE;
    g_camera_cntx.af_state = AF_CALCULATE;
    g_camera_cntx.af_animation_process = AF_ANIMATION_STEP1;
    
    /* send command to driver to start cal focus */
    mdi_camera_start_autofocus_process((mdi_callback) mmi_camera_autofocus_callback);
    
    /* draw animation for focus process */
    g_camera_cntx.is_draw_timer_on = TRUE;
    gui_start_timer(100, mmi_camera_preview_draw_osd_timer);
    
    mmi_camera_preview_draw_osd();
    mmi_camera_blt();
    mmi_camera_capture_button_press();
}
#endif /* __MMI_CAMERA_AF_TEST__ */ 

#if defined(__AF_SUPPORT_ONE_KEY__) || defined(__MMI_CAMERA_AF_TEST__)
/*****************************************************************************
* FUNCTION
*  mmi_camera_af_and_capture
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_af_and_capture(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camera_capture_button_autofocus_pressed();
    mmi_camera_capture_button_press();
}
#endif


/*****************************************************************************
* FUNCTION
*  mmi_camera_capture_button_autofocus_pressed
* DESCRIPTION
*  press AF button
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_capture_button_autofocus_pressed()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__
    mmi_camera_stop_app_watchdog();
#endif
    
    if (mdi_camera_is_ready_to_capture() == TRUE && g_camera_cntx.af_state != AF_CALCULATE)
    {
        g_camera_cntx.is_autofocus_pressed = TRUE;
        g_camera_cntx.af_state = AF_CALCULATE;
        g_camera_cntx.af_animation_process = AF_ANIMATION_STEP1;
        
        /* send command to driver to start cal focus */
        mdi_camera_start_autofocus_process((mdi_camera_af_ind_callback) mmi_camera_autofocus_callback);
        
        /* clear key handler */
        ClearInputEventHandler(MMI_DEVICE_KEY);
        
        SetKeyHandler(mmi_camera_preview_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_preview_lsk_release, KEY_LSK, KEY_EVENT_UP);
        
        SetKeyHandler(mmi_camera_preview_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_preview_rsk_release, KEY_RSK, KEY_EVENT_UP);
        
#ifdef __CAMERA_AUTOFOCUS__
        SetKeyHandler(mmi_camera_dummy_func, CAMERA_CAPTURE_KEY, KEY_HALF_PRESS_DOWN);
        SetKeyHandler(mmi_camera_capture_button_autofocus_released, CAMERA_CAPTURE_KEY, KEY_HALF_PRESS_UP);
        
        SetKeyHandler(mmi_camera_dummy_func, KEY_9, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_capture_button_autofocus_released, KEY_9, KEY_EVENT_UP);
#endif /* __CAMERA_AUTOFOCUS__ */ 
        
        /* register capture and control keys */
        if (CAMERA_CAPTURE_KEY != -1)
        {
            SetKeyHandler(mmi_camera_capture_button_press, CAMERA_CAPTURE_KEY, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camera_dummy_func, CAMERA_CAPTURE_KEY, KEY_EVENT_REPEAT);
            SetKeyHandler(mmi_camera_capture_button_release, CAMERA_CAPTURE_KEY, KEY_EVENT_UP);
        }
        
        if (CAMERA_CAPTURE_EXTRA_KEY1 != -1)
        {
            SetKeyHandler(mmi_camera_capture_button_press, (U16)CAMERA_CAPTURE_EXTRA_KEY1, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY1, KEY_EVENT_REPEAT);
            SetKeyHandler(mmi_camera_capture_button_release, (U16)CAMERA_CAPTURE_EXTRA_KEY1, KEY_EVENT_UP);
        }
        
        if (CAMERA_CAPTURE_EXTRA_KEY2 != -1)
        {
            SetKeyHandler(mmi_camera_capture_button_press, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_REPEAT);
            SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_LONG_PRESS);
            SetKeyHandler(mmi_camera_capture_button_release, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_UP);
        }
        
        
        /* draw animation for focus process */
        g_camera_cntx.is_draw_timer_on = TRUE;
        gui_start_timer(100, mmi_camera_preview_draw_osd_timer);
        
        mmi_camera_preview_draw_osd();
        mmi_camera_blt();
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_capture_button_autofocus_released
* DESCRIPTION
*  release AF button
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_capture_button_autofocus_released()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_camera_cntx.is_af_capture == FALSE)
    {
        
#ifdef __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__
        mmi_camera_restart_app_watchdog();
#endif
        g_camera_cntx.is_autofocus_pressed = FALSE;
        mdi_camera_stop_autofocus_process();
        
        g_camera_cntx.af_state = AF_CANCEL;
        
        /* register key */
        mmi_camera_preview_set_key_hdlr();
        
        /* send cancel command to driver to stop cal focus */
        gui_cancel_timer(mmi_camera_preview_draw_osd_timer);
        g_camera_cntx.is_draw_timer_on = FALSE;
        
        /* draw animation for stopping focus process */
        mmi_camera_preview_draw_osd();
        mmi_camera_blt();
    }
    
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_draw_bolder_rect
* DESCRIPTION
*  draw rect with bolder
* PARAMETERS
*  x1                  [IN]        Start x
*  y1                  [IN]        Start y
*  x2                  [IN]        End x
*  y2                  [IN]        End y
*  bolder_width        [IN]        Width of bolder
*  frame_color         [IN]        
*  gdi_color(?)        [IN]        Color of bolder
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_draw_bolder_rect(S32 x1, S32 y1, S32 x2, S32 y2, S32 bolder_width, gdi_color frame_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
    S32 offset_x = 0;
    S32 offset_y = 0;
#endif /* __MMI_CAMERA_5_OSD_LAYER__ */ 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_CAMERA_5_OSD_LAYER__)
    if (g_camera_cntx.is_single_osd_layer == FALSE)
    {
        offset_x = g_camera_cntx.active_camera_osd_ptr->osd_region3.offset_x;
        offset_y = g_camera_cntx.active_camera_osd_ptr->osd_region3.offset_y;
    }
    x1 -= offset_x;
    x2 -= offset_x;
    y1 -= offset_y;
    y2 -= offset_y;
#elif defined(__MMI_CAMERA_3_OSD_LAYER__)
    if (g_camera_cntx.is_single_osd_layer == FALSE)
    {
        offset_x = g_camera_cntx.active_camera_osd_ptr->osd_region2.offset_x;
        offset_y = g_camera_cntx.active_camera_osd_ptr->osd_region2.offset_y;
    }
    x1 -= offset_x;
    x2 -= offset_x;
    y1 -= offset_y;
    y2 -= offset_y;
#endif /* __MMI_CAMERA_5_OSD_LAYER__ */ 
    gdi_draw_rect(x1 - bolder_width, y1 - bolder_width, x2 + bolder_width, y2 + bolder_width, frame_color);
    gdi_draw_rect(x1 + bolder_width, y1 + bolder_width, x2 - bolder_width, y2 - bolder_width, frame_color);
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_draw_autofocus_process
* DESCRIPTION
*  draw AF related OSD
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_draw_autofocus_process()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* U16 image_id = 0; */
    U16 af_x = 0;
    U16 af_y = 0;
    U16 af_width = 0;
    gdi_color af_color = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_CAMERA_5_OSD_LAYER__)
    if (g_camera_cntx.is_single_osd_layer == FALSE)
    {
        gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle4);
    }
#elif defined(__MMI_CAMERA_3_OSD_LAYER__)
    if (g_camera_cntx.is_single_osd_layer == FALSE)
    {
        gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle2);
    }
#endif /* __MMI_CAMERA_5_OSD_LAYER__ */ 
    
    switch (g_camera_cntx.af_state)
    {
    case AF_CALCULATE:
        
        if (g_camera_cntx.is_manual_autofocus == FALSE)
        {
            if (g_camera_cntx.af_animation_process == AF_ANIMATION_END)
            {
                g_camera_cntx.af_animation_process = AF_ANIMATION_STEP1;
            }
            
            switch (g_camera_cntx.setting.af_meter)
            {
#ifdef __CAMERA_AUTOFOCUS_5_ZONE__
            case CAMERA_SETTING_AUTOFOCUS_5_ZONE:
                switch (g_camera_cntx.af_animation_process)
                {
                case AF_ANIMATION_STEP1:
                    af_color = GDI_COLOR_WHITE;
                    break;
                case AF_ANIMATION_STEP2:
                    af_color = GDI_COLOR_GRAY;
                    break;
                case AF_ANIMATION_STEP3:
                    af_color = GDI_COLOR_BLACK;
                    break;
                }
                
                af_width = CAMERA_AF_SMALL_WIDTH;
                af_x = g_camera_cntx.af_zone0_x - af_width / 2;
                af_y = g_camera_cntx.af_zone0_y - af_width / 2;
                mmi_camera_draw_bolder_rect(af_x, af_y, af_x + af_width - 1, af_y + af_width - 1, 1, af_color);
                af_x = g_camera_cntx.af_zone1_x - af_width / 2;
                af_y = g_camera_cntx.af_zone1_y - af_width / 2;
                mmi_camera_draw_bolder_rect(af_x, af_y, af_x + af_width - 1, af_y + af_width - 1, 1, af_color);
                af_x = g_camera_cntx.af_zone2_x - af_width / 2;
                af_y = g_camera_cntx.af_zone2_y - af_width / 2;
                mmi_camera_draw_bolder_rect(af_x, af_y, af_x + af_width - 1, af_y + af_width - 1, 1, af_color);
                af_x = g_camera_cntx.af_zone3_x - af_width / 2;
                af_y = g_camera_cntx.af_zone3_y - af_width / 2;
                mmi_camera_draw_bolder_rect(af_x, af_y, af_x + af_width - 1, af_y + af_width - 1, 1, af_color);
                af_x = g_camera_cntx.af_zone4_x - af_width / 2;
                af_y = g_camera_cntx.af_zone4_y - af_width / 2;
                mmi_camera_draw_bolder_rect(af_x, af_y, af_x + af_width - 1, af_y + af_width - 1, 1, af_color);
                break;
#endif /* __CAMERA_AUTOFOCUS_5_ZONE__ */ 
#ifdef __CAMERA_AUTOFOCUS_3_ZONE__
                case CAMERA_SETTING_AUTOFOCUS_3_ZONE:
                    switch (g_camera_cntx.af_animation_process)
                    {
                    case AF_ANIMATION_STEP1:
                        af_color = GDI_COLOR_WHITE;
                        break;
                    case AF_ANIMATION_STEP2:
                        af_color = GDI_COLOR_GRAY;
                        break;
                    case AF_ANIMATION_STEP3:
                        af_color = GDI_COLOR_BLACK;
                        break;
                    }
                    
                    af_width = CAMERA_AF_SMALL_WIDTH;
                    af_x = g_camera_cntx.af_zone0_x - af_width / 2;
                    af_y = g_camera_cntx.af_zone0_y - af_width / 2;
                    mmi_camera_draw_bolder_rect(af_x, af_y, af_x + af_width - 1, af_y + af_width - 1, 1, af_color);
                    af_x = g_camera_cntx.af_zone1_x - af_width / 2;
                    af_y = g_camera_cntx.af_zone1_y - af_width / 2;
                    mmi_camera_draw_bolder_rect(af_x, af_y, af_x + af_width - 1, af_y + af_width - 1, 1, af_color);
                    af_x = g_camera_cntx.af_zone2_x - af_width / 2;
                    af_y = g_camera_cntx.af_zone2_y - af_width / 2;
                    mmi_camera_draw_bolder_rect(af_x, af_y, af_x + af_width - 1, af_y + af_width - 1, 1, af_color);
                    break;
#endif /* __CAMERA_AUTOFOCUS_3_ZONE__ */ 
#ifdef __CAMERA_AUTOFOCUS_1_ZONE__
                    case CAMERA_SETTING_AUTOFOCUS_1_ZONE:
                        {
                            switch (g_camera_cntx.af_animation_process)
                            {
                            case AF_ANIMATION_STEP1:
                                af_width = CAMERA_AF_LARGE_WIDTH;
                                af_color = GDI_COLOR_WHITE;
                                break;
                            case AF_ANIMATION_STEP2:
                                af_color = GDI_COLOR_GRAY;
                                af_width = CAMERA_AF_NORMAL_WIDTH;
                                break;
                            case AF_ANIMATION_STEP3:
                                af_color = GDI_COLOR_BLACK;
                                af_width = CAMERA_AF_SMALL_WIDTH;
                                break;
                            }
                            
                            af_x = g_camera_cntx.af_zone0_x - af_width / 2;
                            af_y = g_camera_cntx.af_zone0_y - af_width / 2;
                            mmi_camera_draw_bolder_rect(
                                af_x,
                                af_y,
                                af_x + af_width - 1,
                                af_y + af_width - 1,
                                1,
                                GDI_COLOR_WHITE);
                        }
                        break;
#endif /* __CAMERA_AUTOFOCUS_1_ZONE__ */ 
                    default:
                        break;
            }
            g_camera_cntx.af_animation_process++;
            }
            else
            {
                
            }
            
            break;
        case AF_SUCCEED:
            switch (g_camera_cntx.setting.af_meter)
            {
#ifdef __CAMERA_AUTOFOCUS_5_ZONE__
            case CAMERA_SETTING_AUTOFOCUS_5_ZONE:
                af_width = CAMERA_AF_SMALL_WIDTH;
                if (g_camera_cntx.af_result & 0x01)
                {
                    af_x = g_camera_cntx.af_zone0_x;
                    af_y = g_camera_cntx.af_zone0_y;
                    af_x -= af_width / 2;
                    af_y -= af_width / 2;
                    mmi_camera_draw_bolder_rect(
                        af_x,
                        af_y,
                        af_x + af_width - 1,
                        af_y + af_width - 1,
                        1,
                        GDI_COLOR_GREEN);
                }
                if (g_camera_cntx.af_result & 0x02)
                {
                    af_x = g_camera_cntx.af_zone1_x;
                    af_y = g_camera_cntx.af_zone1_y;
                    af_x -= af_width / 2;
                    af_y -= af_width / 2;
                    mmi_camera_draw_bolder_rect(
                        af_x,
                        af_y,
                        af_x + af_width - 1,
                        af_y + af_width - 1,
                        1,
                        GDI_COLOR_GREEN);
                }
                if (g_camera_cntx.af_result & 0x04)
                {
                    af_x = g_camera_cntx.af_zone2_x;
                    af_y = g_camera_cntx.af_zone2_y;
                    af_x -= af_width / 2;
                    af_y -= af_width / 2;
                    mmi_camera_draw_bolder_rect(
                        af_x,
                        af_y,
                        af_x + af_width - 1,
                        af_y + af_width - 1,
                        1,
                        GDI_COLOR_GREEN);
                }
                if (g_camera_cntx.af_result & 0x08)
                {
                    af_x = g_camera_cntx.af_zone3_x;
                    af_y = g_camera_cntx.af_zone3_y;
                    af_x -= af_width / 2;
                    af_y -= af_width / 2;
                    mmi_camera_draw_bolder_rect(
                        af_x,
                        af_y,
                        af_x + af_width - 1,
                        af_y + af_width - 1,
                        1,
                        GDI_COLOR_GREEN);
                }
                if (g_camera_cntx.af_result & 0x10)
                {
                    af_x = g_camera_cntx.af_zone4_x;
                    af_y = g_camera_cntx.af_zone4_y;
                    af_x -= af_width / 2;
                    af_y -= af_width / 2;
                    mmi_camera_draw_bolder_rect(
                        af_x,
                        af_y,
                        af_x + af_width - 1,
                        af_y + af_width - 1,
                        1,
                        GDI_COLOR_GREEN);
                }
                break;
#endif /* __CAMERA_AUTOFOCUS_5_ZONE__ */ 
#ifdef __CAMERA_AUTOFOCUS_3_ZONE__
            case CAMERA_SETTING_AUTOFOCUS_3_ZONE:
                af_width = CAMERA_AF_SMALL_WIDTH;
                
                if (g_camera_cntx.af_result & 0x01)
                {
                    af_x = g_camera_cntx.af_zone0_x;
                    af_y = g_camera_cntx.af_zone0_y;
                    af_x -= af_width / 2;
                    af_y -= af_width / 2;
                    mmi_camera_draw_bolder_rect(
                        af_x,
                        af_y,
                        af_x + af_width - 1,
                        af_y + af_width - 1,
                        1,
                        GDI_COLOR_GREEN);
                }
                if (g_camera_cntx.af_result & 0x02)
                {
                    af_x = g_camera_cntx.af_zone1_x;
                    af_y = g_camera_cntx.af_zone1_y;
                    af_x -= af_width / 2;
                    af_y -= af_width / 2;
                    mmi_camera_draw_bolder_rect(
                        af_x,
                        af_y,
                        af_x + af_width - 1,
                        af_y + af_width - 1,
                        1,
                        GDI_COLOR_GREEN);
                }
                if (g_camera_cntx.af_result & 0x04)
                {
                    af_x = g_camera_cntx.af_zone2_x;
                    af_y = g_camera_cntx.af_zone2_y;
                    af_x -= af_width / 2;
                    af_y -= af_width / 2;
                    mmi_camera_draw_bolder_rect(
                        af_x,
                        af_y,
                        af_x + af_width - 1,
                        af_y + af_width - 1,
                        1,
                        GDI_COLOR_GREEN);
                }
                break;
#endif /* __CAMERA_AUTOFOCUS_3_ZONE__ */ 
#ifdef __CAMERA_AUTOFOCUS_1_ZONE__
            case CAMERA_SETTING_AUTOFOCUS_1_ZONE:
                {
                    af_width = CAMERA_AF_SMALL_WIDTH;
                    
                    af_x = g_camera_cntx.af_zone0_x - af_width / 2;
                    af_y = g_camera_cntx.af_zone0_y - af_width / 2;
                    mmi_camera_draw_bolder_rect(
                        af_x,
                        af_y,
                        af_x + af_width - 1,
                        af_y + af_width - 1,
                        1,
                        GDI_COLOR_GREEN);
                }
                break;
#endif /* __CAMERA_AUTOFOCUS_1_ZONE__ */ 
            default:
                ASSERT(0);
                break;
            }
            
            break;
        case AF_FAIL:
            af_width = CAMERA_AF_SMALL_WIDTH;
            
            af_x = g_camera_cntx.af_zone0_x - af_width / 2;
            af_y = g_camera_cntx.af_zone0_y - af_width / 2;
            mmi_camera_draw_bolder_rect(af_x, af_y, af_x + af_width - 1, af_y + af_width - 1, 1, GDI_COLOR_RED);
            
            break;
        case AF_CANCEL:
            break;
            
 }
 
#if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
 if (g_camera_cntx.is_single_osd_layer == FALSE)
 {
     gdi_layer_pop_and_restore_active();
 }  
#endif /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 
}

#endif /* __CAMERA_AUTOFOCUS__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_create_preview_resource
* DESCRIPTION
*  free main lcd's preview layer resource
* PARAMETERS
*  offset_x        [IN]        Preview layer offset x
*  offset_y        [IN]        Preview layer offset y
*  width           [IN]        Preview layer width
*  height          [IN]        Preview_layer height
*  rotate          [IN]        Lcm rotate
* RETURNS
*  void
*****************************************************************************/
void mmi_camera_preview_create_preview_resource(S32 offset_x, S32 offset_y, S32 width, S32 height, U8 rotate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 buf_ptr;
    S32 buf_size;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(width * height <= LCD_WIDTH * LCD_HEIGHT);
    
    gdi_layer_push_and_set_active(g_camera_cntx.base_layer_handle);
    gdi_layer_get_buffer_ptr(&buf_ptr);
    
    buf_size = ((width * height * GDI_MAINLCD_BIT_PER_PIXEL) >> 3);
    gdi_layer_create_using_outside_memory(
        0,
        0,
        width,
        height,
        &g_camera_cntx.preview_layer_handle,
        (PU8) buf_ptr,
        buf_size);
    
#ifdef __MMI_CAMERA_DIRECT_SENSOR_SUPPORT__
    //g_camera_cntx.direct_couple_buffer = buf_ptr + offset_y * width * 2;
#endif

    gdi_layer_set_active(g_camera_cntx.preview_layer_handle);
#ifdef GDI_USING_LAYER_BACKGROUND
    gdi_layer_set_background(GDI_COLOR_BLACK);
#endif 
    gdi_layer_set_position(offset_x, offset_y);
    
    /*@ Add by Vincent */
    /* if using idp rotate, we need to config preview layer as vertical */
#if defined(__CAMERA_OSD_HORIZONTAL__) && defined(__MDI_CAMERA_HW_ROTATOR_SUPPORT__)
    
#ifdef __MDI_CAMERA_HW_ROTATOR_BY_LCD__
    gdi_layer_set_rotate(GDI_LAYER_ROTATE_90);
#else
    kal_wap_trace(MOD_MMI, TRACE_GROUP_3, "[cam][6253] 3) resize preview layer (%d,%d)",height,width);
    gdi_layer_resize(height, width);
    kal_wap_trace(MOD_MMI, TRACE_GROUP_3, "[cam][6253] 4) set preview offset_x/offset_y==(%d,%d)",LCD_WIDTH-height-offset_y,offset_x);
    gdi_layer_set_position(LCD_WIDTH-height-offset_y,offset_x);
#endif

#elif defined(__CAMERA_OSD_HORIZONTAL__)
    
    gdi_layer_set_rotate(GDI_LAYER_ROTATE_90);
    
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) && defined(__MDI_CAMERA_HW_ROTATOR_SUPPORT__) */
    
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_free_preview_resource
* DESCRIPTION
*  free main lcd's preview layer resource
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_camera_preview_free_preview_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_camera_cntx.preview_layer_handle == GDI_LAYER_EMPTY_HANDLE)
    {
        return;
    }
    gdi_layer_free(g_camera_cntx.preview_layer_handle);
    g_camera_cntx.preview_layer_handle = GDI_LAYER_EMPTY_HANDLE;
}


#ifdef __CAMERA_FEATURE_ADD_FRAME__
/*****************************************************************************
* FUNCTION
*  mmi_camera_create_add_frame_layer
* DESCRIPTION
*  create add frame layer resource
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_create_add_frame_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if ( g_camera_cntx.add_frame_layer_handle == GDI_LAYER_EMPTY_HANDLE
        &&((g_camera_cntx.is_fullscreen) && (g_camera_cntx.setting.add_frame != CAMERA_SETTING_ADD_FRAME_OFF) 
        ||(g_camera_cntx.setting.add_frame_tileshot != CAMERA_SETTING_ADD_FRAME_OFF)))
    {
        
        gdi_layer_create(0, 0, LCD_WIDTH, LCD_HEIGHT, &g_camera_cntx.add_frame_layer_handle);
        gdi_layer_push_and_set_active(g_camera_cntx.add_frame_layer_handle);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();
    }
    
    if ( g_camera_cntx.add_frame_layer_handle != GDI_LAYER_EMPTY_HANDLE )
    {
        /* update frame */
        mmi_camera_draw_add_frame();
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_free_add_frame_layer
* DESCRIPTION
*  create add frame layer resource
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_free_add_frame_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_camera_cntx.add_frame_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(g_camera_cntx.add_frame_layer_handle);
        g_camera_cntx.add_frame_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }
}
#endif /* __CAMERA_FEATURE_ADD_FRAME__ */ 

/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_create_resource
* DESCRIPTION
*  create main lcd's preview layer resource
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_preview_create_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_camera_cntx.is_mainlcd_resource == FALSE);
    /* if main lcd resoruce is not created */
    
    /************ base layer ************/
    /* get both MainLCD and SubLCD base handle */
    gdi_layer_get_base_handle(&g_camera_cntx.base_layer_handle);
    
    /* clear fullscreen */
    gdi_layer_clear(GDI_COLOR_BLACK);
#ifdef CAMERA_MODULE_WITH_LCD
    gdi_layer_set_source_key(FALSE, GDI_COLOR_TRANSPARENT);
#endif 
    
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
    /* make sublcd active and get it's base layer handle */
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_layer_get_base_handle(&g_camera_cntx.sublcd_base_layer_handle);
    
    gdi_layer_clear(GDI_COLOR_BLACK);
    
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 
    
    /************ frame layer ************/
#ifdef __CAMERA_FEATURE_ADD_FRAME__
    mmi_camera_create_add_frame_layer();
#endif /* __CAMERA_FEATURE_ADD_FRAME__ */ 
    
    
    /************ osd layer ************/
    /*currently in order to save memory, we will steal GDI memory, 
    NOTE : we only use the memory, but do not use the handle */
    if (g_camera_cntx.gdi_layer_handle == GDI_NULL_HANDLE)
    {
        gdi_layer_create(
            0,
            0,
            LCD_WIDTH,
            LCD_HEIGHT,
            &g_camera_cntx.gdi_layer_handle);
        gdi_layer_push_and_set_active(g_camera_cntx.gdi_layer_handle);
        gdi_layer_get_buffer_ptr(&g_camera_cntx.gdi_layer_buffer_ptr);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
    }
    /* steal done */

#if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
    mmi_camera_create_osd_layer();
    g_camera_cntx.is_mainlcd_resource = TRUE;
#else /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 
    /* create a double layer frame from outside memory */
    g_camera_cntx.osd_layer_buf_ptr0 = mmi_frm_scrmem_alloc_framebuffer(CAMERA_OSD_BUFFER_SIZE);
    ASSERT(g_camera_cntx.osd_layer_buf_ptr0 != NULL);
    
    gdi_layer_create_cf_double_using_outside_memory(
        GDI_COLOR_FORMAT_16,
        0,
        0,
        LCD_WIDTH,
        LCD_HEIGHT,
        &g_camera_cntx.osd_layer_handle0,
        (PU8) g_camera_cntx.osd_layer_buf_ptr0,
        (S32) CAMERA_OSD_BUFFER_SIZE,
        (PU8) g_camera_cntx.gdi_layer_buffer_ptr, 
        (S32) CAMERA_OSD_BUFFER_SIZE);
    
    gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle0);
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();
    
    /*@ Add by Vincent  */
#if defined(__MDI_CAMERA_HW_ROTATOR_SUPPORT__) && defined(__CAMERA_OSD_HORIZONTAL__)
    kal_wap_trace(MOD_MMI, TRACE_GROUP_3, "[cam][6253] create buffer for hw rotate, line:%d",__LINE__);
    
    gdi_layer_create_using_outside_memory(
        0,
        0,
        LCD_WIDTH,
        LCD_HEIGHT,
        &g_camera_cntx.osd_idp_rotate_layer_handle,
        (PU8)g_camera_cntx.app_mem_pool,
        CAMERA_OSD_BUFFER_SIZE);
    
    gdi_layer_push_and_set_active(g_camera_cntx.osd_idp_rotate_layer_handle);
    gdi_layer_get_buffer_ptr(&g_camera_cntx.osd_idp_rotate_ptr);
    ASSERT(g_camera_cntx.osd_idp_rotate_ptr != NULL);
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();
#endif
    
    
    g_camera_cntx.is_mainlcd_resource = TRUE;
    
#endif /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_free_resource
* DESCRIPTION
*  free main lcd's preview layer resource
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_preview_free_resource(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef CAMERA_MODULE_WITH_LCD
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
#endif 
    
    /****** free add frame layer ******/
#ifdef __CAMERA_FEATURE_ADD_FRAME__
    mmi_camera_free_add_frame_layer();
#endif /* __CAMERA_FEATURE_ADD_FRAME__ */ 
    
#if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
    mmi_camera_free_osd_layer();
#else /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 
    /****** free osd layer ******/
    if (g_camera_cntx.osd_layer_handle0 != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(g_camera_cntx.osd_layer_handle0);
        g_camera_cntx.osd_layer_handle0 = GDI_LAYER_EMPTY_HANDLE;
        
        mmi_frm_scrmem_free((void*)g_camera_cntx.osd_layer_buf_ptr0);
        g_camera_cntx.osd_layer_buf_ptr0 = NULL;
    }
#if defined(__MDI_CAMERA_HW_ROTATOR_SUPPORT__) && defined(__CAMERA_OSD_HORIZONTAL__)
    if (g_camera_cntx.osd_idp_rotate_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(g_camera_cntx.osd_idp_rotate_layer_handle);
        g_camera_cntx.osd_idp_rotate_layer_handle = GDI_LAYER_EMPTY_HANDLE;
        g_camera_cntx.osd_idp_rotate_ptr = NULL;
    }
#endif /* defined(__MDI_CAMERA_HW_ROTATOR_SUPPORT__) */
#endif /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 
    
    
    /* restore only base layer active */
    gdi_layer_set_blt_layer(g_camera_cntx.base_layer_handle, 0, 0, 0);
    
    g_camera_cntx.is_mainlcd_resource = FALSE;
    
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_start
* DESCRIPTION
*  start previewing of main lcd
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_preview_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_camera_setting_struct camera_setting_data;
    mdi_camera_preview_struct camera_preview_data;
    GDI_HANDLE preview_layer_handle = 0;
    U32 preview_layer_flag = 0;
    U32 blt_layer_flag = 0;
    S32 preview_wnd_offset_x = 0;
    S32 preview_wnd_offset_y = 0;
    U16 preview_wnd_width = 0;
    U16 preview_wnd_height = 0;
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* preview parametes */
    camera_setting_data.zoom = mmi_camera_preview_get_zoom_factor();
    camera_setting_data.wb = camera_wb_command_map[g_camera_cntx.setting.wb];
    camera_setting_data.manual_wb = FALSE;
    camera_setting_data.ev = camera_ev_command_map[g_camera_cntx.setting.ev];
    camera_setting_data.banding = camera_banding_command_map[g_camera_cntx.setting.banding];
    camera_setting_data.flash = camera_flash_command_map[g_camera_cntx.setting.flash];
    camera_setting_data.osd_rotate = g_camera_cntx.osd_rotate;
    camera_setting_data.night = g_camera_cntx.setting.night;
    
    camera_setting_data.iso = camera_iso_command_map[g_camera_cntx.setting.iso];
    camera_setting_data.ae_meter = camera_ae_meter_command_map[g_camera_cntx.setting.ae_meter];
    camera_setting_data.dsc_mode = camera_dsc_mode_command_map[g_camera_cntx.setting.dsc_mode];
    camera_setting_data.af_mode = camera_autofocus_mode_command_map[g_camera_cntx.setting.af_mode];
    camera_setting_data.af_metering_mode = camera_autofocus_command_map[g_camera_cntx.setting.af_meter];
    camera_setting_data.shutter_pri = 0;
    camera_setting_data.aperture_pri = 0;
    
#ifdef __CAMERA_FEATURE_XENON_FLASH__
    camera_setting_data.xenon_flash_status_callback = mmi_camera_xenon_flash_callback;
#else
    camera_setting_data.xenon_flash_status_callback = NULL;
#endif
    
    /* default effect */
    camera_setting_data.effect = camera_effect_command_map[g_camera_cntx.setting.effect];
    camera_setting_data.brightness = 128;
    camera_setting_data.saturation = 128;
    camera_setting_data.contrast = 128;
    camera_setting_data.hue = 0;
    
#ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_1__
    if (g_camera_cntx.setting.effect == CAMERA_SETTING_EFFECT_CUSTOM_FX_1)
    {
        camera_setting_data.effect = camera_effect_command_map[CAMERA_SETTING_EFFECT_NORMAL];
        camera_setting_data.brightness = g_camera_cntx.setting.fx_brightness[0];
        camera_setting_data.saturation = g_camera_cntx.setting.fx_saturation[0];
        camera_setting_data.contrast = g_camera_cntx.setting.fx_contrast[0];
        camera_setting_data.hue = g_camera_cntx.setting.fx_hue[0];
    }
#endif /* __CAMERA_FEATURE_EFFECT_CUSTOM_FX_1__ */ 
    
#ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_2__
    if (g_camera_cntx.setting.effect == CAMERA_SETTING_EFFECT_CUSTOM_FX_2)
    {
        camera_setting_data.effect = camera_effect_command_map[CAMERA_SETTING_EFFECT_NORMAL];
        camera_setting_data.brightness = g_camera_cntx.setting.fx_brightness[1];
        camera_setting_data.saturation = g_camera_cntx.setting.fx_saturation[1];
        camera_setting_data.contrast = g_camera_cntx.setting.fx_contrast[1];
        camera_setting_data.hue = g_camera_cntx.setting.fx_hue[1];
    }
#endif /* __CAMERA_FEATURE_EFFECT_CUSTOM_FX_2__ */ 
    
#ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_3__
    if (g_camera_cntx.setting.effect == CAMERA_SETTING_EFFECT_CUSTOM_FX_3)
    {
        camera_setting_data.effect = camera_effect_command_map[CAMERA_SETTING_EFFECT_NORMAL];
        camera_setting_data.brightness = g_camera_cntx.setting.fx_brightness[2];
        camera_setting_data.saturation = g_camera_cntx.setting.fx_saturation[2];
        camera_setting_data.contrast = g_camera_cntx.setting.fx_contrast[2];
        camera_setting_data.hue = g_camera_cntx.setting.fx_hue[2];
    }
#endif /* __CAMERA_FEATURE_EFFECT_CUSTOM_FX_3__ */ 
    
    camera_setting_data.overlay_frame_mode = FALSE;
    camera_setting_data.overlay_frame_depth = 0;
    camera_setting_data.overlay_frame_width = 0;
    camera_setting_data.overlay_frame_height = 0;
    camera_setting_data.overlay_frame_source_key = 0;
    camera_setting_data.overlay_frame_buffer_address = 0;
    
    camera_setting_data.preview_width = g_camera_cntx.preview_width;
    camera_setting_data.preview_height = g_camera_cntx.preview_height;
    
    /* capture parameters */
    camera_setting_data.image_qty = camera_image_qty_command_map[g_camera_cntx.setting.image_qty];
    camera_setting_data.image_width = g_camera_cntx.image_width;
    camera_setting_data.image_height = g_camera_cntx.image_height;
    
    camera_setting_data.lcm = MDI_CAMERA_PREVIEW_LCM_MAINLCD;
    camera_setting_data.preview_rotate = CAMERA_PREVIEW_MAINLCD_ROTATE;
    camera_setting_data.lcm_rotate = CAMERA_LCM_MAINLCD_ROTATE;
    
    camera_setting_data.continue_capture = g_camera_cntx.is_continue_capture;
    
    /* AF */
    /* turn on led highlight */
    mmi_camera_turn_on_preview_led_highlight();
    
    /* 
    * if using MT6218B series moudle with a Master backend (AIT700, etc),
    * we have to clear the preview layer's background to transparent,
    * and we have to resoret it after preview stop (stopped by capture command)
    */
    
#ifdef CAMERA_MODULE_WITH_LCD
    gdi_layer_clear(CAMEAR_BG_TRASN_COLOR);
#endif 
    
    if (g_camera_cntx.is_tileshot)
    {
        ASSERT(0);
    }
    else
    {
#ifdef __CAMERA_AUTOFOCUS__
#ifdef HORIZONTAL_CAMERA
        {
            S32 tmp;
            
            if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270)
            {
                camera_setting_data.af_zone0_x = CAMERA_AF_POSITION_1_X;
                camera_setting_data.af_zone0_y = CAMERA_AF_POSITION_1_Y;
                camera_setting_data.af_zone1_x = CAMERA_AF_POSITION_4_X;
                camera_setting_data.af_zone1_y = CAMERA_AF_POSITION_4_Y;
                camera_setting_data.af_zone2_x = CAMERA_AF_POSITION_5_X;
                camera_setting_data.af_zone2_y = CAMERA_AF_POSITION_5_Y;
                camera_setting_data.af_zone3_x = CAMERA_AF_POSITION_3_X;
                camera_setting_data.af_zone3_y = CAMERA_AF_POSITION_3_Y;
                camera_setting_data.af_zone4_x = CAMERA_AF_POSITION_2_X;
                camera_setting_data.af_zone4_y = CAMERA_AF_POSITION_2_Y;
                
                TRANSLATE_COORDINATE_TO_270(camera_setting_data.af_zone0_x, camera_setting_data.af_zone0_y, tmp);
                TRANSLATE_COORDINATE_TO_270(camera_setting_data.af_zone1_x, camera_setting_data.af_zone1_y, tmp);
                TRANSLATE_COORDINATE_TO_270(camera_setting_data.af_zone2_x, camera_setting_data.af_zone2_y, tmp);
                TRANSLATE_COORDINATE_TO_270(camera_setting_data.af_zone3_x, camera_setting_data.af_zone3_y, tmp);
                TRANSLATE_COORDINATE_TO_270(camera_setting_data.af_zone4_x, camera_setting_data.af_zone4_y, tmp);
                
                g_camera_cntx.af_zone0_x = camera_setting_data.af_zone0_x;
                g_camera_cntx.af_zone1_x = camera_setting_data.af_zone1_x;
                g_camera_cntx.af_zone2_x = camera_setting_data.af_zone2_x;
                g_camera_cntx.af_zone3_x = camera_setting_data.af_zone3_x;
                g_camera_cntx.af_zone4_x = camera_setting_data.af_zone4_x;
                
                g_camera_cntx.af_zone0_y = camera_setting_data.af_zone0_y;
                g_camera_cntx.af_zone1_y = camera_setting_data.af_zone1_y;
                g_camera_cntx.af_zone2_y = camera_setting_data.af_zone2_y;
                g_camera_cntx.af_zone3_y = camera_setting_data.af_zone3_y;
                g_camera_cntx.af_zone4_y = camera_setting_data.af_zone4_y;
            }
            else
            {
                g_camera_cntx.af_zone0_x = camera_setting_data.af_zone0_x = CAMERA_AF_POSITION_1_X;
                g_camera_cntx.af_zone0_y = camera_setting_data.af_zone0_y = CAMERA_AF_POSITION_1_Y;
                g_camera_cntx.af_zone1_x = camera_setting_data.af_zone1_x = CAMERA_AF_POSITION_2_X;
                g_camera_cntx.af_zone1_y = camera_setting_data.af_zone1_y = CAMERA_AF_POSITION_2_Y;
                g_camera_cntx.af_zone2_x = camera_setting_data.af_zone2_x = CAMERA_AF_POSITION_3_X;
                g_camera_cntx.af_zone2_y = camera_setting_data.af_zone2_y = CAMERA_AF_POSITION_3_Y;
                g_camera_cntx.af_zone3_x = camera_setting_data.af_zone3_x = CAMERA_AF_POSITION_4_X;
                g_camera_cntx.af_zone3_y = camera_setting_data.af_zone3_y = CAMERA_AF_POSITION_4_Y;
                g_camera_cntx.af_zone4_x = camera_setting_data.af_zone4_x = CAMERA_AF_POSITION_5_X;
                g_camera_cntx.af_zone4_y = camera_setting_data.af_zone4_y = CAMERA_AF_POSITION_5_Y;
                
                TRANSLATE_COORDINATE_TO_270(camera_setting_data.af_zone0_x, camera_setting_data.af_zone0_y, tmp);
                TRANSLATE_COORDINATE_TO_270(camera_setting_data.af_zone1_x, camera_setting_data.af_zone1_y, tmp);
                TRANSLATE_COORDINATE_TO_270(camera_setting_data.af_zone2_x, camera_setting_data.af_zone2_y, tmp);
                TRANSLATE_COORDINATE_TO_270(camera_setting_data.af_zone3_x, camera_setting_data.af_zone3_y, tmp);
                TRANSLATE_COORDINATE_TO_270(camera_setting_data.af_zone4_x, camera_setting_data.af_zone4_y, tmp);
            }
        }
#else /* HORIZONTAL_CAMERA */ 
        g_camera_cntx.af_zone0_x = camera_setting_data.af_zone0_x = CAMERA_AF_POSITION_1_X;
        g_camera_cntx.af_zone0_y = camera_setting_data.af_zone0_y = CAMERA_AF_POSITION_1_Y;
        g_camera_cntx.af_zone1_x = camera_setting_data.af_zone1_x = CAMERA_AF_POSITION_2_X;
        g_camera_cntx.af_zone1_y = camera_setting_data.af_zone1_y = CAMERA_AF_POSITION_2_Y;
        g_camera_cntx.af_zone2_x = camera_setting_data.af_zone2_x = CAMERA_AF_POSITION_3_X;
        g_camera_cntx.af_zone2_y = camera_setting_data.af_zone2_y = CAMERA_AF_POSITION_3_Y;
        g_camera_cntx.af_zone3_x = camera_setting_data.af_zone3_x = CAMERA_AF_POSITION_4_X;
        g_camera_cntx.af_zone3_y = camera_setting_data.af_zone3_y = CAMERA_AF_POSITION_4_Y;
        g_camera_cntx.af_zone4_x = camera_setting_data.af_zone4_x = CAMERA_AF_POSITION_5_X;
        g_camera_cntx.af_zone4_y = camera_setting_data.af_zone4_y = CAMERA_AF_POSITION_5_Y;
        
#endif /* HORIZONTAL_CAMERA */ 
#endif /* __CAMERA_AUTOFOCUS__ */ 
        
        preview_layer_handle = g_camera_cntx.preview_layer_handle;
        
        /* use preview wnd's position */
        preview_wnd_offset_x = g_camera_cntx.active_camera_osd_ptr->preview_wnd.offset_x;
        preview_wnd_offset_y = g_camera_cntx.active_camera_osd_ptr->preview_wnd.offset_y;
        preview_wnd_width = g_camera_cntx.preview_width;
        preview_wnd_height = g_camera_cntx.preview_height;
        
        /* preview (hw), OSD */
#if defined(__MMI_CAMERA_BASELAYER_SET_COLOR_SUPPORT__)
#if defined(__MMI_CAMERA_5_OSD_LAYER__)
        if (g_camera_cntx.is_single_osd_layer == FALSE)
        {
            blt_layer_flag =
                GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2 |
                GDI_LAYER_ENABLE_LAYER_3 | GDI_LAYER_ENABLE_LAYER_4 | GDI_LAYER_ENABLE_LAYER_5;
        }
        else
        {
            blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1;
        }
#elif defined(__MMI_CAMERA_3_OSD_LAYER__) 
        if (g_camera_cntx.is_single_osd_layer == FALSE)
        {
            blt_layer_flag =
                GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2 |
                GDI_LAYER_ENABLE_LAYER_3 ;
        }
        else
        {
            blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1;
        }
        
#else /* __MMI_CAMERA_5_OSD_LAYER__ */ 
        blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1;
#endif /* __MMI_CAMERA_5_OSD_LAYER__ */ 
        preview_layer_flag = GDI_LAYER_ENABLE_LAYER_0;
        
#elif defined(__MMI_CAMERA_DIRECT_SENSOR_SUPPORT__)
        blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1; 
        preview_layer_flag = GDI_LAYER_ENABLE_LAYER_1;
#else /* defined(__MMI_CAMERA_BASELAYER_SET_COLOR_SUPPORT__)*/ 
        blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2;
        preview_layer_flag = GDI_LAYER_ENABLE_LAYER_1;
#endif /* defined(__MMI_CAMERA_BASELAYER_SET_COLOR_SUPPORT__) */ 
}

#ifdef __CAMERA_FEATURE_XENON_FLASH__
g_camera_cntx.xenon_flash_state = MMI_CAMERA_XENON_FLASH_OFF;
#endif

/* preview data for preview start */
camera_preview_data.preview_layer_handle = preview_layer_handle;
camera_preview_data.preview_wnd_offset_x = preview_wnd_offset_x;
camera_preview_data.preview_wnd_offset_y = preview_wnd_offset_y;
camera_preview_data.preview_wnd_width = preview_wnd_width;
camera_preview_data.preview_wnd_height = preview_wnd_height;
camera_preview_data.blt_layer_flag = blt_layer_flag;
camera_preview_data.preview_layer_flag = preview_layer_flag;
camera_preview_data.is_lcd_update = TRUE;
camera_preview_data.src_key_color = GDI_COLOR_TRANSPARENT;
camera_preview_data.is_tvout = TRUE;

mmi_camera_get_next_filename(g_camera_cntx.captured_filepath);

#ifdef __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__
mmi_camera_restart_app_watchdog();
#endif
/*@ Add by Vincent */
#if defined(__CAMERA_OSD_HORIZONTAL__) && defined(__MDI_CAMERA_HW_ROTATOR_SUPPORT__)
mdi_camera_set_hw_rotator(MDI_CAMERA_PREVIEW_ROTATE_90);
#endif

g_camera_cntx.last_error
= mdi_camera_preview_start(
                           &camera_preview_data,
                           &camera_setting_data);

/* for reducing tearing effect on WQVGA lcm */
#if defined(__MMI_CAMERA_QVGA_WALLPAPER_ON_WQVGA_LCM__)
mmi_camera_preview_hide_hint();
#endif /* __MMI_CAMERA_QVGA_WALLPAPER_ON_WQVGA_LCM__ */

}


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_stop
* DESCRIPTION
*  stop previewing of main lcd
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_preview_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop previewing */
    mdi_camera_preview_stop();
    
    /* restore black background */
#ifdef CAMERA_MODULE_WITH_LCD
    mmi_camera_preview_clear_background();
#endif 
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_set_blt_layer
* DESCRIPTION
*  set blt layer based on current status (ex: is previwing, has add frame, etc )
* PARAMETERS
*  is_previewing       [IN]        Is preview flag
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_preview_set_blt_layer(BOOL is_previewing)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (is_previewing)
    {
        if (g_camera_cntx.is_tileshot)
        {
            MMI_ASSERT(0);
        }
        else
        {
            /* (1) previwing */
#if defined(__MMI_CAMERA_BASELAYER_SET_COLOR_SUPPORT__)
#if defined(__MMI_CAMERA_5_OSD_LAYER__)
            if (g_camera_cntx.is_single_osd_layer == FALSE)
            {
                    gdi_layer_set_blt_layer_ext(
                        g_camera_cntx.preview_layer_handle,
                        g_camera_cntx.osd_layer_handle0,
                        g_camera_cntx.osd_layer_handle1,
                        g_camera_cntx.osd_layer_handle2,
                        g_camera_cntx.osd_layer_handle3,
                        g_camera_cntx.osd_layer_handle4);
            }
            else
            {
                gdi_layer_set_blt_layer(g_camera_cntx.preview_layer_handle, g_camera_cntx.osd_layer_handle0, 0, 0);
            }
#elif defined(__MMI_CAMERA_3_OSD_LAYER__)
            if (g_camera_cntx.is_single_osd_layer == FALSE)
            {
                gdi_layer_set_blt_layer(
                    g_camera_cntx.preview_layer_handle,
                    g_camera_cntx.osd_layer_handle0,
                    g_camera_cntx.osd_layer_handle1,
                    g_camera_cntx.osd_layer_handle2);
            }
            else
            {
                gdi_layer_set_blt_layer(g_camera_cntx.preview_layer_handle, g_camera_cntx.osd_layer_handle0, 0, 0);
            }
            
#else /* __MMI_CAMERA_5_OSD_LAYER__ */ 
            gdi_layer_set_blt_layer(g_camera_cntx.preview_layer_handle, g_camera_cntx.osd_layer_handle0, 0, 0);
            
#endif /* __MMI_CAMERA_5_OSD_LAYER__ */ 
            
#elif defined(__MMI_CAMERA_DIRECT_SENSOR_SUPPORT__)
            gdi_layer_set_blt_layer(g_camera_cntx.base_layer_handle,g_camera_cntx.preview_layer_handle, 0, 0);
#else /* defined(__MMI_CAMERA_BASELAYER_SET_COLOR_SUPPORT__) */ 
            gdi_layer_set_blt_layer(
                g_camera_cntx.base_layer_handle,
                g_camera_cntx.preview_layer_handle,
                g_camera_cntx.osd_layer_handle0,
                0);
#endif /* defined(__MMI_CAMERA_BASELAYER_SET_COLOR_SUPPORT__) */ 
        }
    }
    else
    {
        if (g_camera_cntx.is_tileshot)
        {
            MMI_ASSERT(0);
        }
        else
        {
            /*  not previewing. */
#if defined(__MMI_CAMERA_BASELAYER_SET_COLOR_SUPPORT__)
#if defined(__MMI_CAMERA_5_OSD_LAYER__)
            if (g_camera_cntx.is_single_osd_layer == FALSE)
            {
                
                gdi_layer_set_blt_layer_ext(
                    g_camera_cntx.preview_layer_handle,
                    g_camera_cntx.osd_layer_handle0,
                    g_camera_cntx.osd_layer_handle1,
                    g_camera_cntx.osd_layer_handle2,
                    g_camera_cntx.osd_layer_handle3,
                    g_camera_cntx.osd_layer_handle4);
                
            }
            else
            {
                gdi_layer_set_blt_layer(g_camera_cntx.preview_layer_handle, g_camera_cntx.osd_layer_handle0, 0, 0);
            }
#elif defined(__MMI_CAMERA_3_OSD_LAYER__)
            if (g_camera_cntx.is_single_osd_layer == FALSE)
            {
                
                gdi_layer_set_blt_layer(
                    g_camera_cntx.preview_layer_handle,
                    g_camera_cntx.osd_layer_handle0,
                    g_camera_cntx.osd_layer_handle1,
                    g_camera_cntx.osd_layer_handle2);
            }
            else
            {
                gdi_layer_set_blt_layer(g_camera_cntx.preview_layer_handle, g_camera_cntx.osd_layer_handle0, 0, 0);
            }
            
#else /* __MMI_CAMERA_5_OSD_LAYER__ */ 
            gdi_layer_set_blt_layer(g_camera_cntx.preview_layer_handle, g_camera_cntx.osd_layer_handle0, 0, 0);
            
#endif /* __MMI_CAMERA_5_OSD_LAYER__ */ 
#else /* defined(__MMI_CAMERA_BASELAYER_SET_COLOR_SUPPORT__) */ 
            gdi_layer_set_blt_layer(g_camera_cntx.base_layer_handle, g_camera_cntx.osd_layer_handle0, 0, 0);
#endif /* defined(__MMI_CAMERA_BASELAYER_SET_COLOR_SUPPORT__) */ 
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_clear_background
* DESCRIPTION
*  clear backgroud of preview screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_preview_clear_background(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_color bg_color;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_camera_cntx.base_layer_handle);
    if (g_camera_cntx.active_camera_osd_ptr->bg.is_draw_bg_color)
    {
        bg_color = GDI_RGB_TO_BUFFER_FORMAT(
            g_camera_cntx.active_camera_osd_ptr->bg.r,
            g_camera_cntx.active_camera_osd_ptr->bg.g,
            g_camera_cntx.active_camera_osd_ptr->bg.b);
        
        gdi_layer_clear(bg_color);
    }
    
    if (g_camera_cntx.active_camera_osd_ptr->bg.is_draw_bg_image)
    {
        gdi_image_draw_id(0, 0, IMG_ID_CAMERA_PREVIEW_BACKGROUND);
    }
    
    if (!g_camera_cntx.active_camera_osd_ptr->bg.is_draw_bg_color &&
        !g_camera_cntx.active_camera_osd_ptr->bg.is_draw_bg_image)
    {
        gdi_layer_clear(GDI_COLOR_BLACK);
    }
    
    gdi_layer_pop_and_restore_active();
    
    
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_flatten_layer
* DESCRIPTION
*  flatten layers to base
* PARAMETERS
*  is_previewing       [IN]        
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_preview_flatten_layer(BOOL is_previewing)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_previewing)
    {
        if (g_camera_cntx.is_tileshot)
        {
            ASSERT(0);
        }
        else
        {
            gdi_layer_push_and_set_active(g_camera_cntx.base_layer_handle);
            gdi_layer_clear(GDI_COLOR_BLACK);
            gdi_layer_pop_and_restore_active();
            return;

#if defined(__MMI_CAMERA_BASELAYER_SET_COLOR_SUPPORT__)
#if (MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL==24)          
            gdi_layer_push_and_set_active(g_camera_cntx.base_layer_handle);
            gdi_layer_clear(GDI_COLOR_BLACK);
            gdi_layer_pop_and_restore_active();
#elif defined(__MMI_CAMERA_5_OSD_LAYER__) 
            gdi_layer_flatten_to_base_ext(g_camera_cntx.preview_layer_handle, g_camera_cntx.osd_layer_handle0, g_camera_cntx.osd_layer_handle1, g_camera_cntx.osd_layer_handle2, g_camera_cntx.osd_layer_handle3, 0);
#elif defined(__MMI_CAMERA_3_OSD_LAYER__) 
            gdi_layer_flatten_to_base(g_camera_cntx.preview_layer_handle, g_camera_cntx.osd_layer_handle0, g_camera_cntx.osd_layer_handle1, 0);
#else
            gdi_layer_push_and_set_active(g_camera_cntx.base_layer_handle);
            gdi_layer_clear(GDI_COLOR_BLACK);
            gdi_layer_pop_and_restore_active();
#endif
#elif defined(__MMI_CAMERA_DIRECT_SENSOR_SUPPORT__)
            gdi_layer_flatten_to_base(
                g_camera_cntx.base_layer_handle,
                g_camera_cntx.preview_layer_handle,
                g_camera_cntx.osd_layer_handle0, 
                0);
#else /* defined(__MMI_CAMERA_BASELAYER_SET_COLOR_SUPPORT__) */ 
            gdi_layer_flatten_to_base(
                g_camera_cntx.base_layer_handle,
                g_camera_cntx.preview_layer_handle,
                g_camera_cntx.osd_layer_handle0,
                0);
#endif /* defined(__MMI_CAMERA_BASELAYER_SET_COLOR_SUPPORT__) */ 
        }
    }
    else
    {
#if (MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL==24)          
        gdi_layer_push_and_set_active(g_camera_cntx.base_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
#elif defined(__MMI_CAMERA_5_OSD_LAYER__) 
        gdi_layer_flatten_to_base_ext(g_camera_cntx.preview_layer_handle, g_camera_cntx.osd_layer_handle0, g_camera_cntx.osd_layer_handle1, g_camera_cntx.osd_layer_handle2, g_camera_cntx.osd_layer_handle3, 0);
#elif defined(__MMI_CAMERA_3_OSD_LAYER__) 
        gdi_layer_flatten_to_base(g_camera_cntx.preview_layer_handle, g_camera_cntx.osd_layer_handle0, g_camera_cntx.osd_layer_handle1, 0);
#else
        gdi_layer_flatten_to_base(g_camera_cntx.base_layer_handle, g_camera_cntx.osd_layer_handle0, 0, 0);
#endif
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_hide_hint
* DESCRIPTION
*  hide hint
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_preview_hide_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* for reducing tearing effect on WQVGA lcm */
#if defined(__MMI_CAMERA_QVGA_WALLPAPER_ON_WQVGA_LCM__)
    if (CAMERA_STATE_IN(CAMERA_STATE_PREVIEW))
    {
        gdi_layer_set_blt_layer_ext(
            g_camera_cntx.preview_layer_handle,
            g_camera_cntx.osd_layer_handle0,
            g_camera_cntx.osd_layer_handle1,
            g_camera_cntx.osd_layer_handle2,
            g_camera_cntx.osd_layer_handle3,
            g_camera_cntx.osd_layer_handle4);
    }
#endif /* __MMI_CAMERA_QVGA_WALLPAPER_ON_WQVGA_LCM__ */
    mmi_camera_preview_set_hint(NULL, NULL, 255);
    mmi_camera_preview_draw_osd();
    mmi_camera_blt();
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_draw_osd
* DESCRIPTION
*  draw preview title
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_preview_draw_osd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
    if (g_camera_cntx.is_single_osd_layer)
    {
        gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle0);
        gdi_layer_toggle_double();
        /* toggle double buffer */
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    }
    else
    {
        /* for reducing tearing effect on WQVGA lcm */
#if defined(__MMI_CAMERA_QVGA_WALLPAPER_ON_WQVGA_LCM__)
        if (g_camera_cntx.fade_time != 255 && !CAMERA_STATE_IN(CAMERA_STATE_DELETE_CONFIRM))
        {
            if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_0)
            {
                gdi_layer_set_blt_layer_ext(
                    g_camera_cntx.preview_layer_handle,
                    g_camera_cntx.osd_layer_handle0,
                    g_camera_cntx.osd_layer_handle1,
                    g_camera_cntx.osd_layer_handle2,
                    g_camera_cntx.osd_layer_handle3,
                    0);
            }
            else
            {
                gdi_layer_set_blt_layer_ext(
                    g_camera_cntx.preview_layer_handle,
                    g_camera_cntx.osd_layer_handle0,
                    g_camera_cntx.osd_layer_handle1,
                    g_camera_cntx.osd_layer_handle2,
                    g_camera_cntx.osd_layer_handle3,
                    0);
            }
        }
#endif /* __MMI_CAMERA_QVGA_WALLPAPER_ON_WQVGA_LCM__ */
        
        gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle0);
        gdi_layer_toggle_double();
        /* toggle double buffer */
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        
        gdi_layer_set_active(g_camera_cntx.osd_layer_handle1);
        gdi_layer_toggle_double();
        /* toggle double buffer */
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        
        gdi_layer_set_active(g_camera_cntx.osd_layer_handle2);
        gdi_layer_toggle_double();
        /* toggle double buffer */
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        
#ifdef __MMI_CAMERA_5_OSD_LAYER__
        gdi_layer_set_active(g_camera_cntx.osd_layer_handle3);
        gdi_layer_toggle_double();
        /* toggle double buffer */
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        
        gdi_layer_set_active(g_camera_cntx.osd_layer_handle4);
        gdi_layer_toggle_double();
        /* toggle double buffer */
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
#endif
        gdi_layer_pop_and_restore_active();
    }
    
    gdi_set_alpha_blending_source_layer(g_camera_cntx.osd_layer_handle0);
    
#else /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 
    
    /*@ Add by Vincent */
    /* if using idp rotate, we need to config osd buffer for idp rotate only, we do not need to config original osd layer as horizontal */
#if defined(__CAMERA_OSD_HORIZONTAL__) && defined(__MDI_CAMERA_HW_ROTATOR_SUPPORT__)
    
    if(g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_0)
    {
        kal_wap_trace(MOD_MMI, TRACE_GROUP_3, "[cam][6253] osd_rotate == 0, direct use osd double layer");
        gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle0);
        gdi_layer_toggle_double();
        /* toggle double buffer */
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        
        gdi_set_alpha_blending_source_layer(g_camera_cntx.osd_layer_handle0);
    }
    else
    {
        kal_wap_trace(MOD_MMI, TRACE_GROUP_3, "[cam][6253] osd_rotate != 0, use idp_rotate_layer");
        gdi_layer_push_and_set_active(g_camera_cntx.osd_idp_rotate_layer_handle);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        
        gdi_set_alpha_blending_source_layer(g_camera_cntx.osd_idp_rotate_layer_handle);
    }
#else /* defined(__CAMERA_OSD_HORIZONTAL__) && defined(__MDI_CAMERA_HW_ROTATOR_SUPPORT__) */
    
    gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle0);
    gdi_layer_toggle_double();
    /* toggle double buffer */
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    
    gdi_set_alpha_blending_source_layer(g_camera_cntx.osd_layer_handle0);
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) && defined(__MDI_CAMERA_HW_ROTATOR_SUPPORT__)*/
#endif /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 
    
    
    /* do not draw any thing here */
    if ((g_camera_cntx.app_state != CAMERA_STATE_DELETE_CONFIRM) &&
        (g_camera_cntx.app_state != CAMERA_STATE_BURSTSHOT_SAVE_CONFIRM) &&
        (g_camera_cntx.is_fullscreen) &&
        ((g_camera_cntx.setting.add_frame != 0) || (g_camera_cntx.setting.add_frame_tileshot != 0)) &&
        (g_camera_cntx.add_frame_layer_handle != GDI_LAYER_EMPTY_HANDLE)
#if defined(__CAMERA_FEATURE_CONT_SHOT_BURST__)
        && (g_camera_cntx.setting.cont_shot != CAMERA_SETTING_CONT_SHOT_BURST)
#endif
        )
    {
        PU8 src;
        PU8 dest;
        U16 src_width, src_height, src_pitch;
        S32 src_offset_x, src_offset_y;
        S32 dest_pitch, dest_offset_x, dest_offset_y;
        gdi_rect_struct dest_clip;
        
        gdi_layer_get_buffer_ptr(&dest);
        
        gdi_layer_push_and_set_active(g_camera_cntx.add_frame_layer_handle);
        gdi_layer_get_buffer_ptr(&src);
        
        
#if defined(__CAMERA_OSD_HORIZONTAL__)
        src_pitch = g_camera_cntx.preview_height;
        src_width = g_camera_cntx.preview_height;
        src_height = g_camera_cntx.preview_width;
#else
        src_pitch = g_camera_cntx.preview_width;
        src_width = g_camera_cntx.preview_width;
        src_height = g_camera_cntx.preview_height;
#endif
        src_offset_x = 0;
        src_offset_y = 0;
        
        dest_pitch = g_camera_cntx.osd_UI_device_width;
        dest_clip.x1 = 0;
        dest_clip.y1 = 0;
        dest_clip.x2 = g_camera_cntx.osd_UI_device_width - 1;
        dest_clip.y2 = g_camera_cntx.osd_UI_device_height - 1;
        dest_offset_y = 0;
        dest_offset_x = 0;
        gdi_layer_pop_and_restore_active();
        
        gdi_2d_memory_blt_without_transpant_check(
            src,
            src_pitch,
            src_offset_x,
            src_offset_y,
            src_width,
            src_height,
            dest,
            dest_pitch,
            dest_offset_x,
            dest_offset_y,
            dest_clip,
            GDI_MAINLCD_BIT_PER_PIXEL);
    }
    
    /****** wanna draw any thing on OSD layer, please add code after this ******/
#ifdef __CAMERA_AUTOFOCUS__
    if (g_camera_cntx.is_autofocus_pressed == TRUE)
    {
        mmi_camera_draw_autofocus_process();
    }
#endif /* __CAMERA_AUTOFOCUS__ */ 
    
    mmi_camera_preview_draw_softkey();
    mmi_camera_preview_draw_title();
    
    if (g_camera_cntx.fade_time != 255)
    {
        mmi_camera_preview_draw_hint();
        g_camera_cntx.fade_time = 0;
    }
    
    if ((g_camera_cntx.app_state != CAMERA_STATE_DELETE_CONFIRM) &&
        (g_camera_cntx.app_state != CAMERA_STATE_BURSTSHOT_SAVE_CONFIRM))
    {
        mmi_camera_preview_draw_icon();
        
        if (g_camera_cntx.app_state == CAMERA_STATE_CONTSHOT)
        {
#ifdef __CAMERA_FEATURE_CONT_SHOT_DRAW_COUNTBAR__
            mmi_camera_preview_draw_contshot_countbar();
#endif 
        }
    }
#if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
    if (g_camera_cntx.is_single_osd_layer)
    {
        gdi_layer_pop_and_restore_active();
    }
#else /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)*/ 
    gdi_layer_pop_and_restore_active();
    
    /*@ Add by Vincent */
    /* if using idp rotate, we need to config osd buffer for idp rotate only, we do not need to config original osd layer as horizontal */
#if defined(__CAMERA_OSD_HORIZONTAL__) && defined(__MDI_CAMERA_HW_ROTATOR_SUPPORT__) 
    
#if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
    /* double check there should no __MMI_CAMERA_3_OSD_LAYER__ || __MMI_CAMERA_5_OSD_LAYER__*/
    ASSERT(0);
#endif
    
    if(g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270)
    {
#ifndef GDI_USING_2D_ENGINE_V3
        PU8 dest;
#endif
        
        gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle0);
        gdi_layer_toggle_double();
        /* toggle double buffer */
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        
        gdi_set_alpha_blending_source_layer(g_camera_cntx.osd_layer_handle0);
        
        /* rotate idp_rotate_layer to osd_layer */
#if defined(GDI_USING_2D_ENGINE_V3)
        gdi_2d_begin();
        gdi_2d_set_layer_as_dest_buffer(g_camera_cntx.osd_layer_handle0);
        gdi_2d_set_layer_as_src_bitblt_buffer(g_camera_cntx.osd_idp_rotate_layer_handle);
        gdi_2d_rotate(GDI_TRANSFORM_ROTATE_90);
        gdi_2d_end();
#else
        gdi_layer_get_buffer_ptr(&dest);
        
        kal_wap_trace(MOD_MMI, TRACE_GROUP_3, "[cam][6253] g2d rotate to osd layer (src_width,src_height) = (%d,%d)", LCD_HEIGHT, LCD_WIDTH);
        
        /* toggle double buffer */
        mmi_camera_sw_rotate(
            dest,
            g_camera_cntx.osd_idp_rotate_ptr,
            (U32) LCD_HEIGHT,
            (U32) LCD_WIDTH);        
#endif
        
        gdi_layer_pop_and_restore_active();
    }
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) && defined(__MDI_CAMERA_HW_ROTATOR_SUPPORT__)  */
    
#endif /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 
#if defined(__MMI_CAMERA_BG_CALL__)
    if (mmi_ucm_is_background_call() == TRUE && CAMERA_STATE_IN(CAMERA_STATE_EXIT))
    {
        gdi_layer_push_and_set_active(g_camera_cntx.base_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
        gdi_layer_set_blt_layer(g_camera_cntx.base_layer_handle, g_camera_cntx.osd_layer_handle0, 0, 0);
    }
#endif /* __MMI_CAMERA_BG_CALL__ */
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_draw_title
* DESCRIPTION
*  draw preview title
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_preview_draw_title(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if is fullscreen display, do not draw title */
    if (g_camera_cntx.is_fullscreen)
    {
        return;
    }
    
    /* if not fullscreen and need title */
    if (g_camera_cntx.active_camera_osd_ptr->title.is_draw_mmi_title_bar &&
        g_camera_cntx.active_camera_osd_ptr->title.is_draw_mmi_caption)
    {
        gdi_layer_lock_frame_buffer();
        
        show_title_status_icon();
        draw_title();
        
        gdi_layer_unlock_frame_buffer();
        gdi_layer_reset_clip();
        gdi_layer_reset_text_clip();
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_draw_softkey
* DESCRIPTION
*  draw preview softkey
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_preview_draw_softkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 lsk_offset_x = 0;
    S32 lsk_offset_y = 0;
    S32 rsk_offset_x = 0;
    S32 rsk_offset_y = 0;
    S32 str_width;
    S32 str_height;
    PS8 str_ptr;
    U16 lsk_id;
    U16 rsk_id;
    S32 offset_x = 0;
    S32 offset_y = 0;
    S32 truncated_width = 0;
    MMI_BOOL truncated = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
    if (g_camera_cntx.is_single_osd_layer == FALSE)
    {
        offset_x = g_camera_cntx.active_camera_osd_ptr->osd_region0.offset_x;
        offset_y = g_camera_cntx.active_camera_osd_ptr->osd_region0.offset_y;
        gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle0);
    }
#endif /* __MMI_CAMERA_5_OSD_LAYER__ */ 
    if (g_camera_cntx.app_state == CAMERA_STATE_DELETE_CONFIRM)
    {
        if (g_camera_cntx.external_request_mode == MMI_CAMERA_EXTERNAL_MODE_OFF)
        {
            lsk_id = STR_GLOBAL_OPTIONS;
            rsk_id = STR_GLOBAL_BACK;
        }
        else
        {
            lsk_id = STR_ID_CAMERA_CONTINUE;
            rsk_id = STR_GLOBAL_DELETE;
        }
    }
    else if (g_camera_cntx.app_state == CAMERA_STATE_BURSTSHOT_SAVE_CONFIRM)
    {
        lsk_id = STR_GLOBAL_SAVE;
        rsk_id = STR_GLOBAL_CLEAR;
    }
    else if ((g_camera_cntx.app_state == CAMERA_STATE_PREVIEW) && (g_camera_cntx.tile_cur_num >= 1))
    {
        lsk_id = STR_GLOBAL_OPTIONS;
        
        rsk_id = STR_GLOBAL_CLEAR;
    }
    else
    {
        /*Draw lsk and rsk*/
        if (g_camera_cntx.is_lsk_pressed)
        {
            gdi_image_draw_id(
                g_camera_cntx.active_camera_osd_ptr->lsk.offset_x - offset_x,
                g_camera_cntx.active_camera_osd_ptr->lsk.offset_y - offset_y,
                (U16) (IMG_ID_CAMERA_OSD_OPTIONS_SEL));
        }
        else
        {
            gdi_image_draw_id(
                g_camera_cntx.active_camera_osd_ptr->lsk.offset_x - offset_x,
                g_camera_cntx.active_camera_osd_ptr->lsk.offset_y - offset_y,
                (U16) (IMG_ID_CAMERA_OSD_OPTIONS));
        }
        if (g_camera_cntx.is_rsk_pressed)
        {
            gdi_image_draw_id(
                g_camera_cntx.active_camera_osd_ptr->rsk.offset_x - offset_x,
                g_camera_cntx.active_camera_osd_ptr->rsk.offset_y - offset_y,
                (U16) (IMG_ID_CAMERA_OSD_BACK_SEL));
        }
        else
        {
            gdi_image_draw_id(
                g_camera_cntx.active_camera_osd_ptr->rsk.offset_x - offset_x,
                g_camera_cntx.active_camera_osd_ptr->rsk.offset_y - offset_y,
                (U16) (IMG_ID_CAMERA_OSD_BACK));
        }
        /* lsk */
        gdi_image_get_dimension_id(
            (U16) (IMG_ID_CAMERA_OSD_OPTIONS),
            &g_camera_cntx.touch_lsk.width,
            &g_camera_cntx.touch_lsk.height);
        g_camera_cntx.touch_lsk.offset_x = g_camera_cntx.active_camera_osd_ptr->lsk.offset_x;
        g_camera_cntx.touch_lsk.offset_y = g_camera_cntx.active_camera_osd_ptr->lsk.offset_y;
        /* rsk */
        gdi_image_get_dimension_id(
            (U16) (IMG_ID_CAMERA_OSD_BACK),
            &g_camera_cntx.touch_rsk.width,
            &g_camera_cntx.touch_rsk.height);
        g_camera_cntx.touch_rsk.offset_x = g_camera_cntx.active_camera_osd_ptr->rsk.offset_x;
        g_camera_cntx.touch_rsk.offset_y = g_camera_cntx.active_camera_osd_ptr->rsk.offset_y;
#if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
        if (g_camera_cntx.is_single_osd_layer == FALSE)
        {
            gdi_layer_pop_and_restore_active();
        }
#endif /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 
        return;/* will draw options and back by icons*/
    }
    
    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();
    
    /* if is fullscreen display, or normal display but without mmi_softkey */
    if ((g_camera_cntx.is_fullscreen) || (!g_camera_cntx.active_camera_osd_ptr->softkey.is_draw_mmi_softkey))
    {
        gui_set_font(&MMI_medium_font);
        
        /* lsk */
        str_ptr = (PS8) GetString(lsk_id);
        
        gui_measure_string((UI_string_type) str_ptr, &str_width, &str_height);
        
        if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270)
        {
#if defined(__CAMERA_OSD_HORIZONTAL__)
            truncated = wgui_softkey_get_offset(
                (UI_string_type) str_ptr,
                &lsk_offset_x,
                &lsk_offset_y,
                &truncated_width,
                MMI_LEFT_SOFTKEY,
                MMI_FRM_SCREEN_ROTATE_270);
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
        }
        else
        {
            truncated = wgui_softkey_get_offset(
                (UI_string_type) str_ptr,
                &lsk_offset_x,
                &lsk_offset_y,
                &truncated_width,
                MMI_LEFT_SOFTKEY,
                mmi_frm_get_screen_rotate());
        }
        
        /* check r2lMMIFlag flag to correct offset_x of string, due to we will do the change in 
        * mmi_camera_draw_style_text() */
        if (r2lMMIFlag)
        {
            if (truncated)
            {
                lsk_offset_x -= truncated_width;
            }
            else
            {
                lsk_offset_x -= gui_get_string_width((UI_string_type) str_ptr);
            }
        }
        
        if (g_camera_cntx.is_lsk_pressed)
        {
            lsk_offset_x++;
            lsk_offset_y++;
        }
        
        mmi_camera_draw_style_text(
            str_ptr,
            lsk_offset_x - offset_x,
            lsk_offset_y - offset_y,
            truncated_width,
            &g_camera_cntx.active_camera_osd_ptr->softkey.lsk);
        
        g_camera_cntx.touch_lsk.offset_x = lsk_offset_x;
        g_camera_cntx.touch_lsk.offset_y = lsk_offset_y;
        g_camera_cntx.touch_lsk.width = str_width;
        g_camera_cntx.touch_lsk.height = str_height;
        
        /* rsk */
        str_ptr = (PS8) GetString(rsk_id);
        
        gui_measure_string((UI_string_type) str_ptr, &str_width, &str_height);
        if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270)
        {
#if defined(__CAMERA_OSD_HORIZONTAL__)
            truncated = wgui_softkey_get_offset(
                (UI_string_type) str_ptr,
                &rsk_offset_x,
                &rsk_offset_y,
                &truncated_width,
                MMI_RIGHT_SOFTKEY,
                MMI_FRM_SCREEN_ROTATE_270);
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
        }
        else
        {
            truncated = wgui_softkey_get_offset(
                (UI_string_type) str_ptr,
                &rsk_offset_x,
                &rsk_offset_y,
                &truncated_width,
                MMI_RIGHT_SOFTKEY,
                mmi_frm_get_screen_rotate());
        }
        
        if (r2lMMIFlag)
        {
            if (truncated)
            {
                rsk_offset_x -= truncated_width;
            }
            else
            {
                rsk_offset_x -= gui_get_string_width((UI_string_type) str_ptr);
            }
        }
        
        
        if (g_camera_cntx.is_rsk_pressed)
        {
            rsk_offset_x++;
            rsk_offset_y++;
        }
        
        mmi_camera_draw_style_text(
            str_ptr,
            rsk_offset_x - offset_x,
            rsk_offset_y - offset_y,
            truncated_width,
            &g_camera_cntx.active_camera_osd_ptr->softkey.rsk);
        
        g_camera_cntx.touch_rsk.offset_x = rsk_offset_x;
        g_camera_cntx.touch_rsk.offset_y = rsk_offset_y;
        g_camera_cntx.touch_rsk.width = str_width;
        g_camera_cntx.touch_rsk.height = str_height;
        
#if defined(__MMI_CAMERA_FORWARD_SUPPORT__) && defined(__MMI_OP11_CAMERA_VDOREC_CUSTOMIZE__)
        if (g_camera_cntx.app_state == CAMERA_STATE_DELETE_CONFIRM && 
            g_camera_cntx.external_request_mode == MMI_CAMERA_EXTERNAL_MODE_OFF &&
            mmi_camera_is_forward_function_ready() == MMI_TRUE)
        {
            if (g_camera_cntx.is_mms_icon_pressed == FALSE)
            {
                gdi_image_draw_id(
                    g_camera_cntx.touch_mms_icon.offset_x - offset_x,
                    g_camera_cntx.touch_mms_icon.offset_y - offset_y,
                    IMG_ID_CAMERA_FORWARD_TO_MMS);
            }
            else
            {
                gdi_image_draw_id(
                    g_camera_cntx.touch_mms_icon.offset_x - offset_x + 1,
                    g_camera_cntx.touch_mms_icon.offset_y - offset_y + 1,
                    IMG_ID_CAMERA_FORWARD_TO_MMS);
            }
        }
#endif /* defined(__MMI_CAMERA_FORWARD_SUPPORT__) */ 
        
}
else
{
    if (g_camera_cntx.is_rsk_pressed)
    {
        set_softkey_flags_on(UI_BUTTON_STATE_CLICKED | UI_BUTTON_STATE_DOWN, MMI_RIGHT_SOFTKEY);
    }
    else
    {
        set_softkey_flags_off(UI_BUTTON_STATE_CLICKED, MMI_RIGHT_SOFTKEY);
        set_softkey_flags_off(UI_BUTTON_STATE_DOWN, MMI_RIGHT_SOFTKEY);
    }
    
    if (g_camera_cntx.is_lsk_pressed)
    {
        set_softkey_flags_on(UI_BUTTON_STATE_CLICKED | UI_BUTTON_STATE_DOWN, MMI_LEFT_SOFTKEY);
    }
    else
    {
        set_softkey_flags_off(UI_BUTTON_STATE_CLICKED, MMI_LEFT_SOFTKEY);
        set_softkey_flags_off(UI_BUTTON_STATE_DOWN, MMI_LEFT_SOFTKEY);
    }
    
    change_left_softkey(lsk_id, IMG_GLOBAL_OK);
    change_right_softkey(rsk_id, IMG_GLOBAL_BACK);
    
    /* draw MMI standard softkey */
    gdi_layer_lock_frame_buffer();
    
    show_softkey_background();
    
    show_left_softkey();
    show_right_softkey();
    
    gdi_layer_unlock_frame_buffer();
    
}
#if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
if (g_camera_cntx.is_single_osd_layer == FALSE)
{
    gdi_layer_pop_and_restore_active();
}
#endif /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_draw_hint
* DESCRIPTION
*  draw preview OSD panel
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_preview_draw_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str1_width;
    S32 str1_height;
    S32 str2_width;
    S32 str2_height;
    S32 str1_offset_x;
    S32 str1_offset_y;
    S32 str2_offset_x;
    S32 str2_offset_y;
    S32 spacing;
    PS8 hint_str1;
    PS8 hint_str2;
    
    S32 offset_x = 0;
    S32 offset_y = 0;
    S32 truncated_width = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_CAMERA_5_OSD_LAYER__)
    if (g_camera_cntx.is_single_osd_layer == FALSE)
    {
        offset_x = g_camera_cntx.active_camera_osd_ptr->osd_region3.offset_x;
        offset_y = g_camera_cntx.active_camera_osd_ptr->osd_region3.offset_y;
        gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle3);
    }
#elif defined(__MMI_CAMERA_3_OSD_LAYER__)    
    if (g_camera_cntx.is_single_osd_layer == FALSE)
    {
        offset_x = g_camera_cntx.active_camera_osd_ptr->osd_region2.offset_x;
        offset_y = g_camera_cntx.active_camera_osd_ptr->osd_region2.offset_y;
        gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle2);
    }
#endif /* __MMI_CAMERA_5_OSD_LAYER__ */ 
    /* clear hint background region */
    
    /* draw hint */
    if (g_camera_cntx.active_camera_osd_ptr->hint_box.is_show)
    {
        hint_str1 = g_camera_cntx.hint1_buf;
        hint_str2 = g_camera_cntx.hint2_buf;
        
        /* be removed : clear hint backgounrd */

        gui_set_text_clip(
            g_camera_cntx.active_camera_osd_ptr->hint_box.offset_x,
            g_camera_cntx.active_camera_osd_ptr->hint_box.offset_y,
            g_camera_cntx.active_camera_osd_ptr->hint_box.offset_x + g_camera_cntx.active_camera_osd_ptr->hint_box.width - 1,
            g_camera_cntx.active_camera_osd_ptr->hint_box.offset_y + g_camera_cntx.active_camera_osd_ptr->hint_box.height - 1);
        
        gui_measure_string((UI_string_type) hint_str1, &str1_width, &str1_height);
        gui_measure_string((UI_string_type) hint_str2, &str2_width, &str2_height);
        
        str1_offset_x = (g_camera_cntx.active_camera_osd_ptr->hint_box.width - str1_width) >> 1;
        
        spacing = g_camera_cntx.active_camera_osd_ptr->hint_box.height - str1_height - str1_height;
        spacing = (spacing > 0) ? (spacing / 3 + 1) : 0;
        
        str1_offset_y = (g_camera_cntx.active_camera_osd_ptr->hint_box.height - str1_height - str1_height)/2;
        str2_offset_y = str1_offset_y + spacing + str1_height;
        str2_offset_x = (g_camera_cntx.active_camera_osd_ptr->hint_box.width - str2_width) >> 1;
        
        gdi_layer_reset_clip();
        gui_reset_text_clip();
        
        if ((g_camera_cntx.app_state == CAMERA_STATE_DELETE_CONFIRM) ||
            (g_camera_cntx.app_state == CAMERA_STATE_BURSTSHOT_SAVE_CONFIRM))
        {
        /* when in delete confirm screen when horizontal screen,(landscape lcm also)
        filename will overlap softkey, so we need to find another way to display filename. 
            if it will overlap softkey, we will truncate it and replace with "..." */
#if defined(__MMI_CAMERA_LANDSCAPE_LCM__)
            U16 rsk_id = STR_GLOBAL_DELETE;
            S32 lsk_offset_x;
            S32 lsk_offset_y;
            PS8 str_ptr;
            
            /* lsk */
            str_ptr = (PS8) GetString(rsk_id);
            wgui_softkey_get_offset((UI_string_type) str_ptr, &lsk_offset_x, &lsk_offset_y, &truncated_width, MMI_LEFT_SOFTKEY, MMI_FRM_SCREEN_ROTATE_270);
            
            str1_offset_x = (lsk_offset_x - str1_width) >> 1;
            
            mmi_camera_draw_style_text(
                hint_str1,
                str1_offset_x - offset_x,
                ((MMI_title_height - str1_height) >> 1) - offset_y,
                lsk_offset_x - (str1_offset_x - offset_x),
                &g_camera_cntx.active_camera_osd_ptr->hint_box.style_text);
#else /* __MMI_CAMERA_LANDSCAPE_LCM__ */
#if defined(__CAMERA_OSD_HORIZONTAL__)
            if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270)
            {
                U16 rsk_id = STR_GLOBAL_DELETE;
                S32 lsk_offset_x;
                S32 lsk_offset_y;
                PS8 str_ptr;
                
                /* lsk */
                str_ptr = (PS8) GetString(rsk_id);
                wgui_softkey_get_offset((UI_string_type) str_ptr, &lsk_offset_x, &lsk_offset_y, &truncated_width, MMI_LEFT_SOFTKEY, MMI_FRM_SCREEN_ROTATE_270);
                
                str1_offset_x = (lsk_offset_x - str1_width) >> 1;
                
                mmi_camera_draw_style_text(
                    hint_str1,
                    str1_offset_x - offset_x,
                    ((MMI_title_height - str1_height) >> 1) - offset_y,
                    lsk_offset_x - (str1_offset_x - offset_x),
                    &g_camera_cntx.active_camera_osd_ptr->hint_box.style_text);
            }
            else
#endif /* __CAMERA_OSD_HORIZONTAL__ */
            {
                mmi_camera_draw_style_text(
                    hint_str1,
                    g_camera_cntx.active_camera_osd_ptr->hint_box.offset_x + str1_offset_x - offset_x,
                    ((MMI_title_height - str1_height) >> 1) - offset_y,
                    0,
                    &g_camera_cntx.active_camera_osd_ptr->hint_box.style_text);
            }
#endif /* __MMI_CAMERA_LANDSCAPE_LCM__ */
        }
        else
        {
            mmi_camera_draw_style_text(
                hint_str1,
                g_camera_cntx.active_camera_osd_ptr->hint_box.offset_x + str1_offset_x - offset_x,
                g_camera_cntx.active_camera_osd_ptr->hint_box.offset_y + str1_offset_y - offset_y,
                0,
                &g_camera_cntx.active_camera_osd_ptr->hint_box.style_text);
            
            mmi_camera_draw_style_text(
                hint_str2,
                g_camera_cntx.active_camera_osd_ptr->hint_box.offset_x + str2_offset_x - offset_x,
                g_camera_cntx.active_camera_osd_ptr->hint_box.offset_y + str2_offset_y - offset_y,
                0,
                &g_camera_cntx.active_camera_osd_ptr->hint_box.style_text);
        }
        
        if (g_camera_cntx.fade_time != 0 && g_camera_cntx.fade_time != 255)
        {
            gui_start_timer(HINT_POPUP_FADE_TIME, mmi_camera_preview_hide_hint);
            g_camera_cntx.fade_time = 0;
        }
}
#if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
if (g_camera_cntx.is_single_osd_layer == FALSE)
{
    gdi_layer_pop_and_restore_active();
}
#endif /* __MMI_CAMERA_5_OSD_LAYER__ */ 
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_get_zoom_total_level_cnt
* DESCRIPTION
*  draw preview OSD panel
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static S32 mmi_camera_get_zoom_total_level_cnt()
{
#ifdef __CAMERA_FAST_ZOOM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    for (i = g_camera_cntx.setting.zoom_idx; i < CAMERA_FEATURE_ZOOM_COUNT; i++)
    {
        if (g_camera_feature_zoom[i] == g_camera_cntx.zoom_limit)
        {
            break;
        }
    }
    return i;
#else
    return 10;
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_draw_icon
* DESCRIPTION
*  draw preview OSD panel
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_preview_draw_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];
    U8 str_buf_UCS2[512];
    S32 str_width;
    S32 str_height;
    S32 offset_x = 0;
    S32 offset_y = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /******************************************************/
    /*                Draw normal OSD icons               */
    /******************************************************/
#if defined(__MMI_CAMERA_5_OSD_LAYER__)
    /****** draw icon MACRO ******/
#define DRAW_OSD_ICON(a,A)                                                                  \
    do {                                                                                        \
    if(g_camera_cntx.active_camera_osd_ptr->##a##.is_show)                                   \
    {                                                                                        \
    if(g_camera_cntx.is_single_osd_layer==FALSE)                                          \
    {                                                                                     \
    switch(g_camera_cntx.active_camera_osd_ptr->##a##.group_id)                        \
    {                                                                               \
                 case 0:                                                                      \
                 gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle0);           \
                 offset_x = g_camera_cntx.active_camera_osd_ptr->osd_region0.offset_x;     \
                 offset_y = g_camera_cntx.active_camera_osd_ptr->osd_region0.offset_y;     \
                 break;                                                                    \
                 case 1:                                                                      \
                 gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle1);           \
                 offset_x = g_camera_cntx.active_camera_osd_ptr->osd_region1.offset_x;     \
                 offset_y = g_camera_cntx.active_camera_osd_ptr->osd_region1.offset_y;     \
                 break;                                                                    \
                 case 2:                                                                      \
                 gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle2);           \
                 offset_x = g_camera_cntx.active_camera_osd_ptr->osd_region2.offset_x;     \
                 offset_y = g_camera_cntx.active_camera_osd_ptr->osd_region2.offset_y;     \
                 break;                                                                    \
                 case 3:                                                                      \
                 gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle3);           \
                 offset_x = g_camera_cntx.active_camera_osd_ptr->osd_region3.offset_x;     \
                 offset_y = g_camera_cntx.active_camera_osd_ptr->osd_region3.offset_y;     \
                 break;                                                                    \
                 case 4:                                                                      \
                 gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle4);           \
                 offset_x = g_camera_cntx.active_camera_osd_ptr->osd_region4.offset_x;     \
                 offset_y = g_camera_cntx.active_camera_osd_ptr->osd_region4.offset_y;     \
                 break;                                                                    \
    }                                                                               \
    }                                                                                     \
    gdi_image_draw_id(g_camera_cntx.active_camera_osd_ptr->##a##.offset_x-offset_x, \
    g_camera_cntx.active_camera_osd_ptr->##a##.offset_y-offset_y, \
    (U16)(IMG_ID_CAMERA_OSD_##A##_START+g_camera_cntx.setting.##a##+1));\
    if(g_camera_cntx.is_single_osd_layer==FALSE)                                          \
    gdi_layer_pop_and_restore_active();                                                \
    }                                                                                        \
    } while(0);
#define CHECK_OSD_LAYER_BEGIN(a)                                                       \
    do {                                                                                \
    if(g_camera_cntx.is_single_osd_layer==FALSE)                                     \
    {                                                                                \
    switch(g_camera_cntx.active_camera_osd_ptr->##a##.group_id)                   \
    {                                                                          \
              case 0:                                                                 \
              gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle0);      \
              offset_x = g_camera_cntx.active_camera_osd_ptr->osd_region0.offset_x;\
              offset_y = g_camera_cntx.active_camera_osd_ptr->osd_region0.offset_y;\
              break;                                                               \
              case 1:                                                                 \
              gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle1);      \
              offset_x = g_camera_cntx.active_camera_osd_ptr->osd_region1.offset_x;\
              offset_y = g_camera_cntx.active_camera_osd_ptr->osd_region1.offset_y;\
              break;                                                               \
              case 2:                                                                 \
              gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle2);      \
              offset_x = g_camera_cntx.active_camera_osd_ptr->osd_region2.offset_x;\
              offset_y = g_camera_cntx.active_camera_osd_ptr->osd_region2.offset_y;\
              break;                                                               \
              case 3:                                                                 \
              gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle3);      \
              offset_x = g_camera_cntx.active_camera_osd_ptr->osd_region3.offset_x;\
              offset_y = g_camera_cntx.active_camera_osd_ptr->osd_region3.offset_y;\
              break;                                                               \
              case 4:                                                                 \
              gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle4);      \
              offset_x = g_camera_cntx.active_camera_osd_ptr->osd_region4.offset_x;\
              offset_y = g_camera_cntx.active_camera_osd_ptr->osd_region4.offset_y;\
              break;                                                               \
    }                                                                          \
    }                                                                                \
    } while(0);
    
#define CHECK_OSD_LAYER_END()                     \
    do {                                           \
    if(g_camera_cntx.is_single_osd_layer==FALSE)\
    gdi_layer_pop_and_restore_active();      \
    } while(0);
#elif defined(__MMI_CAMERA_3_OSD_LAYER__)
    /****** draw icon MACRO ******/
#define DRAW_OSD_ICON(a,A)                                                                  \
    do {                                                                                        \
    if(g_camera_cntx.active_camera_osd_ptr->##a##.is_show)                                   \
    {                                                                                        \
    if(g_camera_cntx.is_single_osd_layer==FALSE)                                          \
    {                                                                                     \
    switch(g_camera_cntx.active_camera_osd_ptr->##a##.group_id)                        \
              {                                                                               \
                 case 0:                                                                      \
                 gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle0);           \
                 offset_x = g_camera_cntx.active_camera_osd_ptr->osd_region0.offset_x;     \
                 offset_y = g_camera_cntx.active_camera_osd_ptr->osd_region0.offset_y;     \
                 break;                                                                    \
                 case 1:                                                                      \
                 gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle1);           \
                 offset_x = g_camera_cntx.active_camera_osd_ptr->osd_region1.offset_x;     \
                 offset_y = g_camera_cntx.active_camera_osd_ptr->osd_region1.offset_y;     \
                 break;                                                                    \
                 case 2:                                                                      \
                 gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle2);           \
                 offset_x = g_camera_cntx.active_camera_osd_ptr->osd_region2.offset_x;     \
                 offset_y = g_camera_cntx.active_camera_osd_ptr->osd_region2.offset_y;     \
                 break;                                                                    \
              }                                                                               \
        }                                                                                     \
        gdi_image_draw_id(g_camera_cntx.active_camera_osd_ptr->##a##.offset_x-offset_x, \
        g_camera_cntx.active_camera_osd_ptr->##a##.offset_y-offset_y, \
        (U16)(IMG_ID_CAMERA_OSD_##A##_START+g_camera_cntx.setting.##a##+1));\
        if(g_camera_cntx.is_single_osd_layer==FALSE)                                          \
        gdi_layer_pop_and_restore_active();                                                \
     }                                                                                        \
    } while(0);
#define CHECK_OSD_LAYER_BEGIN(a)                                                       \
    do {                                                                                \
    if(g_camera_cntx.is_single_osd_layer==FALSE)                                     \
     {                                                                                \
     switch(g_camera_cntx.active_camera_osd_ptr->##a##.group_id)                   \
           {                                                                          \
              case 0:                                                                 \
              gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle0);      \
              offset_x = g_camera_cntx.active_camera_osd_ptr->osd_region0.offset_x;\
              offset_y = g_camera_cntx.active_camera_osd_ptr->osd_region0.offset_y;\
              break;                                                               \
              case 1:                                                                 \
              gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle1);      \
              offset_x = g_camera_cntx.active_camera_osd_ptr->osd_region1.offset_x;\
              offset_y = g_camera_cntx.active_camera_osd_ptr->osd_region1.offset_y;\
              break;                                                               \
              case 2:                                                                 \
              gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle2);      \
              offset_x = g_camera_cntx.active_camera_osd_ptr->osd_region2.offset_x;\
              offset_y = g_camera_cntx.active_camera_osd_ptr->osd_region2.offset_y;\
              break;                                                               \
           }                                                                          \
     }                                                                                \
    } while(0);
#define CHECK_OSD_LAYER_END()                     \
    do {                                           \
    if(g_camera_cntx.is_single_osd_layer==FALSE)\
    gdi_layer_pop_and_restore_active();      \
    } while(0);
#else /* __MMI_CAMERA_5_OSD_LAYER__ */ 
/****** draw icon MACRO ******/
#define DRAW_OSD_ICON(a,A)                                                                  \
    do {                                                                                        \
    if(g_camera_cntx.active_camera_osd_ptr->##a##.is_show)                                   \
     {                                                                                        \
     gdi_image_draw_id(g_camera_cntx.active_camera_osd_ptr->##a##.offset_x,                \
     g_camera_cntx.active_camera_osd_ptr->##a##.offset_y,                \
     (U16)(IMG_ID_CAMERA_OSD_##A##_START+g_camera_cntx.setting.##a##+1));\
     }                                                                                        \
    } while(0);
#define CHECK_OSD_LAYER_BEGIN(a)
#define CHECK_OSD_LAYER_END()

#endif /* __MMI_CAMERA_5_OSD_LAYER__ */ 

if (!g_camera_cntx.is_hide_osd)
{
    /* draw icon */
#ifdef __CAMERA_FEATURE_EFFECT__
    DRAW_OSD_ICON(effect, EFFECT);
#endif 
    
#ifdef __CAMERA_FEATURE_WB__
    DRAW_OSD_ICON(wb, WB);
#endif 
    
#ifdef __CAMERA_FEATURE_FLASH__
    DRAW_OSD_ICON(flash, FLASH);
#endif 
    
#ifdef __CAMERA_FEATURE_LED_HIGHLIGHT__
    DRAW_OSD_ICON(led_highlight, LED_HIGHLIGHT);
#endif 
    
#ifdef __CAMERA_FEATURE_EV__
    DRAW_OSD_ICON(ev, EV);
#endif 
    
#ifdef __CAMERA_FEATURE_NIGHT__
    DRAW_OSD_ICON(night, NIGHT);
#endif 
    
#ifdef __CAMERA_FEATURE_XENON_FLASH__
    CHECK_OSD_LAYER_BEGIN(flash_charge_status);
    if (g_camera_cntx.xenon_flash_state == MMI_CAMERA_XENON_FLASH_CHARGING)
        gdi_image_draw_id(
        g_camera_cntx.active_camera_osd_ptr->flash_charge_status.offset_x - offset_x,
        g_camera_cntx.active_camera_osd_ptr->flash_charge_status.offset_y - offset_y,
        (U16)IMG_ID_CAMERA_FLASH_CHARGING);
    else if (g_camera_cntx.xenon_flash_state == MMI_CAMERA_XENON_FLASH_READY)
        gdi_image_draw_id(
        g_camera_cntx.active_camera_osd_ptr->flash_charge_status.offset_x - offset_x,
        g_camera_cntx.active_camera_osd_ptr->flash_charge_status.offset_y - offset_y,
        (U16)IMG_ID_CAMERA_FLASH_FULL);
    CHECK_OSD_LAYER_END();        
#endif
    
    DRAW_OSD_ICON(closeup, CLOSEUP);
    
    if (g_camera_cntx.external_request_mode != MMI_CAMERA_EXTERNAL_MODE_LARGEST_RESOLUTION)
    {
        if (g_camera_cntx.active_camera_osd_ptr->image_size.is_show)
        {
            CHECK_OSD_LAYER_BEGIN(image_size);
            if (g_camera_cntx.is_tileshot == TRUE)
            {
                gdi_image_draw_id(
                    g_camera_cntx.active_camera_osd_ptr->image_size.offset_x - offset_x,
                    g_camera_cntx.active_camera_osd_ptr->image_size.offset_y - offset_y,
                    (U16) mmi_camera_get_img_size_img_id(LCD_WIDTH, LCD_HEIGHT));
            }
            else
            {
                gdi_image_draw_id(
                    g_camera_cntx.active_camera_osd_ptr->image_size.offset_x - offset_x,
                    g_camera_cntx.active_camera_osd_ptr->image_size.offset_y - offset_y,
                    (U16) mmi_camera_get_img_size_img_id(g_camera_cntx.image_width, g_camera_cntx.image_height));
            }
            CHECK_OSD_LAYER_END();
        }
    }
    
    DRAW_OSD_ICON(image_qty, IMAGE_QTY);
    
#ifdef __CAMERA_FEATURE_CONT_SHOT__
    if (g_camera_cntx.external_request_mode == MMI_CAMERA_EXTERNAL_MODE_OFF)
    {   
        /* !for External Request */
        DRAW_OSD_ICON(cont_shot, CONT_SHOT);
    }
#endif 
    
#ifdef __CAMERA_DSC_MODE__
    DRAW_OSD_ICON(dsc_mode, DSC_MODE);
#endif 
    
#ifdef __CAMERA_FEATURE_DELAY_TIMER__
    DRAW_OSD_ICON(delay_timer, DELAY_TIMER);
#endif 
    
#ifdef __CAMERA_AUTOFOCUS_MODE__
    DRAW_OSD_ICON(af_mode, FOCUS_MODE);
#endif 
    
#ifdef __CAMERA_FEATURE_AE_METER__
    DRAW_OSD_ICON(ae_meter, AE_METER);
#endif 
    
#ifdef __CAMERA_AUTOFOCUS_METERING__
    DRAW_OSD_ICON(af_meter, FOCUS_METER);
#endif 
    
#ifdef __CAMERA_FEATURE_ISO_SUPPORT__
#ifdef __CAMERA_DSC_MODE_NIGHT__
    if(g_camera_cntx.active_camera_osd_ptr->iso.is_show && g_camera_cntx.setting.dsc_mode != CAMERA_SETTING_DSC_MODE_NIGHT)
#else
        if(g_camera_cntx.active_camera_osd_ptr->iso.is_show)
#endif
        {
            CHECK_OSD_LAYER_BEGIN(iso);
            gdi_image_draw_id(g_camera_cntx.active_camera_osd_ptr->iso.offset_x - offset_x,
                g_camera_cntx.active_camera_osd_ptr->iso.offset_y - offset_y,
                (U16)(IMG_ID_CAMERA_OSD_ISO_START+g_camera_cntx.setting.iso+1));
            CHECK_OSD_LAYER_END();
        }
#endif 
        
        /* ev */
#ifdef __CAMERA_FEATURE_EV__
        DRAW_OSD_ICON(ev, EV);
        
        if (g_camera_cntx.active_camera_osd_ptr->ev_inc.is_show)
        {
            CHECK_OSD_LAYER_BEGIN(ev_inc);
            if (g_camera_cntx.setting.ev == CAMERA_SETTING_EV_COUNT - 1)
            {
                gdi_image_draw_id(
                    g_camera_cntx.active_camera_osd_ptr->ev_inc.offset_x - offset_x,
                    g_camera_cntx.active_camera_osd_ptr->ev_inc.offset_y - offset_y,
                    (U16) (IMG_ID_CAMERA_OSD_EV_INC_DIS));
            }
            else
            {
                
                if (g_camera_cntx.touch_ev_inc.is_press)
                {
                    gdi_image_draw_id(
                        g_camera_cntx.active_camera_osd_ptr->ev_inc.offset_x - offset_x,
                        g_camera_cntx.active_camera_osd_ptr->ev_inc.offset_y - offset_y,
                        (U16) (IMG_ID_CAMERA_OSD_EV_INC_SEL));
                }
                else
                {
                    gdi_image_draw_id(
                        g_camera_cntx.active_camera_osd_ptr->ev_inc.offset_x - offset_x,
                        g_camera_cntx.active_camera_osd_ptr->ev_inc.offset_y - offset_y,
                        (U16) (IMG_ID_CAMERA_OSD_EV_INC));
                }
            }
            CHECK_OSD_LAYER_END();
        }
        
        if (g_camera_cntx.active_camera_osd_ptr->ev_dec.is_show)
        {
            CHECK_OSD_LAYER_BEGIN(ev_dec);
            
            if (g_camera_cntx.setting.ev == 0)
            {
                gdi_image_draw_id(
                    g_camera_cntx.active_camera_osd_ptr->ev_dec.offset_x - offset_x,
                    g_camera_cntx.active_camera_osd_ptr->ev_dec.offset_y - offset_y,
                    (U16) (IMG_ID_CAMERA_OSD_EV_DEC_DIS));
            }
            else
            {
                if (g_camera_cntx.touch_ev_dec.is_press)
                {
                    gdi_image_draw_id(
                        g_camera_cntx.active_camera_osd_ptr->ev_dec.offset_x - offset_x,
                        g_camera_cntx.active_camera_osd_ptr->ev_dec.offset_y - offset_y,
                        (U16) (IMG_ID_CAMERA_OSD_EV_DEC_SEL));
                }
                else
                {
                    gdi_image_draw_id(
                        g_camera_cntx.active_camera_osd_ptr->ev_dec.offset_x - offset_x,
                        g_camera_cntx.active_camera_osd_ptr->ev_dec.offset_y - offset_y,
                        (U16) (IMG_ID_CAMERA_OSD_EV_DEC));
                }
            }
            CHECK_OSD_LAYER_END();
        }
        
#endif /* __CAMERA_FEATURE_EV__ */ 
        
#ifdef __CAMERA_FEATURE_ZOOM__
        /* zooming icon */
        if ((g_camera_cntx.toggle_updown_key == TRUE) && g_camera_cntx.active_camera_osd_ptr->zoom.is_show &&
            g_camera_cntx.zoom_limit != 10)
        {
            S32 num_width, num_height, num_x, num_y, num;
            U32 total_idx, current_idx;
            
            /* CALCULATE THE SLIDER LOACTION AND DRAW */
            total_idx = mmi_camera_get_zoom_total_level_cnt();
            current_idx = (U32) g_camera_cntx.setting.zoom_idx;
            
#ifdef __CAMERA_FAST_ZOOM_SUPPORT__
            if (g_camera_cntx.is_fast_zoom)
            {
        #ifdef __MTK_TARGET__
                mdi_camera_get_fast_zoom_factor(&current_idx);
                g_camera_cntx.setting.zoom_idx = mmi_camera_get_zoom_level_idx((S32)current_idx);
                current_idx = g_camera_cntx.setting.zoom_idx;
        #endif
            }
#endif /* __CAMERA_FAST_ZOOM_SUPPORT__ */ 
            
            
            if (g_camera_cntx.active_camera_osd_ptr->zoom_inc.is_show)
            {
                CHECK_OSD_LAYER_BEGIN(zoom_inc);
                if (current_idx == total_idx)
                {
                    gdi_image_draw_id(
                        g_camera_cntx.active_camera_osd_ptr->zoom_inc.offset_x - offset_x,
                        g_camera_cntx.active_camera_osd_ptr->zoom_inc.offset_y - offset_y,
                        (U16) (IMG_ID_CAMERA_OSD_ZOOM_INC_DIS));
                }
                else
                {
                    if (g_camera_cntx.touch_zoom_inc.is_press)
                    {
                        gdi_image_draw_id(
                            g_camera_cntx.active_camera_osd_ptr->zoom_inc.offset_x - offset_x,
                            g_camera_cntx.active_camera_osd_ptr->zoom_inc.offset_y - offset_y,
                            (U16) (IMG_ID_CAMERA_OSD_ZOOM_INC_SEL));
                    }
                    else
                    {
                        gdi_image_draw_id(
                            g_camera_cntx.active_camera_osd_ptr->zoom_inc.offset_x - offset_x,
                            g_camera_cntx.active_camera_osd_ptr->zoom_inc.offset_y - offset_y,
                            (U16) (IMG_ID_CAMERA_OSD_ZOOM_INC));
                    }
                }
                CHECK_OSD_LAYER_END();
            }
            
            if (g_camera_cntx.active_camera_osd_ptr->zoom_dec.is_show)
            {
                CHECK_OSD_LAYER_BEGIN(zoom_dec);
                if (current_idx == 0)
                {
                    gdi_image_draw_id(
                        g_camera_cntx.active_camera_osd_ptr->zoom_dec.offset_x - offset_x,
                        g_camera_cntx.active_camera_osd_ptr->zoom_dec.offset_y - offset_y,
                        (U16) (IMG_ID_CAMERA_OSD_ZOOM_DEC_DIS));
                }
                else
                {
                    if (g_camera_cntx.touch_zoom_dec.is_press)
                    {
                        gdi_image_draw_id(
                            g_camera_cntx.active_camera_osd_ptr->zoom_dec.offset_x - offset_x,
                            g_camera_cntx.active_camera_osd_ptr->zoom_dec.offset_y - offset_y,
                            (U16) (IMG_ID_CAMERA_OSD_ZOOM_DEC_SEL));
                    }
                    else
                    {
                        gdi_image_draw_id(
                            g_camera_cntx.active_camera_osd_ptr->zoom_dec.offset_x - offset_x,
                            g_camera_cntx.active_camera_osd_ptr->zoom_dec.offset_y - offset_y,
                            (U16) (IMG_ID_CAMERA_OSD_ZOOM_DEC));
                    }
                }
                CHECK_OSD_LAYER_END();
            }
            
            CHECK_OSD_LAYER_BEGIN(zoom);
            gdi_image_get_dimension_id(IMG_ID_CAMERA_OSD_ZOOM_BAR, &num_width, &num_height);
            gdi_image_draw_id(
                g_camera_cntx.active_camera_osd_ptr->zoom.offset_x - offset_x,
                g_camera_cntx.active_camera_osd_ptr->zoom.offset_y - offset_y,
                (U16) (IMG_ID_CAMERA_OSD_ZOOM_BAR));
            current_idx += 10;
            num_x = g_camera_cntx.active_camera_osd_ptr->zoom.offset_x - offset_x + num_width;
            num_y = g_camera_cntx.active_camera_osd_ptr->zoom.offset_y - offset_y;
            num = current_idx / 10;
            gdi_image_draw_id(num_x, num_y, IMG_ID_CAMERA_OSD_NUM_00 + num);
            
            gdi_image_get_dimension_id(IMG_ID_CAMERA_OSD_NUM_00 + num, &num_width, &num_height);
            num_x = num_x + num_width;
            gdi_image_draw_id(num_x, num_y, IMG_ID_CAMERA_OSD_NUM_DOT);
            
            gdi_image_get_dimension_id(IMG_ID_CAMERA_OSD_NUM_DOT, &num_width, &num_height);
            num = current_idx - num * 10;
            num_x = num_x + num_width;
            gdi_image_draw_id(num_x, num_y, IMG_ID_CAMERA_OSD_NUM_00 + num);
            current_idx -= 10;
            CHECK_OSD_LAYER_END();
            
    }
    
#endif /* __CAMERA_FEATURE_ZOOM__ */ 
    
    
    /* remain storage string */
    if (g_camera_cntx.active_camera_osd_ptr->remain_storage.is_show)
    {
        CHECK_OSD_LAYER_BEGIN(remain_storage);
        gui_reset_text_clip();
        gui_set_font(&MMI_small_font);
        
        sprintf(str_buf, "%d%%", g_camera_cntx.remain_percent);
        mmi_asc_to_ucs2((PS8) str_buf_UCS2, (PS8) str_buf);
        
        gui_measure_string((UI_string_type) str_buf_UCS2, &str_width, &str_height);
        
        if (g_camera_cntx.active_camera_osd_ptr->remain_storage.is_right_align)
        {
            mmi_camera_draw_style_text(
                (PS8) str_buf_UCS2,
                g_camera_cntx.active_camera_osd_ptr->remain_storage.offset_x - str_width - offset_x,
                g_camera_cntx.active_camera_osd_ptr->remain_storage.offset_y - offset_y,
                0,
                &g_camera_cntx.active_camera_osd_ptr->remain_storage.style_text);
        }
        else
        {
            mmi_camera_draw_style_text(
                (PS8) str_buf_UCS2,
                g_camera_cntx.active_camera_osd_ptr->remain_storage.offset_x - offset_x,
                g_camera_cntx.active_camera_osd_ptr->remain_storage.offset_y - offset_y,
                0,
                &g_camera_cntx.active_camera_osd_ptr->remain_storage.style_text);
        }
        CHECK_OSD_LAYER_END();
    }
}
else
{
#ifdef __CAMERA_FAST_ZOOM_SUPPORT__
    /* While the osd is hiden and fast_zoom is true, still update zoom_idx from DRV */
    if (g_camera_cntx.is_fast_zoom)
    {
        U32 current_idx;
        mdi_camera_get_fast_zoom_factor(&current_idx);
        g_camera_cntx.setting.zoom_idx = mmi_camera_get_zoom_level_idx((S32)current_idx);
    }
#endif /* __CAMERA_FAST_ZOOM_SUPPORT__ */ 
}

/* capture icon */
if (g_camera_cntx.active_camera_osd_ptr->capture.is_show)
{
    CHECK_OSD_LAYER_BEGIN(capture);
    if (g_camera_cntx.is_capturing)
    {
        gdi_image_draw_id(
            g_camera_cntx.active_camera_osd_ptr->capture.offset_x - offset_x,
            g_camera_cntx.active_camera_osd_ptr->capture.offset_y - offset_y,
            (U16) (IMG_ID_CAMERA_OSD_CAPTURE_SEL));
    }
    else
    {
        gdi_image_draw_id(
            g_camera_cntx.active_camera_osd_ptr->capture.offset_x - offset_x,
            g_camera_cntx.active_camera_osd_ptr->capture.offset_y - offset_y,
            (U16) (IMG_ID_CAMERA_OSD_CAPTURE));
    }
    CHECK_OSD_LAYER_END();
}

}


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_draw_contshot_countbar
* DESCRIPTION
*  draw contshot contbar
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_CONT_SHOT_DRAW_COUNTBAR__
static void mmi_camera_preview_draw_contshot_countbar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 img_id;
    S32 image_width;
    S32 image_height;
    S32 box_height;
    S32 offset_x;
    S32 offset_y;
    S32 remain_shot;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_camera_cntx.setting.cont_shot)
    {
    case CAMERA_SETTING_CONT_SHOT_1:
        img_id = IMG_ID_CAMERA_OSD_CONT_SHOT_BAR_1;
        break;
        
    case CAMERA_SETTING_CONT_SHOT_2:
        img_id = IMG_ID_CAMERA_OSD_CONT_SHOT_BAR_2;
        break;
        
    case CAMERA_SETTING_CONT_SHOT_3:
        img_id = IMG_ID_CAMERA_OSD_CONT_SHOT_BAR_3;
        break;
        
    default:
        img_id = 0;
    }
    
    gdi_image_get_dimension_id(img_id, &image_width, &image_height);
    
    box_height = image_height / g_camera_cntx.cont_shot_total_count;
    remain_shot = g_camera_cntx.cont_shot_total_count - g_camera_cntx.cont_shot_count;
    
    if (g_camera_osd_cntx.cont_count_bar.is_top_align)
    {
        /* top align */
        offset_x = g_camera_osd_cntx.cont_count_bar.offset_x;
        offset_y = g_camera_osd_cntx.cont_count_bar.offset_y;
        
        gdi_layer_push_clip();
        gdi_layer_set_clip(offset_x, offset_y, offset_x + image_width - 1, offset_y + box_height * remain_shot - 1);
        
        gdi_image_draw_id(offset_x, offset_y, img_id);
        gdi_layer_pop_clip();
    }
    else
    {
        /* bottom align */
        offset_x = g_camera_osd_cntx.cont_count_bar.offset_x;
        offset_y = g_camera_osd_cntx.cont_count_bar.offset_y;
        
        gdi_layer_push_clip();
        gdi_layer_set_clip(offset_x, offset_y - box_height * remain_shot + 1, offset_x + image_width - 1, offset_y);
        
        gdi_image_draw_id(offset_x, offset_y - image_height + 1, img_id);
        gdi_layer_pop_clip();
    }
    
}
#endif /* __CAMERA_FEATURE_CONT_SHOT_DRAW_COUNTBAR__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_set_hint
* DESCRIPTION
*  set hint string
* PARAMETERS
*  hint_str1       [IN]        String 1
*  hint_str2       [IN]        String 2
*  fade_time       [IN]        Hint fade out time
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_preview_set_hint(PS8 hint_str1, PS8 hint_str2, U16 fade_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clear buffer */
    memset(g_camera_cntx.hint1_buf, 0, CAMERA_HINT_BUF_SIZE);
    memset(g_camera_cntx.hint2_buf, 0, CAMERA_HINT_BUF_SIZE);
    
    if (hint_str1 != NULL)
    {
        mmi_ucs2ncpy((PS8) g_camera_cntx.hint1_buf, (PS8) hint_str1, CAMERA_HINT_CHAR_COUNT);
    }
    
    if (hint_str2 != NULL)
    {
        mmi_ucs2ncpy((PS8) g_camera_cntx.hint2_buf, (PS8) hint_str2, CAMERA_HINT_CHAR_COUNT);
    }
    
    g_camera_cntx.fade_time = fade_time;
    
}


#if defined(__CAMERA_OSD_HORIZONTAL__)
/*****************************************************************************
* FUNCTION
*  mmi_camera_config_layer_orientation
* DESCRIPTION
*  config layer orientation while HORIZONTAL_CAMERA is on.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_config_layer_orientation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
#ifdef __MMI_TVOUT__
    /*  
    * Vertical | Horizontal |
    * -------------------------
    * w/o TV | LCD      | LCD        |
    * w   TV | LCD      | LCM        |
    * -------------------------      
    * 
    * * vertical = full sceren play
    * 
    * * gdi_lcd_set_rotate_by_layer(TRUE) = LCD Rotate
    * * gdi_lcd_set_rotate_by_layer(FALSE) = LCM Rotat
    */
    
    if (!mdi_tvout_is_enable())
    {
        /* tvout not enable */
        gdi_lcd_set_rotate_by_layer(TRUE);
    }
    else if (g_camera_cntx.is_fullscreen)
    {
        /* tv-out is enable and is vertical display */
        gdi_lcd_set_rotate_by_layer(TRUE);
    }
    else
    {
        gdi_lcd_set_rotate_by_layer(FALSE);
    }
#else /* __MMI_TVOUT__ */ 
    /* if no tvout, we always use LCD rotate */
    gdi_lcd_set_rotate_by_layer(TRUE);
#endif /* __MMI_TVOUT__ */ 
    
    g_camera_cntx.previous_osd_rotate = CAMERA_DISPLAY_ROTATE_RESET;
    mmi_camera_check_osd_orientation();
    
#ifdef __MMI_TVOUT__
    /* since someone change lcd/lcm rotate mechanism (gdi_lcd_set_rotate_by_layer()), 
    we must call this function to change driver's mode */
    if (mdi_tvout_is_enable())
    {
        if (g_camera_cntx.is_fullscreen)
        {
            mdi_tvout_set_mode(MDI_TV_MODE_LCD_SCR, 0, 0);
        }
        else
        {
            mdi_tvout_set_mode(MDI_TV_MODE_MULTIMEDIA_HOR_LCD_SCR, 0, 0);
        }
    }
#endif /* __MMI_TVOUT__ */ 
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_check_osd_orientation
* DESCRIPTION
*  update display rotate (0 | 90 | 180 | 270 )
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_check_osd_orientation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
#define ROTATE_OSD_LAYER(__a__, __A__,__L__)                                                                                            \
    do {                                                                                                                                    \
    gdi_layer_push_and_set_active(g_camera_cntx.##__L__##);                                                                                 \
    gdi_layer_set_rotate(##__A__##);                                                                                                        \
    gdi_layer_resize(g_camera_cntx.active_camera_osd_ptr->##__a__##.width,g_camera_cntx.active_camera_osd_ptr->##__a__##.height);           \
    gdi_layer_set_position(g_camera_cntx.active_camera_osd_ptr->##__a__##.offset_x,g_camera_cntx.active_camera_osd_ptr->##__a__##.offset_y);\
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);                                                                                      \
    gdi_layer_pop_and_restore_active();                                                                                                     \
    } while(0);
#endif /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 
    if (g_camera_cntx.previous_osd_rotate != g_camera_cntx.osd_rotate)
    {
        switch (g_camera_cntx.osd_rotate)
        {
        case CAMERA_DISPLAY_ROTATE_0:
            g_camera_cntx.active_camera_osd_ptr = &g_camera_osd_cntx;
            g_camera_cntx.osd_UI_device_height = LCD_HEIGHT;
            g_camera_cntx.osd_UI_device_width = LCD_WIDTH;
#if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
            if (g_camera_cntx.is_single_osd_layer)
            {
                gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle0);
                gdi_layer_set_rotate(GDI_LAYER_ROTATE_0);
                gdi_layer_resize(g_camera_cntx.osd_UI_device_width, g_camera_cntx.osd_UI_device_height);
                gdi_layer_set_position(0, 0);
                gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
                gdi_layer_pop_and_restore_active();
            }
            else
            {
                ROTATE_OSD_LAYER(osd_region0, GDI_LAYER_ROTATE_0, osd_layer_handle0);
                ROTATE_OSD_LAYER(osd_region1, GDI_LAYER_ROTATE_0, osd_layer_handle1);
                ROTATE_OSD_LAYER(osd_region2, GDI_LAYER_ROTATE_0, osd_layer_handle2);
#ifdef __MMI_CAMERA_5_OSD_LAYER__
                ROTATE_OSD_LAYER(osd_region3, GDI_LAYER_ROTATE_0, osd_layer_handle3);
                ROTATE_OSD_LAYER(osd_region4, GDI_LAYER_ROTATE_0, osd_layer_handle4);
#endif
            }
#else /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 
            /*@ Add by Vincent  */
            /* if using idp rotate, we need to config osd buffer for idp rotate only, we do not need to config original osd layer as horizontal */
#if defined(__MDI_CAMERA_HW_ROTATOR_SUPPORT__) && defined(__CAMERA_OSD_HORIZONTAL__)
            kal_wap_trace(MOD_MMI, TRACE_GROUP_3, "[cam][6253] 6) config idp_rotate_layer (width,height) = (%d,%d)",g_camera_cntx.osd_UI_device_width,g_camera_cntx.osd_UI_device_height);
            gdi_layer_push_and_set_active(g_camera_cntx.osd_idp_rotate_layer_handle);
            gdi_layer_set_rotate(GDI_LAYER_ROTATE_0);
            gdi_layer_resize(g_camera_cntx.osd_UI_device_width, g_camera_cntx.osd_UI_device_height);
            gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
            gdi_layer_pop_and_restore_active();                
#else
            gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle0);
            gdi_layer_toggle_double();
            gdi_layer_set_rotate(GDI_LAYER_ROTATE_0);
            gdi_layer_resize(g_camera_cntx.osd_UI_device_width, g_camera_cntx.osd_UI_device_height);
            gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
            gdi_layer_pop_and_restore_active();
#endif
#endif /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 
            break;
#if defined(__CAMERA_OSD_HORIZONTAL__)
        case CAMERA_DISPLAY_ROTATE_270:
            g_camera_cntx.active_camera_osd_ptr = &g_camera_osd_cntx_270;
            g_camera_cntx.osd_UI_device_height = LCD_WIDTH;
            g_camera_cntx.osd_UI_device_width = LCD_HEIGHT;
#if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
            if (g_camera_cntx.is_single_osd_layer)
            {
                gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle0);
                gdi_layer_set_rotate(GDI_LAYER_ROTATE_90);
                gdi_layer_resize(g_camera_cntx.osd_UI_device_width, g_camera_cntx.osd_UI_device_height);
                gdi_layer_set_position(0, 0);
                gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
                gdi_layer_pop_and_restore_active();
            }
            else
            {
                ROTATE_OSD_LAYER(osd_region0, GDI_LAYER_ROTATE_90, osd_layer_handle0);
                ROTATE_OSD_LAYER(osd_region1, GDI_LAYER_ROTATE_90, osd_layer_handle1);
                ROTATE_OSD_LAYER(osd_region2, GDI_LAYER_ROTATE_90, osd_layer_handle2);
#ifdef __MMI_CAMERA_5_OSD_LAYER__
                ROTATE_OSD_LAYER(osd_region3, GDI_LAYER_ROTATE_90, osd_layer_handle3);
                ROTATE_OSD_LAYER(osd_region4, GDI_LAYER_ROTATE_90, osd_layer_handle4);
#endif
            }
#else /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 
            /*@ Add by Vincent */
            /* if using idp rotate, we need to config osd buffer for idp rotate only, we do not need to config original osd layer as horizontal */
#if defined(__MDI_CAMERA_HW_ROTATOR_SUPPORT__) && defined(__CAMERA_OSD_HORIZONTAL__)
            kal_wap_trace(MOD_MMI, TRACE_GROUP_3, "[cam][6253] 6) config idp_rotate_layer (width,height) = (%d,%d)",g_camera_cntx.osd_UI_device_width,g_camera_cntx.osd_UI_device_height);
            gdi_layer_push_and_set_active(g_camera_cntx.osd_idp_rotate_layer_handle);
            gdi_layer_set_rotate(GDI_LAYER_ROTATE_90);
            gdi_layer_resize(g_camera_cntx.osd_UI_device_width, g_camera_cntx.osd_UI_device_height);
            gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
            gdi_layer_pop_and_restore_active();                
#else
            gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle0);
            gdi_layer_toggle_double();
            gdi_layer_set_rotate(GDI_LAYER_ROTATE_90);
            gdi_layer_resize(g_camera_cntx.osd_UI_device_width, g_camera_cntx.osd_UI_device_height);
            gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
            gdi_layer_pop_and_restore_active();
#endif
            
            break;
#endif /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 
            break;
#endif /* __CAMERA_OSD_HORIZONTAL__ */
        default:
            ASSERT(0);
            break;
        }
        
        g_camera_cntx.previous_osd_rotate = g_camera_cntx.osd_rotate;
        mmi_camera_update_osd_touch_icon();
}
}

#endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_get_zoom_limit
* DESCRIPTION
*  get zoom limit
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static U16 mmi_camera_get_zoom_limit(U16 capture_size_enum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 zoom_limit = 10;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(ISP_SUPPORT) && defined(__MTK_TARGET__)
    /* get zoom_limit from sensor driver */
    if (g_camera_cntx.has_camera_previewed == TRUE)
    {
        ASSERT(CAMERA_SETTING_IMAGE_SIZE_COUNT>capture_size_enum);
        zoom_limit = g_camera_cntx.max_zoom_limit[capture_size_enum];
    }
    else
#endif /* defined(ISP_SUPPORT) && defined(__MTK_TARGET__) */ 
    {
        switch(capture_size_enum)
        {
#if defined(__CAMERA_FEATURE_IMAGE_SIZE_LL__)
        case CAMERA_SETTING_IMAGE_SIZE_LL:
            zoom_limit = CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT;
            break;
#endif
#if defined(__CAMERA_FEATURE_IMAGE_SIZE_L__)
        case CAMERA_SETTING_IMAGE_SIZE_L:
            zoom_limit = CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT;
            break;
#endif
#if defined(__CAMERA_FEATURE_IMAGE_SIZE_M__)
        case CAMERA_SETTING_IMAGE_SIZE_M:
            zoom_limit = CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT;
            break;
#endif
#if defined(__CAMERA_FEATURE_IMAGE_SIZE_S__)
        case CAMERA_SETTING_IMAGE_SIZE_S:
            zoom_limit = CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT;
            break;
#endif
#if defined(__CAMERA_FEATURE_IMAGE_SIZE_SS__)
        case CAMERA_SETTING_IMAGE_SIZE_SS:
            zoom_limit = CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT;
            break;
#endif
        default:
            break;            
        }    
    }
    return zoom_limit;
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_update_capture_size
* DESCRIPTION
*  update capture size and preview size due to setting change
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_camera_preview_update_capture_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
    /* check if is burst shot, if yes, change and store previous capture size */
    if (g_camera_cntx.setting.cont_shot == CAMERA_SETTING_CONT_SHOT_BURST)
    {    
        /* if not correct image size, change to it */
        if (g_camera_cntx.setting.image_size != CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX)
        {
            g_camera_cntx.image_size_before_burst = g_camera_cntx.setting.image_size;
            g_camera_cntx.setting.image_size = CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX;
        }
    }
#endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 
    
#ifdef __CAMERA_FEATURE_IMAGE_SIZE_LL__
    UPDATE_IMAGE_SIZE(LL);
#endif /* __CAMERA_FEATURE_IMAGE_SIZE_LL__ */ 
    
#ifdef __CAMERA_FEATURE_IMAGE_SIZE_L__
    UPDATE_IMAGE_SIZE(L);
#endif /* __CAMERA_FEATURE_IMAGE_SIZE_L__ */ 
    
#ifdef __CAMERA_FEATURE_IMAGE_SIZE_M__
    UPDATE_IMAGE_SIZE(M);
#endif /* __CAMERA_FEATURE_IMAGE_SIZE_M__ */ 
    
#ifdef __CAMERA_FEATURE_IMAGE_SIZE_S__
    UPDATE_IMAGE_SIZE(S);
#endif /* __CAMERA_FEATURE_IMAGE_SIZE_S__ */ 
    
#ifdef __CAMERA_FEATURE_IMAGE_SIZE_SS__
    UPDATE_IMAGE_SIZE(SS);
#endif /* __CAMERA_FEATURE_IMAGE_SIZE_SS__ */ 
    
    
    g_camera_cntx.zoom_limit = mmi_camera_get_zoom_limit(g_camera_cntx.setting.image_size);
    
#if defined(__MMI_CAMERA_QVGA_WALLPAPER_ON_WQVGA_LCM__) || defined(__MMI_CAMERA_QVGA_WALLPAPER_ON_WQVGA_LCM_FOR_MODIS__)
    if (g_camera_cntx.image_width < g_camera_cntx.image_height)
#else
        if ((g_camera_cntx.image_width == LCD_WIDTH) && (g_camera_cntx.image_height == LCD_HEIGHT))
#endif
        {
            g_camera_cntx.is_fullscreen = TRUE;
            
#if defined(__CAMERA_OSD_HORIZONTAL__)
            if (g_camera_cntx.is_tileshot != TRUE)
            {
                g_camera_cntx.previous_osd_rotate = CAMERA_DISPLAY_ROTATE_RESET;
                g_camera_cntx.osd_rotate = CAMERA_DISPLAY_ROTATE_0;
                g_camera_cntx.capture_path = CAPTURE_FROM_LAYER;
            }
#else 
            g_camera_cntx.capture_path = CAPTURE_FROM_LAYER;
#endif 
        }
        else
        {
#if defined(__CAMERA_OSD_HORIZONTAL__)
            if (g_camera_cntx.is_fullscreen == TRUE)
            {
                g_camera_cntx.previous_osd_rotate = g_camera_cntx.osd_rotate;
                g_camera_cntx.osd_rotate = CAMERA_DISPLAY_ROTATE_270;
                g_camera_cntx.capture_path = CAPTURE_FROM_MEMORY;
            }
#else /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
            g_camera_cntx.capture_path = CAPTURE_FROM_MEMORY;
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
            g_camera_cntx.is_fullscreen = FALSE;
        }
        
        
#if defined(__CAMERA_OSD_HORIZONTAL__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST__)
        if (g_camera_cntx.setting.cont_shot == CAMERA_SETTING_CONT_SHOT_BURST)
        {
            g_camera_cntx.previous_osd_rotate = CAMERA_DISPLAY_ROTATE_RESET;
            g_camera_cntx.osd_rotate = CAMERA_DISPLAY_ROTATE_270;
            g_camera_cntx.capture_path = CAPTURE_FROM_MEMORY;
        }
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST__) */ 
        
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_get_zoom_factor
* DESCRIPTION
*  get zoom factor based on feature define
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static U16 mmi_camera_preview_get_zoom_factor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CAMERA_FEATURE_ZOOM__
    if (g_camera_cntx.setting.zoom_idx >= CAMERA_FEATURE_ZOOM_COUNT)
    {
        mmi_camera_restore_setting();
        return 0;
    }
    else
    {
        return g_camera_feature_zoom[g_camera_cntx.setting.zoom_idx];
    }
#else
    return 10;
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_ev_inc_key_press
* DESCRIPTION
*  preview right arrow pressed, adjust EV
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_preview_ev_inc_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__
    mmi_camera_stop_app_watchdog();
#endif
    if (g_camera_cntx.app_state == CAMERA_STATE_PREVIEW)
    {
        if (g_camera_cntx.setting.ev < CAMERA_SETTING_EV_COUNT - 1)
        {
            g_camera_cntx.touch_ev_inc.is_press = TRUE;
            
            g_camera_cntx.setting.ev++;
            
            mdi_camera_update_para_ev(camera_ev_command_map[g_camera_cntx.setting.ev]);
            
            mmi_camera_preview_set_hint(NULL, NULL, 0);
            mmi_camera_preview_draw_osd();
            
            mmi_camera_blt();
            
            if (g_camera_cntx.is_ev_inc_pressed)
            {
                gui_start_timer(100, mmi_camera_preview_ev_inc_key_press);
            }
            else
            {
                /* first time press up arrow, use longer time */
                gui_start_timer(300, mmi_camera_preview_ev_inc_key_press);
                g_camera_cntx.is_ev_inc_pressed = TRUE;
            }
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_ev_inc_key_release
* DESCRIPTION
*  preview right arrow release
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_preview_ev_inc_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_camera_preview_ev_inc_key_press);
#ifdef __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__
    mmi_camera_restart_app_watchdog();
#endif
    if (g_camera_cntx.app_state == CAMERA_STATE_PREVIEW)
    {
        g_camera_cntx.is_ev_inc_pressed = FALSE;
        g_camera_cntx.touch_ev_inc.is_press = FALSE;
        mmi_camera_preview_draw_osd();
        mmi_camera_blt();
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_ev_dec_key_press
* DESCRIPTION
*  preview left arrow pressed, adjust EV
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_preview_ev_dec_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__
    mmi_camera_stop_app_watchdog();
#endif
    if (g_camera_cntx.app_state == CAMERA_STATE_PREVIEW)
    {
        if (g_camera_cntx.setting.ev > 0)
        {
            g_camera_cntx.touch_ev_dec.is_press = TRUE;
            
            g_camera_cntx.setting.ev--;
            
            mdi_camera_update_para_ev(camera_ev_command_map[g_camera_cntx.setting.ev]);
            
            mmi_camera_preview_set_hint(NULL, NULL, 0);
            mmi_camera_preview_draw_osd();
            mmi_camera_blt();
            
            if (g_camera_cntx.is_ev_dec_pressed)
            {
                gui_start_timer(100, mmi_camera_preview_ev_dec_key_press);
            }
            else
            {
                /* first time press up arrow, use longer time */
                gui_start_timer(300, mmi_camera_preview_ev_dec_key_press);
                g_camera_cntx.is_ev_dec_pressed = TRUE;
            }
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_ev_dec_key_release
* DESCRIPTION
*  preview left arrow release
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_preview_ev_dec_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_camera_preview_ev_dec_key_press);
#ifdef __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__
    mmi_camera_restart_app_watchdog();
#endif
    if (g_camera_cntx.app_state == CAMERA_STATE_PREVIEW)
    {
        g_camera_cntx.is_ev_dec_pressed = FALSE;
        g_camera_cntx.touch_ev_dec.is_press = FALSE;
        mmi_camera_preview_draw_osd();
        mmi_camera_blt();
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_initilize_zoom_factor
* DESCRIPTION
*  initialize zoom factor
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_initilize_zoom_factor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;
    U16 zoom_limit = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* LL, L, M, S, SS */
#ifdef __CAMERA_FEATURE_IMAGE_SIZE_SS__
    zoom_limit = mdi_camera_get_max_zoom_factor(CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH, CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT);
    if (CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT > zoom_limit)
    {
        g_camera_cntx.max_zoom_limit[index++] = zoom_limit;
    }
    else
    {
        g_camera_cntx.max_zoom_limit[index++] = CAMERA_FEATURE_PREVIEW_SS_ZOOM_LIMIT;
    }
    
    if (g_camera_cntx.setting.image_size == CAMERA_SETTING_IMAGE_SIZE_SS)
        g_camera_cntx.zoom_limit = g_camera_cntx.max_zoom_limit[CAMERA_SETTING_IMAGE_SIZE_SS];
#endif /* __CAMERA_FEATURE_IMAGE_SIZE_SS__ */ 
    
#ifdef __CAMERA_FEATURE_IMAGE_SIZE_S__
    zoom_limit = mdi_camera_get_max_zoom_factor(CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH, CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT);
    if (CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT > zoom_limit)
    {
        g_camera_cntx.max_zoom_limit[index++] = zoom_limit;
    }
    else
    {
        g_camera_cntx.max_zoom_limit[index++] = CAMERA_FEATURE_PREVIEW_S_ZOOM_LIMIT;
    }
    
    if (g_camera_cntx.setting.image_size == CAMERA_SETTING_IMAGE_SIZE_S)
        g_camera_cntx.zoom_limit = g_camera_cntx.max_zoom_limit[CAMERA_SETTING_IMAGE_SIZE_S];
    
#endif /* __CAMERA_FEATURE_IMAGE_SIZE_S__ */ 
    
#ifdef __CAMERA_FEATURE_IMAGE_SIZE_M__
    zoom_limit = mdi_camera_get_max_zoom_factor(CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH, CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT);
    if (CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT > zoom_limit)
    {
        g_camera_cntx.max_zoom_limit[index++] = zoom_limit;
    }
    else
    {
        g_camera_cntx.max_zoom_limit[index++] = CAMERA_FEATURE_PREVIEW_M_ZOOM_LIMIT;
    }
    
    if (g_camera_cntx.setting.image_size == CAMERA_SETTING_IMAGE_SIZE_M)
        g_camera_cntx.zoom_limit = g_camera_cntx.max_zoom_limit[CAMERA_SETTING_IMAGE_SIZE_M];
#endif /* __CAMERA_FEATURE_IMAGE_SIZE_M__ */ 
    
#ifdef __CAMERA_FEATURE_IMAGE_SIZE_L__
    zoom_limit = mdi_camera_get_max_zoom_factor(CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH, CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT);
    if (CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT > zoom_limit)
    {
        g_camera_cntx.max_zoom_limit[index++] = zoom_limit;
    }
    else
    {
        g_camera_cntx.max_zoom_limit[index++] = CAMERA_FEATURE_PREVIEW_L_ZOOM_LIMIT;
    }
    if (g_camera_cntx.setting.image_size == CAMERA_SETTING_IMAGE_SIZE_L)
        g_camera_cntx.zoom_limit = g_camera_cntx.max_zoom_limit[CAMERA_SETTING_IMAGE_SIZE_L];
#endif /* __CAMERA_FEATURE_IMAGE_SIZE_L__ */ 
    
#ifdef __CAMERA_FEATURE_IMAGE_SIZE_LL__
    zoom_limit = mdi_camera_get_max_zoom_factor(CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH, CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT);
    if (CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT > zoom_limit)
    {
        g_camera_cntx.max_zoom_limit[index++] = zoom_limit;
    }
    else
    {
        g_camera_cntx.max_zoom_limit[index++] = CAMERA_FEATURE_PREVIEW_LL_ZOOM_LIMIT;
    }
    if (g_camera_cntx.setting.image_size == CAMERA_SETTING_IMAGE_SIZE_LL)
        g_camera_cntx.zoom_limit = g_camera_cntx.max_zoom_limit[CAMERA_SETTING_IMAGE_SIZE_LL];
    
#endif /* __CAMERA_FEATURE_IMAGE_SIZE_LL__ */ 
    
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_zoom_in
* DESCRIPTION
*  zoom out
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_ZOOM__
static void mmi_camera_preview_zoom_in(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 zoom_factor;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_camera_cntx.app_state == CAMERA_STATE_PREVIEW)
    {
        if (g_camera_cntx.setting.zoom_idx < CAMERA_FEATURE_ZOOM_COUNT - 1)
        {
            if (g_camera_cntx.zoom_limit > mmi_camera_preview_get_zoom_factor())
            {
                g_camera_cntx.setting.zoom_idx += 1;
                
                g_camera_cntx.touch_zoom_inc.is_press = TRUE;
                
                /* get zoom factor based on features define */
                zoom_factor = mmi_camera_preview_get_zoom_factor();
                
                mdi_camera_update_para_zoom(zoom_factor);
                
                mmi_camera_preview_set_hint(NULL, NULL, 0);
                mmi_camera_preview_draw_osd();
                mmi_camera_blt();
                
#if defined(ISP_SUPPORT)
                /* only build-in camera use long pressed zooming feature */
                /* since backend module's zooming time is not stable, will cause zooming jump two level */
#ifdef __CAMERA_FAST_ZOOM_SUPPORT__
                if (!g_camera_cntx.is_up_arrow_pressed)
                {
                    gui_start_timer(200, mmi_camera_start_fast_zoom_in);
                }
#else /* __CAMERA_FAST_ZOOM_SUPPORT__ */ 
                if (g_camera_cntx.is_up_arrow_pressed)
                {
                    gui_start_timer(100, mmi_camera_preview_zoom_in);
                }
                else
                {
                    /* first time press up arrow, use longer time */
                    gui_start_timer(300, mmi_camera_preview_zoom_in);
                }
#endif /* __CAMERA_FAST_ZOOM_SUPPORT__ */ 
#endif /* defined(ISP_SUPPORT) */ 
                
            }
        }
        else
        {
            g_camera_cntx.touch_zoom_inc.is_press = FALSE;
            mmi_camera_preview_draw_osd();
            mmi_camera_blt();
        }
    }
    
}
#endif /* __CAMERA_FEATURE_ZOOM__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_draw_osd_timer
* DESCRIPTION
*  redraw osd timer
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_preview_draw_osd_timer()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camera_preview_draw_osd();
    mmi_camera_blt();
    if (g_camera_cntx.is_draw_timer_on)
    {
        gui_start_timer(100, mmi_camera_preview_draw_osd_timer);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_zoom_out
* DESCRIPTION
*  zoom out
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_ZOOM__
static void mmi_camera_preview_zoom_out(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 zoom_factor;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_camera_cntx.app_state == CAMERA_STATE_PREVIEW)
    {
        if (g_camera_cntx.setting.zoom_idx > 0)
        {
            g_camera_cntx.touch_zoom_dec.is_press = TRUE;
            
            g_camera_cntx.setting.zoom_idx -= 1;
            
            /* get zoom factor based on features define */
            zoom_factor = mmi_camera_preview_get_zoom_factor();
            
            mdi_camera_update_para_zoom(zoom_factor);
            
            mmi_camera_preview_set_hint(NULL, NULL, 0);
            mmi_camera_preview_draw_osd();
            mmi_camera_blt();
            
#if defined(ISP_SUPPORT)
#ifdef __CAMERA_FAST_ZOOM_SUPPORT__
            if (!g_camera_cntx.is_down_arrow_pressed)
            {
                gui_start_timer(200, mmi_camera_start_fast_zoom_out);
            }
#else /* __CAMERA_FAST_ZOOM_SUPPORT__ */ 
            /* only build-in camera use long pressed zooming feature */
            /* since backend module's zooming time is not stable, will cause zooming jump two level */
            if (g_camera_cntx.is_down_arrow_pressed)
            {
                gui_start_timer(100, mmi_camera_preview_zoom_out);
            }
            else
            {
                /* first time press down arrow, use longer time */
                gui_start_timer(300, mmi_camera_preview_zoom_out);
            }
#endif /* __CAMERA_FAST_ZOOM_SUPPORT__ */ 
#endif /* defined(ISP_SUPPORT) */ 
            
        }
        else
        {
            g_camera_cntx.touch_zoom_dec.is_press = FALSE;
            mmi_camera_preview_draw_osd();
            mmi_camera_blt();
        }
    }
}
#endif /* __CAMERA_FEATURE_ZOOM__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_up_arrow_press
* DESCRIPTION
*  preview up arrow pressed, adjust zooming
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#if defined(__CAMERA_FEATURE_ZOOM__)
static void mmi_camera_preview_up_arrow_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__
    mmi_camera_stop_app_watchdog();
#endif
    if (!g_camera_cntx.is_up_arrow_pressed)
    {
        switch (g_camera_cntx.up_key)
        {
        case CAMERA_ZOOMIN:
            mmi_camera_preview_zoom_in();
            break;
        }
    }
    
    g_camera_cntx.is_up_arrow_pressed = TRUE;
}
#endif /* defined(__CAMERA_FEATURE_ZOOM__)*/ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_up_arrow_release
* DESCRIPTION
*  preview up arrow release, stop adjust zooming
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#if defined(__CAMERA_FEATURE_ZOOM__)
static void mmi_camera_preview_up_arrow_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.is_up_arrow_pressed = FALSE;
    
    g_camera_cntx.touch_zoom_inc.is_press = FALSE;
    
#ifdef __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__
    mmi_camera_restart_app_watchdog();
#endif
    
    switch (g_camera_cntx.up_key)
    {
    case CAMERA_ZOOMIN:
#ifdef __CAMERA_FAST_ZOOM_SUPPORT__
        if (g_camera_cntx.is_fast_zoom == TRUE)
        {
            g_camera_cntx.is_draw_timer_on = FALSE;
            mmi_camera_stop_fast_zoom();
            mmi_camera_preview_draw_osd();
            mmi_camera_blt();
            gui_cancel_timer(mmi_camera_preview_draw_osd_timer);
        }
        else if (g_camera_cntx.is_fast_zoom == FALSE)
        {
            mmi_camera_preview_draw_osd();
            mmi_camera_blt();
            gui_cancel_timer(mmi_camera_start_fast_zoom_in);
        }
#else /* __CAMERA_FAST_ZOOM_SUPPORT__ */ 
        gui_cancel_timer(mmi_camera_preview_zoom_in);
        mmi_camera_preview_draw_osd();
        mmi_camera_blt();
#endif /* __CAMERA_FAST_ZOOM_SUPPORT__ */ 
        break;
    }
}
#endif /* defined(__CAMERA_FEATURE_ZOOM__)*/ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_down_arrow_press
* DESCRIPTION
*  preview down arrow pressed, adjust zooming
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#if defined(__CAMERA_FEATURE_ZOOM__)
static void mmi_camera_preview_down_arrow_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__
    mmi_camera_stop_app_watchdog();
#endif
    
    if (!g_camera_cntx.is_down_arrow_pressed)
    {
        switch (g_camera_cntx.down_key)
        {
        case CAMERA_ZOOMOUT:
            mmi_camera_preview_zoom_out();
            break;
        }
    }
    
    g_camera_cntx.is_down_arrow_pressed = TRUE;
    
}
#endif /* defined(__CAMERA_FEATURE_ZOOM__)*/ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_down_arrow_release
* DESCRIPTION
*  preview down arrow release, stop adjust zooming
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#if defined(__CAMERA_FEATURE_ZOOM__)
static void mmi_camera_preview_down_arrow_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.is_down_arrow_pressed = FALSE;
    
    g_camera_cntx.touch_zoom_dec.is_press = FALSE;
    
#ifdef __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__
    mmi_camera_restart_app_watchdog();
#endif
    
    switch (g_camera_cntx.down_key)
    {
    case CAMERA_ZOOMOUT:
#ifdef __CAMERA_FAST_ZOOM_SUPPORT__
        if (g_camera_cntx.is_fast_zoom == TRUE)
        {
            g_camera_cntx.is_draw_timer_on = FALSE;
            mmi_camera_stop_fast_zoom();
            mmi_camera_preview_draw_osd();
            mmi_camera_blt();
            gui_cancel_timer(mmi_camera_preview_draw_osd_timer);
        }
        else if (g_camera_cntx.is_fast_zoom == FALSE)
        {
            mmi_camera_preview_draw_osd();
            mmi_camera_blt();
            gui_cancel_timer(mmi_camera_start_fast_zoom_out);
        }
#else /* __CAMERA_FAST_ZOOM_SUPPORT__ */ 
        gui_cancel_timer(mmi_camera_preview_zoom_out);
        mmi_camera_preview_draw_osd();
        mmi_camera_blt();
#endif /* __CAMERA_FAST_ZOOM_SUPPORT__ */ 
        break;
    }
    
}
#endif /* defined(__CAMERA_FEATURE_ZOOM__)*/ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_effect_hotkey_press
* DESCRIPTION
*  effect setting hotkey pressed
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#if defined(__CAMERA_FEATURE_EFFECT__)
static void mmi_camera_preview_effect_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__
    mmi_camera_restart_app_watchdog();
#endif
    mmi_camera_preview_effect_change(TRUE);
}
#endif /* defined(__CAMERA_FEATURE_EFFECT__) */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_effect_change
* DESCRIPTION
*  chage effect
* PARAMETERS
*  is_next     [IN]        Change effect to next, otherwise is previous
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_EFFECT__
static void mmi_camera_preview_effect_change(BOOL is_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];
    BOOL is_custom_fx = FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_next)
    {
        if (g_camera_cntx.setting.effect < CAMERA_SETTING_EFFECT_COUNT - 1)
        {
            g_camera_cntx.setting.effect++;
        }
        else
        {
            g_camera_cntx.setting.effect = 0;
        }
    }
    else
    {
        if (g_camera_cntx.setting.effect >= 1)
        {
            g_camera_cntx.setting.effect--;
        }
        else
        {
            g_camera_cntx.setting.effect = CAMERA_SETTING_EFFECT_COUNT - 1;
        }
    }
    
#ifndef __CAMERA_FEATURE_HIDE_HINT__
    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_CAMERA_EFFECT_SETTING));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");
    
    mmi_camera_preview_set_hint(
        (PS8) str_buf,
        (PS8) GetString((U16) (g_camera_cntx.setting.effect + STR_ID_CAMERA_EFFECT_START + 1)),
        HINT_POPUP_FADE_TIME);
#endif /* __CAMERA_FEATURE_HIDE_HINT__ */ 
    
    mmi_camera_preview_draw_osd();
    
#ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_1__
    if (g_camera_cntx.setting.effect == CAMERA_SETTING_EFFECT_CUSTOM_FX_1)
    {
        mdi_camera_update_para_effect(camera_effect_command_map[CAMERA_SETTING_EFFECT_NORMAL]);
        mdi_camera_update_para_brightness(g_camera_cntx.setting.fx_brightness[0]);
        mdi_camera_update_para_saturation(g_camera_cntx.setting.fx_saturation[0]);
        mdi_camera_update_para_contrast(g_camera_cntx.setting.fx_contrast[0]);
        mdi_camera_update_para_hue(g_camera_cntx.setting.fx_hue[0]);
        
        is_custom_fx = TRUE;
    }
#endif /* __CAMERA_FEATURE_EFFECT_CUSTOM_FX_1__ */ 
    
#ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_2__
    if (g_camera_cntx.setting.effect == CAMERA_SETTING_EFFECT_CUSTOM_FX_2)
    {
        mdi_camera_update_para_effect(camera_effect_command_map[CAMERA_SETTING_EFFECT_NORMAL]);
        mdi_camera_update_para_brightness(g_camera_cntx.setting.fx_brightness[1]);
        mdi_camera_update_para_saturation(g_camera_cntx.setting.fx_saturation[1]);
        mdi_camera_update_para_contrast(g_camera_cntx.setting.fx_contrast[1]);
        mdi_camera_update_para_hue(g_camera_cntx.setting.fx_hue[1]);
        
        is_custom_fx = TRUE;
    }
#endif /* __CAMERA_FEATURE_EFFECT_CUSTOM_FX_2__ */ 
    
#ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_3__
    if (g_camera_cntx.setting.effect == CAMERA_SETTING_EFFECT_CUSTOM_FX_3)
    {
        mdi_camera_update_para_effect(camera_effect_command_map[CAMERA_SETTING_EFFECT_NORMAL]);
        mdi_camera_update_para_brightness(g_camera_cntx.setting.fx_brightness[2]);
        mdi_camera_update_para_saturation(g_camera_cntx.setting.fx_saturation[2]);
        mdi_camera_update_para_contrast(g_camera_cntx.setting.fx_contrast[2]);
        mdi_camera_update_para_hue(g_camera_cntx.setting.fx_hue[2]);
        
        is_custom_fx = TRUE;
    }
#endif /* __CAMERA_FEATURE_EFFECT_CUSTOM_FX_3__ */ 
    
    if (!is_custom_fx)
    {
        mdi_camera_update_para_effect(camera_effect_command_map[g_camera_cntx.setting.effect]);
        mdi_camera_update_para_brightness(128);
        mdi_camera_update_para_saturation(128);
        mdi_camera_update_para_contrast(128);
        mdi_camera_update_para_hue(0);
    }
    
    mmi_camera_blt();
    
}
#endif /* __CAMERA_FEATURE_EFFECT__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_wb_hotkey_press
* DESCRIPTION
*  wb hotkey pressed
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#if defined(__CAMERA_FEATURE_WB__)
static void mmi_camera_preview_wb_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__
    mmi_camera_restart_app_watchdog();
#endif
    mmi_camera_preview_wb_change(TRUE);
}
#endif /* defined(__CAMERA_FEATURE_WB__) */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_wb_change
* DESCRIPTION
*  change wb
* PARAMETERS
*  is_next     [IN]        Change wb to next, otherwise is previous
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_WB__
static void mmi_camera_preview_wb_change(BOOL is_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_next)
    {
        if (g_camera_cntx.setting.wb < CAMERA_SETTING_WB_COUNT - 1)
        {
            g_camera_cntx.setting.wb++;
        }
        else
        {
            g_camera_cntx.setting.wb = 0;
        }
    }
    else
    {
        if (g_camera_cntx.setting.wb >= 1)
        {
            g_camera_cntx.setting.wb--;
        }
        else
        {
            g_camera_cntx.setting.wb = CAMERA_SETTING_WB_COUNT - 1;
        }
    }
    
#ifndef __CAMERA_FEATURE_HIDE_HINT__
    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_CAMERA_WB));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");
    
    mmi_camera_preview_set_hint(
        (PS8) str_buf,
        (PS8) GetString((U16) (g_camera_cntx.setting.wb + STR_ID_CAMERA_WB_START + 1)),
        HINT_POPUP_FADE_TIME);
#endif /* __CAMERA_FEATURE_HIDE_HINT__ */ 
    
    mdi_camera_update_para_wb(camera_wb_command_map[g_camera_cntx.setting.wb]);
    
    mmi_camera_preview_draw_osd();
    
    mmi_camera_blt();
    
}
#endif /* __CAMERA_FEATURE_WB__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_led_highlight_hotkey_press
* DESCRIPTION
*  led highlight hotkey pressed
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#if defined(__CAMERA_FEATURE_LED_HIGHLIGHT__)
static void mmi_camera_preview_led_highlight_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__
    mmi_camera_restart_app_watchdog();
#endif
    mmi_camera_preview_led_highlight_change(TRUE);
}
#endif /* defined(__CAMERA_FEATURE_LED_HIGHLIGHT__) */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_led_highlight_change
* DESCRIPTION
*  led highlight change
* PARAMETERS
*  is_next     [IN]        Change led highlight to next, otherwise is previous
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_LED_HIGHLIGHT__
static void mmi_camera_preview_led_highlight_change(BOOL is_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_next)
    {
        if (g_camera_cntx.setting.led_highlight < CAMERA_SETTING_LED_HIGHLIGHT_COUNT - 1)
        {
            g_camera_cntx.setting.led_highlight++;
        }
        else
        {
            g_camera_cntx.setting.led_highlight = 0;
        }
    }
    else
    {
        if (g_camera_cntx.setting.led_highlight >= 1)
        {
            g_camera_cntx.setting.led_highlight--;
        }
        else
        {
            g_camera_cntx.setting.led_highlight = CAMERA_SETTING_LED_HIGHLIGHT_COUNT - 1;
        }
    }
    
#ifndef __CAMERA_FEATURE_HIDE_HINT__
    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_CAMERA_LED_HIGHLIGHT));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");
    
    mmi_camera_preview_set_hint(
        (PS8) str_buf,
        (PS8) GetString((U16) (g_camera_cntx.setting.led_highlight + STR_ID_CAMERA_LED_HIGHLIGHT_START + 1)),
        HINT_POPUP_FADE_TIME);
#endif /* __CAMERA_FEATURE_HIDE_HINT__ */ 
    
    mmi_camera_preview_draw_osd();
    
    mmi_camera_blt();
    
    /* trun on/off led highlight */
    mmi_camera_turn_on_preview_led_highlight();
    
}
#endif /* __CAMERA_FEATURE_LED_HIGHLIGHT__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_flash_hotkey_press
* DESCRIPTION
*  flash hotkey pressed
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#if defined(__CAMERA_FEATURE_FLASH__)
static void mmi_camera_preview_flash_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__
    mmi_camera_restart_app_watchdog();
#endif
    mmi_camera_preview_flash_change(TRUE);
}
#endif /* defined(__CAMERA_FEATURE_FLASH__)*/ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_flash_change
* DESCRIPTION
*  flash change
* PARAMETERS
*  is_next     [IN]        Change led highlight to next, otherwise is previous
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_FLASH__
static void mmi_camera_preview_flash_change(BOOL is_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_next)
    {
        if (g_camera_cntx.setting.flash < CAMERA_SETTING_FLASH_COUNT - 1)
        {
            g_camera_cntx.setting.flash++;
        }
        else
        {
            g_camera_cntx.setting.flash = 0;
        }
    }
    else
    {
        if (g_camera_cntx.setting.flash >= 1)
        {
            g_camera_cntx.setting.flash--;
        }
        else
        {
            g_camera_cntx.setting.flash = CAMERA_SETTING_FLASH_COUNT - 1;
        }
    }
    
#ifndef __CAMERA_FEATURE_HIDE_HINT__
    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_CAMERA_FLASH));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");
    
    mmi_camera_preview_set_hint(
        (PS8) str_buf,
        (PS8) GetString((U16) (g_camera_cntx.setting.flash + STR_ID_CAMERA_FLASH_START + 1)),
        HINT_POPUP_FADE_TIME);
#endif /* __CAMERA_FEATURE_HIDE_HINT__ */ 
    
#ifdef __CAMERA_FEATURE_XENON_FLASH__
    if (g_camera_cntx.setting.flash == CAMERA_SETTING_FLASH_OFF)
        g_camera_cntx.xenon_flash_state = MMI_CAMERA_XENON_FLASH_OFF;
#endif
    /* update quality parameter to mdi_camera */
    mdi_camera_update_para_flash(camera_flash_command_map[g_camera_cntx.setting.flash]);
    
    mmi_camera_preview_draw_osd();
    mmi_camera_blt();
    
}
#endif /* __CAMERA_FEATURE_FLASH__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_night_hotkey_press
* DESCRIPTION
*  night hotkey pressed
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#if defined(__CAMERA_FEATURE_NIGHT__)
static void mmi_camera_preview_night_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__
    mmi_camera_restart_app_watchdog();
#endif
    mmi_camera_preview_night_change(TRUE);
}
#endif /* defined(__CAMERA_FEATURE_NIGHT__)*/ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_night_change
* DESCRIPTION
*  night change
* PARAMETERS
*  is_next     [IN]        Change night to next, otherwise is previous
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_NIGHT__
static void mmi_camera_preview_night_change(BOOL is_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_next)
    {
        if (g_camera_cntx.setting.night < CAMERA_SETTING_NIGHT_COUNT - 1)
        {
            g_camera_cntx.setting.night++;
        }
        else
        {
            g_camera_cntx.setting.night = 0;
        }
    }
    else
    {
        if (g_camera_cntx.setting.night >= 1)
        {
            g_camera_cntx.setting.night--;
        }
        else
        {
            g_camera_cntx.setting.night = CAMERA_SETTING_NIGHT_COUNT - 1;
        }
    }
    
#ifndef __CAMERA_FEATURE_HIDE_HINT__
    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_CAMERA_NIGHT));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");
    
    mmi_camera_preview_set_hint(
        (PS8) str_buf,
        (PS8) GetString((U16) (g_camera_cntx.setting.night + STR_ID_CAMERA_NIGHT_START + 1)),
        HINT_POPUP_FADE_TIME);
#endif /* __CAMERA_FEATURE_HIDE_HINT__ */ 
    
    mmi_camera_preview_draw_osd();
    
    mmi_camera_blt();
    
    mdi_camera_update_para_night(g_camera_cntx.setting.night);
    
}
#endif /* __CAMERA_FEATURE_NIGHT__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_image_size_hotkey_press
* DESCRIPTION
*  image size hotkey pressed
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_preview_image_size_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__
    mmi_camera_restart_app_watchdog();
#endif
    mmi_camera_preview_image_size_change(TRUE);
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_image_size_change
* DESCRIPTION
*  image size change
* PARAMETERS
*  is_next     [IN]        Change image size to next, otherwise is previous
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_preview_image_size_change(BOOL is_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];
    S32 prev_preview_width;
    S32 prev_preview_height;
    BOOL prev_is_fullscreen;
    BOOL prev_is_tileshot;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* change size */
    if (is_next)
    {
        if (g_camera_cntx.setting.image_size < CAMERA_SETTING_IMAGE_SIZE_COUNT - 1)
        {
            g_camera_cntx.setting.image_size++;
        }
        else
        {
            g_camera_cntx.setting.image_size = 0;
        }
    }
    else
    {
        if (g_camera_cntx.setting.image_size >= 1)
        {
            g_camera_cntx.setting.image_size--;
        }
        else
        {
            g_camera_cntx.setting.image_size = CAMERA_SETTING_IMAGE_SIZE_COUNT - 1;
        }
    }
    
    
    
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
    /* disable burst shot if size can not support */
    if ((g_camera_cntx.setting.image_size != CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX) &&
        (g_camera_cntx.setting.cont_shot == CAMERA_SETTING_CONT_SHOT_BURST))
    {
        g_camera_cntx.setting.cont_shot = CAMERA_DEFAULT_SETTING_CONT_SHOT;
    }
#endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 
    
    /* backup previous */
    prev_preview_width = g_camera_cntx.preview_width;
    prev_preview_height = g_camera_cntx.preview_height;
    prev_is_fullscreen = g_camera_cntx.is_fullscreen;
    prev_is_tileshot = g_camera_cntx.is_tileshot;
    
#ifndef __CAMERA_FEATURE_HIDE_HINT__
    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_CAMERA_IMAGE_SIZE));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");
    
    mmi_camera_preview_set_hint(
        (PS8) str_buf,
        (PS8) GetString((U16) (g_camera_cntx.image_size_str_id[g_camera_cntx.setting.image_size])),
        HINT_POPUP_FADE_TIME);
#endif /* __CAMERA_FEATURE_HIDE_HINT__ */ 
    
    /* update parameters */
    mmi_camera_preview_update_capture_size();
    
    if ((prev_preview_width != g_camera_cntx.preview_width) ||
        (prev_preview_height != g_camera_cntx.preview_height) ||
        (prev_is_fullscreen != g_camera_cntx.is_fullscreen) ||
        (g_camera_cntx.setting.zoom_idx != CAMERA_DEFAULT_SETTING_ZOOM_IDX))
    {
        /* since preview para is changed, stop and restart preview */
        mmi_camera_preview_stop();
        
        /* restore zoom setting */
        g_camera_cntx.setting.zoom_idx = CAMERA_DEFAULT_SETTING_ZOOM_IDX;
        
#if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
        if (prev_is_fullscreen != g_camera_cntx.is_fullscreen)
        {
            if (g_camera_cntx.is_fullscreen && g_camera_cntx.setting.add_frame != 0)
            {
                g_camera_cntx.is_single_osd_layer = TRUE;
            }
            else
            {
                g_camera_cntx.is_single_osd_layer = FALSE;
            }
            mmi_camera_free_osd_layer();
            mmi_camera_create_osd_layer();
        }
#endif /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 
        
        /* set blt */
        mmi_camera_preview_set_blt_layer(FALSE);
        
        /* update add frame */
#ifdef __CAMERA_FEATURE_ADD_FRAME__
        if (g_camera_cntx.add_frame_layer_handle == GDI_LAYER_EMPTY_HANDLE)
            mmi_camera_create_add_frame_layer();
#endif 
        
#if defined(__CAMERA_OSD_HORIZONTAL__)
        mmi_camera_check_osd_orientation();
        
        /* update functions of up/down/left/right key */
        mmi_camera_preview_set_key_hdlr();
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
        
        /* clear background color */
        mmi_camera_preview_clear_background();
        mmi_camera_preview_draw_osd();
        
#if defined(__MMI_TVOUT__) && defined(__CAMERA_OSD_HORIZONTAL__)
        
        if (!mdi_tvout_is_enable())
        {
            /* tvout not enable */
            gdi_lcd_set_rotate_by_layer(TRUE);
        }
        else if (g_camera_cntx.is_fullscreen)
        {
            /* tv-out is enable and is vertical display */
            gdi_lcd_set_rotate_by_layer(TRUE);
        }
        else
        {
            gdi_lcd_set_rotate_by_layer(FALSE);
        }
        
        if (mdi_tvout_is_enable())
        {
            /* when HORIZONTAL is enable, the fullscreen means vertical screen */
            if (g_camera_cntx.is_fullscreen)
            {
                mdi_tvout_set_mode(MDI_TV_MODE_LCD_SCR, 0, 0);
            }
            else
            {
                mdi_tvout_set_mode(MDI_TV_MODE_MULTIMEDIA_HOR_LCD_SCR, 0, 0);
            }
        }
#endif /* defined(__MMI_TVOUT__) && defined(__CAMERA_OSD_HORIZONTAL__) */ 
        
        mmi_camera_blt();
        mmi_camera_preview_free_preview_resource();
        {
            S32 offset_x = 0;
            S32 offset_y = 0;
            
#ifdef HORIZONTAL_CAMERA
#ifndef __MMI_CAMERA_QVGA_WALLPAPER_ON_WQVGA_LCM__
            offset_x = (LCD_HEIGHT - g_camera_cntx.preview_width) >>1 ;
            offset_y = (LCD_WIDTH - g_camera_cntx.preview_height) >> 1;
#endif
#else 
            offset_x = (LCD_WIDTH - g_camera_cntx.preview_width) >> 1;
            offset_y = (LCD_HEIGHT - g_camera_cntx.preview_height) >> 1;
#endif 
#ifdef __MMI_CAMERA_TOP_ALIGN__
            offset_x = 0;
            offset_y = 0;
#endif
            mmi_camera_preview_create_preview_resource(
                offset_x,
                offset_y,
                g_camera_cntx.preview_width,
                g_camera_cntx.preview_height,
                g_camera_cntx.lcm_rotate);
        }
        
        /* set blt layer for previwing */
        mmi_camera_preview_set_blt_layer(TRUE);
        
        mmi_camera_preview_start();
        
        /* check if preview success */
        if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
        {
            mmi_camera_display_error_popup();
        }
        
}
else
{
    mdi_camera_update_para_zoom(mmi_camera_preview_get_zoom_factor());
    mdi_camera_update_para_image_size(g_camera_cntx.image_width, g_camera_cntx.image_height);
    
    mmi_camera_preview_draw_osd();
    mmi_camera_blt();
}

}


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_image_qty_hotkey_press
* DESCRIPTION
*  imaeg qty hotkey pressed
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_preview_image_qty_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__
    mmi_camera_restart_app_watchdog();
#endif
    mmi_camera_preview_image_qty_change(TRUE);
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_image_qty_change
* DESCRIPTION
*  image qty hotkey pressed
* PARAMETERS
*  is_next     [IN]        Change image qty to next, otherwise is previous
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_preview_image_qty_change(BOOL is_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_next)
    {
        if (g_camera_cntx.setting.image_qty < CAMERA_SETTING_IMAGE_QTY_COUNT - 1)
        {
            g_camera_cntx.setting.image_qty++;
        }
        else
        {
            g_camera_cntx.setting.image_qty = 0;
        }
    }
    else
    {
        if (g_camera_cntx.setting.image_qty >= 1)
        {
            g_camera_cntx.setting.image_qty--;
        }
        else
        {
            g_camera_cntx.setting.image_qty = CAMERA_SETTING_IMAGE_QTY_COUNT - 1;
        }
    }
    
#ifndef __CAMERA_FEATURE_HIDE_HINT__
    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_CAMERA_IMAGE_QTY));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");
    
    mmi_camera_preview_set_hint(
        (PS8) str_buf,
        (PS8) GetString((U16) (g_camera_cntx.setting.image_qty + STR_ID_CAMERA_IMAGE_QTY_START + 1)),
        HINT_POPUP_FADE_TIME);
#endif /* __CAMERA_FEATURE_HIDE_HINT__ */ 
    
    /* update quality parameter to mdi_camera */
    mdi_camera_update_para_image_qty(camera_image_qty_command_map[g_camera_cntx.setting.image_qty]);
    
    mmi_camera_preview_draw_osd();
    
    mmi_camera_blt();
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_cont_shot_hotkey_press
* DESCRIPTION
*  cont shot hotkey pressed
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#if defined(__CAMERA_FEATURE_CONT_SHOT__)
static void mmi_camera_preview_cont_shot_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__
    mmi_camera_restart_app_watchdog();
#endif
    mmi_camera_preview_cont_shot_change(TRUE);
}
#endif /* defined(__CAMERA_FEATURE_CONT_SHOT__)*/ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_cont_shot_change
* DESCRIPTION
*  cont shot change
* PARAMETERS
*  is_next     [IN]        Change cont shot to next, otherwise is previous
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_CONT_SHOT__
static void mmi_camera_preview_cont_shot_change(BOOL is_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];
    BOOL need_restart_preview;
    BOOL need_change_capture_size = FALSE;
    S32 prev_preview_width;
    S32 prev_preview_height;
    
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
    BOOL need_restore_image_size;
#endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    need_restart_preview = FALSE;
    
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
    /* inti var */
    need_restore_image_size = FALSE;
    
    /* leaving burst shot */
    if (g_camera_cntx.setting.cont_shot == CAMERA_SETTING_CONT_SHOT_BURST)
    {
        need_restore_image_size = TRUE;
    }
#endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 
    
    if (is_next)
    {
        if (g_camera_cntx.setting.cont_shot < CAMERA_SETTING_CONT_SHOT_COUNT - 1)
        {
            g_camera_cntx.setting.cont_shot++;
        }
        else
        {
            g_camera_cntx.setting.cont_shot = 0;
        }
    }
    else
    {
        if (g_camera_cntx.setting.cont_shot >= 1)
        {
            g_camera_cntx.setting.cont_shot--;
        }
        else
        {
            g_camera_cntx.setting.cont_shot = CAMERA_SETTING_CONT_SHOT_COUNT - 1;
        }
    }
    
    
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
    /* check change out from burst need to change image and preview size */
    if (need_restore_image_size)
    {
        if (g_camera_cntx.image_size_before_burst != CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX)
        {
            /* restore preview */
            g_camera_cntx.setting.image_size = g_camera_cntx.image_size_before_burst;
            need_change_capture_size = TRUE;
        }
    }
    
    /* check if change to burst need to change image and preview size */
    if (g_camera_cntx.setting.cont_shot == CAMERA_SETTING_CONT_SHOT_BURST)
    {
        /* store image size before enter burst shot */
        g_camera_cntx.image_size_before_burst = g_camera_cntx.setting.image_size;
        
        /* if not correct image size, change to it */
        if (g_camera_cntx.setting.image_size != CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX)
        {
            g_camera_cntx.setting.image_size = CAMERA_FEATURE_CONT_SHOT_BURST_IMAGE_IDX;
            need_change_capture_size = TRUE;
        }
    }
#endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 
    
    if (need_change_capture_size)
    {
        prev_preview_width = g_camera_cntx.preview_width;
        prev_preview_height = g_camera_cntx.preview_height;
        
        mmi_camera_preview_update_capture_size();
        mdi_camera_update_para_image_size(g_camera_cntx.image_width, g_camera_cntx.image_height);
        
        if ((prev_preview_width != g_camera_cntx.preview_width) ||
            (prev_preview_height != g_camera_cntx.preview_height) ||
            (g_camera_cntx.setting.zoom_idx != CAMERA_DEFAULT_SETTING_ZOOM_IDX))
        {
            need_restart_preview = TRUE;
        }
        
#if defined(__CAMERA_OSD_HORIZONTAL__)
        if (g_camera_cntx.previous_osd_rotate == CAMERA_DISPLAY_ROTATE_RESET)
        {
            need_restart_preview = TRUE;
        }
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
    }
    
#ifndef __CAMERA_FEATURE_HIDE_HINT__
    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_CAMERA_CONT_SHOT));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");
    
    mmi_camera_preview_set_hint(
        (PS8) str_buf,
        (PS8) GetString((U16) (g_camera_cntx.setting.cont_shot + STR_ID_CAMERA_CONT_SHOT_START + 1)),
        HINT_POPUP_FADE_TIME);
#endif /* __CAMERA_FEATURE_HIDE_HINT__ */ 
    
    
    if (need_restart_preview)
    {
        /* since preview para is changed, stop and restart preview */
        mmi_camera_preview_stop();
        
#if (defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)) && defined(__CAMERA_OSD_HORIZONTAL__)
#if defined(__CAMERA_FEATURE_CONT_SHOT_BURST__)
        if (g_camera_cntx.setting.cont_shot == CAMERA_SETTING_CONT_SHOT_BURST)
        {
            /* not fullscreen(lcm size) but using single layer, change to using multi osd */
            if (g_camera_cntx.is_fullscreen == FALSE && g_camera_cntx.is_single_osd_layer == TRUE)
            {
                g_camera_cntx.is_single_osd_layer = FALSE;
                
                mmi_camera_free_osd_layer();
                mmi_camera_create_osd_layer();
                /* update osd layers */
                g_camera_cntx.previous_osd_rotate = CAMERA_DISPLAY_ROTATE_RESET;
            }
        } 
        else
#endif
            /* full screen and using multi-osd but with add_frame, change to using single osd */
            if (g_camera_cntx.is_fullscreen == TRUE && g_camera_cntx.is_single_osd_layer == FALSE &&
                g_camera_cntx.setting.add_frame != 0)
            {
                g_camera_cntx.is_single_osd_layer = TRUE;
                
                mmi_camera_free_osd_layer();
                mmi_camera_create_osd_layer();
                /* update osd layers */
                g_camera_cntx.previous_osd_rotate = CAMERA_DISPLAY_ROTATE_RESET;
                
            }
#endif /* (defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)) && defined(__CAMERA_OSD_HORIZONTAL__) */ 
            
            
            /* check if need to update osd orienation */
#if defined(__CAMERA_OSD_HORIZONTAL__)
            if (g_camera_cntx.previous_osd_rotate == CAMERA_DISPLAY_ROTATE_RESET)
            {
                mmi_camera_check_osd_orientation();
                mmi_camera_preview_set_key_hdlr();
            }
#endif
            
            /* restore zoom setting */
            g_camera_cntx.setting.zoom_idx = CAMERA_DEFAULT_SETTING_ZOOM_IDX;
            
            /* update add frame */
#ifdef __CAMERA_FEATURE_ADD_FRAME__
            mmi_camera_create_add_frame_layer();
#endif 
            
            /* set blt */
            mmi_camera_preview_set_blt_layer(FALSE);
            
            /* clear background color */
            mmi_camera_preview_clear_background();
            
            mmi_camera_preview_draw_osd();
            
#if defined(__MMI_TVOUT__) && defined(__CAMERA_OSD_HORIZONTAL__)
            if (!mdi_tvout_is_enable())
            {
                /* tvout not enable */
                gdi_lcd_set_rotate_by_layer(TRUE);
            }
            else if (g_camera_cntx.is_fullscreen)
            {
                /* tv-out is enable and is vertical display */
                gdi_lcd_set_rotate_by_layer(TRUE);
            }
            else
            {
                gdi_lcd_set_rotate_by_layer(FALSE);
            }
            
            if (mdi_tvout_is_enable())
            {
                /* when HORIZONTAL is enable, the fullscreen means vertical screen */
                if (g_camera_cntx.is_fullscreen)
                {
                    mdi_tvout_set_mode(MDI_TV_MODE_LCD_SCR, 0, 0);
                }
                else
                {
                    mdi_tvout_set_mode(MDI_TV_MODE_MULTIMEDIA_HOR_LCD_SCR, 0, 0);
                }
            }
#endif /* defined(__MMI_TVOUT__) && defined(__CAMERA_OSD_HORIZONTAL__) */ 
            
            mmi_camera_blt();
            
            {
                S32 offset_x = 0;
                S32 offset_y = 0;
                
                mmi_camera_preview_free_preview_resource();
#ifdef HORIZONTAL_CAMERA
#ifndef __MMI_CAMERA_QVGA_WALLPAPER_ON_WQVGA_LCM__
                offset_x = (LCD_HEIGHT - g_camera_cntx.preview_width) >>1 ;
                offset_y = (LCD_WIDTH - g_camera_cntx.preview_height) >> 1;
#endif
#else 
                offset_x = (LCD_WIDTH - g_camera_cntx.preview_width) >> 1;
                offset_y = (LCD_HEIGHT - g_camera_cntx.preview_height) >> 1;
#endif 
#ifdef __MMI_CAMERA_TOP_ALIGN__
                offset_x = 0;
                offset_y = 0;
#endif
                mmi_camera_preview_create_preview_resource(
                    offset_x,
                    offset_y,
                    g_camera_cntx.preview_width,
                    g_camera_cntx.preview_height,
                    g_camera_cntx.lcm_rotate);
            }
            
            /* set blt layer for previwing */
            mmi_camera_preview_set_blt_layer(TRUE);
            
            mmi_camera_preview_start();
            
            /* check if preview success */
            if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
            {
                mmi_camera_display_error_popup();
                return;
            }
}
else
{
    mmi_camera_preview_draw_osd();
    mmi_camera_blt();
}

}
#endif /* __CAMERA_FEATURE_CONT_SHOT__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_delay_timer_hotkey_press
* DESCRIPTION
*  delay_timer hotkey pressed
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#if defined(__CAMERA_FEATURE_DELAY_TIMER__)
static void mmi_camera_preview_delay_timer_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__
    mmi_camera_restart_app_watchdog();
#endif
    mmi_camera_preview_delay_timer_change(TRUE);
}
#endif /* defined(__CAMERA_FEATURE_DELAY_TIMER__)*/ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_delay_timer_change
* DESCRIPTION
*  delay_timer change
* PARAMETERS
*  is_next     [IN]        Change delay timer to next, otherwise is previous
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_DELAY_TIMER__
static void mmi_camera_preview_delay_timer_change(BOOL is_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_next)
    {
        if (g_camera_cntx.setting.delay_timer < CAMERA_SETTING_DELAY_TIMER_COUNT - 1)
        {
            g_camera_cntx.setting.delay_timer++;
        }
        else
        {
            g_camera_cntx.setting.delay_timer = 0;
        }
    }
    else
    {
        if (g_camera_cntx.setting.delay_timer >= 1)
        {
            g_camera_cntx.setting.delay_timer--;
        }
        else
        {
            g_camera_cntx.setting.delay_timer = CAMERA_SETTING_DELAY_TIMER_COUNT - 1;
        }
    }
    
#ifndef __CAMERA_FEATURE_HIDE_HINT__
    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_CAMERA_DELAY_TIMER));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");
    
    mmi_camera_preview_set_hint(
        (PS8) str_buf,
        (PS8) GetString((U16) (g_camera_cntx.setting.delay_timer + STR_ID_CAMERA_DELAY_TIMER_START + 1)),
        HINT_POPUP_FADE_TIME);
#endif /* __CAMERA_FEATURE_HIDE_HINT__ */ 
    
    mmi_camera_preview_draw_osd();
    mmi_camera_blt();
    
}
#endif /* __CAMERA_FEATURE_DELAY_TIMER__ */ 

#ifdef __CAMERA_DSC_MODE__
/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_dsc_mode_hotkey_press
* DESCRIPTION
*  shot mode hotkey pressed
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_preview_dsc_mode_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__
    mmi_camera_restart_app_watchdog();
#endif
    mmi_camera_preview_dsc_mode_change(TRUE);
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_dsc_mode_change
* DESCRIPTION
*  shot mode hotkey pressed
* PARAMETERS
*  is_next     [IN]        Change shot mode to next, otherwise is previous
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_preview_dsc_mode_change(BOOL is_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_next)
    {
        if (g_camera_cntx.setting.dsc_mode < CAMERA_SETTING_DSC_MODE_COUNT - 1)
        {
            g_camera_cntx.setting.dsc_mode++;
        }
        else
        {
            g_camera_cntx.setting.dsc_mode = 0;
        }
    }
    else
    {
        if (g_camera_cntx.setting.dsc_mode >= 1)
        {
            g_camera_cntx.setting.dsc_mode--;
        }
        else
        {
            g_camera_cntx.setting.dsc_mode = CAMERA_SETTING_DSC_MODE_COUNT - 1;
        }
    }
    
    
    /* night mode: should also set night_mode for DRV use */
#ifdef __CAMERA_DSC_MODE_NIGHT__
    if(g_camera_cntx.setting.dsc_mode == CAMERA_SETTING_DSC_MODE_NIGHT)
        g_camera_cntx.setting.night = 1;
    else
        g_camera_cntx.setting.night = 0;
#endif 
    
    /* update quality parameter to mdi_camera */
    mdi_camera_update_para_dsc_mode(camera_dsc_mode_command_map[g_camera_cntx.setting.dsc_mode]);
    
#ifndef __CAMERA_FEATURE_HIDE_HINT__
    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_CAMERA_DSC_MODE));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");
    
    mmi_camera_preview_set_hint(
        (PS8) str_buf,
        (PS8) GetString((U16) (g_camera_cntx.setting.dsc_mode + STR_ID_CAMERA_DSC_MODE_START + 1)),
        HINT_POPUP_FADE_TIME);
#endif /* __CAMERA_FEATURE_HIDE_HINT__ */
    mmi_camera_preview_draw_osd();
    
    mmi_camera_blt();
}
#endif /* __CAMERA_DSC_MODE__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_iso_hotkey_press
* DESCRIPTION
*  shot mode hotkey pressed
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_ISO_SUPPORT__
static void mmi_camera_preview_iso_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__
    mmi_camera_restart_app_watchdog();
#endif
    /* night mode conflict with iso */
#ifdef __CAMERA_DSC_MODE_NIGHT__
    if (g_camera_cntx.setting.dsc_mode == CAMERA_SETTING_DSC_MODE_NIGHT)
        return;
#endif
    mmi_camera_preview_iso_change(TRUE);
}
#endif /* __CAMERA_FEATURE_ISO_SUPPORT__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_iso_change
* DESCRIPTION
*  shot mode hotkey pressed
* PARAMETERS
*  is_next     [IN]        Change shot mode to next, otherwise is previous
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_ISO_SUPPORT__
static void mmi_camera_preview_iso_change(BOOL is_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_next)
    {
        if (g_camera_cntx.setting.iso < CAMERA_SETTING_ISO_COUNT - 1)
        {
            g_camera_cntx.setting.iso++;
        }
        else
        {
            g_camera_cntx.setting.iso = 0;
        }
    }
    else
    {
        if (g_camera_cntx.setting.iso >= 1)
        {
            g_camera_cntx.setting.iso--;
        }
        else
        {
            g_camera_cntx.setting.iso = CAMERA_SETTING_ISO_COUNT - 1;
        }
    }
    
    /* update quality parameter to mdi_camera */
    mdi_camera_update_para_iso(camera_iso_command_map[g_camera_cntx.setting.iso]);
    
#ifndef __CAMERA_FEATURE_HIDE_HINT__
    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_CAMERA_ISO));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");
    
    mmi_camera_preview_set_hint(
        (PS8) str_buf,
        (PS8) GetString((U16) (g_camera_cntx.setting.iso + STR_ID_CAMERA_ISO_START + 1)),
        HINT_POPUP_FADE_TIME);
#endif /* __CAMERA_FEATURE_HIDE_HINT__ */
    
    mmi_camera_preview_draw_osd();
    
    mmi_camera_blt();
}
#endif /* __CAMERA_FEATURE_ISO_SUPPORT__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_ae_meter_hotkey_press
* DESCRIPTION
*  shot mode hotkey pressed
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_AE_METER__
static void mmi_camera_preview_ae_meter_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__
    mmi_camera_restart_app_watchdog();
#endif
    mmi_camera_preview_ae_meter_change(TRUE);
}
#endif /* __CAMERA_FEATURE_AE_METER__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_ae_meter_change
* DESCRIPTION
*  shot mode hotkey pressed
* PARAMETERS
*  is_next     [IN]        Change shot mode to next, otherwise is previous
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_AE_METER__
static void mmi_camera_preview_ae_meter_change(BOOL is_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_next)
    {
        if (g_camera_cntx.setting.ae_meter < CAMERA_SETTING_AE_METER_COUNT - 1)
        {
            g_camera_cntx.setting.ae_meter++;
        }
        else
        {
            g_camera_cntx.setting.ae_meter = 0;
        }
    }
    else
    {
        if (g_camera_cntx.setting.ae_meter >= 1)
        {
            g_camera_cntx.setting.ae_meter--;
        }
        else
        {
            g_camera_cntx.setting.ae_meter = CAMERA_SETTING_AE_METER_COUNT - 1;
        }
    }
    
    /* update quality parameter to mdi_camera */
    mdi_camera_update_para_ae_meter(camera_ae_meter_command_map[g_camera_cntx.setting.ae_meter]);
    
#ifndef __CAMERA_FEATURE_HIDE_HINT__
    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_CAMERA_AE_METER));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");
    
    mmi_camera_preview_set_hint(
        (PS8) str_buf,
        (PS8) GetString((U16) (g_camera_cntx.setting.ae_meter + STR_ID_CAMERA_AE_METER_START + 1)),
        HINT_POPUP_FADE_TIME);
#endif /* __CAMERA_FEATURE_HIDE_HINT__ */
    
    mmi_camera_preview_draw_osd();
    
    mmi_camera_blt();
}
#endif /* __CAMERA_FEATURE_AE_METER__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_af_mode_hotkey_press
* DESCRIPTION
*  AF mode hotkey pressed
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#if defined(__CAMERA_AUTOFOCUS_MODE__)
static void mmi_camera_preview_af_mode_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__
    mmi_camera_restart_app_watchdog();
#endif
    mmi_camera_preview_af_mode_change(TRUE);
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_af_mode_change
* DESCRIPTION
*  shot mode hotkey pressed
* PARAMETERS
*  is_next     [IN]        Change shot mode to next, otherwise is previous
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_preview_af_mode_change(BOOL is_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_next)
    {
        if (g_camera_cntx.setting.af_mode + 1 < CAMERA_SETTING_AUTOFOCUS_MODE_COUNT)
        {
            g_camera_cntx.setting.af_mode++;
        }
        else
        {
            g_camera_cntx.setting.af_mode = 0;
        }
    }
    else
    {
        if (g_camera_cntx.setting.af_mode >= 1)
        {
            g_camera_cntx.setting.af_mode--;
        }
        else
        {
            g_camera_cntx.setting.af_mode = CAMERA_SETTING_AUTOFOCUS_MODE_COUNT - 1;
        }
    }
    
    
    /* update quality parameter to mdi_camera */
    mdi_camera_update_para_af_mode(camera_autofocus_mode_command_map[g_camera_cntx.setting.af_mode]);
    
#ifndef __CAMERA_FEATURE_HIDE_HINT__
    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_CAMERA_AUTOFOCUS_MODE));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");
    
    mmi_camera_preview_set_hint(
        (PS8) str_buf,
        (PS8) GetString((U16) (g_camera_cntx.setting.af_mode + STR_ID_CAMERA_AUTOFOCUS_MODE_START + 1)),
        HINT_POPUP_FADE_TIME);
#endif /* __CAMERA_FEATURE_HIDE_HINT__ */        
    mmi_camera_preview_draw_osd();
    
    mmi_camera_blt();
}

#endif /* defined(__CAMERA_AUTOFOCUS_MODE__) */ /* __CAMERA_FEATURE_STORAGE__ */


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_af_meter_hotkey_press
* DESCRIPTION
*  AF metering hotkey pressed
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#if defined(__CAMERA_AUTOFOCUS_METERING__)
static void mmi_camera_preview_af_meter_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__
    mmi_camera_restart_app_watchdog();
#endif
    mmi_camera_preview_af_meter_change(TRUE);
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_af_meter_change
* DESCRIPTION
*  shot mode hotkey pressed
* PARAMETERS
*  is_next     [IN]        Change shot mode to next, otherwise is previous
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_preview_af_meter_change(BOOL is_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_next)
    {
        if (g_camera_cntx.setting.af_meter + 1 < CAMERA_SETTING_AUTOFOCUS_COUNT)
        {
            g_camera_cntx.setting.af_meter++;
        }
        else
        {
            g_camera_cntx.setting.af_meter = 0;
        }
    }
    else
    {
        if (g_camera_cntx.setting.af_meter >= 1)
        {
            g_camera_cntx.setting.af_meter--;
        }
        else
        {
            g_camera_cntx.setting.af_meter = CAMERA_SETTING_AUTOFOCUS_COUNT - 1;
        }
    }
    
    /* update quality parameter to mdi_camera */
    mdi_camera_update_para_af_metering(camera_autofocus_command_map[g_camera_cntx.setting.af_meter]);
    
#ifndef __CAMERA_FEATURE_HIDE_HINT__
    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_CAMERA_AUTOFOCUS_METERING));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");
    
    mmi_camera_preview_set_hint(
        (PS8) str_buf,
        (PS8) GetString((U16) (g_camera_cntx.setting.af_meter + STR_ID_CAMERA_AUTOFOCUS_START + 1)),
        HINT_POPUP_FADE_TIME);
#endif /* __CAMERA_FEATURE_HIDE_HINT__ */        
    mmi_camera_preview_draw_osd();
    
    mmi_camera_blt();
}

#endif /* defined(__CAMERA_AUTOFOCUS_METERING__) */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_storage_hotkey_press
* DESCRIPTION
*  delay_timer hotkey pressed
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#if defined(__CAMERA_FEATURE_STORAGE__)
static void mmi_camera_preview_storage_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__
    mmi_camera_restart_app_watchdog();
#endif
    mmi_camera_preview_storage_change(TRUE);
}
#endif /* defined(__CAMERA_FEATURE_STORAGE__)*/ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_storage_change
* DESCRIPTION
*  storage change
* PARAMETERS
*  is_next     [IN]        Change storage to next, otherwise is previous
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_STORAGE__
static void mmi_camera_preview_storage_change(BOOL is_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];
    U16 cur_storage;
    S32 create_result;
    U8 total_num;
    U8 highlighted_idx;
    U32 drv_inline_list_p;
    BOOL is_storage_path_changed;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cur_storage = mmi_imgview_get_storage();
    
    mmi_fmgr_get_exist_storage_inline_list((S8)cur_storage,&total_num,&(drv_inline_list_p),&highlighted_idx);
    
    if (total_num > 1) 
        is_storage_path_changed = TRUE;
    else
        is_storage_path_changed = FALSE;
    
    if (is_next)
    {
        if (highlighted_idx < total_num - 1)
        {
            highlighted_idx++;
        }
        else
        {
            highlighted_idx= 0;
        }
    }
    else
    {
        if (highlighted_idx>= 1)
        {
            highlighted_idx--;
        }
        else
        {
            highlighted_idx= total_num-1;
        }
        
    }
    
#ifndef __CAMERA_FEATURE_HIDE_HINT__
    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_GLOBAL_STORAGE));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");
    
    mmi_camera_preview_set_hint(
        (PS8) str_buf,
        (PS8) (((U8**)drv_inline_list_p)[highlighted_idx]),
        HINT_POPUP_FADE_TIME);
#endif /* __CAMERA_FEATURE_HIDE_HINT__ */ 
    
    mmi_camera_preview_draw_osd();
    mmi_camera_blt();
    
    mmi_fmgr_get_drive_letter_by_inline_index(highlighted_idx,(S8*)&cur_storage);
    
    mmi_imgview_set_storage(cur_storage);
    
    /* storage changed */
    if (is_storage_path_changed)
    {
        if (mmi_camera_check_and_restore_valid_drv())
        {
            /* drv is valid, create directory */
            mmi_imgview_get_storage_file_path(g_camera_cntx.storage_filepath);
            create_result = mmi_imgview_create_file_dir(g_camera_cntx.storage_filepath);
            
            /* create directory failed */
            if (create_result == FS_WRITE_PROTECTION)
            {
                g_camera_cntx.last_error = CAMERA_ERR_WRITE_PROTECT;
                
                /* has error - restore to phone */
                mmi_imgview_set_storage((U16)MMI_PUBLIC_DRV);
            }
            else if (create_result == FS_DISK_FULL)
            {
                if (cur_storage == (U16) MMI_PUBLIC_DRV)
                {
                    g_camera_cntx.last_error = CAMERA_ERR_PHONE_DISK_FULL;
                }
                else
                {
                    /* storage is card */
                    g_camera_cntx.last_error = CAMERA_ERR_CARD_DISK_FULL;
                    
                    /* has error - restore to phone */
                    mmi_imgview_set_storage((U16)MMI_PUBLIC_DRV);
                }
            }
            else if (create_result == FS_ROOT_DIR_FULL)
            {
                if (cur_storage == (U16) MMI_PUBLIC_DRV)
                {
                    g_camera_cntx.last_error = CAMERA_ERR_ROOT_DIR_FULL;
                }
                else
                {
                    /* storage is card */
                    g_camera_cntx.last_error = CAMERA_ERR_ROOT_DIR_FULL;
                    
                    /* has error - restore to phone */
                    mmi_imgview_set_storage((U16)MMI_PUBLIC_DRV);
                }
            }
            mmi_camera_get_next_filename(g_camera_cntx.captured_filepath);
        }
        else
        {
            /* drv no valid, means card is plugged out (or phone FAT corrupted) */
            /* if storage before restoration is already in phone, means FAT is corrupted */
            if (cur_storage == (U16) MMI_PUBLIC_DRV)
            {
                g_camera_cntx.last_error = CAMERA_ERR_CORRUPT_FAT;
            }
            else
            {
                g_camera_cntx.last_error = MDI_RES_CAMERA_ERR_NO_DISK;
            }
        }
        
        /* check if preview success */
        if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
        {
            mmi_camera_display_error_popup();
        }
        
    }
    
}
#endif /* __CAMERA_FEATURE_STORAGE__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_draw_add_frame
* DESCRIPTION
*  exit preview state
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_ADD_FRAME__
static void mmi_camera_draw_add_frame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 image_idx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_camera_cntx.is_fullscreen) && ((g_camera_cntx.setting.add_frame != CAMERA_SETTING_ADD_FRAME_OFF) ||
        (g_camera_cntx.setting.add_frame_tileshot != CAMERA_SETTING_ADD_FRAME_OFF)))
    {
        gdi_layer_push_and_set_active(g_camera_cntx.add_frame_layer_handle);
        
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
        
        /**
        * due to performance issue, we not support fullscreen addframe on WQVGA lcm
        * we resize add frame layer to QVGA (320x240) 
        */
#if defined(__CAMERA_OSD_HORIZONTAL__)
        gdi_layer_resize(g_camera_cntx.preview_height,g_camera_cntx.preview_width);
#else
        gdi_layer_resize(g_camera_cntx.preview_width,g_camera_cntx.preview_height);
#endif
        
        /* if frame is set and preview size is LCD size, draw frame */
        if (g_camera_cntx.is_tileshot)
        {
            image_idx = (U16) (IMG_ID_CAMERA_TILE_ADD_FRAME_START + g_camera_cntx.setting.add_frame_tileshot);
        }
        else
        {
            image_idx = (U16) (IMG_ID_CAMERA_ADD_FRAME_START + g_camera_cntx.setting.add_frame);
        }
        
        gdi_image_draw_id(0, 0, (U16) (image_idx));
        
        gdi_layer_pop_and_restore_active();
    }
    
}
#endif /* __CAMERA_FEATURE_ADD_FRAME__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_change_frame_down
* DESCRIPTION
*  change add frame
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_ADD_FRAME__
static void mmi_camera_preview_change_frame_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 prev_add_frame;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
    if (g_camera_cntx.setting.cont_shot == CAMERA_SETTING_CONT_SHOT_BURST)
    {
        return;
    }
#endif
    if (g_camera_cntx.is_fullscreen)
    {
        if (g_camera_cntx.is_tileshot == TRUE)
        {
            prev_add_frame = g_camera_cntx.setting.add_frame_tileshot;
            
            if (g_camera_cntx.setting.add_frame_tileshot >= CAMERA_SETTING_ADD_FRAME_COUNT - 1)
            {
                g_camera_cntx.setting.add_frame_tileshot = 0;
            }
            else
            {
                g_camera_cntx.setting.add_frame_tileshot++;
            }
        }
        else
        {
            prev_add_frame = g_camera_cntx.setting.add_frame;
            
            if (g_camera_cntx.setting.add_frame >= CAMERA_SETTING_ADD_FRAME_COUNT - 1)
            {
                g_camera_cntx.setting.add_frame = 0;
            }
            else
            {
                g_camera_cntx.setting.add_frame++;
            }
        }
        
        mmi_camera_preview_stop();
        
        g_camera_cntx.capture_path = CAPTURE_FROM_LAYER;
        
#if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
        if (g_camera_cntx.setting.add_frame == 0 || prev_add_frame == 0)
        {
            if (g_camera_cntx.setting.add_frame == 0)
            {
                g_camera_cntx.is_single_osd_layer = FALSE;
            }
            else
            {
                g_camera_cntx.is_single_osd_layer = TRUE;
            }
            
            mmi_camera_free_osd_layer();
            mmi_camera_create_osd_layer();
            
#if defined(__CAMERA_OSD_HORIZONTAL__)
            /* update osd layers */
            g_camera_cntx.previous_osd_rotate = CAMERA_DISPLAY_ROTATE_RESET;
            mmi_camera_check_osd_orientation();
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
            
            /* update blt layers */
            mmi_camera_preview_set_blt_layer(TRUE);
        }
#endif /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 
        
        if (prev_add_frame == 0)
        {
            mmi_camera_create_add_frame_layer();
            mmi_camera_draw_add_frame();
        }
        else if (g_camera_cntx.setting.add_frame == 0)
            mmi_camera_free_add_frame_layer();
        else
            mmi_camera_draw_add_frame();
        
        gdi_layer_push_and_set_active(g_camera_cntx.preview_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
        
        mmi_camera_preview_draw_osd();
        
        mmi_camera_blt();
        
        mmi_camera_preview_start();
        
        if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
        {
            mmi_camera_display_error_popup();
        }
        
    }
}
#endif /* __CAMERA_FEATURE_ADD_FRAME__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_change_frame_up
* DESCRIPTION
*  change add frame
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_ADD_FRAME__
static void mmi_camera_preview_change_frame_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 prev_add_frame;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
    if (g_camera_cntx.setting.cont_shot == CAMERA_SETTING_CONT_SHOT_BURST)
    {
        return;
    }
#endif
    if (g_camera_cntx.is_fullscreen)
    {
        if (g_camera_cntx.is_tileshot == TRUE)
        {
            prev_add_frame = g_camera_cntx.setting.add_frame_tileshot;
            
            if (g_camera_cntx.setting.add_frame_tileshot == 0)
            {
                g_camera_cntx.setting.add_frame_tileshot = CAMERA_SETTING_ADD_FRAME_COUNT - 1;
            }
            else
            {
                g_camera_cntx.setting.add_frame_tileshot--;
            }
        }
        else
        {
            prev_add_frame = g_camera_cntx.setting.add_frame;
            
            if (g_camera_cntx.setting.add_frame == 0)
            {
                g_camera_cntx.setting.add_frame = CAMERA_SETTING_ADD_FRAME_COUNT - 1;
            }
            else
            {
                g_camera_cntx.setting.add_frame--;
            }
        }
        
        mmi_camera_preview_stop();
        
        g_camera_cntx.capture_path = CAPTURE_FROM_LAYER;
        
#if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
        if (g_camera_cntx.setting.add_frame == 0 || prev_add_frame == 0)
        {
            if (g_camera_cntx.setting.add_frame == 0)
            {
                g_camera_cntx.is_single_osd_layer = FALSE;
            }
            else
            {
                g_camera_cntx.is_single_osd_layer = TRUE;
            }
            
            mmi_camera_free_osd_layer();
            mmi_camera_create_osd_layer();
            
#if defined(__CAMERA_OSD_HORIZONTAL__)
            /* update osd layers */
            g_camera_cntx.previous_osd_rotate = CAMERA_DISPLAY_ROTATE_RESET;
            mmi_camera_check_osd_orientation();
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
            
            /* update blt layers */
            mmi_camera_preview_set_blt_layer(TRUE);
        }
#endif /* defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */ 
        
        if (prev_add_frame == 0)
        {
            mmi_camera_create_add_frame_layer();
            mmi_camera_draw_add_frame();
        }
        else if (g_camera_cntx.setting.add_frame == 0)
            mmi_camera_free_add_frame_layer();
        else
            mmi_camera_draw_add_frame();
        
        gdi_layer_push_and_set_active(g_camera_cntx.preview_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
        
        mmi_camera_preview_draw_osd();
        mmi_camera_blt();
        
        mmi_camera_preview_start();
        
        if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
        {
            mmi_camera_display_error_popup();
        }
    }
}
#endif /* __CAMERA_FEATURE_ADD_FRAME__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_lsk_press
* DESCRIPTION
*  previwe lsk pressed
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_preview_lsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.is_lsk_pressed = TRUE;
    
    mmi_camera_preview_draw_osd();
    mmi_camera_blt();
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_lsk_release
* DESCRIPTION
*  previwe lsk released
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_preview_lsk_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_camera_cntx.is_lsk_pressed == FALSE)
    {
        return;
    }
    g_camera_cntx.is_lsk_pressed = FALSE;
    
    mmi_camera_preview_draw_osd();
    mmi_camera_blt();
    
    mmi_camera_entry_option_menu_screen();
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_rsk_press
* DESCRIPTION
*  previwe rsk pressed
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_preview_rsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.is_rsk_pressed = TRUE;
    
    mmi_camera_preview_draw_osd();
    mmi_camera_blt();
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_preview_rsk_release
* DESCRIPTION
*  previwe rsk released
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_preview_rsk_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_camera_cntx.is_rsk_pressed == FALSE)
    {
        return;
    }
    g_camera_cntx.is_rsk_pressed = FALSE;
    
    mmi_camera_preview_draw_osd();
    
    /* for External Request */
    if (g_camera_cntx.external_request_mode != MMI_CAMERA_EXTERNAL_MODE_OFF)
    {
        if(g_camera_cntx.external_request_mode == MMI_CAMERA_EXTERNAL_MODE_LARGEST_RESOLUTION)
            g_camera_cntx.setting.image_size = g_camera_cntx.img_size_backup;
        
        g_camera_cntx.setting.cont_shot = g_camera_cntx.contshot_backup;
        g_camera_cntx.external_request_mode = MMI_CAMERA_EXTERNAL_MODE_OFF;
    }
    
    
    if ((g_camera_cntx.app_state == CAMERA_STATE_PREVIEW) &&
        (g_camera_cntx.is_tileshot) && (g_camera_cntx.tile_cur_num != 0))
    {
        MMI_ASSERT(0);
    }
    else
    {
        mmi_camera_blt();
    }
    
    /* camera with only 23key, will use RSK to capture */
#ifdef __MMI_CAMERA_23KEY__
    mmi_camera_capture_button_press();
#else 
    GoBackHistory();
#endif 
}

/*****************************************************************************
*
*  Main LCD Countdown State
*
*****************************************************************************/


/*****************************************************************************
* FUNCTION
*  mmi_camera_entry_countdown_state
* DESCRIPTION
*  entry count down state
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_entry_countdown_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* register soft keys */
    ClearInputEventHandler(MMI_DEVICE_KEY);
    
    SetKeyHandler(mmi_camera_preview_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_preview_lsk_release, KEY_LSK, KEY_EVENT_UP);
    
    SetKeyHandler(mmi_camera_preview_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_preview_rsk_release, KEY_RSK, KEY_EVENT_UP);
    
    /* clearn center key - since if not clear, this key will mappign to LSK */
    if (CAMERA_CAPTURE_KEY != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, CAMERA_CAPTURE_KEY, KEY_EVENT_DOWN);
    }
    
    if (CAMERA_CAPTURE_EXTRA_KEY1 != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY1, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY1, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY1, KEY_LONG_PRESS);
    }
    
    if (CAMERA_CAPTURE_EXTRA_KEY2 != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_LONG_PRESS);
    }
    
    
    /* init countdown para */
    switch (g_camera_cntx.setting.delay_timer)
    {
    case CAMERA_SETTING_DELAY_TIMER_1:
        {
            g_camera_cntx.capture_countdown = CAMERA_FEATURE_DELAY_TIMER_1_DURATION * 1000;
        }
        break;
        
    case CAMERA_SETTING_DELAY_TIMER_2:
        {
            g_camera_cntx.capture_countdown = CAMERA_FEATURE_DELAY_TIMER_2_DURATION * 1000;
        }
        break;
        
    case CAMERA_SETTING_DELAY_TIMER_3:
        {
            g_camera_cntx.capture_countdown = CAMERA_FEATURE_DELAY_TIMER_3_DURATION * 1000;
        }
        break;
        
    default:
        /* restore default value */
        mmi_camera_restore_setting();
        break;
    }
    
#ifdef __COUNTDOWN_USING_MMA__
    mmi_camera_init_countdown_mma();
#endif
    
    /* start count down */
    mmi_camera_countdown_cyclic();
    
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_exit_countdown_state
* DESCRIPTION
*  entry count down state
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_exit_countdown_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop countdown timer */
    gui_cancel_timer(mmi_camera_countdown_stop_LED);
    mmi_camera_countdown_stop_LED();
    gui_cancel_timer(mmi_camera_countdown_cyclic);
    
#ifdef __COUNTDOWN_USING_MMA__
    gui_cancel_timer(mmi_camera_capture);
    gui_cancel_timer(mmi_camera_deinit_countdown_mma);
#endif
    
    /* free preview resource */
    if (g_camera_cntx.app_next_state == CAMERA_STATE_EXIT)
    {
#ifdef __COUNTDOWN_USING_MMA__
        if (g_camera_cntx.multi_sound_countdown != 0 && g_camera_cntx.multi_sound_dummy_bg != 0)
        {
            mmi_camera_deinit_countdown_mma();
        }
#endif
        
        /* stop previewing */
        mmi_camera_preview_stop();
        
        /* turn off led highlight */
        mmi_camera_turn_off_led_highlight();
        
        /* flatten layer */
        mmi_camera_preview_flatten_layer(TRUE);
    }
    
}

#ifdef __COUNTDOWN_USING_MMA__
static void mmi_camera_init_countdown_mma(void)
{
    /* set flag */
    
    /* open and play a dummy midi at backgroup - this is a must do to play multi-channel sound */
    g_camera_cntx.multi_sound_dummy_bg = mdi_audio_mma_open_midi((void*)camera_sound_dummy_bg, CAMERA_SOUND_DUMMY_BG_LEN, 0, NULL);
    mdi_audio_mma_play_midi(g_camera_cntx.multi_sound_dummy_bg);
    
    g_camera_cntx.multi_sound_countdown = mdi_audio_mma_open_wav(
        (void*)camera_sound_countdown,
        (U32) CAMREA_SOUND_COUNTDOWN_LEN,
        1,
        NULL);
}


static void mmi_camera_deinit_countdown_mma(void)
{
    mdi_audio_mma_stop_midi(g_camera_cntx.multi_sound_dummy_bg);
    mdi_audio_mma_close_midi(g_camera_cntx.multi_sound_dummy_bg);
    
    mdi_audio_mma_stop_wav(g_camera_cntx.multi_sound_countdown);
    mdi_audio_mma_close_wav(g_camera_cntx.multi_sound_countdown);
    
    g_camera_cntx.multi_sound_countdown = 0;
    g_camera_cntx.multi_sound_dummy_bg = 0;
}
#endif
/*****************************************************************************
* FUNCTION
*  mmi_camera_countdown_cyclic
* DESCRIPTION
*  count down delay timer cyclic loop
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_countdown_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* countdonw duration and freq */
    if (g_camera_cntx.capture_countdown > 6000)
    {
        if (g_camera_cntx.setting.led_highlight == CAMERA_SETTING_LED_HIGHLIGHT_OFF)
        {
            SetGPIOLevelReq(GPIO_DEV_LED_STATUS_1, LED_LIGHT_LEVEL5);
        }
        
        gui_start_timer(100, mmi_camera_countdown_stop_LED);
        gui_start_timer(1000, mmi_camera_countdown_cyclic);
        g_camera_cntx.capture_countdown -= 1000;
        
        if (!MMI_CAMERA_IS_SILENT_MODE())
        {
#ifdef __COUNTDOWN_USING_MMA__
            mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER_BOTH);
            mdi_audio_set_volume(VOL_TYPE_MEDIA,CAMERA_SHUTTER_SOUND_VOLUMN);
            mdi_audio_mma_stop_wav(g_camera_cntx.multi_sound_countdown);
            mdi_audio_mma_play_wav(g_camera_cntx.multi_sound_countdown);
#else
            mdi_audio_play_string_with_vol_path((void*)camera_sound_countdown, (U32) CAMREA_SOUND_COUNTDOWN_LEN,
                MDI_FORMAT_DVI_ADPCM,
                DEVICE_AUDIO_PLAY_ONCE,
                NULL, NULL, CAMERA_SHUTTER_SOUND_VOLUMN, MDI_DEVICE_SPEAKER_BOTH);
#endif
        }
    }
    else if (g_camera_cntx.capture_countdown > 2000)
    {
        if (g_camera_cntx.setting.led_highlight == CAMERA_SETTING_LED_HIGHLIGHT_OFF)
        {
            SetGPIOLevelReq(GPIO_DEV_LED_STATUS_1, LED_LIGHT_LEVEL5);
        }
        
        gui_start_timer(100, mmi_camera_countdown_stop_LED);
        gui_start_timer(500, mmi_camera_countdown_cyclic);
        g_camera_cntx.capture_countdown -= 500;
        
        if (!MMI_CAMERA_IS_SILENT_MODE())
        {
#ifdef __COUNTDOWN_USING_MMA__
            mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER_BOTH);
            mdi_audio_set_volume(VOL_TYPE_MEDIA,CAMERA_SHUTTER_SOUND_VOLUMN);
            mdi_audio_mma_stop_wav(g_camera_cntx.multi_sound_countdown);
            mdi_audio_mma_play_wav(g_camera_cntx.multi_sound_countdown);
#else
            mdi_audio_play_string_with_vol_path((void*)camera_sound_countdown, (U32) CAMREA_SOUND_COUNTDOWN_LEN,
                MDI_FORMAT_DVI_ADPCM,
                DEVICE_AUDIO_PLAY_ONCE,
                NULL, NULL, CAMERA_SHUTTER_SOUND_VOLUMN, MDI_DEVICE_SPEAKER_BOTH);
#endif
            
        }
    }
    else if (g_camera_cntx.capture_countdown >= 0)
    {
        if (g_camera_cntx.setting.led_highlight == CAMERA_SETTING_LED_HIGHLIGHT_OFF)
        {
            SetGPIOLevelReq(GPIO_DEV_LED_STATUS_1, LED_LIGHT_LEVEL5);
        }
        
        gui_start_timer(100, mmi_camera_countdown_stop_LED);
        gui_start_timer(200, mmi_camera_countdown_cyclic);
        g_camera_cntx.capture_countdown -= 200;
        
        if (!MMI_CAMERA_IS_SILENT_MODE())
        {
#ifdef __COUNTDOWN_USING_MMA__
            mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER_BOTH);
            mdi_audio_set_volume(VOL_TYPE_MEDIA,CAMERA_SHUTTER_SOUND_VOLUMN);
            mdi_audio_mma_stop_wav(g_camera_cntx.multi_sound_countdown);
            mdi_audio_mma_play_wav(g_camera_cntx.multi_sound_countdown);
#else
            mdi_audio_play_string_with_vol_path((void*)camera_sound_countdown, (U32) CAMREA_SOUND_COUNTDOWN_LEN,
                MDI_FORMAT_DVI_ADPCM,
                DEVICE_AUDIO_PLAY_ONCE,
                NULL, NULL, CAMERA_SHUTTER_SOUND_VOLUMN, MDI_DEVICE_SPEAKER_BOTH);
#endif
            
        }
    }
    else
    {
#ifdef __COUNTDOWN_USING_MMA__
        gui_start_timer(200, mmi_camera_deinit_countdown_mma);
        gui_start_timer(300, mmi_camera_capture);
#else
        mmi_camera_capture();
#endif
        return;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_countdown_stop_LED
* DESCRIPTION
*  stop count down LED
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_countdown_stop_LED(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_camera_cntx.setting.led_highlight == CAMERA_SETTING_LED_HIGHLIGHT_OFF)
    {
        SetGPIOLevelReq(GPIO_DEV_LED_STATUS_1, LED_LIGHT_LEVEL0);
    }
}

/*****************************************************************************
*
*  Main LCD Cont Shot State
*
*****************************************************************************/


/*****************************************************************************
* FUNCTION
*  mmi_camera_entry_contshot_state
* DESCRIPTION
*  entry contshot state
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_entry_contshot_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* register soft keys */
    ClearInputEventHandler(MMI_DEVICE_KEY);
    
    SetKeyHandler(mmi_camera_preview_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_preview_lsk_release, KEY_LSK, KEY_EVENT_UP);
    
    SetKeyHandler(mmi_camera_preview_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_preview_rsk_release, KEY_RSK, KEY_EVENT_UP);
    
    /* clearn center key - since if not clear, this key will mappign to LSK */
    if (CAMERA_CAPTURE_KEY != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, CAMERA_CAPTURE_KEY, KEY_EVENT_DOWN);
    }
    
    if (CAMERA_CAPTURE_EXTRA_KEY1 != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY1, KEY_EVENT_DOWN);
    }
    
    if (CAMERA_CAPTURE_EXTRA_KEY2 != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_LONG_PRESS);
    }
    
    
#ifdef __MMI_CAMERA_AF_TEST__
    if (g_camera_cntx.is_af_test == FALSE)
    {
#endif /* __MMI_CAMERA_AF_TEST__ */ 
        /* init count down para */
        switch (g_camera_cntx.setting.cont_shot)
        {
        case CAMERA_SETTING_CONT_SHOT_1:
            {
                g_camera_cntx.cont_shot_total_count = CAMERA_FEATURE_CONT_SHOT_1_COUNT;
                g_camera_cntx.cont_shot_count = 0;
            }
            break;
            
#ifdef __CAMERA_FEATURE_CONT_SHOT_2__
        case CAMERA_SETTING_CONT_SHOT_2:
            {
                g_camera_cntx.cont_shot_total_count = CAMERA_FEATURE_CONT_SHOT_2_COUNT;
                g_camera_cntx.cont_shot_count = 0;
            }
            break;
#endif /* __CAMERA_FEATURE_CONT_SHOT_2__ */ 
#ifdef __CAMERA_FEATURE_CONT_SHOT_3__
        case CAMERA_SETTING_CONT_SHOT_3:
            {
                g_camera_cntx.cont_shot_total_count = CAMERA_FEATURE_CONT_SHOT_3_COUNT;
                g_camera_cntx.cont_shot_count = 0;
            }
            break;
#endif /* __CAMERA_FEATURE_CONT_SHOT_3__ */ 
        }
#ifdef __MMI_CAMERA_AF_TEST__
    }
#endif 
    mmi_camera_contshot_cyclic();
    
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_exit_contshot_state
* DESCRIPTION
*  entry contshot state
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_exit_contshot_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* cancel countdown timer */
    gui_cancel_timer(mmi_camera_contshot_cyclic);
    
    /* free preview resource */
    if (g_camera_cntx.app_next_state == CAMERA_STATE_EXIT)
    {
        /* stop previewing */
        mmi_camera_preview_stop();
        
        /* turn off led highlight */
        mmi_camera_turn_off_led_highlight();
        
        /* flatten layer */
        mmi_camera_preview_flatten_layer(TRUE);
    }
    
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_contshot_cyclic
* DESCRIPTION
*  cont shot cyclic loop
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_contshot_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
#ifndef __CAMERA_FEATURE_CONT_SHOT_DRAW_COUNTBAR__
    S8 buffer[100];
    S8 UCS2_buffer[100];
#endif /* __CAMERA_FEATURE_CONT_SHOT_DRAW_COUNTBAR__ */ 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_camera_cntx.cont_shot_count + 1 == g_camera_cntx.cont_shot_total_count)
    {
        g_camera_cntx.is_continue_capture = FALSE;
    }
    else
    {
        g_camera_cntx.is_continue_capture = TRUE;
    }
    
    /* set capturing flag */
    g_camera_cntx.is_capturing = TRUE;
    
    MMI_CAMERA_START_MEASURE("OSD");
    
    if (g_camera_cntx.cont_shot_total_count != 1)
    {
#ifndef __CAMERA_FEATURE_CONT_SHOT_DRAW_COUNTBAR__
        sprintf(buffer, "%d / %d", g_camera_cntx.cont_shot_count + 1, g_camera_cntx.cont_shot_total_count);
        mmi_asc_to_ucs2((PS8) UCS2_buffer, (PS8) buffer);
        mmi_ucs2cpy((PS8) buffer, (PS8) GetString(STR_ID_CAMERA_NOFIFY_CAPTURING));
        mmi_camera_preview_set_hint((PS8) buffer, UCS2_buffer, 0);
#else /* __CAMERA_FEATURE_CONT_SHOT_DRAW_COUNTBAR__ */ 
        mmi_camera_preview_set_hint(NULL, NULL, 0);
#endif /* __CAMERA_FEATURE_CONT_SHOT_DRAW_COUNTBAR__ */ 
        
        mmi_camera_preview_draw_osd();
        mmi_camera_blt();
    }
    else
    {
        /* if only 1 image, draw "Capture.." string */
        mmi_camera_preview_set_hint((PS8) GetString(STR_ID_CAMERA_NOFIFY_CAPTURING), NULL, 0);
        mmi_camera_preview_draw_osd();
        mmi_camera_blt();
    }
    
    
    MMI_CAMERA_STOP_MEASURE("OSD");
    
    
    /* will capture then save to file */
    mmi_camera_commit_filename_seq_no();
    
    /* start timer for next shot */
#ifdef __MMI_CAMERA_AF_TEST__
    if (g_camera_cntx.is_af_test == FALSE)
    {
        gui_start_timer(100, mmi_camera_contshot_cyclic);
    }
#else /* __MMI_CAMERA_AF_TEST__ */ 
    gui_start_timer(100, mmi_camera_contshot_cyclic);
#endif /* __MMI_CAMERA_AF_TEST__ */ 
    
    mmi_camera_turn_on_capture_led_highlight();
    
    MMI_CAMERA_START_MEASURE("SND");
    
    /* play capture sound after capture */
    mmi_camera_capture_play_sound();
    
    MMI_CAMERA_STOP_MEASURE("SND");
    
    MMI_CAMERA_START_MEASURE("ACJ");
    if (g_camera_cntx.setting.add_frame == CAMERA_SETTING_ADD_FRAME_OFF)
    {
        switch (g_camera_cntx.capture_path)
        {
        case CAPTURE_FROM_MEMORY:
            g_camera_cntx.last_error = mdi_camera_capture_to_file(g_camera_cntx.captured_filepath, g_camera_cntx.is_continue_capture);
            break;
        case CAPTURE_FROM_LAYER:
            g_camera_cntx.last_error = mdi_camera_capture_layer_to_file(
#if defined(__MMI_CAMERA_BASELAYER_SET_COLOR_SUPPORT__)
                GDI_LAYER_ENABLE_LAYER_0,
#else 
                GDI_LAYER_ENABLE_LAYER_1,
#endif 
                g_camera_cntx.captured_filepath,
                0,
                0,
                g_camera_cntx.image_width,
                g_camera_cntx.image_height,
                g_camera_cntx.is_continue_capture);
            
            break;
            
        default:
            g_camera_cntx.last_error = mdi_camera_capture_to_file(g_camera_cntx.captured_filepath, g_camera_cntx.is_continue_capture);
            break;
        }
    }
    else
    {
        switch (g_camera_cntx.capture_path)
        {
        case CAPTURE_FROM_MEMORY:
            g_camera_cntx.last_error = mdi_camera_capture_to_file(g_camera_cntx.captured_filepath, g_camera_cntx.is_continue_capture);
            break;
        case CAPTURE_FROM_LAYER:
#if defined(__MMI_CAMERA_BASELAYER_SET_COLOR_SUPPORT__)
            /* (0) Base-as preview buffer, (2) Add frame layer */
#if defined(__MMI_CAMERA_5_OSD_LAYER__)
            gdi_layer_set_blt_layer(
                g_camera_cntx.preview_layer_handle,
                g_camera_cntx.osd_layer_handle0,
                g_camera_cntx.add_frame_layer_handle,
                0);
#elif defined(__MMI_CAMERA_3_OSD_LAYER__)
            gdi_layer_set_blt_layer(
                g_camera_cntx.preview_layer_handle,
                g_camera_cntx.osd_layer_handle0,
                g_camera_cntx.add_frame_layer_handle,
                0);       
#else /* defined(__MMI_CAMERA_5_OSD_LAYER__) */ 
            gdi_layer_set_blt_layer(
                g_camera_cntx.preview_layer_handle,
                g_camera_cntx.osd_layer_handle0,
                g_camera_cntx.add_frame_layer_handle,
                0);
#endif /* defined(__MMI_CAMERA_5_OSD_LAYER__) */ 
            
            g_camera_cntx.last_error
                = mdi_camera_capture_layer_to_file(
                GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_2,
                g_camera_cntx.captured_filepath,
                0,
                0,
                g_camera_cntx.image_width,
                g_camera_cntx.image_height,
                g_camera_cntx.is_continue_capture);
            
#else /* defined(__MMI_CAMERA_BASELAYER_SET_COLOR_SUPPORT__) */
#if defined(__MMI_CAMERA_5_OSD_LAYER__)
            gdi_layer_set_blt_layer(
                g_camera_cntx.base_layer_handle,
                g_camera_cntx.preview_layer_handle,
                g_camera_cntx.osd_layer_handle0,
                g_camera_cntx.add_frame_layer_handle);
#elif defined(__MMI_CAMERA_3_OSD_LAYER__)
            gdi_layer_set_blt_layer(
                g_camera_cntx.base_layer_handle,
                g_camera_cntx.preview_layer_handle,
                g_camera_cntx.osd_layer_handle0,
                g_camera_cntx.add_frame_layer_handle);
#else /* defined(__MMI_CAMERA_5_OSD_LAYER__) */ 
            gdi_layer_set_blt_layer(
                g_camera_cntx.base_layer_handle,
                g_camera_cntx.preview_layer_handle,
                g_camera_cntx.osd_layer_handle0,
                g_camera_cntx.add_frame_layer_handle);
#endif /* defined(__MMI_CAMERA_5_OSD_LAYER__) */ 
            g_camera_cntx.last_error
                = mdi_camera_capture_layer_to_file(
                GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_3,
                g_camera_cntx.captured_filepath,
                0,
                0,
                g_camera_cntx.osd_UI_device_width,
                g_camera_cntx.osd_UI_device_height,
                g_camera_cntx.is_continue_capture);
            
#endif /* defined(__MMI_CAMERA_BASELAYER_SET_COLOR_SUPPORT__) */
            
            break;
        default:
            g_camera_cntx.last_error = mdi_camera_capture_to_file(g_camera_cntx.captured_filepath, g_camera_cntx.is_continue_capture);
            break;
        }
    }
    
    MMI_CAMERA_STOP_MEASURE("ACJ");
    
    MMI_CAMERA_START_MEASURE("ASV");
    if (g_camera_cntx.last_error == MDI_RES_CAMERA_SUCCEED)
    {
        g_camera_cntx.last_error = mdi_camera_save_captured_image();
    }
    MMI_CAMERA_STOP_MEASURE("ASV");    
    /* after captured restore black background */
#ifdef CAMERA_MODULE_WITH_LCD
    if (!g_camera_cntx.is_fullscreen)
    {
        mmi_camera_preview_clear_background();
    }
#endif /* CAMERA_MODULE_WITH_LCD */ 
    
    mmi_camera_turn_off_led_highlight();
    
    /* captured, previwing is stopped, change blt layer */
    mmi_camera_preview_set_blt_layer(FALSE);
    
    
    if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
    {
#ifdef __CAMERA_AUTOFOCUS__
        mdi_camera_stop_autofocus_process();
        g_camera_cntx.af_state = AF_CANCEL;
#endif /* __CAMERA_AUTOFOCUS__ */ 
        
        g_camera_cntx.is_continue_capture = FALSE;
        
        mmi_camera_restore_filename_seq_no();
        
        gui_cancel_timer(mmi_camera_contshot_cyclic);
        FS_Delete((U16*) g_camera_cntx.captured_filepath);
        mmi_camera_display_error_popup();
        return;
    }
    
    g_camera_cntx.cont_shot_count++;
    
    /* terminate condition */
    if (g_camera_cntx.cont_shot_count >= g_camera_cntx.cont_shot_total_count)
    {
#ifdef __MMI_CAMERA_AF_TEST__
        if (g_camera_cntx.is_af_test == TRUE)
        {
            g_camera_cntx.is_af_test = FALSE;
        }
#endif /* __MMI_CAMERA_AF_TEST__ */ 
        
#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) */

        /* stop timer */
        gui_cancel_timer(mmi_camera_contshot_cyclic);
        
        MMI_CAMERA_START_MEASURE("RSP");
        CAMERA_ENTER_STATE(CAMERA_STATE_PREVIEW);
        MMI_CAMERA_STOP_MEASURE("RSP");
        
        return;
    }
    else
    {
        /* change blt layer for previwing */
        mmi_camera_preview_set_blt_layer(TRUE);
        
        MMI_CAMERA_START_MEASURE("RSP");
        mmi_camera_preview_start();
        MMI_CAMERA_STOP_MEASURE("RSP");
        
        if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
        {
            g_camera_cntx.is_continue_capture = FALSE;
            /* stop timer */
            gui_cancel_timer(mmi_camera_contshot_cyclic);
            mmi_camera_display_error_popup();
            return;
        }
#ifdef __MMI_CAMERA_AF_TEST__
        if (g_camera_cntx.is_af_test == TRUE)
        {
            mmi_camera_af_test_start();
        }
#endif /* __MMI_CAMERA_AF_TEST__ */ 
    }
}

/*****************************************************************************
*
*  Burstshot State
*
*****************************************************************************/


/*****************************************************************************
* FUNCTION
*  mmi_camera_entry_burstshot_capture_state
* DESCRIPTION
*  entry burstshot state
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
static void mmi_camera_entry_burstshot_capture_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* register softkeys */
    ClearInputEventHandler(MMI_DEVICE_KEY);
    
    /* clearn center key - since if not clear, this key will mapping to LSK */
    if (CAMERA_CAPTURE_KEY != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, CAMERA_CAPTURE_KEY, KEY_EVENT_DOWN);
    }
    
    if (CAMERA_CAPTURE_EXTRA_KEY1 != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY1, KEY_EVENT_DOWN);
    }
    
    if (CAMERA_CAPTURE_EXTRA_KEY2 != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_LONG_PRESS);
    }
    
    mmi_camera_turn_on_capture_led_highlight();
    
    /* set capturing flag */
    g_camera_cntx.is_capturing = TRUE;
    
    mmi_camera_preview_set_hint((PS8) GetString(STR_ID_CAMERA_NOFIFY_BURST_CAPTURING), NULL, 0);
    
#ifdef __CAMERA_AUTOFOCUS__
    g_camera_cntx.is_autofocus_pressed = FALSE;
#endif 
    
    mmi_camera_preview_draw_osd();
    mmi_camera_blt();
    
#if defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__)
    
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_dummy_func, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_dummy_func, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_dummy_func, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_dummy_func, KEY_LSK, KEY_EVENT_UP);
    
    SetKeyHandler(mmi_camera_dummy_func, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_dummy_func, KEY_RSK, KEY_EVENT_UP);
    
    if (g_camera_cntx.setting.shutter_sound != CAMERA_SETTING_SHUTTER_SOUND_OFF && !MMI_CAMERA_IS_SILENT_MODE())
    {
        /* start multi_channel sound, for capture sound effect */
        
        if (g_camera_cntx.is_multi_sound_open == FALSE)
        {
            /* multi_sound still not opened, open them */
            
            /* set flag */
            g_camera_cntx.is_multi_sound_open = TRUE;
            
            /* open and play a dummy midi at backgroup - this is a must do to play multi-channel sound */
            g_camera_cntx.multi_sound_dummy_bg = mdi_audio_mma_open_midi((void*)camera_sound_dummy_bg, CAMERA_SOUND_DUMMY_BG_LEN, 0, NULL);
            
            mdi_audio_mma_play_midi(g_camera_cntx.multi_sound_dummy_bg);
            
            g_camera_cntx.multi_sound_cap_idx = 0;
            
            switch (g_camera_cntx.setting.shutter_sound)
            {
            case CAMERA_SETTING_SHUTTER_SOUND_1:
                {
                    g_camera_cntx.multi_sound_capture0 = mdi_audio_mma_open_wav(
                        (void*)camera_sound_shutter_1,
                        (U32) CAMERA_SOUND_SHUTTER_1_LEN,
                        1,
                        NULL);
                    
                    g_camera_cntx.multi_sound_capture1 = mdi_audio_mma_open_wav(
                        (void*)camera_sound_shutter_1,
                        (U32) CAMERA_SOUND_SHUTTER_1_LEN,
                        1,
                        NULL);
                    
                    g_camera_cntx.multi_sound_capture2 = mdi_audio_mma_open_wav(
                        (void*)camera_sound_shutter_1,
                        (U32) CAMERA_SOUND_SHUTTER_1_LEN,
                        1,
                        NULL);
                }
                break;
                
            case CAMERA_SETTING_SHUTTER_SOUND_2:
                {
                    g_camera_cntx.multi_sound_capture0 = mdi_audio_mma_open_wav(
                        (void*)camera_sound_shutter_2,
                        (U32) CAMERA_SOUND_SHUTTER_2_LEN,
                        1,
                        NULL);
                    
                    g_camera_cntx.multi_sound_capture1 = mdi_audio_mma_open_wav(
                        (void*)camera_sound_shutter_2,
                        (U32) CAMERA_SOUND_SHUTTER_2_LEN,
                        1,
                        NULL);
                    
                    g_camera_cntx.multi_sound_capture2 = mdi_audio_mma_open_wav(
                        (void*)camera_sound_shutter_2,
                        (U32) CAMERA_SOUND_SHUTTER_2_LEN,
                        1,
                        NULL);
                }
                break;
                
            case CAMERA_SETTING_SHUTTER_SOUND_3:
                {
                    g_camera_cntx.multi_sound_capture0 = mdi_audio_mma_open_wav(
                        (void*)camera_sound_shutter_3,
                        (U32) CAMERA_SOUND_SHUTTER_3_LEN,
                        1,
                        NULL);
                    
                    g_camera_cntx.multi_sound_capture1 = mdi_audio_mma_open_wav(
                        (void*)camera_sound_shutter_3,
                        (U32) CAMERA_SOUND_SHUTTER_3_LEN,
                        1,
                        NULL);
                    
                    g_camera_cntx.multi_sound_capture2 = mdi_audio_mma_open_wav(
                        (void*)camera_sound_shutter_3,
                        (U32) CAMERA_SOUND_SHUTTER_3_LEN,
                        1,
                        NULL);
                }
                break;
            }
        }
        else
        {
            /* multi_sound is alrady opened, stop the timer that will close it */
            gui_cancel_timer(mmi_camera_burstshot_close_multi_sound);
        }
        
    }
    
#ifdef __MMI_BIP_SUPPORT__
    if (mmi_bt_bip_server_is_working())
        mmi_bt_bip_server_pause_fs_operation();
#endif
    
#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) */
    
    /* MT6228 support non-blocking burst shot */
    /* call mdi to capture and save */
    g_camera_cntx.last_error
        = mdi_camera_non_block_burst_capture_to_memory(
        CAMERA_FEATURE_CONT_SHOT_BURST_COUNT,
        &g_camera_cntx.burst_jpg_data,
        mmi_camera_burstshot_capture_result_hdlr);
    
    if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
    {
        mmi_camera_display_error_popup();
        return;
    }
    
#else /* defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__) */ 
    
    SetKeyHandler(mmi_camera_preview_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_preview_lsk_release, KEY_LSK, KEY_EVENT_UP);
    
    SetKeyHandler(mmi_camera_preview_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_preview_rsk_release, KEY_RSK, KEY_EVENT_UP);
    
    /* burst shot shall play before capture */
    mmi_camera_capture_play_sound();
    
#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) */

    /* call mdi to capture and save */
    g_camera_cntx.last_error
        = mdi_camera_burst_capture_to_memory(CAMERA_FEATURE_CONT_SHOT_BURST_COUNT, &g_camera_cntx.burst_jpg_data);
    
#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) */

    /* clear capturing flag */
    g_camera_cntx.is_capturing = FALSE;
    
    /* restore black background */
#ifdef CAMERA_MODULE_WITH_LCD
    mmi_camera_preview_clear_background();
#endif 
    
    /* will enter save confirm, close led highlight */
    mmi_camera_turn_off_led_highlight();
    
    /* captured, previewing is stopped, change blt layer */
    mmi_camera_preview_set_blt_layer(FALSE);
    
    if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
    {
        mmi_camera_display_error_popup();
        return;
    }
    else
    {
        CAMERA_ENTER_STATE(CAMERA_STATE_BURSTSHOT_SAVE_CONFIRM);
    }
    
#endif /* defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__) */ 
    
}
#endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_burstshot_capture_result_hdlr
* DESCRIPTION
*  no block burst shot capture result handler
* PARAMETERS
*  ret                 [IN]        Burst shot result
*  captured_count      [IN]        
*  count(?)            [IN]        How many image is captured, count start from 1
* RETURNS
*  void
*****************************************************************************/
#if defined(__CAMERA_FEATURE_CONT_SHOT_BURST__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__)
static void mmi_camera_burstshot_capture_result_hdlr(MDI_RESULT ret, U16 captured_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if camera is in EXIT state by interrup, just do nothing */
    if (g_camera_cntx.app_state == CAMERA_STATE_EXIT)
    {
        return;
    }
    
    /* capture count start from 1 */
    mmi_camera_capture_play_multi_channel_sound();
    
    if (ret >= 0)
    {
        /* no error happened */
        if (captured_count == CAMERA_FEATURE_CONT_SHOT_BURST_COUNT)
        {
#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) */

            g_camera_cntx.is_capturing = FALSE;
#ifdef __CAMERA_AUTOFOCUS__
            mdi_camera_stop_autofocus_process();
#endif /* __CAMERA_AUTOFOCUS__ */ 
            PowerAndEndKeyHandler();
            
            /* will enter save confirm, close led highlight */
            mmi_camera_turn_off_led_highlight();
#ifdef __MMI_BIP_SUPPORT__
            if (mmi_bt_bip_server_is_working())
                mmi_bt_bip_server_continue_fs_operation();
#endif
            CAMERA_ENTER_STATE(CAMERA_STATE_BURSTSHOT_SAVE_CONFIRM);
            return;
        }
    }
    else
    {
        g_camera_cntx.is_capturing = FALSE;
        g_camera_cntx.last_error = ret;
        mmi_camera_display_error_popup();
    }
}
#endif /* defined(__CAMERA_FEATURE_CONT_SHOT_BURST__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__) */ /* __CAMERA_FEATURE_CONT_SHOT_BURST__ & __CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__ */


/*****************************************************************************
* FUNCTION
*  mmi_camera_burstshot_close_multi_sound
* DESCRIPTION
*  no block burst shot capture result handler
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#if defined(__CAMERA_FEATURE_CONT_SHOT_BURST__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__)
static void mmi_camera_burstshot_close_multi_sound(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* capture count start from 1 */
    if (g_camera_cntx.is_multi_sound_open)
    {
        mdi_audio_mma_stop_midi(g_camera_cntx.multi_sound_dummy_bg);
        mdi_audio_mma_close_midi(g_camera_cntx.multi_sound_dummy_bg);
        
        mdi_audio_mma_stop_wav(g_camera_cntx.multi_sound_capture0);
        mdi_audio_mma_close_wav(g_camera_cntx.multi_sound_capture0);
        
        mdi_audio_mma_stop_wav(g_camera_cntx.multi_sound_capture1);
        mdi_audio_mma_close_wav(g_camera_cntx.multi_sound_capture1);
        
        mdi_audio_mma_stop_wav(g_camera_cntx.multi_sound_capture2);
        mdi_audio_mma_close_wav(g_camera_cntx.multi_sound_capture2);
        
        g_camera_cntx.multi_sound_capture0 = 0;
        g_camera_cntx.multi_sound_capture1 = 0;
        g_camera_cntx.multi_sound_capture2 = 0;
        g_camera_cntx.multi_sound_dummy_bg = 0;
        
        g_camera_cntx.is_multi_sound_open = FALSE;
    }
    
}
#endif /* defined(__CAMERA_FEATURE_CONT_SHOT_BURST__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__) */ /* __CAMERA_FEATURE_CONT_SHOT_BURST__ & __CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__ */


/*****************************************************************************
* FUNCTION
*  mmi_camera_exit_burstshot_capture_state
* DESCRIPTION
*  entry burstshot state
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
static void mmi_camera_exit_burstshot_capture_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop capture and stop dummy bg midi for multi-channel sound */
#if defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__)
    
    if (g_camera_cntx.is_capturing)
    {
        mdi_camera_stop_non_block_burst_capture();
#ifdef __MMI_BIP_SUPPORT__
        if (mmi_bt_bip_server_is_working())
            mmi_bt_bip_server_continue_fs_operation();
#endif
    }
    
    /*
    * close multi-channel sound after 500 ms, this is used to 
    * avoid last sound be terminate when play to half 
    */
    gui_start_timer(500, mmi_camera_burstshot_close_multi_sound);
    
#endif /* defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__) */ 
    
    /* hide hint on panel if it is not fade out */
    mmi_camera_preview_hide_hint();
    
    /* free preview resource */
    if (g_camera_cntx.app_next_state == CAMERA_STATE_EXIT)
    {
        /* turn off led highlight */
        mmi_camera_turn_off_led_highlight();
        
        /* mdi_camera_burst_shot_stop */
        /* need this function if burstshot is non-blocking */
        
        /* flatten layer */
        mmi_camera_preview_flatten_layer(TRUE);
    }
    
}
#endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 

/*****************************************************************************
*
*  BurstShot Save Confirm State
*
*****************************************************************************/


/*****************************************************************************
* FUNCTION
*  mmi_camera_entry_burstshot_save_confirm_state
* DESCRIPTION
*  enter save confirm state
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
static void mmi_camera_entry_burstshot_save_confirm_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;
    S32 resized_offset_x;
    S32 resized_offset_y;
    S32 resized_width;
    S32 resized_height;
    S32 image_region_width;
    S32 image_region_height;
    S32 image_region_offset_x;
    S32 image_region_offset_y;
    S32 i, j;
    S32 image_box_width;
    S32 image_box_height;
    S32 image_box_offset_x;
    S32 image_box_offset_y;
    S32 spacing;
    S32 index;
    PU8 image_buf_ptr;
    U32 image_buf_size;
    S32 image_width = 0;
    S32 image_height = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* init var */
    g_camera_cntx.is_lsk_pressed = FALSE;
    g_camera_cntx.is_rsk_pressed = FALSE;
    
    spacing = 2;
    
    /* register soft keys */
    ClearInputEventHandler(MMI_DEVICE_KEY);
    
    SetKeyHandler(mmi_camera_burstshot_save_confirm_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_burstshot_save_confirm_lsk_release, KEY_LSK, KEY_EVENT_UP);
    
    SetKeyHandler(mmi_camera_burstshot_save_confirm_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_burstshot_save_confirm_rsk_release, KEY_RSK, KEY_EVENT_UP);
    
    /* clearn center key - since if not clear, this key will mappign to LSK */
    if (CAMERA_CAPTURE_KEY != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, CAMERA_CAPTURE_KEY, KEY_EVENT_DOWN);
    }
    
    if (CAMERA_CAPTURE_EXTRA_KEY1 != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY1, KEY_EVENT_DOWN);
    }
    
    if (CAMERA_CAPTURE_EXTRA_KEY2 != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_LONG_PRESS);
    }
    
    /* clear base layer background */
    mmi_camera_preview_clear_background();
    
#if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
    g_camera_cntx.is_single_osd_layer = TRUE;
    g_camera_cntx.previous_osd_rotate = CAMERA_DISPLAY_ROTATE_RESET;
    mmi_camera_free_osd_layer();
    mmi_camera_create_osd_layer();
#if defined(__CAMERA_OSD_HORIZONTAL__)
    mmi_camera_check_osd_orientation();
#endif
#endif /* #if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */
#if defined(__CAMERA_OSD_HORIZONTAL__)
    if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270)
    {
        gdi_layer_resize(LCD_HEIGHT,LCD_WIDTH);
        gdi_layer_set_rotate(GDI_LAYER_ROTATE_90);
    }
#endif
    gdi_layer_set_blt_layer(g_camera_cntx.base_layer_handle, g_camera_cntx.osd_layer_handle0, 0, 0);
    
    /* hide icons  */
    mmi_camera_preview_set_hint(NULL, NULL, 0);
    mmi_camera_preview_draw_osd();
    
    gdi_image_jpeg_get_dimension(
        (PU8) g_camera_cntx.burst_jpg_data.file_address[0],
        g_camera_cntx.burst_jpg_data.file_size[0],
        &image_width,
        &image_height);
    
    /* set clip region as content region */
    gdi_layer_reset_clip();
    
    /* calc image region */
    image_region_width = g_camera_cntx.osd_UI_device_width;
    image_region_height = g_camera_cntx.osd_UI_device_height;
    image_region_offset_x = 0;
    image_region_offset_y = 0;
    
    if (g_camera_cntx.active_camera_osd_ptr->title.is_draw_mmi_title_bar)
    {
        image_region_height -= (MMI_title_height + MMI_title_y);
        image_region_offset_y += (MMI_title_height + MMI_title_y);
    }
    
    if (g_camera_cntx.active_camera_osd_ptr->softkey.is_draw_mmi_softkey)
    {
        image_region_height -= (MMI_button_bar_height);
    }
    
    /* TODO: check image_width & image_height no Zero */
    
    image_box_width = image_region_width - spacing * (CAMERA_FEATURE_CONT_SHOT_BURST_SAVE_COL * 2);
    image_box_width /= CAMERA_FEATURE_CONT_SHOT_BURST_SAVE_COL;
    
    image_box_height = image_region_height - spacing * (CAMERA_FEATURE_CONT_SHOT_BURST_SAVE_ROW * 2);
    image_box_height /= CAMERA_FEATURE_CONT_SHOT_BURST_SAVE_ROW;
    
    index = 0;
    for (i = 0; i < CAMERA_FEATURE_CONT_SHOT_BURST_SAVE_ROW; i++)
    {
        for (j = 0; j < CAMERA_FEATURE_CONT_SHOT_BURST_SAVE_COL; j++)
        {
            image_buf_ptr = (PU8) g_camera_cntx.burst_jpg_data.file_address[index];
            image_buf_size = (U32) g_camera_cntx.burst_jpg_data.file_size[index];
            
            image_box_offset_x = image_region_offset_x + (j * 2 + 1) * spacing + j * image_box_width;
            image_box_offset_y = image_region_offset_y + (i * 2 + 1) * spacing + i * image_box_height;
            
            if ((image_box_width >= image_width) && (image_box_height >= image_height))
            {
                /* align preview window at the center of box */
                offset_x = image_box_offset_x + ((image_box_width - image_width) >> 1);
                offset_y = image_box_offset_y + ((image_box_height - image_height) >> 1);
                
                gdi_image_jpeg_draw(offset_x, offset_y, image_buf_ptr, image_buf_size);
                
                gdi_draw_rect(
                    image_box_offset_x + offset_x - 1,
                    image_box_offset_y + offset_y - 1,
                    image_box_offset_x + offset_x + image_width,
                    image_box_offset_y + offset_y + image_height,
                    GDI_COLOR_WHITE);
            }
            else
            {
                gdi_image_util_fit_bbox(
                    image_box_width,
                    image_box_height,
                    image_width,
                    image_height,
                    &resized_offset_x,
                    &resized_offset_y,
                    &resized_width,
                    &resized_height);
                gdi_image_jpeg_draw_resized(
                    resized_offset_x + image_box_offset_x,
                    resized_offset_y + image_box_offset_y,
                    resized_width,
                    resized_height,
                    image_buf_ptr,
                    image_buf_size);
                
                gdi_draw_rect(
                    image_box_offset_x + resized_offset_x - 1,
                    image_box_offset_y + resized_offset_y - 1,
                    image_box_offset_x + resized_offset_x + resized_width,
                    image_box_offset_y + resized_offset_y + resized_height,
                    GDI_COLOR_WHITE);
                
            }
            
		#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#endif /* defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) */

            /* blt */
            mmi_camera_blt();
            
            /* next image */
            index++;
        }
    }
    
    /* draw save notify text */
    mmi_camera_preview_set_hint((PS8) GetString(STR_ID_CAMERA_NOTIFY_SAVE_CONFIRM), NULL, 0);
    mmi_camera_preview_draw_osd();
    
    /* blt */
    mmi_camera_blt();
    
}
#endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_exit_burstshot_save_confirm_state
* DESCRIPTION
*  exit save confirm state
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
static void mmi_camera_exit_burstshot_save_confirm_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* free preview resource */
    if (g_camera_cntx.app_next_state == CAMERA_STATE_EXIT)
    {
        /* turn off led highlight */
        mmi_camera_turn_off_led_highlight();
    }
    else
    {
        /* clear panel */
        mmi_camera_preview_set_hint(NULL, NULL, 0);
        mmi_camera_preview_draw_osd();
        
        mmi_camera_blt();
    }
    
}
#endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_burstshot_save_confirm_lsk_press
* DESCRIPTION
*  draw save confirm softkey
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
static void mmi_camera_burstshot_save_confirm_lsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.is_lsk_pressed = TRUE;
    mmi_camera_preview_draw_osd();
    
    mmi_camera_blt();
}
#endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_burstshot_save_confirm_lsk_release
* DESCRIPTION
*  lsk release
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
static void mmi_camera_burstshot_save_confirm_lsk_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_camera_cntx.is_lsk_pressed == FALSE)
    {
        return;
    }
    g_camera_cntx.is_lsk_pressed = FALSE;
    mmi_camera_preview_draw_osd();
    mmi_camera_blt();
    
    /* enter burstshot saving to save file */
    CAMERA_ENTER_STATE(CAMERA_STATE_BURSTSHOT_SAVING);
}
#endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_burstshot_save_confirm_rsk_press
* DESCRIPTION
*  draw save confirm softkey
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
static void mmi_camera_burstshot_save_confirm_rsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.is_rsk_pressed = TRUE;
    mmi_camera_preview_draw_osd();
    mmi_camera_blt();
}
#endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_burstshot_save_confirm_rsk_release
* DESCRIPTION
*  draw save confirm softkey
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
static void mmi_camera_burstshot_save_confirm_rsk_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_camera_cntx.is_rsk_pressed == FALSE)
    {
        return;
    }
    g_camera_cntx.is_rsk_pressed = FALSE;
    
    mmi_camera_preview_draw_osd();
    mmi_camera_blt();
    
    CAMERA_ENTER_STATE(CAMERA_STATE_PREVIEW);
}
#endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 

/*****************************************************************************
*
*  Save Burstshot State
*
*****************************************************************************/


/*****************************************************************************
* FUNCTION
*  mmi_camera_entry_burstshot_saving_state
* DESCRIPTION
*  entry save burstshot state
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
static void mmi_camera_entry_burstshot_saving_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* register softkeys */
    ClearInputEventHandler(MMI_DEVICE_KEY);
    
    SetKeyHandler(mmi_camera_dummy_func, KEY_LSK, KEY_EVENT_UP);
    SetKeyHandler(mmi_camera_dummy_func, KEY_RSK, KEY_EVENT_UP);
    
    /* clearn center key - since if not clear, this key will mappign to LSK */
    if (CAMERA_CAPTURE_KEY != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, CAMERA_CAPTURE_KEY, KEY_EVENT_DOWN);
    }
    
    if (CAMERA_CAPTURE_EXTRA_KEY1 != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY1, KEY_EVENT_DOWN);
    }
    
    if (CAMERA_CAPTURE_EXTRA_KEY2 != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_LONG_PRESS);
    }
    
    
    /* draw base layer only */
    gdi_layer_set_blt_layer(g_camera_cntx.base_layer_handle, 0, 0, 0);
    
#if defined(__CAMERA_OSD_HORIZONTAL__)
    mmi_frm_reset_screen_rotation();
    if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270)
    {
        gdi_layer_resize(LCD_HEIGHT,LCD_WIDTH);
        gdi_layer_set_rotate(GDI_LAYER_ROTATE_0);
        mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
    }
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
    
    /* currently we use gdi layer buffer for OSD, but when show category, it also use gdi buffer, 
    so we should release the memory */
    if (g_camera_cntx.gdi_layer_handle != GDI_NULL_HANDLE)
    {       
        gdi_layer_free(g_camera_cntx.gdi_layer_handle);
        g_camera_cntx.gdi_layer_handle = GDI_NULL_HANDLE;
        g_camera_cntx.gdi_layer_buffer_ptr = NULL;
    }

#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    force_no_small_screen();
#endif
#ifdef __CAMERA_FEATURE_ADD_FRAME__
    mmi_camera_free_add_frame_layer();
#endif
    ExitCategoryFunction();
    gdi_layer_lock_frame_buffer();
    ShowCategory65Screen((PU8) GetString(STR_GLOBAL_SAVING), mmi_get_event_based_image(MMI_EVENT_PROGRESS), NULL);
    gdi_layer_unlock_frame_buffer();
    g_camera_cntx.is_cat65_show = TRUE;
    
    
    /* start save burst shot */
    g_camera_cntx.burst_save_index = 0;
    mmi_camera_burstshot_saving_cyclic();
}
#endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_exit_burstshot_saving_state
* DESCRIPTION
*  exit save burstshot state
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
static void mmi_camera_exit_burstshot_saving_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* exit popup screen to free drawmanager's resource */
    if (g_camera_cntx.is_cat65_show)
    {
        g_camera_cntx.is_cat65_show = FALSE;
        ExitCategoryFunction();
    }
    
    gui_cancel_timer(mmi_camera_burstshot_saving_cyclic);
    gdi_image_stop_animation_all();
    
    if (g_camera_cntx.app_next_state == CAMERA_STATE_EXIT)
    {
        /* turn off led highlight */
        mmi_camera_turn_off_led_highlight();
        
        /* flatten layer */
        mmi_camera_preview_flatten_layer(FALSE);
    }
}
#endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_burstshot_saving_cyclic
* DESCRIPTION
*  loop to save burstshot image
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
static void mmi_camera_burstshot_saving_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filename[FMGR_PATH_BUFFER_SIZE];
    PU8 image_buf_ptr;
    U32 image_buf_size;
    U32 written;
    FS_HANDLE file_handle;
    
#ifdef EXIF_SUPPORT
    U32 size_of_exif_info = 0;
#endif 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* this function has nvram access */
    mmi_camera_get_next_filename(buf_filename);
    
    mmi_camera_commit_filename_seq_no();
    
    /* start timer for next shot */
    gui_start_timer(100, mmi_camera_burstshot_saving_cyclic);
    
    /* save burst shot image */
    
    image_buf_ptr = (PU8) g_camera_cntx.burst_jpg_data.file_address[g_camera_cntx.burst_save_index];
    image_buf_size = (U32) g_camera_cntx.burst_jpg_data.file_size[g_camera_cntx.burst_save_index];
    
    file_handle = FS_Open((U16*) buf_filename, FS_CREATE | FS_READ_WRITE);
    
    if (file_handle > 0)
    {
#ifdef EXIF_SUPPORT
        /* eixf_burst_mode_fill_header(kal_uint8* Buffer,kal_uint32 BufferOffset); */
#if defined(__MTK_TARGET__)
        size_of_exif_info = eixf_burst_mode_fill_header(image_buf_ptr);
#endif 
        image_buf_size += size_of_exif_info;
        image_buf_ptr -= size_of_exif_info;
#endif /* EXIF_SUPPORT */ 
        FS_Write(file_handle, (void*)image_buf_ptr, image_buf_size, (U32*) & written);
        FS_Close(file_handle);
        
        /* cant write in whole file, must be disk full */
        if (image_buf_size != written)
        {
            /* delete the file that is not save complete */
            FS_Delete((U16*) buf_filename);
            g_camera_cntx.last_error = MDI_RES_CAMERA_ERR_DISK_FULL;
            mmi_camera_restore_filename_seq_no();
            /* will display a popup, go out application and re-enter */
            mmi_camera_display_error_popup();
            return;
        }
    }
    else
    {
        if (file_handle == FS_DISK_FULL)
        {
            g_camera_cntx.last_error = MDI_RES_CAMERA_ERR_DISK_FULL;
        }
        else if (file_handle == FS_ROOT_DIR_FULL)
        {
            g_camera_cntx.last_error = CAMERA_ERR_ROOT_DIR_FULL;
        }
        else if (file_handle == FS_WRITE_PROTECTION)
        {
            g_camera_cntx.last_error = MDI_RES_CAMERA_ERR_WRITE_PROTECTION;
        }
        else
        {
            g_camera_cntx.last_error = CAMERA_ERR_SAVE_FAIL;
        }
        mmi_camera_restore_filename_seq_no();
        /* will display a popup, go out application and re-enter */
        mmi_camera_display_error_popup();
        return;
    }
    
    /* teminate condition */
    if (g_camera_cntx.burst_save_index >= CAMERA_FEATURE_CONT_SHOT_BURST_COUNT - 1)
    {
        CAMERA_ENTER_STATE(CAMERA_STATE_DELETE_DONE);
        return;
    }
    
    /* increase index */
    g_camera_cntx.burst_save_index++;
    
}
#endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_entry_delete_confirm_state
* DESCRIPTION
*  enter save confirm state
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_entry_delete_confirm_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 image_width;
    S32 image_height;
    S32 offset_x;
    S32 offset_y;
    S32 resized_offset_x;
    S32 resized_offset_y;
    S32 resized_width;
    S32 resized_height;
    S32 result;
    S32 image_region_width;
    S32 image_region_height;
    S32 image_region_offset_x;
    S32 image_region_offset_y;
    S32 index;
    S32 str_len = mmi_ucs2strlen(g_camera_cntx.captured_filepath);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_CAMERA_START_MEASURE("ADC");
    
    /* init var */
    g_camera_cntx.is_lsk_pressed = FALSE;
    g_camera_cntx.is_rsk_pressed = FALSE;
    
#ifdef __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__
    mmi_camera_stop_app_watchdog();
    mmi_camera_start_delete_confirm_watchdog();
#endif
    
    /* register soft keys */
    ClearInputEventHandler(MMI_DEVICE_KEY);
    
    /* continue */
    SetKeyHandler(mmi_camera_delete_confirm_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_delete_confirm_rsk_release, KEY_RSK, KEY_EVENT_UP);
    
    /* options */
    SetKeyHandler(mmi_camera_delete_confirm_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_delete_confirm_lsk_release, KEY_LSK, KEY_EVENT_UP);
    
    SetKeyHandler(mmi_camera_reentry_preview_state, KEY_CAMERA, KEY_EVENT_DOWN);
    
#if defined(__MMI_OP11_CAMERA_VDOREC_CUSTOMIZE__)
#if defined(__MMI_CAMERA_FORWARD_SUPPORT__)
    if (g_camera_cntx.external_request_mode == MMI_CAMERA_EXTERNAL_MODE_OFF
        && g_camera_cntx.app_state == CAMERA_STATE_DELETE_CONFIRM 
        && mmi_camera_is_forward_function_ready() == MMI_TRUE)
    {
        SetKeyHandler(mmi_camera_forward_icon_press, KEY_ENTER, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_forward_icon_release, KEY_ENTER, KEY_EVENT_UP);
        
        SetKeyHandler(mmi_camera_forward_icon_press, KEY_9, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_forward_icon_release, KEY_9, KEY_EVENT_UP);
    }
#endif /* defined(__MMI_CAMERA_FORWARD_SUPPORT__) */ 
#endif
    /* free preview resource */
    mmi_camera_preview_free_preview_resource();
    
    /* reset osd layer, due to we may use 3osd or 5osd, currently we use 1osd, so need to reset */
    mmi_camera_reset_osd_layer();
    
    /* before drawing captured jpeg on osd, we need to reset base layer if no direct couplbe support */
    /* in direct couple mode, the image is saved in base layer ,so can not reset base layer*/
    if (!g_camera_cntx.is_direct_couple)
    {
        mmi_camera_reset_base_layer();
    }
    
    /* init title bar */
    if (g_camera_cntx.active_camera_osd_ptr->title.is_draw_mmi_title_bar)
    {
#if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)
        reset_title_status_icon();
        show_status_icon_bar(0);
#endif /* defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) */ 
        
        /* hide short cut */
        wgui_title_set_menu_shortcut_number(-1);
        
        if (g_camera_cntx.active_camera_osd_ptr->title.is_draw_mmi_caption)
        {
            ChangeTitle(MAIN_MENU_TITLE_MULTIMEDIA_ICON, (PU8) GetString(STR_ID_CAMERA_APP_NAME));
        }
        else
        {
            ChangeTitle(0, (PU8) GetString(STR_ID_CAMERA_APP_NAME));
        }
    }
    else
    {
#if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)
        hide_status_icon_bar(0);
#endif 
    }
    
    if (g_camera_cntx.is_tileshot)
    {
        MMI_ASSERT(0);
    }
    else
    {
        /* clear base layer background */
        /* in direct couple mode, the image is saved in base layer ,so can not reset base layer*/
        if (!g_camera_cntx.is_direct_couple)
        {
            mmi_camera_preview_clear_background();
        }
        gdi_layer_set_blt_layer(g_camera_cntx.base_layer_handle, g_camera_cntx.osd_layer_handle0, 0, 0);
        
        if (g_camera_cntx.app_prev_state == CAMERA_STATE_FORWARD_TO || CAMERA_STATE_IN(CAMERA_STATE_FORWARD_TO))
        {
            /* get file dimension */
            result = gdi_image_jpeg_get_dimension_file(
                g_camera_cntx.captured_filepath,
                &image_width,
                &image_height);
        }
        else
        {
            /*in this case, direct couple will no capture buffer for you, only direct couple buffer for you
            so we may get the file info from file, but this may lead mmi run much time, maybe some time it will 
            crash , then on that project, it should not open this compile option*/
        #ifdef __YUVCAM_ENCODE_DIRECT_WRITE_FILE__
            /* get file dimension */
            result = gdi_image_jpeg_get_dimension_file(
                g_camera_cntx.captured_filepath,
                &image_width,
                &image_height);
        #else
            result = gdi_image_jpeg_get_dimension(
                g_camera_cntx.capture_buf_ptr,
                g_camera_cntx.capture_size,
                &image_width,
                &image_height);
        #endif
        }
        /* set clip region as content region */
        gdi_layer_reset_clip();
        
        MMI_CAMERA_GET_START_TIME(MMI_TRC_CAMERA_DECODE_JPEG_TIME);
        MMI_CAMERA_START_MEASURE("ADJ");
#ifdef __MMI_CAMERA_DIRECT_COUPLE__
        if (g_camera_cntx.is_direct_couple == TRUE && (g_camera_cntx.app_prev_state != CAMERA_STATE_FORWARD_TO && !CAMERA_STATE_IN(CAMERA_STATE_FORWARD_TO)))
        {
            PU8 src;
            PU8 dest;
            U16 src_width, src_height, src_pitch;
            S32 src_offset_x=0, src_offset_y=0;
            S32 dest_pitch, dest_offset_x, dest_offset_y;
            gdi_rect_struct dest_clip;
            
            /*@ Add by Vincent */
            /* need to set base layer's rotation for direct couple */
#if defined(__CAMERA_OSD_HORIZONTAL__)
            if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270)
            {
                gdi_layer_resize(LCD_HEIGHT,LCD_WIDTH);
                gdi_layer_set_rotate(GDI_LAYER_ROTATE_90);
            }
#endif
            
            gdi_layer_get_buffer_ptr(&dest);
            src = g_camera_cntx.direct_couple_buffer;
            src_pitch = g_camera_cntx.resized_width;
            dest_pitch = g_camera_cntx.osd_UI_device_width;
            dest_clip.x1 = g_camera_cntx.resized_offset_x;
            dest_clip.y1 = g_camera_cntx.resized_offset_y;
            dest_clip.x2 = g_camera_cntx.resized_offset_x + g_camera_cntx.resized_width - 1;
            dest_clip.y2 = g_camera_cntx.resized_offset_y + g_camera_cntx.resized_height - 1;
            src_width = g_camera_cntx.resized_width;
            src_height = g_camera_cntx.resized_height;
            dest_offset_x = g_camera_cntx.resized_offset_x;
            dest_offset_y = g_camera_cntx.resized_offset_y;
            
            /* use 2D copy from cache layer to thumbnail layer */
            gdi_2d_memory_blt_without_transpant_check(
                src,
                src_pitch,
                src_offset_x,
                src_offset_y,
                src_width,
                src_height,
                dest,
                dest_pitch,
                dest_offset_x,
                dest_offset_y,
                dest_clip,
                GDI_MAINLCD_BIT_PER_PIXEL);
            
            g_camera_cntx.is_direct_couple = FALSE;
        }
        else
#endif
        {
            /* calc image region */
            image_region_width = g_camera_cntx.osd_UI_device_width;
            image_region_height = g_camera_cntx.osd_UI_device_height;
            image_region_offset_x = 0;
            image_region_offset_y = 0;
            
            if (g_camera_cntx.active_camera_osd_ptr->title.is_draw_mmi_title_bar)
            {
                image_region_height -= (MMI_title_height + MMI_title_y);
                image_region_offset_y += (MMI_title_height + MMI_title_y);
            }
            
            if (g_camera_cntx.active_camera_osd_ptr->softkey.is_draw_mmi_softkey)
            {
                image_region_height -= (MMI_button_bar_height);
            }
            
            if (result >= 0)
            {
                if ((image_region_width >= image_width) && (image_region_height >= image_height))
                {
                    /* align preview window at the center of screen */
                    offset_x = image_region_offset_x + ((image_region_width - image_width) >> 1);
                    offset_y = image_region_offset_y + ((image_region_height - image_height) >> 1);
                    
                    if (g_camera_cntx.app_prev_state == CAMERA_STATE_FORWARD_TO || CAMERA_STATE_IN(CAMERA_STATE_FORWARD_TO))
                    {
                        gdi_image_jpeg_draw_file(offset_x, offset_y, g_camera_cntx.captured_filepath);
                    }
                    else
                    {
                    /*in this case, direct couple will no capture buffer for you, only direct couple buffer for you
                    so we may get the file info from file, but this may lead mmi run much time, maybe some time it will 
                        crash , then on that project, it should not open this compile option*/
                    #ifdef __YUVCAM_ENCODE_DIRECT_WRITE_FILE__
                        gdi_image_jpeg_draw_file(offset_x, offset_y, g_camera_cntx.captured_filepath);
                    #else
                        gdi_image_jpeg_draw(offset_x, offset_y, g_camera_cntx.capture_buf_ptr, g_camera_cntx.capture_size);
                    #endif
                    }   
                }
                else
                {
                    gdi_image_util_fit_bbox(
                        image_region_width,
                        image_region_height,
                        image_width,
                        image_height,
                        &resized_offset_x,
                        &resized_offset_y,
                        &resized_width,
                        &resized_height);
                    
                    if (g_camera_cntx.app_prev_state == CAMERA_STATE_FORWARD_TO || CAMERA_STATE_IN(CAMERA_STATE_FORWARD_TO))
                    {
                        gdi_image_jpeg_draw_resized_file(
                            resized_offset_x + image_region_offset_x,
                            resized_offset_y + image_region_offset_y,
                            resized_width,
                            resized_height,
                            g_camera_cntx.captured_filepath);
                    }
                    else
                    {
                    /*in this case, direct couple will no capture buffer for you, only direct couple buffer for you
                    so we may get the file info from file, but this may lead mmi run much time, maybe some time it will 
                        crash , then on that project, it should not open this compile option*/
                    #ifdef __YUVCAM_ENCODE_DIRECT_WRITE_FILE__
                        gdi_image_jpeg_draw_resized_file(
                            resized_offset_x + image_region_offset_x,
                            resized_offset_y + image_region_offset_y,
                            resized_width,
                            resized_height,
                            g_camera_cntx.captured_filepath);
                    #else
                        gdi_image_jpeg_draw_resized(
                            resized_offset_x + image_region_offset_x,
                            resized_offset_y + image_region_offset_y,
                            resized_width,
                            resized_height,
                            g_camera_cntx.capture_buf_ptr,
                            g_camera_cntx.capture_size);
                    #endif
                    }
                }
            }
            else 
            {
                /*Correct the result of GDI*/
                if (!mmi_camera_check_and_restore_valid_drv())
                {
                    g_camera_cntx.last_error = MDI_RES_CAMERA_ERR_NO_DISK;
                }
                else
                {
                    g_camera_cntx.last_error = result;
                }
                return;
            }
        }
}
MMI_CAMERA_STOP_MEASURE("ADJ");
MMI_CAMERA_GET_STOP_TIME_AND_PRINT_TRACE(MMI_TRC_CAMERA_DECODE_JPEG_TIME);

/* find file name - by finding "\\" */
for (index = str_len * 2 - 2; index >= 2; index -= 2)
{
    if (mmi_ucs2ncmp((PS8) & g_camera_cntx.captured_filepath[index], (PS8) L"\\", 1) == 0)
    {
        index += 2;
        break;
    }
}

/* draw filename, for we use hint style to draw filename, we must make the hint display to TRUE*/
{
    BOOL is_display_hint_org;
    
    is_display_hint_org = g_camera_cntx.active_camera_osd_ptr->hint_box.is_show;
    if (g_camera_cntx.active_camera_osd_ptr->hint_box.is_show == FALSE)
    {
        g_camera_cntx.active_camera_osd_ptr->hint_box.is_show = TRUE;
    }
    mmi_camera_preview_set_hint((PS8) &(g_camera_cntx.captured_filepath[index]), NULL, 0);
    mmi_camera_preview_draw_osd();
    
    g_camera_cntx.active_camera_osd_ptr->hint_box.is_show = is_display_hint_org;
}

/* blt */
mmi_camera_blt();
MMI_CAMERA_STOP_MEASURE("ADC");
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_exit_delete_confirm_state
* DESCRIPTION
*  exit save confirm state
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_exit_delete_confirm_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__
    mmi_camera_stop_delete_confirm_watchdog();
#endif
    /*@ Add by Vincent */
    /* need to set back base layer's rotation due to direct couple */
#if defined(__MMI_CAMERA_DIRECT_COUPLE__) 
    gdi_layer_resize(LCD_WIDTH,LCD_HEIGHT);
    gdi_layer_set_rotate(GDI_LAYER_ROTATE_0);
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_delete_confirm_lsk_press
* DESCRIPTION
*  draw save confirm softkey
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_delete_confirm_lsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.is_lsk_pressed = TRUE;
    mmi_camera_preview_draw_osd();
#ifdef __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__
    mmi_camera_stop_delete_confirm_watchdog();
#endif
    
    gdi_lcd_blt(g_camera_cntx.base_layer_handle, g_camera_cntx.osd_layer_handle0, 0, 0);
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_delete_confirm_lsk_release
* DESCRIPTION
*  lsk release
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_delete_confirm_lsk_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_camera_cntx.is_lsk_pressed == FALSE)
    {
        return;
    }
    g_camera_cntx.is_lsk_pressed = FALSE;
    mmi_camera_preview_draw_osd();
    
    gdi_lcd_blt(g_camera_cntx.base_layer_handle, g_camera_cntx.osd_layer_handle0, 0, 0);
    
    /*@ Add by Vincent */
    /* need to set back base layer's rotation for direct couple */
#if defined(__MDI_CAMERA_HW_ROTATOR_SUPPORT__) 
    gdi_layer_resize(LCD_WIDTH,LCD_HEIGHT);
    gdi_layer_set_rotate(GDI_LAYER_ROTATE_0);
#endif
    
    if (g_camera_cntx.external_request_mode == MMI_CAMERA_EXTERNAL_MODE_OFF)
    {
        g_camera_cntx.app_prev_state = g_camera_cntx.app_state;
        g_camera_cntx.app_state = CAMERA_STATE_FORWARD_TO;
    #if defined(__CAMERA_OSD_HORIZONTAL__)
        if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270)
        {
            mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
        }
        else
        {
            mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_0);
        }
    #endif /* __CAMERA_OSD_HORIZONTAL__ */
    if (mmi_camera_is_forward_function_ready()) /* not in flight mode */
    {
        mmi_frm_unhide_menu_item(MENU_ID_CAMERA_FORWARD_OPTION);
    #if defined(__MMI_MMS_POSTCARD__)
    #if defined(__MMI_EMAIL__)
        mmi_frm_hide_menu_item(MENU_ID_CAMERA_FORWARD_OPTION_TO_EMAIL);
    #endif
        if (mms_is_ready())
        {
            mmi_frm_unhide_menu_item(MENU_ID_CAMERA_FORWARD_OPTION_TO_POSTCARD);
        }
        else
        {
            mmi_frm_hide_menu_item(MENU_ID_CAMERA_FORWARD_OPTION_TO_POSTCARD);
        }

    #elif defined(__MMI_EMAIL__)
        if (mmi_email_is_email_can_forward()==TRUE)
        {
            mmi_frm_unhide_menu_item(MENU_ID_CAMERA_FORWARD_OPTION_TO_EMAIL);
        }
        else
        {
            mmi_frm_hide_menu_item(MENU_ID_CAMERA_FORWARD_OPTION_TO_EMAIL);
        }
    #endif
    
    #if defined(__MMI_MMS__)
        if (mms_is_ready())
        {
            mmi_frm_unhide_menu_item(MENU_ID_CAMERA_FORWARD_OPTION_TO_MMS);
        }
        else
        {
            mmi_frm_hide_menu_item(MENU_ID_CAMERA_FORWARD_OPTION_TO_MMS);
        }
    #endif
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_CAMERA_FORWARD_OPTION);
    }
        
    DisplayCascadingMenu(
        MENU_ID_CAMERA_CONFIRM_OPTION,
        mmi_camera_delete_confirm_option_cmd_hdlr);
    }
    else 
    {
        /* for External Request */
        g_camera_cntx.callback_ptr(MMI_TRUE,g_camera_cntx.captured_filepath);
        GoBackHistory();
        if (g_camera_cntx.is_in_fast_forward == TRUE)
        {
            g_camera_cntx.app_state = CAMERA_STATE_FORWARD_TO;
            g_camera_cntx.is_in_fast_forward = FALSE;
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_delete_confirm_rsk_press
* DESCRIPTION
*  draw save confirm softkey
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_delete_confirm_rsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.is_rsk_pressed = TRUE;
    mmi_camera_preview_draw_osd();
#ifdef __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__
    mmi_camera_stop_delete_confirm_watchdog();
#endif
    gdi_lcd_blt(g_camera_cntx.base_layer_handle, g_camera_cntx.osd_layer_handle0, 0, 0);
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_delete_confirm_rsk_release
* DESCRIPTION
*  draw save confirm softkey
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_delete_confirm_rsk_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_camera_cntx.is_rsk_pressed == FALSE)
    {
        return;
    }
    g_camera_cntx.is_rsk_pressed = FALSE;
    
    mmi_camera_preview_draw_osd();
    gdi_lcd_blt(g_camera_cntx.base_layer_handle, g_camera_cntx.osd_layer_handle0, 0, 0);
    if (g_camera_cntx.external_request_mode == MMI_CAMERA_EXTERNAL_MODE_OFF)
    {
        CAMERA_ENTER_STATE(CAMERA_STATE_PREVIEW);
    }
    else
    {
        mmi_camera_delete_confirm_delete_file();
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_delete_confirm_delete_file
* DESCRIPTION
*  save file
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_delete_confirm_delete_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_check;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* blt base only */
    gdi_layer_set_blt_layer(g_camera_cntx.base_layer_handle, 0, 0, 0);
    
    gdi_layer_lock_frame_buffer();
    
    /* show popup category */
#if defined(__CAMERA_OSD_HORIZONTAL__)
    mmi_frm_reset_screen_rotation();
    if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270)
    {
        /* rotate base layer */
        gdi_layer_resize(LCD_HEIGHT,LCD_WIDTH);
        gdi_layer_set_rotate(GDI_LAYER_ROTATE_0);
        mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
    }
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
    
    /* currently we use gdi layer buffer for OSD, but when show category, it also use gdi buffer, 
    so we should release the memory */
    if (g_camera_cntx.gdi_layer_handle != GDI_NULL_HANDLE)
    {       
        gdi_layer_free(g_camera_cntx.gdi_layer_handle);
        g_camera_cntx.gdi_layer_handle = GDI_NULL_HANDLE;
        g_camera_cntx.gdi_layer_buffer_ptr = NULL;
    }
    
#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    force_no_small_screen();
#endif 
#ifdef __CAMERA_FEATURE_ADD_FRAME__
    mmi_camera_free_add_frame_layer();
#endif
    ExitCategoryFunction();
    gdi_layer_lock_frame_buffer();
    ShowCategory65Screen((PU8) GetString(STR_GLOBAL_DELETING), mmi_get_event_based_image(MMI_EVENT_PROGRESS), NULL);
    gdi_layer_unlock_frame_buffer();
    g_camera_cntx.is_cat65_show = TRUE;
    
    
    gdi_layer_unlock_frame_buffer();
    mmi_camera_blt();
    
    if (g_camera_cntx.is_tileshot)
    {
        MMI_ASSERT(0);
    }
    else
    {
        file_check = FS_Delete((U16*) g_camera_cntx.captured_filepath);
        
        mmi_camera_restore_filename_seq_no();
        
        /* cant write in whole file, must be disk full */
        if (file_check != FS_NO_ERROR)
        {
            MMI_ID_TYPE str_id;
            
            str_id = GetFileSystemErrorString(file_check);
            
            if (g_camera_cntx.is_cat65_show)
            {
                g_camera_cntx.is_cat65_show = FALSE;
                ExitCategoryFunction();
            }   

            MMI_CAMERA_DISPLAY_POPUP(GetString(str_id), MMI_EVENT_FAILURE);
            
            return;
        }
    }
    
    if (g_camera_cntx.is_cat65_show)
    {
        g_camera_cntx.is_cat65_show = FALSE;
        ExitCategoryFunction();
    }
    
    /* enter save done */
    CAMERA_ENTER_STATE(CAMERA_STATE_DELETE_DONE);
}


/*****************************************************************************
*
*  Save Done State 
*
*****************************************************************************/


/*****************************************************************************
* FUNCTION
*  mmi_camera_entry_delete_done_state
* DESCRIPTION
*  enter save done state, show a save done popup
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_entry_delete_done_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clear all keys */
    ClearInputEventHandler(MMI_DEVICE_KEY);
    
    /* draw base layer only */
    gdi_layer_set_blt_layer(g_camera_cntx.base_layer_handle, 0, 0, 0);
    
    gdi_layer_lock_frame_buffer();
    
    /* show popup category */
#if defined(__CAMERA_OSD_HORIZONTAL__)
    mmi_frm_reset_screen_rotation();
    if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270 &&
        mmi_frm_get_screen_rotate() != CAMERA_DISPLAY_ROTATE_270)
    {
        gdi_layer_resize(LCD_HEIGHT,LCD_WIDTH);
        gdi_layer_set_rotate(GDI_LAYER_ROTATE_0);
        mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
    }
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
    
#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    force_no_small_screen();
#endif 
#ifdef __CAMERA_FEATURE_ADD_FRAME__
    mmi_camera_free_add_frame_layer();
#endif
    ExitCategoryFunction();
    
    if (g_camera_cntx.app_prev_state == CAMERA_STATE_BURSTSHOT_SAVING)
    {
        gdi_layer_lock_frame_buffer();
        ShowCategory65Screen((PU8) GetString(STR_GLOBAL_SAVED), mmi_get_event_based_image(MMI_EVENT_SUCCESS), NULL);
        gdi_layer_unlock_frame_buffer();
    }
    else
    {
        gdi_layer_lock_frame_buffer();
        ShowCategory65Screen((PU8) GetString(STR_GLOBAL_DELETED), mmi_get_event_based_image(MMI_EVENT_SUCCESS), NULL);
        gdi_layer_unlock_frame_buffer();
    }
    
    
    g_camera_cntx.is_cat65_show = TRUE;

#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) */
    
    gdi_layer_unlock_frame_buffer();
    
    mmi_camera_blt();
    
    gui_start_timer(mmi_get_event_based_duration(MMI_EVENT_SUCCESS), mmi_camera_delete_done_timeout);
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_exit_delete_done_state
* DESCRIPTION
*  exit save done state
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_exit_delete_done_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* will display a popup, go out application and re-enter */
    if (g_camera_cntx.is_cat65_show)
    {
        g_camera_cntx.is_cat65_show = FALSE;
        ExitCategoryFunction();
    }
    
    gui_cancel_timer(mmi_camera_delete_done_timeout);
    
    /* stop anmation on popup category */
    gdi_image_stop_animation_all();
#if defined(__CAMERA_OSD_HORIZONTAL__)
    
    if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270)
    {
        mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_0);
        gdi_layer_push_and_set_active(g_camera_cntx.base_layer_handle);
        gdi_layer_clear_background(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
        
    }
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
    
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_delete_done_timeout
* DESCRIPTION
*  save done popup timeout
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_delete_done_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* enter sub preview state */
    CAMERA_ENTER_STATE(CAMERA_STATE_PREVIEW);  
}

/***************************************************************************
*
*  Mainlcd Capture 
*
***************************************************************************/
#ifdef __MMI_CAMERA_DIRECT_COUPLE__
static void mmi_camera_cal_direct_couple_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 image_region_width;
    S32 image_region_height;
    S32 image_region_offset_x;
    S32 image_region_offset_y;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    image_region_width = g_camera_cntx.osd_UI_device_width;
    image_region_height = g_camera_cntx.osd_UI_device_height;
    image_region_offset_x = 0;
    image_region_offset_y = 0;
    
    if (g_camera_cntx.active_camera_osd_ptr->title.is_draw_mmi_title_bar)
    {
        image_region_height -= (MMI_title_height + MMI_title_y);
        image_region_offset_y += (MMI_title_height + MMI_title_y);
    }
    
    if (g_camera_cntx.active_camera_osd_ptr->softkey.is_draw_mmi_softkey)
    {
        image_region_height -= (MMI_button_bar_height);
    }
    
    if ((image_region_width >= g_camera_cntx.image_width) && (image_region_height >= g_camera_cntx.image_height))
    {
        g_camera_cntx.resized_offset_x = image_region_offset_x + ((image_region_width - g_camera_cntx.image_width) >> 1);
        g_camera_cntx.resized_offset_y = image_region_offset_y + ((image_region_height - g_camera_cntx.image_height) >> 1);
        g_camera_cntx.resized_width = g_camera_cntx.image_width;
        g_camera_cntx.resized_height = g_camera_cntx.image_height;
    }
    else
    {
        gdi_image_util_fit_bbox(
            image_region_width,
            image_region_height,
            g_camera_cntx.image_width,
            g_camera_cntx.image_height,
            &g_camera_cntx.resized_offset_x,
            &g_camera_cntx.resized_offset_y,
            &g_camera_cntx.resized_width,
            &g_camera_cntx.resized_height);
    }
}
#endif


/*****************************************************************************
* FUNCTION
*  mmi_camera_capture
* DESCRIPTION
*  capture photo
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_capture(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 base_layer_buffer_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_CAMERA_GET_START_TIME(MMI_TRC_CAMERA_KEY_TO_CAPTURE_TIME);
    
#if defined(__MMI_CAMERA_DIRECT_SENSOR_SUPPORT__)
    /*
    * When __DIRECT_SENSOR_SUPPORT__, always use capture from layer.
    */
    g_camera_cntx.capture_path = CAPTURE_FROM_LAYER;
#endif
/* Vogins Start */
#if defined(__VRE30_AM__)
{
    kal_uint32 temp_size = CAMERA_OSD_BUFFER_SIZE;
    if((g_camera_cntx.image_width *g_camera_cntx.image_height*GDI_MAINLCD_BIT_PER_PIXEL)>>3 > CAMERA_OSD_BUFFER_SIZE)
    {
        temp_size = (g_camera_cntx.image_width *g_camera_cntx.image_height*GDI_MAINLCD_BIT_PER_PIXEL)>>3;
    }
/*michael 100430 begin*/
    if (!med_check_memory_is_enough(temp_size*2+CAMERA_OSD_BUFFER_SIZE))
    {
        mmi_ap_prompt_to_release_mem(MMI_AP_MED_CAMERA_ID, 
                                     0, 
                                     (temp_size)*2
                                     +CAMERA_OSD_BUFFER_SIZE,
                                     NULL);
        return;
    }
}
#endif
/*michael 100430 end*/
/* Vogins End */
    switch (g_camera_cntx.setting.cont_shot)
    {
    case CAMERA_SETTING_CONT_SHOT_OFF:
        {
            /* capture button pressed */
            g_camera_cntx.is_capturing = TRUE;
            
            mmi_camera_turn_on_capture_led_highlight();
            
            MMI_CAMERA_START_MEASURE("OSD");
            mmi_camera_preview_set_hint((PS8) GetString(STR_ID_CAMERA_NOFIFY_CAPTURING), NULL, 0);
            mmi_camera_preview_draw_osd();
            
            mmi_camera_blt();
            MMI_CAMERA_STOP_MEASURE("OSD");
            
            MMI_CAMERA_START_MEASURE("SND");
            /* play capture sound after capture */
            mmi_camera_capture_play_sound();
            MMI_CAMERA_STOP_MEASURE("SND");
            
            MMI_CAMERA_START_MEASURE("PRE");
            
            /* call mdi to capture and save */
            if (g_camera_cntx.setting.add_frame == CAMERA_SETTING_ADD_FRAME_OFF)
            {
                switch (g_camera_cntx.capture_path)
                {
                case CAPTURE_FROM_MEMORY:
#if defined(__MMI_CAMERA_DIRECT_COUPLE__)
                    mmi_camera_cal_direct_couple_data();
                    ASSERT(g_camera_cntx.direct_couple_buffer!=NULL);
                    MMI_CAMERA_STOP_MEASURE("PRE");
                    MMI_CAMERA_GET_STOP_TIME_AND_PRINT_TRACE(MMI_TRC_CAMERA_KEY_TO_CAPTURE_TIME);
                    
                    //MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_CAMERA_KEY_TO_CAPTURE_TIME, g_mmi_cam_duration,__LINE__);
                    
                    MMI_CAMERA_GET_START_TIME(MMI_TRC_CAMERA_CAPTURE_TIME);
                    MMI_CAMERA_START_MEASURE("ACJ");
                    
                    if ((g_camera_cntx.image_width > g_camera_cntx.preview_width) && 
                        (g_camera_cntx.image_height > g_camera_cntx.preview_height))
                    {
                        g_camera_cntx.is_direct_couple = FALSE;
                    }
                    else
                    {
                        g_camera_cntx.is_direct_couple = FALSE;
                    }

                    if (g_camera_cntx.is_direct_couple)
                    {
                        g_camera_cntx.last_error
                            = mdi_camera_capture_to_memory_direct_couple(&g_camera_cntx.capture_buf_ptr,
                            &g_camera_cntx.capture_size,
                            (U32) g_camera_cntx.direct_couple_buffer, 
                            ((g_camera_cntx.resized_width *g_camera_cntx.resized_height*GDI_MAINLCD_BIT_PER_PIXEL)>>3), 
                            g_camera_cntx.resized_width,
                            g_camera_cntx.resized_height,
                            g_camera_cntx.captured_filepath);
                    }
                    else
                    {
                        g_camera_cntx.last_error
                        = mdi_camera_capture_to_memory(&g_camera_cntx.capture_buf_ptr, &g_camera_cntx.capture_size, g_camera_cntx.captured_filepath);
                    }
                    MMI_CAMERA_STOP_MEASURE("ACJ");
                    MMI_CAMERA_GET_STOP_TIME_AND_PRINT_TRACE(MMI_TRC_CAMERA_CAPTURE_TIME);
                    //MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_CAMERA_CAPTURE_TIME, g_mmi_cam_duration,__LINE__);
#else
                    
                    MMI_CAMERA_STOP_MEASURE("PRE");
                    MMI_CAMERA_GET_STOP_TIME_AND_PRINT_TRACE(MMI_TRC_CAMERA_KEY_TO_CAPTURE_TIME);
                    //MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_CAMERA_KEY_TO_CAPTURE_TIME, g_mmi_cam_duration,__LINE__);
                    
                    MMI_CAMERA_GET_START_TIME(MMI_TRC_CAMERA_CAPTURE_TIME);
                    MMI_CAMERA_START_MEASURE("ACJ");
                    g_camera_cntx.last_error
                        = mdi_camera_capture_to_memory(&g_camera_cntx.capture_buf_ptr, &g_camera_cntx.capture_size, g_camera_cntx.captured_filepath);
                    MMI_CAMERA_STOP_MEASURE("ACJ");
                    MMI_CAMERA_GET_STOP_TIME_AND_PRINT_TRACE(MMI_TRC_CAMERA_CAPTURE_TIME);
                    //MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_CAMERA_CAPTURE_TIME, g_mmi_cam_duration,__LINE__);
#endif
                    break;
                case CAPTURE_FROM_LAYER:    /* capture layer to memory */
#if defined(__MMI_CAMERA_DIRECT_SENSOR_SUPPORT__)
                    mmi_camera_cal_direct_couple_data();
                    ASSERT(g_camera_cntx.direct_couple_buffer!=NULL);
                    
                    MMI_CAMERA_STOP_MEASURE("PRE");
                    MMI_CAMERA_GET_STOP_TIME_AND_PRINT_TRACE(MMI_TRC_CAMERA_KEY_TO_CAPTURE_TIME);
                    //MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_CAMERA_KEY_TO_CAPTURE_TIME, g_mmi_cam_duration,__LINE__);
                    
                    MMI_CAMERA_GET_START_TIME(MMI_TRC_CAMERA_CAPTURE_TIME);
                    MMI_CAMERA_START_MEASURE("ACJ");
                    
                    g_camera_cntx.last_error
                        = mdi_camera_capture_layer_to_memory_direct_couple(GDI_LAYER_ENABLE_LAYER_0,
                        &g_camera_cntx.capture_buf_ptr,
                        &g_camera_cntx.capture_size,
                        0,
                        0,
                        g_camera_cntx.image_width,
                        g_camera_cntx.image_height,
                        (U32) g_camera_cntx.direct_couple_buffer, 
                        ((g_camera_cntx.resized_width *g_camera_cntx.resized_height*GDI_MAINLCD_BIT_PER_PIXEL)>>3), 
                        g_camera_cntx.resized_width,
                        g_camera_cntx.resized_height,
                        g_camera_cntx.captured_filepath);
                    MMI_CAMERA_STOP_MEASURE("ACJ");
                    MMI_CAMERA_GET_STOP_TIME_AND_PRINT_TRACE(MMI_TRC_CAMERA_CAPTURE_TIME);
                    //MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_CAMERA_CAPTURE_TIME, g_mmi_cam_duration,__LINE__);
                #ifdef __DIRECT_SENSOR_SUPPORT__
                    g_camera_cntx.is_direct_couple = TRUE;
                #else
                    if ((g_camera_cntx.image_width > g_camera_cntx.preview_width) && 
                        (g_camera_cntx.image_height > g_camera_cntx.preview_height))
                    {
                        g_camera_cntx.is_direct_couple = FALSE;
                    }
                    else
                    {
                        g_camera_cntx.is_direct_couple = FALSE;
                    }
                #endif
#else /* defined(__MMI_CAMERA_DIRECT_SENSOR_SUPPORT__) */
                    MMI_CAMERA_STOP_MEASURE("PRE");
                    MMI_CAMERA_GET_STOP_TIME_AND_PRINT_TRACE(MMI_TRC_CAMERA_KEY_TO_CAPTURE_TIME);
                    //MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_CAMERA_KEY_TO_CAPTURE_TIME, g_mmi_cam_duration,__LINE__);
                    
                    MMI_CAMERA_GET_START_TIME(MMI_TRC_CAMERA_CAPTURE_TIME);
                    MMI_CAMERA_START_MEASURE("ACJ");
                    
                    g_camera_cntx.last_error
                        = mdi_camera_capture_layer_to_memory(
                        GDI_LAYER_ENABLE_LAYER_0,
                        &g_camera_cntx.capture_buf_ptr,
                        &g_camera_cntx.capture_size,
                        0,
                        0,
                        g_camera_cntx.image_width,
                        g_camera_cntx.image_height,
                        g_camera_cntx.captured_filepath);
                    MMI_CAMERA_STOP_MEASURE("ACJ");
                    MMI_CAMERA_GET_STOP_TIME_AND_PRINT_TRACE(MMI_TRC_CAMERA_CAPTURE_TIME);
                    //MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_CAMERA_CAPTURE_TIME, g_mmi_cam_duration,__LINE__);
#endif/* defined(__MMI_CAMERA_DIRECT_SENSOR_SUPPORT__) */
                    break;
                default:
                    MMI_CAMERA_STOP_MEASURE("PRE");
                    MMI_CAMERA_GET_STOP_TIME_AND_PRINT_TRACE(MMI_TRC_CAMERA_KEY_TO_CAPTURE_TIME);
                    //MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_CAMERA_KEY_TO_CAPTURE_TIME, g_mmi_cam_duration,__LINE__);
                    
                    MMI_CAMERA_GET_START_TIME(MMI_TRC_CAMERA_CAPTURE_TIME);
                    MMI_CAMERA_START_MEASURE("ACJ");
                    g_camera_cntx.last_error
                        = mdi_camera_capture_to_memory(&g_camera_cntx.capture_buf_ptr, &g_camera_cntx.capture_size, g_camera_cntx.captured_filepath);
                    MMI_CAMERA_STOP_MEASURE("ACJ");
                    MMI_CAMERA_GET_STOP_TIME_AND_PRINT_TRACE(MMI_TRC_CAMERA_CAPTURE_TIME);
                    //MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_CAMERA_CAPTURE_TIME, g_mmi_cam_duration,__LINE__);
                    break;
            }
        }
        else
        {
            switch (g_camera_cntx.capture_path)
            {
            case CAPTURE_FROM_MEMORY:
#if defined(__MMI_CAMERA_DIRECT_COUPLE__)
                mmi_camera_cal_direct_couple_data();
                ASSERT(g_camera_cntx.direct_couple_buffer!=NULL);
                
                MMI_CAMERA_STOP_MEASURE("PRE");
                MMI_CAMERA_GET_STOP_TIME_AND_PRINT_TRACE(MMI_TRC_CAMERA_KEY_TO_CAPTURE_TIME);
                //MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_CAMERA_KEY_TO_CAPTURE_TIME, g_mmi_cam_duration,__LINE__);
                
                MMI_CAMERA_GET_START_TIME(MMI_TRC_CAMERA_CAPTURE_TIME);
                MMI_CAMERA_START_MEASURE("ACJ");
                g_camera_cntx.last_error
                    = mdi_camera_capture_to_memory_direct_couple(&g_camera_cntx.capture_buf_ptr,
                    &g_camera_cntx.capture_size,
                    (U32) g_camera_cntx.direct_couple_buffer, 
                    ((g_camera_cntx.resized_width *g_camera_cntx.resized_height*GDI_MAINLCD_BIT_PER_PIXEL)>>3), 
                    g_camera_cntx.resized_width,
                    g_camera_cntx.resized_height,
                    g_camera_cntx.captured_filepath);
                MMI_CAMERA_STOP_MEASURE("ACJ");
                MMI_CAMERA_GET_STOP_TIME_AND_PRINT_TRACE(MMI_TRC_CAMERA_CAPTURE_TIME);
                //MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_CAMERA_CAPTURE_TIME, g_mmi_cam_duration,__LINE__);
                if ((g_camera_cntx.image_width > g_camera_cntx.preview_width) && 
                    (g_camera_cntx.image_height > g_camera_cntx.preview_height))
                {
                    g_camera_cntx.is_direct_couple = TRUE;
                }
                else
                {
                    g_camera_cntx.is_direct_couple = FALSE;
                }
                
#else
                MMI_CAMERA_STOP_MEASURE("PRE");
                MMI_CAMERA_GET_STOP_TIME_AND_PRINT_TRACE(MMI_TRC_CAMERA_KEY_TO_CAPTURE_TIME);
                //MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_CAMERA_KEY_TO_CAPTURE_TIME, g_mmi_cam_duration,__LINE__);
                
                MMI_CAMERA_GET_START_TIME(MMI_TRC_CAMERA_CAPTURE_TIME);
                MMI_CAMERA_START_MEASURE("ACJ");
                g_camera_cntx.last_error
                    = mdi_camera_capture_to_memory(&g_camera_cntx.capture_buf_ptr, &g_camera_cntx.capture_size, g_camera_cntx.captured_filepath);
                MMI_CAMERA_STOP_MEASURE("ACJ");
                MMI_CAMERA_GET_STOP_TIME_AND_PRINT_TRACE(MMI_TRC_CAMERA_CAPTURE_TIME);
                //MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_CAMERA_CAPTURE_TIME, g_mmi_cam_duration,__LINE__);
#endif
                break;
            case CAPTURE_FROM_LAYER:
                
                gdi_layer_set_blt_layer(
                    g_camera_cntx.preview_layer_handle,
                    g_camera_cntx.osd_layer_handle0,
                    g_camera_cntx.add_frame_layer_handle,
                    0);
                
                /* (0) Base-as preview buffer, (2) Add frame layer */
                
                MMI_CAMERA_STOP_MEASURE("PRE");
                MMI_CAMERA_GET_STOP_TIME_AND_PRINT_TRACE(MMI_TRC_CAMERA_KEY_TO_CAPTURE_TIME);
                //MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_CAMERA_KEY_TO_CAPTURE_TIME, g_mmi_cam_duration,__LINE__);
                
                MMI_CAMERA_GET_START_TIME(MMI_TRC_CAMERA_CAPTURE_TIME);
                MMI_CAMERA_START_MEASURE("ACJ");
                g_camera_cntx.last_error
                    = mdi_camera_capture_layer_to_memory(
                    GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_2,
                    &g_camera_cntx.capture_buf_ptr,
                    &g_camera_cntx.capture_size,
                    0,
                    0,
                    g_camera_cntx.image_width,
                    g_camera_cntx.image_height,
                    g_camera_cntx.captured_filepath);
                
                MMI_CAMERA_STOP_MEASURE("ACJ");
                MMI_CAMERA_GET_STOP_TIME_AND_PRINT_TRACE(MMI_TRC_CAMERA_CAPTURE_TIME);
                //MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_CAMERA_CAPTURE_TIME, g_mmi_cam_duration,__LINE__);
                break;
            default:
                MMI_CAMERA_STOP_MEASURE("PRE");
                MMI_CAMERA_GET_STOP_TIME_AND_PRINT_TRACE(MMI_TRC_CAMERA_KEY_TO_CAPTURE_TIME);
                //MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_CAMERA_KEY_TO_CAPTURE_TIME, g_mmi_cam_duration,__LINE__);
                
                MMI_CAMERA_GET_START_TIME(MMI_TRC_CAMERA_CAPTURE_TIME);
                MMI_CAMERA_START_MEASURE("ACJ");
                g_camera_cntx.last_error
                    = mdi_camera_capture_to_memory(&g_camera_cntx.capture_buf_ptr, &g_camera_cntx.capture_size,g_camera_cntx.captured_filepath);
                MMI_CAMERA_STOP_MEASURE("ACJ");
                MMI_CAMERA_GET_STOP_TIME_AND_PRINT_TRACE(MMI_TRC_CAMERA_CAPTURE_TIME);
                //MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_CAMERA_CAPTURE_TIME, g_mmi_cam_duration,__LINE__);
                
                break;
            }
        }
        /* restore background */
#ifdef CAMERA_MODULE_WITH_LCD
        if (!g_camera_cntx.is_fullscreen)
        {
            mmi_camera_preview_clear_background();
        }
#endif /* CAMERA_MODULE_WITH_LCD */ 
        
        /* will enter save confirm, close led highlight */
        mmi_camera_turn_off_led_highlight();
        
        /* captured, previewing is stopped, change blt layer */
        mmi_camera_preview_set_blt_layer(FALSE);
        
        if (g_camera_cntx.last_error == MDI_RES_CAMERA_SUCCEED)
        {
            MMI_CAMERA_START_MEASURE("DCP");
            
#ifdef __MMI_CAMERA_DIRECT_COUPLE__
            if (g_camera_cntx.is_direct_couple == TRUE)
            {
                PU8 src;
                PU8 dest;
                U16 src_width, src_height, src_pitch;
                S32 src_offset_x=0, src_offset_y=0;
                S32 dest_pitch, dest_offset_x, dest_offset_y;
                gdi_rect_struct dest_clip;
                /*@ Add by Vincent */
                /* need to set base layer's rotation for direct couple */
#if defined(__CAMERA_OSD_HORIZONTAL__)
                if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270)
                {
                    gdi_layer_resize(LCD_HEIGHT,LCD_WIDTH);
                    gdi_layer_set_rotate(GDI_LAYER_ROTATE_90);
                }
#endif
                /* trigger */          
                /* direct couple buffer is base layer ptr, the source buf is the same with dest, what shall we do
                find some tmp buffer, currently, the osd one buf is empty. so we use it, so trigger*/
                //gdi_layer_get_buffer_ptr(&base_layer_buffer_ptr);

                //gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle0);
                //gdi_layer_toggle_double();
                //gdi_layer_get_buffer_ptr(&dest);
                //gdi_layer_toggle_double();
                //gdi_layer_pop_and_restore_active();

                gdi_layer_get_buffer_ptr(&dest);
                
                src = g_camera_cntx.direct_couple_buffer;

                if (src != dest)
                {
                    gdi_layer_clear(GDI_COLOR_BLACK);

                    src_pitch = g_camera_cntx.resized_width;
                    dest_pitch = g_camera_cntx.osd_UI_device_width;
                    dest_clip.x1 = g_camera_cntx.resized_offset_x;
                    dest_clip.y1 = g_camera_cntx.resized_offset_y;
                    dest_clip.x2 = g_camera_cntx.resized_offset_x + g_camera_cntx.resized_width - 1;
                    dest_clip.y2 = g_camera_cntx.resized_offset_y + g_camera_cntx.resized_height - 1;
                    src_width = g_camera_cntx.resized_width;
                    src_height = g_camera_cntx.resized_height;
                    dest_offset_x = g_camera_cntx.resized_offset_x;
                    dest_offset_y = g_camera_cntx.resized_offset_y;
                    
                    /* use 2D copy from cache layer to thumbnail layer */
                    gdi_2d_memory_blt_without_transpant_check(
                        src,
                        src_pitch,
                        src_offset_x,
                        src_offset_y,
                        src_width,
                        src_height,
                        dest,
                        dest_pitch,
                        dest_offset_x,
                        dest_offset_y,
                        dest_clip,
                        GDI_MAINLCD_BIT_PER_PIXEL);
                }
                else
                {
                    /* do nothing */
                }
                //memcpy(base_layer_buffer_ptr, dest, g_camera_cntx.osd_UI_device_width * g_camera_cntx.osd_UI_device_height * 2);
                gdi_layer_set_blt_layer(g_camera_cntx.base_layer_handle,g_camera_cntx.osd_layer_handle0, 0, 0);
            }
#endif
            mmi_camera_preview_set_hint((PS8) GetString(STR_GLOBAL_SAVING), NULL, 0);
            mmi_camera_preview_draw_osd();

		#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#endif /* defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) */

            /* for reducing tearing effect on WQVGA lcm */
#if defined(__MMI_CAMERA_QVGA_WALLPAPER_ON_WQVGA_LCM__) && defined(__MMI_CAMERA_5_OSD_LAYER__)
            if (g_camera_cntx.capture_path == CAPTURE_FROM_MEMORY)
            {
        #if defined(__CAMERA_OSD_HORIZONTAL__)
                gdi_layer_blt(
                    g_camera_cntx.preview_layer_handle,
                    g_camera_cntx.osd_layer_handle0, 
                    g_camera_cntx.osd_layer_handle4, 
                    0, 
                    0, 
                    0,
                    g_camera_cntx.base_UI_device_height - 1, 
                    g_camera_cntx.base_UI_device_width - 1);
        #else
                gdi_layer_blt(
                    g_camera_cntx.preview_layer_handle,
                    g_camera_cntx.osd_layer_handle0, 
                    g_camera_cntx.osd_layer_handle4, 
                    0, 
                    0, 
                    0,
                    g_camera_cntx.base_UI_device_width - 1, 
                    g_camera_cntx.base_UI_device_height - 1);
        #endif /*__CAMERA_OSD_HORIZONTAL__*/
            }
            else
            {
                mmi_camera_blt();
            }
#else 
            mmi_camera_blt();
#endif /* __MMI_CAMERA_QVGA_WALLPAPER_ON_WQVGA_LCM__ */
            
            
            MMI_CAMERA_STOP_MEASURE("DCP");
            
            MMI_CAMERA_GET_START_TIME(MMI_TRC_CAMERA_SAVING_TIME);
            MMI_CAMERA_START_MEASURE("ASV");
            g_camera_cntx.last_error = mdi_camera_save_captured_image();
            MMI_CAMERA_STOP_MEASURE("ASV");
            MMI_CAMERA_GET_STOP_TIME_AND_PRINT_TRACE(MMI_TRC_CAMERA_SAVING_TIME);

        #if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) */ 

            //MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_CAMERA_SAVING_TIME, g_mmi_cam_duration,__LINE__);
        }
        else
		{
		#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#endif /* defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) */

		#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#endif /* defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) */ 
		}
        g_camera_cntx.is_capturing = FALSE;
        
        if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
        {
            FS_Delete((U16*) g_camera_cntx.captured_filepath);
            mmi_camera_display_error_popup();
            return;
        }
        else
        {
            /* will capture then save to file */
            mmi_camera_commit_filename_seq_no();
            
            if (g_camera_cntx.external_request_mode == MMI_CAMERA_EXTERNAL_MODE_OFF)
            {
                CAMERA_ENTER_STATE(CAMERA_STATE_DELETE_CONFIRM);
            }
            else 
            {
                CAMERA_ENTER_STATE(CAMERA_STATE_DELETE_CONFIRM);
            }
        }
    }
    break;
    
    case CAMERA_SETTING_CONT_SHOT_1:
#ifdef __CAMERA_FEATURE_CONT_SHOT_2__
    case CAMERA_SETTING_CONT_SHOT_2:
#endif 
#ifdef __CAMERA_FEATURE_CONT_SHOT_3__
    case CAMERA_SETTING_CONT_SHOT_3:
#endif 
        {
            CAMERA_ENTER_STATE(CAMERA_STATE_CONTSHOT);
            return;
        }
        break;
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
    case CAMERA_SETTING_CONT_SHOT_BURST:
        {
            CAMERA_ENTER_STATE(CAMERA_STATE_BURSTSHOT);
            return;
        }
        break;
#endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 
        
    default:
        /* restore default value */
        mmi_camera_restore_setting();
        break;
        
}

}


/*****************************************************************************
* FUNCTION
*  mmi_camera_capture_button_press
* DESCRIPTION
*  capture button presse
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_capture_button_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__
    mmi_camera_restart_app_watchdog();
#endif
    /* capture only works if camera is ready, otherwise will ignore this action */
    if (mdi_camera_is_ready_to_capture() == TRUE)
    {
        /* HANDLE AF STATE */
#ifdef __CAMERA_AUTOFOCUS__
        if (g_camera_cntx.af_state == AF_CALCULATE)
        {
            g_camera_cntx.is_af_capture = TRUE;
            return;
        }
        
        /* avoid that audio hang when playing focus succeed sound */ 
        if (!MMI_CAMERA_IS_SILENT_MODE() && g_camera_cntx.setting.shutter_sound != CAMERA_SETTING_SHUTTER_SOUND_OFF && g_camera_cntx.is_audio_finished == FALSE)
        {
            return;
        }
#endif /* __CAMERA_AUTOFOCUS__ */ 
        
#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) */
		
        /* if not self timer, capture the image */
        if (g_camera_cntx.setting.delay_timer == CAMERA_SETTING_DELAY_TIMER_OFF)
        {
            mmi_camera_capture();
        }
        else
        {
            CAMERA_ENTER_STATE(CAMERA_STATE_COUNTDOWN);
        }
    }
#ifdef __MMI_CAMERA_AF_TEST__
    else if (g_camera_cntx.is_af_test == TRUE)
    {
        mmi_camera_capture_button_press();
    }
#endif /* __MMI_CAMERA_AF_TEST__ */ 
    /* flush key event */
    ClearKeyEvents();
    
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_capture_button_release
* DESCRIPTION
*  capture button release
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_capture_button_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* flush all key event */
#ifdef __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__
    mmi_camera_restart_app_watchdog();
#endif
    ClearKeyEvents();
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_capture_play_sound
* DESCRIPTION
*  play capture shutter sound effect
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_camera_capture_play_sound(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (MMI_CAMERA_IS_SILENT_MODE())
    {
        return;
    }
    kal_get_time(&g_camera_cntx.multi_sound_tick);
#if defined (__MMI_CAMERA_DIRECT_SENSOR_SUPPORT__)
    mdi_audio_play_id(TONE_WARNING1,DEVICE_AUDIO_PLAY_ONCE,0,0);
#else
    /* force to close multi channel sound */
#if defined(__CAMERA_FEATURE_CONT_SHOT_BURST__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__)
    mmi_camera_burstshot_close_multi_sound();
    gui_cancel_timer(mmi_camera_burstshot_close_multi_sound);
#endif /* defined(__CAMERA_FEATURE_CONT_SHOT_BURST__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__) */ 
    
    /* play capture sound */
    switch (g_camera_cntx.setting.shutter_sound)
    {
    case CAMERA_SETTING_SHUTTER_SOUND_1:
        {
            mdi_audio_play_string_with_vol_path((void*)camera_sound_shutter_1, (U32) CAMERA_SOUND_SHUTTER_1_LEN,
#if defined(__MMI_CAMERA_HIGH_END__)
                MDI_FORMAT_WAV,
#else 
                MDI_FORMAT_DVI_ADPCM,
#endif 
                DEVICE_AUDIO_PLAY_ONCE,
                NULL, NULL, CAMERA_SHUTTER_SOUND_VOLUMN, MDI_DEVICE_SPEAKER_BOTH);
        }
        break;
        
    case CAMERA_SETTING_SHUTTER_SOUND_2:
        {
            mdi_audio_play_string_with_vol_path((void*)camera_sound_shutter_2, (U32) CAMERA_SOUND_SHUTTER_2_LEN,
#if defined(__MMI_CAMERA_HIGH_END__)
                MDI_FORMAT_WAV,
#else 
                MDI_FORMAT_DVI_ADPCM,
#endif 
                DEVICE_AUDIO_PLAY_ONCE,
                NULL, NULL, CAMERA_SHUTTER_SOUND_VOLUMN, MDI_DEVICE_SPEAKER_BOTH);
        }
        break;
        
    case CAMERA_SETTING_SHUTTER_SOUND_3:
        {
            mdi_audio_play_string_with_vol_path((void*)camera_sound_shutter_3, (U32) CAMERA_SOUND_SHUTTER_3_LEN,
#if defined(__MMI_CAMERA_HIGH_END__)
                MDI_FORMAT_WAV,
#else 
                MDI_FORMAT_DVI_ADPCM,
#endif 
                DEVICE_AUDIO_PLAY_ONCE,
                NULL, NULL, CAMERA_SHUTTER_SOUND_VOLUMN, MDI_DEVICE_SPEAKER_BOTH);
        }
        break;
        
    case CAMERA_SETTING_SHUTTER_SOUND_OFF:
    default:
        /* do not play sound */
        break;
    }
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_capture_play_multi_channel_sound
* DESCRIPTION
*  play capture shutter sound effect when support multi-channel
*  this is for no-blocking burst shot for MT6228
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#if defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__)
static void mmi_camera_capture_play_multi_channel_sound(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* play capture sound */
    
    if (g_camera_cntx.is_multi_sound_open==FALSE)
        return;
    
    switch (g_camera_cntx.setting.shutter_sound)
    {
    case CAMERA_SETTING_SHUTTER_SOUND_1:
    case CAMERA_SETTING_SHUTTER_SOUND_2:
    case CAMERA_SETTING_SHUTTER_SOUND_3:
        {
            if (g_camera_cntx.multi_sound_cap_idx == 0)
            {
                mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER_BOTH);
                mdi_audio_set_volume(VOL_TYPE_MEDIA,CAMERA_SHUTTER_SOUND_VOLUMN);
                mdi_audio_mma_stop_wav(g_camera_cntx.multi_sound_capture0);
                mdi_audio_mma_play_wav(g_camera_cntx.multi_sound_capture0);
            }
            else if (g_camera_cntx.multi_sound_cap_idx == 1)
            {
                mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER_BOTH);
                mdi_audio_set_volume(VOL_TYPE_MEDIA,CAMERA_SHUTTER_SOUND_VOLUMN);
                mdi_audio_mma_stop_wav(g_camera_cntx.multi_sound_capture1);
                mdi_audio_mma_play_wav(g_camera_cntx.multi_sound_capture1);
            }
            else
            {
                mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER_BOTH);
                mdi_audio_set_volume(VOL_TYPE_MEDIA,CAMERA_SHUTTER_SOUND_VOLUMN);
                mdi_audio_mma_stop_wav(g_camera_cntx.multi_sound_capture2);
                mdi_audio_mma_play_wav(g_camera_cntx.multi_sound_capture2);
            }
            
            g_camera_cntx.multi_sound_cap_idx++;
            
            if (g_camera_cntx.multi_sound_cap_idx >= 3)
            {
                g_camera_cntx.multi_sound_cap_idx = 0;
            }
            
        }
        break;
        
    case CAMERA_SETTING_SHUTTER_SOUND_OFF:
    default:
        /* do not play sound */
        break;
    }
    
}
#endif /* defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__) */ 

/*****************************************************************************
*
*  Toggle To Sub State 
*
*****************************************************************************/


/*****************************************************************************
* FUNCTION
*  mmi_camera_entry_toggle_to_sub_state
* DESCRIPTION
*  enter toggle to sub state
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_entry_toggle_to_sub_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clear all keys */
    ClearInputEventHandler(MMI_DEVICE_KEY);
    
    gdi_layer_set_blt_layer(g_camera_cntx.base_layer_handle, 0, 0, 0);
#if defined(__CAMERA_OSD_HORIZONTAL__)
    mmi_frm_reset_screen_rotation();
    if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270 &&
        mmi_frm_get_screen_rotate() != CAMERA_DISPLAY_ROTATE_270)
    {
        mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
    }
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
    
#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    force_no_small_screen();
#endif 
#ifdef __CAMERA_FEATURE_ADD_FRAME__
    mmi_camera_free_add_frame_layer();
#endif
    ExitCategoryFunction();
    gdi_layer_lock_frame_buffer();
    ShowCategory65Screen((PU8) GetString(STR_ID_CAMERA_NOTIFY_SELF_CAPTURE_ON), mmi_get_event_based_image(MMI_EVENT_SUCCESS), NULL);
    gdi_layer_unlock_frame_buffer();
    g_camera_cntx.is_cat65_show = TRUE;
    
    
    gui_start_timer(TOGGLE_POPUP_FADE_TIME, mmi_camera_toggle_to_sub_timeout);
}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_exit_toggle_to_sub_state
* DESCRIPTION
*  exit save confirm state
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_exit_toggle_to_sub_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* will display a popup, go out application and re-enter */
    if (g_camera_cntx.is_cat65_show)
    {
        g_camera_cntx.is_cat65_show = FALSE;
        ExitCategoryFunction();
    }
    
    gui_cancel_timer(mmi_camera_toggle_to_sub_timeout);
    
    /* stop anmation on popup category */
    gdi_image_stop_animation_all();
    
}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_toggle_to_sub_timeout
* DESCRIPTION
*  exit save confirm state
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_toggle_to_sub_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* enter sub preview state */
    CAMERA_ENTER_STATE(CAMERA_STATE_SUB_PREVIEW);
}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 

/*****************************************************************************
*
*  Toggle To Main State 
*
*****************************************************************************/


/*****************************************************************************
* FUNCTION
*  mmi_camera_entry_toggle_to_main_state
* DESCRIPTION
*  enter toggle to main state
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_entry_toggle_to_main_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clear all keys */
    ClearInputEventHandler(MMI_DEVICE_KEY);
    
    /* show popup category */
    gdi_layer_set_blt_layer(g_camera_cntx.base_layer_handle, 0, 0, 0);
#if defined(__CAMERA_OSD_HORIZONTAL__)
    mmi_frm_reset_screen_rotation();
    if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270 &&
        mmi_frm_get_screen_rotate() != CAMERA_DISPLAY_ROTATE_270)
    {
        mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
    }
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
    
#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
    force_no_small_screen();
#endif 
#ifdef __CAMERA_FEATURE_ADD_FRAME__
    mmi_camera_free_add_frame_layer();
#endif
    
    
    ExitCategoryFunction();
    gdi_layer_lock_frame_buffer();
    ShowCategory65Screen((PU8) GetString(STR_ID_CAMERA_NOTIFY_SELF_CAPTURE_OFF), mmi_get_event_based_image(MMI_EVENT_SUCCESS), NULL);
    gdi_layer_unlock_frame_buffer();
    g_camera_cntx.is_cat65_show = TRUE;
    
    
    gui_start_timer(TOGGLE_POPUP_FADE_TIME, mmi_camera_toggle_to_main_timeout);
}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_exit_toggle_to_main_state
* DESCRIPTION
*  exit toggle to main state
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_exit_toggle_to_main_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* will display a popup, go out application and re-enter */
    if (g_camera_cntx.is_cat65_show)
    {
        g_camera_cntx.is_cat65_show = FALSE;
        ExitCategoryFunction();
    }
    
    gui_cancel_timer(mmi_camera_toggle_to_main_timeout);
    
    /* stop anmation on popup category */
    gdi_image_stop_animation_all();
    
}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_toggle_to_main_timeout
* DESCRIPTION
*  toggle to main popup timeout
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_toggle_to_main_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* enter sub preview state */
    CAMERA_ENTER_STATE(CAMERA_STATE_PREVIEW);
}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 

/*****************************************************************************
*
*  Sublcd Screen
*
*****************************************************************************/


/*****************************************************************************
* FUNCTION
*  mmi_camera_entry_sublcd_screen
* DESCRIPTION
*  entry sublcd screen, if still remain on standard MMI sublcd screen, time update will
*  redraw sublcd while mainlcd is previewing, will cause driver assert.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __MMI_SUBLCD__
void mmi_camera_entry_sublcd_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* print debug info */
    CAMERA_TRACE_FUNC_ENTER_SUBLCD();
    
    ExecSubLCDCurrExitHandler();
    ShowCategory331Screen();
    SetSubLCDExitHandler(mmi_camera_exit_sublcd_screen);
    
    g_camera_cntx.is_sublcd_display = TRUE;
}
#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_exit_sublcd_screen
* DESCRIPTION
*  exit sublcd screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __MMI_SUBLCD__
void mmi_camera_exit_sublcd_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SubLCDHistoryNode sub_history;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* print debug info */
    CAMERA_TRACE_FUNC_EXIT_SUBLCD();
    
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
    /* someone may exit/draw sublcd first then exit mainlcd, this may cause driver assert */
    /* also stop preview here */
    mmi_camera_sublcd_preview_stop();
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 
    
    g_camera_cntx.is_sublcd_display = FALSE;
    
    sub_history.entryFuncPtr = mmi_camera_entry_sublcd_screen;
    AddSubLCDHistory(&sub_history);
    
}
#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_sublcd_draw_icon
* DESCRIPTION
*  draw a sublcd icon.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __MMI_SUBLCD__
void mmi_camera_sublcd_draw_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 image_width;
    S32 image_height;
    S32 lcd_width;
    S32 lcd_height;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_lcd_get_dimension(&lcd_width, &lcd_height);
    
    gdi_layer_reset_clip();
    
    gdi_layer_clear_background(GDI_COLOR_WHITE);
    gdi_image_get_dimension_id(IMG_ID_CAMERA_PREVIEW_SUBLCD_ICON, &image_width, &image_height);
    gdi_image_draw_id(
        (lcd_width - image_width) >> 1,
        (lcd_height - image_height) >> 1,
        IMG_ID_CAMERA_PREVIEW_SUBLCD_ICON);
    gdi_layer_blt_base_layer(0, 0, lcd_width - 1, lcd_height - 1);
    
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
}
#endif /* __MMI_SUBLCD__ */ 

/*****************************************************************************
*
*  Sublcd Preview State 
*
*****************************************************************************/


/*****************************************************************************
* FUNCTION
*  mmi_camera_entry_sublcd_preview_state
* DESCRIPTION
*  entry sublcd preview state
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_entry_sublcd_preview_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* draw a popup on mainlcd  */
    /* only first time enter sub preview needs to draw main lcd */
    if ((g_camera_cntx.app_prev_state == CAMERA_STATE_EXIT) ||
        (g_camera_cntx.app_prev_state == CAMERA_STATE_TOGGLE_TO_SUB))
    {
        gdi_layer_lock_frame_buffer();
        
        /* clear fullscreen */
#ifdef CAMERA_MODULE_WITH_LCD
        gdi_layer_clear(CAMEAR_BG_TRASN_COLOR);
#else 
        gdi_layer_clear(GDI_COLOR_BLACK);
#endif 
        
#if defined(__CAMERA_OSD_HORIZONTAL__)
        mmi_frm_reset_screen_rotation();
        if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270 &&
            mmi_frm_get_screen_rotate() != CAMERA_DISPLAY_ROTATE_270)
        {
            mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
        }
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
        
#ifdef __MMI_UI_SMALL_SCREEN_SUPPORT__
        force_no_small_screen();
#endif 
#ifdef __CAMERA_FEATURE_ADD_FRAME__
        mmi_camera_free_add_frame_layer();
#endif
        
        ExitCategoryFunction();
        gdi_layer_lock_frame_buffer();
        ShowCategory65Screen((PU8) GetString(STR_ID_CAMERA_NOFITY_SELF_CAPTURE_SUBLCD_PREVIEW), mmi_get_event_based_image(MMI_EVENT_SUCCESS), NULL);
        gdi_layer_unlock_frame_buffer();
        g_camera_cntx.is_cat65_show = TRUE;
        
        /* IMG_GLOBAL_INFO may be an animation, we have to stop it avoid both lcd updating */
        gdi_image_stop_animation_all();
        gdi_layer_unlock_frame_buffer();
        
        mmi_camera_sublcd_preview_set_key_hdlr();
        mmi_camera_blt();
    }
    
    /* turn on led highlight */
    mmi_camera_turn_on_preview_led_highlight();
    
    /* set key handler */
    mmi_camera_sublcd_preview_set_key_hdlr();
    
    /* set correct lcm rotate */
    /* config rotate of preview layer, only ISP_SUPPORT need */
#if defined(ISP_SUPPORT)
    gdi_layer_push_and_set_active(g_camera_cntx.sublcd_base_layer_handle);
    if (g_camera_cntx.is_clam_close == TRUE)
    {
        gdi_layer_set_rotate(CAMERA_LCM_SUBLCD_CLAM_CLOSE_ROTATE);
    }
    else
    {
        gdi_layer_set_rotate(CAMERA_LCM_SUBLCD_CLAM_OPEN_ROTATE);
    }
    gdi_layer_pop_and_restore_active();
#endif /* defined(ISP_SUPPORT) */ 
    /* preview start */
    mmi_camera_sublcd_preview_start();
    
    /* check if preview function has error */
    if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
    {
        mmi_camera_display_sublcd_error_popup();
    }
    
}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_exit_sublcd_preview_state
* DESCRIPTION
*  exit sublcd preview state
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_exit_sublcd_preview_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* exit app || toggle to main */
    
    /* config rotate of preview layer, only ISP_SUPPORT need */
#if defined(ISP_SUPPORT)
    gdi_layer_push_and_set_active(g_camera_cntx.sublcd_base_layer_handle);
    gdi_layer_set_rotate(CAMERA_LCM_ROTATE_0);
    gdi_layer_pop_and_restore_active();
#endif /* defined(ISP_SUPPORT) */ 
    if ((g_camera_cntx.app_next_state == CAMERA_STATE_EXIT) ||
        (g_camera_cntx.app_next_state == CAMERA_STATE_TOGGLE_TO_MAIN))
    {
        /* stop previewing */
        mmi_camera_sublcd_preview_stop();
        
        /* turn off led highlight */
        mmi_camera_turn_off_led_highlight();
        
        /* exit popup screen to free drawmanager's resource */
        /* this shall call after preview is stopped, or will cause multiple lcd access */
        if (g_camera_cntx.is_cat65_show)
        {
            ExitCategoryFunction();
        }
    }
    
    if (g_camera_cntx.app_next_state == CAMERA_STATE_EXIT)
    {
    /* 
    * when interrupt happened while clam is close (preview on sub)
    * we will go handling interrupt, when back from interrupt, 
    * we shall force enter sub again to keep clam open close state correct 
        */
        
        if (g_camera_cntx.is_clam_close)
        {
            g_camera_cntx.is_force_self_capture = TRUE;
        }
    }
    
}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_sublcd_preview_set_key_hdlr
* DESCRIPTION
*  set sublcd key handler
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_sublcd_preview_set_key_hdlr()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(mmi_camera_sublcd_preview_lsk_release, KEY_LSK, KEY_EVENT_UP);
    SetKeyHandler(mmi_camera_sublcd_preview_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
    
    SetKeyHandler(mmi_camera_sublcd_preview_rsk_release, KEY_RSK, KEY_EVENT_UP);
    SetKeyHandler(mmi_camera_sublcd_preview_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
    
    SetKeyHandler(mmi_camera_sublcd_capture_button_press, CAMERA_CAPTURE_KEY, KEY_EVENT_DOWN);
    
    if (CAMERA_CAPTURE_EXTRA_KEY1 != -1)
    {
        SetKeyHandler(mmi_camera_sublcd_capture_button_press, (U16)CAMERA_CAPTURE_EXTRA_KEY1, KEY_EVENT_DOWN);
    }
    
    if (CAMERA_CAPTURE_EXTRA_KEY2 != -1)
    {
        SetKeyHandler(mmi_camera_sublcd_capture_button_press, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_LONG_PRESS);
    }
    
    
    
    SetKeyHandler(mmi_camera_toggle_self_capture, CAMERA_TOGGLE_SELF_CAPTURE_KEY, KEY_EVENT_DOWN);
}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_sublcd_preview_start
* DESCRIPTION
*  start previewing on sublcd
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_sublcd_preview_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_camera_setting_struct camera_setting_data;
    mdi_camera_preview_struct camera_preview_data;
    S32 sublcd_width;
    S32 sublcd_height;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get sublcd base layer handle */
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_layer_get_dimension(&sublcd_width, &sublcd_height);
    
#ifdef CAMERA_MODULE_WITH_LCD
    gdi_layer_clear(CAMEAR_BG_TRASN_COLOR);
#endif 
    
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
    
    /* preview parametes */
    camera_setting_data.zoom = mmi_camera_preview_get_zoom_factor();
    camera_setting_data.wb = camera_wb_command_map[g_camera_cntx.setting.wb];
    camera_setting_data.ev = camera_ev_command_map[g_camera_cntx.setting.ev];
    camera_setting_data.banding = camera_banding_command_map[g_camera_cntx.setting.banding];
    camera_setting_data.flash = camera_flash_command_map[g_camera_cntx.setting.flash];
    camera_setting_data.ae_meter = camera_ae_meter_command_map[g_camera_cntx.setting.ae_meter];
    camera_setting_data.iso = camera_iso_command_map[g_camera_cntx.setting.iso];
    camera_setting_data.night = g_camera_cntx.setting.night;
    camera_setting_data.dsc_mode = camera_dsc_mode_command_map[g_camera_cntx.setting.dsc_mode];
    
    /* effect */
    camera_setting_data.effect = camera_effect_command_map[g_camera_cntx.setting.effect];
    camera_setting_data.brightness = 128;
    camera_setting_data.saturation = 128;
    camera_setting_data.contrast = 128;
    camera_setting_data.hue = 0;
    camera_setting_data.xenon_flash_status_callback = NULL;
    
#ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_1__
    if (g_camera_cntx.setting.effect == CAMERA_SETTING_EFFECT_CUSTOM_FX_1)
    {
        camera_setting_data.effect = camera_effect_command_map[CAMERA_SETTING_EFFECT_NORMAL];
        camera_setting_data.brightness = g_camera_cntx.setting.fx_brightness[0];
        camera_setting_data.saturation = g_camera_cntx.setting.fx_saturation[0];
        camera_setting_data.contrast = g_camera_cntx.setting.fx_contrast[0];
        camera_setting_data.hue = g_camera_cntx.setting.fx_hue[0];
    }
#endif /* __CAMERA_FEATURE_EFFECT_CUSTOM_FX_1__ */ 
    
#ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_2__
    if (g_camera_cntx.setting.effect == CAMERA_SETTING_EFFECT_CUSTOM_FX_2)
    {
        camera_setting_data.effect = camera_effect_command_map[CAMERA_SETTING_EFFECT_NORMAL];
        camera_setting_data.brightness = g_camera_cntx.setting.fx_brightness[1];
        camera_setting_data.saturation = g_camera_cntx.setting.fx_saturation[1];
        camera_setting_data.contrast = g_camera_cntx.setting.fx_contrast[1];
        camera_setting_data.hue = g_camera_cntx.setting.fx_hue[1];
    }
#endif /* __CAMERA_FEATURE_EFFECT_CUSTOM_FX_2__ */ 
    
#ifdef __CAMERA_FEATURE_EFFECT_CUSTOM_FX_3__
    if (g_camera_cntx.setting.effect == CAMERA_SETTING_EFFECT_CUSTOM_FX_3)
    {
        camera_setting_data.effect = camera_effect_command_map[CAMERA_SETTING_EFFECT_NORMAL];
        camera_setting_data.brightness = g_camera_cntx.setting.fx_brightness[2];
        camera_setting_data.saturation = g_camera_cntx.setting.fx_saturation[2];
        camera_setting_data.contrast = g_camera_cntx.setting.fx_contrast[2];
        camera_setting_data.hue = g_camera_cntx.setting.fx_hue[2];
    }
#endif /* __CAMERA_FEATURE_EFFECT_CUSTOM_FX_3__ */ /* __CAMERA_FEATURE_EFFECT_CUSTOM_FX_32__ */
    
    /* preview size is sublcd size */
    camera_setting_data.preview_width = CAMERA_FEATURE_SUBLCD_PREVIEW_SIZE_WIDTH;
    camera_setting_data.preview_height = CAMERA_FEATURE_SUBLCD_PREVIEW_SIZE_HEIGHT;
    
    /* capture parameters */
    camera_setting_data.image_qty = camera_image_qty_command_map[g_camera_cntx.setting.image_qty];
    camera_setting_data.image_width = g_camera_cntx.image_width;
    camera_setting_data.image_height = g_camera_cntx.image_height;
    
    /* preview on sublcd */
    camera_setting_data.lcm = MDI_CAMERA_PREVIEW_LCM_SUBLCD;
    
#ifdef __CAMERA_AUTOFOCUS__
    g_camera_cntx.af_zone0_x = camera_setting_data.af_zone0_x = CAMERA_FEATURE_SUBLCD_PREVIEW_SIZE_WIDTH/2;
    g_camera_cntx.af_zone0_y = camera_setting_data.af_zone0_y = CAMERA_FEATURE_SUBLCD_PREVIEW_SIZE_HEIGHT/2;
    g_camera_cntx.af_zone1_x = camera_setting_data.af_zone1_x = 0;
    g_camera_cntx.af_zone1_y = camera_setting_data.af_zone1_y = 0;
    g_camera_cntx.af_zone2_x = camera_setting_data.af_zone2_x = 0;
    g_camera_cntx.af_zone2_y = camera_setting_data.af_zone2_y = 0;
    g_camera_cntx.af_zone3_x = camera_setting_data.af_zone3_x = 0;
    g_camera_cntx.af_zone3_y = camera_setting_data.af_zone3_y = 0;
    g_camera_cntx.af_zone4_x = camera_setting_data.af_zone4_x = 0;
    g_camera_cntx.af_zone4_y = camera_setting_data.af_zone4_y = 0;
#endif /* __CAMERA_AUTOFOCUS__ */ 
    
    
    if (g_camera_cntx.is_clam_close == TRUE)
    {
        camera_setting_data.preview_rotate = CAMERA_PREVIEW_SUBLCD_CLAM_CLOSE_ROTATE;
        camera_setting_data.lcm_rotate = CAMERA_LCM_SUBLCD_CLAM_CLOSE_ROTATE;
    }
    else
    {
        camera_setting_data.preview_rotate = CAMERA_PREVIEW_SUBLCD_CLAM_OPEN_ROTATE;
        camera_setting_data.lcm_rotate = CAMERA_LCM_SUBLCD_CLAM_OPEN_ROTATE;
    }
    
    camera_setting_data.continue_capture = g_camera_cntx.is_continue_capture;
    
    camera_setting_data.osd_rotate = CAMERA_DISPLAY_ROTATE_0;
    /* set sublcd's layer info to lcd driver by calling gdi_layer_set_blt_layer() */
    /* set layer for preview */
    mmi_camera_sublcd_preview_set_blt_layer(TRUE);  /* TRUE == Preview */
    
    /* turn on led highlight */
    mmi_camera_turn_on_preview_led_highlight();
    
    camera_preview_data.preview_layer_handle = g_camera_cntx.sublcd_base_layer_handle;
    camera_preview_data.preview_wnd_offset_x = 0;
    camera_preview_data.preview_wnd_offset_y = 0;
    camera_preview_data.preview_wnd_width = sublcd_width;
    camera_preview_data.preview_wnd_height = sublcd_height;
    camera_preview_data.blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0;
    camera_preview_data.preview_layer_flag = GDI_LAYER_ENABLE_LAYER_0;
    camera_preview_data.is_lcd_update = TRUE;
    camera_preview_data.src_key_color = CAMEAR_BG_TRASN_COLOR;/* this value is use only CAMERA_MODULE_WITH_LCD */
    camera_preview_data.is_tvout = FALSE;
    
    /* start preview */
    g_camera_cntx.last_error = mdi_camera_preview_start(
        &camera_preview_data,
        &camera_setting_data);
    
}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_sublcd_preview_stop
* DESCRIPTION
*  stop previewing on sublcd
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_sublcd_preview_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_camera_preview_stop();
    
    /* restore black background */
#ifdef CAMERA_MODULE_WITH_LCD
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
#endif /* CAMERA_MODULE_WITH_LCD */ 
}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_sublcd_preview_set_blt_layer
* DESCRIPTION
*  set blt layer based on current status
* PARAMETERS
*  is_previewing       [IN]        Is preview flag
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_sublcd_preview_set_blt_layer(BOOL is_previewing)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* currently no function, reserve it when sublcd will use multi-layer */
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_layer_set_blt_layer(g_camera_cntx.sublcd_base_layer_handle, 0, 0, 0);
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_sublcd_preview_lsk_press
* DESCRIPTION
*  stop sublcd preview then mimic softkey press.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_sublcd_preview_lsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* this function will stop sublcd preview when soft key is down */
    /* if not stop sublcd preview first, mainlcd will draw softkey down and cause driver assert */
    
    if ((g_camera_cntx.app_state == CAMERA_STATE_SUB_PREVIEW) ||
        (g_camera_cntx.app_state == CAMERA_STATE_SUB_CONTSHOT) ||
        (g_camera_cntx.app_state == CAMERA_STATE_SUB_COUNTDOWN))
    {
        mmi_camera_sublcd_preview_stop();
        gui_cancel_timer(mmi_camera_sublcd_contshot_cyclic);
        gui_cancel_timer(mmi_camera_sublcd_countdown_cyclic);
    }
    
}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_sublcd_preview_rsk_press
* DESCRIPTION
*  stop sublcd preview then mimic softkey press.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_sublcd_preview_rsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* this function will stop sublcd preview when soft key is down */
    /* if not stop sublcd preview first, mainlcd will draw softkey down and cause driver assert */
    /* if is preview on sub and RSK pressm, has to stop preview first then darw on Main */
    
    if ((g_camera_cntx.app_state == CAMERA_STATE_SUB_PREVIEW) ||
        (g_camera_cntx.app_state == CAMERA_STATE_SUB_CONTSHOT) ||
        (g_camera_cntx.app_state == CAMERA_STATE_SUB_COUNTDOWN))
    {
        mmi_camera_sublcd_preview_stop();
        gui_cancel_timer(mmi_camera_sublcd_contshot_cyclic);
        gui_cancel_timer(mmi_camera_sublcd_countdown_cyclic);
    }
}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_sublcd_preview_lsk_release
* DESCRIPTION
*  stop sublcd preview then mimic softkey press.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_sublcd_preview_lsk_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camera_entry_option_menu_screen();
}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_sublcd_preview_rsk_release
* DESCRIPTION
*  stop sublcd preview then mimic softkey press.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_sublcd_preview_rsk_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackHistory();
}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 

/*****************************************************************************
*
*  Sublcd Countdown State
*
*****************************************************************************/


/*****************************************************************************
* FUNCTION
*  mmi_camera_entry_sublcd_countdown_state
* DESCRIPTION
*  entry count down state
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_entry_sublcd_countdown_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* register soft keys */
    ClearInputEventHandler(MMI_DEVICE_KEY);
    
    SetKeyHandler(mmi_camera_sublcd_preview_lsk_release, KEY_LSK, KEY_EVENT_UP);
    SetKeyHandler(mmi_camera_sublcd_preview_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
    
    SetKeyHandler(mmi_camera_sublcd_preview_rsk_release, KEY_RSK, KEY_EVENT_UP);
    SetKeyHandler(mmi_camera_sublcd_preview_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
    
    /* clearn center key - since if not clear, this key will mappign to LSK */
    if (CAMERA_CAPTURE_KEY != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, CAMERA_CAPTURE_KEY, KEY_EVENT_DOWN);
    }
    
    if (CAMERA_CAPTURE_EXTRA_KEY1 != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY1, KEY_EVENT_DOWN);
    }
    
    if (CAMERA_CAPTURE_EXTRA_KEY2 != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_LONG_PRESS);
    }
    
    /* init countdown para */
    switch (g_camera_cntx.setting.delay_timer)
    {
    case CAMERA_SETTING_DELAY_TIMER_1:
        {
            g_camera_cntx.capture_countdown = CAMERA_FEATURE_DELAY_TIMER_1_DURATION * 1000;
        }
        break;
        
    case CAMERA_SETTING_DELAY_TIMER_2:
        {
            g_camera_cntx.capture_countdown = CAMERA_FEATURE_DELAY_TIMER_2_DURATION * 1000;
        }
        break;
        
    case CAMERA_SETTING_DELAY_TIMER_3:
        {
            g_camera_cntx.capture_countdown = CAMERA_FEATURE_DELAY_TIMER_3_DURATION * 1000;
        }
        break;
        
    default:
        /* restore default value */
        mmi_camera_restore_setting();
        break;
    }
    
#ifdef __COUNTDOWN_USING_MMA__
    mmi_camera_init_countdown_mma();
#endif
    
    /* start count down */
    mmi_camera_sublcd_countdown_cyclic();
    
}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_exit_sublcd_countdown_state
* DESCRIPTION
*  entry count down state
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_exit_sublcd_countdown_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop countdown timer */
    gui_cancel_timer(mmi_camera_sublcd_countdown_stop_LED);
    mmi_camera_sublcd_countdown_stop_LED();
    gui_cancel_timer(mmi_camera_sublcd_countdown_cyclic);
#ifdef __COUNTDOWN_USING_MMA__
    gui_cancel_timer(mmi_camera_capture);
    gui_cancel_timer(mmi_camera_deinit_countdown_mma);
#endif
    
    /* free preview resource */
    if (g_camera_cntx.app_next_state == CAMERA_STATE_EXIT)
    {
#ifdef __COUNTDOWN_USING_MMA__
        if (g_camera_cntx.multi_sound_countdown != 0 && g_camera_cntx.multi_sound_dummy_bg != 0)
        {
            mmi_camera_deinit_countdown_mma();
        }
#endif
        
        /* stop previewing */
        mmi_camera_sublcd_preview_stop();
        
        /* turn off led highlight */
        mmi_camera_turn_off_led_highlight();
        
        /* 
        * when interrupt happened while clam is close (preview on sub)
        * we will go handling interrupt, when back from interrupt, 
        * we shall force enter sub again to keep clam open close state correct 
        */
        if (g_camera_cntx.is_clam_close)
        {
            g_camera_cntx.is_force_self_capture = TRUE;
        }
    }
    
}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_sublcd_countdown_cyclic
* DESCRIPTION
*  count down delay timer cyclic loop
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_sublcd_countdown_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* countdonw duration and freq */
    if (g_camera_cntx.capture_countdown > 6000)
    {
        if (g_camera_cntx.setting.led_highlight == CAMERA_SETTING_LED_HIGHLIGHT_OFF)
        {
            SetGPIOLevelReq(GPIO_DEV_LED_STATUS_1, LED_LIGHT_LEVEL5);
        }
        
        gui_start_timer(100, mmi_camera_sublcd_countdown_stop_LED);
        gui_start_timer(1000, mmi_camera_sublcd_countdown_cyclic);
        g_camera_cntx.capture_countdown -= 1000;
        
        if (!MMI_CAMERA_IS_SILENT_MODE())
        {
#ifdef __COUNTDOWN_USING_MMA__
            mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER_BOTH);
            mdi_audio_set_volume(VOL_TYPE_MEDIA,CAMERA_SHUTTER_SOUND_VOLUMN);
            mdi_audio_mma_stop_wav(g_camera_cntx.multi_sound_countdown);
            mdi_audio_mma_play_wav(g_camera_cntx.multi_sound_countdown);
#else
            mdi_audio_play_string_with_vol_path((void*)camera_sound_countdown, (U32) CAMREA_SOUND_COUNTDOWN_LEN,
                MDI_FORMAT_DVI_ADPCM,
                DEVICE_AUDIO_PLAY_ONCE,
                NULL, NULL, CAMERA_SHUTTER_SOUND_VOLUMN, MDI_DEVICE_SPEAKER_BOTH);
#endif
        }
    }
    else if (g_camera_cntx.capture_countdown > 2000)
    {
        if (g_camera_cntx.setting.led_highlight == CAMERA_SETTING_LED_HIGHLIGHT_OFF)
        {
            SetGPIOLevelReq(GPIO_DEV_LED_STATUS_1, LED_LIGHT_LEVEL5);
        }
        
        gui_start_timer(100, mmi_camera_sublcd_countdown_stop_LED);
        gui_start_timer(500, mmi_camera_sublcd_countdown_cyclic);
        g_camera_cntx.capture_countdown -= 500;
        
        if (!MMI_CAMERA_IS_SILENT_MODE())
        {
#ifdef __COUNTDOWN_USING_MMA__
            mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER_BOTH);
            mdi_audio_set_volume(VOL_TYPE_MEDIA,CAMERA_SHUTTER_SOUND_VOLUMN);
            mdi_audio_mma_stop_wav(g_camera_cntx.multi_sound_countdown);
            mdi_audio_mma_play_wav(g_camera_cntx.multi_sound_countdown);
#else
            mdi_audio_play_string_with_vol_path((void*)camera_sound_countdown, (U32) CAMREA_SOUND_COUNTDOWN_LEN,
                MDI_FORMAT_DVI_ADPCM,
                DEVICE_AUDIO_PLAY_ONCE,
                NULL, NULL, CAMERA_SHUTTER_SOUND_VOLUMN, MDI_DEVICE_SPEAKER_BOTH);
#endif
        }
    }
    else if (g_camera_cntx.capture_countdown >= 0)
    {
        if (g_camera_cntx.setting.led_highlight == CAMERA_SETTING_LED_HIGHLIGHT_OFF)
        {
            SetGPIOLevelReq(GPIO_DEV_LED_STATUS_1, LED_LIGHT_LEVEL5);
        }
        
        gui_start_timer(100, mmi_camera_sublcd_countdown_stop_LED);
        gui_start_timer(200, mmi_camera_sublcd_countdown_cyclic);
        g_camera_cntx.capture_countdown -= 200;
        
        if (!MMI_CAMERA_IS_SILENT_MODE())
        {
#ifdef __COUNTDOWN_USING_MMA__
            mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER_BOTH);
            mdi_audio_set_volume(VOL_TYPE_MEDIA,CAMERA_SHUTTER_SOUND_VOLUMN);
            mdi_audio_mma_stop_wav(g_camera_cntx.multi_sound_countdown);
            mdi_audio_mma_play_wav(g_camera_cntx.multi_sound_countdown);
#else
            mdi_audio_play_string_with_vol_path((void*)camera_sound_countdown, (U32) CAMREA_SOUND_COUNTDOWN_LEN,
                MDI_FORMAT_DVI_ADPCM,
                DEVICE_AUDIO_PLAY_ONCE,
                NULL, NULL, CAMERA_SHUTTER_SOUND_VOLUMN, MDI_DEVICE_SPEAKER_BOTH);
#endif
        }
        
    }
    else
    {
#ifdef __COUNTDOWN_USING_MMA__
        gui_start_timer(200, mmi_camera_deinit_countdown_mma);
        gui_start_timer(300, mmi_camera_sublcd_capture);
#else
        mmi_camera_sublcd_capture();
#endif
        return;
    }
}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_sublcd_countdown_stop_LED
* DESCRIPTION
*  stop count down LED
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_sublcd_countdown_stop_LED(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_camera_cntx.setting.led_highlight == CAMERA_SETTING_LED_HIGHLIGHT_OFF)
    {
        SetGPIOLevelReq(GPIO_DEV_LED_STATUS_1, LED_LIGHT_LEVEL0);
    }
}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 

/*****************************************************************************
*
*  Sublcd Cont Shot State
*
*****************************************************************************/


/*****************************************************************************
* FUNCTION
*  mmi_camera_entry_sublcd_contshot_state
* DESCRIPTION
*  entry contshot state
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_entry_sublcd_contshot_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* register soft keys */
    ClearInputEventHandler(MMI_DEVICE_KEY);
    
    SetKeyHandler(mmi_camera_sublcd_preview_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_sublcd_preview_lsk_release, KEY_LSK, KEY_EVENT_UP);
    
    SetKeyHandler(mmi_camera_sublcd_preview_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_sublcd_preview_rsk_release, KEY_RSK, KEY_EVENT_UP);
    
    /* clearn center key - since if not clear, this key will mappign to LSK */
    if (CAMERA_CAPTURE_KEY != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, CAMERA_CAPTURE_KEY, KEY_EVENT_DOWN);
    }
    
    if (CAMERA_CAPTURE_EXTRA_KEY1 != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY1, KEY_EVENT_DOWN);
    }
    
    if (CAMERA_CAPTURE_EXTRA_KEY2 != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_LONG_PRESS);
    }
    
    /* init count down para */
    switch (g_camera_cntx.setting.cont_shot)
    {
    case CAMERA_SETTING_CONT_SHOT_OFF:
        {
            g_camera_cntx.cont_shot_total_count = 1;
            g_camera_cntx.cont_shot_count = 0;
        }
        break;
        
    case CAMERA_SETTING_CONT_SHOT_1:
        {
            g_camera_cntx.cont_shot_total_count = CAMERA_FEATURE_CONT_SHOT_1_COUNT;
            g_camera_cntx.cont_shot_count = 0;
        }
        break;
        
#ifdef __CAMERA_FEATURE_CONT_SHOT_2__
    case CAMERA_SETTING_CONT_SHOT_2:
        {
            g_camera_cntx.cont_shot_total_count = CAMERA_FEATURE_CONT_SHOT_2_COUNT;
            g_camera_cntx.cont_shot_count = 0;
        }
        break;
#endif /* __CAMERA_FEATURE_CONT_SHOT_2__ */ 
#ifdef __CAMERA_FEATURE_CONT_SHOT_3__
    case CAMERA_SETTING_CONT_SHOT_3:
        {
            g_camera_cntx.cont_shot_total_count = CAMERA_FEATURE_CONT_SHOT_3_COUNT;
            g_camera_cntx.cont_shot_count = 0;
        }
        break;
#endif /* __CAMERA_FEATURE_CONT_SHOT_3__ */ 
    }
    
    mmi_camera_sublcd_contshot_cyclic();
    
}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_exit_sublcd_contshot_state
* DESCRIPTION
*  entry contshot state
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_exit_sublcd_contshot_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* cancel contshot timer */
    gui_cancel_timer(mmi_camera_sublcd_contshot_cyclic);
    
    /* free preview resource */
    if (g_camera_cntx.app_next_state == CAMERA_STATE_EXIT)
    {
        /* stop previewing */
        mmi_camera_sublcd_preview_stop();
        
        /* turn off led highlight */
        mmi_camera_turn_off_led_highlight();
        
        /* 
        * when interrupt happened while clam is close (preview on sub)
        * we will go handling interrupt, when back from interrupt, 
        * we shall force enter sub again to keep clam open close state correct 
        */
        
        if (g_camera_cntx.is_clam_close)
        {
            g_camera_cntx.is_force_self_capture = TRUE;
        }
    }
    
}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_sublcd_contshot_cyclic
* DESCRIPTION
*  cont shot cyclic loop
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_sublcd_contshot_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filename[FMGR_PATH_BUFFER_SIZE];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* this function has nvram access */
    //mmi_camera_get_next_filename(buf_filename);
    mmi_camera_commit_filename_seq_no();
    
    /* start timer for next shot */
    gui_start_timer(100, mmi_camera_sublcd_contshot_cyclic);
    
    mmi_camera_turn_on_capture_led_highlight();
    
    if (g_camera_cntx.cont_shot_count + 1 == g_camera_cntx.cont_shot_total_count)
    {
        g_camera_cntx.is_continue_capture = FALSE;
    }
    else
    {
        g_camera_cntx.is_continue_capture = TRUE;
    }
    
    g_camera_cntx.last_error = mdi_camera_capture_to_file(buf_filename, g_camera_cntx.is_continue_capture);
    
    /* play capture sound after capture */
    mmi_camera_capture_play_sound();
    
    /* restore black background */
#ifdef CAMERA_MODULE_WITH_LCD
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
#endif /* CAMERA_MODULE_WITH_LCD */ 
    
    mmi_camera_turn_off_led_highlight();
    
    /* captured, previwing is stopped, change blt layer */
    mmi_camera_sublcd_preview_set_blt_layer(FALSE);
    
    if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
    {
        g_camera_cntx.is_continue_capture = FALSE;
        gui_cancel_timer(mmi_camera_sublcd_contshot_cyclic);
        FS_Delete((U16*) buf_filename);
        mmi_camera_restore_filename_seq_no();
        mmi_camera_display_sublcd_error_popup();
        return;
    }
    
    g_camera_cntx.cont_shot_count++;
    
    /* terminate condition */
    if (g_camera_cntx.cont_shot_count >= g_camera_cntx.cont_shot_total_count)
    {
        /* stop timer */
        gui_cancel_timer(mmi_camera_sublcd_contshot_cyclic);
        CAMERA_ENTER_STATE(CAMERA_STATE_SUB_PREVIEW);
        return;
    }
    else
    {
        /* change blt layer for previwing */
        mmi_camera_sublcd_preview_set_blt_layer(TRUE);
        
        /* config rotate of preview layer, only ISP_SUPPORT need */
#if defined(ISP_SUPPORT)
        gdi_layer_push_and_set_active(g_camera_cntx.sublcd_base_layer_handle);
        
        if (g_camera_cntx.is_clam_close == TRUE)
        {
            gdi_layer_set_rotate(CAMERA_LCM_SUBLCD_CLAM_CLOSE_ROTATE);
        }
        else
        {
            gdi_layer_set_rotate(CAMERA_LCM_SUBLCD_CLAM_OPEN_ROTATE);
        }
        
        gdi_layer_pop_and_restore_active();
#endif /* defined(ISP_SUPPORT) */ 
        
        mmi_camera_sublcd_preview_start();
        
        if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
        {
            g_camera_cntx.is_continue_capture = FALSE;
            /* stop timer */
            gui_cancel_timer(mmi_camera_sublcd_contshot_cyclic);
            mmi_camera_display_sublcd_error_popup();
            return;
        }
    }
    
}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 

/*****************************************************************************
*
*  Sublcd Capture Burst State
*
*****************************************************************************/


/*****************************************************************************
* FUNCTION
*  mmi_camera_entry_sublcd_burstshot_state
* DESCRIPTION
*  entry contshot state
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#if defined(__CAMERA_FEATURE_SELF_CAPTURE__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST__)
static void mmi_camera_entry_sublcd_burstshot_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* register softkeys */
    ClearInputEventHandler(MMI_DEVICE_KEY);
    
    SetKeyHandler(mmi_camera_sublcd_preview_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_sublcd_preview_lsk_release, KEY_LSK, KEY_EVENT_UP);
    
    SetKeyHandler(mmi_camera_sublcd_preview_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_sublcd_preview_rsk_release, KEY_RSK, KEY_EVENT_UP);
    
    /* clearn center key - since if not clear, this key will mappign to LSK */
    if (CAMERA_CAPTURE_KEY != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, CAMERA_CAPTURE_KEY, KEY_EVENT_DOWN);
    }
    
    if (CAMERA_CAPTURE_EXTRA_KEY1 != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY1, KEY_EVENT_DOWN);
    }
    
    if (CAMERA_CAPTURE_EXTRA_KEY2 != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_LONG_PRESS);
    }
    
    mmi_camera_turn_on_capture_led_highlight();
    
    g_camera_cntx.is_capturing = TRUE;
    
#if defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__)
    
    if (!MMI_CAMERA_IS_SILENT_MODE() && g_camera_cntx.setting.shutter_sound != CAMERA_SETTING_SHUTTER_SOUND_OFF)
    {
        /* start multi_channel sound, for capture sound effect */
        
        /* open and play a dummy midi at backgroup - this is a must do to play multi-channel sound */
        g_camera_cntx.multi_sound_dummy_bg = mdi_audio_mma_open_midi((void*)camera_sound_dummy_bg, CAMERA_SOUND_DUMMY_BG_LEN, 0, NULL);
        
        mdi_audio_mma_play_midi(g_camera_cntx.multi_sound_dummy_bg);
        
        g_camera_cntx.multi_sound_cap_idx = 0;
        
        switch (g_camera_cntx.setting.shutter_sound)
        {
        case CAMERA_SETTING_SHUTTER_SOUND_1:
            {
                g_camera_cntx.multi_sound_capture0 = mdi_audio_mma_open_wav((void*)camera_sound_shutter_1, (U32) CAMERA_SOUND_SHUTTER_1_LEN, 1, NULL);
                
                g_camera_cntx.multi_sound_capture1 = mdi_audio_mma_open_wav((void*)camera_sound_shutter_1, (U32) CAMERA_SOUND_SHUTTER_1_LEN, 1, NULL);
                
                g_camera_cntx.multi_sound_capture2 = mdi_audio_mma_open_wav((void*)camera_sound_shutter_1, (U32) CAMERA_SOUND_SHUTTER_1_LEN, 1, NULL);
            }
            
            break;
            
        case CAMERA_SETTING_SHUTTER_SOUND_2:
            {
                g_camera_cntx.multi_sound_capture0 = mdi_audio_mma_open_wav((void*)camera_sound_shutter_2, (U32) CAMERA_SOUND_SHUTTER_2_LEN, 1, NULL);
                
                g_camera_cntx.multi_sound_capture1 = mdi_audio_mma_open_wav((void*)camera_sound_shutter_2, (U32) CAMERA_SOUND_SHUTTER_2_LEN, 1, NULL);
                
                g_camera_cntx.multi_sound_capture2 = mdi_audio_mma_open_wav((void*)camera_sound_shutter_2, (U32) CAMERA_SOUND_SHUTTER_2_LEN, 1, NULL);
            }
            break;
            
        case CAMERA_SETTING_SHUTTER_SOUND_3:
            {
                g_camera_cntx.multi_sound_capture0 = mdi_audio_mma_open_wav((void*)camera_sound_shutter_3, (U32) CAMERA_SOUND_SHUTTER_3_LEN, 1, NULL);
                
                g_camera_cntx.multi_sound_capture1 = mdi_audio_mma_open_wav((void*)camera_sound_shutter_3, (U32) CAMERA_SOUND_SHUTTER_3_LEN, 1, NULL);
                
                g_camera_cntx.multi_sound_capture2 = mdi_audio_mma_open_wav((void*)camera_sound_shutter_3, (U32) CAMERA_SOUND_SHUTTER_3_LEN, 1, NULL);
            }
            break;
        }
    }
    
    /* MT6228 support non-blocking burst shot */
    /* call mdi to capture and save */
    g_camera_cntx.last_error
        = mdi_camera_non_block_burst_capture_to_memory(
        CAMERA_FEATURE_CONT_SHOT_BURST_COUNT,
        &g_camera_cntx.burst_jpg_data,
        mmi_camera_sublcd_burstshot_capture_result_hdlr);
    
#else /* defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__) */ 
    /* burst shot shall play before capture */
    mmi_camera_capture_play_sound();
    
    /* call mdi to capture and save */
    g_camera_cntx.last_error
        = mdi_camera_burst_capture_to_memory(CAMERA_FEATURE_CONT_SHOT_BURST_COUNT, &g_camera_cntx.burst_jpg_data);
    
    /* restore black background */
#ifdef CAMERA_MODULE_WITH_LCD
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
#endif /* CAMERA_MODULE_WITH_LCD */ 
    
    /* stop led */
    mmi_camera_turn_off_led_highlight();
    
    if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
    {
        playRequestedTone(ERROR_TONE);
        CAMERA_ENTER_STATE(CAMERA_STATE_SUB_PREVIEW);
    }
    else
    {
        CAMERA_ENTER_STATE(CAMERA_STATE_SUB_BURSTSHOT_SAVING);
    }
    
#endif /* defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__) */ 
    
}
#endif /* defined(__CAMERA_FEATURE_SELF_CAPTURE__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST__) */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_exit_sublcd_burstshot_state
* DESCRIPTION
*  entry contshot state
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#if defined(__CAMERA_FEATURE_SELF_CAPTURE__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST__)
static void mmi_camera_exit_sublcd_burstshot_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop dummy bg midi for multi-channel sound */
#if defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__)
    
    if (g_camera_cntx.is_capturing)
    {
        mdi_camera_stop_non_block_burst_capture();
    }
    
    if (!MMI_CAMERA_IS_SILENT_MODE() && g_camera_cntx.setting.shutter_sound != CAMERA_SETTING_SHUTTER_SOUND_OFF)
    {
        mdi_audio_mma_stop_midi(g_camera_cntx.multi_sound_dummy_bg);
        mdi_audio_mma_close_midi(g_camera_cntx.multi_sound_dummy_bg);
        
        mdi_audio_mma_stop_wav(g_camera_cntx.multi_sound_capture0);
        mdi_audio_mma_close_wav(g_camera_cntx.multi_sound_capture0);
        
        mdi_audio_mma_stop_wav(g_camera_cntx.multi_sound_capture1);
        mdi_audio_mma_close_wav(g_camera_cntx.multi_sound_capture1);
        
        mdi_audio_mma_stop_wav(g_camera_cntx.multi_sound_capture2);
        mdi_audio_mma_close_wav(g_camera_cntx.multi_sound_capture2);
        
        g_camera_cntx.multi_sound_capture0 = 0;
        g_camera_cntx.multi_sound_capture1 = 0;
        g_camera_cntx.multi_sound_capture2 = 0;
        g_camera_cntx.multi_sound_dummy_bg = 0;
    }
    
#endif /* defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__) */ 
    
    if (g_camera_cntx.app_next_state == CAMERA_STATE_EXIT)
    {
        /* turn off led highlight */
        mmi_camera_turn_off_led_highlight();
    }
    
    if (g_camera_cntx.app_next_state == CAMERA_STATE_EXIT)
    {
    /* 
    * when interrupt happened while clam is close (preview on sub)
    * we will go handling interrupt, when back from interrupt, 
    * we shall force enter sub again to keep clam open close state correct 
        */
        
        if (g_camera_cntx.is_clam_close)
        {
            g_camera_cntx.is_force_self_capture = TRUE;
        }
    }
    
}
#endif /* defined(__CAMERA_FEATURE_SELF_CAPTURE__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST__) */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_sublcd_burstshot_capture_result_hdlr
* DESCRIPTION
*  no block burst shot capture result handler
* PARAMETERS
*  ret                 [IN]        
*  captured_count      [IN]        
* RETURNS
*  void
*****************************************************************************/
#if defined(__CAMERA_FEATURE_SELF_CAPTURE__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__)
static void mmi_camera_sublcd_burstshot_capture_result_hdlr(MDI_RESULT ret, U16 captured_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if camera is in EXIT state by interrup, just do nothing */
    if (g_camera_cntx.app_state == CAMERA_STATE_EXIT)
    {
        return;
    }
    
    /* capture count start from 1 */
    mmi_camera_capture_play_multi_channel_sound();
    
    if (ret >= 0)
    {
        /* no error happened */
        if (captured_count == CAMERA_FEATURE_CONT_SHOT_BURST_COUNT)
        {
            g_camera_cntx.is_capturing = FALSE;
            CAMERA_ENTER_STATE(CAMERA_STATE_SUB_BURSTSHOT_SAVING);
            return;
        }
    }
    else
    {
        g_camera_cntx.is_capturing = FALSE;
        playRequestedTone(ERROR_TONE);
        CAMERA_ENTER_STATE(CAMERA_STATE_SUB_PREVIEW);
    }
}
#endif /* defined(__CAMERA_FEATURE_SELF_CAPTURE__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__) */ /* __CAMERA_FEATURE_SELF_CAPTURE__ & __CAMERA_FEATURE_CONT_SHOT_BURST__ & __CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__ */

/*****************************************************************************
*
*  Sublcd Save Burstshot State
*
*****************************************************************************/


/*****************************************************************************
* FUNCTION
*  mmi_camera_entry_sublcd_burstshot_saving_state
* DESCRIPTION
*  entry sublcd save burstshot state
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#if defined(__CAMERA_FEATURE_SELF_CAPTURE__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST__)
static void mmi_camera_entry_sublcd_burstshot_saving_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_width;
    S32 str_height;
    PS8 str_ptr;
    S32 lcd_width;
    S32 lcd_height;
    gdi_handle layer_handle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* register softkeys */
    ClearInputEventHandler(MMI_DEVICE_KEY);
    
    SetKeyHandler(mmi_camera_dummy_func, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_dummy_func, KEY_LSK, KEY_EVENT_UP);
    
    SetKeyHandler(mmi_camera_dummy_func, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_dummy_func, KEY_RSK, KEY_EVENT_UP);
    
    /* clearn center key - since if not clear, this key will mappign to LSK */
    if (CAMERA_CAPTURE_KEY != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, CAMERA_CAPTURE_KEY, KEY_EVENT_DOWN);
    }
    
    if (CAMERA_CAPTURE_EXTRA_KEY1 != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY1, KEY_EVENT_DOWN);
    }
    
    if (CAMERA_CAPTURE_EXTRA_KEY2 != -1)
    {
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_EVENT_REPEAT);
        SetKeyHandler(mmi_camera_dummy_func, (U16)CAMERA_CAPTURE_EXTRA_KEY2, KEY_LONG_PRESS);
    }
    
    /* drwa saving string */
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_layer_reset_text_clip();
    
    gdi_lcd_get_dimension(&lcd_width, &lcd_height);
    gdi_layer_get_active(&layer_handle);
    
    str_ptr = (PS8) GetString(STR_ID_CAMERA_NOTIFY_SAVING);
    
    gui_measure_string((UI_string_type) str_ptr, &str_width, &str_height);
    
    mmi_camera_draw_style_text(
        str_ptr,
        (lcd_width - str_width) >> 1,
        (lcd_height - str_height) >> 1,
        0,
        &g_camera_cntx.active_camera_osd_ptr->hint_box.style_text);
    
    gdi_layer_blt(layer_handle, 0, 0, 0, 0, 0, lcd_width - 1, lcd_height - 1);
    
    /* restore to main */
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
    
    /* start save burst shot */
    g_camera_cntx.burst_save_index = 0;
    mmi_camera_sublcd_burstshot_saving_cyclic();
}
#endif /* defined(__CAMERA_FEATURE_SELF_CAPTURE__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST__) */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_exit_sublcd_burstshot_saving_state
* DESCRIPTION
*  exit sublcd save burstshot state
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#if defined(__CAMERA_FEATURE_SELF_CAPTURE__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST__)
static void mmi_camera_exit_sublcd_burstshot_saving_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_camera_sublcd_burstshot_saving_cyclic);
    gdi_image_stop_animation_all();
    
    if (g_camera_cntx.app_next_state == CAMERA_STATE_EXIT)
    {
    /* 
    * when interrupt happened while clam is close (preview on sub)
    * we will go handling interrupt, when back from interrupt, 
    * we shall force enter sub again to keep clam open close state correct 
        */
        
        if (g_camera_cntx.is_clam_close)
        {
            g_camera_cntx.is_force_self_capture = TRUE;
        }
    }
    
}
#endif /* defined(__CAMERA_FEATURE_SELF_CAPTURE__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST__) */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_sublcd_burstshot_saving_cyclic
* DESCRIPTION
*  loop to save sublcd burstshot image
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#if defined(__CAMERA_FEATURE_SELF_CAPTURE__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST__)
static void mmi_camera_sublcd_burstshot_saving_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filename[FMGR_PATH_BUFFER_SIZE];
    PU8 image_buf_ptr;
    U32 image_buf_size;
    U32 written;
    FS_HANDLE file_handle;
    
#ifdef EXIF_SUPPORT
    U32 size_of_exif_info = 0;
#endif 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* this function has nvram access */
    mmi_camera_get_next_filename(buf_filename);
    
    mmi_camera_commit_filename_seq_no();
    /* start timer for next shot */
    gui_start_timer(100, mmi_camera_sublcd_burstshot_saving_cyclic);
    
    /* save burst shot image */
    image_buf_ptr = (PU8) g_camera_cntx.burst_jpg_data.file_address[g_camera_cntx.burst_save_index];
    image_buf_size = (U32) g_camera_cntx.burst_jpg_data.file_size[g_camera_cntx.burst_save_index];
    
    file_handle = FS_Open((U16*) buf_filename, FS_CREATE | FS_READ_WRITE);
    
    if (file_handle > 0)
    {
#ifdef EXIF_SUPPORT
        /* eixf_burst_mode_fill_header(kal_uint8* Buffer,kal_uint32 BufferOffset); */
#if defined(__MTK_TARGET__)
        size_of_exif_info = eixf_burst_mode_fill_header(image_buf_ptr);
#endif 
        image_buf_size += size_of_exif_info;
        image_buf_ptr -= size_of_exif_info;
#endif /* EXIF_SUPPORT */ 
        
        FS_Write(file_handle, (void*)image_buf_ptr, image_buf_size, (U32*) & written);
        FS_Close(file_handle);
        
        /* cant write in whole file, must be disk full */
        if (image_buf_size != written)
        {
            /* delete the file that is not save complete */
            FS_Delete((U16*) buf_filename);
            
            g_camera_cntx.last_error = MDI_RES_CAMERA_ERR_DISK_FULL;
            
            mmi_camera_restore_filename_seq_no();
            /* this is not serious error, will play a notify tone */
            /* it will directly re-entry sub preview state */
            mmi_camera_display_sublcd_error_popup();
            
            return;
        }
    }
    else
    {
        if (file_handle == FS_DISK_FULL)
        {
            g_camera_cntx.last_error = MDI_RES_CAMERA_ERR_DISK_FULL;
        }
        else if (file_handle == FS_ROOT_DIR_FULL)
        {
            g_camera_cntx.last_error = CAMERA_ERR_ROOT_DIR_FULL;
        }
        else if (file_handle == FS_WRITE_PROTECTION)
        {
            g_camera_cntx.last_error = MDI_RES_CAMERA_ERR_WRITE_PROTECTION;
        }
        else
        {
            g_camera_cntx.last_error = CAMERA_ERR_SAVE_FAIL;
        }
        
        mmi_camera_restore_filename_seq_no();
        /* this is not serious error, will play a notify tone */
        /* it will directly re-entry sub preview state */
        mmi_camera_display_sublcd_error_popup();
        return;
    }
    
    /* teminate condition */
    if (g_camera_cntx.burst_save_index >= CAMERA_FEATURE_CONT_SHOT_BURST_COUNT - 1)
    {
        CAMERA_ENTER_STATE(CAMERA_STATE_SUB_PREVIEW);
        return;
    }
    
    /* increase index */
    g_camera_cntx.burst_save_index++;
    
}
#endif /* defined(__CAMERA_FEATURE_SELF_CAPTURE__) && defined(__CAMERA_FEATURE_CONT_SHOT_BURST__) */ 

/***************************************************************************
*
*  Sublcd Capture 
*
***************************************************************************/


/*****************************************************************************
* FUNCTION
*  mmi_camera_sublcd_capture
* DESCRIPTION
*  capture photo
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_sublcd_capture(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CAMERA_DIRECT_COUPLE__
    S32 image_region_width;
    S32 image_region_height;
    S32 image_region_offset_x;
    S32 image_region_offset_y;
    S32 resized_offset_x;
    S32 resized_offset_y;
    S32 resized_width;
    S32 resized_height;    
    U32 buf_size;
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_camera_cntx.setting.cont_shot)
    {
        
    case CAMERA_SETTING_CONT_SHOT_OFF:
        mmi_camera_turn_on_capture_led_highlight();
        
        /* since user may capture when clam close, and open clam to view the captured image */
        /* disable clam open action */
        g_camera_cntx.is_dis_clam_open = TRUE;
        
#ifdef __MMI_CAMERA_DIRECT_COUPLE__
        /* Calculate the image buffer size */
        image_region_width = g_camera_cntx.osd_UI_device_width;
        image_region_height = g_camera_cntx.osd_UI_device_height;
        image_region_offset_x = 0;
        image_region_offset_y = 0;
        
        if (g_camera_cntx.active_camera_osd_ptr->title.is_draw_mmi_title_bar)
        {
            image_region_height -= (MMI_title_height + MMI_title_y);
            image_region_offset_y += (MMI_title_height + MMI_title_y);
        }
        
        if (g_camera_cntx.active_camera_osd_ptr->softkey.is_draw_mmi_softkey)
        {
            image_region_height -= (MMI_button_bar_height);
        }
        
        if ((image_region_width >= g_camera_cntx.image_width) && (image_region_height >= g_camera_cntx.image_height))
        {
            resized_width = g_camera_cntx.image_width;
            resized_height = g_camera_cntx.image_height;
        }
        else
        {
            gdi_image_util_fit_bbox(
                image_region_width,
                image_region_height,
                g_camera_cntx.image_width,
                g_camera_cntx.image_height,
                &resized_offset_x,
                &resized_offset_y,
                &resized_width,
                &resized_height);
            
        }
        
        buf_size = (((resized_width *resized_height*GDI_MAINLCD_BIT_PER_PIXEL)>>3)*2);
        
        ASSERT(g_camera_cntx.direct_couple_buffer!=NULL);
        
        g_camera_cntx.last_error
            = mdi_camera_capture_to_memory_direct_couple(&g_camera_cntx.capture_buf_ptr, 
            &g_camera_cntx.capture_size,
            (U32) g_camera_cntx.direct_couple_buffer, 
            buf_size, 
            resized_width,
            resized_height,
            g_camera_cntx.captured_filepath);
        if ((g_camera_cntx.image_width > g_camera_cntx.preview_width) && 
            (g_camera_cntx.image_height > g_camera_cntx.preview_height))
        {
            g_camera_cntx.is_direct_couple = TRUE;
        }
        else
        {
            g_camera_cntx.is_direct_couple = FALSE;
        }
        
#else
        g_camera_cntx.last_error
            = mdi_camera_capture_to_memory(&g_camera_cntx.capture_buf_ptr, &g_camera_cntx.capture_size, g_camera_cntx.captured_filepath);
        mmi_camera_turn_off_led_highlight();
        if (g_camera_cntx.last_error == MDI_RES_CAMERA_SUCCEED)
        {
            g_camera_cntx.last_error = mdi_camera_save_captured_image();
        }
        if (g_camera_cntx.last_error != MDI_RES_CAMERA_SUCCEED)
        {
            FS_Delete((U16*) g_camera_cntx.captured_filepath);
            mmi_camera_display_error_popup();
            return;
        }
#endif
        
        /* play capture sound after capture */
        mmi_camera_capture_play_sound();
        
        mmi_camera_sublcd_draw_icon();
        
        mmi_camera_turn_off_led_highlight();
        CAMERA_ENTER_STATE(CAMERA_STATE_DELETE_CONFIRM);
        
        break;
        
    case CAMERA_SETTING_CONT_SHOT_1:
        
#ifdef __CAMERA_FEATURE_CONT_SHOT_2__
    case CAMERA_SETTING_CONT_SHOT_2:
#endif 
        
#ifdef __CAMERA_FEATURE_CONT_SHOT_3__
    case CAMERA_SETTING_CONT_SHOT_3:
#endif 
        {
            CAMERA_ENTER_STATE(CAMERA_STATE_SUB_CONTSHOT);
            return;
        }
        break;
        
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
    case CAMERA_SETTING_CONT_SHOT_BURST:
        {
            CAMERA_ENTER_STATE(CAMERA_STATE_SUB_BURSTSHOT);
            return;
        }
        break;
#endif /* __CAMERA_FEATURE_CONT_SHOT_BURST__ */ 
        
    default:
        /* restore default value */
        mmi_camera_restore_setting();
        break;
        
}

}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_sublcd_capture_button_press
* DESCRIPTION
*  capture button presse
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
static void mmi_camera_sublcd_capture_button_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__
    mmi_camera_restart_app_watchdog();
#endif
    /* capture only works is camera is ready, otherwise will ignore this action */
    if (mdi_camera_is_ready_to_capture() == TRUE)
    {
        /* if not self timer, capture the image */
        if (g_camera_cntx.setting.delay_timer == CAMERA_SETTING_DELAY_TIMER_OFF)
        {
            mmi_camera_sublcd_capture();
        }
        else
        {
            CAMERA_ENTER_STATE(CAMERA_STATE_SUB_COUNTDOWN);
        }
    }
    
    /* flush key event */
    ClearKeyEvents();
}
#endif /* __CAMERA_FEATURE_SELF_CAPTURE__ */ 

/*****************************************************************************
*
*  Utility drawing functions
*
*****************************************************************************/


/*****************************************************************************
* FUNCTION
*  mmi_camera_draw_style_text
* DESCRIPTION
*  draw style text
* PARAMETERS
*  str             [IN]        String
*  offset_x        [IN]        Offset x
*  offset_y        [IN]        Offset y
*  style_txt       [IN]        Text style
* RETURNS
*  void
*****************************************************************************/
void mmi_camera_draw_style_text(PS8 str, S32 offset_x, S32 offset_y, S32 truncated_width,camera_style_text_struct *style_txt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (r2lMMIFlag)
    {
        offset_x += gui_get_string_width((UI_string_type) str);
    }
    
    if (truncated_width == 0)
    {
        if (style_txt->style == CAMERA_TEXT_STYLE_NORMAL)
        {
            gui_move_text_cursor(offset_x, offset_y);
            gui_set_text_color(gui_color(style_txt->r, style_txt->g, style_txt->b));
            gui_print_text((UI_string_type) str);
        }
        else if (style_txt->style == CAMERA_TEXT_STYLE_BORDER)
        {
            gui_move_text_cursor(offset_x, offset_y);
            gui_set_text_color(gui_color(style_txt->r, style_txt->g, style_txt->b));
            gui_set_text_border_color(gui_color(style_txt->style_r, style_txt->style_g, style_txt->style_b));
            gui_print_bordered_text((UI_string_type) str);
        }
        else if (style_txt->style == CAMERA_TEXT_STYLE_SHADOW)
        {
            gui_move_text_cursor(offset_x + 1, offset_y + 1);
            gui_set_text_color(gui_color(style_txt->style_r, style_txt->style_g, style_txt->style_b));
            gui_print_text((UI_string_type) str);
            
            gui_move_text_cursor(offset_x, offset_y);
            gui_set_text_color(gui_color(style_txt->r, style_txt->g, style_txt->b));
            gui_print_text((UI_string_type) str);
        }
        else
        {
            MMI_ASSERT(0);
        }
    }
    else if (truncated_width > 0)
    {
        if (style_txt->style == CAMERA_TEXT_STYLE_NORMAL)
        {
            gui_set_text_color(gui_color(style_txt->r, style_txt->g, style_txt->b));
            gui_print_truncated_text(offset_x,offset_y,truncated_width,(UI_string_type) str);
        }
        else if (style_txt->style == CAMERA_TEXT_STYLE_BORDER)
        {
            gui_set_text_color(gui_color(style_txt->r, style_txt->g, style_txt->b));
            gui_set_text_border_color(gui_color(style_txt->style_r, style_txt->style_g, style_txt->style_b));
            gui_print_truncated_borderd_text(offset_x,offset_y,truncated_width,(UI_string_type) str);
        }
        else if (style_txt->style == CAMERA_TEXT_STYLE_SHADOW)
        {
            gui_set_text_color(gui_color(style_txt->style_r, style_txt->style_g, style_txt->style_b));
            gui_print_truncated_text(offset_x+1,offset_y+1,truncated_width,(UI_string_type) str);
            
            gui_set_text_color(gui_color(style_txt->r, style_txt->g, style_txt->b));
            gui_print_truncated_text(offset_x,offset_y,truncated_width,(UI_string_type) str);
        }
        else
        {
            MMI_ASSERT(0);
        }
        
    }
    else
    {
        MMI_ASSERT(truncated_width>=0);
    }
    
}

/*****************************************************************************
*
*  Touch Screen Support
*
*****************************************************************************/


/*****************************************************************************
* FUNCTION
*  mmi_camera_touch_scr_pen_down_hdlr
* DESCRIPTION
*  touch screen hdlr when pen down
* PARAMETERS
*  pos     [IN]        Pen down position
* RETURNS
*  void
*****************************************************************************/
#if defined(__CAMERA_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_camera_touch_scr_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270)
    {
        S32 tmp;
        
        tmp = pos.x;
        pos.x = pos.y;
        pos.y = (LCD_WIDTH - 1) - tmp;
    }
#if defined(__MMI_CAMERA_BG_CALL__)
    if (mmi_ucm_is_background_call()==TRUE)
    {
        if (mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_lsk) == MMI_TRUE)
        {
            mmi_camera_preview_lsk_press();
            g_camera_cntx.touch_object = CAMERA_TOUCH_LSK;
            return;
        }
        
        if (mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_rsk) == MMI_TRUE)
        {
            mmi_camera_preview_rsk_press();
            g_camera_cntx.touch_object = CAMERA_TOUCH_RSK;
            return;
        }
        
        /* capture */
        if (mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_capture) == MMI_TRUE)
        {
            mmi_camera_incall_popup_error();
            g_camera_cntx.touch_object = CAMERA_TOUCH_CAPTURE;
            return;
        }
        
        return ;
    }
#endif /* __MMI_CAMERA_BG_CALL__ */
    
#ifdef __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__
    mmi_camera_stop_all_watchdog();
#endif
    
    /* other screen use generic touch screen handler */
    if ((g_camera_cntx.is_fullscreen) || (!g_camera_cntx.active_camera_osd_ptr->softkey.is_draw_mmi_softkey))
    {
        /* LSK */
        if (mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_lsk) == MMI_TRUE)
        {
            switch (g_camera_cntx.app_state)
            {
                /* main lcd */
            case CAMERA_STATE_PREVIEW:
            case CAMERA_STATE_COUNTDOWN:
            case CAMERA_STATE_CONTSHOT:
                mmi_camera_preview_lsk_press();
                break;
            case CAMERA_STATE_BURSTSHOT:
#if !defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__)
                mmi_camera_preview_lsk_press();
#endif 
                break;
                
            case CAMERA_STATE_DELETE_CONFIRM:
                mmi_camera_delete_confirm_lsk_press();
                break;
                
            case CAMERA_STATE_BURSTSHOT_SAVE_CONFIRM:
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
                mmi_camera_burstshot_save_confirm_lsk_press();
#endif 
                break;
                
                /* sub lcd */
            case CAMERA_STATE_SUB_PREVIEW:
            case CAMERA_STATE_SUB_COUNTDOWN:
            case CAMERA_STATE_SUB_CONTSHOT:
            case CAMERA_STATE_SUB_BURSTSHOT:
            case CAMERA_STATE_SUB_BURSTSHOT_SAVING:
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
                mmi_camera_sublcd_preview_lsk_press();
#endif 
                break;
            }
            
            g_camera_cntx.touch_object = CAMERA_TOUCH_LSK;
            return;
        }
        
        /* RSK */
        if (mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_rsk) == MMI_TRUE)
        {
            switch (g_camera_cntx.app_state)
            {
                /* main lcd */
            case CAMERA_STATE_PREVIEW:
            case CAMERA_STATE_COUNTDOWN:
            case CAMERA_STATE_CONTSHOT:
                mmi_camera_preview_rsk_press();
                break;
            case CAMERA_STATE_BURSTSHOT:
#if !defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__)
                mmi_camera_preview_rsk_press();
#endif 
                break;
            case CAMERA_STATE_DELETE_CONFIRM:
                mmi_camera_delete_confirm_rsk_press();
                break;
                
            case CAMERA_STATE_BURSTSHOT_SAVE_CONFIRM:
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
                mmi_camera_burstshot_save_confirm_rsk_press();
#endif 
                break;
                
                /* sub lcd */
            case CAMERA_STATE_SUB_PREVIEW:
            case CAMERA_STATE_SUB_COUNTDOWN:
            case CAMERA_STATE_SUB_CONTSHOT:
            case CAMERA_STATE_SUB_BURSTSHOT:
            case CAMERA_STATE_SUB_BURSTSHOT_SAVING:
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
                mmi_camera_sublcd_preview_rsk_press();
#endif 
                break;
            }
            g_camera_cntx.touch_object = CAMERA_TOUCH_RSK;
            return;
        }
        
    }
    else
    {
        if (wgui_test_lsk_position(pos) == MMI_TRUE)
        {
            /* draw clicked lsk */
            mmi_camera_preview_lsk_press();
            g_camera_cntx.touch_object = CAMERA_TOUCH_LSK;
            return;
        }
        if (wgui_test_rsk_position(pos) == MMI_TRUE)
        {
            /* draw clicked rsk */
            mmi_camera_preview_rsk_press();
            g_camera_cntx.touch_object = CAMERA_TOUCH_RSK;
            return;
        }
    }
    /* while af is calculating, disable touch panel */
#ifdef __CAMERA_AUTOFOCUS__
    if (g_camera_cntx.af_state == AF_CALCULATE || g_camera_cntx.is_autofocus_pressed == TRUE)
    {
        g_camera_cntx.touch_object = CAMERA_TOUCH_NONE;
        return;
    }
#endif /* __CAMERA_AUTOFOCUS__ */ 
    
    if (g_camera_cntx.app_state == CAMERA_STATE_PREVIEW && g_camera_cntx.is_capturing == FALSE)
    {
        /* osd test */
#define OSD_ICON_TOUCH_TEST(a,A)                                                             \
    do {                                                                                         \
    if(g_camera_cntx.active_camera_osd_ptr->##a##.is_show)                                    \
        {                                                                                         \
        if(mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_##a##) == MMI_TRUE)\
        {                                                                                      \
        mmi_camera_preview_##a##_hotkey_press();                                            \
        g_camera_cntx.touch_object = CAMERA_TOUCH_##A;                                      \
        return;                                                                             \
    }                                                                                      \
    }                                                                                         \
    } while(0);
        
        if (!g_camera_cntx.is_hide_osd)
        {
            
#ifdef __CAMERA_FEATURE_EFFECT__
            OSD_ICON_TOUCH_TEST(effect, EFFECT);
#endif 
            
#ifdef __CAMERA_FEATURE_WB__
            OSD_ICON_TOUCH_TEST(wb, WB);
#endif 
            
#ifdef __CAMERA_FEATURE_FLASH__
            OSD_ICON_TOUCH_TEST(flash, FLASH);
#endif 
            
#ifdef __CAMERA_FEATURE_LED_HIGHLIGHT__
            OSD_ICON_TOUCH_TEST(led_highlight, LED_HIGHLIGHT);
#endif 
            
#ifdef __CAMERA_FEATURE_NIGHT__
            OSD_ICON_TOUCH_TEST(night, NIGHT);
#endif 
            
            if (g_camera_cntx.external_request_mode != MMI_CAMERA_EXTERNAL_MODE_LARGEST_RESOLUTION)
            {
                OSD_ICON_TOUCH_TEST(image_size, IMAGE_SIZE);
            }
            
            OSD_ICON_TOUCH_TEST(image_qty, IMAGE_QTY);
            
#ifdef __CAMERA_FEATURE_CONT_SHOT__
            if (g_camera_cntx.external_request_mode == MMI_CAMERA_EXTERNAL_MODE_OFF)
            {
                /* !for External Request */
                OSD_ICON_TOUCH_TEST(cont_shot, CONT_SHOT);
            }
#endif 
            
#ifdef __CAMERA_FEATURE_DELAY_TIMER__
            OSD_ICON_TOUCH_TEST(delay_timer, DELAY_TIMER);
#endif 
            
#ifdef __CAMERA_DSC_MODE__
            OSD_ICON_TOUCH_TEST(dsc_mode, DSC_MODE);
#endif 
            
#ifdef __CAMERA_FEATURE_ISO_SUPPORT__
#ifdef __CAMERA_DSC_MODE_NIGHT__
            if (g_camera_cntx.active_camera_osd_ptr->iso.is_show && g_camera_cntx.setting.dsc_mode != CAMERA_SETTING_DSC_MODE_NIGHT)
#else
                if (g_camera_cntx.active_camera_osd_ptr->iso.is_show)
#endif            
                {
                    if(mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_iso) == MMI_TRUE)
                    {
                        mmi_camera_preview_iso_hotkey_press();
                        g_camera_cntx.touch_object = CAMERA_TOUCH_ISO;
                        return;
                    }
                }
#endif 
                
#ifdef __CAMERA_FEATURE_AE_METER__
                OSD_ICON_TOUCH_TEST(ae_meter, AE_METER);
#endif 
                
#ifdef __CAMERA_AUTOFOCUS_MODE__
                OSD_ICON_TOUCH_TEST(af_mode, AF_MODE);
#endif 
                
#ifdef __CAMERA_AUTOFOCUS_METERING__
                OSD_ICON_TOUCH_TEST(af_meter, AF_METER);
#endif 
                
#ifdef __CAMERA_FEATURE_STORAGE__
                OSD_ICON_TOUCH_TEST(storage, STORAGE);
#endif 
                
                /* ev inc test */
                if (mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_ev_inc) == MMI_TRUE)
                {
                    mmi_camera_preview_ev_inc_key_press();
                    g_camera_cntx.touch_object = CAMERA_TOUCH_EV_INC;
                    return;
                }
                
                /* ev dec test */
                if (mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_ev_dec) == MMI_TRUE)
                {
                    mmi_camera_preview_ev_dec_key_press();
                    g_camera_cntx.touch_object = CAMERA_TOUCH_EV_DEC;
                    return;
                }
#ifdef __CAMERA_FEATURE_ZOOM__
                /* zoom inc test */
                if (mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_zoom_inc) == MMI_TRUE)
                {
                    mmi_camera_preview_up_arrow_press();
                    g_camera_cntx.touch_object = CAMERA_TOUCH_ZOOM_INC;
                    return;
                }
                
                /* zoom dec test */
                if (mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_zoom_dec) == MMI_TRUE)
                {
                    mmi_camera_preview_down_arrow_press();
                    g_camera_cntx.touch_object = CAMERA_TOUCH_ZOOM_DEC;
                    return;
                }
#endif
    }
    
    /* capture */
    if (mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_capture) == MMI_TRUE)
    {
#ifdef __MMI_CAMERA_AF_TEST__
        mmi_camera_af_test();
#else 
        mmi_camera_capture_button_press();
#endif 
        g_camera_cntx.touch_object = CAMERA_TOUCH_CAPTURE;
        return;
    }
}
#if defined(__MMI_CAMERA_FORWARD_SUPPORT__)
else if (g_camera_cntx.app_state == CAMERA_STATE_DELETE_CONFIRM &&
         g_camera_cntx.external_request_mode == MMI_CAMERA_EXTERNAL_MODE_OFF &&
         mmi_camera_is_forward_function_ready() == MMI_TRUE)
{
    if (mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_mms_icon) == MMI_TRUE)
    {
        mmi_camera_forward_icon_press();
        g_camera_cntx.touch_object = CAMERA_TOUCH_MMS_ICON;
    }
    return;
}
#endif /* defined(__MMI_CAMERA_FORWARD_SUPPORT__)*/ 

g_camera_cntx.touch_object = CAMERA_TOUCH_NONE;

}
#endif /* defined(__CAMERA_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__) */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_touch_scr_pen_up_hdlr
* DESCRIPTION
*  touch screen hdlr when pen up
* PARAMETERS
*  pos     [IN]        Pen up position
* RETURNS
*  void
*****************************************************************************/
#if defined(__CAMERA_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_camera_touch_scr_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270)
    {
        S32 tmp;
        
        tmp = pos.x;
        pos.x = pos.y;
        pos.y = (LCD_WIDTH - 1) - tmp;
    }
#if defined(__MMI_CAMERA_BG_CALL__)
    if (mmi_ucm_is_background_call()==TRUE)
    {
        switch (g_camera_cntx.touch_object)
        {
        case CAMERA_TOUCH_LSK:
            if (mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_lsk) == MMI_TRUE)
            {
                mmi_camera_preview_lsk_release();
            }
            else if (g_camera_cntx.is_lsk_pressed == TRUE)
            {
                g_camera_cntx.is_lsk_pressed = FALSE;
                mmi_camera_preview_draw_osd();
                mmi_camera_blt();
            }
            break;
            
        case CAMERA_TOUCH_RSK:
            if (mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_rsk) == MMI_TRUE)
            {
                mmi_camera_preview_rsk_release();
            }
            else if (g_camera_cntx.is_rsk_pressed == TRUE)
            {
                g_camera_cntx.is_rsk_pressed = FALSE;
                mmi_camera_preview_draw_osd();
                mmi_camera_blt();
            }
            break;
        default:
            break;
        }
        return;
    }
#endif /* __MMI_CAMERA_BG_CALL__ */
    
#ifdef __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__
    mmi_camera_start_all_watchdog();
#endif
    
    switch (g_camera_cntx.touch_object)
    {
    case CAMERA_TOUCH_LSK:
        if (mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_lsk) == MMI_TRUE)
        {
            switch (g_camera_cntx.app_state)
            {
                /* main lcd */
            case CAMERA_STATE_PREVIEW:
            case CAMERA_STATE_COUNTDOWN:
            case CAMERA_STATE_CONTSHOT:
                mmi_camera_preview_lsk_release();
                break;
            case CAMERA_STATE_BURSTSHOT:
#if !defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__)
                mmi_camera_preview_lsk_release();
#endif 
                break;
                
            case CAMERA_STATE_DELETE_CONFIRM:
                mmi_camera_delete_confirm_lsk_release();
                break;
                
            case CAMERA_STATE_BURSTSHOT_SAVE_CONFIRM:
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
                mmi_camera_burstshot_save_confirm_lsk_release();
#endif 
                break;
                
                /* sub lcd */
            case CAMERA_STATE_SUB_PREVIEW:
            case CAMERA_STATE_SUB_COUNTDOWN:
            case CAMERA_STATE_SUB_CONTSHOT:
            case CAMERA_STATE_SUB_BURSTSHOT:
            case CAMERA_STATE_SUB_BURSTSHOT_SAVING:
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
                mmi_camera_sublcd_preview_rsk_release();
#endif 
                break;
            }
        }
        else if (g_camera_cntx.is_lsk_pressed == TRUE)
        {
            g_camera_cntx.is_lsk_pressed = FALSE;
            mmi_camera_preview_draw_osd();
            mmi_camera_blt();
        }
        break;
        
    case CAMERA_TOUCH_RSK:
        if (mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_rsk) == MMI_TRUE)
        {
            switch (g_camera_cntx.app_state)
            {
                /* main lcd */
            case CAMERA_STATE_PREVIEW:
            case CAMERA_STATE_COUNTDOWN:
            case CAMERA_STATE_CONTSHOT:
                mmi_camera_preview_rsk_release();
                break;
            case CAMERA_STATE_BURSTSHOT:
#if !defined(__CAMERA_FEATURE_CONT_SHOT_BURST_NON_BLOCK__)
                mmi_camera_preview_rsk_release();
#endif 
                break;
            case CAMERA_STATE_DELETE_CONFIRM:
                mmi_camera_delete_confirm_rsk_release();
                break;
                
            case CAMERA_STATE_BURSTSHOT_SAVE_CONFIRM:
#ifdef __CAMERA_FEATURE_CONT_SHOT_BURST__
                mmi_camera_burstshot_save_confirm_rsk_release();
#endif 
                break;
                
                /* sub lcd */
            case CAMERA_STATE_SUB_PREVIEW:
            case CAMERA_STATE_SUB_COUNTDOWN:
            case CAMERA_STATE_SUB_CONTSHOT:
            case CAMERA_STATE_SUB_BURSTSHOT:
            case CAMERA_STATE_SUB_BURSTSHOT_SAVING:
#ifdef __CAMERA_FEATURE_SELF_CAPTURE__
                mmi_camera_sublcd_preview_lsk_release();
#endif 
                break;
            }
        }
        else if (g_camera_cntx.is_rsk_pressed == TRUE)
        {
            g_camera_cntx.is_rsk_pressed = FALSE;
            mmi_camera_preview_draw_osd();
            mmi_camera_blt();
        }
        
        break;
        
    case CAMERA_TOUCH_EV_INC:
        if (mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_ev_inc) == MMI_TRUE)
        {
            mmi_camera_preview_ev_inc_key_release();
        }
        break;
        
    case CAMERA_TOUCH_EV_DEC:
        if (mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_ev_dec) == MMI_TRUE)
        {
            mmi_camera_preview_ev_dec_key_release();
        }
        break;
#ifdef __CAMERA_FEATURE_ZOOM__
    case CAMERA_TOUCH_ZOOM_INC:
        if (mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_zoom_inc) == MMI_TRUE)
        {
            mmi_camera_preview_up_arrow_release();
        }
        break;
        
    case CAMERA_TOUCH_ZOOM_DEC:
        if (mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_zoom_dec) == MMI_TRUE)
        {
            mmi_camera_preview_down_arrow_release();
        }
        break;
#endif            
#if defined(__MMI_CAMERA_FORWARD_SUPPORT__)
    case CAMERA_TOUCH_MMS_ICON:
        if (g_camera_cntx.app_state == CAMERA_STATE_DELETE_CONFIRM 
            && mmi_camera_is_forward_function_ready() == MMI_TRUE)
        {
            if (mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_mms_icon) == MMI_TRUE)
            {
                mmi_camera_forward_icon_release();
            }
        }
        break;
#endif /* defined(__MMI_CAMERA_FORWARD_SUPPORT__) */ 
        
    default:
        break;
}

}
#endif /* defined(__CAMERA_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__) */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_touch_scr_pen_move_hdlr
* DESCRIPTION
*  touch screen hdlr when pen move
* PARAMETERS
*  pos     [IN]        Pen move position
* RETURNS
*  void
*****************************************************************************/
#if defined(__CAMERA_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_camera_touch_scr_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL softkey_pressed;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    softkey_pressed = FALSE;
    if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270)
    {
        S32 tmp;
        
        tmp = pos.x;
        pos.x = pos.y;
        pos.y = (LCD_WIDTH - 1) - tmp;
    }
#if defined(__MMI_CAMERA_BG_CALL__)
    if (mmi_ucm_is_background_call()==TRUE)
    {
        switch (g_camera_cntx.touch_object)
        {
        case CAMERA_TOUCH_LSK:
            if (mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_lsk))
            {
                softkey_pressed = TRUE;
            }
            else
            {
                softkey_pressed = FALSE;
            }
            
            if (softkey_pressed != g_camera_cntx.is_lsk_pressed)
            {
                g_camera_cntx.is_lsk_pressed = softkey_pressed;
                mmi_camera_preview_draw_osd();
                mmi_camera_blt();
            }
            break;
            
        case CAMERA_TOUCH_RSK:
            if (mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_rsk))
            {
                softkey_pressed = TRUE;
            }
            else
            {
                softkey_pressed = FALSE;
            }
            
            if (softkey_pressed != g_camera_cntx.is_rsk_pressed)
            {
                g_camera_cntx.is_rsk_pressed = softkey_pressed;
                mmi_camera_preview_draw_osd();
                mmi_camera_blt();
            }
            break;
        }
        return;
    }
#endif /* __MMI_CAMERA_BG_CALL__ */
    
    switch (g_camera_cntx.touch_object)
    {
    case CAMERA_TOUCH_LSK:
        if (mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_lsk))
        {
            softkey_pressed = TRUE;
        }
        else
        {
            softkey_pressed = FALSE;
        }
        
        if (softkey_pressed != g_camera_cntx.is_lsk_pressed)
        {
            g_camera_cntx.is_lsk_pressed = softkey_pressed;
            mmi_camera_preview_draw_osd();
            mmi_camera_blt();
        }
        break;
        
    case CAMERA_TOUCH_RSK:
        if (mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_rsk))
        {
            softkey_pressed = TRUE;
        }
        else
        {
            softkey_pressed = FALSE;
        }
        
        if (softkey_pressed != g_camera_cntx.is_rsk_pressed)
        {
            g_camera_cntx.is_rsk_pressed = softkey_pressed;
            mmi_camera_preview_draw_osd();
            mmi_camera_blt();
        }
        break;
        
    case CAMERA_TOUCH_EV_INC:
        if (!mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_ev_inc))
        {
            /* move out, treat as key release */
            mmi_camera_preview_ev_inc_key_release();
        }
        break;
        
    case CAMERA_TOUCH_EV_DEC:
        if (!mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_ev_dec))
        {
            /* move out, treat as key release */
            mmi_camera_preview_ev_dec_key_release();
        }
        break;
#ifdef __CAMERA_FEATURE_ZOOM__
    case CAMERA_TOUCH_ZOOM_INC:
        if (!mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_zoom_inc))
        {
            /* move out, treat as key release */
            mmi_camera_preview_up_arrow_release();
        }
        break;
        
    case CAMERA_TOUCH_ZOOM_DEC:
        if (!mmi_camera_touch_scr_hit_test(pos.x, pos.y, &g_camera_cntx.touch_zoom_dec))
        {
            /* move out, treat as key release */
            mmi_camera_preview_down_arrow_release();
        }
        break;
#endif            
#if defined(__MMI_CAMERA_FORWARD_SUPPORT__)
    case CAMERA_TOUCH_MMS_ICON:
        if (g_camera_cntx.app_state == CAMERA_STATE_DELETE_CONFIRM 
            && mmi_camera_is_forward_function_ready() == MMI_TRUE)
        {
            g_camera_cntx.is_mms_icon_pressed = FALSE;
            mmi_camera_preview_draw_osd();
            
            mmi_camera_blt();
        }
        break;
#endif /* defined(__MMI_CAMERA_FORWARD_SUPPORT__) */ 
        
    }
}
#endif /* defined(__CAMERA_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__) */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_touch_scr_hit_test
* DESCRIPTION
*  test if is within touch region
* PARAMETERS
*  pos_x           [IN]        Position x
*  pos_y           [IN]        Position y
*  touch_obj       [?]         
*  touch(?)        [IN]        Touch object structure
* RETURNS
* BOOL
*****************************************************************************/
#if defined(__CAMERA_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__)
static BOOL mmi_camera_touch_scr_hit_test(S32 pos_x, S32 pos_y, camera_ui_touch_struct *touch_obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((pos_x >= touch_obj->offset_x) &&
        (pos_x < touch_obj->offset_x + touch_obj->width) &&
        (pos_y >= touch_obj->offset_y) && (pos_y < touch_obj->offset_y + touch_obj->height))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
#endif /* defined(__CAMERA_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__) */ 

/*****************************************************************************
*
*  Screen Snapshot
*
*****************************************************************************/


/*****************************************************************************
* FUNCTION
*  mmi_camera_scr_snapshot
* DESCRIPTION
*  snapshot screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __MMI_SCREEN_SNAPSHOT__
void mmi_camera_scr_snapshot(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_camera_cntx.is_screen_snapshot) ||               /* capture screen shot */
        (g_camera_cntx.app_state != CAMERA_STATE_EXIT) ||   /* in camera app */
        (mmi_vdorec_is_in_app()) ||                         /* in video recorder */
        (mmi_vdoply_is_in_app()))                           /* in video player */
    {
        return;
    }
    
    mmi_camera_entry_scr_snapshot_screen();
    
}
#endif /* __MMI_SCREEN_SNAPSHOT__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_entry_scr_snapshot_screen
* DESCRIPTION
*  entry  screen snapshot screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __MMI_SCREEN_SNAPSHOT__
static void mmi_camera_entry_scr_snapshot_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle base_layer;
    S8 storage_filepath[FMGR_PATH_BUFFER_SIZE];
    S8 storage_filename[FMGR_PATH_BUFFER_SIZE];
    U16 cur_storage;
    S32 create_result;
    MDI_RESULT result;
    S8 buffer[25];
    S8 UCS2_buffer[50];
    S8 UCS2_testname[50];
    S8 UCS2_alpha[10];
    S16 error = 0;
    U16 filename_seq_no;
    U16 alpha_count;
    U16 alpha_index;
    FS_HANDLE file_handle;
    mmi_event_notify_enum event_id;
    MMI_ID_TYPE str_id = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.is_screen_snapshot = TRUE;
    
    /* enter a new screen, force previous screen leave */
    EntryNewScreen(
        SCR_ID_CAMERA_SCREEN_SNAPSHOT,
        mmi_camera_exit_scr_snapshot_screen,
        NULL,   /* entry function is null, will not add to history by framework */
        NULL);
    
    /* load Setting */
    mmi_camera_load_setting();
    
    /* allocate storage path buffer */
    memset(storage_filepath, 0, FMGR_PATH_BUFFER_SIZE);
    
    /* check if path is valid or not. if not will pop up a screen after the preview screen is show */
    cur_storage = mmi_imgview_get_storage();
    
    /* drv is valid, create directory */
    mmi_imgview_get_storage_file_path(storage_filepath);
    create_result = mmi_imgview_create_file_dir(storage_filepath);
    
    /* create directory error check */
    if (create_result < 0)
    {
        str_id = GetFileSystemErrorString(create_result);
        MMI_CAMERA_DISPLAY_POPUP(GetString(str_id), MMI_EVENT_FAILURE);
        return;
    }
    
    
    /* get/store sequentail number */
    ReadValue(NVRAM_SCR_SNAPSHOT_SEQ_NO, &filename_seq_no, DS_SHORT, &error);
    if (filename_seq_no == 0xffff)
    {
        filename_seq_no = 1;    /* init value */
    }
    else
    {
        filename_seq_no++;
        if (filename_seq_no > 9999) /* more than 4 digits */
        {
            filename_seq_no = 1;
        }
    }
    WriteValue(NVRAM_SCR_SNAPSHOT_SEQ_NO, &filename_seq_no, DS_SHORT, &error);
    
    alpha_count = 'Z' - 'A' + 1;
    alpha_index = 0;
    
    sprintf((PS8) buffer, "SCR%04d", filename_seq_no);
    mmi_asc_to_ucs2((PS8) UCS2_buffer, (PS8) buffer);
    
    while (1)
    {
        sprintf((PS8) buffer, "%c", 'A' + alpha_index);
        mmi_asc_to_ucs2((PS8) UCS2_alpha, (PS8) buffer);
        
        mmi_ucs2cpy(UCS2_testname, UCS2_buffer);
        mmi_ucs2cat(UCS2_testname, UCS2_alpha);
        mmi_ucs2cat(UCS2_testname, (PS8) L".jpg");
        
        mmi_ucs2cpy((PS8) storage_filename, (PS8) storage_filepath);
        mmi_ucs2cat((PS8) storage_filename, (PS8) UCS2_testname);
        
        file_handle = FS_Open((U16*) storage_filename, FS_READ_ONLY);
        
        if (file_handle >= 0)
        {
            /* file exist */
            FS_Close(file_handle);
            alpha_index++;
        }
        else
        {
            break;
        }
        
        /* exit condition - will get a IMGXXXXZ.jpg as file name */
        if (alpha_index >= alpha_count - 1)
        {
            break;
        }
    }
    
    /* play capture sound */
    mmi_camera_capture_play_sound();
    
    /* encode layer */
    gdi_layer_get_base_handle(&base_layer);
    result = mdi_camera_encode_layer_to_jpeg(base_layer, storage_filename);
    
    switch (result)
    {
    case MDI_RES_CAMERA_SUCCEED:
        /* use storage_filepath as tmp buffer */
        mmi_ucs2cpy(storage_filepath, (PS8) GetString(STR_ID_CAMERA_NOTIFY_SCREEN_CAPTURED));
        mmi_ucs2cat(storage_filepath, (PS8) L"\n");
        mmi_ucs2cat(storage_filepath, (PS8) UCS2_testname);
        MMI_CAMERA_DISPLAY_POPUP((PU8) storage_filepath, MMI_EVENT_SUCCESS);
        return;
        break;
        
    default:
        str_id = mmi_camera_get_error_string_by_error_enum(result);
        event_id = mmi_camera_get_error_type_by_error_enum(result);
        MMI_CAMERA_DISPLAY_POPUP((PU8) GetString(str_id), event_id);
        return;
        break;
    }
    
}
#endif /* __MMI_SCREEN_SNAPSHOT__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_exit_scr_snapshot_screen
* DESCRIPTION
*  exit  screen snapshot screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __MMI_SCREEN_SNAPSHOT__
static void mmi_camera_exit_scr_snapshot_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.is_screen_snapshot = FALSE;
}
#endif /* __MMI_SCREEN_SNAPSHOT__ */ 

#if defined(__MMI_CAMERA_FORWARD_SUPPORT__)
/*****************************************************************************
* FUNCTION
*  mmi_camera_forward_icon_press
* DESCRIPTION
*  press forward_icon
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_forward_icon_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__
    mmi_camera_stop_delete_confirm_watchdog();
#endif
    g_camera_cntx.is_mms_icon_pressed = TRUE;
    mmi_camera_preview_draw_osd();
    mmi_camera_blt();
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_forward_icon_release
* DESCRIPTION
*  release forward_icon
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_forward_icon_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.is_mms_icon_pressed = FALSE;
    mmi_camera_preview_draw_osd();
    
    mmi_camera_blt();
    
#if defined(__MMI_CAMERA_FORWARD_SUPPORT__)
    g_camera_cntx.app_prev_state = g_camera_cntx.app_state;
    g_camera_cntx.app_state = CAMERA_STATE_FORWARD_TO;
    mmi_camera_entry_forward_menu_screen();
#else
    mms_content_insert_hdlr((PS8) g_camera_cntx.captured_filepath);
#endif
}

#endif /* defined(__MMI_CAMERA_FORWARD_SUPPORT__) */ 

#ifdef __CAMERA_FAST_ZOOM_SUPPORT__
/*****************************************************************************
* FUNCTION
*  mmi_camera_get_zoom_level_idx
* DESCRIPTION
*  draw preview OSD panel
* PARAMETERS
*  factor      [IN]        
* RETURNS
*  void
*****************************************************************************/
static U16 mmi_camera_get_zoom_level_idx(S32 factor)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < CAMERA_FEATURE_ZOOM_COUNT; i++)
    {
        if (g_camera_feature_zoom[i] == factor)
        {
            return i;
        }
    }
    
    return g_camera_cntx.setting.zoom_idx;
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_start_fast_zoom_in
* DESCRIPTION
*  start fast zoom operation
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_start_fast_zoom_in(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.is_fast_zoom = TRUE;
    g_camera_cntx.is_draw_timer_on = TRUE;
    gui_start_timer(100, mmi_camera_preview_draw_osd_timer);
#if defined(MT6253) || defined(MT6253T)
    mdi_camera_start_fast_zoom(TRUE, (U8) g_camera_cntx.zoom_limit, 2, 1);
#else
    mdi_camera_start_fast_zoom(TRUE, (U8) g_camera_cntx.zoom_limit, 1, 1);
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_start_fast_zoom_out
* DESCRIPTION
*  start fast zoom operation
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_start_fast_zoom_out(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.is_fast_zoom = TRUE;
    g_camera_cntx.is_draw_timer_on = TRUE;
    gui_start_timer(100, mmi_camera_preview_draw_osd_timer);
#if defined(MT6253) || defined(MT6253T)
    mdi_camera_start_fast_zoom(FALSE, (U8) g_camera_cntx.zoom_limit, 2, 1);
#else
    mdi_camera_start_fast_zoom(FALSE, (U8) g_camera_cntx.zoom_limit, 1, 1);
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_stop_fast_zoom
* DESCRIPTION
*  stop fast zoom operation
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_stop_fast_zoom(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 current_idx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_camera_stop_fast_zoom();
    g_camera_cntx.is_fast_zoom = FALSE;
    mdi_camera_get_fast_zoom_factor(&current_idx);
    g_camera_cntx.setting.zoom_idx = mmi_camera_get_zoom_level_idx((S32)current_idx);    
}
#endif /* __CAMERA_FAST_ZOOM_SUPPORT__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_camera_get_camera_banding
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  U16 OUT camera banding 
*****************************************************************************/
U8 mmi_camera_get_camera_banding(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camera_load_setting();
    return camera_banding_command_map[g_camera_cntx.setting.banding];
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_change_to_largest_img_size
* DESCRIPTION
*  change capture image size of camera application to the larget resolution.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_camera_change_to_largest_img_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CAMERA_FEATURE_IMAGE_SIZE_LL__
    g_camera_cntx.setting.image_size = CAMERA_SETTING_IMAGE_SIZE_LL;
    goto update_capture_size;
#endif /* __CAMERA_FEATURE_IMAGE_SIZE_LL__ */ 
    
#ifdef __CAMERA_FEATURE_IMAGE_SIZE_L__
    g_camera_cntx.setting.image_size = CAMERA_SETTING_IMAGE_SIZE_L;
    goto update_capture_size;
#endif /* __CAMERA_FEATURE_IMAGE_SIZE_L__ */ 
    
#ifdef __CAMERA_FEATURE_IMAGE_SIZE_M__
    g_camera_cntx.setting.image_size = CAMERA_SETTING_IMAGE_SIZE_M;
    goto update_capture_size;
#endif /* __CAMERA_FEATURE_IMAGE_SIZE_M__ */ 
    
#ifdef __CAMERA_FEATURE_IMAGE_SIZE_S__
    g_camera_cntx.setting.image_size = CAMERA_SETTING_IMAGE_SIZE_S;
    goto update_capture_size;
#endif /* __CAMERA_FEATURE_IMAGE_SIZE_S__ */ 
    
#ifdef __CAMERA_FEATURE_IMAGE_SIZE_SS__
    g_camera_cntx.setting.image_size = CAMERA_SETTING_IMAGE_SIZE_SS;
    goto update_capture_size;
#endif /* __CAMERA_FEATURE_IMAGE_SIZE_SS__ */ 
    
    
update_capture_size:
    
#ifdef __CAMERA_FEATURE_IMAGE_SIZE_LL__
    UPDATE_IMAGE_SIZE(LL);
#endif /* __CAMERA_FEATURE_IMAGE_SIZE_LL__ */ 
    
#ifdef __CAMERA_FEATURE_IMAGE_SIZE_L__
    UPDATE_IMAGE_SIZE(L);
#endif /* __CAMERA_FEATURE_IMAGE_SIZE_L__ */ 
    
#ifdef __CAMERA_FEATURE_IMAGE_SIZE_M__
    UPDATE_IMAGE_SIZE(M);
#endif /* __CAMERA_FEATURE_IMAGE_SIZE_M__ */ 
    
#ifdef __CAMERA_FEATURE_IMAGE_SIZE_S__
    UPDATE_IMAGE_SIZE(S);
#endif /* __CAMERA_FEATURE_IMAGE_SIZE_S__ */ 
    
#ifdef __CAMERA_FEATURE_IMAGE_SIZE_SS__
    UPDATE_IMAGE_SIZE(SS);
#endif /* __CAMERA_FEATURE_IMAGE_SIZE_SS__ */ 
    
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_external_request
* DESCRIPTION
*  for External Request
* PARAMETERS
*  void
* RETURNS
*  void 
*****************************************************************************/
void mmi_camera_external_request_by_mode( mmi_camera_external_mode_enum mode , camera_result_callback callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scr_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_CAMERA_BG_CALL__)
    if (mmi_ucm_is_background_call() == MMI_TRUE)
    {
        mmi_camera_incall_popup_error();
        return;
    }
#endif
    
    /*Delete all camera related screen to deal with re-entry*/
    for (scr_id = SCR_ID_CAMERA_APP; scr_id < SCR_ID_CAMERA_END; scr_id ++)
    {
        DeleteScreenIfPresent(scr_id);
    }
    
    /* allocate memory from App-Based ASM */
    //if (g_camera_cntx.app_mem_pool==NULL && CAMERA_DIRECT_COUPLE_BUFFER_SIZE >0)
#if defined(__MDI_CAMERA_HW_ROTATOR_SUPPORT__) && defined(__CAMERA_OSD_HORIZONTAL__)
    if (g_camera_cntx.app_mem_pool==NULL)
    {
        g_camera_cntx.app_mem_pool 
            = applib_mem_ap_alloc_framebuffer(APPLIB_MEM_AP_ID_CAMERA, CAMERA_HW_ROTATE_TMP_BUFFER);
        
        if (g_camera_cntx.app_mem_pool == NULL)
        {
            /* temp solution for MAUI01117575, due to appmem callback couldn't pass parameters */
            g_camera_cntx.tmp_callback_ptr = callback;
            g_camera_cntx.tmp_external_request_mode = mode;
            
            mmi_frm_appmem_prompt_to_release_mem(
                APPLIB_MEM_AP_ID_CAMERA,
                IMG_ID_CAMERA_APP_ICON,
                CAMERA_HW_ROTATE_TMP_BUFFER ,
                mmi_camera_app_mem_success_callback);
            return;
        }       
    }
#endif
    
#if defined(__DIRECT_SENSOR_SUPPORT__)
    if (g_camera_cntx.app_mem_pool==NULL)
    {
        /* reset parameters of appmem callback  */
        g_camera_cntx.tmp_callback_ptr = NULL;
        g_camera_cntx.tmp_external_request_mode = MMI_CAMERA_EXTERNAL_MODE_OFF;        
        
        g_camera_cntx.app_mem_pool 
            = applib_mem_ap_alloc_framebuffer(APPLIB_MEM_AP_ID_CAMERA, CAMERA_DIRECT_COUPLE_BUFFER_SIZE);
        
        if (g_camera_cntx.app_mem_pool == NULL)
        {
            mmi_frm_appmem_prompt_to_release_mem(
                APPLIB_MEM_AP_ID_CAMERA,
                IMG_ID_CAMERA_APP_ICON,
                CAMERA_DIRECT_COUPLE_BUFFER_SIZE ,
                mmi_camera_app_mem_success_callback);
            return;
        }       
    }
#endif
    
    mmi_camera_load_setting();
    g_camera_cntx.callback_ptr = callback;
    g_camera_cntx.external_request_mode = mode;
    g_camera_cntx.contshot_backup = g_camera_cntx.setting.cont_shot;
    g_camera_cntx.setting.cont_shot = 0;
    
    if (CAMERA_STATE_IN(CAMERA_STATE_FORWARD_TO))
    {
        g_camera_cntx.is_in_fast_forward = TRUE;
        CAMERA_ENTER_STATE(CAMERA_STATE_EXIT);
    }    
    
    switch(g_camera_cntx.external_request_mode)
    {
    case MMI_CAMERA_EXTERNAL_MODE_LARGEST_RESOLUTION:
        g_camera_cntx.img_size_backup = g_camera_cntx.setting.image_size;
        mmi_camera_change_to_largest_img_size();
        break;
    default:
        break;
    }
    
    mmi_camera_app_screen();
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_entry_for_external_request
* DESCRIPTION
*  for External Request
* PARAMETERS
*  void
* RETURNS
*  void 
*****************************************************************************/
void mmi_camera_entry_for_external_request(
                                           camera_result_callback callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_camera_external_request_by_mode(MMI_CAMERA_EXTERNAL_MODE_NORMAL, callback);
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_forward_to_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_camera_forward_to_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    switch(g_camera_cntx.forward_to)
    {
        /* Bluetooth sending API revise */
#ifdef __MMI_BT_SEND_SUPPORT__
    case MMI_CAMERA_FORWARD_TO_BT:
        {
            btsend_obj_struct obj;
            btsend_app_struct app;
            
            memset(&obj, 0, sizeof(obj));
            memset(&app, 0, sizeof(app));
            
            obj.data.obj_type = BTSEND_USE_FILE;
            obj.data.u.file.path = (U16 *)g_camera_cntx.captured_filepath;
            
            app.id = (U8)APP_CAMERA;
#ifdef __MMI_BT_AUTO_PROMPT_SWITCH__
            mmi_bt_send_object(&obj, &app, BTSEND_PROF_ALL, BTSEND_OPT_DEFAULT_DEVICE);
#else
            mmi_bt_send_object(&obj, &app, BTSEND_PROF_ALL, BTSEND_OPT_NORMAL);
#endif                
        }
        break;
#endif /* __MMI_BT_SEND_SUPPORT */
        
#ifdef __MMI_EMAIL__
    case MMI_CAMERA_FORWARD_TO_EMAIL:
        {
#ifndef __MMI_OP11_CAMERA_VDOREC_CUSTOMIZE__    
            mmi_email_app_send_param_struct email_param;
#endif
            
#ifdef __MMI_OP11_CAMERA_VDOREC_CUSTOMIZE__
            mmi_email_app_send_attch_to_addr((PS8) g_camera_cntx.captured_filepath);
#else /* __MMI_OP11_CAMERA_VDOREC_CUSTOMIZE__ */
            mmi_email_app_send_init_param_to_null(&email_param);
            email_param.attch_file_path = (S8*)g_camera_cntx.captured_filepath;
            mmi_email_app_send(&email_param, EMAIL_ATTCH_FILL_FLAG);
#endif /* __MMI_OP11_CAMERA_VDOREC_CUSTOMIZE__ */
        }
        break;
#endif /* __MMI_EMAIL__ */
        
#ifdef __MMI_MMS__
    case MMI_CAMERA_FORWARD_TO_MMS:
        mms_content_insert_hdlr((PS8) g_camera_cntx.captured_filepath);
        break;
#endif /* __MMI_MMS__ */
#ifdef __MMI_MMS_POSTCARD__
    case MMI_CAMERA_FORWARD_TO_POSTCARD:
        {
            mms_content_entry_struct mms_content;
            memset(&mms_content, 0x00, sizeof(mms_content_entry_struct));
            
            mms_content.mode = MMS_NEW_FILE;
            mms_content.msg_type = MMS_MSG_TYPE_POSTCARD;
            mms_content.file_path = g_camera_cntx.captured_filepath;
            mms_content.addr = 0;
            mms_content.subject = 0;
            mms_content.text_buffer = 0;
            mms_general_insert_hdlr(&mms_content);
        }
        break;
#endif /* __MMI_MMS_POSTCARD__ */
    default:
        ASSERT(0);
        break;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_hilight_forward_to_bt
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_camera_hilight_forward_to_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.forward_to = MMI_CAMERA_FORWARD_TO_BT;
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_hilight_forward_to_email
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_camera_hilight_forward_to_email(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.forward_to = MMI_CAMERA_FORWARD_TO_EMAIL;
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_hilight_forward_to_mms
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_camera_hilight_forward_to_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.forward_to = MMI_CAMERA_FORWARD_TO_MMS;
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_hilight_forward_to_postcard
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_camera_hilight_forward_to_postcard(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.forward_to = MMI_CAMERA_FORWARD_TO_POSTCARD;
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_entry_forward_menu_screen
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_camera_entry_forward_menu_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[16];
    U16 ItemIcons[16];
    U16 nItems;
    U8 *guiBuffer;
    U8 *PopUpList[32];
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CAMERA_FORWARD_OPTION, NULL, mmi_camera_entry_forward_menu_screen, NULL);
    
#if defined(__CAMERA_OSD_HORIZONTAL__)
    if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270)
    {
        mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
    }
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
    
    if (mmi_camera_is_forward_function_ready())
    {
        mmi_frm_unhide_menu_item(MENU_ID_CAMERA_FORWARD_OPTION);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_CAMERA_FORWARD_OPTION);
    }
#if defined(__MMI_MMS_POSTCARD__)
#if defined(__MMI_EMAIL__) 
    mmi_frm_hide_menu_item(MENU_ID_CAMERA_FORWARD_OPTION_TO_EMAIL);
#endif
    
    if (mms_is_ready())
    {
        mmi_frm_unhide_menu_item(MENU_ID_CAMERA_FORWARD_OPTION_TO_POSTCARD);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_CAMERA_FORWARD_OPTION_TO_POSTCARD);
    }
    
#elif defined(__MMI_EMAIL__) 
    if (mmi_email_is_email_can_forward()==TRUE)
    {
        mmi_frm_unhide_menu_item(MENU_ID_CAMERA_FORWARD_OPTION_TO_EMAIL);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_CAMERA_FORWARD_OPTION_TO_EMAIL);
    }
#endif
    
    
#if defined(__MMI_MMS__)
    if (mms_is_ready())
    {
        mmi_frm_unhide_menu_item(MENU_ID_CAMERA_FORWARD_OPTION_TO_MMS);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_CAMERA_FORWARD_OPTION_TO_MMS);
    }
#endif
    
#if !defined(__MMI_OPP_SUPPORT__) && !defined(__MMI_BPP_SUPPORT__) 
    mmi_frm_hide_menu_item(MENU_ID_CAMERA_FORWARD_OPTION_TO_BT);
#endif
    
    guiBuffer = GetCurrGuiBuffer(SCR_ID_CAMERA_FORWARD_OPTION);
    nItems = GetNumOfChild_Ext(MENU_ID_CAMERA_FORWARD_OPTION);
    GetSequenceStringIds_Ext(MENU_ID_CAMERA_FORWARD_OPTION, ItemList);
    GetSequenceImageIds_Ext(MENU_ID_CAMERA_FORWARD_OPTION, ItemIcons);
    SetParentHandler(MENU_ID_CAMERA_FORWARD_OPTION);
    
    RegisterHighlightHandler(ExecuteCurrHiliteHandler_Ext);
    
    for (i = 0; i < nItems; i++)
    {
        PopUpList[i] = NULL;
        ItemIcons[i] = (U16) (IMG_GLOBAL_L1 + i);
    }
    
    ConstructHintsList(MENU_ID_CAMERA_FORWARD_OPTION, PopUpList);
    
    ShowCategory52Screen(
        STR_GLOBAL_SEND,
        GetRootTitleIcon(MENU_ID_CAMERA_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        ItemIcons,
        (U8 **) PopUpList,
        0,
        0,
        guiBuffer);
    
    
    SetLeftSoftkeyFunction(mmi_camera_forward_to_hdlr, KEY_EVENT_UP);
    SetKeyHandler(mmi_camera_forward_to_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_is_forward_function_ready
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  MMI_BOOL
*****************************************************************************/
MMI_BOOL mmi_camera_is_forward_function_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
#if defined(__MMI_BT_SEND_SUPPORT__)
    if (mmi_bootup_get_active_flight_mode() == FLIGHTMODE_OFF ||
        mmi_bt_is_to_display_bt_menu() == MMI_TRUE)
    {
        ret = MMI_TRUE;
    }
#elif defined(__MMI_MMS__) || defined(__MMI_EMAIL__)
    #if defined(__MMI_EMAIL__)
        if (mmi_email_is_email_can_forward() && mmi_bootup_get_active_flight_mode() == FLIGHTMODE_OFF)
        {
            ret = MMI_TRUE;
        }
    #endif
#if defined(__MMI_MMS__)
    if (mms_is_ready() && mmi_bootup_get_active_flight_mode() == FLIGHTMODE_OFF)
    {
        ret = MMI_TRUE;
    }
#endif
#endif
    
    return ret;
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_get_max_capture_resolution
* DESCRIPTION
*  
* PARAMETERS
*  S32 *width  [out] width of max capture resolution
*  S32 *height [out] height of max capture resolution
* RETURNS
*  void
*****************************************************************************/
void mmi_camera_get_max_capture_resolution(S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__CAMERA_FEATURE_IMAGE_SIZE_LL__)
    *width = CAMERA_FEATURE_IMAGE_SIZE_LL_WIDTH;
    *height = CAMERA_FEATURE_IMAGE_SIZE_LL_HEIGHT;
#elif defined(__CAMERA_FEATURE_IMAGE_SIZE_L__)
    *width = CAMERA_FEATURE_IMAGE_SIZE_L_WIDTH;
    *height = CAMERA_FEATURE_IMAGE_SIZE_L_HEIGHT;
#elif defined(__CAMERA_FEATURE_IMAGE_SIZE_M__)
    *width = CAMERA_FEATURE_IMAGE_SIZE_M_WIDTH;
    *height = CAMERA_FEATURE_IMAGE_SIZE_M_HEIGHT;
#elif defined(__CAMERA_FEATURE_IMAGE_SIZE_S__)
    *width = CAMERA_FEATURE_IMAGE_SIZE_S_WIDTH;
    *height = CAMERA_FEATURE_IMAGE_SIZE_S_HEIGHT;
#elif defined(__CAMERA_FEATURE_IMAGE_SIZE_SS__)
    *width = CAMERA_FEATURE_IMAGE_SIZE_SS_WIDTH;
    *height = CAMERA_FEATURE_IMAGE_SIZE_SS_HEIGHT;
#else
#error "please check setting of mmi_features_camera.h" 
#endif
}


#if defined(__MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__)
/*****************************************************************************
* FUNCTION
*  mmi_camera_restart_app_watchdog
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_camera_restart_app_watchdog(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_camera_app_watchdog_callback);
    g_camera_cntx.app_timer_count = 0;
    gui_start_timer(MMI_CAMERA_APP_POLLING_DURATION,mmi_camera_app_watchdog_callback);
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_stop_app_watchdog
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_camera_stop_app_watchdog(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_camera_app_watchdog_callback);
    g_camera_cntx.app_timer_count = 0;
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_app_watchdog_callback
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_camera_app_watchdog_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.app_timer_count += MMI_CAMERA_APP_POLLING_DURATION;
    
    if (g_camera_cntx.app_timer_count < MMI_CAMERA_APP_WATCHDOG_DURATION)
    {
        gui_start_timer(MMI_CAMERA_APP_POLLING_DURATION, mmi_camera_app_watchdog_callback);        
    }
    else
    {
        GoBackHistory();
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_start_delete_confirm_watchdog
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_camera_start_delete_confirm_watchdog(void)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.delete_confirm_timer_count = 0;
    gui_start_timer(MMI_CAMERA_APP_POLLING_DURATION,mmi_camera_delete_confirm_watchdog_timer_callback);
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_delete_confirm_watchdog_timer_callback
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_camera_delete_confirm_watchdog_timer_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_camera_cntx.delete_confirm_timer_count += MMI_CAMERA_DELETE_CONFIRM_POLLING_DURATION ;
    
    if (g_camera_cntx.delete_confirm_timer_count < MMI_CAMERA_DELETE_CONFIRM_WATCHDOG_DURATION )
    {
        gui_start_timer(MMI_CAMERA_DELETE_CONFIRM_POLLING_DURATION , mmi_camera_delete_confirm_watchdog_timer_callback);        
    }
    else
    {
        if (g_camera_cntx.external_request_mode == MMI_CAMERA_EXTERNAL_MODE_OFF)
        {
#if defined(__MMI_CAMERA_BG_CALL__)
            if (mmi_ucm_is_background_call() == TRUE)
            {
                g_camera_cntx.last_error = MDI_RES_CAMERA_SUCCEED;
                EntryNewScreen(SCR_ID_CAMERA_END, NULL, NULL, NULL);
                GoBackHistory();
                return;
            }
#endif
            CAMERA_ENTER_STATE(CAMERA_STATE_PREVIEW);
        }
        else 
        {
            /* for External Request */
            g_camera_cntx.callback_ptr(MMI_TRUE,g_camera_cntx.captured_filepath);
            GoBackHistory();
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_stop_delete_confirm_watchdog
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_camera_stop_delete_confirm_watchdog(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_camera_delete_confirm_watchdog_timer_callback);
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_start_watchdog_by_kbd
* DESCRIPTION
*  start watchdog
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_start_all_watchdog(void)
{
    mmi_camera_restart_app_watchdog();
    if (g_camera_cntx.app_state == CAMERA_STATE_DELETE_CONFIRM)
    {
        mmi_camera_start_delete_confirm_watchdog();
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_stop_all_watchdog
* DESCRIPTION
*  stop watchdog
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_stop_all_watchdog(void)
{
    mmi_camera_stop_app_watchdog();
    mmi_camera_stop_delete_confirm_watchdog();
}
#endif /* __MMI_CAMERA_FEATURE_WATCHDOG_TIMEOUT__ */


#if defined(__MMI_CAMERA_RECORDER_ONE_KEY_TOGGLE__)
/*****************************************************************************
* FUNCTION
*  mmi_camera_switch_to_vdorec_app
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_camera_switch_to_vdorec_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_CAMERA_OPTION,NULL,NULL,NULL);
    DeleteUptoScrID(SCR_ID_CAMERA_APP);
    DeleteScreenIfPresent(SCR_ID_CAMERA_APP);
    
    mmi_vdorec_entry_app();
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_highlight_to_vdorec_app
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_camera_highlight_to_vdorec_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_camera_switch_to_vdorec_app, KEY_EVENT_UP);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_camera_switch_to_vdorec_app, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
}
#endif /* _MMI_CAMERA_RECORDER_ONE_KEY_TOGGLE__ */


/*****************************************************************************
* FUNCTION
*  mmi_camera_reentry_preview_state
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_camera_reentry_preview_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_camera_cntx.external_request_mode == MMI_CAMERA_EXTERNAL_MODE_OFF)
    {
        CAMERA_ENTER_STATE(CAMERA_STATE_PREVIEW);
    }
    ClearKeyEvents();    
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_reset_osd_layer
* DESCRIPTION
*  this api is used in delete confirm state to reset osdlayer to correct state.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_camera_reset_osd_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__)
    /* reset osd layer, using single osd layer when in delete confirm state. */
    g_camera_cntx.is_single_osd_layer = TRUE;
    g_camera_cntx.previous_osd_rotate = CAMERA_DISPLAY_ROTATE_RESET;
    mmi_camera_free_osd_layer();
    mmi_camera_create_osd_layer();
#else
    
    if (g_camera_cntx.osd_layer_buf_ptr0 == NULL )
    {
        
        g_camera_cntx.osd_layer_buf_ptr0 = mmi_frm_scrmem_alloc_framebuffer(CAMERA_OSD_BUFFER_SIZE);
        ASSERT(g_camera_cntx.osd_layer_buf_ptr0 != NULL);
    }
    
    /*currently in order to save memory, we will steal GDI memory, 
    NOTE : we only use the memory, but do not use the handle */
    if (g_camera_cntx.gdi_layer_handle == GDI_NULL_HANDLE)
    {
        gdi_layer_create(
            0,
            0,
            LCD_WIDTH,
            LCD_HEIGHT,
            &g_camera_cntx.gdi_layer_handle);
        gdi_layer_push_and_set_active(g_camera_cntx.gdi_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_get_buffer_ptr(&g_camera_cntx.gdi_layer_buffer_ptr);
        gdi_layer_pop_and_restore_active();
    }
    /* steal done */

    if (g_camera_cntx.osd_layer_handle0 == GDI_NULL_HANDLE)
    {        
        gdi_layer_create_cf_double_using_outside_memory(
            GDI_COLOR_FORMAT_16,
            0,
            0,
            LCD_WIDTH,
            LCD_HEIGHT,
            &g_camera_cntx.osd_layer_handle0,
            (PU8) g_camera_cntx.osd_layer_buf_ptr0,
            (S32) CAMERA_OSD_BUFFER_SIZE,
            (PU8) g_camera_cntx.gdi_layer_buffer_ptr, 
            (S32) CAMERA_OSD_BUFFER_SIZE);

        gdi_layer_push_and_set_active(g_camera_cntx.osd_layer_handle0);
        gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();
    }
#endif /* #if defined(__MMI_CAMERA_5_OSD_LAYER__) || defined(__MMI_CAMERA_3_OSD_LAYER__) */
    
#if defined(__CAMERA_OSD_HORIZONTAL__)
    mmi_camera_check_osd_orientation();
#endif
    
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_reset_base_layer
* DESCRIPTION
*  this api is used in delete confirm state to reset baselayer to correct state.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_camera_reset_base_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
#if defined(__CAMERA_OSD_HORIZONTAL__)
    gdi_layer_push_and_set_active(g_camera_cntx.base_layer_handle);
    if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_0)
    {
        gdi_layer_resize(LCD_WIDTH, LCD_HEIGHT);
        gdi_layer_set_rotate(GDI_LAYER_ROTATE_0);
        gdi_layer_clear_background(GDI_COLOR_BLACK);
        gdi_layer_set_active(g_camera_cntx.osd_layer_handle0);
        gdi_layer_set_rotate(GDI_LAYER_ROTATE_0);
    }
    else if (g_camera_cntx.osd_rotate == CAMERA_DISPLAY_ROTATE_270)
    {
        gdi_layer_resize(LCD_HEIGHT, LCD_WIDTH);
        gdi_layer_set_rotate(GDI_LAYER_ROTATE_90);
        
#if !MDI_CAMERA_MT6228_SERIES    
        gdi_layer_clear_background(GDI_COLOR_BLACK);
#endif        
    }
    gdi_layer_pop_and_restore_active();
#else /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
#if !MDI_CAMERA_MT6228_SERIES
    gdi_layer_push_and_set_active(g_camera_cntx.base_layer_handle);
    gdi_layer_clear_background(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();
#endif
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_delete_file
* DESCRIPTION
*  This function is delete captured image
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_camera_delete_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_check;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_camera_cntx.is_tileshot)
    {
        MMI_ASSERT(0);
    }
    else
    {
        /* ENTER EXIT STATE */
        g_camera_cntx.app_state = CAMERA_STATE_EXIT;
        
        file_check = FS_Delete((U16*) g_camera_cntx.captured_filepath);
        mmi_camera_restore_filename_seq_no();
        
        if (file_check != FS_NO_ERROR)
        {
            MMI_ID_TYPE str_id;
            
            str_id = GetFileSystemErrorString(file_check);
            MMI_CAMERA_DISPLAY_POPUP(GetString(str_id), MMI_EVENT_FAILURE);
            
            return;
        }
        else
        {
            MMI_CAMERA_DISPLAY_POPUP(GetString(STR_GLOBAL_DELETED), MMI_EVENT_SUCCESS);
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_camera_delete_confirm_option_cmd_hdlr
* DESCRIPTION
*  This function is the menu item handler for cascading menu.
* PARAMETERS
*  menu_id         [IN]        Menu ID
* RETURNS
*  MMI_TRUE if the command is handled; otherwise, MMI_FALSE to follow the 
*  cascading menu rule.
*****************************************************************************/
static MMI_BOOL mmi_camera_delete_confirm_option_cmd_hdlr(U16 menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_id)
    {
    case MENU_ID_CAMERA_FORWARD_OPTION:
        return MMI_FALSE;            
#if defined(__MMI_PHOTOEDITOR__)
    case MENU_ID_CAMERA_CONFIRM_OPTION_EDIT:
        mmi_phoart_entry_from_fmgr(g_camera_cntx.captured_filepath, FALSE);
        return MMI_TRUE;
#endif /* __MMI_PHOTOEDITOR__ */
    case MENU_ID_CAMERA_CONFIRM_OPTION_DELETE:
#if defined(__MMI_SCREEN_ROTATE__)
        mmi_display_popup_confirm_rotated(
            get_string(STR_GLOBAL_YES),
            get_image(IMG_GLOBAL_YES),
            get_string(STR_GLOBAL_NO),
            get_image(IMG_GLOBAL_NO),
            get_string(STR_ID_CAMERA_DELETE_ASK),
            MMI_EVENT_QUERY,
            g_camera_cntx.osd_rotate);
#else /* __MMI_SCREEN_ROTATE__*/
        mmi_display_popup_confirm(
            get_string(STR_GLOBAL_YES),
            get_image(IMG_GLOBAL_YES),
            get_string(STR_GLOBAL_NO),
            get_image(IMG_GLOBAL_NO),
            get_string(STR_ID_CAMERA_DELETE_ASK),
            MMI_EVENT_QUERY);
#endif /* __MMI_SCREEN_ROTATE__ */
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetLeftSoftkeyFunction(mmi_camera_delete_file, KEY_EVENT_UP);                                  
        return MMI_TRUE;
    case MENU_ID_CAMERA_FORWARD_OPTION_TO_BT:
        g_camera_cntx.forward_to = MMI_CAMERA_FORWARD_TO_BT;
        mmi_camera_forward_to_hdlr();
        return MMI_TRUE;
        break;
    case MENU_ID_CAMERA_FORWARD_OPTION_TO_EMAIL:
        g_camera_cntx.forward_to = MMI_CAMERA_FORWARD_TO_EMAIL;
        mmi_camera_forward_to_hdlr();
        return MMI_TRUE;
        break;
    case MENU_ID_CAMERA_FORWARD_OPTION_TO_MMS:
        g_camera_cntx.forward_to = MMI_CAMERA_FORWARD_TO_MMS;
        mmi_camera_forward_to_hdlr();
        return MMI_TRUE;
        break;
    case MENU_ID_CAMERA_FORWARD_OPTION_TO_POSTCARD:
        g_camera_cntx.forward_to = MMI_CAMERA_FORWARD_TO_POSTCARD;
        mmi_camera_forward_to_hdlr();
        return MMI_TRUE;
        break;
    default:
        break;
    }
    
    return MMI_FALSE;
}


#ifndef GDI_USING_2D_ENGINE_V3 
/*****************************************************************************
* FUNCTION
*  mmi_camera_sw_rotate
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  
*****************************************************************************/
void mmi_camera_sw_rotate(
                          U8* pDst,
                          U8* pSrc,
                          U32 const src_width,
                          U32 const src_height)
{
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

        SWROT_ROTATE_ANGLE_ENUM rotate_angle;   
        SWROT_RETURN_CODE_ENUM ret;             
        swrot_rotate_handle_struct swrot_handle;

        rotate_angle = SWROT_ROTATE_ANGLE_090; 
        MMI_CAMERA_START_MEASURE("SWR");
        ret = swrot_initialize(&swrot_handle);
        ret = swrot_set_src_color_format(&swrot_handle, SWROT_COLOR_FORMAT_RGB565, SWROT_BLOCK_SIZE_0);
        ret = swrot_set_dst_color_format(&swrot_handle, SWROT_COLOR_FORMAT_RGB565, SWROT_BLOCK_SIZE_0);
        ret = swrot_set_rotate_angle(&swrot_handle, rotate_angle);
        ret = swrot_set_src_info(&swrot_handle, (void*)pSrc, (void*)NULL, (void*)NULL, src_width);
        ret = swrot_set_src_rect(&swrot_handle, 0, 0, (kal_uint32)src_width, (kal_uint32)src_height);
        ret = swrot_set_dst_info(&swrot_handle, (void*)pDst, (void*)NULL, (void*)NULL, src_height);
        ret = swrot_set_dst_rect(&swrot_handle, 0, 0, (kal_uint32)src_height, (kal_uint32)src_width); 
        ret = swrot_set_working_buffer(&swrot_handle, (void*)NULL, (kal_uint32)NULL);
        ret = swrot_rotate(&swrot_handle);
        MMI_CAMERA_STOP_MEASURE("SWR");
 
}

#endif


/*****************************************************************************
* FUNCTION
*  mmi_camera_save_profiling_log
* DESCRIPTION
*  EM save capture profiling log
* PARAMETERS
*  
* RETURNS
*  
*****************************************************************************/
#if defined(__MTK_INTERNAL__)// && defined(__MTK_TARGET__)
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
/* under construction !*/
#endif

#endif /* defined(__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__) */ 

