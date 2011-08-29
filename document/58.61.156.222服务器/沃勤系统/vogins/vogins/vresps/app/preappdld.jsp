<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangAction"%>
<%@ page import="com.language.langdata.LangDBTable"%>
<%@ page import="com.vogins.sps.db.mobile.MFPartner"%>
<%@ page import="com.vogins.sps.db.mobile.Mobile"%>
<%@ page import="com.vogins.sps.db.app.AppVersion"%>
<%
	MFPartner mf = new MFPartner();
	Mobile mo = new Mobile();
	AppVersion appver = new AppVersion();
%>
<html>

<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<TITLE><%=LangPage.langPage.getPageTitle("preappdld")%></TITLE>
	<meta http-equiv="Pragma" content="no-cache">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_main.css">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_swin.css">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_cal.css">
	<SCRIPT language="JavaScript" type="text/javascript" src="../js/jwdf_check.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../js/jwdf_util.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_xml.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_view.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_swin.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_cal.js"></SCRIPT>
	<script language=javascript>
		var cur_params = "";
		<!-----------------------显示汇总结果--------------------------->
		function showReport(){
			if(SearchForm.filtertype.value == "2"){
				if(SearchForm.ScreenWidth.value > 1000 || SearchForm.ScreenWidth.value < 100){
					alert("屏幕宽不符合要求！");
					return false;
				}
				if(SearchForm.ScreenHeight.value > 1000 || SearchForm.ScreenHeight.value < 100){
					alert("屏幕高不符合要求！");
					return false;
				}
			}
			cur_params = getP(SearchForm);
			listPageURL.put('reportlist','../GetFilterApp.do?'+getP(SearchForm));
			openPage('reportlist','1');
			sel_appid = "";
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

			mfwindow.Create('mf_window','<%=LangPage.langPage.getWindowsTitle("mf_selectmf")%>',600,400,mfHTML);
			mfwindow.Show();
			openPage('mflist','1');
		}
		
		function selectMF(){
			if(listCurrentKey.get('mflist') == ""){
				alert("<%=LangAction.langAction.getNoselect_mf()%>");
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
			if(SearchForm.SelMF.value==""){
				alert("<%=LangAction.langAction.getNoselect_mf()%>");
				SearchForm.SelMFText.focus();
				return false;
			}
			if(cur_mfid != ""){
				listPageURL.put('moblist','../GetMobileList.do?PartnerId='+cur_mfid+'&index=#index#');
				mobwindow.Create('mob_window','<%=LangPage.langPage.getWindowsTitle("app_selectapp")%>',600,400,mobHTML);
				mobwindow.Show();
				openPage('moblist','1');
			}
		}
		
		function selectMob(){
			if(listCurrentKey.get('moblist') == ""){
				alert("<%=LangAction.langAction.getNoselect_mobile()%>");
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
				if(name == "<%=mo.getAliasByFiled("MobileId")%>"){
					cur_mobid = value;
					SearchForm.SelMobile.value = value;
				}
				if(name == "<%=mo.getAliasByFiled("MobileName")%>"){
					SearchForm.SelMobileText.value = value;
				}
			}
			mobwindow.Close();
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

		function setScreen(){
			type = SearchForm.Screen.value;
			if(type == 1){
				SearchForm.ScreenWidth.value="176";
				SearchForm.ScreenHeight.value="220";
			}else if(type == 2){
				SearchForm.ScreenWidth.value="240";
				SearchForm.ScreenHeight.value="320";
			}else if(type == 4){
				SearchForm.ScreenWidth.value="240";
				SearchForm.ScreenHeight.value="400";
			}else if(type == 0){
				SearchForm.ScreenWidth.value="0";
				SearchForm.ScreenHeight.value="0";
			}else{
				SearchForm.ScreenWidth.value="0";
				SearchForm.ScreenHeight.value="0";
			} 
		}   

		function showFilter(){
			type = document.all['filtertype'].value;
			if(type == '1'){
				document.all['div_mobile'].style.display = "";
				document.all['div_param'].style.display = "none";
			}else if(type == '2'){
				document.all['div_mobile'].style.display = "none";
				document.all['div_param'].style.display = "";
			}
			document.all['reportlist'].innerHTML = "&nbsp;";
			cur_params = "";
			sel_appid = "";
		}

		var sel_appid = "";
		function clickCheck2(id){
			if(document.all["chk2_"+id].checked){
				if(sel_appid.indexOf(";"+id+";")<0){
					if(sel_appid == "") sel_appid = ";"+id+";";
					else sel_appid = sel_appid+id+";";
				}
			}else{
				if(sel_appid.indexOf(";"+id+";")>=0){
					sel_appid = sel_appid.replace(";"+id+";",";");
				}
			}
		}
		function doSelect2(){
			newSubmit22();
			bookwindow.Close();
		}

		function downloadSelect(){
			if(sel_appid=="" || sel_appid==";"){
				alert("<%=LangAction.langAction.getNoselect_app()%>");
				return;
			}else{
				window.open("../PreAppDownload.do?VerId="+sel_appid,"DownloadFrame");
			}
		}
		function downloadAll(){
			if(cur_params == ""){
				alert("<%=LangAction.langAction.getPreapp_unknow_filter()%>");
				return;
			}else{
				window.open("../PreAppDldAll.do?"+cur_params,"DownloadFrame");
			}
		}
		
		<!----------------------页面初始化----------------------->
		var mfHTML = "";
		var mobHTML = "";
	
		function init(){
			mfHTML = document.all["tb_mf"].innerHTML;
			document.all["tb_mf"].innerHTML = "";

			mobHTML = document.all["tb_mob"].innerHTML;
			document.all["tb_mob"].innerHTML = "";

			initList();
			showFilter();
		}


		function initList(){
			listIndex.put('reportlist','1');
			listPageURL.put('reportlist','');
			listDetailURL.put('reportlist','');
			listCurrentId.put('reportlist','');
			listCurrentKey.put('reportlist','');
			listDetailWidth.put('reportlist','400');
			listDetailHeight.put('reportlist','300');
			listListXSL.put('reportlist','../xsl/checklist3.xsl');
			listDetailXSL.put('reportlist','');

			listIndex.put('mflist','1');
			listPageURL.put('mflist','../GetMFList.do?index=#index#');
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
		<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("preappdld")%></td>
	</tr>
	</table>
	
	<!-- 查询条件 -->
	<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr><td height="5"></td></tr>
	<tr>
		<td valign="middle" style="font-size:9pt;color:#4796ee;">
			<form method="POST" name="SearchForm" class="editform">
			<b><%=LangPage.langPage.getSearch("search_conditions")%></b><%=LangPage.langPage.getSearch("search_type")%><select name="filtertype" onchange="showFilter();"><option value="1"><%=LangPage.langPage.getSearch("search_bymobile")%></option><option value="2"><%=LangPage.langPage.getSearch("search_byprarm")%></option></select><br>
			<div id="div_mobile" style="display:;">
			<b>　　　　　</b><%=LangPage.langPage.getSearch("search_mf")%><input type="text" class="input_edit"  name="SelMFText" readonly>
				<input type="hidden" name="SelMF">
				<a href="#" onclick="showMF();"><img src="../<%=LangPage.langPage.getButton_img_path()%>select_001.gif"   border="0" align="top" vspace="1" /></a>
			&nbsp;&nbsp;&nbsp;
			<%=mo.getAliasByFiled("MobileName") %><input type="text" class="input_edit"  name="SelMobileText" readonly>
				<input type="hidden" name="SelMobile" readonly>
				<a href="#" onclick="showMob();"><img src="../<%=LangPage.langPage.getButton_img_path()%>select_001.gif"   border="0" align="top" vspace="1" /></a>
			&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
			<a href="#" onclick="showReport();"><img src="../<%=LangPage.langPage.getButton_img_path()%>filter_001.gif"   border="0" align="top" vspace="1" /></a>
			</div>
			<div id="div_param" style="display:none;">
			<b>　　　　　</b><%=appver.getAliasByFiled("ScreenType") %>

				<select name="Screen" onchange="setScreen();">
					<option value="1"><%=LangPage.langPage.getSelect("screen_qcif")%></option>
					<option value="2"><%=LangPage.langPage.getSelect("screen_qvga")%></option>
					<option value="4"><%=LangPage.langPage.getSelect("screen_wqvga")%></option>
					<option value="8"><%=LangPage.langPage.getSelect("screen_other")%></option>
				</select>&nbsp;&nbsp;
				<%=appver.getAliasByFiled("ScreenWidth") %><input type="text" name="ScreenWidth" onkeydown="enterUnsigned();" style="width:50;" value="176">&nbsp;&nbsp;<%=appver.getAliasByFiled("ScreenHeight") %><input type="text" name="ScreenHeight" onkeydown="enterUnsigned();" style="width:50;" value="220">
			<b>　　　　　</b><%=appver.getAliasByFiled("MemorySize") %>

				<select name="Memory">
					<option value="500">500K</option>
					<option value="600">600K</option>
					<option value="800">800K</option>
					<option value="1000">1000K</option>
				</select>
			<br>
			<b>　　　　　</b><%=appver.getAliasByFiled("InputDC") %>

				<input type="checkbox" name="Input_Keypad"><%=LangPage.langPage.getSelect("screen_keypad")%>&nbsp;&nbsp;
				<input type="checkbox" name="Input_Touch"><%=LangPage.langPage.getSelect("screen_touch")%>

			<b>　　　　　</b><%=appver.getAliasByFiled("VREVersion") %>
				<input class="input_edit" style="width:100;" onkeydown="enterFloat();" type="text" name="VreVersion" value="">
			&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
			<a href="#" onclick="showReport();"><img src="../<%=LangPage.langPage.getButton_img_path()%>filter_001.gif"   border="0" align="top" vspace="1" /></a>
			</div>
			</form>
		</td>
	</tr>
	<tr><td height="5"></td></tr>
	</table>

	<!-- 操作按钮 -->
	<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_buttonbar" valign="middle">
			<a href="#" onclick="downloadAll();"><img src="../<%=LangPage.langPage.getButton_img_path()%>downloadall_001.gif"   border="0" align="top" vspace="1" /></a>
			<a href="#" onclick="downloadSelect();"><img src="../<%=LangPage.langPage.getButton_img_path()%>downloadselect_001.gif"   border="0" align="top" vspace="1" /></a>
		</td>
	</tr>
	</table>

	<center>
	<!-- 汇总结果显示区域 -->
	<div id="reportdiv" align="center" style="width:90%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		<fieldset class="fieldset_edit">
		<legend id="reporttitle" class="legend_edit"><b><%=LangPage.langPage.getWindowsTitle("mobile_applist")%></b></legend>
		<div id="reportlist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		</div>
		</fieldset>
	</div>
	</center>
</body>
	<!-- 手机厂商列表显示区域 -->
	<div id="tb_mf" class="datainfo">
		<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
			<tr>
				<td class="td_buttonbar" valign="middle" style="font-size:9pt;"><%=LangPage.langPage.getSelect("search_searmf")%>


					<input type="text" class="input_edit"  name="SearchMFByName">
					<a href="#" onclick="searchMFByName();"><img src="../<%=LangPage.langPage.getButton_img_path()%>search_003.gif"  border="0" align="top" vspace="1" /></a>
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
	
	<div align="center" id="download_div" style="display:none;">
		<iframe src="" name="DownloadFrame"></iframe>
	</div>
	
</html>
