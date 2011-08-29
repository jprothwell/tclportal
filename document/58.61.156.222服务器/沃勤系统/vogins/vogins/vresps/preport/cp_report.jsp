<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangAction"%>
<%@ page import="com.language.langdata.LangDBTable"%>
<html>

<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<TITLE><%=LangPage.langPage.getPageTitle("cp_report")%></TITLE>
	<meta http-equiv="Pragma" content="no-cache">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_main.css">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_swin.css">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_cal.css">
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_cal.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../js/jwdf_util.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_xml.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_view.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_swin.js"></SCRIPT>

	<script language=javascript>
	<!-----------------------显示汇总结果--------------------------->
	function showReport(){
		if(SearchForm.stattype.value=="1"){
			listPageURL.put('reportlist','../CPReport_Date.do?'+getP(SearchForm)+'&index=#index#');
		}else if(SearchForm.stattype.value=="2"){
			listPageURL.put('reportlist','../CPReport_App.do?'+getP(SearchForm)+'&index=#index#');
		}
		openPage('reportlist','1');
	}
	

<!------------------------------------------------------------->
	
<!------------------根据所选CP，更新产品下拉框--------------------------->
	function showApp(){
		SearchForm.SelApp.options.length = 0;
		SearchForm.SelApp.add(document.createElement("OPTION"));
		SearchForm.SelApp.options[0].text="<%=LangPage.langPage.getSelect("status_all")%>";
		SearchForm.SelApp.options[0].value="0";
		sendG("../GetCPApplication.do",getCPResult);
	}
	function getCPResult(cartXML){
		var cart = cartXML.getElementsByTagName("result")[0];
		var list = cart.getElementsByTagName("list")[0];
		var rows = list.getElementsByTagName("row");
		SearchForm.SelApp.options.length = 0;
		SearchForm.SelApp.add(document.createElement("OPTION"));
		SearchForm.SelApp.options[0].text="<%=LangPage.langPage.getSelect("status_all")%>";
		SearchForm.SelApp.options[0].value="0";
		for(var i=0;i<rows.length;i++){
			var key = rows[i].getElementsByTagName("key")[0].firstChild.nodeValue;
			var field = rows[i].getElementsByTagName("field")[0].firstChild.nodeValue;
			SearchForm.SelApp.add(document.createElement("OPTION"));
			SearchForm.SelApp.options[i+1].text=field;
			SearchForm.SelApp.options[i+1].value=key;
		}
	}
<!------------------------------------------------------------->

   
<!----------------------页面初始化----------------------->
		function init(){
			showApp();
			
			initList();
		}

		function initList(){
			listIndex.put('reportlist','1');
			listPageURL.put('reportlist','');
			listDetailURL.put('reportlist','');
			listCurrentId.put('reportlist','');
			listCurrentKey.put('reportlist','');
			listDetailWidth.put('reportlist','400');
			listDetailHeight.put('reportlist','300');
			listListXSL.put('reportlist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('reportlist','');
		}
<!------------------------------------------------------------->
	</script>
</head>

<body onload="init();">
	<!-- 页面标题 -->
	<table class="table_pagetitle" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("cp_report")%></td>
	</tr>
	</table>

	<!-- 查询条件 -->
	<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr><td height="5"></td></tr>
	<tr>
		<td valign="middle" style="font-size:9pt;color:#4796ee;">
			<form method="POST" name="SearchForm" class="editform">
			<b><%=LangPage.langPage.getSearch("search_conditions")%></b><%=LangPage.langPage.getSearch("search_type")%><select name="stattype"><option value="1"><%=LangPage.langPage.getSearch("search_bydate")%></option><option value="2"><%=LangPage.langPage.getSearch("search_byapp")%></option></select>&nbsp;&nbsp;<%=LangPage.langPage.getWindowsTitle("app_selectapp")%><select name="SelApp"><option value="0"><%=LangPage.langPage.getSelect("status_all")%></option></select><br>
			<b>　　　　　</b><%=LangPage.langPage.getSearch("search_startdate")%><input class="input_edit" type="text" name="StartDate" style="width:80;" value="" readonly>&nbsp;<a href="#" onclick="LtCalendar.create('StartDate',68,165);"><img src="../<%=LangPage.langPage.getButton_img_path()%>point_001.gif"   border="0" align="top" vspace="1" /></a>
			&nbsp;&nbsp;<%=LangPage.langPage.getSearch("search_enddate")%><input class="input_edit" type="text" name="EndDate" style="width:80;" value="" readonly>&nbsp;<a href="#" onclick="LtCalendar.create('EndDate',68,345);"><img src="../<%=LangPage.langPage.getButton_img_path()%>point_001.gif"   border="0" align="top" vspace="1" /></a>
			&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href="#" onclick="showReport();"><img src="../<%=LangPage.langPage.getButton_img_path()%>search_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			</form>
		</td>
	</tr>
	<tr><td height="5"></td></tr>
	</table>

	<!-- 查询结果显示区域 -->
	<center>
	<div align="center" id="reportlist" style="width:90%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
	</div>
	</center>
</body>

</html>
