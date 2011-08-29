<%@ page contentType="text/html;charset=utf-8"%> 
<%@ page import="com.language.langdata.LangPage"%>  
<%@ page import="com.language.langdata.LangAction"%>  
<%@ page import="org.jwdf.framework.console.*"%>
<%@ page import="org.jwdf.util.*"%>
<%@ page import="com.vogins.sps.db.app30.TopDldFolder"%>
<%@ page import="com.vogins.sps.init.SystemParas"%>
<%@ page import="com.vogins.sps.util.StringUtil"%>
<%@ page import="com.jspsmart.upload.*"%>
<jsp:useBean id="mySmartUpload" scope="page" class="com.jspsmart.upload.SmartUpload" />
<%
	TopDldFolder top = new TopDldFolder();

	String strEdit = request.getParameter("edit");
	String parentId = request.getParameter("ParentId");
	if(strEdit == null) strEdit = "0";
	if(parentId == null || parentId.equals("")) parentId = "0";

	String folderName = "";
	String seqRule = "";
	
	String strErrorInfo = "";
	if(strEdit.equals("1"))
	{
		mySmartUpload.initialize(pageContext);
		Request myRequest = mySmartUpload.getRequest();
		mySmartUpload.upload();

		folderName = myRequest.getParameter("FolderName");
		seqRule = myRequest.getParameter("SeqRule");
		
		if(folderName == null) folderName = "";
		if(seqRule == null) seqRule = "";
		
		if(folderName.equals("")){
			strErrorInfo = LangPage.langPage.getPlease_input()+top.getAliasByFiled("FolderName");
		}else	{
			com.jspsmart.upload.File myContentFile = mySmartUpload.getFiles().getFile(0);
			String ContentFileName = myContentFile.getFileName();
			
			String extName = StringUtil.getFileExtName(ContentFileName);
			String tempFile = Long.toString(System.currentTimeMillis()) + "." + extName;
			if(!myContentFile.isMissing())
			{
				myContentFile.saveAs(SystemParas.getIcon_topdld() + "/" + tempFile,SmartUpload.SAVE_PHYSICAL);

				String sessionId = Console.session_manager.getSessionId(request);
				String strAddUser = Console.session_manager.get(sessionId).getUserName();

				TopDldFolder more = new TopDldFolder();
				int level = more.getFolderLevel(parentId);
				if(level<=3){
					TopDldFolder subs[] = more.getSubFolder(parentId);
					if(subs.length<20){
						more.setValue("ParentId",parentId);
						more.setValue("SeqNo",more.getNewSeqNo(parentId));
						more.setValue("FolderName",folderName);
						more.setValue("SeqRule",seqRule);
						more.setValue("IconName",ContentFileName);
						more.setValue("IconPath",SystemParas.getIcon_topdld() + "/" + tempFile);
						more.setValue("AddTime",DateUtil.getFullDateTime());
						more.setValue("AddUser",strAddUser);
						if(more.insert()){
							myContentFile.saveAs(SystemParas.getIcon_topdld() + "_pri/" + tempFile,SmartUpload.SAVE_PHYSICAL);
							myContentFile.saveAs(SystemParas.getIcon_topdld() + "_bak/" + tempFile,SmartUpload.SAVE_PHYSICAL);
							strErrorInfo = LangAction.langAction.getSuccess_insert();
						}else{
							strErrorInfo = LangAction.langAction.getFailed_insert();
						}
					}else{
						strErrorInfo = LangAction.langAction.getOut_subfolder_count();
					}
				}else{
					strErrorInfo = LangAction.langAction.getOut_folder_level();
				}
			}else{
				strErrorInfo = LangAction.langAction.getNoselect_uploadfile(); 
			}
		}
	}
%>
<html>

<head>
<TITLE><%=LangPage.langPage.getPageTitle("newTopdld")%></TITLE>
	<meta http-equiv="Pragma" content="no-cache">
	<SCRIPT language="JavaScript" type="text/javascript" src="../../js/jwdf_check.js"></SCRIPT>
	<link rel="stylesheet" type="text/css" href="../../css/jwdf_main.css">
</head>

<body scroll="no">
	<table id="tb_new" class="table_edit" cellpadding="0" cellspacing="0" align="center">
		<tr>
			<td>
				<table class="table_detaillist" cellpadding="0" cellspacing="1" align="center">
				<form method="POST" action="newTopdld.jsp?ParentId=<%=parentId%>&edit=1" name="NewForm" ENCTYPE="multipart/form-data">
					<tr>
						<td height="20" colspan="1" bgcolor="#8acef5"><b><%=LangPage.langPage.getPageTitle("newTopdld")%></b></td>
						<td height="20" align="right" bgcolor="#8acef5" style="color:red;"><%=strErrorInfo%></td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=top.getAliasByFiled("FolderName") %>：</td>
						<td class="td_detailcontent0">
							<input class="input_edit" style="width:100%;" type="text" name="FolderName" maxlength="24" value="<%=folderName%>">
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=top.getAliasByFiled("SeqRule") %>：</td>
						<td class="td_detailcontent0">
							<textarea name="SeqRule" class="input_textarea"><%=seqRule%></textarea>
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=top.getAliasByFiled("IconPath") %>：</td>
						<td class="td_detailcontent0">
							<input class="input_edit" type="file" name="UploadFile" value="" style="width:300;"></input>
						</td>
					</tr>					
					<tr>
						<td colspan="2" align="center" valign="middle" class="td_editbutton">
							<a href="#" onclick="NewForm.submit();"><img src="../../<%=LangPage.langPage.getButton_img_path()%>submit_001.gif"   border="0" align="top" vspace="1" /></a>
						</td>
					</tr>
				</form>
				</table>
			</td>
		</tr>
	</table>

</body>

</html>