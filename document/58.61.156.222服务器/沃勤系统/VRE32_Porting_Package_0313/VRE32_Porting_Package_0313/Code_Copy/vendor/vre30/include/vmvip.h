#include "vmhttp.h"

#ifndef VIP_H_
#define VIP_H_

#ifdef __cplusplus
extern "C" {
#endif

#define SHELL_CONFIG_FILENAME           "shell_config.cfg"//shaw

#ifdef _VMDEBUG
#define  PHSH_VIP_DEBUG         //shaw
#endif
//#define  APPSTORE_SUPPORT_COFING
#define  VIP_SUPPORT_NEW_BILLING

//rencai.xiao 2010/04/19 VIP support to upload imsi
#define VIP_SUPPORT_UPLOAD_IMSI
//rencai.xiao 2010/04/23 VIP can get url from nvram
#define VIP_SUPPORT_GET_CONFIG_FROM_NVRAM

#define VIP_CHECK_DOWNLOAD_READY
/**
 * @name VIP协议的版本号
 * @brief 按需要选择打开其中的有一个。
 * @{
 */
//#define VIP12
//#define VIP13
#define VIP14  //add by shaw, 09/11/04

//rencai.xiao 2010/04/28 download payment hint msg.
#define VIP15

//rencai.xiao 2010/06/03 twice confirm
#define VIP16
/** @} */

/* 
 * VIP通讯的联网地址 
 */
#ifdef OS_ANYKA
	#define PROVISION_URL "http://anyka.vspace.net.cn/vmac/servlet/provision"
#else
   //#define  PROVISION_URL "http://www.vspace.net.cn/vresps3/provision"
//#define  PROVISION_URL "http://172.26.59.60:8080/vresps/provision"//VIP14测试后台
    //#define  PROVISION_URL "http://www.vspace.net.cn/vresps/provision"//VIP14测试后台
	//#define PROVISION_URL "http://www.vspace.net.cn/vresps/provision"//新测试后台
	//#define PROVISION_URL "http://as.vspace.net.cn:9999/vresps/provision"//正式后台
    //#define PROVISION_URL "http://www.vspace.net.cn/vmacmtk/provision" 
	//#define PROVISION_URL "http://218.249.47.76/sps/provision"//北京后台
	//#define PROVISION_URL "http://www.vspace.net.cn/shelldemo/provision"
	//#define PROVISION_URL "http://192.168.0.53:8080/sps/provision"
	//#define PROVISION_URL "http://www.vogins.com:9999/vmac/servlet/provision"
  #define PROVISION_URL "http://as.vspace.net.cn:9999/vresps/provision"//正式后台
	//#define PROVISION_URL "http://gate.vspace.net.cn:9999/vresps/provision"//香港服务器后台
		//#define PROVISION_URL "http://test.vspace.net.cn/vresps/provision"//test
#endif

/**
 * @name VIP请求的命令字.
 * @{
 */
#define REQ_CONNECT_CMD				1
#define REQ_WAP_PROXY_RESULT		2
#define REQ_ASK_FOR_PRICE_CMD		3
#define REQ_PAY_BY_WAP				4
#define REQ_GET_USER_INFO			6
#define REQ_ENCRYPT_CMD				7
#define REQ_READRES_CMD				10
#define REQ_POST_DATA_CMD           11
/** @} */

/**
 * @name VIP响应的命令字.
 * @{
 */
#define RES_WAP_PAYMENT_COMPLETE	1
#define RES_PROCESS_WAP_PROXY		2
#define RES_PRICE_INFO_CMD			3
#define RES_ERROR_CMD				5   /*下载失败其它情况*/
#define RES_ENCRYPT_CMD				7
#define RES_USER_INFO				6
#define RES_ENCRYPT_CMD				7
#define RES_RESCONTENT_CMD			10  /*下载成功*/

/** @} */

#ifndef VIP12
#define VIP_UPDATE_VRE_SYS_CONFIG_URL	"/update/config.txt"       /*系统配置信息*/
#define VIP_DSM_URL						"/shell/app_list.txt"      /*更新列表*/
#define VIP_VRE_EXECUTABLE_FILE_URL		"/shell/download_app.txt"  /*下载应用*/

#define VIP_FEE_CHANNEL_RUL             "/update/feechannel.txt"   /*计费通道*/
#ifdef VIP14
#define VIP_DSM_DOWN_TOP_URL            "/shell/down_top.txt"      /*热门下载*/
#define VIP_DSM_NEW_TOP_URL             "/shell/new_top.txt"       /*最新上架*/
#define VIP_DSM_RECOMMEDN_URL           "/shell/recommend.txt"     /*精品推荐*/
#define VIP_DOWNLOAD_ICON_URL           "/shell/download_icon.txt" /*icon图标*/
#define VIP_RANK_APP_URL                "/shell/rank_app.txt"      /*评级*/
#define VIP_MSG_LIST_URL                "/shell/msg_list.txt"      /*站内消息*/
#define VIP_APP_DETAIL_URL              "/shell/app_detail.txt"    /*产品详细信息*/
#define VIP_WAP_LIST_URL                "/shell/wap_list.txt"      /*手机酷站*/

//added by rencai.xiao 2010/07/21
#define VIP_GET_FILESIZE_URL             "/shell/getfilesize.txt"     /*获取文件大小*/
#define VIP_CHECK_DLL_VERSION_URL        "/shell/sm_checkupdate.txt"  /*检测dll版本*/

#ifdef VIP_SUPPORT_NEW_BILLING
#define VIP_SYNC_FEEINFO_URL            "/upload/sync_feeinfo.txt"  /*计费信息同步*/
#define VIP_SYNC_SMSINFO_URL            "/upload/sync_smsinfo.txt"  /*短信信息同步*/
#define VIP_PROMOTION_UPDATE_URL        "/update/promotion_update.txt" /*促销金额更新*/
#endif
#endif
#endif

typedef unsigned char BYTE;

/**
 * VIP协议里的注册回调函数的类型。
 */
#ifdef VIP12
typedef void (* vm_vip_callback) (VMINT vip_response_type, const void* vip_response);
#else
typedef void (* vm_vip_progress_callback)(VMINT percent);
typedef void (* vm_vip_callback) (VMINT uid, VMINT mpi, VMINT vip_response_type, 
	const void* vip_response, VMUINT response_size);
#endif

/**
 * @struct user_info_t
 * @brief VIP协议得到用户数据的结构.
 */
typedef struct user_info_t {
	int userid;
	char nickname[50];
	char password[50];
} user_info_t;

/**
 * @struct session_pool_item_t
 * @brief HTTP 连接的管理结构.
 */
typedef struct session_pool_item_t {
	int used;
	http_session_t session;
} session_pool_item_t;

#ifndef VIP12
/**
 * @struct vm_http_item_t
 * @brief http连接请求的上下文.
 */
typedef struct vm_vip_item_t {
	VMINT user_id;							/**<VRE用户编号.								*/
	VMINT mobile_phone_id;					/**<机型号在VIP13和以后的版本中由服务机器分配.	*/
	VMINT http_handle;						/**<HTTP连接句柄. 								*/
	VMSHORT used;							/**<是否正在发送的标志位.						*/
	VMUINT8 des_key[8];						/**<DES密钥.									*/
	VMSHORT encrypt;						/**<该次连接是否被加密,0为加密,非0为
												已经被加密.									*/
	vm_vip_callback callback;				/**<客户程序注册上来的回调函数.					*/
	VMCHAR vip_session[255];				/**<在VIP通讯期间产生的会话号.					*/
	VMUINT8* repeat_content;				/**<重新发送的内容。							*/
	VMINT repeat_content_size;				/**<重发内容的长度。							*/
	VMINT allow_repeat;						/**<是否允许重新发送VIP请求。					*/
	vm_vip_progress_callback progress_hook;	/**<VIP协议进度的回调函数。						*/
} vm_vip_item_t;
#endif

/**
 * @name 使用模式.
 */
#define USAGE_MODE_PER_TIME		(1)
#define USAGE_MODE_PERIOD		(2)

/**
 * @name 付费方式.
 */
#define PAY_METHOD_BY_WAP		(1)
#define PAY_METHOD_BY_SMS		(2)

//add by shaw, 09/11/06
/**
 * @name 连接
 */
#define  VIP_APP_HANDLE         (0)      //下载应用的连接
#define  VIP_OTHER_HANDLE       (1)      //下载其它内容的连接

#ifdef LINK_RICH
/* 短信计费方式 */
typedef struct sms_charge_t {
	char access_number[21];
	char order[100];
	int sms_count;
} sms_charge_t;
/* WAP计费方式 */
typedef struct wap_charge_t {
	char reverse_subscribe_url[181];	// 反向订购地址。
} wap_charge_t;
/* 计费方式 */
typedef union charge_info_t {
	sms_charge_t sms_info;
	wap_charge_t wap_info;
} charge_info_t;
/* 计费信息 */
typedef struct price_t {
	BYTE usage_mode;					// 计费模式
	int param;							// 计费天数或次数
	int price;							// 歌曲价格
	BYTE pay_method;					// 计费用方式
	char download_song_url[181];		// 歌曲下载地址
	charge_info_t charge_info;			// 计费信息
} price_t;
#else
typedef struct price_t {
	int usage_mode;
	int param;
	int price;
	int pay_method;
	char access_number[21];
	char order_cmd[100];
	int sms_count;
} price_t;
#endif

/**
 * @struct res_content_t
 * @brief 资源请求对应的响应.
 */
typedef struct res_content_t {
	int len;					/**<资源响应的字节长度。	*/
	BYTE* buf;					/**<资源的头指针。			*/
} res_content_t;

/**
 * @struct error_t
 * @brief 错误响应.
 */
typedef struct error_t {
	int code;					/**<错误码。				*/
	char message[255];			/**<错误码相关的文字说明。	*/
} error_t;

#ifdef VIP12
/**
 * 向vip处理逻辑中注册回调函数，该函数应该在发送任何vip
 * 请求后调用。
 * 
 * @param[in]	pf 注册到vip通讯的回调函数。
 */
void register_vip_callback(vm_vip_callback pf);
#else
/**
 * 向vip处理逻辑中注册回调函数，该函数应该在发送任何vip
 * 请求后调用。
 * 
 * @param[in]	pf 注册到vip通讯的回调函数。
 * @return		0 表示注册成功，否则为错误码，本函数也必须在vip_init函数调用后
 *				被调用。
 */
VMINT register_vip_callback(vm_vip_callback pf);

//add by shaw, 09/11/05   用于注册下载App回调的接口
#ifdef VIP14
/**
 * 向vip处理逻辑中注册回调函数，该函数应该在发送任何vip
 * 请求后调用。
 * 
 * @param[in]	pf 注册到vip通讯的回调函数。
 * @return		0 表示注册成功，否则为错误码，本函数也必须在vip_init函数调用后
 *				被调用。
 */
VMINT register_vip_callback_for_app(vm_vip_callback pf);
#endif
#endif

#ifdef VIP12
/**
 * 初始化VIP协议栈，这个方法必须在调用任何VIP方法之前执行。
 *
 * @param[in]			phondid	手机型号编号。
 * @param[in]			userid 用户编号。
 */
void vip_init(VMINT phoneid, VMINT userid);
#else
/**
 * 初始化VIP协议栈，这个方法必须在调用任何VIP方法之前执行。
 * 
 * @param[in]			phondid	手机型号编号。
 * @param[in]			userid 用户编号。
 * @return				0表示初始化成功，否则为失败。
 */
VMINT vip_init(VMINT phoneid, VMINT userid);

#ifdef VIP14
/**
 * 初始化VIP协议栈，这个方法必须在调用任何VIP方法之前执行。
 * 
 * @param[in]			phondid	手机型号编号。
 * @param[in]			userid 用户编号。
 * @param[in]           nHandle 初始化，VIP_APP_HANDLE为下载应用的句柄，VIP_OTHER_HANDLE下载其它内容的句柄
 * @return				0表示初始化成功，否则为失败。
 */
VMINT vip_init_ext(VMINT phoneid, VMINT userid, VMINT nHandle);
#endif
#endif

/**
 * 向VIP协议栈注册一个显示进度的回调函数，本函数只有在VIP13协议来才被实现。
 * 
 * @param[in]			progress_hook 回传接受VIP响应的进度。
 * @return				0表示成功，否则为失败，本函数也必须在
*/
#ifndef VIP12
VMINT register_vip_progress_callback(vm_vip_progress_callback progress_hook);

//add by shaw, 09/11/05  用于注册下载App回调的接口
#ifdef VIP14   
VMINT register_vip_progress_callback_for_app(vm_vip_progress_callback progress_hook);
#endif
#endif

/**
 * 读资源，这是个异步方法，调用后立即返回，结果通过VM_VIP_RESCONTENT消息反馈给应用程序。
 *
 * @param[in]			respath 资源路径。
 */
VMINT vip_read_resource(VMCHAR* respath);

/**
 * 询价请求，这是异步方法，调用后立即返回，结果通过VM_VIP_PRICE_INFO消息反馈给应用程序。
 *
 * @param[in]			pay_point_id 计费点编号。
 */
VMINT vip_ask_for_price(VMINT pay_point_id);

/**
 * 取得用户编号。
 */
VMINT vip_get_user_id(void);

/**
 * 通过WAP付费，这是异步方法，调用后立即返回，结果通过VM_VIP_WAP_PAYMENT_COMPLETE消息
 * 返回。
 *
 * @param[in]			pay_point_id 计费点编号。
 */
VMINT vip_pay_by_wap(int pay_point_id);

/**
 * 取得手机用户在后台系统的注册资料，调用后立即返回。结果通过VM_VIP_USER_INFO消息返回。
 */
VMINT vip_get_user_info(void);

/**
 * 取消vip请求，对于VIP13协议及以上版本调用效果同
 * vip_cancel_request_and_finalize函数相同。
 */
void cancel_all_vip_request(void);

#ifndef VIP12
/**
 * 取消vip请求，并且释放掉所有的资源，本函数和vip_init对应。如果调用了vip_init
 * 函数则必须调用本函数以释放资源。
 */
void vip_cancel_request_and_finalize(void);

//add by shaw, 09/11/04
#ifdef VIP14
/**
 * 取消指定句柄的连接
 *
 * @nHandle 指定的句柄，VIP_APP_HANDLE为下载应用的句柄，VIP_OTHER_HANDLE为下载其它内容的句柄
 */
void vip_cancel_request_handle(VMINT nHandle);


/**
 * 释放初始化时申请的空间
 */
void vip_finalize(void);
#endif
#endif


/**
 *获取HTTP联网地址
 *
 * @return     0表示获取成功，否则获取失败
 */
VMINT vip_get_shell_config_value(VMCHAR * key_value, VMCHAR * pro_url);
#ifdef __cplusplus
}

#endif

#endif