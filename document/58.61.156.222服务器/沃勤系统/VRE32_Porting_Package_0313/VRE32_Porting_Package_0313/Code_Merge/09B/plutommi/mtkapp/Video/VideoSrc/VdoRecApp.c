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
 *   VdoRecApp.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Video Recorder Applcation.
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
#include "MMI_include.h"
#ifndef _MMI_VDORECAPP_C
#define _MMI_VDORECAPP_C

#if defined(__MMI_VIDEO_RECORDER__) && !defined(__MMI_CAMCORDER__)

#include "lcd_sw_rnd.h"
#include "MMI_features_video.h" /* features */

/* framework related headers */

#include "SettingDefs.h"        /* ST_NOTIFYDURATION define */
#include "gpioInc.h"    /* LED */
#include "IdleAppProt.h"        /* for IsIdleArrived() */
#include "CommonScreens.h"      /* Popup */
#include "ProtocolEvents.h"     /* Interrupt message ID */
#include "MainMenuDef.h"        /* Multi-media icon */
#include "CallManagementGProt.h"        /* CM releated */

#include "wgui_status_icons.h"  /* status UI */
#include "wgui_softkeys.h"      /* softkey */

#include "FileManagerGProt.h"   /* file path / file error  */
#include "FileManagerDef.h"     /* file error text */
#include "FileMgr.h"
#include "mmiapi_enum.h"        /* Stop LED */
#include "USBDeviceGprot.h"     /* USB MS mode */
#include "AlarmFrameworkProt.h" /* alarm framework */
#include "DataAccountGprot.h"
#include "SimDetectionGprot.h"  /* flight mode */

/* gdi, mid, video rec headers */
#include "lcd_if.h"
#include "lcd_sw_rnd.h"
#include "mdi_datatype.h"
#include "mdi_include.h"
#include "mdi_video.h"  /* mdi video library */

#ifdef __VDOREC_COLOR_IDX_FRAME__
#include "imgdma.h"
#include "mdi_camera.h"
#endif /* __VDOREC_COLOR_IDX_FRAME__ */ 

#ifdef __VDOREC_FEATURE_TOUCH_SCREEN__
#endif 

#ifdef __MMI_VDOREC_MMS_SUPPORT__
#include "WapProt.h"
#endif 

#include "ConnectManageGProt.h"

/* video recoder related */
#include "resource_video_skins.h"       /* UI custom config */

#include "VdoRecResDef.h"
#include "VdoPlyResDef.h"
#include "VdoRecApp.h"
#include "VdoPlyApp.h"
#include "VdoRecGProt.h"
#include "VdoPlyGProt.h"        /* entry function */

#ifdef __MMI_MMS__
#include "wapadp.h"
#include "mmsadp.h"
#endif 

#ifdef __MMI_TVOUT__
#include "mdi_tv.h"
#endif 

#if defined(__MMI_BT_MTK_SUPPORT__) && defined(__MMI_FTS_SUPPORT__)
#include "BTMMICm.h"
#include "BTMMIFtpGprots.h"
#endif /* __MMI_BT_MTK_SUPPORT__ && __MMI_FTS_SUPPORT__ */ 

#if defined(__MMI_BT_MTK_SUPPORT__) || defined(__MMI_OPP_SUPPORT__)
#include "BTMMICm.h"
#include "BTMMIOppGprots.h"
#include "OPPMMIGprots.h"
#endif /* __MMI_BT_MTK_SUPPORT__ || __MMI_OPP_SUPPORT__ */ 

#include "BTMMIScrGprots.h"
#include "BTMMIObexGprots.h"

#ifdef __DIRECT_SENSOR_SUPPORT__
#include "image_sensor.h"
#endif 

#ifdef __MMI_CAMERA__
#include "mdi_camera.h"
#include "CameraApp.h"
#endif

#ifdef __MMI_EMAIL__
#include "EmailAppGProt.h"
#endif

#ifdef __VDOREC_FEATURE_CALL_ACCEPT_OPTION__
#include "managecallmain.h"
#endif 

/* detect fly mode */
#include "SimDetectionGprot.h"

#ifdef __MMI_UCM__
#include "UCMGProt.h"
#endif /* __MMI_UCM__ */


#include "ProfileGprots.h"

#ifdef __MMI_OP01_DCD__
extern void mmi_dcd_line_taken(void);
extern void mmi_dcd_line_given(void);
extern MMI_BOOL mmi_dcd_is_syncing(void);
extern void mmi_dcd_running_conflict_prompt(void);
#endif

/***************************************************************************** 
* Define
*****************************************************************************/
#define DUMMY_COMMAND               (0)
#define HINT_POPUP_FADE_TIME        (2000)

#if defined(__MDI_VIDEO_HW_ROTATOR_SUPPORT__) && defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__)
#define __VDOREC_ROTATE_OSD_FOR_HW_ROTATOR__
#endif

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/
extern wgui_inline_item wgui_inline_items[];
extern BOOL r2lMMIFlag;

/****************************************************************************
* Global Function                                                           
*****************************************************************************/
extern void custom_start_flashlight(kal_uint8 red_level, kal_uint8 green_level, kal_uint8 blue_level, kal_uint8 duty);
extern void custom_stop_flashlight(void);
extern kal_uint8 GpioCtrlReq(kal_uint8 action);
extern void AudioStopReq(U16 soundId);
extern U16 GetCurKeypadTone(void);
extern void refresh_status_icon_display(void);  /* in Wgui_status_icons.c */

/***************************************************************************** 
* Local Variable
*****************************************************************************/
vdorec_context_struct g_vdorec_cntx;
vdorec_menu_context_struct g_vdorec_menu_cntx;
U8 g_vdorec_feature_zoom[] = 
   {10,11,12,13,14,15,16,17,18,19,
	20,21,22,23,24,25,26,27,28,29,
	30,31,32,33,34,35,36,37,38,39,
	40,41,42,43,44,45,46,47,48,49,
	50,51,52,53,54,55,56,57,58,59,
	60,61,62,63,64,65,66,67,68,69,
	70,71,72,73,74,75,76,77,78,79,80};

/***************************************************************************** 
* Local Function
*****************************************************************************/

/* app */
static void mmi_vdorec_blt_screen(void);
static void mmi_vdorec_restore_setting(void);
static void mmi_vdorec_get_save_filename(S8 *file_buf_p);
static void mmi_vdorec_disply_popup(PU8 str_ptr, S32 eventy_type);

/* preview */
static BOOL mmi_vdorec_check_and_display_error_popup(void);

#ifdef __VDOREC_FEATURE_VIDEO_SIZE__
static void mmi_vdorec_resize_preview_layer(void);
#endif 

static void mmi_vdorec_get_video_size(S32 *video_width, S32 *video_height);
static U16 mmi_vdorec_get_zoom_factor(void);
static void mmi_vdorec_lsk_press_hdlr(void);
static void mmi_vdorec_lsk_release_hdlr(void);
static void mmi_vdorec_rsk_press_hdlr(void);
static void mmi_vdorec_rsk_release_hdlr(void);
static void mmi_vdorec_ck_press_hdlr(void);
static void mmi_vdorec_ck_release_hdlr(void);

#ifdef __VDOREC_FEATURE_EV__
static void mmi_vdorec_inc_ev_key_press_hdlr(void);
static void mmi_vdorec_inc_ev_key_release_hdlr(void);
static void mmi_vdorec_dec_ev_key_press_hdlr(void);
static void mmi_vdorec_dec_ev_key_release_hdlr(void);
#endif /* __VDOREC_FEATURE_EV__ */

#ifdef __VDOREC_FEATURE_ZOOM__
static void mmi_vdorec_zoom_in(void);
static void mmi_vdorec_zoom_in_key_press_hdlr(void);
static void mmi_vdorec_zoom_in_key_release_hdlr(void);
static void mmi_vdorec_zoom_out(void);
static void mmi_vdorec_zoom_out_key_press_hdlr(void);
static void mmi_vdorec_zoom_out_key_release_hdlr(void);
#endif /* __VDOREC_FEATURE_ZOOM__ */ 

static void mmi_vdorec_turn_on_led_highlight(void);
static void mmi_vdorec_turn_off_led_highlight(void);
static void mmi_vdorec_record_result_hdlr_callback(MDI_RESULT result);

#ifdef __VDOREC_FEATURE_VIDEO_SIZE__
static void mmi_vdorec_video_size_hotkey_press(void);
#endif

#ifdef __VDOREC_FEATURE_VIDEO_QTY__
static void mmi_vdorec_video_qty_hotkey_press(void);
#endif

#ifdef __VDOREC_FEATURE_NIGHT__
static void mmi_vdorec_night_hotkey_press(void);
#endif 

#ifdef __VDOREC_FEATURE_WB__
static void mmi_vdorec_wb_hotkey_press(void);
#endif 

#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT__
static void mmi_vdorec_led_highlight_hotkey_press(void);
#endif 

#ifdef __VDOREC_FEATURE_RECORD_AUD__
static void mmi_vdorec_record_aud_hotkey_press(void);
#endif 

static void mmi_vdorec_start_preview(void);
static void mmi_vdorec_enter_state(U16 state);


#if defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__)
static U8 mmi_vdorec_clam_close_event_hdlr(mmi_frm_int_event_type interrupt_event);
#endif 

static void mmi_vdorec_entry_app_internal(void);
static void mmi_vdorec_exit_app(void);

#ifdef __MMI_SUBLCD__
static void mmi_vdorec_draw_sublcd_icon(void);
static void mmi_vdorec_entry_sublcd_screen(void);
static void mmi_vdorec_exit_sublcd_screen(void);
#endif /* __MMI_SUBLCD__ */ 

static void mmi_vdorec_record_timer_cyclic(void);
static void mmi_vdorec_draw_bg_image(void);
static void mmi_vdorec_draw_bg_color(void);
static void mmi_vdorec_draw_title(void);
static void mmi_vdorec_draw_status(void);
static void mmi_vdorec_draw_softkey(void);
static void mmi_vdorec_set_softkey(PS8 lsk_str_ptr, PS8 rsk_str_ptr, U16 lsk_img_id, U16 rsk_img_id, U16 ck_img_id);
static void mmi_vdorec_draw_panel_state(void);

static void mmi_vdorec_draw_panel_ev(void);

static void mmi_vdorec_draw_panel_zoom(void);

static void mmi_vdorec_draw_panel_timer(void);
static void mmi_vdorec_init_ui(void);
static void mmi_vdorec_draw_style_text(PS8 str, S32 offset_x, S32 offset_y, S32 truncate_width, video_style_text_struct *style_txt);
static void mmi_vdorec_hide_hint(void);
static void mmi_vdorec_draw_hint(void);
static void mmi_vdorec_set_hint(PS8 hint_str1, PS8 hint_str2, U16 fade_time);
static void mmi_vdorec_draw_osd(U32 component);

/* save */
static void mmi_vdorec_save_confirm_no(void);
static void mmi_vdorec_entry_save_confirm_screen(void);

static void mmi_vdorec_save_confirm_forward_to(void);
static void mmi_vdorec_save_result_hdlr_callback(MDI_RESULT result);
static void mmi_vdorec_exit_saving_screen(void);
static U8 mmi_vdorec_saving_screen_del_hdlr(void *dummy_ptr);
static void mmi_vdorec_entry_saving_screen(void);

/* menu */
static void mmi_vdorec_entry_option_screen(void);
static void mmi_vdorec_camcoder_setting_lsk_press(void);
static void mmi_vdorec_camcoder_setting_highlight_hdlr(S32 index);
static void mmi_vdorec_exit_camcoder_setting_screen(void);
static void mmi_vdorec_entry_camcoder_setting_screen(void);

#ifndef __VDOREC_FEATURE_MERGE_MENU__
static void mmi_vdorec_video_setting_lsk_press(void);
static void mmi_vdorec_video_setting_highlight_hdlr(S32 index);
static void mmi_vdorec_exit_video_setting_screen(void);
static void mmi_vdorec_entry_video_setting_screen(void);
#endif /* __VDOREC_FEATURE_MERGE_MENU__ */ 

static void mmi_vdorec_set_effect_setting_value(void);
static void mmi_vdorec_entry_effect_setting_screen(void);

#ifdef __VDOREC_COLOR_IDX_FRAME__
static void mmi_vdorec_color_idx_frame_highlight_hdlr(S32 idx);
static void mmi_vdorec_entry_color_idx_frame_view_screen(void);
static void mmi_vdorec_color_idx_frame_goto_previous_frame(void);
static void mmi_vdorec_color_idx_frame_goto_next_frame(void);
static void mmi_vdorec_set_color_idx_frame_value(void);
static void mmi_vdorec_entry_color_idx_frame_screen(void);
static void mmi_vdorec_draw_color_idx_frame(void);
static void mmi_vdorec_preview_change_frame_down(void);
static void mmi_vdorec_preview_change_frame_up(void);
#endif /* __VDOREC_COLOR_IDX_FRAME__ */ 

#ifdef __VDOREC_FEATURE_STORAGE__
static void mmi_vdorec_entry_set_storage_screen(void);
static void mmi_vdorec_entry_set_app_storage_screen(void);
static void mmi_vdorec_entry_set_storage_screen_internal(void);
static void mmi_vdorec_set_storage_lsk_hdlr(void);
static void mmi_vdorec_set_storage_rsk_hdlr(void);
static void mmi_vdorec_storage_highlight_handler(S32 index);
#endif /* __VDOREC_FEATURE_STORAGE__ */ 

static void mmi_vdorec_entry_restore_default_confirm_yes(void);
static void mmi_vdorec_entry_restore_default_confirm_screen(void);

#if defined(__VDOREC_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_vdorec_touch_scr_pen_down_hdlr(mmi_pen_point_struct pos);
static void mmi_vdorec_touch_scr_pen_up_hdlr(mmi_pen_point_struct pos);
static void mmi_vdorec_touch_scr_pen_move_hdlr(mmi_pen_point_struct pos);
static BOOL mmi_vdorec_touch_scr_hit_test(S32 pos_x, S32 pos_y, vdorec_ui_touch_struct *touch_obj);
#endif /* defined(__VDOREC_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__) */ /* __VDOREC_FEATURE_TOUCH_SCREEN__ & __MMI_TOUCH_SCREEN__ */

#ifdef __VDOREC_FEATURE_SWITCH_TO_CAMERA__
void mmi_vdorec_highlight_to_camera(void);
void mmi_vdorec_switch_to_camera_hdlr(void);
#endif /* __VDOREC_FEATURE_SWITCH_TO_CAMERA__ */

#ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__

void mmi_vdorec_highlight_delete(void);

#ifdef __MMI_VDOREC_MMS_SUPPORT__
void mmi_vdorec_highlight_to_mms(void);
#endif


void mmi_vdorec_highlight_to_email(void);


void mmi_vdorec_highlight_send(void);

#ifdef __VDOREC_FEATURE_RSK_DELETE__
void mmi_vdorec_highlight_continue(void);
#endif
#ifdef __MMI_BT_SEND_SUPPORT__
void mmi_vdorec_highlight_to_bluetooth(void);
#endif 

void mmi_vdorec_entry_preview_option_screen(void);
void mmi_vdorec_entry_preview_video_screen(void);
void mmi_vdorec_fsm_preview_stop(void);
void mmi_vdorec_fsm_preview_play(void);
void mmi_vdorec_play_timer_cyclic(void);
void mmi_vdorec_delete_saved_vdo_confirm(void);
void mmi_vdorec_del_key_press_hdlr(void);
void mmi_vdorec_del_key_release_hdlr(void);
void mmi_vdorec_preview_idle_timeout_hdlr(void);
U8 mmi_vdorec_preview_idle_timeout_cancel(KEYBRD_MESSAGE *eventKey);
#endif /* __VDOREC_FEATURE_PREVIEW_SAVED_FILE__ */
void mmi_vdorec_hide_unaviailable_send_options(void);
void mmi_vdorec_entry_send_screen(void);
void mmi_vdorec_load_saved_filename(PS8 filepath);

static void mmi_vdorec_draw_panel_progress_bar(U8 ratio);
static void mmi_vdorec_clear_panel_progress_bar(void);
static void mmi_vdorec_update_progress_ratio(void);
static BOOL mmi_vdorec_is_draw_progress_bar(void);

BOOL mmi_vdorec_is_in_bgcall(void);

/*init variable of compile option*/
static void mmi_vdorec_init_according_to_compile_option(void);

/*fast zoom related function*/
static void mmi_vdorec_draw_zoom_osd(void);
#if 1 /*this is for smooth zoom ,currently not support, but 38 chi will support*/
static U16  mmi_vdorec_get_zoom_level_idx(S32 factor);
#endif
static void mmi_vdorec_start_fast_zoom_in(void);
static void mmi_vdorec_start_fast_zoom_out(void);
static void mmi_vdorec_stop_fast_zoom(void);
static void mmi_vdorec_merge_blt_rgn(S32 x, S32 y, S32 w, S32 h);
static void mmi_vdorec_set_merge_region(S32 x, S32 y, S32 w, S32 h);

static U8 mmi_vdorec_pre_key_listen_hdlr(KEYBRD_MESSAGE *key_msg);
static U8 mmi_vdorec_post_key_listen_hdlr(KEYBRD_MESSAGE *key_msg);
static void mmi_vdorec_reset_watchdog_time_out_handler(void);
static void mmi_vdorec_watchdog_time_out_handler(void);
static MMI_BOOL mmi_vdorec_malloc_app_mem(void);
static void mmi_vdorec_free_app_mem(void);

/****************************************************************************
* Setting command map                                                                
*****************************************************************************/

/*********** WB ***********/
const U8 vdorec_wb_command_map[VDOREC_SETTING_WB_COUNT + 1] = 
{
#ifdef __VDOREC_FEATURE_WB_AUTO__
    MDI_VIDEO_WB_AUTO,  /* CAMREA_SETTING_WB_AUTO */
#endif 

#ifdef __VDOREC_FEATURE_WB_DAYLIGHT__
    MDI_VIDEO_WB_DAYLIGHT,  /* VDOREC_SETTING_WB_DAYLIGHT */
#endif 

#ifdef __VDOREC_FEATURE_WB_TUNGSTEN__
    MDI_VIDEO_WB_TUNGSTEN,  /* VDOREC_SETTING_WB_TUNGSTEN */
#endif 

#ifdef __VDOREC_FEATURE_WB_FLUORESCENT__
    MDI_VIDEO_WB_FLUORESCENT,   /* VDOREC_SETTING_WB_FLUORESCENT */
#endif 

#ifdef __VDOREC_FEATURE_WB_CLOUD__
    MDI_VIDEO_WB_CLOUD, /* VDOREC_SETTING_WB_CLOUD */
#endif 

#ifdef __VDOREC_FEATURE_WB_INCANDESCENCE__
    MDI_VIDEO_WB_INCANDESCENCE, /* VDOREC_SETTING_WB_INCANDESCENCE */
#endif 

    DUMMY_COMMAND
};

/*********** EV ***********/
const U8 vdorec_ev_command_map[VDOREC_SETTING_EV_COUNT + 1] = 
{
#ifdef __VDOREC_FEATURE_EV_4__
    MDI_VIDEO_EV_N4,    /* VDOREC_SETTING_EV_N4 */
#endif 

#ifdef __VDOREC_FEATURE_EV_3__
    MDI_VIDEO_EV_N3,    /* VDOREC_SETTING_EV_N3 */
#endif 

#ifdef __VDOREC_FEATURE_EV_2__
    MDI_VIDEO_EV_N2,    /* VDOREC_SETTING_EV_N2 */
#endif 

    MDI_VIDEO_EV_N1,    /* VDOREC_SETTING_EV_N1 */
    MDI_VIDEO_EV_0,     /* VDOREC_SETTING_EV_0 */
    MDI_VIDEO_EV_P1,    /* VDOREC_SETTING_EV_P1 */

#ifdef __VDOREC_FEATURE_EV_2__
    MDI_VIDEO_EV_P2,    /* VDOREC_SETTING_EV_P2 */
#endif 

#ifdef __VDOREC_FEATURE_EV_3__
    MDI_VIDEO_EV_P3,    /* VDOREC_SETTING_EV_P3 */
#endif 

#ifdef __VDOREC_FEATURE_EV_4__
    MDI_VIDEO_EV_P4,    /* VDOREC_SETTING_EV_P4 */
#endif 

    DUMMY_COMMAND
};

/*********** Banding ***********/
const U8 vdorec_banding_command_map[VDOREC_SETTING_BANDING_COUNT + 1] = 
{
    MDI_VIDEO_BANDING_50HZ,
    MDI_VIDEO_BANDING_60HZ,

    DUMMY_COMMAND
};

/*********** EFFECT ***********/
const U8 vdorec_effect_command_map[VDOREC_SETTING_EFFECT_COUNT + 1] = 
{
#ifdef __VDOREC_FEATURE_EFFECT_NORMAL__
    MDI_VIDEO_EFFECT_NOMRAL,
#endif 

#ifdef __VDOREC_FEATURE_EFFECT_GRAYSCALE__
    MDI_VIDEO_EFFECT_GRAYSCALE,
#endif 

#ifdef __VDOREC_FEATURE_EFFECT_SEPIA__
    MDI_VIDEO_EFFECT_SEPIA,
#endif 

#ifdef __VDOREC_FEATURE_EFFECT_SEPIA_GREEN__
    MDI_VIDEO_EFFECT_SEPIA_GREEN,
#endif 

#ifdef __VDOREC_FEATURE_EFFECT_SEPIA_BLUE__
    MDI_VIDEO_EFFECT_SEPIA_BLUE,
#endif 

#ifdef __VDOREC_FEATURE_EFFECT_COLOR_INVERT__
    MDI_VIDEO_EFFECT_COLOR_INVERT,
#endif 

#ifdef __VDOREC_FEATURE_EFFECT_GRAY_INVERT__
    MDI_VIDEO_EFFECT_GRAY_INVERT,
#endif 

#ifdef __VDOREC_FEATURE_EFFECT_BLACKBOARD__
    MDI_VIDEO_EFFECT_BLACKBOARD,
#endif 

#ifdef __VDOREC_FEATURE_EFFECT_WHITEBOARD__
    MDI_VIDEO_EFFECT_WHITEBOARD,
#endif 

#ifdef __VDOREC_FEATURE_EFFECT_COPPER_CARVING__
    MDI_VIDEO_EFFECT_COPPER_CARVING,
#endif 

#ifdef __VDOREC_FEATURE_EFFECT_BLUE_CARVING__
    MDI_VIDEO_EFFECT_BLUE_CARVING,
#endif 

#ifdef __VDOREC_FEATURE_EFFECT_EMBOSSMENT__
    MDI_VIDEO_EFFECT_EMBOSSMENT,
#endif 

#ifdef __VDOREC_FEATURE_EFFECT_CONTRAST__
    MDI_VIDEO_EFFECT_CONTRAST,
#endif 

#ifdef __VDOREC_FEATURE_EFFECT_JEAN__
    MDI_VIDEO_EFFECT_JEAN,
#endif 

#ifdef __VDOREC_FEATURE_EFFECT_SKETCH__
    MDI_VIDEO_EFFECT_SKETCH,
#endif 

#ifdef __VDOREC_FEATURE_EFFECT_OIL__
    MDI_VIDEO_EFFECT_OIL,
#endif 

    DUMMY_COMMAND
};

#if defined(MDI_VIDEO_MT6228_SERIES)

   /*********** Video Size ***********/
const U8 vdorec_video_size_command_map[VDOREC_SETTING_VIDEO_SIZE_COUNT + 1] = 
{
#ifdef __VDOREC_FEATURE_VIDEO_SIZE_SQCIF__
    MDI_VIDEO_VIDEO_SIZE_SQCIF,
#endif 

#ifdef __VDOREC_FEATURE_VIDEO_SIZE_QQVGA__
    MDI_VIDEO_VIDEO_SIZE_QQVGA,
#endif 

#ifdef __VDOREC_FEATURE_VIDEO_SIZE_QCIF__
    MDI_VIDEO_VIDEO_SIZE_QCIF,
#endif 

#ifdef __VDOREC_FEATURE_VIDEO_SIZE_QVGA__
    MDI_VIDEO_VIDEO_SIZE_QVGA,
#endif 

#ifdef __VDOREC_FEATURE_VIDEO_SIZE_CIF__
    MDI_VIDEO_VIDEO_SIZE_CIF,
#endif 

    DUMMY_COMMAND
};

#else /* MDI_VIDEO_MT6228_SERIES */ 
   /* MT6219 and previous chip only support QCIF size */

   /*********** Video Size ***********/
const U8 vdorec_video_size_command_map[VDOREC_SETTING_VIDEO_SIZE_COUNT + 1] = 
{
    MDI_VIDEO_VIDEO_SIZE_QCIF,

#ifdef __VDOREC_FEATURE_VIDEO_SIZE_QVGA__
    MDI_VIDEO_VIDEO_SIZE_QVGA,
#endif 

    DUMMY_COMMAND
};
#endif /* MDI_VIDEO_MT6228_SERIES */ 

/*********** Video Qty ***********/
const U8 vdorec_video_qty_command_map[VDOREC_SETTING_VIDEO_QTY_COUNT + 1] = 
{
#ifdef __VDOREC_FEATURE_VIDEO_QTY_LOW__
    MDI_VIDEO_REC_QTY_LOW,
#endif 

#ifdef __VDOREC_FEATURE_VIDEO_QTY_NORMAL__
    MDI_VIDEO_REC_QTY_NORMAL,
#endif 

#ifdef __VDOREC_FEATURE_VIDEO_QTY_HIGH__
    MDI_VIDEO_REC_QTY_HIGH,
#endif 

#ifdef __VDOREC_FEATURE_VIDEO_QTY_FINE__
        MDI_VIDEO_REC_QTY_FINE,
#endif 

    DUMMY_COMMAND
};

/*********** Video Format ***********/
const U8 vdorec_video_format_command_map[VDOREC_SETTING_VIDEO_FORMAT_COUNT + 1] = 
{
    MDI_VIDEO_VIDEO_FORMAT_3GP,
    MDI_VIDEO_VIDEO_FORMAT_MP4,

    DUMMY_COMMAND
};

/*************time limit ************/
const U32 vdorec_video_time_limit_command_map[VDOREC_SETTING_TIME_LIMIT_COUNT + 1] = 
{
    0,                              /* no limit */
    VDOREC_FEATURE_TIME_LIMIT_1,
    VDOREC_FEATURE_TIME_LIMIT_2,
    VDOREC_FEATURE_TIME_LIMIT_3,
    
    DUMMY_COMMAND
};

/*************size limit ************/
const U32 vdorec_video_size_limit_command_map[VDOREC_SETTING_SIZE_LIMIT_COUNT + 1] = 
{
    0,                              /* no limit */
    VDOREC_FEATURE_SIZE_LIMIT_1,
    VDOREC_FEATURE_SIZE_LIMIT_2,
    VDOREC_FEATURE_SIZE_LIMIT_3,
    
    DUMMY_COMMAND
};

/*****************************************************************************
*
* Applcation Related
*
*****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_for_external_request
 * DESCRIPTION
 *  Entry video recorder and record a video with requested size 
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
void mmi_vdorec_entry_for_external_request(
        S8 *filepath, 
        U32 max_size,
        U32 max_time_sec,
        void (*result_callback)(MMI_BOOL result, S8 *filepath))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ENTRY_FROM_EXTERNAL, max_size, max_time_sec);
    MMI_ASSERT(result_callback != NULL);

#if defined(__MMI_BACKGROUND_CALL__)
    if (mmi_vdorec_is_in_bgcall())
    {
        mmi_ucm_app_entry_error_message();
        return;
    }
#endif /* __MMI_BACKGROUND_CALL__ */

    /* delete existing video recorder - avoid re-entry */
    for (scr_id = SCR_ID_VDOREC_APP; scr_id < SCR_ID_VDOREC_END; scr_id ++)
    {
        DeleteScreenIfPresent((U16)scr_id);
    }
    
#ifdef __VDOREC_ROTATE_OSD_FOR_HW_ROTATOR__
    if (g_vdorec_cntx.app_mem_bufer == NULL)
    {
        if (!mmi_vdorec_malloc_app_mem())
        {
            mmi_frm_appmem_prompt_to_release_mem(
                STR_ID_VDOREC_APP_NAME,
                IMG_ID_VDOREC_APP_ICON,
                VDOREC_APP_MEMORY_BUFFER_SIZE,
                mmi_vdorec_entry_app);
            return;
        }
    }
#endif

    mmi_vdorec_load_setting();    
    g_vdorec_cntx.ext_req_callback = result_callback;
    g_vdorec_cntx.is_ext_req = MMI_TRUE;
    g_vdorec_cntx.is_use_ext_req_path = MMI_FALSE;       
    g_vdorec_cntx.ext_req_size = max_size;
    g_vdorec_cntx.ext_rec_time = max_time_sec;

    /* video cant record so accurate */
    if (g_vdorec_cntx.ext_req_size < mmi_vdorec_get_min_external_request_size())
    {
        g_vdorec_cntx.ext_req_callback(MMI_FALSE, NULL);
        return;
    }

    if (filepath != NULL)
    {
        g_vdorec_cntx.is_use_ext_req_path = MMI_TRUE;        
        mmi_ucs2ncpy(g_vdorec_cntx.filepath, filepath, FMGR_PATH_BUFFER_SIZE);
    }

#if defined(__MMI_OP12_CAMERA_VDOREC_CUSTOMIZE__) && defined(__VDOREC_FEATURE_VIDEO_SIZE_SQCIF__)
    g_vdorec_cntx.ext_video_size = VDOREC_SETTING_VIDEO_SIZE_SQCIF;
    g_vdorec_cntx.old_video_size = g_vdorec_cntx.setting.video_size; /* store video size, store back after return */
#endif

#ifdef __VDOREC_FEATURE_CALL_ACCEPT_OPTION__
    g_vdorec_cntx.old_call_mode = FALSE;
#endif
    /* enter video recorder */
    mmi_vdorec_entry_app_internal();
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_get_min_external_request_size
 * DESCRIPTION
 *  get minal external request size (in K), reasonal size for 1 sec
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
U32 mmi_vdorec_get_min_external_request_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MJPG_ENCODE
    /* Motion JPEG */
    ret = 60;
#else
    /* MPEG4 */
    ret = 30;
#endif
    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_GET_MIN_EXTERNAL_SIZE, ret);
    return ret;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_is_in_app
 * DESCRIPTION
 *  is in video recorder app or not
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_vdorec_is_in_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL is_in_app = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (g_vdorec_cntx.state != VDOREC_STATE_EXIT)
    {
        is_in_app = TRUE;
    }
    else
    {
        is_in_app = FALSE;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_IS_IN_APP, is_in_app);
    return is_in_app;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_blt_screen
 * DESCRIPTION
 *  blt full screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_blt_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_BLT_SCREEN);

    if (g_vdorec_cntx.is_use_hw_rotate)
    {
        if (g_vdorec_cntx.osd_layer_region_count == VDOREC_OSD_LAYER_COUNT_ONE)
        {
            if (g_vdorec_cntx.is_use_blt_region)
            {
                S32 layer_width, layer_height;
                S32 x, y, w, h;
                
                gdi_layer_push_and_set_active(g_vdorec_cntx.tmp_osd_layer_region_handle[0]);
                gdi_layer_get_dimension(&layer_width, &layer_height);
                gdi_layer_pop_and_restore_active();
                
                /*the blt region is rotated, so we mush rotated the bacy*/
                x = g_vdorec_cntx.blt_area_y;
                y = g_vdorec_cntx.lcd_width - g_vdorec_cntx.blt_area_x - g_vdorec_cntx.blt_area_w;
                w = g_vdorec_cntx.blt_area_h;
                h = g_vdorec_cntx.blt_area_w;
                
                mdi_util_rotate_osd_partial_region_for_hw_rotator(
                    g_vdorec_cntx.tmp_osd_layer_region_handle[0], 
                    x, 
                    y, 
                    w, 
                    h, 
                    g_vdorec_cntx.osd_layer_handle);
            }
            else
            {
                mdi_util_rotate_osd_for_hw_rotator(g_vdorec_cntx.tmp_osd_layer_region_handle[0], g_vdorec_cntx.osd_layer_handle);
            }
        }
        else
        {
            for (i = 0 ; i < g_vdorec_cntx.osd_layer_region_count; i++)
            {
                if (g_vdorec_cntx.is_osd_layer_updated[i])
                {
                    mdi_util_rotate_osd_for_hw_rotator(g_vdorec_cntx.tmp_osd_layer_region_handle[i], g_vdorec_cntx.osd_layer_region_handle[i]);
                }
            }
        }
    }

    if (g_vdorec_cntx.is_use_blt_region)
    {
        gdi_layer_blt_previous(
            g_vdorec_cntx.blt_area_x, 
            g_vdorec_cntx.blt_area_y, 
            g_vdorec_cntx.blt_area_x + g_vdorec_cntx.blt_area_w - 1,
            g_vdorec_cntx.blt_area_y + g_vdorec_cntx.blt_area_h - 1);
    }
    else
    {
        if (g_vdorec_cntx.is_use_hw_rotate)
        {
            gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
        }
        else
        {
        #if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__)
            gdi_layer_blt_previous(0, 0, UI_device_height - 1, UI_device_width - 1);
        #else 
            gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
        #endif
        }
    }

    /* if use dirty region, will make the two buffer the same, it is for next drawing. */
    if (g_vdorec_cntx.is_use_hw_rotate)
    {
        if (g_vdorec_cntx.osd_layer_region_count == VDOREC_OSD_LAYER_COUNT_ONE)
        {
            if (g_vdorec_cntx.is_use_blt_region)
            {
                S32 layer_width, layer_height;
                S32 x, y, w, h;
                
                gdi_layer_push_and_set_active(g_vdorec_cntx.tmp_osd_layer_region_handle[0]);
                gdi_layer_get_dimension(&layer_width, &layer_height);
                gdi_layer_toggle_double();
                gdi_layer_pop_and_restore_active();
                
                /*the blt region is rotated, so we mush rotated the bacy*/
                x = g_vdorec_cntx.blt_area_y;
                y = g_vdorec_cntx.lcd_width - g_vdorec_cntx.blt_area_x - g_vdorec_cntx.blt_area_w;
                w = g_vdorec_cntx.blt_area_h;
                h = g_vdorec_cntx.blt_area_w;
                
                gdi_layer_push_and_set_active(g_vdorec_cntx.osd_layer_handle);
                gdi_layer_toggle_double();
                
                mdi_util_rotate_osd_partial_region_for_hw_rotator(
                    g_vdorec_cntx.tmp_osd_layer_region_handle[0], 
                    x, 
                    y, 
                    w, 
                    h, 
                    g_vdorec_cntx.osd_layer_handle);
                
                gdi_layer_toggle_double();
                gdi_layer_pop_and_restore_active();
                mmi_vdorec_set_merge_region(0, 0, 0, 0);
            }
            else
            {
                /* nothing needed*/
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_hilight_app
 * DESCRIPTION
 *  highlight vdorec menuitem
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_hilight_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_HILIGHT_APP);

    SetLeftSoftkeyFunction(mmi_vdorec_entry_app, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdorec_entry_app, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


static MMI_BOOL mmi_vdorec_malloc_app_mem(void)
{
    g_vdorec_cntx.app_mem_bufer  
        = applib_mem_ap_alloc_framebuffer(APPLIB_MEM_AP_ID_VDOREC, VDOREC_APP_MEMORY_BUFFER_SIZE);

    if (g_vdorec_cntx.app_mem_bufer == NULL)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


static void mmi_vdorec_free_app_mem(void)
{
    if (g_vdorec_cntx.app_mem_bufer)
    {
        applib_mem_ap_free(g_vdorec_cntx.app_mem_bufer);
    
        g_vdorec_cntx.app_mem_bufer = NULL;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_vdorec_init_app
* DESCRIPTION
*  init vdorec applcation
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
    mmi_vdorec_free_app_mem();
    
    /*Notify MMI that this application is already stopped */
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_VDOREC, KAL_TRUE);
    
    for (screen_id = SCR_ID_VDOREC_APP; screen_id < SCR_ID_VDOREC_END; screen_id++)
    {
        DeleteScreenIfPresent(screen_id);
    }
    
    g_vdorec_cntx.gdi_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    g_vdorec_cntx.app_mem_bufer = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_init_app
 * DESCRIPTION
 *  init vdorec applcation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_init_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_INIT_APP);

    g_vdorec_cntx.state = VDOREC_STATE_EXIT;
    g_vdorec_cntx.last_error = MDI_RES_VDOREC_SUCCEED;
    g_vdorec_cntx.is_saving = FALSE;
    g_vdorec_cntx.is_sub_display = FALSE;
    g_vdorec_cntx.is_setting_loaded = FALSE;

#ifdef __VDOREC_ROTATE_OSD_FOR_HW_ROTATOR__
    applib_mem_ap_register(APPLIB_MEM_AP_ID_VDOREC,STR_ID_VDOREC_APP_NAME,
        IMG_ID_VDOREC_APP_ICON, mmi_camera_app_mem_stop_callback);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_load_setting
 * DESCRIPTION
 *  load setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_load_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_LOAD_SETTING);

    /* read storage setting from video player */
    mmi_vdoply_load_setting();

    /* if already loaded into memory, do not need load again */
    if (!g_vdorec_cntx.is_setting_loaded)
    {
        ReadRecord(NVRAM_EF_VIDEO_SETTING_LID, 1, (void*)&g_vdorec_cntx.setting, NVRAM_EF_VIDEO_SETTING_SIZE, &error);

        /* first time init */
        if (g_vdorec_cntx.setting.wb == 0xffff)
        {
            mmi_vdorec_restore_setting();
        }

        g_vdorec_cntx.setting.led_value = VDOREC_DEFAULT_PREVIEW_LED_VALUE;
   
        g_vdorec_cntx.is_setting_loaded = TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_store_setting
 * DESCRIPTION
 *  store setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_store_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_STORE_SETTING);

    WriteRecord(NVRAM_EF_VIDEO_SETTING_LID, 1, (void*)&g_vdorec_cntx.setting, NVRAM_EF_VIDEO_SETTING_SIZE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_restore_setting
 * DESCRIPTION
 *  restore setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_restore_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_RESTORE_SETTING);
    
    g_vdorec_cntx.setting.wb = VDOREC_DEFAULT_SETTING_WB;
    g_vdorec_cntx.setting.ev = VDOREC_DEFAULT_SETTING_EV;
    g_vdorec_cntx.setting.led_highlight = VDOREC_DEFAULT_SETTING_LED_HIGHLIGHT;
    g_vdorec_cntx.setting.night = VDOREC_DEFAULT_SETTING_NIGHT;
    g_vdorec_cntx.setting.banding = VDOREC_DEFAULT_SETTING_BANDING;

    g_vdorec_cntx.setting.effect = VDOREC_DEFAULT_SETTING_EFFECT;

    g_vdorec_cntx.setting.video_size = VDOREC_DEFAULT_SETTING_VIDEO_SIZE;
    g_vdorec_cntx.setting.video_qty = VDOREC_DEFAULT_SETTING_VIDEO_QTY;
    g_vdorec_cntx.setting.size_limit = VDOREC_DEFAULT_SETTING_SIZE_LIMIT;
    g_vdorec_cntx.setting.time_limit = VDOREC_DEFAULT_SETTING_TIME_LIMIT;
    g_vdorec_cntx.setting.record_aud = VDOREC_DEFAULT_SETTING_RECORD_AUD;
    g_vdorec_cntx.setting.video_format = VDOREC_DEFAULT_SETTING_VIDEO_FORMAT;

    g_vdorec_cntx.setting.brightness = 128;
    g_vdorec_cntx.setting.contrast = 128;
    g_vdorec_cntx.setting.zoom = VDOREC_DEFAULT_SETTING_ZOOM;

    #ifdef __VDOREC_FEATURE_CALL_ACCEPT_OPTION__
    g_vdorec_cntx.setting.accept_call = VDOREC_DEFAULT_ACCEPT_CALL;
    #endif

#ifdef __VDOREC_COLOR_IDX_FRAME__
    g_vdorec_cntx.setting.color_idx_frame = VDOREC_DEFAULT_SETTING_COLOR_IDX_FRAME;
#endif 

    #if defined(__VDOREC_FEATURE_QVGA_RECORD_SUPPORT__)
    #ifdef __VDOREC_FEATURE_VIDEO_QTY_FINE__    
    if (g_vdorec_cntx.setting.video_qty == VDOREC_SETTING_VIDEO_QTY_FINE)
    {
        g_vdorec_cntx.setting.video_size = VDOREC_SETTING_VIDEO_SIZE_QVGA;
    }
    else
    {
        g_vdorec_cntx.setting.video_size = VDOREC_SETTING_VIDEO_SIZE_QCIF;
    }
    #endif /* __VDOREC_FEATURE_VIDEO_QTY_FINE__  */

    #if defined(__VDOREC_FEATURE_VIDEO_QTY_LOW__)
    if (g_vdorec_cntx.setting.video_qty == VDOREC_SETTING_VIDEO_QTY_LOW)
    {
        g_vdorec_cntx.setting.video_format = VDOREC_SETTING_VIDEO_FORMAT_3GP;
    }
    else
    {
        g_vdorec_cntx.setting.video_format = VDOREC_SETTING_VIDEO_FORMAT_MP4;
    }
    #endif /* __VDOREC_FEATURE_VIDEO_QTY_LOW__  */
    #endif /* defined(__VDOREC_FEATURE_QVGA_RECORD_SUPPORT__) */

    mmi_vdorec_store_setting();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_get_save_filename
 * DESCRIPTION
 *  get next file name to be recorded
 * PARAMETERS
 *  file_buf_p      [?]     
 *  a  UUT      filename buffer ptr(?)
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_get_save_filename(S8 *file_buf_p)
{

#ifdef __MMI_CAMERA_RECORDER_ONE_KEY_TOGGLE__
    mdi_get_ucs2_filename(file_buf_p,FMGR_MAX_PATH_LEN,g_vdorec_cntx.storage_filepath,MDI_NAMING_TYPE_DDMMYY_HHMM,FMGR_TYPE_3GP_VIDEO);

    /* store the filename */
    mmi_ucs2ncpy(g_vdorec_cntx.setting.save_name, mmi_fmgr_extract_file_name(file_buf_p), FMGR_MAX_FILE_LEN);
    mmi_vdorec_store_setting();
#else
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buffer[25];
    S8 UCS2_buffer[50];
    S8 UCS2_testname[50];
    S8 UCS2_alpha[10];
    S16 error = 0;
    U16 filename_seq_no;
    U16 alpha_count;
    U16 alpha_index;
    FS_HANDLE file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get/store sequentail number */
    ReadValue(NVRAM_VDOREC_FILENAME_SEQ_NO, &filename_seq_no, DS_SHORT, &error);

    if (filename_seq_no == 0xffff)
    {
        filename_seq_no = 1;    /* init value */
    }

    g_vdorec_cntx.filename_seq_no = filename_seq_no;
    alpha_count = 'Z' - 'A' + 1;

    while(1)
    {
        alpha_index = 0;

        sprintf((PS8)buffer, "MOV%04d", g_vdorec_cntx.filename_seq_no);
        mmi_asc_to_ucs2((PS8)UCS2_buffer, (PS8)buffer);

        while (1)
        {
            sprintf((PS8)buffer, "%c", 'A' + alpha_index);
            mmi_asc_to_ucs2((PS8)UCS2_alpha, (PS8)buffer);

            mmi_ucs2cpy(UCS2_testname, UCS2_buffer);
            mmi_ucs2cat(UCS2_testname, UCS2_alpha);

        #if defined(MP4_ENCODE)
            mmi_ucs2cat(UCS2_testname, (PS8)L".3gp");
        #elif defined(MJPG_ENCODE)
            mmi_ucs2cat(UCS2_testname, (PS8)L".avi");
        #else
            MMI_ASSERT(0);    
        #endif /* chip version */

            mmi_ucs2ncpy((PS8)file_buf_p, (PS8)g_vdorec_cntx.storage_filepath, FMGR_MAX_PATH_LEN);
            mmi_ucs2cat((PS8)file_buf_p, (PS8)UCS2_testname);

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
                WriteValue(NVRAM_VDOREC_FILENAME_SEQ_NO, &g_vdorec_cntx.filename_seq_no, DS_SHORT, &error);
                mmi_ucs2ncpy(g_vdorec_cntx.setting.save_name, mmi_fmgr_extract_file_name(file_buf_p), FMGR_MAX_FILE_LEN);
                mmi_vdorec_store_setting();
                return;
            }

            if (alpha_index >= alpha_count - 1)
            {
                g_vdorec_cntx.filename_seq_no++;
                /* leave internal while */
                break;
            }
        }
    }
#endif /* __MMI_CAMERA_RECORDER_ONE_KEY_TOGGLE__ */

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_GET_SAVE_FILE_NAME);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_disply_popup
 * DESCRIPTION
 *  display popup. will roate if is horizontal screen
 * PARAMETERS
 *  str_ptr             [IN]        String pointer
 *  img_id              [IN]        Image id
 *  image_on_bottom     [IN]        Is image on bottom
 *  tone_duration       [IN]        Tone duration
 *  tone_id             [IN]        Tine id
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_disply_popup(PU8 str_ptr, S32 eventy_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_DISPLAY_POPUP, eventy_type);

#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__VDOREC_ROTATE_OSD_FOR_HW_ROTATOR__)
    mmi_display_popup_rotated((UI_string_type)str_ptr, eventy_type, MMI_FRM_SCREEN_ROTATE_270);
#elif defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    if (mmi_frm_get_screen_rotate() == MMI_FRM_SCREEN_ROTATE_270 ||
    	  gdi_lcd_get_rotate() == GDI_LAYER_ROTATE_270)
    {
        /* rotate the popup only if the screen is being rotated */
        mmi_display_popup_rotated((UI_string_type)str_ptr, eventy_type, MMI_FRM_SCREEN_ROTATE_270);
    }
    else
    {
        mmi_display_popup((UI_string_type)str_ptr, eventy_type);
    }
#else /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__) */ 
    mmi_display_popup((UI_string_type)str_ptr, eventy_type);
#endif /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__) */ 
}

/*****************************************************************************
*
* Preview Screen
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_check_and_display_error_popup
 * DESCRIPTION
 *  display error popup.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static BOOL mmi_vdorec_check_and_display_error_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id = STR_GLOBAL_ERROR;
    mmi_event_notify_enum event_type = MMI_EVENT_FAILURE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_CHECK_AND_DISPLAY_POPUP);

    if (g_vdorec_cntx.last_error != MDI_RES_VDOREC_SUCCEED)
    {
	/* clear record keys */
        ClearKeyHandler(VDOREC_RECORD_KEY, KEY_EVENT_UP);
		
        if (VDOREC_RECORD_EXTRA_KEY1 != -1)
        {
            ClearKeyHandler((U16)(VDOREC_RECORD_EXTRA_KEY1), KEY_EVENT_UP);
        }
		
        if (VDOREC_RECORD_EXTRA_KEY2 != -1)
        {
            ClearKeyHandler((U16)(VDOREC_RECORD_EXTRA_KEY2), KEY_EVENT_UP);
        }

        ClearInputEventHandler(MMI_DEVICE_KEY);
        str_id = mdi_util_get_mdi_error_info(g_vdorec_cntx.last_error, &event_type);
        switch (g_vdorec_cntx.last_error)
        {
                /* followings are serious error, has to exit app */
            case MDI_RES_VDOREC_ERR_HW_NOT_READY:
            case MDI_RES_VDOREC_ERR_POWER_ON_FAILED:
            case MDI_RES_VDOREC_ERR_FAILED:
            case MDI_RES_VDOREC_ERR_PREVIEW_FAILED:
            case MDI_RES_VDOREC_ERR_RESUME_FAILED:
            case MDI_RES_VDOREC_ERR_PAUSE_FAILED:
            case MDI_RES_VDOREC_ERR_SAVE_FILE_FAILED:
            //case MDI_RES_VDOREC_ERR_RECORD_FAILED:
                mmi_vdorec_disply_popup(
                    (PU8) GetString(str_id),
                    event_type);
                DeleteNHistory(1);
                break;

        #ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__
            /* error of open saved video file  */
            case MDI_RES_VDOPLY_ERR_FAILED:
            case MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED:
            case MDI_RES_VDOPLY_ERR_PLAY_FAILED:
            case MDI_RES_VDOPLY_ERR_SEEK_FAILED:
            case MDI_RES_VDOPLY_ERR_INVALID_RESOULTION:
            case MDI_RES_VDOPLY_ERR_UNSUPPORTED_FORMAT:
            case MDI_RES_VDOPLY_ERR_MEMORY_INSUFFICIENT:
            case MDI_RES_VDOPLY_ERR_DRM_PROHIBITED:
            case MDI_RES_VDOPLY_ERR_DRM_DURATION_USED:
                mmi_vdorec_disply_popup(
                    (PU8) GetString(str_id),
                    event_type);
                DeleteNHistory(1);
                break;
        #endif /* __VDOREC_FEATURE_PREVIEW_SAVED_FILE__ */

            default:
                mmi_vdorec_disply_popup(
                    (PU8) GetString(str_id),
                    event_type);
        }

        g_vdorec_cntx.last_error = MDI_RES_VDOREC_SUCCEED;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_resize_preview_layer
 * DESCRIPTION
 *  resize preview layer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOREC_FEATURE_VIDEO_SIZE__
static void mmi_vdorec_resize_preview_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 video_width;
    S32 video_height;
    S32 resized_offset_x;
    S32 resized_offset_y;
    S32 resized_width;
    S32 resized_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    video_width = 176;
    video_height = 144;

#ifdef __VDOREC_FEATURE_VIDEO_SIZE_SQCIF__
    if (g_vdorec_cntx.setting.video_size == VDOREC_SETTING_VIDEO_SIZE_SQCIF)
    {
        video_width = 129;
        video_height = 96;
    }
#endif /* __VDOREC_FEATURE_VIDEO_SIZE_SQCIF__ */ 

#ifdef __VDOREC_FEATURE_VIDEO_SIZE_QQVGA__
    if (g_vdorec_cntx.setting.video_size == VDOREC_SETTING_VIDEO_SIZE_QQVGA)
    {
        video_width = 160;
        video_height = 120;
    }
#endif /* __VDOREC_FEATURE_VIDEO_SIZE_QQVGA__ */ 

#ifdef __VDOREC_FEATURE_VIDEO_SIZE_QCIF__
    if (g_vdorec_cntx.setting.video_size == VDOREC_SETTING_VIDEO_SIZE_QCIF)
    {
        video_width = 176;
        video_height = 144;
    }
#endif /* __VDOREC_FEATURE_VIDEO_SIZE_QCIF__ */ 

#ifdef __VDOREC_FEATURE_VIDEO_SIZE_QVGA__
    if (g_vdorec_cntx.setting.video_size == VDOREC_SETTING_VIDEO_SIZE_QVGA)
    {
        video_width = 320;
        video_height = 240;
    }
#endif /* __VDOREC_FEATURE_VIDEO_SIZE_QVGA__ */ 

#ifdef __VDOREC_FEATURE_VIDEO_SIZE_CIF__
    if (g_vdorec_cntx.setting.video_size == VDOREC_SETTING_VIDEO_SIZE_CIF)
    {
        video_width = 352;
        video_height = 288;
    }
#endif /* __VDOREC_FEATURE_VIDEO_SIZE_CIF__ */ 

    gdi_util_fit_box(
        GDI_UTIL_MODE_LONG_SIDE_FIT,
        g_vdorec_cntx.preview_wnd_width,
        g_vdorec_cntx.preview_wnd_height,
        video_width,
        video_height,
        &resized_offset_x,
        &resized_offset_y,
        &resized_width,
        &resized_height);

    gdi_layer_push_and_set_active(g_vdorec_cntx.preview_layer_handle);

    gdi_layer_resize(resized_width, resized_height);
    gdi_layer_set_position(
        g_vdorec_cntx.preview_wnd_offset_x + resized_offset_x,
        g_vdorec_cntx.preview_wnd_offset_y + resized_offset_y);

    gdi_layer_pop_and_restore_active();

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_RESIZE_PREVIEW_LAYER, video_width, video_height);
}
#endif /* __VDOREC_FEATURE_VIDEO_SIZE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_get_zoom_factor
 * DESCRIPTION
 *  get zoom factor based on feature define
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_get_video_size(S32 *video_width, S32 *video_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *video_width = 176;
    *video_height = 144;

#ifdef __VDOREC_FEATURE_VIDEO_SIZE_SQCIF__
    if (g_vdorec_cntx.setting.video_size == VDOREC_SETTING_VIDEO_SIZE_SQCIF)
    {
        *video_width = 129;
        *video_height = 96;
    }
#endif /* __VDOREC_FEATURE_VIDEO_SIZE_SQCIF__ */ 

#ifdef __VDOREC_FEATURE_VIDEO_SIZE_QQVGA__
    if (g_vdorec_cntx.setting.video_size == VDOREC_SETTING_VIDEO_SIZE_QQVGA)
    {
        *video_width = 160;
        *video_height = 120;
    }
#endif /* __VDOREC_FEATURE_VIDEO_SIZE_QQVGA__ */ 

#ifdef __VDOREC_FEATURE_VIDEO_SIZE_QCIF__
    if (g_vdorec_cntx.setting.video_size == VDOREC_SETTING_VIDEO_SIZE_QCIF)
    {
        *video_width = 176;
        *video_height = 144;
    }
#endif /* __VDOREC_FEATURE_VIDEO_SIZE_QCIF__ */ 

#ifdef __VDOREC_FEATURE_VIDEO_SIZE_QVGA__
    if (g_vdorec_cntx.setting.video_size == VDOREC_SETTING_VIDEO_SIZE_QVGA)
    {
        *video_width = 320;
        *video_height = 240;
    }
#endif /* __VDOREC_FEATURE_VIDEO_SIZE_QVGA__ */ 

#ifdef __VDOREC_FEATURE_VIDEO_SIZE_CIF__
    if (g_vdorec_cntx.setting.video_size == VDOREC_SETTING_VIDEO_SIZE_CIF)
    {
        *video_width = 352;
        *video_height = 288;
    }
#endif /* __VDOREC_FEATURE_VIDEO_SIZE_CIF__ */ 

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_GET_VIDEO_SIZE, *video_width, *video_height);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_get_zoom_factor
 * DESCRIPTION
 *  get zoom factor based on feature define
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U16 mmi_vdorec_get_zoom_factor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 zoom_factor;
    U32 current_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef ISP_SUPPORT
    if (g_vdorec_cntx.is_fast_zoom_support && g_vdorec_cntx.is_fast_zoom)
    {
        mdi_camera_get_fast_zoom_factor(&current_idx);
        current_idx = mmi_vdorec_get_zoom_level_idx(current_idx);
        
        g_vdorec_cntx.setting.zoom = current_idx;
        if (g_vdorec_cntx.zoom_limit < g_vdorec_feature_zoom[current_idx])
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_GET_ZOOM_FACTOR, g_vdorec_cntx.zoom_limit, g_vdorec_cntx.zoom_limit);
            return g_vdorec_cntx.zoom_limit;
        }
        else
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_GET_ZOOM_FACTOR, g_vdorec_feature_zoom[current_idx], g_vdorec_cntx.zoom_limit);
            return g_vdorec_feature_zoom[current_idx];
        }
    }
    else
    {
        zoom_factor = g_vdorec_feature_zoom[g_vdorec_cntx.setting.zoom];

        if (g_vdorec_cntx.zoom_limit < zoom_factor)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_GET_ZOOM_FACTOR, g_vdorec_cntx.zoom_limit, g_vdorec_cntx.zoom_limit);
            return g_vdorec_cntx.zoom_limit;
        }
        else
        {
            return zoom_factor;
        }
    }
#else /* ISP_SUPPORT */ /* #ifdef ISP_SUPPORT */
    zoom_factor = g_vdorec_feature_zoom[g_vdorec_cntx.setting.zoom];
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_GET_ZOOM_FACTOR, zoom_factor, g_vdorec_cntx.zoom_limit);
    return zoom_factor;
#endif /* ISP_SUPPORT */ /* #ifdef ISP_SUPPORT */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_lsk_press_hdlr
 * DESCRIPTION
 *  lsk press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_lsk_press_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_LSK_PRESS);

    g_vdorec_cntx.is_lsk_pressed = TRUE;
    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY);
    mmi_vdorec_blt_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_lsk_release_hdlr
 * DESCRIPTION
 *  lsk release hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_lsk_release_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_LSK_RELEASE);

    g_vdorec_cntx.is_lsk_pressed = FALSE;
    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY);
    mmi_vdorec_blt_screen();
#ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__
    switch(g_vdorec_cntx.state)
    {
        case VDOREC_STATE_VIDEO_PREVIEW_PLAY:
        case VDOREC_STATE_VIDEO_PREVIEW_STOP:
        case VDOREC_STATE_VIDEO_PREVIEW_BGCALL:
            mmi_vdorec_entry_preview_option_screen();
            break;
            
        default:
            mmi_vdorec_entry_option_screen();
            break;
    }
#else /* __VDOREC_FEATURE_PREVIEW_SAVED_FILE__*/
    mmi_vdorec_entry_option_screen();
#endif /* __VDOREC_FEATURE_PREVIEW_SAVED_FILE__ */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_rsk_press_hdlr
 * DESCRIPTION
 *  rsk press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_rsk_press_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_RSK_PRESS);

    g_vdorec_cntx.is_rsk_pressed = TRUE;
    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY);
    mmi_vdorec_blt_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_rsk_release_hdlr
 * DESCRIPTION
 *  rsk release hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_rsk_release_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_RSK_RELEASE);
    
    g_vdorec_cntx.is_rsk_pressed = FALSE;
    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY);
    mmi_vdorec_blt_screen();

    switch (g_vdorec_cntx.state)
    {
        case VDOREC_STATE_PREVIEW:
        case VDOREC_STATE_BG_CALL:
            if (g_vdorec_cntx.is_ext_req)
            {   
                if (g_vdorec_cntx.ext_req_callback)
                {
                    g_vdorec_cntx.ext_req_callback(MMI_FALSE, NULL);
                }
            }
            
            GoBackHistory();
            break;

        case VDOREC_STATE_RECORD:
            mdi_video_rec_record_stop();
            gui_cancel_timer(mmi_vdorec_record_timer_cyclic);

            #ifdef __VDOREC_FEATURE_DIRECT_SAVE__
            mmi_vdorec_entry_saving_screen();
            #else
            mmi_vdorec_entry_save_confirm_screen();
            #endif /* __VDOREC_FEATURE_DIRECT_SAVE__ */
            break;

        case VDOREC_STATE_PAUSE:
            mdi_video_rec_record_stop();
            gui_cancel_timer(mmi_vdorec_record_timer_cyclic);
            
            #ifdef __VDOREC_FEATURE_DIRECT_SAVE__
            mmi_vdorec_entry_saving_screen();
            #else
            mmi_vdorec_entry_save_confirm_screen();
            #endif /* __VDOREC_FEATURE_DIRECT_SAVE__ */
            break;
            
        case VDOREC_STATE_VIDEO_PREVIEW_PLAY:
        case VDOREC_STATE_VIDEO_PREVIEW_STOP:
        case VDOREC_STATE_VIDEO_PREVIEW_BGCALL:
        #ifdef __VDOREC_FEATURE_RSK_DELETE__
            mmi_vdorec_delete_saved_vdo_confirm();
        #else
            GoBackHistory();
        #endif
            break;
        
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_null_key_event
 * DESCRIPTION
 *  ck press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_null_key_event(void)
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
 *  mmi_vdorec_ck_press_hdlr
 * DESCRIPTION
 *  ck press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_ck_press_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_CK_PRESS);
    
    g_vdorec_cntx.is_ck_pressed = TRUE;

    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY);
    mmi_vdorec_blt_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_ck_release_hdlr
 * DESCRIPTION
 *  ck release hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_ck_release_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_CK_RELEASE);
    
    g_vdorec_cntx.is_ck_pressed = FALSE;


    if (mmi_vdorec_is_in_bgcall())
    {
        mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY);
        mmi_vdorec_blt_screen();
        /* do not change state */
        mmi_vdorec_disply_popup(
            (PU8)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL),
            MMI_EVENT_FAILURE);
        return;
    }

    switch (g_vdorec_cntx.state)
    {
        case VDOREC_STATE_PREVIEW:
            /*if in preview screen you press record key, will clear hint*/
            mmi_vdorec_set_hint(NULL, NULL, 0);
            /*if hint has drawed, should cancel hind hint timer*/
            gui_cancel_timer(mmi_vdorec_hide_hint);

            mmi_vdorec_draw_osd(
                VDOREC_OSD_COMPONENT_CLEAR_STATUS | 
                VDOREC_OSD_COMPONENT_SOFTKEY |
                VDOREC_OSD_COMPONENT_HINT
				);
            mmi_vdorec_blt_screen();
            mmi_vdorec_enter_state(VDOREC_STATE_RECORD);
            break;

        case VDOREC_STATE_PAUSE:
            mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY);
            mmi_vdorec_blt_screen();
            mmi_vdorec_enter_state(VDOREC_STATE_RECORD);
            break;

        case VDOREC_STATE_RECORD:
            mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY);
            mmi_vdorec_blt_screen();
            mmi_vdorec_enter_state(VDOREC_STATE_PAUSE);        
            break;

#ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__
        case VDOREC_STATE_VIDEO_PREVIEW_PLAY:
            mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY);
            mmi_vdorec_blt_screen();
            mmi_vdorec_enter_state(VDOREC_STATE_VIDEO_PREVIEW_STOP);


            break;
        case VDOREC_STATE_VIDEO_PREVIEW_STOP:
            mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY);
            mmi_vdorec_blt_screen();
            mmi_vdorec_enter_state(VDOREC_STATE_VIDEO_PREVIEW_PLAY);
            break;
#endif /* __VDOREC_FEATURE_PREVIEW_SAVED_FILE__ */

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_inc_ev
 * DESCRIPTION
 *  increase ev value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOREC_FEATURE_EV__
static void mmi_vdorec_inc_ev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_EV_INC, g_vdorec_cntx.setting.ev);

    if (g_vdorec_cntx.setting.ev < VDOREC_SETTING_EV_COUNT - 1)
    {
        g_vdorec_cntx.setting.ev++;

        mdi_video_rec_update_para_ev(vdorec_ev_command_map[g_vdorec_cntx.setting.ev]);

        mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_EV);
        mmi_vdorec_blt_screen();

        if (g_vdorec_cntx.is_first_time_ev)
        {
            /* first time ev, will wait longer to ev again */
            gui_start_timer(VDOREC_INC_INTERVAL_FIRST, mmi_vdorec_inc_ev);
            g_vdorec_cntx.is_first_time_ev = FALSE;
        }
        else
        {
            gui_start_timer(VDOREC_INC_INTERVAL, mmi_vdorec_inc_ev);
        }
    }

}
#endif /* __VDOREC_FEATURE_EV__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_dec_ev
 * DESCRIPTION
 *  decrease ev value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOREC_FEATURE_EV__
static void mmi_vdorec_dec_ev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_DEC_EV, g_vdorec_cntx.setting.ev);

    if (g_vdorec_cntx.setting.ev > 0)
    {
        g_vdorec_cntx.setting.ev--;

        mdi_video_rec_update_para_ev(vdorec_ev_command_map[g_vdorec_cntx.setting.ev]);

        mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_EV);

        mmi_vdorec_blt_screen();

        if (g_vdorec_cntx.is_first_time_ev)
        {
            /* first time ev, will wait longer to ev again */
            gui_start_timer(VDOREC_INC_INTERVAL_FIRST, mmi_vdorec_dec_ev);
            g_vdorec_cntx.is_first_time_ev = FALSE;
        }
        else
        {
            gui_start_timer(VDOREC_INC_INTERVAL, mmi_vdorec_dec_ev);
        }
    }

}
#endif /* __VDOREC_FEATURE_EV__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_inc_ev_key_press_hdlr
 * DESCRIPTION
 *  right arrow press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOREC_FEATURE_EV__
static void mmi_vdorec_inc_ev_key_press_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_EV_INC_PRESS);

    if (g_vdorec_cntx.is_watchdog_support)
    {
        mmi_vdorec_reset_watchdog_time_out_handler();
    }

#ifdef __VDOREC_FEATURE_RECORDING_EV__
    /* not in preview & record state */
    if ((g_vdorec_cntx.state != VDOREC_STATE_PREVIEW) &&
        (g_vdorec_cntx.state != VDOREC_STATE_RECORD) && (g_vdorec_cntx.state != VDOREC_STATE_PAUSE))
    {
        return;
    }
#else /* __VDOREC_FEATURE_RECORDING_EV__ */ 
    /* not in preview state */
    if (g_vdorec_cntx.state != VDOREC_STATE_PREVIEW)
    {
        return;
    }
#endif /* __VDOREC_FEATURE_RECORDING_EV__ */ 

    if (!g_vdorec_cntx.is_ev_inc_key_pressed)
    {
        g_vdorec_cntx.is_ev_inc_key_pressed = TRUE;
        g_vdorec_cntx.is_first_time_ev = TRUE;
        mmi_vdorec_inc_ev();
    }

}
#endif /* __VDOREC_FEATURE_EV__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_inc_ev_key_release_hdlr
 * DESCRIPTION
 *  right arrow release hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOREC_FEATURE_EV__
static void mmi_vdorec_inc_ev_key_release_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_EV_INC_RELEASE);

    if (g_vdorec_cntx.is_watchdog_support)
    {
        mmi_vdorec_reset_watchdog_time_out_handler();
        mmi_vdorec_watchdog_time_out_handler();
    }

    /* cancel timer */
    gui_cancel_timer(mmi_vdorec_inc_ev);
    g_vdorec_cntx.is_ev_inc_key_pressed = FALSE;

#ifdef __VDOREC_FEATURE_RECORDING_EV__
    /* not in preview & record state */
    if ((g_vdorec_cntx.state != VDOREC_STATE_PREVIEW) &&
        (g_vdorec_cntx.state != VDOREC_STATE_RECORD) && (g_vdorec_cntx.state != VDOREC_STATE_PAUSE))
    {
        return;
    }
#else /* __VDOREC_FEATURE_RECORDING_EV__ */ 
    /* not in preview state */
    if (g_vdorec_cntx.state != VDOREC_STATE_PREVIEW)
    {
        return;
    }
#endif /* __VDOREC_FEATURE_RECORDING_EV__ */ 

    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_EV);
    mmi_vdorec_blt_screen();
}
#endif /* __VDOREC_FEATURE_EV__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_dec_ev_key_press_hdlr
 * DESCRIPTION
 *  left arrow press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOREC_FEATURE_EV__
static void mmi_vdorec_dec_ev_key_press_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_EV_DEC_PRESS);

    if (g_vdorec_cntx.is_watchdog_support)
    {
        mmi_vdorec_reset_watchdog_time_out_handler();
    }

#ifdef __VDOREC_FEATURE_RECORDING_EV__
    /* not in preview & record state */
    if ((g_vdorec_cntx.state != VDOREC_STATE_PREVIEW) &&
        (g_vdorec_cntx.state != VDOREC_STATE_RECORD) && (g_vdorec_cntx.state != VDOREC_STATE_PAUSE))
    {
        return;
    }
#else /* __VDOREC_FEATURE_RECORDING_EV__ */ 
    /* not in preview state */
    if (g_vdorec_cntx.state != VDOREC_STATE_PREVIEW)
    {
        return;
    }
#endif /* __VDOREC_FEATURE_RECORDING_EV__ */ 

    if (!g_vdorec_cntx.is_ev_dec_key_pressed)
    {
        g_vdorec_cntx.is_ev_dec_key_pressed = TRUE;
        g_vdorec_cntx.is_first_time_ev = TRUE;
        mmi_vdorec_dec_ev();
    }

}
#endif /* __VDOREC_FEATURE_EV__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_dec_ev_key_release_hdlr
 * DESCRIPTION
 *  left arrow release hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOREC_FEATURE_EV__
static void mmi_vdorec_dec_ev_key_release_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_EV_DEC_RELEASE);

    if (g_vdorec_cntx.is_watchdog_support)
    {
        mmi_vdorec_reset_watchdog_time_out_handler();
        mmi_vdorec_watchdog_time_out_handler();
    }

    /* cancel timer */
    gui_cancel_timer(mmi_vdorec_dec_ev);
    g_vdorec_cntx.is_ev_dec_key_pressed = FALSE;

#ifdef __VDOREC_FEATURE_RECORDING_EV__
    /* not in preview & record state */
    if ((g_vdorec_cntx.state != VDOREC_STATE_PREVIEW) &&
        (g_vdorec_cntx.state != VDOREC_STATE_RECORD) && (g_vdorec_cntx.state != VDOREC_STATE_PAUSE))
    {
        return;
    }
#else /* __VDOREC_FEATURE_RECORDING_EV__ */ 
    /* not in preview state */
    if (g_vdorec_cntx.state != VDOREC_STATE_PREVIEW)
    {
        return;
    }
#endif /* __VDOREC_FEATURE_RECORDING_EV__ */ 

    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_EV);
    mmi_vdorec_blt_screen();
}
#endif /* __VDOREC_FEATURE_EV__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_zoom_in
 * DESCRIPTION
 *  zoom in
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOREC_FEATURE_ZOOM__
static void mmi_vdorec_zoom_in(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 prev_zoom_factor;
    U16 next_zoom_factor;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ZOOM_IN);

#ifdef __VDOREC_FEATURE_RECORDING_ZOOM__
    /* not in preview & record state */
    if ((g_vdorec_cntx.state != VDOREC_STATE_PREVIEW) &&
        (g_vdorec_cntx.state != VDOREC_STATE_RECORD) && (g_vdorec_cntx.state != VDOREC_STATE_PAUSE))
    {
        return;
    }
#else /* __VDOREC_FEATURE_RECORDING_ZOOM__ */ 
    /* not in preview state */
    if (g_vdorec_cntx.state != VDOREC_STATE_PREVIEW)
    {
        return;
    }
#endif /* __VDOREC_FEATURE_RECORDING_ZOOM__ */ 

    if (g_vdorec_cntx.setting.zoom < VDOREC_FEATURE_ZOOM_COUNT - 1)
    {
    #ifdef ISP_SUPPORT
        prev_zoom_factor = mmi_vdorec_get_zoom_factor();

        g_vdorec_cntx.setting.zoom += 1;
        next_zoom_factor = mmi_vdorec_get_zoom_factor();

        if (prev_zoom_factor == next_zoom_factor)
        {
            /* reach sensor zoom limit */
            g_vdorec_cntx.setting.zoom -= 1;
            return;
        }
    #else /* ISP_SUPPORT */ 
        g_vdorec_cntx.setting.zoom += 1;
    #endif /* ISP_SUPPORT */ 

        mdi_video_rec_update_para_zoom(mmi_vdorec_get_zoom_factor());

        mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_ZOOM);

        mmi_vdorec_blt_screen();

        /* only build-in camera use long pressed zooming feature */
        /* since backend module's zooming time is not stable, will cause zooming jump two level */
		if (g_vdorec_cntx.is_fast_zoom_support)
        {
			/* first time zoom, will wait longer to zoom again */
			gui_start_timer(VDOREC_INC_INTERVAL_FIRST, mmi_vdorec_start_fast_zoom_in);
			g_vdorec_cntx.is_first_time_zoom = FALSE;
		}
		else
		{
			if (g_vdorec_cntx.is_first_time_zoom)
			{
				/* first time zoom, will wait longer to zoom again */
				gui_start_timer(VDOREC_INC_INTERVAL_FIRST, mmi_vdorec_zoom_in);
				g_vdorec_cntx.is_first_time_zoom = FALSE;
			}
			else
			{
				gui_start_timer(VDOREC_INC_INTERVAL, mmi_vdorec_zoom_in);
			}
		}
    }
}
#endif /* __VDOREC_FEATURE_ZOOM__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_zoom_in_key_press_hdlr
 * DESCRIPTION
 *  up arrow press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOREC_FEATURE_ZOOM__
static void mmi_vdorec_zoom_in_key_press_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ZOOM_IN_KEY_PRESS);

    if (g_vdorec_cntx.is_watchdog_support)
    {
        mmi_vdorec_reset_watchdog_time_out_handler();
    }

#ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__
    if (g_vdorec_cntx.state == VDOREC_STATE_VIDEO_PREVIEW_PLAY ||
        g_vdorec_cntx.state == VDOREC_STATE_VIDEO_PREVIEW_STOP ||
        g_vdorec_cntx.state == VDOREC_STATE_VIDEO_PREVIEW_BGCALL)
    {
        return;
    }
#endif /* __VDOREC_FEATURE_PREVIEW_SAVED_FILE__ */

    if (!g_vdorec_cntx.is_zoom_in_key_pressed)
    {
        g_vdorec_cntx.is_zoom_in_key_pressed = TRUE;
        g_vdorec_cntx.is_first_time_zoom = TRUE;
        mmi_vdorec_zoom_in();
    }

}
#endif /* __VDOREC_FEATURE_ZOOM__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_zoom_in_key_release_hdlr
 * DESCRIPTION
 *  up arrow release hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOREC_FEATURE_ZOOM__
static void mmi_vdorec_zoom_in_key_release_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ZOOM_IN_KEY_RELEASE);

    if (g_vdorec_cntx.is_watchdog_support)
    {
        mmi_vdorec_reset_watchdog_time_out_handler();
        mmi_vdorec_watchdog_time_out_handler();
    }

#ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__
    if (g_vdorec_cntx.state == VDOREC_STATE_VIDEO_PREVIEW_PLAY ||
        g_vdorec_cntx.state == VDOREC_STATE_VIDEO_PREVIEW_STOP ||
        g_vdorec_cntx.state == VDOREC_STATE_VIDEO_PREVIEW_BGCALL)
    {
        return;
    }
#endif /* __VDOREC_FEATURE_PREVIEW_SAVED_FILE__ */

    g_vdorec_cntx.is_zoom_in_key_pressed = FALSE;
    
    if (g_vdorec_cntx.is_fast_zoom_support)
    {
        mmi_vdorec_stop_fast_zoom();
        gui_cancel_timer(mmi_vdorec_draw_zoom_osd);
        gui_cancel_timer(mmi_vdorec_start_fast_zoom_in);
    }
    else
    {
        gui_cancel_timer(mmi_vdorec_zoom_in);
    }

    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_ZOOM);
    mmi_vdorec_blt_screen();
}
#endif /* __VDOREC_FEATURE_ZOOM__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_zoom_out
 * DESCRIPTION
 *  zoom in
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOREC_FEATURE_ZOOM__
static void mmi_vdorec_zoom_out(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ZOOM_OUT);

    if (g_vdorec_cntx.is_watchdog_support)
    {
        mmi_vdorec_reset_watchdog_time_out_handler();
    }
    
#ifdef __VDOREC_FEATURE_RECORDING_ZOOM__
    /* not in preview & record state */
    if ((g_vdorec_cntx.state != VDOREC_STATE_PREVIEW) &&
        (g_vdorec_cntx.state != VDOREC_STATE_RECORD) && (g_vdorec_cntx.state != VDOREC_STATE_PAUSE))
    {
        return;
    }
#else /* __VDOREC_FEATURE_RECORDING_ZOOM__ */ 
    /* not in preview state */
    if (g_vdorec_cntx.state != VDOREC_STATE_PREVIEW)
    {
        return;
    }
#endif /* __VDOREC_FEATURE_RECORDING_ZOOM__ */ 

    if (g_vdorec_cntx.setting.zoom > 0)
    {
        g_vdorec_cntx.setting.zoom -= 1;

        mdi_video_rec_update_para_zoom(mmi_vdorec_get_zoom_factor());

        mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_ZOOM);

        mmi_vdorec_blt_screen();

        /* only build-in camera use long pressed zooming feature */
        /* since backend module's zooming time is not stable, will cause zooming jump two level */
		if (g_vdorec_cntx.is_fast_zoom_support)
        {
			/* first time zoom, will wait longer to zoom again */
			gui_start_timer(VDOREC_INC_INTERVAL_FIRST, mmi_vdorec_start_fast_zoom_out);
			g_vdorec_cntx.is_first_time_zoom = FALSE;            
		}
		else
		{
			if (g_vdorec_cntx.is_first_time_zoom)
			{
				/* first time zoom, will wait longer to zoom again */
				gui_start_timer(VDOREC_INC_INTERVAL_FIRST, mmi_vdorec_zoom_out);
				g_vdorec_cntx.is_first_time_zoom = FALSE;            
			}
			else
			{
				gui_start_timer(VDOREC_INC_INTERVAL, mmi_vdorec_zoom_out);
			}
		}
    }

}
#endif /* __VDOREC_FEATURE_ZOOM__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_zoom_out_key_press_hdlr
 * DESCRIPTION
 *  down arrow press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOREC_FEATURE_ZOOM__
static void mmi_vdorec_zoom_out_key_press_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ZOOM_OUT_KEY_PRESS);

    if (g_vdorec_cntx.is_watchdog_support)
    {
        mmi_vdorec_reset_watchdog_time_out_handler();
        mmi_vdorec_watchdog_time_out_handler();
    }

#ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__
    if (g_vdorec_cntx.state == VDOREC_STATE_VIDEO_PREVIEW_PLAY ||
        g_vdorec_cntx.state == VDOREC_STATE_VIDEO_PREVIEW_STOP ||
        g_vdorec_cntx.state == VDOREC_STATE_VIDEO_PREVIEW_BGCALL)
    {
        return;
    }
#endif /* __VDOREC_FEATURE_PREVIEW_SAVED_FILE__ */
    
    if (!g_vdorec_cntx.is_zoom_out_key_pressed)
    {
        g_vdorec_cntx.is_zoom_out_key_pressed = TRUE;
        g_vdorec_cntx.is_first_time_zoom = TRUE;

        mmi_vdorec_zoom_out();
    }
}
#endif /* __VDOREC_FEATURE_ZOOM__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_zoom_out_key_release_hdlr
 * DESCRIPTION
 *  up arrow release hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOREC_FEATURE_ZOOM__
static void mmi_vdorec_zoom_out_key_release_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ZOOM_OUT_KEY_RELEASE);

#ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__
    if (g_vdorec_cntx.state == VDOREC_STATE_VIDEO_PREVIEW_PLAY ||
        g_vdorec_cntx.state == VDOREC_STATE_VIDEO_PREVIEW_STOP ||
        g_vdorec_cntx.state == VDOREC_STATE_VIDEO_PREVIEW_BGCALL)
    {
        return;
    }
#endif /* __VDOREC_FEATURE_PREVIEW_SAVED_FILE__ */

    
    g_vdorec_cntx.is_zoom_out_key_pressed = FALSE;

    if (g_vdorec_cntx.is_fast_zoom_support)
    {
        mmi_vdorec_stop_fast_zoom();
        gui_cancel_timer(mmi_vdorec_draw_zoom_osd);
        gui_cancel_timer(mmi_vdorec_start_fast_zoom_out);
    }
    else
    {
        gui_cancel_timer(mmi_vdorec_zoom_out);
    }

    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_ZOOM);
    mmi_vdorec_blt_screen();
}
#endif /* __VDOREC_FEATURE_ZOOM__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_turn_on_led_highlight
 * DESCRIPTION
 *  turn on led highlight
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_turn_on_led_highlight(void)
{
#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT__    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 duty;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    duty = g_vdorec_cntx.setting.led_value;

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_TURN_ON_LED, duty);

#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT_ON_OFF__
    if (g_vdorec_cntx.setting.led_highlight)
    {
        custom_start_flashlight(1, 1, 1, duty);
    }
#else /* __VDOREC_FEATURE_LED_HIGHLIGHT_ON_OFF__ */ 
    /* __VDOREC_FEATURE_LED_HIGHLIGHT_7_COLOR__ */
    switch (g_vdorec_cntx.setting.led_highlight)
    {
        case VDOREC_SETTING_LED_HIGHLIGHT_WHITE:
            custom_start_flashlight(1, 1, 1, duty);
            break;

        case VDOREC_SETTING_LED_HIGHLIGHT_RED:
            custom_start_flashlight(1, 0, 0, duty);
            break;

        case VDOREC_SETTING_LED_HIGHLIGHT_GREEN:
            custom_start_flashlight(0, 1, 0, duty);
            break;

        case VDOREC_SETTING_LED_HIGHLIGHT_BLUE:
            custom_start_flashlight(0, 0, 1, duty);
            break;

        case VDOREC_SETTING_LED_HIGHLIGHT_YELLOW:
            custom_start_flashlight(1, 1, 0, duty);
            break;

        case VDOREC_SETTING_LED_HIGHLIGHT_PURPLE:
            custom_start_flashlight(1, 0, 1, duty);
            break;

        case VDOREC_SETTING_LED_HIGHLIGHT_CYAN:
            custom_start_flashlight(0, 1, 1, duty);
            break;
    }
#endif /* __VDOREC_FEATURE_LED_HIGHLIGHT_ON_OFF__ */ 

#endif /* __VDOREC_FEATURE_LED_HIGHLIGHT__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_turn_off_led_highlight
 * DESCRIPTION
 *  turn off led highlight
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_turn_off_led_highlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_TURN_OFF_LED);

#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT__
    custom_stop_flashlight();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_record_result_hdlr_callback
 * DESCRIPTION
 *  record result callback hdlr
 * PARAMETERS
 *  result      [IN]        
 *  a(?)        [IN]        Current state
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_record_result_hdlr_callback(MDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_RECORD_RESULT_HDLR_CALLBACK);

    ASSERT((g_vdorec_cntx.state == VDOREC_STATE_RECORD) || (g_vdorec_cntx.state == VDOREC_STATE_PAUSE));

    gui_cancel_timer(mmi_vdorec_record_timer_cyclic);
#ifdef __VDOREC_FEATURE_EV__    
    gui_cancel_timer(mmi_vdorec_dec_ev);
    gui_cancel_timer(mmi_vdorec_inc_ev);
#endif /* __VDOREC_FEATURE_EV__ */

#ifdef __VDOREC_FEATURE_ZOOM__
    gui_cancel_timer(mmi_vdorec_zoom_in);
    gui_cancel_timer(mmi_vdorec_zoom_out);
#endif /* __VDOREC_FEATURE_ZOOM__ */ 

    if (g_vdorec_cntx.is_ext_req)
    {
        if (result == MDI_RES_VDOREC_DISK_FULL)
        {
            mmi_vdorec_disply_popup(
                (PU8)GetString(FMGR_FS_DISK_FULL_TEXT),
                MMI_EVENT_FAILURE);
            return;
        }
        else if (result == MDI_RES_VDOREC_REACH_SIZE_LIMIT)
        {
            mmi_vdorec_disply_popup(
                (PU8)GetString(STR_ID_VDOREC_SIZE_LIMIT),
                MMI_EVENT_FAILURE);
            return;
        }
        else if (result == MDI_RES_VDOREC_ERR_FAILED)
        {
            mmi_vdorec_disply_popup(
                (PU8)GetString(STR_ID_VDOREC_NOTIFY_ERROR),
                MMI_EVENT_FAILURE);

            DeleteScreenIfPresent(SCR_ID_VDOREC_APP);            
            g_vdorec_cntx.ext_req_callback(MMI_FALSE, NULL);
            return;
        }
        else if (result == MDI_RES_VDOREC_ERR_STORAGE_TOO_SLOW)
        {
            mmi_vdorec_disply_popup(
                (PU8)GetString(STR_ID_VDOREC_NOTIFY_STORAGE_TOO_SLOW),
                MMI_EVENT_FAILURE);
            g_vdorec_cntx.ext_req_callback(MMI_FALSE, NULL);
            return;
        }        
        else
        {
            /* unhandle return */
            MMI_ASSERT(0);
        }
    }
    else
    {
        if (result == MDI_RES_VDOREC_DISK_FULL)
        {
            mmi_vdorec_disply_popup(
                (PU8) GetString(FMGR_FS_DISK_FULL_TEXT),
                MMI_EVENT_FAILURE);
            return;
        }
        else if (result == MDI_RES_VDOREC_REACH_SIZE_LIMIT)
        {
            mmi_vdorec_disply_popup(
                (PU8) GetString(STR_ID_VDOREC_SIZE_LIMIT),
                MMI_EVENT_INFO);
            return;
        }
        else if (result == MDI_RES_VDOREC_ERR_FAILED)
        {
            mmi_vdorec_disply_popup(
                (PU8) GetString(STR_ID_VDOREC_NOTIFY_ERROR),
                MMI_EVENT_FAILURE);
            return;
        }
        else if (result == MDI_RES_VDOREC_ERR_STORAGE_TOO_SLOW)
        {
            mmi_vdorec_disply_popup(
                (PU8)GetString(STR_ID_VDOREC_NOTIFY_STORAGE_TOO_SLOW),
                MMI_EVENT_FAILURE);
            return;
        }               
        else
        {
            /* unhandle return */
            MMI_ASSERT(0);
        }

    }

#ifdef __VDOREC_FEATURE_DIRECT_SAVE__
    mmi_vdorec_entry_saving_screen();
#else
    mmi_vdorec_entry_save_confirm_screen();
#endif /* __VDOREC_FEATURE_DIRECT_SAVE__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_wb_hotkey_press
 * DESCRIPTION
 *  wb hotkey pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOREC_FEATURE_VIDEO_SIZE__
static void mmi_vdorec_video_size_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];
    S32 video_width;
    S32 video_height;
    S32 current_preview_layer_width;
    S32 current_preview_layer_height;
    S32 previous_preview_layer_width;
    S32 previous_preview_layer_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_VIDEO_SIZE_HOTKEY_PRESS);

    /*if not in preview state, will forbit hotkey*/
    if(g_vdorec_cntx.state != VDOREC_STATE_PREVIEW)
    {
        return;
    }

    if (g_vdorec_cntx.setting.video_size < VDOREC_SETTING_VIDEO_SIZE_COUNT - 1)
    {
        g_vdorec_cntx.setting.video_size++;
    }
    else
    {
        g_vdorec_cntx.setting.video_size = 0;
    }
    
    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_VDOREC_VIDEO_SIZE));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");
    
    /* draw osd */
    mmi_vdorec_set_hint(
        (PS8) str_buf,
        (PS8) GetString((U16) (g_vdorec_cntx.setting.video_size + STR_ID_VDOREC_VIDEO_SIZE_START + 1)),
        HINT_POPUP_FADE_TIME);
    
    /*video size changed, so need stop and then start video*/
    mdi_video_rec_preview_stop();

    /*get the previous preview layer width*/
    gdi_layer_push_and_set_active(g_vdorec_cntx.preview_layer_handle);
    gdi_layer_get_dimension(&previous_preview_layer_width, &previous_preview_layer_height);
    gdi_layer_pop_and_restore_active();

    mmi_vdorec_resize_preview_layer();

    /*get the current preview layer width*/
    gdi_layer_push_and_set_active(g_vdorec_cntx.preview_layer_handle);
    gdi_layer_get_dimension(&current_preview_layer_width, &current_preview_layer_height);
    gdi_layer_pop_and_restore_active();

    /*if the preview windown width and height has changed , we should clear preview layer date, for it maybe confused*/
    if ((previous_preview_layer_width != current_preview_layer_width) ||
        (previous_preview_layer_height != current_preview_layer_height))
    {
        gdi_layer_push_and_set_active(g_vdorec_cntx.preview_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
    }
    if (!mmi_vdorec_is_in_bgcall())
    {
        mmi_vdorec_start_preview();
    }

    /*if video size changed, the zoom value should be reset*/
    g_vdorec_cntx.setting.zoom = VDOREC_DEFAULT_SETTING_ZOOM;     
    mdi_video_rec_update_para_zoom(mmi_vdorec_get_zoom_factor());
    /*video size changed, need reget the zoom limit*/
    mmi_vdorec_get_video_size(&video_width, &video_height);
    g_vdorec_cntx.zoom_limit = mdi_video_rec_get_max_zoom_factor(video_width, video_height);

    /* if zoom is like 2.6x, round it to 2.0x */
    g_vdorec_cntx.zoom_limit /= 10;
    g_vdorec_cntx.zoom_limit *= 10;

    if (g_vdorec_cntx.zoom_limit < 10)
    {
        g_vdorec_cntx.zoom_limit = 10;
    }

#ifdef __VDOREC_HIDE_HINT__
    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_STATUS | VDOREC_OSD_COMPONENT_ZOOM);
#else
    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_HINT | VDOREC_OSD_COMPONENT_STATUS | VDOREC_OSD_COMPONENT_ZOOM);
#endif
    
    mmi_vdorec_blt_screen();
}
#endif


#ifdef __VDOREC_FEATURE_VIDEO_QTY__
static void mmi_vdorec_video_qty_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];
    U16 string_base_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_QTY_HOTKEY_PRESS);

    /*if not in preview state, will forbit hotkey*/
    if(g_vdorec_cntx.state != VDOREC_STATE_PREVIEW)
    {
        return;
    }

    if (g_vdorec_cntx.setting.video_qty < VDOREC_SETTING_VIDEO_QTY_COUNT - 1)
    {
        g_vdorec_cntx.setting.video_qty++;
    }
    else
    {
        g_vdorec_cntx.setting.video_qty = 0;
    }

    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_VDOREC_VIDEO_QTY));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");
    

#if defined(__VDOREC_FEATURE_QVGA_RECORD_SUPPORT__)
    string_base_id = STR_ID_VDOREC_VIDEO_QTY2_START;
#else
    string_base_id = STR_ID_VDOREC_VIDEO_QTY_START;
#endif    
    
    /* draw osd */
    mmi_vdorec_set_hint(
        (PS8) str_buf,
        (PS8) GetString((U16) (g_vdorec_cntx.setting.video_qty + string_base_id  + 1)),
        HINT_POPUP_FADE_TIME);
    
    #if defined(__VDOREC_FEATURE_QVGA_RECORD_SUPPORT__)
    #ifdef __VDOREC_FEATURE_VIDEO_QTY_FINE__    
    if (g_vdorec_cntx.setting.video_qty == VDOREC_SETTING_VIDEO_QTY_FINE)
    {
        g_vdorec_cntx.setting.video_size = VDOREC_SETTING_VIDEO_SIZE_QVGA;
    }
    else
    {
        g_vdorec_cntx.setting.video_size = VDOREC_SETTING_VIDEO_SIZE_QCIF;
    }

    {
        S32 video_width, video_height;

        /*if video size changed, the zoom value should be reset*/
        g_vdorec_cntx.setting.zoom = VDOREC_DEFAULT_SETTING_ZOOM;     
        mdi_video_rec_update_para_zoom(mmi_vdorec_get_zoom_factor());
        /*video size changed, need reget the zoom limit*/
        mmi_vdorec_get_video_size(&video_width, &video_height);
        g_vdorec_cntx.zoom_limit = mdi_video_rec_get_max_zoom_factor(video_width, video_height);
        
        /* if zoom is like 2.6x, round it to 2.0x */
        g_vdorec_cntx.zoom_limit /= 10;
        g_vdorec_cntx.zoom_limit *= 10;
        
        if (g_vdorec_cntx.zoom_limit < 10)
        {
            g_vdorec_cntx.zoom_limit = 10;
        }
    }
    #endif /* __VDOREC_FEATURE_VIDEO_QTY_FINE__  */

    #if defined(__VDOREC_FEATURE_VIDEO_QTY_LOW__)
    if (g_vdorec_cntx.setting.video_qty == VDOREC_SETTING_VIDEO_QTY_LOW)
    {
        g_vdorec_cntx.setting.video_format = VDOREC_SETTING_VIDEO_FORMAT_3GP;
    }
    else
    {
        g_vdorec_cntx.setting.video_format = VDOREC_SETTING_VIDEO_FORMAT_MP4;
    }
    #endif /* __VDOREC_FEATURE_VIDEO_QTY_LOW__  */
    #endif /* defined(__VDOREC_FEATURE_QVGA_RECORD_SUPPORT__) */

#ifdef __VDOREC_FEATURE_QVGA_RECORD_SUPPORT__
#ifdef __VDOREC_HIDE_HINT__
    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_STATUS | VDOREC_OSD_COMPONENT_ZOOM);
#else
    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_HINT | VDOREC_OSD_COMPONENT_STATUS | VDOREC_OSD_COMPONENT_ZOOM);
#endif
#else
#ifdef __VDOREC_HIDE_HINT__
    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_STATUS);
#else
    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_HINT | VDOREC_OSD_COMPONENT_STATUS);
#endif
#endif
    mmi_vdorec_blt_screen();

    /* for quality only used in preview start, so I stop and restart preview*/
    mdi_video_rec_preview_stop();
    if (!mmi_vdorec_is_in_bgcall())
    {
        mmi_vdorec_start_preview();
    }
}
#endif


#ifdef __VDOREC_FEATURE_NIGHT__
static void mmi_vdorec_night_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_NIGHT_HOTKEY_PRESS);
 
    /*if not in preview state, will forbit hotkey*/
    if(g_vdorec_cntx.state != VDOREC_STATE_PREVIEW)
    {
        return;
    }

    if (g_vdorec_cntx.setting.night < VDOREC_SETTING_NIGHT_COUNT - 1)
    {
        g_vdorec_cntx.setting.night++;
    }
    else
    {
        g_vdorec_cntx.setting.night = 0;
    }
    
    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_VDOREC_NIGHT));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");
    
    /* draw osd */
    mmi_vdorec_set_hint(
        (PS8) str_buf,
        (PS8) GetString((U16) (g_vdorec_cntx.setting.night + STR_ID_VDOREC_NIGHT_START + 1)),
        HINT_POPUP_FADE_TIME);
    
#ifdef __VDOREC_HIDE_HINT__
    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_STATUS);
#else
    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_STATUS | VDOREC_OSD_COMPONENT_HINT);
#endif
    
    mdi_video_rec_update_para_night(g_vdorec_cntx.setting.night);
    
    mmi_vdorec_blt_screen();
}
#endif 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_wb_hotkey_press
 * DESCRIPTION
 *  wb hotkey pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOREC_FEATURE_WB__
static void mmi_vdorec_wb_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_WB_HOTKEY_PRESS);
 
    /*if not in preview state, will forbit hotkey*/
    if(g_vdorec_cntx.state != VDOREC_STATE_PREVIEW)
    {
        return;
    }

    if (g_vdorec_cntx.setting.wb < VDOREC_SETTING_WB_COUNT - 1)
    {
        g_vdorec_cntx.setting.wb++;
    }
    else
    {
        g_vdorec_cntx.setting.wb = 0;
    }
    
    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_VDOREC_WB));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");
    
    /* update osd */
    mmi_vdorec_set_hint(
        (PS8) str_buf,
        (PS8) GetString((U16) (g_vdorec_cntx.setting.wb + STR_ID_VDOREC_WB_START + 1)),
        HINT_POPUP_FADE_TIME);
    
#ifdef __VDOREC_HIDE_HINT__
    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_STATUS);
#else
    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_HINT | VDOREC_OSD_COMPONENT_STATUS);
#endif
    
    mdi_video_rec_update_para_wb(vdorec_wb_command_map[g_vdorec_cntx.setting.wb]);
    
    mmi_vdorec_blt_screen();
}
#endif 

/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_led_highlight_hotkey_press
 * DESCRIPTION
 *  led highlight hotkey pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT__
static void mmi_vdorec_led_highlight_hotkey_press(void)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_LED_HIGHLIGHT_HOTKEY_PRESS);

    /*if not in preview state, will forbit hotkey*/
    if(g_vdorec_cntx.state != VDOREC_STATE_PREVIEW)
    {
        return;
    }

    if (g_vdorec_cntx.setting.led_highlight < VDOREC_SETTING_LED_HIGHLIGHT_COUNT - 1)
    {
        g_vdorec_cntx.setting.led_highlight++;
    }
    else
    {
        g_vdorec_cntx.setting.led_highlight = 0;
    }
    
    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_VDOREC_LED_HIGHLIGHT));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");
    
    /* update osd */
    mmi_vdorec_set_hint(
        (PS8) str_buf,
        (PS8) GetString((U16) (g_vdorec_cntx.setting.led_highlight + STR_ID_VDOREC_LED_HIGHLIGHT_START + 1)),
        HINT_POPUP_FADE_TIME);
    
#ifdef __VDOREC_HIDE_HINT__
    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_STATUS);
#else
    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_HINT | VDOREC_OSD_COMPONENT_STATUS);
#endif
    
    /* turn on/of led */
    if (g_vdorec_cntx.setting.led_highlight == VDOREC_SETTING_LED_HIGHLIGHT_OFF)
    {
        mmi_vdorec_turn_off_led_highlight();
    }
    else
    {
        mmi_vdorec_turn_on_led_highlight();
    }
    
    mmi_vdorec_turn_on_led_highlight();
    
    mmi_vdorec_blt_screen();
}
#endif 

#ifdef __VDOREC_FEATURE_RECORD_AUD__
static void mmi_vdorec_record_aud_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 str_buf[256];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_RECORD_AUD_HOTKEY_PRESS);

    /*if not in preview state, will forbit hotkey*/
    if(g_vdorec_cntx.state != VDOREC_STATE_PREVIEW)
    {
        return;
    }

    if (g_vdorec_cntx.setting.record_aud < VDOREC_SETTING_RECORD_AUD_COUNT - 1)
    {
        g_vdorec_cntx.setting.record_aud++;
    }
    else
    {
        g_vdorec_cntx.setting.record_aud = 0;
    }
    
    /* for record audio used in preview start, so I stop and restart preview*/
    mdi_video_rec_preview_stop();
    if (!mmi_vdorec_is_in_bgcall())
    {
        mmi_vdorec_start_preview();
    }
    
    mmi_ucs2cpy((PS8) str_buf, (PS8) L"[ ");
    mmi_ucs2cat((PS8) str_buf, (PS8) GetString(STR_ID_VDOREC_RECORD_AUD));
    mmi_ucs2cat((PS8) str_buf, (PS8) L" ]");
    
    /* update osd */
    mmi_vdorec_set_hint(
        (PS8) str_buf,
        (PS8) GetString((U16) (g_vdorec_cntx.setting.record_aud + STR_ID_VDOREC_RECORD_AUD_START + 1)),
        HINT_POPUP_FADE_TIME);
    
#ifdef __VDOREC_HIDE_HINT__
    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_STATUS);
#else
    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_HINT | VDOREC_OSD_COMPONENT_STATUS);
#endif
        
    mmi_vdorec_blt_screen();
}
#endif 

/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_start_preview
 * DESCRIPTION
 *  Start preview
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_start_preview(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_video_setting_struct video_preview_data;
    U32 blt_layer_flag = 0;
    U32 preview_layer_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_START_PREVIEW);

    video_preview_data.wb = vdorec_wb_command_map[g_vdorec_cntx.setting.wb];
    video_preview_data.ev = vdorec_ev_command_map[g_vdorec_cntx.setting.ev];
    video_preview_data.banding = vdorec_banding_command_map[g_vdorec_cntx.setting.banding];
    video_preview_data.video_qty = vdorec_video_qty_command_map[g_vdorec_cntx.setting.video_qty];
    video_preview_data.video_format = vdorec_video_format_command_map[g_vdorec_cntx.setting.video_format];
    video_preview_data.effect = vdorec_effect_command_map[g_vdorec_cntx.setting.effect];

#ifdef __DIRECT_SENSOR_SUPPORT__
    /* MT6223 do not have resizer, the record size should be the same as preview size */
    video_preview_data.video_size = MDI_VIDEO_VIDEO_SIZE_USER_DEFINE;
    video_preview_data.user_def_width = g_vdorec_cntx.preview_wnd_width;
    video_preview_data.user_def_height = g_vdorec_cntx.preview_wnd_height;
#else /* __DIRECT_SENSOR_SUPPORT__ */
    video_preview_data.video_size = vdorec_video_size_command_map[g_vdorec_cntx.setting.video_size];
    video_preview_data.user_def_width = 0;
    video_preview_data.user_def_height = 0;
#endif /* __DIRECT_SENSOR_SUPPORT__ */

    video_preview_data.zoom = mmi_vdorec_get_zoom_factor();
    video_preview_data.night = g_vdorec_cntx.setting.night;
    video_preview_data.brightness = 128;
    video_preview_data.contrast = 128;
    video_preview_data.saturation = 128;
    video_preview_data.hue = 0;
    video_preview_data.preview_rotate = VDOREC_MAINLCD_ROTATE;

#ifdef __VDOREC_COLOR_IDX_FRAME__
    if (g_vdorec_cntx.setting.color_idx_frame != VDOREC_SETTING_COLOR_IDX_FRAME_OFF)
    {
        video_preview_data.overlay_frame_mode = TRUE;
        /* although we support 1/2/4/8, but we use 8 only b/c gdi layer support */
        video_preview_data.overlay_frame_depth = OVERLAY_8BPP_PHOTO_FRAME;
        video_preview_data.overlay_frame_width = g_vdorec_cntx.overlay_frame_width;
        video_preview_data.overlay_frame_height = g_vdorec_cntx.overlay_frame_height;
        video_preview_data.overlay_frame_source_key = g_vdorec_cntx.overlay_frame_source_key;
        video_preview_data.overlay_frame_buffer_address = (kal_uint32) g_vdorec_cntx.overlay_frame_buf_ptr;
    }
    else
    {
        video_preview_data.overlay_frame_mode = FALSE;
        video_preview_data.overlay_frame_depth = 0;
        video_preview_data.overlay_frame_width = 0;
        video_preview_data.overlay_frame_height = 0;
        video_preview_data.overlay_frame_source_key = 0;
        video_preview_data.overlay_frame_buffer_address = 0;
    }
#else /* __VDOREC_COLOR_IDX_FRAME__ */ 
    video_preview_data.overlay_frame_mode = FALSE;
    video_preview_data.overlay_frame_depth = 0;
    video_preview_data.overlay_frame_width = 0;
    video_preview_data.overlay_frame_height = 0;
    video_preview_data.overlay_frame_source_key = 0;
    video_preview_data.overlay_frame_buffer_address = 0;
#endif /* __VDOREC_COLOR_IDX_FRAME__ */ 

#ifdef __VDOREC_FEATURE_HORIZONTAL_VIEW__
    video_preview_data.lcm_rotate = MDI_VIDEO_LCD_ROTATE_270;
#else 
    video_preview_data.lcm_rotate = MDI_VIDEO_LCD_ROTATE_0;
#endif 

#ifdef __VDOREC_FEATURE_SIZE_LIMIT__
    switch (g_vdorec_cntx.setting.size_limit)
    {

        case VDOREC_SETTING_SIZE_LIMIT_1:
            video_preview_data.size_limit = VDOREC_FEATURE_SIZE_LIMIT_1;
            break;

        case VDOREC_SETTING_SIZE_LIMIT_2:
            video_preview_data.size_limit = VDOREC_FEATURE_SIZE_LIMIT_2;
            break;

        case VDOREC_SETTING_SIZE_LIMIT_3:
            video_preview_data.size_limit = VDOREC_FEATURE_SIZE_LIMIT_3;
            break;

        default:
            video_preview_data.size_limit = 0;
            break;
    }
#else /* __VDOREC_FEATURE_SIZE_LIMIT__ */ 
    /* no size limit */
    video_preview_data.size_limit = 0;
#endif /* __VDOREC_FEATURE_SIZE_LIMIT__ */ 

    /* if this is an external record request */
    if (g_vdorec_cntx.is_ext_req)
    {
        /* use only external req record size */
        video_preview_data.size_limit = 0;
        if (g_vdorec_cntx.ext_req_size > 0)
        {
            video_preview_data.size_limit = g_vdorec_cntx.ext_req_size;
        }
    }

#ifdef __VDOREC_FEATURE_RECORD_AUD__
    switch (g_vdorec_cntx.setting.record_aud)
    {
        case VDOREC_SETTING_RECORD_AUD_OFF:
            video_preview_data.record_aud = FALSE;
            break;

        case VDOREC_SETTING_RECORD_AUD_ON:
            video_preview_data.record_aud = TRUE;
            break;
    }
#else /* __VDOREC_FEATURE_RECORD_AUD__ */ 
    video_preview_data.record_aud = TRUE;
#endif /* __VDOREC_FEATURE_RECORD_AUD__ */ 

    /*config the video layer*/
    preview_layer_flag = GDI_LAYER_ENABLE_LAYER_0;
    blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0;
    
    if (g_vdorec_cntx.osd_layer_region_count == VDOREC_OSD_LAYER_COUNT_ONE)
    {
        blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1;
    }
    else
    {
        if (g_vdorec_cntx.osd_layer_region_handle[0])
        {
            blt_layer_flag |= GDI_LAYER_ENABLE_LAYER_1;
        }
        
        if (g_vdorec_cntx.osd_layer_region_handle[1])
        {
            blt_layer_flag |= GDI_LAYER_ENABLE_LAYER_2;
        }
        
        if (g_vdorec_cntx.osd_layer_region_handle[2])
        {
            blt_layer_flag |= GDI_LAYER_ENABLE_LAYER_3;
        }
        
#ifdef GDI_6_LAYERS
        if (g_vdorec_cntx.osd_layer_region_handle[3])
        {
            blt_layer_flag |= GDI_LAYER_ENABLE_LAYER_4;
        }
#endif
    }    
    
    if (g_vdorec_cntx.is_use_hw_rotate)
    {
        mdi_video_set_hw_rotator(MDI_CAMERA_PREVIEW_ROTATE_90);
    }

    g_vdorec_cntx.last_error 
        = mdi_video_rec_preview_start(
            g_vdorec_cntx.preview_layer_handle,
            blt_layer_flag,
            preview_layer_flag,
            MMI_TRUE,
            &video_preview_data);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_enter_state
 * DESCRIPTION
 *  enter state
 * PARAMETERS
 *  state       [IN]        
 *  a(?)        [IN]        Next state to be entered
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_enter_state(U16 state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 prev_state;
    S32 video_width;
    S32 video_height;
    U16 prev_zoom;
    S16 error;
    U32 prev_time_sec;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ENTER_STATE, state);

    /* flush key event */
    ClearKeyEvents();
    ClearInputEventHandler(MMI_DEVICE_KEY);
    g_vdorec_cntx.is_lsk_pressed = FALSE;
    g_vdorec_cntx.is_rsk_pressed = FALSE;
    g_vdorec_cntx.is_ck_pressed = FALSE;
    g_vdorec_cntx.is_zoom_in_key_pressed = FALSE;
    g_vdorec_cntx.is_zoom_out_key_pressed = FALSE;
    g_vdorec_cntx.is_ev_inc_key_pressed = FALSE;
    g_vdorec_cntx.is_ev_dec_key_pressed = FALSE;

    #ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__
    g_vdorec_cntx.is_del_key_pressed = FALSE;
    #endif /*  __VDOREC_FEATURE_PREVIEW_SAVED_FILE__ */

    SetKeyHandler(mmi_vdorec_lsk_press_hdlr, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vdorec_lsk_release_hdlr, KEY_LSK, KEY_EVENT_UP);

    SetKeyHandler(mmi_vdorec_rsk_press_hdlr, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vdorec_rsk_release_hdlr, KEY_RSK, KEY_EVENT_UP);

#ifdef __VDOREC_FEATURE_HORIZONTAL_VIEW__
#ifdef __VDOREC_FEATURE_EV__
    SetKeyHandler(mmi_vdorec_inc_ev_key_press_hdlr, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vdorec_inc_ev_key_release_hdlr, KEY_DOWN_ARROW, KEY_EVENT_UP);
    SetKeyHandler(UI_dummy_function, KEY_DOWN_ARROW, KEY_REPEAT);
    SetKeyHandler(mmi_vdorec_dec_ev_key_press_hdlr, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vdorec_dec_ev_key_release_hdlr, KEY_UP_ARROW, KEY_EVENT_UP);
    SetKeyHandler(UI_dummy_function, KEY_UP_ARROW, KEY_REPEAT);
#endif /* __VDOREC_FEATURE_EV__ */
#ifdef __VDOREC_FEATURE_ZOOM__
    SetKeyHandler(mmi_vdorec_zoom_out_key_press_hdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vdorec_zoom_out_key_release_hdlr, KEY_LEFT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(UI_dummy_function, KEY_LEFT_ARROW, KEY_REPEAT);
    SetKeyHandler(mmi_vdorec_zoom_in_key_press_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vdorec_zoom_in_key_release_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(UI_dummy_function, KEY_RIGHT_ARROW, KEY_REPEAT);
#endif /* __VDOREC_FEATURE_ZOOM__ */
#else /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */ /* normal view */
#ifdef __VDOREC_FEATURE_EV__
    SetKeyHandler(mmi_vdorec_inc_ev_key_press_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vdorec_inc_ev_key_release_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(UI_dummy_function, KEY_RIGHT_ARROW, KEY_REPEAT);
    SetKeyHandler(mmi_vdorec_dec_ev_key_press_hdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vdorec_dec_ev_key_release_hdlr, KEY_LEFT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(UI_dummy_function, KEY_LEFT_ARROW, KEY_REPEAT);
#endif /* __VDOREC_FEATURE_EV__ */    
#ifdef __VDOREC_FEATURE_ZOOM__
    SetKeyHandler(mmi_vdorec_zoom_out_key_press_hdlr, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vdorec_zoom_out_key_release_hdlr, KEY_DOWN_ARROW, KEY_EVENT_UP);
    SetKeyHandler(UI_dummy_function, KEY_DOWN_ARROW, KEY_REPEAT);
    SetKeyHandler(mmi_vdorec_zoom_in_key_press_hdlr, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vdorec_zoom_in_key_release_hdlr, KEY_UP_ARROW, KEY_EVENT_UP);
    SetKeyHandler(UI_dummy_function, KEY_UP_ARROW, KEY_REPEAT);
#endif /* __VDOREC_FEATURE_ZOOM__ */
#endif /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */ 

#if !defined(__VDOREC_COLOR_IDX_FRAME__)
#ifdef __VDOREC_FEATURE_ZOOM__
    SetKeyHandler(mmi_vdorec_zoom_out_key_press_hdlr, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vdorec_zoom_out_key_release_hdlr, KEY_VOL_DOWN, KEY_EVENT_UP);
    SetKeyHandler(UI_dummy_function, KEY_VOL_DOWN, KEY_REPEAT);
    SetKeyHandler(mmi_vdorec_zoom_in_key_press_hdlr, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vdorec_zoom_in_key_release_hdlr, KEY_VOL_UP, KEY_EVENT_UP);
    SetKeyHandler(UI_dummy_function, KEY_VOL_UP, KEY_REPEAT);
#endif /* __VDOREC_FEATURE_ZOOM__ */
#endif /* !defined(__VDOREC_COLOR_IDX_FRAME__) */ 

    /* have dedicate record key */
    SetKeyHandler(mmi_vdorec_ck_press_hdlr, VDOREC_RECORD_KEY, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vdorec_ck_release_hdlr, VDOREC_RECORD_KEY, KEY_EVENT_UP);

#ifdef __VDOREC_FEATURE_SWITCH_TO_CAMERA__
    /* key 0 will not use 
    SetKeyHandler(mmi_vdorec_ck_press_hdlr, KEY_0, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vdorec_ck_release_hdlr, KEY_0, KEY_EVENT_UP);
    */
#ifdef __MMI_CAMERA__
    if (VDOREC_SWITCH_TO_CAMERA_KEY != -1 && !g_vdorec_cntx.is_ext_req)
    {
        SetKeyHandler(mmi_vdorec_switch_to_camera_hdlr, VDOREC_SWITCH_TO_CAMERA_KEY, KEY_EVENT_DOWN);
    }
#endif /* __MMI_CAMERA__ */
#endif  /* __VDOREC_FEATURE_SWITCH_TO_CAMERA__ */


    if (VDOREC_RECORD_EXTRA_KEY1 != -1)
    {
        SetKeyHandler(mmi_vdorec_ck_press_hdlr, (U16)(VDOREC_RECORD_EXTRA_KEY1), KEY_EVENT_DOWN);
        SetKeyHandler(mmi_vdorec_ck_release_hdlr, (U16)(VDOREC_RECORD_EXTRA_KEY1), KEY_EVENT_UP);
        SetKeyHandler(mmi_vdorec_null_key_event, (U16)(VDOREC_RECORD_EXTRA_KEY1), KEY_LONG_PRESS);        
    }

    if (VDOREC_RECORD_EXTRA_KEY2 != -1)
    {
        SetKeyHandler(mmi_vdorec_ck_press_hdlr, (U16)(VDOREC_RECORD_EXTRA_KEY2), KEY_EVENT_DOWN);
        SetKeyHandler(mmi_vdorec_ck_release_hdlr, (U16)(VDOREC_RECORD_EXTRA_KEY2), KEY_EVENT_UP);
        SetKeyHandler(mmi_vdorec_null_key_event, (U16)(VDOREC_RECORD_EXTRA_KEY2), KEY_LONG_PRESS);                
    }

    /* hot keys */
#ifdef __VDOREC_FEATURE_VIDEO_SIZE__
    if (VDOREC_VIDEO_SIZE_KEY != -1)
    {
        SetKeyHandler(mmi_vdorec_video_size_hotkey_press, (U16)VDOREC_VIDEO_SIZE_KEY, KEY_EVENT_DOWN);
    }
#endif

#ifdef __VDOREC_FEATURE_VIDEO_QTY__
    if (VDOREC_VIDEO_QTY_KEY != -1)
    {
        SetKeyHandler(mmi_vdorec_video_qty_hotkey_press, (U16)VDOREC_VIDEO_QTY_KEY, KEY_EVENT_DOWN);
    }
#endif

#ifdef __VDOREC_FEATURE_NIGHT__
    if (VDOREC_NIGHT_KEY != -1)
    {
        SetKeyHandler(mmi_vdorec_night_hotkey_press, (U16)VDOREC_NIGHT_KEY, KEY_EVENT_DOWN);
    }
#endif /* __VDOREC_FEATURE_NIGHT__ */ 
    
#ifdef __VDOREC_FEATURE_WB__
    if (VDOREC_WB_KEY != -1)
    {
        SetKeyHandler(mmi_vdorec_wb_hotkey_press, (U16)VDOREC_WB_KEY, KEY_EVENT_DOWN);
    }
#endif /* __VDOREC_FEATURE_WB__ */ 

#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT__
    if (VDOREC_LED_HIGHLIGHT_KEY != -1)
    {
        SetKeyHandler(mmi_vdorec_led_highlight_hotkey_press, (U16)VDOREC_LED_HIGHLIGHT_KEY, KEY_EVENT_DOWN);
    }
#endif /* __VDOREC_FEATURE_LED_HIGHLIGHT__ */ 

#ifdef __VDOREC_FEATURE_RECORD_AUD__
    if (VDOREC_RECORD_AUD_KEY != -1)
    {
        SetKeyHandler(mmi_vdorec_record_aud_hotkey_press, (U16)VDOREC_RECORD_AUD_KEY, KEY_EVENT_DOWN);
    }
#endif /* __VDOREC_FEATURE_WB__ */ 


#ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__
    if (state == VDOREC_STATE_VIDEO_PREVIEW_PLAY || state == VDOREC_STATE_VIDEO_PREVIEW_STOP)
    {
        if (VDOREC_DELETE_KEY != -1)
        {
            SetKeyHandler(mmi_vdorec_del_key_press_hdlr, (U16)VDOREC_DELETE_KEY, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdorec_del_key_release_hdlr, (U16)VDOREC_DELETE_KEY, KEY_EVENT_UP);
        }
    }
#endif /* __VDOREC_FEATURE_PREVIEW_SAVED_FILE__ */

    switch (state)
    {
        case VDOREC_STATE_PREVIEW:
        {
            prev_state = g_vdorec_cntx.state;
            g_vdorec_cntx.state = state;

            if (g_vdorec_cntx.is_watchdog_support)
            {
                mmi_vdorec_reset_watchdog_time_out_handler();
                mmi_vdorec_watchdog_time_out_handler();

                mmi_frm_kbd_reg_pre_key_hdlr(mmi_vdorec_pre_key_listen_hdlr);
                mmi_frm_kbd_reg_post_key_hdlr(mmi_vdorec_post_key_listen_hdlr);           
            }

        #ifdef __VDOREC_COLOR_IDX_FRAME__
            SetKeyHandler(mmi_vdorec_preview_change_frame_up, KEY_VOL_UP, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdorec_preview_change_frame_down, KEY_VOL_DOWN, KEY_EVENT_DOWN);
        #endif /* __VDOREC_COLOR_IDX_FRAME__ */ 

            if (mmi_vdorec_is_in_bgcall())
            {
                mdi_util_show_not_available_in_call_hint(g_vdorec_cntx.preview_layer_handle, 0, 0, 
                    g_vdorec_cntx.preview_wnd_width, g_vdorec_cntx.preview_wnd_height);
            }

            mmi_vdorec_set_softkey(0, 0, IMG_ID_VDOREC_SK_OPTION, IMG_ID_VDOREC_SK_BACK, IMG_ID_VDOREC_SK_RECORD);
            mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY);
            mmi_vdorec_blt_screen();

            /* start preview */
            if (!mmi_vdorec_is_in_bgcall())
            {
                mmi_vdorec_start_preview();
            }
            
            /* error check */
            if (mmi_vdorec_check_and_display_error_popup() == TRUE)     /* TRUE means has error */
            {
                return;
            }

            if (prev_state == VDOREC_STATE_EXIT)
            {
                /* get zoom limit after preview start */
                mmi_vdorec_get_video_size(&video_width, &video_height);
                prev_zoom = g_vdorec_cntx.zoom_limit;
                
                g_vdorec_cntx.zoom_limit = mdi_video_rec_get_max_zoom_factor(video_width, video_height);

                /* if zoom is like 2.6x, round it to 2.0x */
                g_vdorec_cntx.zoom_limit /= 10;
                g_vdorec_cntx.zoom_limit *= 10;

                if (g_vdorec_cntx.zoom_limit < 10)
                {
                    g_vdorec_cntx.zoom_limit = 10;
                }

                if (prev_zoom != g_vdorec_cntx.zoom_limit)
                {
                #ifdef __VDOREC_FEATURE_ZOOM__
                    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_ZOOM);
                #endif
                    mmi_vdorec_blt_screen();
                }
            }
                        
        }
            break;

        case VDOREC_STATE_RECORD:
        {
            prev_state = g_vdorec_cntx.state;
            g_vdorec_cntx.state = state;

            if (g_vdorec_cntx.is_watchdog_support)
            {
                mmi_vdorec_reset_watchdog_time_out_handler();
            }

            mmi_vdorec_set_softkey(
                0, 
                0, 
                IMG_ID_VDOREC_SK_OPTION, 
                IMG_ID_VDOREC_SK_STOP, 
                IMG_ID_VDOREC_SK_PAUSE);

            if (mmi_vdorec_is_draw_progress_bar())
            {
                mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY|VDOREC_OSD_COMPONENT_TIMER|VDOREC_OSD_COMPONENT_PROGRESS|VDOREC_OSD_COMPONENT_STATE);
            }
            else
            {
                mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY|VDOREC_OSD_COMPONENT_TIMER|VDOREC_OSD_COMPONENT_STATE);
            }
            mmi_vdorec_blt_screen();


            if (prev_state == VDOREC_STATE_PAUSE)
            {
                g_vdorec_cntx.last_error = mdi_video_rec_record_resume();

                /* 
                 * this may happend Meida send out record finsih message but MMI not receive it,
                 * meanwhile MMI try to pasue.
                 * MDI will ignore this meassge when some one call pause API at this situation, so
                 * MMI has to enter save screen
                 */
                if (g_vdorec_cntx.last_error == MDI_RES_VDOREC_RECORD_ALREADY_STOP)
                {
                #ifdef __VDOREC_FEATURE_DIRECT_SAVE__
                    mmi_vdorec_entry_saving_screen();
                #else
                    mmi_vdorec_entry_save_confirm_screen();
                #endif /* __VDOREC_FEATURE_DIRECT_SAVE__ */
                    return;
                }
            }
            else
            {
                if (!IsSilentModeActivated())
                {
                    mdi_audio_play_id(TONE_WARNING1, DEVICE_AUDIO_PLAY_ONCE, NULL, NULL);
                }
                kal_sleep_task(200);                     /* sleep mmi to avoid the record tone is being recorded */
            
                /* before record start, commit the seq num */
                ReadValue(NVRAM_VDOREC_FILENAME_SEQ_NO, &g_vdorec_cntx.filename_seq_no, DS_SHORT, &error);
                g_vdorec_cntx.filename_seq_no++;
                WriteValue(NVRAM_VDOREC_FILENAME_SEQ_NO, &g_vdorec_cntx.filename_seq_no, DS_SHORT, &error);
                
                g_vdorec_cntx.last_error = mdi_video_rec_record_start(g_vdorec_cntx.filepath, mmi_vdorec_record_result_hdlr_callback);
            }
            #if 0
/* under construction !*/
            #endif /* 0 */
            /* error check */
            if (mmi_vdorec_check_and_display_error_popup() == TRUE)     /* TRUE means has error */
            {
                return;
            }

            /* start draw timer */
            mmi_vdorec_record_timer_cyclic();
        }
            break;

        case VDOREC_STATE_PAUSE:
        {
            g_vdorec_cntx.state = state;

        #ifdef __VDOREC_COLOR_IDX_FRAME__
            SetKeyHandler(mmi_vdorec_preview_change_frame_up, KEY_VOL_UP, KEY_EVENT_DOWN);
            SetKeyHandler(mmi_vdorec_preview_change_frame_down, KEY_VOL_DOWN, KEY_EVENT_DOWN);
        #endif /* __VDOREC_COLOR_IDX_FRAME__ */ 

        #if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__)
            mmi_vdorec_set_softkey(0, 0, IMG_ID_VDOREC_SK_OPTION, IMG_ID_VDOREC_SK_STOP, IMG_ID_VDOREC_SK_RESUME);
        #else /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) */ 
            mmi_vdorec_set_softkey(
                0,
                0,
                IMG_ID_VDOREC_SK_OPTION,
                IMG_ID_VDOREC_SK_STOP,
                IMG_ID_VDOREC_SK_RESUME);
        #endif /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) */ 

            gui_cancel_timer(mmi_vdorec_record_timer_cyclic);
            if (g_vdorec_cntx.is_timer_show)
            {
                /* draw the record time when before stopping on screen */
                prev_time_sec = (U32) (g_vdorec_cntx.record_time / 1000);            
                mdi_video_rec_get_cur_record_time(&g_vdorec_cntx.record_time);
                if ((g_vdorec_cntx.record_time / 1000) > prev_time_sec)
                {
                    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_TIMER | VDOREC_OSD_COMPONENT_SOFTKEY|VDOREC_OSD_COMPONENT_STATE);
                }
                else
                {
                    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY|VDOREC_OSD_COMPONENT_STATE);
                }
			}
            else
            {
                mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY|VDOREC_OSD_COMPONENT_STATE);
            }
            mmi_vdorec_blt_screen();

            g_vdorec_cntx.last_error = mdi_video_rec_record_pause(KAL_FALSE);

            /* 
             * this may happend Meida send out record finsih message but MMI not receive it,
             * meanwhile MMI try to pasue.
             * MDI will ignore this meassge when some one call pause API at this situation, so
             * MMI has to enter save screen
             */
            if (g_vdorec_cntx.last_error == MDI_RES_VDOREC_RECORD_ALREADY_STOP)
            {
            #ifdef __VDOREC_FEATURE_DIRECT_SAVE__
                mmi_vdorec_entry_saving_screen();
            #else
                mmi_vdorec_entry_save_confirm_screen();
            #endif /* __VDOREC_FEATURE_DIRECT_SAVE__ */
                return;
            }
            else if (g_vdorec_cntx.last_error == MDI_RES_VDOREC_DISK_FULL)
            {
                mmi_vdorec_disply_popup(
                    (PU8) GetString(FMGR_FS_DISK_FULL_TEXT),
                    MMI_EVENT_FAILURE);
                return;
            }
            else if (g_vdorec_cntx.last_error == MDI_RES_VDOREC_REACH_SIZE_LIMIT)
            {
                mmi_vdorec_disply_popup(
                    (PU8) GetString(STR_ID_VDOREC_SIZE_LIMIT),
                    MMI_EVENT_INFO);
                return;
            }

            #if 0
/* under construction !*/
            #endif
            /* pasue error check */
            if (mmi_vdorec_check_and_display_error_popup() == TRUE)     /* TRUE means has error */
            {
                return;
            }
        }
            break;
    #ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__
        case VDOREC_STATE_VIDEO_PREVIEW_PLAY:
        #ifdef __MMI_CAMERA__
            if (VDOREC_SWITCH_TO_CAMERA_KEY != -1 && !g_vdorec_cntx.is_ext_req)
            {
                SetKeyHandler(UI_dummy_function, VDOREC_SWITCH_TO_CAMERA_KEY, KEY_EVENT_DOWN);
            }
        #endif /* __MMI_CAMERA__ */

            mmi_vdorec_fsm_preview_play();
            g_vdorec_cntx.state = state;

            if (VDOREC_SWITCH_TO_CAMERA_KEY != -1)
            {
                SetKeyHandler(UI_dummy_function, VDOREC_SWITCH_TO_CAMERA_KEY, KEY_EVENT_DOWN);
            }
            if (VDOREC_DELETE_KEY != -1)
            {
                SetKeyHandler(mmi_vdorec_del_key_press_hdlr, (U16)VDOREC_DELETE_KEY, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_vdorec_del_key_release_hdlr, (U16)VDOREC_DELETE_KEY, KEY_EVENT_UP);
            }
            /* overwrite record key */
            SetKeyHandler(GoBackHistory, VDOREC_RECORD_KEY, KEY_EVENT_UP);
        
            break;
            
        case VDOREC_STATE_VIDEO_PREVIEW_STOP:
        #ifdef __MMI_CAMERA__
            if (VDOREC_SWITCH_TO_CAMERA_KEY != -1 && !g_vdorec_cntx.is_ext_req)
            {
                SetKeyHandler(UI_dummy_function, VDOREC_SWITCH_TO_CAMERA_KEY, KEY_EVENT_DOWN);
            }
        #endif /* __MMI_CAMERA__ */

            mmi_frm_kbd_reg_pre_key_hdlr(mmi_vdorec_preview_idle_timeout_cancel);
            g_vdorec_cntx.state = state;
            mmi_vdorec_fsm_preview_stop();
            if (VDOREC_SWITCH_TO_CAMERA_KEY != -1)
            {
                SetKeyHandler(UI_dummy_function, VDOREC_SWITCH_TO_CAMERA_KEY, KEY_EVENT_DOWN);
            }
            if (VDOREC_DELETE_KEY != -1)
            {
                SetKeyHandler(mmi_vdorec_del_key_press_hdlr, (U16)VDOREC_DELETE_KEY, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_vdorec_del_key_release_hdlr, (U16)VDOREC_DELETE_KEY, KEY_EVENT_UP);
            }
            /* overwrite record key */            
            SetKeyHandler(GoBackHistory, VDOREC_RECORD_KEY, KEY_EVENT_UP);
            break;
            
        case VDOREC_STATE_VIDEO_PREVIEW_BGCALL:
        #ifdef __MMI_CAMERA__
            if (VDOREC_SWITCH_TO_CAMERA_KEY != -1 && !g_vdorec_cntx.is_ext_req)
            {
                SetKeyHandler(UI_dummy_function, VDOREC_SWITCH_TO_CAMERA_KEY, KEY_EVENT_DOWN);
            }
        #endif /* __MMI_CAMERA__ */

            mmi_frm_kbd_reg_pre_key_hdlr(mmi_vdorec_preview_idle_timeout_cancel);
            g_vdorec_cntx.state = state;
            if (VDOREC_SWITCH_TO_CAMERA_KEY != -1)
            {
                SetKeyHandler(UI_dummy_function, VDOREC_SWITCH_TO_CAMERA_KEY, KEY_EVENT_DOWN);
            }
            if (VDOREC_DELETE_KEY != -1)
            {
                SetKeyHandler(mmi_vdorec_del_key_press_hdlr, (U16)VDOREC_DELETE_KEY, KEY_EVENT_DOWN);
                SetKeyHandler(mmi_vdorec_del_key_release_hdlr, (U16)VDOREC_DELETE_KEY, KEY_EVENT_UP);
            }
            /* overwrite record key */            
            SetKeyHandler(GoBackHistory, VDOREC_RECORD_KEY, KEY_EVENT_UP);            
            break;
    #endif /* __VDOREC_FEATURE_PREVIEW_SAVED_FILE__ */
    
        default:
            ASSERT(0);
            break;

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_clam_close_event_hdlr
 * DESCRIPTION
 *  handle clam close event
 * PARAMETERS
 *  ptr     [IN]        Message data ptr
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) 
static U8 mmi_vdorec_clam_close_event_hdlr(mmi_frm_int_event_type interrupt_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_CLAM_CLOSE_EVENT_HDLR);

    if (interrupt_event & MMI_FRM_INT_CLAM)
    {
        if (interrupt_event == MMI_FRM_INT_CLAM_CLOSE)
        {
            GoBackHistory();
            return FALSE;
        }
    }

    /* return false means will pass this interrut to default handler */
    return FALSE;
}

#endif /* defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_del_app_screen_hdlr
 * DESCRIPTION
 *  del app screen callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_vdorec_del_app_screen_hdlr(void *ptr)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filepath[FMGR_PATH_BUFFER_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_DEL_APP_SCREEN_HDLR);

    if (g_vdorec_cntx.is_watchdog_support)
    {
        mmi_vdorec_reset_watchdog_time_out_handler();
    }

#ifdef __DIRECT_SENSOR_SUPPORT__
    /* 
     * 6223 will call mdi_video_rec_limited_avi_deinit here, 
     * so we need to stop rec first 
     */

    if (g_vdorec_cntx.state == VDOREC_STATE_RECORD)
    {
        mdi_video_rec_record_stop();
    }
    else if (g_vdorec_cntx.state == VDOREC_STATE_PREVIEW)
    {
        mdi_video_rec_preview_stop();
    }
    else if (g_vdorec_cntx.state == VDOREC_STATE_PAUSE)
    {
        mdi_video_rec_record_stop();
        mdi_video_rec_preview_stop();
    }

    g_vdorec_cntx.state = VDOREC_STATE_EXIT;

    /* free resouce */
    mdi_video_rec_limited_avi_deinit();

    /* clean tmp files */
    mmi_vdoply_get_storage_file_path(buf_filepath);
    mdi_video_rec_delete_unsaved_file(buf_filepath);

#else

    /* always clean up tmp files */
    mmi_vdoply_get_storage_file_path(buf_filepath);
    mdi_video_rec_delete_unsaved_file(buf_filepath);
    
#endif /* __DIRECT_SENSOR_SUPPORT__ */

    g_vdorec_cntx.is_change_storage = FALSE;

#if defined(__MMI_OP12_CAMERA_VDOREC_CUSTOMIZE__) && defined(__VDOREC_FEATURE_VIDEO_SIZE_SQCIF__)
    if (g_vdorec_cntx.is_ext_req)
    {
        g_vdorec_cntx.setting.video_size = g_vdorec_cntx.old_video_size; /* restore the video size setting to original */
    }
#endif  /* defined(__MMI_OP12_CAMERA_VDOREC_CUSTOMIZE__) && defined(__VDOREC_FEATURE_VIDEO_SIZE_SQCIF__) */

    g_vdorec_cntx.is_foward_to = FALSE;
    
#ifdef __VDOREC_ROTATE_OSD_FOR_HW_ROTATOR__
    mmi_vdorec_free_app_mem();
#endif

    return FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_app
 * DESCRIPTION
 *  Video recoder entry point
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_entry_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ENTRY_APP);
/* Vogins Start */
/*michael 100506 begin*/
#if defined(__VRE30_AM__)
    if (!med_check_memory_is_enough(MAX_MED_VID_ENC_EXT_MEM_SIZE+LCD_WIDTH*LCD_HEIGHT*VDOREC_BUFFER_DEPTH*2)) 
    {
        mmi_ap_prompt_to_release_mem(MMI_AP_MED_VIDEO_ID, 0, MAX_MED_VID_ENC_EXT_MEM_SIZE+LCD_WIDTH*LCD_HEIGHT*VDOREC_BUFFER_DEPTH*2, mmi_vdorec_entry_app);
        return;
    }
#endif
/*michael 100506 end*/
/* Vogins End */
    /* disable external reqeust flag */
    g_vdorec_cntx.is_ext_req = MMI_FALSE;
    g_vdorec_cntx.is_use_ext_req_path = MMI_FALSE;
#ifdef __VDOREC_FEATURE_CALL_ACCEPT_OPTION__   
    g_vdorec_cntx.old_call_mode = MMI_FALSE;
#endif

#ifdef __VDOREC_ROTATE_OSD_FOR_HW_ROTATOR__
    if (g_vdorec_cntx.app_mem_bufer == NULL)
    {
        if (!mmi_vdorec_malloc_app_mem())
        {
            mmi_frm_appmem_prompt_to_release_mem(
                STR_ID_VDOREC_APP_NAME,
                IMG_ID_VDOREC_APP_ICON,
                VDOREC_APP_MEMORY_BUFFER_SIZE,
                mmi_vdorec_entry_app);
            return;
        }
    }
#endif

#if defined(__MMI_BACKGROUND_CALL__)
    if (mmi_vdorec_is_in_bgcall())
    {
        mmi_ucm_app_entry_error_message();
        return;
    }
#endif /* __MMI_BACKGROUND_CALL__ */

    mmi_vdorec_entry_app_internal();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_app_pre_check
 * DESCRIPTION
 *  return wheather video recorder should be available now.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_vdorec_entry_app_pre_check(PS8 p_filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 cur_storage;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ENTRY_APP_PRE_CHECK);

#if defined(__USB_IN_NORMAL_MODE__)
    if (mmi_usb_is_in_mass_storage_mode() && mmi_usb_check_path_exported((PS8)p_filepath))
    {
        /* in mass storage mode */
        if (mmi_usb_check_path_exported((PS8)p_filepath))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            DeleteScreenIfPresent(SCR_ID_VDOREC_APP);
            return MMI_FALSE;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

#ifdef __VDOREC_FEATURE_STORAGE__
    /* check if there is no storage or not*/
    {
        U8 storage_total_num;
        U32 *drv_inline_list_p;
        U8 highlight_idx;

        mmi_fmgr_get_exist_storage_inline_list(
            (S8)mmi_vdoply_get_storage(),
            &storage_total_num,
            (PU32)&drv_inline_list_p,
            &highlight_idx);

        if (storage_total_num == 0)
        {
            mmi_vdorec_disply_popup(
                (PU8)GetString(STR_GLOBAL_INSERT_MEMORY_CARD),
                MMI_EVENT_FAILURE);
            DeleteScreenIfPresent(SCR_ID_VDOREC_APP);
            return MMI_FALSE;
        }
    }
#endif

#ifdef __MMI_BT_SUPPORT__
    /* if is 6223 or 6225 series, cant concurrent with background BT action */
    if (mmi_bt_is_receiving())
    {
        mmi_vdorec_disply_popup(
            (PU8)GetString(STR_ID_VDOREC_NOTIFY_BT_IS_WORKING),
            MMI_EVENT_FAILURE);
        DeleteScreenIfPresent(SCR_ID_VDOREC_APP);
        return MMI_FALSE;
    }
#endif /* __MMI_BT_SUPPORT__ */


#if !defined(MDI_VIDEO_MT6228_SERIES)
    /* this is used to solve MMS background send, which will cause bandwidth not enoguth */
    if(mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_DATA_CSD_ALL))
    {
        mmi_vdorec_disply_popup(
            (PU8)GetString(STR_ID_VDOREC_NOTIFY_SYSTEM_TOO_BUSY),
            MMI_EVENT_FAILURE);
        DeleteScreenIfPresent(SCR_ID_VDOREC_APP);
        return MMI_FALSE;
    }
#endif /* !defined(MDI_VIDEO_MT6228_SERIES) */

    /* 
     * Check if device is busy, this may happened user abort file copying, 
     * but driver is till aborting 
     */
    cur_storage = mmi_vdoply_get_storage();

    if (FS_GetDevStatus(cur_storage, FS_FEATURE_STATE_ENUM) == FS_DEVICE_BUSY)
    {
        mmi_vdorec_disply_popup(
            (PU8)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE),
            MMI_EVENT_FAILURE);
        DeleteScreenIfPresent(SCR_ID_VDOREC_APP);
        return MMI_FALSE;
    }

#if defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) && defined(__MTK_TARGET__)
    /* back to idle if clam is closed */
    if (IsClamClose())
    {
        DisplayIdleScreen();
        return MMI_FALSE;
    }
#endif /* defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) && defined(__MTK_TARGET__) */ 

#if defined(__DIRECT_SENSOR_SUPPORT__) || defined(MT6253T) || defined(MT6253)
    if (cbm_disallow_bearer_activation() == KAL_FALSE)
    {
        cbm_disallow_bearer_error_popup();
        DeleteScreenIfPresent(SCR_ID_VDOREC_APP);
        return MMI_FALSE;
    }
#endif /* __DIRECT_SENSOR_SUPPORT__ */

#if defined(__MMI_OP01_DCD__)
    if (mmi_dcd_is_syncing())
    {
        mmi_dcd_running_conflict_prompt();
        DeleteScreenIfPresent(SCR_ID_VDOREC_APP);
        return MMI_FALSE;
    }
    else
    {
        mmi_dcd_line_taken();
    }
#endif

#ifdef __VDOREC_FEATURE_STORAGE__
    if (g_vdorec_cntx.is_change_storage)
    {
        g_vdorec_cntx.is_direct_exit = TRUE;
        g_vdorec_cntx.is_change_storage = FALSE;
        
        EntryNewScreen(SCR_ID_VDOREC_APP, mmi_vdorec_exit_app, mmi_vdorec_entry_app_internal, MMI_FULL_SCREEN);
    
        mmi_vdorec_entry_set_app_storage_screen();
        return MMI_FALSE;
    }
#endif /* __VDOREC_FEATURE_STORAGE__ */    

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_app_internal
 * DESCRIPTION
 *  video record app entry point
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_entry_app_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filepath[FMGR_PATH_BUFFER_SIZE];
    U8 *guiBuffer;
    U16 cur_storage;
    S32 create_result;
    S32 layer_offset_x;
    S32 layer_offset_y;
    S32 layer_width;
    S32 layer_height;
    PU8 base_layer_ptr;
    S32 buffer_size;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ENTRY_APP_INTERNAL);

    
    /* load setting */
    mmi_vdorec_load_setting();
    mmi_vdoply_get_storage_file_path(buf_filepath);

    if (mmi_vdorec_entry_app_pre_check(buf_filepath) == MMI_FALSE)
    {
        if (!IsScreenPresent(SCR_ID_VDOREC_APP))
        {
            mmi_vdorec_free_app_mem();
        }
        return; /* pre check failed, video recorder is not available now. */
    }

    EntryNewScreen(SCR_ID_VDOREC_APP, mmi_vdorec_exit_app, mmi_vdorec_entry_app_internal, MMI_FULL_SCREEN);
    SetDelScrnIDCallbackHandler(SCR_ID_VDOREC_APP, mmi_vdorec_del_app_screen_hdlr);

    mmi_vdorec_init_according_to_compile_option();

#ifdef __MMI_BT_SUPPORT__
    mmi_bt_disable_receiving();   /* disable BT back ground receive. remember to resume when exit this screen */
#endif

    g_vdorec_cntx.is_direct_exit = FALSE;
    
    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();

    entry_full_screen();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_VDOREC_APP);

    /* entry sublcd */
#ifdef __MMI_SUBLCD__
    if (!mmi_is_redrawing_bk_screens())
    {
        if (!g_vdorec_cntx.is_sub_display)
        {
            ForceSubLCDScreen(mmi_vdorec_entry_sublcd_screen);
        }
    }
#endif /* __MMI_SUBLCD__ */ 

#if defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) 
    /* register event hdlr */
    mmi_frm_block_interrupt_event_handler(MMI_FRM_INT_CLAM, mmi_vdorec_clam_close_event_hdlr, NULL);
#endif /* defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) */ 

    /* hook to touch screen callback */
#if defined(__VDOREC_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_pen_down_handler(mmi_vdorec_touch_scr_pen_down_hdlr);
    wgui_register_pen_up_handler(mmi_vdorec_touch_scr_pen_up_hdlr);
    wgui_register_pen_move_handler(mmi_vdorec_touch_scr_pen_move_hdlr);
#endif /* defined(__VDOREC_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__) */ 

    if (guiBuffer == NULL)
    {
        /* each time newly enter vdorec, zoom will be reset to default */
        g_vdorec_cntx.setting.zoom = VDOREC_DEFAULT_SETTING_ZOOM;
        g_vdorec_cntx.zoom_limit = VDOREC_FEAUTRE_ZOOM_LIMIT;

    #ifdef __DIRECT_SENSOR_SUPPORT__
        mdi_video_rec_limited_avi_init();
    #endif

        if(g_vdorec_cntx.is_ext_req && VDOREC_SETTING_VIDEO_SIZE_COUNT != g_vdorec_cntx.ext_video_size)
        {
            g_vdorec_cntx.setting.video_size = g_vdorec_cntx.ext_video_size;
        }
    }

    /* init some golbal value */
    g_vdorec_cntx.last_error = MDI_RES_VDOREC_SUCCEED;
    g_vdorec_cntx.record_time = 0;
    g_vdorec_cntx.is_lsk_pressed = FALSE;
    g_vdorec_cntx.is_rsk_pressed = FALSE;
    g_vdorec_cntx.is_ck_pressed = FALSE;
    g_vdorec_cntx.is_zoom_in_key_pressed = FALSE;
    g_vdorec_cntx.is_zoom_out_key_pressed = FALSE;
    g_vdorec_cntx.is_ev_inc_key_pressed = FALSE;
    g_vdorec_cntx.is_ev_dec_key_pressed = FALSE;

    #ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__
    g_vdorec_cntx.is_del_key_pressed = FALSE;
    #endif /*  __VDOREC_FEATURE_PREVIEW_SAVED_FILE__ */

    /* clear hint buffer */
    memset(g_vdorec_cntx.hint1_buf, 0, VDOREC_HINT_BUF_SIZE);
    memset(g_vdorec_cntx.hint2_buf, 0, VDOREC_HINT_BUF_SIZE);

    /* allocate storage path by using submenu's buffer */
    g_vdorec_cntx.storage_filepath = gui_malloc(FMGR_PATH_BUFFER_SIZE);

    /* check if path is valid or not. if not will pop up a screen after the preview screen is shown */
    cur_storage = mmi_vdoply_get_storage();

    /* if no error. load path into buffer */
    mmi_vdoply_get_storage_file_path((PS8) g_vdorec_cntx.storage_filepath);
    create_result = mmi_vdoply_create_file_dir((PS8) g_vdorec_cntx.storage_filepath);

   /*******************************************************************
   * Init proper global state for video applcation  
   ********************************************************************/
    /* force all playing keypad tone off */
    AudioStopReq(GetCurKeypadTone());

    /* disable key pad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);

    /* enable multi_layer */
    gdi_layer_multi_layer_enable();

    /* suspend background play */
    mdi_audio_suspend_background_play();

    /* disalbe align timer */
    UI_disable_alignment_timers();

    /* stop LED patten */
    StopLEDPatternBackGround();

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

    /* use medium font */
    gui_set_font(&MMI_medium_font);

    g_vdorec_cntx.prev_rotate_by_layer = gdi_lcd_get_rotate_by_layer();


#ifdef __MMI_TVOUT__
    if (!mdi_tvout_is_enable())
    {
        /* if no TV-out, rotate by layer */
        gdi_lcd_set_rotate_by_layer(TRUE);
    }
    else
    {   
        /* if have Tv-out rotate by LCM */
        gdi_lcd_set_rotate_by_layer(FALSE);
    }
#else
    /* if no TV-out, rotate by layer */
    gdi_lcd_set_rotate_by_layer(TRUE);
#endif /* __MMI_TVOUT__ */


    /***************************************************************************** 
     * Create layers 
     *****************************************************************************/
#ifdef __VDOREC_FEATURE_HORIZONTAL_VIEW__


    if (g_vdorec_cntx.is_use_hw_rotate)
    {
        /* MT6238/53 series, will use IDP/LCD rotator */
        gdi_lcd_set_rotate(GDI_LAYER_ROTATE_0);      
    }
    else 
    {
        /* defined(MDI_VIDEO_MT6238_SERIES) */
        gdi_lcd_set_rotate(GDI_LAYER_ROTATE_270);
    }

#ifdef __MMI_TVOUT__
    if (mdi_tvout_is_enable())
    {
        mdi_tvout_set_mode(MDI_TV_MODE_MULTIMEDIA_HOR_LCD_SCR, 0, 0);
    }
#endif /* __MMI_TVOUT__ */ 

#endif /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */ 

   /************ base layer layer ************/
    gdi_layer_get_base_handle(&g_vdorec_cntx.bg_layer_handle);
    
    gdi_layer_push_and_set_active(g_vdorec_cntx.bg_layer_handle);
    gdi_layer_get_buffer_ptr(&base_layer_ptr);
    gdi_layer_pop_and_restore_active();

#ifdef __VDOREC_FEATURE_HORIZONTAL_VIEW__
    g_vdorec_cntx.lcd_width = UI_device_height;
    g_vdorec_cntx.lcd_height = UI_device_width;

    if (!g_vdorec_cntx.is_use_hw_rotate)
    {
        /* if not use hw rotator, we will change the bg layer to horizontal size */
        /* if use hw rotator, we will change the bg layer to portrait size */
        gdi_layer_resize(g_vdorec_cntx.lcd_width, g_vdorec_cntx.lcd_height);
    }
    else
    {
        g_vdorec_cntx.lcd_width = UI_device_width;
        g_vdorec_cntx.lcd_height = UI_device_height;
    }

#else /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */ 
    g_vdorec_cntx.lcd_width = UI_device_width;
    g_vdorec_cntx.lcd_height = UI_device_height;

#endif /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */ 

    /************ preview window layer ************/
#ifdef __DIRECT_SENSOR_SUPPORT__
    g_vdorec_cntx.preview_wnd_width = IMAGE_VIDEO_PREVIEW_WIDTH;
    g_vdorec_cntx.preview_wnd_height = IMAGE_VIDEO_PREVIEW_HEIGHT;

    g_vdorec_cntx.preview_wnd_offset_x = g_vdorec_osd_cntx.preview_wnd.rect.offset_x;
    g_vdorec_cntx.preview_wnd_offset_x += 
          ((g_vdorec_osd_cntx.preview_wnd.rect.width - IMAGE_VIDEO_PREVIEW_WIDTH) >> 1);        
    
    g_vdorec_cntx.preview_wnd_offset_y = g_vdorec_osd_cntx.preview_wnd.rect.offset_y;
    g_vdorec_cntx.preview_wnd_offset_y += 
        ((g_vdorec_osd_cntx.preview_wnd.rect.height - IMAGE_VIDEO_PREVIEW_HEIGHT) >> 1);            

#else /* __DIRECT_SENSOR_SUPPORT__ */
    g_vdorec_cntx.preview_wnd_width = g_vdorec_osd_cntx.preview_wnd.rect.width;
    g_vdorec_cntx.preview_wnd_height = g_vdorec_osd_cntx.preview_wnd.rect.height;
    g_vdorec_cntx.preview_wnd_offset_x = g_vdorec_osd_cntx.preview_wnd.rect.offset_x;
    g_vdorec_cntx.preview_wnd_offset_y = g_vdorec_osd_cntx.preview_wnd.rect.offset_y;
#endif /* __DIRECT_SENSOR_SUPPORT__ */

#ifdef __VDOREC_FEATURE_HORIZONTAL_VIEW__

#ifdef __MMI_SCREEN_ROTATE__
    mmi_frm_set_self_rotation_flag(MMI_FRM_SCREEN_ROTATE_270);
#endif 

    if (g_vdorec_cntx.is_use_hw_rotate)
    {
        if (g_vdorec_cntx.is_use_hw_rotate_by_lcd)
        {
            layer_offset_x = g_vdorec_cntx.preview_wnd_offset_x;
            layer_offset_y = g_vdorec_cntx.preview_wnd_offset_y;
            layer_width = g_vdorec_cntx.preview_wnd_width;
            layer_height = g_vdorec_cntx.preview_wnd_height;     
        }
        else
        {
            layer_offset_x = 
                UI_device_width - 
                g_vdorec_cntx.preview_wnd_offset_y - 
                g_vdorec_cntx.preview_wnd_height;
            layer_offset_y = g_vdorec_cntx.preview_wnd_offset_x;
            layer_width = g_vdorec_cntx.preview_wnd_height;
            layer_height = g_vdorec_cntx.preview_wnd_width;   
        }
    }
    else
    { 
        layer_offset_x = g_vdorec_cntx.preview_wnd_offset_x;
        layer_offset_y = g_vdorec_cntx.preview_wnd_offset_y;
        layer_width = g_vdorec_cntx.preview_wnd_width;
        layer_height = g_vdorec_cntx.preview_wnd_height;    
    }

    /*gdi_layer_create(
        layer_offset_x,
        layer_offset_y,
        layer_width,
        layer_height,
        &g_vdorec_cntx.preview_layer_handle);*/

    buffer_size = layer_width * layer_height * VDOREC_BUFFER_DEPTH;
    gdi_layer_create_using_outside_memory(
        layer_offset_x,
        layer_offset_y,
        layer_width,
        layer_height,
        &g_vdorec_cntx.preview_layer_handle,
        base_layer_ptr,
        buffer_size);

    gdi_layer_push_and_set_active(g_vdorec_cntx.preview_layer_handle);

    if (g_vdorec_cntx.is_use_hw_rotate && g_vdorec_cntx.is_use_hw_rotate_by_lcd)
    {
        gdi_layer_set_rotate(GDI_LCD_LAYER_ROTATE_90);
    }

    gdi_layer_clear(GDI_COLOR_BLACK);

#ifdef GDI_USING_LAYER_BACKGROUND
    gdi_layer_set_background(GDI_COLOR_BLACK);
#endif

#else /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */ 

    /*gdi_layer_create(
        g_vdorec_cntx.preview_wnd_offset_x,
        g_vdorec_cntx.preview_wnd_offset_y,
        g_vdorec_cntx.preview_wnd_width,
        g_vdorec_cntx.preview_wnd_height,
        &g_vdorec_cntx.preview_layer_handle);*/

    buffer_size = g_vdorec_cntx.preview_wnd_width * g_vdorec_cntx.preview_wnd_height * VDOREC_BUFFER_DEPTH;
    gdi_layer_create_using_outside_memory(
        g_vdorec_cntx.preview_wnd_offset_x,
        g_vdorec_cntx.preview_wnd_offset_y,
        g_vdorec_cntx.preview_wnd_width,
        g_vdorec_cntx.preview_wnd_height,
        &g_vdorec_cntx.preview_layer_handle,
        base_layer_ptr,
        buffer_size);

    gdi_layer_push_and_set_active(g_vdorec_cntx.preview_layer_handle);

    gdi_layer_clear(GDI_COLOR_BLACK);

#ifdef GDI_USING_LAYER_BACKGROUND
    gdi_layer_set_background(GDI_COLOR_BLACK);
#endif

#endif /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */ 

    gdi_layer_pop_and_restore_active();

    /* resized preview layer */
#ifdef __VDOREC_FEATURE_VIDEO_SIZE__
    mmi_vdorec_resize_preview_layer();
#endif 

   /***************************************************************************** 
   * register interrupt event hdlr
   *****************************************************************************/
    #ifdef __VDOREC_FEATURE_CALL_ACCEPT_OPTION__
        if (!g_vdorec_cntx.setting.accept_call)
        {
            g_vdorec_cntx.old_call_mode = mmi_blacklist_get_reject_all_mode();
            mmi_blacklist_set_reject_all_mode(TRUE);
        }
    #endif /* __VDOREC_FEATURE_CALL_ACCEPT_OPTION__ */

    mmi_frm_block_general_interrupt_event(
        MMI_FRM_INT_CHARGER | 
        MMI_FRM_INT_USB_CHARGER |
        MMI_FRM_INT_SMS | 
        MMI_FRM_INT_FMGR_CARD | 
        MMI_FRM_INT_WAP_MMS | 
        MMI_FRM_INT_BT_TASK |
        MMI_FRM_INT_MMI_JAVA_TIMEALARM_PUSH);

   /****************************************************************************
   * draw skin                                                                 
   *****************************************************************************/
    mmi_vdorec_init_ui();

    gdi_layer_reset_clip(); /* use full screen clip */
    gui_reset_text_clip();  /* use full screen text clip */

    gdi_layer_lock_frame_buffer(); 

    g_vdorec_cntx.progress = 0;

	 mmi_vdorec_set_softkey(
        0,
        0,
        IMG_ID_VDOREC_SK_OPTION,
        IMG_ID_VDOREC_SK_BACK,
        IMG_ID_VDOREC_SK_RECORD);

    mmi_vdorec_draw_osd(
        VDOREC_OSD_COMPONENT_STATUS|
        VDOREC_OSD_COMPONENT_EV|
        VDOREC_OSD_COMPONENT_ZOOM|
        VDOREC_OSD_COMPONENT_SOFTKEY);

    gdi_layer_unlock_frame_buffer();

	if (g_vdorec_cntx.osd_layer_region_count == VDOREC_OSD_LAYER_COUNT_ONE)
	{
		gdi_layer_set_blt_layer(
			g_vdorec_cntx.preview_layer_handle,
			g_vdorec_cntx.osd_layer_handle,
			0,
			0);
	}
	else if (g_vdorec_cntx.osd_layer_region_count == VDOREC_OSD_LAYER_COUNT_THREE)
	{
		gdi_layer_set_blt_layer(
			g_vdorec_cntx.preview_layer_handle,
			g_vdorec_cntx.osd_layer_region_handle[0],
			g_vdorec_cntx.osd_layer_region_handle[1],
			g_vdorec_cntx.osd_layer_region_handle[2]);
	}
#ifdef GDI_6_LAYERS
	else
	{    
		gdi_layer_set_blt_layer_ext(
			g_vdorec_cntx.preview_layer_handle,
			g_vdorec_cntx.osd_layer_region_handle[0],
			g_vdorec_cntx.osd_layer_region_handle[1],
			g_vdorec_cntx.osd_layer_region_handle[2],
			g_vdorec_cntx.osd_layer_region_handle[3],
			0);
	}
#endif

    if (g_vdorec_cntx.is_use_blt_region)
    {
        /*if enter new screen ,should redraw full screen, for some area is use layer background to fill color*/
        mmi_vdorec_set_merge_region(0,0, g_vdorec_cntx.lcd_width, g_vdorec_cntx.lcd_height);
    }

    mmi_vdorec_blt_screen();

    /* this function is entry by small screen's history draw, no need to open file */
    if (mmi_is_redrawing_bk_screens())
    {
        return;
    }

    /* check if storage exist or not */
    if (create_result != FS_NO_ERROR)
    {
        U16 string_id = STR_GLOBAL_ERROR;
        S32 event_type = MMI_EVENT_FAILURE;

        string_id = mmi_fmgr_util_get_fs_error_info(create_result, &event_type);
        
            /* storage not exist */            
            mmi_vdorec_disply_popup(
            (PU8)GetString(string_id),
            event_type);

        /* 
         * Storage has error, set this flag and re-enter app screen, 
         * will launch storage selection screen 
         */
        g_vdorec_cntx.is_change_storage = TRUE;

    #ifndef __VDOREC_FEATURE_STORAGE__        
        /* if no storage to change, will leave app */
        DeleteNHistory(1);

        if (g_vdorec_cntx.is_ext_req)
        {
            g_vdorec_cntx.ext_req_callback(MMI_FALSE, NULL);    
            g_vdorec_cntx.ext_req_callback = NULL;
        }
    #endif /* __VDOREC_FEATURE_STORAGE__ */
        return;

    }


    /* power on HW */
    if (g_vdorec_cntx.last_error == MDI_RES_VDOREC_SUCCEED && !mmi_vdorec_is_in_bgcall())
    {
        /* do not power on if is in call */
        g_vdorec_cntx.last_error = mdi_video_rec_power_on();
    }

    if (mmi_vdorec_check_and_display_error_popup() != TRUE) /* !TRUE means error popup displayed */
    {
        /* 
         * if record finish has popup, it will not entry saving directly, 
         * after popup gone, we have to enter saving procedure 
         */

        /* ask media if there is a unsaved file */
        mmi_vdoply_get_storage_file_path(buf_filepath);

        if (g_vdorec_cntx.is_ext_req && guiBuffer == NULL)
        {
            /* delete unsaved file */
            mdi_video_rec_delete_unsaved_file(buf_filepath);

            if (!g_vdorec_cntx.is_use_ext_req_path)
            {
                /* not using ext req path, we have to get a filename */
                mmi_vdorec_get_save_filename(g_vdorec_cntx.filepath);
            }
            
            mmi_vdorec_enter_state(VDOREC_STATE_PREVIEW);
            mmi_vdorec_turn_on_led_highlight();
        }
        else
        {
            mmi_vdoply_get_storage_file_path(g_vdorec_cntx.filepath);
            mmi_vdorec_load_saved_filename(g_vdorec_cntx.filepath);
        #ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__
            if (mdi_video_rec_has_unsaved_file(buf_filepath) && g_vdorec_cntx.is_ext_req)
            {
                mmi_vdorec_entry_saving_screen();
                return;
            }
        #endif /* __VDOREC_FEATURE_PREVIEW_SAVED_FILE__ */
        
            if (mdi_video_rec_has_unsaved_file(buf_filepath) == TRUE)
            {
                mmi_vdorec_entry_save_confirm_screen();
                return;
            }
            else
            {
                /* generate a new filename */
                mmi_vdorec_get_save_filename(g_vdorec_cntx.filepath);
                mmi_vdorec_enter_state(VDOREC_STATE_PREVIEW);
                mmi_vdorec_turn_on_led_highlight();
            }
        }

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_exit_app
 * DESCRIPTION
 *  video recorder ext function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_exit_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    gdi_handle base_layer_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_EXIT_APP);

    if (g_vdorec_cntx.is_watchdog_support)
    {
        mmi_vdorec_reset_watchdog_time_out_handler();
    }

    if (g_vdorec_cntx.is_direct_exit)
    {
        /* 
         * when enter app and we found that we need to change storage, we will show 
         * change strage screen directly, so we dont need execute this exit function 
         */
        return;
    }
    
#if defined(__DIRECT_SENSOR_SUPPORT__) || defined(MT6253T) || defined(MT6253)
    cbm_allow_bearer_activation();
#endif

#if defined(__MMI_OP01_DCD__)
    mmi_dcd_line_given();
#endif

    /* cancel active timer */
    gui_cancel_timer(mmi_vdorec_record_timer_cyclic);
    gui_cancel_timer(mmi_vdorec_hide_hint);

#ifdef __VDOREC_FEATURE_ZOOM__
    /*stop zoom*/
	if (g_vdorec_cntx.is_fast_zoom_support)
	{
		mmi_vdorec_stop_fast_zoom();
		gui_cancel_timer(mmi_vdorec_draw_zoom_osd);
		gui_cancel_timer(mmi_vdorec_start_fast_zoom_out);
		gui_cancel_timer(mmi_vdorec_start_fast_zoom_in);
	}
	else
	{
		mmi_vdorec_stop_fast_zoom();
		gui_cancel_timer(mmi_vdorec_zoom_in);
		gui_cancel_timer(mmi_vdorec_zoom_out);
	}
#endif /* __VDOREC_FEATURE_ZOOM__ */ 

#ifdef __VDOREC_FEATURE_EV__
    gui_cancel_timer(mmi_vdorec_inc_ev);
    gui_cancel_timer(mmi_vdorec_dec_ev);
#endif /* __VDOREC_FEATURE_EV__ */

    if (g_vdorec_cntx.state == VDOREC_STATE_RECORD)
    {
        mdi_video_rec_record_stop();
    }
    else if (g_vdorec_cntx.state == VDOREC_STATE_PREVIEW)
    {
        mdi_video_rec_preview_stop();
    }
    else if (g_vdorec_cntx.state == VDOREC_STATE_PAUSE)
    {
        mdi_video_rec_record_stop();
        mdi_video_rec_preview_stop();
    }

	g_vdorec_cntx.state = VDOREC_STATE_EXIT;

    mmi_vdorec_store_setting();

    mdi_video_rec_power_off();

    mmi_vdorec_turn_off_led_highlight();

    /*for we use base layer as preview layer handle, so we must reset and clear base layer image*/
    gdi_layer_get_base_handle(&base_layer_handle);
    gdi_layer_push_and_set_active(base_layer_handle);
    gdi_layer_set_rotate(GDI_LCD_LAYER_ROTATE_0);
    gdi_layer_resize(LCD_WIDTH, LCD_HEIGHT);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();

    /*continue flatten*/
    //gdi_layer_flatten_previous_to_base();

    /* free layer */

    /* free preview layers */
    gdi_layer_free(g_vdorec_cntx.preview_layer_handle);
    g_vdorec_cntx.preview_layer_handle = 0;

    /*release tmp layer handle*/
    if (g_vdorec_cntx.is_use_hw_rotate)
    {
        for (i = 0 ; i < g_vdorec_cntx.osd_layer_region_count ; i ++)
        {
            gdi_layer_free(g_vdorec_cntx.tmp_osd_layer_region_handle[i]);
            g_vdorec_cntx.tmp_osd_layer_region_handle[i] = GDI_LAYER_EMPTY_HANDLE;
            
            //mmi_frm_scrmem_free(g_vdorec_cntx.tmp_osd_layer_region_handle_ptr[i]);
            g_vdorec_cntx.tmp_osd_layer_region_handle_ptr[i] = NULL;    
        }
    }
    
#ifdef __VDOREC_FEATURE_SHOW_STATUS_BAR__
    wgui_status_icon_set_display_layer(g_vdorec_cntx.prev_status_bar_layer_handle);
    
    if (g_vdorec_cntx.status_bar_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(g_vdorec_cntx.status_bar_layer_handle);
        g_vdorec_cntx.status_bar_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }
#endif /* __VDOPLY_FEATURE_SHOW_STATUS_BAR__ */
    
#ifdef __VDOREC_COLOR_IDX_FRAME__
    /* free color idx frame layer */
    gdi_layer_free(g_vdorec_cntx.overlay_frame_layer_handle);
    g_vdorec_cntx.overlay_frame_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    
    mmi_frm_scrmem_free((void*)g_vdorec_cntx.overlay_frame_buf_ptr);
    g_vdorec_cntx.overlay_frame_buf_ptr = NULL;
#endif /* __VDOREC_COLOR_IDX_FRAME__ */ 

    if (g_vdorec_cntx.osd_layer_region_count == VDOREC_OSD_LAYER_COUNT_ONE)
    {
        if (g_vdorec_cntx.osd_layer_handle)
        {
            gdi_layer_free(g_vdorec_cntx.osd_layer_handle);
            mmi_frm_scrmem_free(g_vdorec_cntx.osd_layer_buf_ptr);
            g_vdorec_cntx.osd_layer_buf_ptr = NULL;
        }
    }
    else
    {
        for (i = 0 ; i < g_vdorec_cntx.osd_layer_region_count ; i++)
        {
            if (g_vdorec_cntx.osd_layer_region_handle[i] != GDI_LAYER_EMPTY_HANDLE)
            {
                gdi_layer_free(g_vdorec_cntx.osd_layer_region_handle[i]);
                g_vdorec_cntx.osd_layer_region_handle[i] = GDI_LAYER_EMPTY_HANDLE;
                
                mmi_frm_scrmem_free(g_vdorec_cntx.osd_layer_region_handle_ptr[i]);
                g_vdorec_cntx.osd_layer_region_handle_ptr[i] = NULL;
            }
        }
    }
   
#ifdef __VDOREC_FEATURE_HORIZONTAL_VIEW__
    if (g_vdorec_cntx.is_use_hw_rotate)
    {
        mdi_video_set_hw_rotator(MDI_VIDEO_LCD_ROTATE_0);                
    }
    gdi_lcd_set_rotate(GDI_LAYER_ROTATE_0);

    gdi_layer_resize(UI_device_width, UI_device_height);

#ifdef __MMI_TVOUT__
    if (mdi_tvout_is_enable())
    {
        mdi_tvout_set_mode(MDI_TV_MODE_LCD_SCR, 0, 0);
    }
#endif /* __MMI_TVOUT__ */ 

    /* clear in black layer if it is horizontal view */
    gdi_layer_clear(GDI_COLOR_BLACK);
    
#endif /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */ 

    /* restore rotate layer flag */
    gdi_lcd_set_rotate_by_layer(g_vdorec_cntx.prev_rotate_by_layer);

    /* disable multi layer */
    gdi_layer_multi_layer_disable();

    /* resume alignment timer */
    UI_disable_alignment_timers();

    /* resume LED patten */
    StartLEDPatternBackGround();

    /* let MMI can sleep */
    TurnOffBacklight();

    /* resume background audio */
    mdi_audio_resume_background_play();

    /* re-enable keypad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

    /* free buffer */
    gui_free(g_vdorec_cntx.storage_filepath);
    g_vdorec_cntx.storage_filepath = NULL;

    /* exit sublcd */
#ifdef __MMI_SUBLCD__
    /* exit app screen if exist , and not exit because toggle self capture to sublcd */
    if (g_vdorec_cntx.is_sub_display)
    {
        GoBackSubLCDHistory();
        g_vdorec_cntx.is_sub_display = FALSE;
    }
#endif /* __MMI_SUBLCD__ */ 


#ifdef __MMI_BT_SUPPORT__
    mmi_bt_enable_receiving();   /* enable BT back ground receive. remember to resume when exit this screen */
#endif

    if (g_vdorec_cntx.gdi_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(g_vdorec_cntx.gdi_layer_handle);
        g_vdorec_cntx.gdi_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }

    #ifdef __VDOREC_FEATURE_CALL_ACCEPT_OPTION__
    if (!g_vdorec_cntx.setting.accept_call)
    {
        /* restore */
        mmi_blacklist_set_reject_all_mode(g_vdorec_cntx.old_call_mode);
    }
    #endif /* __VDOREC_FEATURE_CALL_ACCEPT_OPTION__ */

    mmi_frm_clear_interrupt_event_handler(MMI_FRM_INT_WAP_MMS | MMI_FRM_INT_BT_TASK | MMI_FRM_INT_GPIO);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_draw_sublcd_icon
 * DESCRIPTION
 *  draw a sublcd icon.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
static void mmi_vdorec_draw_sublcd_icon(void)
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
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_DRAW_SUBLCD_ICON);

    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_lcd_get_dimension(&lcd_width, &lcd_height);

    gdi_layer_reset_clip();

    gdi_layer_clear_background(GDI_COLOR_WHITE);
    gdi_image_get_dimension_id(IMG_ID_VDOREC_SUBLCD_ICON, &image_width, &image_height);
    gdi_image_draw_id((lcd_width - image_width) >> 1, (lcd_height - image_height) >> 1, IMG_ID_VDOREC_SUBLCD_ICON);
    gdi_layer_blt_base_layer(0, 0, lcd_width - 1, lcd_height - 1);

    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
}
#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_sublcd_screen
 * DESCRIPTION
 *  entry sublcd screen, if still remain on standard MMI sublcd screen, time update will
 *  redraw sublcd while mainlcd is previewing, will cause driver assert.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
static void mmi_vdorec_entry_sublcd_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ENTRY_SUBLCD_SCREEN);

    ExecSubLCDCurrExitHandler();
    ShowCategory331Screen();
    SetSubLCDExitHandler(mmi_vdorec_exit_sublcd_screen);

    /* draw a icon on sub */
    mmi_vdorec_draw_sublcd_icon();

    g_vdorec_cntx.is_sub_display = TRUE;
}
#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_exit_sublcd_screen
 * DESCRIPTION
 *  exit sublcd screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
static void mmi_vdorec_exit_sublcd_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SubLCDHistoryNode SubLCDHistory;

    /* someone may exit/draw sublcd first then exit mainlcd, this may cause driver assert */
    /* also stop preview here */

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_EXIT_SUBLCD_SCREEN);

    if (g_vdorec_cntx.state == VDOREC_STATE_RECORD)
    {
        mdi_video_rec_record_stop();
    }
    else if (g_vdorec_cntx.state == VDOREC_STATE_PREVIEW)
    {
        mdi_video_rec_preview_stop();
    }
    else if (g_vdorec_cntx.state == VDOREC_STATE_PAUSE)
    {
        mdi_video_rec_record_stop();
        mdi_video_rec_preview_stop();
    }

    g_vdorec_cntx.state = VDOREC_STATE_EXIT;

    /* exit sub */
    g_vdorec_cntx.is_sub_display = FALSE;

    SubLCDHistory.entryFuncPtr = mmi_vdorec_entry_sublcd_screen;
    AddSubLCDHistory(&SubLCDHistory);
}
#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_record_timer_cyclic
 * DESCRIPTION
 *  record timer cyclic to get and draw timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_record_timer_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U64 prev_time_in_sec;
    U32 time_in_sec;
    U64 prev_progress;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_RECORD_TIMER_CYLIC, g_vdorec_cntx.is_timer_show);

	if (!g_vdorec_cntx.is_timer_show)
	{
		return;
	}

    prev_time_in_sec = (U32) (g_vdorec_cntx.record_time / 1000);

    mdi_video_rec_get_cur_record_time(&g_vdorec_cntx.record_time);
    time_in_sec = (U32) (g_vdorec_cntx.record_time / 1000);

    /* time limit check */
#ifdef __VDOREC_FEATURE_TIME_LIMIT__
    if (g_vdorec_cntx.is_ext_req)
    {
        if ( g_vdorec_cntx.ext_rec_time != 0)
        {
            if (time_in_sec >= g_vdorec_cntx.ext_rec_time)
            {
                mdi_video_rec_record_stop();

                mmi_vdorec_disply_popup(
                    (PU8) GetString(STR_ID_VDOREC_TIME_LIMIT),
                    MMI_EVENT_INFO);
                return;
            }
        }
    }
    else
    {
        /* from video recorder app (not external request) */
        if (g_vdorec_cntx.setting.time_limit > VDOREC_SETTING_TIME_LIMIT_NO_LIMIT &&
            g_vdorec_cntx.setting.time_limit < VDOREC_SETTING_TIME_LIMIT_COUNT)
        {
            if(time_in_sec >= vdorec_video_time_limit_command_map[g_vdorec_cntx.setting.time_limit])
            {
                mdi_video_rec_record_stop();
                
                mmi_vdorec_disply_popup(
                    (PU8) GetString(STR_ID_VDOREC_TIME_LIMIT),
                    MMI_EVENT_INFO);
                return;
            }
        }
    }

#if 0    
    #ifdef __VDOREC_FEATURE_LIMIT_ALERT__
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
    #endif /* __VDOREC_FEATURE_LIMIT_ALERT__ */            
#endif /* 0 */    
#endif /* __VDOREC_FEATURE_TIME_LIMIT__ */ 

    if ((time_in_sec > prev_time_in_sec) || (prev_time_in_sec == 0))
    {
        mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_TIMER);
        mmi_vdorec_blt_screen();
    }
    
	/*draw progress*/
    if (mmi_vdorec_is_draw_progress_bar())
    {
        prev_progress = g_vdorec_cntx.progress;
        mmi_vdorec_update_progress_ratio();
        if (g_vdorec_cntx.progress > prev_progress)
        {
            mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_PROGRESS);
            mmi_vdorec_blt_screen();
        }
     }

    gui_start_timer(200, mmi_vdorec_record_timer_cyclic);
}


static void mmi_vdorec_draw_bg_image(void)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_DRAW_BG_IMAGE);

    gdi_layer_push_and_set_active(g_vdorec_cntx.osd_layer_handle);
    gdi_image_draw_id(0, 0, IMG_ID_VDOREC_OSD_BG);
    gdi_layer_pop_and_restore_active();

    if (g_vdorec_cntx.is_use_blt_region)
    {
        mmi_vdorec_merge_blt_rgn(0, 0, g_vdorec_cntx.lcd_width, g_vdorec_cntx.lcd_height);
    }
}


static void mmi_vdorec_draw_bg_color(void)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_DRAW_BG_IMAGE);
    
    gdi_layer_push_and_set_active(g_vdorec_cntx.osd_layer_handle);
    
    gdi_draw_solid_rect(0, 0, g_vdorec_cntx.lcd_width, g_vdorec_cntx.preview_wnd_offset_y, GDI_COLOR_BLACK);
    gdi_draw_solid_rect(0, 0, g_vdorec_cntx.preview_wnd_offset_x, g_vdorec_cntx.lcd_height, GDI_COLOR_BLACK);
    gdi_draw_solid_rect(0, g_vdorec_cntx.preview_wnd_offset_y + g_vdorec_cntx.preview_wnd_height, 
        g_vdorec_cntx.lcd_width, g_vdorec_cntx.lcd_height, GDI_COLOR_BLACK);
    gdi_draw_solid_rect(g_vdorec_cntx.preview_wnd_offset_x + g_vdorec_cntx.preview_wnd_width, 0, 
        g_vdorec_cntx.lcd_width, g_vdorec_cntx.lcd_height, GDI_COLOR_BLACK);

    gdi_layer_pop_and_restore_active();
    
    if (g_vdorec_cntx.is_use_blt_region)
    {
        mmi_vdorec_merge_blt_rgn(0, 0, g_vdorec_cntx.lcd_width, g_vdorec_cntx.lcd_height);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_draw_title
 * DESCRIPTION
 *  draw title
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_draw_title(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_width;
    S32 str_height;
    S32 offset_x;
    S32 offset_y;
    S32 layer_offset_x;
    S32 layer_offset_y;
    PS8 str_ptr;
    video_rect_struct *bbox_rect_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_DRAW_TITLE);

	if (!g_vdorec_osd_cntx.title.is_draw_app_name)
	{
		return;
	}

    gdi_layer_push_and_set_active(g_vdorec_cntx.title_draw_layer);

    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

    /* display filename */
    if (g_vdorec_osd_cntx.title.is_draw_app_name)
    {   
        bbox_rect_p = &g_vdorec_osd_cntx.title.rect;

        gui_set_text_clip(
            bbox_rect_p->offset_x - layer_offset_x,
            bbox_rect_p->offset_y - layer_offset_y,
            bbox_rect_p->offset_x + bbox_rect_p->width - layer_offset_x - 1,
            bbox_rect_p->offset_y + bbox_rect_p->height - layer_offset_y - 1);

        str_ptr = (PS8) GetString(STR_ID_VDOREC_APP_NAME);

        gui_measure_string((UI_string_type) str_ptr, &str_width, &str_height);

        if (g_vdorec_osd_cntx.title.v_align == VIDEO_ALIGN_TOP)
        {
            offset_y = 0;
        }
        else if (g_vdorec_osd_cntx.title.v_align == VIDEO_ALIGN_BOTTOM)
        {
            offset_y = bbox_rect_p->height - str_height;
        }
        else    /* center */
        {
            offset_y = (bbox_rect_p->height - str_height) >> 1;
        }

        offset_y += bbox_rect_p->offset_y;

        if (g_vdorec_osd_cntx.title.h_align == VIDEO_ALIGN_LEFT)
        {
            offset_x = 0;
        }
        else if (g_vdorec_osd_cntx.title.h_align == VIDEO_ALIGN_RIGHT)
        {
            offset_x = bbox_rect_p->width - str_width;
        }
        else
        {
            offset_x = (bbox_rect_p->width - str_width) >> 1;
        }

        offset_x += bbox_rect_p->offset_x;

        mmi_vdorec_draw_style_text(
            str_ptr, 
            offset_x - layer_offset_x, 
            offset_y - layer_offset_y, 
            0,
            &g_vdorec_osd_cntx.title.style_text);

        gui_reset_text_clip();  /* restore clip to full screen */

        if (g_vdorec_cntx.is_use_blt_region)
        {
            mmi_vdorec_merge_blt_rgn(
                bbox_rect_p->offset_x,
                bbox_rect_p->offset_y,
                bbox_rect_p->width,
                bbox_rect_p->height);
        }
    }
    
#ifdef __VDOREC_FEATURE_SHOW_STATUS_BAR__
    show_status_icons();  
#endif /* __VDOREC_FEATURE_SHOW_STATUS_BAR__ */

    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_clear_status
 * DESCRIPTION
 *  clear video recorder status icons.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_clear_status(void)
{
    video_osd_vdorec_status_struct *status_p;
    S32 image_width, image_height;
    S32 layer_offset_x, layer_offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_CLEAR_STATUS, g_vdorec_osd_cntx.status.is_show);

    if (!g_vdorec_osd_cntx.status.is_show)
    {
        return;
    }

    status_p = &g_vdorec_osd_cntx.status;

    gdi_layer_push_and_set_active(g_vdorec_cntx.status_draw_layer);

    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

#define CLEAR_OSD_ICON(a,A)                                                                             \
    do                                                                                                  \
    {                                                                                                   \
        if(status_p->##a##.is_show)                                                                     \
        {                                                                                               \
            gdi_image_get_dimension_id(IMG_ID_VDOREC_OSD_##A##_START + 1, &image_width, &image_height); \
            gdi_draw_solid_rect(                                                                        \
                status_p->##a##.offset_x - layer_offset_x,                                              \
                status_p->##a##.offset_y - layer_offset_y,                                              \
                status_p->##a##.offset_x + image_width - layer_offset_x,                                \
                status_p->##a##.offset_y + image_height - layer_offset_y,                               \
                GDI_COLOR_TRANSPARENT);                                                                 \
            if (g_vdorec_cntx.is_use_blt_region)                                                        \
            {                                                                                           \
                mmi_vdorec_merge_blt_rgn(                                                               \
                    status_p->##a##.offset_x, status_p->##a##.offset_y, image_width, image_height);     \
            }                                                                                           \
        }                                                                                               \
    } while(0);                                                                                         \

#ifdef __VDOREC_FEATURE_VIDEO_SIZE__
    CLEAR_OSD_ICON(video_size, VIDEO_SIZE);
#endif
    
#ifdef __VDOREC_FEATURE_VIDEO_QTY__
    CLEAR_OSD_ICON(video_qty, VIDEO_QTY);
#endif
    
#ifdef __VDOREC_FEATURE_NIGHT__
    CLEAR_OSD_ICON(night, NIGHT);
#endif 
    
#ifdef __VDOREC_FEATURE_WB__
    CLEAR_OSD_ICON(wb, WB);
#endif
    
#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT__
    CLEAR_OSD_ICON(led_highlight, LED_HIGHLIGHT);
#endif 
    
#ifdef __VDOREC_FEATURE_RECORD_AUD__
    CLEAR_OSD_ICON(record_aud, RECORD_AUD);
#endif 
    
#ifdef __VDOREC_FEATURE_SIZE_LIMIT__
    CLEAR_OSD_ICON(size_limit, SIZE_LIMIT);
#endif 
    
#ifdef __VDOREC_FEATURE_TIME_LIMIT__
    CLEAR_OSD_ICON(time_limit, TIME_LIMIT);
#endif 

    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_draw_status
 * DESCRIPTION
 *  draw video recorder status icons.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_draw_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    video_osd_vdorec_status_struct *status_p;
    S32 layer_offset_x, layer_offset_y;
    S32 image_width, image_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_DRAW_STATUS, g_vdorec_osd_cntx.status.is_show);

    if (!g_vdorec_osd_cntx.status.is_show)
    {
        return;
    }

    status_p = &g_vdorec_osd_cntx.status;

    gdi_layer_push_and_set_active(g_vdorec_cntx.status_draw_layer);

    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

   /****** draw icon MACRO ******/
#define DRAW_OSD_ICON(a,A)                                                                           \
    do {                                                                                             \
      if(status_p->##a##.is_show)                                                                    \
      {                                                                                              \
         gdi_image_get_dimension_id(IMG_ID_VDOREC_OSD_##A##_START + 1, &image_width, &image_height); \
         gdi_image_draw_id(status_p->##a##.offset_x - layer_offset_x,                                \
                           status_p->##a##.offset_y - layer_offset_y,                                \
                           (U16)(IMG_ID_VDOREC_OSD_##A##_START+g_vdorec_cntx.setting.##a##+1));      \
         if (g_vdorec_cntx.is_use_blt_region)                                                        \
         {                                                                                           \
            mmi_vdorec_merge_blt_rgn(                                                             \
            status_p->##a##.offset_x, status_p->##a##.offset_y, image_width, image_height);          \
         }                                                                                           \
      }                                                                                              \
   } while(0);

#ifdef __VDOREC_FEATURE_VIDEO_SIZE__
    DRAW_OSD_ICON(video_size, VIDEO_SIZE);
#endif

#ifdef __VDOREC_FEATURE_VIDEO_QTY__
    DRAW_OSD_ICON(video_qty, VIDEO_QTY);
#endif

#ifdef __VDOREC_FEATURE_NIGHT__
    DRAW_OSD_ICON(night, NIGHT);
#endif 

#ifdef __VDOREC_FEATURE_WB__
    DRAW_OSD_ICON(wb, WB);
#endif

#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT__
    DRAW_OSD_ICON(led_highlight, LED_HIGHLIGHT);
#endif 

#ifdef __VDOREC_FEATURE_RECORD_AUD__
    DRAW_OSD_ICON(record_aud, RECORD_AUD);
#endif 

#ifdef __VDOREC_FEATURE_SIZE_LIMIT__
    DRAW_OSD_ICON(size_limit, SIZE_LIMIT);
#endif 

#ifdef __VDOREC_FEATURE_TIME_LIMIT__
    DRAW_OSD_ICON(time_limit, TIME_LIMIT);
#endif 

    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_draw_softkey
 * DESCRIPTION
 *  draw softkey bar (softkey)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_draw_softkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 lsk_offset_x;
    S32 lsk_offset_y;
    S32 rsk_offset_x;
    S32 rsk_offset_y;
    S32 ck_offset_x;
    S32 ck_offset_y;
    S32 img_width;
    S32 img_height;
    S32 layer_offset_x;
    S32 layer_offset_y;
    U16 image_id = 0;

#ifdef __VDOREC_FEATURE_TOUCH_SCREEN__
    vdorec_ui_touch_struct *touch_p;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_DRAW_SOFTKEY);

    gdi_layer_reset_clip();

    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

    if ((g_vdorec_osd_cntx.softkey.is_lsk_icon != FALSE) && (g_vdorec_cntx.lsk_img_id != 0))
    {
        gdi_image_get_dimension_id(g_vdorec_cntx.lsk_img_id, &img_width, &img_height);
        
        lsk_offset_x = g_vdorec_osd_cntx.softkey.icon_lsk_pos.offset_x;
        lsk_offset_y = g_vdorec_osd_cntx.softkey.icon_lsk_pos.offset_y;
        
#ifdef __VDOREC_FEATURE_TOUCH_SCREEN__
        
        touch_p = &g_vdorec_cntx.touch_lsk;
        touch_p->offset_x = lsk_offset_x;
        touch_p->offset_y = lsk_offset_y;
        touch_p->width = img_width;
        touch_p->height = img_height;
        
#endif /* __VDOREC_FEATURE_TOUCH_SCREEN__ */ 
     
        gdi_layer_push_and_set_active(g_vdorec_cntx.lsk_draw_layer);
        
        gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

        if (!g_vdorec_cntx.is_disp_bg_img && !g_vdorec_cntx.is_disp_bg_img_usint_color)
        {
            gdi_draw_solid_rect(lsk_offset_x - layer_offset_x, lsk_offset_y - layer_offset_y - 1, lsk_offset_x+img_width - 1, lsk_offset_y+img_height, GDI_COLOR_TRANSPARENT);
        }
        
        if (g_vdorec_cntx.is_lsk_pressed)
        {
            image_id = g_vdorec_cntx.lsk_img_id + 1;
        }
        else
        {
            image_id = g_vdorec_cntx.lsk_img_id;
        }

        gdi_image_draw_id(
            lsk_offset_x - layer_offset_x, 
            lsk_offset_y - layer_offset_y, 
            image_id);
        
        gdi_layer_pop_and_restore_active();

        if (g_vdorec_cntx.is_use_blt_region)
        {
            mmi_vdorec_merge_blt_rgn(
                lsk_offset_x, 
                lsk_offset_y,
                img_width,
                img_height);
        }
    }

    if ((g_vdorec_osd_cntx.softkey.is_rsk_icon != FALSE) && (g_vdorec_cntx.rsk_img_id != 0))
    {
#if defined(__VDOREC_FEATURE_PREVIEW_SAVED_FILE__) && defined(__VDOREC_FEATURE_RSK_DELETE__)
        /* change the RSK image id */
        if (GetExitScrnID() == SCR_ID_VDOREC_SAVED_PREVIEW)
        {
            g_vdorec_cntx.rsk_img_id = IMG_ID_VDOREC_SK_DELETE;   
        }
#endif /*  __VDOREC_FEATURE_RSK_DELETE__ */
        
        gdi_image_get_dimension_id(g_vdorec_cntx.rsk_img_id, &img_width, &img_height);          
        
        rsk_offset_x = g_vdorec_osd_cntx.softkey.icon_rsk_pos.offset_x;
        rsk_offset_y = g_vdorec_osd_cntx.softkey.icon_rsk_pos.offset_y;
        
        
#ifdef __VDOREC_FEATURE_TOUCH_SCREEN__
        
        touch_p = &g_vdorec_cntx.touch_rsk;
        touch_p->offset_x = rsk_offset_x;
        touch_p->offset_y = rsk_offset_y;
        touch_p->width = img_width;
        touch_p->height = img_height;
        
#endif /* __VDOREC_FEATURE_TOUCH_SCREEN__ */ 
        
        gdi_layer_push_and_set_active(g_vdorec_cntx.rsk_draw_layer);
        
        gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

        if (!g_vdorec_cntx.is_disp_bg_img && !g_vdorec_cntx.is_disp_bg_img_usint_color)
        {
            gdi_draw_solid_rect(rsk_offset_x - layer_offset_x, rsk_offset_y - layer_offset_y, rsk_offset_x+img_width, rsk_offset_y+img_height, GDI_COLOR_TRANSPARENT);
        }
        
        if (g_vdorec_cntx.is_rsk_pressed)
        {
            image_id = g_vdorec_cntx.rsk_img_id + 1;
        }
        else
        {
            image_id = g_vdorec_cntx.rsk_img_id;
        }
        
    /*currently del key and rsk location are both rsk, but the image are different*/
    #if defined(__VDOREC_FEATURE_PREVIEW_SAVED_FILE__) && defined(__VDOREC_FEATURE_RSK_DELETE__)
        if (SCR_ID_VDOREC_SAVED_PREVIEW == GetActiveScreenId())
        {
            if (g_vdorec_cntx.is_del_key_pressed)
            {
                image_id = g_vdorec_cntx.rsk_img_id + 1;
            }
            else
            {
                image_id = g_vdorec_cntx.rsk_img_id;
            }
        }
    #endif

        gdi_image_draw_id(
            rsk_offset_x - layer_offset_x, 
            rsk_offset_y - layer_offset_y, 
            image_id);

        gdi_layer_pop_and_restore_active();

        if (g_vdorec_cntx.is_use_blt_region)
        {
            mmi_vdorec_merge_blt_rgn(
                rsk_offset_x, 
                rsk_offset_y,
                img_width,
                img_height);
        }
    }   

    if (g_vdorec_osd_cntx.softkey.is_ck_icon)
    {

        /* draw c key */

        if (g_vdorec_cntx.ck_img_id != 0)
        {
            gdi_image_get_dimension_id(g_vdorec_cntx.ck_img_id, &img_width, &img_height);

            ck_offset_x = g_vdorec_osd_cntx.softkey.icon_ck_pos.offset_x;
            ck_offset_y = g_vdorec_osd_cntx.softkey.icon_ck_pos.offset_y;

        #ifdef __VDOREC_FEATURE_TOUCH_SCREEN__
            
            touch_p = &g_vdorec_cntx.touch_ck;
            touch_p->offset_x = ck_offset_x;
            touch_p->offset_y = ck_offset_y;
            touch_p->width = img_width;
            touch_p->height = img_height;
            
        #endif /* __VDOREC_FEATURE_TOUCH_SCREEN__ */

            gdi_layer_push_and_set_active(g_vdorec_cntx.ck_draw_layer);

            if (!g_vdorec_cntx.is_disp_bg_img && !g_vdorec_cntx.is_disp_bg_img_usint_color)
            {
                gdi_draw_solid_rect(ck_offset_x - layer_offset_x, ck_offset_y - layer_offset_y, ck_offset_x+img_width, ck_offset_y+img_height, GDI_COLOR_TRANSPARENT);
            }
            
            if (g_vdorec_cntx.is_ck_pressed)
            {
                image_id = g_vdorec_cntx.ck_img_id + 1;
            }
            else
            {
                image_id = g_vdorec_cntx.ck_img_id;
            }

            gdi_image_draw_id(
                ck_offset_x - layer_offset_x, 
                ck_offset_y- layer_offset_y, 
                image_id);

            gdi_layer_pop_and_restore_active();

            if (g_vdorec_cntx.is_use_blt_region)
            {
                mmi_vdorec_merge_blt_rgn(
                    ck_offset_x, 
                    ck_offset_y,
                    img_width,
                    img_height);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_set_softkey
 * DESCRIPTION
 *  Set softkey string ptr that will be draw
 * PARAMETERS
 *  lsk_str_ptr     [IN]        Lsk string pointer
 *  rsk_str_ptr     [IN]        Rsk string pointer
 *  lsk_img_id      [IN]        Lsk image id
 *  rsk_img_id      [IN]        Rsk image id
 *  ck_img_id       [IN]        Ck_image id
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_set_softkey(PS8 lsk_str_ptr, PS8 rsk_str_ptr, U16 lsk_img_id, U16 rsk_img_id, U16 ck_img_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_SET_SOFTKEY);

    g_vdorec_cntx.lsk_img_id = lsk_img_id;
    g_vdorec_cntx.rsk_img_id = rsk_img_id;
    g_vdorec_cntx.ck_img_id = ck_img_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_draw_panel_state
 * DESCRIPTION
 *  draw panel state (stop, pause, record)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_draw_panel_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_offset_x;
    S32 layer_offset_y;    
    S32 image_width;
    S32 image_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_DRAW_PANEL_STATE);

    /*state is always showed with timer*/
    if (!g_vdorec_cntx.is_timer_show)
    {
         return;
    }

    gdi_layer_push_and_set_active(g_vdorec_cntx.state_draw_layer);

    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

    gdi_image_get_dimension_id(IMG_ID_VDOREC_TIME_NUMBER_0, &image_width, &image_height);

    if (g_vdorec_cntx.state != VDOREC_STATE_RECORD)
    {
        gdi_draw_solid_circle(
            g_vdorec_cntx.timer.hr_0_offset_x - VDOREC_TIME_STATE_REDIUS * 2 - 1 - layer_offset_x,
            g_vdorec_cntx.timer.offset_y + ((image_height - VDOREC_TIME_STATE_REDIUS * 2) >> 1) + VDOREC_TIME_STATE_REDIUS- layer_offset_y,
            VDOREC_TIME_STATE_REDIUS,
            GDI_COLOR_GREEN);
    }
    else
    {
        gdi_draw_solid_circle(
            g_vdorec_cntx.timer.hr_0_offset_x - VDOREC_TIME_STATE_REDIUS * 2 - 1 - layer_offset_x,
            g_vdorec_cntx.timer.offset_y + ((image_height - VDOREC_TIME_STATE_REDIUS * 2) >> 1) + VDOREC_TIME_STATE_REDIUS - layer_offset_y,
            VDOREC_TIME_STATE_REDIUS,
            GDI_COLOR_RED);
    }

    gdi_layer_pop_and_restore_active();

    if (g_vdorec_cntx.is_use_blt_region)
    {
        mmi_vdorec_merge_blt_rgn(
            g_vdorec_cntx.timer.hr_0_offset_x - VDOREC_TIME_STATE_REDIUS * 3 - 1,
            g_vdorec_cntx.timer.offset_y,
            VDOREC_TIME_STATE_REDIUS >> 1,
            VDOREC_TIME_STATE_REDIUS >> 1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_draw_panel_ev
 * DESCRIPTION
 *  draw panel ev
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_draw_panel_ev(void)
{
#ifdef __VDOREC_FEATURE_EV__	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_offset_x;
    S32 layer_offset_y;    
    S32 image_width;
    S32 image_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_DRAW_PANEL_EV);

    gdi_layer_push_and_set_active(g_vdorec_cntx.ev_draw_layer);
    
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

    gdi_image_draw_id(
        g_vdorec_osd_cntx.panel.ev.offset_x - layer_offset_x,
        g_vdorec_osd_cntx.panel.ev.offset_y - layer_offset_y,
        (U16) (IMG_ID_VDOREC_OSD_EV_START + g_vdorec_cntx.setting.ev + 1));

    if (g_vdorec_cntx.is_use_blt_region)
    {
        gdi_image_get_dimension_id(IMG_ID_VDOREC_OSD_EV_START + 1, &image_width, &image_height);
        mmi_vdorec_merge_blt_rgn(
            g_vdorec_osd_cntx.panel.ev.offset_x,
            g_vdorec_osd_cntx.panel.ev.offset_y,
            image_width,
            image_height);
    }

    /* ev inc */
	if (g_vdorec_cntx.setting.ev >= VDOREC_SETTING_EV_COUNT - 1)
	{
                gdi_image_draw_id(
                    g_vdorec_osd_cntx.panel.ev_inc.offset_x - layer_offset_x,
                    g_vdorec_osd_cntx.panel.ev_inc.offset_y - layer_offset_y,
                    IMG_ID_VDOREC_TOUCH_OSD_EV_INC_DIS);
                if (g_vdorec_cntx.is_use_blt_region)
                {
                    gdi_image_get_dimension_id(IMG_ID_VDOREC_TOUCH_OSD_EV_INC_DIS, &image_width, &image_height);
                    mmi_vdorec_merge_blt_rgn(
                        g_vdorec_osd_cntx.panel.ev_inc.offset_x,
                        g_vdorec_osd_cntx.panel.ev_inc.offset_y,
                        image_width,
                        image_height);
               }
	}
	else if((g_vdorec_cntx.touch_ev_inc.is_press) || (g_vdorec_cntx.is_ev_inc_key_pressed))
	{
            gdi_image_draw_id(
                g_vdorec_osd_cntx.panel.ev_inc.offset_x - layer_offset_x,
                g_vdorec_osd_cntx.panel.ev_inc.offset_y - layer_offset_y,
                IMG_ID_VDOREC_TOUCH_OSD_EV_INC_SEL);
            if (g_vdorec_cntx.is_use_blt_region)
            {
                gdi_image_get_dimension_id(IMG_ID_VDOREC_TOUCH_OSD_EV_INC_SEL, &image_width, &image_height);
                mmi_vdorec_merge_blt_rgn(
                    g_vdorec_osd_cntx.panel.ev_inc.offset_x,
                    g_vdorec_osd_cntx.panel.ev_inc.offset_y,
                    image_width,
                    image_height);
            }
	}
	else
	{
            gdi_image_draw_id(
                g_vdorec_osd_cntx.panel.ev_inc.offset_x - layer_offset_x,
                g_vdorec_osd_cntx.panel.ev_inc.offset_y - layer_offset_y,
                IMG_ID_VDOREC_TOUCH_OSD_EV_INC);
            if (g_vdorec_cntx.is_use_blt_region)
            {
                gdi_image_get_dimension_id(IMG_ID_VDOREC_TOUCH_OSD_EV_INC, &image_width, &image_height);
                mmi_vdorec_merge_blt_rgn(
                   g_vdorec_osd_cntx.panel.ev_inc.offset_x,
                    g_vdorec_osd_cntx.panel.ev_inc.offset_y,
                    image_width,
                    image_height);
            }
	}

    /* ev dec */
	if (g_vdorec_cntx.setting.ev == 0)
	{
            gdi_image_draw_id(
                g_vdorec_osd_cntx.panel.ev_dec.offset_x - layer_offset_x,
                g_vdorec_osd_cntx.panel.ev_dec.offset_y - layer_offset_y,
                IMG_ID_VDOREC_TOUCH_OSD_EV_DEC_DIS);
            if (g_vdorec_cntx.is_use_blt_region)
            {
                gdi_image_get_dimension_id(IMG_ID_VDOREC_TOUCH_OSD_EV_DEC_DIS, &image_width, &image_height);
                mmi_vdorec_merge_blt_rgn(
                    g_vdorec_osd_cntx.panel.ev_dec.offset_x,
                    g_vdorec_osd_cntx.panel.ev_dec.offset_y,
                    image_width,
                    image_height);
            }
	}
	else if ((g_vdorec_cntx.touch_ev_dec.is_press) || (g_vdorec_cntx.is_ev_dec_key_pressed))
		
    {
        gdi_image_draw_id(
            g_vdorec_osd_cntx.panel.ev_dec.offset_x - layer_offset_x,
            g_vdorec_osd_cntx.panel.ev_dec.offset_y - layer_offset_y,
            IMG_ID_VDOREC_TOUCH_OSD_EV_DEC_SEL);
        if (g_vdorec_cntx.is_use_blt_region)
        {
            gdi_image_get_dimension_id(IMG_ID_VDOREC_TOUCH_OSD_EV_DEC_SEL, &image_width, &image_height);
            mmi_vdorec_merge_blt_rgn(
                g_vdorec_osd_cntx.panel.ev_dec.offset_x,
                g_vdorec_osd_cntx.panel.ev_dec.offset_y,
                image_width,
                image_height);
        }
    }
    else
    {
         gdi_image_draw_id(
             g_vdorec_osd_cntx.panel.ev_dec.offset_x - layer_offset_x,
             g_vdorec_osd_cntx.panel.ev_dec.offset_y - layer_offset_y,
             IMG_ID_VDOREC_TOUCH_OSD_EV_DEC);
         if (g_vdorec_cntx.is_use_blt_region)
        {
            gdi_image_get_dimension_id(IMG_ID_VDOREC_TOUCH_OSD_EV_DEC, &image_width, &image_height);
            mmi_vdorec_merge_blt_rgn(
                g_vdorec_osd_cntx.panel.ev_dec.offset_x,
                g_vdorec_osd_cntx.panel.ev_dec.offset_y,
                image_width,
                image_height);
        }
    }

    gdi_layer_pop_and_restore_active();

#endif /* __VDOREC_FEATURE_EV__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_draw_panel_zoom
 * DESCRIPTION
 *  draw panel zoom
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_draw_panel_zoom(void)
{
#ifdef __VDOREC_FEATURE_ZOOM__	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_offset_x;
    S32 layer_offset_y;
    S32 factor_offset_x;
    S32 factor_offset_y;
    S32 image_width;
    S32 image_height;
    U16 curr_digit;
    S16 zoom_region_x = 0;
    S16 zoom_region_y = 0;
    S16 zoom_region_w = 0;
    S16 zoom_region_h = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_DRAW_PANEL_ZOOM);

    gdi_layer_push_and_set_active(g_vdorec_cntx.zoom_draw_layer);
    
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

    /* zooming icon */
    gdi_image_draw_id(
        g_vdorec_osd_cntx.panel.zoom.offset_x - layer_offset_x,
        g_vdorec_osd_cntx.panel.zoom.offset_y - layer_offset_y,
        IMG_ID_VDOREC_TOUCH_OSD_ZOOM_HEAD);

    /*zoom factor*/
    g_vdorec_cntx.zoom_factor = mmi_vdorec_get_zoom_factor();

    factor_offset_x = g_vdorec_osd_cntx.panel.zoom.offset_x - layer_offset_x;
    factor_offset_y = g_vdorec_osd_cntx.panel.zoom.offset_y - layer_offset_y;
    if (g_vdorec_cntx.is_use_blt_region)
    {
        zoom_region_x = g_vdorec_osd_cntx.panel.zoom.offset_x;
        zoom_region_y = g_vdorec_osd_cntx.panel.zoom.offset_y;
        zoom_region_w = 0;
        zoom_region_h = 0;
    }

    gdi_image_get_dimension_id(IMG_ID_VDOREC_TOUCH_OSD_ZOOM_HEAD, &image_width, &image_height);
    factor_offset_x += image_width;
    if (g_vdorec_cntx.is_use_blt_region)
    {
        zoom_region_w += image_width;
        zoom_region_h = image_height;
    }

    /*first zoom digit*/
    curr_digit = g_vdorec_cntx.zoom_factor / 10 % 10;
    gdi_image_draw_id(factor_offset_x, factor_offset_y, (U16)(IMG_ID_VDOREC_EFFECT_NUMBER_0 + curr_digit));

    /*draw dot*/
    gdi_image_get_dimension_id(IMG_ID_VDOREC_EFFECT_NUMBER_0, &image_width, &image_height);
    factor_offset_x += image_width;
    if (g_vdorec_cntx.is_use_blt_region)
    {
        zoom_region_w += image_width;
    }
    gdi_image_draw_id(factor_offset_x, factor_offset_y, IMG_ID_VDOREC_EFFECT_DOT);

    /*second zoom digit*/
    gdi_image_get_dimension_id(IMG_ID_VDOREC_EFFECT_DOT, &image_width, &image_height);
    factor_offset_x += image_width;
    if (g_vdorec_cntx.is_use_blt_region)
    {
        zoom_region_w += image_width;
    }
    curr_digit = g_vdorec_cntx.zoom_factor % 10;
    gdi_image_draw_id(factor_offset_x, factor_offset_y, (U16)(IMG_ID_VDOREC_EFFECT_NUMBER_0 + curr_digit));

    /*get last digit width*/
    gdi_image_get_dimension_id(IMG_ID_VDOREC_EFFECT_NUMBER_0, &image_width, &image_height);
    if (g_vdorec_cntx.is_use_blt_region)
    {
        zoom_region_w += image_width;
    }
    if (g_vdorec_cntx.is_use_blt_region)
    {
        mmi_vdorec_merge_blt_rgn(
            zoom_region_x,
            zoom_region_y,
            zoom_region_w,
            zoom_region_h);
        }

    /*third zoom digit*/
    /*gdi_image_get_dimension_id(IMG_ID_VDOREC_EFFECT_NUMBER_0, &image_width, &image_height);
    factor_offset_x += image_width;
    curr_digit = g_vdorec_cntx.zoom_factor % 10;
    gdi_image_draw_id(factor_offset_x, factor_offset_y, (U16)(IMG_ID_VDOREC_EFFECT_NUMBER_0 + curr_digit));*/

    /* zoom inc */
	if (mmi_vdorec_get_zoom_factor() == g_vdorec_cntx.zoom_limit)
	{
            gdi_image_draw_id(
            g_vdorec_osd_cntx.panel.zoom_inc.offset_x - layer_offset_x,
                g_vdorec_osd_cntx.panel.zoom_inc.offset_y - layer_offset_y,
                IMG_ID_VDOREC_TOUCH_OSD_ZOOM_INC_DIS);
            gdi_image_get_dimension_id(IMG_ID_VDOREC_TOUCH_OSD_ZOOM_INC_DIS, &image_width, &image_height);
            if (g_vdorec_cntx.is_use_blt_region)
            {
                mmi_vdorec_merge_blt_rgn(
                    g_vdorec_osd_cntx.panel.zoom_inc.offset_x,
                    g_vdorec_osd_cntx.panel.zoom_inc.offset_y,
                    image_width,
                    image_height);
            }
	}
	else if (g_vdorec_cntx.touch_zoom_inc.is_press || g_vdorec_cntx.is_zoom_in_key_pressed)
	{			
            gdi_image_draw_id(
                g_vdorec_osd_cntx.panel.zoom_inc.offset_x - layer_offset_x,
                g_vdorec_osd_cntx.panel.zoom_inc.offset_y - layer_offset_y,
                IMG_ID_VDOREC_TOUCH_OSD_ZOOM_INC_SEL);
            gdi_image_get_dimension_id(IMG_ID_VDOREC_TOUCH_OSD_ZOOM_INC_SEL, &image_width, &image_height);
            if (g_vdorec_cntx.is_use_blt_region)
            {
                mmi_vdorec_merge_blt_rgn(
                    g_vdorec_osd_cntx.panel.zoom_inc.offset_x,
                    g_vdorec_osd_cntx.panel.zoom_inc.offset_y,
                    image_width,
                    image_height);
            }
	}
	else
	{
            gdi_image_draw_id(
                g_vdorec_osd_cntx.panel.zoom_inc.offset_x - layer_offset_x,
                g_vdorec_osd_cntx.panel.zoom_inc.offset_y - layer_offset_y,
                IMG_ID_VDOREC_TOUCH_OSD_ZOOM_INC);
            gdi_image_get_dimension_id(IMG_ID_VDOREC_TOUCH_OSD_ZOOM_INC, &image_width, &image_height);
            if (g_vdorec_cntx.is_use_blt_region)
            {
                mmi_vdorec_merge_blt_rgn(
                    g_vdorec_osd_cntx.panel.zoom_inc.offset_x,
                    g_vdorec_osd_cntx.panel.zoom_inc.offset_y,
                    image_width,
                    image_height);
            }
	}

	/* zoom dec */
	if (g_vdorec_cntx.setting.zoom == 0)
	{
            gdi_image_draw_id(
                g_vdorec_osd_cntx.panel.zoom_dec.offset_x - layer_offset_x,
                g_vdorec_osd_cntx.panel.zoom_dec.offset_y - layer_offset_y,
                IMG_ID_VDOREC_TOUCH_OSD_ZOOM_DEC_DIS);
            gdi_image_get_dimension_id(IMG_ID_VDOREC_TOUCH_OSD_ZOOM_DEC_DIS, &image_width, &image_height);
            if (g_vdorec_cntx.is_use_blt_region)
            {
                mmi_vdorec_merge_blt_rgn(
                    g_vdorec_osd_cntx.panel.zoom_dec.offset_x,
                    g_vdorec_osd_cntx.panel.zoom_dec.offset_y,
                    image_width,
                    image_height);
            }
	}
    else if ((g_vdorec_cntx.touch_zoom_dec.is_press) || (g_vdorec_cntx.is_zoom_out_key_pressed))
    {
        gdi_image_draw_id(
            g_vdorec_osd_cntx.panel.zoom_dec.offset_x - layer_offset_x,
            g_vdorec_osd_cntx.panel.zoom_dec.offset_y - layer_offset_y,
            IMG_ID_VDOREC_TOUCH_OSD_ZOOM_DEC_SEL);
        gdi_image_get_dimension_id(IMG_ID_VDOREC_TOUCH_OSD_ZOOM_DEC_SEL, &image_width, &image_height);
        if (g_vdorec_cntx.is_use_blt_region)
        {
            mmi_vdorec_merge_blt_rgn(
                g_vdorec_osd_cntx.panel.zoom_dec.offset_x,
                g_vdorec_osd_cntx.panel.zoom_dec.offset_y,
                image_width,
                image_height);
        }
    }
    else
    {
        gdi_image_draw_id(
            g_vdorec_osd_cntx.panel.zoom_dec.offset_x - layer_offset_x,
            g_vdorec_osd_cntx.panel.zoom_dec.offset_y - layer_offset_y,
            IMG_ID_VDOREC_TOUCH_OSD_ZOOM_DEC);
        gdi_image_get_dimension_id(IMG_ID_VDOREC_TOUCH_OSD_ZOOM_DEC, &image_width, &image_height);
        if (g_vdorec_cntx.is_use_blt_region)
        {
            mmi_vdorec_merge_blt_rgn(
                g_vdorec_osd_cntx.panel.zoom_dec.offset_x,
                g_vdorec_osd_cntx.panel.zoom_dec.offset_y,
                image_width,
                image_height);
        }
    }

    gdi_layer_pop_and_restore_active();
#endif /* __VDOREC_FEATURE_ZOOM__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_clear_panel_timer
 * DESCRIPTION
 *  draw panel timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_clear_timer(void)
{
	S32 offset_x1, offset_y1, offset_x2, offset_y2, digit_width, digit_height, layer_offset_x, layer_offset_y;

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_CLEAR_TIMER, g_vdorec_cntx.is_timer_show);

	if (!g_vdorec_cntx.is_timer_show)
	{
		return;
	}

    gdi_layer_push_and_set_active(g_vdorec_cntx.timer_draw_layer);
    
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

    gdi_image_get_dimension_id(IMG_ID_VDOREC_TIME_NUMBER_0, &digit_width, &digit_height);

    offset_x1 = g_vdorec_cntx.timer.hr_0_offset_x - layer_offset_x;
    offset_y1 = g_vdorec_cntx.timer.offset_y - layer_offset_y;
    offset_x2 = g_vdorec_cntx.timer.sec_1_offset_x + digit_width - layer_offset_x;
    offset_y2 = g_vdorec_cntx.timer.offset_y + digit_height - layer_offset_y;

    gdi_draw_solid_rect(offset_x1, offset_y1, offset_x2, offset_y2, GDI_COLOR_TRANSPARENT);

    gdi_layer_pop_and_restore_active();

    if (g_vdorec_cntx.is_use_blt_region)
    {
        mmi_vdorec_merge_blt_rgn(
            g_vdorec_cntx.timer.hr_0_offset_x, 
            g_vdorec_cntx.timer.offset_y, 
            g_vdorec_cntx.timer.sec_1_offset_x + digit_width - g_vdorec_cntx.timer.hr_0_offset_x, 
            digit_height);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_draw_panel_timer
 * DESCRIPTION
 *  draw panel timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_draw_panel_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hour;
    S32 hour_remain;
    S32 min;
    S32 sec;
    U32 rec_time;
    S32 layer_offset_x;
    S32 layer_offset_y;    
    S32 image_width;
    S32 image_height;
    
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_DRAW_PANEL_TIMER, g_vdorec_cntx.is_timer_show);

	if (!g_vdorec_cntx.is_timer_show)
	{
		return;
	}

    gdi_layer_push_and_set_active(g_vdorec_cntx.timer_draw_layer);

    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
   
    rec_time = (U32) (g_vdorec_cntx.record_time / 1000);

   /******** draw timer *********/
    hour = rec_time / 3600;
    hour_remain = rec_time % 3600;
    min = hour_remain / 60;
    sec = hour_remain % 60;

    mmi_vdorec_clear_timer();

    gdi_image_get_dimension_id(IMG_ID_VDOREC_TIME_NUMBER_0, &image_width, &image_height);

    
    /* hr */
    gdi_image_draw_id(
        g_vdorec_cntx.timer.hr_0_offset_x - layer_offset_x,
        g_vdorec_cntx.timer.offset_y - layer_offset_y,
        (U16) (IMG_ID_VDOREC_TIME_NUMBER_0 + (U16) hour / 10));

    gdi_image_draw_id(
        g_vdorec_cntx.timer.hr_1_offset_x - layer_offset_x,
        g_vdorec_cntx.timer.offset_y - layer_offset_y,
        (U16) (IMG_ID_VDOREC_TIME_NUMBER_0 + (U16) hour % 10));

    gdi_image_draw_id(
        g_vdorec_cntx.timer.col_0_offset_x - layer_offset_x,
        g_vdorec_cntx.timer.offset_y - layer_offset_y,
        (U16) (IMG_ID_VDOREC_TIME_COL));

    /* min */
    gdi_image_draw_id(
        g_vdorec_cntx.timer.min_0_offset_x - layer_offset_x,
        g_vdorec_cntx.timer.offset_y - layer_offset_y,
        (U16) (IMG_ID_VDOREC_TIME_NUMBER_0 + (U16) min / 10));

    gdi_image_draw_id(
        g_vdorec_cntx.timer.min_1_offset_x - layer_offset_x,
        g_vdorec_cntx.timer.offset_y - layer_offset_y,
        (U16) (IMG_ID_VDOREC_TIME_NUMBER_0 + (U16) min % 10));

    gdi_image_draw_id(
        g_vdorec_cntx.timer.col_1_offset_x - layer_offset_x,
        g_vdorec_cntx.timer.offset_y - layer_offset_y,
        (U16) (IMG_ID_VDOREC_TIME_COL));

    /* sec */
    gdi_image_draw_id(
        g_vdorec_cntx.timer.sec_0_offset_x - layer_offset_x,
        g_vdorec_cntx.timer.offset_y - layer_offset_y,
        (U16) (IMG_ID_VDOREC_TIME_NUMBER_0 + (U16) sec / 10));

    gdi_image_draw_id(
        g_vdorec_cntx.timer.sec_1_offset_x - layer_offset_x,
        g_vdorec_cntx.timer.offset_y - layer_offset_y,
        (U16) (IMG_ID_VDOREC_TIME_NUMBER_0 + (U16) sec % 10));
    
    gdi_layer_pop_and_restore_active();

    if (g_vdorec_cntx.is_use_blt_region)
    {
        mmi_vdorec_merge_blt_rgn(
            g_vdorec_cntx.timer.hr_0_offset_x,
            g_vdorec_cntx.timer.offset_y,
            g_vdorec_cntx.timer.sec_1_offset_x + image_width - g_vdorec_cntx.timer.hr_0_offset_x,
            image_height);
    }
}


static gdi_handle mmi_vdorec_get_layer_handle_by_position(S32 offset_x, S32 offset_y, U32 component)
{
    gdi_handle handle = GDI_LAYER_EMPTY_HANDLE;
    video_rect_struct *rect_0_ptr;
    video_rect_struct *rect_1_ptr;
    video_rect_struct *rect_2_ptr;
    video_rect_struct *rect_3_ptr;    
                          
    rect_0_ptr = &g_vdorec_osd_cntx.osd_layer_region.region_0;                    
    rect_1_ptr = &g_vdorec_osd_cntx.osd_layer_region.region_1;                    
    rect_2_ptr = &g_vdorec_osd_cntx.osd_layer_region.region_2;  
    rect_3_ptr = &g_vdorec_osd_cntx.osd_layer_region.region_3;  

    if ((offset_x >= rect_0_ptr->offset_x) &&                   
        (offset_x <= rect_0_ptr->offset_x + rect_0_ptr->width) && 
        (offset_y >= rect_0_ptr->offset_y) &&                   
        (offset_y <= rect_0_ptr->offset_y + rect_0_ptr->height))  
    {
        if (g_vdorec_cntx.is_use_hw_rotate)
        {
            handle = g_vdorec_cntx.tmp_osd_layer_region_handle[0];    
        }
        else
        {
            handle = g_vdorec_cntx.osd_layer_region_handle[0];
        }
        g_vdorec_cntx.osd_layer_region_mask[0] |= component;
    }                                                               
    else if ((offset_x >= rect_1_ptr->offset_x) &&            
        (offset_x <= rect_1_ptr->offset_x+rect_1_ptr->width) &&   
        (offset_y >= rect_1_ptr->offset_y) &&                     
        (offset_y <= rect_1_ptr->offset_y+rect_1_ptr->height))    
    {
        if (g_vdorec_cntx.is_use_hw_rotate)
        {
            handle = g_vdorec_cntx.tmp_osd_layer_region_handle[1];
        }
        else
        {
            handle = g_vdorec_cntx.osd_layer_region_handle[1];      
        }
        g_vdorec_cntx.osd_layer_region_mask[1] |= component;
    } 
    else if ((offset_x >= rect_2_ptr->offset_x) &&            
             (offset_x <= rect_2_ptr->offset_x+rect_2_ptr->width) &&   
             (offset_y >= rect_2_ptr->offset_y) &&                     
             (offset_y <= rect_2_ptr->offset_y+rect_2_ptr->height))    
    {
        if (g_vdorec_cntx.is_use_hw_rotate)
        {
            handle = g_vdorec_cntx.tmp_osd_layer_region_handle[2];
        }
        else
        {
            handle = g_vdorec_cntx.osd_layer_region_handle[2];  
        }
        g_vdorec_cntx.osd_layer_region_mask[2] |= component;
    } 
    else if ((offset_x >= rect_3_ptr->offset_x) &&            
             (offset_x <= rect_3_ptr->offset_x+rect_3_ptr->width) &&   
             (offset_y >= rect_3_ptr->offset_y) &&                     
             (offset_y <= rect_3_ptr->offset_y+rect_3_ptr->height))    
    {
        if (g_vdorec_cntx.is_use_hw_rotate)
        {
            handle = g_vdorec_cntx.tmp_osd_layer_region_handle[3];  
        }
        else
        {
            handle = g_vdorec_cntx.osd_layer_region_handle[3];
        }
        g_vdorec_cntx.osd_layer_region_mask[3] |= component;
    } 
                                                                 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_GET_LAYER_HANDLE_BY_POSITION, handle);

    return  handle;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_init_ui
 * DESCRIPTION
 *  init panel (timer)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_init_ui(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 digit_width;
    S32 col_width;
    S32 height;

    S32 region_0_buf_size;
    S32 region_1_buf_size;
    S32 region_2_buf_size;    
    S32 region_3_buf_size;    
    video_rect_struct *rect_ptr;
    video_osd_vodrec_panel_struct *panel_ptr;    
    video_osd_softkey_struct *sk_ptr;    
    
#ifdef __VDOREC_FEATURE_TOUCH_SCREEN__
    vdorec_ui_touch_struct *touch_p;
#endif 
    PU8 gdi_layer_buffer_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_INIT_UI);

#ifdef __VDOREC_COLOR_IDX_FRAME__
    /************ overlay frame ************/
    /* create overlay frame buffer */
    g_vdorec_cntx.overlay_frame_buf_ptr = mmi_frm_scrmem_alloc_framebuffer(VDOREC_OVERLAY_FRAME_BUFFER_SIZE);
    ASSERT(g_vdorec_cntx.overlay_frame_buf_ptr != NULL);
    
    gdi_layer_create_cf_using_outside_memory(
        GDI_COLOR_FORMAT_8,
        0,
        0,
        LCD_WIDTH,
        LCD_HEIGHT,
        &g_vdorec_cntx.overlay_frame_layer_handle,
        (PU8) g_vdorec_cntx.overlay_frame_buf_ptr,
        (S32) VDOREC_OVERLAY_FRAME_BUFFER_SIZE);
    gdi_layer_push_and_set_active(g_vdorec_cntx.overlay_frame_layer_handle);
    
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();
    
    /* update frame */
    if (g_vdorec_cntx.setting.color_idx_frame != VDOREC_SETTING_COLOR_IDX_FRAME_OFF)
    {
        mmi_vdorec_draw_color_idx_frame();
    }
    
#endif /* __VDOREC_COLOR_IDX_FRAME__ */ /* __CAMERA_FEATURE_ADD_FRAME_COLOR_IDX__ */

#ifdef __VDOREC_FEATURE_SHOW_STATUS_BAR__
    gdi_layer_create(
        0, 
        0, 
        UI_DEVICE_WIDTH, 
        MMI_STATUS_BAR_HEIGHT, 
        &g_vdorec_cntx.status_bar_layer_handle);
    
    gdi_layer_push_and_set_active(g_vdorec_cntx.status_bar_layer_handle);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();
    
    g_vdorec_cntx.prev_status_bar_layer_handle = wgui_status_icon_get_display_layer();
    wgui_status_icon_set_display_layer(g_vdorec_cntx.status_bar_layer_handle);
    show_status_icon_bar(0);
    wgui_set_wallpaper_on_bottom(MMI_TRUE);
    
#else /* __VDOREC_FEATURE_SHOW_STATUS_BAR__ */
    g_vdorec_cntx.status_bar_layer_handle = GDI_LAYER_EMPTY_HANDLE;
#endif /* __VDOREC_FEATURE_SHOW_STATUS_BAR__ */

    /*currently in order to save memory, we will steal GDI memory, 
    NOTE : we only use the memory, but do not use the handle */
    if (g_vdorec_cntx.gdi_layer_handle == GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_create(
            0,
            0,
            LCD_HEIGHT,        
            LCD_WIDTH,        
            &g_vdorec_cntx.gdi_layer_handle);
        gdi_layer_push_and_set_active(g_vdorec_cntx.gdi_layer_handle);
        gdi_layer_get_buffer_ptr(&gdi_layer_buffer_ptr);
        gdi_layer_pop_and_restore_active();
    }
    //gdi_layer_free(g_vdorec_cntx.gdi_layer_handle);
    /* steal done */

    if (g_vdorec_cntx.osd_layer_region_count == VDOREC_OSD_LAYER_COUNT_ONE) 
    {
        /************ osd layer ************/
        /* create a double layer frame from outside memory */
        if (g_vdorec_cntx.osd_layer_region_count == VDOREC_OSD_LAYER_COUNT_ONE)
        {
            g_vdorec_cntx.osd_layer_buf_ptr = mmi_frm_scrmem_alloc_framebuffer(VDOREC_OSD_BUFFER_SIZE);
            
            gdi_layer_create_cf_double_using_outside_memory(
                GDI_COLOR_FORMAT_16,
                0,
                0,
                g_vdorec_cntx.lcd_width,
                g_vdorec_cntx.lcd_height,
                &g_vdorec_cntx.osd_layer_handle,
                (PU8)g_vdorec_cntx.osd_layer_buf_ptr,
                VDOREC_OSD_BUFFER_SIZE,
                (PU8)gdi_layer_buffer_ptr,
                VDOREC_OSD_BUFFER_SIZE);

            /*gdi_layer_create_double_using_outside_memory(
                0, 
                0, 
                g_vdorec_cntx.lcd_width, 
                g_vdorec_cntx.lcd_height, 
                &g_vdorec_cntx.osd_layer_handle, 
                (PU8)g_vdorec_cntx.osd_layer_buf_ptr, 
                (S32)LCD_WIDTH*LCD_HEIGHT*VDOREC_BUFFER_DEPTH*2);*/
            
            gdi_layer_push_and_set_active(g_vdorec_cntx.osd_layer_handle);
            
            /* clear both layer */
            gdi_layer_clear(GDI_COLOR_TRANSPARENT);
            
            gdi_layer_toggle_double();
            
            gdi_layer_clear(GDI_COLOR_TRANSPARENT);
            
            gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
            gdi_layer_pop_and_restore_active();
        }
        else
        {
            g_vdorec_cntx.osd_layer_handle = GDI_LAYER_EMPTY_HANDLE;
        }   
        
        if (g_vdorec_cntx.is_use_hw_rotate)
        {
            /*g_vdorec_cntx.tmp_osd_layer_region_handle_ptr[0]
                = (PU8) mmi_frm_scrmem_alloc_framebuffer(LCD_WIDTH * LCD_HEIGHT * VDOREC_BUFFER_DEPTH);
            
            gdi_layer_create_using_outside_memory(
                0,
                0,
                LCD_HEIGHT,        
                LCD_WIDTH,        
                &g_vdorec_cntx.tmp_osd_layer_region_handle[0],   
                (PU8)g_vdorec_cntx.tmp_osd_layer_region_handle_ptr[0],
                (S32)(LCD_WIDTH * LCD_HEIGHT * VDOREC_BUFFER_DEPTH));*/
            
            /*gdi_layer_create(
                0,
                0,
                LCD_HEIGHT,        
                LCD_WIDTH,        
                &g_vdorec_cntx.tmp_osd_layer_region_handle[0]);*/

            g_vdorec_cntx.tmp_osd_layer_region_handle_ptr[0] = 
                applib_mem_ap_alloc_framebuffer(APPLIB_MEM_AP_ID_VDOREC, VDOREC_OSD_BUFFER_SIZE);

            gdi_layer_create_using_outside_memory(
                0,
                0,
                LCD_HEIGHT,        
                LCD_WIDTH,        
                &g_vdorec_cntx.tmp_osd_layer_region_handle[0],   
                (PU8)g_vdorec_cntx.tmp_osd_layer_region_handle_ptr[0],
                (S32)VDOREC_OSD_BUFFER_SIZE);

            gdi_layer_push_and_set_active(g_vdorec_cntx.tmp_osd_layer_region_handle[0]);
            gdi_layer_clear(GDI_COLOR_TRANSPARENT);   
            gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
            gdi_layer_pop_and_restore_active();
            
        }
    }
    else
    {
        /* bg */
        /* newer cip has layer bg color, we can split bg into smaller region for better performance */
        /* we will use screen ASM to create two smaller layer region */
        
        if (g_vdorec_cntx.is_use_hw_rotate)
        {
            /* region 0 */
            rect_ptr = &g_vdorec_osd_cntx.osd_layer_region.region_0;
            region_0_buf_size = rect_ptr->width*rect_ptr->height*VDOREC_BUFFER_DEPTH;

            g_vdorec_cntx.osd_layer_region_handle_ptr[0] = (PU8) mmi_frm_scrmem_alloc_framebuffer(region_0_buf_size);
            
            gdi_layer_create_cf_double_using_outside_memory(
                GDI_COLOR_FORMAT_16,
                g_vdorec_cntx.lcd_width - rect_ptr->offset_y - rect_ptr->height,
                rect_ptr->offset_x,
                rect_ptr->height,
                rect_ptr->width,
                &g_vdorec_cntx.osd_layer_region_handle[0],
                (PU8)g_vdorec_cntx.osd_layer_region_handle_ptr[0],
                region_0_buf_size,
                (PU8)gdi_layer_buffer_ptr,
                region_0_buf_size);
            
            /*gdi_layer_create_double_using_outside_memory(
                g_vdorec_cntx.lcd_width - rect_ptr->offset_y - rect_ptr->height,
                rect_ptr->offset_x,
                rect_ptr->height,
                rect_ptr->width,
                &g_vdorec_cntx.osd_layer_region_handle[0],   
                (PU8)g_vdorec_cntx.osd_layer_region_handle_ptr[0],
                (S32)region_0_buf_size);*/
            
            gdi_layer_push_and_set_active(g_vdorec_cntx.osd_layer_region_handle[0]);       
            gdi_layer_clear(GDI_COLOR_TRANSPARENT);
            gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
            gdi_layer_pop_and_restore_active();
            
            /* region 1 */
            rect_ptr = &g_vdorec_osd_cntx.osd_layer_region.region_1;    
            region_1_buf_size = rect_ptr->width*rect_ptr->height*VDOREC_BUFFER_DEPTH;
            g_vdorec_cntx.osd_layer_region_handle_ptr[1] = (PU8) mmi_frm_scrmem_alloc_framebuffer(region_1_buf_size);
            
            gdi_layer_create_cf_double_using_outside_memory(
                GDI_COLOR_FORMAT_16,
                g_vdorec_cntx.lcd_width - rect_ptr->offset_y - rect_ptr->height,
                rect_ptr->offset_x,
                rect_ptr->height,
                rect_ptr->width,
                &g_vdorec_cntx.osd_layer_region_handle[1],
                (PU8)g_vdorec_cntx.osd_layer_region_handle_ptr[1],
                region_1_buf_size,
                (PU8)gdi_layer_buffer_ptr + region_0_buf_size,
                region_1_buf_size);

            /*gdi_layer_create_double_using_outside_memory(
                g_vdorec_cntx.lcd_width - rect_ptr->offset_y - rect_ptr->height,
                rect_ptr->offset_x,
                rect_ptr->height,        
                rect_ptr->width,        
                &g_vdorec_cntx.osd_layer_region_handle[1],   
                (PU8)g_vdorec_cntx.osd_layer_region_handle_ptr[1],
                (S32)region_1_buf_size); */
            
            gdi_layer_push_and_set_active(g_vdorec_cntx.osd_layer_region_handle[1]);       
            gdi_layer_clear(GDI_COLOR_TRANSPARENT);
            gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
            gdi_layer_pop_and_restore_active();
            
            /* region 2 */
            rect_ptr = &g_vdorec_osd_cntx.osd_layer_region.region_2;    
            region_2_buf_size = rect_ptr->width*rect_ptr->height*VDOREC_BUFFER_DEPTH;
            g_vdorec_cntx.osd_layer_region_handle_ptr[2] = (PU8) mmi_frm_scrmem_alloc_framebuffer(region_2_buf_size);
            
            gdi_layer_create_cf_double_using_outside_memory(
                GDI_COLOR_FORMAT_16,
                g_vdorec_cntx.lcd_width - rect_ptr->offset_y - rect_ptr->height,
                rect_ptr->offset_x,
                rect_ptr->height,
                rect_ptr->width,
                &g_vdorec_cntx.osd_layer_region_handle[2],
                (PU8)g_vdorec_cntx.osd_layer_region_handle_ptr[2],
                region_2_buf_size,
                (PU8)gdi_layer_buffer_ptr + region_0_buf_size + region_1_buf_size,
                region_2_buf_size);

            /*gdi_layer_create_double_using_outside_memory(
                g_vdorec_cntx.lcd_width - rect_ptr->offset_y - rect_ptr->height,
                rect_ptr->offset_x,
                rect_ptr->height,        
                rect_ptr->width,        
                &g_vdorec_cntx.osd_layer_region_handle[2],   
                (PU8)g_vdorec_cntx.osd_layer_region_handle_ptr[2],
                (S32)region_2_buf_size);*/
            
            gdi_layer_push_and_set_active(g_vdorec_cntx.osd_layer_region_handle[2]);       
            gdi_layer_clear(GDI_COLOR_TRANSPARENT);
            gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
            gdi_layer_pop_and_restore_active();
            
            /* region 3 */
            if (g_vdorec_cntx.osd_layer_region_count == VDOREC_OSD_LAYER_COUNT_FOUR)
            {
                rect_ptr = &g_vdorec_osd_cntx.osd_layer_region.region_3;    
                region_3_buf_size = rect_ptr->width*rect_ptr->height*VDOREC_BUFFER_DEPTH;
                g_vdorec_cntx.osd_layer_region_handle_ptr[3] = (PU8) mmi_frm_scrmem_alloc_framebuffer(region_3_buf_size);
                
                gdi_layer_create_cf_double_using_outside_memory(
                    GDI_COLOR_FORMAT_16,
                    g_vdorec_cntx.lcd_width - rect_ptr->offset_y - rect_ptr->height,
                    rect_ptr->offset_x,
                    rect_ptr->height,
                    rect_ptr->width,
                    &g_vdorec_cntx.osd_layer_region_handle[3],
                    (PU8)g_vdorec_cntx.osd_layer_region_handle_ptr[3],
                    region_3_buf_size,
                    (PU8)gdi_layer_buffer_ptr + region_0_buf_size + region_1_buf_size + region_2_buf_size,
                    region_3_buf_size);

                /*gdi_layer_create_double_using_outside_memory(
                    g_vdorec_cntx.lcd_width - rect_ptr->offset_y - rect_ptr->height,
                    rect_ptr->offset_x,
                    rect_ptr->height,        
                    rect_ptr->width,        
                    &g_vdorec_cntx.osd_layer_region_handle[3],   
                    (PU8)g_vdorec_cntx.osd_layer_region_handle_ptr[3],
                    (S32)region_3_buf_size);*/
                
                gdi_layer_push_and_set_active(g_vdorec_cntx.osd_layer_region_handle[3]);       
                gdi_layer_clear(GDI_COLOR_TRANSPARENT);
                gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
                gdi_layer_pop_and_restore_active();
            }
            else
            {
                g_vdorec_cntx.osd_layer_region_handle[3] = GDI_LAYER_EMPTY_HANDLE;
            }

            /*HW rotate tmp layer*/
            /* region 0 */
            rect_ptr = &g_vdorec_osd_cntx.osd_layer_region.region_0;
            region_0_buf_size = rect_ptr->width*rect_ptr->height*VDOREC_BUFFER_DEPTH;
            
            /*
            g_vdorec_cntx.tmp_osd_layer_region_handle_ptr[0] = (PU8) mmi_frm_scrmem_alloc_framebuffer(region_0_buf_size);
            
            gdi_layer_create_using_outside_memory(
                rect_ptr->offset_x,
                rect_ptr->offset_y,
                rect_ptr->width,        
                rect_ptr->height,        
                &g_vdorec_cntx.tmp_osd_layer_region_handle[0],   
                (PU8)g_vdorec_cntx.tmp_osd_layer_region_handle_ptr[0],
                (S32)region_0_buf_size);
                */
            /*gdi_layer_create(
                rect_ptr->offset_x,
                rect_ptr->offset_y,
                rect_ptr->width,        
                rect_ptr->height,        
                &g_vdorec_cntx.tmp_osd_layer_region_handle[0]);*/

            g_vdorec_cntx.tmp_osd_layer_region_handle_ptr[0] = g_vdorec_cntx.app_mem_bufer;

            gdi_layer_create_using_outside_memory(
                rect_ptr->offset_x,
                rect_ptr->offset_y,
                rect_ptr->width,        
                rect_ptr->height,        
                &g_vdorec_cntx.tmp_osd_layer_region_handle[0],   
                (PU8)g_vdorec_cntx.tmp_osd_layer_region_handle_ptr[0],
                (S32)region_0_buf_size);

            gdi_layer_push_and_set_active(g_vdorec_cntx.tmp_osd_layer_region_handle[0]);       
            gdi_layer_clear(GDI_COLOR_TRANSPARENT);
            gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
            gdi_layer_pop_and_restore_active();
            
            /* region 1 */
            rect_ptr = &g_vdorec_osd_cntx.osd_layer_region.region_1;    
            region_1_buf_size = rect_ptr->width*rect_ptr->height*VDOREC_BUFFER_DEPTH;
            /*g_vdorec_cntx.tmp_osd_layer_region_handle_ptr[1] = (PU8) mmi_frm_scrmem_alloc_framebuffer(region_1_buf_size);
            
            gdi_layer_create_using_outside_memory(
                rect_ptr->offset_x,
                rect_ptr->offset_y,
                rect_ptr->width,        
                rect_ptr->height,        
                &g_vdorec_cntx.tmp_osd_layer_region_handle[1],   
                (PU8)g_vdorec_cntx.tmp_osd_layer_region_handle_ptr[1],
                (S32)region_1_buf_size);
                */
            
            /*gdi_layer_create(
                rect_ptr->offset_x,
                rect_ptr->offset_y,
                rect_ptr->width,        
                rect_ptr->height,        
                &g_vdorec_cntx.tmp_osd_layer_region_handle[1]);*/

            g_vdorec_cntx.tmp_osd_layer_region_handle_ptr[1] = g_vdorec_cntx.app_mem_bufer + region_0_buf_size;
            
            gdi_layer_create_using_outside_memory(
                rect_ptr->offset_x,
                rect_ptr->offset_y,
                rect_ptr->width,        
                rect_ptr->height,        
                &g_vdorec_cntx.tmp_osd_layer_region_handle[1],   
                (PU8)g_vdorec_cntx.tmp_osd_layer_region_handle_ptr[1],
                (S32)region_1_buf_size);

            gdi_layer_push_and_set_active(g_vdorec_cntx.tmp_osd_layer_region_handle[1]);       
            gdi_layer_clear(GDI_COLOR_TRANSPARENT);
            gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
            gdi_layer_pop_and_restore_active();
            
            /* region 2 */
            rect_ptr = &g_vdorec_osd_cntx.osd_layer_region.region_2;    
            region_2_buf_size = rect_ptr->width*rect_ptr->height*VDOREC_BUFFER_DEPTH;
            /*g_vdorec_cntx.tmp_osd_layer_region_handle_ptr[2] = (PU8) mmi_frm_scrmem_alloc_framebuffer(region_2_buf_size);
            
            gdi_layer_create_using_outside_memory(
                rect_ptr->offset_x,
                rect_ptr->offset_y,
                rect_ptr->width,        
                rect_ptr->height,        
                &g_vdorec_cntx.tmp_osd_layer_region_handle[2],   
                (PU8)g_vdorec_cntx.tmp_osd_layer_region_handle_ptr[2],
                (S32)region_2_buf_size);
            */

            /*gdi_layer_create(
                rect_ptr->offset_x,
                rect_ptr->offset_y,
                rect_ptr->width,        
                rect_ptr->height,        
                &g_vdorec_cntx.tmp_osd_layer_region_handle[2]);*/

            g_vdorec_cntx.tmp_osd_layer_region_handle_ptr[2] = g_vdorec_cntx.app_mem_bufer + region_0_buf_size + region_1_buf_size;
            
            gdi_layer_create_using_outside_memory(
                rect_ptr->offset_x,
                rect_ptr->offset_y,
                rect_ptr->width,        
                rect_ptr->height,        
                &g_vdorec_cntx.tmp_osd_layer_region_handle[2],   
                (PU8)g_vdorec_cntx.tmp_osd_layer_region_handle_ptr[2],
                (S32)region_2_buf_size);

            gdi_layer_push_and_set_active(g_vdorec_cntx.tmp_osd_layer_region_handle[2]);       
            gdi_layer_clear(GDI_COLOR_TRANSPARENT);
            gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
            gdi_layer_pop_and_restore_active();
            
            
            /* region 3 */
            if (g_vdorec_cntx.osd_layer_region_count == VDOREC_OSD_LAYER_COUNT_FOUR)
            {
                rect_ptr = &g_vdorec_osd_cntx.osd_layer_region.region_3;    
                region_3_buf_size = rect_ptr->width*rect_ptr->height*VDOREC_BUFFER_DEPTH;
                /*g_vdorec_cntx.tmp_osd_layer_region_handle_ptr[3] = (PU8) mmi_frm_scrmem_alloc_framebuffer(region_3_buf_size);
                
                gdi_layer_create_using_outside_memory(
                    rect_ptr->offset_x,
                    rect_ptr->offset_y,
                    rect_ptr->width,        
                    rect_ptr->height,        
                    &g_vdorec_cntx.tmp_osd_layer_region_handle[3],   
                    (PU8)g_vdorec_cntx.tmp_osd_layer_region_handle_ptr[3],
                    (S32)region_3_buf_size);
                */

                /*gdi_layer_create(
                    rect_ptr->offset_x,
                    rect_ptr->offset_y,
                    rect_ptr->width,        
                    rect_ptr->height,        
                    &g_vdorec_cntx.tmp_osd_layer_region_handle[3]);*/

                g_vdorec_cntx.tmp_osd_layer_region_handle_ptr[3] = 
                    g_vdorec_cntx.app_mem_bufer + region_0_buf_size + region_1_buf_size + region_2_buf_size;
                
                gdi_layer_create_using_outside_memory(
                    rect_ptr->offset_x,
                    rect_ptr->offset_y,
                    rect_ptr->width,        
                    rect_ptr->height,       
                    &g_vdorec_cntx.tmp_osd_layer_region_handle[3],   
                    (PU8)g_vdorec_cntx.tmp_osd_layer_region_handle_ptr[3],
                    (S32)region_3_buf_size);

                gdi_layer_push_and_set_active(g_vdorec_cntx.tmp_osd_layer_region_handle[3]);       
                gdi_layer_clear(GDI_COLOR_TRANSPARENT);
                gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
                gdi_layer_pop_and_restore_active();
            }
            else
            {
                g_vdorec_cntx.tmp_osd_layer_region_handle[3] = GDI_LAYER_EMPTY_HANDLE;
            }
        }
        else
        {
            /* region 0 */
            rect_ptr = &g_vdorec_osd_cntx.osd_layer_region.region_0;
            region_0_buf_size = rect_ptr->width*rect_ptr->height*VDOREC_BUFFER_DEPTH;
            
            g_vdorec_cntx.osd_layer_region_handle_ptr[0] = (PU8) mmi_frm_scrmem_alloc_framebuffer(region_0_buf_size);
            
            gdi_layer_create_cf_double_using_outside_memory(
                GDI_COLOR_FORMAT_16,
                rect_ptr->offset_x,
                rect_ptr->offset_y,
                rect_ptr->width,
                rect_ptr->height,
                &g_vdorec_cntx.osd_layer_region_handle[0],
                (PU8)g_vdorec_cntx.osd_layer_region_handle_ptr[0],
                region_0_buf_size,
                (PU8)gdi_layer_buffer_ptr,
                region_0_buf_size);

            /*gdi_layer_create_double_using_outside_memory(
                rect_ptr->offset_x,
                rect_ptr->offset_y,
                rect_ptr->width,        
                rect_ptr->height,        
                &g_vdorec_cntx.osd_layer_region_handle[0],   
                (PU8)g_vdorec_cntx.osd_layer_region_handle_ptr[0],
                (S32)region_0_buf_size);*/
            
            gdi_layer_push_and_set_active(g_vdorec_cntx.osd_layer_region_handle[0]);       
            gdi_layer_clear(GDI_COLOR_TRANSPARENT);
            gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
            gdi_layer_pop_and_restore_active();
            
            /* region 1 */
            rect_ptr = &g_vdorec_osd_cntx.osd_layer_region.region_1;    
            region_1_buf_size = rect_ptr->width*rect_ptr->height*VDOREC_BUFFER_DEPTH;
            g_vdorec_cntx.osd_layer_region_handle_ptr[1] = (PU8) mmi_frm_scrmem_alloc_framebuffer(region_1_buf_size);
            
            gdi_layer_create_cf_double_using_outside_memory(
                GDI_COLOR_FORMAT_16,
                rect_ptr->offset_x,
                rect_ptr->offset_y,
                rect_ptr->width,
                rect_ptr->height,
                &g_vdorec_cntx.osd_layer_region_handle[1],
                (PU8)g_vdorec_cntx.osd_layer_region_handle_ptr[1],
                region_1_buf_size,
                (PU8)gdi_layer_buffer_ptr + region_0_buf_size,
                region_1_buf_size);
            
            /*gdi_layer_create_double_using_outside_memory(
                rect_ptr->offset_x,
                rect_ptr->offset_y,
                rect_ptr->width,        
                rect_ptr->height,        
                &g_vdorec_cntx.osd_layer_region_handle[1],   
                (PU8)g_vdorec_cntx.osd_layer_region_handle_ptr[1],
                (S32)region_1_buf_size);*/
            
            gdi_layer_push_and_set_active(g_vdorec_cntx.osd_layer_region_handle[1]);       
            gdi_layer_clear(GDI_COLOR_TRANSPARENT);
            gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
            gdi_layer_pop_and_restore_active();
            
            /* region 2 */
            rect_ptr = &g_vdorec_osd_cntx.osd_layer_region.region_2;    
            region_2_buf_size = rect_ptr->width*rect_ptr->height*VDOREC_BUFFER_DEPTH;
            g_vdorec_cntx.osd_layer_region_handle_ptr[2] = (PU8) mmi_frm_scrmem_alloc_framebuffer(region_2_buf_size);
            
            gdi_layer_create_cf_double_using_outside_memory(
                GDI_COLOR_FORMAT_16,
                rect_ptr->offset_x,
                rect_ptr->offset_y,
                rect_ptr->width,
                rect_ptr->height,
                &g_vdorec_cntx.osd_layer_region_handle[2],
                (PU8)g_vdorec_cntx.osd_layer_region_handle_ptr[2],
                region_2_buf_size,
                (PU8)gdi_layer_buffer_ptr + region_0_buf_size + region_1_buf_size,
                region_2_buf_size);

            /*gdi_layer_create_double_using_outside_memory(
                rect_ptr->offset_x,
                rect_ptr->offset_y,
                rect_ptr->width,        
                rect_ptr->height,        
                &g_vdorec_cntx.osd_layer_region_handle[2],   
                (PU8)g_vdorec_cntx.osd_layer_region_handle_ptr[2],
                (S32)region_2_buf_size);*/
            
            gdi_layer_push_and_set_active(g_vdorec_cntx.osd_layer_region_handle[2]);       
            gdi_layer_clear(GDI_COLOR_TRANSPARENT);
            gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
            gdi_layer_pop_and_restore_active();
            
            /* region 3 */
            if (g_vdorec_cntx.osd_layer_region_count == VDOREC_OSD_LAYER_COUNT_FOUR)
            {
                rect_ptr = &g_vdorec_osd_cntx.osd_layer_region.region_3;    
                region_3_buf_size = rect_ptr->width*rect_ptr->height*VDOREC_BUFFER_DEPTH;
                g_vdorec_cntx.osd_layer_region_handle_ptr[3] = (PU8) mmi_frm_scrmem_alloc_framebuffer(region_3_buf_size);
                
                gdi_layer_create_cf_double_using_outside_memory(
                    GDI_COLOR_FORMAT_16,
                    rect_ptr->offset_x,
                    rect_ptr->offset_y,
                    rect_ptr->width,
                    rect_ptr->height,
                    &g_vdorec_cntx.osd_layer_region_handle[3],
                    (PU8)g_vdorec_cntx.osd_layer_region_handle_ptr[3],
                    region_3_buf_size,
                    (PU8)gdi_layer_buffer_ptr + region_0_buf_size + region_1_buf_size + region_2_buf_size,
                    region_3_buf_size);

                /*gdi_layer_create_double_using_outside_memory(
                    rect_ptr->offset_x,
                    rect_ptr->offset_y,
                    rect_ptr->width,        
                    rect_ptr->height,        
                    &g_vdorec_cntx.osd_layer_region_handle[3],   
                    (PU8)g_vdorec_cntx.osd_layer_region_handle_ptr[3],
                    (S32)region_3_buf_size);*/
                
                gdi_layer_push_and_set_active(g_vdorec_cntx.osd_layer_region_handle[3]);       
                gdi_layer_clear(GDI_COLOR_TRANSPARENT);
                gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
                gdi_layer_pop_and_restore_active();
            }
            else
            {
                g_vdorec_cntx.osd_layer_region_handle[3] = GDI_LAYER_EMPTY_HANDLE;
            }
        }
    }

    if (g_vdorec_cntx.osd_layer_region_count != VDOREC_OSD_LAYER_COUNT_ONE) 
    {
        /*init region layer mask*/
        g_vdorec_cntx.osd_layer_region_mask[0] = 0;

        panel_ptr = &g_vdorec_osd_cntx.panel;
        g_vdorec_cntx.ev_draw_layer = mmi_vdorec_get_layer_handle_by_position(panel_ptr->ev.offset_x, panel_ptr->ev.offset_y, VDOREC_OSD_COMPONENT_EV);
        g_vdorec_cntx.zoom_draw_layer = mmi_vdorec_get_layer_handle_by_position(panel_ptr->zoom.offset_x, panel_ptr->zoom.offset_y, VDOREC_OSD_COMPONENT_ZOOM);
        g_vdorec_cntx.timer_draw_layer = mmi_vdorec_get_layer_handle_by_position(panel_ptr->timer.offset_x, panel_ptr->timer.offset_y, VDOREC_OSD_COMPONENT_TIMER | VDOREC_OSD_COMPONENT_CLEAR_TIMER);
        /*currently we make the state in front of timer, so they are the same layer*/
        g_vdorec_cntx.state_draw_layer = mmi_vdorec_get_layer_handle_by_position(panel_ptr->timer.offset_x, panel_ptr->timer.offset_y, VDOREC_OSD_COMPONENT_STATE);
        
        if (mmi_vdorec_is_draw_progress_bar())
        {
            g_vdorec_cntx.progress_draw_layer = mmi_vdorec_get_layer_handle_by_position(panel_ptr->progress_bar.offset_x, panel_ptr->progress_bar.offset_y, VDOREC_OSD_COMPONENT_PROGRESS | VDOREC_OSD_COMPONENT_CLEAR_PROGRESS);
        }
        
        sk_ptr = &g_vdorec_osd_cntx.softkey;
        g_vdorec_cntx.ck_draw_layer = mmi_vdorec_get_layer_handle_by_position(sk_ptr->icon_ck_pos.offset_x, sk_ptr->icon_ck_pos.offset_y, VDOREC_OSD_COMPONENT_SOFTKEY);
        g_vdorec_cntx.lsk_draw_layer = mmi_vdorec_get_layer_handle_by_position(sk_ptr->icon_lsk_pos.offset_x, sk_ptr->icon_lsk_pos.offset_y, VDOREC_OSD_COMPONENT_SOFTKEY);
        g_vdorec_cntx.rsk_draw_layer = mmi_vdorec_get_layer_handle_by_position(sk_ptr->icon_rsk_pos.offset_x, sk_ptr->icon_rsk_pos.offset_y, VDOREC_OSD_COMPONENT_SOFTKEY);     
        
        if (g_vdorec_osd_cntx.title.is_draw_app_name)
        {       
            g_vdorec_cntx.title_draw_layer = mmi_vdorec_get_layer_handle_by_position(g_vdorec_osd_cntx.title.rect.offset_x, g_vdorec_osd_cntx.title.rect.offset_y, VDOREC_OSD_COMPONENT_TITLE); 
        }
        
        g_vdorec_cntx.status_draw_layer = mmi_vdorec_get_layer_handle_by_position(g_vdorec_osd_cntx.status.video_size.offset_x, g_vdorec_osd_cntx.status.video_size.offset_y, VDOREC_OSD_COMPONENT_STATUS | VDOREC_OSD_COMPONENT_CLEAR_STATUS); 

        g_vdorec_cntx.hint_draw_layer = mmi_vdorec_get_layer_handle_by_position(g_vdorec_osd_cntx.hint.rect.offset_x, g_vdorec_osd_cntx.hint.rect.offset_y, VDOREC_OSD_COMPONENT_HINT); 
    }
    else
    {
        if (g_vdorec_cntx.is_use_hw_rotate)
        {
            /* if have HW rotator support, we will draw to a tmp buffer, then rotate to bg buffer */
            g_vdorec_cntx.ev_draw_layer = g_vdorec_cntx.tmp_osd_layer_region_handle[0];
            g_vdorec_cntx.zoom_draw_layer = g_vdorec_cntx.tmp_osd_layer_region_handle[0];
            g_vdorec_cntx.timer_draw_layer = g_vdorec_cntx.tmp_osd_layer_region_handle[0];
            g_vdorec_cntx.state_draw_layer = g_vdorec_cntx.tmp_osd_layer_region_handle[0];
            g_vdorec_cntx.rsk_draw_layer = g_vdorec_cntx.tmp_osd_layer_region_handle[0];
            g_vdorec_cntx.lsk_draw_layer = g_vdorec_cntx.tmp_osd_layer_region_handle[0];
            g_vdorec_cntx.ck_draw_layer = g_vdorec_cntx.tmp_osd_layer_region_handle[0];
            g_vdorec_cntx.title_draw_layer = g_vdorec_cntx.tmp_osd_layer_region_handle[0];
            g_vdorec_cntx.status_draw_layer = g_vdorec_cntx.tmp_osd_layer_region_handle[0];
            g_vdorec_cntx.hint_draw_layer = g_vdorec_cntx.tmp_osd_layer_region_handle[0];
            g_vdorec_cntx.progress_draw_layer = g_vdorec_cntx.tmp_osd_layer_region_handle[0];
        }
        else
        {
            g_vdorec_cntx.ev_draw_layer = g_vdorec_cntx.osd_layer_handle;
            g_vdorec_cntx.zoom_draw_layer = g_vdorec_cntx.osd_layer_handle;
            g_vdorec_cntx.timer_draw_layer = g_vdorec_cntx.osd_layer_handle;
            g_vdorec_cntx.state_draw_layer = g_vdorec_cntx.osd_layer_handle;
            g_vdorec_cntx.rsk_draw_layer = g_vdorec_cntx.osd_layer_handle;
            g_vdorec_cntx.lsk_draw_layer = g_vdorec_cntx.osd_layer_handle;
            g_vdorec_cntx.ck_draw_layer = g_vdorec_cntx.osd_layer_handle;
            g_vdorec_cntx.title_draw_layer = g_vdorec_cntx.osd_layer_handle;
            
            g_vdorec_cntx.status_draw_layer = g_vdorec_cntx.osd_layer_handle;
            g_vdorec_cntx.hint_draw_layer = g_vdorec_cntx.osd_layer_handle;
            g_vdorec_cntx.progress_draw_layer = g_vdorec_cntx.osd_layer_handle;
            
        #ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__
            //g_vdorec_cntx.del_draw_layer = g_vdorec_cntx.osd_layer_handle;
        #endif
        }
    }
    
    /* timer */
    gdi_image_get_dimension_id(IMG_ID_VDOREC_TIME_COL, &col_width, &height);
    gdi_image_get_dimension_id(IMG_ID_VDOREC_EFFECT_NUMBER_0, &digit_width, &height);

    g_vdorec_cntx.timer.offset_y = g_vdorec_osd_cntx.panel.timer.offset_y;

    g_vdorec_cntx.timer.hr_0_offset_x = g_vdorec_osd_cntx.panel.timer.offset_x;
    g_vdorec_cntx.timer.hr_1_offset_x = g_vdorec_cntx.timer.hr_0_offset_x + digit_width;
    g_vdorec_cntx.timer.col_0_offset_x = g_vdorec_cntx.timer.hr_1_offset_x + digit_width;
    g_vdorec_cntx.timer.min_0_offset_x = g_vdorec_cntx.timer.col_0_offset_x + col_width;
    g_vdorec_cntx.timer.min_1_offset_x = g_vdorec_cntx.timer.min_0_offset_x + digit_width;
    g_vdorec_cntx.timer.col_1_offset_x = g_vdorec_cntx.timer.min_1_offset_x + digit_width;
    g_vdorec_cntx.timer.sec_0_offset_x = g_vdorec_cntx.timer.col_1_offset_x + col_width;
    g_vdorec_cntx.timer.sec_1_offset_x = g_vdorec_cntx.timer.sec_0_offset_x + digit_width;

#ifdef __VDOREC_FEATURE_TOUCH_SCREEN__
    g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;

    /* init touch region */

    /* ev inc */
    memset(&g_vdorec_cntx.touch_ev_inc, 0, sizeof(vdorec_ui_touch_struct));
    memset(&g_vdorec_cntx.touch_ev_dec, 0, sizeof(vdorec_ui_touch_struct));    
#ifdef __VDOREC_FEATURE_EV__
    touch_p = &g_vdorec_cntx.touch_ev_inc;
    touch_p->offset_x = g_vdorec_osd_cntx.panel.ev_inc.offset_x;
    touch_p->offset_y = g_vdorec_osd_cntx.panel.ev_inc.offset_y;
    touch_p->is_press = FALSE;
    gdi_image_get_dimension_id(IMG_ID_VDOREC_TOUCH_OSD_EV_INC, &touch_p->width, &touch_p->height);

    /* ev dec */
    touch_p = &g_vdorec_cntx.touch_ev_dec;
    touch_p->offset_x = g_vdorec_osd_cntx.panel.ev_dec.offset_x;
    touch_p->offset_y = g_vdorec_osd_cntx.panel.ev_dec.offset_y;
    touch_p->is_press = FALSE;
    gdi_image_get_dimension_id(IMG_ID_VDOREC_TOUCH_OSD_EV_DEC, &touch_p->width, &touch_p->height);
#endif /* __VDOREC_FEATURE_EV__ */

    /* zoom inc */
    memset(&g_vdorec_cntx.touch_zoom_inc, 0, sizeof(vdorec_ui_touch_struct));
    memset(&g_vdorec_cntx.touch_zoom_dec, 0, sizeof(vdorec_ui_touch_struct)); 

#ifdef __VDOREC_FEATURE_ZOOM__    
    touch_p = &g_vdorec_cntx.touch_zoom_inc;
    touch_p->offset_x = g_vdorec_osd_cntx.panel.zoom_inc.offset_x;
    touch_p->offset_y = g_vdorec_osd_cntx.panel.zoom_inc.offset_y;
    touch_p->is_press = FALSE;
    gdi_image_get_dimension_id(IMG_ID_VDOREC_TOUCH_OSD_ZOOM_INC, &touch_p->width, &touch_p->height);

    /* zoom dec */
    touch_p = &g_vdorec_cntx.touch_zoom_dec;
    touch_p->offset_x = g_vdorec_osd_cntx.panel.zoom_dec.offset_x;
    touch_p->offset_y = g_vdorec_osd_cntx.panel.zoom_dec.offset_y;
    touch_p->is_press = FALSE;
    gdi_image_get_dimension_id(IMG_ID_VDOREC_TOUCH_OSD_ZOOM_DEC, &touch_p->width, &touch_p->height);
#endif /* __VDOREC_FEATURE_EV__ */

    /***************** 1. video size *******************/
    /***************** 2. video qty ********************/
    /***************** 3. night ************************/
    /***************** 4. wb ***************************/
    /***************** 5. led highlight ****************/
    /***************** 6. record audio *****************/

#ifdef __VDOREC_FEATURE_VIDEO_SIZE__
    touch_p = &g_vdorec_cntx.touch_video_size;
    touch_p->offset_x = g_vdorec_osd_cntx.status.video_size.offset_x;
    touch_p->offset_y = g_vdorec_osd_cntx.status.video_size.offset_y;
    touch_p->is_press = FALSE;
    gdi_image_get_dimension_id(IMG_ID_VDOREC_OSD_VIDEO_SIZE_START + 1, &touch_p->width, &touch_p->height);
#endif

#ifdef __VDOREC_FEATURE_VIDEO_QTY__
    touch_p = &g_vdorec_cntx.touch_video_qty;
    touch_p->offset_x = g_vdorec_osd_cntx.status.video_qty.offset_x;
    touch_p->offset_y = g_vdorec_osd_cntx.status.video_qty.offset_y;
    touch_p->is_press = FALSE;
    gdi_image_get_dimension_id(IMG_ID_VDOREC_OSD_VIDEO_QTY_START + 1, &touch_p->width, &touch_p->height);
#endif

#ifdef __VDOREC_FEATURE_NIGHT__
    touch_p = &g_vdorec_cntx.touch_night;
    touch_p->offset_x = g_vdorec_osd_cntx.status.night.offset_x;
    touch_p->offset_y = g_vdorec_osd_cntx.status.night.offset_y;
    touch_p->is_press = FALSE;
    gdi_image_get_dimension_id(IMG_ID_VDOREC_OSD_NIGHT_START + 1, &touch_p->width, &touch_p->height);
#endif

#ifdef __VDOREC_FEATURE_WB__
    touch_p = &g_vdorec_cntx.touch_wb;
    touch_p->offset_x = g_vdorec_osd_cntx.status.wb.offset_x;
    touch_p->offset_y = g_vdorec_osd_cntx.status.wb.offset_y;
    touch_p->is_press = FALSE;
    gdi_image_get_dimension_id(IMG_ID_VDOREC_OSD_WB_START + 1, &touch_p->width, &touch_p->height);
#endif

#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT__
    touch_p = &g_vdorec_cntx.touch_led_highlight;
    touch_p->offset_x = g_vdorec_osd_cntx.status.led_highlight.offset_x;
    touch_p->offset_y = g_vdorec_osd_cntx.status.led_highlight.offset_y;
    touch_p->is_press = FALSE;
    gdi_image_get_dimension_id(IMG_ID_VDOREC_OSD_LED_HIGHLIGHT_START + 1, &touch_p->width, &touch_p->height);
#endif

#ifdef __VDOREC_FEATURE_RECORD_AUD__
    touch_p = &g_vdorec_cntx.touch_record_aud;
    touch_p->offset_x = g_vdorec_osd_cntx.status.record_aud.offset_x;
    touch_p->offset_y = g_vdorec_osd_cntx.status.record_aud.offset_y;
    touch_p->is_press = FALSE;
    gdi_image_get_dimension_id(IMG_ID_VDOREC_OSD_RECORD_AUD_START + 1, &touch_p->width, &touch_p->height);
#endif

#ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__
    touch_p = &g_vdorec_cntx.touch_del;
    touch_p->is_press = FALSE;
    touch_p->offset_x = g_vdorec_osd_cntx.panel.zoom.offset_x;
    touch_p->offset_y = g_vdorec_osd_cntx.panel.zoom.offset_y;
    gdi_image_get_dimension_id(IMG_ID_VDOREC_SK_DELETE, &touch_p->width, &touch_p->height);
#endif /* __VDOREC_FEATURE_PREVIEW_SAVED_FILE__ */

#endif /* __VDOREC_FEATURE_TOUCH_SCREEN__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_draw_style_text
 * DESCRIPTION
 *  draw styled text
 * PARAMETERS
 *  str             [IN]        String
 *  offset_x        [IN]        Offset x
 *  offset_y        [IN]        Offset y
 *  truncate_width  [IN]        Tauncate width
 *  style_txt       [IN]        Text style
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_draw_style_text(PS8 str, S32 offset_x, S32 offset_y, S32 truncate_width, video_style_text_struct *style_txt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_DRAW_STYLE_TEXT);

    if (r2lMMIFlag)
    {
        offset_x += gui_get_string_width((UI_string_type) str);
    }

    if (style_txt->style == VIDEO_TEXT_STYLE_NORMAL)
    {
        if (truncate_width != 0)
        {
            gui_set_text_color(gui_color(style_txt->r, style_txt->g, style_txt->b));
            gui_print_truncated_text(offset_x, offset_y, truncate_width, (UI_string_type)str);
        }
        else
        {
            gui_move_text_cursor(offset_x, offset_y);
            gui_set_text_color(gui_color(style_txt->r, style_txt->g, style_txt->b));
            gui_print_text((UI_string_type) str);
        }
    }
    else if (style_txt->style == VIDEO_TEXT_STYLE_BORDER)
    {
        if (truncate_width != 0)
        {        
            gui_set_text_color(gui_color(style_txt->r, style_txt->g, style_txt->b));
            gui_set_text_border_color(gui_color(style_txt->style_r, style_txt->style_g, style_txt->style_b));
            gui_print_truncated_borderd_text(offset_x, offset_y, truncate_width, (UI_string_type)str);
        }
        else
        {
            gui_move_text_cursor(offset_x, offset_y);
            gui_set_text_color(gui_color(style_txt->r, style_txt->g, style_txt->b));
            gui_set_text_border_color(gui_color(style_txt->style_r, style_txt->style_g, style_txt->style_b));
            gui_print_bordered_text((UI_string_type) str);
        }
    }
    else if (style_txt->style == VIDEO_TEXT_STYLE_SHADOW)
    {
        if (truncate_width != 0)
        {            
            gui_set_text_color(gui_color(style_txt->style_r, style_txt->style_g, style_txt->style_b));
            gui_print_truncated_text(offset_x + 1, offset_y + 1, truncate_width, (UI_string_type)str);
            
            gui_set_text_color(gui_color(style_txt->r, style_txt->g, style_txt->b));
            gui_print_truncated_text(offset_x, offset_y, truncate_width, (UI_string_type)str);
        }
        else
        {
            gui_move_text_cursor(offset_x + 1, offset_y + 1);
            gui_set_text_color(gui_color(style_txt->style_r, style_txt->style_g, style_txt->style_b));
            gui_print_text((UI_string_type) str);

            gui_move_text_cursor(offset_x, offset_y);
            gui_set_text_color(gui_color(style_txt->r, style_txt->g, style_txt->b));
            gui_print_text((UI_string_type) str);
        }
    }
    else
    {
        MMI_ASSERT(0);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_hide_hint
 * DESCRIPTION
 *  Hide hint
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_hide_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_HIDE_HINT);

    mmi_vdorec_set_hint(NULL, NULL, 0);
    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_HINT);
    mmi_vdorec_blt_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_draw_hint
 * DESCRIPTION
 *  enter save screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_draw_hint(void)
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
    S32 layer_offset_x;
    S32 layer_offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_DRAW_HINT, g_vdorec_osd_cntx.hint.is_show);

    if (!g_vdorec_osd_cntx.hint.is_show)
    {
        return;
    }
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    mmi_fe_set_antialias(MMI_FALSE);
#endif

    gdi_layer_push_and_set_active(g_vdorec_cntx.hint_draw_layer);

    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

    gdi_draw_solid_rect(
        g_vdorec_osd_cntx.hint.rect.offset_x - layer_offset_x, 
        g_vdorec_osd_cntx.hint.rect.offset_y - layer_offset_y, 
        g_vdorec_osd_cntx.hint.rect.offset_x + g_vdorec_osd_cntx.hint.rect.width - layer_offset_x, 
        g_vdorec_osd_cntx.hint.rect.offset_y + g_vdorec_osd_cntx.hint.rect.height - layer_offset_y, 
        GDI_COLOR_TRANSPARENT);

    if (g_vdorec_cntx.hint1_buf != NULL)
    {
        gui_measure_string((UI_string_type) g_vdorec_cntx.hint1_buf, &str1_width, &str1_height);

        if (g_vdorec_cntx.hint2_buf == NULL)
        {
            str1_offset_x = (str1_width < g_vdorec_osd_cntx.hint.rect.width)?
                            ((g_vdorec_osd_cntx.hint.rect.width - str1_width) >> 1):
                            0;

            str1_offset_y = (g_vdorec_osd_cntx.hint.rect.height - str1_height) >> 1;
        }
        else
        {
            gui_measure_string((UI_string_type) g_vdorec_cntx.hint2_buf, &str2_width, &str2_height);
            
            str1_offset_x = (str1_width < g_vdorec_osd_cntx.hint.rect.width)?
                            ((g_vdorec_osd_cntx.hint.rect.width - str1_width) >> 1):
                            0;

            /* use string1_height only becuz string 2 is usually longer and may be truncated in some cases */
            spacing = g_vdorec_osd_cntx.hint.rect.height - (str1_height << 1); 
            spacing = (spacing > 0) ? (spacing / 3 + 1) : 0;

            str1_offset_y = spacing;

            str2_offset_x = (str2_width < g_vdorec_osd_cntx.hint.rect.width)?
                            ((g_vdorec_osd_cntx.hint.rect.width - str2_width) >> 1):
                            0;
            str2_offset_y = spacing * 2 + 1 + str1_height;
        }

        str1_offset_x += g_vdorec_osd_cntx.hint.rect.offset_x - layer_offset_x;
        str1_offset_y += g_vdorec_osd_cntx.hint.rect.offset_y - layer_offset_y;
        str2_offset_x += g_vdorec_osd_cntx.hint.rect.offset_x - layer_offset_x;
        str2_offset_y += g_vdorec_osd_cntx.hint.rect.offset_y - layer_offset_y;

        gdi_layer_reset_clip();
        gui_reset_text_clip();

        mmi_vdorec_draw_style_text(
            g_vdorec_cntx.hint1_buf,
            str1_offset_x,
            str1_offset_y,
            g_vdorec_osd_cntx.hint.rect.width,
            &g_vdorec_osd_cntx.hint.style_text);

        if (g_vdorec_cntx.hint2_buf != NULL)
        {
            mmi_vdorec_draw_style_text(
                g_vdorec_cntx.hint2_buf,
                str2_offset_x,
                str2_offset_y,
                g_vdorec_osd_cntx.hint.rect.width,
                &g_vdorec_osd_cntx.hint.style_text);
        }

        if (g_vdorec_cntx.fade_time != 0)
        {
            gui_start_timer(HINT_POPUP_FADE_TIME, mmi_vdorec_hide_hint);
        }

    }

    gdi_layer_pop_and_restore_active();

#ifdef __MMI_VECTOR_FONT_SUPPORT__
    mmi_fe_set_antialias(MMI_TRUE);
#endif

    if (g_vdorec_cntx.is_use_blt_region)
    {
        mmi_vdorec_merge_blt_rgn(
            g_vdorec_osd_cntx.hint.rect.offset_x, 
            g_vdorec_osd_cntx.hint.rect.offset_y, 
            g_vdorec_osd_cntx.hint.rect.width, 
            g_vdorec_osd_cntx.hint.rect.height);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_set_hint
 * DESCRIPTION
 *  set hint string
 * PARAMETERS
 *  hint_str1       [IN]        String 1
 *  hint_str2       [IN]        String 2
 *  fade_time       [IN]        Hint fade out time
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_set_hint(PS8 hint_str1, PS8 hint_str2, U16 fade_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_SET_HINT);

    /* clear buffer */
    memset(g_vdorec_cntx.hint1_buf, 0, VDOREC_HINT_BUF_SIZE);
    memset(g_vdorec_cntx.hint2_buf, 0, VDOREC_HINT_BUF_SIZE);

    if (hint_str1 != NULL)
    {
        mmi_ucs2ncpy((PS8) g_vdorec_cntx.hint1_buf, (PS8) hint_str1, VDOREC_HINT_CHAR_COUNT);
    }

    if (hint_str2 != NULL)
    {
        mmi_ucs2ncpy((PS8) g_vdorec_cntx.hint2_buf, (PS8) hint_str2, VDOREC_HINT_CHAR_COUNT);
    }

    g_vdorec_cntx.fade_time = fade_time;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_draw_osd
 * DESCRIPTION
 *  draw osd, currently, all the component is in osd layer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_draw_osd(U32 component)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdorec_cntx.is_use_blt_region)
    {
        mmi_vdorec_set_merge_region(0, 0, 0, 0);
    }

    if (g_vdorec_cntx.osd_layer_region_count == VDOREC_OSD_LAYER_COUNT_ONE)
    {
        gdi_layer_push_and_set_active(g_vdorec_cntx.osd_layer_handle);
        
        /* toggle double buffer */
        if (gdi_layer_is_double(g_vdorec_cntx.osd_layer_handle))
        {
            gdi_layer_toggle_double();
            if (!g_vdorec_cntx.is_use_hw_rotate)
            {
                /*for 6253 serial, we will use tmp buffer for drawing, this copy is useless,
                  so remove this to update performance*/
                gdi_layer_copy_double();
            }
        }

        gdi_layer_pop_and_restore_active();
    }
    else    
    {
        /*prepare the region 0 OSD buffer*/
		/*this algo will have some error, and need to modify much, so I just copy*/
        for (i = 0; i< g_vdorec_cntx.osd_layer_region_count; i++)
        {
            if (g_vdorec_cntx.osd_layer_region_mask[i] & component)
            {
                if (g_vdorec_cntx.is_use_hw_rotate)
                {
                    g_vdorec_cntx.is_osd_layer_updated[i] = MMI_TRUE;
                }
                else
                {
                    g_vdorec_cntx.is_osd_layer_updated[i] = MMI_FALSE;
                }
                gdi_layer_push_and_set_active(g_vdorec_cntx.osd_layer_region_handle[i]);
                
                if (gdi_layer_is_double(g_vdorec_cntx.osd_layer_region_handle[i]))
                {
                    gdi_layer_toggle_double();
                    if (!g_vdorec_cntx.is_use_hw_rotate)
                    {
                        /*for 6253 serial, we will use tmp buffer for drawing, this copy is useless,
                        so remove this to update performance*/
                        gdi_layer_copy_double();
                    }
                }  
                
                gdi_layer_pop_and_restore_active();
            }
            else
            {
                g_vdorec_cntx.is_osd_layer_updated[i] = MMI_FALSE;
            }
        }

        /*for (i = 0; i< g_vdorec_cntx.osd_layer_region_count; i++)
        {
            gdi_layer_push_and_set_active(g_vdorec_cntx.osd_layer_region_handle[i]);
			
            if (gdi_layer_is_double(g_vdorec_cntx.osd_layer_region_handle[i]))
            {
                gdi_layer_toggle_double();
                gdi_layer_copy_double();
            }  
			
            gdi_layer_pop_and_restore_active();
        }*/
    }

	gui_lock_double_buffer();

    /*if no layer background, will draw image instead*/
    if (g_vdorec_cntx.is_disp_bg_img_usint_color)
    {
        component |= VDOREC_OSD_COMPONENT_SOFTKEY;
        component |= VDOREC_OSD_COMPONENT_STATUS;
        mmi_vdorec_draw_bg_color();
    }
    else if (g_vdorec_cntx.is_disp_bg_img)
    {
        mmi_vdorec_draw_bg_image();
    }

	if (SCR_ID_VDOREC_SAVED_PREVIEW == GetActiveScreenId())
    {
        if (component & VDOREC_OSD_COMPONENT_TITLE)
        {
            mmi_vdorec_draw_title();
        }

        if (component & VDOREC_OSD_COMPONENT_TIMER)
        {
            mmi_vdorec_draw_panel_timer();
        }

        if (component & VDOREC_OSD_COMPONENT_SOFTKEY)
        {
            mmi_vdorec_draw_softkey();
        }

        if (component & VDOREC_OSD_COMPONENT_DELETE)
        {
            mmi_vdorec_draw_softkey();
        }
    }
    else
    {
        /* clear*/
        if (component & VDOREC_OSD_COMPONENT_CLEAR_STATUS)
        {
            mmi_vdorec_clear_status();
        }

        if (component & VDOREC_OSD_COMPONENT_CLEAR_TIMER)
        {
            mmi_vdorec_clear_timer();
        }

        if (component & VDOREC_OSD_COMPONENT_CLEAR_PROGRESS)
        {
            mmi_vdorec_clear_panel_progress_bar();
        }

        /* drawing */
        if (component & VDOREC_OSD_COMPONENT_STATUS)
        {
            mmi_vdorec_draw_status();
        }
        
        if (component&VDOREC_OSD_COMPONENT_HINT)
        {
            mmi_vdorec_draw_hint();
        }
        
        if (component&VDOREC_OSD_COMPONENT_STATE)
        {
            mmi_vdorec_draw_panel_state();
        }
        
        if (component&VDOREC_OSD_COMPONENT_EV)
        {
            mmi_vdorec_draw_panel_ev();
        }
        
        if (component&VDOREC_OSD_COMPONENT_ZOOM)
        {
            mmi_vdorec_draw_panel_zoom();
        }
        
        if (component&VDOREC_OSD_COMPONENT_SOFTKEY)
        {
            mmi_vdorec_draw_softkey();
        }
        
        if (component&VDOREC_OSD_COMPONENT_TITLE)
        {
            mmi_vdorec_draw_title();
        }
        
        if (component&VDOREC_OSD_COMPONENT_PROGRESS)
        {
            mmi_vdorec_draw_panel_progress_bar((U8)g_vdorec_cntx.progress);
        }
        
        if (component&VDOREC_OSD_COMPONENT_TIMER)
        {
            mmi_vdorec_draw_panel_timer();
        }
    }    
	gui_unlock_double_buffer();
}



/*****************************************************************************
*
*  Save Screen
*
*****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_save_confirm_no
 * DESCRIPTION
 *  enter save screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_save_confirm_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filepath[FMGR_PATH_BUFFER_SIZE];
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_SAVE_CONFIRM_NO);

    /* delete unsaved file */
    mmi_vdoply_get_storage_file_path(buf_filepath);
    mdi_video_rec_delete_unsaved_file(buf_filepath);

    if (g_vdorec_cntx.is_ext_req && g_vdorec_cntx.is_use_ext_req_path)
    {
        /* use external path, do nothing */
    }
    else
    {
        /* the seq num is already increase, so if we dont want to save this file, decrease it */
        ReadValue(NVRAM_VDOREC_FILENAME_SEQ_NO, &g_vdorec_cntx.filename_seq_no, DS_SHORT, &error);

        if (g_vdorec_cntx.filename_seq_no > 1)
        {
            g_vdorec_cntx.filename_seq_no--;
        }
           
        WriteValue(NVRAM_VDOREC_FILENAME_SEQ_NO, &g_vdorec_cntx.filename_seq_no, DS_SHORT, &error);
    }

    if (g_vdorec_cntx.is_ext_req)
    {
#ifdef __VDOREC_FEATURE_BACK_TO_PREVIEW_SCREEN_IF_NOT_ADD__
        DeleteUptoScrID(SCR_ID_VDOREC_APP);
        
        GoBackHistory();
#else
        /* delete all video recorder screen */
        DeleteUptoScrID(SCR_ID_VDOREC_APP);
        DeleteNHistory(1);

        /* notify request caller, video is not saved */
        g_vdorec_cntx.ext_req_callback(MMI_FALSE, NULL);
        g_vdorec_cntx.ext_req_callback = NULL;
        GoBackHistory();
#endif
    }
    else
    {
        GoBackHistory();
    }
   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_save_confirm_screen
 * DESCRIPTION
 *  enter save confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_entry_save_confirm_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_send_support = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ENTRY_SAVE_CONFIRM_SCREEN);

	ClearInputEventHandler(MMI_DEVICE_KEY);
    
#ifdef __MMI_VDOREC_MMS_SUPPORT__
    if (mms_is_ready())
    {
        is_send_support = MMI_TRUE;
    }
    else
    {
        is_send_support = MMI_FALSE;
    }
#else
    is_send_support = MMI_FALSE;
#endif

    if (!is_send_support)
    {
    #ifdef __MMI_BT_SEND_SUPPORT__
        is_send_support = mmi_bt_is_to_display_bt_menu();
    #else
        is_send_support = MMI_FALSE;
    #endif
    }
    
    if (!is_send_support)
    {
    #ifdef __MMI_VDOREC_EMAIL_SUPPORT__
        is_send_support = mmi_email_is_email_can_forward();
    #else 
        is_send_support = MMI_FALSE;
    #endif
    }
    
#ifdef  __VDOREC_FEATURE_DIRECT_SAVE__
    is_send_support = MMI_FALSE;
#endif

if (g_vdorec_cntx.is_ext_req)
{
    is_send_support = MMI_FALSE;
}

#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    #ifdef __MMI_WGUI_CSK_ENABLE__
        g_vdorec_cntx.is_foward_to = FALSE;
        g_vdorec_cntx.is_save_done_when_mt = FALSE;
        
        if (is_send_support)
        {
            mmi_display_popup_confirmext_rotated(
                get_string(STR_GLOBAL_YES),
                get_image(IMG_GLOBAL_YES),
                get_string(STR_GLOBAL_NO),
                get_image(IMG_GLOBAL_NO),
                0,
                IMG_ID_VDOREC_FORWARD_TO_MMS,
                (UI_string_type)get_string(STR_GLOBAL_SAVE_ASK),
                MMI_EVENT_QUERY,
                MMI_FRM_SCREEN_ROTATE_270);

            register_center_softkey_to_enter_key();
            SetCenterSoftkeyFunction(mmi_vdorec_save_confirm_forward_to, KEY_EVENT_UP);
        }
        else
        {
            mmi_display_popup_confirm_rotated(
                get_string(STR_GLOBAL_YES),
                get_image(IMG_GLOBAL_YES),
                get_string(STR_GLOBAL_NO),
                get_image(IMG_GLOBAL_NO),
                get_string(STR_GLOBAL_SAVE_ASK),
                MMI_EVENT_QUERY,
                MMI_FRM_SCREEN_ROTATE_270);
        }        
    #else
        {
            mmi_display_popup_confirm_rotated(
                get_string(STR_GLOBAL_YES),
                get_image(IMG_GLOBAL_YES),
                get_string(STR_GLOBAL_NO),
                get_image(IMG_GLOBAL_NO),
                get_string(STR_GLOBAL_SAVE_ASK),
                MMI_EVENT_QUERY,
                MMI_FRM_SCREEN_ROTATE_270);
        }
    #endif
#else /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__) */
    #ifdef __MMI_WGUI_CSK_ENABLE__
        g_vdorec_cntx.is_foward_to = FALSE;
        g_vdorec_cntx.is_save_done_when_mt = FALSE;
        
        if (is_send_support)
        {
            mmi_display_popup_confirmext(
                get_string(STR_GLOBAL_YES),
                get_image(IMG_GLOBAL_YES),
                get_string(STR_GLOBAL_NO),
                get_image(IMG_GLOBAL_NO),
                0,
                IMG_ID_VDOREC_FORWARD_TO_MMS,
                get_string(STR_GLOBAL_SAVE_ASK),
                MMI_EVENT_QUERY);
            
            register_center_softkey_to_enter_key();
            SetCenterSoftkeyFunction(mmi_vdorec_save_confirm_forward_to, KEY_EVENT_UP);
        }
        else
        {
            mmi_display_popup_confirm(
                get_string(STR_GLOBAL_YES),
                get_image(IMG_GLOBAL_YES),
                get_string(STR_GLOBAL_NO),
                get_image(IMG_GLOBAL_NO),
                get_string(STR_GLOBAL_SAVE_ASK),
                MMI_EVENT_QUERY);
        }        
    #else
        {
            mmi_display_popup_confirm(
                get_string(STR_GLOBAL_YES),
                get_image(IMG_GLOBAL_YES),
                get_string(STR_GLOBAL_NO),
                get_image(IMG_GLOBAL_NO),
                get_string(STR_GLOBAL_SAVE_ASK),
                MMI_EVENT_QUERY);
        }
    #endif
#endif

    SetRightSoftkeyFunction(mmi_vdorec_save_confirm_no, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_vdorec_entry_saving_screen, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_save_confirm_forward_to
 * DESCRIPTION
 *  forward to key pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_save_confirm_forward_to(void)
{
#if (defined(__MMI_VDOREC_MMS_SUPPORT__) || defined(__MMI_BT_SEND_SUPPORT__) || defined(__MMI_EMAIL__)) && !defined(__VDOREC_FEATURE_DIRECT_SAVE__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_SAVE_FORWARD_TO);

    g_vdorec_cntx.is_foward_to = TRUE;
    mmi_vdorec_entry_saving_screen();
#endif /* defined(__MMI_VDOREC_MMS_SUPPORT__) && !defined(__VDOREC_FEATURE_DIRECT_SAVE__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_save_result_hdlr_callback
 * DESCRIPTION
 *  callback function when save is done
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_save_result_hdlr_callback(MDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_SAVE_RESULT_HDLR_CALLBACK);

    g_vdorec_cntx.is_saving = FALSE;

    /* if video recorder is already removed from history , do not show popup */
    if (!IsScreenPresent(SCR_ID_VDOREC_APP))
    {
        return;
    }

    if (g_vdorec_cntx.is_foward_to)
    {
    #if (defined(__MMI_VDOREC_MMS_SUPPORT__) || defined(__MMI_BT_SEND_SUPPORT__) || defined(__MMI_EMAIL__)) && !defined(__VDOREC_FEATURE_DIRECT_SAVE__)

        /* link to foward to */
        if (SCR_ID_VDOREC_SAVING == GetActiveScreenId())
        {
            /* enter only not in call and wap not in call */
            if (result >= 0)
            {
                /* foward to MMS */
                DeleteUptoScrID(SCR_ID_VDOREC_APP);
                /*mms_content_insert_hdlr(g_vdorec_cntx.filepath);*/
                mmi_vdorec_entry_send_screen();
                g_vdorec_cntx.is_foward_to = FALSE;
                DeleteScreenIfPresent(SCR_ID_VDOREC_SAVING);
                DeleteScreenIfPresent(SCR_ID_VDOREC_SAVE_CONFIRM);                
                return;
            }
            else if (result == MDI_RES_VDOREC_ERR_DISK_FULL)
            {
                mmi_vdorec_disply_popup(
                    (PU8) GetString(FMGR_FS_DISK_FULL_TEXT),
                    MMI_EVENT_FAILURE);
            }
            else
            {
                mmi_vdorec_disply_popup(
                    (PU8) GetString(STR_GLOBAL_FAILED_TO_SAVE),
                    MMI_EVENT_FAILURE);
            }

            DeleteScreenIfPresent(SCR_ID_VDOREC_SAVING);
            DeleteScreenIfPresent(SCR_ID_VDOREC_SAVE_CONFIRM);

            /* if clam is close, delete one more screen, avoid enter video recorder */
            if (IsClamClose())
            {
                DeleteNHistory(1);
            }

        }
        else
        {
            /*
             * when it is in MT, do nothing, will handle foward
             * to after back from MT 
             */

            g_vdorec_cntx.save_result = result;
            g_vdorec_cntx.is_save_done_when_mt = TRUE;
            return;

        }

    #endif /* __MMI_VDOREC_MMS_SUPPORT__ */ 

    }
    else
    {
        if (g_vdorec_cntx.is_ext_req)
        {
            DeleteScreenIfPresent(SCR_ID_VDOREC_SAVING);
            
            if (SCR_ID_VDOREC_SAVING == GetActiveScreenId())
            {
                /* enter only not in call and wap not in call */
                if (result >= 0)
                {
                    /* delete all video recorder screen */
                    DeleteScreenIfPresent(SCR_ID_VDOREC_SAVING);
                    DeleteScreenIfPresent(SCR_ID_VDOREC_SAVE_CONFIRM);
                    DeleteScreenIfPresent(SCR_ID_VDOREC_APP);
                    
                    g_vdorec_cntx.ext_req_callback(MMI_TRUE, g_vdorec_cntx.filepath);
                    g_vdorec_cntx.ext_req_callback = NULL;                    
                    GoBackHistory();
                    return;
                }
                else if (result == MDI_RES_VDOREC_ERR_DISK_FULL)
                {
                    mmi_vdorec_disply_popup(
                        (PU8) GetString(FMGR_FS_DISK_FULL_TEXT),
                        MMI_EVENT_FAILURE);
                    
                    /* delete all video recorder screen */
                    DeleteScreenIfPresent(SCR_ID_VDOREC_SAVING);
                    DeleteScreenIfPresent(SCR_ID_VDOREC_SAVE_CONFIRM);
                    DeleteScreenIfPresent(SCR_ID_VDOREC_APP);

                    g_vdorec_cntx.ext_req_callback(MMI_FALSE, NULL);
                    g_vdorec_cntx.ext_req_callback = NULL;                    
                    return;
                }
                else
                {    
                    mmi_vdorec_disply_popup(
                        (PU8) GetString(STR_GLOBAL_FAILED_TO_SAVE),
                        MMI_EVENT_FAILURE);

                    /* delete all video recorder screen */
                    DeleteScreenIfPresent(SCR_ID_VDOREC_SAVING);
                    DeleteScreenIfPresent(SCR_ID_VDOREC_SAVE_CONFIRM);
                    DeleteScreenIfPresent(SCR_ID_VDOREC_APP);
                    
                    g_vdorec_cntx.ext_req_callback(MMI_FALSE, NULL);
                    g_vdorec_cntx.ext_req_callback = NULL;                    
                    return;                    
                }
            }
            else
            {
                /* not in saving screen */
                
                if (result >= 0)
                {
                    /* delete all video recorder screen */
                    DeleteScreenIfPresent(SCR_ID_VDOREC_SAVING);
                    DeleteScreenIfPresent(SCR_ID_VDOREC_SAVE_CONFIRM);
                    DeleteScreenIfPresent(SCR_ID_VDOREC_APP);
                    
                    g_vdorec_cntx.ext_req_callback(MMI_TRUE, g_vdorec_cntx.filepath);
                    g_vdorec_cntx.ext_req_callback = NULL;                    
                    return;
                }
                else
                {
                    /* delete all video recorder screen */
                    DeleteScreenIfPresent(SCR_ID_VDOREC_SAVING);
                    DeleteScreenIfPresent(SCR_ID_VDOREC_SAVE_CONFIRM);
                    DeleteScreenIfPresent(SCR_ID_VDOREC_APP);
                    
                    g_vdorec_cntx.ext_req_callback(MMI_FALSE, NULL);
                    g_vdorec_cntx.ext_req_callback = NULL;                    
                    return;
                }
            }
        }
        else
        {
            DeleteScreenIfPresent(SCR_ID_VDOREC_SAVING);

            /* Alarm playing */
            if (AlmIsTonePlaying())
            {
                return;
            }

            /* is in call, they have higher priority, do not show popup */
            if (SCR_ID_VDOREC_SAVING == GetActiveScreenId())
            {
                /* enter only not in call and wap not in call */
                if (result >= 0)
                {
                    mmi_vdorec_disply_popup(
                        (PU8) GetString(STR_ID_VDOREC_NOTIFY_SAVED),
                        MMI_EVENT_SUCCESS);
                        
                #if defined(__VDOREC_FEATURE_PREVIEW_SAVED_FILE__) && defined(__MTK_TARGET__)
                    /* insert preview screen to Hisotry, so after popup, will return to preview screen */
                    /* don't care gui_buffer & input_buffer, since we won't handle it. */
                    GenericExitScreen(SCR_ID_VDOREC_PREVIEW_OPTION, mmi_vdorec_entry_preview_video_screen);
                #endif /* __VDOREC_FEATURE_PREVIEW_SAVED_FILE__ */
                }
                else if (result == MDI_RES_VDOREC_ERR_DISK_FULL)
                {
                    mmi_vdorec_disply_popup(
                        (PU8) GetString(FMGR_FS_DISK_FULL_TEXT),
                        MMI_EVENT_FAILURE);
                }
                else
                {
                    mmi_vdorec_disply_popup(
                        (PU8) GetString(STR_GLOBAL_FAILED_TO_SAVE),
                        MMI_EVENT_FAILURE);
                }

                DeleteScreenIfPresent(SCR_ID_VDOREC_SAVING);
                DeleteScreenIfPresent(SCR_ID_VDOREC_SAVE_CONFIRM);

                /* if clam is close, delete one more screen, avoid enter video recorder */
                if (IsClamClose())
                {
                    DeleteNHistory(1);
                #ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__
                    DeleteScreenIfPresent(SCR_ID_VDOREC_SAVED_PREVIEW);
                #endif 
                }
            }
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_exit_saving_screen
 * DESCRIPTION
 *  enter save screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_exit_saving_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_EXIT_SAVE_SCREEN);

    /* resume background play */
    mdi_audio_resume_background_play();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_saving_screen_del_hdlr
 * DESCRIPTION
 *  Del screen callback function
 * PARAMETERS
 *  dummy_ptr       [?]     
 * RETURNS
 *  U8
 *****************************************************************************/
static U8 mmi_vdorec_saving_screen_del_hdlr(void *dummy_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_SAVING_SCREEN_DEL_HDLR, g_vdorec_cntx.is_saving);

    if (g_vdorec_cntx.is_saving)
    {
        return TRUE;    /* if is saving, will not delete this screen from history */
    }
    else
    {
        return FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_saving_screen
 * DESCRIPTION
 *  enter save screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_entry_saving_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S8 buf_filepath[FMGR_PATH_BUFFER_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ENTRY_SAVING_SCREEN);

#if (defined(__MMI_VDOREC_MMS_SUPPORT__) || defined(__MMI_BT_SEND_SUPPORT__) || defined(__MMI_EMAIL__)) && !defined(__VDOREC_FEATURE_DIRECT_SAVE__)
    if (g_vdorec_cntx.is_save_done_when_mt && g_vdorec_cntx.is_foward_to)
    {
        /* save done while in MT, when back from MT, will enter here */
        g_vdorec_cntx.is_save_done_when_mt = FALSE;

        if (g_vdorec_cntx.save_result >= 0)
        {
            DeleteUptoScrID(SCR_ID_VDOREC_APP);
            mmi_vdorec_entry_send_screen();
            /*mms_content_insert_hdlr(g_vdorec_cntx.filepath);*/
            return;
        }
        else if (g_vdorec_cntx.save_result == MDI_RES_VDOREC_ERR_DISK_FULL)
        {
            mmi_vdorec_disply_popup(
                (PU8) GetString(FMGR_FS_DISK_FULL_TEXT),
                MMI_EVENT_FAILURE);
        }
        else
        {
            mmi_vdorec_disply_popup(
                (PU8) GetString(STR_GLOBAL_FAILED_TO_SAVE),
                MMI_EVENT_FAILURE);
        }

        /* if clam is close, delete one more screen, avoid enter video recorder */
        if (IsClamClose())
        {
            DeleteNHistory(1);
        }

        return;
    }
#endif /* __MMI_VDOREC_MMS_SUPPORT__ */ 

    g_vdorec_cntx.is_saving = TRUE;
    SetDelScrnIDCallbackHandler(SCR_ID_VDOREC_SAVING, mmi_vdorec_saving_screen_del_hdlr);

    /* suspend background play */
    mdi_audio_suspend_background_play();

    EntryNewScreen(SCR_ID_VDOREC_SAVING, mmi_vdorec_exit_saving_screen, mmi_vdorec_entry_saving_screen, NULL);

    /* rotate UI */
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
#endif 

    ShowCategory66Screen(
        CAT66_AREA_NONE,
        CAT66_AREA_NONE,
        0,
        0,
        0,
        0,
        (PU8) GetString(STR_ID_VDOREC_NOTIFY_SAVING),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_VDOREC_SAVING);

    if (guiBuffer == NULL)
    {
        g_vdorec_cntx.last_error = mdi_video_rec_save_file(g_vdorec_cntx.filepath, mmi_vdorec_save_result_hdlr_callback);

        if (mmi_vdorec_check_and_display_error_popup() == TRUE) /* TRUE means has error */
        {
            /* if has error, cant save, delete temp file */
            mdi_video_rec_delete_unsaved_file(buf_filepath);
            return;
        }
    }

    /* clear end key, this action cant be abort */
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
}

/*****************************************************************************
*
* Menu Screens
*
*****************************************************************************/


#ifdef __MMI_VIDEO_PLAYER__
/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_highlight_to_vdoply
 * DESCRIPTION
 *  hiligith to vdorec menuitem
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_highlight_to_vdoply(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_HILIGHT_TO_VDO_PLY);

    SetLeftSoftkeyFunction(mmi_vdoply_entry_app, KEY_EVENT_UP);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vdoply_entry_app, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
#endif /* __MMI_VIDEO_PLAYER__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_option_screen
 * DESCRIPTION
 *  entry option menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_entry_option_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[16];
    U16 ItemIcons[16] = 
    {
        IMG_GLOBAL_L1, 
        IMG_GLOBAL_L2,
        IMG_GLOBAL_L3,
        IMG_GLOBAL_L4,
        IMG_GLOBAL_L5,
        IMG_GLOBAL_L6,
        IMG_GLOBAL_L7,
        IMG_GLOBAL_L8,
        IMG_GLOBAL_L9,
        IMG_GLOBAL_L10,
        IMG_GLOBAL_L11,
        IMG_GLOBAL_L12,
        IMG_GLOBAL_L13,
        IMG_GLOBAL_L14,
        IMG_GLOBAL_L15,
        IMG_GLOBAL_L16
    };
    U16 nItems;
    U8 *guiBuffer;
    U8 *PopUpList[32];
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ENTRY_OPTION_SCREEN);

    EntryNewScreen(SCR_ID_VDOREC_OPTION, NULL, mmi_vdorec_entry_option_screen, NULL);

#ifdef __VDOREC_FEATURE_SWITCH_TO_CAMERA__
    if (g_vdorec_cntx.is_ext_req)
    {
        /* hide switch to cam */        
        mmi_frm_hide_menu_item(MENU_ID_VDOREC_TO_CAMERA);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_VDOREC_TO_CAMERA);
    }
#endif /* __VDOREC_FEATURE_SWITCH_TO_CAMERA__ */

#ifdef __VDOREC_FEATURE_STORAGE__
    if (MMI_PUBLIC_DRV == MMI_CARD_DRV)
    {
        mmi_frm_hide_menu_item(MENU_ID_VDOREC_STORAGE);
    }
#endif

    guiBuffer = GetCurrGuiBuffer(SCR_ID_VDOREC_OPTION);
    nItems = GetNumOfChild_Ext(MENU_ID_VDOREC_OPTION);
    GetSequenceStringIds_Ext(MENU_ID_VDOREC_OPTION, ItemList);
    SetParentHandler(MENU_ID_VDOREC_OPTION);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0; i < nItems; i++)
    {
        PopUpList[i] = NULL;
    }

    ConstructHintsList(MENU_ID_VDOREC_OPTION, PopUpList);

    /* rotate UI */
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
#endif 

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_VDOREC_APP),
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

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_highlight_camcoder_setting
 * DESCRIPTION
 *  highlight camecoder setting menuitem
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_highlight_camcoder_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_HILIGHT_CAMCORDER_SETTING);

    SetLeftSoftkeyFunction(mmi_vdorec_entry_camcoder_setting_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdorec_entry_camcoder_setting_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_camcoder_setting_lsk_press
 * DESCRIPTION
 *  camcoder setting lsk press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_camcoder_setting_lsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#define CAMCODER_SETTING_SELECTED_VALUE(a, A)                                            \
   {                                                                                        \
      g_vdorec_cntx.setting.##a = g_vdorec_menu_cntx.camcoder_setting_inline.##a##_selected;\
   }

#ifdef __VDOREC_FEATURE_WB__
    CAMCODER_SETTING_SELECTED_VALUE(wb, WB);
#endif 

#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT__
    CAMCODER_SETTING_SELECTED_VALUE(led_highlight, LED_HIGHLIGHT);
#endif 

#ifdef __VDOREC_FEATURE_EV__
    CAMCODER_SETTING_SELECTED_VALUE(ev, EV);
#endif 

#ifdef __VDOREC_FEATURE_NIGHT__
    CAMCODER_SETTING_SELECTED_VALUE(night, NIGHT);
#endif 

#ifdef __VDOREC_FEATURE_BANDING__
    CAMCODER_SETTING_SELECTED_VALUE(banding, BANDING);
#endif 

#ifdef __VDOREC_FEATURE_CALL_ACCEPT_OPTION__
    CAMCODER_SETTING_SELECTED_VALUE(accept_call,ACCEPT_CALL);
#endif

#ifdef __VDOREC_FEATURE_MERGE_MENU__

    /* merge "Video Setting" items into "CamCoder Setting" */
#ifdef __VDOREC_FEATURE_VIDEO_SIZE__
    CAMCODER_SETTING_SELECTED_VALUE(video_size, VIDEO_SIZE);
#endif 

#ifdef __VDOREC_FEATURE_VIDEO_QTY__
    CAMCODER_SETTING_SELECTED_VALUE(video_qty, VIDEO_QTY);
#endif 

#ifdef __VDOREC_FEATURE_SIZE_LIMIT__
    CAMCODER_SETTING_SELECTED_VALUE(size_limit, SIZE_LIMIT);
#endif 

#ifdef __VDOREC_FEATURE_TIME_LIMIT__
    CAMCODER_SETTING_SELECTED_VALUE(time_limit, TIME_LIMIT);
#endif 

#ifdef __VDOREC_FEATURE_RECORD_AUD__
    CAMCODER_SETTING_SELECTED_VALUE(record_aud, RECORD_AUD);
#endif 

#ifdef __VDOREC_FEATURE_VIDEO_FORMAT__
    CAMCODER_SETTING_SELECTED_VALUE(video_format, VIDEO_FORMAT);
#endif 

#ifdef __VDOREC_FEATURE_ZOOM__
    g_vdorec_cntx.setting.zoom = VDOREC_DEFAULT_SETTING_ZOOM;
#endif 

#endif /* __VDOREC_FEATURE_MERGE_MENU__ */ 

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_CAMCORDER_SETTING_LSK_PRESS);

    mmi_vdorec_store_setting();

    mmi_vdorec_disply_popup((PU8) GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS);
    DeleteNHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_camcoder_setting_highlight_hdlr
 * DESCRIPTION
 *  camcoder setting highlight handler
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_camcoder_setting_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_CAMCORDER_SETTING_HIGHLIGHT_HDLR);

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetCategory57LeftSoftkeyFunction(mmi_vdorec_camcoder_setting_lsk_press);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_exit_camcoder_setting_screen
 * DESCRIPTION
 *  exit camcoder setting screen (inline selection screen)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_exit_camcoder_setting_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 inputBufferSize;
    history h;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_EXIT_CAMCORDER_SETTING);

    CloseCategory57Screen();
    h.scrnID = SCR_ID_VDOREC_CAMCODER_SETTING;
    h.entryFuncPtr = mmi_vdorec_entry_camcoder_setting_screen;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57History(h.guiBuffer);
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_camcoder_setting_screen
 * DESCRIPTION
 *  entry camcoder setting screen (inline selection screen)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_entry_camcoder_setting_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
    S32 item_offset = 0;
    S32 i;
    MMI_ID_TYPE item_icons[VDOREC_CAMCODER_SETTING_ITEM_COUNT * 2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ENTRY_CAMCORDER_SETTING_SCREEN);

    for (i = 0 ; i < VDOREC_CAMCODER_SETTING_ITEM_COUNT; i++)
    {
        item_icons[2 * i] = IMG_GLOBAL_L1 + i;
        item_icons[2 * i + 1] = 0;
    }

    EntryNewScreen(SCR_ID_VDOREC_CAMCODER_SETTING, mmi_vdorec_exit_camcoder_setting_screen, NULL, NULL);

    InitializeCategory57Screen();

   /******************************************************************
   *  MACRO to create inline selection. 
   ******************************************************************/
#define CREATE_CAMCODER_SETTING_INLINE_SELECT(a, A)                                                                             \
   {                                                                                                                               \
      g_vdorec_menu_cntx.camcoder_setting_inline.##a##_selected = g_vdorec_cntx.setting.##a;                                       \
      for(i = 0 ; i < VDOREC_SETTING_##A##_COUNT; i++)                                                                             \
      {                                                                                                                            \
         g_vdorec_menu_cntx.camcoder_setting_inline.##a##_str[i] = (UI_string_type)GetString((U16)(STR_ID_VDOREC_##A##_START+i+1));\
      }                                                                                                                            \
      SetInlineItemCaption(&wgui_inline_items[item_offset++], (PU8)GetString((U16)(STR_ID_VDOREC_##A)));                           \
      SetInlineItemActivation(&wgui_inline_items[item_offset],                                                                     \
                              INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,                                                              \
                              0 );                                                                                                 \
      SetInlineItemSelect( &wgui_inline_items[item_offset++],                                                                      \
                           VDOREC_SETTING_##A##_COUNT,                                                                             \
                           (U8**)g_vdorec_menu_cntx.camcoder_setting_inline.##a##_str,                                             \
                           &g_vdorec_menu_cntx.camcoder_setting_inline.##a##_selected);                                            \
   }

   /****************************************************************************
   *  Create inline selection                                                               
   *****************************************************************************/
#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT__
    CREATE_CAMCODER_SETTING_INLINE_SELECT(led_highlight, LED_HIGHLIGHT);
#endif 

#ifdef __VDOREC_FEATURE_EV__
    CREATE_CAMCODER_SETTING_INLINE_SELECT(ev, EV);
#endif 

#ifdef __VDOREC_FEATURE_NIGHT__
    CREATE_CAMCODER_SETTING_INLINE_SELECT(night, NIGHT);
#endif 

#ifdef __VDOREC_FEATURE_BANDING__
    CREATE_CAMCODER_SETTING_INLINE_SELECT(banding, BANDING);
#endif 


#ifdef __VDOREC_FEATURE_CALL_ACCEPT_OPTION__
    CREATE_CAMCODER_SETTING_INLINE_SELECT(accept_call, ACCEPT_CALL);
#endif /* __VDOREC_FEATURE_CALL_ACCEPT_OPTION__ */


#ifdef __VDOREC_FEATURE_MERGE_MENU__

    /* merge "Video Setting" items into "CamCoder Setting" */
#ifdef __VDOREC_FEATURE_VIDEO_SIZE__
    CREATE_CAMCODER_SETTING_INLINE_SELECT(video_size, VIDEO_SIZE);
#endif 

#ifdef __VDOREC_FEATURE_VIDEO_QTY__
    #if defined(__VDOREC_FEATURE_QVGA_RECORD_SUPPORT__)
        CREATE_CAMCODER_SETTING_INLINE_SELECT(video_qty, VIDEO_QTY2);
    #else
        CREATE_CAMCODER_SETTING_INLINE_SELECT(video_qty, VIDEO_QTY);
    #endif 
#endif 

    if (!g_vdorec_cntx.is_ext_req)
    {
#ifdef __VDOREC_FEATURE_SIZE_LIMIT__
    CREATE_CAMCODER_SETTING_INLINE_SELECT(size_limit, SIZE_LIMIT);
#endif 

#ifdef __VDOREC_FEATURE_TIME_LIMIT__
    CREATE_CAMCODER_SETTING_INLINE_SELECT(time_limit, TIME_LIMIT);
#endif 
    }

#ifdef __VDOREC_FEATURE_RECORD_AUD__
    CREATE_CAMCODER_SETTING_INLINE_SELECT(record_aud, RECORD_AUD);
#endif 

#ifdef __VDOREC_FEATURE_VIDEO_FORMAT__
    CREATE_CAMCODER_SETTING_INLINE_SELECT(video_format, VIDEO_FORMAT);
#endif 

#endif /* __VDOREC_FEATURE_MERGE_MENU__ */ 

    guiBuffer = GetCurrGuiBuffer(SCR_ID_VDOREC_CAMCODER_SETTING);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_VDOREC_CAMCODER_SETTING, &inputBufferSize);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, VDOREC_CAMCODER_SETTING_ITEM_COUNT * 2, inputBuffer);
    }

    RegisterHighlightHandler(mmi_vdorec_camcoder_setting_highlight_hdlr);

    /* rotate UI */
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
#endif 

    /* show category */
    ShowCategory57Screen(
        STR_ID_VDOREC_CAMCODER_SETTING,
        GetRootTitleIcon(MENU_ID_VDOREC_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        item_offset,
        item_icons,
        wgui_inline_items,
        0,
        guiBuffer);

    /* set key hdlr */
    SetCategory57LeftSoftkeyFunction(mmi_vdorec_camcoder_setting_lsk_press);
    DisableCategory57ScreenDone();
    SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_highlight_video_setting
 * DESCRIPTION
 *  highlight video setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __VDOREC_FEATURE_MERGE_MENU__
void mmi_vdorec_highlight_video_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_HIGHLIGHT_VIDEO_SETTING);

    SetLeftSoftkeyFunction(mmi_vdorec_entry_video_setting_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdorec_entry_video_setting_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
}
#endif /* __VDOREC_FEATURE_MERGE_MENU__ */ 


void mmi_vdorec_hint_wb(U16 index)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_HINT_WB);

    memset((PS8) hintData[(index)], 0, sizeof(hintData[(index)]));
    mmi_ucs2cpy(
        (S8*) hintData[index],
        (S8*) GetString((U16) (STR_ID_VDOREC_WB_START + g_vdorec_cntx.setting.wb + 1)));
}


static void mmi_vdorec_set_wb_value(void)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_SET_WB_VALUE);

    mmi_vdorec_disply_popup((PU8) GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS);
    DeleteNHistory(1);
    g_vdorec_cntx.setting.wb = (U16) GetCurrHiliteID();
    mmi_vdorec_store_setting();
}


static void mmi_vdorec_entry_wb_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[32] = {0};
    U8 *guiBuffer;
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ENTRY_WB_SCREEN);

    EntryNewScreen(SCR_ID_VDOREC_VIDEO_WB, NULL, mmi_vdorec_entry_wb_screen, NULL);

#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
#endif
    
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VDOREC_VIDEO_WB);

    SetParentHandler(MENU_ID_VDOREC_WHITE_BALANCE);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0 ; i < VDOREC_SETTING_WB_COUNT; i++)
    {
        ItemList[i] = STR_ID_VDOREC_WB_START + i + 1;
    }

    ShowCategory11Screen(
        STR_ID_VDOREC_WB,
        GetRootTitleIcon(MENU_ID_VDOREC_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        VDOREC_SETTING_WB_COUNT,
        ItemList,
        g_vdorec_cntx.setting.wb,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_vdorec_set_wb_value, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


void mmi_vdorec_highlight_wb(void)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_HIGHLIGHT_WB);

    SetLeftSoftkeyFunction(mmi_vdorec_entry_wb_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdorec_entry_wb_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_video_setting_lsk_press
 * DESCRIPTION
 *  video setting lsk pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __VDOREC_FEATURE_MERGE_MENU__
static void mmi_vdorec_video_setting_lsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_VIDEO_SETTING_LSK_PRESS);

#define VIDEO_SETTING_SET_SELECTED_VALUE(a, A)                                        \
   {                                                                                     \
      g_vdorec_cntx.setting.##a = g_vdorec_menu_cntx.video_setting_inline.##a##_selected;\
   }

#ifdef __VDOREC_FEATURE_ZOOM__
    g_vdorec_cntx.setting.zoom = VDOREC_DEFAULT_SETTING_ZOOM;
#endif 

    VIDEO_SETTING_SET_SELECTED_VALUE(video_size, VIDEO_SIZE);
    VIDEO_SETTING_SET_SELECTED_VALUE(video_qty, VIDEO_QTY);
    VIDEO_SETTING_SET_SELECTED_VALUE(size_limit, SIZE_LIMIT);
    VIDEO_SETTING_SET_SELECTED_VALUE(time_limit, TIME_LIMIT);
    VIDEO_SETTING_SET_SELECTED_VALUE(record_aud, RECORD_AUD);
    VIDEO_SETTING_SET_SELECTED_VALUE(video_format, VIDEO_FORMAT);

    #if defined(__VDOREC_FEATURE_QVGA_RECORD_SUPPORT__)
    #ifdef __VDOREC_FEATURE_VIDEO_QTY_FINE__    
    if (g_vdorec_cntx.setting.video_qty == VDOREC_SETTING_VIDEO_QTY_FINE)
    {
        g_vdorec_cntx.setting.video_size = VDOREC_SETTING_VIDEO_SIZE_QVGA;
    }
    else
    {
        g_vdorec_cntx.setting.video_size = VDOREC_SETTING_VIDEO_SIZE_QCIF;
    }
    #endif /* __VDOREC_FEATURE_VIDEO_QTY_FINE__  */
    
    #if defined(__VDOREC_FEATURE_VIDEO_QTY_LOW__)
    if (g_vdorec_cntx.setting.video_qty == VDOREC_SETTING_VIDEO_QTY_LOW)
    {
        g_vdorec_cntx.setting.video_format = VDOREC_SETTING_VIDEO_FORMAT_3GP;
    }
    else
    {
        g_vdorec_cntx.setting.video_format = VDOREC_SETTING_VIDEO_FORMAT_MP4;
    }
    #endif /* __VDOREC_FEATURE_VIDEO_QTY_LOW__  */
    #endif /* defined(__VDOREC_FEATURE_QVGA_RECORD_SUPPORT__) */    

    mmi_vdorec_store_setting();

    mmi_vdorec_disply_popup((PU8) GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS);
    DeleteNHistory(1);
}
#endif /* __VDOREC_FEATURE_MERGE_MENU__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_video_setting_highlight_hdlr
 * DESCRIPTION
 *  video setting highlight hdlr
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __VDOREC_FEATURE_MERGE_MENU__
static void mmi_vdorec_video_setting_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_VIDEO_SETTING_HIGHLIGHT_HDLR);

    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetCategory57LeftSoftkeyFunction(mmi_vdorec_video_setting_lsk_press);
}
#endif /* __VDOREC_FEATURE_MERGE_MENU__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_exit_video_setting_screen
 * DESCRIPTION
 *  exit video setting screen (inline selection)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __VDOREC_FEATURE_MERGE_MENU__
static void mmi_vdorec_exit_video_setting_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 inputBufferSize;
    history h;
    S16 nHistory = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_EXIT_VIDEO_SETTING_SCREEN);

    CloseCategory57Screen();
    h.scrnID = SCR_ID_VDOREC_VIDEO_SETTING;
    h.entryFuncPtr = mmi_vdorec_entry_video_setting_screen;
    mmi_ucs2cpy((S8*) h.inputBuffer, (S8*) & nHistory);
    inputBufferSize = (U16) GetCategory57DataSize();
    GetCategory57History(h.guiBuffer);
    GetCategory57Data((U8*) h.inputBuffer);
    AddNHistory(h, inputBufferSize);
}
#endif /* __VDOREC_FEATURE_MERGE_MENU__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_video_setting_screen
 * DESCRIPTION
 *  entry video setting screen (inline selection)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __VDOREC_FEATURE_MERGE_MENU__
static void mmi_vdorec_entry_video_setting_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
    S32 item_offset = 0;
    S32 i;
    MMI_ID_TYPE item_icons[VDOREC_VIDEO_SETTING_ITEM_COUNT * 2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ENTRY_VIDEO_SETTING_SCREEN);

    for (i = 0 ; i < VDOREC_VIDEO_SETTING_ITEM_COUNT; i++)
    {
        item_icons[2 * i] = IMG_GLOBAL_L1 + i;
        item_icons[2 * i + 1] = 0;
    }

    EntryNewScreen(SCR_ID_VDOREC_VIDEO_SETTING, mmi_vdorec_exit_video_setting_screen, NULL, NULL);

    InitializeCategory57Screen();

   /******************************************************************
   *  MACRO to create inline selection. 
   ******************************************************************/
#define CREATE_VIDEO_SETTING_INLINE_SELECT(a, A)                                                                             \
   {                                                                                                                            \
      g_vdorec_menu_cntx.video_setting_inline.##a##_selected = g_vdorec_cntx.setting.##a;                                       \
      for(i = 0 ; i < VDOREC_SETTING_##A##_COUNT; i++)                                                                          \
      {                                                                                                                         \
         g_vdorec_menu_cntx.video_setting_inline.##a##_str[i] = (UI_string_type)GetString((U16)(STR_ID_VDOREC_##A##_START+1+i));\
      }                                                                                                                         \
      SetInlineItemCaption(&wgui_inline_items[item_offset++], (PU8)GetString((U16)(STR_ID_VDOREC_##A)));                        \
      SetInlineItemActivation(&wgui_inline_items[item_offset],                                                                  \
                              INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,                                                           \
                              0 );                                                                                              \
      SetInlineItemSelect( &wgui_inline_items[item_offset++],                                                                   \
                           VDOREC_SETTING_##A##_COUNT,                                                                          \
                           (U8**)g_vdorec_menu_cntx.video_setting_inline.##a##_str,                                             \
                           &g_vdorec_menu_cntx.video_setting_inline.##a##_selected);                                            \
   }

   /****************************************************************************
   *  Create inline selection                                                               
   *****************************************************************************/
#ifdef __VDOREC_FEATURE_VIDEO_SIZE__
    CREATE_VIDEO_SETTING_INLINE_SELECT(video_size, VIDEO_SIZE);
#endif 

#ifdef __VDOREC_FEATURE_VIDEO_QTY__
   #if defined(__VDOREC_FEATURE_QVGA_RECORD_SUPPORT__)
        CREATE_VIDEO_SETTING_INLINE_SELECT(video_qty, VIDEO_QTY2);
    #else
        CREATE_VIDEO_SETTING_INLINE_SELECT(video_qty, VIDEO_QTY);
    #endif 
#endif 

   if(!g_vdorec_cntx.is_ext_req)
   {
    /* always use external limit when entry from external request */
    #ifdef __VDOREC_FEATURE_SIZE_LIMIT__
        CREATE_VIDEO_SETTING_INLINE_SELECT(size_limit, SIZE_LIMIT);
    #endif 

    #ifdef __VDOREC_FEATURE_TIME_LIMIT__
        CREATE_VIDEO_SETTING_INLINE_SELECT(time_limit, TIME_LIMIT);
    #endif 
   }

#ifdef __VDOREC_FEATURE_RECORD_AUD__
    CREATE_VIDEO_SETTING_INLINE_SELECT(record_aud, RECORD_AUD);
#endif 

    /*if qvga record support, will not display format, format is related with video quality*/
#if !defined(__VDOREC_FEATURE_QVGA_RECORD_SUPPORT__)
#ifdef __VDOREC_FEATURE_VIDEO_FORMAT__
    CREATE_VIDEO_SETTING_INLINE_SELECT(video_format, VIDEO_FORMAT);
#endif 
#endif

    guiBuffer = GetCurrGuiBuffer(SCR_ID_VDOREC_VIDEO_SETTING);
    inputBuffer = GetCurrNInputBuffer(SCR_ID_VDOREC_VIDEO_SETTING, &inputBufferSize);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, VDOREC_VIDEO_SETTING_ITEM_COUNT * 2, inputBuffer);
    }

    RegisterHighlightHandler(mmi_vdorec_video_setting_highlight_hdlr);

    /* rotate UI */
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
#endif 

    /* show category */
    ShowCategory57Screen(
        STR_ID_VDOREC_VIDEO_SETTING,
        GetRootTitleIcon(MENU_ID_VDOREC_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        item_offset,
        item_icons,
        wgui_inline_items,
        0,
        guiBuffer);

    /* set key hdlr */
    SetCategory57LeftSoftkeyFunction(mmi_vdorec_video_setting_lsk_press);
    DisableCategory57ScreenDone();
    SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);

}
#endif /* __VDOREC_FEATURE_MERGE_MENU__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_hint_effect_setting
 * DESCRIPTION
 *  hint effect setting
 * PARAMETERS
 *  index       [IN]        
 *  a(?)        [IN]        Hilight index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_hint_effect_setting(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_HINT_EFFECT_SETTING);

    memset((PS8) hintData[(index)], 0, sizeof(hintData[(index)]));
    mmi_ucs2cpy(
        (S8*) hintData[index],
        (S8*) GetString((U16) (STR_ID_VDOREC_EFFECT_START + g_vdorec_cntx.setting.effect + 1)));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_highlight_effect_setting
 * DESCRIPTION
 *  highlight effect setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_highlight_effect_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_HIGHLIGHT_EFFECT_SETTING);

    SetLeftSoftkeyFunction(mmi_vdorec_entry_effect_setting_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdorec_entry_effect_setting_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_set_effect_setting_value
 * DESCRIPTION
 *  effect setting set value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_set_effect_setting_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_SET_EFFECT_SETTING_VALUE);

    mmi_vdorec_disply_popup((PU8) GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS);
    DeleteNHistory(1);
    g_vdorec_cntx.setting.effect = (U16) GetCurrHiliteID();
    mmi_vdorec_store_setting();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_effect_setting_screen
 * DESCRIPTION
 *  entry effect setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_entry_effect_setting_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[16];
    U16 nItems;
    U8 *gui_buffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ENTRY_EFFECT_SETTING_SCREEN);

    EntryNewScreen(SCR_ID_VDOREC_EFFECT_SETTING, NULL, mmi_vdorec_entry_effect_setting_screen, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_VDOREC_EFFECT_SETTING);

    nItems = GetNumOfChild(MENU_ID_VDOREC_EFFECT_SETTING);
    GetSequenceStringIds(MENU_ID_VDOREC_EFFECT_SETTING, ItemList);
    SetParentHandler(MENU_ID_VDOREC_EFFECT_SETTING);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* rotate UI */
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
#endif 

    ShowCategory11Screen(
        STR_ID_VDOREC_EFFECT_SETTING,
        GetRootTitleIcon(MENU_ID_VDOREC_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        g_vdorec_cntx.setting.effect,   /* current index */
        gui_buffer);

    SetLeftSoftkeyFunction(mmi_vdorec_set_effect_setting_value, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_hint_storage
 * DESCRIPTION
 *  hint storage
 * PARAMETERS
 *  index       [IN]        
 *  a(?)        [IN]        Hilight index
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOREC_FEATURE_STORAGE__
void mmi_vdorec_hint_storage(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_HINT_STORAGE);

    memset((PS8) hintData[(index)], 0, sizeof(hintData[(index)]));
    if (FS_NO_ERROR != FS_GetDevStatus(mmi_vdoply_get_storage() ,FS_MOUNT_STATE_ENUM))
    {
        mmi_vdoply_set_storage((U16) MMI_PUBLIC_DRV);
    }
    
    mmi_fmgr_get_drive_name(
        (S8)mmi_vdoply_get_storage(), 
        (S8*)&hintData[index], 
        (U8)((FMGR_MAX_DRIVE_NAME_LEN + 1 ) * ENCODING_LENGTH));
}
#endif /* __VDOREC_FEATURE_STORAGE__ */ 



#ifdef __VDOREC_FEATURE_STORAGE__
/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_set_storage_screen
 * DESCRIPTION
 *  entry storage setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_storage_highlight_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_STORAGE_HIGHLIGHT_HANDLER, index);

    g_vdorec_menu_cntx.cur_idx = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_set_storage_screen
 * DESCRIPTION
 *  entry storage setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_entry_set_storage_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filepath[FMGR_PATH_BUFFER_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ENTRY_SET_STORAGE_SCREEN);

    /* check current storage have unsaved file or not */
    mmi_vdoply_get_storage_file_path(buf_filepath);

    if (mdi_video_rec_has_unsaved_file(buf_filepath))
    {
        mmi_vdorec_disply_popup(
            (PU8) GetString(STR_ID_VDOREC_NOTIFY_PLZ_SAVE_FIRST),
            MMI_EVENT_INFO);
    }
    else
    {
        /* change storage for Option -> Storage */        
        g_vdorec_cntx.is_option_storage = TRUE;        
        mmi_vdorec_entry_set_storage_screen_internal();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_app_storage_screen
 * DESCRIPTION
 *  entry app storage setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_entry_set_app_storage_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ENTRY_SET_APP_STORAGE_SCREEN);

    /* change storage for App -> Storage */
    /* this is used when enter app, the storage is not exist or folder cant be created */
    g_vdorec_cntx.is_option_storage = FALSE;    
    mmi_vdorec_entry_set_storage_screen_internal();
    
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_set_storage_screen_internal
 * DESCRIPTION
 *  entry storage setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_entry_set_storage_screen_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 total_num;
    U8 highlighted;
    U32 *inline_list_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VDOREC_STORAGE, NULL, mmi_vdorec_entry_set_storage_screen_internal, NULL);

    mmi_fmgr_get_exist_storage_inline_list(
        (S8)mmi_vdoply_get_storage(), 
        &total_num, 
        (PU32)&inline_list_p, 
        &highlighted);

#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)   
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
#endif

    RegisterHighlightHandler(mmi_vdorec_storage_highlight_handler);

    ShowCategory36Screen(
        STR_GLOBAL_STORAGE,
        GetRootTitleIcon(MENU_ID_VDOREC_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        total_num,
        (PU8*)inline_list_p,
        highlighted,   /* current index */
        NULL);

    SetLeftSoftkeyFunction(mmi_vdorec_set_storage_lsk_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_vdorec_set_storage_rsk_hdlr, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdorec_set_storage_rsk_hdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vdorec_set_storage_lsk_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ENTRY_SET_STORAGE_SCREEN_INTERNAL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_set_storage_lsk_hdlr
 * DESCRIPTION
 *  set storage
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_set_storage_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf[64];
    S8 buf_filepath[FMGR_PATH_BUFFER_SIZE];
    S32 create_result;
    S8 drv_letter;
    U16 prev_storage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_SET_STORAGE_LSK_HDLR);

    mmi_fmgr_get_drive_letter_by_inline_index((U8)g_vdorec_menu_cntx.cur_idx, &drv_letter);

    prev_storage = mmi_vdoply_get_storage();
    mmi_vdoply_set_storage(drv_letter);

    sprintf(buf, "%c:\\", (U8)drv_letter);
    mmi_asc_to_ucs2(buf_filepath, buf);

    /* check if photo path exist or not */
    mmi_vdoply_get_storage_file_path(buf_filepath);
    create_result = mmi_vdoply_create_file_dir(buf_filepath);

    if (create_result != FS_NO_ERROR)
    {
        if (create_result == FS_WRITE_PROTECTION)
        {
            mmi_vdorec_disply_popup(
                (PU8) GetString(FMGR_FS_WRITE_PROTECTION_TEXT),
                MMI_EVENT_FAILURE);

            /* restore prev storage setting */            
            mmi_vdoply_set_storage((U16)prev_storage);

            /* after popup, will re-enter storage screen */              
            return;     
        }
        else if (create_result == FS_DISK_FULL)
        {
            mmi_vdorec_disply_popup(
                (PU8) GetString(FMGR_FS_DISK_FULL_TEXT),
                MMI_EVENT_FAILURE);


            /* restore prev storage setting */                  
            mmi_vdoply_set_storage((U16)prev_storage);

            /* after popup, will re-enter storage screen */              
            return;     
        }
        else if (create_result == FS_ROOT_DIR_FULL)
        {
            mmi_vdorec_disply_popup(
                (PU8) GetString(FMGR_FS_ROOT_DIR_FULL_TEXT),
                MMI_EVENT_FAILURE);


            /* restore prev storage setting */      
            mmi_vdoply_set_storage((U16)prev_storage);

            /* after popup, will re-enter storage screen */              
            return;        
        }
        else
        {
            /* other file system error */
            mmi_vdorec_disply_popup(
                (PU8) GetString(STR_ID_VDOREC_NOTIFY_STORAGE_NOT_READY),
                MMI_EVENT_FAILURE);


            /* restore prev storage setting */      
            mmi_vdoply_set_storage((U16)prev_storage);

            /* after popup, will re-enter storage screen */              
            return;                    
        }
    }
    else
    {
        /* folder created */
        mmi_vdorec_disply_popup(
            (PU8) GetString(STR_GLOBAL_DONE),
            MMI_EVENT_SUCCESS);

        mmi_vdoply_store_setting();
        
        if (g_vdorec_cntx.is_option_storage)
        {
            /* user press RSK in drv selection screen */
            DeleteUptoScrID(SCR_ID_VDOREC_OPTION);
        }
        else
        {
            /* enter video recorder app */
            DeleteUptoScrID(SCR_ID_VDOREC_APP);
        }
        return;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_set_storage_rsk_hdlr
 * DESCRIPTION
 *  set storage
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_set_storage_rsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_SET_STORAGE_RSK_HDLR);

    if (g_vdorec_cntx.is_option_storage)
    {
        /* option -> storage */
        GoBackHistory();
    }
    else
    {   
        /* app -> storage */
        /* exit video recorder app */
        DeleteUptoScrID(SCR_ID_VDOREC_APP);
        DeleteNHistory(1);
        GoBackHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_highlight_storage
 * DESCRIPTION
 *  highlight storage
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_highlight_storage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_HILIGHT_STORAGE);

    SetLeftSoftkeyFunction(mmi_vdorec_entry_set_storage_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdorec_entry_set_storage_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
}
#endif /* __VDOREC_FEATURE_STORAGE__ */ 



/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_highlight_restore_default
 * DESCRIPTION
 *  highlight restore default
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_highlight_restore_default(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_HIGHLIGHT_RESTORE_DEFAULT);

    SetLeftSoftkeyFunction(mmi_vdorec_entry_restore_default_confirm_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdorec_entry_restore_default_confirm_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_restore_default_confirm_yes
 * DESCRIPTION
 *  restore default confirm yes.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_entry_restore_default_confirm_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ENTRY_RESTORE_DEFAULT_CONFIRM_YES);

    /* restore default values */
    mmi_vdorec_restore_setting();
    
    /* restore storage vdoply part - storage */
    mmi_vdoply_set_storage((U16)MMI_PUBLIC_DRV);
    mmi_vdoply_store_setting();

    mmi_vdorec_disply_popup((PU8) GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS);
    DeleteNHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_restore_default_confirm_screen
 * DESCRIPTION
 *  entry restore default confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_entry_restore_default_confirm_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filepath[FMGR_PATH_BUFFER_SIZE];
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ENTRY_RESTORE_DEFAULT_CONFIRM_SCREEN);

    /* check current storage have unsaved file or not */
    mmi_vdoply_get_storage_file_path(buf_filepath);
	if (mdi_video_rec_has_unsaved_file(buf_filepath))
    {
        mmi_vdorec_disply_popup(
            (PU8) GetString(STR_ID_VDOREC_NOTIFY_PLZ_SAVE_FIRST),
            MMI_EVENT_INFO);
		return;
    }

#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)

    mmi_display_popup_confirm_rotated(
        get_string(STR_GLOBAL_YES),
        get_image(IMG_GLOBAL_YES),
        get_string(STR_GLOBAL_NO),
        get_image(IMG_GLOBAL_NO),
        (UI_string_type)get_string(STR_ID_VDOREC_NOTIFY_RESTORE_DEFAULT_CONFIRM),
        MMI_EVENT_QUERY,
        MMI_FRM_SCREEN_ROTATE_270);

#else /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__) */ 

    mmi_display_popup_confirm(
        get_string(STR_GLOBAL_YES),
        get_image(IMG_GLOBAL_YES),
        get_string(STR_GLOBAL_NO),
        get_image(IMG_GLOBAL_NO),
        (UI_string_type)get_string(STR_ID_VDOREC_NOTIFY_RESTORE_DEFAULT_CONFIRM),
        MMI_EVENT_QUERY);

#endif /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__) */ 

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_vdorec_entry_restore_default_confirm_yes, KEY_EVENT_UP);
}

/*****************************************************************************
*
*  Touch Screen Support
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_touch_scr_pen_down_hdlr
 * DESCRIPTION
 *  touch screen hdlr when pen down
 * PARAMETERS
 *  pos     [IN]        Pen down position
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__VDOREC_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_vdorec_touch_scr_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__)
    S32 tmp_x;
    S32 tmp_y;
#endif /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_TOUCH_SCR_PEN_DOWN_HDLR);

    if (g_vdorec_cntx.is_watchdog_support)
    {
        mmi_vdorec_reset_watchdog_time_out_handler();
    }

#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__)

    /* cord tranfrom, since already rotate */
    tmp_x = pos.x;
    tmp_y = pos.y;
    pos.x = tmp_y;
    pos.y = (UI_device_width - 1) - tmp_x;

#endif /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) */ 

#ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__
    if (g_vdorec_cntx.state == VDOREC_STATE_VIDEO_PREVIEW_PLAY ||
         g_vdorec_cntx.state == VDOREC_STATE_VIDEO_PREVIEW_STOP)
    {
        /* cancel idle timer */
        mmi_vdorec_preview_idle_timeout_cancel(NULL);
        
        if (mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_del))
        {
            g_vdorec_cntx.touch_del.is_press = TRUE;
            mmi_vdorec_del_key_press_hdlr();
            g_vdorec_cntx.touch_object = VDOREC_TOUCH_DEL;
            return;
        }
        /* bypass EV/Zoom in video preview mode */
    #ifdef __VDOREC_FEATURE_EV__ 
        if (mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_ev_inc) ||
            mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_ev_dec))
        {
            return;
        }
    #endif /* __VDOREC_FEATURE_EV__ */
    #ifdef __VDOREC_FEATURE_ZOOM__
        if (mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_zoom_inc) ||
            mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_zoom_dec))
        {
            return;
        }
    #endif /* __VDOREC_FEATURE_ZOOM__ */
    }
#endif /* __VDOREC_FEATURE_PREVIEW_SAVED_FILE__ */


#ifdef __VDOREC_FEATURE_EV__ 
    /* ev inc */
    if (mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_ev_inc))
    {
        if (g_vdorec_cntx.setting.ev >= VDOREC_SETTING_EV_COUNT - 1)
        {
            return;
        }

        g_vdorec_cntx.touch_ev_inc.is_press = TRUE;
        g_vdorec_cntx.is_first_time_ev = TRUE;
        mmi_vdorec_inc_ev();

        g_vdorec_cntx.touch_object = VDOREC_TOUCH_EV_INC;
        return;
    }

    /* ev dec */
    if (mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_ev_dec))
    {
        if (g_vdorec_cntx.setting.ev == 0)
        {
            return;
        }

        g_vdorec_cntx.touch_ev_dec.is_press = TRUE;
        g_vdorec_cntx.is_first_time_ev = TRUE;
        mmi_vdorec_dec_ev();

        g_vdorec_cntx.touch_object = VDOREC_TOUCH_EV_DEC;
        return;
    }
#endif /* __VDOREC_FEATURE_EV__ */   


#ifdef __VDOREC_FEATURE_ZOOM__  
    /* zoom inc */
    if (mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_zoom_inc))
    {
        g_vdorec_cntx.touch_zoom_inc.is_press = TRUE;
        g_vdorec_cntx.is_first_time_zoom = TRUE;
        mmi_vdorec_zoom_in();
        g_vdorec_cntx.touch_object = VDOREC_TOUCH_ZOOM_INC;
        return;
    }

    /* zoom dec */
    if (mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_zoom_dec))
    {
        g_vdorec_cntx.touch_zoom_dec.is_press = TRUE;

        mmi_vdorec_zoom_out();
        g_vdorec_cntx.is_first_time_zoom = TRUE;
        g_vdorec_cntx.touch_object = VDOREC_TOUCH_ZOOM_DEC;
        return;
    }
#endif /* __VDOREC_FEATURE_ZOOM__ */

    /* rsk */
    if (mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_rsk))
    {
        mmi_vdorec_rsk_press_hdlr();
        g_vdorec_cntx.touch_object = VDOREC_TOUCH_RSK;
        return;
    }

    /* lsk */
    if (mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_lsk))
    {
        mmi_vdorec_lsk_press_hdlr();
        g_vdorec_cntx.touch_object = VDOREC_TOUCH_LSK;
        return;
    }

    /* ck */
    if (mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_ck))
    {
        mmi_vdorec_ck_press_hdlr();
        g_vdorec_cntx.touch_object = VDOREC_TOUCH_CK;
        return;
    }

#ifdef __VDOREC_FEATURE_VIDEO_SIZE__
    /* video size*/
    if (mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_video_size))
    {
        mmi_vdorec_video_size_hotkey_press();
        g_vdorec_cntx.touch_object = VDOREC_TOUCH_VIDEO_SIZE;
        return;
    }
#endif
    
#ifdef __VDOREC_FEATURE_VIDEO_QTY__
    /* video quality*/
    if (mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_video_qty))
    {
        mmi_vdorec_video_qty_hotkey_press();
        g_vdorec_cntx.touch_object = VDOREC_TOUCH_VIDEO_QTY;
        return;
    }
#endif
    
#ifdef __VDOREC_FEATURE_NIGHT__
    if (mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_night))
    {
        mmi_vdorec_night_hotkey_press();
        g_vdorec_cntx.touch_object = VDOREC_TOUCH_NIGHT;
        return;
    }
#endif 
    
#ifdef __VDOREC_FEATURE_WB__
    if (mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_wb))
    {
        mmi_vdorec_wb_hotkey_press();
        g_vdorec_cntx.touch_object = VDOREC_TOUCH_WB;
        return;
    }
#endif
    
#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT__
    if (mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_led_highlight))
    {
        mmi_vdorec_led_highlight_hotkey_press();
        g_vdorec_cntx.touch_object = VDOREC_TOUCH_LED_HIGHLIGHT;
        return;
    }
#endif 
    
#ifdef __VDOREC_FEATURE_RECORD_AUD__
    if (mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_record_aud))
    {
        mmi_vdorec_record_aud_hotkey_press();
        g_vdorec_cntx.touch_object = VDOREC_TOUCH_RECORD_AUDIO;
        return;
    }
#endif 
    
#ifdef __VDOREC_FEATURE_SIZE_LIMIT__
    if (mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_size_limit))
    {
        g_vdorec_cntx.touch_object = VDOREC_TOUCH_CK;
        return;
    }
#endif 
    
#ifdef __VDOREC_FEATURE_TIME_LIMIT__
    if (mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_time_limit))
    {
        g_vdorec_cntx.touch_object = VDOREC_TOUCH_CK;
        return;
    }
#endif 

}
#endif /* defined(__VDOREC_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__) */ /* __VDOREC_FEATURE_TOUCH_SCREEN__ & __MMI_TOUCH_SCREEN__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_touch_scr_pen_up_hdlr
 * DESCRIPTION
 *  touch screen hdlr when pen up
 * PARAMETERS
 *  pos     [IN]        Pen up position
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__VDOREC_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_vdorec_touch_scr_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_TOUCH_PEN_UP_HDLR);

    if (g_vdorec_cntx.is_watchdog_support)
    {
        mmi_vdorec_reset_watchdog_time_out_handler();
        mmi_vdorec_watchdog_time_out_handler();
    }

    if (g_vdorec_cntx.touch_object == VDOREC_TOUCH_NONE)
    {
        return;
    }

    switch (g_vdorec_cntx.touch_object)
    {
        case VDOREC_TOUCH_EV_INC:
        #ifdef __VDOREC_FEATURE_EV__            
            g_vdorec_cntx.touch_ev_inc.is_press = FALSE;
            g_vdorec_cntx.is_ev_inc_key_pressed = FALSE;

            gui_cancel_timer(mmi_vdorec_inc_ev);

            mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_EV);
            mmi_vdorec_blt_screen();
        #endif /* __VDOREC_FEATURE_EV__ */
            g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            break;

        case VDOREC_TOUCH_EV_DEC:
        #ifdef __VDOREC_FEATURE_EV__              
            g_vdorec_cntx.touch_ev_dec.is_press = FALSE;
            g_vdorec_cntx.is_ev_dec_key_pressed = FALSE;

            gui_cancel_timer(mmi_vdorec_dec_ev);

            mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_EV);
            mmi_vdorec_blt_screen();
        #endif /* __VDOREC_FEATURE_EV__ */            
            g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            break;

        case VDOREC_TOUCH_ZOOM_INC:
        #ifdef __VDOREC_FEATURE_ZOOM__            
            g_vdorec_cntx.touch_zoom_inc.is_press = FALSE;
            g_vdorec_cntx.is_zoom_in_key_pressed = FALSE;

            mmi_vdorec_stop_fast_zoom();
            gui_cancel_timer(mmi_vdorec_draw_zoom_osd);
            gui_cancel_timer(mmi_vdorec_start_fast_zoom_in);
        
            gui_cancel_timer(mmi_vdorec_zoom_in);
            mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_ZOOM);
            mmi_vdorec_blt_screen();
        #endif /* __VDOREC_FEATURE_ZOOM__ */
            g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            break;

        case VDOREC_TOUCH_ZOOM_DEC:
        #ifdef __VDOREC_FEATURE_ZOOM__                    
            g_vdorec_cntx.touch_zoom_dec.is_press = FALSE;
            g_vdorec_cntx.is_zoom_out_key_pressed = FALSE;

            mmi_vdorec_stop_fast_zoom();
            gui_cancel_timer(mmi_vdorec_draw_zoom_osd);
            gui_cancel_timer(mmi_vdorec_start_fast_zoom_out);
        
            gui_cancel_timer(mmi_vdorec_zoom_out);
            mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_ZOOM);
            mmi_vdorec_blt_screen();
        #endif /* __VDOREC_FEATURE_ZOOM__ */        
            g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            break;

        case VDOREC_TOUCH_RSK:
            mmi_vdorec_rsk_release_hdlr();
            g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            break;

        case VDOREC_TOUCH_LSK:
            mmi_vdorec_lsk_release_hdlr();
            g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            break;

        case VDOREC_TOUCH_CK:
            mmi_vdorec_ck_release_hdlr();
            g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            break;
            
    #ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__
        case VDOREC_TOUCH_DEL:
            g_vdorec_cntx.touch_del.is_press = FALSE;
            mmi_vdorec_del_key_release_hdlr();
            g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            break;
    #endif /* __VDOREC_FEATURE_PREVIEW_SAVED_FILE__ */
    }

}
#endif /* defined(__VDOREC_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__) */ /* __VDOREC_FEATURE_TOUCH_SCREEN__ & __MMI_TOUCH_SCREEN__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_touch_scr_pen_move_hdlr
 * DESCRIPTION
 *  touch screen hdlr when pen move
 * PARAMETERS
 *  pos     [IN]        Pen move position
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__VDOREC_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_vdorec_touch_scr_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__)
    S32 tmp_x;
    S32 tmp_y;
#endif /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_TOUCH_SCR_PEN_MOVE);

    if (g_vdorec_cntx.touch_object == VDOREC_TOUCH_NONE)
    {
        return;
    }

#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__)

    /* cord tranfrom, since already rotate */
    tmp_x = pos.x;
    tmp_y = pos.y;
    pos.x = tmp_y;
    pos.y = (UI_device_width - 1) - tmp_x;

#endif /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) */ 

    switch (g_vdorec_cntx.touch_object)
    {
        case VDOREC_TOUCH_EV_INC:
        #ifdef __VDOREC_FEATURE_EV__             
            if (!mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_ev_inc))
            {
                /* if move out */
                g_vdorec_cntx.touch_ev_inc.is_press = FALSE;
                g_vdorec_cntx.is_ev_inc_key_pressed = FALSE;

                gui_cancel_timer(mmi_vdorec_inc_ev);

                mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_EV);
                mmi_vdorec_blt_screen();

                g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            }
        #endif /* __VDOREC_FEATURE_EV__ */                 
            break;

        case VDOREC_TOUCH_EV_DEC:
        #ifdef __VDOREC_FEATURE_EV__             
            if (!mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_ev_dec))
            {
                /* if move out */
                g_vdorec_cntx.touch_ev_dec.is_press = FALSE;
                g_vdorec_cntx.is_ev_dec_key_pressed = FALSE;

                gui_cancel_timer(mmi_vdorec_dec_ev);

                mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_EV);
                mmi_vdorec_blt_screen();

                g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            }
        #endif /* __VDOREC_FEATURE_EV__ */                 
            break;

        case VDOREC_TOUCH_ZOOM_INC:
        #ifdef __VDOREC_FEATURE_ZOOM__            
            if (!mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_zoom_inc))
            {
                /* if move out */
                g_vdorec_cntx.touch_zoom_inc.is_press = FALSE;
                g_vdorec_cntx.is_zoom_in_key_pressed = FALSE;

                if (g_vdorec_cntx.is_fast_zoom_support)
                {
                    mmi_vdorec_stop_fast_zoom();
                    gui_cancel_timer(mmi_vdorec_draw_zoom_osd);
                    gui_cancel_timer(mmi_vdorec_start_fast_zoom_in);
                }

                gui_cancel_timer(mmi_vdorec_zoom_in);
                
                mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_ZOOM);
                mmi_vdorec_blt_screen();

                g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            }
        #endif /* __VDOREC_FEATURE_ZOOM__ */      
            break;

        case VDOREC_TOUCH_ZOOM_DEC:
        #ifdef __VDOREC_FEATURE_ZOOM__            
            if (!mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_zoom_dec))
            {
                /* if move out */
                g_vdorec_cntx.touch_zoom_dec.is_press = FALSE;
                g_vdorec_cntx.is_zoom_out_key_pressed = FALSE;

                if (g_vdorec_cntx.is_fast_zoom_support)
                {
                    mmi_vdorec_stop_fast_zoom();
                    gui_cancel_timer(mmi_vdorec_draw_zoom_osd);
                    gui_cancel_timer(mmi_vdorec_start_fast_zoom_out);
                }
                
                gui_cancel_timer(mmi_vdorec_zoom_out);
                
                mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_ZOOM);
                mmi_vdorec_blt_screen();

                g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            }
        #endif /* __VDOREC_FEATURE_ZOOM__ */                  
            break;

        case VDOREC_TOUCH_RSK:
            if (!mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_rsk))
            {
                /* if move out */
                g_vdorec_cntx.is_rsk_pressed = FALSE;

                mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY);
                mmi_vdorec_blt_screen();

                g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            }
            break;

        case VDOREC_TOUCH_LSK:
            if (!mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_lsk))
            {
                /* if move out */
                g_vdorec_cntx.is_lsk_pressed = FALSE;

                mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY);
                mmi_vdorec_blt_screen();

                g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            }
            break;

        case VDOREC_TOUCH_CK:
            if (!mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_ck))
            {
                /* if move out */
                g_vdorec_cntx.is_ck_pressed = FALSE;

                mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY);
                mmi_vdorec_blt_screen();

                g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            }
            break;

        #ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__
            case VDOREC_TOUCH_DEL:
            if (!mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_del))
            {
                /* if move out */
                g_vdorec_cntx.touch_del.is_press= FALSE;
                g_vdorec_cntx.is_del_key_pressed = FALSE;

                mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY);
                mmi_vdorec_blt_screen();

                g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            }
            break;
        #endif /* __VDOREC_FEATURE_PREVIEW_SAVED_FILE__ */

    }

}
#endif /* defined(__VDOREC_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__) */ /* __VDOREC_FEATURE_TOUCH_SCREEN__ & __MMI_TOUCH_SCREEN__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_touch_scr_hit_test
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
#if defined(__VDOREC_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__)
static BOOL mmi_vdorec_touch_scr_hit_test(S32 pos_x, S32 pos_y, vdorec_ui_touch_struct *touch_obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_TOUCH_SCR_HIT_TEST);

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
#endif /* defined(__VDOREC_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__) */ /* __VDOREC_FEATURE_TOUCH_SCREEN__ & __MMI_TOUCH_SCREEN__ */

#ifdef __VDOREC_COLOR_IDX_FRAME__
/*****************************************************************************
*  color idx frame 
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_hint_color_idx_frame
 * DESCRIPTION
 *  hint color idx frame
 * PARAMETERS
 *  index       [IN]        
 *  a(?)        [IN]        Hilight index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_hint_color_idx_frame(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_COLOR_IDX_FRAME);

    memset((PS8) hintData[(index)], 0, sizeof(hintData[(index)]));
    mmi_ucs2cpy(
        (S8*) hintData[index],
        (S8*) GetString((U16) (STR_ID_VDOREC_COLOR_IDX_FRAME_START + g_vdorec_cntx.setting.color_idx_frame + 1)));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_highlight_color_idx_frame
 * DESCRIPTION
 *  highlight color idx frame
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_highlight_color_idx_frame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_HIGHLIGHT_COLOR_IDX_FRAME);

    SetLeftSoftkeyFunction(mmi_vdorec_entry_color_idx_frame_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdorec_entry_color_idx_frame_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_color_idx_frame_highlight_hdlr
 * DESCRIPTION
 *  color idx frame highlight handler
 * PARAMETERS
 *  idx     [IN]        Highlight index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_color_idx_frame_highlight_hdlr(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_COLOR_IDX_FRAME_HILIGHT_HDLR);

    g_vdorec_menu_cntx.cur_selected_color_idx_frame = idx;

    if (idx == 0)   /* off */
    {
        ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(mmi_vdorec_set_color_idx_frame_value, KEY_EVENT_UP);
    }
    else    /* frame */
    {
        ChangeLeftSoftkey(STR_GLOBAL_VIEW, IMG_GLOBAL_OK);
        SetLeftSoftkeyFunction(mmi_vdorec_entry_color_idx_frame_view_screen, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_color_idx_frame_view_screen
 * DESCRIPTION
 *  entry color idx frame viewer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_entry_color_idx_frame_view_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 img_id = 0;
    U16 str_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ENTRY_COLOR_IDX_FRAME_VIEW_SCREEN);

    EntryNewScreen(SCR_ID_VDOREC_COLOR_IDX_FRAME_VIEW, NULL, mmi_vdorec_entry_color_idx_frame_view_screen, NULL);

#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
#endif 

    gdi_layer_lock_frame_buffer();

    str_id = (U16) (STR_ID_VDOREC_COLOR_IDX_FRAME_OFF + g_vdorec_menu_cntx.cur_selected_color_idx_frame);

#ifdef __VDOREC_FEATURE_VIDEO_SIZE_QQVGA__
    img_id = (U16) (IMG_ID_VDOREC_COLOR_IDX_FRAME_QVGA_START + g_vdorec_menu_cntx.cur_selected_color_idx_frame);
#elif defined(__VDOREC_FEATURE_VIDEO_SIZE_CIF__) || defined(__VDOREC_FEATURE_VIDEO_SIZE_QCIF__)
    img_id = (U16) (IMG_ID_VDOREC_COLOR_IDX_FRAME_QCIF_START + g_vdorec_menu_cntx.cur_selected_color_idx_frame);
#endif 

    ShowCategory221Screen(
        str_id,
        GetRootTitleIcon(MENU_ID_VDOREC_APP),
        STR_ID_VDOREC_COLOR_IDX_FRAME_SET,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        GDI_COLOR_WHITE,
        NULL);

#ifndef __MMI_TOUCH_SCREEN__
    draw_arrow_indication(0, 0, 1, 1);
#endif 

    gdi_layer_set_clip(
        0,
        MMI_title_y + MMI_title_height,
        UI_device_width - 1,
        MMI_title_y + MMI_title_height + MMI_content_height - 1);

    {
        S32 offset_x, offset_y, img_width, img_height;

        offset_x = MMI_title_x;
        offset_y = MMI_title_y + MMI_title_height;

        gdi_image_get_dimension_id(img_id, &img_width, &img_height);

        if (img_width > img_height)
        {
            if (img_width > MMI_content_width)
            {
                float tmp = (float)img_width / MMI_content_width;

                img_height = (S32) (((float)img_height) / tmp);
                img_width = MMI_content_width;
            }
            else
            {
                offset_x += ((MMI_content_width - img_width) >> 1);
            }

            offset_y += ((MMI_content_height - img_height) >> 1);
        }
        else
        {
            if (img_height > MMI_content_height)
            {
                float tmp = (float)img_height / MMI_content_height;

                img_width = (S32) (((float)img_width) / tmp);
                img_height = MMI_content_height;
            }
            else
            {
                offset_y += ((MMI_content_height - img_height) >> 1);
            }

            offset_x += ((MMI_content_width - img_width) >> 1);
        }
        gdi_image_draw_resized_id(offset_x, offset_y, img_width, img_height, img_id);
    }

    /* gdi_image_draw_id(0, 0, img_id); */

    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_base_layer(0, 0, UI_device_width - 1, UI_device_height - 1);

    SetLeftSoftkeyFunction(mmi_vdorec_set_color_idx_frame_value, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vdorec_color_idx_frame_goto_previous_frame, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_vdorec_color_idx_frame_goto_next_frame, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_color_idx_frame_goto_previous_frame
 * DESCRIPTION
 *  go to previous frame
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_color_idx_frame_goto_previous_frame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_COLOR_IDX_FRAME_GOTO_PREVIOUS_FRAME);

    if (g_vdorec_menu_cntx.cur_selected_color_idx_frame == 1)
    {
        g_vdorec_menu_cntx.cur_selected_color_idx_frame = VDOREC_SETTING_COLOR_IDX_FRAME_COUNT - 1;
    }
    else
    {
        g_vdorec_menu_cntx.cur_selected_color_idx_frame--;
    }

    mmi_vdorec_entry_color_idx_frame_view_screen();
    DeleteNHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_color_idx_frame_goto_next_frame
 * DESCRIPTION
 *  go to next frame
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_color_idx_frame_goto_next_frame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_COLOR_IDX_FRAME_GOTO_NEXT_FRAME);

    if (g_vdorec_menu_cntx.cur_selected_color_idx_frame >= VDOREC_SETTING_COLOR_IDX_FRAME_COUNT - 1)
    {
        g_vdorec_menu_cntx.cur_selected_color_idx_frame = 1;
    }
    else
    {
        g_vdorec_menu_cntx.cur_selected_color_idx_frame++;
    }

    mmi_vdorec_entry_color_idx_frame_view_screen();
    DeleteNHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_set_color_idx_frame_value
 * DESCRIPTION
 *  set color idx frame setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_set_color_idx_frame_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_SET_COLOR_IDX_FRAME_VALUE);

    /* capture size not full screen */
    mmi_vdorec_disply_popup((PU8) GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS);
    DeleteUptoScrID(SCR_ID_VDOREC_OPTION);

    g_vdorec_cntx.setting.color_idx_frame = g_vdorec_menu_cntx.cur_selected_color_idx_frame;
    mmi_vdorec_store_setting();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_color_idx_frame_screen
 * DESCRIPTION
 *  highlight color idx frame
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_entry_color_idx_frame_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[16];
    U16 ItemIcons[16] = 
    {
        IMG_GLOBAL_L1, 
            IMG_GLOBAL_L2,
            IMG_GLOBAL_L3,
            IMG_GLOBAL_L4,
            IMG_GLOBAL_L5,
            IMG_GLOBAL_L6,
            IMG_GLOBAL_L7,
            IMG_GLOBAL_L8,
            IMG_GLOBAL_L9,
            IMG_GLOBAL_L10,
            IMG_GLOBAL_L11,
            IMG_GLOBAL_L12,
            IMG_GLOBAL_L13,
            IMG_GLOBAL_L14,
            IMG_GLOBAL_L15,
            IMG_GLOBAL_L16
    };U16 nItems;
    U8 *guiBuffer;
    U16 selected_item = 0;
    U16 menu_id = 0;
    U16 title_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ENTRY_COLOR_IDX_FRAME_SCREEN);

    EntryNewScreen(SCR_ID_VDOREC_COLOR_IDX_FRAME, NULL, mmi_vdorec_entry_color_idx_frame_screen, NULL);

#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
#endif 

    menu_id = MENU_ID_VDOREC_COLOR_IDX_FRAME;
    title_id = STR_ID_VDOREC_COLOR_IDX_FRAME;

    guiBuffer = GetCurrGuiBuffer(SCR_ID_VDOREC_COLOR_IDX_FRAME);
    nItems = GetNumOfChild(menu_id);

    GetSequenceStringIds(menu_id, ItemList);
    SetParentHandler(menu_id);

    RegisterHighlightHandler(mmi_vdorec_color_idx_frame_highlight_hdlr);

    if (guiBuffer != NULL)
    {
        selected_item = g_vdorec_menu_cntx.cur_selected_color_idx_frame;
    }
    else
    {
        selected_item = g_vdorec_cntx.setting.color_idx_frame;
    }

    ShowCategory11Screen(
        title_id,
        GetRootTitleIcon(MENU_ID_VDOREC_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        selected_item,  /* current index */
        NULL);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_draw_color_idx_frame
 * DESCRIPTION
 *  draw colo idx frame on overlay_frame layer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_draw_color_idx_frame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 image_idx = 0;
    gdi_color *p_gdi_palette;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_DRAW_COLOR_IDX_FRAME);

    gdi_layer_push_and_set_active(g_vdorec_cntx.overlay_frame_layer_handle);

    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);

    /* if frame is set , draw frame */
    if (g_vdorec_cntx.setting.color_idx_frame != VDOREC_SETTING_COLOR_IDX_FRAME_OFF)
    {
        switch (vdorec_video_size_command_map[g_vdorec_cntx.setting.video_size])
        {
        #ifdef __VDOREC_FEATURE_VIDEO_SIZE_SQCIF__
            case MDI_VIDEO_VIDEO_SIZE_SQCIF:
                ASSERT(0);
                break;
        #endif /* __VDOREC_FEATURE_VIDEO_SIZE_SQCIF__ */ 

        #ifdef __VDOREC_FEATURE_VIDEO_SIZE_QCIF__
            case MDI_VIDEO_VIDEO_SIZE_QCIF:
                image_idx = (U16) (IMG_ID_VDOREC_COLOR_IDX_FRAME_QCIF_START + g_vdorec_cntx.setting.color_idx_frame);
                g_vdorec_cntx.overlay_frame_width = VDOREC_COLOR_IDX_FRAME_QCIF_WIDTH;
                g_vdorec_cntx.overlay_frame_height = VDOREC_COLOR_IDX_FRAME_QCIF_HEIGHT;
                break;
        #endif /* __VDOREC_FEATURE_VIDEO_SIZE_QCIF__ */ 

        #ifdef __VDOREC_FEATURE_VIDEO_SIZE_CIF__
            case MDI_VIDEO_VIDEO_SIZE_CIF:
                image_idx = (U16) (IMG_ID_VDOREC_COLOR_IDX_FRAME_QCIF_START + g_vdorec_cntx.setting.color_idx_frame);
                g_vdorec_cntx.overlay_frame_width = VDOREC_COLOR_IDX_FRAME_QCIF_WIDTH;
                g_vdorec_cntx.overlay_frame_height = VDOREC_COLOR_IDX_FRAME_QCIF_HEIGHT;
                break;
        #endif /* __VDOREC_FEATURE_VIDEO_SIZE_CIF__ */ 

        #ifdef __VDOREC_FEATURE_VIDEO_SIZE_QQVGA__
            case MDI_VIDEO_VIDEO_SIZE_QQVGA:
                image_idx = (U16) (IMG_ID_VDOREC_COLOR_IDX_FRAME_QVGA_START + g_vdorec_cntx.setting.color_idx_frame);
                g_vdorec_cntx.overlay_frame_width = VDOREC_COLOR_IDX_FRAME_QVGA_WIDTH;
                g_vdorec_cntx.overlay_frame_height = VDOREC_COLOR_IDX_FRAME_QVGA_HEIGHT;
                break;
        #endif /* __VDOREC_FEATURE_VIDEO_SIZE_QQVGA__ */ 

            default:
                ASSERT(0);
                break;
        }
        gdi_layer_resize(g_vdorec_cntx.overlay_frame_width, g_vdorec_cntx.overlay_frame_height);
        gdi_image_draw_id_with_transparent_color(0, 0, (U16) (image_idx));

        /* get palette and convert it into YUV444 */
        p_gdi_palette = gdi_layer_get_palette();
        g_vdorec_cntx.overlay_frame_source_key = (U8) gdi_image_gif_get_transparent_index();
        g_vdorec_cntx.overlay_frame_palette_size = gdi_image_gif_get_palette_size();
      /*************** RGB to YUV format **************************************************
      *
      *     [MSDN RGB888 to YUV444 (16bits)]
      *
      *     Y = ( (  66 * R + 129 * G +  25 * B + 128) >> 8) +  16
      *     U = ( ( -38 * R -  74 * G + 112 * B + 128) >> 8) + 128
      *     V = ( ( 112 * R -  94 * G -  18 * B + 128) >> 8) + 128
      *     
      *     These formulas produce 8-bit results using coefficients 
      *     that require no more than 8 bits of (unsigned) precision. 
      *     Intermediate results require up to 16 bits of precision.
      *
      ***************************************************************************************/
        {
            U16 i;
            U32 Y, U, V;
            U32 R, G, B;
            U32 *p_overlay_palette;

            p_overlay_palette = &g_vdorec_cntx.overlay_palette[0];
            for (i = 0; i < 256; i++)
            {
                R = (U32) ((U8) (*p_gdi_palette >> 16));
                G = (U32) ((U8) (*p_gdi_palette >> 8));
                B = (U32) ((U8) (*p_gdi_palette));

                Y = (U32) ((U8) (((66 * R + 129 * G + 25 * B + 128) >> 8) + 16));
                U = (U32) ((U8) (((-38 * R - 74 * G + 112 * B + 128) >> 8) + 128));
                V = (U32) ((U8) (((112 * R - 94 * G - 18 * B + 128) >> 8) + 128));

                (*p_overlay_palette) = (V) | (U << 8) | (Y << 16);
                p_overlay_palette++;
                p_gdi_palette++;
            }
        }
        /* set palette, currently we only support 8bpp(256 colors) palette */
        mdi_video_set_overlay_palette(255, &g_vdorec_cntx.overlay_palette[0]);
    }
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_preview_change_frame_down
 * DESCRIPTION
 *  change add frame
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_preview_change_frame_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_PREVIW_CHANGE_FRAME_DOWN);

    /* currently only allows to edit in preview state */
    if (g_vdorec_cntx.state == VDOREC_STATE_PREVIEW)
    {
        if (g_vdorec_cntx.setting.color_idx_frame == 0)
        {
            g_vdorec_cntx.setting.color_idx_frame = VDOREC_SETTING_COLOR_IDX_FRAME_COUNT - 1;
        }
        else
        {
            g_vdorec_cntx.setting.color_idx_frame--;
        }

        mdi_video_rec_preview_stop();
        mmi_vdorec_draw_color_idx_frame();
        mmi_vdorec_start_preview();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_preview_change_frame_up
 * DESCRIPTION
 *  change add frame
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_preview_change_frame_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_PREVIEW_CHANGE_FRAME_UP);

    /* currently only allows to edit in preview state */
    if (g_vdorec_cntx.state == VDOREC_STATE_PREVIEW)
    {
        if (g_vdorec_cntx.setting.color_idx_frame >= VDOREC_SETTING_COLOR_IDX_FRAME_COUNT - 1)
        {
            g_vdorec_cntx.setting.color_idx_frame = 0;
        }
        else
        {
            g_vdorec_cntx.setting.color_idx_frame++;
        }

        mdi_video_rec_preview_stop();
        mmi_vdorec_draw_color_idx_frame();
        mmi_vdorec_start_preview();
    }

}
#endif /* __VDOREC_COLOR_IDX_FRAME__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_usb_mode_hdlr
 * DESCRIPTION
 *  usb mode handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_usb_mode_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_USB_MODE_HDLR);

    if (g_vdorec_cntx.is_saving)
    {
        mdi_video_rec_stop_save();
        g_vdorec_cntx.is_saving = FALSE;
        DeleteScreenIfPresent(SCR_ID_VDOREC_SAVING);
    }
}


#ifdef __VDOREC_FEATURE_SWITCH_TO_CAMERA__
/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_highlight_to_camera
 * DESCRIPTION
 *  camera
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_highlight_to_camera(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_HIGHLIGHT_TO_CAMERA);

    SetLeftSoftkeyFunction(mmi_vdorec_switch_to_camera_hdlr, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdorec_switch_to_camera_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_switch_to_camera_hdlr
 * DESCRIPTION
 *  switch to camera app.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_switch_to_camera_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_SWITCH_TO_CAMERA_HDLR);

    switch(g_vdorec_cntx.state)
    {
        case VDOREC_STATE_BG_CALL:
        case VDOREC_STATE_VIDEO_PREVIEW_BGCALL:
            mmi_vdorec_disply_popup(
                (PU8)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL),
                MMI_EVENT_FAILURE);
            break;
            
        default:
            EntryNewScreen(SCR_ID_VDOREC_OPTION, NULL,NULL,NULL);
            
            for (i = SCR_ID_VDOREC_APP; i < SCR_ID_VDOREC_END; i++)
            {
                DeleteScreenIfPresent(i);
            }
            mmi_camera_entry_app_screen();            
            break;
    }
}
#endif /* __VDOREC_FEATURE_SWITCH_TO_CAMERA__ */

#ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_delete_saved_vdo_hdlr
 * DESCRIPTION
 *  delete saved video.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_delete_saved_vdo_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_DELETE_SAVED_VDO_HDLR);

    fs_ret = FS_Delete((WCHAR*)g_vdorec_cntx.filepath);

    if (fs_ret == FS_NO_ERROR)
    {
        mmi_vdorec_disply_popup((PU8)GetString(STR_GLOBAL_DELETED), MMI_EVENT_SUCCESS);
    }
    else
    {
        mmi_vdorec_disply_popup(
            (PU8)GetString(GetFileSystemErrorString(fs_ret)),
            MMI_EVENT_FAILURE);
    }
    DeleteScreenIfPresent(SCR_ID_VDOREC_PREVIEW_OPTION);
    DeleteScreenIfPresent(SCR_ID_VDOREC_SAVED_PREVIEW);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_delete_saved_vdo_confirm
 * DESCRIPTION
 *  confirm screen of delete saved video
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_delete_saved_vdo_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_DELETE_SAVED_VDO_CONFIRM);

#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    
    mmi_display_popup_confirm_rotated(
        get_string(STR_GLOBAL_YES),
        get_image(IMG_GLOBAL_YES),
        get_string(STR_GLOBAL_NO),
        get_image(IMG_GLOBAL_NO),
        (UI_string_type)get_string(STR_ID_VDOREC_NOTIFY_DELETE_CONFIRM),
        MMI_EVENT_QUERY,
       MMI_FRM_SCREEN_ROTATE_270);
    
#else /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__) */ 
    
    mmi_display_popup_confirm(
        get_string(STR_GLOBAL_YES),
        get_image(IMG_GLOBAL_YES),
        get_string(STR_GLOBAL_NO),
        get_image(IMG_GLOBAL_NO),
        (UI_string_type)get_string(STR_ID_VDOREC_NOTIFY_DELETE_CONFIRM),
        MMI_EVENT_QUERY);

#endif /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__) */ 
   
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_vdorec_delete_saved_vdo_hdlr, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_highlight_delete
 * DESCRIPTION
 *  hilight handler of delete.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_highlight_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_HIGHLIGHT_DELETE);

    SetLeftSoftkeyFunction(mmi_vdorec_delete_saved_vdo_confirm, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdorec_delete_saved_vdo_confirm, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


#if defined (__VDOREC_FEATURE_MERGE_SEND_OPTION__)
/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_highlight_to_camera
 * DESCRIPTION
 *  camera
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_highlight_send(void)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_HIGHLIGHT_SEND);

    SetLeftSoftkeyFunction(mmi_vdorec_entry_send_screen, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdorec_entry_send_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
#endif /* __VDOREC_FEATURE_MERGE_SEND_OPTION__ */


#if defined(__VDOREC_FEATURE_RSK_DELETE__)
/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_highlight_to_camera
 * DESCRIPTION
 *  camera
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_preview_continue(void)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_PREVIEW_CONTINUE);

    GoBackToHistory(SCR_ID_VDOREC_APP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_highlight_to_camera
 * DESCRIPTION
 *  camera
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_highlight_continue(void)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_HIGHLIGHT_CONTINUE);

    SetLeftSoftkeyFunction(mmi_vdorec_preview_continue, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdorec_preview_continue, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);   
}
#endif /* defined(__VDOREC_FEATURE_RSK_DELETE__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_preview_option_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_entry_preview_option_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[16];
    U16 ItemIcons[16] = 
    {
        IMG_GLOBAL_L1, 
            IMG_GLOBAL_L2,
            IMG_GLOBAL_L3,
            IMG_GLOBAL_L4,
            IMG_GLOBAL_L5,
            IMG_GLOBAL_L6,
            IMG_GLOBAL_L7,
            IMG_GLOBAL_L8,
            IMG_GLOBAL_L9,
            IMG_GLOBAL_L10,
            IMG_GLOBAL_L11,
            IMG_GLOBAL_L12,
            IMG_GLOBAL_L13,
            IMG_GLOBAL_L14,
            IMG_GLOBAL_L15,
            IMG_GLOBAL_L16
    };
    U16 nItems;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ENTRY_PREVIEW_OPTION_SCREEN);

    EntryNewScreen(SCR_ID_VDOREC_PREVIEW_OPTION, NULL, mmi_vdorec_entry_preview_option_screen, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_VDOREC_PREVIEW_OPTION);

    mmi_vdorec_hide_unaviailable_send_options();

    nItems = GetNumOfChild_Ext(MENU_ID_VDOREC_PREVIEW_OPTION);
    GetSequenceStringIds_Ext(MENU_ID_VDOREC_PREVIEW_OPTION, ItemList);
    SetParentHandler(MENU_ID_VDOREC_PREVIEW_OPTION);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* rotate UI */
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
#endif

    ShowCategory52Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_VDOREC_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        ItemIcons,
        0,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_preview_idle_timeout_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_preview_idle_timeout_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_PREVIEW_IDLE_TIMEROUT_HDLR);

    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_preview_idle_timeout_cancel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_vdorec_preview_idle_timeout_cancel(KEYBRD_MESSAGE *eventKey)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_PREVIEW_IDLE_TIMEOUT_CANCEL);

    gui_cancel_timer(mmi_vdorec_preview_idle_timeout_hdlr);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_preview_option_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_exit_preview_video_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_EXIT_PREVIEW_VIDEO_SCREEN);

    gui_cancel_timer(mmi_vdorec_play_timer_cyclic);
    mmi_vdorec_preview_idle_timeout_cancel(NULL);       /* cancel preview timeout timer */
    mmi_frm_kbd_reg_pre_key_hdlr(NULL);
    
    if (g_vdorec_cntx.state == VDOREC_STATE_VIDEO_PREVIEW_PLAY)
    {
        mdi_video_ply_stop();
        mdi_video_ply_close_clip_file();
    }
    else if (g_vdorec_cntx.state == VDOREC_STATE_VIDEO_PREVIEW_STOP)
    {
        mdi_video_ply_close_clip_file();
    }
    
    g_vdorec_cntx.state = VDOREC_STATE_EXIT;
    g_vdorec_cntx.is_del_key_pressed = FALSE;

    gdi_layer_flatten_previous_to_base();    
    
    /* free bg layer */

    /* free preview layers */
    gdi_layer_free(g_vdorec_cntx.preview_layer_handle);
    g_vdorec_cntx.preview_layer_handle = 0;

    /*release tmp layer handle*/
    if (g_vdorec_cntx.is_use_hw_rotate)
    {
        for (i = 0 ; i < g_vdorec_cntx.osd_layer_region_count ; i ++)
        {
            gdi_layer_free(g_vdorec_cntx.tmp_osd_layer_region_handle[i]);
            g_vdorec_cntx.tmp_osd_layer_region_handle[i] = GDI_LAYER_EMPTY_HANDLE;
            
            //mmi_frm_scrmem_free(g_vdorec_cntx.tmp_osd_layer_region_handle_ptr[i]);
            //g_vdorec_cntx.tmp_osd_layer_region_handle_ptr[i] = NULL;    
        }
    }

    
#ifdef __VDOREC_FEATURE_SHOW_STATUS_BAR__
    wgui_status_icon_set_display_layer(g_vdorec_cntx.prev_status_bar_layer_handle);
    
    if (g_vdorec_cntx.status_bar_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(g_vdorec_cntx.status_bar_layer_handle);
        g_vdorec_cntx.status_bar_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }
#endif /* __VDOPLY_FEATURE_SHOW_STATUS_BAR__ */

    if (g_vdorec_cntx.osd_layer_region_count == VDOREC_OSD_LAYER_COUNT_ONE)
    {
        if (g_vdorec_cntx.osd_layer_handle)
        {
            gdi_layer_free(g_vdorec_cntx.osd_layer_handle);
            mmi_frm_scrmem_free(g_vdorec_cntx.osd_layer_buf_ptr);
            g_vdorec_cntx.osd_layer_buf_ptr = NULL;
        }
    }
    else
    {
        for (i = 0 ; i < g_vdorec_cntx.osd_layer_region_count ; i++)
        {
            if (g_vdorec_cntx.osd_layer_region_handle[i] != GDI_LAYER_EMPTY_HANDLE)
            {
                gdi_layer_free(g_vdorec_cntx.osd_layer_region_handle[i]);
                g_vdorec_cntx.osd_layer_region_handle[i] = GDI_LAYER_EMPTY_HANDLE;
                
                mmi_frm_scrmem_free(g_vdorec_cntx.osd_layer_region_handle_ptr[i]);
                g_vdorec_cntx.osd_layer_region_handle_ptr[i] = NULL;
            }
        }
    }
    
#ifdef __VDOREC_FEATURE_HORIZONTAL_VIEW__
    /* restore base layer rotation */

    gdi_lcd_set_rotate(GDI_LAYER_ROTATE_0);

    gdi_layer_resize(UI_device_width, UI_device_height);

#ifdef __MMI_TVOUT__
    if (mdi_tvout_is_enable())
    {
        mdi_tvout_set_mode(MDI_TV_MODE_LCD_SCR, 0, 0);
    }
#endif /* __MMI_TVOUT__ */ 

    /* clear in black layer if it is horizontal view */
    gdi_layer_clear(GDI_COLOR_BLACK);
    
#endif /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */ 

    /* restore rotate layer flag */
    gdi_lcd_set_rotate_by_layer(g_vdorec_cntx.prev_rotate_by_layer);

    /* disable multi layer */
    gdi_layer_multi_layer_disable();

    /* resume alignment timer */
    UI_disable_alignment_timers();

    /* resume LED patten */
    StartLEDPatternBackGround();

    /* let MMI can sleep */
    TurnOffBacklight();

    /* resume background audio */
    mdi_audio_resume_background_play();

    /* re-enable keypad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

    if (g_vdorec_cntx.gdi_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(g_vdorec_cntx.gdi_layer_handle);
        g_vdorec_cntx.gdi_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }

    /* exit sublcd */
#ifdef __MMI_SUBLCD__
    /* exit app screen if exist , and not exit because toggle self capture to sublcd */
    if (g_vdorec_cntx.is_sub_display)
    {
        GoBackSubLCDHistory();
        g_vdorec_cntx.is_sub_display = FALSE;
    }
#endif /* __MMI_SUBLCD__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_preview_video_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_entry_preview_video_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    mdi_video_info_struct v_info;
    PU8 base_layer_ptr;
    S32 buffer_size;
    S32 layer_offset_x;
    S32 layer_offset_y;
    S32 layer_width;
    S32 layer_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ENTRY_PREVIEW_VIDEO_SCREEN);

#if defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) && defined(__MTK_TARGET__)
    /* back to idle if clam is closed */
    if (IsClamClose())
    {
        DisplayIdleScreen();
        return;
    }
#endif /* defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) && defined(__MTK_TARGET__) */ 

    EntryNewScreen(
        SCR_ID_VDOREC_SAVED_PREVIEW,
        mmi_vdorec_exit_preview_video_screen,
        mmi_vdorec_entry_preview_video_screen,
        NULL);


    DeleteScreenIfPresent(SCR_ID_VDOREC_PREVIEW_OPTION);
    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();

    entry_full_screen();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_VDOREC_SAVED_PREVIEW);

    /* entry sublcd */
#ifdef __MMI_SUBLCD__
    if (!mmi_is_redrawing_bk_screens())
    {
        if (!g_vdorec_cntx.is_sub_display)
        {
            ForceSubLCDScreen(mmi_vdorec_entry_sublcd_screen);
        }
    }
#endif /* __MMI_SUBLCD__ */ 

#if defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) 
    /* register event hdlr */
    mmi_frm_block_interrupt_event_handler(MMI_FRM_INT_CLAM, mmi_vdorec_clam_close_event_hdlr, NULL);
#endif /* defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) */ 

    /* hook to touch screen callback */
#if defined(__VDOREC_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_pen_down_handler(mmi_vdorec_touch_scr_pen_down_hdlr);
    wgui_register_pen_up_handler(mmi_vdorec_touch_scr_pen_up_hdlr);
    wgui_register_pen_move_handler(mmi_vdorec_touch_scr_pen_move_hdlr);
#endif /* defined(__VDOREC_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__) */ 

   /*******************************************************************
   * Init proper global state for video applcation  
   ********************************************************************/
    
    AudioStopReq(GetCurKeypadTone());                       /* force all playing keypad tone off */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);      /* disable key pad tone */
    gdi_layer_multi_layer_enable();                         /* enable multi_layer */
    mdi_audio_suspend_background_play();                    /* suspend background play */
    UI_disable_alignment_timers();                          /* disalbe align timer */
    StopLEDPatternBackGround();                             /* stop LED patten */
    gdi_layer_clear(GDI_COLOR_BLACK);
    TurnOnBacklight(0);                                     /* stop MMI sleep */

    gui_set_font(&MMI_medium_font);                         /* use medium font */

    g_vdorec_cntx.prev_rotate_by_layer = gdi_lcd_get_rotate_by_layer();

#ifdef __MMI_TVOUT__
    if (!mdi_tvout_is_enable())
    {
        gdi_lcd_set_rotate_by_layer(TRUE);                  /* if no TV-out, rotate by layer */
    }
    else
    {   
        gdi_lcd_set_rotate_by_layer(FALSE);                 /* if have Tv-out rotate by LCM */
    }
#endif /* __MMI_TVOUT__ */


    /***************************************************************************** 
     * Create layers 
     *****************************************************************************/
#ifdef __VDOREC_FEATURE_HORIZONTAL_VIEW__
    if (g_vdorec_cntx.is_use_hw_rotate)
    {
        gdi_lcd_set_rotate(GDI_LAYER_ROTATE_0);
    }
    else
    {
        gdi_lcd_set_rotate(GDI_LAYER_ROTATE_270);
    }
#ifdef __MMI_TVOUT__
    if (mdi_tvout_is_enable())
    {
        mdi_tvout_set_mode(MDI_TV_MODE_MULTIMEDIA_HOR_LCD_SCR, 0, 0);
    }
#endif /* __MMI_TVOUT__ */ 

#endif /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */ 

   /************ base layer layer ************/
    gdi_layer_get_base_handle(&g_vdorec_cntx.bg_layer_handle);

    gdi_layer_push_and_set_active(g_vdorec_cntx.bg_layer_handle);
    gdi_layer_get_buffer_ptr(&base_layer_ptr);
    gdi_layer_pop_and_restore_active();

#ifdef __VDOREC_FEATURE_HORIZONTAL_VIEW__
    if (g_vdorec_cntx.is_use_hw_rotate)
    {
        g_vdorec_cntx.lcd_width = UI_device_width;
        g_vdorec_cntx.lcd_height = UI_device_height;
    }
    else
    {
        g_vdorec_cntx.lcd_width = UI_device_height;
        g_vdorec_cntx.lcd_height = UI_device_width;
    }
#else /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */ 
    g_vdorec_cntx.lcd_width = UI_device_width;
    g_vdorec_cntx.lcd_height = UI_device_height;

#endif /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */ 
    
    /************ preview window layer ************/

    g_vdorec_cntx.preview_wnd_width = g_vdorec_osd_cntx.preview_wnd.rect.width;
    g_vdorec_cntx.preview_wnd_height = g_vdorec_osd_cntx.preview_wnd.rect.height;
    g_vdorec_cntx.preview_wnd_offset_x = g_vdorec_osd_cntx.preview_wnd.rect.offset_x;
    g_vdorec_cntx.preview_wnd_offset_y = g_vdorec_osd_cntx.preview_wnd.rect.offset_y;


#ifdef __VDOREC_FEATURE_HORIZONTAL_VIEW__

#ifdef __MMI_SCREEN_ROTATE__
    mmi_frm_set_self_rotation_flag(MMI_FRM_SCREEN_ROTATE_270);
#endif 

    if (g_vdorec_cntx.is_use_hw_rotate)
    {
        if (g_vdorec_cntx.is_use_hw_rotate_by_lcd)
        {
            layer_offset_x = g_vdorec_cntx.preview_wnd_offset_x;
            layer_offset_y = g_vdorec_cntx.preview_wnd_offset_y;
            layer_width = g_vdorec_cntx.preview_wnd_width;
            layer_height = g_vdorec_cntx.preview_wnd_height;   
        }
        else
        {
            layer_offset_x = 
                UI_device_width - 
                g_vdorec_cntx.preview_wnd_offset_y - 
                g_vdorec_cntx.preview_wnd_height;
            layer_offset_y = g_vdorec_cntx.preview_wnd_offset_x;
            layer_width = g_vdorec_cntx.preview_wnd_height;
            layer_height = g_vdorec_cntx.preview_wnd_width;   
        }
    }
    else
    { 
        layer_offset_x = g_vdorec_cntx.preview_wnd_offset_x;
        layer_offset_y = g_vdorec_cntx.preview_wnd_offset_y;
        layer_width = g_vdorec_cntx.preview_wnd_width;
        layer_height = g_vdorec_cntx.preview_wnd_height;    
    }

    /*gdi_layer_create(
        0,
        0,
        g_vdorec_cntx.preview_wnd_width,
        g_vdorec_cntx.preview_wnd_height,
        &g_vdorec_cntx.preview_layer_handle);*/

    buffer_size = g_vdorec_cntx.preview_wnd_width * g_vdorec_cntx.preview_wnd_height * VDOREC_BUFFER_DEPTH;
    gdi_layer_create_using_outside_memory(
        layer_offset_x,
        layer_offset_y,
        layer_width,
        layer_height,
        &g_vdorec_cntx.preview_layer_handle,
        base_layer_ptr,
        buffer_size);

    gdi_layer_push_and_set_active(g_vdorec_cntx.preview_layer_handle);

    if (g_vdorec_cntx.is_use_hw_rotate && g_vdorec_cntx.is_use_hw_rotate_by_lcd)
    {
        gdi_layer_set_rotate(GDI_LCD_LAYER_ROTATE_90);
    }

    gdi_layer_clear(GDI_COLOR_BLACK);

#ifdef GDI_USING_LAYER_BACKGROUND
    gdi_layer_set_background(GDI_COLOR_BLACK);
#endif  

#else /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */ 

    /*gdi_layer_create(
        g_vdorec_cntx.preview_wnd_offset_x,
        g_vdorec_cntx.preview_wnd_offset_y,
        g_vdorec_cntx.preview_wnd_width,
        g_vdorec_cntx.preview_wnd_height,
        &g_vdorec_cntx.preview_layer_handle);*/

    buffer_size = g_vdorec_cntx.preview_wnd_width * g_vdorec_cntx.preview_wnd_height * VDOREC_BUFFER_DEPTH;
    gdi_layer_create_using_outside_memory(
        g_vdorec_cntx.preview_wnd_offset_x,
        g_vdorec_cntx.preview_wnd_offset_y,
        g_vdorec_cntx.preview_wnd_width,
        g_vdorec_cntx.preview_wnd_height,
        &g_vdorec_cntx.preview_layer_handle,
        base_layer_ptr,
        buffer_size);

    gdi_layer_push_and_set_active(g_vdorec_cntx.preview_layer_handle);

    gdi_layer_clear(GDI_COLOR_BLACK);

#ifdef GDI_USING_LAYER_BACKGROUND
    gdi_layer_set_background(GDI_COLOR_BLACK);
#endif  

#endif /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */ 

    gdi_layer_pop_and_restore_active();

    /* resized preview layer */
#ifdef __VDOREC_FEATURE_VIDEO_SIZE__
    mmi_vdorec_resize_preview_layer();
#endif 
    g_vdorec_cntx.osd_layer_handle = GDI_LAYER_EMPTY_HANDLE;

   /****************************************************************************
   * draw skin                                                                 
   *****************************************************************************/
    mmi_vdorec_init_ui();

    gdi_layer_reset_clip(); /* use full screen clip */
    gui_reset_text_clip();  /* use full screen text clip */

    gdi_layer_lock_frame_buffer();

    /* bg image */
   
#ifdef __VDOREC_FEATURE_SHOW_STATUS_BAR__
    wgui_status_icon_set_display_layer(g_vdorec_cntx.status_bar_layer_handle);
    show_status_icon_bar(0);
#endif /* __VDOREC_FEATURE_SHOW_STATUS_BAR__ */

    g_vdorec_cntx.record_time = 0;
    
    mmi_vdorec_set_softkey(
        0,
        0,
        IMG_ID_VDOREC_SK_OPTION,
        IMG_ID_VDOREC_SK_BACK,
        IMG_ID_VDOREC_SK_PLAY);

    mmi_vdorec_draw_osd(
        VDOREC_OSD_COMPONENT_SOFTKEY|
        VDOREC_OSD_COMPONENT_TIMER);

    gdi_layer_unlock_frame_buffer();

    if (g_vdorec_cntx.osd_layer_region_count == VDOREC_OSD_LAYER_COUNT_ONE)
    {
        gdi_layer_set_blt_layer(
            g_vdorec_cntx.preview_layer_handle,
            g_vdorec_cntx.osd_layer_handle,
            0,
            0);
    }
    else if (g_vdorec_cntx.osd_layer_region_count == VDOREC_OSD_LAYER_COUNT_THREE)
    {
        gdi_layer_set_blt_layer(
            g_vdorec_cntx.preview_layer_handle,
            g_vdorec_cntx.osd_layer_region_handle[0],
            g_vdorec_cntx.osd_layer_region_handle[1],
            g_vdorec_cntx.osd_layer_region_handle[2]);
    }
#ifdef GDI_6_LAYERS
    else
    {    
        gdi_layer_set_blt_layer_ext(
            g_vdorec_cntx.preview_layer_handle,
            g_vdorec_cntx.osd_layer_region_handle[0],
            g_vdorec_cntx.osd_layer_region_handle[1],
            g_vdorec_cntx.osd_layer_region_handle[2],
            g_vdorec_cntx.osd_layer_region_handle[3],
            0);
    }
#endif

    if (g_vdorec_cntx.is_use_blt_region)
    {
        /*if enter new screen ,should redraw full screen, for some area is use layer background to fill color*/
        mmi_vdorec_set_merge_region(0,0, g_vdorec_cntx.lcd_width, g_vdorec_cntx.lcd_height);
    }
    
    mmi_vdorec_blt_screen();

    /* this function is entry by small screen's history draw, no need to open file */
    if (mmi_is_redrawing_bk_screens())
    {
        return;
    }

    if (!mmi_vdorec_is_in_bgcall())
    {
        /* open video file */
        //mmi_ucs2cpy(g_vdorec_cntx.filepath, (PS8)L"d:\\videos\\PWRONOFF.mpg");
        g_vdorec_cntx.last_error = mdi_video_ply_open_clip_file(g_vdorec_cntx.filepath, &v_info);
        if (!mmi_vdorec_check_and_display_error_popup())
        {
            gui_start_timer(5000, mmi_vdorec_preview_idle_timeout_hdlr);
            mmi_vdorec_enter_state(VDOREC_STATE_VIDEO_PREVIEW_STOP);
        }        
    }
    else
    {
        gui_start_timer(5000, mmi_vdorec_preview_idle_timeout_hdlr);
        mmi_vdorec_enter_state(VDOREC_STATE_VIDEO_PREVIEW_BGCALL);
    }
   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_play_timer_cyclic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_play_timer_cyclic(void)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_PLAY_TIMER_CYCLIC);

    mdi_video_ply_get_cur_play_time(&(g_vdorec_cntx.record_time));
    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_TIMER);
    mmi_vdorec_blt_screen();

    if (g_vdorec_cntx.state == VDOREC_STATE_VIDEO_PREVIEW_PLAY)
    {
        gui_start_timer(200, mmi_vdorec_play_timer_cyclic);
    }
}

void mmi_vdorec_preview_play_finish_callback(MDI_RESULT res)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_PREVIW_PLAY_FINISH_CALLBACK);

    gui_cancel_timer(mmi_vdorec_play_timer_cyclic);
    if (g_vdorec_cntx.last_error >= MDI_RES_VDOPLY_SUCCEED ||
        !mmi_vdorec_check_and_display_error_popup())
    {
        mmi_vdorec_enter_state(VDOREC_STATE_VIDEO_PREVIEW_STOP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_fsm_preview_play
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_fsm_preview_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 blt_layer_flag;
    U32 play_layer_flag;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_FSM_PREVIEW_PLAY);

#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__)
    mmi_vdorec_set_softkey(
        0, 
        0, 
        IMG_ID_VDOREC_SK_OPTION, 
        IMG_ID_VDOREC_SK_BACK, 
        IMG_ID_VDOREC_SK_STOP);
#else /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) */ 
    mmi_vdorec_set_softkey(
        0,
        0,
        IMG_ID_VDOREC_SK_OPTION,
        IMG_ID_VDOREC_SK_BACK,
        IMG_ID_VDOREC_SK_STOP);
#endif /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) */

    if (g_vdorec_cntx.is_use_blt_region)
    {
        /*if enter new screen ,should redraw full screen, for some area is use layer background to fill color*/
        mmi_vdorec_set_merge_region(0,0, g_vdorec_cntx.lcd_width, g_vdorec_cntx.lcd_height);
    }

    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY);
    mmi_vdorec_blt_screen();
    /* open video and play */

/*config the video layer*/
    play_layer_flag = GDI_LAYER_ENABLE_LAYER_0;
    blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0;

    if (g_vdorec_cntx.osd_layer_region_count == VDOREC_OSD_LAYER_COUNT_ONE)
    {
        blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1;
    }
    else
    {
        if (g_vdorec_cntx.osd_layer_region_handle[0])
        {
            blt_layer_flag |= GDI_LAYER_ENABLE_LAYER_1;
        }
        
        if (g_vdorec_cntx.osd_layer_region_handle[1])
        {
            blt_layer_flag |= GDI_LAYER_ENABLE_LAYER_2;
        }
        
        if (g_vdorec_cntx.osd_layer_region_handle[2])
        {
            blt_layer_flag |= GDI_LAYER_ENABLE_LAYER_3;
        }
        
#ifdef GDI_6_LAYERS
        if (g_vdorec_cntx.osd_layer_region_handle[3])
        {
            blt_layer_flag |= GDI_LAYER_ENABLE_LAYER_4;
        }
#endif
    }    

    if (g_vdorec_cntx.is_use_hw_rotate)
    {
        mdi_video_set_hw_rotator(GDI_LAYER_ROTATE_90);
    }
 
    /* video will be open before enter play state */
    mdi_video_ply_seek(0);

#ifdef __VDOREC_FEATURE_HORIZONTAL_VIEW__
    mdi_video_ply_play(
        g_vdorec_cntx.preview_layer_handle,
        blt_layer_flag,
        play_layer_flag,
        1,
        TRUE,
        TRUE,
        MDI_DEVICE_SPEAKER2 ,
        MDI_VIDEO_LCD_ROTATE_270,
        100,
        mmi_vdorec_preview_play_finish_callback);
#else   /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */
    mdi_video_ply_play(
        g_vdorec_cntx.preview_layer_handle,
        blt_layer_flag,
        play_layer_flag,
        1,
        TRUE,
        TRUE,
        MDI_DEVICE_SPEAKER2 ,
        MDI_VIDEO_LCD_ROTATE_0,
        100,
        mmi_vdorec_preview_play_finish_callback);
#endif  /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */

    gui_start_timer(200, mmi_vdorec_play_timer_cyclic);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_fsm_preview_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_fsm_preview_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_FSM_PREVIEW_STOP);

#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__)
    mmi_vdorec_set_softkey(
        0, 
        0, 
        IMG_ID_VDOREC_SK_OPTION, 
        IMG_ID_VDOREC_SK_BACK, 
        IMG_ID_VDOREC_SK_PLAY);
#else /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) */ 
    mmi_vdorec_set_softkey(
        0,
        0,
        IMG_ID_VDOREC_SK_OPTION,
        IMG_ID_VDOREC_SK_BACK,
        IMG_ID_VDOREC_SK_PLAY);
#endif /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) */
    
    gui_cancel_timer(mmi_vdorec_play_timer_cyclic);   
    
    if (g_vdorec_cntx.is_use_hw_rotate)
    {
        mdi_video_set_hw_rotator(GDI_LAYER_ROTATE_90);
    }

    mdi_video_ply_stop();
    mdi_video_ply_seek_and_get_frame(0, g_vdorec_cntx.preview_layer_handle);

    g_vdorec_cntx.record_time = 0;
    
    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY | VDOREC_OSD_COMPONENT_TIMER);

    if (g_vdorec_cntx.is_use_blt_region)
    {
        /*if enter new screen ,should redraw full screen, for some area is use layer background to fill color*/
        mmi_vdorec_set_merge_region(0,0, g_vdorec_cntx.lcd_width, g_vdorec_cntx.lcd_height);
    }

    mmi_vdorec_blt_screen();


}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_del_key_press_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_del_key_press_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_DEL_KEY_PRESS_HDLR);

    switch(g_vdorec_cntx.state)
    {
        case VDOREC_STATE_VIDEO_PREVIEW_PLAY:
        case VDOREC_STATE_VIDEO_PREVIEW_STOP:
        case VDOREC_STATE_VIDEO_PREVIEW_BGCALL:
            break;
        default:
            return;
    }

    if (!g_vdorec_cntx.is_del_key_pressed)
    {
        g_vdorec_cntx.is_del_key_pressed = TRUE;
        mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY);
        mmi_vdorec_blt_screen();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_del_key_release_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_del_key_release_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_DEL_KEY_RELEASE_HDLR);

    if (g_vdorec_cntx.is_del_key_pressed)
    {

        g_vdorec_cntx.is_del_key_pressed = FALSE;
        mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY);
        mmi_vdorec_blt_screen();
        switch(g_vdorec_cntx.state)
        {
            case VDOREC_STATE_VIDEO_PREVIEW_PLAY:
            case VDOREC_STATE_VIDEO_PREVIEW_STOP:
            case VDOREC_STATE_VIDEO_PREVIEW_BGCALL:
                mmi_vdorec_delete_saved_vdo_confirm();
                break;

            default:
                ASSERT(0);
                return;
        }
    }
}
#endif  /* __VDOREC_FEATURE_PREVIEW_SAVED_FILE__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_hide_unavailable_send_options
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_hide_unaviailable_send_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__VDOREC_FEATURE_MERGE_SEND_OPTION__)    
    BOOL hide_send_menu = TRUE;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /* following menu items should be hidden when in */
    /* 1. external request                           */
    /* 2. flight mode                                */
    /* 3. or sim is not ready (mms)                  */

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_HIDE_UNAVIAILABLE_SEND_OPTIONS);

#ifdef __MMI_BT_SEND_SUPPORT__
    if (g_vdorec_cntx.is_ext_req)
    {
        mmi_frm_hide_menu_item(MENU_ID_VDOREC_TO_BT);
    }
    else if (!mmi_bt_is_to_display_bt_menu())
    {
        mmi_frm_hide_menu_item(MENU_ID_VDOREC_TO_BT);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_VDOREC_TO_BT);
    #if defined(__VDOREC_FEATURE_MERGE_SEND_OPTION__)
        hide_send_menu = FALSE;
    #endif
    }
#else
    mmi_frm_hide_menu_item(MENU_ID_VDOREC_TO_BT);
#endif /* __MMI_BT_SEND_SUPPORT__ */      

#if defined(__MMI_VDOREC_EMAIL_SUPPORT__)
    if (!mmi_email_is_email_can_forward() || mmi_bootup_get_active_flight_mode() || g_vdorec_cntx.is_ext_req)
    {
        mmi_frm_hide_menu_item(MENU_ID_VDOREC_TO_EMAIL);      
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_VDOREC_TO_EMAIL);
    #if defined(__VDOREC_FEATURE_MERGE_SEND_OPTION__)
        hide_send_menu = FALSE;        
    #endif

    }
#else
    mmi_frm_hide_menu_item(MENU_ID_VDOREC_TO_EMAIL);      
#endif /* defined(__MMI_VDOREC_EMAIL_SUPPORT__) */

#if defined(__MMI_VDOREC_MMS_SUPPORT__)
    if(!mms_is_ready() || g_vdorec_cntx.is_ext_req)
    {
        mmi_frm_hide_menu_item(MENU_ID_VDOREC_TO_MMS);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_VDOREC_TO_MMS);
    #if defined(__VDOREC_FEATURE_MERGE_SEND_OPTION__)
        hide_send_menu = FALSE;        
    #endif
    }
#else
    mmi_frm_unhide_menu_item(MENU_ID_VDOREC_TO_MMS);
#endif /* __MMI_VDOREC_MMS_SUPPORT__ */

#if defined(__VDOREC_FEATURE_MERGE_SEND_OPTION__)
    if (hide_send_menu)
    {
        mmi_frm_hide_menu_item(MENU_ID_VDOREC_SEND);
    }
    else
    {
        mmi_frm_unhide_menu_item(MENU_ID_VDOREC_SEND);
    }
#endif /* __VDOREC_FEATURE_MERGE_SEND_OPTION__ */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_send_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_entry_send_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[16];
    U16 ItemIcons[16] = 
    {
        IMG_GLOBAL_L1, 
            IMG_GLOBAL_L2,
            IMG_GLOBAL_L3,
            IMG_GLOBAL_L4,
            IMG_GLOBAL_L5,
            IMG_GLOBAL_L6,
            IMG_GLOBAL_L7,
            IMG_GLOBAL_L8,
            IMG_GLOBAL_L9,
            IMG_GLOBAL_L10,
            IMG_GLOBAL_L11,
            IMG_GLOBAL_L12,
            IMG_GLOBAL_L13,
            IMG_GLOBAL_L14,
            IMG_GLOBAL_L15,
            IMG_GLOBAL_L16
    };
    U16 nItems;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ENTRY_SEND_SCREEN);

    EntryNewScreen(SCR_ID_VDOREC_SEND, NULL, mmi_vdorec_entry_send_screen, NULL);

    guiBuffer = GetCurrGuiBuffer(SCR_ID_VDOREC_SEND);

    mmi_vdorec_hide_unaviailable_send_options();
    
    nItems = GetNumOfChild_Ext(MENU_ID_VDOREC_SEND);
    GetSequenceStringIds_Ext(MENU_ID_VDOREC_SEND, ItemList);
    SetParentHandler(MENU_ID_VDOREC_SEND);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* rotate UI */
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
#endif

    ShowCategory52Screen(
        STR_GLOBAL_SEND,
        GetRootTitleIcon(MENU_ID_VDOREC_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        ItemIcons,
        0,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_load_saved_filename
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_load_saved_filename(PS8 filepath)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_LOAD_SAVED_FILENAME);

    mmi_vdorec_load_setting();
    mmi_ucs2ncat(filepath, g_vdorec_cntx.setting.save_name, FMGR_MAX_FILE_LEN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_update_progress_ratio
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_update_progress_ratio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 progress_time = 0;
    U32 progress_size = 0;
    U64 current_time_size;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_UPDATE_PROGRESS_RATIO);
    
    /* calculate size limit */
    current_time_size = mdi_video_rec_get_record_file_size();       /* in bytes */
    if (g_vdorec_cntx.is_ext_req)
    {
        if (g_vdorec_cntx.ext_req_size != 0)
        {
            progress_size = (U32) current_time_size / (U32) g_vdorec_cntx.ext_req_size / 10;
        }
    }
    else if (g_vdorec_cntx.setting.size_limit != 0)
    {
        progress_size =
            (U32) current_time_size / vdorec_video_size_limit_command_map[g_vdorec_cntx.setting.size_limit] / 10;
    }

    /* calculate time limit */
    /* g_vdorec_cntx.record_time */
    if (g_vdorec_cntx.is_ext_req)
    {
        if (g_vdorec_cntx.ext_rec_time != 0)
        {
            progress_time = (U32)g_vdorec_cntx.record_time / (U32) g_vdorec_cntx.ext_rec_time / 10;
        }
    }
    else if (g_vdorec_cntx.setting.time_limit != 0)
    {
        progress_time =
            (U32)g_vdorec_cntx.record_time / (U32) vdorec_video_time_limit_command_map[g_vdorec_cntx.setting.time_limit] / 10;

    }

    /* update progress */
    if (progress_time == 0 && progress_size == 0)
    {
        g_vdorec_cntx.progress = 0;
    }
    else
    {
        if (progress_time > progress_size)
        {
            g_vdorec_cntx.progress = (progress_time > g_vdorec_cntx.progress)? (U16) progress_time : g_vdorec_cntx.progress;
        }
        else
        {
            g_vdorec_cntx.progress = (progress_size > g_vdorec_cntx.progress)? (U16) progress_size : g_vdorec_cntx.progress;
        }  
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_clear_panel_progress_bar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_clear_panel_progress_bar(void)
{
    S32 image_width;
    S32 image_height;
    S32 layer_offset_x;
    S32 layer_offset_y;
    S32 offset_x1, offset_y1, offset_x2, offset_y2;

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_CLEAR_PANEL_PROGRESS_BAR);

    gdi_layer_push_and_set_active(g_vdorec_cntx.timer_draw_layer);

    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

    gdi_image_get_dimension_id(IMG_ID_VDOREC_PROGRESS_FILL, &image_width, &image_height);

    offset_x1 = g_vdorec_osd_cntx.panel.progress_bar.offset_x - layer_offset_x;
    offset_y1 = g_vdorec_osd_cntx.panel.progress_bar.offset_y - layer_offset_y;
    offset_x2 = g_vdorec_osd_cntx.panel.progress_bar.offset_x + image_width - layer_offset_x;
    offset_y2 = g_vdorec_osd_cntx.panel.progress_bar.offset_y + image_height - layer_offset_y;

    gdi_draw_solid_rect(offset_x1, offset_x2, offset_y1, offset_y2, GDI_COLOR_TRANSPARENT);

    gdi_layer_pop_and_restore_active();

    if (g_vdorec_cntx.is_use_blt_region)
    {
        mmi_vdorec_merge_blt_rgn(
            g_vdorec_osd_cntx.panel.progress_bar.offset_x, 
            g_vdorec_osd_cntx.panel.progress_bar.offset_y, 
            image_width, 
            image_height);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_draw_progress_bar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_draw_panel_progress_bar(U8 ratio)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_offset_x;
    S32 layer_offset_y;
    S32 bar_width;
    S32 bar_height;
    GDI_RESULT tmp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_DRAW_PANEL_PROGRESS_BAR, ratio);

    if (!mmi_vdorec_is_draw_progress_bar())
    {
        return;
    }

    gdi_layer_push_and_set_active(g_vdorec_cntx.progress_draw_layer);

    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

    gdi_image_get_dimension_id(IMG_ID_VDOREC_PROGRESS_FILL, &bar_width, &bar_height);

    /* draw_background */
    tmp = gdi_image_draw_id(g_vdorec_osd_cntx.panel.progress_bar.offset_x - layer_offset_x,
                      g_vdorec_osd_cntx.panel.progress_bar.offset_y - layer_offset_y,
                      IMG_ID_VDOREC_PROGRESS_EMPTY);
    /* set clip, draw fill progress */
    if (ratio != 0)
    {
        gdi_layer_push_clip();
        gdi_layer_set_clip(
            g_vdorec_osd_cntx.panel.progress_bar.offset_x - layer_offset_x,
            g_vdorec_osd_cntx.panel.progress_bar.offset_y - layer_offset_y,
            g_vdorec_osd_cntx.panel.progress_bar.offset_x - layer_offset_x + bar_width * ratio / 100,
            g_vdorec_osd_cntx.panel.progress_bar.offset_y - layer_offset_y + bar_height);
        gdi_image_draw_id(
            g_vdorec_osd_cntx.panel.progress_bar.offset_x - layer_offset_x,
            g_vdorec_osd_cntx.panel.progress_bar.offset_y - layer_offset_y,
            IMG_ID_VDOREC_PROGRESS_FILL);
        gdi_layer_pop_clip();
    }

    gdi_layer_pop_and_restore_active();

    if (g_vdorec_cntx.is_use_blt_region)
    {
        mmi_vdorec_merge_blt_rgn(
            g_vdorec_osd_cntx.panel.progress_bar.offset_x,
            g_vdorec_osd_cntx.panel.progress_bar.offset_y,
            bar_width * ratio / 100,
            bar_height);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_is_draw_progress_bar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static BOOL mmi_vdorec_is_draw_progress_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret = FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_IS_DRAW_PROGRESS_BAR);

#ifndef __VDOREC_FEATURE_LIMIT_PROGRESS_BAR__
	return ret;
#endif

    if (g_vdorec_cntx.is_ext_req)
     {
         if (g_vdorec_cntx.ext_req_size != 0)
         {
            ret = TRUE;
         }
     }
     else if (g_vdorec_cntx.setting.size_limit != 0)
     {
         ret = TRUE;
     }


     if (g_vdorec_cntx.is_ext_req)
     {
         if (g_vdorec_cntx.ext_rec_time != 0)
         {
             ret = TRUE;
         }
     }
     else if (g_vdorec_cntx.setting.time_limit != 0)
     {
         ret = TRUE;
     }

     return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_is_draw_progress_bar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_vdorec_notify_storage_change_hdlr(U32 notify_flag, void* para)
{
#ifdef __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filepath[FMGR_PATH_BUFFER_SIZE];
    U16 id_scr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_NOTIFY_STORAGE_CHANGE_HDLR);

    switch(notify_flag)
    {
        case MMI_FMGR_NOTIFY_SET_STORAGE_PRE_CHK:
            /* check current storage have unsaved file or not */
            for (id_scr = SCR_ID_VDOREC_APP; id_scr < SCR_ID_VDOREC_END; id_scr++)
            {
                if(IsScreenPresent(id_scr))
                {
                    mmi_vdoply_get_storage_file_path(buf_filepath);            
                    if (mdi_video_rec_has_unsaved_file(buf_filepath))
                    {
                        return FALSE;
                    }
                    break;
                }
            }
            break;
        case MMI_FMGR_NOTIFY_SET_STORAGE:
            /* if vide player is enabled. let video playter change the storage */
        #ifndef __MMI_VIDEO_PLAYER__
            mmi_vdoply_set_storage( (U16)*((S8*)para) );
        #endif /* __MMI_VIDEO_PLAYER__ */
            break;
        default:
            break;
    }
#endif /* __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__ */

    return TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_is_in_bgcall
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_vdorec_is_in_bgcall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_IS_IN_BG_CALL);

#ifdef __MMI_UCM__
    return (BOOL) mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_NO_CSD);
#else
    return (isInCall() && !IsWapCallPresent());
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_delete_all_from_history
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_delete_all_from_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_DELETE_ALL_FROM_HISTORY);

    for (scr_id = SCR_ID_VDOREC_SEND; scr_id >= SCR_ID_VDOREC_APP; scr_id--)
    {
        DeleteScreenIfPresent(scr_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_init_according_to_compile_option
 * DESCRIPTION
 *  init variable according to the compile option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_init_according_to_compile_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_INIT_ACCORDING_COMPILE_OPTION);

	/*get the layer count*/
    g_vdorec_cntx.osd_layer_region_count = VDOREC_OSD_LAYER_COUNT_ONE;
    
#ifdef __VDOREC_FEATURE_MULTI_REGION_LAYER_3__
    g_vdorec_cntx.osd_layer_region_count = VDOREC_OSD_LAYER_COUNT_THREE;
#endif
    
#ifdef __VDOREC_FEATURE_MULTI_REGION_LAYER_4__
    g_vdorec_cntx.osd_layer_region_count = VDOREC_OSD_LAYER_COUNT_FOUR;
#endif
    g_vdorec_cntx.osd_layer_region_handle[0] = 0;
    g_vdorec_cntx.osd_layer_region_handle[1] = 0;
    g_vdorec_cntx.osd_layer_region_handle[2] = 0;
    g_vdorec_cntx.osd_layer_region_handle[3] = 0;

	/*display hint or not*/
#ifdef __VDOREC_FEATURE_HIDE_HINT__
	g_vdorec_osd_cntx.hint.is_show = FALSE;
#endif
	
	/*display timer or not*/
#ifdef __VDOREC_FEATURE_HIDE_TIMER__
	g_vdorec_cntx.is_timer_show = FALSE;
#else
	g_vdorec_cntx.is_timer_show = TRUE;
#endif

#ifdef __VDOREC_FEATURE_ZOOM__
	g_vdorec_cntx.is_zoom_support = MMI_TRUE;
#else
	g_vdorec_cntx.is_zoom_support = MMI_FALSE;
#endif

#ifdef __VDOREC_FEATURE_FAST_ZOOM__
	g_vdorec_cntx.is_fast_zoom_support = MMI_TRUE;
#else
	g_vdorec_cntx.is_fast_zoom_support = MMI_FALSE;
#endif

    g_vdorec_cntx.is_disp_bg_img = MMI_FALSE;
    g_vdorec_cntx.is_disp_bg_img_usint_color = MMI_FALSE;
#if defined(__DIRECT_SENSOR_SUPPORT__) /*do not support layer background, so add background image*/
#if ((LCD_WIDTH == 128) && (LCD_HEIGHT == 128))
    g_vdorec_cntx.is_disp_bg_img = MMI_TRUE;
#endif
#if ((LCD_WIDTH == 128) && (LCD_HEIGHT == 160))
    g_vdorec_cntx.is_disp_bg_img = MMI_TRUE;
#endif
#if ((LCD_WIDTH == 176) && (LCD_HEIGHT == 220))
    g_vdorec_cntx.is_disp_bg_img = MMI_TRUE;
#endif
#if ((LCD_WIDTH == 240) && (LCD_HEIGHT == 320))
    g_vdorec_cntx.is_disp_bg_img_usint_color = MMI_TRUE;
#endif
#endif

#ifdef __VDOREC_ROTATE_OSD_FOR_HW_ROTATOR__
    g_vdorec_cntx.is_use_hw_rotate = MMI_TRUE;
    g_vdorec_cntx.is_use_blt_region = MMI_TRUE;
#ifdef __MDI_VIDEO_HW_ROTATOR_BY_LCD__
    g_vdorec_cntx.is_use_hw_rotate_by_lcd = MMI_TRUE;
#else
    g_vdorec_cntx.is_use_hw_rotate_by_lcd = MMI_FALSE;
#endif
#else
    g_vdorec_cntx.is_use_hw_rotate = MMI_FALSE;
    g_vdorec_cntx.is_use_blt_region = MMI_FALSE;
#endif

#ifdef __VDOREC_PREVIEW_WATCHDOG_TIMEOUT__
    g_vdorec_cntx.is_watchdog_support = MMI_TRUE;
#else
    g_vdorec_cntx.is_watchdog_support = MMI_FALSE;
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_vdorec_get_zoom_level_idx
* DESCRIPTION
*  get zoom level index
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#if 1 /*this is for smooth zoom ,currently not support, but 38 chip will support*/
static U16  mmi_vdorec_get_zoom_level_idx(S32 factor)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_GET_ZOOM_LEVEL_INDEX, factor);

    for (i = 0; i < sizeof(g_vdorec_feature_zoom)/sizeof(g_vdorec_feature_zoom[0]); i++)
    {
        if (g_vdorec_feature_zoom[i] == factor)
        {
            return i;
        }
    }
	
    return g_vdorec_cntx.setting.zoom;
}
#endif


/*****************************************************************************
* FUNCTION
*  mmi_vdorec_draw_zoom_osd
* DESCRIPTION
*  draw zoom osd
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_vdorec_draw_zoom_osd(void)
{
#ifdef __VDOREC_FEATURE_FAST_ZOOM__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_DRAW_ZOOM_OSD);

    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_ZOOM);
    mmi_vdorec_blt_screen();
    
    if (g_vdorec_cntx.is_fast_zoom)
    {
        gui_start_timer(VDOREC_INC_INTERVAL_FIRST, mmi_vdorec_draw_zoom_osd);
    }
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_vdorec_start_fast_zoom_in
* DESCRIPTION
*  start fast zoom in
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_vdorec_start_fast_zoom_in(void)
{
#ifdef __VDOREC_FEATURE_FAST_ZOOM__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_START_FAST_ZOOM_IN);

	g_vdorec_cntx.is_fast_zoom = TRUE;
    gui_start_timer(VDOREC_INC_INTERVAL, mmi_vdorec_draw_zoom_osd);
    mdi_camera_start_fast_zoom(TRUE, (U8) g_vdorec_cntx.zoom_limit, 1, 1);
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_vdorec_start_fast_zoom_out
* DESCRIPTION
*  start fast zoom out
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_vdorec_start_fast_zoom_out(void)
{
#ifdef __VDOREC_FEATURE_FAST_ZOOM__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_START_FAST_ZOOM_OUT);
    g_vdorec_cntx.is_fast_zoom = MMI_TRUE;
    gui_start_timer(VDOREC_INC_INTERVAL, mmi_vdorec_draw_zoom_osd);
    mdi_camera_start_fast_zoom(FALSE, (U8) g_vdorec_cntx.zoom_limit, 1, 1);
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_vdorec_stop_fast_zoom
* DESCRIPTION
*  stop the fast zoom
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_vdorec_stop_fast_zoom(void)
{
#ifdef __VDOREC_FEATURE_FAST_ZOOM__
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 current_idx;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_STOP_FAST_ZOOM);

    mdi_camera_stop_fast_zoom();

    /*need update the zoom factor*/
    if (g_vdorec_cntx.is_fast_zoom_support && g_vdorec_cntx.is_fast_zoom)
    {
        mdi_camera_get_fast_zoom_factor(&current_idx);
        current_idx = mmi_vdorec_get_zoom_level_idx(current_idx);
        
        g_vdorec_cntx.setting.zoom = current_idx;
    }
    g_vdorec_cntx.is_fast_zoom = MMI_FALSE;
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_mscr_merge_blt_rgn
* DESCRIPTION
*  merge blt region
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
static  void mmi_vdorec_merge_blt_rgn(S32 x, S32 y, S32 w, S32 h)
{
#ifdef __VDOREC_ROTATE_OSD_FOR_HW_ROTATOR__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    S32 x2, y2, real_x = 0, real_y = 0, real_w = 0, real_h = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_MERGE_BLT_REGION_BEFORE, x, y, w, h);

    if (x < 0)
    {
        x = 0;
    }
    if (y < 0)
    {
        y = 0;
    }

    if (g_vdorec_cntx.is_use_hw_rotate)
    {
        real_x = g_vdorec_cntx.lcd_width - h - y;
        real_y = x;
        real_w = h;
        real_h = w;
    }

    if (g_vdorec_cntx.blt_area_w == 0 || g_vdorec_cntx.blt_area_h == 0)
    {
        mmi_vdorec_set_merge_region(real_x, real_y, real_w, real_h);
        return;
    }
    x2 = g_vdorec_cntx.blt_area_x + g_vdorec_cntx.blt_area_w;
    y2 = g_vdorec_cntx.blt_area_y + g_vdorec_cntx.blt_area_h;
    
    if (g_vdorec_cntx.blt_area_x > real_x)
    {
        g_vdorec_cntx.blt_area_x = real_x;
    }
    if (g_vdorec_cntx.blt_area_y > real_y)
    {
        g_vdorec_cntx.blt_area_y = real_y;
    }
    if (x2 < real_x + real_w)
    {
        x2 = real_x + real_w;
    }
    if (y2 < real_y + real_h)
    {
        y2 = real_y + real_h;
    }  
    g_vdorec_cntx.blt_area_w = x2 - g_vdorec_cntx.blt_area_x;
    g_vdorec_cntx.blt_area_h = y2 - g_vdorec_cntx.blt_area_y;

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_MERGE_BLT_REGION_AFTER, 
        g_vdorec_cntx.blt_area_x, g_vdorec_cntx.blt_area_y, g_vdorec_cntx.blt_area_w, g_vdorec_cntx.blt_area_h);
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_vdorec_set_merge_region
* DESCRIPTION
*  set the blt area
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_vdorec_set_merge_region(S32 x, S32 y, S32 w, S32 h)
{
#ifdef __VDOREC_ROTATE_OSD_FOR_HW_ROTATOR__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_SET_BLT_REGION, x, y, w, h);

    g_vdorec_cntx.blt_area_x = x;
    g_vdorec_cntx.blt_area_y = y;
    g_vdorec_cntx.blt_area_w = w;
    g_vdorec_cntx.blt_area_h = h;
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_vdorec_pre_key_listen_hdlr
* DESCRIPTION
*  use pre key to stop watch dog
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static U8 mmi_vdorec_pre_key_listen_hdlr(KEYBRD_MESSAGE *key_msg)
{
#ifdef __VDOREC_PREVIEW_WATCHDOG_TIMEOUT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_PRE_KEY_LISTEN_HDLR);

    mmi_vdorec_reset_watchdog_time_out_handler();
#endif

    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  mmi_vdorec_post_key_listen_hdlr
* DESCRIPTION
*  use post key to restore watch dog
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static U8 mmi_vdorec_post_key_listen_hdlr(KEYBRD_MESSAGE *key_msg)
{
#ifdef __VDOREC_PREVIEW_WATCHDOG_TIMEOUT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_POST_KEY_LISTEN_HDLR);

    mmi_vdorec_reset_watchdog_time_out_handler();
    mmi_vdorec_watchdog_time_out_handler();
#endif

    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  mmi_vdorec_reset_watchdog_time_out_handler
* DESCRIPTION
*  reset watch dog
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_vdorec_reset_watchdog_time_out_handler(void)
{
#ifdef __VDOREC_PREVIEW_WATCHDOG_TIMEOUT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_RESET_WATCHDOG);

    gui_cancel_timer(mmi_vdorec_watchdog_time_out_handler);
    g_vdorec_cntx.watchdog_listen_duration = 0;
#endif /* __VDOREC_PREVIEW_WATCHDOG_TIMEOUT__ */ 
}


/*****************************************************************************
* FUNCTION
*  mmi_bcr_watchdog_time_out_handler
* DESCRIPTION
*  watch dog listen handler
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_vdorec_watchdog_time_out_handler(void)
{
#ifdef __VDOREC_PREVIEW_WATCHDOG_TIMEOUT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_START_WATCH_DOG);

    if (g_vdorec_cntx.state != VDOREC_STATE_PREVIEW)
    {
        /*if you start watch dog when vdorec is not in preview state, will give no response*/
        return;
    }

    if (g_vdorec_cntx.watchdog_listen_duration < MMI_VDOREC_WATCHDOG_TIMEOUT_DUR_MAX/MMI_VDOREC_WATCHDOG_TIMEOUT_DUR_INTERVAL)
    {
        g_vdorec_cntx.watchdog_listen_duration++;
        gui_start_timer(MMI_VDOREC_WATCHDOG_TIMEOUT_DUR_INTERVAL, mmi_vdorec_watchdog_time_out_handler);
    }
    else
    {
        if (GetActiveScreenId() == SCR_ID_VDOREC_APP)
        {
            GoBackHistory();
        }
    }
#endif /* __VDOREC_PREVIEW_WATCHDOG_TIMEOUT__ */ 
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_to_mms_hdlr
 * DESCRIPTION
 *  mms forward handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_to_mms_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_TO_MMS_HDLR);

#ifdef __MMI_VDOREC_MMS_SUPPORT__
    mms_content_insert_hdlr(g_vdorec_cntx.filepath);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_highlight_to_mms
 * DESCRIPTION
 *  mms forward hilighte handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_highlight_to_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_HIGHLIGHT_TO_MMS);

    SetLeftSoftkeyFunction(mmi_vdorec_to_mms_hdlr, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdorec_to_mms_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


#ifdef __MMI_VDOREC_EMAIL_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_highlight_to_email
 * DESCRIPTION
 *  mms forward hilighte handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_to_email_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_OP11_CAMERA_VDOREC_CUSTOMIZE__    
    mmi_email_app_send_param_struct email_param;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_TO_EMAIL_HDLR);

#ifdef __MMI_OP11_CAMERA_VDOREC_CUSTOMIZE__
    mmi_email_app_send_attch_to_addr(g_vdorec_cntx.filepath);
#else /* __MMI_OP11_CAMERA_VDOREC_CUSTOMIZE__ */
    mmi_email_app_send_init_param_to_null(&email_param);
    email_param.attch_file_path = (S8*)g_vdorec_cntx.filepath;
    mmi_email_app_send(&email_param, EMAIL_ATTCH_FILL_FLAG);
#endif /* __MMI_OP11_CAMERA_VDOREC_CUSTOMIZE__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_highlight_to_email
 * DESCRIPTION
 *  mms forward hilighte handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_highlight_to_email(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_HIGHLIGHT_TO_EMAIL);

    SetLeftSoftkeyFunction(mmi_vdorec_to_email_hdlr, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdorec_to_email_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
#endif /*  __MMI_VDOREC_EMAIL_SUPPORT__*/


#ifdef __MMI_BT_SEND_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_to_BT_hdlr
 * DESCRIPTION
 *  to BT hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_to_BT_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    {
        btsend_obj_struct obj;
        btsend_app_struct app;
    
        memset(&obj, 0, sizeof(obj));
        memset(&app, 0, sizeof(app));
    
        obj.data.obj_type = BTSEND_USE_FILE;
        obj.data.u.file.path = (U16 *)g_vdorec_cntx.filepath;
    
        app.id = (U8)APP_VDOREC;
    
#ifdef __MMI_BT_AUTO_PROMPT_SWITCH__
        mmi_bt_send_object(&obj, &app, BTSEND_PROF_ALL, BTSEND_OPT_DEFAULT_DEVICE);
#else        
        mmi_bt_send_object(&obj, &app, BTSEND_PROF_ALL, BTSEND_OPT_NORMAL);
#endif        
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_TO_BT_HDLR);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_highlight_to_bluetooth
 * DESCRIPTION
 *  to BT hilight hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_highlight_to_bluetooth(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_HILIGHT_TO_BLUETOOTH);

    SetLeftSoftkeyFunction(mmi_vdorec_to_BT_hdlr, KEY_EVENT_UP);
    SetKeyHandler(mmi_vdorec_to_BT_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
#endif /* __MMI_BT_SEND_SUPPORT__ */



#endif /* __MMI_VIDEO_RECORDER__ && __MMI_CAMCORDER__ */ 
#endif /* _MMI_VDORECAPP_C */ 

