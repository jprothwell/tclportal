#ifndef VMIO_H_
#define VMIO_H_

#include "vmsim.h"
#include "vmsys.h"
#include "vmtel.h"
#include "vmdl.h"

#ifdef __cplusplus
extern "C" {
#endif


typedef enum 
{
	VM_FILE_COMMIT_ERROR = -1,
	VM_FILE_OPEN_ERROR = -2,
	VM_FILE_NAME_ERROR = -1,
	VM_FILE_OK = 0
} vm_file_error_t;

/**
 * @name VRE֧�ֵİ����¼���
 * @{
 */
/**
 * �����ɿ��¼���
 */
#define VM_KEY_EVENT_UP			(1)

/**
 * ���̰����¼���
 */
#define VM_KEY_EVENT_DOWN			(2)

/**
 * ���̳����¼���
 */
#define VM_KEY_EVENT_LONG_PRESS	(3)

/**
 * ���̶�ΰ�ͬһ�����Ĳ�����
 */
#define VM_KEY_EVENT_REPEAT		(4)
/** @} */


/**
 * @name VRE֧�ֵİ�����
 * @{
 */
/**
 * �Ϸ������
 */
#define VM_KEY_UP					(-1)

/**
 * �·������
 */
#define VM_KEY_DOWN				(-2)

/**
 * �������
 */
#define VM_KEY_LEFT					(-3)

/**
 * �ҷ������
 */
#define VM_KEY_RIGHT				(-4)

/**
 * ���ܼ���
 */
#define VM_KEY_LEFT_SOFTKEY		(-6)

/**
 * �ҹ��ܼ���
 */
#define VM_KEY_RIGHT_SOFTKEY		(-7)

/**
 * ȷ��(OK)����
 */
#define VM_KEY_OK					(-5)

/**
 * ɾ������
 */
#define VM_KEY_CLEAR				(-8)

/**
 * ���ؼ���
 */
#define VM_KEY_BACK					(-9)

/**
 * ����0����
 */
#define VM_KEY_NUM0				(48)

/**
 * ����1����
 */
#define VM_KEY_NUM1				(49)

/**
 * ����2����
 */
#define VM_KEY_NUM2				(50)

/**
 * ����3����
 */
#define VM_KEY_NUM3				(51)

/**
 * ����4����
 */
#define VM_KEY_NUM4				(52)

/**
 * ����5����
 */
#define VM_KEY_NUM5				(53)

/**
 * ����6����
 */
#define VM_KEY_NUM6				(54)

/**
 * ����7����
 */
#define VM_KEY_NUM7				(55)

/**
 * ����8����
 */
#define VM_KEY_NUM8				(56)

/**
 * ����9����
 */
#define VM_KEY_NUM9				(57)

/**
 * ���ϵ���������
 */
#define VM_KEY_VOL_UP				(58)

/**
 * ���µ���������
 */
#define VM_KEY_VOL_DOWN			(59)

/**
 * ����(#)����
 */
#define VM_KEY_POUND				(35)

/**
 * �Ǻ�(*)����
 */
#define VM_KEY_STAR					(42)
/** @} */

/**********chenkang 20100203add for qwerty keypad begin***********/
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
#define 	VM_KEY_A 65
#define	VM_KEY_B 66
#define	VM_KEY_C 67
#define	VM_KEY_D 68
#define	VM_KEY_E 69
#define	VM_KEY_F 70
#define	VM_KEY_G 71
#define	VM_KEY_H 72
#define	VM_KEY_I 73
#define	VM_KEY_J 74
#define	VM_KEY_K 75
#define	VM_KEY_L 76
#define	VM_KEY_M 77
#define	VM_KEY_N 78
#define	VM_KEY_O 79
#define	VM_KEY_P 80
#define	VM_KEY_Q 81
#define	VM_KEY_R 82
#define	VM_KEY_S 83
#define	VM_KEY_T 84
#define	VM_KEY_U 85
#define	VM_KEY_V 86
#define	VM_KEY_W 87
#define	VM_KEY_X 88
#define	VM_KEY_Y 89
#define	VM_KEY_Z 90
#define	VM_KEY_SPACE 91
#define	VM_KEY_TAB 92
#define	VM_KEY_DEL 93
#define	VM_KEY_ALT 94
#define	VM_KEY_CTRL 95
#define	VM_KEY_WIN 96
#define	VM_KEY_SHIFT 97
#define	VM_KEY_QUESTION 98
#define	VM_KEY_PERIOD 99
#define	VM_KEY_COMMA 100
#define	VM_KEY_EXCLAMATION 101
#define	VM_KEY_APOSTROPHE 102
#define	VM_KEY_AT 103
#define	VM_KEY_BACKSPACE 104
#define	VM_KEY_QWERTY_ENTER 105
#define	VM_KEY_FN 106
#define	VM_KEY_SYMBOL 107
#define	VM_KEY_NUM_LOCK 108
#define	VM_KEY_QWERTY_MENU 109
#endif /* __QWERTY_KEYPAD_SUPPORT__ */
/**********chenkang 20100203add for qwerty keypad end***********/

/*
 * �ļ����ԡ�
 */
#define VM_FS_ATTR_READ_ONLY        	0x01
#define VM_FS_ATTR_HIDDEN           	0x02
#define VM_FS_ATTR_SYSTEM           	0x04
#define VM_FS_ATTR_VOLUME          	0x08
#define VM_FS_ATTR_DIR              		0x10
#define VM_FS_ATTR_ARCHIVE          	0x20
#define VM_FS_LONGNAME_ATTR         	0x0F

struct vm_fileinfo_t {
	VMWCHAR filename[MAX_APP_NAME_LEN];
	VMINT size;
};

typedef  struct  vm_fileinfo_ext
{
   VMWCHAR 	     filefullname[MAX_APP_NAME_LEN];   /*����Ŀ¼���ļ���*/
   VMCHAR          filename[8];                                     /*8.3��ʽ�ļ����ַ����飬ĩβ����Ϊ��'\0'*/
   VMCHAR          extension[3];                                   /*8.3��ʽ�ļ���չ���ַ����飬ĩβ����Ϊ��'\0'*/
   VMBYTE           attributes;
   vm_time_t       create_datetime;
   vm_time_t	    modify_datetime;
   VMUINT           filesize;
   VMUINT           drive;
   VMUINT           stamp;
} vm_fileinfo_ext;

typedef void (*vm_key_handler_t)(VMINT event, VMINT keycode);

/**
 * ע����̻ص����������ڲ�����������¼���
 *
 * @param f				�¼��ص�������event������ʾ�¼����ͣ���VM_KEY_EVENT�������壻
 *						keycode������ʾ��ֵ����VM_KEY�������塣
 */
void vm_reg_keyboard_callback(vm_key_handler_t handler);

/**
 * @name VRE֧�ֵıʴ���Ϣ��
 * @{
 */
/**
 * ���رʰ����¼���
 */
#define VM_PEN_EVENT_TAP				1

/**
 * ���ر��ɿ��¼���
 */
#define VM_PEN_EVENT_RELEASE			2

/**
 * ���ر��ƶ��¼���
 */
#define VM_PEN_EVENT_MOVE				3

/**
 * ���رʳ����¼���
 */
#define VM_PEN_EVENT_LONG_TAP			4

/**
 * ���ر�˫���¼���
 */
#define VM_PEN_EVENT_DOUBLE_CLICK		5

/**
 * ���ر��ظ�����¼���
 */
#define VM_PEN_EVENT_REPEAT			6
/** @} */

typedef void (*vm_pen_handler_t)(VMINT event, VMINT x, VMINT y);

/**
 * ע�������ص����������ڲ������������¼���
 *
 * @param f				�¼��ص�������event��ʾ�¼����ͣ���VM_PEN_EVENT�������壻
 *						x������ʾ��������꣬y������ʾ��������ꡣ
 */
void vm_reg_pen_callback(vm_pen_handler_t handler);

/**
 * ���ļ�ʹ�䴦�ڿɶ�״̬��
 */
#define MODE_READ					1

/**
 * ���ļ�ʹ�䴦�ڿ�д״̬��
 */
#define MODE_WRITE					2

/**
 * ���ļ�ʹ�䴦��д״̬������ļ����������Զ�����֮��
 */
#define MODE_CREATE_ALWAYS_WRITE	4

/**
 * ���ļ�ʹ�䴦��׷��״̬���ļ����Ѵ��ڵ����ݲ��ᱻ�Զ���ա�
 */
#define MODE_APPEND					8

/**
 * ���ļ���
 *
 * @param filename		��UCS2��ʽ������ļ�·����
 * @param mode			�ļ���ģʽ������MODE_READ����д��MODE_WRITE����
 *						�����ļ�����������Ǵ���֮��MODE_CREATE_ALWAYS_WRITE����
 * @param binary		TRUE��ʾ�Զ����Ƹ�ʽ���ļ���FALSE��ʾ��ASCII��ʽ���ļ���
 *
 * @return				�ɹ����򷵻طǸ�����������Ϊ�������ʾʧ�ܡ�
 */
VMFILE vm_file_open(const VMWSTR filename, VMUINT mode, VMUINT binary);

/**
 * �ر��ļ���
 *
 * @param handle		Ҫ�رյ��ļ������
 */
void vm_file_close(VMFILE handle);

/**
 * ���ļ����ݶ����ڴ棬ϵͳ���ļ���ǰ��дָ��λ�ÿ�ʼ����
 *
 * @param handle		���ļ������
 * @param data			Ҫ������ڴ��ַָ�롣
 * @param length		Ҫ������ֽ�����
 * @param nread			����������ֽ�����
 *
 * @return				���ض������ֽ���������0��ʾ�д����������Ѿ������ļ�β����
 */
VMINT vm_file_read(VMFILE handle, void * data, VMUINT length, VMUINT *nread);

/**
 * ���ļ�д�����ݣ�ϵͳ���ļ���ǰ��д��ָ��λ�ÿ�ʼд��
 *
 * @param handle		��д���ļ��ľ����
 * @param data			Ҫд��������ڴ�ָ�롣
 * @param length		Ҫд����ֽ�����
 * @param written		ʵ��д����ֽ�����
 *
 * @return				ʵ��д����ֽ���������0��ʾ��������
 */
VMINT vm_file_write(VMFILE handle, void * data, VMUINT length, VMUINT * written);

/**
 * ��I/O�����е���������ˢ�����ļ��У������������ǿ�ư�д��������ύ���ļ��С�
 *
 * @param handle		Ҫˢ�µ��ļ������
 *
 * @return				����0��ʾ�ɹ�������Ϊʧ�ܡ�
 */
VMINT vm_file_commit(VMFILE handle);

#define BASE_BEGIN		1
#define BASE_CURR		2
#define BASE_END		3

/**
 * �ƶ��ļ���дָ�뵽ָ��λ�á�
 * ���ָ��λ�ó������ļ���Χ�������ز���ʧ�ܡ�
 * 
 *
 * @param handle		�ļ������
 * @param offset		�ƶ�ƫ���������ֽ�Ϊ��λ��
 * @param base			�ƶ���ַ�����ļ�ͷ��ʼ��BASE_BEGIN�����ӵ�ǰλ�ÿ�ʼ��BASE_CURR����
 *						���ļ�β��ʼ��BASE_END����
 *
 * @return				����0��ʾ�ɹ������ظ�����ʾʧ�ܡ�
 */
VMINT vm_file_seek(VMFILE handle, VMINT offset, VMINT base);

/**
 * �ļ���дָ��ĵ�ǰλ�á�
 *
 * @param handle		�ļ������
 *
 * @return			��ǰ�ļ�ָ��λ�ã����ظ�����ʾʧ�ܡ�
 */
VMINT vm_file_tell(VMFILE handle);

/**
 * �ļ���дָ��ĵ�ǰλ���Ƿ��Ѿ����ļ�ĩβ��
 *
 * @param handle		�ļ������
 *
 * @return			TRUE=�ѵ�ĩβ�� FALSE=δ��ĩβ��
 */
VMINT vm_file_is_eof(VMFILE handle);

/**
 * ����ļ���С�����ֽ�Ϊ��λ��
 * 
 * @param handle		�ļ������
 * @param file_size		��Ҫ��д����ļ��Ĵ�С��ָ�룬���ֽ�Ϊ��λ��
 *
 * @return				����0��ʾȡ�ļ���С�ɹ�������Ϊʧ�ܡ�
 */
VMINT vm_file_getfilesize(VMFILE handle, VMUINT *file_size);

/**
 * ɾ���ļ���
 * 
 * @param filename		��UCS2�����ʽ���ļ�·����
 *
 * @return				����0��ʾ�ɹ�������Ϊʧ�ܡ�
 */
VMINT vm_file_delete(const VMWSTR filename);

/**
 * �ļ���������
 * 
 * @param filename		��UCS2��ʽ�����ԭʼ�ļ�·����
 * @param newname		��UCS2��ʽ�����Ŀ���ļ�·����
 *
 * @return				����0��ʾ�ɹ�������Ϊʧ�ܡ�
 */
VMINT vm_file_rename(const VMWSTR filename, const VMWSTR newname);

/**
 * ����Ŀ¼��
 *
 * @param dirname		��UCS2��ʽ�����·������
 *
 * @return				����0��ʾ�ɹ�������Ϊʧ�ܡ�
 */
VMINT vm_file_mkdir(const VMWSTR dirname);

/**
 * ɾ��·����
 *
 * @param dirname		��UCS2��ʽ����ı�ɾ��·������
 *
 * @return				����0��ʾ�ɹ�������Ϊʧ�ܡ�
 */
VMINT vm_file_rmdir(const VMWSTR dirname);

/**
 * �����ļ����ԡ�
 * ���õ�ֵ���ܰ���VM_FS_ATTR_VOLUME��VM_FS_ATTR_DIR��VM_FS_LONGNAME_ATTR
 * �ļ����Ե�ֵΪ����������ֵ������ֵ��ο��ļ����Եĺ궨�塣
 *
 * @param filename   �ļ���(��ȫ·��)��
 * @param attributes  �ļ����ԡ�
 *
 * @return       ����0��ʾ�ɹ�������Ϊʧ�ܡ�
 */
VMINT vm_file_set_attributes(const VMWSTR filename, VMBYTE attributes);

/**
 * ��ȡ�ļ����ԡ�
 * �ļ����Ե�ֵΪ����������ֵ������ֵ��ο��ļ����Եĺ궨�塣
 *
 * @param filename  �ļ���(��ȫ·��)��
 *
 * @return �����ļ����ԣ�����Ϊʧ�ܡ�
 */
VMINT vm_file_get_attributes(const VMWSTR filename);


/**
 * ���Ҹ���Ŀ¼�µ��ļ�������ʹ��*ͨ�����
 *
 * @param pathname			����·����
 * @param info				�ҵ����ļ���Ϣ��
 *
 * @return					���ظ�����ʾʧ�ܣ����򷵻ش��ڻ����0��һ�����Ҿ����
 */
VMINT vm_find_first(VMWSTR pathname, struct vm_fileinfo_t* info);

/**
 * ����һ�β��ҽ���з�����һ���ļ�����
 *
 * @param handle		vm_find_first���صľ����
 * @param info			�ҵ����ļ���Ϣ��
 *
 * @return				����0��ʾ�ҵ���һ���ļ��������ʾ���ҽ�����
 */
VMINT vm_find_next(VMINT handle, struct vm_fileinfo_t* info);

/**
 * �رղ��ҽ�����������ڲ�����Ϻ���á�
 *
 * @param handle		���Ҿ����
 */
void vm_find_close(VMINT handle);

#define vm_get_removable_driver vm_get_removeable_driver
/**
 * ����ֻ��Ͽ��ƶ����������̷������ƶ�������һ����TF/MICRO SD�����ֻ�����ӳ��
 * ���ļ�ϵͳ�С�
 *
 * @return				���ƶ����������̷������ظ�����ʾ�ֻ�û�п��ƶ���������
 */
VMINT vm_get_removable_driver(void);

/**
 * ����ֻ�ϵͳ�̷�������ʹ���ֻ�����FLASH���γɵ����������϶����ڵ��������ޡ�
 *
 * @return				ϵͳ�̷������ظ�����ʾȡϵͳ�̷�ʧ�ܡ�
 */
VMINT vm_get_system_driver(void);

/**
 * �õ��ֻ��ļ�ϵͳ��ָ���̷���ʣ����ļ�ϵͳ�ռ䣬���ֽ�Ϊ��λ��������ȡ��ϵͳ�̷���ʾ�����롣
 * 
 * @code
 * VMINT sys_driver = -1;
 * VMUINT sys_driver_size = 0;
 * if ((sys_driver = vm_get_system_driver()) >= 0)
 * {
 *     VMCHAR driver_str[2] = {0};
 *     
 *     sprintf(driver_str, "%c", (VMCHAR)sys_driver);
 *     sys_driver_size = vm_get_disk_free_space(vm_ucs2_string(driver_str));
 * }
 * @endcode
 * @param[in]			drv_name �̷�����ֵ0��β��
 * @return 			ָ���̷�ʣ����ļ�ϵͳ�ռ䣬��λΪ�ֽڡ����ָ����
 *					�̷��������򷵻�0��
 */
VMUINT vm_get_disk_free_space(VMWSTR drv_name);

/**
 * @name ���뷨�ص�������״ֵ̬��
 * @{
 */
/**
 * �û����������������ɰ�ȷ����
 */
#define VM_INPUT_OK					(1)
/**
 * �û�ȡ���������롣
 */
#define VM_INPUT_CANCEL			(0)
/** @} */

/**
 * ���������봰�ڲ���ȡ���롣
 *	
 * @param f				������ɺ󽫻�ص��ĺ���ָ�룬�ɿͻ�����ע�ᡣ����
 *						state����ΪVM_INPUT_OK��ʾ�û����������ֲ���ȷ�ϣ�VM_INPUT_CANCEL���ʾ�û�ȡ����
 *						textΪ�û��������ֵ�ָ�롣
 *
 * @return				����0��ʾ���������봰�ڳɹ�������ʧ�ܡ�
 */
VMINT vm_input_text(void (*f)(VMINT state, VMWSTR text));

/**
 * �������֣�Ĭ�����뷨Ϊƴ����
 */
#define VM_INPUT_METHOD_TEXT		1

/** 
 * �������룬Ĭ�����뷨ΪӢ����ĸ�������������ǺŸ��ǡ�
 */
#define VM_INPUT_METHOD_PASSWORD	2

/** 
 * �������֣�Ĭ�����뷨Ϊ���֡�
 */
#define VM_INPUT_METHOD_NUMERIC		4

/**
 * ����СдӢ����ĸ��Ĭ�����뷨ΪСдӢ����ĸ��
 */
#define VM_INPUT_METHOD_ALPHABETIC	8

/**
 * ���������봰�ڲ��첽�����������֣�����vm_input_text()����ǿ�棬����
 * �趨Ĭ���������֣������ܹ��趨Ĭ�����뷨��
 *
 * @param def_str				Ĭ�����֣������봰�ڴ򿪺�Ĭ�����ֻ���ʾ�����봰���С�
 * @param def_input_method	Ĭ�����뷨������ΪINPUT_METHOD���������е�����һ�֡�
 * @param f					����������ݵĻص�������
 *
 * @return		����0��ʾ�������뷨���ڳɹ���Ӧ�ó���ͨ���ص����������������ݡ�
 */
VMINT vm_input_text2(VMWSTR def_str, VMINT def_input_method, 
	void (*f)(VMINT state, VMWSTR text));

/**
 * ���������봰�ڲ��첽�����������֣����ñ�
 * �������Ӧ�ó����л�����̨�����̺ͱ����붼��
 * �����봰�ڽӹܣ���������ɻ�ȡ��ʱ������Ӧ��
 * �����л���ǰ̨��Ȼ�󽫻��յ��������Ļص�
 * ���������ַ����Ļص�ֻ���ڻص����������÷�Χ
 * ��ʹ�á�
 * 
 * @param[in]					default_string Ĭ�����֣������봰�ڴ򿪺�Ĭ�����ֻ���ʾ�����봰���С�
 * @param[in]					input_max_size �����������ֵ�����ַ�������
 * @param[in]					default_input_method Ĭ�����뷨������ΪINPUT_METHOD���������е�����һ�֡�
 * @param[in/out]				input_text_cb ����������ݵĻص���������һ��������TRUE��ʾ
 *							�û�����"ȷ��"��ΪFALSE���ʾ�û�����ȡ����
 */
VMINT vm_input_text3(VMWSTR default_string, VMINT input_max_size, 
	VMINT default_input_method, void (*input_text_cb)(VMINT state, VMWSTR text));
	
/**
 * �ֻ�ƽ̨�Ƿ�֧��ȫ���̻��߱�׼���̡�
 * 
 * @return	�Ƿ�֧��ȫ���̻��߱�׼���̡�
 * @retval	FALSE ��ʾ��֧�֡�
 * @retval	TRUE ��ʾ֧�֡�
 */
VMINT vm_is_support_keyborad(void);

/**
 * �ֻ�ƽ̨�Ƿ�֧�ֱʴ���
 *
 * @return �Ƿ�֧�ֱʴ���
 * @retval FALSE ��ʾ��֧�֡�
 * @retval TRUE ��ʾ֧�֡�
 */
VMINT vm_is_support_pen_touch(void);

/**
 * �ֻ��Ƿ���Figner�İ汾��
 * 
 * @return		�Ƿ���Figner Touch�İ汾��
 * @retval		FALSE ��ʾ��Figner Touch�İ汾��
 * @retval		TRUE ��ʾ֧��Figner Touch�İ汾��
 */
VMINT vm_is_figner_touch_version(void);

/**
 * �Ƿ�֧��G-Sensor��
 *
 * @return				�ֻ��Ƿ�֧��G-Sensor��
 * @retval				TRUE��ʾ֧�֣�FALSE��ʾ��֧�֡�	
 */
VMINT vm_is_support_gsensor(void);

/**
 * �Ƿ�֧��Camera Sensor��
 *
 * @return				�ֻ��Ƿ�֧��Camera Sensor��
 * @retval				TRUE��ʾ֧�֣�FALSE��ʾ��֧�֡�	
 */
VMINT vm_is_support_camera_sensor(void);

/**
 *	ȡ�ļ��޸����ڡ�
 *
 *	@param filename   ȫ·���ļ�����UCS2����
 *	@param modify_time	�ļ�����޸�ʱ���ָ�룬ͨ�����ָ��ȥ����ֵ
 *
 *	@return 	0=ȡʱ��ɹ�	-1=ȡʱ��ʧ��
 */
VMINT vm_file_get_modify_time(const VMWSTR filename, vm_time_t * modify_time);

/**
 * ���Ҹ���Ŀ¼�µ��ļ�������ʹ��*ͨ�����
 *
 * @param pathname			����·����
 * @param direntry				�ҵ����ļ���Ŀ¼��Ϣ��
 *
 * @return					���ظ�����ʾʧ�ܣ����򷵻ش��ڻ����0��һ�����Ҿ����
 */
VMINT vm_find_first_ext(VMWSTR pathname, vm_fileinfo_ext * direntry);

/**
 * ����һ�β��ҽ���з�����һ���ļ�����
 *
 * @param handle		              vm_find_first���صľ����
 * @param direntry				�ҵ����ļ���Ŀ¼��Ϣ��
 *
 * @return				����0��ʾ�ҵ���һ���ļ��������ʾ���ҽ�����
 */
VMINT vm_find_next_ext(VMINT handle,  vm_fileinfo_ext * direntry);


/**
 * �رղ��ҽ�����������ڲ�����Ϻ���á�
 *
 * @param handle		���Ҿ����
 */
void vm_find_close_ext(VMINT handle);


typedef struct
{
	VMINT   current_city;       /* index of current selected city in world map */
	VMINT   foreign_city;       /* foreign city index */
	VMINT8  date_seperator;
	VMINT   date_format;
	VMINT   time_format;
	VMINT   current_dst;        /* current home city daylight saving time */
	
#ifdef __MMI_WC_TZ_SUPPORT__
	FLOAT   current_timezone;   /* current home city time zone */
	VMUINT8 highlightIndex;     /* current high light index in world clock map */
#endif
	
	/* below 4 variables are stored in nvram */
	VMINT8	foreign_index;
	VMINT8	wc_dst;             /* day light saving flag */
	VMINT8	setting_dt_dst;
	VMINT16	timezone;
	VMINT16	frn_timezone;
	
} vm_phoneset_info_struct;

#ifdef __cplusplus
}
#endif

#endif
