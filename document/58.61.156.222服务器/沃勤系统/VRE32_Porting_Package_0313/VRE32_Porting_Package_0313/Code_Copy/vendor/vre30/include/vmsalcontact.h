#ifndef VMPHONEBOOKSAL_H_
#define VMPHONEBOOKSAL_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "vmcontact.h"


/**
 * 添加电话本条目(如果要添加多条记录，需要等回调函数返回后才能调用vm_phb_add_contact函数添加下一条记录)。
 *
 * @param req_info  添加电话本条目信息请求的数据指针。
 *                           请求数据结构中包含了需要添加条目的指针，指向具体条目内容。
 *                           添加成功后，通过回调函数得到条目内容和位置信息。
 * @param cb		电话本回调函数指针。
 *
 * @return  	请求操作是否成功，值参见vm_phb_req_error_enum。
 */
vm_phb_req_error_enum vm_sal_phb_add_contact(vm_phb_add_req_struct* req_info,  vm_phb_callback_type cb);

/**
 * 删除电话本条目(如果要删除多条记录，需要等回调函数返回后才能调用vm_phb_delete_contact函数删除下一条记录)。
 *
 * @param req_info   删除电话本条目请求的数据指针。
 *                             请求结构中包含需要删除条目的位置信息(index:1~sim1存储的电话数目/1~phnoe存储的电话数/
 *                             1~sim2e存储的电话数;storage:VM_PHB_STORAGE_LOC_SIM/VM_PHB_STORAGE_LOC_PHONE/VM_PHB_STORAGE_LOC_SIM2)。
 * @param cb		电话本回调函数指针。
 *
 * @return 	请求操作是否成功，值参见vm_phb_req_error_enum。
 */
vm_phb_req_error_enum vm_sal_phb_delete_contact(vm_phb_delete_req_struct* req_info,   vm_phb_callback_type cb);

/**
 * 更新电话本条目信息(如果要 更新多条记录，需要等回调函数返回后才能调用vm_phb_update_contact函数 更新下一条记录)。
 *
 * @param req_info   更新电话本条目信息请求的数据指针。
 *                            请求结构中包含需要更新条目的位置信息(index:1~sim1存储的电话数目/1~phnoe存储的电话数/
 *                             1~sim2e存储的电话数;storage:VM_PHB_STORAGE_LOC_SIM/VM_PHB_STORAGE_LOC_PHONE/VM_PHB_STORAGE_LOC_SIM2)。
 *@param cb		电话本回调函数指针。
 *
 * @return 	请求操作是否成功，值参见vm_phb_req_error_enum。 
 */
vm_phb_req_error_enum vm_sal_phb_update_contact(vm_phb_update_req_struct* req_info,  vm_phb_callback_type cb);

/**
 * 查找电话本条目,这种查找方式基于手机方式(异步接口)。
 * 每次查找通过回调函数返回第一个符合查找条件的条目信息。
 *
 * @param req_info   查找电话本条目信息请求的数据指针。
 *                            请求数据结构中包含了查找类型和匹配字。
 * @param cb		电话本回调函数指针。
 *
 * @return 	请求操作是否成功，值参见vm_phb_req_error_enum。
 */
vm_phb_req_error_enum vm_sal_phb_search_contact(vm_phb_search_req_struct* req_info,   vm_phb_callback_type cb);


/**
 * 查找电话本条目信息，一次通过参数pos_array返回符合条件的所有记录的位置信息。
 *
 * @param req_info              查找电话本条目列表请求的数据指针。
 *                                        请求数据结构中包含了查找类型和匹配字。
 * @param pos_array           符合条件的所有记录的位置信息数组。
 * @param post_array_len    参数pos_array数组的长度。
 *
 * @VMINT    查找到的数量，返回值>=0，为条目数。
 */
VMINT vm_sal_phb_search_contact_list(vm_phb_search_list_req_struct* req_info, vm_phb_contact_pos_struct* pos_array, VMINT post_array_len);


/**
 *根据位置信息 获取电话本条目信息(异步接口)。
 *
 * @param req_info   获取电话本条目信息请求的数据指针。
 *                              请求数据结构中包含了条目的位置信息(index:1~sim1存储的电话数目/1~phnoe存储的电话数/
 *                             1~sim2e存储的电话数;storage:VM_PHB_STORAGE_LOC_SIM/VM_PHB_STORAGE_LOC_PHONE/VM_PHB_STORAGE_LOC_SIM2)。
 * @param cb		电话本回调函数指针。
 *
 * @return 	请求操作是否成功，值参见vm_phb_req_error_enum。
 */
vm_phb_req_error_enum vm_sal_phb_get_contact(vm_phb_get_req_struct* req_info,  vm_phb_callback_type cb);


/**
 * 查找电话本条目,这种查找方式基于手机方式(同步接口)。。
 * 每次查找通过回调函数返回第一个符合查找条件的条目信息。
 *
 * @param req_info   查找电话本条目信息请求的数据指针。
 *                            请求数据结构中包含了查找类型和匹配字。
 * @param cb		电话本回调函数指针。
 *
 * @return 	请求操作是否成功，值参见vm_phb_req_error_enum。
 */
vm_phb_req_error_enum vm_sal_phb_search_contact_syn(vm_phb_search_req_struct* req_info);


/**
 *根据位置信息 获取电话本条目信息(同步方式)。
 *
 * @param req_info   获取电话本条目信息请求的数据指针。
 *                              请求数据结构中包含了条目的位置信息(index:1~sim1存储的电话数目/1~phnoe存储的电话数/
 *                             1~sim2e存储的电话数;storage:VM_PHB_STORAGE_LOC_SIM/VM_PHB_STORAGE_LOC_PHONE/VM_PHB_STORAGE_LOC_SIM2)。
 *
 * @return 	请求操作是否成功，值参见vm_phb_req_error_enum。
 */
 
vm_phb_req_error_enum vm_sal_phb_get_contact_syn(vm_phb_get_req_struct* req_info);

/**
 * 获取某存储位置上存储电话的总容量。
 *
 * @param storage   存储的位置，指出需要获取哪个存储位置上的电话本条目的容量。
 *                            值参见vm_phb_storage_loc_enum。
 *
 * @return 	返回电话本条目容量总数。
 *                  返回值<0，为操作错误，
 *                  返回值>=0，为条目数。
 */
VMINT vm_sal_phb_get_total_contacts(vm_phb_storage_loc_enum storage);

/**
 * 获取某存储位置上已存电话的条目位置信息。
 *
 *
 * @param pos_array    返回已经使用的电话本条目位置信息的数组。
 *                                数组的大小先由函数vm_phb_get_used_contacts_count(vm_phb_storage_loc_enum storage)的返回值得到，然后再根据返回值
 *                                申请数组的大小。
 * @param storage		存储的位置，指出需要获取哪个存储位置上的电话本条目已经使用的数量。
 *                                 值参见vm_phb_storage_loc_enum。
 *
 * @return	返回电话本已用条目总数。
 *                  返回值<0，为操作错误，
 *                  返回值>=0，为条目数。
 */
VMINT vm_sal_phb_get_used_contacts(vm_phb_contact_pos_struct* pos_array,  vm_phb_storage_loc_enum storage);

/**
 * 获取某存储位置上已存电话的总数目。
 *
 * @param storage		存储的位置，指出需要获取哪个存储位置上的电话本条目已经使用的数量。
 *                                 值参见vm_phb_storage_loc_enum。  
 *
 * @return	返回电话本已用条目总数。
 *                  返回值<0，为操作错误，
 *                  返回值>=0，为条目数。
 */
VMINT vm_sal_phb_get_used_contacts_count(vm_phb_storage_loc_enum storage);

/**
 * 获取电话本组的数量
 *
 * @return 手机电话本中组的数量。
 *
 */
VMINT vm_sal_phb_get_group_list_count(void);

/**
 * 获取电话本组的列表数组。
 * 
 * @param group_array             组的列表数组。
 * @param group_array_len       数组的长度。
 *
 * @return    获取到组的数量。
 */
VMINT vm_sal_phb_get_group_list(vm_phb_group_struct* group_array, VMINT  group_array_len);

/**
 * 获取电话本组号对应的组名。
 * 
 * @param   group_id           组号。
 * @param   group_name     组名字符串指针。
 * @param   len                   组名字符串长度。
 *
 * @return    是否成功。TRUE=成功， FALSE=失败。
 */
VMINT vm_sal_phb_get_group_name_by_id(VMUINT group_id, VMWCHAR*  group_name, VMINT len);


#ifdef __cplusplus
}
#endif

#endif
