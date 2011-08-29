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

#include "vmcert.h" 	//��� Ϊ�� ����Ļ��ת֧�� ����Ļ��������Ļ
#include "vmgettag.h" 


/*
 * ����ת����
 *///������ 20100706ȥ���� static
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
 * @�����ֻ���ǽֽ����ͨ���ֻ���������ǽֽ��
 * @����ǽֽ����Ϊǰ̨״̬����̨���е�״̬���øýӿ���Ч�� 
 * @ǽֽ�ĸ�ʽ��ʱֻ֧�� "BMP"��"GIF"��"JPG" ����ͼƬ��ʽ��
 * @���øýӿ�֮ǰ����Ҫɾ�����еĲ�
 * @param file_name	 ���ǽֽͼƬ��ȫ·�����Ϊ259�ַ�
 * @���׳�������ʧ�ܵĵط��� ͼƬ�Ĵ�С������ͼƬ�Ŀ�� 
 *
 * @return	����VM_WALLPAPER_SUCCEED��ʾ�����ɹ���
 * @return	����VM_WALLPAPER_ERR_WRONG_PARAM��ʾ·���ı����ʽ����ȷ����·��Ϊ�ջ����ļ������ڣ������ֻ�ϵͳ���ڴ治��
 * @return	����VM_WALLPAPER_ERR_UNSUPPORT_IMAGE_TYPE��֧�ֵ�ͼƬ����
 * @return	����VM_WALLPAPER_ERR_BASE_LAYER_EXIST���㻹���ڲ���������ǽֽ
 * @return	����VM_WALLPAPER_MIBR_NOT_FORE Ӧ�ô��ں�̨״̬ 
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
	
	if (vm_pmng_state(VM_PMNG_CUR_HANDLE) != VM_PMNG_FOREGROUND) //�������ǰ̨״̬�Ͳ���������ǽֽ
		return VM_WALLPAPER_MIBR_NOT_FORE;	
	
	if( layer_trans_tbl[0].used == TRUE) //���㻹���ھͲ���������ǽֽ
	{
		return VM_WALLPAPER_ERR_BASE_LAYER_EXIST;
	}


	
	if (file_name) //·����Ϊ��
	{
		struct vm_fileinfo_ext info;
		VMINT find_hdl =  -1;
		VMINT file_length =0;

		file_length =wstrlen(file_name);
		if(file_length>259) 	//�ļ��ĳ��ȵİ�ȫ���ж�
		{		
			vm_log_error("[vmgraph] vm_set_active_wallpaper filename =%d , ", file_length);
			return VM_WALLPAPER_ERR_WRONG_PARAM;
		}
		
			
		find_hdl = vm_find_first_ext(file_name , &info);
		if(find_hdl < 0) //û���ҵ�����ļ�
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

			if( info.filesize >= sys_driver_size ) //��ѯ ϵͳ�̲��������� ��ǽֽͼƬ
				{
					return  VM_WALLPAPER_ERR_WRONG_PARAM;
				}

			if( !mmi_fmgr_util_file_limit_check(g_fmgr_wallpaper_limit_arry, (PS8)file_name, &error_str_pp) )
			{
				return VM_WALLPAPER_ERR_WRONG_PARAM;
			}
	
			for( i=0; i<3; i++)
			{ 
				if(info.extension[i]< 'a') //��׺ȫ���ĳ�Сд�ַ�
				{
					info.extension[i] +=32; 
				}
			}

			
			if( (strncmp("bmp", info.extension,3)== 0)
				|| (strncmp("gif", info.extension,3)== 0)
				|| (strncmp("jpg", info.extension,3)== 0) )
			{
				g_phnset_cntx_p->wpss_type = MMI_PHNSET_TYPE_WP; //���ֵ���Բ��ñ��棬��Ϊ���������wallpaper,screen saver, power on off display�����õĶ�����
				phnset_dispchar_strp = OslMalloc(FMGR_PATH_BUFFER_SIZE); //����������ɺ���PhnsetWpUsrDefFreeBuf()���
				mmi_ucs2cpy(phnset_dispchar_strp, (S8*)file_name);
				vre_phnset_copy_wpss_check_device(); 		//�첽��������������ʾpopup
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
	else //·��Ϊ�� 
	{
		return VM_WALLPAPER_ERR_WRONG_PARAM;
	}
}


#endif  /* __VRE__ */
