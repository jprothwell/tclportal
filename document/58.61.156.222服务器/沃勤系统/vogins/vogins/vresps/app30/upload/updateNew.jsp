<%@ page contentType="text/html;charset=utf-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangAction"%>
<%@ page import="com.vogins.sps.db.app.*"%>
<%@ page import="org.jwdf.io.*"%>
<%@ page import="org.jwdf.framework.base.AbstractTableBean"%>
<%@ page import="com.vogins.sps.init.SystemParas"%>
<%@ page import="com.vogins.sps.pack.AppPackage"%>
<%@ page import="com.vogins.sps.db.app30.NewFolder"%>
<%@ page import="com.vogins.sps.util.StringUtil"%>
<%@ page import="java.io.File"%>
<%@ page import="com.jspsmart.upload.*"%>
<jsp:useBean id="mySmartUpload" scope="page" class="com.jspsmart.upload.SmartUpload" />
<%
	NewFolder fol = new NewFolder();

	String strEdit = request.getParameter("edit");
	String folderId = request.getParameter("FolderId");
	if(strEdit == null) strEdit = "0";
	if(folderId == null) folderId = "";

	String folderName = "";
	String seqRule = "";

	String fileName = "";

	String strErrorInfo = "";
	if(folderId.equals("")){
		strErrorInfo = LangAction.langAction.getNoselect_folder();
	}
	else if(strEdit.equals("1"))
	{
		mySmartUpload.initialize(pageContext);
		Request myRequest = mySmartUpload.getRequest();
		mySmartUpload.upload();

		folderName = myRequest.getParameter("FolderName");
		seqRule = myRequest.getParameter("SeqRule");
		if(folderName == null) folderName = "";
		if(seqRule == null) seqRule = "";
		
		if(folderName.equals("")){
			strErrorInfo = LangPage.langPage.getPlease_input()+fol.getAliasByFiled("FolderName");
		}else	{
			com.jspsmart.upload.File myContentFile = mySmartUpload.getFiles().getFile(0);
			String ContentFileName = myContentFile.getFileName();
			
			String extName = StringUtil.getFileExtName(ContentFileName);
			String tempFile = Long.toString(System.currentTimeMillis()) + "." + extName;
			if(!myContentFile.isMissing())
			{
				myContentFile.saveAs(SystemParas.getIcon_new() + "/" + tempFile,SmartUpload.SAVE_PHYSICAL);

				NewFolder more = new NewFolder();
				if(more.getInfo(folderId)){
					more.setValue("FolderName",folderName);
					more.setValue("SeqRule",seqRule);
					more.setValue("IconName",ContentFileName);
					more.setValue("IconPath",SystemParas.getIcon_new() + "/" + tempFile);
					if(more.update()){
						myContentFile.saveAs(SystemParas.getIcon_new() + "_pri/" + tempFile,SmartUpload.SAVE_PHYSICAL);
						myContentFile.saveAs(SystemParas.getIcon_new() + "_bak/" + tempFile,SmartUpload.SAVE_PHYSICAL);
						strErrorInfo = LangAction.langAction.getSuccess_update();
					}else{
						strErrorInfo = LangAction.langAction.getFailed_update();
					}
				}else{
					strErrorInfo = LangAction.langAction.getRecord_not_exist();
				}
			}else{
				NewFolder more = new NewFolder();
				if(more.getInfo(folderId)){
					more.setValue("FolderName",folderName);
					more.setValue("SeqRule",seqRule);
					if(more.update()){
						strErrorInfo =  LangAction.langAction.getSuccess_update();
					}else{
						strErrorInfo = LangAction.langAction.getFailed_update();
					}
				}else{
					strErrorInfo =  LangAction.langAction.getRecord_not_exist();
				}
			}
		}
	}
	else{
		NewFolder mfolder = new NewFolder();
		mfolder.getInfo(folderId);
		folderName = mfolder.getValue("FolderName");
		seqRule = mfolder.getValue("SeqRule");
		fileName = mfolder.getValue("IconName");
	}
%>
<html>

<head>
<TITLE><%=LangPage.langPage.getPageTitle("updateNew")%></TITLE>
	<meta http-equiv="Pragma" content="no-cache">
	<SCRIPT language="JavaScript" type="text/javascript" src="../../js/jwdf_check.js"></SCRIPT>
	<link rel="stylesheet" type="text/css" href="../../css/jwdf_main.css">
</head>

<body scroll="no">
	<table id="tb_new" class="table_edit" cellpadding="0" cellspacing="0" align="center">
		<tr>
			<td>
				<table class="table_detaillist" cellpadding="0" cellspacing="1" align="center">
				<form method="POST" action="updateNew.jsp?FolderId=<%=folderId%>&edit=1" name="NewForm" ENCTYPE="multipart/form-data">
					<tr>
						<td height="20" colspan="1" bgcolor="#8acef5"><b><%=LangPage.langPage.getPageTitle("updateNew")%></b></td>
						<td height="20" align="right" bgcolor="#8acef5" style="color:red;"><%=strErrorInfo%></td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=fol.getAliasByFiled("FolderName")%>：</td>
						<td class="td_detailcontent0">
							<input class="input_edit" style="width:100%;" type="text" name="FolderName" maxlength="24" value="<%=folderName%>">
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=fol.getAliasByFiled("SeqRule")%>：</td>
						<td class="td_detailcontent0">
							<textarea name="SeqRule" class="input_textarea"><%=seqRule%></textarea>
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=fol.getAliasByFiled("IconPath")%>：</td>
						<td class="td_detailcontent0">
							<input class="input_edit" type="file" name="UploadFile" value="" style="width:200;"></input><%if(!fileName.equals("")){out.println("("+fileName+")");}%>
						</td>
					</tr>					
					<tr>
						<td colspan="4" align="center" valign="middle" class="td_editbutton">
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