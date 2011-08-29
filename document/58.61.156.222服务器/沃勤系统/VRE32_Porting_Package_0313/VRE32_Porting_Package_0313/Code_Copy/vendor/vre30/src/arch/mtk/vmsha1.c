#ifdef __VRE__

#if (defined(__VRE_RB_08A__) || defined(__VRE_RB_08B__)) /*Version control*/
#include "vmsha1.h"

/*
 *  Define the circular shift macro
 */
#define SHA1CircularShift(bits,word) \
                ((((word) << (bits)) & 0xFFFFFFFF) | \
                ((word) >> (32-(bits))))

/* Function prototypes */
//void SHA1ProcessMessageBlock(SHA1Context *);
static void SHA1ProcessMessageBlock( SHA1Context * context );
static void SHA1PadMessage(SHA1Context * context );

/*  
 *  SHA1Reset
 *
 *  Description:
 *      This function will initialize the SHA1Context in preparation
 *      for computing a new message digest.
 *
 *  Parameters:
 *      context: [in/out]
 *          The context to reset.
 *
 *  Returns:
 *      Nothing.
 *
 *  Comments:
 *
 */
void vm_sha1_reset( SHA1Context *context )
{
    context->Length_Low             = 0;
    context->Length_High            = 0;
    context->Message_Block_Index    = 0;

    context->Message_Digest[0]      = 0x67452301;
    context->Message_Digest[1]      = 0xEFCDAB89;
    context->Message_Digest[2]      = 0x98BADCFE;
    context->Message_Digest[3]      = 0x10325476;
    context->Message_Digest[4]      = 0xC3D2E1F0;

    context->Computed   = 0;
    context->Corrupted  = 0;
}

/*  
 *  SHA1Result
 *
 *  Description:
 *      This function will return the 160-bit message digest into the
 *      Message_Digest array within the SHA1Context provided
 *
 *  Parameters:
 *      context: [in/out]
 *          The context to use to calculate the SHA-1 hash.
 *
 *  Returns:
 *      1 if successful, 0 if it failed.
 *
 *  Comments:
 *
 */
VMINT vm_sha1_result( SHA1Context * context )
{

    if( context->Corrupted )
        return 0;

    if( !context->Computed )
    {
        SHA1PadMessage( context );
        context->Computed = 1;
    }

    return 1;
}

/*  
 *  SHA1Input
 *
 *  Description:
 *      This function accepts an array of octets as the next portion of
 *      the message.
 *
 *  Parameters:
 *      context: [in/out]
 *          The SHA-1 context to update
 *      message_array: [in]
 *          An array of characters representing the next portion of the
 *          message.
 *      length: [in]
 *          The length of the message in message_array
 *
 *  Returns:
 *      Nothing.
 *
 *  Comments:
 *
 */
void vm_sha1_input( SHA1Context * context, VMUINT8 * message_array, VMUINT length )
{
    if( !length )
        return;

    if( context->Computed || context->Corrupted )
    {
        context->Corrupted = 1;
        return;
    }

    while( length-- && !context->Corrupted )
    {
        context->Message_Block[context->Message_Block_Index++] =
                                                (*message_array & 0xFF);

        context->Length_Low += 8;

        /* Force it to 32 bits */
        context->Length_Low &= 0xFFFFFFFF;
        if (context->Length_Low == 0)
        {
            context->Length_High++;

            /* Force it to 32 bits */
            context->Length_High &= 0xFFFFFFFF;
            if (context->Length_High == 0)
            {
                /* Message is too long */
                context->Corrupted = 1;
            }
        }

        if (context->Message_Block_Index == 64)
            SHA1ProcessMessageBlock(context);

        message_array++;
    }
}

/*  
 *  SHA1ProcessMessageBlock
 *
 *  Description:
 *      This function will process the next 512 bits of the message
 *      stored in the Message_Block array.
 *
 *  Parameters:
 *      None.
 *
 *  Returns:
 *      Nothing.
 *
 *  Comments:
 *      Many of the variable names in the SHAContext, especially the
 *      single character names, were used because those were the names
 *      used in the publication.
 *         
 *
 */
static void SHA1ProcessMessageBlock(SHA1Context *context)
{
    VMUINT			K[] =            /* Constants defined in SHA-1   */      
							{
								0x5A827999,
								0x6ED9EBA1,
								0x8F1BBCDC,
								0xCA62C1D6
							};
    VMINT         t;                  /* Loop counter                 */
    VMUINT    temp;               /* Temporary word value         */
    VMUINT    W[80];              /* Word sequence                */
    VMUINT    A, B, C, D, E;      /* Word buffers                 */

    /*
     *  Initialize the first 16 words in the array W
     */
    for( t = 0; t < 16; t++ )
    {
        W[t] = ((VMUINT) context->Message_Block[t * 4]) << 24;
        W[t] |= ((VMUINT) context->Message_Block[t * 4 + 1]) << 16;
        W[t] |= ((VMUINT) context->Message_Block[t * 4 + 2]) << 8;
        W[t] |= ((VMUINT) context->Message_Block[t * 4 + 3]);
    }

    for(t = 16; t < 80; t++)
    {
       W[t] = SHA1CircularShift(1,W[t-3] ^ W[t-8] ^ W[t-14] ^ W[t-16]);
    }

    A = context->Message_Digest[0];
    B = context->Message_Digest[1];
    C = context->Message_Digest[2];
    D = context->Message_Digest[3];
    E = context->Message_Digest[4];

    for(t = 0; t < 20; t++)
    {
        temp =  SHA1CircularShift(5,A) +
                ((B & C) | ((~B) & D)) + E + W[t] + K[0];
        temp &= 0xFFFFFFFF;
        E = D;
        D = C;
        C = SHA1CircularShift(30,B);
        B = A;
        A = temp;
    }

    for(t = 20; t < 40; t++)
    {
        temp = SHA1CircularShift(5,A) + (B ^ C ^ D) + E + W[t] + K[1];
        temp &= 0xFFFFFFFF;
        E = D;
        D = C;
        C = SHA1CircularShift(30,B);
        B = A;
        A = temp;
    }

    for(t = 40; t < 60; t++)
    {
        temp = SHA1CircularShift(5,A) +
               ((B & C) | (B & D) | (C & D)) + E + W[t] + K[2];
        temp &= 0xFFFFFFFF;
        E = D;
        D = C;
        C = SHA1CircularShift(30,B);
        B = A;
        A = temp;
    }

    for(t = 60; t < 80; t++)
    {
        temp = SHA1CircularShift(5,A) + (B ^ C ^ D) + E + W[t] + K[3];
        temp &= 0xFFFFFFFF;
        E = D;
        D = C;
        C = SHA1CircularShift(30,B);
        B = A;
        A = temp;
    }

    context->Message_Digest[0] =
                        (context->Message_Digest[0] + A) & 0xFFFFFFFF;
    context->Message_Digest[1] =
                        (context->Message_Digest[1] + B) & 0xFFFFFFFF;
    context->Message_Digest[2] =
                        (context->Message_Digest[2] + C) & 0xFFFFFFFF;
    context->Message_Digest[3] =
                        (context->Message_Digest[3] + D) & 0xFFFFFFFF;
    context->Message_Digest[4] =
                        (context->Message_Digest[4] + E) & 0xFFFFFFFF;

    context->Message_Block_Index = 0;
}

/*  
 *  SHA1PadMessage
 *
 *  Description:
 *      According to the standard, the message must be padded to an even
 *      512 bits.  The first padding bit must be a '1'.  The last 64
 *      bits represent the length of the original message.  All bits in
 *      between should be 0.  This function will pad the message
 *      according to those rules by filling the Message_Block array
 *      accordingly.  It will also call SHA1ProcessMessageBlock()
 *      appropriately.  When it returns, it can be assumed that the
 *      message digest has been computed.
 *
 *  Parameters:
 *      context: [in/out]
 *          The context to pad
 *
 *  Returns:
 *      Nothing.
 *
 *  Comments:
 *
 */
static void SHA1PadMessage(SHA1Context *context)
{
    /*
     *  Check to see if the current message block is too small to hold
     *  the initial padding bits and length.  If so, we will pad the
     *  block, process it, and then continue padding into a second
     *  block.
     */
    if (context->Message_Block_Index > 55)
    {
        context->Message_Block[context->Message_Block_Index++] = 0x80;

        while(context->Message_Block_Index < 64)
            context->Message_Block[context->Message_Block_Index++] = 0;

        SHA1ProcessMessageBlock( context );

        while(context->Message_Block_Index < 56)
            context->Message_Block[context->Message_Block_Index++] = 0;
    }
    else
    {
        context->Message_Block[context->Message_Block_Index++] = 0x80;

        while(context->Message_Block_Index < 56)
            context->Message_Block[context->Message_Block_Index++] = 0;
    }

    /*
     *  Store the message length as the last 8 octets
     */
    context->Message_Block[56] = (context->Length_High >> 24) & 0xFF;
    context->Message_Block[57] = (context->Length_High >> 16) & 0xFF;
    context->Message_Block[58] = (context->Length_High >> 8) & 0xFF;
    context->Message_Block[59] = (context->Length_High) & 0xFF;
    context->Message_Block[60] = (context->Length_Low >> 24) & 0xFF;
    context->Message_Block[61] = (context->Length_Low >> 16) & 0xFF;
    context->Message_Block[62] = (context->Length_Low >> 8) & 0xFF;
    context->Message_Block[63] = (context->Length_Low) & 0xFF;

    SHA1ProcessMessageBlock( context );
}

VMINT _vm_reg_sha1_modual(void)
{
	return 0;
}
#else /*Version control*/

#include "che_api.h"
#include "vmsha1.h"
#include "vmsys.h"
#include "vmpromng.h"
#include "vmresmng.h"
#include "vmmod.h"
#include "vmlog.h"
#include "vmmem.h"


static void vm_sha1_mod_init(void);
static void vm_sha1_mod_finalize(void);
static VMINT vm_sha1_mod_evt_proc(VRE_MOD_LIFECIRCLE_EVT event);
static void vm_sha1_release_callback(VM_P_HANDLE process_handle, VMINT sys_state);
static STCHE   *vm_get_cheinfo_from_processid(VM_P_HANDLE processid,VMINT * res_id);
/**
 * 注册本地SHA1模块。
 *
 * @return 返回REG_VRE_MODULE_SUCCESS表示注册成功，否则返回相应的错误码。
 */
VMINT _vm_reg_sha1_modual(void)
{
	int res_code = REG_VRE_MODULE_SUCCESS;
	
	if ((res_code = _vm_reg_module("sha1", (MOD_EVT_PROCESS)vm_sha1_mod_evt_proc)) != REG_VRE_MODULE_SUCCESS)
	{
		vm_log_error("Failed to regisiter sha1 moudle. Error Code : %d", res_code);
	}

	return res_code;
}

static VMINT vm_sha1_mod_evt_proc(VRE_MOD_LIFECIRCLE_EVT event)
{
	switch(event)
	{
	case EVT_MOD_INIT:
		vm_sha1_mod_init();
		break;
	case EVT_MOD_RELEASE:
		vm_sha1_mod_finalize();
		break;
	default:
		vm_log_error("{sha1 MODULE}Receive [%d] event.", event);
	}
	return REG_VRE_MODULE_SUCCESS;
}


void vm_sha1_release_callback(VM_P_HANDLE process_handle, VMINT sys_state)
{
	//	vm_log_warn("vm_sha1_release_callback...process_handle:%d.. sys_state:%d",process_handle,sys_state);

		switch (sys_state)
		{
			case VM_PMNG_UNLOAD:
				{
					VMINT i=0,sha1_ctx_size=0;
					STCHE   *sha1_ctx_p=NULL;

					while ( (i = vm_res_findfirst(process_handle, VM_RES_TYPE_SHA1)) != VM_RES_NOT_FIND)
					{
						vm_res_get_data(VM_RES_TYPE_SHA1,i,(void**)&sha1_ctx_p,&sha1_ctx_size);
						if (sha1_ctx_p)
						{
							vm_free(sha1_ctx_p);
							sha1_ctx_p=NULL;
						}
						//vm_log_warn("vm_res_release_data....");	
						vm_res_release_data(VM_RES_TYPE_SHA1, i );
						vm_res_findclose(VM_RES_TYPE_SHA1);
					}
				}
				
				break;	
		}


}



static void vm_sha1_mod_init(void)
{	
	/*
	if (!vm_res_node_p )
	{
		if  ((vm_res_node_p=(vm_res_node_t  *)_vm_kernel_calloc(sizeof(vm_res_node_t)*vm_res_type_max_handle(VM_RES_TYPE_SHA1)))==NULL)
			vm_log_error(" malloc vm_res_node_p failed in vm_sha1_mod_init()..." );
	}
	*/
	vm_res_type_set_notify_callback(VM_RES_TYPE_SHA1,vm_sha1_release_callback);
}

static void vm_sha1_mod_finalize(void)
{
	/*
	if (vm_res_node_p)
	{
		//vm_free(vm_res_node_p);
		_vm_kernel_free(vm_res_node_p);
		vm_res_node_p=NULL;
	}
	*/
}

static STCHE   *vm_get_cheinfo_from_processid(VM_P_HANDLE processid,VMINT * res_id)
{
	vm_res_node_t   vm_res_node;

	memset(&vm_res_node,0x00,sizeof(vm_res_node_t));
	if (vm_res_get_data_list_by_proecss(processid, VM_RES_TYPE_SHA1,&vm_res_node ,1)>0)
	{
		if (res_id)
		{
			*res_id=vm_res_node.res_id;
			vm_log_warn("...vm_get_cheinfo_from_processid()....*res_id:%d.",*res_id);
		}
		return (STCHE  *)(vm_res_node.data_content);
	}
	return NULL;
	
}


void vm_sha1_reset( SHA1Context *context )
{
	VM_P_HANDLE processid=vm_pmng_get_current_handle();
	STCHE   *sha1_ctx_p=NULL;
	VMINT res_id;
	
	sha1_ctx_p=vm_get_cheinfo_from_processid(processid,&res_id);
	
	if (!sha1_ctx_p) 
	{
		//vm_log_warn("if ((!res_node) || (!sha1_ctx_p) ).....");
		if  ((sha1_ctx_p=(STCHE  *)vm_calloc(sizeof(STCHE)))==NULL)
		{
			vm_log_error(" malloc sha1_ctx_p failed in vm_sha1_reset()..." );
			return;
		}
	} 
	che_init(sha1_ctx_p, CHE_SHA1);
	//保存资源
	//vm_log_warn("...vm_sha1_reset().....sava_data...process_handle:%d.",processid);
	vm_res_save_data(VM_RES_TYPE_SHA1, (void*)(sha1_ctx_p),sizeof(STCHE), NULL,processid );
	
	memset(context->Message_Digest, 0x00, sizeof(context->Message_Digest));

}

VMINT vm_sha1_result( SHA1Context * context )
{ 
	STCHE   *sha1_ctx_p=NULL;
	VMINT res_id;
	
	sha1_ctx_p=vm_get_cheinfo_from_processid(vm_pmng_get_current_handle(),&res_id);

	if (sha1_ctx_p)
	{
		if (context)
		{
			che_process(sha1_ctx_p, CHE_SHA1, CHE_MODE_NULL, CHE_HASH, NULL, (VMUINT8*)context->Message_Digest,0, KAL_TRUE);
			che_deinit(sha1_ctx_p);
		} else
			vm_log_error(" context   is Null");
		vm_free(sha1_ctx_p);
		sha1_ctx_p=NULL;
		//释放资源
		vm_res_release_data(VM_RES_TYPE_SHA1,res_id);
		
	}	else
	{
		vm_log_error("  sha1_ctx_p  is NULL  in vm_sha1_result...");
		return 0;
	}
	
	return 1;
}
 

void vm_sha1_input( SHA1Context * context, VMUINT8 * message_array, VMUINT length )
{
	STCHE   *sha1_ctx_p=NULL;
	VMINT res_id;

	sha1_ctx_p=vm_get_cheinfo_from_processid(vm_pmng_get_current_handle(),&res_id);	
	
	if (sha1_ctx_p)
	{
		if (context && message_array )
		{
			che_process(sha1_ctx_p, CHE_SHA1, CHE_MODE_NULL, CHE_HASH, message_array, (VMUINT8*)context->Message_Digest, length, KAL_FALSE);
		} else
			vm_log_error(" context || message_array is NULL OR  (length<0)...");
	} else
		vm_log_error(" sha1_ctx_p is NULL...");

	
}

#endif /*Version control*/

#endif /*__VRE__*/