<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangAction"%>
<%@ page import="com.language.langdata.LangDBTable"%>
<%@ page import="com.vogins.sps.db.mobile.MFPartner"%>
<%@ page import="com.vogins.sps.db.mobile.Mobile"%>
<%
   MFPartner mf = new MFPartner();
   Mobile mobile = new Mobile();
 %>
<html>

<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<TITLE><%=LangPage.langPage.getPageTitle("reportFee_mf")%></TITLE>
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
		
		<!------------------选择手机厂商---------------------------->
		var cur_mfid = "";
		var mfwindow = new SimpleWindow();
		function showMF(){
			SearchForm.SelMFText.value = "";
			SearchForm.SelMF.value = "";
			
			SearchForm.SelMobileText.value = "";
			SearchForm.SelMobile.value = "";

			SearchForm.UserAgent.value = "0";		//清空UA数据
			SearchForm.UserAgent.options.length = 0;
			SearchForm.UserAgent.add(document.createElement("OPTION"));
			SearchForm.UserAgent.options[0].text="<%=LangPage.langPage.getSelect("status_all")%>";
			SearchForm.UserAgent.options[0].value="0";
			
			mfwindow.Create('mf_window','<%=LangPage.langPage.getWindowsTitle("mf_selectmf")%>',600,400,mfHTML);
			mfwindow.Show();
			listPageURL.put('mflist','../GetMFList.do?index=#index#');
			openPage('mflist','1');
		}
		
		function selectMF(){
			if(listCurrentKey.get('mflist') == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=mf.getAliasByFiled("MFName")%>");
				//alert("没有选择手机厂商！");
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
					showUserAgent();
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
			if(SearchForm.SelMF.value==""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=mf.getAliasByFiled("MFName")%>");
				SearchForm.SelMFText.focus();
				return false;
			}
			if(cur_mfid != ""){
				listPageURL.put('moblist','../GetMobileList.do?PartnerId='+cur_mfid+'&index=#index#');
				mobwindow.Create('mob_window','<%=LangPage.langPage.getWindowsTitle("mobile_selectmobile")%>',600,400,mobHTML);
				mobwindow.Show();
				openPage('moblist','1');
			}
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

		<!-----------------------------初始化UA下拉框-------------------------------->
		function showUserAgent(){
		      if(SearchForm.SelMF.value != ""){
		          showUA();
		      }else{
				SearchForm.UserAgent.options.length = 0;
				SearchForm.UserAgent.add(document.createElement("OPTION"));
				SearchForm.UserAgent.options[0].text="<%=LangPage.langPage.getSelect("status_all")%>";
				SearchForm.UserAgent.options[0].value="0";
		      }
		}
		
		<!------------------根据所选厂商，更新机型UA下拉框--------------------------->
		function showUA(){
			if(SearchForm.SelMF.value != ""){
				sendG("../GetUabyMFId.do?MFId="+SearchForm.SelMF.value,getUAResult);
			}else{
				SearchForm.UserAgent.options.length = 0;
				SearchForm.UserAgent.add(document.createElement("OPTION"));
				SearchForm.UserAgent.options[0].text="<%=LangPage.langPage.getSelect("status_all")%>";
				SearchForm.UserAgent.options[0].value="0";
			}
		}
		function getUAResult(cartXML){
			var cart = cartXML.getElementsByTagName("result")[0];
			var list = cart.getElementsByTagName("list")[0];
			var rows = list.getElementsByTagName("row");
			SearchForm.UserAgent.options.length = 0;
			SearchForm.UserAgent.add(document.createElement("OPTION"));
			SearchForm.UserAgent.options[0].text="<%=LangPage.langPage.getSelect("status_all")%>";
			SearchForm.UserAgent.options[0].value="0";
			for(var i=0;i<rows.length;i++){
				var key = rows[i].getElementsByTagName("key")[0].firstChild.nodeValue;
				var field = rows[i].getElementsByTagName("field")[0].firstChild.nodeValue;
				SearchForm.UserAgent.add(document.createElement("OPTION"));
				SearchForm.UserAgent.options[i+1].text=field;
				SearchForm.UserAgent.options[i+1].value=key;
			}
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
		var reportdetailHTML = "";
		var mfHTML = "";
		var mobHTML = "";
	
		function init(){
		 	reportdetailHTML = document.all["tb_reportdetail"].innerHTML;
			document.all["tb_reportdetail"].innerHTML = "";
			
			mfHTML = document.all["tb_mf"].innerHTML;
			document.all["tb_mf"].innerHTML = "";

			mobHTML = document.all["tb_mob"].innerHTML;
			document.all["tb_mob"].innerHTML = "";

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
		}
		<!------------------------------------------------------------->
	</script>
</head>

<body onload="init();">
	<!-- 页面标题 -->
	<table class="table_pagetitle" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("reportFee_mf")%></td>
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
	
			<b><%=LangPage.langPage.getSearch("search_conditions")%></b><br/><%=LangPage.langPage.getSearch("search_mf")%><input type="text" class="input_edit"  name="SelMFText" readonly>
				<input type="hidden" name="SelMF">
				<a href="#" onclick="showMF();"><img src="../<%=LangPage.langPage.getButton_img_path()%>select_001.gif"   border="0" align="middle" vspace="0" /></a>
			&nbsp;&nbsp;&nbsp;
			<%=LangPage.langPage.getSearch("search_mobile")%><input type="text" class="input_edit"  name="SelMobileText" readonly>
				<input type="hidden" name="SelMobile" readonly>
				<a href="#" onclick="showMob();"><img src="../<%=LangPage.langPage.getButton_img_path()%>select_001.gif"   border="0" align="middle" vspace="0" /></a>
			&nbsp;&nbsp;&nbsp;
			<%=LangPage.langPage.getSearch("search_useragent")%><select name="UserAgent"><option value="0"><%=LangPage.langPage.getSelect("status_all")%></option></select><br>
			&nbsp;&nbsp;&nbsp;
			<%=LangPage.langPage.getSearch("search_startdate")%><input class="input_edit" type="text" name="StartDate" style="width:80;" value="">&nbsp;<a href="#" onclick="LtCalendar.create('StartDate',68,165);"><img src="../<%=LangPage.langPage.getButton_img_path()%>point_001.gif"   border="0" align="top" vspace="1" /></a>
			&nbsp;&nbsp;&nbsp;
			<%=LangPage.langPage.getSearch("search_enddate")%><input class="input_edit" type="text" name="EndDate" style="width:80;" value="">&nbsp;<a href="#" onclick="LtCalendar.create('EndDate',68,345);"><img src="../<%=LangPage.langPage.getButton_img_path()%>point_001.gif"   border="0" align="top" vspace="1" /></a><br/>
			 <%=LangPage.langPage.getSearch("search_type")%><select name="reporttype"><option value="5"><%=LangPage.langPage.getSearch("search_bymf")%></option><option value="6"><%=LangPage.langPage.getSearch("search_bymobile")%></option><option value="7"><%=LangPage.langPage.getSearch("search_byua")%></option></select>
			&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href="#" onclick="showReport();"><img src="../<%=LangPage.langPage.getButton_img_path()%>search_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
	
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
</html>
