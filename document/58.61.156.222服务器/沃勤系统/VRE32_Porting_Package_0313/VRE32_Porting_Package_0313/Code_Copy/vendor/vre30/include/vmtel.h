#ifndef VMTEL_H
#define VMTEL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"


typedef enum
{
	VM_CALLOUT_ERR_STATE = -7,	 /*��ǰ̨״̬*/
	VM_CALLOUT_ERR_NO_SIM ,	 	/*��sim��*/
	VM_CALLOUT_ERR_FLIGHT, 		/*����ģʽ*/
	VM_CALLOUT_ERR_BUSY,			/*�豸��æ*/
	VM_CALLOUT_ERR_PHONE_NUM,	/*�������*/
	VM_CALLOUT_ERR_PROCESS,		/*���̴���*/
	VM_CALLOUT_ERR_NO_RES,		/*δ���뵽��Դ*/
	VM_CALLOUT_NO_ERR
}vm_callout_error_t;

typedef enum
{
	VM_CALLOUT_IDEL = 0,
	VM_CALLOUT_BUSY
}vm_callout_status_t;

/*
 * �绰�ص��������Ͷ���
 *
 * ����һΪ�绰�ú���
 * ������Ϊ���ز�����
 */
typedef void (*VM_CALLOUT_RESPONSE_T)(VMWSTR, VMINT);

/**
 * �绰������
 * 
 * �����ģʽ��˵����
 * �������ں�̨���У��޷�����绰��
 * ǰ̨���̿��Բ���绰����ͨ��endkey�л�����̨��endkey������Ӧ�绰���棬���һ�������
 *
 * @param phnum			UCS2�����ʽ���ֻ����롣
 */
void vm_callout(VMWSTR phnum);

/**
 * �绰������
 * 
 * �����ģʽ��˵����
 * �������ں�̨���У��޷�����绰��
 * ǰ̨���̿��Բ���绰����ͨ��endkey�л�����̨��endkey������Ӧ�绰���棬���һ�������
 *
 * @param phnum			UCS2�����ʽ���ֻ����롣
 * @param callback		�ص�������
 *
 * @return	�绰�����Ľ��������ֵ��ο�vm_callout_error_t��
 *			��ȷ����VM_CALLOUT_NO_ERR����ֵΪ�����롣
 */
VMINT vm_callout_ex(VMWSTR phnum, VM_CALLOUT_RESPONSE_T callback);

/**
 * ����Ϣ���ͳɹ���
 */
#define VM_SMS_RESULT_OK			1

/**
 * ����Ϣ����ʧ�ܡ�
 */
#define VM_SMS_RESULT_ERROR			2

/**
 * ����ȡ������Ϣ����
 */
#define VM_SMS_RESULT_ABORT			3

/**
 * ���Ͷ���Ϣ��
 *
 * @param phone_number		Ŀ���ֻ����롣
 * @param content			����Ϣ���ݡ�
 * @param callback			�ص�������
 * @return     				TRUE=���Ͷ�������ɹ���FALSE=���Ͷ�������ʧ�ܡ�
 * @see						vm_cancel_send_sms
 */
VMINT vm_send_sms(VMWSTR phone_number, VMWSTR content, void (*callback)(VMINT result));

/**
 * ȡ������Ϣ�ķ��ͣ����֮ǰû�е���vm_send_sms����ñ�������û�����á����ע�ᵽvm_send_sms
 * ��ĺ����Ѿ��ص�����ִ�б�����Ҳû���κ����á�ֻ���ڵ���vm_send_sms�󣬲��ҷ��سɹ�����
 * �ص�������û�б�ϵͳ���ز��ܵ��ñ�������
 *
 * @see						vm_send_sms
 */
void vm_cancel_send_sms(void);

/**
 * vm_open_wap_url �ĺ�������ֵ��
 * @{
 */
/**
 * ��������ɹ���
 */
#define VM_OPEN_WAP_URL_SUCCESS				(0)
/**
 * ��������
 */
#define VM_OPEN_WAP_URL_ERROR_PARAM			(-1)
/**
 * �ֻ��ڵ�ǰ״̬��WAP���񲻿��á�
 */
#define VM_OPEN_WAP_URL_NO_SERVICE			(-2)
/**
 * �����ڵ�ǰ״̬���޷����������
 */
#define VM_OPEN_WAP_URL_ERROR_STATUS		(-3)
/** @} */

/**
 * ��WAP�������ת����Ӧ�ĵ�ַ��������ֻ���ڽ��̴���ǰ̨״̬�²��ܵ��á�
 *
 * @param url					WAP��ַ��
 * @return					���������Ƿ�ɹ���
 * @retval					VM_OPEN_WAP_URL_SUCCESS ��WAP�������ɹ���
 * @retval					VM_OPEN_WAP_URL_ERROR_PARAM �������󣬴������ʧ�ܡ�
 * @retval					VM_OPEN_WAP_URL_NO_SERVICE ��ǰ����������á�
 * @retval					VM_OPEN_WAP_URL_ERROR_STATUS ������̲���ǰ̨���ñ��������򷵻�ʧ�ܡ�
 */
VMINT vm_open_wap_url(VMWSTR url);

#ifdef __cplusplus
}
#endif

#endif
