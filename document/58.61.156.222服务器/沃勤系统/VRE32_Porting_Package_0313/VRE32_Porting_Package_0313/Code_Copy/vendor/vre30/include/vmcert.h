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
	VM_CE_INFO_END = 0,//��ֹ��
	VM_CE_INFO_DEV,//Ӧ�ÿ���������
	VM_CE_INFO_APP_ID,//Ӧ�ó�����
	VM_CE_INFO_CERT_ID,//֤�鹫Կ���
	VM_CE_INFO_NAME,//Ӧ�ó�������
	VM_CE_INFO_VER,//Ӧ�ó���汾������x.y.z ��������
	VM_CE_INFO_ISSUE,//֤�鷢������
	VM_CE_INFO_EXPIRED,//֤���������
	VM_CE_INFO_PAY,//�Ʒ���Ϣ
	VM_CE_INFO_PAY_NODE,//�շѵ�
	VM_CE_INFO_PRICE,//�۸�
	VM_CE_INFO_PAY_MODE,//�Ʒ�ģʽ
	VM_CE_INFO_PAY_PARAM,//�ƷѲ���
	VM_CE_INFO_APP_USE,//�Զ������
	VM_CE_INFO_PAY_CHANNEL,//���շ�ͨ����
	VM_CE_INFO_MEM_REQ,//���г��������ڴ�����
	VM_CE_INFO_RESOLUTION_REQ,//���г����������Ļ�ֱ���
	VM_CE_INFO_PLAT_REQ,//���г�����������ƽ̨�汾��
	VM_CE_INFO_IMSI,
	VM_CE_INFO_PERMISSION,//��������ʹ�õ�ϵͳ�ӿ�
	VM_CE_INFO_TRIAL,
	VM_CE_INFO_COMPILER,
	VM_CE_INFO_INPUT_MODE,
	VM_CE_INFO_DESC,
	VM_CE_INFO_SUPPORT_BG_RUN,	// �Ƿ�֧�ֺ�����.
	
	//add by han wei
	VM_CE_INFO_NAME_LIST, //���������б����������ͣ�
	VM_CE_INFO_DESC_LIST, //��Ӫ˵�����б����������ͣ�
	VM_CE_INFO_ZIMO_LIST, //��������ģ���б����������ͣ�

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
