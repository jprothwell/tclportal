<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangAction"%>
<%@ page import="com.language.langdata.LangDBTable"%>
<%@ page import="com.vogins.sps.db.app.Application"%>
<%@ page import="com.vogins.sps.db.mobile.Mobile"%>
<%
   Mobile mobile = new Mobile();
	Application app = new Application();
%>
<html>

<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<TITLE><%=LangPage.langPage.getPageTitle("mf_app")%></TITLE>
	<meta http-equiv="Pragma" content="no-cache">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_main.css">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_swin.css">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_cal.css">
	<SCRIPT language="JavaScript" type="text/javascript" src="../js/jwdf_check.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../js/jwdf_util.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_xml.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_view.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_swin.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>sps_workflow.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_cal.js"></SCRIPT>
	<script language=javascript>
		var cur_params = "";
		<!-----------------------显示汇总结果--------------------------->
		function showReport(){
			cur_params = getP(SearchForm);
			listPageURL.put('reportlist','../GetFilterApp.do?'+getP(SearchForm));
			openPage('reportlist','1');
			sel_appid = "";
		}
		<!------------------------------------------------------------->
		
		var cur_mobid = "";
		var mobwindow = new SimpleWindow();
		function showMob(){
			listPageURL.put('moblist','../GetMFMobileList.do?index=#index#');
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

		<!---------------------------机型查询列表---------------------------------->
		function searchMobByName(){
			listIndex.put('moblist','1');
			var mobName = SearchMobByName.value;
			listPageURL.put('moblist','../SearchMFMobile.do?MobName='+encodeURIComponent(mobName)+'&index=#index#');
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
				alert("<%=LangPage.langPage.getPlease_input()%><%=app.getAliasByFiled("AppName")%>");
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
		<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("mf_app")%></td>
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
			<b>　　　　　</b><%=LangPage.langPage.getSearch("search_mobile")%><input type="text" class="input_edit"  name="SelMobileText" readonly>
				<input type="hidden" name="SelMobile" readonly>
				<a href="#" onclick="showMob();"><img src="../<%=LangPage.langPage.getButton_img_path()%>select_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
			<a href="#" onclick="showReport();"><img src="../<%=LangPage.langPage.getButton_img_path()%>filter_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			</div>
			<div id="div_param" style="display:none;">
			<b>　　　　　</b><%=LangPage.langPage.getSearch("search_screentype")%>

				<select name="Screen" onchange="setScsreen();">
					<option value="1"><%=LangPage.langPage.getSelect("screen_qcif")%></option>
					<option value="2"><%=LangPage.langPage.getSelect("screen_qvga")%></option>
					<option value="4"><%=LangPage.langPage.getSelect("screen_wqvga")%></option>
					<option value="8"><%=LangPage.langPage.getSelect("screen_other")%></option>
				</select>&nbsp;&nbsp;
				<%=mobile.getAliasByFiled("ScreenWidth") %><input type="text" name="ScreenWidth" onkeydown="enterUnsigned();" style="width:50;" value="176">&nbsp;&nbsp;<%=mobile.getAliasByFiled("ScreenHeight") %><input type="text" name="ScreenHeight" onkeydown="enterUnsigned();" style="width:50;" value="220">
			<b>　　　　　</b><%=mobile.getAliasByFiled("MemorySize") %>

				<select name="Memory">
					<option value="500">500K</option>
					<option value="600">600K</option>
					<option value="800">800K</option>
					<option value="1000">1000K</option>
				</select>
			<br>
			<b>　　　　　</b><%=mobile.getAliasByFiled("InputType") %>

				<input type="checkbox" name="Input_Keypad"><%=LangPage.langPage.getSelect("screen_keypad")%>&nbsp;&nbsp;
				<input type="checkbox" name="Input_Touch"><%=LangPage.langPage.getSelect("screen_touch")%>

			<b>　　　　　</b><%=mobile.getAliasByFiled("VREVersion") %>
				<input class="input_edit" style="width:100;" onkeydown="enterFloat();" type="text" name="VreVersion" value="">
			&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
			<a href="#" onclick="showReport();"><img src="../<%=LangPage.langPage.getButton_img_path()%>filter_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
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
			<a href="#" onclick="downloadSelect();"><img src="../<%=LangPage.langPage.getButton_img_path()%>downloadselect_001.gif"  border="0" align="top" vspace="1" /></a>&nbsp;&nbsp;
			<a href="#" onclick="downloadAll();"><img src="../<%=LangPage.langPage.getButton_img_path()%>downloadall_001.gif"  border="0" align="top" vspace="1" /></a>
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

	<!-- 机型列表显示区域 -->
	<div id="tb_mob" class="datainfo">
		<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
			<tr>
				<td class="td_buttonbar" valign="middle" style="font-size:9pt;"><%=LangPage.langPage.getSelect("search_searmobile")%>


					<input type="text" class="input_edit"  name="SearchMobByName">
					<a href="#" onclick="searchMobByName();"><img src="../<%=LangPage.langPage.getButton_img_path()%>search_003.gif"  border="0" align="top" vspace="1" /></a>
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
