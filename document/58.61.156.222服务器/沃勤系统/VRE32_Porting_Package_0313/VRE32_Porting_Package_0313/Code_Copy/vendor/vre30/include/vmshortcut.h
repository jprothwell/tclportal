#ifndef _VM_SHORTCUT_
#define	_VM_SHORTCUT_

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"

/**
 *	通过传入带全路径的文件名，获取VXP文件中的icon信息。
 *	函数需要调用两次。
 *	第一次调用，设置参数icon_ptr为NULL，将返回icon图像数据的长度。
 *	第二次调用，通过参数icon_ptr返回icon的图像数据
 *
 *	@param vxp_filename VXP文件的文件名，带全路径
 *	@param icon_ptr			存放图标数据空间的首地址指针
 *	@param size					存放图标数据空间的大小
 *
 *	@return  图标数据需要存储空间的大小。如果第一次调用返回为0，代表获取图标信息失败。
 */
VMINT vm_get_appicon( VMWSTR vxp_filename, VMSTR icon_ptr, VMINT size);

/**
 *	通过传入带全路径的文件名，获取VXP文件中的appid信息。
 *
 *	@param vxp_filename VXP文件的文件名，带全路径
 *
 *	@return  返回VXP文件中的appid。如果等于0，代表获取失败。
 */
VMINT vm_get_appid(VMWSTR vxp_filename);


/**
 *	验证应用程序是否有效
 *
 *	@param vxp_filename VXP文件的文件名，带全路径
 *
 *	@return  应用程序验证通过,返回0, 否则返回负数的错误码。参考vmcerter.h
 */
VMINT vm_app_is_valid(VMWSTR vxp_filename);


#ifdef __cplusplus
}
#endif

#endif