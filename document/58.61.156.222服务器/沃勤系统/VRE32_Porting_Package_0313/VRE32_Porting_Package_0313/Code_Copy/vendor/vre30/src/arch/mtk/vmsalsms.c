#ifdef __VRE__
#include "mmi_include.h"
#include "SimDetectionGprot.h"
#include "mmi_msg_context.h"

#include "string.h"
#include "vmmod.h"
#include "vmsys.h"
#include "vmio.h"
#include "vmlog.h"
#include "vmopt.h"
#include "vmstdlib.h"
#include "vmchset.h"
#include "vmsim.h"
#include "vmmem.h"
#include "vmmacrostub.h"

#include "vmsms.h"
#include "vmresmng.h"

#if defined(__VRE_RB_08A__ ) || defined(__VRE_RB_08B__ )
#include "SMSApi.h"//ltz
#include "SmsGuiInterfaceProt.h"//ltz
#include "SMSStruct.h"
#elif defined(__VRE_RB_09A__)
#include "SMSStruct.h"
#include "SMSFunc.h"
#else
#include "SmsSrvGprot.h"
#endif


/* ------------------------------------------------------------------------ */
/* 系统全局变量声明。                                                       */
/* ------------------------------------------------------------------------ */
#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
extern VMINT vre_running;
#else

extern VMINT vm_selected_simcard;
/* changed by zaiping.chen, 2010.07.15, static memory optimize, begin */
//srv_sms_msg_data_struct  vm_read_data;
//VMINT16  content_buffer[VM_SMS_MSG_CONTENT_LEN+1];
srv_sms_msg_data_struct *sms_data;
VMWSTR sms_content;
/* changed by zaiping.chen, 2010.07.15, static memory optimize, end */
#endif

//extern VMUINT16  smssend_state;

//#if defined(__VRE_RB_09B__)
#if (!defined(__VRE_RB_09A__) && !defined(__VRE_RB_08A__))
/* changed by zaiping.chen, 2010.07.15, static memory optimize, begin */
//srv_sms_msg_data_struct  vm_read_data;
//VMINT16  content_buffer[VM_SMS_MSG_CONTENT_LEN+1];
srv_sms_msg_data_struct *sms_data;
VMWSTR sms_content;
/* changed by zaiping.chen, 2010.07.15, static memory optimize, end */
#endif

/* ------------------------------------------------------------------------ */
/* 系统函数声明。                                                           */
/* ------------------------------------------------------------------------ */
#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
extern U16 mmi_frm_sms_get_sms_list_size (U16 type);
extern U8 mmi_frm_sms_check_action_pending(void);
extern U16 UnicodeToAnsii(S8 *pOutBuffer, S8 *pInBuffer );
extern void AlmEnableSPOF(void);
extern EMSData * GetEMSDataForEdit (EMSData ** p, U8 force);
extern void mmi_frm_sms_abort_sending_sms(mmi_frm_sms_abort_enum type);
extern EMSData *GetEMSDataForView(EMSData **p, U8 force);
extern void vm_sms_callback(vm_sms_callback_t* callback_data);

extern void vm_sal_sms_select_simcard( mmi_frm_sms_send_struct * sendData);
extern VMINT vm_sal_sms_delete_msg_list(vm_sms_box_enum box_type,  vm_sms_sim_enum sim_id, VmSmsCallbackFunc callback_func,  void* user_data, VMINT * cause);
extern VMINT vm_sal_sms_get_msg_id_list(vm_sms_query_t* query_data,  VmSmsCallbackFunc callback_func,  void* user_data,VMINT * cause);
extern VMINT16 vm_sal_sms_get_msg_id(vm_sms_box_enum box_type, VMUINT16 msg_index);
extern  VMINT vm_sms_convert_box(vm_sms_box_enum box_type);
extern void vm_sms_read_msg_callback(void *data, module_type mod, U16 result);
extern VMUINT8 vm_sms_interrupt_action(void *data, int withobject, void *content);
extern VMUINT8 vm_sms_interrupt_callback(void *data, void *content);

VMINT vm_sms_sys_set_interrupt_event_handler(void);
VMINT vm_sms_sys_clear_interrupt_event_handler(void);

#else

//extern void  mmi_frm_sms_abort_sending_sms(mmi_frm_sms_abort_enum type);
//extern VMINT vm_sms_send_callback(srv_sms_callback_struct* callback_data);
extern pBOOL mmi_bootup_get_active_flight_mode(void);
extern void vm_sms_callback(srv_sms_callback_struct* callback_data);
extern void srv_sms_set_storage_type(SMS_HANDLE sms_handle, srv_sms_storage_enum storage_type);
#endif

/* ------------------------------------------------------------------------ */
/* 模块内部变量声明。                                                       */
/* ------------------------------------------------------------------------ */
#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
/*
 * 短消息服务的系统变量声明。
 */
//static U8 vm_DeliveryRepyStates[2];
/*
  * 短消息发送状态。TRUE=不可以发送， FALSE=可以发送
  */
//static U16 smsbusy_state = TRUE;

#define  VM_SMS_NUM0    L'0'
#define  VM_SMS_NUM1    L'1'
#define  VM_SMS_NUM3    L'3'
#define  VM_SMS_NUM5    L'5'
#define  VM_SMS_NUM8    L'8'

/*
  * 是否设置完毕mmi状态报告的发送1为还没有设置，0表示
  * 设置完毕。
  */
//static U8 ic_gCloseDeliveryRepyStatesFlag = 0;
#else

static SMS_HANDLE smssend_handle = NULL;
#endif

/* ------------------------------------------------------------------------ */
/* 模块内部函数声明。                                                       */
/* ------------------------------------------------------------------------ */

#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
static VMINT vm_sms_convert_status(VMINT status);
#endif

static VMINT vm_send_sms_request(S8*number, U16* content);
//#if defined(__VRE_RB_09B__)
#if (!defined(__VRE_RB_09A__) && !defined(__VRE_RB_08A__))
void vm_sal_cancel_send_sms(void);

static VMINT vm_sms_interrupt_event_callback(srv_sms_event_struct* event_data);
static VMINT vm_sms_sys_set_interrupt_event_handler(vm_sms_event_enum event_id);
static VMINT vm_sms_sys_clear_interrupt_event_handler(vm_sms_event_enum event_id);
#endif

 VMINT vm_sal_initialize_sms_module(void)
{
#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))

    vm_sms_sys_set_interrupt_event_handler();
#else
    vm_sms_sys_set_interrupt_event_handler(VM_EVT_ID_SMS_NEW_MSG);

	/* add by zaiping.chen, 2010.07.15, static memory optimize, begin */
	vm_log_debug("static memory optimize: vm_sal_initialize_sms_module");
	sms_data = vm_malloc(sizeof(srv_sms_msg_data_struct));
	if (NULL == sms_data)
	{
		vm_log_error("vm_sal_initialize_sms_module - vm_malloc fail.");
		return -1;
	}
	sms_content = vm_malloc((VM_SMS_MSG_CONTENT_LEN + 1) * sizeof(VMINT16));
	if (NULL == sms_content)
	{
		vm_log_error("vm_sal_initialize_sms_module - vm_malloc fail.");
		vm_free(sms_data);
		sms_data = NULL;
		return -2;
	}
	/* add by zaiping.chen, 2010.07.15, static memory optimize, end */

#endif
	return 0;
}

 VMINT vm_sal_finialize_sms_module(void)
{

	//vm_sal_cancel_send_sms();	
//#if defined(__VRE_RB_09B__)
#if (!defined(__VRE_RB_09A__) && !defined(__VRE_RB_08A__))
	smssend_handle = NULL;
	/* changed by zaiping.chen, 2010.07.15, static memory optimize, begin */
	//memset(&vm_read_data, 0, sizeof(srv_sms_msg_data_struct));
	//memset(&content_buffer, 0, sizeof(VMINT16)*(VM_SMS_MSG_CONTENT_LEN+1));
	vm_log_debug("static memory optimize: vm_sal_finialize_sms_module");
	if (NULL != sms_data)
	{
		vm_free(sms_data);
		sms_data = NULL;
	}
	if (NULL != sms_content)
	{
		vm_free(sms_content);
		sms_content = NULL;
	}
	/* changed by zaiping.chen, 2010.07.15, static memory optimize, end */
#endif
#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
	vm_sms_sys_clear_interrupt_event_handler();
#else
	vm_sms_sys_clear_interrupt_event_handler(VM_EVT_ID_SMS_NEW_MSG);
#endif
	return 0;
}

/*
void vm_sal_cancel_send_sms(void)
{
	//if (smssend_state == TRUE)
	//{
		vm_log_debug("vm_cancel_send_sms start");
		mmi_frm_sms_abort_sending_sms(MMI_FRM_SMS_ABORT_WITH_FINISH_IND);
	//}
}
*/
#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
VMINT vm_sal_send_sms(VMWSTR phone_number, VMWSTR content, void (*callback)(VMINT result),VMINT * cause) 
{
	VMCHAR phn[VM_SMS_MAX_ADDR_LEN];
#else
VMINT vm_sal_send_sms(VMWSTR phone_number, VMWSTR content, void (*callback)(VMINT result)) 
{
#endif	

	VMINT retval = FALSE;

	if (mmi_bootup_get_active_flight_mode() == TRUE)
	{
		vm_log_debug("vm_send_sms: flight mode");
		return FALSE;
	}

	vm_log_debug("vm_send_sms phonenumber : %s", vm_gb2312_string(phone_number));
	//vm_log_debug("vm_send_sms content : %s", vm_gb2312_string(content));
#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
		vm_ucs2_to_default(phn, VM_SMS_MAX_ADDR_LEN, phone_number);
		vm_log_debug("vm_send_sms phonenumber : %s", phn);
	if (vm_send_sms_request((S8 *)phn, (U16 *) content) == 0)
#else
	if (vm_send_sms_request((S8 *)phone_number, (U16 *) content) == 0)
#endif	
			retval = TRUE;
	else
			retval = FALSE;

	return retval;
}

#if (defined(__VRE_RB_09A__) || defined(__VRE_RB_08A__))
VMINT vm_sal_send_sms_person(VMWSTR phone_number, VMWSTR content, void (*callback)(VMINT result)) 
{
	//VMCHAR temp[80];
	VMCHAR phn[VM_SMS_MAX_ADDR_LEN];
	VMINT retval = FALSE;

	if (vm_sim_card_count() <= 0)
	{
		vm_log_debug("vm_send_sms_person: no sim card");
		return FALSE;
	}
	if (mmi_bootup_get_active_flight_mode() == TRUE)
	{
		vm_log_debug("vm_send_sms_person: flight mode");
		return FALSE;
	}
	

		//vm_ucs2_to_gb2312(phn, VM_SMS_MAX_ADDR_LEN, phone_number);
		vm_ucs2_to_default(phn, VM_SMS_MAX_ADDR_LEN, phone_number);

		
		//vm_ucs2_to_gb2312(temp, 80, phone_number);
		//vm_log_debug("vm_send_sms_person phonenumber : %s", temp);
		//vm_ucs2_to_gb2312(temp, 80, content);
		//vm_log_debug("vm_send_sms_person content : %s", temp);
		if (vm_send_sms_request((S8 *)phn, (U16 *) content) == 0)
			retval = TRUE;
		else
			retval = FALSE;
			

	vm_log_debug("vm_send_sms_person : retval=%d", retval);
	return retval;
}

VMINT vm_send_sms_response(void *dummy, module_type mod, U16 flag)
{
	vm_sms_callback_t callback_data;
	VMINT result = FALSE;
	
	if(vre_running == FALSE)
	{
		return TRUE;
	}
	memset(&callback_data, 0, sizeof(vm_sms_callback_t));
		
	vm_log_debug("vm_send_sms_response : flag=%d", flag);
	switch(flag)
	{
		case MMI_FRM_SMS_OK:
        	//send success
		
			result = TRUE;
			callback_data.result = VM_SMS_RESULT_OK;
			callback_data.cause = VM_SMS_CAUSE_NO_ERROR;
        		break;
		case MMI_FRM_SMS_ABORT:
		case MMI_FRM_SMS_RETURN:
             	case MMI_FRM_SMS_END:
		case MMI_FRM_SMS_END_FROM_SENDING:
         	case MMI_FRM_SMS_NUMINVALID:
		case MMI_FRM_SMS_SC_EMPTY:
             	case MMI_FRM_SMS_DATAEXCEED:
 		default:
        		result = FALSE;
			callback_data.result = VM_SMS_RESULT_ERROR;
			callback_data.cause = VM_SMS_CAUSE_DATA_INVALID;
        		break;
	}
	callback_data.action = VM_SMS_ACTION_SEND;
	
	vm_sms_callback(&callback_data);
	return result;
}
VMINT vm_send_sms_request(S8* number, U16* content)
{
	//	VMCHAR plmn[8]={0};

		VMINT is_ucs2 = FALSE;
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_sms_send_struct * sendData = vm_malloc(sizeof(mmi_frm_sms_send_struct));//You'd better not allocate memory like this.

    if (sendData == NULL)
		return -1;

	 /* if (vm_query_operator_code(plmn, sizeof(plmn))!= 0)
		{
			vm_free(sendData);
			return -1;
		}*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    //vm_log_debug("vm_send_sms_request : set Data");
    memset((S8*) sendData, 0, sizeof(mmi_frm_sms_send_struct));

    memset((S8*) sendData->number, 0, sizeof(sendData->number));
    //mmi_ucs2ncpy((S8*) sendData->number, (S8*)number, 21);
    strncpy((S8*)sendData->number, (S8*)number, MAX_DIGITS_SMS);

	/*	if((strstr(plmn, "51010") != NULL ) || (strstr(plmn, "51011") != NULL ) || (strstr(plmn, "51089") != NULL ) || (strstr(plmn, "51008") != NULL ))
		{
		
			sendData->dcs = SMSAL_8BIT_DCS;
		}
		else*/
		{
		
			is_ucs2 = mmi_frm_sms_check_UCS2(content, mmi_wcslen(content));
			  if(is_ucs2 == TRUE)
			  {
			   	sendData->dcs = SMSAL_UCS2_DCS;
			  }
			  else
			  {
			  	 sendData->dcs = SMSAL_DEFAULT_DCS;
			  }
			 
			  
			 sendData->stringlength = mmi_wcslen(content);//only if content is UCS2 format
   			 sendData->string = get_ctrl_buffer((sendData->stringlength + 1) * ENCODING_LENGTH);//do not free this memory.!!

   			 if (sendData->string == NULL)
   			 {
     			   vm_free(sendData);
	 			return -1;
  			 }
  		
  			 mmi_wcsncpy((U16 *) sendData->string, (U16 *) content, sendData->stringlength);
		}
  

    sendData->sendcheck |= MMI_FRM_SMS_SCR;/* do not display sending screen */
    sendData->sendcheck |= MMI_FRM_SMS_SC;

	
  /*  #ifdef VRE_DUAL_SIM    	
	
		if (vm_selected_simcard == 1)
		{
			vm_log_debug("vm_send_sms_request : set sendrequire 1");
			sendData->sendrequire |= MMI_FRM_SMS_SEND_BY_SIM1;
		}
		else if  (vm_selected_simcard == 2)
		{
			vm_log_debug("vm_send_sms_request : set sendrequire 2");
    			sendData->sendrequire |= MMI_FRM_SMS_SEND_BY_SIM2; 
		}
		else
		{
			vm_log_debug("vm_send_sms_request : set sendrequire 1");
			sendData->sendrequire |= MMI_FRM_SMS_SEND_BY_SIM1; 
		}
	
#endif  */
 	 vm_sal_sms_select_simcard(sendData);
	
	//vm_log_debug("vm_send_sms_request : before mmi_frm_sms_send_sms_for_other_app");
	
      /*设置正在发送，无法接受下一条*/
     
       mmi_frm_sms_send_sms_for_other_app((PsFuncPtrU16)vm_send_sms_response, MOD_MMI, sendData);
	//vm_log_debug("vm_send_sms_request : after mmi_frm_sms_send_sms_for_other_app");  

	vm_free(sendData);    
	return 0;
}

/*
static void vm_sms_read_msg_callback(void *data, module_type mod, U16 result)
{
	vm_sms_callback_t callback_data;
	vm_sms_read_msg_cb_t   msg_ptr;
	vm_sms_msg_data_t * read_msg = NULL;
	VMINT8 *content = NULL;
		 

	VMUINT16 type;
	VMUINT16 sms_frm_type;
		
	vm_log_debug("vm_sms_read_sms_callback:result=%d", result);

	if(vre_running == FALSE)
	{
		return;
	}
	
	memset(&callback_data, 0, sizeof(vm_sms_callback_t));

	if (result != MMI_FRM_SMS_OK)
	{
      
		callback_data.result = FALSE;
		callback_data.cause = VM_SMS_CAUSE_DATA_INVALID;
	}
	else
	{
		EMSData *pEms;
 		
		type = *(U16*)data;
		vm_log_debug("vm_sms_read_sms_callback:type=%d", type);
		GetEMSDataForView(&pEms, 0);
		read_msg = _vm_kernel_calloc(sizeof(vm_sms_msg_data_t));
		if(read_msg == NULL)
		{
			callback_data.result = FALSE;
			callback_data.cause = VM_SMS_CAUSE_DATA_INVALID;
			vm_sms_callback(&callback_data);
			return;
			
		}
		msg_ptr.msg_data = read_msg;
		
		sms_frm_type = type & 0x0FFF;
		vm_log_debug("vm_sms_read_sms_callback:sms_frm_type=%d", sms_frm_type);
		switch (sms_frm_type)
		{
			case MMI_FRM_SMS_APP_UNREAD:
			case MMI_FRM_SMS_APP_INBOX:
			                       
				if (sms_frm_type == MMI_FRM_SMS_APP_UNREAD)
                            {
 					read_msg->status = VM_SMS_STATUS_UNREAD;
                            }
                            else
                            {
					read_msg->status  = VM_SMS_STATUS_READ;
                            }
                   
				break;
                    

			case MMI_FRM_SMS_APP_OUTBOX:
				 read_msg->status  = VM_SMS_STATUS_SENT;
				break;

			case MMI_FRM_SMS_APP_DRAFTS:
				 read_msg->status  = VM_SMS_STATUS_DRAFT;
				break;

#ifdef __MMI_UNIFIED_MESSAGE__
			case MMI_FRM_SMS_APP_UNSENT:	
				 read_msg->status  = VM_SMS_STATUS_UNSENT;
				break;
#endif
                
			default:
				 read_msg->status  = VM_SMS_STATUS_UNSUPPORTED;
				 callback_data.result = FALSE;
				callback_data.cause = VM_SMS_CAUSE_DATA_INVALID;
                        break;
		}
		
		if(read_msg->status != VM_SMS_STATUS_UNSUPPORTED)
		{
			content =  _vm_kernel_calloc(pEms->textLength+2);
			if(content == NULL)
			{
				callback_data.result = FALSE;
				callback_data.cause = VM_SMS_CAUSE_DATA_INVALID;
				vm_sms_callback(&callback_data);
				_vm_kernel_free(read_msg);
				return;
			}
			read_msg->content_buff = content;
		//read_msg->number
		//read_msg->mti
		//read_msg->tp_st
		//read_msg->folder_id
		//read_msg->para_flag
		//read_msg->storage_type
		//read_msg->sim_id
		//read_msg->timestamp
		//read_msg->sc_address
		//read_msg->pid
		//read_msg->vp
		//read_msg->status_report
		//read_msg->reply_path
		read_msg->src_port = pEms->PortNum.src_port;
		read_msg->dest_port = pEms->PortNum.dst_port;
		read_msg->dcs = pEms->dcs;
	
		read_msg->content_buff_size = pEms->textLength + 2;
		vm_wstrncpy((VMWSTR)read_msg->content_buff, (VMWSTR)pEms->textBuffer, (read_msg->content_buff_size-2)/2);
		
		read_msg->dcs = pEms->dcs;
		vm_log_debug("vm_sms_read_sms_callback:read_msg->dcs = %d", read_msg->dcs);
		
		vm_log_debug("vm_sms_read_sms_callback:vm_gb2312_string((VMWSTR)read_msg->content_buff) =%s", vm_gb2312_string((VMWSTR)read_msg->content_buff));
		vm_log_debug("vm_sms_read_sms_callback: vm_gb2312_string((VMWSTR)pEms->textBuffer) =%s", vm_gb2312_string((VMWSTR)pEms->textBuffer));
		vm_log_debug("vm_sms_read_sms_callback:pEms->textBuffer =%s", pEms->textBuffer);
		
		vm_log_debug("vm_sms_read_sms_callback:pEms->textLength = %d", pEms->textLength);

		callback_data.result = TRUE;
		callback_data.cause = VM_SMS_CAUSE_NO_ERROR;
			
		}
	}
              
    
	callback_data.action = VM_SMS_ACTION_READ;
	callback_data.user_data = NULL;
	callback_data.action_data = &msg_ptr;
	
	vm_sms_callback(&callback_data);
	
	_vm_kernel_free(read_msg);
	_vm_kernel_free(content);
		

}
*/

VMINT vm_sal_sms_read_msg(VMUINT16 msg_id, VMINT change_status,  vm_sms_msg_data_t* msg_data, 
	            VmSmsCallbackFunc  callback_func, void* user_data,VMINT * cause)
{
	VMUINT16 type;
	VMUINT16 index;
	

	mmi_frm_sms_get_list_index(&type, &index, msg_id);
	
	if(type == MMI_FRM_SMS_INVALID_INDEX || index == MMI_FRM_SMS_INVALID_INDEX)
	{
		vm_log_error("vm_sms_read_msg : type == MMI_FRM_SMS_INVALID_INDEX ");
		return VM_SMS_REQ_ERROR;
	}

	
	mmi_frm_sms_read_sms( vm_sms_read_msg_callback, MOD_MMI, type, index, change_status);
	return VM_SMS_REQ_NO_ERROR;
      
}

static void vm_sms_add_msg_callback(void *data, module_type mod, U16 result)
{
	vm_sms_callback_t callback_data;
	vm_sms_save_msg_cb_t  add_msg_ptr ;
	VMINT16 msg_id = 0;
	
	vm_log_debug("vm_sms_add_msg_callback:result=%d", result);

	if(vre_running == FALSE)
	{
		return;
	}
	memset(&callback_data, 0, sizeof(vm_sms_callback_t));
	
	switch(result)
	{
		case MMI_FRM_SMS_OK:
	 		
		
			msg_id = *((VMINT16*)data);
			vm_log_debug("vm_sms_add_sms_callback:msg_id=%d", msg_id);
			callback_data.result = TRUE;
			callback_data.cause = VM_SMS_CAUSE_NO_ERROR;
			break;
		case MMI_FRM_SMS_ERROR:
				
		case MMI_FRM_SMS_RETURN:
	                
		case MMI_FRM_SMS_END:
	           	
		case MMI_FRM_SMS_END_FROM_SENDING:
	        	 
		case MMI_FRM_SMS_NUMINVALID:
	        		
		case MMI_FRM_SMS_SC_EMPTY:
		       
		case MMI_FRM_SMS_DATAEXCEED:
		        
		default:
		       	 		
			callback_data.result = FALSE;
			callback_data.cause = VM_SMS_CAUSE_DATA_INVALID;
			break;
	}
	
	callback_data.action = VM_SMS_ACTION_SAVE;
	callback_data.user_data = NULL;
	callback_data.action_data = &add_msg_ptr;
	add_msg_ptr.msg_id = msg_id;
	
	vm_sms_callback(&callback_data);
			
	vm_log_debug("vm_sms_add_msg_callback:end");
}

VMINT vm_sal_sms_add_msg(vm_sms_add_msg_data_t * msg_data, VmSmsCallbackFunc callback_func, void* user_data,VMINT * cause)
{
	mmi_frm_sms_send_struct * sendData = NULL;
	VMCHAR phn[VM_SMS_MAX_ADDR_LEN] = {0};
	VMINT status;
	
	vm_log_debug("vm_sal_sms_add_msg:start,msg_data->status=%x",msg_data->status);
	
	status =  vm_sms_convert_status(msg_data->status);
	if(status == VM_SMS_REQ_ERROR)
	{
		vm_log_error("vm_sal_sms_add_msg :status == VM_SMS_REQ_ERROR");
		return VM_SMS_REQ_ERROR;
	}
	vm_log_debug("vm_sal_sms_add_msg:status=%x",status);
	sendData = vm_calloc(sizeof(mmi_frm_sms_send_struct));
	if(sendData == NULL)
	{
		vm_log_error("vm_sal_sms_add_msg : sendData == NULL");
		return VM_SMS_REQ_ERROR;
	}

	
	sendData->dcs = SMSAL_UCS2_DCS;
	sendData->status =status;
	sendData->stringlength = vm_wstrlen((VMWSTR)msg_data->content);//only if content is UCS2 format
	sendData->string = get_ctrl_buffer((sendData->stringlength + 1) * ENCODING_LENGTH);//do not free this memory.!!

	if (sendData->string == NULL)
	{
		vm_free(sendData);
		return VM_SMS_REQ_ERROR;
	}
	//vm_ucs2_to_gb2312(phn, VM_SMS_MAX_ADDR_LEN, (VMWSTR)msg_data->number);
	vm_ucs2_to_default(phn, VM_SMS_MAX_ADDR_LEN, (VMWSTR)msg_data->number);
	
	strncpy((S8*)sendData->number, (S8*)phn, VM_SMS_MAX_ADDR_LEN);
	
	vm_log_debug("vm_sal_sms_add_msg:sendData->numbe=%s",sendData->number);
	
	vm_wstrncpy((VMWSTR)sendData->string, (VMWSTR)msg_data->content, vm_wstrlen((VMWSTR)msg_data->content));

	//sms_callback = callback_func;
	mmi_frm_sms_save_sms_for_other_app(vm_sms_add_msg_callback, MOD_MMI, sendData);

	vm_free(sendData);
	vm_log_debug("vm_sal_sms_add_msg:end");
	return VM_SMS_REQ_NO_ERROR;
	
}

static void vm_sms_delete_msg_callback(void *data, module_type mod, U16 result)
{
	vm_sms_callback_t callback_data;
	
	vm_log_debug("vm_sms_delete_msg_callback:result=%d", result);
	memset(&callback_data, 0, sizeof(vm_sms_callback_t));

	if(vre_running == FALSE)
	{
		return;
	}
	switch(result)
	{
		case MMI_FRM_SMS_OK:
	 		
			callback_data.result = TRUE;
			callback_data.cause = VM_SMS_CAUSE_NO_ERROR;
			break;
			
		case MMI_FRM_SMS_ERROR:
				
		case MMI_FRM_SMS_RETURN:
	                
		case MMI_FRM_SMS_END:
	           	
		case MMI_FRM_SMS_END_FROM_SENDING:
	        	 
		case MMI_FRM_SMS_NUMINVALID:
	        		
		case MMI_FRM_SMS_SC_EMPTY:
		       
		case MMI_FRM_SMS_DATAEXCEED:
		        
		default:
		       	 		
			callback_data.result = FALSE;
			callback_data.cause = VM_SMS_CAUSE_DATA_INVALID;
			break;
	}
	
	callback_data.action = VM_SMS_ACTION_DELETE;
	callback_data.user_data = NULL;
	callback_data.action_data = NULL;
	
	vm_sms_callback(&callback_data);
	
	vm_log_debug("vm_sms_delete_msg_callback:end");
}

VMINT vm_sal_sms_delete_msg(VMUINT16 msg_id, VmSmsCallbackFunc callback_func,  void* user_data,VMINT * cause)
{
	VMUINT16 type;
	VMUINT16 index;
	
	vm_log_debug("vm_sal_sms_delete_msg:start");
	
	mmi_frm_sms_get_list_index(&type, &index, msg_id);
	
	if(type == MMI_FRM_SMS_INVALID_INDEX || index == MMI_FRM_SMS_INVALID_INDEX)
	{
		vm_log_error("vm_sal_sms_delete_msg : type == MMI_FRM_SMS_INVALID_INDEX ");
		return VM_SMS_REQ_ERROR;
	}
		
	mmi_frm_sms_delete_sms(vm_sms_delete_msg_callback, MOD_MMI, type, index);
	vm_log_debug("vm_sal_sms_delete_msg:end");
	
	return VM_SMS_REQ_NO_ERROR;
}

VMINT vm_sal_sms_delete_msg_for_interrupt(VMUINT16 index, VmSmsCallbackFunc callback_func,  void* user_data,VMINT * cause)
{
	
	vm_log_debug("vm_sal_sms_delete_msg:start");
	

	//mmi_frm_sms_delete_sms(vm_sms_delete_msg_callback, MOD_MMI, MMI_FRM_SMS_INBOX, index);
    mmi_frm_sms_delete_sms(vm_sms_delete_msg_callback, MOD_MMI, MMI_FRM_SMS_APP_AWAITS, index);
	vm_log_debug("vm_sal_sms_delete_msg:end");
	
	return VM_SMS_REQ_NO_ERROR;
}



 void vm_sms_delete_msg_list_callback(void *data, module_type mod, U16 result)
{
	vm_sms_callback_t callback_data;
		
	vm_log_debug("vm_sms_delete_msg_list_callback:result=%d", result);

	if(vre_running == FALSE)
	{
		return;
	}
	memset(&callback_data, 0, sizeof(vm_sms_callback_t));

	switch(result)
	{
		case MMI_FRM_SMS_OK:
	 		
			callback_data.result = TRUE;
			callback_data.cause = VM_SMS_CAUSE_NO_ERROR;
			break;
			
		case MMI_FRM_SMS_ERROR:
				
		case MMI_FRM_SMS_RETURN:
	                
		case MMI_FRM_SMS_END:
	           	
		case MMI_FRM_SMS_END_FROM_SENDING:
	        	 
		case MMI_FRM_SMS_NUMINVALID:
	        		
		case MMI_FRM_SMS_SC_EMPTY:
		       
		case MMI_FRM_SMS_DATAEXCEED:
		        
		default:
		       	 		
			callback_data.result = FALSE;
			callback_data.cause = VM_SMS_CAUSE_DATA_INVALID;
			break;
	}

	
	callback_data.action = VM_SMS_ACTION_DELETE;
	callback_data.user_data = NULL;
	callback_data.action_data = NULL;
			
	vm_log_debug("vm_sms_delete_msg_list_callback:callback_data.action=%d", callback_data.action);
	vm_sms_callback(&callback_data);

	vm_log_debug("vm_sms_delete_msg_list_callback:END");
}
/*OK*/
VMINT16 vm_sal_sms_get_box_size(vm_sms_box_enum box_type)
{
	
	VMUINT16 size = 0;
	VMUINT16 type;
	
	vm_log_debug("vm_sal_sms_get_box_size:start box_type=%d",box_type);

	type = vm_sms_convert_box( box_type);
	if(type == VM_SMS_REQ_ERROR)
	{
		vm_log_error("vm_sal_sms_get_box_size:type == VM_SMS_REQ_ERROR");
		return VM_SMS_REQ_ERROR;
	}
	vm_log_debug("vm_sal_sms_get_box_size: type=%d",type);
	size =  mmi_frm_sms_get_sms_list_size( type);
	vm_log_debug("vm_sal_sms_get_box_size:size=%d, type=%d", size, type);
	
	return size;
	   	
}

/*OK*/
 void vm_sms_get_sc_address_callback(void *data, module_type mod, U16 result)
{
		
	vm_sms_callback_t callback_data;
	vm_sms_get_sc_addr_cb_t  sc_addr_cb;
	
	vm_log_debug("vm_sms_get_sc_address_callback:result=%d", result);
	
	if(vre_running == FALSE)
	{
		return;
	}
	
	memset(&sc_addr_cb, 0, sizeof(vm_sms_get_sc_addr_cb_t));
	
	switch(result)
		
	{
		case MMI_FRM_SMS_OK:
	 					
			//vm_wstrncpy((VMWSTR)&vm_sc_addr, (VMWSTR)data, VM_SMS_MAX_ADDR_LEN);
			if(data)
			{
#if (defined(__VRE_RB_08B__) || defined(__VRE_RB_08A__))

				vm_log_debug("vm_sms_get_sc_address_callback:vm_wstrlen((VMWSTR)data)=%d", vm_wstrlen((VMWSTR)((msg_profile_edit_struct *)data)->scAddress));//ltz
				vm_log_debug("vm_sms_get_sc_address_callback: vm_gb2312_string((VMWSTR)data)=%s", vm_gb2312_string((VMWSTR)((msg_profile_edit_struct *)data)->scAddress));//ltz
						
				//vm_ucs2_to_gb2312((VMSTR)sc_addr_cb.sc_addr, VM_SMS_MAX_ADDR_LEN, (VMWSTR)data);
				vm_ucs2_to_default((VMSTR)sc_addr_cb.sc_addr, VM_SMS_MAX_ADDR_LEN, (VMWSTR)((msg_profile_edit_struct *)data)->scAddress);//ltz
#else
				vm_log_debug("vm_sms_get_sc_address_callback:vm_wstrlen((VMWSTR)data)=%d", vm_wstrlen((VMWSTR)data));
				vm_log_debug("vm_sms_get_sc_address_callback: vm_gb2312_string((VMWSTR)data)=%s", vm_gb2312_string((VMWSTR)data));
						
				//vm_ucs2_to_gb2312((VMSTR)sc_addr_cb.sc_addr, VM_SMS_MAX_ADDR_LEN, (VMWSTR)data);
				vm_ucs2_to_default((VMSTR)sc_addr_cb.sc_addr, VM_SMS_MAX_ADDR_LEN, (VMWSTR)data);
#endif			
				
				vm_log_debug("vm_sms_get_sc_address_callback:sc_addr=%s, strlen(sc_addr)=%d", sc_addr_cb.sc_addr, strlen(sc_addr_cb.sc_addr));
			}
			callback_data.result = TRUE;
			callback_data.cause = VM_SMS_CAUSE_NO_ERROR;
			break;
		case MMI_FRM_SMS_ERROR:
				
		case MMI_FRM_SMS_RETURN:
	                
		case MMI_FRM_SMS_END:
	           	
		case MMI_FRM_SMS_END_FROM_SENDING:
	        	 
		case MMI_FRM_SMS_NUMINVALID:
	        		
		case MMI_FRM_SMS_SC_EMPTY:
		       
		case MMI_FRM_SMS_DATAEXCEED:
		        
		default:
		   			
			callback_data.result = FALSE;
			callback_data.cause = VM_SMS_CAUSE_DATA_INVALID;
			break;
	 }
	
	
	callback_data.action = VM_SMS_ACTION_GET_SC_ADDR;
	callback_data.action_data = &sc_addr_cb;
		
	vm_sms_callback(&callback_data);
	
	vm_log_debug("vm_sms_get_sc_address_callback:end");
	
}


/*
VMUINT8 vm_sms_new_msg(void *data, int withobject, void *content)
{
   
    mmi_frm_sms_deliver_msg_struct *msg = (mmi_frm_sms_deliver_msg_struct*) data;
    U8 number[MAX_DIGITS_SMS + 1] = {0};

    if (msg->display_type == SMSAL_MSG_TYPE_CLASS0
#ifdef __MMI_DUAL_SIM_MASTER__
		|| msg->display_type == MMI_FRM_SMS_TYPE_CLASS0_SLAVE
#endif
       )
    {
    	  mmi_frm_sms_convert_l4_num_to_ascii_num(number, &msg->addr_number, MAX_DIGITS_SMS);
    	  vm_log_debug("msg->addr_number.numbe=%s", msg->addr_number);
    	  if(strcmp((char*)number, "12520")==0)
    	  {
       	 return TRUE;
    	  }
		  
    }
      	
    return FALSE;
}*/

static VMINT vm_sms_sys_event_registered = FALSE;
#define vm_sms_event_registered_by_process(PHANDLE) (vm_res_get_data_list_count_by_proecss((PHANDLE), VM_RES_TYPE_SMS_INTERRUPT) > 0)
VMINT vm_sms_sys_set_interrupt_event_handler(void)
{
    if (!vm_sms_sys_event_registered)
    {
        mmi_frm_sms_reg_msg_check(vm_sms_interrupt_action, vm_sms_interrupt_callback);
        vm_sms_sys_event_registered = TRUE;
    }        
	return VM_SMS_REQ_NO_ERROR;
}

VMINT vm_sms_sys_clear_interrupt_event_handler(void)
{
	return VM_SMS_REQ_NO_ERROR;
}

VMINT vm_sms_clear_interrupt_event_handler(vm_sms_event_enum event_id,  VmSmsEventFunc event_func,  void* user_data)
{
    return VM_SMS_REQ_ERROR;
}

VMINT vm_sms_clear_interrupt_event_handler_forpay(vm_sms_event_enum event_id,  VmSmsEventFunc event_func,  void* user_data)
{
    VMINT id = -1;
    VM_P_HANDLE phandle = vm_pmng_get_current_handle(); 
    vm_res_node_t res_node;
    VMINT res_id;
    
	vm_log_debug("[SMS]-vm_sms_clear_interrupt_event_handler:start");   
    if(event_id != VM_EVT_ID_SMS_NEW_MSG)
        return VM_SMS_REQ_ERROR;
    if (!vm_sms_event_registered_by_process(phandle))
        return VM_SMS_REQ_NO_ERROR;

    if (vm_res_get_data_list_by_proecss(phandle, VM_RES_TYPE_SMS_INTERRUPT, &res_node, 1) < 0)
    {
       vm_log_debug("[SMS]-vm_sms_clear_interrupt_event_handler:vm_res_get_data_list_by_proecss error");
       return VM_SMS_MIBR_ERROR;        
    }

    res_id = res_node.res_id;
    vm_log_debug("[SMS]-vm_sms_clear_interrupt_event_handler:vm_res_release_data = %d",res_id); 
    if (vm_res_release_data(VM_RES_TYPE_SMS_INTERRUPT, res_id) < 0)
    {
       vm_log_debug("[SMS]-vm_sms_clear_interrupt_event_handler:vm_res_release_data error");
       return VM_SMS_MIBR_ERROR;
    }    
	vm_log_debug("[SMS]-vm_sms_clear_interrupt_event_handler:end");	
    return VM_SMS_REQ_NO_ERROR;

}

static VMINT vm_sms_identify_interrupt_event_data(char * user_data)
{
    char identify_str[16] = "VRE PAYMENT";
    if (strncmp(identify_str,user_data,16))
        return FALSE;
    return TRUE;
}
VMINT vm_sms_set_interrupt_event_handler(vm_sms_event_enum event_id,  VmSmsEventFunc event_func,  void* user_data)
{
    return VM_SMS_REQ_ERROR;
}

VMINT vm_sms_set_interrupt_event_handler_forpay(vm_sms_event_enum event_id,  VmSmsEventFunc event_func,  void* user_data)
{
    VMINT id = -1;
    VM_P_HANDLE phandle = vm_pmng_get_current_handle(); 
    VMINT res_id;

    vm_log_debug("[SMS]-vm_sms_set_interrupt_event_handler:start");

    if (phandle == 0)
        return VM_SMS_MIBR_NOT_IN_PROCESS_SPACE;
    
    if(event_id != VM_EVT_ID_SMS_NEW_MSG)
        return VM_SMS_REQ_ERROR;		
    if(!event_func)
        return VM_SMS_REQ_ERROR;

    if (!(vm_sms_identify_interrupt_event_data((char *)user_data)))
        return VM_SMS_IDENTIFY_ERROR;

    if (vm_sms_event_registered_by_process(phandle))
        return VM_SMS_REQ_CALLBACK_REGISTERED;
    
    if ((res_id = vm_res_save_data(VM_RES_TYPE_SMS_INTERRUPT, (void*)event_func, 4, NULL, phandle)) < 0)
    {
       vm_log_debug("[SMS]-vm_sms_set_interrupt_event_handler:vm_res_save_data error");
       return VM_SMS_MIBR_ERROR;
    }
    vm_log_debug("[SMS]-vm_sms_set_interrupt_event_handler:vm_res_save_data = %d,%x,%x",res_id,event_func,&event_func);    
	vm_log_debug("[SMS]-vm_sms_set_interrupt_event_handler:end");	
	return VM_SMS_REQ_NO_ERROR;
}


/***********************/


 VMINT vm_sms_get_msg_index(VMUINT16 *type, VMUINT16 *index, VMUINT16 msg_id)
{

 	mmi_frm_sms_get_list_index(type, index, msg_id);
	return VM_SMS_REQ_NO_ERROR;

}


static VMINT vm_sms_convert_status(VMINT status)
{
	VMINT msg_status = 0;
	
	
	switch(status)
	{
		case VM_SMS_STATUS_UNREAD:
			msg_status = SMSAL_REC_UNREAD;
			break;
			
		case VM_SMS_STATUS_READ:
			msg_status = SMSAL_REC_READ;
			break;
			
		case VM_SMS_STATUS_SENT:
		
			msg_status =SMSAL_STO_SENT;
			break;
			
		
		case VM_SMS_STATUS_UNSENT:
			msg_status =SMSAL_STO_UNSENT ;
			break;
			
	
		case VM_SMS_STATUS_DRAFT:
			msg_status = SMSAL_STO_DRAFT;
			break;

		default:
			msg_status = VM_SMS_REQ_ERROR;
			vm_log_error("vm_sms_add_msg : msg_status=%d",msg_status);
			break;
	}
	
 	return msg_status;

}

#else

VMINT vm_send_sms_request(S8* number, U16* content)
{
//	char * content_asc_buffer = NULL;
//	VMCHAR plmn[8]={0};


        smssend_handle = srv_sms_get_send_handle();
	if (smssend_handle == NULL)
	{
		/* can not get handle */
		return -1;
	}

	if ((U16)srv_sms_is_bg_send_action_busy() == TRUE)
	{
		/* background sending is busy */
		return -1;
	}
/*	if (vm_query_operator_code(plmn, sizeof(plmn))!= 0)
	{
		return -1;
	}*/
	/* set sending state */
	//smssend_state = TRUE;

	/* set address number */
	srv_sms_set_address(smssend_handle, (S8*)number);
	/* set content of DCS encoding */
	
	
	//srv_sms_set_content_dcs(smssend_handle, SRV_SMS_DCS_7BIT); 
	

	//strncpy(mcc, plmn, 3);
	/*if((strstr(plmn, "51010") != NULL ) || (strstr(plmn, "51011") != NULL ) || (strstr(plmn, "51089") != NULL ) || (strstr(plmn, "51008") != NULL ))
	{
		
		srv_sms_set_content_dcs(smssend_handle, SRV_SMS_DCS_8BIT); 
		content_asc_buffer = vm_calloc(mmi_wcslen(content)+1);
		if(content_asc_buffer == NULL)
		{
			return -1;
		}
		vm_ucs2_to_ascii(content_asc_buffer, mmi_wcslen(content)+1, (VMWSTR)content);
		srv_sms_set_content(smssend_handle, (S8*)content_asc_buffer, (U16)(mmi_wcslen(content)+1));
		
		vm_log_warn("sms: mmi_wcslen(content)+1=%d,content_asc_buffer=%s", mmi_wcslen(content)+1,content_asc_buffer);
	}
	else*/
	{
	//	srv_sms_set_content_dcs(smssend_handle, SRV_SMS_DCS_UCS2);
		srv_sms_set_content_dcs(smssend_handle, SRV_SMS_DCS_7BIT);
		/* set content */
		srv_sms_set_content(smssend_handle, (S8*)content, (U16)((mmi_wcslen(content)+1)*2));

	}
	

    //#ifdef VRE_DUAL_SIM    	
	if (sysconf.dual_sim_master == MMI_TRUE)
	{
		if (vm_selected_simcard == 1)
		{
			vm_log_debug("vm_send_sms_request : set sendrequire 1");
			srv_sms_set_sim_id(smssend_handle, SRV_SMS_SIM_1);
		}
		else if  (vm_selected_simcard == 2)
		{
			vm_log_debug("vm_send_sms_request : set sendrequire 2");
			srv_sms_set_sim_id(smssend_handle, SRV_SMS_SIM_2);
		}
		else
		{
			vm_log_debug("vm_send_sms_request : set sendrequire 1");
			srv_sms_set_sim_id(smssend_handle, SRV_SMS_SIM_1);
		}
	}
//#endif /*VRE_DUAL_SIM */

	/* send request */
	srv_sms_send_msg(smssend_handle, (SrvSmsCallbackFunc)vm_sms_callback, NULL);

	/*if(content_asc_buffer != NULL)
	vm_free(content_asc_buffer);*/

	
	return 0;
}



/* changed by zaiping.chen, 2010.07.15, static memory optimize, begin */
#if 0
VMINT vm_sal_sms_read_msg(VMUINT16 msg_id, VMINT change_status,  vm_sms_msg_data_t* msg_data, 
	            VmSmsCallbackFunc  callback_func, void* user_data, VMINT * cause)
{
      VMINT res = 0;
   //   srv_sms_msg_data_struct* data = NULL;
  //    VMINT16 * content_buffer = NULL;
  	  
     vm_log_debug("vm_sal_sms_read_msg:start");  
      if(!msg_data)
      {
          vm_log_error("vm_sal_sms_read_msg:msg_data == NULL");
	   *cause = SRV_SMS_CAUSE_DATA_INVALID;
	   return VM_SMS_REQ_ERROR;
      }
	if(srv_sms_is_sms_ready()==0)  
	{
	   vm_log_error("vm_sal_sms_read_msg:srv_sms_is_sms_ready()==0");
	   *cause = SRV_SMS_CAUSE_NOT_READY;
	   return VM_SMS_REQ_ERROR;
	}
	
       res = srv_sms_is_msg_exist(msg_id);
       if(res == 0)
       {
          vm_log_error("vm_sal_sms_read_msg: msg is not exist");
	   *cause = SRV_SMS_CAUSE_DATA_INVALID; 
	   return VM_SMS_REQ_ERROR;
       }
    /*   data =(srv_sms_msg_data_struct*) _vm_kernel_calloc(sizeof(srv_sms_msg_data_struct));
	if(data == NULL)
      	{
      	    vm_log_error("vm_sal_sms_read_msg: data == NULL");
	    return VM_SMS_REQ_ERROR;
      	} 
	 content_buffer =(VMINT16 *) _vm_kernel_calloc(sizeof(VMINT16)*(VM_SMS_MSG_CONTENT_LEN+1));
       if(content_buffer == NULL)
      	{
      	    vm_free(data);
           vm_log_error("vm_sms_read_msg: content_buffer == NULL");
	    return VM_SMS_REQ_ERROR;
      	}*/
       memset(&vm_read_data, 0, sizeof(srv_sms_msg_data_struct));
	memset(& content_buffer, 0, sizeof(content_buffer));
	//vm_log_debug("sizeof(vm_read_data)=%d", sizeof(srv_sms_msg_data_struct));/*132*/
	vm_log_debug("sizeof(content_buffer)=%d", sizeof(content_buffer));/*1002*/
	
      /*data->folder_id = SRV_SMS_FOLDER_DEFAULT;
      data->para_flag |= SRV_SMS_PARA_NUM;
      data->para_flag |= SRV_SMS_PARA_SCA;
      data->para_flag |= SRV_SMS_PARA_PID; 
      data->para_flag |= SRV_SMS_PARA_DCS;
      data->para_flag |= SRV_SMS_PARA_VP; 
      data->para_flag |= SRV_SMS_PARA_STATUS_REPORT;
      data->para_flag |= SRV_SMS_PARA_REPLY_PATH;
      data->para_flag |= SRV_SMS_PARA_PORT; 
      data->para_flag |= SRV_SMS_PARA_CLASS;
      data->para_flag |= SRV_SMS_PARA_STATUS; 
      data->para_flag |= SRV_SMS_PARA_SIM_ID;
      data->para_flag |= SRV_SMS_PARA_STORAGE_TYPE;
      data->para_flag |= SRV_SMS_PARA_TIMESTAMP; 
      data->para_flag |= SRV_SMS_PARA_CONTENT_BUFF;
	
      data->content_buff = (VMINT8*)content_buffer;
      data->content_buff_size = (VM_SMS_MSG_CONTENT_LEN+1)*sizeof(VMINT16);
	*/
      vm_read_data.folder_id = SRV_SMS_FOLDER_DEFAULT;
      vm_read_data.para_flag |= SRV_SMS_PARA_NUM;
      vm_read_data.para_flag |= SRV_SMS_PARA_SCA;
      vm_read_data.para_flag |= SRV_SMS_PARA_PID; 
      vm_read_data.para_flag |= SRV_SMS_PARA_DCS;
      vm_read_data.para_flag |= SRV_SMS_PARA_VP; 
      vm_read_data.para_flag |= SRV_SMS_PARA_STATUS_REPORT;
      vm_read_data.para_flag |= SRV_SMS_PARA_REPLY_PATH;
      vm_read_data.para_flag |= SRV_SMS_PARA_PORT; 
      vm_read_data.para_flag |= SRV_SMS_PARA_CLASS;
      vm_read_data.para_flag |= SRV_SMS_PARA_STATUS; 
      vm_read_data.para_flag |= SRV_SMS_PARA_SIM_ID;
      vm_read_data.para_flag |= SRV_SMS_PARA_STORAGE_TYPE;
      vm_read_data.para_flag |= SRV_SMS_PARA_TIMESTAMP; 
      vm_read_data.para_flag |= SRV_SMS_PARA_CONTENT_BUFF;
	
      vm_read_data.content_buff = (VMINT8*)content_buffer;
      vm_read_data.content_buff_size = sizeof(content_buffer);
	  
      srv_sms_read_msg(msg_id, change_status, &vm_read_data, (SrvSmsCallbackFunc)vm_sms_callback, user_data);

	vm_log_debug("vm_sms_read_msg:end");   
      return VM_SMS_REQ_NO_ERROR;
 
}
#endif
VMINT vm_sal_sms_read_msg(VMUINT16 msg_id, VMINT change_status,  vm_sms_msg_data_t* msg_data, 
	            VmSmsCallbackFunc  callback_func, void* user_data, VMINT * cause)
{
	VMINT res = 0;
  	  
	vm_log_debug("vm_sal_sms_read_msg: start");  
	if(!msg_data)
	{
		vm_log_error("vm_sal_sms_read_msg: msg_data == NULL");
		*cause = SRV_SMS_CAUSE_DATA_INVALID;
		return VM_SMS_REQ_ERROR;
	}
	if(srv_sms_is_sms_ready()==0)  
	{
		vm_log_error("vm_sal_sms_read_msg: srv_sms_is_sms_ready()==0");
		*cause = SRV_SMS_CAUSE_NOT_READY;
		return VM_SMS_REQ_ERROR;
	}
	
	res = srv_sms_is_msg_exist(msg_id);
	if(res == 0)
	{
		vm_log_error("vm_sal_sms_read_msg: msg is not exist");
		*cause = SRV_SMS_CAUSE_DATA_INVALID; 
		return VM_SMS_REQ_ERROR;
	}

	vm_log_debug("static memory optimize: vm_sal_sms_read_msg");
	if ((NULL == sms_data) || (NULL == sms_content))
	{
		vm_log_error("static memory optimize: error sms_data - %p, sms_content - %p", sms_data, sms_content);
		return VM_SMS_REQ_ERROR;
	}
	memset(sms_data, 0, sizeof(srv_sms_msg_data_struct));
	memset(sms_content, 0, (VM_SMS_MSG_CONTENT_LEN + 1) * sizeof(VMINT16));
	vm_log_debug("sizeof(sms_content) = %d", (VM_SMS_MSG_CONTENT_LEN + 1) * sizeof(VMINT16));/*1002*/
	
	sms_data->folder_id = SRV_SMS_FOLDER_DEFAULT;
	sms_data->para_flag |= SRV_SMS_PARA_NUM;
	sms_data->para_flag |= SRV_SMS_PARA_SCA;
	sms_data->para_flag |= SRV_SMS_PARA_PID; 
	sms_data->para_flag |= SRV_SMS_PARA_DCS;
	sms_data->para_flag |= SRV_SMS_PARA_VP; 
	sms_data->para_flag |= SRV_SMS_PARA_STATUS_REPORT;
	sms_data->para_flag |= SRV_SMS_PARA_REPLY_PATH;
	sms_data->para_flag |= SRV_SMS_PARA_PORT; 
	sms_data->para_flag |= SRV_SMS_PARA_CLASS;
	sms_data->para_flag |= SRV_SMS_PARA_STATUS; 
	sms_data->para_flag |= SRV_SMS_PARA_SIM_ID;
	sms_data->para_flag |= SRV_SMS_PARA_STORAGE_TYPE;
	sms_data->para_flag |= SRV_SMS_PARA_TIMESTAMP; 
	sms_data->para_flag |= SRV_SMS_PARA_CONTENT_BUFF;
	
	sms_data->content_buff = (VMINT8*)sms_content;
	sms_data->content_buff_size = (VM_SMS_MSG_CONTENT_LEN + 1) * sizeof(VMINT16);
	
	srv_sms_read_msg(msg_id, change_status, sms_data, (SrvSmsCallbackFunc)vm_sms_callback, user_data);

	vm_log_debug("vm_sms_read_msg: end");
	return VM_SMS_REQ_NO_ERROR;
 
}
/* changed by zaiping.chen, 2010.07.15, static memory optimize, end */


VMINT vm_sal_sms_add_msg(vm_sms_add_msg_data_t * msg_data, VmSmsCallbackFunc callback_func, void* user_data, VMINT * cause)
{
	SMS_HANDLE  handle = NULL;
	MYTIME timestamp;
	 
	vm_log_debug("vm_sal_sms_add_msg:start");  
     if(!msg_data)
     {
          vm_log_error("vm_sal_sms_add_msg:msg_data ==NULL");
	   *cause = SRV_SMS_CAUSE_DATA_INVALID;
	   return VM_SMS_REQ_ERROR;
      }
	 
      if(srv_sms_is_sms_ready()==0)  
      {
	   vm_log_error("vm_sal_sms_add_msg:srv_sms_is_sms_ready()==0");
	   *cause = SRV_SMS_CAUSE_NOT_READY;
	   return VM_SMS_REQ_ERROR;
      }
	  
      handle =  srv_sms_get_save_handle();
	vm_log_debug("vm_sal_sms_add_msg:handle=%d",handle);  
      if(handle == NULL)
      {
          vm_log_error("vm_sal_sms_add_msg:handle < 0");
	   *cause = SRV_SMS_CAUSE_DATA_INVALID;
	   return VM_SMS_REQ_ERROR;
      }
	  
  	vm_log_debug("vm_sal_sms_add_msg:timestamp");  
	timestamp.nYear = msg_data->timestamp.year;
	timestamp.nMonth= msg_data->timestamp.mon;
	timestamp.nDay= msg_data->timestamp.day;
	timestamp.nHour = msg_data->timestamp.hour;
	timestamp.nMin = msg_data->timestamp.min;
	timestamp.nSec = msg_data->timestamp.sec;
	
	vm_log_debug("vm_sal_sms_add_msg:msg_data->number=%s", vm_gb2312_string((VMWSTR)msg_data->number));  
	srv_sms_set_address(handle, msg_data->number);
	
	vm_log_debug("vm_sal_sms_add_msg:srv_sms_set_content_dcs");  
	srv_sms_set_content_dcs( handle, SRV_SMS_DCS_UCS2);  
	
	vm_log_debug("vm_sal_sms_add_msg:srv_sms_set_content"); 
       srv_sms_set_content( handle, msg_data->content , msg_data->content_size);  
	   
	vm_log_debug("vm_sal_sms_add_msg:msg_data->status=%x",msg_data->status); 
	srv_sms_set_status(handle, msg_data->status); 

	vm_log_debug("vm_sal_sms_add_msg:msg_data->storage_type=%d",msg_data->storage_type); 
	srv_sms_set_storage_type(handle, msg_data->storage_type); 
	
	vm_log_debug("vm_sal_sms_add_msg: msg_data->sim_id=%d", msg_data->sim_id); 
	srv_sms_set_sim_id(handle, msg_data->sim_id);

	vm_log_debug("vm_sal_sms_add_msg: srv_sms_set_save_timestamp"); 
	srv_sms_set_save_timestamp(handle, &timestamp);

	vm_log_debug("vm_sal_sms_add_msg: srv_sms_save_msg"); 
	srv_sms_save_msg(handle, (SrvSmsCallbackFunc)vm_sms_callback, user_data);
	       
       vm_log_debug("vm_sal_sms_add_msg:end");  
       return VM_SMS_REQ_NO_ERROR;
}


VMINT vm_sal_sms_delete_msg(VMUINT16 msg_id, VmSmsCallbackFunc callback_func,  void* user_data, VMINT * cause)
{
    VMINT res = 0;
	
    vm_log_debug("vm_sms_delete_msg:start");  

    if(srv_sms_is_sms_ready()==0 )  
     {
	   vm_log_error("vm_sms_delete_msg:srv_sms_is_sms_ready()==0");
	   *cause = SRV_SMS_CAUSE_NOT_READY;
	   return VM_SMS_REQ_ERROR;
    }
    res = srv_sms_is_msg_exist(msg_id);
    if(res == 0)
    {
          vm_log_error("vm_sms_delete_msg:msg is not exist");
	   *cause = SRV_SMS_CAUSE_DATA_INVALID;
	   return VM_SMS_REQ_ERROR;
     }
    srv_sms_delete_msg(msg_id, (SrvSmsCallbackFunc)vm_sms_callback, user_data);

    vm_log_debug("vm_sms_delete_msg:end");  
     return VM_SMS_REQ_NO_ERROR;
}


VMINT vm_sal_sms_delete_msg_list(vm_sms_box_enum box_type,  vm_sms_sim_enum sim_id, VmSmsCallbackFunc callback_func,  void* user_data, VMINT * cause)
{
      vm_log_debug("vm_sms_delete_msg_list:start");  
           
      if(srv_sms_is_sms_ready()==0)  
      {
	   vm_log_error("vm_sms_delete_msg_list:srv_sms_is_sms_ready()==0");
	   *cause = SRV_SMS_CAUSE_NOT_READY;
	   return VM_SMS_REQ_ERROR;
      }
       srv_sms_delete_msg_list(box_type, sim_id, (SrvSmsCallbackFunc)vm_sms_callback, user_data);

      vm_log_debug("vm_sms_delete_msg_list:end");  
      return VM_SMS_REQ_NO_ERROR;

}


VMINT vm_sal_sms_get_msg_id_list(vm_sms_query_t* query_data,  VmSmsCallbackFunc callback_func,  void* user_data, VMINT * cause)
{
     srv_sms_query_struct * sms_query = NULL;
	 
     vm_log_debug("vm_sal_sms_get_msg_id_list:start");  
     if(!query_data)
     {
          vm_log_error("vm_sal_sms_get_msg_id_list:query_data == NULL");
	  *cause = SRV_SMS_CAUSE_DATA_INVALID;
	   return VM_SMS_REQ_ERROR;
     }
      if(srv_sms_is_sms_ready()==0 )  
      {
	   vm_log_error("vm_sal_sms_get_msg_id_list:srv_sms_is_sms_ready()==0");
	   *cause = SRV_SMS_CAUSE_NOT_READY;
	   return VM_SMS_REQ_ERROR;
      }
     sms_query = (srv_sms_query_struct *) _vm_kernel_calloc(sizeof(srv_sms_query_struct));
     if(sms_query == NULL)
     { 
          vm_log_error("vm_sal_sms_get_msg_id_list:sms_query ==NULL");
	   *cause = SRV_SMS_CAUSE_MEM_INSUFFICIENT;
	   return VM_SMS_REQ_ERROR;
      } 
     
      sms_query->folder_id = SRV_SMS_FOLDER_DEFAULT;
      sms_query->query_flag = SRV_SMS_QUERY_STATUS;  
      sms_query->sort_flag = query_data->sort_flag;  
      sms_query->order_flag = query_data->order_flag;  
      sms_query->status = query_data->status;  
          
      srv_sms_query_msg(sms_query, (SrvSmsCallbackFunc)vm_sms_callback, user_data);

      _vm_kernel_free(sms_query);
       vm_log_debug("vm_sal_sms_get_msg_id_list:end");  
      return VM_SMS_REQ_NO_ERROR;
}


VMINT16 vm_sal_sms_get_msg_id(vm_sms_box_enum box_type, VMUINT16 msg_index)
{
    VMINT msg_id = -1;
	
    vm_log_debug("vm_sal_sms_get_msg_id:start");  
        
     if(srv_sms_is_sms_ready()==0)  
     {
	   vm_log_error("vm_sal_sms_get_msg_id:srv_sms_is_sms_ready()==0");
	   return VM_SMS_REQ_ERROR;
     }
    msg_id = (VMINT)srv_sms_get_msg_id(box_type, msg_index);
	
    if(msg_id == SRV_SMS_INVALID_MSG_ID)
		msg_id = -1;
	
    vm_log_debug("vm_sal_sms_get_msg_id:end");  
    return msg_id;

}


VMINT16 vm_sal_sms_get_box_size(vm_sms_box_enum box_type)
{
     VMINT size = 0;

    vm_log_debug("vm_sal_sms_get_box_size:start");  
     
     if(srv_sms_is_sms_ready()==0 )  
     {
	   vm_log_error("vm_sal_sms_get_box_size:srv_sms_is_sms_ready()==0");
	   return VM_SMS_REQ_ERROR;
     }
    size = (VMINT)srv_sms_get_list_size(box_type);
    
    vm_log_debug("vm_sal_sms_get_box_size:end");  
    return size;

}


VMINT vm_sal_sms_get_sc_address(vm_sms_sim_enum sim_id, VmSmsCallbackFunc callback, void* user_data)
{	
	srv_sms_setting_struct * sms_setting = NULL;
	srv_sms_callback_struct  callback_data;
	vm_sms_get_sc_addr_cb_t  sc_addr_cb;
	  
	vm_log_debug("vm_sal_sms_get_sc_address_asyn:start");  
   
	if(srv_sms_is_sms_ready()==0 )  
	{
		vm_log_error("vm_sal_sms_get_sc_address_asyn:srv_sms_is_sms_ready()==0");
		return VM_SMS_REQ_ERROR;
	}
	
	memset(&sc_addr_cb, 0, sizeof(vm_sms_get_sc_addr_cb_t));	
	sms_setting = (srv_sms_setting_struct*)srv_sms_get_default_setting( sim_id);
		
	strncpy(sc_addr_cb.sc_addr, sms_setting->sc_addr, VM_SMS_MAX_ADDR_LEN); 

	vm_log_debug("vm_sal_sms_get_sc_address:sc_addr=%s",sc_addr_cb.sc_addr);
	callback_data.user_data = user_data;
	callback_data.action_data = &sc_addr_cb;
	callback_data.action = VM_SMS_ACTION_GET_SC_ADDR;
	if(strlen(sc_addr_cb.sc_addr) != 0)
	{		
		callback_data.result = 1;
		callback_data.cause = 0;
		
	}
	else
	{
		callback_data.result = 0;
		callback_data.cause = SRV_SMS_CAUSE_SC_EMPTY;
		vm_log_error("vm_sms_get_sc_address:strlen(sc_addr_cb.sc_addr) =%d",strlen(sc_addr_cb.sc_addr) );
	}
	
 	vm_sms_callback(&callback_data);
	vm_log_debug("vm_sal_sms_get_sc_address_asyn:end");  
	return VM_SMS_REQ_NO_ERROR;
}

VMINT vm_sal_sms_get_sc_address_syn(VMCHAR * sc_addr,  vm_sms_sim_enum sim_id)
{
      srv_sms_setting_struct * sms_setting = NULL;
	  
      vm_log_debug("vm_sal_sms_get_sc_address_syn:start");  

     sms_setting = (srv_sms_setting_struct*)srv_sms_get_default_setting( sim_id);
	 
     strncpy(sc_addr, sms_setting->sc_addr, VM_SMS_MAX_ADDR_LEN); 

     vm_log_debug("vm_sal_sms_get_sc_address_syn:sc_addr=%s",sc_addr);  
	 
     return VM_SMS_REQ_NO_ERROR;

}




#define vm_sms_event_registered_by_process(PHANDLE) (vm_res_get_data_list_count_by_proecss((PHANDLE), VM_RES_TYPE_SMS_INTERRUPT) > 0)

VMINT vm_sms_sys_set_interrupt_event_handler(vm_sms_event_enum event_id)
{
    VMINT id = -1;

    vm_log_debug("[SMS]-vm_sms_sys_set_interrupt_event_handler:start");
    if(event_id != VM_EVT_ID_SMS_NEW_MSG)
        return VM_SMS_REQ_ERROR;
    
    id = EVT_ID_SRV_SMS_NEW_MSG;
    srv_sms_set_interrupt_event_handler(id, (SrvSmsEventFunc)vm_sms_interrupt_event_callback, NULL);
	vm_log_debug("[SMS]-vm_sms_set_interrupt_event_handler:end");	
	return VM_SMS_REQ_NO_ERROR;
}
VMINT vm_sms_set_interrupt_event_handler(vm_sms_event_enum event_id,  VmSmsEventFunc event_func,  void* user_data)
{
    return VM_SMS_REQ_ERROR;
}


static VMINT vm_sms_identify_interrupt_event_data(char * user_data)
{
    char identify_str[16] = "VRE PAYMENT";
    if (strncmp(identify_str,user_data,16))
        return FALSE;
    return TRUE;
}

VMINT vm_sms_set_interrupt_event_handler_forpay(vm_sms_event_enum event_id,  VmSmsEventFunc event_func,  void* user_data)
{   
    VMINT id = -1;
    VM_P_HANDLE phandle = vm_pmng_get_current_handle(); 
    VMINT res_id;

    vm_log_debug("[SMS]-vm_sms_set_interrupt_event_handler:start");

    if (phandle == 0)
        return VM_SMS_MIBR_NOT_IN_PROCESS_SPACE;
		
    if(event_id != VM_EVT_ID_SMS_NEW_MSG || !event_func)
        return VM_SMS_REQ_ERROR;

    if (!(vm_sms_identify_interrupt_event_data((char *)user_data)))
        return VM_SMS_IDENTIFY_ERROR;
    
    if (vm_sms_event_registered_by_process(phandle))
        return VM_SMS_REQ_CALLBACK_REGISTERED;

    
    id = EVT_ID_SRV_SMS_NEW_MSG;

    
    if ((res_id = vm_res_save_data(VM_RES_TYPE_SMS_INTERRUPT, (void*)event_func, 4, NULL, phandle)) < 0)
    {
       vm_log_debug("[SMS]-vm_sms_set_interrupt_event_handler:vm_res_save_data error%d",res_id);
       return VM_SMS_MIBR_ERROR;
    }
    vm_log_debug("[SMS]-vm_sms_set_interrupt_event_handler:vm_res_save_data = %d,%x,%x",res_id,event_func,&event_func);    
	vm_log_debug("[SMS]-vm_sms_set_interrupt_event_handler:end");	
	return VM_SMS_REQ_NO_ERROR;
}



VMINT vm_sms_sys_clear_interrupt_event_handler(vm_sms_event_enum event_id)
{
    VMINT id = -1;

	vm_log_debug("[SMS]-vm_sms_sys_clear_interrupt_event_handler:start");   
    if(event_id != VM_EVT_ID_SMS_NEW_MSG)
        return VM_SMS_REQ_ERROR;
    
    id = EVT_ID_SRV_SMS_NEW_MSG;
    srv_sms_clear_interrupt_event_handler(id, (SrvSmsEventFunc)vm_sms_interrupt_event_callback,  NULL);
	vm_log_debug("[SMS]-vm_sms_sys_clear_interrupt_event_handler:end");	
    return VM_SMS_REQ_NO_ERROR;

}


VMINT vm_sms_clear_interrupt_event_handler(vm_sms_event_enum event_id,  VmSmsEventFunc event_func,  void* user_data)
{
    return VM_SMS_REQ_ERROR;
}

VMINT vm_sms_clear_interrupt_event_handler_forpay(vm_sms_event_enum event_id,  VmSmsEventFunc event_func,  void* user_data)
{
    VMINT id = -1;
    VM_P_HANDLE phandle = vm_pmng_get_current_handle(); 
    vm_res_node_t res_node;
    VMINT res_id;
    
	vm_log_debug("[SMS]-vm_sms_clear_interrupt_event_handler:start");   
    if(event_id != VM_EVT_ID_SMS_NEW_MSG)
        return VM_SMS_REQ_ERROR;
    
    id = EVT_ID_SRV_SMS_NEW_MSG;

    if (!vm_sms_event_registered_by_process(phandle))
        return VM_SMS_REQ_NO_ERROR;

    if (vm_res_get_data_list_by_proecss(phandle, VM_RES_TYPE_SMS_INTERRUPT, &res_node, 1) < 0)
    {
       vm_log_debug("[SMS]-vm_sms_clear_interrupt_event_handler:vm_res_get_data_list_by_proecss error");
       return VM_SMS_MIBR_ERROR;        
    }

    res_id = res_node.res_id;
    vm_log_debug("[SMS]-vm_sms_clear_interrupt_event_handler:vm_res_release_data = %d",res_id); 
    if (vm_res_release_data(VM_RES_TYPE_SMS_INTERRUPT, res_id) < 0)
    {
       vm_log_debug("[SMS]-vm_sms_clear_interrupt_event_handler:vm_res_release_data error");
       return VM_SMS_MIBR_ERROR;
    }    
	vm_log_debug("[SMS]-vm_sms_clear_interrupt_event_handler:end");	
    return VM_SMS_REQ_NO_ERROR;

}


static void vm_msg_ascii_to_usc2(char* out_usc2, const char* in_ascii, VMUINT16 ascci_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 ascii_index = 0;
	U16 usc2_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	while(ascii_index < ascci_len)
	{
		if (in_ascii[ascii_index] != '\0')
		{
			out_usc2[usc2_index] = in_ascii[ascii_index];
			out_usc2[usc2_index + 1] = 0;

			usc2_index += 2; 
		}
		ascii_index++;
	}

	out_usc2[usc2_index] = 0;
	out_usc2[usc2_index + 1] = 0;
}

static VMINT vm_sms_interrupt_event_callback(srv_sms_event_struct* event_data)
{
    vm_sms_event_t  vm_sms_event_ptr;
	  
    vm_sms_event_new_sms_t  vm_event_new_msg;
    srv_sms_event_new_sms_struct  *srv_event_new_msg = NULL;
	  
    vm_sms_new_msg_t * vm_new_msg = NULL;
    srv_sms_new_msg_struct * srv_new_msg = NULL;
    SMS_HANDLE  handle = NULL;
    VMCHAR number[6]={0};
    VMINT res = FALSE;
    VMINT user_res = FALSE;
    VM_P_HANDLE *phandle_lst = NULL;
    VMUINT process_num = 0;
    VMINT i;
    VM_P_HANDLE cur_p_handle;
    vm_res_node_t res_node;

    VMCHAR * vm_event_new_msg_content;

    VMUINT16 contentLen = 0;
    VMCHAR *unicodecontent = NULL;
    VMCHAR* content;    

	 
    if(!event_data)
    {
        vm_log_error("[SMS]-vm_sms_interrupt_event_callback:event_data == NULL");
        return FALSE;
    }
	  
    if(event_data->evt_id != EVT_ID_SRV_SMS_NEW_MSG || (!event_data->event_info))
    {
        vm_log_debug("[SMS]-vm_sms_interrupt_event_callback:not EVT_ID_SRV_SMS_NEW_MSG or event_info is NULL");
        return FALSE;
    }        

    vm_new_msg = _vm_kernel_calloc(sizeof(vm_sms_new_msg_t));
    if(!vm_new_msg)
    {
        vm_log_error("[SMS]-vm_sms_interrupt_event_callback:new_msg == NULL");
        return FALSE;
    }

    memset(&vm_sms_event_ptr,0,sizeof(vm_sms_event_t));
    memset(&vm_event_new_msg,0,sizeof(vm_sms_event_new_sms_t));    
    
    srv_event_new_msg = (srv_sms_event_new_sms_struct*)event_data->event_info;
    srv_new_msg = (srv_sms_new_msg_struct *)srv_event_new_msg->msg_data;  

    
    vm_sms_event_ptr.event_id = VM_EVT_ID_SMS_NEW_MSG;
    vm_sms_event_ptr.size = event_data->size;
    vm_sms_event_ptr.user_data= NULL;
    vm_sms_event_ptr.event_info = (vm_sms_event_new_sms_t*)&vm_event_new_msg;  
    vm_log_debug("[SMS]-vm_sms_event_ptr size=%d,%d",vm_sms_event_ptr.size,event_data->size);

    
    
    vm_event_new_msg.msg_data = (vm_sms_new_msg_t *)vm_new_msg;
    vm_event_new_msg.msg_id = srv_event_new_msg->msg_id;
    
                vm_event_new_msg_content = _vm_kernel_calloc(srv_new_msg->message_len+2);
            if(!vm_event_new_msg_content)
            {
                if(vm_new_msg)
                    _vm_kernel_free(vm_new_msg);
                vm_log_error("[SMS]-vm_sms_interrupt_event_callback:vm_event_new_msg_content == NULL");
                return FALSE;
            }   
            memcpy(vm_event_new_msg_content , srv_event_new_msg->content , srv_new_msg->message_len);
            memset(vm_event_new_msg_content + srv_new_msg->message_len, 0, 2);  
    /*content = (VMCHAR*)srv_new_msg->data;

        if (srv_new_msg->dcs == SRV_SMS_DCS_UCS2)
        {
            contentLen = srv_new_msg->message_len;

            vm_event_new_msg_content = _vm_kernel_calloc(contentLen + 2);
            if(!vm_event_new_msg_content)
            {
                if(vm_new_msg)
                    _vm_kernel_free(vm_new_msg);
                vm_log_error("[SMS]-vm_sms_interrupt_event_callback:vm_event_new_msg_content == NULL");
                return FALSE;
            }              
            memcpy(vm_event_new_msg_content, content, contentLen);
            memset(vm_event_new_msg_content + contentLen, 0, 2);
        }
        else
        {
            contentLen = srv_new_msg->message_len / 2;
            vm_event_new_msg_content = _vm_kernel_calloc((contentLen + 1) * 2);
            if(!vm_event_new_msg_content)
            {
                if(vm_new_msg)
                    _vm_kernel_free(vm_new_msg);
                vm_log_error("[SMS]-vm_sms_interrupt_event_callback:vm_event_new_msg_content == NULL");
                return FALSE;
            }              
            vm_msg_ascii_to_usc2(vm_event_new_msg_content, (char *)content, contentLen);
            memset(vm_event_new_msg_content + contentLen * 2, 0, 2);
        }
*/
    
    
    vm_event_new_msg.content = (VMUINT8 *)vm_event_new_msg_content;  

    vm_log_debug("[SMS]-vm_event_new_msg msg_id=%d,%d",vm_event_new_msg.msg_id,srv_event_new_msg->msg_id);
    vm_log_debug("[SMS]-vm_event_new_msg content=%s,%s",vm_event_new_msg.content,srv_event_new_msg->content);


    
			   
    vm_new_msg->msg_id = srv_new_msg->msg_id;
    vm_new_msg->dest_port = srv_new_msg->dest_port;
    vm_new_msg->src_port = srv_new_msg->src_port;
    vm_new_msg->message_len = srv_new_msg->message_len;
    vm_new_msg->ref = srv_new_msg->ref;
    strncpy((char*)vm_new_msg->number, (char*)srv_new_msg->number, VM_SMS_MAX_ADDR_LEN);
    strncpy((char*)vm_new_msg->sc_number, (char*)srv_new_msg->sc_number, VM_SMS_MAX_ADDR_LEN);
    vm_new_msg->timestamp.year = srv_new_msg->timestamp.nYear;
    vm_new_msg->timestamp.mon = srv_new_msg->timestamp.nMonth;
    vm_new_msg->timestamp.day = srv_new_msg->timestamp.nDay;
    vm_new_msg->timestamp.hour = srv_new_msg->timestamp.nHour;
    vm_new_msg->timestamp.min = srv_new_msg->timestamp.nMin;
    vm_new_msg->timestamp.sec = srv_new_msg->timestamp.nSec;
    vm_new_msg->total_seg = srv_new_msg->total_seg;
    vm_new_msg->seg = srv_new_msg->seg;
    vm_new_msg->dcs = srv_new_msg->dcs;
    vm_new_msg->mti = srv_new_msg->mti;
    vm_new_msg->pid = srv_new_msg->pid;
    vm_new_msg->fo = srv_new_msg->fo;
    strncpy((char*)vm_new_msg->data, (char*)srv_new_msg->data, 1);
    vm_new_msg->sim_id = srv_new_msg->sim_id;
    vm_new_msg->storage_type = srv_new_msg->storage_type;
    
    vm_log_debug("[SMS]-vm_new_msg msg_id=%d,%d",vm_new_msg->msg_id,srv_new_msg->msg_id);
    vm_log_debug("[SMS]-vm_new_msg dest_port=%d,%d",vm_new_msg->dest_port,srv_new_msg->dest_port);
    vm_log_debug("[SMS]-vm_new_msg src_port=%d,%d",vm_new_msg->src_port,srv_new_msg->src_port);
    
    vm_log_debug("[SMS]-vm_new_msg message_len=%d,%d",vm_new_msg->message_len,srv_new_msg->message_len);
    vm_log_debug("[SMS]-vm_new_msg ref=%d,%d",vm_new_msg->ref,srv_new_msg->ref);

	  
    vm_log_debug("===========================================");
    vm_log_debug("[SMS]-vm_sms_block addr = %x,%x,%x",&vm_sms_event_ptr,&vm_event_new_msg,&vm_new_msg);
    vm_log_debug("[SMS]-vm_sms_block name addr = %x",vm_new_msg->number);
    vm_log_debug("===========================================");

    
    vm_log_debug("[SMS]-vm_new_msg number=%s,%s",vm_new_msg->number,srv_new_msg->number);
    vm_log_debug("[SMS]-vm_new_msg sc_number=%s,%s",vm_new_msg->sc_number,srv_new_msg->sc_number);
    
    vm_log_debug("[SMS]-vm_new_msg year=%d,%d",vm_new_msg->timestamp.year,srv_new_msg->timestamp.nYear);
    vm_log_debug("[SMS]-vm_new_msg mon=%d,%d",vm_new_msg->timestamp.mon,srv_new_msg->timestamp.nMonth);
    vm_log_debug("[SMS]-vm_new_msg day=%d,%d",vm_new_msg->timestamp.day,srv_new_msg->timestamp.nDay);
    vm_log_debug("[SMS]-vm_new_msg hour=%d,%d",vm_new_msg->timestamp.hour,srv_new_msg->timestamp.nHour);
    vm_log_debug("[SMS]-vm_new_msg min=%d,%d",vm_new_msg->timestamp.min,srv_new_msg->timestamp.nMin);    
    vm_log_debug("[SMS]-vm_new_msg sec=%d,%d",vm_new_msg->timestamp.sec,srv_new_msg->timestamp.nSec);
    
    vm_log_debug("[SMS]-vm_new_msg total_seg=%d,%d",vm_new_msg->total_seg,srv_new_msg->total_seg);    
    vm_log_debug("[SMS]-vm_new_msg seg=%d,%d",vm_new_msg->seg,srv_new_msg->seg); 
    vm_log_debug("[SMS]-vm_new_msg dcs=%d,%d",vm_new_msg->dcs,srv_new_msg->dcs);     
    vm_log_debug("[SMS]-vm_new_msg mti=%d,%d",vm_new_msg->mti,srv_new_msg->mti); 
    vm_log_debug("[SMS]-vm_new_msg pid=%d,%d",vm_new_msg->pid,srv_new_msg->pid);
    vm_log_debug("[SMS]-vm_new_msg fo=%d,%d",vm_new_msg->fo,srv_new_msg->fo);   
    vm_log_debug("[SMS]-vm_new_msg data=%c,%c",vm_new_msg->data,srv_new_msg->data);     
    vm_log_debug("[SMS]-vm_new_msg sim_id=%d,%d",vm_new_msg->sim_id,srv_new_msg->sim_id);
    vm_log_debug("[SMS]-vm_new_msg storage_type=%d,%d",vm_new_msg->storage_type,srv_new_msg->storage_type);     


    vm_log_debug("[SMS]- vm_sms_interrupt_action - begin");
	{/* SMS interuption by daniel.lin */
		VMINT p_state;
		for (p_state=VM_PMNG_FOREGROUND; p_state<=VM_PMNG_BACKGROUND; p_state++)
		{
			VMINT res_size;
			VMINT res_handle = vm_res_findfirst(-1, VM_RES_TYPE_SMS_INTERRUPT);
            vm_log_debug("[SMS]- vm_sms_interrupt_action - p_state:%d, res_handle=%d", p_state, res_handle);
			while ( VM_RES_NOT_FIND != res_handle )
			{
				VmSmsEventFunc cb = NULL;
	            vm_log_debug("[SMS]- vm_sms_interrupt_action - 2 p_state:%d, res_handle=%d", p_state, res_handle);
				if (VM_RES_OK == vm_res_get_data(VM_RES_TYPE_SMS_INTERRUPT, res_handle, (void **)&cb, &res_size) )
				{
					VMINT p_handle = vm_res_get_process_handle(VM_RES_TYPE_SMS_INTERRUPT, res_handle);
	            	vm_log_debug("[SMS]- vm_sms_interrupt_action - 2 p_state:%d, res_handle=%d, p_handle:%d", p_state, res_handle, p_handle);
					if (vm_pmng_state(p_handle) == p_state)
					{
	            		vm_log_debug("[SMS]- vm_sms_interrupt_action - 3 p_state:%d, res_handle=%d, p_handle:%d", p_state, res_handle, p_handle);
				        if (cb && vm_pmng_set_ctx(p_handle) == VM_PMNG_OP_OK)
				        {
				            vm_log_debug("[SMS]- vm_sms_interrupt_action - p_state=%d, cb=%x", p_state, cb);
			                user_res = ((VmSmsEventFunc)cb)(&vm_sms_event_ptr);
				            vm_pmng_reset_ctx();
				        }  
						
				        if (user_res)
				        {
				            if(vm_new_msg)
				                _vm_kernel_free(vm_new_msg);
				            if(vm_event_new_msg_content)
				                _vm_kernel_free(vm_event_new_msg_content);            
				            vm_log_debug("[SMS]- interupted: cb=%x", cb);
							vm_res_findclose(VM_RES_TYPE_SMS_INTERRUPT);
				            return TRUE;                
				        }
					}
				}
				res_handle = vm_res_findnext(-1, VM_RES_TYPE_SMS_INTERRUPT);
			}
			vm_res_findclose(VM_RES_TYPE_SMS_INTERRUPT);
		}
	}
    vm_log_debug("[SMS]- vm_sms_interrupt_action - end");   
   
   
#if 0     
    if (vm_pmng_get_process_lst(VM_PMNG_FOREGROUND, &phandle_lst, &process_num) < 0)
    {
        if(vm_new_msg)
            _vm_kernel_free(vm_new_msg);
        if(vm_event_new_msg_content)
            _vm_kernel_free(vm_event_new_msg_content);
        vm_log_debug("[SMS]-vm_sms_interrupt_event_callback:vm_pmng_get_process_lst VM_PMNG_FOREGROUND error");
        return FALSE;
    }     
    for (i = 0; i < process_num; i++)
    {
        cur_p_handle = (VM_P_HANDLE)*(phandle_lst + i);
        vm_log_debug("[SMS]-vm_sms_interrupt_event_callback:cur_p_handle = %d",cur_p_handle);
        if (!vm_sms_event_registered_by_process(cur_p_handle))
            continue;
        if (vm_res_get_data_list_by_proecss(cur_p_handle, VM_RES_TYPE_SMS_INTERRUPT, &res_node, 1) < 0)
            continue;
        if (vm_pmng_set_ctx(cur_p_handle) == VM_PMNG_OP_OK)
        {
            vm_log_debug("[SMS]-vm_sms_interrupt_event_callback:res_node=%d,%x,%x,size=%d",res_node.res_id,res_node.data_content,res_node.data_content,res_node.data_size);
            if (res_node.data_content)
            {
                user_res = ((VmSmsEventFunc)(res_node.data_content))(&vm_sms_event_ptr);
            }
            vm_pmng_reset_ctx();
        }  
        
        if (user_res)
        {
            if(vm_new_msg)
                _vm_kernel_free(vm_new_msg);
            if(phandle_lst)
                _vm_kernel_free(phandle_lst);
            if(vm_event_new_msg_content)
                _vm_kernel_free(vm_event_new_msg_content);            
            return TRUE;                
        }           
    }
    
    if (phandle_lst)
        _vm_kernel_free(phandle_lst);
    phandle_lst = NULL;
    process_num = 0;
    
    if (vm_pmng_get_process_lst(VM_PMNG_BACKGROUND, &phandle_lst, &process_num) < 0)
    {
        if(vm_new_msg)
            _vm_kernel_free(vm_new_msg);
        if(vm_event_new_msg_content)
            _vm_kernel_free(vm_event_new_msg_content);        
        vm_log_debug("[SMS]-vm_sms_interrupt_event_callback:vm_pmng_get_process_lst VM_PMNG_BACKGROUND error");
        return FALSE;
    } 

    
    for (i = 0; i < process_num; i++)
    {
        cur_p_handle = (VM_P_HANDLE)*(phandle_lst + i);
        if (!vm_sms_event_registered_by_process(cur_p_handle))
            continue;
        if (vm_res_get_data_list_by_proecss(cur_p_handle, VM_RES_TYPE_SMS_INTERRUPT, &res_node, 1) < 0)
            continue;
        if (vm_pmng_set_ctx(cur_p_handle) == VM_PMNG_OP_OK)
        {
            vm_log_debug("[SMS]-vm_sms_interrupt_event_callback:res_node.data_content=%x",res_node.data_content);
            if (res_node.data_content)
            {
                user_res = ((VmSmsEventFunc)(res_node.data_content))(&vm_sms_event_ptr);
            }
            vm_pmng_reset_ctx();
        }  
        
        if (user_res)
        {
            if(vm_new_msg)
                _vm_kernel_free(vm_new_msg);
            if (phandle_lst)
                _vm_kernel_free(phandle_lst);
            if(vm_event_new_msg_content)
                _vm_kernel_free(vm_event_new_msg_content);            
            return TRUE;                
        }           
    }
        
#endif        
    if(vm_new_msg)
        _vm_kernel_free(vm_new_msg);
    if (phandle_lst)
        _vm_kernel_free(phandle_lst);
    if(vm_event_new_msg_content)
        _vm_kernel_free(vm_event_new_msg_content);    
    return FALSE;
    
}

#endif

#endif
