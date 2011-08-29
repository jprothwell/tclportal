/*****************************************************************************
 * 
 * �����ļ�����ģ�顣ϵͳʹ��WIN32 INI FILE���Ƶ������ļ���ʽ���������ı��������ָ�
 * �����ø�ʽ��������һ�������ļ�������
 *
 *   #
 *   # This is global configuration section.
 *   #
 *   [global]
 *   live time=50
 * 
 *   [locale]
 *   country=zh
 *   language=CN
 *
 * ÿ�Է���������������ÿ�������ж��������Ŀ�������ļ������ƴ�С��ʵ���ܹ����������
 * ��Ŀ����ȡ�����ڴ�Ĵ�С��������ÿ��Ϊһ����¼��#��ͷ��ʾ����ע���С������������
 * ��ֵ֮����"="�ָ����Ⱥ�ǰ��Ŀո�ᱻ�Զ����ԣ���������ǰ���ո������ֵβ���Ŀո�
 * �ᱻ�������������Ƶ���󳤶���32���ַ�������\0��������ֵ����󳤶���128���ַ�
 * ������\0����
 *
 * $Author: guangyu.tang $
 * $Date: 2008/03/26 03:59:12 $
 *
 ****************************************************************************/

#ifndef VMCFG_H
#define VMCFG_H

#ifdef __cplusplus
extern "C" {
#endif

#include "vmstdlib.h"

typedef struct _vm_cfg_handle_t {
	VMWCHAR filename[128];
	VMFILE	file;
	vm_dyn_array_t *sections;
} vm_cfg_handle_t;

typedef struct _vm_cfg_section_t {
	char name[32];
	vm_dyn_array_t *items;
} vm_cfg_section_t;

typedef struct _vm_cfg_item_t {
	char name[32];
	char value[128];
} vm_cfg_item_t;

/**
 * �������ļ���
 *
 * @param filename		�����ļ�����
 *
 * @return				���������ļ����ָ������򿪳ɹ������򷵻�NULL��
 */
vm_cfg_handle_t* vm_open_config(VMWSTR filename);

/**
 * �������õ��ļ���
 *
 * @param handle		�����ļ����ָ�롣
 *
 * @return				����0��ʾ����ɹ�������Ϊʧ�ܡ�
 */
VMINT vm_save_config(vm_cfg_handle_t* handle);

/**
 * �ر������ļ���
 *
 * @param handle		�����ļ����ָ�롣
 */
void vm_close_config(vm_cfg_handle_t* handle);

/**
 * ��������������ֵ���ַ�����ʽ���ء�
 *
 * @param handle		�����ļ����ָ�롣
 * @param section		�����������NULL���ʾ��������������Ҫ�����������ñ�
 * @param name			���������ơ�
 * @param value			�������ֵ��
 * @param def			��������û������ʱ���ص�Ĭ��ֵ��
 *
 * @return				����0��ʾ��ȡ���óɹ������򷵻ش����롣
 */
VMINT vm_get_cfg_str(vm_cfg_handle_t* handle, char* section, char* name, 
	 char* value, char* def);

/**
 * �����ַ�����ʽ��������Ŀ��
 *
 * @param handle		�����ļ����ָ�롣
 * @param section		�����������NULL���ʾ��������������Ҫ�����������ñ�
 * @param name			���������ơ�
 * @param value			�������ֵ��
 *
 * @return				����0��ʾ���³ɹ������򷵻ش����롣
 */
VMINT vm_set_cfg_str(vm_cfg_handle_t* handle, char* section, char* name,
	 char* value);

/**
 * ��������������ֵ����������ʽ���ء�
 *
 * @param handle		�����ļ����ָ�롣
 * @param section		�����������NULL���ʾ��������������Ҫ�����������ñ�
 * @param name			���������ơ�
 * @param value			�������ֵ��
 * @param def			��������û������ʱ���ص�Ĭ��ֵ��
 *
 * @return				����0��ʾ��ȡ���óɹ������򷵻ش����롣
 */
VMINT vm_get_cfg_int(vm_cfg_handle_t* handle, char* section, char* name, 
	 int* value, int def);

/**
 * ������������ʽ��������Ŀ��
 *
 * @param handle		�����ļ����ָ�롣
 * @param section		�����������NULL���ʾ��������������Ҫ�����������ñ�
 * @param name			���������ơ�
 * @param value			�������ֵ��
 *
 * @return				����0��ʾ���³ɹ������򷵻ش����롣
 */
VMINT vm_set_cfg_int(vm_cfg_handle_t* handle, char* section, char* name,
	 int value);

#ifdef __cplusplus
}
#endif

#endif
