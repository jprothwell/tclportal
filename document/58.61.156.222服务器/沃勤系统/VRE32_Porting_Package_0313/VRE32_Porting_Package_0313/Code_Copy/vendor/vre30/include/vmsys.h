#ifndef VMSYS_H_
#define VMSYS_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef NULL
#define NULL 0
#endif

//��������VRE ����
#define VM_NORMAL_START_VRE_ENV 1

enum {
	ASM_VMAN_ON,//ȫ����ASM���䣬VM_MEMORY_ACCORDING_NEED����(�����ã���ֹ�󿪴˺�)
	ASM_VMAN_OFF,//ȫ����ASM���䣬VM_MEMORY_ACCORDING_NEED�ر�(�������)
	MEDIABUF_VMAN_ON,//ʹ��media buffer, VM_MEMORY_ACCORDING_NEED����(�������)
	MEDIABUF_VMAN_OFF//ʹ��media buffer, VM_MEMORY_ACCORDING_NEED�ر�(�������)
};
//�ڴ水�����
//#define VM_MEMORY_ACCORDING_NEED

typedef unsigned char VMUINT8;
typedef unsigned short VMUINT16;
typedef unsigned int VMUINT;
typedef unsigned long VMUINT32;

#ifndef WIN32
typedef  unsigned long long VMUINT64 ;
#else
typedef  unsigned long VMUINT64;
#endif

typedef char VMINT8;
typedef short VMINT16;
typedef int  VMINT;
typedef long  VMINT32;

typedef VMUINT8 VMUCHAR;
typedef VMUINT16 VMUWCHAR;
typedef VMUINT8 * VMUSTR;
typedef VMUINT16 * VMUWSTR;

typedef VMINT8 VMCHAR;
typedef VMINT16 VMWCHAR;
typedef VMINT8 * VMSTR;
typedef VMINT16 * VMWSTR;

typedef unsigned char VMBYTE;
typedef unsigned short VMUSHORT;
typedef short VMSHORT;

typedef VMINT VMFILE;

#include "vmtimer.h"

typedef struct vm_time_t {
	VMINT year;		/* ��ݡ�			*/
	VMINT mon;		/* �·ݣ���1��ʼ��	*/
	VMINT day;		/* �죬��1��ʼ��	*/
	VMINT hour;		/* Сʱ��24Сʱ�ơ�	*/
	VMINT min;		/* ���ӡ�			*/
	VMINT sec;		/* �롣				*/
} vm_time_t;

/**
 * ��õ�ǰϵͳʱ�䡣
 *
 * @param time			ָ������vm_time_tָ�롣
 *
 * @return				����0��ʾ�ɹ�������Ϊʧ�ܡ�
 */
VMINT vm_get_time(vm_time_t* time);

/**
 * �ڴ�����ͳ�ƽ����
 */
typedef struct malloc_stat_t {
	/**
	 * �ڴ���亯�����ܵ��ô���������vm_malloc()��vm_realloc()��
	 * vm_calloc()��
	 */
	VMINT malloc_count;

	/**
	 * �ڴ��ͷź������ܵ��ô�����
	 */
	VMINT free_count;

	/**
	 * ��ǰ�ڴ�ռ������
	 */
	VMINT current;

	/**
	 * ����ڴ�ռ������
	 */
	VMINT peak;

	/**
	 * �ڴ����ʧ�ܴ�����
	 */
	VMINT fail_times;

	/**
	 * ����ڴ����ʧ�ܵĿ顣
	 */
	VMINT max_fail_size;

	/**
	 * ��ǰʣ��ѵ�������
	 */
	VMINT avail_heap_size;
} malloc_stat_t;


/**
 * ��õ�ǰ�ڴ������ϵͳ��ͳ�����ݡ��������ڴ���������ú󣬷���
 * ����������ڴ�ͳ�����ݡ�
 */
malloc_stat_t* vm_get_malloc_stat(void);

/**
 * �����ڴ档
 *
 * @param size			Ҫ������ֽ�����
 *
 * @return				�·��䵽���ڴ�ָ�룬����NULL��ʾ����ʧ�ܡ�
 */
void *vm_malloc(int size);

/**
 * �����ڴ棬���ҽ��·��䵽���ڴ���0��
 *
 * @param size			Ҫ������ֽ�����
 *
 * @return				���ط��䵽���ڴ�ָ�룬����NULL��ʾ����ʧ�ܡ�
 */
void *vm_calloc(int size);

/**
 * ���·����ڴ棬����������ڴ泤��С��ԭ���ڴ泤�ȣ�ϵͳ�����κ�
 * ����������Ѹ������ڴ����󵽸������ȣ��ڴ��е����ݼ���������
 *
 * @param p				Ҫ���·�����ڴ�ָ�롣
 * @param size			�µĳ��ȡ�
 *
 * @return				����NULL��ʾ���·���ʧ�ܣ��������ڴ�ָ��
 *						ָ����ڴ治�ͷţ����򷵻���չ����ڴ�
 *						ָ�롣
 */
void *vm_realloc(void* p, int size);

/**
 * �ͷ��ڴ档
 *
 * @param ptr			���ͷŵ��ڴ�ָ�룬������vm_malloc()�����䡣
 */
void vm_free(void* ptr);


 /**
 * ���ǻ���VRE�ĳ�����ں�����Ӧ�ó������ʵ�֡�
 */
void vm_main(void);

/**
 * Ҫ�����»���VRE�û����档
 */
#define VM_MSG_PAINT			1

/**
 * VRE�ӷǼ���״̬�л�Ϊ����״̬��
 */
#define VM_MSG_ACTIVE			2

/**
 * VRE�Ӽ���״̬�л����Ǽ���״̬��
 */
#define VM_MSG_INACTIVE		3

/**
 * VRE��������
 */
#define VM_MSG_CREATE			4

/**
 * VRE���˳���
 */
#define VM_MSG_QUIT			5

/**
 * VRE �����л�����̨���е���Ϣ��
 */
#define VM_MSG_HIDE			6

/**
 * VRE ������Է�ת��Ļ����Ϣ�� ���ᷢ���� ����VRE������Ļ��ת�ĽǶ�
 */
#define VM_MSG_SCREEN_ROTATE		7

/**
 * ϵͳHIDE��PAINT�¼�����ԭ������Ͷ��塣
 */
enum {
	SCREEN_POPUP = 0, 	/* HIDE��PAINT�¼�����ĻPOPUP��Ϊ����绰�����š����뷨����ȵ��� */
	USER_END_KEY		/* HIDE�¼����û����һ������� */
};

/**
 * ϵͳ�¼��������ݽṹ��
 */
typedef struct _vm_sysevt_param_t
{
	VMINT evt_cause; 	/* �¼�����ԭ�� */
	void * evt_detail; 	/* reserved */
} vm_sysevt_param_t;

/**
 * ע��ϵͳ�¼��ص�������
 */
void vm_reg_sysevt_callback(void (*f)(VMINT message, VMINT param));

/**
 * �˳�VREӦ�ó����������ֻ���ɶ�̬װ���VREӦ�ó��������ã�BUILTIN�ĳ���Ӧ����
 * ������������������ú󣬵�ǰ��ִ�е�VREӦ�ó�����ռ�õ��ڴ�ᱻ�����ͷţ���󷵻�
 * VREӦ�ó����������Ӧ�ó����Լ�������ڴ����Դ������Ӧ�ó��������ͷš�
 */
void vm_exit_app(void);

/**
 * �˳�Ӧ�ó�����Ӧ�ó�������������������
 * �������ֻ���ɶ�̬װ���VRE Ӧ�ó�����á��ڵ��ñ���
 * ��ǰӦ�ó�������ͷ�ռ�õ��ڴ�����Դ���ڵ����걾����
 * ��Ӧ�ó���Ӧ����ִ���κδ��롣
 */ 
void vm_exit_and_update_app(void);

/**
 * ���ϵͳ���������������ĺ����������������ڲ�ͬƽ̨�Ͽ��ܻ�������ͬ��
 *
 * @return			ϵͳ���������ھ����ĺ�������
 */
VMINT vm_get_tick_count(void);

/**
 * ��õ�ǰִ�г�����ļ�����
 *
 * @param filename			����ִ�г������Ƶ�UCS2�ַ������顣
 *
 * @return					����0��ʾ�����ɹ������������filename�У�
 *							���򷵻ش����룬��ʾ��ǰ�����ں�̬��û��Ӧ��
 *							���������С�
 */
VMINT vm_get_exec_filename(VMWSTR filename);

/**
 * VRE_SYS_SUBSCRIBER_ID 
 * VRE�û�ID�ţ�ֵ��һ���������Ϊ20��VMCHAR���ַ��������磺100973
 * 
 * VRE_SYS_EQUIPMENT_ID 
 * VREϵͳ��USER AGENT��ֵ��һ���������Ϊ20��VMCHAR���ַ��������磺Gionee-A10
 * 
 * VRE_SYS_VERSION 
 * VRE�汾�ţ�ֵ��һ���������Ϊ12��VMCHAR���ַ�����VRE
 * �汾�ŵ���������Ϊ<���汾��>.<�Ӱ汾��>.<������>
 * ���磺1.2.6
 * 
 * VRE_SYS_HOST_VERSION
 * ����ƽ̨�汾�ţ�ֵ��һ���������Ϊ30��VMCHAR���ַ���������MT6225_08A_VERSION��
 *
 * VRE_SYS_HOST_MAX_MEM
 * ����ƽ̨�����VRE������ڴ棬ֵ��һ���������Ϊ6��VMCHAR���ַ�������
 * ��Ϊȫ���֣�������atoi����ת����ֵ���ͣ���λΪKB�����ڴ���VREϵͳ�ڴ�
 * ���û��ڴ���ܺ͡�
 * ���磺800
 * 
 * VRE_SYS_HOME_DIR
 * �õ�VREϵͳ��HOME·������·����һ���������30��VMCHAR���ַ�����
 * HOME·�������ļ��ָ�����β��
 * ���磺C:\VRE
 */
#define VRE_SYS_SUBSCRIBER_ID		(1)
#define VRE_SYS_EQUIPMENT_ID		(2)
#define VRE_SYS_VERSION			(3)
#define VRE_SYS_HOST_VERSION		(4)
#define VRE_SYS_HOST_MAX_MEM		(5)
#define VRE_SYS_HOME_DIR			(6)

/**
 * �õ�VRE��ϵͳ���ԣ����ԵĶ���Ϊ�ؼ���(key)��ֵ(value)��һ�����ݡ�VRE��ϵͳ����
 * ��VRE�ڲ�ά���ģ������޷�������Ļ�ɾ�������õĳ���ʾ�����£�
 * VMCHAR value[20] = {0};
 * VMUINT valueNum = vm_get_sys_property(VRE_SYS_SUBSCRIBER_ID, value, 20);
 *
 * @param key				��Ҫȡ��VREϵͳ���ԵĹؼ��֡�			
 * @param value				ָ��һ�������ڴ棬�ڱ�������ʵ�����ѵõ���
 *							ֵд����ָ��ָ����ڴ������ڡ������ָ��ָ��
 *							NULL(0��ַ)����ô�ں����ڲ�����д���ַ��Ĳ�����
 * @param len				valueָ��ָ�������ڴ�����ܹ����VMCHAR����Ԫ�صĸ�����
 *							�����ʵ����12������ʵ�ʵ�ֵֻ��10��VMCHAR���ͣ���ô
 *							�����ڻ�������11��λ��д��0x00;���ֵ�պ���12������ô
 *							������д��0x00;���ֵ�ĳ��ȴ���12����ôֻ��д��ǰ12���ַ�
 *							��valueָ����ڴ������ڡ�
 * 
 * @return					ʵ��д���ֵ�ĳ��ȣ���������д���0x00��
*/
VMUINT vm_get_sys_property(const VMINT key, VMCHAR* value, VMUINT len);

/**
 * ��ȡ��ǰ����ʱ����ʱ�
 *
 * @return	����GMTʱ��ֵ��
 */
float vm_get_sys_time_zone(void);

/**
 * ��ȡ�ֻ��龰ģʽ��
 *
 * @return	����0��ʾ��׼ģʽ������1��ʾ����ģʽ������2��ʾ����ģʽ��
 *			����3��ʾ����ģʽ������4��ʾ����ģʽ������5��ʾ����ģʽ��
 *			����6��ʾ����ģʽ��
 */
VMINT vm_get_sys_scene(void);

/**
 * ��ȡ�ֻ���ص�����
 *
 * @return	������ĸ��ȼ����򷵻�ֵΪ0��25��50��75��100����һ����
 *			����������ȼ����򷵻�ֵΪ0��33��66��100����һ����
 */
VMINT vm_get_battery_level(void) ;

/**
 * @name vm_switch_power_saving_mode�����Ĳ�����
 */
typedef enum {
	turn_on_mode = 0, 				/**<�򿪽ڵ�ģʽ */
	turn_off_mode					/**<�رսڵ�ģʽ */
} power_saving_mode_enum;

/**
 * ���ýڵ�ģʽ�����Ӧ�ùر��˽ڵ�ģʽ����Ļ��������Ӧ��ֻ����ǰ̨����ʱ
 * ���ñ�������VRE��ʼ��״̬ʼ��Ϊ���˽ڵ�ģʽ��Ӧ�ñ��л�����̨���˳�ǰ
 * ��Ӧ�ô򿪽ڵ�ģʽ��
 * 
 * @param[in]			mode turn_on_mode��ʾ�򿪽ڵ�ģʽ��turn_off_mode��ʾ�رսڵ�ģʽ��
 * @return			0 ��ʾ���óɹ������򷵻ش����롣
 */
VMINT vm_switch_power_saving_mode(power_saving_mode_enum mode);


#ifdef __cplusplus
}
#endif 

#endif 
