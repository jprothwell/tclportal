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
 *   AMConfig.c
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   AM Configration Src
 *
 * Author:
 * -------
 *  Keith Chen
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __VRE30_AM__

/***************************************************************************** 
* Include header files
*****************************************************************************/
#ifdef __VRE_AM_08AB__
#include "MMI_include.h"
#include "MMIDataType.h"
#else
#include "MMI_frm_gprot.h"
#endif
#include "gui_typedef.h"

#include "AMDef.h"
#include "AMConfig.h"
#include "AMResDef.h"

#include "StatusIconRes.h"

/***************************************************************************** 
* Variable
*****************************************************************************/
extern mmi_am_cntx_struct g_am_cntx;
extern U8 AM_App_Default[];

#ifdef MMI_AM_SC_APP_AS
extern U8 AM_App_AS[];
#endif 
#ifdef MMI_AM_SC_APP_QCS
extern U8 AM_App_QCS[];
#endif 
#ifdef MMI_AM_SC_APP_KRJJH
extern U8 AM_App_Krjjh[];
#endif 
#ifdef MMI_AM_SC_APP_SGGYZ
extern U8 AM_App_Sggyz[];
#endif 
#ifdef MMI_AM_SC_APP_SMCL
extern U8 AM_App_Smcl[];
#endif 
#ifdef MMI_AM_SC_APP_WULINOL
extern U8 AM_App_WuLinol[];
#endif 
#ifdef MMI_AM_SC_APP_BXJG
extern U8 AM_App_Bxjg[];
#endif 
#ifdef MMI_AM_SC_APP_RETURNKING
extern U8 AM_App_RetrunKing[];
#endif 
#ifdef MMI_AM_SC_APP_WORLDWARCRAFT
extern U8 AM_App_WorldWarcraft[];
#endif 
#ifdef MMI_AM_SC_APP_RADIANTWOLF
extern U8 AM_App_RadiantWolf[];
#endif
#ifdef MMI_AM_SC_APP_QQBROWSER
extern U8 AM_App_QQBrowser[];
#endif 
#ifdef MMI_AM_SC_APP_QQ
extern U8 AM_App_QQ2009[];
#endif 
#ifdef MMI_AM_SC_APP_KAIXIN
extern U8 AM_App_KaiXin[];
#endif 
#ifdef MMI_AM_SC_APP_WLOL
extern U8 AM_App_WLOL[];
#endif 
#ifdef MMI_AM_SC_APP_MOBILEKK
extern U8 AM_App_MobileKK[];
#endif 
#ifdef MMI_AM_SC_APP_STOCKSTAR
extern U8 AM_App_StockStar[];
#endif 
#ifdef MMI_AM_SC_APP_FETION
extern U8 AM_App_Fetion[];
#endif 
#ifdef MMI_AM_SC_APP_QQLANDLORD
extern U8 AM_App_QQLandlord[];
#endif 
#ifdef MMI_AM_SC_APP_MSN
extern U8 AM_App_MSN[];
#endif 
#ifdef MMI_AM_SC_APP_FETION
extern U8 AM_App_Fetion[];
#endif 
#ifdef MMI_AM_SC_APP_OPERAMINI
extern U8 AM_App_OperaMini[];
#endif
#ifdef MMI_AM_SC_APP_BAIDU
extern U8 AM_App_Baidu[];
#endif
#ifdef MMI_AM_SC_APP_OPERA
extern U8 AM_App_Opera[];
#endif 
#ifdef MMI_AM_SC_APP_100TV
extern U8 AM_App_100TV[];
#endif 
#ifdef MMI_AM_SC_APP_AIPIM
extern U8 AM_App_AIPIM[];
#endif 
#ifdef MMI_AM_SC_APP_LUUTOO
extern U8 AM_App_Luutoo[];
#endif 
#ifdef MMI_AM_SC_APP_SHANGMAIL
extern U8 AM_App_Shangmail[];
#endif 
#ifdef MMI_AM_SC_APP_BH
extern U8 AM_App_BH[];
#endif
#ifdef MMI_AM_SC_APP_MYLIVE
extern U8 AM_App_MYLIVE[];
#endif
#ifdef MMI_AM_SC_APP_TSF
extern U8 AM_App_TSF[];
#endif  
#ifdef MMI_AM_SC_APP_MT
extern U8 AM_App_MT[];
#endif
#ifdef MMI_AM_SC_APP_PW
extern U8 AM_App_PW[];
#endif 
#ifdef MMI_AM_SC_APP_BA
extern U8 AM_App_BA[];
#endif
#ifdef MMI_AM_SC_APP_FMS
extern U8 AM_App_FMS[];
#endif 
#ifdef MMI_AM_SC_APP_YMD100F
extern U8 AM_App_YMD100F[];
#endif 
#ifdef MMI_AM_SC_APP_VITTER
extern U8 AM_App_VITTER[];
#endif
#ifdef MMI_AM_SC_APP_MOTALK
extern U8 AM_App_MOTALK[];
#endif
#ifdef MMI_AM_SC_APP_RAMBO
extern U8 AM_App_RAMBO[];
#endif
#ifdef MMI_AM_SC_APP_MAGNETICJOE2
extern U8 AM_App_MAGNETICJOE2[];
#endif
#ifdef MMI_AM_SC_APP_PENGUINFERVER
extern U8 AM_App_PENGUINFERVER[];
#endif
#ifdef MMI_AM_SC_APP_ADVOFBUBBLE
extern U8 AM_App_ADVOFBUBBLE[];
#endif
#ifdef MMI_AM_SC_APP_RACING
extern U8 AM_App_RACING[];
#endif
#ifdef MMI_AM_SC_APP_TRANSFORMER
extern U8 AM_App_TRANSFORMER[];
#endif
#ifdef MMI_AM_SC_APP_HAPPYBOBBLE
extern U8 AM_App_HAPPYBOBBLE[];
#endif
#ifdef MMI_AM_SC_APP_JEEP
extern U8 AM_App_JEEP[];
#endif
#define AM_APP_AS_SIZE 427
#define AM_APP_QCS_SIZE 203
#define AM_APP_KRJJH_SIZE 439
#define AM_APP_SGGYZ_SIZE 439
#define AM_APP_SMCL_SIZE 423
#define AM_APP_WULINOL_SIZE 351
#define AM_APP_BXJG_SIZE 363
#define AM_APP_RETURNKING_SIZE 655
#define AM_APP_WORLDWARCRAFT_SIZE 643
#define AM_APP_RADIANTWOLF_SIZE 735
#define AM_APP_QQBROWSER_SIZE 447
#define AM_APP_QQ2009_SIZE 347
#define AM_APP_KAIXIN_SIZE 335
#define AM_APP_WLOL_SIZE 351
#define AM_APP_MOBILEKK_SIZE 351
#define AM_APP_STOCKSTAR_SIZE 443
#define AM_APP_FETION_SIZE 275
#define AM_APP_QQLANDLORD_SIZE 463
#define AM_APP_MSN_SIZE 203
#define AM_APP_FETION_SIZE 275
#define AM_APP_OPERAMINI_SIZE 491
#define AM_APP_BAIDU_SIZE 259
#define AM_APP_OPERA_SIZE 491
#define AM_APP_100TV_SIZE 299
#define AM_APP_AIPIM_SIZE 439
#define AM_APP_LUUTOO_SIZE 275
#define AM_APP_SHANGMAIL_SIZE 323
#define AM_APP_AS_SIZE 427

#define AM_APP_AS_SIZE 				427
#define AM_APP_BH_SIZE 				683
#define AM_APP_MYLIVE_SIZE 			347
#define AM_APP_TSF_SIZE 				923
#define AM_APP_MT_SIZE 				587
#define AM_APP_PW_SIZE 				683
#define AM_APP_BA_SIZE 				779
#define AM_APP_FMS_SIZE 				779
#define AM_APP_YMD100F_SIZE 			1115
#define AM_APP_VITTER_SIZE 			347
#define AM_APP_MOTALK_SIZE 			347
#define AM_APP_RAMBO_SIZE 			299
#define AM_APP_MAGNETICJOE2_SIZE 	635
#define AM_APP_PENGUINFERVER_SIZE 	635
#define AM_APP_ADVOFBUBBLE_SIZE 		971
#define AM_APP_RACING_SIZE 			347
#define AM_APP_TRANSFORMER_SIZE 		587
#define AM_APP_HAPPYBOBBLE_SIZE 		635
#define AM_APP_JEEP_SIZE 				251


/* main menu shortcut app list */
static mmi_am_shortcut_info_struct mm_shortcut_info_list[] = 
{
    /* main menu shortcut, the following just a sample */
    {APPID_VAS,
     IMG_ID_AM_APP_AS,      /* icon resource id */
     0,
     STR_ID_AM_APP_NAME_AS, /* name resource id */
     AM_App_AS,             /* name pointer */
     AM_APP_AS_SIZE,        /* name size */
     0x00010000,
     MMI_AM_AS_FILE_NAME
    }

#if defined(__MMI_VRE_CALCULATOR__)
    ,
    /* calculator */
    {
    APPID_CALCULATOR,           /* app id */
    0x00,                       /* app icon resource id */
    0x00,                       /* app status bar icon id */
    0x00,                       /* app name resource id */
    NULL,                       /* app name pointer */
    0x00,                       /* app name size */
    0x001100B3,                 /* app download id */
                                /* app file name */
#if (!defined(__MMI_FTE_SUPPORT__))
#if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
    "calculator_qc.vxp"
#elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
    "calculator_qv.vxp"
#elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
    "calculator_qv_ls.vxp"
#elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
    "calculator_wq.vxp"
#elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
    "calculator_hv.vxp"
#else
    NULL
#endif
#else   /* __MMI_FTE_SUPPORT__ */
#if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
    "calculator_qc_fte.vxp"
#elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
    "calculator_qv_fte.vxp"
#elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
    "calculator_qv_ls_fte.vxp"
#elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
    "calculator_wq_fte.vxp"
#elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
    "calculator_hv_fte.vxp"
#else
    NULL
#endif
#endif  /* __MMI_FTE_SUPPORT__ */
    }
#endif  /* __MMI_VRE_CALCULATOR__ */

#if defined(__MMI_VRE_WORLD_CLOCK__)
    ,
    /* worldclock */
    {
    APPID_WORLDCLOCK,           /* app id */
    0x00,                       /* app icon resource id */
    0x00,                       /* app status bar icon id */
    0x00,                       /* app name resource id */
    NULL,                       /* app name pointer */
    0x00,                       /* app name size */
    0x001100B4,                 /* app download id */
                                /* app file name */
#if (!defined(__MMI_FTE_SUPPORT__))
#if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
    "worldclock_qc.vxp"
#elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
    "worldclock_qv.vxp"
#elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
    "worldclock_qv_ls.vxp"
#elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
    "worldclock_wq.vxp"
#elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
    "worldclock_hv.vxp"
#else
    NULL
#endif
#else   /* __MMI_FTE_SUPPORT__ */
#if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
    "worldclock_qc_fte.vxp"
#elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
    "worldclock_qv_fte.vxp"
#elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
    "worldclock_qv_ls_fte.vxp"
#elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
    "worldclock_wq_fte.vxp"
#elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
    "worldclock_hv_fte.vxp"
#else
    NULL
#endif
#endif  /* __MMI_FTE_SUPPORT__ */
    }
#endif  /* __MMI_VRE_WORLD_CLOCK__ */
};

/* am shortcut app list */
static mmi_am_shortcut_info_struct am_shortcut_info_list[] = 
{
#ifdef MMI_AM_SC_APP_AS
    /* appstore */
    {APPID_VAS,
     IMG_ID_AM_APP_AS,      /* icon resource id */
     0,
     STR_ID_AM_APP_NAME_AS, /* name resource id */
     AM_App_AS,             /* name pointer */
     AM_APP_AS_SIZE,        /* name size */
     0x00010000,
     MMI_AM_AS_FILE_NAME}
#endif /* MMI_AM_SC_APP_AS */ 

/*added by hendy*/
 #ifdef MMI_AM_SC_APP_QCS
    
    ,/* QCS */
    {APPID_QCS,
     IMG_ID_AM_APP_QCS,      /* icon resource id */
     IMG_SI_VRE_DEFAULT,
     STR_ID_AM_APP_NAME_QCS, /* name resource id */
     AM_App_QCS,         /* name pointer */
     AM_APP_QCS_SIZE,    /* name size */
     3670238,
    #if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
     "qcs-qc.vxp"
    #elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
     "qcs-qv.vxp"
    #elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
     "qcs-qv-ls.vxp"
    #elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
     "qcs-wq.vxp"
    #elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
     "qcs-hv.vxp"
    #else 
     NULL
    #endif 
     }
 #endif /* MMI_AM_SC_APP_QCS */ 
#ifdef MMI_AM_SC_APP_KRJJH
    
    ,/* KRJJH */
    {APPID_KRJJH,
     IMG_ID_AM_APP_KRJJH,      /* icon resource id */
     IMG_SI_VRE_DEFAULT,
     STR_ID_AM_APP_NAME_KRJJH, /* name resource id */
     AM_App_Krjjh,         /* name pointer */
     AM_APP_KRJJH_SIZE,    /* name size */
     1900750,
    #if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
     "krjjh-qc.vxp"
    #elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
     "krjjh-qv.vxp"
    #elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
     "krjjh-qv-ls.vxp"
    #elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
     "krjjh-wq.vxp"
    #elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
     "krjjh-hv.vxp"
    #else 
     NULL
    #endif 
     }
 #endif /* MMI_AM_SC_APP_KRJJH */ 
 #ifdef MMI_AM_SC_APP_SGGYZ
    
    ,/* SGGYZ */
    {APPID_SGGYZ,
     IMG_ID_AM_APP_SGGYZ,      /* icon resource id */
     IMG_SI_VRE_DEFAULT,
     STR_ID_AM_APP_NAME_SGGYZ, /* name resource id */
     AM_App_Sggyz,         /* name pointer */
     AM_APP_SGGYZ_SIZE,    /* name size */
     1900749,
    #if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
     "sggyz-qc.vxp"
    #elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
     "sggyz-qv.vxp"
    #elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
     "sggyz-qv-ls.vxp"
    #elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
     "sggyz-wq.vxp"
    #elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
     "sggyz-hv.vxp"
    #else 
     NULL
    #endif 
     }
 #endif /* MMI_AM_SC_APP_SGGYZ */ 
 #ifdef MMI_AM_SC_APP_SMCL
    
    ,/* SMCL */
    {APPID_SMCL,
     IMG_ID_AM_APP_SMCL,      /* icon resource id */
     IMG_SI_VRE_DEFAULT,
     STR_ID_AM_APP_NAME_SMCL, /* name resource id */
     AM_App_Smcl,         /* name pointer */
     AM_APP_SMCL_SIZE,    /* name size */
     2621592,
    #if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
     "smcl-qc.vxp"
    #elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
     "smcl-qv.vxp"
    #elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
     "smcl-qv-ls.vxp"
    #elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
     "smcl-wq.vxp"
    #elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
     "smcl-hv.vxp"
    #else 
     NULL
    #endif 
     }
 #endif /* MMI_AM_SC_APP_SMCL */ 
 #ifdef MMI_AM_SC_APP_WULINOL
    
    ,/* WULINOL */
    {APPID_WULINOL,
     IMG_ID_AM_APP_WULINOL,      /* icon resource id */
     IMG_SI_VRE_DEFAULT,
     STR_ID_AM_APP_NAME_WULINOL, /* name resource id */
     AM_App_WuLinol,         /* name pointer */
     AM_APP_WULINOL_SIZE,    /* name size */
     3276983,
    #if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
     "wulinol-qc.vxp"
    #elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
     "wulinol-qv.vxp"
    #elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
     "wulinol-qv-ls.vxp"
    #elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
     "wulinol-wq.vxp"
    #elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
     "wulinol-hv.vxp"
    #else 
     NULL
    #endif 
     }
 #endif /* MMI_AM_SC_APP_WULINOL */ 
  #ifdef MMI_AM_SC_APP_BXJG
    
    ,/* BXJG */
    {APPID_BXJG,
     IMG_ID_AM_APP_BXJG,      /* icon resource id */
     IMG_SI_VRE_DEFAULT,
     STR_ID_AM_APP_NAME_BXJG, /* name resource id */
     AM_App_Bxjg,         /* name pointer */
     AM_APP_BXJG_SIZE,    /* name size */
     721034,
    #if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
     "bxjg-qc.vxp"
    #elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
     "bxjg-qv.vxp"
    #elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
     "bxjg-qv-ls.vxp"
    #elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
     "bxjg-wq.vxp"
    #elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
     "bxjg-hv.vxp"
    #else 
     NULL
    #endif 
     }
 #endif /* MMI_AM_SC_APP_BXJG */ 
 #ifdef MMI_AM_SC_APP_RETURNKING
	,/* RETURNKING */
    {APPID_RETURNKING,
     IMG_ID_AM_APP_RETURNKING,        /* icon resource id */
     IMG_SI_VRE_DEFAULT,
     STR_ID_AM_APP_NAME_RETURNKING,   /* name resource id */
     AM_App_RetrunKing,              /* name pointer */
     AM_APP_RETURNKING_SIZE,         /* name size */
     852109,
    #if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
     "mtwz-qc.vxp"
    #elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
     "mtwz-qv.vxp"
    #elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
     "mtwz-qv-ls.vxp"
    #elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
     "mtwz-wq.vxp"
    #elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
     "mtwz-hv.vxp"
    #else 
     NULL
    #endif 
     }
#endif 
#ifdef MMI_AM_SC_APP_WORLDWARCRAFT
	,/* WORLDWARCRAFT */
 	{APPID_WORLDWARCRAFT,
     IMG_ID_AM_APP_WORLDWARCRAFT,        /* icon resource id */
     IMG_SI_VRE_DEFAULT,
     STR_ID_AM_APP_NAME_WORLDWARCRAFT,   /* name resource id */
     AM_App_WorldWarcraft,              /* name pointer */
     AM_APP_WORLDWARCRAFT_SIZE,         /* name size */
     720960,
    #if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
     "mspt1-qc.vxp"
    #elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
     "mspt1-qv.vxp"
    #elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
     "mspt1-qv-ls.vxp"
    #elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
     "mspt1-wq.vxp"
    #elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
     "mspt1-hv.vxp"
    #else 
     NULL
    #endif 
     }
#endif 
#ifdef MMI_AM_SC_APP_RADIANTWOLF
    
    ,/* RADIANTWOLF */
    {APPID_RADIANTWOLF,
     IMG_ID_AM_APP_RADIANTWOLF,      /* icon resource id */
     IMG_SI_VRE_DEFAULT,
     STR_ID_AM_APP_NAME_RADIANTWOLF, /* name resource id */
     AM_App_RadiantWolf,         /* name pointer */
     AM_APP_RADIANTWOLF_SIZE,    /* name size */
     721026,
    #if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
     "radiantwolf-qc.vxp"
    #elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
     "radiantwolf-qv.vxp"
    #elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
     "radiantwolf-qv-ls.vxp"
    #elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
     "radiantwolf-wq.vxp"
    #elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
     "radiantwolf-hv.vxp"
    #else 
     NULL
    #endif 
     }
 #endif /* MMI_AM_SC_APP_RADIANTWOLF */ 
 #ifdef MMI_AM_SC_APP_QQBROWSER
    
    ,/* QQ Browser */
    {APPID_QQBROWSER,
     IMG_ID_AM_APP_QQBROWSER,       /* icon resource id */
     IMG_SI_VRE_DEFAULT,
     STR_ID_AM_APP_NAME_QQBROWSER,  /* name resource id */
     AM_App_QQBrowser,              /* name pointer */
     AM_APP_QQBROWSER_SIZE,         /* name size */
     2687131,
    #if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
     "QQBrowser-qc.vxp"
    #elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
     "QQBrowser-qv.vxp"
    #elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
     "QQBrowser-qv-ls.vxp"
    #elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
     "QQBrowser-wq.vxp"
    #elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
     "QQBrowser-hv.vxp"
    #else 
     NULL
    #endif 
     }
 #endif /* MMI_AM_SC_APP_QQBROWSER */ 
 #ifdef MMI_AM_SC_APP_QQ
    
    ,/* QQ */
    {APPID_QQ,
     IMG_ID_AM_APP_QQ,      /* icon resource id */
     IMG_SI_VRE_QQ,	/*specially for backward compatibility*/
     STR_ID_AM_APP_NAME_QQ, /* name resource id */
     AM_App_QQ2009,         /* name pointer */
     AM_APP_QQ2009_SIZE,    /* name size */
     2687133,
    #if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
     "qq2009-qc.vxp"
    #elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
     "qq2009-qv.vxp"
    #elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
     "qq2009-qv-ls.vxp"
    #elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
     "qq2009-wq.vxp"
    #elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
     "qq2009-hv.vxp"
    #else 
     NULL
    #endif 
     }
 #endif /* MMI_AM_SC_APP_QQ */ 
 #ifdef MMI_AM_SC_APP_KAIXIN
	,/* KAIXIN */
	{APPID_KAIXIN,
     IMG_ID_AM_APP_KAIXIN,        /* icon resource id */
     IMG_SI_VRE_DEFAULT,
     STR_ID_AM_APP_NAME_KAIXIN,   /* name resource id */
     AM_App_KaiXin,              /* name pointer */
     AM_APP_KAIXIN_SIZE,         /* name size */
     3539159,
    #if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
    "kaixin-qc.vxp"
    #elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
     "kaixin-qv.vxp"
    #elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
     "kaixin-qv-ls.vxp"
    #elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
     "kaixin-wq.vxp"
    #elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
     "kaixin-hv.vxp"
    #else 
     NULL
    #endif 
     }
#endif /* MMI_AM_SC_APP_KAIXIN */ 

 #ifdef MMI_AM_SC_APP_WLOL
    ,
    /* WulinOL */
    {APPID_WLOL,
     IMG_ID_AM_APP_WLOL,        /* icon resource id */
     IMG_SI_VRE_DEFAULT,
     STR_ID_AM_APP_NAME_WLOL,   /* name resource id */
     AM_App_WLOL,               /* name pointer */
     AM_APP_WLOL_SIZE,          /* name size */
     3276983,
    #if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
     "wlol-qc.vxp"
    #elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
     "wlol-qv.vxp"
    #elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
     "wlol-qv-ls.vxp"
    #elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
     "wlol-wq.vxp"
    #elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
     "wlol-hv.vxp"
    #else 
     NULL
    #endif 
     }
 #endif /* MMI_AM_SC_APP_WLOL */ 

 #ifdef MMI_AM_SC_APP_MOBILEKK
    ,
    /* MobileKK */
    {APPID_MOBILEKK,
     IMG_ID_AM_APP_MOBILEKK,        /* icon resource id */
     IMG_SI_VRE_DEFAULT,
     STR_ID_AM_APP_NAME_MOBILEKK,   /* name resource id */
     AM_App_MobileKK,               /* name pointer */
     AM_APP_MOBILEKK_SIZE,          /* name size */
     3408071,
    #if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
     "MobileKK-qc.vxp"
    #elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
     "MobileKK-qv.vxp"
    #elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
     "MobileKK-qv-ls.vxp"
    #elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
     "MobileKK-wq.vxp"
    #elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
     "MobileKK-hv.vxp"
    #else 
     NULL
    #endif 
     }
 #endif /* MMI_AM_SC_APP_MOBILEKK */ 

 #ifdef MMI_AM_SC_APP_STOCKSTAR
    ,
    /* Stock star */
    {APPID_STOCKSTAR,
     IMG_ID_AM_APP_STOCKSTAR,       /* icon resource id */
     IMG_SI_VRE_DEFAULT,
     STR_ID_AM_APP_NAME_STOCKSTAR,  /* name resource id */
     AM_App_StockStar,              /* name pointer */
     AM_APP_STOCKSTAR_SIZE,         /* name size */
     3014817,
    #if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
     "zqzx-qc.vxp"
    #elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
     "zqzx-qv.vxp"
    #elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
     "zqzx-qv-ls.vxp"
    #elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
     "zqzx-wq.vxp"
    #elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
     "zqzx-hv.vxp"
    #else 
     NULL
    #endif 
     }
 #endif /* MMI_AM_SC_APP_STOCKSTAR */ 



 #ifdef MMI_AM_SC_APP_QQLANDLORD
    ,
    /* QQ Landlord */
    {APPID_QQLANDLORD,
     IMG_ID_AM_APP_QQLANDLORD,      /* icon resource id */
     IMG_SI_VRE_DEFAULT,
     STR_ID_AM_APP_NAME_QQLANDLORD, /* name resource id */
     AM_App_QQLandlord,             /* name pointer */
     AM_APP_QQLANDLORD_SIZE,        /* name size */
     2687141,
    #if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
     "QQddz-qc.vxp"
    #elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
     "QQddz-qv.vxp"
    #elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
     "QQddz-qv-ls.vxp"
    #elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
     "QQddz-wq.vxp"
    #elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
     "QQddz-hv.vxp"
    #else 
     NULL
    #endif 
     }
 #endif /* MMI_AM_SC_APP_QQLANDLORD */ 

 #ifdef MMI_AM_SC_APP_MSN
    ,/* MSN */
    {APPID_MSN,
     IMG_ID_AM_APP_MSN,         /* icon resource id */
     IMG_SI_VRE_MSN,	/*specially for backward compatibility*/
     STR_ID_AM_APP_NAME_MSN,    /* name resource id */
     AM_App_MSN,                /* name pointer */
     AM_APP_MSN_SIZE,           /* name size */
     2752670,
    #if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
     "msn-qc.vxp"
    #elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
     "msn-qv.vxp"
    #elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
     "msn-qv-ls.vxp"
    #elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
     "msn-wq.vxp"
    #elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
     "msn-hv.vxp"
    #else 
     NULL
    #endif 
     }
 #endif /* MMI_AM_SC_APP_MSN */ 

 #ifdef MMI_AM_SC_APP_FETION
    ,/* FETION */
    {APPID_FETION,
     IMG_ID_AM_APP_FETION,      /* icon resource id */
     IMG_SI_VRE_FETION,
     STR_ID_AM_APP_NAME_FETION, /* name resource id */
     AM_App_Fetion,             /* name pointer */
     AM_APP_FETION_SIZE,        /* name size */
     1835135,
    #if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
     "fetion-qc.vxp"
    #elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
     "fetion-qv.vxp"
    #elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
     "fetion-qv-ls.vxp"
    #elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
     "fetion-wq.vxp"
    #elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
     "fetion-hv.vxp"
    #else 
     NULL
    #endif 
     }
 #endif /* MMI_AM_SC_APP_FETION */ 
 #ifdef MMI_AM_SC_APP_OPERA
    ,
    /* Opera Mini */
    {APPID_OPERA,
     IMG_ID_AM_APP_OPERA,       /* icon resource id */
     IMG_SI_VRE_DEFAULT,
     STR_ID_AM_APP_NAME_OPERA,  /* name resource id */
     AM_App_Opera,              /* name pointer */
     AM_APP_OPERA_SIZE,         /* name size */
     3473610,
    #if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
     "OperaMini-qc.vxp"
    #elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
     "OperaMini-qv.vxp"
    #elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
     "OperaMini-qv-ls.vxp"
    #elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
     "OperaMini-wq.vxp"
    #elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
     "OperaMini-hv.vxp"
    #else 
     NULL
    #endif 
     }
 #endif /* MMI_AM_SC_APP_OPERA */ 

  #ifdef MMI_AM_SC_APP_OPERAMINI
    ,/* OPERAMINI */
    {APPID_OPERAMINI,
     IMG_ID_AM_APP_OPERAMINI,         /* icon resource id */
     IMG_SI_VRE_DEFAULT,
     STR_ID_AM_APP_NAME_OPERAMINI,    /* name resource id */
     AM_App_OperaMini,                /* name pointer */
     AM_APP_OPERAMINI_SIZE,           /* name size */
     3473610,
    #if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
     "operamini-qc.vxp"
    #elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
     "operamini-qv.vxp"
    #elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
     "operamini-qv-ls.vxp"
    #elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
     "operamini-wq.vxp"
    #elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
     "operamini-hv.vxp"
    #else 
     NULL
    #endif 
     }
 #endif /* MMI_AM_SC_APP_OPERAMINI */ 

     #ifdef MMI_AM_SC_APP_BAIDU
    ,/* BAIDU */
    {APPID_BAIDU,
     IMG_ID_AM_APP_BAIDU,         /* icon resource id */
     IMG_SI_VRE_DEFAULT,
     STR_ID_AM_APP_NAME_BAIDU,    /* name resource id */
     AM_App_Baidu,                /* name pointer */
     AM_APP_BAIDU_SIZE,           /* name size */
     1638524,
    #if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
     "baidu-qc.vxp"
    #elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
     "baidu-qv.vxp"
    #elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
     "baidu-qv-ls.vxp"
    #elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
     "baidu-wq.vxp"
    #elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
     "baidu-hv.vxp"
    #else 
     NULL
    #endif 
     }
 #endif /* MMI_AM_SC_APP_BAIDU */ 
 #ifdef MMI_AM_SC_APP_100TV
    ,
    /* 100TV */
    {APPID_100TV,
     IMG_ID_AM_APP_100TV,       /* icon resource id */
     IMG_SI_VRE_DEFAULT,
     STR_ID_AM_APP_NAME_100TV,  /* name resource id */
     AM_App_100TV,              /* name pointer */
     AM_APP_100TV_SIZE,         /* name size */
     3211448,
    #if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
     "100tv-qc.vxp"
    #elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
     "100tv-qv.vxp"
    #elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
     "100tv-qv-ls.vxp"
    #elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
     "100tv-wq.vxp"
    #elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
     "100tv-hv.vxp"
    #else 
     NULL
    #endif 
     }
 #endif /* MMI_AM_SC_APP_100TV */ 

 #ifdef MMI_AM_SC_APP_AIPIM
    ,
    /* AIPIM */
    {APPID_AIPIM,
     IMG_ID_AM_APP_AIPIM,       /* icon resource id */
     IMG_SI_VRE_DEFAULT,
     STR_ID_AM_APP_NAME_AIPIM,  /* name resource id */
     AM_App_AIPIM,              /* name pointer */
     AM_APP_AIPIM_SIZE,         /* name size */
     3145914,
    #if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
     "AIPIM-qc.vxp"
    #elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
     "AIPIM-qv.vxp"
    #elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
     "AIPIM-qv-ls.vxp"
    #elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
     "AIPIM-wq.vxp"
    #elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
     "AIPIM-hv.vxp"
    #else 
     NULL
    #endif 
     }
 #endif /* MMI_AM_SC_APP_AIPIM */ 

 #ifdef MMI_AM_SC_APP_LUUTOO
    ,
    /* Luutoo */
    {APPID_LUUTOO,
     IMG_ID_AM_APP_LUUTOO,      /* icon resource id */
     IMG_SI_VRE_DEFAULT,
     STR_ID_AM_APP_NAME_LUUTOO, /* name resource id */
     AM_App_Luutoo,             /* name pointer */
     AM_APP_LUUTOO_SIZE,        /* name size */
     2883765,
    #if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
     "luutoo-qc.vxp"
    #elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
     "luutoo-qv.vxp"
    #elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
     "luutoo-qv-ls.vxp"
    #elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
     "luutoo-wq.vxp"
    #elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
     "luutoo-hv.vxp"
    #else 
     NULL
    #endif 
     }
 #endif /* MMI_AM_SC_APP_LUUTOO */ 

 #ifdef MMI_AM_SC_APP_SHANGMAIL
    ,
    /* Pushmail */
    {APPID_PUSHMAIL,
     IMG_ID_AM_APP_PUSHMAIL,        /* icon resource id */
     IMG_SI_VRE_PUSHMAIL,	/*specially for backward compatibility*/
     STR_ID_AM_APP_NAME_PUSHMAIL,   /* name resource id */
     AM_App_Shangmail,              /* name pointer */
     AM_APP_SHANGMAIL_SIZE,         /* name size */
     1769598,
    #if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
     "pushmail-qc.vxp"
    #elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
     "pushmail-qv.vxp"
    #elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
     "pushmail-qv-ls.vxp"
    #elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
     "pushmail-wq.vxp"
    #elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
     "pushmail-hv.vxp"
    #else 
     NULL
    #endif 
     },
 #endif /* MMI_AM_SC_APP_SHANGMAIL */ 
 #ifdef MMI_AM_SC_APP_BH
    
    ,/* Bubble Hunter */
    {APPID_BH,
     IMG_ID_AM_APP_BH,      /* icon resource id */
     IMG_SI_VRE_DEFAULT,
     STR_ID_AM_APP_NAME_BH, /* name resource id */
     AM_App_BH,         /* name pointer */
     AM_APP_BH_SIZE,    /* name size */
     131080,
    #if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
     "BubbleHunter-qc.vxp"
    #elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
     "BubbleHunter-qv.vxp"
    #elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
     "BubbleHunter-qv-ls.vxp"
    #elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
     "BubbleHunter-wq.vxp"
    #elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
     "BubbleHunter-hv.vxp"
    #else 
     NULL
    #endif 
     }
 #endif /* MMI_AM_SC_APP_BH */ 
  #ifdef MMI_AM_SC_APP_MYLIVE
    
    ,/* Mylive */
    {APPID_MYLIVE,
     IMG_ID_AM_APP_MYLIVE,      /* icon resource id */
     IMG_SI_VRE_DEFAULT,
     STR_ID_AM_APP_NAME_MYLIVE, /* name resource id */
     AM_App_MYLIVE,         /* name pointer */
     AM_APP_MYLIVE_SIZE,    /* name size */
     393245,
    #if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
     "mylive-qc.vxp"
    #elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
     "mylive-qv.vxp"
    #elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
     "mylive-qv-ls.vxp"
    #elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
     "mylive-wq.vxp"
    #elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
     "mylive-hv.vxp"
    #else 
     NULL
    #endif 
     }
 #endif /* MMI_AM_SC_APP_MYLIVE */ 

 #ifdef MMI_AM_SC_APP_TSF
    
    ,/* Top-secret Flights */
    {APPID_TSF,
     IMG_ID_AM_APP_TSF,      /* icon resource id */
     IMG_SI_VRE_DEFAULT,
     STR_ID_AM_APP_NAME_TSF, /* name resource id */
     AM_App_TSF,         /* name pointer */
     AM_APP_TSF_SIZE,    /* name size */
     196614,
    #if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
     "TopSecretFlights-qc.vxp"
    #elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
     "TopSecretFlights-qv.vxp"
    #elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
     "TopSecretFlights-qv-ls.vxp"
    #elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
     "TopSecretFlights-wq.vxp"
    #elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
     "TopSecretFlights-hv.vxp"
    #else 
     NULL
    #endif 
     }
 #endif /* MMI_AM_SC_APP_TSF */ 
 #ifdef MMI_AM_SC_APP_MT
    
    ,/* Magic Tower */
    {APPID_MT,
     IMG_ID_AM_APP_MT,      /* icon resource id */
     IMG_SI_VRE_DEFAULT,
     STR_ID_AM_APP_NAME_MT, /* name resource id */
     AM_App_MT,         /* name pointer */
     AM_APP_MT_SIZE,    /* name size */
     131073,
    #if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
     "MagicTower-qc.vxp"
    #elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
     "MagicTower-qv.vxp"
    #elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
     "MagicTower-qv-ls.vxp"
    #elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
     "MagicTower-wq.vxp"
    #elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
     "MagicTower-hv.vxp"
    #else 
     NULL
    #endif 
     }
 #endif /* MMI_AM_SC_APP_MT */ 
 #ifdef MMI_AM_SC_APP_PW   
    ,/* Princess Wall */
    {APPID_PW,
     IMG_ID_AM_APP_PW,      /* icon resource id */
     IMG_SI_VRE_DEFAULT,
     STR_ID_AM_APP_NAME_PW, /* name resource id */
     AM_App_PW,         /* name pointer */
     AM_APP_PW_SIZE,    /* name size */
     131075,
    #if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
     "PrincessWall-qc.vxp"
    #elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
     "PrincessWall-qv.vxp"
    #elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
     "PrincessWall-qv-ls.vxp"
    #elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
     "PrincessWall-wq.vxp"
    #elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
     "PrincessWall-hv.vxp"
    #else 
     NULL
    #endif 
     }
 #endif /* MMI_AM_SC_APP_PW */ 
  #ifdef MMI_AM_SC_APP_BA
    
    ,/* Brave Adventure */
    {APPID_BA,
     IMG_ID_AM_APP_BA,      /* icon resource id */
     IMG_SI_VRE_DEFAULT,
     STR_ID_AM_APP_NAME_BA, /* name resource id */
     AM_App_BA,         /* name pointer */
     AM_APP_BA_SIZE,    /* name size */
     196612,
    #if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
     "BraveAdventure-qc.vxp"
    #elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
     "BraveAdventure-qv.vxp"
    #elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
     "BraveAdventure-qv-ls.vxp"
    #elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
     "BraveAdventure-wq.vxp"
    #elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
     "BraveAdventure-hv.vxp"
    #else 
     NULL
    #endif 
     }
 #endif /* MMI_AM_SC_APP_BA */ 
  #ifdef MMI_AM_SC_APP_FMS
	,/* Fly Magic Story */
    {APPID_FMS,
     IMG_ID_AM_APP_FMS,        /* icon resource id */
     IMG_SI_VRE_DEFAULT,
     STR_ID_AM_APP_NAME_FMS,   /* name resource id */
     AM_App_FMS,              /* name pointer */
     AM_APP_FMS_SIZE,         /* name size */
     262153,
    #if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
     "FlyMagicStory-qc.vxp"
    #elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
     "FlyMagicStory-qv.vxp"
    #elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
     "FlyMagicStory-qv-ls.vxp"
    #elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
     "FlyMagicStory-wq.vxp"
    #elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
     "FlyMagicStory-hv.vxp"
    #else 
     NULL
    #endif 
     }
#endif /* MMI_AM_SC_APP_FMS */ 
  #ifdef MMI_AM_SC_APP_YMD100F
    
    ,/* you man? down 100 floor */
    {APPID_YMD100F,
     IMG_ID_AM_APP_YMD100F,      /* icon resource id */
     IMG_SI_VRE_DEFAULT,
     STR_ID_AM_APP_NAME_YMD100F, /* name resource id */
     AM_App_YMD100F,         /* name pointer */
     AM_APP_YMD100F_SIZE,    /* name size */
     327687,
    #if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
     "YMD100F-qc.vxp"
    #elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
     "YMD100F-qv.vxp"
    #elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
     "YMD100F-qv-ls.vxp"
    #elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
     "YMD100F-wq.vxp"
    #elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
     "YMD100F-hv.vxp"
    #else 
     NULL
    #endif 
     }
 #endif /* MMI_AM_SC_APP_YMD100F */ 
 #ifdef MMI_AM_SC_APP_VITTER
	,/* Vitter */
    {APPID_VITTER,
     IMG_ID_AM_APP_VITTER,        /* icon resource id */
     IMG_SI_VRE_DEFAULT,
     STR_ID_AM_APP_NAME_VITTER,   /* name resource id */
     AM_App_VITTER,              /* name pointer */
     AM_APP_VITTER_SIZE,         /* name size */
     655403,
    #if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
     "vitter-qc.vxp"
    #elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
     "vitter-qv.vxp"
    #elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
     "vitter-qv-ls.vxp"
    #elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
     "vitter-wq.vxp"
    #elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
     "vitter-hv.vxp"
    #else 
     NULL
    #endif 
     }
#endif /* MMI_AM_SC_APP_VITTER */ 

 #ifdef MMI_AM_SC_APP_MOTALK
	,/* Motalk */
    {APPID_MOTALK,
     IMG_ID_AM_APP_MOTALK,        /* icon resource id */
     IMG_SI_VRE_DEFAULT,
     STR_ID_AM_APP_NAME_MOTALK,   /* name resource id */
     AM_App_MOTALK,              /* name pointer */
     AM_APP_MOTALK_SIZE,         /* name size */
     655405,
    #if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
     "motalk-qc.vxp"
    #elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
     "motalk-qv.vxp"
    #elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
     "motalk-qv-ls.vxp"
    #elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
     "motalk-wq.vxp"
    #elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
     "motalk-hv.vxp"
    #else 
     NULL
    #endif 
     }
#endif /* MMI_AM_SC_APP_MOTALK */ 

 #ifdef MMI_AM_SC_APP_RAMBO
	,/* Rambo */
    {APPID_RAMBO,
     IMG_ID_AM_APP_RAMBO,        /* icon resource id */
     IMG_SI_VRE_DEFAULT,
     STR_ID_AM_APP_NAME_RAMBO,   /* name resource id */
     AM_App_RAMBO,              /* name pointer */
     AM_APP_RAMBO_SIZE,         /* name size */
     852019,
    #if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
     "rambo-qc.vxp"
    #elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
     "rambo-qv.vxp"
    #elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
     "rambo-qv-ls.vxp"
    #elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
     "rambo-wq.vxp"
    #elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
     "rambo-hv.vxp"
    #else 
     NULL
    #endif 
     }
#endif /* MMI_AM_SC_APP_RAMBO */ 

 #ifdef MMI_AM_SC_APP_MAGNETICJOE2
	,/* Magneticjoe2 */
    {APPID_MAGNETICJOE2,
     IMG_ID_AM_APP_MAGNETICJOE2,        /* icon resource id */
     IMG_SI_VRE_DEFAULT,
     STR_ID_AM_APP_NAME_MAGNETICJOE2,   /* name resource id */
     AM_App_MAGNETICJOE2,              /* name pointer */
     AM_APP_MAGNETICJOE2_SIZE,         /* name size */
     852020,
    #if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
     "magneticjoe2-qc.vxp"
    #elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
     "magneticjoe2-qv.vxp"
    #elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
     "magneticjoe2-qv-ls.vxp"
    #elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
     "magneticjoe2-wq.vxp"
    #elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
     "magneticjoe2-hv.vxp"
    #else 
     NULL
    #endif 
     }
#endif /* MMI_AM_SC_APP_MAGNETICJOE2 */ 

 #ifdef MMI_AM_SC_APP_PENGUINFERVER
	,/* Penguinferver */
    {APPID_PENGUINFERVER,
     IMG_ID_AM_APP_PENGUINFERVER,        /* icon resource id */
     IMG_SI_VRE_DEFAULT,
     STR_ID_AM_APP_NAME_PENGUINFERVER,   /* name resource id */
     AM_App_PENGUINFERVER,              /* name pointer */
     AM_APP_PENGUINFERVER_SIZE,         /* name size */
     852022,
    #if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
     "penguinferver-qc.vxp"
    #elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
     "penguinferver-qv.vxp"
    #elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
     "penguinferver-qv-ls.vxp"
    #elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
     "penguinferver-wq.vxp"
    #elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
     "penguinferver-hv.vxp"
    #else 
     NULL
    #endif 
     }
#endif /* MMI_AM_SC_APP_PENGUINFERVER */ 

 #ifdef MMI_AM_SC_APP_ADVOFBUBBLE
	,/* Adventure of Bubble */
    {APPID_ADVOFBUBBLE,
     IMG_ID_AM_APP_ADVOFBUBBLE,        /* icon resource id */
     IMG_SI_VRE_DEFAULT,
     STR_ID_AM_APP_NAME_ADVOFBUBBLE,   /* name resource id */
     AM_App_ADVOFBUBBLE,              /* name pointer */
     AM_APP_ADVOFBUBBLE_SIZE,         /* name size */
     852023,
    #if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
     "adventureofbubble-qc.vxp"
    #elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
     "adventureofbubble-qv.vxp"
    #elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
     "adventureofbubble-qv-ls.vxp"
    #elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
     "adventureofbubble-wq.vxp"
    #elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
     "adventureofbubble-hv.vxp"
    #else 
     NULL
    #endif 
     }
#endif /* MMI_AM_SC_APP_ADVOFBUBBLE */ 

 #ifdef MMI_AM_SC_APP_RACING
	,/* Racing */
    {APPID_RACING,
     IMG_ID_AM_APP_RACING,        /* icon resource id */
     IMG_SI_VRE_DEFAULT,
     STR_ID_AM_APP_NAME_RACING,   /* name resource id */
     AM_App_RACING,              /* name pointer */
     AM_APP_RACING_SIZE,         /* name size */
     720942,
    #if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
     "racing-qc.vxp"
    #elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
     "racing-qv.vxp"
    #elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
     "racing-qv-ls.vxp"
    #elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
     "racing-wq.vxp"
    #elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
     "racing-hv.vxp"
    #else 
     NULL
    #endif 
     }
#endif /* MMI_AM_SC_APP_RACING */ 

 #ifdef MMI_AM_SC_APP_TRANSFORMER
	,/* Transformer */
    {APPID_TRANSFORMER,
     IMG_ID_AM_APP_TRANSFORMER,        /* icon resource id */
     IMG_SI_VRE_DEFAULT,
     STR_ID_AM_APP_NAME_TRANSFORMER,   /* name resource id */
     AM_App_TRANSFORMER,              /* name pointer */
     AM_APP_TRANSFORMER_SIZE,         /* name size */
     720944,
    #if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
     "transformer-qc.vxp"
    #elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
     "transformer-qv.vxp"
    #elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
     "transformer-qv-ls.vxp"
    #elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
     "transformer-wq.vxp"
    #elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
     "transformer-hv.vxp"
    #else 
     NULL
    #endif 
     }
#endif /* MMI_AM_SC_APP_TRANSFORMER */ 

 #ifdef MMI_AM_SC_APP_HAPPYBOBBLE
	,/* Happy Bobble */
    {APPID_HAPPYBOBBLE,
     IMG_ID_AM_APP_HAPPYBOBBLE,        /* icon resource id */
     IMG_SI_VRE_DEFAULT,
     STR_ID_AM_APP_NAME_HAPPYBOBBLE,   /* name resource id */
     AM_App_HAPPYBOBBLE,              /* name pointer */
     AM_APP_HAPPYBOBBLE_SIZE,         /* name size */
     786481,
    #if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
     "happybobble-qc.vxp"
    #elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
     "happybobble-qv.vxp"
    #elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
     "happybobble-qv-ls.vxp"
    #elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
     "happybobble-wq.vxp"
    #elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
     "happybobble-hv.vxp"
    #else 
     NULL
    #endif 
     }
#endif /* MMI_AM_SC_APP_HAPPYBOBBLE */ 

 #ifdef MMI_AM_SC_APP_JEEP
	,/* Jeep */
    {APPID_JEEP,
     IMG_ID_AM_APP_JEEP,        /* icon resource id */
     IMG_SI_VRE_DEFAULT,
     STR_ID_AM_APP_NAME_JEEP,   /* name resource id */
     AM_App_JEEP,              /* name pointer */
     AM_APP_JEEP_SIZE,         /* name size */
     786482,
    #if defined(__MMI_MAINLCD_176X220__)    /* QCIF */
     "jeep-qc.vxp"
    #elif defined(__MMI_MAINLCD_240X320__)  /* QVGA */
     "jeep-qv.vxp"
    #elif defined(__MMI_MAINLCD_320X240__)  /* L-QVGA */
     "jeep-qv-ls.vxp"
    #elif defined(__MMI_MAINLCD_240X400__)  /* WQVGA */
     "jeep-wq.vxp"
    #elif defined(__MMI_MAINLCD_320X480__)  /* HVGA */
     "jeep-hv.vxp"
    #else 
     NULL
    #endif 
     }
#endif /* MMI_AM_SC_APP_JEEP */ 
};

static mmi_am_config_ms_struct ms_info = 
{
#ifdef __VRE_AM_08AB__
/* QCIF */
#if defined(__MMI_MAINLCD_176X220__)
    2, 2,
    8, 8, 8, IMG_ID_AM_HIGHLIGHT_SCROLLBAR
#elif defined(__MMI_MAINLCD_220X176__)
    3, 2,
    2, 1, 3, IMG_ID_AM_HIGHLIGHT
        /* QVGA */
#elif defined(__MMI_MAINLCD_240X320__)
#ifdef __MMI_FTE_SUPPORT__
    3, 3,
    5, 5, 4, IMG_ID_AM_HIGHLIGHT_SCROLLBAR
#else /* __MMI_FTE_SUPPORT__ */ 
    3, 3,
    8, 8, 4, IMG_ID_AM_HIGHLIGHT_SCROLLBAR
#endif /* __MMI_FTE_SUPPORT__ */ 
        /* L-QVGA */
#elif defined(__MMI_MAINLCD_320X240__)
    4, 2,
    11, 11, 4, IMG_ID_AM_HIGHLIGHT_SCROLLBAR
        /* WQVGA */
#elif defined(__MMI_MAINLCD_240X400__)
#ifdef __MMI_FTE_SUPPORT__
    3, 4,
    5, 5, 4, IMG_ID_AM_HIGHLIGHT_SCROLLBAR
#else /* __MMI_FTE_SUPPORT__ */ 
    3, 4,
    6, 6, 4, IMG_ID_AM_HIGHLIGHT_SCROLLBAR
#endif /* __MMI_FTE_SUPPORT__ */ 
        /* HVGA */
#elif defined(__MMI_MAINLCD_320X480__)
#ifdef __MMI_FTE_SUPPORT__
    4, 5,
    4, 4, 4, IMG_ID_AM_HIGHLIGHT_SCROLLBAR
#else /* __MMI_FTE_SUPPORT__ */ 
    4, 5,
    6, 6, 4, IMG_ID_AM_HIGHLIGHT_SCROLLBAR
#endif /* __MMI_FTE_SUPPORT__ */ 
#else 
    0, 0,
    0, 0, 0, 0
#endif 
#else  /*AM 08AB define else*/
    /* QCIF */
#if defined(__MMI_MAINLCD_176X220__)
    2, 2,
    8, 8, 8, IMG_ID_AM_HIGHLIGHT
#elif defined(__MMI_MAINLCD_220X176__)
    3, 2,
    2, 1, 3, IMG_ID_AM_HIGHLIGHT
        /* QVGA */
#elif defined(__MMI_MAINLCD_240X320__)
#ifdef __MMI_FTE_SUPPORT__
    3, 3,
    5, 5, 4, IMG_ID_AM_HIGHLIGHT
#else /* __MMI_FTE_SUPPORT__ */ 
    3, 3,
    8, 8, 4, IMG_ID_AM_HIGHLIGHT
#endif /* __MMI_FTE_SUPPORT__ */ 
        /* L-QVGA */
#elif defined(__MMI_MAINLCD_320X240__)
    4, 2,
    11, 11, 4, IMG_ID_AM_HIGHLIGHT
        /* WQVGA */
#elif defined(__MMI_MAINLCD_240X400__)
#ifdef __MMI_FTE_SUPPORT__
    3, 4,
    5, 5, 4, IMG_ID_AM_HIGHLIGHT
#else /* __MMI_FTE_SUPPORT__ */ 
    3, 4,
    6, 6, 4, IMG_ID_AM_HIGHLIGHT
#endif /* __MMI_FTE_SUPPORT__ */ 
        /* HVGA */
#elif defined(__MMI_MAINLCD_320X480__)
#ifdef __MMI_FTE_SUPPORT__
    4, 5,
    4, 4, 4, IMG_ID_AM_HIGHLIGHT
#else /* __MMI_FTE_SUPPORT__ */ 
    4, 5,
    6, 6, 4, IMG_ID_AM_HIGHLIGHT
#endif /* __MMI_FTE_SUPPORT__ */ 
#else 
    0, 0,
    0, 0, 0, 0
#endif 
#endif /*AM08AB define*/
};


/*****************************************************************************
 * FUNCTION
 *  mmi_am_config_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_config_init(void)
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
 *  mmi_am_config_get_am_sc_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_am_config_get_am_sc_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return sizeof(am_shortcut_info_list) / sizeof(mmi_am_shortcut_info_struct);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_config_get_am_sc_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mmi_am_shortcut_info_struct *mmi_am_config_get_am_sc_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return am_shortcut_info_list;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_config_get_am_sc_info_by_appid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  appid       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mmi_am_shortcut_info_struct *mmi_am_config_get_am_sc_info_by_appid(mmi_am_shortcut_id_enum appid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < mmi_am_config_get_am_sc_num(); i++)
    {
        if (am_shortcut_info_list[i].app_id == appid)
        {
            return &am_shortcut_info_list[i];
        }
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_config_get_am_sc_name_by_appid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  appid       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S8 *mmi_am_config_get_am_sc_name_by_appid(mmi_am_shortcut_id_enum appid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_am_shortcut_info_struct *p = mmi_am_config_get_am_sc_info_by_appid(appid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!p)
    {
        return NULL;
    }
    else
    {
        return p->file_name;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_config_get_am_sc_name_by_idx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S8 *mmi_am_config_get_am_sc_name_by_idx(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return am_shortcut_info_list[idx].file_name;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_config_get_mm_sc_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_am_config_get_mm_sc_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return sizeof(mm_shortcut_info_list) / sizeof(mmi_am_shortcut_info_struct);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_config_get_mm_sc_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mmi_am_shortcut_info_struct *mmi_am_config_get_mm_sc_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mm_shortcut_info_list;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_config_get_mm_sc_info_by_appid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  appid       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mmi_am_shortcut_info_struct *mmi_am_config_get_mm_sc_info_by_appid(mmi_am_shortcut_id_enum appid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < mmi_am_config_get_mm_sc_num(); i++)
    {
        if (mm_shortcut_info_list[i].app_id == appid)
        {
            return &mm_shortcut_info_list[i];
        }
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_config_get_mm_sc_name_by_appid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  appid       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S8 *mmi_am_config_get_mm_sc_name_by_appid(mmi_am_shortcut_id_enum appid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_am_shortcut_info_struct *p = mmi_am_config_get_mm_sc_info_by_appid(appid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!p)
    {
        return NULL;
    }
    else
    {
        return p->file_name;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_config_is_shortcut_app
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_name        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_am_config_is_shortcut_app(U16 *app_name, S8 dir)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    U16 shortcut_app_name[MMI_AM_MAX_SHORTCUT_APP_FILE_PATH];
		U16 shortcut_app_name_e[MMI_AM_MAX_SHORTCUT_APP_FILE_PATH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_config_is_shortcut_app  ------------------[S]"); 
    /* check AM Shortcut app list */
    for (i = 0; i < mmi_am_config_get_am_sc_num(); i++)
    {
        memset(shortcut_app_name, 0, sizeof(shortcut_app_name));
        mmi_asc_to_wcs(shortcut_app_name, am_shortcut_info_list[i].file_name);

        if (mmi_wcsicmp(app_name, shortcut_app_name) == 0)
        {
        	MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_config_is_shortcut_app  find in am_shortcut_info_list------"); 
					/*vogins_20100728_start*/
					if(i == 0)
						return MMI_TRUE;
					/*vogins_20100728_end*/
	    		for (j = 0; j < mmi_am_config_get_am_sc_num(); j++)
	    		{
							if(am_shortcut_info_list[i].icon_id == g_am_cntx.shortcut_app_list[j].icon_id)
							{
								MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_config_is_shortcut_app  find in g_am_cntx.shortcut_app_list------"); 
								if(g_am_cntx.shortcut_app_list[j].is_downloaded && dir != ((S8)(*(g_am_cntx.shortcut_app_list[j].path))))
									return MMI_FALSE;
								else
									return MMI_TRUE;
							}
	        }
        }
    }

    /* check Main Menu Shortcut app list */
#ifndef __VRE_AM_08AB__
    for (i = 0; i < mmi_am_config_get_mm_sc_num(); i++)
    {
        memset(shortcut_app_name, 0, sizeof(shortcut_app_name));
        mmi_asc_to_wcs(shortcut_app_name, mm_shortcut_info_list[i].file_name);

        if (mmi_wcsicmp(app_name, shortcut_app_name) == 0)
        {
            return MMI_TRUE;
        }
    }
#endif
	MMI_AM_LOG(MOD_MMI, TRACE_GROUP_1, "mmi_am_config_is_shortcut_app  ------------------[E]"); 
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_config_get_ms_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mmi_am_config_ms_struct *mmi_am_config_get_ms_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 num_of_one_screen;
    S32 num_of_items;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    num_of_one_screen = ms_info.app_num_per_col * ms_info.app_num_per_row;
    num_of_items = sml_list_size(g_am_cntx.vxp_file_list) + g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num;

    /* have scroll bar? */
#ifdef __VRE_AM_08AB__
    ms_info.hl_icon_id = IMG_ID_AM_HIGHLIGHT_SCROLLBAR;
#else
    if (num_of_items > num_of_one_screen)
    {
        ms_info.hl_icon_id = IMG_ID_AM_HIGHLIGHT_SCROLLBAR;
    }
#endif
    return &ms_info;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_config_update_ms_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_am_config_update_ms_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 num_of_one_screen;
    S32 num_of_items;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    num_of_one_screen = ms_info.app_num_per_col * ms_info.app_num_per_row;
    num_of_items = sml_list_size(g_am_cntx.vxp_file_list) + g_am_cntx.shortcut_app_num + g_am_cntx.rom_app_num;

    /* have scroll bar? */
#ifdef __VRE_AM_08AB__
    ms_info.hl_icon_id = IMG_ID_AM_HIGHLIGHT_SCROLLBAR;
#else
    if (num_of_items > num_of_one_screen)
    {
        ms_info.hl_icon_id = IMG_ID_AM_HIGHLIGHT_SCROLLBAR;
    }
    else
    {
        ms_info.hl_icon_id = IMG_ID_AM_HIGHLIGHT;
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_config_get_status_bar_resid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_name        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_am_config_get_status_bar_resid(U16 *app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U16 sc_app_name[MMI_AM_MAX_SHORTCUT_APP_NAME];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < mmi_am_config_get_am_sc_num(); i++)
    {
        memset(sc_app_name, 0, sizeof(sc_app_name));
        mmi_asc_to_wcs(sc_app_name, am_shortcut_info_list[i].file_name);
        if (mmi_wcsicmp(app_name, sc_app_name) == 0)
        {
            return am_shortcut_info_list[i].status_bar_image_id;
        }
    }

    return IMG_SI_VRE_DEFAULT;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_config_get_status_bar_resid_by_appid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_am_config_get_status_bar_resid_by_appid(U32 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < mmi_am_config_get_am_sc_num(); i++)
    {
        if (am_shortcut_info_list[i].dl_app_id == app_id)
        {
            return am_shortcut_info_list[i].status_bar_image_id;
        }
    }

    return IMG_SI_VRE_DEFAULT;
}

#endif /* __VRE30_AM__ */ 

