/****************************************************************
 *Fuction 
 *	�ļ����ڴ��ѹ����ѹ
 *Description
 * 	1.�ð汾Ŀǰֻ֧���ļ���ѹ���ļ�ѹ���Լ��ڴ�ѹ����ѹ�ݲ�֧��  
 *	2.ʹ��ʾ�������ҳ�·���void gzip_file_decompress_demo(void)
 *
 ****************************************************************/

#ifndef VMGZIPVRE_H_
#define VMGZIPVRE_H_

#include "vmsys.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * gzip�㷨����ģʽ����Ϊ�ļ�ѹ�����ļ���ѹ���ڴ�ѹ�����ڴ��ѹ4��
 */
typedef enum
{
	GZIP_FILE_COMPRESS = 0,     							/*�ļ�ѹ��*/
	GZIP_FILE_DECOMPRESS,									/*�ļ���ѹ*/
	GZIP_MEMORY_COMPRESS,       							/*�ڴ�ѹ��*/
	GZIP_MEMORY_DECOMPRESS	    							/*�ڴ��ѹ*/
}gzip_work_mode_enum_t;		

/**
* gzip�㷨�ڴ����ģʽ
*/
typedef enum 
{
	GZIP_SAVE_DYNAMIC_RAM_MODE = 1,		  					/*ģʽ1����̬ramռ�õͣ�ֻ�����ڽ�ѹ*/
	GZIP_DEFAULT_DYNAMIC_RAM_MODE   			  			/*ģʽ2����̬ramռ�øߣ�ѹ����ѹ������*/
}gzip_memory_mode_enum_t;

/**
* ��ʼ���ķ�����
*/
typedef enum 
{
	GZIP_NOT_SUPPORT_FILE_COMPRESS = -4,					/*�ݲ�֧���ļ�ѹ��*/
	GZIP_NOT_SUPPORT_MEMORY_COMPRESS,						/*�ݲ�֧���ڴ�ѹ��*/
	GZIP_NOT_SUPPORT_MEMORY_DECOMPRESS,						/*�ݲ�֧���ڴ��ѹ*/
	GZIP_NOT_SUPPORT_MEMORY_MODE,							/*��֧�ֵ��ڴ����ģʽ*/
	GZIP_NO_ENOUGH_MEMORY,								/*û���㹻���ڴ�*/
	GZIP_INIT_SUCCESS										/*��ʼ���ɹ�*/
}gzip_init_return_enum_t;

/**
* ѹ����ѹ�ķ�����
*/
typedef enum
{
	GZIP_OTHER_ERROR = -10,              					/*��������*/
	GZIP_FILE_SAVE_NO_ENOUGH_MEMORY,
	GZIP_USER_MEMORY_IS_NULL_ERROR,							/*�û�δ���뻺��ռ�,�ڴ�ѹ����ѹ*/
	GZIP_NULL_POINTER_ERROR,								/*��ָ�����*/
	GZIP_OUTPUT_FILENAME_MEM_IS_NOT_NULL_ERROR,				/*gzip_file->output_filename��Ϊ�մ���*/
	GZIP_CREATE_OUTFILE_ERROR,           					/*��������ļ�����*/
	GZIP_GENERATE_OUTPUT_FILE_ERROR,     					/*��������ļ�������*/
	GZIP_FILE_OPEN_ERROR,                					/*���ļ�����*/
	GZIP_FILE_GETFILESIZE_ERROR,         					/*����ļ���С����*/
	GZIP_FILE_NAME_ERROR,          							/*�ļ�������*/
	GZIP_COMPRESS_OR_DECOMPRESS_ERROR,   					/*ѹ�����ѹ����*/
	GZIP_COMPRESS_OR_DECOMPRESS_SUCCESS 					/*ѹ�����ѹ�ɹ�*/
}gzip_run_return_enum_t;

/**
* ���ѹ�����ѹ�����Ļص�����
*/
typedef VMINT (*decnumber_callback)( VMINT current_size );

/**
* �ڴ�ѹ����ѹ�ṹ������
*/
typedef struct 
{
	VMINT8*  mem_inptr;    									/*��ѹ�������ѹ���ڴ�ָ�룬���û��ṩ����ռ�*/
	VMINT    mem_insize;   									/*��ѹ�������ѹ���ڴ泤��*/
	VMINT8*  mem_outptr;   									/*ѹ������ѹ����ڴ�ָ�룬���û��ṩ����ռ�*/
	VMINT    total_size;  									/*ѹ������ѹ���ܵ��ڴ泤��*/
	VMINT    current_size;									/* ѹ������ѹ��ǰ���ڴ泤�ȣ��������ڴ����ޣ�������ָ��ƫ��������ѹ�����ѹ�����Σ�
																current_size�״η��ص�ֵ����total_size��������ÿ�η��ص�ֵ����total_size��ȥ(ָ��ƫ����*ѹ�����ѹ����) */																					   
	VMINT    offset_length;  					  			/* �ں˵�outbuf��ָ��ƫ��������һ�ε���ʱ��Ϊ0���´ε���ʱ��Ϊ֮ǰ����
												  				�ýӿ�ʱ�û�����Ľ�ѹ����Ļ����ܺͣ����磺��һ�ε���ʱ���û�������
											      				1024 bytes��mem_outptr�ռ䣬��ô�������Ҫ����ѹ�����ѹ�����ڶ��ε���ʱ��
											      				��Ӧ��offset_length��Ϊ1024�����൱��1024���ֽ���һ�����յ�λ�������ڴ����ޣ�
											      				ֻ������1024���ֽ�������ѹ�����ѹ������ݡ���Ҫע�⣺Ϊ�˱�֤���ݵ���Ч�ԣ��ֶ�
											      				���յ����������밴������˳��ƴ�����������裺��һ�νӵ���11���ڶ��νӵ���22��
											      				�����νӵ���33������������Ӧ��ƴ��Ϊ��112233���������ܱ�֤��ȷ����֮������ڴ治���ޣ�
											      				���������һ���㹻���bufferһ���ԵĽ�������ѹ�����ѹ������ݡ� */
	decnumber_callback decnumberfunc;						/*�ص����������ѹ�����ѹ����*/
}gzip_mem_t;

/**
* �ļ�ѹ����ѹ�ṹ������
*/
typedef struct
{
	VMCHAR * input_filename;								/*  ��ѹ�������ѹ��ȫ·���ļ��������û��ṩ����ռ�
																��VRE���ļ�ϵͳ֧�ֵ�ȫ·�����ļ����Ƶ�������Ϊ260���ַ���
																���д�ѹ����ȫ·���ļ�����Ҫ����257���ַ�����Ԥ��3λ��'.gz����
																����ѹ��ȫ·���ļ�����Ҫ����260���ַ� */
	VMCHAR * output_filename; 								/* ѹ������ѹ���ȫ·���ļ�������Ҫ�û��ṩ����ռ�*/															   
	VMINT   path_select_sign;								/*�ļ�·��ѡ���־��
															  �����ΪTRUE,������ѹ�����ѹ��ָ�����ļ�·��output_filename;
															  �����ΪFALSE,���ļ����Զ��浽.gz�ļ�(����ѹ�ļ�)���ڵ�·��*/
	VMCHAR* get_output_filename;							/*��ȡѹ�����ѹ�ļ���ȫ·���ļ������û�����ҪҲ�����ṩ����ռ䣬
															  ��ֱ��ͨ����ָ��õ���ѹ�ļ���ȫ·���ļ�����ע��˲���Ӧ��vm_gzip_finalize֮ǰ
															  ���path_select_signΪTRUE�����·��Ϊoutput_filename��
															  ���path_select_signΪFALSE�����·��Ϊinput_filename���ڵ�·���£����ļ�������.gz*/
	VMINT   output_file_size;								/*ѹ������ѹ����ļ�size��ע��ò���Ӧ��vm_gzip_finalize֮ǰ����*/
	VMINT   output_filename_length;		    				/*ѹ������ѹ���ȫ·���ļ������ȣ�ע��ò���Ӧ��vm_gzip_finalize֮ǰ����*/
}gzip_file_t;

/**
* ѹ����ѹ��������
*/
typedef union
{
	gzip_file_t  *gzip_file;     							/*�ļ�ѹ����ѹ����*/ 
	gzip_mem_t   *gzip_mem;      							/*�ڴ�ѹ����ѹ����*/

}gzip_file_and_mem_t;

/**
 * ��ʼ��gizp�㷨��
 * ���gzip�㷨����buffer���ڴ�����
 *
 * @param[in]       work_mode			ѹ��ģʽ���ѹģʽ
 * @param[in] 		memory_mode			�ڴ����ģʽ
 *
 * @return 								�ɹ�����1��ʧ����ο���ʼ��������
 */
VMINT vm_gzip_init(gzip_work_mode_enum_t work_mode, gzip_memory_mode_enum_t memory_mode );

/**
 * ѹ�����ѹ���нӿ�
 * �����ļ����ڴ��ѹ������ѹ
 *
 * @param[in] 							file_or_mem  �ļ����ڴ��ѹ����ѹ������ָ��
 *
 * @return 								ѹ�����ѹ�ɹ�����1, ѹ�����ѹʧ�ܷ���0����������ֵ�ο�ѹ����ѹ������
 *
 */
VMINT vm_gzip_run(gzip_file_and_mem_t *file_or_mem);

/**
 * ���gzipѹ�����ѹ
 * gzipѹ�����ѹ�������ͷ�������ڴ���Դ
 *
*/
void vm_gzip_finalize(void);

#ifdef __cplusplus
}
#endif

#endif


/******************************************************************************************
 ******************************************************************************************	

void gzip_file_decompress_demo(void)
{
	gzip_file_and_mem_t * file_decompress = NULL;
	VMINT	init_return = 0;
	VMINT	run_return = 0;
	VMCHAR	outputfilename[260];	
	VMINT	filename_length;
	VMINT	file_size;	
	
	file_decompress = (gzip_file_and_mem_t*)vm_malloc(sizeof(gzip_file_and_mem_t));
	if (file_decompress == NULL)
	{
		return;
	}
	
	file_decompress->gzip_file = (gzip_file_t*)vm_malloc(sizeof(gzip_file_t));
	if (file_decompress->gzip_file == NULL)
	{
		if (file_decompress != NULL)
		{
			vm_free(file_decompress);
			file_decompress = NULL;
		}
		return;
	}
	
	file_decompress->gzip_file->input_filename = (VMCHAR*)vm_malloc(sizeof(VMCHAR)*260);
	if (file_decompress->gzip_file->input_filename == NULL)
	{			
		if (file_decompress->gzip_file != NULL)
		{
			vm_free(file_decompress->gzip_file);
			file_decompress->gzip_file =NULL;
		}
		if (file_decompress != NULL)
		{
			vm_free(file_decompress);
			file_decompress = NULL;
		}
		return;
	}
	
	init_return = vm_gzip_init(GZIP_FILE_DECOMPRESS, GZIP_SAVE_DYNAMIC_RAM_MODE);
	
	sprintf(file_decompress->gzip_file->input_filename, "%c:\\vre\\phsh.vxp.gz", vm_get_system_driver()); 
	
	if (init_return)
		run_return = vm_gzip_run(file_decompress);

	  if (run_return == 1)
	  {
		  filename_length = file_decompress->gzip_file->output_filename_length;
		  file_size = file_decompress->gzip_file->output_file_size;
		  vm_log_debug("file_decompress->gzip_file->output_filename = %s",
		  file_decompress->gzip_file->output_filename);
		  strcpy(outputfilename, file_decompress->gzip_file->output_filename);
	  }
	
	vm_gzip_finalize();
	
	if (file_decompress->gzip_file->input_filename != NULL)
	{
		vm_free(file_decompress->gzip_file->input_filename);
		file_decompress->gzip_file->input_filename = NULL;
	}
	if (file_decompress->gzip_file != NULL)
	{
		vm_free(file_decompress->gzip_file);
		file_decompress->gzip_file =NULL;
	}
	if (file_decompress != NULL)
	{
		vm_free(file_decompress);
		file_decompress = NULL;
	}
	return;
}

******************************************************************************************	
*****************************************************************************************/