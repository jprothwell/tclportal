#ifndef VMSIM_H_
#define VMSIM_H_

#include "vmsys.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ��Ӫ�̡�*/
typedef enum 
{
	NO_SIM_CARD = 0,		/* û��SIM �� 		*/
	UNKOWN_OPERATOR,		/* δ֪��Ӫ�̡�	*/
	CMCC, 					/* �й��ƶ���		*/
	UNICOM, 				/* �й���ͨ��		*/
	CNC,					/* �й���ͨ��		*/
	CNTELCOM,				/* �й����š�		*/
	ALL						/* ������Ӫ�̡�	*/
} operator_t;


typedef enum
{
	VM_SIM_STATE_NET_REG_FAILED = -2,	/*��⵽���ڹ���ģʽ��SIM����
											��SIM��ע������ʧ��*/
	VM_SIM_STATE_ERROR = -1,	/*��ѯ״̬����*/
	VM_SIM_STATE_VACANT = 0,	/*SIM��δ���δ����*/
	VM_SIM_STATE_WORKING = 1	/*SIM����������*/
} vm_sim_state_t;

#define VM_SIM_NO 0  /*��SIM��*/
#define VM_SIM_SIM1 1  /*SIM1��*/
#define VM_SIM_SIM2 2  /*SIM2��*/

/**
 * ��õ�ǰ�����������Ӫ�����ơ�
 *
 * @return			��Ӫ�����ơ�
 */
operator_t vm_get_operator(void);

/**
 * ���SIM���Ƿ���롣
 *
 * @return					����TRUE��ʾSIM���Ѳ��룬����ΪFALSE��
 */
VMINT vm_has_sim_card(void);

/**
 * ����ֻ�����IMEI��
 *
 * ���֧��˫IMEI�ŵ������ֻ���ص�ǰ��Ӧ����IMEI��
 * 
 * @return 				�ֻ�����imei �š�������ص�VMSTR
 *								ָ��һ��NULL��ô��ʾϵͳ�����ڵõ�IMEI��
 *								���Ժ���ñ�������
 */
const VMSTR vm_get_imei(void);

/**
 * ����ֻ�����IMSI��ֻ���ص�ǰ��Ӧ����IMEI����
 * 
 * @return 				�ֻ�����imsi �š�
 */
const VMSTR vm_get_imsi(void);

/**
 *	���sim����������
 *	���������:������˫��(ֻ�п�1��Ч��ֻ�п�2��Ч��˫����Ч)
 *
 *	@return         ��ǰ��������,0=�޿���1=��һ�ſ���2=�����ſ�
 */
VMINT vm_sim_card_count(void);

/**
 *	���õ�ǰsim��
 *
 *	@param card_id sim�������,��Ч����VM_SIM_SIM1=��1��VM_SIM_SIM2=��2
 *
 *	@return		TRUE=���óɹ�, FALSE=����ʧ��
 */
VMINT vm_set_active_sim_card(VMINT card_id);

/**
 *	��ȡָ��sim��״̬
 *
 *	@param card_id sim�������,��Ч����VM_SIM_SIM1=��1��VM_SIM_SIM2=��2
 *
 *	@return	sim��״̬��ֵ�μ�vm_sim_state_t��
 */
vm_sim_state_t vm_get_sim_card_status(VMINT card_id);


#define VM_MAX_OPERATOR_CODE_SIZE			(7)

/**
 * �õ���Ӫ�̱�š�
 * @code
 * VMCHAR op_code[VM_MAX_OPERATOR_CODE_SIZE] = {0};
 * 
 * if (vm_query_operator_code(op_code, sizeof(op_code)) == 0)
 * {
 *     // ȡ����Ӫ�̱�ųɹ���
 * }
 * @endcode
 * @param[out]			buffer ȡ����Ӫ�̱�ź�����ָ����ָλ��д����Ӫ�̱�š�
 * @param[in]				buffer_size buffer�Ĵ�С����λΪ�ֽڡ�
 */
VMINT vm_query_operator_code(VMCHAR* buffer, VMUINT buffer_size);

#ifdef __cplusplus
}
#endif 
#endif

