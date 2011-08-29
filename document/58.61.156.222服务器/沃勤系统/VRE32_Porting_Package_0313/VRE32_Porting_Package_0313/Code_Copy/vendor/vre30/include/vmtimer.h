#ifndef VMTIMER_H_
#define VMTIMER_H_

#include "vmsys.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
	
	VM_TIMER_MTK_TIMER_NO_FREE = -5,
	VM_TIMER_ERROR_OF_PROCESS,
	VM_TIMER_ERROR_OF_RES ,
	VM_TIMER_ERROR_OF_MEM ,
	VM_TIMER_ERROR ,
	VM_TIMER_OK
} vm_timer_error_t;

typedef void (*VM_TIMERPROC_T)(VMINT tid);

/**
 * ������ʱ����
 * ����ʱ�����ɹ�������ϵͳ�ᶨʱ�ص���ʱ��������ֱ������Ա
 * ����vm_delete_timer()ɾ����ʱ��Ϊֹ���������˳�ʱ������Ա����ɾ��������
 * ���������ж�ʱ����
 *
 * ���ඨʱ�������ֻ�����ƹر�״̬�½�������״̬(���л���)��
 *
 * ����һ��Ӧ�ó�����˵�����ඨʱ�����֧��10��ͬʱ������
 *
 * @param millisec		��ʱ����ʱʱ�䣬�Ժ���Ϊ��λ��
 * @param timerproc		��ʱ����ʱ��Ļص�������
 *
 * @return				���طǸ�����ʾ��ʱ��ID�����ظ�����ʾʧ�ܡ�
 */
VMINT vm_create_timer(VMUINT32 millisec, VM_TIMERPROC_T timerproc);

/**
 * ɾ����vm_create_timer�����Ķ�ʱ����
 *
 * @param timerid		��ʱ����ʶ�š�
 *
 * @return				����0��ʾ�ɹ�������Ϊʧ�ܡ�
 */
VMINT vm_delete_timer(VMINT timerid);

/**
 * ������ʱ����
 * ����ʱ�����ɹ�������ϵͳ�ᶨʱ�ص���ʱ��������ֱ������Ա
 * ����vm_delete_timer_ex()ɾ����ʱ��Ϊֹ���������˳�ʱ������Ա����ɾ��������
 * ���������ж�ʱ����
 *
 * �ö�ʱ��ֻ�ڱ���رյ������Ҳ��������������
 *
 * ����һ��Ӧ�ó�����˵�����ඨʱ�����֧��10��ͬʱ������
 *
 * @param millisec		��ʱ����ʱʱ�䣬�Ժ���Ϊ��λ��
 * @param timerproc		��ʱ����ʱ��Ļص�������
 *
 * @return				���طǸ�����ʾ��ʱ��ID�����ظ�����ʾʧ�ܡ�
 */
VMINT vm_create_timer_ex(VMUINT32 millisec, VM_TIMERPROC_T timerproc);


/**
 * ɾ����vm_create_timer_ex�����Ķ�ʱ����
 *
 * @param timerid		��ʱ����ʶ�š�
 *
 * @return				����0��ʾ�ɹ�������Ϊʧ�ܡ�
 */
VMINT vm_delete_timer_ex(VMINT timerid);


#ifdef __cplusplus
}
#endif

#endif