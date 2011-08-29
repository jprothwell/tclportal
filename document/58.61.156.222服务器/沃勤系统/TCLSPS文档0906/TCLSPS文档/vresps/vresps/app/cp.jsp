<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangAction"%>
<%@ page import="com.language.langdata.LangDBTable"%>
<%@ page import="com.vogins.sps.db.app.CPPartner"%>
<%@ page import="com.vogins.sps.db.publicinfo.Contact"%>
<%
	CPPartner cp = new CPPartner();
	Contact contact = new Contact();
%>
<html>

<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<TITLE><%=LangPage.langPage.getPageTitle("cp")%></TITLE>
	<meta http-equiv="Pragma" content="no-cache">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_main.css">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_swin.css">
	<SCRIPT language="JavaScript" type="text/javascript" src="../js/jwdf_util.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_xml.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_view.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_swin.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>sps_workflow.js"></SCRIPT>
	<script language=javascript>
		var cur_flowid = "";
<!--------------------添加内容提供商---------------------->
		var newwindow = new SimpleWindow();
		function showNew(){
			newwindow.Create('new_window','<%=LangPage.langPage.getWindowsTitle("workflow_addcppartner")%>',350,295,newHTML);
			newwindow.Show();
		}
		function newCancel(){
			newwindow.Close();
		}
		function newSubmit(){
			if(NewPartner.CPCode.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=cp.getAliasByFiled("CPCode")%>");
				NewPartner.CPCode.focus();
				return false;
			}
			if(NewPartner.CPName.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=cp.getAliasByFiled("CPName")%>");
				NewPartner.CPName.focus();
				return false;
			}
			if(NewPartner.ShortName.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=cp.getAliasByFiled("ShortName")%>");
				NewPartner.ShortName.focus();
				return false;
			}
			sendP("../AddCP.do",getP(NewPartner),newResult);
		}
		function newResult(cartXML){
			var cart = cartXML.getElementsByTagName("result")[0];
			var flowId = cart.getElementsByTagName("info")[0].firstChild.nodeValue;
			cur_flowid = flowId;

			newwindow.Close();
			openWFNodeSet();
		}
<!------------------------------------------------------------->

<!----------------修改内容提供商------------------------>
		var updatewindow = new SimpleWindow();
		function showUpdate(){
			if(listCurrentKey.get('cplist')==""){
				alert("<%=LangAction.langAction.getNoselect_cp()%>");
				return;
			}else{
				updatewindow.Create('update_window','<%=LangPage.langPage.getWindowsTitle("cp_updatecp")%>',350,295,updateHTML);
				updatewindow.Show();
				sendG("../GetCPInfo.do?CPId="+listCurrentKey.get('cplist'),getUpdate);
			}
		}
		function updateCancel(){
			updatewindow.Close();
		}
		function getUpdate(cartXML){
			var cart = cartXML.getElementsByTagName("result")[0];
			var code = cart.getElementsByTagName("code")[0].firstChild.nodeValue;
			var detail = cart.getElementsByTagName("detail")[0];
			var fields = detail.getElementsByTagName("field");
			for(i=0;i<fields.length;i++){
				var name = fields[i].getElementsByTagName("name")[0].firstChild.nodeValue;
				var value = "";
				if(fields[i].getElementsByTagName("value")[0].firstChild != null){
					value = fields[i].getElementsByTagName("value")[0].firstChild.nodeValue;
				}
				if(name == "<%=cp.getAliasByFiled("CPId")%>") UpdatePartner.CPId.value = value;
				if(name == "<%=cp.getAliasByFiled("CPCode")%>") UpdatePartner.CPCode.value = value;
				if(name == "<%=cp.getAliasByFiled("CPType")%>") UpdatePartner.CPType.value = value;
				else if(name == "<%=cp.getAliasByFiled("CPName")%>") UpdatePartner.CPName.value = value;
				else if(name == "<%=cp.getAliasByFiled("ShortName")%>") UpdatePartner.ShortName.value = value;
				else if(name == "<%=cp.getAliasByFiled("Address")%>") UpdatePartner.Address.value = value;
				else if(name == "<%=cp.getAliasByFiled("Phone")%>") UpdatePartner.Phone.value = value;
				else if(name == "<%=cp.getAliasByFiled("Fax")%>") UpdatePartner.Fax.value = value;
				else if(name == "<%=cp.getAliasByFiled("HomePage")%>") UpdatePartner.HomePage.value = value;
				else if(name == "<%=cp.getAliasByFiled("BillType")%>") UpdatePartner.BillType.value = value;
				else if(name == "<%=cp.getAliasByFiled("SystemUser")%>") UpdatePartner.SystemUser.value = value;
			}
		}
		function updateResult(cartXML){
			var cart = cartXML.getElementsByTagName("result")[0];
			var flowId = cart.getElementsByTagName("info")[0].firstChild.nodeValue;
			cur_flowid = flowId;

			updatewindow.Close();
			openWFNodeSet();
		}
		function updateSubmit(){
			if(UpdatePartner.CPCode.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=cp.getAliasByFiled("CPCode")%>");
				UpdatePartner.CPCode.focus();
				return false;
			}
			if(UpdatePartner.CPName.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=cp.getAliasByFiled("CPName")%>");
				UpdatePartner.CPName.focus();
				return false;
			}
			if(UpdatePartner.ShortName.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=cp.getAliasByFiled("ShortName")%>");
				UpdatePartner.ShortName.focus();
				return false;
			}
			sendP("../UpdateCP.do",getP(UpdatePartner),updateResult);
		}
<!------------------------------------------------------------->
		
<!-------------------删除内容提供商---------------------->
		function deleteObj(){
			if(listCurrentKey.get('cplist')==""){
				alert("<%=LangAction.langAction.getNoselect_cp()%>");
				return;
			}else{
				if(confirm("<%=LangPage.langPage.getDelete_confirm()%>")){
					sendG("../DeleteCP.do?CPId="+listCurrentKey.get('cplist'),deleteResult);
				}
			}
		}
		function deleteResult(cartXML){
			var cart = cartXML.getElementsByTagName("result")[0];
			var flowId = cart.getElementsByTagName("info")[0].firstChild.nodeValue;
			cur_flowid = flowId;

			openWFNodeSet();
		}
<!------------------------------------------------------------->

<!---------------控制显示或关闭联系人管理------------------------------>
		var viewwindow = new SimpleWindow();
		function ShowContact(){
			if(listCurrentKey.get('cplist')==""){
				alert("<%=LangAction.langAction.getNoselect_cp()%>");
				return;
			}else{
				viewwindow.Create('contact_window','<%=LangPage.langPage.getWindowsTitle("contact")%>',500,350,contactHTML);
				viewwindow.Show();
				cur_partnerid = listCurrentKey.get('cplist');
				sendG("../GetCPInfo.do?CPId="+listCurrentKey.get('cplist'),getMFDetail1);
			}
		}		
		function getMFDetail1(cartXML){
			var cart = cartXML.getElementsByTagName("result")[0];
			var code = cart.getElementsByTagName("code")[0].firstChild.nodeValue;
			var detail = cart.getElementsByTagName("detail")[0];
			var fields = detail.getElementsByTagName("field");
			for(i=0;i<fields.length;i++){
				var name = fields[i].getElementsByTagName("name")[0].firstChild.nodeValue;
				var value = "";
				if(fields[i].getElementsByTagName("value")[0].firstChild != null){
					value = fields[i].getElementsByTagName("value")[0].firstChild.nodeValue;
				}
				if(name == "<%=cp.getAliasByFiled("CPCode")%>") document.all["td_CPCode"].innerHTML = value;
				else if(name == "<%=cp.getAliasByFiled("CPName")%>") document.all["td_CPName"].innerHTML = value;
			}
			listPageURL.put('contactlist','../GetContactList.do?PartnerType=3&PartnerId='+listCurrentKey.get('cplist')+'&index=#index#');
			openPage('contactlist','1');
		}
<!------------------------------------------------------------->

<!---------------添加联系人------------------------->
		var newwindow = new SimpleWindow();
		var cur_partnerid="";
		function showNew1(){
			if(cur_partnerid==""){
				alert("<%=LangAction.langAction.getNoselect_cp()%>");
				return;
			}else{
				newwindow.Create('new_window','<%=LangPage.langPage.getWindowsTitle("contact_new")%>',280,177,ConnewHTML);
				newwindow.Show();
			}
		}
		function newCancel1(){
			newwindow.Close();
		}
		function newSubmit1(){
			if(NewContact.Name.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=contact.getAliasByFiled("Name")%>");
				NewContact.Name.focus();
				return false;
			}
			NewContact.PartnerId.value = cur_partnerid;
			sendP("../AddContact.do",getP(NewContact),newResult1);
		}
		function newResult1(){
			newwindow.Close();
			openPage('contactlist',listIndex.get('contactlist'));
		}
<!------------------------------------------------------------->

<!-------------------修改联系人-------------------------->
		var updatewindow = new SimpleWindow();
		function showUpdate1(){
			if(listCurrentKey.get('contactlist')==""){
				alert("<%=LangAction.langAction.getNoselect_contact()%>");
				return;
			}else{
				updatewindow.Create('update_window','<%=LangPage.langPage.getWindowsTitle("contact_update")%>',280,177,ConUpdateHTML);
				updatewindow.Show();
				sendG("../GetContactInfo.do?ContactId="+listCurrentKey.get('contactlist'),getUpdate1);
			}
		}
		function updateCancel1(){
			updatewindow.Close();
		}
		function getUpdate1(cartXML){
			var cart = cartXML.getElementsByTagName("result")[0];
			var code = cart.getElementsByTagName("code")[0].firstChild.nodeValue;
			var detail = cart.getElementsByTagName("detail")[0];
			var fields = detail.getElementsByTagName("field");
			for(i=0;i<fields.length;i++){
				var name = fields[i].getElementsByTagName("name")[0].firstChild.nodeValue;
				var value = "";
				if(fields[i].getElementsByTagName("value")[0].firstChild != null){
					 value = fields[i].getElementsByTagName("value")[0].firstChild.nodeValue;
				}
				if(name == "<%=contact.getAliasByFiled("ContactId")%>") UpdateContact.ContactId.value = value;
				else if(name == "<%=contact.getAliasByFiled("Name")%>") UpdateContact.Name.value = value;
				else if(name == "<%=contact.getAliasByFiled("Sex")%>") UpdateContact.Sex.value = value;
				else if(name == "<%=contact.getAliasByFiled("Mobile")%>") UpdateContact.Mobile.value = value;
				else if(name == "<%=contact.getAliasByFiled("Phone")%>") UpdateContact.Phone.value = value;
				else if(name == "<%=contact.getAliasByFiled("EMail")%>") UpdateContact.EMail.value = value;
				else if(name == "<%=contact.getAliasByFiled("Title")%>") UpdateContact.Title.value = value;
			}
		}
		function updateSubmit1(){
			if(UpdateContact.Name.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=contact.getAliasByFiled("Name")%>");
				UpdateContact.Name.focus();
				return false;
			}
			sendP("../UpdateContact.do",getP(UpdateContact),updateResult1);
		}
		function updateResult1(){
			updatewindow.Close();
			openPage('contactlist',listIndex.get('contactlist'));
		}
<!------------------------------------------------------------->

<!---------------删除联系人------------------------>
		function deleteObj1(){
			if(listCurrentKey.get('contactlist')==""){
				alert("<%=LangAction.langAction.getNoselect_contact()%>");
				return;
			}else{
				if(confirm("<%=LangPage.langPage.getDelete_confirm()%>")){
					sendG("../DeleteContact.do?ContactId="+listCurrentKey.get('contactlist'),deleteResult1);
				}
			}
		}
		function deleteResult1(){
			openPage('contactlist',listIndex.get('contactlist'));
		}
<!------------------------------------------------------------->

<!------------------页面初始化---------------------->
		var newHTML = "";
		var updateHTML = "";

		var ConnewHTML ="";
		var ConUpdateHTML = "";
		var contactHTML ="";

		function init(){
			newHTML = document.all["tb_new"].innerHTML;
			document.all["tb_new"].innerHTML = "";
			updateHTML = document.all["tb_update"].innerHTML;
			document.all["tb_update"].innerHTML = "";

            ConnewHTML = document.all["tb_contactnew"].innerHTML;
			document.all["tb_contactnew"].innerHTML = "";
            ConUpdateHTML = document.all["tb_contactupdate"].innerHTML;
			document.all["tb_contactupdate"].innerHTML = "";
		    contactHTML = document.all["contact_window"].innerHTML;
			document.all["contact_window"].innerHTML = "";

			initList();
			openPage('cplist','1');
		}

		function initList(){
			listIndex.put('cplist','1');
			listPageURL.put('cplist','../GetCPList.do?index=#index#');
			listDetailURL.put('cplist','../GetCPInfo.do?CPId=#id#');
			listCurrentId.put('cplist','');
			listCurrentKey.put('cplist','');
			listDetailWidth.put('cplist','300');
			listDetailHeight.put('cplist','320');
			listListXSL.put('cplist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('cplist','../xsl/jwdf_sdetail.xsl');

		    listIndex.put('contactlist','1');
			listPageURL.put('contactlist','../GetContactList.do?index=#index#');
			listDetailURL.put('contactlist','../GetContactInfo.do?ContactId=#id#');
			listCurrentId.put('contactlist','');
			listCurrentKey.put('contactlist','');
			listDetailWidth.put('contactlist','300');
			listDetailHeight.put('contactlist','250');
			listListXSL.put('contactlist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('contactlist','../xsl/jwdf_sdetail.xsl');
		}
		
<!------------------------------------------------------------->
	</script>
</head>

<body onload="init();">
	<!-- 页面标题 -->
	<table class="table_pagetitle" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("cp")%></td>
	</tr>
	</table>
	
	<!-- 操作按钮 -->
	<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_buttonbar" valign="middle">
			<a href="#" onclick="showNew();"><img src="../<%=LangPage.langPage.getButton_img_path()%>add_001.gif" border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a href="#" onclick="showUpdate();"><img src="../<%=LangPage.langPage.getButton_img_path()%>update_001.gif" border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a href="#" onclick="deleteObj();"><img src="../<%=LangPage.langPage.getButton_img_path()%>delete_001.gif" border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a href="#" onclick="ShowContact();"><img src="../<%=LangPage.langPage.getButton_img_path()%>contact_002.gif" border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
		</td>
	</tr>
	</table>

	<!-- 内容提供商列表显示区域 -->
	<div align="center" id="cplist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
	</div>

	<!-- 添加内容提供商表单 -->
	<div id="tb_new" class="datainfo">
		<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
		<form method="POST" name="NewPartner" class="editform">
		<tr>
			<td class="td_edittitle" width="25%"><%=cp.getAliasByFiled("CPCode")%></td>
			<td class="td_editcontent" width="75%"><input class="input_edit" style="width:100%;" maxlength="20" type="text" name="CPCode"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=cp.getAliasByFiled("CPType")%></td>
			<td class="td_editcontent">
				<select name="CPType">
					<option value="1"><%=LangPage.langPage.getSelect("cp_company")%></option>
					<option value="2"><%=LangPage.langPage.getSelect("cp_persion")%></option>
				</select>
			</td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=cp.getAliasByFiled("CPName")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" maxlength="100" type="text" name="CPName"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=cp.getAliasByFiled("ShortName")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" maxlength="20" type="text" name="ShortName"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=cp.getAliasByFiled("Address")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" maxlength="200" type="text" name="Address"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=cp.getAliasByFiled("Phone")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" maxlength="200" type="text" name="Phone"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=cp.getAliasByFiled("Fax")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" maxlength="200" type="text" name="Fax"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=cp.getAliasByFiled("HomePage")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" maxlength="200" type="text" name="HomePage"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=cp.getAliasByFiled("BillType")%></td>
			<td class="td_editcontent">
				<select name="BillType">
					<option value="1"><%=LangPage.langPage.getSelect("cp_gudingbili")%></option>
					<option value="2"><%=LangPage.langPage.getSelect("cp_fenduanbili")%></option>
				</select>
			</td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=cp.getAliasByFiled("SystemUser")%></td>
			<td class="td_editcontent"><textarea class="input_textarea" name="SystemUser"></textarea></td>
		</tr>
		</form>
		<tr>
			<td class="td_editbutton" colspan="2">
				<a href="#" onclick="newSubmit();"><img src="../<%=LangPage.langPage.getButton_img_path()%>next_001.gif" border="0" align="top" vspace="1" /></a>&nbsp;&nbsp;
				<a href="#" onclick="newCancel();"><img src="../<%=LangPage.langPage.getButton_img_path()%>cancel_001.gif" border="0" align="top" vspace="1" /></a>
			</td>
		</tr>
		</table>
	</div>

	<!-- 修改内容提供商表单 -->
	<div id="tb_update" class="datainfo">
		<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
		<form method="POST" name="UpdatePartner" class="editform">
			<input type="hidden" name="CPId" value="">
		<tr>
			<td class="td_edittitle" width="25%"><%=cp.getAliasByFiled("CPCode")%></td>
			<td class="td_editcontent" width="75%"><input class="input_edit" style="width:100%;" maxlength="20" type="text" name="CPCode"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=cp.getAliasByFiled("CPType")%></td>
			<td class="td_editcontent">
				<select name="CPType">
				<option value="1"><%=LangPage.langPage.getSelect("cp_company")%></option>
					<option value="2"><%=LangPage.langPage.getSelect("cp_persion")%></option>
				</select>
			</td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=cp.getAliasByFiled("CPName")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" maxlength="100" type="text" name="CPName"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=cp.getAliasByFiled("ShortName")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" maxlength="20" type="text" name="ShortName"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=cp.getAliasByFiled("Address")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" maxlength="200" type="text" name="Address"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=cp.getAliasByFiled("Phone")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" maxlength="200" type="text" name="Phone"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=cp.getAliasByFiled("Fax")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" maxlength="200" type="text" name="Fax"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=cp.getAliasByFiled("HomePage")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" maxlength="200" type="text" name="HomePage"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=cp.getAliasByFiled("BillType")%></td>
			<td class="td_editcontent">
				<select name="BillType">
					<option value="1"><%=LangPage.langPage.getSelect("cp_gudingbili")%></option>
					<option value="2"><%=LangPage.langPage.getSelect("cp_fenduanbili")%></option>
				</select>
			</td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=cp.getAliasByFiled("SystemUser")%></td>
			<td class="td_editcontent"><textarea class="input_textarea" name="SystemUser"></textarea></td>
		</tr>
		</form>
		<tr>
			<td class="td_editbutton" colspan="2">
				<a href="#" onclick="updateSubmit();"><img src="../<%=LangPage.langPage.getButton_img_path()%>next_001.gif" border="0" align="top" vspace="1" /></a>&nbsp;&nbsp;
				<a href="#" onclick="updateCancel();"><img src="../<%=LangPage.langPage.getButton_img_path()%>cancel_001.gif" border="0" align="top" vspace="1" /></a>
			</td>
		</tr>
		</table>
	</div>

	<div id="tb_app" class="datainfo">
		<div align="center" id="applist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		</div>
	</div>
	
	<!-- 联系人管理窗口 -->
	<div align="center" id="contact_window" class="datainfo"><!-- 当前厂商信息信息 -->
		<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
			<tr>
				<td class="td_edittitle" width="80"><%=cp.getAliasByFiled("CPCode")%></td>
				<td class="td_editcontent" width="200" id="td_CPCode"></td>
				<td class="td_edittitle" width="80"><%=cp.getAliasByFiled("CPName")%></td>
				<td class="td_editcontent" width="200" id="td_CPName"></td>
			</tr>
		</table>

		<!-- 操作按钮 -->
		<table width="90%" border="0" cellspacing="0" cellpadding="0"
			align="center">
			<tr>
				<td class="td_buttonbar" valign="middle">
					<a href="#" onclick="showNew1();"><img src="../<%=LangPage.langPage.getButton_img_path()%>add_001.gif" border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
					<a href="#" onclick="showUpdate1();"><img src="../<%=LangPage.langPage.getButton_img_path()%>update_001.gif" border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
					<a href="#" onclick="deleteObj1();"><img src="../<%=LangPage.langPage.getButton_img_path()%>delete_001.gif" border="0" align="top" vspace="1"/></a>
				</td>
			</tr>
		</table>

		<!-- 联系人列表显示区域 -->
		<div id="contactlist"
			style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		</div>
	</div>	
	
	<!-- 添加联系人表单 -->
	<div align="center" id="tb_contactnew" class="datainfo">
		<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
		<form method="POST" name="NewContact" class="editform">
			<input type="hidden" name="PartnerId" value="">
			<input type="hidden" name="PartnerType" value="3">
		<tr>
			<td class="td_edittitle" width="25%"><%=contact.getAliasByFiled("Name")%></td>
			<td class="td_editcontent" width="75%"><input class="input_edit" maxlength="20" style="width:100%;" type="text" name="Name"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=contact.getAliasByFiled("Sex")%></td>
			<td class="td_editcontent">
				<select name="Sex">
					<option value="<%=LangPage.langPage.getSelect("sex_man")%>"><%=LangPage.langPage.getSelect("sex_man")%></option>
					<option value="<%=LangPage.langPage.getSelect("sex_women")%>"><%=LangPage.langPage.getSelect("sex_women")%></option>
				</select>
			</td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=contact.getAliasByFiled("Mobile")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;"maxlength="100" type="text" name="Mobile"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=contact.getAliasByFiled("Phone")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" maxlength="100" type="text" name="Phone"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=contact.getAliasByFiled("EMail")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;"maxlength="200" type="text" name="EMail"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=contact.getAliasByFiled("Title")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" maxlength="20" type="text" name="Title"></td>
		</tr>
		</form>
		<tr>
			<td class="td_editbutton" colspan="2">
				<a href="#" onclick="newSubmit1();"><img src="../<%=LangPage.langPage.getButton_img_path()%>ok_001.gif" border="0" align="top" vspace="1" /></a>&nbsp;&nbsp;
				<a href="#" onclick="newCancel1();"><img src="../<%=LangPage.langPage.getButton_img_path()%>cancel_001.gif" border="0" align="top" vspace="1" /></a>
			</td>
		</tr>
		</table>
	</div>

	<!-- 修改联系人表单 -->
	<div align="center" id="tb_contactupdate" class="datainfo">
		<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
		<form method="POST" name="UpdateContact" class="editform">
			<input type="hidden" name="ContactId" value="">
			<input type="hidden" name="PartnerId" value="">
			<input type="hidden" name="PartnerType" value="3">
		<tr>
			<td class="td_edittitle" width="25%"><%=contact.getAliasByFiled("Name")%></td>
			<td class="td_editcontent" width="75%"><input class="input_edit" maxlength="20" style="width:100%;" type="text" name="Name"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=contact.getAliasByFiled("Sex")%></td>
			<td class="td_editcontent">
				<select name="Sex">
					<option value="<%=LangPage.langPage.getSelect("sex_man")%>"><%=LangPage.langPage.getSelect("sex_man")%></option>
					<option value="<%=LangPage.langPage.getSelect("sex_women")%>"><%=LangPage.langPage.getSelect("sex_women")%></option>
				</select>
			</td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=contact.getAliasByFiled("Mobile")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" maxlength="100" type="text" name="Mobile"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=contact.getAliasByFiled("Phone")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" maxlength="100" type="text" name="Phone"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=contact.getAliasByFiled("EMail")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" maxlength="200" type="text" name="EMail"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=contact.getAliasByFiled("Title")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" maxlength="20" type="text" name="Title"></td>
		</tr>
		</form>
		<tr>
			<td class="td_editbutton" colspan="2">
				<a href="#" onclick="updateSubmit1();"><img src="../<%=LangPage.langPage.getButton_img_path()%>ok_001.gif" border="0" align="top" vspace="1" /></a>
				<a href="#" onclick="updateCancel1();"><img src="../<%=LangPage.langPage.getButton_img_path()%>cancel_001.gif" border="0" align="top" vspace="1" /></a>
			</td>
		</tr>
		</table>
	</div>

</body>

</html>
