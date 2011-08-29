#ifndef VMTEL_H
#define VMTEL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"


typedef enum
{
	VM_CALLOUT_ERR_STATE = -7,	 /*非前台状态*/
	VM_CALLOUT_ERR_NO_SIM ,	 	/*无sim卡*/
	VM_CALLOUT_ERR_FLIGHT, 		/*飞行模式*/
	VM_CALLOUT_ERR_BUSY,			/*设备正忙*/
	VM_CALLOUT_ERR_PHONE_NUM,	/*号码错误*/
	VM_CALLOUT_ERR_PROCESS,		/*进程错误*/
	VM_CALLOUT_ERR_NO_RES,		/*未申请到资源*/
	VM_CALLOUT_NO_ERR
}vm_callout_error_t;

typedef enum
{
	VM_CALLOUT_IDEL = 0,
	VM_CALLOUT_BUSY
}vm_callout_status_t;

/*
 * 电话回调函数类型定义
 *
 * 参数一为电话好号码
 * 参数二为返回拨打结果
 */
typedef void (*VM_CALLOUT_RESPONSE_T)(VMWSTR, VMINT);

/**
 * 电话呼出。
 * 
 * 多进程模式下说明：
 * 当进程在后台运行，无法拨打电话。
 * 前台进程可以拨打电话，当通过endkey切换到后台后，endkey将先相应电话界面，做挂机操作。
 *
 * @param phnum			UCS2编码格式的手机号码。
 */
void vm_callout(VMWSTR phnum);

/**
 * 电话呼出。
 * 
 * 多进程模式下说明：
 * 当进程在后台运行，无法拨打电话。
 * 前台进程可以拨打电话，当通过endkey切换到后台后，endkey将先相应电话界面，做挂机操作。
 *
 * @param phnum			UCS2编码格式的手机号码。
 * @param callback		回调函数。
 *
 * @return	电话呼出的结果，返回值请参考vm_callout_error_t。
 *			正确返回VM_CALLOUT_NO_ERR，负值为错误码。
 */
VMINT vm_callout_ex(VMWSTR phnum, VM_CALLOUT_RESPONSE_T callback);

/**
 * 短消息发送成功。
 */
#define VM_SMS_RESULT_OK			1

/**
 * 短消息发送失败。
 */
#define VM_SMS_RESULT_ERROR			2

/**
 * 主动取消短消息发送
 */
#define VM_SMS_RESULT_ABORT			3

/**
 * 发送短消息。
 *
 * @param phone_number		目标手机号码。
 * @param content			短消息内容。
 * @param callback			回调函数。
 * @return     				TRUE=发送短信请求成功，FALSE=发送短信请求失败。
 * @see						vm_cancel_send_sms
 */
VMINT vm_send_sms(VMWSTR phone_number, VMWSTR content, void (*callback)(VMINT result));

/**
 * 取消短消息的发送，如果之前没有调用vm_send_sms则调用本函数将没有作用。如果注册到vm_send_sms
 * 里的函数已经回调，则执行本函数也没有任何作用。只有在调用vm_send_sms后，并且返回成功，在
 * 回调函数里没有被系统调回才能调用本函数。
 *
 * @see						vm_send_sms
 */
void vm_cancel_send_sms(void);

/**
 * vm_open_wap_url 的函数返回值。
 * @{
 */
/**
 * 打开浏览器成功。
 */
#define VM_OPEN_WAP_URL_SUCCESS				(0)
/**
 * 参数错误。
 */
#define VM_OPEN_WAP_URL_ERROR_PARAM			(-1)
/**
 * 手机在当前状态下WAP服务不可用。
 */
#define VM_OPEN_WAP_URL_NO_SERVICE			(-2)
/**
 * 进程在当前状态下无法打开浏览器。
 */
#define VM_OPEN_WAP_URL_ERROR_STATUS		(-3)
/** @} */

/**
 * 打开WAP浏览器并转到相应的地址，本函数只能在进程处在前台状态下才能调用。
 *
 * @param url					WAP地址。
 * @return					打开流程器是否成功。
 * @retval					VM_OPEN_WAP_URL_SUCCESS 打开WAP流程器成功。
 * @retval					VM_OPEN_WAP_URL_ERROR_PARAM 参数错误，打开浏览器失败。
 * @retval					VM_OPEN_WAP_URL_NO_SERVICE 当前浏览器不可用。
 * @retval					VM_OPEN_WAP_URL_ERROR_STATUS 如果进程不在前台调用本函数，则返回失败。
 */
VMINT vm_open_wap_url(VMWSTR url);

#ifdef __cplusplus
}
#endif

#endif
