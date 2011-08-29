<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangAction"%>
<%@ page import="com.vogins.sps.db.mobile.MFPartner"%>
<%@ page import="com.vogins.sps.db.publicinfo.Contact"%>
<%
	MFPartner mf = new MFPartner();
	Contact contact = new Contact();
%>
<html> 

<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<TITLE><%=LangPage.langPage.getPageTitle("mf")%></TITLE>
	<meta http-equiv="Pragma" content="no-cache">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_main.css">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_swin.css">
	<SCRIPT language="JavaScript" type="text/javascript" src="../js/jwdf_util.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_xml.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_view.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_swin.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>sps_workflow.js"></SCRIPT>
	<script language=javascript>
	
<!----------------添加手机厂商---------------------------->
		var cur_flowid = "";
		var newwindow = new SimpleWindow();
		var reg=/[\u4E00-\u9FA5]/g; //汉字判断
		var zimu =/[a-zA-Z]/ ;  //字母判断
		var shuzi =/^[0-9]*[1-9][0-9]*$/; //数字
		function showNew(){
			newwindow.Create('new_window','<%=LangPage.langPage.getWindowsTitle("cw_addmfpartner")%>',350,320,newHTML);
			newwindow.Show();
		}
		function newCancel(){
			newwindow.Close();
		}
		
		function newSubmit(){
			if(NewPartner.PartnerName.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=mf.getAliasByFiled("MFName")%>");
				NewPartner.PartnerName.focus();
				return false;
			}
			sendP("../AddMF.do",getP(NewPartner),newResult);
		}
		function newResult(cartXML){
		    var cart = cartXML.getElementsByTagName("result")[0];
			var flowId = cart.getElementsByTagName("info")[0].firstChild.nodeValue;
			cur_flowid = flowId;

			newwindow.Close();
			openWFNodeSet();
		}
<!------------------------------------------------------------->

<!---------------修改手机厂商--------------------------------->
		var updatewindow = new SimpleWindow();
		function showUpdate(){
			if(listCurrentKey.get('mflist')==""){
				alert("<%=LangAction.langAction.getNoselect_mf()%>");
				return;
			}else{
				updatewindow.Create('update_window','<%=LangPage.langPage.getWindowsTitle("mf_updatemf")%>',350,320,updateHTML);
				updatewindow.Show();
				sendG("../GetMFInfo.do?PartnerId="+listCurrentKey.get('mflist'),getUpdate);
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
				
				if(name == "<%=mf.getAliasByFiled("MFId")%>") UpdatePartner.PartnerId.value = value;
				else if(name == "<%=mf.getAliasByFiled("MFName")%>") UpdatePartner.PartnerName.value = value;
				else if(name == "<%=mf.getAliasByFiled("ShortName")%>") UpdatePartner.ShortName.value = value;
				else if(name == "<%=mf.getAliasByFiled("Address")%>") UpdatePartner.Address.value = value;
				else if(name == "<%=mf.getAliasByFiled("Phone")%>") UpdatePartner.Phone.value = value;
				else if(name == "<%=mf.getAliasByFiled("Fax")%>") UpdatePartner.Fax.value = value;
				else if(name == "<%=mf.getAliasByFiled("HomePage")%>") UpdatePartner.HomePage.value = value;
				else if(name == "<%=mf.getAliasByFiled("BillType")%>") UpdatePartner.Commission.value = value;
				else if(name =="<%=mf.getAliasByFiled("UAId")%>") UpdatePartner.UAId.value = value;
				else if(name =="<%=mf.getAliasByFiled("TestFlag")%>")UpdatePartner.TestFlag.value = value;
				else if(name == "<%=mf.getAliasByFiled("SystemUser")%>") UpdatePartner.SystemUser.value = value;
				else if(name == "<%=mf.getAliasByFiled("FeeChannelTag")%>") UpdatePartner.FeeChannelTag.value = value;
				else if(name == "<%=mf.getAliasByFiled("ProductDirectoryTag")%>") UpdatePartner.ProductDirectoryTag.value = value;
			}
		}
	
		function updateSubmit(){
			if(UpdatePartner.PartnerName.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=mf.getAliasByFiled("MFName")%>");
				UpdatePartner.PartnerName.focus();
				return false;
			}
			sendP("../UpdateMF.do",getP(UpdatePartner),updateResult);
		}
		
		function updateResult(cartXML){
			var cart = cartXML.getElementsByTagName("result")[0];
			var flowId = cart.getElementsByTagName("info")[0].firstChild.nodeValue;
			cur_flowid = flowId;

			updatewindow.Close();
			openWFNodeSet();
		}
<!------------------------------------------------------------->

<!----------------删除手机厂商--------------------------->
		function deleteObj(){
			if(listCurrentKey.get('mflist')==""){
				alert("<%=LangAction.langAction.getNoselect_mf()%>");
				return;
			}else{
				if(confirm("<%=LangPage.langPage.getDelete_confirm()%>")){
					sendG("../DeleteMF.do?MFId="+listCurrentKey.get('mflist'),deleteResult);
				}
			}
		}
		function deleteResult(cartXML){
			var cart = cartXML.getElementsByTagName("result")[0];
			var flowId = cart.getElementsByTagName("info")[0].firstChild.nodeValue;
			cur_flowid = flowId;

			handlewindow.Create('hdl_window','<%=LangPage.langPage.getWindowsTitle("workflow_sub")%>',350,300,handleHTML);
			handlewindow.Show();
			listPageURL.put('sublist','../GetSubWFList.do?index=#index#&AppSeqNo=1&FlowId='+cur_flowid);
			openPage('sublist','1');
		}
<!------------------------------------------------------------->

<!------------------显示机型窗口---------------------------->
		var mobilewindow = new SimpleWindow();
		function showMobile(){
			if(listCurrentKey.get('mflist') == ""){
				alert("<%=LangAction.langAction.getNoselect_mf()%>");
				return;
			}else{
				mobilewindow.Create('mobile_window','<%=LangPage.langPage.getWindowsTitle("cw_mfmobile")%>',500,400,mobileHTML);
				mobilewindow.Show();
				listPageURL.put('mobilelist','../GetMobileList.do?PartnerId='+listCurrentKey.get('mflist')+'&index=#index#');
				openPage('mobilelist','1');
			}
		}
<!------------------------------------------------------------->
		
<!---------------添加联系人------------------------->
		var newwindow1 = new SimpleWindow();
		var cur_partnerid="";
		function showNew1(){
			if(listCurrentKey.get('mflist')==""){
				alert("<%=LangAction.langAction.getNoselect_sp()%>");
				return;
			}else{
				cur_partnerid = listCurrentKey.get('mflist');
				newwindow1.Create('new_window1','<%=LangPage.langPage.getWindowsTitle("contact_new")%>',280,177,ConnewHTML);
				newwindow1.Show();
			}
		}
		function newCancel1(){
			newwindow1.Close();
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
			newwindow1.Close();
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

		var viewwindow = new SimpleWindow();
		function ShowContact(){
			if(listCurrentKey.get('mflist')==""){
				alert("<%=LangAction.langAction.getNoselect_mf()%>");
				return;
			}else{
				viewwindow.Create('contact_window','<%=LangPage.langPage.getWindowsTitle("cw_mfcontact")%>',500,350,contactHTML);
				viewwindow.Show();
				sendG("../GetMFInfo.do?PartnerId="+listCurrentKey.get('mflist'),getMFDetail1);
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
				if(name == "<%=mf.getAliasByFiled("MFName")%>") document.all["td_MfName"].innerHTML = value;
				else if(name == "<%=mf.getAliasByFiled("BillType")%>") document.all["td_Bill"].innerHTML = value;
			    else if(name == "<%=mf.getAliasByFiled("Phone")%>") document.all["td_Phone"].innerHTML = value;
				else if(name == "<%=mf.getAliasByFiled("AddTime")%>") document.all["td_CreateTime"].innerHTML = value;
			}
			listPageURL.put('contactlist','../GetContactList.do?PartnerType=1&PartnerId='+listCurrentKey.get('mflist')+'&index=#index#');
			openPage('contactlist','1');
		}
		<!------------------------------------------------------------->


		<!------------------页面初始化---------------------->
		var newHTML = "";
		var updateHTML = "";
		var mobileHTML = "";
		
		var ConnewHTML ="";
		var ConUpdateHTML = "";
		var contactHTML ="";

		
		function init(){
			newHTML = document.all["tb_new"].innerHTML;
			document.all["tb_new"].innerHTML = "";
			updateHTML = document.all["tb_update"].innerHTML;
			document.all["tb_update"].innerHTML = "";
			mobileHTML = document.all["tb_mobile"].innerHTML;
			document.all["tb_mobile"].innerHTML = "";
            
            ConnewHTML = document.all["tb_contactnew"].innerHTML;
			document.all["tb_contactnew"].innerHTML = "";
            ConUpdateHTML = document.all["tb_contactupdate"].innerHTML;
			document.all["tb_contactupdate"].innerHTML = "";
		    contactHTML = document.all["contact_window"].innerHTML;
			document.all["contact_window"].innerHTML = "";

			initList();
			openPage('mflist','1');
		}

		function initList(){
			listIndex.put('mflist','1');
			listPageURL.put('mflist','../GetMFList.do?index=#index#');
			listDetailURL.put('mflist','../GetMFInfo.do?PartnerId=#id#');
			listCurrentId.put('mflist','');
			listCurrentKey.put('mflist','');
			listDetailWidth.put('mflist','350');
			listDetailHeight.put('mflist','300');
			listListXSL.put('mflist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('mflist','../xsl/jwdf_sdetail.xsl');

			listIndex.put('mobilelist','1');
			listPageURL.put('mobilelist','');
			listDetailURL.put('mobilelist','../GetMobileInfo.do?MobileId=#id#');
			listCurrentId.put('mobilelist','');
			listCurrentKey.put('mobilelist','');
			listDetailWidth.put('mobilelist','350');
			listDetailHeight.put('mobilelist','320');
			listListXSL.put('mobilelist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('mobilelist','../xsl/jwdf_sdetail.xsl');
		
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
		<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("mf")%></td>
	</tr>
	</table>
	
	<!-- 操作按钮 -->
	<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_buttonbar" valign="middle">
			<a href="#" onclick="showNew();"><img src="../<%=LangPage.langPage.getButton_img_path()%>add_001.gif" border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a href="#" onclick="showUpdate();"><img src="../<%=LangPage.langPage.getButton_img_path()%>update_001.gif" border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a href="#" onclick="deleteObj();"><img src="../<%=LangPage.langPage.getButton_img_path()%>delete_001.gif" border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a href="#" onclick="ShowContact();"><img src="../<%=LangPage.langPage.getButton_img_path()%>contact_001.gif" border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a href="#" onclick="showMobile();"><img src="../<%=LangPage.langPage.getButton_img_path()%>mobile_001.gif" border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			
		</td>
	</tr>
	</table>

	<!-- 手机厂商列表显示区域 -->
	<div align="center" id="mflist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
	</div>

	<!-- 添加手机厂商表单 -->
	<div id="tb_new" class="datainfo">
		<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
		<form method="POST" name="NewPartner" class="editform">
					<input type="hidden" name="PartnerType" value="1">
		<tr>
			<td class="td_edittitle" width="25%"><%=mf.getAliasByFiled("MFName")%></td>
			<td class="td_editcontent" width="75%"><input class="input_edit" style="width:100%;" type="text" name="PartnerName"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=mf.getAliasByFiled("ShortName")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="ShortName"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=mf.getAliasByFiled("Address")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="Address"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=mf.getAliasByFiled("Phone")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="Phone"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=mf.getAliasByFiled("Fax")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="Fax"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=mf.getAliasByFiled("HomePage")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="HomePage"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=mf.getAliasByFiled("BillType")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="Commission"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=mf.getAliasByFiled("UAId")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="UAId"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=mf.getAliasByFiled("TestFlag")%></td>
			<td class="td_editcontent" width="200"><select name="TestFlag">
		   <option value="1"><%=LangPage.langPage.getSelect("testflag_test")%></option>
		   <option value="2"><%=LangPage.langPage.getSelect("testflag_normal")%></option>
		   </select>
		</td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=mf.getAliasByFiled("SystemUser")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text"  name="SystemUser"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=mf.getAliasByFiled("FeeChannelTag")%></td>
			<td class="td_editcontent" width="160">
				<select name="FeeChannelTag">
		   			<option value="0"><%=LangPage.langPage.getSelect("bgrun_no")%></option>
		   			<option value="1"><%=LangPage.langPage.getSelect("bgrun_yes")%></option>
		   		</select>
		</tr>
		<tr>
			<td class="td_edittitle"><%=mf.getAliasByFiled("ProductDirectoryTag")%></td>
			<td class="td_editcontent" width="160">
				<select name="ProductDirectoryTag">
		   			<option value="0"><%=LangPage.langPage.getSelect("bgrun_no")%></option>
		   			<option value="1"><%=LangPage.langPage.getSelect("bgrun_yes")%></option>
		   		</select>
		</tr>
		</form>
		<tr>
			<td class="td_editbutton" colspan="2">
				<a href="#" onclick="newSubmit();"><img src="../<%=LangPage.langPage.getButton_img_path()%>next_001.gif"   border="0" align="top" vspace="1" /></a>
				<a href="#" onclick="newCancel();"><img src="../<%=LangPage.langPage.getButton_img_path()%>cancel_001.gif"   border="0" align="top" vspace="1" /></a>
			</td>
		</tr>
		</table>
	</div>

	<!-- 修改手机厂商表单 -->
	<div id="tb_update" class="datainfo">
		<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
		<form method="POST" name="UpdatePartner" class="editform">
			<input type="hidden" name="PartnerId" value="">
			<input type="hidden" name="PartnerType" value="1">
		<tr>
			<td class="td_edittitle" width="25%"><%=mf.getAliasByFiled("MFName")%></td>
			<td class="td_editcontent" width="75%"><input class="input_edit" style="width:100%;" type="text" name="PartnerName"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=mf.getAliasByFiled("ShortName")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="ShortName"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=mf.getAliasByFiled("Address")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="Address"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=mf.getAliasByFiled("Phone")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="Phone"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=mf.getAliasByFiled("Fax")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="Fax"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=mf.getAliasByFiled("HomePage")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="HomePage"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=mf.getAliasByFiled("BillType")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="Commission"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=mf.getAliasByFiled("UAId")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="UAId"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=mf.getAliasByFiled("TestFlag")%></td>
			<td class="td_editcontent" width="200"><select name="TestFlag">
		   <option value="1"><%=LangPage.langPage.getSelect("testflag_test")%></option>
		   <option value="2"><%=LangPage.langPage.getSelect("testflag_normal")%></option>
		   </select>
		</td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=mf.getAliasByFiled("SystemUser")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text"  name="SystemUser"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=mf.getAliasByFiled("FeeChannelTag")%></td>
			<td class="td_editcontent" width="160">
				<select name="FeeChannelTag">
		   			<option value="0"><%=LangPage.langPage.getSelect("bgrun_no")%></option>
		   			<option value="1"><%=LangPage.langPage.getSelect("bgrun_yes")%></option>
		   		</select>
		</tr>
		<tr>
			<td class="td_edittitle"><%=mf.getAliasByFiled("ProductDirectoryTag")%></td>
			<td class="td_editcontent" width="160">
				<select name="ProductDirectoryTag">
		   			<option value="0"><%=LangPage.langPage.getSelect("bgrun_no")%></option>
		   			<option value="1"><%=LangPage.langPage.getSelect("bgrun_yes")%></option>
		   		</select>
		</tr>
		</form>
		<tr>
			<td class="td_editbutton" colspan="2">
				<a href="#" onclick="updateSubmit();"><img src="../<%=LangPage.langPage.getButton_img_path()%>next_001.gif"   border="0" align="top" vspace="1" /></a>
				<a href="#" onclick="updateCancel();"><img src="../<%=LangPage.langPage.getButton_img_path()%>cancel_001.gif"   border="0" align="top" vspace="1" /></a>
			</td>
		</tr>
		</table>
	</div>
	
	
	
	<!-- 联系人管理窗口 -->
<div align="center" id="contact_window" class="datainfo"><!-- 当前厂商信息信息 -->
<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
	<tr>
		<td class="td_edittitle" width="80"><%=mf.getAliasByFiled("MFName")%></td>
		<td class="td_editcontent" width="200" id="td_MfName"></td>
		<td class="td_edittitle" width="80"><%=mf.getAliasByFiled("BillType")%></td>
		<td class="td_editcontent" width="200" id="td_Bill"></td>
	</tr>
	<tr>
		<td class="td_edittitle" width="80"><%=mf.getAliasByFiled("Phone")%></td>
		<td class="td_editcontent" width="200" id="td_Phone"></td>
		<td class="td_edittitle" width="80"><%=mf.getAliasByFiled("AddTime")%></td>
		<td class="td_editcontent" width="200" id="td_CreateTime"></td>
	</tr>
</table>

<!-- 操作按钮 -->
<table width="90%" border="0" cellspacing="0" cellpadding="0"
	align="center">
	<tr>
		<td class="td_buttonbar" valign="middle">
			<a href="#" onclick="showNew1();"><img src="../<%=LangPage.langPage.getButton_img_path()%>add_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a href="#" onclick="showUpdate1();"><img src="../<%=LangPage.langPage.getButton_img_path()%>update_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a href="#" onclick="deleteObj1();"><img src="../<%=LangPage.langPage.getButton_img_path()%>delete_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a href="#" onclick="openPage('contactlist',listIndex.get('contactlist'));"><img src="../<%=LangPage.langPage.getButton_img_path()%>refresh_001.gif"   border="0" align="top" vspace="1"/></a>
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
			<input type="hidden" name=PartnerType value="1">
		<tr>
			<td class="td_edittitle" width="80"><%=contact.getAliasByFiled("Name")%></td>
			<td class="td_editcontent" width="200"><input class="input_edit" style="width:100%;" type="text" name="Name"></td>
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
			<td class="td_edittitle" width="80"><%=contact.getAliasByFiled("Mobile")%></td>
			<td class="td_editcontent" width="200"><input class="input_edit" style="width:100%;" type="text" name="Mobile"></td>
		</tr>
		<tr>
			<td class="td_edittitle" width="80"><%=contact.getAliasByFiled("Phone")%></td>
			<td class="td_editcontent" width="200"><input class="input_edit" style="width:100%;" type="text" name="Phone"></td>
		</tr>
		<tr>
			<td class="td_edittitle" width="80"><%=contact.getAliasByFiled("EMail")%></td>
			<td class="td_editcontent" width="200"><input class="input_edit" style="width:100%;" type="text" name="EMail"></td>
		</tr>
		<tr>
			<td class="td_edittitle" width="80"><%=contact.getAliasByFiled("Title")%></td>
			<td class="td_editcontent" width="200"><input class="input_edit" style="width:100%;" type="text" name="Title"></td>
		</tr>
		</form>
		<tr>
			<td class="td_editbutton" colspan="2">
				<a href="#" onclick="newSubmit1();"><img src="../<%=LangPage.langPage.getButton_img_path()%>ok_001.gif"   border="0" align="top" vspace="1" /></a>
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
			<input type="hidden" name="PartnerType" value="1">
		<tr>
			<td class="td_edittitle" width="80"><%=contact.getAliasByFiled("Name")%></td>
			<td class="td_editcontent" width="200"><input class="input_edit" style="width:100%;" type="text" name="Name"></td>
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
			<td class="td_edittitle" width="80"><%=contact.getAliasByFiled("Mobile")%></td>
			<td class="td_editcontent" width="200"><input class="input_edit" style="width:100%;" type="text" name="Mobile"></td>
		</tr>
		<tr>
			<td class="td_edittitle" width="80"><%=contact.getAliasByFiled("Phone")%></td>
			<td class="td_editcontent" width="200"><input class="input_edit" style="width:100%;" type="text" name="Phone"></td>
		</tr>
		<tr>
			<td class="td_edittitle" width="80"><%=contact.getAliasByFiled("EMail")%></td>
			<td class="td_editcontent" width="200"><input class="input_edit" style="width:100%;" type="text" name="EMail"></td>
		</tr>
		<tr>
			<td class="td_edittitle" width="80"><%=contact.getAliasByFiled("Title")%></td>
			<td class="td_editcontent" width="200"><input class="input_edit" style="width:100%;" type="text" name="Title"></td>
		</tr>
		</form>
		<tr>
			<td class="td_editbutton" colspan="2">
				<a href="#" onclick="updateSubmit1();"><img src="../<%=LangPage.langPage.getButton_img_path()%>ok_001.gif"   border="0" align="top" vspace="1" /></a>
				<a href="#" onclick="updateCancel1();"><img src="../<%=LangPage.langPage.getButton_img_path()%>cancel_001.gif"   border="0" align="top" vspace="1" /></a>
			</td>
		</tr>
		</table> 
	</div>
	
	<div id="tb_mobile" class="datainfo">
		<div align="center" id="mobilelist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		</div>
	</div>
	
</body>

</html>
