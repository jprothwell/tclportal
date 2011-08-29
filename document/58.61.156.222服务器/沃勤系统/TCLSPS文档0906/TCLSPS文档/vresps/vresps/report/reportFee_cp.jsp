<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangAction"%>
<%@ page import="com.language.langdata.LangDBTable"%>
<%@ page import="com.vogins.sps.db.app.CPPartner"%>
<%@ page import="com.vogins.sps.db.app.Application"%>

<%@ page import="java.text.SimpleDateFormat"%>
<%@ page import="java.util.Calendar"%>
<%@ page import="java.util.GregorianCalendar"%>
<%@ page import="java.util.Date"%>
<%
 	CPPartner cp = new CPPartner();
	Application app = new Application();
	
	Calendar calendar  =   new  GregorianCalendar();
	calendar.set( Calendar.DATE,  1 );
%>
<html>

<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<TITLE><%=LangPage.langPage.getPageTitle("reportFee_cp")%></TITLE>
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
	<!-----------------------隐藏按钮--------------------------->
	function showOptions(){
		var search_type = SearchForm.reporttype.value;
		if(search_type=="3"){
			selapptext.style.display = "none";
		}else if(search_type=="4"){
			selapptext.style.display = "";
		}
	}
		<!-----------------------显示汇总结果--------------------------->
		function showReport(){
		  	
			listPageURL.put('reportlist','../Report_CPFee.do?'+getP(SearchForm)+'&index=#index#');
			openPage('reportlist','1');
			document.all["reportdiv"].style.display = "";
		}

	
		//隐藏结果
		function clearall(){
				document.all["reportdiv"].style.display = "none";
		}
		<!------------------------------------------------------------->
		
		<!------------------选择CP---------------------------->
		var cur_cpid = "";
		var cpwindow = new SimpleWindow();
		function showCP(){
			SearchForm.SelAppText.value = "";
			SearchForm.SelApp.value = "";
			cpwindow.Create('sp_window','<%=LangPage.langPage.getWindowsTitle("cp_selectcp")%>',600,400,cpHTML);
			cpwindow.Show();
			listPageURL.put('cplist','../GetCPList.do?index=#index#');
			openPage('cplist','1');
		}
	
		function selectCP(){
			if(listCurrentKey.get('cplist') == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=cp.getAliasByFiled("CPName")%>");
				return;
			}else{
				sendG("../GetCPInfo.do?CPId="+listCurrentKey.get('cplist'),getCPDetail);
			}
		}
		
		function getCPDetail(cartXML){
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
				if(name == "<%=cp.getAliasByFiled("CPId")%>"){
					cur_cpid = value;
					SearchForm.SelCP.value = value;
				}
				if(name == "<%=cp.getAliasByFiled("CPName")%>"){
					SearchForm.SelCPText.value = value;
				}
			}
			cpwindow.Close();
		}	

		<!---------------------------根据CP选择产品---------------------------------->
		var cur_proid = "";
		var prowindow = new SimpleWindow();
		function showPro(){
			if(SearchForm.SelCP.value==""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=cp.getAliasByFiled("CPName")%>");
				SearchForm.SelCPText.focus();
				return false;
			}
			if(cur_cpid != ""){
				listPageURL.put('prolist','../GetAppListByCPId.do?CPId='+cur_cpid+'&index=#index#');
				prowindow.Create('pro_window','<%=LangPage.langPage.getWindowsTitle("app_selectapp")%>',600,400,proHTML);
				prowindow.Show();
				openPage('prolist','1');
			}
		}

		function selectPro(){
			if(listCurrentKey.get('prolist') == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=app.getAliasByFiled("AppName")%>");
				return;
			}else{
				sendG("../GetAppInfo.do?AppId="+listCurrentKey.get('prolist'),getSubDetail);
			}
		}

		function getSubDetail(cartXML){
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
				if(name == "<%=app.getAliasByFiled("AppId")%>"){
					cur_proid = value;
					SearchForm.SelApp.value = value;
				}
				if(name == "<%=app.getAliasByFiled("AppName")%>"){
					SearchForm.SelAppText.value = value;
				}
			}
			prowindow.Close();
		}
		
		<!------------------------------取详细信息------------------------------->
		var detailwindow = new SimpleWindow();
		function showReportDetail(date,name){
	
			SearchForm.Date.value = date;
			SearchForm.Name.value = name;
			SearchForm.Type.value = SearchForm.reporttype.value;
			detailwindow.Create('appversion_window','<%=LangPage.langPage.getWindowsTitle("cw_detail")%>',600,350,reportdetailHTML);
			detailwindow.Show();
			listPageURL.put('reportdetaillist','../Report_SpsDetail.do?'+getP(SearchForm)+'&index=#index#');
			openPage('reportdetaillist','1');
		}

		<!---------------------------CP查询列表---------------------------------->
		function searchCPByName(){
			listIndex.put('cplist','1');
			var cpName = SearchCPByName.value;
			listPageURL.put('cplist','../GetCPListByCP.do?CPName='+encodeURIComponent(cpName)+'&index=#index#');
			listDetailURL.put('cplist','');
			listCurrentId.put('cplist','');
			listCurrentKey.put('cplist','');
			listDetailWidth.put('cplist','400');
			listDetailHeight.put('cplist','300');
			listListXSL.put('cplist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDblClickEvent.put('cplist',selectCP);
			openPage('cplist','1');
		}

		<!---------------------------产品查询列表---------------------------------->
		function searchProByName(){
			listIndex.put('prolist','1');
			var proName = SearchProByName.value;
			var cpId = SearchForm.SelCP.value;
			listPageURL.put('prolist','../GetApByApAndCPId.do?CPId='+cpId+'&AppName='+encodeURIComponent(proName)+'&index=#index#');
			listDetailURL.put('prolist','');
			listCurrentId.put('prolist','');
			listCurrentKey.put('prolist','');
			listDetailWidth.put('prolist','400');
			listDetailHeight.put('prolist','300');
			listListXSL.put('prolist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDblClickEvent.put('prolist',selectPro);
			openPage('prolist','1');
		}
		
		<!----------------------页面初始化----------------------->
		var reportdetailHTML = "";
		var cpHTML = "";
		var proHTML = "";
				
		function init(){
			reportdetailHTML = document.all["tb_reportdetail"].innerHTML;
			document.all["tb_reportdetail"].innerHTML = "";

			cpHTML = document.all["tb_cp"].innerHTML;
			document.all["tb_cp"].innerHTML = "";

			proHTML = document.all["tb_pro"].innerHTML;
			document.all["tb_pro"].innerHTML = "";
			
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
			listListXSL.put('reportlist','../<%=LangPage.langPage.getXsl_path()%>reportlist.xsl');
			listDetailXSL.put('reportlist','');
		   
		     
		    listIndex.put('reportdetaillist','1');
			listPageURL.put('reportdetaillist','');
			listDetailURL.put('reportdetaillist','');
			listCurrentId.put('reportdetaillist','');
			listCurrentKey.put('reportdetaillist','');
			listDetailWidth.put('reportdetaillist','400');
			listDetailHeight.put('reportdetaillist','300');
			listListXSL.put('reportdetaillist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('reportdetaillist','');

			listIndex.put('cplist','1');
			//listPageURL.put('cplist','../GetCPList.do?index=#index#');
			listDetailURL.put('cplist','');
			listCurrentId.put('cplist','');
			listCurrentKey.put('cplist','');
			listDetailWidth.put('cplist','300');
			listDetailHeight.put('cplist','320');
			listListXSL.put('cplist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('cplist','');
			listDblClickEvent.put('cplist',selectCP);

			listIndex.put('prolist','1');
			//listPageURL.put('prolist','../GetFeeCannelBySP.do?SPId='+cur_spid+'&index=#index#');
			listDetailURL.put('prolist','');
			listCurrentId.put('prolist','');
			listCurrentKey.put('prolist','');
			listDetailWidth.put('prolist','300');
			listDetailHeight.put('prolist','320');
			listListXSL.put('prolist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('prolist','');
			listDblClickEvent.put('prolist',selectPro);
		   }
		<!------------------------------------------------------------->
	</script>
</head>

<body onload="init();">
	<!-- 页面标题 -->
	<table class="table_pagetitle" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("reportFee_cp")%></td>
	</tr>
	</table>

	<!-- 查询条件 -->
	<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr><td height="5"></td></tr>
	<tr>
		<td valign="middle" style="font-size:9pt;color:#4796ee;">
			<form method="POST" name="SearchForm" class="editform">
				<input type="hidden" name="Date" value="">
				<input type="hidden" name="Name" value="">
				<input type="hidden" name="Type" value="">
				<input type="hidden" name="year" value="">
				<input type="hidden" name="month" value="">
				<input type="hidden" name="SelCP">
				<input type="hidden" name="SelApp" readonly>
			<b><%=LangPage.langPage.getSearch("search_conditions")%></b>
			<br/>
			<%=LangPage.langPage.getSearch("search_type")%>&nbsp;&nbsp;&nbsp;&nbsp;
			<select name="reporttype" onchange="showOptions();">
				<option value="3"><%=LangPage.langPage.getSearch("search_bycp")%></option>
				<option value="4" selected><%=LangPage.langPage.getSearch("search_byapp")%></option>
			</select>
			<br/>
			<%=LangPage.langPage.getSearch("search_cp")%><input type="text" class="input_edit"  name="SelCPText" readonly>
				<a href="#" onclick="showCP();"><img src="../<%=LangPage.langPage.getButton_img_path()%>select_001.gif"   border="0" align="top" vspace="1" /></a>
			&nbsp;&nbsp;
		<span id="selapptext" >
			<%=LangPage.langPage.getSearch("search_app")%><input type="text" class="input_edit"  name="SelAppText" readonly>
			<a href="#" onclick="showPro();"><img src="../<%=LangPage.langPage.getButton_img_path()%>select_001.gif"   border="0" align="top" vspace="1" /></a>
		</span>
		     <br/><%=LangPage.langPage.getSearch("search_startdate")%>&nbsp;&nbsp;&nbsp;&nbsp;<input class="input_edit" type="text" name="StartDate" style="width:80;" value="<%=new SimpleDateFormat("yyyy-MM-dd").format(calendar.getTime()) %>" readonly>&nbsp;<a href="#" onclick="LtCalendar.create('StartDate',68,165);"><img src="../<%=LangPage.langPage.getButton_img_path()%>point_001.gif"   border="0" align="top" vspace="1" /></a>
			&nbsp;&nbsp;<%=LangPage.langPage.getSearch("search_enddate")%><input class="input_edit" type="text" name="EndDate" style="width:80;" value="<%=new SimpleDateFormat("yyyy-MM-dd").format(new Date()) %>" readonly>&nbsp;<a href="#" onclick="LtCalendar.create('EndDate',68,345);"><img src="../<%=LangPage.langPage.getButton_img_path()%>point_001.gif"   border="0" align="top" vspace="1" /></a><br>
			
			<a href="#" onclick="showReport();"><img src="../<%=LangPage.langPage.getButton_img_path()%>search_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			</form>
		</td>
	</tr>
	<tr><td height="5"></td></tr>
	</table>

	<center>
	<!-- 汇总结果显示区域 -->
	<div id="reportdiv" align="center" style="display:none;width:90%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		<fieldset class="fieldset_edit">
		<legend id="reporttitle" class="legend_edit"><b><%=LangPage.langPage.getWindowsTitle("cw_detail")%></b></legend>
		<div id="reportlist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		</div>
		</fieldset>
	</div>
	<div id="tb_reportdetail" class="datainfo">
		<div align="center" id="reportdetaillist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		</div>
	</div>
	</center>
</body>
	<!-- CP列表显示区域 -->
	<div id="tb_cp" class="datainfo">
		<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
			<tr>
				<td class="td_buttonbar" valign="middle" style="font-size:9pt;"><%=LangPage.langPage.getSelect("search_searcp")%>

					<input type="text" class="input_edit"  name="SearchCPByName">
					<a href="#" onclick="searchCPByName();"><img src="../<%=LangPage.langPage.getButton_img_path()%>search_003.gif"   border="0" align="top" vspace="1" /></a>
				</td>
			</tr>
		</table>
		<div align="center" id="cplist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		</div>
	</div>

	<!-- 产品列表显示区域 -->
	<div id="tb_pro" class="datainfo">
		<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
			<tr>
				<td class="td_buttonbar" valign="middle" style="font-size:9pt;"><%=LangPage.langPage.getSelect("search_searapp")%>

					<input type="text" class="input_edit"  name="SearchProByName">
					<a href="#" onclick="searchProByName();"><img src="../<%=LangPage.langPage.getButton_img_path()%>search_003.gif"   border="0" align="top" vspace="1" /></a>
				</td>
			</tr>
		</table>
		<div align="center" id="prolist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		</div>
	</div>
</html>
