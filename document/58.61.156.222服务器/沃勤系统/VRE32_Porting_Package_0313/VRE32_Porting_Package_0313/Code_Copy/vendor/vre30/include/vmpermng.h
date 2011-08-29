#ifndef		_VM_PER_MNG_
#define		_VM_PER_MNG_

#include "vmsys.h"

#include "vmperdef.h"

#include "vmnvram.h"


/**
 * 获取接口指针。
 *
 * @param func_name				接口名。
 * @return								接口函数入口地址，失败返回0值。
 */
VMINT vm_per_get_fun_prt( VMINT * fun_list, VMCHAR * func_name );


/**
 * 初始化沙箱系统。
 *
 * @param
 * @return								成功时返回0，失败返回负值。
 */
VMINT vm_per_init( void );


/**
 * 结束沙箱系统。
 *
 * @param
 * @return								成功时返回0，失败返回负值。
 */
VMINT vm_per_finalize( void );


/**
 * 根据应用程序的授权建立函数入口列表。
 *
 * @param app_per					应用程序的授权缓冲
 * @param app_per					应用程序的授权长度 
 * @return								成功时返回0，失败返回负值。
 */
VMINT vm_per_catch_fun_list( VMINT * app_per, VMINT app_per_len );

#endif