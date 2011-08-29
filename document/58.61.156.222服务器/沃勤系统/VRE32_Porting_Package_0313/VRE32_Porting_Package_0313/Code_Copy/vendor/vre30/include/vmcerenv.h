/******************************************************************************
 *
 * VRE数字证书封装模块。数字证书用于验证程序完整性，它被附加在文件尾部，本模块
 * 实现了向程序封装数字证书和从程序文件读取数字证书的功能。
 *
 * $date$
 * $author$
 *
 *****************************************************************************/
 
#ifndef VMCERENV_H
#define VMCERENV_H

#include "vmsys.h"
#include "vmio.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * 打开文件，如果文件包含数字证书则返回文件句柄，否则返回错误码。
 *
 * @param filename			文件路径。
 *
 * @return	如果文件成功打开则返回大于等于0的文件句柄，如果文件不存在，或者
 *			文件没有包含证书则返回-1。
 */
VMFILE vm_ce_open_file(VMWSTR filename);


void vm_ce_open_file_rom( VMCHAR * rom );


/**
 * 关闭已经打开的文件。
 *
 * @param handle			以vm_ce_open_file()打开的文件句柄。
 */ 
void vm_ce_close_file(VMFILE handle);

void vm_ce_close_file_rom( VMCHAR * rom );


/**
 * 从打开的文件中读取数字摘要，数字摘要以原文方式读出，如果摘要做过加密运算，
 * 读出的内容则为密文。
 *
 * @param handle			以vm_ce_open_file()打开的文件句柄。
 * @param buf				存放数字摘要的缓冲区指针。
 * @param buf_size			缓冲区指针长度。
 * @param type				存放摘要算法类型的指针。
 *
 * @return					返回0表示读取摘要成功，如果文件读失败，或者缓冲区
 *							不足以存放摘要信息则返回负数错误码。
 */
VMINT vm_ce_read_cert(VMFILE handle, VMUINT8* buf, VMINT buf_size, VMINT * type);

VMINT vm_ce_read_cert_rom(VMCHAR * rom, VMINT rom_size, VMUINT8* buf, VMINT buf_size, VMINT * type);


/**
 * 跳转到证书的第一条记录，在调用vm_ce_next_field()之前必须调用本函数，否则
 * 不能保证读出字段的正确性。
 *
 * @param handle			以vm_ce_open_file()打开的文件句柄。
 *
 * @return					返回0表示操作成功，否则返回负数错误码。
 */
VMINT vm_ce_first_field(VMFILE handle);

VMINT vm_ce_first_field_rom( VMCHAR * rom, VMINT rom_size );

/**
 * 把读指针移到证书的下一条记录。
 *
 * @param handle			以vm_ce_open_file()打开的文件句柄。
 *
 * @return					返回0表示操作成功，返回-1表示已经到最后一条记录，
 *							返回小于-2错误码表示其他错误。
 */
VMINT vm_ce_next_field(VMFILE handle);

/**
 * 读取当前记录的类型，本函数在调用vm_ce_next_field()后只能调用一次，重复调用
 * 会导致后继读出数据错误。
 *
 * @param handle			以vm_ce_open_file()打开的文件句柄。
 * @param type				存放记录类型的整数指针。
 * @param type				存放记录长度的整数指针。
 * 
 * @return					返回0表示操作成功，否则返回错误码。
 */
VMINT vm_ce_read_type(VMFILE handle, VMINT *type, VMINT * value_size );

VMINT vm_ce_read_type_rom(VMCHAR * rom, VMINT rom_size, VMINT *type, VMINT * value_size );

/**
 * 读取当前记录的值，本函数必须在调用vm_ce_read_type()之后调用，而且只能调用
 * 一次，重复调用会导致后继读出数据错误。
 *
 * @param handle			以vm_ce_open_file()打开的文件句柄。
 * @param value				存放字段值的指针。
 * @param value_size		value指针所指向内存块的字节长度。
 *
 * @return 					返回0表示操作成功，否则返回错误码。
 */
VMINT vm_ce_read_value(VMFILE handle, VMUINT8 *value, VMINT value_size);

VMINT vm_ce_read_value_rom(VMCHAR * rom, VMINT rom_size, VMUINT8 *value, VMINT value_size);


/**
 * 读取当前应用附加信息的摘要，摘要算法在证书内说明
 *
 * @param digest_buf		存放摘要的内存指针
 * @param buf_len			存放字段值的指针。
 *
 * @return 				
 */
void vm_ce_get_cert_digest( VMUCHAR * digest_buf, VMINT buf_len );

#ifdef __cplusplus
}
#endif

#endif
