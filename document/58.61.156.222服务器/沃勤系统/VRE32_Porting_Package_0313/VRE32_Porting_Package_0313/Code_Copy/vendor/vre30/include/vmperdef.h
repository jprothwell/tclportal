#ifndef		_VM_PER_DEF_
#define		_VM_PER_DEF_


//declare the funcs


//define the permission id

#define		PER_BASE		5000

#define		PER_OP_OK		0
#define		PER_OP_FAIL	-1

enum{
	PER_PARAM_ERROR = -4,
	PER_APP_ERROR,
	PER_MERGE_ERROR
};

enum{
/*	PER_AUDIO_PLAY = PER_BASE,
	PER_BITSTREAM,
	PER_CALL_OUT,
	PER_CAMERA,
	PER_CONTACT,
	//PER_EXECUTE,
	PER_FILE,
	PER_HTTP,
	PER_LBS,
	PER_MMS,
	PER_NVRAM,
	PER_PRO,
	PER_SECU,
	PER_SENSOR,
	//PER_SHEME,
	PER_SIM,
	PER_SMS_PER,
	PER_SMS_SP,
	PER_SMS_MNG,
	PER_TCP,
	PER_VIDEO,
	PER_XML,	*/
	PER_AUDIO_PLAY = PER_BASE,
	PER_CALL_OUT,
	PER_CAMERA,
	PER_FILE,
	PER_HTTP,
	PER_RECORD,
	PER_SENSOR,
	PER_SIM,
	PER_SMS_PER,
	PER_SMS_SP,
	PER_TCP,
	PER_APPSTORE,
	
	PER_BILLING,
	PER_BITSTREAM,
	PER_CONTACT,
	PER_LBS,
	PER_MMS,
	PER_PRO,
	PER_SMSMNG,
	PER_VIDEO,
	PER_XML,

	PER_TOTAL
};


//define the counter of sections that need remap
#define		REMAP_SECTION_NUM			2

#endif
