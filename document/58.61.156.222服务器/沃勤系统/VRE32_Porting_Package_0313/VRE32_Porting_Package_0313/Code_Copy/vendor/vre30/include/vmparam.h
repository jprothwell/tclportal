/*****************************************************************************
 *
 * 系统配置参数管理模块。VRE的配置参数存储在配置文件内，配置管理模块首先搜索存储卡上
 * 是否存在配置文件，如果没有再搜索内置文件系统，找到后将所有配置参数读入内存，系统内
 * 其他模块可以通过接口函数读写系统配置参数。
 *
 * $Author: guangyu.tang $
 * $Date: 2008/03/25 09:50:07 $
 *
 ****************************************************************************/

#ifndef VMPARAM_H
#define VMPARAM_H

#ifdef __cplusplus
extern "C" {
#endif

#include "vmlog.h"
#include "vmsock.h"

#define SYS_MEM_POOL_SIZE		(100 * 1024)
#define APP_MEM_POOL_SIZE		(700 * 1024)
#define CURRENT_APN				VM_TCP_APN_CMWAP
#define LOG_LEVEL				VM_ERROR_LEVEL

/**
 * 系统配置参数表。
 */
typedef struct _vm_sys_cfg_t {
	/*
	 * 系统内存池容量，如果没有配置默认是100K。
	 */
	VMINT sys_mem_pool_size;

	/*
	 * 应用程序内存池容量，如果没有配置默认是700K。
	 */
	VMINT app_mem_pool_size;

	/*
	 * 默认的网络承载类型，1为CMWAP，2为CMNET，没有配置则为CMWAP。
	 */
	VMINT current_apn;

	/*
	 * 日志输出级别：1-Fatal, 2-Error, 3-Warning, 4-Info, 5-Debug，没有配置则为Error。
	 */
	VMINT log_level;
} vm_sys_cfg_t;

/**
 * 获得系统配置参数。
 *
 * @return			系统配置参数结构指针。
 */
const vm_sys_cfg_t* vm_get_sys_cfg(void);

#ifdef __cplusplus
}
#endif

#endif