#ifndef	_VM_MUL_LANG_
#define	_VM_MUL_LANG_

#include "vmsys.h"

#define		MUL_LANG_RES_NAME		"lang.bin"

//language type list
enum{
	VM_LANG_NULL = 0,
	
	VM_LANG_ENG,
	VM_LANG_CHS,
	VM_LANG_CHT
};

#define		VM_LANG_ID_START		VM_LANG_ENG
#define		VM_LANG_ID_END			VM_LANG_CHT

#define		VM_LANG_ID_DEFAULT		VM_LANG_ENG


/**
 * 初始化多语言资源库。多语言资源存在于vxp文件的vm_res段。资源库在vm_res段中的名字为lang.bin。
 *
 * @return		装载多语言资源库的内存首地址。NULL代表失败。
 */
VMCHAR * vm_mul_lang_init( void );


/**
 * 释放多语言资源库。
 *
 * @param mul_lang_handle 		多语言资源库的内存地址。
 */
void vm_mul_lang_deinit( VMCHAR * mul_lang_handle );


/**
 * 从多语言资源库中获取指定的字符串。
 *
 * @param lang_buf 		多语言资源库的内存地址。
 * @param res_id		字符串资源号。
 * @param lang_id  		语言类型。
 * @param lang_buf  	接受指向字符串的指针的内存。
 *
 * @return				字符串长度。如果返回0，获取指定的字符串失败。成功时，lang_buf指向
 *						的空间存放字符串首地址。
 */
VMINT vm_mul_lang_get_string( VMCHAR * lang_buf, VMINT res_id, VMINT lang_id, VMCHAR ** str_buf );


/**
 * 设定当前的语言。
 *
 * @param lang_buf  	语言类型。
 *
 * @return				返回1成功，0失败。
 */
VMINT vm_mul_lang_set_lang( VMINT lang_id );

/**
 * 获取当前语言设定。
 *
 * @return				语言类型，默认为VM_LANG_ENG。
 */
VMINT vm_mul_lang_get_lang( void );

/**
 * 绘制文字。
 *
 * @param disp_buf		显示缓冲区指针。
 * @param x				被绘制文字的左上角横坐标。
 * @param y				被绘制文字的左上角纵坐标。
 * @param lang_buf		多语言资源库的内存地址。
 * @param res_id		字符串资源号。
 * @param color			文字颜色，使用565格式。
 *
 * @return				
 */
void vm_graphic_textout_by_id( VMUINT8* disp_buf, VMINT x, VMINT y, VMCHAR * lang_buf, VMINT res_id, VMUINT16 color);


/**
 * 获得给定字符串资源长度，以象素为单位。
 *
 * @param lang_buf		多语言资源库的内存地址。
 * @param res_id		字符串资源号。
 *
 * @return				成功返回字符串宽度，以象素为单位。否则返回错误码
 */
VMINT vm_graphic_get_string_width_by_id( VMCHAR * lang_buf, VMINT res_id );

#endif