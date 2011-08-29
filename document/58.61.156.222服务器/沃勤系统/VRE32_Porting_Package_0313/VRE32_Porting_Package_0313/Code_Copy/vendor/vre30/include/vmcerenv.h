/******************************************************************************
 *
 * VRE����֤���װģ�顣����֤��������֤���������ԣ������������ļ�β������ģ��
 * ʵ����������װ����֤��ʹӳ����ļ���ȡ����֤��Ĺ��ܡ�
 *
 * $date$
 * $author$
 *
 *****************************************************************************/
 
#ifndef VMCERENV_H
#define VMCERENV_H

#include "vmsys.h"
#include "vmio.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * ���ļ�������ļ���������֤���򷵻��ļ���������򷵻ش����롣
 *
 * @param filename			�ļ�·����
 *
 * @return	����ļ��ɹ����򷵻ش��ڵ���0���ļ����������ļ������ڣ�����
 *			�ļ�û�а���֤���򷵻�-1��
 */
VMFILE vm_ce_open_file(VMWSTR filename);


void vm_ce_open_file_rom( VMCHAR * rom );


/**
 * �ر��Ѿ��򿪵��ļ���
 *
 * @param handle			��vm_ce_open_file()�򿪵��ļ������
 */ 
void vm_ce_close_file(VMFILE handle);

void vm_ce_close_file_rom( VMCHAR * rom );


/**
 * �Ӵ򿪵��ļ��ж�ȡ����ժҪ������ժҪ��ԭ�ķ�ʽ���������ժҪ�����������㣬
 * ������������Ϊ���ġ�
 *
 * @param handle			��vm_ce_open_file()�򿪵��ļ������
 * @param buf				�������ժҪ�Ļ�����ָ�롣
 * @param buf_size			������ָ�볤�ȡ�
 * @param type				���ժҪ�㷨���͵�ָ�롣
 *
 * @return					����0��ʾ��ȡժҪ�ɹ�������ļ���ʧ�ܣ����߻�����
 *							�����Դ��ժҪ��Ϣ�򷵻ظ��������롣
 */
VMINT vm_ce_read_cert(VMFILE handle, VMUINT8* buf, VMINT buf_size, VMINT * type);

VMINT vm_ce_read_cert_rom(VMCHAR * rom, VMINT rom_size, VMUINT8* buf, VMINT buf_size, VMINT * type);


/**
 * ��ת��֤��ĵ�һ����¼���ڵ���vm_ce_next_field()֮ǰ������ñ�����������
 * ���ܱ�֤�����ֶε���ȷ�ԡ�
 *
 * @param handle			��vm_ce_open_file()�򿪵��ļ������
 *
 * @return					����0��ʾ�����ɹ������򷵻ظ��������롣
 */
VMINT vm_ce_first_field(VMFILE handle);

VMINT vm_ce_first_field_rom( VMCHAR * rom, VMINT rom_size );

/**
 * �Ѷ�ָ���Ƶ�֤�����һ����¼��
 *
 * @param handle			��vm_ce_open_file()�򿪵��ļ������
 *
 * @return					����0��ʾ�����ɹ�������-1��ʾ�Ѿ������һ����¼��
 *							����С��-2�������ʾ��������
 */
VMINT vm_ce_next_field(VMFILE handle);

/**
 * ��ȡ��ǰ��¼�����ͣ��������ڵ���vm_ce_next_field()��ֻ�ܵ���һ�Σ��ظ�����
 * �ᵼ�º�̶������ݴ���
 *
 * @param handle			��vm_ce_open_file()�򿪵��ļ������
 * @param type				��ż�¼���͵�����ָ�롣
 * @param type				��ż�¼���ȵ�����ָ�롣
 * 
 * @return					����0��ʾ�����ɹ������򷵻ش����롣
 */
VMINT vm_ce_read_type(VMFILE handle, VMINT *type, VMINT * value_size );

VMINT vm_ce_read_type_rom(VMCHAR * rom, VMINT rom_size, VMINT *type, VMINT * value_size );

/**
 * ��ȡ��ǰ��¼��ֵ�������������ڵ���vm_ce_read_type()֮����ã�����ֻ�ܵ���
 * һ�Σ��ظ����ûᵼ�º�̶������ݴ���
 *
 * @param handle			��vm_ce_open_file()�򿪵��ļ������
 * @param value				����ֶ�ֵ��ָ�롣
 * @param value_size		valueָ����ָ���ڴ����ֽڳ��ȡ�
 *
 * @return 					����0��ʾ�����ɹ������򷵻ش����롣
 */
VMINT vm_ce_read_value(VMFILE handle, VMUINT8 *value, VMINT value_size);

VMINT vm_ce_read_value_rom(VMCHAR * rom, VMINT rom_size, VMUINT8 *value, VMINT value_size);


/**
 * ��ȡ��ǰӦ�ø�����Ϣ��ժҪ��ժҪ�㷨��֤����˵��
 *
 * @param digest_buf		���ժҪ���ڴ�ָ��
 * @param buf_len			����ֶ�ֵ��ָ�롣
 *
 * @return 				
 */
void vm_ce_get_cert_digest( VMUCHAR * digest_buf, VMINT buf_len );

#ifdef __cplusplus
}
#endif

#endif
