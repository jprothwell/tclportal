#ifndef VMPHONEBOOK_H_
#define VMPHONEBOOK_H_

#ifdef __cplusplus
extern "C" {
#endif
#include "vmsys.h"

#define VM_PHB_MAX_SEARCH_LENGTH 60      /* 搜索字长度限制*/

typedef enum {	
	VM_PHB_REQ_NOT_READY = -2,   /*电话本系统未就绪*/
	VM_PHB_REQ_ERROR,                   /*操作请求错误*/
	VM_PHB_REQ_NO_ERROR             /*操作请求成功*/
}vm_phb_req_error_enum;

typedef enum {
VM_PHB_NAME_MODIFIED = 1,      
VM_PHB_NO_ERROR = 0,       /* 操作请求成功 */
VM_PHB_ERROR = -1,       /* 操作请求失败 */
VM_PHB_NOT_READY = -2,       /* 电话本系统未就绪*/
VM_PHB_NUM_NOT_READY = -3,       /* 电话本搜索未就绪*/
VM_PHB_NOT_SUPPORT = -4,       /* 电话本系统不支持*/
VM_PHB_NOT_FOUND = -5,       /* 没有发现条目*/
VM_PHB_DATAMGR_BUSY = -6,       /* 电话本系统正忙*/
VM_PHB_STORAGE_FULL = -7,       /* 容量已满*/
VM_PHB_NO_SIM_CARD = -8,       /* 无sim卡*/
VM_PHB_ADN_FORBID = -9,       /* sim卡电话本访问失败 */
VM_PHB_OUT_OF_INDEX = -10,       /* 无效序号*/
VM_PHB_NUMBER_TOO_LONG = -11,       /* 无效电话号码*/
VM_PHB_BIRTHDAY_ERROR = -12      /* 无效生日格式*/
} vm_phb_error_enum;

/**
 *	电话本存储位置的枚举
 */
typedef enum {
  VM_PHB_STORAGE_LOC_SIM = 1,  /*SIM卡电话本*/
  VM_PHB_STORAGE_LOC_PHONE,  /*手机电话本*/
  VM_PHB_STORAGE_LOC_SIM2,    /*SIM2卡电话本*/
  VM_PHB_STORAGE_LOC_BOTH   /*包括以上位置的电话本*/
} vm_phb_storage_loc_enum;

/**
 *	电话本搜索类型枚举
 */
typedef enum {
  VM_PHB_SEARCH_TYPE_NAME,  /*按姓名查找*/
  VM_PHB_SEARCH_TYPE_NUM  /*按电话号码查找*/
} vm_phb_search_type_enum;

/**
 *	电话本条目所处存储位置及索引序号的数据结构
 */
typedef struct
{
    VMUSHORT index;              /*不会因为删除一条记录，而改变其他记录的index*/              
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
 *	电话本条目信息的数据结构。
 *    文字信息都以UCS2编码。
 */
typedef struct {
  vm_phb_contact_pos_struct pos;        /*条目所处的存储位置及序号信息*/
  VMUWCHAR name[VM_MAX_PHB_NAME_LENGTH + 1];    /*姓名*/
  VMUWCHAR number[VM_MAX_PHB_NUMBER_LENGTH +1 + 1];    /*电话号码*/
  VMUWCHAR home_number[VM_MAX_PHB_NUMBER_LENGTH + 1 + 1];    /*家庭电话号码*/
  VMUWCHAR office_number[VM_MAX_PHB_NUMBER_LENGTH + 1 + 1];    /*办公电话号码*/
  VMUWCHAR fax_number[VM_MAX_PHB_NUMBER_LENGTH + 1 + 1];    /*传真号码*/
  VMUWCHAR email_address[VM_MAX_PHB_EMAIL_LENGTH + 1];    /*电子邮件地址1*/
  VMUWCHAR email_address2[VM_MAX_PHB_EMAIL_LENGTH + 1];    /*电子邮件地址2*/
  VMUWCHAR company_name[VM_MAX_PHB_COMPANY_LENGTH + 1];    /*公司名字*/
  VMUCHAR birth_day;    /*生日天*/
  VMUCHAR birth_mon;    /*生日月*/
  VMUINT16 birth_year;    /*生日年*/
  VMUWCHAR title[VM_MAX_PHB_TITLE_LENGTH + 1];    /*标题*/
  VMUWCHAR url[VM_MAX_PHB_URL_LENGTH + 1];    /*网址*/
  VMUWCHAR adr_pobox[VM_MAX_PHB_ADDRESS_LENGTH + 1];    /*邮箱*/
  VMUWCHAR adr_extension[VM_MAX_PHB_ADDRESS_LENGTH + 1];    /*延伸地址*/
  VMUWCHAR adr_street[VM_MAX_PHB_ADDRESS_LENGTH + 1];    /*街道*/
  VMUWCHAR adr_city[VM_MAX_PHB_ADDRESS_LENGTH + 1];    /*市*/
  VMUWCHAR adr_state[VM_MAX_PHB_ADDRESS_LENGTH + 1];    /*州、省*/
  VMUWCHAR adr_postal_code[VM_MAX_PHB_ADDRESS_LENGTH + 1];    /*邮编*/
  VMUWCHAR adr_country[VM_MAX_PHB_ADDRESS_LENGTH + 1];    /*国家*/
  VMUWCHAR note[VM_MAX_PHB_NOTE_LENGTH + 1];    /*注释*/
 VMUINT  group_mask;       /*组位，表明需要加入的群组(可以加入多个群组)*/   /* group_mask = (1<< group_id1) + (1<< group_id2) + ...*/         /*如group_mask=1,则加入的group_id=0；如group_mask=3,则加入的group_id=0 和group_id=1*/
                                                   /* group_mask& (1<<VM_MAX_PHB_GROUP_NAME_LENGTH -1)    得到的二进制结果出现1 的位置就是group id的值*/
} vm_phb_contact_struct;

typedef struct {
	VMUINT group_id;
	VMWCHAR group_name[VM_MAX_PHB_GROUP_NAME_LENGTH+1];
} vm_phb_group_struct;


/**
 *	电话本回调函数的类型定义。
 *
 *    @param result   操作结果，请参考vm_phb_error_enum。
 *    @param contact_ptr   电话本条目信息数据指针。
 *                                    该数据结构指针为发起请求时作为请求数据结构一部分传入的。
 */
typedef void (* vm_phb_callback_type)(VMINT result, vm_phb_contact_struct* contact_ptr);

/**
 *	添加电话本条目请求数据结构
 */
typedef struct {
  vm_phb_storage_loc_enum storage;     /*需要添加到的存储设备*/  /*1~phnoe_max, 1~sim_max, 1~sim2_max*/
  vm_phb_contact_struct* contact_ptr;   /*电话本条目内容指针，包含需要添加条目的所有信息。
                                                                回调函数会将该指针返回给客户端，并填写位置信息。*/
} vm_phb_add_req_struct;


/**
 *	删除电话本条目请求数据结构
 */
typedef struct {
  vm_phb_contact_pos_struct pos;	/*需要删除的条目的位置信息*/
} vm_phb_delete_req_struct;


/**
 *	更新电话本条目请求数据结构
 */
typedef struct {
  vm_phb_contact_pos_struct pos;    /*需要更新的条目的位置信息*/
  vm_phb_contact_struct* contact_ptr;   /*电话本条目内容指针，包含需要添加条目的所有信息。
                                                                回调函数会将该指针返回给客户端*/
} vm_phb_update_req_struct;


/**
 *	获取电话本条目请求数据结构
 */
typedef struct {
  vm_phb_contact_pos_struct pos;   /*需要获取条目的位置信息*/
  vm_phb_contact_struct* contact_ptr;   /*电话本条目内容指针，回调函数会将该指针返回给客户端，并填写所有的信息内容*/
} vm_phb_get_req_struct;

/**
 *	查找电话本条目请求数据结构
 */
typedef struct {
  VMWCHAR pattern_ucs2[VM_PHB_MAX_SEARCH_LENGTH];    /*匹配字，ucs2编码*/
  vm_phb_search_type_enum search_type;   /*查找类型，目前只支持两种方式，姓名和电话*/
  vm_phb_contact_struct* contact_ptr;   /*电话本条目内容指针，回调函数会将该指针返回给客户端，并填写所有的信息内容*/
} vm_phb_search_req_struct;


/**
 *	查找电话本条目列表请求数据结构
 */
typedef struct {
  VMWCHAR pattern_ucs2[VM_PHB_MAX_SEARCH_LENGTH];   /*匹配字，ucs2编码*/
  vm_phb_search_type_enum search_type;    /*查找类型，目前只支持两种方式，姓名和电话*/
} vm_phb_search_list_req_struct;


/**
 *	存储电话本条链表结构
 */
typedef struct vm_phb_info_list_struct{
vm_phb_contact_pos_struct  phb_info;
struct vm_phb_info_list_struct* phb_info_next;
}vm_phb_info_list_struct;

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
vm_phb_req_error_enum vm_phb_add_contact(vm_phb_add_req_struct* req_info,  vm_phb_callback_type cb);

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
vm_phb_req_error_enum vm_phb_delete_contact(vm_phb_delete_req_struct* req_info,   vm_phb_callback_type cb);

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
vm_phb_req_error_enum vm_phb_update_contact(vm_phb_update_req_struct* req_info,  vm_phb_callback_type cb);

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
vm_phb_req_error_enum vm_phb_search_contact(vm_phb_search_req_struct* req_info,   vm_phb_callback_type cb);


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
VMINT vm_phb_search_contact_list(vm_phb_search_list_req_struct* req_info, vm_phb_contact_pos_struct* pos_array, VMINT post_array_len);


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
vm_phb_req_error_enum vm_phb_get_contact(vm_phb_get_req_struct* req_info,    vm_phb_callback_type cb);


/**
 * 查找电话本条目,这种查找方式基于手机方式(同步接口)。
 * 每次查找通过回调函数返回第一个符合查找条件的条目信息。
 *
 * @param req_info   查找电话本条目信息请求的数据指针。
 *                            请求数据结构中包含了查找类型和匹配字。
 *
 * @return 	请求操作是否成功，值参见vm_phb_req_error_enum。
 */
vm_phb_req_error_enum vm_phb_search_contact_syn(vm_phb_search_req_struct* req_info);


/**
 *根据位置信息 获取电话本条目信息(同步接口)。
 *
 * @param req_info   获取电话本条目信息请求的数据指针。
 *                              请求数据结构中包含了条目的位置信息(index:1~sim1存储的电话数目/1~phnoe存储的电话数/
 *                             1~sim2e存储的电话数;storage:VM_PHB_STORAGE_LOC_SIM/VM_PHB_STORAGE_LOC_PHONE/VM_PHB_STORAGE_LOC_SIM2)。
 *
 * @return 	请求操作是否成功，值参见vm_phb_req_error_enum。
 */
vm_phb_req_error_enum vm_phb_get_contact_syn(vm_phb_get_req_struct* req_info);


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
VMINT vm_phb_get_total_contacts(vm_phb_storage_loc_enum storage);

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
VMINT vm_phb_get_used_contacts(vm_phb_contact_pos_struct* pos_array,  vm_phb_storage_loc_enum storage);

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
VMINT vm_phb_get_used_contacts_count(vm_phb_storage_loc_enum storage);

/**
 * 获取电话本组的数量
 *
 * @return 手机电话本中组的数量。
 *
 */
VMINT vm_phb_get_group_list_count(void);

/**
 * 获取电话本组的列表数组。
 * 
 * @param group_array             组的列表数组。
 * @param group_array_len       数组的长度。
 *
 * @return    获取到组的数量。
 */
VMINT vm_phb_get_group_list(vm_phb_group_struct* group_array, VMINT  group_array_len);

/**
 * 获取电话本组号对应的组名。
 * 
 * @param   group_id           组号(>=0)(现在支持的为0~19)。
 * @param   group_name     组名字符串指针。
 * @param   len                   组名字符串长度。
 *
 * @return    是否成功。TRUE=成功， FALSE=失败。
 */
VMINT vm_phb_get_group_name_by_id(VMUINT group_id, VMWCHAR*  group_name, VMINT len);

#ifdef __cpluspluss
}
#endif

#endif
