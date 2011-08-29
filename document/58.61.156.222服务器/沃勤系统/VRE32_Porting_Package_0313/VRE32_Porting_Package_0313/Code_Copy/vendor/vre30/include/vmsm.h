#ifndef VMSM_H_
#define VMSM_H_

#include "vmsys.h"
#include "vmdl.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************/

/**
 * VRE Billing Engine Shared Module in ROM
 */
//#define VRE_BESM_IN_ROM

/**
 * Search all SMs in removable & phone memory and compare their versions while loading.
 * The newest one will be loaded.
 */
#define VRE_SM_LOAD_VER_CMP

/**
 * System messages of SM.
 */

 /*
  * SM is being loaded.
  */
#define VM_SM_MSG_LOAD 		(1)

 /*
  * Invoker is querying for entries of SM API.
  */
#define VM_SM_MSG_QUERY		(5)

 /*
  * SM is being unloaded.
  */
#define VM_SM_MSG_UNLOAD 		(9)


/**
 * Definitions of SM's return value
 */

#define VM_SM_SUCCESS 						(0)	 	/* SM operation success */
#define VM_SM_FAILED 						(-1)		/* SM operation failed */
#define VM_SM_PARAM_ERROR 				(-2)		/* SM parameter error */
#define VM_SM_FILE_NOT_FOUND 				(-3)		/* SM file not found */
#define VM_SM_INVALID_INVOKER 				(-4)		/* SM invalid invoker */
#define VM_SM_CREATE_FAILED 				(-5)		/* SM failed to create pcb */
#define VM_SM_CREATE_COPY_FAILED 			(-6)		/* SM failed to create copy */
#define VM_SM_MSG_FAILED 					(-7) 	/* SM failed to handle messages */
#define VM_SM_NAME_MISMATCH 				(-8) 	/* SM name mis-match with name in file tag */

/************************************************************************/

/* SM flag to identify PCB's type */
enum {
	VRE_APP = 0,
	VRE_SM
};


typedef struct _vm_sm_info_t {
	VMCHAR version[6];
} vm_sm_info_t;

/**
 * 查询指定SM 名称的INFO 信息。
 * 
 * @code
 * vm_sm_info_t sm_info;
 * if (vm_sm_query_info("smbilling", sm_info) == SM_SUCCESS)
 * {
 * 	sm_info.version
 * }
 * @endcode
 *  
 * @param[in] 	sm_name	SM文件名；ASCII编码。
 * @param[out] 	sm_info		用于获取SM info信息的结构体。
 *							查询成功时结构体中各成员会被赋值；
 *							查询失败时结构体中各成员不会被赋值。
 * 
 * @return		查询结果:
 * @retval		SM_SUCCESS 	成功
 * @retval		SM_FAILED 		失败
**/
VMINT vm_sm_query_info(VMSTR sm_name, vm_sm_info_t * sm_info);



/************************************************************************/

extern VMUINT _get_vre_sym_entry(void);
#define VRE_ENTRY ((vm_get_sym_entry_t)_get_vre_sym_entry())

/* print log in vre.log */
typedef void(*_vm_log_vre_t)(char* fmt, ...);
#ifndef WIN32
#define vm_log_vre(...) ((_vm_log_vre_t)VRE_ENTRY("_vm_log_debug"))(__VA_ARGS__)
#endif

/* Definitions for explicit SM invoking */

typedef void (*void_void_t)(void);
typedef VMINT (*int_void_t)(void);
typedef VMINT (*int_int_t)(VMINT);

/* Macros for SM */

#define SM_PROCESS_BEGIN() {\
	vm_get_sym_entry_t vre_entry = VRE_ENTRY;	\
	if (((int_int_t)vre_entry("vm_sm_set_sb_by_ptr"))((VMINT)handle_smevt) == 0) {

#define SM_PROCESS_RETURN() ((void_void_t)vre_entry("vm_sm_reset_sb"))();

#define SM_PROCESS_END() SM_PROCESS_RETURN() } }

#define SM_CALLBACK_BEGIN() {\
	vm_get_sym_entry_t vre_entry = VRE_ENTRY;	\
	if (((int_void_t)vre_entry("vm_sm_set_sb_for_invoker"))() == 0) { 

#define SM_CALLBACK_END() SM_PROCESS_END()

#define SM_SAFE_CALLBACK(PTR) \
	SM_CALLBACK_BEGIN() \
	PTR; \
	SM_CALLBACK_END()

#define SM_SAFE_CALLBACK_RETURN(PTR, RET) \
	SM_CALLBACK_BEGIN() \
	RET = PTR; \
	SM_CALLBACK_END()

/* Macros for SM STUB */

#define SM_INVOKE_BEGIN(SM)  {\
	vm_get_sym_entry_t vre_entry = VRE_ENTRY;	\
	if (((int_int_t)VRE_ENTRY("vm_sm_set_sb_by_handle"))(SM) == 0) {

#define SM_INVOKE_END() SM_PROCESS_END()

#define SM_SAFE_INVOKE(SM, PTR) \
	SM_INVOKE_BEGIN(SM) \
	PTR; \
	SM_INVOKE_END() 

#define SM_SAFE_INVOKE_RETURN(SM, PTR, RET) \
	SM_INVOKE_BEGIN(SM) \
	RET = PTR; \
	SM_INVOKE_END() 


/************************************************************************/

/* API for SM */

/**
 * 注册SM 消息系统回调。
 * 
 * @param[in]			smHandler 处理SM系统消息的回调函数。
 */
void vm_reg_sm_callback(VMINT (*smHandler)(VMINT message, VMINT param));

/**
 * 获取当前正在运行的SM的完整文件路径(UCS2编码)。
 * 
 * @param[in]			filename 用以保存SM完整文件路径的字符串数组。
 * 					内存由调用者分配，VRE只负责向其中写入数据。
 *
 * @return			是否成功。
 * @retval			VM_SM_SUCCESS 成功。
 * @retval			VM_SM_FAILED 失败。
 */
VMINT vm_sm_get_filename(VMWSTR filename);

#if 0
/**
 * 从当前正在运行的SM文件中读入资源。
 * 系统根据资源的长度自动为其分配内存，然后从文件读入到内存之中，
 * 程序员在使用完资源后必须调用vm_free()将其释放掉。
 *
 * @param res_name		资源名称，系统在打包时把资源文件名作为资源名称保存到
 *						目标文件中，因此这个参数就是对应的资源文件名，路径部分
 *						不需要给出。比如图像资源文件是"c:\\projects\\game\\1.gif"，
 *						其资源名称就是"1.gif"。
 * @param res_size		被读入的资源长度，字节单位。
 *
 * @return				返回资源数据。
 */
VMUINT8* vm_sm_load_resource(char *res_name, VMINT *res_size);
#endif 

/************************************************************************/

/* API for SM invoker */

/**
 * 装载SM.
 * 
 * @param[in]			sm_name SM 名称。
 * 					sm_name 可以是不带文件路径，不带扩展名的文件名；
 * 					如"xxx" in "c:\vre\xxx.vsm". 此时系统自动在T卡与手机系统盘
 * 					中的"vre"目录中寻找名称匹配的.vsm文件并装载；
 * 					T卡和系统盘中同时存在时，优先加载T卡中的文件。
 * 					sm_name 也可以是.vsm文件的完整路径。
 *
 * @code
 * VMINT sm_hdl = vm_sm_load("sm_charge");
 * if (sm_hdl > 0)
 * {
 * 	...
 * }
 * @endcode
 *
 * @return			成功时返回SM句柄；
 * 					失败时返回如下错误码:
 * @retval			VM_SM_FAILED 失败。
 * @retval			VM_SM_PARAM_ERROR 参数错误。
 * @retval			VM_SM_FILE_NOT_FOUND 找不到文件。
 * @retval			VM_SM_INVALID_INVOKER 无效的调用者。
 * @retval			VM_SM_CREATE_FAILED 创建SM失败。
 * @retval			VM_SM_CREATE_COPY_FAILED 创建SM copy失败。
 * @retval			VM_SM_MSG_FAILED SM响应消息失败。
 * @retval			VM_SM_NAME_MISMATCH SM名称与文件TAG中的名称不匹配。
 */
VMINT vm_sm_load(VMSTR sm_name);

/**
 * 获取SM中指定API ID的函数入口地址。
 * 
 * @param[in]			sm_hdl SM句柄。
 * 					由vm_sm_load创建。
 * @param[in]			api_id SM中对调用者开放的API ID。
 * 					由SM开发者定义，提供在SM的头文件中。
 *
 * @code
 * VMINT sm_hdl = vm_sm_load("sm_charge");
 * func_t func_ptr = NULL;
 * if (sm_hdl > 0)
 * {
 * 	func_ptr = vm_sm_get_func_entry(sm_hdl, id_func);
 * 	if (func_ptr)
 * 	{
 * 		func_ptr(x, y, z);
 * 	}
 * }
 * vm_sm_unload(sm_hdl);
 * @endcode
 *
 * @return			是否成功。
 * @retval			VM_SM_SUCCESS 成功。
 * @retval			VM_SM_FAILED 失败。
 */
VMINT vm_sm_get_func_entry(VMINT sm_hdl, VMINT api_id);

/**
 * 卸载SM.
 * 
 * @param[in]			sm_hdl SM句柄。
 * 					由vm_sm_load创建。
 *
 * @code
 * VMINT sm_hdl = vm_sm_load("sm_charge");
 * if (sm_hdl > 0)
 * {
 * 	...
 * }
 * vm_sm_unload(sm_hdl);
 * @endcode
 *
 * @return			是否成功。
 * @retval			VM_SM_SUCCESS 成功。
 * @retval			VM_SM_FAILED 失败。
 */
VMINT vm_sm_unload(VMINT sm_hdl);


/************************************************************************/


#ifdef __cplusplus
}
#endif 
#endif

