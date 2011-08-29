#ifdef __VRE__
#include "mmi_include.h"
#include "Conversions.h"

#include "vmchset.h"
#include "vmlog.h"
#include "vmopt.h"
#include "vmglobalver.h"

const VMINT defaultvretype2mtktype [VM_TOTAL_LANGUAGE] =
{
	MMI_CHSET_ASCII,
	MMI_CHSET_GB2312,
	MMI_CHSET_BIG5,
	MMI_CHSET_ASCII,
	MMI_CHSET_VIETNAMESE_WIN,
	MMI_CHSET_THAI_WIN,
	MMI_CHSET_ASCII,
	MMI_CHSET_ASCII,
	MMI_CHSET_ASCII,
	MMI_CHSET_TURKISH_ISO,
	MMI_CHSET_KOI8_R,
	MMI_CHSET_ARABIC_ISO,
	MMI_CHSET_PERSIAN_CP1098,
	MMI_CHSET_WESTERN_ISO
};


extern vm_local_info current_local_info;

VMINT vm_ucs2_to_default(VMSTR dst, VMINT size, VMWSTR src) 
{
#ifdef VRE_GLOBAL_VERSION
	VMINT retval = -1;
	VMINT result = 0;
	if (current_local_info.local_info_id == -1)
	{
		//retval =  -1;
		vm_log_error("[CHSET]vm_ucs2_to_default : current_local_info is empty");
		return -1;
	}		

	
	if (size > CONVERT_CHSET_MAX_LEN || size <= 0)
	{
		retval =  -1;
		//vm_log_error("vm_ucs2_to_gb2312 : the size is out of range");
	}
	else
	{
		if (src == NULL || dst == NULL)
		{
			retval =  -1;
			//vm_log_error("vm_ucs2_to_gb2312 : the ptr of src or dst is NULL");
		}
		else
		{
			result = mmi_chset_convert(
				MMI_CHSET_UCS2, 
				(mmi_chset_enum)defaultvretype2mtktype[current_local_info.lang], 
				(VMCHAR *)src, 
				(VMCHAR *)dst, 
				size);
			if (result > 0)
			{
				retval = 0;
			}
			else
			{
				retval =  -1;
				//vm_log_error("vm_ucs2_to_gb2312 : mmi_chset_convert return error");
			}
		}		
	}
	return retval;
#else
	return vm_ucs2_to_gb2312(dst, size, src);
#endif	
}

VMINT vm_default_to_ucs2(VMWSTR dst, VMINT size, VMSTR src) 
{
#ifdef VRE_GLOBAL_VERSION
	VMINT retval = -1;
	VMINT result = 0;

	if (current_local_info.local_info_id == -1)
	{
		//retval =  -1;
		vm_log_error("[CHSET]vm_default_to_ucs2 : current_local_info is empty");
		return -1;
	}			
	
	if (size > CONVERT_CHSET_MAX_LEN || size <= 0)
	{
		retval =  -1;
		//vm_log_error("vm_ucs2_to_gb2312 : the size is out of range");
	}
	else
	{
		if (src == NULL || dst == NULL)
		{
			retval =  -1;
			//vm_log_error("vm_ucs2_to_gb2312 : the ptr of src or dst is NULL");
		}
		else
		{
			result = mmi_chset_convert(
				(mmi_chset_enum)defaultvretype2mtktype[current_local_info.lang], 
				MMI_CHSET_UCS2,
				(VMCHAR *)src, 
				(VMCHAR *)dst, 
				size);
			if (result > 0)
			{
				retval = 0;
			}
			else
			{
				retval =  -1;
				//vm_log_error("vm_ucs2_to_gb2312 : mmi_chset_convert return error");
			}
		}		
	}
	return retval;
#else
	return vm_gb2312_to_ucs2(dst, size, src);
#endif
}

VMINT vm_ucs2_to_gb2312(VMSTR dst, VMINT size, VMWSTR src) 
{
	VMINT retval = -1;
	VMINT result = 0;
	if (size > CONVERT_CHSET_MAX_LEN || size <= 0)
	{
		retval =  -1;
		//vm_log_error("vm_ucs2_to_gb2312 : the size is out of range");
	}
	else
	{
		if (src == NULL || dst == NULL)
		{
			retval =  -1;
			//vm_log_error("vm_ucs2_to_gb2312 : the ptr of src or dst is NULL");
		}
		else
		{
			result = mmi_chset_convert(
				MMI_CHSET_UCS2, 
				MMI_CHSET_GB2312, 
				(VMCHAR *)src, 
				(VMCHAR *)dst, 
				size);
			if (result > 0)
			{
				retval = 0;
			}
			else
			{
				retval =  -1;
				//vm_log_error("vm_ucs2_to_gb2312 : mmi_chset_convert return error");
			}
		}		
	}
	return retval;
	
}

VMINT vm_gb2312_to_ucs2(VMWSTR dst, VMINT size, VMSTR src) 
{
	VMINT retval = -1;
	VMINT result = 0;
	if (size > CONVERT_CHSET_MAX_LEN || size <= 0)
	{
		retval =  -1;
		//vm_log_error("vm_gb2312_to_ucs2 : the size is error");
	}
	else
	{
		if (src == NULL || dst == NULL)
		{
			retval =  -1;
			//vm_log_error("vm_gb2312_to_ucs2 : the ptr of src or dst is NULL");
		}
		else
		{
			result = mmi_chset_convert(
				MMI_CHSET_GB2312, 
				MMI_CHSET_UCS2, 				
				(VMCHAR *)src, 
				(VMCHAR *)dst, 
				size);
			//vm_log_warn("vm_gb2312_to_ucs2 : %s , result=%d", src, result);
			if (result > 0)
			{
				retval = 0;
			}
			else
			{
				retval =  -1;
				//vm_log_error("vm_gb2312_to_ucs2 : mmi_chset_convert return error");
			}
		}		
	}
	return retval;
}

VMINT vm_ucs2_to_ascii(VMSTR dst, VMINT size, VMWSTR src) 
{
	VMINT retval = -1;
	VMINT result = 0;
	if (size > CONVERT_CHSET_MAX_LEN || size <= 0)
	{
		retval =  -1;
		//vm_log_error("vm_ucs2_to_gb2312 : the size is out of range");
	}
	else
	{
		if (src == NULL || dst == NULL)
		{
			retval =  -1;
			//vm_log_error("vm_ucs2_to_gb2312 : the ptr of src or dst is NULL");
		}
		else
		{
			result = mmi_chset_convert(
				MMI_CHSET_UCS2, 
				MMI_CHSET_ASCII, 
				(VMCHAR *)src, 
				(VMCHAR *)dst, 
				size);
			if (result > 0)
			{
				retval = 0;
			}
			else
			{
				retval =  -1;
				//vm_log_error("vm_ucs2_to_gb2312 : mmi_chset_convert return error");
			}
		}		
	}
	return retval;
	
}

VMINT vm_ascii_to_ucs2(VMWSTR dst, VMINT size, VMSTR src)
{
	VMINT retval = -1;
	VMINT result = 0;
	if (size > CONVERT_CHSET_MAX_LEN || size <= 0)
	{
		retval =  -1;
		//vm_log_error("vm_gb2312_to_ucs2 : the size is error");
	}
	else
	{
		if (src == NULL || dst == NULL)
		{
			retval =  -1;
			//vm_log_error("vm_gb2312_to_ucs2 : the ptr of src or dst is NULL");
		}
		else
		{
			result = mmi_chset_convert(
				MMI_CHSET_ASCII, 
				MMI_CHSET_UCS2, 				
				(VMCHAR *)src, 
				(VMCHAR *)dst, 
				size);
			//vm_log_warn("vm_gb2312_to_ucs2 : %s , result=%d", src, result);
			if (result > 0)
			{
				retval = 0;
			}
			else
			{
				retval =  -1;
				//vm_log_error("vm_gb2312_to_ucs2 : mmi_chset_convert return error");
			}
		}		
	}
	return retval;
}

/* changed by zaiping.chen, 2010.07.15, static memory optimize, begin */
#if 0

#define VM_GB_UCS2_STRING_BUFF			(255)

static VMCHAR r[VM_GB_UCS2_STRING_BUFF*2];	//RAM_REDUCTION
VMWSTR vm_ucs2_string(VMSTR s) 
{
	//static VMWCHAR r[VM_GB_UCS2_STRING_BUFF];	//RAM_REDUCTION

	//vm_gb2312_to_ucs2((VMWSTR)r, VM_GB_UCS2_STRING_BUFF, s);
	vm_default_to_ucs2((VMWSTR)r, VM_GB_UCS2_STRING_BUFF, s);
	
	return (VMWSTR)r;
}

VMWSTR vm_ucs2_string_by_ascii(VMSTR s)
{
	//static VMWCHAR r[VM_GB_UCS2_STRING_BUFF];	//RAM_REDUCTION

	vm_ascii_to_ucs2((VMWSTR)r, VM_GB_UCS2_STRING_BUFF, s);
	
	return (VMWSTR)r;
}

VMSTR vm_gb2312_string(VMWSTR s) 
{
	//static VMCHAR r[VM_GB_UCS2_STRING_BUFF];	//RAM_REDUCTION

	vm_ucs2_to_gb2312(r, VM_GB_UCS2_STRING_BUFF, s);

	return (VMSTR)r;
}
#endif

#define VM_GB_UCS2_STRING_BUFF			(256)
VMSTR	ucs2_string;
VMSTR	ucs2_string_ascii;
VMSTR	gb2312_string;

void	init_chset_memory(void)
{
	vm_log_debug("static memory optimize: init_chset_memory");
	ucs2_string = vm_malloc(VM_GB_UCS2_STRING_BUFF);
	if (NULL == ucs2_string)
	{
		vm_log_error("init_chset_memory vm_malloc ucs2_string fail.");
		return;
	}
	
	ucs2_string_ascii = vm_malloc(VM_GB_UCS2_STRING_BUFF);
	if (NULL == ucs2_string_ascii)
	{
		vm_log_error("init_chset_memory vm_malloc ucs2_string_ascii fail.");
		return;
	}
	
	gb2312_string = vm_malloc(VM_GB_UCS2_STRING_BUFF);
	if (NULL == gb2312_string)
	{
		vm_log_error("init_chset_memory vm_malloc gb2312_string fail.");
		return;
	}
}

void	free_chset_memory(void)
{
	vm_log_debug("static memory optimize: free_chset_memory");
	if (NULL != ucs2_string)
	{
		vm_free(ucs2_string);
		ucs2_string = NULL;
	}
	
	if (NULL != ucs2_string_ascii)
	{
		vm_free(ucs2_string_ascii);
		ucs2_string_ascii = NULL;
	}
	
	if (NULL != gb2312_string)
	{
		vm_free(gb2312_string);
		gb2312_string = NULL;
	}
}

VMWSTR vm_ucs2_string(VMSTR s) 
{
	if (NULL != ucs2_string)
	{
		vm_default_to_ucs2((VMWSTR)ucs2_string, VM_GB_UCS2_STRING_BUFF, s);
	}
	return (VMWSTR)ucs2_string;
}

VMWSTR vm_ucs2_string_by_ascii(VMSTR s)
{
	if (NULL != ucs2_string_ascii)
	{
		vm_ascii_to_ucs2((VMWSTR)ucs2_string_ascii, VM_GB_UCS2_STRING_BUFF, s);
	}
	return (VMWSTR)ucs2_string_ascii;
}

VMSTR vm_gb2312_string(VMWSTR s) 
{
	if (NULL != gb2312_string)
	{
	#ifdef __MMI_LANG_SM_CHINESE__
		vm_ucs2_to_gb2312(gb2312_string, VM_GB_UCS2_STRING_BUFF, s);
    #else
        vm_ucs2_to_ascii(gb2312_string, VM_GB_UCS2_STRING_BUFF, s);
    #endif
	}
	return gb2312_string;
}
/* changed by zaiping.chen, 2010.07.15, static memory optimize, end */

const VMINT vreEncodingType2mtkEncodingType [2][VM_CHSET_TOTAL] = 
{
	{
	VM_CHSET_ASCII,
    	VM_CHSET_ARABIC_ISO,
    	VM_CHSET_ARABIC_WIN,
    	VM_CHSET_PERSIAN_CP1097,
    	VM_CHSET_PERSIAN_CP1098,
   	VM_CHSET_BALTIC_ISO,
    	VM_CHSET_BALTIC_WIN,
    	VM_CHSET_CEURO_ISO,
    	VM_CHSET_CEURO_WIN,
    	VM_CHSET_CYRILLIC_ISO,
    	VM_CHSET_CYRILLIC_WIN,
    	VM_CHSET_GREEK_ISO,
    	VM_CHSET_GREEK_WIN,
    	VM_CHSET_HEBREW_ISO,
    	VM_CHSET_HEBREW_WIN,
    	VM_CHSET_LATIN_ISO,
    	VM_CHSET_NORDIC_ISO,
    	VM_CHSET_SEURO_ISO,
   	VM_CHSET_TURKISH_ISO,
    	VM_CHSET_TURKISH_WIN,
    	VM_CHSET_WESTERN_ISO,
    	VM_CHSET_ARMENIAN_ISO,
    	VM_CHSET_WESTERN_WIN,
    	VM_CHSET_BIG5,
    	VM_CHSET_GB2312,
    	VM_CHSET_HKSCS,
    	VM_CHSET_SJIS,
    	VM_CHSET_GB18030,
    	VM_CHSET_UTF7,
    	VM_CHSET_EUCKR,
    	VM_CHSET_THAI_WIN,
    	VM_CHSET_VIETNAMESE_WIN,
    	VM_CHSET_KOI8_R,
    	VM_CHSET_TIS_620,
    	VM_CHSET_UTF16LE,
    	VM_CHSET_UTF16BE,
    	VM_CHSET_UTF8,
    	VM_CHSET_UCS2
	},
	{
	MMI_CHSET_ASCII,
    	MMI_CHSET_ARABIC_ISO,
    	MMI_CHSET_ARABIC_WIN,
    	MMI_CHSET_PERSIAN_CP1097,
    	MMI_CHSET_PERSIAN_CP1098,
   	MMI_CHSET_BALTIC_ISO,
    	MMI_CHSET_BALTIC_WIN,
    	MMI_CHSET_CEURO_ISO,
    	MMI_CHSET_CEURO_WIN,
#if  (defined __VRE_RB_08A__) ||  (defined __VRE_RB_08B__) 
	0,//MMI_CHSET_CYRILLIC_ISO,
	0,//MMI_CHSET_CYRILLIC_WIN,
#else
    	MMI_CHSET_CYRILLIC_ISO,
    	MMI_CHSET_CYRILLIC_WIN,
#endif
    	MMI_CHSET_GREEK_ISO,
    	MMI_CHSET_GREEK_WIN,
    	MMI_CHSET_HEBREW_ISO,
    	MMI_CHSET_HEBREW_WIN,
    	MMI_CHSET_LATIN_ISO,
    	MMI_CHSET_NORDIC_ISO,
    	MMI_CHSET_SEURO_ISO,
   	MMI_CHSET_TURKISH_ISO,
    	MMI_CHSET_TURKISH_WIN,
    	MMI_CHSET_WESTERN_ISO,
#ifdef __VRE_RB_08A__
	0,//MMI_CHSET_ARMENIAN_ISO,
#else
    	MMI_CHSET_ARMENIAN_ISO,
#endif
    	MMI_CHSET_WESTERN_WIN,
    	MMI_CHSET_BIG5,
    	MMI_CHSET_GB2312,
#if  (defined __VRE_RB_08A__) ||  (defined __VRE_RB_08B__) 
	0,//MMI_CHSET_HKSCS,
	0,//MMI_CHSET_SJIS,
#else
    	MMI_CHSET_HKSCS,
    	MMI_CHSET_SJIS,
#endif
    	MMI_CHSET_GB18030,
    	MMI_CHSET_UTF7,
    	MMI_CHSET_EUCKR,
    	MMI_CHSET_THAI_WIN,
    	MMI_CHSET_VIETNAMESE_WIN,
    	MMI_CHSET_KOI8_R,
    	MMI_CHSET_TIS_620,
    	MMI_CHSET_UTF16LE,
    	MMI_CHSET_UTF16BE,
    	MMI_CHSET_UTF8,
    	MMI_CHSET_UCS2
	}
};

VMINT vm_chset_convert(vm_chset_enum src_type, vm_chset_enum dest_type, 
	VMCHAR* src, VMCHAR* dest, VMINT dest_size)
{
	VMINT result = 0;
	
	if (src == NULL || dest == NULL || dest_size <= 0)
	{
		return VM_CHSET_CONVERT_ERR_PARAM;
	}

	if (src_type <= VM_CHSET_BASE || src_type >= VM_CHSET_TOTAL)
	{
		vm_log_error("[CHSET MODULE] Src enconding unsupport");
		return VM_CHSET_CONVERT_SRC_UNSUPPORT_CHSET;
	}

	if (dest_type <= VM_CHSET_BASE || dest_type >= VM_CHSET_TOTAL)
	{
		vm_log_error("[CHSET MODULE] dest enconding unsupport");
		return VM_CHSET_CONVERT_DST_UNSUPPORT_CHSET;
	}

#if(!defined(__VRE_RB_09A__) && !defined(__VRE_RB_08A__))
	if (mmi_chset_is_enabled(vreEncodingType2mtkEncodingType[1][src_type -1]) == KAL_FALSE)
	{
		vm_log_error("[CHSET MODULE] Src enconding unsupport, VRE encoding val[%d], MTK encoding val[%d].",
			vreEncodingType2mtkEncodingType[0][src_type - 1], vreEncodingType2mtkEncodingType[1][src_type - 1]);
		return VM_CHSET_CONVERT_SRC_UNSUPPORT_CHSET;
	}

	if (mmi_chset_is_enabled(vreEncodingType2mtkEncodingType[1][dest_type - 1]) == KAL_FALSE)
	{
		vm_log_error("[CHSET MODULE] Dest enconding unsupport, VRE encoding val[%d], MTK encoding val[%d].",
			vreEncodingType2mtkEncodingType[0][dest_type - 1], vreEncodingType2mtkEncodingType[1][dest_type - 1]);
		return VM_CHSET_CONVERT_DST_UNSUPPORT_CHSET;
	}
#endif

	if ((result = mmi_chset_convert(
		vreEncodingType2mtkEncodingType[1][src_type - 1], 
		vreEncodingType2mtkEncodingType[1][dest_type - 1], 
		src, dest, dest_size)) > 0)
	{
		return VM_CHSET_CONVERT_SUCCESS;
	}

	return VM_CHSET_CONVERT_FATAL_ERROR;
}

vm_language_t vm_get_language(void)
{
	VMUCHAR * countrycode = NULL;
	vm_language_t retval = LANG_UNKOWN;

	countrycode = (U8 *)Get_Current_Lang_CountryCode();
	if (countrycode != NULL)
	{
		//vm_log_debug("countrycode : %s", countrycode);

		if (strcmp((char *)countrycode, (char *)"zh-CN") == 0)
		{
			retval =  GB;
		}
		else if (strcmp((char *)countrycode, (char *)"zh-TW") == 0)
		{
			retval =  BIG5;
		}
		else if (
			strcmp((char *)countrycode, (char *)"en-US") == 0 ||
			strcmp((char *)countrycode, (char *)"en-EN") == 0 ||
			strcmp((char *)countrycode, (char *)"en-UK") == 0
			) 
		{
			retval =  ENGLISH;
		}
/* add by zaiping.chen, 2010.07.17, begin */
#if defined(__MMI_LANG_FRENCH__)
		else if ((strcmp((char *)countrycode, (char *)"fr-FR") == 0) ||
				 (strcmp((char *)countrycode, (char *)"fr-CA") == 0))
		{
			retval = FRENCH;
		}
#endif
#if defined(__MMI_LANG_SPANISH__)
		else if ((strcmp((char *)countrycode, (char *)"es-ES") == 0) ||
				 (strcmp((char *)countrycode, (char *)"es-SA") == 0))
		{
			retval = SPANISH;
		}
#endif
#if defined(__MMI_LANG_DANISH__)
		else if (strcmp((char *)countrycode, (char *)"da-DK") == 0)
		{
			retval = DANISH;
		}
#endif
#if defined(__MMI_LANG_POLISH__)
		else if (strcmp((char *)countrycode, (char *)"pl-PL") == 0)
		{
			retval = POLISH;
		}
#endif
#if defined(__MMI_LANG_PORTUGUESE__)
		else if (strcmp((char *)countrycode, (char *)"pt-PT") == 0)
		{
			retval = PORTUGUESE;
		}
#endif
#if defined(__MMI_LANG_ALBANIAN__)
		else if (strcmp((char *)countrycode, (char *)"sq-SQ") == 0)
		{
			retval = ALBANIAN;
		}
#endif
#if defined(__MMI_LANG_SA___)
		else if (strcmp((char *)countrycode, (char *)"pt-BZ") == 0)
		{
			retval = SA;
		}
#endif
#if defined(__MMI_LANG___)
		else if (strcmp((char *)countrycode, (char *)"is-IS") == 0)
		{
			retval = ICELANDIC;
		}
#endif
#if defined(__MMI_LANG_SERBIAN__)
{
		else if (strcmp((char *)countrycode, (char *)"sr-SR") == 0)
		{
			retval = SERBIAN;
		}
#endif
#if defined(__MMI_LANG_AZERBAIJANI__)
		else if (strcmp((char *)countrycode, (char *)"az-AZ") == 0)
		{
			retval = AZERBAIJANI;
		}
#endif
#if defined(__MMI_LANG_CATALAN__)
		else if (strcmp((char *)countrycode, (char *)"ca-CA") == 0)
		{
			retval = CATALAN;
		}
#endif
#if defined(__MMI_LANG_HAUSA__)
		else if (strcmp((char *)countrycode, (char *)"ha-HA") == 0)
		{
			retval = HAUSA;
		}
#endif

#if defined(__MMI_LANG_KAZAKH__)
		else if (strcmp((char *)countrycode, (char *)"kk-KK") == 0)
		{
			retval = KAZAKH;
		}
#endif
#if defined(__MMI_LANG_MACEDONIAN__)
		else if (strcmp((char *)countrycode, (char *)"mk-MK") == 0)
		{
			retval = MACEDONIAN;
		}
#endif
#if defined(__MMI_LANG_SESOTHO__)
		else if (strcmp((char *)countrycode, (char *)"st-ST") == 0)
		{
			retval = SESOTHO;
		}
#endif

#if defined(__MMI_LANG_TAGALOG__)
		else if (strcmp((char *)countrycode, (char *)"tl-TL") == 0)
		{
			retval = TAGALOG;
		}
#endif
#if defined(__MMI_LANG_YORUBA__)
		else if (strcmp((char *)countrycode, (char *)"yo-YO") == 0)
		{
			retval = YORUBA;
		}
#endif
#if defined(__MMI_LANG_ITALIAN__)
		else if (strcmp((char *)countrycode, (char *)"it-IT") == 0)
		{
			retval = ITALIAN;
		}
#endif
#if defined(__MMI_LANG_GERMAN__)
		else if (strcmp((char *)countrycode, (char *)"de-DE") == 0)
		{
			retval = GERMAN;
		}
#endif
#if defined(__MMI_LANG_MALAY__)
		else if (strcmp((char *)countrycode, (char *)"ms-MY") == 0)
		{
			retval = MALAY;
		}
#endif
#if defined(__MMI_LANG_INDONESIAN__)
		else if (strcmp((char *)countrycode, (char *)"id-ID") == 0)
		{
			retval = INDONESIAN;
		}
#endif
#if defined(__MMI_LANG_CZECH__)
		else if (strcmp((char *)countrycode, (char *)"cs-CZ") == 0)
		{
			retval = CZECH;
		}
#endif
#if defined(__MMI_LANG_NORWEGIAN__)
		else if (strcmp((char *)countrycode, (char *)"nb-NO") == 0)
		{
			retval = NORWEGIAN;
		}
#endif
#if defined(__MMI_LANG_SLOVAK__)
		else if (strcmp((char *)countrycode, (char *)"sk-SK") == 0)
		{
			retval = SLOVAK;
		}
#endif
#if defined(__MMI_LANG_DUTCH__)
		else if (strcmp((char *)countrycode, (char *)"nl-NL") == 0)
		{
			retval = DUTCH;
		}
#endif
#if defined(__MMI_LANG_FINNISH__)
		else if (strcmp((char *)countrycode, (char *)"fi-FI") == 0)
		{
			retval = FINNISH;
		}
#endif
#if defined(__MMI_LANG_HUNGARIAN__)
		else if (strcmp((char *)countrycode, (char *)"hu-HU") == 0)
		{
			retval = HUNGARIAN;
		}
#endif
#if defined(__MMI_LANG_VIETNAMESE__)
		else if (strcmp((char *)countrycode, (char *)"vi-VN") == 0)
		{
			retval = VIETNAMESE;
		}
#endif
#if defined(__MMI_LANG_TURKISH__)
		else if (strcmp((char *)countrycode, (char *)"tr-TR") == 0)
		{
			retval = TURKISH;
		}
#endif
#if defined(__MMI_LANG_RUSSIAN__)
		else if (strcmp((char *)countrycode, (char *)"ru-RU") == 0)
		{
			retval = RUSSIAN;
		}
#endif
#if defined(__MMI_LANG_BULGARIAN__)
		else if (strcmp((char *)countrycode, (char *)"bg-BG") == 0)
		{
			retval = ;
		}
#endif
#if defined(__MMI_LANG_UKRAINIAN__)
		else if (strcmp((char *)countrycode, (char *)"uk-UA") == 0)
		{
			retval = UKRAINIAN;
		}
#endif
#if defined(__MMI_LANG_ARABIC__)
		else if (strcmp((char *)countrycode, (char *)"ar-SA") == 0)
		{
			retval = ARABIC;
		}
#endif
#if defined(__MMI_LANG_PERSIAN__)
		else if (strcmp((char *)countrycode, (char *)"ps-IR") == 0)
		{
			retval = PERSIAN;
		}
#endif
#if defined(__MMI_LANG_URDU__)
		else if (strcmp((char *)countrycode, (char *)"ur-PK") == 0)
		{
			retval = URDU;
		}
#endif
#if defined(__MMI_LANG_HEBREW__)
		else if (strcmp((char *)countrycode, (char *)"he-IL") == 0)
		{
			retval = HEBREW;
		}
#endif
#if defined(__MMI_LANG_THAI__)
		else if (strcmp((char *)countrycode, (char *)"th-TH") == 0)
		{
			retval = THAI;
		}
#endif
#if defined(__MMI_LANG_GREEK__)
		else if (strcmp((char *)countrycode, (char *)"el-GR") == 0)
		{
			retval = GREEK;
		}
#endif
#if defined(__MMI_LANG_SWEDISH__)
		else if (strcmp((char *)countrycode, (char *)"sv-SE") == 0)
		{
			retval = SWEDISH;
		}
#endif
#if defined(__MMI_LANG_CROATIAN__)
		else if (strcmp((char *)countrycode, (char *)"hr-HR") == 0)
		{
			retval = CROATIAN;
		}
#endif
#if defined(__MMI_LANG_ROMANIAN__)
		else if (strcmp((char *)countrycode, (char *)"ro-RO") == 0)
		{
			retval = ROMANIAN;
		}
#endif
#if defined(__MMI_LANG_SLOVENIAN__)
		else if (strcmp((char *)countrycode, (char *)"sl-SI") == 0)
		{
			retval = SLOVENIAN;
		}
#endif
#if defined(__MMI_LANG_HINDI__)
		else if (strcmp((char *)countrycode, (char *)"hi-IN") == 0)
		{
			retval = HINDI;
		}
#endif
#if defined(__MMI_LANG_MARATHI__)  
		else if (strcmp((char *)countrycode, (char *)"mr-IN") == 0)
		{
			retval = MARATHI;
		}
#endif
#if defined(__MMI_LANG_TAMIL__)
		else if (strcmp((char *)countrycode, (char *)"ta-IN") == 0)
		{
			retval = TAMIL;
		}
#endif
#if defined(__MMI_LANG_GUJARATI__)
		else if (strcmp((char *)countrycode, (char *)"gu-IN") == 0)
		{
			retval = GUJARATI;
		}
#endif
#if defined(__MMI_LANG_BENGALI__)
		else if (strcmp((char *)countrycode, (char *)"be-IN") == 0)
		{
			retval = BENGALI;
		}
#endif
#if defined(__MMI_LANG_ASSAMESE__)
		else if (strcmp((char *)countrycode, (char *)"as-IN") == 0)
		{
			retval = ASSAMESE;
		}
#endif
#if defined(__MMI_LANG_PUNJABI__)
		else if (strcmp((char *)countrycode, (char *)"pa-IN") == 0)
		{
			retval = PUNJABI;
		}
#endif
#if defined(__MMI_LANG_TELUGU__)
		else if (strcmp((char *)countrycode, (char *)"te-IN") == 0)
		{
			retval = TELUGU;
		}
#endif
#if defined(__MMI_LANG_KANNADA__)
		else if (strcmp((char *)countrycode, (char *)"kn-IN") == 0)
		{
			retval = KANNADA;
		}
#endif
#if defined(__MMI_LANG_MALAYALAM__)
		else if (strcmp((char *)countrycode, (char *)"ml-IN") == 0)
		{
			retval = MALAYALAM;
		}
#endif
#if defined(__MMI_LANG_ORIYA__)
		else if (strcmp((char *)countrycode, (char *)"or-IN") == 0)
		{
			retval = ORIYA;
		}
#endif
#if defined(__MMI_LANG_XHOSA__)
		else if (strcmp((char *)countrycode, (char *)"xh-ZA") == 0)
		{
			retval = XHOSA;
		}
#endif
#if defined(__MMI_LANG_SWAHILI__)
		else if (strcmp((char *)countrycode, (char *)"sw-TZ") == 0)
		{
			retval = SWAHILI;
		}
#endif
#if defined(__MMI_LANG_AFRIKAANS__)
		else if (strcmp((char *)countrycode, (char *)"af-NA") == 0)
		{
			retval = AFRIKAANS;
		}
#endif
#if defined(__MMI_LANG_ZULU__)
		else if (strcmp((char *)countrycode, (char *)"zu-SZ") == 0)
		{
			retval = ZULU;
		}
#endif
#if defined(__MMI_LANG_LITHUANIAN__)
		else if (strcmp((char *)countrycode, (char *)"lt-LT") == 0)
		{
			retval = LITHUANIAN;
		}
#endif
#if defined(__MMI_LANG_LATVIAN__)
		else if (strcmp((char *)countrycode, (char *)"lv-LV") == 0)
		{
			retval = LATVIAN;
		}
#endif
#if defined(__MMI_LANG_ESTONIAN__)
		else if (strcmp((char *)countrycode, (char *)"et-EE") == 0)
		{
			retval = ESTONIAN;
		}
#endif
#if defined(__MMI_LANG_ARMENIAN__)
		else if (strcmp((char *)countrycode, (char *)"hy-AM") == 0)
		{
			retval = ARMENIAN;
		}
#endif
#if defined(__MMI_LANG_GEORGIAN__)
		else if (strcmp((char *)countrycode, (char *)"ka-GE") == 0)
		{
			retval = GEORGIAN;
		}
#endif
#if defined(__MMI_LANG_MOLDOVAN__)
		else if (strcmp((char *)countrycode, (char *)"mo-MD") == 0)
		{
			retval = MOLDOVAN;
		}
#endif
#if defined(__MMI_LANG_GALICIAN__)
		else if (strcmp((char *)countrycode, (char *)"gl-ES") == 0)
		{
			retval = GALICIAN;
		}
#endif
#if defined(__MMI_LANG_BASQUE__)
		else if (strcmp((char *)countrycode, (char *)"eu-ES") == 0)
		{
			retval = BASQUE;
		}
#endif
#if defined(__MMI_LANG_IGBO__)
		else if (strcmp((char *)countrycode, (char *)"ig-NG") == 0)
		{
			retval = IGBO;
		}
#endif
#if defined(__MMI_LANG_FILIPINO__)
		else if (strcmp((char *)countrycode, (char *)"fil-PH") == 0)
		{
			retval = FILIPINO;
		}
#endif
#if defined(__MMI_LANG_IRISH__)
		else if (strcmp((char *)countrycode, (char *)"ga-IE") == 0)
		{
			retval = IRISH;
		}
#endif
/* add by zaiping.chen, 2010.07.17, end */
		else
		{
			retval =  LANG_UNKOWN;
		}
	}
	else
	{
		retval = LANG_UNKOWN;
	}
	
	return retval;	
}

#endif
