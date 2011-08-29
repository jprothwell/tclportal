#ifdef __VRE__
#include "mmi_include.h"
#include "vmsys.h"
#include "vmmod.h"
#include "vmlog.h"
#include "vmpromng.h"
#include "vmresmng.h"
#include "vmmem.h"
#include "vmtimer.h"

extern VMINT vre_running;

typedef struct vm_timer_t
{
	VMINT interval;
	VMINT used;
} vm_timer_t;

typedef enum
{
	VM_TIMER = 1,
	VM_TIMER_EX = 2
} vm_timer_type_t;

#define VM_MTK_TIMER_FREE -1

/* --------------------------------------------------------------------------
 * 外部变量声明。
 * ----------------------------------------------------------------------- */


/* --------------------------------------------------------------------------
 * 模块内部变量声明。
 * ----------------------------------------------------------------------- */
#define VRE_SYS_TIMER_INTERVAL (10)

static VMINT timer_array[5];

static VMINT timer_ext_array[5];


VMINT vm_delete_timer(VMINT timerid);
VMINT vm_delete_timer_ex(VMINT timerid);

static void vm_timer_install_timer(VMINT timer_type, VMINT vre_mtk_timer_id, VM_P_HANDLE phandle);



/* --------------------------------------------------------------------------
 * 模块内部函数实现。
 * ----------------------------------------------------------------------- */
static VMINT vm_get_index_by_mtk_timerid(VMINT type, VMINT mtk_timerid)
{
	VMINT id = VM_TIMER_ERROR;
	if (VM_TIMER == type)
	{
		switch(mtk_timerid)
		{
			case VRE_SYS_TIMER_0:
				id = 0;
				break;
			case VRE_SYS_TIMER_1:
				id = 1;
				break;
			case VRE_SYS_TIMER_2:
				id = 2;
				break;
			case VRE_SYS_TIMER_3:
				id = 3;
				break;
			case VRE_SYS_TIMER_4:
				id = 4;
				break;
		}
	}
	else if (VM_TIMER_EX == type)
	{
		switch(mtk_timerid)
		{
			case VRE_SYS_TIMER_EXT_0:
				id = 0;
				break;
			case VRE_SYS_TIMER_EXT_1:
				id = 1;
				break;
			case VRE_SYS_TIMER_EXT_2:
				id = 2;
				break;
			case VRE_SYS_TIMER_EXT_3:
				id = 3;			
				break;
			case VRE_SYS_TIMER_EXT_4:
				id = 4;
				break;
		}
	}
	return id;
		
}


static VMINT vm_get_mtk_timerid_by_index(VMINT type, VMINT index)
{
	VMINT timerid = VM_TIMER_ERROR;
	if (VM_TIMER == type)
	{
		switch(index)
		{
			case 0:
				timerid = VRE_SYS_TIMER_0;
				break;
			case 1:
				timerid = VRE_SYS_TIMER_1;
				break;
			case 2:
				timerid = VRE_SYS_TIMER_2;
				break;
			case 3:
				timerid = VRE_SYS_TIMER_3;
				break;
			case 4:
				timerid = VRE_SYS_TIMER_4;
				break;
		}
	}
	else if (VM_TIMER_EX == type)
	{
		switch(index)
		{
			case 0:
				timerid = VRE_SYS_TIMER_EXT_0;
				break;
			case 1:
				timerid = VRE_SYS_TIMER_EXT_1;
				break;
			case 2:
				timerid = VRE_SYS_TIMER_EXT_2;
				break;
			case 3:
				timerid = VRE_SYS_TIMER_EXT_3;			
				break;
			case 4:
				timerid = VRE_SYS_TIMER_EXT_4;
				break;
		}
	}
	return timerid;
		
}

static void vm_set_mtk_timerid_busy(VMINT timer_type, VMINT  mtk_timerid, VMINT busyflag)
{
	VMINT id = -1;
	if (timer_type == VM_RES_TYPE_TIMER)
	{
		id = vm_get_index_by_mtk_timerid(VM_TIMER, mtk_timerid);
		if (id >= 0)
			timer_array[id]  = busyflag;
	}
	else if (timer_type == VM_RES_TYPE_TIMER_EX)
	{
		id = vm_get_index_by_mtk_timerid(VM_TIMER_EX, mtk_timerid);
		if (id >= 0)
			timer_ext_array[id]  = busyflag;
	}
}

static VMINT vm_get_free_mtk_timerid(VMINT timer_type)
{
	int i = 0;
	if (timer_type == VM_RES_TYPE_TIMER)
	{
		for(i = 0; i < 5; i++)
		{
			if (timer_array[i] == VM_MTK_TIMER_FREE)
			{
				break;
			}
		}
		//vm_log_debug("vm_get_free_mtk_timerid : free mtktimerid=%d", vm_get_mtk_timerid_by_index(VM_TIMER, i));
		return vm_get_mtk_timerid_by_index(VM_TIMER, i);
	}
	else if (timer_type == VM_RES_TYPE_TIMER_EX)
	{
		for(i = 0; i < 5; i++)
		{
			if (timer_ext_array[i] == VM_MTK_TIMER_FREE)
			{
				break;
			}
		}
		return vm_get_mtk_timerid_by_index(VM_TIMER_EX, i);
	}
	return -1;
}


static void _vm_timer_proc(VMINT timer_type, VM_P_HANDLE  phandle)
{
	VMINT mtk_timerid = -1;
	VMINT res_list_count = 0;
	vm_timer_t * timer_p = NULL; 
	VMINT length = 0;
	VMINT i = 0;
	VM_TIMERPROC_T timer_proc = NULL;
	
	res_list_count = vm_res_get_data_list_count_by_proecss(phandle, timer_type);
	//vm_log_debug("_vm_timer_proc(%d, %d) - res_list_count:%d", timer_type, phandle, res_list_count);
	if (res_list_count > 0)
	{
		/*计算时钟列表*/
		if ((i = vm_res_findfirst(phandle, timer_type)) != VM_RES_NOT_FIND)
		{
			//vm_log_debug("_vm_timer_proc(%d, %d) - res_list_count:%d - in findfirst", timer_type, phandle, res_list_count);
			while(i != VM_RES_NOT_FIND)
			{
				vm_res_get_mtk_reshandle(timer_type, i, &mtk_timerid);
				//vm_log_debug("_vm_timer_proc(%d, %d) - i:%d, mtk_timerid:%d", timer_type, phandle, i, mtk_timerid);
				if ((vm_res_get_data(timer_type, i, (void**)&timer_p, &length)) == VM_RES_OK)
				{
					if (timer_p != NULL)
					{
						(timer_p->used) = (timer_p->used) - VRE_SYS_TIMER_INTERVAL;
						if (timer_p->used <= 0)
						{
							timer_p->used = timer_p->interval;	
							//vm_log_debug("_vm_timer_proc(%d, %d) - used:%d", timer_p->used);
							/*回调时钟回调*/
							if ((vm_res_get_callback(timer_type, i, (void**)&timer_proc)) == VM_RES_OK)
							{
								if (timer_proc != NULL)
								{								
									/*进程切换*/
									if (vm_pmng_set_ctx(phandle)  == VM_PMNG_OP_OK)
									{
										vm_log_debug("timer_type=%d, phandle=%d", timer_type, phandle);
										
										if (vre_running == FALSE)
										{
											vm_pmng_reset_ctx();
											return;
										}
										timer_proc(i);
										
										/*恢复现场*/
										vm_pmng_reset_ctx();
									}
								}
								else
								{
									vm_log_debug("vm_timer_ext_proc : timer_proc(%d) is null", i);
								}
							}
							else
							{
								vm_log_debug("vm_timer_ext_proc : timerid %d fail to get timer_proc callback", i);
							}
											
						}					
					}
					else
					{
						vm_log_debug("vm_timer_ext_proc : in loop timer_id=%d, timer_p == NULL", i);
					}				
				}
				else
				{
					vm_log_debug("vm_timer_ext_proc : vm_res_get_data error");
				}
				i = vm_res_findnext(phandle, timer_type);
			}
			vm_res_findclose(timer_type);
			/*启动时钟*/
			if (mtk_timerid >= 0)
			{
				/* 检查当前PID是否还在使用TIMER资源 */
				if (vm_res_get_data_list_count_by_proecss(phandle, timer_type) > 0)
				{
					vm_timer_install_timer(timer_type, mtk_timerid, phandle);
				}
			}
		}
	}
}

static void vm_timer_ext_proc(void *p)
{
	VM_P_HANDLE phandle = -1;

	if (vre_running == FALSE)
		return;

	phandle = (int)p;
	if (phandle < 0)
		return;

	///vm_log_debug("vm_timer_ext_proc step1: phandle=%d", phandle);

	_vm_timer_proc(VM_RES_TYPE_TIMER_EX, phandle);
}


static void vm_timer_proc(void *p)
{
	VM_P_HANDLE phandle = -1;

	if (vre_running == FALSE)
		return;

	phandle = (int)p;
	if (phandle < 0)
		return;

	///vm_log_debug("vm_timer_proc step1: phandle=%d", phandle);

	_vm_timer_proc(VM_RES_TYPE_TIMER, phandle);
}

static void vm_timer_install_timer(VMINT timer_type, VMINT vre_mtk_timer_id, VM_P_HANDLE phandle)
{
	if (timer_type == VM_RES_TYPE_TIMER)
	{
		StartNonAlignTimerEx(vre_mtk_timer_id, 
			(U32)VRE_SYS_TIMER_INTERVAL, 
			vm_timer_proc,  
			(void *)phandle);
		//vm_log_debug("StartNonAlignTimerEx(%d, %d)", vre_mtk_timer_id, phandle);
	}
	else if (timer_type == VM_RES_TYPE_TIMER_EX)
	{
		StartTimerEx(vre_mtk_timer_id, 
			(U32)VRE_SYS_TIMER_INTERVAL, 
			vm_timer_ext_proc,  
			(void *)phandle);
	}
}

/**
 * 进程状态处理机
 */
static void vm_timer_process_state_pro(VM_P_HANDLE phandle, VMINT pro_state)
{
	VMINT i = 0;
	
	switch(pro_state)
	{
		case VM_PMNG_UNLOAD:
			/*删除所有进程相关时钟*/
			while ( (i = vm_res_findfirst(phandle, VM_RES_TYPE_TIMER)) != VM_RES_NOT_FIND)
			{
				vm_delete_timer(i);
				vm_log_debug("vm_timer_process_state_pro : delete timerid=%d", i);
				vm_res_findclose(VM_RES_TYPE_TIMER);
			}			
			break;
		case VM_PMNG_FOREGROUND:
			break;
		case VM_PMNG_BACKGROUND:
			break;
	}
}

/**
 * 进程状态处理机
 */
static void vm_timer_ex_process_state_pro(VM_P_HANDLE phandle, VMINT pro_state)
{
	VMINT i = 0;
	
	switch(pro_state)
	{
		case VM_PMNG_UNLOAD:
			/*删除所有进程相关时钟*/
			while ( (i = vm_res_findfirst(phandle, VM_RES_TYPE_TIMER_EX)) != VM_RES_NOT_FIND)
			{
				vm_delete_timer_ex(i);
				vm_log_debug("vm_timer_ex_process_state_pro : delete timerexid=%d", i);
				vm_res_findclose(VM_RES_TYPE_TIMER_EX);
			}
			
			
			break;
		case VM_PMNG_FOREGROUND:
			break;
		case VM_PMNG_BACKGROUND:
			break;
	}	
}


static void vm_timer_initial(void)
{
	VMINT i = 0;

	for (i =0 ; i < 5; i++)
	{
		timer_array[i] = VM_MTK_TIMER_FREE;
		timer_ext_array[i] = VM_MTK_TIMER_FREE;
	}
	
	vm_res_type_set_notify_callback(VM_RES_TYPE_TIMER, vm_timer_process_state_pro);
	vm_res_type_set_notify_callback(VM_RES_TYPE_TIMER_EX, vm_timer_ex_process_state_pro);
}

static void vm_timer_finialize(void)
{
	VMINT i = VM_RES_NOT_FIND;
	/**
	  * 释放所有TIMER资源
	  */
	//vm_log_debug("vm_timer_finialize start");
	//vm_log_debug("vm_timer_finialize free timer start");
	while ( (i = vm_res_findfirst(-1, VM_RES_TYPE_TIMER)) != VM_RES_NOT_FIND)
	{
		//vm_log_debug("vm_timer_finialize : will delete timerid=%d", i);
		vm_delete_timer(i);
		//vm_log_debug("vm_timer_finialize : have delete timerid=%d", i);
		vm_res_findclose(VM_RES_TYPE_TIMER);
	}
	
	//vm_log_debug("vm_timer_finialize free timer end");
	/**
	  * 释放所有TIMER_EX资源
	  */
	//vm_log_debug("vm_timer_finialize free timer_ex start");
	while ( (i = vm_res_findfirst(-1, VM_RES_TYPE_TIMER_EX)) != VM_RES_NOT_FIND)
	{
		vm_delete_timer_ex(i);
		//vm_log_debug("vm_timer_finialize : delete timerexid=%d", i);
		vm_res_findclose(VM_RES_TYPE_TIMER_EX);
	}
	
	//vm_log_debug("vm_timer_finialize free timer_ex end");
			
	for (i = 0 ; i < 5; i++)
	{ 
		timer_array[i] = VM_MTK_TIMER_FREE;
		timer_ext_array[i] = VM_MTK_TIMER_FREE;
	}
	
	//vm_log_debug("vm_timer_finialize end");
	
	/*关闭系统通知回调*/
	vm_res_type_set_notify_callback(VM_RES_TYPE_TIMER, NULL);
	vm_res_type_set_notify_callback(VM_RES_TYPE_TIMER_EX, NULL);
	//vm_log_debug("vm_timer_finialize end2");
}

static VMINT vm_timer_mod_evt_proc(VRE_MOD_LIFECIRCLE_EVT event)
{
	switch(event)
	{
		case EVT_MOD_INIT:
			vm_timer_initial();
			break;
 		case EVT_MOD_RELEASE:
			vm_timer_finialize();
			break;
	}
	return 0;
}


/* --------------------------------------------------------------------------
 * 模块函数实现。
 * ----------------------------------------------------------------------- */
 VMINT _vm_reg_timer_module(void)
{
	int res = 0;

	if ((res = _vm_reg_module("TIMER MODULE", (MOD_EVT_PROCESS)vm_timer_mod_evt_proc)) 
		!= REG_VRE_MODULE_SUCCESS)
	{
		vm_log_debug("_vm_reg_timer_modual : failed to register timer module. errorcode=%d", res);
	}
	return res;
}

static VMINT _vm_create_timer(VMINT timer_type, VMUINT32 millisec, VM_TIMERPROC_T timerproc)
{
	VMINT timerid = VM_TIMER_ERROR;
	VMINT mtk_timerid = -1;
	VMINT count = 0;
	vm_res_node_t res;
	vm_timer_t* timer_p = NULL; 

	VM_P_HANDLE phandle = vm_pmng_get_current_handle();
	
	if (phandle < 0)
		return VM_TIMER_ERROR_OF_PROCESS;

	count = vm_res_get_data_list_count_by_proecss(phandle, timer_type);

	timer_p = _vm_kernel_malloc(sizeof(vm_timer_t));
	if (timer_p == NULL)
		return  VM_TIMER_ERROR_OF_MEM;	
	timer_p->interval = millisec;
	timer_p->used = millisec;

	timerid = vm_res_save_data(timer_type, timer_p, sizeof(timer_p), (void *)timerproc, phandle);
	if (timerid < 0)
	{
		vm_log_debug("_vm_create_timer : save res fail!!");
		timerid = VM_TIMER_ERROR_OF_RES;
	}
	else
	{
		vm_log_debug("_vm_create_timer : current timer count=%d, timer_type=%d", count, timer_type);
		if (count == 0)
		{
			mtk_timerid = vm_get_free_mtk_timerid(timer_type);
			vm_log_debug("_vm_create_timer : get free mtk_timerid=%d, timer_type=%d", mtk_timerid, timer_type);	
			if (mtk_timerid >= 0)
			{
				if (vm_res_set_mtk_reshandle(timer_type, timerid, mtk_timerid)  < VM_RES_OK)
				{					
					vm_res_release_data(timer_type, timerid);
					timerid = VM_TIMER_ERROR_OF_RES;
					vm_log_debug("_vm_create_timer : vm_res_set_mtk_reshandle error.");
				}
				else
				{
					vm_set_mtk_timerid_busy(timer_type, mtk_timerid, phandle);
					//vm_log_debug("vm_set_mtk_timerid_busy(%d, %d, %d)", timer_type, mtk_timerid, phandle);

					vm_timer_install_timer(timer_type, mtk_timerid,  phandle);
					vm_log_debug("_vm_create_timer : have start mtk timer");
				}
			}
			else
			{
				vm_res_release_data(timer_type, timerid);
				timerid = VM_TIMER_MTK_TIMER_NO_FREE;
				vm_log_debug("_vm_create_timer : all mtk_timerid is busy");
			}			
		}
		else
		{
			if (vm_res_get_data_list_by_proecss(phandle, timer_type, &res, 1) > 0)
			{
				mtk_timerid = res.mtk_res_id;
				if (vm_res_set_mtk_reshandle(timer_type, timerid, mtk_timerid) < VM_RES_OK)
				{
					vm_res_release_data(timer_type, timerid);
					timerid = VM_TIMER_ERROR_OF_RES;
					vm_log_debug("_vm_create_timer : vm_res_set_mtk_reshandle error.");
				}
			}
			else
			{
				vm_res_release_data(timer_type, timerid);
				timerid = VM_TIMER_ERROR_OF_RES;
				vm_log_debug("_vm_create_timer : all mtk_timerid is busy");
			}
		}
	}
	
	if (timerid < 0)
		_vm_kernel_free(timer_p);
	return timerid;		
}

VMINT vm_create_timer(VMUINT32 millisec, VM_TIMERPROC_T timerproc)
{
	return _vm_create_timer(VM_RES_TYPE_TIMER, millisec, timerproc);
}


VMINT vm_create_timer_ex(VMUINT32 millisec, VM_TIMERPROC_T timerproc)
{
	return _vm_create_timer(VM_RES_TYPE_TIMER_EX, millisec, timerproc);
}

static VMINT _vm_delete_timer(VMINT timer_type, VMINT timerid)
{
	vm_timer_t * res_p = NULL;
	VMINT res_node_size = 0;
	VMINT count = 0;
	VMINT mtk_timerid = -1;
	VM_P_HANDLE phandle = -1;
	VM_P_HANDLE curr_phandle = vm_pmng_get_current_handle();

	vm_log_debug("_vm_delete_timer : type=%d, timerid=%d", timer_type, timerid);
	if ((phandle = vm_res_get_process_handle(timer_type, timerid)) < 0)
		return VM_TIMER_ERROR_OF_RES;
	if (curr_phandle > 0) 
	{
		if (phandle != curr_phandle)
			return VM_TIMER_ERROR_OF_PROCESS;
	}	 

	if (vm_res_get_mtk_reshandle(timer_type, timerid, &mtk_timerid) < VM_RES_OK )
		return VM_TIMER_ERROR_OF_RES;
	
	if (vm_res_get_data(timer_type, timerid, (void**)&res_p, &res_node_size) < VM_RES_OK)
		return VM_TIMER_ERROR_OF_RES;	
	_vm_kernel_free(res_p);
	
	vm_res_set_data(timer_type, timerid, NULL, 0);
	vm_res_set_callback(timer_type, timerid, NULL);		

	if (vm_res_release_data(timer_type, timerid) < VM_RES_OK)
		return VM_TIMER_ERROR;
	
	count = vm_res_get_data_list_count_by_proecss(phandle, timer_type);
	if (count <= 0)
	{
		if (mtk_timerid >= 0)
		{
			vm_set_mtk_timerid_busy(timer_type, mtk_timerid, VM_MTK_TIMER_FREE);
		}
	}
	return VM_TIMER_OK;	
}

VMINT vm_delete_timer(VMINT timerid)
{
	return _vm_delete_timer(VM_RES_TYPE_TIMER, timerid);
}

VMINT vm_delete_timer_ex(VMINT timerid)
{
	return _vm_delete_timer(VM_RES_TYPE_TIMER_EX, timerid);
}
#endif
