
#ifndef LOGIC_NET_H
#define LOGIC_NET_H
#include "MMIDataType.h"
//#include "global_define.h"

#ifdef __cplusplus 
extern "C" {
#endif

#define  AM_NET_OK					    0			//成功
#define  AM_NET_ERR					-1			//失败
#define  AM_NET_ERR1					-2			//应用重复评级
#define  AM_NET_ERR2					-3			//产品详细信息无适配版本


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
	APPDLSTATE_UNKNOWN = 0,			//未知状态
	APPDLSTATE_DOWNLOADING,			//正在下载	
	APPDLSTATE_FAIL,					//下载失败
	APPDLSTATE_OK,						//已下载
	APPDLSTATE_NOT,					//未下载
	APPDLSTATE_PAUSE,					//暂停下载
	APPDLSTATE_WAIT					//等待下载
}E_AppDlState_t;
typedef struct
{
   VMINT       nFlag;                         //标记是目录还是应用，0=目录，1=应用
   VMUINT32    nContentID;                    //目录ID号或者AppID
   VMINT	   imageIcon;					  //应用或目录ICON
   VMINT       nAppCount;                     //目录下应用个数，若为应用该值为0
   VMWCHAR	   szName[MAX_LEN_APP_NAME+1];	  //名称
}ContentInfo_t;

typedef struct
{
	ContentInfo_t   ContentInfo;                    //内容结构对象
	E_AppDlState_t	eDownloadState;					//下载状态
	VMINT			nDownloadedTime;				//下载次数
	VMINT			nOrder;							//星级
	VMINT			nSize;							//VXP文件大小；
	VMWCHAR		szCPName[MAX_LEN_CP_NAME+1];	//开发商名称
	VMWCHAR		szUploadTime[MAX_LEN_TIME+1];	//应用上架时间
	VMWCHAR		szIntro[MAX_LEN_APP_INTRO+1];		//应用介绍
	VMWCHAR		szVersionID[MAX_LEN_APP_VERSIONID+1]; //versionid； nContentID + QV
	VMWCHAR		szFileName[MAX_LEN_FILE_NAME + 1];		//文件名
	VMWCHAR		szVersion[MAX_LEN_VERSION + 1];			//版本号1.1.1
}AppInfo_t;

typedef struct AppInfXmlPaser
{
	VMINT nResult;//获取结果
	VMINT nIconSize;
	VMINT nPartSize;//当前ICON part 的尺寸
	VMINT nIconOffset;
	VMBYTE * pIconData;
	AppInfo_t * pAppInfo;
}AMAppInfXmlPser_t;


/**
 * 获取内容列表的回调
 *
 * @param nResult                     获取结果
 * @param nTypeID                     类编号
 * @param nFolderID                   目录编号
 * @param nStartIndex                 起始位置
 * @param nDLNum                      下载数量
 * @param nPercent                    进度
 * @param chNextPage				  是否有下一页，1表示有，0表示无
 * @param chLstPage					  是否是尾页，1表示是，0表示不是
 * @param pContentList                获取的内容列表
 */
typedef void (*content_list_cb)(VMINT nResult, VMINT nTypeID, VMINT nFolderID, VMINT nStartIndex,
									VMINT nDLNum, VMINT nPercent, VMUCHAR chNextPage,VMUCHAR chLstPage,sml_list_t * pContentList);


/**
 *  网络协议层模块初始化
 *
 * @return   初始化成功返回NET_OK，否则返回NET_ERR
 */
extern VMINT am_net_init(void);




/**
 * 获取单一应用的详细信息
 *
 * @param get_single_app_info                其它模块注册上来的获取单个应用详细信息的回调
 *                                           @param nResult  获取结果,
 *                                           @param pAppInfo 获取的应用的详细信息
 *
 * @param nAppID                             应用ID
 *
 * @return                                   成功发起请求返回NET_OK，否则返回NET_ERR
 */
extern VMINT am_net_get_single_app_info(void(*get_single_app_info)(VMINT nResult, AppInfo_t *pAppInfo), VMINT nAppID);



/**
 * 模块Release
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
