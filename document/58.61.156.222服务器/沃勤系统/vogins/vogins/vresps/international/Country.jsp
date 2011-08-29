<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangAction"%>
<%@ page import="com.language.langdata.LangDBTable"%>
<%@ page import="com.vogins.sps.db.internation.Country"%>
<%
	Country co = new Country();
%>
<html>
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<TITLE><%=LangPage.langPage.getPageTitle("country_inter")%></TITLE>
	<meta http-equiv="Pragma" content="no-cache">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_main.css">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_swin.css">
	<SCRIPT language="JavaScript" type="text/javascript" src="../js/jwdf_util.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_xml.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_view.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_swin.js"></SCRIPT>
	<script language=javascript>
	
<!---------------添加------------------------->
		var newwindow = new SimpleWindow();
		function showNew(){
				newwindow.Create('new_window','<%=LangPage.langPage.getWindowsTitle("country_add")%>',500,112,newHTML);
				newwindow.Show();
			}
	
		function newCancel(){
			newwindow.Close();
		}
		function newSubmit(){
			if(NewCountry.CountryCode.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=co.getAliasByFiled("CountryCode")%>");
				NewCountry.CountryCode.focus();
				return false;
			}
			if(NewCountry.CountryName.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=co.getAliasByFiled("CountryName")%>");
				NewCountry.CountryName.focus();
				return false;
			}
			if(NewCountry.EnName.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=co.getAliasByFiled("EnName")%>");
				NewCountry.EnName.focus();
				return false;
			}
			sendP("../AddCountry.do",getP(NewCountry),newResult);
		}
		function newResult(cartXML){
			newwindow.Close();
			openPage('countryblist',listIndex.get('countryblist'));
		}

<!---------------修改------------------------->
		var updatewindow = new SimpleWindow();
		function showUpdate(){
			if(listCurrentKey.get('countryblist')==""){
				alert("<%=LangAction.langAction.getNoselect_country()%>");
				return;
			}else{
				updatewindow.Create('update_window','<%=LangPage.langPage.getWindowsTitle("country_update")%>',500,112,updateHTML);
				updatewindow.Show();
				sendG("../GetCountryInfo.do?CountryCode="+listCurrentKey.get('countryblist'),getUpdate);
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
				if(name == "<%=co.getAliasByFiled("CountryCode")%>"){
					 UpdateCountry.CountryCode.value = value;
				}else if(name == "<%=co.getAliasByFiled("CountryName")%>") {
					UpdateCountry.CountryName.value = value;
				}else if(name == "<%=co.getAliasByFiled("EnName")%>") {
					UpdateCountry.EnName.value = value;
				}
			}
			
		}
		function updateSubmit(){
			if(UpdateCountry.CountryCode.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=co.getAliasByFiled("CountryCode")%>");
				UpdateCountry.CountryCode.focus();
				return false;
			}
			if(UpdateCountry.CountryName.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=co.getAliasByFiled("CountryName")%>");
				UpdateCountry.CountryName.focus();
				return false;
			}
			if(UpdateCountry.EnName.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=co.getAliasByFiled("EnName")%>");
				UpdateCountry.EnName.focus();
				return false;
			}
			
			sendP("../UpdateCountry.do",getP(UpdateCountry),updateResult);
		}
		function updateResult(){
			updatewindow.Close();
			openPage('countryblist',listIndex.get('countryblist'));
		}
		
<!---------------删除------------------------>
		function deleteObj(){
			if(listCurrentKey.get('countryblist')==""){
				alert("<%=LangAction.langAction.getNoselect_country()%>");
				return;
			}else{
				if(confirm("<%=LangPage.langPage.getDelete_confirm()%>")){
					sendG("../DeleteCountry.do?CountryCode="+listCurrentKey.get('countryblist'),deleteResult);
				}
			}
		}
		function deleteResult(){
			openPage('countryblist',listIndex.get('countryblist'));
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
			listPageURL.put('countryblist','../GetCountryList.do?index=#index#');
			//listDetailURL.put('countryblist','../GetCountryInfo.do?CountryId=#id#');
			listCurrentId.put('countryblist','');
			listCurrentKey.put('countryblist','');
			listDetailWidth.put('countryblist','350');
			listDetailHeight.put('countryblist','300');
			listListXSL.put('countryblist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			//listDetailXSL.put('countryblist','../xsl/jwdf_sdetail.xsl');
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
			<td class="td_edittitle" width="25%"><%=co.getAliasByFiled("CountryCode")%></td>
			<td class="td_editcontent" width="75%"><input class="input_edit" style="width:100%;" type="text" maxlength="20" name="CountryCode"></td>
		</tr>
		<tr>
			<td class="td_edittitle" width="25%"><%=co.getAliasByFiled("CountryName")%></td>
			<td class="td_editcontent" width="75%"><input class="input_edit" style="width:100%;" type="text" maxlength="20" name="CountryName"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=co.getAliasByFiled("EnName")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="EnName"></td>
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
			<input type="hidden" name="CountryCodeId" value="">
		<tr>
			<td class="td_edittitle" width="25%"><%=co.getAliasByFiled("CountryCode")%></td>
			<td class="td_editcontent" width="75%"><input class="input_edit" style="width:100%;" type="text" maxlength="20" name="CountryCode" readonly></td>
		</tr>
		<tr>
			<td class="td_edittitle" width="25%"><%=co.getAliasByFiled("CountryName")%></td>
			<td class="td_editcontent" width="75%"><input class="input_edit" style="width:100%;" type="text" maxlength="20" name="CountryName"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=co.getAliasByFiled("EnName")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="EnName"></td>
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
