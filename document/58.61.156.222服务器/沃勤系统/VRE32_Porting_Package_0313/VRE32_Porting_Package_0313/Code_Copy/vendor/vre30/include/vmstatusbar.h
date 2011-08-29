#ifndef VMSTATUSBAR_H_
#define VMSTATUSBAR_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"
#include "vmpromng.h"

#if defined(__VRE_RB_09A__) || defined(__VRE_RB_08B__) || defined(__VRE_RB_08A__)
#define VM_STATUSBARICON_PRE09B   /* 在09A、08B、08A 上打开了这个宏; 在09B 上关闭*/
#endif

typedef enum
{
	VM_ICON_APP_STATE_INVALID = -1,	/*非法状态*/
	VM_ICON_APP_STATE_ONLINE,	/*在线状态*/
	VM_ICON_APP_STATE_INVISIBLE,	/*隐身状态*/
	VM_ICON_APP_STATE_OFFLINE,	/*掉线(脱机)状态*/
	VM_ICON_APP_STATE_AWAY,		/*离开状态*/
	VM_ICON_APP_STATE_BUSY,		/*忙碌状态*/
	/* 额外的5种应用可以配置选择的状态*/
	VM_ICON_APP_STATE_RESERVE1,
	VM_ICON_APP_STATE_RESERVE2,
	VM_ICON_APP_STATE_RESERVE3,
	VM_ICON_APP_STATE_RESERVE4,
	VM_ICON_APP_STATE_RESERVE5,
	/* 内部专用*/
	VM_ICON_APP_STATE_SPECIAL,
	VM_ICON_APP_STATE_NUM	/*合法状态的数量*/
}VM_ICON_APP_STATE;

typedef struct vm_statusbar_state_image_map_t
{
	VM_ICON_APP_STATE app_state;	/**app state**/
	VMUINT8* p_image_data;			/**image data pointer**/
	struct vm_statusbar_state_image_map_t* next;	/**pointer to next **/
}vm_statusbar_state_image_map_t;

/**
 * 设置应用的状态，以便更新Statusbar上的图标
 *
 * @param VM_ICON_APP_STATE			应用状态enum值
 *
 * @return				返回TRUE表示成功，FALSE为失败。
 */
VMINT vm_statusbar_set_app_state(VM_ICON_APP_STATE state);

/**
 * @name ICON的结构体。
 */
typedef struct vm_status_bar_image_t
{
	VMINT icon_id;						/**<ICON 的ID。 					*/
	VM_P_HANDLE pHandle;				/**<ICON所归属的进程ID。 	*/
	VMINT image_status;					/**<ICON状态 ,见VM_FG_ACTION_TYPE*/

	VM_ICON_APP_STATE app_state;						/**应用状态**/ //added
	vm_statusbar_state_image_map_t* p_state_image_table;		/**状态图标映射表**/ //added
	
	VMWCHAR fullFilename[MAX_APP_NAME_LEN + 1];				/**<后台运行程序完整路径名	*/
	struct vm_status_bar_image_t* next;	/**<下一个Image的指针。 	*/
}vm_status_bar_image_t;


/**
 * 后台应用切换到前台的执行动作。
 */
typedef enum 
{
	VM_ICON_SHOW=1 ,			/**显示图标	*/
	VM_ICON_BLINK			/**闪烁图标 	*/
} VM_FG_ICONSTATUS_TYPE;


#if     defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_VUI_HOMESCREEN__)
extern void vm_register_status_icon_pen_event(void);

extern void vm_reset_status_icon_pen_event(void);
#endif

#ifdef __cplusplus
}
#endif 

#endif 
