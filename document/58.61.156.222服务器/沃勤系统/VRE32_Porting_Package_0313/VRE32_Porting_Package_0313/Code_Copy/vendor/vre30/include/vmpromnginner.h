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
	SCREEN_EVENT = 0,				/**<MMI SCREEN ���µ�״̬�л� 							*/
	MOD_EVENT,						/**<��MOD �¼�����״̬�л����µ�״̬�л��� 	*/
	USER_EVENT						/**<���û���Ϊ���µĽ���״̬�л���  			*/
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
	VM_P_HANDLE  pHandle;			/**<���̵ľ���� 									*/
	VMWCHAR fullFileName[MAX_APP_NAME_LEN + 1];	
									/**<���̹����ļ�·���� 						*/
	VMINT isReDriver;				/**<�Ƿ�����T���ϵ�Ӧ�ó��� 				*/
	VMINT r9;						/**<R9�Ĵ���	��ֵ��								*/
	VMUINT8* codeBase;				/**<����εĿ�ʼ��ַ�� 			  			*/
	VMUINT codeSize;				/**<����εĳ��ȣ���λΪ�ֽڡ�			*/
	VMUINT8* dataBase;				/**<���ݶεĿ�ʼ��ַ�� 			  			*/
	VMUINT dataSize;					/**<���ݶεĳ��ȣ���λΪ�ֽڡ�			*/
	VMUINT8* heapBase;				/**<���ݶεĿ�ʼ��ַ�� 			  			*/
	VMUINT heapSize;				/**<���ݶεĳ��ȣ���λΪ�ֽڡ�			*/
	struct _vm_pcb_t* father_pcb;		/**<�����̵�PCB�������ϵͳ����ΪNULL��	*/
	VMINT is_support_bg_run;		/**<�Ƿ�֧�ֺ�̨���У�Ĭ��2.0�ĳ��򶼲�֧�ֺ�̨���У�3.0֮��ĳ���Ӧ��֧�֡�*/
	_VM_STATUS_TRANSFER_EVENT	event;
									/**<ʹ���̷���״̬�л����¼��� 			*/
	VMUINT initParams[6];			/**<װ����װ��Ӧ��ʱ�ĳ�ʼ������ 		*/
	void (*sysEventHandler)(VMINT message, VMINT param);
									/**<����ע������ϵͳ��Ϣ��������	 	*/
	vm_key_handler_t keyHandler;		/**<��������ĺ����� 							*/
	vm_pen_handler_t penHander;		/**<�ʴ�����ĺ�����							*/
	VMFILE fileHandle;				/** ���̴򿪱���VXP�ļ��ľ�� 				*/
	VMINT *	vre_fun_list;			/** �򿪽��̵ĺ���ɳ���б��׵�ַ			*/
	VMINT app_id;					/** Ӧ�ó����š�								*/
	VMINT is_support_all_pen_and_key_event;
									/* �Ƿ�֧�����бʴ��ļ�ֵ 					*/

	_event_filter_t* event_filter;		/** �Ʒ������������							*/
	
	struct _vm_pcb_t* next_pcb;		/**<ͬһ��status union�����һ��pcb�� 			*/							
	VMINT starting;
}_vm_pcb_t;

/* SM info SM PCB need to keep */
typedef struct _vm_sm_t {
	VMINT handle;
	VMWCHAR fullFileName[MAX_APP_NAME_LEN + 1];	
	VMINT isReDriver;				/**<�Ƿ�����T���ϵ�Ӧ�ó��� 				*/
	
	VMUINT8* codeBase;				/**<����εĿ�ʼ��ַ�� 			  			*/
	VMUINT codeSize;				/**<����εĳ��ȣ���λΪ�ֽڡ�			*/
	VMUINT8* dataBase;				/**<���ݶεĿ�ʼ��ַ�� 			  			*/
	VMUINT dataSize;					/**<���ݶεĳ��ȣ���λΪ�ֽڡ�			*/
	VMUINT heapSize;				/**<���ݶεĳ��ȣ���λΪ�ֽڡ�			*/
	VMUINT rwSize;				
	VMUINT ziSize;				
	
	VMINT *	vre_fun_list;			/** �򿪽��̵ĺ���ɳ���б��׵�ַ			*/
	VMINT app_id;					/** Ӧ�ó����š�								*/
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
	VMUINT8* heapBase;				/**<���ݶεĿ�ʼ��ַ�� 			  			*/
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

/* ��VRE3.0�ƷǷ���ء� */
VMINT vm_pmng_set_event_filter(_event_filter_t* be_filter);
VMINT vm_pmng_restore_default_event_filter(void);
VMINT vm_pmng_send_app_sys_event(VM_PROCESS_STATUS pmng_status);

#ifdef __cplusplus
}
#endif 
#endif