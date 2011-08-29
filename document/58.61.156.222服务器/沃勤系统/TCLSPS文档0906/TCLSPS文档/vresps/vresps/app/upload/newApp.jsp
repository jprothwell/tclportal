<%@ page contentType="text/html;charset=utf-8"%>  
<%@ page import="com.language.langdata.LangPage"%> 
<%@ page import="com.language.langdata.LangAction"%>
<%@ page import="com.language.langdata.LangWorkflow"%>
<%@ page import="org.jwdf.framework.console.*"%>
<%@ page import="org.jwdf.util.*"%>
<%@ page import="java.io.File"%>
<%@ page import="com.vogins.gif.GifUtils"%>
<%@ page import="com.vogins.sps.db.app.Application"%>
<%@ page import="com.oa.workflow.db.*"%>
<%@ page import="com.vogins.workflow.db.TApplication"%>
<%@ page import="com.vogins.sps.db.app.GenerateAppId"%>
<%@ page import="com.vogins.sps.db.DBConstants"%>
<%@ page import="com.vogins.sps.init.SystemParas"%>
<%@ page import="com.vogins.sps.util.StringUtil"%>
<%@ page import="com.jspsmart.upload.*"%>
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangDBTable"%>
<jsp:useBean id="mySmartUpload" scope="page" class="com.jspsmart.upload.SmartUpload" />
<%	
	Application appli=new Application();
	
	String strEdit = request.getParameter("edit");
	String cpId = request.getParameter("CPId");
	if(strEdit == null) strEdit = "0";
	if(cpId == null) cpId = "";

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
	String picToAdd = "";	//20100622_产品图标合成
	String strPicSortErrorInfo = "";//20100622_产品图标合成
	
	String freeFlag="0";  //20100728_产品添加免费标识
	String strErrorInfo = "";
	String flowId = "";
	int wfStatus = 0;
	if(strEdit.equals("1")) 
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
		picToAdd = myRequest.getParameter("picToAdd");
		
		freeFlag=myRequest.getParameter("freeFlag");
		
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
		if(picToAdd == null) picToAdd = "0";
		
		if(freeFlag==null || freeFlag.equals("")) freeFlag="0";
		
		appName = new String(appName.getBytes(),"UTF-8");
		appNameBig5 = new String(appNameBig5.getBytes(),"UTF-8");
		manual = new String(manual.getBytes(),"UTF-8");
		appDesc = new String(appDesc.getBytes(),"UTF-8");
		searchWord = new String(searchWord.getBytes(),"UTF-8");
		
		if(cpId.equals("")){ 
			strErrorInfo = LangAction.langAction.getNoselect_cp();
		}else if(appName.equals("")){ 
			strErrorInfo = LangPage.langPage.getPlease_input()+appli.getAliasByFiled("AppName");
		}else	{
			com.jspsmart.upload.File myContentFile = mySmartUpload.getFiles().getFile(0);
			String ContentFileName = myContentFile.getFileName(); 
			String extName = StringUtil.getFileExtName(ContentFileName); 
			String tempFile = Long.toString(System.currentTimeMillis()) + "." + extName;
			if(!myContentFile.isMissing()) 
			{	
				if("gif".equalsIgnoreCase(extName)){	//20100622_产品图标合成
					myContentFile.saveAs(SystemParas.getReportPath() + "/" + tempFile,SmartUpload.SAVE_PHYSICAL);
					File file = new File(SystemParas.getReportPath() + "/" + tempFile);
					if(file.exists()){
						switch(Integer.parseInt(picToAdd)){
						case 0:{
							myContentFile.saveAs(SystemParas.getIcon_app() + "/" + tempFile,SmartUpload.SAVE_PHYSICAL);
							break;
						}
						case 1:{
							GifUtils.pressImage(SystemParas.getReportPath() + "/" + tempFile, SystemParas.getIcon_app()+"/picToAdd/application_free.gif", SystemParas.getIcon_app() + "/" + tempFile, 3, 1f);
							break;
						}
						case 2:{
							GifUtils.pressImage(SystemParas.getReportPath() + "/" + tempFile, SystemParas.getIcon_app()+"/picToAdd/application_new.gif", SystemParas.getIcon_app() + "/" + tempFile, 3, 1f);
							break;
						}
						case 3:{
							GifUtils.pressImage(SystemParas.getReportPath() + "/" + tempFile, SystemParas.getIcon_app()+"/picToAdd/application_recommend.gif", SystemParas.getIcon_app() + "/" + tempFile, 3, 1f);
							break;
						}
						case 4:{
							GifUtils.pressImage(SystemParas.getReportPath() + "/" + tempFile, SystemParas.getIcon_app()+"/picToAdd/application_hot.gif", SystemParas.getIcon_app() + "/" + tempFile, 3, 1f);
							break;
						}
						default:{
							myContentFile.saveAs(SystemParas.getIcon_app() + "/" + tempFile,SmartUpload.SAVE_PHYSICAL);
							break;
						}
						}
					}
					File picResultFile = new File(SystemParas.getIcon_app() + "/" + tempFile);
					if(!picResultFile.exists()){
						strPicSortErrorInfo = LangAction.langAction.getFailToCombination();
					}
				}else{
					strPicSortErrorInfo = LangAction.langAction.getIncorrectPicSort();
				}
				if("".equals(strPicSortErrorInfo)){		//20100622_产品图标合成
				
					String sessionId = Console.session_manager.getSessionId(request);
					String strAddUser = Console.session_manager.get(sessionId).getUserName();
	
					TApplication app = new TApplication(); 
					app.setValue("AppId", GenerateAppId.generateAppId(cpId));
					app.setValue("AppCode", appCode);
					app.setValue("CPId", cpId);
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
					app.setValue("DownloadCount","0");
					app.setValue("LevelFlag",levelFlag);
					app.setValue("AddTime", DateUtil.getFullDateTime());
					app.setValue("AddUser", strAddUser);
					app.setValue("RemoveFlag", DBConstants.RECORD_NORMAL);
					
					app.setValue("FreeFlag",freeFlag);
					
					if(app.insert()){ 
						myContentFile.saveAs(SystemParas.getIcon_app() + "_pri/" + tempFile,SmartUpload.SAVE_PHYSICAL);
						myContentFile.saveAs(SystemParas.getIcon_app() + "_bak/" + tempFile,SmartUpload.SAVE_PHYSICAL);
						
					
						strErrorInfo = LangAction.langAction.getSuccess_insert();
						String subject = LangWorkflow.langWF.getWFTitle("15") + "["+strAddUser+"]:"+appName;
						WorkFlow flow = new WorkFlow();
						flow.setValue("FlowType", "15");
						flow.setValue("ImportanceLevel", LangWorkflow.langWF.getLevel_high());
						flow.setValue("SecretLevel", LangWorkflow.langWF.getLevel_normal());
						flow.setValue("Subject", subject);
						flow.setValue("Content", app.toString());
						flow.setValue("ShortString1", app.getValue("AppId"));
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
							app.delete();
							strErrorInfo = LangWorkflow.langWF.getFailed_create_workflow();
						}
					}else{
						strErrorInfo = LangAction.langAction.getFailed_insert();
					}
				}else{
					strErrorInfo = strPicSortErrorInfo;
				}
			}else{
				strErrorInfo = LangAction.langAction.getNoselect_uploadfile(); 
			}
		}
	}
%>
<html>

<head>
<TITLE><%=LangPage.langPage.getPageTitle("newApp")%></TITLE>
	<meta http-equiv="Pragma" content="no-cache">
	<SCRIPT language="JavaScript" type="text/javascript" src="../../js_gb/jwdf_check.js"></SCRIPT>
	<link rel="stylesheet" type="text/css" href="../../css/jwdf_main.css">
	<link rel="stylesheet" type="text/css" href="../../css/jwdf_swin.css">
	<SCRIPT language="JavaScript" type="text/javascript" src="../../js_gb/jwdf_util.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../../js_gb/jwdf_xml.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../../js_gb/jwdf_view.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../../js_gb/jwdf_swin.js"></SCRIPT>
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
				<form method="POST" action="newApp.jsp?CPId=<%=cpId%>&edit=1" name="NewForm" ENCTYPE="multipart/form-data">
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
						<td class="td_detailcontent1"><%=appli.getAliasByFiled("FreeFlag")%></td>
						<td class="td_detailcontent0"><input class="input_edit" onkeydown="enterUnsigned();" style="width:100%;" type="hidden" name="TopPrice" value="<%=topPrice%>">
                                                                     收费<input type="radio" name="freeFlag" value = "0" checked="checked" >&nbsp;&nbsp;&nbsp;&nbsp;
						     免费<input type="radio" name="freeFlag" value = "1"></td>
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
						<td class="td_detailcontent1"><%=LangPage.langPage.getPageTitle("picToAdd")%></td>
						<td colspan="3" class="td_detailcontent0">
							<img src="../images/view_free.gif">
							<input type="radio" name="picToAdd"  value = "1">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<img src="../images/view_new.gif">
							<input type="radio" name="picToAdd" value = "2">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<img src="../images/view_recommend.gif">
							<input type="radio" name="picToAdd" value = "3">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<img src="../images/view_hot.gif">
							<input type="radio" name="picToAdd" value = "4">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" ><%=appli.getAliasByFiled("IconPath")%></td>
						<td colspan="3" class="td_detailcontent0">
							<input class="input_edit" type="file" name="UploadFile" value="" style="width:300;"></input>
						</td>
					</tr>					
					<tr>
						<td colspan="4" align="center" valign="middle" class="td_editbutton">
							<a href="#" onclick="NewForm.submit();"><img src="../../<%=LangPage.langPage.getButton_img_path()%>/submit_001.gif" border="0" align="top" vspace="1" /></a>
						</td>
					</tr>
				</form>
				</table>
			</td>
		</tr>
	</table>

</body>

</html>
