#ifdef __VRE__

#include "vmlog.h"
#include "vmpromng.h"
#include "vmresmng.h"
#include "vmmod.h"
#include "vmsalgps.h"
#include "vmgps.h"

#include "vmmacrostub.h"
#include "vmopt.h"

#define REG_GPS_MODULE_FAILED -2

/********************************************************************/
/* 模块内部变量												*/
/********************************************************************/
static VMINT16 s_vm_gps_port;	
static VMINT s_vm_gps_handle;
static VMINT s_vm_gps_is_opened;
static VMINT s_vm_sal_gps_parser_enabled_by_vre;

/********************************************************************/
/* 模块内部函数声明											*/
/********************************************************************/
/**
 * 初始化GPS模块。
 */
static void vm_gps_modual_initialize(void);

/**
 * 关闭GPS模块。
 */
static void vm_gps_modual_finialize(void);

/**
 * GPS模块的回调函数。
 *
 * @param event	系统事件。
 */
static VMINT vm_gps_mod_evt_proc(VRE_MOD_LIFECIRCLE_EVT event);

/**
 * GPS进程状态处理函数。
 *
 * @param process_handle	进程ID。
 * @param *buffer			进程状态。
 */
static void vm_gps_notify_process_handler(VM_P_HANDLE process_handle, VMINT sys_state);

/**
 * 删除进程使用的GPS资源。
 *
 * @param process_handle 进程ID号。
 */
static VMINT vm_gps_delete_cur_process_res(VM_P_HANDLE process_handle);

/**
 * 判断保存GPS资源是否失败。
 *
 * @return FALSE表示保存成功了，TRUE表示保存失败。
 */
static VMINT vm_gps_res_save_data_faild(void);

/**
 * 设置分析器。
 */
static void vm_gps_set_parser(void);

/**
 * 判断当前进程是否启动GPS。
 *
 * @return FALSE表示没有启动，TRUE表示已经启动。
 */
static VMINT vm_gps_open_by_cur_process(void);

/********************************************************************/
/* 本模块的函数实现 										*/
/********************************************************************/
VMINT _vm_reg_gps_modual(void)
{
	int res_code = REG_VRE_MODULE_SUCCESS;
	
	if ((res_code = _vm_reg_module("GPS MODUAL", (MOD_EVT_PROCESS)vm_gps_mod_evt_proc)) != REG_VRE_MODULE_SUCCESS)
	{
		vm_log_error("Failed to regisiter GPS moudal. Error Code : %d", res_code);
	}

	return res_code;
}

static VMINT vm_gps_mod_evt_proc(VRE_MOD_LIFECIRCLE_EVT event)
{
	switch(event)
	{
	case EVT_MOD_INIT:
		vm_gps_modual_initialize();
		break;
	case EVT_MOD_RELEASE:
		vm_gps_modual_finialize();
		break;
	default:
		vm_log_error("{GPS MODUAL}Receive unkown[%d] event.", event);
		return REG_GPS_MODULE_FAILED;
	}

	return REG_VRE_MODULE_SUCCESS;
}

static void vm_gps_notify_process_handler(VM_P_HANDLE process_handle, VMINT sys_state)
{
	vm_log_debug("vm_gps_notify_process_handler process_handle=%d,sys_state=%d",process_handle,sys_state);
	if (sys_state == VM_PMNG_UNLOAD)
	{
		vm_gps_delete_cur_process_res(process_handle);
		}
	}


static void vm_gps_modual_initialize(void)
{
	s_vm_gps_is_opened = FALSE;
	s_vm_sal_gps_parser_enabled_by_vre = FALSE;
	vm_res_type_set_notify_callback(VM_RES_TYPE_GPS, vm_gps_notify_process_handler);
}

static void vm_gps_modual_finialize(void)
{
	if(s_vm_gps_is_opened)
	{
		vm_sal_gps_uart_close((VMUINT16)s_vm_gps_port);
		if(s_vm_sal_gps_parser_enabled_by_vre)
		{
			vm_sal_gps_disable_parser();
			s_vm_sal_gps_parser_enabled_by_vre= FALSE;
		}
		s_vm_gps_is_opened = FALSE;
	}
}


VMINT vm_gps_open(void)
{
	VMINT cur_process_id;

	vm_log_debug("vm_gps_open");
	s_vm_gps_port = vm_sal_gps_get_port();
	vm_log_debug("vm_gps_open s_vm_gps_port = %d",s_vm_gps_port);
	if(s_vm_gps_port >= 0)
	{
		cur_process_id = vm_pmng_get_current_handle();
		vm_log_debug("vm_gps_open cur_process_id = %d",cur_process_id);
		vm_log_debug("vm_gps_open s_vm_gps_is_opened = %d",s_vm_gps_is_opened);
		if(!s_vm_gps_is_opened)
		{		
			s_vm_gps_handle = vm_sal_gps_uart_open((VMUINT16)s_vm_gps_port);
			vm_log_debug("vm_gps_open s_vm_gps_handle = %d",s_vm_gps_handle);
			if(s_vm_gps_handle == VM_SAL_GPS_OPEN_SUCCESS)
			{
				if (vm_gps_res_save_data_faild())
				{
					vm_sal_gps_uart_close((VMUINT16)s_vm_gps_port);
					return VM_GPS_OPEN_RES_LESS;
				}
				vm_gps_set_parser();
				s_vm_gps_is_opened = TRUE;
				vm_log_debug("vm_gps_open open success!");
				return VM_GPS_OPEN_SUCCESS;
			}
			return VM_GPS_OPEN_PORT_HANDLE_WRONG;
		}
		else
		{
			if (vm_gps_res_save_data_faild())
			{
				return VM_GPS_OPEN_RES_LESS;
			}
			vm_gps_set_parser();
			vm_log_debug("vm_gps_open already open!");
			return VM_GPS_OPEN_ALREADY_OPEN;
		}
	}
	return VM_GPS_OPEN_PORT_NUMBER_WRONG;
}

VMINT vm_gps_close(void)
{
	return vm_gps_delete_cur_process_res(vm_pmng_get_current_handle());
}

vm_gps_gga_data_struct* vm_gps_get_gga_data( void )
{
	if (vm_gps_open_by_cur_process())
	{
		return vm_sal_gps_get_gga_data();
	}
	return NULL;
}

vm_gps_rmc_data_struct* vm_gps_get_rmc_data( void )
{
	if (vm_gps_open_by_cur_process())
	{
		return vm_sal_gps_get_rmc_data();
	}
	return NULL;
}

vm_gps_gll_data_struct* vm_gps_get_gll_data( void )
{
	if (vm_gps_open_by_cur_process())
	{
		return vm_sal_gps_get_gll_data();
	}
	return NULL;
}

vm_gps_gsv_data_struct* vm_gps_get_gsv_data( void )
{
	if (vm_gps_open_by_cur_process())
	{
		return vm_sal_gps_get_gsv_data();
	}
	return NULL;
}

vm_gps_gsa_data_struct* vm_gps_get_gsa_data(void )
{
	if (vm_gps_open_by_cur_process())
	{
		return vm_sal_gps_get_gsa_data();
	}
	return NULL;
}

vm_gps_vtg_data_struct* vm_gps_get_vtg_data(  void )
{
	if (vm_gps_open_by_cur_process())
	{
		return vm_sal_gps_get_vtg_data();
	}
	return NULL;
}

static VMINT vm_gps_delete_cur_process_res(VM_P_HANDLE process_handle)
{
	if (vm_res_get_data_list_count_by_type(VM_RES_TYPE_GPS) > 0)
	{
		VMINT res_handle = 0;
		if ((res_handle = vm_res_findfirst(process_handle, VM_RES_TYPE_GPS)) != VM_RES_NOT_FIND)
		{
			vm_res_findclose(VM_RES_TYPE_GPS);
			vm_res_release_data(VM_RES_TYPE_GPS, res_handle);
			if (vm_res_get_data_list_count_by_type(VM_RES_TYPE_GPS) <= 0)
			{
				if(s_vm_gps_is_opened)
				{
					vm_sal_gps_uart_close((VMUINT16)s_vm_gps_port);
					s_vm_gps_is_opened = FALSE;
					if(s_vm_sal_gps_parser_enabled_by_vre)
					{
						vm_sal_gps_disable_parser();
						s_vm_sal_gps_parser_enabled_by_vre= FALSE;
					}
					return VM_GPS_CLOSE_SUCCESS;
				}
			}
			return VM_GPS_CLOSE_STILL_APP_USE_DATA;
		}
		vm_res_findclose(VM_RES_TYPE_GPS);
		return VM_GPS_CLOSE_STILL_APP_USE_DATA;
	}
	return VM_GPS_CLOSE_FAILED;
}

static VMINT vm_gps_res_save_data_faild(void)
{
	if (vm_res_get_data_list_count_by_proecss(vm_pmng_get_current_handle(), VM_RES_TYPE_GPS) <= 0)
	{
		if (vm_res_save_data(VM_RES_TYPE_GPS, NULL, 0, NULL, vm_pmng_get_current_handle()) < 0)
		{
			return TRUE;
		}
	}
	return FALSE;
}

static void vm_gps_set_parser(void)
{
	vm_sal_gps_set_work_port((VMUINT8)s_vm_gps_port);
	if(!vm_sal_gps_is_parser_enabled())
	{
		vm_sal_gps_enable_parser();
		s_vm_sal_gps_parser_enabled_by_vre = TRUE;
	}
}

static VMINT vm_gps_open_by_cur_process(void)
{
	if(s_vm_gps_is_opened)
	{
		if (vm_res_get_data_list_count_by_proecss(vm_pmng_get_current_handle(), VM_RES_TYPE_GPS) > 0)
		{
			return TRUE;
		}
	}
	return FALSE;
}
#endif