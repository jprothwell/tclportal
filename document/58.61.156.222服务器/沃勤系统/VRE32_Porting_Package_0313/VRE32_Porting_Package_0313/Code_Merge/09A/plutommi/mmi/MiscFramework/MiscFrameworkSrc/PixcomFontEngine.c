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
 *    pixcomfontengine.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   font engine related function calls
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
*  Include
*****************************************************************************/
#include "MMI_include.h"
#include "gdi_mutex.h"
#include <signal.h>
#include "FontData.h"

#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)

#include "MTKPropFont20.h"
#if defined(__MMI_ZI__)

#if defined(__MMI_ZI_V7__)
#include "ZiV7ExtraCharacter20.h"
#else 
#include "ZiExtraCharacter20.h"
#endif 

#endif /* defined(__MMI_ZI__) */ 

#else /* __MMI_MAINLCD_240X320__ */ 

#include "MTKPropFont.h"
#if defined(__MMI_ZI__)
#if defined(__MMI_ZI_V7__)
#include "ZiV7ExtraCharacter14.h"
#else 
#include "ZiExtraCharacter.h"
#endif 
#endif /* defined(__MMI_ZI__) */ 

#endif /* __MMI_MAINLCD_240X320__ */ 

#include "PixcomFontEngine.h"

/* For Langauge */
#ifdef __MMI_INDIC_ALG__
#include "IndicEngineGprot.h"
#endif /* __MMI_INDIC_ALG__ */ 


#include "LangModuleGProt.h"

#include "BIDIDEF.h"
#include "BIDIGProt.h"



#include "ATHandlerProt.h"
#include "SSCStringHandle.h"
#include "BIDIDEF.h"
#include "BIDIGProt.h"
#include "Gdi_font.h"
#include "med_utility.h"

/*****************************************************************************
*  Define
*****************************************************************************/
#define FONTENGINE_IRAM_PLACEMENT   0
#define BORDERED_TEXT_NO_BOUNDARY 1     /* MTK justin */

/* transparent color (blue) */
#define TRANSPARENT_COLOR_R 0
#define TRANSPARENT_COLOR_G 0
#define TRANSPARENT_COLOR_B 0xff
#define FE_DISPLAY_FLAG_DATE_CHAR  0x01
#define FE_DISPLAY_FLAG_PROPRIETARY_SYMBOL_CHAR  0x02
#define FE_DISPLAY_FLAG_UCS2_PROPRIETARY 0x04
#define FE_UCS2_PROPRIETARY_START 0xE000
#define FE_UCS2_PROPRIETARY_END 0xF8FF

#ifndef max
#define max(a,b)        (((a) > (b)) ? (a) : (b))
#endif
#ifndef min
#define min(a,b)        (((a) < (b)) ? (a) : (b))
#endif

/*****************************************************************************
*  Typedef
*****************************************************************************/
typedef struct
{
    S32 x;
    S32 y; 
    S32 char_gap;
    U8 *String;
    S32 len;
    U32 BaseLineHeight;
    U32 Bordered;
    MMI_BOOL enable_truncated;
    U8 *truncated_symbol;
    S32 truncated_symbol_start;
    S32 visible_x_start;
    S32 visible_x_end;
    gdi_color border_color; 
    gdi_color text_color;
    U32 render_flag;
    S32 max_ascent;
    S32 max_descent;
    U8 assign_direction;
    S32 clip_x1;
    S32 clip_x2;
    S32 clip_y1;
    S32 clip_y2;
}mmi_fe_showstring_int_param_struct, *mmi_fe_showstring_int_param_struct_p;



typedef enum
{
    MMI_FE_LANG_OTHERS,
    MMI_FE_LANG_INDIC,
    MMI_FE_LANG_THAI,
    MMI_FE_LANG_ARABIC,
    MMI_FE_LANG_NONE
}mmi_fe_lang_id;

typedef enum
{
    MMI_FE_INFO_ONLY,
    MMI_FE_GET_DATA,
    MMI_FE_VALID_CHECK,
    MMI_FE_GLYPH_INDEX
} mmi_fe_font_query_type;

typedef U32 (*mmi_fe_show_string_func)(mmi_fe_showstring_int_param_struct_p param);
typedef U32 (*mmi_fe_get_string_width_height_func)(mmi_fe_get_string_info_param_struct_p param);


/*****************************************************************************
*  Global Variables
*****************************************************************************/
U8 gnCurrentFontAttrib = FONTATTRIB_NORMAL;
U8 gbFontType = 0;
static U32 fe_display_flag = 0;
static gdi_mutex_struct g_mmi_fe_cache_mutex;
BOOL cancelWidth = 0;

static mmi_fe_color g_mmi_fe_text_color = {0, 0, 0, 100};
static mmi_fe_color g_mmi_fe_text_border_color = {0, 0, 0, 100};


#if defined(__MMI_VECTOR_FONT_SUPPORT__)
#define FE_LOCK gdi_mutex_lock(&g_mmi_fe_cache_mutex)
#define FE_UNLOCK gdi_mutex_unlock(&g_mmi_fe_cache_mutex)
#else
#define FE_LOCK 
#define FE_UNLOCK
#endif

/* extern sLanguageDetails gLanguageArray[MAX_LANGUAGES]; */
extern sLanguageDetails *gLanguageArray;


extern BOOL r2lMMIFlag;

#ifdef __MMI_BIDI_ALG__
extern U8 MMI_bidi_input_type;
U16 show_pwcWord[MAX_SHOW_STRING_TEXT_LENGTH];
U8 show_visual_str[MAX_SHOW_STRING_TEXT_LENGTH * BIDI_ENCODING_LENGTH];
#endif /* __MMI_BIDI_ALG__ */ 
#ifdef __MMI_ARSHAPING_ENGINE__
static U16 fe_ShaToOrg[MAX_SHOW_STRING_TEXT_LENGTH];
#endif 


#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
extern MMI_BOOL mmi_trace_screen_string(S32 x, S32 y, U8 *str, S32 len, S32 Bordered);
extern MMI_BOOL mmi_trace_screen_char(S32 x, S32 y, U16 unicode, S32 len, S32 Bordered);
#endif


/* For Font Cache */
CharHashTable charHashTableLatin[LATIN_CHAR_HT_SIZE];
CharHashTable charHashTableOthers[OTHERS_CHAR_HT_SIZE];

#if defined(__MMI_MAINLCD_320X480__)
const RangeData gMTKProprietaryFont_RangeData[55]={
{2,2},
{108,108},
{133,134},
{331,331},
{593,593},
{596,596},
{601,603},
{609,609},
{618,618},
{643,643},
{650,650},
{652,652},
{658,658},
{711,711},
{714,716},
{719,719},
{729,729},
{731,731},
{768,769},
{771,771},
{780,780},
{7735,7735},
{7747,7747},
{7751,7751},
{8208,8208},
{8210,8213},
{8216,8223},
{8230,8231},
{8242,8243},
{8245,8246},
{8248,8251},
{8260,8260},
{8364,8364},
{8482,8482},
{8544,8555},
{8560,8571},
{9733,9734},
{12289,12290},
{12298,12303},
{61440,61442},
{61444,61445},
{61447,61447},
{62464,62467},
{62469,62505},
{62720,62725},
{65104,65104},
{65106,65106},
{65108,65111},
{65113,65114},
{65124,65124},
{65281,65374},
{65377,65380},
{65509,65509},
{65515,65515},
{65533,65533},
};

const RangeDetails gMTKProprietaryFont_RangeInfo={
55,
gMTKProprietaryFont_RangeData

};

sCustFontData gMTKProprietaryFont = 
{
20, 20, 17, 3, 0, 50, 500,
(U8 *) MTKProprietaryFont20_Width,
(U8 *) MTKProprietaryFont20_Width, (U32 *) MTKProprietaryFont20_Offset, (U8 *) MTKProprietaryFont20_Data,
    (U32 *) MTKProprietaryFont20_RangeOffset,
{
{FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH,FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH},
{FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH,FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH},
{FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH,FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH},
{FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH,FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH},
{FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH,FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH},
{FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH,FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH},
{FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH,FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH},
{FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH,FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH},
{FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH,FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH}
},
&gMTKProprietaryFont_RangeInfo
};

#if defined(__MMI_ZI__)

#if defined(__MMI_ZI_V7__)

const RangeData gZiExtraCharacter_RangeData[181] = 
{
    {61184, 61192},
    {61200, 61201},
    {61203, 61203},
    {61206, 61206},
    {61209, 61209},
    {61214, 61214},
    {61217, 61228},
    {61230, 61231},
    {61233, 61238},
    {61243, 61247},
    {61249, 61254},
    {61256, 61256},
    {61259, 61260},
    {61264, 61264},
    {61268, 61270},
    {61274, 61274},
    {61276, 61280},
    {61282, 61282},
    {61287, 61287},
    {61289, 61291},
    {61293, 61293},
    {61295, 61319},
    {61321, 61322},
    {61324, 61330},
    {61332, 61333},
    {61335, 61337},
    {61339, 61339},
    {61342, 61342},
    {61346, 61347},
    {61349, 61352},
    {61354, 61354},
    {61357, 61358},
    {61360, 61360},
    {61364, 61365},
    {61367, 61367},
    {61369, 61371},
    {61373, 61376},
    {61378, 61378},
    {61382, 61384},
    {61386, 61386},
    {61389, 61389},
    {61392, 61393},
    {61396, 61397},
    {61399, 61399},
    {61401, 61403},
    {61406, 61407},
    {61411, 61411},
    {61413, 61416},
    {61418, 61418},
    {61421, 61421},
    {61424, 61424},
    {61427, 61427},
    {61431, 61431},
    {61435, 61435},
    {61437, 61442},
    {61445, 61445},
    {61447, 61448},
    {61450, 61450},
    {61452, 61452},
    {61455, 61461},
    {61464, 61464},
    {61466, 61470},
    {61472, 61474},
    {61477, 61477},
    {61479, 61485},
    {61487, 61487},
    {61491, 61493},
    {61495, 61498},
    {61501, 61502},
    {61504, 61504},
    {61508, 61509},
    {61511, 61517},
    {61523, 61523},
    {61525, 61525},
    {61530, 61530},
    {61532, 61535},
    {61538, 61538},
    {61540, 61540},
    {61542, 61542},
    {61544, 61545},
    {61547, 61551},
    {61553, 61558},
    {61561, 61561},
    {61563, 61566},
    {61568, 61568},
    {61570, 61571},
    {61573, 61575},
    {61578, 61582},
    {61586, 61587},
    {61589, 61591},
    {61594, 61595},
    {61597, 61598},
    {61600, 61601},
    {61604, 61606},
    {61609, 61611},
    {61613, 61613},
    {61624, 61627},
    {61633, 61633},
    {61635, 61635},
    {61637, 61637},
    {61642, 61642},
    {61653,61653},
    {61656,61656},
    {61658,61658},
    {61663,61663},
    {61667,61667},
    {61676,61676},
    {61685,61685},
    {61687,61689},
    {61691,61692},
    {61695,61695},
    {61701,61701},
    {61703,61704},
    {61707,61709},
    {61713,61713},
    {61715,61715},
    {61717,61718},
    {61728,61728},
    {61732,61732},
    {61737,61737},
    {61742,61743},
    {61746,61747},
    {61750,61750},
    {61752,61752},
    {61754,61755},
    {61759,61760},
    {61762,61762},
    {61764,61766},
    {61769,61772},
    {61775,61775},
    {61777,61777},
    {61787,61787},
    {61791,61791},
    {61793,61793},
    {61795,61796},
    {61801,61801},
    {61806,61806},
    {61811,61811},
    {61815,61816},
    {61820,61820},
    {61823,61823},
    {61825,61825},
    {61836,61837},
    {61844,61844},
    {61850,61850},
    {61865,61865},
    {61872,61872},
    {61878,61878},
    {61881,61882},
    {61887,61887},
    {61915,61915},
    {61920,61920},
    {61924,61924},
    {61926,61927},
    {61930,61930},
    {61938,61938},
    {61969,61969},
    {61979,61979},
    {61988,61989},
    {61995,61995},
    {61997,61997},
    {62018,62018},
    {62022,62023},
    {62038,62038},
    {62041,62043},
    {62046,62047},
    {62051,62051},
    {62053,62053},
    {62055,62055},
    {62065,62065},
    {62067,62067},
    {62070,62070},
    {62079,62080},
    {62084,62084},
    {62090,62090},
    {62095,62095},
    {62098,62098},
    {62107,62107},
    {62213,62249},
    {62257,62261},
    {62305,62330}
};

const RangeDetails gZiExtraCharacter_RangeInfo = 
{
    181,
    gZiExtraCharacter_RangeData
};

sCustFontData gZiExtraCharacter = 
{
20, 20, 17, 3, 0, 50, 500,
(U8 *) ZiV7ExtraCharacter20_Width,
(U8 *) ZiV7ExtraCharacter20_Width, (U32 *) ZiV7ExtraCharacter20_Offset, (U8 *) ZiV7ExtraCharacter20_Data,
(U32 *) ZiV7ExtraCharacter20_RangeOffset,
{
{FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH,FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH},
{FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH,FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH},
{FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH,FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH},
{FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH,FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH},
{FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH,FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH},
{FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH,FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH},
{FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH,FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH},
{FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH,FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH},
{FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH,FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH}
},
&gZiExtraCharacter_RangeInfo
};

#else /* defined(__MMI_ZI_V7__) */ 

const RangeData gZiExtraCharacter_RangeData[5] = 
{
    {61440, 61448},
    {61456, 62398},
    {62469, 62505},
    {62513, 62517},
    {62561, 62586},
};

const RangeDetails gZiExtraCharacter_RangeInfo = 
{
    5,
    gZiExtraCharacter_RangeData
};

sCustFontData gZiExtraCharacter = 
{
20, 20, 17, 3, 0, 50, 500,
(U8 *) ZiExtraCharacter20_Width,
(U8 *) ZiExtraCharacter20_Width, (U32 *) ZiExtraCharacter20_Offset, (U8 *) ZiExtraCharacter20_Data,
(U32 *) ZiExtraCharacter20_RangeOffset,
{
{FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH,FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH},
{FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH,FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH},
{FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH,FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH},
{FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH,FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH},
{FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH,FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH},
{FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH,FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH},
{FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH,FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH},
{FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH,FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH},
{FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH,FONTATTRIB_NORMAL|FONTATTRIB_BOLD|FONTATTRIB_ITALIC|FONTATTRIB_OBLIQUE|FONTATTRIB_UNDERLINE|FONTATTRIB_STRIKETHROUGH}
},
&gZiExtraCharacter_RangeInfo
};
#endif /* defined(__MMI_ZI_V7__) */ 

#endif /* defined(__MMI_ZI__) */ 


#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__)
const RangeData gMTKProprietaryFont_RangeData[55]={
{2,2},
{108,108},
{133,134},
{331,331},
{593,593},
{596,596},
{601,603},
{609,609},
{618,618},
{643,643},
{650,650},
{652,652},
{658,658},
{711,711},
{714,716},
{719,719},
{729,729},
{731,731},
{768,769},
{771,771},
{780,780},
{7735,7735},
{7747,7747},
{7751,7751},
{8208,8208},
{8210,8213},
{8216,8223},
{8230,8231},
{8242,8243},
{8245,8246},
{8248,8251},
{8260,8260},
{8364,8364},
{8482,8482},
{8544,8555},
{8560,8571},
{9733,9734},
{12289,12290},
{12298,12303},
{61440,61442},
{61444,61445},
{61447,61447},
{62464,62467},
{62469,62505},
{62720,62725},
{65104,65104},
{65106,65106},
{65108,65111},
{65113,65114},
{65124,65124},
{65281,65374},
{65377,65380},
{65509,65509},
{65515,65515},
{65533,65533},
};

const RangeDetails gMTKProprietaryFont_RangeInfo={
55,
    gMTKProprietaryFont_RangeData

};

#if defined(__MMI_FONT_COMPRESSION__)

const mmi_font_compress_info mtk_internal_font_compress_info[] = 
{
{MTKProprietaryFont20_Data, 11956, MTKProprietaryFont20_CompressedData, 3718},
{NULL, 0, NULL, 0}
};

sCustFontData gMTKProprietaryFont = 
{
    20, 20, 17, 3, 0, 50, 500,
    (U8 *) MTKProprietaryFont20_Width,
    (U8 *) MTKProprietaryFont20_Width, (U16*) MTKProprietaryFont20_Offset, (U8 *) MTKProprietaryFont20_Data,
    (mmi_font_range_offset_struct*)&MTKProprietaryFont20_pRange,
    {
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},},
    &gMTKProprietaryFont_RangeInfo
};

#else

sCustFontData gMTKProprietaryFont = 
{
    20, 20, 17, 3, 0, 50, 500,
    (U8 *) MTKProprietaryFont20_Width,
    (U8 *) MTKProprietaryFont20_Width, (U32 *) MTKProprietaryFont20_Offset, (U8 *) MTKProprietaryFont20_Data,
        (U32 *) MTKProprietaryFont20_RangeOffset,
    {
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},},
    &gMTKProprietaryFont_RangeInfo
};

#endif

#if defined(__MMI_ZI__)

#if defined(__MMI_ZI_V7__)

const RangeData gZiExtraCharacter_RangeData[181] = 
{
    {61184, 61192},
    {61200, 61201},
    {61203, 61203},
    {61206, 61206},
    {61209, 61209},
    {61214, 61214},
    {61217, 61228},
    {61230, 61231},
    {61233, 61238},
    {61243, 61247},
    {61249, 61254},
    {61256, 61256},
    {61259, 61260},
    {61264, 61264},
    {61268, 61270},
    {61274, 61274},
    {61276, 61280},
    {61282, 61282},
    {61287, 61287},
    {61289, 61291},
    {61293, 61293},
    {61295, 61319},
    {61321, 61322},
    {61324, 61330},
    {61332, 61333},
    {61335, 61337},
    {61339, 61339},
    {61342, 61342},
    {61346, 61347},
    {61349, 61352},
    {61354, 61354},
    {61357, 61358},
    {61360, 61360},
    {61364, 61365},
    {61367, 61367},
    {61369, 61371},
    {61373, 61376},
    {61378, 61378},
    {61382, 61384},
    {61386, 61386},
    {61389, 61389},
    {61392, 61393},
    {61396, 61397},
    {61399, 61399},
    {61401, 61403},
    {61406, 61407},
    {61411, 61411},
    {61413, 61416},
    {61418, 61418},
    {61421, 61421},
    {61424, 61424},
    {61427, 61427},
    {61431, 61431},
    {61435, 61435},
    {61437, 61442},
    {61445, 61445},
    {61447, 61448},
    {61450, 61450},
    {61452, 61452},
    {61455, 61461},
    {61464, 61464},
    {61466, 61470},
    {61472, 61474},
    {61477, 61477},
    {61479, 61485},
    {61487, 61487},
    {61491, 61493},
    {61495, 61498},
    {61501, 61502},
    {61504, 61504},
    {61508, 61509},
    {61511, 61517},
    {61523, 61523},
    {61525, 61525},
    {61530, 61530},
    {61532, 61535},
    {61538, 61538},
    {61540, 61540},
    {61542, 61542},
    {61544, 61545},
    {61547, 61551},
    {61553, 61558},
    {61561, 61561},
    {61563, 61566},
    {61568, 61568},
    {61570, 61571},
    {61573, 61575},
    {61578, 61582},
    {61586, 61587},
    {61589, 61591},
    {61594, 61595},
    {61597, 61598},
    {61600, 61601},
    {61604, 61606},
    {61609, 61611},
    {61613, 61613},
    {61624, 61627},
    {61633, 61633},
    {61635, 61635},
    {61637, 61637},
    {61642, 61642},
    {61653,61653},
    {61656,61656},
    {61658,61658},
    {61663,61663},
    {61667,61667},
    {61676,61676},
    {61685,61685},
    {61687,61689},
    {61691,61692},
    {61695,61695},
    {61701,61701},
    {61703,61704},
    {61707,61709},
    {61713,61713},
    {61715,61715},
    {61717,61718},
    {61728,61728},
    {61732,61732},
    {61737,61737},
    {61742,61743},
    {61746,61747},
    {61750,61750},
    {61752,61752},
    {61754,61755},
    {61759,61760},
    {61762,61762},
    {61764,61766},
    {61769,61772},
    {61775,61775},
    {61777,61777},
    {61787,61787},
    {61791,61791},
    {61793,61793},
    {61795,61796},
    {61801,61801},
    {61806,61806},
    {61811,61811},
    {61815,61816},
    {61820,61820},
    {61823,61823},
    {61825,61825},
    {61836,61837},
    {61844,61844},
    {61850,61850},
    {61865,61865},
    {61872,61872},
    {61878,61878},
    {61881,61882},
    {61887,61887},
    {61915,61915},
    {61920,61920},
    {61924,61924},
    {61926,61927},
    {61930,61930},
    {61938,61938},
    {61969,61969},
    {61979,61979},
    {61988,61989},
    {61995,61995},
    {61997,61997},
    {62018,62018},
    {62022,62023},
    {62038,62038},
    {62041,62043},
    {62046,62047},
    {62051,62051},
    {62053,62053},
    {62055,62055},
    {62065,62065},
    {62067,62067},
    {62070,62070},
    {62079,62080},
    {62084,62084},
    {62090,62090},
    {62095,62095},
    {62098,62098},
    {62107,62107},
    {62213,62249},
    {62257,62261},
    {62305,62330}
};

const RangeDetails gZiExtraCharacter_RangeInfo = 
{
    181,
    gZiExtraCharacter_RangeData
};

sCustFontData gZiExtraCharacter = 
{
    20, 20, 17, 3, 0, 50, 500,
    (U8 *) ZiV7ExtraCharacter20_Width,
    (U8 *) ZiV7ExtraCharacter20_Width, (U32 *) ZiV7ExtraCharacter20_Offset, (U8 *) ZiV7ExtraCharacter20_Data,
    (U32 *) ZiV7ExtraCharacter20_RangeOffset,
    {
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},},
    &gZiExtraCharacter_RangeInfo
};

#else /* defined(__MMI_ZI_V7__) */ 

const RangeData gZiExtraCharacter_RangeData[5] = 
{
    {61440, 61448},
    {61456, 62398},
    {62469, 62505},
    {62513, 62517},
    {62561, 62586},
};

const RangeDetails gZiExtraCharacter_RangeInfo = 
{
    5,
    gZiExtraCharacter_RangeData
};

sCustFontData gZiExtraCharacter = 
{
    20, 20, 17, 3, 0, 50, 500,
    (U8 *) ZiExtraCharacter20_Width,
    (U8 *) ZiExtraCharacter20_Width, (U32 *) ZiExtraCharacter20_Offset, (U8 *) ZiExtraCharacter20_Data,
        (U32 *) ZiExtraCharacter20_RangeOffset,
    {
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},},
    &gZiExtraCharacter_RangeInfo
};
#endif /* defined(__MMI_ZI_V7__) */ 

#endif /* defined(__MMI_ZI__) */ 

#else /* __MMI_MAINLCD_240X320__ */ /* not defined __MMI_MAINLCD_240X320__ */

const RangeData gMTKProprietaryFont_RangeData[53]={
{2,2},
{133,134},
{230,230},
{240,240},
{331,331},
{593,593},
{596,596},
{601,603},
{609,609},
{618,618},
{643,643},
{650,650},
{652,652},
{658,658},
{711,711},
{714,716},
{719,719},
{729,729},
{731,731},
{768,768},
{7735,7735},
{7747,7747},
{7751,7751},
{8208,8208},
{8210,8213},
{8216,8223},
{8230,8231},
{8242,8243},
{8245,8246},
{8248,8251},
{8260,8260},
{8364,8364},
{8482,8482},
{8544,8555},
{8560,8571},
{9733,9734},
{12289,12290},
{12298,12303},
{61440,61442},
{61444,61445},
{61447,61447},
{62464,62467},
{62720,62725},
{65104,65104},
{65106,65106},
{65108,65111},
{65113,65114},
{65124,65125},
{65281,65374},
{65377,65380},
{65509,65509},
{65515,65515},
{65533,65533},
};

const RangeDetails gMTKProprietaryFont_RangeInfo ={
53,
gMTKProprietaryFont_RangeData
};


#if defined(__MMI_FONT_COMPRESSION__)

const mmi_font_compress_info mtk_internal_font_compress_info[] = 
{
{MTKProprietaryFont_Data,5185,MTKProprietaryFont_CompressedData,2039},
{NULL, 0, NULL, 0}
};

sCustFontData gMTKProprietaryFont = {
14, 14,
#ifdef PLUTO_MMI
11, 3,
#endif 
0, 25, 500,
(U8*)MTKProprietaryFont_Width, (U8*)MTKProprietaryFont_Width, (U16*)MTKProprietaryFont_Offset, (U8*)MTKProprietaryFont_Data, (mmi_font_range_offset_struct*)&MTKProprietaryFont_pRange,
{      
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},},
&gMTKProprietaryFont_RangeInfo};

#else /* __MMI_FONT_COMPRESSION__ */


sCustFontData gMTKProprietaryFont = 
{
    14, 14, 11, 3, 0, 25, 500,
    (U8 *) MTKProprietaryFont_Width,
    (U8 *) MTKProprietaryFont_Width, (U32 *) MTKProprietaryFont_Offset, (U8 *) MTKProprietaryFont_Data,
        (U32 *) MTKProprietaryFont_RangeOffset,
    {
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},},
    &gMTKProprietaryFont_RangeInfo
};

#endif /* __MMI_FONT_COMPRESSION__ */

#if defined(__MMI_ZI__)

#if defined(__MMI_ZI_V7__)

const RangeData gZiExtraCharacter_RangeData[181] = 
{
    {61184,61192},
    {61200,61201},
    {61203,61203},
    {61206,61206},
    {61209,61209},
    {61214,61214},
    {61217,61228},
    {61230,61231},
    {61233,61238},
    {61243,61247},
    {61249,61254},
    {61256,61256},
    {61259,61260},
    {61264,61264},
    {61268,61270},
    {61274,61274},
    {61276,61280},
    {61282,61282},
    {61287,61287},
    {61289,61291},
    {61293,61293},
    {61295,61319},
    {61321,61322},
    {61324,61330},
    {61332,61333},
    {61335,61337},
    {61339,61339},
    {61342,61342},
    {61346,61347},
    {61349,61352},
    {61354,61354},
    {61357,61358},
    {61360,61360},
    {61364,61365},
    {61367,61367},
    {61369,61371},
    {61373,61376},
    {61378,61378},
    {61382,61384},
    {61386,61386},
    {61389,61389},
    {61392,61393},
    {61396,61397},
    {61399,61399},
    {61401,61403},
    {61406,61407},
    {61411,61411},
    {61413,61416},
    {61418,61418},
    {61421,61421},
    {61424,61424},
    {61427,61427},
    {61431,61431},
    {61435,61435},
    {61437,61442},
    {61445,61445},
    {61447,61448},
    {61450,61450},
    {61452,61452},
    {61455,61461},
    {61464,61464},
    {61466,61470},
    {61472,61474},
    {61477,61477},
    {61479,61485},
    {61487,61487},
    {61491,61493},
    {61495,61498},
    {61501,61502},
    {61504,61504},
    {61508,61509},
    {61511,61517},
    {61523,61523},
    {61525,61525},
    {61530,61530},
    {61532,61535},
    {61538,61538},
    {61540,61540},
    {61542,61542},
    {61544,61545},
    {61547,61551},
    {61553,61558},
    {61561,61561},
    {61563,61566},
    {61568,61568},
    {61570,61571},
    {61573,61575},
    {61578,61582},
    {61586,61587},
    {61589,61591},
    {61594,61595},
    {61597,61598},
    {61600,61601},
    {61604,61606},
    {61609,61611},
    {61613,61613},
    {61624,61627},
    {61633,61633},
    {61635,61635},
    {61637,61637},
    {61642,61642},
    {61653,61653},
    {61656,61656},
    {61658,61658},
    {61663,61663},
    {61667,61667},
    {61676,61676},
    {61685,61685},
    {61687,61689},
    {61691,61692},
    {61695,61695},
    {61701,61701},
    {61703,61704},
    {61707,61709},
    {61713,61713},
    {61715,61715},
    {61717,61718},
    {61728,61728},
    {61732,61732},
    {61737,61737},
    {61742,61743},
    {61746,61747},
    {61750,61750},
    {61752,61752},
    {61754,61755},
    {61759,61760},
    {61762,61762},
    {61764,61766},
    {61769,61772},
    {61775,61775},
    {61777,61777},
    {61787,61787},
    {61791,61791},
    {61793,61793},
    {61795,61796},
    {61801,61801},
    {61806,61806},
    {61811,61811},
    {61815,61816},
    {61820,61820},
    {61823,61823},
    {61825,61825},
    {61836,61837},
    {61844,61844},
    {61850,61850},
    {61865,61865},
    {61872,61872},
    {61878,61878},
    {61881,61882},
    {61887,61887},
    {61915,61915},
    {61920,61920},
    {61924,61924},
    {61926,61927},
    {61930,61930},
    {61938,61938},
    {61969,61969},
    {61979,61979},
    {61988,61989},
    {61995,61995},
    {61997,61997},
    {62018,62018},
    {62022,62023},
    {62038,62038},
    {62041,62043},
    {62046,62047},
    {62051,62051},
    {62053,62053},
    {62055,62055},
    {62065,62065},
    {62067,62067},
    {62070,62070},
    {62079,62080},
    {62084,62084},
    {62090,62090},
    {62095,62095},
    {62098,62098},
    {62107,62107},
    {62213,62249},
    {62257,62261},
    {62305,62330}
};

const RangeDetails gZiExtraCharacter_RangeInfo = 
{
    181,
    gZiExtraCharacter_RangeData
};

sCustFontData gZiExtraCharacter = 
{
    14, 14, 12, 2, 0, 25, 500,
    (U8 *) ZiV7ExtraCharacter14_Width,
    (U8 *) ZiV7ExtraCharacter14_Width, (U32 *) ZiV7ExtraCharacter14_Offset, (U8 *) ZiV7ExtraCharacter14_Data,
    (U32 *) ZiV7ExtraCharacter14_RangeOffset,
    {
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},},
    &gZiExtraCharacter_RangeInfo
};

#else /* defined(__MMI_ZI_V7__) */ 
const RangeData gZiExtraCharacter_RangeData[5] = 
{
    {322, 322},
    {341, 341},
    {352, 352},
    {61440, 61448},
    {61456, 62398},
};

const RangeDetails gZiExtraCharacter_RangeInfo = 
{
    5,
    gZiExtraCharacter_RangeData
};

sCustFontData gZiExtraCharacter = 
{
    14, 14, 12, 2, 0, 25, 500,
    (U8 *) ZiExtraCharacter_Width,
    (U8 *) ZiExtraCharacter_Width, (U32 *) ZiExtraCharacter_Offset, (U8 *) ZiExtraCharacter_Data,
        (U32 *) ZiExtraCharacter_RangeOffset,
    {
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},
     {FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH,
      FONTATTRIB_NORMAL | FONTATTRIB_BOLD | FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE | FONTATTRIB_UNDERLINE |
      FONTATTRIB_STRIKETHROUGH},},
    &gZiExtraCharacter_RangeInfo
};
#endif /* defined(__MMI_ZI_V7__) */ 

#endif /* defined(__MMI_ZI__) */ 

#endif /* __MMI_MAINLCD_240X320__ */ 

static const U32 font_tilt_table[61] = {
    0, 0, 0, 0, 0, 1, 1, 1, 1, 2,
    2, 2, 2, 2, 3, 3, 3, 3, 4, 4,
    4, 4, 5, 5, 5, 5, 5, 6, 6, 6,
    6, 7, 7, 7, 7, 8, 8, 8, 8, 8,
    9, 9, 9, 9, 10, 10, 10, 10, 11, 11,
    11, 11, 11, 12, 12, 12, 12, 13, 13, 13, 13
};


U32 gnCurrentFont;
sCustFontData *gpCurrentFont = NULL;
extern U16 gMaxDeployedLangs;
extern U16 gCurrLangIndex;


/*****************************************************************************
*  Global Function
*****************************************************************************/
static U32 mmi_fe_show_string_int(mmi_fe_showstring_int_param_struct_p param);
#if defined(__MMI_LANG_THAI__)
static S32 mmi_fe_show_thai_char_internal(
        S32 CurrentX,
        S32 CurrentY,
        U16 pre2Ch,
        U16 preCh,
        U16 curCh,
        mmi_fe_showstring_int_param_struct_p param);
#endif
#if defined(__MMI_INDIC_ALG__) && !defined(__MMI_VECTOR_FONT_SUPPORT__)
static U32 mmi_fe_show_indic_string_internal(mmi_fe_showstring_int_param_struct_p param);
static U32 mmi_fe_get_string_widthheight_indic_internal(mmi_fe_get_string_info_param_struct_p param);
#endif
U32 mmi_fe_get_string_widthheight(mmi_fe_get_string_info_param_struct_p query);
static S32 mmi_font_engine_get_baseline_internal(U8 *st, S32 len, S32 *LineHeight);
static mmi_font_engine_error_message_enum mmi_fe_get_display_direction(U8* st, U8* dic, S32 len);
static void GetLangIndex(U8 *pCount, S32 *pnFontIndex, S32 *pnIndex, U32 nCh, U32 *pnBase);
static S32 SearchIndexinList(U8 nListIndex, U16 nFontCount, U32 nCh, U32 *pnBase);
static S32 SearchInPropFont(U32 nCh, U32 *pnBase);
static mmi_fe_lang_id mmi_fe_get_lang_id(U32 ch);
static void SetFontValues(U32 nFont, U8 arrCount);
static MMI_BOOL mmi_fe_test_display_as_space(U32 ch);
static MMI_BOOL mmi_fe_test_display_as_null(U32 ch);
static U32 Get_CharWidthHeight_internal(U32 Ch, S32 *pdWidth, S32 *pWidth, S32 *pHeight, S32 *pAscent, S32 *pDescent);

__inline static U32 mmi_fe_get_font_data(
                            U8 type,
                            U16 ch, 
                            U8 **ppCharData, 
                            U32 *data_attr,
                            S32 *pnWidth, 
                            S32 *advance_x, 
                            U16 *glyph_width, 
                            U16 *glyph_height, 
                            S32 *bearing_x,
                            S32 *ascent, 
                            S32 *descent,
                            MMI_BOOL *valid);

#if defined(__MMI_FONT_COMPRESSION__)
static S32 mmi_fe_get_block_index(mmi_font_range_offset_struct *rangeOffset, S32 index);
#endif

/*****************************************************************************
*  External Function
*****************************************************************************/
#ifdef __MTK_TARGET__
extern kal_uint32 INT_SwitchStackToRun(void *stack_start, kal_uint32 stack_size, kal_func_ptr func, kal_uint32 argc, ...);
extern void kal_check_stack(void);
#endif

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
extern MMI_BOOL mmi_frm_enfb_if_enfb(const U8 *img);
extern U32 mmi_frm_enfb_get_img_offset(const U8 *img);
extern void GetResourceENFBData(S32 enfb_handle,S32 offset,void *data, S32 data_size);
#endif

/**************************************************************/


#ifdef __MMI_VECTOR_FONT_SUPPORT__

#include "font_engine_interface.h"

#define FE_FOUR_BYTE_ALIGN(a) ((((a)+3) >> 2) << 2)


static U32 font_engine_font_attr = 0;
static U8  font_engine_font_size = 0;
static U32 font_engine_font_pixel= 0;
static MMI_BOOL font_engine_antialias = MMI_TRUE;
extern const fe_table_struct *font_engine;

MMI_BOOL dummy_fe_init(U16* font_list, U8 font_number){return MMI_FALSE;}
void dummy_fe_set_font_attr(U32 attr){}
void dummy_fe_set_font_size(U32 size, U32 attr){}
void dummy_fe_set_font_color(gdi_color text_color,gdi_color border_color){}
MMI_BOOL dummy_fe_get_font_data(U8 is_need_glyph_data, // need generate glyph or only need character information
                             U16 ucs2,
                             U8** glyph_data,
                             U32 *glyph_size, // bytes number of glyph_data
                             U32 *glyph_attr, // glyph attribute , used for font engine itself
                             U16 *glyph_width,U16 *glyph_height,
                             S32 *bearing_x,S32 *bearing_y,  // the offset from origin for glyph
                             S32 *advance_x,S32 *advance_y,   // the offset for next character origin
                            MMI_BOOL* valid)
{
    return MMI_FALSE;
}

MMI_BOOL dummy_fe_set_font(U16 resid){return MMI_TRUE;}
void dummy_fe_set_antialias(MMI_BOOL value){}

void dummy_fe_show_font_data(U16 ucs2, S32 x,S32 y,U8* glyph_ptr,U32 glyph_size,U32 glyph_attr,U16 glyph_width,U16 glyph_height, U32 border){}
MMI_BOOL dummy_fe_get_width_height(U16 ucs2,S32 *width,S32 *height,S32 *ascent,S32 *descent)
{
    return MMI_FALSE;
}
MMI_BOOL dummy_fe_get_font_info(U32 font_size,S32 *height,S32 *ascent, S32 *descent, MMI_BOOL with_attr)
{
    return MMI_FALSE;
}


void dummy_fe_shaper(U32 lang, U32 script, UI_string_type text, S32 text_len, S32 start_index, S32 run_len, mmi_fe_cluster_info_p cluster){}

const fe_table_struct dummy_font_engine=
{
    dummy_fe_init,
    dummy_fe_set_font_attr,
    dummy_fe_set_font_size,
    dummy_fe_set_font_color,
    dummy_fe_get_font_data,
    dummy_fe_show_font_data,
    dummy_fe_get_font_info,
    dummy_fe_set_antialias,
    dummy_fe_set_font,
    dummy_fe_shaper
};

const U32 g_mmi_fe_script_table[] = 
{
    MMI_FE_OT_SCRIPT_BENGALI,
    MMI_FE_OT_SCRIPT_DEVANAGARI,
    MMI_FE_OT_SCRIPT_GUJARATI,
    MMI_FE_OT_SCRIPT_GURMUKHI,
    MMI_FE_OT_SCRIPT_KANNADA,
    MMI_FE_OT_SCRIPT_MALAYALAM,
    MMI_FE_OT_SCRIPT_ORIYA,
    MMI_FE_OT_SCRIPT_SINHALA,
    MMI_FE_OT_SCRIPT_TAMIL,
    MMI_FE_OT_SCRIPT_TELUEU,
    MMI_FE_OT_SCRIPT_THAI,
    /* the end value. all other new script flag should be added before this one. */
    MMI_FE_OT_DEFAULT
};


const U32 g_mmi_fe_lang_table[] = 
{
    MMI_FE_OT_LANG_ASSAMESE,
    MMI_FE_OT_LANG_BENGALI,
    MMI_FE_OT_LANG_GUJARATI,
    MMI_FE_OT_LANG_HINDI,
    MMI_FE_OT_LANG_KANNADA,
    MMI_FE_OT_LANG_MALAYALAM,
    MMI_FE_OT_LANG_MARATHI,
    MMI_FE_OT_LANG_ORIYA,
    MMI_FE_OT_LANG_PUNJABI,
    MMI_FE_OT_LANG_TAMIL,
    MMI_FE_OT_LANG_TELUGU,
    MMI_FE_OT_LANG_THAI,
    /* the end value. all other new lang flag should be added before this one. */
    MMI_FE_OT_DEFAULT
};
void mmi_fe_disable_font_engine(void)
{
	memset(charHashTableLatin,0,sizeof(charHashTableLatin));
	memset(charHashTableOthers,0,sizeof(charHashTableOthers));

    font_engine = &dummy_font_engine;
}
void mmi_fe_enable_font_engine(void)
{
    font_engine = &font_engine_table;
}
const fe_table_struct *font_engine = &dummy_font_engine;


void mmi_fe_set_antialias(MMI_BOOL value)
{
    GDI_LOCK;
    font_engine_antialias = value;
    if (value)
    {
        font_engine_font_attr |= FE_FONT_ATTR_ANTIALIAS;
    }
    else
    {
        font_engine_font_attr &= (~FE_FONT_ATTR_ANTIALIAS);
    }
    font_engine->set_antialias(value);
    GDI_UNLOCK;
}

#define MMI_FE_CACHE_KEY(UCS2,FONT_SIZE,FONT_ATTR)  (((U32)UCS2) | (((U32)FONT_SIZE)<<16) | (((U32)FONT_ATTR)<<24) )
#define MMI_FE_STACK_SIZE                            8192
#define MMI_FE_FILE_CACHE_SIZE                   (65536>>1)

#if defined(__MTK_TARGET__)
static U32 g_mmi_fe_stack[MMI_FE_STACK_SIZE/4];
#endif

#include "dict.h"

typedef struct
{
    U16 cluster_len : 5;
    U16 lang : 5;
    U16 script : 5;
    U16 init : 1;
    U8 font_attr;
    U8 font_size;
} mmi_fe_cache_key_header_struct;

typedef struct
{
    mmi_fe_cache_key_header_struct header;
    UI_character_type string[FE_MAX_CLUSTER_LEN];
} mmi_fe_cache_key_struct;

typedef struct
{
    S16 x_pos;
    S16 y_pos;
} mmi_fe_char_pos_struct;

typedef struct
{
    kal_int8 width;
    kal_int8 height;
    kal_int8 bearing_x;
    kal_int8 bearing_y;
    kal_int8 advance_x;
    U16 bitmap_size;
    U32 bitmap[1];
} mmi_fe_glyph_info, *mmi_fe_glyph_info_p;

typedef struct
{
    mmi_fe_glyph_ot_info posdata;
    mmi_fe_glyph_info glyph_data;    
} mmi_fe_text_info, *mmi_fe_text_info_p;

typedef struct
{
    S32 glyph_len;
    mmi_fe_text_info glyph_list[1];    
} mmi_fe_cache_node_data_struct;

typedef struct
{
    dnode_t  node_header;
    U8 data;
} mmi_fe_cache_tree_node_struct;

typedef struct mmi_fe_cache_tree_struct
{
    struct mmi_fe_cache_tree_struct *next;
    U32                             ref_cnt;
    dict_t                          dict;
    U8*                             memory_used;
    U8*                             memory_end;
} mmi_fe_cache_tree_struct;

#define MMI_FE_CACHE_TREE_SIZE      200*2*1024		/* default font engine cache size */
#define MMI_FE_CACHE_TREE_PAGE_SIZE 200*1024	/* memory from media task, will be free if need */
#if MMI_FE_CACHE_TREE_SIZE < MMI_FE_CACHE_TREE_PAGE_SIZE
    #error "font engine pool size too small"
#endif    

static U32 MMI_FE_CACHE_TREE_DEFAULT_POOL[MMI_FE_CACHE_TREE_SIZE/4];
static U32 mmi_fe_cache_tree_default_pool_used;
static mmi_fe_cache_tree_struct *mmi_fe_cache_tree;


static U8 mmi_fe_font_file_cache[MMI_FE_FILE_CACHE_SIZE];
static U8 g_mmi_fe_font_file_number[FE_MAX_FONT_FAMILY_NUMBER];
static U16 g_mmi_fe_font_file_list[FE_MAX_FONT_FAMILY_NUMBER][FE_MAX_FONT_FILE_NUMBER];
/* to record proprietary font temporially. 
    We would put the priprietary in the end of the font list. 
    We asume only one proprietary font for each family now. */
static U16 g_mmi_fe_private_font_file_list[FE_MAX_FONT_FAMILY_NUMBER];
static U16* g_mmi_fe_curr_font_list;
static U16 g_mmi_fe_font_family = 0;
static U32 g_mmi_fe_curr_font_file = 0;

#define MMI_FE_CLUSTER_POOL_SIZE 128*128/2

static U32 g_mmi_fe_cluster_data_pool[MMI_FE_CLUSTER_POOL_SIZE];

#if defined(__MMI_LANG_THAI__)
static MMI_BOOL mmi_fe_is_thai_character(U16 curCh);
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_size_to_pixel
 * DESCRIPTION
 *  Convert the size to pixel
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_fe_size_to_pixel(U8 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 pixels;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if((size & 0x80) == 0)
    {
    #if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__)
        switch((size & 0x0F))
        {
        case SMALL_FONT:
            pixels = 14;
            break;
        case MEDIUM_FONT:
            pixels = 20;
            break;
        case LARGE_FONT:
            pixels = 22;
            break;
         case SUBLCD_FONT:
            pixels = 9;
            break;
        case DIALER_FONT:
           pixels = 27;
           break;
       case VIRTUAL_KEYBOARD_FONT:
          pixels = 12;
          break;
         default:
            pixels = 20;
            break;
        }
    #elif defined(__MMI_MAINLCD_320X480__)    
         switch((size & 0x0F))
         {
         case SMALL_FONT:
             pixels = 14;
             break;
         case MEDIUM_FONT:
             pixels = 20;
             break;
         case LARGE_FONT:
             pixels = 24;
             break;
          case SUBLCD_FONT:
             pixels = 9;
             break;
         case DIALER_FONT:
            pixels = 48;
            break;
        case VIRTUAL_KEYBOARD_FONT:
           pixels = 20;
           break;
         case VIRTUAL_KEYBOARD_LARGE_FONT:
            pixels = 30;
            break;
         case NUMBER_1_FONT:
            pixels = 12;
            break;
        case NUMBER_2_FONT:
           pixels = 16;
           break;
         default:
            pixels = 20;
            break;
         }
    #else
        switch((size & 0x0F))
        {
            case SMALL_FONT:
                pixels = 9;
                break;
            case MEDIUM_FONT:
                pixels = 14;
                break;
            case LARGE_FONT:
                pixels = 16;
                break;
            case SUBLCD_FONT:
                pixels = 9;
                break;
            case DIALER_FONT:
                pixels = 27;
                break;
            case VIRTUAL_KEYBOARD_FONT:
                pixels = 12;
                break;
            default:
                pixels = 20;
                break;
        }
    
    #endif    
    }
    else
    {
        pixels = size & 0x7f;
    }
    return pixels;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_set_font
 * DESCRIPTION
 *  to set font size and attribute
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_set_font(U8 size, U32 attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(font_engine_font_size == 0  || font_engine_font_size != size || font_engine_font_attr != attr)
    {
        font_engine_font_attr = attr;
        font_engine_font_size   = size;
        font_engine_font_pixel  = mmi_fe_size_to_pixel(size);
        if (font_engine_antialias)
        {
            font_engine_font_attr |= FE_FONT_ATTR_ANTIALIAS;
        }
        else
        {
            font_engine_font_attr &= (~FE_FONT_ATTR_ANTIALIAS);
        }

    #if defined(__MTK_TARGET__)
        INT_SwitchStackToRun(
            g_mmi_fe_stack, 
            MMI_FE_STACK_SIZE, 
            (kal_func_ptr)font_engine->set_font_size,
            2,
            font_engine_font_pixel,
            font_engine_font_attr);
    #else
        font_engine->set_font_size( font_engine_font_pixel, font_engine_font_attr);
    #endif
    
    #ifdef __MTK_TARGET__
        kal_check_stack(); /* if overflow , assert it */
    #endif
        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_cache_tree_cmp_fun
 * DESCRIPTION
 *  Compare function for tree node 
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static int mmi_fe_cache_tree_cmp_fun(const void *a,const void *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_cache_key_struct* key_a = (mmi_fe_cache_key_struct*)a;
    mmi_fe_cache_key_struct* key_b = (mmi_fe_cache_key_struct*)b;
    int comp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    comp = key_a->header.cluster_len - key_b->header.cluster_len;    
    if (comp)
        return comp;

    comp = memcmp(key_a, key_b, sizeof(mmi_fe_cache_key_header_struct) + sizeof(UI_character_type)*key_a->header.cluster_len);
    return comp;
}




/*****************************************************************************
 * FUNCTION
 *  mmi_fe_cache_tree_free_notify_callback
 * DESCRIPTION
 *  To allocate node for tree 
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void mmi_fe_cache_tree_free_notify_callback(void* ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_cache_tree_struct *tree = mmi_fe_cache_tree->next;
    mmi_fe_cache_tree_struct *parent = mmi_fe_cache_tree;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FE_LOCK;

    for(; tree != NULL;parent = tree, tree = tree->next)
    {
        if((void*)tree == ptr) /* remove this node from cache_tree_list */
        {
            parent->next = tree->next;
            FE_UNLOCK;
            return;
        }
    }
    MMI_ASSERT(0); // memory leak !! didn't find this memory pointer
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_cache_tree_init
 * DESCRIPTION
 *  To allocate node for tree 
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void mmi_fe_cache_tree_init(mmi_fe_cache_tree_struct *tree,U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    size &= ~0x3;

    dict_init(&tree->dict,DICTCOUNT_T_MAX,mmi_fe_cache_tree_cmp_fun);
    tree->ref_cnt=0;
    tree->next = NULL;
    tree->memory_used = ((U8*)tree) + ((sizeof(mmi_fe_cache_tree_struct)+3)&(~3));
    tree->memory_end  = ((U8*)tree) + size;
}

mmi_fe_cache_tree_node_struct* mmi_fe_cache_tree_alloc_node(mmi_fe_cache_tree_struct *tree,U32 size)
{
    mmi_fe_cache_tree_node_struct*  node = NULL;
	size = size&(~3); /* mmi_fe_cache_tree_node_struct already contain 4 bytes bitmap space */
    if(tree->memory_used+size <= tree->memory_end)
    {
        node = (mmi_fe_cache_tree_node_struct*)tree->memory_used;
        tree->memory_used += size;
    }
    return node;
}


void* mmi_fe_cache_tree_allocate_page(void)
{
    mmi_fe_cache_tree_struct *tree = NULL;
    int size;

    // allocate from static default pool
    if(mmi_fe_cache_tree_default_pool_used< MMI_FE_CACHE_TREE_SIZE)
    {
        if(mmi_fe_cache_tree_default_pool_used + MMI_FE_CACHE_TREE_PAGE_SIZE < MMI_FE_CACHE_TREE_SIZE )
            size = MMI_FE_CACHE_TREE_PAGE_SIZE;
        else
            size = MMI_FE_CACHE_TREE_SIZE - mmi_fe_cache_tree_default_pool_used;

        // remain space should large then header + 1 font data cache(128x128x8 bits )
        if(size >(sizeof(mmi_fe_cache_tree_struct)+sizeof(mmi_fe_cache_tree_node_struct)+128*128))
        {
            tree = (mmi_fe_cache_tree_struct*)(((char*)MMI_FE_CACHE_TREE_DEFAULT_POOL)+mmi_fe_cache_tree_default_pool_used);
            mmi_fe_cache_tree_default_pool_used += size;
        }
    }

    // allocate from media un-used memory, and will be freed if need.
    if(tree== NULL)
    {
        size = MMI_FE_CACHE_TREE_PAGE_SIZE;

        tree = (mmi_fe_cache_tree_struct *)med_alloc_temp_ext_mem(size,mmi_fe_cache_tree_free_notify_callback);
    }

    // try to overdue a cache page
    if(tree==NULL)
    {
        mmi_fe_cache_tree_struct *T;
        tree = T = mmi_fe_cache_tree->next;
        
        for(; T != NULL;T = T->next)
        {
            if(T->ref_cnt < tree->ref_cnt)
                tree = T;
        }

        if(tree) // release this node from tree list
            mmi_fe_cache_tree_free_notify_callback((void*)tree);
    }
       
    if(tree)
    {
        /* attach this tree into cache_tree_list */
        mmi_fe_cache_tree_init(tree,size);
    }
    return tree;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_cache_key_maker
 * DESCRIPTION
 *  To create key
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
__inline static void mmi_fe_cache_key_maker(UI_string_type text, S32 len, FE_OT_FLAG lang, U32 attr, U8 size, FE_OT_FLAG script, MMI_BOOL init, mmi_fe_cache_key_struct* key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 script_index = 0, lang_index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (g_mmi_fe_script_table[script_index] != script)
    {
        script_index++;
    }
    while (g_mmi_fe_lang_table[lang_index] != lang)
    {
        lang_index++;
    }
    key->header.cluster_len = (U16)len;
    key->header.font_attr = (U8)attr;
    key->header.font_size = size;
    key->header.lang = lang_index;
    key->header.script = script_index;
    key->header.init = (init == 0? 1: 0);
    memcpy(&key->string, text, len*sizeof(U16));
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_cache_tree_find
 * DESCRIPTION
 *  To find font cache 
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
__inline static BOOL mmi_fe_cache_tree_find(mmi_fe_cache_key_struct* key, mmi_fe_text_info_p* data_ptr, S32* len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_cache_tree_struct *tree = mmi_fe_cache_tree;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for(; tree != NULL;tree = tree->next)
    {
        mmi_fe_cache_tree_node_struct *node = NULL;
        mmi_fe_cache_node_data_struct *data = NULL;
        node = (mmi_fe_cache_tree_node_struct*) dict_lookup(&tree->dict, (const void *)key);
        if(node)
        {
            data = (mmi_fe_cache_node_data_struct*)(&node->data + sizeof(mmi_fe_cache_key_header_struct) + FE_FOUR_BYTE_ALIGN(key->header.cluster_len<<2));
            *data_ptr = (mmi_fe_text_info_p)&data->glyph_list;
            *len = data->glyph_len;
            tree->ref_cnt++;
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_cache_tree_save
 * DESCRIPTION
 *  To save the font data into cache tree
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
__inline static void mmi_fe_cache_tree_save(mmi_fe_cache_key_struct* key, S32 glyph_len, mmi_fe_text_info_p glyph_list, U32 cluster_data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_cache_tree_struct *tree;
    mmi_fe_cache_tree_node_struct *node;
    mmi_fe_cache_node_data_struct *data;
    S32 keysize = sizeof(mmi_fe_cache_key_header_struct) + FE_FOUR_BYTE_ALIGN(key->header.cluster_len<<2);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    do
    {
        tree = mmi_fe_cache_tree;
        node = NULL;
        for(; tree != NULL;tree = tree->next)
        {
            node = mmi_fe_cache_tree_alloc_node(tree,sizeof(mmi_fe_cache_tree_node_struct) + keysize + cluster_data_size);
            if (node)
            {
                memset(node, 0, sizeof(mmi_fe_cache_tree_node_struct) + keysize + cluster_data_size);

                data = (mmi_fe_cache_node_data_struct*)(&node->data + keysize);
                if (key)
                    memcpy(&node->data, key, keysize);
                if (glyph_list)
                    memcpy(&data->glyph_list[0], glyph_list, cluster_data_size);
                data->glyph_len = glyph_len;
                
                dnode_init(&node->node_header,node);
                dict_insert(&tree->dict,(dnode_t*)node,(const void*)&node->data);
                return;
            }
        }
        /* not enough memory for current tree list, try to allocate new tree */

        tree = mmi_fe_cache_tree_allocate_page();
        
        if(tree == NULL)  /* media task didn't have any memory free !*/
            break;

        /* attach this tree into cache_tree_list */
        tree->next = mmi_fe_cache_tree->next;
        mmi_fe_cache_tree->next = tree;
    }
    while(1);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_cache_init
 * DESCRIPTION
 *  To reset vector font cache
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
__inline static void mmi_fe_cache_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    
    mmi_fe_cache_tree = (mmi_fe_cache_tree_struct *)MMI_FE_CACHE_TREE_DEFAULT_POOL;
    mmi_fe_cache_tree_init(mmi_fe_cache_tree,MMI_FE_CACHE_TREE_PAGE_SIZE);
    mmi_fe_cache_tree_default_pool_used = MMI_FE_CACHE_TREE_PAGE_SIZE;
    
}

extern U8 *GetFontResource(U16 ResId, BOOL *is_enfb,S32 *enfb_handle, S32 *size); // this enfb_handle is the offset of font data in ENFB
extern S8 *GetImageRaw(U16 ImageId);


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_check_font_header
 * DESCRIPTION
 *  To get font family and flag
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_fe_check_font_header(U16 resid, U8* flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* res = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *flag = 0;
    res = (U8*)GetImageRaw(resid);
    if (!res) return -1;
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    if (mmi_frm_enfb_if_enfb(res) == MMI_TRUE)
    {
        U8 enfb_header[8];        
        U32 enfb_handle = mmi_frm_enfb_get_img_offset(res);
        GetResourceENFBData(enfb_handle, 0, (void*)&enfb_header, 8);
        if (enfb_header[0] == IMAGE_TYPE_TTF)
        {
            *flag = enfb_header[3];
            return enfb_header[1];
        }
        else
        {
            return -1;
        }
    }
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

    if (res[0] == IMAGE_TYPE_TTF)
    {
        *flag = res[3];
        return res[1];
    }
    return -1;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_multiple_file_init
 * DESCRIPTION
 *  To initialize multitple file cache
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_fe_multiple_file_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    S32 family = 0;
    U8 flag;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(mmi_fe_font_file_cache, 0xFF, MMI_FE_FILE_CACHE_SIZE);
    memset(g_mmi_fe_private_font_file_list, 0, sizeof(U16)*FE_MAX_FONT_FAMILY_NUMBER);
    g_mmi_fe_font_file_number[0] = 0;
    g_mmi_fe_font_file_number[1] = 0;
    g_mmi_fe_font_file_number[2] = 0;

    

    for (i = IMG_GLOBAL_FONT_1; i <= IMG_GLOBAL_FONT_10; i ++)
    {
        family = mmi_fe_check_font_header(i, &flag);
        if (family != -1) /* all vector font type should be checked */
        {
            if (flag)
            {
                g_mmi_fe_private_font_file_list[family] = i;
            }
            else
            {
                g_mmi_fe_font_file_list[family][g_mmi_fe_font_file_number[family]++] = i;
            }
        }
    }

    /* copy the private font in the end */
    for (i = 0; i < FE_MAX_FONT_FAMILY_NUMBER; i++)
    {
        if (g_mmi_fe_private_font_file_list[i] != 0)
        {
            g_mmi_fe_font_file_list[i][g_mmi_fe_font_file_number[i]++] = g_mmi_fe_private_font_file_list[i];
        }
    }
    g_mmi_fe_curr_font_list = g_mmi_fe_font_file_list[g_mmi_fe_font_family];
    g_mmi_fe_curr_font_file = 0;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_set_family
 * DESCRIPTION
 *  To change font family (reserved.)
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void mmi_fe_set_family(S32 family_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_fe_font_family = family_index;
    mmi_fe_multiple_file_init();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_vector_set_active
 * DESCRIPTION
 *  To change active font for vector font engine.
 * PARAMETERS
 *  res_id    [IN]   the resource id for the font
 *  index     [IN]   the index in font array
 * RETURNS
 *  
 *****************************************************************************/
__inline static void mmi_fe_vector_change_active(U16 res_id, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    g_mmi_fe_curr_font_file = index;         
#if defined(__MTK_TARGET__)
    INT_SwitchStackToRun(
        g_mmi_fe_stack, 
        MMI_FE_STACK_SIZE, 
        (kal_func_ptr)font_engine->set_font,
        1,
        res_id);
#else
    font_engine->set_font(res_id);        
#endif

}

#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_init
 * DESCRIPTION
 *  To initalize font engine 
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void mmi_fe_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VECTOR_FONT_SUPPORT__)    
    BOOL ret;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_mutex_init(&g_mmi_fe_cache_mutex);
#if defined(__MMI_VECTOR_FONT_SUPPORT__)    
    g_mmi_fe_font_family = 0;
    mmi_fe_cache_init();
    mmi_fe_multiple_file_init();
#ifdef __MTK_TARGET__
    ret = INT_SwitchStackToRun(
                g_mmi_fe_stack, 
                MMI_FE_STACK_SIZE, 
                (kal_func_ptr)font_engine_table.init, 
                2,
                g_mmi_fe_curr_font_list, 
                g_mmi_fe_font_file_number[g_mmi_fe_font_family]);
    kal_check_stack(); /* if overflow , assert it */
#else
    ret = font_engine_table.init(g_mmi_fe_curr_font_list, g_mmi_fe_font_file_number[g_mmi_fe_font_family]);
#endif

    if (ret)
    {
        mmi_fe_enable_font_engine();
        mmi_fe_set_antialias(MMI_TRUE);
        mmi_fe_set_font(1, 0);
    }
    else
    {
        MMI_ASSERT(0);
    }

    /* generate font cache */
    mmi_fe_vector_change_active(g_mmi_fe_curr_font_list[0], 0);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_test_display_as_space
 * DESCRIPTION
 *  To test if a special character should be displayed as space or not 
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
__inline static MMI_BOOL mmi_fe_test_display_as_space(U32 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FONT_TEST_CONTROL_CHAR(ch) || FONT_TEST_SPACE_CHAR(ch))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_test_display_as_null
 * DESCRIPTION
 *  To test if a special character should be displayed as zero width character or not 
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
__inline static MMI_BOOL mmi_fe_test_display_as_null(U32 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ch == 0x7f ||
         FONT_TEST_ZERO_WIDTH_CHAR(ch) ||
         FONT_TEST_FORMATTING_CHARS(ch) || 
         FONT_TEST_ZERO_WIDTH_SPACE(ch) ||
        (ch ==0x0085 && (!(fe_display_flag & FE_DISPLAY_FLAG_PROPRIETARY_SYMBOL_CHAR))))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_test_display_as_invalid
 * DESCRIPTION
 *  To test if a special character should be displayed as invalid character (Dec: 65515/ Hex: 0xFFEB) or not 
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
__inline static MMI_BOOL mmi_fe_test_display_as_invalid(U32 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((FONT_TEST_DATE_CHARS(ch) && (!(fe_display_flag & FE_DISPLAY_FLAG_DATE_CHAR))) ||
        (ch == 0x0086 && (!(fe_display_flag & FE_DISPLAY_FLAG_PROPRIETARY_SYMBOL_CHAR))))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_test_alpabetic_lang_char
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_fe_test_alphabetic_lang_char(UI_character_type ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_INDIC_ALG__)
    if ((ch <= 0x2180 || ch >= 0x9eaf) /*&& !IRE_INDIC_CHARACTER_UCS2_RANGE(ch)*/)
        return MMI_TRUE;
#else
    if ((ch <= 0x2180 || ch >= 0x9eaf))
        return MMI_TRUE;
#endif
    return MMI_FALSE;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_fe_enable_ucs2_proprietary_display
 * DESCRIPTION
 *  To enable UCS2 proprietary range (0xE000 - 0xF8FF) 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_enable_ucs2_proprietary_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    fe_display_flag |= FE_DISPLAY_FLAG_UCS2_PROPRIETARY;
    GDI_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_disable_ucs2_proprietary__display
 * DESCRIPTION
 *  To disable UCS2 proprietary range (0xE000 - 0xF8FF) 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_disable_ucs2_proprietary_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    fe_display_flag &= (~FE_DISPLAY_FLAG_UCS2_PROPRIETARY);
    GDI_UNLOCK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_enable_date_char_display
 * DESCRIPTION
 *  To enable special date character (133~147 0x85~0x93) display 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_enable_date_char_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    fe_display_flag |= FE_DISPLAY_FLAG_DATE_CHAR;
    GDI_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_disable_date_char_display
 * DESCRIPTION
 *  To disable special date character (133~147 0x85~0x93) display 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_disable_date_char_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    fe_display_flag &= (~FE_DISPLAY_FLAG_DATE_CHAR);
    GDI_UNLOCK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_enable_proprietary_symbol_display
 * DESCRIPTION
 *  To enable special CR-LF and SPACE symbol used in symbol table (133~134 0x85~0x86) display 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_enable_proprietary_symbol_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    fe_display_flag |= FE_DISPLAY_FLAG_PROPRIETARY_SYMBOL_CHAR;
    GDI_UNLOCK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_disable_proprietary_symbol_display
 * DESCRIPTION
 *  To disable special CR-LF and SPACE symbol used in symbol table (133~134 0x85~0x86) display 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_disable_proprietary_symbol_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    fe_display_flag &= (~FE_DISPLAY_FLAG_PROPRIETARY_SYMBOL_CHAR);
    GDI_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  Get_Current_Lang_CountryCode
 * DESCRIPTION
 *  To get current language's country code
 *  This is used to get current language's country code
 * PARAMETERS
 *  void
 * RETURNS
 *  U8 *
 *****************************************************************************/
U8 *Get_Current_Lang_CountryCode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* str;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    str = (U8*) gLanguageArray[gCurrLangIndex].aLangCountryCode;
    GDI_UNLOCK;
    return str;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_set_text_color
 * DESCRIPTION
 *  To set text color
 * PARAMETERS
 *  color c
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_set_text_color(mmi_fe_color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    g_mmi_fe_text_color = c;
    GDI_UNLOCK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_set_text_border_color
 * DESCRIPTION
 *  To set text border color
 * PARAMETERS
 *  color c
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_set_text_border_color(mmi_fe_color c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    g_mmi_fe_text_border_color = c;
    GDI_UNLOCK;

}



/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_text_color
 * DESCRIPTION
 *  To get text color
 * PARAMETERS
 *  void
 * RETURNS
 *  color
 *****************************************************************************/
mmi_fe_color mmi_fe_get_text_color(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_color ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    ret = g_mmi_fe_text_color;
    GDI_UNLOCK;
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_text_border_color
 * DESCRIPTION
 *  To get text border color
 * PARAMETERS
 *  void
 * RETURNS
 *  color
 *****************************************************************************/
mmi_fe_color mmi_fe_get_text_border_color(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_color ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    ret = g_mmi_fe_text_border_color;
    GDI_UNLOCK;
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_is_vector_font_support
 * DESCRIPTION
 *  To check if vector font is supported on the platform
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL 
 *****************************************************************************/
MMI_BOOL mmi_fe_is_vector_font_support(void)
{
#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    return MMI_TRUE;
#else
    return MMI_FALSE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_is_r2l_state
 * DESCRIPTION
 *  To check if it is on r2l state under current system language
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL 
 *****************************************************************************/
MMI_BOOL mmi_fe_is_r2l_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    ret = r2lMMIFlag;
    GDI_UNLOCK;
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  SetFont
 * DESCRIPTION
 *  To set the fonts.  
 *  This is used to set all different type of font with different sizes.
 * PARAMETERS
 *  Font:            [IN] the font attribute        
 *  arrCount:       [IN] the font family       
 * RETURNS
 *  U8
 *****************************************************************************/
U8 SetFont(stFontAttribute Font, U8 arrCount)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    gnCurrentFont = Font.size;
    gbFontType = Font.smallCaps;
    gnCurrentFontAttrib = 0;

    if (gbFontType != 0)
    {
        gbFontType = 0;
    }

    if (Font.bold)
    {
        gnCurrentFontAttrib |= FONTATTRIB_BOLD;
    }
    if (Font.italic)
    {
        gnCurrentFontAttrib |= FONTATTRIB_ITALIC;
    }
    if (Font.oblique)
    {
        gnCurrentFontAttrib |= FONTATTRIB_OBLIQUE;
    }
    if (Font.underline)
    {
        gnCurrentFontAttrib |= FONTATTRIB_UNDERLINE;
    }
    if (!gnCurrentFontAttrib)
    {
        gnCurrentFontAttrib |= FONTATTRIB_NORMAL;
    }

    SetFontValues(gnCurrentFont, arrCount);
    
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    {
        U32 attr = 0;

        if(Font.bold)       attr |= FE_FONT_ATTR_BOLD;
        if(Font.italic)     attr |= FE_FONT_ATTR_ITALIC;
        if(Font.oblique)    attr |= FE_FONT_ATTR_OBLIQUE;
        if(Font.smallCaps)  attr |= FE_FONT_ATTR_SMALL_CAPS;
        if(Font.underline)  attr |= FE_FONT_ATTR_UNDERLINE;

        if (arrCount < g_mmi_fe_font_file_number[g_mmi_fe_font_family])
        {
            mmi_fe_vector_change_active(g_mmi_fe_curr_font_list[arrCount], arrCount);
        }
        //font_engine->set_font_attr(font_engine_font_attr);
        mmi_fe_set_font((U8)gnCurrentFont, attr);
    }
#endif

    GDI_UNLOCK;
    return 0;
}



/*****************************************************************************
 * FUNCTION
 *  GetFont
 * DESCRIPTION
 *  To get the current font.
 *  This is used to get current font attribute.
 * PARAMETERS
 *  Font            [IN/OUT]        
 *  arrCount        [IN/OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
void GetFont(stFontAttribute *Font, U8 *arrCount)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    memset(Font, 0, sizeof(stFontAttribute));
    *arrCount = 0;
    Font ->size = gnCurrentFont;
    Font ->smallCaps = gbFontType;	

    if ((gnCurrentFontAttrib & FONTATTRIB_BOLD))
    {
        Font->bold = MMI_TRUE;
    }
    if ((gnCurrentFontAttrib & FONTATTRIB_ITALIC))
    {
        Font->italic = MMI_TRUE;
    }
    if ((gnCurrentFontAttrib & FONTATTRIB_OBLIQUE))
    {
        Font->oblique = MMI_TRUE;
    }
    if ((gnCurrentFontAttrib & FONTATTRIB_UNDERLINE))
    {
        Font->underline = MMI_TRUE;
    }
    if ((gnCurrentFontAttrib & FONTATTRIB_NORMAL))
    {
    }
    GDI_UNLOCK;

}

/*****************************************************************************
 * FUNCTION
 *  SetFontValues
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nFont           [IN]        
 *  arrCount        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void SetFontValues(U32 nFont, U8 arrCount)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gLanguageArray[arrCount].fontfamilyList[gLanguageArray[arrCount].nCurrentFamily] == NULL)
        return;

    if ((gLanguageArray[arrCount].fontfamilyList[gLanguageArray[arrCount].nCurrentFamily]->nTotalFonts) > nFont)
    {
        gpCurrentFont =
            gLanguageArray[arrCount].fontfamilyList[gLanguageArray[arrCount].nCurrentFamily]->fontData[nFont];
    }
    else
    {
        gpCurrentFont = gLanguageArray[arrCount].fontfamilyList[gLanguageArray[arrCount].nCurrentFamily]->fontData[0];
    }
}

#if(FONTENGINE_IRAM_PLACEMENT)
#ifdef __MTK_TARGET__
#pragma arm section code
#endif 
#endif /* (FONTENGINE_IRAM_PLACEMENT) */ 

#if defined(__MMI_ZI__)


/*****************************************************************************
 * FUNCTION
 *  SearchInZiExtraFont
 * DESCRIPTION
 *  To search a character in the Zi Extra font
 *  
 *  This function applies binary search assuming that the RangeList
 *  array is sorted ina scending order and no ranges overlap.
 * PARAMETERS
 *  nCh         [IN]        
 *  pnBase      [OUT]       Returns the base
 * RETURNS
 *  S32 - The offset of the character in the Range table
 *****************************************************************************/
S32 SearchInZiExtraFont(U32 nCh, U32 *pnBase)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 nFirst = 0;
    S16 nLast = gZiExtraCharacter.pRangeDetails->nNoOfRanges - 1;
    S16 nMid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (nLast >= nFirst)
    {
        nMid = (nFirst + nLast) / 2;;
        if ((nCh >= gZiExtraCharacter_RangeData[nMid].nMin) && (nCh <= gZiExtraCharacter_RangeData[nMid].nMax))
        {
            *pnBase = gZiExtraCharacter_RangeData[nMid].nMin;
#if defined(__MMI_FONT_COMPRESSION__)
            return gZiExtraCharacter.pRange->rangeOffset[nMid];
#else
            return gZiExtraCharacter.pRange[nMid];
#endif

        }
        if (nCh > gZiExtraCharacter_RangeData[nMid].nMin)
        {
            nFirst = nMid + 1;
        }
        else
        {
            nLast = nMid - 1;
        }

    }

    return -1;
}
#endif /* defined(__MMI_ZI__) */ 

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_font_data_internal
 * DESCRIPTION
 *  To get font resource and data for a specific UCS2 character
 * PARAMETERS
 *  Ch              [IN]        
 *  Font            [IN]        
 *  ppCharData   [OUT]   
 *  pnWidth       [OUT]   
 *  advance_x   [OUT]
 *  pnHeight      [OUT]   
 *  glyph_width  [OUT]   
 *  glyph_height [OUT]   
 * RETURNS
 *  U32 the number of byte of the font resource
 *****************************************************************************/
__inline static U32 mmi_fe_get_font_data_internal(
                            U16 Ch, 
                            U8 type,
                            U8 **ppCharData, 
                            S32 *pnWidth, 
                            S32 *advance_x, 
                            U16 *pnHeight, 
                            U16 *glyph_width, 
                            U16 *glyph_height, 
                            S32* ascent, 
                            S32* descent,
                            MMI_BOOL* valid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;
    S32 NumChar = 0;
    S32 index = -1;
    S32 nFontIndex = -1;
    U32 nIndexInList;
    U32 nBase;
    U32 nHashKey = 0;
    CharHashTable *charHashTable;
#if defined(__MMI_FONT_COMPRESSION__)
    U16 block_index, block_index_next;
#endif

#ifdef __MMI_INDIC_ALG__
    sCustFontData *CurrentFont = gpCurrentFont;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *advance_x = 0;
#endif /* __MMI_INDIC_ALG__ */ 

    if (Ch & 0xFF00)
    {
        charHashTable = charHashTableOthers;
        nHashKey = Ch & OTHERS_CHAR_HT_MASK;
    }
    else
    {
        charHashTable = charHashTableLatin;
        nHashKey = Ch & LATIN_CHAR_HT_MASK;
    }

    /* for character check, we couldn't use cache. */
    if (type != MMI_FE_VALID_CHECK)
    {
        if (charHashTable[nHashKey].unicode == Ch && charHashTable[nHashKey].gnCurrentFont == gnCurrentFont)
        {
            *ppCharData = charHashTable[nHashKey].CharData;
            *pnWidth = charHashTable[nHashKey].Width;
            *pnHeight = charHashTable[nHashKey].Height;
            *advance_x = (S32)charHashTable[nHashKey].DWidth;
            /* usually the character width = data width */
            *glyph_height = *pnHeight;
            *glyph_width = * pnWidth; 
            *ascent = charHashTable[nHashKey].Ascent;
            *descent = charHashTable[nHashKey].Descent;
            if (!(gnCurrentFontAttrib & FONTATTRIB_BOLD &&
                gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_BOLD) ||
                !(gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_NORMAL))
            {
            }
            else
            {
                /* when bold word, character width is more one than data width */
                *pnWidth = *pnWidth + 1;
                *advance_x = *advance_x + 1;
            }
            
            return charHashTable[nHashKey].NumChar;
        }
    }
    charHashTable[nHashKey].unicode = Ch;
    GetLangIndex(&count, &nFontIndex, &index, Ch, &nBase);
    charHashTable[nHashKey].count = count;
    charHashTable[nHashKey].gnCurrentFont = gnCurrentFont;
    charHashTable[nHashKey].index = index;

    if (index > -1)
    {

        /* Comments : No error handling is being  done if some characters come that is not
           currently supported then nothing can be displayed */

        SetFontValues(nFontIndex, count);
        charHashTable[nHashKey].Width = *pnWidth = gpCurrentFont->nWidth;
        charHashTable[nHashKey].DWidth = *advance_x = gpCurrentFont->nWidth;
        charHashTable[nHashKey].Height = *pnHeight = gpCurrentFont->nHeight;
        charHashTable[nHashKey].Ascent = *ascent = gpCurrentFont->nAscent;
        charHashTable[nHashKey].Descent = *descent = gpCurrentFont->nDescent;

        if (gpCurrentFont->nEquiDistant)
        {
        #if defined(__MMI_FONT_COMPRESSION__)
            charHashTable[nHashKey].NumChar = NumChar = gpCurrentFont->nCharBytes;
            nIndexInList = index + (Ch - nBase);
            charHashTable[nHashKey].CharData = *ppCharData = (gpCurrentFont->pDataArray + (nIndexInList * NumChar));
        #else /* __MMI_FONT_COMPRESSION__ */
            charHashTable[nHashKey].NumChar = NumChar = gpCurrentFont->nCharBytes;
            nIndexInList = index + (NumChar * (Ch - nBase));
            charHashTable[nHashKey].CharData = *ppCharData = (gpCurrentFont->pDataArray + nIndexInList);
        #endif /* __MMI_FONT_COMPRESSION__ */
        }
        else
        {
        #if defined(__MMI_FONT_COMPRESSION__)
            nIndexInList = index + (Ch - nBase);
            block_index = mmi_fe_get_block_index(gpCurrentFont->pRange, nIndexInList);
            block_index_next = mmi_fe_get_block_index(gpCurrentFont->pRange, nIndexInList + 1);

            charHashTable[nHashKey].Width = *pnWidth = gpCurrentFont->pWidthArray[nIndexInList];
            charHashTable[nHashKey].DWidth = *advance_x = gpCurrentFont->pWidthArray[nIndexInList];
            charHashTable[nHashKey].NumChar = NumChar =
                ((block_index_next << 16) + gpCurrentFont->pOffsetArray[nIndexInList + 1])
                 - ((block_index << 16) + gpCurrentFont->pOffsetArray[nIndexInList]);
            charHashTable[nHashKey].CharData = *ppCharData =
                (gpCurrentFont->pDataArray + (block_index << 16) + gpCurrentFont->pOffsetArray[nIndexInList]);
        #else /* __MMI_FONT_COMPRESSION__ */
            nIndexInList = index + (Ch - nBase);
            charHashTable[nHashKey].Width = *pnWidth = gpCurrentFont->pWidthArray[nIndexInList];
            charHashTable[nHashKey].DWidth = *advance_x = gpCurrentFont->pWidthArray[nIndexInList];
            charHashTable[nHashKey].NumChar = NumChar =
                (gpCurrentFont->pOffsetArray[nIndexInList + 1] - gpCurrentFont->pOffsetArray[nIndexInList]);
            charHashTable[nHashKey].CharData = *ppCharData =
                (gpCurrentFont->pDataArray + gpCurrentFont->pOffsetArray[nIndexInList]);
        #endif /* __MMI_FONT_COMPRESSION__ */
        }
    #ifdef __MMI_INDIC_ALG__
        if (gpCurrentFont->pDWidthArray)
        {
            *advance_x = (S32)gpCurrentFont->pDWidthArray[nIndexInList];            
            charHashTable[nHashKey].DWidth = gpCurrentFont->pDWidthArray[nIndexInList];
        }
        gpCurrentFont = CurrentFont;
    #endif /* __MMI_INDIC_ALG__ */ 
        /* usually the character width = data width */
        *glyph_height = *pnHeight;
        *glyph_width = * pnWidth;    
        if (!(gnCurrentFontAttrib & FONTATTRIB_BOLD &&
                gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_BOLD) ||
                !(gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_NORMAL))
        {
        
        }
        else
        {
            /* when bold word, character width is one more than data width */
            *pnWidth = *pnWidth + 1;
            *advance_x = *advance_x + 1;
        }

        return NumChar;
    }
    else
    {
    #if defined(__MMI_ZI__)
        index = SearchInZiExtraFont(Ch, &nBase);
        if (index != -1)
        {
            charHashTable[nHashKey].Height = *pnHeight = gZiExtraCharacter.nHeight;
            nIndexInList = index + (Ch - nBase);
            charHashTable[nHashKey].Width = *pnWidth = gZiExtraCharacter.pWidthArray[nIndexInList];
            charHashTable[nHashKey].Ascent = *ascent = gZiExtraCharacter.nAscent;
            charHashTable[nHashKey].Descent = *descent = gZiExtraCharacter.nDescent;
            charHashTable[nHashKey].NumChar = NumChar =
                (gZiExtraCharacter.pOffsetArray[nIndexInList + 1] - gZiExtraCharacter.pOffsetArray[nIndexInList]);
            charHashTable[nHashKey].CharData = *ppCharData =
                (gZiExtraCharacter.pDataArray + gZiExtraCharacter.pOffsetArray[nIndexInList]);
            charHashTable[nHashKey].DWidth = *pnWidth;
            *advance_x = *pnWidth;
        }
        else
    #endif
        {
            index = SearchInPropFont(Ch, &nBase);
            if (index == -1)
            {
                /* ch is junk */
                MMI_TRACE(MMI_FW_TRC_G9_FE, TRC_MMI_FE_INVALID_CHARACTER, Ch);
                Ch = 65515; /* 0x4E01;//0x000F; */
                *valid = MMI_FALSE;
                index = SearchInPropFont(Ch, &nBase);
                if (index == -1)
                {
                #ifdef __MMI_INDIC_ALG__
                    gpCurrentFont = CurrentFont;
                #endif 
                    *advance_x = 0;
                    *pnWidth = 0;
                    *glyph_height = 0;
                    *glyph_width = 0;
                    *ascent = 0;
                    *descent = 0;
                    return NumChar;
                }
            }
            charHashTable[nHashKey].Height = *pnHeight = gMTKProprietaryFont.nHeight;
            nIndexInList = index + (Ch - nBase);
            charHashTable[nHashKey].Width = *pnWidth = gMTKProprietaryFont.pWidthArray[nIndexInList];
            charHashTable[nHashKey].Ascent = *ascent = gMTKProprietaryFont.nAscent;
            charHashTable[nHashKey].Descent = *descent = gMTKProprietaryFont.nDescent;
            charHashTable[nHashKey].NumChar = NumChar =
                (gMTKProprietaryFont.pOffsetArray[nIndexInList + 1] - gMTKProprietaryFont.pOffsetArray[nIndexInList]);
            charHashTable[nHashKey].CharData = *ppCharData =
                (gMTKProprietaryFont.pDataArray + gMTKProprietaryFont.pOffsetArray[nIndexInList]);
            charHashTable[nHashKey].DWidth = *pnWidth;
            *advance_x = *pnWidth;

        }

    }
#ifdef __MMI_INDIC_ALG__
    gpCurrentFont = CurrentFont;
#endif
    /* usually the character width = data width */
    *glyph_height = *pnHeight;
    *glyph_width = * pnWidth;    
    if (!(gnCurrentFontAttrib & FONTATTRIB_BOLD &&
            gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_BOLD) ||
            !(gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_NORMAL))
    {
    
    }
    else
    {
        /* when bold word, character width is one more than data width */
        *pnWidth = *pnWidth + 1;
        *advance_x = *advance_x + 1;
    }    

    return NumChar;
}

#if defined(__MMI_VECTOR_FONT_SUPPORT__)


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_char_file_info
 * DESCRIPTION
 *  To get the font file index of the specified ch
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
__inline static U8 mmi_fe_get_char_file_info(U16 ch)
{
    if (ch&1)
    {
        return (mmi_fe_font_file_cache[(ch>>1)]& 0x0f);
    }
    else
    {
        return (((mmi_fe_font_file_cache[(ch>>1)]& 0xf0)>>4) & 0x0f);
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_fe_set_active_font
 * DESCRIPTION
 *  To set font active font to the file which the specified ch belong to
 *  the value 0xf present that the file index of the specified ch is unkonw. 
 *  Then we would start a loop to find out the index.
 * PARAMETERS
 *  U16 the specified character
 * RETURNS
 *  MMI_BOOL to indicate if the ch belong to private font
 *****************************************************************************/
__inline static MMI_BOOL mmi_fe_set_active_font(U16 ch, MMI_BOOL private_first)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 fontnum; 
    U32 data_attr;
    U8 *pCharData;
    U16 glyph_width, glyph_height;
    S32 advance_x, advance_y, bearing_y, bearing_x, glyph_size;
    MMI_BOOL valid;    
    BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (private_first)
    {
        /* set to the last one */
        mmi_fe_vector_change_active(
            g_mmi_fe_private_font_file_list[g_mmi_fe_font_family], 
            g_mmi_fe_font_file_number[g_mmi_fe_font_family] - 1);
        /* check the validness */
    #if defined(__MTK_TARGET__)
        ret = INT_SwitchStackToRun(
                    g_mmi_fe_stack, 
                    MMI_FE_STACK_SIZE, 
                    (kal_func_ptr)font_engine->get_font_data, 
                    12,
                    MMI_FE_VALID_CHECK,
                    ch,
                    &pCharData,
                    &glyph_size,
                    &data_attr,
                    &glyph_width,
                    &glyph_height,
                    &bearing_x,
                    &bearing_y,
                    &advance_x,
                    &advance_y, 
                    &valid);
    #else
        ret = font_engine->get_font_data( 
                                            MMI_FE_VALID_CHECK,
                                            ch,
                                            &pCharData,
                                            &glyph_size,
                                            &data_attr,
                                            &glyph_width,
                                            &glyph_height,
                                            &bearing_x,
                                            &bearing_y,
                                            &advance_x,
                                            &advance_y, 
                                            &valid);
    #endif
        if (valid)
        {
            return MMI_TRUE;
        }
    }
    
    fontnum = mmi_fe_get_char_file_info(ch);
    if (fontnum != 0x0f)
    {
        mmi_fe_vector_change_active(g_mmi_fe_curr_font_list[fontnum], fontnum);
        return MMI_FALSE;
    }
    else
    {
        S32 i = 0;
        for (i = 0; i< g_mmi_fe_font_file_number[g_mmi_fe_font_family]; i ++)
        {
            U8 file = (i & 0xf);
            mmi_fe_vector_change_active(g_mmi_fe_curr_font_list[i], i);
        #if defined(__MTK_TARGET__)
            ret = INT_SwitchStackToRun(
                        g_mmi_fe_stack, 
                        MMI_FE_STACK_SIZE, 
                        (kal_func_ptr)font_engine->get_font_data, 
                        12,
                        MMI_FE_VALID_CHECK,
                        ch,
                        &pCharData,
                        &glyph_size,
                        &data_attr,
                        &glyph_width,
                        &glyph_height,
                        &bearing_x,
                        &bearing_y,
                        &advance_x,
                        &advance_y, 
                        &valid);
        #else
            ret = font_engine->get_font_data( 
                                                MMI_FE_VALID_CHECK,
                                                ch,
                                                &pCharData,
                                                &glyph_size,
                                                &data_attr,
                                                &glyph_width,
                                                &glyph_height,
                                                &bearing_x,
                                                &bearing_y,
                                                &advance_x,
                                                &advance_y, 
                                                &valid);
        #endif
            if (valid)
            {
                if (ch&1)
                {
                    mmi_fe_font_file_cache[(ch>>1)] &= (file | 0xf0);
                }
                else
                {
                    mmi_fe_font_file_cache[(ch>>1)] &= ((file<<4) | 0x0f);
                }
                return MMI_FALSE;
            }
        }
        MMI_TRACE(MMI_FW_TRC_G9_FE, TRC_MMI_FE_INVALID_CHARACTER, ch);
        /* no data found in all font file, set to the first font */
        if (ch&1)
        {
            mmi_fe_font_file_cache[(ch>>1)] &= (0xf0);
        }
        else
        {
            mmi_fe_font_file_cache[(ch>>1)] &= (0x0f);
        }
        mmi_fe_vector_change_active(g_mmi_fe_curr_font_list[0], 0);
    }
    return MMI_FALSE;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_fe_shaper
 * DESCRIPTION
 *  To do open type shaping
 * PARAMETERS
 *  void
 * RETURNS
 *  S32 the length of the display buffer 
 *****************************************************************************/
S32 mmi_fe_shaper(mmi_lm_lang_enum lang, UI_string_type text, S32 text_len, S32 start_index, S32 run_len, mmi_fe_text_info_p* text_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    FE_OT_FLAG ot_lang = MMI_FE_OT_DEFAULT, ot_script = MMI_FE_OT_DEFAULT;
    S32 i = 0;
    mmi_fe_cache_key_struct key;
    mmi_fe_cluster_info fe_cluster;
    S32 glyph_len = 0;
    S32 pool_usage = 0; /* pool usage in byte */
    mmi_fe_text_info_p text_p = NULL;
    U8 *pCharData;
    U32 data_attr;
    S32 pnWidth, ascent, descent;
    S32 advance_x;
    U16 glyph_width;
    U16 glyph_height; 
    S32 bearing_x; 
    MMI_BOOL valid;
    MMI_BOOL private_first = MMI_FALSE;
    MMI_BOOL private_font = MMI_FALSE;
    U32 temp_font_attr = font_engine_font_attr;
    MMI_BOOL font_set = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (lang)
    {
        case MMI_LM_LANG_THAI:
            ot_lang = MMI_FE_OT_LANG_THAI;
            ot_script = MMI_FE_OT_SCRIPT_THAI;
            break;
    #if defined(__MMI_INDIC_ALG__)        
        case MMI_LM_LANG_INDIC:
            {
                for (i = 0; i < text_len; i ++)
                {
                    switch (text[i])
                    {
                        case 0x09e4: /* Bengali */
                        case 0x0a64: /* Punjabi */
                        case 0x0ae4: /* Gujarati */
                        case 0x0b64: /* Oriya */
                        case 0x0be4: /* Tamil */
                        case 0x0c64: /* Telugu */
                        case 0x0ce4: /* Kannada */
                        case 0x0d64: /* Malayalam */
                            text[i] = 0x0964;
                            break;
                        case 0x09e5: /* Bengali */
                        case 0x0a65: /* Punjabi */
                        case 0x0ae5: /* Gujarati */
                        case 0x0b65: /* Oriya */
                        case 0x0be5: /* Tamil */
                        case 0x0c65: /* Telugu */
                        case 0x0ce5: /* Kannada */
                        case 0x0d65: /* Malayalam */
                            text[i] = 0x0965;
                            break;
                                    
                    }
                }
                switch(ire_get_character_lang_id(text[0]))
                {
                    ///TODO: check character lang by enum, and add for marathi or hindi by current language.
                    case 0x01: /* IRE_LANGUAGE_ID_HINDI */
                        /* set Hindi as first priority */
                        {
                            U8* lcc = Get_Current_Lang_CountryCode();
                            if (memcmp(lcc, "mr-IN", 5)==0)
                            {
                                ot_lang = MMI_FE_OT_LANG_MARATHI;
                                ot_script = MMI_FE_OT_SCRIPT_DEVANAGARI;
                            }
                            else
                            {
                                ot_lang = MMI_FE_OT_LANG_HINDI;
                                ot_script = MMI_FE_OT_SCRIPT_DEVANAGARI;                        
                            }
                        }
                        break;
                    ///TODO: check character by enum and add for Bengali or Assamese
                    case 0x02: /* IRE_LANGUAGE_ID_BENGALI */ 
                        /* set Bengali as first priority */
                        {
                            U8* lcc = Get_Current_Lang_CountryCode();
                            if (memcmp(lcc, "as-IN", 5)==0)
                            {
                                ot_lang = MMI_FE_OT_LANG_ASSAMESE; 
                                ot_script = MMI_FE_OT_SCRIPT_BENGALI;
                            }
                            else
                            {
                                ot_lang = MMI_FE_OT_LANG_BENGALI; 
                                ot_script = MMI_FE_OT_SCRIPT_BENGALI;                        
                            }
                        }
                        break;
                    case 0x03: /* IRE_LANGUAGE_ID_PUNJABI */                       
                        ot_lang = MMI_FE_OT_LANG_PUNJABI; 
                        ot_script = MMI_FE_OT_SCRIPT_GURMUKHI;
                        break;
                    case 0x04: /* IRE_LANGUAGE_ID_GUJARATI */                       
                        ot_lang = MMI_FE_OT_LANG_GUJARATI; 
                        ot_script = MMI_FE_OT_SCRIPT_GUJARATI;
                        break;
                    case 0x05: /* IRE_LANGUAGE_ID_ORIYA */                       
                        ot_lang = MMI_FE_OT_LANG_ORIYA; 
                        ot_script = MMI_FE_OT_SCRIPT_ORIYA;
                        break;
                    case 0x06: /* IRE_LANGUAGE_ID_TAMIL */                       
                        ot_lang = MMI_FE_OT_LANG_TAMIL; 
                        ot_script = MMI_FE_OT_SCRIPT_TAMIL;
                        break;
                    case 0x07: /* IRE_LANGUAGE_ID_TELUGU */                       
                        ot_lang = MMI_FE_OT_LANG_TELUGU; 
                        ot_script = MMI_FE_OT_SCRIPT_TELUEU;
                        break;
                    case 0x08: /* IRE_LANGUAGE_ID_KANNADA */                       
                        ot_lang = MMI_FE_OT_LANG_KANNADA; 
                        ot_script = MMI_FE_OT_SCRIPT_KANNADA;
                        break;
                    case 0x09: /* IRE_LANGUAGE_ID_MALAYALAM */                       
                        ot_lang = MMI_FE_OT_LANG_MALAYALAM; 
                        ot_script = MMI_FE_OT_SCRIPT_MALAYALAM;
                        break;                        
                }
            }
            break;
    #endif    
            default :
                if (mmi_fe_test_display_as_null(text[start_index]))
                    return 0;
                if (mmi_fe_test_display_as_space(text[start_index]))
                {
                    text = L" ";
                    run_len = 1;
                    start_index = 0;
                }
                if (mmi_fe_test_display_as_invalid(text[start_index]))
                {
                    text = L"\0xFFEB";
                    run_len = 1;
                    start_index = 0;                    
                }
                break;
    }

    
    /* 
      *  proprietary font should be checked first if
      *  1. the private flag is enable.
      *  2. the character is in private range.
      *  3. there is private font. 
    */
    if (fe_display_flag & FE_DISPLAY_FLAG_UCS2_PROPRIETARY && 
        (text[start_index] >= FE_UCS2_PROPRIETARY_START && text[start_index] <= FE_UCS2_PROPRIETARY_END) &&
        (g_mmi_fe_private_font_file_list[g_mmi_fe_font_family] != 0))
    {
        private_first = MMI_TRUE;
        private_font = mmi_fe_set_active_font(text[start_index], private_first);
        if (private_first && private_font)
            temp_font_attr |= FE_FONT_ATTR_PRIVATE;
        font_set = MMI_TRUE;
    }
       

    /* create key */
    mmi_fe_cache_key_maker(text + start_index, run_len, ot_lang, temp_font_attr, font_engine_font_size, ot_script, start_index,&key);

    /* get from cache */
    ret = mmi_fe_cache_tree_find(&key, text_info, &glyph_len);

    if (ret)
    {
        return glyph_len;
    }
    else
    {    
        if (!font_set)
            mmi_fe_set_active_font(text[start_index], private_first);
        mmi_fe_cluster_info_init(&fe_cluster);
#if defined(__MTK_TARGET__)
        ret = INT_SwitchStackToRun(
                    g_mmi_fe_stack, 
                    MMI_FE_STACK_SIZE, 
                    (kal_func_ptr)font_engine->shaper, 
                    7,
                    ot_lang, ot_script, text, text_len, start_index, run_len, &fe_cluster);
#else        
        font_engine->shaper(ot_lang, ot_script, text, text_len, start_index, run_len, &fe_cluster);
#endif

        /* update */
        for (i = 0; i < fe_cluster.glyph_len; i++)
        {
            text_p = (mmi_fe_text_info_p)&g_mmi_fe_cluster_data_pool[pool_usage];
            memcpy(text_p, &fe_cluster.glyph_buf[i], sizeof(mmi_fe_glyph_ot_info));
            text_p->glyph_data.bitmap_size = (U16)mmi_fe_get_font_data(
                                                                    MMI_FE_GLYPH_INDEX, 
                                                                    fe_cluster.glyph_buf[i].glyph_index, 
                                                                    & pCharData, 
                                                                    &data_attr, 
                                                                    &pnWidth, 
                                                                    &advance_x, 
                                                                    &glyph_width, 
                                                                    &glyph_height, 
                                                                    &bearing_x, 
                                                                    &ascent, 
                                                                    &descent, 
                                                                    &valid);

            text_p->glyph_data.advance_x = (kal_int8)advance_x;

            /* adjust bearing for some special case. such as only thai up vowel in the cluster. */
            if (i == 0 && bearing_x < 0)
            {
                text_p->glyph_data.bearing_x = 0;
            }
            else
            {
                text_p->glyph_data.bearing_x = (kal_int8)bearing_x;
            }
            text_p->glyph_data.bearing_y = (kal_int8)ascent;
            text_p->glyph_data.height = (kal_int8)glyph_height;
            text_p->glyph_data.width= (kal_int8)glyph_width;

            if (pool_usage + (text_p->glyph_data.bitmap_size >> 2) < MMI_FE_CLUSTER_POOL_SIZE)
            {
                memcpy(&text_p->glyph_data.bitmap, pCharData, text_p->glyph_data.bitmap_size);
            }
            else
            {
                ///TODO: process later
                MMI_ASSERT(0);
            }
                
            pool_usage += (sizeof(mmi_fe_glyph_ot_info) + 
                                  sizeof(mmi_fe_glyph_info) + 
                                  FE_FOUR_BYTE_ALIGN(text_p->glyph_data.bitmap_size)) >> 2;
        }
        *text_info = (mmi_fe_text_info_p)&g_mmi_fe_cluster_data_pool;

        /* save into cache */

        mmi_fe_cache_tree_save(&key, fe_cluster.glyph_len, (mmi_fe_text_info_p)&g_mmi_fe_cluster_data_pool, pool_usage << 2);
    }    

    return fe_cluster.glyph_len;
}


#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_font_data
 * DESCRIPTION
 *  To get font resource and data for a specific UCS2 character
 * PARAMETERS
 *  Ch              [IN]        
 *  Font            [IN]        
 *  ppCharData   [OUT]   
 *  pnWidth       [OUT]   
 *  advance_x   [OUT]
 *  pnHeight      [OUT]   
 *  glyph_width  [OUT]   
 *  glyph_height [OUT]   
 * RETURNS
 *  U32 the number of byte of the font resource
 *****************************************************************************/
__inline static U32 mmi_fe_get_font_data(
                            U8 type,
                            U16 ch, 
                            U8 **ppCharData, 
                            U32 *data_attr,
                            S32 *pnWidth, 
                            S32 *advance_x, 
                            U16 *glyph_width, 
                            U16 *glyph_height, 
                            S32 *bearing_x,
                            S32 *ascent, 
                            S32 *descent,
                            MMI_BOOL *valid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 dummy_pnHeight;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *valid = MMI_TRUE;

    if (type != MMI_FE_GLYPH_INDEX)
    {
        if (mmi_fe_test_display_as_null((U32)ch))
        {
            *ascent = 0;
            *descent = 0;
            *pnWidth = 0;
            *advance_x = 0;
            *glyph_height = 0;
            *glyph_width = 0;
            *data_attr = 0;
            return 0;
        }
        if (mmi_fe_test_display_as_space(ch))
        {
            ch = 0x20;
        } 
        if (mmi_fe_test_display_as_invalid(ch))
        {
            ch = 0xFFEB;
        }        
    #ifdef __MMI_VECTOR_FONT_SUPPORT__
        switch (ch)
        {
            case 0x09e4: /* Bengali */
            case 0x0a64: /* Punjabi */
            case 0x0ae4: /* Gujarati */
            case 0x0b64: /* Oriya */
            case 0x0be4: /* Tamil */
            case 0x0c64: /* Telugu */
            case 0x0ce4: /* Kannada */
            case 0x0d64: /* Malayalam */
                ch = 0x0964;
                break;
            case 0x09e5: /* Bengali */
            case 0x0a65: /* Punjabi */
            case 0x0ae5: /* Gujarati */
            case 0x0b65: /* Oriya */
            case 0x0be5: /* Tamil */
            case 0x0c65: /* Telugu */
            case 0x0ce5: /* Kannada */
            case 0x0d65: /* Malayalam */
                ch = 0x0965;
                break;                    
        }
    #endif        
        
    }
    #ifdef __MMI_VECTOR_FONT_SUPPORT__
    {
        U32 glyph_size = 0;
        MMI_BOOL ret = FALSE;
        S32 bearing_y,advance_y;
        MMI_BOOL private_first = MMI_FALSE;
        MMI_BOOL private_font = MMI_FALSE;
        
        /* 
          *  proprietary font should be checked first if
          *  1. the private flag is enable.
          *  2. the character is in private range.
          *  3. there is private font. 
        */
        if (fe_display_flag & FE_DISPLAY_FLAG_UCS2_PROPRIETARY && 
            (ch >= FE_UCS2_PROPRIETARY_START && ch <= FE_UCS2_PROPRIETARY_END) &&
            (g_mmi_fe_private_font_file_list[g_mmi_fe_font_family] != 0))
        {
            private_first = MMI_TRUE;
        }

        if (type != MMI_FE_GLYPH_INDEX)
            private_font = mmi_fe_set_active_font(ch, private_first);
        
    #if defined(__MTK_TARGET__)
        ret = INT_SwitchStackToRun(
                    g_mmi_fe_stack, 
                    MMI_FE_STACK_SIZE, 
                    (kal_func_ptr)font_engine->get_font_data, 
                    12,
                    type,
                    ch,
                    ppCharData,
                    &glyph_size,
                    data_attr,
                    glyph_width,
                    glyph_height,
                    bearing_x,
                    &bearing_y,
                    advance_x,
                    &advance_y, 
                    valid);
    #else
        ret = font_engine->get_font_data( 
                                            type,
                                            ch,
                                            ppCharData,
                                            &glyph_size,
                                            data_attr,
                                            glyph_width,
                                            glyph_height,
                                            bearing_x,
                                            &bearing_y,
                                            advance_x,
                                            &advance_y, 
                                            valid);
    #endif
        if (ret)
        {                
            *pnWidth = (*bearing_x > 0 ? *bearing_x : 0) + *glyph_width;
            *ascent      = bearing_y;
            *descent     = *glyph_height - bearing_y;
            return glyph_size;
        }
    }
    #endif
    *data_attr = 0; // don't assign any data attribute
    *bearing_x = 0;
    /* for bdf font, it is ok to save data into cache in the two case. */
    return mmi_fe_get_font_data_internal(ch,type,ppCharData,pnWidth,advance_x,&dummy_pnHeight,glyph_width,glyph_height, ascent, descent, valid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_font_data
 * DESCRIPTION
 *  to show character at the desired x, y position by the color
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
__inline static void mmi_fe_show_font_data(
                            U16 ch,
                            S32 x,
                            S32 y,
                            U8* glyph_ptr,
                            U32 glyph_size,
                            U32 glyph_attr,
                            U16 glyph_width,
                            U16 glyph_height,
                            U32 Bordered,
                            U8 font_attr,
                            gdi_color text_color,
                            gdi_color border_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    if (glyph_attr & FE_GLYPH_ATTR_USING_FONT_ENGINE)
    {
        font_engine->show_font_data(ch, x, y, glyph_ptr, glyph_size, glyph_attr, glyph_width, glyph_height, Bordered);
        return;
    }
#endif

    if (Bordered == 1 || Bordered == 2)
    {
        gdi_show_char_bordered(x, y, text_color, border_color, glyph_ptr, glyph_size, glyph_width, glyph_height, font_attr);
    }
    else if ((!
             (gnCurrentFontAttrib & FONTATTRIB_BOLD &&
              gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_BOLD) ||
             !(gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_NORMAL)) || Bordered == 3)
    {
        gdi_show_char(x, y, text_color, glyph_ptr, glyph_size, glyph_width, glyph_height, font_attr);
    }
    else
    {
        gdi_show_char(x + 1, y, text_color, glyph_ptr, glyph_size, glyph_width, glyph_height, font_attr);
        gdi_show_char(x, y, text_color, glyph_ptr, glyph_size, glyph_width, glyph_height, font_attr);
    }
}


#if defined(__MMI_FONT_COMPRESSION__)
/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_block_index
 * DESCRIPTION
 *  To Get block index of  compress data.
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_fe_get_block_index(mmi_font_range_offset_struct *rangeOffset, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < rangeOffset->num_of_block; i++)
    {
        if (index < (rangeOffset->block_index_array)[i])
        {
            return i;
        }
    }

    return -1;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  GetLangIndex
 * DESCRIPTION
 *  To get the language index of the character.
 * PARAMETERS
 *  pCount        [OUT]  The langugae Index
 *  pnFontIndex [OUT] 
 *  pnIndex       [OUT]  The offset of the character in the array
 *  nCh            [IN]     The character to look for
 *  pnBase        [OUT]  Base of Character set
 * RETURNS
 *  void
 *****************************************************************************/
static void GetLangIndex(U8 * pCount, S32 * pnFontIndex, S32 * pnIndex, U32 nCh, U32 * pnBase)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* first check the index in the current language. 90% of the cases strings will be from current language */
    U16 nFontCount;
    sFontFamily *pFontFamily;
    U16 nFontAttrib = gnCurrentFontAttrib;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    *pCount = 0;

    while (*pCount < gMaxDeployedLangs)
    {
        pFontFamily = gLanguageArray[*pCount].fontfamilyList[gLanguageArray[*pCount].nCurrentFamily];
        nFontCount = 0;
        if (gnCurrentFontAttrib & FONTATTRIB_BOLD && (U32) (pFontFamily->fontData[nFontCount]->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_BOLD)) /* this will test for bold font.. which ever font is bold will betaken */
            /* bold is super set. If font is displayed for bold and italic then the bold font will be made as italic */
        {
            nFontAttrib = FONTATTRIB_BOLD;
        }
        else
        {
            nFontAttrib &= ~FONTATTRIB_BOLD;
            if (!nFontAttrib)
            {
                nFontAttrib |= FONTATTRIB_NORMAL;
            }
        }

#if defined(__MMI_VECTOR_FONT_SUPPORT__)
        if (pFontFamily != NULL)
        {
#endif
        while (nFontCount < pFontFamily->nTotalFonts)
        {
            if ((U32) (pFontFamily->fontData[nFontCount]->pFontType[gnCurrentFont][gbFontType] & nFontAttrib))
            {
                if (nCh >= pFontFamily->fontData[nFontCount]->pRangeDetails->pRangeData[0].nMin &&
                    nCh <=
                    pFontFamily->fontData[nFontCount]->pRangeDetails->pRangeData[pFontFamily->fontData[nFontCount]->
                                                                                 pRangeDetails->nNoOfRanges - 1].nMax)
                {

                    *pnIndex = SearchIndexinList(*pCount, nFontCount, nCh, pnBase);
                    if (*pnIndex == -1)
                    {
                        ++nFontCount;
                    }
                    else
                    {
                        gpCurrentFont = pFontFamily->fontData[nFontCount];
                        *pnFontIndex = nFontCount;
                        return;
                    }

                }   /* if(nCh>=pFontFamily->fontData[nFontCount].pRangeData[0].nMin && */
                else
                {
                    ++nFontCount;
                }
            }
            else
            {
                ++nFontCount;
            }
        }   /* while(nFontCount < pFontFamily->nTotalFonts) */
    #if defined(__MMI_VECTOR_FONT_SUPPORT__)
        }
    #endif

        ++(*pCount);

    }   /* while(*pCount < gMaxDeployedLangs) */

    if (*pnIndex == -1)
    {
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  SearchIndexinList
 * DESCRIPTION
 *  To search index and base of the character in a language.
 *  
 *  This function applies binary search assuming that the RangeList
 *  array is sorted ina scending order and no ranges overlap.
 * PARAMETERS
 *  nListIndex      [IN]        
 *  nFontCount      [IN]        
 *  nCh             [IN]        
 *  pnBase          [OUT]       Returns the base
 * RETURNS
 *  S32 - The offset of the character in the Range table
 *****************************************************************************/
static S32 SearchIndexinList(U8 nListIndex, U16 nFontCount, U32 nCh, U32 *pnBase)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 nFirst = 0;
    S16 nLast =
        gLanguageArray[nListIndex].fontfamilyList[gLanguageArray[nListIndex].nCurrentFamily]->fontData[nFontCount]->
        pRangeDetails->nNoOfRanges - 1;
    const RangeData *pRangeData =
        gLanguageArray[nListIndex].fontfamilyList[gLanguageArray[nListIndex].nCurrentFamily]->fontData[nFontCount]->
        pRangeDetails->pRangeData;
#if defined(__MMI_FONT_COMPRESSION__)
    const U16 *pRange =
        gLanguageArray[nListIndex].fontfamilyList[gLanguageArray[nListIndex].nCurrentFamily]->fontData[nFontCount]->
        pRange->rangeOffset;
#else /* __MMI_FONT_COMPRESSION__ */
    U32 *pRange =
        gLanguageArray[nListIndex].fontfamilyList[gLanguageArray[nListIndex].nCurrentFamily]->fontData[nFontCount]->
        pRange;
#endif /* __MMI_FONT_COMPRESSION__ */
    S16 nMid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (nLast >= nFirst)
    {
        nMid = (nFirst + nLast) / 2;;
        if ((nCh >= pRangeData[nMid].nMin) && (nCh <= pRangeData[nMid].nMax))
        {
            *pnBase = pRangeData[nMid].nMin;
            return pRange[nMid];

        }
        if (nCh > pRangeData[nMid].nMin)
        {
            nFirst = nMid + 1;
        }
        else
        {
            nLast = nMid - 1;
        }

    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  SearchInPropFont
 * DESCRIPTION
 *  To search a character in the properitory font
 *  
 *  This function applies binary search assuming that the RangeList
 *  array is sorted ina scending order and no ranges overlap.
 * PARAMETERS
 *  nCh         [IN]        
 *  pnBase      [OUT]       Returns the base
 * RETURNS
 *  S32 - The offset of the character in the Range table
 *****************************************************************************/
static S32 SearchInPropFont(U32 nCh, U32 *pnBase)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 nFirst = 0;
    S16 nLast = gMTKProprietaryFont.pRangeDetails->nNoOfRanges - 1;
    S16 nMid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (nLast >= nFirst)
    {
        nMid = (nFirst + nLast) / 2;;
        if ((nCh >= gMTKProprietaryFont_RangeData[nMid].nMin) && (nCh <= gMTKProprietaryFont_RangeData[nMid].nMax))
        {
            *pnBase = gMTKProprietaryFont_RangeData[nMid].nMin;
#if defined(__MMI_FONT_COMPRESSION__)
            return gMTKProprietaryFont.pRange->rangeOffset[nMid];
#else
            return gMTKProprietaryFont.pRange[nMid];
#endif

        }
        if (nCh > gMTKProprietaryFont_RangeData[nMid].nMin)
        {
            nFirst = nMid + 1;
        }
        else
        {
            nLast = nMid - 1;
        }

    }

    return -1;
}

/*****************************************************************************
 * FUNCTION
 *  Get_CharWidthHeight_internal
 * DESCRIPTION
 *  To get the font info of the desired character
 * PARAMETERS
 *  ch         [IN]        
 *  pdWidth [OUT]            the dwidth of the character. 
                                     If the character is not Indic character. The dwidth is equal to width.
 *  pWidth   [OUT]            the width of the ch.
 *  pHeight  [OUT]            the height of the ch.
 *  pAscent [OUT]            the ascent of the ch.
 *  pDescent [OUT]          the descent of the ch.
 * RETURNS
 *  FE_GLYPH_ATTR_USING_FONT_ENGINE or 0
 *****************************************************************************/
static U32 Get_CharWidthHeight_internal(U32 Ch, S32 *pdWidth, S32 *pWidth, S32 *pHeight, S32 *pAscent, S32 *pDescent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *pCharData;
    U32 data_attr;
    S32 pnWidth;
    S32 advance_x;
    U16 glyph_width;
    U16 glyph_height; 
    S32 bearing_x; 
    MMI_BOOL valid;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_fe_get_font_data(MMI_FALSE, (U16)Ch, &pCharData, &data_attr, &pnWidth, &advance_x, &glyph_width, &glyph_height, &bearing_x, pAscent, pDescent, &valid);
    *pdWidth = advance_x;
    *pWidth = pnWidth;
    *pHeight = glyph_height;
    return data_attr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_glyph_metrics
 * DESCRIPTION
 *  This is used to get the glyph metrics for a sepcified character. 
 *  The font metrics is considered with font attribute.
 *  The caller to use this API should get GDI lock first for thread safe in font engine.
 * PARAMETERS
 *  ch:                   [IN]  the ucs2 code for the character      
 *  metrics:             [OUT] the metrics for the ch        
 * RETURNS
 *  MMI_BOOL        [OUT] to indicate if the character is valid or not. 
 *                                 If it is invalid character, the metrics info is the info for nil character.
 *****************************************************************************/
MMI_BOOL mmi_fe_get_glyph_metrics(U16 ch, mmi_fe_glyph_metrics_struct_p matrix)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *pCharData;
    U32 data_attr;
    S32 pnWidth;
    S32 advance_x;
    U16 glyph_width;
    U16 glyph_height; 
    S32 bearing_x; 
    MMI_BOOL valid;
    S32 ascent, descent;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    FE_LOCK;
    mmi_fe_get_font_data(MMI_FALSE, ch, &pCharData, &data_attr, &pnWidth, &advance_x, &glyph_width, &glyph_height, &bearing_x, &ascent, &descent, &valid);
    matrix->adv_x = (S16)advance_x;
    matrix->width = glyph_width;
    matrix->height = glyph_height;
    matrix->descent = (S16)descent;
    matrix->ascent = (S16)ascent;
    /* enlarge the font width for italic or qblique if it is bitmap font. */
    if ((gnCurrentFontAttrib & (FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE)) && data_attr == 0)
    {
        matrix->width += (font_tilt_table[matrix->height]);
    }
    if ((gnCurrentFontAttrib & (FONTATTRIB_BOLD)) && data_attr == 0)
    {
        matrix->width += 1;
    }
    /* add one pixel height for the underline */
    if (gnCurrentFontAttrib & FONTATTRIB_UNDERLINE)
    {
        matrix->descent++;
    }
    FE_UNLOCK;
    return valid;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_font_engine_get_baseline_internal
 * DESCRIPTION
 *  This is used to get the baseline for first n (len) character of the input string (st).
 * PARAMETERS
 *  st                   [IN]        
 *  len                 [IN]        
 *  Font               [IN]    
 *  LineHeight       [OUT]  the height of the string.
 * RETURNS
 *  S32             [OUT] baseline for the string
 *****************************************************************************/
static S32 mmi_font_engine_get_baseline_internal(U8 *st, S32 len, S32 *LineHeight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 baseline = 0;
    U32 unicode = 0;
    S32 Width = 0, Height = 0, Ascent = 0, Descent = 0, dwidth = 0, max_descent = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* error check */
    if (len < 0)
        return MMI_FONT_ENGINE_ZERO_LENGTH;
    if (st == NULL)
        return MMI_FONT_ENGINE_ERROR_NULL_STRING;

    while (len != 0)
    {
        if ((st[0] == '\0') && (st[1] == '\0'))
            break;
        len --;

        unicode = st[0];
        unicode |= (st[1] << 8);
        Get_CharWidthHeight_internal(unicode, &dwidth, &Width,& Height, &Ascent, &Descent);
    #if defined(__MMI_LANG_THAI__) && !defined(__MMI_VECTOR_FONT_SUPPORT__)
        if (IsThaiToneMark(unicode))
            Ascent++;
    #endif
        
        if (Ascent > baseline)
            baseline = Ascent;
        if(Descent > max_descent)
            max_descent = Descent;
        st+=2;
    }
    *LineHeight = (max_descent + baseline);
    return baseline;

}




/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_lang_id
 * DESCRIPTION
 *  To get lang id by input char
 * PARAMETERS
 *  char                   [IN]        
 * RETURNS
 *  mmi_fe_lang_id     the enum of the langauge id
 *****************************************************************************/
__inline static mmi_fe_lang_id mmi_fe_get_lang_id(U32 ch)
{
    
#ifdef __MMI_ARSHAPING_ENGINE__
    if(ch < 0x0600) return MMI_FE_LANG_OTHERS;
    if(ch < 0x06FF) return MMI_FE_LANG_ARABIC;
#endif

#ifdef __MMI_INDIC_ALG__
    if(ch < 0x0900) return MMI_FE_LANG_OTHERS;
    if(ch < 0x0DF4) return MMI_FE_LANG_INDIC;    
#endif

#ifdef __MMI_LANG_THAI__
    if(ch < 0x0E01) return MMI_FE_LANG_OTHERS;
    if(ch < 0x0E7F) return MMI_FE_LANG_THAI;
#endif

#ifdef __MMI_INDIC_ALG__
    if(ch < 0xe900) return MMI_FE_LANG_OTHERS;
    if(ch < 0xee52) return MMI_FE_LANG_INDIC;
#endif

#ifdef __MMI_ARSHAPING_ENGINE__
    if(ch < 0xFB50) return MMI_FE_LANG_OTHERS;
    if(ch < 0xFDFF) return MMI_FE_LANG_ARABIC;
#endif

#if defined(__MMI_ARSHAPING_ENGINE__)
    if(ch < 0xFE70) return MMI_FE_LANG_OTHERS;
    if(ch < 0xFEFF) return MMI_FE_LANG_ARABIC;
#endif
    return MMI_FE_LANG_OTHERS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_string
 * DESCRIPTION
 *  To display string in the screen
 * PARAMETERS
 *  param:                   [IN]        the input parameter for string display
 * RETURNS
 *  UNIT32  how many character is diaplyed.
 *****************************************************************************/
U32 mmi_fe_show_string(mmi_fe_showstring_info_struct_p param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_showstring_int_param_struct param_in;
    U32 ret;
    S32 clip_x1, clip_x2, clip_y1, clip_y2;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (param->len <= 0 || param->String == NULL)
    {
        return 0;
    }

    if (param->enable_truncated)
    {
        ret = mmi_font_engine_show_truncated_text(
            param->x, 
            param->y, 
            param->truncated_width, 
            param->String, 
            param->truncated_symbol, 
            param->Bordered);
    }
    else
    {
        
        memset(&param_in, 0, sizeof(mmi_fe_showstring_int_param_struct));
        gdi_layer_get_clip(&clip_x1, &clip_y1, &clip_x2, &clip_y2);
        param_in.x = param->x;
        param_in.y = param->y;
        param_in.String = param->String;
        param_in.assign_direction = param->assign_direction;
        param_in.BaseLineHeight = param->BaseLineHeight;
        param_in.char_gap = param->char_gap;
        param_in.len = param->len;
        param_in.enable_truncated = MMI_FALSE;
        param_in.truncated_symbol = NULL;
        param_in.visible_x_start = -1;
        param_in.visible_x_end = -1;
        param_in.Bordered = param->Bordered;
        param_in.render_flag = param->render_flag;        
        param_in.clip_x1 = clip_x1;
        param_in.clip_x2 = clip_x2;
        param_in.clip_y1 = clip_y1;
        param_in.clip_y2 = clip_y2;    
        ret = mmi_fe_show_string_int(&param_in);
    }
	return ret;
}

#if defined(__MMI_LANG_THAI__)


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_is_thai_character
 * DESCRIPTION
 *  Check if the character is thai character
 * PARAMETERS
 *  curCh                   [IN]        character to check
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_fe_is_thai_character(U16 curCh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((curCh >= 0x0E01 && curCh <= 0x0E7F) ||
        (curCh == 0xF700) || (curCh == 0xF70F))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_thai_char_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  CurrentX        [IN]        
 *  CurrentY        [IN]        
 *  Font            [IN]        
 *  BackGround      [IN]        
 *  curCh           [IN]        
 *  LineHeight      [IN]        
 *  Bordered        [IN]        
 *  pre2Ch          [IN]        
 *  preCh           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
__inline static S32 mmi_fe_show_thai_char_internal(
        S32 CurrentX,
        S32 CurrentY,
        U16 pre2Ch,
        U16 preCh,
        U16 curCh,
        mmi_fe_showstring_int_param_struct_p param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *CharData;
    U32 CharDataAttr;
    U32 NumChar;
    S32 nWidth;
    U16 glyph_width;
    U16 glyph_height;
    S32 ascent;
    S32 descent;
    S32 bearing_x;
    S32 advance_x;
    S32 iX = CurrentX;
    S32 iY = CurrentY;
    static S32 pre_base_x, pre_up_vowel_x, pre_down_vowel_x;
    MMI_BOOL valid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check for formatting character */
    if (mmi_fe_test_display_as_null((U32)curCh))
        return 0;

#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
	mmi_trace_screen_char(CurrentX, CurrentY, curCh, 0, param->Bordered);
#endif

    NumChar = mmi_fe_get_font_data(
                       MMI_TRUE, 
                       curCh, 
                       &CharData,
                       &CharDataAttr, 
                       &nWidth, 
                       &advance_x, 
                       &glyph_width, 
                       &glyph_height, 
                       &bearing_x,
                       &ascent, 
                       &descent,
                       &valid);

    /* adjust iX and iY for Thai characters */
    if (CharDataAttr==0 && mmi_fe_is_thai_character(curCh))
    {
        if (IsThaiBaseLineChar(curCh))
        {
            if (IsThaiLongTailChar(preCh))
            {
                iX += 1;
                advance_x += 1;
            }
            //if the current character is 0x0E33 and previous or previous 2 character is base line character, 0x0E33 shall be
            //moved ahead to let the circyle sign on the top of previous or previous2 character
            if (curCh == 0x0E33 && (IsThaiBaseLineChar(preCh) || IsThaiBaseLineChar(pre2Ch)))
            {
                iX -= 1;
                advance_x -= 1;
            }
            pre_base_x = iX;
        }
        else if (IsThaiAboveLineChar(curCh))
        {
            /* Above line characters */
            iY -= 1;    /* Reserver 1 pixtel vertical interleaving */
            if (IsThaiBaseLineChar(preCh) && IsThaiConsonant(preCh))
            {
                /* Process the X coordinate when combining with other base line characters */
                iX -= ((S32) nWidth);
                if (IsThaiLongTailChar(preCh))  /* move ahead 3 pixels, */
                {
                    iX -= 3;
                    if (iX < pre_base_x)
                        iX = pre_base_x;
                }
                else if (preCh == 0x0E0A || preCh == 0x0E0B)
                {
                    iX -= 2;
                }
                else if (preCh == 0x0E2C)   /* move ahead 6 pixels */
                {
                    iX -= 2;
                    if (glyph_height <= 17 && (curCh == 0x0e34 || curCh == 0x0e35 || curCh == 0x0e37))
                    {
                        iX -= 1;
                    }
                #if ! (defined(__MMI_MAINLCD_128X128__) ||defined(__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_176X220__))
                    else if (glyph_height == 20)
                    {
                        switch (curCh)
                        {
                            case 0x0e31:
                                iX -= 1;
                                break;
                            case 0x0e34: 
                            case 0x0e35:
                            case 0x0e36: 
                            case 0x0e37:   
                            case 0x0e47:    
                                iX = pre_base_x;
                                break;
                        }
                    }
                #if defined(__MMI_MAINLCD_320X480__)    
                    else if (glyph_height == 24)
                    {
                        switch (curCh)
                        {
                            case 0x0e4c:
                                iX -= 2;
                                break;
                            case 0x0e31: 
                            case 0x0e34:
                            case 0x0e35:
                            case 0x0e36:
                            case 0x0e37:
                            case 0x0e47:
                                iX = pre_base_x;
                                break;
                        }
                    }
                #endif    
                #endif    
                    if (iX < pre_base_x)
                        iX = pre_base_x;
                }
            }
            else if (IsThaiUpDownVowel(preCh) && IsThaiUpSign(curCh))
            {
                if (IsThaiUpVowel(preCh))
                {
                    iY -= 3;
                    iX = pre_up_vowel_x;
                }
                else
                {
                    iX -= ((S32) nWidth);
                }

                if (!IsThaiBaseLineChar(pre2Ch))
                {
                    if (IsThaiBottomLineChar(preCh))
                    {
                        if (iX < pre_down_vowel_x)
                            iX = pre_down_vowel_x;
                    }
                    else if (IsThaiAboveLineChar(preCh))
                    {
                        if (iX < pre_up_vowel_x)
                            iX = pre_up_vowel_x;
                    }
                }
            }

            if (IsThaiUpVowel(curCh))
                pre_up_vowel_x = iX;
        }
        else if (IsThaiBottomLineChar(curCh))
        {
            /* Bottom line characters */
            if (IsThaiBaseLineChar(preCh))
            {
                iX -= ((S32) nWidth);                
            }
            pre_down_vowel_x = iX;
        }
        else if (IsThaiToneMark(curCh))
        {
            /* Tone marks */
            iY -= 1;
            if (IsThaiBaseLineChar(preCh) && preCh != 0x0e30)
            {
                iX -= ((S32) nWidth);
                if (preCh == 0x0E33)
                {
                    iY -= 3;    /* move tone mark higher */
                    if (IsThaiBaseLineChar(pre2Ch))
                    {
                        iX -= 7;    /* Move tone mark ahead across the width of */
                    }

                }
                else if (IsThaiLongTailChar(preCh))
                {
                    iX -= 2/*3*/;    /* move tone mark ahead for 3 pixel */
                #if ! (defined(__MMI_MAINLCD_128X128__) ||defined(__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_176X220__))
                    if (glyph_height == 20 && preCh == 0x0e1b && (curCh == 0x0e48 || curCh == 0x0e49 || curCh == 0x0e4b))
                    {
                        iX -= 1;
                    }
                    else if (glyph_height == 20 && preCh == 0x0e1d && (curCh == 0x0e48 || curCh == 0x0e49 || curCh == 0x0e4b))
                    {
                        iX -= 1;
                    }
                    else if (glyph_height == 20 && preCh == 0x0e1f)
                    {
                        iX -= 1;
                    }
                #if defined(__MMI_MAINLCD_320X480__)
                    else if (glyph_height == 24 && preCh == 0x0e1b && (curCh == 0x0e48 || curCh == 0x0e49 || curCh == 0x0e4b))
                    {    
                        iX -= 2;
                    }
                    else if (glyph_height == 24 && preCh == 0x0e1d && (curCh == 0x0e48 || curCh == 0x0e49 || curCh == 0x0e4b))
                    {    
                        iX -= 2;
                    }
                    else if (glyph_height == 24 && preCh == 0x0e1f)
                    {    
                        iX -= 2;
                    }
                #endif    
                #endif                    
                    if (iX < pre_base_x)
                        iX = pre_base_x;
                }
                else if (preCh == 0x0E0A || preCh == 0x0E0B)
                {
                    iX -= 2;
                }
                else if (preCh == 0x0E2C)
                {
                    iX -= 2;
                    if (glyph_height <= 17)
                    {
                        if (curCh == 0x0e48 || curCh == 0x0e4b)
                        {
                            iX -= 2;
                        }
                    }
                #if ! (defined(__MMI_MAINLCD_128X128__) ||defined(__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_176X220__))
                    else if (glyph_height == 20)
                    {
                        switch (curCh)
                        {
                            case 0x0e48:
                                iY -= 1;
                                break;
                            case 0x0e49:
                            case 0x0e4a:
                            case 0x0e4b:
                                iX -= 1;
                                break;
                        }
                    }
                #if defined(__MMI_MAINLCD_320X480__)
                    else if (glyph_height == 24)
                    {
                        iX -= 4;
                    }
                #endif
                #endif
                    if (iX < pre_base_x)
                        iX = pre_base_x;
                }
                else if (preCh == 0x0e13 || (preCh == 0x0e19 && glyph_height > 17) || preCh == 0x0e28 || preCh == 0x0e29 || preCh == 0x0e2A)
                {
                    iX -= 3;
                }
                else if (preCh == 0x0e19 && glyph_height <= 17)
                {
                    iX -= 1;
                }
            }
            else if (IsThaiSignChar(preCh))
            {
                
            }
            else if (IsThaiAboveLineChar(preCh))
            {
                iY -= 3;
                iX -= ((S32) nWidth);
                if (IsThaiLongTailChar(pre2Ch))
                {
                    iX -= 3;
                }
                else if (pre2Ch == 0x0E0A || pre2Ch == 0x0E0B)
                {
                    iX -= 2;
                }
                else if (pre2Ch == 0x0E2C)
                {
                    iX -= 3;
                }
                
                if (IsThaiBaseLineChar(pre2Ch))
                {
                    if (iX < pre_base_x)
                        iX = pre_base_x;
                }
                else
                {
                    if (iX < pre_up_vowel_x)
                        iX = pre_up_vowel_x;
                }

            }
            else if (IsThaiBottomLineChar(preCh))
            {
                iX -= ((S32) nWidth);
                if (IsThaiLongTailChar(pre2Ch))
                {
                    iX -= 3;
                }

                if (IsThaiBaseLineChar(pre2Ch))
                {
                    if (iX < pre_base_x)
                        iX = pre_base_x;
                }
                else
                {
                    if (iX < pre_down_vowel_x)
                        iX = pre_down_vowel_x;
                }
            }
            else if (preCh == 0x0E47 || preCh == 0x0E4C)
            {
                /* move the tone mark to next character space */
                iX += ((S32) nWidth);
            }

        }
        else if (IsThaiSignChar(curCh))
        {
            if (IsThaiBaseLineChar(preCh) && IsThaiUpSign(curCh))
            {
                iX -= ((S32) nWidth);
            }
            if (IsThaiLongTailChar(preCh))
            {
                iX -= 2;
            }
            if (!IsThaiBaseLineChar(pre2Ch))
            {
                if (IsThaiBottomLineChar(preCh))
                {
                    if (iX < pre_down_vowel_x)
                        iX = pre_down_vowel_x;
                }
                else if (IsThaiAboveLineChar(preCh))
                {
                    if (iX < pre_up_vowel_x)
                        iX = pre_up_vowel_x;
                }
            }
        }
        //(1)Other cases: For Thai digits and base line sign, the only thing we have to do is moving cursor
        //(2)Show Characters

    }
    {
        iY = iY + (param->BaseLineHeight - ascent);
        iX += bearing_x;
        if (param->max_ascent < ascent)
            param->max_ascent = ascent;
        if (param->max_descent < descent)
            param->max_descent = descent;

        
        if (param->enable_truncated)
        {
            if (r2lMMIFlag)
            {
                if (iX  < param->visible_x_start)
                {
                    return advance_x;
                }
                else
                {
                    param->enable_truncated = MMI_FALSE;
                    param->truncated_symbol_start = iX ;
                }
            }
            else
            {
                if (iX  + nWidth > param->visible_x_end)
                {
                    param->enable_truncated = MMI_FALSE;
                    param->truncated_symbol_start = iX ;                    
                    return advance_x;
                }        
            }
        }

        mmi_fe_show_font_data(curCh , iX ,iY,CharData,NumChar,CharDataAttr,glyph_width,glyph_height,
                              param->Bordered,gnCurrentFontAttrib,param->text_color,param->border_color);
    }
    return advance_x;
}


#endif /* defined(__MMI_LANG_THAI__) */


#if !defined(__MMI_VECTOR_FONT_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_single_cluster_other
 * DESCRIPTION
 *  To display one cluster for common language
 * PARAMETERS
 *  param                   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fe_show_single_cluster_other(mmi_fe_show_one_cluster_param_struct_p param, gdi_color text_color, gdi_color border_color)
{
    UI_character_type curch = 0;
    S32 i;
    U8 *CharData;
    U32 CharDataAttr;    
    U32 NumChar;
    S32 nWidth = 0;
    S32 bearing_x;
    S32 advance_x;
    U16 glyph_width = 0;
    U16 glyph_height = 0;
    S32 ascent = 0;
    S32 descent = 0;
    MMI_BOOL bordered = param->bordered;
    MMI_BOOL valid;
    S32 curX = param->x;
    S32 y_offset;
    for (i = 0; i < param->len; i ++)
    {
        curch = param->string[(i << 1)] | (param->string[(i << 1)+1] << 8);
        NumChar = mmi_fe_get_font_data(MMI_FE_GET_DATA, curch, &CharData,&CharDataAttr, &nWidth, &advance_x, &glyph_width, &glyph_height, &bearing_x,&ascent, &descent, &valid);
        y_offset = param->y+ (param->baseline - ascent);
        if (i == 0 && bearing_x < 0)
            bearing_x = 0;
        if (NumChar)
            mmi_fe_show_font_data(curch , curX + bearing_x,y_offset,CharData,NumChar,CharDataAttr,glyph_width,glyph_height,
                              bordered,gnCurrentFontAttrib,text_color,border_color);
        curX+= advance_x;

    }
}

#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_string_int
 * DESCRIPTION
 *  To display a string in the screen
 * PARAMETERS
 *  param                   [IN]        
 * RETURNS
 *  UNIT32
 *****************************************************************************/
static U32 mmi_fe_show_string_int(mmi_fe_showstring_int_param_struct_p param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len = param->len;
    S32 curX = 0, curY = 0;
#if defined(__MMI_ARSHAPING_ENGINE__)
    MMI_BOOL IS_ARABIC = MMI_FALSE;
#endif
#if defined(__MMI_BIDI_ALG__)
    MMI_BOOL IS_BIDI = MMI_FALSE;
#endif
    S32 check_len = 0;
    U8 *temp_string = param->String;
    U8 *String = param->String;
    U16 visual_str_len = 0, visual_cur_pos = 0;
    BIDI_PARAGRAPH_TYPES paratype = P_LTR;
    S32 lang_string_group = 0;
    U8 *lang_string_start = NULL;
    S32 x_offset = 0;
    S32 totalLineHeight = 0;
    gdi_color border_color = 0, text_color;
    U32 render_flag = param->render_flag;
    U8 tempFontAttrib = gnCurrentFontAttrib;
    MMI_BOOL enableTruncated = param->enable_truncated;
    MMI_BOOL drawTwice = MMI_FALSE;
    S32 max_descent = 0, temp_descent;
    MMI_BOOL border;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    FE_LOCK;

    
#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
    mmi_trace_screen_string(param->x, param->y, String, len, param->Bordered);
#endif
    if (param->Bordered && 
        g_mmi_fe_text_border_color.r == TRANSPARENT_COLOR_R && 
        g_mmi_fe_text_border_color.g == TRANSPARENT_COLOR_G && 
        g_mmi_fe_text_border_color.b == TRANSPARENT_COLOR_B)
    {
        param->Bordered = 0;
    }
    border = param->Bordered;

    border_color =
        gdi_act_color_from_rgb(0xff, g_mmi_fe_text_border_color.r, g_mmi_fe_text_border_color.g, g_mmi_fe_text_border_color.b);        
    text_color =
        gdi_act_color_from_rgb(0xff, g_mmi_fe_text_color.r, g_mmi_fe_text_color.g, g_mmi_fe_text_color.b);
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    font_engine->set_font_color(text_color,border_color);
#endif
    
    gnCurrentFontAttrib &= (~(FONTATTRIB_UNDERLINE | FONTATTRIB_STRIKETHROUGH));

    /* initialize */
    param->text_color = text_color;
    param->border_color = border_color;

    if (len < 0)
    {
        len = mmi_ucs2strlen((const char *)String);
    }
#if defined(__MMI_BIDI_ALG__) || defined(__MMI_ARSHAPING_ENGINE__) 
    if (len > MAX_SHOW_STRING_TEXT_LENGTH - ENCODING_LENGTH) 
        len = MAX_SHOW_STRING_TEXT_LENGTH - ENCODING_LENGTH;
#endif

    curX = param->x;
    curY = param->y;
    /* cancelWidth = true would be set by editor */
#if !defined(__MMI_VECTOR_FONT_SUPPORT__)    
    if (r2lMMIFlag && !cancelWidth /*|| param->BaseLineHeight == -1*/)
#endif        
    {
        mmi_fe_get_string_info_param_struct query;
        query.String = String;
        query.n = len;
        query.w = param->char_gap;
        query.enableTruncated = MMI_FALSE;
        query.targetWidth = -1;

        mmi_fe_get_string_widthheight(&query);
        if (r2lMMIFlag && !cancelWidth)
        {
            curX = param->x - query.pWidth + 1;
        }
        if (param->BaseLineHeight == -1)
        {
            param->BaseLineHeight = query.baseline;
        }
    }

    

    /* the data passed from editor has been processed by BIDI and shaping. Hence, go to process. */
    if (cancelWidth)
       goto  MMI_FE_SHOW_STRING;
    
#if defined(__MMI_BIDI_ALG__)
    check_len = len;
    while (check_len != 0)
    {
        U8 dic = 0;
        U16 unicode = 0;
        if ((temp_string[0] == '\0') && (temp_string[1] == '\0'))
            break;
        check_len--;

        unicode = temp_string[0];
        unicode |= (temp_string[1] << 8);

#if defined(__MMI_ARSHAPING_ENGINE__)
        if (IS_ARABIC_CHARACTER(unicode))
            IS_ARABIC = MMI_TRUE;
#endif

        bidi_get_char_type((U8*)(&unicode), &dic);

        if (dic == BIDI_R || dic == AL || dic == AN || dic == WS)
        {
            IS_BIDI = MMI_TRUE;
        }
        
        if (IS_BIDI
#if defined(__MMI_ARSHAPING_ENGINE__)
            && IS_ARABIC
#endif
            )
            break;
        temp_string += 2;
    }

#endif

    /* shaping */
#if defined(__MMI_ARSHAPING_ENGINE__)
    if (IS_ARABIC)
    {
        mmi_ucs2ncpy((S8 *) show_pwcWord, (S8 *) String, len);
        ArabicShapeEngine_ext((U16*)&len, show_pwcWord);
        String = (U8*)&show_pwcWord;        
    }
#endif

    /* bidi */
#if defined(__MMI_BIDI_ALG__)    
    if (IS_BIDI || param->assign_direction == BIDI_R)
    {
        if (param->assign_direction == BIDI_R)
        {
            paratype = P_RTL;
        }
        bidi_main_ext(
            String, 
            (U16)len, 
            0, 
            show_visual_str, 
            &visual_str_len, 
            &visual_cur_pos, 
            NULL,
            NULL,
            MMI_FALSE,
            MMI_bidi_input_type, 
            MMI_FALSE, 
            paratype);
        String = (U8*) show_visual_str;
    }
    else
    {
        mmi_ucs2ncpy((S8 *) show_visual_str, (S8 *) String, len);
        String = (U8*) show_visual_str;
    }
#endif

MMI_FE_SHOW_STRING:

    /* baseline hasn't be got in previous step. */
    if (!(r2lMMIFlag && !cancelWidth))
    {
        if (param->BaseLineHeight == -1)
        {
			S32 baseline = mmi_font_engine_get_baseline_internal(String, len, &totalLineHeight);
    		param->BaseLineHeight = baseline;
        }
    }
    

    lang_string_start = String;
    lang_string_group = 0;
    gdi_font_begin(curX,curY,text_color, gnCurrentFontAttrib);

#ifdef __MMI_VECTOR_FONT_SUPPORT__
    if(param->Bordered) 
    {
        font_engine_font_attr |= FE_FONT_ATTR_BORDER;
        font_engine->set_font_attr(font_engine_font_attr);
#ifdef __MTK_TARGET__
        kal_check_stack(); /* if overflow , assert it */
#endif
    }
#endif

FE_SHOW_STRING_START:

    /* change param->x to real start x */
    param->x = curX;
    {
        mmi_lm_cluster_info cluster, prev_cluster, prev2_cluster;
        U8* str_end;
        U8* str_start;
        MMI_BOOL show = MMI_TRUE, show_prev = MMI_FALSE;
        mmi_lm_show_cluster_param show_param;
                
        str_start = String;
        str_end = String + len*2;
        mmi_lm_cluster_init(&prev_cluster);
        mmi_lm_cluster_init(&prev2_cluster);
        mmi_lm_cluster_init(&cluster);   
        x_offset = curX;
        show_param.cluster = &cluster;
        show_param.baseline = param->BaseLineHeight;
        show_param.y = param->y;
        show_param.bordered = param->Bordered;
        show_param.prev_cluster = &prev_cluster;
        
        do
        {
            ///TODO: check the case for r2lmmiflag

            /* variable initialize */
            show = MMI_TRUE;

            memcpy(&prev2_cluster, &prev_cluster, sizeof(mmi_lm_cluster_info));
            memcpy(&prev_cluster, &cluster, sizeof(mmi_lm_cluster_info));            
            mmi_lm_cluster_init(&cluster);   

            
            cluster.data_ptr = str_start;
            mmi_lm_get_current_cluster(cluster.data_ptr, str_end, &prev2_cluster, &prev_cluster, &cluster);

            temp_descent = cluster.h - cluster.by;
            if (temp_descent > max_descent)
                max_descent = temp_descent;

            if (cluster.lang_id != MMI_LM_LANG_OTHERS)
                drawTwice = MMI_TRUE;

            if (prev_cluster.lang_id != MMI_LM_LANG_NONE &&
                ((prev_cluster.lang_id == MMI_LM_LANG_ARABIC && cluster.lang_id != MMI_LM_LANG_ARABIC) ||
                (prev_cluster.lang_id != MMI_LM_LANG_ARABIC && cluster.lang_id == MMI_LM_LANG_ARABIC)) &&
                !render_flag)
                x_offset++;
            if ((x_offset >  param->clip_x2 + 1))
            {
                if (param->enable_truncated)
                {
                    if (x_offset > param->visible_x_start)
                    {
                        param->truncated_symbol_start = x_offset;
                        break;
                    }
                }
                else
                {
                    break;
                }
            }

            x_offset += cluster.rx;


            /* the end of the cluster is in the front of the clip x. */
            if (x_offset + cluster.w < param->clip_x1)
            {
                show = MMI_FALSE;
            }
            
            if (param->enable_truncated)
            {
                if (x_offset + cluster.w < param->visible_x_start)
                    show = MMI_FALSE;
                if (r2lMMIFlag && (x_offset < param->visible_x_start))
                    show = MMI_FALSE;
                if (r2lMMIFlag && x_offset >= param->visible_x_start)
                {
                    param->truncated_symbol_start = x_offset;
                    param->enable_truncated = MMI_FALSE;
                }
                if ( !r2lMMIFlag && (x_offset + cluster.adv_x - 1) > param->visible_x_end)
                {
                    param->truncated_symbol_start = x_offset;
                    break;
                }
            }

            show_param.x = x_offset;
            if (show)
            {
                mmi_lm_draw_cluster(&show_param);
            }
            x_offset += cluster.adv_x;
            show_prev = show;
            
            str_start+= cluster.data_len*2;
        } while (str_start < str_end);

    }

    if (param->Bordered)
    {
    #ifdef __MMI_VECTOR_FONT_SUPPORT__
        font_engine_font_attr &= ~FE_FONT_ATTR_BORDER;
        font_engine->set_font_attr(font_engine_font_attr);
    #ifdef __MTK_TARGET__
        kal_check_stack(); /* if overflow , assert it */
    #endif
    #endif
        if (drawTwice)
        {
            /* draw the data inside again */
            gdi_font_end();
            gdi_font_begin(curX, curY, text_color, gnCurrentFontAttrib);
            param->Bordered = 0;
            param->enable_truncated = enableTruncated;
            
            goto FE_SHOW_STRING_START;
        }
        
    }
    param->Bordered = border;
    gnCurrentFontAttrib = tempFontAttrib;

    if (gnCurrentFontAttrib & FONTATTRIB_UNDERLINE)
    {
        S32 height_offset = param->y + (param->BaseLineHeight + max_descent);
        gdi_draw_line( param->x, height_offset, x_offset - 1, height_offset, text_color);
    }
    if (gnCurrentFontAttrib & FONTATTRIB_STRIKETHROUGH)
    {
        S32 height_offset = param->y + ((param->BaseLineHeight + max_descent) >> 1);
        gdi_draw_line( param->x, height_offset, x_offset - 1, height_offset, text_color);
    }

    
    UI_UNUSED_PARAMETER(paratype);
    UI_UNUSED_PARAMETER(visual_cur_pos);
    UI_UNUSED_PARAMETER(visual_str_len);
    UI_UNUSED_PARAMETER(temp_string);
    UI_UNUSED_PARAMETER(check_len);
    
    gdi_font_end();

    FE_UNLOCK;
    GDI_UNLOCK;
    return x_offset;
}

#if defined(__MMI_INDIC_ALG__) && !defined(__MMI_VECTOR_FONT_SUPPORT__)

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_indic_string_internal
 * DESCRIPTION
 *  To display a string in the screen
 *  
 *  This is used to display the string in the screen
 * PARAMETERS
 *  x                   [IN]        
 *  y                   [IN]        
 *  Font                [IN]        
 *  BackGround          [IN]        
 *  String              [?]         
 *  LineHeight          [IN]        
 *  NumChar(?)          [IN]        
 *  CharData(?)         [IN]        
 *  Background(?)       [IN]        
 * RETURNS
 *  UNIT32
 *****************************************************************************/
static U32 mmi_fe_show_indic_string_internal(mmi_fe_showstring_int_param_struct_p param)
{    

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //W05.38 Remove GDI_ENTER_CRITICAL_SECTION outside GDI
    //GDI_ENTER_CRITICAL_SECTION(ShowString_internal)
    U8 *CharData;
    U32 NumChar;
    U32 Counter = 0;
    S32 CurrentX;
    U32 string_width = 0;
    S32 y = param->y;    
    S32 nXOffset;
    S32 yy = 0;
    U16 unicode = 0;
    gdi_color border_color = 0, text_color;
    S32 len = param->len;
    U8 *String = param->String;
    S32 ascent = 0, descent = 0;

    U32 CharDataAttr;    
    S32 nWidth = 0;
    S32 bearing_x;
    S32 advance_x;
    U16 glyph_width = 0;
    U16 glyph_height = 0;
    MMI_BOOL valid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  
    border_color = param->border_color;
    text_color = param->text_color;

    /* Error Check */
    if (len == 0)
    {
        return MMI_FONT_ENGINE_ZERO_LENGTH;
    }
    if (String == NULL)
        return MMI_FONT_ENGINE_ERROR_NULL_STRING;



    CurrentX = param->x;
    unicode = 0;
    
    while (len != 0)
    {
        U16 prev_unicode = 0;

    NEXT:
        len--;

        prev_unicode = unicode;
        unicode = String[0];
        unicode |= (String[1] << 8);

        if (mmi_fe_test_display_as_space(unicode))
        {
            unicode = 0x20;
	  }
        if (mmi_fe_test_display_as_invalid(unicode))
        {
            unicode = 0xFFEB;
        }        
        if (mmi_fe_test_display_as_null(unicode))
        {
            String += 2;
            if (len == 0) /* when the formatting character is the last character in the string */
                break;
            else
                goto NEXT;
        }
        
        NumChar = mmi_fe_get_font_data(MMI_TRUE, unicode, &CharData,&CharDataAttr, &nWidth, &advance_x, &glyph_width, &glyph_height, &bearing_x,&ascent, &descent, &valid);
        Counter++;
   
       if (param->max_ascent < ascent)
           param->max_ascent = ascent;
       if (param->max_descent < descent)
           param->max_descent = descent;
       
        nXOffset = CurrentX + nWidth;
        ire_get_text_x(&CurrentX, unicode, yy, advance_x, nWidth);


        if ((CurrentX > param->clip_x2 + 1) && !r2lMMIFlag)
            break;
        /* to check string width boundary when skiping first pass */
        string_width += nWidth;
        y = param->y + (param->BaseLineHeight - ascent);
        mmi_fe_show_font_data((U16)unicode, CurrentX, y, CharData, NumChar, CharDataAttr, glyph_width, glyph_height, param->Bordered, gnCurrentFontAttrib, text_color, border_color);
        CurrentX += nWidth;
        String += 2;
    }



    return CurrentX;

}



#endif



/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_display_direction
 * DESCRIPTION
 *  To get display direction by the content
 * PARAMETERS
 *  st      [IN]     the string input   
 *  dic           [OUT]        the display direction get by string content
 * RETURNS
 *  U8
 *****************************************************************************/
static mmi_font_engine_error_message_enum mmi_fe_get_display_direction(U8* st, U8* dic, S32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BIDI_ALG__)
    U8 default_direction = 0;
    U16 strongCharType = 0xFFFF;
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* error check */
    if (st == NULL) return MMI_FONT_ENGINE_ERROR_NULL_STRING;

#if defined(__MMI_BIDI_ALG__)
    while (len > 0)
    {
        bidi_get_char_type((U8 *) st, (U8 *) & default_direction);
        if (default_direction == BIDI_R || default_direction == AL || default_direction == AN)
        {
            strongCharType = BIDI_R;
            break;
        }
        else if (default_direction == BIDI_L)
        {
            strongCharType = BIDI_L;
            break;
        }
        st += 2;
        len --;
    }

    if (strongCharType == BIDI_R)
    {
        (*dic) = BIDI_R;
    }
    else
    {
        (*dic) = BIDI_L;
    }

#else
    (*dic) = BIDI_L; 
#endif
    
    return MMI_FONT_ENGINE_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_measure_string_by_char_num
 * DESCRIPTION
 *  To get string width by the fixed char width.
 *  the fixed char width is count by the max width of the character.
 *  And the string width is the max char width multiple the numofchar.
 *  The characte of Arabic series, Indic series, Thai and Vietnamese language is not allowed
 *  to be the input. 
 * PARAMETERS
 *  numofchar: [IN]  the number of character of the string
 *  st:            [IN]  all the character would be displayed as a char in the string. 
 *  width:       [OUT] the width
 *  height:      [OUT]  the height
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_measure_string_by_char_num(U8* st, S32 numofchar, S32* width, S32* height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len = mmi_ucs2strlen((const char*)st);
    S32 max_w = 0, max_ascent = 0, max_descent = 0;
    S32 w = 0, h = 0, dwidth = 0, ascent = 0, descent = 0;
    S32 i = 0;
    U32 unicode = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    FE_LOCK;
    for (i = 0 ; i < len * 2; i += 2)
    {
        unicode = st[i];
        unicode |= (st[i + 1] << 8);
        Get_CharWidthHeight_internal(unicode, &dwidth, &w, &h, &ascent, &descent);
        if (dwidth > w)
            w = dwidth;
        max_w = (w > max_w) ? w : max_w;
        max_ascent = (ascent > max_ascent) ? ascent : max_ascent;
        max_descent = (descent > max_descent) ? descent : max_descent;
        
    }

    *width = (max_w * numofchar);
    *height = (max_ascent + max_descent);
    FE_UNLOCK;
    GDI_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_engine_show_truncated_text
 * DESCRIPTION
 *  Print truncated text
 *  If length of text is greater  than screen width then the text is truncated. 
 *  The assign truncated symbol are shown at end of text
 * PARAMETERS
 *  x:                       [IN]        Start x positoin
 *  y:                       [IN]        Start Y position
 *  xwidth:                [IN]        Width of text in pixels to display. The border width is not included.
 *  st:                      [IN]        Text to display
 *  truncated_symbol: [IN]        The truncated symbol, it would be show at the end of text if truncation is necessary
 *  bordered:             [IN]        To indicate if it is border or not
 * RETURNS
 *  S32                     [OUT]   for checking if the string has been truncated
 *****************************************************************************/
mmi_font_engine_error_message_enum mmi_font_engine_show_truncated_text(S32 x, S32 y,S32 xwidth, U8 *st, U8 *truncated_symbol, MMI_BOOL bordered )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 new_xwidth; /* the new width after subtract truncated_symbol width from original width*/
    S32 symbol_width; /* the width of turncated symbol string */
    S32 symbol_height; /* the width of truncated symbol string */
    U8 default_direction = 0;
    mmi_fe_showstring_int_param_struct param;    
    S32 baseline = 0;
    mmi_fe_get_string_info_param_struct query;
    S32 len = mmi_ucs2strlen((S8*)st);
    mmi_font_engine_error_message_enum ret = MMI_FONT_ENGINE_TRUNCATION;
    S32 clip_x1, clip_x2, clip_y1, clip_y2;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* for error check */
    if (st == NULL) return MMI_FONT_ENGINE_ERROR_NULL_STRING;

    mmi_fe_get_display_direction(st, &default_direction, len);
    gdi_layer_get_clip(&clip_x1, &clip_y1, &clip_x2, &clip_y2);

    GDI_LOCK;
    /* for check if truncation is necessary */
    memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
    query.String = st;
    query.enableTruncated = MMI_FALSE;
    query.w = 0;
    query.n = len;
    mmi_fe_get_string_widthheight(&query);
    
    baseline = query.baseline;

    if (bordered && 
        g_mmi_fe_text_border_color.r == TRANSPARENT_COLOR_R && 
        g_mmi_fe_text_border_color.g == TRANSPARENT_COLOR_G && 
        g_mmi_fe_text_border_color.b == TRANSPARENT_COLOR_B)
    {
        bordered = MMI_FALSE;
    }
    memset(&param, 0, sizeof(mmi_fe_showstring_int_param_struct));

    param.x = x;
    param.y = y;
    param.String = st;
    param.BaseLineHeight = query.baseline;
    param.Bordered = bordered;
    param.len = -1;
    param.assign_direction = default_direction;
    param.char_gap = 0;
    param.clip_x1 = clip_x1;
    param.clip_x2 = clip_x2;
    param.clip_y1 = clip_y1;
    param.clip_y2 = clip_y2;    
    param.render_flag = 0;

    if (query.pWidth <= xwidth)
    {
        param.enable_truncated = MMI_FALSE;
        param.truncated_symbol = NULL;
        param.visible_x_start = -1;
        param.visible_x_end = -1;
        if (bordered)
        {
            mmi_fe_show_string_bordered_baseline(x, y, st, baseline, default_direction);
        }
        else
        {
            mmi_fe_show_string_baseline(x, y, st, baseline, default_direction);
        }
        ret = MMI_FONT_ENGINE_NO_TRUNCATION;
    }
    else
    {
        Get_StringWidthHeight(truncated_symbol, &symbol_width, &symbol_height);
        if (bordered)
        {
            symbol_width += 2;
        }

        new_xwidth = xwidth - symbol_width;
        if (new_xwidth < 0)
        {
            ret = MMI_FONT_ENGINE_ERROR_NO_TRUNCATION_AVAILABLE;
        }
        else
        {
            param.enable_truncated = MMI_TRUE;
            param.truncated_symbol = truncated_symbol;

            if (r2lMMIFlag)
            {
                param.visible_x_start = x - new_xwidth;
                param.visible_x_end = x;
            }
            else
            {
                param.visible_x_start = x;
                param.visible_x_end = x + new_xwidth;
            }
            param.y = y;

            mmi_fe_show_string_int(&param);    
            if ((!r2lMMIFlag && !(param.truncated_symbol_start >  clip_x2 + 1)) ||
                (r2lMMIFlag && !(param.truncated_symbol_start < clip_x1) ))
            {
                /* display truncated symbol */
                param.enable_truncated = MMI_FALSE;
                param.String = truncated_symbol;
                param.x = param.truncated_symbol_start;

                param.y = y;
                param.BaseLineHeight = baseline;
                if (r2lMMIFlag)
                    param.x --;
                mmi_fe_show_string_int(&param);  
            }
        }
    }
    GDI_UNLOCK;
    return ret;

}


/*****************************************************************************
 * FUNCTION
 *  ShowString_n
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x_unsigned      [IN]        
 *  y_unsigned      [IN]        
 *  Font            [IN]        
 *  BackGround      [IN]        
 *  String          [?]         
 *  Len             [IN]        
 *  LineHeight      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_fe_show_string_n(
        U32 x_unsigned,
        U32 y_unsigned,
        U8 *String,
        S32 Len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 default_direction = 0;
    mmi_fe_showstring_int_param_struct param;
    S32 clip_x1, clip_x2, clip_y1, clip_y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&param, 0, sizeof(mmi_fe_showstring_int_param_struct));
    
    mmi_fe_get_display_direction(String, &default_direction, Len);
    gdi_layer_get_clip(&clip_x1, &clip_y1, &clip_x2, &clip_y2);

    param.String = String;
    param.x = x_unsigned;
    param.y = y_unsigned;
    param.BaseLineHeight = -1;
    param.Bordered = MMI_FALSE;
    param.len = Len;
    param.enable_truncated = MMI_FALSE;
    param.truncated_symbol = NULL;
    param.visible_x_start = -1;
    param.visible_x_end = -1;
    param.assign_direction = default_direction;
    param.char_gap = 0;
    param.clip_x1 = clip_x1;
    param.clip_x2 = clip_x2;
    param.clip_y1 = clip_y1;
    param.clip_y2 = clip_y2;    
    param.render_flag = 0;

    return mmi_fe_show_string_int(&param);    

}


/*****************************************************************************
 * FUNCTION
 *  ShowString_n_baseline
 * DESCRIPTION
 *  To display a string by the assigned baseline.
 * PARAMETERS
 *  x               [IN]        
 *  y               [IN]        
 *  Font            [IN]        
 *  BackGround      [IN]        
 *  String          [?]         
 *  baseline      [IN]
 *  default_direction [IN] the direction to read the string (R2L or L2R)
 * RETURNS
 *  
 *****************************************************************************/
U32  mmi_fe_show_string_n_baseline(
        U32 x_unsigned,
        U32 y_unsigned,
        U8 *String,
        S32 Len,
        S32 baseline)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_showstring_int_param_struct param;
    U8 default_direction = 0;
    S32 clip_x1, clip_x2, clip_y1, clip_y2;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&param, 0, sizeof(mmi_fe_showstring_int_param_struct));
    
    mmi_fe_get_display_direction(String, &default_direction, Len);
    gdi_layer_get_clip(&clip_x1, &clip_y1, &clip_x2, &clip_y2);
    param.x = x_unsigned;
    param.y = y_unsigned;
    param.String = String;
    param.BaseLineHeight = baseline;
    param.Bordered = MMI_FALSE;
    param.len = Len;
    param.enable_truncated = MMI_FALSE;
    param.truncated_symbol = NULL;
    param.visible_x_start = -1;
    param.visible_x_end = -1;
    param.assign_direction = default_direction;
    param.char_gap = 0;
    param.clip_x1 = clip_x1;
    param.clip_x2 = clip_x2;
    param.clip_y1 = clip_y1;
    param.clip_y2 = clip_y2;    
    param.render_flag = 0;

    return mmi_fe_show_string_int(&param);    
    
}

/*****************************************************************************
 * FUNCTION
 *  ShowString_baseline
 * DESCRIPTION
 *  To display a string by the assigned baseline.
 * PARAMETERS
 *  x               [IN]        
 *  y               [IN]        
 *  Font            [IN]        
 *  BackGround      [IN]        
 *  String          [?]         
 *  baseline      [IN]
 *  default_direction [IN] the direction to read the string (R2L or L2R)
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_fe_show_string_baseline(S32 x, S32 y, U8 *String, S32 baseline, U8 default_direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_showstring_int_param_struct param;
    S32 clip_x1, clip_x2, clip_y1, clip_y2;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&param, 0, sizeof(mmi_fe_showstring_int_param_struct));
    
    gdi_layer_get_clip(&clip_x1, &clip_y1, &clip_x2, &clip_y2);
    param.x = x;
    param.y = y;
    param.String = String;
    param.BaseLineHeight = baseline;
    param.Bordered = MMI_FALSE;
    param.len = mmi_ucs2strlen((const char*)String);
    param.enable_truncated = MMI_FALSE;
    param.truncated_symbol = NULL;
    param.visible_x_start = -1;
    param.visible_x_end = -1;
    param.assign_direction = default_direction;
    param.char_gap = 0;
    param.clip_x1 = clip_x1;
    param.clip_x2 = clip_x2;
    param.clip_y1 = clip_y1;
    param.clip_y2 = clip_y2;    
    param.render_flag = 0;

    return mmi_fe_show_string_int(&param);    
    
}

/*****************************************************************************
 * FUNCTION
 *  ShowString
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x               [IN]        
 *  y               [IN]        
 *  Font            [IN]        
 *  BackGround      [IN]        
 *  String          [?]         
 *  LineHeight      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_fe_show_string_ext(S32 x, S32 y, U8 *String)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_showstring_int_param_struct param;
    U8 default_direction = 0;
    S32 clip_x1, clip_x2, clip_y1, clip_y2;
    S32 nLen;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&param, 0, sizeof(mmi_fe_showstring_int_param_struct));
    
    nLen = mmi_ucs2strlen((const char*)String);
    mmi_fe_get_display_direction(String, &default_direction, nLen);
    gdi_layer_get_clip(&clip_x1, &clip_y1, &clip_x2, &clip_y2);
    
    param.x = x;
    param.y = y;
    param.String = String;
    param.BaseLineHeight = -1;
    param.Bordered = MMI_FALSE;
    param.len = nLen;
    param.enable_truncated = MMI_FALSE;
    param.truncated_symbol = NULL;
    param.visible_x_start = -1;
    param.visible_x_end = -1;
    param.assign_direction = default_direction;
    param.char_gap = 0;
    param.clip_x1 = clip_x1;
    param.clip_x2 = clip_x2;
    param.clip_y1 = clip_y1;
    param.clip_y2 = clip_y2;    
    param.render_flag = 0;

    return mmi_fe_show_string_int(&param);    
}


/*****************************************************************************
 * FUNCTION
 *  ShowStringBordered_baseline
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x               [IN]        
 *  y               [IN]        
 *  Font            [IN]        
 *  BackGround      [IN]        
 *  String          [?]         
 *  LineHeight      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_fe_show_string_bordered_baseline(S32 x, S32 y, U8 *String, S32 baseline, U8 default_direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_showstring_int_param_struct param;
    S32 clip_x1, clip_x2, clip_y1, clip_y2;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&param, 0, sizeof(mmi_fe_showstring_int_param_struct));
    
    gdi_layer_get_clip(&clip_x1, &clip_y1, &clip_x2, &clip_y2);

    param.x = x;
    param.y = y;
    param.String = String;
    param.BaseLineHeight = baseline;
    param.Bordered = MMI_TRUE;
    param.len = mmi_ucs2strlen((const char*)String);
    param.enable_truncated = MMI_FALSE;
    param.truncated_symbol = NULL;
    param.visible_x_start = -1;
    param.visible_x_end = -1;
    param.assign_direction = default_direction;
    param.char_gap = 0;
    param.clip_x1 = clip_x1;
    param.clip_x2 = clip_x2;
    param.clip_y1 = clip_y1;
    param.clip_y2 = clip_y2;    
    param.render_flag = 0;
    return mmi_fe_show_string_int(&param);    
    
}


/*****************************************************************************
 * FUNCTION
 *  ShowString_by_direction
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x               [IN]        
 *  y               [IN]        
 *  Font            [IN]        
 *  BackGround      [IN]        
 *  String          [IN]         
 *  LineHeight      [IN]        
 *  default_direction [IN] the default direction for the string (R2L or L2R)
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_fe_show_string_by_direction(S32 x, S32 y, U8 *String, U8 default_direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nLen = 0;
    mmi_fe_showstring_int_param_struct param;
    S32 clip_x1, clip_x2, clip_y1, clip_y2;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&param, 0, sizeof(mmi_fe_showstring_int_param_struct));
    
    nLen = mmi_ucs2strlen((const char*)String);  
    gdi_layer_get_clip(&clip_x1, &clip_y1, &clip_x2, &clip_y2);

    param.x = x;
    param.y = y;
    param.String = String;
    param.BaseLineHeight = -1;
    param.Bordered = MMI_FALSE;
    param.len = nLen;
    param.enable_truncated = MMI_FALSE;
    param.truncated_symbol = NULL;
    param.visible_x_start = -1;
    param.visible_x_end = -1;
    param.assign_direction = default_direction;
    param.char_gap = 0;
    param.clip_x1 = clip_x1;
    param.clip_x2 = clip_x2;
    param.clip_y1 = clip_y1;
    param.clip_y2 = clip_y2;    
    param.render_flag = 0;

    return mmi_fe_show_string_int(&param);    

}

/*****************************************************************************
 * FUNCTION
 *  ShowStringBordered
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x               [IN]        
 *  y               [IN]        
 *  Font            [IN]        
 *  BackGround      [IN]        
 *  String          [?]         
 *  LineHeight      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_fe_show_string_bordered(S32 x, S32 y, U8 *String)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nLen = 0;
    U8 default_direction = 0;
    mmi_fe_showstring_int_param_struct param;
    S32 clip_x1, clip_x2, clip_y1, clip_y2;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&param, 0, sizeof(mmi_fe_showstring_int_param_struct));
    
    nLen = mmi_ucs2strlen((const char*)String);
    mmi_fe_get_display_direction(String, &default_direction, nLen);
    
    gdi_layer_get_clip(&clip_x1, &clip_y1, &clip_x2, &clip_y2);
    param.x = x;
    param.y = y;
    param.String = String;
    param.BaseLineHeight = -1;
    param.Bordered = MMI_TRUE;
    param.len = nLen;
    param.enable_truncated = MMI_FALSE;
    param.truncated_symbol = NULL;
    param.visible_x_start = -1;
    param.visible_x_end = -1;
    param.assign_direction = default_direction;
    param.char_gap = 0;
    param.clip_x1 = clip_x1;
    param.clip_x2 = clip_x2;
    param.clip_y1 = clip_y1;
    param.clip_y2 = clip_y2;    
    param.render_flag = 0;

    return mmi_fe_show_string_int(&param);    
}


/*****************************************************************************
 * FUNCTION
 *  ShowStringBordered_n
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x_unsigned      [IN]        
 *  y_unsigned      [IN]        
 *  Font            [IN]        
 *  BackGround      [IN]        
 *  String          [?]         
 *  Len             [IN]        
 *  LineHeight      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_fe_show_string_bordered_n(
        U32 x_unsigned,
        U32 y_unsigned,
        U8 *String,
        int Len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 default_direction = 0;
    mmi_fe_showstring_int_param_struct param;
    S32 clip_x1, clip_x2, clip_y1, clip_y2;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&param, 0, sizeof(mmi_fe_showstring_int_param_struct));
    
    mmi_fe_get_display_direction(String, &default_direction, Len);    
    gdi_layer_get_clip(&clip_x1, &clip_y1, &clip_x2, &clip_y2);
    
    param.x = x_unsigned;
    param.y = y_unsigned;
    param.String = String;
    param.BaseLineHeight = -1;
    param.Bordered = MMI_TRUE;
    param.len = Len;
    param.enable_truncated = MMI_FALSE;
    param.truncated_symbol = NULL;
    param.visible_x_start = -1;
    param.visible_x_end = -1;
    param.assign_direction = default_direction;    
    param.char_gap = 0;
    param.clip_x1 = clip_x1;
    param.clip_x2 = clip_x2;
    param.clip_y1 = clip_y1;
    param.clip_y2 = clip_y2;    
    return mmi_fe_show_string_int(&param);    

}


/*****************************************************************************
 * FUNCTION
 *  ShowStringBordered_by_direction
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x               [IN]        
 *  y               [IN]        
 *  Font            [IN]        
 *  BackGround      [IN]        
 *  String          [?]         
 *  LineHeight      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_fe_show_string_bordered_by_direction(S32 x, S32 y, U8 *String, U8 default_direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nLen = 0;
    mmi_fe_showstring_int_param_struct param;
    S32 clip_x1, clip_x2, clip_y1, clip_y2;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&param, 0, sizeof(mmi_fe_showstring_int_param_struct));
    
    nLen = mmi_ucs2strlen((const char*)String);
    gdi_layer_get_clip(&clip_x1, &clip_y1, &clip_x2, &clip_y2);

    param.x = x;
    param.y = y;
    param.String = String;
    param.BaseLineHeight = -1;
    param.Bordered = MMI_TRUE;
    param.len = nLen;
    param.enable_truncated = MMI_FALSE;
    param.truncated_symbol = NULL;
    param.visible_x_start = -1;
    param.visible_x_end = -1;
    param.assign_direction = default_direction;
    param.char_gap = 0;
    param.clip_x1 = clip_x1;
    param.clip_x2 = clip_x2;
    param.clip_y1 = clip_y1;
    param.clip_y2 = clip_y2;    
    param.render_flag = 0;

    return mmi_fe_show_string_int(&param);    
}



/*****************************************************************************
 * FUNCTION
 *  Get_CharWidth
 * DESCRIPTION
 *  To get char widths
 *  
 *  This is used to get char widths
 * PARAMETERS
 *  Ch          [IN]        
 *  pdWidth     [?]         
 * RETURNS
 *  S32(?)
 *****************************************************************************/
void Get_CharWidth(U32 Ch, S32 *pWidth)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 dwidth = 0, Height = 0, Ascent = 0, Descent = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    FE_LOCK;
    Get_CharWidthHeight_internal(Ch, &dwidth, pWidth, &Height, &Ascent, &Descent);
    FE_UNLOCK;
    GDI_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  Get_CharNumInWidth_internal
 * DESCRIPTION
 *  To get char number in specified width and gap
 *  This function only work for non-complicated langauge. 
 *  It means that the language process is not processed in the function.
 * PARAMETERS
 *  String:             [IN] the string content        
 *  width:              [IN] the specifed width to display the string.       
 *  checklinebreak:  [IN] to check line break or not.       
 *  gap:                 [IN] the gap between each character  
 *  number:            [OUT] number of characters
 * RETURNS
 *  The number of character could be displayed in the specified width.
 *****************************************************************************/
U32 Get_CharNumInWidth_internal(U8 *String, U32 width, U8 checklinebreak, U32 gap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 nwidth = 0, chwidth, chheight;
    U32 nchar = 0, line_break_char_counter = 0;
    U16 ch;
    U8 linebreakflag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_wc(&ch, String);
    if (ch == 0)
    {
        return 0;
    }

    do
    {
        mmi_ucs2_to_wc(&ch, String);

        if (checklinebreak)
        {
            linebreakflag = FONT_TEST_WORD_WRAPPING_BREAK_CHARACTER(ch);
        }

        if (FONT_TEST_BIDI_CONTROL_CHAR(ch))
        {
            chwidth = 0;
        }
        else
        {
            Get_CharWidthHeight(ch, (S32*) & chwidth, (S32*) & chheight);
            chwidth += gap;
        }

        nwidth += chwidth;
        String += 2;
        nchar++;
        if (checklinebreak)
        {
            if (UI_STRING_END_OF_STRING_CHARACTER(ch))
            {
                line_break_char_counter = nchar;
            }

            if (linebreakflag)
            {
                line_break_char_counter = nchar;
            }
            /*
             * if (!FONT_TEST_ASCII_CHARACTER(ch))
             * {
             * line_break_char_counter = 0;
             * }
             */
        }

    } while (nwidth <= width && ch != 0 /* && ch != 0x0A && ch != 0x0D */ );

    if (checklinebreak)
    {
        if (line_break_char_counter == 0)
        {
            nchar--;
        }
        else
        {
            nchar = line_break_char_counter;
        }
    }
    else
    {
        nchar--;
    }

    return nchar;

}



/*****************************************************************************
 * FUNCTION
 *  Get_CharNumInWidth_w
 * DESCRIPTION
 *  To get char number in specified width and gap
 *  This function only work for non-complicated langauge. 
 *  It means that the language process is not processed in the function.
 * PARAMETERS
 *  String:             [IN] the string content        
 *  width:              [IN] the specifed width to display the string.       
 *  checklinebreak:  [IN] to check line break or not.       
 *  gap:                 [IN] the gap between each character  
 *  number:            [OUT] number of characters
 * RETURNS
 *  The number of character could be displayed in the specified width.
 *****************************************************************************/
U32 Get_CharNumInWidth_w(U8 *String, U32 width, U8 checklinebreak, U32 gap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    ret = Get_CharNumInWidth_internal(String, width, checklinebreak, gap);
    GDI_UNLOCK;
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  Get_CharNumInWidth
 * DESCRIPTION
 *  To get char number in specified width
 *  This function only work for non-complicated langauge. 
 *  It means that the language process is not processed in the function.
 * PARAMETERS
 *  String:             [IN] the string content        
 *  width:              [IN] the specifed width to display the string.       
 *  checklinebreak:  [IN] to check line break or not.       
 *  number:            [OUT] number of characters
 * RETURNS
 *  The number of character could be displayed in the specified width.
 *****************************************************************************/
U32 Get_CharNumInWidth(U8 *String, U32 width, U8 checklinebreak)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    ret = Get_CharNumInWidth_internal(String, width, checklinebreak, 1);
    GDI_UNLOCK;
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  Get_CharWidthHeight
 * DESCRIPTION
 *  To get char width and height. 
 *  The font attribute is not considered as the propriety to influence the return value.
 *  Before using the API, please setup font.
 * PARAMETERS
 *  ch:              [IN]     the character
 *  pWidth :       [OUT]  the character width. 
 *                               If the character is non-India character, the width would be returned. 
 *                               Othrewise, the dwidth (advance width) would be returned.  
 *  pHeight:       [OUT]   the height of the character.
 * RETURNS
 *  void
 *****************************************************************************/
void Get_CharWidthHeight(U32 Ch, S32 *pWidth, S32 *pHeight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ascent = 0;
    S32 descent = 0;
    S32 width = 0;
    S32 dwidth = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    FE_LOCK;
    Get_CharWidthHeight_internal(Ch, &dwidth, &width, pHeight, &ascent, &descent);
#if defined(__MMI_INDIC_ALG__)
    if (IRE_INDIC_CHARACTER_UCS2_RANGE(Ch))
    {
        *pWidth = dwidth;
    }
    else
#endif
    {
        *pWidth = width;
    }
    FE_UNLOCK;
    GDI_UNLOCK;
}

/* Vogins Start */
#if defined(__VRE__)
void Get_CharInfo_ForVRE(U32 Ch, S32 *pWidth, S32 *pDwidth,S32 *pHeight, S32 *Ascent, S32 *Descent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    FE_LOCK;
    Get_CharWidthHeight_internal(Ch, pDwidth, pWidth, pHeight, Ascent, Descent);
    FE_UNLOCK;
    GDI_UNLOCK;
}
#endif
/* Vogins End */


/**************************************************************
* FUNCTION NAME 
*  Get_CharBoundingBox()
* Description
*  To get the bounding box of "drawn area" of a character
*  REMARKS 
*     1. It does not handle Hindi properly.
*     2. The function is slow because it process internal font data.
*     3. This function can be used to align a character in a better way because the "drawn area" is aligned
*         differently for different font database.
* PARAMETERS
*  Ch:               [IN] the character ucs2 code
*  pCharWidth:   [OUT] width of character
*  pCharHeight:  [OUT] height of character
*  pBoxXoffset:  [OUT] X offset of the bounding box of drawn area relative to the top-left corner
*  pBoxYoffset:  [OUT] Y offset of the bounding box of drawn area  relative to the top-left corner
*  pBoxWidth:    [OUT] width of the bounding box of drawn area 
*  pBoxHeight:   [OUT] height of the bounding box of drawn area 
* RETURNS
*  void
**************************************************************/
void Get_CharBoundingBox(U32 Ch, S32 * pCharWidth, S32 * pCharHeight, S32 * pBoxXoffset, S32 * pBoxYoffset,
                         S32 * pBoxWidth, S32 * pBoxHeight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *font_data;
    U32 font_data_size;
    S32 char_width;
    U16 data_height;
    U16 data_width;
    S32 fx1, fy1, fx2, fy2, x, y;
    S32 ascent = 0, descent = 0;
    U32 data_attr = 1;
    S32 dwidth;
    S32 bearing_x;
    MMI_BOOL valid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    FE_LOCK;
    
    font_data_size =
    mmi_fe_get_font_data(MMI_FALSE, (U16)Ch, &font_data, &data_attr, &char_width, &dwidth, &data_width,  &data_height, &bearing_x, &ascent, &descent, &valid);
    FE_UNLOCK;
    GDI_UNLOCK;

    *pCharWidth = data_width;
    *pCharHeight = data_height;

    fx1 = data_width - 1;   /* min X of drawn area */
    fx2 = 0;                /* max X of drawn area */
    fy1 = data_height - 1;  /* min Y of drawn area */
    fy2 = 0;                /* max Y of drawn area */

    x = 0;
    y = 0;


#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    if (data_attr)
    {
        *pBoxXoffset = 0;
        *pBoxYoffset = 0;
        *pBoxWidth = data_width;
        *pBoxHeight = data_height;
        return;
    }
#endif

    while (font_data_size--)
    {
        U8 pattern = *font_data++;

        if (!pattern)
        {
            U32 nTemp;

            x += 8;
            nTemp = x / data_width;
            if (nTemp)
            {
                y += nTemp;
                data_height -= (U16) nTemp;
                if (!data_height)
                {
                    break;
                }
            }

            x %= data_width;
        }
        else
        {
            S32 i;

            for (i = 0; i < 8; i++)
            {
                if (pattern & 1)
                {
                    if (x < fx1)
                    {
                        fx1 = x;
                    }
                    if (y < fy1)
                    {
                        fy1 = y;
                    }
                    if (x > fx2)
                    {
                        fx2 = x;
                    }
                    if (y > fy2)
                    {
                        fy2 = y;
                    }
                }

                x++;
                if (x == (S32) data_width)
                {
                    y++;
                    data_height--;
                    x = 0;
                    if (!data_height)
                    {
                        break;
                    }
                }
                pattern >>= 1;
            }
        }
    }

    MMI_DBG_ASSERT(fx2 >= fx1 && fy2 >= fy1);

    *pBoxXoffset = fx1;
    *pBoxYoffset = fy1;
    *pBoxWidth = fx2 - fx1 + 1;
    *pBoxHeight = fy2 - fy1 + 1;
}



/*****************************************************************************
 * FUNCTION
 *  Get_StringWidthHeight
 * DESCRIPTION
 *  To get string width and height. 
 *  The bordered attribute is not considered as an attribute to influence the string width & height.
 * PARAMETERS
 *  String:      [IN]        the string content
 *  pWidth:     [OUT]     the string width         
 *  pHeight:    [OUT]     the string height    
 * RETURNS
 *  void
 *****************************************************************************/
void Get_StringWidthHeight(U8 *String, S32 *pWidth, S32 *pHeight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nLen;
    mmi_fe_get_string_info_param_struct query;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
    nLen = mmi_ucs2strlen((const char*)String);

    query.String = String;
    query.checkCompleteWord = MMI_FALSE;
    query.enableTruncated = MMI_FALSE;
    query.n = nLen;
    query.w = 0;

    mmi_fe_get_string_widthheight(&query);
    *pWidth = query.pWidth;
    *pHeight = query.pHeight;
}

#if(FONTENGINE_IRAM_PLACEMENT)
#ifdef __MTK_TARGET__
#pragma arm section code
#endif 
#endif /* (FONTENGINE_IRAM_PLACEMENT) */ 



/*****************************************************************************
 * FUNCTION
 *  Get_StringWidthHeight_n
 * DESCRIPTION
 *  To get string widths and height upto a given number of characters
 * PARAMETERS
 *  String:       [IN]   the string content        
 *  n:             [IN]   the given number of characters.     
 *  pWidth:     [OUT]  the string width      
 *  pHeight:     [OUT]  the string height      
 * RETURNS
 *  void
 *****************************************************************************/
void Get_StringWidthHeight_n(U8 *String, S32 n, S32 *pWidth, S32 *pHeight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_get_string_info_param_struct query;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
    query.String = String;
    query.n = n;
    query.enableTruncated = MMI_FALSE;
    query.w = 0;
    mmi_fe_get_string_widthheight(&query);

    *pWidth = query.pWidth;
    *pHeight = query.pHeight;
}



/*****************************************************************************
 * FUNCTION
 *  Get_StringWidthHeight_multitap
 * DESCRIPTION
 *  To get the multitap string width and height.
 *  The language process would not applied in the string. 
 *  We consider each character as a separate character to query its attribute.
 * PARAMETERS
 *  String:      [IN]     the string content    
 *  w:           [IN]      the gap between each character.  
 *  pWidth:      [OUT]  the string width       
 *  pHeight:     [OUT]  the string height       
 * RETURNS
 *  void
 *****************************************************************************/
void Get_StringWidthHeight_multitap(U8 *String, S32 w, S32 *pWidth, S32 *pHeight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 StrWidth = 0;
    S32 Counter = 0;
    S32 nHeight = 0;
    U16 unicode = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *pHeight = 0;
    *pWidth = 0;

    if (String == NULL)
    {
        return;
    }
    GDI_LOCK;
    while (1)
    {
        if ((String[0] == '\0') && (String[1] == '\0'))
        {
            break;
        }
        memcpy(&unicode, String, 2);

        Get_CharWidthHeight(unicode, &StrWidth, &nHeight);
        /* Consider the Thai String length is different from others */

        (*pWidth) += (StrWidth + w);
        if (*pHeight < nHeight)
        {
            *pHeight = nHeight;
        }
        Counter++;

        String += 2;
    }
    GDI_UNLOCK;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  Get_StringWidthHeight_w
 * DESCRIPTION
 *  To get string widths and height with the given gap
 * PARAMETERS
 *  String:       [IN]   the string content        
 *  w:             [IN]   the gap between each character     
 *  pWidth:     [OUT]  the string width      
 *  pHeight:     [OUT]  the string height      
 * RETURNS
 *  void
 *****************************************************************************/
void Get_StringWidthHeight_w(U8 *String, S32 w, S32 *pWidth, S32 *pHeight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nLen= 0;
    mmi_fe_get_string_info_param_struct query;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nLen = mmi_ucs2strlen((const char*)String);
    
    memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
    query.String = String;
    query.n = nLen;
    query.enableTruncated = MMI_FALSE;
    query.w = w;
    mmi_fe_get_string_widthheight(&query);
    
    *pWidth = query.pWidth;
    *pHeight = query.pHeight;
}


/*****************************************************************************
 * FUNCTION
 *  Get_StringWidthHeight_wn
 * DESCRIPTION
 *  To get string widths and height upto a given number of characters and the given gap between each character.
 * PARAMETERS
 *  String:       [IN]   the string content     
 *  w:             [IN]   the gap between each character     
 *  n:             [IN]   the given number of characters.     
 *  pWidth:     [OUT]  the string width      
 *  pHeight:     [OUT]  the string height      
 * RETURNS
 *  void
 *****************************************************************************/
void Get_StringWidthHeight_wn(U8 *String, S32 w, S32 n, S32 *pWidth, S32 *pHeight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_get_string_info_param_struct query;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
    query.String = String;
    query.n = n;
    query.enableTruncated = MMI_FALSE;
    query.w = w;
    mmi_fe_get_string_widthheight(&query);

    *pWidth = query.pWidth;
    *pHeight = query.pHeight;
}

/*****************************************************************************
 * FUNCTION
 *  Get_StringWidthHeight_variant
 * DESCRIPTION
 *  To get string widths, height and how many character could be displayed in the spefied width 
 *  with a given number of characters and the given gap between each character.
 * PARAMETERS
 *  String:                    [IN]   the string content     
 *  w:                          [IN]   the gap between each character     
 *  n:                           [IN]   the given number of characters.     
 *  pWidth:                   [OUT]  the string width      
 *  pHeight:                  [OUT]  the string height 
 *  max_width:              [IN]    the specified width to display the string.
 *  checkLineBreak:        [IN]    to indicate if the line break character should be considered as an end.
 *  checkCompleteWord: [IN]    to indicate if the complete word should be considered.
 * RETURNS
 *  void
 *****************************************************************************/
U32 Get_StringWidthHeight_variant(U8 *string, S32 w, S32 n, S32 *pWidth, S32 *pHeight, S32 max_width, U8 checkLineBreak, U8 checkCompleteWord)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_get_string_info_param_struct query;
    S32 counter = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
    query.String = string;
    query.n = n;
    query.enableTruncated = MMI_TRUE;
    query.w = w;
    query.targetWidth = max_width;
    query.checkCompleteWord = checkCompleteWord;
    query.checklinebreak = checkLineBreak;
    counter = mmi_fe_get_string_widthheight(&query);

    
    *pWidth = query.pWidth;
    *pHeight = query.pHeight;

    return counter;
}



#if defined(__MMI_INDIC_ALG__) && !defined(__MMI_VECTOR_FONT_SUPPORT__)

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_string_widthheight_indic_internal
 * DESCRIPTION
 *  get Indc string information
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
static U32 mmi_fe_get_string_widthheight_indic_internal(mmi_fe_get_string_info_param_struct_p param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    U32 prev_base_char_dwidth = 0;
    U32 prev_base_char_width = 0;
    U32 prev_char_dwidth = 0;
    U32 prev_char_width = 0;

    U32 pWidth = 0;
    U32 pWidth_adv = 0;
    U32 Counter = 0;
    U32 n = param->n;
    S32 ascent = 0, descent = 0;
    S32 chWidth = 0, chHeight = 0, chAscent = 0, chDescent = 0, chDwidth = 0;
    U32 curr_char_pos = 0 , pre_char_pos = 0, pre_base_char_pos = 0;
    U16 curCh = 0;
    U8 *String = param->String;
    S32 cursorX = 0;
    MMI_BOOL cluster_last_char  = IRE_IS_OFFSET_REQUIRED();
    mmi_fe_glyph_metrics_struct metrics;
    S32 Italic_tilt = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IRE_RESET_RENDERING_CORRECTION();
    /*
    if (!ire_is_indic_rules_parsing())
    {
        cluster_last_char = MMI_FALSE;
    }
    */

    while (Counter < n)
    {
        if (String[0] == 0 && String[1] == 0)
        {
            break;
        }
        curCh = String[1] << 8 | String[0];
        Get_CharWidthHeight_internal((U32) curCh, &chDwidth, &chWidth, &chHeight, &chAscent, &chDescent);
        if(Counter == 0)
        {
            mmi_fe_get_glyph_metrics(curCh, &metrics);
            Italic_tilt = metrics.width - chWidth;
        }
        if (IRE_INDIC_CHARACTER_UCS2_RANGE(curCh))
        {
            curr_char_pos = ire_identify_char_position(curCh);
            switch (curr_char_pos)
            {
                case IRE_BELOW_AND_POST_BASE_POSITION:
                case IRE_POSTBASE_POSITION:
            {
                    /* The width of the character will be returned
                    * if any dependent vowel comes as independently */     
                    if((n == 1) && IRE_IS_CHAR_TYPE_DEP_VOWEL(curCh))
                    {
                        pWidth_adv = chWidth;
                        pWidth = chWidth;
                        break;

                    }
                    if((cluster_last_char  == MMI_TRUE) && (Counter == (n - 1)))
                    {
                        (pWidth_adv) += chWidth;
                         pWidth += chDwidth;
                         break;

                    }
                    
                    prev_base_char_dwidth = chDwidth;
                    prev_base_char_width = chWidth;
                    pre_base_char_pos = curr_char_pos;
                    prev_char_dwidth = chDwidth;
                    prev_char_width = chWidth;

                    (pWidth) += chDwidth;
                    pWidth_adv += chDwidth;
                    break;

                }
                case IRE_POST_BASE_POSITION_REQ_CORRECTION:
                case IRE_POST_BASE_POSITION_REQ_CORRECTION2:
                {
                    if((cluster_last_char  == MMI_TRUE) && (Counter == (n - 1)))
                    {
                        (pWidth_adv) += chWidth;
                        (pWidth) += chDwidth;
                        break;

                    }
                    
                    prev_base_char_dwidth = chDwidth;
                    prev_base_char_width = chWidth;
                    pre_base_char_pos = curr_char_pos;
                    prev_char_dwidth = chDwidth;
                    prev_char_width = chWidth;
                    IRE_SET_RENDERING_CORRECTION(curCh);
                    (pWidth) += chDwidth;
                    pWidth_adv += chDwidth;
                    break;
             }
                /* The width of the previous base consonant will be taken, 
                if current character position is above base */ 
                case IRE_ABOVE_BASE_POSITION:
                {

                    S32 temp_move = 0;
                    /* The width of the character will be returned
                    * if any sign comes as independently */

                    if ((n == 1) || (Counter == 0))
                    {
                        pWidth_adv = chWidth;
                        pWidth = chWidth;
                        break;

                    }
                    temp_move = (prev_base_char_dwidth < chWidth ?  (chWidth - prev_base_char_dwidth) : 0);
                    cursorX = (cursorX< temp_move)? temp_move:cursorX;


                    //if (Counter == (n - 1))
                    {
                        if ( (ire_is_indic_rules_parsing() && (cluster_last_char  == MMI_TRUE)) ||
                          (!ire_is_indic_rules_parsing() && IRE_IS_OFFSET_REQUIRED()) )
                        {
                          pWidth_adv += temp_move;
                          pWidth += temp_move;

                          pWidth_adv  += (prev_base_char_width - prev_base_char_dwidth);
                          pWidth  += (prev_base_char_width - prev_base_char_dwidth);
                        }
                    }

                    prev_char_dwidth = chDwidth;
                    prev_char_width = chWidth;

                    break;
                }
                /* The width of the previous base consonant will be taken, 
                if current character position is  below base */     
                case IRE_BELOW_BASE_POSITION_IGNORE_CORRECTION_ATTRIBUTE:
                {
                    S32 temp_move = 0;
                    /* The width of the character will be returned
                    * if any sign comes as independently */
                    if ((n == 1) || (Counter == 0))
                    {
                        pWidth_adv = chWidth;
                        pWidth = chWidth;
                        break;

                    }
                    temp_move = (prev_base_char_dwidth < chWidth ?  (chWidth - prev_base_char_dwidth) : 0);
                    cursorX = (cursorX< temp_move)? temp_move:cursorX;

                    if (Counter == (n - 1))
                    {
                        if ( (ire_is_indic_rules_parsing() && (cluster_last_char  == MMI_TRUE)) ||
                          (!ire_is_indic_rules_parsing() && IRE_IS_OFFSET_REQUIRED()) )
                        {
                          pWidth_adv += temp_move;
                          pWidth_adv  += (prev_base_char_width - prev_base_char_dwidth);  
                            pWidth += temp_move;
                        }
                    }
                    prev_char_dwidth = chDwidth;
                    prev_char_width = chWidth;

                    IRE_RESET_RENDERING_CORRECTION();
                    IRE_RESET_SMALL_CONSONANT_FLAG();
                        break;
                    }
                case IRE_BELOW_BASE_POSITION:
                    {
                     U32 temp_move = 0;
                     if((pre_char_pos == curr_char_pos) || (pre_char_pos == IRE_BELOW_AND_POST_BASE_POSITION)
                            || (pre_char_pos == IRE_BELOW_BASE_POSITION_IGNORE_CORRECTION_ATTRIBUTE))

                     {
                        (pWidth_adv) += chDwidth;
                        pWidth += chDwidth;
                        break;
                     }
                    if ((IRE_IS_RENDERING_CORRECTION() && (pre_base_char_pos == IRE_POST_BASE_POSITION_REQ_CORRECTION)) ||
                        (pre_base_char_pos == IRE_POST_BASE_POSITION_REQ_CORRECTION2))
                    {
                        S32 temp_rendering_width = prev_base_char_dwidth - IRE_IS_RENDERING_CORRECTION();
                        S32 temp_dwidth = chDwidth - temp_rendering_width;
                        S32 temp_width = chWidth - temp_rendering_width;
                        
                        pWidth_adv += ((temp_dwidth > 0)) ? temp_dwidth : 0;
                        pWidth += ((temp_width > 0)) ? temp_width : 0;

                        IRE_RESET_RENDERING_CORRECTION();
                        IRE_RESET_SMALL_CONSONANT_FLAG();
                    }
                    else
                    {
                        if (ire_is_indic_rules_parsing())
                        {
                            if((cluster_last_char  == MMI_TRUE) && Counter == (n - 1))
                            {
                                temp_move = (prev_base_char_width < chWidth ?  (chWidth - prev_base_char_width) : 0);
                                pWidth_adv  += (prev_base_char_width - prev_base_char_dwidth);
                                pWidth_adv += temp_move;
                                break;
                            }
                        }
                        else 
                        {
                            temp_move = (prev_char_width < chWidth ?  (chWidth - prev_char_width) : 0);
                            cursorX = (cursorX< temp_move)? temp_move:cursorX;
                            //if(IRE_IS_OFFSET_REQUIRED() && (Counter == (n - 1)))
                            {
                                pWidth_adv += temp_move;
                                pWidth_adv  += (prev_base_char_width - prev_base_char_dwidth);  
                            }
                        }
                    }
                    
                    prev_char_dwidth = chDwidth;
                    prev_char_width = chWidth;

                        break;
                    }
                default:
                    (pWidth_adv) += chDwidth;
                    pWidth += chDwidth;
                    prev_base_char_dwidth = chDwidth;
                    prev_base_char_width = chWidth;
                    prev_char_dwidth = chDwidth;
                    prev_char_width = chWidth;
                    break;

            }
        }
        else
        {
            /* For non- Indic characters */
            (pWidth) += chWidth;
            prev_base_char_dwidth = chDwidth;
            prev_base_char_width = chWidth;
        }
        
        if (chAscent > ascent)
            ascent = chAscent;
        
        if (chDescent > descent)
            descent = chDescent;

        pre_char_pos = curr_char_pos;
        
        String += 2;
        Counter++;
    }

    param->pWidth = pWidth + Italic_tilt;
    param->pHeight = ascent + descent;
    param->maxAscent = ascent;
    param->maxDescent = descent;
    param->baseline = ascent;
    param->adv_h = param->pHeight;
    param->adv_w = pWidth_adv;
    return Counter;

}


#endif /* defined(__MMI_INDIC_ALG__) */

#if defined(__MMI_LANG_THAI__)

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_string_widthheight_thai
 * DESCRIPTION
 *  get Thai string information by language
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_fe_get_string_widthheight_thai(mmi_fe_get_string_info_param_struct_p param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    mmi_lm_cluster_info cluster, prev_cluster, prev2_cluster;
    U8* str_end;
    U8* str_start;
    S32 width = 0, adv_w = 0;
    S32 counter = 0;
    MMI_BOOL enableTruncated = param->enableTruncated;
    S32 targetWidth = param->targetWidth;
    S32 ascent = 0, descent = 0;
    S32 chDescent = 0;
    MMI_BOOL truncated = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    str_end = param->String + param->n*2;
    mmi_lm_cluster_init(&prev_cluster);
    mmi_lm_cluster_init(&prev2_cluster);
    mmi_lm_cluster_init(&cluster);   

    str_start = param->String;


    while (counter < param->n)
    {
        str_start+= cluster.data_len*2;
        width += (cluster.adv_x + cluster.rx) + param->w;
        
        memcpy(&prev2_cluster, &prev_cluster, sizeof(mmi_lm_cluster_info));
        memcpy(&prev_cluster, &cluster, sizeof(mmi_lm_cluster_info));

        mmi_lm_cluster_init(&cluster);   
        cluster.data_ptr = str_start;
        mmi_lm_get_current_cluster(cluster.data_ptr, str_end, &prev2_cluster, &prev_cluster, &cluster);
        if (enableTruncated && targetWidth < width + cluster.adv_x)
        {
            truncated = MMI_TRUE;
            break;
        }
        if ((S32)cluster.by > ascent)
            ascent = (S32)cluster.by;
        
        chDescent = (S32)(cluster.h - cluster.by);
        if (chDescent > descent)
            descent = chDescent;
                
        counter += cluster.data_len;
        adv_w += (cluster.adv_x + cluster.rx);
    }
    
    width+= ((cluster.adv_x > cluster.w? cluster.adv_x : cluster.w) + param->w);

    if (enableTruncated && truncated)
    {
        param->enableTruncated = MMI_FALSE;
    }
    param->adv_w = adv_w;
    param->pWidth = width;        
    param->pHeight = ascent + descent;
    param->maxAscent = ascent;
    param->maxDescent = descent;
    param->baseline = ascent;
    return counter;
    
}
#endif /* defined(__MMI_LANG_THAI__) */

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_string_widthheight
 * DESCRIPTION
 *  To get string width height
 * PARAMETERS
 *  query:  [IN/OUT] the query parameter to indicate the input and output
 * RETURNS
 *  U32   how many characters is counted.
 *****************************************************************************/
U32 mmi_fe_get_string_widthheight(mmi_fe_get_string_info_param_struct_p query)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 Counter = 0;
    U32 numofChar = 0;
    S32 ascent = 0, descent = 0;
    U8 *String = query->String;
    S32 nLen = query->n;
    mmi_fe_get_string_info_param_struct string_part_param;

#if defined(__MMI_ARSHAPING_ENGINE__) || defined(__MMI_BIDI_ALG__)
    S32 check_len = 0; /* used to check every character in the string */
    U8 *temp_string = String;
#endif
#if defined(__MMI_BIDI_ALG__)
    MMI_BOOL IS_BIDI = MMI_FALSE;
    U8 default_direction;
    BIDI_PARAGRAPH_TYPES paratype = P_RTL;
    U16 visual_str_len = 0, visual_cur_pos = 0;
#endif
#if defined(__MMI_ARSHAPING_ENGINE__)
    MMI_BOOL IS_ARABIC = MMI_FALSE;
#endif
    S32 lang_string_group = 0;
    U8 *lang_string_start = NULL;
    MMI_BOOL enableTruncated = query->enableTruncated;
    S32 targetWidth = query->targetWidth;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* initialization */
    query->pHeight = 0;
    query->pWidth = 0;
    query->baseline = 0;
    /* error check */
    if (String == NULL || nLen == 0 || (enableTruncated && targetWidth == 0))
    {
        return numofChar;
    }
    GDI_LOCK;
    FE_LOCK;

#if defined(__MMI_BIDI_ALG__) || defined(__MMI_ARSHAPING_ENGINE__)

    if (nLen > MAX_SHOW_STRING_TEXT_LENGTH - ENCODING_LENGTH) 
    {
        nLen = MAX_SHOW_STRING_TEXT_LENGTH - ENCODING_LENGTH;
    }
#endif

#if defined(__MMI_BIDI_ALG__)
        mmi_fe_get_display_direction(String, &default_direction, nLen);

        temp_string = String;
        check_len = nLen;
        while (check_len != 0)
        {
            U8 dic = 0;
            U16 unicode = 0;
            if ((temp_string[0] == '\0') && (temp_string[1] == '\0'))
                break;
            check_len--;
    
            unicode = temp_string[0];
            unicode |= (temp_string[1] << 8);
    
#if defined(__MMI_ARSHAPING_ENGINE__)
            if (IS_ARABIC_CHARACTER(unicode))
                IS_ARABIC = MMI_TRUE;
#endif
    
            bidi_get_char_type((U8*)(&unicode), &dic);
    
            if (dic == BIDI_R || dic == AL || dic == AN || dic == WS)
            {
                IS_BIDI = MMI_TRUE;
            }
            
            if (IS_BIDI
#if defined(__MMI_ARSHAPING_ENGINE__)
                && IS_ARABIC
#endif
                )
                break;
            temp_string += 2;
        }
    
#endif


    /* check if shaping is necessary */
#if defined(__MMI_ARSHAPING_ENGINE__)
    if (IS_ARABIC)
    {
        mmi_ucs2ncpy((S8*) show_pwcWord, (S8*) String,nLen);
        show_pwcWord[nLen] = 0;
        nLen = mmi_ucs2strlen((const char*)show_pwcWord);
        if (enableTruncated)
        {
            memset(fe_ShaToOrg, 0x00, MAX_SHOW_STRING_TEXT_LENGTH);
            ArabicShapeEngine2_ext((U16*)&nLen, (U16*)show_pwcWord, NULL, fe_ShaToOrg);
        }
        else
        {
            ArabicShapeEngine_ext((U16*)&nLen, (U16*)show_pwcWord);
        }
        String = (U8*) show_pwcWord;
    }
#endif

#if defined(__MMI_BIDI_ALG__)    
        if (IS_BIDI || default_direction == BIDI_R)
        {
            if (default_direction == BIDI_R)
            {
                paratype = P_RTL;
            }
            else
            {
                paratype = P_LTR;
            }
            bidi_main_ext(
                String, 
                (U16)nLen, 
                0, 
                show_visual_str, 
                &visual_str_len, 
                &visual_cur_pos, 
                NULL,
                NULL,
                MMI_FALSE,
                MMI_bidi_input_type, 
                MMI_FALSE, 
                paratype);
            String = (U8*) show_visual_str;
        }
        else
        {
            mmi_ucs2ncpy((S8 *) show_visual_str, (S8 *) String, nLen);
            String = (U8*) show_visual_str;
        }
#endif



    lang_string_start = String;
    lang_string_group = 0;

    memcpy(&string_part_param, query, sizeof(mmi_fe_get_string_info_param_struct));

    {
        mmi_lm_cluster_info cluster, prev_cluster, prev2_cluster;
        U8* str_end;
        U8* str_start;
        S32 width = 0, adv_w = 0;
        S32 prev_space_width = 0;
        S32 prev_space_height = 0;
        S32 prev_space_index = -1;
        S32 prev_adv_w = 0;
        S32 prev_ascent = 0, prev_descent = 0;
        S32 chDescent = 0;
        
        str_start = String;
        str_end = String + nLen*2;
        mmi_lm_cluster_init(&prev_cluster);
        mmi_lm_cluster_init(&prev2_cluster);
        mmi_lm_cluster_init(&cluster);   
        do
        {
            str_start+= cluster.data_len*2;

            /* variable initialize */
            memcpy(&prev2_cluster, &prev_cluster, sizeof(mmi_lm_cluster_info));
            memcpy(&prev_cluster, &cluster, sizeof(mmi_lm_cluster_info));            
            mmi_lm_cluster_init(&cluster);   
            
            cluster.data_ptr = str_start;
            mmi_lm_get_current_cluster(cluster.data_ptr, str_end, &prev2_cluster, &prev_cluster, &cluster);

            if (query->enableTruncated)
            {
                UI_character_type curCh;
                curCh = ((cluster.data_ptr[0]) |(cluster.data_ptr[1] << 8));
                
                if (query->checklinebreak)
                {
                    if (FONT_TEST_NEW_LINE_CHAR(curCh))
                    {
                        goto GET_STRING_WIDTHHEIGH;
                    }
                }
                if (query->checkCompleteWord)
                {
                    /* check space */
                    if (FONT_TEST_WORD_WRAPPING_BREAK_CHARACTER(curCh))
                    {
                        prev_space_index = Counter;
                        prev_space_height = ascent + descent;
                        prev_space_width = width;
                        prev_ascent = ascent;
                        prev_descent = descent;
                        prev_adv_w = adv_w;
                    }
                }
                
                if (targetWidth < adv_w + cluster.adv_x)
                {
                    /* if there is one space in previous, restore the data back to the space. */
                    if (query->checkCompleteWord && prev_space_index != -1)
                    {
                        numofChar = prev_space_index;
                        adv_w = prev_adv_w;
                        width = prev_space_width;
                        ascent = prev_ascent;
                        descent = prev_descent;
                    }
                    goto GET_STRING_WIDTHHEIGH;
                }
            }
            if ((S32)cluster.by > ascent)
                ascent = (S32)cluster.by;
            
            chDescent = (S32)(cluster.h - cluster.by);
            if (chDescent > descent)
                descent = chDescent;

            if (((prev_cluster.lang_id == MMI_LM_LANG_ARABIC && cluster.lang_id != MMI_LM_LANG_ARABIC) ||
                (prev_cluster.lang_id != MMI_LM_LANG_ARABIC && cluster.lang_id == MMI_LM_LANG_ARABIC)) )
                adv_w++;

        /* [Vector font] a special process to make sure if the space is in the end of the string, the cursor move would be included. */
        #if defined(__MMI_VECTOR_FONT_SUPPORT__)
            if (!cluster.w && cluster.adv_x)
                cluster.w = cluster.adv_x;
        #endif            
            width = adv_w + cluster.w + query->w + cluster.rx;
            adv_w += cluster.adv_x + query->w + cluster.rx;
            
            numofChar += cluster.data_len;
        } while (numofChar < nLen);
GET_STRING_WIDTHHEIGH:
        if (!width && adv_w)
            width = adv_w;
        query->adv_w = adv_w;
        query->adv_h = ascent + descent;
        query->pWidth = width;
        query->baseline = ascent;
        query->maxAscent = ascent;
        query->maxDescent = descent;
        query->pHeight = ascent + descent;
    }
#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    if (query->pWidth && !query->pHeight)
    {
        query->pHeight = font_engine_font_pixel;
    }
#endif    
    /* because the underline is drawn in the bottom of the string. */
    if (gnCurrentFontAttrib & FONTATTRIB_UNDERLINE)
    {
        query->pHeight++;
    }

#if defined(__MMI_ARSHAPING_ENGINE__)
    if (IS_ARABIC && enableTruncated)
    {
        numofChar = fe_ShaToOrg[numofChar - 1];
    }
#endif
    FE_UNLOCK;
    GDI_UNLOCK;
    return numofChar;
}


/*****************************************************************************
 * FUNCTION
 *  Get_CharHeight
 * DESCRIPTION
 *  To get char height
 * PARAMETERS
 *  void
 * RETURNS
 *  S32    the char height
 *****************************************************************************/
S32 Get_CharHeight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 height = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    height = font_engine_font_pixel;
#else
    height = (S32) gpCurrentFont->nHeight;
#endif
    GDI_UNLOCK;
    return height;
}

/*****************************************************************************
 * FUNCTION
 *  Get_CharDisplayHeightofAllType
 * DESCRIPTION
 *  To get char height for current font
 * PARAMETERS
 *  void
 * RETURNS
 *  S32 the height
 *****************************************************************************/
S32 Get_CharDisplayHeightofAllType(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    S32 height,ascent, descent;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    if (font_engine->get_font_info(font_engine_font_pixel,&height,&ascent,&descent,MMI_TRUE))
    {
        ret = height +2;
    }
    else
#endif
    {
        ret = (S32) (gpCurrentFont->nHeight + 2);
        UI_UNUSED_PARAMETER(height);
        UI_UNUSED_PARAMETER(ascent);
        UI_UNUSED_PARAMETER(descent);        
    }
    GDI_UNLOCK;
#ifdef __MTK_TARGET__
    kal_check_stack(); /* if overflow , assert it */
#endif
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  Get_CharAscent
 * DESCRIPTION
 *  To get char ascent
 * PARAMETERS
 *  void
 * RETURNS
 *  S32  the ascent for the char
 *****************************************************************************/
S32 Get_CharAscent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    S32 height,ascent, descent;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    if (font_engine->get_font_info(font_engine_font_pixel,&height,&ascent,&descent,MMI_FALSE))
    {
            ret = ascent;
    }
    else
#endif
    {
        ret = (S32) gpCurrentFont->nAscent;
        UI_UNUSED_PARAMETER(height);
        UI_UNUSED_PARAMETER(ascent);
        UI_UNUSED_PARAMETER(descent);        
    }
    GDI_UNLOCK;
#ifdef __MTK_TARGET__
    kal_check_stack(); /* if overflow , assert it */
#endif
    return ret;

}

/*****************************************************************************
 * FUNCTION
 *  Get_CharDescent
 * DESCRIPTION
 *  To get char descent
 * PARAMETERS
 *  void
 * RETURNS
 *  S32  the descent for the char
 *****************************************************************************/
S32 Get_CharDescent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    S32 height,ascent, descent;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    if(font_engine->get_font_info(font_engine_font_pixel,&height,&ascent,&descent,MMI_TRUE))
    {
        ret = descent;
    }
    else
#endif
    {
        ret = (S32) gpCurrentFont->nDescent;
        UI_UNUSED_PARAMETER(height);
        UI_UNUSED_PARAMETER(ascent);
        UI_UNUSED_PARAMETER(descent);        
    }
    GDI_UNLOCK;
#ifdef __MTK_TARGET__
    kal_check_stack(); /* if overflow , assert it */
#endif
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  Get_CharDisplayHeightOfAllLangAndType
 * DESCRIPTION
 *  To get maximum char descent regardless of language and font attribute for current font 
 * PARAMETERS
 *  void
 * RETURNS
 *  S32  the descent
 *****************************************************************************/
S32 Get_CharDisplayDescentOfAllType(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    S32 height,ascent, descent;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    if (font_engine->get_font_info(font_engine_font_pixel,&height,&ascent,&descent,MMI_TRUE))
    {
        ret = descent + 1;
    }
    else
#endif
    {
        ret = (S32) (gpCurrentFont->nDescent + 1);
        UI_UNUSED_PARAMETER(height);
        UI_UNUSED_PARAMETER(ascent);
        UI_UNUSED_PARAMETER(descent);        
    }
    GDI_UNLOCK;
#ifdef __MTK_TARGET__
    kal_check_stack(); /* if overflow , assert it */
#endif
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  Get_CharDisplayHeightOfAllLangAndType
 * DESCRIPTION
 *  To get maximum char ascent regardless of language and font attribute for current font 
 * PARAMETERS
 *  void
 * RETURNS
 *  S32  the ascent
 *****************************************************************************/
S32 Get_CharDisplayAscentOfAllType(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    S32 height,ascent, descent;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    if (font_engine->get_font_info(font_engine_font_pixel,&height,&ascent,&descent,MMI_TRUE))
    {
        ret = ascent + 1;
    }
    else
#endif
    {
        ret = (S32) (gpCurrentFont->nAscent + 1);
        UI_UNUSED_PARAMETER(height);
        UI_UNUSED_PARAMETER(ascent);
        UI_UNUSED_PARAMETER(descent);        
    }
    GDI_UNLOCK;
#ifdef __MTK_TARGET__
    kal_check_stack(); /* if overflow , assert it */
#endif
    return ret;
}



/*****************************************************************************
 * FUNCTION
 *  Get_CharDisplayHeightOfAllLangAndType
 * DESCRIPTION
 *  To get maximum char height regardless of language and font attribute 
 * PARAMETERS
 *  size:        [IN]   the font size     
 * RETURNS
 *  S32  the height
 *****************************************************************************/
S32 Get_CharDisplayHeightOfAllLangAndType(U8 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ascent = 0, descent = 0, height = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    mmi_fe_get_char_info_of_all_lang(size, &height, &ascent, &descent);
    GDI_UNLOCK;
    return height+2;
}




/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_char_info_of_all_lang
 * DESCRIPTION
 *  To get maximum char height, ascent and descent for a specifed size regardless of language
 * PARAMETERS
 *  size:         [IN]  the specified size
 *  height:      [OUT] the height
 *  ascent:     [OUT]  the ascent
 *  descent:   [OUT]   the descent
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_get_char_info_of_all_lang(U8 size, S32* pheight, S32* pascent, S32* pdescent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 lang_index;
    sFontFamily *pFontFamily;
    S32 ascent = 0, descent = 0, max_ascent = 0, max_descent = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    {
        S32 height = 0;
        for (lang_index = 0; lang_index < g_mmi_fe_font_file_number[g_mmi_fe_font_family]; lang_index ++)
        {
            mmi_fe_vector_change_active(g_mmi_fe_curr_font_list[lang_index], lang_index);
            if (font_engine->get_font_info(mmi_fe_size_to_pixel(size), &height, &ascent, &descent, MMI_FALSE))
            {
                if (max_ascent < ascent)
                    max_ascent = ascent;
                if (max_descent < descent)
                    max_descent = descent;
            }
        }
        *pheight =  (max_ascent + max_descent);
        *pascent = max_ascent;
        *pdescent = max_descent;
    #ifdef __MTK_TARGET__
        kal_check_stack(); /* if overflow , assert it */
    #endif
        return;
    }
#endif

    for (lang_index = 0; lang_index < gMaxDeployedLangs; lang_index++)
    {
        pFontFamily = gLanguageArray[lang_index].fontfamilyList[gLanguageArray[lang_index].nCurrentFamily];
        ascent = (S32) pFontFamily->fontData[size]->nAscent;
        descent = (S32) pFontFamily->fontData[size]->nDescent;
    #if defined(__MMI_LANG_THAI__)
        if (!memcmp(&gLanguageArray[lang_index].aLangCountryCode, "th-TH", 5))
        {
            ascent++;
        }
    #endif
        if ( ascent > max_ascent)
        {
            max_ascent = ascent;
        }
        if (descent > max_descent)
        {
            max_descent = descent;
        }
    }

    if (max_ascent < (S32) gMTKProprietaryFont.nAscent)
    {
        max_ascent = (S32) gMTKProprietaryFont.nAscent;
    }
    if (max_descent < (S32) gMTKProprietaryFont.nDescent)
    {
        max_descent = (S32) gMTKProprietaryFont.nDescent;
    }

#if defined(__MMI_ZI__)
    if (max_ascent < (S32) gZiExtraCharacter.nAscent)
    {
        max_ascent = (S32) gZiExtraCharacter.nAscent;
    }
    if (max_descent < (S32) gZiExtraCharacter.nDescent)
    {
        max_descent = (S32) gZiExtraCharacter.nDescent;
    }
#endif /* defined(__MMI_ZI__) */ 

    *pheight =  (max_ascent + max_descent);
    *pascent = max_ascent;
    *pdescent = max_descent;
}


/*****************************************************************************
 * FUNCTION
 *  Get_CharHeightOfAllLang
 * DESCRIPTION
 *  To get maximum char height regardless of language
 * PARAMETERS
 *  size:        [IN]        the font size
 * RETURNS
 *  S32  the char height
 *****************************************************************************/
S32 Get_CharHeightOfAllLang(U8 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ascent = 0, descent = 0, height = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    mmi_fe_get_char_info_of_all_lang(size, &height, &ascent, &descent);
    GDI_UNLOCK;
    return height;
}



/*****************************************************************************
 * FUNCTION
 *  Get_StringHeight
 * DESCRIPTION
 *  To get string height
 * PARAMETERS
 *  void
 * RETURNS
 *  S32  the string height
 *****************************************************************************/
S32 Get_StringHeight()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sFontFamily *pFontFamily;
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    if (font_engine_font_pixel)
    {
        ret = font_engine_font_pixel;
    }
    else
#endif
    {
        pFontFamily = gLanguageArray[gCurrLangIndex].fontfamilyList[gLanguageArray[gCurrLangIndex].nCurrentFamily];
        ret = (S32) (pFontFamily->fontData[gnCurrentFont]->nHeight);
    }
    GDI_UNLOCK;
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  Get_StringLength_InCluster
 * DESCRIPTION
 *  Get the string length in cluster 
 * PARAMETERS
 *  input_str       [IN]        
 *  len             [IN]        
 *  base_len        [IN]        
 * RETURNS
 *  U32 - the string length according the clusters
 *****************************************************************************/
U32 Get_StringLength_InCluster(U8* input_str, U32 len, U32 base_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 val = base_len; /* Assume the string length in cluster is the same with base_len */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_INDIC_ALG__
    if (ire_is_reset_indic_params())
    {
        ire_reset_indic_params();
    }
    if (ire_is_indic_rules_parsing())
    {
        U16 cluster_fill[G_MAX];
        S32 cluster_length = 0;
        U32 total_len = 0;

        ire_init_cluster_start_p(input_str);
        ire_init_cluster_end_p(input_str + (len *2));
        ire_disable_indic_rules_parsing();
        ire_disable_indic_reset_hindi_params();

        /*This loop takes the string cluster by cluster and renders the string*/
        do
        {
            if (total_len >= len)
            {
                /* Parsing the string finished */
                break;
            }
     		
            cluster_length = ire_get_cluster(cluster_fill);
            total_len += cluster_length;
            if (total_len > base_len)
            {
                /* 
                 * the total_len according the clusters is larger than base_len. 
                 * Don't need to paser continually. 
                 */
                break;
            }
        } while (cluster_length);

        ire_enable_indic_rules_parsing();
        ire_enable_indic_reset_indic_params();

        if (total_len > base_len)
        {
            /*
             * The endding character is part of the cluster.
             * We will discard that part.
             */
            val = total_len - cluster_length;
        }
        else
        {
            val = total_len;
        }
    }
#endif /* __MMI_INDIC_ALG__ */

    return val;
}



/*****************************************************************************
 * FUNCTION
 *  TestDiffFonts
 * DESCRIPTION
 *  To test the different fonts with diferent sizes.
 *  
 *  This is used to test the different fonts with diferent sizes.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * BOOL
 *  
 *****************************************************************************/
void TestDiffFonts()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 count = 0, y = 20;
    stFontAttribute fontInfo;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fontInfo.bold = 0;
    fontInfo.italic = 0;
    fontInfo.underline = 0;

    fontInfo.size = 9;  /* (size 8..15 FOR type 2..5 ) & (size 9...15 FOR type 1 ) */
    fontInfo.type = 1;  /* 1...5 */

    SetFont(fontInfo,(U8)gCurrLangIndex);

    for (count = 0; count < 2; count++)
    {
        mmi_fe_show_string_ext(0, y, (PU8) "abcdefghij");
        y += 20;

        mmi_fe_show_string_ext(0, y, (PU8) "klmnopqrst");
        y += 20;

        mmi_fe_show_string_ext(0, y, (PU8) "uvwxyz");
        fontInfo.size += 1;
        y += 20;

    }
}


/*****************************************************************************
 * FUNCTION
 *  Get_FontHeight
 * DESCRIPTION
 *  
 * PARAMETERS
 *  f               [IN]        
 *  arrCount        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 Get_FontHeight(stFontAttribute f, U8 arrCount)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sFontFamily *pFontFamily;
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    pFontFamily = gLanguageArray[arrCount].fontfamilyList[gLanguageArray[arrCount].nCurrentFamily];
    ret = (S32) (pFontFamily->fontData[f.size]->nHeight);
    GDI_UNLOCK;
    return ret;
}

#if !defined(__MMI_VECTOR_FONT_SUPPORT__) && defined(__MMI_LANG_THAI__)
/*****************************************************************************
 * FUNCTION
 *  mmi_fe_query_thai_cluster
 * DESCRIPTION
 *  get Thai cluster information
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_fe_query_thai_cluster(mmi_lm_cluster_info_p cluster)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 counter = 0;    
    UI_character_type curCh = 0, preCh = 0, pre2Ch = 0;
    S32 prev_width = 0;
    S32 prev_height = 0;
    S32 width = 0, height = 0, adv_w = 0;
    mmi_fe_glyph_metrics_struct metrics;
    S32 ascent = 0, descent = 0;
    S32 prev_up_line_width = 0, prev_up_line_adv = 0, prev_bottom_line_width = 0, prev_bottom_line_adv = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (counter < cluster->cluster_len)
    {
        prev_width = width;
        prev_height = height;
        curCh = cluster->display_buffer[counter];
        mmi_fe_get_glyph_metrics(curCh, &metrics);

        
        if (THAI_CHAR_RANGE(curCh)/*curCh >= THAI_C_KO_KAI && curCh <= THAI_S_KHOMUT*/)
        {
            //curCh = unicode;
            // Base line character, can combinate with above vowels,bottom vowels, tone mark, and sign
            if (IsThaiBaseLineChar(curCh))
            {
                if (IsThaiLongTailChar(preCh))
                {
                    adv_w++;
                }
                //if the current character is 0x0E33 and previous or previous 2 character is base line character, 0x0E33 shall be
                //moved ahead to let the circyle sign on the top of previous or previous2 character
                if (curCh == 0x0E33 && (IsThaiBaseLineChar(preCh) || IsThaiBaseLineChar(pre2Ch)))
                {
                    width = (adv_w - 1)+ metrics.width;
                    adv_w = adv_w - 1 + metrics.adv_x;
                }
                else
                {
                    width = adv_w + metrics.width;
                    adv_w = adv_w + metrics.adv_x;
                }
            }
            /* For Thai digits and base line sign, the only thing we have to do is moving cursor */
            else if (IsThaiDigitChar(curCh) || IsThaiBaseSignChar(curCh))
            {
                width = adv_w + metrics.width;
                adv_w += metrics.adv_x;
            }
            else if (IsThaiToneMark(curCh))
            {
                if (IsThaiSignChar(preCh))
                {
                    /* move the tone two pixel way from the sign. */
                    adv_w +=2;
                    width = adv_w + metrics.adv_x;
                    adv_w += (metrics.adv_x);
                }
                else if (IsThaiBaseLineChar(preCh) && preCh != 0x0e30)
                {
                
                }
                else if (IsThaiAboveLineChar(preCh))
                {
                    if (!IsThaiBaseLineChar(pre2Ch))
                    {
                        /* check the above line or bottom line char width */
                        if (prev_up_line_adv < metrics.adv_x)
                        {
                            adv_w += (metrics.adv_x - prev_up_line_adv);
                        }
                        if (prev_up_line_width < metrics.width)
                        {
                            prev_up_line_width += (metrics.width - prev_up_line_width);
                        }
                    }
                }
                else if (IsThaiBottomLineChar(preCh))
                {
                    if (!IsThaiBaseLineChar(pre2Ch))
                    {
                        /* check the above line or bottom line char width */
                        if (prev_bottom_line_adv < metrics.adv_x)
                        {
                            adv_w += (metrics.adv_x - prev_bottom_line_adv);
                        }
                        if (prev_bottom_line_width < metrics.width)
                        {
                            prev_bottom_line_width += (metrics.width - prev_bottom_line_width);
                        }
                        
                    }
                }                
                else if (preCh == 0x0E47)
                {
                    /* move the tone mark to next character space */
                    width = adv_w + metrics.adv_x;
                    adv_w += (metrics.adv_x);
                }
                else
                {
                    width = adv_w + metrics.adv_x;
                    adv_w += (metrics.adv_x);
                }
            }
            else if(IsThaiSignChar(curCh))
            {
                if((IsThaiBaseLineChar(preCh) && IsThaiUpSign(curCh)))
                {
                    /* no increase in with. Because the when the previous character is baseline char, 
                        the sign character would be put in the top of the previous one. */
                }
                else if (IsThaiUpDownVowel(preCh) && IsThaiUpSign(curCh))
                {
                    /* no increase in widht. Because up sign could be put in the same vertical line with up and down vowel. */
                    if (!IsThaiBaseLineChar(pre2Ch))
                    {
                        if (IsThaiBottomLineChar(preCh))
                        {
                            /* check the above line or bottom line char width */
                            if (prev_bottom_line_adv < metrics.adv_x)
                            {
                                adv_w += (metrics.adv_x - prev_bottom_line_adv);
                            }
                            if (prev_bottom_line_width < metrics.width)
                            {
                                prev_bottom_line_width += (metrics.width - prev_bottom_line_width);
                            }
                        }
                        else if (IsThaiAboveLineChar(preCh))
                        {
                            /* check the above line or bottom line char width */
                            if (prev_up_line_adv < metrics.adv_x)
                            {
                                adv_w += (metrics.adv_x - prev_up_line_adv);
                            }
                            if (prev_up_line_width < metrics.width)
                            {
                                prev_up_line_width += (metrics.width - prev_up_line_width);
                            }
                        }
                    }
                }                
                else
                {
                    width = adv_w + metrics.adv_x;
                    adv_w += (metrics.adv_x);
                }
            }
            else if (IsThaiAboveLineChar(curCh))
            {
                if (!(IsThaiBaseLineChar(preCh) && IsThaiConsonant(preCh)))
                {
                    width = adv_w + metrics.adv_x;
                    adv_w += (metrics.adv_x);
                }
                metrics.ascent++;
                prev_up_line_width = metrics.width;
                prev_up_line_adv = metrics.adv_x;
            }
            else if (IsThaiToneMark(curCh))
            {
                metrics.ascent++;
            }
            else if (IsThaiBottomLineChar(curCh))
            {
                /* Bottom line characters */
                if (!IsThaiBaseLineChar(preCh))
                {
                    width = adv_w + metrics.adv_x;
                    adv_w += (metrics.adv_x);
                }
                prev_bottom_line_width = metrics.width;
                prev_bottom_line_adv = metrics.adv_x;
            }
        }

        if (metrics.ascent > ascent)
            ascent = metrics.ascent;
        
        if (metrics.descent > descent)
            descent = metrics.descent;
                
        counter ++;
        pre2Ch = preCh;
        preCh = curCh;
    }
    cluster->w = width;
    cluster->h = ascent + descent;
    cluster->by = ascent;
    cluster->adv_x = adv_w;

}
#endif

#if defined(__MMI_VECTOR_FONT_SUPPORT__)
void mmi_fe_set_char_pos(mmi_fe_glyph_ot_info_p pos_info, mmi_fe_glyph_info_p glyph_info,mmi_fe_char_pos_struct* pos, mmi_fe_char_pos_struct* currpos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pos_info->offset < 0)
    {
        mmi_fe_glyph_ot_info_p baseCharGlyph;
        mmi_fe_char_pos_struct* baseCharPos;

        baseCharGlyph = pos_info + pos_info->offset;
        baseCharPos = pos + pos_info->offset;
        pos->x_pos = baseCharPos->x_pos + pos_info->pos_x;
        pos->y_pos = baseCharPos->y_pos + (-pos_info->pos_y);
    }
    else if (pos_info->offset == 0)
    {
        pos->x_pos = currpos->x_pos + pos_info->pos_x;
        pos->y_pos = currpos->y_pos + (-pos_info->pos_y);
    }        
    else
    {
        MMI_ASSERT(0);
    }
}

#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_query_single_cluster
 * DESCRIPTION
 *  To query one cluster. 
 * PARAMETERS
 *  param:   [IN] the parameter for one cluster
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_query_single_cluster(mmi_lm_cluster_info_p prev_cluster, mmi_lm_cluster_info_p cluster)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    FE_LOCK;
#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    {
        mmi_fe_text_info_p text_info = NULL;
        S32 i = 0, len = 0, start_index = 0, run_len = 0, cluster_len;        
        UI_character_type cluster_text[FE_MAX_CLUSTER_LEN*2];
        S32 temp_descent = 0;
        mmi_fe_char_pos_struct position[FE_MAX_CLUSTER_LEN];
        S16 descent;
        U8* pool_ptr;
        mmi_fe_char_pos_struct currpos = {0, 0};
        S32 width = 0, temp_x = 0;
        
        memset(&position, 0, sizeof(mmi_fe_char_pos_struct)*FE_MAX_CLUSTER_LEN);
        memset(&cluster_text, 0, sizeof(UI_character_type)*FE_MAX_CLUSTER_LEN);
        switch (cluster->lang_id)
        {
        #if defined(__MMI_INDIC_ALG__)
            case MMI_LM_LANG_INDIC:
                {
                    UI_character_type prev_ch = 0;
                    UI_character_type curr_ch = cluster->data_ptr[0] | (cluster->data_ptr[1] << 8); 
                    if (prev_cluster)
                        if (prev_cluster->data_ptr)
                            prev_ch = prev_cluster->data_ptr[0] | (prev_cluster->data_ptr[1] << 8); 
                    if (ire_get_character_lang_id(curr_ch) == ire_get_character_lang_id(prev_ch))
                    {
                        memcpy(&cluster_text, prev_cluster->data_ptr, prev_cluster->data_len << 1);
                        memcpy(&cluster_text[prev_cluster->data_len], cluster->data_ptr, cluster->data_len << 1);
                        len = prev_cluster->data_len + cluster->data_len;
                        start_index = prev_cluster->data_len;
                        run_len = cluster->data_len;
                    }
                    else
                    {
                        memcpy(&cluster_text, cluster->data_ptr, cluster->data_len<<1);
                        len = cluster->data_len;
                        start_index = 0;
                        run_len = len;
                    }
                }
                break;
        #endif        
            default:
                memcpy(&cluster_text, cluster->display_buffer, cluster->cluster_len<<1);
                len = cluster->cluster_len;
                start_index = 0;
                run_len = len;
                break;
        }

        cluster_len = mmi_fe_shaper(cluster->lang_id, cluster_text, len, start_index, run_len, (mmi_fe_text_info_p*)&pool_ptr);
        /* calculate the info */
        if (cluster_len)
        {
            for (i = 0; i < cluster_len; i ++)
            {                    
                text_info = (mmi_fe_text_info_p)pool_ptr;
                mmi_fe_set_char_pos(&text_info->posdata, &text_info->glyph_data, &position[i], &currpos);
                temp_x = position[i].x_pos + text_info->glyph_data.bearing_x;
                if (temp_x < 0)
                    temp_x = 0;
                if (temp_x + text_info->glyph_data.width > width)
                    width = temp_x + text_info->glyph_data.width;
                
                if (text_info->glyph_data.bearing_y - position[i].y_pos > cluster->by)
                    cluster->by = text_info->glyph_data.bearing_y - position[i].y_pos;

                descent = text_info->glyph_data.height - text_info->glyph_data.bearing_y;
                if (descent> temp_descent)
                    temp_descent = descent;
                if (text_info->posdata.new_advance)
                {
                    currpos.x_pos = currpos.x_pos + text_info->posdata.delta_x;
                }
                else
                {
                    currpos.x_pos = currpos.x_pos + (text_info->posdata.delta_x + text_info->glyph_data.advance_x);
                }

                /* goto next glyph */
                pool_ptr += (sizeof(mmi_fe_glyph_ot_info) + sizeof(mmi_fe_glyph_info) + FE_FOUR_BYTE_ALIGN(text_info->glyph_data.bitmap_size));            
            }
            cluster->adv_x = currpos.x_pos;
            cluster->w = width;
            cluster->h = cluster->by + temp_descent;
            
            if (cluster_len > 0 && cluster->adv_x == 0)
            {
                cluster->adv_x = width;
            }
        }
        else
        {
            cluster->w = 0;
            cluster->h = 0;
            cluster->adv_x = 0;
            cluster->adv_y = 0;
            cluster->bx = 0;
            cluster->by = 0;
            
        }

    }

#else

    switch (cluster->lang_id)
    {
    #if defined(__MMI_LANG_THAI__)
        case MMI_LM_LANG_THAI:
            mmi_fe_query_thai_cluster(cluster);
            break;
    #endif        
    #if defined(__MMI_INDIC_ALG__)
        case MMI_LM_LANG_INDIC:
            {
                mmi_fe_get_string_info_param_struct param = {0};
                U16 disp_cluster[G_MAX + 1];
                if (cluster->data_len == 1)
                {
                    disp_cluster[0] = MMI_LM_GET_CHARACTER_FROM_BUFFER(cluster->data_ptr);
                    disp_cluster[1] = 0;
                    cluster->cluster_len = 1;
                }
                else
                {
                    UI_character_type org_data[G_MAX + 1];
                    memcpy(&org_data, cluster->data_ptr, cluster->data_len*sizeof(UI_character_type));
                    org_data[cluster->data_len] = 0;
                    cluster->cluster_len = ire_language_rules(disp_cluster, org_data, cluster->data_len);
                    disp_cluster[cluster->cluster_len] = 0;
                }
                if (cluster->cluster_len < MMI_LM_CLUSTER_MAX)
                    memcpy(&cluster->display_buffer, disp_cluster, (cluster->cluster_len+1)<<1);
                param.String = (U8*)(disp_cluster);
                param.n = cluster->cluster_len;
                
            #if defined (__MMI_LANG_TELUGU__)
                IRE_RESET_RENDERING_CORRECTION();
            #endif
                mmi_fe_get_string_widthheight_indic_internal(&param);
                     
                cluster->w = param.pWidth;
                cluster->h = param.pHeight;
                cluster->by = param.baseline;
                cluster->adv_x = param.adv_w;
            }
            break;
    #endif        
        default:
            {
                /*----------------------------------------------------------------*/
                /* Local Variables                                                */
                /*----------------------------------------------------------------*/
                S32 i = 0;
                U16 ch; 
                S16 temp_ascent = 0;
                S16 temp_descent = 0;
                mmi_fe_glyph_metrics_struct matrix;
                S16 temp_height = 0;
                S16 x = 0;
                /*----------------------------------------------------------------*/
                /* Code Body                                                      */
                /*----------------------------------------------------------------*/
                for (;i < cluster->cluster_len; i ++)
                {
                    ch = cluster->display_buffer[i];
                    if (i != 0)
                    {
                        cluster->w+= matrix.adv_x;        
                    }
                    mmi_fe_get_glyph_metrics(ch, &matrix);
                    cluster->adv_x += matrix.adv_x;
                    if (matrix.ascent > temp_ascent)
                        temp_ascent = matrix.ascent;
                    if (matrix.descent > temp_descent)
                        temp_descent = matrix.descent;
                    if (temp_height < matrix.height)
                        temp_height = matrix.height;
                    x+= matrix.adv_x;
                }
                if (cluster->cluster_len == 1 && cluster->adv_x == 0)
                {
                    cluster->adv_x += matrix.width;
                }
            
                cluster->w+= matrix.width;  
                cluster->h = temp_ascent+ temp_descent;
                if (cluster->h < temp_height)
                    cluster->h = temp_height;
                cluster->by = temp_ascent;
            }

            break;
    }

#endif
    GDI_UNLOCK;
    FE_UNLOCK;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_single_cluster
 * DESCRIPTION
 *  To display one cluster. The content should be in its display form.
 * PARAMETERS
 *  param:   [IN] the parameter for one cluster
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_show_single_cluster(mmi_fe_show_one_cluster_param_struct_p param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_color border_color = 0, text_color;
    mmi_fe_showstring_int_param_struct show_param;
    U8 tempFontAttrib = gnCurrentFontAttrib;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    FE_LOCK;
    memset(&show_param, 0, sizeof(mmi_fe_showstring_int_param_struct));
    text_color = gdi_act_color_from_rgb(0xff, g_mmi_fe_text_color.r, g_mmi_fe_text_color.g, g_mmi_fe_text_color.b);
    border_color = gdi_act_color_from_rgb(0xff, g_mmi_fe_text_border_color.r, g_mmi_fe_text_border_color.g, g_mmi_fe_text_border_color.b);
    gnCurrentFontAttrib &= (~(FONTATTRIB_UNDERLINE | FONTATTRIB_STRIKETHROUGH));
    gdi_font_begin(param->x, param->y, text_color, gnCurrentFontAttrib);

    if (param->bordered && 
        g_mmi_fe_text_border_color.r == TRANSPARENT_COLOR_R && 
        g_mmi_fe_text_border_color.g == TRANSPARENT_COLOR_G && 
        g_mmi_fe_text_border_color.b == TRANSPARENT_COLOR_B)
    {
        param->bordered = 0;
    }

#ifdef __MMI_VECTOR_FONT_SUPPORT__
    font_engine->set_font_color(text_color,border_color);
    if(param->bordered) 
    {
        font_engine_font_attr |= FE_FONT_ATTR_BORDER;
        font_engine->set_font_attr(font_engine_font_attr);
    #ifdef __MTK_TARGET__
        kal_check_stack(); /* if overflow , assert it */
    #endif
    }
    {
        S32 i = 0, len = 0;
        mmi_fe_char_pos_struct position[FE_MAX_CLUSTER_LEN];
        mmi_fe_char_pos_struct currpos;
        UI_character_type cluster_buffer[FE_MAX_CLUSTER_LEN*2];
        mmi_fe_text_info_p text_info = NULL;        
        U8* pool_ptr;
        S32 disp_x;
        currpos.x_pos = param->x;
        currpos.y_pos = param->y;

        memset(cluster_buffer, 0, sizeof(cluster_buffer));
        memcpy(cluster_buffer, param->string, sizeof(UI_character_type)*param->len);
        memset(position, 0, sizeof(position));

        len = mmi_fe_shaper(param->langid, cluster_buffer, param->len, param->subarray_start, param->subarray_len, (mmi_fe_text_info_p*)&pool_ptr);
        /* calculate the info */
        for (i = 0; i < len; i ++)
        {                    
            text_info = (mmi_fe_text_info_p)pool_ptr;
            mmi_fe_set_char_pos(&text_info->posdata, &text_info->glyph_data, &position[i], &currpos);
            disp_x = position[i].x_pos + text_info->glyph_data.bearing_x;
            if (disp_x < param->x)
                disp_x = param->x;
            mmi_fe_show_font_data(
                text_info->posdata.glyph_index, 
                disp_x, 
                (param->baseline - text_info->glyph_data.bearing_y) + position[i].y_pos, 
                (U8*)&text_info->glyph_data.bitmap, 
                text_info->glyph_data.bitmap_size, 
                FE_GLYPH_ATTR_USING_FONT_ENGINE, 
                text_info->glyph_data.width, 
                text_info->glyph_data.height, 
                param->bordered, 
                gnCurrentFontAttrib, 
                text_color, 
                border_color);
           // mmi_fe_update_char_pos(&fe_cluster.glyph_buf[i], &position[i + 1], &position[i]);
            if (text_info->posdata.new_advance)
            {
                currpos.x_pos = currpos.x_pos + text_info->posdata.delta_x;
            }
            else
            {
                currpos.x_pos = currpos.x_pos + (text_info->posdata.delta_x + text_info->glyph_data.advance_x);
            }
            //currpos.y_pos = position[i].y_pos;
            
            /* goto next glyph */
            pool_ptr += (sizeof(mmi_fe_glyph_ot_info) + sizeof(mmi_fe_glyph_info) + FE_FOUR_BYTE_ALIGN(text_info->glyph_data.bitmap_size));
        }        
    }

    if (param->bordered) 
    {
        font_engine_font_attr &= ~FE_FONT_ATTR_BORDER;
        font_engine->set_font_attr(font_engine_font_attr);
    #ifdef __MTK_TARGET__
        kal_check_stack(); /* if overflow , assert it */
    #endif
    }

#else

    switch (param->langid)
    {
    #if defined(__MMI_LANG_THAI__)
        case MMI_LM_LANG_THAI:
            {
                UI_character_type prech = 0, pre2ch = 0, curch = 0;
                S32 i, char_w = 0;
                S32 string_width = 0;
                
                show_param.Bordered = param->bordered;
                show_param.BaseLineHeight = param->baseline;
                show_param.text_color = text_color;
                show_param.border_color = border_color;
                for (i = 0; i < param->len; i ++)
                {
                    curch = param->string[(i << 1)] | (param->string[(i << 1)+1] << 8);
                    char_w = mmi_fe_show_thai_char_internal(param->x+string_width, param->y, pre2ch, prech, ((UI_string_type)param->string)[i], &show_param);
                    if (char_w > string_width)
                        string_width = char_w;
                    pre2ch = prech;
                    prech = curch;
                }
            }
            break;
    #endif
    #if defined(__MMI_INDIC_ALG__)
        case MMI_LM_LANG_INDIC:            
            {
                S32 clip_x1, clip_x2, clip_y1, clip_y2;

                gdi_layer_get_clip(&clip_x1, &clip_y1, &clip_x2, &clip_y2);
                ire_indic_padding_value(0);
                show_param.String = param->string;
                show_param.len = param->len;
                show_param.x = param->x;
                show_param.y = param->y;
                show_param.text_color = text_color;
                show_param.border_color = border_color;
                show_param.Bordered = param->bordered;
                show_param.BaseLineHeight = param->baseline;
                show_param.clip_x1 = clip_x1;
                show_param.clip_x2 = clip_x2;
                show_param.clip_y1 = clip_y1;
                show_param.clip_y2 = clip_y2;    
                if (ire_is_reset_indic_params())
                    ire_reset_indic_params();
                mmi_fe_show_indic_string_internal(&show_param);
                ire_indic_padding_def_value();
            }
            break;
    #endif
        default:
            {
                mmi_fe_show_single_cluster_other(param, text_color,border_color);       
            }
            break;
    }
#endif

    gnCurrentFontAttrib = tempFontAttrib;
    gdi_font_end();
    FE_UNLOCK;
    GDI_UNLOCK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_check_string
 * DESCRIPTION
 *  To check the input string if the first len character is supported in current font configuration
 * PARAMETERS
 *  font:                   [IN]        
 *  string:                 [IN] the desired string
 *  len:                     [IN] the first len character should be checked.
 * RETURNS
 *  MMI_BOOL           the validness of the string
 *****************************************************************************/
MMI_BOOL mmi_fe_check_string(stFontAttribute font, U8* string, S32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 Ch;
    U32 data_attr;
    U8 *pCharData;
    U16 dataWidth, dataHeight;
    S32 nWidth, nDWidth, ascent, descent, bearing_x;
    MMI_BOOL valid;    
    S32 index;
    MMI_BOOL ret = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    FE_LOCK;
    for (index = 0; index < len; index ++)
    {
        Ch = string[0] | (string[1] << 8);
        string+=2;

        mmi_fe_get_font_data(
            MMI_FE_VALID_CHECK, 
            Ch, 
            &pCharData, 
            &data_attr, 
            &nWidth, 
            &nDWidth, 
            &dataWidth, 
            &dataHeight, 
            &bearing_x, 
            &ascent, 
            &descent, 
            &valid);
        if (!valid)
        {
            ret = MMI_FALSE;
            break;
        }
    }
    FE_UNLOCK;    
    GDI_UNLOCK;
    return ret;
}


#if defined(__MMI_VECTOR_FONT_SUPPORT__)
#define FE_CELL_DIFF_HALF(a, b)  ((a) >= (b) ? (((a) - (b)) - (((a)-(b))>>1)) : 0)
#else
#define FE_CELL_DIFF_HALF(a, b)  ((a) >= (b) ? (((a)-(b))>>1) : 0)
#endif
#define FE_CELL_DIFF_THREE_FOURTH(a, b) ((a) >= (b)? (((a) - (b)) - (((a) - (b))>>2)) : 0)

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_char_with_bounding_box
 * DESCRIPTION
 *  show character inside the bounding box with the specified font size
 * PARAMETERS
 *  x       [IN]  the x position
 *  y       [IN]  the y position
 *  width  [IN]   the bounding box width
 *  height  [IN]   the bounding box height
 *  ch     [IN]  the specified character
 *  type    [IN]  aligh type
 *  Font    [IN]  the max font size
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_show_char_with_bounding_box(S32 x, S32 y, S32 width, S32 height, U16 ch, mmi_fe_align_type type, stFontAttribute Font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 glyph_width, glyph_height, bbox_x, bbox_y, bbox_width, bbox_height, diff_w, diff_h;
    U8 arrCount = 0;
    S32 char_x, char_y;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    FE_LOCK;
    
#if defined(__MMI_VECTOR_FONT_SUPPORT__)    
    /* for the case using enum, change it to pixel size. */
    if (Font.size < 6)
        Font.size = FONT_PIXEL_SIZE(mmi_fe_size_to_pixel(Font.size));
    do
#endif        
    {
        SetFont(Font, arrCount);
        Get_CharBoundingBox(ch, &glyph_width, &glyph_height, &bbox_x, &bbox_y, &bbox_width, &bbox_height);
        /* leave 2 as the border */
        diff_w = bbox_width - width;
        diff_h = bbox_height - height;
        Font.size -=2;
    }
#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    while (bbox_width > width || bbox_height > height);
#endif    


    switch (type)
    {
        case MMI_FE_ALIGN_BOTTOM: /* bottom align */       
            char_x = x + FE_CELL_DIFF_HALF(width, bbox_width) - bbox_x;
            char_y = y + FE_CELL_DIFF_THREE_FOURTH(height, bbox_height) - bbox_y;
            break;
        case MMI_FE_ALIGN_TOP:            
            char_x = x + FE_CELL_DIFF_HALF(width, bbox_width) - bbox_x;
            char_y = y + FE_CELL_DIFF_HALF(height, glyph_height);
            break;
        default: /* center align */
            
            char_x = x + FE_CELL_DIFF_HALF(width, bbox_width) - bbox_x;
            char_y = y + FE_CELL_DIFF_HALF(height, bbox_height) - bbox_y;
            
            /* HACK. the number of remaing pixels is odd. */
            /* It is not always correct depending on the baseline of the font database */
            /* The magic number bbox_y + "1" can be modified */
            if (((height - bbox_height) & 1) && (bbox_y > glyph_height - bbox_height - bbox_y))
            {
                char_y++;
            }
            break;
    }

    mmi_fe_show_char_at_xy(char_x, char_y, ch);

    FE_UNLOCK;
    GDI_UNLOCK;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_char_at_xy
 * DESCRIPTION
 *  To display the character at a specifed position. 
 *  Rendering rule would not be considered to adjuest the x,y position.
 * PARAMETERS
 *  x:       [IN]  the x position
 *  y:       [IN]  the y position
 *  ch:     [IN]  the specified character
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_show_char_at_xy(S32 x, S32 y, U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *CharData;
    U32 CharDataAttr;
    U32 NumChar;
    S32 nWidth;
    U16 glyph_width;
    U16 glyph_height;
    S32 ascent = 0;
    S32 descent = 0;
    S32 bearing_x;
    S32 advance_x;
    gdi_color text_color;
    MMI_BOOL valid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check for formatting character */
    if (mmi_fe_test_display_as_null((U32)ch))
        return;
    GDI_LOCK;
    FE_LOCK;

    text_color = gdi_act_color_from_rgb(0xff, g_mmi_fe_text_color.r, g_mmi_fe_text_color.g, g_mmi_fe_text_color.b);
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    font_engine->set_font_color(text_color,0);
#endif

    if (mmi_fe_test_display_as_space(ch))
    {
        ch = 0x20;
    }
    if (mmi_fe_test_display_as_invalid(ch))
    {
        ch = 0xFFEB;
    }        
    gdi_font_begin(x,y,text_color, gnCurrentFontAttrib);

    NumChar = mmi_fe_get_font_data(MMI_TRUE, ch, &CharData,&CharDataAttr, &nWidth, &advance_x, &glyph_width, &glyph_height, &bearing_x,&ascent, &descent, &valid);

    mmi_fe_show_font_data(ch , x, y, CharData,NumChar,CharDataAttr,glyph_width,glyph_height,
                              0,gnCurrentFontAttrib,text_color,0);

    gdi_font_end();
    FE_UNLOCK;
    GDI_UNLOCK;
}


const L2RLangSSC l2RLangSSC[] = 
{
    SSC_ARABIC,
    SSC_PERSIAN,
    SSC_URDU,
    SSC_HEBREW
};


/*****************************************************************************
 * FUNCTION
 *  IsL2RMMIStyle
 * DESCRIPTION
 *  To check if current langauge should be rendered from R2L or L2R
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE or FALSE
 *****************************************************************************/
BOOL IsL2RMMIStyle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = 0;
    U8 temp_str1[30];
    U8 temp_str2[30];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2((S8*) temp_str1, (S8*) gLanguageArray[gCurrLangIndex].aLangSSC);

    for (index = 0; index < (sizeof(l2RLangSSC) / sizeof(l2RLangSSC[0])); index++)
    {
        mmi_asc_to_ucs2((S8*) temp_str2, (S8*) l2RLangSSC[index].sscString);
        /* pTemp = (U8 *) temp_str; */

        if (mmi_ucs2cmp((const S8*)temp_str1, (const S8*)temp_str2) == 0)
        {
            return MMI_TRUE;
        }

    }

    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  ShowDebugString
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x               [IN]        
 *  y               [IN]        
 *  Font            [IN]        
 *  String          [?]         
 *  len             [IN]        
 *  LineHeight      [IN]        
 *  Bordered        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 ShowDebugStringInt(S32 x, S32 y, U8 *String, S32 len, U32 Bordered)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *CharData;

    U32 NumChar;
    U32 Counter = 0;
    S32 CurrentX;
    S32 nWidth;
    U16 unicode = 0;
    U16 glyph_width;
    U16 glyph_height;
    S32 ascent = 0;
    S32 descent = 0;
    S32 advance_x = 0;
    U16 nHeight = 0;
    gdi_color border_color = 0, text_color;
    MMI_BOOL valid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    mmi_fe_disable_font_engine();
#endif
    if (Bordered) border_color = gdi_act_color_from_rgb(0xff, g_mmi_fe_text_border_color.r, g_mmi_fe_text_border_color.g, g_mmi_fe_text_border_color.b);
    text_color = gdi_act_color_from_rgb(0xff, g_mmi_fe_text_color.r, g_mmi_fe_text_color.g, g_mmi_fe_text_color.b);

#ifdef __MMI_VECTOR_FONT_SUPPORT__
    font_engine->set_font_color(text_color,border_color);
#endif

    gdi_font_begin(x,y,text_color, gnCurrentFontAttrib);

    CurrentX = x;
    while (len != 0)
    {
        if ((String[0] == '\0') && (String[1] == '\0'))
        {
            break;
        }
        len--;

        unicode = String[0];
        unicode |= (String[1] << 8);

        if (mmi_fe_test_display_as_space(unicode))
        {
            unicode = 0x20;
        }
        if (mmi_fe_test_display_as_invalid(unicode))
        {
            unicode = 0xFFEB;
        }        

        NumChar = mmi_fe_get_font_data_internal(unicode, MMI_FE_GET_DATA, &CharData, &nWidth, &advance_x, &nHeight, &glyph_width, &glyph_height, &ascent, &descent, &valid);

        Counter++;
        mmi_fe_show_font_data(unicode , CurrentX,y,CharData,NumChar,0,glyph_width,glyph_height,
                              Bordered,gnCurrentFontAttrib,text_color,border_color);

        CurrentX += nWidth;

        String += 2;
    }
    gdi_font_end();


    return CurrentX;
}


/*****************************************************************************
 * FUNCTION
 *  ShowDebugString
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x               [IN]        
 *  y               [IN]        
 *  Font            [IN]        
 *  String          [?]         
 *  len             [IN]        
 *  LineHeight      [IN]        
 *  Bordered        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 ShowDebugString(S32 x, S32 y, stFontAttribute Font, U8 *String, S32 len, U32 LineHeight, U32 Bordered)
{

    
    return ShowDebugStringInt(x, y, String, len, Bordered);
}
/*-----------------------------------------------------------------------*/
/*--------------------------- *** End *** -------------------------------*/
/*-----------------------------------------------------------------------*/

