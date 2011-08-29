#ifndef VMSM_H_
#define VMSM_H_

#include "vmsys.h"
#include "vmdl.h"

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************/

/**
 * VRE Billing Engine Shared Module in ROM
 */
//#define VRE_BESM_IN_ROM

/**
 * Search all SMs in removable & phone memory and compare their versions while loading.
 * The newest one will be loaded.
 */
#define VRE_SM_LOAD_VER_CMP

/**
 * System messages of SM.
 */

 /*
  * SM is being loaded.
  */
#define VM_SM_MSG_LOAD 		(1)

 /*
  * Invoker is querying for entries of SM API.
  */
#define VM_SM_MSG_QUERY		(5)

 /*
  * SM is being unloaded.
  */
#define VM_SM_MSG_UNLOAD 		(9)


/**
 * Definitions of SM's return value
 */

#define VM_SM_SUCCESS 						(0)	 	/* SM operation success */
#define VM_SM_FAILED 						(-1)		/* SM operation failed */
#define VM_SM_PARAM_ERROR 				(-2)		/* SM parameter error */
#define VM_SM_FILE_NOT_FOUND 				(-3)		/* SM file not found */
#define VM_SM_INVALID_INVOKER 				(-4)		/* SM invalid invoker */
#define VM_SM_CREATE_FAILED 				(-5)		/* SM failed to create pcb */
#define VM_SM_CREATE_COPY_FAILED 			(-6)		/* SM failed to create copy */
#define VM_SM_MSG_FAILED 					(-7) 	/* SM failed to handle messages */
#define VM_SM_NAME_MISMATCH 				(-8) 	/* SM name mis-match with name in file tag */

/************************************************************************/

/* SM flag to identify PCB's type */
enum {
	VRE_APP = 0,
	VRE_SM
};


typedef struct _vm_sm_info_t {
	VMCHAR version[6];
} vm_sm_info_t;

/**
 * ��ѯָ��SM ���Ƶ�INFO ��Ϣ��
 * 
 * @code
 * vm_sm_info_t sm_info;
 * if (vm_sm_query_info("smbilling", sm_info) == SM_SUCCESS)
 * {
 * 	sm_info.version
 * }
 * @endcode
 *  
 * @param[in] 	sm_name	SM�ļ�����ASCII���롣
 * @param[out] 	sm_info		���ڻ�ȡSM info��Ϣ�Ľṹ�塣
 *							��ѯ�ɹ�ʱ�ṹ���и���Ա�ᱻ��ֵ��
 *							��ѯʧ��ʱ�ṹ���и���Ա���ᱻ��ֵ��
 * 
 * @return		��ѯ���:
 * @retval		SM_SUCCESS 	�ɹ�
 * @retval		SM_FAILED 		ʧ��
**/
VMINT vm_sm_query_info(VMSTR sm_name, vm_sm_info_t * sm_info);



/************************************************************************/

extern VMUINT _get_vre_sym_entry(void);
#define VRE_ENTRY ((vm_get_sym_entry_t)_get_vre_sym_entry())

/* print log in vre.log */
typedef void(*_vm_log_vre_t)(char* fmt, ...);
#ifndef WIN32
#define vm_log_vre(...) ((_vm_log_vre_t)VRE_ENTRY("_vm_log_debug"))(__VA_ARGS__)
#endif

/* Definitions for explicit SM invoking */

typedef void (*void_void_t)(void);
typedef VMINT (*int_void_t)(void);
typedef VMINT (*int_int_t)(VMINT);

/* Macros for SM */

#define SM_PROCESS_BEGIN() {\
	vm_get_sym_entry_t vre_entry = VRE_ENTRY;	\
	if (((int_int_t)vre_entry("vm_sm_set_sb_by_ptr"))((VMINT)handle_smevt) == 0) {

#define SM_PROCESS_RETURN() ((void_void_t)vre_entry("vm_sm_reset_sb"))();

#define SM_PROCESS_END() SM_PROCESS_RETURN() } }

#define SM_CALLBACK_BEGIN() {\
	vm_get_sym_entry_t vre_entry = VRE_ENTRY;	\
	if (((int_void_t)vre_entry("vm_sm_set_sb_for_invoker"))() == 0) { 

#define SM_CALLBACK_END() SM_PROCESS_END()

#define SM_SAFE_CALLBACK(PTR) \
	SM_CALLBACK_BEGIN() \
	PTR; \
	SM_CALLBACK_END()

#define SM_SAFE_CALLBACK_RETURN(PTR, RET) \
	SM_CALLBACK_BEGIN() \
	RET = PTR; \
	SM_CALLBACK_END()

/* Macros for SM STUB */

#define SM_INVOKE_BEGIN(SM)  {\
	vm_get_sym_entry_t vre_entry = VRE_ENTRY;	\
	if (((int_int_t)VRE_ENTRY("vm_sm_set_sb_by_handle"))(SM) == 0) {

#define SM_INVOKE_END() SM_PROCESS_END()

#define SM_SAFE_INVOKE(SM, PTR) \
	SM_INVOKE_BEGIN(SM) \
	PTR; \
	SM_INVOKE_END() 

#define SM_SAFE_INVOKE_RETURN(SM, PTR, RET) \
	SM_INVOKE_BEGIN(SM) \
	RET = PTR; \
	SM_INVOKE_END() 


/************************************************************************/

/* API for SM */

/**
 * ע��SM ��Ϣϵͳ�ص���
 * 
 * @param[in]			smHandler ����SMϵͳ��Ϣ�Ļص�������
 */
void vm_reg_sm_callback(VMINT (*smHandler)(VMINT message, VMINT param));

/**
 * ��ȡ��ǰ�������е�SM�������ļ�·��(UCS2����)��
 * 
 * @param[in]			filename ���Ա���SM�����ļ�·�����ַ������顣
 * 					�ڴ��ɵ����߷��䣬VREֻ����������д�����ݡ�
 *
 * @return			�Ƿ�ɹ���
 * @retval			VM_SM_SUCCESS �ɹ���
 * @retval			VM_SM_FAILED ʧ�ܡ�
 */
VMINT vm_sm_get_filename(VMWSTR filename);

#if 0
/**
 * �ӵ�ǰ�������е�SM�ļ��ж�����Դ��
 * ϵͳ������Դ�ĳ����Զ�Ϊ������ڴ棬Ȼ����ļ����뵽�ڴ�֮�У�
 * ����Ա��ʹ������Դ��������vm_free()�����ͷŵ���
 *
 * @param res_name		��Դ���ƣ�ϵͳ�ڴ��ʱ����Դ�ļ�����Ϊ��Դ���Ʊ��浽
 *						Ŀ���ļ��У��������������Ƕ�Ӧ����Դ�ļ�����·������
 *						����Ҫ����������ͼ����Դ�ļ���"c:\\projects\\game\\1.gif"��
 *						����Դ���ƾ���"1.gif"��
 * @param res_size		���������Դ���ȣ��ֽڵ�λ��
 *
 * @return				������Դ���ݡ�
 */
VMUINT8* vm_sm_load_resource(char *res_name, VMINT *res_size);
#endif 

/************************************************************************/

/* API for SM invoker */

/**
 * װ��SM.
 * 
 * @param[in]			sm_name SM ���ơ�
 * 					sm_name �����ǲ����ļ�·����������չ�����ļ�����
 * 					��"xxx" in "c:\vre\xxx.vsm". ��ʱϵͳ�Զ���T�����ֻ�ϵͳ��
 * 					�е�"vre"Ŀ¼��Ѱ������ƥ���.vsm�ļ���װ�أ�
 * 					T����ϵͳ����ͬʱ����ʱ�����ȼ���T���е��ļ���
 * 					sm_name Ҳ������.vsm�ļ�������·����
 *
 * @code
 * VMINT sm_hdl = vm_sm_load("sm_charge");
 * if (sm_hdl > 0)
 * {
 * 	...
 * }
 * @endcode
 *
 * @return			�ɹ�ʱ����SM�����
 * 					ʧ��ʱ�������´�����:
 * @retval			VM_SM_FAILED ʧ�ܡ�
 * @retval			VM_SM_PARAM_ERROR ��������
 * @retval			VM_SM_FILE_NOT_FOUND �Ҳ����ļ���
 * @retval			VM_SM_INVALID_INVOKER ��Ч�ĵ����ߡ�
 * @retval			VM_SM_CREATE_FAILED ����SMʧ�ܡ�
 * @retval			VM_SM_CREATE_COPY_FAILED ����SM copyʧ�ܡ�
 * @retval			VM_SM_MSG_FAILED SM��Ӧ��Ϣʧ�ܡ�
 * @retval			VM_SM_NAME_MISMATCH SM�������ļ�TAG�е����Ʋ�ƥ�䡣
 */
VMINT vm_sm_load(VMSTR sm_name);

/**
 * ��ȡSM��ָ��API ID�ĺ�����ڵ�ַ��
 * 
 * @param[in]			sm_hdl SM�����
 * 					��vm_sm_load������
 * @param[in]			api_id SM�жԵ����߿��ŵ�API ID��
 * 					��SM�����߶��壬�ṩ��SM��ͷ�ļ��С�
 *
 * @code
 * VMINT sm_hdl = vm_sm_load("sm_charge");
 * func_t func_ptr = NULL;
 * if (sm_hdl > 0)
 * {
 * 	func_ptr = vm_sm_get_func_entry(sm_hdl, id_func);
 * 	if (func_ptr)
 * 	{
 * 		func_ptr(x, y, z);
 * 	}
 * }
 * vm_sm_unload(sm_hdl);
 * @endcode
 *
 * @return			�Ƿ�ɹ���
 * @retval			VM_SM_SUCCESS �ɹ���
 * @retval			VM_SM_FAILED ʧ�ܡ�
 */
VMINT vm_sm_get_func_entry(VMINT sm_hdl, VMINT api_id);

/**
 * ж��SM.
 * 
 * @param[in]			sm_hdl SM�����
 * 					��vm_sm_load������
 *
 * @code
 * VMINT sm_hdl = vm_sm_load("sm_charge");
 * if (sm_hdl > 0)
 * {
 * 	...
 * }
 * vm_sm_unload(sm_hdl);
 * @endcode
 *
 * @return			�Ƿ�ɹ���
 * @retval			VM_SM_SUCCESS �ɹ���
 * @retval			VM_SM_FAILED ʧ�ܡ�
 */
VMINT vm_sm_unload(VMINT sm_hdl);


/************************************************************************/


#ifdef __cplusplus
}
#endif 
#endif

