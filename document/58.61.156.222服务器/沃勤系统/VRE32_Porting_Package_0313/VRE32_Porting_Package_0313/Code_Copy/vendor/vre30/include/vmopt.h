#ifndef VRE_OPTIONS_H_
#define VRE_OPTIONS_H_

#ifdef __cplusplus 
extern "C" {
#endif
#include "vmsys.h"
#include "vmmem.h"

/* --------------------------- VRE ---------------------------------- */

/**
 * 根据MTK的宏定义VRE双卡宏。
 */ 
#ifdef __MMI_DUAL_SIM_MASTER__
#ifndef VRE_DUAL_SIM
	#define VRE_DUAL_SIM
#endif
#endif

/**
 *	内置游戏个数
 */
#define VRE_BUILDIN_APP_COUNT 					(2)

/*
 * 如果定义则VRE 用ASM内存，否者使用Media内存。
 */
#ifndef  __VRE_MEDIA_BUF__
	#define VRE_SUPPORT_ASM_MEMPOOL
#endif

/*
 * 如果支持认证和沙箱则该宏应该被打开，否则关闭。
 */
#define VRE_SUPPORT_SECURITY_FEATURE

/*
 * 如果是测试后台则该宏应该被打开，否则关闭。
 */
//#define __VRE_TEST_SERVER__

/*
 * 如果支持通过IMEI号进行SDK开发认证将打开，否则用IMSI号认证。
 */
//#define VRE_SUPPORT_CERT_SDK_BY_IMEI

/* 
 * 以下的10, 11, 12, 13需要根据默认的ID定义。 
 */
/*
 * 默认的移动CMWAP联网帐号ID。
 */
//#define CMWAP	(vm_get_account_id(10))

/*
 * 默认的移动CMNET联网帐号ID。
 */
//#define CMNET	(vm_get_account_id(11))

/**
 * 默认的联通UNIWAP联网帐号ID。
 */
//#define UNIWAP	(vm_get_account_id(12))

/**
 * 默认的联通UNINET联网帐号ID。
 */
//#define UNINET	(vm_get_account_id(13))

/*
 * 如果定义则VRE 用静态内存，否者使用动态内存。
 */
//#define VRE_SUPPORT_BUILTIN_MEMPOOL

/*
 * 如果定义则支持VRE 按挂机键退出，不定义则不支持。
 */
//#define VRE_SUPPORT_END_KEY_EXIT			

/*
 * 如果定义则支持触摸屏，否者不支持。
 */
#ifdef __MMI_TOUCH_SCREEN__
#ifndef VRE_SUPPORT_SCREEN_TOUCH
#define VRE_SUPPORT_SCREEN_TOUCH
#endif
#endif

/*
 * 如果定义则支持全键盘，否则不支持。
 */
#if defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
#ifndef VRE_SUPPORT_TOTAL_KEYPAD
#define VRE_SUPPORT_TOTAL_KEYPAD
#endif
#endif

/*
 * 是否支持摄像头功能, 注释掉则表示不支持.
 */
#if defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__)
#ifndef VRE_SUPPORT_CAMERA_FEATURE
#define VRE_SUPPORT_CAMERA_FEATURE
#endif
#endif

/*
 * 如果定义则每次启动VRE 的时候都读取一遍sim卡上信息，否者
 * 只有在第一次的启动VRE 时候才读取。
 */
#define VRE_SUPPORT_GET_SIM_INFO_PER_RUNING

/*
 * 如果定义则支持在VRE 里调用系统的WAP浏览器，否者则不支持。
 */
#ifdef WAP_SUPPORT
#define VRE_SUPPORT_OPEN_WAP_BROWSER
#endif

/*
 * 是否支持集成外部传感器,打开本宏表示支持,否则不支持.
 */
#define VRE_SUPPORT_INTEGRATE_EXTERNAL_SENSOR

/*
 * VRE是否支持选卡的功能。打开该宏表示支持，否者为不支持。
 */
//#define VRE_SUPPORT_SELECT_SIM_CARD

/*
 * VRE系统内存值的尺寸，单位是字节,默认是600K。
 * 根据平台分别适配6225:819200; 6235:1572864; 6238:2097152
 */
#define VRE_SYS_MEMPOOL_SIZE (VRE_SYS_MEMORY_SIZE << 10)

/*
 * 如果没有定义AM，则把AM使用的内存定义成0。
 */
#if (!defined(MMI_AM_USING_VRE_MEM) || !defined(__VRE30_AM__))
#define VRE_AM_MAX_DYN_MEM_SIZE 			(0)
#else
#define VRE_AM_MAX_DYN_MEM_SIZE  			MMI_AM_MAX_DYN_MEM_SIZE
#endif

/*
 * 使用Media Buffer或ASM用到宏定义。
 */
#ifdef __VRE_MEDIA_BUF__
  #if (!defined(MMI_AM_USING_VRE_MEM) || !defined(__VRE30_AM__))
    #define VRE_SYS_ASM_MEMPOOL_SIZE			(0)
  #else
    #define VRE_SYS_ASM_MEMPOOL_SIZE			(0 + MMI_AM_MAX_DYN_MEM_SIZE)
  #endif
  #define VRE_SYS_MED_MEMPOOL_SIZE			(VRE_SYS_MEMPOOL_SIZE + VRE_30_KERNEL_MEM_SIZE)
#else
  #if (!defined(MMI_AM_USING_VRE_MEM) || !defined(__VRE30_AM__))
    #define VRE_SYS_ASM_MEMPOOL_SIZE			(VRE_SYS_MEMPOOL_SIZE + VRE_30_KERNEL_MEM_SIZE)
  #else
    #define VRE_SYS_ASM_MEMPOOL_SIZE			(VRE_SYS_MEMPOOL_SIZE + VRE_30_KERNEL_MEM_SIZE + MMI_AM_MAX_DYN_MEM_SIZE)
  #endif
  #define VRE_SYS_MED_MEMPOOL_SIZE			(0)
#endif

/*
  * VRE系统版本号。
  */
#define VRE_SYS_VRESION_NUMBER							"3.2.0"

/*
 * VRE 支持的最大的打开文件的句柄。
 */
#define VRE_SUPPORT_FILE_HANDLE_MAX_NUM					(12)

/*
 * VRE 支持的最大的TCP 上下文。
 */
#define VRE_SUPPORT_TCP_CONTEXT_MAX_NUM					(3)

/*
 * 系统盘重定向特性，打开后除了落在白名单内的文件，其余向系统盘写入的
 * 文件都会被重定向到存储卡上。
 */
/* #define VRE_SYS_DRIVER_REMAPPING */

/*
 * 开启内存分区功能，把内核和用户内存分区管理。必须打开。
 */
#define VRE_MEMORY_PARTITION

/*
 * 字符宽度补偿，像素单位。当系统返回的字符高度参数和实际不符时，通过
 * 这个参数补足。 
 */
#define VRE_CHAR_H_PADDING								(0)

/*
 * 字符高度补偿，像素单位。当系统返回的字符高度参数和实际不符时，通过
 * 这个参数补足。
 */
#define VRE_CHAR_V_PADDING								(0)

/*
  * 把系统信息输出到屏幕
  */
//#define VM_OUTPUT_MEM_STATE	

/**
 * VRE 是否支持SCREEN GROUP的机制.
 */
#if !defined(__VRE_RB_09A__)
#define VRE_SUPPORT_SCREEN_GROUP_FRAMEWOK
#endif

/*
 * 是否支持在VRE应用程序运行时来新短信只有提示音而没有弹出窗口，在运行音频，视频，录音时，没有提示音没有弹出窗口
 */
//#define     VM_SUPPORT_SMS_NO_POPUP

/**
 * 平台的文件管理器中启动VREApp的回调函数。
 * @param 			path VREApp的文件名，带全路径。
 * @param 			is_short	
 */
void vm_open_vre_exec_file_callback(const VMWSTR path, VMINT is_short);

/**
 * 通知VRE 进入USB模式。
 */
void mmi_vre_enter_usb_mode(void);

/**
 * 通知VRE 退出了USB模式。
 */
void mmi_vre_exit_usb_mode(void);

/**
 * 拔出T卡的处理。
 */
void mmi_vre_card_plug_out_hdlr(void);

/**
 * 是否允许格式化指定的磁盘。
 */
VMINT  mmi_vre_pre_format_hdlr(VMINT8 drv);

#ifdef __cplusplus
}
#endif

#endif
