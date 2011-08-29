/**
 * vmnvramadapter.h�Ƕ���vmnvram.h�����䣬�ṩ��APP STRORE����NVRAM�Ĳ����ӿں���������
 * APP STORE��Ӧ��ֻ����vmnvramadapter.h�������ĺ�������NVRAM���в�������Ӧ��ֱ�ӵ���
 * vmnvram.h��ĺ�����
 * vmnvramadapter.hӦ��ֻ��APP STORE��ͼƷ�������ű�ʹ�á�
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
 * �����ɹ���
 */
#define VM_ADAPTER_NVRAM_SUCCESS			(0)

/**
 * ��¼û�б����֡�
 */
#define VM_ADAPTER_NVRAM_NOT_FOUND_RECORD	(1)

/**
 * �ڴ治����
 */
#define VM_ADAPTER_NVRAM_ERROR_MEM			(-1)

/**
 * ��������
 */
#define VM_ADAPTER_NVRAM_ERROR_PARAM		(-2)

/**
 * ��ȡNVRAM�ڲ�����
 */
#define VM_ADAPTER_NVRAM_INTERNAL_ERROR		(-3)

/**
 * ������NVRAM�Ĵ洢������
 */
#define VM_ADAPTER_NVRAM_OVERFLOW_STORAGE	(-4)
/** @} */

/**
 * Ӧ�ó����շѼ�¼��
 */
typedef vm_app_info_t		vm_app_charge_record;

/**
 * �շ�ͨ����¼��
 */
typedef struct {
	VMUSHORT    org_id;				/*��š�										*/	
	VMUSHORT	sp_id;				/*�ƶ�����ͨ�ı�־,	1���ƶ���2����ͨ��3�ǵ��š�	*/
	VMCHAR		sms_id[20];			/*���Ž���š�									*/
	VMCHAR		sms_content[30];	/*�������ݡ�												*/
	VMUINT		fee;				/*ͨ���ĵ��ۣ���λΪ�֡�						*/
} vm_payment_channel_record;

/**
 * ���ݲ�Ʒ��ŵõ�Ӧ�ó����շѼ�¼��
 * 
 * @param[in]			pid ��Ʒ��š�
 * @param[out]			record ָ���շѼ�¼�ṹ��ָ�롣
 * @return				�Ƿ�����ɹ��ı�־��
 * @retval				VM_ADAPTER_NVRAM_SUCCESS ���ݲ�Ʒ��ųɹ��ҵ���Ӧ��Ӧ�ó���Ʒ�״̬��
 * @retval				VM_ADAPTER_NVRAM_ERROR_PARAM recordָ��NULL��ʱ�򷵻ر������롣
 * @retval				VM_ADAPTER_NVRAM_NOT_FOUND_RECORD ���ݲ�Ʒ���û���ҵ���Ӧ��Ӧ�ó����շѼ�¼��
 * @retval				VM_ADAPTER_NVRAM_INTERNAL_ERROR �ڲ�����װ�ز��ɹ���
 * @retval				VM_ADAPTER_NVRAM_ERROR_MEM �ڴ治�㣬װ�ز��ɹ���
 */
VMINT vm_load_app_charge_record(VMINT pid, vm_app_charge_record* record);

/**
 * �洢Ӧ���շѼ�¼�����NVRAM��������Ѿ����ˣ��򸲸ǵ���ǰ�Ѿ������ڲ���
 * ���类�洢��Ӧ�ó����Ӧ���շѼ�¼������洢���շѼ�¼�Ѿ����������֮��
 * 
 * @param[in]			record �շѼ�¼��
 * @param[in]			exist_app_pid_lst ��ǰ���ڵĲ�Ʒ��ŵ��б�
 * @param[in]			lst_num ��Ʒ��ŵĸ�����
 * @return				�����Ƿ�ɹ��ı�־��
 * @retval				VM_ADAPTER_NVRAM_SUCCESS �洢�ɹ���
 * @retval				VM_ADAPTER_NVRAM_ERROR_PARAM �����������record����ΪNULL��
 *						��lst_num����0����exist_app_pid_lst����NULL����ô�������뽫�ᱻ���ء�
 * @retval				VM_ADAPTER_NVRAM_INTERNAL_ERROR �ڲ����󣬴洢���ɹ���
 * @retval				VM_ADAPTER_NVRAM_ERROR_MEM �ڲ����������治�ɹ���
*/
VMINT vm_save_app_charge_record(vm_app_charge_record* record, 
	VMINT* exist_app_pid_lst, VMUINT lst_num);
	
/**
 * ��ѯ��save_app_charge_record�Ƿ�Ḳ�ǵ�����ļƷ�״̬��¼�����򷵻�
 * ��Ҫ���Ǽ�¼����Ӧ��APP_ID��
 * 
 * @param[in]			exec_app_id ��Ҫ���е�Ӧ�ó���ID��
 * @param[out]			replace_app_id ����0����Ҫ����NVRAM���Ѿ��еļƷ�
 *						״̬��¼�����򷵻ؽ����ܱ����ǵ��Ʒ�״̬��¼�Ķ�Ӧ��Ӧ�ó���
 *						ID��
 * @return				�Ƿ�ɹ��ı�־��
 * @retval				VM_ADAPTER_NVRAM_SUCCESS �ɹ���
 * @retval				VM_ADAPTER_NVRAM_ERROR_PARAM ����Ĳ�����
 * @retval				VM_ADAPTER_NVRAM_ERROR_MEM �ڴ治�����������ɹ���
 * @retval				VM_ADAPTER_NVRAM_INTERNAL_ERROR �ڲ����󣬲������ɹ���
 */
VMINT vm_app_charge_record_is_replace(VMINT exec_app_id, VMINT* replace_app_id);

/**
 * �洢�շ�ͨ����
 * 
 * @param[in]			record_lst �շ�������¼�б�������Ӧ��ָ��record_num��
 *						vm_payment_channel_record�ṹ�����ݡ�
 * @param[in]			record_num record_lstָ���vm_payment_channel_record�ṹ�ĸ�����
 * @return				�洢�Ƿ�ɹ��ı�־��
 * @retval				VM_ADAPTER_NVRAM_SUCCESS ����ɹ���
 * @retval				VM_ADAPTER_NVRAM_OVERFLOW_STORAGE �����˴洢������
 * @retval				VM_ADAPTER_NVRAM_ERROR_PARAM ����Ĳ��������record_lstָ��NULL����ô�����󽫻ᱻ���ء�
 * @retval				VM_ADAPTER_NVRAM_INTERNAL_ERROR �ڲ����󣬴洢ʧ�ܡ�
 * @retval				VM_ADAPTER_NVRAM_ERROR_MEM �ڴ治�����洢ʧ�ܡ�
 */
VMINT vm_save_charge_channel_records(vm_payment_channel_record* record_lst, 
	VMUINT record_num);

/**
 * װ��ָ����ŵ��շ�ͨ�������װ�سɹ��ڲ�ʹ��ʱ���������vm_release_charge_channel_records
 * ���������ͷš�
 * 
 * @param[in]			group_id ָ���üƷ�ͨ����š�
 * @param[out]			record_lst ָ��vm_payment_channel_record��ͷָ���ָ�룬�ڲ��ú�
 *						�������vm_release_charge_channel_records�ͷ��ڴ档
 * @param[out]			record_num ����������Ҳ���ָ����ļƷ�ͨ����record_numд��0��
 * @return				�Ƿ�ɹ�װ�صı�־��
 * @retval				VM_ADAPTER_NVRAM_SUCCESS װ�سɹ���
 * @retval				VM_ADAPTER_NVRAM_INTERNAL_ERROR �ڲ�����װ��ʧ�ܡ�
 * @retval				VM_ADAPTER_NVRAM_ERROR_MEM �ڴ治����װ��ʧ�ܡ�
 * @note				�ڲ�ʹ��record_lst��ָ��Ķ�������Ҫ����
 *						vm_release_charge_channel_records�����ͷ�֮��
 */
VMINT vm_load_group_charge_channel_records(VMUSHORT group_id, 
	vm_payment_channel_record** record_lst, VMUINT* record_num);

/**
 * �ͷ��շ�ͨ����¼�������¼��ͨ��vm_load_charge_channel_records������ȡ��
 * ����Ҫ���ñ������ͷš�
 * 
 * @param[in]			record_lst ָ��vm_payment_channel_record�ṹ��ͷָ�롣
 * @return				�Ƿ�ɹ��ı�־��
 * @retval				VM_ADAPTER_NVRAM_SUCCESS �ɹ��ͷ�װ�ص��շ�ͨ����¼��
 * @retval				VM_ADAPTER_NVRAM_ERROR_PARAM ��������
 */
VMINT vm_release_charge_channel_records(vm_payment_channel_record* record_lst);

/**
 * �洢���ͱ�š�
 * 
 * @param[in]				mid ���ͱ�š�
 * @return					�Ƿ�ɹ��洢���ͱ�š�
 * @retval					VM_ADAPTER_NVRAM_SUCCESS �洢�ɹ���
 * @retval					VM_ADAPTER_NVRAM_INTERNAL_ERROR NVRAM�ڲ����󣬴洢ʧ�ܡ�
 * @retval					VM_ADAPTER_NVRAM_ERROR_MEM �ڴ治��������ʧ�ܡ�
 */
VMINT vm_save_mobile_phone_id_record(VMINT mid);

/**
 * �洢�û���š�
 * 
 * @param[in]				uid �û���š�
 * @return					�洢�û���š�
 * @retval					VM_ADAPTER_NVRAM_SUCCESS �洢�ɹ���
 * @retval					VM_ADAPTER_NVRAM_INTERNAL_ERROR NVRAM�ڲ����󣬴洢ʧ�ܡ�
 * @retval					VM_ADAPTER_NVRAM_ERROR_MEM �ڴ治��������ʧ�ܡ�		
 */
VMINT vm_save_user_id_record(VMINT uid);

/**
 * װ�ػ��ͱ�ţ��������û�д洢���ͱ�ţ�����ñ���������
 * �õ��Ļ��ͱ��Ϊ0��
 * 
 * @param[in]				mid ���ͱ�ŵ�ָ�롣
 * @return					װ�ػ��ͱ���Ƿ�ɹ���
 * @retval					VM_ADAPTER_NVRAM_SUCCESS ��NVRAMװ�سɹ���
 * @retval					VM_ADAPTER_NVRAM_INTERNAL_ERROR NVRAM�ڲ�����װ��ʧ�ܡ�
 * @retval					VM_ADAPTER_NVRAM_ERROR_PARAM ��������װ��ʧ�ܡ�
 * @retval					VM_ADAPTER_NVRAM_ERROR_MEM �ڴ治����װ��ʧ�ܡ�									
 */
VMINT vm_load_mobile_phone_id_record(VMINT* mid);

/**
 * װ���û���ţ��������û�д洢�û���ţ�����ñ���������
 * �õ����û����Ϊ0��
 * 
 * @param[in]				uid �û���ŵ�ָ�롣
 * @return					װ���û�����Ƿ�ɹ���
 * @retval					VM_ADAPTER_NVRAM_SUCCESS ��NVRAMװ�سɹ���
 * @retval					VM_ADAPTER_NVRAM_INTERNAL_ERROR NVRAM�ڲ�����װ��ʧ�ܡ�
 * @retval					VM_ADAPTER_NVRAM_ERROR_PARAM ��������װ��ʧ�ܡ�
 * @retval					VM_ADAPTER_NVRAM_ERROR_MEM �ڴ治����װ��ʧ�ܡ�										
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
 * �ϲ�����ʱ���������������ֻ��ȡ������Ӧ�ó����ĸ���ʱ�����ʾ������Ρ�
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
 * @param[out]				timestamps �ϲ����ĸ���ʱ������顣
 * @param[in]				curr_timestamp ��Ҫ���ϲ���ָ�����͵�ʱ�����
 * @param[in]				time_type ʱ��������ͣ���Ӧ����VM_NVRAM_MAX_TIMESTAMP��
 * @return					�ϲ��Ƿ�ɹ���
 * @retval					TRUE ��ʾ�ɹ���
 * @retval					FALSE ��ʾʧ�ܡ�
 */
VMINT vm_merge_timestamp(vm_time_t timestamps[VM_NVRAM_MAX_TIMESTAMP], 
	vm_time_t* curr_timestamp, TIMESTAMP_TYPE time_type);

/**
 * ��ȡָ�����͵ĸ���ʱ�����������ȡ��ϵͳȨ�޵ĸ���ʱ�����֤���ĸ���ʱ�����
 * 
 * @code
 * vm_time_t timestamps[5];
 * vm_time_t curr_timestamp;
 *
 * if (vm_load_timestamps_record(timestamps) == VM_ADAPTER_NVRAM_SUCCESS)
 * {
 *     if (vm_merge_timestamp(timestamps, &curr_timestamp, VM_NVRAM_SYS_PERMISSION_TIMESTAMP))
 *     {
 *         // �ɹ��õ�ϵͳȨ�޵ĸ���ʱ�����
 *     }
 *	   if (vm_merge_timestamp(timestamps, &curr_timestamp, VM_NVRAM_PUBLIC_CERT_LST_TIMESTAMP))
 *     {
 *         // �ɹ��õ���Կ��ĸ���ʱ�����
 *     }
 * } 
 * @endcode
 * @param[in]				timestamps ȡ�ø���ʱ��������顣
 * @param[out]				curr_timestamp �õ�ָ������ʱ�����
 * @param[in]				time_type ʱ��������͡�
 * @return					����Ƿ�ɹ���
 * @retval					TRUE �ɹ���
 * @retval					FALSE ʧ�ܡ�
 */
VMINT vm_split_timestamp(vm_time_t timestamps[VM_NVRAM_MAX_TIMESTAMP], 
	vm_time_t* curr_timestamp, TIMESTAMP_TYPE time_type);

/**
 * �洢���еĸ���ʱ�����
 * 
 * 
 * @param[in]				timestamps ��Ҫ�洢�ĸ���ʱ������顣
 * @return					�洢�Ƿ�ɹ���
 * @retval					VM_ADAPTER_NVRAM_SUCCESS �ɹ��洢��
 * @retval					VM_ADAPTER_NVRAM_ERROR_PARAM ����Ĳ������洢ʧ�ܡ�
 * @retval					VM_ADAPTER_NVRAM_INTERNAL_ERROR NVRAM�ڲ��������洢ʧ�ܡ�
 * @retval					VM_ADAPTER_NVRAM_ERROR_MEM �ڴ治�������´���ʧ�ܡ�
 */
VMINT vm_save_timestamps_record(vm_time_t timestamps[VM_NVRAM_MAX_TIMESTAMP]);

/**
 * װ�����еĸ���ʱ�����
 * 
 * 
 * @param[out]				timestamps װ�صĸ���ʱ������顣
 * @return					װ���Ƿ�ɹ���
 * @retval					VM_ADAPTER_NVRAM_SUCCESS װ�سɹ���
 * @retval					VM_ADAPTER_NVRAM_ERROR_PARAM ����Ĳ�����װ��ʧ�ܡ�
 * @retval					VM_ADAPTER_NVRAM_INTERNAL_ERROR NVRAM�ڲ�������װ��ʧ�ܡ�
 * @retval					VM_ADAPTER_NVRAM_ERROR_MEM �ڴ治��������װ��ʧ�ܡ�
 */
VMINT vm_load_timestamps_record(vm_time_t timestamps[VM_NVRAM_MAX_TIMESTAMP]);

/**
 * ��Կ�Ĵ洢��¼��
 */
typedef struct {
	VMKey pKey;
	vm_time_t timestamp;
} vm_cert_record;

/**
* Ȩ�޼�¼��
 */
typedef vm_permission_t sys_permission_record;


/**
 * �洢����Ӧ�ó���ID��¼�б�
 * 
 * @param[in]				ban_app_lst ���õ�APP ID�б�
 * @param[in]				lst_num �б��������Ľ��õ�APP ID�ĸ�����
 * @return					�洢�Ƿ�ɹ��ı�־��
 * @retval					VM_ADAPTER_NVRAM_SUCCESS �洢�ɹ���
 * @retval					VM_ADAPTER_NVRAM_ERROR_PARAM �������󣬵��´洢ʧ�ܡ�
 * @retval					VM_ADAPTER_NVRAM_INTERNAL_ERROR NVRAM�ڲ������´洢ʧ�ܡ�
 * @retval					VM_ADAPTER_NVRAM_OVERFLOW_STORAGE ��Ҫ�洢�����ݳ����˴洢�������洢ʧ�ܡ�
 * @retval					VM_ADAPTER_NVRAM_ERROR_MEM �ڴ治�����洢ʧ�ܡ�
 */
VMINT vm_save_ban_app_lst_records(VMUINT* ban_app_lst, VMUINT lst_num);

/**
 * �洢ϵͳȨ�޼�¼�б�
 * 
 * @param[in]				permission_lst Ȩ���б�
 * @param[in]				lst_num �б�������Ȩ�޵ĸ�����
 * @return					�洢�Ƿ�ɹ��ı�־��
 * @retval					VM_ADAPTER_NVRAM_SUCCESS �洢�ɹ���
 * @retval					VM_ADAPTER_NVRAM_ERROR_PARAM �������󣬵��´洢ʧ�ܡ�
 * @retval					VM_ADAPTER_NVRAM_INTERNAL_ERROR NVRAM�ڲ������´洢ʧ�ܡ�
 * @retval					VM_ADAPTER_NVRAM_OVERFLOW_STORAGE ��Ҫ�洢�����ݳ����˴洢�������洢ʧ�ܡ�
 * @retval					VM_ADAPTER_NVRAM_ERROR_MEM �ڴ治�����洢ʧ�ܡ�
*/
VMINT vm_save_sys_permission_lst_records(sys_permission_record* permission_lst, 
	VMUINT lst_num);

/**
 * �洢֤���¼�б�
 * 
 * @param[in]				cert_lst ��Կ��¼�б�
 * @param[in]				lst_num �б��������Ĺ�Կ��¼�ĸ�����
 * @return					�洢�Ƿ�ɹ��ı�־��
 * @retval					VM_ADAPTER_NVRAM_SUCCESS �洢�ɹ���
 * @retval					VM_ADAPTER_NVRAM_ERROR_PARAM �������󣬵��´洢ʧ�ܡ�
 * @retval					VM_ADAPTER_NVRAM_INTERNAL_ERROR NVRAM�ڲ������´洢ʧ�ܡ�
 * @retval					VM_ADAPTER_NVRAM_OVERFLOW_STORAGE ��Ҫ�洢�����ݳ����˴洢�������洢ʧ�ܡ�
 * @retval					VM_ADAPTER_NVRAM_ERROR_MEM �ڴ治�����洢ʧ�ܡ�
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
	VMUINT fee;						/* ͨ���۸�					*/
	VMUINT16 sms_type;				/* �������ͣ�1Ϊ��ȷ��2Ϊģ���� */
	VMWCHAR service_name[11];		/* ҵ�����ơ�					*/
	VMWCHAR sp_name[9];				/* SP���ơ�						*/
	VMCHAR sms_access[21];			/* ���Ž����					*/
	VMCHAR sms_command[31];			/* ����ָ��						*/
	VMCHAR customer_number[16];		/* �ͷ�����						*/
	VMUINT need_send_num;			/* ���ŷ�������					*/
	VMUINT fee_actual;			/* ������Ӧ��ʵ�ʼ۸�*/
	VMUINT left_use_num;		/* ��ͨ��ʣ��ʹ�ô���*/
	VMUINT second_flag;			/* ��ͨ���Ƿ�Ϊ����ȷ��ͨ����1Ϊ��Ҫ����ȷ�ϣ�2 Ϊ����Ҫ����ȷ��*/
} vm_payment_channel_ext_record;

/**
 * ��ָ��ͨ����ָ����Ӫ�̱�ţ�ȡ�ö��żƷ�ͨ����ͨ�����۸�Ӵ�С���У��۸���ͬ�Ľ�ֻ����һ��
 * ����ͨ������̭�۸���ͬͨ����ԭ��Ϊ:ģ��ָ�����ھ�ȷָ��,��ȷָ��֮��Ϊ��һ����
 * 
 * @param[in]		group_id
 * @param[in]		operator_code
 * @param[out]		records
 * @param[out]		records_num
 */
VMINT vm_load_payment_channel_ext_records(VMUINT16 group_id, VMCHAR* operator_code, 
	vm_payment_channel_ext_record** records, VMUINT16* records_num);

/**
 * vm_load_payment_channel_ext_records����ȡ�õļƷ�ͨ����
 * 
 * @param[in]		records
 */
void vm_unload_payment_channel_ext_records(vm_payment_channel_ext_record* records);

/**
 * ȡ���û�������Ƿ�Ҫ�ڷ��Ͷ���ǰ��ʾ�ı�־��
 * 
 * @param[out]		user_balance
 * @param[out]		sms_notification_flag
 */
VMINT vm_get_user_balance_and_sms_notify_flag(VMUINT* user_balance, VMUINT* sms_notification_flag, VMUINT* reserved);

/**
 * �����û���
 * 
 * @param[in]		user_balance �û���
 */
VMINT vm_set_user_balance(VMUINT user_balance);

/**
 * ����Ʒ�ƾ֤��
 * 
 * @param[in]		detail_record �Ʒ�ƾ֤��
 */
VMINT vm_save_charge_detail_record(vm_charge_detail_record_t* detail_record);

/**
 * ������ŷ���ƾ֤��
 * 
 * @param[in]		sms_access ���Ž���š�
 * @param[in]		sms_command ����ָ�
 */
VMINT vm_save_sms_detail_record(VMCHAR* sms_access, VMCHAR* sms_command);


typedef enum
{
VM_VRE_VERSION30 = 0,
VM_VRE_VERSION31,
VM_VRE_VERSION32

}vre_vresion_enum;


/**
VMUINT send_second_flag; /*����ȫ�رգ���Ӧ�����ڼƷ�ʱ������ȷ�϶����Ѿ�����ȥ�ı�־��
							Ӧ�üƷѽ�������󣬸��ݴ˱�־�����Ƿ�Ҫ����Ʒ�ƾ֤ ��
				���ڰ뿪��ȫ��send_second_flag��ʾƥ�䵽�˶��ţ��ѽ�Ҫ���͵����ݺ����¼�����ˡ�
	
*/
typedef struct vm_second_sms_t
{
	VMWCHAR service_name[11];		
	VMWCHAR sp_name[9];
	VMUINT channel_fee;	
	VMUINT fee;	
	VMUINT send_index;/*�����Ͷ���ȷ�϶��ţ����ô˱�־���ȴ����ŷ��ͽ�������ݴ˱�־���жϷ��ص����������ŵ�callback��ֵΪquick_charge_sms_ptr->total_send_sms++*/
	VMUINT send_second_flag; /*����ȫ�رգ���Ӧ�����ڼƷ�ʱ������ȷ�϶����Ѿ�����ȥ�ı�־��Ӧ�üƷѽ�������󣬸��ݴ˱�־�����Ƿ�Ҫ����Ʒ�ƾ֤ */
	VMUINT save_sms_index; /*�����˽ṹʱ�����index, ֻΪtotal_save_sms++*/
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
 * ����ȷ���¼ӽṹ
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
 * �����������Ƿ����ָ�������ṩ�����֣��������ƺͼƷ�ֵ, ƥ���򽫶������ݵ�������ִ�д��random, û��������ִ���'Y'д��random
 *
 * @param sms			��������
 * @param sp_name		�����ṩ������
 * @param service_name	��������
 * @param fee			�Ʒ�ֵ���Է�Ϊ��λ
 * @param random		����������ִ���'Y'��ָ��, ������ִ�Ϊ"�ظ�"��"ȷ�ϵ㲥"����ִ�
 * @param size			����������ִ��ռ����ֵ������ĩβ��0 
 * 
 * @return				�ɹ�����TRUE, ���򷵻�FALSE
 */
VMINT sms_pattern_check(VMWSTR sms, VMWSTR sp_name, VMWSTR service_name, VMUINT fee, VMWSTR random, VMUINT size);

#define PAYMENT_LOG
 
#ifdef __cplusplus
}
#endif

#endif

