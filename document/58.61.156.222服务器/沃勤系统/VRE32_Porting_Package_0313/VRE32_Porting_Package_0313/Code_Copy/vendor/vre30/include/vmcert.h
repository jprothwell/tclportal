#ifndef _VM_CERT_MANAGER_
#define	_VM_CERT_MANAGER_

#include "vmsys.h"

#include "vmcerter.h"

//#ifdef	CERT_1024
//#	define	RSA_LEN						128
//#else //512 bit
#define	RSA_LEN						64
//#endif

#define	DIG_MD5_LEN				16
#define	DIG_SHA_LEN				20

#define	DIG_MAX_LEN				DIG_SHA_LEN
#define	DIG_MIN_LEN				DIG_MD5_LEN

#define		CERT_HEAD_LEN				6

#define		CERT_DIGEST_TYPE_MD5		1
#define		CERT_DIGEST_TYPE_SHA		2

#define		CERT_DIGEST_LEN				64

#define		ISD_APP_NUM						-1

#define		RESERVED_BYTES_NUM				8

//define the types of extended info in a cert
enum{
	VM_CE_INFO_END = 0,//终止符
	VM_CE_INFO_DEV,//应用开发商名称
	VM_CE_INFO_APP_ID,//应用程序编号
	VM_CE_INFO_CERT_ID,//证书公钥编号
	VM_CE_INFO_NAME,//应用程序名称
	VM_CE_INFO_VER,//应用程序版本，采用x.y.z 命名方法
	VM_CE_INFO_ISSUE,//证书发放日期
	VM_CE_INFO_EXPIRED,//证书过期日期
	VM_CE_INFO_PAY,//计费信息
	VM_CE_INFO_PAY_NODE,//收费点
	VM_CE_INFO_PRICE,//价格
	VM_CE_INFO_PAY_MODE,//计费模式
	VM_CE_INFO_PAY_PARAM,//计费参数
	VM_CE_INFO_APP_USE,//自定义序号
	VM_CE_INFO_PAY_CHANNEL,//代收费通道号
	VM_CE_INFO_MEM_REQ,//运行程序必须的内存容量
	VM_CE_INFO_RESOLUTION_REQ,//运行程序所需的屏幕分辨率
	VM_CE_INFO_PLAT_REQ,//运行程序所需的最低平台版本号
	VM_CE_INFO_IMSI,
	VM_CE_INFO_PERMISSION,//程序允许使用的系统接口
	VM_CE_INFO_TRIAL,
	VM_CE_INFO_COMPILER,
	VM_CE_INFO_INPUT_MODE,
	VM_CE_INFO_DESC,
	VM_CE_INFO_SUPPORT_BG_RUN,	// 是否支持后运行.
	
	//add by han wei
	VM_CE_INFO_NAME_LIST, //程序名（列表，分语言类型）
	VM_CE_INFO_DESC_LIST, //运营说明（列表，分语言类型）
	VM_CE_INFO_ZIMO_LIST, //程序名字模（列表，分语言类型）

	VM_CE_INFO_TOTAL
};

//added by han wei for new interface in VRE 30
#define		VM_CE_INFO_LIST_START		VM_CE_INFO_NAME_LIST
#define		VM_CE_INFO_LIST_END			VM_CE_INFO_ZIMO_LIST


//define the Cert envelop head
typedef struct _VRECertHead{
//		VMUCHAR		tag[6];
		VMINT		digestype;

		VMUCHAR		signature[RSA_LEN];
		VMINT		offset;

		VMUCHAR		reserve[RESERVED_BYTES_NUM];
} VRECertHead;


typedef struct _VRECertExtHead{
		VMINT		type;
		VMINT		len;
} VRECertExtHead;


typedef vm_time_t	VRECertTime;

typedef VMINT (* VM_CE_PARAM_CHECK_FUNC)( VMINT tag, void * Cert_ptr );

typedef struct _VRECert{
//		VRECertHead *	head;
		VMUCHAR *								digest;
		VMINT										diglen;

		VMINT										digesttype;

		VMUCHAR *								ptr[VM_CE_INFO_TOTAL];
		VMINT										len[VM_CE_INFO_TOTAL];
		
		VM_CE_PARAM_CHECK_FUNC	checkfunc[VM_CE_INFO_TOTAL];
} VRECert;

#endif
