#ifndef	_VM_RSA_H_
#define _VM_RSA_H_

#include "vmsys.h"

#define		KEY_LEN			64

typedef struct _VMKey{
		VMINT		id;
		VMINT		modlen;
		VMINT		keylen;
		VMUCHAR		mod[KEY_LEN];
		VMUCHAR		key[KEY_LEN];
} VMKey;

typedef VMKey		VMPUBKey;
typedef	VMKey		VMPRIKey;

enum{
	VM_RSA_BN_INDEX_IN = 0,
	VM_RSA_BN_INDEX_MOD,
	VM_RSA_BN_INDEX_KEY,

	VM_RSA_BN_INDEX_RES,
	VM_RSA_BN_INDEX_TOTAL
};

typedef struct _VMPUBKeyCert{
		VMPUBKey		pub;
		VMUCHAR			digest[KEY_LEN];
} VMPUBCert;


/**
 * 用指定编号的密钥解密给定的签名。
 *
 * @param signature		指向签名的内存指针。
 * @param sign_len		签名的长度。
 * @param id					密钥编号。
 * @param text				指向签名解密后内容的内存指针。
 * @param text_len		(in)接受签名解密后内容的内存长度，(out)签名解密后内容的长度。  
 * @return						如果解密成功，返回值为0，失败返回错误码。
 */
VMINT vm_rsa_verify_by_id( VMUCHAR * signature, VMINT sign_len, VMINT id, VMUCHAR * text, VMINT * text_len );



/**
 * 用指定的密钥解密给定的签名。
 *
 * @param signature		指向签名的内存指针。
 * @param sign_len		签名的长度。
 * @param key					指向存储密钥的结构体的指针。
 * @param text				指向签名解密后内容的内存指针。
 * @param text_len		(in)接受签名解密后内容的内存长度，(out)签名解密后内容的长度。  
 * @return						如果解密成功，返回值为0，失败返回错误码。
 */
VMINT vm_rsa_verify( VMUCHAR * signature, VMINT sign_len, VMKey * key, VMUCHAR * text, VMINT * text_len );


/**
 * 用指定的密钥对给定的内容签名。
 *
 * @param content			指向签名的内存指针。
 * @param cont_len		签名的长度。
 * @param key					指向存储密钥的结构体的指针。
 * @param signature		指向签名解密后内容的内存指针。
 * @param sign_len		(in)接受签名解密后内容的内存长度，(out)签名解密后内容的长度。
 * @param type				指定签名使用的密钥类型，PUB_PADDING指用公钥签名；PRI_PADDING指用私钥签名。
 * @return						如果解密成功，返回值为0，失败返回错误码。
 */
VMINT vm_rsa_sign( VMUCHAR * content, VMINT cont_len, VMKey * key, VMUCHAR * signature, VMINT * sign_len, VMINT type );


/**
 * 用指定的密钥对给定的内容签名。
 *
 * @param content			指向签名的内存指针。
 * @param cont_len		签名的长度。
 * @param prikey			指向存储密钥的结构体的指针。
 * @param signature		指向签名解密后内容的内存指针。
 * @param sign_len		(in)接受签名解密后内容的内存长度，(out)签名解密后内容的长度。
 * @param type				指定签名使用的密钥类型，PUB_PADDING指用公钥签名；PRI_PADDING指用私钥签名。
 * @return						如果解密成功，返回值为0，失败返回错误码。
 */
VMINT vm_rsa_sign_by_id( VMUCHAR * content, VMINT cont_len, VMINT id, VMUCHAR * signature, VMINT * sign_len, VMINT type );


#endif
