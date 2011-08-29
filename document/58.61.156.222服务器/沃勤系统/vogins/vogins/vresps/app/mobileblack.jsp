<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangAction"%>
<%@ page import="com.language.langdata.LangDBTable"%>
<%@ page import="com.vogins.sps.db.mobile.MFPartner"%>
<%@ page import="com.vogins.sps.db.mobile.Mobile"%>
<%
	MFPartner mf = new MFPartner();
	Mobile mob=new Mobile();
%>
<html>

<head>
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
	<TITLE><%=LangPage.langPage.getPageTitle("mobileblack")%></TITLE>
	<meta http-equiv="Pragma" content="no-cache">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_main.css">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_swin.css">
	<SCRIPT language="JavaScript" type="text/javascript" src="../js/jwdf_util.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_xml.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_view.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_swin.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>sps_workflow.js"></SCRIPT>
	
	<script language="javascript">
		var cur_flowid = "";
		<!---------------添加一组产品到类别------------------------->
		function newSubmit22(){
			if(sel_appid == ""){
				alert("<%=LangAction.langAction.getNoselect_app()%>");
				return false;
			}
			sendG("../AddMobileAppBlack.do?MobileId="+document.all['SelMobile'].value+"&AppId="+sel_appid,newResult22);
			sel_appid = "";
		}
		function newResult22(cartXML){
			var cart = cartXML.getElementsByTagName("result")[0];
			var flowId = cart.getElementsByTagName("info")[0].firstChild.nodeValue;
			cur_flowid = flowId;

			openWFNodeSet();
		}
		<!------------------------------------------------------------->

		<!---------------从类别中删除产品------------------------>
		function deleteObj1(){
			if(listCurrentKey.get('applist')==""){
				alert("<%=LangAction.langAction.getNoselect_app()%>");
				return;
			}else{
				if(confirm("<%=LangPage.langPage.getDelete_confirm()%>")){
					sendG("../DelMobileAppBlack.do?MobileId="+document.all['SelMobile'].value+"&AppId="+listCurrentKey.get('applist'),deleteResult1);
				}
			}
		}
		function deleteResult1(cartXML){
			var cart = cartXML.getElementsByTagName("result")[0];
			var flowId = cart.getElementsByTagName("info")[0].firstChild.nodeValue;
			cur_flowid = flowId;

			openWFNodeSet();
		}
		<!------------------------------------------------------------->

		<!------------------显示产品选择窗口---------------------------->
		var curIndex2 = "1";
		var bookwindow = new SimpleWindow();
		function showBook(){
			bookwindow.Create('product_window','<%=LangPage.langPage.getWindowsTitle("app_selectapp")%>',600,400,'');
			openPage2('1');
		}
		function openPage2(index){
			curIndex2 = index;
			sendG("../GetAllAppList.do",getAppResult);
		}
		function getAppResult(cartXML){
			var xsl = loadXSL("../xsl/checklist2.xsl");
			bookwindow.Repaint(cartXML.transformNode(xsl));
			bookwindow.Show();
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
		<!------------------------------------------------------------->

		<!------------------选择手机厂商---------------------------->
		var cur_mfid = "";
		var mfwindow = new SimpleWindow();
		function showMF(){
			SelMobileText.value = "";
			SelMobile.value = "";
			mfwindow.Create('mf_window','<%=LangPage.langPage.getWindowsTitle("cp_selectcp")%>',600,400,mfHTML);
			mfwindow.Show();
			listPageURL.put('mflist','../GetMFList.do?index=#index#');
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
					SelMF.value = value;
				}
				if(name == "<%=mf.getAliasByFiled("MFName")%>"){
					SelMFText.value = value;
				}
			}
			mfwindow.Close();
		}	
		
		
		<!---------------------------根据手机厂商选择机型---------------------------------->
		var cur_mobid = "";
		var mobwindow = new SimpleWindow();
		function showMob(){
			if(SelMF.value==""){
				alert("<%=LangAction.langAction.getNoselect_mf()%>");
				SelMFText.focus();
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
				if(name == "<%=mob.getAliasByFiled("MobileId")%>"){
					cur_mobid = value;
					SelMobile.value = value;
				}
				if(name == "<%=mob.getAliasByFiled("MobileName")%>"){
					SelMobileText.value = value;
				}
			}
			mobwindow.Close();
			showBlackList();
		}

		<!--------------------------显示初始化黑名单列表----------------------------------->
		function showBlackList(){
			listPageURL.put('applist','../GetMobileAppBlack.do?MobileId='+document.all['SelMobile'].value+'&index=#index#');
			openPage('applist','1');
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
			var mfId = SelMF.value;
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
		
		<!------------------页面初始化---------------------->
		var mfHTML = "";
		var mobHTML = "";
		
		function init(){
	
			mfHTML = document.all["tb_mf"].innerHTML;
			document.all["tb_mf"].innerHTML = "";

			mobHTML = document.all["tb_mob"].innerHTML;
			document.all["tb_mob"].innerHTML = "";
			
			//showMF();
			showBlackList();
			
			initList();
		}

		function initList(){
			listIndex.put('applist','1');
			listPageURL.put('applist','../GetMobileAppBlack.do?index=#index#');
			listDetailURL.put('applist','../GetAppInfo.do?AppId=#id#');
			listCurrentId.put('applist','');
			listCurrentKey.put('applist','');
			listDetailWidth.put('applist','400');
			listDetailHeight.put('applist','300');
			listListXSL.put('applist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('applist','../xsl/jwdf_sdetail.xsl');
			
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
		<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("mobileblack")%></td>
	</tr>
	</table>

	<table align="center" width="100%" border="0" cellpadding="0" cellspacing="0">
		<tr>
			<td class="td_bottomline" style="font-size:9pt;padding-left:20;padding-top:5;padding-bottom:5;">
				<%=LangPage.langPage.getSearch("search_mf")%><input type="text" class="input_edit"  name="SelMFText" readonly>
				<input type="hidden" name="SelMF">
				<a href="#" onclick="showMF();"><img src="../<%=LangPage.langPage.getButton_img_path()%>select_001.gif"   border="0" align="top" vspace="1" /></a>
				&nbsp;&nbsp;<%=LangPage.langPage.getSearch("search_mobile")%><input type="text" class="input_edit"  name="SelMobileText" readonly>
				<input type="hidden" name="SelMobile" readonly>
				<a href="#" onclick="showMob();"><img src="../<%=LangPage.langPage.getButton_img_path()%>select_001.gif"   border="0" align="top" vspace="1" /></a>
			</td>
		</tr>
	</table>
	
	<table width="100%" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td valign="top">
				
			<!-- 操作按钮 -->
			<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
			<tr>
				<td class="td_buttonbar" valign="middle">
					<a href="#" onclick="showBook();"><img src="../<%=LangPage.langPage.getButton_img_path()%>addapp_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
					<a href="#" onclick="deleteObj1();"><img src="../<%=LangPage.langPage.getButton_img_path()%>deleteapp_001.gif"   border="0" align="top" vspace="1"/></a>
				</td>
			</tr>
			</table>

			<!-- 产品列表显示区域 -->
			<center>
			<div align="center" id="applist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
			</div>
			</center>
		</td>
	</tr>
	</table>
	
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
