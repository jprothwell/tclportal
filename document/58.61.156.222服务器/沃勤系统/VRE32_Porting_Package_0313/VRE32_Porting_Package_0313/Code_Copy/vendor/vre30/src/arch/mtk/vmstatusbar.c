#ifdef __VRE__


#include "gpioInc.h"
#include "mdi_audio.h"
#include "UCMGprot.h" 
#include "custom_mmi_default_value.h"

#include "vmresmng.h"
#include "vmdl.h"
#include "vmmod.h"
#include "vmmem.h"
#include "vmlog.h"
#include "vmchset.h"
#include "vmstdlib.h"

#include "vmstatusbar.h"
#include "Commonscreensresdef.h"
#include "AMresdef.h"
#include "vredef.h"
#include "vmcert.h"
#include "vmgettag.h"
#include "gui_typedef.h"

#include "todolistresdef.h"

#include "StatusIconRes.h"
#include "vmres.h"


typedef struct
{
	VMINT icon_id;
	VMINT is_used;
}vm_statusbar_icon_t;

static vm_statusbar_icon_t g_icon_table[] = {
		{STATUS_ICON_VRE_1, FALSE},
		{STATUS_ICON_VRE_2, FALSE},
		{STATUS_ICON_VRE_3, FALSE},
		{STATUS_ICON_VRE_4, FALSE}
};

/**
 * 有独立STATUS ICONID 链头指针。
 */
static vm_status_bar_image_t* statusbar_image_queue = NULL;

/*
* 默认STATUS ICONID 链头指针。	
*/
static vm_status_bar_image_t* statusbar_default_image_queue = NULL;


/**
 * 提示时候的MIDI音乐。
 */
const __align(2) static VMUINT8 vm_notify_midi_data[] = 
{
0x4D, 0x54, 0x68, 0x64, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x01, 0x01, 0xE0, 0x4D, 0x54, 
0x72, 0x6B, 0x00, 0x00, 0x00, 0x98, 0x00, 0xFF, 0x51, 0x03, 0x05, 0x16, 0x15, 0x00, 0xFF, 0x58, 
0x04, 0x04, 0x02, 0x18, 0x08, 0x00, 0xF0, 0x07, 0x7F, 0x7F, 0x04, 0x01, 0x00, 0x7F, 0xF7, 0x01, 
0xB0, 0x00, 0x00, 0x01, 0xB0, 0x20, 0x00, 0x01, 0xC0, 0x0B, 0x01, 0xB0, 0x07, 0x7F, 0x02, 0x90, 
0x3D, 0x61, 0x00, 0x90, 0x36, 0x3F, 0x3C, 0x90, 0x36, 0x00, 0x00, 0x90, 0x3D, 0x00, 0x00, 0x90, 
0x42, 0x68, 0x00, 0x90, 0x3B, 0x46, 0x3C, 0x90, 0x3B, 0x00, 0x00, 0x90, 0x42, 0x00, 0x00, 0x90, 
0x49, 0x70, 0x00, 0x90, 0x42, 0x4E, 0x3C, 0x90, 0x42, 0x00, 0x00, 0x90, 0x49, 0x00, 0x00, 0x90, 
0x4E, 0x78, 0x00, 0x90, 0x47, 0x56, 0x3C, 0x90, 0x47, 0x00, 0x00, 0x90, 0x4E, 0x00, 0x00, 0x90, 
0x55, 0x7F, 0x00, 0x90, 0x4E, 0x5D, 0x3C, 0x90, 0x4E, 0x00, 0x00, 0x90, 0x55, 0x00, 0x85, 0x0E, 
0x90, 0x24, 0x15, 0x78, 0x90, 0x24, 0x00, 0x86, 0x48, 0xFF, 0x07, 0x05, 0x53, 0x54, 0x41, 0x52, 
0x54, 0x83, 0x60, 0xFF, 0x07, 0x04, 0x53, 0x54, 0x4F, 0x50, 0x00, 0xFF, 0x2F, 0x00
};

extern VMINT vm_check_if_appcalling(void);
extern MMI_ALERT_TYPE GetMtCallAlertTypeEnum(void);
extern U16 mmi_am_get_status_bar_icon_resid(U16 *app_name);
static VMWCHAR* vm_get_fullfilename_by_iconid(VMINT icon_id);
static vm_status_bar_image_t* vm_get_defaulticons_statusbar(void);
static  VMWCHAR* vm_get_fullfilename_by_queue_iconid(vm_status_bar_image_t *image_queue,VMINT icon_id);
static VMINT vm_pmng_apply_to_action_in_fg(VM_P_HANDLE pHandle,VM_FG_ICONSTATUS_TYPE status,VMINT notify_type);
static VMINT vm_statusbar_get_iconid_by_phandle(VM_P_HANDLE pHandle);
static VMINT vm_statusbar_get_iconstatus_by_phandle(VM_P_HANDLE pHandle);
static vm_status_bar_image_t* vm_statusbar_get_status_bar_image_byhandle(VM_P_HANDLE pHandle);
static vm_status_bar_image_t* vm_statusbar_get_status_bar_image(vm_status_bar_image_t *image_queue,VM_P_HANDLE pHandle);
static  void vm_statusbar_freenode_of_queue(vm_status_bar_image_t **image_queue,VM_P_HANDLE pHandle);
static void vm_statusbar_freenode(VM_P_HANDLE pHandle);
static void vm_statusbar_free_state_image_table(vm_statusbar_state_image_map_t* p_state_image_table);
static void vm_statusbar_free_image(vm_status_bar_image_t* p_image);
static void vm_status_bar_hide_icon(VMINT icon_id);
static void vm_status_bar_show_icon(VMINT icon_id);
static void vm_status_bar_blink_icon(VMINT icon_id);
static void vm_status_bar_update_icon(void);
static VMINT vm_statusbar_getIconImageId(VMINT icon_id);
static VMINT vm_statusbar_is_iconid_used(VMINT icon_id);
static void vm_statusbar_set_iconid_used(VMINT icon_id, VMINT is_used);
static void vm_statusbar_set_iconid_all_used(VMINT is_used);
static VMINT vm_statusbar_get_unused_iconid(void);
//static VMINT vm_statusbar_get_suitable_iconid(U16* app_name);
static VMINT vm_status_bar_change_icon_image(vm_status_bar_image_t* p_image);



static vm_status_bar_image_t* vm_get_statusbar_byiconid(vm_status_bar_image_t *image_queue,VMINT icon_id)
{
	vm_status_bar_image_t *tmp=image_queue;
		
	while (tmp != NULL)
		{
			if (tmp->icon_id== icon_id)
			{
				return tmp;
			}
			tmp = tmp->next;
		}	
	return NULL;
}
 
static  VMWCHAR* vm_get_fullfilename_by_queue_iconid(vm_status_bar_image_t *image_queue,VMINT icon_id)
{
	vm_status_bar_image_t *tmp=vm_get_statusbar_byiconid(image_queue, icon_id);

	//vm_log_debug("...vm_get_fullfilename_by_queue_iconid...");
	if (tmp)
	{
		
		return tmp->fullFilename;
	}
	else
	{	vm_log_error("...vm_get_fullfilename_by_queue_iconid... tmp is NULL");	}
	
	return NULL;
	
}

static VMWCHAR* vm_get_fullfilename_by_iconid(VMINT icon_id)
{
	//vm_log_debug("...vm_get_fullfilename_by_iconid... icon_id:%d",icon_id);
	return vm_get_fullfilename_by_queue_iconid(statusbar_image_queue, icon_id);
}

	
static vm_status_bar_image_t* vm_get_defaulticons_statusbar(void)
{
	return statusbar_default_image_queue;
	
}



static VMINT vm_statusbar_get_iconid_by_phandle(VM_P_HANDLE pHandle)
{
	vm_status_bar_image_t *image=NULL;
	image=vm_statusbar_get_status_bar_image_byhandle(pHandle);
	if (image)
		return image->icon_id;
	return 0;
}

static VMINT vm_statusbar_get_iconstatus_by_phandle(VM_P_HANDLE pHandle)
{
	vm_status_bar_image_t *image=NULL;
	image=vm_statusbar_get_status_bar_image_byhandle(pHandle);
	if (image)
		return image->image_status;
	return 0;
}

static vm_status_bar_image_t* vm_statusbar_get_status_bar_image_byhandle(VM_P_HANDLE pHandle)
{
	vm_status_bar_image_t *tmp=NULL;

	if ((tmp=vm_statusbar_get_status_bar_image(statusbar_image_queue,pHandle))==NULL)
		tmp=vm_statusbar_get_status_bar_image(statusbar_default_image_queue,pHandle);
	
	return tmp;
}


static vm_status_bar_image_t* vm_statusbar_get_status_bar_image(vm_status_bar_image_t *image_queue,VM_P_HANDLE pHandle)
{
	vm_status_bar_image_t *tmp=image_queue;
		
	while (tmp != NULL)
		{
			if (tmp->pHandle == pHandle)
			{
				return tmp;
			}
			tmp = tmp->next;
		}	
	return NULL;
}


static void vm_statusbar_freenode(VM_P_HANDLE pHandle)
{
	vm_statusbar_freenode_of_queue(&statusbar_image_queue,pHandle);
	vm_statusbar_freenode_of_queue(&statusbar_default_image_queue,pHandle);
}

static void vm_statusbar_free_state_image_table(vm_statusbar_state_image_map_t* p_state_image_table)
{
	vm_statusbar_state_image_map_t* cur = p_state_image_table;
	vm_statusbar_state_image_map_t* tmp = NULL;
	while(cur)
	{
		tmp = cur;
		cur = cur->next;
		vm_free(tmp->p_image_data);
		tmp->p_image_data = NULL;
		vm_free(tmp);
	}
}

static void vm_statusbar_free_image(vm_status_bar_image_t* p_image)
{
	//if (VM_ICON_APP_STATE_SPECIAL != p_image->app_state)/*State has been changed by application*/
	//{
		/****Restore origin image****/
		ChangeStatusIconImage(p_image->icon_id, IMG_SI_VRE_DEFAULT);
	//}
	/*************Set iconid unused**************/
	vm_statusbar_set_iconid_used(p_image->icon_id, FALSE);
	/*************释放状态图标表******/
	vm_statusbar_free_state_image_table(p_image->p_state_image_table);
	
	vm_free(p_image);
	p_image = NULL;
}

static  void vm_statusbar_freenode_of_queue(vm_status_bar_image_t **image_queue,VM_P_HANDLE pHandle)
{
	vm_status_bar_image_t *tmp = *image_queue, *tmp2 = *image_queue;
	while (tmp != NULL)
	{
		tmp2 = tmp->next;
		if ((tmp->pHandle == pHandle) && (*image_queue == tmp))//头结点
		{
			*image_queue = tmp->next;
			vm_statusbar_free_image(tmp);
			return;
		} 
		else if ( tmp2 && (tmp2->pHandle == pHandle))//其他结点
		{
			tmp->next=tmp2->next;
			vm_statusbar_free_image(tmp2);
			return;
		}
		
		tmp = tmp2;
	}
}

static void vm_status_bar_hide_icon(VMINT icon_id)
{
	vm_log_debug("[STATUS BAR]hide_icon %d....", icon_id);
	HideStatusIcon(icon_id);	
}
static void vm_status_bar_show_icon(VMINT icon_id)
{
	vm_log_debug("[STATUS BAR]show_icon = %d....", icon_id);
	ShowStatusIcon(icon_id);
}

static void vm_status_bar_blink_icon(VMINT icon_id)
{
	vm_log_debug("[STATUS BAR]blink_icon %d....", icon_id);
	BlinkStatusIcon(icon_id);
}

static void vm_status_bar_update_icon(void)
{
	UpdateStatusIcons();
}

static VMINT vm_statusbar_getIconImageId(VMINT icon_id)
{
	return GetIconImageId(icon_id); 
}

static VMINT vm_statusbar_is_iconid_used(VMINT icon_id)
{
	VMINT is_used = TRUE;
	switch (icon_id)
	{
		case STATUS_ICON_VRE_1:
			is_used = g_icon_table[0].is_used;
			break;
		case STATUS_ICON_VRE_2:
			is_used = g_icon_table[1].is_used;
			break;
		case STATUS_ICON_VRE_3:
			is_used = g_icon_table[2].is_used;
			break;
		case STATUS_ICON_VRE_4:
			is_used = g_icon_table[3].is_used;
			break;
		default:
			break;
	}
	return is_used;
}

static void vm_statusbar_set_iconid_used(VMINT icon_id, VMINT is_used)
{
	switch (icon_id)
	{
		case STATUS_ICON_VRE_1:
			g_icon_table[0].is_used = is_used;
			break;
		case STATUS_ICON_VRE_2:
			g_icon_table[1].is_used = is_used;
			break;
		case STATUS_ICON_VRE_3:
			g_icon_table[2].is_used = is_used;
			break;
		case STATUS_ICON_VRE_4:
		       g_icon_table[3].is_used = is_used;
			break;
		default:
			break;
	}
}

static void vm_statusbar_set_iconid_all_used(VMINT is_used)
{
	VMINT i = 0;
	for (; i < 4; i++)
	{
		g_icon_table[i].is_used = is_used;
	}
}

static VMINT vm_statusbar_get_unused_iconid(void)
{
	VMINT icon_id = STATUS_ICON_VRE_DEFAULT;
	VMINT i = 0;
	for (; i < 4; i++)
	{
		if (!g_icon_table[i].is_used)
			return g_icon_table[i].icon_id;
	}
	return icon_id;
}

/*static VMINT vm_statusbar_get_suitable_iconid(U16* app_name)
{
	VMINT is_used = TRUE;
	VMINT icon_id = STATUS_ICON_VRE_DEFAULT;
	
	icon_id = mmi_am_get_status_bar_icon_resid(app_name);	
	
	is_used = vm_statusbar_is_iconid_used(icon_id);
	
	if (is_used)
	{
		return vm_statusbar_get_unused_iconid();
	}
	else
	{
		return icon_id;
	}
	
}*/

static VMINT vm_status_bar_change_icon_image(vm_status_bar_image_t* p_image)
{
	vm_statusbar_state_image_map_t* table = p_image->p_state_image_table;
	
	while(table)
	{
		if (p_image->app_state == table->app_state)//find the image mapping with app_state
		{
			vm_log_debug("change_icon_image: find the mapping image");

			ChangeStatusIconImageData(p_image->icon_id, table->p_image_data);
			vm_status_bar_show_icon(p_image->icon_id);
			return TRUE;
		}
		table = table->next;
	}
	vm_log_warn("change_icon_image: can't find the mapping image");
	return FALSE;
}

static VMINT vm_statusbar_create_state_image_table(vm_status_bar_image_t* p_image)
{
	if (p_image == NULL)
	{
		p_image->p_state_image_table = NULL;
		vm_log_error("vm_statusbar_create_state_image_table: p_image = NULL!");
		return FALSE;
	}
	if (vm_pmng_state(p_image->pHandle) != VM_PMNG_BACKGROUND)
	{
		p_image->p_state_image_table = NULL;
		vm_log_error("vm_statusbar_create_state_image_table: application is not bg!");
		return FALSE;
	}
	else
	{
		/******加载建立当前应用状态图标表*******/
		VMINT res_size = 0;
		VMINT offset = 0;
		VMUINT8* p_res_buf = NULL;
		vm_statusbar_state_image_map_t* head = NULL;
		vm_statusbar_state_image_map_t* current = NULL;
		
		p_res_buf = vm_load_resource_from_file(p_image->fullFilename, "VOGINS_ICON_TABLE.VIT", &res_size);
		vm_log_debug("vm_statusbar_create_state_image_table: vm_load_resource_from_file, res_size = %d", res_size);
		if (p_res_buf == NULL)
		{
			p_image->p_state_image_table = NULL;
			vm_log_error("vm_statusbar_create_state_image_table: load vit file failed.");
			return FALSE;
		}

		while(offset + 8 < res_size)
		{
			vm_statusbar_state_image_map_t* node = NULL;
			node = vm_calloc(sizeof(vm_statusbar_state_image_map_t));
			if (node)
			{
				VMINT image_data_size = 0;
				image_data_size = (p_res_buf[offset + 5] << 16) + (p_res_buf[offset + 4] << 8) + p_res_buf[offset + 3];
				vm_log_debug("vm_statusbar_create_state_image_table: image data size = %d", image_data_size);
				node->app_state = (VMINT)p_res_buf[offset];
				
				node->p_image_data = vm_calloc(image_data_size + 8);
				if (node->p_image_data == NULL)
				{
					/**free state image table**/
					vm_statusbar_free_state_image_table(head);
					/**free resource**/
					vm_free(p_res_buf);
					p_image->p_state_image_table = NULL;
					
					vm_log_debug("vm_statusbar_create_state_image_table: vm_calloc failed");
					return FALSE;
				}
				memcpy(node->p_image_data, p_res_buf + offset + 1, image_data_size + 8);
				
				node->next = NULL;
				if (current == NULL)
					head = current = node;
				else
				{
					current->next = node;
					current = current->next;
				}
				offset += (9 + image_data_size);
				vm_log_debug("vm_statusbar_create_state_image_table: offset = %d", offset);
			}
		}

		/**free resource**/
		vm_free(p_res_buf);

		if (offset == res_size)
		{
			p_image->p_state_image_table = head;
			
			vm_log_debug("vm_statusbar_create_state_image_table: successfully");
			return TRUE;
		}
		else
		{
			/**free state image table**/
			vm_statusbar_free_state_image_table(head);
			p_image->p_state_image_table = NULL;
			
			vm_log_debug("vm_statusbar_create_state_image_table: failed");
			return FALSE;
		}

	}
}

VMINT vm_statusbar_set_app_state(VM_ICON_APP_STATE state)
{
	if (VM_ICON_APP_STATE_ONLINE <= state && state < VM_ICON_APP_STATE_NUM)
	{
		VM_P_HANDLE app_handle = 0;
		vm_status_bar_image_t* icon_image = NULL;
		
		vm_log_debug("vm_statusbar_set_app_state: valid state.");
		
		app_handle = vm_pmng_get_app_handle();
		if (app_handle == 0)
		{
			vm_log_error("vm_statusbar_set_app_state: handle error.");
			return FALSE;
		}
		icon_image = vm_statusbar_get_status_bar_image_byhandle(app_handle);
		if (icon_image == NULL)
		{
			vm_log_error("vm_statusbar_set_app_state: image NULL.");
			return FALSE;
		}
		
		if (icon_image->app_state != state)
		{
			VM_ICON_APP_STATE state_old = icon_image->app_state;//save old state
			VMINT res = FALSE;
			icon_image->app_state = state;
			
			vm_log_debug("vm_statusbar_set_app_state: icon_id=%d, state=%d", icon_image->icon_id, icon_image->app_state);
			
			//查找状态图片映射表，根据状态切换图片。
			res = vm_status_bar_change_icon_image(icon_image);
			if (res == FALSE)
			{
				vm_log_warn("vm_statusbar_set_app_state: change image failed.");
				icon_image->app_state = state_old;//restore state
			}
			return res;
		}
		return TRUE;
	}
	else
	{
		vm_log_warn("vm_statusbar_set_app_state: invalid state.");
		return FALSE;
	}
}

VMINT vm_check_if_appcalling(void)
{
	#if defined(VM_STATUSBARICON_PRE09B)
		if ((mmi_ucm_app_incoming_call(MMI_UCM_CALL_TYPE_ALL) + 
         		mmi_ucm_app_outgoing_call(MMI_UCM_CALL_TYPE_ALL) + 
         		mmi_ucm_app_total_call(MMI_UCM_CALL_TYPE_NO_CSD)) > 0 )
		{
			return TRUE;
		}
	#else
		if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
		{
			return TRUE;
		}
	#endif
	return FALSE;
}

static void vm_statusbar_process_default_queue(void)
{
	vm_status_bar_image_t* pIcon = statusbar_default_image_queue;
	VMINT bFound = FALSE;
	while(pIcon)
	{
		if(pIcon->image_status == VM_ICON_BLINK)
		{
			bFound = TRUE;
			vm_log_debug("process_default_queue: find blink icon true.");
			break;
		}
		pIcon = pIcon->next;
	}
	if(bFound)
	{
		vm_status_bar_blink_icon(pIcon->icon_id);
		vm_log_debug("process_default_queue: blink icon = %d.", pIcon->icon_id);
	}
	else
	{
		if(statusbar_default_image_queue)
		{
			vm_status_bar_show_icon(statusbar_default_image_queue->icon_id);
			vm_log_debug("process_default_queue: show icon = %d.", statusbar_default_image_queue->icon_id);
		}
	}
	vm_status_bar_update_icon();
}

static void vm_status_bar_status_notify_callback(VM_P_HANDLE pHandle, VMINT status)
{
	VMINT resHandle = 0;
	VMINT icon_id = 0;

	vm_log_debug("vm_status_bar_status_notify_callback start: handle = %d, status = %d", pHandle, status);

	switch (status)
	{
	case VM_PMNG_FOREGROUND:	
		{
			vm_status_bar_image_t *image=NULL;
			icon_id = vm_statusbar_get_iconid_by_phandle(pHandle);
			//vm_log_error("VM_PMNG_FOREGROUND..........icon_id:%d", icon_id);
			if (icon_id != 0)
			{
				vm_status_bar_hide_icon(icon_id);
				vm_status_bar_update_icon();
			}	

			//修改ICON 状态
			if ((image=vm_statusbar_get_status_bar_image_byhandle(pHandle))!=NULL)
			{
				image->image_status=VM_ICON_SHOW;
			}
		}
		break;
	case VM_PMNG_UNLOAD:
		{
			icon_id = vm_statusbar_get_iconid_by_phandle(pHandle);
			vm_log_debug("[STATUS BAR]VM_PMNG_UNLOAD..........icon_id:%d", icon_id);
			if (icon_id != 0)
			{
				vm_status_bar_hide_icon(icon_id);
				vm_status_bar_update_icon();
			}
			
			//释放image结点内存
			vm_statusbar_freenode(pHandle);
			
			while ((resHandle = vm_res_findfirst(pHandle, VM_RES_TYPE_STATUS_BAR)) 
				!= VM_RES_NOT_FIND)
			{
				vm_res_release_data(VM_RES_TYPE_STATUS_BAR, resHandle);
				vm_res_findclose(VM_RES_TYPE_STATUS_BAR);
			}

			//检查是否还有默认应用需要闪动
			if (icon_id == STATUS_ICON_VRE_DEFAULT)
			{
				vm_statusbar_process_default_queue();
			}
		}
		break;
	case VM_PMNG_BACKGROUND:
		{
			vm_log_debug("[STATUS BAR]VM_PMNG_BACKGROUND...........");
			//只有支持后台运行的才显示statusbar icon图标	
			if (vm_pmng_is_support_bg(pHandle))
			{
				//kal_prompt_trace(MOD_IDLE,".....vm_pmng_is_support_bg(pHandle)==TRUE....");
				vm_pmng_apply_to_action_in_fg(pHandle,VM_ICON_SHOW,NULL);
				
				icon_id = vm_statusbar_get_iconid_by_phandle(pHandle);
				vm_log_debug("[STATUS BAR]bg...........%d", icon_id);
				//检查是否还有默认应用需要闪动
				if (icon_id == STATUS_ICON_VRE_DEFAULT)
				{
					vm_statusbar_process_default_queue();
				}
			}
			else
			{	
				kal_prompt_trace(MOD_IDLE,".....vm_pmng_is_support_bg(pHandle)==FALSE....");
			}
		}
		break;
	}

	vm_log_debug("vm_status_bar_status_notify_callback end.");
}

static VMINT vm_statusbar_mod_evt_proc(VRE_MOD_LIFECIRCLE_EVT event)
{
	VMINT resHandle = 0;
	vm_status_bar_image_t* image = NULL;
	
	switch(event)
	{
		case EVT_MOD_INIT:
			statusbar_image_queue = NULL;
			statusbar_default_image_queue=NULL;

			/*********Set all iconid unused***********/
			vm_statusbar_set_iconid_all_used(FALSE);

			if (vm_res_type_set_notify_callback(VM_RES_TYPE_STATUS_BAR, 
				vm_status_bar_status_notify_callback) != 0)
				return -1;
			break;
 		case EVT_MOD_RELEASE:
			/* 释放链表 */
			if (statusbar_image_queue)
			{
				vm_status_bar_hide_icon(statusbar_image_queue->icon_id);
				vm_status_bar_update_icon();
				
				while ((image = statusbar_image_queue) != NULL)
				{
					statusbar_image_queue = statusbar_image_queue->next;

					vm_statusbar_free_image(image);
				}
				statusbar_image_queue = NULL;
			}

			if (statusbar_default_image_queue)
			{
				vm_status_bar_hide_icon(statusbar_image_queue->icon_id);
				vm_status_bar_update_icon();
				
				while ((image = statusbar_default_image_queue) != NULL)
				{
					statusbar_default_image_queue = statusbar_default_image_queue->next;
					
					vm_statusbar_free_image(image);
				}
				statusbar_default_image_queue = NULL;
			}
			
			/* 释放资源*/
			while ((resHandle = vm_res_findfirst(-1, VM_RES_TYPE_STATUS_BAR)) 
				!= VM_RES_NOT_FIND)
			{
				vm_res_release_data(VM_RES_TYPE_STATUS_BAR, resHandle);
				vm_res_findclose(VM_RES_TYPE_STATUS_BAR);
			}
			
			vm_res_type_set_notify_callback(VM_RES_TYPE_STATUS_BAR, NULL);
			break;
	}
	return 0;
}

static void vm_statusbar_play_midi_callback(kal_int32 handle, kal_int32 result)
{
	mdi_audio_mma_stop(handle);
	mdi_audio_mma_close(handle);
}

VMINT _vm_reg_statusbar_module(void)
{
	int res_code = REG_VRE_MODULE_SUCCESS;
	
	if ((res_code = _vm_reg_module("STATUSBAR MODULE", 
		(MOD_EVT_PROCESS)vm_statusbar_mod_evt_proc)) != REG_VRE_MODULE_SUCCESS)
	{
		vm_log_error("[STATUSBAR MODULE]Failed to regisiter statusbar module. Error Code : %d", res_code);
	}

	return res_code;
}

VMINT vm_pmng_apply_to_run_in_fg(VMINT notify_type)
{
	return vm_pmng_apply_to_action_in_fg(vm_pmng_get_app_handle(),VM_ICON_BLINK,notify_type);
}


VMINT vm_pmng_apply_to_action_in_fg(VM_P_HANDLE pHandle,VM_FG_ICONSTATUS_TYPE status,VMINT notify_type)
{
	MMI_ALERT_TYPE alerttype = GetMtCallAlertTypeEnum();
//	kal_prompt_trace(MOD_IDLE,"[STATUSBAR MODULE]vm_pmng_apply_to_action_in_fg  ::pHandle():%d,status :%d, notify_type:%d ",pHandle,status,notify_type);
//	vm_log_error("[STATUSBAR MODULE]vm_pmng_apply_to_action_in_fg  ::pHandle():%d,status :%d, notify_type:%d ",pHandle,status,notify_type);

	if (status==VM_ICON_BLINK)
	{
		/*if (!(notify_type & VM_NOTIFY_TYPE_SOUND) 
		&& !(notify_type & VM_NOTIFY_TYPE_VIBRATILITY))*/
		if (notify_type < 0x00 || notify_type > 0x11)
			return VM_PMNG_ERROR_PARAM;
	}
	
	if (vm_pmng_state(pHandle) != VM_PMNG_BACKGROUND)
		return VM_PMNG_NO_OP_IN_STATUS;

	if (vm_res_get_data_list_count_by_proecss(pHandle, VM_RES_TYPE_STATUS_BAR) <= 0)//Prevent from recreating image
	{
		vm_status_bar_image_t* image = NULL;
		VMWCHAR *fullFilename = NULL, *filename = NULL;

		if ((fullFilename = vm_calloc((MAX_APP_NAME_LEN + 1) * sizeof(VMWCHAR))) == NULL)
			return VM_PMNG_NO_MEM;

		if (vm_get_exec_filename(fullFilename) != 0)
		{
			vm_free(fullFilename);
			return VM_PMNG_NO_OP_IN_STATUS;
		}

		for (filename = fullFilename + vm_wstrlen(fullFilename) - 1;
			filename > fullFilename; filename--)
		{
			if ((*filename) == (VMWCHAR)L'\\')
			{
				if (filename == (fullFilename + vm_wstrlen(fullFilename) - 1))
					filename = fullFilename;
				else
					filename++;
				break;
			}
		}
		
		if ((image = vm_malloc(sizeof(vm_status_bar_image_t))) != NULL)
		{
			if (vm_res_save_data(VM_RES_TYPE_STATUS_BAR, NULL, 0, NULL, pHandle) >= 0)
			{
				VMINT res = FALSE;
				VMINT spec_imgid = mmi_am_get_status_bar_icon_resid((U16*)filename);
				
				/* 进入链。  */
				
				/*************Get one unused iconid**************/
				image->icon_id = vm_statusbar_get_unused_iconid();
				/*************Set iconid used**************/
				vm_statusbar_set_iconid_used(image->icon_id, TRUE);
				image->pHandle = pHandle;
				image->image_status=status;

				vm_wstrncpy(image->fullFilename, fullFilename,MAX_APP_NAME_LEN);

				if(image->icon_id==STATUS_ICON_VRE_DEFAULT)  //如是默认icon进 statusbar_default_image_queue
				{
					image->next = statusbar_default_image_queue;
					statusbar_default_image_queue = image;
			
				} else //进 statusbar_image_queue
				{
					image->next = statusbar_image_queue;
					statusbar_image_queue = image;
				}
				
				
				//create state-image table
				vm_statusbar_create_state_image_table(image);
				image->app_state = VM_ICON_APP_STATE_SPECIAL;//首先设为内置专用状态
				/**改变状态图标需要在image进image队列之后**/
				/*res = vm_statusbar_set_app_state(VM_ICON_APP_STATE_ONLINE);//设置初始状态
				if (res == FALSE)
					vm_log_warn("[STATUSBAR MODULE] set initial state error.");*/
				
				/**specially for backward compatibility**/
				if (IMG_SI_VRE_FETION <= spec_imgid && spec_imgid <= IMG_SI_VRE_QQ)
				{
					ChangeStatusIconImage(image->icon_id, spec_imgid);
				}
				
			}
			else
			{
				vm_log_error("[STATUSBAR MODULE] vm_res_save_data failed.....");
				
				vm_statusbar_free_image(image);
			}
		}
		
		vm_free(fullFilename);  
		
	}

	if (statusbar_image_queue || statusbar_default_image_queue)
	{
		VMINT icon_id = 0;
		vm_status_bar_image_t* image=NULL;
		
		icon_id = vm_statusbar_get_iconid_by_phandle(pHandle);
		
		//vm_log_error("[STATUSBAR MODULE]statusbar_image_queue>0..icon_id:%d",icon_id);
		
		if (icon_id != 0)
		{
			vm_status_bar_hide_icon(icon_id);
			switch (status)
			{
				case VM_ICON_BLINK:
					{
						VMINT mutli_media_op = TRUE;

						//修改ICON 状态
						if ((image=vm_statusbar_get_status_bar_image_byhandle(pHandle))!=NULL)
						{
							image->image_status=VM_ICON_BLINK;
						}

						/* 判定是否要做震动或播放MIDI的操作 */ 
						mutli_media_op =!vm_check_if_appcalling();
						
						//kal_prompt_trace(MOD_IDLE,"..[STATUS BAR]. alerttype:%d.mutli_media_op:%d ..mdi_audio_is_idle=%d,mdi_audio_mma_is_idle():%d,mdi_audio_is_playing(MDI_AUDIO_PLAY_STRING):%d,mdi_audio_is_playing(MDI_AUDIO_PLAY_FILE):%d",alerttype,mutli_media_op,mdi_audio_is_idle(),mdi_audio_mma_is_idle(),mdi_audio_is_playing(MDI_AUDIO_PLAY_STRING),mdi_audio_is_playing(MDI_AUDIO_PLAY_FILE));//,vm_statusbar_IsToneAllow()
						//vm_log_warn("..[STATUS BAR]. alerttype:%d.mutli_media_op:%d ..mdi_audio_is_idle=%d,mdi_audio_mma_is_idle():%d,mdi_audio_is_playing(MDI_AUDIO_PLAY_STRING):%d,mdi_audio_is_playing(MDI_AUDIO_PLAY_FILE):%d",alerttype,mutli_media_op,mdi_audio_is_idle(),mdi_audio_mma_is_idle(),mdi_audio_is_playing(MDI_AUDIO_PLAY_STRING),mdi_audio_is_playing(MDI_AUDIO_PLAY_FILE));//mdi_audio_is_able_to_use_by_other_task(),,vm_statusbar_IsToneAllow()

						switch (alerttype)	//使用switch特性，有意不加break。
						{	
								case MMI_ALERT_NONE:
									mutli_media_op = FALSE;			
								case MMI_RING:
								case MMI_VIBRATION_AND_RING:
								case MMI_VIBRATION_THEN_RING:
									/* 播放音频 		*/
									if ((mdi_audio_is_idle()) && mutli_media_op && (notify_type & VM_NOTIFY_TYPE_SOUND)
									#if defined(__MMI_VIDEO_RECORDER__) && !defined(__MMI_CAMCORDER__)
									&& !mmi_vdorec_is_in_app() 
									#endif
									#ifdef __MMI_VIDEO_PLAYER__
									&& ! mmi_vdoply_is_in_app()
									#endif
									) //aud_mma_is_idle()//vm_statusbar_IsToneAllow()
									{
										VMINT midiHandle = 0, ret= 0;

										if ((midiHandle = mdi_audio_mma_open_midi((void*)vm_notify_midi_data, 
											sizeof(vm_notify_midi_data), 1, vm_statusbar_play_midi_callback)) != 0)
										{
											if ((ret = mdi_audio_mma_play_midi(midiHandle)) != MDI_AUDIO_SUCCESS)
											{
												mdi_audio_mma_close_midi(midiHandle);
												vm_log_warn("[STATUS BAR]Failed to play notiftication midi. ErrorCode = %d.", midiHandle);
											}
										}
										else
										{
											vm_log_warn("[STATUS BAR]Failed to open notiftication midi. ErrorCode = %d.", midiHandle);
										}
									}
									
								case MMI_VIBRATION_ONLY:	
									/* 震动 			*/
									if (mutli_media_op && (notify_type & VM_NOTIFY_TYPE_VIBRATILITY))
									{
										PlayVibratorOnce();
									}			
									break;
						}
						
						
						vm_status_bar_blink_icon(icon_id); 
					}
					break;
				case VM_ICON_SHOW:
					{
						if (vm_statusbar_get_iconstatus_by_phandle(pHandle)==VM_ICON_BLINK) //如果原来是blink,保持blink
						{
							vm_status_bar_blink_icon(icon_id); 
						} 
						else
						{
							vm_status_bar_show_icon(icon_id); 
						}
						break;					
					}
				default:
					vm_status_bar_show_icon(icon_id); 
					break;					
			}

			vm_status_bar_update_icon();
		
		}
		else
		{
			vm_log_warn("[STATUS BAR] icon_id is NULL.......");
		}
	}

	return VM_PMNG_OP_OK;
}



#if     defined(__MMI_TOUCH_SCREEN__) /*&& !defined(__MMI_VUI_HOMESCREEN__)*/

//#define VM_GOBACK_LIST  /*如希望默认列表程序退出返回列表，请打开此宏*/

#ifdef VM_GOBACK_LIST
S32 ifclickmethod=FALSE;
#endif

S32 hightlight_bg_appindex=-1;
extern U8 hintData[MAX_SUB_MENUS][MAX_SUB_MENU_HINT_SIZE];
extern U8 subMenuData[MAX_SUB_MENUS][MAX_SUB_MENU_SIZE];
extern PU8 subMenuDataPtrs[MAX_SUB_MENUS];
extern PU8 hintDataPtrs[MAX_SUB_MENUS];
extern VMINT vre_running ;

void vm_status_icon_cb(VMINT tid);
void vm_process_status_icon(void);/*注册的回调处理函数*/
void vm_statusbar_process_icon(VMINT icon_id);
void vm_process_status_defaulticon(void);
extern void vm_register_status_icon_pen_event(void);
extern VMINT vm_get_sb(void);
extern void vm_restore_sb(VMINT sb);

VMINT vm_check_ifallow_process(void)
{
		U16 actScreenid=GetActiveScreenId();

		//kal_prompt_trace(MOD_IDLE,"SCR_MEDMEM_STOP_PROMPT:%d,,,actScreenid=%d...VRE_SCREEN_ID:%d, GRP_ID_AM:%d",SCR_MEDMEM_STOP_PROMPT,actScreenid,VRE_SCREEN_ID,GRP_ID_AM);

		if (vm_check_if_appcalling())
		{
			vm_log_debug("...vm_check_if_appcalling...");
			return FALSE;
		}

		//排除SCREEN，返回FALSE
		//有screen排除都可在此添加
		if (
			(actScreenid>=VRE_SCREEN_ID) && (actScreenid<GRP_ID_VRE_END) || (actScreenid>=GRP_ID_AM) && (actScreenid<SCR_ID_AM_LAST)  || (actScreenid==SCR_MEDMEM_STOP_PROMPT)  || (actScreenid==SCR_TDL_REMINDER) 
			 || (actScreenid>=SCR_APPMEM_STOP_PROMPT)  && (actScreenid<=SCR_APPMEM_STOP_PROGRESSING)
		)
			return FALSE;


		return TRUE;
}


/*ltz 0612*/
//#ifdef __MMI_VUI_HOMESCREEN__
signed int g_statusicon_id;
void vm_status_icon_cb(VMINT tid)
{
	vm_delete_timer(tid);
	switch(g_statusicon_id)
	{
		case STATUS_ICON_VRE_1:
		case STATUS_ICON_VRE_2:
		case STATUS_ICON_VRE_3:
		case STATUS_ICON_VRE_4:
			vm_statusbar_process_icon(g_statusicon_id);
			break;
		case STATUS_ICON_VRE_DEFAULT:
			vm_process_status_defaulticon();
			break;
		default:
			break;
	}
}

void vm_process_status_icon(void)
{
	vm_create_timer(0, vm_status_icon_cb);
}
//#endif

void vm_statusbar_process_icon(VMINT icon_id)
{
	if (vm_check_ifallow_process())
	{
		vm_pmng_create_process(vm_get_fullfilename_by_iconid(icon_id), NULL, NULL);
	}
}

void vm_resume_backgound_app(void)
{
	vm_log_debug("...vm_resume_backgound_app::");
	if	(!vm_check_if_appcalling())
		vm_pmng_create_process((VMWSTR)hintDataPtrs[hightlight_bg_appindex], NULL, NULL);
}


void vm_hilight_set_backgound_index(S32 hightlight_index )
{
	vm_log_debug("...vm_hilight_set_backgound_index::hilight_index=%d",hightlight_index);
	hightlight_bg_appindex=hightlight_index;

}

#ifdef VM_GOBACK_LIST
extern void vm_processing_status_defaulticon(void);
extern void vm_exitprocess_status_defaulticon(void);
void vm_exitprocess_status_defaulticon(void)
{
	ifclickmethod=FALSE;
}


void vm_process_status_defaulticon(void)
{
	ifclickmethod=TRUE;
	vm_processing_status_defaulticon();
}
 
void vm_processing_status_defaulticon(void)
#else
void vm_process_status_defaulticon(void)
#endif
{
	U8* gui_buffer = NULL;
	VMINT i=0, tagsize=0;
	vm_status_bar_image_t* default_iconsbar=vm_get_defaulticons_statusbar(); 
	VMSTR tag_buf=NULL; 


	//kal_prompt_trace(MOD_IDLE,"...........vm_process_status_defaulticon...ifclickmethod:%d...",ifclickmethod);
	vm_log_debug("....vm_process_status_defaulticon.....");

#ifdef VM_GOBACK_LIST
	if (ifclickmethod)
	{
#endif
	 
	if (!vm_check_ifallow_process())
	{
		//kal_prompt_trace(MOD_IDLE,"...........vm_process_status_defaulticon....vm_check_ifallow_process()==FALSE");
		vm_log_error("....vm_process_status_defaulticon...vm_check_ifallow_process()==FALSE..");
		return;
	}

#ifdef VM_GOBACK_LIST
	}
#endif
	
	if (default_iconsbar)
	{
		vm_status_bar_image_t* tmp=default_iconsbar;
		VMINT currR9 = vm_get_sb();

		//kal_prompt_trace(MOD_IDLE,"............default_iconsbar is NOT NULL............");

		memset(hintData,0x00,sizeof(U8)*MAX_SUB_MENUS*MAX_SUB_MENU_HINT_SIZE);
		memset(hintDataPtrs,0x00,sizeof(PU8)*MAX_SUB_MENUS);

		memset(subMenuData,0x00,sizeof(U8)*MAX_SUB_MENUS*MAX_SUB_MENU_SIZE);
		memset(subMenuDataPtrs,0x00,sizeof(PU8)*MAX_SUB_MENUS);
		
		hintDataPtrs[0] = hintData[0];
        	subMenuDataPtrs[0] = subMenuData[0]; 
		i=0;

		
		vm_restore_sb(0);
		while(tmp)
		{
			//kal_prompt_trace(MOD_IDLE,"..........tmp->icon_id :%d,STATUS_ICON_VRE_DEFAULT:%d",tmp->icon_id,STATUS_ICON_VRE_DEFAULT);
			if ( (tmp->icon_id==STATUS_ICON_VRE_DEFAULT))   // 只显示默认图标应用
			{
				VMINT  ret=-99;
				tagsize=0;
				if((ret=vm_get_vm_tag(tmp->fullFilename,VM_CE_INFO_NAME,NULL,&tagsize) )== GET_TAG_TRUE)
				{
					tag_buf =_vm_kernel_calloc(tagsize + 1);
					if(tag_buf)
					{
						//kal_prompt_trace(MOD_IDLE,".............tagsize :%d",tagsize);
						//vm_log_error("....tagsize :%d",tagsize);
						if(vm_get_vm_tag(tmp->fullFilename, VM_CE_INFO_NAME, tag_buf, &tagsize) == GET_TAG_TRUE)
						{
							//kal_prompt_trace(MOD_IDLE,".............tag_buf :%s",tag_buf);
							//vm_log_error("....tag_buf :%s",tag_buf);
							vm_default_to_ucs2((VMWSTR)subMenuData[i],MAX_SUB_MENU_SIZE,tag_buf); 
							subMenuDataPtrs[i] = subMenuData[i];
							hintDataPtrs[i]=(PU8)tmp->fullFilename;
							i++;
						}
						vm_free(tag_buf);
					} else
					{	
						vm_log_error("....tag_buf =_vm_kernel_realloc. is NULL.");
						//kal_prompt_trace(MOD_IDLE,".............tag_buf =_vm_kernel_realloc. is NULL..........");

					}
				}
				// kal_prompt_trace(MOD_IDLE,"........ret:%d...",ret);
			}
			tmp=tmp->next;
		}
		vm_restore_sb(currR9);
		//如果只有一个，则直接启动
		if (
		#ifdef VM_GOBACK_LIST
			ifclickmethod &&
		#endif
			(i==1)
		)
		{
				vm_pmng_create_process((VMWSTR)hintDataPtrs[0], NULL, NULL);
				return;
		}
		
	}else
	{
			//列表为空
			GoBackHistory();
			return;
	}

#ifdef VM_GOBACK_LIST
		EntryNewScreen(VRE_BACKGROUND_LIST_SCREEN_ID,  vm_exitprocess_status_defaulticon, vm_processing_status_defaulticon, NULL);
#else
		EntryNewScreen(VRE_BACKGROUND_LIST_SCREEN_ID,  NULL, NULL, NULL);//(FuncPtr)vm_process_status_defaulticon
#endif

	//SetDelScrnIDCallbackHandler(VRE_BACKGROUND_LIST_SCREEN_ID, (HistoryDelCBPtr)vm_exit_process_status_defaulticon);
	gui_buffer = GetCurrGuiBuffer(VRE_BACKGROUND_LIST_SCREEN_ID);


	RegisterHighlightHandler(vm_hilight_set_backgound_index);

	//kal_prompt_trace(MOD_IDLE,"............count i=%d..........",i );

    ShowCategory6Screen(
        STR_VRE_TITLE,
	0,
	STR_GLOBAL_OK,
	0,
	STR_GLOBAL_BACK,
	0,
        (S32)i ,
        (U8 **)  subMenuDataPtrs,
        (U8 **)hintDataPtrs,
        (S32)0,
        NULL);


	if (i>0)
		SetLeftSoftkeyFunction(vm_resume_backgound_app, KEY_EVENT_UP);
	else
		SetLeftSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);	
	
	SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

 
}


void vm_register_status_icon_pen_event(void)
{
#if defined(VM_STATUSBARICON_PRE09B)
	wgui_register_status_icon_pen_event_hdlr(STATUS_ICON_VRE_1, WGUI_STATUS_ICON_BAR_PEN_SELECT_ICON, vm_process_status_icon);
	wgui_register_status_icon_pen_event_hdlr(STATUS_ICON_VRE_2, WGUI_STATUS_ICON_BAR_PEN_SELECT_ICON, vm_process_status_icon);
	wgui_register_status_icon_pen_event_hdlr(STATUS_ICON_VRE_3, WGUI_STATUS_ICON_BAR_PEN_SELECT_ICON, vm_process_status_icon);
	wgui_register_status_icon_pen_event_hdlr(STATUS_ICON_VRE_4, WGUI_STATUS_ICON_BAR_PEN_SELECT_ICON, vm_process_status_icon);
	wgui_register_status_icon_pen_event_hdlr(STATUS_ICON_VRE_DEFAULT, WGUI_STATUS_ICON_BAR_PEN_SELECT_ICON, vm_process_status_icon);
#else
	wgui_status_icon_bar_register_pen_event_handler(STATUS_ICON_VRE_1, WGUI_STATUS_ICON_BAR_PEN_SELECT_ICON, vm_process_status_icon);
	wgui_status_icon_bar_register_pen_event_handler(STATUS_ICON_VRE_2, WGUI_STATUS_ICON_BAR_PEN_SELECT_ICON, vm_process_status_icon);
	wgui_status_icon_bar_register_pen_event_handler(STATUS_ICON_VRE_3, WGUI_STATUS_ICON_BAR_PEN_SELECT_ICON, vm_process_status_icon);
	wgui_status_icon_bar_register_pen_event_handler(STATUS_ICON_VRE_4, WGUI_STATUS_ICON_BAR_PEN_SELECT_ICON, vm_process_status_icon);
	wgui_status_icon_bar_register_pen_event_handler(STATUS_ICON_VRE_DEFAULT, WGUI_STATUS_ICON_BAR_PEN_SELECT_ICON, vm_process_status_icon);
#endif
}

void vm_reset_status_icon_pen_event(void)
{
#if defined(VM_STATUSBARICON_PRE09B)
	wgui_register_status_icon_pen_event_hdlr(STATUS_ICON_VRE_1, WGUI_STATUS_ICON_BAR_PEN_SELECT_ICON, NULL);
	wgui_register_status_icon_pen_event_hdlr(STATUS_ICON_VRE_2, WGUI_STATUS_ICON_BAR_PEN_SELECT_ICON, NULL);
	wgui_register_status_icon_pen_event_hdlr(STATUS_ICON_VRE_3, WGUI_STATUS_ICON_BAR_PEN_SELECT_ICON, NULL);
	wgui_register_status_icon_pen_event_hdlr(STATUS_ICON_VRE_4, WGUI_STATUS_ICON_BAR_PEN_SELECT_ICON, NULL);
	wgui_register_status_icon_pen_event_hdlr(STATUS_ICON_VRE_DEFAULT, WGUI_STATUS_ICON_BAR_PEN_SELECT_ICON, NULL);
#else
	wgui_status_icon_bar_register_pen_event_handler(STATUS_ICON_VRE_1, WGUI_STATUS_ICON_BAR_PEN_SELECT_ICON, NULL);
	wgui_status_icon_bar_register_pen_event_handler(STATUS_ICON_VRE_2, WGUI_STATUS_ICON_BAR_PEN_SELECT_ICON, NULL);
	wgui_status_icon_bar_register_pen_event_handler(STATUS_ICON_VRE_3, WGUI_STATUS_ICON_BAR_PEN_SELECT_ICON, NULL);
	wgui_status_icon_bar_register_pen_event_handler(STATUS_ICON_VRE_4, WGUI_STATUS_ICON_BAR_PEN_SELECT_ICON, NULL);
	wgui_status_icon_bar_register_pen_event_handler(STATUS_ICON_VRE_DEFAULT, WGUI_STATUS_ICON_BAR_PEN_SELECT_ICON, NULL);
#endif
}


VMINT vm_vre_is_running(void)
{
	return vre_running;
}
#endif




#endif
