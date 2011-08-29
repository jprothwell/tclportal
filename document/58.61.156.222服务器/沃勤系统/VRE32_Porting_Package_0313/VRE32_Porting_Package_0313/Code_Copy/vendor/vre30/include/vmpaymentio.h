#ifndef __VM_PAYMENT_REGISTER_IO
#define __VM_PAYMENT_REGISTER_IO

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"
#include "vmbilling.h"

/**
 * 计费注册文件的开始部分。
 */
#define PAYMENT_REG_FILENAME_START_PARTY		"PRF_"

/**
 * 计费注册文件的后缀。
 */
#define PAYMENT_REG_FILENAME_SUFFIX				".REG"

/**
 * 计费注册文件的版本号。
 */
#define PAYMENT_REG_FILE_VERSION_NUM			(1)

/**
 * @name 计费注册文件里的免费模式。
 * @{
 */
/**
 * 按次免费。
 */
#define TRAIL_MODE_TIME						(1)
/**
 * 按天免费。
 */
#define TRAIL_MODE_DATE						(2)
/**
 * 无免费信息。
 */
#define TRAIL_MODE_NONE						(3)
/** @} */

/**
 * @name 计费模式。
 * @{
 */
/**
 * 按天计费模式。
 */
#define PAYMENT_MODE_DATE		PAYMENT_MODE_BY_DATE
/**
 * 按次计费模式。
 */
#define PAYMENT_MODE_TIME		PAYMENT_MODE_BY_TIME
/**
 * 买断模式。
 */
#define PAYMENT_MODE_FOREVER	PAYMENT_MODE_BY_FOREVER
/** @} */

/**
 * @name 计费注册文件操作的返回值。
 * @{
 */
#define PAY_REG_PROCESS_SUCCESS					(0)
#define PAY_REG_ERR_IO									(-1)
#define PAY_REG_ERR_PARAM								(-2)
#define PAY_REG_ERR_FILE_VERSION				(-3)
#define PAY_REG_ERR_INTERNAL_ERROR				(-4)
#define PAY_REG_ERR_FILE_INVALIDATE				(-5)
#define PAY_REG_ERR_FILE_NOT_EXIST				(-6)
#define PAY_REG_ERR_FILE_SYSTEM_NO_SPACE		(-7)
#define PAY_REG_ERR_NO_MEMORY					(-8)
#define PAY_REG_ERR_PAYMENT_RECORD_NOT_EXITS	(-9)
/** @} */

/**
 * @struct vm_payment_record_t
 * @brief 
 */
typedef struct 
{
	VMINT app_payment_id;		/**<应用程序内部ID。				*/
	VMUINT payment_mode;		/**<计费模式。						*/
	VMUINT payment_value;		/**<剩余的次数或截止日期。			*/
} vm_payment_record_t;

/**
 * 指定的计费文件的文件名是否存在。
 * 
 * @param[in]			filename 带路径的计费注册文件名称。
 * @param[out]			is_exists 指定的文件是否存在。
 * @return				成功与否。
 * @retval				PAY_REG_PROCESS_SUCCESS 成功。
 * @retval				PAY_REG_ERR_PARAM 错误的参数。
 */
VMINT vm_payment_reg_file_is_exist(VMWCHAR* filename, VMINT* is_exists);

/**
 * 指定名称计费注册文件是否合法。 
 *
 * @param[in]			filename 带路径的计费注册文件名称。
 * @param[out]			is_validate 是否合法。
 * @param[in]			random 用于验证计费文件是否合法的PADDING串。
 * @return				验证是否成功，否则为相应的错误码。
 * @retval				PAY_REG_PROCESS_SUCCESS 成功。
 * @retval				PAY_REG_ERR_PARAM 错误的参数。
 * @retval				PAY_REG_ERR_FILE_NOT_EXIST 指定名称的计费注册文件不存在。
 * @retval				PAY_REG_ERR_IO 文件IO错误。
 * @retval				PAY_REG_ERR_NO_MEMORY 内部不够，失败。
 */
VMINT vm_payment_reg_file_is_validate(VMWCHAR* filename, VMINT* is_validate, VMUINT8 random[8]);

/**
 * 保存计费记录，如果计费注册文件不存在则创建之。在保存指定的计费记录前先要验证旧
 * 的计费记录文件是否合法，如果不合法则返回PAY_REG_ERR_FILE_INVALIDATE。如果计费
 * 注册文件已经存在，则old_random参数不应该为NULL，否则会返回PAY_REG_ERR_PARAM。
 * 
 * @param[in]			filename 带路径的计费注册文件名称。
 * @param[in]			record 计费记录。
 * @param[in]			old_random 用于验证旧的计费注册文件是否合法的PADDING串。
 * @param[in]			new_random 生成新的认证信息的PADDING串。
 * @return				保存计费记录是否成功。
 * @retval				PAY_REG_PROCESS_SUCCESS 成功。
 * @retval				PAY_REG_ERR_PARAM 错误的参数。
 * @retval				PAY_REG_ERR_FILE_SYSTEM_NO_SPACE 文件系统没有空间。
 * @retval				PAY_REG_ERR_FILE_INVALIDATE 非法的计费注册文件。
 * @retval				PAY_REG_ERR_IO 文件IO错误。
 * @retval				PAY_REG_ERR_INTERNAL_ERROR 内部错误。
 * @retval				PAY_REG_ERR_NO_MEMORY 内存不够。
 */
VMINT vm_save_payment_information(VMWCHAR* filename, vm_payment_record_t* record, 
	VMUINT8 old_random[8], VMUINT8 new_random[8]);

/**
 * 根据指定的文件名和应用程序内部计费点编号，装载计费记录。
 * 
 * @param[in]			filename 带路径的计费注册文件名称。
 * @param[in]			app_payment_id 应用程序内部计费点ID。
 * @param[out]			record 计费记录。
 * @param[in]			random 用于验证旧的计费注册文件是否合法的PADDING串。
 * @return				装载指定计费记录
 * @retval				PAY_REG_PROCESS_SUCCESS 成功与否。
 * @retval				PAY_REG_ERR_PAYMENT_RECORD_NOT_EXITS 指定app_payment_id的计费记录
 *						不存在。
 * @retval				PAY_REG_ERR_PARAM 错误的参数。
 * @retval				PAY_REG_ERR_FILE_NOT_EXIST 文件不存在。
 * @retval				PAY_REG_ERR_FILE_INVALIDATE 非法的计费注册文件。
 * @retval				PAY_REG_ERR_IO 文件IO操作失败。
 * @retval				PAY_REG_ERR_NO_MEMORY 内存不够。
 * @retval				PAY_REG_ERR_PAYMENT_RECORD_NOT_EXITS 指定的应用程序内部计费点ID没有找
 *						到对应计费记录。
 */
VMINT vm_load_payment_information(VMWCHAR* filename, VMINT app_payment_id, 
	vm_payment_record_t* record, VMUINT8 random[8]);

/**
 * 装载使用免费信息。
 * 
 * @param[in]			filename 带路径的计费注册文件名称。
 * @param[out]			trail_mode 试用模式。
 *						TRAIL_MODE_NONE没有免费信息，TRAIL_MODE_TIME按次，TRAIL_MODE_DATE按天。
 * @param[out]			trail_value 试用的值。
 * @param[in]			random 用于验证旧的计费注册文件是否合法的PADDING串。
 * @return				装载免费信息成功与否。
 * @retval				PAY_REG_PROCESS_SUCCESS 操作成功。
 * @retval				PAY_REG_ERR_PARAM 错误的参数。
 * @retval				PAY_REG_ERR_FILE_NOT_EXIST 指定名称的计费用注册文件不存在。
 * @retval				PAY_REG_ERR_IO 文件IO操作失败。
 * @retval				PAY_REG_ERR_FILE_INVALIDATE	计费注册文件非法。
 * @retval				PAY_REG_ERR_NO_MEMORY 内存不足，无法执行。
 */
VMINT vm_load_trail_information(VMWCHAR* filename, VMUSHORT* trail_mode, 
	VMUINT* trail_value, VMUINT8 random[8]);

/**
 * 保存使用免费信息，如果计费注册文件不存在则创建之。在保存指定的免费信息前先要验证旧
 * 的计费记录文件是否合法，如果不合法则返回PAY_REG_ERR_FILE_INVALIDATE。如果计费
 * 注册文件已经存在，则old_des_key参数不应该为NULL，否则会返回PAY_REG_ERR_PARAM。 
 * 
 * @param[in]			filename 带路径的计费注册文件名称。
 * @param[in]			trail_mode 试用模式。
 *						TRAIL_MODE_NONE没有免费信息，TRAIL_MODE_TIME按次，TRAIL_MODE_DATE按天。
 * @param[in]			trail_value 与试用模式相关的试用的值。
 * @param[in]			old_random 用于验证旧的计费注册文件是否合法的PADDING串。
 * @param[in]			new_random 生成新的认证信息的PADDING串。
 * @return				保存免费信息成功与否的标志。
 * @retval				PAY_REG_PROCESS_SUCCESS 操作成功。
 * @retval				PAY_REG_ERR_PARAM 错误的参数。
 * @retval				PAY_REG_ERR_IO 文件IO操作失败。
 * @retval				PAY_REG_ERR_FILE_SYSTEM_NO_SPACE 没有足够的空间创建计费注册文件。
 * @retval				PAY_REG_ERR_FILE_INVALIDATE	计费注册文件非法。
 * @retval				PAY_REG_ERR_NO_MEMORY 没有足够内存。
 * @retval				PAY_REG_ERR_INTERNAL_ERROR 内部错误。
 */
VMINT vm_save_trail_information(VMWCHAR* filename, VMUSHORT trail_mode, VMUINT trail_value, 
	VMUINT8 old_random[8], VMUINT8 new_random[8]);

/**
 * 删除计费注册文件。
 * 
 * @param[in]			filename 带路径的计费注册文件名称。
 * @return				删除计费注册文件是否成功。
 * @retval				PAY_REG_PROCESS_SUCCESS 成功删除。
 * @retval				PAY_REG_ERR_PARAM 错误的参数。
 * @retval				PAY_REG_ERR_FILE_NOT_EXIST 指定名称的计费注册文件不存在。
 * @retval				PAY_REG_ERR_IO 文件IO操作失败。
 */
VMINT vm_delete_payment_reg_file(VMWCHAR* filename);

#ifdef __cplusplus
}
#endif


#endif