#ifndef		_VM_PKCK_1_PADDDING_SCHEME_
#define		_VM_PKCK_1_PADDDING_SCHEME_

#include "vmsys.h"

#define RSA_PKCS_PADDING_SIZE			11


#define	PUB_PADDING					1
#define	PRI_PADDING					2

#define PADDING_TYPE_ERROR			0

#define PKCS_PADDING_OK					1

/**
 * �������PKCS1�淶����䡣
 *
 * @param to_buf			Ŀ�껺���ָ�롣
 * @param to_len			Ŀ�껺��ĳ��ȡ�
 * @param from_buf		ָ����Ҫ�������ݵ�ָ�롣
 * @param fromn_len		��Ҫ�������ݵĳ��ȡ� 
 * @param type				����������ͣ�PUB_PADDINGΪ��Կǩ��������ͣ�PRI_PADDINGΪ˽Կǩ��������͡� 
 * @return						��ӳɹ�����1��ʧ�ܷ���0��
 */
VMINT vm_add_pkcs_padding( VMUCHAR * to_buf, VMINT to_len, VMUCHAR * from_buf, VMINT from_len, VMINT type );


/**
 * ����PKCS1�淶ȥ����䣬����Ҫָ��������͡����ԭʼ�ַ�������PKCS1�淶��䣬�������޸ġ�
 *
 * @param to_buf			Ŀ�껺���ָ�롣
 * @param to_len			Ŀ�껺��ĳ��ȡ�
 * @param from_buf		ָ����Ҫȥ���������ݵ�ָ�롣
 * @param fromn_len		��Ҫȥ���������ݵĳ��ȡ� 
 * @return						ȥ�����ɹ�����1ȥ����������ݳ��ȣ�ʧ�ܷ���0��
 */
VMINT vm_check_pkcs_padding( VMUCHAR * to_buf, VMINT to_len, VMUCHAR * from_buf, VMINT from_len );

#endif