#ifdef __VRE__
#include "mmi_include.h"
#include "Conversions.h"

#include "kal_trace.h"

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "vmlog.h"
#include "vmio.h"
#include "vmsys.h"
#include "vmchset.h"
#include "vmpromng.h"

#ifdef WIN32
//#include "windows.h"
#endif

#ifdef VRE_ENABLE_LOG

static int log_file;
static int log_init;
//commented by minqi.lin - 2010-02-02
//static int def_log_level;
//static int def_log_mtk;
//static int def_log_out;

//added by minqi.lin - 2010-02-02
/************************************************************************************
 * from vmoption.c 
 */
/* 
 * 日志输出开关(TRUE--输出日志，FALSE--不输出日志)。
 */						
//static 
extern int logOut;	

/* 
 * 日志输出级别				
 */
//static 
extern int logLevel;

/* 
 * 向catcher输出日志开关(TRUE--向catcher输出日志，FALSE--向文件输出日志)。			
 */
//static 
extern int logMtk;

/*Temperaly used for compitable with original codes*/
#define def_log_level		logLevel
#define def_log_mtk		logMtk
#define def_log_out		logOut

extern char logModule[VRE_MAX_C_FILE_COUNT * VRE_MAX_C_FILENAME_LEN];

/*
 * from vmoption.c 
 ************************************************************************************/

static char _modFile[VRE_MAX_C_FILENAME_LEN];	// = {0}; without this expression, the code size can reduce VRE_MAX_C_FILENAME_LEN

static char * _cache_file_ = NULL;	/*Pointer to the filename of current running file*/
static int _lineNo = 0;				/*Line No. of current running file*/

int _logAllModule = 0;		/*Project wide global BOOL variable, in charege of whether to log all the modules*/

static void log_it(VMINT level, char* fmt, va_list ap);

#define MOD_VRE MOD_CUSTOM1
void vm_trace(char* text)
{
	kal_wap_trace(MOD_VRE, TRACE_INFO, "[MOD_VRE]%s", text);
	
}

void vm_log_init(char* filename, int log_level) {
	char wfilename[100];
	UINT written = 0;
	char text[128];
	int result;
   
  //CHSET_ASCII,	   
	result = mmi_chset_convert(
				MMI_CHSET_ASCII, 
				MMI_CHSET_UCS2, 				
				(VMCHAR *)filename, 
				(VMCHAR *)wfilename, 
				100);

	if (result <= 0)
	{
		sprintf(text, "mmi_chset_convert result=%d", result);
		vm_trace(text);
		
		log_init = 0;
		return;
	}

	sprintf(text, "vre 3.0.75 AM 0416 log start -%s","Daily Build-2010-05-26 with 10.22!");
	strcat(text, "\n\0");
	
	vm_trace(text);
	
			//使用在原有文件尾部添加数据方式
		if ((log_file = FS_Open((WCHAR *)wfilename,FS_CREATE_ALWAYS)) < 0) 
		{
			log_init = 0;
			return;
		}

		if (FS_Write(log_file, text, (VMUINT)strlen(text), &written) < 0)
		{
			FS_Close(log_file);
			log_init = 0;
			return;
		}
	
		if (FS_Commit(log_file) < 0)
		{
			FS_Close(log_file);
			log_init = 0;
			return;
		}
	
	
	def_log_level = log_level;
	log_init = 1;
	def_log_out = 1;
	def_log_mtk = 0;
	
	strcpy(logModule, VRE_DEFAULT_LOG_MODULE);
	_modFile[0] = 0;
	_cache_file_ = NULL;
	_lineNo = 0;
	_logAllModule = TRUE;
}

/*
void vm_log_debug(char* fmt, ...) {
	va_list ap;

	if (log_init && (def_log_level >= VM_DEBUG_LEVEL) && def_log_out) {
		va_start(ap, fmt);
		log_it(VM_DEBUG_LEVEL, fmt, ap);
		va_end(ap);
	}
}

void vm_log_info(char* fmt, ...) {
	va_list ap;

	if (log_init && (def_log_level >= VM_INFO_LEVEL) && def_log_out) {
		va_start(ap, fmt);
		log_it(VM_INFO_LEVEL, fmt, ap);
		va_end(ap);
	}
}

void vm_log_warn(char* fmt, ...) {
	va_list ap;

	if (log_init && (def_log_level >= VM_WARN_LEVEL) && def_log_out) {
		va_start(ap, fmt);
		log_it(VM_WARN_LEVEL, fmt, ap);
		va_end(ap);
	}
}

void vm_log_error(char* fmt, ...) {
	va_list ap;

	if (log_init && (def_log_level >= VM_ERROR_LEVEL) && def_log_out) {
		va_start(ap, fmt);
		log_it(VM_ERROR_LEVEL, fmt, ap);
		va_end(ap);
	}
}

void vm_log_fatal(char* fmt, ...) {
	va_list ap;

	if (log_init && (def_log_level >= VM_FATAL_LEVEL) && def_log_out) {
		va_start(ap, fmt);
		log_it(VM_FATAL_LEVEL, fmt, ap);
		va_end(ap);
	}
}
*/
void _vm_log_debug(char* fmt, ...) {
	va_list ap;

	if (log_init && (def_log_level >= VM_DEBUG_LEVEL) && def_log_out) {
		va_start(ap, fmt);
		log_it(VM_DEBUG_LEVEL, fmt, ap);
		va_end(ap);
	}
}

void _vm_log_info(char* fmt, ...) {
	va_list ap;

	if (log_init && (def_log_level >= VM_INFO_LEVEL) && def_log_out) {
		va_start(ap, fmt);
		log_it(VM_INFO_LEVEL, fmt, ap);
		va_end(ap);
	}
}

void _vm_log_warn(char* fmt, ...) {
	va_list ap;

	if (log_init && (def_log_level >= VM_WARN_LEVEL) && def_log_out) {
		va_start(ap, fmt);
		log_it(VM_WARN_LEVEL, fmt, ap);
		va_end(ap);
	}
}

void _vm_log_error(char* fmt, ...) {
	va_list ap;

	if (log_init && (def_log_level >= VM_ERROR_LEVEL) && def_log_out) {
		va_start(ap, fmt);
		log_it(VM_ERROR_LEVEL, fmt, ap);
		va_end(ap);
	}
}

void _vm_log_fatal(char* fmt, ...) {
	va_list ap;

	if (log_init && (def_log_level >= VM_FATAL_LEVEL) && def_log_out) {
		va_start(ap, fmt);
		log_it(VM_FATAL_LEVEL, fmt, ap);
		va_end(ap);
	}
}



extern VMINT vm_pmng_get_current_handle_ignore_status(void);
void log_it(VMINT level, char* fmt, va_list ap) 
{
	vm_time_t tm;
	VM_P_HANDLE phandle;
	char text[260], level_text[10] = {0};
	VMUINT written;
#ifdef WIN32
	//char szMsg[1024];
#endif

	if (!log_init)
		return ;

	memset(text, 0x00, sizeof(text));
	memset(level_text, 0x00, sizeof(level_text));
	
	switch(level)
	{
	case VM_DEBUG_LEVEL:
		strcpy(level_text, "DEBUG");
		break;
	case VM_INFO_LEVEL:
		strcpy(level_text, "INFO");
		break;
	case VM_WARN_LEVEL:
		strcpy(level_text, "WARN");
		break;
	case VM_ERROR_LEVEL:
		strcpy(level_text, "ERROR");
		break;
	default:
		strcpy(level_text, "FATAL");
		break;
	};
	
	vm_get_time(&tm);
	phandle = vm_pmng_get_current_handle_ignore_status();
	sprintf(text, "%d-%02.2d-%02.2d %02.2d:%02.2d:%02.2d [%s][PID:%d][%s:%d]- ", tm.year, tm.mon, tm.day, tm.hour,
		tm.min, tm.sec, level_text, phandle, _modFile, _lineNo);
	vsprintf(text + strlen(text), fmt, ap);
	strcat(text, "\n\0");

	if(def_log_mtk)
	{
		vm_trace(text);
	}
	else
	{
		if (FS_Write(log_file, text, (VMUINT)strlen(text), &written) < 0)
		{
			FS_Close(log_file);
			log_init = 0;
			return;
		}
		if (FS_Commit(log_file) < 0)
		{
			FS_Close(log_file);
			log_init = 0;
			return;
		}
	}
	#ifdef WIN32
	//sprintf( szMsg, "%s", text);
	//OutputDebugString(szMsg);
	#endif
	
}

void vm_log_close(void) {
	if (log_init) 
	{
		FS_Commit(log_file);
		FS_Close(log_file);
		log_init = 0;
		def_log_out = 1;
		def_log_mtk = 0;
		def_log_level = VM_WARN_LEVEL;
	}
}

//void vm_set_log_out(int log_out)
//{
//	def_log_out = log_out;
//}
//void vm_set_log_level(int log_level)
//{
//	def_log_level = log_level;
//}

//void vm_set_log_mtk(int log_mtk)
//{
//	def_log_mtk = log_mtk;
//}

void _vm_log_long(char *fmt, int len)
{
  	if (len > 0 && len < 200) {
		_vm_log_debug("\n%s", fmt);
  	} else if (len > 200) {
		char text[200];
		int i = 0, t_size = sizeof(text); 
		//char *text=(char*)vm_malloc(t_size);
		//if (NULL == text) return;
		_vm_log_debug("\nLONG LOG==================================================");
		while (i < len) {													
			memset(text, 0,  t_size);						
			memcpy(text, fmt+i, t_size-1<len-i ? t_size-1 : len-i);	
			_vm_log_debug("\n%s", text);								
			i += t_size-1; 
		}
		_vm_log_debug("\nLONG LOG==================================================");
		//vm_free(text); 
	}
}

int _vm_log_module(const char* __file__, const int __line__)
{
	static unsigned int _cache_ret_;

	//_vm_log_debug("[LOG] enter _vm_log_module - __FILE__[%p:%s] vs. cache[%p][%d][%d]; _logAllModule[%d]",  
	//	__file__,__file__, _cache_file_, _lineNo, _cache_ret_, _logAllModule);
	//_vm_log_long(logModule, strlen(logModule));

	/*
	 * _lineNo is used in log_it, which let us know clearly where the log action happened.
	 * The value of _lineNo is always changing, thus we have to update its value everytime.
	 */
	_lineNo = __line__;	
	
	/*
	 * check if the cache is match. 
	 * 	if match, directly return the cache result.
	 * 	if not match, do more checking.
	 */
	if (_cache_file_ != __file__)	
	{
		int i = 0;
		char * p = NULL;

		/*updating the cache, save the address of constant string __FILE__*/
		_cache_file_ = (char*)__file__;

		/*
		 * set "p" to the start address of "xxxx.c"
		 *			
		 * p = strstr(__file__, ".c");			//1
		 * p = __file__ + strlen(__file__) - 2;	//2
		 * 1 is obviously slower than 2, but more flexible.
		 * A faster but unflexible method is given below:
		 */
		switch (__file__[0])
		{
/*NOTE:
__file__ example:	
//SAL
"vmsys.c"
"vendor\vre30\src\arch\mtk\vmsim.c"
//CORE
"dlmalloc.c"
"core\dlmalloc.c"
"src\core\dlmalloc.c"

!!!NOTICE:
In order to speed up the string matching, 
t's better to make sure that the objs in vrecore.lib is compiled with relative path.
*/
		case 's':	//"src\core\dlmalloc.c"
			if (strncmp(__file__, "src", 3) == 0 )
			{
				p = (char *)__file__ + 9;	//sizeof("src\\core\\");
				break;
			}
		case 'c':	//"core\dlmalloc.c"
			if (strncmp(__file__, "core", 4) == 0 )
			{
				p = (char *)__file__ + 5;	//sizeof("core\\");
				break;
			}
		case 'v':	//"vendor\vre30\src\arch\mtk\vmsim.c"
			if (strncmp(__file__, "vendor", 6) == 0 )
			{
				//__file__[17] -> sizeof("vendor\vre30\src\")
				if (__file__[17] == 'a') //"vendor\vre30\src\arch\mtk\vmsim.c"
				{
					p = (char *)__file__ + 26;	//sizeof("vendor\\vre30\\src\\arch\\mtk\\");
					break;
				}
				if (__file__[17] == 'c') //"vendor\vre30\src\core\dlmalloc.c"
				{
					p = (char *)__file__ + 22;	//sizeof("vendor\\vre30\\src\\core\\");
					break;
				}
			}
		default:	//unexpected source file path.
			//X:\xxx\xxx\src\core\dlmalloc.c, or dlmalloc.c
			p = strstr(__file__, ".c");
			//while (*--p != '\\'); p++;
			while (p != __file__)
			{
				if (*p == '\\' || *p == '/')	//"xxx\xxx, xxx/xxx"
				{
					p ++;
					break;
				}
				p --;
			}
			//break;
			
			//_vm_log_warn("[LOG] unrecognized __FILE__[%p:%s]", __file__, __file__);
			
			//_modFile[0] = 0;	//strcpy(_modFile, __file__);
			//return _cache_ret_ = TRUE;
			//break;
		}

		/*
		 * find "xxxx" in "xxxx.c", and copy "xxxx" to "_modFile"
		 */
		while (*p != '.')	
		{
			if (i < VRE_MAX_C_FILENAME_LEN)
			{
				_modFile[i++] = *p++;
			}
			else 
			{
				_modFile[0] = 0;
				i = 0;
				kal_wap_trace(MOD_MMI, TRACE_GROUP_7, "vre log file path out of _modFile length");
				break;
			}
		}
		_modFile[i] = 0; 	//i = strlen(_modFile)

		//strncpy(_modFile, ++p, i);	//copy operation is finished above
		
		/* 
		 * Till here, the running file's name "_modFile" is obtained 
		 * It 's also used in log_it function to show out in log text.
		 *********************************************************/

		/*
		 * check if current module is configured to be logged.
		 */
		if (_logAllModule)
		{
			_cache_ret_ = TRUE;
			p = logModule;
			while ( (p = strchr(p, '-')) != NULL )
			{
				if ( strncmp(++p, _modFile, i) == 0 )
				{
					_cache_ret_ = FALSE;
					break;
				}
			}
		}
		else 
		{
			_cache_ret_ = FALSE;
			p = strstr(logModule, _modFile);
			if (p)
				_cache_ret_ = TRUE;
		}
		 
		//if (_logAllModule && 	/*log all modules*/
			/* if "-xxx" in the configuratioin string  the xxx module will not be log out, updated by daniel.lin 2010-7-10 */
		//	( (p=(char*)strstr(logModule, _modFile))!=NULL && p>logModule && *(p-1)!='-' ) )  /*log current module*/	// find "_modFile" in logModule configuration string "xxx,xxx,xxx".
		//{
			//_vm_log_debug("[LOG] do log MODULE[%s] in __FILE__[%p:%s]", _modFile, __file__, __file__);
		//	_cache_ret_ = TRUE;
		//} 
		//else 
		//{
			//_vm_log_debug("[LOG] do not log MODULE[%s] in __FILE__[%p:%s]", _modFile, __file__,__file__);
		//	_cache_ret_ = FALSE;
		//}
	}
	return _cache_ret_;
}

#endif
#endif
