
#ifndef LOGIC_NET_H
#define LOGIC_NET_H
#include "MMIDataType.h"
//#include "global_define.h"

#ifdef __cplusplus 
extern "C" {
#endif

#define  AM_NET_OK					    0			//�ɹ�
#define  AM_NET_ERR					-1			//ʧ��
#define  AM_NET_ERR1					-2			//Ӧ���ظ�����
#define  AM_NET_ERR2					-3			//��Ʒ��ϸ��Ϣ������汾


#define MAX_LEN_APP_NAME		24
#define MAX_LEN_APP_INTRO		200
#define MAX_LEN_APP_VERSIONID	22
#define MAX_LEN_CP_NAME			16
#define MAX_LEN_TIME			12
#define MAX_LEN_FILE_NAME		260
#define MAX_LEN_VERSION			20


#define  APPLIST_MORE_LIST_ID                1
#define  APPLIST_TOP_LIST_ID                 2
#define  APPLIST_NEW_LIST_ID                 3
#define  APPLIST_RECOM_LIST_ID               4

typedef enum 
{
	APPDLSTATE_UNKNOWN = 0,			//δ֪״̬
	APPDLSTATE_DOWNLOADING,			//��������	
	APPDLSTATE_FAIL,					//����ʧ��
	APPDLSTATE_OK,						//������
	APPDLSTATE_NOT,					//δ����
	APPDLSTATE_PAUSE,					//��ͣ����
	APPDLSTATE_WAIT					//�ȴ�����
}E_AppDlState_t;
typedef struct
{
   VMINT       nFlag;                         //�����Ŀ¼����Ӧ�ã�0=Ŀ¼��1=Ӧ��
   VMUINT32    nContentID;                    //Ŀ¼ID�Ż���AppID
   VMINT	   imageIcon;					  //Ӧ�û�Ŀ¼ICON
   VMINT       nAppCount;                     //Ŀ¼��Ӧ�ø�������ΪӦ�ø�ֵΪ0
   VMWCHAR	   szName[MAX_LEN_APP_NAME+1];	  //����
}ContentInfo_t;

typedef struct
{
	ContentInfo_t   ContentInfo;                    //���ݽṹ����
	E_AppDlState_t	eDownloadState;					//����״̬
	VMINT			nDownloadedTime;				//���ش���
	VMINT			nOrder;							//�Ǽ�
	VMINT			nSize;							//VXP�ļ���С��
	VMWCHAR		szCPName[MAX_LEN_CP_NAME+1];	//����������
	VMWCHAR		szUploadTime[MAX_LEN_TIME+1];	//Ӧ���ϼ�ʱ��
	VMWCHAR		szIntro[MAX_LEN_APP_INTRO+1];		//Ӧ�ý���
	VMWCHAR		szVersionID[MAX_LEN_APP_VERSIONID+1]; //versionid�� nContentID + QV
	VMWCHAR		szFileName[MAX_LEN_FILE_NAME + 1];		//�ļ���
	VMWCHAR		szVersion[MAX_LEN_VERSION + 1];			//�汾��1.1.1
}AppInfo_t;

typedef struct AppInfXmlPaser
{
	VMINT nResult;//��ȡ���
	VMINT nIconSize;
	VMINT nPartSize;//��ǰICON part �ĳߴ�
	VMINT nIconOffset;
	VMBYTE * pIconData;
	AppInfo_t * pAppInfo;
}AMAppInfXmlPser_t;


/**
 * ��ȡ�����б�Ļص�
 *
 * @param nResult                     ��ȡ���
 * @param nTypeID                     ����
 * @param nFolderID                   Ŀ¼���
 * @param nStartIndex                 ��ʼλ��
 * @param nDLNum                      ��������
 * @param nPercent                    ����
 * @param chNextPage				  �Ƿ�����һҳ��1��ʾ�У�0��ʾ��
 * @param chLstPage					  �Ƿ���βҳ��1��ʾ�ǣ�0��ʾ����
 * @param pContentList                ��ȡ�������б�
 */
typedef void (*content_list_cb)(VMINT nResult, VMINT nTypeID, VMINT nFolderID, VMINT nStartIndex,
									VMINT nDLNum, VMINT nPercent, VMUCHAR chNextPage,VMUCHAR chLstPage,sml_list_t * pContentList);


/**
 *  ����Э���ģ���ʼ��
 *
 * @return   ��ʼ���ɹ�����NET_OK�����򷵻�NET_ERR
 */
extern VMINT am_net_init(void);




/**
 * ��ȡ��һӦ�õ���ϸ��Ϣ
 *
 * @param get_single_app_info                ����ģ��ע�������Ļ�ȡ����Ӧ����ϸ��Ϣ�Ļص�
 *                                           @param nResult  ��ȡ���,
 *                                           @param pAppInfo ��ȡ��Ӧ�õ���ϸ��Ϣ
 *
 * @param nAppID                             Ӧ��ID
 *
 * @return                                   �ɹ��������󷵻�NET_OK�����򷵻�NET_ERR
 */
extern VMINT am_net_get_single_app_info(void(*get_single_app_info)(VMINT nResult, AppInfo_t *pAppInfo), VMINT nAppID);



/**
 * ģ��Release
 *
 */
extern void am_net_release(void);
/*
sml_list_t * am_net_xml_stack_create(void);

VMINT am_net_xml_stack_clear(sml_list_t * Stack);

void am_net_xml_stack_destroy(sml_list_t * Stack);

void am_net_xml_stack_push(sml_list_t * Stack,void * Data);

void * am_net_xml_stack_pop(sml_list_t * Stack);

void * am_net_xml_stack_get(sml_list_t * Stack);
*/

#ifdef __cplusplus 
}
#endif

#endif
