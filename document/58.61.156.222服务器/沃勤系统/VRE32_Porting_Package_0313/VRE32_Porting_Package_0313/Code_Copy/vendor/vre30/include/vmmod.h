/***********************************************************************
  * ģ�����������ʵ�ֵĺ�������Щ�����ṩ�˹���ģ��
  * �������ڵĹ��ܡ���VRE�������ģ�鶼��������״̬��
  * ������״̬�ֱ��Ӧ:
  *
  * (1) INIT_STATE
  * ��VRE��û��������ʱ�����ģ�鴦�ڸ�״̬���ڸ�״̬��
  * ����ģ���ṩ�ķ����ǿ�ѡ��ġ�VRE�еĸ�������ģ���
  * �Բ��ṩ�κη���Ҳ����ѡ���ṩ���ֻ�ȫ���ķ���
  * ������ṩ�������ģ���ڱ�״̬��Ӧ�ò�������
  * ����ģ���ʵ�֣���Ϊ��INITAL_STATE�£�����ģ���ṩ��
  * ������û�б�֤�ġ�
  *
  * (2) RUNNING_STATE
  * ��ϵͳ����INIT_STATE�£���ģ���յ�EVT_MOD_INIT��Ϣ��ģ���
  * Ӧ�ù��ɵ�RUNNING_STATE�£�������ģ�鴦��FREEZING_STATE��ʱ��
  * �յ�EVT_MOD_ACTIVE��Ϣ����ôģ��Ҳ�ᴦ��RUNNING_STATE
  * ״̬�¡��ڸ�״̬�£�VRE�ڲ���ģ��Ӧ���ṩȫ���ķ����ܡ�
  *
  * (3) FREEZING_STATE
  * ��ģ���յ���EVT_MOD_ACTIVE��Ϣ��VREģ���Ӧ���л���FREEZING_STATE
  * ״̬���ڸ�״̬��ģ������ṩ�ķ����ǲ�ȷ���ģ�������֤�ġ�
  * Ӧ�ó������յ�VRE������INACTIVE��Ϣ��Ӧ���ٵ���VRE�κ�ģ���ṩ
  * ���κη�����Ϊ��Ӧ�ó����յ�����Ϣ�����е�ģ�鶼�Ѵ���
  * FREEZING_STATE���ˡ�ֱ��ģ���յ�EVT_MOD_ACTIVE������ģ��͹��ɵ�
  * RUNNING_STATE״̬���յ�EVT_MOD_RELEASE��Ϣ��ģ��͹��ɵ�INIT_STATE״̬
  * ���ˡ�
  *
  * copyright vogins.co
  * version 1.2.0
  *
  **********************************************************************/
#ifndef MODULE_H
#define MODULE_H

#include "vmsys.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
  * VRE����ģ������������¼���
  */
typedef enum {EVT_MOD_INIT = 1, EVT_MOD_ACTIVE, EVT_MOD_INACTIVE, EVT_MOD_RELEASE} VRE_MOD_LIFECIRCLE_EVT;

/*
  * ����ģ�鴦���������͡�
  */
typedef VMINT (*MOD_EVT_PROCESS)(VRE_MOD_LIFECIRCLE_EVT);

/*
  * ע��ģ��ɹ���
  */
#define REG_VRE_MODULE_SUCCESS						0

/*
  * ������ϵͳ���ܽ��ܵ�����ģ����Ŀ��
  */
#define OVERFLOW_MAX_MODULE_NUM_ERROR			1

/*
  * ģ������ƺ��Ѿ�ע�ᵽϵͳ��ģ��������ͬ��
  */
#define VRE_MODULE_NAME_CONFLICT_ERROR			2

/*
  * ģ�������û��ָ���Ĵ���
  */
#define VRE_MODULE_NAME_NOT_EXISTS_ERROR			3

/**
 * ע��һ��VREģ�顣VRE�е�ÿ��ģ�鶼Ӧ�õ�������������Լ�ע�ᵽϵͳ�С�
 * �ڽ���VRE��������ǰ��VRE�������ᰴģ��ע���˳�����ΰ�ģ�����������
 * �¼�֪ͨ����ģ�顣��ǰ��ģ�鴦�����ķ���ֵֻ����ģ�鴦��EVT_MOD_INIT
 * ��ʱ����Ч������0����ʾ�ɹ������˸�����������Ϣ�����򷵻ش����롣��
 * ��һ��ģ���ڴ���EVT_MOD_INIT��ʱ�򷵻ش�����ôģ���������ᷢ�͸���
 * ����RUNNING_STATE״̬��ģ��EVT_MOD_RELEASE��Ϣ�������˳�VREϵͳ��
 * 
 * 
 * @param name			ģ������ƣ���ģ�����Ʊ�����ָ����ģ���������Ѿ�ע���ģ��������ͬ��
 *						��ô�������᷵�أ��ж��Ǵ�Сд���еġ�����ģ�����Ʊ���
 *						����ֵ�ģ�Ҳ����˵strlen(name)  > 0 ������TRUE��
 * @param process			ģ��ע�ᵽģ��������ϵ�ģ�����������ϵĴ�������		
 *
 * @return
 */
VMINT _vm_reg_module(VMSTR name, MOD_EVT_PROCESS process);

/**
 * ע�����е�ģ�顣
 */
VMINT _vm_reg_modules(void);

/**
 * ģ��������״̬���͡�
 */
typedef enum {
	MOD_STATUS_SHUTDOWN,
	MOD_STATUS_RUNNING,
	MOD_STATUS_PAUSE
} VRE_MOD_STATUS;

/**
 * �õ�ģ��������״̬��
 */
VRE_MOD_STATUS _vm_get_status(void);

/**
  * ֪ͨģ��������ڵ�ģ�����������¼���
  * 
  * 
  * @param event			��Ҫ֪ͨ��ģ������������¼���
  * 
  */
VMINT _vm_notify_modules(VRE_MOD_LIFECIRCLE_EVT event);


/**
  * ��ʼ��ģ��������õ�����Դ�������ڵ���_vm_setup_modules����
  * ǰ���á�
  */
void _vm_initizlize_module_manager(void);

/**
  * ����ģ��������õ�����Դ�������ڵ���_vm_cleanup_modules������
  * ���á�
  */
void _vm_destory_module_manager(void);

#ifdef __cplusplus
}
#endif

#endif

