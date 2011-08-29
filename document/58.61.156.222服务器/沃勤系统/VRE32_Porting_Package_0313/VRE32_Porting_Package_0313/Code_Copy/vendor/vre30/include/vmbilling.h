/**********************************************************************************
 * 计费相关函数的头文件。计费引擎现只支持CMCC(中国移动)和UNICOM(中国联通)的G网计费，
 * 并且提供保存，扣除，查询已计费信息的功能。
 * 
 * 
 * @author jie.chen@vogins.com
 * @version 1.3.0
 **********************************************************************************/
#ifndef __BILLING_H__
#define __BILLING_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"

/**
 * 应用程序预装在手机里。
 */
#define PAYMENT_APP_SOURCE_FROM_PREINSTALL		(1)

/**
 * 应用程序通过下载得到。
 */
#define PAYMENT_APP_SOURCE_FROM_DOWNLOAD		(2)

/**
 * 异步计费函数返回的状态参数。
 */
typedef VMINT CALLBACK_PAYMENT_STATE;

/**
 * @name vm_quick_charge的异步回调函数的参数。
 * @{
 */
/**
 * 计费成功。
 */
#define PAYMENT_STATE_SUCCESS				(0)
/**
 * 计费失败。 
 */
#define PAYMENT_STATE_FAILED				(-1)

/**
 * 计费被取消。
 */
#define PAYMENT_STATE_CANCEL				(-2)
/** @} */

/**
 * @name 计费模式。
 * @{
 */
/**
 * 按次收费的模式。
 */
#define PAYMENT_MODE_BY_TIME				(1)
/**
 * 按天收费的模式。
 */
#define PAYMENT_MODE_BY_DATE				(2)
/**
 * 买断的模式。
 */
#define PAYMENT_MODE_BY_FOREVER				(3)
/** @} */

/**
 * @name 计费引擎相关的返回码
 */
#define PAYMENT_RET_SUCCESS					(0)
#define PAYMENT_RET_IN_DURABILITY			(1)
#define PAYMENT_RET_NEED_PAYMENT			(2)
#define PAYMENT_ERR_NO_SIM_CARD				(-1)
#define PAYMENT_ERR_LACK_FS_SPACE			(-2)
#define PAYMENT_ERR_WRONG_PARAM				(-3)
#define PAYMENT_ERR_NO_MEM					(-4)
#define PAYMENT_ERR_CURRENT_DATE			(-5)
#define PAYMENT_ERR_NOT_EXISTS_PAYMENT_ID	(-6)
#define PAYMENT_ERR_IO						(-7)
#define PAYMENT_ERR_INTERNAL_ERROR			(-8)
/** @} */

/**
 * @name vm_quick_charge函数返回码。
 * @{
 */
/**
 * 对于免费的计费点将不会触发计费流程，而是直接保存天数和次数。
 * 对于非免费的返回该值将会触发计费流程，在计费成功后才会保存。
 * 购买的天数和次数。
 */ 
#define CHARGE_RET_ACCEPT_CHARGE			PAYMENT_RET_SUCCESS
/**
 * 在没有插SIM卡或未知的运营商该错误也会被返回。
 */
#define ERROR_CHARGE_RET_NO_SIM_CARD		PAYMENT_ERR_NO_SIM_CARD
/**
 * 如果文件系统上没有足够的空间，则该错误将会被返回。
 */
#define ERROR_CHARGE_RET_LACK_FS_SPACE		PAYMENT_ERR_LACK_FS_SPACE
/**
 * 如果参数错误，那么该错误码将会被返回。
 */
#define ERROR_CHARGE_RET_WRONG_PARAM		PAYMENT_ERR_WRONG_PARAM
/**
 * 内存不够或计费请求队列已满等。
 */
#define ERROR_CHARGE_RET_LACK_RESOURCE		PAYMENT_ERR_NO_MEM
/**
 * 手机当前日期错误，在手机系统日期早于2009/1/1则本错误码将会被返回。
 */
#define ERROR_CHARGE_RET_CURRENT_DATE_ERROR	PAYMENT_ERR_CURRENT_DATE
/**
 * 由于一些系统性错误导致的计费引擎内部错误。
 */
#define ERROR_CHARGE_RET_INT_ERROR			PAYMENT_ERR_INTERNAL_ERROR
/**
 * 本错误码只可能在模拟器上出现。
 */
#define ERROR_CHARGE_RET_VXP_FILE_ERROR		(PAYMENT_ERR_INTERNAL_ERROR - 1)
/**
 * 进程状态错误。
 */
#define ERROR_CHARGE_RET_APP_STATE			(PAYMENT_ERR_INTERNAL_ERROR - 2)
/** @} */

/**
 * 本函数用于计费，计费是否成功依靠用户程序注册上来的回调函数传递给应用程序的。本函数只能在前台调用。
 * 调用本函数后如果可以计费则应用会收到被挂起或切换到后台的消息，这时应用程序将释放所有的图形资源，由
 * 计费引擎接管界面与各种输入。在计费有结果时，计费引擎首先会回调计费结果，并且应用会在收到计费结果后
 * 收到被激活或被切换到前台的消息。
 * @code
 * void myCallBack(VMINT local_payment_id, CALLBACK_PAYMENT_STATE state)
 * {
 *    vm_release_charge_resource();
 *    if (state == PAYMENT_STATE_SUCCESS)
 *    {
 *        vm_save_charge_info("killer", 1, PAYMENT_MODE_BY_TIME, 10);
 *	      game_run();
 *    }
 *    else
 *    {
 *	      // 失败的处理逻辑。
 *	  }
 * }
 * 
 * VMINT ret = 0;
 * if ((ret = vm_query_charge_info("killer", 1, NULL, NULL, NULL) == QUERY_CHARGE_RET_NEED_PAYMENT))
 * {
 *     VMINT errorCode = 0;
 *     if (errorCode = vm_quick_charge("killer", 1, 100, myCallBack, NULL) == CHARGE_RET_ACCEPT_CHARGE)
 *     {
 *         // 刷应用程序界面，等待回调用函数。
 *     }
 *     else
 *     {
 *         // 失败，根据返回的错误码提示。
 *     }    
 * }
 * else if (ret == QUERY_CHARGE_RET_IN_DURABILITY)
 * {
 *    vm_deduct_charged_value("killer", 1);
 *    game_run();
 * }
 * else
 * {
 *    // 显示失败
 * }
 * @endcode
 * @param[in] good_name						需要购买的物品名称，最多为12个字符。
 * @param[in] local_payment_id 				应用程序内部计费点ID,需要在同一个应用程序里保持唯一。该值应该从1开始编号，最大不允许超过10000。
 * @param[in] price							本次请求收取费用的价格，单位为分。如果等于0则表示免费。如果本参数小于
 *											0,则将返回ERROR_CHARGE_RET_WRONG_PARAM的错误.										
 * @param[in] payment_callback				用户注册上来的回调函数，必须非NULL。
 * @param[in] extra_content					上行短信的附加信息，最多为10个字符，不能包含空格。
 * @param[in] charge_flag					TRUE 表示应用程序关心计费程序与否，FALSE则表示应用程序不关心计费是否真的成功，如果设置成FALSE则
 *											可能加快计费回调的速度。
 * @return									是否接受计费请求的标志。
 * @retval									CHARGE_RET_ACCEPT_CHARGE 计费引擎接受了计费请求。
 * @retval									ERROR_CHARGE_RET_NO_SIM_CARD  没有SIM卡或不是移动或联通的运营商则本错误码将会被返回。
 * @retval									ERROR_CHARGE_RET_LACK_FS_SPACE 文件系统缺少空间。
 * @retval									ERROR_CHARGE_RET_WRONG_PARAM 错误参数。
 * @retval									ERROR_CHARGE_RET_LACK_RESOURCE 如果内存不够或计费队列已满，那么本错误码将会被返回。
 * @retval									ERROR_CHARGE_RET_CURRENT_DATE_ERROR 手机系统时间错误。
 * @retval									ERROR_CHARGE_RET_INT_ERROR 计费引擎内部错误。
 * @retval									ERROR_CHARGE_RET_VXP_FILE_ERROR app_name参数为NULL本函数将会被返回，
 *											本错误只会在VRE模拟器里出现，在手机上该参数将会被忽略。	
 * @retval									ERROR_CHARGE_RET_APP_STATE 如果应用程序不在前台调用本函数则会收到被错误码。
 */
VMINT vm_quick_charge(VMWSTR good_name, VMINT local_payment_id, VMINT price, 
	void (*payment_callback)(VMINT local_payment_id, CALLBACK_PAYMENT_STATE state), VMSTR extra_content, VMINT charge_flag);

/**
 * 取消计费，并且释放vm_quick_charge函数所引起的计费用流程中产生的资源。如果用户程序没有注册回
 * 调函数或回调函数里没有调用本函数，那么计费过程中的资源将一直存在。应用程序应该在退出前调用本
 * 函数。在计费过程中不应该调用本函数，否则可能造成收取了一部分的金额，而用户无法使用计费用后的
 * 内容。
 */
void vm_release_charge_resource(void);

/**
 * @name vm_save_charge_info函数的返回码。
 * @{
 */
/**
 * 保存成功。
 */
#define SAVE_RET_SUCCESS					PAYMENT_RET_SUCCESS
/**
 * 没有插SIM卡或未知的运营商。
 */
#define ERROR_SAVE_RET_NO_SIM_CARD			PAYMENT_ERR_NO_SIM_CARD
/**
 * 文件系统缺少空间。
 */
#define ERROR_SAVE_RET_LACK_FS_SPACE		PAYMENT_ERR_LACK_FS_SPACE
/**
 * 错误的参数。
 */
#define ERROR_SAVE_RET_WRONG_PARAM			PAYMENT_ERR_WRONG_PARAM
/**
 * 内存不足。
 */
#define ERROR_SAVE_RET_LACK_RESOURCE		PAYMENT_ERR_NO_MEM
/**
 * 错误的日期，如果手机系统时间小于2009/1/1那么本错误将会被返回。
 */
#define ERROR_SAVE_RET_CURRENT_DATE_ERROR	PAYMENT_ERR_CURRENT_DATE
/**
 * 计费引擎内部错误。
 */
#define ERROR_SAVE_RET_INT_ERROR			PAYMENT_ERR_INTERNAL_ERROR
/**
 * 本错误码只可能在模拟器上出现。
 */
#define ERROR_SAVE_RET_VXP_FILE_ERROR		(PAYMENT_ERR_INTERNAL_ERROR - 1)
/**
 * 无法得到IMSI号，当前版本错误码将不会被返回。
 */
#define ERROR_SAVE_RET_NOT_GET_IMSI			(PAYMENT_ERR_INTERNAL_ERROR - 2)
/** @} */
/**
 * 保存计费后的计费信息.
 * 
 * @param[in] 				app_name 应用程序名称，比如"killer"，不应该为NULL，必须要以数值0结尾，该参数只在模拟器上有效。
 * @param[in]				local_payment_id 应用程序内部计费点ID,需要在同一个应用程序里保持唯一。该值应该从1开始编号，最大不允许超过10000。
 * @param[in]				payment_mode 保存已计费信息的计费模式。<br/>
 *							<li>PAYMENT_MODE_BY_TIME 表示按次。		</li>
 *							<li>PAYMENT_MODE_BY_DATE 表示按天。		</li>
 *							<li>PAYMENT_MODE_BY_FOREVER 表示买断。	</li>
 * @param[in]				payment_value </br>
 *							<li>如果payment_mode参数为PAYMENT_MODE_BY_TIME则本参数表示付费成功后的使用次数。	</li>
 *							<li>如果payment_mode参数为PAYMENT_MODE_BY_DATE则本参数表示付费成功后的使用天数。	</li>
 *							<li>如果payment_mode参数为PAYMENT_MODE_BY_FOREVER则本参数将会被忽略。				</li>
 *                          <li>如果本参数为0则表示买断的模式，忽略掉payment_mode参数。							</li>
 * @return					是否成功保存计费信息的标志。
 * @retval					SAVE_RET_SUCCESS 保存成功。
 * @retval					ERROR_SAVE_RET_LACK_FS_SPACE 文件系统空间不足，保存失败。
 * @retval					ERROR_SAVE_RET_WRONG_PARAM 错误的参数，保存失败。
 * @retval					ERROR_SAVE_RET_LACK_RESOURCE 内存不足，保存失败。
 * @retval					ERROR_SAVE_RET_CURRENT_DATE_ERROR 如果手机系统时间小于2009/1/1日则不错误将会被返回，保存失败。
 * @retval					ERROR_SAVE_RET_INT_ERROR 计费引擎内部错误，保存失败。
 * @retval					ERROR_SAVE_RET_VXP_FILE_ERROR app_name参数为NULL本函数将会被返回，本错误只会在VRE模拟器里
 *							出现，在手机上该参数将会被忽略。	
 */
VMINT vm_save_charge_info(VMSTR app_name, VMINT local_payment_id, VMINT payment_mode, VMUINT payment_value);

/**
 * @name vm_deduct_charged_value函数的返回值
 * @{
 */
/**
 * 扣除购买的天数或次数成功.
 */
#define DEDUCT_CHARGED_RET_SUCCESS								PAYMENT_RET_SUCCESS
/**
 * 指定的计费点ID不存在.
 */
#define ERROR_DEDUCT_CHARGED_RECORD_NOT_FOUND					PAYMENT_ERR_NOT_EXISTS_PAYMENT_ID
/**
 * 参数错误。
 */
#define ERROR_DEDUCT_CHARGED_RET_WRONG_PARAM					PAYMENT_ERR_WRONG_PARAM
/**
 * 如果收费过程中的缺乏资源，那么该错误码将会被返回。
 */
#define ERROR_DEDUCT_CHARGED_RET_LACK_RESOURCE					PAYMENT_ERR_NO_MEM
/**
 * 如果手机的系统时间小于2009年1月1日，那么将返回本错误码。
 */
#define ERROR_DEDUCT_CHARGED_RET_CURRENT_DATE_ERROR				PAYMENT_ERR_CURRENT_DATE
/**
 * 无SIM卡或未知的运营商。
 */
#define ERROR_DEDUCT_CHARGED_RET_NO_SIM_CARD					PAYMENT_ERR_NO_SIM_CARD
/**
 * 计费引擎内部错误。
 */
#define ERROR_DEDUCT_CHARGED_RET_INT_ERROR						PAYMENT_ERR_INTERNAL_ERROR
/**
 * 得到IMSI号失败。
 */
#define ERROR_DEDUCT_CHARGED_RET_NOT_GET_IMSI					(PAYMENT_ERR_INTERNAL_ERROR - 1)
/**
 * 本错误码只可能在模拟器上出现。
 */
#define ERROR_DEDUCT_CHARGED_RET_EXEC_FILE_PREFIX_ERROR			(PAYMENT_ERR_INTERNAL_ERROR - 2)
/** @} */
/**
 * 本函数将扣除用户购买的天数或次数，如果对于买断的计费点调用
 * 本函数将没有任何作用，如果对于已经到期的计费点调用本函数也
 * 没有任何作用。
 *
 * @param[in]	app_name 应用程序名称，比如"killer"，不应该为NULL，必须要以数值0结尾，该参数只在模拟器上有效。
 * @param[in]	local_payment_id 应用程序内部计费点ID,需要在同一个应用程序里保持唯一。该值应该从1开始编号，最大不允许超过10000。
 * @return		
 * @retval		DEDUCT_CHARGED_RET_SUCCESS 扣除成功。
 * @retval		ERROR_DEDUCT_CHARGED_RECORD_NOT_FOUND 没有发现指定计费点ID的已存计费记录，扣除失败。
 * @retval		ERROR_DEDUCT_CHARGED_RET_WRONG_PARAM 错误的参数，扣除失败。
 * @retval		ERROR_DEDUCT_CHARGED_RET_LACK_RESOURCE 内存不足，导致失败。
 * @retval		ERROR_DEDUCT_CHARGED_RET_CURRENT_DATE_ERROR 当前日期错误，如果当前手机日期小于2009/1/1，
 *				那么本错误码将会被返回。
 * @retval		ERROR_DEDUCT_CHARGED_RET_INT_ERROR 计费引擎内部错误导致扣除失败。
 * @retval		ERROR_DEDUCT_CHARGED_RET_EXEC_FILE_PREFIX_ERROR app_name参数为NULL本函数将会被返回，本错误只会在VRE模拟器里
 *				出现，在手机上该参数将会被忽略。
 */
VMINT vm_deduct_charged_value(VMSTR app_name, VMINT local_payment_id);

/**
 * @name vm_query_charge_info函数的返回码
 * @{
 */
/**
 * 表示还在计费的有效期内。
 */
#define QUERY_CHARGE_RET_IN_DURABILITY			PAYMENT_RET_IN_DURABILITY
/**
 * 表示需要计费。
 */
#define QUERY_CHARGE_RET_NEED_PAYMENT			PAYMENT_RET_NEED_PAYMENT
/**
 * 参数错误。
 */
#define QUERY_CHARGE_RET_PARAM_ERROR			PAYMENT_ERR_WRONG_PARAM
/**
 * 内存不足。
 */
#define QUERY_CHARGE_RET_LACK_RESOURCE			PAYMENT_ERR_NO_MEM
/**
 * 如果手机的系统时间小于2000年1月1日，那么将返回该错误。
 */
#define QUERY_CHARGE_RET_CURRENT_DATE_ERROR		PAYMENT_ERR_CURRENT_DATE
/**
 * 没有SIM卡或未知运营商。
 */
#define QUERY_CHARGE_RET_NO_SIM_CARD			PAYMENT_ERR_NO_SIM_CARD
/**
 * 计费引擎内部错误。
 */
#define QUERY_CHARGE_RET_INT_ERROR				PAYMENT_ERR_INTERNAL_ERROR
/**
 * 无法得到IMSI号。
 */
#define QUERY_CHARGE_RET_NOT_GET_IMSI			(PAYMENT_ERR_INTERNAL_ERROR - 1)
/**
 * 本错误码只可能在模拟器上出现。 
 */
#define QUERY_CHARGE_RET_EXEC_FILE_PREFIX_ERROR (PAYMENT_ERR_INTERNAL_ERROR - 2)
/** @} */

/**
 * 查询指定文件前缀和指定应用本地计费点ID的计费信息.
 * 
 * @param[in] 	app_name 应用程序名称，比如"killer"，不应该为NULL，必须要以数值0结尾，该参数只在模拟器上有效。
 * @param[in]	local_payment_id 应用程序内部计费点ID,需要在同一个应用程序里保持唯一。该值应该从1开始编号，最大不允许超过10000。
 * @param[out]	payment_mode 希望得到的计费类型指针,如果返回QUERY_CHARGE_RET_IN_DURABILITY,那么会向本参数的内存地址
 *				写入计费方式.写入的数值为PAYMENT_MODE_BY_TIME表示按次,PAYMENT_MODE_BY_DATE表示按
 *				天,如果本函数返回QUERY_CHARGE_RET_NEED_PAYMENT则不会写入.
 * @param[out]	payment_surplus_value 希望得到的剩余的次数或天数的指针类型,如果本函数返回QUERY_CHARGE_RET_IN_DURABILITY,那么
 *				会向本参数指针所指的地址写入剩余的次数或天数.如果是买断模式则写入0.如果本函数返
 *				回QUERY_CHARGE_RET_NEED_PAYMENT则不会写入.
 * @param[out]	is_saved 如果用户希望在收到QUERY_CHARGE_RET_NEED_PAYMENT的时候同时需要知道是否用户对该计费
 *				点保存过.那么就应该提供该指针.那么本函数在返回QUERY_CHARGE_RET_NEED_PAYMENT的时候
 *				会将TRUE或FALSE写入该指针指向的内存地址.FALSE表示没有保存过.TRUE表示已经保存过.
 *				只有在本函数返回QUERY_CHARGE_RET_NEED_PAYMENT的时候才会写入.
 *				
 * @return		表示查询是否成功和是否在计费期内。		
 * @retval		QUERY_CHARGE_RET_IN_DURABILITY 在计费使用期内。
 * @retval		QUERY_CHARGE_RET_NEED_PAYMENT 不在计费使用期内，需要计费。
 * @retval		QUERY_CHARGE_RET_PARAM_ERROR 参数错误，查询失败。
 * @retval		QUERY_CHARGE_RET_LACK_RESOURCE 内部不够，查询失败。
 * @retval		QUERY_CHARGE_RET_CURRENT_DATE_ERROR 当前日期错误，如果当前手机日期小于2009/1/1，
 *				那么本错误码将会被返回。
 * @retval		QUERY_CHARGE_RET_INT_ERROR 计费引擎内部错误。
 * @retval		QUERY_CHARGE_RET_EXEC_FILE_PREFIX_ERROR app_name参数为NULL本函数将会被返回，本错误只会在VRE模拟器里
 *				出现，在手机上该参数将会被忽略。
 */
VMINT vm_query_charge_info(VMSTR app_name, VMINT local_payment_id, 
	VMINT* payment_mode, VMINT* payment_surplus_value, VMINT* is_saved);

/**
 * @name vm_get_charge_notification的返回值。
 */
/**
* 寻价成功。
*/
#define NOTIFICATION_RET_SUCCESS											(0)
/**
* 错误的参数。
*/
#define ERROR_NOTIFICATION_RET_WRONG_PARAM									(-1)
/**
* 内存不够。
*/
#define ERROR_NOTIFICATION_RET_ERROR_MEM									(-2)
/**
* 错误的VXP文件。
*/
#define ERROR_NOTIFICATION_RET_VXP_FILE_ERROR								(-3)
/**
* 价格无法匹配。
*/
#define ERROR_NOTIFICATION_RET_DISMATCH_PRICE								(-4)
/**
 * 应用不需要提示。
 */
#define ERROR_NOTIFICATION_NO_NOTIFICATION									(-5)

/**
* 得到计费前的提示文字与实际的交易价格。
* 
* @code
* VMINT ret = 0, transaction_price = 0;
* if ((ret = vm_query_charge_info("ball", 1, NULL, NULL, NULL) == QUERY_CHARGE_RET_NEED_PAYMENT))
* {
*     VMINT errorCode = 0;
*     VMWSTR notification = NULL;
*	 
*	 if (vm_get_charge_notification(200, 1, &transaction_price, &notification) == 0)
*	 {
*	     draw_notification(notification); // 显示提示界面，用户确认后调用vm_quick_charge开始计费。
*       vm_free(notification);
*     }
* }
* @endcode
* @param[in]								fix_price 游戏对该计费点的定价，单位为分。
* @param[in]								local_payment_id 应用程序内部计费点ID。
* @param[out]								transaction_price 计费引擎支持的计费价格，单位为分。这个价格也是调用vm_quick_charge所传入的价格。
* @param[out]								notification 提示给用户的提示文字，在使用完后必须调用vm_free函数把notification释放掉。
* @return									是否寻价成功的标志。
* @retval									NOTIFICATION_RET_SUCCESS 寻价成功。
* @retval									ERROR_NOTIFICATION_RET_WRONG_PARAM 错误的参数。
* @retval									ERROR_NOTIFICATION_RET_ERROR_MEM 内存不够。
* @retval									ERROR_NOTIFICATION_RET_VXP_FILE_ERROR 错误的VXP文件。
* @retval									ERROR_NOTIFICATION_RET_DISMATCH_PRICE 价格不能不匹配。
* @retval									ERROR_NOTIFICATION_NO_NOTIFICATION 应用不需要提示，由计费引擎负责提示。
*/
VMINT vm_get_charge_notification(VMUINT fix_price, VMINT local_payment_id, VMUINT* transaction_price, VMWSTR* notification);

#ifdef __cplusplus
}
#endif

#endif



