#ifndef VMMMS_H
#define VMMMS_H 

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"

/**
 *xml文件的路径。
 */
#define MAX_MMS_APP_NAME_LEN  100

typedef enum
{
	VM_MMS_CANCEL = -3,						/*用户取消发送。*/
	VM_MMS_FAIL = -2,                                   		 /*操作请求错误。*/     
     	VM_MMS_MEMORY_NOT_ENOUGH = -1,    		 /*内存不足。*/
      	VM_MMS_SUCCESS							 /*操作成功。*/
 }vm_mms_result_enum;

typedef enum
{
	VM_MMS_TYPE_SMIL_MMS = 0,       			 /*SMIL XML 类型。*/
	VM_MMS_TYPE_MIXED_MMS          				 /*MIXED XML 类型。*/
}vm_mms_type_enum;

typedef enum
{
	VM_MMS_SIM_ID_SIM1 = 1,          			 	 /*sim1 卡。*/
	VM_MMS_SIM_ID_SIM2                 				 /*sim2 卡。*/
}vm_mms_sim_id_enum;

typedef struct
{
	VMUWCHAR xml_filepath[MAX_MMS_APP_NAME_LEN];/*XML文件路径。*/
	VMUINT xml_size;							 /*XML文件大小。*/
	VMUINT8 mms_type;                    				 /*参考vm_mms_type_enum。*/
	VMUINT8 sim_id;                        				 /*参考vm_mms_sim_id_enum。*/
}vm_send_mms_req_t;


/**
 *	彩信回调函数的类型定义。
 *
 *    @param result   操作结果，值参考vm_mms_result_enum。
 */
typedef void (*vm_mms_callback_type)(VMINT  result);

/**
 * 彩信的发送函数。调用此函数后，callback会返回发送结果。
 *
 * @param req_ptr		要发送的彩信的信息。参考vm_send_mms_req_t。
 * @param callback	回调函数。
 *
 * @return	FALSE表示失败，TRUE表示成功。
 */
VMINT vm_mms_send_mms(vm_send_mms_req_t * req_ptr,  vm_mms_callback_type callback);

/**
 * 取消彩信的发送。用户先调用vm_mms_send_mms函数，vm_mms_send_mms函数
 * 先将要发送的彩信放到队列里，然后从队列里取出一个一个发送，
 * 取消彩信发送函数就是将当前进程要发送的彩信从队列中删除，如
 * 果没有调用vm_mms_send_mms函数或者彩信发送的回调函数已经回调回
 * 来，此取消发送函数不起作用。
 */
void vm_mms_cancel_send_mms(void);


#ifdef __cplusplus
}
#endif

#endif








