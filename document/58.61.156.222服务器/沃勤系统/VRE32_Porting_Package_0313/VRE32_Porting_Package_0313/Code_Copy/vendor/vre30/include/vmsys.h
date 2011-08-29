#ifndef VMSYS_H_
#define VMSYS_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef NULL
#define NULL 0
#endif

//正常启动VRE 环境
#define VM_NORMAL_START_VRE_ENV 1

enum {
	ASM_VMAN_ON,//全部从ASM分配，VM_MEMORY_ACCORDING_NEED开启(保护用，防止误开此宏)
	ASM_VMAN_OFF,//全部从ASM分配，VM_MEMORY_ACCORDING_NEED关闭(正常情况)
	MEDIABUF_VMAN_ON,//使用media buffer, VM_MEMORY_ACCORDING_NEED开启(正常情况)
	MEDIABUF_VMAN_OFF//使用media buffer, VM_MEMORY_ACCORDING_NEED关闭(正常情况)
};
//内存按需分配
//#define VM_MEMORY_ACCORDING_NEED

typedef unsigned char VMUINT8;
typedef unsigned short VMUINT16;
typedef unsigned int VMUINT;
typedef unsigned long VMUINT32;

#ifndef WIN32
typedef  unsigned long long VMUINT64 ;
#else
typedef  unsigned long VMUINT64;
#endif

typedef char VMINT8;
typedef short VMINT16;
typedef int  VMINT;
typedef long  VMINT32;

typedef VMUINT8 VMUCHAR;
typedef VMUINT16 VMUWCHAR;
typedef VMUINT8 * VMUSTR;
typedef VMUINT16 * VMUWSTR;

typedef VMINT8 VMCHAR;
typedef VMINT16 VMWCHAR;
typedef VMINT8 * VMSTR;
typedef VMINT16 * VMWSTR;

typedef unsigned char VMBYTE;
typedef unsigned short VMUSHORT;
typedef short VMSHORT;

typedef VMINT VMFILE;

#include "vmtimer.h"

typedef struct vm_time_t {
	VMINT year;		/* 年份。			*/
	VMINT mon;		/* 月份，从1开始。	*/
	VMINT day;		/* 天，从1开始。	*/
	VMINT hour;		/* 小时，24小时制。	*/
	VMINT min;		/* 分钟。			*/
	VMINT sec;		/* 秒。				*/
} vm_time_t;

/**
 * 获得当前系统时间。
 *
 * @param time			指向结果的vm_time_t指针。
 *
 * @return				返回0表示成功，否则为失败。
 */
VMINT vm_get_time(vm_time_t* time);

/**
 * 内存分配的统计结果。
 */
typedef struct malloc_stat_t {
	/**
	 * 内存分配函数的总调用次数，包括vm_malloc()、vm_realloc()、
	 * vm_calloc()。
	 */
	VMINT malloc_count;

	/**
	 * 内存释放函数的总调用次数。
	 */
	VMINT free_count;

	/**
	 * 当前内存占用量。
	 */
	VMINT current;

	/**
	 * 最大内存占用量。
	 */
	VMINT peak;

	/**
	 * 内存分配失败次数。
	 */
	VMINT fail_times;

	/**
	 * 最大内存分配失败的块。
	 */
	VMINT max_fail_size;

	/**
	 * 当前剩余堆的容量。
	 */
	VMINT avail_heap_size;
} malloc_stat_t;


/**
 * 获得当前内存管理子系统的统计数据。当分区内存管理功能启用后，返回
 * 激活分区的内存统计数据。
 */
malloc_stat_t* vm_get_malloc_stat(void);

/**
 * 分配内存。
 *
 * @param size			要分配的字节数。
 *
 * @return				新分配到的内存指针，返回NULL表示分配失败。
 */
void *vm_malloc(int size);

/**
 * 分配内存，并且将新分配到的内存清0。
 *
 * @param size			要分配的字节数。
 *
 * @return				返回分配到的内存指针，返回NULL表示分配失败。
 */
void *vm_calloc(int size);

/**
 * 重新分配内存，如果给定的内存长度小于原有内存长度，系统不做任何
 * 操作，否则把给定的内存扩大到给定长度，内存中的数据继续保留。
 *
 * @param p				要重新分配的内存指针。
 * @param size			新的长度。
 *
 * @return				返回NULL表示重新分配失败，给定的内存指针
 *						指向的内存不释放，否则返回扩展后的内存
 *						指针。
 */
void *vm_realloc(void* p, int size);

/**
 * 释放内存。
 *
 * @param ptr			被释放的内存指针，必须由vm_malloc()所分配。
 */
void vm_free(void* ptr);


 /**
 * 这是基于VRE的程序入口函数，应用程序必须实现。
 */
void vm_main(void);

/**
 * 要求重新绘制VRE用户界面。
 */
#define VM_MSG_PAINT			1

/**
 * VRE从非激活状态切换为激活状态。
 */
#define VM_MSG_ACTIVE			2

/**
 * VRE从激活状态切换到非激活状态。
 */
#define VM_MSG_INACTIVE		3

/**
 * VRE被创建。
 */
#define VM_MSG_CREATE			4

/**
 * VRE序退出。
 */
#define VM_MSG_QUIT			5

/**
 * VRE 程序被切换到后台运行的消息。
 */
#define VM_MSG_HIDE			6

/**
 * VRE 程序可以翻转屏幕的消息。 还会发过来 建议VRE程序屏幕翻转的角度
 */
#define VM_MSG_SCREEN_ROTATE		7

/**
 * 系统HIDE或PAINT事件产生原因的类型定义。
 */
enum {
	SCREEN_POPUP = 0, 	/* HIDE或PAINT事件由屏幕POPUP行为，如电话、短信、输入法界面等导致 */
	USER_END_KEY		/* HIDE事件由用户按挂机键导致 */
};

/**
 * 系统事件参数数据结构。
 */
typedef struct _vm_sysevt_param_t
{
	VMINT evt_cause; 	/* 事件发生原因 */
	void * evt_detail; 	/* reserved */
} vm_sysevt_param_t;

/**
 * 注册系统事件回调函数。
 */
void vm_reg_sysevt_callback(void (*f)(VMINT message, VMINT param));

/**
 * 退出VRE应用程序，这个函数只能由动态装入的VRE应用程序所调用，BUILTIN的程序不应调用
 * 这个函数。函数被调用后，当前被执行的VRE应用程序所占用的内存会被立即释放，随后返回
 * VRE应用程序管理器，应用程序自己申请的内存和资源必须由应用程序自行释放。
 */
void vm_exit_app(void);

/**
 * 退出应用程序并由应用程序管理器完成升级请求，
 * 这个函数只能由动态装入的VRE 应用程序调用。在调用本函
 * 数前应用程序必须释放占用的内存与资源，在调用完本函数
 * 后应用程序不应该再执行任何代码。
 */ 
void vm_exit_and_update_app(void);

/**
 * 获得系统启动到现在流经的毫秒数，计数精度在不同平台上可能会有所不同。
 *
 * @return			系统启动到现在经过的毫秒数。
 */
VMINT vm_get_tick_count(void);

/**
 * 获得当前执行程序的文件名。
 *
 * @param filename			保存执行程序名称的UCS2字符串数组。
 *
 * @return					返回0表示操作成功，结果保存在filename中，
 *							否则返回错误码，表示当前处于内核态，没有应用
 *							程序在运行。
 */
VMINT vm_get_exec_filename(VMWSTR filename);

/**
 * VRE_SYS_SUBSCRIBER_ID 
 * VRE用户ID号，值是一个长度最大为20个VMCHAR的字符串。例如：100973
 * 
 * VRE_SYS_EQUIPMENT_ID 
 * VRE系统的USER AGENT，值是一个长度最大为20个VMCHAR的字符串。例如：Gionee-A10
 * 
 * VRE_SYS_VERSION 
 * VRE版本号，值是一个长度最大为12个VMCHAR的字符串，VRE
 * 版本号的命名规则为<主版本号>.<子版本号>.<发布号>
 * 例如：1.2.6
 * 
 * VRE_SYS_HOST_VERSION
 * 宿主平台版本号，值是一个长度最大为30个VMCHAR的字符串。例如MT6225_08A_VERSION。
 *
 * VRE_SYS_HOST_MAX_MEM
 * 宿主平台分配给VRE的最大内存，值是一个长度最大为6个VMCHAR的字符串，该
 * 串为全数字，可以用atoi函数转成数值类型，单位为KB。该内存是VRE系统内存
 * 和用户内存的总和。
 * 例如：800
 * 
 * VRE_SYS_HOME_DIR
 * 得到VRE系统的HOME路径，该路径是一个长度最大30个VMCHAR的字符串。
 * HOME路径不以文件分隔符结尾。
 * 例如：C:\VRE
 */
#define VRE_SYS_SUBSCRIBER_ID		(1)
#define VRE_SYS_EQUIPMENT_ID		(2)
#define VRE_SYS_VERSION			(3)
#define VRE_SYS_HOST_VERSION		(4)
#define VRE_SYS_HOST_MAX_MEM		(5)
#define VRE_SYS_HOME_DIR			(6)

/**
 * 得到VRE的系统属性，属性的定义为关键字(key)和值(value)的一组数据。VRE的系统属性
 * 是VRE内部维护的，程序无法对其更改或删除。调用的程序示例如下：
 * VMCHAR value[20] = {0};
 * VMUINT valueNum = vm_get_sys_property(VRE_SYS_SUBSCRIBER_ID, value, 20);
 *
 * @param key				需要取得VRE系统属性的关键字。			
 * @param value				指向一段连续内存，在本函数的实现里会把得到的
 *							值写到该指针指向的内存区域内。如果该指针指向
 *							NULL(0地址)，那么在函数内不会有写入字符的操作。
 * @param len				value指针指向连续内存最多能够存放VMCHAR类型元素的个数。
 *							如果该实参是12，但是实际的值只有10个VMCHAR类型，那么
 *							函数内会在最后第11个位置写入0x00;如果值刚好是12个，那么
 *							将不会写入0x00;如果值的长度大于12，那么只会写入前12个字符
 *							到value指向的内存区域内。
 * 
 * @return					实际写入的值的长度，不算最后的写入的0x00。
*/
VMUINT vm_get_sys_property(const VMINT key, VMCHAR* value, VMUINT len);

/**
 * 获取当前城市时区的时差。
 *
 * @return	返回GMT时差值。
 */
float vm_get_sys_time_zone(void);

/**
 * 获取手机情景模式。
 *
 * @return	返回0表示标准模式，返回1表示会以模式，返回2表示户外模式，
 *			返回3表示室内模式，返回4表示耳机模式，返回5表示静音模式，
 *			返回6表示蓝牙模式。
 */
VMINT vm_get_sys_scene(void);

/**
 * 获取手机电池电量。
 *
 * @return	如果分四个等级，则返回值为0，25，50，75，100其中一个。
 *			如果分三个等级，则返回值为0，33，66，100其中一个。
 */
VMINT vm_get_battery_level(void) ;

/**
 * @name vm_switch_power_saving_mode函数的参数。
 */
typedef enum {
	turn_on_mode = 0, 				/**<打开节电模式 */
	turn_off_mode					/**<关闭节电模式 */
} power_saving_mode_enum;

/**
 * 设置节电模式，如果应用关闭了节电模式，屏幕将常亮。应用只能在前台运行时
 * 调用本函数，VRE初始的状态始终为打开了节电模式，应用被切换到后台或退出前
 * 都应该打开节电模式。
 * 
 * @param[in]			mode turn_on_mode表示打开节电模式，turn_off_mode表示关闭节电模式。
 * @return			0 表示设置成功，否则返回错误码。
 */
VMINT vm_switch_power_saving_mode(power_saving_mode_enum mode);


#ifdef __cplusplus
}
#endif 

#endif 
