#ifndef _VM_CER_MNG_
#define	_VM_CER_MNG_

#include "vmcert.h"
#include "vmsys.h"

/**
 * ��ʼ��Ӧ�ó���֤����֤ϵͳ��
 *
 * @param 
 *
 * @return	���֤��ϵͳ��ʼ���ɹ�������ֵΪ0��ʧ�ܷ��ش����롣
 */
VMINT vm_ce_init( void );


/**
 * ����Ӧ�ó���֤����֤ϵͳ��
 *
 * @param 
 *
 * @return
 */
void vm_ce_finialize( void );


/**
 * װ��Ӧ�ó���֤�顣
 *
 * @param filename			�ļ�·����
 *
 * @return	���֤��װ�سɹ��򷵻�����֤��Ľṹָ�룬���֤�鲻���ڣ�����
 *			�ļ�û�а���֤���򷵻�ֵΪ�ա�
 */
VRECert * vm_ce_load_app( VMWSTR filename );

VRECert * vm_ce_load_app_rom( VMCHAR * rom, VMINT	rom_size );

/**
 * ж��Ӧ�ó���֤�顣
 *
 * @param cert				����֤��Ľṹָ�롣
 *
 * @return	�޷���ֵ
 */
void vm_ce_unload_app( VRECert * cert );

enum{
		VERIFY_SIG = 1,
		VERIFY_FULL
};

/**
 * ��֤Ӧ�ó����Ƿ�Ϸ���
 *
 * @param cert				����֤��Ľṹָ�롣
 * @param digest			Ӧ�ó���ժҪ��ͬӦ�ó����ǩ�е�ժҪ��Ϣ����
 * @param len				Ӧ�ó���ժҪ����
 * @param type				Ӧ�ó�������
 * @param mode				��֤ģʽ��VERIFY_SIG��ʾ����֤ǩ����VERIFY_FULL��ʾ����������������� 
 * @return	���Ӧ�ó�����֤�ɹ��򷵻�ֵΪ�㣬���򷵻ظ����Ĵ�����롣
 */
VMINT vm_ce_verify_app( VRECert * cert, VMUCHAR * digest, VMINT len, VMINT mode );


/**
 * ��ȡӦ�ó����ժҪ��
 *
 * @param filename		Ӧ�ó�������
 * @param cache_buf		�ļ����塣
 * @param cache_len		�ļ������С�� 
 * @param digest			Ӧ�ó���ժҪ��ͬӦ�ó����ǩ�е�ժҪ��Ϣ����
 * @return				����Ӧ�ó���ժҪ�Ƿ�ɹ���0Ϊ�ɹ�������Ϊ������롣
 */
VMINT vm_ce_get_app_digest( VMWSTR filename, VMUCHAR * cache_buf, VMINT cache_len, unsigned char digest[DIG_MAX_LEN] );


/**
 * ��ȡӦ�ó����ժҪ��
 *
 * @param rom			Ӧ�ó�������
 * @param rom_size		Ӧ�ó����С�� 
 * @param digest			Ӧ�ó���ժҪ��ͬӦ�ó����ǩ�е�ժҪ��Ϣ����
 * @return				����Ӧ�ó���ժҪ�Ƿ�ɹ���0Ϊ�ɹ�������Ϊ������롣
 */
VMINT vm_ce_get_app_digest_rom( VMCHAR * rom, VMINT rom_size, unsigned char digest[DIG_MAX_LEN] );

/**
 * ��֤Ӧ�ó����Ƿ�Ϸ���
 *
 * @param filename		Ӧ�ó�������
 * @return	���Ӧ�ó�����֤�ɹ��򷵻�ֵΪ�㣬���򷵻ظ��������롣
 */
VMINT vm_ce_auth_app( VMWSTR filename, VMUCHAR * cache_buf, VMINT cache_len );


/**
 * �����ں������е�Ӧ��id�����˹���Ӧ��id�б�
 * ���ԭʼ�б��д���������������е�id����id �ᱻ���
 *
 * @param appid_list		Ӧ��id �б�
 * @param appid_len		Ӧ��id �б���

 * @return				�ɹ�����ʱ�����㣬���򷵻ظ����Ĵ�����롣
 */
VMINT vm_ce_check_appid_list( VMINT * appid_list, VMINT appid_len );

/**
 * UA �����õ�DES����
 * 
 *
 * @param input			�����ܵ�����
 * @param input_len		�����ܵ����ĳ���
 * @param output_len		���ܺ�����ݳ���

 * @return				�ɹ�����ʱ�������ĵ�ָ�룬���򷵻�NULL��
 */
VMUINT8 * vm_ua_decrypt_data(VMUINT8 * input, VMINT input_len, VMINT * output_len);
#endif
