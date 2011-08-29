#ifndef _VM_CER_MNG_
#define	_VM_CER_MNG_

#include "vmcert.h"
#include "vmsys.h"

/**
 * 初始化应用程序证书验证系统。
 *
 * @param 
 *
 * @return	如果证书系统初始化成功，返回值为0，失败返回错误码。
 */
VMINT vm_ce_init( void );


/**
 * 结束应用程序证书验证系统。
 *
 * @param 
 *
 * @return
 */
void vm_ce_finialize( void );


/**
 * 装载应用程序证书。
 *
 * @param filename			文件路径。
 *
 * @return	如果证书装载成功则返回描述证书的结构指针，如果证书不存在，或者
 *			文件没有包含证书则返回值为空。
 */
VRECert * vm_ce_load_app( VMWSTR filename );

VRECert * vm_ce_load_app_rom( VMCHAR * rom, VMINT	rom_size );

/**
 * 卸载应用程序证书。
 *
 * @param cert				描述证书的结构指针。
 *
 * @return	无返回值
 */
void vm_ce_unload_app( VRECert * cert );

enum{
		VERIFY_SIG = 1,
		VERIFY_FULL
};

/**
 * 验证应用程序是否合法。
 *
 * @param cert				描述证书的结构指针。
 * @param digest			应用程序摘要（同应用程序标签中的摘要信息）。
 * @param len				应用程序摘要长度
 * @param type				应用程序类型
 * @param mode				验证模式，VERIFY_SIG表示仅验证签名，VERIFY_FULL表示会检验其他运行条件 
 * @return	如果应用程序验证成功则返回值为零，否则返回负数的错误代码。
 */
VMINT vm_ce_verify_app( VRECert * cert, VMUCHAR * digest, VMINT len, VMINT mode );


/**
 * 获取应用程序的摘要。
 *
 * @param filename		应用程序名。
 * @param cache_buf		文件缓冲。
 * @param cache_len		文件缓冲大小。 
 * @param digest			应用程序摘要（同应用程序标签中的摘要信息）。
 * @return				计算应用程序摘要是否成功，0为成功，负数为错误代码。
 */
VMINT vm_ce_get_app_digest( VMWSTR filename, VMUCHAR * cache_buf, VMINT cache_len, unsigned char digest[DIG_MAX_LEN] );


/**
 * 获取应用程序的摘要。
 *
 * @param rom			应用程序名。
 * @param rom_size		应用程序大小。 
 * @param digest			应用程序摘要（同应用程序标签中的摘要信息）。
 * @return				计算应用程序摘要是否成功，0为成功，负数为错误代码。
 */
VMINT vm_ce_get_app_digest_rom( VMCHAR * rom, VMINT rom_size, unsigned char digest[DIG_MAX_LEN] );

/**
 * 验证应用程序是否合法。
 *
 * @param filename		应用程序名。
 * @return	如果应用程序验证成功则返回值为零，否则返回负数错误码。
 */
VMINT vm_ce_auth_app( VMWSTR filename, VMUCHAR * cache_buf, VMINT cache_len );


/**
 * 过滤在黑名单中的应用id，过滤过的应用id列表，
 * 如果原始列表中存在已列入黑名单中的id，此id 会被清除
 *
 * @param appid_list		应用id 列表
 * @param appid_len		应用id 列表长度

 * @return				成功过滤时返回零，否则返回负数的错误代码。
 */
VMINT vm_ce_check_appid_list( VMINT * appid_list, VMINT appid_len );

/**
 * UA 保护用的DES解密
 * 
 *
 * @param input			待解密的密文
 * @param input_len		待解密的密文长度
 * @param output_len		解密后的数据长度

 * @return				成功解密时返回密文的指针，否则返回NULL。
 */
VMUINT8 * vm_ua_decrypt_data(VMUINT8 * input, VMINT input_len, VMINT * output_len);
#endif
