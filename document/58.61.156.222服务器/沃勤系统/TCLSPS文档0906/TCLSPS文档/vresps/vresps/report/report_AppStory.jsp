<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangAction"%>
<%@ page import="com.language.langdata.LangDBTable"%>
<%@ page import="com.vogins.sps.db.mobile.MFPartner"%>
<%@ page import="com.vogins.sps.db.mobile.Mobile"%>

<%@ page import="java.text.SimpleDateFormat"%>
<%@ page import="java.util.Calendar"%>
<%@ page import="java.util.GregorianCalendar"%>
<%@ page import="java.util.Date"%>
<%
   MFPartner mf = new MFPartner();
   Mobile mobile = new Mobile();
   
   Calendar calendar  =   new  GregorianCalendar();
	calendar.set( Calendar.DATE,  1 );
%>
<html>

<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<TITLE><%=LangPage.langPage.getPageTitle("report_AppStory")%></TITLE>
	<meta http-equiv="Pragma" content="no-cache">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_main.css">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_swin.css">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_cal.css">
	<SCRIPT language="JavaScript" type="text/javascript" src="../js/jwdf_util.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_xml.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_view.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_swin.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_cal.js"></SCRIPT>
	<script language=javascript><!--

		<!-----------------------显示汇总结果--------------------------->
		function showReport(){
		
			if(SearchForm.reporttype.value=='1'){   //按时间
				listPageURL.put('reportlist','../Report_AppHour.do?'+getP(SearchForm)+'&index=#index#');
				openPage('reportlist','1');
			}else if(SearchForm.reporttype.value=='2'){ //按日期
				listPageURL.put('reportlist','../Report_AppDate.do?'+getP(SearchForm)+'&index=#index#');
				openPage('reportlist','1');
			}
			
		}
		<!------------------------------------------------------------->
		<!------------------选择手机厂商---------------------------->
		var cur_mfid = "";
		var mfwindow = new SimpleWindow();
		function showMF(){
			SearchForm.SelMobileText.value = "";
			SearchForm.SelMobile.value = "";
			mfwindow.Create('mf_window','<%=LangPage.langPage.getWindowsTitle("mf_selectmf")%>',600,400,mfHTML);
			mfwindow.Show();
			listPageURL.put('mflist','../GetMFList.do?index=#index#');
			openPage('mflist','1');
		}
		
		function selectMF(){
			if(listCurrentKey.get('mflist') == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=mf.getAliasByFiled("MFName")%>");
				return;
			}else{
				sendG("../GetMFInfo.do?PartnerId="+listCurrentKey.get('mflist'),getMFDetail);
			}
		}
		
		function getMFDetail(cartXML){
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
				if(name == "<%=mf.getAliasByFiled("MFId")%>"){
					cur_mfid = value;
					SearchForm.SelMF.value = value;
				}
				if(name == "<%=mf.getAliasByFiled("MFName")%>"){
					SearchForm.SelMFText.value = value;
				}
			}
			mfwindow.Close();
		}	

		<!---------------------------根据手机厂商选择机型---------------------------------->
		var cur_mobid = "";
		var mobwindow = new SimpleWindow();
		function showMob(){
			listPageURL.put('moblist','../GetMobileList.do?PartnerId=0&index=#index#');
			mobwindow.Create('mob_window','<%=LangPage.langPage.getWindowsTitle("mobile_selectmobile")%>',600,400,mobHTML);
			mobwindow.Show();
			openPage('moblist','1');
		}
		
		function selectMob(){
			if(listCurrentKey.get('moblist') == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=mobile.getAliasByFiled("MobileName")%>");
				return;
			}else{
				sendG("../GetMobileInfo.do?MobileId="+listCurrentKey.get('moblist'),getMobDetail);
			}
		}
		
		function getMobDetail(cartXML){
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
				if(name == "<%=mobile.getAliasByFiled("MobileId")%>"){
					cur_mobid = value;
					SearchForm.SelMobile.value = value;
				}
				if(name == "<%=mobile.getAliasByFiled("MobileName")%>"){
					SearchForm.SelMobileText.value = value;
				}
			}
			mobwindow.Close();
		}
		<!---------------------------根据机型选择AppStoreId---------------------------------->
		var cur_asid = "";
		var appstoreidwindow = new SimpleWindow();
		function showAppStoreId(){
			if(SearchForm.SelMobile.value==""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=mobile.getAliasByFiled("MobileName")%>");
				SearchForm.SelMobileText.focus();
				return false;
			}
			if(cur_mobid != ""){
				listPageURL.put('asidlist','../GetASIdList.do?PartnerId='+cur_mobid+'&index=#index#');
				appstoreidwindow.Create('mob_window','<%=LangPage.langPage.getWindowsTitle("mobile_selectmobile")%>',200,400,asidHTML);
				appstoreidwindow.Show();
				openPage('asidlist','1');
			}
		}
		
		function selectASId(){
			if(listCurrentKey.get('asidlist') == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=mobile.getAliasByFiled("MobileName")%>");
				return;
			}else{
				getASID(listCurrentKey.get('asidlist'));
				//sendG("../GetAppStoreInfo.do?AppStoreId="+listCurrentKey.get('asidlist'),getASIDDetail);
			}
		}

		function getASID(asid){
			cur_asid = asid;
			SearchForm.AppStoreIdText.value = asid;
			SearchForm.AppStoreId.value = asid;
			appstoreidwindow.Close();
		}
		
		<!---------------------------手机厂商查询列表---------------------------------->
		function searchMFByName(){
			listIndex.put('mflist','1');
			var mfName = SearchMFByName.value;
			listPageURL.put('mflist','../GetMFListByMFName.do?MFName='+encodeURIComponent(mfName)+'&index=#index#');
			listDetailURL.put('mflist','');
			listCurrentId.put('mflist','');
			listCurrentKey.put('mflist','');
			listDetailWidth.put('mflist','400');
			listDetailHeight.put('mflist','300');
			listListXSL.put('mflist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDblClickEvent.put('mflist',selectMF);
			openPage('mflist','1');
		}

		<!---------------------------机型查询列表---------------------------------->
		function searchMobByName(){
			listIndex.put('moblist','1');
			var mobName = SearchMobByName.value;
			var mfId = SearchForm.SelMF.value;
			listPageURL.put('moblist','../GetMoByMoAndMFId.do?MFId='+mfId+'&MobName='+encodeURIComponent(mobName)+'&index=#index#');
			listDetailURL.put('moblist','');
			listCurrentId.put('moblist','');
			listCurrentKey.put('moblist','');
			listDetailWidth.put('moblist','400');
			listDetailHeight.put('moblist','300');
			listListXSL.put('moblist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDblClickEvent.put('moblist',selectMob);
			openPage('moblist','1');
		}
	
		<!----------------------页面初始化----------------------->
		
		var mfHTML = "";
		var mobHTML = "";
		var asidHTML = "";
		
		function init(){
			mfHTML = document.all["tb_mf"].innerHTML;
			document.all["tb_mf"].innerHTML = "";

			mobHTML = document.all["tb_mob"].innerHTML;
			document.all["tb_mob"].innerHTML = "";

			asidHTML = document.all["tb_asid"].innerHTML;
			document.all["tb_asid"].innerHTML = "";
			
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

			listIndex.put('mflist','1');
			//listPageURL.put('mflist','../GetMFList.do?index=#index#');
			listDetailURL.put('mflist','');
			listCurrentId.put('mflist','');
			listCurrentKey.put('mflist','');
			listDetailWidth.put('mflist','300');
			listDetailHeight.put('mflist','320');
			listListXSL.put('mflist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('mflist','');
			listDblClickEvent.put('mflist',selectMF);

			listIndex.put('moblist','1');
			//listPageURL.put('moblist','../GetFeeCannelBySP.do?SPId='+cur_spid+'&index=#index#');
			listDetailURL.put('moblist','');
			listCurrentId.put('moblist','');
			listCurrentKey.put('moblist','');
			listDetailWidth.put('moblist','300');
			listDetailHeight.put('moblist','320');
			listListXSL.put('moblist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('moblist','');
			listDblClickEvent.put('moblist',selectMob);

			listIndex.put('asidlist','1');
			//listPageURL.put('asidlist','../GetFeeCannelBySP.do?SPId='+cur_spid+'&index=#index#');
			listDetailURL.put('asidlist','');
			listCurrentId.put('asidlist','');
			listCurrentKey.put('asidlist','');
			listDetailWidth.put('asidlist','300');
			listDetailHeight.put('asidlist','320');
			listListXSL.put('asidlist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('asidlist','');
			listDblClickEvent.put('asidlist',selectASId);
	
		}
		<!------------------------------------------------------------->
	</script>
</head>

<body onload="init();">
	<!-- 页面标题 -->
	<table class="table_pagetitle" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("report_AppStory")%></td>
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
		<b><%=LangPage.langPage.getSearch("search_conditions")%></b>
			</br>
			<%=LangPage.langPage.getSearch("search_mobile")%><input type="text" class="input_edit"  name="SelMobileText" readonly>
				<input type="hidden" name="SelMobile" readonly>
				<a href="#" onclick="showMob();"><img src="../<%=LangPage.langPage.getButton_img_path()%>select_001.gif"   border="0" align="top" vspace="1" /></a>&nbsp;&nbsp;&nbsp;
				AppStoreId:<input type="text" class="input_edit"  name="AppStoreIdText" readonly>
				<input type="hidden" name="AppStoreId" readonly>
				<a href="#" onclick="showAppStoreId();"><img src="../<%=LangPage.langPage.getButton_img_path()%>select_001.gif"   border="0" align="top" vspace="1" /></a>
		     <br/><%=LangPage.langPage.getSearch("search_startdate")%><input class="input_edit" type="text" name="StartDate" style="width:80;" value="<%=new SimpleDateFormat("yyyy-MM-dd").format(calendar.getTime()) %>" readonly>&nbsp;<a href="#" onclick="LtCalendar.create('StartDate',68,165);"><img src="../<%=LangPage.langPage.getButton_img_path()%>point_001.gif"   border="0" align="top" vspace="1" /></a>
			&nbsp;&nbsp;<%=LangPage.langPage.getSearch("search_enddate")%><input class="input_edit" type="text" name="EndDate" style="width:80;" value="<%=new SimpleDateFormat("yyyy-MM-dd").format(new Date()) %>" readonly>&nbsp;<a href="#" onclick="LtCalendar.create('EndDate',68,345);"><img src="../<%=LangPage.langPage.getButton_img_path()%>point_001.gif"   border="0" align="top" vspace="1" /></a><br/>
			<%=LangPage.langPage.getSearch("search_type")%><select name="reporttype"><option value="1"><%=LangPage.langPage.getSearch("search_byhour")%></option><option value="2"><%=LangPage.langPage.getSearch("search_bydate")%></option></select>
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
	<!-- 手机厂商列表显示区域 -->
	<div id="tb_mf" class="datainfo">
		<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
			<tr>
				<td class="td_buttonbar" valign="middle" style="font-size:9pt;"><%=LangPage.langPage.getSelect("search_searmf")%>

					<input type="text" class="input_edit"  name="SearchMFByName">
					<a href="#" onclick="searchMFByName();"><img src="../<%=LangPage.langPage.getButton_img_path()%>search_003.gif"   border="0" align="top" vspace="1" /></a>
				</td>
			</tr>
		</table>
		<div align="center" id="mflist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		</div>
	</div>

	<!-- 机型列表显示区域 -->
	<div id="tb_mob" class="datainfo">
		<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
			<tr>
				<td class="td_buttonbar" valign="middle" style="font-size:9pt;"><%=LangPage.langPage.getSelect("search_searmobile")%>

					<input type="text" class="input_edit"  name="SearchMobByName">
					<a href="#" onclick="searchMobByName();"><img src="../<%=LangPage.langPage.getButton_img_path()%>search_003.gif"   border="0" align="top" vspace="1" /></a>
				</td>
			</tr>
		</table>
		<div align="center" id="moblist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		</div>
	</div>
	<!-- AppStoreId列表显示区域 -->
	<div id="tb_asid" class="datainfo">
		<div align="center" id="asidlist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		</div>
	</div>
</html>






