#ifndef	_VM_PRO_MNG_INNER
#define _VM_PRO_MNG_INNER

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"
#include "vmio.h"
#include "vmpromng.h"

#define MAX_CTX_STACK_NUM				(20)//(6) //modified by daniel.lin
#define MAX_LIMITED_PROCESS_NUM		(4)

#define SH_TYPE_R9						(1)
#define SH_TYPE_PROCESS_HANDLE		(2)
#define SH_TYPE_FILENAME				(3)
#define SH_TYPE_PCB						(4)

/* Moved from vmpromng.c by daniel.lin, 2010-7-26  */
#define STACK_SIZE 						(3 * 1024)
#define HEAP_SIZE 						(1024 * 2)
#define PARAM_BLOCK_SIZE 				(128)

enum {
SM_FIND_BY_R9 						= SH_TYPE_R9,
SM_FIND_BY_HANDLE 				= SH_TYPE_PROCESS_HANDLE,
SM_FIND_BY_FILENAME 				= SH_TYPE_FILENAME,
SM_FIND_BY_PCB 					= SH_TYPE_PCB,
SM_FIND_BY_HANDLER, 	/* Find SM by smHandler */
SM_FIND_BY_SM_INVOKER,
SM_FIND_BY_PCB_EVENT_FILTER
};

typedef enum {
	SCREEN_EVENT = 0,				/**<MMI SCREEN 导致的状态切换 							*/
	MOD_EVENT,						/**<由MOD 事件导致状态切换导致的状态切换。 	*/
	USER_EVENT						/**<由用户行为导致的进程状态切换。  			*/
}_VM_STATUS_TRANSFER_EVENT;

typedef struct {
	VMINT (*sys_event_filter)(VMINT message, VMINT param);
	VMINT (*pen_event_filter)(VMINT pen_event, VMINT x, VMINT y);
	VMINT (*key_event_filter)(VMINT key_event, VMINT key_code);
} _event_filter_t;

/**
 * size = 300 byte
 */
typedef struct _vm_pcb_t
{
	VM_P_HANDLE  pHandle;			/**<进程的句柄。 									*/
	VMWCHAR fullFileName[MAX_APP_NAME_LEN + 1];	
									/**<进程归属文件路径。 						*/
	VMINT isReDriver;				/**<是否是在T卡上的应用程序。 				*/
	VMINT r9;						/**<R9寄存器	的值。								*/
	VMUINT8* codeBase;				/**<代码段的开始地址。 			  			*/
	VMUINT codeSize;				/**<代码段的长度，单位为字节。			*/
	VMUINT8* dataBase;				/**<数据段的开始地址。 			  			*/
	VMUINT dataSize;					/**<数据段的长度，单位为字节。			*/
	VMUINT8* heapBase;				/**<数据段的开始地址。 			  			*/
	VMUINT heapSize;				/**<数据段的长度，单位为字节。			*/
	struct _vm_pcb_t* father_pcb;		/**<父进程的PCB，如果是系统进程为NULL。	*/
	VMINT is_support_bg_run;		/**<是否支持后台运行，默认2.0的程序都不支持后台运行，3.0之后的程序都应该支持。*/
	_VM_STATUS_TRANSFER_EVENT	event;
									/**<使进程发生状态切换的事件。 			*/
	VMUINT initParams[6];			/**<装载器装载应用时的初始参数。 		*/
	void (*sysEventHandler)(VMINT message, VMINT param);
									/**<进程注册上来系统消息处理函数。	 	*/
	vm_key_handler_t keyHandler;		/**<按键处理的函数。 							*/
	vm_pen_handler_t penHander;		/**<笔触处理的函数。							*/
	VMFILE fileHandle;				/** 进程打开本身VXP文件的句柄 				*/
	VMINT *	vre_fun_list;			/** 打开进程的函数沙箱列表首地址			*/
	VMINT app_id;					/** 应用程序编号。								*/
	VMINT is_support_all_pen_and_key_event;
									/* 是否支持所有笔触的键值 					*/

	_event_filter_t* event_filter;		/** 计费引擎过滤器。							*/
	
	struct _vm_pcb_t* next_pcb;		/**<同一个status union里的下一个pcb。 			*/							
	VMINT starting;
}_vm_pcb_t;

/* SM info SM PCB need to keep */
typedef struct _vm_sm_t {
	VMINT handle;
	VMWCHAR fullFileName[MAX_APP_NAME_LEN + 1];	
	VMINT isReDriver;				/**<是否是在T卡上的应用程序。 				*/
	
	VMUINT8* codeBase;				/**<代码段的开始地址。 			  			*/
	VMUINT codeSize;				/**<代码段的长度，单位为字节。			*/
	VMUINT8* dataBase;				/**<数据段的开始地址。 			  			*/
	VMUINT dataSize;					/**<数据段的长度，单位为字节。			*/
	VMUINT heapSize;				/**<数据段的长度，单位为字节。			*/
	VMUINT rwSize;				
	VMUINT ziSize;				
	
	VMINT *	vre_fun_list;			/** 打开进程的函数沙箱列表首地址			*/
	VMINT app_id;					/** 应用程序编号。								*/
	//VMINT type;
	VMINT (*smHandler)(VMINT message, VMINT param);
	struct _vm_sm_copy_t * children;
	VMINT ref_count;
	struct _vm_sm_app_t * sm_app;
} _vm_sm_t;

/* SM struct for RW/ZI copy */
typedef struct _vm_sm_copy_t {
	VMINT handle;
	VMUINT r9;	
	VMUINT8* memBase;	
	VMUINT memSize;	
	VMUINT8* heapBase;				/**<数据段的开始地址。 			  			*/
	VMINT invokerType;	/* maybe APP, maybe SM */
	VMINT invoker;	/* maybe APP, maybe SM */
	_vm_pcb_t* pcb;
	_vm_sm_t* sm_ptr;
	_event_filter_t* event_filter;	/* for billing engine */
	struct _vm_sm_copy_t * next;
} _vm_sm_copy_t;

typedef struct vm_pro_ctx_t 
{
	VMINT restore_r9;
} vm_pro_ctx_t;

typedef struct vm_pro_ctx_stack_t
{
	VMUINT num;
	vm_pro_ctx_t ctxs[MAX_CTX_STACK_NUM];
} vm_pro_ctx_stack_t;

_vm_pcb_t* _vm_get_pcb_by_phandle(VM_P_HANDLE phandle);

/* 与VRE3.0计非费相关。 */
VMINT vm_pmng_set_event_filter(_event_filter_t* be_filter);
VMINT vm_pmng_restore_default_event_filter(void);
VMINT vm_pmng_send_app_sys_event(VM_PROCESS_STATUS pmng_status);

#ifdef __cplusplus
}
#endif 
#endif