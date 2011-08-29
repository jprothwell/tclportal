<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangAction"%>
<%@ page import="com.language.langdata.LangDBTable"%>
<%@ page import="com.vogins.sps.db.as30.WebMessage"%>
<%
	WebMessage web = new WebMessage();
%>
<html>

<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<TITLE><%=LangPage.langPage.getPageTitle("webmessage")%></TITLE>
	<meta http-equiv="Pragma" content="no-cache">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_main.css">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_swin.css">
	<SCRIPT language="JavaScript" type="text/javascript" src="../js/jwdf_util.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_xml.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_view.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_swin.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>sps_workflow.js"></SCRIPT>
	<script language=javascript>
<!---------------添加------------------------->
		var newwindow = new SimpleWindow();
		function showNew(){
				newwindow.Create('new_window','<%=LangPage.langPage.getWindowsTitle("as_addwebmessage")%>',500,146,newHTML);
				newwindow.Show();
			}
	
		function newCancel(){
			newwindow.Close();
		}
		function newSubmit(){
			if(NewMsg.MsgSubject.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=web.getAliasByFiled("MsgSubject")%>");
				NewMsg.MsgSubject.focus();
				return false;
			}
			if(NewMsg.MsgContent.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=web.getAliasByFiled("MsgContent")%>");
				NewMsg.MsgContent.focus();
				return false;
			}
			if(NewMsg.MsgContent.value.length>"256"){
			     alert("<%=LangPage.langPage.getMessage_content()%>");
			     NewMsg.MsgContent.focus;
			     return false;
			}
			sendP("../AddWebMsg.do",getP(NewMsg),newResult);
		}
		function newResult(cartXML){
			var cart = cartXML.getElementsByTagName("result")[0];
			var flowId = cart.getElementsByTagName("info")[0].firstChild.nodeValue;
			cur_flowid = flowId;

			newwindow.Close();
			openWFNodeSet();
		}

<!---------------修改------------------------->
		var updatewindow = new SimpleWindow();
		function showUpdate(){
		    
			if(listCurrentKey.get('msglist')==""){
				alert("<%=LangAction.langAction.getNoselect_webmessage()%>");
				return;
			}else{
				updatewindow.Create('update_window','<%=LangPage.langPage.getWindowsTitle("as_updatewebMessage")%>',500,146,updateHTML);
				updatewindow.Show();
				sendG("../GetMsgInfo.do?MsgId="+listCurrentKey.get('msglist'),getUpdate);
			}
		}
		function updateCancel(){
			updatewindow.Close();
		}
		function getUpdate(cartXML){
			UpdateMsg.reset();
		
			var cart = cartXML.getElementsByTagName("result")[0];
			var code = cart.getElementsByTagName("code")[0].firstChild.nodeValue;
			var detail = cart.getElementsByTagName("detail")[0];
			var fields = detail.getElementsByTagName("field");
			var upothertable = document.getElementById("Upothertable");
			var upviewType = document.getElementById("UpviewTable");
			for(i=0;i<fields.length;i++){
				var name = fields[i].getElementsByTagName("name")[0].firstChild.nodeValue;
				var value = "";
				if(fields[i].getElementsByTagName("value")[0].firstChild != null){
					value = fields[i].getElementsByTagName("value")[0].firstChild.nodeValue;
				}
				if(name == "<%=web.getAliasByFiled("MsgId")%>") UpdateMsg.MsgId.value = value;
				else if(name == "<%=web.getAliasByFiled("MsgSubject")%>") UpdateMsg.MsgSubject.value = value;
				else if(name == "<%=web.getAliasByFiled("MsgContent")%>") UpdateMsg.MsgContent.value = value;
				else if(name =="<%=web.getAliasByFiled("LevelFlag")%>")UpdateMsg.LevelFlag.value = value;
				
			}
			
		}
		function updateSubmit(){
			if(UpdateMsg.MsgSubject.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=web.getAliasByFiled("MsgSubject")%>");
				UpdateMsg.MsgSubject.focus();
				return false;
			}
			if(UpdateMsg.MsgContent.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=web.getAliasByFiled("MsgContent")%>");
				UpdateMsg.MsgContent.focus();
				return false;
			}
			if(UpdateMsg.MsgContent.value.length>"256"){
			       alert("<%=LangPage.langPage.getMessage_content()%>");
			     
			     UpdateMsg.MsgContent.focus;
			     return false;
			}
			sendP("../UpdateWebMsg.do",getP(UpdateMsg),updateResult);
		}
		function updateResult(cartXML){
			var cart = cartXML.getElementsByTagName("result")[0];
			var flowId = cart.getElementsByTagName("info")[0].firstChild.nodeValue;
			cur_flowid = flowId;

			updatewindow.Close();
			openWFNodeSet();
		}
		
<!---------------删除消息------------------------>
		function deleteObj(){
			if(listCurrentKey.get('msglist')==""){
				alert("<%=LangAction.langAction.getNoselect_webmessage()%>");
				return;
			}else{
				if(confirm("<%=LangPage.langPage.getDelete_confirm()%>")){
					sendG("../DeleteWebMsg.do?MsgId="+listCurrentKey.get('msglist'),deleteResult);
				}
			}
		}
		function deleteResult(cartXML){
			var cart = cartXML.getElementsByTagName("result")[0];
			var flowId = cart.getElementsByTagName("info")[0].firstChild.nodeValue;
			cur_flowid = flowId;

			openWFNodeSet();
		}
<!------------------页面初始化---------------------->
		var newHTML = "";
		var updateHTML = "";
		
		function init(){
			newHTML = document.all["tb_new"].innerHTML;
			document.all["tb_new"].innerHTML = "";
			updateHTML = document.all["tb_update"].innerHTML;
			document.all["tb_update"].innerHTML = "";
			
			initList();
			openPage('msglist','1');
		}
		function initList(){
			listIndex.put('msglist','1');
			listPageURL.put('msglist','../GetAllMsg.do?index=#index#');
			listDetailURL.put('msglist','../GetMsgInfo.do?MsgId=#id#');
			listCurrentId.put('msglist','');
			listCurrentKey.put('msglist','');
			listDetailWidth.put('msglist','350');
			listDetailHeight.put('msglist','300');
			listListXSL.put('msglist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('msglist','../xsl/jwdf_sdetail.xsl');


		}
		
<!------------------------------------------------------------->
	</script>
</head>

<body onload="init();">
	<!-- 页面标题 -->
	<table class="table_pagetitle" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("webmessage")%></td>
	</tr>
	</table>
	
	<!-- 操作按钮 -->
	<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_buttonbar" valign="middle">
			<a href="#" onclick="showNew();"><img src="../<%=LangPage.langPage.getButton_img_path()%>add_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a href="#" onclick="showUpdate();"><img src="../<%=LangPage.langPage.getButton_img_path()%>update_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a href="#" onclick="deleteObj();"><img src="../<%=LangPage.langPage.getButton_img_path()%>delete_001.gif"   border="0" align="top" vspace="1"/></a>
		</td>
	</tr>
	</table>

	<!-- 消息列表显示区域 -->
	<div align="center" id="msglist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
	</div>

	<!-- 添加消息 -->
	<div id="tb_new" class="datainfo">
		<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
		<form method="POST" name="NewMsg" class="editform">
		<tr>
			<td class="td_edittitle" width="25%"><%=web.getAliasByFiled("MsgSubject")%></td>
			<td class="td_editcontent" width="75%"><input class="input_edit" style="width:100%;" type="text" name="MsgSubject" maxlength="32"></td>
		</tr>
		<tr>
			<td class="td_edittitle" width="100"><%=web.getAliasByFiled("MsgContent")%></td>
		<td class="td_editcontent">
			<textarea class="input_textarea" name="MsgContent"></textarea>
	    </td>
	    </tr>
	     <tr>
			<td class="td_edittitle"><%=web.getAliasByFiled("LevelFlag")%></td>
			<td class="td_editcontent" width="200"><select name="LevelFlag">
		    <option value="1"><%=LangPage.langPage.getSelect("web_tuijian")%></option>
		   <option value="0"><%=LangPage.langPage.getSelect("web_normal")%></option>
		   </select>
		</td>
		</tr>
		</form>
		<tr>
			<td class="td_editbutton" colspan="2">
				<a href="#" onclick="newSubmit();"><img src="../<%=LangPage.langPage.getButton_img_path()%>add_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
				<a href="#" onclick="newCancel();"><img src="../<%=LangPage.langPage.getButton_img_path()%>cancel_001.gif"   border="0" align="top" vspace="1" /></a>
			</td>
		</tr>
		</table>
	</div>

	<!-- 修改消息 -->
	<div id="tb_update" class="datainfo">
		<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
		<form method="POST" name="UpdateMsg" class="editform">
			<input type="hidden" name="MsgId" value="">
		<tr>
			<td class="td_edittitle" width="25%"><%=web.getAliasByFiled("MsgSubject")%></td>
			<td class="td_editcontent" width="75%"><input class="input_edit" style="width:100%;" type="text" name="MsgSubject" maxlength="32"></td>
		</tr>
		<tr>
			<td class="td_edittitle" width="100"><%=web.getAliasByFiled("MsgContent")%></td>
		<td class="td_editcontent" ><textarea
			class="input_textarea" name="MsgContent"></textarea>
	    </td>
		</tr>
	     <tr>
			<td class="td_edittitle"><%=web.getAliasByFiled("LevelFlag")%></td>
			<td class="td_editcontent" width="200"><select name="LevelFlag">
		    <option value="1"><%=LangPage.langPage.getSelect("web_tuijian")%></option>
		   <option value="0"><%=LangPage.langPage.getSelect("web_normal")%></option>
		   </select>
		</td>
		</tr>
		</form>
		<tr>
			<td class="td_editbutton" colspan="2">
				<a href="#" onclick="updateSubmit();"><img src="../<%=LangPage.langPage.getButton_img_path()%>update_001.gif"   border="0" align="top" vspace="1"/></a>
				<a href="#" onclick="updateCancel();"><img src="../<%=LangPage.langPage.getButton_img_path()%>cancel_001.gif"   border="0" align="top" vspace="1" /></a>
			</td>
		</tr>
		</table>
	</div>

</body>

</html>
