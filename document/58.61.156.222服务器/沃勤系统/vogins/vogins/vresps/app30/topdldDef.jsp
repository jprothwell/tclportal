<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangAction"%>
<%@ page import="com.language.langdata.LangDBTable"%>
<%@ page import="com.vogins.sps.db.app.DefaultInfo"%>
<%@ page import="com.vogins.sps.db.app30.TopDldInfo"%>
<%
	TopDldInfo top=new TopDldInfo();
%>
<html>

<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<TITLE><%=LangPage.langPage.getPageTitle("topdlddef")%></TITLE>
	<meta http-equiv="Pragma" content="no-cache">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_main.css">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_swin.css">
	<SCRIPT language="JavaScript" type="text/javascript" src="../js/jwdf_util.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_xml.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_view.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_swin.js"></SCRIPT>
	<script language=javascript>
<!--------------------添加总表---------------------->
		var newwindow = new SimpleWindow();
		function showNew(){
			newwindow.Create('new_window','<%=LangPage.langPage.getWindowsTitle("app_addtable")%>',350,123,newHTML);
			newwindow.Show();
		}
		function newCancel(){
			newwindow.Close();
		}
		function newSubmit(){
			if(NewDefault.DefName.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=top.getAliasByFiled("TopDldName")%>");
				NewDefault.DefName.focus();
				return false;
			}
			sendP("../AddTopDefault.do",getP(NewDefault),newResult);
		}
		function newResult(){
			newwindow.Close();
			openPage('deflist',listIndex.get('deflist'));
		}
<!------------------------------------------------------------->
		
<!----------------修改总表------------------------>
		var updatewindow = new SimpleWindow();
		function showUpdate(){
			if(listCurrentKey.get('deflist')==""){
				alert("<%=LangAction.langAction.getNoselect_default()%>");
				return;
			}else{
				updatewindow.Create('update_window','<%=LangPage.langPage.getWindowsTitle("app_updatetable")%>',350,123,updateHTML);
				updatewindow.Show();
				sendG("../GetTopDefInfo.do?DefId="+listCurrentKey.get('deflist'),getUpdate);
			}
		}
		function updateCancel(){
			updatewindow.Close();
		}
		function getUpdate(cartXML){
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
				if(name == "<%=top.getAliasByFiled("TopDldId")%>") UpdateDefault.DefId.value = value;
				if(name == "<%=top.getAliasByFiled("TopDldName")%>") UpdateDefault.DefName.value = value;
				if(name == "<%=top.getAliasByFiled("TopDldDesc")%>") UpdateDefault.DefDesc.value = value;
			}
		}
		function updateResult(){
			updatewindow.Close();
			openPage('deflist',listIndex.get('deflist'));
		}
		function updateSubmit(){
			if(UpdateDefault.DefName.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=top.getAliasByFiled("TopDldName")%>");
				UpdateDefault.DefName.focus();
				return false;
			}
			sendP("../UpdateTopDef.do",getP(UpdateDefault),updateResult);
		}
<!------------------------------------------------------------->
		
<!-------------------删除总表---------------------->
		function deleteObj(){
			if(listCurrentKey.get('deflist')==""){
				alert("<%=LangAction.langAction.getNoselect_default()%>");
				return;
			}else{
				if(confirm("<%=LangPage.langPage.getDelete_confirm()%>")){
					sendG("../DeleteTopDef.do?DefId="+listCurrentKey.get('deflist'),deleteResult);
				}
			}
		}
		function deleteResult(){
			openPage('deflist',listIndex.get('deflist'));
		}
<!------------------------------------------------------------->

		function downloadFile(){
			if(listCurrentKey.get('deflist')==""){
				alert("<%=LangAction.langAction.getNoselect_default()%>");
				return;
			}else{
				window.open("../TopDefDownload.do?DefId="+listCurrentKey.get('deflist'),"DownloadFrame");
			}
		}


		var cur_defid = "";
		
<!---------------控制显示或关闭总表配置窗口------------------------------>
		var viewwindow = new SimpleWindow();
		function ShowContact(){
			initTree();
			if(listCurrentKey.get('deflist')==""){
				alert("<%=LangAction.langAction.getNoselect_default()%>");
				return;
			}else{
				viewwindow.Create('config_app_window','<%=LangPage.langPage.getWindowsTitle("app_tableconfig")%>',600,400,configHTML);
				viewwindow.Show();
				cur_defid = listCurrentKey.get('deflist');
				showSub('foldertree','0','1','0');
			}
		}	

		function showFolderApp(){
			listPageURL.put('applist','../GetTopDefAppList.do?DefId='+cur_defid+'&FolderId='+treeCurrentId.get('foldertree')+'&index=#index#');
			openPage('applist','1');
		}
<!------------------------------------------------------------->
<!---------------添加一组产品到类别------------------------->
		function newSubmit22(){
			if(treeCurrentId.get('foldertree') == "" || treeCurrentId.get('foldertree')=="0"){
				alert("<%=LangAction.langAction.getNoselect_folder()%>");
				return false;
			}else if(sel_appid == ""){
				alert("<%=LangAction.langAction.getNoselect_app()%>");
				return false;
			}
			sendG("../AddTopDefApp.do?DefId="+cur_defid+"&FolderId="+treeCurrentId.get('foldertree')+"&AppId="+sel_appid,newResult22);
			sel_appid = "";
		}
		function newResult22(){
			openPage('applist',listIndex.get('applist'));
		}
<!------------------------------------------------------------->

<!---------------从类别中删除产品------------------------>
		function deleteObj1(){
			if(treeCurrentId.get('foldertree') == "" || treeCurrentId.get('foldertree') == "0"){
				alert("<%=LangAction.langAction.getNoselect_folder()%>");
			}else if(listCurrentKey.get('applist')==""){
				alert("<%=LangAction.langAction.getNoselect_app()%>");
				return;
			}else{
				if(confirm("<%=LangPage.langPage.getDelete_confirm()%>")){
					sendG("../DeleteTopDefApp.do?RecId="+listCurrentKey.get('applist'),deleteResult1);
				}
			}
		}
		function deleteResult1(){
			openPage('applist',listIndex.get('applist'));
		}
<!------------------------------------------------------------->

<!------------------显示产品选择窗口---------------------------->
		var curIndex2 = "1";
		var bookwindow = new SimpleWindow();
		function showBook(){
			if(treeCurrentId.get('foldertree') == "" || treeCurrentId.get('foldertree')=="0"){
				alert("<%=LangAction.langAction.getNoselect_folder()%>");
			}else{
				bookwindow.Create('product_window','<%=LangPage.langPage.getWindowsTitle("app_selectapp")%>',600,400,'');
				openPage2('1');
			}
		}
		function openPage2(index){
			curIndex2 = index;
			sendG("../GetAllAppList.do",getAppResult);
		}
		function getAppResult(cartXML){
			var xsl = loadXSL("../<%=LangPage.langPage.getXsl_path()%>checklist2.xsl");
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

		function moveUp(){
			if(listCurrentKey.get('applist')==""){
				alert("<%=LangAction.langAction.getNoselect_app()%>");
				return;
			}else{
				sendG("../UpTopDefApp.do?RecId="+listCurrentKey.get('applist'),renovateResult);
			}
		}
		function renovateResult(){
			openPage('applist',1);
		}
		
		function moveDown(){
			if(listCurrentKey.get('applist')==""){
				alert("<%=LangAction.langAction.getNoselect_app()%>");
				return;
			}else{
				sendG("../DownTopDefApp.do?RecId="+listCurrentKey.get('applist'),renovateResult);
			}
		}


<!----------------显示产品版本----------------------->
		var detailaccwindow = new SimpleWindow();
		function showVersion(){
			if(listCurrentKey.get('applist') == ''){
				alert('<%=LangAction.langAction.getNoselect_app()%>');
			}else{
				sendG("../GetTopDefVersion.do?RecId="+listCurrentKey.get('applist'),detailResult1);
				detailaccwindow.Create('app_version_window','<%=LangPage.langPage.getWindowsTitle("app_appversion")%>',550,350,'');
			}
		}
		function detailResult1(cartXML){
			var xsl = loadXSL("../xsl/sps_defaultversion.xsl");
			detailaccwindow.Repaint(cartXML.transformNode(xsl));
			detailaccwindow.Show();
		}
<!------------------------------------------------------------->
		
<!--------------添加或删除版本--------------------------->
		function setAppVersion(verid){
			if(document.all["chk"+verid].checked){
				sendG("../AddTopDefVersion.do?RecId="+listCurrentKey.get('applist')+"&VerId="+verid,setVersionResult);
			}else{
				sendG("../DeleteTopDefVer.do?RecId="+listCurrentKey.get('applist')+"&VerId="+verid,setVersionResult);
			}
		}
		function setVersionResult(cartXML){
			detailaccwindow.Close();
			showVersion();
		}
<!------------------------------------------------------------->
		
<!------------------页面初始化---------------------->
		var newHTML = "";
		var updateHTML = "";

		var configHTML ="";
		function init(){
			newHTML = document.all["tb_new"].innerHTML;
			document.all["tb_new"].innerHTML = "";
			updateHTML = document.all["tb_update"].innerHTML;
			document.all["tb_update"].innerHTML = "";

			configHTML = document.all["config_window"].innerHTML;
			document.all["config_window"].innerHTML = "";
			
			initList();
			initTree();
			openPage('deflist','1');
		}

		function initList(){
			listIndex.put('deflist','1');
			listPageURL.put('deflist','../GetTopDefList.do?index=#index#');
			listDetailURL.put('deflist','../GetTopDefInfo.do?DefId=#id#');
			listCurrentId.put('deflist','');
			listCurrentKey.put('deflist','');
			listDetailWidth.put('deflist','400');
			listDetailHeight.put('deflist','320');
			listListXSL.put('deflist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('deflist','../xsl/jwdf_sdetail.xsl');

			listIndex.put('applist','1');
			listPageURL.put('applist','');
			listDetailURL.put('applist','');
			listCurrentId.put('applist','');
			listCurrentKey.put('applist','');
			listDetailWidth.put('applist','400');
			listDetailHeight.put('applist','300');
			listListXSL.put('applist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('applist','../xsl/jwdf_sdetail.xsl');
		}

		function initTree(){
			treeCurrentId.put('foldertree','');
			treeCurrentName.put('foldertree','');
			treeCurrentParent.put('foldertree','');
			treeCurrentChild.put('foldertree','');
			treeLeafInfo.put('foldertree','0');
			treeSubURL.put('foldertree','../GetSubRTFolder.do?ParentId=#id#');
			treeLeafURL.put('foldertree','');
			treeSubXSL.put('foldertree','../xsl/jwdf_subtree.xsl');
			treeLeafXSL.put('foldertree','');
			treeSubEvent.put('foldertree',showFolderApp);
		}
<!------------------------------------------------------------->
	</script>
</head>

<body onload="init();">
	<!-- 页面标题 -->
	<table class="table_pagetitle" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("topdlddef")%></td>
	</tr>
	</table>
	
	<!-- 操作按钮 -->
	<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_buttonbar" valign="middle">
			<a href="#" onclick="showNew();"><img src="../<%=LangPage.langPage.getButton_img_path()%>add_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a href="#" onclick="showUpdate();"><img src="../<%=LangPage.langPage.getButton_img_path()%>update_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a href="#" onclick="deleteObj();"><img src="../<%=LangPage.langPage.getButton_img_path()%>delete_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a href="#" onclick="ShowContact();"><img src="../<%=LangPage.langPage.getButton_img_path()%>setuptable_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a href="#" onclick="downloadFile();"><img src="../<%=LangPage.langPage.getButton_img_path()%>downloadtable_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a href="#" onclick="location.href='topdldFolder.jsp'"><img src="../<%=LangPage.langPage.getButton_img_path()%>listmanage_001.gif"   border="0" align="top" vspace="1"/></a>
		</td>
	</tr>
	</table>

	<!-- 总表列表显示区域 -->
	<div align="center" id="deflist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
	</div>

	<!-- 添加总表表单 -->
	<div id="tb_new" class="datainfo">
		<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
		<form method="POST" name="NewDefault" class="editform">
		<tr>
			<td class="td_edittitle" width="25%"><%=top.getAliasByFiled("TopDldName")%></td>
			<td class="td_editcontent" width="75%"><input class="input_edit" style="width:100%;" maxlength="20" type="text" name="DefName"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=top.getAliasByFiled("TopDldDesc")%></td>
			<td class="td_editcontent"><textarea class="input_textarea" name="DefDesc"></textarea></td>
		</tr>
		</form>
		<tr>
			<td class="td_editbutton" colspan="2">
				<a href="#" onclick="newSubmit();"><img src="../<%=LangPage.langPage.getButton_img_path()%>ok_001.gif"   border="0" align="top" vspace="1" /></a>&nbsp;&nbsp;
				<a href="#" onclick="newCancel();"><img src="../<%=LangPage.langPage.getButton_img_path()%>cancel_001.gif"   border="0" align="top" vspace="1" /></a>
			</td>
		</tr>
		</table>
	</div>

	<!-- 修改总表表单 -->
	<div id="tb_update" class="datainfo">
		<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
		<form method="POST" name="UpdateDefault" class="editform">
			<input type="hidden" name="DefId" value="">
		<tr>
			<td class="td_edittitle" width="25%"><%=top.getAliasByFiled("TopDldName")%></td>
			<td class="td_editcontent" width="75%"><input class="input_edit" style="width:100%;" maxlength="20" type="text" name="DefName"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=top.getAliasByFiled("TopDldDesc")%></td>
			<td class="td_editcontent"><textarea class="input_textarea" name="DefDesc"></textarea></td>
		</tr>
		</form>
		<tr>
			<td class="td_editbutton" colspan="2">
				<a href="#" onclick="updateSubmit();"><img src="../<%=LangPage.langPage.getButton_img_path()%>ok_001.gif"   border="0" align="top" vspace="1" /></a>&nbsp;&nbsp;
				<a href="#" onclick="updateCancel();"><img src="../<%=LangPage.langPage.getButton_img_path()%>cancel_001.gif"   border="0" align="top" vspace="1" /></a>
			</td>
		</tr>
		</table>
	</div>

	<!-- 总表配置窗口 -->
	<div align="center" id="config_window" class="datainfo"><!-- 当前厂商信息信息 -->
		<table width="100%" height="100%" border="0" cellspacing="0" cellpadding="0" align="center">
		<tr>
			<td valign="top">
					
				<!-- 操作按钮 -->
				<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
				<tr>
					<td class="td_buttonbar" valign="middle">
						<a href="#" onclick="showBook();"><img src="../<%=LangPage.langPage.getButton_img_path()%>addapp_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
						<a href="#" onclick="deleteObj1();"><img src="../<%=LangPage.langPage.getButton_img_path()%>deleteapp_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
						<a href="#" onclick="moveUp();"><img src="../<%=LangPage.langPage.getButton_img_path()%>up_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
						<a href="#" onclick="moveDown();"><img src="../<%=LangPage.langPage.getButton_img_path()%>down_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
						<a href="#" onclick="showVersion();"><img src="../<%=LangPage.langPage.getButton_img_path()%>version_002.gif"   border="0" align="top" vspace="1" /></a>
					</td>
				</tr>
				</table>
	
				<!-- 产品列表显示区域 -->
				<center>
				<div align="center" id="applist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
				</div>
				</center>
			</td>
			<td width="150" class="td_detailcontent1" style="padding-top:5;font-size:9pt;border-left:0.05cm solid #c3c3c3;" valign="top">
				<div id="servlet" class="div_main" style="display:;">
					<table class="table_menuitem" border="0" cellpadding="0" cellspacing="0">
					<tr style="display:none;" id="foldertreetr00">
						<td id="foldertreetd000">&nbsp;</td>
					</tr>
					</table>
				</div>
			</td>
		</tr>
		</table>
	</div>	
	
	<div align="center" id="download_div" style="display:none;">
		<iframe src="" name="DownloadFrame"></iframe>
	</div>
	
</body>

</html>
