#ifndef VMSALMMS_H
#define VMSALMMS_H 

#ifdef __cplusplus
extern "C" {
#endif

#include "vmmms.h"

/**
 * MMSģ��SAL���ʼ��������
 */
void vm_sal_mms_modual_initialize(void);

/**
 * MMSģ��SAL��ֹͣ������
 */
void vm_sal_mms_modual_finialize(void);

/**
 * MMSģ��SAL�㷢�Ͳ��ź�����
 *
 * @param req_ptr		������Ϣ��
 * @param callback	�ص�������
 */
VMINT vm_sal_mms_send_mms(vm_send_mms_req_t * req_ptr,  vm_mms_callback_type callback);

/**
 * MMSģ��SAL��ȡ�����Ͳ��ź�����
 *
 */
void vm_sal_mms_cancel_send_mms(void);

   

#ifdef __cplusplus
}
#endif

#endif








