#ifndef _VM_DES_H_
#define _VM_DES_H_

#include "vmsys.h"

#ifndef uint8
#define uint8  VMUINT8
#endif

#ifndef uint32
#define uint32 VMUINT
#endif

#define	VMDESHANDLE			VMINT

#define	DES_INVALID_HANDLE		-1
#define	DES_OK					0

#define DES_BLOCK_SIZE		8

VMDESHANDLE vm_des_set_key( VMUINT8 key[8] );

VMUINT8 * vm_des_encrypt( VMDESHANDLE handle, VMUINT8 * input, VMINT input_len, VMINT * output_len );

VMUINT8 * vm_des_decrypt( VMDESHANDLE handle, VMUINT8 * input, VMINT input_len, VMINT * output_len );

VMINT vm_des_reset_key( VMDESHANDLE handle );

#endif /* des.h */

