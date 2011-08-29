#ifndef _VM_SHORTCUT_
#define	_VM_SHORTCUT_

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"

/**
 *	ͨ�������ȫ·�����ļ�������ȡVXP�ļ��е�icon��Ϣ��
 *	������Ҫ�������Ρ�
 *	��һ�ε��ã����ò���icon_ptrΪNULL��������iconͼ�����ݵĳ��ȡ�
 *	�ڶ��ε��ã�ͨ������icon_ptr����icon��ͼ������
 *
 *	@param vxp_filename VXP�ļ����ļ�������ȫ·��
 *	@param icon_ptr			���ͼ�����ݿռ���׵�ַָ��
 *	@param size					���ͼ�����ݿռ�Ĵ�С
 *
 *	@return  ͼ��������Ҫ�洢�ռ�Ĵ�С�������һ�ε��÷���Ϊ0�������ȡͼ����Ϣʧ�ܡ�
 */
VMINT vm_get_appicon( VMWSTR vxp_filename, VMSTR icon_ptr, VMINT size);

/**
 *	ͨ�������ȫ·�����ļ�������ȡVXP�ļ��е�appid��Ϣ��
 *
 *	@param vxp_filename VXP�ļ����ļ�������ȫ·��
 *
 *	@return  ����VXP�ļ��е�appid���������0�������ȡʧ�ܡ�
 */
VMINT vm_get_appid(VMWSTR vxp_filename);


/**
 *	��֤Ӧ�ó����Ƿ���Ч
 *
 *	@param vxp_filename VXP�ļ����ļ�������ȫ·��
 *
 *	@return  Ӧ�ó�����֤ͨ��,����0, ���򷵻ظ����Ĵ����롣�ο�vmcerter.h
 */
VMINT vm_app_is_valid(VMWSTR vxp_filename);


#ifdef __cplusplus
}
#endif

#endif