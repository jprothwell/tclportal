#ifdef __VRE__

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#include "vmopt.h"
#include "vmio.h"
#include "vmsys.h"
#include "vmchset.h"
#include "vmhttp.h"
#include "vmlog.h"
#include "vminifile.h"
#include "vmsock.h"

extern VMINT vm_get_memory_pool_size(void);

/* �����ļ� */
static char options_file[50];


/* ��ʼ����־ */
static int options_file_init = 0;


/* 
 * ��־�������(TRUE--�����־��FALSE--�������־)��
 */						
//static 
int logOut = TRUE;	

/* 
 * ��־�������				
 */
//static 
int logLevel = VM_FATAL_LEVEL;

/* 
 * ��catcher�����־����(TRUE--��catcher�����־��FALSE--���ļ������־)��			
 */
//static 
int logMtk = FALSE;

#ifdef VRE_ENABLE_LOG
char logModule[VRE_MAX_C_FILE_COUNT * VRE_MAX_C_FILENAME_LEN]; // = {0};
extern int _logAllModule;
#endif

/* 
 * �ڴ�ص���������λΪKB��
 */						
static int dMemSize = VRE_SYS_MEMPOOL_SIZE;									


/* ��������Ϣkey���� 
static char *section = "Options";
static char *log_key = "log_level";
static char *log_out_key = "log_out";
static char *log_mtk_key = "log_mtk";
static char *memory_key = "dynamic_memory";*/
#define section			"Options"
#define log_key 			"log_level"
#define log_out_key		"log_out"
#define log_mtk_key		"log_mtk"
#define memory_key		"dynamic_memory"
#define log_module_key	"log_module"


int vre_get_options_dynamic_memory(void);
int vre_get_options_log_level(void);
int vre_get_options_log_out(void);
int vre_get_options_log_mtk(void);

void vre_set_options_log_level(int log_level);
void vre_set_options_log_out(int log_out);
void vre_set_options_log_mtk(int log_mtk);

void vre_set_options_dynamic_memory(int dy_mem_size);

/* ����ϵͳ��־���� */
void vre_set_options_log_level(int log_level) 
{
	char buf[64] = {0};
	
	if(!options_file_init) 
		return;
	
	sprintf(buf, "%d\t", log_level);
	if(vm_write_profile_string(section, log_key, buf, options_file))
	{
		logLevel = log_level;
		vm_log_debug("Options Log Level Change:%d",vre_get_options_log_level());
	}
}

/* ����ϵͳ��־�������*/
void vre_set_options_log_out(int log_out) 
{
	char buf[64] = {0};
	
	if(!options_file_init) 
		return;
	
	sprintf(buf, "%d\t", log_out);
	if(vm_write_profile_string(section, log_out_key, buf, options_file))
	{
		logOut = log_out;
		vm_log_debug("Options Log Out Change:%d",vre_get_options_log_out());
	}
}

/* ������catcher�����־����*/
void vre_set_options_log_mtk(int log_mtk) 
{
	char buf[64] = {0};
	
	if(!options_file_init) 
		return;
	
	sprintf(buf, "%d\t", log_mtk);
	if(vm_write_profile_string(section, log_mtk_key, buf, options_file))
	{
		logMtk = log_mtk;
		vm_log_debug("Options Log Mtk Change:%d",vre_get_options_log_mtk());
	}
}

/*����ϵͳ��̬�ڴ��С*/
void vre_set_options_dynamic_memory(int dy_mem_size) 
{
	char buf[64] = {0};
	
	if(!options_file_init) 
		return;
	sprintf(buf,"%d\t",dy_mem_size);
	
	if(vm_write_profile_string(section, memory_key, buf, options_file))
	{	
		dMemSize = dy_mem_size;
		vm_log_debug("Options Dynamic Memory Size Change:%d",vre_get_options_dynamic_memory());
	}
}

/*ȡ��־��������*/
int vre_get_options_log_level(void) 
{
	return logLevel;
}

/*ȡ��־�������*/
int vre_get_options_log_out(void) 
{
	return logOut;
}

/*ȡ��catcher�����־����*/
int vre_get_options_log_mtk(void) 
{
	return logMtk;
}


/*ȡ��̬�ڴ��С����*/
int vre_get_options_dynamic_memory(void) 
{
	return dMemSize;
	//return VRE_SYS_MEMPOOL_SIZE;
}

/**
 * ��ȡVRE��optionѡ����OPEN_RESOURCE_MANAGER_DEBUG_MODE
 * ����걻�򿪣���ôVRE�����Բ����е�filename��λ�ú�����
 * ����optionѡ��������ļ���
 */
VMINT vre_options_init(char* filename)
{
	struct vm_fileinfo_t file;
	VMINT findHandle = -1;
	

	if(!filename || strlen(filename) ==0)
		return FALSE;

	sprintf(options_file, "%s", filename);
	options_file_init = 1;
		
	//if ((findHandle = vm_find_first(vm_ucs2_string(options_file), &file)) >= 0)
	if ((findHandle = vm_find_first(vm_ucs2_string_by_ascii(options_file), &file)) >= 0)
	{
		vm_find_close(findHandle);
		logLevel = vm_read_profile_int(section, log_key, VM_WARN_LEVEL, options_file);
		/**
		dMemSize = vm_read_profile_int(section, memory_key, 
			vm_get_memory_pool_size() , options_file);
			**/
		logOut = vm_read_profile_int(section, log_out_key, TRUE, options_file);
#ifdef VRE_ENABLE_LOG
		if (logOut)
		{
			if (vm_read_profile_string(section, log_module_key, logModule, sizeof(logModule), VRE_DEFAULT_LOG_MODULE, options_file) )
			{
				vm_log_debug("[OPTIONS] module log configuration read. logModule:");
				vm_log_long(logModule, strlen(logModule));
				
				_logAllModule = strchr(logModule, '*') ? TRUE : FALSE;
			}
			else
			{
				vm_log_error("[OPTIONS] read log configuration of modules error!!!");
			}
		}
#endif
		logMtk = vm_read_profile_int(section, log_mtk_key, FALSE, options_file);
		vm_log_warn("VRE Options:logLevel=%d, logOut=%d, logMtk=%d", logLevel, logOut, logMtk);
	}
	else
	{
		logLevel = VM_WARN_LEVEL;
	
		/**
		dMemSize = vm_get_memory_pool_size();
		**/
		logOut = TRUE;
		logMtk = FALSE;
#ifdef OPEN_RESOURCE_MANAGER_DEBUG_MODE
		vre_set_options_log_level(logLevel);
		/*
		vre_set_options_dynamic_memory(dMemSize);
		*/
		vre_set_options_log_out(logOut);
		vre_set_options_log_mtk(logMtk);
#endif	
	}	
	
	 dMemSize = VRE_SYS_MEMPOOL_SIZE;
	vm_log_warn("VRE Options: log_level=%d, dynamic_memory=%d, log_out=%d, log_mtk=%d, findHandle=%d",
		logLevel, dMemSize, logOut, logMtk, findHandle);

	return (findHandle >= 0 ? TRUE : FALSE);
}
#endif

