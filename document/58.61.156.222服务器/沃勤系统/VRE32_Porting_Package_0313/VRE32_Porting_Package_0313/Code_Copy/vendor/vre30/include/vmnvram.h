#ifndef VMNVRAM_H_
#define VMNVRAM_H_

#include "vmsys.h"
#include "vmglobalver.h"
#ifdef __cplusplus
extern "C" {
#endif

#define VM_NVRAM_RW_ERROR -1
/**
 *	��Կ(�洢)���ݳ���
 */
#define PK_CONTENT_LEN		(200)
/**
 *	�洢��һ��NVRAM��¼�еĹ�Կ����
 */
#define ROOT_PK_LIST_SIZE   (8)
/**
 *	�洢��һ��NVRAM��¼�е�Ӧ�ú���������
 */
#define BAN_LIST_SIZE		(256)

/**
 *     ��Կռ�ÿռ��С
 */
#define NVRAM_PKEY_LIST_NUM								(3648)

/**
 * NVRAM��洢����Ӫ�̱�ʶ��
 * NVRAM_OPERATOR_CMCC Ϊ�й��ƶ���
 * NVRAM_OPERATOR_UNI Ϊ�й���ͨ��
 */
#define NVRAM_OPERATOR_CMCC				(1)
#define NVRAM_OPERATOR_UNI				(2)

/**
 *	�洢��NVRAM��¼��һ����Կ�Ľṹ
 */
typedef struct 
{
	VMINT pkey_index;						/*��Կ������*/
	VMINT8 pkey_content[PK_CONTENT_LEN];	/*��Կ����*/
	vm_time_t pkey_time_stamp;
} vm_pkey_t;

/**
 *	�洢��NVRAMһ����¼������洢�˸���Կ
 *	��Ҫ����NVRAM��¼��
 */
typedef struct 
{
	vm_pkey_t pkey_item[ROOT_PK_LIST_SIZE];
} vm_nvram_root_pkey_list_t;

/**
 *	�洢��NVRAMһ����¼������洢Ӧ�ó��������
 *	��Ҫһ��NVRAM��¼��
 */
typedef struct 
{
	VMUINT app_ban_item[BAN_LIST_SIZE];
	vm_time_t app_ban_time_stamp;
} vm_nvram_app_ban_list_t;

/**
  *	��NVRAM�ж�ȡָ����¼�ŵĹ�Կ��,һ����Կ��������8����Կ.
  *
  *	@param list_index	��¼��,����ֻ֧��������¼(0����1), ������ֵ�����ش�
  * @param pkey_list   ��Կ����ָ��,�����ȡ�ɹ�,ͨ�����ָ�뷵�ع�Կ��
  *
  *	@return TRUE=��ȡ�ɹ�,FALSE=��ȡʧ��
  */
VMINT vm_nvram_get_pkey_list(VMINT list_index, vm_nvram_root_pkey_list_t * pkey_list);

/**
  *	��NVRAM��д�빫Կ����ָ����¼��,һ����Կ��������8����Կ.
  *
  *	@param list_index	��¼��,����ֻ֧��������¼(0����1), ������ֵ�����ش�
  * @param pkey_list   ��Կ����ָ��,���ô˺���ǰ���뽫ָ��ָ��Կ������
  *
  *	@return TRUE=д��ɹ�,FALSE=д��ʧ��
  */
VMINT vm_nvram_set_pkey_list(VMINT list_index, vm_nvram_root_pkey_list_t * pkey_list);

/**
  *	��NVRAM�ж�ȡӦ�ó����������
  *
  * @param ban_list_ptr   Ӧ�ó������������ָ��,�����ȡ�ɹ�,ͨ�����ָ�뷵�غ�������
  * @return TRUE=��ȡ�ɹ�,FALSE=��ȡʧ��
  */
VMINT vm_nvram_get_ban_list(vm_nvram_app_ban_list_t * ban_list_ptr);

/**
  *	��NVRAM��д��Ӧ�ó����������.
  *
  *   @param ban_list_ptr   Ӧ�ó������������ָ��,���ô˺���ǰ���뽫ָ��ָ�������������
  *
  *	@return TRUE=д��ɹ�,FALSE=д��ʧ��
  */
VMINT vm_nvram_set_ban_list(vm_nvram_app_ban_list_t * ban_list_ptr);

/**
  *	��NVRAM����Ӧ�ó����������,�������洢��ȫ�ֱ���app_ban_list ��.
  *	������ϵͳ����ʱ���ߺ������޸ĺ���øú���
  *
  *	@return TRUE=��ȡ�ɹ�,FALSE=��ȡʧ��
  */
VMINT vm_load_app_ban_list(void);

/**
 *	�ͷ�ȫ�ֱ���app_ban_list(Ӧ�ó����������)
 */
void vm_unload_app_ban_list(void);


VMINT vm_app_in_ban_list(VMUINT app_id);

#define SYM_PERMISSION_LEN 200

typedef enum 
{
	VM_ENTRY_REFUSE = 0,  /*�ӿھܾ�����*/
	VM_ENTRY_ACCEPT = 1   /*�ӿ��������*/
} vm_permission_e;

typedef struct 
{
	VMINT operate_index;  /*��������*/
	vm_permission_e permission;   /*��������*/
} vm_permission_t;

/**
  *	�洢��NVRAMһ����¼������洢ɳ������
  *	��Ҫһ��NVRAM��¼
  *   nvram�нӿ�����б����ݽṹ
  */
typedef struct
{
	VMINT vm_sym_permission_list_len;
	vm_permission_t vm_sym_permission_list[SYM_PERMISSION_LEN];
} vm_nvram_permission_list_t;   

/**
 *	��NVRAM������ϵͳ�ӿ�����б�
 *    @param permission_list_ptr    ϵͳ�ӿ�����б�
 *
 *    @return  TRUE=���óɹ�; FALSE=����ʧ��;
 */
VMINT vm_nvram_set_sym_permission(vm_nvram_permission_list_t * permission_list_ptr);

/**
 *	��NVRAM�ж�ȡϵͳ�ӿ�����б�
 *    @param permission_list_ptr    ϵͳ�ӿ�����б�
 *
 *    @return  TRUE=���óɹ�; FALSE=����ʧ��;
 */
VMINT vm_nvram_get_sym_permission(vm_nvram_permission_list_t * permission_list_ptr);

/**
 *	�ϲ�����б�,����app������б���ϵͳ����б�����ɱ�ǽ���
 *    �õ��ϲ��������б�
 *    @param   app_permission_list  Ӧ�ó���ӿ�����б�,����ʱӦΪ�ǿ�
 *    @param   app_permission_list_len  Ӧ�ó���ӿ�����б���,����ʱ�������0
 *    @param   merge_permission_list   �ϲ��󷵻ص�����б�����ʱӦΪ�ǿ�.
 *    @param   merge_permission_list_len_ptr �ϲ�����б�,����ʱ�������0, ����ϲ��ɹ�����Ϊ����0,����Ϊ0.
 *
 *    @retrun   FALSE=�ϲ�ʧ��, TRUE=�ϲ��ɹ�
 */
VMINT vm_merge_permission(vm_permission_t * app_permission_list, 
							   VMINT app_permission_list_len, 
							   vm_permission_t * merge_permission_list, 
							   VMINT * merge_permission_list_len_ptr);



/**
 *	ϵͳ�������ݽṹ
 */ 
typedef struct
{
	vm_time_t sys_time_stamp[5]; 
	VMINT uid;
	VMINT mobile_phone_id;
} vm_nvram_sysconf_t;

/**
 *	��nvram�õ�ϵͳ����
 *	@param sysconfig_ptr   ָ��ϵͳ�������ݽṹ��ָ�룬����ΪNULL
 *	@return TRUE=�����ɹ� , FALSE=����ʧ��
 */
VMINT vm_get_sysconf(vm_nvram_sysconf_t * sysconfig_ptr);

/**
 *	���üƷ�ͨ�����б�nvram
 *	@param sysconfig_ptr   ָ��ϵͳ�������ݽṹ��ָ�룬����ΪNULL
 *	@return TRUE=�����ɹ� , FALSE=����ʧ��
 */
VMINT vm_set_sysconf(vm_nvram_sysconf_t * sysconfig_ptr);

/********************************************************/
/*********************������AS ���**************/
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
 *	����appstore���õ�nvram
 *	@param appstore_config_ptr   ָ��appstore�������ݽṹ��ָ�룬����ΪNULL
 *	@return TRUE=�����ɹ� , FALSE=����ʧ��
 */
VMINT vm_set_appstore_config(vm_nvram_appstore_config_t * appstore_config_ptr);

/**
 *	��nvram�õ�appstore����
 *	@param appstore_config_ptr   ָ��appstore�������ݽṹ��ָ�룬����ΪNULL
 *	@return TRUE=�����ɹ� , FALSE=����ʧ��
 */
VMINT vm_get_appstore_config(vm_nvram_appstore_config_t * appstore_config_ptr);

/**
 *	����appstore3��չ���õ�nvram
 *	@param appstore_config_ptr   ָ��appstore�������ݽṹ��ָ�룬����ΪNULL
 *	@return TRUE=�����ɹ� , FALSE=����ʧ��
 */
VMINT vm_set_appstore3_config(vm_nvram_appstore3_config_t * appstore_config_ptr);

/**
 *	��nvram�õ�appstore3��չ����
 *	@param appstore_config_ptr   ָ��appstore�������ݽṹ��ָ�룬����ΪNULL
 *	@return TRUE=�����ɹ� , FALSE=����ʧ��
 */
VMINT vm_get_appstore3_config(vm_nvram_appstore3_config_t * appstore_config_ptr);



/********************************************************/
/*********************�����ǼƷ����**************/
/********************************************************/

/**
 * ͨ�����ݽṹ
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
 * NVRAM��������洢�ļƷ�ͨ��������
 */
#define NVRAM_PAYMENT_CHANNEL_EXT_NUM						(32)
#define NVRAM_PAYMENT_CHANNEL_EXT_NUM_PER_RECORD			(16)



/**
 *	ͨ���б����ݽṹ
 */
typedef struct
{
	vm_paychannel_ext_t	paychannel_list_ext[NVRAM_PAYMENT_CHANNEL_EXT_NUM];
}  vm_nvram_paychannel_list_ext_t;

/**
 *	��nvram�õ��Ʒ�ͨ���б�
 *	@param paychannel_list_ext_ptr   ָ��Ʒ�ͨ���б����ݽṹ��ָ�룬����ΪNULL
 *	@return TRUE=�����ɹ� , FALSE=����ʧ��
 */
VMINT vm_get_pay_channel_list_ext(vm_nvram_paychannel_list_ext_t * paychannel_list_ext_ptr);

/**
 *	���üƷ�ͨ���б�nvram
 *	@param paychannel_list_ext_ptr   ָ��Ʒ�ͨ���б����ݽṹ��ָ�룬����ΪNULL
 *	@return TRUE=�����ɹ� , FALSE=����ʧ��
 */
VMINT vm_set_pay_channel_list_ext(vm_nvram_paychannel_list_ext_t * paychannel_list_ext_ptr);


/**
 *     �Ʒ�ƾ֤�ṹ
 */
typedef struct {
	VMINT app_id;  /*��ˮ��*/
	VMUINT seq_id;  /*Ӧ�ó�����*/
	VMUINT local_payment_id;  /*�Ʒѵ���*/
	VMUINT fee;  /*�۸�*/
	VMUINT source;  /*Ӧ�ó�����Դ��0ΪԤװ��1Ϊ����*/
	VMCHAR ext_content[12];  /*�ϴ�������������Ϣ*/
} vm_charge_detail_record_t;

/**
 *    NVRAM��������洢�ļƷ�ƾ֤�ĸ���
 */
#define NVRAM_CHARGE_DETAIL_NUM     (32)

/**
 *    �Ʒ�ƾ֤�б�
 */
typedef struct {
	vm_charge_detail_record_t charge_detail[NVRAM_CHARGE_DETAIL_NUM];
} vm_nvram_charge_detail_list_t;

/**
 *	 ��nvram�õ� �Ʒ�ƾ֤�б�
 *	@param charge_detail_list_ptr   ָ�� �Ʒ�ƾ֤�б����ݽṹ��ָ�룬����ΪNULL
 *	@return TRUE=�����ɹ� , FALSE=����ʧ��
 */
VMINT vm_get_charge_detail_list(vm_nvram_charge_detail_list_t * charge_detail_list_ptr);

/**
 *	���� �Ʒ�ƾ֤�б�nvram
 *	@param charge_detail_list_ptr   ָ�� �Ʒ�ƾ֤�б����ݽṹ��ָ�룬����ΪNULL
 *	@return TRUE=�����ɹ� , FALSE=����ʧ��
 */
VMINT vm_set_charge_detail_list(vm_nvram_charge_detail_list_t * charge_detail_list_ptr);


/**
 *    �ƷѶ���ƾ֤���ݽṹ
 */
typedef struct {
VMUINT seq_id;
VMCHAR sms_access[21];
VMCHAR sms_command[31];
} vm_sms_detail_record_t;

/**
 *    NVRAM��������洢�ļƷѶ���ƾ֤�ĸ���
 */
#define NVRAM_CHARGE_SMS_DETAIL_NUM     (32)

/**
 *    �ƷѶ���ƾ֤�б�
 */
typedef struct {
	vm_sms_detail_record_t   charge_sms_detail[NVRAM_CHARGE_SMS_DETAIL_NUM];
} vm_nvram_charge_sms_detail_list_t;

/**
 *	 ��nvram�õ� �ƷѶ���ƾ֤�б�
 *	@param charge_sms_detail_list_ptr   ָ�� �ƷѶ���ƾ֤�б����ݽṹ��ָ�룬����ΪNULL
 *	@return TRUE=�����ɹ� , FALSE=����ʧ��
 */
VMINT vm_get_charge_sms_detail_list(vm_nvram_charge_sms_detail_list_t * charge_sms_detail_list_ptr);

/**
 *	���� �ƷѶ���ƾ֤�б�nvram
 *	@param charge_sms_detail_list_ptr   ָ�� �ƷѶ���ƾ֤�б����ݽṹ��ָ�룬����ΪNULL
 *	@return TRUE=�����ɹ� , FALSE=����ʧ��
 */
VMINT vm_set_charge_sms_detail_list(vm_nvram_charge_sms_detail_list_t * charge_sms_detail_list_ptr);

/**
 *	�Ʒ�ˮӡ���ݽṹ
 */
typedef struct {
VMINT app_id;
VMINT app_state;
VMINT8 available [8];
} vm_app_info_ext_t;

/**
 *    NVRAM��������洢�ĳ���״̬�ĸ���
 */
#define NVRAM_APP_PAYMENT_INFO_EXT_NUM			(500)
#define NVRAM_APP_PAYMENT_INFO_EXT_NUM_PER_RECORD			(100)

/**
 *	Ӧ�ó���״̬�б����ݽṹ
 */
typedef struct
{
	vm_app_info_ext_t app_info_ext_list[NVRAM_APP_PAYMENT_INFO_EXT_NUM];
} vm_nvram_app_info_ext_list_t;

/**
 *	 ��nvram�õ�Ӧ����Ϣ�б�
 *	@param app_info_ext_list_ptr   ָ��Ӧ�ó���״̬�б����ݽṹ��ָ�룬����ΪNULL
 *	@return TRUE=�����ɹ� , FALSE=����ʧ��
 */
VMINT vm_get_app_info_list(vm_nvram_app_info_ext_list_t * app_info_ext_list_ptr);

/**
 *	����Ӧ����Ϣ�б�nvram
 *	@param app_info_ext_list_ptr   ָ��Ӧ�ó���״̬�б����ݽṹ��ָ�룬����ΪNULL
 *	@return TRUE=�����ɹ� , FALSE=����ʧ��
 */
VMINT vm_set_app_info_list(vm_nvram_app_info_ext_list_t * app_info_ext_list_ptr);


/**
 *    �Ʒ����ýṹ
 */
typedef struct {
VMUINT update_interval_days;
VMUINT sms_notification_flag;
VMUINT user_balance;
VMUINT reserved;
} vm_pay_config_t;

/**
 *	 ��nvram�õ��Ʒ�����
 *	@param pay_config_ptr   ָ��Ʒ��������ݽṹ��ָ�룬����ΪNULL
 *	@return TRUE=�����ɹ� , FALSE=����ʧ��
 */
VMINT vm_get_pay_config(vm_pay_config_t * pay_config_ptr);

/**
 *	���üƷ����õ�nvram
 *	@param pay_config_ptr   ָ��Ʒ��������ݽṹ��ָ�룬����ΪNULL
 *	@return TRUE=�����ɹ� , FALSE=����ʧ��
 */
VMINT vm_set_pay_config(vm_pay_config_t * pay_config_ptr);


/**
 *     ��Ӫ�̽ṹ
 */
typedef struct {
	VMCHAR operator_code[8];
} vm_operator_code_t;

#define NVRAM_OPERATE_CODE_LIST_NUM   (32)

/**
 *	��Ӫ�̱����ݽṹ
 */
typedef struct
{
	vm_operator_code_t operator_code_list[NVRAM_OPERATE_CODE_LIST_NUM];
} vm_nvram_operator_code_list_t;

/**
 *	 ��nvram�õ���Ӫ�̱�
 *	@param operator_code_list_ptr   ָ����Ӫ�̱����ݽṹ��ָ�룬����ΪNULL
 *	@return TRUE=�����ɹ� , FALSE=����ʧ��
 */
VMINT vm_get_operator_code(vm_nvram_operator_code_list_t * operator_code_list_ptr);

/**
 *	������Ӫ�̱�nvram
 *	@param operator_code_list_ptr   ָ����Ӫ�̱����ݽṹ��ָ�룬����ΪNULL
 *	@return TRUE=�����ɹ� , FALSE=����ʧ��
 */
VMINT vm_set_operator_code(vm_nvram_operator_code_list_t * operator_code_list_ptr);


 
/**
 * ͨ�����ݽṹ
 */
typedef struct
{
	VMUINT		org_id;				/*��ţ���λ�η�ʽ��ʾ������0����Ͱ����λ��1���Դ����ơ�	*/
	VMUINT16	        sp_id;				/*�ƶ�����ͨ�ı�־,	1bit���ƶ���2bit����ͨ��3bit�ǵ��š�	*/
	VMCHAR		sms_id[20];			/*���Ž���š�												*/
	VMCHAR		sms_content[30];	/*�������ݡ�												*/
	VMUINT		fee;					/*ͨ���ĵ��ۣ���λΪ�֡�									*/
}  vm_paychannel_t;

/**
 * NVRAM��������洢�ļƷ�ͨ��������
 */
#define NVRAM_PAYMENT_CHANNEL_NUM						(128)
#define NVRAM_PAYMENT_CHANNEL_NUM_PER_RECORD			(32)

/**
 *	ͨ���б����ݽṹ
 */
typedef struct
{
	vm_paychannel_t	paychannel_list[NVRAM_PAYMENT_CHANNEL_NUM];
}  vm_nvram_paychannel_list_t;

/**
 *	Ӧ�ó���״ֵ̬��ö����
 */
typedef enum
{
	VM_TRIAL = 0,		/*���ã����ɷ�*/
	VM_USING,			/*�Ѿ��ɷѣ�����*/
	VM_TERMINATE,		/*�ɷ�ʧЧ��ͣ��*/
	VM_NO_STATE
} vm_app_state_e;

/**
 *	Ӧ�ó���״̬���ݽṹ
 */
typedef struct 
{
	VMINT app_id;				/*Ӧ�ó������*/
	VMINT app_state;			/*Ӧ�ó���״̬*/
	VMINT8 available[8];		/*Ӧ�ó�����Ч�ֶΣ���Чʱ��8�ֽ��룬��ЧʱΪȫ0*/
} vm_app_info_t;

#define NVRAM_APP_PAYMENT_INFO_NUM			(500)

/**
 *	Ӧ�ó���״̬�б����ݽṹ
 */
typedef struct
{
	vm_app_info_t app_info_list[NVRAM_APP_PAYMENT_INFO_NUM];
} vm_nvram_app_info_list_t;

/**
 *	 ��nvram�õ�Ӧ����Ϣ�б�
 *	@param app_info_list_ptr   ָ��Ӧ�ó���״̬�б����ݽṹ��ָ�룬����ΪNULL
 *	@return TRUE=�����ɹ� , FALSE=����ʧ��
 */
VMINT vm_get_app_state_list(vm_nvram_app_info_list_t * app_info_list_ptr);

/**
 *	����Ӧ����Ϣ�б�nvram
 *	@param app_info_list_ptr   ָ��Ӧ�ó���״̬�б����ݽṹ��ָ�룬����ΪNULL
 *	@return TRUE=�����ɹ� , FALSE=����ʧ��
 */
VMINT vm_set_app_state_list(vm_nvram_app_info_list_t * app_info_list_ptr);

/**
 *	���üƷ�ͨ���б�nvram
 *	@param paychannel_list_ptr   ָ��Ʒ�ͨ���б����ݽṹ��ָ�룬����ΪNULL
 *	@return TRUE=�����ɹ� , FALSE=����ʧ��
 */
VMINT vm_set_pay_channel_list(vm_nvram_paychannel_list_t * paychannel_list_ptr);

/**
 *	��nvram�õ��Ʒ�ͨ���б�
 *	@param paychannel_list_ptr   ָ��Ʒ�ͨ���б����ݽṹ��ָ�룬����ΪNULL
 *	@return TRUE=�����ɹ� , FALSE=����ʧ��
 */
VMINT vm_get_pay_channel_list(vm_nvram_paychannel_list_t * paychannel_list_ptr);



/*vre3.1.1��ʼ����*******************************************************************************/

/**(vre3.1.1��ʼ�д˺���)
 */
VMINT vm_set_local_apn_info(vm_local_info * local_info_ptr);

 /**(vre3.1.1��ʼ�д˺���)
 */
VMINT vm_get_local_apn_info(vm_local_info * local_info_ptr);
VMINT vm_set_user_apn_info(vm_apn_info * apn_info_ptr);

VMINT vm_get_user_apn_info(vm_apn_info * apn_info_ptr);
 
 	
typedef struct {	
	VMUINT fee_actual;   
	VMINT reserv1;     /*(vre3.1.4��ʼ�˱����ֶα�ʾ����)*/
	VMINT reserv2;	   /*(vre3.1.4��ʼ�˱����ֶα�ʾ����)*/
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
	VMINT rate;                           /* ���� */
	VMCHAR mcc[4];                     /*������*/
	VMWCHAR title[64];               /*��ʾ�������: �ʷ�˵��*/ 
	VMWCHAR ok[16];				 /*�������ʾ����:ȷ��*/ 
	VMWCHAR back[16];			 /*�������ʾ����:����*/ 
	VMWCHAR notification1[160];	/*����1��ʾ����:��ʾ�û���Ҫ�������Ʒ����ʾ��*/ 
	VMWCHAR notification2[128];	/*����2��ʾ����:�Ʒ��е���ʾ��*/ 
	VMWCHAR notification3[128];	/*����3��ʾ����:�Ʒѳɹ�����ʾ��*/ 
	VMWCHAR notification4[160];    /*����4��ʾ����:�Ʒ�ʧ�ܵ���ʾ��*/  
	VMWCHAR currency_unit[10];    /*Ӣ�ı�ʾ�ı��ػ��ҵ�λ*/
}vm_pay_notification_t;


/**(vre3.1.1��ʼ�д˺���)
 *	���õ���ʾ���Ե�nvram
 *	@param pay_notification_ptr   ָ����Ӫ�̱����ݽṹ��ָ�룬����ΪNULL
 *	@return TRUE=�����ɹ� , FALSE=����ʧ��
 */
VMINT vm_set_pay_notification(vm_pay_notification_t * pay_notification_ptr);

/**(vre3.1.1��ʼ�д˺���)
 *	 ��nvram�õ��ù���ʾ����
 *	@param pay_notification_ptr   ָ����Ӫ�̱����ݽṹ��ָ�룬����ΪNULL
 *	@return TRUE=�����ɹ� , FALSE=����ʧ��
 */
VMINT vm_get_pay_notification(vm_pay_notification_t * pay_notification_ptr);

/**(vre3.1.1��ʼ�д˺���)
 *	���õ��Ʒ�ͨ����չ�����Ϣ��nvram
 *	@param paychannel_a_list_ext_ptr   ָ����Ӫ�̱����ݽṹ��ָ�룬����ΪNULL
 *	@return TRUE=�����ɹ� , FALSE=����ʧ��
 */
VMINT vm_set_pay_channel_a_list_ext(vm_nvram_paychannel_a_list_ext_t * paychannel_a_list_ext_ptr);

/**(vre3.1.1��ʼ�д˺���)
 *	 ��nvram�õ��Ʒ�ͨ����չ�����Ϣ
 *	@param paychannel_a_list_ext_ptr   ָ����Ӫ�̱����ݽṹ��ָ�룬����ΪNULL
 *	@return TRUE=�����ɹ� , FALSE=����ʧ��
 */
VMINT vm_get_pay_channel_a_list_ext(vm_nvram_paychannel_a_list_ext_t * paychannel_a_list_ext_ptr);



/**(vre3.1.1��ʼ�д˺���)
 *	������Ӫ�̱�nvram     (indexȡֵ: 0~3)
 *	@param operator_code_list_ptr   ָ����Ӫ�̱����ݽṹ��ָ�룬����ΪNULL
 *	@return TRUE=�����ɹ� , FALSE=����ʧ��
 */
VMINT vm_set_operator_code_ext(VMINT index, vm_nvram_operator_code_list_t * operator_code_list_ptr);

 
/**
 *	 ��nvram�õ���Ӫ�̱�   (indexȡֵ: 0~3)
 *	@param operator_code_list_ptr   ָ����Ӫ�̱����ݽṹ��ָ�룬����ΪNULL
 *	@return TRUE=�����ɹ� , FALSE=����ʧ��
 */
VMINT vm_get_operator_code_ext(VMINT index, vm_nvram_operator_code_list_t * operator_code_list_ptr);


/****************************************************************************************************/


/*vre3.1.4��ʼ����*******************************************************************************/
/*
 * �Ʒ�ͨ��ʹ����Ϣ
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
 * �Ʒ�ͨ��ʹ����Ϣ�б�
 */
typedef struct
{
	vm_paychanel_usage_info_t	paychannel_usage_list_ext[NVRAM_PAYMENT_CHANNEL_EXT_NUM];
}  vm_nvram_paychannel_usage_list_t;


/**(vre3.1.4��ʼ�д˺���)
 *	��nvram�õ��Ʒ�ͨ��ʹ����Ϣ�б�
 *	@param paychannel_usage_list_ptr   ָ��Ʒ�ͨ���б����ݽṹ��ָ�룬����ΪNULL
 *	@return TRUE=�����ɹ� , FALSE=����ʧ��
 */
 VMINT vm_get_paychannel_usage_list(vm_nvram_paychannel_usage_list_t * paychannel_usage_list_ptr);
 
/**(vre3.1.4��ʼ�д˺���)
 *	���üƷ�ͨ��ʹ����Ϣ�б�nvram
 *	@param paychannel_usage_list_ptr   ָ��Ʒ�ͨ���б����ݽṹ��ָ�룬����ΪNULL
 *	@return TRUE=�����ɹ� , FALSE=����ʧ��
 */
VMINT vm_set_paychannel_usage_list(vm_nvram_paychannel_usage_list_t * paychannel_usage_list_ptr);


/**
 *     ��չ�Ʒ�ƾ֤�ṹ
 */
typedef struct {
	VMINT app_id;  /*��ˮ��*/
	VMUINT seq_id;  /*Ӧ�ó�����*/
	VMUINT local_payment_id;  /*�Ʒѵ���*/
	VMUINT fee;  /*�۸�*/
	VMUINT source;  /*Ӧ�ó�����Դ��0ΪԤװ��1Ϊ����*/
	VMCHAR ext_content[12];  /*�ϴ�������������Ϣ*/
	VMCHAR mcc[4];  /*������*/
} vm_charge_detail_record_ext_t;

/**
 *       ��չ�Ʒ�ƾ֤�б�
 */

typedef struct {
	vm_charge_detail_record_ext_t charge_detail_ext[NVRAM_CHARGE_DETAIL_NUM];
} vm_nvram_charge_detail_list_ext_t;



/**(vre3.1.4��ʼ�д˺���)
 *	 ��nvram�õ�  ��չ�Ʒ�ƾ֤�б�
 *	@param charge_detail_list_ptr   ָ�� �Ʒ�ƾ֤�б����ݽṹ��ָ�룬����ΪNULL
 *	@return TRUE=�����ɹ� , FALSE=����ʧ��
 */
VMINT vm_get_charge_detail_list_ext(vm_nvram_charge_detail_list_ext_t * charge_detail_list_ext_ptr);

/**(vre3.1.4��ʼ�д˺���)
 *	����  ��չ�Ʒ�ƾ֤�б�nvram
 *	@param charge_detail_list_ptr   ָ�� �Ʒ�ƾ֤�б����ݽṹ��ָ�룬����ΪNULL
 *	@return TRUE=�����ɹ� , FALSE=����ʧ��
 */
VMINT vm_set_charge_detail_list_ext(vm_nvram_charge_detail_list_ext_t * charge_detail_list_ext_ptr);


/**
 *    ��չ�Ʒ����ýṹ
 */
typedef struct {
VMUINT update_interval_days;
VMUINT sms_notification_flag;
VMUINT user_balance;
VMUINT reserved;
VMWCHAR pre_string[12]; 
VMWCHAR suff_string[2]; 
} vm_pay_config_ext_t;



/**(vre3.1.4��ʼ�д˺���)
 *	 ��nvram�õ� ��չ�Ʒ�����
 *	@param pay_config_ptr   ָ�� ��չ�Ʒ��������ݽṹ��ָ�룬����ΪNULL
 *	@return TRUE=�����ɹ� , FALSE=����ʧ��
 */
VMINT vm_get_pay_config_ext(vm_pay_config_ext_t * pay_config_ext_ptr);

/**(vre3.1.4��ʼ�д˺���)
 *	���� ��չ�Ʒ����õ�nvram
 *	@param pay_config_ptr   ָ�� ��չ�Ʒ��������ݽṹ��ָ�룬����ΪNULL
 *	@return TRUE=�����ɹ� , FALSE=����ʧ��
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





