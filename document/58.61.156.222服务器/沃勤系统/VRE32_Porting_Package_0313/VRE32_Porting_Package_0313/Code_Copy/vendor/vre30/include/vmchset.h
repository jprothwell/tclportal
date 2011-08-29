#ifndef VMCHSET_H_
#define VMCHSET_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"

#define CONVERT_CHSET_MAX_LEN 4096

/**
 * 把UCS2格式的字符串转换为当地默认语言编码格式的字符串。
 *
 * @param dst			存放转换结果的字符串。
 * @param size			目标串的最大长度。
 * @param src			被转换的字符串。
 *
 * @return				返回0表示转换成功，否则为失败。
 */
VMINT vm_ucs2_to_default(VMSTR dst, VMINT size, VMWSTR src);

/**
 * 把地默认语言编码格式的字符串转换为UCS2编码格式。
 *
 * @param dst			存放转换结果的字符串。
 * @param size			目标串的最大长度。
 * @param src			被转换的字符串。
 *
 * @return				返回0表示转换成功，否则为失败。
 */
VMINT  vm_default_to_ucs2(VMWSTR dst, VMINT size, VMSTR src);

/**
 * 把UCS2格式的字符串转换为GB2312编码格式的字符串。
 *
 * @param dst			存放转换结果的字符串。
 * @param size			目标串的最大长度。
 * @param src			被转换的字符串。
 *
 * @return				返回0表示转换成功，否则为失败。
 */
VMINT vm_ucs2_to_gb2312(VMSTR dst, VMINT size, VMWSTR src);

/**
 * 把GB2312格式的字符串转换为UCS2编码格式。
 *
 * @param dst			存放转换结果的字符串。
 * @param size			目标串的最大长度。
 * @param src			被转换的字符串。
 *
 * @return				返回0表示转换成功，否则为失败。
 */
VMINT  vm_gb2312_to_ucs2(VMWSTR dst, VMINT size, VMSTR src);

/**
 * 把UCS2格式的字符串转换为ASCII编码格式的字符串。
 *
 * @param dst			存放转换结果的字符串。
 * @param size			目标串的最大长度。
 * @param src			被转换的字符串。
 *
 * @return				返回0表示转换成功，否则为失败。
 */
VMINT vm_ucs2_to_ascii(VMSTR dst, VMINT size, VMWSTR src);

/**
 * 把ASCII格式的字符串转换为UCS2编码格式。
 *
 * @param dst			存放转换结果的字符串。
 * @param size			目标串的最大长度。
 * @param src			被转换的字符串。
 *
 * @return				返回0表示转换成功，否则为失败。
 */
VMINT vm_ascii_to_ucs2(VMWSTR dst, VMINT size, VMSTR src);

/**
 * 把给定的GB2312编码字符串立即转换为UCS2编码并返回，这是一个简化版的转换函数，
 * 非线程安全。
 */
VMWSTR vm_ucs2_string(VMSTR s);

/**
 * 把给定的ASCII编码字符串立即转换为UCS2编码并返回，这是一个简化版的转换函数，
 * 非线程安全。
 */
VMWSTR vm_ucs2_string_by_ascii(VMSTR s);

/**
 * 把UCS字符串转换为GB2312，这是简化版的转换函数，非线程安全，也不能递归调用。
 * 
 * @param s		被转换的字符串。 
 * 
 * @return		转换为GB2312的字符串指针。
 */
char* vm_gb2312_string(VMWSTR s);

typedef enum {GB = 1, ENGLISH, BIG5, FRENCH, SPANISH, DANISH, POLISH, PORTUGUESE, 
	ALBANIAN, ICELANDIC, SERBIAN, AZERBAIJANI, CATALAN,	HAUSA, KAZAKH, MACEDONIAN, 
	SESOTHO, TAGALOG, YORUBA, ITALIAN, GERMAN, 	MALAY, INDONESIAN, CZECH, 
	NORWEGIAN, SLOVAK, DUTCH, FINNISH, HUNGARIAN, VIETNAMESE, TURKISH, RUSSIAN, 
	UKRAINIAN, ARABIC, PERSIAN, URDU, HEBREW, THAI, GREEK, SWEDISH, CROATIAN, 
	ROMANIAN, SLOVENIAN, HINDI, MARATHI, TAMIL,	GUJARATI, BENGALI, ASSAMESE, 
	PUNJABI, TELUGU, KANNADA, MALAYALAM, ORIYA, XHOSA, SWAHILI, AFRIKAANS, 
	ZULU, LITHUANIAN, LATVIAN, ESTONIAN, ARMENIAN, GEORGIAN, MOLDOVAN, GALICIAN,
	BASQUE, IGBO, FILIPINO, IRISH, LANG_UNKOWN
} vm_language_t;


/**
 * 得到平台现在正在使用的语言类型。
 *
 *
 * @return				当前平台所使用的语言类型。				
 */
vm_language_t vm_get_language(void);

typedef enum
{
	VM_CHSET_BASE = 0,
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
    	VM_CHSET_UCS2,
	VM_CHSET_TOTAL
}vm_chset_enum;

/**
 * vm_chset_convert 函数的返回值。
 * @{
 */
#define VM_CHSET_CONVERT_SUCCESS						(0)
#define VM_CHSET_CONVERT_ERR_PARAM					(-1)
#define VM_CHSET_CONVERT_SRC_UNSUPPORT_CHSET		(-2)
#define VM_CHSET_CONVERT_DST_UNSUPPORT_CHSET		(-3)
#define VM_CHSET_CONVERT_FATAL_ERROR					(-4)
/** @} */

/**
 * 字符编码转换。
 * 
 * @param[in] 				src_type 源字符串编码类型。
 * @param[in] 				dest_type 目标字符串编码类型。
 * @param[in] 				src 源字符串。
 * @param[out] 				dest 存放目标字符串的空间。
 * @param[in] 				dest_size 存放目标字符串空间的大小，单位为字节。
 * 
 * @return					转码是否成功的标志。
 * @retval					VM_CHSET_CONVERT_SUCCESS 转码成功.
 * @retval					VM_CHSET_CONVERT_ERR_PARAM 参数错误.
 * @retval					VM_CHSET_CONVERT_SRC_UNSUPPORT_CHSET 源字符串的字符编码不被支持.
 * @retval					VM_CHSET_CONVERT_DST_UNSUPPORT_CHSET 需要转换到的编码不被支持.
 * @retval					VM_CHSET_CONVERT_FATAL_ERROR 转换字符编码失败。
 * 
 */
VMINT vm_chset_convert(vm_chset_enum src_type, vm_chset_enum dest_type, 
	VMCHAR* src, VMCHAR* dest, VMINT dest_size);


#ifdef __cplusplus
}
#endif

#endif
