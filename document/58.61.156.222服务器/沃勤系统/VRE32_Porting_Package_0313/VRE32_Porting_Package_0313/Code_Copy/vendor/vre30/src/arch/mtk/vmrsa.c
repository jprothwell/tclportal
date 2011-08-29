#ifdef __VRE__

#if defined(__VRE_RB_08A__) || defined(__VRE_RB_08B__) /*Version control*/
#include "vmpkcs.h"
#include "vmlog.h"//ltz
#include "vmrsa.h"
#include "vmcerter.h"

#include "vmbn.h"

static VMINT	rsa_encode( VMUCHAR * signature, VMINT sign_len, VMKey * key, VMUCHAR * text, VMINT * text_len );

static void		InvertBuf( VMUCHAR * buf, VMINT buf_len );

static 	VMPUBKey	pub;
static 	VMPRIKey	pri;


VMINT vm_rsa_verify( VMUCHAR * signature, VMINT sign_len, VMPUBKey * pubkey, VMUCHAR * text, VMINT * text_len )
{
	VMUCHAR *	buf = NULL;
	VMINT		buf_len = 0, res_code = 0, content_len = 0;

	//alloc memory for receiving decoded data
	//vm_log_fatal("vm_rsa_verify : buf = (VMUCHAR *)vm_malloc start");
	buf = (VMUCHAR *)vm_malloc((int)( KEY_LEN * sizeof(VMUCHAR) ));
	//vm_log_fatal("vm_rsa_verify : buf = (VMUCHAR *)vm_malloc end");
	if( buf == NULL )
		return -1;

	buf_len = KEY_LEN;

	res_code = rsa_encode( signature, sign_len, (VMKey *)pubkey, buf, &buf_len );
	if( res_code < 0 )
	{
		vm_free( buf );

		return res_code;
	}

	//vm_log_fatal( "encode OK, buf_len=%d", buf_len );

	InvertBuf( buf, buf_len );

	//catch the content without padding
	content_len = vm_check_pkcs_padding( text, *text_len, buf, buf_len );
	//vm_log_fatal( "check padding: %d", content_len );
	if( content_len )
		*text_len = content_len;
/*	else
		res_code = -2;*/
	else
	{
		*text_len = buf_len;
		
		memcpy( text, buf, buf_len );
	}	

	vm_free( buf );

	//vm_log_fatal( " finish the rsa verification" ); 

	return res_code;
}


VMINT vm_rsa_verify_by_id( VMUCHAR * signature, VMINT sign_len, VMINT id, VMUCHAR * text, VMINT * text_len )
{
	//vm_log_fatal( "verify_by_id start to get key" );
	
	switch( vm_ce_get_key( id, (VMKey *)&pub ) )
	{
		case VM_CE_GET_KEY_EXPIRED:
			return VM_CE_RSA_KEY_EXPIRED;
		case VM_CE_GET_KEY_OK:
			break;
		default:
			return VM_CE_RSA_GET_KEY_ERROR;
	}

	//vm_log_fatal( "catched key & start to verify" );

	return vm_rsa_verify( signature, sign_len, (VMKey *)&pub, text, text_len );
}

VMINT vm_rsa_sign( VMUCHAR * signature, VMINT sign_len, VMPRIKey * prikey, VMUCHAR * text, VMINT * text_len, VMINT type )
{
	VMUCHAR *	buf = NULL;
	VMINT		buf_len = 0, res_code = 0, content_len = 0;

	//alloc memory for receiving decoded data
	buf = (VMUCHAR *)vm_malloc( KEY_LEN * sizeof(VMUCHAR) );
	if( buf == NULL )
		return -1;

	memset( buf, 0x00, KEY_LEN );

	res_code = vm_add_pkcs_padding( buf, KEY_LEN, signature, sign_len, type );
	if( res_code != PKCS_PADDING_OK )
	{
		vm_free( buf );
		return -1;
	}

	res_code = rsa_encode( buf, KEY_LEN, (VMKey *)prikey, text, text_len );

	InvertBuf( text, *text_len );

	vm_free( buf );

	return res_code;

	//return rsa_encode( signature, sign_len, (VMKey *)prikey, text, text_len );
}


VMINT vm_rsa_sign_by_id( VMUCHAR * signature, VMINT sign_len, VMINT id, VMUCHAR * text, VMINT * text_len, VMINT type )
{
	if( vm_ce_get_key( id, (VMKey *)&pri ) < 0 )
		return -1;

	return vm_rsa_sign( signature, sign_len, (VMKey *)&pri, text, text_len, type );	
}


static VMINT	rsa_encode( VMUCHAR * signature, VMINT sign_len, VMKey * key, VMUCHAR * text, VMINT * text_len )
{
	VMINT			i = 0, buf_len = 0;
	VA_BN_CTX			*ctx=NULL;
	VA_BN_MONT_CTX		*mode_ctx = NULL;
	VABIGNUM	*		bn[VM_RSA_BN_INDEX_TOTAL];

	vm_log_debug( "verify -- checking params" );			
	
	if( signature == NULL || sign_len == 0 || key == NULL )
		return -1;
		
	if( key->modlen == 0 || key->keylen == 0 )
		return -1;
		
	if( text == NULL || text_len == NULL || *text_len == 0 )
		return -1;

	for( ; i<VM_RSA_BN_INDEX_TOTAL; i++ )
		bn[i] = NULL;

	vm_log_debug( "verify -- start to verify" );

	//vm_log_fatal( "VA_BN_CTX_new" );

	ctx=VA_BN_CTX_new();
	if( ctx == NULL )
		return -2;

	//vm_log_fatal( "VA_BN_CTX_start" );

	VA_BN_CTX_start(ctx);

	//vm_log_fatal( "VA_BN_CTX_get" );	

	//initial the bn list
	for( i=0; i<VM_RSA_BN_INDEX_TOTAL; i++ )
		bn[i] = VA_BN_CTX_get(ctx);

	//vm_log_fatal( "VA_BN_CTX_end" );	

	for( i=0; i<VM_RSA_BN_INDEX_TOTAL; i++ )
	{
		if( bn[i] == NULL )
		{
			VA_BN_CTX_end(ctx);
			VA_BN_CTX_free(ctx);

			return -2;
		}
	}

	//vm_log_fatal( "VA_BN_bin2bn" );	

	VA_BN_bin2bn( key->mod, key->modlen, bn[VM_RSA_BN_INDEX_MOD] );
	VA_BN_bin2bn( key->key, key->keylen, bn[VM_RSA_BN_INDEX_KEY] );
	VA_BN_bin2bn( signature, sign_len, bn[VM_RSA_BN_INDEX_IN] );	

	//vm_log_fatal( "VA_BN_MONT_CTX_set_locked" );

	VA_BN_MONT_CTX_set_locked( &mode_ctx, 1, bn[VM_RSA_BN_INDEX_MOD], ctx );

	//vm_log_fatal( "VA_BN_mod_exp_mont" );

	VA_BN_mod_exp_mont( bn[VM_RSA_BN_INDEX_RES], bn[VM_RSA_BN_INDEX_IN], bn[VM_RSA_BN_INDEX_KEY], 
						bn[VM_RSA_BN_INDEX_MOD], ctx, mode_ctx );


	//read the result
	*text_len = (bn[VM_RSA_BN_INDEX_RES]->top)*sizeof(int);

	memcpy( text, (unsigned char *)(bn[VM_RSA_BN_INDEX_RES]->d), *text_len );

	//vm_log_fatal( "VA_BN_MONT_CTX_free" );

	VA_BN_MONT_CTX_free( mode_ctx );	

	//vm_log_fatal( "VA_BN_CTX_end" );
	
	VA_BN_CTX_end(ctx);

	//vm_log_fatal( "VA_BN_CTX_free" );
	
	VA_BN_CTX_free(ctx);

	

	return 0;
}

static void InvertBuf( VMUCHAR * buf, VMINT buf_len )
{
	VMUCHAR *			buf_back = NULL;
	VMINT				i = 0;

	buf_back = (VMUCHAR *)vm_malloc( buf_len * sizeof(VMUCHAR *) );
	if( buf_back == NULL )
		return;

	for( ; i<buf_len; i++ )
		buf_back[i] = *(buf+buf_len-1-i);

	memcpy( buf, buf_back, buf_len );

	vm_free( buf_back );
}

#else /*Version control*/

#include "che_api.h"

#include "vmrsa.h"
#include "vmcerter.h"
#include "vmcervar.h"

static STCHE   che_str;

static 	VMPUBKey	pub;
static 	VMPRIKey	pri;

static VMINT	rsa_encode( VMUCHAR * signature, VMINT sign_len, VMKey * key, VMUCHAR * text, VMINT * text_len );
static VMINT	rsa_decode( VMUCHAR * signature, VMINT sign_len, VMKey * key, VMUCHAR * text, VMINT * text_len );

/*
//test
static void vm_print_array_hex(VMUINT8* enc, VMUINT ptrlen)
{	
	VMINT i=0;
	for(i=0;i<ptrlen;i=(i+10))
	{
		kal_prompt_trace(MOD_IDLE,"  %02x,%02x,%02x,%02x,%02x,%02x,%02x,%02x%02x,%02x   ",enc[i],enc[i+1],enc[i+2],enc[i+3],enc[i+4],enc[i+5],enc[i+6],enc[i+7],enc[i+8],enc[i+9]);	
		vm_log_warn("   0x%02x,0x%02x,0x%02x,0x%02x,0x%02x,0x%02x,0x%02x,0x%02x,0x%02x,0x%02x  ",enc[i],enc[i+1],enc[i+2],enc[i+3],enc[i+4],enc[i+5],enc[i+6],enc[i+7],enc[i+8],enc[i+9]);	
	}

}
*/

VMINT vm_rsa_verify( VMUCHAR * signature, VMINT sign_len, VMPUBKey * pubkey, VMUCHAR * text, VMINT * text_len )
{
	VMINT		 res_code = 0;

	res_code = rsa_decode( signature, sign_len, (VMKey *)pubkey, text, text_len );

/*
	vm_log_warn("---------print signature---sign_len:%d---------",sign_len);
	vm_print_array_hex(signature,sign_len);
	vm_log_warn("---------print pubkey->mod----pubkey->modlen:%d-------",pubkey->modlen);
	vm_print_array_hex(pubkey->mod,pubkey->modlen);
	vm_log_warn("---------print pubkey->key---pubkey->keylen:%d-----",pubkey->keylen);
	vm_print_array_hex(pubkey->key,pubkey->keylen);
	vm_log_warn("---------print text----*text_len:%d--res_code:%d-----",*text_len,res_code);
	vm_print_array_hex(text,*text_len);
*/	

	return res_code;
}


VMINT vm_rsa_verify_by_id( VMUCHAR * signature, VMINT sign_len, VMINT id, VMUCHAR * text, VMINT * text_len )
{
	//vm_log_fatal( "verify_by_id start to get key" );
	
	switch( vm_ce_get_key( id, (VMKey *)&pub ) )
	{
		case VM_CE_GET_KEY_EXPIRED:
			return VM_CE_RSA_KEY_EXPIRED;
		case VM_CE_GET_KEY_OK:
			break;
		default:
			return VM_CE_RSA_GET_KEY_ERROR;
	}

	//vm_log_fatal( "catched key & start to verify" );
	return vm_rsa_verify( signature, sign_len, (VMKey *)&pub, text, text_len );
}

VMINT vm_rsa_sign( VMUCHAR * signature, VMINT sign_len, VMPRIKey * prikey, VMUCHAR * text, VMINT * text_len, VMINT type )
{
	
	VMINT		res_code = 0;
	
	res_code=rsa_encode( signature, sign_len, (VMKey *)prikey, text, text_len );

/*
	vm_log_warn("---------print signature---sign_len:%d---------",sign_len);
	vm_print_array_hex(signature,sign_len);
	vm_log_warn("---------print prikey->mod----prikey->modlen:%d-------",prikey->modlen);
	vm_print_array_hex(prikey->mod,prikey->modlen);
	vm_log_warn("---------print prikey->key---prikey->keylen:%d-----",prikey->keylen);
	vm_print_array_hex(prikey->key,prikey->keylen);
	vm_log_warn("---------print text----*text_len:%d--res_code:%d-----",*text_len,res_code);
	vm_print_array_hex(text,*text_len);
*/	
	
	return res_code;

}


VMINT vm_rsa_sign_by_id( VMUCHAR * signature, VMINT sign_len, VMINT id, VMUCHAR * text, VMINT * text_len, VMINT type )
{
	if( vm_ce_get_key( id, (VMKey *)&pri ) < 0 )
		return -1;

	return vm_rsa_sign( signature, sign_len, (VMKey *)&pri, text, text_len, type );	
}


static VMINT	rsa_encode( VMUCHAR * signature, VMINT sign_len, VMKey * key, VMUCHAR * text, VMINT * text_len )
{
	
	
	if( signature == NULL || sign_len == 0 || key == NULL )
		return -1;
		
	if( key->modlen == 0 || key->keylen == 0 )
		return -1;
		
	if( text == NULL || text_len == NULL )
		return -1;

	che_init(&che_str,CHE_RSA);
	che_key_action(&che_str, CHE_SET_RSA_N, key->mod, key->modlen);
   	che_key_action(&che_str, CHE_SET_RSA_E, key->key,key->keylen );//3
   	che_rsa_public_encrypt(&che_str, signature, sign_len, text, (VMUINT*)text_len, CHE_RSA_PKCS1_V15);
	
    	che_deinit(&che_str);	
	return 0;
	
}


static VMINT	rsa_decode( VMUCHAR * signature, VMINT sign_len, VMKey * key, VMUCHAR * text, VMINT * text_len )
{		

	if( signature == NULL || sign_len == 0 || key == NULL )
		return -1;
		
	if( key->modlen == 0 || key->keylen == 0 )
		return -1;
		
	if( text == NULL || text_len == NULL )
		return -1;

	che_init(&che_str,CHE_RSA);
	che_key_action(&che_str, CHE_SET_RSA_N, key->mod, key->modlen);
	
	che_key_action(&che_str, CHE_SET_RSA_E, key->key,key->keylen);
	che_rsa_public_decrypt(&che_str, signature, sign_len, text, (VMUINT*)text_len,CHE_RSA_PKCS1_V15 );

	che_deinit(&che_str);
		return 0;
}

#endif /*Version control*/

#endif /*__VRE__*/
