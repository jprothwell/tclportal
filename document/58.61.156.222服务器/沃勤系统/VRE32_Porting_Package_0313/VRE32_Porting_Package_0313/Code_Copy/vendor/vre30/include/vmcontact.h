#ifndef VMPHONEBOOK_H_
#define VMPHONEBOOK_H_

#ifdef __cplusplus
extern "C" {
#endif
#include "vmsys.h"

#define VM_PHB_MAX_SEARCH_LENGTH 60      /* �����ֳ�������*/

typedef enum {	
	VM_PHB_REQ_NOT_READY = -2,   /*�绰��ϵͳδ����*/
	VM_PHB_REQ_ERROR,                   /*�����������*/
	VM_PHB_REQ_NO_ERROR             /*��������ɹ�*/
}vm_phb_req_error_enum;

typedef enum {
VM_PHB_NAME_MODIFIED = 1,      
VM_PHB_NO_ERROR = 0,       /* ��������ɹ� */
VM_PHB_ERROR = -1,       /* ��������ʧ�� */
VM_PHB_NOT_READY = -2,       /* �绰��ϵͳδ����*/
VM_PHB_NUM_NOT_READY = -3,       /* �绰������δ����*/
VM_PHB_NOT_SUPPORT = -4,       /* �绰��ϵͳ��֧��*/
VM_PHB_NOT_FOUND = -5,       /* û�з�����Ŀ*/
VM_PHB_DATAMGR_BUSY = -6,       /* �绰��ϵͳ��æ*/
VM_PHB_STORAGE_FULL = -7,       /* ��������*/
VM_PHB_NO_SIM_CARD = -8,       /* ��sim��*/
VM_PHB_ADN_FORBID = -9,       /* sim���绰������ʧ�� */
VM_PHB_OUT_OF_INDEX = -10,       /* ��Ч���*/
VM_PHB_NUMBER_TOO_LONG = -11,       /* ��Ч�绰����*/
VM_PHB_BIRTHDAY_ERROR = -12      /* ��Ч���ո�ʽ*/
} vm_phb_error_enum;

/**
 *	�绰���洢λ�õ�ö��
 */
typedef enum {
  VM_PHB_STORAGE_LOC_SIM = 1,  /*SIM���绰��*/
  VM_PHB_STORAGE_LOC_PHONE,  /*�ֻ��绰��*/
  VM_PHB_STORAGE_LOC_SIM2,    /*SIM2���绰��*/
  VM_PHB_STORAGE_LOC_BOTH   /*��������λ�õĵ绰��*/
} vm_phb_storage_loc_enum;

/**
 *	�绰����������ö��
 */
typedef enum {
  VM_PHB_SEARCH_TYPE_NAME,  /*����������*/
  VM_PHB_SEARCH_TYPE_NUM  /*���绰�������*/
} vm_phb_search_type_enum;

/**
 *	�绰����Ŀ�����洢λ�ü�������ŵ����ݽṹ
 */
typedef struct
{
    VMUSHORT index;              /*������Ϊɾ��һ����¼�����ı�������¼��index*/              
    vm_phb_storage_loc_enum storage; 
} vm_phb_contact_pos_struct;

#define VM_MAX_PHB_NAME_LENGTH   30
#define VM_MAX_PHB_NUMBER_LENGTH   40
#define VM_MAX_PHB_EMAIL_LENGTH   60
#define VM_MAX_PHB_COMPANY_LENGTH	20
#define VM_MAX_PHB_TITLE_LENGTH	20
#define VM_MAX_PHB_URL_LENGTH	128
#define VM_MAX_PHB_ADDRESS_LENGTH	25
#define VM_MAX_PHB_NOTE_LENGTH	30
#define VM_MAX_PHB_GROUP_NAME_LENGTH 20

/**
 *	�绰����Ŀ��Ϣ�����ݽṹ��
 *    ������Ϣ����UCS2���롣
 */
typedef struct {
  vm_phb_contact_pos_struct pos;        /*��Ŀ�����Ĵ洢λ�ü������Ϣ*/
  VMUWCHAR name[VM_MAX_PHB_NAME_LENGTH + 1];    /*����*/
  VMUWCHAR number[VM_MAX_PHB_NUMBER_LENGTH +1 + 1];    /*�绰����*/
  VMUWCHAR home_number[VM_MAX_PHB_NUMBER_LENGTH + 1 + 1];    /*��ͥ�绰����*/
  VMUWCHAR office_number[VM_MAX_PHB_NUMBER_LENGTH + 1 + 1];    /*�칫�绰����*/
  VMUWCHAR fax_number[VM_MAX_PHB_NUMBER_LENGTH + 1 + 1];    /*�������*/
  VMUWCHAR email_address[VM_MAX_PHB_EMAIL_LENGTH + 1];    /*�����ʼ���ַ1*/
  VMUWCHAR email_address2[VM_MAX_PHB_EMAIL_LENGTH + 1];    /*�����ʼ���ַ2*/
  VMUWCHAR company_name[VM_MAX_PHB_COMPANY_LENGTH + 1];    /*��˾����*/
  VMUCHAR birth_day;    /*������*/
  VMUCHAR birth_mon;    /*������*/
  VMUINT16 birth_year;    /*������*/
  VMUWCHAR title[VM_MAX_PHB_TITLE_LENGTH + 1];    /*����*/
  VMUWCHAR url[VM_MAX_PHB_URL_LENGTH + 1];    /*��ַ*/
  VMUWCHAR adr_pobox[VM_MAX_PHB_ADDRESS_LENGTH + 1];    /*����*/
  VMUWCHAR adr_extension[VM_MAX_PHB_ADDRESS_LENGTH + 1];    /*�����ַ*/
  VMUWCHAR adr_street[VM_MAX_PHB_ADDRESS_LENGTH + 1];    /*�ֵ�*/
  VMUWCHAR adr_city[VM_MAX_PHB_ADDRESS_LENGTH + 1];    /*��*/
  VMUWCHAR adr_state[VM_MAX_PHB_ADDRESS_LENGTH + 1];    /*�ݡ�ʡ*/
  VMUWCHAR adr_postal_code[VM_MAX_PHB_ADDRESS_LENGTH + 1];    /*�ʱ�*/
  VMUWCHAR adr_country[VM_MAX_PHB_ADDRESS_LENGTH + 1];    /*����*/
  VMUWCHAR note[VM_MAX_PHB_NOTE_LENGTH + 1];    /*ע��*/
 VMUINT  group_mask;       /*��λ��������Ҫ�����Ⱥ��(���Լ�����Ⱥ��)*/   /* group_mask = (1<< group_id1) + (1<< group_id2) + ...*/         /*��group_mask=1,������group_id=0����group_mask=3,������group_id=0 ��group_id=1*/
                                                   /* group_mask& (1<<VM_MAX_PHB_GROUP_NAME_LENGTH -1)    �õ��Ķ����ƽ������1 ��λ�þ���group id��ֵ*/
} vm_phb_contact_struct;

typedef struct {
	VMUINT group_id;
	VMWCHAR group_name[VM_MAX_PHB_GROUP_NAME_LENGTH+1];
} vm_phb_group_struct;


/**
 *	�绰���ص����������Ͷ��塣
 *
 *    @param result   �����������ο�vm_phb_error_enum��
 *    @param contact_ptr   �绰����Ŀ��Ϣ����ָ�롣
 *                                    �����ݽṹָ��Ϊ��������ʱ��Ϊ�������ݽṹһ���ִ���ġ�
 */
typedef void (* vm_phb_callback_type)(VMINT result, vm_phb_contact_struct* contact_ptr);

/**
 *	��ӵ绰����Ŀ�������ݽṹ
 */
typedef struct {
  vm_phb_storage_loc_enum storage;     /*��Ҫ��ӵ��Ĵ洢�豸*/  /*1~phnoe_max, 1~sim_max, 1~sim2_max*/
  vm_phb_contact_struct* contact_ptr;   /*�绰����Ŀ����ָ�룬������Ҫ�����Ŀ��������Ϣ��
                                                                �ص������Ὣ��ָ�뷵�ظ��ͻ��ˣ�����дλ����Ϣ��*/
} vm_phb_add_req_struct;


/**
 *	ɾ���绰����Ŀ�������ݽṹ
 */
typedef struct {
  vm_phb_contact_pos_struct pos;	/*��Ҫɾ������Ŀ��λ����Ϣ*/
} vm_phb_delete_req_struct;


/**
 *	���µ绰����Ŀ�������ݽṹ
 */
typedef struct {
  vm_phb_contact_pos_struct pos;    /*��Ҫ���µ���Ŀ��λ����Ϣ*/
  vm_phb_contact_struct* contact_ptr;   /*�绰����Ŀ����ָ�룬������Ҫ�����Ŀ��������Ϣ��
                                                                �ص������Ὣ��ָ�뷵�ظ��ͻ���*/
} vm_phb_update_req_struct;


/**
 *	��ȡ�绰����Ŀ�������ݽṹ
 */
typedef struct {
  vm_phb_contact_pos_struct pos;   /*��Ҫ��ȡ��Ŀ��λ����Ϣ*/
  vm_phb_contact_struct* contact_ptr;   /*�绰����Ŀ����ָ�룬�ص������Ὣ��ָ�뷵�ظ��ͻ��ˣ�����д���е���Ϣ����*/
} vm_phb_get_req_struct;

/**
 *	���ҵ绰����Ŀ�������ݽṹ
 */
typedef struct {
  VMWCHAR pattern_ucs2[VM_PHB_MAX_SEARCH_LENGTH];    /*ƥ���֣�ucs2����*/
  vm_phb_search_type_enum search_type;   /*�������ͣ�Ŀǰֻ֧�����ַ�ʽ�������͵绰*/
  vm_phb_contact_struct* contact_ptr;   /*�绰����Ŀ����ָ�룬�ص������Ὣ��ָ�뷵�ظ��ͻ��ˣ�����д���е���Ϣ����*/
} vm_phb_search_req_struct;


/**
 *	���ҵ绰����Ŀ�б��������ݽṹ
 */
typedef struct {
  VMWCHAR pattern_ucs2[VM_PHB_MAX_SEARCH_LENGTH];   /*ƥ���֣�ucs2����*/
  vm_phb_search_type_enum search_type;    /*�������ͣ�Ŀǰֻ֧�����ַ�ʽ�������͵绰*/
} vm_phb_search_list_req_struct;


/**
 *	�洢�绰��������ṹ
 */
typedef struct vm_phb_info_list_struct{
vm_phb_contact_pos_struct  phb_info;
struct vm_phb_info_list_struct* phb_info_next;
}vm_phb_info_list_struct;

/**
 * ��ӵ绰����Ŀ(���Ҫ��Ӷ�����¼����Ҫ�Ȼص��������غ���ܵ���vm_phb_add_contact���������һ����¼)��
 *
 * @param req_info  ��ӵ绰����Ŀ��Ϣ���������ָ�롣
 *                           �������ݽṹ�а�������Ҫ�����Ŀ��ָ�룬ָ�������Ŀ���ݡ�
 *                           ��ӳɹ���ͨ���ص������õ���Ŀ���ݺ�λ����Ϣ��
 * @param cb		�绰���ص�����ָ�롣
 *
 * @return  	��������Ƿ�ɹ���ֵ�μ�vm_phb_req_error_enum��
 */
vm_phb_req_error_enum vm_phb_add_contact(vm_phb_add_req_struct* req_info,  vm_phb_callback_type cb);

/**
 * ɾ���绰����Ŀ(���Ҫɾ��������¼����Ҫ�Ȼص��������غ���ܵ���vm_phb_delete_contact����ɾ����һ����¼)��
 *
 * @param req_info   ɾ���绰����Ŀ���������ָ�롣
 *                             ����ṹ�а�����Ҫɾ����Ŀ��λ����Ϣ(index:1~sim1�洢�ĵ绰��Ŀ/1~phnoe�洢�ĵ绰��/
 *                             1~sim2e�洢�ĵ绰��;storage:VM_PHB_STORAGE_LOC_SIM/VM_PHB_STORAGE_LOC_PHONE/VM_PHB_STORAGE_LOC_SIM2)��
 * @param cb		�绰���ص�����ָ�롣
 *
 * @return 	��������Ƿ�ɹ���ֵ�μ�vm_phb_req_error_enum��
 */
vm_phb_req_error_enum vm_phb_delete_contact(vm_phb_delete_req_struct* req_info,   vm_phb_callback_type cb);

/**
 * ���µ绰����Ŀ��Ϣ(���Ҫ ���¶�����¼����Ҫ�Ȼص��������غ���ܵ���vm_phb_update_contact���� ������һ����¼)��
 *
 * @param req_info   ���µ绰����Ŀ��Ϣ���������ָ�롣
 *                            ����ṹ�а�����Ҫ������Ŀ��λ����Ϣ(index:1~sim1�洢�ĵ绰��Ŀ/1~phnoe�洢�ĵ绰��/
 *                             1~sim2e�洢�ĵ绰��;storage:VM_PHB_STORAGE_LOC_SIM/VM_PHB_STORAGE_LOC_PHONE/VM_PHB_STORAGE_LOC_SIM2)��
 *@param cb		�绰���ص�����ָ�롣
 *
 * @return 	��������Ƿ�ɹ���ֵ�μ�vm_phb_req_error_enum�� 
 */
vm_phb_req_error_enum vm_phb_update_contact(vm_phb_update_req_struct* req_info,  vm_phb_callback_type cb);

/**
 * ���ҵ绰����Ŀ,���ֲ��ҷ�ʽ�����ֻ���ʽ(�첽�ӿ�)��
 * ÿ�β���ͨ���ص��������ص�һ�����ϲ�����������Ŀ��Ϣ��
 *
 * @param req_info   ���ҵ绰����Ŀ��Ϣ���������ָ�롣
 *                            �������ݽṹ�а����˲������ͺ�ƥ���֡�
 * @param cb		�绰���ص�����ָ�롣
 *
 * @return 	��������Ƿ�ɹ���ֵ�μ�vm_phb_req_error_enum��
 */
vm_phb_req_error_enum vm_phb_search_contact(vm_phb_search_req_struct* req_info,   vm_phb_callback_type cb);


/**
 * ���ҵ绰����Ŀ��Ϣ��һ��ͨ������pos_array���ط������������м�¼��λ����Ϣ��
 *
 * @param req_info              ���ҵ绰����Ŀ�б����������ָ�롣
 *                                        �������ݽṹ�а����˲������ͺ�ƥ���֡�
 * @param pos_array           �������������м�¼��λ����Ϣ���顣
 * @param post_array_len    ����pos_array����ĳ��ȡ�
 *
 * @VMINT    ���ҵ�������������ֵ>=0��Ϊ��Ŀ����
 */
VMINT vm_phb_search_contact_list(vm_phb_search_list_req_struct* req_info, vm_phb_contact_pos_struct* pos_array, VMINT post_array_len);


/**
 *����λ����Ϣ ��ȡ�绰����Ŀ��Ϣ(�첽�ӿ�)��
 *
 * @param req_info   ��ȡ�绰����Ŀ��Ϣ���������ָ�롣
 *                              �������ݽṹ�а�������Ŀ��λ����Ϣ(index:1~sim1�洢�ĵ绰��Ŀ/1~phnoe�洢�ĵ绰��/
 *                             1~sim2e�洢�ĵ绰��;storage:VM_PHB_STORAGE_LOC_SIM/VM_PHB_STORAGE_LOC_PHONE/VM_PHB_STORAGE_LOC_SIM2)��
 * @param cb		�绰���ص�����ָ�롣
 *
 * @return 	��������Ƿ�ɹ���ֵ�μ�vm_phb_req_error_enum��
 */
vm_phb_req_error_enum vm_phb_get_contact(vm_phb_get_req_struct* req_info,    vm_phb_callback_type cb);


/**
 * ���ҵ绰����Ŀ,���ֲ��ҷ�ʽ�����ֻ���ʽ(ͬ���ӿ�)��
 * ÿ�β���ͨ���ص��������ص�һ�����ϲ�����������Ŀ��Ϣ��
 *
 * @param req_info   ���ҵ绰����Ŀ��Ϣ���������ָ�롣
 *                            �������ݽṹ�а����˲������ͺ�ƥ���֡�
 *
 * @return 	��������Ƿ�ɹ���ֵ�μ�vm_phb_req_error_enum��
 */
vm_phb_req_error_enum vm_phb_search_contact_syn(vm_phb_search_req_struct* req_info);


/**
 *����λ����Ϣ ��ȡ�绰����Ŀ��Ϣ(ͬ���ӿ�)��
 *
 * @param req_info   ��ȡ�绰����Ŀ��Ϣ���������ָ�롣
 *                              �������ݽṹ�а�������Ŀ��λ����Ϣ(index:1~sim1�洢�ĵ绰��Ŀ/1~phnoe�洢�ĵ绰��/
 *                             1~sim2e�洢�ĵ绰��;storage:VM_PHB_STORAGE_LOC_SIM/VM_PHB_STORAGE_LOC_PHONE/VM_PHB_STORAGE_LOC_SIM2)��
 *
 * @return 	��������Ƿ�ɹ���ֵ�μ�vm_phb_req_error_enum��
 */
vm_phb_req_error_enum vm_phb_get_contact_syn(vm_phb_get_req_struct* req_info);


/**
 * ��ȡĳ�洢λ���ϴ洢�绰����������
 *
 * @param storage   �洢��λ�ã�ָ����Ҫ��ȡ�ĸ��洢λ���ϵĵ绰����Ŀ��������
 *                            ֵ�μ�vm_phb_storage_loc_enum��
 *
 * @return 	���ص绰����Ŀ����������
 *                  ����ֵ<0��Ϊ��������
 *                  ����ֵ>=0��Ϊ��Ŀ����
 */
VMINT vm_phb_get_total_contacts(vm_phb_storage_loc_enum storage);

/**
 * ��ȡĳ�洢λ�����Ѵ�绰����Ŀλ����Ϣ��
 *
 *
 * @param pos_array    �����Ѿ�ʹ�õĵ绰����Ŀλ����Ϣ�����顣
 *                                ����Ĵ�С���ɺ���vm_phb_get_used_contacts_count(vm_phb_storage_loc_enum storage)�ķ���ֵ�õ���Ȼ���ٸ��ݷ���ֵ
 *                                ��������Ĵ�С��
 * @param storage		�洢��λ�ã�ָ����Ҫ��ȡ�ĸ��洢λ���ϵĵ绰����Ŀ�Ѿ�ʹ�õ�������
 *                                 ֵ�μ�vm_phb_storage_loc_enum��
 *
 * @return	���ص绰��������Ŀ������
 *                  ����ֵ<0��Ϊ��������
 *                  ����ֵ>=0��Ϊ��Ŀ����
 */
VMINT vm_phb_get_used_contacts(vm_phb_contact_pos_struct* pos_array,  vm_phb_storage_loc_enum storage);

/**
 * ��ȡĳ�洢λ�����Ѵ�绰������Ŀ��
 *
 * @param storage		�洢��λ�ã�ָ����Ҫ��ȡ�ĸ��洢λ���ϵĵ绰����Ŀ�Ѿ�ʹ�õ�������
 *                                 ֵ�μ�vm_phb_storage_loc_enum��  
 *
 * @return	���ص绰��������Ŀ������
 *                  ����ֵ<0��Ϊ��������
 *                  ����ֵ>=0��Ϊ��Ŀ����
 */
VMINT vm_phb_get_used_contacts_count(vm_phb_storage_loc_enum storage);

/**
 * ��ȡ�绰���������
 *
 * @return �ֻ��绰�������������
 *
 */
VMINT vm_phb_get_group_list_count(void);

/**
 * ��ȡ�绰������б����顣
 * 
 * @param group_array             ����б����顣
 * @param group_array_len       ����ĳ��ȡ�
 *
 * @return    ��ȡ�����������
 */
VMINT vm_phb_get_group_list(vm_phb_group_struct* group_array, VMINT  group_array_len);

/**
 * ��ȡ�绰����Ŷ�Ӧ��������
 * 
 * @param   group_id           ���(>=0)(����֧�ֵ�Ϊ0~19)��
 * @param   group_name     �����ַ���ָ�롣
 * @param   len                   �����ַ������ȡ�
 *
 * @return    �Ƿ�ɹ���TRUE=�ɹ��� FALSE=ʧ�ܡ�
 */
VMINT vm_phb_get_group_name_by_id(VMUINT group_id, VMWCHAR*  group_name, VMINT len);

#ifdef __cpluspluss
}
#endif

#endif
