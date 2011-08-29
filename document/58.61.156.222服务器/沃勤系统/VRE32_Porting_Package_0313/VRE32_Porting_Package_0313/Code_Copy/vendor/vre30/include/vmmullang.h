#ifndef	_VM_MUL_LANG_
#define	_VM_MUL_LANG_

#include "vmsys.h"

#define		MUL_LANG_RES_NAME		"lang.bin"

//language type list
enum{
	VM_LANG_NULL = 0,
	
	VM_LANG_ENG,
	VM_LANG_CHS,
	VM_LANG_CHT
};

#define		VM_LANG_ID_START		VM_LANG_ENG
#define		VM_LANG_ID_END			VM_LANG_CHT

#define		VM_LANG_ID_DEFAULT		VM_LANG_ENG


/**
 * ��ʼ����������Դ�⡣��������Դ������vxp�ļ���vm_res�Ρ���Դ����vm_res���е�����Ϊlang.bin��
 *
 * @return		װ�ض�������Դ����ڴ��׵�ַ��NULL����ʧ�ܡ�
 */
VMCHAR * vm_mul_lang_init( void );


/**
 * �ͷŶ�������Դ�⡣
 *
 * @param mul_lang_handle 		��������Դ����ڴ��ַ��
 */
void vm_mul_lang_deinit( VMCHAR * mul_lang_handle );


/**
 * �Ӷ�������Դ���л�ȡָ�����ַ�����
 *
 * @param lang_buf 		��������Դ����ڴ��ַ��
 * @param res_id		�ַ�����Դ�š�
 * @param lang_id  		�������͡�
 * @param lang_buf  	����ָ���ַ�����ָ����ڴ档
 *
 * @return				�ַ������ȡ��������0����ȡָ�����ַ���ʧ�ܡ��ɹ�ʱ��lang_bufָ��
 *						�Ŀռ����ַ����׵�ַ��
 */
VMINT vm_mul_lang_get_string( VMCHAR * lang_buf, VMINT res_id, VMINT lang_id, VMCHAR ** str_buf );


/**
 * �趨��ǰ�����ԡ�
 *
 * @param lang_buf  	�������͡�
 *
 * @return				����1�ɹ���0ʧ�ܡ�
 */
VMINT vm_mul_lang_set_lang( VMINT lang_id );

/**
 * ��ȡ��ǰ�����趨��
 *
 * @return				�������ͣ�Ĭ��ΪVM_LANG_ENG��
 */
VMINT vm_mul_lang_get_lang( void );

/**
 * �������֡�
 *
 * @param disp_buf		��ʾ������ָ�롣
 * @param x				���������ֵ����ϽǺ����ꡣ
 * @param y				���������ֵ����Ͻ������ꡣ
 * @param lang_buf		��������Դ����ڴ��ַ��
 * @param res_id		�ַ�����Դ�š�
 * @param color			������ɫ��ʹ��565��ʽ��
 *
 * @return				
 */
void vm_graphic_textout_by_id( VMUINT8* disp_buf, VMINT x, VMINT y, VMCHAR * lang_buf, VMINT res_id, VMUINT16 color);


/**
 * ��ø����ַ�����Դ���ȣ�������Ϊ��λ��
 *
 * @param lang_buf		��������Դ����ڴ��ַ��
 * @param res_id		�ַ�����Դ�š�
 *
 * @return				�ɹ������ַ�����ȣ�������Ϊ��λ�����򷵻ش�����
 */
VMINT vm_graphic_get_string_width_by_id( VMCHAR * lang_buf, VMINT res_id );

#endif