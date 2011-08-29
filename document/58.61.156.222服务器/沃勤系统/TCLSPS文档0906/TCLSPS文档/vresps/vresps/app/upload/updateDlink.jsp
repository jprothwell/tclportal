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
<jsp:useBean id="mySmartUpload" scope="page"
	class="com.jspsmart.upload.SmartUpload" />
<%
	Dynamiclink fol=new Dynamiclink();
		
	String strEdit = request.getParameter("edit");
	String recId = request.getParameter("RecId");
	
	String smid="";
	String smname="";
	String smversion="";
	String fileName = "";
	String remark="";
	String strErrorInfo = "";
	
	if(strEdit == null) strEdit = "0";

	if(recId.equals(""))
	{
		strErrorInfo = LangAction.langAction.getNoselect_folder();
	}
	else if(strEdit.equals("1"))
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
		String extName		   = StringUtil.getFileExtName(ContentFileName);
		String tempFile 	   = Long.toString(System.currentTimeMillis()) + "." + extName;
		System.out.println("------------------"+myContentFile.isMissing());
		if(!myContentFile.isMissing())
		{
			 if(smid.replaceAll("[\u4e00-\u9fa5]*[a-z]*[A-Z]*\\d*-*_*\\s*", "").length()==0)
			   {				 
				 if(smname.replaceAll("[\u4e00-\u9fa5]*[a-z]*[A-Z]*\\d*-*_*\\s*","").length()==0)
				 {						
						String sessionId = Console.session_manager.getSessionId(request);
						String strAddUser = Console.session_manager.get(sessionId).getUserName();	
						
						myContentFile.saveAs(SystemParas.getDynamiclink()+ "/" + tempFile,SmartUpload.SAVE_PHYSICAL);
						GzipUtils.compress(SystemParas.getDynamiclink()+ "/" + tempFile);
						System.out.println("添加文件夹路径------------------"+SystemParas.getDynamiclink()+ "/" + tempFile);

					    Dynamiclink more = new Dynamiclink();						    
					    more.getInfo(recId);
						String filename = more.getValue("SavePath");
						System.out.println("删除文件夹路径------------------"+filename);
						String file_gz_name = more.getValue("CompressedPath");
						System.out.println("删除文件夹压缩路径------------------"+file_gz_name);
						
					    if(more.getInfo(recId))
						  {
					    	more.setValue("SMId",smid);
							more.setValue("SMName",smname);
							more.setValue("SMVersion",smversion);
							more.setValue("FileName",ContentFileName);
							more.setValue("SavePath",SystemParas.getDynamiclink() + "/" + tempFile);
							more.setValue("CompressedPath",SystemParas.getDynamiclink() + "/" + tempFile+".gz");						
							more.setValue("Remark",remark);
						//	more.setValue("AddUser",strAddUser);
						//	more.setValue("AddTime",DateUtil.getFullDateTime());
							more.setValue("UpdateTime",DateUtil.getFullDateTime());
							more.setValue("UpdateUser",strAddUser);
							if(more.update()){
								more.deleteFile(filename);
								more.deleteFile(file_gz_name);
								strErrorInfo = LangAction.langAction.getSuccess_update();
							}else{
								strErrorInfo = LangAction.langAction.getFailed_update();
							}	
						  }
					    else{
							strErrorInfo = LangAction.langAction.getRecord_not_exist();
						}
				 }
				 else
				 {
					 strErrorInfo="名称输入格式不正确，请重新输入！"; 
				 }
			   }
			 else
			 {
				 strErrorInfo="编号输入字符不正确，请重新输入！";
			 } 
		}
		else
		{
			//strErrorInfo = LangAction.langAction.getNoselect_uploadfile(); 	
			Dynamiclink more = new Dynamiclink();
			if(more.getInfo(recId))						
				{		
						String sessionId = Console.session_manager.getSessionId(request);
						String strAddUser = Console.session_manager.get(sessionId).getUserName();	
						more.setValue("SMId",smid);
						more.setValue("SMName",smname);
						more.setValue("SMVersion",smversion);				
						more.setValue("Remark",remark);
						more.setValue("UpdateTime",DateUtil.getFullDateTime());
						more.setValue("UpdateUser",strAddUser);
					
					 if(smid.replaceAll("[\u4e00-\u9fa5]*[a-z]*[A-Z]*\\d*-*_*\\s*", "").length()==0)
					   {
						 if(smname.replaceAll("[\u4e00-\u9fa5]*[a-z]*[A-Z]*\\d*-*_*\\s*", "").length()==0)
						 {
							if(more.update()){
								strErrorInfo = LangAction.langAction.getSuccess_update();
							}else{
								strErrorInfo = LangAction.langAction.getFailed_update();
							}	
						 }
						 else
						 {
							 strErrorInfo="编号输入字符不正确，请重新输入！";
						 }
					   }
					else
					   {
						 strErrorInfo="名称输入格式不正确，请重新输入！";
					   }
				}else{
					strErrorInfo = LangAction.langAction.getRecord_not_exist();
				}
		}
			
	}
	else
	{
		Dynamiclink mfolder = new Dynamiclink();
		 mfolder.getInfo(recId);
		smid	 = mfolder.getValue("SMId");
		smname	 = mfolder.getValue("SMName");
		smversion= mfolder.getValue("SMVersion");
		fileName = mfolder.getValue("FileName");
		remark	 = mfolder.getValue("Remark");
	}
	
	
%>
<html>
<head>
<TITLE><%=LangPage.langPage.getPageTitle("newMore")%></TITLE>
<meta http-equiv="Pragma" content="no-cache">
<SCRIPT language="JavaScript" type="text/javascript"
	src="../../js/jwdf_check.js"></SCRIPT>
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
<table id="tb_new" class="table_edit" cellpadding="0" cellspacing="0"
	align="center">
	<tr>
		<td>
		<table class="table_detaillist" cellpadding="0" cellspacing="1"
			align="center">
			<form method="POST" action="updateDlink.jsp?RecId=<%=recId%>&edit=1"
				name="NewForm" ENCTYPE="multipart/form-data">
			<tr>
				<td height="15" align="right" bgcolor="#8acef5"
					style="font-size: 9pt; color: red;"></td>
				<td height="15" align="right" bgcolor="#8acef5"
					style="font-size: 9pt; color: red;"><%=strErrorInfo%></td>
			</tr>
			<tr>
				<td class="td_detailcontent1" align="center"><%=fol.getAliasByFiled("SMId")%>：</td>
				<td class="td_detailcontent0"><input class="input_edit"
					style="width: 100%;" type="text" name="SMId" maxlength="24"
					value="<%=smid%>"></td>
			</tr>
			<tr>
				<td class="td_detailcontent1" align="center"><%=fol.getAliasByFiled("SMName")%>：</td>
				<td class="td_detailcontent0"><input class="input_edit"
					style="width: 100%;" type="text" name="SMName" maxlength="24"
					value="<%=smname%>"></td>
			</tr>
			<tr>
				<td class="td_detailcontent1" align="center"><%=fol.getAliasByFiled("SMVersion")%>：</td>
				<td class="td_detailcontent0"><input class="input_edit"
					style="width: 100%;" type="text" name="SMVersion" maxlength="24"
					value="<%=smversion%>"></td>
			</tr>

			<tr>
				<td class="td_detailcontent1" align="center"><%=fol.getAliasByFiled("SavePath")%>：</td>
				<td class="td_detailcontent0"><input class="input_edit"
					type="file" name="UploadFile" value="" style="width: 300;"
					UNSELECTABLE="on"></input>
				<%if(!fileName.equals("")){out.println("("+fileName+")");}%>
				</td>
			</tr>
			<tr>
				<td class="td_detailcontent1" align="center"><%=fol.getAliasByFiled("Remark") %>：</td>
				<td class="td_detailcontent0"><textarea name="Remark"
					class="input_textarea"><%=remark%></textarea></td>
			</tr>
			<tr>
				<td colspan="2" align="center" valign="middle" class="td_editbutton">
				<a href="#" onclick="check();"><img
					src="../../<%=LangPage.langPage.getButton_img_path()%>submit_001.gif"
					border="0" align="top" vspace="1" /></a></td>
			</tr>
			</form>
		</table>
		</td>
	</tr>
</table>

</body>

</html>