#ifndef VMCHSET_H_
#define VMCHSET_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"

#define CONVERT_CHSET_MAX_LEN 4096

/**
 * ��UCS2��ʽ���ַ���ת��Ϊ����Ĭ�����Ա����ʽ���ַ�����
 *
 * @param dst			���ת��������ַ�����
 * @param size			Ŀ�괮����󳤶ȡ�
 * @param src			��ת�����ַ�����
 *
 * @return				����0��ʾת���ɹ�������Ϊʧ�ܡ�
 */
VMINT vm_ucs2_to_default(VMSTR dst, VMINT size, VMWSTR src);

/**
 * �ѵ�Ĭ�����Ա����ʽ���ַ���ת��ΪUCS2�����ʽ��
 *
 * @param dst			���ת��������ַ�����
 * @param size			Ŀ�괮����󳤶ȡ�
 * @param src			��ת�����ַ�����
 *
 * @return				����0��ʾת���ɹ�������Ϊʧ�ܡ�
 */
VMINT  vm_default_to_ucs2(VMWSTR dst, VMINT size, VMSTR src);

/**
 * ��UCS2��ʽ���ַ���ת��ΪGB2312�����ʽ���ַ�����
 *
 * @param dst			���ת��������ַ�����
 * @param size			Ŀ�괮����󳤶ȡ�
 * @param src			��ת�����ַ�����
 *
 * @return				����0��ʾת���ɹ�������Ϊʧ�ܡ�
 */
VMINT vm_ucs2_to_gb2312(VMSTR dst, VMINT size, VMWSTR src);

/**
 * ��GB2312��ʽ���ַ���ת��ΪUCS2�����ʽ��
 *
 * @param dst			���ת��������ַ�����
 * @param size			Ŀ�괮����󳤶ȡ�
 * @param src			��ת�����ַ�����
 *
 * @return				����0��ʾת���ɹ�������Ϊʧ�ܡ�
 */
VMINT  vm_gb2312_to_ucs2(VMWSTR dst, VMINT size, VMSTR src);

/**
 * ��UCS2��ʽ���ַ���ת��ΪASCII�����ʽ���ַ�����
 *
 * @param dst			���ת��������ַ�����
 * @param size			Ŀ�괮����󳤶ȡ�
 * @param src			��ת�����ַ�����
 *
 * @return				����0��ʾת���ɹ�������Ϊʧ�ܡ�
 */
VMINT vm_ucs2_to_ascii(VMSTR dst, VMINT size, VMWSTR src);

/**
 * ��ASCII��ʽ���ַ���ת��ΪUCS2�����ʽ��
 *
 * @param dst			���ת��������ַ�����
 * @param size			Ŀ�괮����󳤶ȡ�
 * @param src			��ת�����ַ�����
 *
 * @return				����0��ʾת���ɹ�������Ϊʧ�ܡ�
 */
VMINT vm_ascii_to_ucs2(VMWSTR dst, VMINT size, VMSTR src);

/**
 * �Ѹ�����GB2312�����ַ�������ת��ΪUCS2���벢���أ�����һ���򻯰��ת��������
 * ���̰߳�ȫ��
 */
VMWSTR vm_ucs2_string(VMSTR s);

/**
 * �Ѹ�����ASCII�����ַ�������ת��ΪUCS2���벢���أ�����һ���򻯰��ת��������
 * ���̰߳�ȫ��
 */
VMWSTR vm_ucs2_string_by_ascii(VMSTR s);

/**
 * ��UCS�ַ���ת��ΪGB2312�����Ǽ򻯰��ת�����������̰߳�ȫ��Ҳ���ܵݹ���á�
 * 
 * @param s		��ת�����ַ����� 
 * 
 * @return		ת��ΪGB2312���ַ���ָ�롣
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
 * �õ�ƽ̨��������ʹ�õ��������͡�
 *
 *
 * @return				��ǰƽ̨��ʹ�õ��������͡�				
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
 * vm_chset_convert �����ķ���ֵ��
 * @{
 */
#define VM_CHSET_CONVERT_SUCCESS						(0)
#define VM_CHSET_CONVERT_ERR_PARAM					(-1)
#define VM_CHSET_CONVERT_SRC_UNSUPPORT_CHSET		(-2)
#define VM_CHSET_CONVERT_DST_UNSUPPORT_CHSET		(-3)
#define VM_CHSET_CONVERT_FATAL_ERROR					(-4)
/** @} */

/**
 * �ַ�����ת����
 * 
 * @param[in] 				src_type Դ�ַ����������͡�
 * @param[in] 				dest_type Ŀ���ַ����������͡�
 * @param[in] 				src Դ�ַ�����
 * @param[out] 				dest ���Ŀ���ַ����Ŀռ䡣
 * @param[in] 				dest_size ���Ŀ���ַ����ռ�Ĵ�С����λΪ�ֽڡ�
 * 
 * @return					ת���Ƿ�ɹ��ı�־��
 * @retval					VM_CHSET_CONVERT_SUCCESS ת��ɹ�.
 * @retval					VM_CHSET_CONVERT_ERR_PARAM ��������.
 * @retval					VM_CHSET_CONVERT_SRC_UNSUPPORT_CHSET Դ�ַ������ַ����벻��֧��.
 * @retval					VM_CHSET_CONVERT_DST_UNSUPPORT_CHSET ��Ҫת�����ı��벻��֧��.
 * @retval					VM_CHSET_CONVERT_FATAL_ERROR ת���ַ�����ʧ�ܡ�
 * 
 */
VMINT vm_chset_convert(vm_chset_enum src_type, vm_chset_enum dest_type, 
	VMCHAR* src, VMCHAR* dest, VMINT dest_size);


#ifdef __cplusplus
}
#endif

#endif
