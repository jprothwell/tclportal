#ifdef __VRE__
#include "vmsys.h"
#include "vmtheme.h"
#include "vmsaltheme.h"

#include "mmi_include.h"
#include "vmmacrostub.h"
#include "vmchset.h"
#include "vmlog.h"
#include "vmstdlib.h"
#include "vmopt.h"
#include "string.h"
#include "math.h"
#include "vmsys.h"
#include "vmio.h"
#include "vmmod.h"
#include "vmresmng.h"
#include "vmpromng.h"

#include "vmcert.h" 	//添加 为了 做屏幕翻转支持 横屏幕启动竖屏幕
#include "vmgettag.h" 


/*
 * 层句柄转换表。
 *///王传祥 20100706去掉的 static
// extern layer_param_t layer_trans_tbl[16];
typedef struct _layer_param_t {
	VMUINT handle;
	VMINT   trans_color;
	VMINT   x;
	VMINT   y;
	VMINT   width;
	VMINT   height;
	VMUINT8* buffer;
	VMUINT8* canvas;
	VMINT   mibrhandle;
	VMINT   rotate;
	VMINT   used;
	VMINT   all_delete;
    VMUINT  flag;
} layer_param_t;

extern  layer_param_t layer_trans_tbl[];


/*VMINT vm_set_active_theme(VMUSTR file_name)
{
	VMINT result = FALSE;
	if (file_name != NULL)
		result = vm_sal_set_active_theme(file_name);

	return result;
	
}*/


/*VMINT vm_set_active_wallpaper(VMCHAR *file_name)
{
	VMINT result = FALSE;
	if (file_name != NULL)
		 //result= vm_sal_set_active_wallpaper(file_name);	
	{
	vm_log_fatal("[vmtheme]:vm_set_active_wallpaper1111");
		g_phnset_cntx_p->wpss_type == MMI_PHNSET_TYPE_WP;
			vm_log_fatal("[vmtheme]:vm_set_active_wallpaper2222");
		result = PhnsetSetWallpaperByFileName(file_name); //S8*
			vm_log_fatal("[vmtheme]:vm_set_active_wallpaper333");
	}
	return result;
}*/




/*
 * @设置手机的墙纸，不通过手机本地设置墙纸。
 * @设置墙纸必须为前台状态，后台运行的状态调用该接口无效。 
 * @墙纸的格式暂时只支持 "BMP"，"GIF"，"JPG" 三种图片格式，
 * @调用该接口之前必须要删除所有的层
 * @param file_name	 存放墙纸图片的全路径，最长为259字符
 * @容易出现设置失败的地方有 图片的大小，还有图片的宽高 
 *
 * @return	返回VM_WALLPAPER_SUCCEED表示操作成功。
 * @return	返回VM_WALLPAPER_ERR_WRONG_PARAM表示路径的编码格式不正确或者路径为空或者文件不存在，或者手机系统盘内存不足
 * @return	返回VM_WALLPAPER_ERR_UNSUPPORT_IMAGE_TYPE不支持的图片类型
 * @return	返回VM_WALLPAPER_ERR_BASE_LAYER_EXIST基层还存在不可以设置墙纸
 * @return	返回VM_WALLPAPER_MIBR_NOT_FORE 应用处在后台状态 
 */

#include "PhoneSetup.h"
#include "FileMgrServicehdlr.h"
extern PHNSET_CNTX g_phnset_cntx;
extern void vre_phnset_copy_wpss_check_device(void);
extern void PhnsetWpUsrDefFreeBuf(void);
extern const S32 g_fmgr_wallpaper_limit_arry[];




VMINT vm_set_active_wallpaper(VMWCHAR* file_name)
{	

	
	vm_log_error("[vmgraph] :vm_set_active_wallpaper  start");
#ifdef __VRE_RB_08A__

			return VM_WALLPAPER_ERR_UNSUPPORT_IMAGE_TYPE;
#endif
	
	if (vm_pmng_state(VM_PMNG_CUR_HANDLE) != VM_PMNG_FOREGROUND) //如果不在前台状态就不可以设置墙纸
		return VM_WALLPAPER_MIBR_NOT_FORE;	
	
	if( layer_trans_tbl[0].used == TRUE) //基层还存在就不可以设置墙纸
	{
		return VM_WALLPAPER_ERR_BASE_LAYER_EXIST;
	}


	
	if (file_name) //路径不为空
	{
		struct vm_fileinfo_ext info;
		VMINT find_hdl =  -1;
		VMINT file_length =0;

		file_length =wstrlen(file_name);
		if(file_length>259) 	//文件的长度的安全性判断
		{		
			vm_log_error("[vmgraph] vm_set_active_wallpaper filename =%d , ", file_length);
			return VM_WALLPAPER_ERR_WRONG_PARAM;
		}
		
			
		find_hdl = vm_find_first_ext(file_name , &info);
		if(find_hdl < 0) //没有找到这个文件
		{
			vm_find_close_ext(find_hdl);
			vm_log_error("[vmgraph] vm_set_active_wallpaper not find file");
			return	VM_WALLPAPER_ERR_WRONG_PARAM;
		}
		else
		{
			VMINT i =0;

			VMINT sys_driver = -1;
			VMUINT sys_driver_size = 0;

			PS8 error_str_pp;
			
			vm_find_close_ext(find_hdl); 
						
			 	if ((sys_driver = vm_get_system_driver()) >= 0)
			  {
			      VMCHAR driver_str[2] = {0};
			      
			      sprintf(driver_str, "%c", (VMCHAR)sys_driver);
			      sys_driver_size = vm_get_disk_free_space(vm_ucs2_string(driver_str));
			  }

			if( info.filesize >= sys_driver_size ) //查询 系统盘不足以容纳 该墙纸图片
				{
					return  VM_WALLPAPER_ERR_WRONG_PARAM;
				}

			if( !mmi_fmgr_util_file_limit_check(g_fmgr_wallpaper_limit_arry, (PS8)file_name, &error_str_pp) )
			{
				return VM_WALLPAPER_ERR_WRONG_PARAM;
			}
	
			for( i=0; i<3; i++)
			{ 
				if(info.extension[i]< 'a') //后缀全都改成小写字符
				{
					info.extension[i] +=32; 
				}
			}

			
			if( (strncmp("bmp", info.extension,3)== 0)
				|| (strncmp("gif", info.extension,3)== 0)
				|| (strncmp("jpg", info.extension,3)== 0) )
			{
				g_phnset_cntx_p->wpss_type = MMI_PHNSET_TYPE_WP; //这个值可以不用保存，因为不会出现在wallpaper,screen saver, power on off display中设置的动作。
				phnset_dispchar_strp = OslMalloc(FMGR_PATH_BUFFER_SIZE); //请在设置完成后用PhnsetWpUsrDefFreeBuf()清除
				mmi_ucs2cpy(phnset_dispchar_strp, (S8*)file_name);
				vre_phnset_copy_wpss_check_device(); 		//异步操作，但不会显示popup
				PhnsetWpUsrDefFreeBuf();
				return VM_WALLPAPER_SUCCEED;
			}
			else
			{
				vm_log_error("[vmgraph] vm_set_active_wallpaper VM_GDI_ERR_UNSUPPORT_IMAGE_TYPE");
				return 	VM_WALLPAPER_ERR_UNSUPPORT_IMAGE_TYPE;
			}
		}		
	}
	else //路径为空 
	{
		return VM_WALLPAPER_ERR_WRONG_PARAM;
	}
}


#endif  /* __VRE__ */
