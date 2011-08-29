#ifdef __VRE__
#include "stdlib.h"
#include "string.h"
#include "vmsys.h"
#include "vmua.h"
#include "vmmd5.h"
#include "vmlog.h"
#include "vmcermng.h"
//#include "Dlmalloc.h"

#ifdef __VRE_CIPHER_UA__

extern VMUINT8 md5_des_default[32];


VMUINT8 md5_des[] = {0xF1,0x53,0x3F,0x63,0x11,0x90,0x0D,0x61,0xD6,0x08,0x60,0x2F,0x2F,0x37,0xE3,0xDF,0xE9,0xA8,0x5F,0xFA,0xB7,0x0F,0xB8,0xB3,0xC6,0x7E,0x24,0x51,0x72,0x25,0xA2,0x13};


VMUINT vm_get_useragent(VMCHAR* value, VMUINT len)
{
	VMUINT 		length = 0;
	VMUINT8* 	decrypt_ptr = NULL;
	VMINT      	output_len = 0;
	VMUINT8* 	md5_ptr = NULL;
	VMUINT8* 	ua_ptr = NULL;
	md5_state_t	md5State;
	md5_byte_t    szDigest[16];
      
	decrypt_ptr = vm_ua_decrypt_data(md5_des, sizeof(md5_des), &output_len);
	vm_log_debug("vm_get_useragent output_len = %d", output_len);

	if(decrypt_ptr == NULL)  // 解密不成功，密文有误,则解密默认密文
	{
		decrypt_ptr = vm_ua_decrypt_data(md5_des_default, sizeof(md5_des_default), &output_len);
		vm_log_debug("default vm_get_useragent output_len = %d", output_len);
	
		if(decrypt_ptr != NULL)  // 容错，防止默认密文有误!
		{	
			ua_ptr = (VMUINT8*)_vm_kernel_malloc((output_len - 15)*sizeof(VMUINT8));
			if(ua_ptr == NULL)
			{
				if(decrypt_ptr != NULL)
				{
					vm_free(decrypt_ptr);
					decrypt_ptr = NULL;
				}
				return -1;
			}
			

			md5_ptr = (VMUINT8*)_vm_kernel_malloc(17*sizeof(VMUINT8));
			if(md5_ptr == NULL)
			{
				if(decrypt_ptr != NULL)
				{
					vm_free(decrypt_ptr);
					decrypt_ptr = NULL;
				}
				if(ua_ptr != NULL)
				{
					_vm_kernel_free(ua_ptr);
					ua_ptr = NULL;
				}
				return -1;
			}
	

			memcpy(ua_ptr , decrypt_ptr, output_len - 16);
			memcpy(md5_ptr, decrypt_ptr + output_len - 16, 16);

			ua_ptr[output_len - 16] = '\0';
			md5_ptr[16] = '\0';

			vm_log_debug("vm_get_useragent ua_ptr:%s", ua_ptr);
			
			//生成MD5摘要
			md5_init(&md5State);
			md5_append(&md5State, (const md5_byte_t *)ua_ptr, sizeof(VMUINT8)*(output_len - 16));
			md5_finish(&md5State, szDigest);

			if(memcmp(md5_ptr, szDigest, 16) == 0)  // MD5摘要对比成功
			{
				vm_log_debug(" default MD5 Verification PASS!");
				vm_log_debug("vm_get_useragent ua_ptr:%s", ua_ptr);

				length = strlen((const char*)ua_ptr);
				if (length >= len)
					length = len - 1;

				strncpy(value, (const char*)ua_ptr, length);
				value[length] = '\0';

				vm_log_debug("default vm_get_useragent UA:%s", value);
				vm_log_debug("default vm_get_useragent UA length:%d", length);

				if(ua_ptr != NULL)
				{
					_vm_kernel_free(ua_ptr);
					ua_ptr = NULL;	
				}
				if(md5_ptr != NULL)
				{
					_vm_kernel_free(md5_ptr);
					md5_ptr = NULL;	
				}
				if(decrypt_ptr != NULL)
				{
					vm_free(decrypt_ptr);
					decrypt_ptr = NULL;
				}
								
				return length;
			}
			else   // MD5摘要对比失败
			{
				if(ua_ptr != NULL)
				{
					_vm_kernel_free(ua_ptr);
					ua_ptr = NULL;	
				}
				if(md5_ptr != NULL)
				{
					_vm_kernel_free(md5_ptr);
					md5_ptr = NULL;	
				}
				if(decrypt_ptr != NULL)
				{
					vm_free(decrypt_ptr);
					decrypt_ptr = NULL;
				}
				vm_log_debug("default MD5 Verification FAIL!");
				return -1;
			}
				
		}
		else // 默认密文有误
		{
			vm_log_debug("default Ciphertext Error!");
			return -1;
		}
		
	}
	else // 解密成功
	{
		ua_ptr = (VMUINT8*)_vm_kernel_malloc((output_len - 15)*sizeof(VMUINT8));
		if(ua_ptr == NULL)
		{
			if(decrypt_ptr != NULL)
			{
				vm_free(decrypt_ptr);
				decrypt_ptr = NULL;
			}
			return -1;
		}

		md5_ptr = (VMUINT8*)_vm_kernel_malloc(17*sizeof(VMUINT8));
		if(md5_ptr == NULL)
		{
			if(decrypt_ptr != NULL)
			{
				vm_free(decrypt_ptr);
				decrypt_ptr = NULL;
			}
			if(ua_ptr != NULL)
			{
				_vm_kernel_free(ua_ptr);
				ua_ptr = NULL;
			}
			return -1;
		}

		memcpy(ua_ptr , decrypt_ptr, output_len - 16);
		memcpy(md5_ptr, decrypt_ptr + output_len - 16, 16);

		ua_ptr[output_len - 16] = '\0';
		md5_ptr[16] = '\0';

		vm_log_debug("vm_get_useragent ua_ptr:%s", ua_ptr);
		
		//生成MD5摘要
		md5_init(&md5State);
		md5_append(&md5State, (const md5_byte_t *)ua_ptr, sizeof(VMUINT8)*(output_len - 16));
		md5_finish(&md5State, szDigest);

		if(memcmp(md5_ptr, szDigest, 16) == 0) // MD5摘要对比成功
		{
			vm_log_debug(" MD5 Verification PASS!");
			vm_log_debug("vm_get_useragent ua_ptr:%s", ua_ptr);
			
			length = strlen((const char*)ua_ptr);
			if (length >= len)
				length = len - 1;

			strncpy(value, (const char*)ua_ptr, length);
			value[length] = '\0';

			vm_log_debug("vm_get_useragent UA:%s", value);
			vm_log_debug("vm_get_useragent UA length:%d", length);

			if(ua_ptr != NULL)
			{
				_vm_kernel_free(ua_ptr);
				ua_ptr = NULL;	
			}
			if(md5_ptr != NULL)
			{
				_vm_kernel_free(md5_ptr);
				md5_ptr = NULL;	
			}
			if(decrypt_ptr != NULL)
			{
				vm_free(decrypt_ptr);
				decrypt_ptr = NULL;
			}
			
			return length;
		}
		else   // MD5摘要对比失败，则调用默认密文
		{	
			if(decrypt_ptr != NULL)
			{
				vm_free(decrypt_ptr);
				decrypt_ptr = NULL;
			}

			decrypt_ptr = vm_ua_decrypt_data(md5_des_default, sizeof(md5_des_default), &output_len);
			vm_log_debug("default2 vm_get_useragent output_len = %d", output_len);

			if(decrypt_ptr != NULL)  // 解密默认密文成功
			{	
				ua_ptr = (VMUINT8*)_vm_kernel_malloc((output_len - 15)*sizeof(VMUINT8));
				if(ua_ptr == NULL)
				{
					if(decrypt_ptr != NULL)
					{
						vm_free(decrypt_ptr);
						decrypt_ptr = NULL;
					}
					return -1;
				}
				
				md5_ptr = (VMUINT8*)_vm_kernel_malloc(17*sizeof(VMUINT8));
				if(md5_ptr == NULL)
				{
					if(decrypt_ptr != NULL)
					{
						vm_free(decrypt_ptr);
						decrypt_ptr = NULL;
					}
					if(ua_ptr != NULL)
					{
						_vm_kernel_free(ua_ptr);
						ua_ptr = NULL;
					}
					return -1;
				}

				memcpy(ua_ptr , decrypt_ptr, output_len - 16);
				memcpy(md5_ptr, decrypt_ptr + output_len - 16, 16);

				ua_ptr[output_len - 16] = '\0';
				md5_ptr[16] = '\0';

				vm_log_debug("vm_get_useragent ua_ptr:%s", ua_ptr);
				
				//生成MD5摘要
				md5_init(&md5State);
				md5_append(&md5State, (const md5_byte_t *)ua_ptr, sizeof(VMUINT8)*(output_len - 16));
				md5_finish(&md5State, szDigest);

				if(memcmp(md5_ptr, szDigest, 16) == 0)
				{
					vm_log_debug(" default2 MD5 Verification PASS!");
					vm_log_debug("vm_get_useragent ua_ptr:%s", ua_ptr);
					
					length = strlen((const char*)ua_ptr);
					if (length >= len)
						length = len - 1;

					strncpy(value, (const char*)ua_ptr, length);
					value[length] = '\0';

					vm_log_debug("default2 vm_get_useragent UA:%s", value);
					vm_log_debug("default2 vm_get_useragent UA length:%d", length);

					if(ua_ptr != NULL)
					{
						_vm_kernel_free(ua_ptr);
						ua_ptr = NULL;	
					}
					if(md5_ptr != NULL)
					{
						_vm_kernel_free(md5_ptr);
						md5_ptr = NULL;	
					}
					if(decrypt_ptr != NULL)
					{
						vm_free(decrypt_ptr);
						decrypt_ptr = NULL;
					}
						
					return length;
				}
				else
				{
					if(ua_ptr != NULL)
					{
						_vm_kernel_free(ua_ptr);
						ua_ptr = NULL;	
					}
					if(md5_ptr != NULL)
					{
						_vm_kernel_free(md5_ptr);
						md5_ptr = NULL;	
					}
					if(decrypt_ptr != NULL)
					{
						vm_free(decrypt_ptr);
						decrypt_ptr = NULL;
					}
					vm_log_debug("default2 MD5 Verification FAIL!");
					return -1;
				}
					
			}
			else
			{
				vm_log_debug("default2 Ciphertext Error!");
				return -1;
			}
		
	   }
		
    }
		
}

#else /* __VRE_CIPHER_UA__ */

VMUINT vm_get_useragent(VMCHAR* value, VMUINT len)
{
	VMUINT length = 0;
	length = strlen(VRE_SYS_USER_AGENT);
	if (length >= len)
		length = len - 1;
	strncpy(value, VRE_SYS_USER_AGENT, length);
	value[length] = '\0';
	//vm_log_debug("UA:%s",value);
	return length;
}

#endif /* __VRE_CIPHER_UA__ */


VMUINT vm_get_host_version(VMCHAR* value, VMUINT len)
{
	VMUINT length = 18;
			if (length >= len)
				length = len - 1;
#ifdef MT6225 
	strncpy(value, "MT6225_09A_VERSION", length);
#else
  #ifdef MT6235
  			strncpy(value, "MT6235_09A_VERSION", length);
  #else
    #ifdef MT6238
			strncpy(value, "MT6238_09A_VERSION", length);
    #else
			#ifdef MT6253
					strncpy(value, "MT6253_09A_VERSION", length);
			#else
					#ifdef MT6225B
						strncpy(value, "MT6225B_09A_VERSION", length);
					#else
						#ifdef MT6235B
							strncpy(value, "MT6235B_09A_VERSION", length);
						#else				
							strncpy(value, "MT6225_09A_VERSION", length);
						#endif
					#endif
	    #endif
    #endif
  #endif
#endif
			value[length] = '\0';
	//vm_log_debug("host version:%s",value);
	return length;
}
#endif
