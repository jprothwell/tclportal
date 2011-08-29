<%@ page contentType="text/html;charset=GB2312"%>   
<%@ page import="com.oa.db.Message"%>
<%@ page import="com.oa.db.MsgAttachment"%>
<%@ page import="java.util.Vector"%>
<%@ page import="java.util.Hashtable"%>
<%@ page import="org.jwdf.util.DateUtil"%>
<%@ page import="org.jwdf.framework.console.Console"%>
<%@ page import="com.jspsmart.upload.*"%>
<jsp:useBean id="mySmartUpload" scope="page" class="com.jspsmart.upload.SmartUpload" />
<%
	String strEdit = request.getParameter("edit");
	if(strEdit == null) strEdit = "0";

	String receivers = "";
	String level = Message.OA_MESSAGE_LEVEL_NORMAL;
	String subject = "";
	String content = "";
	String reqReply = Message.OA_MESSAGE_NO_REQUEST_REPLY;
	String fileCount = "1";
	String staffId = (String)Console.getSessionValue(request,"UserName");
	
	String strErrorInfo = "";
	if(!strEdit.equals("0"))
	{
		mySmartUpload.initialize(pageContext);
		Request myRequest = mySmartUpload.getRequest();
		mySmartUpload.upload();
	
		receivers = myRequest.getParameter("Receivers");
		level = myRequest.getParameter("Level");
		subject = myRequest.getParameter("Subject");
		content = myRequest.getParameter("Content");
		reqReply = myRequest.getParameter("ReqReply");
		fileCount = myRequest.getParameter("FileCount");
		
		if(receivers == null) receivers = "";
		if(level == null || level.equals("")) level = Message.OA_MESSAGE_LEVEL_NORMAL;
		if(subject == null || subject.equals("")) subject = "无标题";
		if(content == null || content.equals("")) content = "无内容";
		if(reqReply == null || reqReply.equals("")) reqReply = Message.OA_MESSAGE_NO_REQUEST_REPLY;
		if(fileCount == null || fileCount.equals("")) fileCount = "1";
		
		if(receivers.equals("") && (strEdit.equals("1") || strEdit.equals("2")))
		{
			strErrorInfo = "没有指定收件人！";
		} else	{
			int intCount = Integer.valueOf(fileCount);
			Vector<Vector> files = new Vector<Vector>();
			for(int i=0;i<intCount;i++){
				com.jspsmart.upload.File myContentFile = mySmartUpload.getFiles().getFile(i);
				String srcFileName = myContentFile.getFileName();
				int fileSize = myContentFile.getSize();
			
				String filePath = MsgAttachment.OA_MESSAGE_ATTACHMENT_SAVE_PATH + "/"+staffId + "_" + Long.toString(System.currentTimeMillis())+".dat";
				if(!myContentFile.isMissing()){
					myContentFile.saveAs(filePath,SmartUpload.SAVE_PHYSICAL);
					Vector<String> temp = new Vector<String>();
					temp.add(srcFileName);
					temp.add(filePath);
					temp.add(Integer.toString(fileSize));
					files.add(temp);
				}
			}
			
			Message msg = new Message();
			msg.setValue("MsgType",Message.OA_MESSAGE_TYPE_SENDER);
			msg.setValue("Sender",staffId);
			msg.setValue("Receiver","");
			msg.setValue("Receivers",receivers);
			msg.setValue("Level",level);
			msg.setValue("Subject",subject);
			msg.setValue("Content",content);
			msg.setValue("ReqReply",reqReply);
			msg.setValue("Reply",Message.OA_MESSAGE_NO_REPLY);
			msg.setValue("ReadFlag",Message.OA_MESSAGE_NO_READ);
			msg.setValue("SendTime",DateUtil.getFullDateTime());
			if(files.size()>0){
				msg.setValue("AttachFlag",Message.OA_MESSAGE_ATTACHMENT);
			}else{
				msg.setValue("AttachFlag",Message.OA_MESSAGE_NO_ATTACHMENT);
			}
			if(strEdit.equals("1")){
				msg.setValue("MsgStatus",Message.OA_MESSAGE_STATUS_SEND);
			}	else if(strEdit.equals("2")){
				msg.setValue("MsgStatus",Message.OA_MESSAGE_STATUS_WAIT_SEND);
			}else if(strEdit.equals("3")){
				msg.setValue("MsgStatus",Message.OA_MESSAGE_STATUS_EDIT);
			}
			String msgId = msg.addMsg();
			if(msgId != null){
				if(files.size()>0){
					MsgAttachment attach = new MsgAttachment();
					attach.setValue("MsgId",msgId);
					attach.setValue("UploadTime",DateUtil.getFullDateTime());
					for(int j=0;j<files.size();j++){
						Vector temp = files.get(j);
						attach.setValue("AttachName",(String)temp.get(0));
						attach.setValue("AttachPath",(String)temp.get(1));
						attach.setValue("AttachSize",(String)temp.get(2));
						attach.insert();
					}
				}
				if(!strEdit.equals("1"))
					strErrorInfo = "保存完成！";
			}
			else{
				strErrorInfo = "添加发件人信息失败！";
			}
			
			if(strEdit.equals("1")){
				Vector<String> errorReceivers = new Vector<String>();

				/*如果支持选部门发送，还需要在这里多一步处理，把部门转换为员工列表*/
				String rs[] = receivers.split("\\;");
				Hashtable<String,String> sends = new Hashtable<String,String>();
				for(int i=0;i<rs.length;i++){
					if(!rs[i].equals("") && !sends.containsKey(rs[i])){
						sends.put(rs[i], "");
						if(!rs[i].equals("")){//判断收件人有效性时，是否是合法系统用户，因为员工表还没有，此处暂时省略
							msg.setValue("MsgType", Message.OA_MESSAGE_TYPE_RECEIVER);
							msg.setValue("Receiver", rs[i]);
							msg.setValue("MsgStatus", Message.OA_MESSAGE_STATUS_SEND);
							String newId = msg.addMsg();
							if(newId != null){
								if(files.size()>0){
									MsgAttachment attach = new MsgAttachment();
									attach.setValue("MsgId",newId);
									attach.setValue("UploadTime",DateUtil.getFullDateTime());
									for(int j=0;j<files.size();j++){
										Vector temp = (Vector)files.get(j);
										attach.setValue("AttachName",(String)temp.get(0));
										attach.setValue("AttachPath",(String)temp.get(1));
										attach.setValue("AttachSize",(String)temp.get(2));
										attach.insert();
									}
								}
							}else{
								errorReceivers.add(rs[i]);
							}
						}else{
							errorReceivers.add(rs[i]);
						}
					}
				}
				if(errorReceivers.size()>0){
					/*如果有发送失败的收件人，发送一个通知信息*/
					Message sys_msg = new Message();
					sys_msg.setValue("MsgType", Message.OA_MESSAGE_TYPE_RECEIVER);
					sys_msg.setValue("Sender","SYSTEM");
					sys_msg.setValue("Receiver", msg.getValue("Sender"));
					sys_msg.setValue("Receivers", msg.getValue("Sender"));
					sys_msg.setValue("Level", Message.OA_MESSAGE_LEVEL_HIGH);
					sys_msg.setValue("Subject", "ERROR:"+msg.getValue("Subject"));
					StringBuffer con = new StringBuffer(1024);
					con.append(msg.getValue("Sender"));
					con.append(",您好：\n");
					con.append("　　您发送的信息：");
					con.append(msg.getValue("Subject"));
					con.append("\n　　下列收件人没有送达：");
					for(int j=0;j<errorReceivers.size();j++){
						con.append(errorReceivers.get(j));
						con.append(";");
					}
					con.append("\n　　请检查收件人名称正确。\n\n         SYSTEM\n         　　");
					con.append(DateUtil.getFullDateTime());
					sys_msg.setValue("Content", con.toString());
					sys_msg.setValue("MsgStatus", Message.OA_MESSAGE_STATUS_SEND);
					sys_msg.setValue("ReqReply", Message.OA_MESSAGE_NO_REQUEST_REPLY);
					sys_msg.setValue("Reply", Message.OA_MESSAGE_NO_REPLY);
					sys_msg.setValue("ReadFlag", Message.OA_MESSAGE_NO_READ);
					sys_msg.setValue("AttachFlag", Message.OA_MESSAGE_NO_ATTACHMENT);
					sys_msg.setValue("SendTime", DateUtil.getFullDateTime());
					sys_msg.insert();
				}
				strErrorInfo = "发送完成！";
			}
		}
	}
%>
<html>

<head>
<TITLE>添加版本信息</TITLE>
	<meta http-equiv="Pragma" content="no-cache">
	<link rel="stylesheet" type="text/css" href="../../css/jwdf_main.css">
	<link rel="stylesheet" type="text/css" href="../../css/jwdf_swin.css">
	<SCRIPT language="JavaScript" type="text/javascript" src="../../js/jwdf_util.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../../js/jwdf_xml.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../../js/jwdf_view.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../../js/jwdf_swin.js"></SCRIPT>
	<script language=javascript>
		function showStaff(){
			alert("组织结构完成后添加！");
		}
		
		function doSend(){
			NewForm.action = "sendmsg.jsp?edit=1";
			NewForm.submit();
		}

		function doSaveWait(){
			NewForm.action = "sendmsg.jsp?edit=2";
			NewForm.submit();
		}

		function doSaveEdit(){
			NewForm.action = "sendmsg.jsp?edit=3";
			NewForm.submit();
		}
	</script>
</head>

<body>
	<table width="100%" border="0" cellspacing="0" cellpadding="0" align="center">
		<tr>
			<td class="td_buttonbar" valign="middle" style="font-size:9pt;color:red;">
				<a href="#" onclick="doSend();"><img src="../../buttons/send_001.gif" width="48" height="18" border="0" align="top" vspace="1" /></a>&nbsp;&nbsp;
				<a href="#" onclick="doSaveWait();"><img src="../../buttons/save_001.gif" width="78" height="18" border="0" align="top" vspace="1" /></a>&nbsp;&nbsp;
				<a href="#" onclick="doSaveEdit();"><img src="../../buttons/save_002.gif" width="78" height="18" border="0" align="top" vspace="1" /></a>
			</td>
		</tr>
	</table>

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
				<form method="POST" action="newVersion.jsp?edit=1" name="NewForm" ENCTYPE="multipart/form-data">
					<tr>
						<td width="25%" class="td_detailcontent1" align="center">收件人：</td>
						<td width="75%" class="td_detailcontent0">
							<input style="width:200;" class="input_edit" type="text" name="Receivers" value="<%=receivers%>">
							<a href="#" onclick="showStaff();"><img src="../../buttons/select_001.gif" width="48" height="18" border="0" align="top" vspace="1" /></a>
						</td>
					</tr>
					<tr>
						<td width="25%" class="td_detailcontent1" align="center">标题：</td>
						<td width="75%" class="td_detailcontent0"><input class="input_edit" style="width:100%;" type="text" name="Subject" value="<%=subject%>"></input></td>
					</tr>
					<tr>
						<td width="25%" class="td_detailcontent1" align="center">内容：</td>
						<td width="75%" class="td_detailcontent0"><textarea class="content_textarea" style="height:50;" name="Content"><%=content%></textarea></td>
					</tr>
					<tr>
						<td width="25%" class="td_detailcontent1" align="center">重要级别：</td>
						<td width="75%" class="td_detailcontent0">
							<select name="Level">
								<option<%if(level.equals(Message.OA_MESSAGE_LEVEL_LOW)){%> selected<%}%> value="<%=Message.OA_MESSAGE_LEVEL_LOW%>">不重要</option>
								<option<%if(level.equals(Message.OA_MESSAGE_LEVEL_NORMAL)){%> selected<%}%> value="<%=Message.OA_MESSAGE_LEVEL_NORMAL%>">普通</option>
								<option<%if(level.equals(Message.OA_MESSAGE_LEVEL_HIGH)){%> selected<%}%> value="<%=Message.OA_MESSAGE_LEVEL_HIGH%>">重要</option>
								<option<%if(level.equals(Message.OA_MESSAGE_LEVEL_HIGHEST)){%> selected<%}%> value="<%=Message.OA_MESSAGE_LEVEL_HIGHEST%>">非常重要</option>
							</select>
						</td>
					</tr>
					<tr>
						<td width="25%" class="td_detailcontent1" align="center">要求回复：</td>
						<td width="75%" class="td_detailcontent0">
							<select name="ReqReply">
								<option<%if(reqReply.equals(Message.OA_MESSAGE_NO_REQUEST_REPLY)){%> selected<%}%> value="<%=Message.OA_MESSAGE_NO_REQUEST_REPLY%>">不要求</option>
								<option<%if(reqReply.equals(Message.OA_MESSAGE_REQUEST_REPLY)){%> selected<%}%> value="<%=Message.OA_MESSAGE_REQUEST_REPLY%>">要求</option>
							</select>
						</td>
					</tr>
					<tr>
						<td width="25%" class="td_detailcontent1" align="center">附件：</td>
						<td width="75%" class="td_detailcontent0">
							<input class="input_edit" type="file" name="UploadFile" value=""></input><br>
						</td>
					</tr>					
				</form>
				</table>
			</td>
		</tr>
	</table>
</body>

</html>