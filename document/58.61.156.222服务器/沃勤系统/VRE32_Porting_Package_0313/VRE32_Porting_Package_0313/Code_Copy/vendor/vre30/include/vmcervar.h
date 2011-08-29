#ifndef _VM_CER_VAR_H_
#define	_VM_CER_VAR_H_

#include "vmsys.h"

#include "vmrsa.h"

/**
 * 装载证书系统数据。
 *
 *
 * @return				返回0表示转换成功，负值为失败,内容参见vmcerter.h。
 */
VMINT	vm_ce_load_var( void );


/**
 * 卸载证书系统数据。
 *
 *
 * @return				无返回值
 */
void	vm_ce_unload_var( void );


/**
 * 通过id获得公钥。
 * 
 * @param id				公钥id。
 * @param key_buf		存储公钥的缓冲。
 * 
 * @return					返回0表示解码成功，负数为失败,内容参见vmcerter.h。
 */
VMINT	vm_ce_get_key( VMINT id, VMKey * key_buf );

#endif