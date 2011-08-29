/**
 * vmnvramadapter.h是对于vmnvram.h的适配，提供了APP STRORE对于NVRAM的操作接口函数声明。
 * APP STORE里应该只调用vmnvramadapter.h里声明的函数来对NVRAM进行操作而不应该直接调用
 * vmnvram.h里的函数。
 * vmnvramadapter.h应该只在APP STORE里和计费引擎里才被使用。
 * 
 * @vresion 1.3.0
 * @author	jie.chen@vogins.com
 */
#ifndef __VM_NVRAM_ADAPTER
#define __VM_NVRAM_ADAPTER


#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"
#include "vmnvram.h"
#include "vmrsa.h"

/**
 * @name 
 * @{
 */
/**
 * 操作成功。
 */
#define VM_ADAPTER_NVRAM_SUCCESS			(0)

/**
 * 记录没有被发现。
 */
#define VM_ADAPTER_NVRAM_NOT_FOUND_RECORD	(1)

/**
 * 内存不够。
 */
#define VM_ADAPTER_NVRAM_ERROR_MEM			(-1)

/**
 * 参数错误。
 */
#define VM_ADAPTER_NVRAM_ERROR_PARAM		(-2)

/**
 * 存取NVRAM内部错误。
 */
#define VM_ADAPTER_NVRAM_INTERNAL_ERROR		(-3)

/**
 * 操作了NVRAM的存储容量。
 */
#define VM_ADAPTER_NVRAM_OVERFLOW_STORAGE	(-4)
/** @} */

/**
 * 应用程序收费记录。
 */
typedef vm_app_info_t		vm_app_charge_record;

/**
 * 收费通道记录。
 */
typedef struct {
	VMUSHORT    org_id;				/*组号。										*/	
	VMUSHORT	sp_id;				/*移动或联通的标志,	1是移动，2是联通，3是电信。	*/
	VMCHAR		sms_id[20];			/*短信接入号。									*/
	VMCHAR		sms_content[30];	/*短信内容。												*/
	VMUINT		fee;				/*通道的单价，单位为分。						*/
} vm_payment_channel_record;

/**
 * 根据产品编号得到应用程序收费记录。
 * 
 * @param[in]			pid 产品编号。
 * @param[out]			record 指向收费记录结构的指针。
 * @return				是否操作成功的标志。
 * @retval				VM_ADAPTER_NVRAM_SUCCESS 根据产品编号成功找到对应的应用程序计费状态。
 * @retval				VM_ADAPTER_NVRAM_ERROR_PARAM record指向NULL的时候返回本错误码。
 * @retval				VM_ADAPTER_NVRAM_NOT_FOUND_RECORD 根据产品编号没有找到对应的应用程序收费记录。
 * @retval				VM_ADAPTER_NVRAM_INTERNAL_ERROR 内部错误，装载不成功。
 * @retval				VM_ADAPTER_NVRAM_ERROR_MEM 内存不足，装载不成功。
 */
VMINT vm_load_app_charge_record(VMINT pid, vm_app_charge_record* record);

/**
 * 存储应用收费记录，如果NVRAM里的数据已经满了，则覆盖掉当前已经不存在并且
 * 最早被存储的应用程序对应的收费记录。如果存储的收费记录已经存在则更新之。
 * 
 * @param[in]			record 收费记录。
 * @param[in]			exist_app_pid_lst 当前存在的产品编号的列别。
 * @param[in]			lst_num 产品编号的个数。
 * @return				操作是否成功的标志。
 * @retval				VM_ADAPTER_NVRAM_SUCCESS 存储成功。
 * @retval				VM_ADAPTER_NVRAM_ERROR_PARAM 参数错误，如果record参数为NULL，
 *						或lst_num大于0并且exist_app_pid_lst参数NULL，那么本错误码将会被返回。
 * @retval				VM_ADAPTER_NVRAM_INTERNAL_ERROR 内部错误，存储不成功。
 * @retval				VM_ADAPTER_NVRAM_ERROR_MEM 内部不够，储存不成功。
*/
VMINT vm_save_app_charge_record(vm_app_charge_record* record, 
	VMINT* exist_app_pid_lst, VMUINT lst_num);
	
/**
 * 查询在save_app_charge_record是否会覆盖掉较早的计费状态记录，有则返回
 * 将要覆盖记录所对应的APP_ID。
 * 
 * @param[in]			exec_app_id 需要运行的应用程序ID。
 * @param[out]			replace_app_id 返回0则不需要覆盖NVRAM里已经有的计费
 *						状态记录。否则返回将可能被覆盖掉计费状态记录的对应的应用程序
 *						ID。
 * @return				是否成功的标志。
 * @retval				VM_ADAPTER_NVRAM_SUCCESS 成功。
 * @retval				VM_ADAPTER_NVRAM_ERROR_PARAM 错误的参数。
 * @retval				VM_ADAPTER_NVRAM_ERROR_MEM 内存不够，操作不成功。
 * @retval				VM_ADAPTER_NVRAM_INTERNAL_ERROR 内部错误，操作不成功。
 */
VMINT vm_app_charge_record_is_replace(VMINT exec_app_id, VMINT* replace_app_id);

/**
 * 存储收费通道。
 * 
 * @param[in]			record_lst 收费渠道记录列表，本参数应该指向record_num个
 *						vm_payment_channel_record结构的数据。
 * @param[in]			record_num record_lst指向的vm_payment_channel_record结构的个数。
 * @return				存储是否成功的标志。
 * @retval				VM_ADAPTER_NVRAM_SUCCESS 储存成功。
 * @retval				VM_ADAPTER_NVRAM_OVERFLOW_STORAGE 超过了存储容量。
 * @retval				VM_ADAPTER_NVRAM_ERROR_PARAM 错误的参数，如果record_lst指向NULL，那么本错误将会被返回。
 * @retval				VM_ADAPTER_NVRAM_INTERNAL_ERROR 内部错误，存储失败。
 * @retval				VM_ADAPTER_NVRAM_ERROR_MEM 内存不够，存储失败。
 */
VMINT vm_save_charge_channel_records(vm_payment_channel_record* record_lst, 
	VMUINT record_num);

/**
 * 装载指定组号的收费通道，如果装载成功在不使用时，必须调用vm_release_charge_channel_records
 * 函数将其释放。
 * 
 * @param[in]			group_id 指定得计费通道组号。
 * @param[out]			record_lst 指向vm_payment_channel_record的头指针的指针，在不用后
 *						必须调用vm_release_charge_channel_records释放内存。
 * @param[out]			record_num 个数，如果找不到指定组的计费通道则record_num写入0。
 * @return				是否成功装载的标志。
 * @retval				VM_ADAPTER_NVRAM_SUCCESS 装载成功。
 * @retval				VM_ADAPTER_NVRAM_INTERNAL_ERROR 内部错误，装载失败。
 * @retval				VM_ADAPTER_NVRAM_ERROR_MEM 内存不够，装载失败。
 * @note				在不使用record_lst所指向的对象，则需要调用
 *						vm_release_charge_channel_records函数释放之。
 */
VMINT vm_load_group_charge_channel_records(VMUSHORT group_id, 
	vm_payment_channel_record** record_lst, VMUINT* record_num);

/**
 * 释放收费通道记录，如果记录是通过vm_load_charge_channel_records函数获取，
 * 则需要调用本函数释放。
 * 
 * @param[in]			record_lst 指向vm_payment_channel_record结构的头指针。
 * @return				是否成功的标志。
 * @retval				VM_ADAPTER_NVRAM_SUCCESS 成功释放装载的收费通道记录。
 * @retval				VM_ADAPTER_NVRAM_ERROR_PARAM 参数错误。
 */
VMINT vm_release_charge_channel_records(vm_payment_channel_record* record_lst);

/**
 * 存储机型编号。
 * 
 * @param[in]				mid 机型编号。
 * @return					是否成功存储机型编号。
 * @retval					VM_ADAPTER_NVRAM_SUCCESS 存储成功。
 * @retval					VM_ADAPTER_NVRAM_INTERNAL_ERROR NVRAM内部错误，存储失败。
 * @retval					VM_ADAPTER_NVRAM_ERROR_MEM 内存不够，储存失败。
 */
VMINT vm_save_mobile_phone_id_record(VMINT mid);

/**
 * 存储用户编号。
 * 
 * @param[in]				uid 用户编号。
 * @return					存储用户编号。
 * @retval					VM_ADAPTER_NVRAM_SUCCESS 存储成功。
 * @retval					VM_ADAPTER_NVRAM_INTERNAL_ERROR NVRAM内部错误，存储失败。
 * @retval					VM_ADAPTER_NVRAM_ERROR_MEM 内存不够，储存失败。		
 */
VMINT vm_save_user_id_record(VMINT uid);

/**
 * 装载机型编号，如果从来没有存储机型编号，则调用本函数将会
 * 得到的机型编号为0。
 * 
 * @param[in]				mid 机型编号的指针。
 * @return					装载机型编号是否成功。
 * @retval					VM_ADAPTER_NVRAM_SUCCESS 从NVRAM装载成功。
 * @retval					VM_ADAPTER_NVRAM_INTERNAL_ERROR NVRAM内部错误，装载失败。
 * @retval					VM_ADAPTER_NVRAM_ERROR_PARAM 参数错误，装载失败。
 * @retval					VM_ADAPTER_NVRAM_ERROR_MEM 内存不够，装载失败。									
 */
VMINT vm_load_mobile_phone_id_record(VMINT* mid);

/**
 * 装载用户编号，如果从来没有存储用户编号，则调用本函数将会
 * 得到的用户编号为0。
 * 
 * @param[in]				uid 用户编号的指针。
 * @return					装载用户编号是否成功。
 * @retval					VM_ADAPTER_NVRAM_SUCCESS 从NVRAM装载成功。
 * @retval					VM_ADAPTER_NVRAM_INTERNAL_ERROR NVRAM内部错误，装载失败。
 * @retval					VM_ADAPTER_NVRAM_ERROR_PARAM 参数错误，装载失败。
 * @retval					VM_ADAPTER_NVRAM_ERROR_MEM 内存不够，装载失败。										
 */
VMINT vm_load_user_id_record(VMINT* uid);

typedef enum 
{
	VM_NVRAM_SYSTEM_TIMESTAMP = 0,
	VM_NVRAM_BAN_APP_LST_TIMESTAMP,
	VM_NVRAM_SYS_PERMISSION_TIMESTAMP,
	VM_NVRAM_PUBLIC_CERT_LST_TIMESTAMP,
	VM_NVRAM_CHARGE_CHANNEL_LST_TIMESTAMP,
	VM_NVRAM_MAX_TIMESTAMP
} TIMESTAMP_TYPE;

/**
 * 合并更新时间戳。以下例子是只存取黑名单应用程序表的更新时间戳的示例代码段。
 * 
 * @code
 * vm_time_t timestamps[5];
 * vm_time_t ban_app_lst_time = {2000, 1, 1, 0, 0, 0};
 * 
 * if (vm_load_timestamps_record(timestamps) == VM_ADAPTER_NVRAM_SUCCESS)
 * {
 *     if (vm_merge_timestamp(timestamps, &ban_app_lst_time, VM_NVRAM_BAN_APP_LST_TIMESTAMP))
 *	       vm_save_timestamps_record(timestamps);
 * }
 * @endcode
 * @param[out]				timestamps 合并到的更新时间戳数组。
 * @param[in]				curr_timestamp 需要被合并的指定类型的时间戳。
 * @param[in]				time_type 时间戳的类型，不应该是VM_NVRAM_MAX_TIMESTAMP。
 * @return					合并是否成功。
 * @retval					TRUE 表示成功。
 * @retval					FALSE 表示失败。
 */
VMINT vm_merge_timestamp(vm_time_t timestamps[VM_NVRAM_MAX_TIMESTAMP], 
	vm_time_t* curr_timestamp, TIMESTAMP_TYPE time_type);

/**
 * 提取指定类型的更新时间戳，以下是取得系统权限的更新时间戳和证书库的更新时间戳。
 * 
 * @code
 * vm_time_t timestamps[5];
 * vm_time_t curr_timestamp;
 *
 * if (vm_load_timestamps_record(timestamps) == VM_ADAPTER_NVRAM_SUCCESS)
 * {
 *     if (vm_merge_timestamp(timestamps, &curr_timestamp, VM_NVRAM_SYS_PERMISSION_TIMESTAMP))
 *     {
 *         // 成功得到系统权限的更新时间戳。
 *     }
 *	   if (vm_merge_timestamp(timestamps, &curr_timestamp, VM_NVRAM_PUBLIC_CERT_LST_TIMESTAMP))
 *     {
 *         // 成功得到公钥库的更新时间戳。
 *     }
 * } 
 * @endcode
 * @param[in]				timestamps 取得更新时间戳的数组。
 * @param[out]				curr_timestamp 得到指定类型时间戳。
 * @param[in]				time_type 时间戳的类型。
 * @return					提成是否成功。
 * @retval					TRUE 成功。
 * @retval					FALSE 失败。
 */
VMINT vm_split_timestamp(vm_time_t timestamps[VM_NVRAM_MAX_TIMESTAMP], 
	vm_time_t* curr_timestamp, TIMESTAMP_TYPE time_type);

/**
 * 存储所有的更新时间戳。
 * 
 * 
 * @param[in]				timestamps 需要存储的更新时间戳数组。
 * @return					存储是否成功。
 * @retval					VM_ADAPTER_NVRAM_SUCCESS 成功存储。
 * @retval					VM_ADAPTER_NVRAM_ERROR_PARAM 错误的参数，存储失败。
 * @retval					VM_ADAPTER_NVRAM_INTERNAL_ERROR NVRAM内部操作，存储失败。
 * @retval					VM_ADAPTER_NVRAM_ERROR_MEM 内存不够，导致储存失败。
 */
VMINT vm_save_timestamps_record(vm_time_t timestamps[VM_NVRAM_MAX_TIMESTAMP]);

/**
 * 装载所有的更新时间戳。
 * 
 * 
 * @param[out]				timestamps 装载的更新时间戳数组。
 * @return					装载是否成功。
 * @retval					VM_ADAPTER_NVRAM_SUCCESS 装载成功。
 * @retval					VM_ADAPTER_NVRAM_ERROR_PARAM 错误的参数，装载失败。
 * @retval					VM_ADAPTER_NVRAM_INTERNAL_ERROR NVRAM内部操作，装载失败。
 * @retval					VM_ADAPTER_NVRAM_ERROR_MEM 内存不够，导致装载失败。
 */
VMINT vm_load_timestamps_record(vm_time_t timestamps[VM_NVRAM_MAX_TIMESTAMP]);

/**
 * 公钥的存储记录。
 */
typedef struct {
	VMKey pKey;
	vm_time_t timestamp;
} vm_cert_record;

/**
* 权限记录。
 */
typedef vm_permission_t sys_permission_record;


/**
 * 存储禁用应用程序ID记录列表。
 * 
 * @param[in]				ban_app_lst 禁用的APP ID列表。
 * @param[in]				lst_num 列表所包含的禁用的APP ID的个数。
 * @return					存储是否成功的标志。
 * @retval					VM_ADAPTER_NVRAM_SUCCESS 存储成功。
 * @retval					VM_ADAPTER_NVRAM_ERROR_PARAM 参数错误，导致存储失败。
 * @retval					VM_ADAPTER_NVRAM_INTERNAL_ERROR NVRAM内部错误导致存储失败。
 * @retval					VM_ADAPTER_NVRAM_OVERFLOW_STORAGE 需要存储的内容超过了存储容量，存储失败。
 * @retval					VM_ADAPTER_NVRAM_ERROR_MEM 内存不够，存储失败。
 */
VMINT vm_save_ban_app_lst_records(VMUINT* ban_app_lst, VMUINT lst_num);

/**
 * 存储系统权限记录列表。
 * 
 * @param[in]				permission_lst 权限列表。
 * @param[in]				lst_num 列表所包含权限的个数。
 * @return					存储是否成功的标志。
 * @retval					VM_ADAPTER_NVRAM_SUCCESS 存储成功。
 * @retval					VM_ADAPTER_NVRAM_ERROR_PARAM 参数错误，导致存储失败。
 * @retval					VM_ADAPTER_NVRAM_INTERNAL_ERROR NVRAM内部错误导致存储失败。
 * @retval					VM_ADAPTER_NVRAM_OVERFLOW_STORAGE 需要存储的内容超过了存储容量，存储失败。
 * @retval					VM_ADAPTER_NVRAM_ERROR_MEM 内存不够，存储失败。
*/
VMINT vm_save_sys_permission_lst_records(sys_permission_record* permission_lst, 
	VMUINT lst_num);

/**
 * 存储证书记录列表。
 * 
 * @param[in]				cert_lst 公钥记录列表。
 * @param[in]				lst_num 列表所包含的公钥记录的个数。
 * @return					存储是否成功的标志。
 * @retval					VM_ADAPTER_NVRAM_SUCCESS 存储成功。
 * @retval					VM_ADAPTER_NVRAM_ERROR_PARAM 参数错误，导致存储失败。
 * @retval					VM_ADAPTER_NVRAM_INTERNAL_ERROR NVRAM内部错误导致存储失败。
 * @retval					VM_ADAPTER_NVRAM_OVERFLOW_STORAGE 需要存储的内容超过了存储容量，存储失败。
 * @retval					VM_ADAPTER_NVRAM_ERROR_MEM 内存不够，存储失败。
 */
VMINT vm_save_cert_lst_records(vm_cert_record* cert_lst, VMUINT lst_num);

/************************************************************************************/

#define			VM_PRECISE_COMMAND_SMS_TYPE			(1)
#define			VM_FUZZY_COMMAND_SMS_TYPE			(2)

#define			VM_NEED_SECOND_CONFIRM_FLAG			(1)
#define			VM_NO_SECOND_CONFIRM_FLAG			(2)

/* 112 byte * 32 = 3584 */
typedef struct 
{
	VMUINT fee;						/* 通道价格。					*/
	VMUINT16 sms_type;				/* 短信类型，1为精确，2为模糊。 */
	VMWCHAR service_name[11];		/* 业务名称。					*/
	VMWCHAR sp_name[9];				/* SP名称。						*/
	VMCHAR sms_access[21];			/* 短信接入号					*/
	VMCHAR sms_command[31];			/* 短信指令						*/
	VMCHAR customer_number[16];		/* 客服号码						*/
	VMUINT need_send_num;			/* 短信发送条数					*/
	VMUINT fee_actual;			/* 点数对应的实际价格*/
	VMUINT left_use_num;		/* 该通道剩余使用次数*/
	VMUINT second_flag;			/* 该通道是否为二次确认通道，1为需要二次确认，2 为不需要二次确认*/
} vm_payment_channel_ext_record;

/**
 * 按指定通道与指定运营商编号，取得短信计费通道，通道按价格从大到小排列，价格相同的将只保留一条
 * 短信通道，淘汰价格相同通道的原则为:模糊指令优于精确指令,精确指令之间为第一条。
 * 
 * @param[in]		group_id
 * @param[in]		operator_code
 * @param[out]		records
 * @param[out]		records_num
 */
VMINT vm_load_payment_channel_ext_records(VMUINT16 group_id, VMCHAR* operator_code, 
	vm_payment_channel_ext_record** records, VMUINT16* records_num);

/**
 * vm_load_payment_channel_ext_records函数取得的计费通道。
 * 
 * @param[in]		records
 */
void vm_unload_payment_channel_ext_records(vm_payment_channel_ext_record* records);

/**
 * 取得用户余额与是否要在发送短信前提示的标志。
 * 
 * @param[out]		user_balance
 * @param[out]		sms_notification_flag
 */
VMINT vm_get_user_balance_and_sms_notify_flag(VMUINT* user_balance, VMUINT* sms_notification_flag, VMUINT* reserved);

/**
 * 设置用户余额。
 * 
 * @param[in]		user_balance 用户余额。
 */
VMINT vm_set_user_balance(VMUINT user_balance);

/**
 * 保存计费凭证。
 * 
 * @param[in]		detail_record 计费凭证。
 */
VMINT vm_save_charge_detail_record(vm_charge_detail_record_t* detail_record);

/**
 * 保存短信发送凭证。
 * 
 * @param[in]		sms_access 短信接入号。
 * @param[in]		sms_command 短信指令。
 */
VMINT vm_save_sms_detail_record(VMCHAR* sms_access, VMCHAR* sms_command);


typedef enum
{
VM_VRE_VERSION30 = 0,
VM_VRE_VERSION31,
VM_VRE_VERSION32

}vre_vresion_enum;


/**
VMUINT send_second_flag; /*对于全关闭，当应用正在计费时，二次确认短信已经发出去的标志，
							应用计费结果出来后，根据此标志表明是否要保存计费凭证 ；
				对于半开和全开send_second_flag表示匹配到了短信，已将要发送的内容号码记录下来了。
	
*/
typedef struct vm_second_sms_t
{
	VMWCHAR service_name[11];		
	VMWCHAR sp_name[9];
	VMUINT channel_fee;	
	VMUINT fee;	
	VMUINT send_index;/*当发送二次确认短信，设置此标志，等待短信发送结果，根据此标志，判断返回的是哪条短信的callback，值为quick_charge_sms_ptr->total_send_sms++*/
	VMUINT send_second_flag; /*对于全关闭，当应用正在计费时，二次确认短信已经发出去的标志，应用计费结果出来后，根据此标志表明是否要保存计费凭证 */
	VMUINT save_sms_index; /*创建此结构时分配的index, 只为total_save_sms++*/
	VMWCHAR sms_content[16];
	VMWCHAR sms_number[21];
	struct vm_second_sms_t * next;	
}vm_second_sms_t;

typedef struct vm_quick_charge_list_t
{
	VMINT app_id;								
	VMINT local_payment_id;	
	VMINT app_state;
	VMUINT16 source;	
	VMCHAR ext_content[12]; 
	VMUINT open_state;
	VMUINT semi_close_send;
	vm_second_sms_t *  second_sms_ptr;
	struct vm_quick_charge_list_t * next;
}vm_quick_charge_list_t;

typedef struct 
{
	vm_quick_charge_list_t * quick_charge_list;
	VMUINT total_send_sms;
	VMUINT total_save_sms;
}vm_quick_charge_sms_t;


/**
 * 二次确认新加结构
 */
 typedef enum
{
	VM_APP_BILLING_FAIL = -1,
	VM_APP_BILLING,
	VM_APP_BILLING_SUCCESS
}vm_app_state_t;



VMINT vm_set_quick_charge_state(VMINT app_state);

VMINT vm_save_second_send_sms(vm_payment_channel_ext_record * channel_ext_lst);

void vm_save_charge_record_and_clear_quick(void);

void vm_wmemcpy(VMWSTR dst, VMWSTR src, VMINT count);

VMINT vm_find_and_replace_string(VMWSTR  buffer, VMINT  buffer_size, VMWSTR dst_string, VMWSTR src_string);

VMINT vm_find_and_insert_string(VMWSTR  buffer, VMINT  buffer_size, VMWSTR insert_string, VMWSTR find_string);

VMINT vm_find_the_send_sms_index_open(void);

VMINT vm_save_pay_usage(vm_second_sms_t * second_sms_ptr);


VMINT vm_save_charge_detail_record_ext(vm_charge_detail_record_ext_t* detail_record_ext);


/**
 * 检查短信内容是否包含指定服务提供商名字，服务名称和计费值, 匹配则将短信内容的随机数字串写到random, 没有随机数字串则将'Y'写到random
 *
 * @param sms			短信内容
 * @param sp_name		服务提供商名字
 * @param service_name	服务名称
 * @param fee			计费值，以分为单位
 * @param random		保存随机数字串或'Y'的指针, 随机数字串为"回复"到"确认点播"间的字串
 * @param size			保存随机数字串空间最大值，包括末尾的0 
 * 
 * @return				成功返回TRUE, 否则返回FALSE
 */
VMINT sms_pattern_check(VMWSTR sms, VMWSTR sp_name, VMWSTR service_name, VMUINT fee, VMWSTR random, VMUINT size);

#define PAYMENT_LOG
 
#ifdef __cplusplus
}
#endif

#endif

