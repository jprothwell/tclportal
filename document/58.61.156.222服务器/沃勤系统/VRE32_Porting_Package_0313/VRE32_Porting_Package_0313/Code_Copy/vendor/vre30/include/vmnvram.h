#ifndef VMNVRAM_H_
#define VMNVRAM_H_

#include "vmsys.h"
#include "vmglobalver.h"
#ifdef __cplusplus
extern "C" {
#endif

#define VM_NVRAM_RW_ERROR -1
/**
 *	公钥(存储)内容长度
 */
#define PK_CONTENT_LEN		(200)
/**
 *	存储到一条NVRAM记录中的公钥个数
 */
#define ROOT_PK_LIST_SIZE   (8)
/**
 *	存储到一条NVRAM记录中的应用黑名单个数
 */
#define BAN_LIST_SIZE		(256)

/**
 *     公钥占用空间大小
 */
#define NVRAM_PKEY_LIST_NUM								(3648)

/**
 * NVRAM里存储的运营商标识。
 * NVRAM_OPERATOR_CMCC 为中国移动。
 * NVRAM_OPERATOR_UNI 为中国联通。
 */
#define NVRAM_OPERATOR_CMCC				(1)
#define NVRAM_OPERATOR_UNI				(2)

/**
 *	存储到NVRAM记录中一个公钥的结构
 */
typedef struct 
{
	VMINT pkey_index;						/*公钥索引号*/
	VMINT8 pkey_content[PK_CONTENT_LEN];	/*公钥内容*/
	vm_time_t pkey_time_stamp;
} vm_pkey_t;

/**
 *	存储到NVRAM一条记录，里面存储八个公钥
 *	需要两条NVRAM记录。
 */
typedef struct 
{
	vm_pkey_t pkey_item[ROOT_PK_LIST_SIZE];
} vm_nvram_root_pkey_list_t;

/**
 *	存储到NVRAM一条记录，里面存储应用程序黑名单
 *	需要一条NVRAM记录。
 */
typedef struct 
{
	VMUINT app_ban_item[BAN_LIST_SIZE];
	vm_time_t app_ban_time_stamp;
} vm_nvram_app_ban_list_t;

/**
  *	从NVRAM中读取指定记录号的公钥集,一个公钥集最多包含8个公钥.
  *
  *	@param list_index	记录号,现在只支持两条记录(0或者1), 其他数值将返回错
  * @param pkey_list   公钥集的指针,如果读取成功,通过这个指针返回公钥集
  *
  *	@return TRUE=读取成功,FALSE=读取失败
  */
VMINT vm_nvram_get_pkey_list(VMINT list_index, vm_nvram_root_pkey_list_t * pkey_list);

/**
  *	向NVRAM中写入公钥集到指定记录号,一个公钥集最多包含8个公钥.
  *
  *	@param list_index	记录号,现在只支持两条记录(0或者1), 其他数值将返回错
  * @param pkey_list   公钥集的指针,调用此函数前必须将指针指向公钥集数据
  *
  *	@return TRUE=写入成功,FALSE=写入失败
  */
VMINT vm_nvram_set_pkey_list(VMINT list_index, vm_nvram_root_pkey_list_t * pkey_list);

/**
  *	从NVRAM中读取应用程序黑名单集
  *
  * @param ban_list_ptr   应用程序黑名单集的指针,如果读取成功,通过这个指针返回黑名单集
  * @return TRUE=读取成功,FALSE=读取失败
  */
VMINT vm_nvram_get_ban_list(vm_nvram_app_ban_list_t * ban_list_ptr);

/**
  *	向NVRAM中写入应用程序黑名单集.
  *
  *   @param ban_list_ptr   应用程序黑名单集的指针,调用此函数前必须将指针指向黑名单集数据
  *
  *	@return TRUE=写入成功,FALSE=写入失败
  */
VMINT vm_nvram_set_ban_list(vm_nvram_app_ban_list_t * ban_list_ptr);

/**
  *	从NVRAM调入应用程序黑名单集,黑名单存储在全局变量app_ban_list 中.
  *	建议在系统启动时或者黑名单修改后调用该函数
  *
  *	@return TRUE=读取成功,FALSE=读取失败
  */
VMINT vm_load_app_ban_list(void);

/**
 *	释放全局变量app_ban_list(应用程序黑名单集)
 */
void vm_unload_app_ban_list(void);


VMINT vm_app_in_ban_list(VMUINT app_id);

#define SYM_PERMISSION_LEN 200

typedef enum 
{
	VM_ENTRY_REFUSE = 0,  /*接口拒绝访问*/
	VM_ENTRY_ACCEPT = 1   /*接口允许访问*/
} vm_permission_e;

typedef struct 
{
	VMINT operate_index;  /*入口类序号*/
	vm_permission_e permission;   /*入口类许可*/
} vm_permission_t;

/**
  *	存储到NVRAM一条记录，里面存储沙箱数据
  *	需要一条NVRAM记录
  *   nvram中接口许可列表数据结构
  */
typedef struct
{
	VMINT vm_sym_permission_list_len;
	vm_permission_t vm_sym_permission_list[SYM_PERMISSION_LEN];
} vm_nvram_permission_list_t;   

/**
 *	在NVRAM中设置系统接口许可列表
 *    @param permission_list_ptr    系统接口许可列表
 *
 *    @return  TRUE=设置成功; FALSE=设置失败;
 */
VMINT vm_nvram_set_sym_permission(vm_nvram_permission_list_t * permission_list_ptr);

/**
 *	在NVRAM中读取系统接口许可列表
 *    @param permission_list_ptr    系统接口许可列表
 *
 *    @return  TRUE=设置成功; FALSE=设置失败;
 */
VMINT vm_nvram_get_sym_permission(vm_nvram_permission_list_t * permission_list_ptr);

/**
 *	合并许可列表,导入app的许可列表，与系统许可列表作许可标记交集
 *    得到合并后的许可列表
 *    @param   app_permission_list  应用程序接口许可列表,输入时应为非空
 *    @param   app_permission_list_len  应用程序接口许可列表长度,输入时必须大于0
 *    @param   merge_permission_list   合并后返回的许可列表，输入时应为非空.
 *    @param   merge_permission_list_len_ptr 合并许可列表,输入时必须大于0, 如果合并成功返回为大于0,否则为0.
 *
 *    @retrun   FALSE=合并失败, TRUE=合并成功
 */
VMINT vm_merge_permission(vm_permission_t * app_permission_list, 
							   VMINT app_permission_list_len, 
							   vm_permission_t * merge_permission_list, 
							   VMINT * merge_permission_list_len_ptr);



/**
 *	系统配置数据结构
 */ 
typedef struct
{
	vm_time_t sys_time_stamp[5]; 
	VMINT uid;
	VMINT mobile_phone_id;
} vm_nvram_sysconf_t;

/**
 *	从nvram得到系统配置
 *	@param sysconfig_ptr   指向系统配置数据结构的指针，不能为NULL
 *	@return TRUE=操作成功 , FALSE=操作失败
 */
VMINT vm_get_sysconf(vm_nvram_sysconf_t * sysconfig_ptr);

/**
 *	设置计费通道组列表到nvram
 *	@param sysconfig_ptr   指向系统配置数据结构的指针，不能为NULL
 *	@return TRUE=操作成功 , FALSE=操作失败
 */
VMINT vm_set_sysconf(vm_nvram_sysconf_t * sysconfig_ptr);

/********************************************************/
/*********************以下是AS 相关**************/
/********************************************************/
typedef struct  
{
	 VMINT8 update_type;
	 VMINT8 update_hint;
	 VMINT8 download_flag;
	 VMINT8 sim_index;
	 VMINT8 net_type;
	 VMINT8 theme_index;
	 VMINT8 sitenav_type;
	 VMINT8 back_char;
	 VMINT update_value;
	 VMINT sitenav_value;
	 VMINT reserved_vvalue;	 
	 VMINT  back_int;
} vm_nvram_appstore3_config_t;


typedef struct
{
	VMINT8 update_type;
	VMINT8 update_hint;
	VMINT8 download_flag;
	VMINT8 sim_index;
	VMINT update_value;	
} vm_nvram_appstore_config_t;

/**
 *	设置appstore配置到nvram
 *	@param appstore_config_ptr   指向appstore配置数据结构的指针，不能为NULL
 *	@return TRUE=操作成功 , FALSE=操作失败
 */
VMINT vm_set_appstore_config(vm_nvram_appstore_config_t * appstore_config_ptr);

/**
 *	从nvram得到appstore配置
 *	@param appstore_config_ptr   指向appstore配置数据结构的指针，不能为NULL
 *	@return TRUE=操作成功 , FALSE=操作失败
 */
VMINT vm_get_appstore_config(vm_nvram_appstore_config_t * appstore_config_ptr);

/**
 *	设置appstore3扩展配置到nvram
 *	@param appstore_config_ptr   指向appstore配置数据结构的指针，不能为NULL
 *	@return TRUE=操作成功 , FALSE=操作失败
 */
VMINT vm_set_appstore3_config(vm_nvram_appstore3_config_t * appstore_config_ptr);

/**
 *	从nvram得到appstore3扩展配置
 *	@param appstore_config_ptr   指向appstore配置数据结构的指针，不能为NULL
 *	@return TRUE=操作成功 , FALSE=操作失败
 */
VMINT vm_get_appstore3_config(vm_nvram_appstore3_config_t * appstore_config_ptr);



/********************************************************/
/*********************以下是计费相关**************/
/********************************************************/

/**
 * 通道数据结构
 */
typedef struct {	
	VMUINT operator_bitmap; 
	VMUINT fee;   
	VMUINT16 sms_type;  
	VMUINT16 org_id; 
	VMWCHAR service_name[11];
	VMWCHAR sp_name[9]; 
	VMCHAR customer_number[16];
	VMCHAR sms_id[21]; 
	VMCHAR sms_content[31];
	} vm_paychannel_ext_t;


/**
 * NVRAM里所允许存储的计费通道个数。
 */
#define NVRAM_PAYMENT_CHANNEL_EXT_NUM						(32)
#define NVRAM_PAYMENT_CHANNEL_EXT_NUM_PER_RECORD			(16)



/**
 *	通道列表数据结构
 */
typedef struct
{
	vm_paychannel_ext_t	paychannel_list_ext[NVRAM_PAYMENT_CHANNEL_EXT_NUM];
}  vm_nvram_paychannel_list_ext_t;

/**
 *	从nvram得到计费通道列表
 *	@param paychannel_list_ext_ptr   指向计费通道列表数据结构的指针，不能为NULL
 *	@return TRUE=操作成功 , FALSE=操作失败
 */
VMINT vm_get_pay_channel_list_ext(vm_nvram_paychannel_list_ext_t * paychannel_list_ext_ptr);

/**
 *	设置计费通道列表到nvram
 *	@param paychannel_list_ext_ptr   指向计费通道列表数据结构的指针，不能为NULL
 *	@return TRUE=操作成功 , FALSE=操作失败
 */
VMINT vm_set_pay_channel_list_ext(vm_nvram_paychannel_list_ext_t * paychannel_list_ext_ptr);


/**
 *     计费凭证结构
 */
typedef struct {
	VMINT app_id;  /*流水号*/
	VMUINT seq_id;  /*应用程序编号*/
	VMUINT local_payment_id;  /*计费点编号*/
	VMUINT fee;  /*价格*/
	VMUINT source;  /*应用程序来源，0为预装，1为下载*/
	VMCHAR ext_content[12];  /*上传到服务器的信息*/
} vm_charge_detail_record_t;

/**
 *    NVRAM里所允许存储的计费凭证的个数
 */
#define NVRAM_CHARGE_DETAIL_NUM     (32)

/**
 *    计费凭证列表
 */
typedef struct {
	vm_charge_detail_record_t charge_detail[NVRAM_CHARGE_DETAIL_NUM];
} vm_nvram_charge_detail_list_t;

/**
 *	 从nvram得到 计费凭证列表
 *	@param charge_detail_list_ptr   指向 计费凭证列表数据结构的指针，不能为NULL
 *	@return TRUE=操作成功 , FALSE=操作失败
 */
VMINT vm_get_charge_detail_list(vm_nvram_charge_detail_list_t * charge_detail_list_ptr);

/**
 *	设置 计费凭证列表到nvram
 *	@param charge_detail_list_ptr   指向 计费凭证列表数据结构的指针，不能为NULL
 *	@return TRUE=操作成功 , FALSE=操作失败
 */
VMINT vm_set_charge_detail_list(vm_nvram_charge_detail_list_t * charge_detail_list_ptr);


/**
 *    计费短信凭证数据结构
 */
typedef struct {
VMUINT seq_id;
VMCHAR sms_access[21];
VMCHAR sms_command[31];
} vm_sms_detail_record_t;

/**
 *    NVRAM里所允许存储的计费短信凭证的个数
 */
#define NVRAM_CHARGE_SMS_DETAIL_NUM     (32)

/**
 *    计费短信凭证列表
 */
typedef struct {
	vm_sms_detail_record_t   charge_sms_detail[NVRAM_CHARGE_SMS_DETAIL_NUM];
} vm_nvram_charge_sms_detail_list_t;

/**
 *	 从nvram得到 计费短信凭证列表
 *	@param charge_sms_detail_list_ptr   指向 计费短信凭证列表数据结构的指针，不能为NULL
 *	@return TRUE=操作成功 , FALSE=操作失败
 */
VMINT vm_get_charge_sms_detail_list(vm_nvram_charge_sms_detail_list_t * charge_sms_detail_list_ptr);

/**
 *	设置 计费短信凭证列表到nvram
 *	@param charge_sms_detail_list_ptr   指向 计费短信凭证列表数据结构的指针，不能为NULL
 *	@return TRUE=操作成功 , FALSE=操作失败
 */
VMINT vm_set_charge_sms_detail_list(vm_nvram_charge_sms_detail_list_t * charge_sms_detail_list_ptr);

/**
 *	计费水印数据结构
 */
typedef struct {
VMINT app_id;
VMINT app_state;
VMINT8 available [8];
} vm_app_info_ext_t;

/**
 *    NVRAM里所允许存储的程序状态的个数
 */
#define NVRAM_APP_PAYMENT_INFO_EXT_NUM			(500)
#define NVRAM_APP_PAYMENT_INFO_EXT_NUM_PER_RECORD			(100)

/**
 *	应用程序状态列表数据结构
 */
typedef struct
{
	vm_app_info_ext_t app_info_ext_list[NVRAM_APP_PAYMENT_INFO_EXT_NUM];
} vm_nvram_app_info_ext_list_t;

/**
 *	 从nvram得到应用信息列表
 *	@param app_info_ext_list_ptr   指向应用程序状态列表数据结构的指针，不能为NULL
 *	@return TRUE=操作成功 , FALSE=操作失败
 */
VMINT vm_get_app_info_list(vm_nvram_app_info_ext_list_t * app_info_ext_list_ptr);

/**
 *	设置应用信息列表到nvram
 *	@param app_info_ext_list_ptr   指向应用程序状态列表数据结构的指针，不能为NULL
 *	@return TRUE=操作成功 , FALSE=操作失败
 */
VMINT vm_set_app_info_list(vm_nvram_app_info_ext_list_t * app_info_ext_list_ptr);


/**
 *    计费配置结构
 */
typedef struct {
VMUINT update_interval_days;
VMUINT sms_notification_flag;
VMUINT user_balance;
VMUINT reserved;
} vm_pay_config_t;

/**
 *	 从nvram得到计费配置
 *	@param pay_config_ptr   指向计费配置数据结构的指针，不能为NULL
 *	@return TRUE=操作成功 , FALSE=操作失败
 */
VMINT vm_get_pay_config(vm_pay_config_t * pay_config_ptr);

/**
 *	设置计费配置到nvram
 *	@param pay_config_ptr   指向计费配置数据结构的指针，不能为NULL
 *	@return TRUE=操作成功 , FALSE=操作失败
 */
VMINT vm_set_pay_config(vm_pay_config_t * pay_config_ptr);


/**
 *     运营商结构
 */
typedef struct {
	VMCHAR operator_code[8];
} vm_operator_code_t;

#define NVRAM_OPERATE_CODE_LIST_NUM   (32)

/**
 *	运营商表数据结构
 */
typedef struct
{
	vm_operator_code_t operator_code_list[NVRAM_OPERATE_CODE_LIST_NUM];
} vm_nvram_operator_code_list_t;

/**
 *	 从nvram得到运营商表
 *	@param operator_code_list_ptr   指向运营商表数据结构的指针，不能为NULL
 *	@return TRUE=操作成功 , FALSE=操作失败
 */
VMINT vm_get_operator_code(vm_nvram_operator_code_list_t * operator_code_list_ptr);

/**
 *	设置运营商表到nvram
 *	@param operator_code_list_ptr   指向运营商表数据结构的指针，不能为NULL
 *	@return TRUE=操作成功 , FALSE=操作失败
 */
VMINT vm_set_operator_code(vm_nvram_operator_code_list_t * operator_code_list_ptr);


 
/**
 * 通道数据结构
 */
typedef struct
{
	VMUINT		org_id;				/*组号，以位段方式表示。属于0号组就把最低位置1，以此类推。	*/
	VMUINT16	        sp_id;				/*移动或联通的标志,	1bit是移动，2bit是联通，3bit是电信。	*/
	VMCHAR		sms_id[20];			/*短信接入号。												*/
	VMCHAR		sms_content[30];	/*短信内容。												*/
	VMUINT		fee;					/*通道的单价，单位为分。									*/
}  vm_paychannel_t;

/**
 * NVRAM里所允许存储的计费通道个数。
 */
#define NVRAM_PAYMENT_CHANNEL_NUM						(128)
#define NVRAM_PAYMENT_CHANNEL_NUM_PER_RECORD			(32)

/**
 *	通道列表数据结构
 */
typedef struct
{
	vm_paychannel_t	paychannel_list[NVRAM_PAYMENT_CHANNEL_NUM];
}  vm_nvram_paychannel_list_t;

/**
 *	应用程序状态值，枚举型
 */
typedef enum
{
	VM_TRIAL = 0,		/*试用，待缴费*/
	VM_USING,			/*已经缴费，在用*/
	VM_TERMINATE,		/*缴费失效，停用*/
	VM_NO_STATE
} vm_app_state_e;

/**
 *	应用程序状态数据结构
 */
typedef struct 
{
	VMINT app_id;				/*应用程序序号*/
	VMINT app_state;			/*应用程序状态*/
	VMINT8 available[8];		/*应用程序有效字段，有效时含8字节码，无效时为全0*/
} vm_app_info_t;

#define NVRAM_APP_PAYMENT_INFO_NUM			(500)

/**
 *	应用程序状态列表数据结构
 */
typedef struct
{
	vm_app_info_t app_info_list[NVRAM_APP_PAYMENT_INFO_NUM];
} vm_nvram_app_info_list_t;

/**
 *	 从nvram得到应用信息列表
 *	@param app_info_list_ptr   指向应用程序状态列表数据结构的指针，不能为NULL
 *	@return TRUE=操作成功 , FALSE=操作失败
 */
VMINT vm_get_app_state_list(vm_nvram_app_info_list_t * app_info_list_ptr);

/**
 *	设置应用信息列表到nvram
 *	@param app_info_list_ptr   指向应用程序状态列表数据结构的指针，不能为NULL
 *	@return TRUE=操作成功 , FALSE=操作失败
 */
VMINT vm_set_app_state_list(vm_nvram_app_info_list_t * app_info_list_ptr);

/**
 *	设置计费通道列表到nvram
 *	@param paychannel_list_ptr   指向计费通道列表数据结构的指针，不能为NULL
 *	@return TRUE=操作成功 , FALSE=操作失败
 */
VMINT vm_set_pay_channel_list(vm_nvram_paychannel_list_t * paychannel_list_ptr);

/**
 *	从nvram得到计费通道列表
 *	@param paychannel_list_ptr   指向计费通道列表数据结构的指针，不能为NULL
 *	@return TRUE=操作成功 , FALSE=操作失败
 */
VMINT vm_get_pay_channel_list(vm_nvram_paychannel_list_t * paychannel_list_ptr);



/*vre3.1.1开始增加*******************************************************************************/

/**(vre3.1.1开始有此函数)
 */
VMINT vm_set_local_apn_info(vm_local_info * local_info_ptr);

 /**(vre3.1.1开始有此函数)
 */
VMINT vm_get_local_apn_info(vm_local_info * local_info_ptr);
VMINT vm_set_user_apn_info(vm_apn_info * apn_info_ptr);

VMINT vm_get_user_apn_info(vm_apn_info * apn_info_ptr);
 
 	
typedef struct {	
	VMUINT fee_actual;   
	VMINT reserv1;     /*(vre3.1.4开始此保留字段表示日线)*/
	VMINT reserv2;	   /*(vre3.1.4开始此保留字段表示月线)*/
	VMUINT operator_bitmap2; 
	VMUINT operator_bitmap3;
	VMUINT operator_bitmap4;	
} vm_paychannel_a_ext_t;

#define NVRAM_PAYMENT_CHANNEL_A_EXT_NUM						(32)
#define NVRAM_PAYMENT_CHANNEL_A_EXT_NUM_PER_RECORD			(16)

typedef struct
{
	vm_paychannel_a_ext_t	paychannel_a_list_ext[NVRAM_PAYMENT_CHANNEL_A_EXT_NUM];
}  vm_nvram_paychannel_a_list_ext_t;


typedef  struct
{
	VMINT rate;                           /* 倍率 */
	VMCHAR mcc[4];                     /*国家码*/
	VMWCHAR title[64];               /*提示界面标题: 资费说明*/ 
	VMWCHAR ok[16];				 /*左软键提示语言:确认*/ 
	VMWCHAR back[16];			 /*右软键提示语言:返回*/ 
	VMWCHAR notification1[160];	/*界面1提示语言:提示用户将要购买的物品的提示语*/ 
	VMWCHAR notification2[128];	/*界面2提示语言:计费中的提示语*/ 
	VMWCHAR notification3[128];	/*界面3提示语言:计费成功的提示语*/ 
	VMWCHAR notification4[160];    /*界面4提示语言:计费失败的提示语*/  
	VMWCHAR currency_unit[10];    /*英文表示的本地货币单位*/
}vm_pay_notification_t;


/**(vre3.1.1开始有此函数)
 *	设置到提示语言到nvram
 *	@param pay_notification_ptr   指向运营商表数据结构的指针，不能为NULL
 *	@return TRUE=操作成功 , FALSE=操作失败
 */
VMINT vm_set_pay_notification(vm_pay_notification_t * pay_notification_ptr);

/**(vre3.1.1开始有此函数)
 *	 从nvram得到该国提示语言
 *	@param pay_notification_ptr   指向运营商表数据结构的指针，不能为NULL
 *	@return TRUE=操作成功 , FALSE=操作失败
 */
VMINT vm_get_pay_notification(vm_pay_notification_t * pay_notification_ptr);

/**(vre3.1.1开始有此函数)
 *	设置到计费通道扩展相关信息到nvram
 *	@param paychannel_a_list_ext_ptr   指向运营商表数据结构的指针，不能为NULL
 *	@return TRUE=操作成功 , FALSE=操作失败
 */
VMINT vm_set_pay_channel_a_list_ext(vm_nvram_paychannel_a_list_ext_t * paychannel_a_list_ext_ptr);

/**(vre3.1.1开始有此函数)
 *	 从nvram得到计费通道扩展相关信息
 *	@param paychannel_a_list_ext_ptr   指向运营商表数据结构的指针，不能为NULL
 *	@return TRUE=操作成功 , FALSE=操作失败
 */
VMINT vm_get_pay_channel_a_list_ext(vm_nvram_paychannel_a_list_ext_t * paychannel_a_list_ext_ptr);



/**(vre3.1.1开始有此函数)
 *	设置运营商表到nvram     (index取值: 0~3)
 *	@param operator_code_list_ptr   指向运营商表数据结构的指针，不能为NULL
 *	@return TRUE=操作成功 , FALSE=操作失败
 */
VMINT vm_set_operator_code_ext(VMINT index, vm_nvram_operator_code_list_t * operator_code_list_ptr);

 
/**
 *	 从nvram得到运营商表   (index取值: 0~3)
 *	@param operator_code_list_ptr   指向运营商表数据结构的指针，不能为NULL
 *	@return TRUE=操作成功 , FALSE=操作失败
 */
VMINT vm_get_operator_code_ext(VMINT index, vm_nvram_operator_code_list_t * operator_code_list_ptr);


/****************************************************************************************************/


/*vre3.1.4开始增加*******************************************************************************/
/*
 * 计费通道使用信息
 */
typedef struct {
VMUINT year;
VMUINT month;
VMUINT day;
VMUINT daily_used_num;
VMUINT monthly_used_num;
VMINT reserv1;
VMINT reserv2;
} vm_paychanel_usage_info_t;


/*
 * 计费通道使用信息列表
 */
typedef struct
{
	vm_paychanel_usage_info_t	paychannel_usage_list_ext[NVRAM_PAYMENT_CHANNEL_EXT_NUM];
}  vm_nvram_paychannel_usage_list_t;


/**(vre3.1.4开始有此函数)
 *	从nvram得到计费通道使用信息列表
 *	@param paychannel_usage_list_ptr   指向计费通道列表数据结构的指针，不能为NULL
 *	@return TRUE=操作成功 , FALSE=操作失败
 */
 VMINT vm_get_paychannel_usage_list(vm_nvram_paychannel_usage_list_t * paychannel_usage_list_ptr);
 
/**(vre3.1.4开始有此函数)
 *	设置计费通道使用信息列表到nvram
 *	@param paychannel_usage_list_ptr   指向计费通道列表数据结构的指针，不能为NULL
 *	@return TRUE=操作成功 , FALSE=操作失败
 */
VMINT vm_set_paychannel_usage_list(vm_nvram_paychannel_usage_list_t * paychannel_usage_list_ptr);


/**
 *     扩展计费凭证结构
 */
typedef struct {
	VMINT app_id;  /*流水号*/
	VMUINT seq_id;  /*应用程序编号*/
	VMUINT local_payment_id;  /*计费点编号*/
	VMUINT fee;  /*价格*/
	VMUINT source;  /*应用程序来源，0为预装，1为下载*/
	VMCHAR ext_content[12];  /*上传到服务器的信息*/
	VMCHAR mcc[4];  /*国家码*/
} vm_charge_detail_record_ext_t;

/**
 *       扩展计费凭证列表
 */

typedef struct {
	vm_charge_detail_record_ext_t charge_detail_ext[NVRAM_CHARGE_DETAIL_NUM];
} vm_nvram_charge_detail_list_ext_t;



/**(vre3.1.4开始有此函数)
 *	 从nvram得到  扩展计费凭证列表
 *	@param charge_detail_list_ptr   指向 计费凭证列表数据结构的指针，不能为NULL
 *	@return TRUE=操作成功 , FALSE=操作失败
 */
VMINT vm_get_charge_detail_list_ext(vm_nvram_charge_detail_list_ext_t * charge_detail_list_ext_ptr);

/**(vre3.1.4开始有此函数)
 *	设置  扩展计费凭证列表到nvram
 *	@param charge_detail_list_ptr   指向 计费凭证列表数据结构的指针，不能为NULL
 *	@return TRUE=操作成功 , FALSE=操作失败
 */
VMINT vm_set_charge_detail_list_ext(vm_nvram_charge_detail_list_ext_t * charge_detail_list_ext_ptr);


/**
 *    扩展计费配置结构
 */
typedef struct {
VMUINT update_interval_days;
VMUINT sms_notification_flag;
VMUINT user_balance;
VMUINT reserved;
VMWCHAR pre_string[12]; 
VMWCHAR suff_string[2]; 
} vm_pay_config_ext_t;



/**(vre3.1.4开始有此函数)
 *	 从nvram得到 扩展计费配置
 *	@param pay_config_ptr   指向 扩展计费配置数据结构的指针，不能为NULL
 *	@return TRUE=操作成功 , FALSE=操作失败
 */
VMINT vm_get_pay_config_ext(vm_pay_config_ext_t * pay_config_ext_ptr);

/**(vre3.1.4开始有此函数)
 *	设置 扩展计费配置到nvram
 *	@param pay_config_ptr   指向 扩展计费配置数据结构的指针，不能为NULL
 *	@return TRUE=操作成功 , FALSE=操作失败
 */
VMINT vm_set_pay_config_ext(vm_pay_config_ext_t * pay_config_ext_ptr);


typedef struct {	
	VMCHAR mcc[4];
	vm_pay_notification_t vm_notification_info;
	vm_paychannel_ext_t vm_paychannel_info[NVRAM_PAYMENT_CHANNEL_EXT_NUM];
	vm_paychannel_a_ext_t vm_paychannel_a_ext[NVRAM_PAYMENT_CHANNEL_A_EXT_NUM];
	vm_operator_code_t  vm_operator_info[NVRAM_OPERATE_CODE_LIST_NUM];
	vm_operator_code_t vm_operator_info2[NVRAM_OPERATE_CODE_LIST_NUM];
	vm_operator_code_t vm_operator_info3[NVRAM_OPERATE_CODE_LIST_NUM];
	vm_operator_code_t vm_operator_info4[NVRAM_OPERATE_CODE_LIST_NUM];
	//vm_pay_config_t  vm_pay_config_info;
	vm_pay_config_ext_t  vm_pay_config_info;

} vm_payment_info_t;


typedef struct {	
	VMCHAR mcc[4];
	vm_pay_notification_t * vm_notification_p;
	vm_paychannel_ext_t * vm_paychannel_p;
	VMUINT16 paychannel_len;
	vm_paychannel_a_ext_t * vm_paychannel_a_ext_p;
	VMUINT16 paychannel_a_ext_len;
	vm_operator_code_t * vm_operator_info0_p;
	VMUINT16 operator_info_len0;
	vm_operator_code_t * vm_operator_info1_p;
	VMUINT16 operator_info_len1;
	vm_operator_code_t * vm_operator_info2_p;
	VMUINT16 operator_info_len2;
	vm_operator_code_t * vm_operator_info3_p;
	VMUINT16 operator_info_len3;
	vm_pay_config_ext_t * vm_pay_config_info;
} vm_payment_info_csr_t;



#ifdef __cplusplus
}
#endif

#endif





