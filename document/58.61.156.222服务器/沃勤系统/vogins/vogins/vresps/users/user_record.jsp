<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangDBTable"%>
<%@ page import="com.vogins.sps.db.touse.*"%>
<%
 Touse touse = new Touse();
%>
<html>

<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<TITLE><%=LangPage.langPage.getPageTitle("user_record")%></TITLE>
	<meta http-equiv="Pragma" content="no-cache">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_main.css">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_swin.css">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_cal.css">
	<SCRIPT language="JavaScript" type="text/javascript" src="../js/jwdf_util.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_xml.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_view.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_swin.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_cal.js"></SCRIPT>
	<script language=javascript>
<!----------------读取指定用户的使用记录----------------------->
		function getPara(){
			var para = "";
			para = "Mobile=" + document.all["Mobile0"].value;
			para = para + "&SubscriberId=" + document.all["SubscriberId0"].value;
			para = para + "&StartDate=" + document.all["StartDate"].value;
			para = para + "&EndDate=" + document.all["EndDate"].value;
			return para;
		}
		function showLog(){
			if(document.all["Mobile0"].value == "" && document.all["SubscriberId0"].value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=touse.getAliasByFiled("Mobile")%>");
				//alert("请输入用户手机号码或用户编号！");
				return;
				
			}else{
		
				listPageURL.put('loglist','../GetUserRecord.do?'+getPara()+'&index=#index#');
				openPage('loglist','1');
				showTouse();
			}
		}
<!------------------------------------------------------------->
<!----------------读取用户投诉记录----------------------->
		function getPara0(){
			var para = "";
			para = "Mobile0=" + document.all["Mobile0"].value;
			para = para + "&SubscriberId0=" + document.all["SubscriberId0"]	.value;
			para = para + "&StartDate=" + document.all["StartDate"].value;
			para = para + "&EndDate=" + document.all["EndDate"].value;
			return para;
		}
		function showTouse(){
			listPageURL.put('touselist','../SearchTouse.do?'+getPara0()+'&index=#index#');
			openPage('touselist','1');
		}
<!------------------------------------------------------------->
<!------------------------------------------------------------->
		
<!---------------添加一个新投诉------------------------->
		var newwindow = new SimpleWindow();
		function showNew(){
			if(document.all["Mobile0"].value=="" && document.all["SubscriberId0"].value==""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=touse.getAliasByFiled("Mobile")%>");
				return;
			}else{
				sendG("../GetSubscriber.do?"+getPara(),getUpdate);
				newwindow.Create('new_window','<%=LangPage.langPage.getWindowsTitle("mobile_addtouse")%>',280,305,newHTML);
				newwindow.Show();
			}
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
				if(name == "<%=touse.getAliasByFiled("SubscriberId")%>") NewTouse.SubscriberId.value = value;
				else if(name == "<%=touse.getAliasByFiled("Mobile")%>") NewTouse.Mobile.value = value;
				else if(name == "<%=touse.getAliasByFiled("MobileId")%>") NewTouse.MobileId.value = value;
				else if(name == "<%=touse.getAliasByFiled("MobileName")%>") NewTouse.MobileName.value = value;
			}
		}
		function newCancel(){
			newwindow.Close();
		}
		function newSubmit(){
			if(NewTouse.Mobile.value == ""){
			  alert("<%=LangPage.langPage.getPlease_input()%><%=touse.getAliasByFiled("Mobile")%>");
				NewTouse.Mobile.focus();
				return false;
			}
			sendP("../AddTouse.do",getP(NewTouse),newResult);
		}
		function newResult(){
			openPage('touselist',listIndex.get('touselist'));
			newwindow.Close();
		}
<!------------------------------------------------------------->

<!------------------页面初始化---------------------->
		var newHTML = "";
		function init(){
			newHTML = document.all["tb_new"].innerHTML;
			document.all["tb_new"].innerHTML = "";

			initList();
		}

		function initList(){
			listIndex.put('loglist','1');
			listPageURL.put('loglist','');
			listDetailURL.put('loglist','');
			listCurrentId.put('loglist','');
			listCurrentKey.put('loglist','');
			listDetailWidth.put('loglist','300');
			listDetailHeight.put('loglist','220');
			listListXSL.put('loglist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('loglist','');

			listIndex.put('touselist','1');
			listPageURL.put('touselist','');
			listDetailURL.put('touselist','../GetTouseInfo.do?TouseId=#id#');
			listCurrentId.put('touselist','');
			listCurrentKey.put('touselist','');
			listDetailWidth.put('touselist','400');
			listDetailHeight.put('touselist','350');
			listListXSL.put('touselist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('touselist','../xsl/jwdf_sdetail.xsl');

		}
<!------------------------------------------------------------->
	</script>
</head>

<body onload="init();">
	<!-- 页面标题 -->
	<table class="table_pagetitle" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("user_record")%></td>
	</tr>
	</table>
	
	<!-- 查询条件区域 -->
	<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr><td height="5"></td></tr>
	<tr>
		<td valign="middle" style="font-size:9pt;color:#4796ee;">
			<b><%=LangPage.langPage.getSearch("search_conditions")%></b><%=LangPage.langPage.getSearch("search_mobilenum")%><input class="input_edit" type="text" name="Mobile0" style="width:80;" value="">
			&nbsp;&nbsp;<%=LangPage.langPage.getSearch("search_userid")%><input class="input_edit" type="text" name="SubscriberId0" style="width:80;" value=""><br>
			<b>　　　　　</b><%=LangPage.langPage.getSearch("search_startdate")%><input class="input_edit" type="text" name="StartDate" style="width:80;" value="">&nbsp;<a href="#" onclick="LtCalendar.create('StartDate',68,165);"><img src="../<%=LangPage.langPage.getButton_img_path()%>point_001.gif"   border="0" align="top" vspace="1" /></a>
			&nbsp;&nbsp;<%=LangPage.langPage.getSearch("search_enddate")%><input class="input_edit" type="text" name="EndDate" style="width:80;" value="">&nbsp;<a href="#" onclick="LtCalendar.create('EndDate',68,345);"><img src="../<%=LangPage.langPage.getButton_img_path()%>point_001.gif"   border="0" align="top" vspace="1" /></a>
			&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href="#" onclick="showLog();"><img src="../<%=LangPage.langPage.getButton_img_path()%>search_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
		</td>
	</tr>
	<tr><td height="5"></td></tr>
	</table>

	<center>
	<!-- 使用记录显示区域 -->
	<div align="center" style="width:90%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		<fieldset class="fieldset_edit">
		<legend class="legend_edit"><b><%=LangPage.langPage.getSearch("touse_userecord")%></b></legend>
		<div id="loglist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		</div>
		</fieldset>
	</div>
	
	<br>
	<!-- 投诉记录显示区域 -->
	<div align="center" style="width:90%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		<fieldset class="fieldset_edit">
		<legend class="legend_edit"><b><%=LangPage.langPage.getSearch("touse_touserecord")%></b></legend>
		<div id="touselist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		</div>
		</fieldset>
	</div>
	</center>
	
	<!-- 操作按钮 -->
	<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_buttonbar" valign="middle" style="padding-left:5;">
			<a href="#" onclick="showNew();"><img src="../<%=LangPage.langPage.getButton_img_path()%>addcomplaint_001.gif"   border="0" align="top" vspace="1" /></a>
		</td>
	</tr>
	</table>

	<!-- 添加投诉表单 -->
	<div align="center" id="tb_new" class="datainfo">
		<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
		<form method="POST" name="NewTouse" class="editform">
		<tr>
			<td class="td_edittitle" width="80"><%=touse.getAliasByFiled("SubscriberId")%></td>
			<td class="td_editcontent" width="200"><input class="input_edit" style="width:100%;" type="text" name="SubscriberId"></td>
		</tr>
		<tr>
			<td class="td_edittitle" width="80"><%=touse.getAliasByFiled("Mobile")%></td>
			<td class="td_editcontent" width="200"><input class="input_edit" style="width:100%;" type="text" name="Mobile"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=touse.getAliasByFiled("MobileName")%></td>
			<td class="td_editcontent">
				<input class="input_edit" style="width:100%;" type="text" name="MobileName" value="">
				<input type="hidden" name="MobileId" value="">
			</td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=touse.getAliasByFiled("AppName")%></td>
			<td class="td_editcontent">
				<input class="input_edit" style="width:100%;" type="text" name="AppName">
				<input type="hidden" name="AppId">
				<input type="hidden" name="AppPrice">
				<input type="hidden" name="FeeType">
				<input type="hidden" name="FeeValue">
			</td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=touse.getAliasByFiled("TouseContent")%></td>
			<td class="td_editcontent"><textarea class="input_textarea" name="TouseContent"></textarea></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=touse.getAliasByFiled("Solution")%></td>
			<td class="td_editcontent"><textarea class="input_textarea" name="Solution"></textarea></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=touse.getAliasByFiled("Compensation")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="Compensation"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=touse.getAliasByFiled("TouseStatus")%></td>
			<td class="td_editcontent">
				<input name="TouseStatus" type="radio" value="0" checked><%=LangPage.langPage.getSelect("status_continue") %>&nbsp;&nbsp;
				<input name="TouseStatus" type="radio" value="1"><%=LangPage.langPage.getSelect("status_complete")%></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=touse.getAliasByFiled("Remark")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="Remark"></td>
		</tr>
		</form>
		 <tr>
				<td class="td_editbutton" colspan="2">
					<a href="#" onclick="newSubmit();"><img src="../<%=LangPage.langPage.getButton_img_path()%>ok_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
					<a href="#" onclick="newCancel();"><img src="../<%=LangPage.langPage.getButton_img_path()%>cancel_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
				</td>
			</tr>
		</table>
	</div>	
</body>

</html>
