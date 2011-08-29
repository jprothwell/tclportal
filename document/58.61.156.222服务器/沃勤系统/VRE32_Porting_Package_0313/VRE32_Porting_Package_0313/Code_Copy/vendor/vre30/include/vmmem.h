#ifndef VMMEM_H
#define VMMEM_H

#include "vmsys.h"

#ifdef __cplusplus 
extern "C" {
#endif

/************************************************************************
 *
 *
 *
 * VRE 3.0 ���ķ���CORE�ڴ�ĺ�������Щ��������APP ���š�
 *
 *
 *
 ************************************************************************/
/**
 * VRE��Ҫͳ���ڴ������
 */
#define VRE_ENABLE_MEM_DEBUG

/**
 * �Ƿ�ʹ��DL�㷨����HEAP �ڴ�,��Ϊʹ��,����Ϊ��ʹ��.
 */
#define VRE_ENABLE_DL_HEAP_MANAGER

/**
 * VRE Kernel���ڴ��С����λΪ�ֽڡ�
 */
#define VRE_30_KERNEL_MEM_SIZE					(70 << 10)

/**
 * VRE 2.0���Kernel�ڴ棬��λΪ�ֽڡ�
 */
#define VRE_20_KERNEL_MEM_SIZE					(50 << 10)

/**
 * VRE App�ڴ��ÿһҳ�Ĵ�С����λΪ�ֽڡ�
 */
//#define VRE_APP_SEG_MEM_PAGE_SIZE					(200 << 10)//(400 << 10)

/*
 * Ӧ�ó������ơ�
 */
typedef struct vm_multi_lang_app_name_t {
	VMINT lang_id;								/**<VM_LANG_ENG, VM_LANG_CHS, VM_LANG_CHT 	*/
	VMWSTR app_name;							/**<Ӧ�ó����ļ����ơ� 				*/
	struct vm_multi_lang_app_name_t *next;			/**<��һ�����Ե�Ӧ�ó������ơ� 	*/
} vm_multi_lang_app_name_t;

/**
 * �ڴ���ƿ顣
 */
typedef struct vm_mem_control_block_t
{
	VMINT process_handle;
	VMUINT8* mem_base;
    	VMUINT mem_size;
	VMINT hide_flag;
	void (*stop_cb)(void);
	void* adm_id;
	vm_multi_lang_app_name_t* app_name;
#ifdef VRE_ENABLE_MEM_DEBUG
	malloc_stat_t mem_stat;
#endif
} vm_mem_control_block_t;

/**
 * ��ʼ���ڴ�أ��������ֻӦ����VRE������ʱ��
 * ���á�
 * 
 * @return			0���سɹ�����Ϊʧ�ܡ�
 */
VMINT _vm_init_mem_pool(void);

/**
 * ����VRE Kernel�ڴ棬���ҽ��·��䵽���ڴ���0��
 *
 * @param size			Ҫ������ֽ�����
 *
 * @return				���ط��䵽���ڴ�ָ�룬����NULL��ʾ����ʧ�ܡ�
 */
void* _vm_kernel_malloc(VMINT size);

/**
 * ���·���VRE Kernal�ڴ棬����������ڴ泤��С��ԭ���ڴ泤�ȣ�ϵͳ�����κ�
 * ����������Ѹ������ڴ����󵽸������ȣ��ڴ��е����ݼ���������
 *
 * @param p				Ҫ���·�����ڴ�ָ�롣
 * @param size			�µĳ��ȡ�
 *
 * @return				����NULL��ʾ���·���ʧ�ܣ��������ڴ�ָ��
 *						ָ����ڴ治�ͷţ����򷵻���չ����ڴ�
 *						ָ�롣
 */
void* _vm_kernel_realloc(void* p, VMINT size);

/**
 * �������VRE Kernal�ڴ棬���ҽ��·��䵽���ڴ���0��
 *
 * @param size			Ҫ������ֽ�����
 *
 * @return				���ط��䵽���ڴ�ָ�룬����NULL��ʾ����ʧ�ܡ�
 */
void* _vm_kernel_calloc(VMINT size);

/**
 * �ͷ�VRE Kernel�ڴ档
 *
 * @param ptr			���ͷŵ��ڴ�ָ�룬������vm_malloc()�����䡣
 */
void _vm_kernel_free(void* ptr);

/**
 * ���ֻ���ǰ��ָ�������봫���APPID���õ�Ӧ�ó�������ơ�
 * 
 * 
 * @param[in]				native_app_id Ӧ�ó���ID��
 * @param[in]				lang_id Ϊ����ID ��ʾΪVM_LANG_ENG��VM_LANG_CHS��VM_LANG_CHT��
 */
VMWSTR _vm_get_mem_app_name(VMINT native_app_id, VMINT lang_id);

/*
 * �����ָ�����̵��ڴ�ռ䣬������ֻ���ɽ��̹��������á�
 * 
 * @param[in]				processHandle ���̵�ID��
 * @param[in]				appName ���ڴ治��ʱ��ʾ���ļ����ơ�
 * @param[in]				size ��Ҫ������ڴ�ռ�Ĵ�С����λΪ�ֽڡ�
 * @param[in]				flag TRUE ��ʾ��Ҫ���أ�FALSE��ʾ����Ҫ���ء�
 */
void* _vm_alloc_app_seg_mem(VMINT processHandle, vm_multi_lang_app_name_t* appName, VMINT size, VMINT hideFlag);

/*
 * �����ͷ��ڴ�ĵ��������û�ѡ���ͷ��ڴ档
 * 
 * @param[in]				memSize ������Ҫ������ڴ档
 * @param[in]				successCallback ���û�ѡ����ֹͣĳ��Ӧ�ú���callback�����ĺ�����
 * @param[in]				isSysProcess �Ƿ���ϵͳ���̡�
 */
void _vm_prompt_to_release_mem(VMUINT memSize, void (*successCallback)(void), VMINT isSysProcess);

/**
 * ���øý��̵�HEAP���򣬱�����ֻ���ɽ��̹��������á�
 * 
 * @param[in]				processHandle ���̾����
 * @param[in]				heapBase �ý���HEAP����Ļ�ַ��
 * @param[in]				heapSize �ý���HEAP����Ĵ�С��
 *
 * @return 				0��ʾ���óɹ�������Ϊʧ�ܡ�
 */
VMINT _vm_set_app_heap_attr_mem(VMINT processHandle, VMUINT8* heapBase, VMINT heapSize);

/**
 * ��ѯ �û����̶��� ����ܹ�װ�ص��û���������
 * 
 * @return ���ڵ���0�� ����
 */
VMUINT _vm_query_app_num_mem(void);

/**
 * �ͷŸý���ռ�õ������ڴ棬������ֻ���ɽ��̹��������á�
 * 
 * @param[in]				processHandle ���̾����
 */
void _vm_free_app_seg_mem(VMINT processHandle);

/**
 * ��ѯ�û����̶������������Ŀ����ڴ��Ĵ�С��
 * 
 * @return				�û����̶������������Ŀ����ڴ��Ĵ�С,
 *						��λΪ�ֽڡ�
 */
VMUINT _vm_get_app_seg_free_space(void);

#ifdef __cplusplus
}
#endif

#endif

