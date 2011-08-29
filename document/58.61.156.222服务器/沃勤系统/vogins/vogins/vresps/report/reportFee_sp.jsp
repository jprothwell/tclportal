<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangAction"%>
<%@ page import="com.language.langdata.LangDBTable"%>
<%@ page import="com.vogins.sps.db.fee.SPPartner"%>
<%@ page import="com.vogins.sps.db.fee.FeeChannel"%>
<%
	SPPartner sp = new SPPartner();
    FeeChannel channel = new FeeChannel();
 %>
<html>
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<TITLE><%=LangPage.langPage.getPageTitle("reportFee_sp")%></TITLE>
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
		var cur_spid = "";
		<!------------------选择SP---------------------------->
		var spwindow = new SimpleWindow();
		function showSP(){
			SearchForm.SubChannel.value = "";
			SearchForm.SelChannel.value = "";
			spwindow.Create('sp_window','<%=LangPage.langPage.getWindowsTitle("fee_selectsp")%>',600,400,spHTML);
			spwindow.Show();
			listPageURL.put('splist','../GetFeeList.do?index=#index#');
			openPage('splist','1');
		}
	
		function selectSP(){
			if(listCurrentKey.get('splist') == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=sp.getAliasByFiled("SPName")%>");
				return;
			}else{
				sendG("../GetFeeInfo.do?SPId="+listCurrentKey.get('splist'),getPDetail);
			}
		}

		function getPDetail(cartXML){
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
				if(name == "<%=sp.getAliasByFiled("SPId")%>"){
					cur_spid = value;
					SearchForm.SelFee.value = value;
				}
				if(name == "<%=sp.getAliasByFiled("SPName")%>"){
					SearchForm.SubFee.value = value;
				}
			}
			spwindow.Close();
		}

		<!---------------------------选择子渠道---------------------------------->
		var cur_subid = "";
		var subwindow = new SimpleWindow();
		function showChannel(){
			if(SearchForm.SelFee.value==""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=sp.getAliasByFiled("SPName")%>");
				SearchForm.SubFee.focus();
				return false;
			}
			if(cur_spid != ""){
				listPageURL.put('sublist','../GetFeeCannelBySP.do?SPId='+cur_spid+'&index=#index#');
				subwindow.Create('sub_window','<%=LangPage.langPage.getWindowsTitle("fee_selectchannel")%>',600,400,subHTML);
				subwindow.Show();
				openPage('sublist','1');
			}
		}

		function selectSubChannel(){
			if(listCurrentKey.get('sublist') == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=channel.getAliasByFiled("FeeName")%>");
				//alert("没有选择子渠道！");
				return;
			}else{
				sendG("../GetSubInfo.do?FeeId="+listCurrentKey.get('sublist'),getSubDetail);
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
				if(name == "<%=channel.getAliasByFiled("FeeId")%>"){
					cur_subid = value;
					SearchForm.SelChannel.value = value;
				}
				if(name == "<%=channel.getAliasByFiled("FeeName")%>"){
					SearchForm.SubChannel.value = value;
				}
			}
			subwindow.Close();
		}

		<!------------------------------查询信息------------------------------->

		function showReport(){
			if(document.all["reporttype"].value == "1"){
				listPageURL.put('reportlist','../Sp_DateReport.do?'+getP(SearchForm)+'&index=#index#');
				openPage('reportlist','1');
			}else if(document.all["reporttype"].value == "2"){
				listPageURL.put('reportlist','../Sp_ChannelReport.do?'+getP(SearchForm)+'&index=#index#');
				openPage('reportlist','1');
			}
	
		}
		<!------------------------------取详细信息------------------------------->
		var detailwindow = new SimpleWindow();
		function showReportDetail(date,name){

			SearchForm.Date.value = date;
			SearchForm.Name.value = name;
			SearchForm.Type.value = SearchForm.reporttype.value;
			detailwindow.Create('detail_window','<%=LangPage.langPage.getWindowsTitle("cw_detail")%>',600,350,reportdetailHTML);
			detailwindow.Show();
			listPageURL.put('reportdetaillist','../Report_SpsDetail.do?'+getP(SearchForm)+'&index=#index#');
			openPage('reportdetaillist','1');
		}
		
		<!---------------------------SP查询列表---------------------------------->
		function searchBySP(){
			listIndex.put('splist','1');
			var spName = SearchBySP.value;
			listPageURL.put('splist','../GetSPListBySP.do?SPName='+encodeURIComponent(spName)+'&index=#index#');
			listDetailURL.put('splist','');
			listCurrentId.put('splist','');
			listCurrentKey.put('splist','');
			listDetailWidth.put('splist','400');
			listDetailHeight.put('splist','300');
			listListXSL.put('splist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDblClickEvent.put('splist',selectSP);
			openPage('splist','1');
		}

		<!---------------------------子渠道查询列表---------------------------------->
		function searchBySubChannel(){
			listIndex.put('sublist','1');
			var feeName = SearchBySubChannel.value;
			var spId = SearchForm.SelFee.value;
			listPageURL.put('sublist','../GetFeeListByFee.do?SPId='+spId+'&FeeName='+encodeURIComponent(feeName)+'&index=#index#');
			listDetailURL.put('sublist','');
			listCurrentId.put('sublist','');
			listCurrentKey.put('sublist','');
			listDetailWidth.put('sublist','400');
			listDetailHeight.put('sublist','300');
			listListXSL.put('sublist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDblClickEvent.put('sublist',selectSubChannel);
			openPage('sublist','1');
		}
		
		<!----------------------页面初始化----------------------->
		var reportdetailHTML = "";
		var spHTML = "";
		var subHTML = "";
		
		function init(){
		    reportdetailHTML = document.all["tb_reportdetail"].innerHTML;
			document.all["tb_reportdetail"].innerHTML = "";

			spHTML = document.all["tb_sp"].innerHTML;
			document.all["tb_sp"].innerHTML = "";

			subHTML = document.all["tb_sub"].innerHTML;
			document.all["tb_sub"].innerHTML = "";
			
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

			listIndex.put('splist','1');
			//listPageURL.put('splist','../GetFeeList.do?index=#index#');
			listDetailURL.put('splist','');
			listCurrentId.put('splist','');
			listCurrentKey.put('splist','');
			listDetailWidth.put('splist','300');
			listDetailHeight.put('splist','320');
			listListXSL.put('splist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('splist','');
			listDblClickEvent.put('splist',selectSP);

			listIndex.put('sublist','1');
			//listPageURL.put('sublist','../GetFeeCannelBySP.do?SPId='+cur_spid+'&index=#index#');
			listDetailURL.put('sublist','');
			listCurrentId.put('sublist','');
			listCurrentKey.put('sublist','');
			listDetailWidth.put('sublist','300');
			listDetailHeight.put('sublist','320');
			listListXSL.put('sublist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('sublist','');
			listDblClickEvent.put('sublist',selectSubChannel);

		}
	</script>
</head>

<body onload="init();">
	<!-- 页面标题 -->
	<table class="table_pagetitle" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("reportFee_sp")%></td>
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
			<b><%=LangPage.langPage.getSearch("search_conditions")%></b><br/>
			SP：&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<input type="text" class="input_edit"  name="SubFee" readonly>
				<input type="hidden" name="SelFee">
				<a href="#" onclick="showSP();"><img src="../<%=LangPage.langPage.getButton_img_path()%>select_001.gif"  border="0" align="top" vspace="1" /></a>
			&nbsp;&nbsp;&nbsp;
			<%=LangPage.langPage.getSearch("search_channel")%><input type="text" class="input_edit"  name="SubChannel" readonly>
				<input type="hidden" name="SelChannel" readonly>
				<a href="#" onclick="showChannel();"><img src="../<%=LangPage.langPage.getButton_img_path()%>select_001.gif"  border="0" align="top" vspace="1" /></a>
		     <br/><%=LangPage.langPage.getSearch("search_startdate")%><input class="input_edit" type="text" name="StartDate" style="width:80;" value="">&nbsp;<a href="#" onclick="LtCalendar.create('StartDate',68,165);"><img src="../<%=LangPage.langPage.getButton_img_path()%>point_001.gif"   border="0" align="top" vspace="1" /></a>
			&nbsp;&nbsp;<%=LangPage.langPage.getSearch("search_enddate")%><input class="input_edit" type="text" name="EndDate" style="width:80;" value="">
			<a href="#" onclick="LtCalendar.create('EndDate',68,345);"><img src="../<%=LangPage.langPage.getButton_img_path()%>point_001.gif"   border="0" align="top" vspace="1" /></a><br>
			  <%=LangPage.langPage.getSearch("search_type")%><select name="reporttype"><option value="1"><%=LangPage.langPage.getSearch("search_bydate")%></option><option value="2"><%=LangPage.langPage.getSearch("search_bychannel")%></option></select>
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
	<div id="tb_reportdetail" class="datainfo">
		<div align="center" id="reportdetaillist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		</div>
	</div>
	
	<!-- SP列表显示区域 -->
	<div id="tb_sp" class="datainfo">
		<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
			<tr>
				<td class="td_buttonbar" valign="middle" style="font-size:9pt;"><%=LangPage.langPage.getSelect("search_searsp")%>

					<input type="text" class="input_edit"  name="SearchBySP">
					<a href="#" onclick="searchBySP();"><img src="../<%=LangPage.langPage.getButton_img_path()%>search_003.gif"   border="0" align="top" vspace="1" /></a>
				</td>
			</tr>
		</table>
		<div align="center" id="splist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		</div>
	</div>

	<!-- 子渠道列表显示区域 -->
	<div id="tb_sub" class="datainfo">
		<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
			<tr>
				<td class="td_buttonbar" valign="middle" style="font-size:9pt;"><%=LangPage.langPage.getSelect("search_searchannel")%>
					<input type="text" class="input_edit"  name="SearchBySubChannel">
					<a href="#" onclick="searchBySubChannel();"><img src="../<%=LangPage.langPage.getButton_img_path()%>search_003.gif"   border="0" align="top" vspace="1" /></a>
				</td>
			</tr>
		</table>
		<div align="center" id="sublist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		</div>
	</div>
</body>
</html>
