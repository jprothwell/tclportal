#ifndef VMDL_H_
#define VMDL_H_

#include "vmsys.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * 应用程序的名称的完整的表示的格式为:
 * "盘符:\\路径\应用程序名称"[?"盘符:\\路径\应用程序名称"]
 * 其中[]中的内容为可选的，如果有则表示需要通过'?'前的应用程序来启动'?'后的应用程序。
 * 
 * 应用程序名称的格式是通过应用程序名称的后缀来区分。
 * (1) rom表示ROM格式。
 * (2) vxp表示VXP格式。
 * (3) axf表示AXF格式。
 */
 
/**
 * 支持的应用程序的名称完整表示的最大字符个数。
 * VRE里支持的全路径的文件名称的最大个数为260个字符
 */
#define MAX_APP_NAME_LEN					(260)

/**
 * 应用程序启动的重定向的分隔符号。
 */
#define REDIRECT_APPNAME_SEPARATOR		L'?'

/**
 * symbol的类型。
 */
typedef VMINT (*vm_get_sym_entry_t)(char* sym);

/**
 * 所执行的应用程序名称的格式。
 */
typedef enum
{
	VM_EXEC_VXP,		/**<VXP格式，表示应用程序以文件的形式存在，存储在文件系统中。 		*/
	VM_EXEC_AXF,		/**<AXF格式。表示应用程序以文件的形式存在，存储在文件系统中。 		*/
	VM_EXEC_ROM,		/**<ROM格式。表示应用程序以字节数组的形式存在，存储在ROM DATA中。 	*/
	VM_EXEC_NO_FORMAT	/**<未知的格式。 													*/
} vm_exec_format_enum;

/**
 * 从应用程序文件名称中得到应用程序文件在ROM DATA里的程序映像的头指针。所以
 * 应用程序的文件名称必须是VM_EXEC_ROM的格式。
 * 
 * @param[in]		wfilename 应用程序文件名称，不应该包含有REDIRECT_APPNAME_SEPARATOR的，
 *				并且还应该只对于VM_EXEC_ROM格式的表示形式有效。否则返回NULL。
 * @return		如果成功则返回内存映像的头指针，否则返回NULL。
 */
VMUINT8* vm_get_execrom_ptr(VMWSTR wfilename);

/**
 * 根据ROM DATA里得到程序映像的的大小。在ROM中的格式如下。
 * @code
 *					|-------------------|
 * rom_ptr--> 		| app image size 	|
 *            		|-------------------|
 *			  		|  app    image  	|
 *            		|-------------------|
 * @endcode
 * @param[in]		rom_ptr 在ROM DATA里的头指针。
 * @return		如果成功则返回程序内存映像的大小，否则返回0。
 */
VMINT vm_get_execrom_size(VMUINT8* rom_ptr);

/**
 * 从完整的应用程序文件名称中得到所执行的应用程序名称的格式。
 * 
 * @param[in]		wfilename 应用程序文件名称，不应该包含有REDIRECT_APPNAME_SEPARATOR的，否则返回VM_EXEC_NO_FORMAT。
 * @return		如果成功则返回内存映像的头指针，否则返回VM_EXEC_NO_FORMAT。
 */
vm_exec_format_enum vm_parse_exec_format(VMWSTR wfilename);

/**
 * 从文件串中提取指定的序号的带路径的文件名称。
 * 比如"c:\\vre\game.vxp?c:\\vre\game2.vxp"，如果想提取?前一段名称则file_index参数应该为0，后一段则为1。如果没有'?'则
 * file_index必须为0。
 * 
 * @param[in]		wfilename 应用程序的名称的完整的表示。
 * @param[in]		file_index 序号。
 * @param[out]	wexec_filename 在得到指定序号的程序名称段后，希望函数写入的内存空间头指针，不应该为NULL。
 * @param[in]		wexec_filename_len wexec_filename所指向的空间大小，单位为字节，该长度必须大于MAX_APP_NAME_LEN。
 * @return		如果成功则返回TRUE，否则返回FALSE。
 */
VMINT vm_get_segment_from_filename(VMWSTR wfilename, VMINT file_index, VMWSTR wexec_filename, 
	VMINT wexec_filename_len);

/**
 * 指定的应用程序名称里是否包含REDIRECT_APPNAME_SEPARATOR。
 * 
 * @param[in]		完整的应用程序名称。
 * @return		TRUE 表示exec_filename里包含REDIRECT_APPNAME_SEPARATOR
 *				，FALSE 则表示不包含REDIRECT_APPNAME_SEPARATOR。
 */
VMINT vm_is_redirection_filename(VMWSTR exec_filename);

#define EXEC_SUCCESS								(0)
#define EXEC_INTERNAL_ERROR						(-1)
#define EXEC_ERROR_FORMAT							(-2)
#define EXEC_PARAM_ERROR							(-3)

#define EXEC_TAG_PLATFORM_PARAM_DISMATCH		(-4)
#define EXEC_APP_TIMESTAMP_ERROR					(-5)
#define EXEC_BAN_LIST_APP							(-6)
#define EXEC_INVALIDATE_APP						(-7)
#define EXEC_IMSI_DISMATCH							(-8)
#define EXEC_CERT_OVREDUE							(-9)

#define EXEC_NOT_EXEC_IN_STATUS					(-10)
#define EXEC_NO_MEM								(-11)

/**
 * 装入一个基于VRE的应用程序，并且把程序控制权转交给新启动的程序。
 *
 * @param filename		程序路径。
 *
 * @return				返回0表示执行成功，此时VRE被挂起，执行权交给
 *						应用程序。返回负数表示失败。
 */
VMINT vm_exec(VMWSTR filename);

/**
 * 启动已经装载到内存的程序，内存映像的内容必须和文件一致。
 *
 * @param ptr			程序内存映像的内存指针。
 *
 * @return				返回0表示启动成功。
 */
VMINT vm_exec_from_mem(VMUINT8 *ptr);

/**
 * 释放动态装入的VRE应用程序所占用的内存，这个方法只在VRE内部使用，
 * 应用程序不应调用此函数，否则会引起不可预测的结果。
 */ 
void vm_free_vreapp(void);

/**
 * 应用程序启动类型。
 */
typedef enum {
	ASYN_EXECUTE_SHORTCUT_APP_TYPE = 1,		/**<重定向启动应用程序，而不显示APP STORE。 */
	ASYN_EXECUTE_APP_STORE_TYPE				/**<从APP STORE里启动应用程序。 			*/			
} ASYN_EXECUTE_TYPE;

/**
 * 从vm_asyn_execute_context_t.pre_app_execute_ret可以得到
 * 启动应用时的状态。
 * @{
 */
/**
 *  启动成功，正常退出。
 */
#define APP_ASYN_EXECUTE_SUCCESS							(0)

/**
 * 应用程序可运行的平台与真实运行的平台不匹配。
 */
#define APP_ASYN_EXECUTE_PLATFORM_PARAM_DISMATCH		(-1)

/**
 * 应用程序运行的时间不在其有效期内。
 */
#define APP_ASYN_EXECUTE_TIMESTAMP_ERROR				(-2)

/**
 * 应用程序在黑名单里。
 */
#define APP_ASYN_EXECUTE_BANNED_APP						(-3)

/**
 * 应用程序非法，没有经授权。
 */
#define APP_ASYN_EXECUTE_INVALIDATE_APP					(-4)

/**
 * IMSI号不存在。
 */
#define APP_ASYN_EXECUTE_IMSI_DISMATCH					(-5)

/**
 * APP所使用的证书已经过期。
 */
#define APP_USE_CERT_OVERDUE								(-6)

/**
 * VRE系统内部错误。
 */
#define APP_ASYN_EXECUTE_INTERNAL_ERROR					(-7)
/** @} */

/**
 * 用户保存到上下文中数据的最大尺寸，单位为字节。
 */
#define ASYN_MAX_MEM_SIZE									(20)

/**
 * 启动应用程序时的上下文类型定义。
 */
typedef struct 
{
	VMWCHAR app_name[MAX_APP_NAME_LEN + 1];						/**<先前启动子程序的父应用程序的名称。					*/
	VMINT pre_app_execute_ret;										/**<先前一次启动子应用是否成功的返回值或错误码。	*/
	ASYN_EXECUTE_TYPE pre_app_execute_type;						/**<先前一次启动子应用的启动方式。							*/
	VMUCHAR pre_app_execute_user_data[ASYN_MAX_MEM_SIZE];		/**<在启动应用程序前保存的数据。 							*/
	VMUINT user_data_size;											/**<在启动应用程序前保存的数据的长度。 					*/
	VMFILE pre_app_file_handle;										/**<先前启动子程序的父应用程序的文件句柄。 			*/
} vm_asyn_execute_context_t;

/**
 * 把应用程序希望保存的数据保存到上下文中，
 * 实现从子程序里返回父程序后可以得到保存的
 * 数据。本函数应该在调用vm_execute前调用。
 * 
 * @param[in]		data 希望保存的到启动上下文的数据。
 * @param[in]		data_size 数据的大小，单位为字节。本参数
 *					应该小于或者等于ASYN_MAX_MEM_SIZE。
 * @return			是否成功保存数据。
 * @retval			TRUE 保存成功。
 * @retval			FALSE 保存失败。
 */
VMINT vm_save_execute_context(VMUCHAR* data, VMUINT data_size);

/**
 * 取得先前一次启动子程序的上下文。
 * 
 * @param[out]		context 上下文，如果取得上下问成功会将上下文的数据
 *					写入context所指向的结构中。
 * @return			是否取得应用程序上下文成功。
 * @retval			TRUE 读取上下文成功。
 * @retval			FALSE 读取上下文失败。
 */
VMINT vm_load_execute_context(vm_asyn_execute_context_t* context);

#ifdef __cplusplus
}
#endif

#endif