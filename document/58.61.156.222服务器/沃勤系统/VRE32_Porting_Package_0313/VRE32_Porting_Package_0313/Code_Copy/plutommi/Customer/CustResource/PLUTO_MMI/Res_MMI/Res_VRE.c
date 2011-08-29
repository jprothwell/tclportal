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
	ADD_APPLICATION_STRING2(STR_ID_VRE_USB_FAIL_TO_START, "USB:Funcation not allowed","USB:Funcation not allowed"); /*USB:�ù�����ʱ�޷�ʹ��*/
	ADD_APPLICATION_IMAGE2( IMAGE_VRE_LARGE_ICON,CUST_IMG_PATH "\\\\MainLCD\\\\FileManager\\\\FM_VXP.gif","VRE Large");
	ADD_APPLICATION_IMAGE2( IMAGE_VRE_SMALL_ICON,CUST_IMG_PATH "\\\\MainLCD\\\\FileManager\\\\FM_SMALL_VXP.pbm","VRE Small");
	ADD_APPLICATION_IMAGE2( IMAGE_VRE_ICON,CUST_IMG_PATH "\\\\MainLCD\\\\Submenu\\\\NoSIM\\\\NS_VRE.pbm","VRE Icon");
	ADD_APPLICATION_STRING2(STR_ID_VRE_TAG_ERR_FAIL_TO_START, "This program cannot be run in this phone.", "This program cannot be run in this phone.");//�������󣬲��ʺ��ڱ������С�
	ADD_APPLICATION_STRING2(STR_ID_VRE_DATE_ERR_FAIL_TO_START, "Phone date is wrong. Please correct it.", "Phone date is wrong. Please correct it.");//ϵͳʱ�����������Ϊ��ȷ��ϵͳʱ������ԡ�
	ADD_APPLICATION_STRING2(STR_ID_VRE_CERT_ERR_FAIL_TO_START, "Invalid certification. Failed to run this program.", "Invalid certification. Failed to run this program.");//��������֤����֤ʧ��
	ADD_APPLICATION_STRING2(STR_ID_VRE_INVALID_SIM_FAIL_TO_START, "Invalid SIM card. Please insert valid one and retry.", "Invalid SIM card. Please insert valid one and retry.");//SIM����֤���������ע���SIM��
	ADD_APPLICATION_STRING2(STR_ID_VRE_CERT_EXPIRED_FAIL_TO_START, "The certification of this program is expired.", "The certification of this program is expired.");//��֤����֤���ѹ���
	ADD_APPLICATION_STRING2(STR_ID_VRE_RECURSIVELY_START, "Please launch Fun&Games from menu", "Please launch Fun&Games from menu"); /*��ͨ���˵��������ֿռ�*/
	ADD_APPLICATION_STRING2(STR_ID_VRE_CARD_PLUGOUT, "NO storage card, Please press OK to close application.", "NO storage card, Please press OK to close application."); //�洢���ѵ�������ȷ�Ϲر�Ӧ�ó���
	ADD_APPLICATION_STRING2(STR_ID_VRE_FILE_OVERFLOW, "Number of files in VRE directory exceeds 5000. Can't startup.", "Number of files in VRE directory exceeds 5000. Can't startup.") /* ����ʧ�ܣ�VREĿ¼���ļ����ѳ���5ǧ����*/
}
#endif
