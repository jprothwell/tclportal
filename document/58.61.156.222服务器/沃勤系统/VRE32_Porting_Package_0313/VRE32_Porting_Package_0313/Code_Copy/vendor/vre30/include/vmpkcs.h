#ifndef		_VM_PKCK_1_PADDDING_SCHEME_
#define		_VM_PKCK_1_PADDDING_SCHEME_

#include "vmsys.h"

#define RSA_PKCS_PADDING_SIZE			11


#define	PUB_PADDING					1
#define	PRI_PADDING					2

#define PADDING_TYPE_ERROR			0

#define PKCS_PADDING_OK					1

/**
 * 加入符合PKCS1规范的填充。
 *
 * @param to_buf			目标缓冲的指针。
 * @param to_len			目标缓冲的长度。
 * @param from_buf		指向需要填充的内容的指针。
 * @param fromn_len		需要填充的内容的长度。 
 * @param type				填充所用类型，PUB_PADDING为公钥签名填充类型，PRI_PADDING为私钥签名填充类型。 
 * @return						添加成功返回1，失败返回0。
 */
VMINT vm_add_pkcs_padding( VMUCHAR * to_buf, VMINT to_len, VMUCHAR * from_buf, VMINT from_len, VMINT type );


/**
 * 根据PKCS1规范去除填充，不需要指定填充类型。如果原始字符串中无PKCS1规范填充，将不作修改。
 *
 * @param to_buf			目标缓冲的指针。
 * @param to_len			目标缓冲的长度。
 * @param from_buf		指向需要去除填充的内容的指针。
 * @param fromn_len		需要去除填充的内容的长度。 
 * @return						去除填充成功返回1去除填充后的内容长度，失败返回0。
 */
VMINT vm_check_pkcs_padding( VMUCHAR * to_buf, VMINT to_len, VMUCHAR * from_buf, VMINT from_len );

#endif