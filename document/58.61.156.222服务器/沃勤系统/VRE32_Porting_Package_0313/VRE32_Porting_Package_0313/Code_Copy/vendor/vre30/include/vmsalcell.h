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
 * 注册CELL消息，分配内存。
 *
 * @return	返回VM_SAL_CELL_REG_SUCCESS表示注册成功，返回VM_SAL_CELL_REG_CUR_MALLOC_FAILED
 *			表示分配当前小区内存失败，返回VM_SAL_CELL_REG_NBR_MALLOC_FAILED表示分配
 *			相邻小区内存失败，返回VM_SAL_CELL_REG_ILM_MALLOC_FAILED表示分配发送消息
 *			内存失败。
 */
VMINT vm_sal_cell_reg_req(void);

/**
 * 取消CELL消息的注册，释放内存。
 */
void vm_sal_cell_dereg_req(void);

/**
 * 获取当前小区的信息。
 *
 * @return	返回指向当前小区信息的结构体指针。
 */
vm_cell_info_struct* vm_sal_cell_get_cur_cell_info(void);

/**
 * 获取相邻小区的信息。
 *
 * @return	返回指向相邻小区的结构体指针的指针。该指针指向一个数组，数组
 *			中每一项是指向一个相邻小区的结构体指针。
 */
vm_cell_info_struct** vm_sal_cell_get_nbr_cell_info(void);

/**
 * 获取当前小区的相邻小区数目。
 *
 * @return	当前小区的相邻小区数目变量的地址。
 */
VMINT* vm_sal_cell_get_nbr_num(void);

#ifdef __cplusplus
}
#endif 
#endif

