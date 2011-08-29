#ifndef _VM_CER_VAR_H_
#define	_VM_CER_VAR_H_

#include "vmsys.h"

#include "vmrsa.h"

/**
 * װ��֤��ϵͳ���ݡ�
 *
 *
 * @return				����0��ʾת���ɹ�����ֵΪʧ��,���ݲμ�vmcerter.h��
 */
VMINT	vm_ce_load_var( void );


/**
 * ж��֤��ϵͳ���ݡ�
 *
 *
 * @return				�޷���ֵ
 */
void	vm_ce_unload_var( void );


/**
 * ͨ��id��ù�Կ��
 * 
 * @param id				��Կid��
 * @param key_buf		�洢��Կ�Ļ��塣
 * 
 * @return					����0��ʾ����ɹ�������Ϊʧ��,���ݲμ�vmcerter.h��
 */
VMINT	vm_ce_get_key( VMINT id, VMKey * key_buf );

#endif