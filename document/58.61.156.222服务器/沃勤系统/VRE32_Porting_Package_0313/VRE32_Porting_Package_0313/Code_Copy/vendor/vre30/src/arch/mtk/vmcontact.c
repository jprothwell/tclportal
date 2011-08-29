#ifdef __VRE__

#if !defined(__VRE_RB_09A__)

//#include "PhoneBookGprot.h"
#include "MMI_include.h"
#include "PhbSrvGprot.h"

#include "vmmod.h"
#include "vmsys.h"
#include "vmio.h"
#include "vmlog.h"
#include "vmopt.h"
#include "vmstdlib.h"
#include "vmchset.h"
#include "vmsim.h"
#include "vmmem.h"
#include "vmcontact.h"

#include "vmresmng.h"
#include "vmpromng.h"

#include "vmsalcontact.h"
#include "vmmacrostub.h"
/*
  * 应用程序短消息回调函数。
  */


/* ------------------------------------------------------------------------ */
/* 系统全局变量声明。                                                       */
/* ------------------------------------------------------------------------ */
extern VMINT vm_is_card2Absent(void);
extern VMINT vm_is_card1Absent(void);
//extern void  vm_phb_build_contact_ptr(vm_phb_contact_struct* contact, srv_phb_sdk_contact_struct * contact_ptr);	

/* ------------------------------------------------------------------------ */
/* 系统函数声明。                                                           */
/* ------------------------------------------------------------------------ */
void vm_phb_callback_manager(S32 result, srv_phb_sdk_contact_struct* contact_ptr);

/* ------------------------------------------------------------------------ */
/* 模块内部变量声明。                                                       */
/* ------------------------------------------------------------------------ */
static VMINT vm_phb_storage_is_valid(vm_phb_storage_loc_enum storage);
static void  vm_phb_queue_manager(VMINT tid);

static VMINT phb_busy_flag = 0;

static VMINT phb_process_handle = -1;

extern VMINT vre_running;

typedef enum
{
	VM_PHB_ADD,
  	VM_PHB_DELETE,
  	VM_PHB_UPDATE,
  	VM_PHB_SEARCH,
  	VM_PHB_GET_CONTACT
    
}phb_operation_type;


typedef struct
{
 	VMINT  operation_type;
 	vm_phb_add_req_struct* req_info;
 	vm_phb_callback_type cb;
 
 }phb_add_t;

typedef struct
{
	VMINT  operation_type;
 	vm_phb_delete_req_struct* req_info;
 	vm_phb_callback_type cb;
 
 }phb_delete_t;

typedef struct
{
	VMINT  operation_type;
	vm_phb_update_req_struct* req_info;
	vm_phb_callback_type cb;
 
 }phb_update_t;


typedef struct
{
	VMINT  operation_type;
	vm_phb_search_req_struct* req_info;
	vm_phb_callback_type cb;
 
 }phb_search_t;

typedef struct
{
	VMINT  operation_type;
	vm_phb_get_req_struct* req_info;
	vm_phb_callback_type cb;
 
 }phb_get_contact_t;



/* ------------------------------------------------------------------------ */
/* 模块内部函数声明。                                                       */
/* ------------------------------------------------------------------------ */
static void  vm_phb_process_status_callback(VM_P_HANDLE process_handle, VMINT sys_state);

/* ------------------------------------------------------------------------ */
/* 函数定义                                                    */
/* ------------------------------------------------------------------------ */

static void vm_finialize_phb_module(void)
{
 
	phb_busy_flag=0;
	phb_process_handle = -1;
 
	vm_res_type_set_notify_callback(VM_RES_TYPE_PHONE_BOOK,  NULL);
   
}


static void vm_intial_phb_module(void)
{ 
	phb_busy_flag=0;
	phb_process_handle = -1;

	vm_res_type_set_notify_callback(VM_RES_TYPE_PHONE_BOOK,  vm_phb_process_status_callback);
}

/*
  * 电话簿模块的生命周期函数。
  */
static VMINT phb_mod_evt_proc(VRE_MOD_LIFECIRCLE_EVT event)
{
  
	switch(event)
	{
		case EVT_MOD_INIT:
			vm_intial_phb_module();
	
			break;
		case EVT_MOD_ACTIVE:
			break;
		case EVT_MOD_INACTIVE:
			break;
		case EVT_MOD_RELEASE:
			vm_finialize_phb_module();
			break;
		default:
			vm_log_error("{PHB MODULE}Receive unkown [%d] event.", event);
			return -2;
	}

	return 0;
}


VMINT _vm_reg_phb_module(void)
{
	int res = 0;
	
	if ((res = _vm_reg_module("PHB MODULE", (MOD_EVT_PROCESS)phb_mod_evt_proc)) != REG_VRE_MODULE_SUCCESS)
	{
		vm_log_error("Failed to regisiter phb module. Error Code : %d", res);
	}
	return res;
}

static void  vm_phb_process_status_callback(VM_P_HANDLE process_handle, VMINT sys_state)
{
	VMINT i = 0;
	VMINT res = -1;
	phb_add_t * phb_add = NULL;
	phb_delete_t * phb_delete = NULL;
	phb_update_t * phb_update = NULL;
	phb_search_t * phb_search = NULL;
	phb_get_contact_t * phb_get_contact = NULL;
	VMINT* data_buffer = NULL;  
	VMINT buffer_size = 0;

	VMINT cur_data_handle = -1;
	VMINT is_cur_node = FALSE;
       VMINT p_handle = -1; 
	
	cur_data_handle = vm_res_findfirst(-1, VM_RES_TYPE_PHONE_BOOK);
	if(cur_data_handle == VM_RES_NOT_FIND)
		return;
	vm_res_findclose(VM_RES_TYPE_PHONE_BOOK);
	
	p_handle = vm_res_get_process_handle( VM_RES_TYPE_PHONE_BOOK, cur_data_handle);
	if(p_handle == process_handle)
	{
		is_cur_node = TRUE;
	}	
	switch(sys_state)
	{
		case VM_PMNG_UNLOAD:
			/*删除所有进程相关结点*/
			vm_log_debug("vm_phb_process_status_callback:start");  
			while ( (i = vm_res_findfirst(process_handle, VM_RES_TYPE_PHONE_BOOK)) != VM_RES_NOT_FIND)
			{
				res= vm_res_get_data( VM_RES_TYPE_PHONE_BOOK, i, (void**)&data_buffer, &buffer_size );

				if(res == 0)
				{
					switch(data_buffer[0])
					{
	              
						case VM_PHB_ADD:
							phb_add = (phb_add_t *)data_buffer;
							vm_free(phb_add->req_info);	
							vm_free(phb_add);
							vm_log_debug("vm_phb_process_status_callback:VM_PHB_ADD");   	
							break;

						case VM_PHB_DELETE:
							phb_delete = (phb_delete_t *)data_buffer;
							vm_free(phb_delete->req_info);	
							vm_free(phb_delete);
							vm_log_debug("vm_phb_process_status_callback:VM_PHB_DELETE");   
							break;

						case VM_PHB_UPDATE:
							phb_update = (phb_update_t *)data_buffer;
							vm_free(phb_update->req_info);	
							vm_free(phb_update);
							vm_log_debug("vm_phb_process_status_callback:VM_PHB_UPDATE");   
							break;

						case VM_PHB_SEARCH:
							phb_search = (phb_search_t *)data_buffer;
							vm_free(phb_search->req_info);	
							vm_free(phb_search);
							vm_log_debug("vm_phb_process_status_callback:VM_PHB_SEARCH"); 
							break;

						case VM_PHB_GET_CONTACT:
							phb_get_contact = (phb_get_contact_t *)data_buffer;
							vm_free(phb_get_contact->req_info);	
							vm_free(phb_get_contact);
							vm_log_debug("vm_phb_process_status_callback:VM_PHB_GET_CONTACT"); 
							break;
     
						default:
							vm_log_debug("vm_phb_process_status_callback:type=%d error",data_buffer[0]);  
							break;
					}
				
				}
				vm_res_release_data(VM_RES_TYPE_PHONE_BOOK,  i); 
				vm_log_debug("vm_phb_process_status_callback : data handle=%d", i);
				vm_res_findclose(VM_RES_TYPE_PHONE_BOOK);
			}
			
			if( (is_cur_node == TRUE) &&(phb_process_handle == -1))
			{
				cur_data_handle = vm_res_findfirst(-1, VM_RES_TYPE_PHONE_BOOK);
				if(cur_data_handle == VM_RES_NOT_FIND)
					return;
				vm_res_findclose(VM_RES_TYPE_PHONE_BOOK);
				
				p_handle = vm_res_get_process_handle( VM_RES_TYPE_PHONE_BOOK, cur_data_handle);
				if (vm_pmng_set_ctx(p_handle) == VM_PMNG_OP_OK)
				{
					if(vm_create_timer(100, (VM_TIMERPROC_T)vm_phb_queue_manager)<0)
					{
						vm_log_debug("vm_phb_process_status_callback timer fail");
					}
					phb_process_handle = -1;
					vm_pmng_reset_ctx();     
				}
							       
			}		
			vm_log_debug("vm_phb_process_status_callback:end");  
					
			break;
		case VM_PMNG_FOREGROUND:
			break;
		case VM_PMNG_BACKGROUND:
			break;
	}


}


static void  vm_phb_queue_manager(VMINT tid)
{ 
  
	phb_add_t * phb_add = NULL;
	phb_delete_t * phb_delete = NULL;
	phb_update_t * phb_update = NULL;
	phb_search_t * phb_search = NULL;
	phb_get_contact_t * phb_get_contact = NULL;
	vm_res_node_t res_node;
	VMINT * data_buffer = NULL;
	VMINT res = -1;
	VMINT i = 0;


	if(tid >=0)
	{
		vm_log_debug("vm_phb_queue_manager  delete time=%d", tid);
		i = vm_delete_timer(tid);
		if(i < 0)
		{
			vm_log_error("vm_phb_queue_manager:vm_delete_timer fail");
		}
		else
		{

			vm_log_debug("vm_phb_queue_manager:vm_delete_timer success");
		}
	}
	if(phb_busy_flag)
	{
		vm_log_debug("vm_phb_queue_manager:sms_busy_flag=1");
		return;
	}
	
	res = vm_res_get_data_list_by_type(VM_RES_TYPE_PHONE_BOOK, &res_node, 1);
	if(res <= 0)
	{
		vm_log_debug("vm_phb_queue_manager:vm_res_get_data fail");
		return;
	}
	vm_log_debug("vm_phb_queue_manager:res=%d",res);
	
	
	phb_busy_flag = 1;
	data_buffer = (VMINT * )res_node.data_content;
	
	vm_log_debug("vm_phb_queue_manager:type=%d",data_buffer[0]);  
	phb_process_handle = res_node.phandle;
	switch(data_buffer[0])
	{
     
		case VM_PHB_ADD:
			phb_add = (phb_add_t *)res_node.data_content;
			vm_log_debug("phb_add->req_info->contact_ptr->name=%s",vm_gb2312_string((VMWSTR)phb_add->req_info->contact_ptr->name));
			vm_log_debug("phb_add->req_info->contact_ptr->number=%s",vm_gb2312_string((VMWSTR)phb_add->req_info->contact_ptr->number));
			res = vm_sal_phb_add_contact( phb_add->req_info,  phb_add->cb);
			if(res < 0)
			{
				vm_phb_callback_manager(res, NULL);
				vm_log_error("vm_phb_queue_manager:VM_PHB_ADD res=%d", res);   	
			}
			vm_log_debug("vm_phb_queue_manager:VM_PHB_ADD");   	
			break;

		case VM_PHB_DELETE:
			phb_delete = (phb_delete_t *)res_node.data_content;
			res = vm_sal_phb_delete_contact( phb_delete->req_info,  phb_delete->cb);
			if(res < 0)
			{
				vm_phb_callback_manager(res, NULL);
				vm_log_error("vm_phb_queue_manager:VM_PHB_DELETE res=%d", res);   	
			}
			vm_log_debug("vm_phb_queue_manager:VM_PHB_DELETE");   
			break;

		case VM_PHB_UPDATE:
			phb_update = (phb_update_t *)res_node.data_content;
			res = vm_sal_phb_update_contact( phb_update->req_info,  phb_update->cb);
			if(res < 0)
			{
				vm_phb_callback_manager(res, NULL);
				vm_log_error("vm_phb_queue_manager:VM_PHB_UPDATE res=%d", res);   	
			}
			vm_log_debug("vm_phb_queue_manager:VM_PHB_UPDATE");   
			break;

		case VM_PHB_SEARCH:
			phb_search = (phb_search_t *)res_node.data_content;
			res = vm_sal_phb_search_contact( phb_search->req_info,  phb_search->cb);
			if(res < 0)
			{
				vm_phb_callback_manager(res, NULL);
				vm_log_error("vm_phb_queue_manager:VM_PHB_SEARCH res=%d", res);   	
			}
			vm_log_debug("vm_phb_queue_manager:VM_PHB_SEARCH"); 
		   	break;

	       case VM_PHB_GET_CONTACT:
			phb_get_contact = (phb_get_contact_t *)res_node.data_content;
			res = vm_sal_phb_get_contact(phb_get_contact->req_info,  phb_get_contact->cb);
			if(res < 0)
			{
				vm_phb_callback_manager(res, NULL);
				vm_log_error("vm_phb_queue_manager:VM_PHB_GET_CONTACT res=%d", res);   	
			}
			vm_log_debug("vm_phb_queue_manager:VM_PHB_GET_CONTACT"); 
			break;
		
		default:
			phb_busy_flag = 0;
			vm_log_debug("vm_phb_queue_manager:type=%d error",data_buffer[0]);  
			break;
	}
	
	vm_log_debug("vm_phb_queue_manager:end");  

 
}


void vm_phb_callback_manager(S32 result, srv_phb_sdk_contact_struct* contact_ptr)
{
	VMINT data_handle = -1;
	VMINT i = 0;
	VMINT res = -1;
	vm_res_node_t res_node;
	vm_phb_callback_type callback;
	 
	phb_add_t *     phb_add = NULL;
	phb_delete_t * phb_delete = NULL;
	phb_update_t * phb_update = NULL;
	phb_search_t * phb_search = NULL;
	phb_get_contact_t * phb_get_contact = NULL;
	 
	VMINT * data_buffer = NULL;
	VMINT phbresult = -1;

	if(vre_running == FALSE)
		return;
  
	vm_log_debug("vm_phb_callback_manager:reault =%d",result );
	switch(result)
	{
		case SRV_PHB_NAME_MODIFIED:
			phbresult = VM_PHB_NAME_MODIFIED;
			break;

		case SRV_PHB_NO_ERROR:
		 	phbresult = VM_PHB_NO_ERROR;
			break;

		case SRV_PHB_ERROR :
			phbresult = VM_PHB_ERROR;
			break;

		case SRV_PHB_NOT_READY:
			phbresult = VM_PHB_NOT_READY;
			break;

		case SRV_PHB_NUM_NOT_READY:
			phbresult = VM_PHB_NUM_NOT_READY;
			break;

		case SRV_PHB_NOT_SUPPORT:
			phbresult = VM_PHB_NOT_SUPPORT;
			break;
		
		case SRV_PHB_NOT_FOUND:
			phbresult = VM_PHB_NOT_FOUND;
			break;

		case SRV_PHB_DATAMGR_BUSY:
			phbresult = VM_PHB_DATAMGR_BUSY;
			break;

		case SRV_PHB_STORAGE_FULL:
			phbresult = VM_PHB_STORAGE_FULL;
			break;
		
		case SRV_PHB_NO_SIM_CARD:
			phbresult = VM_PHB_NO_SIM_CARD;
			break;

		case SRV_PHB_ADN_FORBID:
			phbresult = VM_PHB_ADN_FORBID;
			break;

		case SRV_PHB_OUT_OF_INDEX:
			phbresult = VM_PHB_OUT_OF_INDEX;
			break;

		case SRV_PHB_NUMBER_TOO_LONG:
			phbresult = VM_PHB_NUMBER_TOO_LONG;
			break;
		 
		case SRV_PHB_BIRTHDAY_ERROR:
			phbresult = VM_PHB_BIRTHDAY_ERROR;
			break;

		default:
			phbresult = VM_PHB_ERROR;
			break;

	}
	   
     	  
	res = vm_res_get_data_list_by_type(VM_RES_TYPE_PHONE_BOOK, &res_node, 1);
	  
	vm_log_debug("vm_phb_callback_manager:res=%d count = %d", res, vm_res_get_data_list_count_by_type(VM_RES_TYPE_PHONE_BOOK));
	 
	if(res <= 0)
	{
		vm_log_debug("vm_phb_callback_manager:res <= 0");
		return;
	}
	data_handle = res_node.res_id;
	  
	if(phb_process_handle == res_node.phandle)
	{
		if (vm_pmng_set_ctx(res_node.phandle) == VM_PMNG_OP_OK)
		{
			vm_log_debug("vm_phb_callback_manager:phandle=%d, result=%d", res_node.phandle, result);
			vm_res_get_callback(VM_RES_TYPE_PHONE_BOOK, data_handle, (void * * )&callback);
			//callback(phbresult, user_phb_contact);
	   
			data_buffer = (VMINT * )res_node.data_content;
	
			vm_log_debug("vm_phb_callback_manager:type=%d",data_buffer[0]);   
			switch(data_buffer[0])
			{
	          
				case VM_PHB_ADD:
					phb_add = (phb_add_t *)res_node.data_content;
					vm_phb_build_contact_ptr(phb_add->req_info->contact_ptr , contact_ptr);
					if(callback != NULL)
						callback(phbresult, phb_add->req_info->contact_ptr);
					vm_free(phb_add->req_info);
					vm_log_debug("vm_phb_callback_manager:VM_PHB_ADD");   	
					break;

				case VM_PHB_DELETE:
					phb_delete = (phb_delete_t *)res_node.data_content;
					if(callback != NULL)
						callback(phbresult, NULL);
					vm_free(phb_delete->req_info);
					vm_log_debug("vm_phb_callback_manager:VM_PHB_DELETE");   
					break;

				case VM_PHB_UPDATE:
					phb_update = (phb_update_t *)res_node.data_content;
					vm_phb_build_contact_ptr(phb_update->req_info->contact_ptr , contact_ptr);
					if(callback != NULL)
						callback(phbresult, phb_update->req_info->contact_ptr);
					vm_free(phb_update->req_info);
					vm_log_debug("vm_phb_callback_manager:VM_PHB_UPDATE");   
					break;

				case VM_PHB_SEARCH:
					phb_search = (phb_search_t *)res_node.data_content;
					vm_phb_build_contact_ptr(phb_search->req_info->contact_ptr , contact_ptr);
					if(callback != NULL)
						callback(phbresult, phb_search->req_info->contact_ptr);
					vm_free(phb_search->req_info);
					vm_log_debug("vm_phb_callback_manager:VM_PHB_SEARCH"); 
					break;

				case VM_PHB_GET_CONTACT:
					phb_get_contact = (phb_get_contact_t *)res_node.data_content;
					vm_phb_build_contact_ptr(phb_get_contact->req_info->contact_ptr , contact_ptr);
					if(callback != NULL)
						callback(phbresult, phb_get_contact->req_info->contact_ptr);
					vm_free(phb_get_contact->req_info);
					vm_log_debug("vm_phb_callback_manager:VM_PHB_GET_CONTACT"); 
					break;
	     
       
				default:
					vm_log_debug("vm_phb_callback_manager:type=%d error",data_buffer[0]);  
					break;
			}
		 
	       
			if(res_node.data_content)
				vm_free(res_node.data_content);

			vm_log_debug("vm_phb_callback_manager: vm_free(&res_node.data_content)");    
	   
			i= vm_res_release_data(VM_RES_TYPE_PHONE_BOOK,  data_handle); 
			if(i < 0)
			{
				vm_log_error("vm_phb_callback_manager:vm_res_release_data fail");
			}
         	 
			vm_log_debug("vm_phb_callback_manager:release_data i=%d",i); 
		
		   
			vm_pmng_reset_ctx();     
	   
		}
			  
	}

	vm_log_debug("vm_phb_callback_manager:count=%d",vm_res_get_data_list_count_by_type(VM_RES_TYPE_PHONE_BOOK) );
	if(vm_res_get_data_list_count_by_type(VM_RES_TYPE_PHONE_BOOK) > 0 )
	{
		vm_res_get_data_list_by_type(VM_RES_TYPE_PHONE_BOOK, &res_node, 1);
		if (vm_pmng_set_ctx(res_node.phandle) == VM_PMNG_OP_OK)
		{
			if(vm_create_timer(100, (VM_TIMERPROC_T)vm_phb_queue_manager)<0)
			{
				
				vm_log_debug("vm_phb_callback_manager timer fail");
                     }
		       phb_process_handle = -1;				   
		       vm_pmng_reset_ctx();     
		 }
	}
	   
       phb_busy_flag = 0;
		
       vm_log_debug("vm_phb_callback_manager:vm_phb_callback_manager end");   	
	

}



vm_phb_req_error_enum vm_phb_add_contact(vm_phb_add_req_struct* req_info,  vm_phb_callback_type cb)
{
	phb_add_t * phb_add = NULL;
	vm_phb_add_req_struct *req_info_ptr = NULL;
	VMINT pid = -1;
	VMINT avaliable = -1;
	VMINT data_handle = -1;
  		 
	if(req_info == NULL || req_info->contact_ptr == NULL)
       {
		vm_log_error("vm_phb_add_contact:req_info == NULL");
		return VM_PHB_REQ_ERROR;
       }
    
	if(req_info->storage == VM_PHB_STORAGE_LOC_BOTH)
	{
		vm_log_error("vm_phb_add_contact:VM_PHB_STORAGE_LOC_BOTH");
		return VM_PHB_REQ_ERROR;
	}
	  
	if(vm_phb_storage_is_valid(req_info->storage) != VM_PHB_REQ_NO_ERROR)
	{
		vm_log_error("vm_phb_add_contact:vm_phb_storage_is_not_valid");
		return VM_PHB_REQ_ERROR;
	}
	   
	if((vm_wstrlen((VMWSTR)req_info->contact_ptr->name) == 0) && (vm_wstrlen((VMWSTR)req_info->contact_ptr->number) == 0))
	{
		vm_log_error("vm_phb_add_contact:name or number is NULL");
		return VM_PHB_REQ_ERROR;
	}  	

	pid = vm_pmng_get_current_handle();
	if(pid <=0)
		return VM_PHB_REQ_ERROR;	
      	   
	avaliable = vm_res_type_avaliable_handle(VM_RES_TYPE_PHONE_BOOK, pid);
	if(avaliable <= 0)
	{
		vm_log_error("vm_phb_add_contact : avaliable <= 0");
		return VM_PHB_REQ_ERROR;
	   
	}
	req_info_ptr = vm_calloc(sizeof(vm_phb_add_req_struct));
	if(req_info_ptr == NULL)
	{
		vm_log_error("vm_phb_add_contact:req_info_ptr == NULL");
		return VM_PHB_REQ_ERROR;
	}
	phb_add = vm_calloc(sizeof(phb_add_t));
	if(phb_add == NULL)
	{
		vm_free(req_info_ptr);
		vm_log_error("vm_phb_add_contact:phb_add == NULL");
		return VM_PHB_REQ_ERROR;
	}
	req_info_ptr->contact_ptr = req_info->contact_ptr;
	req_info_ptr->storage = req_info->storage;
	phb_add->operation_type = VM_PHB_ADD;
	phb_add->req_info = req_info_ptr;
	phb_add->cb = cb;
	
	if(vm_res_get_data_list_count_by_type(VM_RES_TYPE_PHONE_BOOK) == 0 )
	{
		if(vm_create_timer(100, (VM_TIMERPROC_T)vm_phb_queue_manager)<0)
		{
			
			vm_log_error("vm_phb_add_contact timer fail");
		}
	
	}
	
	data_handle = vm_res_save_data(VM_RES_TYPE_PHONE_BOOK, phb_add,  sizeof(phb_add_t), (void *)cb, pid);
	if(data_handle < 0)
       {
		vm_log_error("vm_phb_add_contact data_handle < 0");
		vm_free(req_info_ptr);
		vm_free(phb_add);
		return VM_PHB_REQ_ERROR;
	}
	vm_log_debug("vm_phb_add_contact count = %d",vm_res_get_data_list_count_by_type(VM_RES_TYPE_PHONE_BOOK));
  	
	return VM_PHB_REQ_NO_ERROR;
	   
}


vm_phb_req_error_enum vm_phb_delete_contact(vm_phb_delete_req_struct* req_info,   vm_phb_callback_type cb)
{
     
	phb_delete_t * phb_delete = NULL;
	vm_phb_delete_req_struct * req_info_ptr = NULL;
       VMINT pid = -1;
       VMINT avaliable = -1;
	VMINT data_handle = -1;
   
	if(req_info == NULL)
       {
		vm_log_error("vm_phb_delete_contact:req_info == NULL");
		return VM_PHB_REQ_ERROR;
	}

	if(req_info->pos.storage == VM_PHB_STORAGE_LOC_BOTH)
	{
		vm_log_error("vm_phb_delete_contact:VM_PHB_STORAGE_LOC_BOTH");
		return VM_PHB_REQ_ERROR;
	} 
	 
	if(vm_phb_storage_is_valid(req_info->pos.storage) != VM_PHB_REQ_NO_ERROR)
	{
		vm_log_error("vm_phb_delete_contact:vm_phb_storage_is_not_valid");
		return VM_PHB_REQ_ERROR;
	}

	pid = vm_pmng_get_current_handle();
	if(pid < 0)
		return VM_PHB_REQ_ERROR;	
	
	avaliable = vm_res_type_avaliable_handle(VM_RES_TYPE_PHONE_BOOK, pid);
	if(avaliable <= 0)
	{
		vm_log_error("vm_phb_delete_contact : avaliable <= 0");
		return VM_PHB_REQ_ERROR;
	   
	}
	req_info_ptr = vm_calloc(sizeof(vm_phb_delete_req_struct));
	if(req_info_ptr == NULL)
	{
		vm_log_error("vm_phb_delete_contact:req_info_ptr == NULL");
		return VM_PHB_REQ_ERROR;
	}
	phb_delete = vm_calloc(sizeof(phb_delete_t));
	if( phb_delete == NULL)
	{
		vm_free(req_info_ptr);
		vm_log_error("vm_phb_delete_contact:phb_delete == NULL");
		return VM_PHB_REQ_ERROR;
      	}
	
	req_info_ptr->pos = req_info->pos;
	phb_delete->operation_type = VM_PHB_DELETE;
	phb_delete->req_info = req_info_ptr;
	phb_delete->cb = cb;

	if(vm_res_get_data_list_count_by_type(VM_RES_TYPE_PHONE_BOOK) == 0 )
	{
		if(vm_create_timer(100, (VM_TIMERPROC_T)vm_phb_queue_manager)<0)
		{
			
			vm_log_debug("vm_phb_delete_contact timer fail");
		}
		
	   
	}
	 
	data_handle = vm_res_save_data(VM_RES_TYPE_PHONE_BOOK, phb_delete,  sizeof(phb_delete_t), (void *)cb, pid);
	if(data_handle < 0)
	{
		vm_log_error("vm_phb_delete_contact data_handle < 0");
		vm_free(req_info_ptr);
		vm_free(phb_delete);
		return VM_PHB_REQ_ERROR;
	}
	vm_log_debug("vm_phb_delete_contact count = %d",vm_res_get_data_list_count_by_type(VM_RES_TYPE_PHONE_BOOK));
	
	return VM_PHB_REQ_NO_ERROR;
	   

}

vm_phb_req_error_enum vm_phb_update_contact(vm_phb_update_req_struct* req_info,  vm_phb_callback_type cb)
{
	phb_update_t * phb_update = NULL;
	vm_phb_update_req_struct * req_info_ptr =NULL;
	VMINT pid = -1;
	VMINT avaliable = -1;
	VMINT data_handle = -1;
	
	if(req_info == NULL || req_info->contact_ptr == NULL)
	{
		vm_log_error("vm_phb_update_contact :req_info == NULL,req_info->contact_ptr == NULL");
		return VM_PHB_REQ_ERROR;
	}
	  

	if(req_info->pos.storage == VM_PHB_STORAGE_LOC_BOTH)
	{
		vm_log_error("vm_phb_update_contact:VM_PHB_STORAGE_LOC_BOTH");
		return VM_PHB_REQ_ERROR;
      	} 
	   
       if(vm_phb_storage_is_valid(req_info->pos.storage) != VM_PHB_REQ_NO_ERROR)
	{
		vm_log_error("vm_phb_update_contact:vm_phb_storage_is_not_valid");
		return VM_PHB_REQ_ERROR;
      	}

	if((vm_wstrlen((VMWSTR)req_info->contact_ptr->name) == 0) && (vm_wstrlen((VMWSTR)req_info->contact_ptr->number) == 0))
	{
		vm_log_error("vm_phb_update_contact:name or number is NULL");
		return VM_PHB_REQ_ERROR;
      	}  	

	pid = vm_pmng_get_current_handle();
	if(pid <= 0)
		return VM_PHB_REQ_ERROR;	
	
	avaliable = vm_res_type_avaliable_handle(VM_RES_TYPE_PHONE_BOOK, pid);
	if(avaliable <= 0)
	{
		vm_log_error("vm_phb_update_contact : avaliable <= 0");
		return VM_PHB_REQ_ERROR;
	   
	}
	
       req_info_ptr = vm_calloc(sizeof(vm_phb_update_req_struct));
	if(req_info_ptr == NULL)
	{
		vm_log_error("vm_phb_update_contact:req_info_ptr == NULL");
		return VM_PHB_REQ_ERROR;
      	}
       phb_update = vm_calloc(sizeof(phb_update_t));
	if(phb_update == NULL)
	{
		vm_free(req_info_ptr);
		vm_log_error("vm_phb_update_contact:phb_update == NULL");
		return VM_PHB_REQ_ERROR;
      	}
	
	req_info_ptr->contact_ptr = req_info->contact_ptr;
	req_info_ptr->pos = req_info->pos;
       phb_update->operation_type = VM_PHB_UPDATE;
	phb_update->req_info = req_info_ptr;
	phb_update->cb = cb;

	if(vm_res_get_data_list_count_by_type(VM_RES_TYPE_PHONE_BOOK) == 0 )
	{
		if(vm_create_timer(100, (VM_TIMERPROC_T)vm_phb_queue_manager)<0)
		{
			
			vm_log_debug("vm_phb_update_contact timer fail");
		}
		
	}
	 
	data_handle = vm_res_save_data(VM_RES_TYPE_PHONE_BOOK, phb_update,  sizeof(phb_update_t), (void *)cb, pid);
	if(data_handle < 0)
	{
		vm_log_error("vm_phb_update_contact data_handle < 0");
		vm_free(req_info_ptr);
		vm_free(phb_update);
		return VM_PHB_REQ_ERROR;
	}
	vm_log_debug("vm_phb_update_contact count = %d",vm_res_get_data_list_count_by_type(VM_RES_TYPE_PHONE_BOOK));
	
	return VM_PHB_REQ_NO_ERROR;
	   

}


vm_phb_req_error_enum vm_phb_search_contact(vm_phb_search_req_struct* req_info,   vm_phb_callback_type cb)
{
	phb_search_t * phb_search = NULL;
	vm_phb_search_req_struct * req_info_ptr = NULL;
	VMINT pid = -1;
	VMINT avaliable = -1;
	VMINT data_handle = -1;
	
	if(req_info == NULL || req_info->contact_ptr == NULL)
	{
		vm_log_error("vm_phb_search_contact:req_info == NULL");
		return VM_PHB_REQ_ERROR;
       }

	pid = vm_pmng_get_current_handle();
	if(pid <= 0)
		return VM_PHB_REQ_ERROR;	
	
	avaliable = vm_res_type_avaliable_handle(VM_RES_TYPE_PHONE_BOOK, pid);
	if(avaliable <= 0)
	{
		vm_log_error("vm_phb_search_contact : avaliable <= 0");
		return VM_PHB_REQ_ERROR;
	   
	}
	req_info_ptr = vm_calloc(sizeof(vm_phb_search_req_struct));
	if(req_info_ptr == NULL)
	{
		vm_log_error("vm_phb_search_contact:req_info_ptr == NULL");
		return VM_PHB_REQ_ERROR;
      	}
	phb_search = vm_calloc(sizeof(phb_search_t));
	if(!phb_search)
	{
		vm_free(req_info_ptr);
		vm_log_error("vm_phb_search_contact:phb_search == NULL");
		return VM_PHB_REQ_ERROR;
	}
	
	req_info_ptr->contact_ptr = req_info->contact_ptr;
	req_info_ptr->search_type = req_info->search_type;
	vm_wstrncpy(req_info_ptr->pattern_ucs2, req_info->pattern_ucs2, VM_PHB_MAX_SEARCH_LENGTH-1);
	phb_search->operation_type = VM_PHB_SEARCH;
	phb_search->req_info = req_info_ptr;
	phb_search->cb = cb;

	if(vm_res_get_data_list_count_by_type(VM_RES_TYPE_PHONE_BOOK) == 0 )
	{
		if(vm_create_timer(100, (VM_TIMERPROC_T)vm_phb_queue_manager)<0)
		{
			
			vm_log_debug("vm_phb_search_contact timer fail");
		}
		
	}
	 
	data_handle = vm_res_save_data(VM_RES_TYPE_PHONE_BOOK, phb_search,  sizeof(phb_search_t), (void *)cb, pid);
	if(data_handle < 0)
	{
		vm_log_error("vm_phb_search_contact data_handle < 0");
		vm_free(req_info_ptr);
		vm_free(phb_search);
		return VM_PHB_REQ_ERROR;
	}
	vm_log_debug("vm_phb_search_contact count = %d",vm_res_get_data_list_count_by_type(VM_RES_TYPE_PHONE_BOOK));
		
	return VM_PHB_REQ_NO_ERROR;
}


vm_phb_req_error_enum vm_phb_get_contact(vm_phb_get_req_struct* req_info,    vm_phb_callback_type cb)
{
	phb_get_contact_t * phb_get_contact = NULL;
	vm_phb_get_req_struct * req_info_ptr = NULL;
	VMINT pid = -1;
	VMINT avaliable = -1;
	VMINT data_handle = -1;
	
	if(req_info == NULL || req_info->contact_ptr == NULL)
	{
		vm_log_error("vm_phb_get_contact:req_info == NULL");
		return VM_PHB_REQ_ERROR;
	}

	if(req_info->pos.storage == VM_PHB_STORAGE_LOC_BOTH)
	{
		vm_log_error("vm_phb_get_contact:VM_PHB_STORAGE_LOC_BOTH");
		return VM_PHB_REQ_ERROR;
      	}
	   
	if(vm_phb_storage_is_valid(req_info->pos.storage) != VM_PHB_REQ_NO_ERROR)
	{
		vm_log_error("vm_phb_get_contact:vm_phb_storage_is_not_valid");
		return VM_PHB_REQ_ERROR;
      	}
	   
	pid = vm_pmng_get_current_handle();
	if(pid <= 0)
		return VM_PHB_REQ_ERROR;	
	
	avaliable = vm_res_type_avaliable_handle(VM_RES_TYPE_PHONE_BOOK, pid);
	if(avaliable <= 0)
	{
		vm_log_error("vm_phb_get_contact : avaliable <= 0");
		return VM_PHB_REQ_ERROR;
	   
	}
	req_info_ptr = vm_calloc(sizeof(vm_phb_get_req_struct));
	if(req_info_ptr == NULL)
	{
		vm_log_error("vm_phb_get_contact:req_info_ptr == NULL");
		return VM_PHB_REQ_ERROR;
      	}
       phb_get_contact = vm_calloc(sizeof(phb_get_contact_t));
	if(phb_get_contact == NULL)
	{
		vm_free(req_info_ptr);
		vm_log_error("vm_phb_get_contact:phb_get_contact == NULL");
		return VM_PHB_REQ_ERROR;
      	}
	
	req_info_ptr->contact_ptr = req_info->contact_ptr;
	req_info_ptr->pos = req_info->pos;
	phb_get_contact->operation_type = VM_PHB_GET_CONTACT;
	phb_get_contact->req_info = req_info_ptr;
	phb_get_contact->cb = cb;

	if(vm_res_get_data_list_count_by_type(VM_RES_TYPE_PHONE_BOOK) == 0 )
	{
		if(vm_create_timer(100, (VM_TIMERPROC_T)vm_phb_queue_manager)<0)
		{
			
			vm_log_debug("vm_phb_get_contact timer fail");
		}
		
	}
	
	data_handle = vm_res_save_data(VM_RES_TYPE_PHONE_BOOK, phb_get_contact,  sizeof(phb_get_contact_t), (void *)cb, pid);
	if(data_handle < 0)
       {
		vm_log_error("vm_phb_get_contact data_handle < 0");
		vm_free(req_info_ptr);
		vm_free(phb_get_contact);
		return VM_PHB_REQ_ERROR;
	}
	vm_log_debug("vm_phb_get_contact count = %d",vm_res_get_data_list_count_by_type(VM_RES_TYPE_PHONE_BOOK));
	

	return VM_PHB_REQ_NO_ERROR;

}

vm_phb_req_error_enum vm_phb_search_contact_syn(vm_phb_search_req_struct* req_info)
{
	VMINT res = VM_PHB_REQ_ERROR;
	
	if(req_info == NULL || req_info->contact_ptr == NULL)
	{
		vm_log_error("vm_phb_search_contact_syn:req_info == NULL");
		return VM_PHB_REQ_ERROR;
       }
	
	res = vm_sal_phb_search_contact_syn(req_info);
	
	vm_log_debug("vm_phb_search_contact_syn:end");  
	
       return res;

}

vm_phb_req_error_enum vm_phb_get_contact_syn(vm_phb_get_req_struct* req_info)
{
	VMINT res = VM_PHB_REQ_ERROR;
	
	
	if(req_info == NULL || req_info->contact_ptr == NULL)
	{
		vm_log_error("vm_phb_get_contact_syn:req_info == NULL");
		return VM_PHB_REQ_ERROR;
	}
     
	if(req_info->pos.storage == VM_PHB_STORAGE_LOC_BOTH)
	{
		vm_log_error("vm_phb_get_contact_syn:VM_PHB_STORAGE_LOC_BOTH");
		return VM_PHB_REQ_ERROR;
      	}
	   
	if(vm_phb_storage_is_valid(req_info->pos.storage) != VM_PHB_REQ_NO_ERROR)
	{
		vm_log_error("vm_phb_get_contact_syn:vm_phb_storage_is_not_valid");
		return VM_PHB_REQ_ERROR;
      	}
	  
	res = vm_sal_phb_get_contact_syn(req_info);

	vm_log_debug("vm_phb_get_contact_syn:end");  
	
       return res;

}



VMINT vm_phb_get_total_contacts(vm_phb_storage_loc_enum storage)
{
	VMINT res = VM_PHB_REQ_ERROR;
       
	if(vm_phb_storage_is_valid(storage) != VM_PHB_REQ_NO_ERROR)
	{
		vm_log_error("vm_phb_get_total_contacts:vm_phb_storage_is_not_valid");
		return VM_PHB_REQ_ERROR;
	}

	res = vm_sal_phb_get_total_contacts(storage);
	    
	vm_log_debug("vm_phb_get_total_contacts:res=%d", res);
	return res;

}


VMINT vm_phb_get_used_contacts_count(vm_phb_storage_loc_enum storage)
{

	VMINT res = VM_PHB_REQ_ERROR;
    
	if(vm_phb_storage_is_valid(storage) != VM_PHB_REQ_NO_ERROR)
	{
		vm_log_error("vm_phb_get_used_contacts_count:vm_phb_storage_is_not_valid");
		return VM_PHB_REQ_ERROR;
	}
	res = vm_sal_phb_get_used_contacts_count(storage);
	vm_log_debug("vm_phb_get_used_contacts_count:res = %d", res);
	  
	return res;
        
}


VMINT vm_phb_get_used_contacts(vm_phb_contact_pos_struct* pos_array,  vm_phb_storage_loc_enum storage)
{
    
	VMINT res = VM_PHB_REQ_ERROR;

	if(vm_phb_storage_is_valid(storage) != VM_PHB_REQ_NO_ERROR)
       {
		vm_log_error("vm_phb_get_used_contacts:vm_phb_storage_is_not_valid");
		return VM_PHB_REQ_ERROR;
       }
 	  
	res = vm_sal_phb_get_used_contacts(pos_array, storage);

	vm_log_debug("vm_phb_get_used_contacts:res = %d", res);
	return res;
	
        
}


VMINT vm_phb_search_contact_list(vm_phb_search_list_req_struct* req_info, vm_phb_contact_pos_struct* pos_array, VMINT post_array_len)
{
 	
	VMINT search_num = 0;

	if(req_info == NULL ||pos_array ==NULL||post_array_len<0)
	{
		vm_log_error("vm_phb_search_contact_list:req_info == NULL");
		return VM_PHB_REQ_ERROR;
	}
	 
	vm_log_debug("req_info->search_type=%d",req_info->search_type);
	search_num = vm_sal_phb_search_contact_list(req_info, pos_array, post_array_len); 
		 
	vm_log_debug("vm_phb_search_contact_list:search_num= %d",search_num);
	
	return search_num;
      
   }


VMINT vm_phb_get_group_list_count(void)
{

	VMINT group_count = 0;
		 
	group_count = vm_sal_phb_get_group_list_count(); 
 
	vm_log_debug("vm_phb_get_group_list_count:group_count = %d", group_count);
		
	return group_count;
       
		 
}

VMINT vm_phb_get_group_list(vm_phb_group_struct* group_array, VMINT  group_array_len)
{
   
	VMINT len = 0;
       	
	len = vm_sal_phb_get_group_list(group_array, group_array_len);
	  
       vm_log_debug("vm_phb_get_group_list:len = %d", len);
	   
       return len;
    

}


VMINT vm_phb_get_group_name_by_id(VMUINT group_id, VMWCHAR*  group_name, VMINT len)
{
    
	VMINT res = FALSE;
  	
	if(group_name==NULL || len <= 0)
       {
		vm_log_error("vm_phb_get_group_name_by_id:group_name==NULL || len <= 0");
		return FALSE;	
	}
	  
      res = vm_sal_phb_get_group_name_by_id(group_id, group_name, len);

      vm_log_debug("vm_phb_get_group_name_by_id:res= %d", res);
	  
      return res;
  

}



static VMINT vm_phb_storage_is_valid(vm_phb_storage_loc_enum storage)
{

	if(storage < VM_PHB_STORAGE_LOC_SIM ||storage >VM_PHB_STORAGE_LOC_BOTH)
	{
		vm_log_error("vm_phb_storage_is_valid:storage is not valid");
		return VM_PHB_REQ_ERROR;
	}
	 
	//#if (defined(VRE_DUAL_SIM))
	 if (sysconf.dual_sim_master == MMI_TRUE)
	 {

		if(storage == VM_PHB_STORAGE_LOC_SIM)
		{
			if(vm_is_card1Absent()!=0)
			{
				vm_log_error("vm_phb_storage_is_valid:vm_is_card1Absent ");
				return VM_PHB_REQ_ERROR;
			}
		}
		else if(storage == VM_PHB_STORAGE_LOC_SIM2)
		{
			if(vm_is_card2Absent()!=0)
			{
				vm_log_error("vm_phb_storage_is_valid:vm_is_card2Absent");
				return VM_PHB_REQ_ERROR;
			}
		}
	 }
	//#else
	else
	{
 
		if(storage == VM_PHB_STORAGE_LOC_SIM)
		{
			if(vm_has_sim_card()==FALSE)
			{
				vm_log_error("vm_phb_storage_is_valid:vm_has_sim_card fail");
				return VM_PHB_REQ_ERROR;
			}
		}
		else if(storage == VM_PHB_STORAGE_LOC_SIM2)
		{
			vm_log_error("vm_phb_storage_is_valid:storage ==VM_PHB_STORAGE_LOC_SIM2 error");
			return VM_PHB_REQ_ERROR;
		}
	 
	//#endif
	}
   

	return VM_PHB_REQ_NO_ERROR;

}


#endif

#endif
