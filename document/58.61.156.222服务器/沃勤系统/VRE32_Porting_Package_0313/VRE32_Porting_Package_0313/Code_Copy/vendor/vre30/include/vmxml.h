//#ifdef __XML_SUPPORT__

#ifndef VMXML_H
#define VMXML_H

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"

/*************************************************************/
/* Main data structures & types */

/**
 *	��������������ʾDOCTYPE��ǩ��ʼ���ַ���"<!DOCTYPE"ʱ�����ô˻ص�������
 *
 *	@param data					�����ֶΣ���δʹ��
 *	@param doctypeName			�ĵ���������
 *	@param sysid					SYSTEM��Ӧ���ַ�������
 *	@param pubid					PUBLIC��Ӧ���ַ�������
 *	@param internal_subset			�ڲ��Ӽ�������Ϊ0
 *	@param error 				�����룬VM_XML_ERROR_ENUM����
 *
 *	@return					void

****************************************************************
DOCTYPE Examples:

-CSDN
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" 
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"> 
doctypeName: html
pubid:
	"-//W3C//DTD XHTML 1.0 Transitional//EN" 
	"http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"
	
-Gmail
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
"http://www.w3.org/TR/html4/loose.dtd">
doctypeName: HTML
pubid:
	"-//W3C//DTD HTML 4.01 Transitional//EN" 
	"http://www.w3.org/TR/html4/loose.dtd"

-Google Calendar
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN" 
"http://www.w3.org/TR/html4/strict.dtd">
doctypeName: HTML
pubid:
	"-//W3C//DTD HTML 4.01//EN" 
	"http://www.w3.org/TR/html4/strict.dtd"

<!DOCTYPE note SYSTEM "Note.dtd">
doctypeName: note
sysid:
	"Note.dtd"
****************************************************************

 */
typedef void (*XML_start_doctype_hdlr) (
	void *data, 
	const VMCHAR *doctypeName,  
	const VMCHAR **sysid, 
	const VMCHAR **pubid,
	VMINT internal_subset,
	VMINT error);

/**
 *	��������������ʾDOCTYPE��ǩ�������ַ�">"ʱ�����ô˻ص�������
 *
 *    @param data				�����ֶΣ���δʹ��
 *    @param error 				�����룬VM_XML_ERROR_ENUM ����
 *
 *	@return					void
 */
typedef void (*XML_end_doctype_hdlr) (
	void *data, 
	VMINT error);

/**
 *	��������������ʾԪ�ر�ǩ��ʼ���ַ���"<xxx>"ʱ�����ô˻ص�������
 *
 *    @param data				�����ֶΣ���δʹ��
 *    @param el				Ԫ����:xxx
 *    @param attr 				�����б�0Ϊ��������1Ϊ����ֵ��2Ϊ��������3Ϊ����ֵ...�Դ����ơ�
 *    @param error 				�����룬VM_XML_ERROR_ENUM ����
 *
 *	@return					void
 */
typedef void (*XML_start_elem_hdlr) (
	void *data,
	const VMCHAR *el,
	const VMCHAR **attr,
	VMINT error);

/**
 *	��������������ʾԪ�ر�ǩ�������ַ���"</xxx>"ʱ�����ô˻ص�������
 *
 *    @param data				�����ֶΣ���δʹ��
 *    @param el				Ԫ����:xxx
 *    @param error 				�����룬VM_XML_ERROR_ENUM ����
 *
 *	@return					void
 */
typedef void (*XML_end_elem_hdlr) (
	void *data, 
	const VMCHAR *el, 
	VMINT error);

/**
 *	������������Ԫ���е�����ʱ"<xxx>xxxxx</xxx>"�����ô˻ص�������
 *
 *    @param resv				�����ֶΣ���δʹ��
 *    @param el				Ԫ����:xxx
 *    @param data 				����:xxxxx
 *    @param len				���ݳ���
 *    @param error 				������
 *
 *	@return					void
 */
typedef void (*XML_data_hdlr) (
	void *resv,
	const VMCHAR *el,
	const VMCHAR *data,
	VMINT len,
	VMINT error);

/**
 * ��������Ĵ�����ö�����͡�
 */
typedef enum
{
    VM_XML_RESULT_FILE_NOT_FOUND = -4,	/* the file isn't found */
    VM_XML_RESULT_OUT_OF_MEMORY = -3,		/* the memory isn't enough*/
    VM_XML_RESULT_ENCODING_ERROR = -2,	/* the char encoding error */
    VM_XML_RESULT_FAIL = -1,				/* fail to parse xml */
    VM_XML_RESULT_OK = 0					/* parsing xml succed */
} VM_XML_RESULT_ENUM;

/**
 * ���������лص�����ʹ�õĴ�����ö�����͡�
 */
typedef enum
{
    VM_XML_NO_ERROR,									/* no error */
    VM_XML_ERROR_MISMATCH_TAG,						/* error string: end tag name */
    VM_XML_ERROR_MISMATCH_DOCTYPENAME_ROOTNAME,	/* error string: root element name */
    VM_XML_ERROR_INVALID_ATTRIBUTE,					/* error string: attribute name */
    VM_XML_ERROR_DUPLICATE_ATTRIBUTE,				/* error string: attribute name */
    VM_XML_ERROR_ENTITY_DEFINITION,					/* error string: entity name */
    VM_XML_ERROR_UNDEFINED_ENTITY               			/* error string: entity name */
} VM_XML_ERROR_ENUM;

/**
 * �������ṹ��������������лص�������ָ�롣
 */
typedef struct _VM_XML_PARSER_STRUCT 
{
	XML_start_doctype_hdlr start_doctype_hdlr;	/* function pointer provided by app */
	XML_end_doctype_hdlr end_doctype_hdlr;	/* function pointer provided by app */
	XML_start_elem_hdlr start_elem_hdlr;		/* function pointer provided by app */
	XML_end_elem_hdlr end_elem_hdlr;			/* function pointer provided by app */
	XML_data_hdlr data_hdlr;					/* function pointer provided by app */
} VM_XML_PARSER_STRUCT;

/*************************************************************/
/** Main APIs */
/**
 * ��ʼ��һ���µĽ��������������лص���������ΪϵͳĬ��ֵ��
 *
 * @param parser		ȫ�ֽ������ṹ
 *
 * @return			    ʧ�ܣ�VM_XML_RESULT_FAIL�� �ɹ���VM_XML_RESULT_OK
 */
VMINT vm_xml_new_parser(VM_XML_PARSER_STRUCT *parser);

/**
 * Ϊ����������DOCTYPE��ǩ�ص�������
 *
 * @param parser		ȫ�ֽ������ṹ
 * @param start_hdlr	DOCTYPE��ǩ��ʼ�ص�����ָ��
 * @param end_hdlr	DOCTYPE��ǩ�����ص�����ָ��
 *
 * @return			void
 */
void vm_xml_set_doctype_handlers(
	VM_XML_PARSER_STRUCT *parser,
	XML_start_doctype_hdlr start_hdlr,
	XML_end_doctype_hdlr end_hdlr);

/**
 * Ϊ����������Ԫ�ر�ǩ�ص�������
 *
 * @param parser		ȫ�ֽ������ṹ
 * @param start_hdlr	Ԫ�ر�ǩ��ʼ�ص�����ָ��
 * @param end_hdlr	Ԫ�ر�ǩ�����ص�����ָ��
 *
 * @return			void
 */
void vm_xml_set_element_handlers(
	VM_XML_PARSER_STRUCT *parser,
	XML_start_elem_hdlr start_hdlr,
	XML_end_elem_hdlr end_hdlr);

/**
 * Ϊ�������������ݴ���ص�������
 *
 * @param parser		ȫ�ֽ������ṹ
 * @param data_hdlr	���ݴ���ص�����ָ��
 *
 * @return			void
 */
void vm_xml_set_data_handler(
	VM_XML_PARSER_STRUCT *parser, 
	XML_data_hdlr data_hdlr);

/**
 * ��ʼ����XML��
 *
 * @param parser		ȫ�ֽ������ṹ
 * @param xmlsource	����ΪXML�ļ���, Ҳ����ΪXML�ַ���������
 * @param length		��length==0˵��XML�����ļ�����length>0˵��XML���Ի�������
 *
 * @return			ʧ�ܣ�VM_XML_RESULT_FAIL�� �ɹ���VM_XML_RESULT_OK
 */
VMINT vm_xml_parse(
	VM_XML_PARSER_STRUCT *parser,
	const VMCHAR *xmlsource,
	VMINT length);

/**
 * ��ȡ�����ַ�����
 *
 * @return			�ַ�����ʽ�Ĵ�������
 */
VMCHAR* vm_xml_get_error(void);

/****************************************************************/

/**
 * ��ȡXML�����������
 *
 * @return		XML�����������
VMINT vm_xml_fetch_handle(void);
 */

/**
 * ע��DOCTYPE��ǩ����ص�������
 *
 * @param 		handle, XML�����������
 * @param 		start_hdlr, DOCTYPE��ǩ��ʼ�ص�����ָ�롣
 * @param 		end_hdlr, DOCTYPE��ǩ�����ص�����ָ�롣
 *
 * @return		<0, failed; ==0, success
VMINT vm_xml_reg_doctype_handlers(
	VMINT handle, 
	XML_start_doctype_hdlr start_hdlr,
	XML_end_doctype_hdlr end_hdlr);
 */

/**
 * ע��Ԫ�ر�ǩ����ص�������
 *
 * @param 		handle, XML�����������
 * @param 		start_hdlr, Ԫ�ر�ǩ��ʼ�ص�����ָ�롣
 * @param 		end_hdlr, Ԫ�ر�ǩ�����ص�����ָ�롣
 *
 * @return		<0, failed; ==0, success
VMINT vm_xml_reg_element_handlers(
	VMINT handle, 
	XML_start_elem_hdlr start_hdlr,
	XML_end_elem_hdlr end_hdlr);
 */

/**
 *  ע�����ݴ���ص�������
 *
 * @param 		handle, XML�����������
 * @param 		elem_hdlr, ���ݴ���ص�����ָ�롣
 *
 * @return		<0, failed; ==0, success
VMINT vm_xml_reg_data_handler(
	VMINT handle, 
	XML_data_hdlr data_hdlr);
 */

/**
 * ��ʼ����XML��
 *
 * @param 		handle, XML�����������
 * @param 		xmlsource, ����ΪXML�ļ���, Ҳ����ΪXML�ַ���������
 * @param 		length, 	��length==0˵��XML�����ļ���
 						��length>0˵��XML���Ի�������
 *
 * @return		<0, failed; ==0, success
VMINT vm_xml_do_parse(
	VMINT handle,
 	const VMCHAR *xmlsource,
	VMINT length);
 */

/**
 *  �ͷ�XML�����������
 *
 * @param 		handle, XML�����������
 *
 * @return		<0, failed; ==0, success
VMINT vm_xml_free_handle(VMINT handle);
 */

/**
 * ��ȡ�����ַ�����
 *
 * @return		�ַ�����ʽ�Ĵ�������
VMCHAR* vm_xml_get_last_error(void);
 */

#ifdef __cplusplus
}
#endif

#endif	/*VMXML_H*/ 

//#endif	/*__XML_SUPPORT__*/
