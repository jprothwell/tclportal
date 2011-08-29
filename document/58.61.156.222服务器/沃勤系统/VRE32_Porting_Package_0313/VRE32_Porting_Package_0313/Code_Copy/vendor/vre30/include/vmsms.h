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
    VM_SMS_REQ_ERROR = -1,                       /*���Ų����������*/
    VM_SMS_REQ_NO_ERROR,                    /*���Ų�������ɹ�*/
    VM_SMS_REQ_CALLBACK_REGISTERED
} vm_sms_error_enum;


typedef enum
{
    VM_SMS_BOX_INBOX        = 0x01,                   /*�ռ���*/
    VM_SMS_BOX_OUTBOX       = 0x02,                 /*�ѷ��Ͷ����ļ���*/
    VM_SMS_BOX_DRAFTS       = 0x04,                   /*�ݸ���*/
    VM_SMS_BOX_UNSENT       = 0x08,                   /*�����Ͷ����ļ���*/
    VM_SMS_BOX_SIM          = 0x10,                 /*sim��*/
    VM_SMS_BOX_ARCHIVE      = 0x20,
    
    VM_SMS_BOX_RESERVED     = 0x40		 /*��֧�ֵ�״̬*/
  
} vm_sms_box_enum;

/* Message Folder Type 111*/
typedef enum
{
    VM_SMS_FOLDER_DEFAULT,
    VM_SMS_FOLDER_ARCHIVE
} vm_sms_folder_enum;

/* ���Ŵ洢״̬*/
typedef enum
{

    VM_SMS_STATUS_UNREAD       = 0x01,        /*δ��״̬ */
    VM_SMS_STATUS_READ         = 0x02,          /*�Ѷ�״̬*/
    VM_SMS_STATUS_SENT         = 0x04,          /*�ѷ���״̬*/
    VM_SMS_STATUS_UNSENT       = 0x08,       /*����״̬(������)*/
    VM_SMS_STATUS_DRAFT        = 0x10,        /*д�ݸ�״̬*/
    
    VM_SMS_STATUS_UNSUPPORTED  = 0x20   /*��֧�ֵ�״̬*/
} vm_sms_status_enum;


/* ��Ϣ����ָʾ*/
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


/*���Ŵ洢λ������*/
typedef enum
{
    VM_SMS_STORAGE_ME,              /*�洢���ֻ���*/
    VM_SMS_STORAGE_SIM,             /*�洢��sim����*/

    VM_SMS_STORAGE_UNSPECIFIC
} vm_sms_storage_enum;

typedef enum
{
    VM_MMI_SIM_1 = 0x0001,
    VM_MMI_SIM_2 = 0x0002
  }vm_sim_enum;

/* �������� */
typedef enum
{
    VM_MMI_GSM = 0x0100
  } vm_network_enum;

/* sim������ */
typedef enum
{
    VM_SMS_SIM_1 = VM_MMI_GSM | VM_MMI_SIM_1,   /* sim1������ */
    VM_SMS_SIM_2 = VM_MMI_GSM | VM_MMI_SIM_2,  /* sim2������ */
    VM_SMS_TOTAL
} vm_sms_sim_enum;


/* ���ż���*/
typedef enum
{
   VM_SMS_CLASS_0  = 0x00,    /*����Ϣֱ����ʾ�û��նˣ����洢*/
   VM_SMS_CLASS_1  = 0x01,   /*����Ϣ�洢���ֻ��ڴ���*/
   VM_SMS_CLASS_2  = 0x02,  /*����Ϣ�洢��sim���ϣ���ֹ���䵽�ն�*/
   VM_SMS_CLASS_3  = 0x03    /*����Ϣ�洢���û��豸��(TE)*/
} vm_sms_class_enum;


/* ������Ч��*/
typedef enum
{
    VM_SMS_VP_1_HR     = 11,              /* ������Ч��1Сʱ*/
    VM_SMS_VP_6_HR     = 71,              /* ������Ч��6Сʱ*/
    VM_SMS_VP_12_HR    = 143,           /* ������Ч��12Сʱ*/
    VM_SMS_VP_24_HR    = 167,           /* ������Ч��24Сʱ*/
    VM_SMS_VP_72_HR    = 169,           /* ������Ч��72Сʱ*/
    VM_SMS_VP_1_WEEK   = 173,         /* ������Ч��һ��*/
    VM_SMS_VP_MAX      = 255
} vm_sms_vp_enum;


/* SMS���뷽ʽ*/
typedef enum
{
    VM_SMS_DCS_7BIT        = 0x00, /* GSM 7 bit default alphabet */
    VM_SMS_DCS_8BIT        = 0x04, /* 8 bit data */
    VM_SMS_DCS_UCS2        = 0x08, /* UCS2 (16bit) */
    VM_SMS_DCS_RESERVED    = 0x0c
} vm_sms_dcs_enum;


/* Э���ʶ*/
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
    VM_SMS_ACTION_SEND,                             /*���Ͷ��Ų���*/
    VM_SMS_ACTION_READ,                            /*��ȡ���Ų���*/
    VM_SMS_ACTION_DELETE,                        /*ɾ�����Ų���*/
    VM_SMS_ACTION_SAVE,                           /*����¶��Ų���*/
    VM_SMS_ACTION_UPDATE,                      /*�޸Ķ��Ų���*/
    VM_SMS_ACTION_COPY,                          /*���ƶ��Ų���*/
    VM_SMS_ACTION_MOVE,                         /*�ƶ����Ų���*/
    VM_SMS_ACTION_QUERY,                       /*��ѯ���Ų���*/
    VM_SMS_ACTION_CHANGE_STATUS,      /*�ı����״̬����*/
    VM_SMS_ACTION_MOVE_TO_ARCHIVE,
    VM_SMS_ACTION_GET_CONTENT,         /*�õ��������ݲ���*/
    VM_SMS_ACTION_GET_SIM_NUM,        /*�õ�sim��id����*/
    VM_SMS_ACTION_GET_SC_ADDR
} vm_sms_action_enum;


/* SMS ���ؽ������*/
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
    VM_SMS_CAUSE_NOT_READY         = 341,               /*����ϵͳδ����*/
    VM_SMS_CAUSE_SEND_BUSY,                                 /*���ڷ��Ͷ���*/
    VM_SMS_CAUSE_SEND_ABORT,
    VM_SMS_CAUSE_MEM_INSUFFICIENT,                       /*�����ڴ治��*/
    VM_SMS_CAUSE_DATA_INVALID,                            /*��Ч����*/
    VM_SMS_CAUSE_DATA_EXCEED,                          /*���ݹ���*/
    VM_SMS_CAUSE_NUMBER_EMPTY,                         /*���շ�����Ϊ��*/
    VM_SMS_CAUSE_NUMBER_INVALID,                      /*���շ�������Ч*/
    VM_SMS_CAUSE_SC_EMPTY,                              /*�������ĺ���Ϊ��*/
    VM_SMS_CAUSE_SC_INVALID,                            /*�������ĺ�����Ч*/
    VM_SMS_CAUSE_FDL_FAIL,
    VM_SMS_CAUSE_AT_CONFLICT,
    VM_SMS_CAUSE_OP_CONFLICT,
    VM_SMS_CAUSE_EMAIL_NO_SPACE,
    VM_SMS_CAUSE_FS_ERROR,

    VM_SMS_CAUSE_UNKNOWN_ERROR     = 500
} vm_sms_cause_enum;

/* SMS ������־*/
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



/* SMS ��������*/
typedef enum
{
    VM_SMS_SORT_NONE,
    VM_SMS_SORT_TIMESTAMP,            /*��ʱ������*/
    VM_SMS_SORT_MSG_TYPE,              /*����Ϣ��������*/
    VM_SMS_SORT_STORAGE_TYPE,      /*���洢��������*/
    VM_SMS_SORT_NUMBER,                 /*����������*/
    VM_SMS_SORT_CONTENT,               /*����������*/
    VM_SMS_SORT_PID,                        /*��Э���ʶ����*/
    VM_SMS_SORT_SIM_ID                    /*��sim��������*/

} vm_sms_sort_enum;


/* SMS ����˳��*/
typedef enum
{
    VM_SMS_ORDER_DEFAULT,              /*Ĭ������*/
    VM_SMS_ORDER_ASC,                    /*����������*/
    VM_SMS_ORDER_DESC                  /*����������*/
} vm_sms_order_enum;


/* SMS�¼�����*/
typedef enum
{

    VM_EVT_ID_SMS_NEW_MSG

} vm_sms_event_enum;


/* SMS �����ص��������ݽṹ */
typedef struct
{
    VMINT  result;                       /*1--�ɹ���0--ʧ��*/
    vm_sms_cause_enum cause;
    vm_sms_action_enum action;
    void *action_data;
    void *user_data;
} vm_sms_callback_t;

/* ��Ϣʱ��ṹ*/
typedef struct
{
     VMINT event_id;
     VMINT size;
     void * user_data;
     void *event_info;
} vm_sms_event_t;


/*��ȡ����Ϣ���ݽṹ */
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

/*������Ϣ���ݽṹ */
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


/* ��ѯ����id���ݽṹ*/
typedef struct
{
    vm_sms_sort_enum sort_flag;
    vm_sms_order_enum order_flag;
    vm_sms_status_enum status;  /**/
  
} vm_sms_query_t;


/* ����Ϣ���ݽṹ */
typedef struct
{
    VMUINT16 msg_id;
    VMUINT16 dest_port;                                                    /*Ŀ��˿�*/
    VMUINT16 src_port;                                                      /*Դ�˿�*/
    VMUINT16 message_len;                                              /*��Ϣ����*/
    VMUINT16 ref;                                                               /* concat. message reference */
    VMUINT8 number[VM_SMS_MAX_ADDR_LEN + 1];           /*���ͷ�����*/
    VMUINT8 sc_number[VM_SMS_MAX_ADDR_LEN + 1];
    vm_time_t timestamp;                                                       /*��������ʱ���*/
    VMUINT8 total_seg;                                                       /*��Ϣ�ֶ�����*/
    VMUINT8 seg;                                                                /*�ڼ����ֶ�*/
    VMUINT8 dcs;                                                                  /*���뷽ʽ*/
    VMUINT8 mti;                                                                 /*��Ϣ����ָʾ*/
    VMUINT8 pid;                                                                  /*Э���ʶ*/
    VMUINT8 fo;
    VMUINT8 data[1];                                                           /*����*/
    vm_sms_sim_enum sim_id;                                            /*sim��id*/
    vm_sms_storage_enum storage_type;                            /*�洢λ��*/
} vm_sms_new_msg_t;


/*��ȡĳ����Ϣ�ص��������ݽṹ */
typedef struct
{
    vm_sms_msg_data_t *msg_data;
} vm_sms_read_msg_cb_t;


/* ����ĳ����Ϣ�ص��������ݽṹ*/
typedef struct
{
    VMUINT16 msg_id;
} vm_sms_save_msg_cb_t;


/*ɾ��ĳ����Ϣ�ص��������ݽṹ */
typedef struct
{
    void *dummy;
} vm_sms_delete_msg_cb_t;


/* ɾ���б��е���Ϣ �ص��������ݽṹ*/
typedef struct
{
     VMUINT16 deleted_msg_num;
} vm_sms_delete_msg_list_cb_t;



/* ��ѯ������Ŀ�ص������ṹ*/
typedef struct
{
    VMUINT16 msg_num;                    /*������Ŀ*/
    VMUINT16 *msg_id_list;               /*����id�б�*/
} vm_sms_query_msg_cb_t;


/*����Ϣ�����¼��ص������ṹ*/
typedef struct
{
    VMUINT16  msg_id;                      /*��Ϣid*/
    VMUINT8  *content;
    void *msg_data;                          /* ����Ϣ����(vm_sms_new_msg_t �ṹ)*/
} vm_sms_event_new_sms_t;

/* ��ȡ�������ĺ���ص������ṹ*/
typedef struct
{
     VMINT8 sc_addr[VM_SMS_MAX_ADDR_LEN + 1];
} vm_sms_get_sc_addr_cb_t;

/**
 *	���Ź���ص����������Ͷ��塣
 *
 *    @param callback_data   �������
 *                 callback_data->result = 1,�����ɹ���allback_data->result = 0������ʧ�ܡ�
 *                 callback_data->cause ��������������μ�vm_sms_cause_enum��
 *                 callback_data->action�������ͣ��μ�vm_sms_action_enum��
 *                 callback_data->action_data�����������ݣ���������Ͷ���ͬ��
 *                 callback_data->user_data�û���������ݡ�
 */
typedef void(*VmSmsCallbackFunc)(vm_sms_callback_t* callback_data);


/**
 *	ע������¼��ص����������Ͷ��塣
 *
 *    @param vm_sms_event_t   �������
 *                 event_data->event_id, ע��Ķ����¼�id��
 *                 event_data->size ���ؽ����С��
 *                 event_data->user_data �û���������ݡ�
 *                 event_data->event_info ���ص����ݣ���ע�᲻ͬ���¼����ص����ݽṹ��ͬ��
 *                 ��ע����ϢΪVM_EVT_ID_SMS_NEW_MSG������ṹΪvm_sms_event_new_sms_t.
 */
typedef VMINT(*VmSmsEventFunc)(vm_sms_event_t* event_data);


/**
 * ���ݶ���id��ȡ�������ݣ���������ͨ���ص��������ء�
 * 
 * @param   msg_id  ���ŵ�id(>=0)��
 * @param   change_status  ��ȡ����ʱ�ı��״̬(0--���ı�״̬��!0�ı�״̬)��
 * @param   msg_data   ��Ϣ�����ݼ�������Ϣ��
 * @param   callback_func �û��Ļص�������
 * @param   user_data 
 *
 * @return    �����Ƿ�ɹ���ֵ�μ�vm_sms_error_enum��
 */
VMINT vm_sms_read_msg(VMUINT16 msg_id, VMINT change_status,  vm_sms_msg_data_t* msg_data, 
	            VmSmsCallbackFunc  callback_func, void* user_data);


/**
 * ����һ���¶��ţ�����ɻص��������ء�
 * 
 * @param   msg_data �û�Ҫ��������ݡ�
 * @param   callback_func �û��Ļص�������
 * @param   user_data 
 *
 * @return     �����Ƿ�ɹ���ֵ�μ�vm_sms_error_enum��
 */
VMINT vm_sms_add_msg(vm_sms_add_msg_data_t * msg_data, VmSmsCallbackFunc callback_func, void* user_data);


/**
 * ɾ��ĳ�����ţ�����ɻص��������ء�
 * 
 * @param   msg_id  ���ŵ�id(>=0)��
 * @param   callback_func �û��Ļص�������
 * @param   user_data 
 *
 * @return      �����Ƿ�ɹ���ֵ�μ�vm_sms_error_enum��
 */
VMINT vm_sms_delete_msg(VMUINT16 msg_id, VmSmsCallbackFunc callback_func,  void* user_data);


/**
 * ɾ��ĳ�ļ����ϻ������ļ����еĶ��š�
 * 
 * @param   box_type    �����ļ����б���ֵ��Ϊvm_sms_box_enum�е���ϡ�
 * @param  sim_id  ֵ�μ�vm_sms_sim_enum��
 * @param   callback_func  �û��ص�������
 * @param   user_data    
 *
 * @return     �����Ƿ�ɹ���ֵ�μ�vm_sms_error_enum��
 */
VMINT vm_sms_delete_msg_list(vm_sms_box_enum box_type,  vm_sms_sim_enum sim_id, VmSmsCallbackFunc callback_func,  void* user_data);


/**
 * ��ȡĳ���ļ��л������ļ��е�msg id ��
 * 
 * @param   query_data Ҫ��ȡ���ļ����е�msg id������ʽ��
 * @param   callback_func �û��Ļص�������
 * @param   user_data
 * 
 * @return    �����Ƿ�ɹ���ֵ�μ�vm_sms_error_enum��
 */
VMINT vm_sms_get_msg_id_list(vm_sms_query_t* query_data,  VmSmsCallbackFunc callback_func,  void* user_data);


/**
 * �õ�ĳ�ļ�����ĳ�����ŵ�id��
 * 
 * @param   box_type �����ļ����б�
 * @param   msg_index  �ļ�����ĳ�����ŵ����� (>=0)(����ɾ��ĳ�ļ�����
 *            ��һ�����Ŷ��ı���ļ����������ŵ�index,��msg id����ı䣬ĳ�ļ�������һ������
 *����index��msg id�Ĵ�С����  )������:msg_id_list[index]=msg_id
 *                   msg_id_list[0]=0                                                       msg_id_list[0]=0                                            msg_id_list[0]=0
 *                   msg_id_list[1]=1   ɾ��msg id=2�Ķ��ź�     msg_id_list[1]=1    ����һ�����ź�  msg_id_list[1]=1  
 *                   msg_id_list[2]=2                                                      msg_id_list[2]=3                                             msg_id_list[2]=2   
 *                   msg_id_list[3]=3                                                                                                                           msg_id_list[3]=3
 *          
 *
 * @return    ����msg id (>=0,msg id;����-1,�����ڶ�Ӧ��msg id)��
 */
VMINT16 vm_sms_get_msg_id(vm_sms_box_enum box_type, VMUINT16 msg_index);


/**
 * �õ�ĳ�ļ����ϴ洢���ŵĵ���������
 * 
 * @param   box_type  �����ļ����б���ֵΪvm_sms_box_enum�е�ĳһ����
 *
 * @return    ���ض��ŵ�������
 */
VMINT16 vm_sms_get_box_size(vm_sms_box_enum box_type);

/**
 * �õ��������ĺ���(�첽)��
 * 
 * @param   sim_id     sim��id��
 * @param   callback_func      �û��Ļص�������
 * @param   user_data     
 *
 * @return    �����Ƿ�ɹ���ֵ�μ�vm_sms_error_enum��
 */
VMINT vm_sms_get_sc_address( vm_sms_sim_enum sim_id, VmSmsCallbackFunc callback_func, void* user_data);

/**
 * ע������¼���
 * 
 * @param   event_id  �¼�id��
 * @param   event_func �����¼��ĺ�����
 * @param   user_data 
 *
 * @return   �����Ƿ�ɹ���ֵ�μ�vm_sms_error_enum��
 */
VMINT vm_sms_set_interrupt_event_handler(vm_sms_event_enum event_id,  VmSmsEventFunc event_func,  void* user_data);


/**
 * ��������¼���
 * 
 * @param   event_id  �¼�id��
 * @param   event_func �����¼��ĺ�����
 * @param   user_data  
 *
 * @return   �����Ƿ�ɹ���ֵ�μ�vm_sms_error_enum��
 */
VMINT vm_sms_clear_interrupt_event_handler(vm_sms_event_enum event_id,  VmSmsEventFunc event_func,  void* user_data);

/**
 * �õ��������ĺ���(ͬ��)��
 * 
 * @param   vm_sc_addr        ����������ĺ��롣
 * @param   sim_id     sim��id��
 *
 * @return    ֵVM_SMS_REQ_ERROR--֧��ͬ����ʽ�� �������VM_SMS_SUPPORT_SYN_SCA--֧��ͬ����ʽ,����ɹ���
 *                                 VM_SMS_NOT_SUPPORT_SYN_SCA--��֧��ͬ����ʽ,����ʧ�ܡ�
 */
VMINT vm_sms_get_sc_address_syn(vm_sms_get_sc_addr_cb_t * vm_sc_addr,  vm_sms_sim_enum sim_id);

#ifdef __cplusplus
}
#endif

#endif

