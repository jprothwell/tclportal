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
#include "PixtelDataTypes.h"
#ifdef __MMI_WLAN_FEATURES__
#include "DataAccountResDef.h"
#endif

#ifdef DEVELOPER_BUILD_FIRST_PASS
#include "PopulateRes.h"

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
#endif /* __UI_UNIFIED_COMPOSER_EDITOR_CATEGORY__ */
ADD_APPLICATION_IMAGE2 (WGUI_DEFAULT_PREVIEW_IMAGE_ID, CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\broken.gif", "Default Preview");
}


void PopulateMMSViewerRes(void)
{
#ifdef __UI_MMS_VIEWER_CATEGORY__
    ADD_APPLICATION_IMAGE2 (WGUI_MV_ATTACHFILE_ICON_IMAGE_ID, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\MMS_attach.bmp", "Attachment ICON");
    ADD_APPLICATION_IMAGE2 (WGUI_MV_REFERENCE_ICON_IMAGE_ID, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\MMS_ref.bmp", "Reference ICON");
    ADD_APPLICATION_IMAGE2 (WGUI_MV_RING_ICON_IMAGE_ID, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\MMS_Ring.bmp", "Ring ICON");
    //ADD_APPLICATION_IMAGE2 (WGUI_MV_TITLE_ICON_IMAGE_ID, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\MMS_title.bmp", "Title ICON");
    ADD_APPLICATION_IMAGE2 (WGUI_MV_BAR_ICON_IMAGE_ID, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\BAR.gif", "Bar ICON");
    ADD_APPLICATION_IMAGE2 (WGUI_MV_RING_STOP_ICON_IMAGE_ID, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\MMS_RingStop.bmp", "Left Arrow ICON");

    ADD_APPLICATION_IMAGE2 (WGUI_MV_LEFT_ARROW_ICON_IMAGE_ID, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\MMS_LA.bmp", "Left Arrow ICON");
    ADD_APPLICATION_IMAGE2 (WGUI_MV_LEFT_ARROW_DOWN_ICON_IMAGE_ID, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\MMS_LADown.bmp", "Left Arrow Down ICON");
    ADD_APPLICATION_IMAGE2 (WGUI_MV_RIGHT_ARROW_ICON_IMAGE_ID, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\MMS_RA.bmp", "Right Arrow ICON");
    ADD_APPLICATION_IMAGE2 (WGUI_MV_RIGHT_ARROW_DOWN_ICON_IMAGE_ID, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\MMS_RADown.bmp", "Right Arrow Down ICON");

    ADD_APPLICATION_IMAGE2 (WGUI_MV_DRM_IMAGE_LOCK_ID, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\Image_lock.gif", "DRM image lock");
    ADD_APPLICATION_IMAGE2 (WGUI_MV_DRM_VIDEO_LOCK_ID, CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\Video_lock.gif", "DRM video lock");
#endif /* __UI_MMS_VIEWER_CATEGORY__ */
}


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

	ADD_APPLICATION_STRING2(WGUI_CATEGORY_CLEAR_STRING_ID,"Clear","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_ABC_STRING_ID,"ABC","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_abc_STRING_ID,"abc","Category screens string");
#if defined(__MMI_SMART_FIRST_UPPERCASE__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_Abc_STRING_ID,"Abc","Category screens string");
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
    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_SPANISH_STRING_ID,"Es","Category screens string");
    #endif
#endif	
#if defined(__MMI_MULTITAP_POLISH__)||defined(__MMI_T9_POLISH__)||defined(__MMI_ZI_POLISH__) || defined(__MMI_CSTAR_POLISH__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_POLISH_STRING_ID,"PO","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_polish_STRING_ID,"po","Category screens string");
        
    #if defined(__MMI_SMART_FIRST_UPPERCASE__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_POLISH_STRING_ID,"Po","Category screens string");
    #endif
#endif
#if defined(__MMI_MULTITAP_DANISH__)||defined(__MMI_T9_DANISH__)||defined(__MMI_ZI_DANISH__) || defined(__MMI_CSTAR_DANISH__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_DANISH_STRING_ID,"DA","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_danish_STRING_ID,"da","Category screens string");
            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_DANISH_STRING_ID,"Da","Category screens string");
    #endif
#endif	
#if defined(__MMI_MULTITAP_FRENCH__)||defined(__MMI_T9_FRENCH__)||defined(__MMI_ZI_CA_FRENCH__)||defined(__MMI_ZI_EU_FRENCH__) || defined(__MMI_CSTAR_FRENCH__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_FRENCH_STRING_ID,"FR","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_french_STRING_ID,"fr","Category screens string");
                
    #if defined(__MMI_SMART_FIRST_UPPERCASE__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_FRENCH_STRING_ID,"Fr","Category screens string");
    #endif
#endif	
#if defined(__MMI_MULTITAP_GERMAN__)||defined(__MMI_T9_GERMAN__)||defined(__MMI_ZI_GERMAN__) || defined(__MMI_CSTAR_GERMAN__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_GERMAN_STRING_ID,"DE","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_german_STRING_ID,"de","Category screens string");
                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_GERMAN_STRING_ID,"De","Category screens string");
    #endif
#endif	
#if defined(__MMI_MULTITAP_ITALIAN__)||defined(__MMI_T9_ITALIAN__)||defined(__MMI_ZI_ITALIAN__) || defined(__MMI_CSTAR_ITALIAN__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_ITALIAN_STRING_ID,"IT","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_italian_STRING_ID,"it","Category screens string");
                        
    #if defined(__MMI_SMART_FIRST_UPPERCASE__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_ITALIAN_STRING_ID,"It","Category screens string");
    #endif
#endif	
#if defined (__MMI_T9_RUSSIAN__) || defined(__MMI_MULTITAP_RUSSIAN__)||defined(__MMI_ZI_RUSSIAN__)||defined(__MMI_ZI_RECOMMENDED_SIZE_RUSSIAN__) || defined(__MMI_CSTAR_RUSSIAN__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_RUSSIAN_STRING_ID,"RU","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_russian_STRING_ID,"ru","Category screens string");
                            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_RUSSIAN_STRING_ID,"Ru","Category screens string");
    #endif
#endif	
#if defined (__MMI_T9_BULGARIAN__) || defined(__MMI_MULTITAP_BULGARIAN__)||defined(__MMI_ZI_BULGARIAN__) || defined(__MMI_CSTAR_BULGARIAN__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_BULGARIAN_STRING_ID,"BG","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_bulgarian_STRING_ID,"bg","Category screens string");
                                
    #if defined(__MMI_SMART_FIRST_UPPERCASE__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_BULGARIAN_STRING_ID,"Bg","Category screens string");
    #endif
#endif
#if defined (__MMI_T9_UKRAINIAN__) || defined(__MMI_MULTITAP_UKRAINIAN__)||defined(__MMI_ZI_UKRAINIAN__) || defined(__MMI_CSTAR_UKRAINIAN__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_UKRAINIAN_STRING_ID,"UK","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_L_UKRAINIAN_STRING_ID,"uk","Category screens string");
                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_UKRAINIAN_STRING_ID,"Uk","Category screens string");
    #endif
#endif
#if defined(__MMI_MULTITAP_TURKISH__)||defined(__MMI_ZI_TURKISH__)||defined(__MMI_T9_TURKISH__) || defined(__MMI_CSTAR_TURKISH__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_TURKISH_STRING_ID,"TR","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_turkish_STRING_ID,"tr","Category screens string");
                                        
    #if defined(__MMI_SMART_FIRST_UPPERCASE__)
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
                                            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_PORTUGUESE_STRING_ID,"Pt","Category screens string");
    #endif
#endif	
#if defined(__MMI_MULTITAP_INDONESIAN__)||defined(__MMI_ZI_INDONESIAN__)||defined(__MMI_T9_INDONESIAN__)   || defined(__MMI_CSTAR_INDONESIAN__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_INDONESIAN_STRING_ID,"ID","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_indonesian_STRING_ID,"id","Category screens string");
                                                
    #if defined(__MMI_SMART_FIRST_UPPERCASE__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_INDONESIAN_STRING_ID,"Id","Category screens string");
    #endif
#endif	
#if defined(__MMI_MULTITAP_CZECH__)||defined(__MMI_T9_CZECH__)||defined(__MMI_ZI_CZECH__) || defined(__MMI_CSTAR_CZECH__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_CZECH_STRING_ID,"CZ","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_czech_STRING_ID,"cz","Category screens string");
                                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_CZECH_STRING_ID,"Cz","Category screens string");
    #endif
#endif	
#if defined(__MMI_MULTITAP_MALAY__)||defined(__MMI_ZI_MALAY__)||defined(__MMI_T9_MALAY__) || defined(__MMI_CSTAR_MALAY__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_MALAY_STRING_ID,"MS","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_malay_STRING_ID,"ms","Category screens string");
                                                        
    #if defined(__MMI_SMART_FIRST_UPPERCASE__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_MALAY_STRING_ID,"Ms","Category screens string");
    #endif
#endif	
#if defined(__MMI_MULTITAP_VIETNAMESE__)||defined(__MMI_ZI_VIETNAMESE__)||defined(__MMI_T9_VIETNAMESE__)   || defined(__MMI_CSTAR_VIETNAMESE__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_VIETNAMESE_STRING_ID,"VI","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_vietnamese_STRING_ID,"vi","Category screens string");
                                                            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_VIETNAMESE_STRING_ID,"Vi","Category screens string");
    #endif
#endif	
#if defined(__MMI_MULTITAP_FINNISH__)||defined(__MMI_T9_FINNISH__)||defined(__MMI_ZI_FINNISH__) || defined(__MMI_CSTAR_FINNISH__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_FINNISH_STRING_ID,"FI","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_finnish_STRING_ID,"fi","Category screens string");
                                                                
    #if defined(__MMI_SMART_FIRST_UPPERCASE__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_FINNISH_STRING_ID,"Fi","Category screens string");
    #endif
#endif
#if defined(__MMI_MULTITAP_HUNGARIAN__)||defined(__MMI_T9_HUNGARIAN__)||defined(__MMI_ZI_HUNGARIAN__)  || defined(__MMI_CSTAR_HUNGARIAN__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_HUNGARIAN_STRING_ID,"HG","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_hungarian_STRING_ID,"hg","Category screens string");
                                                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_HUNGARIAN_STRING_ID,"Hg","Category screens string");
    #endif
#endif	
#if defined(__MMI_MULTITAP_ARABIC__)||defined(__MMI_T9_ARABIC__) || defined(__MMI_ZI_ARABIC__)||defined(__MMI_CSTAR_ARABIC__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_ARABIC_STRING_ID,"AR","Category screens string");
#endif	
#if defined(__MMI_LANG_ARABIC__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_ARABIC_NUMERIC_STRING_ID,"AR 123","Arabic Numeric");
#endif	
#if defined(__MMI_MULTITAP_PERSIAN__) || defined(__MMI_ZI_PERSIAN__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_PERSIAN_STRING_ID,"FA","Category screens string");
#endif	

#if defined(__MMI_MULTITAP_URDU__) || defined(__MMI_ZI_URDU__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_URDU_STRING_ID,"UR","Category screens string");
#endif	

#if defined(__MMI_MULTITAP_HINDI__)||defined(__MMI_T9_HINDI__) || defined(__MMI_ZI_HINDI__)||defined(__MMI_CSTAR_HINDI__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_HINDI_STRING_ID,"HI","Category screens string");
#endif
#if defined(__MMI_MULTITAP_MARATHI__) || defined(__MMI_ZI_MARATHI__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_MARATHI_STRING_ID,"MA","Category screens string");
#endif
#if defined(__MMI_MULTITAP_TAMIL__) || defined(__MMI_ZI_TAMIL__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_TAMIL_STRING_ID,"TA","Category screens string");
#endif
#if defined(__MMI_MULTITAP_BENGALI__) || defined(__MMI_ZI_BENGALI__)  
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_BENGALI_STRING_ID,"BE","Category screens string");
#endif
#if defined(__MMI_MULTITAP_PUNJABI__) || defined(__MMI_ZI_PUNJABI__)   
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_PUNJABI_STRING_ID,"PU","Category screens string");
#endif
#if defined(__MMI_MULTITAP_TELUGU__) || defined(__MMI_ZI_TELUGU__) 
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_TELUGU_STRING_ID,"TE","Category screens string");
#endif

#if defined(__MMI_MULTITAP_KANNADA__) || defined(__MMI_ZI_KANNADA__) 
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_KANNADA_STRING_ID,"KN","Category screens string");
#endif

#if defined(__MMI_MULTITAP_GUJARATI__) || defined(__MMI_ZI_GUJARATI__) 
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_GUJARATI_STRING_ID,"GU","Category screens string");
#endif

#if defined(__MMI_MULTITAP_NORWEGIAN__)||defined(__MMI_T9_NORWEGIAN__)|| defined(__MMI_ZI_NORWEGIAN__) || defined(__MMI_CSTAR_NORWEGIAN__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_NORWEGIAN_STRING_ID,"NO","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_norwegian_STRING_ID,"no","Category screens string");
                                                                        
    #if defined(__MMI_SMART_FIRST_UPPERCASE__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_NORWEGIAN_STRING_ID,"No","Category screens string");
    #endif
#endif
#if defined(__MMI_MULTITAP_SLOVAK__)||defined(__MMI_T9_SLOVAK__)||defined(__MMI_ZI_SLOVAK__) || defined(__MMI_CSTAR_SLOVAK__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_SLOVAK_STRING_ID,"SK","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_slovak_STRING_ID,"sk","Category screens string");
                                                                            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_SLOVAK_STRING_ID,"Sk","Category screens string");
    #endif
#endif
#if defined(__MMI_MULTITAP_DUTCH__)||defined(__MMI_ZI_DUTCH__)||defined(__MMI_T9_DUTCH__)   || defined(__MMI_CSTAR_DUTCH__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_DUTCH_STRING_ID,"NL","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_dutch_STRING_ID,"nl","Category screens string");
                                                                                
    #if defined(__MMI_SMART_FIRST_UPPERCASE__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_DUTCH_STRING_ID,"Nl","Category screens string");
    #endif
#endif
#if defined(__MMI_MULTITAP_SWEDISH__)||defined(__MMI_T9_SWEDISH__)||defined(__MMI_ZI_SWEDISH__) || defined(__MMI_CSTAR_SWEDISH__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_SWEDISH_STRING_ID,"SV","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_swedish_STRING_ID,"sv","Category screens string");
                                                                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_SWEDISH_STRING_ID,"Sv","Category screens string");
    #endif
#endif

#if defined(__MMI_MULTITAP_CROATIAN__)||defined(__MMI_T9_CROATIAN__)||defined(__MMI_ZI_CROATIAN__) || defined(__MMI_CSTAR_CROATIAN__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_CROATIAN_STRING_ID,"HR","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_croatian_STRING_ID,"hr","Category screens string");
                                                                                        
    #if defined(__MMI_SMART_FIRST_UPPERCASE__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_CROATIAN_STRING_ID,"Hr","Category screens string");
    #endif
#endif
#if defined(__MMI_MULTITAP_ROMANIAN__)||defined(__MMI_ZI_ROMANIAN__)||defined(__MMI_T9_ROMANIAN__) || defined(__MMI_CSTAR_ROMANIAN__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_ROMANIAN_STRING_ID,"RO","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_romanian_STRING_ID,"ro","Category screens string");
                                                                                            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_ROMANIAN_STRING_ID,"Ro","Category screens string");
    #endif
#endif
#if defined(__MMI_MULTITAP_SLOVENIAN__)||defined(__MMI_T9_SLOVENIAN__)||defined(__MMI_ZI_SLOVENIAN__) || defined(__MMI_CSTAR_SLOVENIAN__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_SLOVENIAN_STRING_ID,"SL","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_slovenian_STRING_ID,"sl","Category screens string");
                                                                                                
    #if defined(__MMI_SMART_FIRST_UPPERCASE__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_SLOVENIAN_STRING_ID,"Sl","Category screens string");
    #endif
#endif

#if defined(__MMI_MULTITAP_GREEK__)||defined(__MMI_T9_GREEK__)||defined(__MMI_ZI_GREEK__) || defined(__MMI_CSTAR_GREEK__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_GREEK_STRING_ID,"EL","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_greek_STRING_ID,"el","Category screens string");
                                                                                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_GREEK_STRING_ID,"El","Category screens string");
    #endif
#endif

#if defined(__MMI_MULTITAP_XHOSA__)||defined(__MMI_T9_XHOSA__)||defined(__MMI_ZI_XHOSA__) || defined(__MMI_CSTAR_XHOSA__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_U_XHOSA_STRING_ID,"XH","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_L_XHOSA_STRING_ID,"xh","Category screens string");
                                                                                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_XHOSA_STRING_ID,"Xh","Category screens string");
    #endif
#endif

#if defined(__MMI_MULTITAP_SWAHILI__)||defined(__MMI_T9_SWAHILI__)||defined(__MMI_ZI_SWAHILI__) || defined(__MMI_CSTAR_SWAHILI__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_U_SWAHILI_STRING_ID,"SW","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_L_SWAHILI_STRING_ID,"sw","Category screens string");
                                                                                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_SWAHILI_STRING_ID,"Sw","Category screens string");
    #endif
#endif

#if defined(__MMI_MULTITAP_AFRIKAANS__)||defined(__MMI_T9_AFRIKAANS__)||defined(__MMI_ZI_AFRIKAANS__) || defined(__MMI_CSTAR_AFRIKAANS__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_U_AFRIKAANS_STRING_ID,"AF","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_L_AFRIKAANS_STRING_ID,"af","Category screens string");
                                                                                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_AFRIKAANS_STRING_ID,"Af","Category screens string");
    #endif
#endif

#if defined(__MMI_MULTITAP_ZULU__)||defined(__MMI_T9_ZULU__)||defined(__MMI_ZI_ZULU__) || defined(__MMI_CSTAR_ZULU__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_U_ZULU_STRING_ID,"ZU","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_L_ZULU_STRING_ID,"zu","Category screens string");
                                                                                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_ZULU_STRING_ID,"Zu","Category screens string");
    #endif
#endif

#if defined(__MMI_MULTITAP_LITHUANIAN__)||defined(__MMI_T9_LITHUANIAN__)||defined(__MMI_ZI_LITHUANIAN__) || defined(__MMI_CSTAR_LITHUANIAN__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_U_LITHUANIAN_STRING_ID,"LT","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_L_LITHUANIAN_STRING_ID,"lt","Category screens string");
                                                                                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_LITHUANIAN_STRING_ID,"Lt","Category screens string");
    #endif
#endif

#if defined(__MMI_MULTITAP_LATVIAN__)||defined(__MMI_T9_LATVIAN__)||defined(__MMI_ZI_LATVIAN__) || defined(__MMI_CSTAR_LATVIAN__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_U_LATVIAN_STRING_ID,"LV","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_L_LATVIAN_STRING_ID,"lv","Category screens string");
                                                                                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_LATVIAN_STRING_ID,"Lv","Category screens string");
    #endif
#endif

#if defined(__MMI_MULTITAP_ESTONIAN__)||defined(__MMI_T9_ESTONIAN__)||defined(__MMI_ZI_ESTONIAN__) || defined(__MMI_CSTAR_ESTONIAN__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_U_ESTONIAN_STRING_ID,"ET","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_L_ESTONIAN_STRING_ID,"et","Category screens string");
                                                                                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_ESTONIAN_STRING_ID,"Et","Category screens string");
    #endif
#endif

#if defined(__MMI_MULTITAP_ARMENIAN__)||defined(__MMI_T9_ARMENIAN__)||defined(__MMI_ZI_ARMENIAN__) || defined(__MMI_CSTAR_ARMENIAN__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_U_ARMENIAN_STRING_ID,"HY","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_L_ARMENIAN_STRING_ID,"hy","Category screens string");
                                                                                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_ARMENIAN_STRING_ID,"Hy","Category screens string");
    #endif
#endif

#if defined(__MMI_MULTITAP_GEORGIAN__)||defined(__MMI_T9_GEORGIAN__)||defined(__MMI_ZI_GEORGIAN__) || defined(__MMI_CSTAR_GEORGIAN__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_GEORGIAN_STRING_ID,"KA","Category screens string");
#endif

#if defined(__MMI_MULTITAP_MOLDOVAN__)||defined(__MMI_T9_MOLDOVAN__)||defined(__MMI_ZI_MOLDOVAN__) || defined(__MMI_CSTAR_MOLDOVAN__)
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_U_MOLDOVAN_STRING_ID,"MO","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_L_MOLDOVAN_STRING_ID,"mo","Category screens string");
                                                                                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__)
	    ADD_APPLICATION_STRING2(WGUI_CATEGORY_FIRST_U_MOLDOVAN_STRING_ID,"Mo","Category screens string");
    #endif
#endif


#if defined(__MMI_CSTAR__)
    ADD_APPLICATION_STRING2(STR_INPUT_METHOD_CSTAR_NEW_WORD,"New Word","Cstar input method string");
#endif /*defined(__MMI_CSTAR__)*/

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

	ADD_APPLICATION_STRING2(STR_GUI_TIME_AM,"AM","String for AM");
	ADD_APPLICATION_STRING2(STR_GUI_TIME_PM,"PM","String for PM");

	ADD_APPLICATION_STRING2(STR_GUI_TIME_AM_ENG, "AM", "String for AM in English");
	ADD_APPLICATION_STRING2(STR_GUI_TIME_PM_ENG, "PM", "String for PM in English");

	/*code ended vandana mehtani*/
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_EDIT_STRING_ID,"Edit","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_DONE_STRING_ID,"Done","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_ON_STRING_ID,"On","Category screens string");
	ADD_APPLICATION_STRING2(WGUI_CATEGORY_OFF_STRING_ID,"Off","Category screens string");
	ADD_APPLICATION_IMAGE2(WGUI_VOLUME_LEVEL1,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_SC01.gif","VOL LEVEL1");
	ADD_APPLICATION_IMAGE2(WGUI_VOLUME_LEVEL2,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_SC02.gif","VOL LEVEL2");
	ADD_APPLICATION_IMAGE2(WGUI_VOLUME_LEVEL3,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_SC03.gif","VOL LEVEL3");
	ADD_APPLICATION_IMAGE2(WGUI_VOLUME_LEVEL4,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_SC04.gif","VOL LEVEL4");
	ADD_APPLICATION_IMAGE2(WGUI_VOLUME_LEVEL5,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_SC05.gif","VOL LEVEL5");
	ADD_APPLICATION_IMAGE2(WGUI_VOLUME_LEVEL6,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_SC06.gif","VOL LEVEL6");
	ADD_APPLICATION_IMAGE2(WGUI_VOLUME_LEVEL7,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_SC07.gif","VOL LEVEL7");
//PMT HIMANSHU START 20050729
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)      /* 081206 volume control */
	ADD_APPLICATION_IMAGE2(WGUI_VOLUME_UP_UP_IMAGE_ID,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_up_up.bmp","Volume up button normal image");
	ADD_APPLICATION_IMAGE2(WGUI_VOLUME_UP_DOWN_IMAGE_ID,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_up_down.bmp","Volume up button pressed image");
	ADD_APPLICATION_IMAGE2(WGUI_VOLUME_DOWN_UP_IMAGE_ID,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_down_up.bmp","Volume down button normal image");
	ADD_APPLICATION_IMAGE2(WGUI_VOLUME_DOWN_DOWN_IMAGE_ID,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_down_down.bmp","Volume down button pressed image");
#endif
//PMT HIMANSHU END 20050729
	/*code ended vandana mehtani*/
	ADD_APPLICATION_IMAGE2(WGUI_SLIDE_CONTROL_BG_IMAGE_ID,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Valuemap\\\\MAP.BMP","Background for Slide Control");
	ADD_APPLICATION_IMAGE2(WGUI_SLIDE_CONTROL_SI_IMAGE_ID,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Valuemap\\\\INDICATE.BMP","Slide Indicator image for Slide Control");

	ADD_APPLICATION_IMAGE2(WGUI_INPUT_INFORMATION_ICON1,CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\MUT.BMP","Icon for Multitap input mode");


#ifdef SVG12_SUPPORT
	ADD_APPLICATION_IMAGE2(IMG_SVG_DEFAULT_ICON,CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\svg_tiny_logo.svg","Icon for SVG loading");
#endif

    /* Dialing Screen */
#ifdef __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__
    ADD_APPLICATION_IMAGE2(IMG_DIALING_SCREEN,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\DUALMODE_TH_DIALING_SCREEN.GIF","Image of Dialing Screen");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_0,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\TH_DIALING_KEY0.BMP","Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_1,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\TH_DIALING_KEY1.BMP","Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_2,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\TH_DIALING_KEY2.BMP","Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_3,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\TH_DIALING_KEY3.BMP","Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_4,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\TH_DIALING_KEY4.BMP","Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_5,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\TH_DIALING_KEY5.BMP","Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_6,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\TH_DIALING_KEY6.BMP","Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_7,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\TH_DIALING_KEY7.BMP","Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_8,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\TH_DIALING_KEY8.BMP","Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_9,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\TH_DIALING_KEY9.BMP","Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_HASH,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\TH_DIALING_KEY_HASH.BMP","Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_STAR,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\TH_DIALING_KEY_STAR.BMP","Image of Dialing Key");
#else   /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
	ADD_APPLICATION_IMAGE2(IMG_DIALING_SCREEN,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_SCREEN.GIF","Image of Dialing Screen");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_0,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_KEY0.BMP","Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_1,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_KEY1.BMP","Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_2,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_KEY2.BMP","Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_3,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_KEY3.BMP","Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_4,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_KEY4.BMP","Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_5,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_KEY5.BMP","Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_6,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_KEY6.BMP","Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_7,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_KEY7.BMP","Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_8,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_KEY8.BMP","Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_9,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_KEY9.BMP","Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_HASH,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_KEY_HASH.BMP","Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_STAR,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_KEY_STAR.BMP","Image of Dialing Key");
#endif  /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */

#if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
#ifdef __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_PHB,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\DUALMODE_TH_DIALING_PHONEBOOK.BMP","Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_CALL,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\DUALMODE_TH_DIALING_CALL.BMP","Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_CALL_SLAVE,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\DUALMODE_TH_DIALING_CALL_SLAVE.BMP","Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_PHB_DISABLED,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\DUALMODE_TH_DIALING_PHONEBOOK_DISABLED.BMP","Image of Disabled Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_CALL_DISABLED,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\DUALMODE_TH_DIALING_CALL_DISABLED.BMP","Image of Disabled Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_CALL_SLAVE_DISABLED,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\DUALMODE_TH_DIALING_CALL_SLAVE_DISABLED.BMP","Image of Dialing Key");
#else   /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_PHB,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_PHONEBOOK.BMP","Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_CALL,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_CALL.BMP","Image of Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_PHB_DISABLED,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_PHONEBOOK_DISABLED.BMP","Image of Disabled Dialing Key");
	ADD_APPLICATION_IMAGE2(IMG_DIALING_KEY_CALL_DISABLED,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_CALL_DISABLED.BMP","Image of Disabled Dialing Key");
#endif  /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */
#endif /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ */


#ifdef __MMI_SCREEN_ROTATE__
	ADD_APPLICATION_IMAGE2(IMG_SCREEN_ROTATE_TITLE,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Horizontal\\\\Rotated_title.bmp","Image of rotated title");
	ADD_APPLICATION_IMAGE2(IMG_SCREEN_ROTATE_BACKGROUND,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Horizontal\\\\Rotated_bkgrnd.gif","Image of rotated background");	
#endif 

#ifdef __MMI_TOUCH_SCREEN__
	/* Wait long-press animation */
	ADD_APPLICATION_IMAGE2(IMG_PEN_WAITING_LONGPRESS,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Touch\\\\TH_LongPress.gif","Animation when pen is long-tapped");		

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

#if (defined(__MMI_LANG_CZECH__) || defined(__MMI_LANG_SLOVAK__))
  ADD_APPLICATION_IMAGE2(IMG_VKBD_CZECH,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CZECH_SLOVAK.PNG","Czech_Slovak keyboard");
#endif /* (defined(__MMI_LANG_CZECH__) || defined(__MMI_LANG_SLOVAK__))*/
#ifdef __MMI_LANG_HEBREW__
  ADD_APPLICATION_IMAGE2(IMG_VKBD_HEBREW,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_HEBREW.PNG","Hebrew keyboard");
#endif /* __MMI_LANG_HEBREW__ */
#ifdef __MMI_LANG_BULGARIAN__
  ADD_APPLICATION_IMAGE2(IMG_VKBD_BULGARIAN,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_BULGARIAN.PNG","Bulgarian keyboard");
#endif /* __MMI_LANG_BULGARIAN__ */
#if (defined(__MMI_LANG_DANISH__) || defined(__MMI_LANG_NORWEGIAN__))
  ADD_APPLICATION_IMAGE2(IMG_VKBD_DANISH_NORWEGIAN,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_DANISH_NORWEGIAN.PNG","Danish_Norwegian keyboard");
#endif /* defined(__MMI_LANG_DANISH__)||defined(__MMI_LANG_NORWEGIAN__) */
#ifdef __MMI_LANG_GREEK__
  ADD_APPLICATION_IMAGE2(IMG_VKBD_GREEK,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_GREEK.PNG","Greek keyboard");
#endif /*__MMI_LANG_GREEK__*/
#if (defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_HUNGARIAN__) || defined(__MMI_LANG_ARABIC__))
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
#if defined(__MMI_LANG_ARABIC__)
  ADD_APPLICATION_IMAGE2(IMG_VKBD_ARABIC,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_ARABIC.PNG","Arabic keyboard");
#endif
#if defined(__MMI_LANG_THAI__)
  ADD_APPLICATION_IMAGE2(IMG_VKBD_THAI,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_THAI.PNG","Thai keyboard");
#endif
/* MTI START HINDI & TAMIL VK  */
#if defined(__MMI_LANG_TAMIL__)
  ADD_APPLICATION_IMAGE2(IMG_VKBD_TAMIL,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_TAMIL.PNG","Tamil keyboard");
#endif
#if defined(__MMI_MULTITAP_PUNJABI__) && defined (__MMI_MAINLCD_128X160__)
  ADD_APPLICATION_IMAGE2(IMG_VKBD_PUNJABI_128x160,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_PUNJABI_128x160.png","Punjabi keyboard for 128x160 layout 5");
#endif

/* MTI END HINDI & TAMIL VK  */
#if defined(__MMI_LANG_UKRAINIAN__)
  ADD_APPLICATION_IMAGE2(IMG_VKBD_UKRAINIAN,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_UKRAINIAN.PNG","Ukrainian keyboard");
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
	ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_EUROSYMB,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_EUROSYMB.BMP","Custom key - european symbol picker");
	ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_ENTER,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_ENTER.BMP","Custom key - Enter");
	ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_BRACKET,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_BRACKET.BMP","Custom key - Bracket");
	/* MTI START HINDI & TAMIL VK  */
	#if defined(__MMI_INDIC_ALG__)
	ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_INDIC_SYMBPICKER,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_INDIC_SYMBPICKER.BMP","Custom key - SLIDE");
	ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_INDIC_CAPSON,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_INDIC_CAPS_ON.BMP","Custom key - Caps ON");
	ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_INDIC_CAPSOFF,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_INDIC_CAPS_OFF.BMP","Custom key - Caps OFF");
	ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_INDIC_SYMBOLS,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_INDIC_SYMBOLS.BMP","Custom key - SYMBOLS");
	ADD_APPLICATION_IMAGE2(IMG_VKBD_CUSTOM_INDIC_BACK,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_INDIC_BACK.BMP","Custom key - BACK");	
	#endif
	/* MTI END HINDI & TAMIL VK  */
    #ifdef __MMI_VK_LARGE_ICON__ 
        ADD_APPLICATION_IMAGE2(IMG_VKBD_LARGE_ICON_BG_ZOOM_LEFT,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\vk_large_icon_left.png","virtual keyboard large icon - left arrow");
        ADD_APPLICATION_IMAGE2(IMG_VKBD_LARGE_ICON_BG_ZOOM_RIGHT,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\vk_large_icon_right.png","virtual keyboard large icon - right arrow");
    #endif /* __MMI_VK_LARGE_ICON__ */
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

#if defined(__MMI_ZI__)
//MTK Elvis
	ADD_APPLICATION_IMAGE2(WGUI_ZI_EZITEXT_LOGO,CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\eZiText_N12px_col.bmp","Icon for eZiText");
	ADD_APPLICATION_IMAGE2(WGUI_ZI_EZITEXT_BPMF_LOGO,CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\TC_eZiText_Bopomofo_N12px_col.bmp","Icon for eZiText BPMF");
	ADD_APPLICATION_IMAGE2(WGUI_ZI_EZITEXT_PINYIN_LOGO,CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\SC_eZiText_Pinyin_N12px_col.bmp","Icon for eZiText Pinyin");
	ADD_APPLICATION_IMAGE2(WGUI_ZI_EZITEXT_SM_STROKE_LOGO,CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\SC_eZiText_Stroke_N12px_col.bmp","Icon for eZiText SC Stroke");
	ADD_APPLICATION_IMAGE2(WGUI_ZI_EZITEXT_TR_STROKE_LOGO,CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\TC_eZiText_Stroke_N12px_col.bmp","Icon for eZiText TC Stroke");
//MTK end
#elif defined(__MMI_T9__)||defined(__MMI_ITAP__)||defined(__MMI_KA__) || defined(__MMI_CSTAR__)
//MTK Elvis IME input method indicators
	ADD_APPLICATION_IMAGE2(WGUI_IME_MULTITAP_BPMF_IMG,CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\Multitap BPMF.bmp","Icon for T9 multitap BPMF");
	ADD_APPLICATION_IMAGE2(WGUI_IME_MULTITAP_PINYIN_IMG,CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\Multiatp Pinyin.bmp","Icon for T9 multitap pinyin");
	ADD_APPLICATION_IMAGE2(WGUI_IME_SMART_BPMF_IMG,CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\Smart BPMF.bmp","Icon for T9 smart BPMF");
	ADD_APPLICATION_IMAGE2(WGUI_IME_SMART_PINYIN_IMG,CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\Smart Pinyin.bmp","Icon for T9 smart pinyin");
	ADD_APPLICATION_IMAGE2(WGUI_IME_SM_STROKE_IMG,CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\Simplified Chinese stroke.bmp","Icon for T9 SC Stroke");
	ADD_APPLICATION_IMAGE2(WGUI_IME_TR_STROKE_IMG,CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\Traditonal Chinese stroke.bmp","Icon for T9 TC Stroke");
	ADD_APPLICATION_IMAGE2(WGUI_IME_SMART_ENGLISH_IMG,CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\Smartamb.bmp","Icon for T9 smart English");
//MTK end
#endif

	ADD_APPLICATION_IMAGE2 (CHAT_LOCAL_IMG, CUST_IMG_PATH"\\\\MainLCD\\\\Chat\\\\CT_IN.PBM", "CHAT app Menu item OUT common Image");	
	ADD_APPLICATION_IMAGE2 (CHAT_REMOTE_IMG, CUST_IMG_PATH"\\\\MainLCD\\\\Chat\\\\CT_OUT.PBM", "CHAT app Menu item IN common Image");	

	ADD_APPLICATION_IMAGE2(IMG_H_SELECT_LEFT,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\SELECT_LEFT.pbm", "Left arrow in horizontal select");
	ADD_APPLICATION_IMAGE2(IMG_H_SELECT_RIGHT,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\SELECT_RIGHT.pbm", "Right arrow in horizontal select");
	ADD_APPLICATION_IMAGE2 (RIGHT_RED_ARROW, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\PV_ARR.pbm","right arrow");
	ADD_APPLICATION_IMAGE2 (LEFT_RED_ARROW, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\PV_ARL.pbm","left arrow");

#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__)
	ADD_APPLICATION_IMAGE2 (LEFT_ARROW_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\LEFT_ARROW_DOWN.pbm","LEFT_ARROW_DOWN");
	ADD_APPLICATION_IMAGE2 (LEFT_ARROW_UP, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\LEFT_ARROW_UP.pbm","LEFT_ARROW_UP");
	ADD_APPLICATION_IMAGE2 (RIGHT_ARROW_DOWN, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\RIGHT_ARROW_DOWN.pbm","RIGHT_ARROW_DOWN");
	ADD_APPLICATION_IMAGE2 (RIGHT_ARROW_UP, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\RIGHT_ARROW_UP.pbm","RIGHT_ARROW_UP");
#endif

#ifndef __MMI_TOUCH_DIAL_SCREEN__
#if defined( __MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__)
	//ADD_APPLICATION_IMAGE2 (IMG_POPUP_TITLE, CUST_IMG_PATH"\\\\MainLCD\\\\WarningPage\\\\PopUpPage\\\\PP_TB.BMP","Background image of popup screen");
	ADD_APPLICATION_IMAGE2 (IMG_DIALING_SCREEN_BG_UP,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\idle_top.png", "Image of Dialing Screen background");
	ADD_APPLICATION_IMAGE2 (IMG_DIALING_SCREEN_BG_DOWN,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\idle_botton.png", "Image of Dialing Screen background");
	ADD_APPLICATION_IMAGE2 (IMG_DIALING_SCREEN_BG_LEFT,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\idle_left.png", "Image of Dialing Screen background");
	ADD_APPLICATION_IMAGE2 (IMG_DIALING_SCREEN_BG_RIGHT,CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\idle_right.png", "Image of Dialing Screen background");
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
#ifdef __MMI_UI_DALMATIAN_MAINMENU__
	ADD_APPLICATION_IMAGE2(MAIN_MENU_DALMATIAN_BALL, CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\PAGE\\\\Dalmatian\\\\MM_BALL.gif","Main Menu Ball Animation");

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
	ADD_APPLICATION_IMAGE2(CAL_ENGLISH_DAYS_IMAGE,CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Week\\\\week.bmp","Day of Week display");
	ADD_APPLICATION_IMAGE2(CAL_CHINESE_DAYS_IMAGE,CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Week\\\\chinese week.bmp","Day of Week display");
#ifdef __MMI_TOUCH_SCREEN__
	ADD_APPLICATION_IMAGE2 (CAL_LEFT_ARROW_UP_IMAGE, CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_upL.bmp","calendar title left arrow");
	ADD_APPLICATION_IMAGE2 (CAL_LEFT_ARROW_DOWN_IMAGE, CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_downL.bmp","calendar title left arrow down");
	ADD_APPLICATION_IMAGE2 (CAL_RIGHT_ARROW_UP_IMAGE, CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_upR.bmp","calendar title right arrow");
	ADD_APPLICATION_IMAGE2 (CAL_RIGHT_ARROW_DOWN_IMAGE, CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_downR.bmp","calendar title right arrow down");
#endif /* __MMI_TOUCH_SCREEN__ */
#endif /*__MMI_CALENDAR__*/

	ADD_APPLICATION_IMAGE2 (IMG_TITLEBAR_BG, CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\TB_BG.pbm","keyboard for password input");//070505 Calvin should remove 
//PMT HIMANSHU START 20050625
#ifdef __MMI_UI_TECHNO_MAINMENU__
	ADD_APPLICATION_IMAGE2(MAIN_MENU_PAGE_BG, CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\PAGE\\\\Techno\\\\MM_BG.gif","Main Menu Background Animo Image");
	ADD_APPLICATION_IMAGE2(MAIN_MENU_PAGE_BG2, CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\PAGE\\\\Techno\\\\MM_BG2.gif","Main Menu Background Animo Image");
	ADD_APPLICATION_IMAGE2(MAIN_MENU_PAGE_BG3, CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\PAGE\\\\Techno\\\\MM_BG3.gif","Main Menu Background Animo Image");
	ADD_APPLICATION_IMAGE2(MAIN_MENU_PAGE_BG4, CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\PAGE\\\\Techno\\\\MM_BG4.gif","Main Menu Background Animo Image");
	ADD_APPLICATION_IMAGE2(MAIN_MENU_PAGE_BG5, CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\PAGE\\\\Techno\\\\MM_BG5.gif","Main Menu Background Animo Image");
#endif
//PMT HIMANSHU END

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
#ifdef __MMI_DIGITAL_CLOCK_IMAGE_NUMBER__
	ADD_APPLICATION_IMAGE2(IMG_TECHNO_DIGITAL_CLOCK_0, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\0.png", " Techno Idlescreen Digital Clock Number 0 Image");
	ADD_APPLICATION_IMAGE2(IMG_TECHNO_DIGITAL_CLOCK_1, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\1.png", " Techno Idlescreen Digital Clock Number 1 Image");
	ADD_APPLICATION_IMAGE2(IMG_TECHNO_DIGITAL_CLOCK_2, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\2.png", " Techno Idlescreen Digital Clock Number 2 Image");
	ADD_APPLICATION_IMAGE2(IMG_TECHNO_DIGITAL_CLOCK_3, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\3.png", " Techno Idlescreen Digital Clock Number 3 Image");
	ADD_APPLICATION_IMAGE2(IMG_TECHNO_DIGITAL_CLOCK_4, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\4.png", " Techno Idlescreen Digital Clock Number 4 Image");
	ADD_APPLICATION_IMAGE2(IMG_TECHNO_DIGITAL_CLOCK_5, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\5.png", " Techno Idlescreen Digital Clock Number 5 Image");
	ADD_APPLICATION_IMAGE2(IMG_TECHNO_DIGITAL_CLOCK_6, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\6.png", " Techno Idlescreen Digital Clock Number 6 Image");
	ADD_APPLICATION_IMAGE2(IMG_TECHNO_DIGITAL_CLOCK_7, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\7.png", " Techno Idlescreen Digital Clock Number 7 Image");
	ADD_APPLICATION_IMAGE2(IMG_TECHNO_DIGITAL_CLOCK_8, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\8.png", " Techno Idlescreen Digital Clock Number 8 Image");
	ADD_APPLICATION_IMAGE2(IMG_TECHNO_DIGITAL_CLOCK_9, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\9.png", " Techno Idlescreen Digital Clock Number 9 Image");
	ADD_APPLICATION_IMAGE2(IMG_TECHNO_DIGITAL_CLOCK_AM, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\am.png", " Techno Idlescreen Digital Clock AM Image");
	ADD_APPLICATION_IMAGE2(IMG_TECHNO_DIGITAL_CLOCK_PM, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\pm.png", " Techno Idlescreen Digital Clock PM Image");
	ADD_APPLICATION_IMAGE2(IMG_TECHNO_DIGITAL_CLOCK_COLON, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\colon.png", " Techno Idlescreen Digital Clock Colon Image");
#endif /* __MMI_DIGITAL_CLOCK_IMAGE_NUMBER__ */
#ifdef __MMI_DIGITAL_CLOCK_STYLE_BACKGROUND__
	ADD_APPLICATION_IMAGE2(IMG_TECHNO_DIGITAL_CLOCK_DAY_BACKGROUND, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\day.png", " Techno Idlescreen Digital Clock Day Background Image");
	ADD_APPLICATION_IMAGE2(IMG_TECHNO_DIGITAL_CLOCK_NIGHT_BACKGROUND, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\night.png", " Techno Idlescreen Digital Clock Night Background Image");
#endif /* __MMI_DIGITAL_CLOCK_STYLE_BACKGROUND__ */
	/* 070306 Alpha layer End */
#endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */
//PMT HIMANSHU END 20050721

//PMT HIMANSHU START 20050815
#if defined(__MMI_DRAW_MANAGER__)
	ADD_APPLICATION_IMAGE2(IMAGE_VIEW_TITLEBAR_BG, CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\TB_IV_BG.pbm","Title bar of Wallpaper and ScreenSaver Image View Screen");
#endif
	ADD_APPLICATION_IMAGE2(IMG_FLEXIBLE_TITLEBAR_BG, CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\TB_FLEXIBLE.pbm","Title bar for flexible size");//093006 popup title
//PMT HIMANSHU END 20050815
//PMT NEERAJ START 20050825
#ifdef __MMI_UI_TWO_LINE_MENUITEM_STYLES__
	ADD_APPLICATION_IMAGE2(TWO_LINE_VOLUME_IMAGE,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_INLINE.gif","Inline Volume Image");
#endif
//PMT NEERAJ END 20050825
#if defined (__MMI_MAINLCD_128X128__)
    ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_NORMAL_TAB, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar.bmp", "normal tab");
    ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_FOCUSED_TAB, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\focused_tab_bar.bmp", "focused tab");
    ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_BLINKING_TAB, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_blink.bmp", "blinking tab");
    ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_TAB_L_ARROW, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\TAB_ARROW_L.GIF", "right arrow on tab");
    ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_TAB_R_ARROW, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\TAB_ARROW_R.GIF", "left arrow on tab");
    ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_TAB_HINT_AREA, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\TITLEBAR.bmp", "tab hint area");
#else  /* __MMI_MAINLCD_128X128__ */
	ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_NORMAL_TAB, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar.png", "normal tab");
	ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_FOCUSED_TAB, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\focused_tab_bar.png", "focused tab");
	ADD_APPLICATION_IMAGE2(IMG_HORIZONTAL_BLINKING_TAB, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_blink.png", "blinking tab");
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
    ADD_APPLICATION_IMAGE2(WGUI_IMG_TEXT_BG_MID,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TextBG\\\\TBG_MID.png","text background middle");
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

    /* Status icon bar time */
    ADD_APPLICATION_IMAGE2(IMG_STATUS_ICON_TIME_AM,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\StatusiconTime\\\\AM.bmp", "Status icon time am");
    ADD_APPLICATION_IMAGE2(IMG_STATUS_ICON_TIME_PM,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\StatusiconTime\\\\PM.bmp", "Status icon time pm");
    ADD_APPLICATION_IMAGE2(IMG_STATUS_ICON_TIME_AM_CH,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\StatusiconTime\\\\AM_CH.bmp", "Status icon time am ch");
    ADD_APPLICATION_IMAGE2(IMG_STATUS_ICON_TIME_PM_CH,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\StatusiconTime\\\\PM_CH.bmp", "Status icon time pm ch");

#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
#endif

#ifdef __MMI_CAT116_SUPPORT__
    ADD_APPLICATION_IMAGE2(IMG_ID_CALL_PLAN_BACKGROUND, CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TextBG\\\\BG.png","call plan background");
#endif

    ADD_APPLICATION_IMAGE2(SMALL_CHECKBOX_ON_IMAGE_ID,CUST_IMG_PATH"\\\\MainLCD\\\\UIELement\\\\Checkbox\\\\S_CK_S.BMP","Image associated with small CheckBox On.");
    ADD_APPLICATION_IMAGE2(SMALL_CHECKBOX_OFF_IMAGE_ID,CUST_IMG_PATH"\\\\MainLCD\\\\UIELement\\\\Checkbox\\\\S_CK_UNS.BMP","Image associated with small CheckBox Off.");

    PopulateUnifiedComposerEditorRes();

    PopulateMMSViewerRes();

}

//PMT VIKAS START 20050720
#if defined( __MMI_UI_ANIMATED_TITLE_EFFECT__)||defined(__MMI_UI_LIST_HIGHLIGHT_EFFECTS__)
void PopulateTitleListAnimationResources(void)
{
      #ifdef __MMI_UI_ANIMATED_TITLE_EFFECT__
      ADD_APPLICATION_IMAGE2(IMG_TITLE_SCROLL,CUST_IMG_PATH"\\\\MainLCD\\\\\UIElement\\\\AnimationEffects\\\\Title\\\\AnimationTitle.gif", "Animation Image for title");
      #endif

       #ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
        ADD_APPLICATION_IMAGE2(IMG_LIST_HIGHLIGHTER,CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\AnimationEffects\\\\List\\\\AnimationHighlighter.gif", "Highlighter animatian image");
      #endif
}
#endif
//PMT VIKAS END 20050720

void PopulateStatusIconResources(void)
{	
/* Vogins Start */
#ifdef __VRE30_AM__
    ADD_APPLICATION_IMAGE2(IMG_SI_VRE_DEFAULT,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_VRE_default.bmp","Status Icon: VRE default");
    ADD_APPLICATION_IMAGE2(IMG_SI_VRE_FETION,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_VRE_Fetion.bmp","Status Icon: VRE fetion");
    ADD_APPLICATION_IMAGE2(IMG_SI_VRE_MSN,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_VRE_MSN.bmp","Status Icon: VRE MSN");
    ADD_APPLICATION_IMAGE2(IMG_SI_VRE_PUSHMAIL,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_VRE_Pushmail.bmp","Status Icon: VRE pushmail");
    ADD_APPLICATION_IMAGE2(IMG_SI_VRE_QQ,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_VRE_QQ.bmp","Status Icon: VRE QQ");
#endif
/* Vogins End */

	//ADD_APPLICATION_IMAGE2(IMG_SI_SIGNAL_STRENGTH,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\signal\\\\SI_SIG.GIF","Status Icon: Signal strength");
	ADD_APPLICATION_IMAGE2(IMG_SI_SIGNAL_STRENGTH,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\signal\\\\SI_SIG","Status Icon: Signal strength");
#ifdef __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__ //022505 Calvin added
	//ADD_APPLICATION_IMAGE2(IMG_SI_SIGNAL_STRENGTH_L1,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\signal\\\\SI_SIG_L1.GIF","Status Icon: Signal strength with L1");
	//ADD_APPLICATION_IMAGE2(IMG_SI_SIGNAL_STRENGTH_L2,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\signal\\\\SI_SIG_L2.GIF","Status Icon: Signal strength with L2");
	ADD_APPLICATION_IMAGE2(IMG_SI_SIGNAL_STRENGTH_L1,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\signal\\\\SI_SIG_L1","Status Icon: Signal strength with L1");
	ADD_APPLICATION_IMAGE2(IMG_SI_SIGNAL_STRENGTH_L2,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\signal\\\\SI_SIG_L2","Status Icon: Signal strength with L2");
#else
	ADD_APPLICATION_IMAGE2(IMG_SI_LINE_L1,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_L1.BMP","Status Icon: Line 1");
	ADD_APPLICATION_IMAGE2(IMG_SI_LINE_L2,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_L2.BMP","Status Icon: Line 2");
#endif
	//ADD_APPLICATION_IMAGE2(IMG_SI_BATTERY_STRENGTH,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\battery\\\\SI_BAT.GIF","Status Icon: Battery strength");
	ADD_APPLICATION_IMAGE2(IMG_SI_BATTERY_STRENGTH,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\battery\\\\SI_BAT","Status Icon: Battery strength");
	ADD_APPLICATION_IMAGE2(IMG_SI_3G,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_3G.BMP","Status Icon: WCDMA");
	ADD_APPLICATION_IMAGE2(IMG_SI_2G,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_2G.BMP","Status Icon: GSM_GPRS");
	ADD_APPLICATION_IMAGE2(IMG_SI_ANY,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_Any.BMP","Status Icon: Dual Mode");
#ifdef __MMI_VOIP__//091806 voip icon
	ADD_APPLICATION_IMAGE2(IMG_SI_VOIP,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_VOIP.BMP","Status Icon: VOIP");
#endif
	ADD_APPLICATION_IMAGE2(IMG_SI_KEYPAD_LOCK,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_LOCK.BMP","Status Icon: Keypad lock");
	ADD_APPLICATION_IMAGE2(IMG_SI_KEYPAD_UNLOCK,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_UNLOCK.BMP","Status Icon: Keypad lock");
	ADD_APPLICATION_IMAGE2(IMG_SI_VIBRATE,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_VIB.BMP","Status Icon: Vibrator");
	ADD_APPLICATION_IMAGE2(IMG_SI_SILENT,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_SILENT.BMP","Status Icon: Silent");
	ADD_APPLICATION_IMAGE2(IMG_SI_RING,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_RING.BMP","Status Icon: Ring");
	ADD_APPLICATION_IMAGE2(IMG_SI_VIBRATE_AND_RING,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_VR.BMP","Status Icon: Vibrate and ring");
	ADD_APPLICATION_IMAGE2(IMG_SI_VIBRATE_THEN_RING,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_VTR.BMP","Status Icon: Vibrate then ring");
	ADD_APPLICATION_IMAGE2(IMG_SI_ALARM_ACTIVATED,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_ALARM.BMP","Status Icon: Alarm");
#if !defined(__MMI_DUAL_SIM_MASTER__)
	ADD_APPLICATION_IMAGE2(IMG_SI_ROAMING_INDICATOR,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_RM.BMP","Status Icon: Roaming");
#else   /* __MMI_DUAL_SIM_MASTER__ */
/* under construction !*/
#endif  /* __MMI_DUAL_SIM_MASTER__ */

#ifndef __MMI_DUAL_SIM_MASTER__
	ADD_APPLICATION_IMAGE2(IMG_SI_MISSED_CALL_INDICATOR,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_MCA.BMP","Status Icon: Missed Call");
#endif/*__MMI_DUAL_SIM_MASTER__*/

#ifndef __MMI_DUAL_SIM_MASTER__
	ADD_APPLICATION_IMAGE2(IMG_SI_GPRS_INDICATOR,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_GPRS.BMP","Status Icon: GPRS");
#endif /* __MMI_DUAL_SIM_MASTER__ */

#if (defined (__MMI_STATUS_ICON_EN_EARPHONE__) || defined(__MMI_BT_HP_SUPPORT__) || defined(__MMI_BT_SUPPORT__))
	ADD_APPLICATION_IMAGE2(IMG_SI_EARPHONE_INDICATOR,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_EAR.BMP","Status Icon: EarPhone");
#endif

#ifdef __MMI_STATUS_ICON_MMS__
	ADD_APPLICATION_IMAGE2(IMG_SI_MMS_UNREAD_INDICATOR,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_MMSU.BMP","Status Icon: EarPhone");
	ADD_APPLICATION_IMAGE2(IMG_SI_MMS_BUSY_INDICATOR,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_MMSB.BMP","Status Icon: EarPhone");
#endif


#ifdef __MMI_IRDA_SUPPORT__
     ADD_APPLICATION_IMAGE2(IMG_SI_IR_INDICATOR,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_IR.gif","Status Icon: IR");
#endif



#if defined(__MMI_BT_SUPPORT__)
     ADD_APPLICATION_IMAGE2(IMG_SI_BT,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_BT.bmp","Status Icon: BT");
     ADD_APPLICATION_IMAGE2(IMG_SI_BT_CON,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_BT_CON.bmp","Status Icon: BT");
     ADD_APPLICATION_IMAGE2(IMG_SI_BT_ND,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_BT_ND.bmp","Status Icon: BT");
#endif

#ifdef __MMI_POC__
     ADD_APPLICATION_IMAGE2(IMG_SI_POC,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_Walkt.bmp","Status Icon: PoC registration");//030705 Calvin added
#endif

/* 101205 new icon Calvin Start */
#ifdef __MMI_BG_SOUND_EFFECT__
     ADD_APPLICATION_IMAGE2(IMG_SI_BGSND,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_BGSND.bmp","Status Icon: background sound effect");
#endif

#ifdef __MMI_AUDIO_REVERB_EFFECT__
     ADD_APPLICATION_IMAGE2(IMG_SI_REVERBSND,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_AudReverb.bmp","Status Icon: audio reverb effect");
#endif

#ifdef __MMI_AUDIO_SURROUND_EFFECT__
     ADD_APPLICATION_IMAGE2(IMG_SI_SURROUNDSND,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_3DSound.bmp","Status Icon: audio surround effect");
#endif

#ifdef __MMI_HOMEZONE_STATUS_ICON__

#ifndef __MMI_DUAL_SIM_MASTER__
     ADD_APPLICATION_IMAGE2(IMG_SI_HZONE,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_HZONE.bmp","Status Icon: home zone");
#else
/* under construction !*/
/* under construction !*/
#endif
     ADD_APPLICATION_IMAGE2(IMG_SI_CZONE,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_CZONE.bmp","Status Icon: city zone");
#endif

#ifdef __CTM_SUPPORT__
     ADD_APPLICATION_IMAGE2(IMG_SI_TTY_INDICATOR,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_TTY.bmp","Status Icon: TTY indication");
#endif
/* 101205 new icon Calvin End */

#ifndef __MMI_DUAL_SIM_MASTER__
	ADD_APPLICATION_IMAGE2(IMG_SI_GPRS_ATT_NO_PDP_INDICATOR,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_GPRSC.BMP","Status Icon: GPRS, attach without pdp");	
#endif

	ADD_APPLICATION_IMAGE2(IMG_SI_UNREAD_EMAIL,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_EMUR.bmp","Status Icon: Unread Email");

	ADD_APPLICATION_IMAGE2(IMG_SI_UNREAD_VOICE_L1,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_VOML1.BMP","Status Icon: Unread Voice L1");
	ADD_APPLICATION_IMAGE2(IMG_SI_UNREAD_VOICE_L2,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_VOML2.BMP","Status Icon: Unread Voice L2");
	ADD_APPLICATION_IMAGE2(IMG_SI_UNREAD_VOICE_L1L2,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_VOML12.BMP","Status Icon: Unread Voice L1+L2");
	ADD_APPLICATION_IMAGE2(IMG_SI_UNREAD_FAX_L1,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_FM1.BMP","Status Icon: Unread Fax L1");
	ADD_APPLICATION_IMAGE2(IMG_SI_UNREAD_FAX_L2,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_FM2.BMP","Status Icon: Unread Fax L2");
	ADD_APPLICATION_IMAGE2(IMG_SI_UNREAD_FAX_L1L2,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_FM12.BMP","Status Icon: Unread Fax L1+L2");
	ADD_APPLICATION_IMAGE2(IMG_SI_UNREAD_EMAIL_L1,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_EM1.BMP","Status Icon: Unread Email L1");
	ADD_APPLICATION_IMAGE2(IMG_SI_UNREAD_EMAIL_L2,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_EM2.BMP","Status Icon: Unread Email L2");
	ADD_APPLICATION_IMAGE2(IMG_SI_UNREAD_EMAIL_L1L2,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_EM12.BMP","Status Icon: Unread Email L1+L2");
#ifndef __MMI_DUAL_SIM_MASTER__
	ADD_APPLICATION_IMAGE2(IMG_SI_SMS_INDICATOR,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_MGE.BMP","Status Icon: Message");
#else	/* __MMI_DUAL_SIM_MASTER__ */
/* under construction !*/
#endif	/* __MMI_DUAL_SIM_MASTER__ */

#ifndef __MMI_DUAL_SIM_MASTER__
	ADD_APPLICATION_IMAGE2(IMG_SI_CALL_DIVERT_L1,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_FOR01.BMP","Status Icon: Call Divert L1");
	ADD_APPLICATION_IMAGE2(IMG_SI_CALL_DIVERT_L2,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_FOR02.BMP","Status Icon: Call Divert L2");
	ADD_APPLICATION_IMAGE2(IMG_SI_CALL_DIVERT_L1L2,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_FOR.BMP","Status Icon: Call Divert L1+L2");
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif	/* __MMI_DUAL_SIM_MASTER__ */

	ADD_APPLICATION_IMAGE2(IMG_SI_VOICE_RECORD,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_REC.BMP","Status Icon: Voice record");
	ADD_APPLICATION_IMAGE2(IMG_SI_MUTE,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_MUTE.BMP","Status Icon: Mute");
	ADD_APPLICATION_IMAGE2(IMG_BLINKINGICON_CHAT_ROOM1,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_CHAT1.BMP","Chat Room1 Blinking Icon");
	ADD_APPLICATION_IMAGE2(IMG_BLINKINGICON_CHAT_ROOM2,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_CHAT2.BMP","Chat Room2 Blinking Icon");
	ADD_APPLICATION_IMAGE2(IMG_SI_STOPWATCH,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\SI_STWATCH.bmp","Image for Stopwatch Icon");
   #if defined(__J2ME__) && defined(J2ME_SUPPORT_BACKGROUND)
	ADD_APPLICATION_IMAGE2(IMG_SI_JAVA_BG_VM,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_JAVA.bmp","Java bg vm");
	ADD_APPLICATION_IMAGE2(IMG_SI_JAVA_BG_VM_AUDIO,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_AJAVA.bmp","Java bg vm audio");
   #endif
	// MTK added, Jo 20031031
//	ADD_APPLICATION_IMAGE2(IMG_SI_WMAL,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_WMAL.bmp","Sub LCD Status Icon: Vibrate then Ring");
	// MTK end
	//change according to JL mail 
	ADD_APPLICATION_IMAGE2(IMG_SI_WAP,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_WMAL.bmp","Sub LCD Status Icon: Vibrate then Ring");

#ifndef __MMI_DUAL_SIM_MASTER__
	ADD_APPLICATION_IMAGE2(IMG_SI_NETWORK_CIPHER_GSM,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_NCGSM.bmp","Network Ciphering for GSM");//021505 Calvin added
#endif
	ADD_APPLICATION_IMAGE2(IMG_SI_NETWORK_CIPHER_GPRS,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_NCGPRS.bmp","Network Ciphering for GPRS");//021505 Calvin added

	ADD_APPLICATION_IMAGE2(IMG_SI_JAVA_CONNECT, CUST_IMG_PATH"\\\\MainLCD\\\\JAVA\\\\JAVA_connect.gif","Java connecting");

   /* Max, for IMPS */
   #ifdef __MMI_IMPS__
	ADD_APPLICATION_IMAGE2 ( IMG_SI_IMPS_MSG, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\SI_IMPSMG.bmp", "Status icon in Idle Screen when new msg comes");
	ADD_APPLICATION_IMAGE2 ( IMG_SI_IMPS_LOGIN, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\SI_IMPS.bmp", "Status icon in Idle Screen when login server");
    ADD_APPLICATION_IMAGE2 ( IMG_SI_IMPS_LOGIN_FAIL, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\SI_IMPS_fail.bmp", "Status icon in Idle Screen when login server");
   #endif

#ifdef __MMI_WLAN_FEATURES__
	ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_WLAN_STATUS_DISCONNECT, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\WiFi\\\\wifi_disconnect.bmp","Image of WLAN");
	//ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_WLAN_STATUS_SCANNING, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\WiFi\\\\wifi_connecting.gif","Image of WLAN");
	ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_WLAN_STATUS_SCANNING, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\WiFi\\\\SI_WIFI","Image of WLAN");
    ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_WLAN_STATUS_CONNECT1, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\WiFi\\\\SI_WIFI\\\\0.bmp","Image of WLAN");
	ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_WLAN_STATUS_CONNECT2, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\WiFi\\\\SI_WIFI\\\\1.bmp","Image of WLAN");
	ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_WLAN_STATUS_CONNECT3, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\WiFi\\\\SI_WIFI\\\\2.bmp","Image of WLAN");
	ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_WLAN_STATUS_CONNECT4, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\WiFi\\\\SI_WIFI\\\\3.bmp","Image of WLAN");
	ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_WLAN_STATUS_CONNECT5, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\WiFi\\\\SI_WIFI\\\\4.bmp","Image of WLAN");
	ADD_APPLICATION_IMAGE2(IMG_ID_DTCNT_WLAN_STATUS_CONNECT6, CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\WiFi\\\\SI_WIFI\\\\5.bmp","Image of WLAN");
#endif

/* 082304 MTK Calvin added compile option */	
#ifdef __MMI_SUBLCD__
	ADD_APPLICATION_IMAGE2(IMG_SLSI_SILENT,CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\SB_SIL.BMP","Sub LCD Status Icon: Silent");
	//ADD_APPLICATION_IMAGE2(IMG_SLSI_SIGNAL_STRENGTH,CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\signal\\\\SB_SIG.GIF","Sub LCD Status Icon: Signal strength");
	//ADD_APPLICATION_IMAGE2(IMG_SLSI_BATTERY_STRENGTH,CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\battery\\\\SB_BAT.GIF","Sub LCD Status Icon: Battery strength");
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

#ifndef __MMI_DUAL_SIM_MASTER__
    ADD_APPLICATION_IMAGE2(IMG_SI_EDGE,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_EDGE.bmp","Status Icon: BT");
    ADD_APPLICATION_IMAGE2(IMG_SI_EDGEC,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_EDGEC.bmp","Status Icon: BT");
#endif /* __MMI_DUAL_SIM_MASTER__ */

#ifdef __MMI_PICT_BRIDGE_SUPPORT__
    ADD_APPLICATION_IMAGE2(IMG_SI_PRINT,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_PRINT.bmp","Status Icon: print");
    ADD_APPLICATION_IMAGE2(IMG_SI_PRINT_FAIL,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_PRINT_FAIL.bmp","Status Icon: print_fail");
#endif

#ifdef __MMI_MOBILE_TV_PLAYER__
    ADD_APPLICATION_IMAGE2(IMG_SI_MTV_SIGNAL,CUST_IMG_PATH"\\\\MainLCD\\\\MobileTVPlayer\\\\Signal","Status Icon: MTV signal");
#endif 


#if (defined(OBIGO_Q05A) || defined(JATAAYU_SUPPORT)) && defined(WAP_SUPPORT)
    ADD_APPLICATION_IMAGE2(IMG_SI_SECURITY,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Statusicons\\\\SI_KEY.bmp","");
#endif

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    ADD_APPLICATION_IMAGE2(IMG_SI_OUTBOX_INDICATOR,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_OUTBOXIND.bmp","Status Icon: outboxind");
#endif

#ifdef __MMI_AUDIO_PLAYER__
    ADD_APPLICATION_IMAGE2(IMG_SI_AUDPLY,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_AUDPLY.bmp","Status Icon: audio player");
#endif

    ADD_APPLICATION_IMAGE2(IMG_SI_UNREAD_NET_L1,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_NETL1.bmp","Status Icon: Net L1");
    ADD_APPLICATION_IMAGE2(IMG_SI_UNREAD_NET_L2,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_NETL2.bmp","Status Icon: Net L2");
    ADD_APPLICATION_IMAGE2(IMG_SI_UNREAD_NET_L1L2,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_NETL12.bmp","Status Icon: Net L12");
    ADD_APPLICATION_IMAGE2(IMG_SI_EMAIL_REF,CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons\\\\SI_EMRF.bmp","Status Icon: email refresh");

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


