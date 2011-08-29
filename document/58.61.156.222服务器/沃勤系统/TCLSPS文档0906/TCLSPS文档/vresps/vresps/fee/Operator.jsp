<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangAction"%>
<%@ page import="com.language.langdata.LangDBTable"%>
<%@ page import="com.vogins.sps.db.internation.Operator"%>
<%
	Operator oper = new Operator();
%>
<html>
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<TITLE><%=LangPage.langPage.getPageTitle("operator_inter")%></TITLE>
	<meta http-equiv="Pragma" content="no-cache">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_main.css">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_swin.css">
	<SCRIPT language="JavaScript" type="text/javascript" src="../js/jwdf_util.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_xml.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_view.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_swin.js"></SCRIPT>
	<script language=javascript>
		<!--------------------------------显示国家选择窗口----------------------------------->
		function showCountry(){
		    sendG("../GetAllCountry.do",getCounResult);
		}
		function getCounResult(cartXML){
		 	var cart = cartXML.getElementsByTagName("result")[0];
			var list = cart.getElementsByTagName("list")[0];
			var rows = list.getElementsByTagName("row");
			OperatorForm.CountryCode.options.length = 0;
			OperatorForm.CountryCode.add(document.createElement("OPTION"));
			OperatorForm.CountryCode.options[0].text="<%=LangPage.langPage.getSearch("search_pleaseselect")%>";
			OperatorForm.CountryCode.options[0].value="";
			for(var i=0;i<rows.length;i++){
				var key = rows[i].getElementsByTagName("key")[0].firstChild.nodeValue;
				var field = rows[i].getElementsByTagName("field")[0].firstChild.nodeValue;
				OperatorForm.CountryCode.add(document.createElement("OPTION"));
				OperatorForm.CountryCode.options[i+1].text=field;
			    OperatorForm.CountryCode.options[i+1].value=key;
		 
			}
		}
		function getSpByCountry(){
		    listPageURL.put('operatorlist','../GetOPByCountry3.do?CountryCode='+OperatorForm.CountryCode.value+'&index=#index#');
			openPage('operatorlist','1');
		 
		}

		<!--------------添加------------------------>
		var newwindow = new SimpleWindow();

		function showNew(){
			if(OperatorForm.CountryCode.value == ""){
				alert("<%=LangAction.langAction.getNoselect_country()%>");
				return false;
			}
			newwindow.Create('new_window','<%=LangPage.langPage.getWindowsTitle("operator_add")%>',500,91,newHTML);
			newwindow.Show();
			NewOperator.CountryCode.value = OperatorForm.CountryCode.value;
		}
	
		function newCancel(){
			newwindow.Close();
		}
		function newSubmit(){
			if(NewOperator.OpCode.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=oper.getAliasByFiled("OpCode")%>");
				NewOperator.OpCode.focus();
				return false;
			}
			if(NewOperator.Operator.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=oper.getAliasByFiled("Operator")%>");
				NewOperator.Operator.focus();
				return false;
			}
			sendP("../AddOperator.do",getP(NewOperator),newResult);
			openPage('operatorlist',listIndex.get('operatorlist'));
		}
		function newResult(cartXML){
			newwindow.Close();
			//openPage('operatorlist',listIndex.get('operatorlist'));
		}

		<!--------------修改------------------------>
		var updatewindow = new SimpleWindow();
		function showUpdate(){
			if(OperatorForm.CountryCode.value == ""){
				alert("<%=LangAction.langAction.getNoselect_operator()%>");
				return;
			}
			updatewindow.Create('update_window','<%=LangPage.langPage.getWindowsTitle("operator_update")%>',550,91,updateHTML);
			updatewindow.Show();
			sendG("../GetOperatorInfo.do?OpCode="+listCurrentKey.get('operatorlist'),getUpdate);
		}
		function updateCancel(){
			updatewindow.Close();
		}
		function getUpdate(cartXML){
			//UpdateOperator.reset();
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
				if(name == "<%=oper.getAliasByFiled("OpCode")%>") UpdateOperator.OpCode.value = value;
				else if(name == "<%=oper.getAliasByFiled("Operator")%>") UpdateOperator.Operator.value = value;
			}
		}
		function updateSubmit(){
			if(UpdateOperator.Operator.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=oper.getAliasByFiled("Operator")%>");
				UpdateOperator.Operator.focus();
				return false;
			}
			
			sendP("../UpdateOperator.do",getP(UpdateOperator),updateResult);
			openPage('operatorlist',listIndex.get('operatorlist'));
		}
		function updateResult(){
			updatewindow.Close();
			openPage('operatorlist',listIndex.get('operatorlist'));
		}
		
		<!--------------删除消息----------------------->
		function deleteObj(){
			if(listCurrentKey.get('operatorlist')==""){
				alert("<%=LangAction.langAction.getNoselect_operator()%>");
				return;
			}else{
				if(confirm("<%=LangPage.langPage.getDelete_confirm()%>")){
					sendG("../DeleteOperator.do?OpCode="+listCurrentKey.get('operatorlist'),deleteResult);
				}
			}
		}
		function deleteResult(){
			openPage('operatorlist',listIndex.get('operatorlist'));
		}
		<!-----------------页面初始化--------------------->
		var newHTML = "";
		var updateHTML = "";
	
		function init(){
			newHTML = document.all["tb_new"].innerHTML;
			document.all["tb_new"].innerHTML = "";
			updateHTML = document.all["tb_update"].innerHTML;
			document.all["tb_update"].innerHTML = "";
            
			showCountry();
	          
			initList();
			//openPage('operatorlist','1');
		}

		function initList(){
			listIndex.put('operatorlist','1');
			//listPageURL.put('operatorlist','../Getoperatorlist.do?index=#index#');
			//listDetailURL.put('operatorlist','../GetFeeInfo.do?SPId=#id#');
			listCurrentId.put('operatorlist','');
			listCurrentKey.put('operatorlist','');
			listDetailWidth.put('operatorlist','300');
			listDetailHeight.put('operatorlist','320');
			listListXSL.put('operatorlist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			//listDetailXSL.put('operatorlist','../xsl/jwdf_sdetail.xsl');
		}
		
		<!------------------------------------------------------------>
</script>
</head>

<body onload="init();">
	<!-- 页面标题 -->
	<table class="table_pagetitle" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("operator_inter")%></td>
	</tr>
	</table>
	
	<!-- 查询条件 -->
	<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr><td height="5"></td></tr>
	<tr>
		<td valign="middle" style="font-size:9pt;color:#4796ee;">
			<form method="POST" name="OperatorForm" class="editform">
		<b><%=LangPage.langPage.getSearch("search_country")%></b><select name="CountryCode" onchange="getSpByCountry();"><option selected value=""><%=LangPage.langPage.getSearch("search_pleaseselect")%></option></select>
				</form>
		</td>
	</tr>
	</table>

	<!-- 操作按钮 -->
	<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_buttonbar" valign="middle">
			<a href="#" onclick="showNew();"><img src="../<%=LangPage.langPage.getButton_img_path()%>add_001.gif" border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a href="#" onclick="showUpdate();"><img src="../<%=LangPage.langPage.getButton_img_path()%>update_001.gif" border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a href="#" onclick="deleteObj();"><img src="../<%=LangPage.langPage.getButton_img_path()%>delete_001.gif" border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
		</td>
	</tr>
	</table>

	<!-- 列表显示区域 -->
	<div align="center" id="operatorlist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
	</div>

	<!-- 添加表单 -->
	<div id="tb_new" class="datainfo">
		<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
		<form method="POST" name="NewOperator" class="editform">
			<input type="hidden" name="CountryCode" value="">
			<tr>
				<td class="td_edittitle" width="25%"><%=oper.getAliasByFiled("OpCode")%></td>
				<td class="td_editcontent" width="75%"><input class="input_edit" style="width:100%;" type="text" name="OpCode"></td>
			</tr>
			<tr>
				<td class="td_edittitle"><%=oper.getAliasByFiled("Operator")%></td>
				<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="Operator"></td>
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
		<form method="POST" name="UpdateOperator" class="editform">
			<input type="hidden" name="OpId" value="">
		<tr>
				<td class="td_edittitle" width="25%"><%=oper.getAliasByFiled("OpCode")%></td>
				<td class="td_editcontent" width="75%"><input class="input_edit" readonly style="width:100%;" type="text" name="OpCode"></td>
			</tr>
			<tr>
				<td class="td_edittitle"><%=oper.getAliasByFiled("Operator")%></td>
				<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="Operator"></td>
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
