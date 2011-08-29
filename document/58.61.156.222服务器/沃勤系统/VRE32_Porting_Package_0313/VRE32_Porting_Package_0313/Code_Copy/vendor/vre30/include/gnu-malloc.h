#ifndef GNU_MALLOC_H
#define GUN_MALLOC_H

#ifdef __cplusplus 
extern "C" {
#endif

#include "vmsys.h"

/**
 * 初始化内存池，与拥有大量内存的PC不同，嵌入系统通常都拥有有限的内存，而且
 * 其标准C库能够从堆中分配的内存大小也可能受限，因此嵌入系统通常都分配一块
 * 固定大小的内存给应用程序，由应用程序自行管理。初始化动作必须在执行任何内
 * 存分配和释放之前调用。
 *
 * @param pool_base		内存池的起始地址。
 * @param pool_size		内存池的长度，以字节为单位。
 */
void gnu_malloc_init(VMUINT8* pool_base, int pool_size);

/**
 * 从内存池中分配给定大小的一块内存。
 *
 * @param n				内存大小，以字节为单位。
 *
 * @return				分配到的内存地址，返回NULL表示分配失败。
 */
VMUINT8* gnu_malloc(VMUINT n);

/**
 * 扩展内存到指定长度，如果给定长度小于给定内存块的长度则不做任何
 * 操作。
 */
VMUINT8* gnu_realloc(VMUINT8* p, VMUINT n);

/**
 * 释放内存，通过gnu_malloc分配的内存只能够释放一次，多次释放会导致无法预料
 * 的后果。
 *
 * @param mem			要释放的内存起始地址。
 */
void gnu_free(VMUINT8* mem);

/**
 * 获得已经使用的内存数量，以字节为单位。
 */
VMINT gnu_malloc_mem_used(void);

/**
 * 获得空闲的内存数量，以字节为单位。
 */
VMINT gnu_malloc_mem_free(void);

#ifdef __cplusplus
}
#endif

#endif
