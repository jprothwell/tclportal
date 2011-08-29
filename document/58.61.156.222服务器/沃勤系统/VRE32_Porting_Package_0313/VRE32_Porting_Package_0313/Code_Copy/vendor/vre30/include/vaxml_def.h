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

/*******************************************************************************
 * Filename:
 * ---------
 * vaxml_def.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *******************************************************************************/

#ifndef __XML_DEF_H__
#define __XML_DEF_H__

/********************************************************************/
/* declaration */
/********************************************************************/
#include "kal_release.h"
#include "Fs_type.h"

/* DOM-NOT_FOR_SDK-BEGIN */
#define VA_XML_TAG_PROLOG_START        "<?xml"
#define VA_XML_TAG_PROLOG_END          "?>"
#define VA_XML_TAG_DOCTYPE_START       "<!DOCTYPE"
#define VA_XML_TAG_ELEMENTTYPE_START   "<!ELEMENT"
#define VA_XML_TAG_ATTLISTTYPE_START   "<!ATTLIST"
#define VA_XML_TAG_ENTITYTYPE_START    "<!ENTITY"
#define VA_XML_TAG_NOTATIONTYPE_START  "<!NOTATION"
#define VA_XML_TAG_COMMENT_START       "<!--"
#define VA_XML_TAG_COMMENT_END         "-->"
#define VA_XML_TAG_CDATA_START         "<![CDATA["
#define VA_XML_TAG_CDATA_END           "]]>"
#define VA_XML_TAG_PI_START            "<?"
#define VA_XML_TAG_ENCODING            "encoding"
#define VA_XML_TAG_ENCODING_UTF8       "utf-8"
#define VA_XML_TAG_ENCODING_UTF16      "utf-16"
#define VA_XML_TAG_ENCODING_UCS2       "iso-10646-ucs-2"
#define VA_XML_TAG_ENCODING_UCS4       "iso-10646-ucs-4"
#define VA_XML_TAG_ENCODING_ASCII      "iso-8859-1"

#define VA_XML_TAG_ELEMENT_START       "<"
#define VA_XML_TAG_ELEMENT_END         "</"
#define VA_XML_TAG_SINGLE_END          "/>"
#define VA_XML_TAG_GENERAL_END         ">"
#define VA_XML_SPACE                   " "
#define VA_XML_QUOTE                   "'"
#define VA_XML_DOUBLE_QUOTE            "\""
#define VA_XML_SQUARE_LEFT_BRAKET      "["
#define VA_XML_SQUARE_RIGHT_BRAKET     "]"


/* Leo add for DLT */
/*****************************************
Note: DLT needs more buffer length.
If anyone needs to use these two macro,
   please include "MMI_features.h" before
   vaxml_def.h.
*****************************************/
#if defined (__MMI_DOWNLOADABLE_THEMES_SUPPORT__) || defined (SVG_SUPPORT)
#define VA_XML_BUFFER_LENGTH        (512)
#define VA_XML_MAX_ATTR_COUNT       (100)
#else /* defined (__MMI_DOWNLOADABLE_THEMES_SUPPORT__) || defined (__SVG_SUPPORT__) */ 
#define VA_XML_BUFFER_LENGTH        (128)
#define VA_XML_MAX_ATTR_COUNT       (30)
#endif /* defined (__MMI_DOWNLOADABLE_THEMES_SUPPORT__) || defined (__SVG_SUPPORT__) */ 

#define VA_MAX_CTRL_BUFFER_SIZE    (2048)
#define VA_XML_MAX_ENTITY_COUNT    (10)
#define VA_XML_MAX_ELEM_DEPTH      (20)
#define VA_XML_CHAR_ENTITY_LENGTH  (15)

#define VA_MAX_FILEBUF_NUM     (2)
#define VA_FILEBUF_SIZE        (5*1024)
#define VA_FILEBUF_BACKSIZE    (2*1024)
#define VA_XML_VIRFILE_MIN     (4*1024)
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  VA_XML_start_elem_hdlr
 * DESCRIPTION
 *  this function is element start handler.
 * PARAMETERS
 *  data:        [IN]        reserved
 *  el:          [IN]        Element name
 *  attr:        [IN]        Attribution list
 *  error:       [IN]        error code
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*VA_XML_start_elem_hdlr) (
                void *data,
                const kal_char *el,
                const kal_char **attr,
                kal_int32 error);


/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  VA_XML_end_elem_hdlr
 * DESCRIPTION
 *  this function is element end handler.
 * PARAMETERS
 *  data:        [IN]        reserved
 *  el:          [IN]        Element name
 *  error:       [IN]        error code
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*VA_XML_end_elem_hdlr) (void *data, const kal_char *el, kal_int32 error);


/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  VA_XML_start_doctype_hdlr
 * DESCRIPTION
 *  this function is document type start handler.
 * PARAMETERS
 *  data:            [IN]        reserved
 *  doctypeName:     [IN]        document type name
 *  sysid:           [IN]        system id
 *  pubid:           [IN]        public id
 *  internal_subset: [IN]        internal subset
 *  error:           [IN]        error code
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*VA_XML_start_doctype_hdlr) (
                void *data,
                const kal_char *doctypeName,
                const kal_char **sysid, 
                const kal_char **pubid,
                kal_int32 internal_subset,
                kal_int32 error);


/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  VA_XML_end_doctype_hdlr
 * DESCRIPTION
 *  this function is used to handle document type.
 * PARAMETERS
 *  data:            [IN]        reserved
 *  error:           [IN]        error code
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*VA_XML_end_doctype_hdlr) (void *data, kal_int32 error);


/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  VA_XML_data_hdlr
 * DESCRIPTION
 *  this function is used to handle data.
 * PARAMETERS
 *  resv:            [IN]        reserved
 *  el:              [IN]        element name
 *  data:            [IN]        data
 *  len:             [IN]        length
 *  error:           [IN]        error code
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*VA_XML_data_hdlr) (
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);


/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  VA_XML_malloc_buffer_ptr
 * DESCRIPTION
 *  this function is used to malloc buffer.
 * PARAMETERS
 *  len:           [IN]        length
 * RETURNS
 *  void
 *****************************************************************************/
typedef void *(*VA_XML_malloc_buffer_ptr) (kal_int32 len);


/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  VA_XML_free_buffer_ptr
 * DESCRIPTION
 *  this function is used to free buffer.
 * PARAMETERS
 *  ptr:           [IN]        buffer pointer
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*VA_XML_free_buffer_ptr) (void *ptr);


/* define the error code */
typedef enum
{
    VA_XML_RESULT_FILE_NOT_FOUND = -4, /* the file isn't found */
    VA_XML_RESULT_OUT_OF_MEMORY = -3,  /* the memory isn't enough*/
    VA_XML_RESULT_ENCODING_ERROR = -2, /* the char encoding error */
    VA_XML_RESULT_FAIL = -1,           /* fail to parse xml */
    VA_XML_RESULT_OK = 0               /* parsing xml succed */
} VA_XML_RESULT_ENUM;

/* define the error code */
typedef enum
{
    VA_XML_NO_ERROR,                               /* no error */
    VA_XML_ERROR_MISMATCH_TAG,                     /* error string: end tag name */
    VA_XML_ERROR_MISMATCH_DOCTYPENAME_ROOTNAME,    /* error string : root element name */
    VA_XML_ERROR_INVALID_ATTRIBUTE,                /* error string : attribute name */
    VA_XML_ERROR_DUPLICATE_ATTRIBUTE,              /* error string : attribute name */
    VA_XML_ERROR_ENTITY_DEFINITION,                /* error string: entity name */
    VA_XML_ERROR_UNDEFINED_ENTITY                  /* error string : entity name */
}va_xml_error_enum;

/* define the pending type */
typedef enum
{
    VA_XML_PENDING_NONE,           /* no pending content */
    VA_XML_PENDING_PROLOG,         /* the prolog is pending */
    VA_XML_PENDING_DOCTYPE,        /* the document type decare is pending */
    VA_XML_PENDING_DOCTYPE_MARKUP, /* the doctype markup is pending */
    VA_XML_PENDING_COMMENT,        /* the comment is pending */
    VA_XML_PENDING_PI,             /* the pi is pending */
    VA_XML_PENDING_CDATA,          /* the cdata is pending */
    VA_XML_PENDING_START_ELEMENT,  /* the start element is pending */
    VA_XML_PENDING_END_ELEMENT     /* the end element is pending */
} VA_XML_PENDING_ENTITY_TYPE_ENUM;

/* define the charset encoding */
typedef enum
{
    VA_XML_ENCODING_UTF8,      /* the char encoding is utf8 */
    VA_XML_ENCODING_UTF16,     /* the char encoding is utf16 */
    VA_XML_ENCODING_UCS2,      /* the char encoding is ucs2 */
    VA_XML_ENCODING_UCS4,      /* the char encoding is ucs4 */
    VA_XML_ENCODING_UNKNOWN    /* the char encoding is unknown */
} VA_XML_ENCODING_TYPE_ENUM;

/* this struct is used to parse char entity */
typedef struct
{
    const kal_char named_ch;        /* Predefined char entity */
    const kal_char *named_string;   /* replace text of char entity */
} va_named_char_entry_struct;

/* this struct is used when using file buffer */
typedef struct 
{
    kal_char  valid;                /* whether the file buffer is valid */
    kal_char  *bufptr;              /* point to the buffer provided by app */
    kal_char  isfull;               /* whether the buffer is full */
    kal_int32 virfilelen;           /* the length of data in buffer */
    kal_int32 virfileseek;          /* the position of file buffer */
    kal_int32 bufsize;              /* the size of file buffer */
    FS_HANDLE fp;                   /* file handle */
    kal_int32 realfilebeginpos;     /* file begin position from where we read data */
    kal_int32 realfileseekpos;      /* seek pointer of real file */
} va_virtual_file_buf_struct;

/* this struct is used to parse xml */
typedef struct
{
    VA_XML_malloc_buffer_ptr get_buffer_ptr;       /* function pointer provided by app */
    VA_XML_free_buffer_ptr free_buffer_ptr;        /* function pointer provided by app */
    VA_XML_start_doctype_hdlr start_doctype_hdlr;  /* function pointer provided by app */
    VA_XML_end_doctype_hdlr end_doctype_hdlr;      /* function pointer provided by app */
    VA_XML_start_elem_hdlr start_elem_hdlr;        /* function pointer provided by app */
    VA_XML_end_elem_hdlr end_elem_hdlr;            /* function pointer provided by app */
    VA_XML_data_hdlr data_hdlr;                    /* function pointer provided by app */
    FS_HANDLE source;                           /* file handle */
    kal_uint8 isext;                            /* whether use file buffer */
    va_virtual_file_buf_struct virfileptr;         /* information of file buffer  */
    const kal_char *xml_text;                   /* point to buffer provided by app */
    kal_char *elem[VA_XML_MAX_ELEM_DEPTH];         /* stack for managing element nesting */
    kal_char *ge_data[VA_XML_MAX_ENTITY_COUNT << 1]; /* manage general entity data */
    kal_char *pe_data[VA_XML_MAX_ENTITY_COUNT << 1]; /* manage parameter entity data */
    kal_char *doct_name;        /* this name is saved to match with root element name */
    kal_char *token_ptr;        /* token pointer */
    kal_char *ap_temp;          /* temp buffer to parse xml */
    kal_char *err_str;          /* save the error string */
    void *root;                 /* indicate the root element */
    kal_int32 xml_len;          /* the length of xml_text */
    kal_int32 curr_depth;       /* stack pointer */
    kal_int32 error;            /* error code */
    kal_int32 prolog_depth;     /* the depth of prolog */
    kal_int32 encoding;         /* character encoding */
    kal_int32 prolog_done;      /* whether the prolog has been parsed */
    kal_int32 pos;              /* file position that indicates the length of parsed content */
    kal_int32 pending_start_pos; /* indicate the file position of the pending data */
    kal_int32 cdata_start_pos;  /* indicate the file position of the cdata */
    kal_int32 cdata_len;        /* the length of cdata */
    kal_int32 data_start_pos;   /* indicate the file position of the data */
    kal_int32 need_end_tag;     /* whether need the end tag */
    kal_int32 pending_type;     /* please refer to VA_XML_PENDING_ENTITY_TYPE_ENUM */
    kal_int32 stop;             /* whether stop the xml parser */
    kal_int32 pause;            /* whether pause the xml parser */
    kal_uint8 pe_count;         /* the count of parameter entity */
    kal_uint8 ge_count;         /* the count of general entity */
} VA_XML_PARSER_STRUCT;

/* DOM-NOT_FOR_SDK-BEGIN */
/* this function is used as default element start handler */
extern void va_xml_elem_start_hdlr(
                void *data,
                const kal_char *el,
                const kal_char **attr,
                kal_int32 error);

/* this function is used as default element end handler */
extern void va_xml_elem_end_hdlr(void *data, const kal_char *el, kal_int32 error);

/* this function is used as default doctype start handler */
extern void va_xml_doctype_start_hdlr(
                void *data,
                const kal_char *doctypeName,
                const kal_char **sysid,
                const kal_char **pubid,
                kal_int32 internal_subset,
                kal_int32 error);

/* this function is used as default doctype end handler */
extern void va_xml_doctype_end_hdlr(void *data, kal_int32 error);

/* this function is used as default general data handler */
extern void va_xml_general_data_hdlr(
                void *resv,
                const kal_char *el,
                const kal_char *data,
                kal_int32 len,
                kal_int32 error);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  va_xml_new_parser
 * DESCRIPTION
 *  this function is used to new parser
 * PARAMETERS
 *  parser:      [IN]        Global parser struct
 * RETURNS
 *  result of parser
 *****************************************************************************/
extern kal_int32 va_xml_new_parser(VA_XML_PARSER_STRUCT *parser);


/*****************************************************************************
 * FUNCTION
 *  va_xml_close_parser
 * DESCRIPTION
 *  this function is used to close parser
 * PARAMETERS
 *  parser:      [IN]        Global parser struct
 * RETURNS
 *  void
 *****************************************************************************/
extern void va_xml_close_parser(VA_XML_PARSER_STRUCT *parser);


/*****************************************************************************
 * FUNCTION
 *  va_xml_close_parser_offset
 * DESCRIPTION
 *  this function is used to close offset-parser
 * PARAMETERS
 *  parser:      [IN]        Global parser struct
 * RETURNS
 *  void
 *****************************************************************************/
extern void va_xml_close_parser_offset(VA_XML_PARSER_STRUCT *parser);


/*****************************************************************************
 * FUNCTION
 *  va_xml_parse_file_from_offset
 * DESCRIPTION
 *  this function is called to parse from offset
 * PARAMETERS
 *  parser:          [IN/OUT]        Global parser struct
 *  file_handle:     [IN]            FS_HANDLE of xml file
 * RETURNS
 *  void
 *****************************************************************************/
extern kal_int32 va_xml_parse_file_from_offset(VA_XML_PARSER_STRUCT *parser, kal_int32 file_handle);


/*****************************************************************************
 * FUNCTION
 *  va_xml_register_doctype_handler
 * DESCRIPTION
 *  this functin is used to register document handler
 * PARAMETERS
 *  parser:          [OUT]       Global parser struct
 *  start_hdlr:      [IN]        Function handler to handle start doc data
 *  end_hdlr:        [IN]        Function handler to handle end doc data
 * RETURNS
 *  void
 *****************************************************************************/
extern void va_xml_register_doctype_handler(
                VA_XML_PARSER_STRUCT *parser,
                VA_XML_start_doctype_hdlr start_hdlr,
                VA_XML_end_doctype_hdlr end_hdlr);


/*****************************************************************************
 * FUNCTION
 *  va_xml_register_element_handler
 * DESCRIPTION
 *  this function is used to register element handler
 * PARAMETERS
 *  parser:          [OUT]       Global parser struct
 *  start_hdlr:      [IN]        Function handler to handle start element data
 *  end_hdlr:        [IN]        Function handler to handle end element data
 * RETURNS
 *  void
 *****************************************************************************/
extern void va_xml_register_element_handler(
                VA_XML_PARSER_STRUCT *parser,
                VA_XML_start_elem_hdlr start_hdlr,
                VA_XML_end_elem_hdlr end_hdlr);


/*****************************************************************************
 * FUNCTION
 *  va_xml_register_data_handler
 * DESCRIPTION
 *  this function is used to register data handler
 * PARAMETERS
 *  parser:          [OUT]       Global parser struct
 *  data_hdlr:       [IN]        Function handler to handle data
 * RETURNS
 *  void
 *****************************************************************************/
extern void va_xml_register_data_handler(VA_XML_PARSER_STRUCT *parser, VA_XML_data_hdlr data_hdlr);


/*****************************************************************************
 * FUNCTION
 *  va_xml_parse
 * DESCRIPTION
 *  this function is called by application to start parsing if application pass
 *  xml text with file
 * PARAMETERS
 *  parser:          [IN/OUT]        Global parser struct
 *  file_name:       [IN]            Xml file name
 * RETURNS
 *  void
 *****************************************************************************/
extern kal_int32 va_xml_parse(VA_XML_PARSER_STRUCT *parser, kal_wchar *file_name);


/*****************************************************************************
 * FUNCTION
 *  va_xml_parse_buffer
 * DESCRIPTION
 *  this function is called by application to start parsing if application 
 *  pass xml text with buffer
 * PARAMETERS
 *  parser:          [IN/OUT]        Global parser struct
 *  xmltext:         [IN]            Xml text buffer
 *  length:          [IN]            the length of buffer
 * RETURNS
 *  return VA_XML_RESULT_OK if successful
 *****************************************************************************/
extern kal_int32 va_xml_parse_buffer(
                    VA_XML_PARSER_STRUCT *parser,
                    const kal_char *xmltext,
                    kal_int32 length);


/*****************************************************************************
 * FUNCTION
 *  va_xml_resume_parse
 * DESCRIPTION
 *  this function is called to resume parsing
 * PARAMETERS
 *  parser:      [IN/OUT]        Global parser struct
 * RETURNS
 *  void
 *****************************************************************************/
extern kal_int32 va_xml_resume_parse(VA_XML_PARSER_STRUCT *parser);


/*****************************************************************************
 * FUNCTION
 *  va_xml_pause_parse
 * DESCRIPTION
 *  this function is called to pause parsing
 * PARAMETERS
 *  parser:      [IN/OUT]        Global parser struct
 * RETURNS
 *  void
 *****************************************************************************/
extern void va_xml_pause_parse(VA_XML_PARSER_STRUCT *parser);


/*****************************************************************************
 * FUNCTION
 *  va_xml_stop_parse
 * DESCRIPTION
 *  this function is called to stop parsing
 * PARAMETERS
 *  parser:      [IN/OUT]        Global parser struct
 * RETURNS
 *  void
 *****************************************************************************/
extern void va_xml_stop_parse(VA_XML_PARSER_STRUCT *parser);


/*****************************************************************************
 * FUNCTION
 *  va_xml_free_parse
 * DESCRIPTION
 *  this function is called to free parser
 * PARAMETERS
 *  parser:      [IN/OUT]        Global parser struct
 * RETURNS
 *  void
 *****************************************************************************/
extern void va_xml_free_parse(VA_XML_PARSER_STRUCT *parser);


/*****************************************************************************
 * FUNCTION
 *  va_xml_get_err_string
 * DESCRIPTION
 *  This function is used to return error string to application
 * PARAMETERS
 *  parser:      [IN]        Global parser struct
 * RETURNS
 *  return error string to application
 *****************************************************************************/
extern kal_char *va_xml_get_err_string(VA_XML_PARSER_STRUCT *parser);


/*****************************************************************************
 * FUNCTION
 *  va_xml_configure_memory
 * DESCRIPTION
 *  this function is used to configure memory
 * PARAMETERS
 *  parser:          [IN]        Global parser struct
 *  get_ptr:         [IN]        The pointer to malloc function
 *  free_ptr:        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void va_xml_configure_memory(
                VA_XML_PARSER_STRUCT *parser,
                VA_XML_malloc_buffer_ptr get_ptr,
                VA_XML_free_buffer_ptr free_ptr);


/*****************************************************************************
 * FUNCTION
 *  va_xml_new_parser_ext
 * DESCRIPTION
 *  this function is used to new parser
 * PARAMETERS
 *  parser:      [IN]        Global parser struct
 *  buffer:      [IN}        buffer provided by app
 *  size:        [IN]        The size of buffer 
 * RETURNS
 *  result of parser
 *****************************************************************************/
extern kal_int32 va_xml_new_parser_ext(
                    VA_XML_PARSER_STRUCT *parser,
                    kal_char* buffer,
                    kal_int32 size);

#endif /* __XML_DEF_H__ */


