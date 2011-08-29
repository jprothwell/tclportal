<%@ page contentType="text/html;charset=gb2312"%>  
<%@ page import="com.language.langdata.LangPage"%> 
<%@ page import="com.language.langdata.LangAction"%>
<%@ page import="com.language.langdata.LangWorkflow"%>
<%@ page import="com.vogins.sps.db.app.*"%>
<%@ page import="com.vogins.workflow.db.TAppStore"%>
<%@ page import="org.jwdf.io.*"%>
<%@ page import="java.io.File"%>
<%@ page import="org.jwdf.framework.console.*"%>
<%@ page import="com.oa.workflow.db.*"%>
<%@ page import="org.jwdf.util.DateUtil"%>
<%@ page import="com.vogins.sps.init.SystemParas"%>
<%@ page import="com.vogins.sps.apppackage.data.PackageInfo"%>
<%@ page import="com.vogins.sps.apppackage.AppPackage"%>
<%@ page import="com.jspsmart.upload.*"%>
<%@ page import="com.vogins.sps.db.app.AppStore"%>
<jsp:useBean id="mySmartUpload" scope="page" class="com.jspsmart.upload.SmartUpload" />
<%
	AppStore app=new AppStore();

	String strEdit = request.getParameter("edit");
	if(strEdit == null) strEdit = "0";
	
	String packVersion = "AS3.0";
	String asVersion = "";
	String versionType = "1";
	String certId = "2";
	String vreVersion = "";
	String memorySize = "0";
	String screen = "0";
	String screenWidth = "0";
	String screenHeight = "0";
	String input_keypad = "1";
	String input_touch = "1";
	String input_zl = null;
	String input_gx = null;
	String mobileList = "";
	String remark = "";
	
	String strErrorInfo = "";
	String flowId = "";
	int wfStatus = 0;
	if(strEdit.equals("1"))
	{
		mySmartUpload.initialize(pageContext);
		Request myRequest = mySmartUpload.getRequest();
		mySmartUpload.upload();

		packVersion = myRequest.getParameter("PackVersion");
		asVersion = myRequest.getParameter("ASVersion");
		versionType = myRequest.getParameter("VersionType");
		certId = myRequest.getParameter("CertId");
		vreVersion = myRequest.getParameter("VREVersion");
		memorySize = myRequest.getParameter("MemorySize");
		screen = myRequest.getParameter("ScreenType");
		screenWidth = myRequest.getParameter("ScreenWidth");
		screenHeight = myRequest.getParameter("ScreenHeight");
		input_keypad = myRequest.getParameter("Input_Keypad");
		input_touch = myRequest.getParameter("Input_Touch");
		input_zl = myRequest.getParameter("Input_ZL");
		input_gx = myRequest.getParameter("Input_GX");
		mobileList = myRequest.getParameter("MobileList");
		remark = myRequest.getParameter("Remark");
		
		if(packVersion == null) packVersion = "AS3.0";
		if(asVersion == null) asVersion = "";
		if(versionType == null || versionType.equals("")) versionType = "1";
		if(certId == null || certId.equals("")) certId = "2";
		if(vreVersion == null) vreVersion = "";
		if(memorySize == null || memorySize.equals("")) memorySize = "0";
		if(screen == null || screen.equals("")) screen = "9";
		if(screenWidth == null || screenWidth.equals("")) screenWidth="0";
		if(screenHeight == null || screenWidth.equals("")) screenHeight = "0";
		int inputtype = 0;
		if(input_keypad != null) inputtype = inputtype + 1;
		if(input_touch != null) inputtype = inputtype + 2;
		if(input_zl != null) inputtype = inputtype + 4;
		if(input_gx != null) inputtype = inputtype + 8;
		if(mobileList == null) mobileList = "";
		if(remark == null) remark = "";
		
		com.jspsmart.upload.File myContentFile = mySmartUpload.getFiles().getFile(0);
			
		if(!myContentFile.isMissing())
		{
			String ContentFileName = myContentFile.getFileName();
			String tempFile = Long.toString(System.currentTimeMillis()) + ".dat";
			myContentFile.saveAs(SystemParas.getAppStorePath() + "/" + tempFile,SmartUpload.SAVE_PHYSICAL);

			String sessionId = Console.session_manager.getSessionId(request);
			String strAddUser = Console.session_manager.get(sessionId).getUserName();

			boolean insertSucc = false;
			
			TAppStore ver = new TAppStore();
			ver.setValue("ASVersion",asVersion);
			ver.setValue("PackVersion",packVersion);
			ver.setValue("VersionType",versionType);
			ver.setValue("CertId",certId);
			ver.setValue("VREVersion",vreVersion);
			ver.setValue("MemorySize",memorySize);
			ver.setValue("ScreenType",screen);
			ver.setValue("ScreenWidth",screenWidth);
			ver.setValue("ScreenHeight",screenHeight);
			ver.setValue("InputDC",Integer.toString(inputtype));
			ver.setValue("MobileList",mobileList);
			ver.setValue("FileName",ContentFileName);
			ver.setValue("FileSize",Integer.toString(myContentFile.getSize()));
			ver.setValue("SavePath",SystemParas.getAppStorePath() + "/" + tempFile);
			ver.setValue("AddTime",DateUtil.getFullDateTime());
			ver.setValue("UpdateTime",DateUtil.getFullDateTime());
			ver.setValue("AddUser",strAddUser);
			ver.setValue("Remark",remark);
			ver.setValue("PublishType",Integer.toString(AppStore.PUBLISH_TYPE_AS3));

			PackageInfo tagInfo = new PackageInfo();
			tagInfo.setSavePath(SystemParas.getAppStorePath() + "/" + tempFile);
			tagInfo.setFileName(ContentFileName);
			tagInfo.setCpName("VOGINS");
			tagInfo.setAppId("65608");
			tagInfo.setCertId(certId);
			tagInfo.setAppName("APPSTORE");
			tagInfo.setAppVersion(asVersion);
			tagInfo.setCertDate("20301231235959");
			tagInfo.setFeeGroupId("0");
			tagInfo.setMemorySize(memorySize);
			tagInfo.setScreenType(screen);
			tagInfo.setScreenWidth(screenWidth);
			tagInfo.setScreenHeight(screenHeight);
			tagInfo.setVreVersion(vreVersion);
			tagInfo.setInputDC(Integer.toString(inputtype));
			tagInfo.setAppDesc("");
			tagInfo.setRank("5");
			
		
			tagInfo.setPermission(";5000;5001;5002;5003;5004;5005;5006;5007;5008;5009;5010;5011;5012;5013;5014;5015;5016;5017;5018;5019;5020;");
			tagInfo.setAppNameBig5("APPSTORE");
			tagInfo.setAppNameEn("APPSTORE");
			tagInfo.setBgRun("0");
		
  
			AppPackage pack = new AppPackage();
			String filename_new = Long.toString(System.currentTimeMillis()+1) + ".dat";
			String packFile = SystemParas.getAppStorePath() + "/" + filename_new;
			if(pack.packFile(packVersion,tagInfo,packFile)){
				File file = new File(SystemParas.getAppStorePath() + "/" + tempFile);
				if(file.exists())
				{
					file.delete();
				}
				File file1 = new File(packFile);
				ver.setValue("SavePath",packFile);
				ver.setValue("FileSize",Integer.toString((int)file1.length()));
				if(ver.insert())
				{
					FileSystem fs = new FileSystem();
					fs.copyFile(packFile,SystemParas.getAppStorePath_bak() + "/" + filename_new);
					fs.copyFile(packFile,SystemParas.getAppStorePath_pri() + "/" + filename_new);
					strErrorInfo = LangAction.langAction.getSuccess_upload();
					insertSucc = true;
				}
				else{
					strErrorInfo = LangAction.langAction.getFailed_insert();
				}
			}else{
				strErrorInfo = LangAction.langAction.getFailed_package();
			}

			if(insertSucc){
				WorkFlow flow = new WorkFlow();
				String subject = LangWorkflow.langWF.getWFTitle("28") + "["+strAddUser+"]:"+asVersion;
				flow.setValue("FlowType", "28");
				flow.setValue("ImportanceLevel", LangWorkflow.langWF.getLevel_high());
				flow.setValue("SecretLevel", LangWorkflow.langWF.getLevel_normal());
				flow.setValue("Subject", subject);
				flow.setValue("Content", ver.toString());
				flow.setValue("ShortString1", ver.getAppStoreIdBySavePath(ver.getValue("SavePath")));
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
%>
<html>

<head>
<TITLE><%=LangPage.langPage.getPageTitle("newAppStore")%></TITLE>
	<meta http-equiv="Pragma" content="no-cache">
	<SCRIPT language="JavaScript" type="text/javascript" src="../../js_gb/jwdf_check.js"></SCRIPT>
	<link rel="stylesheet" type="text/css" href="../../css/jwdf_main.css">
	<link rel="stylesheet" type="text/css" href="../../css/jwdf_swin.css">
	<SCRIPT language="JavaScript" type="text/javascript" src="../../js_gb/jwdf_util.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../../js_gb/jwdf_xml.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../../js_gb/jwdf_view.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../../js_gb/jwdf_swin.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../../<%=LangPage.langPage.getJs_path()%>sps_workflow_u.js"></SCRIPT>
	<script language=javascript>
	function check(){ 
		if (validateVersion()) {
			arr = NewForm.UploadFile.value.split("\\");
			filename = arr[arr.length-1];
			filename = filename.toLowerCase();
			if(filename == "phsh.vxp"){
				NewForm.submit();
			} else {   
				alert("<%=LangPage.langPage.getAppstore_filename_error()%>");
				return false;   
  			}   
		}
	}   

	function validateVersion() {
		version = NewForm.ASVersion.value ;
		rule = /^(\d+\.){2}(\d+)$/;
		if ( rule.test(version)) {
			return true ;
		} else {
			alert("AppStore 版本格式不正确！（请按如下格式填写：3.0.0）");
			return false ;
		}
	}

		function setScreen(type){
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

		<!------------------页面初始化---------------------->
				function init(){
		<%if(wfStatus == 1){%>
					cur_flowid = <%=flowId%>;
					openWFNodeSet();
		<%}%>					
				}
		<!------------------------------------------------------------->
  </script>  
</head>

<body scroll="no" onload="init();">
	<table width="100%" border="0" cellspacing="0" cellpadding="0" align="center">
		<tr>
			<td class="td_buttonbar" valign="middle" style="font-size:9pt;color:red;">
				&nbsp;<%=strErrorInfo%>
			</td>
		</tr>
	</table>

	<table id="tb_new" class="table_edit" cellpadding="0" cellspacing="0" align="center">
		<tr>
			<td>
				<table class="table_detaillist" cellpadding="0" cellspacing="1" align="center">
				<form method="POST" action="newAppStore3.jsp?edit=1" name="NewForm" ENCTYPE="multipart/form-data">
					<input class="input_edit" type="hidden" name="TopPrice" value="0"></input>
					<tr>
						<td class="td_detailcontent1" align="center"><%=app.getAliasByFiled("PackVersion") %>：</td>
						<td class="td_detailcontent0">
							<select name="PackVersion">
								<option selected value="AS3.0">3.0</option>
							</select>
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" width="25%" align="center"><%=app.getAliasByFiled("ASVersion") %>：</td>
						<td class="td_detailcontent0" width="75%">
							<input class="input_edit" style="width:100%;" onkeydown="enterFloat();" type="text" name="ASVersion" value="<%=asVersion%>">
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=app.getAliasByFiled("VersionType") %>：</td>
						<td class="td_detailcontent0">
							<select name="VersionType">
								<option<%if(versionType.equals("1")){%> selected<%}%> value="1"><%=LangPage.langPage.getSelect("app_all")%></option>
								<option<%if(versionType.equals("2")){%> selected<%}%> value="2"><%=LangPage.langPage.getSelect("app_type")%></option>
								<option<%if(versionType.equals("3")){%> selected<%}%> value="3"><%=LangPage.langPage.getSelect("app_mobile")%></option>
							</select>
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=app.getAliasByFiled("CertId") %>：</td>
						<td class="td_detailcontent0">
							<select name="CertId">
								<option<%if(certId.equals("2")){%> selected<%}%> value="2"><%=LangPage.langPage.getSelect("cert_seccert")%></option>
								<option<%if(certId.equals("3")){%> selected<%}%> value="3"><%=LangPage.langPage.getSelect("cert_thirdcert")%></option>
								<option<%if(certId.equals("4")){%> selected<%}%> value="4"><%=LangPage.langPage.getSelect("cert_fourcert")%></option>
							</select>
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=app.getAliasByFiled("VREVersion") %>：</td>
						<td class="td_detailcontent0">
							<input class="input_edit" style="width:100%;" onkeydown="enterFloat();" type="text" name="VREVersion" value="<%=vreVersion%>">
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=app.getAliasByFiled("MemorySize") %>：</td>
						<td class="td_detailcontent0">
							<input class="input_edit" style="width:100%;" onkeydown="enterUnsigned();" type="text" name="MemorySize" value="<%=memorySize%>">
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=app.getAliasByFiled("ScreenType") %>：</td>
						<td class="td_detailcontent0">
							<input type="radio"<%if(screen.equals("1")){out.print(" checked");}%> name="ScreenType" value="1" onclick="setScreen(1);"><%=LangPage.langPage.getSelect("screen_qcif")%>&nbsp;&nbsp;
							<input type="radio"<%if(screen.equals("2")){out.print(" checked");}%> name="ScreenType" value="2" onclick="setScreen(2);"><%=LangPage.langPage.getSelect("screen_qvga")%>&nbsp;&nbsp;
							<input type="radio"<%if(screen.equals("4")){out.print(" checked");}%> name="ScreenType" value="4" onclick="setScreen(4);"><%=LangPage.langPage.getSelect("screen_wqvga")%>
							<input type="radio"<%if(screen.equals("0")){out.print(" checked");}%> name="ScreenType" value="0" onclick="setScreen(0);"><%=LangPage.langPage.getSelect("screen_adaptive")%>
							<input type="radio"<%if(screen.equals("9")){out.print(" checked");}%> name="ScreenType" value="8" onclick="setScreen(8);"><%=LangPage.langPage.getSelect("screen_other")%><br>
							<%=app.getAliasByFiled("ScreenWidth") %><input type="text" onkeydown="enterUnsigned();" name="ScreenWidth" style="width:80;" value="<%=screenWidth%>">&nbsp;&nbsp;<%=app.getAliasByFiled("ScreenHeight") %><input type="text" onkeydown="enterUnsigned();" name="ScreenHeight" style="width:80;" value="<%=screenHeight%>">
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=app.getAliasByFiled("InputDC") %>：</td>
						<td class="td_detailcontent0">
							<input type="checkbox"<%if(input_keypad!=null){out.print(" checked");}%> name="Input_Keypad"><%=LangPage.langPage.getSelect("screen_keypad")%>&nbsp;&nbsp;
							<input type="checkbox"<%if(input_touch!=null){out.print(" checked");}%> name="Input_Touch"><%=LangPage.langPage.getSelect("screen_touch")%>
							<input type="checkbox"<%if(input_zl!=null){out.print(" checked");}%> name="Input_ZL"><%=LangPage.langPage.getSelect("screen_gravitysensor")%>
							<input type="checkbox"<%if(input_gx!=null){out.print(" checked");}%> name="Input_GX"><%=LangPage.langPage.getSelect("screen_opticalsensor")%>
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=app.getAliasByFiled("MobileList") %>：</td>
						<td class="td_detailcontent0"><textarea name="MobileList" class="input_textarea"><%=mobileList%></textarea></td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=app.getAliasByFiled("FileName") %>：</td>
						<td class="td_detailcontent0">
							<input class="input_edit" type="file" name="UploadFile" value="" style="width:250;"></input>
						</td>
					</tr>					
					<tr>
						<td class="td_detailcontent1" align="center"><%=app.getAliasByFiled("Remark") %>：</td>
						<td class="td_detailcontent0"><textarea name="Remark" class="input_textarea"><%=remark%></textarea></td>
					</tr>
					<tr>
						<td colspan="4" align="center" valign="middle" class="td_editbutton">
							<a href="#" onclick="check();"><img src="../../<%=LangPage.langPage.getButton_img_path()%>submit_001.gif" border="0" align="top" vspace="1" /></a>
						</td>
					</tr>
				</form>
				</table>
			</td>
		</tr>
	</table>
</body>

</html>