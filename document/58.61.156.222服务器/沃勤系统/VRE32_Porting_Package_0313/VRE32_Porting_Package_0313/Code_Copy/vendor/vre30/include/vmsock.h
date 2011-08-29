/*
 *
 * TCP ���첽ʵ�֣�����TCP��·���¼������첽��ʽ
 * ֪ͨ�ͻ��ˡ���Ҫ֪ͨ�ͻ��˵��¼�����:
 * 
 * VM_TCP_EVT_CONNECTED
 * ��TCP��·���Ӻ�Ѹ��¼�֪ͨ�ͻ��ˣ������Ӻ����TCP ��
 * �Ķ�дͨ�����ǿ�д���ɶ��ġ�
 *
 * VM_TCP_EVT_CAN_READ
 * ���û��������󣬵�TCP��·�����пɶ������ݣ���ʵ�ֻ�
 * �Ѹ��¼����ظ��ͻ��ˣ�֪ͨ�ͻ��˼�����ȡ���ڿͻ���
 * ����vm_tcp_read������ʱ�򣬷���0���ʾ��ǰ��ͨ���Ѿ�
 * ���ڶ�����״̬���ͻ�����Ӧ���ټ�������vm_tcp_read������
 * ��Ӧ�õȴ��յ�VM_TCP_EVT_CAN_READ�¼����ټ�������
 *
 * VM_TCP_EVT_CAN_WRITE  
 * ���û�д�����󣬵�TCP��·�е�buffer ���пռ��дʱ��
 * ��ʵ�ֻ�Ѹ��¼����ظ��ͻ��ˣ�֪ͨ�ͻ��˼���д���ݡ�
 * �ڿͻ��˵���vm_tcp_write������ʱ�򣬷���0���ʾ��ǰд
 * ͨ���Ѿ�����д����״̬���ͻ�����Ӧ���ټ�������
 * vm_tcp_write��������Ӧ�õȴ��յ�VM_TCP_EVT_CAN_WRITE�¼�����
 * ����д��
 *
 * VM_TCP_EVT_PIPE_BROKEN
 * ���¼�����TCPͨ������ʧ�ܵ�ʱ���첽���ظ��ͻ��ˣ�
 * �ͻ������յ����¼��󣬲�Ӧ������ͨ����д���ݻ�
 * �����ݣ�Ҳ���ü�������vm_tcp_close��������Ӧ�����½���
 * TCP���ӡ�
 * 
 * VM_TCP_EVT_HOST_NOT_FOUND
 * ���¼�ֻ����CMNET���ӵ�ʱ����п��ܷ��ظ��¼�����
 * CMNET����ʱ��ͨ����������ȡIP��ַʧ�ܣ����¼��ᱻ����
 * ���ͻ��ˣ��ͻ��������յ����¼��󣬲�Ӧ������ͨ����
 * д���ݻ�����ݣ�Ҳ��Ӧ�õ���vm_tcp_close��������TCP��·
 * �ᱻ�Զ��رա�
 *
 * VM_TCP_EVT_PIPE_CLOSED
 * ���¼�ֻ��TCP��·�Ѿ�������Ҳ���ǿͻ��������յ�
 * VM_TCP_EVT_CONNECTED�¼���������ʱ��ͨѶ˫�����κ�
 * һ���ر�TCP���ӣ���ô��TCP���ӹرպ󣬿ͻ��˳����
 * �յ����¼��������ǿͻ��Լ�����vm_tcp_close������Ҳ��
 * �յ����¼���֪ͨ��
 *
 */

#ifndef VM_SOCK_H
#define VM_SOCK_H

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"
#include "vmglobalver.h"
/**
 * TCP��·�Ѿ���������ʱ��·���ڿɶ�д״̬��
 */
#define VM_TCP_EVT_CONNECTED	1

/**
 * TCP��·���ڿ�д״̬��
 */
#define VM_TCP_EVT_CAN_WRITE	2

/**
 * TCP��·���ڿɶ�״̬��
 */
#define VM_TCP_EVT_CAN_READ		3

/**
 * TCP��·�жϡ�
 */
#define VM_TCP_EVT_PIPE_BROKEN	4

/**
 * ����δ�ҵ���������ִ��DNS����ʧ�ܺ󷵻ص�״̬��
 */
#define VM_TCP_EVT_HOST_NOT_FOUND	5

/*
 * TCP��·���رպ���¼���
 */
#define VM_TCP_EVT_PIPE_CLOSED	6

/**
 * û���㹻��Դ������TCP��·��
 */
#define VM_TCP_ERR_NO_ENOUGH_RES	-1

/**
 * �����׽���ʧ�ܡ�
 */
#define VM_TCP_ERR_CREATE_FAILED	-2

/**
 * @name VRE֧�ֵ�Access Point Name��
 * @{
 */
/**
 * ʹ��GPRS/CMNET�ʺŴ������ӡ�
 */
#define VM_TCP_APN_CMNET		(1)

/**
 * ʹ��GPRS/CMWAP�ʺŴ������ӡ�
 */
#define VM_TCP_APN_CMWAP		(2)

/**
 * ʹ��WLAN(802.11b/g)�������ӡ�
 */
#define VM_TCP_APN_WIFI		(3)
/** @} */

/**
 * ����TCP���ӣ�����һ���첽����������״̬ͨ���ص������ش���Ӧ�ó���
 * ���ϵͳ���ش��ڵ���0��TCP���Ӿ�����������ڿɶ�д״̬����VRE��
 * ����Ķ�д�����첽ģʽ������VRE�ĵ��������Ծ����ģ�Ӧ�ó��������
 * �첽��ʽ��д�������ݡ�
 *
 * @param host				Զ��������������Ϊ���ʮ���Ƹ�ʽ��IP��ַ��
 * @param port				Զ�������˿ڡ�
 * @param apn				������ʹ�õ�GPRS�ʺţ�����ΪVM_TCP_APN_CMNET
 *							��VM_TCP_APN_CMWAP���Լ�VM_TCP_APN_WIFI��<br></br>
 *							CMNET���й��ƶ��ṩ���ֻ�ֱ����������APN��
 *							��ʱ�ֻ�������Ϊ����һ��MODEM��<br></br>
 *							CMWAP��ֻ���ڳ���WAPҵ���APN��Ӧ�ó������
 *							ͨ���й��ƶ���WAP GATEWAY�������ӷ���������ʱDNS
 *							Ĭ�ϲ�����ֻ�ܷ��ʵ�10.0.0.172�����������<br></br>
 *							VM_TCP_APN_WIFIʹ��Wi-Fi��ʽ���Ѿ�������WLAN�ϵ���Դ
 *							���з��ʵ�APN����ʹ�ñ�����ǰ���Ե���vm_tcp_wifi_connected
 *							������ѯWIFI�Ƿ��Ѿ����ӣ������û�����ӵ�����µ���
 *							������������ܵõ�VM_TCP_ERR_CREATE_FAILED��
 *
 * @param callback			�¼��ص�������ϵͳͨ������ص�������Ӧ��
 *							���򴫵�TCP��·��״̬���ص������ĵ�һ����
 *							����vm_tcp_connect���صľ����eventΪTCP����·���¼���
 *
 * @return					���ش��ڵ���0��TCP���Ӿ����ʾϵͳ�Ѿ�����
 *							���������󣬷��򷵻ظ�����ʾ����
 */
VMINT vm_tcp_connect(const char* host, const VMINT port, const VMINT apn,
	void (*callback)(VMINT handle, VMINT event));

/**
 * �ر�TCP��·��
 *
 * @param handle			��������vm_tcp_connect()���صľ����
 */
void vm_tcp_close(VMINT handle);

/**
* TCP����·���������Ľ�����
*/
#define VM_TCP_READ_EOF				(-1)

/**
 * ��TCP��·�ж�ȡ�����ֽڡ�
 *
 * @param handle			TCP���Ӿ����
 * @param buf				����������
 * @param len				�����������ȡ�
 *
 * @return					���ض�ȡ���ֽ���������0��ʾ��·��û�����ݿɶ�������·
 *							����������VM_TCP_READ_EOF��ʾ��ȡ�������Ľ�������ʱӦ�ó���
 *							Ӧ�õ���vm_tcp_close�ر����ӡ����������������ʾ��·�����쳣��
 *							��ʱ����ԱӦ�ر���·��
 */
VMINT vm_tcp_read(VMINT handle, void* buf, VMINT len);

/**
 * ��TCP��·д�������ֽڡ�
 *
 * @param handle			TCP���Ӿ����
 * @param buf				�洢д�����ݵĻ�������ַָ�롣
 * @param len				Ҫд�����ٸ��ֽڡ�
 *
 * @return					����ʵ��д��TCP��·���ֽ�������
 */
VMINT vm_tcp_write(VMINT handle, void* buf, VMINT len);


/**
 * �ֻ�ƽ̨�Ƿ�֧��Wi-Fi��
 *
 * @return 		�Ƿ�֧��Wi-Fi��
 * @retval 		FALSE ��ʾ��֧�֡�
 * @retval 		TRUE ��ʾ֧�֡�
 */
VMINT vm_is_support_wifi(void);

/**
 * Wi-Fi�Ƿ��Ѿ����ϡ�
 *
 * @return 		�Ƿ��Ѿ����ϡ�
 * @retval 		FALSE ��ʾδ���ϡ�
 * @retval 		TRUE ��ʾ�Ѿ����ϡ�
 */
VMINT vm_wifi_is_connected(void);




typedef void (*vre_gprs_acct_set_done_callback)(void);


typedef void (*vm_tcp_check_ready_callback)(int);

#ifdef __cplusplus
}
#endif

#endif
