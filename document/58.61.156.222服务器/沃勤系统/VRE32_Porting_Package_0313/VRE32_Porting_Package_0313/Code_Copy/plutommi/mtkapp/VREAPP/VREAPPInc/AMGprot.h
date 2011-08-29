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
 *  AMGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  AM header file.
 *
 * Author:
 * -------
 *  Keith Chen
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
* $ Log $
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef AM_GPROT_H
#define AM_GPROT_H
/*vogins move this define to here for vre using*/
//#define MMI_AM_USING_VRE_MEM
#define MMI_VRE_ERR_IS_UNAVAILABLE (-1001)

#if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
#define MMI_AM_MAX_DYN_MEM_SIZE    (95*1024)    /* AM:45K + Download:50K */
#elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
#define MMI_AM_MAX_DYN_MEM_SIZE    (117*1024)   /* AM:67K + Download:50K */
#elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
#define MMI_AM_MAX_DYN_MEM_SIZE    (112*1024)   /* AM:62K + Download:50K */
#elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
#define MMI_AM_MAX_DYN_MEM_SIZE    (130*1024)   /* AM:80K + Download:50K */
#elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
#define MMI_AM_MAX_DYN_MEM_SIZE    (167*1024)   /* AM:117K + Download:50K */
#else 
#define MMI_AM_MAX_DYN_MEM_SIZE    (95*1024)    /* AM:45K + Download:50K */
#endif 

/* shortcut id */
typedef enum
{
    APPID_MAINMENU = 0, /* main menu shortcut id */
    APPID_VAS,          /* appstore shortcut id */
    APPID_BH,			 /* Bubble Hunter id */
    APPID_MYLIVE,		 		/* mylive Hunter id */
    APPID_TSF,			 /* Top-secret Flights id */
    APPID_MT,			 /* Magic Tower id */
    APPID_PW,			 /* Princess Wall id */
    APPID_BA,			 /* Brave Adventure id */
    APPID_FMS,			 /* fly magic story id */
    APPID_YMD100F,		 /* you man? down 100 floor id */
    APPID_VITTER,		 		/* vitter id */
    APPID_MOTALK,		 		/* Motalk id */
    APPID_RAMBO,		 		/* Rambo id */
    APPID_MAGNETICJOE2,		/* Magneticjoe2 id */
    APPID_PENGUINFERVER,      /* penguinfever id */
    APPID_ADVOFBUBBLE,        /* Adventure of Bubble id */
    APPID_RACING,        		/* Racing id */
    APPID_TRANSFORMER,        /* Transformer id */
    APPID_HAPPYBOBBLE,        /* Happy Bobble id */
    APPID_JEEP,        		/* Jeep id */
    APPID_QCS,
    APPID_KRJJH,
    APPID_SGGYZ,
    APPID_SMCL,
    APPID_WULINOL,
    APPID_BXJG,
    APPID_RETURNKING,
    APPID_WORLDWARCRAFT,
    APPID_RADIANTWOLF,
    APPID_QQBROWSER,
    APPID_QQ,
    APPID_KAIXIN,
    APPID_WLOL,
    APPID_MOBILEKK,
    APPID_STOCKSTAR,
    APPID_QQLANDLORD,
    APPID_MSN,
    APPID_FETION,
    APPID_OPERAMINI,
    APPID_BAIDU,
    APPID_OPERA,
    APPID_100TV,
    APPID_AIPIM,
    APPID_LUUTOO,
    APPID_PUSHMAIL,
    APPID_CALCULATOR,   /* calculator */
    APPID_WORLDCLOCK,   /* worldclock */
    
    APPID_MAX
} mmi_am_shortcut_id_enum;

/****************************************************************************
* External Global Function                                                            
*****************************************************************************/
extern void mmi_am_start(void);                 /* start am from main menu */
extern void mmi_am_start_from_fm(U16 *path);    /* start app from file manager */
extern void mmi_am_start_from_hs(U16 *path);    /* start app from home screen */
extern void mmi_am_start_from_mm(mmi_am_shortcut_id_enum appid);        /* start app from main menu */
extern void mmi_am_card_plug_in_hdlr(void);
extern void mmi_am_card_plug_out_hdlr(void);
extern void mmi_am_enter_usb_mode(void);

/* HS-Shortcut Api */
U8 mmi_am_get_shortcut_number(void);
void mmi_am_get_all_shortcut_id(U32 *id_array, U32 size);      /* #id in id_array. Memory is provided by HS. */

/* icon_file memory is offered by hs */
void mmi_am_get_shortcut_icon(
        U32 icon_id,
        U16 *icon_file,
        /* UCS2 string. Memory should be provided by HS. */ U32 size);

                                                                                                /* #characters in the buffer. */

void mmi_am_launch_shortcut(U32 icon_id);
void mmi_am_read_shorcut_record(void);
void mmi_am_init(void);

/* For VRE Core */
extern U16 mmi_am_get_status_bar_icon_resid(U16 *app_name);
extern U16 mmi_am_get_status_bar_icon_resid_by_appid(U32 app_id);
extern MMI_BOOL mmi_am_app_update(U32 app_id, U16 *app_name);

/* For Video Recorder App */
extern S32 mmi_am_is_using_media_memory(void);
extern void mmi_am_media_memory_unavailable_popup(void);
extern U16 mmi_am_get_error_info(S32 error_result, S32* popup_type);
/*Vogins_20100625_start*/
extern void mmi_am_restart();
/*Vogins_20100625_end*/

#endif /* AM_GPROT_H */ 

