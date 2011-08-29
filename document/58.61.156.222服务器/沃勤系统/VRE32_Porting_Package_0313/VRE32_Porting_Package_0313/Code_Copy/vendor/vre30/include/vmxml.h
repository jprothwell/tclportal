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
 *	当解析器读到表示DOCTYPE标签开始的字符串"<!DOCTYPE"时，调用此回调函数。
 *
 *	@param data					保留字段，尚未使用
 *	@param doctypeName			文档类型名称
 *	@param sysid					SYSTEM对应的字符串数组
 *	@param pubid					PUBLIC对应的字符串数组
 *	@param internal_subset			内部子集，总是为0
 *	@param error 				错误码，VM_XML_ERROR_ENUM类型
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
 *	当解析器读到表示DOCTYPE标签结束的字符">"时，调用此回调函数。
 *
 *    @param data				保留字段，尚未使用
 *    @param error 				错误码，VM_XML_ERROR_ENUM 类型
 *
 *	@return					void
 */
typedef void (*XML_end_doctype_hdlr) (
	void *data, 
	VMINT error);

/**
 *	当解析器读到表示元素标签开始的字符串"<xxx>"时，调用此回调函数。
 *
 *    @param data				保留字段，尚未使用
 *    @param el				元素名:xxx
 *    @param attr 				属性列表，0为属性名，1为属性值；2为属性名，3为属性值...以此类推。
 *    @param error 				错误码，VM_XML_ERROR_ENUM 类型
 *
 *	@return					void
 */
typedef void (*XML_start_elem_hdlr) (
	void *data,
	const VMCHAR *el,
	const VMCHAR **attr,
	VMINT error);

/**
 *	当解析器读到表示元素标签结束的字符串"</xxx>"时，调用此回调函数。
 *
 *    @param data				保留字段，尚未使用
 *    @param el				元素名:xxx
 *    @param error 				错误码，VM_XML_ERROR_ENUM 类型
 *
 *	@return					void
 */
typedef void (*XML_end_elem_hdlr) (
	void *data, 
	const VMCHAR *el, 
	VMINT error);

/**
 *	当解析器读到元素中的数据时"<xxx>xxxxx</xxx>"，调用此回调函数。
 *
 *    @param resv				保留字段，尚未使用
 *    @param el				元素名:xxx
 *    @param data 				数据:xxxxx
 *    @param len				数据长度
 *    @param error 				错误码
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
 * 解析结果的错误码枚举类型。
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
 * 解析过程中回调函数使用的错误码枚举类型。
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
 * 解析器结构体变量，保存所有回调函数的指针。
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
 * 初始化一个新的解析器。其中所有回调函数被设为系统默认值。
 *
 * @param parser		全局解析器结构
 *
 * @return			    失败：VM_XML_RESULT_FAIL； 成功：VM_XML_RESULT_OK
 */
VMINT vm_xml_new_parser(VM_XML_PARSER_STRUCT *parser);

/**
 * 为解析器设置DOCTYPE标签回调函数。
 *
 * @param parser		全局解析器结构
 * @param start_hdlr	DOCTYPE标签开始回调函数指针
 * @param end_hdlr	DOCTYPE标签结束回调函数指针
 *
 * @return			void
 */
void vm_xml_set_doctype_handlers(
	VM_XML_PARSER_STRUCT *parser,
	XML_start_doctype_hdlr start_hdlr,
	XML_end_doctype_hdlr end_hdlr);

/**
 * 为解析器设置元素标签回调函数。
 *
 * @param parser		全局解析器结构
 * @param start_hdlr	元素标签开始回调函数指针
 * @param end_hdlr	元素标签结束回调函数指针
 *
 * @return			void
 */
void vm_xml_set_element_handlers(
	VM_XML_PARSER_STRUCT *parser,
	XML_start_elem_hdlr start_hdlr,
	XML_end_elem_hdlr end_hdlr);

/**
 * 为解析器设置数据处理回调函数。
 *
 * @param parser		全局解析器结构
 * @param data_hdlr	数据处理回调函数指针
 *
 * @return			void
 */
void vm_xml_set_data_handler(
	VM_XML_PARSER_STRUCT *parser, 
	XML_data_hdlr data_hdlr);

/**
 * 开始解析XML。
 *
 * @param parser		全局解析器结构
 * @param xmlsource	可能为XML文件名, 也可能为XML字符串缓存名
 * @param length		若length==0说明XML来自文件；若length>0说明XML来自缓冲区。
 *
 * @return			失败：VM_XML_RESULT_FAIL； 成功：VM_XML_RESULT_OK
 */
VMINT vm_xml_parse(
	VM_XML_PARSER_STRUCT *parser,
	const VMCHAR *xmlsource,
	VMINT length);

/**
 * 获取错误字符串。
 *
 * @return			字符串形式的错误描述
 */
VMCHAR* vm_xml_get_error(void);

/****************************************************************/

/**
 * 获取XML解析器句柄。
 *
 * @return		XML解析器句柄。
VMINT vm_xml_fetch_handle(void);
 */

/**
 * 注册DOCTYPE标签处理回调函数。
 *
 * @param 		handle, XML解析器句柄。
 * @param 		start_hdlr, DOCTYPE标签开始回调函数指针。
 * @param 		end_hdlr, DOCTYPE标签结束回调函数指针。
 *
 * @return		<0, failed; ==0, success
VMINT vm_xml_reg_doctype_handlers(
	VMINT handle, 
	XML_start_doctype_hdlr start_hdlr,
	XML_end_doctype_hdlr end_hdlr);
 */

/**
 * 注册元素标签处理回调函数。
 *
 * @param 		handle, XML解析器句柄。
 * @param 		start_hdlr, 元素标签开始回调函数指针。
 * @param 		end_hdlr, 元素标签结束回调函数指针。
 *
 * @return		<0, failed; ==0, success
VMINT vm_xml_reg_element_handlers(
	VMINT handle, 
	XML_start_elem_hdlr start_hdlr,
	XML_end_elem_hdlr end_hdlr);
 */

/**
 *  注册数据处理回调函数。
 *
 * @param 		handle, XML解析器句柄。
 * @param 		elem_hdlr, 数据处理回调函数指针。
 *
 * @return		<0, failed; ==0, success
VMINT vm_xml_reg_data_handler(
	VMINT handle, 
	XML_data_hdlr data_hdlr);
 */

/**
 * 开始解析XML。
 *
 * @param 		handle, XML解析器句柄。
 * @param 		xmlsource, 可能为XML文件名, 也可能为XML字符串缓存名
 * @param 		length, 	若length==0说明XML来自文件；
 						若length>0说明XML来自缓冲区。
 *
 * @return		<0, failed; ==0, success
VMINT vm_xml_do_parse(
	VMINT handle,
 	const VMCHAR *xmlsource,
	VMINT length);
 */

/**
 *  释放XML解析器句柄。
 *
 * @param 		handle, XML解析器句柄。
 *
 * @return		<0, failed; ==0, success
VMINT vm_xml_free_handle(VMINT handle);
 */

/**
 * 获取错误字符串。
 *
 * @return		字符串形式的错误描述
VMCHAR* vm_xml_get_last_error(void);
 */

#ifdef __cplusplus
}
#endif

#endif	/*VMXML_H*/ 

//#endif	/*__XML_SUPPORT__*/
