#ifndef VMMEM_H
#define VMMEM_H

#include "vmsys.h"

#ifdef __cplusplus 
extern "C" {
#endif

/************************************************************************
 *
 *
 *
 * VRE 3.0 核心分配CORE内存的函数，这些函数不对APP 开放。
 *
 *
 *
 ************************************************************************/
/**
 * VRE需要统计内存次数。
 */
#define VRE_ENABLE_MEM_DEBUG

/**
 * 是否使用DL算法管理HEAP 内存,打开为使用,否则为不使用.
 */
#define VRE_ENABLE_DL_HEAP_MANAGER

/**
 * VRE Kernel的内存大小，单位为字节。
 */
#define VRE_30_KERNEL_MEM_SIZE					(70 << 10)

/**
 * VRE 2.0里的Kernel内存，单位为字节。
 */
#define VRE_20_KERNEL_MEM_SIZE					(50 << 10)

/**
 * VRE App内存段每一页的大小，单位为字节。
 */
//#define VRE_APP_SEG_MEM_PAGE_SIZE					(200 << 10)//(400 << 10)

/*
 * 应用程序名称。
 */
typedef struct vm_multi_lang_app_name_t {
	VMINT lang_id;								/**<VM_LANG_ENG, VM_LANG_CHS, VM_LANG_CHT 	*/
	VMWSTR app_name;							/**<应用程序文件名称。 				*/
	struct vm_multi_lang_app_name_t *next;			/**<下一类语言的应用程序名称。 	*/
} vm_multi_lang_app_name_t;

/**
 * 内存控制块。
 */
typedef struct vm_mem_control_block_t
{
	VMINT process_handle;
	VMUINT8* mem_base;
    	VMUINT mem_size;
	VMINT hide_flag;
	void (*stop_cb)(void);
	void* adm_id;
	vm_multi_lang_app_name_t* app_name;
#ifdef VRE_ENABLE_MEM_DEBUG
	malloc_stat_t mem_stat;
#endif
} vm_mem_control_block_t;

/**
 * 初始化内存池，这个动作只应该在VRE启动的时候被
 * 调用。
 * 
 * @return			0返回成功否则为失败。
 */
VMINT _vm_init_mem_pool(void);

/**
 * 分配VRE Kernel内存，并且将新分配到的内存清0。
 *
 * @param size			要分配的字节数。
 *
 * @return				返回分配到的内存指针，返回NULL表示分配失败。
 */
void* _vm_kernel_malloc(VMINT size);

/**
 * 重新分配VRE Kernal内存，如果给定的内存长度小于原有内存长度，系统不做任何
 * 操作，否则把给定的内存扩大到给定长度，内存中的数据继续保留。
 *
 * @param p				要重新分配的内存指针。
 * @param size			新的长度。
 *
 * @return				返回NULL表示重新分配失败，给定的内存指针
 *						指向的内存不释放，否则返回扩展后的内存
 *						指针。
 */
void* _vm_kernel_realloc(void* p, VMINT size);

/**
 * 分配分配VRE Kernal内存，并且将新分配到的内存清0。
 *
 * @param size			要分配的字节数。
 *
 * @return				返回分配到的内存指针，返回NULL表示分配失败。
 */
void* _vm_kernel_calloc(VMINT size);

/**
 * 释放VRE Kernel内存。
 *
 * @param ptr			被释放的内存指针，必须由vm_malloc()所分配。
 */
void _vm_kernel_free(void* ptr);

/**
 * 按手机当前的指定语言与传入的APPID，得到应用程序的名称。
 * 
 * 
 * @param[in]				native_app_id 应用程序ID。
 * @param[in]				lang_id 为语言ID 表示为VM_LANG_ENG，VM_LANG_CHS，VM_LANG_CHT。
 */
VMWSTR _vm_get_mem_app_name(VMINT native_app_id, VMINT lang_id);

/*
 * 分配给指定进程的内存空间，本函数只能由进程管理器调用。
 * 
 * @param[in]				processHandle 进程的ID。
 * @param[in]				appName 在内存不足时提示的文件名称。
 * @param[in]				size 需要分配的内存空间的大小，单位为字节。
 * @param[in]				flag TRUE 表示需要隐藏，FALSE表示不需要隐藏。
 */
void* _vm_alloc_app_seg_mem(VMINT processHandle, vm_multi_lang_app_name_t* appName, VMINT size, VMINT hideFlag);

/*
 * 弹出释放内存的弹出框，让用户选择释放内存。
 * 
 * @param[in]				memSize 本次需要分配的内存。
 * @param[in]				successCallback 在用户选择了停止某个应用后，再callback回来的函数。
 * @param[in]				isSysProcess 是否是系统进程。
 */
void _vm_prompt_to_release_mem(VMUINT memSize, void (*successCallback)(void), VMINT isSysProcess);

/**
 * 设置该进程的HEAP区域，本函数只能由进程管理器调用。
 * 
 * @param[in]				processHandle 进程句柄。
 * @param[in]				heapBase 该进程HEAP区域的基址。
 * @param[in]				heapSize 该进程HEAP区域的大小。
 *
 * @return 				0表示设置成功，否则为失败。
 */
VMINT _vm_set_app_heap_attr_mem(VMINT processHandle, VMUINT8* heapBase, VMINT heapSize);

/**
 * 查询 用户进程段里 最多能够装载的用户进程数。
 * 
 * @return 大于等于0的 数。
 */
VMUINT _vm_query_app_num_mem(void);

/**
 * 释放该进程占用的所有内存，本函数只能由进程管理器调用。
 * 
 * @param[in]				processHandle 进程句柄。
 */
void _vm_free_app_seg_mem(VMINT processHandle);

/**
 * 查询用户进程段里最大的连续的空闲内存块的大小。
 * 
 * @return				用户进程段里最大的连续的空闲内存块的大小,
 *						单位为字节。
 */
VMUINT _vm_get_app_seg_free_space(void);

#ifdef __cplusplus
}
#endif

#endif

