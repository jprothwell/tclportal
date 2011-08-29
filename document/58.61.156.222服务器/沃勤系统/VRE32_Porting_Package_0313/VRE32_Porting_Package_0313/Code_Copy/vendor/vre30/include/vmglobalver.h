#ifndef __VM_GLOBALVER__
#define __VM_GLOBALVER__
#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"


#define VRE_GLOBAL_VERSION


#define VRE_MAX_GPRS_USER_NAME_LEN  16   
#define VRE_MAX_GPRS_PASSWORD_LEN   16
#define VRE_MAX_GPRS_APN_LEN    32




enum{
	VM_DEFAULT_ENGLISH_LANGUAGE = 0,
	VM_CHINA_SIMPLE_LANGUAGE,
	VM_CHINA_TRAD_LANGUAGE,
	VM_ENGLISH_LANGUAGE,
	VM_VIETNAMESE_LANGUAGE,
	VM_THAILAND_LANGUAGE,
	VM_INDONESIA_LANGUAGE,
	VM_MALAYSIA_LANGUAGE,
	VM_HINDI_LANGUAGE,
    VM_TURKEY_LANGUAGE,
    VM_RUSSIA_LANGUAGE,
	VM_ARABIAN_LANGUAGE,
    VM_IRAN_LANGUAGE,
    VM_PORTUGUESE_LANGUAGE,
	VM_TOTAL_LANGUAGE
};

typedef struct  
{
	VMINT	    proxy_port;
	VMSTR       operator_id;
	VMSTR       operator_name;
	VMSTR       proxy_ip;
	VMSTR       apn_proxy;
	VMSTR       apn_no_proxy;
	VMSTR       wap_user_name;
	VMSTR       wap_pass_word;
	VMSTR       net_user_name;
	VMSTR       net_pass_word;    
}vm_apn_info_internal;


typedef struct  
{
	VMINT		apn_info_id;
	VMINT	    proxy_port;
	VMCHAR      operator_id[8];
	VMCHAR      operator_name[64];
	VMCHAR      proxy_ip[16];
	VMCHAR      apn_proxy[VRE_MAX_GPRS_APN_LEN];
	VMCHAR      apn_no_proxy[VRE_MAX_GPRS_APN_LEN];
	VMCHAR      wap_user_name[VRE_MAX_GPRS_USER_NAME_LEN];
	VMCHAR      wap_pass_word[VRE_MAX_GPRS_PASSWORD_LEN];
	VMCHAR      net_user_name[VRE_MAX_GPRS_USER_NAME_LEN];
	VMCHAR      net_pass_word[VRE_MAX_GPRS_PASSWORD_LEN];    
}vm_apn_info;

typedef vm_apn_info vm_apn_info_ext; 


typedef enum
{
    VM_APN_NOT_FIND_SIM_CARD = -6,
	VM_APN_NOT_FOUND_RECORD = -5,
	VM_APN_WRITE_NVRAM_ERROR,
	VM_APN_READ_NVRAM_ERROR,
	VM_APN_NOT_EQUAL,
	VM_APN_INTERNAL_ERROR,
	VM_APN_OK,
	VM_APN_USE_NVRAM_RECORD,
	VM_APN_NO_IN_NATIVE_LIST,
	VM_APN_ONLY_WAP_IN_NATIVE_LIST,
	VM_APN_ONLY_WAP_IN_NATIVE_LIST_LAST,
	VM_APN_ONLY_NET_IN_NATIVE_LIST,
	VM_APN_ONLY_NET_IN_NATIVE_LIST_LAST,
	VM_APN_ALL_IN_NATIVE_LIST
}vm_apn_result;



 

typedef struct
{
 VMINT     local_info_id;
 VMINT lang;
 VMCHAR     mcc[4];
 VMCHAR     provision_addr[512]; 
}vm_local_info;

VMINT vm_get_local_setting_for_app(vm_local_info  *current_local_info);

VMINT vm_get_local_setting(vm_local_info *current_local_info);

VMINT vm_get_current_apn(vm_apn_info *current_apn_info);

VMINT vm_set_payment_info(void);

VMINT vm_get_apn_info(vm_apn_info_ext *current_apn_info);




#ifdef __cplusplus
}
#endif
#endif
