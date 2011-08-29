#ifndef VMCAMERA_H_
#define VMCAMERA_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"

/**
 *  摄像头的句柄类型.
 */
typedef VMINT VM_CAMERA_HANDLE;

/**
 * 手机上摄像头的ID号.
 */
typedef enum 
{
	VM_CAMERA_MAIN_ID = 1,		/**<手机上的主摄像头ID. 					*/
	VM_CAMERA_SUB_ID				/**<手机上的副摄像头ID,一般用来自拍. */
}VM_CAMERA_ID;

/**
 * 摄像头在不同操作下的异步消息,在摄像头的各个状态里所
 * 允许的操作也是不同的.
 */
typedef enum
{
	VM_CAM_PREVIEW_START_DONE = 1,		/**<摄像头开始preview 成功.							*/
	VM_CAM_PREVIEW_START_ABORT,			/**<摄像头开始preview 失败.							*/
	VM_CAM_PREVIEW_STOP_DONE,			/**<摄像头停止preview 成功.							*/
	VM_CAM_PREVIEW_STOP_ABORT,			/**<摄像头停止preview 失败.							*/
	VM_CAM_PREVIEW_FRAME_RECEIVED,		/**<摄像头在preview状态下如果有帧图象
												来到后该消息将会被送到客户程序. 		*/
	VM_CAM_CAPTURE_DONE,					/**<摄像头拍照成功.									*/
	VM_CAM_CAPTURE_ABORT				/**<摄像头拍照失败.									*/
}VM_CAMERA_MESSAGE;

/**
 * 摄像头的状态,结合VM_CAMERA_MESSAGE可以描述的状态图如下.
 * @code
 * VM_CAM_READY_STATUS      VM_CAM_STARTING_PREVIEW_STATUS      VM_CAM_PREVIEW_STATUS      VM_CAM_STOPPING_PREVIEW_STATUS      VM_CAM_CAPTURING_STATUS
 *			| vm_camera_preview_start		                                                                                     			
 *			------------------------------->								
 *											|VM_CAM_PREVIEW_START_DONE																				 
 *											-------------------------------->																
 *											|								|																
 *				VM_CAM_PREVIEW_START_ABORT	|								|																
 *			<--------------------------------								|vm_camera_preview_stop													 							 
 *			|																------------------------------->													 
 *			|																|	VM_CAM_PREVIEW_STOP_ABORT	|														 
 *			|																<-------------------------------													 
 *			|	 																							|								
 *			|																	VM_CAM_PREVIEW_STOP_DONE	|				 				
 *			<------------------------------------------------------------------------------------------------												 
 *			|								 								|								 			 					
 *			|																|vm_camera_capture											
 *			|								 								--------------------------------------------------------------->
 *			|																			 VM_CAM_CAPTURE_DONE/VM_CAM_CAPTURE_ABORT			|
 *			<-------------------------------------------------------------------------------------------------------------------------------
 *			|vm_camera_capture																												|
 *			------------------------------------------------------------------------------------------------------------------------------->
 *			|																			VM_CAM_CAPTURE_DONE/VM_CAM_CAPTURE_ABORT			|
 *			<-------------------------------------------------------------------------------------------------------------------------------
 * @endcode
 */
typedef enum
{
	VM_CAM_READY_STATUS = 1,				/**<成功创建摄像头实例后的状态. 	*/
	VM_CAM_STARTING_PREVIEW_STATUS,	/**<正在启动摄像头预览的状态. 		*/
	VM_CAM_STOPPING_PREVIEW_STATUS,	/**<正在停止摄像头预览的状态. 		*/
	VM_CAM_PREVIEW_STATUS,				/**<正在预览的状态. 						*/
	VM_CAM_CAPTURING_STATUS				/**<正在拍摄状态. 						*/
}VM_CAMERA_STATUS;


/**
 * @name 摄像头操作函数的返回值
 * @{
 */
/**
  * 操作成功.
  */
#define VM_CAM_SUCCESS								(0)
/**
  * 没有足够的内存.
  */
#define VM_CAM_ERR_NOMEMORY						(-1)
/**
  * 摄像头在该状态下不允许此类操作.
  */
#define VM_CAM_ERR_OPERATE_BAD_STATUS			(-2)
/**
  * 错误的参数值.
  */
#define VM_CAM_ERR_BAD_PARAM						(-3)
/**
  * 非法的摄像头句柄.
  */
#define VM_CAM_ERR_INVALID_CAM_HANDLE			(-4)
/**
  * 在VRE的版本还不支持该操作.
  */
#define VM_CAM_ERR_UNSUPPORT_OPERATION			(-5)
/**
  * 重覆创建摄像头实例.
  */
#define VM_CAM_ERR_CAM_INSTANCE_CREATED			(-6)
/**
  * 该摄像头实例还没有注册回调.
  */
#define VM_CAM_ERR_NOT_REGISTER_NOTIFY			(-7)
/**
 * 错误的摄像头ID号.
 */
#define VM_CAM_ERR_INVALID_CAM_ID				(-8)
/**
  * 摄像头的内部错误.
  */
#define VM_CAM_ERR_CAM_INTERNAL_ERROR			(-9)
/**
 * 当前平台不支持摄像头功能.
 */
#define VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE	(-10)
/**
 * 如果是VRE (3.0)及以后版本，如果应用程序在非
 * 前台运行状态下调用了摄像头的某些函数，
 * 那么本错误码将会被返回。
 */
#define VM_CAM_OPERATION_IN_PROCESS_STATUS		(-11)
/** @} */

/**
 * 创建摄像头实例,得到摄像头的句柄.该句柄用于
 * 对摄像头的各种操作.如果本函数返回
 * #VM_CAM_SUCCESS则表示摄像头句柄已经被写
 * 入参数handle_ptr所指向的内存地址上,摄像头也已经处
 * 于就绪状态. 本函数与#vm_release_camera_instance对应,在调用
 * 本函数后如果程序退出或不需要操作摄像头则应该
 * 调用#vm_release_camera_instance函数.
 *
 * @param[in] 			camera_id 摄像头ID.
 * @param[out] 			handle_ptr 指向摄像头句柄的指针.			
 * @return				是否创建摄像头成功与否的返回值.
 * @retval				VM_CAM_SUCCESS 成功.
 * @retval				VM_CAM_ERR_NOMEMORY 内存不足.
 * @retval				VM_CAM_ERR_INVALID_CAM_ID 错误的摄像头ID.
 * @retval				VM_CAM_ERR_CAM_INSTANCE_CREATED 该摄像头ID创建的摄像头实例已经被创建.
 * @retval				VM_CAM_ERR_BAD_PARAM 错误的参数,handle_ptr参数为NULL.
 * @retval				VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE 如果VRE不支持摄像头的功能那么
 *						本参数将会被返回.
 * @retval				VM_CAM_OPERATION_IN_PROCESS_STATUS 如果VRE 3.0及以后版本，客户程序在BackGround状态下调用
 *						本函数那么本参数将会被返回。
 * @see					vm_release_camera_instance
 */
VMINT vm_create_camera_instance(VM_CAMERA_ID camera_id, 
	VM_CAMERA_HANDLE* handle_ptr);

/**
 * 释放摄像头实例.
 * 
 * @param[in]				handle 摄像头句柄,该句柄是由
 *						#vm_create_camera_instance函数产生的.
 * @return				返回是否成功释放摄像头或错误代码.
 * @retval				VM_CAM_SUCCESS 表示释放成功.
 * @retval				VM_CAM_ERR_OPERATE_BAD_STATUS 表示当前的设像头
 *						的状态不允许被释放.
 * @retval				VM_CAM_ERR_INVALID_CAM_HANDLE 非法的摄像头句柄.
 * @retval				VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE 如果VRE不支持摄像头的功能那么
 *						本参数将会被返回. 
 *						才会返回给应用程序。
 * @note					调用了#vm_create_camera_instance创建了摄像头实例后
 *						,在退出程序前必须调用本函数释放掉摄像头
 *						实例.
 * @see					vm_create_camera_instance
 */
VMINT vm_release_camera_instance(VM_CAMERA_HANDLE handle);

/**
 * 得到摄像头当前的状态,在任何状态下都可以调用本函数.
 * 
 * @param[in]				handle 摄像头句柄.
 * @param[out]			cam_status 摄像头的状态指针.
 * @return				得到摄像头状态是否成功.
 * @retval				VM_CAM_SUCCESS 成功.
 * @retval				VM_CAM_ERR_INVALID_CAM_HANDLE 错误的摄像头句柄.
 * @retval				VM_CAM_ERR_BAD_PARAM 错误的参数.
 * @retval				VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE 如果VRE不支持摄像头的功能那么
 *						本参数将会被返回.
 * @retval				VM_CAM_OPERATION_IN_PROCESS_STATUS 如果不是应用程序创建的摄像头句柄，
 *						那么本错误将会被返回。
 *						
 */
VMINT vm_get_camera_status(VM_CAMERA_HANDLE handle, VM_CAMERA_STATUS* cam_status);

/**
 * 帧图象里一个像素的格式.
 */
typedef enum
{
	PIXTEL_RGB565 = 1,					/**<PIXTEL_RGB565格式,高位为红色(RED),低位为蓝色(BLUE), 一个像素占2字节. 		*/
	PIXTEL_BGR565,						/**<PIXTEL_BGR565格式,高位为蓝色(BLUE),低位为红色(RED), 一个像素占2字节. 		*/
	PIXTEL_RGB888,						/**<PIXTEL_RGB888格式,高位为红色(RED),低位为蓝色(BLUE), 一个像素占3字节. 		*/
	PIXTEL_BGR888,						/**<PIXTEL_BGR565格式,高位为蓝色(BLUE),低位为红色(RED), 一个像素占3字节. 		*/
	PIXTEL_ARGB8888,					/**<PIXTEL_ARGB8888格式,高位alpha(alpah通道),低位为蓝色(BLUE), 一个像素占4字节. 	*/
	PIXTEL_ABGR8888					/**<PIXTEL_ABGR8888格式,高位alpha(alpah通道),低位为红色(RED), 一个像素占4字节. 		*/
}PIXTEL_FORMAT_T;

/**
  * @struct 摄像头预览到数据帧
  * @brief 摄像头在预览时候的帧图象,如果把#vm_camera_preview_start 函数的参数is_direct_display_on_screen设置为TRUE,那么将不会有帧的消息回调.
  */
typedef struct vm_cam_frame_data_t
{
	VMUINT 				row_pixel;				/**<每行的像素个数. 								*/
	VMUINT 				col_pixel;				/**<每列的像素个数. 								*/ 
	PIXTEL_FORMAT_T 	pixtel_format;			/**<像素格式,即alpha和rgb的高低位顺序, 也
													能	从中得到每个像素所占的字节数.	*/
	void* 				pixtel_data;				/**<像素数据. 										*/
	VMINT				reserved;				/**<保留字段. 										*/
}vm_cam_frame_data_t;

/**
 * @struct 摄像头拍摄下来的数据
 * @brief 摄像头拍摄后的数据,该数据可以在收到VM_CAM_CAPTURE_DONE后调用#vm_camera_get_capture_data函数得到.
 */
typedef struct vm_cam_capture_data_t
{
	VMCHAR 				mime_type[32];			/**<数据的media的类型. 		*/
	VMUINT8*			data;					/**<数据. 							*/
	VMUINT				data_size;				/**<数据的字节长度. 			*/
	VMINT				reserved;				/**<保留字段. 					*/
}vm_cam_capture_data_t;

/**
 * @struct vm_cam_notify_data_t
 * @brief 
 * 客户程序注册上来的回调函数必须接受的参数所指向的数据结构.
 * 该数据结构用来传递摄像头	的状态和上下文相关的数据. 客户程序
 * 对于该数据结构都应该是只读的.
 */
typedef struct vm_cam_notify_data_t
{
	VM_CAMERA_HANDLE 		handle;					/**<摄像头实例句柄.  							*/
	VM_CAMERA_MESSAGE 	cam_message;			/**<摄像头消息.									*/
	VM_CAMERA_STATUS 		cam_status;				/**<摄像头当前所处状态. 						*/
}vm_cam_notify_data_t;

/**
 * 摄像头用户注册上来的回调函数.
 */
typedef void (*VM_CAMERA_STATUS_NOTIFY)(const vm_cam_notify_data_t* notify_data, void* user_data);

/**
 * 注册回调函数,该函数在有VM_CAMERA_MESSAGE消息时触发系统回调.
 * 
 * @param[in]					handle 摄像头句柄.
 * @param[in]					notify_callback 回调函数.
 * @param[in]					user_data 用户数据,在每次系统回调时作为参数返回,系统不会修改该数据。如果不需要，则该参数可以为NULL。
 * @return 					是否注册成功或错误码.
 * @retval 					VM_CAM_SUCCESS 注册成功.
 * @retval					VM_CAM_ERR_INVALID_CAM_HANDLE 错误的摄像头句柄.
 * @retval					VM_CAM_ERR_BAD_PARAM 错误的参数,如果参数notify_callback为NULL,
 *							那么该错误将会被返回.
 * @retval					VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE 如果VRE不支持摄像头的功能那么
 *							本参数将会被返回.
 * @note						由于摄像头的消息完全是异步的,所以在调用其它摄像头相关
 *							的函数前都应该先注册回调函数,否则可能返回VM_CAM_ERR_NOT_REGISTER_NOTIFY
 *							错误.
 */
VMINT vm_camera_register_notify(VM_CAMERA_HANDLE handle, VM_CAMERA_STATUS_NOTIFY notify_callback, void* user_data);

/**
  * @struct vm_cam_size
  * @brief 摄像头尺寸的数据结构.
  */
typedef struct vm_cam_size_t
{
	VMUINT width;				/**<宽度 */
	VMUINT height;				/**<高度 */
}vm_cam_size_t;

/**
 * 得到系统支持的摄像头预览的各种组合的宽和高.
 *
 * @code
 * void app_set_preview_size(void)
 * {
 *	vm_cam_size_t* ptr = NULL;
 *	VMUINT size = 0, i = 0;
 * 	if (vm_camera_get_support_preview_size(camera_handle, &ptr, &size) == VM_CAM_SUCCESS)
 *	{
 *		vm_cam_size_t my_cam_size;
 *
 *		// 迭代所有支持的尺寸，并且设置最后一个支持的尺寸。
 *		for (i = 0; i < size; i++)
 *		{
 *			my_cam_size.width  = (ptr + i)->width;
 *			my_cam_size.height =(ptr + i) ->height;
 *		}
 *		vm_camera_set_preview_size(camera_handle, &my_cam_size);
 *	}
 * }
 * @endcode
 * @param[in]						handle 摄像头句柄.
 * @param[out]					cam_size_list 尺寸数组的头指针，如果程序需要调用vm_camera_set_preview_size
 *								函数来设置尺寸，那么需要把本数组里的某个元素拷贝到应用程序的
 *								的内存空间中。
 * @param[out]					list_size 尺寸数组的元素个数.
 * @return						是否成功执行了本操作.
 * @retval						VM_CAM_SUCCESS 成功执行操作.
 * @retval						VM_CAM_ERR_INVALID_CAM_HANDLE 错误的摄像头句柄。
 * @retval						VM_CAM_ERR_BAD_PARAM 参数错误.
 * @retval						VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE 如果VRE不支持摄像头的功能那么
 *								本参数将会被返回.
 * @see							vm_camera_set_preview_size
 */ 
VMINT vm_camera_get_support_preview_size(VM_CAMERA_HANDLE handle, const vm_cam_size_t** cam_size_list, VMUINT* list_size);

/**
 * 设置摄像头预览的尺寸,单位为像素.只有在VM_CAM_READY_STATUS状态下才能调用
 * 本函数. 如果不设置预览的尺寸则默认为MAIN LCD 同样的宽度和高度。
 * 
 * @param[in] 					handle 摄像头句柄.
 * @param[in]					preview_size 摄像头预览的尺寸。
 * @return						是否成功设置预览帧尺寸的返回值.
 * @retval						VM_CAM_SUCCESS 设置成功.
 * @retval						VM_CAM_ERR_INVALID_CAM_HANDLE 错误的摄像头句柄.
 * @retval						VM_CAM_ERR_BAD_PARAM 错误的参数,如果参数参数
 *								preview_size 为NULL或preview_size所设置的宽和高的组合不支持,
 *								则该错误码将会被返回.
 * @retval						VM_CAM_ERR_OPERATE_BAD_STATUS 在错误状态下调用了本函数.
 * @retval						VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE 如果VRE不支持摄像头的功能那么
 *								本参数将会被返回.
 * @note							设置的预览尺寸应该是调用vm_camera_get_support_preview_size返回的某
 *								个尺寸.
 * @see							vm_camera_get_support_preview_size
 */
VMINT vm_camera_set_preview_size(VM_CAMERA_HANDLE handle, const vm_cam_size_t* preview_size);

/**
 * 设置在预览时候的帧数,在预览时最大支持每秒 30帧.
 * 在性能比较不理想的手机平台上可能小于每秒30帧.
 * 本函数只能在VM_CAM_READY_STATUS 状态被调用. 如果没有设置
 * 摄像头预览时候的帧率那么将会以平台最大支持的
 * 帧率来启动预览.
 * 
 * @param[in]					handle 摄像头句柄.
 * @param[in]					fps 每秒帧数,如果大于30,则VRE系统将会
 * 								强制把帧数设置为30.
 * @return						
 * @retval						VM_CAM_SUCCESS 设置成功.
 * @retval						VM_CAM_ERR_INVALID_CAM_HANDLE 错误的摄像头句柄.
 * @retval						VM_CAM_ERR_BAD_PARAM 如果fps 为0那么本错误码将会
 *								被返回.
 * @retval						VM_CAM_ERR_OPERATE_BAD_STATUS 如果在非VM_CAM_READY_STATUS调用
 *								本函数将会得到本错误码.
 * @see							vm_camera_preview_start
 */
VMINT vm_camera_set_preview_fps(VM_CAMERA_HANDLE handle, VMUINT fps);

/**
 * 启动预览,只能在VM_CAM_READY_STATUS下调用该函数.如果需要启动摄像头的预
 * 览,那么必须在应用程序中关闭多层,否则启动摄像头预览操作将会失败.
 * 
 * @param[in]					handle 摄像头句柄.
 * @return					是否成功启动预览的返回值.
 * @retval					VM_CAM_SUCCESS 接受开始启动的操作,正在启动摄像头,摄像头进入
 *							VM_CAM_STARTING_PREVIEW_STATUS状态.
 * @retval					VM_CAM_ERR_NOMEMORY 没有足够的内存空间启动预览.
 * @retval					VM_CAM_ERR_OPERATE_BAD_STATUS 在错误的状态下启动摄像头预览.
 * @retval					VM_CAM_ERR_INVALID_CAM_HANDLE 错误的摄像头预览句柄.
 * @retval					VM_CAM_ERR_NOT_REGISTER_NOTIFY 如果还没有注册回调函数就调用本操作,
 *							那么该错误将会被返回.
 * @retval					VM_CAM_OPERATION_IN_PROCESS_STATUS
 * @retval					VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE 如果VRE不支持摄像头的功能那么
 *							本参数将会被返回.
 * @see						vm_camera_preview_stop
 * @see						vm_camera_set_preview_size
 * @see						vm_camera_set_preview_fps
 */
VMINT vm_camera_preview_start(VM_CAMERA_HANDLE handle);
 
/**
 * 停止摄像头的预览, 只能在VM_CAM_PREVIEW_STATUS状态或VM_CAM_STARTING_PREVIEW_STATUS
 * 状态下调用本函数.
 * 
 * @param[in]					handle 摄像头句柄.
 * @return					是否开始停止摄像头预览的返回值.
 * @retval 					VM_CAM_SUCCESS 接受停止摄像头预览的操作,摄像头进入VM_CAM_STOPPING_PREVIEW_STATUS
 *							状态.
 * @retval 					VM_CAM_ERR_OPERATE_BAD_STATUS 在错误的状态下调用了本函数.
 * @retval 					VM_CAM_ERR_INVALID_CAM_HANDLE 错误的摄像头句柄.
 * @retval					VM_CAM_ERR_NOT_REGISTER_NOTIFY 如果还没有注册回调函数就调用本操作,
 *							那么该错误将会被返回.
 * @retval					VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE 如果VRE不支持摄像头的功能那么
 *							本参数将会被返回.
 * @see						vm_camera_preview_start
 */
VMINT vm_camera_preview_stop(VM_CAMERA_HANDLE handle);

/**
 * 得到摄像头的预览数据,只有收到VM_CAM_PREVIEW_FRAME_RECEIVED
 * 消息的时候调用本函数才能得到预览数据帧. 以下是示例代码.
 * @code
 * void cam_message_callback(vm_cam_notify_data_t* notify_data, void* user_data)
 * {
 * 	if (notify_data != NULL)
 *    {
 *		vm_cam_frame_data_t frame;
 *		
 *		switch (notify_data->cam_message)
 *		{
 *		case VM_CAM_PREVIEW_SOPT_DONE:
 *			// 预览已经停止的逻辑.
 *			break;
 *		case VM_CAM_PREVIEW_FRAME_RECEIVED:
 *			if (vm_camera_get_frame(cam_handle, &frame) == VM_CAM_SUCCESS)
 *			{
 *				// 得到预览的帧图象的逻辑,如果应用程序
 *				// 需要在出了回调函数后再用到该帧数据.
 *				// 那么需要拷贝到应用程序的内存中去,否则
 *				// 出了本函数的范围,frame.pixtel_data的内存数据将
 *				// 会被释放掉.如下的流程显示了拷贝的动作.
 *				VMUINT app_frame_data_size = 0;
 *				VMUINT8* app_frame_data = NULL;
 *				
 *				if (frame.pixtel_format == PIXTEL_RGB565 || frame.pixtel_format == PIXTEL_BGR565)
 *					app_frame_data_size = row_pixel * col_pixel * 2;
 *				else if (frame.pixtel_format == PIXTEL_RGB888 || frame.pixtel_format == PIXTEL_BGR888)
 *					app_frame_data_size = row_pixel * col_pixel * 3;
 *				else
 *					app_frame_data_size = row_pixel * col_pixel * 4;
 *
 *				if ((app_frame_data = vm_malloc(app_frame_data_size)) != NULL)
 *				{
 *					memcpy(app_frame_data, frame.pixtel_data, app_frame_data_size);
 *				}
 *				else
 *				{
 *					// 内存不足, 假设我们现在只需要把preview下来的
 *					// 图象刷到屏幕上,则可以按以下的伪代码操作.
 *					// if (frame.rgbformat == 屏幕缓冲区的格式)
 *					// {
 *					//     copy frame.pixtel_data to screen buffer;
 *					//     flush screen buffer;
 *					//  }
 *				}
 *				
 *			}
 *			break;
 *		case ......
 *    		}
 *	}
 * }
 * @endcode
 * @param[in]					handle 摄像头句柄.
 * @param[out]				frame_data 数据帧,只有在返回VM_CAM_SUCCESS下才得到了
 *							预览数据帧.
 * @return 					是否成功得到预览帧的返回值.
 * @retval					VM_CAM_SUCCESS 摄像头句柄. 
 * @retval					VM_CAM_ERR_OPERATE_BAD_STATUS 在错误的状态下调用了本函数.
 * @retval					VM_CAM_ERR_INVALID_CAM_HANDLE 错误的摄像头句柄.
 * @retval					VM_CAM_ERR_BAD_PARAM 在参数frame_data为NULL的时候本错误码将会被返回.
 * @retval					VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE 如果VRE不支持摄像头的功能那么
 *							本参数将会被返回.
 * @see						vm_camera_preview_start
 * @see						vm_camera_preview_stop
 */
VMINT vm_camera_get_frame(VM_CAMERA_HANDLE handle, vm_cam_frame_data_t* frame_data);

/**
 * 得到VRE支持最大照片分辨率,本函数能在摄像头的任何状态下被调用.
 *
 * @param[in]				handle 摄像头句柄.
 * @param[out]			size 照片分辨率的指针.
 * @return				得到VRE支持的最大照片分辨率是否成功.
 * @retval				VM_CAM_SUCCESS 得到VRE 支持的最大照片分辨率成功.
 * @retval				VM_CAM_ERR_BAD_PARAM 错误的参数.
 * @retval				VM_CAM_ERR_INVALID_CAM_HANDLE 错误的摄像头句柄.
 * @retval				VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE 如果VRE不支持摄像头的功能那么
 *						本参数将会被返回.
 * @see					vm_camera_set_capture_size
 * 
 */
VMINT vm_camera_get_max_capture_size(VM_CAMERA_HANDLE handle, vm_cam_size_t* size);

/**
 * 设置摄像头照片的分分辨率,本操作可以在非VM_CAM_CAPTURING_STATUS
 * 的任何状态下执行.
 * 
 * @param[in]					handle 摄像头句柄.
 * @param[in]					size	照片分辨率.
 * @return					是否设置成功.
 * @retval					VM_CAM_SUCCESS 设置拍摄尺寸成功.
 * @retval					VM_CAM_ERR_OPERATE_BAD_STATUS 如果在VM_CAM_CAPTURING_STATUS下调用本
 *							函数本错误码将会被返回.
 * @retval					VM_CAM_ERR_INVALID_CAM_HANDLE 错误的摄像头句柄.
 * @retval					VM_CAM_ERR_BAD_PARAM 如果size参数为NULL,或照片的宽和高的分辨率
 *							不合法,本错误码将会被返回.
 * @retval					VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE 如果VRE不支持摄像头的功能那么
 *							本参数将会被返回.
 * @see						vm_camera_get_max_capture_size
 */
VMINT vm_camera_set_capture_size(VM_CAMERA_HANDLE handle, const vm_cam_size_t* size);

/**
 * 用摄像头拍照.
 * 
 * @param[in]					handle 摄像头句柄.
 * @return					系统是否接受该本操作.
 * @retval					VM_CAM_SUCCESS 接受本操作,摄像头进入VM_CAM_CAPTURING_STATUS状态.
 * @retval					VM_CAM_ERR_INVALID_CAM_HANDLE 错误的摄像头句柄.
 * @retval					VM_CAM_ERR_OPERATE_BAD_STATUS 在本状态下不允许拍照操作.
 * @retval					VM_CAM_ERR_NOT_REGISTER_NOTIFY 如果还没有注册回调函数就调用本操作,
 *							那么该错误将会被返回.
 * @retval					VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE 如果VRE不支持摄像头的功能那么
 *							本参数将会被返回.
 * @see						vm_camera_set_capture_size
 * 
 */
VMINT vm_camera_capture(VM_CAMERA_HANDLE handle);


/**
 * 得到摄像头拍的照片数据及其描述信息,本函数只能在收到
 * VM_CAM_CAPTURE_DONE消息时调用.
 * 
 * @param[in]					handle 摄像头句柄.						
 * @param[out]				capture_data	系统将会把拍照数据和描述写入该结构体的
 *							成员变量中.
 * @return					是否得到拍照数据成功.						
 * @retval					VM_CAM_SUCCESS 成功得到拍照数据.
 * @retval					VM_CAM_ERR_INVALID_CAM_HANDLE 错误的摄像头句柄.
 * @retval					VM_CAM_ERR_OPERATE_BAD_STATUS 在错误了的状态下执行本操作.
 * @retval					VM_CAM_ERR_UNSPPUORT_CAMERA_FEATURE 如果VRE不支持摄像头的功能那么
 *							本参数将会被返回.
 * @see						vm_camera_capture
 */
VMINT vm_camera_get_capture_data(VM_CAMERA_HANDLE handle, vm_cam_capture_data_t* capture_data);

#ifdef __cplusplus
}
#endif

#endif

