#ifndef VMCELL_H_
#define VMCELL_H_

#include "vmsys.h"

#ifdef __cplusplus
extern "C" {
#endif

/*cell��Ϣ�Ľṹ�塣*/
typedef struct{
    VMUINT16 arfcn;           /*�ŵ���š�*/
    VMUINT8 bsic;              /*��վ��ʶ�롣*/
    VMUINT8 rxlev;            /*����ǿ�ȵȼ���*/
    VMUINT16 mcc;            /*���Ҵ��롣*/
    VMUINT16 mnc;            /*������롣*/
    VMUINT16 lac;              /*������롣*/
    VMUINT16 ci;                /*С����ʶ����*/
}vm_cell_info_struct;

/*CELLע��״̬��*/
typedef enum{
	VM_CELL_OPEN_REG_ERROR = -2,		/*CELL��Ϣע�����*/
	VM_CELL_OPEN_RES_LESS = -1,		/*ȱ����Դ��*/
	VM_CELL_OPEN_SUCCESS = 0,			/*�򿪳ɹ���*/
	VM_CELL_OPEN_ALREADY_OPEN = 1	/*�Ѿ��򿪡�*/	
	
	
} vm_cell_reg_state_enum;

/**
 * ����CELL��
 *
 * @return	����VM_CELL_OPEN_SUCCESS��ʾ�򿪳ɹ�������VM_CELL_OPEN_ALREADY_OPEN
 * 			��ʾ�Ѿ��򿪣�����VM_CELL_OPEN_RES_LESS��ʾȱ����Դ������
 *			VM_CELL_OPEN_REG_ERROR��ʾע��CELL��Ϣʧ�ܡ�
 */
VMINT vm_cell_open(void);

/**
 * �ر�CELL��
 */
void vm_cell_close(void);

/**
 * ��õ�ǰС����Ϣ�����ô˺���֮ǰһ��Ҫ����vm_cell_open����������
 * �ص��ǿ�ָ��NULL��
 *
 * @return	������ù�vm_cell_open�������򷵻�ָ��ǰС����Ϣ�ṹ���ָ
 *			�룬���򷵻ؿ�ָ��NULL��
 */
vm_cell_info_struct* vm_cell_get_cur_cell_info(void);

/**
 * �������С����Ϣ�����ô˺���֮ǰһ��Ҫ����vm_cell_open����������
 * �ص��ǿ�ָ��NULL��
 *
 * @return	������ù�vm_cell_open�������򷵻�ָ��ǰС����Ϣ�ṹ������
 *			��ָ�룬���򷵻ؿ�ָ��NULL��
 */
vm_cell_info_struct** vm_cell_get_nbr_cell_info(void);

/**
 * ��õ�ǰС��������С����Ŀ�����ô˺���֮ǰһ��Ҫ����vm_cell_open��
 * �������򷵻ص��ǿ�ָ��NULL��
 *
 * @return	������ù�vm_cell_open�������򷵻ص�ǰС��������С����Ŀ����
 *			�ĵ�ַ�����򷵻ؿ�ָ��NULL��
 */
VMINT* vm_cell_get_nbr_num(void);

#ifdef __cplusplus
}
#endif 
#endif

