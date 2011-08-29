#ifndef VMSMS_H_
#define VMSMS_H_

#ifdef __cplusplus
extern "C" {
#endif
#include "vmsys.h"

#define VM_SMS_MSG_CONTENT_LEN             500

#define VM_SMS_MAX_ADDR_LEN            21

#define VM_SMS_MSG_INFO_CONTENT_LEN   (61 + 19)

#define  VM_SMS_SUPPORT_SYN_SCA   1
#define  VM_SMS_NOT_SUPPORT_SYN_SCA   -2

typedef enum
{
    VM_SMS_IDENTIFY_ERROR = -4,
    VM_SMS_MIBR_NOT_IN_PROCESS_SPACE = -3,
    VM_SMS_MIBR_ERROR = -2,
    VM_SMS_REQ_ERROR = -1,                       /*短信操作请求错误*/
    VM_SMS_REQ_NO_ERROR,                    /*短信操作请求成功*/
    VM_SMS_REQ_CALLBACK_REGISTERED
} vm_sms_error_enum;


typedef enum
{
    VM_SMS_BOX_INBOX        = 0x01,                   /*收件箱*/
    VM_SMS_BOX_OUTBOX       = 0x02,                 /*已发送短信文件夹*/
    VM_SMS_BOX_DRAFTS       = 0x04,                   /*草稿箱*/
    VM_SMS_BOX_UNSENT       = 0x08,                   /*待发送短信文件夹*/
    VM_SMS_BOX_SIM          = 0x10,                 /*sim卡*/
    VM_SMS_BOX_ARCHIVE      = 0x20,
    
    VM_SMS_BOX_RESERVED     = 0x40		 /*不支持的状态*/
  
} vm_sms_box_enum;

/* Message Folder Type 111*/
typedef enum
{
    VM_SMS_FOLDER_DEFAULT,
    VM_SMS_FOLDER_ARCHIVE
} vm_sms_folder_enum;

/* 短信存储状态*/
typedef enum
{

    VM_SMS_STATUS_UNREAD       = 0x01,        /*未读状态 */
    VM_SMS_STATUS_READ         = 0x02,          /*已读状态*/
    VM_SMS_STATUS_SENT         = 0x04,          /*已发送状态*/
    VM_SMS_STATUS_UNSENT       = 0x08,       /*待发状态(发件箱)*/
    VM_SMS_STATUS_DRAFT        = 0x10,        /*写草稿状态*/
    
    VM_SMS_STATUS_UNSUPPORTED  = 0x20   /*不支持的状态*/
} vm_sms_status_enum;


/* 消息类型指示*/
typedef enum
{
   VM_SMS_MTI_DELIVER          = 0x00,
   VM_SMS_MTI_DELIVER_REPORT   = 0x00,
   VM_SMS_MTI_SUBMIT           = 0x01,
   VM_SMS_MTI_SUBMIT_REPORT    = 0x01,
   VM_SMS_MTI_STATUS_REPORT    = 0x02,
   VM_SMS_MTI_COMMAND          = 0x02,   
   VM_SMS_MTI_RESERVED         = 0x03
} vm_sms_mti_enum;


/*短信存储位置类型*/
typedef enum
{
    VM_SMS_STORAGE_ME,              /*存储在手机上*/
    VM_SMS_STORAGE_SIM,             /*存储在sim卡上*/

    VM_SMS_STORAGE_UNSPECIFIC
} vm_sms_storage_enum;

typedef enum
{
    VM_MMI_SIM_1 = 0x0001,
    VM_MMI_SIM_2 = 0x0002
  }vm_sim_enum;

/* 网络类型 */
typedef enum
{
    VM_MMI_GSM = 0x0100
  } vm_network_enum;

/* sim卡类型 */
typedef enum
{
    VM_SMS_SIM_1 = VM_MMI_GSM | VM_MMI_SIM_1,   /* sim1卡类型 */
    VM_SMS_SIM_2 = VM_MMI_GSM | VM_MMI_SIM_2,  /* sim2卡类型 */
    VM_SMS_TOTAL
} vm_sms_sim_enum;


/* 短信级别*/
typedef enum
{
   VM_SMS_CLASS_0  = 0x00,    /*短消息直接显示用户终端，不存储*/
   VM_SMS_CLASS_1  = 0x01,   /*短消息存储到手机内存中*/
   VM_SMS_CLASS_2  = 0x02,  /*短消息存储到sim卡上，禁止传输到终端*/
   VM_SMS_CLASS_3  = 0x03    /*短消息存储到用户设备上(TE)*/
} vm_sms_class_enum;


/* 短信有效期*/
typedef enum
{
    VM_SMS_VP_1_HR     = 11,              /* 短信有效期1小时*/
    VM_SMS_VP_6_HR     = 71,              /* 短信有效期6小时*/
    VM_SMS_VP_12_HR    = 143,           /* 短信有效期12小时*/
    VM_SMS_VP_24_HR    = 167,           /* 短信有效期24小时*/
    VM_SMS_VP_72_HR    = 169,           /* 短信有效期72小时*/
    VM_SMS_VP_1_WEEK   = 173,         /* 短信有效期一周*/
    VM_SMS_VP_MAX      = 255
} vm_sms_vp_enum;


/* SMS编码方式*/
typedef enum
{
    VM_SMS_DCS_7BIT        = 0x00, /* GSM 7 bit default alphabet */
    VM_SMS_DCS_8BIT        = 0x04, /* 8 bit data */
    VM_SMS_DCS_UCS2        = 0x08, /* UCS2 (16bit) */
    VM_SMS_DCS_RESERVED    = 0x0c
} vm_sms_dcs_enum;


/* 协议标识*/
typedef enum
{
    VM_SMS_PID_DEFAULT             = 0x00, /* Text SMS */
    VM_SMS_PID_EMAIL               = 0x32, /* Internet Electronic Mail */

    VM_SMS_PID_TYPE_0              = 0x40, /* Short Message Type 0 */
    VM_SMS_PID_REPLACE_TYPE_1      = 0x41, /* Replace Short Message Type 1 */
    VM_SMS_PID_REPLACE_TYPE_2      = 0x42, /* Replace Short Message Type 2 */
    VM_SMS_PID_REPLACE_TYPE_3      = 0x43, /* Replace Short Message Type 3 */
    VM_SMS_PID_REPLACE_TYPE_4      = 0x44, /* Replace Short Message Type 4 */
    VM_SMS_PID_REPLACE_TYPE_5      = 0x45, /* Replace Short Message Type 5 */
    VM_SMS_PID_REPLACE_TYPE_6      = 0x46, /* Replace Short Message Type 6 */
    VM_SMS_PID_REPLACE_TYPE_7      = 0x47, /* Replace Short Message Type 7 */

    VM_SMS_PID_RETURN_CALL_MSG     = 0x5F, /* Return Call Message */
    VM_SMS_PID_ANSI_136_RDATA      = 0x7C, /* ANSI-136 R-DATA */
    VM_SMS_PID_ME_DOWNLOAD         = 0x7D, /* ME Data Download */
    VM_SMS_PID_ME_DE_PERSONAL      = 0x7E, /* ME De-personalization Short Message */
    VM_SMS_PID_SIM_DOWNLOAD        = 0x7F, /* (U)SIM Data Download */

    VM_SMS_PID_RESERVED
} vm_sms_pid_enum;


/* SMS Action Type */
typedef enum
{
    VM_SMS_ACTION_NONE,
    VM_SMS_ACTION_SEND,                             /*发送短信操作*/
    VM_SMS_ACTION_READ,                            /*读取短信操作*/
    VM_SMS_ACTION_DELETE,                        /*删除短信操作*/
    VM_SMS_ACTION_SAVE,                           /*添加新短信操作*/
    VM_SMS_ACTION_UPDATE,                      /*修改短信操作*/
    VM_SMS_ACTION_COPY,                          /*复制短信操作*/
    VM_SMS_ACTION_MOVE,                         /*移动短信操作*/
    VM_SMS_ACTION_QUERY,                       /*查询短信操作*/
    VM_SMS_ACTION_CHANGE_STATUS,      /*改变短信状态操作*/
    VM_SMS_ACTION_MOVE_TO_ARCHIVE,
    VM_SMS_ACTION_GET_CONTENT,         /*得到短信内容操作*/
    VM_SMS_ACTION_GET_SIM_NUM,        /*得到sim卡id操作*/
    VM_SMS_ACTION_GET_SC_ADDR
} vm_sms_action_enum;


/* SMS 返回结果类型*/
typedef enum
{
    VM_SMS_CAUSE_NO_ERROR = 0,

    VM_SMS_CAUSE_ME_FAILURE        = 300,
    VM_SMS_CAUSE_OP_NOT_ALLOWED    = 302,
    VM_SMS_CAUSE_OP_NOT_SUPPORTED  = 303,
    VM_SMS_CAUSE_INVALID_PDU_PARA  = 304,
    VM_SMS_CAUSE_INVALID_TEXT_PARA = 305,
    VM_SMS_CAUSE_SIM_NOT_INSERTED  = 310,
    VM_SMS_CAUSE_SIM_FAILURE       = 313,
    VM_SMS_CAUSE_MEMORY_FAILURE    = 320,
    VM_SMS_CAUSE_INVALID_MEM_INDEX = 321,
    VM_SMS_CAUSE_MEM_FULL          = 322,
    VM_SMS_CAUSE_SCA_UNKNOWN       = 330,

    /* MMI Defined Error Codes */
    VM_SMS_CAUSE_NOT_READY         = 341,               /*短信系统未就绪*/
    VM_SMS_CAUSE_SEND_BUSY,                                 /*正在发送短信*/
    VM_SMS_CAUSE_SEND_ABORT,
    VM_SMS_CAUSE_MEM_INSUFFICIENT,                       /*短信内存不足*/
    VM_SMS_CAUSE_DATA_INVALID,                            /*无效数据*/
    VM_SMS_CAUSE_DATA_EXCEED,                          /*数据过长*/
    VM_SMS_CAUSE_NUMBER_EMPTY,                         /*接收方号码为空*/
    VM_SMS_CAUSE_NUMBER_INVALID,                      /*接收方号码无效*/
    VM_SMS_CAUSE_SC_EMPTY,                              /*短信中心号码为空*/
    VM_SMS_CAUSE_SC_INVALID,                            /*短信中心号码无效*/
    VM_SMS_CAUSE_FDL_FAIL,
    VM_SMS_CAUSE_AT_CONFLICT,
    VM_SMS_CAUSE_OP_CONFLICT,
    VM_SMS_CAUSE_EMAIL_NO_SPACE,
    VM_SMS_CAUSE_FS_ERROR,

    VM_SMS_CAUSE_UNKNOWN_ERROR     = 500
} vm_sms_cause_enum;

/* SMS 参数标志*/
typedef enum
{
    VM_SMS_PARA_NONE           = 0x00000000,

    VM_SMS_PARA_NUM            = 0x00000001,
    VM_SMS_PARA_SCA            = 0x00000002,
    VM_SMS_PARA_PID            = 0x00000004,
    VM_SMS_PARA_DCS            = 0x00000008,
    VM_SMS_PARA_VP             = 0x00000010,
    VM_SMS_PARA_STATUS_REPORT  = 0x00000020,
    VM_SMS_PARA_REPLY_PATH     = 0x00000040,
    VM_SMS_PARA_PORT           = 0x00000080,
    VM_SMS_PARA_CLASS          = 0x00000100,
    VM_SMS_PARA_MMS            = 0x00000200,
    VM_SMS_PARA_FO             = 0x00000400,

    VM_SMS_PARA_STATUS         = 0x00000800,
    VM_SMS_PARA_SIM_ID         = 0x00001000,
    VM_SMS_PARA_STORAGE_TYPE   = 0x00002000,
    VM_SMS_PARA_TIMESTAMP      = 0x00004000,

    VM_SMS_PARA_CONTENT_EMS    = 0x00008000,
    VM_SMS_PARA_CONTENT_BUFF   = 0x00010000,
    VM_SMS_PARA_CONTENT_FILE   = 0x00020000
} vm_sms_para_enum;



/* SMS 排序类型*/
typedef enum
{
    VM_SMS_SORT_NONE,
    VM_SMS_SORT_TIMESTAMP,            /*按时间排序*/
    VM_SMS_SORT_MSG_TYPE,              /*按消息类型排序*/
    VM_SMS_SORT_STORAGE_TYPE,      /*按存储类型排序*/
    VM_SMS_SORT_NUMBER,                 /*按号码排序*/
    VM_SMS_SORT_CONTENT,               /*按内容排序*/
    VM_SMS_SORT_PID,                        /*按协议标识排序*/
    VM_SMS_SORT_SIM_ID                    /*按sim卡号排序*/

} vm_sms_sort_enum;


/* SMS 排序顺序*/
typedef enum
{
    VM_SMS_ORDER_DEFAULT,              /*默认排序*/
    VM_SMS_ORDER_ASC,                    /*按升序排序*/
    VM_SMS_ORDER_DESC                  /*按降序排序*/
} vm_sms_order_enum;


/* SMS事件类型*/
typedef enum
{

    VM_EVT_ID_SMS_NEW_MSG

} vm_sms_event_enum;


/* SMS 操作回调函数数据结构 */
typedef struct
{
    VMINT  result;                       /*1--成功；0--失败*/
    vm_sms_cause_enum cause;
    vm_sms_action_enum action;
    void *action_data;
    void *user_data;
} vm_sms_callback_t;

/* 消息时间结构*/
typedef struct
{
     VMINT event_id;
     VMINT size;
     void * user_data;
     void *event_info;
} vm_sms_event_t;


/*读取的消息数据结构 */
typedef struct
{
    VMINT8 number[(VM_SMS_MAX_ADDR_LEN + 1)*2 ];
    vm_sms_status_enum status;
    vm_sms_mti_enum mti;
    /* TP-Status, for Status Report */
    VMUINT8 tp_st;
    vm_sms_folder_enum folder_id;

    vm_sms_para_enum para_flag;

    vm_sms_storage_enum storage_type;
    vm_sms_sim_enum sim_id;
    vm_time_t  timestamp;
	
    VMINT8 sc_address[(VM_SMS_MAX_ADDR_LEN + 1)*2];
    vm_sms_pid_enum pid;
    vm_sms_vp_enum vp;

    VMINT status_report;
    VMINT  reply_path;

    VMUINT16 src_port;
    VMUINT16 dest_port;
    vm_sms_dcs_enum dcs;
    vm_sms_class_enum msg_class;
    VMUINT16 content_buff_size;
    VMINT8 *content_buff;
    VMINT8 *content_file_path;

    void *content_ems;
} vm_sms_msg_data_t;

/*增加消息数据结构 */
typedef struct
{
	vm_sms_status_enum status;
	vm_sms_sim_enum sim_id;
	vm_sms_storage_enum storage_type;
	vm_time_t  timestamp;
	VMUINT16 content_size;
	VMINT8 *content;
	VMINT8 number[(VM_SMS_MAX_ADDR_LEN + 1)*2 ];
} vm_sms_add_msg_data_t;


/* 查询短信id数据结构*/
typedef struct
{
    vm_sms_sort_enum sort_flag;
    vm_sms_order_enum order_flag;
    vm_sms_status_enum status;  /**/
  
} vm_sms_query_t;


/* 新消息数据结构 */
typedef struct
{
    VMUINT16 msg_id;
    VMUINT16 dest_port;                                                    /*目标端口*/
    VMUINT16 src_port;                                                      /*源端口*/
    VMUINT16 message_len;                                              /*消息长度*/
    VMUINT16 ref;                                                               /* concat. message reference */
    VMUINT8 number[VM_SMS_MAX_ADDR_LEN + 1];           /*发送方号码*/
    VMUINT8 sc_number[VM_SMS_MAX_ADDR_LEN + 1];
    vm_time_t timestamp;                                                       /*服务中心时间戳*/
    VMUINT8 total_seg;                                                       /*消息分段总数*/
    VMUINT8 seg;                                                                /*第几个分段*/
    VMUINT8 dcs;                                                                  /*编码方式*/
    VMUINT8 mti;                                                                 /*消息类型指示*/
    VMUINT8 pid;                                                                  /*协议标识*/
    VMUINT8 fo;
    VMUINT8 data[1];                                                           /*数据*/
    vm_sms_sim_enum sim_id;                                            /*sim卡id*/
    vm_sms_storage_enum storage_type;                            /*存储位置*/
} vm_sms_new_msg_t;


/*读取某条消息回调函数数据结构 */
typedef struct
{
    vm_sms_msg_data_t *msg_data;
} vm_sms_read_msg_cb_t;


/* 增加某条消息回调函数数据结构*/
typedef struct
{
    VMUINT16 msg_id;
} vm_sms_save_msg_cb_t;


/*删除某条消息回调函数数据结构 */
typedef struct
{
    void *dummy;
} vm_sms_delete_msg_cb_t;


/* 删除列表中的消息 回调函数数据结构*/
typedef struct
{
     VMUINT16 deleted_msg_num;
} vm_sms_delete_msg_list_cb_t;



/* 查询短信数目回调函数结构*/
typedef struct
{
    VMUINT16 msg_num;                    /*短信数目*/
    VMUINT16 *msg_id_list;               /*短信id列表*/
} vm_sms_query_msg_cb_t;


/*新消息打扰事件回调函数结构*/
typedef struct
{
    VMUINT16  msg_id;                      /*消息id*/
    VMUINT8  *content;
    void *msg_data;                          /* 新消息数据(vm_sms_new_msg_t 结构)*/
} vm_sms_event_new_sms_t;

/* 获取短信中心号码回调函数结构*/
typedef struct
{
     VMINT8 sc_addr[VM_SMS_MAX_ADDR_LEN + 1];
} vm_sms_get_sc_addr_cb_t;

/**
 *	短信管理回调函数的类型定义。
 *
 *    @param callback_data   操作结果
 *                 callback_data->result = 1,操作成功，allback_data->result = 0，操作失败。
 *                 callback_data->cause 操作结果描述，参见vm_sms_cause_enum。
 *                 callback_data->action操作类型，参见vm_sms_action_enum。
 *                 callback_data->action_data操作返回数据，因操作类型而不同。
 *                 callback_data->user_data用户传入的数据。
 */
typedef void(*VmSmsCallbackFunc)(vm_sms_callback_t* callback_data);


/**
 *	注册短信事件回调函数的类型定义。
 *
 *    @param vm_sms_event_t   操作结果
 *                 event_data->event_id, 注册的短信事件id。
 *                 event_data->size 返回结果大小。
 *                 event_data->user_data 用户传入的数据。
 *                 event_data->event_info 返回的数据，因注册不同的事件返回的数据结构不同。
 *                 如注册消息为VM_EVT_ID_SMS_NEW_MSG，则其结构为vm_sms_event_new_sms_t.
 */
typedef VMINT(*VmSmsEventFunc)(vm_sms_event_t* event_data);


/**
 * 根据短信id读取短信内容，短信内容通过回调函数返回。
 * 
 * @param   msg_id  短信的id(>=0)。
 * @param   change_status  读取短信时改变短状态(0--不改变状态，!0改变状态)。
 * @param   msg_data   消息的内容及其他信息。
 * @param   callback_func 用户的回调函数。
 * @param   user_data 
 *
 * @return    请求是否成功，值参见vm_sms_error_enum。
 */
VMINT vm_sms_read_msg(VMUINT16 msg_id, VMINT change_status,  vm_sms_msg_data_t* msg_data, 
	            VmSmsCallbackFunc  callback_func, void* user_data);


/**
 * 增加一条新短信，结果由回调函数返回。
 * 
 * @param   msg_data 用户要保存的数据。
 * @param   callback_func 用户的回调函数。
 * @param   user_data 
 *
 * @return     请求是否成功，值参见vm_sms_error_enum。
 */
VMINT vm_sms_add_msg(vm_sms_add_msg_data_t * msg_data, VmSmsCallbackFunc callback_func, void* user_data);


/**
 * 删除某条短信，结果由回调函数返回。
 * 
 * @param   msg_id  短信的id(>=0)。
 * @param   callback_func 用户的回调函数。
 * @param   user_data 
 *
 * @return      请求是否成功，值参见vm_sms_error_enum。
 */
VMINT vm_sms_delete_msg(VMUINT16 msg_id, VmSmsCallbackFunc callback_func,  void* user_data);


/**
 * 删除某文件夹上或所有文件夹中的短信。
 * 
 * @param   box_type    短信文件夹列表，其值可为vm_sms_box_enum中的组合。
 * @param  sim_id  值参见vm_sms_sim_enum。
 * @param   callback_func  用户回调函数。
 * @param   user_data    
 *
 * @return     请求是否成功，值参见vm_sms_error_enum。
 */
VMINT vm_sms_delete_msg_list(vm_sms_box_enum box_type,  vm_sms_sim_enum sim_id, VmSmsCallbackFunc callback_func,  void* user_data);


/**
 * 获取某个文件夹或所有文件夹的msg id 。
 * 
 * @param   query_data 要获取的文件夹中的msg id及排序方式。
 * @param   callback_func 用户的回调函数。
 * @param   user_data
 * 
 * @return    请求是否成功，值参见vm_sms_error_enum。
 */
VMINT vm_sms_get_msg_id_list(vm_sms_query_t* query_data,  VmSmsCallbackFunc callback_func,  void* user_data);


/**
 * 得到某文件夹上某条短信的id。
 * 
 * @param   box_type 短信文件夹列表。
 * @param   msg_index  文件夹上某条短信的索引 (>=0)(会因删除某文件夹中
 *            的一条短信而改变此文件上其他短信的index,但msg id不会改变，某文件夹增加一条短信
 *，其index随msg id的大小而变  )。例如:msg_id_list[index]=msg_id
 *                   msg_id_list[0]=0                                                       msg_id_list[0]=0                                            msg_id_list[0]=0
 *                   msg_id_list[1]=1   删除msg id=2的短信后     msg_id_list[1]=1    增加一条短信后  msg_id_list[1]=1  
 *                   msg_id_list[2]=2                                                      msg_id_list[2]=3                                             msg_id_list[2]=2   
 *                   msg_id_list[3]=3                                                                                                                           msg_id_list[3]=3
 *          
 *
 * @return    返回msg id (>=0,msg id;返回-1,不存在对应的msg id)。
 */
VMINT16 vm_sms_get_msg_id(vm_sms_box_enum box_type, VMUINT16 msg_index);


/**
 * 得到某文件夹上存储短信的的总条数。
 * 
 * @param   box_type  短信文件夹列表，其值为vm_sms_box_enum中的某一个。
 *
 * @return    返回短信的条数。
 */
VMINT16 vm_sms_get_box_size(vm_sms_box_enum box_type);

/**
 * 得到短信中心号码(异步)。
 * 
 * @param   sim_id     sim卡id。
 * @param   callback_func      用户的回调函数。
 * @param   user_data     
 *
 * @return    请求是否成功，值参见vm_sms_error_enum。
 */
VMINT vm_sms_get_sc_address( vm_sms_sim_enum sim_id, VmSmsCallbackFunc callback_func, void* user_data);

/**
 * 注册短信事件。
 * 
 * @param   event_id  事件id。
 * @param   event_func 处理事件的函数。
 * @param   user_data 
 *
 * @return   请求是否成功，值参见vm_sms_error_enum。
 */
VMINT vm_sms_set_interrupt_event_handler(vm_sms_event_enum event_id,  VmSmsEventFunc event_func,  void* user_data);


/**
 * 清除短信事件。
 * 
 * @param   event_id  事件id。
 * @param   event_func 处理事件的函数。
 * @param   user_data  
 *
 * @return   请求是否成功，值参见vm_sms_error_enum。
 */
VMINT vm_sms_clear_interrupt_event_handler(vm_sms_event_enum event_id,  VmSmsEventFunc event_func,  void* user_data);

/**
 * 得到短信中心号码(同步)。
 * 
 * @param   vm_sc_addr        保存短信中心号码。
 * @param   sim_id     sim卡id。
 *
 * @return    值VM_SMS_REQ_ERROR--支持同步方式， 请求错误；VM_SMS_SUPPORT_SYN_SCA--支持同步方式,请求成功；
 *                                 VM_SMS_NOT_SUPPORT_SYN_SCA--不支持同步方式,请求失败。
 */
VMINT vm_sms_get_sc_address_syn(vm_sms_get_sc_addr_cb_t * vm_sc_addr,  vm_sms_sim_enum sim_id);

#ifdef __cplusplus
}
#endif

#endif

