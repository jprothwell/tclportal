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
/**
 *	Copyright Notice
 *	?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 *	Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

	FILENAME	: Res_.c

  	PURPOSE		: Populate Resource for 

	REMARKS		: nil

	AUTHOR		: Yogesh

	DATE		: August-11-2003

**************************************************************/
//PMT NEERAJ START 20050616
#include "MMI_features.h"
//PMT NEERAJ END 20050616
#include "CustomCfg.h"

#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif

#include "wgui_categories_res.h"
#include "gui_config.h"
#include "StatusIconRes.h"
#include "MMIDataType.h"
#ifdef __MMI_WLAN_FEATURES__
#include "DataAccountResDef.h"
#endif

#ifdef DEVELOPER_BUILD_FIRST_PASS
#include "PopulateRes.h"

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
	extern int disableENFB;
#endif

#if (defined __OPTR_NONE__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || (defined(__MMI_MAINLCD_320X480__) && defined(__MMI_FTE_SUPPORT__))) && (!defined(__LOW_COST_SUPPORT_COMMON__))
    #define STATUS_ICON_IMAGE_FILE_PATH "_png"
#else
    #define STATUS_ICON_IMAGE_FILE_PATH ""
#endif

void PopulateUnifiedComposerEditorRes (void)
{
#ifdef __UI_UNIFIED_COMPOSER_EDITOR_CATEGORY__
ADD_APPLICATION_STRING2 (WGUI_UCE_SMS_STRING_ID, "SMS", "SMS string used in information bar showing size of SMS");
ADD_APPLICATION_STRING2 (WGUI_UCE_MMS_STRING_ID, "MMS", "MMS string used in information bar showing size of MMS");

#ifdef __MMI_TOUCH_SCREEN__
ADD_APPLICATION_IMAGE2 (WGUI_UCE_ATTACHFILE_ICON_IMAGE_ID, CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\LAttachfile.pbm", "Attachment ICON");
ADD_APPLICATION_IMAGE2 (WGUI_UCE_AUDIO_ICON_IMAGE_ID, CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\LAudio.pbm", "Audio ICON");
ADD_APPLICATION_IMAGE2 (WGUI_UCE_PICTURE_ICON_IMAGE_ID, CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\LPic.pbm", "Picture ICON");
ADD_APPLICATION_IMAGE2 (WGUI_UCE_VIDEO_ICON_IMAGE_ID, CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\LVideo.pbm", "Video ICON");
#else
ADD_APPLICATION_IMAGE2 (WGUI_UCE_ATTACHFILE_ICON_IMAGE_ID, CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\SAttachfile.pbm", "Attachment ICON");
ADD_APPLICATION_IMAGE2 (WGUI_UCE_AUDIO_ICON_IMAGE_ID, CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\SAudio.pbm", "Audio ICON");
ADD_APPLICATION_IMAGE2 (WGUI_UCE_PICTURE_ICON_IMAGE_ID, CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\Spic.pbm", "Picture ICON");
ADD_APPLICATION_IMAGE2 (WGUI_UCE_VIDEO_ICON_IMAGE_ID, CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\SVideo.pbm", "Video ICON");
#endif /*__MMI_TOUCH_SCREEN__ */

ADD_APPLICATION_IMAGE2(WGUI_UCE_PRE_BUTTON_ID,CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\Left_arrow_normal.bmp","previous(left) button");
ADD_APPLICATION_IMAGE2(WGUI_UCE_PRE_BUTTON_DISABLE_ID,CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\Left_arrow_disable.bmp","previous(left) button");
ADD_APPLICATION_IMAGE2(WGUI_UCE_NEXT_BUTTON_ID,CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\Right_arrow_normal.bmp","next(right) button");
ADD_APPLICATION_IMAGE2(WGUI_UCE_NEXT_BUTTON_DISABLE_ID,CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\Right_arrow_disable.bmp","next(right) button");

#ifdef __MMI_FTE_SUPPORT__
ADD_APPLICATION_IMAGE2(WGUI_UCE_FTE_PRE_BUTTON_NORMAL,CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\Left_arrow_normal.png","previous(left) button");
ADD_APPLICATION_IMAGE2(WGUI_UCE_FTE_PRE_BUTTON_DOWN,CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\Left_arrow_down.png","previous(left) button");
ADD_APPLICATION_IMAGE2(WGUI_UCE_FTE_PRE_BUTTON_DISABLE,CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\Left_arrow_disable.png","previous(left) button");
ADD_APPLICATION_IMAGE2(WGUI_UCE_FTE_NEXT_BUTTON_NORMAL,CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\Right_arrow_normal.png","next(right) button");
ADD_APPLICATION_IMAGE2(WGUI_UCE_FTE_NEXT_BUTTON_DOWN,CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\Right_arrow_down.png","next(right) button");
ADD_APPLICATION_IMAGE2(WGUI_UCE_FTE_NEXT_BUTTON_DISABLE,CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\Right_arrow_disable.png","next(right) button");
ADD_APPLICATION_IMAGE2(WGUI_UCE_FTE_BUTTON_BG,CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\Background.png","button background");
#endif /*__MMI_FTE_SUPPORT__*/

#endif /* __UI_UNIFIED_COMPOSER_EDITOR_CATEGORY__ */
#if defined(__UI_UNIFIED_COMPOSER_EDITOR_CATEGORY__) || defined(__UI_MMS_VIEWER_CATEGORY__)
ADD_APPLICATION_IMAGE2 (WGUI_DEFAULT_PREVIEW_IMAGE_ID, CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\broken.gif", "Default Preview");
ADD_APPLICATION_IMAGE2 (WGUI_DEFAULT_PREVIEW_AVIDEO_ID, CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\broken_video.gif", "Default Preview");
#endif /* defined(__UI_UNIFIED_COMPOSER_EDITOR_CATEGORY__) || defined(__UI_MMS_VIEWER_CATEGORY__) */
}


void PopulateMMSViewerRes(void)
{
#ifdef __UI_MMS_VIEWER_CATEGORY__
    ADD_APPLICATION_IMAGE2 (WGUI_MV_ATTACHFILE_ICON_IMAGE_ID, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\MMS_attach.bmp", "Attachment ICON");
    ADD_APPLICATION_IMAGE2 (WGUI_MV_REFERENCE_ICON_IMAGE_ID, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\MMS_ref.bmp", "Reference ICON");
    ADD_APPLICATION_IMAGE2 (WGUI_MV_RING_ICON_IMAGE_ID, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\MMS_Ring.bmp", "Ring ICON");
#if defined(__MMI_FTE_SUPPORT__)
    ADD_APPLICATION_IMAGE2 (WGUI_MV_TITLE_ICON_IMAGE_ID, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\Background.9slice.png", "Title ICON");
#endif /* defined(__MMI_FTE_SUPPORT__) */
    ADD_APPLICATION_IMAGE2 (WGUI_MV_BAR_ICON_IMAGE_ID, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\BAR.gif", "Bar ICON");
    ADD_APPLICATION_IMAGE2 (WGUI_MV_RING_STOP_ICON_IMAGE_ID, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\MMS_RingStop.bmp", "Left Arrow ICON");

    ADD_APPLICATION_IMAGE2 (WGUI_MV_LEFT_ARROW_ICON_IMAGE_ID, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\MMS_LA.png", "Left Arrow ICON");
    ADD_APPLICATION_IMAGE2 (WGUI_MV_LEFT_ARROW_DOWN_ICON_IMAGE_ID, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\MMS_LADown.png", "Left Arrow Down ICON");
    ADD_APPLICATION_IMAGE2 (WGUI_MV_RIGHT_ARROW_ICON_IMAGE_ID, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\MMS_RA.png", "Right Arrow ICON");
    ADD_APPLICATION_IMAGE2 (WGUI_MV_RIGHT_ARROW_DOWN_ICON_IMAGE_ID, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\MMS_RADown.png", "Right Arrow Down ICON");

    ADD_APPLICATION_IMAGE2 (WGUI_MV_DRM_IMAGE_LOCK_ID, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\Image_lock.gif", "DRM image lock");
    ADD_APPLICATION_IMAGE2 (WGUI_MV_DRM_VIDEO_LOCK_ID, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\Video_lock.gif", "DRM video lock");

    ADD_APPLICATION_IMAGE2 (WGUI_MV_PAUSE_IMAGE_ID, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\MMS_pause.pbm", "MV Key Pause");
    ADD_APPLICATION_IMAGE2 (WGUI_MV_RESUME_IMAGE_ID, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\MMS_resume.pbm", "MV Key Resume");
#endif /* __UI_MMS_VIEWER_CATEGORY__ */
}

/* it should be sync with gui_virtual_keyboard.h */
#if defined(__MMI_LANG_RUSSIAN__) || defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_SA_SPANISH__)\
    || defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_CA_FRENCH__) || defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_SA_PORTUGUESE__) \
    || defined(__MMI_LANG_GERMAN__) || defined(__MMI_LANG_ITALIAN__) || defined(__MMI_LANG_TURKISH__) \
    || defined(__MMI_LANG_POLISH__) || defined(__MMI_LANG_CZECH__) || defined(__MMI_LANG_SLOVAK__) \
    || defined(__MMI_LANG_CROATIAN__) || defined(__MMI_LANG_SLOVENIAN__) || defined(__MMI_LANG_DANISH__) \
    || defined(__MMI_LANG_HUNGARIAN__) || defined(__MMI_LANG_FINNISH__) || defined(__MMI_LANG_ROMANIAN__) \
    || defined(__MMI_LANG_GREEK__) || defined(__MMI_LANG_BULGARIAN__) || defined(__MMI_LANG_MOLDOVAN__) \
    || defined(__MMI_LANG_CATALAN__)|| defined(__MMI_LANG_HAUSA__)|| defined(__MMI_LANG_ICELANDIC__)\
    || defined(__MMI_LANG_AZERBAIJANI__)|| defined(__MMI_LANG_YORUBA__)\
    || defined(__MMI_LANG_NORWEGIAN__)  || defined(__MMI_LANG_LITHUANIAN__)
    
#define  __MMI_VKBD_EUROPEAN_SUPPORT__

#endif /* European languages */


void PopulateCommonCategoryResources(void)
{	
      //MTK add, Robin 1025
      /*
      0x87=>Monday for English
      0x88=>Tuesday
      0x89=>Wednesday
      0x8a=>Thursday
      0x8b=>Friday
      0x8c=>Saturday
      0x8d=>Sunday
      0x8e=>Monday for Traditional Chinese and Simplified Chinese
      0x8f=>Tuesday
      0x90=>Wednesday
      0x91=>Thursday
      0x92=>Friday
      0x93=>Saturday
      0x94=>Sunday
      */
      #ifdef __MMI_SUBLCD__
      S8 str_english_monday[] = { (S8)0x87, (S8)0x00 };
      S8 str_english_tuesday[] ={ (S8)0x88, (S8)0x00 };
      S8 str_english_wednesday[] ={ (S8)0x89, (S8)0x00 };
      S8 str_english_thursday[] ={ (S8)0x8a, (S8)0x00 };
      S8 str_english_friday[] ={ (S8)0x8b, (S8)0x00 };
      S8 str_english_saturday[] ={ (S8)0x8c, (S8)0x00 };
      S8 str_english_sunday[] ={ (S8)0x8d, (S8)0x00 };

      S8 str_chinese_monday[] ={ '(', (S8)0x8e, ')', (S8)0x00 };
      S8 str_chinese_tuesday[] ={ '(', (S8)0x8f, ')', (S8)0x00 };
      S8 str_chinese_wednesday[] ={ '(', (S8)0x90, ')', (S8)0x00 };
      S8 str_chinese_thursday[] ={ '(', (S8)0x91, ')', (S8)0x00 };
      S8 str_chinese_friday[] ={ '(', (S8)0x92, ')', (S8)0x00 };
      S8 str_chinese_saturday[] ={ '(', (S8)0x93, ')', (S8)0x00 };
      S8 str_chinese_sunday[] ={ '(', (S8)0x94, ')', (S8)0x00 };
      #endif
      //MTK end
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_ABC_STRING_ID,"ABC","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_abc_STRING_ID,"abc","Category screens string");
#if defined(__MMI_SMART_FIRST_UPPERCASE__)  || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_Abc_STRING_ID,"Abc","Category screens string");
#endif
#if defined(__MMI_LANG_UK_ENGLISH__)
ADD_APPLICATION_STRING2(WGUI_CATEGORY_UK_ABC_STRING_ID,"ABC-UK","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_uk_abc_STRING_ID,"abc-uk","Category screens string");
#if defined(__MMI_SMART_FIRST_UPPERCASE__)  || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_UK_Abc_STRING_ID,"Abc-Uk","Category screens string");
#endif
#endif
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_123_STRING_ID,"123","Category screens string");

#if defined(__MMI_MULTITAP_THAI__) || defined(__MMI_ZI_THAI__)	||	defined (__MMI_T9_THAI__) || defined (__MMI_CSTAR_THAI__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_thai_STRING_ID,"Th","Category screens string");
#endif 
#if defined(__MMI_MULTITAP_HEBREW__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_hebrew_STRING_ID,"He","Category screens string");
#endif 
#if defined(__MMI_MULTITAP_SPANISH__)||defined(__MMI_T9_SPANISH__)||defined(__MMI_ZI_EU_SPANISH__)||defined(__MMI_ZI_SA_SPANISH__) || defined(__MMI_CSTAR_SPANISH__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_SPANISH_STRING_ID,"ES","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_spanish_STRING_ID,"es","Category screens string");
    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__)  || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_SPANISH_STRING_ID,"Es","Category screens string");
    #endif
#endif	
#if defined(__MMI_MULTITAP_POLISH__)||defined(__MMI_T9_POLISH__)||defined(__MMI_ZI_POLISH__) || defined(__MMI_CSTAR_POLISH__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_POLISH_STRING_ID,"PO","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_polish_STRING_ID,"po","Category screens string");
        
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)  || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_POLISH_STRING_ID,"Po","Category screens string");
    #endif
#endif
#if defined(__MMI_MULTITAP_DANISH__)||defined(__MMI_T9_DANISH__)||defined(__MMI_ZI_DANISH__) || defined(__MMI_CSTAR_DANISH__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_DANISH_STRING_ID,"DA","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_danish_STRING_ID,"da","Category screens string");
            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)  || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_DANISH_STRING_ID,"Da","Category screens string");
    #endif
#endif	
#if defined(__MMI_MULTITAP_SERBIAN__)||defined(__MMI_T9_SERBIAN__)||defined(__MMI_ZI_SERBIAN__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_SERBIAN_STRING_ID,"SR","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_serbian_STRING_ID,"sr","Category screens string");
            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_SERBIAN_STRING_ID,"Sr","Category screens string");
    #endif
#endif	
#if defined(__MMI_MULTITAP_ICELANDIC__)||defined(__MMI_T9_ICELANDIC__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_ICELANDIC_STRING_ID,"IS","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_icelandic_STRING_ID,"is","Category screens string");
            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_ICELANDIC_STRING_ID,"Is","Category screens string");
    #endif
#endif	

#if defined(__MMI_MULTITAP_AZERBAIJANI__)||defined(__MMI_T9_AZERBAIJANI__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_AZERBAIJANI_STRING_ID,"AZ","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_azerbaijani_STRING_ID,"az","Category screens string");
            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)|| defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_AZERBAIJANI_STRING_ID,"Az","Category screens string");
    #endif
#endif
#if defined(__MMI_MULTITAP_CATALAN__)||defined(__MMI_T9_CATALAN__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_CATALAN_STRING_ID,"CA","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_catalan_STRING_ID,"ca","Category screens string");
            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)|| defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_CATALAN_STRING_ID,"Ca","Category screens string");
    #endif
#endif	
#if defined(__MMI_MULTITAP_KAZAKH__)||defined(__MMI_T9_KAZAKH__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_KAZAKH_STRING_ID,"KK","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_kazakh_STRING_ID,"kk","Category screens string");
            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)|| defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_KAZAKH_STRING_ID,"Kk","Category screens string");
    #endif
#endif
#if defined(__MMI_MULTITAP_HAUSA__)||defined(__MMI_T9_HAUSA__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_HAUSA_STRING_ID,"HA","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_hausa_STRING_ID,"ha","Category screens string");
            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)|| defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_HAUSA_STRING_ID,"Ha","Category screens string");
    #endif
#endif	
#if defined(__MMI_MULTITAP_MACEDONIAN__)||defined(__MMI_T9_MACEDONIAN__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_MACEDONIAN_STRING_ID,"MK","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_macedonian_STRING_ID,"mk","Category screens string");
            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)|| defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_MACEDONIAN_STRING_ID,"Mk","Category screens string");
    #endif
#endif	
#if defined(__MMI_MULTITAP_TAGALOG__)||defined(__MMI_T9_TAGALOG__)||defined(__MMI_ZI_TAGALOG__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_TAGALOG_STRING_ID,"TL","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_tagalog_STRING_ID,"tl","Category screens string");
            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)|| defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_TAGALOG_STRING_ID,"Tl","Category screens string");
    #endif
#endif	
#if defined(__MMI_MULTITAP_YORUBA__)||defined(__MMI_T9_YORUBA__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_YORUBA_STRING_ID,"YO","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_yoruba_STRING_ID,"yo","Category screens string");
            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)|| defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_YORUBA_STRING_ID,"Yo","Category screens string");
    #endif
#endif
#if defined(__MMI_MULTITAP_SESOTHO__)||defined(__MMI_T9_SESOTHO__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_SESOTHO_STRING_ID,"ST","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_sesotho_STRING_ID,"st","Category screens string");
            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)|| defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_SESOTHO_STRING_ID,"St","Category screens string");
    #endif
#endif	
#if defined(__MMI_MULTITAP_GALICIAN__)||defined(__MMI_T9_GALICIAN__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_GALICIAN_STRING_ID,"GL","editor Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_galician_STRING_ID,"gl","editor Category screens string");
            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)|| defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_GALICIAN_STRING_ID,"Gl","editor Category screens string");
    #endif
#endif	
#if defined(__MMI_MULTITAP_BASQUE__)||defined(__MMI_T9_BASQUE__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_BASQUE_STRING_ID,"EU","editor Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_basque_STRING_ID,"eu","editor Category screens string");
            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)|| defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_BASQUE_STRING_ID,"Eu","editor Category screens string");
    #endif
#endif	
#if defined(__MMI_MULTITAP_IGBO__)||defined(__MMI_T9_IGBO__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_IGBO_STRING_ID,"IG","editor Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_igbo_STRING_ID,"ig","editor Category screens string");
            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)|| defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_IGBO_STRING_ID,"Ig","editor Category screens string");
    #endif
#endif	
#if defined(__MMI_MULTITAP_FILIPINO__)||defined(__MMI_T9_FILIPINO__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_FILIPINO_STRING_ID,"FIL","editor Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_filipino_STRING_ID,"fil","editor Category screens string");
            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)|| defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_FILIPINO_STRING_ID,"Fil","editor Category screens string");
    #endif
#endif	
#if defined(__MMI_MULTITAP_IRISH__)||defined(__MMI_T9_IRISH__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_IRISH_STRING_ID,"GA","editor Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_irish_STRING_ID,"ga","editor Category screens string");
            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)|| defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_IRISH_STRING_ID,"Ga","editor Category screens string");
    #endif
#endif	
	
	
#if defined(__MMI_MULTITAP_FRENCH__)||defined(__MMI_T9_FRENCH__)||defined(__MMI_ZI_CA_FRENCH__)||defined(__MMI_ZI_EU_FRENCH__) || defined(__MMI_CSTAR_FRENCH__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_FRENCH_STRING_ID,"FR","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_french_STRING_ID,"fr","Category screens string");
                
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)  || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_FRENCH_STRING_ID,"Fr","Category screens string");
    #endif
#endif	
#if defined(__MMI_MULTITAP_GERMAN__)||defined(__MMI_T9_GERMAN__)||defined(__MMI_ZI_GERMAN__) || defined(__MMI_CSTAR_GERMAN__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_GERMAN_STRING_ID,"DE","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_german_STRING_ID,"de","Category screens string");
                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_GERMAN_STRING_ID,"De","Category screens string");
    #endif
#endif	
#if defined(__MMI_MULTITAP_ITALIAN__)||defined(__MMI_T9_ITALIAN__)||defined(__MMI_ZI_ITALIAN__) || defined(__MMI_CSTAR_ITALIAN__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_ITALIAN_STRING_ID,"IT","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_italian_STRING_ID,"it","Category screens string");
                        
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_ITALIAN_STRING_ID,"It","Category screens string");
    #endif
#endif	
#if defined (__MMI_T9_RUSSIAN__) || defined(__MMI_MULTITAP_RUSSIAN__)||defined(__MMI_ZI_RUSSIAN__)||defined(__MMI_ZI_RECOMMENDED_SIZE_RUSSIAN__) || defined(__MMI_CSTAR_RUSSIAN__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_RUSSIAN_STRING_ID,"RU","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_russian_STRING_ID,"ru","Category screens string");
                            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_RUSSIAN_STRING_ID,"Ru","Category screens string");
    #endif
#endif	
#if defined (__MMI_T9_BULGARIAN__) || defined(__MMI_MULTITAP_BULGARIAN__)||defined(__MMI_ZI_BULGARIAN__) || defined(__MMI_CSTAR_BULGARIAN__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_BULGARIAN_STRING_ID,"BG","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_bulgarian_STRING_ID,"bg","Category screens string");
                                
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_BULGARIAN_STRING_ID,"Bg","Category screens string");
    #endif
#endif
#if defined (__MMI_T9_UKRAINIAN__) || defined(__MMI_MULTITAP_UKRAINIAN__)||defined(__MMI_ZI_UKRAINIAN__) || defined(__MMI_CSTAR_UKRAINIAN__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_UKRAINIAN_STRING_ID,"UK","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_L_UKRAINIAN_STRING_ID,"uk","Category screens string");
                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_UKRAINIAN_STRING_ID,"Uk","Category screens string");
    #endif
#endif
#if defined(__MMI_MULTITAP_TURKISH__)||defined(__MMI_ZI_TURKISH__)||defined(__MMI_T9_TURKISH__) || defined(__MMI_CSTAR_TURKISH__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_TURKISH_STRING_ID,"TR","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_turkish_STRING_ID,"tr","Category screens string");
                                        
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_TURKISH_STRING_ID,"Tr","Category screens string");
    #endif
#endif	
#if defined(__MMI_MULTITAP_HEBREW__)||defined(__MMI_ZI_HEBREW__)||defined(__MMI_T9_HEBREW__)||defined(__MMI_CSTAR_HEBREW__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_HEBREW_STRING_ID,"HE","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_hebrew_STRING_ID,"he","Category screens string");
#endif
#if defined(__MMI_MULTITAP_PORTUGUESE__)||defined(__MMI_T9_PORTUGUESE__)||defined(__MMI_ZI_EU_PORTUGUESE__)||defined(__MMI_ZI_SA_PORTUGUESE__)||defined(__MMI_ZI_BZ_PORTUGUESE__) || defined(__MMI_CSTAR_PORTUGUESE__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_PORTUGUESE_STRING_ID,"PT","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_portuguese_STRING_ID,"pt","Category screens string");
                                            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_PORTUGUESE_STRING_ID,"Pt","Category screens string");
    #endif
#endif	
#if defined(__MMI_MULTITAP_INDONESIAN__)||defined(__MMI_ZI_INDONESIAN__)||defined(__MMI_T9_INDONESIAN__)   || defined(__MMI_CSTAR_INDONESIAN__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_INDONESIAN_STRING_ID,"ID","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_indonesian_STRING_ID,"id","Category screens string");
                                                
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_INDONESIAN_STRING_ID,"Id","Category screens string");
    #endif
#endif	
#if defined(__MMI_MULTITAP_CZECH__)||defined(__MMI_T9_CZECH__)||defined(__MMI_ZI_CZECH__) || defined(__MMI_CSTAR_CZECH__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_CZECH_STRING_ID,"CZ","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_czech_STRING_ID,"cz","Category screens string");
                                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_CZECH_STRING_ID,"Cz","Category screens string");
    #endif
#endif	
#if defined(__MMI_MULTITAP_MALAY__)||defined(__MMI_ZI_MALAY__)||defined(__MMI_T9_MALAY__) || defined(__MMI_CSTAR_MALAY__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_MALAY_STRING_ID,"MS","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_malay_STRING_ID,"ms","Category screens string");
                                                        
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_MALAY_STRING_ID,"Ms","Category screens string");
    #endif
#endif	
#if defined(__MMI_MULTITAP_VIETNAMESE__)||defined(__MMI_ZI_VIETNAMESE__)||defined(__MMI_T9_VIETNAMESE__)   || defined(__MMI_CSTAR_VIETNAMESE__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_VIETNAMESE_STRING_ID,"VI","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_vietnamese_STRING_ID,"vi","Category screens string");
                                                            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_VIETNAMESE_STRING_ID,"Vi","Category screens string");
    #endif
#endif	
#if defined(__MMI_MULTITAP_FINNISH__)||defined(__MMI_T9_FINNISH__)||defined(__MMI_ZI_FINNISH__) || defined(__MMI_CSTAR_FINNISH__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_FINNISH_STRING_ID,"FI","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_finnish_STRING_ID,"fi","Category screens string");
                                                                
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_FINNISH_STRING_ID,"Fi","Category screens string");
    #endif
#endif
#if  defined(__MMI_CSTAR_HINGLISH__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_HINGLISH_STRING_ID,"HG","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_hinglish_STRING_ID,"hg","Category screens string");
#endif	

#if defined(__MMI_MULTITAP_HUNGARIAN__)||defined(__MMI_T9_HUNGARIAN__)||defined(__MMI_ZI_HUNGARIAN__)  || defined(__MMI_CSTAR_HUNGARIAN__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_HUNGARIAN_STRING_ID,"HG","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_hungarian_STRING_ID,"hg","Category screens string");
                                                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_HUNGARIAN_STRING_ID,"Hg","Category screens string");
    #endif
#endif	
#if defined(__MMI_MULTITAP_ARABIC__)||defined(__MMI_T9_ARABIC__) || defined(__MMI_ZI_ARABIC__)||defined(__MMI_CSTAR_ARABIC__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_ARABIC_STRING_ID,"AR","Category screens string");
#endif	
#if defined(__MMI_LANG_ARABIC__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_ARABIC_NUMERIC_STRING_ID,"AR 123","Arabic Numeric");
#endif	
#if defined(__MMI_MULTITAP_PERSIAN__) || defined(__MMI_ZI_PERSIAN__)|| defined(__MMI_CSTAR_PERSIAN__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_PERSIAN_STRING_ID,"FA","Category screens string");
#endif	

#if defined(__MMI_MULTITAP_URDU__) || defined(__MMI_ZI_URDU__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_URDU_STRING_ID,"UR","Category screens string");
#endif	

#if defined(__MMI_MULTITAP_HINDI__)||defined(__MMI_T9_HINDI__) || defined(__MMI_ZI_HINDI__)||defined(__MMI_CSTAR_HINDI__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_HINDI_STRING_ID,"HI","Category screens string");
#endif
#if defined(__MMI_MULTITAP_MARATHI__) || defined(__MMI_ZI_MARATHI__)||defined(__MMI_T9_MARATHI__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_MARATHI_STRING_ID,"MR","Category screens string");
#endif
#if defined(__MMI_MULTITAP_TAMIL__) || defined(__MMI_ZI_TAMIL__)||defined(__MMI_T9_TAMIL__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_TAMIL_STRING_ID,"TA","Category screens string");
#endif
#if defined(__MMI_MULTITAP_BENGALI__) || defined(__MMI_ZI_BENGALI__)||defined(__MMI_T9_BENGALi__)  
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_BENGALI_STRING_ID,"BN","Category screens string");
#endif
#if defined(__MMI_MULTITAP_ASSAMESE__)||defined(__MMI_T9_ASSAMESE__)   
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_ASSAMESE_STRING_ID,"AS","Category screens string");
#endif
#if defined(__MMI_MULTITAP_PUNJABI__) || defined(__MMI_ZI_PUNJABI__)||defined(__MMI_T9_PUNJABI__)   
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_PUNJABI_STRING_ID,"PA","Category screens string");
#endif
#if defined(__MMI_MULTITAP_TELUGU__) || defined(__MMI_ZI_TELUGU__)||defined(__MMI_T9_TELUGU__) 
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_TELUGU_STRING_ID,"TE","Category screens string");
#endif

#if defined(__MMI_MULTITAP_KANNADA__) || defined(__MMI_ZI_KANNADA__) ||defined(__MMI_T9_KANNADA__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_KANNADA_STRING_ID,"KN","Category screens string");
#endif

#if defined(__MMI_MULTITAP_MALAYALAM__) || defined(__MMI_ZI_MALAYALAM__) ||defined(__MMI_T9_MALAYALAM__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_MALAYALAM_STRING_ID,"ML","Category screens string");
#endif

#if defined(__MMI_MULTITAP_GUJARATI__) || defined(__MMI_ZI_GUJARATI__) ||defined(__MMI_T9_GUJARATI__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_GUJARATI_STRING_ID,"GU","Category screens string");
#endif
#if defined(__MMI_MULTITAP_ORIYA__) || defined(__MMI_ZI_ORIYA__)||defined(__MMI_T9_ORIYA__) 
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_ORIYA_STRING_ID,"OR","Category screens string");
#endif

#if defined(__MMI_MULTITAP_NORWEGIAN__)||defined(__MMI_T9_NORWEGIAN__)|| defined(__MMI_ZI_NORWEGIAN__) || defined(__MMI_CSTAR_NORWEGIAN__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_NORWEGIAN_STRING_ID,"NO","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_norwegian_STRING_ID,"no","Category screens string");
                                                                        
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_NORWEGIAN_STRING_ID,"No","Category screens string");
    #endif
#endif
#if defined(__MMI_MULTITAP_SLOVAK__)||defined(__MMI_T9_SLOVAK__)||defined(__MMI_ZI_SLOVAK__) || defined(__MMI_CSTAR_SLOVAKIAN__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_SLOVAK_STRING_ID,"SK","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_slovak_STRING_ID,"sk","Category screens string");
                                                                            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_SLOVAK_STRING_ID,"Sk","Category screens string");
    #endif
#endif
#if defined(__MMI_MULTITAP_DUTCH__)||defined(__MMI_ZI_DUTCH__)||defined(__MMI_T9_DUTCH__)   || defined(__MMI_CSTAR_DUTCH__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_DUTCH_STRING_ID,"NL","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_dutch_STRING_ID,"nl","Category screens string");
                                                                                
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_DUTCH_STRING_ID,"Nl","Category screens string");
    #endif
#endif
#if defined(__MMI_MULTITAP_SWEDISH__)||defined(__MMI_T9_SWEDISH__)||defined(__MMI_ZI_SWEDISH__) || defined(__MMI_CSTAR_SWEDISH__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_SWEDISH_STRING_ID,"SV","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_swedish_STRING_ID,"sv","Category screens string");
                                                                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_SWEDISH_STRING_ID,"Sv","Category screens string");
    #endif
#endif

#if defined(__MMI_MULTITAP_CROATIAN__)||defined(__MMI_T9_CROATIAN__)||defined(__MMI_ZI_CROATIAN__) || defined(__MMI_CSTAR_CROATIAN__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_CROATIAN_STRING_ID,"HR","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_croatian_STRING_ID,"hr","Category screens string");
                                                                                        
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_CROATIAN_STRING_ID,"Hr","Category screens string");
    #endif
#endif
#if defined(__MMI_MULTITAP_ROMANIAN__)||defined(__MMI_ZI_ROMANIAN__)||defined(__MMI_T9_ROMANIAN__) || defined(__MMI_CSTAR_ROMANIAN__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_ROMANIAN_STRING_ID,"RO","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_romanian_STRING_ID,"ro","Category screens string");
                                                                                            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_ROMANIAN_STRING_ID,"Ro","Category screens string");
    #endif
#endif
#if defined(__MMI_MULTITAP_SLOVENIAN__)||defined(__MMI_T9_SLOVENIAN__)||defined(__MMI_ZI_SLOVENIAN__) || defined(__MMI_CSTAR_SLOVENIAN__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_SLOVENIAN_STRING_ID,"SL","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_slovenian_STRING_ID,"sl","Category screens string");
                                                                                                
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_SLOVENIAN_STRING_ID,"Sl","Category screens string");
    #endif
#endif

#if defined(__MMI_MULTITAP_GREEK__)||defined(__MMI_T9_GREEK__)||defined(__MMI_ZI_GREEK__) || defined(__MMI_CSTAR_GREEK__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_GREEK_STRING_ID,"EL","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_greek_STRING_ID,"el","Category screens string");
                                                                                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_GREEK_STRING_ID,"El","Category screens string");
    #endif
#endif

#if defined(__MMI_MULTITAP_XHOSA__)||defined(__MMI_T9_XHOSA__)||defined(__MMI_ZI_XHOSA__) || defined(__MMI_CSTAR_XHOSA__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_U_XHOSA_STRING_ID,"XH","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_L_XHOSA_STRING_ID,"xh","Category screens string");
                                                                                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_XHOSA_STRING_ID,"Xh","Category screens string");
    #endif
#endif

#if defined(__MMI_MULTITAP_SWAHILI__)||defined(__MMI_T9_SWAHILI__)||defined(__MMI_ZI_SWAHILI__) || defined(__MMI_CSTAR_SWAHILI__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_U_SWAHILI_STRING_ID,"SW","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_L_SWAHILI_STRING_ID,"sw","Category screens string");
                                                                                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_SWAHILI_STRING_ID,"Sw","Category screens string");
    #endif
#endif

#if defined(__MMI_MULTITAP_AFRIKAANS__)||defined(__MMI_T9_AFRIKAANS__)||defined(__MMI_ZI_AFRIKAANS__) || defined(__MMI_CSTAR_AFRIKAANS__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_U_AFRIKAANS_STRING_ID,"AF","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_L_AFRIKAANS_STRING_ID,"af","Category screens string");
                                                                                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_AFRIKAANS_STRING_ID,"Af","Category screens string");
    #endif
#endif

#if defined(__MMI_MULTITAP_ZULU__)||defined(__MMI_T9_ZULU__)||defined(__MMI_ZI_ZULU__) || defined(__MMI_CSTAR_ZULU__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_U_ZULU_STRING_ID,"ZU","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_L_ZULU_STRING_ID,"zu","Category screens string");
                                                                                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_ZULU_STRING_ID,"Zu","Category screens string");
    #endif
#endif

#if defined(__MMI_MULTITAP_LITHUANIAN__)||defined(__MMI_T9_LITHUANIAN__)||defined(__MMI_ZI_LITHUANIAN__) || defined(__MMI_CSTAR_LITHUANIAN__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_U_LITHUANIAN_STRING_ID,"LT","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_L_LITHUANIAN_STRING_ID,"lt","Category screens string");
                                                                                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_LITHUANIAN_STRING_ID,"Lt","Category screens string");
    #endif
#endif

#if defined(__MMI_MULTITAP_LATVIAN__)||defined(__MMI_T9_LATVIAN__)||defined(__MMI_ZI_LATVIAN__) || defined(__MMI_CSTAR_LATVIAN__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_U_LATVIAN_STRING_ID,"LV","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_L_LATVIAN_STRING_ID,"lv","Category screens string");
                                                                                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_LATVIAN_STRING_ID,"Lv","Category screens string");
    #endif
#endif

#if defined(__MMI_MULTITAP_ESTONIAN__)||defined(__MMI_T9_ESTONIAN__)||defined(__MMI_ZI_ESTONIAN__) || defined(__MMI_CSTAR_ESTONIAN__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_U_ESTONIAN_STRING_ID,"ET","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_L_ESTONIAN_STRING_ID,"et","Category screens string");
                                                                                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_ESTONIAN_STRING_ID,"Et","Category screens string");
    #endif
#endif

#if defined(__MMI_MULTITAP_ALBANIAN__)||defined(__MMI_T9_ALBANIAN__)||defined(__MMI_ZI_ALBANIAN__) || defined(__MMI_CSTAR_ALBANIAN__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_U_ALBANIAN_STRING_ID,"SQ","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_L_ALBANIAN_STRING_ID,"sq","Category screens string");
                                                                                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_ALBANIAN_STRING_ID,"Sq","Category screens string");
    #endif
#endif

#if defined(__MMI_MULTITAP_ARMENIAN__)||defined(__MMI_T9_ARMENIAN__)||defined(__MMI_ZI_ARMENIAN__) || defined(__MMI_CSTAR_ARMENIAN__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_U_ARMENIAN_STRING_ID,"HY","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_L_ARMENIAN_STRING_ID,"hy","Category screens string");
                                                                                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_ARMENIAN_STRING_ID,"Hy","Category screens string");
    #endif
#endif

#if defined(__MMI_MULTITAP_GEORGIAN__)||defined(__MMI_T9_GEORGIAN__)||defined(__MMI_ZI_GEORGIAN__) || defined(__MMI_CSTAR_GEORGIAN__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_GEORGIAN_STRING_ID,"KA","Category screens string");
#endif

#if defined(__MMI_MULTITAP_MOLDOVAN__)||defined(__MMI_T9_MOLDOVAN__)||defined(__MMI_ZI_MOLDOVAN__) || defined(__MMI_CSTAR_MOLDOVAN__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_U_MOLDOVAN_STRING_ID,"MO","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_L_MOLDOVAN_STRING_ID,"mo","Category screens string");
                                                                                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_MOLDOVAN_STRING_ID,"Mo","Category screens string");
    #endif
#endif


#if defined(__MMI_IME_USER_DATABASE__) || defined(__MMI_CSTAR_USER_DICT__)
    ADD_APPLICATION_STRING2(STR_INPUT_METHOD_SPELL_WORD,"Spell Word","Cstar input method string");
    ADD_APPLICATION_STRING2(STR_INPUT_METHOD_WORD_ALREADY_EXISTS,"This word already exists","Input method string");
#endif /*defined(__MMI_CSTAR__)*/

#if defined(__MMI_IME_FTE_ENHANCE__) 
    ADD_APPLICATION_STRING2(STR_IME_PEN_INPUT_STYLE_VK_QWERTY,"QWERTY virtual keyboard","QWERTY virtual keyboard");
    ADD_APPLICATION_STRING2(STR_IME_PEN_INPUT_STYLE_VK_ALPHANUMERIC,"Alphanumeric virtual keyboard","Alphanumeric virtual keyboard");
    ADD_APPLICATION_STRING2(STR_IME_PEN_INPUT_STYLE_HW, "Handwriting","Handwriting");
    
#endif

//MTK add, Robin 1025
#ifdef __MMI_SUBLCD__
     ADD_APPLICATION_STRING2(STR_SUBLCD_CHI_SUNDAY,str_chinese_sunday,"#NO_TRANS# Day of week string for Sub LCD");
	ADD_APPLICATION_STRING2(STR_SUBLCD_CHI_MONDAY,str_chinese_monday,"#NO_TRANS# Day of week string for Sub LCD");
	ADD_APPLICATION_STRING2(STR_SUBLCD_CHI_TUESDAY,str_chinese_tuesday,"#NO_TRANS# Day of week string for Sub LCD");
	ADD_APPLICATION_STRING2(STR_SUBLCD_CHI_WEDNESDAY,str_chinese_wednesday,"#NO_TRANS# Day of week string for Sub LCD");
	ADD_APPLICATION_STRING2(STR_SUBLCD_CHI_THURSDAY,str_chinese_thursday,"#NO_TRANS# Day of week string for Sub LCD");
	ADD_APPLICATION_STRING2(STR_SUBLCD_CHI_FRIDAY,str_chinese_friday,"#NO_TRANS# Day of week string for Sub LCD");
	ADD_APPLICATION_STRING2(STR_SUBLCD_CHI_SATURDAY,str_chinese_saturday,"#NO_TRANS# Day of week string for Sub LCD");

     ADD_APPLICATION_STRING2(STR_SUBLCD_ENG_SUNDAY,str_english_sunday,"#NO_TRANS# Day of week string for Sub LCD");
	ADD_APPLICATION_STRING2(STR_SUBLCD_ENG_MONDAY,str_english_monday,"#NO_TRANS# Day of week string for Sub LCD");
	ADD_APPLICATION_STRING2(STR_SUBLCD_ENG_TUESDAY,str_english_tuesday,"#NO_TRANS# Day of week string for Sub LCD");
	ADD_APPLICATION_STRING2(STR_SUBLCD_ENG_WEDNESDAY,str_english_wednesday,"#NO_TRANS# Day of week string for Sub LCD");
	ADD_APPLICATION_STRING2(STR_SUBLCD_ENG_THURSDAY,str_english_thursday,"#NO_TRANS# Day of week string for Sub LCD");
	ADD_APPLICATION_STRING2(STR_SUBLCD_ENG_FRIDAY,str_english_friday,"#NO_TRANS# Day of week string for Sub LCD");
	ADD_APPLICATION_STRING2(STR_SUBLCD_ENG_SATURDAY,str_english_saturday,"#NO_TRANS# Day of week string for Sub LCD");
#endif /* #ifdef __MMI_SUBLCD__ */
//MTK end

#ifdef __MMI_DATE_TIME_IN_DIFF_LANG__
	ADD_APPLICATION_STRING2(STR_GUI_TIME_AM,"AM","String for AM");
	ADD_APPLICATION_STRING2(STR_GUI_TIME_PM,"PM","String for PM");

	ADD_APPLICATION_STRING2(STR_GUI_TIME_AM_ENG, "AM", "String for AM in English");
	ADD_APPLICATION_STRING2(STR_GUI_TIME_PM_ENG, "PM", "String for PM in English");
#endif /* __MMI_DATE_TIME_IN_DIFF_LANG__ */

	/*code ended vandana mehtani*/
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_ON_STRING_ID,"On","Category screens string");

#ifdef __MMI_SLIM_IMG_RES__
	ADD_APPLICATION_IMAGE2(WGUI_VOLUME_BG,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_BG.png","VOL BG");
	ADD_APPLICATION_IMAGE2(WGUI_VOLUME_FILL,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_FILL.png","VOL FILL");
#else /* __MMI_SLIM_IMG_RES__ */		
	ADD_APPLICATION_IMAGE2(WGUI_VOLUME_LEVEL1,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_SC01.png","VOL LEVEL1");
	ADD_APPLICATION_IMAGE2(WGUI_VOLUME_LEVEL2,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_SC02.png","VOL LEVEL2");
	ADD_APPLICATION_IMAGE2(WGUI_VOLUME_LEVEL3,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_SC03.png","VOL LEVEL3");
	ADD_APPLICATION_IMAGE2(WGUI_VOLUME_LEVEL4,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_SC04.png","VOL LEVEL4");
	ADD_APPLICATION_IMAGE2(WGUI_VOLUME_LEVEL5,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_SC05.png","VOL LEVEL5");
	ADD_APPLICATION_IMAGE2(WGUI_VOLUME_LEVEL6,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_SC06.png","VOL LEVEL6");
	ADD_APPLICATION_IMAGE2(WGUI_VOLUME_LEVEL7,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_SC07.png","VOL LEVEL7");
#endif /* __MMI_SLIM_IMG_RES__ */

#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
	ADD_APPLICATION_IMAGE2(WGUI_VOLUME_UP_UP_IMAGE_ID,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_up_up.png","Volume up button normal image");
	ADD_APPLICATION_IMAGE2(WGUI_VOLUME_UP_DOWN_IMAGE_ID,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_up_down.png","Volume up button pressed image");
	ADD_APPLICATION_IMAGE2(WGUI_VOLUME_UP_DISABLE_IMAGE_ID,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_up_up_dis.png","Volume up button disable image");
	ADD_APPLICATION_IMAGE2(WGUI_VOLUME_DOWN_UP_IMAGE_ID,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_down_up.png","Volume down button normal image");
	ADD_APPLICATION_IMAGE2(WGUI_VOLUME_DOWN_DOWN_IMAGE_ID,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_down_down.png","Volume down button pressed image");
	ADD_APPLICATION_IMAGE2(WGUI_VOLUME_DOWN_DISABLE_IMAGE_ID,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_down_up_dis.png","Volume down button disable image");
#endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */
	/*code ended vandana mehtani*/
#ifdef __MMI_FTE_SUPPORT__
    ADD_APPLICATION_IMAGE2(WGUI_SLIDE_CONTROL_BG_IMAGE_ID,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Valuemap\\\\MAP.9slice.png","Background for Slide Control");
    ADD_APPLICATION_IMAGE2(WGUI_SLIDE_CONTROL_FOCUSE_BG_IMAGE_ID,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Valuemap\\\\MAP_highlight.9slice.png","Background for Slide Control");
    ADD_APPLICATION_IMAGE2(WGUI_SLIDE_CONTROL_SI_IMAGE_ID,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Valuemap\\\\INDICATE.png","Slide Indicator image for Slide Control");
    ADD_APPLICATION_IMAGE2(WGUI_SLIDE_CONTROL_FOCUSE_SI_IMAGE_ID,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Valuemap\\\\INDICATE_highligh.png","Slide Indicator image for Slide Control");
#else /* __MMI_FTE_SUPPORT__ */
	ADD_APPLICATION_IMAGE2(WGUI_SLIDE_CONTROL_BG_IMAGE_ID,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Valuemap\\\\MAP.BMP","Background for Slide Control");
	ADD_APPLICATION_IMAGE2(WGUI_SLIDE_CONTROL_SI_IMAGE_ID,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Valuemap\\\\INDICATE.BMP","Slide Indicator image for Slide Control");
#endif /* __MMI_FTE_SUPPORT__ */


#ifdef SVG12_SUPPORT
	ADD_APPLICATION_IMAGE2(IMG_SVG_DEFAULT_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\svg_tiny_logo.svg","Icon for SVG loading");
#endif

    /* Dialing Screen */
#if defined(__MMI_TOUCH_DIAL_SCREEN__)

#ifdef __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__

#if !defined(__MMI_MAINLCD_320X480__) || defined(__MMI_FTE_SUPPORT__)
    ADD_APPLICATION_IMAGE2(IMG_DIALING_SCREEN, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\DUALMODE_TH_DIALING_SCREEN.BMP", "Image of Dialing Screen");
#endif /* !defined(__MMI_MAINLCD_320X480__) || defined(__MMI_FTE_SUPPORT__) */
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_0, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\TH_DIALING_KEY0.PNG", "Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_1, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\TH_DIALING_KEY1.PNG", "Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_2, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\TH_DIALING_KEY2.PNG", "Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_3, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\TH_DIALING_KEY3.PNG", "Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_4, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\TH_DIALING_KEY4.PNG", "Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_5, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\TH_DIALING_KEY5.PNG", "Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_6, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\TH_DIALING_KEY6.PNG", "Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_7, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\TH_DIALING_KEY7.PNG", "Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_8, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\TH_DIALING_KEY8.PNG", "Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_9, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\TH_DIALING_KEY9.PNG", "Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_HASH, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\TH_DIALING_KEY_HASH.PNG", "Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_STAR, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\TH_DIALING_KEY_STAR.PNG", "Image of Dialing Key");

#else   /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */

#if !defined(__MMI_MAINLCD_320X480__) || defined(__MMI_FTE_SUPPORT__)
    ADD_APPLICATION_IMAGE2(IMG_DIALING_SCREEN, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_SCREEN.BMP", "Image of Dialing Screen");
#endif /* !defined(__MMI_MAINLCD_320X480__) || defined(__MMI_FTE_SUPPORT__) */
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_0, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_KEY0.PNG", "Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_1, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_KEY1.PNG", "Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_2, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_KEY2.PNG", "Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_3, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_KEY3.PNG", "Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_4, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_KEY4.PNG", "Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_5, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_KEY5.PNG", "Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_6, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_KEY6.PNG", "Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_7, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_KEY7.PNG", "Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_8, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_KEY8.PNG", "Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_9, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_KEY9.PNG", "Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_HASH, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_KEY_HASH.PNG", "Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_STAR, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_KEY_STAR.PNG", "Image of Dialing Key");

#endif  /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */

#if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
#ifdef __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__

	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_PHB, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\DUALMODE_TH_DIALING_PHONEBOOK.PNG", "Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_CALL, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\DUALMODE_TH_DIALING_CALL.PNG", "Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_CALL_SLAVE, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\DUALMODE_TH_DIALING_CALL_SLAVE.PNG", "Image of Dialing Key");
#if !defined(__MMI_MAINLCD_320X480__) || defined(__MMI_FTE_SUPPORT__)
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_PHB_DISABLED, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\DUALMODE_TH_DIALING_PHONEBOOK_DISABLED.PNG", "Image of Disabled Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_CALL_DISABLED, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\DUALMODE_TH_DIALING_CALL_DISABLED.PNG", "Image of Disabled Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_CALL_SLAVE_DISABLED, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\DUALMODE_TH_DIALING_CALL_SLAVE_DISABLED.PNG", "Image of Dialing Key");
#endif /* defined(__MMI_MAINLCD_320X480__) || defined(__MMI_FTE_SUPPORT__) */

#else /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */

	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_PHB, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_PHONEBOOK.PNG", "Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_CALL, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_CALL.PNG", "Image of Dialing Key");
#if !defined(__MMI_MAINLCD_320X480__)
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_PHB_DISABLED, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_PHONEBOOK_DISABLED.PNG", "Image of Disabled Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_CALL_DISABLED, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_CALL_DISABLED.PNG", "Image of Disabled Dialing Key");
#endif /* defined(__MMI_MAINLCD_320X480__) */

#endif  /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
#endif /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ */

/* special touch dialing screen images for FTE */
#if defined(__MMI_FTE_SUPPORT__)

#if defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__)
#define DIALING_SCREEN_PATH     CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\"
#else /* defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__) */
#define DIALING_SCREEN_PATH     CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\"
#endif /* defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__) */

	ADD_APPLICATION_IMAGE(IMG_DIALING_KEY_0_DOWN,       DIALING_SCREEN_PATH"TH_DIALING_KEY0_down.png");
	ADD_APPLICATION_IMAGE(IMG_DIALING_KEY_1_DOWN,       DIALING_SCREEN_PATH"TH_DIALING_KEY1_down.PNG");
	ADD_APPLICATION_IMAGE(IMG_DIALING_KEY_2_DOWN,       DIALING_SCREEN_PATH"TH_DIALING_KEY2_down.PNG");
	ADD_APPLICATION_IMAGE(IMG_DIALING_KEY_3_DOWN,       DIALING_SCREEN_PATH"TH_DIALING_KEY3_down.PNG");
	ADD_APPLICATION_IMAGE(IMG_DIALING_KEY_4_DOWN,       DIALING_SCREEN_PATH"TH_DIALING_KEY4_down.PNG");
	ADD_APPLICATION_IMAGE(IMG_DIALING_KEY_5_DOWN,       DIALING_SCREEN_PATH"TH_DIALING_KEY5_down.PNG");
	ADD_APPLICATION_IMAGE(IMG_DIALING_KEY_6_DOWN,       DIALING_SCREEN_PATH"TH_DIALING_KEY6_down.PNG");
	ADD_APPLICATION_IMAGE(IMG_DIALING_KEY_7_DOWN,       DIALING_SCREEN_PATH"TH_DIALING_KEY7_down.PNG");
	ADD_APPLICATION_IMAGE(IMG_DIALING_KEY_8_DOWN,       DIALING_SCREEN_PATH"TH_DIALING_KEY8_down.PNG");
	ADD_APPLICATION_IMAGE(IMG_DIALING_KEY_9_DOWN,       DIALING_SCREEN_PATH"TH_DIALING_KEY9_down.PNG");
	ADD_APPLICATION_IMAGE(IMG_DIALING_KEY_HASH_DOWN,    DIALING_SCREEN_PATH"TH_DIALING_KEY_HASH_down.PNG");
	ADD_APPLICATION_IMAGE(IMG_DIALING_KEY_STAR_DOWN,    DIALING_SCREEN_PATH"TH_DIALING_KEY_STAR_down.PNG");

    ADD_APPLICATION_IMAGE(IMG_DIALING_KEY_BUTTON_UP,    DIALING_SCREEN_PATH"TH_DIALING_KEY.PNG");
	ADD_APPLICATION_IMAGE(IMG_DIALING_KEY_BUTTON_DOWN,  DIALING_SCREEN_PATH"TH_DIALING_KEY_DOWN.PNG");

#if defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)

#if defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__)
	ADD_APPLICATION_IMAGE(IMG_DIALING_KEY_PHB_BUTTON_UP,                DIALING_SCREEN_PATH"TH_DIALING_PHONEBOOK_KEY.png");
	ADD_APPLICATION_IMAGE(IMG_DIALING_KEY_PHB_BUTTON_DOWN,              DIALING_SCREEN_PATH"TH_DIALING_PHONEBOOK_KEY_DOWN.png");
	ADD_APPLICATION_IMAGE(IMG_DIALING_KEY_PHB_BUTTON_DISABLED,          DIALING_SCREEN_PATH"TH_DIALING_PHONEBOOK_KEY_DISABLED.png");
	ADD_APPLICATION_IMAGE(IMG_DIALING_KEY_CALL_BUTTON_UP,               DIALING_SCREEN_PATH"DUALMODE_TH_DIALING_CALL_KEY.png");
	ADD_APPLICATION_IMAGE(IMG_DIALING_KEY_CALL_BUTTON_DOWN,             DIALING_SCREEN_PATH"DUALMODE_TH_DIALING_CALL_KEY_DOWN.png");
	ADD_APPLICATION_IMAGE(IMG_DIALING_KEY_CALL_BUTTON_DISABLED,         DIALING_SCREEN_PATH"DUALMODE_TH_DIALING_CALL_KEY_DISABLED.png");
#else /* defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__) */
	ADD_APPLICATION_IMAGE(IMG_DIALING_KEY_PHB_BUTTON_UP,        DIALING_SCREEN_PATH"TH_DIALING_PHONEBOOK_KEY.png");
	ADD_APPLICATION_IMAGE(IMG_DIALING_KEY_PHB_BUTTON_DOWN,      DIALING_SCREEN_PATH"TH_DIALING_PHONEBOOK_KEY_DOWN.png");
	ADD_APPLICATION_IMAGE(IMG_DIALING_KEY_PHB_BUTTON_DISABLED,  DIALING_SCREEN_PATH"TH_DIALING_PHONEBOOK_KEY_DISABLED.png");
	ADD_APPLICATION_IMAGE(IMG_DIALING_KEY_CALL_BUTTON_UP,       DIALING_SCREEN_PATH"TH_DIALING_CALL_KEY.PNG");
	ADD_APPLICATION_IMAGE(IMG_DIALING_KEY_CALL_BUTTON_DOWN,     DIALING_SCREEN_PATH"TH_DIALING_CALL_KEY_DOWN.PNG");
	ADD_APPLICATION_IMAGE(IMG_DIALING_KEY_CALL_BUTTON_DISABLED, DIALING_SCREEN_PATH"TH_DIALING_CALL_KEY_DISABLED.PNG");
#endif /* defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__) */

#endif /* defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */

#endif /* defined(__MMI_FTE_SUPPORT__) */


#endif /* defined(__MMI_TOUCH_DIAL_SCREEN__) */

    /* Calling */
#if defined(__MMI_MAINLCD_320X480__)
    ADD_APPLICATION_IMAGE2(IMG_CALLING_BUTTON_UP, CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Answer\\\\answer_up.png", "");
    ADD_APPLICATION_IMAGE2(IMG_CALLING_BUTTON_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Answer\\\\answer_down.png", "");
    ADD_APPLICATION_IMAGE2(IMG_CALLING_BUTTON_DISABLE, CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Answer\\\\answer_disable.png", "");
#endif /* defined(__MMI_MAINLCD_320X480__) */

#ifdef __MMI_SCREEN_ROTATE__
	ADD_APPLICATION_IMAGE2(IMG_SCREEN_ROTATE_TITLE,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Horizontal\\\\Rotated_title.bmp","Image of rotated title");
	ADD_APPLICATION_IMAGE2(IMG_SCREEN_ROTATE_BACKGROUND,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Horizontal\\\\Rotated_bkgrnd.gif","Image of rotated background");	
	ADD_APPLICATION_IMAGE2(IMG_SCREEN_ROTATE_TOP_BG, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Horizontal\\\\rotate_top.bmp", "");
	ADD_APPLICATION_IMAGE2(IMG_SCREEN_ROTATE_BOTTOM_BG, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Horizontal\\\\rotate_bottom.bmp", "");
#endif 

#ifdef __MMI_TOUCH_SCREEN__
    #ifndef __LOW_COST_SUPPORT_COMMON__
	/* Wait long-press animation */
	ADD_APPLICATION_IMAGE2(IMG_PEN_WAITING_LONGPRESS,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Touch\\\\TH_LongPress.gif","Animation when pen is long-tapped");		
    #endif
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
	disableENFB = 1;
#endif

#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__)
#if defined(__MMI_MAINLCD_320X480__)

    /* Virtual keyboard */
    ADD_APPLICATION_IMAGE2(IMG_VKBD_STANDARD,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_STANDARD.PNG","Standard keyboard");	
    ADD_APPLICATION_IMAGE2(IMG_VKBD_EXTENDED,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_EXTENDED.PNG","Extended keyboard");	
    ADD_APPLICATION_IMAGE2(IMG_VKBD_TRAY,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_TRAY.PNG","Minimized keyboard ");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_NUM_TRAY,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_NUM_TRAY.png","Minimized keyboard ");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CHINESE_SYMBOL,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CHINESE_SYMBOL.png","Chinese symbol keyboard ");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_NUMBER,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_NUM.PNG","Number keyboard");
#ifdef __MMI_LANG_SM_CHINESE__
    ADD_APPLICATION_IMAGE2(IMG_VKBD_PINYIN,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_PINYIN.PNG","Pinyin keyboard");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_PINYIN_DISPAREA,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_PINYIN_DISPAREA.PNG","Display area of Pinyin keyboard");
#endif /* __MMI_LANG_SM_CHINESE__ */

#if defined(__MMI_LANG_KAZAKH__)
  ADD_APPLICATION_IMAGE2(IMG_VKBD_FARSI_HUNGARIAN_ARABICSYMBOL,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_HUNGARIAN_FARSI.PNG","Hungarian_Farsi keyboard");
#endif /* defined(__MMI_LANG_KAZAKH__)*/

#ifdef __MMI_LANG_TR_CHINESE__
    ADD_APPLICATION_IMAGE2(IMG_VKBD_BOPOMO,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_BOPOMO.PNG","Bopomo keyboard");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_BOPOMO_DISPAREA,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_BOPOMO_DISPAREA.PNG","Display area of Bopomo keyboard");
#endif /* __MMI_LANG_TR_CHINESE__ */

#if (defined( __MMI_LANG_BULGARIAN__) || defined(__MMI_LANG_RUSSIAN__) || defined(__MMI_LANG_UKRAINIAN__) || defined(__MMI_LANG_THAI__)|| defined(__MMI_LANG_SERBIAN__))
    ADD_APPLICATION_IMAGE2(IMG_VKBD_THAI,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_THAI.PNG","Cyrillic keyboard");
#endif /* __MMI_LANG_BULGARIAN__ */

#if defined(__MMI_LANG_ARABIC__) || defined(__MMI_LANG_URDU__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_ARABIC,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_Cyrillic.png","Arabic keyboard");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_FARSI_HUNGARIAN_ARABICSYMBOL,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_THAI.png","Arabic symbol keyboard");
#endif

#if defined(__MMI_LANG_VIETNAMESE__) || defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_SA_SPANISH__) || defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_CA_FRENCH__) || defined(__MMI_LANG_GERMAN__) || defined(__MMI_LANG_ITALIAN__) || \
	defined(__MMI_LANG_TURKISH__) || defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_SA_PORTUGUESE__) || defined(__MMI_LANG_POLISH__) || defined(__MMI_INDIC_ALG__)|| defined(__MMI_LANG_AZERBAIJANI__)|| \
	defined(__MMI_LANG_CATALAN__)|| defined(__MMI_LANG_HAUSA__)|| defined(__MMI_LANG_MACEDONIAN__)|| defined(__MMI_LANG_YORUBA__) || defined(__MMI_LANG_ICELANDIC__)|| defined(__MMI_LANG_BASQUE__)|| defined(__MMI_LANG_GALICIAN__)||\
        defined(__MMI_LANG_IGBO__)|| defined(__MMI_LANG_FILIPINO__)|| defined(__MMI_LANG_IRISH__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_EUROPEAN,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_European.png","Thai keyboard");
#endif

    /* add icon  */
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_NUM,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\123.png","icon for number vk");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_ABC,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\abc.png","icon for abc lowercase vk");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_CAP_ABC,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\ABCABC.png","icon for abc uppercase vk");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_EN_SYM,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\EnglishSymbol.png","icon for abc uppercase vk");

#if defined(__MMI_LANG_TR_CHINESE__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_BOPOMO,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\bopomo.png","Bopomo icon");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_TR_STROKE,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\tr_stroke.png","icon for tr stroke");
#endif
#if defined(__MMI_LANG_SM_CHINESE__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_PINYIN,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\piyin.png","pinyin icon");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_SM_STROKE,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\sm_stroke.png","icon for sm stroke");
#endif
#if defined(__MMI_LANG_HK_CHINESE__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_HK_STROKE,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\hk_stroke.png","icon for hk stroke");
#endif
#if defined(__MMI_LANG_TR_CHINESE__) || defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_HK_CHINESE__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_CH_SYM,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\ChineseSymbol.png","icon for Chinese symbol vk");
#endif
#if defined(__MMI_LANG_ARABIC__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_AR,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\AR.png","pinyin icon");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_AR_NUM,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\AR123.png","icon for sm stroke");
#endif
#if defined(__MMI_LANG_URDU__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_UR,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\UR.png","icon for Urdu vk");
#endif
#if defined(__MMI_LANG_BULGARIAN__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_BG,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\bg.png","icon for abc lowercase vk");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_CAP_BG,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\BGBG.png","icon for abc uppercase vk");
#endif
#if defined(__MMI_LANG_GERMAN__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_DE,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\de.png","icon for abc lowercase vk");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_CAP_DE,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\DEDE.png","icon for abc uppercase vk");
#endif
#if defined(__MMI_LANG_AZERBAIJANI__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_AZ,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\az.png","icon for Azerbaijani lowercase vk");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_CAP_AZ,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\AZAZ.png","icon for Azerbaijani uppercase vk");
#endif
#if defined(__MMI_LANG_CATALAN__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_CA,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\ca.png","icon for CATALAN lowercase vk");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_CAP_CA,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\CACA.png","icon for CATALAN uppercase vk");
#endif
#if defined(__MMI_LANG_HAUSA__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_HA,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\ha.png","icon for HAUSA lowercase vk");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_CAP_HA,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\HAHA.png","icon for HAUSA uppercase vk");
#endif
#if defined(__MMI_LANG_KAZAKH__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_KK,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\kk.png","icon for KAZAKH lowercase vk");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_CAP_KK,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\KKKK.png","icon for KAZAKH uppercase vk");
#endif
#if defined(__MMI_LANG_MACEDONIAN__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_MK,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\mk.png","icon for MACEDONIAN lowercase vk");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_CAP_MK,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\MKMK.png","icon for MACEDONIAN uppercase vk");
#endif
#if defined(__MMI_LANG_SESOTHO__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_ST,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\st.png","icon for SESOTHO lowercase vk");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_CAP_ST,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\STST.png","icon for SESOTHO uppercase vk");
#endif
#if defined(__MMI_LANG_TAGALOG__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_TL,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\tl.png","icon for TAGALOG lowercase vk");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_CAP_TL,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\TLTL.png","icon for TAGALOG uppercase vk");
#endif
#if defined(__MMI_LANG_YORUBA__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_YO,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\yo.png","icon for YORUBA lowercase vk");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_CAP_YO,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\YOYO.png","icon for YORUBA uppercase vk");
#endif
#if defined(__MMI_LANG_SERBIAN__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_SR,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\SR.png","icon for SERBIAN lowercase vk");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_CAP_SR,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\SRSR.png","icon for SERBIAN uppercase vk");
#endif
#if defined(__MMI_LANG_ICELANDIC__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_IS,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\is.png","icon for ICELANDIC lowercase vk");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_CAP_IS,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\ISIS.png","icon for ICELANDIC uppercase vk");
#endif
#if defined(__MMI_LANG_GALICIAN__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_GL,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\gl.png","icon for GALICIAN lowercase vk");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_CAP_GL,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\GLGL.png","icon for GALICIAN uppercase vk");
#endif
#if defined(__MMI_LANG_BASQUE__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_EU,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\eu.png","icon for BASQUE lowercase vk");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_CAP_EU,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\EUEU.png","icon for BASQUE uppercase vk");
#endif
#if defined(__MMI_LANG_IGBO__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_IG,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\ig.png","icon for IGBO lowercase vk");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_CAP_IG,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\IGIG.png","icon for IGBO uppercase vk");
#endif
#if defined(__MMI_LANG_FILIPINO__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_FIL,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\fil.png","icon for FILIPINO lowercase vk");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_CAP_FIL,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\FILFIL.png","icon for FILIPINO uppercase vk");
#endif
#if defined(__MMI_LANG_IRISH__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_IR,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\ga.png","icon for IRISH lowercase vk");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_CAP_IR,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\GAGA.png","icon for IRISH uppercase vk");
#endif
#if defined(__MMI_LANG_ALBANIAN__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_SQ,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\sq.png","icon for Albanian lowercase vk");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_CAP_SQ,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\SQSQ.png","icon for Albanian uppercase vk");
#endif


#if defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_SA_SPANISH__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_ES,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\es.png","icon for abc lowercase vk");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_CAP_ES,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\ESES.png","icon for abc uppercase vk");
#endif
#if defined(__MMI_LANG_HINDI__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_HI,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\HIHI.png","icon for hindi vk");
#endif
#if defined(__MMI_LANG_MARATHI__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_MA,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\MRMR.png","icon for marathi vk");
#endif
#if defined(__MMI_LANG_PUNJABI__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_PU,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\PAPA.png","icon for punjabi vk");
#endif
#if defined(__MMI_LANG_KANNADA__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_KN,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\KN.png","icon for kannada vk");
#endif
#if defined(__MMI_LANG_MALAYALAM__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_MALAYALAM,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\ML.png","icon for malayalam vk");
#endif
#if defined(__MMI_LANG_TAMIL__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_TA,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\TA.png","icon for tamil vk");
#endif
#if defined(__MMI_LANG_TELUGU__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_TE,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\TE.png","icon for telugu vk");
#endif
#if defined(__MMI_LANG_ORIYA__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_OR,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\OR.png","icon for oriya vk");
#endif
#if defined(__MMI_LANG_GUJARATI__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_GU,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\GU.png","icon for gujarati vk");
#endif
#if defined(__MMI_LANG_BENGALI__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_BE,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\BNBN.png","icon for bengali vk");
#endif
#if defined(__MMI_LANG_ASSAMESE__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_AS,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\AS.png","icon for assamese vk");
#endif
#if defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_CA_FRENCH__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_FR,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\fr.png","icon for abc lowercase vk");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_CAP_FR,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\FRFR.png","icon for abc uppercase vk");
#endif
#if defined(__MMI_LANG_ITALIAN__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_IT,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\it.png","icon for abc lowercase vk");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_CAP_IT,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\ITIT.png","icon for abc uppercase vk");
#endif
#if defined(__MMI_LANG_POLISH__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_PO,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\pl.png","icon for abc lowercase vk");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_CAP_PO,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\PLPL.png","icon for abc uppercase vk");
#endif
#if defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_SA_PORTUGUESE__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_PT,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\pt.png","icon for abc lowercase vk");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_CAP_PT,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\PTPT.png","icon for abc uppercase vk");
#endif
#if defined(__MMI_LANG_RUSSIAN__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_RU,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\ru.png","icon for abc lowercase vk");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_CAP_RU,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\RURU.png","icon for abc uppercase vk");
#endif
#if defined(__MMI_LANG_TURKISH__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_TR,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\tr.png","icon for abc lowercase vk");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_CAP_TR,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\TRTR.png","icon for abc uppercase vk");
#endif
#if defined(__MMI_LANG_UKRAINIAN__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_UK,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\uk.png","icon for abc lowercase vk");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_CAP_UK,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\UKUK.png","icon for abc uppercase vk");
#endif
#if defined(__MMI_LANG_VIETNAMESE__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_VI,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\vi.png","icon for abc lowercase vk");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_CAP_VI,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\VIVI.png","icon for abc uppercase vk");
#endif
#if defined(__MMI_LANG_MALAY__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_ML,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\ms.png","icon for abc lowercase vk");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_CAP_ML,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\MSMS.png","icon for abc uppercase vk");
#endif
#if defined(__MMI_LANG_INDONESIAN__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_ID,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\id.png","icon for abc lowercase vk");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_CAP_ID,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\IDID.png","icon for abc uppercase vk");
#endif
#if defined(__MMI_LANG_THAI__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_IM_ICON_TH,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\thai.png","icon for abc lowercase vk");
#endif
#if defined(__MMI_INDIC_VK__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_INDIC_SYMBPICKER,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_INDIC_SYMBPICKER.png","Custom key - SLIDE");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_INDIC_CAPSON,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_INDIC_CAPS_ON.png","Custom key - Caps ON");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_INDIC_CAPSOFF,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_INDIC_CAPS_OFF.png","Custom key - Caps OFF");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_INDIC_SYMBOLS,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_INDIC_SYMBOLS.png","Custom key - SYMBOLS");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_INDIC_BACK,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_INDIC_BACK.png","Custom key - BACK");   
#endif

    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_HIDE,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_HIDE.png","Custom key - Hide");

    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_HIDE_SMALL,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_HAND_SMALL.png","Custom key - Hide");

    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_SHOW,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_SHOW.png","Custom key - Show");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_SWITCH_KEYBOARD,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_KEYBOARD.png","Custom key - switch to big keyboard");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_SWITCH_HANDWRITING,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_HAND.png","Custom key - switch to multi-block handwriting");    
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_BACKSPACE,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_BAKSPACE.png","Custom key - Backspace");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_CAPSLOCK,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_CAPS.png","Custom key - Caps lock");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_SPACE,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_SPACE.png","Custom key - Space");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_SYMBPICKER,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_SYMBPICKER.png","Custom key - symbol picker");
#if defined(__MMI_VKBD_EUROPEAN_SUPPORT__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_EUROSYMB,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_EUROSYMB.png","Custom key - european symbol picker");
#endif
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_ENTER,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_ENTER.png","Custom key - Enter");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_BRACKET,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_BRACKET.png","Custom key - Bracket");


#else /* defined(__MMI_MAINLCD_320X480__) */

	/* Virtual keyboard */
	ADD_APPLICATION_IMAGE2(IMG_VKBD_STANDARD,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_STANDARD.PNG","Standard keyboard");	
	ADD_APPLICATION_IMAGE2(IMG_VKBD_EXTENDED,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_EXTENDED.PNG","Extended keyboard");	
	ADD_APPLICATION_IMAGE2(IMG_VKBD_TRAY,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_TRAY.PNG","Minimized keyboard ");
	ADD_APPLICATION_IMAGE2(IMG_VKBD_NUMBER,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_NUM.PNG","Number keyboard");
#ifdef __MMI_LANG_SM_CHINESE__
	ADD_APPLICATION_IMAGE2(IMG_VKBD_PINYIN,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_PINYIN.PNG","Pinyin keyboard");
	ADD_APPLICATION_IMAGE2(IMG_VKBD_PINYIN_DISPAREA,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_PINYIN_DISPAREA.PNG","Display area of Pinyin keyboard");
#endif /* __MMI_LANG_SM_CHINESE__ */
#ifdef __MMI_LANG_TR_CHINESE__
	ADD_APPLICATION_IMAGE2(IMG_VKBD_BOPOMO,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_BOPOMO.PNG","Bopomo keyboard");
	ADD_APPLICATION_IMAGE2(IMG_VKBD_BOPOMO_DISPAREA,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_BOPOMO_DISPAREA.PNG","Display area of Bopomo keyboard");
#endif /* __MMI_LANG_TR_CHINESE__ */

#if (defined(__MMI_LANG_CZECH__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_LITHUANIAN__)  || defined(__MMI_LANG_ESTONIAN__))
  ADD_APPLICATION_IMAGE2(IMG_VKBD_CZECH,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CZECH_SLOVAK.PNG","Czech_Slovak keyboard");
#endif /* (defined(__MMI_LANG_CZECH__) || defined(__MMI_LANG_SLOVAK__))*/
#ifdef __MMI_LANG_HEBREW__
  ADD_APPLICATION_IMAGE2(IMG_VKBD_HEBREW,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_HEBREW.PNG","Hebrew keyboard");
#endif /* __MMI_LANG_HEBREW__ */
#if (defined( __MMI_LANG_BULGARIAN__))
  ADD_APPLICATION_IMAGE2(IMG_VKBD_BULGARIAN,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_BULGARIAN.PNG","Bulgarian keyboard");
#endif /* __MMI_LANG_BULGARIAN__ */
#if (defined(__MMI_LANG_DANISH__) || defined(__MMI_LANG_NORWEGIAN__))
  ADD_APPLICATION_IMAGE2(IMG_VKBD_DANISH_NORWEGIAN,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_DANISH_NORWEGIAN.PNG","Danish_Norwegian keyboard");
#endif /* defined(__MMI_LANG_DANISH__)||defined(__MMI_LANG_NORWEGIAN__) */
#ifdef __MMI_LANG_GREEK__
  ADD_APPLICATION_IMAGE2(IMG_VKBD_GREEK,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_GREEK.PNG","Greek keyboard");
#endif /*__MMI_LANG_GREEK__*/
#if (defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_HUNGARIAN__)|| defined(__MMI_LANG_KAZAKH__) || defined(__MMI_LANG_ARABIC__) || defined(__MMI_LANG_ARMENIAN__)  || defined(__MMI_LANG_URDU__) || defined(__MMI_LANG_LATVIAN__))
  ADD_APPLICATION_IMAGE2(IMG_VKBD_FARSI_HUNGARIAN_ARABICSYMBOL,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_HUNGARIAN_FARSI.PNG","Hungarian_Farsi keyboard");
#endif /* defined(__MMI_LANG_PERSIAN__)||defined(__MMI_LANG_HUNGARIAN__)||defined(__MMI_LANG_ARABIC__) */
#ifdef __MMI_LANG_PERSIAN__
  ADD_APPLICATION_IMAGE2(IMG_VKBD_FARSI_SYMBOL,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_FARSI_SYMBOL.PNG","Farsi_Symbol keyboard");
#endif /*__MMI_LANG_PERSIAN__*/
#if (defined(__MMI_LANG_FINNISH__) || defined(__MMI_LANG_SWEDISH__))
  ADD_APPLICATION_IMAGE2(IMG_VKBD_FINNISH_SWEDISH,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_FINNISH_SWEDISH.PNG","Finnish_Swedish keyboard");
#endif /* defined(__MMI_LANG_FINNISH__)||defined(__MMI_LANG_SWEDISH__) */
#ifdef __MMI_LANG_VIETNAMESE__
  ADD_APPLICATION_IMAGE2(IMG_VKBD_VIETNAMESE,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_VIETNAMESE.PNG","Vietnamese keyboard");
#endif
#if defined(__MMI_LANG_ARABIC__) || defined(__MMI_LANG_GEORGIAN__)
  ADD_APPLICATION_IMAGE2(IMG_VKBD_ARABIC,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_ARABIC.PNG","Arabic keyboard");
#endif
#if defined(__MMI_LANG_THAI__)
  ADD_APPLICATION_IMAGE2(IMG_VKBD_THAI,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_THAI.PNG","Thai keyboard");
#endif
#if defined(__MMI_INDIC_VK_TAMIL__)
  ADD_APPLICATION_IMAGE2(IMG_VKBD_TAMIL,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_TAMIL.PNG","Tamil keyboard");
#endif
#if defined(__MMI_INDIC_VK_PUNJABI__) && defined (__MMI_MAINLCD_128X160__)
  ADD_APPLICATION_IMAGE2(IMG_VKBD_PUNJABI_128x160,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_PUNJABI_128x160.png","Punjabi keyboard for 128x160 layout 5");
#endif
#if defined(__MMI_LANG_UKRAINIAN__)
  ADD_APPLICATION_IMAGE2(IMG_VKBD_UKRAINIAN,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_UKRAINIAN.PNG","Ukrainian keyboard");
#endif

#if defined(__MMI_INDIC_VK__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_INDIC_SYMBPICKER,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_INDIC_SYMBPICKER.BMP","Custom key - SLIDE");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_INDIC_CAPSON,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_INDIC_CAPS_ON.BMP","Custom key - Caps ON");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_INDIC_CAPSOFF,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_INDIC_CAPS_OFF.BMP","Custom key - Caps OFF");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_INDIC_SYMBOLS,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_INDIC_SYMBOLS.BMP","Custom key - SYMBOLS");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_INDIC_BACK,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_INDIC_BACK.BMP","Custom key - BACK");   
#endif

    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_HIDE,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_HIDE.BMP","Custom key - Hide");

    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_HIDE_SMALL,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_HAND_SMALL.BMP","Custom key - Hide");

    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_SHOW,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_SHOW.BMP","Custom key - Show");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_SWITCH_KEYBOARD,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_KEYBOARD.BMP","Custom key - switch to big keyboard");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_SWITCH_HANDWRITING,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_HAND.BMP","Custom key - switch to multi-block handwriting");    
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_BACKSPACE,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_BAKSPACE.BMP","Custom key - Backspace");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_CAPSLOCK,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_CAPS.BMP","Custom key - Caps lock");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_SPACE,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_SPACE.BMP","Custom key - Space");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_SYMBPICKER,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_SYMBPICKER.BMP","Custom key - symbol picker");
#if defined(__MMI_VKBD_EUROPEAN_SUPPORT__)
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_EUROSYMB,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_EUROSYMB.BMP","Custom key - european symbol picker");
#endif
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_ENTER,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_ENTER.BMP","Custom key - Enter");
    ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_BRACKET,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_BRACKET.BMP","Custom key - Bracket");


#endif /* defined(defined(__MMI_MAINLCD_320X480__)) */
#endif


#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
	disableENFB = 0;
#endif


    #ifdef __MMI_VK_POPUP_HINT__ 
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__)

        ADD_APPLICATION_IMAGE2(IMG_VKBD_LARGE_ICON_BG_ZOOM_LEFT,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\vk_large_icon_left.png","virtual keyboard large icon - left arrow");
        ADD_APPLICATION_IMAGE2(IMG_VKBD_LARGE_ICON_BG_ZOOM_RIGHT,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\vk_large_icon_right.png","virtual keyboard large icon - right arrow");
#endif
    #endif /* __MMI_VK_POPUP_HINT__ */
#endif /* __MMI_TOUCH_SCREEN__ */

    ADD_APPLICATION_IMAGE2(IMG_SELECTOR_FILLER,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\selector_filler.bmp", "selector_filler - ");

#ifdef UI_SCROLLBAR_STYLE_3
	ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_BUTTON_UP,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style3\\\\button_up.pbm", "Scrollbar - ");
	ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_BUTTON_DOWN,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style3\\\\button_down.pbm", "Scrollbar - ");
	ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_V_BAR_TOP,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style3\\\\v_bar_top.pbm", "Scrollbar - ");
	ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_V_BAR_MIDDLE,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style3\\\\v_bar_middle.pbm", "Scrollbar - ");
	ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_V_BAR_BOTTOM,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style3\\\\v_bar_bottom.pbm", "Scrollbar - ");
	ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_H_BAR_LEFT,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style3\\\\h_bar_left.pbm", "Scrollbar - ");
	ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_H_BAR_MIDDLE,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style3\\\\h_bar_middle.pbm", "Scrollbar - ");
	ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_H_BAR_RIGHT,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style3\\\\h_bar_right.pbm", "Scrollbar - ");	
#endif /* UI_SCROLLBAR_STYLE_3 */
#ifdef UI_SCROLLBAR_STYLE_5
#ifdef __MMI_TOUCH_SCREEN__
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_BUTTON_UP,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5_touch\\\\button_up.bmp", "Scrollbar - ");
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_BUTTON_DOWN,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5_touch\\\\button_down.bmp", "Scrollbar - ");
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_BUTTON_UP_PRESSED,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5_touch\\\\button_up_pressed.bmp", "Scrollbar - ");
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_BUTTON_DOWN_PRESSED,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5_touch\\\\button_down_pressed.bmp", "Scrollbar - ");
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_V_BAR_TOP,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5_touch\\\\v_bar_top.bmp", "Scrollbar - ");
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_V_BAR_MIDDLE,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5_touch\\\\v_bar_middle.bmp", "Scrollbar - ");
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_V_BAR_BOTTOM,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5_touch\\\\v_bar_bottom.bmp", "Scrollbar - ");
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_V_BAR_BGD,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5_touch\\\\v_bar_bg.bmp", "Scrollbar - ");
    
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_BUTTON_LEFT,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5_touch\\\\button_left.bmp", "Scrollbar - ");
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_BUTTON_RIGHT,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5_touch\\\\button_right.bmp", "Scrollbar - ");
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_BUTTON_LEFT_PRESSED,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5_touch\\\\button_left_pressed.bmp", "Scrollbar - ");
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_BUTTON_RIGHT_PRESSED,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5_touch\\\\button_right_pressed.bmp", "Scrollbar - ");
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_H_BAR_LEFT,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5_touch\\\\h_bar_left.bmp", "Scrollbar - ");
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_H_BAR_MIDDLE,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5_touch\\\\h_bar_middle.bmp", "Scrollbar - ");
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_H_BAR_RIGHT,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5_touch\\\\h_bar_right.bmp", "Scrollbar - ");
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_H_BAR_BGD,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5_touch\\\\h_bar_bg.bmp", "Scrollbar - ");
#else
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_BUTTON_UP,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5\\\\button_up.bmp", "Scrollbar - ");
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_BUTTON_DOWN,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5\\\\button_down.bmp", "Scrollbar - ");
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_BUTTON_UP_PRESSED,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5\\\\button_up_pressed.bmp", "Scrollbar - ");
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_BUTTON_DOWN_PRESSED,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5\\\\button_down_pressed.bmp", "Scrollbar - ");
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_V_BAR_TOP,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5\\\\v_bar_top.bmp", "Scrollbar - ");
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_V_BAR_MIDDLE,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5\\\\v_bar_middle.bmp", "Scrollbar - ");
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_V_BAR_BOTTOM,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5\\\\v_bar_bottom.bmp", "Scrollbar - ");
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_V_BAR_BGD,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5\\\\v_bar_bg.bmp", "Scrollbar - ");
    
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_BUTTON_LEFT,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5\\\\button_left.bmp", "Scrollbar - ");
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_BUTTON_RIGHT,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5\\\\button_right.bmp", "Scrollbar - ");
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_BUTTON_LEFT_PRESSED,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5\\\\button_left_pressed.bmp", "Scrollbar - ");
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_BUTTON_RIGHT_PRESSED,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5\\\\button_right_pressed.bmp", "Scrollbar - ");
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_H_BAR_LEFT,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5\\\\h_bar_left.bmp", "Scrollbar - ");
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_H_BAR_MIDDLE,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5\\\\h_bar_middle.bmp", "Scrollbar - ");
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_H_BAR_RIGHT,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5\\\\h_bar_right.bmp", "Scrollbar - ");
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_H_BAR_BGD,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5\\\\h_bar_bg.bmp", "Scrollbar - ");
#endif
#endif /* UI_SCROLLBAR_STYLE_5 */


#if defined(UI_SCROLLBAR_STYLE_8)

    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_V_BAR_TOP,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Vodafone_Style\\\\ScrollROCK_Top.png", "Scrollbar - ");
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_V_BAR_MIDDLE,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Vodafone_Style\\\\ScrollROCK_MiddleBG.png", "Scrollbar - ");
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_V_BAR_BOTTOM,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Vodafone_Style\\\\ScrollROCK_Bottom.png", "Scrollbar - ");
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_V_BAR_BGD,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Vodafone_Style\\\\ScrollBG_Middle.png", "Scrollbar - ");

    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_V_BAR_BGD_TOP,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Vodafone_Style\\\\ScrollBG_TOP.png", "Scrollbar - ");
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_V_BAR_BGD_BOTTOM,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Vodafone_Style\\\\ScrollBG_Bottom.png", "Scrollbar - ");
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_V_BAR_INDICATOR,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Vodafone_Style\\\\ScrollROCK_MiddleDot.png", "Scrollbar - ");

    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_H_BAR_LEFT,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Vodafone_Style\\\\ScrollROCK_left_H.png", "Scrollbar - ");
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_H_BAR_MIDDLE,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Vodafone_Style\\\\ScrollROCK_MiddleBG_H.png", "Scrollbar - ");
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_H_BAR_RIGHT,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Vodafone_Style\\\\ScrollROCK_right_H.png", "Scrollbar - ");
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_H_BAR_BGD,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Vodafone_Style\\\\ScrollBG_Middle_H.png", "Scrollbar - ");

    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_H_BAR_BGD_LEFT,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Vodafone_Style\\\\ScrollBG_left_H.png", "Scrollbar - ");
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_H_BAR_BGD_RIGHT,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Vodafone_Style\\\\ScrollBG_right_H.png", "Scrollbar - ");
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_H_BAR_INDICATOR,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Vodafone_Style\\\\ScrollROCK_MiddleDot_H.png", "Scrollbar - ");

#endif /*defined(UI_SCROLLBAR_STYLE_8)*/


#if defined(UI_SCROLLBAR_STYLE_7)

    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_V_BAR_TOP,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\style7\\\\indicator_up.png", "Scrollbar - ");
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_V_BAR_MIDDLE,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\style7\\\\indicator_m.png", "Scrollbar - ");
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_V_BAR_BOTTOM,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\style7\\\\indicator_down.png", "Scrollbar - ");

    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_H_BAR_LEFT,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\style7\\\\indicator_hl.png", "Scrollbar - ");
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_H_BAR_MIDDLE,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\style7\\\\indicator_hm.png", "Scrollbar - ");
    ADD_APPLICATION_IMAGE2(IMG_SCROLLBAR_H_BAR_RIGHT,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\style7\\\\indicator_hr.png", "Scrollbar - ");

#endif /* UI_SCROLLBAR_STYLE_7 */

#if defined(__MMI_IME_FTE_ENHANCE__)
#if defined(__MMI_ZI__) || defined(__MMI_T9__) || defined(__MMI_CSTAR__)
    ADD_APPLICATION_IMAGE2(IMG_ID_IME_INDICATOR_BPMF, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Statusicons_PNG\\\\IME\\\\Bpmf.png","Icon for BOPOMOFO input method");
    ADD_APPLICATION_IMAGE2(IMG_ID_IME_INDICATOR_TR_STROKE, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Statusicons_PNG\\\\IME\\\\TR_Stroke.png","Icon for TR stroke input method");
    ADD_APPLICATION_IMAGE2(IMG_ID_IME_INDICATOR_PINYIN, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Statusicons_PNG\\\\IME\\\\Pinyin.png","Icon for Pinyin input method");
    ADD_APPLICATION_IMAGE2(IMG_ID_IME_INDICATOR_SM_STROKE, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Statusicons_PNG\\\\IME\\\\SM_Stroke.png","Icon for SM stroke input method");
#endif
#else
#if defined(__MMI_ZI__)
//MTK Elvis
	ADD_APPLICATION_IMAGE2(WGUI_ZI_EZITEXT_LOGO,CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\eZiText_N12px_col.bmp","Icon for eZiText");
	ADD_APPLICATION_IMAGE2(WGUI_ZI_EZITEXT_BPMF_LOGO,CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\TC_eZiText_Bopomofo_N12px_col.bmp","Icon for eZiText BPMF");
	ADD_APPLICATION_IMAGE2(WGUI_ZI_EZITEXT_PINYIN_LOGO,CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\SC_eZiText_Pinyin_N12px_col.bmp","Icon for eZiText Pinyin");
	ADD_APPLICATION_IMAGE2(WGUI_ZI_EZITEXT_SM_STROKE_LOGO,CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\SC_eZiText_Stroke_N12px_col.bmp","Icon for eZiText SC Stroke");
	ADD_APPLICATION_IMAGE2(WGUI_ZI_EZITEXT_TR_STROKE_LOGO,CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\TC_eZiText_Stroke_N12px_col.bmp","Icon for eZiText TC Stroke");
	ADD_APPLICATION_IMAGE2(WGUI_ZI_EZITEXT_HK_STROKE_LOGO,CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\HC_eZiText_Stroke_N12px_col.bmp","Icon for eZiText HC Stroke");    
//MTK end
#elif defined(__MMI_T9__)||defined(__MMI_ITAP__)||defined(__MMI_KA__) || defined(__MMI_CSTAR__)
//MTK Elvis IME input method indicators
#if (defined(__MMI_T9_TR_CHINESE__) && defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__)) || (defined(__MMI_CSTAR_TR_CHINESE__) && defined(__MMI_CSTAR_MULTITAP_PHONETIC_INPUT__))
	ADD_APPLICATION_IMAGE2(WGUI_IME_MULTITAP_BPMF_IMG,CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\Multitap BPMF.bmp","Icon for T9 multitap BPMF");
#endif
	ADD_APPLICATION_IMAGE2(WGUI_IME_MULTITAP_PINYIN_IMG,CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\Multiatp Pinyin.bmp","Icon for T9 multitap pinyin");
#if (defined(__MMI_T9_TR_CHINESE__) && defined(__MMI_T9_SMART_PHONETIC_INPUT__)) || (defined(__MMI_CSTAR_TR_CHINESE__) && defined(__MMI_CSTAR_SMART_PHONETIC_INPUT__))
	ADD_APPLICATION_IMAGE2(WGUI_IME_SMART_BPMF_IMG,CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\Smart BPMF.bmp","Icon for T9 smart BPMF");
#endif
	ADD_APPLICATION_IMAGE2(WGUI_IME_SMART_PINYIN_IMG,CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\Smart Pinyin.bmp","Icon for T9 smart pinyin");
	ADD_APPLICATION_IMAGE2(WGUI_IME_SM_STROKE_IMG,CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\Simplified Chinese stroke.bmp","Icon for T9 SC Stroke");
#if (defined(__MMI_T9_TR_CHINESE__) && defined(__MMI_T9_STROKE_INPUT__)) || (defined(__MMI_CSTAR_TR_CHINESE__) && defined(__MMI_CSTAR_STROKE_INPUT__))||(defined(__MMI_T9_HK_CHINESE__) && defined(__MMI_T9_STROKE_INPUT__))
	ADD_APPLICATION_IMAGE2(WGUI_IME_TR_STROKE_IMG,CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\Traditonal Chinese stroke.bmp","Icon for T9 TC Stroke");
#endif
//MTK end
#endif
#endif /* #if defined(__MMI_IME_FTE_ENHANCE__) */
	

#if defined(__MMI_IME_FTE_ENHANCE__)
    ADD_APPLICATION_IMAGE2(WGUI_IME_SMART_ENGLISH_IMG,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Statusicons_PNG\\\\IME\\\\Smartamb.png","Icon for smart input modes");
    ADD_APPLICATION_IMAGE2(WGUI_INPUT_INFORMATION_ICON1,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Statusicons_PNG\\\\IME\\\\MUT.png","Icon for Multitap input mode");
    ADD_APPLICATION_IMAGE2(IMG_ID_IME_INDICATOR_BG,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Statusicons_PNG\\\\IME\\\\Background.9slice.png","IME indicator background");
#else
    ADD_APPLICATION_IMAGE2(WGUI_IME_SMART_ENGLISH_IMG,CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\Smartamb.bmp","Icon for smart English");
    ADD_APPLICATION_IMAGE2(WGUI_INPUT_INFORMATION_ICON1,CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\MUT.BMP","Icon for Multitap input mode");
#endif
    
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    ADD_APPLICATION_IMAGE2(IMG_IME_QWERTY_FN, CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\SI_fn.bmp", "Indicator of FN on");
    ADD_APPLICATION_IMAGE2(IMG_IME_QWERTY_FN_LOCK, CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\SI_Afn.bmp", "Indicator of FN lock");
    ADD_APPLICATION_IMAGE2(IMG_IME_QWERTY_SHIFT, CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\SI_shift.bmp", "Indicator of Shift on");
    ADD_APPLICATION_IMAGE2(IMG_IME_QWERTY_SHIFT_LOCK, CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\SI_Ashift.bmp", "Indicator of Shift lock");
#endif

#ifdef __MMI_FTE_SUPPORT__
    ADD_APPLICATION_IMAGE2(IMG_INLINE_ML_HIGHLIGHT_BG, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\edit\\\\Multiline_editor_highlight.9slice.png", "Inline multiline highlight background");
    ADD_APPLICATION_IMAGE2(IMG_INLINE_ML_NORMAL_BG, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\edit\\\\Multiline_editor_normal.9slice.png", "Inline multiline normal background");

    ADD_APPLICATION_IMAGE2(IMG_INLINE_DISPLAY_ONLY_HIGHLIGHT_BG, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\edit\\\\inline_button_highlight_up.9slice.png", "Inline displayonly highlight background");
    ADD_APPLICATION_IMAGE2(IMG_INLINE_DISPLAY_ONLY_NORMAL_BG, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\edit\\\\inline_button_normal_up.9slice.png", "Inline displayonly normal background");
#endif

	ADD_APPLICATION_IMAGE2(IMG_H_SELECT_LEFT,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\SELECT_LEFT.pbm", "Left arrow in horizontal select");
	ADD_APPLICATION_IMAGE2(IMG_H_SELECT_RIGHT,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\SELECT_RIGHT.pbm", "Right arrow in horizontal select");
	ADD_APPLICATION_IMAGE2 (RIGHT_RED_ARROW, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\PV_ARR.pbm","right arrow");
	ADD_APPLICATION_IMAGE2 (LEFT_RED_ARROW, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\PV_ARL.pbm","left arrow");

#if defined(__MMI_FTE_SUPPORT__)
    ADD_APPLICATION_IMAGE2 (LEFT_ARROW_DOWN, CUST_IMG_PATH"\\\\MAINLCD\\\\WorldClock\\\\TH_WDownL.png","WorldClock left arrow down");
    ADD_APPLICATION_IMAGE2 (LEFT_ARROW_UP, CUST_IMG_PATH"\\\\MAINLCD\\\\WorldClock\\\\TH_WUpL.png","WorldClock left arrow up");
    ADD_APPLICATION_IMAGE2 (RIGHT_ARROW_DOWN, CUST_IMG_PATH"\\\\MAINLCD\\\\WorldClock\\\\TH_WDownR.png","WorldClock right arrow down");
    ADD_APPLICATION_IMAGE2 (RIGHT_ARROW_UP, CUST_IMG_PATH"\\\\MAINLCD\\\\WorldClock\\\\TH_WDUpR.png","WorldClock right arrow up");
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined ( __MMI_MAINLCD_320X480__)
	ADD_APPLICATION_IMAGE2 (LEFT_ARROW_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\LEFT_ARROW_DOWN.pbm","LEFT_ARROW_DOWN");
	ADD_APPLICATION_IMAGE2 (LEFT_ARROW_UP, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\LEFT_ARROW_UP.pbm","LEFT_ARROW_UP");
	ADD_APPLICATION_IMAGE2 (RIGHT_ARROW_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\RIGHT_ARROW_DOWN.pbm","RIGHT_ARROW_DOWN");
	ADD_APPLICATION_IMAGE2 (RIGHT_ARROW_UP, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\RIGHT_ARROW_UP.pbm","RIGHT_ARROW_UP");
#endif
    ADD_APPLICATION_IMAGE2(IMG_LEFT_DISABLED_ARROW, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\CascadingMenu\\\\Arrow_Disable_L.png","LEFT_ARROW_DOWN");
    ADD_APPLICATION_IMAGE2(IMG_RIGHT_DISABLED_ARROW, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\CascadingMenu\\\\Arrow_Disable_R.png","LEFT_ARROW_UP");

#ifndef __MMI_TOUCH_DIAL_SCREEN__
#if defined( __MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__)
	//ADD_APPLICATION_IMAGE2 (IMG_POPUP_TITLE, CUST_IMG_PATH"\\\\MainLCD\\\\WarningPage\\\\PopUpPage\\\\PP_TB.BMP","Background image of popup screen");
{
    S32 force_type = AUTO_TYPE;

    /* force ABM to speed up 6223 + QVGA */
#if (defined(MT6223) || defined(MT6223P)) && defined(__MMI_MAINLCD_240X320__)
    force_type = FORCE_ABM;
#endif

#if !defined(__MMI_TOUCH_DIAL_SCREEN__)
	ADD_APPLICATION_IMAGE_TYPE(IMG_DIALING_SCREEN_BG_UP,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\idle_top.png", "Image of Dialing Screen background", FALSE, force_type);
	ADD_APPLICATION_IMAGE_TYPE(IMG_DIALING_SCREEN_BG_DOWN,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\idle_botton.png", "Image of Dialing Screen background", FALSE, force_type);
	ADD_APPLICATION_IMAGE_TYPE(IMG_DIALING_SCREEN_BG_LEFT,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\idle_left.png", "Image of Dialing Screen background", FALSE, force_type);
	ADD_APPLICATION_IMAGE_TYPE(IMG_DIALING_SCREEN_BG_RIGHT,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\idle_right.png", "Image of Dialing Screen background", FALSE, force_type);
#endif /* !defined(__MMI_TOUCH_DIAL_SCREEN__) */
}
#endif
#endif

//PMT VIKAS START 20050707 	
#ifdef __MMI_UI_DALMATIAN_EDITOR__
	ADD_APPLICATION_IMAGE2 (IMG_EDITOR_DALMATIAN,
								CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\Dalmatian\\\\EDITOR_DALMATIAN_IMAGE.gif",
								"Image for editor");
	ADD_APPLICATION_IMAGE2 (IMG_EDITOR_DALMATIAN_SMALL,
								CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\Dalmatian\\\\EDITOR_DALMATIAN_IMAGE_SMALL.gif",
								"Image for editor");
#endif
//PMT VIKAS END 20050707
/* #ifdef UI_SOFTKEY_STYLE_2 */
	ADD_APPLICATION_IMAGE2 (IMG_SOFTKEY_BAR, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\softkey\\\\softkey.pbm","Background image of SOFTKEY");
/* #endif */
#ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
	ADD_APPLICATION_STRING2 (STR_GLOBAL_LOGO, "TCL","TCL");
	ADD_APPLICATION_IMAGE2 (IMG_SUBLCD_ANALOG_CLOCK, CUST_IMG_PATH"\\\\SubLCD\\\\Active\\\\SB_Analog.gif","Background image of sublcd analog clock");
#endif
#ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
	ADD_APPLICATION_IMAGE2(SOUND_EFFECT_AUDIO_EQ_BG, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\AudioEqualizer\\\\EQ_BG.gif","Audio Equalizer Setting Editing Screen");
	ADD_APPLICATION_IMAGE2(SOUND_EFFECT_AUDIO_EQ_ACTIVE_BAR, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\AudioEqualizer\\\\EQ_BAR.bmp","Activated Bar Image For Audio Equalizer Setting Editing Screen");
	ADD_APPLICATION_IMAGE2(SOUND_EFFECT_AUDIO_EQ_VAL_INDICATOR, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\AudioEqualizer\\\\EQ_indicator.bmp","Level Indicator For Audio Equalizer Setting Editing Screen");
#endif
#ifdef __MMI_TOUCH_SCREEN__
	//ADD_APPLICATION_IMAGE2 (IMG_PASSWD_KEYBOARD, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Touch\\\\pim.bmp","keyboard for password input");
	//ADD_APPLICATION_IMAGE2 (IMG_PASSWD_KEYBOARD_PRESS, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Touch\\\\pim_h.bmp","pressed keyboard for password input");
#endif	
#if (defined __MMI_TOUCH_SCREEN__) && (defined __MMI_WGUI_CSK_ENABLE__)
	ADD_APPLICATION_IMAGE2(IMG_CSK_DIAL_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Touch\\\\Call.bmp","icons used in csk to make call");
#endif

#ifdef __MMI_CALENDAR__
//PMT VIKAS START 20050913
#ifdef __MMI_UI_DALMATIAN_CALENDAR__ 
	ADD_APPLICATION_IMAGE2(IMG_CALENDAR_JAN,CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\DALMATIAN\\\\JAN.BMP","BackGround image JAN.");
#else
#ifdef __MMI_OP01_DM_PROFILE_SETTING__
/* under construction !*/
#endif
//PMT VIKAS START 20050913
#endif
#ifdef __MMI_UI_DALMATIAN_CALENDAR__ 
	ADD_APPLICATION_IMAGE2(DALMATIAN_WEEK_HIGHLIGHTER_IMAGE_ID_JAN,CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\DALMATIAN\\\\WEEK\\\\JAN.gif","Box image JAN.");
	ADD_APPLICATION_IMAGE2(DALMATIAN_WEEK_HIGHLIGHTER_IMAGE_ID_FEB,CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\DALMATIAN\\\\WEEK\\\\FEB.gif","Box image FEB.");
	ADD_APPLICATION_IMAGE2(DALMATIAN_WEEK_HIGHLIGHTER_IMAGE_ID_MAR,CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\DALMATIAN\\\\WEEK\\\\MARCH.gif","Box image MAR.");
	ADD_APPLICATION_IMAGE2(DALMATIAN_WEEK_HIGHLIGHTER_IMAGE_ID_APR,CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\DALMATIAN\\\\WEEK\\\\APRIL.gif","Box image APR.");
	ADD_APPLICATION_IMAGE2(DALMATIAN_WEEK_HIGHLIGHTER_IMAGE_ID_MAY,CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\DALMATIAN\\\\WEEK\\\\MAY.gif","Box image MAY.");
	ADD_APPLICATION_IMAGE2(DALMATIAN_WEEK_HIGHLIGHTER_IMAGE_ID_JUN,CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\DALMATIAN\\\\WEEK\\\\JUNE.gif","Box image JUN.");
	ADD_APPLICATION_IMAGE2(DALMATIAN_WEEK_HIGHLIGHTER_IMAGE_ID_JUL,CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\DALMATIAN\\\\WEEK\\\\JULY.gif","Box image JUL.");
	ADD_APPLICATION_IMAGE2(DALMATIAN_WEEK_HIGHLIGHTER_IMAGE_ID_AUG,CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\DALMATIAN\\\\WEEK\\\\AUG.gif","Box image AUG.");
	ADD_APPLICATION_IMAGE2(DALMATIAN_WEEK_HIGHLIGHTER_IMAGE_ID_SEP,CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\DALMATIAN\\\\WEEK\\\\SEP.gif","Box image SEP.");
	ADD_APPLICATION_IMAGE2(DALMATIAN_WEEK_HIGHLIGHTER_IMAGE_ID_OCT,CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\DALMATIAN\\\\WEEK\\\\OCT.gif","Box image OCT.");
	ADD_APPLICATION_IMAGE2(DALMATIAN_WEEK_HIGHLIGHTER_IMAGE_ID_NOV,CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\DALMATIAN\\\\WEEK\\\\NOV.gif","Box image NOV.");
	ADD_APPLICATION_IMAGE2(DALMATIAN_WEEK_HIGHLIGHTER_IMAGE_ID_DEC,CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\DALMATIAN\\\\WEEK\\\\DEC.gif","Box image DEC.");
#endif
//PMT VIKAS END 20050913
#ifdef __MMI_TOUCH_SCREEN__
#if defined(__MMI_MAINLCD_320X480__) || defined(__MMI_FTE_SUPPORT__)
	ADD_APPLICATION_IMAGE2 (CAL_LEFT_ARROW_UP_IMAGE, CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_upL.png","calendar title left arrow");
	ADD_APPLICATION_IMAGE2 (CAL_LEFT_ARROW_DOWN_IMAGE, CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_downL.png","calendar title left arrow down");
	ADD_APPLICATION_IMAGE2 (CAL_RIGHT_ARROW_UP_IMAGE, CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_upR.png","calendar title right arrow");
	ADD_APPLICATION_IMAGE2 (CAL_RIGHT_ARROW_DOWN_IMAGE, CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_downR.png","calendar title right arrow down");
#else /* __MMI_MAINLCD_320X480__ */
	ADD_APPLICATION_IMAGE2 (CAL_LEFT_ARROW_UP_IMAGE, CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_upL.bmp","calendar title left arrow");
	ADD_APPLICATION_IMAGE2 (CAL_LEFT_ARROW_DOWN_IMAGE, CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_downL.bmp","calendar title left arrow down");
	ADD_APPLICATION_IMAGE2 (CAL_RIGHT_ARROW_UP_IMAGE, CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_upR.bmp","calendar title right arrow");
	ADD_APPLICATION_IMAGE2 (CAL_RIGHT_ARROW_DOWN_IMAGE, CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_downR.bmp","calendar title right arrow down");
#endif /* __MMI_MAINLCD_320X480__ */
#ifdef __MMI_FTE_SUPPORT__
    ADD_APPLICATION_IMAGE2 (IMG_CALENDAR_HORIZONTAL_STRING_BG, CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Date_bar.png","calendar title left arrow");
	ADD_APPLICATION_IMAGE2 (IMG_CALENDAR_HORIZONTAL_SELECT_BG, CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Background.png","calendar title left arrow down");
	ADD_APPLICATION_IMAGE2 (MENSTURAL_LEFT_ARROW_UP_IMAGE, CUST_IMG_PATH"\\\\MainLCD\\\\Health\\\\Left_arrow_normal.png","title left arrow");
	ADD_APPLICATION_IMAGE2 (MENSTURAL_LEFT_ARROW_DOWN_IMAGE, CUST_IMG_PATH"\\\\MainLCD\\\\Health\\\\Left_arrow_highlight.png","title left arrow down");
	ADD_APPLICATION_IMAGE2 (MENSTURAL_RIGHT_ARROW_UP_IMAGE, CUST_IMG_PATH"\\\\MainLCD\\\\Health\\\\Right_arrow_normal.png","title right arrow");
	ADD_APPLICATION_IMAGE2 (MENSTURAL_RIGHT_ARROW_DOWN_IMAGE, CUST_IMG_PATH"\\\\MainLCD\\\\Health\\\\Right_arrow_highlight.png","title right arrow down");
#endif /* __MMI_FTE_SUPPORT__ */
#endif /* __MMI_TOUCH_SCREEN__ */
#endif /*__MMI_CALENDAR__*/


//PMT HIMANSHU START 20050721
#ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
	ADD_APPLICATION_STRING2(STR_IDLESCREEN_SUNDAY, "Sunday", "String Sunday shown in Techno Idlescreen Bar");
	ADD_APPLICATION_STRING2(STR_IDLESCREEN_MONDAY, "Monday", "String Sunday shown in Techno Idlescreen Bar");
	ADD_APPLICATION_STRING2(STR_IDLESCREEN_TUESDAY, "Tuesday", "String Sunday shown in Techno Idlescreen Bar");
	ADD_APPLICATION_STRING2(STR_IDLESCREEN_WEDNESDAY, "Wednesday", "String Sunday shown in Techno Idlescreen Bar");
	ADD_APPLICATION_STRING2(STR_IDLESCREEN_THURSDAY, "Thursday", "String Sunday shown in Techno Idlescreen Bar");
	ADD_APPLICATION_STRING2(STR_IDLESCREEN_FRIDAY, "Friday", "String Sunday shown in Techno Idlescreen Bar");
	ADD_APPLICATION_STRING2(STR_IDLESCREEN_SATURDAY, "Saturday", "String Sunday shown in Techno Idlescreen Bar");
	/* 070306 Alpha layer Start */
	//ADD_APPLICATION_IMAGE2(IMG_TECHNO_IDLESCREEN_BAR, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\IDLESCREEN_BAR.gif", " Techno Idlescreen Bar Image");
	ADD_APPLICATION_IMAGE2(IMG_TECHNO_ANALOG_CLOCK, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\ANALOG_CLOCK.png", " Techno Idlescreen Analog Clock Image");
	ADD_APPLICATION_IMAGE2(IMG_TECHNO_DIGITAL_CLOCK, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\DIGITAL_CLOCK.png", " Techno Idlescreen Digital Clock Image");
#ifdef __MMI_DIGITAL_CLOCK_STYLE_BACKGROUND__
	ADD_APPLICATION_IMAGE2(IMG_TECHNO_DIGITAL_CLOCK_DAY_BACKGROUND, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\day.png", " Techno Idlescreen Digital Clock Day Background Image");
	ADD_APPLICATION_IMAGE2(IMG_TECHNO_DIGITAL_CLOCK_NIGHT_BACKGROUND, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\night.png", " Techno Idlescreen Digital Clock Night Background Image");
#endif /* __MMI_DIGITAL_CLOCK_STYLE_BACKGROUND__ */
#endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */
#ifdef __MMI_DIGITAL_CLOCK_IMAGE_NUMBER__
	ADD_APPLICATION_IMAGE2(IMG_TECHNO_DIGITAL_CLOCK_0, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\DigitalClock\\\\0030.png", " Techno Idlescreen Digital Clock Number 0 Image");
	ADD_APPLICATION_IMAGE2(IMG_TECHNO_DIGITAL_CLOCK_1, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\DigitalClock\\\\0031.png", " Techno Idlescreen Digital Clock Number 1 Image");
	ADD_APPLICATION_IMAGE2(IMG_TECHNO_DIGITAL_CLOCK_2, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\DigitalClock\\\\0032.png", " Techno Idlescreen Digital Clock Number 2 Image");
	ADD_APPLICATION_IMAGE2(IMG_TECHNO_DIGITAL_CLOCK_3, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\DigitalClock\\\\0033.png", " Techno Idlescreen Digital Clock Number 3 Image");
	ADD_APPLICATION_IMAGE2(IMG_TECHNO_DIGITAL_CLOCK_4, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\DigitalClock\\\\0034.png", " Techno Idlescreen Digital Clock Number 4 Image");
	ADD_APPLICATION_IMAGE2(IMG_TECHNO_DIGITAL_CLOCK_5, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\DigitalClock\\\\0035.png", " Techno Idlescreen Digital Clock Number 5 Image");
	ADD_APPLICATION_IMAGE2(IMG_TECHNO_DIGITAL_CLOCK_6, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\DigitalClock\\\\0036.png", " Techno Idlescreen Digital Clock Number 6 Image");
	ADD_APPLICATION_IMAGE2(IMG_TECHNO_DIGITAL_CLOCK_7, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\DigitalClock\\\\0037.png", " Techno Idlescreen Digital Clock Number 7 Image");
	ADD_APPLICATION_IMAGE2(IMG_TECHNO_DIGITAL_CLOCK_8, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\DigitalClock\\\\0038.png", " Techno Idlescreen Digital Clock Number 8 Image");
	ADD_APPLICATION_IMAGE2(IMG_TECHNO_DIGITAL_CLOCK_9, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\DigitalClock\\\\0039.png", " Techno Idlescreen Digital Clock Number 9 Image");
	ADD_APPLICATION_IMAGE2(IMG_TECHNO_DIGITAL_CLOCK_AM, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\DigitalClock\\\\am.png", " Techno Idlescreen Digital Clock AM Image");
	ADD_APPLICATION_IMAGE2(IMG_TECHNO_DIGITAL_CLOCK_PM, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\DigitalClock\\\\pm.png", " Techno Idlescreen Digital Clock PM Image");
	ADD_APPLICATION_IMAGE2(IMG_TECHNO_DIGITAL_CLOCK_COLON, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\DigitalClock\\\\0021.png", " Techno Idlescreen Digital Clock Colon Image");
#endif /* __MMI_DIGITAL_CLOCK_IMAGE_NUMBER__ */
#if 1 /*Pawanjeet*/
	ADD_APPLICATION_IMAGE2(IMG_KEYPAD_LOCK_UNLOCK_BAR_BG, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\PhoneLockUnlock\\\\Bar\\\\UnlockBar_BG.png", " Phone lock unlock bar image");
	ADD_APPLICATION_IMAGE2(IMG_KEYPAD_LOCK_UNLOCK_TIME_BAR_BG, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\PhoneLockUnlock\\\\Bar\\\\UnlockTimeBar_BG.png", " Phone lock unlock time bar image");
	ADD_APPLICATION_IMAGE2(IMG_KEYPAD_LOCK_UNLOCK_BUTTON0, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\PhoneLockUnlock\\\\LongPressButton\\\\Unlock_button0.png", " Phone lock unlock button 0 image");
	ADD_APPLICATION_IMAGE2(IMG_KEYPAD_LOCK_UNLOCK_BUTTON1, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\PhoneLockUnlock\\\\LongPressButton\\\\Unlock_button1.png", " Phone lock unlock button 1 image");
	ADD_APPLICATION_IMAGE2(IMG_KEYPAD_LOCK_UNLOCK_BUTTON2, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\PhoneLockUnlock\\\\LongPressButton\\\\Unlock_button2.png", " Phone lock unlock button 2 image");
	ADD_APPLICATION_IMAGE2(IMG_KEYPAD_LOCK_UNLOCK_BUTTON3, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\PhoneLockUnlock\\\\LongPressButton\\\\Unlock_button3.png", " Phone lock unlock button 3 image");
	ADD_APPLICATION_IMAGE2(IMG_KEYPAD_LOCK_UNLOCK_BUTTON4, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\PhoneLockUnlock\\\\LongPressButton\\\\Unlock_button4.png", " Phone lock unlock button 4 image");
	ADD_APPLICATION_IMAGE2(IMG_KEYPAD_LOCK_UNLOCK_BUTTON5, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\PhoneLockUnlock\\\\LongPressButton\\\\Unlock_button5.png", " Phone lock unlock button 5 image");
#endif

#if (defined __OPTR_NONE__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || (defined(__MMI_MAINLCD_320X480__) && defined(__MMI_FTE_SUPPORT__))) && (!defined(__LOW_COST_SUPPORT_COMMON__))
    ADD_APPLICATION_IMAGE_TYPE(IMG_TECHNO_DIGITAL_SMALL_CLOCK_0, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0030.png", " status icon bar small Digital Clock Number 0 Image", FALSE, FORCE_ABM);
	ADD_APPLICATION_IMAGE_TYPE(IMG_TECHNO_DIGITAL_SMALL_CLOCK_1, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0031.png", " status icon bar small Digital Clock Number 1 Image", FALSE, FORCE_ABM);
	ADD_APPLICATION_IMAGE_TYPE(IMG_TECHNO_DIGITAL_SMALL_CLOCK_2, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0032.png", " status icon bar small Digital Clock Number 2 Image", FALSE, FORCE_ABM);
	ADD_APPLICATION_IMAGE_TYPE(IMG_TECHNO_DIGITAL_SMALL_CLOCK_3, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0033.png", " status icon bar small Digital Clock Number 3 Image", FALSE, FORCE_ABM);
	ADD_APPLICATION_IMAGE_TYPE(IMG_TECHNO_DIGITAL_SMALL_CLOCK_4, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0034.png", " status icon bar small Digital Clock Number 4 Image", FALSE, FORCE_ABM);
	ADD_APPLICATION_IMAGE_TYPE(IMG_TECHNO_DIGITAL_SMALL_CLOCK_5, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0035.png", " status icon bar small Digital Clock Number 5 Image", FALSE, FORCE_ABM);
	ADD_APPLICATION_IMAGE_TYPE(IMG_TECHNO_DIGITAL_SMALL_CLOCK_6, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0036.png", " status icon bar small Digital Clock Number 6 Image", FALSE, FORCE_ABM);
	ADD_APPLICATION_IMAGE_TYPE(IMG_TECHNO_DIGITAL_SMALL_CLOCK_7, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0037.png", " status icon bar small Digital Clock Number 7 Image", FALSE, FORCE_ABM);
	ADD_APPLICATION_IMAGE_TYPE(IMG_TECHNO_DIGITAL_SMALL_CLOCK_8, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0038.png", " status icon bar small Digital Clock Number 8 Image", FALSE, FORCE_ABM);
	ADD_APPLICATION_IMAGE_TYPE(IMG_TECHNO_DIGITAL_SMALL_CLOCK_9, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0039.png", " status icon bar small Digital Clock Number 9 Image", FALSE, FORCE_ABM);
	ADD_APPLICATION_IMAGE_TYPE(IMG_TECHNO_DIGITAL_SMALL_CLOCK_AM, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\am.png", " status icon bar small Digital Clock AM Image", FALSE, FORCE_ABM);
	ADD_APPLICATION_IMAGE_TYPE(IMG_TECHNO_DIGITAL_SMALL_CLOCK_PM, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\pm.png", " status icon bar small Digital Clock PM Image", FALSE, FORCE_ABM);
	ADD_APPLICATION_IMAGE_TYPE(IMG_TECHNO_DIGITAL_SMALL_CLOCK_COLON, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0021.png", " status icon bar small Digital Clock Colon Image", FALSE, FORCE_ABM);
#else
	ADD_APPLICATION_IMAGE_TYPE(IMG_TECHNO_DIGITAL_SMALL_CLOCK_0, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0030.pbm", " status icon bar small Digital Clock Number 0 Image", FALSE, FORCE_ABM);
	ADD_APPLICATION_IMAGE_TYPE(IMG_TECHNO_DIGITAL_SMALL_CLOCK_1, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0031.pbm", " status icon bar small Digital Clock Number 1 Image", FALSE, FORCE_ABM);
	ADD_APPLICATION_IMAGE_TYPE(IMG_TECHNO_DIGITAL_SMALL_CLOCK_2, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0032.pbm", " status icon bar small Digital Clock Number 2 Image", FALSE, FORCE_ABM);
	ADD_APPLICATION_IMAGE_TYPE(IMG_TECHNO_DIGITAL_SMALL_CLOCK_3, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0033.pbm", " status icon bar small Digital Clock Number 3 Image", FALSE, FORCE_ABM);
	ADD_APPLICATION_IMAGE_TYPE(IMG_TECHNO_DIGITAL_SMALL_CLOCK_4, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0034.pbm", " status icon bar small Digital Clock Number 4 Image", FALSE, FORCE_ABM);
	ADD_APPLICATION_IMAGE_TYPE(IMG_TECHNO_DIGITAL_SMALL_CLOCK_5, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0035.pbm", " status icon bar small Digital Clock Number 5 Image", FALSE, FORCE_ABM);
	ADD_APPLICATION_IMAGE_TYPE(IMG_TECHNO_DIGITAL_SMALL_CLOCK_6, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0036.pbm", " status icon bar small Digital Clock Number 6 Image", FALSE, FORCE_ABM);
	ADD_APPLICATION_IMAGE_TYPE(IMG_TECHNO_DIGITAL_SMALL_CLOCK_7, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0037.pbm", " status icon bar small Digital Clock Number 7 Image", FALSE, FORCE_ABM);
	ADD_APPLICATION_IMAGE_TYPE(IMG_TECHNO_DIGITAL_SMALL_CLOCK_8, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0038.pbm", " status icon bar small Digital Clock Number 8 Image", FALSE, FORCE_ABM);
	ADD_APPLICATION_IMAGE_TYPE(IMG_TECHNO_DIGITAL_SMALL_CLOCK_9, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0039.pbm", " status icon bar small Digital Clock Number 9 Image", FALSE, FORCE_ABM);
	ADD_APPLICATION_IMAGE_TYPE(IMG_TECHNO_DIGITAL_SMALL_CLOCK_AM, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\am.pbm", " status icon bar small Digital Clock AM Image", FALSE, FORCE_ABM);
	ADD_APPLICATION_IMAGE_TYPE(IMG_TECHNO_DIGITAL_SMALL_CLOCK_PM, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\pm.pbm", " status icon bar small Digital Clock PM Image", FALSE, FORCE_ABM);
	ADD_APPLICATION_IMAGE_TYPE(IMG_TECHNO_DIGITAL_SMALL_CLOCK_COLON, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0021.pbm", " status icon bar small Digital Clock Colon Image", FALSE, FORCE_ABM);
#endif
#if defined(__MMI_VUI_ENGINE__)
    ADD_APPLICATION_IMAGE2(IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_NUMBER_0, CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Digital_NUM0.png", " statuc icon bar small Digital Clock Number 1 Image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_NUMBER_1, CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Digital_NUM1.png", " statuc icon bar small Digital Clock Number 2 Image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_NUMBER_2, CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Digital_NUM2.png", " statuc icon bar small Digital Clock Number 3 Image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_NUMBER_3, CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Digital_NUM3.png", " statuc icon bar small Digital Clock Number 4 Image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_NUMBER_4, CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Digital_NUM4.png", " statuc icon bar small Digital Clock Number 5 Image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_NUMBER_5, CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Digital_NUM5.png", " statuc icon bar small Digital Clock Number 6 Image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_NUMBER_6, CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Digital_NUM6.png", " statuc icon bar small Digital Clock Number 7 Image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_NUMBER_7, CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Digital_NUM7.png", " statuc icon bar small Digital Clock Number 8 Image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_NUMBER_8, CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Digital_NUM8.png", " statuc icon bar small Digital Clock Number 9 Image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_NUMBER_9, CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Digital_NUM9.png", " statuc icon bar small Digital Clock AM Image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_NUMBER_BACKGROUND, CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Digital_NUM_gray.png", " statuc icon bar small Digital Clock PM Image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_TIME_SEPERATOR_FOREGROUND, CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Digital_Colon.png", " statuc icon bar small Digital Clock Colon Image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_TIME_SEPERATOR_BACKGROUND, CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Digital_Colon_gray.png", " statuc icon bar small Digital Clock Number 0 Image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_AM_FOREGROUND, CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Digital_AM_on.png", " statuc icon bar small Digital Clock Number 1 Image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_AM_BACKGROUND, CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Digital_AM_dis.png", " statuc icon bar small Digital Clock Number 2 Image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_PM_FOREGROUND, CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Digital_PM_on.png", " statuc icon bar small Digital Clock Number 3 Image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_PM_BACKGROUND, CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Digital_PM_dis.png", " statuc icon bar small Digital Clock Number 4 Image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VENUS_ANALOG_IMAGE_CLOCK_BACKGROUND, CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Simulate_BG.png", " statuc icon bar small Digital Clock Number 3 Image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VENUS_ANALOG_IMAGE_CLOCK_COVER, CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Simulate_cover.png", " statuc icon bar small Digital Clock Number 4 Image");

    ADD_APPLICATION_IMAGE2(IMG_ID_VENUS_ANALOG_IMAGE_CLOCK_HOUR_HAND, CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Simulate_SecondHand.png", " statuc icon bar small Digital Clock Number 4 Image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VENUS_ANALOG_IMAGE_CLOCK_MINUTE_HAND, CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Simulate_SecondHand.png", " statuc icon bar small Digital Clock Number 4 Image");
    ADD_APPLICATION_IMAGE2(IMG_ID_VENUS_ANALOG_IMAGE_CLOCK_SECOND_HAND, CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Simulate_SecondHand.png", " statuc icon bar small Digital Clock Number 4 Image");
    
    ADD_APPLICATION_IMAGE2(IMG_ID_VENUS_CLIPBOARD_FM_LEFT_H, CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clipboard\\\\CutCopyPaste_left_highlight.9slice.png", "Venus clipboard floating menu background");
    ADD_APPLICATION_IMAGE2(IMG_ID_VENUS_CLIPBOARD_FM_LEFT_N, CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clipboard\\\\CutCopyPaste_left_normal.9slice.png", "Venus clipboard floating menu background");
    ADD_APPLICATION_IMAGE2(IMG_ID_VENUS_CLIPBOARD_FM_MIDDLE_H, CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clipboard\\\\CutCopyPaste_middle_highlight.9slice.png", "Venus clipboard floating menu background");
    ADD_APPLICATION_IMAGE2(IMG_ID_VENUS_CLIPBOARD_FM_MIDDLE_N, CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clipboard\\\\CutCopyPaste_middle_normal.9slice.png", "Venus clipboard floating menu background");
    ADD_APPLICATION_IMAGE2(IMG_ID_VENUS_CLIPBOARD_FM_RIGHT_H, CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clipboard\\\\CutCopyPaste_right_highlight.9slice.png", "Venus clipboard floating menu background");
    ADD_APPLICATION_IMAGE2(IMG_ID_VENUS_CLIPBOARD_FM_RIGHT_N, CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clipboard\\\\CutCopyPaste_right_normal.9slice.png", "Venus clipboard floating menu background");
    ADD_APPLICATION_IMAGE2(IMG_ID_VENUS_CLIPBOARD_FM_SINGLE_H, CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clipboard\\\\CutCopyPaste_whole_h.9slice.png", "Venus clipboard floating menu background");
    ADD_APPLICATION_IMAGE2(IMG_ID_VENUS_CLIPBOARD_FM_SINGLE_N, CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clipboard\\\\CutCopyPaste_whole_n.9slice.png", "Venus clipboard floating menu background");
    ADD_APPLICATION_IMAGE2(IMG_ID_VENUS_CLIPBOARD_FM_BOTTOM_ARROW_H, CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clipboard\\\\CutCopyPaste_bottom-arrow_h.png", "Venus clipboard floating menu background");
    ADD_APPLICATION_IMAGE2(IMG_ID_VENUS_CLIPBOARD_FM_BOTTOM_ARROW_N, CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clipboard\\\\CutCopyPaste_bottom-arrow_n.png", "Venus clipboard floating menu background");
    ADD_APPLICATION_IMAGE2(IMG_ID_VENUS_CLIPBOARD_FM_TOP_ARROW_H, CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clipboard\\\\CutCopyPaste_top-arrow_h.png", "Venus clipboard floating menu background");
    ADD_APPLICATION_IMAGE2(IMG_ID_VENUS_CLIPBOARD_FM_TOP_ARROW_N, CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clipboard\\\\CutCopyPaste_top-arrow_n.png", "Venus clipboard floating menu background");

#endif /* __MMI_VUI_ENGINE__ */
        
//PMT HIMANSHU END 20050721

//PMT HIMANSHU START 20050815
#if defined(__MMI_DRAW_MANAGER__)
#if defined(__MMI_MAINLCD_320X240__) && defined(__MMI_DUAL_SIM_MASTER__)
    ADD_APPLICATION_IMAGE2(IMAGE_VIEW_TITLEBAR_BG, CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\DualSIM\\\\TB_IV_BG_DUAL.pbm","Title bar of Wallpaper and ScreenSaver Image View Screen");
#else
	ADD_APPLICATION_IMAGE2(IMAGE_VIEW_TITLEBAR_BG, CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\TB_IV_BG.pbm","Title bar of Wallpaper and ScreenSaver Image View Screen");
#endif /* defined(MMI_SHOW_STATUS_ICON_IN_TITLE) && defined(__MMI_DUAL_SIM_MASTER__)*/
#endif /* defined(__MMI_DRAW_MANAGER__)*/
#ifdef UI_SMALL_LIST_SCREEN
	ADD_APPLICATION_IMAGE2(IMG_FLEXIBLE_TITLEBAR_BG, CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\TB_FLEXIBLE.pbm","Title bar for flexible size");//093006 popup title
#endif
//PMT HIMANSHU END 20050815
//PMT NEERAJ START 20050825
#ifdef __MMI_UI_TWO_LINE_MENUITEM_STYLES__
	ADD_APPLICATION_IMAGE2(TWO_LINE_VOLUME_IMAGE,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_INLINE.gif","Inline Volume Image");
#endif
//PMT NEERAJ END 20050825
#if defined (__MMI_MAINLCD_128X128__)
    ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_NORMAL_TAB, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_middle.bmp", "normal tab");
    ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_NORMAL_LEFT_TAB, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_left.bmp", "normal tab");
    ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_NORMAL_RIGHT_TAB, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_right.bmp", "normal tab");
    ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_FOCUSED_TAB, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\focused_tab_bar_middle.bmp", "focused tab");
    ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_FOCUSED_LEFT_TAB, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\focused_tab_bar_left.bmp", "focused tab");
    ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_FOCUSED_RIGHT_TAB, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\focused_tab_bar_right.bmp", "focused tab");
    ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_BLINKING_TAB, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_blink_middle.bmp", "blinking tab");
    ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_BLINKING_LEFT_TAB, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_blink_left.bmp", "blinking tab");
    ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_BLINKING_RIGHT_TAB, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_blink.bmp", "blinking tab");
    ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_TAB_L_ARROW, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\TAB_ARROW_L.GIF", "right arrow on tab");
    ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_TAB_R_ARROW, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\TAB_ARROW_R.GIF", "left arrow on tab");
    ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_TAB_HINT_AREA, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\TITLEBAR.bmp", "tab hint area");
#elif defined(__MMI_MAINLCD_320X480__)  /* __MMI_MAINLCD_128X128__ */
    ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_NORMAL_TAB, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_middle.png", "normal tab");
    ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_NORMAL_LEFT_TAB, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_left.png", "normal tab");
    ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_NORMAL_RIGHT_TAB, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_right.png", "normal tab");
    ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_FOCUSED_TAB, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\focused_tab_bar_middle.png", "focused tab");
    ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_FOCUSED_LEFT_TAB, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\focused_tab_bar_left.png", "focused tab");
    ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_FOCUSED_RIGHT_TAB, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\focused_tab_bar_right.png", "focused tab");
    ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_BLINKING_TAB, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_blink_middle.png", "blinking tab");
    ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_BLINKING_LEFT_TAB, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_blink_left.png", "blinking tab");
    ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_BLINKING_RIGHT_TAB, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_blink_right.png", "blinking tab");
    ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_TAB_L_ARROW, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\TAB_ARROW_L.GIF", "right arrow on tab");
    ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_TAB_R_ARROW, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\TAB_ARROW_R.GIF", "left arrow on tab");
    ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_TAB_HINT_AREA, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\TITLEBAR.png", "tab hint area");
#else  /* __MMI_MAINLCD_128X128__ */
    ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_NORMAL_TAB, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_middle.png", "normal tab");
    ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_NORMAL_LEFT_TAB, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_left.png", "normal tab");
    ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_NORMAL_RIGHT_TAB, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_right.png", "normal tab");
    ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_FOCUSED_TAB, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\focused_tab_bar_middle.png", "focused tab");
    ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_FOCUSED_LEFT_TAB, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\focused_tab_bar_left.png", "focused tab");
    ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_FOCUSED_RIGHT_TAB, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\focused_tab_bar_right.png", "focused tab");
    ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_BLINKING_TAB, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_blink_middle.png", "blinking tab");
    ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_BLINKING_LEFT_TAB, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_blink_left.png", "blinking tab");
    ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_BLINKING_RIGHT_TAB, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_blink_right.png", "blinking tab");
    ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_TAB_L_ARROW, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\TAB_ARROW_L.GIF", "right arrow on tab");
    ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_TAB_R_ARROW, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\TAB_ARROW_R.GIF", "left arrow on tab");
    ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_TAB_HINT_AREA, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\TITLEBAR.GIF", "tab hint area");
#endif /* __MMI_MAINLCD_128X128__ */

	ADD_APPLICATION_IMAGE2(IMG_PERCENTAGE_BAR_LEFT_IMAGE, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ProgressBar\\\\load_left.pbm", "aa");
	ADD_APPLICATION_IMAGE2(IMG_PERCENTAGE_BAR_RIGHT_IMAGE, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ProgressBar\\\\load_right.pbm", "bb");
	ADD_APPLICATION_IMAGE2(IMG_PERCENTAGE_BAR_BG_IMAGE, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ProgressBar\\\\load_bg.pbm", "cc");

    ADD_APPLICATION_IMAGE2(GUI_COLOR_SLIDER_ARROW_IMAGE_ID,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ColorSlider\\\\color_slider_arrow.pbm","Color Slider Arrow");
    
#if(EMS_DISPLAY_SPECIAL_CHARACTERS)
    ADD_APPLICATION_IMAGE2(WGUI_CR_CHARACTER_IMAGE_ID,CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\EMSCR.BMP","EMS CR character display");
    ADD_APPLICATION_IMAGE2(WGUI_ESC_CHARACTER_IMAGE_ID,CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\EMSESC.BMP","EMS ESC character display");
    ADD_APPLICATION_IMAGE2(WGUI_LF_CHARACTER_IMAGE_ID,CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\EMSLF.BMP","EMS LF character display");
#endif
    
    ADD_APPLICATION_IMAGE2(WGUI_IMG_TEXT_BG_TOP,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TextBG\\\\TBG_TOP.png","text background top");
#ifdef __MMI_FTE_SUPPORT__
    ADD_APPLICATION_IMAGE2(WGUI_IMG_TEXT_BG_MID,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TextBG\\\\information_background.9slice.png","text background middle");
#else    
    ADD_APPLICATION_IMAGE2(WGUI_IMG_TEXT_BG_MID,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TextBG\\\\TBG_MID.png","text background middle");
#endif    
    ADD_APPLICATION_IMAGE2(WGUI_IMG_TEXT_BG_BOTTOM,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TextBG\\\\TBG_BOTTOM.png","text background bottom");
    ADD_APPLICATION_IMAGE2(WGUI_IMG_TEXT_BG_PREVIEW,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TextBG\\\\TBG_Preview.png","text&Image Preview background ");
    
    /* Download agent, progressive bar images */
    ADD_APPLICATION_IMAGE2(IMG_CAT412_PROG_BAR_BG, CUST_IMG_PATH"\\\\MainLCD\\\\DLAgent\\\\PROGRESS_BG.bmp", "Cat412 progressive bar bg");
    ADD_APPLICATION_IMAGE2(IMG_CAT412_PROG_BAR_FULL, CUST_IMG_PATH"\\\\MainLCD\\\\DLAgent\\\\PROGRESS_Full.bmp", "Cat412 progressive bar bg");
 
#ifdef __MMI_JATAAYU_MMS_ADVANCED_VIEW_SCREEN__
	ADD_APPLICATION_IMAGE2(IMG_ID_JMMS_NEW_VIEW_SCREEN_PROGRESS_BAR, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\SMIL\\\\BAR.gif","mms new view screen progress bar");
#endif

#ifdef __MMI_ANIMATED_DIAL__
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    SetENFBAssociatedID();
#endif
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIMATED_DIAL_1, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_1", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIMATED_DIAL_2, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_2", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIMATED_DIAL_3, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_3", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIMATED_DIAL_4, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_4", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIMATED_DIAL_5, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_5", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIMATED_DIAL_6, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_6", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIMATED_DIAL_7, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_7", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIMATED_DIAL_8, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_8", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIMATED_DIAL_9, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_9", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIMATED_DIAL_0, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_0", "animated dial image");
    
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIMATED_DIAL_STAR,  CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_star", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIMATED_DIAL_PLUS,  CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_plus", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIMATED_DIAL_P,     CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_p", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIMATED_DIAL_W,     CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_w", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIMATED_DIAL_POUND, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_pound", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIMATED_DIAL_QUEST, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_quest", "animated dial image");

    ADD_APPLICATION_IMAGE2(IMG_ID_ANIMATED_DIAL_S_1, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_s_1", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIMATED_DIAL_S_2, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_s_2", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIMATED_DIAL_S_3, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_s_3", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIMATED_DIAL_S_4, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_s_4", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIMATED_DIAL_S_5, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_s_5", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIMATED_DIAL_S_6, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_s_6", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIMATED_DIAL_S_7, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_s_7", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIMATED_DIAL_S_8, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_s_8", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIMATED_DIAL_S_9, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_s_9", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIMATED_DIAL_S_0, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_s_0", "animated dial image");
    
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIMATED_DIAL_S_STAR,  CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_s_star", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIMATED_DIAL_S_PLUS,  CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_s_plus", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIMATED_DIAL_S_P,     CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_s_p", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIMATED_DIAL_S_W,     CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_s_w", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIMATED_DIAL_S_POUND, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_s_pound", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIMATED_DIAL_S_QUEST, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_s_quest", "animated dial image");
    
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIMATED_DIAL_BG, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_bg.png", "animated dial image");

    ADD_APPLICATION_IMAGE2(IMG_ID_ANIMATED_DIAL_CURSOR,     CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_cursor", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIMATED_DIAL_CURSOR_S,     CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_cursor_s", "animated dial image");

    ADD_APPLICATION_IMAGE2(IMG_ID_ANIM_DIAL_DSPR_1, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\1", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIM_DIAL_DSPR_2, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\2", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIM_DIAL_DSPR_3, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\3", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIM_DIAL_DSPR_4, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\4", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIM_DIAL_DSPR_5, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\5", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIM_DIAL_DSPR_6, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\6", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIM_DIAL_DSPR_7, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\7", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIM_DIAL_DSPR_8, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\8", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIM_DIAL_DSPR_9, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\9", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIM_DIAL_DSPR_0, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\0", "animated dial image");
    
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIM_DIAL_DSPR_STAR,  CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\star", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIM_DIAL_DSPR_PLUS,  CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\plus", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIM_DIAL_DSPR_P,     CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\p", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIM_DIAL_DSPR_W,     CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\w", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIM_DIAL_DSPR_POUND, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\pound", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIM_DIAL_DSPR_QUEST, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\quest", "animated dial image");

    ADD_APPLICATION_IMAGE2(IMG_ID_ANIM_DIAL_DSPR_S_1, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\small\\\\1", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIM_DIAL_DSPR_S_2, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\small\\\\2", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIM_DIAL_DSPR_S_3, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\small\\\\3", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIM_DIAL_DSPR_S_4, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\small\\\\4", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIM_DIAL_DSPR_S_5, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\small\\\\5", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIM_DIAL_DSPR_S_6, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\small\\\\6", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIM_DIAL_DSPR_S_7, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\small\\\\7", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIM_DIAL_DSPR_S_8, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\small\\\\8", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIM_DIAL_DSPR_S_9, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\small\\\\9", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIM_DIAL_DSPR_S_0, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\small\\\\0", "animated dial image");
    
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIM_DIAL_DSPR_S_STAR,  CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\small\\\\star", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIM_DIAL_DSPR_S_PLUS,  CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\small\\\\plus", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIM_DIAL_DSPR_S_P,     CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\small\\\\p", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIM_DIAL_DSPR_S_W,     CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\small\\\\w", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIM_DIAL_DSPR_S_POUND, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\small\\\\pound", "animated dial image");
    ADD_APPLICATION_IMAGE2(IMG_ID_ANIM_DIAL_DSPR_S_QUEST, CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\small\\\\quest", "animated dial image");
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    ResetENFBAssociatedID();
#endif
#endif /* __MMI_ANIMATED_DIAL__ */

    /* Side bar image */
#ifdef __MMI_OP11_SIDEBAR__
    ADD_APPLICATION_IMAGE2(IMG_SIDE_BAR_LEFT,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SideBar\\\\HomePOP_LeftBG.png", "SideBar menu background");
    ADD_APPLICATION_IMAGE2(IMG_SIDE_BAR_MENU_TOP,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SideBar\\\\HomePOP_top.png", "Popout menu top");
    ADD_APPLICATION_IMAGE2(IMG_SIDE_BAR_MENU_TOP2,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SideBar\\\\HomePOP_top2.png", "Popout menu top2");
    ADD_APPLICATION_IMAGE2(IMG_SIDE_BAR_MENU_MIDDLE,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SideBar\\\\HomePOP_middle.png", "Popout menu middle");
    ADD_APPLICATION_IMAGE2(IMG_SIDE_BAR_MENU_BOTTOM,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SideBar\\\\HomePOP_bottom.png", "Popout menu bottom");
    ADD_APPLICATION_IMAGE2(IMG_SIDE_BAR_MENU_BOTTOM2,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SideBar\\\\HomePOP_bottom2.png", "Popout menu bottom2");
    ADD_APPLICATION_IMAGE2(IMG_SIDE_BAR_MENU_LEFT,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SideBar\\\\HomePOP_left.png", "Popout menu left");

    ADD_APPLICATION_IMAGE2(IMG_SIDE_BAR_MENU_HIGHLIGHT_WITHOUT_SCROLLBAR,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SideBar\\\\HomePOP_Highlight_NonTouch_NonScrollbar.png", "Popout menu highlight");
#ifndef __MMI_TOUCH_SCREEN__
    ADD_APPLICATION_IMAGE2(IMG_SIDE_BAR_MENU_HIGHLIGHT_WITH_SCROLLBAR,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SideBar\\\\HomePOP_Highlight_NonTouch_Scrollbar.png", "Popout menu highlight with scrollbar");
#else
    ADD_APPLICATION_IMAGE2(IMG_SIDE_BAR_MENU_HIGHLIGHT_WITH_SCROLLBAR,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SideBar\\\\HomePOP_Highlight_Touch_Scrollbar.png", "Popout menu highlight with scrollbar");
#endif
#endif
    /* Toolbar image */
#ifdef __MMI_OP12_TOOLBAR__   
    ADD_APPLICATION_IMAGE2(IMG_TOOLBAR_LEFT_ARROW,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ToolBar\\\\toolbar_arrow_left.bmp", "Toolbar left arrow");
    ADD_APPLICATION_IMAGE2(IMG_TOOLBAR_RIGHT_ARROW,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ToolBar\\\\toolbar_arrow_right.bmp", "Toolbar right arrow");
    ADD_APPLICATION_IMAGE2(IMG_TOOLBAR_BAR_BG_INACTIVE,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ToolBar\\\\toolbar_TAB_IDLE_nomal.png", "Toolbar inactive bg");
    ADD_APPLICATION_IMAGE2(IMG_TOOLBAR_BAR_BG_EVENT,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ToolBar\\\\toolbar_TAB_IDLE_select.png", "Toolbar event bg");
    ADD_APPLICATION_IMAGE2(IMG_TOOLBAR_BAR_BG_EVENT_INACTIVE,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ToolBar\\\\toolbar_TAB_IDLE_select_transparent.png", "Toolbar event inactive bg");
    ADD_APPLICATION_IMAGE2(IMG_TOOLBAR_MENU_ITEM_BG,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ToolBar\\\\toolbar_TAB_listbg.png", "Toolbar menu item bg");
    ADD_APPLICATION_IMAGE2(IMG_TOOLBAR_BAR_BG_ACTIVE,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ToolBar\\\\toolbar_TAB_nomal.png", "Toolbar active bg");
    ADD_APPLICATION_IMAGE2(IMG_TOOLBAR_BAR_BG_HIGHLIGHT,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ToolBar\\\\toolbar_TAB_select.png", "Toolbar highlight bg");
    ADD_APPLICATION_IMAGE2(IMG_TOOLBAR_TITLE_BG,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ToolBar\\\\toolbar_TAB_Title.png", "Toolbar title bg");

    ADD_APPLICATION_IMAGE2(IMG_TOOLBAR_MENU_HIGHLIGHT_WITH_SCROLLBAR,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ToolBar\\\\Toolbar_highlight_scrollbar.png", "Toolbar");
    ADD_APPLICATION_IMAGE2(IMG_TOOLBAR_MENU_HIGHLIGHT_WITHOUT_SCROLLBAR,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ToolBar\\\\Toolbar_highlight.png", "Toolbar");
    ADD_APPLICATION_IMAGE2(IMG_TOOLBAR_MENU_HIGHLIGHT_DOUBLE_LINE_WITH_SCROLLBAR,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ToolBar\\\\Toolbar_2line_highlight_scrollbar.png", "Toolbar");
    ADD_APPLICATION_IMAGE2(IMG_TOOLBAR_MENU_HIGHLIGHT_DOUBLE_LINE_WITHOUT_SCROLLBAR,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ToolBar\\\\Toolbar_2line_highlight.png", "Toolbar");
#endif

    /* Status icon bar time */
    ADD_APPLICATION_IMAGE2(IMG_STATUS_ICON_TIME_AM,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\StatusiconTime\\\\AM.bmp", "Status icon time am");
    ADD_APPLICATION_IMAGE2(IMG_STATUS_ICON_TIME_PM,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\StatusiconTime\\\\PM.bmp", "Status icon time pm");
    ADD_APPLICATION_IMAGE2(IMG_STATUS_ICON_TIME_AM_CH,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\StatusiconTime\\\\AM_CH.bmp", "Status icon time am ch");
    ADD_APPLICATION_IMAGE2(IMG_STATUS_ICON_TIME_PM_CH,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\StatusiconTime\\\\PM_CH.bmp", "Status icon time pm ch");

#ifdef __MMI_DUAL_SIM_MASTER__
    ADD_APPLICATION_IMAGE2(WGUI_IMG_IDLE_SIM1, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SimCard\\\\SI_Sim1.png","IDLE SIM1 name icon");
    ADD_APPLICATION_IMAGE2(WGUI_IMG_IDLE_SIM2, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SimCard\\\\SI_Sim2.png","IDLE SIM2 name icon");
#endif

#ifdef __MMI_CAT116_SUPPORT__
    ADD_APPLICATION_IMAGE2(IMG_ID_CALL_PLAN_BACKGROUND, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TextBG\\\\BG.png","call plan background");
#endif
#if defined(__MMI_BT_MTK_SUPPORT__) || defined(__MMI_PICT_BRIDGE_SUPPORT__) || defined(__MMI_CSB_BROWSER__)
    ADD_APPLICATION_IMAGE2(SMALL_CHECKBOX_ON_IMAGE_ID,CUST_IMG_PATH"\\\\MainLCD\\\\UIELement\\\\Checkbox\\\\S_CK_S.BMP","Image associated with small CheckBox On.");
    ADD_APPLICATION_IMAGE2(SMALL_CHECKBOX_OFF_IMAGE_ID,CUST_IMG_PATH"\\\\MainLCD\\\\UIELement\\\\Checkbox\\\\S_CK_UNS.BMP","Image associated with small CheckBox Off.");
#endif
#ifdef __MMI_ECOMPASS__
    ADD_APPLICATION_IMAGE2(IMG_ID_COMPASS_BACKGROUND,CUST_IMG_PATH"\\\\MainLCD\\\\Compass\\\\EC_background.png","Image assoicated with compass");
#endif

    /* Move EMS pre defined sound resource here */
    ADD_APPLICATION_AUDIO2(AUD_ID_EMS_CHIMES_HIGH, CUST_ADO_PATH"\\\\EMS\\\\EMS01_ChimesHigh.mid", "EMS predefine sound");
    ADD_APPLICATION_AUDIO2(AUD_ID_EMS_CHIMES_LOW, CUST_ADO_PATH"\\\\EMS\\\\EMS02_ChimesLow.mid", "EMS predefine sound");
    ADD_APPLICATION_AUDIO2(AUD_ID_EMS_DING, CUST_ADO_PATH"\\\\EMS\\\\EMS03_Ding.mid", "EMS predefine sound");
    ADD_APPLICATION_AUDIO2(AUD_ID_EMS_TADA, CUST_ADO_PATH"\\\\EMS\\\\EMS04_TaDa.mid", "EMS predefine sound");
    ADD_APPLICATION_AUDIO2(AUD_ID_EMS_NOTIFY, CUST_ADO_PATH"\\\\EMS\\\\EMS05_Notify.mid", "EMS predefine sound");
    ADD_APPLICATION_AUDIO2(AUD_ID_EMS_DRUM, CUST_ADO_PATH"\\\\EMS\\\\EMS06_Drum.mid", "EMS predefine sound");
    ADD_APPLICATION_AUDIO2(AUD_ID_EMS_CLAPS, CUST_ADO_PATH"\\\\EMS\\\\EMS07_Claps.mid", "EMS predefine sound");
    ADD_APPLICATION_AUDIO2(AUD_ID_EMS_FANFAR, CUST_ADO_PATH"\\\\EMS\\\\EMS08_FanFar.mid", "EMS predefine sound");
    ADD_APPLICATION_AUDIO2(AUD_ID_EMS_CHORE_HGH, CUST_ADO_PATH"\\\\EMS\\\\EMS09_ChordHigh.mid", "EMS predefine sound");
    ADD_APPLICATION_AUDIO2(AUD_ID_EMS_CHORE_LOW, CUST_ADO_PATH"\\\\EMS\\\\EMS10_ChordLow.mid", "EMS predefine sound");

#if defined(__MMI_MAINLCD_128X160__) && defined(__MMI_CALENDAR_ON_IDLE_SCREEN__) && (defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__))
    ADD_APPLICATION_IMAGE2(IMG_ID_IDLE_CALENDAR_NUM_0,CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\week\\\\0030.bmp","Image assoicated with compass");
    ADD_APPLICATION_IMAGE2(IMG_ID_IDLE_CALENDAR_NUM_1,CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\week\\\\0031.bmp","Image assoicated with compass");
    ADD_APPLICATION_IMAGE2(IMG_ID_IDLE_CALENDAR_NUM_2,CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\week\\\\0032.bmp","Image assoicated with compass");
    ADD_APPLICATION_IMAGE2(IMG_ID_IDLE_CALENDAR_NUM_3,CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\week\\\\0033.bmp","Image assoicated with compass");
    ADD_APPLICATION_IMAGE2(IMG_ID_IDLE_CALENDAR_NUM_4,CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\week\\\\0034.bmp","Image assoicated with compass");
    ADD_APPLICATION_IMAGE2(IMG_ID_IDLE_CALENDAR_NUM_5,CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\week\\\\0035.bmp","Image assoicated with compass");
    ADD_APPLICATION_IMAGE2(IMG_ID_IDLE_CALENDAR_NUM_6,CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\week\\\\0036.bmp","Image assoicated with compass");
    ADD_APPLICATION_IMAGE2(IMG_ID_IDLE_CALENDAR_NUM_7,CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\week\\\\0037.bmp","Image assoicated with compass");
    ADD_APPLICATION_IMAGE2(IMG_ID_IDLE_CALENDAR_NUM_8,CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\week\\\\0038.bmp","Image assoicated with compass");
    ADD_APPLICATION_IMAGE2(IMG_ID_IDLE_CALENDAR_NUM_9,CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\week\\\\0039.bmp","Image assoicated with compass");
    ADD_APPLICATION_IMAGE2(IMG_ID_IDLE_CALENDAR_HORIZONTAL_STRING,CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\week\\\\week.bmp","Image assoicated with compass");
#endif


    PopulateUnifiedComposerEditorRes();

    PopulateMMSViewerRes();

}

//PMT VIKAS START 20050720
#if defined( __MMI_UI_ANIMATED_TITLE_EFFECT__)||defined(__MMI_UI_LIST_HIGHLIGHT_EFFECTS__)
void PopulateTitleListAnimationResources(void)
{
      #ifdef __MMI_UI_ANIMATED_TITLE_EFFECT__
      ADD_APPLICATION_IMAGE2(IMG_TITLE_SCROLL,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\AnimationEffects\\\\Title\\\\AnimationTitle.gif", "Animation Image for title");
      #endif

       #ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
        ADD_APPLICATION_IMAGE2(IMG_LIST_HIGHLIGHTER,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\AnimationEffects\\\\List\\\\AnimationHighlighter.gif", "Highlighter animatian image");
      #endif
}
#endif
//PMT VIKAS END 20050720

void PopulateStatusIconResources(void)
{	
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_SIGNAL_STRENGTH,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\signal\\\\SI_SIG","Status Icon: Signal strength", FALSE, FORCE_ABM_SEQUENCE);
#ifdef __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__ //022505 Calvin added
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_SIGNAL_STRENGTH_L1,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\signal\\\\SI_SIG_L1","Status Icon: Signal strength with L1", FALSE, FORCE_ABM_SEQUENCE);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_SIGNAL_STRENGTH_L2,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\signal\\\\SI_SIG_L2","Status Icon: Signal strength with L2", FALSE, FORCE_ABM_SEQUENCE);
#else
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_LINE_L1,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_L1.png","Status Icon: Line 1", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_LINE_L2,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_L2.png","Status Icon: Line 2", FALSE, FORCE_ABM);
#endif
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_BATTERY_STRENGTH,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\battery\\\\SI_BAT","Status Icon: Battery strength", FALSE, FORCE_ABM_SEQUENCE);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_3G,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_3G.png","Status Icon: WCDMA", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_2G,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_2G.png","Status Icon: GSM_GPRS", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_ANY,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_ANY.png","Status Icon: Dual Mode", FALSE, FORCE_ABM);
#ifdef __MMI_VOIP__//091806 voip icon
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_VOIP,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_VOIP.png","Status Icon: VOIP", FALSE, FORCE_ABM);
#endif
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_KEYPAD_LOCK,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_LOCK.png","Status Icon: Keypad lock", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_KEYPAD_UNLOCK,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_UNLOCK.png","Status Icon: Keypad lock", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_VIBRATE,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_VIB.png","Status Icon: Vibrator", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_SILENT,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_SILENT.png","Status Icon: Silent", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_RING,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_RING.png","Status Icon: Ring", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_VIBRATE_AND_RING,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_VR.png","Status Icon: Vibrate and ring", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_VIBRATE_THEN_RING,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_VTR.png","Status Icon: Vibrate then ring", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_ALARM_ACTIVATED,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_ALARM.png","Status Icon: Alarm", FALSE, FORCE_ABM);
#if !defined(__MMI_DUAL_SIM_MASTER__)
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_ROAMING_INDICATOR,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_RM.png","Status Icon: Roaming", FALSE, FORCE_ABM);
#else   /* __MMI_DUAL_SIM_MASTER__ */
       ADD_APPLICATION_IMAGE_TYPE(IMG_SI_ROAMING_INDICATOR,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Statusicons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Callforward\\\\Master\\\\SI_RM_1.png","Status Icon: Roaming", FALSE, FORCE_ABM);
#endif  /* __MMI_DUAL_SIM_MASTER__ */

#ifndef __MMI_DUAL_SIM_MASTER__
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_MISSED_CALL_INDICATOR,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_MCA.png","Status Icon: Missed Call", FALSE, FORCE_ABM);
#endif/*__MMI_DUAL_SIM_MASTER__*/

    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_GPRS_INDICATOR,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_GPRS.png","Status Icon: GPRS", FALSE, FORCE_ABM);

#if (defined (__MMI_STATUS_ICON_EN_EARPHONE__) || defined(__MMI_BT_HP_SUPPORT__) || defined(__MMI_BT_SUPPORT__))
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_EARPHONE_INDICATOR,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_EAR.png","Status Icon: EarPhone", FALSE, FORCE_ABM);
#endif

#if defined(MMS_SUPPORT)
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_MMS_UNREAD_INDICATOR,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_MMSU.png","Status Icon: EarPhone", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_MMS_BUSY_INDICATOR,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_MMSB.png","Status Icon: EarPhone", FALSE, FORCE_ABM);
#endif


#ifdef __MMI_IRDA_SUPPORT__
#if (defined __OPTR_NONE__)
     ADD_APPLICATION_IMAGE_TYPE(IMG_SI_IR_INDICATOR,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_IR","Status Icon: IR", FALSE, FORCE_ABM_SEQUENCE);
#else
     ADD_APPLICATION_IMAGE2(IMG_SI_IR_INDICATOR,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_IR.gif","Status Icon: IR");
#endif
#endif



#if defined(__MMI_BT_SUPPORT__)
     ADD_APPLICATION_IMAGE_TYPE(IMG_SI_BT,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_BT.png","Status Icon: BT", FALSE, FORCE_ABM);
     ADD_APPLICATION_IMAGE_TYPE(IMG_SI_BT_CON,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_BT_CON.png","Status Icon: BT", FALSE, FORCE_ABM);
     ADD_APPLICATION_IMAGE_TYPE(IMG_SI_BT_ND,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_BT_ND.png","Status Icon: BT", FALSE, FORCE_ABM);
#endif

#ifdef __MMI_POC__
     ADD_APPLICATION_IMAGE_TYPE(IMG_SI_POC,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_Walkt.png","Status Icon: PoC registration", FALSE, FORCE_ABM);//030705 Calvin added
#endif

/* 101205 new icon Calvin Start */
#ifdef __MMI_BG_SOUND_EFFECT__
     ADD_APPLICATION_IMAGE_TYPE(IMG_SI_BGSND,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_BGSND.png","Status Icon: background sound effect", FALSE, FORCE_ABM);
#endif

#ifdef __MMI_AUDIO_REVERB_EFFECT__
     ADD_APPLICATION_IMAGE_TYPE(IMG_SI_REVERBSND,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_AUDREVERB.png","Status Icon: audio reverb effect", FALSE, FORCE_ABM);
#endif

#ifdef __MMI_AUDIO_SURROUND_EFFECT__
     ADD_APPLICATION_IMAGE_TYPE(IMG_SI_SURROUNDSND,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_3DSound.png","Status Icon: audio surround effect", FALSE, FORCE_ABM);
#endif

#ifdef __MMI_HOMEZONE_STATUS_ICON__

#ifndef __MMI_DUAL_SIM_MASTER__
     ADD_APPLICATION_IMAGE_TYPE(IMG_SI_HZONE,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_HZONE.png","Status Icon: home zone", FALSE, FORCE_ABM);
#else
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_HZONE,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Homezone\\\\SI_home1.png","Status Icon: home zone master", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_HZONE_SLAVE,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Homezone\\\\SI_home2.png","Status Icon: home zone slave", FALSE, FORCE_ABM);
#endif
     ADD_APPLICATION_IMAGE_TYPE(IMG_SI_CZONE,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_CZONE.png","Status Icon: city zone", FALSE, FORCE_ABM);
#endif

#ifdef __CTM_SUPPORT__
     ADD_APPLICATION_IMAGE_TYPE(IMG_SI_TTY_INDICATOR,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_TTY.png","Status Icon: TTY indication", FALSE, FORCE_ABM);
#endif
/* 101205 new icon Calvin End */

#ifndef __MMI_DUAL_SIM_MASTER__
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_GPRS_ATT_NO_PDP_INDICATOR,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_GPRSC.png","Status Icon: GPRS, attach without pdp", FALSE, FORCE_ABM);   
#endif

    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_EMAIL,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_EMUR.png","Status Icon: Unread Email", FALSE, FORCE_ABM);

    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_VOICE_L1,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_VOML1.png","Status Icon: Unread Voice L1", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_VOICE_L2,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_VOML2.png","Status Icon: Unread Voice L2", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_VOICE_L1L2,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_VOML12.png","Status Icon: Unread Voice L1+L2", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_FAX_L1,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_FM1.png","Status Icon: Unread Fax L1", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_FAX_L2,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_FM2.png","Status Icon: Unread Fax L2", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_FAX_L1L2,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_FM12.png","Status Icon: Unread Fax L1+L2", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_EMAIL_L1,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_EM1.png","Status Icon: Unread Email L1", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_EMAIL_L2,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_EM2.png","Status Icon: Unread Email L2", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_EMAIL_L1L2,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_EM12.png","Status Icon: Unread Email L1+L2", FALSE, FORCE_ABM);
#ifndef __MMI_DUAL_SIM_MASTER__
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_SMS_INDICATOR,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_MGE.png","Status Icon: Message", FALSE, FORCE_ABM);
#else	/* __MMI_DUAL_SIM_MASTER__ */
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_SMS_INDICATOR,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Callforward\\\\Master\\\\SI_MGE_1.png","Status Icon: Message", FALSE, FORCE_ABM);
#endif	/* __MMI_DUAL_SIM_MASTER__ */

#ifndef __MMI_DUAL_SIM_MASTER__
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_CALL_DIVERT_L1,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_FOR01.png","Status Icon: Call Divert L1", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_CALL_DIVERT_L2,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_FOR02.png","Status Icon: Call Divert L2", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_CALL_DIVERT_L1L2,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_FOR.png","Status Icon: Call Divert L1+L2", FALSE, FORCE_ABM);
#else
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_CALL_DIVERT_L1,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Callforward\\\\Master\\\\SI_FOR_L1_1.png","Status Icon: Call Divert L1", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_CALL_DIVERT_L2,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Callforward\\\\Master\\\\SI_FOR_L2_1.png","Status Icon: Call Divert L2", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_CALL_DIVERT_L1L2,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Callforward\\\\Master\\\\SI_FOR_1.png","Status Icon: Call Divert L1+L2", FALSE, FORCE_ABM);
#endif	/* __MMI_DUAL_SIM_MASTER__ */

    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_VOICE_RECORD,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_REC.png","Status Icon: Voice record", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_MUTE,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_MUTE.png","Status Icon: Mute", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_STOPWATCH,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_STWATCH.png","Image for Stopwatch Icon", FALSE, FORCE_ABM);
   #if defined(__J2ME__) && defined(J2ME_SUPPORT_BACKGROUND)
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_JAVA_BG_VM,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_JAVA.png","Java bg vm", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_JAVA_BG_VM_AUDIO,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_AJAVA.png","Java bg vm audio", FALSE, FORCE_ABM);
   #endif

#ifdef __MMI_DUAL_SIM_MASTER__
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_WAP1,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Push\\\\SI_WMAL1.png","Status Icon: Wap sim1", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_WAP2,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Push\\\\SI_WMAL2.png","Status Icon: Wap sim2", FALSE, FORCE_ABM);
#else /* __MMI_DUAL_SIM_MASTER__ */
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_WAP,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_WMAL.png","Status Icon: Wap", FALSE, FORCE_ABM);
#endif /* __MMI_DUAL_SIM_MASTER__ */

#ifndef __MMI_DUAL_SIM_MASTER__
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_NETWORK_CIPHER_GSM,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_NCGSM.png","Network Ciphering for GSM", FALSE, FORCE_ABM);//021505 Calvin added
#endif
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_NETWORK_CIPHER_GPRS,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_NCGPRS.png","Network Ciphering for GPRS", FALSE, FORCE_ABM);//021505 Calvin added

#ifdef __MMI_AUTO_ANSWER_MACHINE__
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_AUTOAM_REC, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_AUTOAM_Record.png","auto answer machine record", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_AUTOAM_UNREAD, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_AUTOAM_Message.png","auto answer machine unread", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_AUTOAM_ON, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_AUTOAM.png","auto answer machine on", FALSE, FORCE_ABM);
#endif /* __MMI_AUTO_ANSWER_MACHINE__ */ 

   /* Max, for IMPS */
   #ifdef __MMI_IMPS__
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif

#ifdef __MMI_WLAN_FEATURES__
    ADD_APPLICATION_IMAGE_TYPE(IMG_ID_DTCNT_WLAN_STATUS_DISCONNECT, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\WiFi\\\\wifi_disconnect.png","Image of WLAN", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_ID_DTCNT_WLAN_STATUS_SCANNING, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\WiFi\\\\SI_WIFI","Image of WLAN", FALSE, FORCE_ABM_SEQUENCE);
    ADD_APPLICATION_IMAGE_TYPE(IMG_ID_DTCNT_WLAN_STATUS_CONNECT1, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\WiFi\\\\SI_WIFI\\\\0.png","Image of WLAN", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_ID_DTCNT_WLAN_STATUS_CONNECT2, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\WiFi\\\\SI_WIFI\\\\1.png","Image of WLAN", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_ID_DTCNT_WLAN_STATUS_CONNECT3, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\WiFi\\\\SI_WIFI\\\\2.png","Image of WLAN", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_ID_DTCNT_WLAN_STATUS_CONNECT4, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\WiFi\\\\SI_WIFI\\\\3.png","Image of WLAN", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_ID_DTCNT_WLAN_STATUS_CONNECT5, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\WiFi\\\\SI_WIFI\\\\4.png","Image of WLAN", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_ID_DTCNT_WLAN_STATUS_CONNECT6, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\WiFi\\\\SI_WIFI\\\\5.png","Image of WLAN", FALSE, FORCE_ABM);
#endif

#ifndef __MMI_DUAL_SIM_MASTER__
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_CSD,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_CSD.png","Status Icon: CSD", FALSE, FORCE_ABM);
#else/* __MMI_DUAL_SIM_MASTER__ */
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_CSD_SIM1,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\CSD\\\\SI_CSD1.png","Status Icon: CSD", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_CSD_SIM2,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\CSD\\\\SI_CSD2.png","Status Icon: CSD", FALSE, FORCE_ABM);
#endif /* __MMI_DUAL_SIM_MASTER__ */

#ifndef __MMI_DUAL_SIM_MASTER__
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_EDGE,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_EDGE.png","Status Icon: BT", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_EDGEC,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_EDGEC.png","Status Icon: BT", FALSE, FORCE_ABM);
#endif /* __MMI_DUAL_SIM_MASTER__ */

#ifdef __MMI_PICT_BRIDGE_SUPPORT__
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_PRINT,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_PRINT.png","Status Icon: print", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_PRINT_FAIL,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_PRINT_FAIL.png","Status Icon: print_fail", FALSE, FORCE_ABM);
#endif

#ifdef __MMI_CALL_INDICATOR__
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_CALL_INDICATOR_ACTIVE,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_CallActive.png","Status Icon: call indicator", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_CALL_INDICATOR_HOLD,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_CallHold.png","Status Icon: call indicator HOLD", FALSE, FORCE_ABM);
#endif 

#ifdef __MMI_MOBILE_TV_PLAYER__
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_MTV_SIGNAL,CUST_IMG_PATH"\\\\MainLCD\\\\MobileTVPlayer\\\\Signal","Status Icon: MTV signal", FALSE, FORCE_ABM_SEQUENCE);
#endif 


#if (defined(OBIGO_Q05A) || defined(JATAAYU_SUPPORT)) && defined(WAP_SUPPORT)
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_SECURITY,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_KEY.png","", FALSE, FORCE_ABM);
#endif

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_OUTBOX_INDICATOR,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_OUTBOXIND.png","Status Icon: outboxind", FALSE, FORCE_ABM);
#endif
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_SMS_SENDING,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_SMSSENDING.png","Status Icon: sms sending", FALSE, FORCE_ABM);

#ifdef __MMI_AUDIO_PLAYER__
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_AUDPLY,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_AUDPLY.png","Status Icon: audio player", FALSE, FORCE_ABM);
#endif

#ifdef __MMI_MEDIA_PLAYER__
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_MEDPLY,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_MPLAYER.png","Status Icon: media player", FALSE, FORCE_ABM);
#endif

#ifdef __MMI_PROV_MESSAGE_SUPPORT__
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_PROVMSG,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_ProvMsg.png","Status Icon: Prov message", FALSE, FORCE_ABM);
#ifdef __MMI_DUAL_SIM_MASTER__
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_PROVMSG_SIM1,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\ProvBox\\\\SI_ProvMsgSIM1.png","Status Icon: Prov message", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_PROVMSG_SIM2,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\ProvBox\\\\SI_ProvMsgSIM2.png","Status Icon: Prov message", FALSE, FORCE_ABM);
#endif
#endif

    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_NET_L1,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_NETL1.png","Status Icon: Net L1", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_NET_L2,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_NETL2.png","Status Icon: Net L2", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_NET_L1L2,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_NETL12.png","Status Icon: Net L12", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_VIDEO_L1,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_VDL1.png","Status Icon: video L1", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_VIDEO_L2,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_VDL2.png","Status Icon: video L2", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_VIDEO_L1L2,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_VDL12.png","Status Icon: video L12", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_EMAIL_REF,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_EMRF.png","Status Icon: email refresh", FALSE, FORCE_ABM);
#if defined(__AGPS_SUPPORT__) && defined(__SUPL_SUPPORT__)
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_AGPS_STATE, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GPS","Status Icon: AGPS state", FALSE, FORCE_ABM);
#endif
#ifdef __MMI_SYNCML_STATUS_ICON_SUPPORT__    
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_SYNCML, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_DS.png","Status Icon: syncml on", FALSE, FORCE_ABM);
#endif
#ifdef __QQIM_SUPPORT__
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_QQIM_AWAY,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_QQIM_AWAY.png","Status Icon: QQIM away", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_QQIM_INVISIBLE,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_QQIM_INVISIBLE.png","Status Icon: QQIM invisible", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_QQIM_MSG,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_QQIM_MSG.png","Status Icon: QQIM msg", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_QQIM_OFFLINE,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_QQIM_OFFLINE.png","Status Icon: QQIM offline", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_QQIM_ONLINE,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_QQIM_ONLINE.png","Status Icon: QQIM online", FALSE, FORCE_ABM);
#endif
/* Vogins Start */
#ifdef __VRE30_AM__
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_VRE_DEFAULT,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_VRE_default.png","Status Icon: VRE default", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_VRE_FETION,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_VRE_Fetion.png","Status Icon: VRE fetion", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_VRE_MSN,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_VRE_MSN.png","Status Icon: VRE MSN", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_VRE_PUSHMAIL,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_VRE_Pushmail.png","Status Icon: VRE pushmail", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_VRE_QQ,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_VRE_QQ.png","Status Icon: VRE QQ", FALSE, FORCE_ABM);
#endif
/* Vogins End */
#ifdef __MMI_DUAL_SIM_MASTER__ 
    // mercury image
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_MASTER_SIGNAL_STRENGTH,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Master\\\\SI_SIG1",
                           "Slave Status Icon: Signal strength", FALSE, FORCE_ABM_SEQUENCE);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_MASTER_SIGNAL_STRENGTH_L1,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Master\\\\SI_SIG1_L1",
                           "Status Icon: Signal strength with L1", FALSE, FORCE_ABM_SEQUENCE);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_MASTER_SIGNAL_STRENGTH_L2,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Master\\\\SI_SIG1_L2",
                           "Status Icon: Signal strength with L2", FALSE, FORCE_ABM_SEQUENCE);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_MASTER_SIGNAL_CLOSED,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Master\\\\SI_SIG1_CLOSE\\\\SI_SIG_1_CLOSE.png",
                           "Slave Status Icon: rf closed", FALSE, FORCE_ABM);

    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_SLAVE_SIGNAL_STRENGTH,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Slave\\\\SI_SIG2",
                           "Slave Status Icon: Signal strength", FALSE, FORCE_ABM_SEQUENCE);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_SLAVE_SIGNAL_STRENGTH_L1,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Slave\\\\SI_SIG2_L1",
                           "Status Icon: Signal strength with L1", FALSE, FORCE_ABM_SEQUENCE);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_SLAVE_SIGNAL_STRENGTH_L2,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Slave\\\\SI_SIG2_L2",
                           "Status Icon: Signal strength with L2", FALSE, FORCE_ABM_SEQUENCE);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_SLAVE_SIGNAL_CLOSED,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Slave\\\\SI_SIG2_CLOSE\\\\SI_SIG_2_CLOSE.png",
                           "Slave Status Icon: rf closed", FALSE, FORCE_ABM);

    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_MASTER_NETWORK_CIPHER_GSM,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Callforward\\\\Master\\\\SI_Ncipher.png",
                           "Slave Status Icon: master gsm", FALSE, FORCE_ABM);

    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_SLAVE_NETWORK_CIPHER_GSM,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Callforward\\\\Slave\\\\SI_Ncipher.png",
                           "Slave Status Icon: slave gsm", FALSE, FORCE_ABM);

    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_VOICE_L1_MASTER,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Master\\\\SI_VOML1.png",
                           "Master Status Icon: master unread voice L1", FALSE, FORCE_ABM);

    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_VOICE_L2_MASTER,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Master\\\\SI_VOML2.png",
                           "Master Status Icon: master unread voice L2", FALSE, FORCE_ABM);

    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_VOICE_L1L2_MASTER,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Master\\\\SI_VOML12.png",
                           "Master Status Icon: master unread voice L12", FALSE, FORCE_ABM);

    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_FAX_L1_MASTER,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Master\\\\SI_FM1.png",
                           "Master Status Icon: master unread fax L1", FALSE, FORCE_ABM);

    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_FAX_L2_MASTER,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Master\\\\SI_FM2.png",
                           "Master Status Icon: master unread fax L2", FALSE, FORCE_ABM);

    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_FAX_L1L2_MASTER,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Master\\\\SI_FM12.png",
                           "Master Status Icon: master unread fax L12", FALSE, FORCE_ABM);

    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_EMAIL_L1_MASTER,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Master\\\\SI_EM1.png",
                           "Master Status Icon: master unread email L1", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_EMAIL_L2_MASTER,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Master\\\\SI_EM2.png",
                           "Master Status Icon: master unread email L2", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_EMAIL_L1L2_MASTER,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Master\\\\SI_EM12.png",
                           "Master Status Icon: master unread email L12", FALSE, FORCE_ABM);

    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_NET_L1_MASTER,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Master\\\\SI_NETL1.png",
                           "Master Status Icon: master unread net L1", FALSE, FORCE_ABM);

    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_NET_L2_MASTER,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Master\\\\SI_NETL2.png",
                           "Master Status Icon: master unread net L2", FALSE, FORCE_ABM);

    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_NET_L1L2_MASTER,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Master\\\\SI_NETL12.png",
                           "Master Status Icon: master unread net L12", FALSE, FORCE_ABM);
   ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_VIDEO_L1_MASTER,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Master\\\\SI_VDL1.png",
                           "Master Status Icon: master unread video L1", FALSE, FORCE_ABM);
    
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_VIDEO_L2_MASTER,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Master\\\\SI_VDL2.png",
                           "Master Status Icon: master unread video L2", FALSE, FORCE_ABM);
    
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_VIDEO_L1L2_MASTER,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Master\\\\SI_VDL12.png",
                           "Master Status Icon: master unread video L12", FALSE, FORCE_ABM);

    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_VOICE_L1_SLAVE,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Slave\\\\SI_VOML1.png",
                           "Master Status Icon: slave unread voice L1", FALSE, FORCE_ABM);

    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_VOICE_L2_SLAVE,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Slave\\\\SI_VOML2.png",
                           "Slave Status Icon: slave unread voice L2", FALSE, FORCE_ABM);

    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_VOICE_L1L2_SLAVE,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Slave\\\\SI_VOML12.png",
                           "Slave Status Icon: slave unread voice L12", FALSE, FORCE_ABM);

    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_FAX_L1_SLAVE,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Slave\\\\SI_FM1.png",
                           "Slave Status Icon: slave unread fax L1", FALSE, FORCE_ABM);

    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_FAX_L2_SLAVE,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Slave\\\\SI_FM2.png",
                           "Slave Status Icon: slave unread fax L2", FALSE, FORCE_ABM);

    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_FAX_L1L2_SLAVE,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Slave\\\\SI_FM12.png",
                           "Slave Status Icon: slave unread fax L12", FALSE, FORCE_ABM);

    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_EMAIL_L1_SLAVE,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Slave\\\\SI_EM1.png",
                           "Slave Status Icon: slave unread email L1", FALSE, FORCE_ABM);

    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_EMAIL_L2_SLAVE,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Slave\\\\SI_EM2.png",
                           "Slave Status Icon: slave unread email L2", FALSE, FORCE_ABM);

    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_EMAIL_L1L2_SLAVE,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Slave\\\\SI_EM12.png",
                           "Slave Status Icon: slave unread email L12", FALSE, FORCE_ABM);

    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_NET_L1_SLAVE,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Slave\\\\SI_NETL1.png",
                           "Slave Status Icon: slave unread net L1", FALSE, FORCE_ABM);

    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_NET_L2_SLAVE,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Slave\\\\SI_NETL2.png",
                           "Slave Status Icon: slave unread net L2", FALSE, FORCE_ABM);

    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_NET_L1L2_SLAVE,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Slave\\\\SI_NETL12.png",
                           "Slave Status Icon: slave unread net L12", FALSE, FORCE_ABM);
       
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_VIDEO_L1_SLAVE,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Slave\\\\SI_VDL1.png",
                           "Slave Status Icon: slave unread video L1", FALSE, FORCE_ABM);
    
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_VIDEO_L2_SLAVE,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Slave\\\\SI_VDL2.png",
                           "Slave Status Icon: slave unread video L2", FALSE, FORCE_ABM);
    
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_UNREAD_VIDEO_L1L2_SLAVE,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\Statusicons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Slave\\\\SI_VDL12.png",
                           "Slave Status Icon: slave unread video L12", FALSE, FORCE_ABM);

    ADD_APPLICATION_IMAGE_TYPE(IMG_SLAVE_CALL_FORWARD, CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Callforward\\\\Slave\\\\SI_FOR_2.png",
                           "Status Icon: slave Call Divert", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SLAVE_CALL_FORWARD_L1, CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Callforward\\\\Slave\\\\SI_FOR_L1_2.png",
                           "Status Icon: slave Call Divert L1", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SLAVE_CALL_FORWARD_L2, CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Callforward\\\\Slave\\\\SI_FOR_L2_2.png",
                           "Status Icon: slave Call Divert L2", FALSE, FORCE_ABM);
    
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_SLAVE_ROAMING_INDICATOR, CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Callforward\\\\Slave\\\\SI_RM_2.png",
                           "Status Icon: Slave Roaming", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_SLAVE_SMS_INDICATOR, CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Callforward\\\\Slave\\\SI_MGE_2.png",
                           "Status Icon: SLAVE Message", FALSE, FORCE_ABM);

    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_MMS_UNREAD_INDICATOR_SIM1, CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\MMS\\\\Master\\\SI_UNREAD_1.png",
                           "Status Icon: Master unread mms", FALSE, FORCE_ABM);

    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_MMS_UNREAD_INDICATOR_SIM2, CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\MMS\\\\Slave\\\SI_UNREAD_2.png",
                           "Status Icon: Slave unread mms", FALSE, FORCE_ABM);

    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_MMS_BUSY_INDICATOR_SIM1, CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\MMS\\\\Master\\\SI_BUSY_1.png",
                           "Status Icon: Master unread mms", FALSE, FORCE_ABM);

    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_MMS_BUSY_INDICATOR_SIM2, CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\MMS\\\\Slave\\\SI_BUSY_2.png",
                           "Status Icon: Slave unread mms", FALSE, FORCE_ABM);

    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_EDGE_SIM1, CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\GPRS\\\\Master\\\SI_EDGE_SIM1.png",
                           "Status Icon: Master EDGE", FALSE, FORCE_ABM);
    
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_GPRS_SERVICE_SIM1, CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\GPRS\\\\Master\\\SI_GPRS_SIM1.png",
                           "Status Icon: Master GPRS", FALSE, FORCE_ABM);
    
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_EDGEC_SIM1, CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\GPRS\\\\Master\\\SI_EDGEC_SIM1.png",
                           "Status Icon: Master EDGEC", FALSE, FORCE_ABM);
    
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_GPRS_ATT_NO_PDP_INDICATOR_SIM1, CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\GPRS\\\\Master\\\SI_GPRSC_SIM1.png",
                           "Status Icon: Master GPRS_ATT_NO_PDP_INDICATOR", FALSE, FORCE_ABM);

    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_EDGE_SIM2, CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\GPRS\\\\Slave\\\SI_EDGE_SIM2.png",
                           "Status Icon: Slave EDGE", FALSE, FORCE_ABM);
    
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_GPRS_SERVICE_SIM2, CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\GPRS\\\\Slave\\\SI_GPRS_SIM2.png",
                           "Status Icon: Slave GPRS", FALSE, FORCE_ABM);
    
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_EDGEC_SIM2, CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\GPRS\\\\Slave\\\SI_EDGEC_SIM2.png",
                           "Status Icon: Slave EDGEC", FALSE, FORCE_ABM);
    
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_GPRS_ATT_NO_PDP_INDICATOR_SIM2, CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\GPRS\\\\Slave\\\SI_GPRSC_SIM2.png",
                           "Status Icon: Slave GPRS_ATT_NO_PDP_INDICATOR", FALSE, FORCE_ABM);
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_CARD1MISSED_CALL_INDICATOR,
                           CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Callforward\\\\Master\\\SI_MCA_1.png",
                           "Status Icon: Missed Call", FALSE, FORCE_ABM);
        
    ADD_APPLICATION_IMAGE_TYPE(IMG_SI_CARD2MISSED_CALL_INDICATOR,
                           CUST_IMG_PATH "\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Callforward\\\\Slave\\\\SI_MCA_2.png",
                           "Status Icon: Missed Call", FALSE, FORCE_ABM);
#endif

/* 082304 MTK Calvin added compile option */    
#ifdef __MMI_SUBLCD__
    ADD_APPLICATION_IMAGE2(IMG_SLSI_SILENT,CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\SB_SIL.BMP","Sub LCD Status Icon: Silent");
    ADD_APPLICATION_IMAGE2(IMG_SLSI_SIGNAL_STRENGTH,CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\signal\\\\SB_SIG","Sub LCD Status Icon: Signal strength");
    ADD_APPLICATION_IMAGE2(IMG_SLSI_BATTERY_STRENGTH,CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\battery\\\\SB_BAT","Sub LCD Status Icon: Battery strength");
    ADD_APPLICATION_IMAGE2(IMG_SLSI_SMS_INDICATOR,CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\SB_MG.BMP","Sub LCD Status Icon: Message");
    ADD_APPLICATION_IMAGE2(IMG_SLSI_RING,CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\SB_RING.BMP","Sub LCD Status Icon: Ring");
    ADD_APPLICATION_IMAGE2(IMG_SLSI_VIBRATE,CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\SB_VIB.BMP","Sub LCD Status Icon: Vibrator");
    ADD_APPLICATION_IMAGE2(IMG_SLSI_VIBRATE_AND_RING,CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\SB_VR.BMP","Sub LCD Status Icon: Vibrate and Ring");
    ADD_APPLICATION_IMAGE2(IMG_SLSI_VIBRATE_THEN_RING,CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\SB_VTR.BMP","Sub LCD Status Icon: Vibrate then Ring");
    ADD_APPLICATION_IMAGE2(IMG_SLSI_ALARM,CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\SB_ALARM.BMP","Sub LCD Status Icon: Alarm");
    ADD_APPLICATION_IMAGE2(IMG_SLSI_MISSED_CALL,CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\SB_MCA.BMP","Sub LCD Status Icon: Missed Call");
#endif
}

#if(ENABLE_CIRCULAR_3D_MENU)
/*----------------------------------------------------------------------------
Function:			PopulateCircular3DMenuResources
Description:		Resource populator for the circular 3D menu
Input Parameters:	none
Output Parameters:	none
Returns:			void
----------------------------------------------------------------------------*/

void PopulateCircular3DMenuResources(void)
{	

	ADD_APPLICATION_IMAGE(CM3D_COMMON_IMAGE0_IMAGE_ID,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\CIRCULAR_3D\\\\CM3D4ball.gif");
	ADD_APPLICATION_IMAGE(CM3D_COMMON_IMAGE1_IMAGE_ID,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\CIRCULAR_3D\\\\CM3D5ball.gif");
	ADD_APPLICATION_IMAGE(CM3D_COMMON_IMAGE2_IMAGE_ID,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\CIRCULAR_3D\\\\CM3D6ball.gif");
	ADD_APPLICATION_IMAGE(CM3D_COMMON_IMAGE3_IMAGE_ID,CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\CIRCULAR_3D\\\\CM3D7ball.gif");

}
#endif
void PopulateThemeResources(void)
{	
}

#endif


