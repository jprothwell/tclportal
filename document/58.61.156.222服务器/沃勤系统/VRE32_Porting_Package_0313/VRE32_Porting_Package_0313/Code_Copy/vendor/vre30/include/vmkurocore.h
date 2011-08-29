//@ Programmer: hujie 2009.09.28
#ifndef _VRE_APP_kuro_core_vre_
#define	_VRE_APP_kuro_core_vre_
#include "vmsys.h"

/**
* Encrypt / Decrpyt kak.dat
* 
* @param pKakDat	kak data
* @param nLength	kak data length
* @param bEncrypt	if true, encrypt, or else decrpyt
*/
VMINT vm_encrypt_kak(VMINT8* pKakDat, VMINT nLength, VMINT8 bEncrypt);

/**
* 激活AlbumKey
*
* @param nAlbumKey		待激活的AlbumKey
* @param bTemp				是否临时激活
* @param wValidPeriod	有效期	(缺省为0)
*
* @return 1-成功，0-失败
*/
VMINT vm_RegisterAlbumKey(VMINT nAlbumKey, VMINT bTemp, VMINT wValidPeriod);

/**
* 取消激活AlbumKey
*
* @param nAlbumKey		已激活的AlbumKey
*
* @return 1-成功，0-失败
*/
VMINT vm_UnRegisterAlbumKey(VMINT nAlbumKey);

/**
* 获取albumkey的激活状态
*
* @param nAlbumKey		Album Key
*
* @return 激活状态
*/
VMINT vm_GetAlbumKeyStatus(VMINT nAlbumKey);




#endif
