#ifndef LOG_H_
#define LOG_H_

#ifdef __cplusplus
extern "C" {
#endif

#define VM_DEBUG_LEVEL		5
#define VM_INFO_LEVEL		4
#define VM_WARN_LEVEL		3
#define VM_ERROR_LEVEL		2
#define VM_FATAL_LEVEL		1

/*
 * VRE log switcher, comment it to build no log version.
 * TODO: this definition should be moved to vmopt.h
 */
#ifdef __VRE_V30_LOG_ON__
#define  VRE_ENABLE_LOG
#endif

#ifdef VRE_ENABLE_LOG

#define VRE_MAX_C_FILENAME_LEN	(20)		/*max length of .c files in VRE*/
//TODO: this macro should be determined when VRE is compling.
#define VRE_MAX_C_FILE_COUNT		(80)		/*max number of .c files in VRE*/

/*add modules need to log out in in default case*/
#define VRE_DEFAULT_LOG_MODULE	"*"	//"vmsys,vmmod,..."

/**
 * 初始化日志文件，必须在启动日志系统之前调用。
 *
 * @param filename		日志文件名，如果为NULL则默认为"c:\vre.log"。
 * @param log_level		记录日志的级别。
 */
void vm_log_init(char* filename, int log_level);

/**
* 设置日志级别。
*/
//void vm_set_log_level(int log_level);

/**
 * 关闭日志文件。
 */
void vm_log_close(void);

/**
 * 输出调试信息。
 *
 * @param fmt		格式化字符串，使用C的printf格式。
 * @param ...		可变参数。
 */
//void vm_log_debug(char* fmt, ...);
void _vm_log_debug(char* fmt, ...);

/**
 * 输出提示信息。
 */
//void vm_log_info(char* fmt, ...);
void _vm_log_info(char* fmt, ...);

/**
 * 输出警告信息。
 */
//void vm_log_warn(char* fmt, ...);
void _vm_log_warn(char* fmt, ...);

/**
 * 输出错误信息。
 */
//void vm_log_error(char* fmt, ...);
void _vm_log_error(char* fmt, ...);

/**
 * 输出致命错误信息。
 */
//void vm_log_fatal(char* fmt, ...);
void _vm_log_fatal(char* fmt, ...);

int _vm_log_module(const char* __file__, const int __line__);

void _vm_log_long(char *fmt, int len);


#ifdef WIN32
#define vm_log_fatal			_vm_log_fatal
#define vm_log_error			_vm_log_error
#define vm_log_warn			_vm_log_warn
#define vm_log_info			_vm_log_info
#define vm_log_debug		_vm_log_debug
#else
#define vm_log_fatal(...)		if(_vm_log_module(__FILE__, __LINE__)) _vm_log_fatal(__VA_ARGS__) 
#define vm_log_error(...)		if(_vm_log_module(__FILE__, __LINE__)) _vm_log_error(__VA_ARGS__)
#define vm_log_warn(...)		if(_vm_log_module(__FILE__, __LINE__)) _vm_log_warn(__VA_ARGS__)
#define vm_log_info(...)		if(_vm_log_module(__FILE__, __LINE__)) _vm_log_info( __VA_ARGS__)
#define vm_log_debug(...)		if(_vm_log_module(__FILE__, __LINE__)) _vm_log_debug(__VA_ARGS__)

#endif

#define vm_log_long		_vm_log_long

#else

#ifdef WIN32
#define vm_log_fatal      
#define vm_log_error 
#define vm_log_warn   
#define vm_log_info      
#define vm_log_debug 

#define vm_log_init  
#define vm_set_log_level  
#define vm_log_close()     
#define vm_log_long 
#else
#define vm_log_fatal(...)      
#define vm_log_error(...)    
#define vm_log_warn(...)     
#define vm_log_info(...)       
#define vm_log_debug(...)  

#define vm_log_init(...)   
#define vm_set_log_level(...)  
#define vm_log_close(...) 

#define vm_log_long(...) 
#endif

#endif  

#ifdef __cplusplus
}
#endif

#endif
