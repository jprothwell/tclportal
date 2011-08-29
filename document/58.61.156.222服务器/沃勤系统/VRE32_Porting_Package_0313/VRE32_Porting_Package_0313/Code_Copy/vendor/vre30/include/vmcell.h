#ifndef VMCELL_H_
#define VMCELL_H_

#include "vmsys.h"

#ifdef __cplusplus
extern "C" {
#endif

/*cell信息的结构体。*/
typedef struct{
    VMUINT16 arfcn;           /*信道编号。*/
    VMUINT8 bsic;              /*基站标识码。*/
    VMUINT8 rxlev;            /*接收强度等级。*/
    VMUINT16 mcc;            /*国家代码。*/
    VMUINT16 mnc;            /*网络代码。*/
    VMUINT16 lac;              /*区域代码。*/
    VMUINT16 ci;                /*小区标识符。*/
}vm_cell_info_struct;

/*CELL注册状态。*/
typedef enum{
	VM_CELL_OPEN_REG_ERROR = -2,		/*CELL消息注册错误。*/
	VM_CELL_OPEN_RES_LESS = -1,		/*缺少资源。*/
	VM_CELL_OPEN_SUCCESS = 0,			/*打开成功。*/
	VM_CELL_OPEN_ALREADY_OPEN = 1	/*已经打开。*/	
	
	
} vm_cell_reg_state_enum;

/**
 * 开启CELL。
 *
 * @return	返回VM_CELL_OPEN_SUCCESS表示打开成功，返回VM_CELL_OPEN_ALREADY_OPEN
 * 			表示已经打开，返回VM_CELL_OPEN_RES_LESS表示缺少资源，返回
 *			VM_CELL_OPEN_REG_ERROR表示注册CELL消息失败。
 */
VMINT vm_cell_open(void);

/**
 * 关闭CELL。
 */
void vm_cell_close(void);

/**
 * 获得当前小区信息。调用此函数之前一定要调用vm_cell_open函数，否则返
 * 回的是空指针NULL。
 *
 * @return	如果调用过vm_cell_open函数，则返回指向当前小区信息结构体的指
 *			针，否则返回空指针NULL。
 */
vm_cell_info_struct* vm_cell_get_cur_cell_info(void);

/**
 * 获得相邻小区信息。调用此函数之前一定要调用vm_cell_open函数，否则返
 * 回的是空指针NULL。
 *
 * @return	如果调用过vm_cell_open函数，则返回指向当前小区信息结构体数组
 *			的指针，否则返回空指针NULL。
 */
vm_cell_info_struct** vm_cell_get_nbr_cell_info(void);

/**
 * 获得当前小区的相邻小区数目。调用此函数之前一定要调用vm_cell_open函
 * 数，否则返回的是空指针NULL。
 *
 * @return	如果调用过vm_cell_open函数，则返回当前小区的相邻小区数目变量
 *			的地址，否则返回空指针NULL。
 */
VMINT* vm_cell_get_nbr_num(void);

#ifdef __cplusplus
}
#endif 
#endif

