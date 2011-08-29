#ifdef __VRE__
#include "vmlog.h"
#include "vmopt.h"
#include "vmsim.h"
#include "vmstdlib.h"
#include "vmsalmms.h"
#include "vmmacrostub.h"


/* ------------------------------------------------------------------------ */
/* ģ���ڲ�����������                                                                             */
/* ------------------------------------------------------------------------ */
 /*
  * Ӧ�ó������Ϣ�ص�������
  */
vm_mms_callback_type  vm_sal_mms_user_callback = NULL;

  /*
  * MMS����״̬��
  */
VMINT s_vm_sal_mms_sendstate = FALSE;

 /*
  * SIM ID�š�
  */
VMUINT s_vm_sal_sim_id;

VMINT s_vm_sal_send_mms_cancel = FALSE;
VMINT s_vm_sal_create_mms_success = FALSE;
VMUINT s_vm_sal_cur_mms_msg_id;

/* ------------------------------------------------------------------------ */
/* ģ���ڲ�����������                                                                              */
/* ------------------------------------------------------------------------ */
static VMINT vm_sal_mms_is_valid(void);

/* ------------------------------------------------------------------------ */
/* ����ʵ��                                                                                                         */
/* ------------------------------------------------------------------------ */
static VMINT vm_sal_mms_is_valid(void)
{
	if (sysconf.newwork_protocol.mms_support)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
void vm_sal_mms_modual_initialize(void)
{
	if(vm_sal_mms_is_valid())
	{
		vm_sal_mms_user_callback = NULL;
		s_vm_sal_send_mms_cancel = FALSE;
		s_vm_sal_create_mms_success = FALSE;
	}
}

void vm_sal_mms_modual_finialize(void)
{
	if (vm_sal_mms_is_valid())
	{
		vm_sal_mms_user_callback = NULL;
      		s_vm_sal_mms_sendstate = FALSE;
		s_vm_sal_send_mms_cancel = FALSE;
		s_vm_sal_create_mms_success = FALSE;
	}
  }


VMINT vm_sal_mms_send_mms(vm_send_mms_req_t * req_ptr,  vm_mms_callback_type callback)
{ 
	VMINT res = -1;

	vm_log_debug("vm_sal_mms_send_mms:start!");
	if(vm_sal_mms_is_valid())
	{
		vm_log_debug("vm_sal_mms_send_mms:valid = %d",vm_sal_mms_is_valid());
		if(req_ptr == NULL)
		{
			vm_log_error("vm_sal_mms_send_mms:req_ptr == NULL");
			return VM_MMS_FAIL;
		}

		if(s_vm_sal_mms_sendstate)
		{
			vm_log_error("vm_sal_mms_send_mms:mms_state == 1");
			return VM_MMS_FAIL;
		}
     
		vm_sal_mms_user_callback = callback;
		s_vm_sal_mms_sendstate = TRUE;
		s_vm_sal_send_mms_cancel = FALSE;
       	s_vm_sal_sim_id = req_ptr->sim_id;

		vm_log_debug("vm_sal_mms_send_mms:create req");
		res = vm_sal_mms_create_req( req_ptr);
	}
	vm_log_debug("vm_sal_mms_send_mms:end!");
       return res;
}

void vm_sal_mms_cancel_send_mms(void)
{
	vm_sal_stub_mms_cancel_send_mms();
}
#endif/*__VRE__*/


