#ifdef __VRE__
#include "mmi_include.h"
#include "SimDetectionGprot.h"
#include "Cbm_api.h"
#include "SimDetectionGexdcl.h"
#include "NetworkSetupDefs.h"

#include "vmopt.h"
#include "vmio.h"
#include "vmsys.h"
#include "vmsim.h"
#include "vmlog.h"
#include "vmchset.h"
#include "vmenv.h"

//#if (defined(MT6225_GEMINI_VERSION) || defined(MT6225_GEMINI_0816_VRESION) || defined(MT6223_GEMINI_08A_VERSION))
#if (defined(VRE_DUAL_SIM))
#include "MTPNP_AD_master_if.h"
#include "mtpnp_pfal_master_def.h"
#include "mtpnp_ad_master_common_def.h"

extern pBOOL mmi_bootup_is_nw_registration_ok(void); 
extern pBOOL mmi_bootup_is_sim2_nw_registration_ok(void);
#endif

/********************************************************************/
/* 系统全局变量的引用										*/
/********************************************************************/
/*
 * 上电后的手机状态。
 */
 extern pwr_context_struct g_pwr_context;

/********************************************************************/
/* 系统函数的引用											*/
/********************************************************************/
//extern void ClearProtocolEventHandler(U16 eventID);
extern U32 always_ask_encode_data_account_id(U32 acct_id, int sim_src, U8 app_id, BOOL always_ask);
extern void mmi_idle_get_dual_sim_status(U8 *sim_status, U8* mode_status);

/********************************************************************/
/* 模块内部变量												*/
/********************************************************************/
#define VM_SIM_CHECKED 1
#define VM_SIM_UNCHECKED 0

/*
 * 手机卡的imsi。
 */
#ifdef VRE_DUAL_SIM
static VMCHAR vm_imsi_number_sim1[20] = {0};
static VMCHAR vm_imsi_number_sim2[20] = {0};
#else
static VMCHAR vm_imsi_number[20] = {0};
#endif
/*
 * 是否已经得到了IMSI的标志，0表示还没有设置，1表示已经设置了。
 */
#ifdef VRE_DUAL_SIM
static VMINT imsi_check_sim1 = VM_SIM_UNCHECKED;
static VMINT imsi_check_sim2 = VM_SIM_UNCHECKED;
#else
static VMINT imsi_check = VM_SIM_UNCHECKED;
#endif

/*
 * 手机卡的imei。
 */
#ifdef VRE_DUAL_SIM
static VMCHAR vm_imei_number1[20] = {0};
static VMCHAR vm_imei_number2[20] = {0};
#else
static VMCHAR vm_imei_number[20] = {0};
#endif
/*
 * 是否设置了vm_imei_number的标志，0表示还没有设置，1表示已经设置了。
 */

#ifdef VRE_DUAL_SIM
static VMINT imei_check_imei1 = VM_SIM_UNCHECKED;
static VMINT imei_check_imei2 = VM_SIM_UNCHECKED;
#else
static VMINT imei_check = VM_SIM_UNCHECKED;
#endif
/*
*已选择sim卡, 0=无卡被选中, 1=卡1被选中, 2=卡2被选中
*/
VMINT vm_selected_simcard = VM_SIM_NO;

/********************************************************************/
/* 模块内部函数											*/
/********************************************************************/
#ifdef VRE_DUAL_SIM
VMINT vm_is_card2_mode(void);
VMINT vm_is_card2Absent(void);
VMINT vm_is_card1_mode(void);
VMINT vm_is_card1Absent(void);
VMINT vm_is_dualcard_mode(void);
#endif


/********************************************************************/
/* 本模块的函数实现 										*/
/********************************************************************/
const VMSTR vm_get_imei_ext(VMINT sim_index)
{
	#ifdef VRE_DUAL_SIM
		if (sim_index == VM_SIM_SIM1)
		{
			if (imei_check_imei1 == VM_SIM_CHECKED)
				return vm_imei_number1;
			else
				return NULL;
		}
		else if (sim_index == VM_SIM_SIM2)
		{
			if (imei_check_imei2 == VM_SIM_CHECKED)
				return vm_imei_number2;
			else
				return NULL;
		}
		else
		{
			if (imei_check_imei1 == VM_SIM_CHECKED)
				return vm_imei_number1;
			else
				return NULL;
		}		
	#else
		if (imei_check == VM_SIM_CHECKED)
			return vm_imei_number;
		else
			return NULL;
	#endif
}


const VMSTR vm_get_imei(void)
{
	#ifdef VRE_DUAL_SIM
		if (vm_selected_simcard == VM_SIM_SIM1)
		{
			if (imei_check_imei1 == VM_SIM_CHECKED)
				return vm_imei_number1;
			else
				return NULL;
		}
		else if (vm_selected_simcard == VM_SIM_SIM2)
		{
			if (imei_check_imei2 == VM_SIM_CHECKED)
				return vm_imei_number2;
			else
				return NULL;
		}
		else
		{
			if (imei_check_imei1 == VM_SIM_CHECKED)
				return vm_imei_number1;
			else
				return NULL;
		}		
	#else
		if (imei_check == VM_SIM_CHECKED)
			return vm_imei_number;
		else
			return NULL;
	#endif
}

const VMSTR vm_get_imsi(void)
{
#ifdef VRE_DUAL_SIM
	VMSTR imsi = NULL;

	switch(MTPNP_AD_Get_UsableSide())
	{
	case MTPNP_AD_DUALSIM_USABLE:
		if (vm_selected_simcard == VM_SIM_SIM2)
			imsi = (imsi_check_sim2 == VM_SIM_CHECKED ? vm_imsi_number_sim2 : NULL);
		else
			imsi =  (imsi_check_sim1 == VM_SIM_CHECKED ? vm_imsi_number_sim1 : NULL);
		
		break;
	case MTPNP_AD_SIMCARD1_USABLE:
		imsi = (imsi_check_sim1 == VM_SIM_CHECKED ? vm_imsi_number_sim1 : NULL);
		
		break;
	case MTPNP_AD_SIMCARD2_USABLE:
		imsi = (imsi_check_sim2 == VM_SIM_CHECKED ? vm_imsi_number_sim2 : NULL);

		break;
	default:
		break;
	}

	return imsi;
#else
	if (imsi_check == VM_SIM_CHECKED)
		return vm_imsi_number;
	else
		return NULL;
#endif
}

VMINT vm_has_sim_card(void) 
{
#if (defined(VRE_DUAL_SIM))
	if (((vm_is_card2_mode()==1) && (vm_is_card2Absent()==1))  
		||  ((vm_is_card1_mode()==1) && (vm_is_card1Absent()==1))
		||  ((vm_is_dualcard_mode()==1) && (vm_is_card2Absent()==1) && (vm_is_card1Absent()==1)))
		    return FALSE;
		return TRUE;
#else
  #if (defined(__VRE_RB_08A__))
	if (g_pwr_context.PowerOnSIMStatus & MMI_SIM_STATUS_NOT_INSERT)
		return FALSE;
	else
		return TRUE;
	#else
	VMUINT8 sim_status;
	VMUINT8 mode_status;
	mmi_idle_get_dual_sim_status(&sim_status, &mode_status);
	if (sim_status == MMI_SIM_ID_SIM1)
		return TRUE;
	else
		return FALSE;
	#endif 
#endif	
}

void vm_init_imei_number(void)
{
#ifdef VRE_DUAL_SIM
	memset(vm_imei_number1, 0x00, 20);
	memcpy (vm_imei_number1, mmi_bootup_get_imei_value(SIM1), 16);
	imei_check_imei1= VM_SIM_CHECKED;
	memset(vm_imei_number2, 0x00, 20);
	memcpy (vm_imei_number2, mmi_bootup_get_imei_value(SIM2), 16);
	imei_check_imei2 = VM_SIM_CHECKED;
	vm_log_debug("finished init imei nubmer: imei1: %s, imei2: %s", vm_imei_number1, vm_imei_number2);
#else
	memset(vm_imei_number, 0x00, 20);
	memcpy (vm_imei_number, mmi_bootup_get_imei_value(), 16);
	imei_check = VM_SIM_CHECKED;
	vm_log_debug("finished init imei nubmer: imei: %s", vm_imei_number);
#endif
}

void vm_init_imsi_number(void)
{
#ifdef VRE_DUAL_SIM
	memset(vm_imsi_number_sim2, 0x00, 20);
	memcpy(vm_imsi_number_sim2, mmi_bootup_get_imsi_value(SIM2), 17);
	imsi_check_sim2 = VM_SIM_CHECKED;	
	memset(vm_imsi_number_sim1, 0x00, 20);
	memcpy(vm_imsi_number_sim1, mmi_bootup_get_imsi_value(SIM1), 17);
	imsi_check_sim1 = VM_SIM_CHECKED;
	vm_log_debug("finished init imsi nubmer: sim1 imsi: %s, sim2 imsi: %s", vm_imsi_number_sim1, vm_imsi_number_sim2); 
		
#else
	memset(vm_imsi_number, 0x00, 20);
	memcpy(vm_imsi_number, mmi_bootup_get_imsi_value(), 17);
	imsi_check = VM_SIM_CHECKED;
	vm_log_debug("finished init imsi nubmer: imsi: %s", vm_imsi_number); 
#endif
}


VMINT vm_is_dualcard_mode(void)
{
#if (defined(VRE_DUAL_SIM))
  #if (defined(__VRE_RB_08A__))
	return (MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_DUALCARD ? 1 : 0);
	#else
	VMUINT8 sim_status;
	VMUINT8 mode_status;
	mmi_idle_get_dual_sim_status(&sim_status, &mode_status);
	vm_log_debug("vm_is_dualcard_mode	- mmi_idle_get_dual_sim_status(%d, %d);", sim_status, mode_status);
	if (mode_status == MMI_SIM_ID_DUAL_SIM)
		return 1;
	return 0;	
	#endif
#else
	return -1;
#endif
}

VMINT vm_is_card1_mode(void)
{
#if (defined(VRE_DUAL_SIM))
  #if (defined(__VRE_RB_08A__))
	return (MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_CARD1 ? 1 : 0);
  #else
	VMUINT8 sim_status;
	VMUINT8 mode_status;
	mmi_idle_get_dual_sim_status(&sim_status, &mode_status);
	vm_log_debug("vm_is_card1_mode	- mmi_idle_get_dual_sim_status(%d, %d);", sim_status, mode_status);
	if (mode_status == MMI_SIM_ID_SIM1)
		return 1;
	return 0;
  #endif
#else
	return -1;
#endif
}


VMINT vm_is_card2_mode(void)
{
#if (defined(VRE_DUAL_SIM))
  #if (defined(__VRE_RB_08A__))
	return (MTPNP_AD_Get_Startup_Mode() == MTPNP_AD_NVRAM_CARD2 ? 1 : 0);
	#else
	VMUINT8 sim_status;
	VMUINT8 mode_status;
	mmi_idle_get_dual_sim_status(&sim_status, &mode_status);
	vm_log_debug("vm_is_card2_mode	- mmi_idle_get_dual_sim_status(%d, %d);", sim_status, mode_status);
	if (mode_status == MMI_SIM_ID_SIM2)
		return 1;
	return 0;
	#endif
#else
	return -1;
#endif
}

VMINT vm_is_flight_mode(void)
{
	if (mmi_bootup_get_active_flight_mode() == TRUE)
	{
		vm_log_debug("is flight mode");
		return TRUE;
	}
	else
	{
		vm_log_debug("is not flight mode");
		return FALSE;
	}
	return FALSE;
}

VMINT vm_is_card1Absent(void)
{
#if (defined(VRE_DUAL_SIM))
  #if (defined(__VRE_RB_08A__))
	return (MTPNP_PFAL_Is_Card1Absent() ? 1 : 0);
  #else
	VMUINT8 sim_status;
	VMUINT8 mode_status;
	mmi_idle_get_dual_sim_status(&sim_status, &mode_status);
	vm_log_debug("vm_is_card1Absent	- mmi_idle_get_dual_sim_status(%d, %d);", sim_status, mode_status);
	if (sim_status == MMI_SIM_ID_SIM1 || sim_status == MMI_SIM_ID_DUAL_SIM)
		return 0;
	return 1;
  #endif
#else
	return -1;
#endif
}


VMINT vm_is_card2Absent(void)
{
#if (defined(VRE_DUAL_SIM))
  #if (defined(__VRE_RB_08A__))
	return (MTPNP_PFAL_Is_Card2Absent() ? 1 : 0);
  #else
	VMUINT8 sim_status;
	VMUINT8 mode_status;
	mmi_idle_get_dual_sim_status(&sim_status, &mode_status);
	vm_log_debug("vm_is_card2Absent	- mmi_idle_get_dual_sim_status(%d, %d);", sim_status, mode_status);
	if (sim_status == MMI_SIM_ID_SIM2 || sim_status == MMI_SIM_ID_DUAL_SIM)
		return 0;
	return 1;
  #endif
#else
	return -1;
#endif
}

/*
void vm_set_simcard_for_sock(VMINT simcard)
{
	vm_selected_simcard = simcard;
}
*/

static VMUINT vm_get_encode_data_accound_id(VMUINT  account_id,VMUINT sim_src, VMUINT8 app_id)
{
	VMUINT result = account_id;
	result = cbm_encode_data_account_id(account_id, sim_src-1, app_id, 0);
	return result;
}

VMUINT vm_get_account_id(VMUINT account_id, VMUINT8 app_id)
{
	VMUINT vm_account_id = account_id;
	
#if (defined(VRE_DUAL_SIM))
	if (vm_is_dualcard_mode() == 1)
	{
		vm_log_debug("{SIM MOUDLE}Card[1] absent: %d, Card[2] absent: %d", 
			vm_is_card1Absent(), vm_is_card2Absent());
		if ((vm_is_card1Absent()==0) && vm_is_card2Absent()==0)
		{
			if (vm_selected_simcard == VM_SIM_SIM1)
			{
				vm_account_id = vm_get_encode_data_accound_id(account_id, 1, app_id);
			}
			else
			{
				vm_account_id = vm_get_encode_data_accound_id(account_id, 2, app_id);
			}
		}
		else 
		{
			if (vm_is_card1Absent() == 1)
			{
				vm_account_id = vm_get_encode_data_accound_id(account_id, 2, app_id);
			}
			else if (vm_is_card2Absent() == 1)
			{
				vm_account_id = vm_get_encode_data_accound_id(account_id, 1, app_id);
			}
		}
	}
	else
	{
		vm_log_debug("{SIM MOUDLE}Card[1] absent: %d, Card[2] absent: %d", 
			vm_is_card1Absent(), vm_is_card2Absent());
		if (vm_is_card1_mode())
		{
			vm_account_id = vm_get_encode_data_accound_id(account_id, 1, app_id);
		}
		else if(vm_is_card2_mode())
		{
			vm_account_id = vm_get_encode_data_accound_id(account_id, 2, app_id);
		}
	}
#else
	vm_account_id = vm_get_encode_data_accound_id(account_id, 1, app_id);
#endif

	return vm_account_id;
}

void _vm_init_sim_card_status(void)
{
	VMINT sim_card_count = vm_sim_card_count();
	VMINT sim_idx = VM_SIM_SIM1;
	
	switch (sim_card_count)
	{
	case 2:
		if (vm_vam_get_sim_card(&sim_idx) != TRUE)
		{
			vm_log_warn("Failed to get sim card index.");
		}
		if (sim_idx != VM_SIM_SIM2)
			sim_idx  = VM_SIM_SIM1;
		vm_set_active_sim_card(sim_idx);
		break;
	case 1:
		if (!(vm_set_active_sim_card(VM_SIM_SIM1)))
		{
			vm_set_active_sim_card(VM_SIM_SIM2);
		}
		break;
	default:
		vm_log_warn("Failed get sim card count: %d", sim_card_count);
	}
}

extern MMI_BOOL mmi_sim_get_home_plmn_num(
    const sim_interface_enum required_sim,
    S8 *home_plmn_num,
    const U32 buffer_size);

//#define VM_GLOBAL_UT
#ifdef VM_GLOBAL_UT
static VMINT vm_read_operator_code_from_file(void * buf,VMINT bufsize)
{
	VMFILE operator_file;
	VMINT drv;
	VMCHAR szPath[32] = {0};
	VMUINT nread;
	if ((drv = vm_get_removable_driver()) < 0)
		drv = vm_get_system_driver();
	sprintf(szPath,"%c:\\vmapnut.cfg",drv);

	if ((operator_file = vm_file_open(vm_ucs2_string_by_ascii("c:\\vmapnut.cfg"), MODE_READ,TRUE)) < 0)
	{		
		vm_log_warn("[GLOBAL]-vm_read_operator_code_from_file:file open error !");
		return -1;
	}
	if ((nread = vm_file_read(operator_file, buf, (VMUINT)bufsize, &nread))  <= 0)
	{
		vm_file_close(operator_file);
		return -1;
	}
	vm_file_close(operator_file);
	vm_log_warn("[GLOBAL]-vm_read_operator_code_from_file:operator_code : %s",buf);
	return 0;
	
}
#endif


VMINT vm_query_operator_code(VMCHAR* buffer, VMUINT buffer_size)
{

#if (defined(VRE_DUAL_SIM))
    	VMCHAR ghnum1[MAX_PLMN_LEN_MMI + 1];
	VMCHAR ghnum2[MAX_PLMN_LEN_MMI + 1];

	if (buffer == NULL || buffer_size == 0)
		return -1;

	if (vm_has_sim_card() == FALSE)
	{
		return -2;
	}
#ifdef VM_GLOBAL_UT
	if (vm_read_operator_code_from_file(buffer,buffer_size) == 0)
		return 0;
#endif
	if (vm_is_dualcard_mode()==1)
	{
		//如两张卡都存在，使用配置信息
		if((vm_is_card1Absent()==0) && (vm_is_card2Absent()==0))
		{
			switch(vm_selected_simcard)
			{
			case 2:
				memset(ghnum2, 0x00, MAX_PLMN_LEN_MMI + 1);
				mmi_sim_get_home_plmn_num(SIM2, (S8 * )ghnum2, MAX_PLMN_LEN_MMI + 1);
			       strncpy(buffer, ghnum2, buffer_size);
				return 0;
			case 1:   
				memset(ghnum1, 0x00, MAX_PLMN_LEN_MMI + 1);
				mmi_sim_get_home_plmn_num(SIM1, (S8 * )ghnum1, MAX_PLMN_LEN_MMI + 1);
				strncpy(buffer, ghnum1, buffer_size);
				return 0;
			}
		}  
		else
		{
			if (vm_is_card1Absent()==1)
			{
				memset(ghnum2, 0x00, MAX_PLMN_LEN_MMI + 1);
				mmi_sim_get_home_plmn_num(SIM2, (S8 * )ghnum2, MAX_PLMN_LEN_MMI + 1);
			       strncpy(buffer, ghnum2, buffer_size);
				return 0;
			} 
			else 
			{
				memset(ghnum1, 0x00, MAX_PLMN_LEN_MMI + 1);
				mmi_sim_get_home_plmn_num(SIM1, (S8 * )ghnum1, MAX_PLMN_LEN_MMI + 1);
				strncpy(buffer, ghnum1, buffer_size);
				return 0;
			}
		}
	}
	else
	{	
		if (vm_is_card1_mode())
		{
			memset(ghnum1, 0x00, MAX_PLMN_LEN_MMI + 1);
			mmi_sim_get_home_plmn_num(SIM1, (S8 * )ghnum1, MAX_PLMN_LEN_MMI + 1);
	        	strncpy(buffer, ghnum1, buffer_size);
			return 0;
		}
		else if(vm_is_card2_mode())
		{
			memset(ghnum2, 0x00, MAX_PLMN_LEN_MMI + 1);
			mmi_sim_get_home_plmn_num(SIM2, (S8 * )ghnum2, MAX_PLMN_LEN_MMI + 1);
        		strncpy(buffer, ghnum2, buffer_size);
			return 0;
		}
	}
	
	return -5;

#else

	VMCHAR ghnum[MAX_PLMN_LEN_MMI + 1];

	if (buffer == NULL || buffer_size == 0)
		return -1;

	if (vm_has_sim_card() == FALSE)
	{
		return -2;
	}

#ifdef VM_GLOBAL_UT
	if (vm_read_operator_code_from_file(buffer,buffer_size) == 0)
		return 0;
#endif


	memset(ghnum, 0x00, MAX_PLMN_LEN_MMI + 1);
	mmi_sim_get_home_plmn_num(SIM1, (S8 * )ghnum, MAX_PLMN_LEN_MMI + 1);
	strncpy(buffer, ghnum, buffer_size);
	return 0;
#endif
}

operator_t vm_get_operator(void)
{
#if (defined(VRE_DUAL_SIM))
    	VMCHAR ghnum1[MAX_PLMN_LEN_MMI + 1];
	VMCHAR ghnum2[MAX_PLMN_LEN_MMI + 1];

	if (vm_has_sim_card() == FALSE)
	{
		return NO_SIM_CARD;
	}

	if (vm_is_dualcard_mode()==1)
	{
		//如两张卡都存在，使用配置信息
		if((vm_is_card1Absent()==0) && (vm_is_card2Absent()==0))
		{
			switch(vm_selected_simcard)
			{
			case 2:
				memset(ghnum2, 0x00, MAX_PLMN_LEN_MMI + 1);
				mmi_sim_get_home_plmn_num(SIM2, (S8 * )ghnum2, MAX_PLMN_LEN_MMI + 1);
			       if (strncmp(ghnum2, "46000", 5) == 0 || strncmp(ghnum2, "46002", 5) == 0 ||strncmp(ghnum2, "46007", 5) == 0)
					return CMCC;
				else if (strncmp(ghnum2, "46001", 5) == 0)
					return UNICOM;
				break;
			case 1:   
				memset(ghnum1, 0x00, MAX_PLMN_LEN_MMI + 1);
				mmi_sim_get_home_plmn_num(SIM1, (S8 * )ghnum1, MAX_PLMN_LEN_MMI + 1);
				if (strncmp(ghnum1, "46000", 5) == 0 || strncmp(ghnum1, "46002", 5) == 0 ||strncmp(ghnum2, "46007", 5) == 0)
					return CMCC;
				else if (strncmp(ghnum1, "46001", 5) == 0)
					return UNICOM;
				break;
			}
		}  
		else
		{
			if (vm_is_card1Absent()==1)
			{
				memset(ghnum2, 0x00, MAX_PLMN_LEN_MMI + 1);
				mmi_sim_get_home_plmn_num(SIM2, (S8 * )ghnum2, MAX_PLMN_LEN_MMI + 1);
			       if (strncmp(ghnum2, "46000", 5) == 0 || strncmp(ghnum2, "46002", 5) == 0 ||strncmp(ghnum2, "46007", 5) == 0)
					return CMCC;
				else if (strncmp(ghnum2, "46001", 5) == 0)
					return UNICOM;
			} 
			else 
			{
				memset(ghnum1, 0x00, MAX_PLMN_LEN_MMI + 1);
				mmi_sim_get_home_plmn_num(SIM1, (S8 * )ghnum1, MAX_PLMN_LEN_MMI + 1);
				if (strncmp(ghnum1, "46000", 5) == 0 || strncmp(ghnum1, "46002", 5) == 0 ||strncmp(ghnum2, "46007", 5) == 0)
					return CMCC;
				else if (strncmp(ghnum1, "46001", 5) == 0)
					return UNICOM;
			}
		}
	}
	else
	{
		if (vm_is_card1_mode())
		{
			memset(ghnum1, 0x00, MAX_PLMN_LEN_MMI + 1);
			mmi_sim_get_home_plmn_num(SIM1, (S8 * )ghnum1, MAX_PLMN_LEN_MMI + 1);
	        if (strncmp(ghnum1, "46000", 5) == 0 || strncmp(ghnum1, "46002", 5) == 0 ||strncmp(ghnum2, "46007", 5) == 0)
				return CMCC;
			else if (strncmp(ghnum1, "46001", 5) == 0)
				return UNICOM;
		}
		else if(vm_is_card2_mode())
		{
			memset(ghnum2, 0x00, MAX_PLMN_LEN_MMI + 1);
			mmi_sim_get_home_plmn_num(SIM2, (S8 * )ghnum2, MAX_PLMN_LEN_MMI + 1);
        	if (strncmp(ghnum2, "46000", 5) == 0 || strncmp(ghnum2, "46002", 5) == 0 ||strncmp(ghnum2, "46007", 5) == 0)
				return CMCC;
		 	else if (strncmp(ghnum2, "46001", 5) == 0)
		 		return UNICOM;
		}
	}
	return UNKOWN_OPERATOR;

#else

	VMCHAR ghnum[MAX_PLMN_LEN_MMI + 1];

	if (vm_has_sim_card() == FALSE)
	{
		return NO_SIM_CARD;
	}
	memset(ghnum, 0x00, MAX_PLMN_LEN_MMI + 1);
	mmi_sim_get_home_plmn_num(SIM1, (S8 * )ghnum, MAX_PLMN_LEN_MMI + 1);
	if (strncmp(ghnum, "46000", 5) == 0)
		return CMCC;
	else if (strncmp(ghnum, "46002", 5) == 0)
		return CMCC;
	else if (strncmp(ghnum, "46007", 5) == 0)
		return CMCC;
	else if (strncmp(ghnum, "46001", 5) == 0)
		return UNICOM;
	else
		return UNKOWN_OPERATOR;
  
#endif
}

VMINT vm_sim_card_count(void)
{
	VMINT retval = 0;

	if (mmi_bootup_get_active_flight_mode() == TRUE)
	{
		vm_log_error("vm_sim_card_count: flight mode");
		return 99;  
	}

#if !defined(__VRE_RB_09A__)
	if (mmi_netset_get_active_preferred_mode() == P_WLAN_ONLY)
	{
		return 0;
	}
#endif

#ifdef VRE_DUAL_SIM 	
	if (vm_is_card2_mode()==1 )
	{
		if (vm_is_card2Absent()==0)
		{
			retval = 1;
		}
		else
		{
			retval = 0;
		}
	}
	else if (vm_is_card1_mode()==1)   
	{
		if (vm_is_card1Absent()==0)
		{
			retval = 1;
		}
		else
		{
			retval = 0;
		}
	}
	else if(vm_is_dualcard_mode()==1)
	{
		if((vm_is_card2Absent()==0) && (vm_is_card1Absent()==0))    
		{
			retval = 2;
		}
		else if ((vm_is_card2Absent()==1) && (vm_is_card1Absent()==1))
		{
			retval = 0;
		}
		else
		{
			retval = 1;
		}
	}
#else
	{
  #if (defined(__VRE_RB_08A__))
		if (mmi_bootup_is_sim_valid())
			return 1;
		else
			return 0;
  #else
		VMUINT8 sim_status;
		VMUINT8 mode_status;
		mmi_idle_get_dual_sim_status(&sim_status, &mode_status);
		if (sim_status == MMI_SIM_ID_SIM1 && mode_status  == MMI_SIM_ID_SIM1)
			return 1;
		else
			return 0;
  #endif
	}
#endif		

	return retval;
}

VMINT vm_set_active_sim_card(VMINT simcard_id)
{
	VMINT retval = FALSE;
	
	if((vm_get_sim_card_status(simcard_id)) == VM_SIM_STATE_WORKING)
	{
		vm_selected_simcard = simcard_id;
		retval = TRUE;
		vm_log_debug("vm_set_active_sim_card : I have selected the %d simcard", simcard_id);
	}
	else
	{
		retval = FALSE;
		vm_log_debug("vm_set_active_sim_card : I failed to select the %d simcard", simcard_id);
	}
	return retval;
}

vm_sim_state_t vm_get_sim_card_status(VMINT card_id)
{
	vm_sim_state_t retval = VM_SIM_STATE_ERROR;

	//vm_log_debug("vm_get_sim_card_status - mmi_bootup_is_sim_removed=%d", mmi_bootup_is_sim_removed());
	//vm_log_debug("vm_get_sim_card_status - mmi_bootup_is_sim_valid=%d", mmi_bootup_is_sim_valid());
	//vm_log_debug("vm_get_sim_card_status - mmi_bootup_is_sim_access_error=%d", mmi_bootup_is_sim_access_error());
	//vm_log_debug("vm_get_sim_card_status - mmi_bootup_is_nw_registration_ok=%d", mmi_bootup_is_nw_registration_ok());
#ifdef VRE_DUAL_SIM /*双卡模式*/
	//vm_log_debug("vm_get_sim_card_status - mmi_bootup_is_sim2_removed=%d", mmi_bootup_is_sim2_removed());
	//vm_log_debug("vm_get_sim_card_status - mmi_bootup_is_sim2_valid=%d", mmi_bootup_is_sim2_valid());
	//vm_log_debug("vm_get_sim_card_status - mmi_bootup_is_sim2_access_error=%d", mmi_bootup_is_sim2_access_error());
	//vm_log_debug("vm_get_sim_card_status - mmi_bootup_is_sim2_nw_registration_ok=%d", mmi_bootup_is_sim2_nw_registration_ok());
#endif
	if (card_id <= VM_SIM_NO || card_id > VM_SIM_SIM2)
	{
		retval = VM_SIM_STATE_ERROR;
	}
	else
	{
#if !defined(__VRE_RB_09A__)
		if (mmi_netset_get_active_preferred_mode() == P_WLAN_ONLY)
		{
			return VM_SIM_STATE_VACANT;
		}
#endif
		
		#ifdef VRE_DUAL_SIM /*双卡模式*/
			if (card_id == VM_SIM_SIM2)
			{
				if (vm_is_card2Absent() != 0 ) /*SIM2未插*/
				{/* SIM2 is not in status */
					if (mmi_bootup_is_sim2_removed())
					{
						vm_log_error("vm_get_sim_card_status  : card2 is absent");
					}
					else if (!mmi_bootup_is_sim2_valid())
					{
						vm_log_error("vm_get_sim_card_status  : card2 invalid");
					}
					else
					{
						vm_log_error("vm_get_sim_card_status  : card2 absent for no reason");
					}
					retval = VM_SIM_STATE_VACANT;
				}
				else if (vm_is_dualcard_mode() == 1 || vm_is_card2_mode() == 1)
				{/* Card 2 mode is ok */
					if (!mmi_bootup_is_sim2_nw_registration_ok())
					{
						vm_log_error("vm_get_sim_card_status  : card2 is network register failed");
						retval = VM_SIM_STATE_NET_REG_FAILED;
					}
					else
					{
						vm_log_debug("vm_get_sim_card_status  : select card2 success");
						retval = VM_SIM_STATE_WORKING;
					}
				}
				else
				{
					vm_log_error("vm_get_sim_card_status  : will select card2, but card_mode is error");
					retval = VM_SIM_STATE_VACANT;
				}
			}
			else
			{
				if (vm_is_card1Absent() != 0 )/*SIM1未插*/
				{
				    if (mmi_bootup_is_sim_removed())
				    {
					vm_log_error("vm_get_sim_card_status  : card1 is absent");
				    }
				    else if (!mmi_bootup_is_sim_valid())
				    {
					vm_log_error("vm_get_sim_card_status  : card1 invalid");
				    }
				    else
				    {
				    }
					retval = VM_SIM_STATE_VACANT;
				}
				else if (vm_is_dualcard_mode() == 1 || vm_is_card1_mode() == 1)
				{/* Card 1 mode is ok */
					if (!mmi_bootup_is_nw_registration_ok())
					{
						vm_log_error("vm_get_sim_card_status  : card1 network register failed");
						retval = VM_SIM_STATE_NET_REG_FAILED;
					}
					else
					{
						vm_log_debug("vm_get_sim_card_status  : select card1 success");
						retval = VM_SIM_STATE_WORKING;
					}
				}
				else
				{
					vm_log_error("vm_get_sim_card_status  : will select card1, but card_mode is error");
					retval = VM_SIM_STATE_VACANT;
				}
			}
		#else
			if (card_id == VM_SIM_SIM2)
			{
				retval = VM_SIM_STATE_ERROR;
			}
			else
			{
#if (defined(__VRE_RB_08A__))
				if (mmi_bootup_is_sim_valid())
				{
					if (!mmi_bootup_is_nw_registration_ok())
					{
						vm_log_error("vm_get_sim_card_status  : card1 network register failed");
						retval = VM_SIM_STATE_NET_REG_FAILED;
					}
					else
					{
						retval = VM_SIM_STATE_WORKING;
					}
				}
				else
					retval = VM_SIM_STATE_VACANT;
#else
				VMUINT8 sim_status;
				VMUINT8 mode_status;
				mmi_idle_get_dual_sim_status(&sim_status, &mode_status);
				if (sim_status == MMI_SIM_ID_SIM1)
				{
					if (!mmi_bootup_is_nw_registration_ok())
					{
						vm_log_error("vm_get_sim_card_status  : card1 network register failed");
						retval = VM_SIM_STATE_NET_REG_FAILED;
					}
					else
					{
						retval = VM_SIM_STATE_WORKING;
					}
				}
				else
				{/* SIM2 not in status */
					if (mmi_bootup_is_sim_removed())
					{
						vm_log_error("vm_get_sim_card_status  : card1 is absent");
					}
					else if (!mmi_bootup_is_sim_valid())
					{
						vm_log_error("vm_get_sim_card_status  : card1 invalid");
					}
					else
					{
					}
					retval = VM_SIM_STATE_VACANT;
				}
#endif
			}

		#endif
	}
	return retval;
}

#endif
