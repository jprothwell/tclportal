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


/* �����Ϣ */
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
 *	��ñ���ļ���ָ���ı������
 *  
 *	@param file		�Ѿ��򿪵��ļ����
 *	@param tag_num  ��Ҫ��ȡ�ı�����
 *  @param buf		��õı������
 *  @param buf_size	������ݵĳ���
 *	
 *	@return			GET_TAG_TRUE��1��ȷ��ȡ��GET_TAG_ERROR��0��ȡ����û�л��ָ���ı������
 */
VMINT vm_get_vm_tag(short* filename,int tag_num, void* buf ,int* buf_size);

/*
 *	�����ļ���MD5У��
 *  
 *  @param filename	ҪУ����ļ���
 *
 *	@return			CHECK_MD5_OK��1У��ͨ����CHECK_MD5_ERROR��0У��ʧ��
 */
VMINT vm_check_md5(short* filename);


/*
 *	ͬʱ��ö��tagֵ
 *  
 *  @param filename	�ļ���
 *
 *  @param tag_req	ϣ�����tag�б�ṹָ��
 *
 *	@return			GET_TAG_TRUE��1��ȷ��ȡ��GET_TAG_ERROR��0��ȡ����û�л��ָ���ı������
*/
VMINT vm_get_multi_tags( short* filename,   MULTI_TAG * tag_req);


/*
 *	�����������ͻ��tagֵ
 *  
 *	@param file		�Ѿ��򿪵��ļ����
 *	@param tag_num  ��Ҫ��ȡ�ı�����
 *  @param buf		��õı������
 *  @param buf_size	������ݵĳ���
 *  @param lang_id	��������
 *	
 *	@return			GET_TAG_TRUE��1��ȷ��ȡ��GET_TAG_ERROR��0��ȡ����û�л��ָ���ı������
*/
VMINT vm_get_tag_by_lang_id( short* filename, int tag_num, void* buf, int* buf_size, int lang_id );


/*
 *	�����������ͻ�ö��tagֵ
 *  
 *  @param filename	�ļ���
 *
 *  @param tag_req	ϣ�����tag�б�ṹָ��
 *  @param lang_id	�������� 
 *
 *	@return			GET_TAG_TRUE��1��ȷ��ȡ��GET_TAG_ERROR��0��ȡ����û�л��ָ���ı������
*/
VMINT vm_get_multi_tags_by_lang_id( short* filename,   MULTI_TAG * tag_req, int lang_id );


#ifdef __cplusplus
}
#endif

#endif
