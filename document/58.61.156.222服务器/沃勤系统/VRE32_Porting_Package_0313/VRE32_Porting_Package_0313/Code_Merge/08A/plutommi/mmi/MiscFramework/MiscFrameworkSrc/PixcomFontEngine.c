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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
*  Include
*****************************************************************************/
#include "MMI_include.h"
#include <signal.h>
#include "FontData.h"
#include "gui_data_types.h"

#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__)

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
#ifdef __MMI_ARSHAPING_ENGINE__
#include "ArabicGProt.h"
#endif 

#include "gui.h"
#include "PixcomFontEngine.h"

/* For Langauge */
#ifdef __MMI_INDIC_ALG__
#include "IndicEngineGprot.h"
#endif /* __MMI_INDIC_ALG__ */ 

#ifdef __MMI_ARSHAPING_ENGINE__
#include "ArabicGProt.h"
#endif 

#ifdef __MMI_LANG_VIETNAMESE__
#include "gui_lang_viet.h"
#endif 

#include "BIDIDEF.h"
#include "BIDIGProt.h"


#if defined(__MMI_LANG_THAI__)
#include "ThaiGProt.h"
#endif

#include "ATHandlerProt.h"
#include "SSCStringHandle.h"
#include "BIDIDEF.h"
#include "BIDIGProt.h"
#include "UCS2Prot.h"
#include "Gdi_font.h"
#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
#endif


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

/*****************************************************************************
*  Typedef
*****************************************************************************/
typedef struct
{
    S32 x;
    S32 y; 
    S32 char_gap;
    stFontAttribute Font;
    U8 BackGround;
    U8 *String;
    S32 len;
    U32 BaseLineHeight;
    U32 Bordered;
    MMI_BOOL enable_truncated;
    U8 *truncated_symbol;
    S32 truncated_symbol_start;
    S32 visible_x_start;
    S32 visible_x_end;
    U8 assign_direction;
    S32 LineHeight;
    S32 LineHeightDiff;
    gdi_color border_color; 
    gdi_color text_color;
    U8 font_attr;
    U32 render_flag;
}mmi_fe_showstring_param_struct, *mmi_fe_showstring_param_struct_p;



typedef enum
{
    MMI_FE_LANG_NONE = 0,
    MMI_FE_LANG_THAI,
    MMI_FE_LANG_ARABIC,
    MMI_FE_LANG_INDIC,
    MMI_FE_LANG_OTHERS,
    MMI_FE_LANG_MAX
}mmi_fe_lang_id;



/*****************************************************************************
*  Global Variables
*****************************************************************************/
U8 gnCurrentFontAttrib = FONTATTRIB_NORMAL;
U8 gbFontType = 0;
static U32 fe_display_flag = 0;
BOOL cancelWidth = 0;

U32 gThaiLineHeight = 17;

void SetFontValues(U32 nFont, U8 arrCount);

/* extern sLanguageDetails gLanguageArray[MAX_LANGUAGES]; */
extern sLanguageDetails *gLanguageArray;
extern void gdi_font_begin(gdi_color fg_color, U8 font_attr);
extern void gdi_font_end(void);

/* MTK steven for removing compile warnings */
extern void gdi_show_char_bordered(
                S32 x,
                S32 y,
                gdi_color text_color,
                gdi_color border_color,
                U8 *font_data,
                U32 font_data_size,
                U16 char_width,
                U16 char_height,
                U8 font_attr);
extern void gdi_show_char(
                S32 x,
                S32 y,
                gdi_color color,
                U8 *font_data,
                U32 font_data_size,
                U16 char_width,
                U16 char_height,
                U8 font_attr);

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

#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__)
const RangeData gMTKProprietaryFont_RangeData[46]={
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
{65515,65515},
};

const RangeDetails gMTKProprietaryFont_RangeInfo={
46,
    gMTKProprietaryFont_RangeData

};

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

const RangeData gMTKProprietaryFont_RangeData[46]={
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
{65515,65515},
};

const RangeDetails gMTKProprietaryFont_RangeInfo ={
46,
gMTKProprietaryFont_RangeData
};


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
static U32 mmi_fe_show_string_ext(mmi_fe_showstring_param_struct_p param);
#if defined(__MMI_LANG_THAI__)
static U32 mmi_fe_show_thai_string(mmi_fe_showstring_param_struct_p param);
static U32 mmi_fe_get_string_widthheight_thai(mmi_fe_get_string_info_param_struct_p param);
#endif
#if defined(__MMI_INDIC_ALG__)
static U32 mmi_fe_show_indic_string(mmi_fe_showstring_param_struct_p param);
static U32 mmi_fe_show_indic_string_internal(mmi_fe_showstring_param_struct_p param);
static U32 mmi_fe_get_string_widthheight_indic_internal(mmi_fe_get_string_info_param_struct_p param);
#endif
static U32 mmi_fe_get_string_widthheight_others(mmi_fe_get_string_info_param_struct_p param);
static U32 mmi_fe_get_string_widthheight_by_lang(mmi_fe_get_string_info_param_struct_p param, mmi_fe_lang_id langid);
/* Vogins Start */
#ifdef __VRE__
U32 mmi_fe_get_string_widthheight(mmi_fe_get_string_info_param_struct_p query);
#else
static U32 mmi_fe_get_string_widthheight(mmi_fe_get_string_info_param_struct_p query);
#endif
/* Vogins End */
static S32 mmi_font_engine_get_baseline_internal(U8 *st, S32 len, stFontAttribute Font, S32 *LineHeight);
static mmi_font_engine_error_message_enum mmi_fe_get_display_direction(U8* st, U8* dic, S32 len);

static mmi_fe_lang_id mmi_fe_get_lang_id(U16 ch);

void SetFontValues(U32 nFont, U8 arrCount);
static MMI_BOOL mmi_fe_test_display_as_space(U32 ch);
static MMI_BOOL mmi_fe_test_display_as_null(U32 ch);

U8 mmi_ucs2_to_wc(PU16 pUnicode, PU8 arr);

/**************************************************************/
extern void text_drawpixel2(S32 x, S32 y);
extern color UI_current_text_color;
extern color UI_text_border_color;

/* extern color UI_text_color; */
extern void (*_ui_text_putpixel) (S32 x, S32 y, color c);
extern void (*_ui_text_putpixel_unconditional) (S32 x, S32 y, color c);
extern void UI_set_current_text_color(color c);


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
static MMI_BOOL mmi_fe_test_display_as_space(U32 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FONT_TEST_CONTROL_CHAR(ch) || (FONT_TEST_SPACE_CHAR(ch) &&! FONT_TEST_ZERO_WIDTH_SPACE(ch)))
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
static MMI_BOOL mmi_fe_test_display_as_null(U32 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ch == 0x0 || ch == 0x7f ||
         FONT_TEST_ZERO_WIDTH_CHAR(ch) ||
         FONT_TEST_FORMATTING_CHARS(ch) || 
         FONT_TEST_ZERO_WIDTH_SPACE(ch) ||
        (FONT_TEST_DATE_CHARS(ch) && (!(fe_display_flag & FE_DISPLAY_FLAG_DATE_CHAR))) ||
        (FONT_TEST_CRLF_ANF_SPACE_PROPRIETARY_SYMBOL(ch) && 
          (!(fe_display_flag & FE_DISPLAY_FLAG_PROPRIETARY_SYMBOL_CHAR))))
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
    fe_display_flag |= FE_DISPLAY_FLAG_DATE_CHAR;
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
    fe_display_flag &= (~FE_DISPLAY_FLAG_DATE_CHAR);
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
    fe_display_flag |= FE_DISPLAY_FLAG_PROPRIETARY_SYMBOL_CHAR;

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
    fe_display_flag &= (~FE_DISPLAY_FLAG_PROPRIETARY_SYMBOL_CHAR);

}


/*****************************************************************************
 * FUNCTION
 *  ShowCharFuncDispatch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  LineHeight      [IN]        
 *  nWidth          [IN]        
 *  nHgt            [IN]        
 *  CurrentX        [IN]        
 *  CurrentY        [IN]        
 *  Font            [IN]        
 *  BackGround      [IN]        
 *  CharData        [?]         
 *  NumChar         [IN]        
 *  Bordered        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
__inline static void ShowCharFuncDispatch(
                        U32 LineHeight,
                        U16 nWidth,
                        U16 nHgt,
                        S32 CurrentX,
                        S32 CurrentY,
                        stFontAttribute Font,
                        U8 BackGround,
                        U8 *CharData,
                        U32 NumChar,
                        U32 Bordered)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 font_attr = 0;
    gdi_color border_color = 0, text_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gnCurrentFontAttrib & FONTATTRIB_ITALIC)
    {
        font_attr |= FONTATTRIB_ITALIC;
    }
    else if (gnCurrentFontAttrib & FONTATTRIB_OBLIQUE)
    {
        font_attr |= FONTATTRIB_OBLIQUE;
    }

    if (Font.underline)
    {
        font_attr |= FONTATTRIB_UNDERLINE;
    }

    {
        if (Bordered)
        {
            border_color = gdi_act_color_from_rgb(0xff, UI_text_border_color.r, UI_text_border_color.g, UI_text_border_color.b);
        }

        text_color = gdi_act_color_from_rgb(0xff, UI_current_text_color.r, UI_current_text_color.g, UI_current_text_color.b);

    }

    if (Bordered)
    {
        gdi_show_char_bordered(
            CurrentX,
            CurrentY,
            text_color,
            border_color,
            CharData,
            NumChar,
            nWidth,
            nHgt,
            font_attr);
    }
    else if (!
             (gnCurrentFontAttrib & FONTATTRIB_BOLD &&
              gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_BOLD) ||
             !(gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_NORMAL))
    {
        gdi_show_char(CurrentX, CurrentY, text_color, CharData, NumChar, nWidth, nHgt, font_attr);
    }
    else
    {
        gdi_show_char(CurrentX + 1, CurrentY, text_color, CharData, NumChar, nWidth, nHgt, font_attr);
        gdi_show_char(CurrentX, CurrentY, text_color, CharData, NumChar, nWidth, nHgt, font_attr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  Get_Current_Lang_CountryCode
 * DESCRIPTION
 *  To get current language's country code
 *  
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

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U8*) gLanguageArray[gCurrLangIndex].aLangCountryCode;
}


/*****************************************************************************
 * FUNCTION
 *  SetFont
 * DESCRIPTION
 *  To set the fonts.
 *  
 *  This is used to set all different type of font with different sizes.
 * PARAMETERS
 *  Font            [IN]        
 *  arrCount        [IN]        
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

    return 0;
}



/*****************************************************************************
 * FUNCTION
 *  GetFont
 * DESCRIPTION
 *  To get the current font.
 *  
 *  This is used to get current font attribute.
 * PARAMETERS
 *  Font            [IN/OUT]        
 *  arrCount        [IN/OUT]        
 * RETURNS
 *  U8
 *****************************************************************************/
void GetFont(stFontAttribute *Font, U8 *arrCount)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
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
void SetFontValues(U32 nFont, U8 arrCount)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
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
            return gZiExtraCharacter.pRange[nMid];

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
 *  GetFontdata
 * DESCRIPTION
 *  To get font resource and data for a specific UCS2 character
 * PARAMETERS
 *  Ch              [IN]        
 *  Font            [IN]        
 *  ppCharData   [OUT]   
 *  pnWidth       [OUT]   
 *  pnHeight      [OUT]   
 *  pdataWidth  [OUT]   
 *  pdataHeight [OUT]   
 * RETURNS
 *  U32 the number of byte of the font resource
 *****************************************************************************/
static U32 GetFontdata(U32 Ch, stFontAttribute Font, U8 **ppCharData, U16 *pnWidth, U16 *pnDWidth, U16 *pnHeight, U16 *pdataWidth, U16 *pdataHeight, PU16 ascent, PU16 descent, MMI_BOOL* valid)
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

#ifdef __MMI_INDIC_ALG__
    sCustFontData *CurrentFont = gpCurrentFont;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    *pnDWidth = 0;
#endif /* __MMI_INDIC_ALG__ */ 
    *valid = MMI_TRUE;

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

    if (charHashTable[nHashKey].unicode == Ch && charHashTable[nHashKey].gnCurrentFont == gnCurrentFont)
    {
        *ppCharData = charHashTable[nHashKey].CharData;
        *pnWidth = charHashTable[nHashKey].Width;
        *pnHeight = charHashTable[nHashKey].Height;
        *pnDWidth = charHashTable[nHashKey].DWidth;
        /* usually the character width = data width */
        *pdataHeight = *pnHeight;
        *pdataWidth = * pnWidth; 
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
            *pnDWidth = *pnDWidth + 1;
        }
        
        return charHashTable[nHashKey].NumChar;
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
        charHashTable[nHashKey].DWidth = *pnDWidth = gpCurrentFont->nWidth;
        charHashTable[nHashKey].Height = *pnHeight = gpCurrentFont->nHeight;
        charHashTable[nHashKey].Ascent = *ascent = gpCurrentFont->nAscent;
        charHashTable[nHashKey].Descent = *descent = gpCurrentFont->nDescent;

        if (gpCurrentFont->nEquiDistant)
        {

            charHashTable[nHashKey].NumChar = NumChar = gpCurrentFont->nCharBytes;
            nIndexInList = index + (NumChar * (Ch - nBase));
            charHashTable[nHashKey].CharData = *ppCharData = (gpCurrentFont->pDataArray + nIndexInList);

        }
        else
        {
            nIndexInList = index + (Ch - nBase);
            charHashTable[nHashKey].Width = *pnWidth = gpCurrentFont->pWidthArray[nIndexInList];
            charHashTable[nHashKey].NumChar = NumChar =
                (gpCurrentFont->pOffsetArray[nIndexInList + 1] - gpCurrentFont->pOffsetArray[nIndexInList]);
            charHashTable[nHashKey].CharData = *ppCharData =
                (gpCurrentFont->pDataArray + gpCurrentFont->pOffsetArray[nIndexInList]);

        }
    #ifdef __MMI_INDIC_ALG__
        if (gpCurrentFont->pDWidthArray)
            charHashTable[nHashKey].DWidth = *pnDWidth = gpCurrentFont->pDWidthArray[nIndexInList];
        gpCurrentFont = CurrentFont;
    #endif /* __MMI_INDIC_ALG__ */ 
        /* usually the character width = data width */
        *pdataHeight = *pnHeight;
        *pdataWidth = * pnWidth;    
        if (!(gnCurrentFontAttrib & FONTATTRIB_BOLD &&
                gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_BOLD) ||
                !(gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_NORMAL))
        {
        
        }
        else
        {
            /* when bold word, character width is one more than data width */
            *pnWidth = *pnWidth + 1;
            *pnDWidth = *pnDWidth + 1;
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
            *pnDWidth = *pnWidth;
        }
        else
    #endif
        {
            index = SearchInPropFont(Ch, &nBase);
            if (index == -1)
            {
                Ch = 65515; /* 0x4E01;//0x000F; */
                *valid = MMI_FALSE;
                index = SearchInPropFont(Ch, &nBase);
                if (index == -1)
                {
                #ifdef __MMI_INDIC_ALG__
                    gpCurrentFont = CurrentFont;
                #endif 
                    *pnWidth = 0;
                    *pnHeight = 0;
                    *ascent = 0;
                    *descent = 0;
                    *pnDWidth = 0;
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
            *pnDWidth = *pnWidth;
        }
    }
#ifdef __MMI_INDIC_ALG__
    gpCurrentFont = CurrentFont;
#endif
    /* usually the character width = data width */
    *pdataHeight = *pnHeight;
    *pdataWidth = * pnWidth;    
    if (!(gnCurrentFontAttrib & FONTATTRIB_BOLD &&
            gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_BOLD) ||
            !(gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_NORMAL))
    {
    
    }
    else
    {
        /* when bold word, character width is one more than data width */
        *pnWidth = *pnWidth + 1;
    }    

    return NumChar;
}


/**************************************************************

   FUNCTION NAME     : GetLangIndex()

   PURPOSE           : To get the language index of the character.

   INPUT PARAMETERS  : U32 nCh - Character to look for

   OUTPUT PARAMETERS : U8* pCount - The langugae Index
                    S32* pnIndex - The offset of the character in the array
                    U32* pnBase -  Base of Character set

   RETURNS           : void
   REMARKS           : Gets the character information

**************************************************************/
void GetLangIndex(U8 * pCount, S32 * pnFontIndex, S32 * pnIndex, U32 nCh, U32 * pnBase)
{
    /* first check the index in the current language. 90% of the cases strings will be from current language */
    U16 nFontCount;
    sFontFamily *pFontFamily;
    U16 nFontAttrib = gnCurrentFontAttrib;

    *pCount = 0;

    while (*pCount < gMaxDeployedLangs)
    {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
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
        ++(*pCount);

    }   /* while(*pCount < gMaxDeployedLangs) */



    if (*pnIndex == -1)
    {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
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
S32 SearchIndexinList(U8 nListIndex, U16 nFontCount, U32 nCh, U32 *pnBase)
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
    U32 *pRange =
        gLanguageArray[nListIndex].fontfamilyList[gLanguageArray[nListIndex].nCurrentFamily]->fontData[nFontCount]->
        pRange;
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
S32 SearchInPropFont(U32 nCh, U32 *pnBase)
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
            return gMTKProprietaryFont.pRange[nMid];

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

/**************************************************************

   FUNCTION NAME     : Get_CharWidthHeight_internal()

   PURPOSE           : To get char widths

   INPUT PARAMETERS  : U32 Ch

   OUTPUT PARAMETERS : nil

   RETURNS           : S32

   REMARKS           : This is used to get char widths

**************************************************************/
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
 *  void
 *****************************************************************************/
void Get_CharWidthHeight_internal(U32 Ch, S32 *pdWidth, S32 *pWidth, S32 *pHeight, S32 *pAscent, S32 *pDescent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count = 0;
    S32 index = -1;
    U32 nBase;
    S32 nFontIndex = -1;
    sCustFontData *CurrentFont = gpCurrentFont;
    /* for font cache */
    U32 nHashKey = 0;
    CharHashTable *charHashTable;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_fe_test_display_as_space(Ch))
    {
        Ch = 0x20;
    }
    
    if (mmi_fe_test_display_as_null(Ch))
    {
        *pdWidth = 0;
        *pWidth = 0;
        *pHeight = 0;
        *pAscent = 0;
        *pDescent = 0;
        return;
    }
    
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
    if (charHashTable[nHashKey].unicode == Ch && charHashTable[nHashKey].gnCurrentFont == gnCurrentFont)
    {
        *pWidth = charHashTable[nHashKey].Width;
        *pdWidth = charHashTable[nHashKey].DWidth;
        *pHeight = charHashTable[nHashKey].Height;
        *pAscent = charHashTable[nHashKey].Ascent;
        *pDescent = charHashTable[nHashKey].Descent;


        if (!(gnCurrentFontAttrib & FONTATTRIB_BOLD &&
             gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_BOLD) ||
            !(gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_NORMAL))
        {
            
        }
        else
        {
            *pdWidth = *pdWidth + 1;
            *pWidth = *pWidth +1;    
        }
        return;
    }
    /* for font cache */

    GetLangIndex(&count, &nFontIndex, &index, Ch, &nBase);

    if (index > -1)
    {
    #ifdef __MMI_INDIC_ALG__
        if (count >= gMaxDeployedLangs)
        {
            *pdWidth = 0;
            *pWidth = 0;
            *pHeight = 0;
            *pAscent = 0;
            *pDescent = 0;
            gpCurrentFont = CurrentFont;
            return;
        }
    #endif /* __MMI_INDIC_ALG__ */ 
        SetFontValues(nFontIndex, count);
        *pHeight = gpCurrentFont->nHeight;
        *pAscent = gpCurrentFont -> nAscent;
        *pDescent = gpCurrentFont -> nDescent;

        if (gpCurrentFont->nEquiDistant)
        {
            *pWidth = gpCurrentFont->nWidth;
        }
        else
        {
            *pWidth = gpCurrentFont->pWidthArray[index + (Ch - nBase)];
        }

        /* by default, set dwidth as width and then modify it if there is dwidth array. */
        *pdWidth = *pWidth;       
    #ifdef __MMI_INDIC_ALG__
        if (IRE_INDIC_CHARACTER_UCS2_RANGE(Ch))
        {
            if (gpCurrentFont->pDWidthArray)
            {
                *pdWidth = gpCurrentFont->pDWidthArray[index + (Ch - nBase)];
            }
        }
    #endif /* __MMI_INDIC_ALG__ */ 

    }
    else
    {
        Get_PropWidthHeight(Ch, pdWidth, pWidth, pHeight, pAscent, pDescent);
    }
    gpCurrentFont = CurrentFont;
    if (!(gnCurrentFontAttrib & FONTATTRIB_BOLD &&
         gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_BOLD) ||
        !(gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_NORMAL))
    {
        
    }
    else
    {
            *pdWidth = *pdWidth + 1;
            *pWidth = *pWidth + 1;  
    }
    return;

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
static S32 mmi_font_engine_get_baseline_internal(U8 *st, S32 len, stFontAttribute Font, S32 *LineHeight)
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
 *  mmi_fe_check_string
 * DESCRIPTION
 *  To check the input string if the first len character is supported in current font configuration
 * PARAMETERS
 *  font                   [IN]        
 *  string                 [IN] the desired string
 *  len                     [IN] the first len character should be checked.
 * RETURNS
 *  MMI_BOOL           the validness of the string
 *****************************************************************************/
MMI_BOOL mmi_fe_check_string(stFontAttribute font, U8* string, S32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 Ch;
    U8 *pCharData;
    U16 nWidth, nDWidth, nHeight, dataWidth, dataHeight, ascent, descent;
    MMI_BOOL valid;    
    S32 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < len; index ++)
    {
        Ch = string[0] | (string[1] << 8);
        string+=2;
        GetFontdata(Ch, font, &pCharData, &nWidth, &nDWidth, &nHeight, &dataWidth, &dataHeight, &ascent, &descent, &valid);
        if (!valid)
            return MMI_FALSE;
    }
    return MMI_TRUE;
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
static mmi_fe_lang_id mmi_fe_get_lang_id(U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_INDIC_ALG__)
    if (IRE_INDIC_CHARACTER_UCS2_RANGE(ch))
    {
        return MMI_FE_LANG_INDIC;
    }
#endif

#if defined(__MMI_LANG_THAI__)
    if (ch >= 0x0E01 && ch <= 0x0E7F)
    {
        return MMI_FE_LANG_THAI;
    }
#endif

#if defined(__MMI_ARSHAPING_ENGINE__)
    if (IS_ARABIC_CHARACTER(ch))
    {
        return MMI_FE_LANG_ARABIC;
    }    
#endif

    return MMI_FE_LANG_OTHERS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_string
 * DESCRIPTION
 *  To display string in the screen
 * PARAMETERS
 *  param                   [IN]        
 * RETURNS
 *  UNIT32
 *****************************************************************************/
U32 mmi_fe_show_string(mmi_fe_showstring_info_struct_p param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_showstring_param_struct param_in = {0};
	U32 ret;
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
            param->Font, 
            param->BackGround, 
            0, 
            param->Bordered);
    }
    else
    {
        param_in.x = param->x;
        param_in.y = param->y;
		param_in.String = param->String;
        param_in.BackGround = param->BackGround;
        param_in.assign_direction = param->assign_direction;
        param_in.BaseLineHeight = param->BaseLineHeight;
        param_in.char_gap = param->char_gap;
        param_in.len = param->len;
        param_in.enable_truncated = MMI_FALSE;
        param_in.truncated_symbol = NULL;
        param_in.visible_x_start = -1;
        param_in.visible_x_end = -1;
        param_in.LineHeight = 0;
        param_in.Font = param->Font;
        param_in.Bordered = param->Bordered;
        param_in.render_flag = param->render_flag;
        ret = mmi_fe_show_string_ext(&param_in);
    }
	return ret;
}

#if defined(__MMI_LANG_THAI__)
/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_thai_string
 * DESCRIPTION
 *  To display Thai string in the screen
 * PARAMETERS
 *  param                   [IN]        
 * RETURNS
 *  UNIT32
 *****************************************************************************/
static U32 mmi_fe_show_thai_string(mmi_fe_showstring_param_struct_p param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;    
    U16 curCh = 0, preCh = 0, pre2Ch = 0;
    S32 curX = param->x, curY = param->y;
    S32 width = 0, height = 0, dwidth = 0, ascent = 0, descent = 0;
    S32 Len = 0;
    U8 *String = param->String;
    S32 string_width = 0;
    MMI_BOOL cursorMove = MMI_TRUE;
    stFontAttribute Font;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Len = param->len;
    if (Len < 0)
    {
        Len = mmi_ucs2strlen((const char *)String);
    }
    if (param->LineHeight > 0)
    {
        curY += param->LineHeightDiff;
    }
    memcpy(&Font, &(param->Font), sizeof(stFontAttribute));
    Font.underline = 0;


    while (index < Len)
    {
        if ((String[0] == '\0') && (String[1] == '\0'))
            break;

        curCh = String[0];
        curCh |= (String[1] << 8);
        String+=2;
        index ++;

        //Get_CharWidthHeight(curCh, &width, &height);
        Get_CharWidthHeight_internal(curCh, &dwidth, &width, &height, &ascent, &descent);

        cursorMove = RequireToMoveCursor(preCh, curCh);
        if (param->enable_truncated)
        {
            if (r2lMMIFlag)
            {
                if (curX < param->visible_x_start)
                {
                    goto Next_char;
                }
                else
                {
                    param->enable_truncated = MMI_FALSE;
                    param->truncated_symbol_start = curX;
                }
            }
            else
            {
                if (cursorMove)
                {
                    if (curX + width > param->visible_x_end)
                    {
                        param->enable_truncated = MMI_FALSE;
                        param->truncated_symbol_start = curX;                    
                        break;
                    }

                }
            }
        }
        curX = ShowStackedChar(curX, curY, Font, param->BackGround, curCh, param->BaseLineHeight, param->Bordered, pre2Ch, preCh);

    Next_char:
        if (cursorMove)
        {
            curX += width;
            string_width += width;
        }
        pre2Ch = preCh;
        preCh = curCh;
    }

    if (param->Font.underline)
    {
        if (param->Font.italic)
        {
            gdi_draw_line(param->x, param->y + height, param->x + string_width + 1, param->y + height, param->text_color);
        }
        else
        {
            gdi_draw_line(param->x, param->y + height, param->x + string_width, param->y + height, param->text_color);        
        }
    }
    return string_width;
}

#endif /* defined(__MMI_LANG_THAI__) */


#if defined(__MMI_LANG_ARMENIAN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_fe_armenian_cluster
 * DESCRIPTION
 *  To check armenain cluster
 * PARAMETERS
 *  curCh                   [IN]        
 *  nextCh
 * RETURNS
 *  U16                     0: no cluster comes others: cluster comes 
 *****************************************************************************/
U16 mmi_fe_armenian_get_cluster(U16 curCh, U16 nextCh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((curCh == 0x0574 ) || (curCh == 0x057e))
    {
        if (curCh == 0x0574)
        {
            if (nextCh == 0x0576)
            {
                ret = 0xfb13;
            }
            else if (nextCh == 0x0565)
            {
                ret = 0xfb14;
            }            
            else if (nextCh == 0x056B)
            {
                ret = 0xfb15;
            }
            else if (nextCh == 0x056D)
            {
                ret = 0xfb17;
            }
        }
        else if (nextCh == 0x0576)
        {
            ret= 0xfb16;
        }
    }
    return ret;
}

#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_other_string
 * DESCRIPTION
 *  To display Thai string in the screen
 * PARAMETERS
 *  param                   [IN]        
 * RETURNS
 *  UNIT32
 *****************************************************************************/
static U32 mmi_fe_show_other_string(mmi_fe_showstring_param_struct_p param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;    
    U16 curCh = 0, preCh = 0, pre2Ch = 0, next_ch = 0, tone_mark = 0, viet_vowel = 0;
    S32 curX = param->x, curY = param->y;
    S32 y_offset = 0;
    //S32 width = 0, height = 0;
    S32 check_len = 0;
    S32 Len = 0;
    U8 *String = param->String;
    S32 string_width = 0;
    gdi_color border_color = 0, text_color;
    U8 font_attr = 0;
    U8 *CharData;
    U32 NumChar;
    /* nHgt, nWidth is the height and width of character and 
        dataHgt, dataWidth is the data height and width */    
    U16 nHgt = 0;
    U16 nWidth = 0, nDWidth = 0;
    U16 dtWidth = 0;
    U16 dtHgt = 0;
    U16 ascent = 0;
    U16 descent = 0;
    S32 baseline = param->BaseLineHeight;
    MMI_BOOL bordered = param->Bordered;
    S32 clip_x1 = 0, clip_x2 = 0, clip_y1 = 0, clip_y2 = 0;
    MMI_BOOL valid;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  
    border_color = param->border_color;
    text_color = param->text_color;
    font_attr = param->font_attr;

    Len = param->len;
    if (Len < 0)
    {
        Len = mmi_ucs2strlen((const char *)String);
    }
    if (param->LineHeight > 0)
    {
        curY += param->LineHeightDiff;
    }
   	gdi_layer_get_clip(&clip_x1, &clip_y1, &clip_x2, &clip_y2);

    while (index < Len)
    {
        if ((String[0] == '\0') && (String[1] == '\0'))
            break;
        check_len--;
        if ((curX > clip_x2 + 1) && !r2lMMIFlag)
			return string_width;

        curCh = String[0];
        curCh |= (String[1] << 8);
        String += 2;
        index++;
        
#if defined(__MMI_LANG_VIETNAMESE__)
        if ((curCh > 0x0040) && (curCh < 0x01B1))
        {
            next_ch = String[0];
            next_ch |= (String[1] << 8);
            tone_mark = mmi_viet_tone_mark(next_ch);
            if (VIET_TONE_NONE != tone_mark)
            {
                viet_vowel = mmi_viet_vowel_letter(curCh);
                if (VIET_VOWEL_NONE != viet_vowel)
                {
                    curCh = mmi_viet_combine_vowel_tone(viet_vowel, tone_mark);
                    String += 2;
                    index++;
                }
            }
        }
#endif /* defined(__MMI_LANG_VIETNAMESE__) */ 
#if defined(__MMI_LANG_ARMENIAN__)
        if (((curCh == 0x0574 ) || (curCh == 0x057e)) && (index < Len))
        {
            U16 cluster = 0;
            next_ch = String[0];
            next_ch |= (String[1] << 8);
            cluster = mmi_fe_armenian_get_cluster(curCh, next_ch);
            if (cluster)
            {
                curCh = cluster;
                String += 2;
                index++;                
            }
        }
#endif
        if (mmi_fe_test_display_as_space(curCh))
        {
            curCh = 0x20;
        }
        if (mmi_fe_test_display_as_null((U32)curCh))
        {
            nWidth = 0;
            goto Next_char;
        }
        
        NumChar = GetFontdata(curCh, param->Font, &CharData, &nWidth, &nDWidth, &nHgt, &dtWidth, &dtHgt, &ascent, &descent, &valid);
    
        //Get_CharWidthHeight(curCh, &width, &height);

        if (param->enable_truncated)
        {
            if (r2lMMIFlag)
            {
                if (curX < param->visible_x_start)
                {
                    goto Next_char;
                }
                else
                {
                    param->enable_truncated = MMI_FALSE;
                    param->truncated_symbol_start = curX;
                }
            }
            else
            {
                if (curX + nWidth > param->visible_x_end)
                {
                    param->enable_truncated = MMI_FALSE;
                    param->truncated_symbol_start = curX;                    
                    break;
                }
                
            }
        }

        y_offset = curY + (baseline - ascent);
        if (bordered)
        {
            gdi_show_char_bordered(
                curX,
                y_offset,
                text_color,
                border_color,
                CharData,
                NumChar,
                dtWidth,
                nHgt,
                font_attr);
        }
        else if (!
                 (gnCurrentFontAttrib & FONTATTRIB_BOLD &&
                  gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_BOLD) ||
                 !(gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_NORMAL))
        {
            gdi_show_char(curX, y_offset, text_color, CharData, NumChar, dtWidth, nHgt, font_attr);
        }
        else
        {
            gdi_show_char(curX + 1, y_offset, text_color, CharData, NumChar, dtWidth, nHgt, font_attr);
            gdi_show_char(curX, y_offset, text_color, CharData, NumChar, dtWidth, nHgt, font_attr);
        }

    Next_char:
        string_width += nWidth;
        curX += nWidth;
        pre2Ch = preCh;
        preCh = curCh;
    }
    UI_UNUSED_PARAMETER(viet_vowel);
    UI_UNUSED_PARAMETER(tone_mark);
    UI_UNUSED_PARAMETER(next_ch);

    return string_width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_string_by_lang
 * DESCRIPTION
 *  To dispatch the show string function by lanuage
 * PARAMETERS
 *  param                   [IN]        
 * RETURNS
 *  UNIT32
 *****************************************************************************/
static U32 mmi_fe_show_string_by_lang(mmi_fe_showstring_param_struct_p param, mmi_fe_lang_id langid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_INDIC_ALG__)
    if (langid == MMI_FE_LANG_INDIC)
    {
        return mmi_fe_show_indic_string(param);
    }
#endif
    
#if defined(__MMI_LANG_THAI__)
    if (langid == MMI_FE_LANG_THAI)
    {
        return mmi_fe_show_thai_string(param);
    }
#endif
    
    return mmi_fe_show_other_string(param);
    

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_string_ext
 * DESCRIPTION
 *  To display a string in the screen
 * PARAMETERS
 *  param                   [IN]        
 * RETURNS
 *  UNIT32
 *****************************************************************************/
static U32 mmi_fe_show_string_ext(mmi_fe_showstring_param_struct_p param)
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
    PMT_BIDI_TYPES assign_direction = param->assign_direction;
    S32 check_len = 0;
    U8 *temp_string = param->String;
    U16 unicode = 0;
    U8 *String = param->String;
    U16 visual_str_len = 0, visual_cur_pos = 0;
    BIDI_PARAGRAPH_TYPES paratype = P_RTL;
    S32 lang_string_group = 0;
    mmi_fe_lang_id curLangid = MMI_FE_LANG_NONE, preLangid = MMI_FE_LANG_NONE;
    U8 *lang_string_start = NULL;
    mmi_fe_showstring_param_struct string_part_param;
    S32 x_offset = 0;
    S32 totalLineHeight = 0;
    gdi_color border_color = 0, text_color;
    U8 font_attr = 0;
    S32 clip_x1 = 0, clip_x2 = 0, clip_y1 = 0, clip_y2 = 0;
    U32 render_flag = param->render_flag;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
    mmi_trace_screen_string(param->x, param->y, String, len, param->Bordered);
#endif
    if (param->Bordered && 
        UI_text_border_color.r == TRANSPARENT_COLOR_R && 
        UI_text_border_color.g == TRANSPARENT_COLOR_G && 
        UI_text_border_color.b == TRANSPARENT_COLOR_B)
    {
        param->Bordered = 0;
    }

    if (param->Bordered)
    {
        border_color =
            gdi_act_color_from_rgb(0xff, UI_text_border_color.r, UI_text_border_color.g, UI_text_border_color.b);
    }

    text_color =
        gdi_act_color_from_rgb(0xff, UI_current_text_color.r, UI_current_text_color.g, UI_current_text_color.b);
    
    if (gnCurrentFontAttrib & FONTATTRIB_ITALIC)
        font_attr |= FONTATTRIB_ITALIC;
    else if (gnCurrentFontAttrib & FONTATTRIB_OBLIQUE)
        font_attr |= FONTATTRIB_OBLIQUE;

    if (param->Font.underline)
        font_attr |= FONTATTRIB_UNDERLINE;
    gdi_layer_get_clip(&clip_x1, &clip_y1, &clip_x2, &clip_y2);

    /* initialize */
    param->LineHeightDiff = 0;
    param->font_attr = font_attr;
    param->text_color = text_color;
    param->border_color = border_color;
    string_part_param.LineHeightDiff = 0;

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
    if (r2lMMIFlag && !cancelWidth /*|| param->BaseLineHeight == -1*/)
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
        if (param->LineHeight > 0)
        {
            param->LineHeightDiff = param->LineHeight - query.pHeight;
        }
    }

    
    memcpy(&string_part_param, param, sizeof(mmi_fe_showstring_param_struct));

    /* the data passed from editor has been processed by BIDI and shaping. Hence, go to process. */
    if (cancelWidth)
       goto  MMI_FE_SHOW_STRING;
    
#if defined(__MMI_BIDI_ALG__)
    check_len = len;
    while (check_len != 0)
    {
        U8 dic = 0;
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

        if (dic == BIDI_R || dic == AL || dic == AN)
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
    unicode = 0;

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
    if (IS_BIDI || assign_direction == BIDI_R)
    {
        if (assign_direction == BIDI_R)
        {
            paratype = P_RTL;
        }
        else
        {
            paratype = P_LTR;
        }
        bidi_main_ext(
            String, 
            len, 
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
        if (param->BaseLineHeight == -1 || string_part_param.LineHeight > 0)
        {
			S32 baseline = mmi_font_engine_get_baseline_internal(String, len, param->Font, &totalLineHeight);
			if (string_part_param.BaseLineHeight == -1)
			{
				string_part_param.BaseLineHeight = baseline;
			}
			if (string_part_param.LineHeight > 0)
			{
				string_part_param.LineHeightDiff = string_part_param.LineHeight - totalLineHeight;        
			}    
        }
    }
    
    lang_string_start = String;
    lang_string_group = 0;
    gdi_font_begin(text_color, font_attr);

    while (len > 0)
    {
        if ((String[0] == '\0') && (String[1] == '\0'))
            break;
        len--;
        if ((curX >  clip_x2 + 1) && !r2lMMIFlag)
        {
            lang_string_group = 0;
			break;
        }
        unicode = String[0];
        unicode |= (String[1] << 8);

        preLangid = curLangid;
        curLangid = mmi_fe_get_lang_id(unicode);
        if((unicode == ZWNJ ) ||(unicode == ZWJ))
        {
            curLangid = preLangid;
        }
        if (preLangid == curLangid || preLangid == MMI_FE_LANG_NONE)
        {
            lang_string_group ++;
        }
        else
        {
            /* show string by language */
            string_part_param.String = lang_string_start;
            string_part_param.len = lang_string_group;


            string_part_param.x = curX;
            x_offset = mmi_fe_show_string_by_lang(&string_part_param, preLangid);

            if (param->enable_truncated && !string_part_param.enable_truncated)
            {
                param->truncated_symbol_start = string_part_param.truncated_symbol_start;
                param->enable_truncated = MMI_FALSE;
                if (!r2lMMIFlag)
                {
                    lang_string_group = 0;
			        break;
                }
            }
            
            curX+= x_offset;
            if (((preLangid == MMI_FE_LANG_ARABIC && curLangid != MMI_FE_LANG_ARABIC) ||
                (preLangid != MMI_FE_LANG_ARABIC && curLangid == MMI_FE_LANG_ARABIC)) &&
                !render_flag)
            {
                curX ++;
            }
            lang_string_start = String;
            lang_string_group = 1;
        }
        String += 2;

    }
    if ((curX >  clip_x2 + 1) && !r2lMMIFlag)
    {
        lang_string_group = 0;
    }

    if (lang_string_group)
    {
        string_part_param.String = lang_string_start;
        string_part_param.len = lang_string_group;
        string_part_param.x = curX;
        mmi_fe_show_string_by_lang(&string_part_param, curLangid);
        if (param->enable_truncated && !string_part_param.enable_truncated)
        {
            param->truncated_symbol_start = string_part_param.truncated_symbol_start;
            param->enable_truncated = MMI_FALSE;
        }
    }
    UI_UNUSED_PARAMETER(paratype);
    UI_UNUSED_PARAMETER(visual_cur_pos);
    UI_UNUSED_PARAMETER(visual_str_len);
    UI_UNUSED_PARAMETER(temp_string);
    UI_UNUSED_PARAMETER(check_len);
    UI_UNUSED_PARAMETER(assign_direction);
    
    gdi_font_end();
    return 0;
}

#if defined(__MMI_INDIC_ALG__)
/*****************************************************************************
 * FUNCTION
 *  ShowString_Indic
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
static U32 mmi_fe_show_indic_string(mmi_fe_showstring_param_struct_p param)
{    

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 CurrentX = 0;
    /* the x width of string */
    S32 len = param->len;
    static MMI_BOOL IS_INDIC = MMI_FALSE;
    MMI_BOOL enableTruncated = MMI_FALSE;
    U8 *String = param->String;
    U16 glyph_output[100];
    U16 *glyph_output_ptr = glyph_output;
    S32 Len = 0;
    S32 glypout_strlen = 0;
    S32 width = 0;
    S32 CurX = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Error Check */
    if (len == 0)
    {
        return MMI_FONT_ENGINE_ZERO_LENGTH;
    }
    if (String == NULL)
        return MMI_FONT_ENGINE_ERROR_NULL_STRING;

    CurrentX = param->x;

    if (ire_is_reset_indic_params())
        ire_reset_indic_params();
    if (param->Font.color == 0)
        param->Font.color = 15;
    if (ire_is_indic_rules_parsing())
    {
        U16 cluster_fill[G_MAX];
        S32 cluster_length;
        S32 cluster_width = 0;
        S32 total_len = 0;
        S32 original_len = 0;
        mmi_fe_get_string_info_param_struct string_part_param_height_width;
        mmi_fe_showstring_param_struct string_part_param;

        memcpy(&string_part_param, param, sizeof(mmi_fe_showstring_param_struct));

    #if defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__)
        overwrite_current_language_for_hindi_rules_based_on_input_method();
    #endif 
        ire_init_cluster_start_p(String);
        if (len > 0)
        {
            ire_init_cluster_end_p(String + (len * 2));
        }
        else
        {
            ire_init_cluster_end_p(String + (2 * mmi_ucs2strlen((const char*)String) + 1));
        }
        original_len = len;
        /* This loop takes the string cluster by cluster and renders the string */
        do
        {
            if (total_len == original_len)
                break;

            cluster_length = ire_get_cluster(cluster_fill);
            total_len += cluster_length;
            if (original_len > 0)
            {
                if (total_len > original_len || total_len > len)
                    break;
            }
            if (cluster_length)
            {
                if (cluster_length > 1)
                {
                    Len = ire_language_rules(glyph_output_ptr, cluster_fill, ire_get_display_buffer_len());
                }
                else
                {
                    Len = 1;
                    glyph_output_ptr[0] = cluster_fill[0];
                    glyph_output_ptr[1] = 0;

                }
                /* Cluster shouldn't be truncated. Check the width */
                string_part_param_height_width.String = (U8*) glyph_output_ptr;
                string_part_param_height_width.n = Len;
                string_part_param_height_width.pWidth = 0;
                mmi_fe_get_string_widthheight_indic_internal(&string_part_param_height_width);
                cluster_width = string_part_param_height_width.pWidth;
                width += cluster_width;
                if (param->enable_truncated)
                {
                    if (r2lMMIFlag)
                    {
                        if ((CurrentX) < param->visible_x_start)
                        {
                            enableTruncated = 1;
                            CurrentX += cluster_width;
                            param->x = cluster_width;

                            /* skip the cluster because it is not in the visible region. */
                            continue;
                        }
                        else
                        {
                            S32 symbol_width = 0;
                            S32 symbol_height = 0;

                            Get_StringWidthHeight(param->truncated_symbol, &symbol_width, &symbol_height);
                            param->enable_truncated = MMI_FALSE;
                            if (param->Bordered)
                                symbol_width += 2;

                            if ((CurrentX - symbol_width) > param->visible_x_start)
                            {
                                param->truncated_symbol_start = CurrentX - symbol_width;
                                param->x = CurrentX - symbol_width;
                            }
                            else
                            {
                                param->x = CurrentX;
                                param->truncated_symbol_start = CurrentX;
                                CurrentX = param->visible_x_start;
                            }
                            string_part_param.enable_truncated = MMI_FALSE;
                        }
                    }
                    else
                    {
                        if (CurrentX + width > param->visible_x_end)
                        {
                            enableTruncated = 1;
                            width -= cluster_width;
                            param->enable_truncated = MMI_FALSE;
                            param->truncated_symbol_start = CurrentX;
                            break;
                        }

                    }
                }

                glyph_output_ptr += Len;
                glyph_output_ptr[0] = 0;
                glypout_strlen += Len;
              
            }
        } while (cluster_length);
        param->String = (U8*) & glyph_output;
        param->len = glypout_strlen;
        if (glypout_strlen)
        {
            CurX = mmi_fe_show_indic_string_internal(param);
        }
        if (enableTruncated)
        {
            if (r2lMMIFlag)
                {
                     return width;
                }
                else
                {
                param->truncated_symbol_start = param->x + width;
            }
        }
        IS_INDIC = MMI_FALSE;
        return width;

    }

    if (cancelWidth)
    {
        /* called by editor, the string is the Indic cluster, only display it */

        return mmi_fe_show_indic_string_internal(param);
    }
    return 0;
}


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
static U32 mmi_fe_show_indic_string_internal(mmi_fe_showstring_param_struct_p param)
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
    /* nHgt, nWidth is the height and width of character and 
        dataHgt, dataWidth is the data height and width */
    U16 nHgt;
    U16 nWidth;
    U16 dtHgt;
    U16 dtWidth;
    /* the x width of string */
    U32 string_width = 0;
    S32 y = param->y;    
    U16 nDWidth;
    S32 nXOffset;
    S32 nYOffset;
    S32 yy = 0;
    U16 unicode = 0;
    U8 font_attr = 0;
    gdi_color border_color = 0, text_color;
    S32 clip_x1, clip_y1, clip_x2, clip_y2;
    S32 len = param->len;
    U8 *String = param->String;
    U16 ascent = 0, descent = 0;
    MMI_BOOL bordered = param->Bordered;
    MMI_BOOL valid;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  
    border_color = param->border_color;
    text_color = param->text_color;
    font_attr = param->font_attr;

    /* Error Check */
    if (len == 0)
    {
        return MMI_FONT_ENGINE_ZERO_LENGTH;
    }
    if (String == NULL)
        return MMI_FONT_ENGINE_ERROR_NULL_STRING;

    if (param->Bordered && 
        UI_text_border_color.r == TRANSPARENT_COLOR_R && 
        UI_text_border_color.g == TRANSPARENT_COLOR_G && 
        UI_text_border_color.b == TRANSPARENT_COLOR_B)
    {
        param->Bordered = 0;
    }
    
    gdi_layer_get_clip(&clip_x1, &clip_y1, &clip_x2, &clip_y2);


    CurrentX = param->x;
    unicode = 0;
    
    while (len != 0)
    {
        U16 prev_unicode = 0;

    NEXT:
        if ((String[0] == '\0') && (String[1] == '\0'))
            break;
        len--;

        prev_unicode = unicode;
        unicode = String[0];
        unicode |= (String[1] << 8);

        if (mmi_fe_test_display_as_space(unicode))
        {
            unicode = 0x20;
	  }
        if (mmi_fe_test_display_as_null(unicode))
        {
            String += 2;
            if (len == 0) /* when the formatting character is the last character in the string */
                break;
            else
                goto NEXT;
        }
        
        NumChar = GetFontdata(unicode, param->Font, &CharData, &nWidth, &nDWidth, &nHgt, &dtWidth, &dtHgt, &ascent, &descent, &valid);
        Counter++;
    #ifdef __MMI_INDIC_ALG__
    
        if(!IRE_INDIC_CHARACTER_UCS2_RANGE(unicode))
    #endif
        {
            if (param->BaseLineHeight > 0)
               yy = y + param->BaseLineHeight - nHgt;
            else
            yy = y;
        }
    #ifdef __MMI_INDIC_ALG__
        else
        {
            yy = y;

        }
   #endif

    
        nXOffset = CurrentX + nWidth;
        nYOffset = yy + nHgt;
        ire_get_text_x(&CurrentX, unicode, yy, nDWidth, nWidth);


        if ((CurrentX > clip_x2 + 1) && !r2lMMIFlag)
            break;
        /* to check string width boundary when skiping first pass */
        string_width += nWidth;
        if (bordered)
        {
            gdi_layer_push_clip();
            /* For first character */
            if(Counter == 0)
            {
                gdi_layer_set_clip(CurrentX, yy, CurrentX + dtWidth, yy + dtHgt);

            }
            else
            {
                gdi_layer_set_clip(CurrentX + 1, yy, CurrentX + dtWidth, yy + dtHgt);
            }

            gdi_show_char_bordered(CurrentX, yy, text_color, border_color, CharData, NumChar, dtWidth, dtHgt, font_attr);
            gdi_layer_pop_clip();
        }
        else if (!
                 (gnCurrentFontAttrib & FONTATTRIB_BOLD &&
                  gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_BOLD) ||
                 !(gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_NORMAL))
        {
            gdi_show_char(CurrentX, yy, text_color, CharData, NumChar, dtWidth, dtHgt, font_attr);
        }
        else
        {
            gdi_show_char(CurrentX + 1, yy, text_color, CharData, NumChar, dtWidth, dtHgt, font_attr);
            gdi_show_char(CurrentX, yy, text_color, CharData, NumChar, dtWidth, dtHgt, font_attr);
        }
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
    U8 default_direction = 0;
    U16 strongCharType = 0xFFFF;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* error check */
    if (st == NULL) return MMI_FONT_ENGINE_ERROR_NULL_STRING;

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

    
    return MMI_FONT_ENGINE_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_string_width_by_fixed_char_width
 * DESCRIPTION
 *  To get string width by the fixed char width.
 *  the fixed char width is count by the max width of the character.
 *  And the string width is the max char width multiple the numofchar.
 *  The characte of Arabic series, Indic series, Thai and Vietnamese language is not allowed
 *  to be the input. 
 * PARAMETERS
 *  numofchar [IN]  the number of character of the string
 *  st            [IN]  all the character would be displayed as a char in the string. 
 * RETURNS
 *  S32
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
    for (i = 0 ; i < len * 2; i += 2)
    {
        unicode = st[i];
        unicode |= (st[i + 1] << 8);
        Get_CharWidthHeight_internal(unicode, &dwidth, &w, &h, &ascent, &descent);
        max_w = (w > max_w) ? w : max_w;
        max_ascent = (ascent > max_ascent) ? ascent : max_ascent;
        max_descent = (descent > max_descent) ? descent : max_descent;
        
    }

    *width = (max_w * numofchar);
    *height = (max_ascent + max_descent);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_font_engine_show_truncated_text
 * DESCRIPTION
 *  Print truncated text
 *  
 *  If length of text is greater  than screen width then the text is truncated. 
 *  The assign truncated symbol are shown at end of text
 * PARAMETERS
 *  x                       [IN]        Start x positoin
 *  y                       [IN]        Start Y position
 *  xwidth                  [IN]        Width of text in pixels to display
 *  st                      [IN]        Text to display
 *  truncated_symbol        [IN]        The truncated symbol, it would be show at the end of text if truncation is necessary
 *  Font                    [IN]        Font attribute
 *  BackGround              [IN]        
 *  LineHeight              [IN]        
 *  bordered                [IN]        
 *  border(?)               [IN]        
 *  Background(?)           [IN]        Background color
 * RETURNS
 *  S32                         [OUT]   for checking if the string has been truncated
 *****************************************************************************/
mmi_font_engine_error_message_enum mmi_font_engine_show_truncated_text(S32 x, S32 y,S32 xwidth, U8 *st, U8 *truncated_symbol, stFontAttribute Font,U8 BackGround,U32 LineHeight, MMI_BOOL bordered )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 new_xwidth; /* the new width after subtract truncated_symbol width from original width*/
    S32 symbol_width; /* the width of turncated symbol string */
    S32 symbol_height; /* the width of truncated symbol string */
    U8 default_direction = 0;
    mmi_fe_showstring_param_struct param = {0};    
    S32 baseline = 0;
    mmi_fe_get_string_info_param_struct query;
    S32 len = mmi_ucs2strlen((S8*)st);
    S32 max_line_height = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* for error check */
    if (st == NULL) return MMI_FONT_ENGINE_ERROR_NULL_STRING;

    mmi_fe_get_display_direction(st, &default_direction, len);
    
    /* for check if truncation is necessary */
    memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
    query.String = st;
    query.enableTruncated = MMI_FALSE;
    query.w = 0;
    query.n = len;
    mmi_fe_get_string_widthheight(&query);
    
    baseline = query.baseline;

    if (bordered && 
        UI_text_border_color.r == TRANSPARENT_COLOR_R && 
        UI_text_border_color.g == TRANSPARENT_COLOR_G && 
        UI_text_border_color.b == TRANSPARENT_COLOR_B)
    {
        bordered = MMI_FALSE;
    }

    param.x = x;
    param.y = y;
    param.Font = Font;
    param.BackGround = BackGround;
    param.String = st;
    param.BaseLineHeight = query.baseline;
    param.Bordered = bordered;
    param.len = -1;
    param.assign_direction = default_direction;
    param.char_gap = 0;
    param.LineHeight = (S32)LineHeight;

    if (query.pWidth <= xwidth)
    {
        param.enable_truncated = MMI_FALSE;
        param.truncated_symbol = NULL;
        param.visible_x_start = -1;
        param.visible_x_end = -1;
        if (bordered)
        {
            ShowStringBordered_baseline(x, y, Font, BackGround, st, baseline, default_direction, LineHeight);
        }
        else
        {
            ShowString_baseline(x, y, Font, BackGround, st, baseline, default_direction, LineHeight);
        }
        return MMI_FONT_ENGINE_NO_TRUNCATION;
    }
    
    Get_StringWidthHeight(truncated_symbol, &symbol_width, &symbol_height);
    if (bordered)
    {
        symbol_width += 2;
    }

    new_xwidth = xwidth - symbol_width;
    if (new_xwidth < 0)
        return MMI_FONT_ENGINE_ERROR_NO_TRUNCATION_AVAILABLE;
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
    max_line_height = (query.pHeight > symbol_height)? query.pHeight: symbol_height;
    if (LineHeight > 0)
    {
        param.y = y + (LineHeight - max_line_height);
        param.LineHeight = 0;
    }
    else
    {
        param.y = y;
        param.LineHeight = LineHeight;
    }

    mmi_fe_show_string_ext(&param);    

    /* display truncated symbol */
    param.enable_truncated = MMI_FALSE;
    param.String = truncated_symbol;
    param.x = param.truncated_symbol_start;
    if (LineHeight > 0)
    {
        param.y = y + (LineHeight - max_line_height);
        param.LineHeight = 0;
    }
    else
    {
        param.y = y;
        param.LineHeight = LineHeight;
    }
    param.BaseLineHeight = baseline;
    if (r2lMMIFlag)
        param.x --;
    mmi_fe_show_string_ext(&param);    

    return MMI_FONT_ENGINE_TRUNCATION;

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
U32 ShowString_n(
        U32 x_unsigned,
        U32 y_unsigned,
        stFontAttribute Font,
        U8 BackGround,
        U8 *String,
        int Len,
        U32 LineHeight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 default_direction = 0;
    mmi_fe_showstring_param_struct param = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fe_get_display_direction(String, &default_direction, Len);

    param.x = x_unsigned;
    param.y = y_unsigned;
    param.Font = Font;
    param.BackGround = BackGround;
    param.String = String;
    param.BaseLineHeight = -1;
    param.Bordered = MMI_FALSE;
    param.len = Len;
    param.enable_truncated = MMI_FALSE;
    param.truncated_symbol = NULL;
    param.visible_x_start = -1;
    param.visible_x_end = -1;
    param.assign_direction = default_direction;
    param.char_gap = 0;
    param.LineHeight = (S32)LineHeight;

    return mmi_fe_show_string_ext(&param);    

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
U32 ShowString_n_baseline(
        U32 x_unsigned,
        U32 y_unsigned,
        stFontAttribute Font,
        U8 BackGround,
        U8 *String,
        S32 Len,
        S32 baseline)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_showstring_param_struct param = {0};
    U8 default_direction = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fe_get_display_direction(String, &default_direction, Len);
    param.x = x_unsigned;
    param.y = y_unsigned;
    param.Font = Font;
    param.BackGround = BackGround;
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
    param.LineHeight = 0;

    return mmi_fe_show_string_ext(&param);    
    
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
U32 ShowString_baseline(S32 x, S32 y, stFontAttribute Font, U8 BackGround, U8 *String, S32 baseline, U8 default_direction, U32 LineHeight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nLen = 0;
    mmi_fe_showstring_param_struct param = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nLen = mmi_ucs2strlen((const char*)String);  
    param.x = x;
    param.y = y;
    param.Font = Font;
    param.BackGround = BackGround;
    param.String = String;
    param.BaseLineHeight = baseline;
    param.Bordered = MMI_FALSE;
    param.len = nLen;
    param.enable_truncated = MMI_FALSE;
    param.truncated_symbol = NULL;
    param.visible_x_start = -1;
    param.visible_x_end = -1;
    param.assign_direction = default_direction;
    param.char_gap = 0;
    param.LineHeight = (S32)LineHeight;

    return mmi_fe_show_string_ext(&param);    
    
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
U32 ShowString(S32 x, S32 y, stFontAttribute Font, U8 BackGround, U8 *String, U32 LineHeight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_showstring_param_struct param = {0};
    S32 nLen = 0;
    U8 default_direction = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nLen = mmi_ucs2strlen((const char*)String);
    mmi_fe_get_display_direction(String, &default_direction, nLen);
    
    param.x = x;
    param.y = y;
    param.Font = Font;
    param.BackGround = BackGround;
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
    param.LineHeight = (S32)LineHeight;

    return mmi_fe_show_string_ext(&param);    
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
U32 ShowStringBordered_baseline(S32 x, S32 y, stFontAttribute Font, U8 BackGround, U8 *String, S32 baseline, U8 default_direction, U32 LineHeight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nLen = 0;
    mmi_fe_showstring_param_struct param = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nLen = mmi_ucs2strlen((const char*)String);  
    param.x = x;
    param.y = y;
    param.Font = Font;
    param.BackGround = BackGround;
    param.String = String;
    param.BaseLineHeight = baseline;
    param.Bordered = MMI_TRUE;
    param.len = nLen;
    param.enable_truncated = MMI_FALSE;
    param.truncated_symbol = NULL;
    param.visible_x_start = -1;
    param.visible_x_end = -1;
    param.assign_direction = default_direction;
    param.char_gap = 0;
    param.LineHeight = (S32)LineHeight;
    return mmi_fe_show_string_ext(&param);    
    
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
U32 ShowString_by_direction(S32 x, S32 y, stFontAttribute Font, U8 BackGround, U8 *String, U32 LineHeight, U8 default_direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nLen = 0;
    mmi_fe_showstring_param_struct param = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nLen = mmi_ucs2strlen((const char*)String);  

    param.x = x;
    param.y = y;
    param.Font = Font;
    param.BackGround = BackGround;
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
    param.LineHeight = (S32)LineHeight;

    return mmi_fe_show_string_ext(&param);    

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
U32 ShowStringBordered(S32 x, S32 y, stFontAttribute Font, U8 BackGround, U8 *String, U32 LineHeight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nLen = 0;
    U8 default_direction = 0;
    mmi_fe_showstring_param_struct param = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nLen = mmi_ucs2strlen((const char*)String);
    mmi_fe_get_display_direction(String, &default_direction, nLen);
    
    param.x = x;
    param.y = y;
    param.Font = Font;
    param.BackGround = BackGround;
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
    param.LineHeight = (S32)LineHeight;

    return mmi_fe_show_string_ext(&param);    
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
U32 ShowStringBordered_n(
        U32 x_unsigned,
        U32 y_unsigned,
        stFontAttribute Font,
        U8 BackGround,
        U8 *String,
        int Len,
        U32 LineHeight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 default_direction = 0;
    mmi_fe_showstring_param_struct param = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fe_get_display_direction(String, &default_direction, Len);
    
    param.x = x_unsigned;
    param.y = y_unsigned;
    param.Font = Font;
    param.BackGround = BackGround;
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
    param.LineHeight = (S32)LineHeight;
    return mmi_fe_show_string_ext(&param);    

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
U32 ShowStringBordered_by_direction(S32 x, S32 y, stFontAttribute Font, U8 BackGround, U8 *String, U32 LineHeight, U8 default_direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nLen = 0;
    mmi_fe_showstring_param_struct param = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nLen = mmi_ucs2strlen((const char*)String);

    param.x = x;
    param.y = y;
    param.Font = Font;
    param.BackGround = BackGround;
    param.String = String;
    param.BaseLineHeight = -1;
    param.Bordered = MMI_TRUE;
    param.len = nLen;
    param.enable_truncated = MMI_FALSE;
    param.truncated_symbol = NULL;
    param.visible_x_start = -1;
    param.visible_x_end = -1;
    param.assign_direction = default_direction;
    param.LineHeight = (S32)LineHeight;
    param.char_gap = 0;

    return mmi_fe_show_string_ext(&param);    
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
    Get_CharWidthHeight_internal(Ch, &dwidth, pWidth, &Height, &Ascent, &Descent);
}


/*****************************************************************************
 * FUNCTION
 *  Get_CharNumInWidth
 * DESCRIPTION
 *  To get char number in specified width
 *  
 *  This is used to get char number in specified width
 * PARAMETERS
 *  String              [IN]        
 *  width               [IN]        
 *  checklinebreak      [IN]        
 *  number(?)           [OUT]       Of characters
 * RETURNS
 *  void
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
 *  Get_CharNumInWidth
 * DESCRIPTION
 *  To get char number in specified width
 *  
 *  This is used to get char number in specified width
 * PARAMETERS
 *  String              [IN]        
 *  width               [IN]        
 *  checklinebreak      [IN]        
 *  number(?)           [OUT]       Of characters
 * RETURNS
 *  void
 *****************************************************************************/
U32 Get_CharNumInWidth_w(U8 *String, U32 width, U8 checklinebreak, U32 gap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return Get_CharNumInWidth_internal(String, width, checklinebreak, gap);
}

/*****************************************************************************
 * FUNCTION
 *  Get_CharNumInWidth
 * DESCRIPTION
 *  To get char number in specified width
 *  
 *  This is used to get char number in specified width
 * PARAMETERS
 *  String              [IN]        
 *  width               [IN]        
 *  checklinebreak      [IN]        
 *  number(?)           [OUT]       Of characters
 * RETURNS
 *  void
 *****************************************************************************/
U32 Get_CharNumInWidth(U8 *String, U32 width, U8 checklinebreak)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return Get_CharNumInWidth_internal(String, width, checklinebreak, 1);

}

/**************************************************************

   FUNCTION NAME     : Get_CharWidthHeight()

   PURPOSE           : To get char widths

   INPUT PARAMETERS  : U32 Ch

   OUTPUT PARAMETERS : nil

   RETURNS           : S32

   REMARKS           : This is used to get char widths

**************************************************************/
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
    //FE_LOCK;
    Get_CharWidthHeight_internal(Ch, pDwidth, pWidth, pHeight, Ascent, Descent);
    //FE_UNLOCK;
    GDI_UNLOCK;
}
#endif
/* Vogins End */
/**************************************************************

   FUNCTION NAME     : Get_CharBoundingBox()

   PURPOSE           : To get the bounding box of "drawn area" of a character

   INPUT PARAMETERS  : U32 Ch

   OUTPUT PARAMETERS : pCharWidth - width of character
                     pCharHeight    - height of character
                     pBoxXoffset    - X offset of the bounding box of drawn area relative to the top-left corner
                     pBoxYoffset    - Y offset of the bounding box of drawn area  relative to the top-left corner
                     pBoxWidth      - width of the bounding box of drawn area 
                     pBoxHeight     - height of the bounding box of drawn area 

   RETURNS           : void

   REMARKS           : 
                     1. It does not handle Hindi properly.
                     2. The function is slow because it process internal font data.
                     3. This function can be used to align a character in a better way because the "drawn area" is aligned
                       differently for different font database.
**************************************************************/
void Get_CharBoundingBox(U32 Ch, S32 * pCharWidth, S32 * pCharHeight, S32 * pBoxXoffset, S32 * pBoxYoffset,
                         S32 * pBoxWidth, S32 * pBoxHeight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *font_data;
    U32 font_data_size;
    U16 char_height;
    U16 char_width;
    U16 data_height;
    U16 data_width;
    U16 char_d_width = 0;
    S32 fx1, fy1, fx2, fy2, x, y;
    U16 ascent = 0, descent = 0;
    MMI_BOOL valid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    font_data_size =
        GetFontdata(Ch, *UI_font /* dummy parameter */ , &font_data, &char_width, &char_d_width, &char_height, &data_width, &data_height, &ascent, &descent, &valid);

    *pCharWidth = char_width;
    *pCharHeight = char_height;

    fx1 = char_width - 1;   /* min X of drawn area */
    fx2 = 0;                /* max X of drawn area */
    fy1 = char_height - 1;  /* min Y of drawn area */
    fy2 = 0;                /* max Y of drawn area */

    x = 0;
    y = 0;

    while (font_data_size--)
    {
        U8 pattern = *font_data++;

        if (!pattern)
        {
            U32 nTemp;

            x += 8;
            nTemp = x / char_width;
            if (nTemp)
            {
                y += nTemp;
                char_height -= (U16) nTemp;
                if (!char_height)
                {
                    break;
                }
            }

            x %= char_width;
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
                if (x == (S32) char_width)
                {
                    y++;
                    char_height--;
                    x = 0;
                    if (!char_height)
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
 *  Get_PropWidthHeight
 * DESCRIPTION
 *  To get char widths
 *  
 *  This is used to get char widths
 * PARAMETERS
 *  Ch          [IN]        
 *  pWidth      [?]         
 *  pHeight     [?]         
 * RETURNS
 *  S32
 *****************************************************************************/
S32 Get_PropWidthHeight(U32 Ch, S32 *pDwidth, S32 *pWidth, S32 *pHeight, S32 *pAscent, S32 *pDescent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 nBase = 0;
    S32 index = -1;
    U32 nIndexInList = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MTK Add Steven 2005.06.03 */
#if defined(__MMI_ZI__)
    index = SearchInZiExtraFont(Ch, &nBase);
#else 
    index = SearchInPropFont(Ch, &nBase);
#endif 

    if (index == -1)
    {
    #if defined(__MMI_ZI__)
        index = SearchInPropFont(Ch, &nBase);
        if (index == -1)
        {
    #endif /* defined(__MMI_ZI__) */ 

            Ch = 65515;
            index = SearchInPropFont(Ch, &nBase);
            if (index == -1)
            {
                return index;
            }

        #if defined(__MMI_ZI__)
        }
        nIndexInList = index + (Ch - nBase);
        *pHeight = gMTKProprietaryFont.nHeight;
        *pWidth = gMTKProprietaryFont.pWidthArray[nIndexInList];
        *pAscent = gMTKProprietaryFont.nAscent;
        *pDescent = gMTKProprietaryFont.nDescent;
        goto label_out2;
        #endif /* defined(__MMI_ZI__) */ 

    }

#if defined(__MMI_ZI__)
    nIndexInList = index + (Ch - nBase);
    *pHeight = gZiExtraCharacter.nHeight;
    *pWidth = gZiExtraCharacter.pWidthArray[nIndexInList];
    *pAscent = gZiExtraCharacter.nAscent;
    *pDescent = gZiExtraCharacter.nDescent;
  label_out2:;
#else /* defined(__MMI_ZI__) */ 
    nIndexInList = index + (Ch - nBase);
    *pHeight = gMTKProprietaryFont.nHeight;
    *pWidth = gMTKProprietaryFont.pWidthArray[nIndexInList];
    *pAscent = gMTKProprietaryFont.nAscent;
    *pDescent = gMTKProprietaryFont.nDescent;
#endif /* defined(__MMI_ZI__) */ 
    *pDwidth = *pWidth;
    return index;
}


/*****************************************************************************
 * FUNCTION
 *  Get_StringWidthHeight
 * DESCRIPTION
 *  To get string width and height
 *  
 *  This is used to get string widths
 * PARAMETERS
 *  String      [IN]        
 *  pWidth      [?]         
 *  pHeight     [?]         
 * RETURNS
 *  S32(?)
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

/* july-28-2002 manju: required by UI elements. This function measures a text string's width upto a given number of characters */


/*****************************************************************************
 * FUNCTION
 *  Get_StringWidthHeight_n
 * DESCRIPTION
 *  To get string widths and height upto a given number of characters
 *  
 *  This is used to get string widths upto a given number of characters
 * PARAMETERS
 *  String      [IN]        
 *  n           [IN]        
 *  pWidth      [IN]        
 *  pHeight     [IN]        
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

/* PMT dara added for Multitap thai */


/*****************************************************************************
 * FUNCTION
 *  Get_StringWidthHeight_multitap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  String      [?]         
 *  w           [IN]        
 *  pWidth      [?]         
 *  pHeight     [?]         
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
    return;
}


/*****************************************************************************
 * FUNCTION
 *  Get_StringWidthHeight_w
 * DESCRIPTION
 *  
 * PARAMETERS
 *  String      [?]         
 *  w           [IN]        
 *  pWidth      [?]         
 *  pHeight     [?]         
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
 *  
 * PARAMETERS
 *  String      [?]         
 *  w           [IN]        
 *  n           [IN]        
 *  pWidth      [?]         
 *  pHeight     [?]         
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
 *  
 * PARAMETERS
 *  String          [?]         
 *  w               [IN]        
 *  n               [IN]        
 *  pWidth          [?]         
 *  pHeight         [?]         
 *  max_width       [IN]        
 * RETURNS
 *  
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

#if defined(__MMI_INDIC_ALG__)
/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_string_widthheight_indic
 * DESCRIPTION
 *  get Indic string information by language
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
U32 mmi_fe_get_string_widthheight_indic(mmi_fe_get_string_info_param_struct_p param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 pWidth = 0;
    S32 pHeight = 0;
    U8 *String = param->String;
    S32 n = param->n;
    U16 preCh = 0, pre2Ch = 0;
    S32 prev_width = 0;
    S32 prev_height = 0;
    U32 numofChar = 0;
    MMI_BOOL enableTruncated = param->enableTruncated;
    S32 targetWidth = param->targetWidth;
    MMI_BOOL truncated = MMI_FALSE;
    mmi_fe_get_string_info_param_struct string_part_param;
    U16 glyph_output[100];
    U16 *glyph_output_p = glyph_output;
    U16 str_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ire_is_reset_indic_params())
    {
        ire_reset_indic_params();
    }
    if (ire_is_indic_rules_parsing())
    {
        U16 cluster_fill[G_MAX];
        S32 cluster_length;
        S32 Len;
        S32 len;
        S32 total_len = 0;
        S32 original_len = 0;
        S32 cluster_width;
        U16 pre_cluster = 0;
        U16 current_cluster = 0;

        mmi_fe_get_string_info_param_struct string_part_param_height_width;

    #if defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__)
       overwrite_current_language_for_hindi_rules_based_on_input_method();
    #endif 
        pre2Ch = 0;
        preCh = 0;
        
        memset((U16*) cluster_fill, '\0', sizeof(cluster_fill));
        memset(&string_part_param, 0, sizeof(mmi_fe_get_string_info_param_struct));
        string_part_param.w = param->w;

        if (String == NULL)
        {
            return numofChar;
        }
        ire_init_cluster_start_p(String);

        if (param->n < 0)
        {
            len = gui_strlen((UI_string_type) String);
        }
        else
        {
            len = param->n;
        }

        if (len > 0)
        {
            ire_init_cluster_end_p(String + (len * 2));
        }
        else
        {
            ire_init_cluster_end_p(String + (2 * mmi_ucs2strlen((const char*)String) + 1));
        }
        original_len = len;
    
        /* This loop takes the string cluster by cluster and finds the width  */
    /* and height of the string                                           */
        do
        {
    
            if (total_len == original_len)
                break;
            
            cluster_length = ire_get_cluster(cluster_fill);
            total_len += cluster_length;
            if (original_len > 0)
            {
                if (total_len > original_len || total_len > n)
                {
                    break;
                }
            }
    
            if (cluster_length)
            {
                pre_cluster = current_cluster;
                current_cluster = cluster_fill[0];
                if (cluster_length > 1)
                {
                    Len = ire_language_rules(glyph_output_p, cluster_fill, ire_get_display_buffer_len());
                }
                else
                {
                    Len = 1;
                    glyph_output_p[0] = cluster_fill[0];
                    glyph_output_p[1] = 0;
                }
                if (enableTruncated)
                    {
                    string_part_param_height_width.String = (U8*) glyph_output_p;
                    string_part_param_height_width.n = Len;
                    string_part_param_height_width.pWidth = 0;
                    mmi_fe_get_string_widthheight_indic_internal(&string_part_param_height_width);
                    cluster_width = string_part_param_height_width.pWidth;
                    pWidth += cluster_width;

                    }
                if ((enableTruncated) && (targetWidth > 0) && (pWidth) > targetWidth)
                   {
                        pWidth = prev_width;
                        pHeight = prev_height;
                        truncated = MMI_TRUE;
                        break;
                    }
                else
                {
                    prev_width = pWidth;
                    prev_height = pHeight;
                    glyph_output_p += Len;
                    numofChar += cluster_length;
                    str_len += Len;
                    glyph_output_p[0] = 0;
                }
            }
        } while (cluster_length);
        param->String = (U8*) & glyph_output;
        param->n = str_len;
        mmi_fe_get_string_widthheight_indic_internal(param);
        if (enableTruncated && truncated)
        {
            param->enableTruncated = MMI_FALSE;
        }
        param->String = (U8*) String;
        param->n = numofChar;
        return numofChar;
        
    }
    else
    {
    #if defined (__MMI_LANG_TELUGU__)
        IRE_RESET_RENDERING_CORRECTION();
    #endif 
        mmi_fe_get_string_widthheight_indic_internal(param);
        return param->n;
    }
}


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
    U32 prev_cons_char_width = 0;
    U32 pWidth = 0;
    U32 Counter = 0;
    U32 n = param->n;
    S32 ascent = 0, descent = 0;
    S32 chWidth = 0, chHeight = 0, chAscent = 0, chDescent = 0, chDwidth = 0;
    U32 curr_char_pos = 0 , pre_char_pos = 0;
    U16 curCh = 0;
    U8 *String = param->String;
    S32 cursorX = 0;
    U32 prev_base_char_width = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    IRE_RESET_RENDERING_CORRECTION();
    while (Counter < n)
    {
        if (String[0] == 0 && String[1] == 0)
        {
            break;
        }
        curCh = String[1] << 8 | String[0];
        Get_CharWidthHeight_internal((U32) curCh, &chDwidth, &chWidth, &chHeight, &chAscent, &chDescent);
        
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
                        pWidth = chWidth;
                        break;

                    }
                    prev_cons_char_width = chDwidth;
                    prev_base_char_width = chDwidth;
                    (pWidth) += chDwidth;
                    break;

                }
                case IRE_POST_BASE_POSITION_REQ_CORRECTION:
                {
                    prev_cons_char_width = chDwidth;
                    prev_base_char_width = chDwidth;
                    IRE_SET_RENDERING_CORRECTION(curCh);
                    (pWidth) += chDwidth;
                    break;
             }
                /* The width of the previous base consonant will be taken, 
                if current character position is above base */ 
                case IRE_ABOVE_BASE_POSITION:
                {

                    S32 temp_move = 0;
                    /* The width of the character will be returned
                    * if any sign comes as independently */

                    if(n == 1)
                    {
                        pWidth = chWidth;
                        break;

                    }

                    temp_move = (prev_base_char_width < chWidth ?  (chWidth - prev_base_char_width) : 0);
                    cursorX = (cursorX< temp_move)? temp_move:cursorX;
                    if (ire_is_indic_rules_parsing())
                    {
                        if(Counter == (n - 1))
                        pWidth += temp_move;

                    }
                    else 
                    {
                        if(IRE_IS_OFFSET_REQUIRED() && (Counter == (n - 1)))
                        {
                          pWidth += temp_move;

                        }

                         
                    }

                    break;
                }
                /* The width of the previous base consonant will be taken, 
                if current character position is  below base */     
                case IRE_BELOW_BASE_POSITION_IGNORE_CORRECTION_ATTRIBUTE:
                {
                    S32 temp_move = 0;
                    /* The width of the character will be returned
                    * if any sign comes as independently */
                    if(n == 1)
                    {
                        pWidth = chWidth;
                        break;

                    }
                    temp_move = (prev_base_char_width < chWidth ?  (chWidth - prev_base_char_width) : 0);
                    cursorX = (cursorX< temp_move)? temp_move:cursorX;

                    if (ire_is_indic_rules_parsing())
                    {
                        if(Counter == (n - 1))
                            pWidth += temp_move;

                    }
                    else 
                    {
                        if(IRE_IS_OFFSET_REQUIRED() && (Counter == (n - 1)))
                        {
                          pWidth += temp_move;

                        }

                         
                    }

                    IRE_RESET_RENDERING_CORRECTION();
                    IRE_RESET_SMALL_CONSONANT_FLAG();
                        break;
                    }
                case IRE_BELOW_BASE_POSITION:
                {

                     if((pre_char_pos == curr_char_pos) || (pre_char_pos == IRE_BELOW_AND_POST_BASE_POSITION)
                            || (pre_char_pos == IRE_BELOW_BASE_POSITION_IGNORE_CORRECTION_ATTRIBUTE))

                    {
                        (pWidth) += chDwidth;
                        break;
                    }
                    if (IRE_IS_RENDERING_CORRECTION())
                    {
                        S32 temp_rendering_width = prev_cons_char_width - IRE_IS_RENDERING_CORRECTION();
                        S32 temp_dwidth = chDwidth - temp_rendering_width;
                        (pWidth) += ((temp_dwidth > 0)) ? temp_dwidth : 0;
                        IRE_RESET_RENDERING_CORRECTION();
                        IRE_RESET_SMALL_CONSONANT_FLAG();
                    }
                   
                        break;
                    }
                default:
                    (pWidth) += chDwidth;
                    prev_base_char_width = chDwidth;
                    break;

            }
        }
        else
        {
            /* For non- Indic characters */
            (pWidth) += chWidth;
            prev_base_char_width = chDwidth;
        }
        
        if (chAscent > ascent)
            ascent = chAscent;
        
        if (chDescent > descent)
            descent = chDescent;

        pre_char_pos = curr_char_pos;
        
        String += 2;
        Counter++;
    }

    param->pWidth = pWidth;
    param->pHeight = ascent + descent;
    param->maxAscent = ascent;
    param->maxDescent = descent;
    param->baseline = ascent;
    param->adv_h = param->pHeight;
    param->adv_w = pWidth;
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
static U32 mmi_fe_get_string_widthheight_thai(mmi_fe_get_string_info_param_struct_p param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 pWidth = 0;
    S32 pHeight = 0;
    U8 *String = param->String;
    S32 Counter = 0;
    S32 n = param->n;
    U16 curCh = 0, preCh = 0, pre2Ch = 0;
    S32 prev_width = 0;
    S32 prev_height = 0;
    S32 w = param->w;
    MMI_BOOL enableTruncated = param->enableTruncated;
    S32 targetWidth = param->targetWidth;
    S32 ascent = 0, descent = 0;
    S32 chWidth = 0, chHeight = 0, chAscent = 0, chDescent = 0, chDwidth = 0;
    MMI_BOOL truncated = MMI_FALSE;
    MMI_BOOL gap_vowel = MMI_FALSE;
    MMI_BOOL gap_tone = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    while (Counter < n)
    {
        if ((String[0] == '\0') && (String[1] == '\0'))
        {
            break;
        }
        prev_width = pWidth;
        prev_height = pHeight;
        memcpy(&curCh, String, 2);
        String += 2;

        Get_CharWidthHeight_internal((U32)curCh, &chDwidth, &chWidth, &chHeight, &chAscent, &chDescent);
        
        if (curCh >= 0x0E01 && curCh <= 0x0E7F)
        {
            //curCh = unicode;
            // Base line character, can combinate with above vowels,bottom vowels, tone mark, and sign
            if (IsThaiBaseLineChar(curCh))
            {
                //if the current character is 0x0E33 and previous or previous 2 character is base line character, 0x0E33 shall be
                //moved ahead to let the circyle sign on the top of previous or previous2 character
                if (curCh == 0x0E33 && (IsThaiBaseLineChar(preCh) || IsThaiBaseLineChar(pre2Ch)))
                {
                    pWidth = pWidth - 1 + chWidth+ w;
                }
                else
                {
                    pWidth = pWidth + chWidth + w;
                }
            }
            /* For Thai digits and base line sign, the only thing we have to do is moving cursor */
            else if (IsThaiDigitChar(curCh) || IsThaiBaseSignChar(curCh))
            {
                pWidth = pWidth + chWidth;
            }
            else if (IsThaiToneMark(curCh))
            {
                if (IsThaiSignChar(preCh))
                {
                    /* move the tone two pixel way from the sign. */
                    pWidth = pWidth + chWidth + 2 + w;
                }
                else if (IsThaiBaseLineChar(preCh) || IsThaiAboveLineChar(preCh) || IsThaiBottomLineChar(preCh))
                {
                }
                else if (preCh == 0x0E47)
                {
                    /* move the tone mark to next character space */
                    pWidth = pWidth + chWidth  + w;
                }
                else
                {
                    pWidth = pWidth + chWidth + w;
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
                }                
                else
                {
                    pWidth = pWidth + chWidth + w;
                }
            }
            else if (IsThaiAboveLineChar(curCh))
            {
                if (!(IsThaiBaseLineChar(preCh) && IsThaiConsonant(preCh)))
                {
                    pWidth = pWidth + chWidth + w;                    
                }
                if (!gap_vowel)
                {
                    gap_vowel = MMI_TRUE;
                }
            }
            else if ((!gap_tone) && IsThaiToneMark(curCh))
            {
                gap_tone = MMI_TRUE;
            }
            else if (IsThaiBottomLineChar(curCh))
            {
                /* Bottom line characters */
                if (!IsThaiBaseLineChar(preCh))
                {
                    pWidth = pWidth + chWidth + w;                
                }
            }
        }

        if (enableTruncated && targetWidth < pWidth)
        {
            truncated = MMI_TRUE;
            break;
        }
        
        if (chAscent > ascent)
            ascent = chAscent;
        
        if (chDescent > descent)
            descent = chDescent;
                
        Counter ++;
        pre2Ch = preCh;
        preCh = curCh;
    }

    if (enableTruncated && truncated)
    {
        param->pWidth = prev_width;
        param->enableTruncated = MMI_FALSE;
    }
    else
    {
        param->pWidth = pWidth;        
    }
    if (gap_tone)
        ascent++;
    if (gap_vowel)
        ascent++;
    param->pHeight = ascent + descent;
    param->maxAscent = ascent;
    param->maxDescent = descent;
    param->baseline = ascent;
    return Counter;
}
#endif /* defined(__MMI_LANG_THAI__) */

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_char_info
 * DESCRIPTION
 *  get font info regarding of font attribute
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
void mmi_fe_get_char_info(U16 ch, S32* width, S32* displayw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 dWidth, Height, Ascent, Descent;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Get_CharWidthHeight_internal(ch, &dWidth, width, &Height, &Ascent, &Descent);
    *displayw = *width;
    if (gnCurrentFontAttrib & (FONTATTRIB_ITALIC | FONTATTRIB_OBLIQUE))
    {
        *displayw += (font_tilt_table[Height]);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_string_widthheight_others
 * DESCRIPTION
 *  get string information
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
static U32 mmi_fe_get_string_widthheight_others(mmi_fe_get_string_info_param_struct_p param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 pWidth = 0;
    S32 pHeight = 0;
    U8 *String = param->String;
    S32 Counter = 0;
    S32 n = param->n;
    U16 curCh = 0, preCh = 0;
    S32 w = param->w;
    MMI_BOOL enableTruncated = param->enableTruncated;
    S32 targetWidth = param->targetWidth;
    S32 ascent = 0, descent = 0;
    S32 chWidth = 0, chHeight = 0, chAscent = 0, chDescent = 0, chDwidth = 0;
    MMI_BOOL truncated = MMI_FALSE;
    MMI_BOOL checklinebreak = param->checklinebreak;
    MMI_BOOL checkCompleteWord = param->checkCompleteWord;
    S32 prev_space_width = 0;
    S32 prev_space_height = 0;
    S32 prev_space_index = 0;
#if defined(__MMI_LANG_VIETNAMESE__)
    U16 next_unicode = 0;
    viet_tone_mark tone_mark = VIET_TONE_NONE;
    viet_vowel_letter viet_vowel = VIET_VOWEL_NONE;
#endif /* defined(__MMI_LANG_VIETNAMESE__) */ 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    while (Counter < n)
    {
        if (String[0] == 0 && String[1] == 0)
            break;
        
        memcpy(&curCh, String, 2);
        String += 2;
        
#if defined(__MMI_LANG_VIETNAMESE__)
        if ((curCh > 0x0040) && (curCh < 0x01B1))
        {
            next_unicode = String[0];
            next_unicode |= (String[1] << 8);
            tone_mark = mmi_viet_tone_mark(next_unicode);
            if (VIET_TONE_NONE != tone_mark)
            {
                viet_vowel = mmi_viet_vowel_letter(curCh);
                if (VIET_VOWEL_NONE != viet_vowel)
                {
                    curCh = mmi_viet_combine_vowel_tone(viet_vowel, tone_mark);
                    String += 2;
                    Counter += 1;
                }
            }
        }
#endif /* defined(__MMI_LANG_VIETNAMESE__) */ 
#if defined(__MMI_LANG_ARMENIAN__)
        if (((curCh == 0x0574 ) || (curCh == 0x057e)) && (Counter < n - 1))
        {
            U16 cluster = 0, nextCh = 0;
            nextCh = String[0];
            nextCh |= (String[1] << 8);
            cluster = mmi_fe_armenian_get_cluster(curCh, nextCh);
            if (cluster)
            {
                curCh = cluster;
                String += 2;
                Counter++;
            }
        }
#endif

        Get_CharWidthHeight_internal((U32)curCh, &chDwidth, &chWidth, &chHeight, &chAscent, &chDescent);
        
        if (enableTruncated && checklinebreak)
        {
            if (FONT_TEST_NEW_LINE_CHAR(curCh))
            {
                break;                        
            }
        }
        if (enableTruncated && checkCompleteWord)
        {
            /* check space */
            if (FONT_TEST_WORD_WRAPPING_BREAK_CHARACTER(curCh))
            {
                prev_space_index = Counter;
                prev_space_height = pHeight;
                prev_space_width = pWidth;
            }
        }

        if (enableTruncated && targetWidth < pWidth + chWidth)
        {
            truncated = MMI_TRUE;
            break;
        }
        else
        {
            pWidth = pWidth + chWidth + w;
        }
        
        if (chAscent > ascent)
            ascent = chAscent;
        
        if (chDescent > descent)
            descent = chDescent;
                
        Counter ++;
        
    }
    
    if (enableTruncated && checkCompleteWord && truncated && prev_space_index != 0)
    {
        if (mmi_fe_test_alphabetic_lang_char(curCh) && mmi_fe_test_alphabetic_lang_char(preCh) /*&& (!FONT_TEST_WORD_WRAPPING_BREAK_CHARACTER(curCh))*/)
        {
            pWidth = prev_space_width;
            pHeight = prev_space_height;
            Counter = prev_space_index;
        }
    }
    
    if (enableTruncated && truncated)
    {
        param->enableTruncated = MMI_FALSE;
    }
    param->pWidth = pWidth;        
    param->pHeight = ascent + descent;
    param->maxAscent = ascent;
    param->maxDescent = descent;
    param->baseline = ascent;
    return Counter;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_string_widthheight_by_lang
 * DESCRIPTION
 *  get string information by language
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
static U32 mmi_fe_get_string_widthheight_by_lang(mmi_fe_get_string_info_param_struct_p param, mmi_fe_lang_id langid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_INDIC_ALG__)
    if (langid == MMI_FE_LANG_INDIC)
    {
        return mmi_fe_get_string_widthheight_indic(param);
    }
#endif
    
#if defined(__MMI_LANG_THAI__)
    if (langid == MMI_FE_LANG_THAI)
    {
        return mmi_fe_get_string_widthheight_thai(param);
    }
#endif
    
    return mmi_fe_get_string_widthheight_others(param);    

}

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_string_widthheight
 * DESCRIPTION
 *  
 * PARAMETERS
 *  String       [?]         
 *  w             [IN]        
 *  n              [IN]        
 *  pWidth      [?]         
 *  pHeight     [?] 
 *  targetWidth  [IN]
 *  checklinebreak [IN]
 * RETURNS
 *  void
 *****************************************************************************/
/* Vogins Start */
#ifdef __VRE__
U32 mmi_fe_get_string_widthheight(mmi_fe_get_string_info_param_struct_p query)
#else
static U32 mmi_fe_get_string_widthheight(mmi_fe_get_string_info_param_struct_p query)
#endif
/* Vogins End */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 StrWidth = 0;
    S32 Counter = 0;
    U16 unicode = 0;
    U32 numofChar = 0;
    S32 ascent = 0, descent = 0;
    U8 *String = query->String;
    S32 nLen = query->n;
    mmi_fe_get_string_info_param_struct string_part_param;
    S32 baseline = 0;

#if defined(__MMI_ARSHAPING_ENGINE__) || defined(__MMI_INDIC_ALG__)
    S32 check_len = 0; /* used to check every character in the string */
    U8 *temp_string = String;
#endif
#if defined(__MMI_ARSHAPING_ENGINE__)
    MMI_BOOL IS_ARABIC = MMI_FALSE;
#endif
    S32 lang_string_group = 0;
    mmi_fe_lang_id curLangid = MMI_FE_LANG_NONE, preLangid = MMI_FE_LANG_NONE;
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

    /* check if shaping is necessary */
#if defined(__MMI_ARSHAPING_ENGINE__)
    if (nLen > MAX_SHOW_STRING_TEXT_LENGTH - ENCODING_LENGTH) 
    {
        nLen = MAX_SHOW_STRING_TEXT_LENGTH - ENCODING_LENGTH;
    }
    temp_string = String;
    check_len = nLen;
    while (check_len != 0)
    {
        if ((temp_string[0] == '\0') && (temp_string[1] == '\0'))
            break;
        check_len--;

        unicode = temp_string[0];
        unicode |= (temp_string[1] << 8);

        if (IS_ARABIC_CHARACTER(unicode))
            IS_ARABIC = MMI_TRUE;
        if (IS_ARABIC)
            break;
        temp_string += 2;
    }
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
    unicode = 0;
#endif
    lang_string_start = String;
    lang_string_group = 0;

    memcpy(&string_part_param, query, sizeof(mmi_fe_get_string_info_param_struct));

    while (nLen > 0)
    {
        if ((String[0] == '\0') && (String[1] == '\0'))
            break;
        nLen--;

        unicode = String[0];
        unicode |= (String[1] << 8);

        preLangid = curLangid;
        curLangid = mmi_fe_get_lang_id(unicode);
        if((unicode == ZWNJ ) ||(unicode == ZWJ))
        {
            curLangid = preLangid;
        }
        if (preLangid == curLangid || preLangid == MMI_FE_LANG_NONE)
        {
            lang_string_group ++;
        }
        else
        {
            string_part_param.String = lang_string_start;
            string_part_param.n = lang_string_group;
            
            Counter = mmi_fe_get_string_widthheight_by_lang(&string_part_param, preLangid);
            
            numofChar += Counter;
            if (((preLangid == MMI_FE_LANG_ARABIC && curLangid != MMI_FE_LANG_ARABIC) ||
                (preLangid != MMI_FE_LANG_ARABIC && curLangid == MMI_FE_LANG_ARABIC)))
            {
                string_part_param.pWidth ++;
            }

            if (enableTruncated)
            {
                string_part_param.targetWidth -= string_part_param.pWidth;
            }
            if (ascent < string_part_param.maxAscent)
                ascent = string_part_param.maxAscent;
            if (descent < string_part_param.maxDescent)
                descent = string_part_param.maxDescent;
            if (baseline < string_part_param.baseline)
                baseline = string_part_param.baseline;
            StrWidth += string_part_param.pWidth;

            if (enableTruncated && !string_part_param.enableTruncated)
            {
                lang_string_group = 0;
                break;
            }

            lang_string_start = String;
            lang_string_group = 1;
        }
        String += 2;

    }
    if (lang_string_group)
    {
        string_part_param.String = lang_string_start;
        string_part_param.n = lang_string_group;

        Counter = mmi_fe_get_string_widthheight_by_lang(&string_part_param, curLangid);
        numofChar += Counter;
        if (ascent < string_part_param.maxAscent)
            ascent = string_part_param.maxAscent;
        if (descent < string_part_param.maxDescent)
            descent = string_part_param.maxDescent;
        if (baseline < string_part_param.baseline)
            baseline = string_part_param.baseline;
        StrWidth += string_part_param.pWidth;

    }

    query->pWidth = StrWidth;
    query->pHeight = ascent + descent;
    query->baseline = ascent;

#if defined(__MMI_ARSHAPING_ENGINE__)
    if (IS_ARABIC)
    {
        numofChar = fe_ShaToOrg[numofChar - 1];
    }
#endif
    
    return numofChar;
}


/*****************************************************************************
 * FUNCTION
 *  Get_CharHeight
 * DESCRIPTION
 *  To get char height
 *  
 *  This is used to get char height
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 Get_CharHeight()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S32) gpCurrentFont->nHeight;
}

/*****************************************************************************
 * FUNCTION
 *  Get_CharDisplayHeightofAllType
 * DESCRIPTION
 *  To get char height
 *  
 *  This is used to get char height
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 Get_CharDisplayHeightofAllType()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S32) (gpCurrentFont->nHeight + 2);
}

/*****************************************************************************
 * FUNCTION
 *  Get_CharAscent
 * DESCRIPTION
 *  To get char height
 *  
 *  This is used to get char height
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 Get_CharAscent()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S32) gpCurrentFont->nAscent;
}

/*****************************************************************************
 * FUNCTION
 *  Get_CharDescent
 * DESCRIPTION
 *  To get char height
 *  
 *  This is used to get char height
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 Get_CharDescent()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S32) gpCurrentFont->nDescent;
}

/*****************************************************************************
 * FUNCTION
 *  Get_CharDisplayDescentOfAllType
 * DESCRIPTION
 *  To get char height
 *  
 *  This is used to get char height
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 Get_CharDisplayDescentOfAllType()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S32) (gpCurrentFont->nDescent + 1);
}

/*****************************************************************************
 * FUNCTION
 *  Get_CharDisplayAscentOfAllType
 * DESCRIPTION
 *  To get char height
 *  
 *  This is used to get char height
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 Get_CharDisplayAscentOfAllType()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S32) (gpCurrentFont->nAscent + 1);
}

/*****************************************************************************
 * FUNCTION
 *  Get_CharDisplayHeightOfAllLangAndType
 * DESCRIPTION
 *  To get maximum char height regardless of language and font type 
 *  
 *  Justin. for WAP layout formating.
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 Get_CharDisplayHeightOfAllLangAndType(U8 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (Get_CharHeightOfAllLang(size) + 2);
}




/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_char_info_of_all_lang
 * DESCRIPTION
 *  To get maximum char height, ascent and descent regardless of language
 * PARAMETERS
 *  size        [IN]  
 *  height      [OUT]
 *  ascent      [OUT]
 *  descent     [OUT]   
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fe_get_char_info_of_all_lang(U8 size, S32* pheight, S32* pascent, S32* pdescent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int lang_index;
    sFontFamily *pFontFamily;
    S32 ascent = 0, descent = 0, max_ascent = 0, max_descent = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (lang_index = 0; lang_index < gMaxDeployedLangs; lang_index++)
    {
        pFontFamily = gLanguageArray[lang_index].fontfamilyList[gLanguageArray[lang_index].nCurrentFamily];
        if ((ascent = (S32) pFontFamily->fontData[size]->nAscent) > max_ascent)
        {
            max_ascent = ascent;
        }
        if ((descent = (S32) pFontFamily->fontData[size]->nDescent) > max_descent)
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
 *  
 *  Justin. for WAP layout formating.
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  S32
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
    mmi_fe_get_char_info_of_all_lang(size, &height, &ascent, &descent);
    return height;
}



/*****************************************************************************
 * FUNCTION
 *  Get_StringHeight
 * DESCRIPTION
 *  To get string height
 *  
 *  This is used to get string height
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 Get_StringHeight()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sFontFamily *pFontFamily;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pFontFamily = gLanguageArray[gCurrLangIndex].fontfamilyList[gLanguageArray[gCurrLangIndex].nCurrentFamily];
    return (S32) (pFontFamily->fontData[gnCurrentFont]->nHeight);

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

    for (count = 0; count < 2; count++)
    {
        ShowString(0, y, fontInfo, 0, (PU8) "abcdefghij", 30);
        y += 20;

        ShowString(0, y, fontInfo, 0, (PU8) "klmnopqrst", 30);
        y += 20;

        ShowString(0, y, fontInfo, 0, (PU8) "uvwxyz", 30);
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

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pFontFamily = gLanguageArray[arrCount].fontfamilyList[gLanguageArray[arrCount].nCurrentFamily];
    return (S32) (pFontFamily->fontData[f.size]->nHeight);
}


/*****************************************************************************
 * FUNCTION
 *  RequireToMoveCursor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  preCh       [IN]        
 *  curCh       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
BOOL RequireToMoveCursor(U16 preCh, U16 curCh)
{
#if defined(__MMI_LANG_THAI__)
    pBOOL isPreBaseLineChar = IsThaiBaseLineChar(preCh);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (curCh >= 0x0E01 && curCh <= 0x0E7F)
    {

        if (IsThaiBaseLineChar(curCh) || IsThaiDigitChar(curCh) || IsThaiBaseSignChar(curCh))
        {   /* For base level character */
            return TRUE;
        }
        else if (IsThaiAboveLineChar(curCh))
        {   /* For above level character */
            if (isPreBaseLineChar && IsThaiConsonant(preCh))
            {
                return FALSE;
            }
            /*else if (curCh == 0x0E4C && preCh != 0x0E4C && preCh != 0x0E47)
            {
                return FALSE;
            }*/
            else if (IsThaiUpDownVowel(preCh) && IsThaiUpSign(curCh))
            {
                return FALSE;
            }
            else
            {
                return TRUE;
            }

        }
        else if (IsThaiBottomLineChar(curCh))
        {   /* For below level character */
            if (isPreBaseLineChar && IsThaiConsonant(preCh))
            {
                return FALSE;
            }
            else
            {
                return TRUE;
            }
        }
        else if (IsThaiToneMark(curCh))
        {   /* For Tone mark characters */
            
            /* Tone couldn't be put together with Sign. */
            if (IsThaiSignChar(preCh))
            {
                return TRUE;
            }
            if (isPreBaseLineChar || IsThaiAboveLineChar(preCh) || IsThaiBottomLineChar(preCh))
            {
                return FALSE;
            }
            else
            {
                return TRUE;
            }

        }
        else if (IsThaiUpSign(curCh))
        {
            /* current character is sign and the previous character is consonant */
            if (IsThaiBaseLineChar(preCh))
            {
                return FALSE;
            }
            else
            {
                return TRUE;
            }
        }
        else
        {
            return TRUE;
        }
    }
    else
#endif
    {
        return TRUE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  ShowStackedChar
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
S32 ShowStackedChar(
        S32 CurrentX,
        S32 CurrentY,
        stFontAttribute Font,
        U8 BackGround,
        U16 curCh,
        U32 LineHeight,
        U32 Bordered,
        U16 pre2Ch,
        U16 preCh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* GDI_ENTER_CRITICAL_SECTION(ShowStackedChar) */
    U8 *CharData;
    U32 NumChar;
    /* nHgt, nWidth is the height and width of character and 
        dataHgt, dataWidth is the data height and width */    
    U16 nHgt;
    U16 nWidth;
    U16 dtWidth;
    U16 dtHgt;
    U16 ascent = 0;
    U16 descent = 0;
    U16 nDWidth;
    S32 iX = CurrentX;
    S32 iY = CurrentY;
    gdi_color border_color = 0, text_color;
    U8 font_attr = 0;
    S32 x_offset = CurrentX;
    MMI_BOOL valid;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check for formatting character */
    if (mmi_fe_test_display_as_null((U32)curCh))
        return CurrentX;

    if (gnCurrentFontAttrib & FONTATTRIB_ITALIC)
    {
        font_attr |= FONTATTRIB_ITALIC;
    }
    else if (gnCurrentFontAttrib & FONTATTRIB_OBLIQUE)
    {
        font_attr |= FONTATTRIB_OBLIQUE;
    }

    if (Font.underline)
    {
        font_attr |= FONTATTRIB_UNDERLINE;
    }

    {
        if (Bordered)
        {
            border_color = gdi_act_color_from_rgb(0xff, UI_text_border_color.r, UI_text_border_color.g, UI_text_border_color.b);
        }

        text_color = gdi_act_color_from_rgb(0xff, UI_current_text_color.r, UI_current_text_color.g, UI_current_text_color.b);

    }

#ifdef __MMI_SUPPORT_DUMP_SCREEN_STRING__
	mmi_trace_screen_char(CurrentX, CurrentY, curCh, 0, Bordered);
#endif

    if (mmi_fe_test_display_as_space(curCh))
    {
        curCh = 0x20;
    }

    NumChar = GetFontdata(curCh, Font, &CharData, &nWidth, &nDWidth, &nHgt, &dtWidth, &dtHgt, &ascent, &descent, &valid);


#ifdef __MMI_LANG_THAI__
    /* adjust iX and iY for Thai characters */
    if (curCh >= 0x0E01 && curCh <= 0x0E7F)
    {
        if (IsThaiBaseLineChar(curCh))
        {
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
            //if the current character is 0x0E33 and previous or previous 2 character is base line character, 0x0E33 shall be
            //moved ahead to let the circyle sign on the top of previous or previous2 character
            if (curCh == 0x0E33 && (IsThaiBaseLineChar(preCh) || IsThaiBaseLineChar(pre2Ch)))
            {
                iX -= 1;
                x_offset -= 1;
            }

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
                }
                else if (preCh == 0x0E0A || preCh == 0x0E0B)
                {
                    iX -= 2;
                }
                else if (preCh == 0x0E2C)   /* move ahead 6 pixels */
                {
                    iX -= 6;
                }
            }
            else if (IsThaiUpDownVowel(preCh) && IsThaiUpSign(curCh))
            {
                if (IsThaiUpVowel(preCh))
                    iY -= 3;
                iX -= ((S32) nWidth);
            }

        }
        else if (IsThaiBottomLineChar(curCh))
        {
            /* Bottom line characters */
            if (IsThaiBaseLineChar(preCh) && IsThaiConsonant(preCh))
            {
                iX -= ((S32) nWidth);
                if (preCh == 0x0E2C)
                {
                    iX -= 2;    /* move ahead for 2 pixels */
                }
            }
        }
        else if (IsThaiToneMark(curCh))
        {
            /* Tone marks */
            iY -= 1;
            if (IsThaiBaseLineChar(preCh))
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
                //else if(nextCharUCS2 == 0x0E33)
                //       iY -= 3;//move tone mark higher
                else if (IsThaiLongTailChar(preCh))
                {
                    iX -= 3;    /* move tone mark ahead for 3 pixel */
                }
                else if (preCh == 0x0E0A || preCh == 0x0E0B)
                {
                    iX -= 2;
                }
                else if (preCh == 0x0E2C)
                {
                    iX -= 6;
                }
                else if (preCh == 0x0e13 || preCh == 0x0e19 || preCh == 0x0e28 || preCh == 0x0e29 || preCh == 0x0e2A)
                {
                    iX -= 3;
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
                    iX -= 6;
                }
            }
            else if (IsThaiBottomLineChar(preCh))
            {
                iX -= ((S32) nWidth);
                if (IsThaiLongTailChar(pre2Ch))
                {
                    iX -= 3;
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
        }
        //(1)Other cases: For Thai digits and base line sign, the only thing we have to do is moving cursor
        //(2)Show Characters

    }
#endif //__MMI_LANG_THAI__
    {
        iY = iY + (LineHeight - ascent);
        ShowCharFuncDispatch(LineHeight, dtWidth, dtHgt, iX, iY, Font, BackGround, CharData, NumChar, Bordered);
    }
    return x_offset;
    /* GDI_EXIT_CRITICAL_SECTION(ShowStackedChar) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_char_at_xy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void mmi_fe_show_char_at_xy(S32 x, S32 y, stFontAttribute Font, U8 BackGround, U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *CharData;
    U32 NumChar;
    /* nHgt, nWidth is the height and width of character and 
        dataHgt, dataWidth is the data height and width */    
    U16 nHgt;
    U16 nWidth;
    U16 dtWidth;
    U16 dtHgt;
    U16 ascent = 0;
    U16 descent = 0;
    U16 nDWidth;
    gdi_color text_color;
    U8 font_attr = 0;
    MMI_BOOL valid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check for formatting character */
    if (mmi_fe_test_display_as_null((U32)ch))
        return;

    if (gnCurrentFontAttrib & FONTATTRIB_ITALIC)
    {
        font_attr |= FONTATTRIB_ITALIC;
    }
    else if (gnCurrentFontAttrib & FONTATTRIB_OBLIQUE)
    {
        font_attr |= FONTATTRIB_OBLIQUE;
    }

    if (Font.underline)
    {
        font_attr |= FONTATTRIB_UNDERLINE;
    }

    text_color = gdi_act_color_from_rgb(0xff, UI_current_text_color.r, UI_current_text_color.g, UI_current_text_color.b);

    if (mmi_fe_test_display_as_space(ch))
    {
        ch = 0x20;
    }
    NumChar = GetFontdata(ch, Font, &CharData, &nWidth, &nDWidth, &nHgt, &dtWidth, &dtHgt, &ascent, &descent, &valid);

    gdi_font_begin(text_color, font_attr);
    ShowCharFuncDispatch(0, dtWidth, dtHgt, x, y, Font, BackGround, CharData, NumChar, 0);
    gdi_font_end();
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
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
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
U32 ShowDebugString(S32 x, S32 y, stFontAttribute Font, U8 *String, S32 len, U32 LineHeight, U32 Bordered)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* GDI_ENTER_CRITICAL_SECTION(ShowDebugString) */
    U8 *CharData;

    U32 NumChar;
    U32 Counter = 0;
    S32 CurrentX;
    U16 nHgt;
    U16 nWidth;
    S32 nXOffset;
    S32 nYOffset;
    S32 yy;
    U16 unicode = 0;
    U16 dtWidth;
    U16 dtHgt;
    U16 ascent = 0;
    U16 descent = 0;
    U16 nDWidth = 0;

    U8 font_attr = 0;
    gdi_color border_color = 0, text_color;
    MMI_BOOL valid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gnCurrentFontAttrib & FONTATTRIB_ITALIC)
    {
        font_attr |= FONTATTRIB_ITALIC;
    }
    else if (gnCurrentFontAttrib & FONTATTRIB_OBLIQUE)
    {
        font_attr |= FONTATTRIB_OBLIQUE;
    }

    if (Font.underline)
    {
        font_attr |= FONTATTRIB_UNDERLINE;
    }

    {
        if (Bordered)
        {
            border_color = gdi_act_color_from_rgb(0xff, UI_text_border_color.r, UI_text_border_color.g, UI_text_border_color.b);
        }

        text_color = gdi_act_color_from_rgb(0xff, UI_current_text_color.r, UI_current_text_color.g, UI_current_text_color.b);

    }

    gdi_font_begin(text_color, font_attr);

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

        NumChar = GetFontdata(unicode, Font, &CharData, &nWidth, &nDWidth, &nHgt, &dtWidth, &dtHgt, &ascent, &descent, &valid);

        Counter++;

        if (LineHeight > 0)
        {
            yy = y + LineHeight - nHgt;
        }
        else
        {
            yy = y;
        }

        nXOffset = CurrentX + nWidth;
        nYOffset = yy + nHgt;

        if (Bordered)
        {
            gdi_show_char_bordered(CurrentX, yy, text_color, border_color, CharData, NumChar, nWidth, nHgt, font_attr);
        }
        else if (!
                 (gnCurrentFontAttrib & FONTATTRIB_BOLD &&
                  gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_BOLD) ||
                 !(gpCurrentFont->pFontType[gnCurrentFont][gbFontType] & FONTATTRIB_NORMAL))
        {
            gdi_show_char(CurrentX, yy, text_color, CharData, NumChar, dtWidth, dtHgt, font_attr);
        }
        else
        {
            gdi_show_char(CurrentX + 1, yy, text_color, CharData, NumChar, dtWidth, dtHgt, font_attr);
            gdi_show_char(CurrentX, yy, text_color, CharData, NumChar, dtWidth, dtHgt, font_attr);
        }

        CurrentX += nWidth;

        nHgt = (U8) LineHeight;
        String += 2;
    }
    gdi_font_end();

    return CurrentX;
    /* GDI_RETURN (CurrentX); */

    /* GDI_EXIT_CRITICAL_SECTION(ShowDebugString) */

}

/*-----------------------------------------------------------------------*/
/*--------------------------- *** End *** -------------------------------*/
/*-----------------------------------------------------------------------*/

