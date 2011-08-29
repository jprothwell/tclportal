#ifdef __VRE__

#include "MMI_features.h"
#include "MMIDataType.h"
#include "CustDataProts.h"
#include "GlobalMenuItems.h"
#include "VREDef.h"
#include "PopulateRes.h"


void PopulateVREResData(void)
{

  ADD_APPLICATION_STRING2(STR_VRE_TITLE, "VRE","VRE");
  ADD_APPLICATION_STRING2(STR_ID_VRE_FAIL_TO_START, "Failed to start VRE","Failed to start VRE");
  ADD_APPLICATION_STRING2(STR_ID_VRE_NOT_INSTALL, "Please install VRE","Please install VRE");
	ADD_APPLICATION_STRING2(STR_ID_VRE_USB_FAIL_TO_START, "USB:Funcation not allowed","USB:Funcation not allowed"); /*USB:该功能暂时无法使用*/
	ADD_APPLICATION_IMAGE2( IMAGE_VRE_LARGE_ICON,CUST_IMG_PATH "\\\\MainLCD\\\\FileManager\\\\FM_VXP.gif","VRE Large");
	ADD_APPLICATION_IMAGE2( IMAGE_VRE_SMALL_ICON,CUST_IMG_PATH "\\\\MainLCD\\\\FileManager\\\\FM_SMALL_VXP.pbm","VRE Small");
	ADD_APPLICATION_IMAGE2( IMAGE_VRE_ICON,CUST_IMG_PATH "\\\\MainLCD\\\\Submenu\\\\NoSIM\\\\NS_VRE.pbm","VRE Icon");
	ADD_APPLICATION_STRING2(STR_ID_VRE_TAG_ERR_FAIL_TO_START, "This program cannot be run in this phone.", "This program cannot be run in this phone.");//启动错误，不适合在本机运行。
	ADD_APPLICATION_STRING2(STR_ID_VRE_DATE_ERR_FAIL_TO_START, "Phone date is wrong. Please correct it.", "Phone date is wrong. Please correct it.");//系统时间错误，请设置为正确的系统时间后再试。
	ADD_APPLICATION_STRING2(STR_ID_VRE_CERT_ERR_FAIL_TO_START, "Invalid certification. Failed to run this program.", "Invalid certification. Failed to run this program.");//启动错误，证书验证失败
	ADD_APPLICATION_STRING2(STR_ID_VRE_INVALID_SIM_FAIL_TO_START, "Invalid SIM card. Please insert valid one and retry.", "Invalid SIM card. Please insert valid one and retry.");//SIM卡验证错误，请插入注册的SIM卡
	ADD_APPLICATION_STRING2(STR_ID_VRE_CERT_EXPIRED_FAIL_TO_START, "The certification of this program is expired.", "The certification of this program is expired.");//验证错误，证书已过期
	ADD_APPLICATION_STRING2(STR_ID_VRE_RECURSIVELY_START, "Please launch Fun&Games from menu", "Please launch Fun&Games from menu"); /*请通过菜单启动娱乐空间*/
	ADD_APPLICATION_STRING2(STR_ID_VRE_CARD_PLUGOUT, "NO storage card, Please press OK to close application.", "NO storage card, Please press OK to close application."); //存储卡已弹出，请确认关闭应用程序。
	ADD_APPLICATION_STRING2(STR_ID_VRE_FILE_OVERFLOW, "Number of files in VRE directory exceeds 5000. Can't startup.", "Number of files in VRE directory exceeds 5000. Can't startup.") /* 启动失败，VRE目录下文件数已超过5千个。*/
}
#endif
