<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangAction"%>
<%@ page import="com.language.langdata.LangDBTable"%>
<%@ page import="com.vogins.sps.db.internation.SmsCa"%>
<%@ page import="com.vogins.sps.db.publicinfo.Province"%>
<%
	SmsCa sms = new SmsCa();
	Province pro = new Province();
%>
<html>
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<TITLE><%=LangPage.langPage.getPageTitle("smsca_inter")%></TITLE>
	<meta http-equiv="Pragma" content="no-cache">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_main.css">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_swin.css">
	<SCRIPT language="JavaScript" type="text/javascript" src="../js/jwdf_util.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../js/jwdf_xml.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../js/jwdf_view.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../js/jwdf_swin.js"></SCRIPT>
	<script language=javascript><!--
		<!--------------------------------显示运营商下拉列表----------------------------------->
		function showCountry(){
		    sendG("../GetAllOperator.do",getCounResult);
		}
		function getCounResult(cartXML){
		 	var cart = cartXML.getElementsByTagName("result")[0];
			var list = cart.getElementsByTagName("list")[0];
			var rows = list.getElementsByTagName("row");
			OperatorForm.OpId.options.length = 0;
			OperatorForm.OpId.add(document.createElement("OPTION"));
			OperatorForm.OpId.options[0].text="<%=LangPage.langPage.getSearch("search_pleaseselect")%>";
			OperatorForm.OpId.options[0].value="";
			for(var i=0;i<rows.length;i++){
				var key = rows[i].getElementsByTagName("key")[0].firstChild.nodeValue;
				var field = rows[i].getElementsByTagName("field")[0].firstChild.nodeValue;
				OperatorForm.OpId.add(document.createElement("OPTION"));
				OperatorForm.OpId.options[i+1].text=field;
			    OperatorForm.OpId.options[i+1].value=key;
		 
			}
		}
		function GetCAByOperator(){
		    listPageURL.put('smscalist','../GetCAByOperator.do?OpId='+OperatorForm.OpId.value+'&index=#index#');
			openPage('smscalist','1');
		 
		}

		<!--------------------------------显示添加菜单省份下拉列表----------------------------------->
		function showProvinceAdd(){
		    sendG("../GetAllProvince.do",getProvinceResultAdd);
		}
		function getProvinceResultAdd(cartXML){
		 	var cart = cartXML.getElementsByTagName("result")[0];
			var list = cart.getElementsByTagName("list")[0];
			var rows = list.getElementsByTagName("row");
			NewSmsCA.ProId.options.length = 0;
			NewSmsCA.ProId.add(document.createElement("OPTION"));
			NewSmsCA.ProId.options[0].text="<%=LangPage.langPage.getSearch("search_pleaseselect")%>";
			NewSmsCA.ProId.options[0].value="";
			for(var i=0;i<rows.length;i++){
				var key = rows[i].getElementsByTagName("key")[0].firstChild.nodeValue;
				var field = rows[i].getElementsByTagName("field")[0].firstChild.nodeValue;
				NewSmsCA.ProId.add(document.createElement("OPTION"));
				NewSmsCA.ProId.options[i+1].text=field;
				NewSmsCA.ProId.options[i+1].value=key;
		 
			}
		}

		<!--------------------------------显示修改菜单省份下拉列表----------------------------------->
		function showProvinceUpdate(){
		    sendG("../GetAllProvince.do",getProvinceResult);
		}
		function getProvinceResult(cartXML){
		 	var cart = cartXML.getElementsByTagName("result")[0];
			var list = cart.getElementsByTagName("list")[0];
			var rows = list.getElementsByTagName("row");
			UpdateSmsCa.ProId.options.length = 0;
			UpdateSmsCa.ProId.add(document.createElement("OPTION"));
			UpdateSmsCa.ProId.options[0].text="<%=LangPage.langPage.getSearch("search_pleaseselect")%>";
			UpdateSmsCa.ProId.options[0].value="";
			for(var i=0;i<rows.length;i++){
				var key = rows[i].getElementsByTagName("key")[0].firstChild.nodeValue;
				var field = rows[i].getElementsByTagName("field")[0].firstChild.nodeValue;
				UpdateSmsCa.ProId.add(document.createElement("OPTION"));
				UpdateSmsCa.ProId.options[i+1].text=field;
				UpdateSmsCa.ProId.options[i+1].value=key;
			}
		}
		<!--------------添加------------------------>
		var newwindow = new SimpleWindow();

		function showNew(){
			if(OperatorForm.OpId.value == ""){
				alert("<%=LangAction.langAction.getNoselect_operator()%>");
				return false;
			}
			newwindow.Create('new_window','<%=LangPage.langPage.getWindowsTitle("smsca_add")%>',500,114,newHTML);
			newwindow.Show();
			
			showProvinceAdd();

			NewSmsCA.OpId.value = OperatorForm.OpId.value;
		}
	
		function newCancel(){
			newwindow.Close();
		}
		function newSubmit(){
			if(NewSmsCA.ProId.value ==""){
				NewSmsCA.ProId.focus();
				alert("<%=LangAction.langAction.getNoselect_province()%>");
				return;
			}
			if(NewSmsCA.SmsCA.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=sms.getAliasByFiled("SmsCA")%>");
				NewSmsCA.SmsCA.focus();
				return false;
			}
			sendP("../AddSmsCA.do",getP(NewSmsCA),newResult);
			openPage('smscalist',listIndex.get('smscalist'));
		}
		function newResult(){
			newwindow.Close();
			openPage('smscalist',listIndex.get('smscalist'));
		}

		<!--------------修改------------------------>
		var updatewindow = new SimpleWindow();
		function showUpdate(){
			if(listCurrentKey.get('smscalist')==""){
				alert("<%=LangAction.langAction.getNoselect_smsca()%>");
				return;
			} else{
				updatewindow.Create('update_window','<%=LangPage.langPage.getWindowsTitle("smsca_update")%>',500,114,updateHTML);
				updatewindow.Show();
				sendG("../GetSmsCaInfo.do?CAId="+listCurrentKey.get('smscalist'),getUpdate);
				showProvinceUpdate();
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
			var upothertable = document.getElementById("Upothertable");
			var upviewType = document.getElementById("UpviewTable");
			for(i=0;i<fields.length;i++){
				var name = fields[i].getElementsByTagName("name")[0].firstChild.nodeValue;
				var value = "";
				if(fields[i].getElementsByTagName("value")[0].firstChild != null){
					value = fields[i].getElementsByTagName("value")[0].firstChild.nodeValue;
				}
				if(name == "<%=sms.getAliasByFiled("CAId")%>") UpdateSmsCa.CAId.value = value;
				else if(name == "<%=sms.getAliasByFiled("OpId")%>") UpdateSmsCa.OpId.value = value;
				else if(name == "<%=sms.getAliasByFiled("ProId")%>") UpdateSmsCa.ProId.value = value;
				else if(name == "<%=sms.getAliasByFiled("SmsCA")%>") UpdateSmsCa.SmsCA.value = value;
			}
		}
		function updateSubmit(){
			if(UpdateSmsCa.ProId.value ==""){
				UpdateSmsCa.ProId.focus();
				alert("<%=LangAction.langAction.getNoselect_province()%>");
				return;
			}
			if(UpdateSmsCa.SmsCA.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=sms.getAliasByFiled("SmsCA")%>");
				UpdateSmsCa.SmsCA.focus();
				return;
			}
			
			sendP("../UpdateSmsCa.do",getP(UpdateSmsCa),updateResult);
			openPage('smscalist',listIndex.get('smscalist'));
		}
		function updateResult(){
			updatewindow.Close();
			openPage('smscalist',listIndex.get('smscalist'));
		}
		
		<!--------------删除消息----------------------->
		function deleteObj(){
			if(listCurrentKey.get('smscalist')==""){
				alert("<%=LangAction.langAction.getNoselect_smsca()%>");
				return;
			}else{
				if(confirm("<%=LangPage.langPage.getDelete_confirm()%>")){
					sendG("../DeleteSmsCa.do?CAId="+listCurrentKey.get('smscalist'),deleteResult);
				}
			}
		}
		function deleteResult(){
			openPage('smscalist',listIndex.get('smscalist'));
		}

		<!------------------显示城市选择窗口---------------------------->
		var sel_city = "";
		var sel_cityid = "";
		var cityFrom = "1";
		var citywindow = new SimpleWindow();
		var isInit = false;
		
		function showCity(from){
			cityFrom = from;
			showCityList(cityFrom);
			if(isInit){
				citywindow.Create('city_window','<%=LangPage.langPage.getWindowsTitle("fee_selectprovince")%>',200,250,cityHTML);
				citywindow.Show();
			}
			isInit = false;
			sel_city = "";
			sel_cityid = "";
		}
		function showCityList(cityFrom){
			if(cityFrom == "1"){
				if(NewSmsCA.ProId.value == ""){
					alert("<%=LangAction.langAction.getNoselect_province()%>");
					return;
				}
				var provinceid = "";
				provinceid = NewSmsCA.ProId.value;
				sendG("../GetCityByProId.do?ProvinceId="+provinceid,getCityResult);
				isInit = true;
			}else{
				if(UpdateSmsCa.ProId.value == ""){
					alert("<%=LangAction.langAction.getNoselect_province()%>");
					return;
				}
				var provinceid = "";
				provinceid = UpdateSmsCa.ProId.value;
				sendG("../GetCityByProId.do?ProvinceId="+provinceid,getCityResult);
				isInit = true;
			}
		}
		function getCityResult(cartXML){
			var xsl = loadXSL("../xsl/checklist_1.xsl");
			document.all["citylist"].innerHTML = cartXML.transformNode(xsl);
			if(cityFrom == "2"){
				sel_city = UpdateSmsCa.City.value;
				sel_cityid = UpdateSmsCa.CityId.value;
				selectedCheck();
			}
		}
		
		//修改时，设置已经选择的城市
		function selectedCheck(){
			var cityId = UpdateSmsCa.CityId.value;
			var from = cityId.indexOf(";");
			var to = 0;
			if(from>=0 && from!=cityId.length-1) to = cityId.indexOf(";",from+1);
			while (to > 0){
				var temp = cityId.substring(from+1, to);
				if(temp != ""){
					document.all["chk_"+temp].checked = true;
				}
				from = to;
				if(from!=cityId.length-1) to = cityId.indexOf(";",from+1);
				else to = -1;
			}
		}

		//选择城市

		function clickCheck(id,name){
			if(document.all["chk_"+id].checked){
				if(sel_city.indexOf(";"+name+";")<0){
					if(sel_city == "") sel_city = ";"+name+";";
					else sel_city = sel_city+name+";";
				}
				if(sel_cityid.indexOf(";"+id+";")<0){
					if(sel_cityid == "") sel_cityid = ";"+id+";";
					else sel_cityid = sel_cityid+id+";";
				}
			}else{
				if(sel_city.indexOf(";"+name+";")>=0){
					sel_city = sel_city.replace(";"+name+";",";");
				}
				if(sel_cityid.indexOf(";"+id+";")>=0){
					sel_cityid = sel_cityid.replace(";"+id+";",";");
				}
			}
		}

		function doSelect2(){
			if(cityFrom == "1"){
				NewSmsCA.City.value = sel_city;
				NewSmsCA.CityId.value = sel_cityid;
			}
			else if(cityFrom == "2"){
				UpdateSmsCa.City.value = sel_city;
				UpdateSmsCa.CityId.value = sel_cityid;
			}
			citywindow.Close();
		}
		<!------------------------------------------------------------->
		
		<!-----------------页面初始化--------------------->
		var newHTML = "";
		var updateHTML = "";
		var cityHTML = "";
	
		function init(){
			newHTML = document.all["tb_new"].innerHTML;
			document.all["tb_new"].innerHTML = "";
			updateHTML = document.all["tb_update"].innerHTML;
			document.all["tb_update"].innerHTML = "";
			cityHTML =document.all["select_city"].innerHTML;
			document.all["select_city"].innerHTML = "";
            
			showCountry();
	          
			initList();
			//openPage('smscalist','1');
		}

		function initList(){
			listIndex.put('smscalist','1');
			//listPageURL.put('smscalist','../Getsmscalist.do?index=#index#');
			listDetailURL.put('smscalist','../GetSmsCaInfo.do?CAId=#id#');
			listCurrentId.put('smscalist','');
			listCurrentKey.put('smscalist','');
			listDetailWidth.put('smscalist','300');
			listDetailHeight.put('smscalist','320');
			listListXSL.put('smscalist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('smscalist','../xsl/jwdf_sdetail.xsl');
		}
		
		<!------------------------------------------------------------>
</script>
</head>

<body onload="init();">
	<!-- 页面标题 -->
	<table class="table_pagetitle" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("smsca_inter")%></td>
	</tr>
	</table>
	
	<!-- 显示运营商下拉列表 -->
	<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr><td height="5"></td></tr>
	<tr>
		<td valign="middle" style="font-size:9pt;color:#4796ee;">
			<form method="POST" name="OperatorForm" class="editform">
		<b><%=LangPage.langPage.getSearch("search_operator")%></b><select name="OpId" onchange="GetCAByOperator();"><option selected value=""><%=LangPage.langPage.getSearch("search_pleaseselect")%></option></select>
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
	<div align="center" id="smscalist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
	</div>

	<!-- 添加表单 -->
	<div id="tb_new" class="datainfo">
		
		<!-- 显示省份下拉列表 -->

		<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
		<form method="POST" name="NewSmsCA" class="editform">
			<tr>
				<td class="td_edittitle" width="25%"><%=pro.getAliasByFiled("ProvinceName")%></td>
				<td algin="left" class="td_editcontent">
					<select name="ProId">
						<option selected value=""><%=LangPage.langPage.getSearch("search_pleaseselect")%></option>
					</select>
				</td>
			</tr>
			<tr>
				<td class="td_edittitle" width="80"><%=sms.getAliasByFiled("AreaName")%></td>
				<td class="td_editcontent" width="200">
					<input class="input_edit" type="text" name="City" readonly>
					<input type="hidden" name="CityId">
					<a href="#" onclick="showCity('1');"><img src="../<%=LangPage.langPage.getButton_img_path()%>select_001.gif"   border="0" align="top" vspace="1" /></a>
				</td>
			</tr>
			<input type="hidden" name="OpId" value="">
			<tr>
				<td class="td_edittitle" width="25%"><%=sms.getAliasByFiled("SmsCA")%></td>
				<td class="td_editcontent" width="75%"><input class="input_edit" style="width:100%;" type="text" name="SmsCA"></td>
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
		<form method="POST" name="UpdateSmsCa" class="editform">
			<input type="hidden" name="CAId" value="">
			<input type="hidden" name="OpId" value="">
			<tr>
				<td class="td_edittitle" width="25%"><%=sms.getAliasByFiled("ProvinceName")%></td>
				<td algin="left" class="td_editcontent">
					<select name="ProId">
						<option selected value="ProId"><%=LangPage.langPage.getSearch("search_pleaseselect")%></option>
					</select>
				</td>
			</tr>
			<tr>
				<td class="td_edittitle" width="80"><%=sms.getAliasByFiled("AreaName")%></td>
				<td class="td_editcontent" width="200">
					<input class="input_edit" type="text" name="City" readonly>
					<input type="hidden" name="CityId">
					<a href="#" onclick="showCity('2');"><img src="../<%=LangPage.langPage.getButton_img_path()%>select_001.gif"   border="0" align="top" vspace="1" /></a>
				</td>
			</tr>
			<tr>
				<td class="td_edittitle" width="25%"><%=sms.getAliasByFiled("SmsCA")%></td>
				<td class="td_editcontent" width="75%"><input class="input_edit" style="width:100%;" type="text" name="SmsCA"></td>
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

	<!-- 选择适配城市窗口 -->
	<div id="select_city" class="datainfo">
		<div id="citylist"
			style="width:100%;height:150; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		</div>
		<br>
		<center>
			<a href="#" onclick="doSelect2();"><img src="../<%=LangPage.langPage.getButton_img_path()%>select_001.gif"  border="0" align="top" vspace="1" /></a>
		</center>
	</div>
	
	<div id="tb_fee" class="datainfo">
		<div align="center" id="feelist"
			style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		</div>
	</div>

</body>

</html>
