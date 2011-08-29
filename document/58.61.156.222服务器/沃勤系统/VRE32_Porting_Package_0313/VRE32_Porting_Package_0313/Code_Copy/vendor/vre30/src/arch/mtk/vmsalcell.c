#ifdef __VRE__
#include "vmlog.h"
#include "vmmem.h"
#include "vmsalcell.h"
#include "vmmacrostub.h"

/********************************************************************/
/* 本模块的内部变量 										*/
/********************************************************************/
vm_cell_info_struct* s_vm_sal_cur_cell_info = NULL;
vm_cell_info_struct* s_vm_sal_nbr_cell_info[VM_SAL_CELL_NBR_MAX] = {NULL,NULL,NULL,NULL,NULL,NULL};
VMINT s_vm_sal_cell_nbr_num;

/********************************************************************/
/* 本模块的内部函数声明									*/
/********************************************************************/
static VMINT vm_sal_cell_is_valid(void);

static void vm_sal_cell_free_mem(void);
/********************************************************************/
/* 本模块的函数实现 										*/
/********************************************************************/
static VMINT vm_sal_cell_is_valid(void)
{
	if (sysconf.remote_sensing.cell_info_support)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
VMINT vm_sal_cell_reg_req(void)
{
	vm_log_debug("vm_sal_cell_reg_req:start");
	if (vm_sal_cell_is_valid())
	{
		int i;

		if((s_vm_sal_cur_cell_info = (vm_cell_info_struct*)_vm_kernel_malloc(sizeof(vm_cell_info_struct))) == NULL)
		{
			vm_log_error("vm_sal_cell_reg_req:malloc cur cell mem faild");
			return VM_SAL_CELL_REG_CUR_MALLOC_FAILED;
		}
		for(i = 0; i < VM_SAL_CELL_NBR_MAX; i++)
		{
			if((s_vm_sal_nbr_cell_info[i] = (vm_cell_info_struct*)_vm_kernel_malloc(sizeof(vm_cell_info_struct))) == NULL)
			{
				vm_sal_cell_free_mem();
				vm_log_error("vm_sal_cell_reg_req:malloc nbr cell mem faild");
				return VM_SAL_CELL_REG_NBR_MALLOC_FAILED;
			}
		}
	
		memset(s_vm_sal_cur_cell_info,0,sizeof(vm_cell_info_struct));
		for(i = 0; i < VM_SAL_CELL_NBR_MAX; i++)
		{
			memset(s_vm_sal_nbr_cell_info[i],0, sizeof(vm_cell_info_struct));
		}
		if (vm_sal_stub_cell_reg_req())
		{
			vm_log_debug("vm_sal_cell_reg_req:cell reg success");
			return VM_SAL_CELL_REG_SUCCESS;
		}
		else
		{
			vm_sal_cell_free_mem();
			vm_log_error("vm_sal_cell_reg_req:ilm malloc faild");
			return VM_SAL_CELL_REG_ILM_MALLOC_FAILED;	
		}
	}
	else
	{
		vm_log_error("vm_sal_cell_reg_req:cell is not valid");
		return VM_SAL_CELL_REG_NO_CELL;
	}
}

void vm_sal_cell_dereg_req(void)
{
	vm_log_debug("vm_sal_cell_dereg_req:start");
	if (vm_sal_cell_is_valid())
	{
		vm_sal_stub_cell_dereg_req();
		vm_sal_cell_free_mem();
	}
	vm_log_debug("vm_sal_cell_dereg_req:end");
}


vm_cell_info_struct* vm_sal_cell_get_cur_cell_info(void)
{
	if (vm_sal_cell_is_valid())
	{
		if(s_vm_sal_cur_cell_info != NULL)
		{
			return (s_vm_sal_cur_cell_info);
		}
	}
	return NULL;
}

 vm_cell_info_struct** vm_sal_cell_get_nbr_cell_info(void)
{
	if (vm_sal_cell_is_valid())
	{
		if(s_vm_sal_nbr_cell_info != NULL)
		{
			return (s_vm_sal_nbr_cell_info);
		}
	}
	return NULL;
}

VMINT* vm_sal_cell_get_nbr_num(void)
{
	if (vm_sal_cell_is_valid())
	{
		return &s_vm_sal_cell_nbr_num;
	}
	return NULL;
}
static void vm_sal_cell_free_mem(void)
{
	VMINT i;
	if(s_vm_sal_cur_cell_info != NULL)
	{
		_vm_kernel_free(s_vm_sal_cur_cell_info);
		s_vm_sal_cur_cell_info = NULL;
	}
	for(i=0;i<VM_SAL_CELL_NBR_MAX;i++)
	{
		if(s_vm_sal_nbr_cell_info[i] != NULL)
		{
			_vm_kernel_free(s_vm_sal_nbr_cell_info[i]);
			s_vm_sal_nbr_cell_info[i] = NULL;
		}
	}
}
	
#endif