#ifndef		_VM_PER_MNG_
#define		_VM_PER_MNG_

#include "vmsys.h"

#include "vmperdef.h"

#include "vmnvram.h"


/**
 * ��ȡ�ӿ�ָ�롣
 *
 * @param func_name				�ӿ�����
 * @return								�ӿں�����ڵ�ַ��ʧ�ܷ���0ֵ��
 */
VMINT vm_per_get_fun_prt( VMINT * fun_list, VMCHAR * func_name );


/**
 * ��ʼ��ɳ��ϵͳ��
 *
 * @param
 * @return								�ɹ�ʱ����0��ʧ�ܷ��ظ�ֵ��
 */
VMINT vm_per_init( void );


/**
 * ����ɳ��ϵͳ��
 *
 * @param
 * @return								�ɹ�ʱ����0��ʧ�ܷ��ظ�ֵ��
 */
VMINT vm_per_finalize( void );


/**
 * ����Ӧ�ó������Ȩ������������б�
 *
 * @param app_per					Ӧ�ó������Ȩ����
 * @param app_per					Ӧ�ó������Ȩ���� 
 * @return								�ɹ�ʱ����0��ʧ�ܷ��ظ�ֵ��
 */
VMINT vm_per_catch_fun_list( VMINT * app_per, VMINT app_per_len );

#endif