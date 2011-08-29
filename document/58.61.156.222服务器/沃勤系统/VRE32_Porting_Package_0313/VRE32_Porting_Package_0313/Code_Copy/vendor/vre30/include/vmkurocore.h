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
* ����AlbumKey
*
* @param nAlbumKey		�������AlbumKey
* @param bTemp				�Ƿ���ʱ����
* @param wValidPeriod	��Ч��	(ȱʡΪ0)
*
* @return 1-�ɹ���0-ʧ��
*/
VMINT vm_RegisterAlbumKey(VMINT nAlbumKey, VMINT bTemp, VMINT wValidPeriod);

/**
* ȡ������AlbumKey
*
* @param nAlbumKey		�Ѽ����AlbumKey
*
* @return 1-�ɹ���0-ʧ��
*/
VMINT vm_UnRegisterAlbumKey(VMINT nAlbumKey);

/**
* ��ȡalbumkey�ļ���״̬
*
* @param nAlbumKey		Album Key
*
* @return ����״̬
*/
VMINT vm_GetAlbumKeyStatus(VMINT nAlbumKey);




#endif
