#ifdef __VRE__
#ifdef __XML_SUPPORT__

#if defined(__VRE_RB_08A__) || defined(__VRE_RB_08B__) /*Version control*/
#include "vaxml_def.h"
#define XML_NO_ERROR 	(0)
#else /*Version control*/
#include "APPSDKFrameworkGProt.h"
#include "APPSDKNetworkGProt.h"
#endif /*Version control*/

#include "vmio.h"
#include "vmchset.h"
#include "vmxml.h"

#include "vmpromng.h"
#include "vmresmng.h"

#define _VM_XML_DEBUG_

#ifdef _VM_XML_DEBUG_
#include "vmlog.h"
#else
#define vm_log_debug(...)
#define vm_log_info(...)
#define vm_log_warn(...)
#define vm_log_error(...)
#define vm_log_fatal(...)
#endif

//typedef struct _vm_xml_struct{
//	VM_XML_PARSER_STRUCT * vm_parser;
//#if defined(__VRE_RB_08A__) || defined(__VRE_RB_08B__) /*Version control*/
//	VA_XML_PARSER_STRUCT * mtk_parser;
//#else /*Version control*/
//	XML_PARSER_STRUCT * mtk_parser;
//#endif /*Version control*/
//} vm_xml_struct;

//extern VMINT vre_running;

#if defined(__VRE_RB_08A__) || defined(__VRE_RB_08B__) /*Version control*/
static VA_XML_PARSER_STRUCT mtk_xml_parser ;
#else /*Version control*/
static XML_PARSER_STRUCT mtk_xml_parser ;
#endif /*Version control*/

//static VMINT current_handle = -1;

#define XML_MAX_STR_LEN 	(256)

/**********************************************************************/
/** Default XML handlers */
/*
 * Default DOCTYPE start handler. log the basic data in XML.
 */
static void xml_doctype_start_handler( void *data,
										const VMCHAR *doctypeName,
										const VMCHAR **sysid, 
										const VMCHAR **pubid,
										VMINT internal_subset,
										VMINT error)
{
/*	int ret = -1;
	VMINT res_size = 0;
	vm_xml_struct * xml_struct = NULL;
	
	if (vre_running == FALSE)
	       return;

	* 获取current_handle 对应的资源 *
	ret = vm_res_get_data(VM_RES_TYPE_HTTP_HANDLE, current_handle, (void **)&xml_struct, &res_size);
	if (VM_RES_OK != ret)
	{
		vm_log_error("[XML MODULE] xml_doctype_start_handler - vm_res_get_data failed, "
			"ret:%d, current_handle:%d.", current_handle);
	       return;
	}

	xml_struct->vm_parser->start_doctype_hdlr(data, doctypeName, sysid, pubid, internal_subset, error);
*/	
	
	VMUINT  index = 0, i = 0;
	VMCHAR tmp[XML_MAX_STR_LEN];
	
	memset(tmp, 0, XML_MAX_STR_LEN);

	if (XML_NO_ERROR != error)
	{
		vm_log_error("[XML MODULE] xml_doctype_start_handler -Error:%s ", xml_get_err_string(&mtk_xml_parser));
		return;
	}
	else
	{
		strcat(tmp, "DOCTYPE_Start: ");
		strcat(tmp, doctypeName);
		strcat(tmp, "\t");
		if (sysid != NULL)
			while (sysid[i])
			{
				strcat(tmp, sysid[index]);
				strcat(tmp, "\t");
				i++;
			}
		i = 0;
		if (pubid != NULL)
			while (pubid[i])
			{
				strcat(tmp, pubid[index]);
				strcat(tmp, "\t");
				i++;
			}
		strcat(tmp, "\n");
		
		vm_log_debug("[XML MODULE] xml_doctype_start_handler - XML:%s", tmp);
		return;
	}
}

/*
 * Default DOCTYPE end handler. log the basic data in XML.
 */
static void xml_doctype_end_handler(void *data, VMINT error)
{
/*
	int ret = -1;
	VMINT res_size = 0;
	vm_xml_struct * xml_struct = NULL;
	
	if (vre_running == FALSE)
	       return;

	* 获取current_handle 对应的资源 *
	ret = vm_res_get_data(VM_RES_TYPE_HTTP_HANDLE, current_handle, (void **)&xml_struct, &res_size);
	if (VM_RES_OK != ret)
	{
		vm_log_error("[XML MODULE] xml_doctype_end_handler - vm_res_get_data failed, "
			"ret:%d, current_handle:%d.", current_handle);
	       return;
	}

	xml_struct->vm_parser->end_doctype_hdlr(data, error);
*/

	VMCHAR tmp[XML_MAX_STR_LEN];
	
	memset(tmp, 0, XML_MAX_STR_LEN);

	if (XML_NO_ERROR != error)
	{
		vm_log_error("[XML MODULE] xml_doctype_end_handler -Error:%s ", xml_get_err_string(&mtk_xml_parser));
		return;
	}
	else
	{
		sprintf(tmp, "DOCTYPE_End: %s\n", data);
		vm_log_debug("[XML MODULE] xml_doctype_end_handler - XML:%s", tmp);
	}
}

/*
 * Default element start handler. log the basic data in XML.
 */
static void xml_elem_start_handler( void *data, 
									const VMCHAR *el, 
									const VMCHAR **attr, 
									VMINT error)
{
/*
	int ret = -1;
	VMINT res_size = 0;
	vm_xml_struct * xml_struct = NULL;
	
	if (vre_running == FALSE)
	       return;

	* 获取current_handle 对应的资源 *
	ret = vm_res_get_data(VM_RES_TYPE_HTTP_HANDLE, current_handle, (void **)&xml_struct, &res_size);
	if (VM_RES_OK != ret)
	{
		vm_log_error("[XML MODULE] xml_elem_start_handler - vm_res_get_data failed, "
			"ret:%d, current_handle:%d.", current_handle);
	       return;
	}

	xml_struct->vm_parser->start_elem_hdlr(data, el, attr, error);
*/

	VMINT   index = 0;
	VMCHAR tmp[XML_MAX_STR_LEN];

	memset(tmp, 0, XML_MAX_STR_LEN);

	if (XML_NO_ERROR != error)
	{
		vm_log_error("[XML MODULE] xml_elem_start_handler - el:%s, Error:%s", 
					el, xml_get_err_string(&mtk_xml_parser));
		return;
	}
	else
	{
		strcat(tmp, "Element:");
		strcat(tmp, el);
		strcat(tmp, " Attributes:");
        
		while ((NULL != attr[index]) && (NULL != attr[index + 1]))
		{
			strcat(tmp, attr[index]);
			strcat(tmp, " = ");
			strcat(tmp, attr[index+1]);
			strcat(tmp, "; ");

			index += 2;
		}
		strcat(tmp, "#END");
		strcat(tmp, "\r\n");
		vm_log_debug("[XML MODULE] xml_elem_start_handler - XML:%s", tmp);
	}
}

/*
 * Default element end handler. log the basic data in XML.
 */
static void xml_elem_end_handler(void *data, const VMCHAR *el, VMINT error)
{
/*	
	int ret = -1;
	VMINT res_size = 0;
	vm_xml_struct * xml_struct = NULL;
	
	if (vre_running == FALSE)
	       return;

	* 获取current_handle 对应的资源 *
	ret = vm_res_get_data(VM_RES_TYPE_HTTP_HANDLE, current_handle, (void **)&xml_struct, &res_size);
	if (VM_RES_OK != ret)
	{
		vm_log_error("[XML MODULE] xml_elem_end_handler - vm_res_get_data failed, "
			"ret:%d, current_handle:%d.", current_handle);
	       return;
	}

	xml_struct->vm_parser->end_elem_hdlr(data, el, error);
*/

	VMCHAR tmp[XML_MAX_STR_LEN];
	
	memset(tmp, 0, XML_MAX_STR_LEN);
	
	if (XML_NO_ERROR != error)
	{
		vm_log_error("[XML MODULE] xml_elem_end_handler - el:%s, Error:%s", el, xml_get_err_string(&mtk_xml_parser));
		return;
	}
	else
	{
		sprintf(tmp, "Element:%s\n", el);
		vm_log_debug("[XML MODULE] xml_elem_end_handler - XML:%s", tmp);
	}
}

/*
 * Default element data handler. log the basic data in XML.
 */
static void xml_data_handler(
							void *resv, 
							const VMCHAR *el, 
							const VMCHAR *data, 
							VMINT len, 
							VMINT error)
{
/*
	int ret = -1;
	VMINT res_size = 0;
	vm_xml_struct * xml_struct = NULL;
	
	if (vre_running == FALSE)
	       return;

	* 获取current_handle 对应的资源 *
	ret = vm_res_get_data(VM_RES_TYPE_HTTP_HANDLE, current_handle, (void **)&xml_struct, &res_size);
	if (VM_RES_OK != ret)
	{
		vm_log_error("[XML MODULE] xml_data_handler - vm_res_get_data failed, "
			"ret:%d, current_handle:%d.", current_handle);
	       return;
	}

	xml_struct->vm_parser->data_hdlr(resv, el, data, len, error);
*/

	VMCHAR tmp[XML_MAX_STR_LEN];

	memset(tmp, 0, XML_MAX_STR_LEN);

	if (XML_NO_ERROR != error)
	{
		vm_log_error("[XML MODULE] xml_data_handler - el:%s, Error:%s", el, xml_get_err_string(&mtk_xml_parser));
		return;
	}
	else
	{
		sprintf(tmp, "Element:%s; Data:%s\n", el, data);
		vm_log_debug("[XML MODULE] xml_data_handler - XML:%s", tmp);
	}
}


/**********************************************************************/
/** Main APIs */
VMINT vm_xml_new_parser(VM_XML_PARSER_STRUCT *parser)
{
#if defined(__VRE_RB_08A__) || defined(__VRE_RB_08B__) /*Version control*/
	int ret = VA_XML_RESULT_FAIL;
#else /*Version control*/
	int ret = XML_RESULT_FAIL;
#endif /*Version control*/
	
	if (NULL != parser)
	{
		parser->start_doctype_hdlr = xml_doctype_start_handler;
		parser->end_doctype_hdlr = xml_doctype_end_handler;
		parser->start_elem_hdlr = xml_elem_start_handler;
		parser->end_elem_hdlr = xml_elem_end_handler;
		parser->data_hdlr = xml_data_handler;
		
#if defined(__VRE_RB_08A__) || defined(__VRE_RB_08B__) /*Version control*/
		ret = VA_XML_RESULT_OK;
#else /*Version control*/
		ret = XML_RESULT_OK;
#endif /*Version control*/
	}
	else
	{
		vm_log_error("[XML MODULE] vm_xml_new_parser - parser is null");
	}
	return ret;
}
void vm_xml_set_doctype_handlers(
	VM_XML_PARSER_STRUCT *parser,
	XML_start_doctype_hdlr start_hdlr,
	XML_end_doctype_hdlr end_hdlr)
{
	if (NULL != parser)
	{
		parser->start_doctype_hdlr = (NULL==start_hdlr) ? xml_doctype_start_handler : start_hdlr;
		parser->end_doctype_hdlr = (NULL==end_hdlr) ? xml_doctype_end_handler : end_hdlr;
	}
	else
	{
		vm_log_error("[XML MODULE] vm_xml_set_doctype_handlers - parser is null");
	}
       //xml_register_doctype_handler(mtk_xml_parser , start_hdlr, end_hdlr);
}
void vm_xml_set_element_handlers(
	VM_XML_PARSER_STRUCT *parser,
	XML_start_elem_hdlr start_hdlr,
	XML_end_elem_hdlr end_hdlr)
{
	if (NULL != parser)
	{
		parser->start_elem_hdlr = (NULL==start_hdlr) ? xml_elem_start_handler : start_hdlr;
		parser->end_elem_hdlr = (NULL==end_hdlr) ? xml_elem_end_handler : end_hdlr;
	}
	else
	{
		vm_log_error("[XML MODULE] vm_xml_set_element_handlers - parser is null");
	}
       //xml_register_element_handler(mtk_xml_parser , start_hdlr, end_hdlr);
}
/*
void vm_xml_set_element_handler(
	VM_XML_PARSER_STRUCT *parser,
	XML_elem_hdlr elem_hdlr)
{
	if (NULL != parser)
	{
		//parser->elem_hdlr = (NULL==elem_hdlr) ? NULL : elem_hdlr;
	}
}*/
void vm_xml_set_data_handler(
	VM_XML_PARSER_STRUCT *parser, 
	XML_data_hdlr data_hdlr)
{
	if (NULL != parser)
	{
		parser->data_hdlr = (NULL==data_hdlr) ? xml_data_handler : data_hdlr;
	}
	else
	{
		vm_log_error("[XML MODULE] vm_xml_set_data_handler - parser is null");
	}
       //xml_register_data_handler(mtk_xml_parser , data_hdlr);
}

#if defined(__VRE_RB_08A__) || defined(__VRE_RB_08B__) /*Version control*/
VMINT vm_xml_parse(
	VM_XML_PARSER_STRUCT *parser,
	const VMCHAR *xmlsource,
	VMINT length)
{
	int ret = VM_XML_RESULT_FAIL;

/*Code segment supporting MIBR

	VMINT p_handle = -1;
	VMINT res_handle = -1;
	VMINT res_size = 0;
	vm_xml_struct * xml_struct = NULL;

	xml_struct = (vm_xml_struct *)vm_malloc(sizeof(vm_xml_struct));
	if (NULL == xml_struct)
	{
		vm_log_error("[XML MODULE] vm_xml_fetch_handle - vm_malloc for xml_struct - failed . "
			"res_handle:%d, current_handle:%d .", res_handle, current_handle);
		return -1;
	}
	xml_struct->vm_parser = parser;
	xml_struct->mtk_parser = (XML_PARSER_STRUCT *)vm_malloc(sizeof(XML_PARSER_STRUCT));
	if (NULL == xml_struct->mtk_parser)
	{
		vm_log_error("[XML MODULE] vm_xml_fetch_handle - vm_malloc for mtk_parser - failed . "
			"res_handle:%d, current_handle:%d .", res_handle, current_handle);
		vm_free(xml_struct);
		return -1;
	}

	p_handle = vm_pmng_get_current_handle();
	
	res_handle = vm_res_save_data(VM_RES_TYPE_HTTP_HANDLE, (void *)xml_struct, res_size, NULL, p_handle);
	if (res_handle < 0)
	{
	
		vm_log_error("[XML MODULE] vm_xml_fetch_handle - vm_res_save_data - failed . "
			"res_handle:%d, p_handle:%d, current_handle:%d .", res_handle, p_handle, current_handle);
		vm_free(xml_struct->mtk_parser);
		vm_free(xml_struct);
		return -1;
	}
	current_handle = res_handle;
*/
	ret = va_xml_new_parser(&mtk_xml_parser);
	//ret = xml_new_parser(xml_struct->mtk_parser);
	if (VA_XML_RESULT_OK != ret)
	{
		/* get XML parser error string */
		//parser->error_str = xml_get_err_string(&mtk_xml_parser );
		vm_log_error("[XML MODULE] vm_xml_parse - xml_new_parser() is not XML_RESULT_OK - ret:%d", ret);
		va_xml_close_parser(&mtk_xml_parser);
		//xml_close_parser(xml_struct->mtk_parser);
		//vm_free(xml_struct->mtk_parser);
		//vm_free(xml_struct);
		return -1;
	}
	vm_log_debug("[XML MODULE] vm_xml_parse - after xml_new_parser - length:%d .", length);
	
	va_xml_configure_memory(&mtk_xml_parser, vm_malloc, vm_free);
	//xml_configure_memory(xml_struct->mtk_parser, vm_malloc, vm_free);
	vm_log_debug("[XML MODULE] vm_xml_parse - after xml_configure_memory - length:%d .", length);
		
       va_xml_register_doctype_handler(
	   	//xml_struct->mtk_parser, 
	   	//xml_doctype_start_handler, 
	   	//xml_doctype_end_handler);
	   	&mtk_xml_parser, 
	   	parser->start_doctype_hdlr, 
	   	parser->end_doctype_hdlr);
	vm_log_debug("[XML MODULE] vm_xml_parse - after xml_register_doctype_handler - length:%d .", length);
	   
       va_xml_register_element_handler(
	   	//xml_struct->mtk_parser, 
	   	//xml_elem_start_handler, 
	   	//xml_elem_end_handler);
	   	&mtk_xml_parser, 
	   	parser->start_elem_hdlr, 
	   	parser->end_elem_hdlr);
	vm_log_debug("[XML MODULE] vm_xml_parse - after xml_register_element_handler - length:%d .", length);
	   
       va_xml_register_data_handler(
	   	//xml_struct->mtk_parser, 
	   	//xml_data_handler);
	   	&mtk_xml_parser, 
	   	parser->data_hdlr);
	vm_log_debug("[XML MODULE] vm_xml_parse - after xml_register_data_handler - length:%d .", length);
	   
	if(0 == length)
	{
		vm_log_debug("[XML MODULE] vm_xml_parse - to parse file - %s", xmlsource);
		/* XML Parser start from file */
		ret = va_xml_parse(&mtk_xml_parser, (VMUWSTR)vm_ucs2_string((VMSTR)xmlsource));
		//ret = xml_parse(xml_struct->mtk_parser, (VMUWSTR)vm_ucs2_string((VMSTR)xmlsource));
		vm_log_debug("[XML MODULE] vm_xml_parse - after xml_parse - length:%d .", length);
	}
	else
	{
		vm_log_debug("[XML MODULE] vm_xml_parse - to parse buffer - %p, %d", xmlsource, length);
		/* XML Parser start from buffer */
		ret = va_xml_parse_buffer(&mtk_xml_parser, xmlsource, length);
		//ret = xml_parse_buffer(xml_struct->mtk_parser, xmlsource, length);
		vm_log_debug("[XML MODULE] vm_xml_parse - after xml_parse_buffer - length:%d .", length);
	}

	va_xml_close_parser(&mtk_xml_parser);
	//xml_close_parser(xml_struct->mtk_parser);
	vm_log_debug("[XML MODULE] vm_xml_parse - after xml_close_parser - length:%d .", length);

	if (VA_XML_RESULT_OK!= ret)
	{
		/* get XML parser error string */
		vm_log_error("[XML MODULE] vm_xml_parse - parse result is not XML_RESULT_OK - ret:%d, Error:%s", 
					ret, va_xml_get_err_string(&mtk_xml_parser));
					//ret, xml_get_err_string(xml_struct->mtk_parser));
 		return -1;
	}

/*Code segment supporting MIBR
	current_handle = -1;
	vm_free(xml_struct->mtk_parser);
	vm_free(xml_struct);
	ret = vm_res_release_data(VM_RES_TYPE_HTTP_HANDLE, res_handle);
	if (VM_RES_OK != ret)
	{
		vm_log_error("[XML MODULE] vm_xml_free_handle - vm_res_release_data - failed - "
			"ret:%d, res_handle:%d, current_handle:%d .", ret, res_handle, current_handle);
		return -1;
	}
*/
	return VM_XML_RESULT_OK;
}

#else /*Version control*/
VMINT vm_xml_parse(
	VM_XML_PARSER_STRUCT *parser,
	const VMCHAR *xmlsource,
	VMINT length)
{
	int ret = VM_XML_RESULT_FAIL;

/*Code segment supporting MIBR

	VMINT p_handle = -1;
	VMINT res_handle = -1;
	VMINT res_size = 0;
	vm_xml_struct * xml_struct = NULL;

	xml_struct = (vm_xml_struct *)vm_malloc(sizeof(vm_xml_struct));
	if (NULL == xml_struct)
	{
		vm_log_error("[XML MODULE] vm_xml_fetch_handle - vm_malloc for xml_struct - failed . "
			"res_handle:%d, current_handle:%d .", res_handle, current_handle);
		return -1;
	}
	xml_struct->vm_parser = parser;
	xml_struct->mtk_parser = (XML_PARSER_STRUCT *)vm_malloc(sizeof(XML_PARSER_STRUCT));
	if (NULL == xml_struct->mtk_parser)
	{
		vm_log_error("[XML MODULE] vm_xml_fetch_handle - vm_malloc for mtk_parser - failed . "
			"res_handle:%d, current_handle:%d .", res_handle, current_handle);
		vm_free(xml_struct);
		return -1;
	}

	p_handle = vm_pmng_get_current_handle();
	
	res_handle = vm_res_save_data(VM_RES_TYPE_HTTP_HANDLE, (void *)xml_struct, res_size, NULL, p_handle);
	if (res_handle < 0)
	{
	
		vm_log_error("[XML MODULE] vm_xml_fetch_handle - vm_res_save_data - failed . "
			"res_handle:%d, p_handle:%d, current_handle:%d .", res_handle, p_handle, current_handle);
		vm_free(xml_struct->mtk_parser);
		vm_free(xml_struct);
		return -1;
	}
	current_handle = res_handle;
*/
	ret = xml_new_parser(&mtk_xml_parser);
	//ret = xml_new_parser(xml_struct->mtk_parser);
	if (XML_RESULT_OK != ret)
	{
		/* get XML parser error string */
		//parser->error_str = xml_get_err_string(&mtk_xml_parser );
		vm_log_error("[XML MODULE] vm_xml_parse - xml_new_parser() is not XML_RESULT_OK - ret:%d", ret);
		xml_close_parser(&mtk_xml_parser);
		//xml_close_parser(xml_struct->mtk_parser);
		//vm_free(xml_struct->mtk_parser);
		//vm_free(xml_struct);
		return -1;
	}
	vm_log_debug("[XML MODULE] vm_xml_parse - after xml_new_parser - length:%d .", length);
	
	xml_configure_memory(&mtk_xml_parser, vm_malloc, vm_free);
	//xml_configure_memory(xml_struct->mtk_parser, vm_malloc, vm_free);
	vm_log_debug("[XML MODULE] vm_xml_parse - after xml_configure_memory - length:%d .", length);
		
       xml_register_doctype_handler(
	   	//xml_struct->mtk_parser, 
	   	//xml_doctype_start_handler, 
	   	//xml_doctype_end_handler);
	   	&mtk_xml_parser, 
	   	parser->start_doctype_hdlr, 
	   	parser->end_doctype_hdlr);
	vm_log_debug("[XML MODULE] vm_xml_parse - after xml_register_doctype_handler - length:%d .", length);
	   
       xml_register_element_handler(
	   	//xml_struct->mtk_parser, 
	   	//xml_elem_start_handler, 
	   	//xml_elem_end_handler);
	   	&mtk_xml_parser, 
	   	parser->start_elem_hdlr, 
	   	parser->end_elem_hdlr);
	vm_log_debug("[XML MODULE] vm_xml_parse - after xml_register_element_handler - length:%d .", length);
	   
       xml_register_data_handler(
	   	//xml_struct->mtk_parser, 
	   	//xml_data_handler);
	   	&mtk_xml_parser, 
	   	parser->data_hdlr);
	vm_log_debug("[XML MODULE] vm_xml_parse - after xml_register_data_handler - length:%d .", length);
	   
	if(0 == length)
	{
		vm_log_debug("[XML MODULE] vm_xml_parse - to parse file - %s", xmlsource);
		/* XML Parser start from file */
		ret = xml_parse(&mtk_xml_parser, (VMUWSTR)vm_ucs2_string((VMSTR)xmlsource));
		//ret = xml_parse(xml_struct->mtk_parser, (VMUWSTR)vm_ucs2_string((VMSTR)xmlsource));
		vm_log_debug("[XML MODULE] vm_xml_parse - after xml_parse - length:%d .", length);
	}
	else
	{
		vm_log_debug("[XML MODULE] vm_xml_parse - to parse buffer - %p, %d", xmlsource, length);
		/* XML Parser start from buffer */
		ret = xml_parse_buffer(&mtk_xml_parser, xmlsource, length);
		//ret = xml_parse_buffer(xml_struct->mtk_parser, xmlsource, length);
		vm_log_debug("[XML MODULE] vm_xml_parse - after xml_parse_buffer - length:%d .", length);
	}

	xml_close_parser(&mtk_xml_parser);
	//xml_close_parser(xml_struct->mtk_parser);
	vm_log_debug("[XML MODULE] vm_xml_parse - after xml_close_parser - length:%d .", length);

	if (XML_RESULT_OK!= ret)
	{
		/* get XML parser error string */
		vm_log_error("[XML MODULE] vm_xml_parse - parse result is not XML_RESULT_OK - ret:%d, Error:%s", 
					ret, xml_get_err_string(&mtk_xml_parser));
					//ret, xml_get_err_string(xml_struct->mtk_parser));
 		return -1;
	}

/*Code segment supporting MIBR
	current_handle = -1;
	vm_free(xml_struct->mtk_parser);
	vm_free(xml_struct);
	ret = vm_res_release_data(VM_RES_TYPE_HTTP_HANDLE, res_handle);
	if (VM_RES_OK != ret)
	{
		vm_log_error("[XML MODULE] vm_xml_free_handle - vm_res_release_data - failed - "
			"ret:%d, res_handle:%d, current_handle:%d .", ret, res_handle, current_handle);
		return -1;
	}
*/
	return VM_XML_RESULT_OK;
}

#endif /*Version control*/
/*
void vm_xml_reset_parser(VM_XML_PARSER_STRUCT *parser)
{}
void vm_xml_delete_parser(VM_XML_PARSER_STRUCT *parser)
{}
*/
VMCHAR* vm_xml_get_error()
{
#if defined(__VRE_RB_08A__) || defined(__VRE_RB_08B__) /*Version control*/
	return va_xml_get_err_string(&mtk_xml_parser);
#else /*Version control*/
	return xml_get_err_string(&mtk_xml_parser);
#endif /*Version control*/
	/*
	if (NULL != parser)
	{
		return parser->error_str;
	}*/
}

/**********************************************************************/
/** XML APIs supporting MIBR  2009-12-01 *

VMINT vm_xml_fetch_handle()
{
	VMINT p_handle = -1;
	VMINT res_handle = -1;
	VMINT res_size = 0;
	vm_xml_struct * xml_struct = NULL;

	xml_struct = (vm_xml_struct *)vm_malloc(sizeof(vm_xml_struct));
	if (NULL == xml_struct)
	{
		vm_log_error("[XML MODULE] vm_xml_fetch_handle - vm_malloc for xml_struct - failed . "
			"res_handle:%d, current_handle:%d .", res_handle, current_handle);
		return -1;
	}
	xml_struct->vm_parser = (VM_XML_PARSER_STRUCT *)vm_malloc(sizeof(VM_XML_PARSER_STRUCT));
	if (NULL == xml_struct->vm_parser)
	{
		vm_log_error("[XML MODULE] vm_xml_fetch_handle - vm_malloc for vm_parser - failed . "
			"res_handle:%d, current_handle:%d .", res_handle, current_handle);
		vm_free(xml_struct);
		return -1;
	}
	xml_struct->mtk_parser = (XML_PARSER_STRUCT *)vm_malloc(sizeof(XML_PARSER_STRUCT));
	if (NULL == xml_struct->mtk_parser)
	{
		vm_log_error("[XML MODULE] vm_xml_fetch_handle - vm_malloc for mtk_parser - failed . "
			"res_handle:%d, current_handle:%d .", res_handle, current_handle);
		vm_free(xml_struct->vm_parser);
		vm_free(xml_struct);
		return -1;
	}
	
	* 取当前进程句柄 *
	p_handle = vm_pmng_get_current_handle();
	
 	 * 保存HTTP 资源*
	res_handle = vm_res_save_data(VM_RES_TYPE_HTTP_HANDLE, (void *)xml_struct, res_size, NULL, p_handle);
	if (res_handle < 0)
	{
	* 保存资源失败 *
	
		vm_log_error("[XML MODULE] vm_xml_fetch_handle - vm_res_save_data - failed . "
			"res_handle:%d, p_handle:%d, current_handle:%d .", res_handle, p_handle, current_handle);
		vm_free(xml_struct->mtk_parser);
		vm_free(xml_struct->vm_parser);
		vm_free(xml_struct);
		return -1;
	}
	
	return res_handle;
}

VMINT vm_xml_reg_doctype_handlers(VMINT handle, 
	XML_start_doctype_hdlr start_hdlr,
	XML_end_doctype_hdlr end_hdlr)
{
	VMINT ret = -1;
	VMINT res_size = 0;
	vm_xml_struct * xml_struct = NULL;

	ret = vm_res_get_data(VM_RES_TYPE_HTTP_HANDLE, handle, (void **)&xml_struct, &res_size);
	if (VM_RES_OK != ret)
	{
		vm_log_error("[XML MODULE] vm_xml_reg_doctype_handlers - vm_res_get_data - failed . "
			"handle:%d, current_handle:%d .", handle, current_handle);
		return -1;
	}
	xml_struct->vm_parser->start_doctype_hdlr = start_hdlr;
	xml_struct->vm_parser->end_doctype_hdlr = end_hdlr;
	return 0;
}

VMINT vm_xml_reg_element_handlers(VMINT handle, 
	XML_start_elem_hdlr start_hdlr,
	XML_end_elem_hdlr end_hdlr)
{
	VMINT ret = -1;
	VMINT res_size = 0;
	vm_xml_struct * xml_struct = NULL;

	ret = vm_res_get_data(VM_RES_TYPE_HTTP_HANDLE, handle, (void **)&xml_struct, &res_size);
	if (VM_RES_OK != ret)
	{
		vm_log_error("[XML MODULE] vm_xml_reg_element_handlers - vm_res_get_data - failed . "
			"handle:%d, current_handle:%d .", handle, current_handle);
		return -1;
	}
	xml_struct->vm_parser->start_elem_hdlr = start_hdlr;
	xml_struct->vm_parser->end_elem_hdlr = end_hdlr;
	return 0;
}

VMINT vm_xml_reg_data_handler(VMINT handle, 
	XML_data_hdlr data_hdlr)
{
	VMINT ret = -1;
	VMINT res_size = 0;
	vm_xml_struct * xml_struct = NULL;

	ret = vm_res_get_data(VM_RES_TYPE_HTTP_HANDLE, handle, (void **)&xml_struct, &res_size);
	if (VM_RES_OK != ret)
	{
		vm_log_error("[XML MODULE] vm_xml_reg_data_handler - vm_res_get_data - failed . "
			"handle:%d, current_handle:%d .", handle, current_handle);
		return -1;
	}
	xml_struct->vm_parser->data_hdlr = data_hdlr;
	return 0;
}

VMINT vm_xml_do_parse(VMINT handle,
 	const VMCHAR *xmlsource,
	VMINT length)
{
	int ret = VM_XML_RESULT_FAIL;
	VMINT res_size = 0;
	vm_xml_struct * xml_struct = NULL;
	
	ret = vm_res_get_data(VM_RES_TYPE_HTTP_HANDLE, handle, (void **)&xml_struct, &res_size);
	if (VM_RES_OK != ret)
	{
		vm_log_error("[XML MODULE] vm_xml_parse_handle - vm_res_get_data - failed . "
			"handle:%d, current_handle:%d .", handle, current_handle);
		return ret;
	}
	
 	ret = xml_new_parser(xml_struct->mtk_parser);
	if (VM_XML_RESULT_OK != ret)
	{
		vm_log_error("[XML MODULE] vm_xml_parse - xml_new_parser - failed - "
			"ret:%d, handle:%d, current_handle:%d .", ret, handle, current_handle);
		xml_close_parser(xml_struct->mtk_parser);
		vm_xml_free_handle(handle);
		return ret;
	}
	
	xml_configure_memory(xml_struct->mtk_parser , vm_malloc, vm_free);
		
       xml_register_doctype_handler(
	   	xml_struct->mtk_parser , 
	   	xml_doctype_start_handler, 
	   	xml_doctype_end_handler);
 	   
       xml_register_element_handler(
	   	xml_struct->mtk_parser , 
	   	xml_elem_start_handler, 
	   	xml_elem_end_handler);
	   
       xml_register_data_handler(xml_struct->mtk_parser , xml_data_handler);

	current_handle = handle;
	if(0 == length)
	{
		vm_log_debug("[XML MODULE] vm_xml_parse - to parse file - xmlsource:%s", xmlsource);
		* XML Parser start from file *
		ret = xml_parse(xml_struct->mtk_parser , (VMUWSTR)vm_ucs2_string((VMSTR)xmlsource));
	}
	else
	{
		vm_log_debug("[XML MODULE] vm_xml_parse - to parse buffer - length:%d", length);
		* XML Parser start from buffer *
		ret = xml_parse_buffer(xml_struct->mtk_parser , xmlsource, length);
	}
	current_handle = -1;

	xml_close_parser(xml_struct->mtk_parser );

	if (VM_XML_RESULT_OK != ret)
	{
		* get XML parser error string *
		//parser->error_str = xml_get_err_string(&mtk_xml_parser );
		vm_log_error("[XML MODULE] vm_xml_parse - parse result is not XML_RESULT_OK - "
			"ret:%d, Error:%s", ret, xml_get_err_string(xml_struct->mtk_parser ));
 		vm_xml_free_handle(handle);
		return ret;
	}

	return ret;
}

VMINT vm_xml_free_handle(VMINT handle)
{
	VMINT ret = -1;
	VMINT res_size = 0;
	vm_xml_struct * xml_struct = NULL;

	current_handle = -1;
	ret = vm_res_get_data(VM_RES_TYPE_HTTP_HANDLE, handle, (void **)&xml_struct, &res_size);
	if (VM_RES_OK != ret)
	{
		vm_log_error("[XML MODULE] vm_xml_free_handle - vm_res_get_data - failed . "
			"ret:%d, handle:%d, current_handle:%d .", ret, handle, current_handle);
		return -1;
	}
	
	if (xml_struct->mtk_parser)
	{
		vm_free(xml_struct->mtk_parser);
		vm_log_debug("[XML MODULE] vm_xml_free_handle - vm_free mtk_xml_parser done - "
			"ret:%d, handle:%d, current_handle:%d .", ret, handle, current_handle);
	}
	if (xml_struct->vm_parser)
	{
		vm_free(xml_struct->vm_parser);
		vm_log_debug("[XML MODULE] vm_xml_free_handle - vm_free vm_xml_parser done - "
			"ret:%d, handle:%d, current_handle:%d .", ret, handle, current_handle);
	}
	if (xml_struct)
	{
		vm_free(xml_struct);
		vm_log_debug("[XML MODULE] vm_xml_free_handle - vm_free xml_struct done - "
			"ret:%d, handle:%d, current_handle:%d .", ret, handle, current_handle);
	}

	ret = vm_res_release_data(VM_RES_TYPE_HTTP_HANDLE, handle);
	if (VM_RES_OK != ret)
	{
		vm_log_error("[XML MODULE] vm_xml_free_handle - vm_res_release_data - failed - "
			"ret:%d, handle:%d, current_handle:%d .", ret, handle, current_handle);
		return -1;
	}
	
	return 0;
}

VMCHAR* vm_xml_get_last_error()
{
	int ret = -1;
	VMINT res_size = 0;
	vm_xml_struct * xml_struct = NULL;
	
	* 获取current_handle 对应的资源 *
	ret = vm_res_get_data(VM_RES_TYPE_HTTP_HANDLE, current_handle, (void **)&xml_struct, &res_size);
	if (VM_RES_OK != ret)
	{
		vm_log_error("[XML MODULE] xml_doctype_start_handler - vm_res_get_data failed, "
			"ret:%d, current_handle:%d.", current_handle);
	       return NULL;
	}
	
	return xml_get_err_string(xml_struct->mtk_parser);
}
*/
#endif	/*__XML_SUPPORT__*/
#endif	/*__VRE__*/
