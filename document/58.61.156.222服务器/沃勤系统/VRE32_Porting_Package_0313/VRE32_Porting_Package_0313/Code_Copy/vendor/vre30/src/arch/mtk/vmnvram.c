#ifdef __VRE__
#include "mmi_include.h"

#include "vmsys.h"
#include "vmio.h"
#include "vmwin.h"
#include "vmchset.h"
#include "vmstdlib.h"
#include "vmgettag.h"
#include "vmdl.h"
#include "vmlog.h"
#include "vmnvram.h"
#include "vmdes.h"
#include "vmua.h"
#include "vmmem.h"
#include "vmsim.h"


//static void vm_write_inti_value(VMINT index, VMUINT8* data_buff, VMINT len);
/**
  *	应用黑名单列表
  */
vm_nvram_app_ban_list_t * app_ban_list = NULL;

#define VRE_FIRSTRUNNING 0xff
#define VRE_NOT_FIRSTRUNNING 0x00
#define VRE_NOSET_FIRSTRUNNING 0x11

static VMINT vm_nvram_first_running = VRE_NOSET_FIRSTRUNNING;

VMUINT8 vm_nvram_get_firstflag(void)
{
	VMUINT8 firstflag = VRE_NOT_FIRSTRUNNING;

	VMSHORT pError;
	VMINT result = -1;

	if (vm_nvram_first_running == VRE_NOSET_FIRSTRUNNING)
	{
		result = ReadRecord(NVRAM_EF_VRE_FIRST_RUNNING_LID, 1, (void*)&firstflag, 1, &pError);

		if (result < 0)
		{
			firstflag = VRE_NOT_FIRSTRUNNING;
			vm_log_debug("vm_nvram_get_firstflag : read record error");
		}
		vm_nvram_first_running = firstflag;
	}
	else
	{
		firstflag = vm_nvram_first_running;
	}
	return firstflag;
}

VMINT vm_nvram_set_firstflag(void)
{
	VMUINT8 firstflag = VRE_NOT_FIRSTRUNNING;

	VMSHORT pError;
	VMINT result = -1;
	
	result = WriteRecord(NVRAM_EF_VRE_FIRST_RUNNING_LID, 1, (void*)&firstflag, 1, &pError);

	if (result < 0)
	{
		vm_log_debug("vm_nvram_get_firstflag : write record error");
	}
	else
	{
		vm_nvram_first_running = firstflag;
	}
	return result;
}

#define DES_KEY_LEN 8

extern VMINT	vm_per_hash( VMCHAR * src );
extern const VMSTR vm_get_imei_ext(VMINT sim_index);

VMINT vm_nvram_encrypt_get_key(VMUINT8 firstflag, VMUINT8 * key_buffer, VMINT buffer_len)
{
	VMUINT8 * buf_ptr = key_buffer;
	VMINT a = 0;
	VMINT b = 0;

	VMCHAR stra[22];
	VMCHAR strb[22];
		
	if (buf_ptr == NULL)
		return 0;

	/*测试使用*/
	//memcpy((VMUINT8 *)buf_ptr, "vre888sh", DES_KEY_LEN);
	//return DES_KEY_LEN;
	/*测试使用*/

	if (firstflag == VRE_FIRSTRUNNING) /*首次运行，使用固定key*/
	{
		memcpy((VMUINT8 *)buf_ptr, "vre888sh", DES_KEY_LEN);		
		return DES_KEY_LEN;
	}
	else
	{
		if (vm_get_imei() == NULL)
			return 0;

		memset((VMCHAR *)stra, 0x00, 22);
		memset((VMCHAR *)strb, 0x00, 22);
		
		memcpy(stra, vm_get_imei_ext(VM_SIM_SIM1), 20);
		vm_log_debug("vm_nvram_encrypt_get_key : stra=%s", stra);
		vm_get_useragent(strb, 20);	
		vm_log_debug("vm_nvram_encrypt_get_key : strb=%s", strb);
		
		a = vm_per_hash(stra);
		vm_log_debug("vm_nvram_encrypt_get_key : a=%d", a);
		b = vm_per_hash(strb);
		vm_log_debug("vm_nvram_encrypt_get_key : b=%d", b);

		//memcpy((VMUINT8 *)buf_ptr, (VMUINT8 *)&a, 4);
		memcpy((VMUINT8 *)buf_ptr, (VMUINT8 *)&b, 4);
		memcpy((VMUINT8 *)(buf_ptr+4), (VMUINT8 *)&b, 4);
		return DES_KEY_LEN;
	}
	return 0;	
}


static VMUINT8 * vm_nvram_encrypt_data(VMUINT8 * input, VMINT input_len, VMINT * output_len)
{
	VMDESHANDLE ehandle = -1;
	VMUINT8 * buffer_ptr = NULL;
	VMUINT8 * key_ptr = NULL ;

	key_ptr = (VMUINT8 *)_vm_kernel_malloc(DES_KEY_LEN * sizeof(VMUINT8));
	if (key_ptr == NULL)
		return NULL;
	
	if (vm_nvram_encrypt_get_key(VRE_NOT_FIRSTRUNNING, key_ptr, DES_KEY_LEN) == DES_KEY_LEN)
	{
		vm_log_debug("vm_nvram_encrypt_get_key : %x,%x,%x,%x,%x,%x,%x,%x", 
			*(key_ptr), 
			*(key_ptr+1),
			*(key_ptr+2),
			*(key_ptr+3),
			*(key_ptr+4),
			*(key_ptr+5),
			*(key_ptr+6),
			*(key_ptr+7)
			);
		
		ehandle = vm_des_set_key(key_ptr);

		if (ehandle >= 0)
		{
			vm_log_debug("vm_nvram_encrypt_data : will vm_des_encrypt");
			buffer_ptr = vm_des_encrypt( ehandle, input, input_len, output_len );		
			vm_log_debug("vm_nvram_encrypt_data : have vm_des_encrypt, input_len=%d, output_len=%d", input_len, *output_len);
			vm_des_reset_key(ehandle);
		}
		else
		{
			vm_log_debug("vm_nvram_encrypt_data : create encrypt handle error");
		}		
	}
	_vm_kernel_free(key_ptr);
	return buffer_ptr;	
}

static VMUINT8 * vm_nvram_decrypt_data(VMUINT8 * input, VMINT input_len, VMINT * output_len)
{
	VMDESHANDLE ehandle = -1;
	VMUINT8 * buffer_ptr = NULL;
	VMUINT8 * key_ptr = NULL ;

	key_ptr = (VMUINT8 *)_vm_kernel_malloc(DES_KEY_LEN * sizeof(VMUINT8));
	if (key_ptr == NULL)
		return NULL;

	if (vm_nvram_encrypt_get_key(vm_nvram_get_firstflag(), key_ptr, DES_KEY_LEN) == DES_KEY_LEN)
	{
		ehandle = vm_des_set_key(key_ptr);
		if (ehandle >= 0)
		{
			vm_log_debug("vm_nvram_decrypt_data : will vm_des_decrypt");
			buffer_ptr = vm_des_decrypt( ehandle, input, input_len, output_len );	
			
			vm_log_debug("vm_nvram_decrypt_data : have vm_des_decrypt, input_len=%d, output_len=%d", input_len, *output_len);
			vm_des_reset_key(ehandle);
		}
		else
		{
			vm_log_debug("vm_nvram_encrypt_data : create encrypt handle error");
		}
	
	}
	_vm_kernel_free(key_ptr);
	return buffer_ptr;	
}

VMINT vm_nvram_read_record(VMUINT16 rec_name, VMUINT16 rec_index, VMINT rec_size, void* read_buff, VMUINT16 buff_len)
{
	VMSHORT pError;
	VMINT result = FALSE;
	/*加密数据的首地址*/
	VMUINT8 * encrypt_ptr = NULL;
	

	/*解密数据的首地址*/
	VMUINT8 * decrypt_ptr = NULL;
	VMINT decrypt_len = 0;
	
	if ((encrypt_ptr = (VMUINT8 * )_vm_kernel_malloc(rec_size * sizeof(VMUINT8))) != NULL)
	{
		memset(encrypt_ptr, 0x00, (rec_size * sizeof(VMUINT8)));
		result = ReadRecord(rec_name, rec_index, (void*)encrypt_ptr, rec_size, &pError);
		if (result >= 0)
		{
			decrypt_ptr = vm_nvram_decrypt_data(encrypt_ptr, rec_size, &decrypt_len);
			/*test*/
			//decrypt_len = buff_len;
			/*test*/
			//vm_log_debug("vm_nvram_read_record : decrypt_ptr=0x%x, decrypt_len=%d, buff_len=%d", decrypt_ptr, decrypt_len, buff_len);
			if (decrypt_ptr != NULL)
			{
				//vm_log_debug("vm_nvram_read_record : decrypt_ptr content = %d, %d, %d, %d", *decrypt_ptr, *(decrypt_ptr+1), *(decrypt_ptr+buff_len-2), *(decrypt_ptr+buff_len-1));
				memset(read_buff, 0x00, buff_len);
				if (decrypt_len == buff_len)
				{
					memcpy(read_buff, decrypt_ptr, buff_len);					
					result = TRUE;
					//vm_log_debug("vm_nvram_read_record : success, record ID=%d, index=%d ", rec_name, rec_index);
				}
				else
				{
					vm_log_debug("vm_nvram_read_record : decrypt data len error");
					result = FALSE;
				}
				//vm_log_debug("vm_nvram_read_record : will free decrypt_ptr : 0x%x", decrypt_ptr);
				//vm_log_debug("vm_nvram_read_record : decrypt_ptr content = %d, %d, %d, %d", *decrypt_ptr, *(decrypt_ptr+1), *(decrypt_ptr+buff_len-2), *(decrypt_ptr+buff_len-1));
				vm_free(decrypt_ptr);
				vm_log_debug("vm_nvram_read_record : have free decrypt_ptr");
			}
			else
			{
				vm_log_debug("vm_nvram_read_record : decrypt data error");
				result = FALSE;
			}
		}
		else
		{
			vm_log_debug("vm_nvram_read_record : read record ID=%d, index=%d error, error code=%d", rec_name, rec_index, pError);
			result = FALSE;
		}
		//vm_log_debug("vm_nvram_read_record : will free encrypt_ptr=0x%x", encrypt_ptr);
		_vm_kernel_free(encrypt_ptr);
	}
	else
	{
		vm_log_debug("vm_nvram_read_record : malloc encrypt_ptr error");
	}
	//vm_log_debug("vm_nvram_read_record : end, result=%d", result);
	return result;	
}

VMINT vm_nvram_write_record(VMUINT16 rec_name, VMUINT16 rec_index, VMINT rec_size, void* write_buff, VMUINT16 buff_len)
{
	VMSHORT pError;
	VMINT result = FALSE;
	/*加密数据的首地址*/
	VMUINT8 * encrypt_ptr = NULL;
	VMINT encrypt_len = 0;

	/*for debug*/
	//static int i = 0;

	vm_log_debug("vm_nvram_write_record : rec=%d, index=%d, size=%d", rec_name, rec_index, rec_size);
	encrypt_ptr = vm_nvram_encrypt_data(write_buff, buff_len, &encrypt_len);

	/*for debug*/
	//vm_write_inti_value(i++, encrypt_ptr, encrypt_len);

	if (encrypt_ptr != NULL)
	{
		if (encrypt_len == rec_size)
		{
			result = WriteRecord(rec_name, rec_index, (void*)encrypt_ptr, encrypt_len, &pError);
		}
		else
		{
			result =  VM_NVRAM_RW_ERROR;
		}
		vm_free(encrypt_ptr);
		
		if (result >= 0)
		{
			result = TRUE;
			vm_log_debug("vm_nvram_write_record : success, record ID=%d, index=%d ", rec_name, rec_index);
		}
		else
		{
			vm_log_debug("vm_nvram_write_record : write record ID=%d, index=%d error, error code=%d", rec_name, rec_index, pError);
			result = FALSE;
		}		
	}
	else
	{
		vm_log_debug("vm_nvram_write_record : encrypt_data error");
	}
	
	return result;	
}


VMINT vm_nvram_get_pkey_list(VMINT list_index, vm_nvram_root_pkey_list_t * pkey_list)
{
	VMINT isfound = FALSE;
	VMUINT16 pk_list_len = sizeof(vm_nvram_root_pkey_list_t);

	if ((list_index == 0 || list_index == 1) && pkey_list != NULL)
	{
		isfound = vm_nvram_read_record(
			NVRAM_EF_VRE_PKEY_LIST_EXT_LID,
			(VMUINT16)(1 + list_index),
			NVRAM_EF_VRE_PKEY_LIST_EXT_SIZE,
			(void *)pkey_list,
			pk_list_len);		
	}
	else
	{
		vm_log_debug("vm_nvram_get_pkey_list : pkey_list is NULL, or list_index is error.");
	}
	//vm_log_debug("get pkey list 's result : %d", isfound);
	return isfound;
}

VMINT vm_nvram_set_pkey_list(VMINT list_index, vm_nvram_root_pkey_list_t * pkey_list)
{
	VMINT saved = FALSE;
	VMUINT16 pk_list_len = sizeof(vm_nvram_root_pkey_list_t);

	vm_log_debug("vm_nvram_set_pkey_list start");
	if ((list_index == 0 || list_index == 1) && pkey_list != NULL)
	{
		saved = vm_nvram_write_record(
			NVRAM_EF_VRE_PKEY_LIST_EXT_LID, 
			(VMUINT16)(1 + list_index), 
			NVRAM_EF_VRE_PKEY_LIST_EXT_SIZE,
			(void *)pkey_list,
			pk_list_len);
	}
	else
	{
		vm_log_debug("vm_nvram_set_pkey_list : pkey_list is NULL, or list_index is error");
	}
	
	return saved;
}


VMINT vm_nvram_get_ban_list(vm_nvram_app_ban_list_t * ban_list_ptr)
{
	VMINT isfound = FALSE;
	VMUINT16 ban_list_len = sizeof(vm_nvram_app_ban_list_t);

	if (ban_list_ptr != NULL)
	{
		isfound = vm_nvram_read_record(
			NVRAM_EF_VRE_APP_BAN_LIST_EXT_LID,
			1,
			NVRAM_EF_VRE_APP_BAN_LIST_EXT_SIZE,
			(void *)ban_list_ptr,
			ban_list_len);
	}
	else
	{
		vm_log_debug("vm_nvram_get_ban_list : ban_list_ptr is NULL");
	}
	return isfound;
}

VMINT vm_nvram_set_ban_list(vm_nvram_app_ban_list_t * ban_list_ptr)
{
	VMINT saved = FALSE;
	VMUINT16 ban_list_len = sizeof(vm_nvram_app_ban_list_t);

	if (ban_list_ptr != NULL)
	{
		saved = vm_nvram_write_record(
			NVRAM_EF_VRE_APP_BAN_LIST_EXT_LID,
			1,
			NVRAM_EF_VRE_APP_BAN_LIST_EXT_SIZE,
			(void *)ban_list_ptr,
			ban_list_len);
	}
	else
	{
		vm_log_debug("vm_nvram_set_ban_list : ban_list_ptr is NULL");
	}
	return saved;
}

VMINT vm_load_app_ban_list(void)
{
	VMINT result = 0;
	if (app_ban_list  == NULL)
	{
		app_ban_list = (vm_nvram_app_ban_list_t *)_vm_kernel_malloc(sizeof(vm_nvram_app_ban_list_t));
				if (app_ban_list == NULL)
					return 0;
	}
	memset(app_ban_list, 0x00, sizeof(vm_nvram_app_ban_list_t));
	result = vm_nvram_get_ban_list(app_ban_list);
	if (result == FALSE)
	{
		_vm_kernel_free(app_ban_list);
		app_ban_list = NULL;
	}
	return result;		
}

void vm_unload_app_ban_list(void)
{
	if (app_ban_list != NULL)
	{
		_vm_kernel_free(app_ban_list);
		app_ban_list = NULL;
	}
}
	
VMINT vm_app_in_ban_list(VMUINT app_id)
{
	VMINT isban = FALSE;
	VMINT i;

	if (app_ban_list == NULL)
	{
		return TRUE;
	}

	/**
	  *如果全为0的app_id，代表所有开发商所有应用，
	  *如果全为FFFFFFFF的app_id，代表个人开发应用，
	  *返回FALSE代表不在黑名单内，
	  */
	if ((app_id == 0) || (app_id  == 0xffffffff))
	{
		return FALSE;
	}

	for (i = 0; i < BAN_LIST_SIZE; i++)
	{
		if (app_ban_list->app_ban_item[i] == app_id)
		{
			isban = TRUE;
			break;
		}
		else if (app_ban_list->app_ban_item[i] == (app_id & 0xffff0000)) 
		{
			/*该APP_ID的开发商的所有应用已经被屏蔽*/
			isban = TRUE;
			break;
		}
	}
	return isban;
}

/**
 *	在NVRAM中设置系统接口许可列表
 *    @param permission_list_ptr    系统接口许可列表
 *
 *    @return  TRUE=设置成功; FALSE=设置失败;
 */
VMINT vm_nvram_set_sym_permission(vm_nvram_permission_list_t * permission_list_ptr)
{
	VMINT saved = FALSE;
	VMUINT16 permission_list_len = sizeof(vm_nvram_permission_list_t);

	if (permission_list_ptr != NULL)
	{
		if (permission_list_ptr->vm_sym_permission_list_len > SYM_PERMISSION_LEN 
			||permission_list_ptr->vm_sym_permission_list_len < 0)
		{
			vm_log_debug("vm_nvram_set_sym_permission : permission_list_ptr's len is out of array");
			return FALSE;
		}
		saved = vm_nvram_write_record(
			NVRAM_EF_VRE_SYM_ENTRY_LIST_EXT_LID,
			1,
			NVRAM_EF_VRE_SYM_ENTRY_LIST_EXT_SIZE,
			(void *)permission_list_ptr,
			permission_list_len);
	}
	else
	{
		vm_log_debug("vm_nvram_set_sym_permission : permission_list_ptr is NULL");
	}
	
	return saved;
}

/**
 *	在NVRAM中读取系统接口许可列表
 *    @param permission_list_ptr    系统接口许可列表
 *
 *    @return  TRUE=设置成功; FALSE=设置失败;
 */
VMINT vm_nvram_get_sym_permission(vm_nvram_permission_list_t * permission_list_ptr)
{
	VMINT isfound = FALSE;
	VMUINT16 permission_list_len = sizeof(vm_nvram_permission_list_t);

	if (permission_list_ptr != NULL)
	{
		isfound = vm_nvram_read_record(
			NVRAM_EF_VRE_SYM_ENTRY_LIST_EXT_LID,
			1,
			NVRAM_EF_VRE_SYM_ENTRY_LIST_EXT_SIZE,
			(void *)permission_list_ptr,
			permission_list_len);
	}
	else
	{
		vm_log_debug("vm_nvram_get_sym_permission : permission_list_ptr is NULL");
	}
	return isfound;
}


/**
 *	合并许可列表,导入app的许可列表，与系统许可列表作许可标记交集
 *    得到合并后的许可列表
 *    @param   app_permission_list  应用程序接口许可列表,输入时应为非空
 *    @param   app_permission_list_len  应用程序接口许可列表长度,输入时必须大于0
 *    @param   merge_permission_list   合并后返回的许可列表，输入时应为非空.
 *    @param   merge_permission_list_len_ptr 合并许可列表,输入时必须大于0, 如果合并成功返回为大于0,否则为0.
 *
 *    @retrun   FALSE=合并失败, TRUE=合并成功
 */
VMINT vm_merge_permission(vm_permission_t * app_permission_list, 
							   VMINT app_permission_list_len, 
							   vm_permission_t * merge_permission_list, 
							   VMINT * merge_permission_list_len_ptr)
{
	VMINT i = 0;
	VMINT j = 0;
	VMINT app_per_id = -1;
	VMINT app_permission = 0;

	vm_nvram_permission_list_t * sym_permission_list = NULL; 
	
	if ((sym_permission_list = (vm_nvram_permission_list_t *)_vm_kernel_malloc(sizeof(vm_nvram_permission_list_t))) == NULL)
	{
		*merge_permission_list_len_ptr = 0;
		return FALSE;
	}
		
	memset(sym_permission_list, 0x00, sizeof(vm_nvram_permission_list_t));	
	/*从nvram加载许可列表*/
	vm_nvram_get_sym_permission(sym_permission_list);
	vm_log_debug("vm_merge_permission 1, get_sym_permission");

	/*条件判断
	if (sym_permission_list == NULL)
	{
		
		return FALSE;
	}*/

	if (sym_permission_list->vm_sym_permission_list == NULL || 
		sym_permission_list->vm_sym_permission_list_len == 0)
	{
		*merge_permission_list_len_ptr = 0;
		_vm_kernel_free(sym_permission_list);
		return FALSE;
	}
	
	if (app_permission_list == NULL || 
		app_permission_list_len == 0 ||
		merge_permission_list == NULL || 
		*merge_permission_list_len_ptr == 0)
	{ 
		*merge_permission_list_len_ptr = 0;
		_vm_kernel_free(sym_permission_list);
		return FALSE;
	}
	
	/*初始化合并列表*/
	memset(merge_permission_list, 0x00, ((*merge_permission_list_len_ptr) * sizeof(vm_permission_t)));
	vm_log_debug("vm_merge_permission 2, ");

	
	/*如果合并目标列表长度比系统列表长度长,合并长度采用系统列表长度*/
	if (*merge_permission_list_len_ptr >= sym_permission_list->vm_sym_permission_list_len)
		*merge_permission_list_len_ptr = sym_permission_list->vm_sym_permission_list_len;
	vm_log_debug("vm_merge_permission 3, *merge_permission_list_len : %d", *merge_permission_list_len_ptr);	
	/*复制sym_permission_list 到merge_permission_list*/
	for (j = 0; j < *merge_permission_list_len_ptr; j++)
	{
		merge_permission_list[j].operate_index
			= sym_permission_list->vm_sym_permission_list[j].operate_index;
		merge_permission_list[j].permission
			= sym_permission_list->vm_sym_permission_list[j].permission;
	}
	_vm_kernel_free(sym_permission_list);
	vm_log_debug("vm_merge_permission 4, ");
	/*合并许可表*/
	for ( i = 0; i < app_permission_list_len; i++)
	{
		app_per_id = app_permission_list[i].operate_index;
		app_permission = app_permission_list[i].permission;
		for (j = 0; j < *merge_permission_list_len_ptr; j++)
		{
			if (merge_permission_list[j].operate_index == app_per_id)
			{				
				/*权限交集操作*/
				if (merge_permission_list[j].permission == VM_ENTRY_ACCEPT &&
					app_permission == VM_ENTRY_ACCEPT)
				{
					merge_permission_list[j].permission = VM_ENTRY_ACCEPT;
				}
				else
				{
					merge_permission_list[j].permission = VM_ENTRY_REFUSE;
				}
				break;				
			}			
		}
	}
	vm_log_debug("vm_merge_permission 5, merge finish");
	return 	TRUE;
}

/**
 *	向nvram写入系统配置
 */
static VMINT vm_nvram_set_sysconf(vm_nvram_sysconf_t * sysconfig_ptr)
{
	VMINT saved = FALSE;
	VMUINT16 sysconfig_len = sizeof(vm_nvram_sysconf_t);
	
	if (sysconfig_ptr != NULL)
	{
		vm_log_debug("vm_nvram_set_sysconf step1");
		saved = vm_nvram_write_record(
			NVRAM_EF_VRE_SYM_CONF_LIST_EXT_LID,
			1,
			NVRAM_EF_VRE_SYM_CONF_LIST_EXT_SIZE,
			(void *)sysconfig_ptr,
			sysconfig_len);
		vm_log_debug("vm_nvram_set_sysconf step2");
	}
	else
	{
		vm_log_debug("vm_nvram_set_sysconf : sysconfig_ptr is NULL");
	}
	vm_log_debug("vm_nvram_set_sysconf end");
	return saved;
}


/**
 *	从nvram得到系统配置
 */
static VMINT vm_nvram_get_sysconf(vm_nvram_sysconf_t * sysconfig_ptr)
{
	VMINT isfound = FALSE;
	VMUINT16 sysconfig_len = sizeof(vm_nvram_sysconf_t);

	if (sysconfig_ptr != NULL)
	{
		isfound = vm_nvram_read_record(
			NVRAM_EF_VRE_SYM_CONF_LIST_EXT_LID,
			1,
			NVRAM_EF_VRE_SYM_CONF_LIST_EXT_SIZE,
			(void *)sysconfig_ptr,
			sysconfig_len);
	}
	else
	{
		vm_log_debug("vm_nvram_get_sysconf : sysconfig_ptr is NULL");
	}
	return isfound;
}


VMINT vm_get_sysconf(vm_nvram_sysconf_t * sysconfig_ptr)
{
	return vm_nvram_get_sysconf(sysconfig_ptr);
}

VMINT vm_set_sysconf(vm_nvram_sysconf_t * sysconfig_ptr)
{
	return vm_nvram_set_sysconf(sysconfig_ptr);
}



static VMINT vm_nvram_set_appstore_config(vm_nvram_appstore_config_t * appstore_config_ptr)
{
	VMINT saved = FALSE;

	VMUINT16 len = sizeof(vm_nvram_appstore_config_t);

	//vm_log_debug("vm_nvram_set_appstore_config start len=%d", len);
	//vm_log_debug("vm_nvram_set_appstore_config appstore_config_ptr.update_value=%d", appstore_config_ptr->update_value);
	//vm_log_debug("vm_nvram_set_appstore_config appstore_config_ptr.sim_index=%d", appstore_config_ptr->sim_index);
	if (appstore_config_ptr != NULL)
	{
		saved = vm_nvram_write_record(
			NVRAM_EF_VRE_APPSTORE_CONFIG_LIST_EXT_LID,
			1,
			NVRAM_EF_VRE_APPSTORE_CONFIG_LIST_EXT_SIZE,
			(void *)appstore_config_ptr,
			len);
	}
	else
	{
		vm_log_debug("vm_nvram_set_appstore_config : appstore_config_ptr is NULL");
	}
	//vm_log_debug("vm_nvram_set_appstore_config end");
	return saved;
}

static VMINT vm_nvram_get_appstore_config(vm_nvram_appstore_config_t * appstore_config_ptr)
{
	VMINT isfound = FALSE;
	VMUINT16 len = sizeof(vm_nvram_appstore_config_t);

	//vm_log_debug("vm_nvram_get_appstore_config start len=%d", len);

	if (appstore_config_ptr != NULL)
	{
		isfound = vm_nvram_read_record(
			NVRAM_EF_VRE_APPSTORE_CONFIG_LIST_EXT_LID,
			1,
			NVRAM_EF_VRE_APPSTORE_CONFIG_LIST_EXT_SIZE,
			(void *)appstore_config_ptr,
			len);
	}
	else
	{
		vm_log_debug("vm_nvram_get_appstore_config : appstore_config_ptr is NULL");
	}
	//vm_log_debug("vm_nvram_get_appstore_config end");
	return isfound;
}

static VMINT vm_nvram_set_appstore3_config(vm_nvram_appstore3_config_t * appstore_config_ptr)
{
	VMINT saved = FALSE;

	VMUINT16 len = sizeof(vm_nvram_appstore3_config_t);

	if (appstore_config_ptr != NULL)
	{
		saved = vm_nvram_write_record(
			NVRAM_EF_VRE_APPSTORE3_CONFIG_LIST_EXT_LID,
			1,
			NVRAM_EF_VRE_APPSTORE3_CONFIG_LIST_EXT_SIZE,
			(void *)appstore_config_ptr,
			len);
	}
	else
	{
		vm_log_debug("vm_nvram_set_appstore3_config : appstore3_config_ptr is NULL");
	}
	//vm_log_debug("vm_nvram_set_appstore3_config end");
	return saved;
}

static VMINT vm_nvram_get_appstore3_config(vm_nvram_appstore3_config_t * appstore_config_ptr)
{
	VMINT isfound = FALSE;
	VMUINT16 len = sizeof(vm_nvram_appstore3_config_t);

	//vm_log_debug("vm_nvram_get_appstore3_config start len=%d", len);

	if (appstore_config_ptr != NULL)
	{
		isfound = vm_nvram_read_record(
			NVRAM_EF_VRE_APPSTORE3_CONFIG_LIST_EXT_LID,
			1,
			NVRAM_EF_VRE_APPSTORE3_CONFIG_LIST_EXT_SIZE,
			(void *)appstore_config_ptr,
			len);
	}
	else
	{
		vm_log_debug("vm_nvram_get_appstore3_config : appstore_config_ptr is NULL");
	}
	return isfound;
}

VMINT vm_set_appstore_config(vm_nvram_appstore_config_t * appstore_config_ptr)
{
	return vm_nvram_set_appstore_config(appstore_config_ptr);
}

VMINT vm_get_appstore_config(vm_nvram_appstore_config_t * appstore_config_ptr)
{
	return vm_nvram_get_appstore_config(appstore_config_ptr);
}

VMINT vm_set_appstore3_config(vm_nvram_appstore3_config_t * appstore_config_ptr)
{
	return vm_nvram_set_appstore3_config(appstore_config_ptr);
}
VMINT vm_get_appstore3_config(vm_nvram_appstore3_config_t * appstore_config_ptr)
{
	return vm_nvram_get_appstore3_config(appstore_config_ptr);
}

/** 
 *	设置计费通道列表到nvram
 */
static VMINT vm_nvram_set_paychannel_list_ext(vm_nvram_paychannel_list_ext_t * paychannel_list_ext_ptr)
{
	VMINT saved = TRUE;
	VMUINT16 channel_list_len = (sizeof(vm_paychannel_ext_t) * NVRAM_PAYMENT_CHANNEL_EXT_NUM_PER_RECORD);
	VMINT recordnum = NVRAM_PAYMENT_CHANNEL_EXT_NUM / NVRAM_PAYMENT_CHANNEL_EXT_NUM_PER_RECORD;
	
	if (paychannel_list_ext_ptr != NULL)
	{
		int i = 0;
		for (i = 0; i < recordnum; i++)
		{
			saved &= vm_nvram_write_record(
				NVRAM_EF_VRE_PAY_CHANNEL_LIST_EXT_LID,
				(i + 1),
				NVRAM_EF_VRE_PAY_CHANNEL_LIST_EXT_SIZE,
				(void*)&(paychannel_list_ext_ptr->paychannel_list_ext[i * NVRAM_PAYMENT_CHANNEL_EXT_NUM_PER_RECORD]),
				channel_list_len);
		}
	}
	else
	{
		vm_log_debug("vm_nvram_set_paychannel_list_ext : paychannel_list_ext_ptr is NULL");
	}
	return saved;
}



/**
 *	从nvram得到计费通道列表
 */
static VMINT vm_nvram_get_paychannel_list_ext(vm_nvram_paychannel_list_ext_t * paychannel_list_ext_ptr)
{
	VMINT isfound = TRUE;
	VMUINT16 channel_list_len = (sizeof(vm_paychannel_ext_t) * NVRAM_PAYMENT_CHANNEL_EXT_NUM_PER_RECORD);
	VMINT recordnum = NVRAM_PAYMENT_CHANNEL_EXT_NUM / NVRAM_PAYMENT_CHANNEL_EXT_NUM_PER_RECORD;

	if (paychannel_list_ext_ptr != NULL)
	{
		int i = 0;
		memset(paychannel_list_ext_ptr, 0x00, channel_list_len * recordnum);

		for (i = 0; i < recordnum; i++)
		{
			isfound &= vm_nvram_read_record(
				NVRAM_EF_VRE_PAY_CHANNEL_LIST_EXT_LID,
				(i+1),
				NVRAM_EF_VRE_PAY_CHANNEL_LIST_EXT_SIZE,
				(void*)&(paychannel_list_ext_ptr->paychannel_list_ext[i*NVRAM_PAYMENT_CHANNEL_EXT_NUM_PER_RECORD]),
				channel_list_len);
		}
	}
	else
	{
		vm_log_debug("vm_nvram_get_paychannel_list_ext : paychannel_list_ext_ptr is NULL");
	}
	return isfound;
}

VMINT vm_get_pay_channel_list_ext(vm_nvram_paychannel_list_ext_t * paychannel_list_ext_ptr)
{
	return vm_nvram_get_paychannel_list_ext(paychannel_list_ext_ptr);
}

VMINT vm_set_pay_channel_list_ext(vm_nvram_paychannel_list_ext_t * paychannel_list_ext_ptr)
{	
	VMINT result = FALSE;
	vm_nvram_paychannel_list_ext_t * data_buffer = NULL;
	if ((data_buffer = (vm_nvram_paychannel_list_ext_t *)_vm_kernel_malloc(sizeof(vm_nvram_paychannel_list_ext_t))) != NULL)
    	{
    		memset(data_buffer, 0x00, sizeof(vm_nvram_paychannel_list_ext_t));
    		if (vm_nvram_get_paychannel_list_ext(data_buffer) == TRUE)
	    	{
			if ((result = vm_nvram_set_paychannel_list_ext(paychannel_list_ext_ptr)) == FALSE)
			{
				vm_nvram_set_paychannel_list_ext(data_buffer);
			}
	    	}
		_vm_kernel_free(data_buffer);
		data_buffer = NULL;
    	}
	vm_log_debug("vm_set_pay_channel_list_ext : end result=%d", result);
	return result;
}


/**
 *	从nvram得到计费通道A_EXT列表
 */
static VMINT vm_nvram_set_paychannel_a_list_ext(vm_nvram_paychannel_a_list_ext_t * paychannel_a_list_ext_ptr)
{
	VMINT saved = TRUE;
	VMUINT16 channel_a_list_len = (sizeof(vm_paychannel_a_ext_t) * NVRAM_PAYMENT_CHANNEL_A_EXT_NUM_PER_RECORD);
	VMINT recordnum = NVRAM_PAYMENT_CHANNEL_A_EXT_NUM / NVRAM_PAYMENT_CHANNEL_A_EXT_NUM_PER_RECORD;
	
	if (paychannel_a_list_ext_ptr != NULL)
	{
		int i = 0;
		for (i = 0; i < recordnum; i++)
		{
			saved &= vm_nvram_write_record(
				NVRAM_EF_VRE_PAY_CHANNEL_A_LIST_EXT_LID,
				(i + 1),
				NVRAM_EF_VRE_PAY_CHANNEL_A_LIST_EXT_SIZE,
				(void*)&(paychannel_a_list_ext_ptr->paychannel_a_list_ext[i * NVRAM_PAYMENT_CHANNEL_A_EXT_NUM_PER_RECORD]),
				channel_a_list_len);
		}
	}
	else
	{
		vm_log_debug("vm_nvram_set_paychannel_a_list_ext : paychannel_a_list_ext_ptr is NULL");
	}
	return saved;
}




static VMINT vm_nvram_get_paychannel_a_list_ext(vm_nvram_paychannel_a_list_ext_t * paychannel_a_list_ext_ptr)
{
	VMINT isfound = TRUE;
	VMUINT16 channel_a_list_len = (sizeof(vm_paychannel_a_ext_t) * NVRAM_PAYMENT_CHANNEL_A_EXT_NUM_PER_RECORD);
	VMINT recordnum = NVRAM_PAYMENT_CHANNEL_A_EXT_NUM / NVRAM_PAYMENT_CHANNEL_A_EXT_NUM_PER_RECORD;

	if (paychannel_a_list_ext_ptr != NULL)
	{
		int i = 0;
		memset(paychannel_a_list_ext_ptr, 0x00, channel_a_list_len * recordnum);

		for (i = 0; i < recordnum; i++)
		{
			isfound &= vm_nvram_read_record(
				NVRAM_EF_VRE_PAY_CHANNEL_A_LIST_EXT_LID,
				(i+1),
				NVRAM_EF_VRE_PAY_CHANNEL_A_LIST_EXT_SIZE,
				(void*)&(paychannel_a_list_ext_ptr->paychannel_a_list_ext[i*NVRAM_PAYMENT_CHANNEL_A_EXT_NUM_PER_RECORD]),
				channel_a_list_len);
		}
	}
	else
	{
		vm_log_debug("vm_nvram_get_paychannel_a_list_ext : paychannel_a_list_ext_ptr is NULL");
	}
	return isfound;
}

VMINT vm_get_pay_channel_a_list_ext(vm_nvram_paychannel_a_list_ext_t * paychannel_a_list_ext_ptr)
{
	return vm_nvram_get_paychannel_a_list_ext(paychannel_a_list_ext_ptr);
}

VMINT vm_set_pay_channel_a_list_ext(vm_nvram_paychannel_a_list_ext_t * paychannel_a_list_ext_ptr)
{	
	VMINT result = FALSE;
	vm_nvram_paychannel_a_list_ext_t * data_buffer = NULL;
	if ((data_buffer = (vm_nvram_paychannel_a_list_ext_t *)_vm_kernel_malloc(sizeof(vm_nvram_paychannel_a_list_ext_t))) != NULL)
    	{
    		memset(data_buffer, 0x00, sizeof(vm_nvram_paychannel_a_list_ext_t));
    		if (vm_nvram_get_paychannel_a_list_ext(data_buffer) == TRUE)
	    	{
			if ((result = vm_nvram_set_paychannel_a_list_ext(paychannel_a_list_ext_ptr)) == FALSE)
			{
				vm_nvram_set_paychannel_a_list_ext(data_buffer);
			}
	    	}
		_vm_kernel_free(data_buffer);
		data_buffer = NULL;
    	}
	vm_log_debug("vm_set_pay_channel_a_list_ext : end result=%d", result);
	return result;
}











/**
 *	设置应用信息列表到nvram
 */
static VMINT  vm_nvram_set_app_info_list(vm_nvram_app_info_ext_list_t * app_info_ext_list_ptr)
{
	VMINT saved = TRUE;

	VMUINT16 app_info_list_len = NVRAM_APP_PAYMENT_INFO_EXT_NUM_PER_RECORD * sizeof(vm_app_info_ext_t);
	VMINT recordnum = NVRAM_APP_PAYMENT_INFO_EXT_NUM / NVRAM_APP_PAYMENT_INFO_EXT_NUM_PER_RECORD;

	if (app_info_ext_list_ptr != NULL)
	{
		int i = 0;
		for (i = 0; i < recordnum; i++)
		{
			saved &= vm_nvram_write_record(
			NVRAM_EF_VRE_APP_STATE_LIST_EXT_LID,
			(i+1),
			NVRAM_EF_VRE_APP_STATE_LIST_EXT_SIZE,
			(void*)&(app_info_ext_list_ptr->app_info_ext_list[(i*NVRAM_APP_PAYMENT_INFO_EXT_NUM_PER_RECORD)]),
			app_info_list_len);
		}
	}
	else
	{
		vm_log_debug("vm_nvram_set_app_info_list : app_info_ext_list_ptr is NULL");
	}
	return saved;
}


/**
 *	 从nvram得到应用信息列表
 */
static VMINT  vm_nvram_get_app_info_list(vm_nvram_app_info_ext_list_t * app_info_ext_list_ptr)
{
	VMINT isfound = TRUE;
	VMUINT16 app_info_list_len = NVRAM_APP_PAYMENT_INFO_EXT_NUM_PER_RECORD * sizeof(vm_app_info_ext_t);
	VMINT recordnum = NVRAM_APP_PAYMENT_INFO_EXT_NUM / NVRAM_APP_PAYMENT_INFO_EXT_NUM_PER_RECORD;
	
	if (app_info_ext_list_ptr != NULL)
	{
		int i = 0;
		memset(app_info_ext_list_ptr, 0x00, sizeof(vm_nvram_app_info_ext_list_t));

		for (i = 0; i < recordnum; i++)
		{
			isfound &= vm_nvram_read_record(
			NVRAM_EF_VRE_APP_STATE_LIST_EXT_LID,
			(i+1),
			NVRAM_EF_VRE_APP_STATE_LIST_EXT_SIZE,
			(void*)&(app_info_ext_list_ptr->app_info_ext_list[(i*NVRAM_APP_PAYMENT_INFO_EXT_NUM_PER_RECORD)]),
			app_info_list_len);
		}
	}
	else
	{
		vm_log_debug("vm_nvram_get_app_info_list : app_info_ext_list_ptr is NULL");
	}
	return isfound;
}

VMINT vm_get_app_info_list(vm_nvram_app_info_ext_list_t * app_info_ext_list_ptr)
{
	return vm_nvram_get_app_info_list(app_info_ext_list_ptr);
}

VMINT vm_set_app_info_list(vm_nvram_app_info_ext_list_t * app_info_ext_list_ptr)
{
	VMINT result = FALSE;
	vm_nvram_app_info_ext_list_t * data_buffer = NULL;
	
	if ((data_buffer = (vm_nvram_app_info_ext_list_t *)_vm_kernel_malloc(sizeof(vm_nvram_app_info_ext_list_t))) != NULL)
    	{
		memset(data_buffer, 0x00, sizeof(vm_nvram_app_info_ext_list_t));
		if (vm_nvram_get_app_info_list(data_buffer) == TRUE)
		{
			if (( result = vm_nvram_set_app_info_list(app_info_ext_list_ptr)) == FALSE)
			{
				vm_nvram_set_app_info_list(data_buffer);
			}
		}
		_vm_kernel_free(data_buffer);
		data_buffer = NULL;
    	}
	return result;
}


static VMINT vm_nvram_get_charge_detail_list(vm_nvram_charge_detail_list_t * charge_detail_list_ptr)
{
	VMINT isfound = FALSE;
	VMUINT16 len = sizeof(vm_nvram_charge_detail_list_t);

	if (charge_detail_list_ptr != NULL)
	{
		isfound = vm_nvram_read_record(
			NVRAM_EF_VRE_CHARGE_DETAIL_LIST_EXT_LID,
			1,
			NVRAM_EF_VRE_CHARGE_DETAIL_LIST_EXT_SIZE,
			(void *)charge_detail_list_ptr,
			len);
	}
	else
	{
		vm_log_debug("vm_get_charge_detail_list : charge_detail_list_ptr is NULL");
	}
	return isfound;
}

static VMINT vm_nvram_set_charge_detail_list(vm_nvram_charge_detail_list_t * charge_detail_list_ptr)
{
	VMINT saved = FALSE;
	VMUINT16 len = sizeof(vm_nvram_charge_detail_list_t);

	if (charge_detail_list_ptr != NULL)
	{
		saved = vm_nvram_write_record(
			NVRAM_EF_VRE_CHARGE_DETAIL_LIST_EXT_LID,
			1,
			NVRAM_EF_VRE_CHARGE_DETAIL_LIST_EXT_SIZE,
			(void *)charge_detail_list_ptr,
			len);
	}
	else
	{
		vm_log_debug("vm_nvram_set_charge_detail_list : charge_detail_list_ptr is NULL");
	}
	return saved;
}

VMINT vm_get_charge_detail_list(vm_nvram_charge_detail_list_t * charge_detail_list_ptr)
{
	return vm_nvram_get_charge_detail_list(charge_detail_list_ptr);
}

VMINT vm_set_charge_detail_list(vm_nvram_charge_detail_list_t * charge_detail_list_ptr)
{
	return vm_nvram_set_charge_detail_list(charge_detail_list_ptr);
}

static VMINT vm_nvram_get_charge_sms_detail_list(vm_nvram_charge_sms_detail_list_t * charge_sms_detail_list_ptr)
{
	VMINT isfound = FALSE;
	VMUINT16 len = sizeof(vm_nvram_charge_sms_detail_list_t);

	if (charge_sms_detail_list_ptr != NULL)
	{
		isfound = vm_nvram_read_record(
			NVRAM_EF_VRE_CHARGE_SMS_DETAIL_LIST_EXT_LID,
			1,
			NVRAM_EF_VRE_CHARGE_SMS_DETAIL_LIST_EXT_SIZE,
			(void *)charge_sms_detail_list_ptr,
			len);
	}
	else
	{
		vm_log_debug("vm_nvram_get_charge_sms_detail_list : charge_sms_detail_list_ptr is NULL");
	}
	return isfound;
}

static VMINT vm_nvram_set_charge_sms_detail_list(vm_nvram_charge_sms_detail_list_t * charge_sms_detail_list_ptr)
{
	VMINT saved = FALSE;
	VMUINT16 len = sizeof(vm_nvram_charge_sms_detail_list_t);

	if (charge_sms_detail_list_ptr != NULL)
	{
		saved = vm_nvram_write_record(
			NVRAM_EF_VRE_CHARGE_SMS_DETAIL_LIST_EXT_LID,
			1,
			NVRAM_EF_VRE_CHARGE_SMS_DETAIL_LIST_EXT_SIZE,
			(void *)charge_sms_detail_list_ptr,
			len);
	}
	else
	{
		vm_log_debug("vm_nvram_set_charge_sms_detail_list : charge_sms_detail_list_ptr is NULL");
	}
	return saved;
}

VMINT vm_get_charge_sms_detail_list(vm_nvram_charge_sms_detail_list_t * charge_sms_detail_list_ptr)
{
	return vm_nvram_get_charge_sms_detail_list(charge_sms_detail_list_ptr);
}

VMINT vm_set_charge_sms_detail_list(vm_nvram_charge_sms_detail_list_t * charge_sms_detail_list_ptr)
{
	return vm_nvram_set_charge_sms_detail_list(charge_sms_detail_list_ptr);
}

static VMINT vm_nvram_get_pay_config(vm_pay_config_t * pay_config_ptr)
{
	VMINT isfound = FALSE;
	VMUINT16 len = sizeof(vm_pay_config_t);

	if (pay_config_ptr != NULL)
	{
		isfound = vm_nvram_read_record(
			NVRAM_EF_VRE_PAY_CONFIG_EXT_LID,
			1,
			NVRAM_EF_VRE_PAY_CONFIG_EXT_SIZE,
			(void *)pay_config_ptr,
			len);
			
		/*
		if (isfound)
		{
			vm_log_debug(
				"reserved=%d, sms_notification_flag=%d, update_interval_days=%d, user_balance=%d",
				pay_config_ptr->reserved,
				pay_config_ptr->sms_notification_flag,
				pay_config_ptr->update_interval_days,
				pay_config_ptr->user_balance
				);
		}
		*/
	}
	else
	{
		vm_log_debug("vm_nvram_get_pay_config : pay_config_ptr is NULL");
	}
	return isfound;
}

static VMINT vm_nvram_set_pay_config(vm_pay_config_t * pay_config_ptr)
{
	VMINT saved = FALSE;
	VMUINT16 len = sizeof(vm_pay_config_t);

	if (pay_config_ptr != NULL)
	{
		saved = vm_nvram_write_record(
			NVRAM_EF_VRE_PAY_CONFIG_EXT_LID,
			1,
			NVRAM_EF_VRE_PAY_CONFIG_EXT_SIZE,
			(void *)pay_config_ptr,
			len);
		
		/*
		vm_log_debug(
			"reserved=%d, sms_notification_flag=%d, update_interval_days=%d, user_balance=%d",
			pay_config_ptr->reserved,
			pay_config_ptr->sms_notification_flag,
			pay_config_ptr->update_interval_days,
			pay_config_ptr->user_balance
			);
			*/
	}
	else
	{
		vm_log_debug("vm_nvram_set_pay_config : pay_config_ptr is NULL");
	}
	return saved;
}

VMINT vm_get_pay_config(vm_pay_config_t * pay_config_ptr)
{
	return vm_nvram_get_pay_config(pay_config_ptr);
}

VMINT vm_set_pay_config(vm_pay_config_t * pay_config_ptr)
{
	return vm_nvram_set_pay_config(pay_config_ptr);
}

VMINT vm_nvram_get_operator_code(vm_nvram_operator_code_list_t * operator_code_list_ptr)
{
	VMINT isfound = FALSE;
	VMUINT16 len = sizeof(vm_nvram_operator_code_list_t);

	if (operator_code_list_ptr != NULL)
	{
		isfound = vm_nvram_read_record(
			NVRAM_EF_VRE_OPERATOR_CODE_EXT_LID,
			1,
			NVRAM_EF_VRE_OPERATOR_CODE_EXT_SIZE,
			(void *)operator_code_list_ptr,
			len);
	}
	else
	{
		vm_log_debug("vm_nvram_get_operator_code : operator_code_list_ptr is NULL");
	}
	return isfound;

}

VMINT vm_nvram_set_operator_code(vm_nvram_operator_code_list_t * operator_code_list_ptr)
{
	VMINT saved = FALSE;
	VMUINT16 len = sizeof(vm_nvram_operator_code_list_t);

	if (operator_code_list_ptr != NULL)
	{
		saved = vm_nvram_write_record(
			NVRAM_EF_VRE_OPERATOR_CODE_EXT_LID,
			1,
			NVRAM_EF_VRE_OPERATOR_CODE_EXT_SIZE,
			(void *)operator_code_list_ptr,
			len);
	}
	else
	{
		vm_log_debug("vm_nvram_set_operator_code : operator_code_list_ptr is NULL");
	}
	return saved;
}


VMINT vm_get_operator_code(vm_nvram_operator_code_list_t * operator_code_list_ptr)
{
	return vm_nvram_get_operator_code(operator_code_list_ptr);
}

VMINT vm_set_operator_code(vm_nvram_operator_code_list_t * operator_code_list_ptr)
{
	return vm_nvram_set_operator_code(operator_code_list_ptr);
}



VMINT vm_nvram_get_operator_code_ext(VMINT index, vm_nvram_operator_code_list_t * operator_code_list_ptr)
{
	VMINT isfound = FALSE;
	VMUINT16 len = 3 * sizeof(vm_nvram_operator_code_list_t);
	VMUINT16 len_per_list = sizeof(vm_nvram_operator_code_list_t);

	vm_nvram_operator_code_list_t * operatelist_ptr;

	if ((operator_code_list_ptr == NULL) || (index>3)|| (index <0))
		return FALSE;

	if (index == 0)
		return vm_get_operator_code(operator_code_list_ptr);

	operatelist_ptr = vm_calloc(3 * sizeof(vm_nvram_operator_code_list_t));

	if (operatelist_ptr == NULL)
		return FALSE;
	

	if (operatelist_ptr != NULL)
	{
		isfound = vm_nvram_read_record(
			NVRAM_EF_VRE_OPERATOR_CODE_234_EXT_LID,
			1,
			NVRAM_EF_VRE_OPERATOR_CODE_234_EXT_SIZE,
			(void *)operatelist_ptr,
			len);

		memcpy(operator_code_list_ptr, (VMUINT8 * )operatelist_ptr + (index-1) * len_per_list, len_per_list);

		vm_free(operatelist_ptr);
	}
	else
	{
		vm_log_debug("vm_nvram_get_operator_code : operator_code_list_ptr is NULL");
	}
	return isfound;

}

VMINT vm_nvram_get_operator_code_ext_init(vm_nvram_operator_code_list_t * operatelist_ptr);
VMINT vm_nvram_set_operator_code_ext(VMINT index, vm_nvram_operator_code_list_t * operator_code_list_ptr)
{
	VMINT saved = FALSE;
	VMUINT16 len = 3 * sizeof(vm_nvram_operator_code_list_t);
	VMUINT16 len_per_list = sizeof(vm_nvram_operator_code_list_t);	
	vm_nvram_operator_code_list_t * operatelist_ptr;

	if ((operator_code_list_ptr == NULL) || (index>3) || (index <0))
		return FALSE;
	if (index == 0)
		return vm_set_operator_code(operator_code_list_ptr);
	
	/*read record form 234*/
	operatelist_ptr = vm_calloc(len);
	if (operatelist_ptr == NULL)
		return FALSE;	
	
	/*if (vm_nvram_get_operator_code_ext(1,operatelist_ptr) == FALSE)
	{
		vm_free(operatelist_ptr);
		return FALSE;		
	}
	if (vm_nvram_get_operator_code_ext(2,(vm_nvram_operator_code_list_t *)(operatelist_ptr+len_per_list)) == FALSE)
	{
		vm_free(operatelist_ptr);
		return FALSE;		
	}
	if (vm_nvram_get_operator_code_ext(3,(vm_nvram_operator_code_list_t *)(operatelist_ptr+len_per_list * 2)) == FALSE)
	{
		vm_free(operatelist_ptr);
		return FALSE;		
	}*/
		
	vm_nvram_get_operator_code_ext_init(operatelist_ptr);
	/*memcpy to record's mem*/
	memcpy((VMUINT8 * )operatelist_ptr + (index-1) * len_per_list, operator_code_list_ptr,len_per_list);
	


	/*save to nvram*/
	if (operator_code_list_ptr != NULL)
	{
		saved = vm_nvram_write_record(
			NVRAM_EF_VRE_OPERATOR_CODE_234_EXT_LID,
			1,
			NVRAM_EF_VRE_OPERATOR_CODE_234_EXT_SIZE,
			(void *)operatelist_ptr,
			len);
	}
	else
	{
		vm_log_debug("vm_nvram_set_operator_code : operator_code_list_ptr is NULL");
	}

	vm_free(operatelist_ptr);
	return saved;
}


VMINT vm_get_operator_code_ext(VMINT index, vm_nvram_operator_code_list_t * operator_code_list_ptr)
{
	return vm_nvram_get_operator_code_ext(index, operator_code_list_ptr);
}

VMINT vm_set_operator_code_ext(VMINT index,vm_nvram_operator_code_list_t * operator_code_list_ptr)
{
	return vm_nvram_set_operator_code_ext(index, operator_code_list_ptr);
}



VMINT vm_nvram_set_local_apn_info(vm_local_info * local_info_ptr)
{
	VMINT saved = FALSE;
	VMUINT16 len = sizeof(vm_local_info);

	if (local_info_ptr != NULL)
	{
		saved = vm_nvram_write_record(
			NVRAM_EF_VRE_LOCAL_APN_INFO_EXT_LID,
			1,
			NVRAM_EF_VRE_LOCAL_APN_INFO_EXT_SIZE,
			(void *)local_info_ptr,
			len);
	}
	else
	{
		vm_log_debug("vm_nvram_set_local_apn_info : local_info_ptr is NULL");
	}
	return saved;
}

VMINT vm_nvram_get_local_apn_info(vm_local_info * local_info_ptr)
{
	VMINT isfound = FALSE;
	VMUINT16 len = sizeof(vm_local_info);

	if (local_info_ptr != NULL)
	{
		isfound = vm_nvram_read_record(
			NVRAM_EF_VRE_LOCAL_APN_INFO_EXT_LID,
			1,
			NVRAM_EF_VRE_LOCAL_APN_INFO_EXT_SIZE,
			(void *)local_info_ptr,
			len);
	}
	else
	{
		vm_log_debug("vm_nvram_get_local_apn_info : local_info_ptr is NULL");
	}
	return isfound;
}

VMINT vm_set_local_apn_info(vm_local_info * local_info_ptr)
{
	return vm_nvram_set_local_apn_info(local_info_ptr);
}

VMINT vm_get_local_apn_info(vm_local_info * local_info_ptr)
{
	return vm_nvram_get_local_apn_info(local_info_ptr);
}



VMINT vm_nvram_set_user_apn_info(vm_apn_info * apn_info_ptr)
{
	VMINT saved = FALSE;
	VMUINT16 len = sizeof(vm_apn_info);

	if (apn_info_ptr != NULL)
	{
		saved = vm_nvram_write_record(
			NVRAM_EF_VRE_USER_APN_INFO_LID,
			1,
			NVRAM_EF_VRE_USER_APN_INFO_SIZE,
			(void *)apn_info_ptr,
			len);
	}
	else
	{
		vm_log_debug("vm_nvram_set_user_apn_info : apn_info_ptr is NULL");
	}
	return saved;
}

VMINT vm_nvram_get_user_apn_info(vm_apn_info * apn_info_ptr)
{
	VMINT isfound = FALSE;
	VMUINT16 len = sizeof(vm_apn_info);

	if (apn_info_ptr != NULL)
	{
		isfound = vm_nvram_read_record(
			NVRAM_EF_VRE_USER_APN_INFO_LID,
			1,
			NVRAM_EF_VRE_USER_APN_INFO_SIZE,
			(void *)apn_info_ptr,
			len);
	}
	else
	{
		vm_log_debug("vm_nvram_get_user_apn_info : apn_info_ptr is NULL");
	}
	return isfound;
}
VMINT vm_set_user_apn_info(vm_apn_info * apn_info_ptr)
{
	return vm_nvram_set_user_apn_info(apn_info_ptr);
}

VMINT vm_get_user_apn_info(vm_apn_info * apn_info_ptr)
{
	return vm_nvram_get_user_apn_info(apn_info_ptr);
}




VMINT vm_nvram_set_pay_notification(vm_pay_notification_t * pay_notification_ptr)
{
	VMINT saved = FALSE;
	VMUINT16 len = sizeof(vm_pay_notification_t);

	if (pay_notification_ptr != NULL)
	{
		saved = vm_nvram_write_record(
			NVRAM_EF_VRE_PAY_NOTIFICATION_EXT_LID,
			1,
			NVRAM_EF_VRE_PAY_NOTIFICATION_EXT_SIZE,
			(void *)pay_notification_ptr,
			len);
	}
	else
	{
		vm_log_debug("vm_nvram_set_pay_notification : pay_notification_ptr is NULL");
	}
	return saved;
}

VMINT vm_nvram_get_pay_notification(vm_pay_notification_t * pay_notification_ptr)
{
	VMINT isfound = FALSE;
	VMUINT16 len = sizeof(vm_pay_notification_t);

	if (pay_notification_ptr != NULL)
	{
		isfound = vm_nvram_read_record(
			NVRAM_EF_VRE_PAY_NOTIFICATION_EXT_LID,
			1,
			NVRAM_EF_VRE_PAY_NOTIFICATION_EXT_SIZE,
			(void *)pay_notification_ptr,
			len);
	}
	else
	{
		vm_log_debug("vm_nvram_get_pay_notification : pay_notification_ptr is NULL");
	}
	return isfound;
}

VMINT vm_set_pay_notification(vm_pay_notification_t * pay_notification_ptr)
{
	return vm_nvram_set_pay_notification(pay_notification_ptr);
}

VMINT vm_get_pay_notification(vm_pay_notification_t * pay_notification_ptr)
{
	return vm_nvram_get_pay_notification(pay_notification_ptr);
}

VMINT vm_nvram_set_paychannel_usage_list(vm_nvram_paychannel_usage_list_t * paychannel_usage_list_ptr)
{
	VMINT saved = FALSE;
	VMUINT16 len = sizeof(vm_nvram_paychannel_usage_list_t);

	if (paychannel_usage_list_ptr != NULL)
	{
		saved = vm_nvram_write_record(
			NVRAM_EF_VRE_PAYCHANNEL_USAGE_EXT_LID,
			1,
			NVRAM_EF_VRE_PAYCHANNEL_USAGE_EXT_SZIE,
			(void *)paychannel_usage_list_ptr,
			len);
	}
	else
	{
		vm_log_debug("vm_nvram_set_paychannel_usage_list : paychannel_usage_list_ptr is NULL");
	}
	return saved;
}

VMINT vm_nvram_get_paychannel_usage_list(vm_nvram_paychannel_usage_list_t * paychannel_usage_list_ptr)
{
	VMINT isfound = FALSE;
	VMUINT16 len = sizeof(vm_nvram_paychannel_usage_list_t);

	if (paychannel_usage_list_ptr != NULL)
	{
		isfound = vm_nvram_read_record(
			NVRAM_EF_VRE_PAYCHANNEL_USAGE_EXT_LID,
			1,
			NVRAM_EF_VRE_PAYCHANNEL_USAGE_EXT_SZIE,
			(void *)paychannel_usage_list_ptr,
			len);
	}
	else
	{
		vm_log_debug("vm_nvram_get_paychannel_usage_list : paychannel_usage_list_ptr is NULL");
	}
	return isfound;
}

VMINT vm_set_paychannel_usage_list(vm_nvram_paychannel_usage_list_t * paychannel_usage_list_ptr)
{
	return vm_nvram_set_paychannel_usage_list(paychannel_usage_list_ptr);
}

VMINT vm_get_paychannel_usage_list(vm_nvram_paychannel_usage_list_t * paychannel_usage_list_ptr)
{
	return vm_nvram_get_paychannel_usage_list(paychannel_usage_list_ptr);
}


static VMINT vm_nvram_get_charge_detail_list_ext(vm_nvram_charge_detail_list_ext_t * charge_detail_list_ext_ptr)
{
	VMINT isfound = FALSE;
	VMUINT16 len = sizeof(vm_nvram_charge_detail_list_ext_t);

	if (charge_detail_list_ext_ptr != NULL)
	{
		isfound = vm_nvram_read_record(
			NVRAM_EF_VRE_CHARGE_DETAIL_LIST_EXT_EXT_LID,
			1,
			NVRAM_EF_VRE_CHARGE_DETAIL_LIST_EXT_EXT_SIZE,
			(void *)charge_detail_list_ext_ptr,
			len);
	}
	else
	{
		vm_log_debug("vm_nvram_get_charge_detail_list_ext : charge_sms_detail_list_ptr is NULL");
	}
	return isfound;
	
}

static VMINT vm_nvram_set_charge_detail_list_ext(vm_nvram_charge_detail_list_ext_t * charge_detail_list_ext_ptr)
{
	VMINT saved = FALSE;
	VMUINT16 len = sizeof(vm_nvram_charge_detail_list_ext_t);

	if (charge_detail_list_ext_ptr != NULL)
	{
		saved = vm_nvram_write_record(
			NVRAM_EF_VRE_CHARGE_DETAIL_LIST_EXT_EXT_LID,
			1,
			NVRAM_EF_VRE_CHARGE_DETAIL_LIST_EXT_EXT_SIZE,
			(void *)charge_detail_list_ext_ptr,
			len);
	}
	else
	{
		vm_log_debug("vm_nvram_set_charge_detail_list_ext : charge_sms_detail_list_ptr is NULL");
	}
	return saved;
	
}

static VMINT vm_nvram_get_pay_config_ext(vm_pay_config_ext_t * pay_config_ext_ptr)
{
	VMINT isfound = FALSE;
	VMUINT16 len = sizeof(vm_pay_config_ext_t);

	if (pay_config_ext_ptr != NULL)
	{
		isfound = vm_nvram_read_record(
			NVRAM_EF_VRE_PAY_CONFIG_EXT_EXT_LID,
			1,
			NVRAM_EF_VRE_PAY_CONFIG_EXT_EXT_SIZE,
			(void *)pay_config_ext_ptr,
			len);
	
	}
	else
	{
		vm_log_debug("vm_nvram_get_pay_config_ext : pay_config_ptr is NULL");
	}
	return isfound;	
	
}

static VMINT vm_nvram_set_pay_config_ext(vm_pay_config_ext_t * pay_config_ext_ptr)
{
	VMINT saved = FALSE;
	VMUINT16 len = sizeof(vm_pay_config_ext_t);

	if (pay_config_ext_ptr != NULL)
	{
		saved = vm_nvram_write_record(
			NVRAM_EF_VRE_PAY_CONFIG_EXT_EXT_LID,
			1,
			NVRAM_EF_VRE_PAY_CONFIG_EXT_EXT_SIZE,
			(void *)pay_config_ext_ptr,
			len);
	
	}
	else
	{
		vm_log_debug("vm_nvram_set_pay_config_ext : pay_config_ptr is NULL");
	}
	return saved;
}

VMINT vm_get_charge_detail_list_ext(vm_nvram_charge_detail_list_ext_t * charge_detail_list_ext_ptr)

{
	return vm_nvram_get_charge_detail_list_ext(charge_detail_list_ext_ptr);
}

VMINT vm_set_charge_detail_list_ext(vm_nvram_charge_detail_list_ext_t * charge_detail_list_ext_ptr)
{
	return vm_nvram_set_charge_detail_list_ext(charge_detail_list_ext_ptr);
}

VMINT vm_get_pay_config_ext(vm_pay_config_ext_t * pay_config_ext_ptr)
{
	return vm_nvram_get_pay_config_ext(pay_config_ext_ptr);
}

VMINT vm_set_pay_config_ext(vm_pay_config_ext_t * pay_config_ext_ptr)
{
	return vm_nvram_set_pay_config_ext(pay_config_ext_ptr);

}

VMINT vm_nvram_get_operator_code_ext_init(vm_nvram_operator_code_list_t * operatelist_ptr)
{
	VMINT isfound = FALSE;
	VMUINT16 len = 3 * sizeof(vm_nvram_operator_code_list_t);

	
	if (operatelist_ptr != NULL)
	{
		isfound = vm_nvram_read_record(
			NVRAM_EF_VRE_OPERATOR_CODE_234_EXT_LID,
			1,
			NVRAM_EF_VRE_OPERATOR_CODE_234_EXT_SIZE,
			(void *)operatelist_ptr,
			len);

	
	}
	else
	{
		vm_log_debug("vm_nvram_get_operator_code_ext_init : operator_code_list_ptr is NULL");
	}
	return isfound;

}

VMINT vm_nvram_set_operator_code_ext_init(vm_nvram_operator_code_list_t * operatelist_ptr)
{
	VMINT saved = FALSE;
	VMUINT16 len = 3 * sizeof(vm_nvram_operator_code_list_t);
	

	/*save to nvram*/
	if (operatelist_ptr != NULL)
	{
		saved = vm_nvram_write_record(
			NVRAM_EF_VRE_OPERATOR_CODE_234_EXT_LID,
			1,
			NVRAM_EF_VRE_OPERATOR_CODE_234_EXT_SIZE,
			(void *)operatelist_ptr,
			len);
	}
	else
	{
		vm_log_debug("vm_nvram_set_operator_code_ext_init : operatelist_ptr is NULL");
	}

	return saved;
}



void vm_nvram_re_encrypt(void)
{
	void * data_buffer = NULL;
	if ((data_buffer = (vm_nvram_root_pkey_list_t *)_vm_kernel_malloc(sizeof(vm_nvram_root_pkey_list_t))) != NULL)
	{
	    	if (vm_nvram_get_pkey_list(0, (vm_nvram_root_pkey_list_t *)data_buffer) == TRUE)
	    	{
			vm_nvram_set_pkey_list(0, (vm_nvram_root_pkey_list_t *)data_buffer);
	    	}
		_vm_kernel_free(data_buffer);
		data_buffer = NULL;		
		vm_log_debug("r/w the first pkey list");
	}

	if ((data_buffer = (vm_nvram_root_pkey_list_t *)_vm_kernel_malloc(sizeof(vm_nvram_root_pkey_list_t))) != NULL)
	{
	    	if (vm_nvram_get_pkey_list(1, (vm_nvram_root_pkey_list_t *)data_buffer) == TRUE)
	    	{
			vm_nvram_set_pkey_list(1, (vm_nvram_root_pkey_list_t *)data_buffer);
	    	}
		_vm_kernel_free(data_buffer);
		data_buffer = NULL;	
		vm_log_debug("r/w the second pkey list");
	}

    	if ((data_buffer = (vm_nvram_permission_list_t *)_vm_kernel_malloc(sizeof(vm_nvram_permission_list_t))) != NULL)
    	{
	    	if (vm_nvram_get_sym_permission((vm_nvram_permission_list_t *)data_buffer) == TRUE)
	    	{
			vm_nvram_set_sym_permission((vm_nvram_permission_list_t *)data_buffer);
	    	}
		_vm_kernel_free(data_buffer);
		data_buffer = NULL;
		vm_log_debug("r/w the permission list");
    	}
    	
    	//NVRAM_EF_VRE_APP_BAN_LIST_LID,
	if ((data_buffer = (vm_nvram_app_ban_list_t *)_vm_kernel_malloc(sizeof(vm_nvram_app_ban_list_t))) != NULL)
	{
		memset(data_buffer, 0x00, sizeof(vm_nvram_app_ban_list_t));
		vm_nvram_set_ban_list(data_buffer);
		_vm_kernel_free(data_buffer);
		data_buffer = NULL;
		vm_log_debug("r/w the ban list");
	}
	
    	//NVRAM_EF_VRE_SYM_CONF_LIST_LID,
    	if ((data_buffer = (vm_nvram_sysconf_t *)_vm_kernel_malloc(sizeof(vm_nvram_sysconf_t))) != NULL)
    	{
		memset(data_buffer, 0x00, sizeof(vm_nvram_sysconf_t));
		vm_nvram_set_sysconf(data_buffer);
		_vm_kernel_free(data_buffer);
		data_buffer = NULL;
		vm_log_debug("r/w the sysconf list");
    	}  	
	
    	//NVRAM_EF_VRE_APPSTORE_CONFIG_LIST_LID,
    	if ((	data_buffer = (vm_nvram_appstore_config_t *)_vm_kernel_malloc(sizeof(vm_nvram_appstore_config_t))) != NULL)
    	{
		memset(data_buffer, 0x00, sizeof(vm_nvram_appstore_config_t));
		vm_nvram_set_appstore_config(data_buffer);
		_vm_kernel_free(data_buffer);
		data_buffer = NULL;
		vm_log_debug("r/w the as config list");
    	}
	
	//NVRAM_EF_VRE_APPSTORE3_CONFIG_LIST_LID
	if ((data_buffer = (vm_nvram_appstore3_config_t *)_vm_kernel_malloc(sizeof(vm_nvram_appstore3_config_t))) != NULL)
	{
		memset(data_buffer, 0x00, sizeof(vm_nvram_appstore3_config_t));
		vm_nvram_set_appstore3_config(data_buffer);
		_vm_kernel_free(data_buffer);
		data_buffer = NULL;
		vm_log_debug("r/w the as3 config list");
	}	

	//计费相关数据初始化
	if ((data_buffer = (vm_nvram_paychannel_list_ext_t *)_vm_kernel_malloc(sizeof(vm_nvram_paychannel_list_ext_t))) != NULL)
    	{
    		vm_log_debug("will get paychannel ptr=%p", data_buffer);
	    	if (vm_nvram_get_paychannel_list_ext((vm_nvram_paychannel_list_ext_t *)data_buffer) == TRUE)
	    	{
			vm_nvram_set_paychannel_list_ext((vm_nvram_paychannel_list_ext_t *)data_buffer);
	    	}
		_vm_kernel_free(data_buffer);
		data_buffer = NULL;
		vm_log_debug("r/w the paychannel list, %d", sizeof(vm_nvram_paychannel_list_ext_t));
    	}

	if ((data_buffer = (vm_nvram_paychannel_a_list_ext_t *)_vm_kernel_malloc(sizeof(vm_nvram_paychannel_a_list_ext_t))) != NULL)
    	{
    		vm_log_debug("will get paychannel_a ptr=%p", data_buffer);
	    	if (vm_nvram_get_paychannel_a_list_ext((vm_nvram_paychannel_a_list_ext_t *)data_buffer) == TRUE)
	    	{
			vm_nvram_set_paychannel_a_list_ext((vm_nvram_paychannel_a_list_ext_t *)data_buffer);
	    	}
		_vm_kernel_free(data_buffer);
		data_buffer = NULL;
		vm_log_debug("r/w the paychannel_a list, %d", sizeof(vm_nvram_paychannel_a_list_ext_t));
    	}	

	if ((data_buffer = (vm_nvram_operator_code_list_t *)_vm_kernel_malloc(sizeof(vm_nvram_operator_code_list_t))) != NULL)
    	{
    		vm_log_debug("will get operatecode ptr=%p", data_buffer);
	    	if (vm_get_operator_code((vm_nvram_operator_code_list_t *)data_buffer) == TRUE)
	    	{
			vm_set_operator_code((vm_nvram_operator_code_list_t *)data_buffer);
	    	}
		_vm_kernel_free(data_buffer);
		data_buffer = NULL;
		vm_log_debug("r/w the operatecode, %d", sizeof(vm_nvram_operator_code_list_t));
    	}

	

	if ((data_buffer = (vm_pay_config_t *)_vm_kernel_malloc(sizeof(vm_pay_config_t))) != NULL)
    	{
    		vm_log_debug("will get pay config ptr=%p", data_buffer);
	    	if (vm_get_pay_config((vm_pay_config_t *)data_buffer) == TRUE)
	    	{
			vm_set_pay_config((vm_pay_config_t *)data_buffer);
	    	}
		_vm_kernel_free(data_buffer);
		data_buffer = NULL;
		vm_log_debug("r/w the pay config, %d", sizeof(vm_pay_config_t));
    	}

    	if ((data_buffer = (vm_nvram_app_info_ext_list_t *)_vm_kernel_malloc(sizeof(vm_nvram_app_info_ext_list_t))) != NULL)
    	{
		memset(data_buffer, 0x00, sizeof(vm_nvram_app_info_ext_list_t));
		vm_nvram_set_app_info_list(data_buffer);
		_vm_kernel_free(data_buffer);
		data_buffer = NULL;
		vm_log_debug("r/w the appstate list");
    	}

	if ((data_buffer = (vm_nvram_charge_detail_list_t *)_vm_kernel_malloc(sizeof(vm_nvram_charge_detail_list_t))) != NULL)
    	{
		memset(data_buffer, 0x00, sizeof(vm_nvram_charge_detail_list_t));
		vm_set_charge_detail_list(data_buffer);
		_vm_kernel_free(data_buffer);
		data_buffer = NULL;
		vm_log_debug("r/w the charge_detail_list");
    	}

	if ((data_buffer = (vm_nvram_charge_sms_detail_list_t *)_vm_kernel_malloc(sizeof(vm_nvram_charge_sms_detail_list_t))) != NULL)
    	{
		memset(data_buffer, 0x00, sizeof(vm_nvram_charge_sms_detail_list_t));
		vm_set_charge_sms_detail_list(data_buffer);
		_vm_kernel_free(data_buffer);
		data_buffer = NULL;
		vm_log_debug("r/w the charge_sms_detail_list");
    	}

	#ifdef VRE_GLOBAL_VERSION
	
	if ((data_buffer = (vm_nvram_operator_code_list_t *)_vm_kernel_malloc(sizeof(vm_nvram_operator_code_list_t)*3)) != NULL)
    	{
    		vm_log_debug("will get operatecode list=%p", data_buffer);
	    	if (vm_nvram_get_operator_code_ext_init((vm_nvram_operator_code_list_t *)data_buffer) == TRUE)
	    	{
				vm_nvram_set_operator_code_ext_init((vm_nvram_operator_code_list_t *)data_buffer);
			
	    	}
			else
			
			{
				vm_log_error("vm_get_operatecode_lis error");
			}
			_vm_kernel_free(data_buffer);
			data_buffer = NULL;
			vm_log_debug("r/w the operatecode_lis, %d", sizeof(vm_nvram_operator_code_list_t)*3);
		}
		
	if ((data_buffer = (vm_local_info *)_vm_kernel_malloc(sizeof(vm_local_info))) != NULL)
	{
		memset(data_buffer, 0x00, sizeof(vm_local_info));
		vm_nvram_set_local_apn_info(data_buffer);
		_vm_kernel_free(data_buffer);
		data_buffer = NULL;
		vm_log_debug("r/w the local_info");
	}

	if ((data_buffer = (vm_apn_info *)_vm_kernel_malloc(sizeof(vm_apn_info))) != NULL)
	{
		memset(data_buffer, 0x00, sizeof(vm_apn_info));
		vm_nvram_set_user_apn_info(data_buffer);
		_vm_kernel_free(data_buffer);
		data_buffer = NULL;
		vm_log_debug("r/w the apn_info");
	}    
	
	if ((data_buffer = (vm_pay_notification_t *)_vm_kernel_malloc(sizeof(vm_pay_notification_t))) != NULL)
	{
		memset(data_buffer, 0x00, sizeof(vm_pay_notification_t));
		vm_nvram_set_pay_notification(data_buffer);
		_vm_kernel_free(data_buffer);
		data_buffer = NULL;
		vm_log_debug("r/w the pay notification");
	}
	
	#endif
	
	if ((data_buffer = (vm_nvram_paychannel_usage_list_t *)_vm_kernel_malloc(sizeof(vm_nvram_paychannel_usage_list_t))) != NULL)
	{
		memset(data_buffer, 0x00, sizeof(vm_nvram_paychannel_usage_list_t));
		vm_nvram_set_paychannel_usage_list(data_buffer);
		_vm_kernel_free(data_buffer);
		data_buffer = NULL;
		vm_log_debug("r/w the set_paychannel_usage_list");
	}

	if ((data_buffer = (vm_nvram_charge_detail_list_ext_t *)_vm_kernel_malloc(sizeof(vm_nvram_charge_detail_list_ext_t))) != NULL)
	{
		memset(data_buffer, 0x00, sizeof(vm_nvram_charge_detail_list_ext_t));
		vm_nvram_set_charge_detail_list_ext(data_buffer);
		_vm_kernel_free(data_buffer);
		data_buffer = NULL;
		vm_log_debug("r/w the vm_nvram_get_charge_detail_list_ext");
	}

	if ((data_buffer = (vm_pay_config_ext_t *)_vm_kernel_malloc(sizeof(vm_pay_config_ext_t))) != NULL)
    	{
    		vm_log_debug("will get  vm_pay_config_ext_t ptr=%p", data_buffer);
	    	if (vm_get_pay_config_ext((vm_pay_config_ext_t *)data_buffer) == TRUE)
	    	{
			vm_set_pay_config_ext((vm_pay_config_ext_t *)data_buffer);
	    	}
		_vm_kernel_free(data_buffer);
		data_buffer = NULL;
		vm_log_debug("r/w the pay vm_pay_config_ext_t, %d", sizeof(vm_pay_config_ext_t));
    	}
	
}



void vm_nvram_init(void)
{
	VMINT result = FALSE;
	VMUINT8 firstflag = 0;	

	vm_log_debug("vm_nvram_init : start");
	/*read first flag from nvram*/
	firstflag = vm_nvram_get_firstflag();
	vm_log_debug("vm_nvram_init : firstflag=0x%x", firstflag);
	/*if it is the first time running, reencrypt the nvram data by running key*/
	if (firstflag == VRE_FIRSTRUNNING)
	{
		//vm_nvram_inti_test();/*for debug*/
		vm_nvram_re_encrypt();
		if (vm_nvram_set_firstflag() >= 0)
		{
			vm_log_debug("vm_nvram_init : have set firstflag");
			result = TRUE;
		}		
	}
	else if (firstflag == VRE_NOT_FIRSTRUNNING)/*else return system*/
	{
		vm_log_debug("vm_nvram_init : firstflag is false");
		result = TRUE;
	}
	else
	{
		result = FALSE;
	}	
	vm_log_debug("vm_nvram_init finish : result=%d", result);
}

/**
 *  以下计费相关接口已废除,仅实现空函数。
 */
VMINT vm_get_app_state_list(vm_nvram_app_info_list_t * app_info_list_ptr)
{
	return vm_get_app_info_list((vm_nvram_app_info_ext_list_t *)app_info_list_ptr);
}

VMINT vm_set_app_state_list(vm_nvram_app_info_list_t * app_info_list_ptr)
{
	return vm_set_app_info_list((vm_nvram_app_info_ext_list_t *)app_info_list_ptr);
}

VMINT vm_set_pay_channel_list(vm_nvram_paychannel_list_t * paychannel_list_ptr)
{
	return FALSE;
}

VMINT vm_get_pay_channel_list(vm_nvram_paychannel_list_t * paychannel_list_ptr)
{
	return FALSE;
}
#endif
