#ifndef VMMMS_H
#define VMMMS_H 

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"

/**
 *xml�ļ���·����
 */
#define MAX_MMS_APP_NAME_LEN  100

typedef enum
{
	VM_MMS_CANCEL = -3,						/*�û�ȡ�����͡�*/
	VM_MMS_FAIL = -2,                                   		 /*�����������*/     
     	VM_MMS_MEMORY_NOT_ENOUGH = -1,    		 /*�ڴ治�㡣*/
      	VM_MMS_SUCCESS							 /*�����ɹ���*/
 }vm_mms_result_enum;

typedef enum
{
	VM_MMS_TYPE_SMIL_MMS = 0,       			 /*SMIL XML ���͡�*/
	VM_MMS_TYPE_MIXED_MMS          				 /*MIXED XML ���͡�*/
}vm_mms_type_enum;

typedef enum
{
	VM_MMS_SIM_ID_SIM1 = 1,          			 	 /*sim1 ����*/
	VM_MMS_SIM_ID_SIM2                 				 /*sim2 ����*/
}vm_mms_sim_id_enum;

typedef struct
{
	VMUWCHAR xml_filepath[MAX_MMS_APP_NAME_LEN];/*XML�ļ�·����*/
	VMUINT xml_size;							 /*XML�ļ���С��*/
	VMUINT8 mms_type;                    				 /*�ο�vm_mms_type_enum��*/
	VMUINT8 sim_id;                        				 /*�ο�vm_mms_sim_id_enum��*/
}vm_send_mms_req_t;


/**
 *	���Żص����������Ͷ��塣
 *
 *    @param result   ���������ֵ�ο�vm_mms_result_enum��
 */
typedef void (*vm_mms_callback_type)(VMINT  result);

/**
 * ���ŵķ��ͺ��������ô˺�����callback�᷵�ط��ͽ����
 *
 * @param req_ptr		Ҫ���͵Ĳ��ŵ���Ϣ���ο�vm_send_mms_req_t��
 * @param callback	�ص�������
 *
 * @return	FALSE��ʾʧ�ܣ�TRUE��ʾ�ɹ���
 */
VMINT vm_mms_send_mms(vm_send_mms_req_t * req_ptr,  vm_mms_callback_type callback);

/**
 * ȡ�����ŵķ��͡��û��ȵ���vm_mms_send_mms������vm_mms_send_mms����
 * �Ƚ�Ҫ���͵Ĳ��ŷŵ������Ȼ��Ӷ�����ȡ��һ��һ�����ͣ�
 * ȡ�����ŷ��ͺ������ǽ���ǰ����Ҫ���͵Ĳ��ŴӶ�����ɾ������
 * ��û�е���vm_mms_send_mms�������߲��ŷ��͵Ļص������Ѿ��ص���
 * ������ȡ�����ͺ����������á�
 */
void vm_mms_cancel_send_mms(void);


#ifdef __cplusplus
}
#endif

#endif








