#ifndef VMPHONEBOOKSAL_H_
#define VMPHONEBOOKSAL_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "vmcontact.h"


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
vm_phb_req_error_enum vm_sal_phb_add_contact(vm_phb_add_req_struct* req_info,  vm_phb_callback_type cb);

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
vm_phb_req_error_enum vm_sal_phb_delete_contact(vm_phb_delete_req_struct* req_info,   vm_phb_callback_type cb);

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
vm_phb_req_error_enum vm_sal_phb_update_contact(vm_phb_update_req_struct* req_info,  vm_phb_callback_type cb);

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
vm_phb_req_error_enum vm_sal_phb_search_contact(vm_phb_search_req_struct* req_info,   vm_phb_callback_type cb);


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
VMINT vm_sal_phb_search_contact_list(vm_phb_search_list_req_struct* req_info, vm_phb_contact_pos_struct* pos_array, VMINT post_array_len);


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
vm_phb_req_error_enum vm_sal_phb_get_contact(vm_phb_get_req_struct* req_info,  vm_phb_callback_type cb);


/**
 * ���ҵ绰����Ŀ,���ֲ��ҷ�ʽ�����ֻ���ʽ(ͬ���ӿ�)����
 * ÿ�β���ͨ���ص��������ص�һ�����ϲ�����������Ŀ��Ϣ��
 *
 * @param req_info   ���ҵ绰����Ŀ��Ϣ���������ָ�롣
 *                            �������ݽṹ�а����˲������ͺ�ƥ���֡�
 * @param cb		�绰���ص�����ָ�롣
 *
 * @return 	��������Ƿ�ɹ���ֵ�μ�vm_phb_req_error_enum��
 */
vm_phb_req_error_enum vm_sal_phb_search_contact_syn(vm_phb_search_req_struct* req_info);


/**
 *����λ����Ϣ ��ȡ�绰����Ŀ��Ϣ(ͬ����ʽ)��
 *
 * @param req_info   ��ȡ�绰����Ŀ��Ϣ���������ָ�롣
 *                              �������ݽṹ�а�������Ŀ��λ����Ϣ(index:1~sim1�洢�ĵ绰��Ŀ/1~phnoe�洢�ĵ绰��/
 *                             1~sim2e�洢�ĵ绰��;storage:VM_PHB_STORAGE_LOC_SIM/VM_PHB_STORAGE_LOC_PHONE/VM_PHB_STORAGE_LOC_SIM2)��
 *
 * @return 	��������Ƿ�ɹ���ֵ�μ�vm_phb_req_error_enum��
 */
 
vm_phb_req_error_enum vm_sal_phb_get_contact_syn(vm_phb_get_req_struct* req_info);

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
VMINT vm_sal_phb_get_total_contacts(vm_phb_storage_loc_enum storage);

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
VMINT vm_sal_phb_get_used_contacts(vm_phb_contact_pos_struct* pos_array,  vm_phb_storage_loc_enum storage);

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
VMINT vm_sal_phb_get_used_contacts_count(vm_phb_storage_loc_enum storage);

/**
 * ��ȡ�绰���������
 *
 * @return �ֻ��绰�������������
 *
 */
VMINT vm_sal_phb_get_group_list_count(void);

/**
 * ��ȡ�绰������б����顣
 * 
 * @param group_array             ����б����顣
 * @param group_array_len       ����ĳ��ȡ�
 *
 * @return    ��ȡ�����������
 */
VMINT vm_sal_phb_get_group_list(vm_phb_group_struct* group_array, VMINT  group_array_len);

/**
 * ��ȡ�绰����Ŷ�Ӧ��������
 * 
 * @param   group_id           ��š�
 * @param   group_name     �����ַ���ָ�롣
 * @param   len                   �����ַ������ȡ�
 *
 * @return    �Ƿ�ɹ���TRUE=�ɹ��� FALSE=ʧ�ܡ�
 */
VMINT vm_sal_phb_get_group_name_by_id(VMUINT group_id, VMWCHAR*  group_name, VMINT len);


#ifdef __cplusplus
}
#endif

#endif
