/*
 *  sha1.h
 *
 *	Copyright (C) 1998
 *	Paul E. Jones <paulej@arid.us>
 *	All Rights Reserved
 *
 *****************************************************************************
 *	$Id: vmsha1.h,v 1.1 2008/12/30 02:19:04 wei.han Exp $
 *****************************************************************************
 *
 *  Description:
 *      This class implements the Secure Hashing Standard as defined
 *      in FIPS PUB 180-1 published April 17, 1995.
 *
 *      Many of the variable names in the SHA1Context, especially the
 *      single character names, were used because those were the names
 *      used in the publication.
 *
 *      Please read the file sha1.c for more information.
 *
 */

#ifndef __SHA1_VRE_H__
#define __SHA1_VRE_H__


#include "vmsys.h"


/* 
 *  This structure will hold context information for the hashing
 *  operation
 */
typedef struct SHA1Context
{
	VMUINT		Message_Digest[5]; /* Message Digest (output)          */

    VMUINT		Length_Low;        /* Message length in bits           */
    VMUINT		Length_High;       /* Message length in bits           */

    VMUINT8		Message_Block[64]; /* 512-bit message blocks      */
    VMINT		Message_Block_Index;    /* Index into message block array   */

    VMINT		Computed;               /* Is the digest computed?          */
    VMINT		Corrupted;              /* Is the message digest corruped?  */
} SHA1Context;


/*
 *  Function Prototypes
 */
void	vm_sha1_reset( SHA1Context * context );
VMINT	vm_sha1_result( SHA1Context * context );

void	vm_sha1_input( SHA1Context * context, VMUINT8 * message_array, VMUINT length );

#endif
