<%@ page contentType="text/html;charset=utf-8"%>  
<%@ page import="com.language.langdata.LangPage"%> 
<%@ page import="com.language.langdata.LangAction"%> 
<%@ page import="org.jwdf.framework.console.*"%>
<%@ page import="org.jwdf.util.*"%>
<%@ page import="com.vogins.sps.db.app.Dynamiclink"%>
<%@ page import="com.vogins.sps.init.SystemParas"%>
<%@ page import="com.vogins.sps.util.StringUtil"%>
<%@ page import="com.vogins.gzip.GzipUtils"%>
<%@ page import="com.jspsmart.upload.*"%>
<jsp:useBean id="mySmartUpload" scope="page" class="com.jspsmart.upload.SmartUpload" />
<%
	Dynamiclink fol=new Dynamiclink();
		
	String strEdit = request.getParameter("edit");
	if(strEdit == null) strEdit = "0";
	
	String fileName = "";
	String smid="";
	String smname="";
	String smversion="";
	String remark="";
	
	String strErrorInfo = "";
	if(strEdit.equals("1"))
	{
		mySmartUpload.initialize(pageContext);
		Request myRequest = mySmartUpload.getRequest();
		mySmartUpload.upload();

		smid   = 	myRequest.getParameter("SMId").replaceAll(" +", "");;
		smname = 	myRequest.getParameter("SMName").replaceAll(" +", "");;
		smversion = myRequest.getParameter("SMVersion");
		remark  =	myRequest.getParameter("Remark").replaceAll(" +", "");;
		
			com.jspsmart.upload.File myContentFile = mySmartUpload.getFiles().getFile(0);
			String ContentFileName = myContentFile.getFileName();
			
			String extName = StringUtil.getFileExtName(ContentFileName);
			String tempFile = Long.toString(System.currentTimeMillis()) + "." + extName;
			if(!myContentFile.isMissing())
			{
				 if(smid.replaceAll("[\u4e00-\u9fa5]*[a-z]*[A-Z]*\\d*-*_*\\s*", "").length()==0||smid.equals(""))
				   {
					 if(smname.replaceAll("[\u4e00-\u9fa5]*[a-z]*[A-Z]*\\d*-*_*\\s*", "").length()==0||smname.equals(""))
					 {
							myContentFile.saveAs(SystemParas.getDynamiclink()+ "/" + tempFile,SmartUpload.SAVE_PHYSICAL);
							GzipUtils.compress(SystemParas.getDynamiclink()+ "/" + tempFile);
							String sessionId = Console.session_manager.getSessionId(request);
							String strAddUser = Console.session_manager.get(sessionId).getUserName();

							Dynamiclink more = new Dynamiclink();
						
							more.setValue("SMId",smid);
							more.setValue("SMName",smname);
							more.setValue("SMVersion",smversion);
							more.setValue("FileName",ContentFileName);
							more.setValue("SavePath",SystemParas.getDynamiclink() + "/" + tempFile);
							more.setValue("CompressedPath",SystemParas.getDynamiclink() + "/" + tempFile+".gz");						
							more.setValue("Remark",remark);
							more.setValue("AddUser",strAddUser);
							more.setValue("AddTime",DateUtil.getFullDateTime());
							more.setValue("UpdateTime",DateUtil.getFullDateTime());
							more.setValue("UpdateUser",strAddUser);
							if(more.insert()){
								strErrorInfo = LangAction.langAction.getSuccess_insert();
							}else{
								strErrorInfo = LangAction.langAction.getFailed_insert();
							}
							}else{
								 strErrorInfo="输入字符不正确，请重新输入！";
							}
					}else{
						 strErrorInfo="输入编号格式不正确，请重新输入！";
						 }
 				 }
			}
%>
<html>

<head>
<TITLE>动态连接库</TITLE>
	<meta http-equiv="Pragma" content="no-cache">
	<SCRIPT language="JavaScript" type="text/javascript" src="../../js/jwdf_check.js"></SCRIPT>
	<link rel="stylesheet" type="text/css" href="../../css/jwdf_main.css">
	<script language=javascript>
  function check(){ 
	if(checksmid()){
		if(checksmname()){	  
			if (validateVersion()) {
				if(checkfile()){
					NewForm.submit();	
				}
			}
		  }
		}
	}

		
		function validateVersion() {
			version = NewForm.SMVersion.value ;
			rule = /^(\d+\.){2}(\d+)$/;
			if ( rule.test(version)) {
				return true ;
			} else {
				alert("版本格式不正确！（请按如下格式填写：3.0.0）");
				return false ;
			}
		}
		function checksmid() {
			smid = NewForm.SMId.value ;
			if (smid!="") {
				return true ;
			} else {
				alert("编号不能为空！");
				return false ;
			}
		}
		function checksmname() {
			smname = NewForm.SMName.value ;
			if (smname!="") {
				return true ;
			} else {
				alert("名称不能为空！");
				return false ;
			}
		}
		function checkfile() {
			file=NewForm.UploadFile.value;
			if (file!="") {
				return true ;
			} else {
				alert("没有上传文件！");
				return false ;
			}
		}
		</script>
</head>

<body scroll="no">
	<table id="tb_new" class="table_edit" cellpadding="0" cellspacing="0" align="center">
		<tr>
			<td>
				<table class="table_detaillist" cellpadding="0" cellspacing="1" align="center">
				<form method="POST" action="newDlink.jsp?edit=1" name="NewForm" ENCTYPE="multipart/form-data">
					<tr>
						<td  height="15" align="right" bgcolor="#8acef5" style="font-size:9pt;color:red;"></td>
						<td  height="15" align="right" bgcolor="#8acef5" style="font-size:9pt;color:red;"><%=strErrorInfo%></td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=fol.getAliasByFiled("SMId")%>：</td>
						<td class="td_detailcontent0">
							<input class="input_edit" style="width:100%;" type="text" name="SMId" maxlength="24" value="<%=smid%>">
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=fol.getAliasByFiled("SMName")%>：</td>
						<td class="td_detailcontent0">
							<input class="input_edit" style="width:100%;" type="text" name="SMName" maxlength="24" value="<%=smname%>">
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=fol.getAliasByFiled("SMVersion")%>：</td>
						<td class="td_detailcontent0">
							<input class="input_edit" style="width:100%;" type="text" name="SMVersion" maxlength="24" value="<%=smversion%>">
						</td>
					</tr>

					<tr>
						<td class="td_detailcontent1" align="center"><%=fol.getAliasByFiled("SavePath")%>：</td>
						<td class="td_detailcontent0">
							<input class="input_edit" type="file" name="UploadFile" value="" style="width:300;" UNSELECTABLE="on"></input>
						</td>
					</tr>
					<tr>
						<td class="td_detailcontent1" align="center"><%=fol.getAliasByFiled("Remark") %>：</td>
						<td class="td_detailcontent0"><textarea name="Remark" class="input_textarea"><%=remark%></textarea></td>
					</tr>		
					<tr>
						<td colspan="2" align="center" valign="middle" class="td_editbutton">
							<a href="#" onclick="check();"><img src="../../<%=LangPage.langPage.getButton_img_path()%>submit_001.gif"   border="0" align="top" vspace="1" /></a>
						</td>
					</tr>
				</form>
				</table>
			</td>
		</tr>
	</table>

</body>

</html>