#ifdef __VRE__

#include "vmmacrostub.h"
#include "vmsys.h"
#include "vmkurocore.h"


/**
* Encrypt / Decrpyt kak.dat
* 
* @param pKakDat	kak data
* @param nLength	kak data length
* @param bEncrypt	if true, encrypt, or else decrpyt
*
* Note: this API will be provided by VRE
*/
VMINT vm_encrypt_kak(VMINT8* pKakDat, VMINT nLength, VMINT8 bEncrypt)
{
	return stub_encrypt_kak(pKakDat, nLength, bEncrypt);
}

VMINT vm_RegisterAlbumKey(VMINT nAlbumKey, VMINT bTemp, VMINT wValidPeriod)
{
	return stub_RegisterAlbumKey(nAlbumKey, bTemp, wValidPeriod);
}

VMINT vm_UnRegisterAlbumKey(VMINT nAlbumKey)
{
	return stub_UnRegisterAlbumKey(nAlbumKey);
}

VMINT vm_GetAlbumKeyStatus(VMINT nAlbumKey)
{
	return stub_GetAlbumKeyStatus(nAlbumKey);
}

#endif /* __VRE__ */
