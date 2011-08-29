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
 * @name VRE支持的按键事件。
 * @{
 */
/**
 * 键盘松开事件。
 */
#define VM_KEY_EVENT_UP			(1)

/**
 * 键盘按下事件。
 */
#define VM_KEY_EVENT_DOWN			(2)

/**
 * 键盘长按事件。
 */
#define VM_KEY_EVENT_LONG_PRESS	(3)

/**
 * 键盘多次按同一个键的操作。
 */
#define VM_KEY_EVENT_REPEAT		(4)
/** @} */


/**
 * @name VRE支持的按键。
 * @{
 */
/**
 * 上方向键。
 */
#define VM_KEY_UP					(-1)

/**
 * 下方向键。
 */
#define VM_KEY_DOWN				(-2)

/**
 * 左方向键。
 */
#define VM_KEY_LEFT					(-3)

/**
 * 右方向键。
 */
#define VM_KEY_RIGHT				(-4)

/**
 * 左功能键。
 */
#define VM_KEY_LEFT_SOFTKEY		(-6)

/**
 * 右功能键。
 */
#define VM_KEY_RIGHT_SOFTKEY		(-7)

/**
 * 确认(OK)键。
 */
#define VM_KEY_OK					(-5)

/**
 * 删除键。
 */
#define VM_KEY_CLEAR				(-8)

/**
 * 返回键。
 */
#define VM_KEY_BACK					(-9)

/**
 * 数字0键。
 */
#define VM_KEY_NUM0				(48)

/**
 * 数字1键。
 */
#define VM_KEY_NUM1				(49)

/**
 * 数字2键。
 */
#define VM_KEY_NUM2				(50)

/**
 * 数字3键。
 */
#define VM_KEY_NUM3				(51)

/**
 * 数字4键。
 */
#define VM_KEY_NUM4				(52)

/**
 * 数字5键。
 */
#define VM_KEY_NUM5				(53)

/**
 * 数字6键。
 */
#define VM_KEY_NUM6				(54)

/**
 * 数字7键。
 */
#define VM_KEY_NUM7				(55)

/**
 * 数字8键。
 */
#define VM_KEY_NUM8				(56)

/**
 * 数字9键。
 */
#define VM_KEY_NUM9				(57)

/**
 * 向上的音量键。
 */
#define VM_KEY_VOL_UP				(58)

/**
 * 向下的音量键。
 */
#define VM_KEY_VOL_DOWN			(59)

/**
 * 井号(#)键。
 */
#define VM_KEY_POUND				(35)

/**
 * 星号(*)键。
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
 * 文件属性。
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
   VMWCHAR 	     filefullname[MAX_APP_NAME_LEN];   /*不带目录的文件名*/
   VMCHAR          filename[8];                                     /*8.3格式文件名字符数组，末尾可能为非'\0'*/
   VMCHAR          extension[3];                                   /*8.3格式文件扩展名字符数组，末尾可能为非'\0'*/
   VMBYTE           attributes;
   vm_time_t       create_datetime;
   vm_time_t	    modify_datetime;
   VMUINT           filesize;
   VMUINT           drive;
   VMUINT           stamp;
} vm_fileinfo_ext;

typedef void (*vm_key_handler_t)(VMINT event, VMINT keycode);

/**
 * 注册键盘回调函数，用于捕获键盘输入事件。
 *
 * @param f				事件回调函数，event参数表示事件类型，见VM_KEY_EVENT常量定义；
 *						keycode参数表示键值，见VM_KEY常量定义。
 */
void vm_reg_keyboard_callback(vm_key_handler_t handler);

/**
 * @name VRE支持的笔触消息。
 * @{
 */
/**
 * 触控笔按下事件。
 */
#define VM_PEN_EVENT_TAP				1

/**
 * 触控笔松开事件。
 */
#define VM_PEN_EVENT_RELEASE			2

/**
 * 触控笔移动事件。
 */
#define VM_PEN_EVENT_MOVE				3

/**
 * 触控笔长按事件。
 */
#define VM_PEN_EVENT_LONG_TAP			4

/**
 * 触控笔双击事件。
 */
#define VM_PEN_EVENT_DOUBLE_CLICK		5

/**
 * 触控笔重复点击事件。
 */
#define VM_PEN_EVENT_REPEAT			6
/** @} */

typedef void (*vm_pen_handler_t)(VMINT event, VMINT x, VMINT y);

/**
 * 注册笔输入回调函数，用于捕获触摸屏输入事件。
 *
 * @param f				事件回调函数，event表示事件类型，见VM_PEN_EVENT常量定义；
 *						x参数表示点击横坐标，y参数表示点击纵坐标。
 */
void vm_reg_pen_callback(vm_pen_handler_t handler);

/**
 * 打开文件使其处于可读状态。
 */
#define MODE_READ					1

/**
 * 打开文件使其处于可写状态。
 */
#define MODE_WRITE					2

/**
 * 打开文件使其处于写状态，如果文件不存在则自动创建之。
 */
#define MODE_CREATE_ALWAYS_WRITE	4

/**
 * 打开文件使其处于追加状态，文件中已存在的内容不会被自动清空。
 */
#define MODE_APPEND					8

/**
 * 打开文件。
 *
 * @param filename		以UCS2格式编码的文件路径。
 * @param mode			文件打开模式，读（MODE_READ），写（MODE_WRITE），
 *						无论文件存在与否总是创建之（MODE_CREATE_ALWAYS_WRITE）。
 * @param binary		TRUE表示以二进制格式打开文件，FALSE表示以ASCII方式打开文件。
 *
 * @return				成功打开则返回非负数句柄，如果为负数则表示失败。
 */
VMFILE vm_file_open(const VMWSTR filename, VMUINT mode, VMUINT binary);

/**
 * 关闭文件。
 *
 * @param handle		要关闭的文件句柄。
 */
void vm_file_close(VMFILE handle);

/**
 * 把文件内容读入内存，系统从文件当前读写指针位置开始读。
 *
 * @param handle		读文件句柄。
 * @param data			要读入的内存地址指针。
 * @param length		要读入的字节数。
 * @param nread			真正读入的字节数。
 *
 * @return				返回读到的字节数，返回0表示有错误发生或者已经到达文件尾部。
 */
VMINT vm_file_read(VMFILE handle, void * data, VMUINT length, VMUINT *nread);

/**
 * 向文件写入数据，系统从文件当前读写诶指针位置开始写。
 *
 * @param handle		被写入文件的句柄。
 * @param data			要写入的数据内存指针。
 * @param length		要写入的字节数。
 * @param written		实际写入的字节数。
 *
 * @return				实际写入的字节数，返回0表示发生错误。
 */
VMINT vm_file_write(VMFILE handle, void * data, VMUINT length, VMUINT * written);

/**
 * 把I/O缓冲中的内容立即刷新至文件中，这个函数用于强制把写入的数据提交到文件中。
 *
 * @param handle		要刷新的文件句柄。
 *
 * @return				返回0表示成功，否则为失败。
 */
VMINT vm_file_commit(VMFILE handle);

#define BASE_BEGIN		1
#define BASE_CURR		2
#define BASE_END		3

/**
 * 移动文件读写指针到指定位置。
 * 如果指定位置超过了文件范围，将返回操作失败。
 * 
 *
 * @param handle		文件句柄。
 * @param offset		移动偏移量，以字节为单位。
 * @param base			移动基址，从文件头开始（BASE_BEGIN），从当前位置开始（BASE_CURR），
 *						从文件尾开始（BASE_END）。
 *
 * @return				返回0表示成功，返回负数表示失败。
 */
VMINT vm_file_seek(VMFILE handle, VMINT offset, VMINT base);

/**
 * 文件读写指针的当前位置。
 *
 * @param handle		文件句柄。
 *
 * @return			当前文件指针位置，返回负数表示失败。
 */
VMINT vm_file_tell(VMFILE handle);

/**
 * 文件读写指针的当前位置是否已经到文件末尾。
 *
 * @param handle		文件句柄。
 *
 * @return			TRUE=已到末尾， FALSE=未到末尾。
 */
VMINT vm_file_is_eof(VMFILE handle);

/**
 * 获得文件大小，以字节为单位。
 * 
 * @param handle		文件句柄。
 * @param file_size		需要被写入的文件的大小的指针，以字节为单位。
 *
 * @return				返回0表示取文件大小成功，否则为失败。
 */
VMINT vm_file_getfilesize(VMFILE handle, VMUINT *file_size);

/**
 * 删除文件。
 * 
 * @param filename		以UCS2编码格式的文件路径。
 *
 * @return				返回0表示成功，否则为失败。
 */
VMINT vm_file_delete(const VMWSTR filename);

/**
 * 文件重命名。
 * 
 * @param filename		以UCS2格式编码的原始文件路径。
 * @param newname		以UCS2格式编码的目标文件路径。
 *
 * @return				返回0表示成功，否则为失败。
 */
VMINT vm_file_rename(const VMWSTR filename, const VMWSTR newname);

/**
 * 创建目录。
 *
 * @param dirname		以UCS2格式编码的路径名。
 *
 * @return				返回0表示成功，否则为失败。
 */
VMINT vm_file_mkdir(const VMWSTR dirname);

/**
 * 删除路径。
 *
 * @param dirname		以UCS2格式编码的被删除路径名。
 *
 * @return				返回0表示成功，否则为失败。
 */
VMINT vm_file_rmdir(const VMWSTR dirname);

/**
 * 设置文件属性。
 * 设置的值不能包含VM_FS_ATTR_VOLUME，VM_FS_ATTR_DIR，VM_FS_LONGNAME_ATTR
 * 文件属性的值为或运算的组合值，具体值请参考文件属性的宏定义。
 *
 * @param filename   文件名(带全路径)。
 * @param attributes  文件属性。
 *
 * @return       返回0表示成功，负数为失败。
 */
VMINT vm_file_set_attributes(const VMWSTR filename, VMBYTE attributes);

/**
 * 获取文件属性。
 * 文件属性的值为或运算的组合值，具体值请参考文件属性的宏定义。
 *
 * @param filename  文件名(带全路径)。
 *
 * @return 返回文件属性，负数为失败。
 */
VMINT vm_file_get_attributes(const VMWSTR filename);


/**
 * 查找给定目录下的文件，可以使用*通配符。
 *
 * @param pathname			查找路径。
 * @param info				找到的文件信息。
 *
 * @return					返回负数表示失败，否则返回大于或等于0的一个查找句柄。
 */
VMINT vm_find_first(VMWSTR pathname, struct vm_fileinfo_t* info);

/**
 * 在上一次查找结果中返回下一个文件名。
 *
 * @param handle		vm_find_first返回的句柄。
 * @param info			找到的文件信息。
 *
 * @return				返回0表示找到下一个文件，否则表示查找结束。
 */
VMINT vm_find_next(VMINT handle, struct vm_fileinfo_t* info);

/**
 * 关闭查找结果集，必须在查找完毕后调用。
 *
 * @param handle		查找句柄。
 */
void vm_find_close(VMINT handle);

#define vm_get_removable_driver vm_get_removeable_driver
/**
 * 获得手机上可移动驱动器的盘符，可移动驱动器一般是TF/MICRO SD卡，手机将其映射
 * 到文件系统中。
 *
 * @return				可移动驱动器的盘符，返回负数表示手机没有可移动驱动器。
 */
VMINT vm_get_removable_driver(void);

/**
 * 获得手机系统盘符，这是使用手机内置FLASH所形成的驱动器，肯定存在但容量有限。
 *
 * @return				系统盘符，返回负数表示取系统盘符失败。
 */
VMINT vm_get_system_driver(void);

/**
 * 得到手机文件系统上指定盘符的剩余的文件系统空间，以字节为单位。以下是取得系统盘符的示例代码。
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
 * @param[in]			drv_name 盘符以数值0结尾。
 * @return 			指定盘符剩余的文件系统空间，单位为字节。如果指定的
 *					盘符不存在则返回0。
 */
VMUINT vm_get_disk_free_space(VMWSTR drv_name);

/**
 * @name 输入法回调函数的状态值。
 * @{
 */
/**
 * 用户在输入界面输入完成按确定。
 */
#define VM_INPUT_OK					(1)
/**
 * 用户取消本次输入。
 */
#define VM_INPUT_CANCEL			(0)
/** @} */

/**
 * 打开文字输入窗口并获取输入。
 *	
 * @param f				输入完成后将会回调的函数指针，由客户程序注册。其中
 *						state参数为VM_INPUT_OK表示用户输入了文字并已确认，VM_INPUT_CANCEL则表示用户取消。
 *						text为用户输入文字的指针。
 *
 * @return				返回0表示打开文字输入窗口成功，否则失败。
 */
VMINT vm_input_text(void (*f)(VMINT state, VMWSTR text));

/**
 * 输入文字，默认输入法为拼音。
 */
#define VM_INPUT_METHOD_TEXT		1

/** 
 * 输入密码，默认输入法为英文字母，输入内容用星号覆盖。
 */
#define VM_INPUT_METHOD_PASSWORD	2

/** 
 * 输入数字，默认输入法为数字。
 */
#define VM_INPUT_METHOD_NUMERIC		4

/**
 * 输入小写英文字母，默认输入法为小写英文字母。
 */
#define VM_INPUT_METHOD_ALPHABETIC	8

/**
 * 打开文字输入窗口并异步获得输入的文字，这是vm_input_text()的增强版，可以
 * 设定默认输入文字，并且能够设定默认输入法。
 *
 * @param def_str				默认文字，在输入窗口打开后，默认文字会显示在输入窗口中。
 * @param def_input_method	默认输入法，必须为INPUT_METHOD常量定义中的其中一种。
 * @param f					获得输入内容的回调函数。
 *
 * @return		返回0表示开启输入法窗口成功，应用程序通过回调函数获得输入的内容。
 */
VMINT vm_input_text2(VMWSTR def_str, VMINT def_input_method, 
	void (*f)(VMINT state, VMWSTR text));

/**
 * 打开文字输入窗口并异步获得输入的文字，调用本
 * 函数会把应用程序切换到后台，键盘和笔输入都会
 * 被输入窗口接管，在输入完成或取消时，首先应用
 * 程序被切换掉前台，然后将会收到输入结果的回调
 * 对于输入字符串的回调只能在回调函数的作用范围
 * 内使用。
 * 
 * @param[in]					default_string 默认文字，在输入窗口打开后，默认文字会显示在输入窗口中。
 * @param[in]					input_max_size 允许输入文字的最大字符个数。
 * @param[in]					default_input_method 默认输入法，必须为INPUT_METHOD常量定义中的其中一种。
 * @param[in/out]				input_text_cb 获得输入内容的回调函数，第一个参数是TRUE表示
 *							用户按了"确定"，为FALSE则表示用户按了取消。
 */
VMINT vm_input_text3(VMWSTR default_string, VMINT input_max_size, 
	VMINT default_input_method, void (*input_text_cb)(VMINT state, VMWSTR text));
	
/**
 * 手机平台是否支持全键盘或者标准键盘。
 * 
 * @return	是否支持全键盘或者标准键盘。
 * @retval	FALSE 表示不支持。
 * @retval	TRUE 表示支持。
 */
VMINT vm_is_support_keyborad(void);

/**
 * 手机平台是否支持笔触。
 *
 * @return 是否支持笔触。
 * @retval FALSE 表示不支持。
 * @retval TRUE 表示支持。
 */
VMINT vm_is_support_pen_touch(void);

/**
 * 手机是否是Figner的版本。
 * 
 * @return		是否是Figner Touch的版本。
 * @retval		FALSE 表示是Figner Touch的版本。
 * @retval		TRUE 表示支持Figner Touch的版本。
 */
VMINT vm_is_figner_touch_version(void);

/**
 * 是否支持G-Sensor。
 *
 * @return				手机是否支持G-Sensor。
 * @retval				TRUE表示支持，FALSE表示不支持。	
 */
VMINT vm_is_support_gsensor(void);

/**
 * 是否支持Camera Sensor。
 *
 * @return				手机是否支持Camera Sensor。
 * @retval				TRUE表示支持，FALSE表示不支持。	
 */
VMINT vm_is_support_camera_sensor(void);

/**
 *	取文件修改日期。
 *
 *	@param filename   全路径文件名，UCS2编码
 *	@param modify_time	文件最后修改时间的指针，通过这个指针去返回值
 *
 *	@return 	0=取时间成功	-1=取时间失败
 */
VMINT vm_file_get_modify_time(const VMWSTR filename, vm_time_t * modify_time);

/**
 * 查找给定目录下的文件，可以使用*通配符。
 *
 * @param pathname			查找路径。
 * @param direntry				找到的文件的目录信息。
 *
 * @return					返回负数表示失败，否则返回大于或等于0的一个查找句柄。
 */
VMINT vm_find_first_ext(VMWSTR pathname, vm_fileinfo_ext * direntry);

/**
 * 在上一次查找结果中返回下一个文件名。
 *
 * @param handle		              vm_find_first返回的句柄。
 * @param direntry				找到的文件的目录信息。
 *
 * @return				返回0表示找到下一个文件，否则表示查找结束。
 */
VMINT vm_find_next_ext(VMINT handle,  vm_fileinfo_ext * direntry);


/**
 * 关闭查找结果集，必须在查找完毕后调用。
 *
 * @param handle		查找句柄。
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
