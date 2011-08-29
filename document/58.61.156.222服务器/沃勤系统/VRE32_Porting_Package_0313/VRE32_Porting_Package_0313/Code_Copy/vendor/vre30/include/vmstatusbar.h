#ifndef VMSTATUSBAR_H_
#define VMSTATUSBAR_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"
#include "vmpromng.h"

#if defined(__VRE_RB_09A__) || defined(__VRE_RB_08B__) || defined(__VRE_RB_08A__)
#define VM_STATUSBARICON_PRE09B   /* ��09A��08B��08A �ϴ��������; ��09B �Ϲر�*/
#endif

typedef enum
{
	VM_ICON_APP_STATE_INVALID = -1,	/*�Ƿ�״̬*/
	VM_ICON_APP_STATE_ONLINE,	/*����״̬*/
	VM_ICON_APP_STATE_INVISIBLE,	/*����״̬*/
	VM_ICON_APP_STATE_OFFLINE,	/*����(�ѻ�)״̬*/
	VM_ICON_APP_STATE_AWAY,		/*�뿪״̬*/
	VM_ICON_APP_STATE_BUSY,		/*æµ״̬*/
	/* �����5��Ӧ�ÿ�������ѡ���״̬*/
	VM_ICON_APP_STATE_RESERVE1,
	VM_ICON_APP_STATE_RESERVE2,
	VM_ICON_APP_STATE_RESERVE3,
	VM_ICON_APP_STATE_RESERVE4,
	VM_ICON_APP_STATE_RESERVE5,
	/* �ڲ�ר��*/
	VM_ICON_APP_STATE_SPECIAL,
	VM_ICON_APP_STATE_NUM	/*�Ϸ�״̬������*/
}VM_ICON_APP_STATE;

typedef struct vm_statusbar_state_image_map_t
{
	VM_ICON_APP_STATE app_state;	/**app state**/
	VMUINT8* p_image_data;			/**image data pointer**/
	struct vm_statusbar_state_image_map_t* next;	/**pointer to next **/
}vm_statusbar_state_image_map_t;

/**
 * ����Ӧ�õ�״̬���Ա����Statusbar�ϵ�ͼ��
 *
 * @param VM_ICON_APP_STATE			Ӧ��״̬enumֵ
 *
 * @return				����TRUE��ʾ�ɹ���FALSEΪʧ�ܡ�
 */
VMINT vm_statusbar_set_app_state(VM_ICON_APP_STATE state);

/**
 * @name ICON�Ľṹ�塣
 */
typedef struct vm_status_bar_image_t
{
	VMINT icon_id;						/**<ICON ��ID�� 					*/
	VM_P_HANDLE pHandle;				/**<ICON�������Ľ���ID�� 	*/
	VMINT image_status;					/**<ICON״̬ ,��VM_FG_ACTION_TYPE*/

	VM_ICON_APP_STATE app_state;						/**Ӧ��״̬**/ //added
	vm_statusbar_state_image_map_t* p_state_image_table;		/**״̬ͼ��ӳ���**/ //added
	
	VMWCHAR fullFilename[MAX_APP_NAME_LEN + 1];				/**<��̨���г�������·����	*/
	struct vm_status_bar_image_t* next;	/**<��һ��Image��ָ�롣 	*/
}vm_status_bar_image_t;


/**
 * ��̨Ӧ���л���ǰ̨��ִ�ж�����
 */
typedef enum 
{
	VM_ICON_SHOW=1 ,			/**��ʾͼ��	*/
	VM_ICON_BLINK			/**��˸ͼ�� 	*/
} VM_FG_ICONSTATUS_TYPE;


#if     defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_VUI_HOMESCREEN__)
extern void vm_register_status_icon_pen_event(void);

extern void vm_reset_status_icon_pen_event(void);
#endif

#ifdef __cplusplus
}
#endif 

#endif 
