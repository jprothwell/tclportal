#ifndef	_VM_RSA_H_
#define _VM_RSA_H_

#include "vmsys.h"

#define		KEY_LEN			64

typedef struct _VMKey{
		VMINT		id;
		VMINT		modlen;
		VMINT		keylen;
		VMUCHAR		mod[KEY_LEN];
		VMUCHAR		key[KEY_LEN];
} VMKey;

typedef VMKey		VMPUBKey;
typedef	VMKey		VMPRIKey;

enum{
	VM_RSA_BN_INDEX_IN = 0,
	VM_RSA_BN_INDEX_MOD,
	VM_RSA_BN_INDEX_KEY,

	VM_RSA_BN_INDEX_RES,
	VM_RSA_BN_INDEX_TOTAL
};

typedef struct _VMPUBKeyCert{
		VMPUBKey		pub;
		VMUCHAR			digest[KEY_LEN];
} VMPUBCert;


/**
 * ��ָ����ŵ���Կ���ܸ�����ǩ����
 *
 * @param signature		ָ��ǩ�����ڴ�ָ�롣
 * @param sign_len		ǩ���ĳ��ȡ�
 * @param id					��Կ��š�
 * @param text				ָ��ǩ�����ܺ����ݵ��ڴ�ָ�롣
 * @param text_len		(in)����ǩ�����ܺ����ݵ��ڴ泤�ȣ�(out)ǩ�����ܺ����ݵĳ��ȡ�  
 * @return						������ܳɹ�������ֵΪ0��ʧ�ܷ��ش����롣
 */
VMINT vm_rsa_verify_by_id( VMUCHAR * signature, VMINT sign_len, VMINT id, VMUCHAR * text, VMINT * text_len );



/**
 * ��ָ������Կ���ܸ�����ǩ����
 *
 * @param signature		ָ��ǩ�����ڴ�ָ�롣
 * @param sign_len		ǩ���ĳ��ȡ�
 * @param key					ָ��洢��Կ�Ľṹ���ָ�롣
 * @param text				ָ��ǩ�����ܺ����ݵ��ڴ�ָ�롣
 * @param text_len		(in)����ǩ�����ܺ����ݵ��ڴ泤�ȣ�(out)ǩ�����ܺ����ݵĳ��ȡ�  
 * @return						������ܳɹ�������ֵΪ0��ʧ�ܷ��ش����롣
 */
VMINT vm_rsa_verify( VMUCHAR * signature, VMINT sign_len, VMKey * key, VMUCHAR * text, VMINT * text_len );


/**
 * ��ָ������Կ�Ը���������ǩ����
 *
 * @param content			ָ��ǩ�����ڴ�ָ�롣
 * @param cont_len		ǩ���ĳ��ȡ�
 * @param key					ָ��洢��Կ�Ľṹ���ָ�롣
 * @param signature		ָ��ǩ�����ܺ����ݵ��ڴ�ָ�롣
 * @param sign_len		(in)����ǩ�����ܺ����ݵ��ڴ泤�ȣ�(out)ǩ�����ܺ����ݵĳ��ȡ�
 * @param type				ָ��ǩ��ʹ�õ���Կ���ͣ�PUB_PADDINGָ�ù�Կǩ����PRI_PADDINGָ��˽Կǩ����
 * @return						������ܳɹ�������ֵΪ0��ʧ�ܷ��ش����롣
 */
VMINT vm_rsa_sign( VMUCHAR * content, VMINT cont_len, VMKey * key, VMUCHAR * signature, VMINT * sign_len, VMINT type );


/**
 * ��ָ������Կ�Ը���������ǩ����
 *
 * @param content			ָ��ǩ�����ڴ�ָ�롣
 * @param cont_len		ǩ���ĳ��ȡ�
 * @param prikey			ָ��洢��Կ�Ľṹ���ָ�롣
 * @param signature		ָ��ǩ�����ܺ����ݵ��ڴ�ָ�롣
 * @param sign_len		(in)����ǩ�����ܺ����ݵ��ڴ泤�ȣ�(out)ǩ�����ܺ����ݵĳ��ȡ�
 * @param type				ָ��ǩ��ʹ�õ���Կ���ͣ�PUB_PADDINGָ�ù�Կǩ����PRI_PADDINGָ��˽Կǩ����
 * @return						������ܳɹ�������ֵΪ0��ʧ�ܷ��ش����롣
 */
VMINT vm_rsa_sign_by_id( VMUCHAR * content, VMINT cont_len, VMINT id, VMUCHAR * signature, VMINT * sign_len, VMINT type );


#endif
