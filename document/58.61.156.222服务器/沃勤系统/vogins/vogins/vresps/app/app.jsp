<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangAction"%>
<%@ page import="com.language.langdata.LangDBTable"%>
<%@ page import="com.vogins.sps.db.app.Application"%>
<%@ page import="com.vogins.sps.db.app.CPPartner"%>
<%
	CPPartner cp = new CPPartner();
	Application app = new Application();
%>
<html>

<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<TITLE><%=LangPage.langPage.getPageTitle("app")%></TITLE>
	<meta http-equiv="Pragma" content="no-cache">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_main.css">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_swin.css">
	<SCRIPT language="JavaScript" type="text/javascript" src="../js/jwdf_util.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_xml.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_view.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_swin.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>sps_workflow.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../js/jwdf_check.js"></SCRIPT>
	<script language=javascript>
		var cur_cpid = "";

<!------------------显示CP选择窗口---------------------------->
		var cpwindow = new SimpleWindow();
		function showCP(){
			cpwindow.Create('cp_window','<%=LangPage.langPage.getWindowsTitle("cp_selectcp")%>',600,400,cpHTML);
			cpwindow.Show();
			listPageURL.put('cplist','../GetCPList.do?index=#index#');
			openPage('cplist','1');
		}

		//选择收费渠道
		function selectCP(){
			if(listCurrentKey.get('cplist') == ""){
				alert("<%=LangAction.langAction.getNoselect_cp()%>");
				return;
			}else{
				sendG("../GetCPInfo.do?CPId="+listCurrentKey.get('cplist'),getPDetail);
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
				if(name == "<%=cp.getAliasByFiled("CPId")%>"){
					cur_cpid = value;
				}else if(name == "<%=cp.getAliasByFiled("CPName")%>"){
					document.all["apptitle"].innerHTML = "<%=cp.getAliasByFiled("CPName")%> [" + value + "]";
					showButton();
				}
			}
			cpwindow.Close();
			if(cur_cpid != ""){
				listPageURL.put('applist','../GetAppList.do?CPId='+cur_cpid+'&index=#index#');
				openPage('applist','1');
			}
		}
<!------------------------------------------------------------->
		
<!---------------添加一个新应用程序（游戏）------------------------->
		function showNew(){
			if(cur_cpid == ""){
				alert("<%=LangAction.langAction.getNoselect_cp()%>");
				return;
			}else{
				var newappwindow = new SimpleWindow();
				newappwindow.Create('new_app_window','<%=LangPage.langPage.getWindowsTitle("app_addapp")%>',550,335,'');
				newappwindow.Show();
				newappwindow.OpenURL('upload/newApp.jsp?CPId='+cur_cpid);
			}
		}
<!------------------------------------------------------------->

<!-------------------修改应用程序信息-------------------------->
		function showUpdate(){
			if(listCurrentKey.get('applist')==""){
				alert("<%=LangAction.langAction.getNoselect_app()%>");
				return;
			}else{
				var updateappwindow = new SimpleWindow();
				updateappwindow.Create('update_app_window','<%=LangPage.langPage.getWindowsTitle("app_updateapp")%>',550,335,'');
				updateappwindow.Show();
				var a = new Date();
				updateappwindow.OpenURL('upload/updateApp.jsp?AppId='+listCurrentKey.get('applist')+'&randomid='+a.getTime());
			}
		}
<!------------------------------------------------------------->
		
<!---------------删除应用程序------------------------>
		function deleteObj(){
			if(listCurrentKey.get('applist')==""){
				alert("<%=LangAction.langAction.getNoselect_app()%>");
				return;
			}else{
				if(confirm("<%=LangPage.langPage.getDelete_confirm()%>")){
					sendG("../DeleteApplication.do?AppId="+listCurrentKey.get('applist'),deleteResult);
				}
			}
		}
		function deleteResult(cartXML){
			var cart = cartXML.getElementsByTagName("result")[0];
			var flowId = cart.getElementsByTagName("info")[0].firstChild.nodeValue;
			cur_flowid = flowId;

			openWFNodeSet();
		}
<!------------------------------------------------------------->

<!---------------控制显示或关闭版本管理------------------------------>
		var versionwindow = new SimpleWindow();
		function showVersion(){
			if(listCurrentKey.get('applist')==""){
				alert("<%=LangAction.langAction.getNoselect_app()%>");
				return;
			}else{
				versionwindow.Create('appversion_window','<%=LangPage.langPage.getWindowsTitle("app_appversion")%>',550,400,versionHTML);
				versionwindow.Show();
				sendG("../GetAppInfo.do?AppId="+listCurrentKey.get('applist'),getAppDetail);
			}
		}		
		function getAppDetail(cartXML){
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
				if(name == "<%=app.getAliasByFiled("AppName")%>") document.all["td_AppName"].innerHTML = value;
				else if(name == "<%=app.getAliasByFiled("Price")%>") document.all["td_Price"].innerHTML = value;
				else if(name == "<%=app.getAliasByFiled("TopPrice")%>") document.all["td_TopPrice"].innerHTML = value;
				else if(name == "<%=app.getAliasByFiled("AddTime")%>") document.all["td_CreateTime"].innerHTML = value;
			}
			listPageURL.put('versionlist','../GetVersionList.do?AppId='+listCurrentKey.get('applist')+'&index=#index#');
			openPage('versionlist','1');
		}
<!------------------------------------------------------------->
		
<!---------------添加一个应用程序版本------------------------->
		function showNew1(){
			var newversionwindow = new SimpleWindow();
			newversionwindow.Create('new_version_window','<%=LangPage.langPage.getWindowsTitle("app_addversion")%>',750,562,'');
			newversionwindow.Show();
			newversionwindow.OpenURL('upload/newVersion.jsp?AppId='+listCurrentKey.get('applist'));
		}
<!------------------------------------------------------------->

<!-------------------修改应用程序信息-------------------------->
		function showUpdate1(){
			if(listCurrentKey.get('versionlist')==""){
				alert("<%=LangAction.langAction.getNoselect_appversion()%>");
				return;
			}else{
				var updateversionwindow = new SimpleWindow();
				updateversionwindow.Create('update_version_window','<%=LangPage.langPage.getWindowsTitle("app_updateversion")%>',750,562,'');
				updateversionwindow.Show();
				var a = new Date();
				updateversionwindow.OpenURL('upload/updateVersion.jsp?VerId='+listCurrentKey.get('versionlist')+'&randomid='+a.getTime());
			}
		}
<!------------------------------------------------------------->
		
<!---------------删除版本信息------------------------>
		function deleteObj1(){
			if(listCurrentKey.get('versionlist')==""){
				alert("<%=LangAction.langAction.getNoselect_appversion()%>");
				return;
			}else{
				if(confirm("<%=LangPage.langPage.getDelete_confirm()%>")){
					sendG("../DeleteVersion.do?VerId="+listCurrentKey.get('versionlist'),deleteResult1);
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

<!-----------------------产品版本文件下载----------------------------->
		function downloadFile(){
			if(listCurrentKey.get('versionlist')==""){
				alert("<%=LangAction.langAction.getNoselect_appversion()%>");
				return;
			}else{
				window.open("../AppDownload.do?VerId="+listCurrentKey.get('versionlist'),"DownloadFrame");
			}
		}
<!------------------------------------------------------------->

<!---------------------------按产品查询列表---------------------------------->
		function searchByApp(){
			if(SearchByApp.value == ""){
				alert("没有输入查询关键字!");
			}else{
				document.all["apptitle"].innerHTML = "<%=cp.getAliasByFiled("CPName")%> []";
				listIndex.put('applist','1');
				var appName = SearchByApp.value;
				listPageURL.put('applist','../GetAppListByName.do?AppName='+encodeURIComponent(appName)+'&index=#index#');	//用encodeURIComponent(appName)函数转码为UTF-8
				listDetailURL.put('applist','../GetAppInfo.do?AppId=#id#');
				listCurrentId.put('applist','');
				listCurrentKey.put('applist','');
				listDetailWidth.put('applist','400');
				listDetailHeight.put('applist','300');
				listListXSL.put('applist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
				listDetailXSL.put('applist','../xsl/jwdf_sdetail.xsl');
				openPage('applist','1');
				//显示按钮
				shownew.style.visibility = "visible";
				showupdate.style.visibility = "visible";
				deleteobj.style.visibility = "visible";
				refresh.style.visibility = "visible";
				showversion.style.visibility = "visible";
			}
		}

<!---------------------------按CP查询列表---------------------------------->
		function searchByCP(){
			listIndex.put('cplist','1');
			var cpName = SearchByCP.value;
			listPageURL.put('cplist','../GetCPListByCP.do?CPName='+encodeURIComponent(cpName)+'&index=#index#');	//用encodeURIComponent(appName)函数转码为UTF-8
			listDetailURL.put('cplist','');
			listCurrentId.put('cplist','');
			listCurrentKey.put('cplist','');
			listDetailWidth.put('cplist','400');
			listDetailHeight.put('cplist','300');
			listListXSL.put('cplist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDblClickEvent.put('cplist',selectCP);
			openPage('cplist','1');
		}
<!------------------控制隐藏显示按钮---------------------->
		function showButton(){
			if(cur_cpid==""){
				shownew.style.visibility = "hidden";
				showupdate.style.visibility = "hidden";
				deleteobj.style.visibility = "hidden";
				refresh.style.visibility = "hidden";
				showversion.style.visibility = "hidden";
			}else{
				shownew.style.visibility = "visible";
				showupdate.style.visibility = "visible";
				deleteobj.style.visibility = "visible";
				refresh.style.visibility = "visible";
				showversion.style.visibility = "visible";
			}
		}
<!------------------页面初始化---------------------->
		var versionHTML = "";
		var cpHTML = "";

		function init(){
			versionHTML = document.all["version_window"].innerHTML;
			document.all["version_window"].innerHTML = "";

			cpHTML = document.all["tb_cp"].innerHTML;
			document.all["tb_cp"].innerHTML = "";

			showButton();
			
			initList();
		}

		function initList(){
			listIndex.put('applist','1');
			listPageURL.put('applist','');
			listDetailURL.put('applist','../GetAppInfo.do?AppId=#id#');
			listCurrentId.put('applist','');
			listCurrentKey.put('applist','');
			listDetailWidth.put('applist','400');
			listDetailHeight.put('applist','380');
			listListXSL.put('applist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('applist','../xsl/jwdf_sdetail.xsl');

			listIndex.put('versionlist','1');
			listPageURL.put('versionlist','');
			listDetailURL.put('versionlist','');
			listCurrentId.put('versionlist','');
			listCurrentKey.put('versionlist','');
			listDetailWidth.put('versionlist','300');
			listDetailHeight.put('versionlist','220');
			listListXSL.put('versionlist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('versionlist','');

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
		}
<!------------------------------------------------------------->
	</script>
</head>

<body onload="init();">
	<!-- 页面标题 -->
	<table class="table_pagetitle" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("app")%></td>
	</tr>
	</table>
	
	<!-- 选择的内容提供商 -->
	<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td width="100" class="td_buttonbar" valign="middle" style="font-size:9pt;">
			<a href="#" onclick="showCP();"><img src="../<%=LangPage.langPage.getButton_img_path()%>selectcp_001.gif" border="0" align="top" vspace="1"/></a>
		</td>
		<td id="apptitle" class="td_buttonbar" valign="middle" style="font-size:9pt;"><%=cp.getAliasByFiled("CPName")%> []</td>
		<td class="td_buttonbar" valign="middle" style="font-size:9pt;"><%=LangPage.langPage.getSearch("search_byapp")%>
			<input type="text" class="input_edit" name="SearchByApp">
			<a href="#" onclick="searchByApp();"><img src="../<%=LangPage.langPage.getButton_img_path()%>search_001.gif" border="0" align="top" vspace="1"/></a>
		</td>
	</tr>
	</table>
				
	<!-- 操作按钮 -->
	<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_buttonbar" valign="middle">
			<a id="shownew" href="#" onclick="showNew();"><img src="../<%=LangPage.langPage.getButton_img_path()%>add_001.gif" border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a id="showupdate" href="#" onclick="showUpdate();"><img src="../<%=LangPage.langPage.getButton_img_path()%>update_001.gif" border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a id="deleteobj" href="#" onclick="deleteObj();"><img src="../<%=LangPage.langPage.getButton_img_path()%>delete_001.gif" border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a id="refresh" href="#" onclick="openPage('applist',listIndex.get('applist'));"><img src="../<%=LangPage.langPage.getButton_img_path()%>refresh_001.gif"  border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a id="showversion" href="#" onclick="showVersion();"><img src="../<%=LangPage.langPage.getButton_img_path()%>version_001.gif" border="0" align="top" vspace="1"/></a>
		</td>
		
	</tr>
	</table>

	<!-- 产品列表显示区域 -->
	<div align="center" id="applist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
	</div>
	
	<!-- 版本管理窗口 -->
	<div align="center" id="version_window" class="datainfo">
		<!-- 当前程序信息 -->
		<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
		<tr>
			<td class="td_edittitle" width="15%"><%=app.getAliasByFiled("AppName")%></td>
			<td class="td_editcontent" width="35%" id="td_AppName"></td>
			<td class="td_edittitle" width="15%"><%=app.getAliasByFiled("Price")%></td>
			<td class="td_editcontent" width="35%" id="td_Price"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=app.getAliasByFiled("TopPrice")%></td>
			<td class="td_editcontent" id="td_TopPrice"></td>
			<td class="td_edittitle"><%=app.getAliasByFiled("AddTime")%></td>
			<td class="td_editcontent" id="td_CreateTime"></td>
		</tr>
		</table>
		
		<!-- 操作按钮 -->
		<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
		<tr>
			<td class="td_buttonbar" valign="middle">
				<a href="#" onclick="showNew1();"><img src="../<%=LangPage.langPage.getButton_img_path()%>add_001.gif" border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
				<a href="#" onclick="showUpdate1();"><img src="../<%=LangPage.langPage.getButton_img_path()%>update_001.gif" border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
				<a href="#" onclick="deleteObj1();"><img src="../<%=LangPage.langPage.getButton_img_path()%>delete_001.gif" border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
				<a href="#" onclick="openPage('versionlist',listIndex.get('versionlist'));"><img src="../<%=LangPage.langPage.getButton_img_path()%>refresh_001.gif" border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
				<a href="#" onclick="downloadFile();"><img src="../<%=LangPage.langPage.getButton_img_path()%>download_001.gif" border="0" align="top" vspace="1"/></a>
			</td>
		</tr>
		</table>

		<!-- 版本列表显示区域 -->
		<div id="versionlist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		</div>
	</div>

	<div align="center" id="download_div" style="display:none;">
		<iframe src="" name="DownloadFrame"></iframe>
	</div>
	
	<!-- cp列表显示区域 -->
	<div id="tb_cp" class="datainfo">
		<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
			<tr>
				<td class="td_buttonbar" valign="middle" style="font-size:9pt;"><%=LangPage.langPage.getSearch("search_bycp")%>

					<input type="text" class="input_edit"  name="SearchByCP">
					<a href="#" onclick="searchByCP();"><img src="../<%=LangPage.langPage.getButton_img_path()%>search_003.gif" border="0" align="top" vspace="1" /></a>
				</td>
			</tr>
		</table>
		<div align="center" id="cplist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		</div>
	</div>
</body>

</html>
