/*****************************************************************************
 *
 * ϵͳ���ò�������ģ�顣VRE�����ò����洢�������ļ��ڣ����ù���ģ�����������洢����
 * �Ƿ���������ļ������û�������������ļ�ϵͳ���ҵ����������ò��������ڴ棬ϵͳ��
 * ����ģ�����ͨ���ӿں�����дϵͳ���ò�����
 *
 * $Author: guangyu.tang $
 * $Date: 2008/03/25 09:50:07 $
 *
 ****************************************************************************/

#ifndef VMPARAM_H
#define VMPARAM_H

#ifdef __cplusplus
extern "C" {
#endif

#include "vmlog.h"
#include "vmsock.h"

#define SYS_MEM_POOL_SIZE		(100 * 1024)
#define APP_MEM_POOL_SIZE		(700 * 1024)
#define CURRENT_APN				VM_TCP_APN_CMWAP
#define LOG_LEVEL				VM_ERROR_LEVEL

/**
 * ϵͳ���ò�����
 */
typedef struct _vm_sys_cfg_t {
	/*
	 * ϵͳ�ڴ�����������û������Ĭ����100K��
	 */
	VMINT sys_mem_pool_size;

	/*
	 * Ӧ�ó����ڴ�����������û������Ĭ����700K��
	 */
	VMINT app_mem_pool_size;

	/*
	 * Ĭ�ϵ�����������ͣ�1ΪCMWAP��2ΪCMNET��û��������ΪCMWAP��
	 */
	VMINT current_apn;

	/*
	 * ��־�������1-Fatal, 2-Error, 3-Warning, 4-Info, 5-Debug��û��������ΪError��
	 */
	VMINT log_level;
} vm_sys_cfg_t;

/**
 * ���ϵͳ���ò�����
 *
 * @return			ϵͳ���ò����ṹָ�롣
 */
const vm_sys_cfg_t* vm_get_sys_cfg(void);

#ifdef __cplusplus
}
#endif

#endif