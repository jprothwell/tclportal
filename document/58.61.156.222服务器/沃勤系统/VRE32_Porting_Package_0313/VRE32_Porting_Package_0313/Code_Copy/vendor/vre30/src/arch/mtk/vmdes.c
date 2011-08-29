#ifdef __VRE__

#if defined(__VRE_RB_08A__) || defined(__VRE_RB_08B__) /*Version control*/
/*
 *  FIPS-46-3 compliant 3DES implementation
 *
 *  Copyright (C) 2001-2003  Christophe Devine
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "vmdes.h"

/* the eight DES S-boxes */

#define		DES_CTX_MAX		2

typedef struct
{
    uint32		esk[32];     /* DES encryption subkeys */
    uint32		dsk[32];     /* DES decryption subkeys */
}
des_context;

typedef struct _DES_CONTEXT_t{
		des_context		context;
		VMUCHAR			lastblock[8];
		VMUCHAR			key[8];
} DES_CONTEXT;

DES_CONTEXT *		g_des_ctx[DES_CTX_MAX];

static int  des_set_key( des_context *ctx, uint8 key[8] );
static void des_encrypt( des_context *ctx, uint8 input[8], uint8 output[8] );
static void des_decrypt( des_context *ctx, uint8 input[8], uint8 output[8] );

static VMINT	SearchForSlot( DES_CONTEXT ** pPoints, VMINT max );

static void		InitIV( VMDESHANDLE handle );

static uint32 SB1[64] =
{
    0x01010400, 0x00000000, 0x00010000, 0x01010404,
    0x01010004, 0x00010404, 0x00000004, 0x00010000,
    0x00000400, 0x01010400, 0x01010404, 0x00000400,
    0x01000404, 0x01010004, 0x01000000, 0x00000004,
    0x00000404, 0x01000400, 0x01000400, 0x00010400,
    0x00010400, 0x01010000, 0x01010000, 0x01000404,
    0x00010004, 0x01000004, 0x01000004, 0x00010004,
    0x00000000, 0x00000404, 0x00010404, 0x01000000,
    0x00010000, 0x01010404, 0x00000004, 0x01010000,
    0x01010400, 0x01000000, 0x01000000, 0x00000400,
    0x01010004, 0x00010000, 0x00010400, 0x01000004,
    0x00000400, 0x00000004, 0x01000404, 0x00010404,
    0x01010404, 0x00010004, 0x01010000, 0x01000404,
    0x01000004, 0x00000404, 0x00010404, 0x01010400,
    0x00000404, 0x01000400, 0x01000400, 0x00000000,
    0x00010004, 0x00010400, 0x00000000, 0x01010004
};

static uint32 SB2[64] =
{
    0x80108020, 0x80008000, 0x00008000, 0x00108020,
    0x00100000, 0x00000020, 0x80100020, 0x80008020,
    0x80000020, 0x80108020, 0x80108000, 0x80000000,
    0x80008000, 0x00100000, 0x00000020, 0x80100020,
    0x00108000, 0x00100020, 0x80008020, 0x00000000,
    0x80000000, 0x00008000, 0x00108020, 0x80100000,
    0x00100020, 0x80000020, 0x00000000, 0x00108000,
    0x00008020, 0x80108000, 0x80100000, 0x00008020,
    0x00000000, 0x00108020, 0x80100020, 0x00100000,
    0x80008020, 0x80100000, 0x80108000, 0x00008000,
    0x80100000, 0x80008000, 0x00000020, 0x80108020,
    0x00108020, 0x00000020, 0x00008000, 0x80000000,
    0x00008020, 0x80108000, 0x00100000, 0x80000020,
    0x00100020, 0x80008020, 0x80000020, 0x00100020,
    0x00108000, 0x00000000, 0x80008000, 0x00008020,
    0x80000000, 0x80100020, 0x80108020, 0x00108000
};

static uint32 SB3[64] =
{
    0x00000208, 0x08020200, 0x00000000, 0x08020008,
    0x08000200, 0x00000000, 0x00020208, 0x08000200,
    0x00020008, 0x08000008, 0x08000008, 0x00020000,
    0x08020208, 0x00020008, 0x08020000, 0x00000208,
    0x08000000, 0x00000008, 0x08020200, 0x00000200,
    0x00020200, 0x08020000, 0x08020008, 0x00020208,
    0x08000208, 0x00020200, 0x00020000, 0x08000208,
    0x00000008, 0x08020208, 0x00000200, 0x08000000,
    0x08020200, 0x08000000, 0x00020008, 0x00000208,
    0x00020000, 0x08020200, 0x08000200, 0x00000000,
    0x00000200, 0x00020008, 0x08020208, 0x08000200,
    0x08000008, 0x00000200, 0x00000000, 0x08020008,
    0x08000208, 0x00020000, 0x08000000, 0x08020208,
    0x00000008, 0x00020208, 0x00020200, 0x08000008,
    0x08020000, 0x08000208, 0x00000208, 0x08020000,
    0x00020208, 0x00000008, 0x08020008, 0x00020200
};

static uint32 SB4[64] =
{
    0x00802001, 0x00002081, 0x00002081, 0x00000080,
    0x00802080, 0x00800081, 0x00800001, 0x00002001,
    0x00000000, 0x00802000, 0x00802000, 0x00802081,
    0x00000081, 0x00000000, 0x00800080, 0x00800001,
    0x00000001, 0x00002000, 0x00800000, 0x00802001,
    0x00000080, 0x00800000, 0x00002001, 0x00002080,
    0x00800081, 0x00000001, 0x00002080, 0x00800080,
    0x00002000, 0x00802080, 0x00802081, 0x00000081,
    0x00800080, 0x00800001, 0x00802000, 0x00802081,
    0x00000081, 0x00000000, 0x00000000, 0x00802000,
    0x00002080, 0x00800080, 0x00800081, 0x00000001,
    0x00802001, 0x00002081, 0x00002081, 0x00000080,
    0x00802081, 0x00000081, 0x00000001, 0x00002000,
    0x00800001, 0x00002001, 0x00802080, 0x00800081,
    0x00002001, 0x00002080, 0x00800000, 0x00802001,
    0x00000080, 0x00800000, 0x00002000, 0x00802080
};

static uint32 SB5[64] =
{
    0x00000100, 0x02080100, 0x02080000, 0x42000100,
    0x00080000, 0x00000100, 0x40000000, 0x02080000,
    0x40080100, 0x00080000, 0x02000100, 0x40080100,
    0x42000100, 0x42080000, 0x00080100, 0x40000000,
    0x02000000, 0x40080000, 0x40080000, 0x00000000,
    0x40000100, 0x42080100, 0x42080100, 0x02000100,
    0x42080000, 0x40000100, 0x00000000, 0x42000000,
    0x02080100, 0x02000000, 0x42000000, 0x00080100,
    0x00080000, 0x42000100, 0x00000100, 0x02000000,
    0x40000000, 0x02080000, 0x42000100, 0x40080100,
    0x02000100, 0x40000000, 0x42080000, 0x02080100,
    0x40080100, 0x00000100, 0x02000000, 0x42080000,
    0x42080100, 0x00080100, 0x42000000, 0x42080100,
    0x02080000, 0x00000000, 0x40080000, 0x42000000,
    0x00080100, 0x02000100, 0x40000100, 0x00080000,
    0x00000000, 0x40080000, 0x02080100, 0x40000100
};

static uint32 SB6[64] =
{
    0x20000010, 0x20400000, 0x00004000, 0x20404010,
    0x20400000, 0x00000010, 0x20404010, 0x00400000,
    0x20004000, 0x00404010, 0x00400000, 0x20000010,
    0x00400010, 0x20004000, 0x20000000, 0x00004010,
    0x00000000, 0x00400010, 0x20004010, 0x00004000,
    0x00404000, 0x20004010, 0x00000010, 0x20400010,
    0x20400010, 0x00000000, 0x00404010, 0x20404000,
    0x00004010, 0x00404000, 0x20404000, 0x20000000,
    0x20004000, 0x00000010, 0x20400010, 0x00404000,
    0x20404010, 0x00400000, 0x00004010, 0x20000010,
    0x00400000, 0x20004000, 0x20000000, 0x00004010,
    0x20000010, 0x20404010, 0x00404000, 0x20400000,
    0x00404010, 0x20404000, 0x00000000, 0x20400010,
    0x00000010, 0x00004000, 0x20400000, 0x00404010,
    0x00004000, 0x00400010, 0x20004010, 0x00000000,
    0x20404000, 0x20000000, 0x00400010, 0x20004010
};

static uint32 SB7[64] =
{
    0x00200000, 0x04200002, 0x04000802, 0x00000000,
    0x00000800, 0x04000802, 0x00200802, 0x04200800,
    0x04200802, 0x00200000, 0x00000000, 0x04000002,
    0x00000002, 0x04000000, 0x04200002, 0x00000802,
    0x04000800, 0x00200802, 0x00200002, 0x04000800,
    0x04000002, 0x04200000, 0x04200800, 0x00200002,
    0x04200000, 0x00000800, 0x00000802, 0x04200802,
    0x00200800, 0x00000002, 0x04000000, 0x00200800,
    0x04000000, 0x00200800, 0x00200000, 0x04000802,
    0x04000802, 0x04200002, 0x04200002, 0x00000002,
    0x00200002, 0x04000000, 0x04000800, 0x00200000,
    0x04200800, 0x00000802, 0x00200802, 0x04200800,
    0x00000802, 0x04000002, 0x04200802, 0x04200000,
    0x00200800, 0x00000000, 0x00000002, 0x04200802,
    0x00000000, 0x00200802, 0x04200000, 0x00000800,
    0x04000002, 0x04000800, 0x00000800, 0x00200002
};

static uint32 SB8[64] =
{
    0x10001040, 0x00001000, 0x00040000, 0x10041040,
    0x10000000, 0x10001040, 0x00000040, 0x10000000,
    0x00040040, 0x10040000, 0x10041040, 0x00041000,
    0x10041000, 0x00041040, 0x00001000, 0x00000040,
    0x10040000, 0x10000040, 0x10001000, 0x00001040,
    0x00041000, 0x00040040, 0x10040040, 0x10041000,
    0x00001040, 0x00000000, 0x00000000, 0x10040040,
    0x10000040, 0x10001000, 0x00041040, 0x00040000,
    0x00041040, 0x00040000, 0x10041000, 0x00001000,
    0x00000040, 0x10040040, 0x00001000, 0x00041040,
    0x10001000, 0x00000040, 0x10000040, 0x10040000,
    0x10040040, 0x10000000, 0x00040000, 0x10001040,
    0x00000000, 0x10041040, 0x00040040, 0x10000040,
    0x10040000, 0x10001000, 0x10001040, 0x00000000,
    0x10041040, 0x00041000, 0x00041000, 0x00001040,
    0x00001040, 0x00040040, 0x10000000, 0x10041000
};

/* PC1: left and right halves bit-swap */

static uint32 LHs[16] =
{
    0x00000000, 0x00000001, 0x00000100, 0x00000101,
    0x00010000, 0x00010001, 0x00010100, 0x00010101,
    0x01000000, 0x01000001, 0x01000100, 0x01000101,
    0x01010000, 0x01010001, 0x01010100, 0x01010101
};

static uint32 RHs[16] =
{
    0x00000000, 0x01000000, 0x00010000, 0x01010000,
    0x00000100, 0x01000100, 0x00010100, 0x01010100,
    0x00000001, 0x01000001, 0x00010001, 0x01010001,
    0x00000101, 0x01000101, 0x00010101, 0x01010101,
};


//static des_context *	desctx;

//static VMUCHAR			des_cur_key[8];

/* platform-independant 32-bit integer manipulation macros */

#define GET_UINT32(n,b,i)                       \
{                                               \
    (n) = ( (uint32) (b)[(i)    ] << 24 )       \
        | ( (uint32) (b)[(i) + 1] << 16 )       \
        | ( (uint32) (b)[(i) + 2] <<  8 )       \
        | ( (uint32) (b)[(i) + 3]       );      \
}

#define PUT_UINT32(n,b,i)                       \
{                                               \
    (b)[(i)    ] = (uint8) ( (n) >> 24 );       \
    (b)[(i) + 1] = (uint8) ( (n) >> 16 );       \
    (b)[(i) + 2] = (uint8) ( (n) >>  8 );       \
    (b)[(i) + 3] = (uint8) ( (n)       );       \
}

/* Initial Permutation macro */

#define DES_IP(X,Y)                                             \
{                                                               \
    T = ((X >>  4) ^ Y) & 0x0F0F0F0F; Y ^= T; X ^= (T <<  4);   \
    T = ((X >> 16) ^ Y) & 0x0000FFFF; Y ^= T; X ^= (T << 16);   \
    T = ((Y >>  2) ^ X) & 0x33333333; X ^= T; Y ^= (T <<  2);   \
    T = ((Y >>  8) ^ X) & 0x00FF00FF; X ^= T; Y ^= (T <<  8);   \
    Y = ((Y << 1) | (Y >> 31)) & 0xFFFFFFFF;                    \
    T = (X ^ Y) & 0xAAAAAAAA; Y ^= T; X ^= T;                   \
    X = ((X << 1) | (X >> 31)) & 0xFFFFFFFF;                    \
}

/* Final Permutation macro */

#define DES_FP(X,Y)                                             \
{                                                               \
    X = ((X << 31) | (X >> 1)) & 0xFFFFFFFF;                    \
    T = (X ^ Y) & 0xAAAAAAAA; X ^= T; Y ^= T;                   \
    Y = ((Y << 31) | (Y >> 1)) & 0xFFFFFFFF;                    \
    T = ((Y >>  8) ^ X) & 0x00FF00FF; X ^= T; Y ^= (T <<  8);   \
    T = ((Y >>  2) ^ X) & 0x33333333; X ^= T; Y ^= (T <<  2);   \
    T = ((X >> 16) ^ Y) & 0x0000FFFF; Y ^= T; X ^= (T << 16);   \
    T = ((X >>  4) ^ Y) & 0x0F0F0F0F; Y ^= T; X ^= (T <<  4);   \
}

/* DES round macro */

#define DES_ROUND(X,Y)                          \
{                                               \
    T = *SK++ ^ X;                              \
    Y ^= SB8[ (T      ) & 0x3F ] ^              \
         SB6[ (T >>  8) & 0x3F ] ^              \
         SB4[ (T >> 16) & 0x3F ] ^              \
         SB2[ (T >> 24) & 0x3F ];               \
                                                \
    T = *SK++ ^ ((X << 28) | (X >> 4));         \
    Y ^= SB7[ (T      ) & 0x3F ] ^              \
         SB5[ (T >>  8) & 0x3F ] ^              \
         SB3[ (T >> 16) & 0x3F ] ^              \
         SB1[ (T >> 24) & 0x3F ];               \
}

/* DES key schedule */

static int des_main_ks( uint32 SK[32], uint8 key[8] )
{
    int i;
    uint32 X, Y, T;

    GET_UINT32( X, key, 0 );
    GET_UINT32( Y, key, 4 );

    /* Permuted Choice 1 */

    T =  ((Y >>  4) ^ X) & 0x0F0F0F0F;  X ^= T; Y ^= (T <<  4);
    T =  ((Y      ) ^ X) & 0x10101010;  X ^= T; Y ^= (T      );

    X =   (LHs[ (X      ) & 0xF] << 3) | (LHs[ (X >>  8) & 0xF ] << 2)
        | (LHs[ (X >> 16) & 0xF] << 1) | (LHs[ (X >> 24) & 0xF ]     )
        | (LHs[ (X >>  5) & 0xF] << 7) | (LHs[ (X >> 13) & 0xF ] << 6)
        | (LHs[ (X >> 21) & 0xF] << 5) | (LHs[ (X >> 29) & 0xF ] << 4);

    Y =   (RHs[ (Y >>  1) & 0xF] << 3) | (RHs[ (Y >>  9) & 0xF ] << 2)
        | (RHs[ (Y >> 17) & 0xF] << 1) | (RHs[ (Y >> 25) & 0xF ]     )
        | (RHs[ (Y >>  4) & 0xF] << 7) | (RHs[ (Y >> 12) & 0xF ] << 6)
        | (RHs[ (Y >> 20) & 0xF] << 5) | (RHs[ (Y >> 28) & 0xF ] << 4);

    X &= 0x0FFFFFFF;
    Y &= 0x0FFFFFFF;

    /* calculate subkeys */

    for( i = 0; i < 16; i++ )
    {
        if( i < 2 || i == 8 || i == 15 )
        {
            X = ((X <<  1) | (X >> 27)) & 0x0FFFFFFF;
            Y = ((Y <<  1) | (Y >> 27)) & 0x0FFFFFFF;
        }
        else
        {
            X = ((X <<  2) | (X >> 26)) & 0x0FFFFFFF;
            Y = ((Y <<  2) | (Y >> 26)) & 0x0FFFFFFF;
        }

        *SK++ =   ((X <<  4) & 0x24000000) | ((X << 28) & 0x10000000)
                | ((X << 14) & 0x08000000) | ((X << 18) & 0x02080000)
                | ((X <<  6) & 0x01000000) | ((X <<  9) & 0x00200000)
                | ((X >>  1) & 0x00100000) | ((X << 10) & 0x00040000)
                | ((X <<  2) & 0x00020000) | ((X >> 10) & 0x00010000)
                | ((Y >> 13) & 0x00002000) | ((Y >>  4) & 0x00001000)
                | ((Y <<  6) & 0x00000800) | ((Y >>  1) & 0x00000400)
                | ((Y >> 14) & 0x00000200) | ((Y      ) & 0x00000100)
                | ((Y >>  5) & 0x00000020) | ((Y >> 10) & 0x00000010)
                | ((Y >>  3) & 0x00000008) | ((Y >> 18) & 0x00000004)
                | ((Y >> 26) & 0x00000002) | ((Y >> 24) & 0x00000001);

        *SK++ =   ((X << 15) & 0x20000000) | ((X << 17) & 0x10000000)
                | ((X << 10) & 0x08000000) | ((X << 22) & 0x04000000)
                | ((X >>  2) & 0x02000000) | ((X <<  1) & 0x01000000)
                | ((X << 16) & 0x00200000) | ((X << 11) & 0x00100000)
                | ((X <<  3) & 0x00080000) | ((X >>  6) & 0x00040000)
                | ((X << 15) & 0x00020000) | ((X >>  4) & 0x00010000)
                | ((Y >>  2) & 0x00002000) | ((Y <<  8) & 0x00001000)
                | ((Y >> 14) & 0x00000808) | ((Y >>  9) & 0x00000400)
                | ((Y      ) & 0x00000200) | ((Y <<  7) & 0x00000100)
                | ((Y >>  7) & 0x00000020) | ((Y >>  3) & 0x00000011)
                | ((Y <<  2) & 0x00000004) | ((Y >> 21) & 0x00000002);
    }

    return( 0 );
}

static int des_set_key( des_context *ctx, uint8 key[8] )
{
    int i;

    /* setup encryption subkeys */

    des_main_ks( ctx->esk, key );

    /* setup decryption subkeys */

    for( i = 0; i < 32; i += 2 )
    {
        ctx->dsk[i    ] = ctx->esk[30 - i];
        ctx->dsk[i + 1] = ctx->esk[31 - i];
    }

    return( 0 );
}

/* DES 64-bit block encryption/decryption */

static void des_crypt( uint32 SK[32], uint8 input[8], uint8 output[8] )
{
    uint32 X, Y, T;

    GET_UINT32( X, input, 0 );
    GET_UINT32( Y, input, 4 );

    DES_IP( X, Y );

    DES_ROUND( Y, X );  DES_ROUND( X, Y );
    DES_ROUND( Y, X );  DES_ROUND( X, Y );
    DES_ROUND( Y, X );  DES_ROUND( X, Y );
    DES_ROUND( Y, X );  DES_ROUND( X, Y );
    DES_ROUND( Y, X );  DES_ROUND( X, Y );
    DES_ROUND( Y, X );  DES_ROUND( X, Y );
    DES_ROUND( Y, X );  DES_ROUND( X, Y );
    DES_ROUND( Y, X );  DES_ROUND( X, Y );

    DES_FP( Y, X );

    PUT_UINT32( Y, output, 0 );
    PUT_UINT32( X, output, 4 );
}

static void des_encrypt( des_context *ctx, uint8 input[8], uint8 output[8] )
{
    des_crypt( ctx->esk, input, output );
}

static void des_decrypt( des_context *ctx, uint8 input[8], uint8 output[8] )
{
    des_crypt( ctx->dsk, input, output );
}

VMDESHANDLE vm_des_set_key( VMUINT8 key[8] )
{
	VMINT		iSlot;

	if( key == NULL )
		return DES_INVALID_HANDLE;

	iSlot = SearchForSlot( g_des_ctx, DES_CTX_MAX );
	if( iSlot < 0 )
		return DES_INVALID_HANDLE;

	g_des_ctx[iSlot] = (DES_CONTEXT *)vm_malloc( sizeof(DES_CONTEXT) );
	
	if( g_des_ctx[iSlot] )
	{
		memset( g_des_ctx[iSlot], 0x00, sizeof(DES_CONTEXT) );
		memcpy( &(g_des_ctx[iSlot]->key), key, 8 );

		InitIV( iSlot );

		return des_set_key( &(g_des_ctx[iSlot]->context), key );
	}
	else
		return -1;
}

VMUINT8 * vm_des_encrypt( VMDESHANDLE handle, VMUINT8 * input, VMINT input_len, VMINT * output_len )
{
	VMINT	len = input_len;
	VMUINT8 * output = NULL, * outorg = NULL;

	if( input == NULL || output_len == NULL || input_len == 0 )
		return NULL;

	if( handle<0 || handle>DES_CTX_MAX || g_des_ctx[handle] == NULL )
		return NULL;

	output = (VMUINT8 *)vm_malloc( (input_len/8 + 1) * 8 );
	if( output == NULL )
		return NULL;

	outorg = output;

	while( len >= 0 )
	{
		VMUINT8		in[DES_BLOCK_SIZE], out[DES_BLOCK_SIZE];

		memset( in, 0x00, DES_BLOCK_SIZE );
		memset( out, 0x00, DES_BLOCK_SIZE );

		if( len<8 )
		{
			memcpy( in, input, len );

			//using PKCS5 padding
			memset( in+len, (VMUCHAR)(8-len), 8-len );
		}
		else
			memcpy( in, input, DES_BLOCK_SIZE );

		//for mode handleing; only ecb in this version
		{
			VMINT	m = 0;

			for( ; m<8; m++ )
				in[m] = in[m] ^ g_des_ctx[handle]->lastblock[m];
		}

		//encrypt a block 64bits
		des_encrypt( &(g_des_ctx[handle]->context), in, out );

		memcpy( output, out, DES_BLOCK_SIZE );

		output += DES_BLOCK_SIZE;
		input += DES_BLOCK_SIZE;
		len -= DES_BLOCK_SIZE;

		{
			VMINT	m = 0;

			for( ; m<8; m++ )
				g_des_ctx[handle]->lastblock[m] = out[m];
		}

		//des_set_key( &(g_des_ctx[handle]->context), g_des_ctx[handle]->key );
	}

	*output_len = (input_len/8 + 1) * 8;

	return outorg;
}

VMUINT8 * vm_des_decrypt( VMDESHANDLE handle, VMUINT8 * input, VMINT input_len, VMINT * output_len )
{
	VMINT	len = input_len;
	VMUINT8 * output = NULL, * outorg = NULL;

	if( input == NULL || output_len == NULL || input_len == 0 )
		return NULL;

	if( handle<0 || handle>DES_CTX_MAX || g_des_ctx[handle] == NULL )
		return NULL;

	output = (VMUINT8 *)vm_malloc( input_len );
	if( output == NULL )
		return NULL;

	outorg = output;

	while( len > 0 )
	{
		VMUINT8		in[DES_BLOCK_SIZE], out[DES_BLOCK_SIZE];

		memset( in, 0x00, DES_BLOCK_SIZE );
		memset( out, 0x00, DES_BLOCK_SIZE );

		if( len<8 )
			memcpy( in, input, len );
		else
			memcpy( in, input, DES_BLOCK_SIZE );

		//encrypt a block 64bits
		des_decrypt( &(g_des_ctx[handle]->context), in, out );

		//for mode handleing; only ecb in this version
		{
			VMINT	m = 0;

			for( ; m<8; m++ )
				out[m] = out[m] ^ g_des_ctx[handle]->lastblock[m];
		}

		memcpy( output, out, DES_BLOCK_SIZE );

		output += DES_BLOCK_SIZE;
		input += DES_BLOCK_SIZE;
		len -= DES_BLOCK_SIZE;

		{
			VMINT	m = 0;

			for( ; m<8; m++ )
				g_des_ctx[handle]->lastblock[m] = in[m];
		}
	}

	//delete PKCS5 padding
	{
		VMINT		m = 0; 
		VMUCHAR		pad[8], padch = *(output-1);

		memset( pad, padch, 8 );

		if( !memcmp( output-(VMINT)padch, pad, (VMINT)padch ) )
				*output_len = input_len-(VMINT)padch;
		else
		{
			if(outorg != NULL)
			{
					vm_free( outorg );	
					outorg = NULL;
			}
			return NULL;
		}
	}

	return outorg;
}

VMINT vm_des_reset_key( VMDESHANDLE handle )
{
	if( handle<0 || handle>DES_CTX_MAX || g_des_ctx[handle] == NULL )
		return DES_INVALID_HANDLE;

	vm_free( g_des_ctx[handle] );
	g_des_ctx[handle] = NULL;

	return DES_OK;
}

static VMINT	SearchForSlot( DES_CONTEXT ** pPoints, VMINT max )
{
	VMINT		i = 0;

	for( ; i<max; i++ )
	{
		if( pPoints[i] == NULL )
			return i;
	}

	return -1;
}

static void InitIV( VMDESHANDLE handle )
{
	VMUCHAR *		keystring = g_des_ctx[handle]->key, * ivstring = g_des_ctx[handle]->lastblock;
	VMINT			i = 1;

	if( handle<0 || handle>DES_CTX_MAX || g_des_ctx[handle] == NULL )
		return;
	
	memcpy( ivstring, keystring, 8 );
}

#else /*Version control*/

#include "vmdes.h"
#include "che_api.h"
#include "vmlog.h"
#include "vmmem.h"
#define		DES_CTX_MAX		2


typedef struct _DES_CONTEXT_t{
		STCHE  		 che_str;
		VMUCHAR			key[8];
} DES_CONTEXT;

DES_CONTEXT *		g_des_ctx[DES_CTX_MAX];

static VMINT	SearchForSlot( DES_CONTEXT ** pPoints, VMINT max );


/*
//test
extern void vm_print_array_hex(VMUINT8* enc, VMUINT ptrlen);
void vm_print_array_hex(VMUINT8* enc, VMUINT ptrlen)
{	
	VMINT i=0;
	for(i=0;i<ptrlen;i=(i+10))
	{
		kal_prompt_trace(MOD_IDLE,"  %02x,%02x,%02x,%02x,%02x,%02x,%02x,%02x%02x,%02x   ",enc[i],enc[i+1],enc[i+2],enc[i+3],enc[i+4],enc[i+5],enc[i+6],enc[i+7],enc[i+8],enc[i+9]);	
		vm_log_warn("   0x%02x,0x%02x,0x%02x,0x%02x,0x%02x,0x%02x,0x%02x,0x%02x,0x%02x,0x%02x  ",enc[i],enc[i+1],enc[i+2],enc[i+3],enc[i+4],enc[i+5],enc[i+6],enc[i+7],enc[i+8],enc[i+9]);	
	}

}
void vm_init_array_hex(VMUINT8* enc, VMUINT ptrlen,VMUINT value)
{	
	VMINT i=0;
	for(i=0;i<ptrlen;i++)
	{
		enc[i]=value;
	}

}	
*/

VMDESHANDLE vm_des_set_key( VMUINT8 key[8] )
{
	VMINT		iSlot;

	//vm_log_warn(" vm_des_set_key.....");
	if( key == NULL )
	{
		//vm_log_warn(" key==NULL");
		return DES_INVALID_HANDLE;
	}
	iSlot = SearchForSlot( g_des_ctx, DES_CTX_MAX );

	//vm_log_warn(" iSlot:%d",iSlot);
	
	if( iSlot < 0 )
		return DES_INVALID_HANDLE;

	//g_des_ctx[iSlot] = (DES_CONTEXT *)vm_calloc( sizeof(DES_CONTEXT) );
	g_des_ctx[iSlot] = (DES_CONTEXT *)_vm_kernel_calloc( sizeof(DES_CONTEXT) );
	
	if( g_des_ctx[iSlot] )
	{
		//vm_log_warn(" g_des_ctx[iSlot]  is not NULL");
		//memset( g_des_ctx[iSlot], 0x00, sizeof(DES_CONTEXT) );
		memcpy( &(g_des_ctx[iSlot]->key), key, 8 );

		che_init(&(g_des_ctx[iSlot]->che_str), CHE_DES);
		che_set_iv(&(g_des_ctx[iSlot]->che_str), g_des_ctx[iSlot]->key, 8);

		che_key_action(&(g_des_ctx[iSlot]->che_str), CHE_SET_KEY, g_des_ctx[iSlot]->key, 8);
		return iSlot;
	}
	else{
		//vm_log_warn(" g_des_ctx[iSlot] is NULL",iSlot);
		return -1;
	}
}

VMUINT8 * vm_des_encrypt( VMDESHANDLE handle, VMUINT8 * input, VMINT input_len, VMINT * output_len )
{
	VMUINT8 * output = NULL,*temp_input=NULL;

	//vm_log_warn(" vm_des_encrypt........");
	if( input == NULL || output_len == NULL || input_len == 0 )
		return NULL;

	if( handle<0 || handle>DES_CTX_MAX || g_des_ctx[handle] == NULL )
		return NULL;

	output = (VMUINT8 *)vm_calloc( (input_len/8 + 2) * 8 );//预留8字节保护
	if( output == NULL ){
		//vm_log_warn(" output is  NULL");
		return NULL;
	}


	//保证传入input是4字节对齐，如不是4字节对齐，使用vm_calloc分配一份
	if (((VMUINT)input)&3)
	{
		temp_input = (VMUINT8 *)vm_calloc(input_len );
		if( temp_input == NULL ){
			vm_log_warn(" temp_input is  NULL");
			return NULL;
		}
		memcpy(temp_input,input,input_len);
	}else
	 	temp_input=input;	
	//vm_log_warn(" temp_input:%p...input:%p..(VMUINT)input:%u.",temp_input,input,(VMUINT)input);
	
	che_process(&(g_des_ctx[handle]->che_str), CHE_DES,  CHE_CBC/*CHE_ECB*/, CHE_ENC, temp_input, output, input_len, KAL_TRUE);	
	*output_len = (input_len/8 + 1) * 8;
/*
	vm_log_warn("---------after che_process---");
	vm_log_warn("---------print input---input_len:%d---------",input_len);
	vm_print_array_hex(input,input_len);
	vm_log_warn("---------print temp_input---:%d---------",input_len);
	vm_print_array_hex(temp_input,input_len);

	vm_log_warn("---------print output--,*output_len+16:%d----",*output_len+8);
	vm_print_array_hex(output,*output_len+8);
*/
	if  ((((VMUINT)input)&3) && (temp_input))
	{
		vm_free(temp_input);
		temp_input=NULL;
	}
	
	return output;
}

VMUINT8 * vm_des_decrypt( VMDESHANDLE handle, VMUINT8 * input, VMINT input_len, VMINT * output_len )
{
	VMUINT8 * output = NULL;

	if( input == NULL || output_len == NULL || input_len == 0 )
		return NULL;

	if( handle<0 || handle>DES_CTX_MAX || g_des_ctx[handle] == NULL )
		return NULL;

	output = (VMUINT8 *)vm_calloc( (input_len/8 + 2) * 8 );//8 字节对齐再加8/16字节保护(che_process CHE_DEC会修改output中input_len长度后8个字节值)
	if( output == NULL ){
		vm_log_warn(" output is  NULL");
		return NULL;
		}


	che_process(&(g_des_ctx[handle]->che_str), CHE_DES,  CHE_CBC/*CHE_ECB*/, CHE_DEC, input, output, input_len, KAL_TRUE);


	//vm_log_warn("---------print input---input_len:%d---------",input_len);
	//vm_print_array_hex(input,input_len);
	//vm_log_warn("---------print che_process------");
	//vm_log_warn("---------print output------");
	//vm_print_array_hex(output,input_len);
	//vm_log_warn(" input_len:%d",input_len);
	
	//delete PKCS5 padding
	{
		VMUCHAR		pad[8], padch = *(output+input_len-1);

		memset( pad, padch, 8 );
		
		if( !memcmp( output+input_len-(VMINT)padch, pad, (VMINT)padch ) )
			{
				vm_log_warn("( !memcmp( output+input_len-(VMINT)padch, pad, (VMINT)padch ) )");
				*output_len = input_len-(VMINT)padch;

			}	
		else
		{
			vm_log_warn("Delete padding WRONG.................");
			//vm_log_warn("PKCS5 padding COMPARE.... 0x%02x,0x%02x,0x%02x,0x%02x,0x%02x,0x%02x,0x%02x",output[input_len-(VMINT)padch],output[input_len-(VMINT)padch+1],output[input_len-(VMINT)padch+2],output[input_len-(VMINT)padch+3],
			//					output[input_len-(VMINT)padch+4],output[input_len-(VMINT)padch+5],output[input_len-(VMINT)padch+6],output[input_len-(VMINT)padch+7]);
			vm_free( output );

			return NULL;
		}
	}
	//vm_log_warn("  input_len:%d, *output_len :%d",input_len,*output_len );

	return output;
}

VMINT vm_des_reset_key( VMDESHANDLE handle )
{
	//vm_log_warn("---------print vm_des_reset_key------");
	if( handle<0 || handle>DES_CTX_MAX || g_des_ctx[handle] == NULL )
		return DES_INVALID_HANDLE;

	che_deinit(&(g_des_ctx[handle]->che_str));	
	

	//vm_free( g_des_ctx[handle] );
	_vm_kernel_free(g_des_ctx[handle]);
	g_des_ctx[handle] = NULL;


	return DES_OK;
}

static VMINT	SearchForSlot( DES_CONTEXT ** pPoints, VMINT max )
{
	VMINT		i = 0;

	//vm_log_warn(" SearchForSlot......");
	for( ; i<max; i++ )
	{
		if( pPoints[i] == NULL )
			return i;
	}
	return -1;
}

#endif /*Version control*/

#endif /*__VRE__*/
