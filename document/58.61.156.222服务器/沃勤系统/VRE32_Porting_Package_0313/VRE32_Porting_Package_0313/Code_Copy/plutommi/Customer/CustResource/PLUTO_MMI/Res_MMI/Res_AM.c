#ifdef __VRE30_AM__

#include "MMI_features.h"
#include "MMIDataType.h"
#include "CustDataProts.h"
#include "GlobalMenuItems.h"
#include "AMResDef.h"
#include "AMConfig.h"
#include "PopulateRes.h"


void PopulateAMResData(void)
{
    // AM Title
    ADD_APPLICATION_STRING2(STR_ID_AM_NAME, "App Manager","");
    ADD_APPLICATION_STRING2(STR_ID_AM_LOADING, "Initialize","");  
    // Main Screen
    ADD_APPLICATION_STRING2(STR_ID_AM_MAIN_NO_DOWNLOAD, "Please insert a SIM card.","");      
    // Options Screen 
    ADD_APPLICATION_STRING2(STR_ID_AM_OPTION_LAUNCH, "Launch","");   
    ADD_APPLICATION_STRING2(STR_ID_AM_OPTION_CREATE_SHORTCUT, "Create shortcut","");   
    ADD_APPLICATION_STRING2(STR_ID_AM_OPTION_DELETE_SHORTCUT, "Remove shortcut","");  
    ADD_APPLICATION_STRING2(STR_ID_AM_OPTION_DATA_ACCOUNT, "Data Account","");
    // Details Screen     
    ADD_APPLICATION_STRING2(STR_ID_AM_DETAILS_INFO, "Information","");    
    ADD_APPLICATION_STRING2(STR_ID_AM_DETAILS_SIZE, "Size","");    
    ADD_APPLICATION_STRING2(STR_ID_AM_DETAILS_PATH, "Storage","");    
    ADD_APPLICATION_STRING2(STR_ID_AM_DETAILS_DEVELOPER, "Developer","");  
    ADD_APPLICATION_STRING2(STR_ID_AM_DETAILS_TEL, "Tel","");    
    ADD_APPLICATION_STRING2(STR_ID_AM_DETAILS_STORAGE_PHONE, "Phone","");    
    ADD_APPLICATION_STRING2(STR_ID_AM_DETAILS_STORAGE_ROM, "ROM","");   
    ADD_APPLICATION_STRING2(STR_ID_AM_DETAILS_STORAGE_MEMORY_CARD, "Memory card","");   
    // Settings Screen
    ADD_APPLICATION_STRING2(STR_ID_AM_SETTINGS_SIM, "Select SIM","");  
    ADD_APPLICATION_STRING2(STR_ID_AM_SETTINGS_CONN, "Connection mode","");  
    // SIM Settings Screen
    ADD_APPLICATION_STRING2(STR_ID_AM_SIM_SETTINGS_TITLE, "Select SIM","");  
    ADD_APPLICATION_STRING2(STR_ID_AM_SIM_SETTINGS_SIM1, "SIM1","");  
    ADD_APPLICATION_STRING2(STR_ID_AM_SIM_SETTINGS_SIM2, "SIM2","");  
    // Conn Settings Screen
    ADD_APPLICATION_STRING2(STR_ID_AM_CONN_SETTINGS_TITLE, "Connection mode","");  
    ADD_APPLICATION_STRING2(STR_ID_AM_CONN_SETTINGS_GPRS, "GPRS conn.","");  
    ADD_APPLICATION_STRING2(STR_ID_AM_CONN_SETTINGS_WIFI, "WIFI conn.","");  
    // Download Progress Screen

    // Update CDR
    ADD_APPLICATION_STRING2(STR_ID_AM_CDR_NEW_CONTENT, "New content was found, update now?","");  
    ADD_APPLICATION_STRING2(STR_ID_AM_CDR_NEW_VERSION, "New version was found, update now?","");  
    ADD_APPLICATION_STRING2(STR_ID_AM_CDR_UPDATE_SUCC, "Update successfully","");  
    ADD_APPLICATION_STRING2(STR_ID_AM_CDR_UPDATE_FAIL, "Failed to update","");  

    // User balance
    ADD_APPLICATION_STRING2(STR_ID_AM_USER_BALANCE, "% RMB left, you can use for payment.","");      
    
    // Popup Msg
    ADD_APPLICATION_STRING2(STR_ID_AM_FILE_OVERFLOW, "Number of files in VRE directory exceeds 5000. Cannot startup.", "Number of files in VRE directory exceeds 5000. Cannot startup.");
    ADD_APPLICATION_STRING2(STR_ID_AM_START_FAILURE, "Failed to start","");  
    ADD_APPLICATION_STRING2(STR_ID_AM_VRE_INIT_FAILURE, "Failed to initialize VRE","");  
    ADD_APPLICATION_STRING2(STR_ID_AM_DELETE_APP_QUERY, "Delete?","");  
    ADD_APPLICATION_STRING2(STR_ID_AM_DELETE_APP_FAILURE, "Failed to delete","");  
    ADD_APPLICATION_STRING2(STR_ID_AM_SET_FAILURE, "Failed to set","");  
    ADD_APPLICATION_STRING2(STR_ID_AM_CONNCT_FAILURE, "Failed to connect","");  
    ADD_APPLICATION_STRING2(STR_ID_AM_DOWNLOAD_FAILURE, "Failed to download","");  
    ADD_APPLICATION_STRING2(STR_ID_AM_DOWNLOAD_CANCEL, "Download has been cancelled","");  
    ADD_APPLICATION_STRING2(STR_ID_AM_DOWNLOAD_CONTINUE, "continue to download?","");  	
    ADD_APPLICATION_STRING2(STR_ID_AM_DOWNLOAD_DONE, "Download successfully, open now?","");  
    /* Dan 0528 begin */
    ADD_APPLICATION_STRING2(STR_ID_AM_DOWNLOAD_1302_ERR, "Invalid download parameter","");  
    ADD_APPLICATION_STRING2(STR_ID_AM_DOWNLOAD_1401_ERR, "Invalid download parameter",""); 
    ADD_APPLICATION_STRING2(STR_ID_AM_DOWNLOAD_1402_ERR, "Application not exist","");
    ADD_APPLICATION_STRING2(STR_ID_AM_DOWNLOAD_1403_ERR, "Application not exist","");
    ADD_APPLICATION_STRING2(STR_ID_AM_DOWNLOAD_1404_ERR, "MD5 error!","");
    ADD_APPLICATION_STRING2(STR_ID_AM_DOWNLOAD_1405_ERR, "Sorry, data request error!","");
    ADD_APPLICATION_STRING2(STR_ID_AM_DOWNLOAD_1406_ERR, "App will be available soon","");
    ADD_APPLICATION_STRING2(STR_ID_AM_DOWNLOAD_1407_ERR, "App will be available soon","");
    /* Dan 0528 end */
    ADD_APPLICATION_STRING2(STR_ID_AM_SHORTCUT_SET_DONE, "Shortcut is created in Home Screen.","");  
    ADD_APPLICATION_STRING2(STR_ID_AM_SHORTCUT_SET_DUPLICATE, "Shortcut already exists.","");  
    ADD_APPLICATION_STRING2(STR_ID_AM_SHORTCUT_OLD_VER_SET_FAILURE, "It is an old version. Shortcut is not created.","");  
    ADD_APPLICATION_STRING2(STR_ID_AM_SHORTCUT_SET_FAILURE, "Application is illegal. Shortcut is not created.","");  
    ADD_APPLICATION_STRING2(STR_ID_AM_SHORTCUT_SET_MAX, "The number of shortcuts is full.","");  
    ADD_APPLICATION_STRING2(STR_ID_AM_SHORTCUT_DEL_QUERY, "Remove the shortcut from Home Screen?","");  
    ADD_APPLICATION_STRING2(STR_ID_AM_SHORTCUT_DEL_DONE, "Shortcut is removed","");  
    ADD_APPLICATION_STRING2(STR_ID_AM_FILE_CORRUPT, "Application is corrupt",""); 
    ADD_APPLICATION_STRING2(STR_ID_AM_SHORTCUT_HS_DEL, "Application not found, remove the shortcut?",""); 
    // VRE App start failure message
    ADD_APPLICATION_STRING2(STR_ID_AM_FAIL_TO_START, "Failed to start application","Failed to start application");
    ADD_APPLICATION_STRING2(STR_ID_AM_FILE_NOT_EXIST, "Application does not exist","");
    ADD_APPLICATION_STRING2(STR_ID_AM_TAG_ERR_FAIL_TO_START, "Application does not match with the phone", "This Application cannot be run in this phone.");
    ADD_APPLICATION_STRING2(STR_ID_AM_DATE_ERR_FAIL_TO_START, "Phone date is wrong", "Phone date is wrong");
    ADD_APPLICATION_STRING2(STR_ID_AM_CERT_ERR_FAIL_TO_START, "Invalid certification", "Invalid certification. Failed to run this application.");
    ADD_APPLICATION_STRING2(STR_ID_AM_INVALID_SIM_FAIL_TO_START, "Invalid sim card", "Invalid sim card. Please insert valid one.");
    ADD_APPLICATION_STRING2(STR_ID_AM_CERT_EXPIRED_FAIL_TO_START, "The certification of this application is expired", "The certification of this application is expired.");
    ADD_APPLICATION_STRING2(STR_ID_AM_EXCEED_MAX_APP_NUM, "Application Number exceeded", "Application Number exceeded");
    ADD_APPLICATION_STRING2(STR_ID_AM_SYS_NOT_ENOUGH_MEMORY, "System memory not enough", "System memory not enough");
    ADD_APPLICATION_STRING2(STR_ID_AM_PROMPT_APPLICATION, "Please quit the running APP", "Please quit the runing APP");

    ADD_APPLICATION_STRING2(STR_ID_AM_APN_NOT_EXIST ,"APN not exist, edit?","");
    ADD_APPLICATION_STRING2(STR_ID_AM_DATA_ACCOUNT_INCORRECT ,"APN incorrect, update?", "");

    ADD_APPLICATION_STRING2(STR_ID_AM_DCNT_CAPTION_USE_PROXY ,"Use proxy","");
    ADD_APPLICATION_STRING2(STR_ID_AM_DCNT_CAPTION_IP_ADDRESS ,"IP address", "");
    ADD_APPLICATION_STRING2(STR_ID_AM_DCNT_CAPTION_PORT ,"Proxy port", "");
    ADD_APPLICATION_STRING2(STR_ID_AM_DTCNT_CAPTION_APN ,"APN", "");
    ADD_APPLICATION_STRING2(STR_ID_AM_DTCNT_INPUT_LACK,"Need input APN. Input again?","");
    // Common Image Resource
    // Loading Srceen ICON
    ADD_APPLICATION_IMAGE2( IMG_ID_AM_LOADING,CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_Loading.gif","");
    // Title ICON
    ADD_APPLICATION_IMAGE2( IMG_ID_AM_TITLE,CUST_IMG_PATH "\\\\MainLCD\\\\Titlebar\\\\TB_VRE.pbm","");
    // State ICON
    ADD_APPLICATION_IMAGE2( IMG_ID_AM_STATE_UNDOWNLOAD,CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_Undownload.png","");
    ADD_APPLICATION_IMAGE2( IMG_ID_AM_STATE_BG,CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_BG.png","");
    ADD_APPLICATION_IMAGE2( IMG_ID_AM_STATE_SHORTCUT,CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_Shortcut.png","");
    // Highlight ICON
    ADD_APPLICATION_IMAGE2( IMG_ID_AM_HIGHLIGHT,CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_Highlight.png","");
    ADD_APPLICATION_IMAGE2( IMG_ID_AM_HIGHLIGHT_SCROLLBAR,CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_Highlight_Scrollbar.png","");

    // AM Shortcut App
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_DEFAULT, "Damaged","");  
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_VRE20, "VRE App","");  
    ADD_APPLICATION_IMAGE2( IMG_ID_AM_APP_DEFAULT,CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_Default.gif","");
    #ifdef MMI_AM_SC_APP_AS
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_AS, "Download",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_AS,CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_AS.gif","");
    #endif

	#ifdef MMI_AM_SC_APP_QCS
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_QCS, "QCS",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_QCS, CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_QCS.gif","");
    #endif
	#ifdef MMI_AM_SC_APP_KRJJH
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_KRJJH, "KRJJH",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_KRJJH, CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_Krjjh.gif","");
    #endif
	#ifdef MMI_AM_SC_APP_SGGYZ
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_SGGYZ, "SGGYZ",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_SGGYZ, CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_Sggyz.gif","");
    #endif
	#ifdef MMI_AM_SC_APP_SMCL
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_SMCL, "SMCL",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_SMCL, CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_Smcl.gif","");
    #endif
	#ifdef MMI_AM_SC_APP_WULINOL
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_WULINOL, "WULINOL",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_WULINOL, CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_WuLinol.gif","");
    #endif
	#ifdef MMI_AM_SC_APP_BXJG
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_BXJG, "BXJG",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_BXJG, CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_Bxjg.gif","");
    #endif  
    #ifdef MMI_AM_SC_APP_RETURNKING
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_RETURNKING, "RETURNKING",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_RETURNKING,CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_ReturnKing.gif","");
    #endif
    #ifdef MMI_AM_SC_APP_WORLDWARCRAFT
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_WORLDWARCRAFT, "WORLDWARCRAFT",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_WORLDWARCRAFT,CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_WorldWarcraft.gif","");
    #endif
	#ifdef MMI_AM_SC_APP_RADIANTWOLF
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_RADIANTWOLF, "RADIANTWOLF",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_RADIANTWOLF, CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_RadiantWolf.gif","");
    #endif
    #ifdef MMI_AM_SC_APP_QQBROWSER
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_QQBROWSER, "QQBROWSER",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_QQBROWSER, CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_QQbrowser.gif","");
    #endif
	
    #ifdef MMI_AM_SC_APP_QQ
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_QQ, "QQ2009",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_QQ,CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_QQ2009.gif","");
    #endif
	

    
    #ifdef MMI_AM_SC_APP_KAIXIN
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_KAIXIN, "KAIXIN",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_KAIXIN,CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_KaiXin.gif","");
    #endif
	
    #ifdef MMI_AM_SC_APP_WLOL
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_WLOL, "WuLinOL",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_WLOL, CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_WulinOL.gif","");
    #endif
   
    #ifdef MMI_AM_SC_APP_MOBILEKK
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_MOBILEKK, "MobileKK",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_MOBILEKK, CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_MobileKK.gif","");
    #endif
   
    #ifdef MMI_AM_SC_APP_STOCKSTAR
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_STOCKSTAR, "StockStar",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_STOCKSTAR, CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_StockStar.gif","");
    #endif
    
    #ifdef MMI_AM_SC_APP_FETION
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_FETION, "Fetion",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_FETION,CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_Fetion.gif","");
    #endif
   
    #ifdef MMI_AM_SC_APP_QQLANDLORD
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_QQLANDLORD, "QQLandlord",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_QQLANDLORD, CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_QQLandlord.gif","");
    #endif
    
    #ifdef MMI_AM_SC_APP_MSN
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_MSN, "MSN",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_MSN, CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_MSN.gif",""); 
    #endif

     #ifdef MMI_AM_SC_APP_FETION
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_FETION, "FETION",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_FETION,CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_Fetion.gif","");
    #endif

	#ifdef MMI_AM_SC_APP_OPERAMINI
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_OPERAMINI, "OPERAMINI",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_OPERAMINI, CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_OperaMini.gif",""); 
    #endif

	#ifdef MMI_AM_SC_APP_BAIDU
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_BAIDU, "BAIDU",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_BAIDU, CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_Baidu.gif",""); 
    #endif
    #ifdef MMI_AM_SC_APP_OPERA
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_OPERA, "OperaMini",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_OPERA, CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_Opera.gif",""); 
    #endif
   
    #ifdef MMI_AM_SC_APP_100TV
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_100TV, "100TV",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_100TV, CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_100TV.gif","");
    #endif
   
    #ifdef MMI_AM_SC_APP_AIPIM
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_AIPIM, "AIPIM",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_AIPIM, CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_AIPIM.gif","");
    #endif
    
    #ifdef MMI_AM_SC_APP_LUUTOO
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_LUUTOO, "Luutoo",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_LUUTOO, CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_Luutoo.gif",""); 
    #endif
    
    #ifdef MMI_AM_SC_APP_SHANGMAIL
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_PUSHMAIL, "ShangMail",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_PUSHMAIL,CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_Pushmail.gif","");
   #endif
	//added by hendy	
		#ifdef MMI_AM_SC_APP_BH
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_BH, "Bubble Hunter",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_BH, CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_BH.gif","");
    #endif
	#ifdef MMI_AM_SC_APP_MYLIVE
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_MYLIVE, "Mylive",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_MYLIVE, CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_Mylive.gif","");
    #endif
	#ifdef MMI_AM_SC_APP_TSF
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_TSF, "Top-secret Flights",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_TSF, CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_TSF.gif","");
    #endif
	#ifdef MMI_AM_SC_APP_MT
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_MT, "Magic Tower",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_MT, CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_MT.gif","");
    #endif
	#ifdef MMI_AM_SC_APP_PW
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_PW, "Princess Wall",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_PW, CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_PW.gif","");
    #endif
	#ifdef MMI_AM_SC_APP_BA
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_BA, "Brave Adventure",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_BA, CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_BA.gif","");
    #endif  
	#ifdef MMI_AM_SC_APP_FMS
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_FMS, "Fly Magic Story",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_FMS,CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_FMS.gif","");
    #endif
	#ifdef MMI_AM_SC_APP_YMD100F
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_YMD100F, "You Man?Down 100 Floor",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_YMD100F, CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_YMD100F.gif","");
    #endif
    #ifdef MMI_AM_SC_APP_VITTER
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_VITTER, "Vitter",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_VITTER,CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_Vitter.gif","");
    #endif
	//added by hendy	
	#ifdef MMI_AM_SC_APP_MOTALK
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_MOTALK, "Motalk",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_MOTALK,CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_Motalk.gif","");
    #endif

	#ifdef MMI_AM_SC_APP_RAMBO
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_RAMBO, "Rambo",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_RAMBO,CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_Rambo.gif","");
    #endif

	#ifdef MMI_AM_SC_APP_MAGNETICJOE2
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_MAGNETICJOE2, "Magneticjoe2",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_MAGNETICJOE2,CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_Magneticjoe2.gif","");
    #endif

	#ifdef MMI_AM_SC_APP_PENGUINFERVER
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_PENGUINFERVER, "Penguinfever",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_PENGUINFERVER,CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_Penguinfever.gif","");
    #endif

	#ifdef MMI_AM_SC_APP_ADVOFBUBBLE
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_ADVOFBUBBLE, "Adventure of Bubble",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_ADVOFBUBBLE,CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_AdventureofBubble.gif","");
    #endif

	#ifdef MMI_AM_SC_APP_RACING
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_RACING, "Racing",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_RACING,CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_Racing.gif","");
    #endif

	#ifdef MMI_AM_SC_APP_TRANSFORMER
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_TRANSFORMER, "Transformer",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_TRANSFORMER,CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_Transformer.gif","");
    #endif

	#ifdef MMI_AM_SC_APP_HAPPYBOBBLE
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_HAPPYBOBBLE, "Happy Bobble",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_HAPPYBOBBLE,CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_HappyBobble.gif","");
    #endif

	#ifdef MMI_AM_SC_APP_JEEP
    ADD_APPLICATION_STRING2(STR_ID_AM_APP_NAME_JEEP, "Jeep",""); 
    ADD_APPLICATION_IMAGE2(IMG_ID_AM_APP_JEEP,CUST_IMG_PATH "\\\\MainLCD\\\\VREAPP\\\\AM_App_Jeep.gif","");
    #endif

    ADD_APPLICATION_STRING2(STR_ID_AM_MEDIA_MEMORY_UNAVAIBLE, "Please stop Fun & Games.",""); 
/*vogins_20100625_start*/
ADD_APPLICATION_STRING2(STR_ID_AM_PROMPT_INFOMATION, "These products supply you with free downloading and updating and the gprs flux fee causing from it will be collected by the operators. Advice you to query china mobile or china unicom to open monthly benefit.",""); 
ADD_APPLICATION_STRING2(STR_ID_AM_SC_PROMPT_INFOMATION, "This product supplies you with free downloading and updating and the gprs flux fee causing from it will be collected by the operators. Advice you to query china mobile or china unicom to open monthly benefit.","");
/*vogins_20100625_end*/
  	 //wei.xia add by 0624 for vre version information
   	ADD_APPLICATION_STRING2(STR_ID_INFORMATION, "VRE INFORMATION","VRE INFORMATION"); 
	//add end 
	/*vogins_20100712_start*/
	ADD_APPLICATION_STRING2(STR_ID_AM_PROCESSES_MANAGER, "Processes Manager", "");
	ADD_APPLICATION_STRING2(STR_ID_AM_STOP_FAILURE, "Failed to stop the application!", "");
	/*vogins_20100712_end*/
}
#endif
