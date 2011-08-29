#ifdef __VRE__
#include "vmlog.h"
#include "vmmem.h"
#include "vmsalgps.h"
#include "vmmacrostub.h"

/********************************************************************/
/* 模块内部变量。											*/
/********************************************************************/
vm_gps_info_struct *s_vm_sal_gps_info = NULL;

/********************************************************************/
/* 模块内部函数声明	。									*/
/********************************************************************/
/**
 * 判断GPS宏是否已经打开。
 *
 * @return	TRUE表示GPS宏已经打开，FALSE表示GPS宏关闭。
 */
static VMINT vm_sal_gps_is_valid(void);

static VMINT vm_sal_gps_is_open_by_process(void);

/********************************************************************/
/* 模块的函数实现。											*/
/********************************************************************/
static VMINT vm_sal_gps_is_valid(void)
{
	if(sysconf.remote_sensing.gps_support)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

VMINT vm_sal_gps_uart_open(VMUINT16 port)
{
	vm_log_debug("vm_sal_gps_uart_open:start");
	if (vm_sal_gps_is_valid())
	{
		VMINT uart_handle;
		if((s_vm_sal_gps_info = (vm_gps_info_struct*)_vm_kernel_malloc(sizeof(vm_gps_info_struct))) == NULL)
		{
			vm_log_error("vm_sal_gps_uart_open:malloc faild");
			return VM_SAL_GPS_MALLOC_FAILED;
		}
		memset(s_vm_sal_gps_info,0,sizeof(vm_gps_info_struct));
		uart_handle = vm_sal_stub_gps_uart_open(port);
		vm_log_debug("vm_sal_gps_uart_open:uart_handle = %d",uart_handle);
		if(uart_handle >= 0)
		{
			vm_log_debug("vm_sal_gps_uart_open:gps open success");
			return VM_SAL_GPS_OPEN_SUCCESS;
		}
		_vm_kernel_free(s_vm_sal_gps_info);
		s_vm_sal_gps_info = NULL;
		vm_log_debug("vm_sal_gps_uart_open:open faild(uart handle wrong)");
		return VM_SAL_GPS_UART_HANDLE_WRONG;
	}
	else
	{
		vm_log_error("vm_sal_gps_uart_open:GPS is not valid");
		return VM_SAL_GPS_NO_GPS;
	}
}

void vm_sal_gps_uart_close( VMUINT16 port)
{
	vm_log_debug("vm_sal_gps_uart_close:start");
	if (vm_sal_gps_is_valid())
	{
		vm_sal_stub_gps_uart_close(port);
		if(s_vm_sal_gps_info != NULL)
		{
			vm_log_debug("vm_sal_gps_uart_close:free mem");
			_vm_kernel_free(s_vm_sal_gps_info);
			s_vm_sal_gps_info = NULL;
		}
	}
	vm_log_debug("vm_sal_gps_uart_close:end");
}

vm_gps_gga_data_struct* vm_sal_gps_get_gga_data( void )
{
	if (vm_sal_gps_is_open_by_process())
	{
		return &(s_vm_sal_gps_info->gga_data);
	}
	return NULL;
}

vm_gps_rmc_data_struct* vm_sal_gps_get_rmc_data( void )
{
	if (vm_sal_gps_is_open_by_process())
	{
		return &(s_vm_sal_gps_info->rmc_data);
	}
	return NULL;
}

vm_gps_gll_data_struct* vm_sal_gps_get_gll_data( void )
{
	if (vm_sal_gps_is_open_by_process())
	{
		return &(s_vm_sal_gps_info->gll_data);
	}
	return NULL;
}

vm_gps_gsv_data_struct* vm_sal_gps_get_gsv_data( void )
{
	if (vm_sal_gps_is_open_by_process())
	{
		return &(s_vm_sal_gps_info->gsv_data);
	}
	return NULL;
}

vm_gps_gsa_data_struct* vm_sal_gps_get_gsa_data(void )
{
	if (vm_sal_gps_is_open_by_process())
	{
		return &(s_vm_sal_gps_info->gsa_data);
	}
	return NULL;
}

vm_gps_vtg_data_struct* vm_sal_gps_get_vtg_data(  void )
{
	if (vm_sal_gps_is_open_by_process())
	{
		return &(s_vm_sal_gps_info->vtg_data);
	}
	return NULL;
}

static VMINT vm_sal_gps_is_open_by_process(void)
{
	if (vm_sal_gps_is_valid())
	{
		if(s_vm_sal_gps_info != NULL)
		{
			return TRUE;
		}
	}
	return FALSE;
}
#endif/*__VRE__*/
