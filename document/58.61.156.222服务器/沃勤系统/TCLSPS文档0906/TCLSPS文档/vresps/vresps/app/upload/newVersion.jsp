<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangAction"%>
<%@ page import="com.language.langdata.LangWorkflow"%>
<%@ page import="com.vogins.sps.db.app.AppVersion"%>
<%@ page import="com.vogins.sps.db.app.*"%>
<%@ page import="com.vogins.sps.db.publicinfo.SystemParam"%>
<%@ page import="org.jwdf.io.*"%>
<%@ page import="org.jwdf.framework.console.*"%>
<%@ page import="org.jwdf.util.*"%>
<%@ page import="java.io.File"%>
<%@ page import="com.oa.workflow.db.*"%>
<%@ page import="org.jwdf.framework.base.AbstractTableBean"%>
<%@ page import="com.vogins.workflow.db.TAppVersion"%>
<%@ page import="com.vogins.sps.db.app30.*"%>
<%@ page import="com.vogins.sps.apppackage.AppPackage"%>
<%@ page import="com.vogins.sps.apppackage.data.PackageInfo"%>
<%@ page import="com.vogins.sps.init.SystemParas"%>
<%@ page import="com.jspsmart.upload.*"%>
<jsp:useBean id="mySmartUpload" scope="page" class="com.jspsmart.upload.SmartUpload" />
<%
	AppVersion appver = new AppVersion();
	Application app = new Application();
	CPPartner cp = new CPPartner();
	String strEdit = request.getParameter("edit");
	String appId = request.getParameter("AppId");
	if(strEdit == null) strEdit = "0";
	if(appId == null) appId = "";

	String packVersion = "3.0";
	String rank = "5";
	String verType = "1";
	String certId = "0";
	String certDate = "20301231235959";
	String version = "1.0.0";
	String memery = "0";
	String screen = "0";
	String screenWidth = "0";
	String screenHeight = "0";
	String input_keypad = null;
	String input_touch = null;
	String input_zl = null;
	String input_gx = null;
	String feeGroupId = "0";
	String price = "0";
	String feeType = "1";
	String feeValue = "0";
	String vreVersion = "";
	String compilerVersion = "1";
	String trialFlag = "1";
	String trialPrice = "0";
	String trialType = "1";
	String trialValue = "0";
	String mobileList = "";
	String bgRun = "0";
	
	String appDesc = "";
	String appName = LangPage.langPage.getDef_appname();
	String appNameBig5 = "測試產品";
	String appNameEn = "TestApp";
	String cpName = LangPage.langPage.getDef_cpname();
	
	String sc_qqvga = null;
	String sc_qcif = null;
	String sc_qvga = null;
	String sc_wqvga = null;
	String sc_hvga = null;
	String sc_qqvga_ls = null;
	String sc_qcif_ls = null;
	String sc_qvga_ls = null;
	String sc_wqvga_ls = null;
	String sc_hvga_ls = null;
	String sc_other = null;
	
	String mtk_08A = "1";
	String mtk_08B = "1";
	String mtk_09A = "1";
	String mtk_09B = "1";
	String mtkList = ";";
	
	String chip_6223 = "1";
	String chip_6225 = "1";
	String chip_6235 = "1";
	String chip_6238 = "1";
	String chip_6253 = "1";
	String chipList = ";";

	String perm_5000 = "1";
	String perm_5001 = "1";
	String perm_5002 = "1";
	String perm_5003 = "1";
	String perm_5004 = "1";
	String perm_5005 = "1";
	String perm_5006 = "1";
	String perm_5007 = "1";
	String perm_5008 = "1";
	String perm_5009 = "1";
	String perm_5010 = "1";
	String perm_5011 = "1";
	String perm_5012 = "1";
	String perm_5013 = "1";
	String perm_5014 = "1";
	String perm_5015 = "1";
	String perm_5016 = "1";
	String perm_5017 = "1";
	String perm_5018 = "1";
	String perm_5019 = "1";
	String perm_5020 = "1";
	String permissionList = ";";
	String feechannel = "0";
	String feechannel1 = "0";
	String screenList = ";";
	
	String strErrorInfo = "";
	String flowId = "";
	int wfStatus = 0;
	if(appId.equals("")){
		strErrorInfo = "LangAction.langAction.getNoselect_app()";
	}
	else if(strEdit.equals("1"))
	{
		mySmartUpload.initialize(pageContext);
		Request myRequest = mySmartUpload.getRequest();
		mySmartUpload.upload();

		packVersion = myRequest.getParameter("PackVersion");
		rank = myRequest.getParameter("Rank");
		verType = myRequest.getParameter("VerType");
		certId = myRequest.getParameter("CertId");
		certDate = myRequest.getParameter("CertDate");
		version = myRequest.getParameter("Version");
		memery = myRequest.getParameter("Memery");
		screen = myRequest.getParameter("Screen");
		screenWidth = myRequest.getParameter("ScreenWidth");
		screenHeight = myRequest.getParameter("ScreenHeight");
		input_keypad = myRequest.getParameter("Input_Keypad");
		input_touch = myRequest.getParameter("Input_Touch");
		input_zl = myRequest.getParameter("Input_ZL");
		input_gx = myRequest.getParameter("Input_GX");
		feeGroupId = myRequest.getParameter("FeeGroupId");
		price = myRequest.getParameter("Price");
		feeType = myRequest.getParameter("FeeType");
		feeValue = myRequest.getParameter("FeeValue");
		vreVersion = myRequest.getParameter("VreVersion");
		compilerVersion = myRequest.getParameter("CompilerVersion");
		trialFlag = myRequest.getParameter("TrialFlag");
		trialPrice = myRequest.getParameter("TrialPrice");
		trialType = myRequest.getParameter("TrialType");
		trialValue = myRequest.getParameter("TrialValue");
		mobileList = myRequest.getParameter("MobileList");
		
		mtk_08A = myRequest.getParameter("08A");
		mtk_08B = myRequest.getParameter("08B");
		mtk_09A = myRequest.getParameter("09A");
		mtk_09B = myRequest.getParameter("09B");
		
		chip_6223 = myRequest.getParameter("6223");
		chip_6225 = myRequest.getParameter("6225");
		chip_6235 = myRequest.getParameter("6235");
		chip_6238 = myRequest.getParameter("6238");
		chip_6253 = myRequest.getParameter("6253");
		
		perm_5000 = myRequest.getParameter("5000");
		perm_5001 = myRequest.getParameter("5001");
		perm_5002 = myRequest.getParameter("5002");
		perm_5003 = myRequest.getParameter("5003");
		perm_5004 = myRequest.getParameter("5004");
		perm_5005 = myRequest.getParameter("5005");
		perm_5006 = myRequest.getParameter("5006");
		perm_5007 = myRequest.getParameter("5007");
		perm_5008 = myRequest.getParameter("5008");
		perm_5009 = myRequest.getParameter("5009");
		perm_5010 = myRequest.getParameter("5010");
		perm_5011 = myRequest.getParameter("5011");
		perm_5012 = myRequest.getParameter("5012");
		perm_5013 = myRequest.getParameter("5013");
		perm_5014 = myRequest.getParameter("5014");
		perm_5015 = myRequest.getParameter("5015");
		perm_5016 = myRequest.getParameter("5016");
		perm_5017 = myRequest.getParameter("5017");
		perm_5018 = myRequest.getParameter("5018");
		perm_5019 = myRequest.getParameter("5019");
		perm_5020 = myRequest.getParameter("5020");
		bgRun = myRequest.getParameter("BGRun");
		feechannel = myRequest.getParameter("FeeChannel");
		feechannel1 = myRequest.getParameter("FeeChannel1");

		sc_qqvga = myRequest.getParameter("QQVGA");
		sc_qcif = myRequest.getParameter("QCIF");
		sc_qvga = myRequest.getParameter("QVGA");
		sc_wqvga = myRequest.getParameter("WQVGA");
		sc_hvga = myRequest.getParameter("HVGA");
		sc_qqvga_ls = myRequest.getParameter("QQVGA-LS");
		sc_qcif_ls = myRequest.getParameter("QCIF-LS");
		sc_qvga_ls = myRequest.getParameter("QVGA-LS");
		sc_wqvga_ls = myRequest.getParameter("WQVGA-LS");
		sc_hvga_ls = myRequest.getParameter("HVGA-LS");
		sc_other = myRequest.getParameter("OtherScreen");
		
		if(rank == null || rank.equals("")) rank = "5";
		if(verType == null || verType.equals("")) verType = "1";
		if(certId == null || certId.equals("")) certId = "0";
		if(certDate == null || certDate.equals("")) certDate = "00000000000000";
		if(version == null || version.equals("")) version = "1.0.0";
		if(memery == null || memery.equals("")) memery = "0";
		if(screen == null || screen.equals("")) screen = "9";
		if(screenWidth == null || screenWidth.equals("")) screenWidth="0";
		if(screenHeight == null || screenWidth.equals("")) screenHeight = "0";
		int inputtype = 0;
		if(input_keypad != null) inputtype = inputtype + 1;
		if(input_touch != null) inputtype = inputtype + 2;
		if(input_zl != null) inputtype = inputtype + 4;
		if(input_gx != null) inputtype = inputtype + 8;
		if(feeGroupId == null || feeGroupId.equals("")) feeGroupId = "0";
		if(price == null || price.equals("")) price = "0";
		if(feeType == null || feeType.equals("")) feeType = "1";
		if(feeValue == null || feeValue.equals("")) feeValue = "0";
		if(vreVersion == null) vreVersion = "";
		if(compilerVersion == null || compilerVersion.equals("")) compilerVersion = "1";
		if(trialFlag == null || trialFlag.equals("")) trialFlag = "1";
		if(trialPrice == null || trialPrice.equals("")) trialPrice = "0";
		if(trialType == null || trialType.equals("")) trialType = "1";
		if(trialValue == null || trialValue.equals("")) trialValue = "0";
		if(mobileList == null) mobileList = "";
		
		if(mtk_08A != null) mtkList = mtkList + "08A;";
		if(mtk_08B != null) mtkList = mtkList + "08B;";
		if(mtk_09A != null) mtkList = mtkList + "09A;";
		if(mtk_09B != null) mtkList = mtkList + "09B;";
		
		if(chip_6223 != null) chipList = chipList + "6223;";
		if(chip_6225 != null) chipList = chipList + "6225;";
		if(chip_6235 != null) chipList = chipList + "6235;";
		if(chip_6238 != null) chipList = chipList + "6238;";
		if(chip_6253 != null) chipList = chipList + "6253;";
		
		if(perm_5000 != null) permissionList = permissionList + "5000;";
		if(perm_5001 != null) permissionList = permissionList + "5001;";
		if(perm_5002 != null) permissionList = permissionList + "5002;";
		if(perm_5003 != null) permissionList = permissionList + "5003;";
		if(perm_5004 != null) permissionList = permissionList + "5004;";
		if(perm_5005 != null) permissionList = permissionList + "5005;";
		if(perm_5006 != null) permissionList = permissionList + "5006;";
		if(perm_5007 != null) permissionList = permissionList + "5007;";
		if(perm_5008 != null) permissionList = permissionList + "5008;";
		if(perm_5009 != null) permissionList = permissionList + "5009;";
		if(perm_5010 != null) permissionList = permissionList + "5010;";
		if(perm_5011 != null) permissionList = permissionList + "5011;";
		if(perm_5012 != null) permissionList = permissionList + "5012;";
		if(perm_5013 != null) permissionList = permissionList + "5013;";
		if(perm_5014 != null) permissionList = permissionList + "5014;";
		if(perm_5015 != null) permissionList = permissionList + "5015;";
		if(perm_5016 != null) permissionList = permissionList + "5016;";
		if(perm_5017 != null) permissionList = permissionList + "5017;";
		if(perm_5018 != null) permissionList = permissionList + "5018;";
		if(perm_5019 != null) permissionList = permissionList + "5019;";
		if(perm_5020 != null) permissionList = permissionList + "5020;";
		
		if(sc_qqvga != null) screenList = screenList + "QQVGA;";
		if(sc_qcif != null) screenList = screenList + "QCIF;";
		if(sc_qvga != null) screenList = screenList + "QVGA;";
		if(sc_wqvga != null) screenList = screenList + "WQVGA;";
		if(sc_hvga != null) screenList = screenList + "HVGA;";
		if(sc_qqvga_ls != null) screenList = screenList + "QQVGA-LS;";
		if(sc_qcif_ls != null) screenList = screenList + "QCIF-LS;";
		if(sc_qvga_ls != null) screenList = screenList + "QVGA-LS;";
		if(sc_wqvga_ls != null) screenList = screenList + "WQVGA-LS;";
		if(sc_hvga_ls != null) screenList = screenList + "HVGA-LS;";
		
		String scs[] = screenList.split(";");
		
		if(scs.length > 0){
			
			if(scs.length>2){
				screen = "0";
			}else if(screenList.equals(";QCIF;")){
				screen = "1";
			}else if(screenList.equals(";QVGA;")){
				screen = "2";
			}else if(screenList.equals(";WQVGA;")){
				screen = "4";
			}else if(sc_other != null){
				screen = "8";
			}else{
				screen = "999";
			}
			
			if(screenWidth.equals("")) screenWidth = "0";
			if(screenHeight.equals("")) screenHeight = "0";
	
			if(bgRun == null || bgRun.equals("")) bgRun = "0";
			if(feechannel == null || feechannel.equals("")) feechannel="0"; //计费通道
			if(feechannel1 == null || feechannel1.equals("")) feechannel1="0"; //计费通道
	
			if(!screen.equals("0") && screenWidth.equals("0") && screenHeight.equals("0")&& screenList.equals("")){
				strErrorInfo = LangPage.langPage.getNoselect_screentype();
			}else if(memery.equals("")){
				strErrorInfo = LangPage.langPage.getNoselect_memorysize();
			}else if(inputtype == 0){
				strErrorInfo = LangPage.langPage.getNoselect_inputdc();
			}else if("".equals(mtkList) || mtkList == null || ";".equals(mtkList)){
				strErrorInfo = LangPage.langPage.getPlease_select()+appver.getAliasByFiled("MTKVersion");
			}else if("".equals(chipList) || chipList == null || ";".equals(chipList)){
				strErrorInfo = LangPage.langPage.getPlease_select()+appver.getAliasByFiled("ChipVersion");
			}else	{
				
				com.jspsmart.upload.File myContentFile = mySmartUpload.getFiles().getFile(0);
				String ContentFileName = myContentFile.getFileName();
				
				boolean blnIsHave = false;
				String tempFile = Long.toString(System.currentTimeMillis()) + ".dat";
				if(!myContentFile.isMissing())
				{
					myContentFile.saveAs(SystemParas.getAppPath() + "/" + tempFile,SmartUpload.SAVE_PHYSICAL);
					blnIsHave = true;
				}
	
				String sessionId = Console.session_manager.getSessionId(request);
				String strAddUser = Console.session_manager.get(sessionId).getUserName();
	
				String wfType = "25";
				AppFolder af = new AppFolder();
				MoreApp ma = new MoreApp();
				RecommendApp ra = new RecommendApp();
				if(af.checkAppExist(appId) || ma.checkAppExist(appId) || ra.checkAppExist(appId)){
					wfType = "22";
				}
	
				boolean insertSucc = false;
				
				SystemParam sversion = new SystemParam();
				String version_id = sversion.getItemValue("app_version_id");
				
				TAppVersion ver = new TAppVersion();
				//String verId = ver.getFormatId(appId,10) + ver.getFormatId(version_id,10);
				//ver.setValue("VerId",verId);
				ver.setValue("AppId",appId);
				ver.setValue("PackVersion",packVersion);
				ver.setValue("VerType",verType);
				ver.setValue("FileSize",Integer.toString(myContentFile.getSize()));
				ver.setValue("FileName",ContentFileName);
				ver.setValue("SavePath",SystemParas.getAppPath() + "/" + tempFile);
				ver.setValue("PackageFlag","0");
				ver.setValue("Rank",rank);
				ver.setValue("CertId",certId);
				ver.setValue("CertDate",certDate);
				ver.setValue("AppVersion",version);
				ver.setValue("MemorySize",memery);
				ver.setValue("ScreenType",screen);
				ver.setValue("ScreenList",screenList);
				ver.setValue("ScreenWidth",screenWidth);
				ver.setValue("ScreenHeight",screenHeight);
				ver.setValue("InputDC",Integer.toString(inputtype));
				ver.setValue("FeeGroupId",feeGroupId);
				ver.setValue("FeeChannel",feechannel);
				ver.setValue("FeeChannel1",feechannel1);
				ver.setValue("FeePrice",price);
				ver.setValue("FeeType",feeType);
				ver.setValue("FeeValue",feeValue);
				ver.setValue("VREVersion",vreVersion);
				ver.setValue("MTKVersion",mtkList);
				ver.setValue("ChipVersion",chipList);
				ver.setValue("CompilerVersion",compilerVersion);
				ver.setValue("TrialFlag",trialFlag);
				ver.setValue("TrialPrice",trialPrice);
				ver.setValue("TrialType",trialType);
				ver.setValue("TrialValue",trialValue);
				ver.setValue("Permission",permissionList);
				ver.setValue("MobileList",mobileList);
				ver.setValue("BackgroundRun",bgRun);
				ver.setValue("AddTime",DateUtil.getFullDateTime());
				ver.setValue("AddUser",strAddUser);
	
				if(blnIsHave){
					//Application app = new Application();
					if(app.getInfo(appId)){
						appName = app.getValue("AppName");
						appDesc = app.getValue("AppDesc");
						appNameBig5 = app.getValue("AppNameBig5");
						appNameEn = app.getValue("AppNameEn");
					//	CPPartner cp = new CPPartner();
						if(cp.getInfo(app.getValue("CPId"))){
							cpName = cp.getValue("ShortName");
						}
					}
					PackageInfo tagInfo = new PackageInfo();
					tagInfo.setSavePath(SystemParas.getAppPath() + "/" + tempFile);
					tagInfo.setFileName(ContentFileName);
					tagInfo.setCpName(cpName);
					tagInfo.setAppId(appId);
					tagInfo.setCertId(certId);
					tagInfo.setAppName(appName);
					tagInfo.setAppVersion(version);
					tagInfo.setCertDate(certDate);
					tagInfo.setFeeGroupId(feeGroupId);
					tagInfo.setMemorySize(memery);
					tagInfo.setScreenType(screen);
					tagInfo.setScreenWidth(screenWidth);
					tagInfo.setScreenHeight(screenHeight);
					tagInfo.setVreVersion(vreVersion);
					tagInfo.setPermission(permissionList);
					tagInfo.setInputDC(Integer.toString(inputtype));
					tagInfo.setAppDesc(appDesc);
					tagInfo.setRank(rank);
					
					if(packVersion.equals("3.0")){
						tagInfo.setAppNameBig5(appNameBig5);
						tagInfo.setAppNameEn(appNameEn);
						tagInfo.setBgRun(bgRun);
					}else{
						tagInfo.setFeePrice(price);
						tagInfo.setFeeType(feeType);
						tagInfo.setFeeValue(feeValue);
						tagInfo.setTrialFlag(trialFlag);
						tagInfo.setTrialPrice(trialPrice);
						tagInfo.setTrialType(trialType);
						tagInfo.setTrialValue(trialValue);
			            tagInfo.setFeechannel(feechannel);   
			            tagInfo.setFeechannel1(feechannel1);   
					}

					
					AppPackage pack = new AppPackage();
					String filename_new = Long.toString(System.currentTimeMillis()+1) + ".dat";
					String packFile = SystemParas.getAppPath() + "/" + filename_new;
					if(pack.packFile(packVersion,tagInfo,packFile)){
						File file = new File(SystemParas.getAppPath() + "/" + tempFile);
						if(file.exists())
						{
							file.delete();
						}
						File file1 = new File(packFile);
						ver.setValue("SavePath",packFile);
						ver.setValue("FileSize",Integer.toString((int)file1.length()));
						if(ver.insertAppVersion()){
							sversion.setItemValue("app_version_id",Integer.toString(Integer.parseInt(version_id)+1));
							FileSystem fs = new FileSystem();
							fs.copyFile(packFile,SystemParas.getAppPath_bak() + "/" + filename_new);
							fs.copyFile(packFile,SystemParas.getAppPath_pri() + "/" + filename_new);
							strErrorInfo = LangAction.langAction.getSuccess_upload();
							insertSucc = true;
						}else{
							strErrorInfo = LangAction.langAction.getFailed_insert();
						}
					}else{
						strErrorInfo = LangAction.langAction.getFailed_package();
					}
						
					if(insertSucc){
						WorkFlow flow = new WorkFlow();
						String subject = LangWorkflow.langWF.getWFTitle(wfType) + "["+strAddUser+"]:"+appId;
						flow.setValue("FlowType", wfType);
						flow.setValue("ImportanceLevel", LangWorkflow.langWF.getLevel_high());
						flow.setValue("SecretLevel", LangWorkflow.langWF.getLevel_normal());
						flow.setValue("Subject", subject);
						flow.setValue("Content", ver.toString());
						flow.setValue("ShortString1", ver.getValue("VerId"));
						flow.setValue("CreateStaff", strAddUser);
						flow.setValue("CreateTime", DateUtil.getFullDateTime());
						flowId = flow.addWorkFlow();
						if(flowId != null){
							WFNode node = new WFNode();
							WFNode nodes[] = node.getNodes(flow.getValue("FlowType"));
							if(nodes != null){
								for(int i=0;i<nodes.length;i++){
									SubWorkFlow sub = new SubWorkFlow();
									sub.setValue("FlowId", flowId);
									sub.setValue("SeqNo", nodes[i].getValue("SeqNo"));
									sub.setValue("SubName", nodes[i].getValue("NodeName"));
									if(nodes[i].getValue("SeqNo").equals("1")){
										sub.setValue("HandleStaff", strAddUser);
										sub.setValue("HandleResult", SubWorkFlow.OA_WORKFLOW_SUBRESULT_OPEN);
										sub.setValue("HandleTime", DateUtil.getFullDateTime());
									}else{
										sub.setValue("HandleStaff", "");
										sub.setValue("HandleResult", SubWorkFlow.OA_WORKFLOW_SUBRESULT_CLOSE);
										sub.setValue("HandleTime", "2000-01-01 00:00:00");
									}
									sub.setValue("HandleOpinion", "");
									sub.setValue("Remark", "");
									sub.insert();
								}
							}
							wfStatus = 1;
						}else{
							ver.delete();
							strErrorInfo = LangWorkflow.langWF.getFailed_create_workflow();
						}
					}
				}else{
					strErrorInfo = LangAction.langAction.getNoselect_uploadfile(); 
				}
			}
			
		}else{
			strErrorInfo = LangPage.langPage.getNoselect_screentype();
		}
		
	}
%>
<html>

<head>
<TITLE><%=LangPage.langPage.getPageTitle("newVersion")%></TITLE>
	<meta http-equiv="Pragma" content="no-cache">
	<SCRIPT language="JavaScript" type="text/javascript" src="../../js_gb/jwdf_check.js"></SCRIPT>
	<link rel="stylesheet" type="text/css" href="../../css/jwdf_main.css">
	<link rel="stylesheet" type="text/css" href="../../css/jwdf_swin.css">
	<SCRIPT language="JavaScript" type="text/javascript" src="../../<%=LangPage.langPage.getJs_path()%>jwdf_util.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../../<%=LangPage.langPage.getJs_path()%>jwdf_xml.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../../<%=LangPage.langPage.getJs_path()%>jwdf_view.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../../<%=LangPage.langPage.getJs_path()%>jwdf_swin.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../../<%=LangPage.langPage.getJs_path()%>sps_workflow_u1.js"></SCRIPT>
	<script language=javascript>
		function newSubmit(){
			if(NewForm.VreVersion.value==""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=appver.getAliasByFiled("VREVersion")%>");
				NewForm.VreVersion.focus();
				return;
			}else{
				var temp = NewForm.VreVersion.value;
				var reg=/^((([0]?[0-9]?[0-9]){1}|(1[0-2][0-7]){1})\.){2}(([0]?[0-9]?[0-9]){1}|(1[0-2][0-7]){1})$/;
				if(reg.test(temp)){
					NewForm.submit();
				}else{
					alert("<%=LangAction.langAction.getVreVersion_format_wrong()%>");
				}
			}
		}
		
		function setScreen(){
			type = NewForm.Screen.value;
			if(type == 1){
				NewForm.ScreenWidth.value="176";
				NewForm.ScreenHeight.value="220";
			}else if(type == 2){
				NewForm.ScreenWidth.value="240";
				NewForm.ScreenHeight.value="320";
			}else if(type == 4){
				NewForm.ScreenWidth.value="240";
				NewForm.ScreenHeight.value="400";
			}else if(type == 0){
				NewForm.ScreenWidth.value="0";
				NewForm.ScreenHeight.value="0";
			}else{
				NewForm.ScreenWidth.value="0";
				NewForm.ScreenHeight.value="0";
			} 
		}   

		function showChannel(){	 
		    sendG("../../GetCMCCChannel2x.do",getChannelResult);
		}
		function getChannelResult(cartXML){

		 	var cart = cartXML.getElementsByTagName("result")[0];
			var list = cart.getElementsByTagName("list")[0];
			var rows = list.getElementsByTagName("row");
			NewForm.FeeChannel.options.length = 0;
			NewForm.FeeChannel.add(document.createElement("OPTION"));
			NewForm.FeeChannel.options[0].text="";
			NewForm.FeeChannel.options[0].value="";
			for(var i=0;i<rows.length;i++){
				var key = rows[i].getElementsByTagName("key")[0].firstChild.nodeValue;
				var field = rows[i].getElementsByTagName("field")[0].firstChild.nodeValue;
				NewForm.FeeChannel.add(document.createElement("OPTION"));
				NewForm.FeeChannel.options[i+1].text=field;
			    NewForm.FeeChannel.options[i+1].value=key;
			   
			}
		}

		function showChannel1(){	 
		    sendG("../../GetUNChannel2x.do",getChannelResult1);
		}
		function getChannelResult1(cartXML){

		 	var cart = cartXML.getElementsByTagName("result")[0];
			var list = cart.getElementsByTagName("list")[0];
			var rows = list.getElementsByTagName("row");
			NewForm.FeeChannel1.options.length = 0;
			NewForm.FeeChannel1.add(document.createElement("OPTION"));
			NewForm.FeeChannel1.options[0].text="";
			NewForm.FeeChannel1.options[0].value="";
			for(var i=0;i<rows.length;i++){
				var key = rows[i].getElementsByTagName("key")[0].firstChild.nodeValue;
				var field = rows[i].getElementsByTagName("field")[0].firstChild.nodeValue;
				NewForm.FeeChannel1.add(document.createElement("OPTION"));
				NewForm.FeeChannel1.options[i+1].text=field;
			    NewForm.FeeChannel1.options[i+1].value=key;
			   
			}
		}
		
		function showForm(){
			if(document.all["PackageVersion"].value == "3.0"){
				document.all["div_form"].innerHTML = app30HTML;
			}else if(document.all["PackageVersion"].value == "2.3"){
				document.all["div_form"].innerHTML = app23HTML;
			    showChannel();
			    showChannel1();
			}else if(document.all["PackageVersion"].value == "3.3"){
				document.all["div_form"].innerHTML = app33HTML;
			    showChannel();
			    showChannel1();
			}else if(document.all["PackageVersion"].value == "2.2"){
				document.all["div_form"].innerHTML = app22HTML;
			    showChannel();
			}else if(document.all["PackageVersion"].value == "2.1"){
				document.all["div_form"].innerHTML = app21HTML;
			}else if(document.all["PackageVersion"].value == "2.0"){
				document.all["div_form"].innerHTML = app20HTML;
			}else if(document.all["PackageVersion"].value == "AS3.0"){
				document.all["div_form"].innerHTML = as30HTML;
				NewForm.AppName.value = "AppStore";
				NewForm.AppNameBig5.value = "AppStore";
				NewForm.AppNameEn.value = "AppStore";
			}else if(document.all["PackageVersion"].value == "AS2.0"){
				document.all["div_form"].innerHTML = as20HTML;
				NewForm.AppName.value = "AppStore";
			}
		}
		var app33HTML = "";
		var app30HTML = "";
		var app23HTML = "";
		var app22HTML = "";
		var app21HTML = "";
		var app20HTML = "";
		
		function init(){
			app33HTML = document.all["form_app_33"].innerHTML;
			document.all["form_app_33"].innerHTML = "";
			
			app30HTML = document.all["form_app_30"].innerHTML;
			document.all["form_app_30"].innerHTML = "";

			app23HTML = document.all["form_app_23"].innerHTML;
			document.all["form_app_23"].innerHTML = "";
			
			app22HTML = document.all["form_app_22"].innerHTML;
			document.all["form_app_22"].innerHTML = "";

			app21HTML = document.all["form_app_21"].innerHTML;
			document.all["form_app_21"].innerHTML = "";

			app20HTML = document.all["form_app_20"].innerHTML;
			document.all["form_app_20"].innerHTML = "";

			showForm();

			<%if(wfStatus == 1){%>
			cur_flowid = <%=flowId%>;
			openWFNodeSet();
			<%}%>					
		}
  </script>  
</head>

<body scroll="no" onload="init();">
	<table id="tb_new" class="table_edit" cellpadding="0" cellspacing="0" align="center">
		<tr>
			<td>
				<table class="table_detaillist" cellpadding="0" cellspacing="1" align="center">
					<tr>
						<td height="20" colspan="1" bgcolor="#8acef5"><b><%=LangPage.langPage.getWindowsTitle("app_appversion")%></b></td>
						<td height="20" align="right" colspan="3" bgcolor="#8acef5" style="color:red;"><%=strErrorInfo%></td>
					</tr>
					<tr>
						<td colspan="4" class="td_detailcontent1" style="color:red;">
							选择打包版本：<select name="PackageVersion" onchange="showForm();">
								<option <%if(packVersion.equals("3.3")){%> selected<%}%> value="3.3">App 3.3</option>
								<option <%if(packVersion.equals("3.0")){%> selected<%}%> value="3.0">App 3.0</option>
								<option <%if(packVersion.equals("2.3")){%> selected<%}%> value="2.3">App 2.3</option>
								<option <%if(packVersion.equals("2.2")){%> selected<%}%> value="2.2">App 2.2</option>
								<option <%if(packVersion.equals("2.1")){%> selected<%}%> value="2.1">App 2.1</option>
								<option <%if(packVersion.equals("2.0")){%> selected<%}%> value="2.0">App 2.0</option>
							</select>
						</td>
					</tr>
				</table>
			</td>
		</tr>
	</table>

	<div id="div_form">
	</div>
	<div align="center" id="form_app_33" class="datainfo">
		<table id="tb_new" class="table_edit" cellpadding="0" cellspacing="0" align="center">
		<tr>
			<td>
				<table class="table_detaillist" cellpadding="0" cellspacing="1" align="center">
				<form method="POST" action="newVersion.jsp?AppId=<%=appId%>&edit=1" name="NewForm" ENCTYPE="multipart/form-data">
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("VerType")%></td>
						<td class="td_detailcontent0">
							<input type="hidden" name="PackVersion" value="3.3">
							<select name="VerType">
								<option<%if(verType.equals("1")){%> selected<%}%> value="1"><%=LangPage.langPage.getSelect("app_type")%></option>
								<option<%if(verType.equals("2")){%> selected<%}%> value="2"><%=LangPage.langPage.getSelect("app_mobile")%></option>
							</select>
						</td>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("AppVersion")%></td>
						<td class="td_detailcontent0">
							<input class="input_edit" style="width:100%;" onkeydown="enterFloat();" type="text" name="Version" value="<%=version%>">
						</td>
					</tr>
					<tr>
						<td width="15%" class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("Rank")%></td>
						<td width="35%" class="td_detailcontent0">
							<select name="Rank">
								<option<%if(rank.equals("1")){%> selected<%}%> value="1"><%=LangPage.langPage.getSelect("rank_first")%></option>
								<option<%if(rank.equals("2")){%> selected<%}%> value="2"><%=LangPage.langPage.getSelect("rank_sec")%></option>
								<option<%if(rank.equals("3")){%> selected<%}%> value="3"><%=LangPage.langPage.getSelect("rank_thir")%></option>
								<option<%if(rank.equals("4")){%> selected<%}%> value="4"><%=LangPage.langPage.getSelect("rank_four")%></option>
								<option<%if(rank.equals("5")){%> selected<%}%> value="5"><%=LangPage.langPage.getSelect("rank_five")%></option>
							</select>
						</td>
						<td width="15%" class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("MemorySize")%></td>
						<td width="35%" class="td_detailcontent0" width="200">
							<select name="Memery">
								<option<%if(memery.equals("400")){%> selected<%}%> value="400">400K</option>
								<option<%if(memery.equals("500")){%> selected<%}%> value="500">500K</option>
								<option<%if(memery.equals("600")){%> selected<%}%> value="600">600K</option>
								<option<%if(memery.equals("800")){%> selected<%}%> value="800">800K</option>
								<option<%if(memery.equals("1000")){%> selected<%}%> value="1000">1000K</option>
								<option<%if(memery.equals("1536")){%> selected<%}%> value="1536">1.5M</option>
								<option<%if(memery.equals("3072")){%> selected<%}%> value="3072">3M</option>
							</select>
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("CertId")%></td>
						<td class="td_detailcontent0">
							<select name="CertId">
								<option<%if(certId.equals("5")){%> selected<%}%> value="5"><%=LangPage.langPage.getSelect("cert_fivecert")%></option>
								<option<%if(certId.equals("6")){%> selected<%}%> value="6"><%=LangPage.langPage.getSelect("cert_sixcert")%></option>
								<option<%if(certId.equals("7")){%> selected<%}%> value="7"><%=LangPage.langPage.getSelect("cert_severcert")%></option>
								<option<%if(certId.equals("8")){%> selected<%}%> value="8"><%=LangPage.langPage.getSelect("cert_eightcert")%></option>
								<option<%if(certId.equals("9")){%> selected<%}%> value="9"><%=LangPage.langPage.getSelect("cert_ninecert")%></option>
								<option<%if(certId.equals("10")){%> selected<%}%> value="10"><%=LangPage.langPage.getSelect("cert_tencert")%></option>
								<option<%if(certId.equals("11")){%> selected<%}%> value="11"><%=LangPage.langPage.getSelect("cert_elvencert")%></option>
								<option<%if(certId.equals("12")){%> selected<%}%> value="12"><%=LangPage.langPage.getSelect("cert_twecert")%></option>
								<option<%if(certId.equals("13")){%> selected<%}%> value="13"><%=LangPage.langPage.getSelect("cert_thirteencert")%></option>
								<option<%if(certId.equals("14")){%> selected<%}%> value="14"><%=LangPage.langPage.getSelect("cert_fourteencert")%></option>
								<option<%if(certId.equals("15")){%> selected<%}%> value="15"><%=LangPage.langPage.getSelect("cert_fifteencert")%></option>
							</select>
						</td>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("CertDate")%></td>
						<td class="td_detailcontent0">
							<input class="input_edit" style="width:100%;" onkeydown="enterUnsigned();" type="text" name="CertDate" value="<%=certDate%>">
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("ScreenType")%></td>
						<td colspan="3" class="td_detailcontent0">
							<input type="checkbox"<%if(sc_qqvga!=null){out.print(" checked");}%> name="QQVGA">QQVGA&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_qcif!=null){out.print(" checked");}%> name="QCIF">QCIF&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_qvga!=null){out.print(" checked");}%> name="QVGA">QVGA&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_wqvga!=null){out.print(" checked");}%> name="WQVGA">WQVGA&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_hvga!=null){out.print(" checked");}%> name="HVGA">HVGA<br>
							<input type="checkbox"<%if(sc_qqvga_ls!=null){out.print(" checked");}%> name="QQVGA-LS">QQVGA-LS&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_qcif_ls!=null){out.print(" checked");}%> name="QCIF-LS">QCIF-LS&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_qvga_ls!=null){out.print(" checked");}%> name="QVGA-LS">QVGA-LS&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_wqvga_ls!=null){out.print(" checked");}%> name="WQVGA-LS">WQVGA-LS&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_hvga_ls!=null){out.print(" checked");}%> name="HVGA-LS">HVGA-LS<br>
							<input type="checkbox"<%if(sc_other!=null){out.print(" checked");}%> name="OtherScreen">Other&nbsp;&nbsp;&nbsp;<%=LangPage.langPage.getSelect("screen_width")%><input type="text" name="ScreenWidth" onkeydown="enterUnsigned();" style="width:80;" value="<%=screenWidth%>">&nbsp;&nbsp;<%=LangPage.langPage.getSelect("screen_height")%><input type="text" name="ScreenHeight" onkeydown="enterUnsigned();" style="width:80;" value="<%=screenHeight%>">
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("MTKVersion")%></td>
						<td colspan="3" class="td_detailcontent0">
							<input type="checkbox"<%if(mtk_08A !=null){out.print(" checked");}%> name="08A">08A&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(mtk_08B !=null){out.print(" checked");}%> name="08B">08B&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(mtk_09A !=null){out.print(" checked");}%> name="09A">09A&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(mtk_09B !=null){out.print(" checked");}%> name="09B">09B
						</td>
					</tr>	
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("ChipVersion")%></td>
						<td colspan="3" class="td_detailcontent0">
							<input type="checkbox"<%if(chip_6223 !=null){out.print(" checked");}%> name="6223">6223&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(chip_6225 !=null){out.print(" checked");}%> name="6225">6225&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(chip_6235 !=null){out.print(" checked");}%> name="6235">6235&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(chip_6238 !=null){out.print(" checked");}%> name="6238">6238&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(chip_6253 !=null){out.print(" checked");}%> name="6253">6253
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("InputDC")%></td>
						<td colspan="3" class="td_detailcontent0">
							<input type="checkbox"<%if(input_keypad!=null){out.print(" checked");}%> name="Input_Keypad"><%=LangPage.langPage.getSelect("screen_keypad")%>&nbsp;&nbsp;
							<input type="checkbox"<%if(input_touch!=null){out.print(" checked");}%> name="Input_Touch"><%=LangPage.langPage.getSelect("screen_touch")%>
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("FeeGroupId")%></td>
						<td class="td_detailcontent0">
							<select name="FeeGroupId">
								<option<%if(feeGroupId.equals("0")){%> selected<%}%> value="0"><%=LangPage.langPage.getSelect("group_zero")%></option>
								<option<%if(feeGroupId.equals("1")){%> selected<%}%> value="1"><%=LangPage.langPage.getSelect("group_first")%></option>
								<option<%if(feeGroupId.equals("2")){%> selected<%}%> value="2"><%=LangPage.langPage.getSelect("group_two")%></option>
								<option<%if(feeGroupId.equals("3")){%> selected<%}%> value="3"><%=LangPage.langPage.getSelect("group_three")%></option>
								<option<%if(feeGroupId.equals("4")){%> selected<%}%> value="4"><%=LangPage.langPage.getSelect("group_four")%></option>
								<option<%if(feeGroupId.equals("5")){%> selected<%}%> value="5"><%=LangPage.langPage.getSelect("group_five")%></option>
								<option<%if(feeGroupId.equals("6")){%> selected<%}%> value="6"><%=LangPage.langPage.getSelect("group_six")%></option>
								<option<%if(feeGroupId.equals("7")){%> selected<%}%> value="7"><%=LangPage.langPage.getSelect("group_seven")%></option>
								<option<%if(feeGroupId.equals("8")){%> selected<%}%> value="8"><%=LangPage.langPage.getSelect("group_eight")%></option>
								<option<%if(feeGroupId.equals("9")){%> selected<%}%> value="9"><%=LangPage.langPage.getSelect("group_nine")%></option>
								<option<%if(feeGroupId.equals("10")){%> selected<%}%> value="10"><%=LangPage.langPage.getSelect("group_ten")%></option>
								<option<%if(feeGroupId.equals("11")){%> selected<%}%> value="11"><%=LangPage.langPage.getSelect("group_elven")%></option>
								<option<%if(feeGroupId.equals("12")){%> selected<%}%> value="12"><%=LangPage.langPage.getSelect("group_twlve")%></option>
								<option<%if(feeGroupId.equals("13")){%> selected<%}%> value="13"><%=LangPage.langPage.getSelect("group_thirteen")%></option>
								<option<%if(feeGroupId.equals("14")){%> selected<%}%> value="14"><%=LangPage.langPage.getSelect("group_fourteen")%></option>
								<option<%if(feeGroupId.equals("15")){%> selected<%}%> value="15"><%=LangPage.langPage.getSelect("group_fifteen")%></option>
							</select>
						</td>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("VREVersion")%></td>
						<td class="td_detailcontent0">
							<input class="input_edit" style="width:100%;" onkeydown="enterFloat();" type="text" name="VreVersion" value="<%=vreVersion%>">
						</td>
					</tr>	

					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("FeeChannel")%>-移动</td>
						<td class="td_detailcontent0">
							<select name="FeeChannel">
								<option value=""></option> 
							</select>
						</td>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("FeeChannel")%>-联通</td>
						<td class="td_detailcontent0">
							<select name="FeeChannel1">
								<option value=""></option> 
							</select>
						</td>
					</tr>							
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("Permission")%></td>
						<td colspan="3" class="td_detailcontent0">
							<input type="checkbox"<%if(perm_5000!=null){out.print(" checked");}%> name="5000">PER_AUDIO_PLAY&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5001!=null){out.print(" checked");}%> name="5001">PER_CALL_OUT&nbsp;
							<input type="checkbox"<%if(perm_5002!=null){out.print(" checked");}%> name="5002">PER_CAMERA&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5003!=null){out.print(" checked");}%> name="5003">PER_FILE<br>
							<input type="checkbox"<%if(perm_5004!=null){out.print(" checked");}%> name="5004">PER_HTTP&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5005!=null){out.print(" checked");}%> name="5005">PER_RECORD&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5006!=null){out.print(" checked");}%> name="5006">PER_SENSOR&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5007!=null){out.print(" checked");}%> name="5007">PER_SIM<br>
							<input type="checkbox"<%if(perm_5008!=null){out.print(" checked");}%> name="5008">PER_SMS_PER&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5009!=null){out.print(" checked");}%> name="5009">PER_SMS_SP&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5010!=null){out.print(" checked");}%> name="5010">PER_TCP&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5011!=null){out.print(" checked");}%> name="5011">PER_APPSTORE<br>
							<input type="checkbox"<%if(perm_5012!=null){out.print(" checked");}%> name="5012">PER_BILLING
							<input type="checkbox"<%if(perm_5013!=null){out.print(" checked");}%> name="5013">PER_BITSTREAM
							<input type="checkbox"<%if(perm_5014!=null){out.print(" checked");}%> name="5014">PER_CONTACT
							<input type="checkbox"<%if(perm_5015!=null){out.print(" checked");}%> name="5015">PER_LBS
							<input type="checkbox"<%if(perm_5016!=null){out.print(" checked");}%> name="5016">PER_MMS<br>
							<input type="checkbox"<%if(perm_5017!=null){out.print(" checked");}%> name="5017">PER_PRO
							<input type="checkbox"<%if(perm_5018!=null){out.print(" checked");}%> name="5018">PER_SMSMNG
							<input type="checkbox"<%if(perm_5019!=null){out.print(" checked");}%> name="5019">PER_VIDEO
							<input type="checkbox"<%if(perm_5020!=null){out.print(" checked");}%> name="5020">PER_XML<br>
						</td>
					</tr>
			
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("MobileList")%></td>
						<td colspan="3" class="td_detailcontent0"><textarea name="MobileList" class="input_textarea"><%=mobileList%></textarea></td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("FileName")%></td>
						<td colspan="3" class="td_detailcontent0">
							<input class="input_edit" type="file" name="UploadFile" value="" style="width:400;"></input>
						</td>
					</tr>					
					<tr>
						<td class="td_detailcontent1" align="center"><%=LangPage.langPage.getBackground_run()%></td>
						<td colspan="3" class="td_detailcontent0">
							<select name="BGRun">
								<option<%if(bgRun.equals("0")){%> selected<%}%> value="0"><%=LangPage.langPage.getSelect("bgrun_no")%></option>
								<option<%if(bgRun.equals("1")){%> selected<%}%> value="1"><%=LangPage.langPage.getSelect("bgrun_yes")%></option>
							</select>
						</td>
					</tr>
					<tr>
						<td colspan="4" align="center" valign="middle" class="td_editbutton">
							<a href="#" onclick="newSubmit();"><img src="../../<%=LangPage.langPage.getButton_img_path()%>submit_001.gif" border="0" align="top" vspace="1" /></a>
						</td>
					</tr>
				</form>
				</table>
			</td>
		</tr>
	</table>

	</div>



	<div align="center" id="form_app_30" class="datainfo">
	<table id="tb_new" class="table_edit" cellpadding="0" cellspacing="0" align="center">
		<tr>
			<td>
				<table class="table_detaillist" cellpadding="0" cellspacing="1" align="center">
				<form method="POST" action="newVersion.jsp?AppId=<%=appId%>&edit=1" name="NewForm" ENCTYPE="multipart/form-data">
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("VerType")%></td>
						<td class="td_detailcontent0">
							<input type="hidden" name="PackVersion" value="3.0">
							<select name="VerType">
								<option<%if(verType.equals("1")){%> selected<%}%> value="1"><%=LangPage.langPage.getSelect("app_type")%></option>
								<option<%if(verType.equals("2")){%> selected<%}%> value="2"><%=LangPage.langPage.getSelect("app_mobile")%></option>
							</select>
						</td>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("AppVersion")%></td>
						<td class="td_detailcontent0">
							<input class="input_edit" style="width:100%;" onkeydown="enterFloat();" type="text" name="Version" value="<%=version%>">
						</td>
					</tr>
					<tr>
						<td width="15%" class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("Rank")%></td>
						<td width="35%" class="td_detailcontent0">
							<select name="Rank">
								<option<%if(rank.equals("1")){%> selected<%}%> value="1"><%=LangPage.langPage.getSelect("rank_first")%></option>
								<option<%if(rank.equals("2")){%> selected<%}%> value="2"><%=LangPage.langPage.getSelect("rank_sec")%></option>
								<option<%if(rank.equals("3")){%> selected<%}%> value="3"><%=LangPage.langPage.getSelect("rank_thir")%></option>
								<option<%if(rank.equals("4")){%> selected<%}%> value="4"><%=LangPage.langPage.getSelect("rank_four")%></option>
								<option<%if(rank.equals("5")){%> selected<%}%> value="5"><%=LangPage.langPage.getSelect("rank_five")%></option>
							</select>
						</td>
						<td width="15%" class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("MemorySize")%></td>
						<td width="35%" class="td_detailcontent0" width="200">
							<select name="Memery">
								<option<%if(memery.equals("400")){%> selected<%}%> value="400">400K</option>
								<option<%if(memery.equals("500")){%> selected<%}%> value="500">500K</option>
								<option<%if(memery.equals("600")){%> selected<%}%> value="600">600K</option>
								<option<%if(memery.equals("800")){%> selected<%}%> value="800">800K</option>
								<option<%if(memery.equals("1000")){%> selected<%}%> value="1000">1000K</option>
								<option<%if(memery.equals("1536")){%> selected<%}%> value="1536">1.5M</option>
								<option<%if(memery.equals("3072")){%> selected<%}%> value="3072">3M</option>
							</select>
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("CertId")%></td>
						<td class="td_detailcontent0">
							<select name="CertId">
								<option<%if(certId.equals("5")){%> selected<%}%> value="5"><%=LangPage.langPage.getSelect("cert_fivecert")%></option>
								<option<%if(certId.equals("6")){%> selected<%}%> value="6"><%=LangPage.langPage.getSelect("cert_sixcert")%></option>
								<option<%if(certId.equals("7")){%> selected<%}%> value="7"><%=LangPage.langPage.getSelect("cert_severcert")%></option>
								<option<%if(certId.equals("8")){%> selected<%}%> value="8"><%=LangPage.langPage.getSelect("cert_eightcert")%></option>
								<option<%if(certId.equals("9")){%> selected<%}%> value="9"><%=LangPage.langPage.getSelect("cert_ninecert")%></option>
								<option<%if(certId.equals("10")){%> selected<%}%> value="10"><%=LangPage.langPage.getSelect("cert_tencert")%></option>
								<option<%if(certId.equals("11")){%> selected<%}%> value="11"><%=LangPage.langPage.getSelect("cert_elvencert")%></option>
								<option<%if(certId.equals("12")){%> selected<%}%> value="12"><%=LangPage.langPage.getSelect("cert_twecert")%></option>
								<option<%if(certId.equals("13")){%> selected<%}%> value="13"><%=LangPage.langPage.getSelect("cert_thirteencert")%></option>
								<option<%if(certId.equals("14")){%> selected<%}%> value="14"><%=LangPage.langPage.getSelect("cert_fourteencert")%></option>
								<option<%if(certId.equals("15")){%> selected<%}%> value="15"><%=LangPage.langPage.getSelect("cert_fifteencert")%></option>
							</select>
						</td>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("CertDate")%></td>
						<td class="td_detailcontent0">
							<input class="input_edit" style="width:100%;" onkeydown="enterUnsigned();" type="text" name="CertDate" value="<%=certDate%>">
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("ScreenType")%></td>
						<td colspan="3" class="td_detailcontent0">
							<input type="checkbox"<%if(sc_qqvga!=null){out.print(" checked");}%> name="QQVGA">QQVGA&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_qcif!=null){out.print(" checked");}%> name="QCIF">QCIF&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_qvga!=null){out.print(" checked");}%> name="QVGA">QVGA&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_wqvga!=null){out.print(" checked");}%> name="WQVGA">WQVGA&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_hvga!=null){out.print(" checked");}%> name="HVGA">HVGA<br>
							<input type="checkbox"<%if(sc_qqvga_ls!=null){out.print(" checked");}%> name="QQVGA-LS">QQVGA-LS&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_qcif_ls!=null){out.print(" checked");}%> name="QCIF-LS">QCIF-LS&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_qvga_ls!=null){out.print(" checked");}%> name="QVGA-LS">QVGA-LS&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_wqvga_ls!=null){out.print(" checked");}%> name="WQVGA-LS">WQVGA-LS&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_hvga_ls!=null){out.print(" checked");}%> name="HVGA-LS">HVGA-LS<br>
							<input type="checkbox"<%if(sc_other!=null){out.print(" checked");}%> name="OtherScreen">Other&nbsp;&nbsp;&nbsp;<%=LangPage.langPage.getSelect("screen_width")%><input type="text" name="ScreenWidth" onkeydown="enterUnsigned();" style="width:80;" value="<%=screenWidth%>">&nbsp;&nbsp;<%=LangPage.langPage.getSelect("screen_height")%><input type="text" name="ScreenHeight" onkeydown="enterUnsigned();" style="width:80;" value="<%=screenHeight%>">
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("MTKVersion")%></td>
						<td colspan="3" class="td_detailcontent0">
							<input type="checkbox"<%if(mtk_08A !=null){out.print(" checked");}%> name="08A">08A&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(mtk_08B !=null){out.print(" checked");}%> name="08B">08B&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(mtk_09A !=null){out.print(" checked");}%> name="09A">09A&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(mtk_09B !=null){out.print(" checked");}%> name="09B">09B
						</td>
					</tr>	
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("ChipVersion")%></td>
						<td colspan="3" class="td_detailcontent0">
							<input type="checkbox"<%if(chip_6223 !=null){out.print(" checked");}%> name="6223">6223&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(chip_6225 !=null){out.print(" checked");}%> name="6225">6225&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(chip_6235 !=null){out.print(" checked");}%> name="6235">6235&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(chip_6238 !=null){out.print(" checked");}%> name="6238">6238&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(chip_6253 !=null){out.print(" checked");}%> name="6253">6253
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("InputDC")%></td>
						<td colspan="3" class="td_detailcontent0">
							<input type="checkbox"<%if(input_keypad!=null){out.print(" checked");}%> name="Input_Keypad"><%=LangPage.langPage.getSelect("screen_keypad")%>&nbsp;&nbsp;
							<input type="checkbox"<%if(input_touch!=null){out.print(" checked");}%> name="Input_Touch"><%=LangPage.langPage.getSelect("screen_touch")%>
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("FeeGroupId")%></td>
						<td class="td_detailcontent0">
							<select name="FeeGroupId">
								<option<%if(feeGroupId.equals("0")){%> selected<%}%> value="0"><%=LangPage.langPage.getSelect("group_zero")%></option>
								<option<%if(feeGroupId.equals("1")){%> selected<%}%> value="1"><%=LangPage.langPage.getSelect("group_first")%></option>
								<option<%if(feeGroupId.equals("2")){%> selected<%}%> value="2"><%=LangPage.langPage.getSelect("group_two")%></option>
								<option<%if(feeGroupId.equals("3")){%> selected<%}%> value="3"><%=LangPage.langPage.getSelect("group_three")%></option>
								<option<%if(feeGroupId.equals("4")){%> selected<%}%> value="4"><%=LangPage.langPage.getSelect("group_four")%></option>
								<option<%if(feeGroupId.equals("5")){%> selected<%}%> value="5"><%=LangPage.langPage.getSelect("group_five")%></option>
								<option<%if(feeGroupId.equals("6")){%> selected<%}%> value="6"><%=LangPage.langPage.getSelect("group_six")%></option>
								<option<%if(feeGroupId.equals("7")){%> selected<%}%> value="7"><%=LangPage.langPage.getSelect("group_seven")%></option>
								<option<%if(feeGroupId.equals("8")){%> selected<%}%> value="8"><%=LangPage.langPage.getSelect("group_eight")%></option>
								<option<%if(feeGroupId.equals("9")){%> selected<%}%> value="9"><%=LangPage.langPage.getSelect("group_nine")%></option>
								<option<%if(feeGroupId.equals("10")){%> selected<%}%> value="10"><%=LangPage.langPage.getSelect("group_ten")%></option>
								<option<%if(feeGroupId.equals("11")){%> selected<%}%> value="11"><%=LangPage.langPage.getSelect("group_elven")%></option>
								<option<%if(feeGroupId.equals("12")){%> selected<%}%> value="12"><%=LangPage.langPage.getSelect("group_twlve")%></option>
								<option<%if(feeGroupId.equals("13")){%> selected<%}%> value="13"><%=LangPage.langPage.getSelect("group_thirteen")%></option>
								<option<%if(feeGroupId.equals("14")){%> selected<%}%> value="14"><%=LangPage.langPage.getSelect("group_fourteen")%></option>
								<option<%if(feeGroupId.equals("15")){%> selected<%}%> value="15"><%=LangPage.langPage.getSelect("group_fifteen")%></option>
							</select>
						</td>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("VREVersion")%></td>
						<td class="td_detailcontent0">
							<input class="input_edit" style="width:100%;" onkeydown="enterFloat();" type="text" name="VreVersion" value="<%=vreVersion%>">
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("Permission")%></td>
						<td colspan="3" class="td_detailcontent0">
							<input type="checkbox"<%if(perm_5000!=null){out.print(" checked");}%> name="5000">PER_AUDIO_PLAY&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5001!=null){out.print(" checked");}%> name="5001">PER_CALL_OUT&nbsp;
							<input type="checkbox"<%if(perm_5002!=null){out.print(" checked");}%> name="5002">PER_CAMERA&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5003!=null){out.print(" checked");}%> name="5003">PER_FILE<br>
							<input type="checkbox"<%if(perm_5004!=null){out.print(" checked");}%> name="5004">PER_HTTP&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5005!=null){out.print(" checked");}%> name="5005">PER_RECORD&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5006!=null){out.print(" checked");}%> name="5006">PER_SENSOR&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5007!=null){out.print(" checked");}%> name="5007">PER_SIM<br>
							<input type="checkbox"<%if(perm_5008!=null){out.print(" checked");}%> name="5008">PER_SMS_PER&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5009!=null){out.print(" checked");}%> name="5009">PER_SMS_SP&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5010!=null){out.print(" checked");}%> name="5010">PER_TCP&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5011!=null){out.print(" checked");}%> name="5011">PER_APPSTORE<br>
							<input type="checkbox"<%if(perm_5012!=null){out.print(" checked");}%> name="5012">PER_BILLING
							<input type="checkbox"<%if(perm_5013!=null){out.print(" checked");}%> name="5013">PER_BITSTREAM
							<input type="checkbox"<%if(perm_5014!=null){out.print(" checked");}%> name="5014">PER_CONTACT
							<input type="checkbox"<%if(perm_5015!=null){out.print(" checked");}%> name="5015">PER_LBS
							<input type="checkbox"<%if(perm_5016!=null){out.print(" checked");}%> name="5016">PER_MMS<br>
							<input type="checkbox"<%if(perm_5017!=null){out.print(" checked");}%> name="5017">PER_PRO
							<input type="checkbox"<%if(perm_5018!=null){out.print(" checked");}%> name="5018">PER_SMSMNG
							<input type="checkbox"<%if(perm_5019!=null){out.print(" checked");}%> name="5019">PER_VIDEO
							<input type="checkbox"<%if(perm_5020!=null){out.print(" checked");}%> name="5020">PER_XML<br>
						</td>
					</tr>					
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("MobileList")%></td>
						<td colspan="3" class="td_detailcontent0"><textarea name="MobileList" class="input_textarea"><%=mobileList%></textarea></td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("FileName")%></td>
						<td colspan="3" class="td_detailcontent0">
							<input class="input_edit" type="file" name="UploadFile" value="" style="width:400;"></input>
						</td>
					</tr>					
					<tr>
						<td class="td_detailcontent1" align="center"><%=LangPage.langPage.getBackground_run()%></td>
						<td colspan="3" class="td_detailcontent0">
							<select name="BGRun">
								<option<%if(bgRun.equals("0")){%> selected<%}%> value="0"><%=LangPage.langPage.getSelect("bgrun_no")%></option>
								<option<%if(bgRun.equals("1")){%> selected<%}%> value="1"><%=LangPage.langPage.getSelect("bgrun_yes")%></option>
							</select>
						</td>
					</tr>
					<tr>
						<td colspan="4" align="center" valign="middle" class="td_editbutton">
							<a href="#" onclick="newSubmit();"><img src="../../<%=LangPage.langPage.getButton_img_path()%>submit_001.gif" border="0" align="top" vspace="1" /></a>
						</td>
					</tr>
				</form>
				</table>
			</td>
		</tr>
	</table>
	</div>

	<div align="center" id="form_app_23" class="datainfo">
	<table id="tb_new" class="table_edit" cellpadding="0" cellspacing="0" align="center">
		<tr>
			<td>
				<table class="table_detaillist" cellpadding="0" cellspacing="1" align="center">
				<form method="POST" action="newVersion.jsp?AppId=<%=appId%>&edit=1" name="NewForm" ENCTYPE="multipart/form-data">
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("VerType")%></td>
						<td class="td_detailcontent0">
							<input type="hidden" name="PackVersion" value="2.3">
							<select name="VerType">
								<option<%if(verType.equals("1")){%> selected<%}%> value="1"><%=LangPage.langPage.getSelect("app_type")%></option>
								<option<%if(verType.equals("2")){%> selected<%}%> value="2"><%=LangPage.langPage.getSelect("app_mobile")%></option>
							</select>
						</td>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("AppVersion")%></td>
						<td class="td_detailcontent0">
							<input class="input_edit" style="width:100%;" onkeydown="enterFloat();" type="text" name="Version" value="<%=version%>">
						</td>
					</tr>
					<tr>
						<td width="15%" class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("Rank")%></td>
						<td width="35%" class="td_detailcontent0">
							<select name="Rank">
								<option<%if(rank.equals("1")){%> selected<%}%> value="1"><%=LangPage.langPage.getSelect("rank_first")%></option>
								<option<%if(rank.equals("2")){%> selected<%}%> value="2"><%=LangPage.langPage.getSelect("rank_sec")%></option>
								<option<%if(rank.equals("3")){%> selected<%}%> value="3"><%=LangPage.langPage.getSelect("rank_thir")%></option>
								<option<%if(rank.equals("4")){%> selected<%}%> value="4"><%=LangPage.langPage.getSelect("rank_four")%></option>
								<option<%if(rank.equals("5")){%> selected<%}%> value="5"><%=LangPage.langPage.getSelect("rank_five")%></option>
							</select>
						</td>
						<td width="15%" class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("MemorySize")%></td>
						<td width="35%" class="td_detailcontent0" width="200">
							<select name="Memery">
								<option<%if(memery.equals("400")){%> selected<%}%> value="400">400K</option>
								<option<%if(memery.equals("500")){%> selected<%}%> value="500">500K</option>
								<option<%if(memery.equals("600")){%> selected<%}%> value="600">600K</option>
								<option<%if(memery.equals("800")){%> selected<%}%> value="800">800K</option>
								<option<%if(memery.equals("1000")){%> selected<%}%> value="1000">1000K</option>
								<option<%if(memery.equals("1536")){%> selected<%}%> value="1536">1.5M</option>
								<option<%if(memery.equals("3072")){%> selected<%}%> value="3072">3M</option>
							</select>
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("CertId")%></td>
						<td class="td_detailcontent0">
							<select name="CertId">
								<option<%if(certId.equals("5")){%> selected<%}%> value="5"><%=LangPage.langPage.getSelect("cert_fivecert")%></option>
								<option<%if(certId.equals("6")){%> selected<%}%> value="6"><%=LangPage.langPage.getSelect("cert_sixcert")%></option>
								<option<%if(certId.equals("7")){%> selected<%}%> value="7"><%=LangPage.langPage.getSelect("cert_severcert")%></option>
								<option<%if(certId.equals("8")){%> selected<%}%> value="8"><%=LangPage.langPage.getSelect("cert_eightcert")%></option>
								<option<%if(certId.equals("9")){%> selected<%}%> value="9"><%=LangPage.langPage.getSelect("cert_ninecert")%></option>
								<option<%if(certId.equals("10")){%> selected<%}%> value="10"><%=LangPage.langPage.getSelect("cert_tencert")%></option>
								<option<%if(certId.equals("11")){%> selected<%}%> value="11"><%=LangPage.langPage.getSelect("cert_elvencert")%></option>
								<option<%if(certId.equals("12")){%> selected<%}%> value="12"><%=LangPage.langPage.getSelect("cert_twecert")%></option>
								<option<%if(certId.equals("13")){%> selected<%}%> value="13"><%=LangPage.langPage.getSelect("cert_thirteencert")%></option>
								<option<%if(certId.equals("14")){%> selected<%}%> value="14"><%=LangPage.langPage.getSelect("cert_fourteencert")%></option>
								<option<%if(certId.equals("15")){%> selected<%}%> value="15"><%=LangPage.langPage.getSelect("cert_fifteencert")%></option>
							</select>
						</td>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("CertDate")%></td>
						<td class="td_detailcontent0">
							<input class="input_edit" style="width:100%;" onkeydown="enterUnsigned();" type="text" name="CertDate" value="<%=certDate%>">
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("ScreenType")%></td>
						<td colspan="3" class="td_detailcontent0">
							<input type="checkbox"<%if(sc_qqvga!=null){out.print(" checked");}%> name="QQVGA">QQVGA&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_qcif!=null){out.print(" checked");}%> name="QCIF">QCIF&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_qvga!=null){out.print(" checked");}%> name="QVGA">QVGA&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_wqvga!=null){out.print(" checked");}%> name="WQVGA">WQVGA&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_hvga!=null){out.print(" checked");}%> name="HVGA">HVGA<br>
							<input type="checkbox"<%if(sc_qqvga_ls!=null){out.print(" checked");}%> name="QQVGA-LS">QQVGA-LS&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_qcif_ls!=null){out.print(" checked");}%> name="QCIF-LS">QCIF-LS&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_qvga_ls!=null){out.print(" checked");}%> name="QVGA-LS">QVGA-LS&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_wqvga_ls!=null){out.print(" checked");}%> name="WQVGA-LS">WQVGA-LS&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_hvga_ls!=null){out.print(" checked");}%> name="HVGA-LS">HVGA-LS<br>
							<input type="checkbox"<%if(sc_other!=null){out.print(" checked");}%> name="OtherScreen">Other&nbsp;&nbsp;&nbsp;<%=LangPage.langPage.getSelect("screen_width")%><input type="text" name="ScreenWidth" onkeydown="enterUnsigned();" style="width:80;" value="<%=screenWidth%>">&nbsp;&nbsp;<%=LangPage.langPage.getSelect("screen_height")%><input type="text" name="ScreenHeight" onkeydown="enterUnsigned();" style="width:80;" value="<%=screenHeight%>">
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("MTKVersion")%></td>
						<td colspan="3" class="td_detailcontent0">
							<input type="checkbox"<%if(mtk_08A !=null){out.print(" checked");}%> name="08A">08A&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(mtk_08B !=null){out.print(" checked");}%> name="08B">08B&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(mtk_09A !=null){out.print(" checked");}%> name="09A">09A&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(mtk_09B !=null){out.print(" checked");}%> name="09B">09B
						</td>
					</tr>	
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("ChipVersion")%></td>
						<td colspan="3" class="td_detailcontent0">
							<input type="checkbox"<%if(chip_6223 !=null){out.print(" checked");}%> name="6223">6223&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(chip_6225 !=null){out.print(" checked");}%> name="6225">6225&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(chip_6235 !=null){out.print(" checked");}%> name="6235">6235&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(chip_6238 !=null){out.print(" checked");}%> name="6238">6238&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(chip_6253 !=null){out.print(" checked");}%> name="6253">6253
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("InputDC")%></td>
						<td colspan="3" class="td_detailcontent0">
							<input type="checkbox"<%if(input_keypad!=null){out.print(" checked");}%> name="Input_Keypad"><%=LangPage.langPage.getSelect("screen_keypad")%>&nbsp;&nbsp;
							<input type="checkbox"<%if(input_touch!=null){out.print(" checked");}%> name="Input_Touch"><%=LangPage.langPage.getSelect("screen_touch")%>
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("FeeGroupId")%></td>
						<td class="td_detailcontent0">
							<select name="FeeGroupId">
								<option<%if(feeGroupId.equals("0")){%> selected<%}%> value="0"><%=LangPage.langPage.getSelect("group_zero")%></option>
								<option<%if(feeGroupId.equals("1")){%> selected<%}%> value="1"><%=LangPage.langPage.getSelect("group_first")%></option>
								<option<%if(feeGroupId.equals("2")){%> selected<%}%> value="2"><%=LangPage.langPage.getSelect("group_two")%></option>
								<option<%if(feeGroupId.equals("3")){%> selected<%}%> value="3"><%=LangPage.langPage.getSelect("group_three")%></option>
								<option<%if(feeGroupId.equals("4")){%> selected<%}%> value="4"><%=LangPage.langPage.getSelect("group_four")%></option>
								<option<%if(feeGroupId.equals("5")){%> selected<%}%> value="5"><%=LangPage.langPage.getSelect("group_five")%></option>
								<option<%if(feeGroupId.equals("6")){%> selected<%}%> value="6"><%=LangPage.langPage.getSelect("group_six")%></option>
								<option<%if(feeGroupId.equals("7")){%> selected<%}%> value="7"><%=LangPage.langPage.getSelect("group_seven")%></option>
								<option<%if(feeGroupId.equals("8")){%> selected<%}%> value="8"><%=LangPage.langPage.getSelect("group_eight")%></option>
								<option<%if(feeGroupId.equals("9")){%> selected<%}%> value="9"><%=LangPage.langPage.getSelect("group_nine")%></option>
								<option<%if(feeGroupId.equals("10")){%> selected<%}%> value="10"><%=LangPage.langPage.getSelect("group_ten")%></option>
								<option<%if(feeGroupId.equals("11")){%> selected<%}%> value="11"><%=LangPage.langPage.getSelect("group_elven")%></option>
								<option<%if(feeGroupId.equals("12")){%> selected<%}%> value="12"><%=LangPage.langPage.getSelect("group_twlve")%></option>
								<option<%if(feeGroupId.equals("13")){%> selected<%}%> value="13"><%=LangPage.langPage.getSelect("group_thirteen")%></option>
								<option<%if(feeGroupId.equals("14")){%> selected<%}%> value="14"><%=LangPage.langPage.getSelect("group_fourteen")%></option>
								<option<%if(feeGroupId.equals("15")){%> selected<%}%> value="15"><%=LangPage.langPage.getSelect("group_fifteen")%></option>
							</select>
						</td>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("FeePrice")%></td>
						<td class="td_detailcontent0">
							<input class="input_edit" onkeydown="enterUnsigned();" style="width:100%;" type="text" name="Price" value="<%=price%>">
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("FeeType")%></td>
						<td class="td_detailcontent0">
							<select name="FeeType">
								<option<%if(feeType.equals("1")){%> selected<%}%> value="1"><%=LangPage.langPage.getSelect("feetype_day")%></option>
								<option<%if(feeType.equals("2")){%> selected<%}%> value="2"><%=LangPage.langPage.getSelect("feetype_time")%></option>
								<option<%if(feeType.equals("3")){%> selected<%}%> value="3"><%=LangPage.langPage.getSelect("feetype_buy")%></option>
							</select>
						</td>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("FeeValue")%></td>
						<td class="td_detailcontent0">
							<input class="input_edit" style="width:100%;" onkeydown="enterUnsigned();" type="text" name="FeeValue" value="<%=feeValue%>">
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("VREVersion")%></td>
						<td colspan="3" class="td_detailcontent0">
							<input class="input_edit" style="width:100%;" onkeydown="enterFloat();" type="text" name="VreVersion" value="<%=vreVersion%>">
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("FeeChannel")%>-移动</td>
						<td class="td_detailcontent0">
							<select name="FeeChannel">
								<option value=""></option> 
							</select>
						</td>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("FeeChannel")%>-联通</td>
						<td class="td_detailcontent0">
							<select name="FeeChannel1">
								<option value=""></option> 
							</select>
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("TrialFlag")%></td>
						<td class="td_detailcontent0">
							<select name="TrialFlag">
								<option<%if(trialFlag.equals("0")){%> selected<%}%> value="0"><%=LangPage.langPage.getSelect("trial_no")%></option>
								<option<%if(trialFlag.equals("1")){%> selected<%}%> value="1"><%=LangPage.langPage.getSelect("trial_yes")%></option>
							</select>
						</td>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("TrialPrice")%></td>
						<td class="td_detailcontent0">
							<input class="input_edit" style="width:100%;" onkeydown="enterUnsigned();" type="text" name="TrialPrice" value="<%=trialPrice%>">
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("TrialType")%></td>
						<td class="td_detailcontent0">
							<select name="TrialType">
								<option<%if(trialType.equals("1")){%> selected<%}%> value="1"><%=LangPage.langPage.getSelect("feetype_day")%></option>
								<option<%if(trialType.equals("2")){%> selected<%}%> value="2"><%=LangPage.langPage.getSelect("feetype_time")%></option>
							</select>
						</td>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("TrialValue")%></td>
						<td class="td_detailcontent0">
							<input class="input_edit" style="width:100%;" onkeydown="enterUnsigned();" type="text" name="TrialValue" value="<%=trialValue%>">
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("Permission")%></td>
						<td colspan="3" class="td_detailcontent0">
							<input type="checkbox"<%if(perm_5000!=null){out.print(" checked");}%> name="5000">PER_AUDIO_PLAY&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5001!=null){out.print(" checked");}%> name="5001">PER_CALL_OUT&nbsp;
							<input type="checkbox"<%if(perm_5002!=null){out.print(" checked");}%> name="5002">PER_CAMERA&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5003!=null){out.print(" checked");}%> name="5003">PER_FILE<br>
							<input type="checkbox"<%if(perm_5004!=null){out.print(" checked");}%> name="5004">PER_HTTP&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5005!=null){out.print(" checked");}%> name="5005">PER_RECORD&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5006!=null){out.print(" checked");}%> name="5006">PER_SENSOR&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5007!=null){out.print(" checked");}%> name="5007">PER_SIM<br>
							<input type="checkbox"<%if(perm_5008!=null){out.print(" checked");}%> name="5008">PER_SMS_PER&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5009!=null){out.print(" checked");}%> name="5009">PER_SMS_SP&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5010!=null){out.print(" checked");}%> name="5010">PER_TCP&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5011!=null){out.print(" checked");}%> name="5011">PER_APPSTORE<br>
						</td>
					</tr>					
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("MobileList")%></td>
						<td colspan="3" class="td_detailcontent0"><textarea name="MobileList" class="input_textarea"><%=mobileList%></textarea></td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("FileName")%></td>
						<td colspan="3" class="td_detailcontent0">
							<input class="input_edit" type="file" name="UploadFile" value="" style="width:400;"></input>
						</td>
					</tr>					
					<tr>
						<td colspan="4" align="center" valign="middle" class="td_editbutton">
							<a href="#" onclick="newSubmit();"><img src="../../<%=LangPage.langPage.getButton_img_path()%>submit_001.gif" border="0" align="top" vspace="1" /></a>
						</td>
					</tr>
				</form>
				</table>
			</td>
		</tr>
	</table>
	</div>

	<div align="center" id="form_app_22" class="datainfo">
	<table id="tb_new" class="table_edit" cellpadding="0" cellspacing="0" align="center">
		<tr>
			<td>
				<table class="table_detaillist" cellpadding="0" cellspacing="1" align="center">
				<form method="POST" action="newVersion.jsp?AppId=<%=appId%>&edit=1" name="NewForm" ENCTYPE="multipart/form-data">
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("VerType")%></td>
						<td class="td_detailcontent0">
							<input type="hidden" name="PackVersion" value="2.2">
							<select name="VerType">
								<option<%if(verType.equals("1")){%> selected<%}%> value="1"><%=LangPage.langPage.getSelect("app_type")%></option>
								<option<%if(verType.equals("2")){%> selected<%}%> value="2"><%=LangPage.langPage.getSelect("app_mobile")%></option>
							</select>
						</td>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("AppVersion")%></td>
						<td class="td_detailcontent0">
							<input class="input_edit" style="width:100%;" onkeydown="enterFloat();" type="text" name="Version" value="<%=version%>">
						</td>
					</tr>
					<tr>
						<td width="15%" class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("Rank")%></td>
						<td width="35%" class="td_detailcontent0">
							<select name="Rank">
								<option<%if(rank.equals("1")){%> selected<%}%> value="1"><%=LangPage.langPage.getSelect("rank_first")%></option>
								<option<%if(rank.equals("2")){%> selected<%}%> value="2"><%=LangPage.langPage.getSelect("rank_sec")%></option>
								<option<%if(rank.equals("3")){%> selected<%}%> value="3"><%=LangPage.langPage.getSelect("rank_thir")%></option>
								<option<%if(rank.equals("4")){%> selected<%}%> value="4"><%=LangPage.langPage.getSelect("rank_four")%></option>
								<option<%if(rank.equals("5")){%> selected<%}%> value="5"><%=LangPage.langPage.getSelect("rank_five")%></option>
							</select>
						</td>
						<td width="15%" class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("MemorySize")%></td>
						<td width="35%" class="td_detailcontent0" width="200">
							<select name="Memery">
								<option<%if(memery.equals("400")){%> selected<%}%> value="400">400K</option>
								<option<%if(memery.equals("500")){%> selected<%}%> value="500">500K</option>
								<option<%if(memery.equals("600")){%> selected<%}%> value="600">600K</option>
								<option<%if(memery.equals("800")){%> selected<%}%> value="800">800K</option>
								<option<%if(memery.equals("1000")){%> selected<%}%> value="1000">1000K</option>
								<option<%if(memery.equals("1536")){%> selected<%}%> value="1536">1.5M</option>
								<option<%if(memery.equals("3072")){%> selected<%}%> value="3072">3M</option>
							</select>
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("CertId")%></td>
						<td class="td_detailcontent0">
							<select name="CertId">
								<option<%if(certId.equals("5")){%> selected<%}%> value="5"><%=LangPage.langPage.getSelect("cert_fivecert")%></option>
								<option<%if(certId.equals("6")){%> selected<%}%> value="6"><%=LangPage.langPage.getSelect("cert_sixcert")%></option>
								<option<%if(certId.equals("7")){%> selected<%}%> value="7"><%=LangPage.langPage.getSelect("cert_severcert")%></option>
								<option<%if(certId.equals("8")){%> selected<%}%> value="8"><%=LangPage.langPage.getSelect("cert_eightcert")%></option>
								<option<%if(certId.equals("9")){%> selected<%}%> value="9"><%=LangPage.langPage.getSelect("cert_ninecert")%></option>
								<option<%if(certId.equals("10")){%> selected<%}%> value="10"><%=LangPage.langPage.getSelect("cert_tencert")%></option>
								<option<%if(certId.equals("11")){%> selected<%}%> value="11"><%=LangPage.langPage.getSelect("cert_elvencert")%></option>
								<option<%if(certId.equals("12")){%> selected<%}%> value="12"><%=LangPage.langPage.getSelect("cert_twecert")%></option>
								<option<%if(certId.equals("13")){%> selected<%}%> value="13"><%=LangPage.langPage.getSelect("cert_thirteencert")%></option>
								<option<%if(certId.equals("14")){%> selected<%}%> value="14"><%=LangPage.langPage.getSelect("cert_fourteencert")%></option>
								<option<%if(certId.equals("15")){%> selected<%}%> value="15"><%=LangPage.langPage.getSelect("cert_fifteencert")%></option>
							</select>
						</td>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("CertDate")%></td>
						<td class="td_detailcontent0">
							<input class="input_edit" style="width:100%;" onkeydown="enterUnsigned();" type="text" name="CertDate" value="<%=certDate%>">
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("ScreenType")%></td>
						<td colspan="3" class="td_detailcontent0">
							<input type="checkbox"<%if(sc_qqvga!=null){out.print(" checked");}%> name="QQVGA">QQVGA&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_qcif!=null){out.print(" checked");}%> name="QCIF">QCIF&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_qvga!=null){out.print(" checked");}%> name="QVGA">QVGA&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_wqvga!=null){out.print(" checked");}%> name="WQVGA">WQVGA&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_hvga!=null){out.print(" checked");}%> name="HVGA">HVGA<br>
							<input type="checkbox"<%if(sc_qqvga_ls!=null){out.print(" checked");}%> name="QQVGA-LS">QQVGA-LS&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_qcif_ls!=null){out.print(" checked");}%> name="QCIF-LS">QCIF-LS&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_qvga_ls!=null){out.print(" checked");}%> name="QVGA-LS">QVGA-LS&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_wqvga_ls!=null){out.print(" checked");}%> name="WQVGA-LS">WQVGA-LS&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_hvga_ls!=null){out.print(" checked");}%> name="HVGA-LS">HVGA-LS<br>
							<input type="checkbox"<%if(sc_other!=null){out.print(" checked");}%> name="OtherScreen">Other&nbsp;&nbsp;&nbsp;<%=LangPage.langPage.getSelect("screen_width")%><input type="text" name="ScreenWidth" onkeydown="enterUnsigned();" style="width:80;" value="<%=screenWidth%>">&nbsp;&nbsp;<%=LangPage.langPage.getSelect("screen_height")%><input type="text" name="ScreenHeight" onkeydown="enterUnsigned();" style="width:80;" value="<%=screenHeight%>">
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("MTKVersion")%></td>
						<td colspan="3" class="td_detailcontent0">
							<input type="checkbox"<%if(mtk_08A !=null){out.print(" checked");}%> name="08A">08A&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(mtk_08B !=null){out.print(" checked");}%> name="08B">08B&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(mtk_09A !=null){out.print(" checked");}%> name="09A">09A&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(mtk_09B !=null){out.print(" checked");}%> name="09B">09B
						</td>
					</tr>	
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("ChipVersion")%></td>
						<td colspan="3" class="td_detailcontent0">
							<input type="checkbox"<%if(chip_6223 !=null){out.print(" checked");}%> name="6223">6223&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(chip_6225 !=null){out.print(" checked");}%> name="6225">6225&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(chip_6235 !=null){out.print(" checked");}%> name="6235">6235&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(chip_6238 !=null){out.print(" checked");}%> name="6238">6238&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(chip_6253 !=null){out.print(" checked");}%> name="6253">6253
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("InputDC")%></td>
						<td colspan="3" class="td_detailcontent0">
							<input type="checkbox"<%if(input_keypad!=null){out.print(" checked");}%> name="Input_Keypad"><%=LangPage.langPage.getSelect("screen_keypad")%>&nbsp;&nbsp;
							<input type="checkbox"<%if(input_touch!=null){out.print(" checked");}%> name="Input_Touch"><%=LangPage.langPage.getSelect("screen_touch")%>
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("FeeGroupId")%></td>
						<td class="td_detailcontent0">
							<select name="FeeGroupId">
								<option<%if(feeGroupId.equals("0")){%> selected<%}%> value="0"><%=LangPage.langPage.getSelect("group_zero")%></option>
								<option<%if(feeGroupId.equals("1")){%> selected<%}%> value="1"><%=LangPage.langPage.getSelect("group_first")%></option>
								<option<%if(feeGroupId.equals("2")){%> selected<%}%> value="2"><%=LangPage.langPage.getSelect("group_two")%></option>
								<option<%if(feeGroupId.equals("3")){%> selected<%}%> value="3"><%=LangPage.langPage.getSelect("group_three")%></option>
								<option<%if(feeGroupId.equals("4")){%> selected<%}%> value="4"><%=LangPage.langPage.getSelect("group_four")%></option>
								<option<%if(feeGroupId.equals("5")){%> selected<%}%> value="5"><%=LangPage.langPage.getSelect("group_five")%></option>
								<option<%if(feeGroupId.equals("6")){%> selected<%}%> value="6"><%=LangPage.langPage.getSelect("group_six")%></option>
								<option<%if(feeGroupId.equals("7")){%> selected<%}%> value="7"><%=LangPage.langPage.getSelect("group_seven")%></option>
								<option<%if(feeGroupId.equals("8")){%> selected<%}%> value="8"><%=LangPage.langPage.getSelect("group_eight")%></option>
								<option<%if(feeGroupId.equals("9")){%> selected<%}%> value="9"><%=LangPage.langPage.getSelect("group_nine")%></option>
								<option<%if(feeGroupId.equals("10")){%> selected<%}%> value="10"><%=LangPage.langPage.getSelect("group_ten")%></option>
								<option<%if(feeGroupId.equals("11")){%> selected<%}%> value="11"><%=LangPage.langPage.getSelect("group_elven")%></option>
								<option<%if(feeGroupId.equals("12")){%> selected<%}%> value="12"><%=LangPage.langPage.getSelect("group_twlve")%></option>
								<option<%if(feeGroupId.equals("13")){%> selected<%}%> value="13"><%=LangPage.langPage.getSelect("group_thirteen")%></option>
								<option<%if(feeGroupId.equals("14")){%> selected<%}%> value="14"><%=LangPage.langPage.getSelect("group_fourteen")%></option>
								<option<%if(feeGroupId.equals("15")){%> selected<%}%> value="15"><%=LangPage.langPage.getSelect("group_fifteen")%></option>
							</select>
						</td>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("FeePrice")%></td>
						<td class="td_detailcontent0">
							<input class="input_edit" onkeydown="enterUnsigned();" style="width:100%;" type="text" name="Price" value="<%=price%>">
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("FeeType")%></td>
						<td class="td_detailcontent0">
							<select name="FeeType">
								<option<%if(feeType.equals("1")){%> selected<%}%> value="1"><%=LangPage.langPage.getSelect("feetype_day")%></option>
								<option<%if(feeType.equals("2")){%> selected<%}%> value="2"><%=LangPage.langPage.getSelect("feetype_time")%></option>
								<option<%if(feeType.equals("3")){%> selected<%}%> value="3"><%=LangPage.langPage.getSelect("feetype_buy")%></option>
							</select>
						</td>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("FeeValue")%></td>
						<td class="td_detailcontent0">
							<input class="input_edit" style="width:100%;" onkeydown="enterUnsigned();" type="text" name="FeeValue" value="<%=feeValue%>">
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("VREVersion")%></td>
						<td class="td_detailcontent0">
							<input class="input_edit" style="width:100%;" onkeydown="enterFloat();" type="text" name="VreVersion" value="<%=vreVersion%>">
						</td>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("FeeChannel")%></td>
						<td class="td_detailcontent0">
							<select name="FeeChannel">
								<option value=""></option> 
							</select>
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("TrialFlag")%></td>
						<td class="td_detailcontent0">
							<select name="TrialFlag">
								<option<%if(trialFlag.equals("0")){%> selected<%}%> value="0"><%=LangPage.langPage.getSelect("trial_no")%></option>
								<option<%if(trialFlag.equals("1")){%> selected<%}%> value="1"><%=LangPage.langPage.getSelect("trial_yes")%></option>
							</select>
						</td>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("TrialPrice")%></td>
						<td class="td_detailcontent0">
							<input class="input_edit" style="width:100%;" onkeydown="enterUnsigned();" type="text" name="TrialPrice" value="<%=trialPrice%>">
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("TrialType")%></td>
						<td class="td_detailcontent0">
							<select name="TrialType">
								<option<%if(trialType.equals("1")){%> selected<%}%> value="1"><%=LangPage.langPage.getSelect("feetype_day")%></option>
								<option<%if(trialType.equals("2")){%> selected<%}%> value="2"><%=LangPage.langPage.getSelect("feetype_time")%></option>
							</select>
						</td>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("TrialValue")%></td>
						<td class="td_detailcontent0">
							<input class="input_edit" style="width:100%;" onkeydown="enterUnsigned();" type="text" name="TrialValue" value="<%=trialValue%>">
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("Permission")%></td>
						<td colspan="3" class="td_detailcontent0">
							<input type="checkbox"<%if(perm_5000!=null){out.print(" checked");}%> name="5000">PER_AUDIO_PLAY&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5001!=null){out.print(" checked");}%> name="5001">PER_CALL_OUT&nbsp;
							<input type="checkbox"<%if(perm_5002!=null){out.print(" checked");}%> name="5002">PER_CAMERA&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5003!=null){out.print(" checked");}%> name="5003">PER_FILE<br>
							<input type="checkbox"<%if(perm_5004!=null){out.print(" checked");}%> name="5004">PER_HTTP&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5005!=null){out.print(" checked");}%> name="5005">PER_RECORD&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5006!=null){out.print(" checked");}%> name="5006">PER_SENSOR&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5007!=null){out.print(" checked");}%> name="5007">PER_SIM<br>
							<input type="checkbox"<%if(perm_5008!=null){out.print(" checked");}%> name="5008">PER_SMS_PER&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5009!=null){out.print(" checked");}%> name="5009">PER_SMS_SP&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5010!=null){out.print(" checked");}%> name="5010">PER_TCP&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5011!=null){out.print(" checked");}%> name="5011">PER_APPSTORE<br>
						</td>
					</tr>					
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("MobileList")%></td>
						<td colspan="3" class="td_detailcontent0"><textarea name="MobileList" class="input_textarea"><%=mobileList%></textarea></td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("FileName")%></td>
						<td colspan="3" class="td_detailcontent0">
							<input class="input_edit" type="file" name="UploadFile" value="" style="width:400;"></input>
						</td>
					</tr>					
					<tr>
						<td colspan="4" align="center" valign="middle" class="td_editbutton">
							<a href="#" onclick="newSubmit();"><img src="../../<%=LangPage.langPage.getButton_img_path()%>submit_001.gif" border="0" align="top" vspace="1" /></a>
						</td>
					</tr>
				</form>
				</table>
			</td>
		</tr>
	</table>
	</div>

	<div align="center" id="form_app_21" class="datainfo">
	<table id="tb_new" class="table_edit" cellpadding="0" cellspacing="0" align="center">
		<tr>
			<td>
				<table class="table_detaillist" cellpadding="0" cellspacing="1" align="center">
				<form method="POST" action="newVersion.jsp?AppId=<%=appId%>&edit=1" name="NewForm" ENCTYPE="multipart/form-data">
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("VerType")%></td>
						<td class="td_detailcontent0">
							<input type="hidden" name="PackVersion" value="2.1">
							<select name="VerType">
								<option<%if(verType.equals("1")){%> selected<%}%> value="1"><%=LangPage.langPage.getSelect("app_type")%></option>
								<option<%if(verType.equals("2")){%> selected<%}%> value="2"><%=LangPage.langPage.getSelect("app_mobile")%></option>
							</select>
						</td>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("AppVersion")%></td>
						<td class="td_detailcontent0">
							<input class="input_edit" style="width:100%;" onkeydown="enterFloat();" type="text" name="Version" value="<%=version%>">
						</td>
					</tr>
					<tr>
						<td width="15%" class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("Rank")%></td>
						<td width="35%" class="td_detailcontent0">
							<select name="Rank">
								<option<%if(rank.equals("1")){%> selected<%}%> value="1"><%=LangPage.langPage.getSelect("rank_first")%></option>
								<option<%if(rank.equals("2")){%> selected<%}%> value="2"><%=LangPage.langPage.getSelect("rank_sec")%></option>
								<option<%if(rank.equals("3")){%> selected<%}%> value="3"><%=LangPage.langPage.getSelect("rank_thir")%></option>
								<option<%if(rank.equals("4")){%> selected<%}%> value="4"><%=LangPage.langPage.getSelect("rank_four")%></option>
								<option<%if(rank.equals("5")){%> selected<%}%> value="5"><%=LangPage.langPage.getSelect("rank_five")%></option>
							</select>
						</td>
						<td width="15%" class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("MemorySize")%></td>
						<td width="35%" class="td_detailcontent0" width="200">
							<select name="Memery">
								<option<%if(memery.equals("400")){%> selected<%}%> value="400">400K</option>
								<option<%if(memery.equals("500")){%> selected<%}%> value="500">500K</option>
								<option<%if(memery.equals("600")){%> selected<%}%> value="600">600K</option>
								<option<%if(memery.equals("800")){%> selected<%}%> value="800">800K</option>
								<option<%if(memery.equals("1000")){%> selected<%}%> value="1000">1000K</option>
								<option<%if(memery.equals("1536")){%> selected<%}%> value="1536">1.5M</option>
								<option<%if(memery.equals("3072")){%> selected<%}%> value="3072">3M</option>
							</select>
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("CertId")%></td>
						<td class="td_detailcontent0">
							<select name="CertId">
								<option<%if(certId.equals("5")){%> selected<%}%> value="5"><%=LangPage.langPage.getSelect("cert_fivecert")%></option>
								<option<%if(certId.equals("6")){%> selected<%}%> value="6"><%=LangPage.langPage.getSelect("cert_sixcert")%></option>
								<option<%if(certId.equals("7")){%> selected<%}%> value="7"><%=LangPage.langPage.getSelect("cert_severcert")%></option>
								<option<%if(certId.equals("8")){%> selected<%}%> value="8"><%=LangPage.langPage.getSelect("cert_eightcert")%></option>
								<option<%if(certId.equals("9")){%> selected<%}%> value="9"><%=LangPage.langPage.getSelect("cert_ninecert")%></option>
								<option<%if(certId.equals("10")){%> selected<%}%> value="10"><%=LangPage.langPage.getSelect("cert_tencert")%></option>
								<option<%if(certId.equals("11")){%> selected<%}%> value="11"><%=LangPage.langPage.getSelect("cert_elvencert")%></option>
								<option<%if(certId.equals("12")){%> selected<%}%> value="12"><%=LangPage.langPage.getSelect("cert_twecert")%></option>
								<option<%if(certId.equals("13")){%> selected<%}%> value="13"><%=LangPage.langPage.getSelect("cert_thirteencert")%></option>
								<option<%if(certId.equals("14")){%> selected<%}%> value="14"><%=LangPage.langPage.getSelect("cert_fourteencert")%></option>
								<option<%if(certId.equals("15")){%> selected<%}%> value="15"><%=LangPage.langPage.getSelect("cert_fifteencert")%></option>
							</select>
						</td>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("CertDate")%></td>
						<td class="td_detailcontent0">
							<input class="input_edit" style="width:100%;" onkeydown="enterUnsigned();" type="text" name="CertDate" value="<%=certDate%>">
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("ScreenType")%></td>
						<td colspan="3" class="td_detailcontent0">
							<input type="checkbox"<%if(sc_qqvga!=null){out.print(" checked");}%> name="QQVGA">QQVGA&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_qcif!=null){out.print(" checked");}%> name="QCIF">QCIF&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_qvga!=null){out.print(" checked");}%> name="QVGA">QVGA&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_wqvga!=null){out.print(" checked");}%> name="WQVGA">WQVGA&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_hvga!=null){out.print(" checked");}%> name="HVGA">HVGA<br>
							<input type="checkbox"<%if(sc_qqvga_ls!=null){out.print(" checked");}%> name="QQVGA-LS">QQVGA-LS&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_qcif_ls!=null){out.print(" checked");}%> name="QCIF-LS">QCIF-LS&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_qvga_ls!=null){out.print(" checked");}%> name="QVGA-LS">QVGA-LS&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_wqvga_ls!=null){out.print(" checked");}%> name="WQVGA-LS">WQVGA-LS&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_hvga_ls!=null){out.print(" checked");}%> name="HVGA-LS">HVGA-LS<br>
							<input type="checkbox"<%if(sc_other!=null){out.print(" checked");}%> name="OtherScreen">Other&nbsp;&nbsp;&nbsp;<%=LangPage.langPage.getSelect("screen_width")%><input type="text" name="ScreenWidth" onkeydown="enterUnsigned();" style="width:80;" value="<%=screenWidth%>">&nbsp;&nbsp;<%=LangPage.langPage.getSelect("screen_height")%><input type="text" name="ScreenHeight" onkeydown="enterUnsigned();" style="width:80;" value="<%=screenHeight%>">
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("MTKVersion")%></td>
						<td colspan="3" class="td_detailcontent0">
							<input type="checkbox"<%if(mtk_08A !=null){out.print(" checked");}%> name="08A">08A&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(mtk_08B !=null){out.print(" checked");}%> name="08B">08B&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(mtk_09A !=null){out.print(" checked");}%> name="09A">09A&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(mtk_09B !=null){out.print(" checked");}%> name="09B">09B
						</td>
					</tr>	
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("ChipVersion")%></td>
						<td colspan="3" class="td_detailcontent0">
							<input type="checkbox"<%if(chip_6223 !=null){out.print(" checked");}%> name="6223">6223&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(chip_6225 !=null){out.print(" checked");}%> name="6225">6225&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(chip_6235 !=null){out.print(" checked");}%> name="6235">6235&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(chip_6238 !=null){out.print(" checked");}%> name="6238">6238&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(chip_6253 !=null){out.print(" checked");}%> name="6253">6253
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("InputDC")%></td>
						<td colspan="3" class="td_detailcontent0">
							<input type="checkbox"<%if(input_keypad!=null){out.print(" checked");}%> name="Input_Keypad"><%=LangPage.langPage.getSelect("screen_keypad")%>&nbsp;&nbsp;
							<input type="checkbox"<%if(input_touch!=null){out.print(" checked");}%> name="Input_Touch"><%=LangPage.langPage.getSelect("screen_touch")%>
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("FeeGroupId")%></td>
						<td class="td_detailcontent0">
							<select name="FeeGroupId">
								<option<%if(feeGroupId.equals("0")){%> selected<%}%> value="0"><%=LangPage.langPage.getSelect("group_zero")%></option>
								<option<%if(feeGroupId.equals("1")){%> selected<%}%> value="1"><%=LangPage.langPage.getSelect("group_first")%></option>
								<option<%if(feeGroupId.equals("2")){%> selected<%}%> value="2"><%=LangPage.langPage.getSelect("group_two")%></option>
								<option<%if(feeGroupId.equals("3")){%> selected<%}%> value="3"><%=LangPage.langPage.getSelect("group_three")%></option>
								<option<%if(feeGroupId.equals("4")){%> selected<%}%> value="4"><%=LangPage.langPage.getSelect("group_four")%></option>
								<option<%if(feeGroupId.equals("5")){%> selected<%}%> value="5"><%=LangPage.langPage.getSelect("group_five")%></option>
								<option<%if(feeGroupId.equals("6")){%> selected<%}%> value="6"><%=LangPage.langPage.getSelect("group_six")%></option>
								<option<%if(feeGroupId.equals("7")){%> selected<%}%> value="7"><%=LangPage.langPage.getSelect("group_seven")%></option>
								<option<%if(feeGroupId.equals("8")){%> selected<%}%> value="8"><%=LangPage.langPage.getSelect("group_eight")%></option>
								<option<%if(feeGroupId.equals("9")){%> selected<%}%> value="9"><%=LangPage.langPage.getSelect("group_nine")%></option>
								<option<%if(feeGroupId.equals("10")){%> selected<%}%> value="10"><%=LangPage.langPage.getSelect("group_ten")%></option>
								<option<%if(feeGroupId.equals("11")){%> selected<%}%> value="11"><%=LangPage.langPage.getSelect("group_elven")%></option>
								<option<%if(feeGroupId.equals("12")){%> selected<%}%> value="12"><%=LangPage.langPage.getSelect("group_twlve")%></option>
								<option<%if(feeGroupId.equals("13")){%> selected<%}%> value="13"><%=LangPage.langPage.getSelect("group_thirteen")%></option>
								<option<%if(feeGroupId.equals("14")){%> selected<%}%> value="14"><%=LangPage.langPage.getSelect("group_fourteen")%></option>
								<option<%if(feeGroupId.equals("15")){%> selected<%}%> value="15"><%=LangPage.langPage.getSelect("group_fifteen")%></option>
							</select>
						</td>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("FeePrice")%></td>
						<td class="td_detailcontent0">
							<input class="input_edit" onkeydown="enterUnsigned();" style="width:100%;" type="text" name="Price" value="<%=price%>">
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("FeeType")%></td>
						<td class="td_detailcontent0">
							<select name="FeeType">
								<option<%if(feeType.equals("1")){%> selected<%}%> value="1"><%=LangPage.langPage.getSelect("feetype_day")%></option>
								<option<%if(feeType.equals("2")){%> selected<%}%> value="2"><%=LangPage.langPage.getSelect("feetype_time")%></option>
								<option<%if(feeType.equals("3")){%> selected<%}%> value="3"><%=LangPage.langPage.getSelect("feetype_buy")%></option>
							</select>
						</td>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("FeeValue")%></td>
						<td class="td_detailcontent0">
							<input class="input_edit" style="width:100%;" onkeydown="enterUnsigned();" type="text" name="FeeValue" value="<%=feeValue%>">
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("VREVersion")%></td>
						<td colspan="3" class="td_detailcontent0">
							<input class="input_edit" style="width:100%;" onkeydown="enterFloat();" type="text" name="VreVersion" value="<%=vreVersion%>">
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("TrialFlag")%></td>
						<td class="td_detailcontent0">
							<select name="TrialFlag">
								<option<%if(trialFlag.equals("0")){%> selected<%}%> value="0"><%=LangPage.langPage.getSelect("trial_no")%></option>
								<option<%if(trialFlag.equals("1")){%> selected<%}%> value="1"><%=LangPage.langPage.getSelect("trial_yes")%></option>
							</select>
						</td>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("TrialPrice")%></td>
						<td class="td_detailcontent0">
							<input class="input_edit" style="width:100%;" onkeydown="enterUnsigned();" type="text" name="TrialPrice" value="<%=trialPrice%>">
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("TrialType")%></td>
						<td class="td_detailcontent0">
							<select name="TrialType">
								<option<%if(trialType.equals("1")){%> selected<%}%> value="1"><%=LangPage.langPage.getSelect("feetype_day")%></option>
								<option<%if(trialType.equals("2")){%> selected<%}%> value="2"><%=LangPage.langPage.getSelect("feetype_time")%></option>
							</select>
						</td>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("TrialValue")%></td>
						<td class="td_detailcontent0">
							<input class="input_edit" style="width:100%;" onkeydown="enterUnsigned();" type="text" name="TrialValue" value="<%=trialValue%>">
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("Permission")%></td>
						<td colspan="3" class="td_detailcontent0">
							<input type="checkbox"<%if(perm_5000!=null){out.print(" checked");}%> name="5000">PER_AUDIO_PLAY&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5001!=null){out.print(" checked");}%> name="5001">PER_CALL_OUT&nbsp;
							<input type="checkbox"<%if(perm_5002!=null){out.print(" checked");}%> name="5002">PER_CAMERA&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5003!=null){out.print(" checked");}%> name="5003">PER_FILE<br>
							<input type="checkbox"<%if(perm_5004!=null){out.print(" checked");}%> name="5004">PER_HTTP&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5005!=null){out.print(" checked");}%> name="5005">PER_RECORD&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5006!=null){out.print(" checked");}%> name="5006">PER_SENSOR&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5007!=null){out.print(" checked");}%> name="5007">PER_SIM<br>
							<input type="checkbox"<%if(perm_5008!=null){out.print(" checked");}%> name="5008">PER_SMS_PER&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5009!=null){out.print(" checked");}%> name="5009">PER_SMS_SP&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5010!=null){out.print(" checked");}%> name="5010">PER_TCP&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5011!=null){out.print(" checked");}%> name="5011">PER_APPSTORE<br>
						</td>
					</tr>					
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("MobileList")%></td>
						<td colspan="3" class="td_detailcontent0"><textarea name="MobileList" class="input_textarea"><%=mobileList%></textarea></td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("FileName")%></td>
						<td colspan="3" class="td_detailcontent0">
							<input class="input_edit" type="file" name="UploadFile" value="" style="width:400;"></input>
						</td>
					</tr>					
					<tr>
						<td colspan="4" align="center" valign="middle" class="td_editbutton">
							<a href="#" onclick="newSubmit();"><img src="../../<%=LangPage.langPage.getButton_img_path()%>submit_001.gif" border="0" align="top" vspace="1" /></a>
						</td>
					</tr>
				</form>
				</table>
			</td>
		</tr>
	</table>
	</div>

	<div align="center" id="form_app_20" class="datainfo">
	<table id="tb_new" class="table_edit" cellpadding="0" cellspacing="0" align="center">
		<tr>
			<td>
				<table class="table_detaillist" cellpadding="0" cellspacing="1" align="center">
				<form method="POST" action="newVersion.jsp?AppId=<%=appId%>&edit=1" name="NewForm" ENCTYPE="multipart/form-data">
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("VerType")%></td>
						<td class="td_detailcontent0">
							<input type="hidden" name="PackVersion" value="2.0">
							<select name="VerType">
								<option<%if(verType.equals("1")){%> selected<%}%> value="1"><%=LangPage.langPage.getSelect("app_type")%></option>
								<option<%if(verType.equals("2")){%> selected<%}%> value="2"><%=LangPage.langPage.getSelect("app_mobile")%></option>
							</select>
						</td>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("AppVersion")%></td>
						<td class="td_detailcontent0">
							<input class="input_edit" style="width:100%;" onkeydown="enterFloat();" type="text" name="Version" value="<%=version%>">
						</td>
					</tr>
					<tr>
						<td width="15%" class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("Rank")%></td>
						<td width="35%" class="td_detailcontent0">
							<select name="Rank">
								<option<%if(rank.equals("1")){%> selected<%}%> value="1"><%=LangPage.langPage.getSelect("rank_first")%></option>
								<option<%if(rank.equals("2")){%> selected<%}%> value="2"><%=LangPage.langPage.getSelect("rank_sec")%></option>
								<option<%if(rank.equals("3")){%> selected<%}%> value="3"><%=LangPage.langPage.getSelect("rank_thir")%></option>
								<option<%if(rank.equals("4")){%> selected<%}%> value="4"><%=LangPage.langPage.getSelect("rank_four")%></option>
								<option<%if(rank.equals("5")){%> selected<%}%> value="5"><%=LangPage.langPage.getSelect("rank_five")%></option>
							</select>
						</td>
						<td width="15%" class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("MemorySize")%></td>
						<td width="35%" class="td_detailcontent0" width="200">
							<select name="Memery">
								<option<%if(memery.equals("400")){%> selected<%}%> value="400">400K</option>
								<option<%if(memery.equals("500")){%> selected<%}%> value="500">500K</option>
								<option<%if(memery.equals("600")){%> selected<%}%> value="600">600K</option>
								<option<%if(memery.equals("800")){%> selected<%}%> value="800">800K</option>
								<option<%if(memery.equals("1000")){%> selected<%}%> value="1000">1000K</option>
								<option<%if(memery.equals("1536")){%> selected<%}%> value="1536">1.5M</option>
								<option<%if(memery.equals("3072")){%> selected<%}%> value="3072">3M</option>
							</select>
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("CertId")%></td>
						<td class="td_detailcontent0">
							<select name="CertId">
								<option<%if(certId.equals("5")){%> selected<%}%> value="5"><%=LangPage.langPage.getSelect("cert_fivecert")%></option>
								<option<%if(certId.equals("6")){%> selected<%}%> value="6"><%=LangPage.langPage.getSelect("cert_sixcert")%></option>
								<option<%if(certId.equals("7")){%> selected<%}%> value="7"><%=LangPage.langPage.getSelect("cert_severcert")%></option>
								<option<%if(certId.equals("8")){%> selected<%}%> value="8"><%=LangPage.langPage.getSelect("cert_eightcert")%></option>
								<option<%if(certId.equals("9")){%> selected<%}%> value="9"><%=LangPage.langPage.getSelect("cert_ninecert")%></option>
								<option<%if(certId.equals("10")){%> selected<%}%> value="10"><%=LangPage.langPage.getSelect("cert_tencert")%></option>
								<option<%if(certId.equals("11")){%> selected<%}%> value="11"><%=LangPage.langPage.getSelect("cert_elvencert")%></option>
								<option<%if(certId.equals("12")){%> selected<%}%> value="12"><%=LangPage.langPage.getSelect("cert_twecert")%></option>
								<option<%if(certId.equals("13")){%> selected<%}%> value="13"><%=LangPage.langPage.getSelect("cert_thirteencert")%></option>
								<option<%if(certId.equals("14")){%> selected<%}%> value="14"><%=LangPage.langPage.getSelect("cert_fourteencert")%></option>
								<option<%if(certId.equals("15")){%> selected<%}%> value="15"><%=LangPage.langPage.getSelect("cert_fifteencert")%></option>
							</select>
						</td>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("CertDate")%></td>
						<td class="td_detailcontent0">
							<input class="input_edit" style="width:100%;" onkeydown="enterUnsigned();" type="text" name="CertDate" value="<%=certDate%>">
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("ScreenType")%></td>
						<td colspan="3" class="td_detailcontent0">
							<input type="checkbox"<%if(sc_qqvga!=null){out.print(" checked");}%> name="QQVGA">QQVGA&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_qcif!=null){out.print(" checked");}%> name="QCIF">QCIF&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_qvga!=null){out.print(" checked");}%> name="QVGA">QVGA&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_wqvga!=null){out.print(" checked");}%> name="WQVGA">WQVGA&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_hvga!=null){out.print(" checked");}%> name="HVGA">HVGA<br>
							<input type="checkbox"<%if(sc_qqvga_ls!=null){out.print(" checked");}%> name="QQVGA-LS">QQVGA-LS&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_qcif_ls!=null){out.print(" checked");}%> name="QCIF-LS">QCIF-LS&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_qvga_ls!=null){out.print(" checked");}%> name="QVGA-LS">QVGA-LS&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_wqvga_ls!=null){out.print(" checked");}%> name="WQVGA-LS">WQVGA-LS&nbsp;&nbsp;
							<input type="checkbox"<%if(sc_hvga_ls!=null){out.print(" checked");}%> name="HVGA-LS">HVGA-LS<br>
							<input type="checkbox"<%if(sc_other!=null){out.print(" checked");}%> name="OtherScreen">Other&nbsp;&nbsp;&nbsp;<%=LangPage.langPage.getSelect("screen_width")%><input type="text" name="ScreenWidth" onkeydown="enterUnsigned();" style="width:80;" value="<%=screenWidth%>">&nbsp;&nbsp;<%=LangPage.langPage.getSelect("screen_height")%><input type="text" name="ScreenHeight" onkeydown="enterUnsigned();" style="width:80;" value="<%=screenHeight%>">
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("MTKVersion")%></td>
						<td colspan="3" class="td_detailcontent0">
							<input type="checkbox"<%if(mtk_08A !=null){out.print(" checked");}%> name="08A">08A&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(mtk_08B !=null){out.print(" checked");}%> name="08B">08B&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(mtk_09A !=null){out.print(" checked");}%> name="09A">09A&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(mtk_09B !=null){out.print(" checked");}%> name="09B">09B
						</td>
					</tr>	
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("ChipVersion")%></td>
						<td colspan="3" class="td_detailcontent0">
							<input type="checkbox"<%if(chip_6223 !=null){out.print(" checked");}%> name="6223">6223&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(chip_6225 !=null){out.print(" checked");}%> name="6225">6225&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(chip_6235 !=null){out.print(" checked");}%> name="6235">6235&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(chip_6238 !=null){out.print(" checked");}%> name="6238">6238&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(chip_6253 !=null){out.print(" checked");}%> name="6253">6253
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("InputDC")%></td>
						<td colspan="3" class="td_detailcontent0">
							<input type="checkbox"<%if(input_keypad!=null){out.print(" checked");}%> name="Input_Keypad"><%=LangPage.langPage.getSelect("screen_keypad")%>&nbsp;&nbsp;
							<input type="checkbox"<%if(input_touch!=null){out.print(" checked");}%> name="Input_Touch"><%=LangPage.langPage.getSelect("screen_touch")%>
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("FeeGroupId")%></td>
						<td class="td_detailcontent0">
							<select name="FeeGroupId">
								<option<%if(feeGroupId.equals("0")){%> selected<%}%> value="0"><%=LangPage.langPage.getSelect("group_zero")%></option>
								<option<%if(feeGroupId.equals("1")){%> selected<%}%> value="1"><%=LangPage.langPage.getSelect("group_first")%></option>
								<option<%if(feeGroupId.equals("2")){%> selected<%}%> value="2"><%=LangPage.langPage.getSelect("group_two")%></option>
								<option<%if(feeGroupId.equals("3")){%> selected<%}%> value="3"><%=LangPage.langPage.getSelect("group_three")%></option>
								<option<%if(feeGroupId.equals("4")){%> selected<%}%> value="4"><%=LangPage.langPage.getSelect("group_four")%></option>
								<option<%if(feeGroupId.equals("5")){%> selected<%}%> value="5"><%=LangPage.langPage.getSelect("group_five")%></option>
								<option<%if(feeGroupId.equals("6")){%> selected<%}%> value="6"><%=LangPage.langPage.getSelect("group_six")%></option>
								<option<%if(feeGroupId.equals("7")){%> selected<%}%> value="7"><%=LangPage.langPage.getSelect("group_seven")%></option>
								<option<%if(feeGroupId.equals("8")){%> selected<%}%> value="8"><%=LangPage.langPage.getSelect("group_eight")%></option>
								<option<%if(feeGroupId.equals("9")){%> selected<%}%> value="9"><%=LangPage.langPage.getSelect("group_nine")%></option>
								<option<%if(feeGroupId.equals("10")){%> selected<%}%> value="10"><%=LangPage.langPage.getSelect("group_ten")%></option>
								<option<%if(feeGroupId.equals("11")){%> selected<%}%> value="11"><%=LangPage.langPage.getSelect("group_elven")%></option>
								<option<%if(feeGroupId.equals("12")){%> selected<%}%> value="12"><%=LangPage.langPage.getSelect("group_twlve")%></option>
								<option<%if(feeGroupId.equals("13")){%> selected<%}%> value="13"><%=LangPage.langPage.getSelect("group_thirteen")%></option>
								<option<%if(feeGroupId.equals("14")){%> selected<%}%> value="14"><%=LangPage.langPage.getSelect("group_fourteen")%></option>
								<option<%if(feeGroupId.equals("15")){%> selected<%}%> value="15"><%=LangPage.langPage.getSelect("group_fifteen")%></option>
							</select>
						</td>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("FeePrice")%></td>
						<td class="td_detailcontent0">
							<input class="input_edit" onkeydown="enterUnsigned();" style="width:100%;" type="text" name="Price" value="<%=price%>">
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("FeeType")%></td>
						<td class="td_detailcontent0">
							<select name="FeeType">
								<option<%if(feeType.equals("1")){%> selected<%}%> value="1"><%=LangPage.langPage.getSelect("feetype_day")%></option>
								<option<%if(feeType.equals("2")){%> selected<%}%> value="2"><%=LangPage.langPage.getSelect("feetype_time")%></option>
								<option<%if(feeType.equals("3")){%> selected<%}%> value="3"><%=LangPage.langPage.getSelect("feetype_buy")%></option>
							</select>
						</td>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("FeeValue")%></td>
						<td class="td_detailcontent0">
							<input class="input_edit" style="width:100%;" onkeydown="enterUnsigned();" type="text" name="FeeValue" value="<%=feeValue%>">
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("VREVersion")%></td>
						<td colspan="3" class="td_detailcontent0">
							<input class="input_edit" style="width:100%;" onkeydown="enterFloat();" type="text" name="VreVersion" value="<%=vreVersion%>">
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("TrialFlag")%></td>
						<td class="td_detailcontent0">
							<select name="TrialFlag">
								<option<%if(trialFlag.equals("0")){%> selected<%}%> value="0"><%=LangPage.langPage.getSelect("trial_no")%></option>
								<option<%if(trialFlag.equals("1")){%> selected<%}%> value="1"><%=LangPage.langPage.getSelect("trial_yes")%></option>
							</select>
						</td>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("TrialPrice")%></td>
						<td class="td_detailcontent0">
							<input class="input_edit" style="width:100%;" onkeydown="enterUnsigned();" type="text" name="TrialPrice" value="<%=trialPrice%>">
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("TrialType")%></td>
						<td class="td_detailcontent0">
							<select name="TrialType">
								<option<%if(trialType.equals("1")){%> selected<%}%> value="1"><%=LangPage.langPage.getSelect("feetype_day")%></option>
								<option<%if(trialType.equals("2")){%> selected<%}%> value="2"><%=LangPage.langPage.getSelect("feetype_time")%></option>
							</select>
						</td>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("TrialValue")%></td>
						<td class="td_detailcontent0">
							<input class="input_edit" style="width:100%;" onkeydown="enterUnsigned();" type="text" name="TrialValue" value="<%=trialValue%>">
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("Permission")%></td>
						<td colspan="3" class="td_detailcontent0">
							<input type="checkbox"<%if(perm_5000!=null){out.print(" checked");}%> name="5000">PER_AUDIO_PLAY&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5001!=null){out.print(" checked");}%> name="5001">PER_CALL_OUT&nbsp;
							<input type="checkbox"<%if(perm_5002!=null){out.print(" checked");}%> name="5002">PER_CAMERA&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5003!=null){out.print(" checked");}%> name="5003">PER_FILE<br>
							<input type="checkbox"<%if(perm_5004!=null){out.print(" checked");}%> name="5004">PER_HTTP&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5005!=null){out.print(" checked");}%> name="5005">PER_RECORD&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5006!=null){out.print(" checked");}%> name="5006">PER_SENSOR&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5007!=null){out.print(" checked");}%> name="5007">PER_SIM<br>
							<input type="checkbox"<%if(perm_5008!=null){out.print(" checked");}%> name="5008">PER_SMS_PER&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
						 	<input type="checkbox"<%if(perm_5009!=null){out.print(" checked");}%> name="5009">PER_SMS_SP&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5010!=null){out.print(" checked");}%> name="5010">PER_TCP&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<input type="checkbox"<%if(perm_5011!=null){out.print(" checked");}%> name="5011">PER_APPSTORE<br>
						</td>
					</tr>					
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("MobileList")%></td>
						<td colspan="3" class="td_detailcontent0"><textarea name="MobileList" class="input_textarea"><%=mobileList%></textarea></td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("FileName")%></td>
						<td colspan="3" class="td_detailcontent0">
							<input class="input_edit" type="file" name="UploadFile" value="" style="width:400;"></input>
						</td>
					</tr>					
					<tr>
						<td colspan="4" align="center" valign="middle" class="td_editbutton">
							<a href="#" onclick="newSubmit();"><img src="../../<%=LangPage.langPage.getButton_img_path()%>submit_001.gif" border="0" align="top" vspace="1" /></a>
						</td>
					</tr>
				</form>
				</table>
			</td>
		</tr>
	</table>
	</div>
</body>

</html>