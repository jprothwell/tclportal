#ifndef _VM_CERT_ERR_
#define	_VM_CERT_ERR_

#define	VM_CE_CHECK_PARAM_OK			(0)

#define	VM_CE_OP_OK						(0)

#define	VM_CE_OP_FAIL						(-1)

//result code of vm_ce_verify_app
enum{
	VM_CE_VERITY_INSUFFICIENT_SYS_MEM = -15,
	VM_CE_VERIFY_KEY_EXPIRED = -14, //fail to invoke the check func
	VM_CE_CHECK_PARAM_FAIL = -13, //fail to invoke the check func

	VM_PER_MEM_ERROR = -12,
	VM_PER_INIT_ERROR, //can not initial permission system
	VM_PER_CATCH_ERROR, //compose func list error
	
	VM_CE_VERIFY_RESOLUTION_DISMATCH, // the lcd size is smalled than the app requirements
	VM_CE_VERIFY_INSUFFICIENT_MEM, // the system can not provide enough memory to run the app
	VM_CE_VERIFY_TIMESTAMP_ERROR, 
	VM_CE_VERIFY_IMSI_DISMATCH, // the app is personal used and the user is not matched 
	VM_CE_VERIFY_APP_BANNED, //the app is banned 
	VM_CE_VERIFY_DIGEST_DISMATCH, // the verify result is not matched with the desired one
	VM_CE_VERIFY_VERIFY_FAILED, //can not finish the verification with the assigned pub key
	VM_CE_VERIFY_BAD_DIGEST, //can not caculate app & cert digest
	
	VM_CE_VERIFY_BAD_PARAM, //can not catch the Cert envelope structure OR can not catch the digest string OR
													//any of the points to CertID, AppID, IssueData and ExpiredData is NULL
											
		
	VM_CE_VERIFY_OK // verify finished and the app is OK to run
};


//result code of vm_ce_read_cert
enum{
	VM_CE_READ_CERT_LOAD_SIGN_ERROR = -7, // can not load the signature
	VM_CE_READ_CERT_READ_CERT_ERROR, // can not read the cert
	VM_CE_READ_CERT_TAG_ERROR, // the tag is incorrect
	VM_CE_READ_CERT_TAG_READ_ERROR, // can not read the desired tag
	VM_CE_READ_CERT_MEM_ERROR, // fail to allocate the memory for Cert structure
	VM_CE_READ_CERT_FILE_OP_ERROR, // can not operate the file correctly
	VM_CE_READ_CERT_BAD_PARAM, // can not catch the file handle or the Cert structure buffer is already allocated
	
	VM_CE_READ_CERT_OK
};


//result code of vm_ce_first_field
enum{
	VM_CE_FIRST_FIELD_DIGEST_MEM_ERROR = -4, //fail to allocate the memory for digest caculation
	VM_CE_FIRST_FIELD_DIGEST_IN_USE, //the digest is in use now
	VM_CE_FIRST_FIELD_FILE_OP_ERROR, // can not operate the file correctly
	VM_CE_FIRST_FIELD_BAD_PARAM, //can not catch the valid file handle
	
	VM_CE_FIRST_FIELD_OK
};


//result code of vm_ce_next_field
enum{
	VM_CE_NEXT_FIELD_BAD_PARAM = -1, //can not catch the valid file handle
	
	VM_CE_NEXT_FIELD_OK
};


//result code of vm_ce_read_type
enum{
	VM_CE_READ_TYPE_FILE_READ_ERROR = -2, //can not read the file correctly
	VM_CE_READ_TYPE_BAD_PARAM, //can not catch the valid file handle OR digest buffer is invalid
	
	VM_CE_READ_TYPE_OK
};


//result code of vm_ce_read_vaule
enum{
	VM_CE_READ_VALUE_FILE_READ_ERROR = -3, //can not read the file correctly
	VM_CE_READ_VALUE_INVALID_BUF, // the buffer to catch the value is NULL or insufficient
	VM_CE_READ_VALUE_BAD_PARAM, //can not catch the valid file handle OR digest buffer is invalid
	
	VM_CE_READ_VALUE_OK
};


//result code of vm_ce_get_cert_digest
enum{
	VM_CE_CERT_DIG_BAD_PARAM = -1, //can not catch the valid file handle OR digest buffer is invalid
	
	VM_CE_CERT_DIG_OK
};


//result code of vm_ce_get_key
enum{
	VM_CE_GET_KEY_EXPIRED = -3, //the matched key is expired
	VM_CE_GET_KEY_NOT_FOUND, //can not find the key with the desired id
	VM_CE_GET_KEY_BAD_PARAM, //can not catch the valid key storage OR the output buf is NULL
	
	VM_CE_GET_KEY_OK
};


//result code of vm_ce_load_var
enum{
	VM_CE_LOAD_VAR_TIME_ERROR = -5, // time checking error
	VM_CE_LOAD_VAR_LIST_ERROR, // can not load ban list
	VM_CE_LOAD_VAR_KEY_ERROR, // can not load the pub keys
	VM_CE_LOAD_VAR_MEM_ERROR, //can not allocate mem for key storage
	VM_CE_LOAD_VAR_IN_USE, // the memory for key storage is in use
	
	VM_CE_LOAD_VAR_OK
};


//result code of RSA module
enum{
	VM_CE_RSA_KEY_EXPIRED = -5, //fail to invoke the check func
	VM_CE_RSA_CREATE_ERROR = -4, // fail to generate new number
	VM_CE_RSA_CTX_ERROR, // fail to set context
	VM_CE_RSA_PARAM_ERROR, // invalid parameters
	VM_CE_RSA_GET_KEY_ERROR, // can not get the specified key
	
	VM_CE_RSA_OK
};


enum{
	VM_CE_CHECK_BAN_LIST_PARAM_ERROR = -2,
	VM_CE_CHECK_BAN_LIST_NVRAM_ERROR,
	VM_CE_CHECK_BAN_LIST_OK
};

#endif
