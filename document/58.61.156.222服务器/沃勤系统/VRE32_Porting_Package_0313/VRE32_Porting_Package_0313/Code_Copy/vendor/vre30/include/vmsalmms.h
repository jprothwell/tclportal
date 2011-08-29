#ifndef VMSALMMS_H
#define VMSALMMS_H 

#ifdef __cplusplus
extern "C" {
#endif

#include "vmmms.h"

/**
 * MMS模块SAL层初始化函数。
 */
void vm_sal_mms_modual_initialize(void);

/**
 * MMS模块SAL层停止函数。
 */
void vm_sal_mms_modual_finialize(void);

/**
 * MMS模块SAL层发送彩信函数。
 *
 * @param req_ptr		彩信信息。
 * @param callback	回调函数。
 */
VMINT vm_sal_mms_send_mms(vm_send_mms_req_t * req_ptr,  vm_mms_callback_type callback);

/**
 * MMS模块SAL层取消发送彩信函数。
 *
 */
void vm_sal_mms_cancel_send_mms(void);

   

#ifdef __cplusplus
}
#endif

#endif








