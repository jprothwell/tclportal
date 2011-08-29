#ifndef VRE_OPTIONS_H_
#define VRE_OPTIONS_H_

#ifdef __cplusplus 
extern "C" {
#endif
#include "vmsys.h"
#include "vmmem.h"

/* --------------------------- VRE ---------------------------------- */

/**
 * ����MTK�ĺ궨��VRE˫���ꡣ
 */ 
#ifdef __MMI_DUAL_SIM_MASTER__
#ifndef VRE_DUAL_SIM
	#define VRE_DUAL_SIM
#endif
#endif

/**
 *	������Ϸ����
 */
#define VRE_BUILDIN_APP_COUNT 					(2)

/*
 * ���������VRE ��ASM�ڴ棬����ʹ��Media�ڴ档
 */
#ifndef  __VRE_MEDIA_BUF__
	#define VRE_SUPPORT_ASM_MEMPOOL
#endif

/*
 * ���֧����֤��ɳ����ú�Ӧ�ñ��򿪣�����رա�
 */
#define VRE_SUPPORT_SECURITY_FEATURE

/*
 * ����ǲ��Ժ�̨��ú�Ӧ�ñ��򿪣�����رա�
 */
//#define __VRE_TEST_SERVER__

/*
 * ���֧��ͨ��IMEI�Ž���SDK������֤���򿪣�������IMSI����֤��
 */
//#define VRE_SUPPORT_CERT_SDK_BY_IMEI

/* 
 * ���µ�10, 11, 12, 13��Ҫ����Ĭ�ϵ�ID���塣 
 */
/*
 * Ĭ�ϵ��ƶ�CMWAP�����ʺ�ID��
 */
//#define CMWAP	(vm_get_account_id(10))

/*
 * Ĭ�ϵ��ƶ�CMNET�����ʺ�ID��
 */
//#define CMNET	(vm_get_account_id(11))

/**
 * Ĭ�ϵ���ͨUNIWAP�����ʺ�ID��
 */
//#define UNIWAP	(vm_get_account_id(12))

/**
 * Ĭ�ϵ���ͨUNINET�����ʺ�ID��
 */
//#define UNINET	(vm_get_account_id(13))

/*
 * ���������VRE �þ�̬�ڴ棬����ʹ�ö�̬�ڴ档
 */
//#define VRE_SUPPORT_BUILTIN_MEMPOOL

/*
 * ���������֧��VRE ���һ����˳�����������֧�֡�
 */
//#define VRE_SUPPORT_END_KEY_EXIT			

/*
 * ���������֧�ִ����������߲�֧�֡�
 */
#ifdef __MMI_TOUCH_SCREEN__
#ifndef VRE_SUPPORT_SCREEN_TOUCH
#define VRE_SUPPORT_SCREEN_TOUCH
#endif
#endif

/*
 * ���������֧��ȫ���̣�����֧�֡�
 */
#if defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
#ifndef VRE_SUPPORT_TOTAL_KEYPAD
#define VRE_SUPPORT_TOTAL_KEYPAD
#endif
#endif

/*
 * �Ƿ�֧������ͷ����, ע�͵����ʾ��֧��.
 */
#if defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__)
#ifndef VRE_SUPPORT_CAMERA_FEATURE
#define VRE_SUPPORT_CAMERA_FEATURE
#endif
#endif

/*
 * ���������ÿ������VRE ��ʱ�򶼶�ȡһ��sim������Ϣ������
 * ֻ���ڵ�һ�ε�����VRE ʱ��Ŷ�ȡ��
 */
#define VRE_SUPPORT_GET_SIM_INFO_PER_RUNING

/*
 * ���������֧����VRE �����ϵͳ��WAP�������������֧�֡�
 */
#ifdef WAP_SUPPORT
#define VRE_SUPPORT_OPEN_WAP_BROWSER
#endif

/*
 * �Ƿ�֧�ּ����ⲿ������,�򿪱����ʾ֧��,����֧��.
 */
#define VRE_SUPPORT_INTEGRATE_EXTERNAL_SENSOR

/*
 * VRE�Ƿ�֧��ѡ���Ĺ��ܡ��򿪸ú��ʾ֧�֣�����Ϊ��֧�֡�
 */
//#define VRE_SUPPORT_SELECT_SIM_CARD

/*
 * VREϵͳ�ڴ�ֵ�ĳߴ磬��λ���ֽ�,Ĭ����600K��
 * ����ƽ̨�ֱ�����6225:819200; 6235:1572864; 6238:2097152
 */
#define VRE_SYS_MEMPOOL_SIZE (VRE_SYS_MEMORY_SIZE << 10)

/*
 * ���û�ж���AM�����AMʹ�õ��ڴ涨���0��
 */
#if (!defined(MMI_AM_USING_VRE_MEM) || !defined(__VRE30_AM__))
#define VRE_AM_MAX_DYN_MEM_SIZE 			(0)
#else
#define VRE_AM_MAX_DYN_MEM_SIZE  			MMI_AM_MAX_DYN_MEM_SIZE
#endif

/*
 * ʹ��Media Buffer��ASM�õ��궨�塣
 */
#ifdef __VRE_MEDIA_BUF__
  #if (!defined(MMI_AM_USING_VRE_MEM) || !defined(__VRE30_AM__))
    #define VRE_SYS_ASM_MEMPOOL_SIZE			(0)
  #else
    #define VRE_SYS_ASM_MEMPOOL_SIZE			(0 + MMI_AM_MAX_DYN_MEM_SIZE)
  #endif
  #define VRE_SYS_MED_MEMPOOL_SIZE			(VRE_SYS_MEMPOOL_SIZE + VRE_30_KERNEL_MEM_SIZE)
#else
  #if (!defined(MMI_AM_USING_VRE_MEM) || !defined(__VRE30_AM__))
    #define VRE_SYS_ASM_MEMPOOL_SIZE			(VRE_SYS_MEMPOOL_SIZE + VRE_30_KERNEL_MEM_SIZE)
  #else
    #define VRE_SYS_ASM_MEMPOOL_SIZE			(VRE_SYS_MEMPOOL_SIZE + VRE_30_KERNEL_MEM_SIZE + MMI_AM_MAX_DYN_MEM_SIZE)
  #endif
  #define VRE_SYS_MED_MEMPOOL_SIZE			(0)
#endif

/*
  * VREϵͳ�汾�š�
  */
#define VRE_SYS_VRESION_NUMBER							"3.2.0"

/*
 * VRE ֧�ֵ����Ĵ��ļ��ľ����
 */
#define VRE_SUPPORT_FILE_HANDLE_MAX_NUM					(12)

/*
 * VRE ֧�ֵ�����TCP �����ġ�
 */
#define VRE_SUPPORT_TCP_CONTEXT_MAX_NUM					(3)

/*
 * ϵͳ���ض������ԣ��򿪺�������ڰ������ڵ��ļ���������ϵͳ��д���
 * �ļ����ᱻ�ض��򵽴洢���ϡ�
 */
/* #define VRE_SYS_DRIVER_REMAPPING */

/*
 * �����ڴ�������ܣ����ں˺��û��ڴ������������򿪡�
 */
#define VRE_MEMORY_PARTITION

/*
 * �ַ���Ȳ��������ص�λ����ϵͳ���ص��ַ��߶Ȳ�����ʵ�ʲ���ʱ��ͨ��
 * ����������㡣 
 */
#define VRE_CHAR_H_PADDING								(0)

/*
 * �ַ��߶Ȳ��������ص�λ����ϵͳ���ص��ַ��߶Ȳ�����ʵ�ʲ���ʱ��ͨ��
 * ����������㡣
 */
#define VRE_CHAR_V_PADDING								(0)

/*
  * ��ϵͳ��Ϣ�������Ļ
  */
//#define VM_OUTPUT_MEM_STATE	

/**
 * VRE �Ƿ�֧��SCREEN GROUP�Ļ���.
 */
#if !defined(__VRE_RB_09A__)
#define VRE_SUPPORT_SCREEN_GROUP_FRAMEWOK
#endif

/*
 * �Ƿ�֧����VREӦ�ó�������ʱ���¶���ֻ����ʾ����û�е������ڣ���������Ƶ����Ƶ��¼��ʱ��û����ʾ��û�е�������
 */
//#define     VM_SUPPORT_SMS_NO_POPUP

/**
 * ƽ̨���ļ�������������VREApp�Ļص�������
 * @param 			path VREApp���ļ�������ȫ·����
 * @param 			is_short	
 */
void vm_open_vre_exec_file_callback(const VMWSTR path, VMINT is_short);

/**
 * ֪ͨVRE ����USBģʽ��
 */
void mmi_vre_enter_usb_mode(void);

/**
 * ֪ͨVRE �˳���USBģʽ��
 */
void mmi_vre_exit_usb_mode(void);

/**
 * �γ�T���Ĵ���
 */
void mmi_vre_card_plug_out_hdlr(void);

/**
 * �Ƿ������ʽ��ָ���Ĵ��̡�
 */
VMINT  mmi_vre_pre_format_hdlr(VMINT8 drv);

#ifdef __cplusplus
}
#endif

#endif
