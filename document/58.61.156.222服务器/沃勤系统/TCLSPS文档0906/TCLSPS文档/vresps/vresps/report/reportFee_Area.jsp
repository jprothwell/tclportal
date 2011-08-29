<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangAction"%>

<%@ page import="java.text.SimpleDateFormat"%>
<%@ page import="java.util.Calendar"%>
<%@ page import="java.util.GregorianCalendar"%>
<%@ page import="java.util.Date"%>
<%
	Calendar calendar  =   new  GregorianCalendar();
	calendar.set( Calendar.DATE,  1 );
%>
<html>

<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<TITLE><%=LangPage.langPage.getPageTitle("reportFee_Area")%></TITLE>
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
	<!--------------------------------显示添加菜单省份下拉列表----------------------------------->
	function showProvinceAdd(){
	    sendG("../GetAllProvince.do",getProvinceResultAdd);
	}
	function getProvinceResultAdd(cartXML){
	 	var cart = cartXML.getElementsByTagName("result")[0];
		var list = cart.getElementsByTagName("list")[0];
		var rows = list.getElementsByTagName("row");
		SearchForm.ProId.options.length = 0;
		SearchForm.ProId.add(document.createElement("OPTION"));
		SearchForm.ProId.options[0].text="<%=LangPage.langPage.getSearch("search_pleaseselect")%>";
		SearchForm.ProId.options[0].value="";
		for(var i=0;i<rows.length;i++){
			var key = rows[i].getElementsByTagName("key")[0].firstChild.nodeValue;
			var field = rows[i].getElementsByTagName("field")[0].firstChild.nodeValue;
			SearchForm.ProId.add(document.createElement("OPTION"));
			SearchForm.ProId.options[i+1].text=field;
			SearchForm.ProId.options[i+1].value=key;
	 
		}
	}

	<!----------------------显示搜索结果--------------------------->
	 	function showReport(){
	 		if(SearchForm.ProId.value == "" || SearchForm.ProId.value == null){
	 			alert("请选择省份!");
	 			return;
			}
			if(SearchForm.reporttype.value == "3"){
				listPageURL.put('reportlist','../reprot_ProFee.do?'+getP(SearchForm)+'&index=#index#');
				openPage('reportlist','1');
			}
		}
	<!----------------------页面初始化----------------------->
		var reportdetailHTML = "";
		function init(){
			showProvinceAdd();
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
		<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("reportFee_Area")%></td>
	</tr>
	</table>

	<!-- 查询条件 -->
	<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr><td height="5"></td></tr>
	<tr>
		<td valign="middle" style="font-size:9pt;color:#4796ee;">
			<form method="POST" name="SearchForm" class="editform">
				<input type="hidden" name="reporttype" value="3"/>
				<b><%=LangPage.langPage.getSearch("search_conditions")%></b></br>
				省&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;份:
				<select name="ProId">
						<option selected value=""><%=LangPage.langPage.getSearch("search_pleaseselect")%></option>
				</select></br>
				<%=LangPage.langPage.getSearch("search_startdate")%><input class="input_edit" type="text" name="StartDate" style="width:80;" value="<%=new SimpleDateFormat("yyyy-MM-dd").format(calendar.getTime()) %>" readonly>&nbsp;<a href="#" onclick="LtCalendar.create('StartDate',68,165);"><img src="../<%=LangPage.langPage.getButton_img_path()%>point_001.gif"   border="0" align="top" vspace="1" /></a>&nbsp;
				<%=LangPage.langPage.getSearch("search_enddate")%>&nbsp;<input class="input_edit" type="text" name="EndDate" style="width:80;" value="<%=new SimpleDateFormat("yyyy-MM-dd").format(new Date()) %>" readonly>&nbsp;<a href="#" onclick="LtCalendar.create('EndDate',68,345);"><img src="../<%=LangPage.langPage.getButton_img_path()%>point_001.gif"   border="0" align="top" vspace="1" /></a><br>
				<a href="#" onclick="showReport();"><img src="../<%=LangPage.langPage.getButton_img_path()%>search_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
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
	
	<div id="tb_reportdetail" class="datainfo">
		<div align="center" id="reportdetaillist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		</div>
	</div>	
</body>

</html>
