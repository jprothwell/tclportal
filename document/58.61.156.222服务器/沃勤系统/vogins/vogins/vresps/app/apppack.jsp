<%@ page contentType="text/html;charset=UTF-8"%>
<%@ page import="com.language.langdata.LangPage"%> 
<%@ page import="com.language.langdata.LangAction"%>  
<%@ page import="com.vogins.sps.db.app.*"%>
<%@ page import="com.vogins.sps.db.publicinfo.SystemParam"%>
<%@ page import="org.jwdf.io.*"%>
<%@ page import="org.jwdf.framework.console.*"%>
<%@ page import="org.jwdf.util.*"%>
<%@ page import="java.io.File"%>
<%@ page import="org.jwdf.framework.base.AbstractTableBean"%>
<%@ page import="com.vogins.sps.pack.test.*"%>
<%@ page import="com.vogins.sps.init.SystemParas"%>
<%@ page import="com.jspsmart.upload.*"%>
<jsp:useBean id="mySmartUpload" scope="page" class="com.jspsmart.upload.SmartUpload" />
<% 
  AppVersion appver = new AppVersion();
	Application app = new Application();
	CPPartner cp = new CPPartner();
	String strEdit = request.getParameter("edit");
	if(strEdit == null) strEdit = "0";

	String appId = "1179726";
	String appName = LangPage.langPage.getDef_appname();
	String cpName = LangPage.langPage.getDef_cpname();
	String rank = "5";
	String verType = "1";
	String certId = "0";
	String certDate = "20301231235959";
	String version = "1.0.0";
	String memery = "0";
	String screen = "0";
	String screenWidth = "0";
	String screenHeight = "0";
	String input_keypad = "";
	String input_touch = "";
	String input_zl = null;
	String input_gx = null;
	String feeGroupId = "0";
	String price = "0";
	String feeType = "1";
	String feeValue = "0";
	String vreVersion = "1.3.0";
	String compilerVersion = "1";
	String trialFlag = "0";
	String trialPrice = "0";
	String trialType = "1";
	String trialValue = "0";
	String appDesc = "";
	String feePack = null;
	String vre30 = null;
	String bgRun = "0";
	String feechannel="";
	
	String perm_5000 = "1";
	String perm_5001 = null;
	String perm_5002 = null;
	String perm_5003 = null;
	String perm_5004 = "1";
	String perm_5005 = "1";
	String perm_5006 = null;
	String perm_5007 = null;
	String perm_5008 = null;
	String perm_5009 = "1";
	String perm_5010 = null;
	String perm_5011 = null;
	String perm_5012 = null;
	String perm_5013 = null;
	String perm_5014 = null;
	String perm_5015 = null;
	String perm_5016 = null;
	String perm_5017 = null;
	String perm_5018 = null;
	String perm_5019 = null;
	String permissionList = ";";
	
	String downfile = null;
	String destfile = null;
	String strErrorInfo = "";
	if(strEdit.equals("1"))
	{
		mySmartUpload.initialize(pageContext);
		Request myRequest = mySmartUpload.getRequest();
		mySmartUpload.upload();
		feePack = myRequest.getParameter("FeePack");
		appId = myRequest.getParameter("AppId");
		appName = myRequest.getParameter("AppName");
		cpName = myRequest.getParameter("CPName");
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
		appDesc = myRequest.getParameter("AppDesc");
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

		vre30 = myRequest.getParameter("VRE30");
		bgRun = myRequest.getParameter("BGRun");
		feechannel = myRequest.getParameter("FeeChannel");
		
		if(appId == null) appId = "";
		if(appName == null) appName = "";
		if(cpName == null) cpName = "";
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
		if(appDesc == null) appDesc = "";
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
		if(feechannel == null) feechannel=""; //计费通道
		if(bgRun == null || bgRun.equals("")) bgRun = "0";
		if(feePack == null){
			feePack = "0";
		}else{
			feePack = "1";
		}
		if(appId.equals("")){
			strErrorInfo = LangPage.langPage.getInput_appid();
		}else if(appName.equals("")){
			strErrorInfo = LangPage.langPage.getInput_appname();
		}else if(cpName.equals("")){
			strErrorInfo = LangPage.langPage.getInput_cpname();
		}else if(!screen.equals("0") && screenWidth.equals("0") && screenHeight.equals("0")){
			strErrorInfo = LangPage.langPage.getNoselect_screentype();
		}else if(memery.equals("")){
			strErrorInfo = LangPage.langPage.getNoselect_memorysize();
		}else if(inputtype == 0){
			strErrorInfo = LangPage.langPage.getNoselect_inputdc();
		}else	{
			com.jspsmart.upload.File myContentFile = mySmartUpload.getFiles().getFile(0);
			String ContentFileName = myContentFile.getFileName();
			
			boolean blnIsHave = false;
			String tempFile = Long.toString(System.currentTimeMillis()) + ".dat";
			if(!myContentFile.isMissing())
			{
				myContentFile.saveAs(SystemParas.getReportPath() + "/" + tempFile,SmartUpload.SAVE_PHYSICAL);
				blnIsHave = true;
			}

			AppTagInfo tagInfo = new AppTagInfo();
			tagInfo.setSavePath(SystemParas.getReportPath() + "/" + tempFile);
			tagInfo.setFileName(ContentFileName);
			tagInfo.setCpName(cpName);
			tagInfo.setAppId(appId);
			tagInfo.setCertId(certId);
			tagInfo.setAppName(appName);
			tagInfo.setAppVersion(version);
			tagInfo.setCertDate(certDate);
			tagInfo.setFeeGroupId(feeGroupId);
			tagInfo.setFeePrice(price);
			tagInfo.setFeeType(feeType);
			tagInfo.setFeeValue(feeValue);
			tagInfo.setMemorySize(memery);
			tagInfo.setScreenType(screen);
			tagInfo.setScreenWidth(screenWidth);
			tagInfo.setScreenHeight(screenHeight);
			tagInfo.setVreVersion(vreVersion);
			tagInfo.setPermission(permissionList);
			tagInfo.setTrialFlag(trialFlag);
			tagInfo.setTrialPrice(trialPrice);
			tagInfo.setTrialType(trialType);
			tagInfo.setTrialValue(trialValue);
			tagInfo.setInputDC(Integer.toString(inputtype));
			tagInfo.setAppDesc(appDesc);
			tagInfo.setRank(rank);
			
			if(vre30 == null){
				tagInfo.setVre30("0");
			}else{
				tagInfo.setVre30("1");
			}
			tagInfo.setBgRun(bgRun);
            tagInfo.setFeechannel(feechannel);   
            
			if(blnIsHave){
				TestPackage pack = new TestPackage();
				String filename_new = Long.toString(System.currentTimeMillis()+1) + ".dat";
				String packFile = SystemParas.getReportPath() + "/" + filename_new;
				if(pack.packAppFile(packFile,tagInfo,feePack)){
					File file = new File(SystemParas.getReportPath() + "/" + tempFile);
					if(file.exists())
					{
						file.delete();
					}
					File file1 = new File(packFile);
					tagInfo.setSavePath(packFile);
					strErrorInfo = LangAction.langAction.getSuccess_package();
					downfile = filename_new;
					destfile = ContentFileName;
				}else{
					strErrorInfo = LangAction.langAction.getFailed_package();
				}
			}else{
				strErrorInfo = LangAction.langAction.getNoselect_uploadfile(); 
			}
		}
	}
%>
<html>

<head>
<TITLE><%=LangPage.langPage.getPageTitle("apppack")%></TITLE>
	<meta http-equiv="Pragma" content="no-cache">
	<SCRIPT language="JavaScript" type="text/javascript" src="../js/jwdf_check.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../js/jwdf_util.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_xml.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_view.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_swin.js"></SCRIPT>
	<link rel="stylesheet" type="text/css" href="../css/jwdf_main.css">
	<script language=javascript>
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
		
		function downloadFile(downfile,destfile){
			window.open("../TestDownload.do?filename="+downfile+"&destfile="+destfile,"DownloadFrame");
		}

		function showChannel(){	 
		    sendG("../GetAllChannel.do?SPId=",getChannelResult);
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
		function init(){
		    showChannel();
		}
  </script>  
</head>

<body onload="init();">
	<!-- 页面标题 -->
	<table class="table_pagetitle" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("apppack")%></td>
	</tr>
	</table>

	<table id="tb_new" class="table_edit" cellpadding="0" cellspacing="0" align="center">
		<tr>
			<td>
				<table class="table_detaillist" cellpadding="0" cellspacing="1" align="center">
				<form method="POST" action="apppack.jsp?edit=1" name="NewForm" ENCTYPE="multipart/form-data">
					<tr>
						<td height="20" colspan="1" bgcolor="#8acef5"><b><%=LangPage.langPage.getPageTitle("apppack")%></b></td>
						<td height="20" align="right" colspan="3" bgcolor="#8acef5" style="color:red;"><%=strErrorInfo%><%if(downfile!=null){%>【<a href="#" onclick="downloadFile('<%=downfile%>','<%=destfile%>');"><%=LangPage.langPage.getClick_download()%></a>】<%}%></td>
					</tr>
					<tr>
						<td colspan="4" class="td_detailcontent1" align="right" style="color:red;">
							<input type="checkbox"<%if(feePack!=null){out.print(" checked");}%> name="FeePack"><%=LangPage.langPage.getFeeinfo_tag()%>
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=app.getAliasByFiled("AppId")%></td>
						<td class="td_detailcontent0">
							<input class="input_edit" style="width:100%;" onkeydown="enterUnsigned();" type="text" name="AppId" value="<%=appId%>">
						</td>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("AppVersion")%>：</td>
						<td class="td_detailcontent0">
							<input class="input_edit" style="width:100%;" onkeydown="enterFloat();" type="text" name="Version" value="<%=version%>">
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=app.getAliasByFiled("AppName")%></td>
						<td class="td_detailcontent0">
							<input class="input_edit" style="width:100%;" type="text" name="AppName" value="<%=appName%>">
						</td>
						<td class="td_detailcontent1" align="center"><%=cp.getAliasByFiled("CPName")%></td>
						<td class="td_detailcontent0">
							<input class="input_edit" style="width:100%;" type="text" name="CPName" value="<%=cpName%>">
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
								<option<%if(memery.equals("500")){%> selected<%}%> value="500">500K</option>
								<option<%if(memery.equals("600")){%> selected<%}%> value="600">600K</option>
								<option<%if(memery.equals("800")){%> selected<%}%> value="800">800K</option>
								<option<%if(memery.equals("1000")){%> selected<%}%> value="1000">1000K</option>
								<option<%if(memery.equals("1536")){%> selected<%}%> value="1000">1.5M</option>
								<option<%if(memery.equals("3072")){%> selected<%}%> value="1000">3M</option>
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
							<select name="Screen" onchange="setScreen();">
								<option<%if(screen.equals("0")){out.print(" selected");}%> value="0"><%=LangPage.langPage.getSelect("screen_adaptive")%></option>
								<option<%if(screen.equals("1")){out.print(" selected");}%> value="1"><%=LangPage.langPage.getSelect("screen_qcif")%></option>
								<option<%if(screen.equals("2")){out.print(" selected");}%> value="2"><%=LangPage.langPage.getSelect("screen_qvga")%></option>
								<option<%if(screen.equals("4")){out.print(" selected");}%> value="4"><%=LangPage.langPage.getSelect("screen_wqvga")%></option>
								<option<%if(screen.equals("8")){out.print(" selected");}%> value="8"><%=LangPage.langPage.getSelect("screen_other")%></option>
							</select>&nbsp;&nbsp;
							<%=LangPage.langPage.getSelect("screen_width")%><input type="text" name="ScreenWidth" onkeydown="enterUnsigned();" style="width:80;" value="<%=screenWidth%>">&nbsp;&nbsp;<%=LangPage.langPage.getSelect("screen_height")%><input type="text" name="ScreenHeight" onkeydown="enterUnsigned();" style="width:80;" value="<%=screenHeight%>">
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("InputDC")%></td>
						<td  class="td_detailcontent0">
							<input type="checkbox"<%if(input_keypad!=null){out.print(" checked");}%> name="Input_Keypad"><%=LangPage.langPage.getSelect("screen_keypad")%>&nbsp;&nbsp;
							<input type="checkbox"<%if(input_touch!=null){out.print(" checked");}%> name="Input_Touch"><%=LangPage.langPage.getSelect("screen_touch")%>
							<input type="checkbox"<%if(input_zl!=null){out.print(" checked");}%> name="Input_ZL"><%=LangPage.langPage.getSelect("screen_gravitysensor")%>
							<input type="checkbox"<%if(input_gx!=null){out.print(" checked");}%> name="Input_GX"><%=LangPage.langPage.getSelect("screen_opticalsensor")%>
						</td>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("FeeChannel")%></td>
						<td class="td_detailcontent0">
							<select name="FeeChannel">
								<option value=""></option> 
							</select>
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
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("CompilerVersion")%></td>
						<td class="td_detailcontent0">
							<select name="CompilerVersion">
								<option<%if(compilerVersion.equals("1")){%> selected<%}%> value="1">ADS1.2</option>
								<option<%if(compilerVersion.equals("2")){%> selected<%}%> value="2">RVDS3.0</option>
								<option<%if(compilerVersion.equals("3")){%> selected<%}%> value="3">GCC4.0</option>
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
							<font color="red">VRE2.0</font><br>
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
							<font color="red">VRE3.0</font><br>
							<input type="checkbox"<%if(perm_5012!=null){out.print(" checked");}%> name="5012">PER_BITSTREAM
							<input type="checkbox"<%if(perm_5013!=null){out.print(" checked");}%> name="5013">PER_CONTACT
							<input type="checkbox"<%if(perm_5014!=null){out.print(" checked");}%> name="5014">PER_LBS
							<input type="checkbox"<%if(perm_5015!=null){out.print(" checked");}%> name="5015">PER_MMS<br>
							<input type="checkbox"<%if(perm_5016!=null){out.print(" checked");}%> name="5016">PER_PRO
							<input type="checkbox"<%if(perm_5017!=null){out.print(" checked");}%> name="5017">PER_SMSMNG
							<input type="checkbox"<%if(perm_5018!=null){out.print(" checked");}%> name="5018">PER_VIDEO
							<input type="checkbox"<%if(perm_5019!=null){out.print(" checked");}%> name="5019">PER_XML<br>
						</td>
					</tr>					
					<tr>
						<td class="td_detailcontent1" align="center"><%=app.getAliasByFiled("AppDesc")%></td>
						<td colspan="3" class="td_detailcontent0"><textarea name="AppDesc" class="input_textarea"><%=appDesc%></textarea></td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appver.getAliasByFiled("FileName")%></td>
						<td colspan="3" class="td_detailcontent0">
							<input class="input_edit" type="file" name="UploadFile" value="" style="width:400;"></input>
						</td>
					</tr>					
					<tr>
						<td height="20" colspan="1" bgcolor="#8acef5"><b>VRE3.0</b></td>
						<td height="20" colspan="3" bgcolor="#8acef5" style="color:red;">
							<input type="checkbox" <%if(vre30 != null){%> checked<%}%> name="VRE30">VRE30 TAG


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
							<a href="#" onclick="NewForm.submit();"><img src="../<%=LangPage.langPage.getButton_img_path()%>submit_001.gif" border="0" align="top" vspace="1" /></a>
						</td>
					</tr>
				</form>
				</table>
			</td>
		</tr>
	</table>

	<div align="center" id="download_div" style="display:none;">
		<iframe src="" name="DownloadFrame"></iframe>
	</div>

</body>

</html>