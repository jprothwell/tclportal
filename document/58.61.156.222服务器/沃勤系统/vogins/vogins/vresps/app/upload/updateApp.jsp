<%@ page contentType="text/html;charset=utf-8"%> 
<%@ page import="com.language.langdata.LangPage"%>  
<%@ page import="com.language.langdata.LangAction"%>
<%@ page import="com.language.langdata.LangWorkflow"%>
<%@ page import="com.vogins.sps.db.app.*"%>
<%@ page import="org.jwdf.io.*"%>
<%@ page import="org.jwdf.util.DateUtil"%>
<%@ page import="org.jwdf.framework.console.Console"%>
<%@ page import="com.vogins.sps.db.app.Application"%>
<%@ page import="com.vogins.sps.db.app.AppFolder"%>
<%@ page import="com.vogins.sps.db.app30.MoreApp"%>
<%@ page import="com.vogins.sps.db.app30.RecommendApp"%>
<%@ page import="com.oa.workflow.db.*"%>
<%@ page import="com.vogins.workflow.db.TApplication"%>
<%@ page import="com.vogins.sps.init.SystemParas"%>
<%@ page import="com.vogins.sps.util.StringUtil"%>
<%@ page import="java.io.File"%>
<%@ page import="java.util.Hashtable"%>
<%@ page import="com.jspsmart.upload.*"%>
<jsp:useBean id="mySmartUpload" scope="page" class="com.jspsmart.upload.SmartUpload" />
<%
	Application appli = new Application();

	String strEdit = request.getParameter("edit");
	String appId = request.getParameter("AppId");
	if(strEdit == null) strEdit = "0";
	if(appId == null) appId = "";

	String appCode = "";
	String appName = "";
	String appNameBig5 = "";
	String appNameEn = "";
	String levelFlag = "0";
	String appType = "";
	String price = "0";
	String topPrice = "0";
	String manual = "";
	String appDesc = "";
	String searchWord = "";

	String fileName = "";

	String strErrorInfo = "";
	String flowId = "";
	int wfStatus = 0;
	if(appId.equals("")){
		strErrorInfo = LangAction.langAction.getNoselect_app();
	}
	else if(strEdit.equals("1"))
	{
		mySmartUpload.initialize(pageContext);
		Request myRequest = mySmartUpload.getRequest();
		mySmartUpload.upload();

		appCode = myRequest.getParameter("AppCode");
		appName = myRequest.getParameter("AppName");
		appNameBig5 = myRequest.getParameter("AppNameBig5");
		appNameEn = myRequest.getParameter("AppNameEn");
		levelFlag = myRequest.getParameter("LevelFlag");
		appType = myRequest.getParameter("AppType");
		price = myRequest.getParameter("Price");
		topPrice = myRequest.getParameter("TopPrice");
		manual = myRequest.getParameter("Manual");
		appDesc = myRequest.getParameter("AppDesc");
		searchWord = myRequest.getParameter("SearchWord");
		
		if(appCode == null) appCode = "";
		if(appName == null) appName = "";
		if(appNameBig5 == null) appNameBig5 = "";
		if(appNameEn == null) appNameEn = "";
		if(levelFlag == null || levelFlag.equals("")) levelFlag = "0";
		if(appType == null || appType.equals("")) appType = "1";
		if(price == null || price.equals("")) price = "0";
		if(topPrice == null || topPrice.equals("")) topPrice = "0";
		if(manual == null) manual = "";
		if(appDesc == null) appDesc = "";
		if(searchWord == null) searchWord = "";
		
		appName = new String(appName.getBytes(),"UTF-8");
		appNameBig5 = new String(appNameBig5.getBytes(),"UTF-8");
		manual = new String(manual.getBytes(),"UTF-8");
		appDesc = new String(appDesc.getBytes(),"UTF-8");
		searchWord = new String(searchWord.getBytes(),"UTF-8");
		
		if(appName.equals("")){
			strErrorInfo = LangPage.langPage.getPlease_input()+appli.getAliasByFiled("AppName");
		}else	{
			com.jspsmart.upload.File myContentFile = mySmartUpload.getFiles().getFile(0);
			String ContentFileName = myContentFile.getFileName();
			
			String extName = StringUtil.getFileExtName(ContentFileName);
			String tempFile = Long.toString(System.currentTimeMillis()) + "." + extName;

			String sessionId = Console.session_manager.getSessionId(request);
			String strAddUser = Console.session_manager.get(sessionId).getUserName();

			TApplication app = new TApplication();
			if(app.getInfo(appId)){
				String oldData = app.toString();

				String wfType = "18";
				AppFolder af = new AppFolder();
				MoreApp ma = new MoreApp();
				RecommendApp ra = new RecommendApp();
				if(af.checkAppExist(appId) || ma.checkAppExist(appId) || ra.checkAppExist(appId)){
					wfType = "16";
				}
	
				boolean updateSucc = false;
				WorkFlow flow = new WorkFlow();
				Hashtable<String,String> paras = new Hashtable<String,String>();
				paras.put("ShortString1", appId);
				if(flow.checkExist("16", paras) || flow.checkExist("17", paras) || flow.checkExist("18", paras) || flow.checkExist("19", paras)){
					strErrorInfo = LangWorkflow.langWF.getRepeated_workflow_error();
				}else{
					if(!myContentFile.isMissing())
					{
						myContentFile.saveAs(SystemParas.getIcon_app() + "/" + tempFile,SmartUpload.SAVE_PHYSICAL);
						
						app.setValue("AppCode", appCode);
						app.setValue("AppType", appType);
						app.setValue("AppName", appName);
						app.setValue("AppNameBig5", appNameBig5);
						app.setValue("AppNameEn", appNameEn);
						app.setValue("Price", price);
						app.setValue("TopPrice", topPrice);
						app.setValue("Manual", manual);
						app.setValue("AppDesc", appDesc);
						app.setValue("IconName",ContentFileName);
						app.setValue("IconPath",SystemParas.getIcon_app() + "/" + tempFile);
						app.setValue("SearchWord",searchWord);
						app.setValue("LevelFlag",levelFlag);
						if(app.update()){
							updateSucc = true;
							myContentFile.saveAs(SystemParas.getIcon_app() + "_pri/" + tempFile,SmartUpload.SAVE_PHYSICAL);
							myContentFile.saveAs(SystemParas.getIcon_app() + "_bak/" + tempFile,SmartUpload.SAVE_PHYSICAL);
							strErrorInfo = LangAction.langAction.getSuccess_update();
						}else{
							strErrorInfo = LangAction.langAction.getFailed_update();
						}
					}else{
						app.setValue("AppCode", appCode);
						app.setValue("AppType", appType);
						app.setValue("AppName", appName);
						app.setValue("AppNameBig5", appNameBig5);
						app.setValue("AppNameEn", appNameEn);
						app.setValue("Price", price);
						app.setValue("TopPrice", topPrice);
						app.setValue("Manual", manual);
						app.setValue("AppDesc", appDesc);
						app.setValue("SearchWord",searchWord);
						app.setValue("LevelFlag",levelFlag);
						if(app.update()){
							updateSucc = true;
							strErrorInfo = LangAction.langAction.getSuccess_update();
						}else{
							strErrorInfo = LangAction.langAction.getFailed_update();
						}
					}
				}
				if(updateSucc){
					String subject = LangWorkflow.langWF.getWFTitle(wfType) + "["+strAddUser+"]:"+app.getValue("AppName");
					flow.setValue("FlowType", wfType);
					flow.setValue("ImportanceLevel", LangWorkflow.langWF.getLevel_high());
					flow.setValue("SecretLevel", LangWorkflow.langWF.getLevel_normal());
					flow.setValue("Subject", subject);
					flow.setValue("Content", "From:"+oldData+"\nTo:"+app.toString());
					flow.setValue("ShortString1", appId);
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
						Application oldApp = new Application();
						if(oldApp.getInfo(appId)){
							app.setValue("AppId", oldApp.getValue("AppId"));
							app.setValue("AppCode", oldApp.getValue("AppCode"));
							app.setValue("CPId", oldApp.getValue("CPId"));
							app.setValue("AppType", oldApp.getValue("AppType"));
							app.setValue("AppName", oldApp.getValue("AppName"));
							app.setValue("AppNameBig5", oldApp.getValue("AppNameBig5"));
							app.setValue("AppNameEn", oldApp.getValue("AppNameEn"));
							app.setValue("Price", oldApp.getValue("Price"));
							app.setValue("TopPrice", oldApp.getValue("TopPrice"));
							app.setValue("Manual", oldApp.getValue("Manual"));
							app.setValue("AppDesc", oldApp.getValue("AppDesc"));
							app.setValue("IconName", oldApp.getValue("IconName"));
							app.setValue("IconPath", oldApp.getValue("IconPath"));
							app.setValue("SearchWord", oldApp.getValue("SearchWord"));
							app.setValue("DownloadCount", oldApp.getValue("DownloadCount"));
							app.setValue("LevelFlag", oldApp.getValue("LevelFlag"));
							app.setValue("AddTime", oldApp.getValue("AddTime"));
							app.setValue("AddUser", oldApp.getValue("AddUser"));
							app.setValue("RemoveFlag", oldApp.getValue("RemoveFlag"));
							app.update();
						}
						strErrorInfo = LangWorkflow.langWF.getFailed_create_workflow();
					}
				}
			}else{
				strErrorInfo = LangAction.langAction.getRecord_not_exist();
			}
		}
	}
	else{
		Application app = new Application();
		app.getInfo(appId);
		appCode = app.getValue("AppCode");
		appName = app.getValue("AppName");
		appNameBig5 = app.getValue("AppNameBig5");
		appNameEn = app.getValue("AppNameEn");
		appType = app.getValue("AppType");
		price = app.getValue("Price");
		topPrice = app.getValue("TopPrice");
		manual = app.getValue("Manual");
		appDesc = app.getValue("AppDesc");
		fileName = app.getValue("IconName");
		searchWord = app.getValue("SearchWord");
		levelFlag = app.getValue("LevelFlag");
	}
%>
<html>

<head>
<TITLE><%=LangPage.langPage.getPageTitle("updateApp")%></TITLE>
	<meta http-equiv="Pragma" content="no-cache">
	<SCRIPT language="JavaScript" type="text/javascript" src="../../js/jwdf_check.js"></SCRIPT>
	<link rel="stylesheet" type="text/css" href="../../css/jwdf_main.css">
	<link rel="stylesheet" type="text/css" href="../../css/jwdf_swin.css">
	<SCRIPT language="JavaScript" type="text/javascript" src="../../js/jwdf_util.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../../js/jwdf_xml.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../../js/jwdf_view.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../../js/jwdf_swin.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../../<%=LangPage.langPage.getJs_path()%>sps_workflow_u1.js"></SCRIPT>
	<script language=javascript>
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
	<table id="tb_new" class="table_edit" cellpadding="0" cellspacing="0" align="center">
		<tr>
			<td>
				<table class="table_detaillist" cellpadding="0" cellspacing="1" align="center">
				<form method="POST" action="updateApp.jsp?AppId=<%=appId%>&edit=1" name="NewForm" ENCTYPE="multipart/form-data">
					<tr>
						<td height="20" bgcolor="#8acef5"><b><%=LangPage.langPage.getWindowsTitle("mobile_appinfo")%></b></td>
						<td colspan="3" height="20" align="right" bgcolor="#8acef5" style="color:red;"><%=strErrorInfo%></td>
					</tr>
					<tr>
						<td class="td_detailcontent1"><%=appli.getAliasByFiled("AppName")%></td>
						<td class="td_detailcontent0"><input class="input_edit" style="width:100%;" maxlength="20" type="text" name="AppName" value="<%=appName%>"></td>
						<td class="td_detailcontent1"><%=appli.getAliasByFiled("LevelFlag")%></td>
						<td class="td_detailcontent0">
							<select name="LevelFlag">
								<option<%if(levelFlag.equals("0")){%> selected<%}%> value="0"><%=LangPage.langPage.getSelect("levelflag_unknow")%></option>
								<option<%if(levelFlag.equals("1")){%> selected<%}%> value="1"><%=LangPage.langPage.getSelect("levelflag_green")%></option>
								<option<%if(levelFlag.equals("2")){%> selected<%}%> value="2"><%=LangPage.langPage.getSelect("levelflag_org")%></option>
								<option<%if(levelFlag.equals("3")){%> selected<%}%> value="3"><%=LangPage.langPage.getSelect("levelflag_red")%></option>
							</select>
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1"><%=appli.getAliasByFiled("AppNameBig5")%></td>
						<td class="td_detailcontent0"><input class="input_edit" style="width:100%;" maxlength="20" type="text" name="AppNameBig5" value="<%=appNameBig5%>"></td>
						<td class="td_detailcontent1"><%=appli.getAliasByFiled("AppNameEn")%></td>
						<td class="td_detailcontent0"><input class="input_edit" style="width:100%;" maxlength="20" type="text" name="AppNameEn" value="<%=appNameEn%>"></td>
					</tr>
					<tr>
						<td class="td_detailcontent1" width="20%"><%=appli.getAliasByFiled("AppCode")%></td>
						<td class="td_detailcontent0" width="30%"><input class="input_edit" style="width:100%;" maxlength="30" type="text" name="AppCode" value="<%=appCode%>"></td>
						<td class="td_detailcontent1" width="20%"><%=appli.getAliasByFiled("AppType")%></td>
						<td class="td_detailcontent0" width="30%">
							<select name="AppType">
								<option<%if(appType.equals("1")){%> selected<%}%> value="1"><%=LangPage.langPage.getSelect("apptype_action")%></option>
								<option<%if(appType.equals("2")){%> selected<%}%> value="2"><%=LangPage.langPage.getSelect("apptype_chess")%></option>
								<option<%if(appType.equals("3")){%> selected<%}%> value="3"><%=LangPage.langPage.getSelect("apptype_roleplay")%></option>
								<option<%if(appType.equals("4")){%> selected<%}%> value="4"><%=LangPage.langPage.getSelect("apptype_software")%></option>
							</select>
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1"><%=appli.getAliasByFiled("Price")%></td>
						<td class="td_detailcontent0"><input class="input_edit" onkeydown="enterUnsigned();" style="width:100%;" type="text" name="Price" value="<%=price%>"></td>
						<td class="td_detailcontent1"><%=appli.getAliasByFiled("TopPrice")%></td>
						<td class="td_detailcontent0"><input class="input_edit" onkeydown="enterUnsigned();" style="width:100%;" type="text" name="TopPrice" value="<%=topPrice%>"></td>
					</tr>
					<tr>
						<td class="td_detailcontent1"><%=appli.getAliasByFiled("Manual")%></td>
						<td colspan="3" class="td_detailcontent0"><textarea name="Manual" onkeydown="checkLength('Manual',200);" class="input_textarea"><%=manual%></textarea></td>
					</tr>
					<tr>
						<td class="td_detailcontent1"><%=appli.getAliasByFiled("AppDesc")%></td>
						<td colspan="3" class="td_detailcontent0"><textarea name="AppDesc" class="input_textarea" onkeydown="checkLength('AppDesc',85);"><%=appDesc%></textarea></td>
					</tr>
					<tr>
						<td class="td_detailcontent1"><%=appli.getAliasByFiled("SearchWord")%></td>
						<td colspan="3" class="td_detailcontent0"><textarea name="SearchWord" class="input_textarea" onkeydown="checkLength('SearchWord',100);"><%=searchWord%></textarea></td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=appli.getAliasByFiled("IconPath")%></td>
						<td colspan="3" class="td_detailcontent0">
							<input class="input_edit" type="file" name="UploadFile" value="" style="width:200;"></input><%if(!fileName.equals("")){out.println("("+fileName+")");}%>
						</td>
					</tr>					
					<tr>
						<td colspan="4" align="center" valign="middle" class="td_editbutton">
							<a href="#" onclick="NewForm.submit();"><img src="../../<%=LangPage.langPage.getButton_img_path()%>submit_001.gif" border="0" align="top" vspace="1" /></a>
						</td>
					</tr>
				</form>
				</table>
			</td>
		</tr>
	</table>
</body>

</html>