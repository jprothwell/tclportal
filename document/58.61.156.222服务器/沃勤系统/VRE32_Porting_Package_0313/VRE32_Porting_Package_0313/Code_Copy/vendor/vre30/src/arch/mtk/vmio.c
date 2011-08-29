#ifdef __VRE__
#include "mmi_include.h"

#include "vmio.h"
#include "vmchset.h"
#include "vmlog.h"
#include "vmstdlib.h"
#include "vmopt.h"
#include "vmdl.h"
#include "vmfilere.h"
#include "vmsys.h"
#include "vmpromng.h"
#include "vmresmng.h"
#include "vmmod.h"
#include "vmmacrostub.h"
/* ------------------------------------------------------------------------ */
/* 系统函数声明。                                                       */
/* ------------------------------------------------------------------------ */
extern VMINT _vm_get_disk_permission(void);

/* ------------------------------------------------------------------------ */
/* 模块内部变量声明。                                                       */
/* ------------------------------------------------------------------------ */
/*
#ifdef VRE_SYS_DRIVER_REMAPPING
static char *white_list[] = {
	"bill.dat",
	"vre.cfg",
	"vre.log",
	"channel.dat",
	"timestamp.dat",
	"user.dat",
	"vipuser.dat",
	"vre.conf",
	"vmsim.conf",
	"dsm.ini",
	"update.ini"
};
#define WHITE_LIST_NUM	9
#endif
*/
/*
#define FILE_POOL_SIZE 	VRE_SUPPORT_FILE_HANDLE_MAX_NUM

struct file_handle_t 
{
	int used;
	int file;
	int sys_state;
};
*/
/*
  * 文件句柄映射表。
  */
//static struct file_handle_t file_pool[FILE_POOL_SIZE];

/* ------------------------------------------------------------------- */
/* 模块内函数声明。                                                    */
/* ------------------------------------------------------------------- */
/*
#ifdef VRE_SYS_DRIVER_REMAPPING
static VMWSTR file_remap(VMWSTR filename);
static VMINT in_white_list(VMWSTR filename);
#endif
*/

#ifdef VRE_SUPPORT_SECURITY_FEATURE//VRE_IO_REMAP
/*
 * 当前文件的操作权限
 */
extern VMINT	cur_file_sys_per;
/*
 * 文件重定向。
 */
VMINT _vm_remap_usr_disk(VMWSTR dest_filename, VMWSTR source_filename);
#endif

VMINT vm_file_count(void)
{
	VM_P_HANDLE phandle = -1;
	VMINT count = 0;

	phandle = vm_pmng_get_current_handle();
	count = vm_res_get_data_list_count_by_proecss(phandle, VM_RES_TYPE_FILE);
	return count;
}



VMFILE vm_file_open(const VMWSTR filename, VMUINT mode, VMUINT binary) 
{
	VM_P_HANDLE phandle = -1;
	VMINT mtk_file_id = -1;
	VMINT handle = VM_FILE_OPEN_ERROR;
	VMUINT flag = 0;
	//VMCHAR fn[60];

	if (filename == NULL)
	{
		return VM_FILE_NAME_ERROR;
	}

	if (vm_wstrlen(filename) == 0 || vm_wstrlen(filename) > MAX_APP_NAME_LEN)
	{
		return VM_FILE_NAME_ERROR;
	}
	
	//vm_ucs2_to_gb2312(fn, 60, filename);

	phandle = vm_pmng_get_current_handle();
	handle = vm_res_save_data(VM_RES_TYPE_FILE, NULL, 0, NULL, phandle);
	
	//vm_log_debug("vm_file_open  start : mode=%d, phandle=%d, filename=%s", mode, phandle, fn);


	if (handle >= 0) 
	{
		if (mode & MODE_READ)
			flag = FS_READ_ONLY;
		else if (mode & MODE_WRITE)
			flag = FS_READ_WRITE;
		else if (mode & MODE_APPEND)
			flag = FS_READ_WRITE;
		else if (mode & MODE_CREATE_ALWAYS_WRITE)
			flag = FS_CREATE_ALWAYS | FS_READ_WRITE;

		mtk_file_id = FS_Open((WCHAR*)filename, flag);
		if (mtk_file_id >= 0)
		{			
			if (vm_res_set_mtk_reshandle(VM_RES_TYPE_FILE, handle, mtk_file_id) == VM_RES_OK)
			{
				if (mode & MODE_APPEND)
				{
					FS_Seek(mtk_file_id, 0, FS_FILE_END);
				}
			}
			else
			{
				vm_log_debug("vm_file_open : set mtk_file_id error,  mtk_file_id = %d", mtk_file_id);
				FS_Close(mtk_file_id);
				vm_res_release_data(VM_RES_TYPE_FILE, handle);
				handle = VM_FILE_OPEN_ERROR;
			}
		}
		else 
		{
			vm_log_debug("vm_file_open : get mtk_file_id error = %d, <0", mtk_file_id);
			vm_res_release_data(VM_RES_TYPE_FILE, handle);
			handle = VM_FILE_OPEN_ERROR;
		}
	}
	else 
	{
		vm_log_debug("vm_file_open : register res error handle=%d", handle);
		handle = VM_FILE_OPEN_ERROR;
	}
	
	vm_log_debug("vm_file_open:  end mode=%d, phandle=%d, handle=%d", mode, phandle, handle);
	return handle;
	
}

void vm_file_close_in_user_state(void)
{
	/**
	VMINT i = 0;
	for (i = 0; i < FILE_POOL_SIZE; i++) 
	{
		if ((file_pool[i].used == TRUE) && (file_pool[i].sys_state == SYS_STATE_USER)) 
		{
	    		FS_Close(file_pool[i].file);
			file_pool[i].used = FALSE;	
			file_pool[i].sys_state = SYS_STATE_KERNEL;
	  	}
	}**/
}

void vm_file_close_all(void)
{
	VM_P_HANDLE phandle = -1;
	VMINT file_id = VM_RES_NOT_FIND;
	VMINT mtk_file_id = -1;
	
	phandle = vm_pmng_get_current_handle();
	
	while((file_id = vm_res_findfirst(phandle, VM_RES_TYPE_FILE)) != VM_RES_NOT_FIND)
	{
		if (vm_res_get_mtk_reshandle(VM_RES_TYPE_FILE, file_id, &mtk_file_id) == VM_RES_OK)
		{		
			FS_Close(mtk_file_id);
			vm_res_release_data(VM_RES_TYPE_FILE, file_id);
		}
		vm_res_findclose(VM_RES_TYPE_FILE);
	}
	
}

void vm_file_close(VMFILE handle) 
{
	VMINT mtk_file_id = -1;

	vm_log_debug("vm_file_close : start handle=%d", handle);
	
	if (vm_res_get_mtk_reshandle(VM_RES_TYPE_FILE, handle, &mtk_file_id) == VM_RES_OK)
	{
		vm_log_debug("vm_file_close : handle=%d, mtk_file_id=%d", handle, mtk_file_id);
		FS_Close(mtk_file_id);	
		vm_res_release_data(VM_RES_TYPE_FILE, handle);
	}
	
	vm_log_debug("vm_file_close : end handle=%d", handle);
}

VMINT vm_file_read(VMFILE handle, void * data, VMUINT length, VMUINT *nread) 
{
	VMINT mtk_file_id = -1;
	
	if (nread == NULL)
		return 0;

	*nread = 0;
	if (data != NULL)
	{
		if (vm_res_get_mtk_reshandle(VM_RES_TYPE_FILE, handle, &mtk_file_id) == VM_RES_OK)
		{
			if (FS_Read(mtk_file_id, data, length, (UINT *)nread) < FS_NO_ERROR)
			{
				*nread = 0;
			}
		}
	}
	return *nread;
}

VMINT vm_file_write(VMFILE handle, void * data, VMUINT length, VMUINT * written) 
{
	VMINT mtk_file_id = -1;
	
	if(written == NULL)
	{
		return 0;
	}
	
	*written = 0;

	if (data != NULL)
	{
		if (vm_res_get_mtk_reshandle(VM_RES_TYPE_FILE, handle, &mtk_file_id) == VM_RES_OK)
		{
			if (FS_Write(mtk_file_id, data, length, (UINT *)written) < FS_NO_ERROR)
			{
				*written = 0;
			}
		}
	}

	return *written;
}

VMINT vm_file_commit(VMFILE handle) 
{
	VMINT retval = VM_FILE_COMMIT_ERROR;
	VMINT mtk_file_id = -1;

	if (vm_res_get_mtk_reshandle(VM_RES_TYPE_FILE, handle, &mtk_file_id) == VM_RES_OK)
	{
		if (FS_Commit(mtk_file_id) == FS_NO_ERROR)
		{
			retval = VM_FILE_OK;
		}

	}
	return retval;
}

VMINT vm_file_is_eof(VMFILE handle)
{
	VMINT ret = FALSE;
	VMUINT filesize = 0;
	VMINT pos = -1;
	VMINT mtk_file_id = -1;
	if (vm_res_get_mtk_reshandle(VM_RES_TYPE_FILE, handle, &mtk_file_id) == VM_RES_OK)
	{
		pos = FS_Seek(mtk_file_id, 0, FS_FILE_CURRENT);
		//vm_log_debug("vm_file_is_eof : pos=%d", pos);
		FS_GetFileSize(mtk_file_id, &filesize);
		//vm_log_debug("vm_file_is_eof : filesize=%d", filesize);
		if ((VMUINT)pos == (VMUINT)filesize)
			ret = TRUE;
	}
	return ret;
}

VMINT vm_file_tell(VMFILE handle)
{
	VMINT ret = -1;
	VMINT mtk_file_id = -1;
	if (vm_res_get_mtk_reshandle(VM_RES_TYPE_FILE, handle, &mtk_file_id) == VM_RES_OK)
	{
		ret = FS_Seek(mtk_file_id, 0, FS_FILE_CURRENT);
	}
	return ret;
}

VMINT vm_file_seek(VMFILE handle, VMINT offset, VMINT base) 
{
	VMINT origin = 0;
	VMINT retval = -1;

	VMINT head = 0;
	VMINT tail = 0;
	VMINT current = 0;

	VMINT mtk_file_id = -1;


	if (vm_res_get_mtk_reshandle(VM_RES_TYPE_FILE, handle, &mtk_file_id) == VM_RES_OK)
	{
		/*保护现场位置*/
		current = FS_Seek(mtk_file_id, 0, FS_FILE_CURRENT);
		head = FS_Seek(mtk_file_id, 0, FS_FILE_BEGIN);
		tail = FS_Seek(mtk_file_id, 0, FS_FILE_END);

		/*恢复现场位置*/
		current = FS_Seek(mtk_file_id, (head + current), FS_FILE_BEGIN);
		
		if (base == BASE_BEGIN)
		{
			if (((head+offset) > tail) || ((head+offset) < head) )
				return -1;
		}
		else if (base == BASE_END)
		{
			if (((tail+offset) > tail) || ((tail+offset) < head) )
				return -1;
		}
		else if (base == BASE_CURR)
		{
			if (((current+offset) > tail) || ((current+offset) < head) )
				return -1;
		}
		
		switch (base) 
		{
		case BASE_BEGIN:
			origin = FS_FILE_BEGIN;
			break;
		case BASE_CURR:
			origin = FS_FILE_CURRENT;
			break;
		case BASE_END:
			origin = FS_FILE_END;
			break;
		default :
			origin = FS_FILE_BEGIN;
			break;
		}
		 
		retval =  FS_Seek(mtk_file_id, offset, origin) < 0 ? -1 : 0;
	}

	return retval;
}

VMINT vm_file_getfilesize(VMFILE handle, VMUINT *file_size) 
{
	VMINT retval = -1;
	VMINT mtk_file_id = -1;
	if (file_size == NULL)
	{
		return -1;
	}
	
	if (vm_res_get_mtk_reshandle(VM_RES_TYPE_FILE, handle, &mtk_file_id) == VM_RES_OK)
	{
		retval =  FS_GetFileSize(mtk_file_id, (UINT *)file_size);
	}
	return retval;
}

VMINT vm_file_delete(const VMWSTR filename) 
{
	S32  attr = 0;
	VMINT retval = -1;
	if (filename == NULL)
	{
		//vm_log_debug("vm_file_delete : the ptr of filename is NULL");
		return -1;
	}
	if (vm_wstrlen(filename) == 0 || vm_wstrlen(filename) > MAX_APP_NAME_LEN)
	{
		//vm_log_debug("vm_file_delete : the length of filename is error");
		return -1;
	}
	attr = FS_GetAttributes((WCHAR *)filename);
    	if ((attr & FS_ATTR_READ_ONLY))
		FS_SetAttributes((WCHAR *)filename, (U8) (attr & ~(FS_ATTR_READ_ONLY)));

	retval =  FS_Delete((WCHAR *)filename) != FS_NO_ERROR ? -1: 0;
	if (retval != 0)
	{
		//vm_log_debug("vm_file_delete : FS_Delete return error code=%d", retval);
	}
	return retval;
}

VMINT vm_file_rename(const VMWSTR filename, const VMWSTR newname) 
{
	VMINT retval = -1;
	if (filename == NULL || newname == NULL)
	{
		//vm_log_debug("vm_file_rename : the ptr of filename is NULL");
		return -1;
	}
	if (vm_wstrlen(filename) == 0 
		|| vm_wstrlen(filename) > MAX_APP_NAME_LEN
		|| vm_wstrlen(newname) == 0 
		|| vm_wstrlen(newname) > MAX_APP_NAME_LEN
	)
	{
		//vm_log_debug("vm_file_rename : the length of filename is error");
		return -1;
	}
	
	retval =  FS_Rename((WCHAR *)filename, (WCHAR *)newname) != FS_NO_ERROR ? -1: 0;
	if (retval != 0)
	{
		//vm_log_debug("vm_file_rename : FS_Rename return error code=%d", retval);
	}
	return retval;
}


VMINT vm_file_mkdir(const VMWSTR dirname) 
{
	VMINT retval = -1;
	//char fn[128];
	if (dirname == NULL)
	{
		//vm_log_debug("vm_file_mkdir : the ptr of dirname is NULL");
		return -1;
	}
	if (vm_wstrlen(dirname) == 0 || vm_wstrlen(dirname) > MAX_APP_NAME_LEN)
	{
		//vm_log_debug("vm_file_mkdir : the length of dirname is error");
		return -1;
	}

	//memset(fn, 0x00, 128);
	//vm_ucs2_to_gb2312(fn, 128, dirname);
	//vm_log_debug("vm_file_mkdir : %s", fn);
	
	retval =  FS_CreateDir((WCHAR *)dirname) != FS_NO_ERROR ? -1: 0;
	if (retval != 0)
	{
		//vm_log_debug("vm_file_mkdir : FS_CreateDir return error code=%d", retval);
	}
	return retval;
}

VMINT vm_file_rmdir(const VMWSTR dirname) 
{
	VMINT retval = -1;
	if (dirname == NULL)
	{
		//vm_log_debug("vm_file_rmdir : the ptr of dirname is NULL");
		return -1;
	}
	if (vm_wstrlen(dirname) == 0 || vm_wstrlen(dirname) > MAX_APP_NAME_LEN)
	{
		//vm_log_debug("vm_file_rmdir : the length of dirname is error");
		return -1;
	}
	
	//retval =  FS_RemoveDir((WCHAR *)dirname) != FS_NO_ERROR ? -1: 0;
	retval= FS_XDelete(
                (const WCHAR *)dirname,
                FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE,
                NULL,
                0) < 0 ? -1:0;
	
	if (retval < 0)
	{
		//vm_log_debug("vm_file_rmdir : FS_RemoveDir return error code=%d", retval);
	}
	return retval;
}

VMINT vm_file_set_attributes(const VMWSTR filename, VMBYTE attributes)
{
	VMINT res = -1;
	if (filename == NULL)
		return -1;
	
	res = FS_SetAttributes((WCHAR *)filename, attributes);
	if (res != FS_NO_ERROR)
		res = -1;
	else
		res = 0;
	return res;
}

VMINT vm_file_get_attributes(const VMWSTR filename)
{
	VMINT res = -1;
	if (filename == NULL)
		return -1;

	res = FS_GetAttributes((WCHAR *)filename);
	if (res < 0 )
		return -1;
	return res;
}

VMINT vm_find_first_ext(VMWSTR pathname, vm_fileinfo_ext * direntry)  
{
	VMINT handle;
	VMINT mtk_handle;
	FS_DOSDirEntry	file_info;
	VM_P_HANDLE phandle = -1;
	
	
	//VMCHAR fn[128];
	//vm_log_fatal("vm_find_first");
	
	if (pathname == NULL || direntry == NULL)
	{
		//vm_log_debug("vm_find_first_ext : the ptr of pathname or info is NULL");
		return -1;
	}
	if (vm_wstrlen(pathname) == 0 || vm_wstrlen(pathname) > MAX_APP_NAME_LEN)
	{
		//vm_log_debug("vm_find_first_ext : the length of pathname is error");
		return -1;
	}	

	phandle = vm_pmng_get_current_handle();
	handle = vm_res_save_data(VM_RES_TYPE_FILE_FIND, NULL, 0, NULL,  phandle);
	if (handle < 0)
	{
		return -1;
	}
	
	memset(direntry, 0x00, sizeof(vm_fileinfo_ext));
	mtk_handle = FS_FindFirst((WCHAR *)pathname, 0, 0, &file_info, (WCHAR *)(direntry->filefullname), MAX_APP_NAME_LEN * 2);
	if (mtk_handle >= 0) 
	{
		//vm_ucs2_to_gb2312((VMSTR)fn, 100, (VMWCHAR *)(direntry->filefullname));
		////vm_log_debug("vm_find_first_ext : FS_FindFirst return success handle=%d, filename=%s ", handle, fn);
		if (vm_res_set_mtk_reshandle(VM_RES_TYPE_FILE_FIND, handle, mtk_handle) == VM_RES_OK)
		{
			
			memcpy((VMCHAR *)(direntry->filename), (VMCHAR *)(file_info.FileName), 8);
			memcpy((VMCHAR *)(direntry->extension), (VMCHAR *)(file_info.Extension), 3);
			direntry->attributes = file_info.Attributes;
			direntry->filesize = file_info.FileSize;
#if (!defined(__VRE_RB_08A__) && !defined(__VRE_RB_08B__))
			direntry->drive = file_info.Drive;
			direntry->stamp = file_info.Stamp;
#endif
			direntry->create_datetime.year = 1980 + file_info.CreateDateTime.Year1980;
			direntry->create_datetime.mon = file_info.CreateDateTime.Month;
			direntry->create_datetime.day = file_info.CreateDateTime.Day;
			direntry->create_datetime.hour = file_info.CreateDateTime.Hour;
			direntry->create_datetime.min = file_info.CreateDateTime.Minute;
			direntry->create_datetime.sec = file_info.CreateDateTime.Second2 * 2;
			
			direntry->modify_datetime.year = 1980 + file_info.DateTime.Year1980;
			direntry->modify_datetime.mon = file_info.DateTime.Month;
			direntry->modify_datetime.day = file_info.DateTime.Day;
			direntry->modify_datetime.hour = file_info.DateTime.Hour;
			direntry->modify_datetime.min = file_info.DateTime.Minute;
			direntry->modify_datetime.sec = file_info.DateTime.Second2 * 2;
		}
		else
		{
			FS_FindClose(mtk_handle);
			vm_res_release_data(VM_RES_TYPE_FILE_FIND, handle);
			memset(direntry, 0x00, sizeof(vm_fileinfo_ext));
			handle = -1;
		}
	}
	else
	{
		//info->size = 0;
		vm_res_release_data(VM_RES_TYPE_FILE_FIND, handle);
		memset(direntry, 0x00, sizeof(vm_fileinfo_ext));
		handle = -1;
		//vm_log_debug("vm_find_first_ext : FS_FindFirst return handle=%d is error", handle);
	}
	return handle;
}

VMINT vm_find_next_ext(VMINT handle, vm_fileinfo_ext * direntry)
{
	VMINT retval = -1;
	FS_DOSDirEntry file_info;
	VMINT mtk_handle = -1;
	//VMCHAR fn[128];

	if ( direntry == NULL)
	{
		//vm_log_debug("vm_find_next_ext: the ptr of info&direntry is NULL");
		return -1;
	}

	if (vm_res_get_mtk_reshandle(VM_RES_TYPE_FILE_FIND, handle, &mtk_handle) == VM_RES_OK)
	{
		memset(direntry, 0x00, sizeof(vm_fileinfo_ext));
		if ((retval = FS_FindNext(mtk_handle, &file_info, (WCHAR*)(direntry->filefullname), MAX_APP_NAME_LEN * 2)) == FS_NO_ERROR) 
		{
			//vm_ucs2_to_gb2312((VMSTR)fn, 100, (VMWCHAR *)(direntry->filefullname));
			////vm_log_debug("vm_find_next_ext : FS_FindNext return sccuess, handle=%d, filename=%s ", handle, fn);	

			memcpy((VMCHAR *)direntry->filename, (VMCHAR *)file_info.FileName, 8);
			memcpy((VMCHAR *)direntry->extension, (VMCHAR *)file_info.Extension, 3);
			direntry->attributes = file_info.Attributes;
			direntry->filesize = file_info.FileSize;
#if (!defined(__VRE_RB_08A__) && !defined(__VRE_RB_08B__))	
			direntry->drive = file_info.Drive;
			direntry->stamp = file_info.Stamp;
#endif

			direntry->create_datetime.year = 1980 + file_info.CreateDateTime.Year1980;
			direntry->create_datetime.mon = file_info.CreateDateTime.Month;
			direntry->create_datetime.day = file_info.CreateDateTime.Day;
			direntry->create_datetime.hour = file_info.CreateDateTime.Hour;
			direntry->create_datetime.min = file_info.CreateDateTime.Minute;
			direntry->create_datetime.sec = file_info.CreateDateTime.Second2 * 2;
			
			direntry->modify_datetime.year = 1980 + file_info.DateTime.Year1980;
			direntry->modify_datetime.mon = file_info.DateTime.Month;
			direntry->modify_datetime.day = file_info.DateTime.Day;
			direntry->modify_datetime.hour = file_info.DateTime.Hour;
			direntry->modify_datetime.min = file_info.DateTime.Minute;
			direntry->modify_datetime.sec = file_info.DateTime.Second2 * 2;
		}
		else
		{
			//info->size = 0;
			memset(direntry, 0x00, sizeof(vm_fileinfo_ext));
			retval = -1;
			//vm_log_debug("vm_find_next_ext : FS_FindNext return error code =%d, handle=%d", retval, handle);
		}	
	}
	else 
	{
		retval = -1;
	}
	return retval;
}

void vm_find_close_ext(VMINT handle)
{
	vm_find_close(handle);
}

VMINT vm_find_first(VMWSTR pathname, struct vm_fileinfo_t* info) 
{
	VMINT handle = -1;
	VMINT mtk_handle;
	FS_DOSDirEntry	file_info;
	VM_P_HANDLE phandle = -1;
	
	//vm_log_fatal("vm_find_first");
	if (pathname == NULL || info == NULL)
	{
		//vm_log_debug("vm_find_first : the ptr of pathname or info is NULL");
		return -1;
	}
	if (vm_wstrlen(pathname) == 0 || vm_wstrlen(pathname) > MAX_APP_NAME_LEN)
	{
		//vm_log_debug("vm_find_first : the length of pathname is error");
		return -1;
	}	

	phandle = vm_pmng_get_current_handle();
	handle = vm_res_save_data(VM_RES_TYPE_FILE_FIND, NULL, 0, NULL,  phandle);
	if (handle < 0)
	{
		return -1;
	}
	
	if ((mtk_handle = FS_FindFirst((WCHAR *)pathname, 0, 0, &file_info, (WCHAR *)info->filename, MAX_APP_NAME_LEN * 2)) >= 0) 
	{
		//vm_log_debug("vm_find_first : FS_FindFirst return success handle=%d ", handle);
		if (vm_res_set_mtk_reshandle(VM_RES_TYPE_FILE_FIND, handle, mtk_handle) == VM_RES_OK)
		{
			info->size = file_info.FileSize;
		}
		else
		{
			FS_FindClose(mtk_handle);
			vm_res_release_data(VM_RES_TYPE_FILE_FIND, handle);
			handle = -1;
			info->size = 0;
		}

	}
	else
	{
		vm_res_release_data(VM_RES_TYPE_FILE_FIND, handle);
		handle = -1;
		info->size = 0;
		//vm_log_debug("vm_find_first : FS_FindFirst return handle=%d is error", handle);
	}
	return handle;
}


VMINT vm_find_next(VMINT handle, struct vm_fileinfo_t* info) 
{
	int retval = -1;
	FS_DOSDirEntry file_info;
	VMINT mtk_handle = -1;
	//vm_log_fatal("vm_find_next");
	if (vm_res_get_mtk_reshandle(VM_RES_TYPE_FILE_FIND, handle, &mtk_handle) == VM_RES_OK)
	{
		if ((retval = FS_FindNext(mtk_handle, &file_info, (WCHAR*)info->filename, MAX_APP_NAME_LEN * 2)) == FS_NO_ERROR) 
		{
			info->size = file_info.FileSize;
		}
		else
		{
			//vm_log_debug("vm_find_next : FS_FindNext return error code =%d", retval);
		}	
	}
	else
	{
		retval = -1;
	}
	return retval;
}

void vm_find_close(VMINT handle) 
{
	int retval = -1;
	VMINT mtk_handle = -1;

	if (vm_res_get_mtk_reshandle(VM_RES_TYPE_FILE_FIND, handle, &mtk_handle) == VM_RES_OK)
	{
		
		retval = FS_FindClose(mtk_handle);
		vm_res_release_data(VM_RES_TYPE_FILE_FIND, handle);

		if (retval != FS_NO_ERROR)
		{
			//vm_log_debug("vm_find_close : FS_FindClose return error code =%d", retval);
			retval = -1;
		}
		else
		{
			retval = 0;
		}
	}
	//return retval;
}

VMINT vm_get_removeable_driver(void) 
{
	if (FS_GetDevStatus((unsigned int)FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, 	FS_NO_ALT_DRIVE), FS_MOUNT_STATE_ENUM) == FS_NO_ERROR)	
		return FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
	return -1;
}

VMINT vm_get_system_driver(void) 
{
	return FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL);
}

VMINT vm_get_nvram_driver(void)
{
	return FS_GetDrive(FS_DRIVE_I_SYSTEM, 1, 
		FS_DRIVE_I_SYSTEM | FS_DRIVE_V_NORMAL);
}

/*
#ifdef VRE_SYS_DRIVER_REMAPPING
VMINT in_white_list(VMWSTR filename) {
	int i;
	VMWCHAR filepart[128];

	for (i = 0; i < WHITE_LIST_NUM; i++)
	{
		vm_get_filename(filename, filepart);
		if (vm_wstrcmp(filepart, vm_ucs2_string(white_list[i])) == 0)
		{
			return 1;
		}
	}

	return 0;
}


VMWSTR file_remap(VMWSTR filename) {
	static VMWCHAR fn[128];

	vm_safe_wstrcpy(fn, 128, filename);
	if (fn[0] == vm_get_system_driver() && !in_white_list(fn))
	{
		fn[0] = vm_get_removeable_driver();
		////vm_log_debug("To open %s.", vm_gb2312_string(filename));
		////vm_log_debug("Remap to %s.", vm_gb2312_string(fn));
	}

	return fn;
}
#endif
*/

VMUINT vm_get_disk_free_space(VMWSTR drv_name)
{
	VMUINT free_space = 0;
	VMINT fs_handle;
	FS_DiskInfo	disk_info;
	VMCHAR temp[4];
	VMCHAR drv_asc[10];
	VMWCHAR drv_ucs[10];

	if (drv_name == NULL)
	{
		//vm_log_debug("vm_get_disk_free_space : the ptr of drv_name is NULL");
		return 0;
	}

	if (vm_wstrlen(drv_name) != 1)
	{
		//vm_log_debug("vm_get_disk_free_space : the length of drv_name is not 1");
		return 0;
	}

	//vm_ucs2_to_gb2312(temp, 4, drv_name);	
	vm_ucs2_to_ascii(temp, 4, drv_name);
	
	////vm_log_debug("vm_get_disk_free_space : drv=%s", temp);
	sprintf(drv_asc, "%s:\\", temp);
	if ((drv_asc[0] > 'a' && drv_asc[0] < 'z') ||(drv_asc[0] > 'A' && drv_asc[0] < 'Z'))
	{
		////vm_log_debug("vm_get_disk_free_space : drv=%s", drv_asc);
		//vm_gb2312_to_ucs2(drv_ucs, 10, drv_asc);
		vm_ascii_to_ucs2(drv_ucs, 10, drv_asc);

		fs_handle = FS_GetDiskInfo((WCHAR *)drv_ucs, &disk_info, FS_DI_BASIC_INFO|FS_DI_FREE_SPACE);
			
		if(fs_handle >= 0)
		{
			//vm_log_debug("disk_info : Clusters=%d, SectorsPerCluster=%d, BytesPerSector=%d", disk_info.FreeClusters, disk_info.SectorsPerCluster, disk_info.BytesPerSector);
			free_space = disk_info.FreeClusters*disk_info.SectorsPerCluster*disk_info.BytesPerSector;
		}
		else
		{
			//vm_log_debug("vm_get_disk_free_space : FS_GetDiskInfo error");
		}
	}
	else
	{
		//vm_log_debug("vm_get_disk_free_space : the letter of drv_name is error");
		return 0;
	}

	return free_space;
}

#include "DevConfigDef.h"
VMINT vm_is_support_pen_touch(void)
{
/*
#ifdef VRE_SUPPORT_SCREEN_TOUCH
	return TRUE;
#else
	return FALSE;
#endif
*/
	if(sysconf.input_device.touch_screen)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

VMINT vm_is_support_keyborad(void)
{
/*
#ifdef VRE_SUPPORT_TOTAL_KEYPAD
	return TRUE;
#else
	return FALSE;
#endif
*/
	if(sysconf.input_device.keypad_type == MMI_DEVCONFIG_KEYPAD_TYPE_NORMAL 
		|| sysconf.input_device.keypad_type == MMI_DEVCONFIG_KEYPAD_TYPE_QWERTY)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

VMINT vm_is_figner_touch_version(void)
{
	return sysconf.input_device.figner_touch_support;
}

VMINT vm_is_support_gsensor(void)
{
	return sysconf.remote_sensing.motion_sensor;
}

VMINT vm_file_get_modify_time(const VMWSTR filename, vm_time_t * modify_time)
{
	char full_name[MAX_APP_NAME_LEN];
	FS_DOSDirEntry entry;
	FS_FileInfo finfo;
	FS_HANDLE fshandle;
	//char fn[128];

	VMINT retval = -1;
	
	//vm_log_fatal("vm_file_get_modify_time start");
	if (filename == NULL || modify_time == NULL)
	{
		//vm_log_debug("vm_file_get_modify_time : the ptr of filename or modify_time is NULL");
		return -1;
	}

	if (vm_wstrlen(filename) == 0 || vm_wstrlen(filename) > MAX_APP_NAME_LEN)
	{
		//vm_log_debug("vm_file_get_modify_time : the length of filename is error");
		return -1;
	}
	
	//vm_ucs2_to_gb2312(fn, 128, filename);
	//vm_log_fatal("vm_file_open : fn = %s", fn);
	
	
	fshandle = FS_Open((WCHAR *)filename, FS_READ_ONLY);
	if (fshandle > 0)
	{
		//vm_log_fatal("vm_file_get_modify_time step 1");
		finfo.DirEntry = &entry;
		finfo.FullName = full_name;
		if (FS_GetFileInfo(fshandle, &finfo) == FS_NO_ERROR)
		{
			//vm_log_fatal("vm_file_get_modify_time step 2");
			memset(modify_time, 0x00, sizeof(vm_time_t));
			modify_time->year = 1980 + finfo.DirEntry->DateTime.Year1980;
			modify_time->mon = finfo.DirEntry->DateTime.Month;
			modify_time->day = finfo.DirEntry->DateTime.Day;
			modify_time->hour = finfo.DirEntry->DateTime.Hour;
			modify_time->min = finfo.DirEntry->DateTime.Minute;
			modify_time->sec = finfo.DirEntry->DateTime.Second2 * 2;
			retval = 0;
			//vm_log_fatal("vm_file_get_modify_time step 3"); 
		}
		else
		{
			retval = -1;
			//vm_log_debug("vm_file_get_modify_time: FS_GetFileInfo error"); 
		}
		FS_Close(fshandle);
	}
	else
	{
		retval = -1;
		//vm_log_debug("vm_file_get_modify_time: FS_Open error"); 
	}
	//vm_log_fatal("vm_file_get_modify_time end");
	return retval;
}



/*
 * 备注说明:
 * 下列函数完成文件路径重定向功能， 通过VRE_IO_REMAP宏控制是否编译
 */
#ifdef VRE_SUPPORT_SECURITY_FEATURE
/**
 *	打开文件，重定向功能
 */
VMFILE vm_file_open_remap(const VMWSTR filename, VMUINT mode, VMUINT binary) 
{
	VM_P_HANDLE phandle = -1;
	VMINT mtk_file_id = -1;
	VMINT handle = VM_FILE_OPEN_ERROR;
	VMUINT flag = 0;
	//VMCHAR *fn;
	VMWCHAR *remap_filename;

	if (filename == NULL)
	{
		return VM_FILE_NAME_ERROR;
	}

	if (vm_wstrlen(filename) == 0 || vm_wstrlen(filename) > REMAP_FILENAME_MAX_LEN)
	{
		return VM_FILE_NAME_ERROR;
	}	

	phandle = vm_pmng_get_current_handle();
	handle = vm_res_save_data(VM_RES_TYPE_FILE, NULL, 0, NULL, phandle);

	if (handle >= 0) 
	{
		if (mode & MODE_READ)
			flag = FS_READ_ONLY;
		else if (mode & MODE_WRITE)
			flag = FS_READ_WRITE;
		else if (mode & MODE_APPEND)
			flag = FS_READ_WRITE;
		else if (mode & MODE_CREATE_ALWAYS_WRITE)
			flag = FS_CREATE_ALWAYS | FS_READ_WRITE;

		remap_filename = vm_malloc(REMAP_FILENAME_MAX_LEN * sizeof(VMWCHAR));
		if (remap_filename == NULL)
		{
			//vm_log_debug("vm_file_open_remap : malloc remap_filename fail");
			vm_res_release_data(VM_RES_TYPE_FILE, handle);
			return VM_FILE_NAME_ERROR;
		}

		if (_vm_remap_usr_disk((VMWSTR)remap_filename, (VMWSTR)filename) == FALSE)
		{
			//vm_log_debug("vm_file_open_remap : _vm_remap_usr_disk fail");
			vm_free(remap_filename);
			vm_res_release_data(VM_RES_TYPE_FILE, handle);
			return VM_FILE_NAME_ERROR;
		}

		mtk_file_id = FS_Open((WCHAR*)remap_filename, flag);
		if (mtk_file_id >= 0)
		{			
			if (vm_res_set_mtk_reshandle(VM_RES_TYPE_FILE, handle, mtk_file_id) == VM_RES_OK)
			{
				if (mode & MODE_APPEND)
				{
					FS_Seek(mtk_file_id, 0, FS_FILE_END);
				}
			}
			else
			{
				FS_Close(mtk_file_id);
				vm_res_release_data(VM_RES_TYPE_FILE, handle);
				handle = VM_FILE_OPEN_ERROR;
			}
		}
		else 
		{
			vm_res_release_data(VM_RES_TYPE_FILE, handle);
			handle = VM_FILE_OPEN_ERROR;
		}
		vm_free(remap_filename);
	}
	return handle;
}

/**
 *	删除文件，重定向功能
 */
VMINT vm_file_delete_remap(const VMWSTR filename) 
{
	VMINT retval = -1;	
	VMWCHAR *remap_filename;
	S32 attr = 0;

	if (filename == NULL)
	{
		//vm_log_debug("vm_file_delete_remap : the ptr of filename is NULL");
		return -1;
	}
	if (vm_wstrlen(filename) == 0 || vm_wstrlen(filename) > MAX_APP_NAME_LEN)
	{
		//vm_log_debug("vm_file_delete_remap : the length of filename is error");
		return -1;
	}
	
	remap_filename = vm_malloc(REMAP_FILENAME_MAX_LEN * sizeof(VMWCHAR));
	
	if (remap_filename == NULL)
	{
		//vm_log_debug("vm_file_delete_remap : malloc remap_filename fail");
		return -1;
	}
	if (_vm_remap_usr_disk((VMWSTR)remap_filename, (VMWSTR)filename) == FALSE)
	{
		//vm_log_debug("vm_file_delete_remap : _vm_remap_usr_disk fail");
		vm_free(remap_filename);
		return -1;
	}

	attr = FS_GetAttributes((WCHAR *)remap_filename);
    	if ((attr & FS_ATTR_READ_ONLY))
		FS_SetAttributes((WCHAR *)remap_filename, (U8) (attr & ~(FS_ATTR_READ_ONLY)));
		
	retval =  FS_Delete((WCHAR *)remap_filename) != FS_NO_ERROR ? -1:0;	
	if (retval != 0)
	{
		//vm_log_debug("vm_file_delete_remap : FS_Delete return error code=%d", retval);
	}
	
	vm_free(remap_filename);
	return retval;
}

/**
 *	重命名文件，重定向功能
 */
VMINT vm_file_rename_remap(const VMWSTR filename, const VMWSTR newname) 
{
	VMINT retval = -1;
	VMWCHAR *remap_filename;
	VMWCHAR *remap_newname;

	if (filename == NULL || newname == NULL)
	{
		//vm_log_debug("vm_file_rename_remap : the ptr of filename is NULL");
		return -1;
	}
	if (vm_wstrlen(filename) == 0 
		|| vm_wstrlen(filename) > MAX_APP_NAME_LEN
		|| vm_wstrlen(newname) == 0 
		|| vm_wstrlen(newname) > MAX_APP_NAME_LEN
	)
	{
		//vm_log_debug("vm_file_rename_remap : the length of filename is error");
		return -1;
	}

	remap_filename = vm_malloc(REMAP_FILENAME_MAX_LEN * sizeof(VMWCHAR));
	if (remap_filename == NULL)
	{
		//vm_log_debug("vm_file_rename_remap : malloc remap_filename 1 fail");
		return -1;
	}
	
	remap_newname = vm_malloc(REMAP_FILENAME_MAX_LEN * sizeof(VMWCHAR));
	if (remap_newname == NULL)
	{
		//vm_log_debug("vm_file_rename_remap : malloc remap_filename 2 fail");
		vm_free(remap_filename);
		return -1;
	}
	
	
	/*重定向目录文件*/
	if (_vm_remap_usr_disk((VMWSTR)remap_filename, (VMWSTR)filename) == FALSE
		|| _vm_remap_usr_disk((VMWSTR)remap_newname, (VMWSTR)newname) == FALSE)
	{
		//vm_log_debug("vm_file_rename_remap : _vm_remap_usr_disk fail");
		vm_free(remap_filename);
		vm_free(remap_newname);
		return -1;
	}

	retval = (FS_Rename((WCHAR *)remap_filename, (WCHAR *)remap_newname)) != FS_NO_ERROR ? -1:0;

	if (retval != 0)
	{
		//vm_log_debug("vm_file_rename_remap : FS_Rename return error code=%d", retval);
	}
	
	vm_free(remap_filename);
	vm_free(remap_newname);
	return retval;
}


/**
 *	查找文件，重定向功能
 */
VMINT vm_find_first_remap_ext(VMWSTR pathname, vm_fileinfo_ext * direntry) 
{
	VMINT handle;
	FS_DOSDirEntry	file_info;

	VMWCHAR * remap_pathname;

	VMINT mtk_handle;
	VM_P_HANDLE phandle = -1;

	if (pathname == NULL || direntry == NULL)
	{
		//vm_log_debug("vm_find_first_remap : the ptr of pathname or info is NULL");
		return -1;
	}
	if (vm_wstrlen(pathname) == 0 || vm_wstrlen(pathname) > MAX_APP_NAME_LEN)
	{
		//vm_log_debug("vm_find_first_remap : the length of pathname is error");
		return -1;
	}

	remap_pathname = vm_malloc(REMAP_FILENAME_MAX_LEN * sizeof(VMWCHAR));
	if (remap_pathname == NULL)
	{
		//vm_log_debug("vm_find_first_remap : malloc remap_filename fail");
		return -1;
	}
	
	if (_vm_remap_usr_disk((VMWSTR)remap_pathname, (VMWSTR)pathname) == FALSE)
	{
		//vm_log_debug("vm_find_first_remap : _vm_remap_usr_disk fail");
		vm_free(remap_pathname);
		return -1;
	}

	phandle = vm_pmng_get_current_handle();
	handle = vm_res_save_data(VM_RES_TYPE_FILE_FIND, NULL, 0, NULL,  phandle);
	if (handle < 0)
	{
		vm_free(remap_pathname);
		return -1;
	}

	memset(direntry, 0x00, sizeof(vm_fileinfo_ext));
	if ((mtk_handle = FS_FindFirst((WCHAR *)remap_pathname, 0, 0, &file_info, (WCHAR *)(direntry->filefullname), MAX_APP_NAME_LEN)) >= 0) 
	{
		if (vm_res_set_mtk_reshandle(VM_RES_TYPE_FILE_FIND, handle, mtk_handle) == VM_RES_OK)
		{
			memcpy((VMCHAR *)(direntry->filename), (VMCHAR *)(file_info.FileName), 8);
			memcpy((VMCHAR *)(direntry->extension), (VMCHAR *)(file_info.Extension), 3);
			direntry->attributes = file_info.Attributes;		
			direntry->filesize = file_info.FileSize;
#if (!defined(__VRE_RB_08A__) && !defined(__VRE_RB_08B__))	
			direntry->drive = file_info.Drive;
			direntry->stamp = file_info.Stamp;
#endif

			direntry->create_datetime.year = 1980 + file_info.CreateDateTime.Year1980;
			direntry->create_datetime.mon = file_info.CreateDateTime.Month;
			direntry->create_datetime.day = file_info.CreateDateTime.Day;
			direntry->create_datetime.hour = file_info.CreateDateTime.Hour;
			direntry->create_datetime.min = file_info.CreateDateTime.Minute;
			direntry->create_datetime.sec = file_info.CreateDateTime.Second2 * 2;
			
			direntry->modify_datetime.year = 1980 + file_info.DateTime.Year1980;
			direntry->modify_datetime.mon = file_info.DateTime.Month;
			direntry->modify_datetime.day = file_info.DateTime.Day;
			direntry->modify_datetime.hour = file_info.DateTime.Hour;
			direntry->modify_datetime.min = file_info.DateTime.Minute;
			direntry->modify_datetime.sec = file_info.DateTime.Second2 * 2;
		}
		else
		{
			FS_FindClose(mtk_handle);
			vm_res_release_data(VM_RES_TYPE_FILE_FIND, handle);
			handle = -1;
			memset(direntry, 0x00, sizeof(vm_fileinfo_ext));
		}
	}
	else
	{
		vm_res_release_data(VM_RES_TYPE_FILE_FIND, handle);
		handle = -1;
		memset(direntry, 0x00, sizeof(vm_fileinfo_ext));
		//vm_log_debug("vm_find_first_remap : FS_FindFirst return handle=%d is error", handle);
	}
	vm_free(remap_pathname);
	return handle;
}



/**
 *	查找文件，重定向功能
 */
VMINT vm_find_first_remap(VMWSTR pathname, struct vm_fileinfo_t* info) 
{
	VMINT handle;
	FS_DOSDirEntry	file_info;
	VMWCHAR * remap_pathname;
	
	VMINT mtk_handle;
	VM_P_HANDLE phandle = -1;

	if (pathname == NULL || info == NULL)
	{
		//vm_log_debug("vm_find_first_remap : the ptr of pathname or info is NULL");
		return -1;
	}
	if (vm_wstrlen(pathname) == 0 || vm_wstrlen(pathname) > MAX_APP_NAME_LEN)
	{
		//vm_log_debug("vm_find_first_remap : the length of pathname is error");
		return -1;
	}
	if (info->filename == NULL)
	{
		//vm_log_debug("vm_find_first_remap : the ptr of info->filename is NULL");
		return -1;
	}
	if (vm_wstrlen(info->filename) == 0 || vm_wstrlen(info->filename) > MAX_APP_NAME_LEN)
	{
		//vm_log_debug("vm_find_first_remap : the length of info->filename is error");
		return -1;
	}
	
	remap_pathname = vm_malloc(REMAP_FILENAME_MAX_LEN * sizeof(VMWCHAR));
	if (remap_pathname == NULL)
	{
		//vm_log_debug("vm_find_first_remap : malloc remap_filename fail");
		return -1;
	}
	
	if (_vm_remap_usr_disk((VMWSTR)remap_pathname, (VMWSTR)pathname) == FALSE)
	{
		//vm_log_debug("vm_find_first_remap : _vm_remap_usr_disk fail");
		vm_free(remap_pathname);
		return -1;
	}

	phandle = vm_pmng_get_current_handle();
	handle = vm_res_save_data(VM_RES_TYPE_FILE_FIND, NULL, 0, NULL,  phandle);
	if (handle < 0)
	{
		vm_free(remap_pathname);
		return -1;
	}

	if ((mtk_handle = FS_FindFirst((WCHAR *)remap_pathname, 0, 0, &file_info, (WCHAR *)info->filename, MAX_APP_NAME_LEN)) >= 0) 
	{	
		if (vm_res_set_mtk_reshandle(VM_RES_TYPE_FILE_FIND, handle, mtk_handle) == VM_RES_OK)
		{
			info->size = file_info.FileSize;
		}
		else
		{
			FS_FindClose(mtk_handle);
			vm_res_release_data(VM_RES_TYPE_FILE_FIND, handle);
			handle = -1;
			info->size = 0;
		}
	}
	else
	{
		info->size = 0;
		vm_res_release_data(VM_RES_TYPE_FILE_FIND, handle);
		handle = -1;
		//vm_log_debug("vm_find_first_remap : FS_FindFirst return handle=%d is error", handle);
	}
	vm_free(remap_pathname);
	return handle;
}

/**
 *	建立目录，重定向功能
 */
VMINT vm_file_mkdir_remap(const VMWSTR dirname) 
{
	VMINT retval = -1;
	VMWCHAR *remap_dirname;
	//char fn[128];

	//memset(fn, 0x00, 128);
	//vm_ucs2_to_gb2312(fn, 128, dirname);
	//vm_log_fatal("vm_file_mkdir_remap : %s", fn);

	if (dirname == NULL)
	{
		//vm_log_debug("vm_file_mkdir_remap : the ptr of dirname is NULL");
		return -1;
	}
	if (vm_wstrlen(dirname) == 0 || vm_wstrlen(dirname) > MAX_APP_NAME_LEN)
	{
		//vm_log_debug("vm_file_mkdir_remap : the length of dirname is error");
		return -1;
	}
	
	remap_dirname = vm_malloc(REMAP_FILENAME_MAX_LEN * sizeof(VMWCHAR));
	if (remap_dirname == NULL)
	{
		//vm_log_debug("vm_file_mkdir_remap : malloc remap_dirname fail");
		return -1;
	}

	if (_vm_remap_usr_disk((VMWSTR)remap_dirname, (VMWSTR)dirname) == FALSE)
	{
		//vm_log_debug("vm_find_first_remap : _vm_remap_usr_disk fail");
		vm_free(remap_dirname);
		return -1;
	}
	
	retval =  FS_CreateDir((WCHAR *)remap_dirname) != FS_NO_ERROR ? -1:0;

	if (retval != 0)
	{
		//vm_log_debug("vm_file_mkdir_remap : FS_CreateDir return error code=%d", retval);
	}
	
	vm_free(remap_dirname);
	return retval;
}

/**
 *	删除目录，重定向功能
 */
VMINT vm_file_rmdir_remap(const VMWSTR dirname) 
{
	VMINT retval = -1;
	VMWCHAR *remap_dirname;

	if (dirname == NULL)
	{
		//vm_log_debug("vm_file_rmdir_remap : the ptr of dirname is NULL");
		return -1;
	}
	if (vm_wstrlen(dirname) == 0 || vm_wstrlen(dirname) > MAX_APP_NAME_LEN)
	{
		//vm_log_debug("vm_file_rmdir_remap : the length of dirname is error");
		return -1;
	}
	
	remap_dirname = vm_malloc(REMAP_FILENAME_MAX_LEN * sizeof(VMWCHAR));
	if (remap_dirname == NULL)
	{
		//vm_log_debug("vm_file_rmdir_remap : malloc remap_dirname fail");
		return -1;
	}
	
	if (_vm_remap_usr_disk((VMWSTR)remap_dirname, (VMWSTR)dirname) == FALSE)
	{
		//vm_log_debug("vm_find_first_remap : _vm_remap_usr_disk fail");
		vm_free(remap_dirname);
		return -1;
	}
	
	//retval =  FS_RemoveDir((WCHAR *)remap_dirname) != FS_NO_ERROR ? -1:0;

	retval = FS_XDelete(
                (const WCHAR *)remap_dirname,
                FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE,
                NULL,
                0) < 0 ? -1:0;

	if (retval < 0)
	{
		//vm_log_debug("vm_file_mkdir_remap : FS_CreateDir return error code=%d", retval);
	}
	
	vm_free(remap_dirname);
	return retval;
}

VMINT vm_file_set_attributes_remap(const VMWSTR filename, VMBYTE attributes)
{
	VMINT retval = -1;
	VMWCHAR *remap_dirname;

	if (filename == NULL)
		return -1;

	remap_dirname = vm_malloc(REMAP_FILENAME_MAX_LEN * sizeof(VMWCHAR));
	if (remap_dirname == NULL)
	{
		return -1;
	}

	if (_vm_remap_usr_disk((VMWSTR)remap_dirname, (VMWSTR)filename) == FALSE)
	{
		vm_free(remap_dirname);
		return -1;
	}
	
	retval = FS_SetAttributes((WCHAR *)remap_dirname, attributes);

	if (retval != FS_NO_ERROR)
		retval = -1;
	else
		retval = 0;
	
	return retval;
	
}

VMINT vm_file_get_attributes_remap(const VMWSTR filename)
{
	VMINT retval = -1;
	VMWCHAR *remap_dirname;

	if (filename == NULL)
		return -1;

	remap_dirname = vm_malloc(REMAP_FILENAME_MAX_LEN * sizeof(VMWCHAR));
	if (remap_dirname == NULL)
	{
		return -1;
	}

	if (_vm_remap_usr_disk((VMWSTR)remap_dirname, (VMWSTR)filename) == FALSE)
	{
		vm_free(remap_dirname);
		return -1;
	}
	
	retval = FS_GetAttributes((WCHAR *)remap_dirname);
	
	if (retval < 0 )
		return -1;
	return retval;
	
}


/**
 *	创建并得到应用程序目录
 *	创建应用程序的目录,并在该目录下面建立虚拟驱动器目录
 *
 *	@param app_path_str		返回创建的应用程序的目录的字符串指针
 *	@param app_drv			应用程序的虚拟驱动器名，可以重订向到应用程序的目录
 *	@return					TRUE=创建成功 ; FALSE=创建失败
 */
static VMINT _vm_create_current_app_drv(VMSTR app_path_str, VMCHAR app_drv)
{
	VMINT retval = FALSE;
	VMUINT i;
	VMWCHAR *app_wpath;
	VMCHAR *temp_fn;
	VMCHAR *temp_dir;
	
	app_wpath = vm_malloc(REMAP_FILENAME_MAX_LEN * sizeof(VMWCHAR));
	if (app_wpath == NULL)
		return FALSE;
	temp_fn = vm_malloc(REMAP_FILENAME_MAX_LEN * sizeof(VMCHAR));
	if (temp_fn == NULL)
	{
		vm_free(app_wpath);
		return FALSE;
	}
	temp_dir = vm_malloc(REMAP_FILENAME_MAX_LEN * sizeof(VMCHAR));
	if (temp_dir == NULL)
	{
		vm_free(app_wpath);
		vm_free(temp_fn);
		return FALSE;
	}

	
	if (vm_get_exec_filename((VMWSTR)app_wpath) != 0)
	{
		vm_free(app_wpath);
		vm_free(temp_fn);
		vm_free(temp_dir);
		/*表示当前处于内核态*/
		retval = FALSE;
	}
	else
	{
		/*表示当前处于程序在运行*/
		//vm_ucs2_to_gb2312((VMSTR)temp_fn, REMAP_FILENAME_MAX_LEN, (VMWSTR)app_wpath);
		vm_ucs2_to_ascii((VMSTR)temp_fn, REMAP_FILENAME_MAX_LEN, (VMWSTR)app_wpath);
		/*在应用程序目录下面建立同名的目录*/		
		memset(temp_dir, 0x00, REMAP_FILENAME_MAX_LEN);
		for(i = 0; i < strlen(temp_fn); i++)
		{
			if(temp_fn[i] == '.')
			{
				break;
			}
			temp_dir[i] = temp_fn[i];
		}
		temp_dir[i] = '\0';
		//vm_gb2312_to_ucs2((VMWSTR)app_wpath, REMAP_FILENAME_MAX_LEN * 2, (VMSTR)temp_dir);
		vm_ascii_to_ucs2((VMWSTR)app_wpath, REMAP_FILENAME_MAX_LEN * 2, (VMSTR)temp_dir);
		vm_file_mkdir((VMWSTR)app_wpath);
		/*在应用程序目录下面建立虚拟驱动器名目录*/
		memset(temp_fn, 0x00, REMAP_FILENAME_MAX_LEN);
		if ((strlen(temp_dir) + 1) >= REMAP_FILENAME_MAX_LEN)
		{
			retval = FALSE;
		}
		else
		{
			sprintf(temp_fn, "%s\\%c", temp_dir, app_drv);
			//vm_gb2312_to_ucs2((VMWSTR)app_wpath, REMAP_FILENAME_MAX_LEN * 2, (VMSTR)temp_fn);
			vm_ascii_to_ucs2((VMWSTR)app_wpath, REMAP_FILENAME_MAX_LEN * 2, (VMSTR)temp_fn);
			vm_file_mkdir((VMWSTR)app_wpath);
			/*返回应用程序的目录字符串,带虚拟驱动器目录*/
			strcpy(app_path_str, temp_fn);	
			retval = TRUE;
		}
	}
	vm_free(app_wpath);
	vm_free(temp_fn);
	vm_free(temp_dir);
	return retval;
}


/**
 *	重定向应用程序的驱动器,
 *	例如 需要在应用程序app1(c:\vre\app1.afx)中执行打开c:\aa.txt文件, 
 *	如果有系统级权限,程序可以直接打开c:\aa.txt文件,
 *	如果只有用户级权限,程序打开的文件目录将被重定向到应用程序所在目录下的c目录(c:\vre\app1\c\aa.txt)
 *	
 *	@param	dest_filename		重定向后的实际目录
 *	@param	source_filename		重定向前的目录
 *	@return	TRUE=重定向成功 ; FALSE=重定向失败
 */
VMINT _vm_remap_usr_disk(VMWSTR dest_filename, VMWSTR source_filename)
{
	VMINT retval = FALSE;
	VMUINT i = 0;
	VMUINT j = 0;

	VMCHAR *temp_fn;
	VMCHAR *temp_fn1;
	VMCHAR drv;
	VMINT  has_drv = TRUE;

	VMCHAR temp_ch;
	VMCHAR *temp_str;

	VMCHAR *remap_app_path;

	
	//vm_log_debug("_vm_remap_usr_disk begin");
	
	if (dest_filename == NULL || source_filename == NULL)
	{
		//vm_log_debug("_vm_remap_usr_disk : the ptr of source_filename or dest_filename is error");
		return FALSE;
	}

	if ((vm_wstrlen(source_filename) > REMAP_FILENAME_MAX_LEN) || (vm_wstrlen(source_filename) == 0))
	{
		//vm_log_debug("_vm_remap_usr_disk : the length of source_filename is error");
		return FALSE;
	}

	/*判断文件系统访问权限*/
	if (_vm_get_disk_permission() == VM_PERMISSION_SYS_DRV)
	{
		/*系统级权限,直接复制后,返回重定向操作正确*/
		//vm_log_debug("_vm_remap_usr_disk step 1 : system role, load wstrcpy function");
		vm_wstrcpy(dest_filename, source_filename);
		return TRUE;	
	}	
	else if (_vm_get_disk_permission() == VM_PERMISSION_USR_DRV)
	{		
		/*如果是用户级权限*/
		//vm_log_debug("_vm_remap_usr_disk step 2 : usr role");

		temp_fn = vm_malloc(REMAP_FILENAME_MAX_LEN * sizeof(VMCHAR));
		if (temp_fn == NULL)
			return FALSE;
		temp_fn1 = vm_malloc(REMAP_FILENAME_MAX_LEN * sizeof(VMCHAR));
		if (temp_fn1 == NULL)
		{
			vm_free(temp_fn);
			return FALSE;
		}
		temp_str = vm_malloc(REMAP_FILENAME_MAX_LEN * sizeof(VMCHAR));
		if (temp_str == NULL)
		{
			vm_free(temp_fn1);
			vm_free(temp_fn);
			return FALSE;
		}
		remap_app_path = vm_malloc(REMAP_FILENAME_MAX_LEN * sizeof(VMCHAR));
		if (remap_app_path == NULL)
		{
			vm_free(temp_str);
			vm_free(temp_fn1);
			vm_free(temp_fn);
			return FALSE;
		}
		
		//vm_log_debug("_vm_remap_usr_disk step 3");

		//vm_ucs2_to_gb2312(temp_fn, REMAP_FILENAME_MAX_LEN, source_filename);
		vm_ucs2_to_ascii(temp_fn, REMAP_FILENAME_MAX_LEN, source_filename);
		temp_ch = temp_fn[1];
		/*判断是否带驱动器信息*/
		if (temp_ch != ':')
		{
			/*如果没有带驱动器信息,系统缺省指到c驱动器*/
			drv = 'c';
			has_drv = FALSE;
		}
		else
		{
			drv = temp_fn[0];
			has_drv = TRUE;
		}
	
		/*创建用户目录*/
		if (_vm_create_current_app_drv((VMSTR)remap_app_path, drv) == TRUE)
		{
			//vm_log_debug("_vm_remap_usr_disk step 4");
			/*映射到用户驱动器*/
			memset(temp_fn1, 0x00, REMAP_FILENAME_MAX_LEN);
			if (has_drv)
			{
				/*目录中有驱动器名,从第三个字符开始截取*/
				i = 3;
			}
			else
			{
				/*目录中没有驱动器名,从第一个非'\'字符开始截取*/
				i = 0;
				for(j = 0;  j < strlen(temp_fn); j++)
				{
					if (temp_fn[j] == '\\')
					{
						continue;
					}
					else
					{
						i = j;
						break;
					}
				}				
			}
			j = 0;
			for (; i < strlen(temp_fn); i++)
			{
				temp_fn1[j] = temp_fn[i];
				j++;
			}
			if ((strlen(remap_app_path) + strlen(temp_fn1))< REMAP_FILENAME_MAX_LEN)
			{
				sprintf(temp_str, "%s\\%s", remap_app_path, (VMSTR)temp_fn1);
				//vm_log_debug("_vm_remap_usr_disk remap result : %s", temp_str);
				//vm_gb2312_to_ucs2(dest_filename, REMAP_FILENAME_MAX_LEN * 2, temp_str);
				vm_ascii_to_ucs2(dest_filename, REMAP_FILENAME_MAX_LEN * 2, temp_str);
				retval = TRUE;
			}
			else
			{
				retval = FALSE;
			}
		}
		vm_free(remap_app_path);
		vm_free(temp_str);
		vm_free(temp_fn1);
		vm_free(temp_fn);
	}	
	//vm_log_debug("_vm_remap_usr_disk end");
	return retval ;
}

/**
 *	得到系统的文件系统的权限
 *
 *	@return 	VM_PERMISSION_SYS_DRV， VM_PERMISSION_USR_DRV
 */
VMINT _vm_get_disk_permission(void)
{
	return cur_file_sys_per;
}
#endif /*VRE_IO_REMAP*/


static void vm_findfirst_process_state_pro(VM_P_HANDLE phandle, VMINT pro_state)
{
	VMINT i = 0;
	
	switch(pro_state)
	{
		case VM_PMNG_UNLOAD:
			/*删除所有进程相关时钟*/
			while ( (i = vm_res_findfirst(phandle, VM_RES_TYPE_FILE_FIND)) != VM_RES_NOT_FIND)
			{
				vm_find_close(i);
				//vm_log_debug("vm_findfirst_process_state_pro : delete findfirst_handle=%d", i);
				vm_res_findclose(VM_RES_TYPE_FILE_FIND);
			}
			
			
			break;
		case VM_PMNG_FOREGROUND:
			break;
		case VM_PMNG_BACKGROUND:
			break;
	}
}

static void vm_file_process_state_pro(VM_P_HANDLE phandle, VMINT pro_state)
{
	VMINT i = 0;
	
	switch(pro_state)
	{
		case VM_PMNG_UNLOAD:
			/*删除所有进程相关时钟*/
			while ( (i = vm_res_findfirst(phandle, VM_RES_TYPE_FILE)) != VM_RES_NOT_FIND)
			{
				vm_file_close(i);
				//vm_log_debug("vm_file_process_state_pro : delete file_handle=%d", i);
				vm_res_findclose(VM_RES_TYPE_FILE);
			}
			
			
			break;
		case VM_PMNG_FOREGROUND:
			break;
		case VM_PMNG_BACKGROUND:
			break;
	}
}

static void vm_io_initial(void)
{
	vm_res_type_set_notify_callback(VM_RES_TYPE_FILE, vm_file_process_state_pro);
	vm_res_type_set_notify_callback(VM_RES_TYPE_FILE_FIND, vm_findfirst_process_state_pro);
}

static void vm_io_finialize(void)
{
	VMINT i = 0;

	while ( (i = vm_res_findfirst(-1, VM_RES_TYPE_FILE)) != VM_RES_NOT_FIND)
	{
		vm_file_close(i);
		//vm_log_debug("vm_io_finialize : delete file_handle=%d", i);
		vm_res_findclose(VM_RES_TYPE_FILE);
	}
	

	while ( (i = vm_res_findfirst(-1, VM_RES_TYPE_FILE_FIND)) != VM_RES_NOT_FIND)
	{
		vm_find_close(i);
		//vm_log_debug("vm_io_finialize : delete findfirst_handle=%d", i);
		vm_res_findclose(VM_RES_TYPE_FILE_FIND);
	}
	
			
	/*关闭系统通知回调*/
	vm_res_type_set_notify_callback(VM_RES_TYPE_FILE, NULL);
	vm_res_type_set_notify_callback(VM_RES_TYPE_FILE_FIND, NULL);
}

static VMINT vm_io_mod_evt_proc(VRE_MOD_LIFECIRCLE_EVT event)
{
	switch(event)
	{
		case EVT_MOD_INIT:
			vm_io_initial();
			break;
 		case EVT_MOD_RELEASE:
			vm_io_finialize();
			break;
	}
	return 0;
}

VMINT _vm_reg_io_module(void)
{
	int res = 0;

	if ((res = _vm_reg_module("IO MODULE", (MOD_EVT_PROCESS)vm_io_mod_evt_proc)) 
		!= REG_VRE_MODULE_SUCCESS)
	{
		//vm_log_debug("_vm_reg_io_modual : failed to register io module. errorcode=%d", res);
	}
	return res;
}

#endif
