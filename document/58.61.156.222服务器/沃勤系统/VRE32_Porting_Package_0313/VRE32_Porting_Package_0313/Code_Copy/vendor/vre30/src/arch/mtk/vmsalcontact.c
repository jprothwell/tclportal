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
#include "vmsalcontact.h"
#include "vmmacrostub.h"

/*
  * 应用程序短消息回调函数。
  */

//vm_phb_callback_type _user_phb_callback = NULL;

/* ------------------------------------------------------------------------ */
/* 系统全局变量声明。                                                       */
/* ------------------------------------------------------------------------ */

srv_phb_sdk_contact_struct vm_contact_ptr;

/* ------------------------------------------------------------------------ */
/* 系统函数声明。                                                           */
/* ------------------------------------------------------------------------ */

extern void vm_phb_callback_manager(S32 result, srv_phb_sdk_contact_struct* contact_ptr);
//extern void  vm_phb_build_contact_ptr(vm_phb_contact_struct* contact, srv_phb_sdk_contact_struct * contact_ptr);	
//extern void  vm_phb_build_contact(srv_phb_sdk_contact_struct * contact ,  vm_phb_contact_struct* contact_ptr);	
/* ------------------------------------------------------------------------ */
/* 模块内部变量声明。                                                       */
/* ------------------------------------------------------------------------ */


/* ------------------------------------------------------------------------ */
/* 模块内部函数声明。                                                       */
/* ------------------------------------------------------------------------ */

static void  vm_phb_build_contact_pos(srv_phb_sdk_get_req_struct * req ,  vm_phb_get_req_struct* req_info);

/* ------------------------------------------------------------------------ */
/* 函数定义                                                    */
/* ------------------------------------------------------------------------ */


vm_phb_req_error_enum vm_sal_phb_add_contact(vm_phb_add_req_struct* req_info,  vm_phb_callback_type cb)
{
       srv_phb_sdk_add_req_struct  req;
   	 
      	 vm_log_debug("vm_sal_phb_add_contact:start");	
       if(!srv_phb_sdk_is_phb_ready())
      {
      	   vm_log_error("vm_sal_phb_add_contact:srv_phb_sdk_is_phb_not_ready");
	   return VM_PHB_REQ_NOT_READY;
      }
	
	memset(&req, 0, sizeof(req));
	memset(&vm_contact_ptr, 0, sizeof(srv_phb_sdk_contact_struct));
	
	req.contact_ptr= &vm_contact_ptr;
	req.storage = req_info->storage;
	
	vm_phb_build_contact(&vm_contact_ptr, req_info->contact_ptr);
	vm_log_debug("sizeof(srv_phb_sdk_contact_struct)=%d", sizeof(srv_phb_sdk_contact_struct));/*124*/
	
	srv_phb_sdk_add_contact(&req, vm_phb_callback_manager);
	      
       return VM_PHB_REQ_NO_ERROR;
	   
}


vm_phb_req_error_enum vm_sal_phb_delete_contact(vm_phb_delete_req_struct* req_info,   vm_phb_callback_type cb)
{
      srv_phb_sdk_delete_req_struct  req;

      if(!srv_phb_sdk_is_phb_ready())
      {
      	   vm_log_error("vm_sal_phb_delete_contact:srv_phb_sdk_is_phb_not_ready");
	   return VM_PHB_REQ_NOT_READY;
      }
	vm_log_debug("vm_sal_phb_delete_contact:delete");	   
      memset(&req, 0, sizeof(req));	  	
      req.pos.index = req_info->pos.index;
      req.pos.storage = req_info->pos.storage;

   
     srv_phb_sdk_delete_contact(&req,  vm_phb_callback_manager);

     return VM_PHB_REQ_NO_ERROR;

}

vm_phb_req_error_enum vm_sal_phb_update_contact(vm_phb_update_req_struct* req_info,  vm_phb_callback_type cb)
{
       srv_phb_sdk_update_req_struct   req;
	   
       if(!srv_phb_sdk_is_phb_ready())
       {
      	   vm_log_error("vm_sal_phb_update_contact:srv_phb_sdk_is_phb_not_ready");
	   return VM_PHB_REQ_NOT_READY;
       }
	memset(&req, 0, sizeof(req));	
	memset(&vm_contact_ptr, 0, sizeof(srv_phb_sdk_contact_struct));
	
	req.contact_ptr = &vm_contact_ptr;
	req.pos.index = req_info->pos.index;
	req.pos.storage = req_info->pos.storage;
	
	vm_phb_build_contact(&vm_contact_ptr, req_info->contact_ptr);
	
       srv_phb_sdk_update_contact(&req,  vm_phb_callback_manager);

       return VM_PHB_REQ_NO_ERROR;

}


vm_phb_req_error_enum vm_sal_phb_search_contact(vm_phb_search_req_struct* req_info,   vm_phb_callback_type cb)
{
	srv_phb_sdk_search_req_struct  req;
	VMINT result = -1;
	
	if(!srv_phb_sdk_is_phb_ready())
	{
		vm_log_error("vm_sal_phb_search_contact:srv_phb_sdk_is_phb_not_ready");
		return VM_PHB_REQ_NOT_READY;
	}
	vm_log_debug("vm_sal_phb_search_contact: start"); 
	memset(&req, 0, sizeof(req));	  
	memset(&vm_contact_ptr, 0, sizeof(srv_phb_sdk_contact_struct));
	  
	req.contact_ptr = &vm_contact_ptr;

	vm_wstrncpy((VMWSTR)req.pattern_ucs2, req_info->pattern_ucs2,  SRV_PHB_SEARCH_LENGTH-1);
	req.search_type = req_info->search_type;
     	  
	vm_log_debug("vm_sal_phb_search_contact: req.search_type=%d,req.pattern_ucs2=%s", req.search_type, vm_gb2312_string((VMWSTR)req.pattern_ucs2));
	result = srv_phb_sdk_search_contact(&req);
	vm_phb_callback_manager(result, req.contact_ptr);
	vm_log_debug("vm_sal_phb_search_contact:srv_phb_sdk_search_contact end");
	 
	return VM_PHB_REQ_NO_ERROR;

}


vm_phb_req_error_enum vm_sal_phb_get_contact(vm_phb_get_req_struct* req_info,    vm_phb_callback_type cb)
{
       srv_phb_sdk_get_req_struct  req;
	VMINT result = -1;
	   
	if(!srv_phb_sdk_is_phb_ready())
      	{
      	   vm_log_error("vm_sal_phb_get_contact:srv_phb_sdk_is_phb_not_ready");
	   return VM_PHB_REQ_NOT_READY;
      	}
       memset(&req, 0, sizeof(req));	
	memset(&vm_contact_ptr, 0, sizeof(srv_phb_sdk_contact_struct));
	
	req.contact_ptr = &vm_contact_ptr;

	/*req.pos.index = req_info->pos.index;
	req.pos.storage = req_info->pos.storage;
	vm_contact_ptr.pos.index =  req_info->pos.index;
	vm_contact_ptr.pos.storage =  req_info->pos.storage;
	*/ /*vm_phb_build_contact_pos instead of this*/
	
	vm_phb_build_contact_pos(&req ,  req_info);
	  
	vm_log_debug("vm_sal_phb_get_contact:srv_phb_sdk_get_contact start");
	result  = srv_phb_sdk_get_contact(&req);
	vm_phb_callback_manager(result, req.contact_ptr);
	vm_log_debug("vm_sal_phb_get_contact:srv_phb_sdk_get_contact end");

      return VM_PHB_REQ_NO_ERROR;

}



vm_phb_req_error_enum vm_sal_phb_search_contact_syn(vm_phb_search_req_struct* req_info)
{
	srv_phb_sdk_search_req_struct  req;
	srv_phb_sdk_contact_struct * contact = NULL;
	VMINT result = -1;
	VMINT res = VM_PHB_REQ_ERROR;

	vm_log_debug("vm_sal_phb_search_contact_syn: start"); 
	if(!srv_phb_sdk_is_phb_ready())
	{
		vm_log_error("vm_sal_phb_search_contact_syn:srv_phb_sdk_is_phb_not_ready");
		return VM_PHB_REQ_NOT_READY;
	}
	
	contact = vm_calloc(sizeof(srv_phb_sdk_contact_struct));
	if(contact == NULL)
	{
		vm_log_error("vm_sal_phb_search_contact_syn:contact == NULL");
		return VM_PHB_REQ_ERROR;	
	}

      memset(&req, 0, sizeof(req));	  
	  
      req.contact_ptr = contact;

      vm_wstrncpy((VMWSTR)req.pattern_ucs2, req_info->pattern_ucs2,  SRV_PHB_SEARCH_LENGTH-1);
      req.search_type = req_info->search_type;
     	  
      vm_log_debug("vm_sal_phb_search_contact_syn: req.search_type=%d,req.pattern_ucs2=%s", req.search_type, vm_gb2312_string((VMWSTR)req.pattern_ucs2));
      result = srv_phb_sdk_search_contact(&req);
	if(result == SRV_PHB_NO_ERROR)  
	{
		vm_phb_build_contact_ptr(req_info->contact_ptr, req.contact_ptr);
		res = VM_PHB_REQ_NO_ERROR;
	}
    
	vm_free(contact);
	vm_log_debug("vm_sal_phb_search_contact_syn:srv_phb_sdk_search_contact end");
	 
	return res;

}

vm_phb_req_error_enum vm_sal_phb_get_contact_syn(vm_phb_get_req_struct* req_info)
{
       srv_phb_sdk_get_req_struct  req;
	srv_phb_sdk_contact_struct * contact = NULL;
	VMINT result = -1;
	VMINT res = VM_PHB_REQ_ERROR;
		
      if(!srv_phb_sdk_is_phb_ready())
      	{
      	   vm_log_error("vm_sal_phb_get_contact_syn:srv_phb_sdk_is_phb_not_ready");
	   return VM_PHB_REQ_NOT_READY;
      	}
   
       contact = vm_calloc(sizeof(srv_phb_sdk_contact_struct));
	if(contact == NULL)
	{
          vm_log_error("vm_sal_phb_get_contact_syn:contact == NULL");
	   return VM_PHB_REQ_ERROR;	
	}
	
       memset(&req, 0, sizeof(req));	
		
	req.contact_ptr = contact;
	/*
	req.pos.index = req_info->pos.index;
	req.pos.storage = req_info->pos.storage;
	contact->pos.index =  req_info->pos.index;
	contact->pos.storage =  req_info->pos.storage;
	*/
	vm_phb_build_contact_pos(&req ,  req_info);
	  
       result = srv_phb_sdk_get_contact(&req);
	 if(result == SRV_PHB_NO_ERROR)  
	 {
     		 vm_phb_build_contact_ptr(req_info->contact_ptr, req.contact_ptr);
		 res = VM_PHB_REQ_NO_ERROR;
	 }
    	       
       vm_log_debug("vm_sal_phb_get_contact_syn:vm_get_tick_count2()=%d",vm_get_tick_count()); 	
       vm_free(contact);
	vm_log_debug("vm_sal_phb_get_contact_syn:end");  
	
       return res;

}



VMINT vm_sal_phb_get_total_contacts(vm_phb_storage_loc_enum storage)
{
      VMINT total_nums = 0;
      phb_storage_enum  storage_loc;
	    
       if(!srv_phb_sdk_is_phb_ready())
      {
          vm_log_error("vm_sal_phb_get_total_contacts:srv_phb_sdk_is_phb_not_ready");
	   return VM_PHB_REQ_NOT_READY;
      }
	storage_loc = storage;
   
      total_nums = srv_phb_sdk_get_total_contacts(storage_loc);

      return total_nums;
  
}

VMINT vm_sal_phb_get_used_contacts_count(vm_phb_storage_loc_enum storage)
{
      VMINT used_nums;
      phb_storage_enum  storage_loc;
     
     	      
      if(!srv_phb_sdk_is_phb_ready())
      {
          vm_log_error("vm_sal_phb_get_used_contacts_count:srv_phb_sdk_is_phb_not_ready");
	   return VM_PHB_REQ_NOT_READY;
      }
	     
      storage_loc = storage;
      used_nums = srv_phb_sdk_get_used_contacts(NULL, storage_loc);
	  
      if(used_nums <0)  
      {
            vm_log_error("vm_sal_phb_get_used_contacts_count:used_nums <0");
	     return VM_PHB_REQ_ERROR;
      }
	  
      return used_nums;


}


VMINT vm_sal_phb_get_used_contacts(vm_phb_contact_pos_struct* pos_array,  vm_phb_storage_loc_enum storage)
{
      VMINT used_nums = 0;
      phb_storage_enum  storage_loc;
      srv_phb_contact_pos_struct  *contact_array = NULL;
      int i=0;
      VMINT nums = 0;
     	 
      if(!srv_phb_sdk_is_phb_ready())
      {
          vm_log_error("vm_sal_phb_get_used_contacts:srv_phb_sdk_is_phb_not_ready");
	   return VM_PHB_REQ_NOT_READY;
      }
    
      storage_loc = storage;
      used_nums = srv_phb_sdk_get_used_contacts(contact_array, storage_loc);
	  
      if(used_nums < 0)  
      {
            vm_log_error("vm_sal_phb_get_used_contacts:used_nums < 0");
	     return VM_PHB_REQ_ERROR;
      }
	  
      if(pos_array == NULL)
      {
           vm_log_error("vm_sal_phb_get_used_contacts:pos_array == NULL");
	    return used_nums;
      } 
	
      if(used_nums == 0)  
	      return used_nums;
    
      contact_array = vm_calloc(sizeof(srv_phb_contact_pos_struct)*used_nums);
      if(contact_array == NULL)
      {
          vm_log_error("vm_sal_phb_get_used_contacts:contact_array == NULL");
	   return VM_PHB_REQ_ERROR;	
      }
   	   	
     storage_loc = storage;
     nums = srv_phb_sdk_get_used_contacts(contact_array, storage_loc);
     if(nums > 0)
     {
         for(i=0; i < used_nums; i++ )
         {
             pos_array[i].index =contact_array[i].index;
	      pos_array[i].storage=contact_array[i].storage;
         }
     
     }
     vm_free(contact_array);
     return used_nums;

}


VMINT vm_sal_phb_search_contact_list(vm_phb_search_list_req_struct* req_info, vm_phb_contact_pos_struct* pos_array, VMINT post_array_len)
{
	srv_phb_contact_pos_struct  *contact_array = NULL;
	srv_phb_sdk_get_req_struct  req;
	srv_phb_sdk_contact_struct * contact = NULL;
	VMINT used_nums = 0;
	VMINT res = 0;
	VMINT j = 0;
	VMINT i = 0;

	if(!srv_phb_sdk_is_phb_ready())
	{
		vm_log_error("vm_sal_phb_search_contact_list:srv_phb_sdk_is_phb_not_ready");
		return VM_PHB_REQ_NOT_READY;
	}

      used_nums = srv_phb_sdk_get_used_contacts(contact_array, VM_PHB_STORAGE_LOC_BOTH);
	   
      if(used_nums < 0)  
      	{
      	      vm_log_error("vm_sal_phb_search_contact_list:used_nums < 0");
	      return VM_PHB_REQ_ERROR;
      	}
	
	if(used_nums == 0)  
		return used_nums;
	
      contact_array = vm_calloc(sizeof(srv_phb_contact_pos_struct)*used_nums);
	
      if(contact_array == NULL)
      {
          vm_log_error("vm_sal_phb_search_contact_list:contact_array == NULL");
	   return VM_PHB_REQ_ERROR;	
      }
  
	used_nums = srv_phb_sdk_get_used_contacts(contact_array, VM_PHB_STORAGE_LOC_BOTH);
	
	vm_log_debug("vm_sal_phb_search_contact_list:used_nums=%d", used_nums);

	contact = vm_calloc(sizeof(srv_phb_sdk_contact_struct));
	if(contact == NULL)
	{
		vm_free(contact_array);
		vm_log_error("vm_sal_phb_search_contact_list:contact == NULL");
		return VM_PHB_REQ_ERROR;	
      }
	
       for(i=0; i< used_nums; i++)
       {
       	memset(&req, 0, sizeof(srv_phb_sdk_get_req_struct));
		memset(contact, 0, sizeof(srv_phb_sdk_contact_struct));
		req.contact_ptr = contact;
		req.pos.index= contact_array[i].index;
		req.pos.storage= contact_array[i].storage;	  
		contact->pos.index = contact_array[i].index;
		contact->pos.storage = contact_array[i].storage;	  
		  
		vm_log_debug("vm_sal_phb_search_contact_list  contact_array[%d].index=%d",  i, contact_array[i].index);
		vm_log_debug("vm_sal_phb_search_contact_list  contact_array[%d].storage=%d", i, contact_array[i].storage);
		res = srv_phb_sdk_get_contact(&req);
		if(res == SRV_PHB_NO_ERROR)
		{
			if(contact != NULL )
			{
				vm_log_debug("vm_sal_phb_search_contact_list:search_req->search_type=%d",req_info->search_type);
			
				if(req_info->search_type == VM_PHB_SEARCH_TYPE_NAME)
				{
					vm_log_debug("vm_sal_phb_search_contact_list:search_req->pattern_ucs2=%s",vm_gb2312_string(req_info->pattern_ucs2));
					vm_log_debug("vm_sal_phb_search_contact_list:contact_ptr->name=%s",vm_gb2312_string((VMWSTR)contact->name));
					if(vm_wstrcmp((VMWSTR)req_info->pattern_ucs2, (VMWSTR)&contact->name) == 0)
					{
						pos_array[j].index = 	contact->pos.index;
						pos_array[j].storage = contact->pos.storage;
						j++;
						
					}
				}  
		   		else if(req_info->search_type == VM_PHB_SEARCH_TYPE_NUM)
				{
					vm_log_debug("vm_sal_phb_search_contact_list:search_req->pattern_ucs2=%s",vm_gb2312_string(req_info->pattern_ucs2));
					vm_log_debug("vm_sal_phb_search_contact_list:contact_ptr->number=%s",vm_gb2312_string((VMWSTR)contact->number));
					if(vm_wstrcmp((VMWSTR)req_info->pattern_ucs2, (VMWSTR)&contact->number) == 0)
					{
						pos_array[j].index = 	contact->pos.index;
						pos_array[j].storage = contact->pos.storage;
						j++;
					}
				} 
				else
				{
					vm_log_error("vm_sal_phb_search_contact_list: req_info->search_type =%d",req_info->search_type);
				}
			}
			
			if(j == post_array_len)
			{
				break;
			}
		}
		
       }
	   
	vm_free(contact_array);
	vm_free(contact);

	return j;     
	 
}


VMINT vm_sal_phb_get_group_list_count(void)
{

         VMINT group_count = 0;
	   
         group_count =(VMINT)srv_phb_datamgr_get_group_list(NULL, NULL); 
		 
         return group_count;
     
}


VMINT vm_sal_phb_get_group_list(vm_phb_group_struct* group_array, VMINT  group_array_len)
{
	VMINT group_count = 0;
	VMINT len = 0;	   
	VMUINT8 *  group_id_array = NULL;
	VMUINT16*  group_name_array = NULL;
	VMINT i = 0;	   
	
	group_count =(VMINT)srv_phb_datamgr_get_group_list(NULL, NULL); 

   
	if(group_array==NULL || group_array_len <= 0)
		return  group_count;
   
	if(group_count <= 0)
	{
		vm_log_debug("vm_sal_phb_get_group_list: group_count <= 0");
		return  group_count;
	}
   
	len = group_count;
	if(group_array_len < group_count)
		len = group_array_len;

	group_id_array= (VMUINT8 *)vm_calloc(sizeof(VMUINT8) * group_count);
	group_name_array =(VMUINT16* )vm_calloc(sizeof(VMUINT16) *( VM_MAX_PHB_GROUP_NAME_LENGTH+1)*group_count);
	srv_phb_datamgr_get_group_list(group_id_array, group_name_array); 
	for(i=0; i< len; i++)
	{
		group_array[i].group_id = group_id_array[i];
		vm_wstrncpy(group_array[i].group_name, (VMWSTR)(group_name_array +i * (VM_MAX_PHB_GROUP_NAME_LENGTH + 1)), VM_MAX_PHB_GROUP_NAME_LENGTH);
		vm_log_debug("group_array[i].group_id =%d", group_array[i].group_id);
		vm_log_debug("group_array[i].group_name=%s", vm_gb2312_string(group_array[i].group_name));
	    
	}
	if(group_id_array)
		vm_free(group_id_array);
	
	if(group_name_array)
		vm_free(group_name_array);	
	   
	return len;

}


VMINT vm_sal_phb_get_group_name_by_id(VMUINT group_id, VMWCHAR*  group_name, VMINT len)
{

     VMINT group_count = 0;
     VMUINT8 *  group_id_array = NULL;
     VMUINT16*  group_name_array = NULL;
     VMINT i = 0;	   
     VMINT temp_len= 0;
     VMINT res = FALSE;
	 
    group_count =(VMINT)srv_phb_datamgr_get_group_list(NULL, NULL); 
    if(group_count <= 0)
   {
           vm_log_debug("vm_sal_phb_get_group_name_by_id: group_count <= 0");
   	    return  FALSE;
   }
	
    group_id_array=(VMUINT8 *)vm_calloc(sizeof(VMUINT8) * group_count);
    group_name_array =(VMUINT16* ) vm_calloc(sizeof(VMUINT16) *( VM_MAX_PHB_GROUP_NAME_LENGTH+1)*group_count);
    srv_phb_datamgr_get_group_list(group_id_array, group_name_array); 
    for(i=0; i< group_count; i++)
    {
            if(group_id_array[i] == group_id)
            	{
            	         temp_len =  VM_MAX_PHB_GROUP_NAME_LENGTH+1;
            	         if(len < temp_len)
				   temp_len = 	len;
	              vm_wstrncpy(group_name, (VMWSTR)(group_name_array +i * (VM_MAX_PHB_GROUP_NAME_LENGTH + 1)), temp_len);	
			  
		      vm_log_debug("group_name=%s ,group_id=%d",  vm_gb2312_string(group_name), group_id);
	            	res = TRUE;	
		      break;
            	}
    }  
    if(group_id_array)
		vm_free(group_id_array);
	
    if(group_name_array)
		vm_free(group_name_array);	
	
   return res;

}

static void  vm_phb_build_contact_pos(srv_phb_sdk_get_req_struct * req ,  vm_phb_get_req_struct* req_info)
{
	req->pos.index =  req_info->pos.index;
	req->pos.storage = req_info->pos.storage;
	req->contact_ptr->pos.index = req_info->pos.index;
	req->contact_ptr->pos.storage = req_info->pos.storage;
}

#endif

#endif
