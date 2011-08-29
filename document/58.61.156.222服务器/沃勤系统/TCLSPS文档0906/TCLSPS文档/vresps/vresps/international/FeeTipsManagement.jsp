<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangAction"%>
<%@ page import="com.language.langdata.LangDBTable"%>
<%@ page import="com.vogins.sps.db.internation.InternationFeeTip"%>
<%
	InternationFeeTip feeTip = new InternationFeeTip();
%>
<html>
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<TITLE><%=LangPage.langPage.getPageTitle("country_inter")%></TITLE>
	<meta http-equiv="Pragma" content="no-cache">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_main.css">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_swin.css">
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_check.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_util.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_xml.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_view.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_swin.js"></SCRIPT>
	<script language=javascript>
	
<!---------------添加------------------------->
		var newwindow = new SimpleWindow();
		function showNew(){
				newwindow.Create('new_window','<%=LangPage.langPage.getWindowsTitle("country_add")%>',500,538,newHTML);
				newwindow.Show();
				showCountry();
			}
	
		function newCancel(){
			newwindow.Close();
		}
		function newSubmit(){
			if(NewCountry.CountryCode.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=feeTip.getAliasByFiled("CountryCode")%>");
				NewCountry.CountryCode.focus();
				return false;
			}
			if(NewCountry.Notice1.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=feeTip.getAliasByFiled("Notice1")%>");
				NewCountry.Notice1.focus();
				return false;
			}else{
				if(NewCountry.Notice1.value.indexOf("__goodname__")<0 || NewCountry.Notice1.value.indexOf("_goodprice_")<0){
					alert("<%=LangAction.langAction.getTip_no_key()%>");
					return false;
				}
			}
			if(NewCountry.Notice2.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=feeTip.getAliasByFiled("Notice2")%>");
				NewCountry.Notice2.focus();
				return false;
			}
			if(NewCountry.Notice3.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=feeTip.getAliasByFiled("Notice3")%>");
				NewCountry.Notice3.focus();
				return false;
			}
			if(NewCountry.Notice4.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=feeTip.getAliasByFiled("Notice4")%>");
				NewCountry.Notice4.focus();
				return false;
			}
			if(NewCountry.Notice5.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=feeTip.getAliasByFiled("Notice5")%>");
				NewCountry.Notice5.focus();
				return false;
			}
			if(NewCountry.Notice6.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=feeTip.getAliasByFiled("Notice6")%>");
				NewCountry.Notice6.focus();
				return false;
			}
			if(NewCountry.Notice7.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=feeTip.getAliasByFiled("Notice7")%>");
				NewCountry.Notice7.focus();
				return false;
			}
			if(NewCountry.Magnification.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=feeTip.getAliasByFiled("Magnification")%>");
				NewCountry.Magnification.focus();
				return false;
			}else{
				if(isNaN(NewCountry.Magnification.value)){
					alert("<%=LangAction.langAction.getMagnification_mustbe_number()%>");
					return false;
				}
			}
			if(NewCountry.CurrencyUnit.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=feeTip.getAliasByFiled("CurrencyUnit")%>");
				NewCountry.CurrencyUnit.focus();
				return false;
			}
			sendP("../AddTip.do",getP(NewCountry),newResult);
		}
		function newResult(cartXML){
			newwindow.Close();
			openPage('countryblist',listIndex.get('countryblist'));
		}

<!---------------修改------------------------->
		var updatewindow = new SimpleWindow();
		function showUpdate(){
			if(listCurrentKey.get('countryblist')==""){
				alert("<%=LangAction.langAction.getNoselect_tip()%>");
				return;
			}else{
				updatewindow.Create('update_window','<%=LangPage.langPage.getWindowsTitle("country_update")%>',500,536,updateHTML);
				updatewindow.Show();
				sendG("../GetTipInfo.do?RecId="+listCurrentKey.get('countryblist'),getUpdate);
			}
		}
		function updateCancel(){
			updatewindow.Close();
		}
		function getUpdate(cartXML){
			//UpdateCountry.reset();
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
				if(name == "<%=feeTip.getAliasByFiled("CountryCode")%>"){
					 UpdateCountry.CountryCode.value = value;
				}else if(name == "<%=feeTip.getAliasByFiled("Notice1")%>") {
					UpdateCountry.Notice1.value = value;
				}else if(name == "<%=feeTip.getAliasByFiled("Notice2")%>") {
					UpdateCountry.Notice2.value = value;
				}else if(name == "<%=feeTip.getAliasByFiled("Notice3")%>") {
					UpdateCountry.Notice3.value = value;
				}else if(name == "<%=feeTip.getAliasByFiled("Notice4")%>") {
					UpdateCountry.Notice4.value = value;
				}else if(name == "<%=feeTip.getAliasByFiled("Notice5")%>") {
					UpdateCountry.Notice5.value = value;
				}else if(name == "<%=feeTip.getAliasByFiled("Notice6")%>") {
					UpdateCountry.Notice6.value = value;
				}else if(name == "<%=feeTip.getAliasByFiled("Notice7")%>") {
					UpdateCountry.Notice7.value = value;
				}else if(name == "<%=feeTip.getAliasByFiled("Magnification")%>") {
					UpdateCountry.Magnification.value = value;
				}else if(name == "<%=feeTip.getAliasByFiled("CurrencyUnit")%>") {
					UpdateCountry.CurrencyUnit.value = value;
				}else if(name == "<%=feeTip.getAliasByFiled("Remark")%>") {
					UpdateCountry.Remark.value = value;
				}else if(name == "<%=feeTip.getAliasByFiled("RecId")%>") {
					UpdateCountry.RecId.value = value;
				}
			}
			
		}
		function updateSubmit(){
			if(UpdateCountry.CountryCode.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=feeTip.getAliasByFiled("CountryCode")%>");
				UpdateCountry.CountryCode.focus();
				return false;
			}
			if(UpdateCountry.Notice1.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=feeTip.getAliasByFiled("Notice1")%>");
				UpdateCountry.Notice1.focus();
				return false;
			}else{
				if(UpdateCountry.Notice1.value.indexOf("__goodname__")<0 || UpdateCountry.Notice1.value.indexOf("_goodprice_")<0){
					alert("<%=LangAction.langAction.getTip_no_key()%>");
					return false;
				}
			}
			if(UpdateCountry.Notice2.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=feeTip.getAliasByFiled("Notice2")%>");
				UpdateCountry.Notice2.focus();
				return false;
			}if(UpdateCountry.Notice3.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=feeTip.getAliasByFiled("Notice3")%>");
				UpdateCountry.Notice3.focus();
				return false;
			}if(UpdateCountry.Notice4.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=feeTip.getAliasByFiled("Notice4")%>");
				UpdateCountry.Notice4.focus();
				return false;
			}if(UpdateCountry.Notice5.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=feeTip.getAliasByFiled("Notice5")%>");
				UpdateCountry.Notice5.focus();
				return false;
			}if(UpdateCountry.Notice6.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=feeTip.getAliasByFiled("Notice6")%>");
				UpdateCountry.Notice6.focus();
				return false;
			}if(UpdateCountry.Notice7.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=feeTip.getAliasByFiled("Notice7")%>");
				UpdateCountry.Notice7.focus();
				return false;
			}
			if(UpdateCountry.Magnification.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=feeTip.getAliasByFiled("Magnification")%>");
				UpdateCountry.Magnification.focus();
				return false;
			}else{
				if(isNaN(UpdateCountry.Magnification.value)){
					alert("<%=LangAction.langAction.getMagnification_mustbe_number()%>");
					return false;
				}
			}
			if(UpdateCountry.CurrencyUnit.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=feeTip.getAliasByFiled("CurrencyUnit")%>");
				UpdateCountry.CurrencyUnit.focus();
				return false;
			}
			
			sendP("../UpdateTip.do",getP(UpdateCountry),updateResult);
		}
		function updateResult(){
			updatewindow.Close();
			openPage('countryblist',listIndex.get('countryblist'));
		}
		
<!---------------删除------------------------>
		function deleteObj(){
			if(listCurrentKey.get('countryblist')==""){
				alert("<%=LangAction.langAction.getNoselect_tip()%>");
				return;
			}else{
				if(confirm("<%=LangPage.langPage.getDelete_confirm()%>")){
					sendG("../DeleteTip.do?RecId="+listCurrentKey.get('countryblist'),deleteResult);
				}
			}
		}
		function deleteResult(){
			openPage('countryblist',listIndex.get('countryblist'));
		}


<!---------------------------------国家列表显示----------------------------------->
		function showCountry(){
		    sendG("../GetCountryCode.do",getCounResult);
		}
		function getCounResult(cartXML){
		 	var cart = cartXML.getElementsByTagName("result")[0];
			var list = cart.getElementsByTagName("list")[0];
			var rows = list.getElementsByTagName("row");
			NewCountry.CountryCode.options.length = 0;
			NewCountry.CountryCode.add(document.createElement("OPTION"));
			NewCountry.CountryCode.options[0].text="<%=LangPage.langPage.getSearch("search_pleaseselect")%>";
			NewCountry.CountryCode.options[0].value="";
			for(var i=0;i<rows.length;i++){
				var key = rows[i].getElementsByTagName("key")[0].firstChild.nodeValue;
				var field = rows[i].getElementsByTagName("field")[0].firstChild.nodeValue;
				NewCountry.CountryCode.add(document.createElement("OPTION"));
				NewCountry.CountryCode.options[i+1].text=field;
				NewCountry.CountryCode.options[i+1].value=key;
		 
			}
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
			openPage('countryblist','1');
		}

		function initList(){
			listIndex.put('countryblist','1');
			listPageURL.put('countryblist','../GetTipList.do?index=#index#');
			listDetailURL.put('countryblist','../GetTipInfo.do?RecId=#id#');
			listCurrentId.put('countryblist','');
			listCurrentKey.put('countryblist','');
			listDetailWidth.put('countryblist','450');
			listDetailHeight.put('countryblist','287');
			listListXSL.put('countryblist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('countryblist','../xsl/jwdf_sdetail.xsl');


			listIndex.put('conlist','1');
			listPageURL.put('conlist','../GetAllCountry.do');
			listDetailURL.put('conlist','');
			listCurrentId.put('conlist','');
			listCurrentKey.put('conlist','');
			listDetailWidth.put('conlist','300');
			listDetailHeight.put('conlist','320');
			listListXSL.put('conlist','../xsl/jwdf_listnopage.xsl');
			listDetailXSL.put('conlist','');
			//listClickEvent.put('conlist',selectCon);
		}
		
<!------------------------------------------------------------->
	</script>
</head>

<body onload="init();">
	<!-- 页面标题 -->
	<table class="table_pagetitle" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("country_inter")%></td>
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

	<!-- 列表显示区域 -->
	<div align="center" id="countryblist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
	</div>

	<!-- 添加表单 -->
	<div id="tb_new" class="datainfo">
		<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
		<form method="POST" name="NewCountry" class="editform">
		<tr>
			<td class="td_edittitle" width="25%"><%=feeTip.getAliasByFiled("CountryCode")%></td>
			<td algin="left" class="td_editcontent">
			<select name="CountryCode"><option selected value=""><%=LangPage.langPage.getSearch("search_pleaseselect")%></option></select>
			</td>
		</tr>
		<tr>
			<td class="td_edittitle" width="25%"><%=feeTip.getAliasByFiled("Notice1")%></td>
			<td class="td_editcontent" width="75%"><textarea name="Notice1" class="input_textarea" onkeydown="checkLength('Notice1',160);"></textarea></td>
		</tr>
		<tr>
			<td class="td_edittitle" width="25%"><%=feeTip.getAliasByFiled("Notice2")%></td>
			<td class="td_editcontent" width="75%"><textarea name="Notice2" class="input_textarea" onkeydown="checkLength('Notice2',128);"></textarea></td>
		</tr>
		<tr>
			<td class="td_edittitle" width="25%"><%=feeTip.getAliasByFiled("Notice3")%></td>
			<td class="td_editcontent" width="75%"><textarea name="Notice3" class="input_textarea" onkeydown="checkLength('Notice3',128);"></textarea></td>
		</tr>
		<tr>
			<td class="td_edittitle" width="25%"><%=feeTip.getAliasByFiled("Notice4")%></td>
			<td class="td_editcontent" width="75%"><textarea name="Notice4" class="input_textarea" onkeydown="checkLength('Notice4',160);"></textarea></td>
		</tr>
		<tr>
			<td class="td_edittitle" width="25%"><%=feeTip.getAliasByFiled("Notice5")%></td>
			<td class="td_editcontent" width="75%"><textarea name="Notice5" class="input_textarea" onkeydown="checkLength('Notice5',128);"></textarea></td>
		</tr>
		<tr>
			<td class="td_edittitle" width="25%"><%=feeTip.getAliasByFiled("Notice6")%></td>
			<td class="td_editcontent" width="75%"><textarea name="Notice6" class="input_textarea" onkeydown="checkLength('Notice6',32);"></textarea></td>
		</tr>
		<tr>
			<td class="td_edittitle" width="25%"><%=feeTip.getAliasByFiled("Notice7")%></td>
			<td class="td_editcontent" width="75%"><textarea name="Notice7" class="input_textarea" onkeydown="checkLength('Notice7',32);"></textarea></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=feeTip.getAliasByFiled("Magnification")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="Magnification"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=feeTip.getAliasByFiled("CurrencyUnit")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="CurrencyUnit" maxlength="10"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=feeTip.getAliasByFiled("Remark")%></td>
			<td class="td_editcontent"><textarea name="Remark" class="input_textarea" onkeydown="checkLength('Remark',500);"></textarea></td>
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

	<!-- 修改表单 -->
	<div id="tb_update" class="datainfo">
		<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
		<form method="POST" name="UpdateCountry" class="editform">
			<input type="hidden" name="RecId" value="">
		<tr>
			<td class="td_edittitle" width="25%"><%=feeTip.getAliasByFiled("CountryCode")%></td>
			<td class="td_editcontent" width="75%"><input class="input_edit" style="width:100%;" type="text" maxlength="20" name="CountryCode" readonly></td>
		</tr>
				<tr>
			<td class="td_edittitle" width="25%"><%=feeTip.getAliasByFiled("Notice1")%></td>
			<td class="td_editcontent" width="75%"><textarea name="Notice1" class="input_textarea" onkeydown="checkLength('Notice1',160);"></textarea></td>
		</tr>
		<tr>
			<td class="td_edittitle" width="25%"><%=feeTip.getAliasByFiled("Notice2")%></td>
			<td class="td_editcontent" width="75%"><textarea name="Notice2" class="input_textarea" onkeydown="checkLength('Notice2',128);"></textarea></td>
		</tr>
		<tr>
			<td class="td_edittitle" width="25%"><%=feeTip.getAliasByFiled("Notice3")%></td>
			<td class="td_editcontent" width="75%"><textarea name="Notice3" class="input_textarea" onkeydown="checkLength('Notice3',128);"></textarea></td>
		</tr>
		<tr>
			<td class="td_edittitle" width="25%"><%=feeTip.getAliasByFiled("Notice4")%></td>
			<td class="td_editcontent" width="75%"><textarea name="Notice4" class="input_textarea" onkeydown="checkLength('Notice4',160);"></textarea></td>
		</tr>
		<tr>
			<td class="td_edittitle" width="25%"><%=feeTip.getAliasByFiled("Notice5")%></td>
			<td class="td_editcontent" width="75%"><textarea name="Notice5" class="input_textarea" onkeydown="checkLength('Notice5',128);"></textarea></td>
		</tr>
		<tr>
			<td class="td_edittitle" width="25%"><%=feeTip.getAliasByFiled("Notice6")%></td>
			<td class="td_editcontent" width="75%"><textarea name="Notice6" class="input_textarea" onkeydown="checkLength('Notice6',32);"></textarea></td>
		</tr>
		<tr>
			<td class="td_edittitle" width="25%"><%=feeTip.getAliasByFiled("Notice7")%></td>
			<td class="td_editcontent" width="75%"><textarea name="Notice7" class="input_textarea" onkeydown="checkLength('Notice7',32);"></textarea></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=feeTip.getAliasByFiled("Magnification")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="Magnification"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=feeTip.getAliasByFiled("CurrencyUnit")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="CurrencyUnit" maxlength="10"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=feeTip.getAliasByFiled("Remark")%></td>
			<td class="td_editcontent"><textarea name="Remark" class="input_textarea" onkeydown="checkLength('Remark',500);"></textarea></td>
		</tr>
		</form>
		<tr>
			<td class="td_editbutton" colspan="2">
				<a href="#" onclick="updateSubmit();"><img src="../<%=LangPage.langPage.getButton_img_path()%>ok_001.gif"   border="0" align="top" vspace="1" /></a>&nbsp;&nbsp;
				<a href="#" onclick="updateCancel();"><img src="../<%=LangPage.langPage.getButton_img_path()%>cancel_001.gif"   border="0" align="top" vspace="1" /></a>
			</td>
		</tr>
		</table>
	</div>
</body>

</html>
