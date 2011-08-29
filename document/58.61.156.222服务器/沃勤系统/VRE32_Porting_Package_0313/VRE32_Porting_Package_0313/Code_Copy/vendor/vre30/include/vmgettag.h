#ifndef VMTAG_H_
#define VMTAG_H_


#ifdef __cplusplus
extern "C" {
#endif

#include "vmio.h"
#include "vmsys.h"

#define		MULTI_TAG_MAX			10

#define PPID		1
#define USAGE_MODE	2
#define PARAM		3
#define PRICE		4
#define TRIAL		5
#define CN_NAME		6
#define DEVELOPER	7
#define SERIAL_NUM	8
#define VERSION		9
#define ICON		10

#define CHECK_MD5_OK		1
#define CHECK_MD5_ERROR		0

#define GET_TAG_TRUE		1
#define GET_TAG_ERROR		0


#define	GET_TAG_INSUFFICIENT_BUF	(-1)
#define	GET_TAG_NULL_BUF					(-2)
	
#define	GET_TAG_NOT_FOUND 				(-3)
#define	GET_TAG_FILE_ERROR				(-4)

//added by han wei 
#define GET_TAG_NOT_A_LIST_TAG		(-5)
#define GET_TAG_LANG_NOT_FOUND		(-6)


/* 标记信息 */
typedef struct main_sign_t {
	char sign[8];
	int size;
	char md5[16];
	char reserved[8];
} main_sign_t;


typedef struct multi_tag_t{
	VMINT		tag_id[MULTI_TAG_MAX];
	VMINT		tag_len[MULTI_TAG_MAX];
	VMUCHAR *	tag_content[MULTI_TAG_MAX];
} MULTI_TAG;

/*
 *	获得标记文件中指定的标记内容
 *  
 *	@param file		已经打开的文件句柄
 *	@param tag_num  需要获取的标记序号
 *  @param buf		获得的标记内容
 *  @param buf_size	标记内容的长度
 *	
 *	@return			GET_TAG_TRUE或1正确读取，GET_TAG_ERROR或0读取错误，没有获得指定的标记内容
 */
VMINT vm_get_vm_tag(short* filename,int tag_num, void* buf ,int* buf_size);

/*
 *	进行文件的MD5校验
 *  
 *  @param filename	要校验的文件名
 *
 *	@return			CHECK_MD5_OK或1校验通过，CHECK_MD5_ERROR或0校验失败
 */
VMINT vm_check_md5(short* filename);


/*
 *	同时获得多个tag值
 *  
 *  @param filename	文件名
 *
 *  @param tag_req	希望获得tag列表结构指针
 *
 *	@return			GET_TAG_TRUE或1正确读取，GET_TAG_ERROR或0读取错误，没有获得指定的标记内容
*/
VMINT vm_get_multi_tags( short* filename,   MULTI_TAG * tag_req);


/*
 *	根据语言类型获得tag值
 *  
 *	@param file		已经打开的文件句柄
 *	@param tag_num  需要获取的标记序号
 *  @param buf		获得的标记内容
 *  @param buf_size	标记内容的长度
 *  @param lang_id	语言类型
 *	
 *	@return			GET_TAG_TRUE或1正确读取，GET_TAG_ERROR或0读取错误，没有获得指定的标记内容
*/
VMINT vm_get_tag_by_lang_id( short* filename, int tag_num, void* buf, int* buf_size, int lang_id );


/*
 *	根据语言类型获得多个tag值
 *  
 *  @param filename	文件名
 *
 *  @param tag_req	希望获得tag列表结构指针
 *  @param lang_id	语言类型 
 *
 *	@return			GET_TAG_TRUE或1正确读取，GET_TAG_ERROR或0读取错误，没有获得指定的标记内容
*/
VMINT vm_get_multi_tags_by_lang_id( short* filename,   MULTI_TAG * tag_req, int lang_id );


#ifdef __cplusplus
}
#endif

#endif
