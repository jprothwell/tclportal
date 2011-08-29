#ifndef __VM_SENSOR
#define __VM_SENSOR

#include "vmsys.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @VRE的传感器接口的返回值
 * @{
 */
 /**
  * 操作成功.
  */
#define SENSOR_OP_SUCCESS									(0)
/**
 * 操作为异步操作,请参看相关的函数说明.
 */
#define SENSOR_OP_ASYNCHROUS								(1)
/**
 * 错误的参数.
 */
#define SENSOR_ECODE_BAD_PARAM							(-1)
/**
 * 不支持的操作.
 */
#define SENSOR_ECODE_UNSUPPORT_OPERATION				(-2)
/**
 * 在当前状态下不支持该操作.
 */
#define SENSOR_ECODE_UNSUPPORT_OPERATION_IN_STATUS   	(-3)
/**
 * 错误的传感器句柄.
 */
#define SENSOR_ECODE_INVALID_HANDLE						(-4)
/**
 * 指定的传感器名称非法.
 */
#define SENSOR_ECODE_INVALID_NAME						(-5)
/**
 * 传感器实例已创建.
 */
#define SENSOR_ECODE_INSTANCE_CREATED					(-6)
/**
 * 还没有注册传感器的回调函数.
 */
#define SENSOR_ECODE_NOT_REG_NOTIFY						(-7)
/**
 * 缺少内存.
 */
#define SENSOR_ECODE_NO_MEMORY							(-8)
/** @} */

/**
 * 传感器回调消息.
 */
typedef enum {
	SENSOR_START_DONE, 			/**<传感器启动完毕.				*/
	SENSOR_START_ABORT, 			/**<传感器启动失败.				*/
	SENSOR_STOP_DONE,				/**<传感器停止成功. 				*/
	SENSOR_STOP_ABORT,			/**<传感器停止失败. 				*/
	SENSOR_SET_OPTION_DONE, 		/**<设置传感器属性完毕.		*/
	SENSOR_SET_OPTION_ABORT, 	/**<设置传感器属性成功.		*/
	SENSOER_DATA_RECEIVED		/**<传感器接受到了数据.		*/
}VM_SENSOR_MESSAGE;

/**
 * @struct 传感器的回调结构体
 * @brief 传感器接口回调到应用程序的结构体.
 */
typedef struct vm_sensor_notify_t {
	VMINT sensor_handle;			/**<传感器句柄.						*/
	VM_SENSOR_MESSAGE message;	/**<传感器回调消息.					*/
	void* sensor_data;				/**<传感器接收到的数据.			*/
	VMUINT data_size;				/**<传感器接收到的数据个数.		*/
	VMINT reserved;					/**<保留字段.							*/
}vm_sensor_notify_t;

typedef void (*SENSOR_NOTIFY_FUNC)(vm_sensor_notify_t* sensor_notify, void* user_data);

/**
 * 创建传感器实例.
 *  
 * @param[in]				name 传感器的名称,在一个设备里应该保持唯一.
 * @param[out]			sensor_handle 创建了实例的传感器句柄,只有返回
 *						#SENSOR_OP_SUCCESS的时候,本参数才有意义.
 * @return				创建指定名称的传感器实例是否成功的返回值.
 * @retval				SENSOR_OP_SUCCESS 创建传感器实例成功.
 * @retval				SENSOR_OP_ERROR_CODE_BAD_PARAM 如果参数sensor_handle为NULL
 *						那么将会返回本错误码.
 * @retval				SENSOR_ECODE_INVALID_NAME 非法的传感器名称.
 * @retval				SENSOR_ECODE_INSTANCE_CREATED 指定名称的传感器实例
 *						已经被创建.
 * @retval				SENSOR_ECODE_NO_MEMORY 缺少内存.
 * @note					在调用本函数后必须调用#vm_release_sensor_instance,释放
 *						创建出来的传感器实例.
 * @code 
 * // vm_freescale_MMA7455L.h
 * #define USE_SENSOR_NAME "sensor:quality=acceleration;device=mobile;model=TCL-E9;location=inside"
 * #define G_SELECT "G_SELECT"
 * typedef enum {2G, 4G, 8G}G_SELECT_ENUM;
 * @endcode
 * @code
 * // sensor_sample.c
 * VMINT handle;
 * if (vm_create_sensor_instance(USE_SENSOR_NAME, &handle) == SENSOR_OP_SUCCESS)
 * {
 * 	if (vm_register_sensor_notify(handle, (RECEIVE_DATA_FUNC)receive_callback, NULL) == SENSOR_OP_SUCCESS)
 *  	{
 * 		VMINT res = vm_set_sensor_numeric_option(handle, G_SELECT, 2G);
 *		if (res == SENSOR_OP_SUCCESS)
 *		{
 *			// 设置传感器选项成功, 走启动传感器的流程.
 *		}
 *    		else if (res == SENSOR_OP_ASYNCHROUS)
 *		{
 *			// 设置传感器选项将以异步的方式返回其结果.
 *		}
 *		else
 *		{
 *			// 设置传感器选项的错误的处理.
 *		}
 *	}
 * }
 * @endcode
 */
VMINT  vm_create_sensor_instance(const VMSTR name, VMINT* sensor_handle);

/**
 * 释放该传感器实例.
 * 
 * @param[in]				sensor_handle 传感器句柄.
 * @return 				
 * @retval				SENSOR_OP_SUCCESS 操作成功.
 * @retval				SENSOR_OP_ERROR_CODE_INVALID_HANDLE 错误的传感器句柄.
 * @retval				SENSOR_ECODE_UNSUPPORT_OPERATION_IN_STATUS 在当前状态下
 *						不支持调用本函数.
 * @see					vm_create_sensor_instance 
 */
VMINT vm_release_sensor_instance(VMINT sensor_handle);

/**
 * 注册传感器回调函数.
 * 
 * @param[in]				sensor_handle 传感器句柄.
 * @param[in]				callback 回调函数
 * @param[in]				user_data 每次回调放在参数里的客户程序的数据.
 * @return				注册传感器回调函数成功与否的返回值.
 * @retval				SENSOR_OP_SUCCESS 操作成功.
 * @retval				SENSOR_OP_ERROR_CODE_BAD_PARAM 参数错误该错误码将会被返回.
 * @retval				SENSOR_ECODE_INVALID_HANDLE  错误的传感器句柄.
 * 
 */
VMINT vm_register_sensor_notify(VMINT sensor_handle, SENSOR_NOTIFY_FUNC callback, void* user_data);

/**
 * 设置传感器数值类型的选项.
 * 
 * @param[in]				sensor_handle 传感器句柄.
 * @param[in]				control_name 传感器选项的名称.
 * @param[in]				value 传感器选项的值.
 * @return				设置选项成功与否.
 * @retval				SENSOR_OP_SUCCESS 设置选项成功.
 * @retval				SENSOR_OP_ASYNCHROUS  设置为异步操作, 如果设置成功
 *						将会回调SENSOR_SET_OPTION_DONE消息,如果设置失败
 *						则会回调SENSOR_SET_OPTION_ABORT消息.
 * @retval				SENSOR_ECODE_UNSUPPORT_OPERATION_IN_STATUS 在当前状态下
 *						不支持设置该选项.
 * @retval				SENSOR_ECODE_INVALID_HANDLE 错误的传感器句柄.
 * @retval				SENSOR_ECODE_BAD_PARAM 如果参数control_name为NULL
 *						或参数value 不正确,那么该错误码将会被返回.
 * @retval				SENSOR_ECODE_NOT_REG_NOTIFY 在调用本函数前必须调用
 *						#vm_register_sensor_notify函数来注册回调函数,否则将返回该
 *						错误码.
 * @see					vm_set_sensor_string_option
 */
VMINT vm_set_sensor_numeric_option(VMINT sensor_handle, const VMSTR control_name, 
	VMINT value);

/**
 * 设置传感器字符串类型的选项.
 * 
 * @param[in]				sensor_handle 传感器句柄.
 * @param[in]				control_name 传感器选项的名称.
 * @param[in]				value 传感器选项的值.
 * @return				设置选项成功与否.
 * @retval				SENSOR_OP_SUCCESS 设置选项成功.
 * @retval				SENSOR_OP_ASYNCHROUS  设置为异步操作, 如果设置成功
 *						将会回调SENSOR_SET_OPTION_DONE消息,如果设置失败
 *						则会回调SENSOR_SET_OPTION_ABORT消息.
 * @retval				SENSOR_ECODE_UNSUPPORT_OPERATION_IN_STATUS 当前状态下
 *						不支持设置该选项.
 * @retval				SENSOR_ECODE_INVALID_HANDLE  错误的传感器句柄.
 * @retval				SENSOR_ECODE_BAD_PARAM 如果参数control_name为NULL
 *						或参数value 不正确,那么该错误码将会被返回.
 * @retval				SENSOR_ECODE_NOT_REG_NOTIFY 在调用本函数前必须调用
 *						#vm_register_sensor_notify函数来注册回调函数,否则将返回该
 *						错误码.
 * @see					vm_set_sensor_numeric_option
 */
VMINT vm_set_sensor_string_option(VMINT sensor_handle, const VMSTR control_name, 
	VMSTR value);

/**
 * 启动传感器.
 * 
 * @param[in]				sensor_handle 传感器句柄.
 * @return				启动传感器成功与否.
 * @retval				SENSOR_OP_SUCCESS 启动传感器成功.
 * @retval				SENSOR_OP_ASYNCHROUS 启动为异步过程, 如果启动成功
 *						将会回调SENSOR_START_DONE消息,如果启动失败
 *						将会回调SENSOR_START_ABORT消息.
 * @retval				SENSOR_ECODE_UNSUPPORT_OPERATION_IN_STATUS 如果传感器已经启动
 *						那么该错误码将会被返回.
 * @retval				SENSOR_ECODE_INVALID_HANDLE 错误的传感器句柄.
 * @retval				SENSOR_ECODE_NOT_REG_NOTIFY 在调用本函数前必须调用
 *						#vm_register_sensor_notify函数来注册回调函数,否则将返回该
 *						错误码.
 * @note					调用本函数启动传感器后,在调用#vm_release_sensor_instance
 *						前则必须调用#vm_stop_sensor来停止传感器.
 * @see 					vm_stop_sensor
 */
VMINT vm_start_sensor(VMINT sensor_handle);

/**
 * 停止传感器.
 * 
 * @param[in]				sensor_handle 传感器句柄.
 * @return				停止传感器成功与否。
 * @retval				SENSOR_OP_SUCCESS 关闭传感器成功.
 * @retval				SENSOR_OP_ASYNCHROUS 传感器的关闭为异步的,如果停止
 *						成功,将会回调SENSOR_STOP_DONE消息,停止失败将会返回
 *						SENSOR_STOP_ABORT消息.
 * @retval				SENSOR_ECODE_INVALID_HANDLE 错误的传感器句柄.
 * @retval				SENSOR_ECODE_NOT_REG_NOTIFY 在调用本函数前必须调用
 *						#vm_register_sensor_notify函数来注册回调函数,否则将返回该
 *						错误码.
 * @retval				SENSOR_ECODE_UNSUPPORT_OPERATION_IN_STATUS 如果传感器没有启动,
 *						那么该错误码将会被返回.
 * @see					vm_start_sensor		
 */
VMINT vm_stop_sensor(VMINT sensor_handle);

#ifdef __cplusplus
}
#endif 

#endif
