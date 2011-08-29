#ifndef VMSALCELL_H_
#define VMSALCELL_H_

#include "vmcell.h"

#ifdef __cplusplus
extern "C" {
#endif

#define VM_SAL_CELL_NBR_MAX	6

typedef enum{
	VM_SAL_CELL_REG_NO_CELL = -4,
	VM_SAL_CELL_REG_ILM_MALLOC_FAILED = -3 ,
	VM_SAL_CELL_REG_NBR_MALLOC_FAILED = -2, 
	VM_SAL_CELL_REG_CUR_MALLOC_FAILED = -1,	
	VM_SAL_CELL_REG_SUCCESS = 0
} vm_sal_cell_reg_state_enum;

/**
 * ע��CELL��Ϣ�������ڴ档
 *
 * @return	����VM_SAL_CELL_REG_SUCCESS��ʾע��ɹ�������VM_SAL_CELL_REG_CUR_MALLOC_FAILED
 *			��ʾ���䵱ǰС���ڴ�ʧ�ܣ�����VM_SAL_CELL_REG_NBR_MALLOC_FAILED��ʾ����
 *			����С���ڴ�ʧ�ܣ�����VM_SAL_CELL_REG_ILM_MALLOC_FAILED��ʾ���䷢����Ϣ
 *			�ڴ�ʧ�ܡ�
 */
VMINT vm_sal_cell_reg_req(void);

/**
 * ȡ��CELL��Ϣ��ע�ᣬ�ͷ��ڴ档
 */
void vm_sal_cell_dereg_req(void);

/**
 * ��ȡ��ǰС������Ϣ��
 *
 * @return	����ָ��ǰС����Ϣ�Ľṹ��ָ�롣
 */
vm_cell_info_struct* vm_sal_cell_get_cur_cell_info(void);

/**
 * ��ȡ����С������Ϣ��
 *
 * @return	����ָ������С���Ľṹ��ָ���ָ�롣��ָ��ָ��һ�����飬����
 *			��ÿһ����ָ��һ������С���Ľṹ��ָ�롣
 */
vm_cell_info_struct** vm_sal_cell_get_nbr_cell_info(void);

/**
 * ��ȡ��ǰС��������С����Ŀ��
 *
 * @return	��ǰС��������С����Ŀ�����ĵ�ַ��
 */
VMINT* vm_sal_cell_get_nbr_num(void);

#ifdef __cplusplus
}
#endif 
#endif

