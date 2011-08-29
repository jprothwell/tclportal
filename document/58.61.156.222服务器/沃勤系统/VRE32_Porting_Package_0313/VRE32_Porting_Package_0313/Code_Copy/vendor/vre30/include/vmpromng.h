#ifndef	_VM_PRO_MNG_
#define _VM_PRO_MNG_

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"
#include "vmmem.h"

typedef VMINT VM_P_HANDLE;

//process procedure related interfaces

#define	VM_PMNG_OP_OK					(0)
#define   VM_PMNG_PROCESS_NO_EXISTS		(-1)
#define	VM_PMNG_NO_OP_IN_STATUS			(-2)
#define 	VM_PMNG_ERROR_PARAM				(-3)
#define 	VM_PMNG_NO_MEM					(-4)
#define 	VM_PMNG_ERROR_IO					(-5)
#define	VM_PMNG_NO_SCHEDULE				(-6)
#define	VM_PMNG_EXIT						(-7)
#define	VM_PMNG_CERT_FAIL                            (-8)
#define	VM_PMNG_ERROR_FUNLST                     (-9)

#define 	VM_PMNG_SEC_TAG_PLATFORM_PARAM_DISMATCH		(-10)
#define	VM_PMNG_SEC_APP_TIMESTAMP_ERROR				(-11)
#define	VM_PMNG_SEC_IMSI_DISMATCH						(-12)
#define	VM_PMNG_SEC_BAN_LIST_APP						(-13)
#define 	VM_PMNG_SEC_INVALIDATE_APP						(-14)
#define 	VM_PMNG_SEC_CERT_OVREDUE						(-15)
#define 	VM_PMNG_SEC_CERT_SMALL_SYS_MEM					(-16)

#define	VM_PMNG_EXCEED_MAX_PROCESS_NUM				(-17)

#define	VM_PMNG_CUR_HANDLE				(0x0f)

#define VM_PMNG_KERNEL_HANDLE			(0)


typedef enum 
{
	VM_PMNG_UNLOAD = 0,			/**<进程已经被卸载的状态。												*/
	VM_PMNG_FOREGROUND, 			/**<进程在前台运行状态。													*/
	VM_PMNG_BACKGROUND,			/**<进程在后台运行状态。													*/ 
	VM_PMNG_MAX_NUM
}VM_PROCESS_STATUS;


/**
 * 初始化进程管理器，本函数只需要在VRE启动的时候被调用。
 *
 * @return 初始化成功返回 VM_PMNG_OP_OK, 否则返回负数的错误码。
*/
VMINT vm_pmng_init(void);

/**
 * 停止进程管理器，本函数需要在所有模块被释放只后才被
 * 调用。本函数只能在退出VRE的时候被调用。
*/
void vm_pmng_finialize(void);

/**
 * 创建进程调度到前台运行，如果该进程已经被创建则会被
 * 调度到前台运行。如果该进程由于某些原因不能被调度到
 * 前台运行则本函数将会返回失败。对于非VRE Kernel(VAM)进程只有
 * 在Foreground 状态下才能调用本函数，并且调用本函数的进程
 * 会收到HIDE消息，被调度到Background 状态。
 *  
 * @param[in] 	file_name 装载的应用的文件名。
 * @param[in]		app_name，应用程序名称。
 * @return		创建成功时返回进程id, 否则返回负数的错误码
 * @retval		大于0的数表示进程的ID。
 * @retval		VM_PMNG_NO_OP_IN_STATUS 当前运行的进程不在Foreground状态，
 *				不能调用本函数。
 * @retval		VM_PMNG_ERROR_PARAM 如果file_name为NULL则本错误码将会返回。
 * @retval		VM_PMNG_ERROR_IO 如果在IO的时候失败则返回本错误码，对于
 *				已经加载的进程本错误码不会返回。
 * @retval		VM_PMNG_NO_MEM 没有内存加载该应用，对于已经加载的进程本错误码不会返回。
 * @retval		VM_PMNG_NO_SCHEDULE 已经被加载的进程不能被调度到前台运行。
 * @retval		VM_PMNG_SEC_TAG_PLATFORM_PARAM_DISMATCH 平台参数与应用TAG不匹配，创建进程失败。
 * @retval		VM_PMNG_SEC_APP_TIMESTAMP_ERROR 应用程序不在有效期，创建进程失败。
 * @retval		VM_PMNG_SEC_IMSI_DISMATCH	IMSI号与应用程序不匹配，创建进程失败。
 * @retval		VM_PMNG_SEC_BAN_LIST_APP 应用程序为黑名单应用，创建进程失败。
 * @retval		VM_PMNG_SEC_INVALIDATE_APP 应用的证书验证失败，创建进程失败。
 * @retval		VM_PMNG_SEC_CERT_OVREDUE 证书过期。
*/
VM_P_HANDLE vm_pmng_create_process(VMWSTR file_name, vm_multi_lang_app_name_t* app_name, void (*mem_retry_callback)(void));

/**
 * 删除进程，本函数只能由VAM或指定p_handle的父进程调用。在没有进程运行时，
 * 并且VAM退出的情况下，会把VRE的环境停止。
 *  
 * @param[in] 	p_handle	进程ID。
 *
 * @return		操作结果。
 * @retval		VM_PMNG_OP_OK 删除成功。
 * @retval		VM_PMNG_PROCESS_NO_EXISTS 指定的进程不存在。
 */
VMINT vm_pmng_delete_process(VM_P_HANDLE p_handle);

/*
 * 进程把自己设置成后台运行，如果本函数返回VM_PMNG_OP_OK，
 * 那么进程不应该再对UI进程操作，在调用本函数前就应该
 * 关闭UI资源，本函数应该在进程在Foreground状态下才允许调用。
 *  
 * @return	操作结果。
 * @retval	VM_PMNG_OP_OK 操作成功。
 * @retval	VM_PMNG_NO_OP_IN_STATUS 当前状态下不允许调用。
*/
VMINT vm_pmng_set_bg(void);

/*
 * 获得系统可装载进程的最大个数。
 *  
 * @return 	可运行的进程的个数（根据系统配置而定），返回大于0的正整数。
*/
VMINT vm_pmng_max_counter(void);

/*
 * 获得当前系统已加载的进程的个数。
 *  
 * @return		已经加载的进程个数，返回大于等于0的正整数。
 */
VMINT vm_pmng_current_counter(void);

/*
 * 获得前台运行的进程的ID。
 *  
 * @return		当前运行的进程ID。
 * @retval		大于0的数表示当前正在运行进程的ID。
 * @retval		等于0表示当前没有进程在前台运行。
*/
VM_P_HANDLE vm_pmng_fg_process(void);

/*
 * 获得进程的状态
 *  
 * @param[in] 	p_handle	表示需要查询状态进程ID，如果需要查询
 *			       调用本函数进程的状态则本参数应该是
 *				VM_PMNG_CUR_HANDLE 。
 *
 * @return		进程的状态。
 * @retval		VM_PMNG_FOREGROUND 前台运行状态。
 * @retval		VM_PMNG_BACKGROUND 后台运行状态。
 * @retval		VM_PMNG_PAUSED 停止状态。
 * @retval		VM_PMNG_UNLOAD 未加载状态。
*/
VM_PROCESS_STATUS vm_pmng_state(VM_P_HANDLE p_handle);

/*
 * 判断指定进程是否在前台运行。
 *  
 * @param[in] 	p_handle	进程ID，VM_PMNG_CUR_HANDLE 表示当前进程ID。
 * @return		指定进程是否前台运行。
 * @retval		TRUE 表示在前台运行。
 * @retval		FALSE 表示不在前台运行。
*/
VMINT vm_pmng_is_fg(VM_P_HANDLE p_handle);

/*
 * 向指定的进程发送消息。
 *  
 * @param[in] 	p_handle	需要发送到的进程ID。
 * @param[in]		user_message	 用户消息必须是大于等于5000。
 * @param[in]		memsage_param 消息参数。
 *
 * @return		成功时返回VM_PMNG_OP_OK, 否则返回负数的错误码。
 * @retval		VM_PMNG_OP_OK 表示发送成功。
 * @retval		VM_PMNG_PROCESS_NO_EXISTS 进程ID 指定的进程不存在。
 * @retval		VM_PMNG_ERROR_PARAM 如果user_message不大于5000则本函数会返回该本数值。
*/
VMINT vm_pmng_send_sys_msg(VM_P_HANDLE p_handle, VMINT user_message, VMINT memsage_param);

/**
 * 这个函数是设置进程运行环境callback与恢复进程
 * 运行环境的宏。使用方式如下:
 * 
 * PMNG_WRAP_CALLBACK(p_handle, app_callback(param));
 */
#define	PMNG_WRAP_CALLBACK(PHANDLE, APP_CALLBACK_CALLER) \
	if (vm_pmng_set_ctx(PHANDLE) == VM_PMNG_OP_OK){\
		APP_CALLBACK_CALLER;\
		vm_pmng_reset_ctx();\
	}

/*
 * 设置指定进程的运行环境，在callback到进程空间代码段前
 * 必须调用本函数。在callback函数执行完毕，必须调用
 * vm_pmng_reset_ctx释放该运行环境。
 * 
 * @code
 * if (vm_pmng_set_ctx(handle) == VM_PMNG_OP_OK)
 * {
 *     app_callback(event);
 *     vm_pmng_reset_ctx();
 * }
 * @endcode
 * @param[in] 	p_handle	进程ID。
 * @return		设置是否成功。
 * @retval		VM_PMNG_OP_OK 设置成功。
 * @retval		VM_PMNG_PROCESS_NO_EXISTS 指定的进程不存在。
 * @retval		VM_PMNG_NO_OP_IN_STATUS 如果不调用vm_pmng_reset_ctx第二次
 * 				调用本函数的时候就会返回本返回值。
 * @note			vm_pmng_reset_ctx
*/
VMINT vm_pmng_set_ctx(VM_P_HANDLE p_handle);

/*
 * 恢复当前进程设置，该函数恢复vm_pmng_set_ctx调用前
 * 的进程设置环境。
 *  
 * @return		恢复环境是否成功。
 * @retval		VM_PMNG_OP_OK 成功。
 * @retval		VM_PMNG_NO_OP_IN_STATUS 如果没有调用vm_pmng_set_ctx
 * 				就调用本函数，那么本错误码将会被返回。
*/
VMINT vm_pmng_reset_ctx(void);

/*
 * 获取指定进程ID的应用程序文件名。
 *  
 * @param[in] 	p_handle	进程ID，VM_PMNG_CUR_HANDLE 表示当前进程ID。
 * @param[out] 	filename_buf	接受文件名的缓存。
 * @param[in]		filename_len filename_buf所指内容能够放多少个字符。
 * 
 * @return		得到程序文件名称是否成功。
 * @retval		VM_PMNG_OP_OK 操作成功。
 * @retval		VM_PMNG_ERROR_PARAM 如果filename 为NULL则本函数将会被返回。
 * @retval		VM_PMNG_PROCESS_NO_EXISTS 指定的进程ID的进程还没有被加载。
*/
VMINT vm_pmng_file_name(VM_P_HANDLE p_handle, VMWCHAR* filename_buf, VMINT filename_len);

/**
 * 终止挂在后台运行的应用程序，由VAM调用，本函数不会退出VRE环境。
 * 
 * @param[in]		filename 应用程序名称，必须包含路径。
 * @return		是否终止应用程序的返回值。
 * @retval		VM_PMNG_PROCESS_NO_EXISTS 指定的文件名的应用程序根本没有被加载过。
 * @retval		VM_PMNG_NO_OP_IN_STATUS 进程在前台运行无法终止。
 * @retval		VM_PMNG_OP_OK 终止进程成功。
 */
VMINT vm_pmng_destroy_bg_process(VMWSTR filename);

/**
 * 得到指定状态的进程列表，在不使用pHandle时，必须调用_vm_kernel_free释放之。
 * 
 * @param[in]			status 需要得到进程所处的状态。
 * @param[out]		pHandle 进程编号列表。
 * @param[out]		process_num 进程个数。
 * @return			是否成功得到指定状态的进程列表。
 * @retval			VM_PMNG_OP_OK 成功。
 * @retval			VM_PMNG_ERROR_PARAM 错误的参数。
 * @retval			VM_PMNG_NO_MEM 内存不够。
 */
VMINT vm_pmng_get_process_lst(VM_PROCESS_STATUS status, VM_P_HANDLE** pHandle, 
	VMUINT* process_num);

/*
 * 获取指定进程的应用ID。
 *  
 * @param 	p_handle	进程ID，VM_PMNG_CUR_HANDLE 表示当前进程ID。
 *
 * @return	成功时返回应用ID, 否则返回0。
*/
VMINT vm_pmng_app_id(VM_P_HANDLE p_handle);

/*
 * 获取当前在正在运行的APP 或SM 进程ID。
 *  
 * @return	成功时返回进程ID, 否则返回负数的错误码。
 * @retval	大于0的正整数表示进程ID。
 * @retval	0 表示没有进程正在运行。
 *			
*/
VM_P_HANDLE vm_pmng_get_current_handle(void);

/*
 * 获取当前在正在运行的APP 进程ID。
 *  
 * @return	成功时返回进程ID, 否则返回负数的错误码。
 * @retval	大于0的正整数表示进程ID。
 * @retval	0 表示没有进程正在运行。
 *			
*/
VMINT vm_pmng_get_app_handle(void);

/**
 * 后台应用提示用户切换到前台运行的通知方式。
 */
typedef enum 
{
	VM_NOTIFY_TYPE_SILENCE,			/**<安静模式提示*/
	VM_NOTIFY_TYPE_SOUND = 1,			/**<播放声音的方式提示。		*/
	VM_NOTIFY_TYPE_VIBRATILITY = 2	/**<使手机震动的方式提示。 	*/
} VM_FG_NOTIFY_TYPE;

/**
 * 应用申请到前台运行，调用本函数VRE会以应用指定的方式，
 * 通知用户，后台应用需要切换到前台运行。本函数只能在
 * 应用还在后台时调用。以下是事例代码。
 * 
 * @code
 * vm_pmng_apply_to_run_in_fg(VM_NOTIFY_TYPE_SILENCE); 	// 以安静方式闪动提示用户。
 * @endcode
 * @code
 * vm_pmng_apply_to_run_in_fg(VM_NOTIFY_TYPE_SOUND); 	// 只以声音的方式提示用户。
 * @endcode
 * @code
 * vm_pmng_apply_to_run_in_fg(VM_NOTIFY_TYPE_VIBRATILITY); // 只以震动的方式提示用户。
 * @endcode
 * @code
 * vm_pmng_apply_to_run_in_fg(VM_NOTIFY_TYPE_SOUND | VM_NOTIFY_TYPE_VIBRATILITY); // 以声音加震动的方式提示用户。
 * @endcode
 * @param[in]				notify_type 通知的方式。
 */
VMINT vm_pmng_apply_to_run_in_fg(VMINT notify_type);

/**
 * 指定的进程句柄的进程是否支持后台运行。
 *
 *
 * @param[in]					p_handle 为VM_PMNG_CUR_HANDLE表示查询当前进程是否支持BG,否则为进程号。
 * @return					TRUE表示支持,FALSE则表示不支持。
 *
 */
VMINT vm_pmng_is_support_bg(VM_P_HANDLE p_handle);

/*
 *	查询app是否在FG运行
 *  
 *  @param 	appid		应用编号。
 *
 *	@return	如果app在FG运行返回1, 否则返回0。
*/
//VMINT vm_pmng_is_fg_by_appid( VMINT appid );

/*
 *	查询app是否在BG运行
 *  
 *  @param 	appid		应用编号。
 *
 *	@return	如果app在BG运行返回1, 否则返回0。
*/
//VMINT vm_pmng_is_bg_by_appid( VMINT appid );


/*
 * 查询appstore是否在运行,并且返回前台/后台的状态
 *  
 * @param 	running_state		接受前台/后台状态的数据的指针
 * @return	如果appstore在运行返回1, 否则返回0。
 *					返回值是1的情况下，并且appstroe在前台运行，running_state指向的数据为VM_PMNG_FG_RUNNING。 
 *					返回值是1的情况下，并且appstroe在后台运行，running_state指向的数据为VM_PMNG_BG_RUNNING。  
*/
//VMINT vm_pmng_as_running( VMINT * running_state );


/*
临时接口 MP后需要删除,
为了模拟VRE 发 VM_MSG_SCREEN_ROTATE 消息  ,参数为 模拟VRE 建议应用翻转的角度
可以传入的参数建议为以下四种之一
VM_GRAPHIC_SCREEN_ROTATE_0
VM_GRAPHIC_SCREEN_ROTATE_90
VM_GRAPHIC_SCREEN_ROTATE_180
VM_GRAPHIC_SCREEN_ROTATE_270
否则
也发 VM_MSG_ROTATE	消息,不过 建议的翻转角度 为 
VM_GRAPHIC_SCREEN_ROTATE_0
*/
void vm_graphic_rotate_temp(VMINT _rotate_value);



/*
VRE 用来接收 design house 发过来的屏幕翻转多少度
*/
void vm_sensors_rotate(VMINT _rotate_value);



#ifdef __cplusplus
}
#endif 
#endif