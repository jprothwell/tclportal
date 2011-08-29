#ifdef __VRE__
/*******************************************************************
* 内存管理模块，实现与MTK 的内存管理机制的适配。
*
* Author:  Jie.Chen
********************************************************************/
#include "mmi_include.h"
#include "DataAccountGProt.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "gpioInc.h"
#include "SimDetectionGexdcl.h"
#include "DevConfigGprot.h"
#include "vmopt.h"
#include "app_mem.h"
#include "med_main.h"
#include "med_api.h"
#include "vredef.h"
#include "vmenv.h"
#include "vmsys.h"
#include "vmmem.h"
#include "vmpromng.h"
#include "vmlog.h"
#include "vmmullang.h"
/**
 * 1(VRE KERNEL) + 16(SM + APP)
 */
#define MAX_MEM_CONTROL_BLOCK_NUM 			(17)		

/**
 * 全局的配置。
 */
extern mmi_devconfig_system_config_struct sysconf;

/**
 * 内存控制块列表。
 */
static vm_mem_control_block_t mem_control_block[MAX_MEM_CONTROL_BLOCK_NUM];

/***********************************************************
* 应用程序停止的callback。
************************************************************/
static void _vm_stop_app0_callback(void)
{
	extern void vm_exit_by_asm(void);

	if (mem_control_block[0].hide_flag)
	{
		vm_log_error("Error status control block[0].");
	}
	
	vm_exit_by_asm();
	applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_VRE, KAL_TRUE);
}

static void _vm_stop_app1_callback(void)
{
	if (mem_control_block[1].hide_flag)
	{
		vm_log_error("Error status control block[1].");
	}

	vm_pmng_delete_process(mem_control_block[1].process_handle);
	
	if (sysconf.memory_provide == MMI_DEVCONFIG_MEMPEY_PROVIDER_ASM)
	{
		applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_VRE_APP1, KAL_TRUE);
	}
}

static void _vm_stop_app2_callback(void)
{
	if (mem_control_block[2].hide_flag)
	{
		vm_log_error("Error status control block[2].");
	}

	vm_pmng_delete_process(mem_control_block[2].process_handle);
	
	if (sysconf.memory_provide == MMI_DEVCONFIG_MEMPEY_PROVIDER_ASM)
	{
		applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_VRE_APP2, KAL_TRUE);
	}
}

static void _vm_stop_app3_callback(void)
{
	if (mem_control_block[3].hide_flag)
	{
		vm_log_error("Error status control block[3].");
	}

	vm_pmng_delete_process(mem_control_block[3].process_handle);
	
	if (sysconf.memory_provide == MMI_DEVCONFIG_MEMPEY_PROVIDER_ASM)
	{
		applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_VRE_APP3, KAL_TRUE);
	}
}

static void _vm_stop_app4_callback(void)
{
	if (mem_control_block[4].hide_flag)
	{
		vm_log_error("Error status control block[4].");
	}

	vm_pmng_delete_process(mem_control_block[4].process_handle);
	
	if (sysconf.memory_provide == MMI_DEVCONFIG_MEMPEY_PROVIDER_ASM)
	{
		applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_VRE_APP4, KAL_TRUE);
	}
}

static void _vm_stop_app5_callback(void)
{
	if (mem_control_block[5].hide_flag)
	{
		vm_log_error("Error status control block[5].");
	}

	vm_pmng_delete_process(mem_control_block[5].process_handle);
	
	if (sysconf.memory_provide == MMI_DEVCONFIG_MEMPEY_PROVIDER_ASM)
	{
		applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_VRE_APP5, KAL_TRUE);
	}
}

static void _vm_stop_app6_callback(void)
{
	if (mem_control_block[6].hide_flag)
	{
		vm_log_error("Error status control block[6].");
	}

	vm_pmng_delete_process(mem_control_block[6].process_handle);
	
	if (sysconf.memory_provide == MMI_DEVCONFIG_MEMPEY_PROVIDER_ASM)
	{
		applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_VRE_APP6, KAL_TRUE);
	}
}

static void _vm_stop_app7_callback(void)
{
	if (mem_control_block[7].hide_flag)
	{
		vm_log_error("Error status control block[7].");
	}

	vm_pmng_delete_process(mem_control_block[7].process_handle);
	
	if (sysconf.memory_provide == MMI_DEVCONFIG_MEMPEY_PROVIDER_ASM)
	{
		applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_VRE_APP7, KAL_TRUE);
	}
}

static void _vm_stop_app8_callback(void)
{
	if (mem_control_block[8].hide_flag)
	{
		vm_log_error("Error status control block[8].");
	}

	vm_pmng_delete_process(mem_control_block[8].process_handle);
	
	if (sysconf.memory_provide == MMI_DEVCONFIG_MEMPEY_PROVIDER_ASM)
	{
		applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_VRE_APP8, KAL_TRUE);
	}
}

static void _vm_stop_app9_callback(void)
{
	if (mem_control_block[9].hide_flag)
	{
		vm_log_error("Error status control block[9].");
	}

	vm_pmng_delete_process(mem_control_block[9].process_handle);
	
	if (sysconf.memory_provide == MMI_DEVCONFIG_MEMPEY_PROVIDER_ASM)
	{
		applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_VRE_APP9, KAL_TRUE);
	}
}

static void _vm_stop_app10_callback(void)
{
	if (mem_control_block[10].hide_flag)
	{
		vm_log_error("Error status control block[10].");
	}

	vm_pmng_delete_process(mem_control_block[10].process_handle);
	
	if (sysconf.memory_provide == MMI_DEVCONFIG_MEMPEY_PROVIDER_ASM)
	{
		applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_VRE_APP10, KAL_TRUE);
	}
}

static void _vm_stop_app11_callback(void)
{
	if (mem_control_block[11].hide_flag)
	{
		vm_log_error("Error status control block[11].");
	}

	vm_pmng_delete_process(mem_control_block[11].process_handle);
	
	if (sysconf.memory_provide == MMI_DEVCONFIG_MEMPEY_PROVIDER_ASM)
	{
		applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_VRE_APP11, KAL_TRUE);
	}
}

static void _vm_stop_app12_callback(void)
{
	if (mem_control_block[12].hide_flag)
	{
		vm_log_error("Error status control block[12].");
	}

	vm_pmng_delete_process(mem_control_block[12].process_handle);
	
	if (sysconf.memory_provide == MMI_DEVCONFIG_MEMPEY_PROVIDER_ASM)
	{
		applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_VRE_APP12, KAL_TRUE);
	}
}

static void _vm_stop_app13_callback(void)
{
	if (mem_control_block[13].hide_flag)
	{
		vm_log_error("Error status control block[13].");
	}

	vm_pmng_delete_process(mem_control_block[13].process_handle);
	
	if (sysconf.memory_provide == MMI_DEVCONFIG_MEMPEY_PROVIDER_ASM)
	{
		applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_VRE_APP13, KAL_TRUE);
	}
}

static void _vm_stop_app14_callback(void)
{
	if (mem_control_block[14].hide_flag)
	{
		vm_log_error("Error status control block[14].");
	}

	vm_pmng_delete_process(mem_control_block[14].process_handle);
	
	if (sysconf.memory_provide == MMI_DEVCONFIG_MEMPEY_PROVIDER_ASM)
	{
		applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_VRE_APP14, KAL_TRUE);
	}
}

static void _vm_stop_app15_callback(void)
{
	if (mem_control_block[15].hide_flag)
	{
		vm_log_error("Error status control block[15].");
	}

	vm_pmng_delete_process(mem_control_block[15].process_handle);
	
	if (sysconf.memory_provide == MMI_DEVCONFIG_MEMPEY_PROVIDER_ASM)
	{
		applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_VRE_APP15, KAL_TRUE);
	}
}

static void _vm_stop_app16_callback(void)
{
	if (mem_control_block[16].hide_flag)
	{
		vm_log_error("Error status control block[16].");
	}

	vm_pmng_delete_process(mem_control_block[16].process_handle);
	
	if (sysconf.memory_provide == MMI_DEVCONFIG_MEMPEY_PROVIDER_ASM)
	{
		applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_VRE_APP16, KAL_TRUE);
	}
}

#ifdef VRE_ENABLE_DL_HEAP_MANAGER
extern void vm_dl_heap_manager(void);
extern void* vm_dl_heap_seg_create(void* heap_base, VMUINT heap_size);
extern void vm_dl_heap_seg_delete(void* dl_heap_id);
extern void* vm_dl_alloc(void* dl_heap_id, VMINT size, malloc_stat_t* heap_seg_statistic);
extern void vm_dl_free(void* dl_heap_id, void* ptr, malloc_stat_t* heap_seg_statistic);
extern void* vm_dl_realloc(void* dl_heap_id, void* ptr, VMINT size, malloc_stat_t* heap_seg_statistic);
#endif


void *_vm_kernel_malloc(int size)
{
	void *ptr = NULL;

#ifdef VRE_ENABLE_DL_HEAP_MANAGER
	ptr = vm_dl_alloc(mem_control_block[0].adm_id, size, 
  #ifdef VRE_ENABLE_MEM_DEBUG
		&(mem_control_block[0].mem_stat)
  #else
  		NULL
  #endif
		);
#else
	ptr = kal_adm_alloc(mem_control_block[0].adm_id, size);
#endif

	if (ptr == NULL)
	{
		vm_log_warn("[MMNG]Failed(kernel) to malloc memory.free space is = %d", mem_control_block[0].mem_stat.avail_heap_size);
	}

    	return ptr;
}

void *_vm_kernel_calloc(int size)
{
	void* p = _vm_kernel_malloc(size);
	
	if (p != NULL)
	{
		memset(p, 0, size);
	}
		
	return p;
}

void *_vm_kernel_realloc(void *p, VMINT size)
{
	void* ptr = NULL;

#ifdef VRE_ENABLE_DL_HEAP_MANAGER
	ptr = vm_dl_realloc(mem_control_block[0].adm_id, 
		p, size,
  #ifdef VRE_ENABLE_MEM_DEBUG 
		&(mem_control_block[0].mem_stat)
  #else
		NULL
  #endif
		);
#else
    	ptr = _vm_kernel_malloc(size);
    	memcpy(ptr, p, size);
    	_vm_kernel_free(p);
#endif
	
    	return ptr;
}

void _vm_kernel_free(void* ptr)
{
	if (ptr)
	{
#ifdef VRE_ENABLE_DL_HEAP_MANAGER
		vm_dl_free(mem_control_block[0].adm_id, ptr, 
  #ifdef VRE_ENABLE_MEM_DEBUG 
			&(mem_control_block[0].mem_stat)
  #else
  			NULL
  #endif
			);
#else
		kal_adm_free(mem_control_block[0].adm_id, ptr);
#endif
	}
}

extern VMINT vm_pmng_get_current_handle(void);
void *vm_malloc(int size)
{
	VMINT pHandle = vm_pmng_get_current_handle(), i = 0;
	void *ptr = NULL;

	if (pHandle == 0)
	{
		ptr =  _vm_kernel_malloc(size);
	}
	else
	{
		for (i = 1; i < MAX_MEM_CONTROL_BLOCK_NUM; i++)
		{
			if (mem_control_block[i].process_handle == pHandle && mem_control_block[i].adm_id != NULL)
			{
#ifdef VRE_ENABLE_DL_HEAP_MANAGER
				ptr = vm_dl_alloc(mem_control_block[i].adm_id, size, 
  #ifdef VRE_ENABLE_MEM_DEBUG
					&(mem_control_block[i].mem_stat)
  #else
  					NULL
  #endif
				);
#else
				ptr = kal_adm_alloc(mem_control_block[i].adm_id, size);
#endif
				break;
			}
		}
	}

	if (ptr == NULL)
	{
		malloc_stat_t* stat = NULL;

		if ((stat = vm_get_malloc_stat()) == NULL)
		{
			vm_log_warn("[MMNG]Failed to malloc memory");
		}
		else
		{
			vm_log_warn("[MMNG]Failed to malloc memory.free space is = %d", stat->avail_heap_size);
		}
	}

	return ptr;
}

void *vm_calloc(int size)
{
	void* p = vm_malloc(size);
	
	if (p != NULL)
	{
		memset(p, 0, size);
	}
	
	return p;
}

void *vm_realloc(void *p, int size)
{
	void* ptr = NULL;
	
#ifdef VRE_ENABLE_DL_HEAP_MANAGER
	VMINT pHandle = vm_pmng_get_current_handle(), i = 0;

	if (pHandle == 0)
	{
		ptr =  _vm_kernel_realloc(p, size);
	}
	else
	{
		for (i = 1; i < MAX_MEM_CONTROL_BLOCK_NUM; i++)
		{
			if (mem_control_block[i].process_handle == pHandle && mem_control_block[i].adm_id != NULL)
			{
				ptr = vm_dl_realloc(mem_control_block[i].adm_id, p, size,
  #ifdef VRE_ENABLE_MEM_DEBUG 
					&(mem_control_block[i].mem_stat)
  #else
					NULL
  #endif
  					);
  				break;
			}
		}
	}
#else
    	ptr = vm_malloc(size);
    	memcpy(ptr, p, size);
    	vm_free(p);
#endif

    	return ptr;
}

void vm_free(void* ptr)
{
	VMINT pHandle = vm_pmng_get_current_handle(), i = 0;

	if (!ptr)
	{
		return;
	}

	if (pHandle == 0)
	{
		_vm_kernel_free(ptr);
	}
	else
	{
		for (i = 1; i < MAX_MEM_CONTROL_BLOCK_NUM; i++)
		{
			if (mem_control_block[i].process_handle == pHandle && mem_control_block[i].adm_id != NULL)
			{
#ifdef VRE_ENABLE_DL_HEAP_MANAGER
				vm_dl_free(mem_control_block[i].adm_id, ptr, 
  #ifdef VRE_ENABLE_MEM_DEBUG 
					&(mem_control_block[i].mem_stat)
  #else
  					NULL
  #endif
				);
#else
				kal_adm_free(mem_control_block[i].adm_id, ptr);
#endif
				break;
			}
		}
	}
}

VMINT _vm_init_mem_pool(void)
{
	VMINT i = 0;
	
	for (i = 0; i < MAX_MEM_CONTROL_BLOCK_NUM; i++)
	{
		if (mem_control_block[i].mem_base)
		{
			vm_log_error("Memory[%d] don't be freed.", i);
			break;
		}
	}

	memset(mem_control_block, 0x00, sizeof(mem_control_block));
#ifdef VRE_ENABLE_DL_HEAP_MANAGER
	vm_dl_heap_manager();
#endif

	/* Regist stop process callback. */
	mem_control_block[0].stop_cb = _vm_stop_app0_callback;
	mem_control_block[1].stop_cb = _vm_stop_app1_callback;
	mem_control_block[2].stop_cb = _vm_stop_app2_callback;
	mem_control_block[3].stop_cb = _vm_stop_app3_callback;
	mem_control_block[4].stop_cb = _vm_stop_app4_callback;
	mem_control_block[5].stop_cb = _vm_stop_app5_callback;
	mem_control_block[6].stop_cb = _vm_stop_app6_callback;
	mem_control_block[7].stop_cb = _vm_stop_app7_callback;
	mem_control_block[8].stop_cb = _vm_stop_app8_callback;
	mem_control_block[9].stop_cb = _vm_stop_app9_callback;
	mem_control_block[10].stop_cb = _vm_stop_app10_callback;
	mem_control_block[11].stop_cb = _vm_stop_app11_callback;
	mem_control_block[12].stop_cb = _vm_stop_app12_callback;
	mem_control_block[13].stop_cb = _vm_stop_app13_callback;
	mem_control_block[14].stop_cb = _vm_stop_app14_callback;
	mem_control_block[15].stop_cb = _vm_stop_app15_callback;
	mem_control_block[16].stop_cb = _vm_stop_app16_callback;

	return 0;
}

VMWSTR _vm_get_mem_app_name(VMINT native_app_id, VMINT lang_id)
{
	VMINT idx = 0;

	if (sysconf.memory_provide == MMI_DEVCONFIG_MEMPEY_PROVIDER_ASM)
	{
		idx = native_app_id - APPLIB_MEM_AP_ID_VRE;
	}
	else
	{
		idx = native_app_id - MMI_AP_VRE_ID;
	}

	switch (lang_id)
	{
	case ENG:
		lang_id = VM_LANG_ENG;
		break;
	case CHS:
		lang_id = VM_LANG_CHS;
		break;
	case CHT:
		lang_id = VM_LANG_CHT;
		break;
	default:
		lang_id = VM_LANG_ENG;
	}

	vm_log_info("[MMNG]_vm_get_mem_app_name, native_app_id = %d, lang_id= %d, idx = %d", 
		native_app_id, lang_id, idx);
	if (idx >= 0 && idx < MAX_MEM_CONTROL_BLOCK_NUM)
	{
		if (mem_control_block[idx].app_name)
		{
			vm_multi_lang_app_name_t* tmp = mem_control_block[idx].app_name;

			while (tmp)
			{
				if (tmp->lang_id == lang_id)
				{
					vm_log_error("[MMNG]Find lang[%d] app name.", lang_id);
					return tmp->app_name;
				}

				tmp = tmp->next;
			}
		}
	}

	return NULL;
}

void _vm_prompt_to_release_mem(VMUINT memSize, void (*successCallback)(void), VMINT isSysProcess)
{
	if (sysconf.memory_provide == MMI_DEVCONFIG_MEMPEY_PROVIDER_ASM)
	{
		vm_log_info("_vm_prompt_to_release_mem ASM");
		mmi_frm_appmem_prompt_to_release_mem(
			APPLIB_MEM_AP_ID_VRE, IMAGE_VRE_SMALL_ICON, memSize, successCallback);
	}
	else
	{
		vm_log_info("_vm_prompt_to_release_mem MED");
		mmi_ap_prompt_to_release_mem(MMI_AP_VRE_ID, STR_VRE_TITLE, memSize, successCallback);
	}
}

void* _vm_alloc_app_seg_mem(VM_P_HANDLE pHandle, vm_multi_lang_app_name_t* appName, 
	VMINT size, VMINT hideFlag)
{
	VMINT i = 0;

	if (pHandle != 0)
	{
		/* Check pHandle is aleary exists. */
		for (i = 1; i < MAX_MEM_CONTROL_BLOCK_NUM; i++)
		{
			if (mem_control_block[i].process_handle == pHandle)
			{
				vm_log_error("[MEMMNG]Process handle is repeat.");
				return NULL;
			}
		}

		/* Find out empty solt. */
		for (i = 1; i < MAX_MEM_CONTROL_BLOCK_NUM; i++)
		{
			if (mem_control_block[i].mem_base == NULL)
			{
				break;
			}
		}

		/* Not exists empty solt. */
		if (i == MAX_MEM_CONTROL_BLOCK_NUM)
		{
			vm_log_error("[MEMMNG]APP control block is overflow.");
			return NULL;
		}
	}

	if (sysconf.memory_provide == MMI_DEVCONFIG_MEMPEY_PROVIDER_ASM)
	{
		applib_mem_ap_register(APPLIB_MEM_AP_ID_VRE + i, STR_VRE_TITLE, IMAGE_VRE_SMALL_ICON, 
			mem_control_block[i].stop_cb);
#ifdef __VRE_RB_08A__
		if ((mem_control_block[i].mem_base = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_VRE + i, size)) != NULL)
#else
		if ((mem_control_block[i].mem_base = applib_mem_ap_alloc_framebuffer(APPLIB_MEM_AP_ID_VRE + i, size)) != NULL)
#endif
		{
			mem_control_block[i].app_name = appName;
			mem_control_block[i].hide_flag = hideFlag;
			mem_control_block[i].mem_size = size;
			mem_control_block[i].process_handle = pHandle;
			if (hideFlag)
			{
				mmi_frm_appmem_set_hide_list_screen(APPLIB_MEM_AP_ID_VRE + i);
			}

			vm_log_info("[MMNG]Alloc  pHandle[%d][idx=%d]  ASM memory image.", pHandle, i);
		}
	}
	else
	{
		VMINT j = 0, sumSize = 0;

		for (j = 0; j < MAX_MEM_CONTROL_BLOCK_NUM; j++)
		{
			if (mem_control_block[j].mem_base)
			{
				sumSize += mem_control_block[j].mem_size;
			}
		}

		/* Check MED memory sum size is larger than VRE_SYS_MED_MEMPOOL_SIZE */
		if (sumSize + size <= VRE_SYS_MED_MEMPOOL_SIZE)
		{
			if (media_get_ext_buffer(MOD_MMI, (void**)&(mem_control_block[i].mem_base), size) 
				== MED_RES_OK && mem_control_block[i].mem_base != NULL)
			{
				med_mem_ap_register(MMI_AP_VRE_ID + i, 
					STR_VRE_TITLE, size, mem_control_block[i].stop_cb);
		
				mem_control_block[i].app_name = appName;
				mem_control_block[i].hide_flag = hideFlag;
				mem_control_block[i].mem_size = size;
				mem_control_block[i].process_handle = pHandle;
				if (hideFlag)
				{
					med_mem_ap_set_hide_list_screen(MMI_AP_VRE_ID + i);
				}

				vm_log_info("[MMNG]Alloc  pHandle[%d][idx = %d]  MED memory image.", pHandle, i);
			}
		}
		else
		{
			vm_log_warn("[MMNG]Sum mem[%d] exceed max mem[%d]", sumSize + size, VRE_SYS_MED_MEMPOOL_SIZE);
		}

		
	}

	return mem_control_block[i].mem_base;
}

VMINT _vm_set_app_heap_attr_mem(VM_P_HANDLE pHandle, VMUINT8* heapBase, VMINT heapSize)
{
	VMINT i = 0;
	
	for (i = 0; i < MAX_MEM_CONTROL_BLOCK_NUM; i++)
	{
		if (mem_control_block[i].process_handle == pHandle && heapBase >= mem_control_block[i].mem_base)
		{
#ifdef VRE_ENABLE_DL_HEAP_MANAGER
			if ((mem_control_block[i].adm_id = vm_dl_heap_seg_create(
				(void*)heapBase,
				(VMUINT)heapSize)) != NULL)
            		{
				vm_log_info("VRE APP %d ADM ID = %x, heap base: %x, heap size: %d", 
					i, mem_control_block[i].adm_id, heapBase, heapSize);
				return 0;
			}
#else
            		if ((mem_control_block[i].adm_id = (void *)kal_adm_create(
				(void*)heapBase,
				(VMUINT)heapSize,
				(VMUINT *)NULL, 1)) != NULL)
            		{
				vm_log_info("VRE APP %d ADM ID = %x, heap base: %x, heap size: %d", 
					i, mem_control_block[i].adm_id, heapBase, heapSize);
				return 0;
			}
#endif
		}
	}

	return -1;
}

VMUINT _vm_query_app_num_mem(void)
{
	return 4;
}

void _vm_free_app_seg_mem(VM_P_HANDLE pHandle)
{
	VMINT i = 0;
	vm_multi_lang_app_name_t *tmp = NULL, *tmp2 = NULL;

	if (sysconf.memory_provide == MMI_DEVCONFIG_MEMPEY_PROVIDER_ASM)
	{
		for (i = 0; i < MAX_MEM_CONTROL_BLOCK_NUM; i++)
		{
			if (pHandle == mem_control_block[i].process_handle)
			{
				tmp = mem_control_block[i].app_name;
				while (tmp)
				{
					tmp2 = tmp->next;
					_vm_kernel_free(tmp->app_name);
					_vm_kernel_free(tmp);
					tmp = tmp2;
				}
			
				if (mem_control_block[i].adm_id)
        			{
#ifdef VRE_ENABLE_DL_HEAP_MANAGER
					vm_dl_heap_seg_delete(mem_control_block[i].adm_id);
#else
           		 		kal_adm_delete(mem_control_block[i].adm_id);
#endif
            				mem_control_block[i].adm_id = NULL;
        			}
				
				if (mem_control_block[i].hide_flag)
				{
					mmi_frm_appmem_clear_hide_list_screen(APPLIB_MEM_AP_ID_VRE + i);
				}
				applib_mem_ap_free(mem_control_block[i].mem_base);
				
				mem_control_block[i].app_name = NULL;
				mem_control_block[i].hide_flag = FALSE;
				mem_control_block[i].mem_base = NULL;
				mem_control_block[i].mem_size = 0;
				mem_control_block[i].process_handle = 0;
				memset(&(mem_control_block[i].mem_stat), 0x00, sizeof(malloc_stat_t));

				vm_log_info("[MMNG]Free ASM buffer pHandle[%d] memory image.", pHandle);
				break;
			}
		}
	}
	else
	{
		for (i = 0; i < MAX_MEM_CONTROL_BLOCK_NUM; i++)
		{
			if (pHandle == mem_control_block[i].process_handle)
			{
				tmp = mem_control_block[i].app_name;
				while (tmp)
				{
					tmp2 = tmp->next;
					_vm_kernel_free(tmp->app_name);
					_vm_kernel_free(tmp);
					tmp = tmp2;
				}
			
				if (mem_control_block[i].adm_id)
        			{
#ifdef VRE_ENABLE_DL_HEAP_MANAGER
					vm_dl_heap_seg_delete(mem_control_block[i].adm_id);
#else
           		 		kal_adm_delete(mem_control_block[i].adm_id);
#endif
            				mem_control_block[i].adm_id = NULL;
        			}
				
				if (mem_control_block[i].hide_flag)
				{
					med_mem_ap_clear_hide_list_screen(MMI_AP_VRE_ID + i);
				}
				med_mem_ap_deregister(MMI_AP_VRE_ID + i);
				media_free_ext_buffer(MOD_MMI, (void**)&mem_control_block[i].mem_base);
				
				mem_control_block[i].app_name = NULL;
				mem_control_block[i].hide_flag = FALSE;
				mem_control_block[i].mem_base = NULL;
				mem_control_block[i].mem_size = 0;
				mem_control_block[i].process_handle = 0;
				memset(&(mem_control_block[i].mem_stat), 0x00, sizeof(malloc_stat_t));

				vm_log_info("[MMNG]Free MED buffer pHandle[%d] memory image.", pHandle);
				break;
			}
		}
	}
}

malloc_stat_t* vm_get_malloc_stat(void) 
{
#ifdef VRE_ENABLE_MEM_DEBUG
	VMINT pHandle = vm_pmng_get_current_handle(), i = 0;

	for (i = 0; i < MAX_MEM_CONTROL_BLOCK_NUM; i++)
	{
		if (mem_control_block[i].process_handle == pHandle && mem_control_block[i].adm_id != NULL)
		{
			return &(mem_control_block[i].mem_stat);
		}
	}

	return NULL;
#else
	return NULL;
#endif
}

VMUINT _vm_get_app_seg_free_space(void)
{
	return sysconf.memory_size;
}

#endif
