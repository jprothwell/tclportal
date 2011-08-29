#ifndef __VM_ENV__
#define __VM_ENV__

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"
#include "vmdl.h"
#include "vmpromng.h"
#include "vmnvram.h"


typedef enum {
	VRE_EVT_START_SUCCESS = 0,			/**<ASM内存分配成功，VRE启动成功。 								*/
	VRE_EVT_START_INTERNEL_ERROR,		/**<系统在启动过程中内部失败。									*/
	VRE_EVT_QUIT							/**<VRE 即将退出的消息。 												*/
} VAM_START_VRE_EVT;

typedef void (*vm_vre_evt_cb_t)(VAM_START_VRE_EVT evt);

#define VM_VLC_START_SUCCESS					(0)
#define VM_VLC_ASYN_ALLOC_ASM					(1)
#define VM_VLC_ASYN_DATAACCOUNT_CHECK			(2)
#define VM_VLC_MASS_STORAGE					(-1)
#define VM_VLC_MEDIA_BUFFER_ALLOC_ERROR		(-2)
#define VM_VLC_INTERNEL_ERROR					(-3)

/**
 * 启动VRE 环境，但是不会注册Pen, Keyboard的消息处理也不会
 * 创建VRE 的SCREEN。但关于SCREEN有一个例外，在VRE使用ASM
 * 内存并且内存没有分配到的时候，ASM Framework可能会有自己
 * 的Popup Screen。如果VRE环境已经启动则调用本函数不会有任何
 * 的处理，并且返回启动成功。
 * 
 * @param[in]					state 当前没有用到，默认为0。
 * @return					启动VRE是否成功的返回值。
 * @retval					VM_VLC_START_SUCCESS 启动成功。
 * @retval					VM_VLC_ASYN_ALLOC_ASM ASM没有分配到
 *							系统将异步释放掉其它占用ASM的应用。
 * @retval					VM_VLC_MASS_STOREAGE 手机处在存储模式，VRE启动失败。
 * @retval					VM_VLC_MEDIA_BUFFER_ALLOC_ERROR VRE申请media buffer失败。
 * @retval					VM_VLC_INTERNEL_ERROR VRE内部错误。
 */
VMINT vm_vam_load_core(vm_vre_evt_cb_t vam_cb);

/*
 * 应用程序错误。
 */
typedef void (*vm_vre_app_evt_cb_t)(VMUWSTR fileName, VAM_START_VRE_EVT evt);

/**
 * @name vm_execute函数的返回值
 * @{
 */
/**
 * 成功启动了指定应用。
 */
#define VM_EXECUTE_APP_SUCCESS					(0)

/**
 * 指定应用为非法的应用程序。
 */
#define VM_EXECUTE_APP_ILLEGAL					(-1)

/**
 * 没有足够的内存启动应用，
 * 返回该错误码前VRE会显示当前已经启动应用的列表。
 */
#define VM_EXECUTE_APP_NOT_ENOUGH_MEMORY		(-2)

/**
 * 启动栈已满。
 */
#define VM_EXECUTE_APP_CALL_STACK_FULL			(-3)

/**
 * 启动内核内部错误，包括IO读取错误等。
 */
#define VM_EXECUTE_INTERNAL_ERROR				(-4)

/**
 * 应用程序运行参数与平台参数不匹配。
 */
#define VM_EXECUTE_PLATFORM_PARAM_DISMATCH		(-5)

/**
 * 应用程序超过有效期。
 */
#define VM_EXECUTE_TIMESTAMP_ERROR				(-6)

/**
 * 是黑名单的应用不能启动。
 */
#define VM_EXECUTE_BANNED_APP					(-7)

/**
 * 应用程序的IMSI号与平台的IMSI不匹配，启动失败。
 */
#define VM_EXECUTE_IMSI_DISMATCH					(-8)

/**
 * 应用程序使用的证书过期。
 */
#define VM_EXECUTE_CERT_OVERDUE					(-9)

/**
 * 在VRE目录下文件超过5000个则返回该错误码。
 */
#define VM_EXECUTE_EXCEED_FILE_IN_VRE_DIRECTORY (-10)

/**
 * 系统没有足够的内存启动该应用。如果退出所有的应用也不能启动该
 * 应用则本返回数值会被返回。
 */
#define VM_EXECUTE_SYS_NOT_ENOUGH_MEMORY		(-11)

/**
 * 超出VRE允许同时启动运行的最大个数。
 */
#define VM_EXECUTE_EXCEED_MAX_APP_NUM			(-12)
/**@} */

/**
 * 启动应用程序。如果应用启动成功，VRE 会创建VRE 的SCREEN，
 * 失败则不会创建。如果该文件已经被启动，则VRE会直接把
 * 该应用调度到前台。
 * 
 * @param[in]				filename 需要启动的文件名称，需要包含的路径。
 * @param[in]				retry_callback 重新启动
 * @return				是否成功启动了应用程序的返回值。
 * @retval				VM_EXECUTE_APP_SUCCESS 启动应用程序成功。
 * @retval				VM_EXECUTE_APP_ILLEGAL 非法的应用程序。
 * @retval				VM_EXECUTE_APP_NOT_ENOUGH_MEMORY 没有足够的内存启动应用程序。
 * @retval				VM_EXECUTE_APP_CALL_STACK_FULL 调用堆栈已满。
 * @retval				VM_EXECUTE_INTERNAL_ERROR 启动内核内部错误。
 * @retval				VM_EXECUTE_PLATFORM_PARAM_DISMATCH 平台参数不匹配。
 * @retval				VM_EXECUTE_TIMESTAMP_ERROR 应用程序超过有效期。
 * @retval				VM_EXECUTE_BANNED_APP 是黑名单的应用不能启动。
 * @retval				VM_EXECUTE_IMSI_DISMATCH 应用程序的IMSI号与平台的IMSI不匹配，启动失败。
 * @retval				VM_EXECUTE_CERT_OVERDUE 应用程序使用的证书过期。
 * @retval				VM_EXECUTE_EXCEED_FILE_IN_VRE_DIRECTORY VRE目录下文件超过5000个返回该错误码。
 * @retval				VM_EXECUTE_SYS_NOT_ENOUGH_MEMORY 应用所需要内存过大，系统无法满足需求。
 */
VMINT vm_execute(VMWSTR filename, void (*retry_callback)(void));

/**
 * 带参数启动应用程序。param为传入的VMWSTR类型指针，其余参见vm_execute()说明。
 * 
 * @param[in]			filename 需要启动的文件名称，需要包含的路径。
 * @param[in]			param 传入的VMWSTR类型参数指针。
 * @return				参见vm_execute()说明。
 */
VMINT vm_execute_ex(VMWSTR filename, VMWSTR param);

/**
 * 已经运行的应用程序信息。
 */
typedef struct vm_running_app_info_t
{
	VMWCHAR app_filename[MAX_APP_NAME_LEN + 1];		/**< 当前已经运行的应用程序的名称。*/
	VMINT app_id;										/**< 应用程序编号。							*/
	VMUINT alloc_mem;									/**< 内存占用量，单位为KB。 				*/
}vm_running_app_info_t;

/**
 * 启动应用程序，如果返回VM_EXECUTE_APP_NOT_ENOUGH_MEMORY，则会向bg_app_infos与
 * app_info_num指针的位置写入当前正在后台运行的进程列表及个数。
 * 在不使用bg_app_infos所指向内存时，必须调用vm_release_app_running_infos释放
 * exist_app_infos所指向的对象。
 *
 * @code 
 * VMINT ret = VM_EXECUTE_APP_SUCCESS;
 * VMUINT infos_num = 0;
 * vm_running_app_info_t* infos = NULL;
 * 
 * ret = vm_execute_app((VMWSTR)L"c:\\vre\\game.vxp", &infos, &infos_num);
 * switch (ret)
 * {
 * case VM_EXECUTE_APP_NOT_ENOUGH_MEMORY:
 *     // 提示用户退出应用可以启动新应用。
 *     if (infos != NULL)
 *     {
 *         vm_release_app_running_infos(infos);
 *     }
 *     break;
 * case VM_EXECUTE_SYS_NOT_ENOUGH_MEMORY:
 *     // 提示应用无法运行，内存需求过大。
 *     break;
 * case VM_EXECUTE_TIMESTAMP_ERROR:
 *     ......
 * }
 * @endcode
 * 
 * @param[in]				filename 需要启动的文件名称。
 * @param[out]			bg_app_infos 正在后台运行的应用程序的信息。
 * @param[out]			app_info_num 正在后台运行的应用程序信息个数。
 * @param[in]				filename 需要启动的文件名称，需要包含的路径。
 * 
 * @return				是否成功启动了应用程序的返回值。
 * @retval				VM_EXECUTE_APP_SUCCESS 启动应用程序成功。
 * @retval				VM_EXECUTE_APP_ILLEGAL 非法的应用程序。
 * @retval				VM_EXECUTE_APP_NOT_ENOUGH_MEMORY 没有足够的内存启动应用程序。
 * @retval				VM_EXECUTE_APP_CALL_STACK_FULL 调用堆栈已满。
 * @retval				VM_EXECUTE_INTERNAL_ERROR 启动内核内部错误。
 * @retval				VM_EXECUTE_PLATFORM_PARAM_DISMATCH 平台参数不匹配。
 * @retval				VM_EXECUTE_TIMESTAMP_ERROR 应用程序超过有效期。
 * @retval				VM_EXECUTE_BANNED_APP 是黑名单的应用不能启动。
 * @retval				VM_EXECUTE_IMSI_DISMATCH 应用程序的IMSI号与平台的IMSI不匹配，启动失败。
 * @retval				VM_EXECUTE_CERT_OVERDUE 应用程序使用的证书过期。
 * @retval				VM_EXECUTE_EXCEED_FILE_IN_VRE_DIRECTORY VRE目录下文件超过5000个返回该错误码。
 * @retval				VM_EXECUTE_SYS_NOT_ENOUGH_MEMORY 应用所需要内存过大，系统无法满足需求。
 * 
 * @see					vm_release_app_running_infos
 */
//VMINT vm_execute_app(VMWSTR filename, vm_running_app_info_t** bg_app_infos, VMUINT* app_info_num);

/**
 * 带参数启动应用程序，param为传入的VMWSTR类型指针，其余参见vm_execute_app()说明。
 *
 * @param[in]			filename 需要启动的文件名称，需要包含的路径。
 * @param[in]			param 传入的VMWSTR类型参数指针。
 * @param[in]			retry_callback 在返回VM_EXECUTE_APP_NOT_ENOUGH_MEMORY的时候如果其它应用释放了内存则该函数会被回调，
 *								调用者应该再调用本函数来启动应用。
 * 
 * @return				参见vm_execute_app()说明。
 */
VMINT vm_execute_app_ex(VMWSTR filename, VMWSTR param, void (*retry_callback)(void));

/**
 * 得到后台应用程序的信息，如果 得到则需要 调用 vm_release_app_running_infos释放
 * 后台应用程序的 信息 。
 * 
 * @return					后台运行的应用程序的个数。
 * @param[out]				bg_app_infos 正在后台运行的应用程序的信息。
 */
VMINT vm_get_bg_app_infos(vm_running_app_info_t** bg_app_infos);

/**
 * 释放由调用vm_execute_ext产生出来的正在运行的应用程序信息。
 *
 * @param[in]				app_infos 应用程序信息。
 * @see					vm_execute_ext
 */
void vm_release_app_running_infos(vm_running_app_info_t* app_infos);

/**
 * 终止应用程序成功。
 */
#define VM_TERMINATE_SUCCESS					(0)

/**
 * 参数出错。
 */
#define VM_TERMINATE_ERROR_PARAM				(-1)

/**
 * 需要终止的应用程序不存在。
 */
#define VM_TERMINATE_NOT_EXISTS				(-2)

/**
 * 停止在前台运行的进程。
 */
#define VM_TERMINATE_ERROR_STATUS			(-3)

/**
 * 终止后台运行的应用程序。
 * 
 * @code
 * vm_terminate_bg_app((VMWSTR)L"c:\\vre\\game.vxp");
 * @endocde
 * @param[in]					filename 需要终止的应用程序的名称，是绝对路径。
 * @return					是否成功终止应用程序的标志。
 * @retval					VM_TERMINATE_SUCCESS 成功终止应用程序。
 * @retval					VM_TERMINATE_ERROR_PARAM 参数错误。
 * @retval					VM_TERMINATE_NOT_EXISTS 指定的应用程序不存在。
 * @retval					VM_TERMINATE_ERROR_STATUS 停止的应用程序正在前台运行，终止应用
 *							程序失败。
 */
VMINT vm_terminate_bg_app(VMWSTR filename);

/**
 * 如果VRE里有应用正在运行，调用本函数将没有作用;
 * 如果VRE没有运行调用本函数也没有任何作用;
 * 如果VRE没有应用正在运行且VRE环境启动成功，
 * 调用本函数会将VRE环境退出。
 */
void vm_vam_unload_core(void);

#define		VAM_IN_USE					1
#define		VAM_OUT_OF_USE			0

/*
 * 通知内核VAM的状态
 *  
 * @param[in] 			VAM_IN_USE 表示VAM正在运行，VAM_OUT_OF_USE 表示VAM已经退出。
*/
void vm_vam_set_vam_state(VMINT state);

/**
 * VAM 向VRE申请内存。
 * 
 * @param[in]				size 需要申请的内存数。
 * @return				NULL 分配失败，否则为内存的首地址。
 */
void* vm_vam_malloc(VMINT size);

/**
 * VAM 释放内存时调用。
 * 
 * @param[in]				p 需要释放的内存首地址。  
 */
void vm_vam_free(void* p);

/**
 * 重新分配VAM内存，如果给定的内存长度小于原有内存长度，系统不做任何
 * 操作，否则把内存扩大到给定长度，内存中的数据继续保留。如果重分配成功，
 * 则不再需要调用vm_vam_free释放p指针。示例如下:
 * 
 * @code
 * char* ptr = vm_vam_malloc(1024), *tmp = NULL;
 * 
 * if (ptr != NULL)
 * {
 * 	memset(ptr, 0x00, 1024);
 * 	ptr[0] = 'C';
 *	if ((tmp = vm_vam_realloc(ptr, 2048)) != NULL)
 *    {
 *    		tmp[2047] = 'J';
 * 		vm_vam_free(tmp);
 *	}
 *	else
 *	{
 *		vm_vam_free(ptr);
 *	}
 * }
 * @endcode
 * @param[in] 			p 要重新分配的内存指针。
 * @param[in] 			size	新的长度。
 *
 * @return				返回NULL表示重新分配失败，给定的内存指针
 *						指向的内存不释放，否则返回扩展后的内存
 *						指针。
 */
void* vm_vam_realloc(void* p, VMINT size);

/*
 * 判断应用程序是否在运行。
 *
 * @param[in]				vxp_filename	应用的文件名，必须是全路径。
 * @return				如果应用程序正在运行，返回1，否则返回0。
 */
VMINT vm_vam_app_is_running(VMWSTR vxp_filename);

#define		LOAD_VAM_RES_PARAM_ERROR				(-1)
#define		LOAD_VAM_RES_FAIL							(-2)
#define		LOAD_VAM_RES_INSUFFICIENT_BUF			(-3)

/*
 * 从文件中装载指定的资源
 *  
 * @param[in]					filename 文件的名称。
 * @param[in] 				res_name 资源名称。
 * @param[out]				res_size 接受资源长度的指针。
 * @param[in]					cache_buf 外部缓存 。
 * @param[in] 				cache_size 外部缓存的长度。
 * @return					加载资源成功返回0, 否则返回负数的错误码。
*/
int vm_vam_load_resource_from_file( short * filename, char * res_name, int * res_size, char * cache_buf, int cache_size );

/**
 * 语言类型。
 */
typedef enum LANGUAGE_TYPE{
	ENG = 0,		/**<英语。			*/
	CHS,		/**<简体中文。 	*/
	CHT			/**<繁体中文。 	*/
}LANGUAGE_TYPE;

/**
* 从配置文件中获取GIF数据至内存。详见unpackGIFZM.h和unpackGIFZM3.c
* 
* @param[in] 					gifzm 数据源。
* @param[out] 				data_buf 接受数据的缓存。
* @param[out] 				data_len 传回GIF数据长度。
* @return					成功时返回0，否则返回负数的错误码。
*							当data_buf为空时，该接口查询所需要获取的数据的大小，有data_len返回。
*							当data_buf不为空时，data_len的初始值为data_buf的大小, 
*							接口执行完，data_len返回数据的实际大小。
*/
VMINT vm_vam_get_gif_data(VMUINT8 *gifzm, VMUINT8 ** data_buf, VMINT *data_len);

/**
* 从配置文件中获取字符串数据至内存。详见unpackGIFZM.h和unpackGIFZM3.c
* 
* @param[in]					gifzm 数据源。
* @param[out]				data_buf 接受数据的缓存。
* @param[in]					lan 语言类型。
* @param[out]				data_len 传回string数据长度。
* @param[out]				font 传回字符串字体大小。
* @param[out]               data_size 字模size
* @return					成功时返回0，否则返回负数的错误码。
*							当data_buf为空时，该接口查询所需要获取的数据的大小，有data_len返回。
*							当data_buf不为空时，data_len的初始值为data_buf的大小, 
*							接口执行完，data_len返回数据的实际大小。
*/
VMINT vm_vam_get_string_data(VMUINT8* gifzm, VMUINT8** data_buf, LANGUAGE_TYPE lan, VMINT* data_len, VMINT* font, VMINT *data_size);


/**
 * 获取像素宽度
 * @param[in] zimo_buf 指向字模数据的指针 
 * @param[in] str_len 字符个数 
 *
 * @return  字模的像素宽度 
 */
VMINT vm_vam_measure_zimo_string(VMUINT8 *zimo_buf, VMINT str_len);

/**
* 从字符串缓冲获取数据绘制到目标缓冲中。
* 
* @param[out]				dst_buf 目标缓冲
* @param[in] 					x 字符串的左上角横坐标
* @param[in]					y 字符串的左上角纵坐标
* @param[in]					start_idx 起始位置Index，Index从0开始
* @param[in]					out_str_len 输出字符串长度，可以小于实际字符串长度
* @param[in]					src_buf 字符串缓冲
* @param[in]					str_len 字符串实际长度
* @param[in]					font 字符串字体大小
* @param[in]					color 字符串前景颜色，字符串空白区域以透明方式绘制
*/ 
void vm_vam_draw_text(VMUINT8 *dst_buf, VMINT x, VMINT y, VMINT start_idx, VMINT out_str_len, VMUINT8 *src_buf, VMINT str_len, VMINT font, VMUINT16 color);

/**
 * 检查临时文件是否合法及下载进度。
 * 
 * @param[in]					filename 临时文件的名称。
 * @param[out]				progress	接受进度数据的指针。 
 * @return					如果临时文件合法返回0, 否则返回负数的错误码。
 *							返回0时, progress指向的数据代表进度（0 - 100）。
*/
VMINT vm_vam_check_tempfile(VMSHORT * filename, VMINT* progress);

/**
 * 取消下载。
 */
void vm_vam_cancel_download(void);

/**
 * 设置SIM卡。
 *
 * @param[in]					choose_index 选中的SIM卡编号，1为SIM卡一，2为SIM卡二。
 * @return                                	设置成功返回0，否则返回-1
 */
VMINT vm_vam_set_sim_card(VMINT choose_index);

/**
 * 设置网络类型。
 *
 * @param[in]					net_type 网络类型，1为GPRS，2为WIFI。
 * @return                             	设置成功返回0，否则返回-1
 */
VMINT vm_vam_set_net_type(VMINT net_type);

/**
 * 得到当前已经设置的卡的索引。
 * 
 * @param[out]				得到卡索引的指针。
 * @return					是否成功得到SIM卡索引的标志。
 * @retval					TRUE(1) 成功得到SIM卡索引。
 * @retval					FALSE(0) 失败，没有得到SIM卡索引。
 */
VMINT vm_vam_get_sim_card(VMINT* sim_index);

/**
 * 得到当前网络类型。
 * 
 * @param[out]				得到网络类型的指针。
 * @return					是否成功得到网络类型的标志。
 * @retval					TRUE(1) 成功得到网络类型。
 * @retval					FALSE(0) 失败，没有得到网络类型。
 */
VMINT vm_vam_get_net_type(VMINT* net_type);

/**
 * 设置网络连接点。
 * 
 * @param[in] 				point_type 连接点类型，1为CMWAP，2为CMNET。
 * @return                             	设置成功返回0，否则返回-1
 */
//VMINT vm_vam_set_connection_point(VMINT point_type);

/**
 * 验证应用程序是否有效
 * 
 * @param[in]					vxp_filename VXP文件的文件名，带全路径
 * @return					应用程序验证通过,返回0, 否则返回负数的错误码。参考vmcerter.h
 */
VMINT vm_vam_app_is_valid(VMWSTR vxp_filename);

#define  VAM_DL_DONE             	1  //整个VXP下载完成
#define  VAM_DL_OK               		0  //成功
#define  VAM_DL_ERR              		-1 //失败
#define  VAM_DL_NET_ERR         	-2 //网络错误         
#define  VAM_DL_SAVE_ERR         	-3 //保存错误
#define  VAM_DL_APP_NOT_EXIST  -4 //应用不存在
#define  VAM_DL_SPACE_FULL       	-5 //空间不足
#define  VAM_DL_OTHER_ERR        	-6 //其它错误
#define  VAM_DL_FILE_NOT_EXIST -7 //文件不存在
#define  VAM_DL_IO_ERROR        -8 //I/O 操作错误

#define VAM_DL_1302_ERR -9
#define VAM_DL_1401_ERR -10
#define VAM_DL_1402_ERR -11
#define VAM_DL_1403_ERR -12
#define VAM_DL_1404_ERR -13
#define VAM_DL_1405_ERR -14
#define VAM_DL_1406_ERR -15
#define VAM_DL_1407_ERR -16

//rencai.xiao 2010/04/28 
//download payment notification and rate.
#define AM_DOWNLOAD_PAYMENT_NOTIFICATION

//added by rencai.xiao 2010/05/28 增加错误返回类型
#define  VAM_DL_1302_ERR       -9 //当下载请求的参数有错误时，比如没有带AppId等
#define  VAM_DL_1401_ERR      -10//当下载的产品不存在时，一般是客户端的AppId错误或者产品没有适配该机型的版本。
#define  VAM_DL_1402_ERR      -11//适配机型的产品版本，没有上传对应的文件，一般不会发生，因为后台添加版本时强制必须上传文件。
#define  VAM_DL_1403_ERR      -12//适配版本的文件不存在，一般不会发生，应该是一些意外情况造成文件丢失。
#define  VAM_DL_1404_ERR      -13//文件MD5校验码错误，一般发生在正在下载的文件变更时。目前没有返回该错误码，而是直接返回新文件的MD5校验码，客户端直接重新下载文件。
#define  VAM_DL_1405_ERR      -14//文件下载请求的数据段超出了实际文件的范围，正常情况不会发生。
#define  VAM_DL_1406_ERR      -15//产品被加入黑名单。
#define  VAM_DL_1407_ERR      -16//将1401的两种情况分开，1401表示AppId不存在，1407表示无适配版本。

//added by rencai.xiao 2010/06/03 twice confirm
#define AM_SUPPORT_TWICE_CONFIRM

//added by rencai.xiao 2010/06/19 extend pag config, add mcc to vm_charge_detail_record_t and add pre_string and suff_string to vm_pay_config_t
#define AM_SUPPORT_EXTEND_PAY_CONFIG

/**
 * 发起应用下载* @param download_app_cb     下载应用回调
 *                             @param nResult  下载结果:VAM_DL_OK = 成功发送请求或者成功下载完一块
 *                                                      VAM_DL_DONE = 全部下载完成
 *                                                      VAM_DL_ERR等错误码
                                                        VAM_DL_IO_ERROR 文件操作错误
														VAM_DL_SPACE_FULL 空间不足
 *                             @param nPercent nResult不为VAM_DL_DONE时表示下载进度,否则表示存储盘符
 *
 * @param[in] 			    download_app_cb     下载应用回调。
 * @param[out] 				nResult  下载结果:VAM_DL_OK = 成功发送请求或者成功下载完一块
 *                                            VAM_DL_DONE = 全部下载完成
 *                                            VAM_DL_ERR等错误码
 * @paramp[out] 			nPercent nResult不为VAM_DL_DONE时表示下载进度,否则表示存储盘符
 * @param[in] 				pszVersionID 应用版本号ID。
 * @param[in]				pszFileName 文件名。
 * @param[in] 				nBlockSize 下载块大小。
 * @return                  成功发起下载请求返回VAM_DL_OK, 否则返回错误码(VAM_DL_ERR, VAM_DL_IO_ERROR, VAM_DL_SPACE_FULL)。
 */
VMINT vm_vam_download_app(void(*download_app_cb)(VMINT nResult, VMINT nPercent), 
	VMUINT32 nAppID/*VMWSTR pszVersionID*/, VMWSTR pszFileName, VMINT nBlockSize);


#define			VMM_RET_NO_SYSC_CDR								(0)
#define			VAM_RET_NVRAM_NEED_FOR_SYNC_CDR				(1)
#define			VAM_RET_TIME_NEED_FOR_SYNC_CDR					(2)

/**
 * 是否需要同步计费。
 * 
 * @return					是否需要更新的标志。
 * @retval					VMM_RET_NO_SYSC_CDR 表示不需要更新。
 * @retval					VAM_RET_NVRAM_NEED_FOR_SYNC_CDR NVRAM满需要更新。
 * @retval					VAM_RET_TIME_NEED_FOR_SYNC_CDR 时间到需要更新。
 */
VMINT vm_vam_is_sync_cdr(void);

/**
 * 向服务器同步计费请求。
 * 
 * @param[in/out]				sync_cb 成功或失败的回调，参数nResult为0表示成功否则为失败。
 * @return					成功发起同步返回VAM_DL_OK, 否则返回错误码(VAM_DL_ERR, VAM_DL_IO_ERROR)。
 */
VMINT vm_vam_sync_cdr(void (*sync_cb)(VMINT nResult));

/**
 * 得到用户的余额。
 * 
 * @param[out]				user_balance 用户余额。
 * @return					0 表示已经得到余额，否则为失败。
 */
VMINT vm_vam_get_user_balance(VMUINT* user_balance);

/**
  * 取消计费更新
  */
void vm_vam_cancel_sync_cdr(void);
/**
 * 注册申请释放空间函数
 *
 * @param mem_calloc_cb   申请空间接口
 * @param mem_free_cb     释放空间接口
 */
void vm_am_pre_download_app(void *(* mem_calloc_cb)(int size), void (* mem_free_cb)(void *ptr));


/**
 * 获取应用版本号
 *
 * @param[in] 文件名
 * @param[out] 得到的版本号
 *
 * @return 获取成功返回VAM_DL_OK，否则返回VAM_DL_ERR
 */
VMINT vm_get_app_version(VMWSTR filename, VMINT * version);

/*
 * 检测有无更新的请求
 *
 * @return  如果有应用程序的更新请求，返回更新请求的version id,否则返回null。
 */
VMWSTR vm_vam_need_update(void);

/*
 * 清除更新，当vam获取更新请求的version id后，应该通知vre清除更新的version id。
 */
void vm_vam_clean_update(void);

/**
 * 退出所有进程，退出VRE环境。如果VRE没有启动则调用本函数
 * 将不会有任何作用。
 */
void vm_exit(void);

/**
 * 获取正在下载应用的总大小和已下载大小
 *
 * @param nTotalSize                      应用总大小
 * @param nDownloadedSize            已下载大小
 *
 * @return       获取成功返回VAM_DL_OK，否则返回VAM_DL_ERR
 */
 VMINT vm_get_total_and_downloaded_size(VMUINT * nTotalSize, VMUINT * nDownloadedSize);

/**
 * ASM 回收内存的操作的callback函数。
 */
void vm_exit_by_asm(void);

/**
 * 获得内置程序首地址列表。
 * 
 * @param[out]			app_array_ptr 内置程序首地址列表的指针。
 * @param[out]			app_array_len_ptr 内置程序个数。
 */
void vm_get_buildin_app_array(VMINT** app_array_ptr, VMINT* app_array_len_ptr);

/**
 * 获得VRE是否在使用media memory.
 * 
 * @return 正在使用返回1，否则返回0

 */
VMINT mmi_vre_is_using_media_memory(void);


VMINT vm_get_current_apn_info(vm_apn_info_ext *current_apn_info);

/************************************************************************
* 内存剥离新加入的函数。
************************************************************************/

#include "che_api.h"

/*
 * 初始化md5的状态，在调用vm_vam_md5_append之前必须调用本函数。
 *
 * @code 
 * md5_context md5_context;
 * vm_vam_md5_init(&md5_context);
 * vm_vam_md5_append(&md5_context, data, data_len);
 * vm_vam_md5_append(&md5_context, data2, data2_len);
 * ......
 * vm_vam_md5_finish(&md5_context, digest);
 * @endcode
 * @param[in]				md5_context  计算摘要时的上下文。
 */
void vm_vam_md5_init(STCHE* md5_context);

/**
 * 对需要得到摘要的数据进行添加。
 * 
 * 
 * @param[in]				md5_context 计算摘要时的上下文。
 * @param[in]				data 需要得到摘要的数据。
 * @param[in]				nbytes data所指向的字节个数。
 */
void vm_vam_md5_append(STCHE* md5_context, const VMUINT8* data, VMUINT nbytes);

/**
 * 得到摘要数据。
 * 
 * @param[in]				md5_context 计算摘要时的上下文。
 * @param[out]			md5_digest 摘要信息。
 * 
 */
void vm_vam_md5_finish(STCHE* md5_context, VMUINT8 md5_digest[16]);

/**
 * 设置DES密钥。
 * 
 * @code
 * vm_vam_des_set_key(&ctx, des_key);
 * @endcode
 * @param[in]				des_context DES解密或解密时的上下文。
 * @param[in]				key8字节的密钥。
 * @return				0  表示成功，否则为失败。
 */
VMINT vm_vam_des_set_key(STCHE* des_context, VMUINT8 key[8]);

/**
 * 用DES算法加密数据。
 * 
 * @param[in]				des_context DES加密或解密时的上下文。
 * @param[in]				input 首地址必须是8字节对齐的内存地址，input & 7 必须为0。
 * @param[in]				input_len 需要加密数据的长度。
 * @param[out]			output 首地址必须是8字节对齐的内存地址，output & 7 必须为0。
 * 						所指向的长度为(input_len / 8 + 1) * 8
 * @return				0 表示加密成功，否则返回错误码。
 */
VMINT vm_vam_des_encrypt(STCHE* des_context, 
	VMUINT8* input, VMUINT input_len, VMUINT8* output);

/**
 * 用DES算法解密数据。
 * 
 * @param[in]				des_context DES加密或解密时的上下文。
 * @param[in]				input 首地址必须是8字节对齐的内存地址，input & 0x7 必须为0。
 * @param[in]				input_len 需要解密数据的长度。
 * @param[in]				output 首地址必须是8字节对齐的内存地址，output & 7 必须为0。
 * 						所指向的长度为(input_len  / 8 + 1) * 8
 * @param[out]			output_len 解密出来的明文的字节数。
 * @return				0 表示解密成功，否则返回错误码。
 */
VMINT vm_vam_des_decrypt(STCHE* des_context, 
	VMUINT8 * input, VMUINT input_len, VMUINT8* output, VMUINT* output_len);

/**
 * 重置DES状态，在加密或解密完后都必须调用本函数。
 * 
 * @param[in]				des_context 加密或解密时的上下文。
 */
void vm_vam_des_reset_key(STCHE* des_context);

/**
 * 装载资源，如果res为NULL，则调用本函数得到的为res_size的大小。
 *
 * @code
 * VMUINT res_size = 0;
 * char* res_buffer = NULL;
 * vm_vam_load_resource((VMSHORT*)L"d:\\vre\\cc.vxp", "icon.gif", NULL, &res_size); 		//得到Resource的大小。
 * res_buffer = adm_malloc(res_size);
 * vm_vam_load_resource((VMSHORT*)L"d:\\vre\\cc.vxp", "icon.gif", res_buffer, &res_size);	//得到Resource.
 * @endcode
 * @param[in]	 			filename 文件名称。
 * @param[in]				res_name 资源名称。
 * @param[out]			res 需要填入资源的数据的头指针。
 * @param[out]			res_size res所指向内存的大小。
 * @return				0 表示取得资源成功，否则为失败。
 */
VMINT vm_vam_load_resource(VMSHORT * filename, VMCHAR* res_name, 
	VMCHAR* res, VMUINT* res_size);

/*
 * 获得标记文件中指定的标记内容。如果buff参数为NULL ，则只取得该TAG的大小。
 * 
 * 
 * @param[in] 			filename 文件名称。
 * @param[in]				tag_id  需要获取TAG的ID。
 * @param[out]			buf 获得的标记内容
 * @param[in/out]			buf_size	标记内容的长度
 *	
 * @return				0 表示得到TAG成功，否则为失败。
 */
VMINT vm_vam_get_tag(VMWCHAR* filename, VMINT tag_id, void* buf , int* buf_size);

typedef enum
{
	VM_VAM_LANG_ENG = 1,
	VM_VAM_LANG_CHS,
	VM_VAM_LANG_CHT
}VM_VAM_LANG_ID;

/*
 * 根据语言类型，获得标记文件中指定的标记内容。
 * 如果buff参数为NULL ，则只取得该TAG的大小。
 *  
 * @param[in] 			filename 文件名称。
 * @param[in] 			tag_num  需要获取的标记序号。
 * @param[out] 			buf 获得的标记内容。
 * @param[in/out] 			buf_size 标记内容的长度。
 * @param[in]		 		lang_id 语言类型，为VM_VAM_LANG_ID 类型。
 *	
 * @return				0 表示成功得到标记，否则为失败。
*/
VMINT vm_vam_get_tag_by_lang_id(VMWCHAR* filename, VMINT tag_num, 
	void* buf, VMINT* buf_size, VMINT lang_id);


//added by rencai.xiao 2010/07/22 定义此宏表示支持gzip压缩
#define   AM_SUPPORT_GZIP

/**
 * 客户注册上来的联网检测size的回调
 *
 * @param nResult           联网结果。联网失败该值为VAM_DL_ERR，联网成功该值为VAM_DL_OK
 * @param pData             具体数据,格式见VIP协议
 * @param nDataLen          pData数据长度
 */
typedef void(*check_filesize_cb)(VMINT nResult, VMUINT8* pData, VMINT nDataLen);


/**
 * 联网检测size
 *
 * @check_cb           联网回调
 * @pCheckList         要检测的内容ID列表。格式:各ID之间以","隔开，如：appstore,sm_charge,172111,....
 *
 * @return             成功返回VAM_DL_OK, 否则返回VAM_DL_ERR
 */
VMINT vm_vam_check_filesize(check_filesize_cb check_cb, VMUINT8 * pCheckList);


/**
 *客户注册上来的，检测动态库版本的回调
 *
 * @param nResult     联网结果。联网失败该值为VAM_DL_ERR, 联网成功该值为VAM_DL_OK
 * @param pData       具体数据，格式见VIP协议
 * @param nDataLen    pData数据长度
 */
typedef void(*check_dll_version_cb)(VMINT nResult, VMUINT8 * pData, VMINT nDataLen);


/**
 * 检测动态库版本
 *
 * @param check_dll_cb        联网回调
 * @param pCheckList          要检测的版本列表。格式为SMID:Version, 多个时中间已","分隔。如:sm_charge:3.0.0,....
 *
 * @return                    成功返回VAM_DL_OK,否则返回VAM_DL_ERR
 */
VMINT vm_vam_check_dll_version(check_dll_version_cb check_dll_cb, VMUINT8 * pCheckList);


/**
 *  取消check。正在check filesize 或者dll vresion时，中断或者取消可以调用此接口
 */
void vm_vam_cancel_check(void);
#ifdef __cplusplus
}
#endif
#endif
