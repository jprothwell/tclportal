#ifndef VMTIMER_H_
#define VMTIMER_H_

#include "vmsys.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
	
	VM_TIMER_MTK_TIMER_NO_FREE = -5,
	VM_TIMER_ERROR_OF_PROCESS,
	VM_TIMER_ERROR_OF_RES ,
	VM_TIMER_ERROR_OF_MEM ,
	VM_TIMER_ERROR ,
	VM_TIMER_OK
} vm_timer_error_t;

typedef void (*VM_TIMERPROC_T)(VMINT tid);

/**
 * 创建定时器。
 * 当定时器被成功创建后，系统会定时回调定时器处理函数直到程序员
 * 调用vm_delete_timer()删除定时器为止。当程序退出时，程序员必须删除程序所
 * 创建的所有定时器。
 *
 * 该类定时器将在手机背光灯关闭状态下进入休眠状态(运行缓慢)。
 *
 * 对于一个应用程序来说，此类定时器最多支持10个同时工作。
 *
 * @param millisec		定时器超时时间，以毫秒为单位。
 * @param timerproc		定时器超时后的回调函数。
 *
 * @return				返回非负数表示定时器ID，返回负数表示失败。
 */
VMINT vm_create_timer(VMUINT32 millisec, VM_TIMERPROC_T timerproc);

/**
 * 删除由vm_create_timer创建的定时器。
 *
 * @param timerid		定时器标识号。
 *
 * @return				返回0表示成功，负数为失败。
 */
VMINT vm_delete_timer(VMINT timerid);

/**
 * 创建定时器。
 * 当定时器被成功创建后，系统会定时回调定时器处理函数直到程序员
 * 调用vm_delete_timer_ex()删除定时器为止。当程序退出时，程序员必须删除程序所
 * 创建的所有定时器。
 *
 * 该定时器只在背光关闭的情况下也可以正常工作。
 *
 * 对于一个应用程序来说，此类定时器最多支持10个同时工作。
 *
 * @param millisec		定时器超时时间，以毫秒为单位。
 * @param timerproc		定时器超时后的回调函数。
 *
 * @return				返回非负数表示定时器ID，返回负数表示失败。
 */
VMINT vm_create_timer_ex(VMUINT32 millisec, VM_TIMERPROC_T timerproc);


/**
 * 删除由vm_create_timer_ex创建的定时器。
 *
 * @param timerid		定时器标识号。
 *
 * @return				返回0表示成功，负数为失败。
 */
VMINT vm_delete_timer_ex(VMINT timerid);


#ifdef __cplusplus
}
#endif

#endif