#if (defined(__VRE_RB_08A__) || defined(__VRE_RB_08B__))
#include "vmsys.h"
#include "vmpkcs.h"

static VMINT vm_add_PKCS_type_one( VMUCHAR * to, VMINT tlen, VMUCHAR * from, VMINT flen );
static VMINT vm_check_PKCS_type_one( VMUCHAR * to, VMINT tlen, VMUCHAR * from, VMINT flen );

static VMINT vm_add_PKCS_type_two( VMUCHAR * to, VMINT tlen, VMUCHAR * from, VMINT flen );
static VMINT vm_check_PKCS_type_two( VMUCHAR * to, VMINT tlen, VMUCHAR * from, VMINT flen );

static VMINT vm_check_type( VMUCHAR * src, VMINT len );


VMINT vm_add_pkcs_padding( VMUCHAR * to, VMINT tlen, VMUCHAR * from, VMINT flen, VMINT type )
{
	switch( type )
	{
		case PUB_PADDING:
			return vm_add_PKCS_type_two( to, tlen, from, flen );

		case PRI_PADDING:
			return vm_add_PKCS_type_one( to, tlen, from, flen );
	}

	return 0;
}

VMINT vm_check_pkcs_padding( VMUCHAR * to, VMINT tlen, VMUCHAR * from, VMINT flen )
{
	VMINT	type = 0;

	type = vm_check_type( from, flen );

	switch( type )
	{
		case PUB_PADDING:
			return vm_check_PKCS_type_one( to, tlen, from, flen );
			
		case PRI_PADDING:
			return vm_check_PKCS_type_two( to, tlen, from, flen );

		default:
			return PADDING_TYPE_ERROR;
	}
	
	return 0;
}


static VMINT vm_add_PKCS_type_one( VMUCHAR * to, VMINT tlen, VMUCHAR * from, VMINT flen )
{
	VMINT		j;
	VMUCHAR *	p;

	if (flen > (tlen-RSA_PKCS_PADDING_SIZE))
		return 0;
	
	p = to;

	*(p++) = 0;
	*(p++) = 1; /* Private Key BT (Block Type) */

	/* pad out with 0xff data */
	j = tlen-3-flen;
	memset( p, 0xff, j );
	p += j;
	*(p++) = '\0';
	memcpy( p, from, flen );

	return 1;
}

static VMINT vm_check_PKCS_type_one( VMUCHAR * to, VMINT tlen, VMUCHAR * from, VMINT flen )
{
	VMINT		i, j;
	VMUCHAR *	p;

	p = from;
	if( *p != 0 || *(++p) != 0x01 )
		return 0;

	p++;

	/* scan over padding data */
	j = flen-1; /* one for type. */
	for( i=0; i<j; i++ )
	{
		if( *p != 0xff )
		{
			if( *p == 0 )
			{ 
				p++; 
				break; 
			}
			else
				return 0;
		}

		p++;
	}

	if (i == j)
		return 0;

	if (i < 8)
		return 0;
	
	i++; /* Skip over the '\0' */
	j -= i+1;


	if (j > tlen)
		return 0;
	
	memcpy( to, p, j );

	return j;
	
	return 0;
}


static VMINT vm_add_PKCS_type_two( VMUCHAR * to, VMINT tlen, VMUCHAR * from, VMINT flen )
{
	VMINT		i,j;
	VMUCHAR *	p;
	
	if (flen > (tlen-11))
		return 0;
	
	p = to;

	*(p++) = 0;
	*(p++) = 2; /* Public Key BT (Block Type) */

	/* pad out with non-zero random data */
	j = tlen-3-flen;

	//memcpy( p, TYPE_2_PADDING_RANDOM_STRING, j );
	memset( p, 'V', j );
	p += j;

	*(p++) = '\0';

	memcpy( p, from, flen );

	return 1;
}

static VMINT vm_check_PKCS_type_two( VMUCHAR * to, VMINT tlen, VMUCHAR * from, VMINT flen )
{
	VMINT		i,j;
	VMUCHAR *	p;

	p = from;
	if( *p != 0 || *(++p) != 0x02 )
		return 0;

	p++;

	/* scan over padding data */
	j=flen-1; /* one for type. */
	for (i=0; i<j; i++)
	{
		if( *(p++) == 0 ) 
			break;
	}

	if (i == j)
		return 0;

	if (i < 8)
		return 0;

	i++; /* Skip over the '\0' */
	j -= i+1;
	if( j > tlen )
		return 0;

	if( tlen < j )
		return 0;

	memcpy( to, p, j );

	return j;
	
	return 0;
}


static VMINT vm_check_type( VMUCHAR * src, VMINT len )
{
	if( len < RSA_PKCS_PADDING_SIZE )
		return PADDING_TYPE_ERROR;

	if( *src == 0x00 )
	{
		switch( *(src+1) )
		{
			case PUB_PADDING:
			case PRI_PADDING:
				return *(src+1);

			default:
				return PADDING_TYPE_ERROR;
		}
	}
	else
		return PADDING_TYPE_ERROR;
}

#endif