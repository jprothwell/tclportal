/****************************************************************
 *Fuction 
 *	文件和内存的压缩解压
 *Description
 * 	1.该版本目前只支持文件解压，文件压缩以及内存压缩解压暂不支持  
 *	2.使用示例请见本页下方，void gzip_file_decompress_demo(void)
 *
 ****************************************************************/

#ifndef VMGZIPVRE_H_
#define VMGZIPVRE_H_

#include "vmsys.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * gzip算法工作模式，分为文件压缩、文件解压、内存压缩和内存解压4种
 */
typedef enum
{
	GZIP_FILE_COMPRESS = 0,     							/*文件压缩*/
	GZIP_FILE_DECOMPRESS,									/*文件解压*/
	GZIP_MEMORY_COMPRESS,       							/*内存压缩*/
	GZIP_MEMORY_DECOMPRESS	    							/*内存解压*/
}gzip_work_mode_enum_t;		

/**
* gzip算法内存分配模式
*/
typedef enum 
{
	GZIP_SAVE_DYNAMIC_RAM_MODE = 1,		  					/*模式1，动态ram占用低，只能用于解压*/
	GZIP_DEFAULT_DYNAMIC_RAM_MODE   			  			/*模式2，动态ram占用高，压缩解压均适用*/
}gzip_memory_mode_enum_t;

/**
* 初始化的返回码
*/
typedef enum 
{
	GZIP_NOT_SUPPORT_FILE_COMPRESS = -4,					/*暂不支持文件压缩*/
	GZIP_NOT_SUPPORT_MEMORY_COMPRESS,						/*暂不支持内存压缩*/
	GZIP_NOT_SUPPORT_MEMORY_DECOMPRESS,						/*暂不支持内存解压*/
	GZIP_NOT_SUPPORT_MEMORY_MODE,							/*不支持的内存分配模式*/
	GZIP_NO_ENOUGH_MEMORY,								/*没有足够的内存*/
	GZIP_INIT_SUCCESS										/*初始化成功*/
}gzip_init_return_enum_t;

/**
* 压缩解压的返回码
*/
typedef enum
{
	GZIP_OTHER_ERROR = -10,              					/*其他错误*/
	GZIP_FILE_SAVE_NO_ENOUGH_MEMORY,
	GZIP_USER_MEMORY_IS_NULL_ERROR,							/*用户未申请缓存空间,内存压缩解压*/
	GZIP_NULL_POINTER_ERROR,								/*空指针错误*/
	GZIP_OUTPUT_FILENAME_MEM_IS_NOT_NULL_ERROR,				/*gzip_file->output_filename不为空错误*/
	GZIP_CREATE_OUTFILE_ERROR,           					/*生成输出文件错误*/
	GZIP_GENERATE_OUTPUT_FILE_ERROR,     					/*产生输出文件名错误*/
	GZIP_FILE_OPEN_ERROR,                					/*打开文件错误*/
	GZIP_FILE_GETFILESIZE_ERROR,         					/*获得文件大小错误*/
	GZIP_FILE_NAME_ERROR,          							/*文件名错误*/
	GZIP_COMPRESS_OR_DECOMPRESS_ERROR,   					/*压缩或解压错误*/
	GZIP_COMPRESS_OR_DECOMPRESS_SUCCESS 					/*压缩或解压成功*/
}gzip_run_return_enum_t;

/**
* 获得压缩或解压次数的回调声明
*/
typedef VMINT (*decnumber_callback)( VMINT current_size );

/**
* 内存压缩解压结构体声明
*/
typedef struct 
{
	VMINT8*  mem_inptr;    									/*待压缩或待解压的内存指针，由用户提供缓存空间*/
	VMINT    mem_insize;   									/*待压缩或待解压的内存长度*/
	VMINT8*  mem_outptr;   									/*压缩后或解压后的内存指针，由用户提供缓存空间*/
	VMINT    total_size;  									/*压缩后或解压后总的内存长度*/
	VMINT    current_size;									/* 压缩后或解压后当前的内存长度，适用于内存受限，需设置指针偏移量连续压缩或解压的情形，
																current_size首次返回的值等于total_size，接下来每次返回的值等于total_size减去(指针偏移量*压缩或解压次数) */																					   
	VMINT    offset_length;  					  			/* 内核的outbuf的指针偏移量，第一次调用时设为0，下次调用时设为之前调用
												  				该接口时用户申请的解压缩后的缓存总和；例如：第一次调用时，用户申请了
											      				1024 bytes的mem_outptr空间，那么如果还需要继续压缩或解压，即第二次调用时，
											      				则应将offset_length设为1024，即相当于1024个字节是一个接收单位，由于内存受限，
											      				只能由这1024个字节来接收压缩或解压后的数据。但要注意：为了保证数据的有效性，分段
											      				接收的数据最后必须按传出的顺序拼接起来，假设：第一次接的是11，第二次接的是22，
											      				第三次接的是33，则最终数据应该拼接为：112233，这样才能保证正确。反之，如果内存不受限，
											      				则可以申请一个足够大的buffer一次性的接收整个压缩或解压后的数据。 */
	decnumber_callback decnumberfunc;						/*回调函数：获得压缩或解压次数*/
}gzip_mem_t;

/**
* 文件压缩解压结构体声明
*/
typedef struct
{
	VMCHAR * input_filename;								/*  待压缩或待解压的全路径文件名。由用户提供缓存空间
																因VRE的文件系统支持的全路径的文件名称的最大个数为260个字符，
																其中待压缩的全路径文件名不要超过257个字符，需预留3位存'.gz’；
																待解压的全路径文件名不要超过260个字符 */
	VMCHAR * output_filename; 								/* 压缩后或解压后的全路径文件名，需要用户提供缓存空间*/															   
	VMINT   path_select_sign;								/*文件路径选择标志；
															  如果设为TRUE,则将数据压缩或解压到指定的文件路径output_filename;
															  如果设为FALSE,则文件会自动存到.gz文件(待解压文件)所在的路径*/
	VMCHAR* get_output_filename;							/*获取压缩或解压文件的全路径文件名；用户不需要也不能提供缓存空间，
															  可直接通过该指针得到解压文件的全路径文件名，注意此操作应在vm_gzip_finalize之前
															  如果path_select_sign为TRUE，则该路径为output_filename；
															  如果path_select_sign为FALSE，则该路径为input_filename所在的路径下，其文件名少了.gz*/
	VMINT   output_file_size;								/*压缩后或解压后的文件size，注意该操作应在vm_gzip_finalize之前进行*/
	VMINT   output_filename_length;		    				/*压缩后或解压后的全路径文件名长度，注意该操作应在vm_gzip_finalize之前进行*/
}gzip_file_t;

/**
* 压缩解压联合声明
*/
typedef union
{
	gzip_file_t  *gzip_file;     							/*文件压缩解压功能*/ 
	gzip_mem_t   *gzip_mem;      							/*内存压缩解压功能*/

}gzip_file_and_mem_t;

/**
 * 初始化gizp算法。
 * 完成gzip算法各个buffer的内存申请
 *
 * @param[in]       work_mode			压缩模式或解压模式
 * @param[in] 		memory_mode			内存分配模式
 *
 * @return 								成功返回1，失败请参考初始化返回码
 */
VMINT vm_gzip_init(gzip_work_mode_enum_t work_mode, gzip_memory_mode_enum_t memory_mode );

/**
 * 压缩或解压运行接口
 * 发起文件或内存的压缩、解压
 *
 * @param[in] 							file_or_mem  文件或内存的压缩解压的联合指针
 *
 * @return 								压缩或解压成功返回1, 压缩或解压失败返回0，其他返回值参考压缩解压返回码
 *
 */
VMINT vm_gzip_run(gzip_file_and_mem_t *file_or_mem);

/**
 * 完成gzip压缩或解压
 * gzip压缩或解压结束后，释放申请的内存资源
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