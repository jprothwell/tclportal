<%@ page contentType="text/html;charset=gb2312"%>   
<%@ page import="com.oa.workflow.db.WFAttachment"%>
<%@ page import="org.jwdf.util.DateUtil"%>
<%@ page import="org.jwdf.framework.console.Console"%>
<%@ page import="com.jspsmart.upload.*"%>
<jsp:useBean id="mySmartUpload" scope="page" class="com.jspsmart.upload.SmartUpload" />
<%
	String strEdit = request.getParameter("edit");
	String attachmentId = request.getParameter("AttachmentId");
	if(strEdit == null) strEdit = "0";
	if(attachmentId == null) attachmentId = "";

	String strErrorInfo = "";
	if(attachmentId.equals("")){
		strErrorInfo = "没有选择要修改的工作流附件！";
	}
	else if(strEdit.equals("1"))
	{
		WFAttachment attach = new WFAttachment();
		if(attach.getInfo(attachmentId)){
			mySmartUpload.initialize(pageContext);
			Request myRequest = mySmartUpload.getRequest();
			mySmartUpload.upload();
		
			com.jspsmart.upload.File myContentFile = mySmartUpload.getFiles().getFile(0);
			String ContentFileName = myContentFile.getFileName();
				
			boolean blnIsHave = false;
			String filePath = WFAttachment.OA_WORKFLOW_ATTACHMENT_SAVE_PATH + "/" + attach.getValue("FlowId") + "_" + Long.toString(System.currentTimeMillis())+".dat";
			if(!myContentFile.isMissing())
			{
				myContentFile.saveAs(filePath,SmartUpload.SAVE_PHYSICAL);
				blnIsHave = true;
			}
				
			if(!blnIsHave)
			{
				strErrorInfo = "没有找到上传的文件！"; 
			}
			String staffId = (String)Console.getSessionValue(request,"UserName");
				
			attach.setValue("AttachmentPath",filePath);
			attach.setValue("AttachmentName",ContentFileName);
			attach.setValue("AttachmentSize",Integer.toString(myContentFile.getSize()));
			attach.setValue("UploadTime",DateUtil.getFullDateTime());
			attach.setValue("UploadStaff",staffId);
			if(attach.update())
			{
				strErrorInfo = "上传成功！";
			}
			else{
				strErrorInfo = "[上传失败]"+attach.getErrorInfo();
			}
		}else{
			strErrorInfo = "要修改的附件没有找到！";
		}
	}
%>
<html>

<head>
<TITLE>修改附件</TITLE>
	<meta http-equiv="Pragma" content="no-cache">
	<link rel="stylesheet" type="text/css" href="../../css/jwdf_main.css">
</head>

<body>
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
					<form method="POST" action="updateattach.jsp?AttachmentId=<%=attachmentId%>&edit=1" name="NewForm" ENCTYPE="multipart/form-data">
					<tr>
						<td width="30%" class="td_detailcontent1" align="center">上传文件：</td>
						<td width="70%" class="td_detailcontent0">
							<input class="input_edit" type="file" name="UploadFile" value=""></input>
						</td>
					</tr>					
					<tr>
						<td colspan="2" align="center" valign="middle" class="td_editbutton">
							<input type="button"  value="提交" onclick="NewForm.submit();" class="button" onmouseover="this.className='buttonover';"  onmouseout="this.className='button';">&nbsp;&nbsp;
						</td>
					</tr>
					</form>
				</table>
			</td>
		</tr>
	</table>
</body>

</html>