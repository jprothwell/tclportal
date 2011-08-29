<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangAction"%>
<%@ page import="com.language.langdata.LangDBTable"%>
<%@ page import="com.vogins.sps.db.fee.SPPartner"%>
<%@ page import="com.vogins.sps.db.publicinfo.Contact"%>
<%
	SPPartner sp = new SPPartner();
	Contact contact = new Contact();
%>
<html>

<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<TITLE><%=LangPage.langPage.getPageTitle("Sp")%></TITLE>
<meta http-equiv="Pragma" content="no-cache">
<link rel="stylesheet" type="text/css" href="../css/jwdf_main.css">
<link rel="stylesheet" type="text/css" href="../css/jwdf_swin.css">
<SCRIPT language="JavaScript" type="text/javascript" src="../js/jwdf_util.js"></SCRIPT>
<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_xml.js"></SCRIPT>
<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_view.js"></SCRIPT>
<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_swin.js"></SCRIPT>
<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>sps_workflow.js"></SCRIPT>
	
<script language=javascript>
<!--------------------添加收费渠道-------------------------->
	var newwindow = new SimpleWindow();
	var reg=/[\u4E00-\u9FA5]/g; //汉字判断
	var zimu =/[a-zA-Z]/ ;  //字母判断
	var shuzi =/^[0-9]*[1-9][0-9]*$/; //数字
	var cur_flowid = "";
	function showNew(){
		newwindow.Create('new_window','<%=LangPage.langPage.getWindowsTitle("fee_addsp")%>',300,265,newHTML);
		newwindow.Show();
	}
	function newCancel(){
		newwindow.Close();
	}
	function newSubmit(){
		if(NewPartner.SPName.value == ""){
			alert("<%=LangPage.langPage.getPlease_input()%><%=sp.getAliasByFiled("SPName")%>");
			NewPartner.SPName.focus();
			return false;
		}
		if(NewPartner.SPName.value.length>25){
		    alert("<%=LangPage.langPage.getSp_namelong()%>");
		    NewPartner.SPName.focus();
			return false;
		}
		if(NewPartner.ShortName.value.length>10){
			alert("<%=LangPage.langPage.getSp_shortnamelong()%>");
			NewPartner.ShortName.focus();
			return false;
		}
			
		sendP("../AddFee.do",getP(NewPartner),newResult);
	}
	function newResult(cartXML){
		var cart = cartXML.getElementsByTagName("result")[0];
		var flowId = cart.getElementsByTagName("info")[0].firstChild.nodeValue;
		cur_flowid = flowId;

		newwindow.Close();
		openWFNodeSet();
	}
<!------------------------------------------------------------->
<!------------------修改收费渠道------------------------->
	var updatewindow = new SimpleWindow();
	function showUpdate(){
		if(listCurrentKey.get('feelist')==""){
			alert("<%=LangAction.langAction.getNoselect_feechannel()%>");
			return false;
		}else{
			updatewindow.Create('update_window','<%=LangPage.langPage.getWindowsTitle("fee_updatesp")%>',300,265,updateHTML);
			updatewindow.Show();
			sendG("../GetFeeInfo.do?SPId="+listCurrentKey.get('feelist'),getUpdate);
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
			if(name == "<%=sp.getAliasByFiled("SPId")%>") UpdatePartner.SPId.value = value;
			else if(name == "<%=sp.getAliasByFiled("SPName")%>") UpdatePartner.SPName.value = value;
			else if(name == "<%=sp.getAliasByFiled("ShortName")%>") UpdatePartner.ShortName.value = value;
			else if(name == "<%=sp.getAliasByFiled("Address")%>") UpdatePartner.Address.value = value;
			else if(name == "<%=sp.getAliasByFiled("Phone")%>") UpdatePartner.Phone.value = value;
			else if(name == "<%=sp.getAliasByFiled("Fax")%>") UpdatePartner.Fax.value = value;
			else if(name == "<%=sp.getAliasByFiled("HomePage")%>") UpdatePartner.HomePage.value = value;
			else if(name == "<%=sp.getAliasByFiled("BillType")%>") UpdatePartner.BillType.value = value;
			else if(name == "<%=sp.getAliasByFiled("SystemUser")%>") UpdatePartner.SystemUser.value = value;
			else if(name == "<%=sp.getAliasByFiled("VoginsUser")%>") UpdatePartner.VoginsUser.value = value;
			else if(name == "<%=sp.getAliasByFiled("VoginsPass")%>") UpdatePartner.VoginsPass.value = value;
			else if(name == "<%=sp.getAliasByFiled("FeeURL")%>") UpdatePartner.FeeURL.value = value;
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
		if(UpdatePartner.SPName.value == ""){
			alert("<%=LangPage.langPage.getPlease_input()%><%=sp.getAliasByFiled("SPName")%>");
			UpdatePartner.SPName.focus();
			return false;
		}
		if(UpdatePartner.SPName.value.length>25){
		    alert("<%=LangPage.langPage.getSp_namelong()%>");
		    UpdatePartner.SPName.focus();
			return false;
		}
		if(UpdatePartner.ShortName.value.length>10){
			alert("<%=LangPage.langPage.getSp_shortnamelong()%>");
			UpdatePartner.ShortName.focus();
			return false;
		}
		sendP("../UpdateFee.do",getP(UpdatePartner),updateResult);
	}
<!------------------------------------------------------------->
		
<!--------------------删除收费渠道----------------------->
	function deleteObj(){
		if(listCurrentKey.get('feelist')==""){
			alert("<%=LangAction.langAction.getNoselect_sp()%>");
			return;
		}else{
			if(confirm("<%=LangPage.langPage.getDelete_confirm()%>")){
				sendG("../DeleteFee.do?SPId="+listCurrentKey.get('feelist'),deleteResult);
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
		
<!---------------添加联系人------------------------->
	var newwindow = new SimpleWindow();
	var cur_partnerid="";
	var cur_parttype="";
	function showNew1(){
		if(cur_partnerid==""){
			alert("<%=LangAction.langAction.getNoselect_sp()%>");
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
			return false;
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
			else if(name == "<%=contact.getAliasByFiled("PartnerId")%>") UpdateContact.PartnerId.value = value;
			else if(name == "<%=contact.getAliasByFiled("partnerType")%>") UpdateContact.PartnerId.value = value;
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
	var viewwindow = new SimpleWindow();
	function ShowContact(){
		if(listCurrentKey.get('feelist')==""){
			alert("<%=LangAction.langAction.getNoselect_sp()%>");
			return;
		}else{
			viewwindow.Create('contact_window','<%=LangPage.langPage.getWindowsTitle("sp_contact")%>',500,350,contactHTML);
			viewwindow.Show();
			cur_partnerid = listCurrentKey.get('feelist');
			sendG("../GetFeeInfo.do?SPId="+listCurrentKey.get('feelist'),getSPDetail1);
		}
	}		
	function getSPDetail1(cartXML){
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
			if(name == "<%=sp.getAliasByFiled("SPName")%>") document.all["td_MfName"].innerHTML = value;
			else if(name == "<%=sp.getAliasByFiled("BillType")%>") document.all["td_Bill"].innerHTML = value;
			else if(name == "<%=sp.getAliasByFiled("Phone")%>") document.all["td_Phone"].innerHTML = value;
			else if(name == "<%=sp.getAliasByFiled("AddTime")%>") document.all["td_CreateTime"].innerHTML = value;
		}
		listPageURL.put('contactlist','../GetContactList.do?PartnerType=2&&PartnerId='+listCurrentKey.get('feelist')+'&index=#index#');
		openPage('contactlist','1');
	}
<!------------------页面初始化---------------------->
	var newHTML = "";
	var updateHTML = "";
	var serviceHTML = "";
		
    var ConnewHTML ="";
	var ConUpdateHTML = "";
	var contactHTML ="";
		
    var conHTML ="";
		
	function init(){
		newHTML = document.all["tb_new"].innerHTML;
		document.all["tb_new"].innerHTML = "";
		updateHTML = document.all["tb_update"].innerHTML;
		document.all["tb_update"].innerHTML = "";
		ConnewHTML = document.all["tb_contactnew"].innerHTML;
		document.all["tb_contactnew"].innerHTML = "";
		ConUpdateHTML = document.all["tb_contactupdate"].innerHTML;
		document.all["tb_contactupdate"].innerHTML = "";
			
	    conHTML = document.all["tb_con"].innerHTML;
		document.all["tb_con"].innerHTML = "";
			
		contactHTML = document.all["contact_window"].innerHTML;
		document.all["contact_window"].innerHTML = "";
			
		initList();
		openPage('feelist','1');
	}

	function initList(){
		listIndex.put('feelist','1');
		listPageURL.put('feelist','../GetFeeList.do?index=#index#');
		listDetailURL.put('feelist','../GetFeeInfo.do?SPId=#id#');
		listCurrentId.put('feelist','');
		listCurrentKey.put('feelist','');
		listDetailWidth.put('feelist','300');
		listDetailHeight.put('feelist','320');
		listListXSL.put('feelist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
		listDetailXSL.put('feelist','../xsl/jwdf_sdetail.xsl');
  
		listIndex.put('countrylist','1');
		listPageURL.put('countrylist','../GetAllCountry.do?index=#index#');
		listDetailURL.put('countrylist','');
		listCurrentId.put('countrylist','');
		listCurrentKey.put('countrylist','');
		listDetailWidth.put('countrylist','300');
		listDetailHeight.put('countrylist','320');
		listListXSL.put('feelist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
		
		listIndex.put('contactlist','1');
		listPageURL.put('contactlist','../GetContactList.do？index=#index#');
		listDetailURL.put('contactlist','../GetContactInfo.do?ContactId=#id#');
		listCurrentId.put('contactlist','');
		listCurrentKey.put('contactlist','');
		listDetailWidth.put('contactlist','350');
		listDetailHeight.put('contactlist','320');
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
		<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("Sp")%></td>
	</tr>
</table>
<!-- 操作按钮 -->
<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td>
			<a href="#" onclick="showNew();"><img src="../<%=LangPage.langPage.getButton_img_path()%>add_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a href="#" onclick="showUpdate();"><img src="../<%=LangPage.langPage.getButton_img_path()%>update_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a href="#" onclick="deleteObj();"><img src="../<%=LangPage.langPage.getButton_img_path()%>delete_001.gif"  border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a href="#" onclick="ShowContact();"><img src="../<%=LangPage.langPage.getButton_img_path()%>contact_001.gif"  border="0" align="top" vspace="1"/></a>
		</td>
	</tr>
</table>

<!-- 收费渠道列表显示区域 -->
<div align="center" id="feelist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
</div>

<!-- 添加收费渠道的表单 -->
<div id="tb_new" class="datainfo">
<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
	<form method="POST" name="NewPartner" class="editform">
	<input type="hidden" name="CountryCode" value="CHN"> 
	<input type="hidden" name="BillType" value="0">
	<tr>
		<td class="td_edittitle" width="25%"><%=sp.getAliasByFiled("SPName")%></td>
		<td class="td_editcontent" width="75%">
			<input class="input_edit" style="width:100%;" type="text" name="SPName" >
		</td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=sp.getAliasByFiled("ShortName")%></td>
		<td class="td_editcontent">
			<input class="input_edit" style="width:100%;" type="text" name="ShortName" maxlength="20">
		</td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=sp.getAliasByFiled("Address")%></td>
		<td class="td_editcontent">
			<input class="input_edit" style="width:100%;" type="text" name="Address" maxlength="25">
		</td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=sp.getAliasByFiled("Phone")%></td>
		<td class="td_editcontent">
			<input class="input_edit" style="width:100%;" type="text" name="Phone" maxlength="15">
		</td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=sp.getAliasByFiled("Fax")%></td>
		<td class="td_editcontent">
			<input class="input_edit" style="width:100%;" type="text" name="Fax" maxlength="15">
		</td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=sp.getAliasByFiled("HomePage")%></td>
		<td class="td_editcontent">
			<input class="input_edit" style="width:100%;" type="text" name="HomePage">
		</td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=sp.getAliasByFiled("SystemUser")%></td>
		<td class="td_editcontent">
			<input class="input_edit" style="width:100%;" type="text" name="SystemUser">
		</td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=sp.getAliasByFiled("VoginsUser")%></td>
		<td class="td_editcontent">
			<input class="input_edit" style="width:100%;" type="text" name="VoginsUser">
		</td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=sp.getAliasByFiled("VoginsPass")%></td>
		<td class="td_editcontent">
			<input class="input_edit" style="width:100%;" type="text" name="VoginsPass">
		</td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=sp.getAliasByFiled("FeeURL")%></td>
		<td class="td_editcontent">
			<input class="input_edit" style="width:100%;" type="text" name="FeeURL">
		</td>
	</tr>
	</form>
	<tr>
		<td height="25" class="td_editbutton" colspan="2">
			<a href="#" onclick="newSubmit();"><img src="../<%=LangPage.langPage.getButton_img_path()%>next_001.gif"   border="0" align="top" vspace="1" /></a>&nbsp;&nbsp;
			<a href="#" onclick="newCancel();"><img src="../<%=LangPage.langPage.getButton_img_path()%>cancel_001.gif"   border="0" align="top" vspace="1" /></a>
		</td>
	</tr>
</table>
</div>

<!-- 修改收费渠道的表单 -->
<div id="tb_update" class="datainfo">
<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
	<form method="POST" name="UpdatePartner" class="editform">
	<input type="hidden" name="SPId" value="">
	<input type="hidden" name="CountryCode" value="CHN"> 
	<input type="hidden" name="BillType" value="0">
	<tr>
		<td class="td_edittitle" width="25%"><%=sp.getAliasByFiled("SPName")%></td>
		<td class="td_editcontent" width="75%">
			<input class="input_edit" style="width:100%;" type="text" name="SPName">
		</td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=sp.getAliasByFiled("ShortName")%></td>
		<td class="td_editcontent">
			<input class="input_edit" style="width:100%;" type="text" name="ShortName" maxlength="20">
		</td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=sp.getAliasByFiled("Address")%></td>
		<td class="td_editcontent">
			<input class="input_edit" style="width:100%;" type="text" name="Address" >
		</td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=sp.getAliasByFiled("Phone")%></td>
		<td class="td_editcontent">
			<input class="input_edit" style="width:100%;" type="text" name="Phone" maxlength="15">
		</td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=sp.getAliasByFiled("Fax")%></td>
		<td class="td_editcontent">
			<input class="input_edit" style="width:100%;" type="text" name="Fax">
		</td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=sp.getAliasByFiled("HomePage")%></td>
		<td class="td_editcontent">
			<input class="input_edit" style="width:100%;" type="text" name="HomePage">
		</td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=sp.getAliasByFiled("SystemUser")%></td>
		<td class="td_editcontent">
			<input class="input_edit" style="width:100%;" type="text" name="SystemUser">
		</td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=sp.getAliasByFiled("VoginsUser")%></td>
		<td class="td_editcontent">
			<input class="input_edit" style="width:100%;" type="text" name="VoginsUser">
		</td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=sp.getAliasByFiled("VoginsPass")%></td>
		<td class="td_editcontent">
			<input class="input_edit" style="width:100%;" type="text" name="VoginsPass">
		</td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=sp.getAliasByFiled("FeeURL")%></td>
		<td class="td_editcontent">
			<input class="input_edit" style="width:100%;" type="text" name="FeeURL">
		</td>
	</tr>
	<tr>
		<td class="td_editbutton" colspan="2">
			<a href="#" onclick="updateSubmit();"><img src="../<%=LangPage.langPage.getButton_img_path()%>next_001.gif"   border="0" align="top" vspace="1" /></a>&nbsp;&nbsp;
			<a href="#" onclick="updateCancel();"><img src="../<%=LangPage.langPage.getButton_img_path()%>cancel_001.gif"   border="0" align="top" vspace="1" /></a>
		</td>
	</tr>
	</form>
</table>
</div>

<!-- 联系人管理窗口 -->
<div align="center" id="contact_window" class="datainfo"><!-- 当前厂商信息信息 -->
<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
	<tr>
		<td class="td_edittitle" width="80"><%=sp.getAliasByFiled("SPName")%></td>
		<td class="td_editcontent" width="200" id="td_MfName"></td>
		<td class="td_edittitle" width="80"><%=sp.getAliasByFiled("BillType")%></td>
		<td class="td_editcontent" width="200" id="td_Bill"></td>
	</tr>
	<tr>
		<td class="td_edittitle" width="80"><%=sp.getAliasByFiled("Phone")%></td>
		<td class="td_editcontent" width="200" id="td_Phone"></td>
		<td class="td_edittitle" width="80"><%=sp.getAliasByFiled("AddTime")%></td>
		<td class="td_editcontent" width="200" id="td_CreateTime"></td>
	</tr>
</table>

<!-- 操作按钮 -->
<table width="90%" border="0" cellspacing="0" cellpadding="0"
	align="center">
	<tr>
		<td class="td_buttonbar" valign="middle">
			<a href="#" onclick="showNew1();"><img src="../<%=LangPage.langPage.getButton_img_path()%>add_001.gif"  border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a href="#" onclick="showUpdate1();"><img src="../<%=LangPage.langPage.getButton_img_path()%>update_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a href="#" onclick="deleteObj1();"><img src="../<%=LangPage.langPage.getButton_img_path()%>delete_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a href="#" onclick="openPage('contactlist',listIndex.get('contactlist'));"><img src="../<%=LangPage.langPage.getButton_img_path()%>refresh_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
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
		<input type="hidden" name="PartnerType" value="2">
	<tr>
		<td class="td_edittitle" width="25%"><%=contact.getAliasByFiled("Name")%></td>
		<td class="td_editcontent" width="75%"><input class="input_edit" style="width:100%;" type="text" name="Name" maxlength="10"></td>
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
		<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="Mobile"  maxlength="11"></td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=contact.getAliasByFiled("Phone")%></td>
		<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="Phone"  maxlength="12"></td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=contact.getAliasByFiled("EMail")%></td>
		<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="EMail"  maxlength="25"></td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=contact.getAliasByFiled("Title")%></td>
		<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="Title"  maxlength="8"></td>
	</tr>
	</form>
	<tr>
		<td class="td_editbutton" colspan="2">
			<a href="#" onclick="newSubmit1();"><img src="../<%=LangPage.langPage.getButton_img_path()%>ok_001.gif"   border="0" align="top" vspace="1" /></a>&nbsp;&nbsp;
			<a href="#" onclick="newCancel1();"><img src="../<%=LangPage.langPage.getButton_img_path()%>cancel_001.gif"   border="0" align="top" vspace="1" /></a>
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
		<input type="hidden" name="PartnerType" value="2">
	<tr>
		<td class="td_edittitle" width="25%"><%=contact.getAliasByFiled("Name")%></td>
		<td class="td_editcontent" width="75%"><input class="input_edit" style="width:100%;" type="text" name="Name" maxlength="10"></td>
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
		<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="Mobile" maxlength="11"></td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=contact.getAliasByFiled("Phone")%></td>
		<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="Phone" maxlength="12"></td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=contact.getAliasByFiled("EMail")%></td>
		<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="EMail" maxlength="25"></td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=contact.getAliasByFiled("Title")%></td>
		<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="Title" maxlength="8"></td>
	</tr>
	</form>
	<tr>
		<td class="td_editbutton" colspan="2">
			<a href="#" onclick="updateSubmit1();"><img src="../<%=LangPage.langPage.getButton_img_path()%>ok_001.gif"   border="0" align="top" vspace="1" /></a>&nbsp;&nbsp;
			<a href="#" onclick="updateCancel1();"><img src="../<%=LangPage.langPage.getButton_img_path()%>cancel_001.gif"   border="0" align="top" vspace="1" /></a>
		</td>
	</tr>
	</table>
</div>

<div id="tb_con" class="datainfo">
	<div align="center" id="conlist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
	</div>
</div>

</body>

</html>
