<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangAction"%>
<%@ page import="com.language.langdata.LangDBTable"%>
<%@ page import="com.vogins.sps.db.app.FolderInfo"%>
<%@ page import="com.vogins.sps.db.app.Application"%>
<%
	FolderInfo fol=new FolderInfo();
	Application app=new Application();
%>
<html>

<head>
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
	<TITLE><%=LangPage.langPage.getPageTitle("appfolder")%></TITLE>
	<meta http-equiv="Pragma" content="no-cache">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_main.css">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_swin.css">
	<SCRIPT language="JavaScript" type="text/javascript" src="../js/jwdf_util.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_xml.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_view.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_swin.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>sps_workflow.js"></SCRIPT>
	
	<script language=javascript>
	var cur_flowid = "";
<!---------------------显示产品类别列表（树型）------------------------>
		var cur_trid="";
		var cur_typecode="";
		
		//显示子类别
		function showsubmenu(id){
			if(cur_trid!="" && cur_trid != "0"){
				document.all["td"+cur_trid].style.backgroundColor="";
				document.all["td"+cur_trid].style.color="black";
			}
			if(id != "" && id != "0"){
				document.all["td"+id].style.backgroundColor="#08246b";
				document.all["td"+id].style.color="white";
			}
			cur_trid=id;
			cur_typecode = id;
			if(id != "" && id != "0") {
				showBooks();
			}
			if(id != "" && id != "0"){
				if (document.all["tr"+id].style.display == ""){
					document.all["tr"+id].style.display = "none";
					document.all["img_"+id].src = "../images/folderclosed.gif";
				}else{
					sendG("../GetSubFolder.do?ParentId="+id,getMenuResult);
				}
			}else{
				sendG("../GetSubFolder.do?ParentId=0",getMenuResult);
			}
		}
		function getMenuResult(cartXML){
			var xsl = loadXSL("../xsl/submenulist.xsl");
			if(cur_typecode=="") cur_parentid="0";
			document.all["td0"+cur_typecode].innerHTML = cartXML.transformNode(xsl);
			document.all["tr"+cur_typecode].style.display = "";
			if(cur_typecode != "0")
				document.all["img_"+cur_typecode].src = "../images/folderopen.gif";
		}
<!------------------------------------------------------------->

<!-----------------添加应用类别------------------------------------>
		var newwindow = new SimpleWindow();
		function showNew(){
			newwindow.Create('new_window','<%=LangPage.langPage.getWindowsTitle("app_apptype")%>',280,93,newHTML);
			newwindow.Show();
			NewType.ParentId.value = cur_typecode;
		}
		function newCancel(){
			newwindow.Close();
		}
		function newSubmit(){
			if(NewType.FolderName.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=fol.getAliasByFiled("FolderName")%>");
				NewType.FolderName.focus();
				return false;
			}
			sendP("../AddFolder.do",getP(NewType),newResult);
		}
		function newResult(cartXML){
			var cart = cartXML.getElementsByTagName("result")[0];
			var flowId = cart.getElementsByTagName("info")[0].firstChild.nodeValue;
			cur_flowid = flowId;

			newwindow.Close();
			openWFNodeSet();
		}
<!------------------------------------------------------------->
		
<!---------------------修改产品类别----------------------------->
		var updatewindow = new SimpleWindow();
		function showUpdate(){
			if(cur_typecode=="" || cur_typecode=="0"){
				alert("<%=LangAction.langAction.getNoselect_folder()%>");
				return;
			}else{
				updatewindow.Create('update_window','<%=LangPage.langPage.getWindowsTitle("app_updatetype")%>',280,93,updateHTML);
				updatewindow.Show();
				UpdateType.FolderId.value = cur_typecode;
				sendG("../GetFolderInfo.do?FolderId="+cur_typecode,getUpdate);
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
				if(fields[i].getElementsByTagName("value")[0].firstChild!=null)
					value = fields[i].getElementsByTagName("value")[0].firstChild.nodeValue;
				if(name == "<%=fol.getAliasByFiled("FolderId")%>")	UpdateType.FolderId.value = value;
				else if(name == "<%=fol.getAliasByFiled("FolderName")%>") UpdateType.FolderName.value = value;
				else if(name == "<%=fol.getAliasByFiled("SeqType")%>") UpdateType.SeqType.value = value;
			}
		}
		function updateResult(cartXML){
			var cart = cartXML.getElementsByTagName("result")[0];
			var flowId = cart.getElementsByTagName("info")[0].firstChild.nodeValue;
			cur_flowid = flowId;

			updatewindow.Close();
			openWFNodeSet();

			document.all["applist"].innerHTML = "&nbsp;";
			cur_typecode = "";
			cur_trid = "";
		}
		function updateSubmit(){
			sendP("../UpdateFolder.do",getP(UpdateType),updateResult);
		}
<!------------------------------------------------------------->
		
<!---------------------删除产品类别------------------------->
		function deleteObj(){
			if(cur_typecode=="" || cur_typecode == "0"){
				alert("<%=LangAction.langAction.getNoselect_folder()%>");
				return;
			}else{
				if(confirm("<%=LangPage.langPage.getDelete_confirm()%>")){
					sendG("../DeleteFolder.do?FolderId="+cur_typecode,deleteResult);
				}
			}
		}
		function deleteResult(cartXML){
			var cart = cartXML.getElementsByTagName("result")[0];
			var flowId = cart.getElementsByTagName("info")[0].firstChild.nodeValue;
			cur_flowid = flowId;

			openWFNodeSet();

			document.all["applist"].innerHTML = "&nbsp;";
			cur_typecode = "";
			cur_trid = "";
		}
<!------------------------------------------------------------->

<!----------------读取指定类别的产品----------------------->
		function showBooks(){
			listPageURL.put('applist','../GetFolderAppList.do?FolderId='+cur_typecode+'&index=#index#');
			openPage('applist','1');
		}
<!------------------------------------------------------------->

<!---------------添加一组产品到类别------------------------->
		function newSubmit22(){
			if(cur_typecode == "" || cur_typecode=="0"){
				alert("<%=LangAction.langAction.getNoselect_folder()%>");
				return false;
			}else if(sel_appid == ""){
				alert("<%=LangAction.langAction.getNoselect_app()%>");
				return false;
			}
			sendG("../AddAppToFolder.do?FolderId="+cur_typecode+"&AppId="+sel_appid,newResult22);
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
			if(cur_typecode == "" || cur_typecode == "0"){
				alert("<%=LangAction.langAction.getNoselect_folder()%>");
			}else if(listCurrentKey.get('booklist')==""){
				alert("<%=LangAction.langAction.getNoselect_app()%>");
				return;
			}else{
				if(confirm("<%=LangPage.langPage.getDelete_confirm()%>")){
					sendG("../DeleteAppFolder.do?RecId="+listCurrentKey.get('applist'),deleteResult1);
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
			if(cur_typecode == "" || cur_typecode=="0"){
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
				sendG("../UpAppFolder.do?RecId="+listCurrentKey.get('applist'),renovateResult);
			}
		}
		function renovateResult(cartXML){
			var cart = cartXML.getElementsByTagName("result")[0];
			var flowId = cart.getElementsByTagName("info")[0].firstChild.nodeValue;
			cur_flowid = flowId;

			openWFNodeSet();
		}
		
		function moveDown(){
			if(listCurrentKey.get('applist')==""){
				alert("<%=LangAction.langAction.getNoselect_app()%>");
				return;
			}else{
				sendG("../DownAppFolder.do?RecId="+listCurrentKey.get('applist'),renovateResult);
			}
		}

		function typeUp(){
			if(cur_typecode==""){
				alert("<%=LangAction.langAction.getNoselect_folder()%>");
				return;
			}else{
				sendG("../UpFolder.do?FolderId="+cur_typecode,renovateTypeResult);
			}
		}
		function renovateTypeResult(cartXML){
			var cart = cartXML.getElementsByTagName("result")[0];
			var flowId = cart.getElementsByTagName("info")[0].firstChild.nodeValue;
			cur_flowid = flowId;

			openWFNodeSet();
		}
		
		function typeDown(){
			if(cur_typecode==""){
				alert("<%=LangAction.langAction.getNoselect_folder()%>");
				return;
			}else{
				sendG("../DownFolder.do?FolderId="+cur_typecode,renovateTypeResult);
			}
		}

<!------------------页面初始化---------------------->
		var newHTML = "";
		var updateHTML = "";

		function init(){
			newHTML = document.all["tb_new"].innerHTML;
			document.all["tb_new"].innerHTML = "";
			updateHTML = document.all["tb_update"].innerHTML;
			document.all["tb_update"].innerHTML = "";

			showsubmenu('0');
			initList();
		}

		function initList(){
			listIndex.put('applist','1');
			listPageURL.put('applist','');
			listDetailURL.put('applist','../GetAppFolderInfo.do?RecId=#id#');
			listCurrentId.put('applist','');
			listCurrentKey.put('applist','');
			listDetailWidth.put('applist','400');
			listDetailHeight.put('applist','300');
			listListXSL.put('applist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('applist','../xsl/jwdf_sdetail.xsl');
		}
<!------------------------------------------------------------->
	</script>
</head>

<body onload="init();">
	<!-- 页面标题 -->
	<table class="table_pagetitle" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("appfolder")%></td>
	</tr>
	</table>
	
	<table width="100%" height="100%" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td valign="top">
				
			<!-- 操作按钮 -->
			<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
			<tr>
				<td class="td_buttonbar" valign="middle">
					<a href="#" onclick="showBook();"><img src="../<%=LangPage.langPage.getButton_img_path()%>addapp_001.gif"  border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
					<a href="#" onclick="deleteObj1();"><img src="../<%=LangPage.langPage.getButton_img_path()%>deleteapp_001.gif"  border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
					<a href="#" onclick="moveUp();"><img src="../<%=LangPage.langPage.getButton_img_path()%>up_001.gif"  border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
					<a href="#" onclick="moveDown();"><img src="../<%=LangPage.langPage.getButton_img_path()%>down_001.gif"  border="0" align="top" vspace="1"/></a>
				</td>
			</tr>
			</table>

			<!-- 产品列表显示区域 -->
			<center>
			<div align="center" id="applist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
			</div>
			</center>
		</td>
		<td width="250" class="td_detailcontent1" style="padding-top:5;font-size:9pt;border-left:0.05cm solid #c3c3c3;" valign="top">
			<!-- 操作按钮 -->
			<table width="100%" border="0" cellspacing="0" cellpadding="0" align="center">
			<tr>
				<td class="td_buttonbar" valign="middle">
					<a href="#" onclick="showNew();"><img src="../<%=LangPage.langPage.getButton_img_path()%>add_001.gif"  border="0" align="top" vspace="1"/></a>
					<a href="#" onclick="showUpdate();"><img src="../<%=LangPage.langPage.getButton_img_path()%>update_001.gif"  border="0" align="top" vspace="1"/></a>
					<a href="#" onclick="deleteObj();"><img src="../<%=LangPage.langPage.getButton_img_path()%>delete_001.gif"  border="0" align="top" vspace="1"/></a><br/>
					<a href="#" onclick="typeUp();"><img src="../<%=LangPage.langPage.getButton_img_path()%>up_001.gif"  border="0" align="top" vspace="1"/></a>
					<a href="#" onclick="typeDown();"><img src="../<%=LangPage.langPage.getButton_img_path()%>down_001.gif"  border="0" align="top" vspace="1"/></a>
				</td>
			</tr>
			</table>
			<div id="servlet" class="div_main" style="display:;">
				<table class="table_menuitem" border="0" cellpadding="0" cellspacing="0">
				<tr style="display:none;" id="tr0">
					<td id="td00">&nbsp;</td>
				</tr>
				</table>
			</div>
		</td>
	</tr>
	</table>

	<!-- 添加应用程序类别 -->
	<div align="center" id="tb_new" class="datainfo">
		<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
		<form method="POST" name="NewType" class="editform">
			<input type="hidden" name="ParentId" value="">
		<tr>
			<td class="td_edittitle" width="80"><%=fol.getAliasByFiled("FolderName")%></td>
			<td class="td_editcontent" width="200"><input class="input_edit" style="width:100%;" type="text" name="FolderName"></td>
		</tr>
		<tr>
			<td class="td_edittitle" width="80"><%=fol.getAliasByFiled("SeqType")%></td>
			<td class="td_editcontent" width="200">
				<select name="SeqType">
					<option value="0"><%=LangPage.langPage.getSelect("app_setseq")%></option>
					<option value="1"><%=LangPage.langPage.getSelect("app_bydowncount")%></option>
					<option value="2"><%=LangPage.langPage.getSelect("app_bypaycount")%></option>
					<option value="3"><%=LangPage.langPage.getSelect("app_byaddtime")%></option>
				</select>
			</td>
		</tr>
		</form>
		<tr>
			<td class="td_editbutton" colspan="2">
				<a href="#" onclick="newSubmit();"><img src="../<%=LangPage.langPage.getButton_img_path()%>ok_001.gif"  border="0" align="top" vspace="1" /></a>&nbsp;&nbsp;
				<a href="#" onclick="newCancel();"><img src="../<%=LangPage.langPage.getButton_img_path()%>cancel_001.gif"  border="0" align="top" vspace="1" /></a>
			</td>
		</tr>
		</table>
	</div>

	<!-- 修改应用程序表单 -->
	<div align="center" id="tb_update" class="datainfo">
		<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
		<form method="POST" name="UpdateType" class="editform">
			<input type="hidden" name="FolderId" value="">
		<tr>
			<td class="td_edittitle" width="80"><%=fol.getAliasByFiled("FolderName")%></td>
			<td class="td_editcontent" width="200"><input class="input_edit" style="width:100%;" type="text" name="FolderName"></td>
		</tr>
		<tr>
			<td class="td_edittitle" width="80"><%=fol.getAliasByFiled("SeqType")%></td>
			<td class="td_editcontent" width="200">
				<select name="SeqType">
					<option value="0"><%=LangPage.langPage.getSelect("app_setseq")%></option>
					<option value="1"><%=LangPage.langPage.getSelect("app_bydowncount")%></option>
					<option value="2"><%=LangPage.langPage.getSelect("app_bypaycount")%></option>
					<option value="3"><%=LangPage.langPage.getSelect("app_byaddtime")%></option>
				</select>
			</td>
		</tr>
		</form>
		<tr>
			<td class="td_editbutton" colspan="2">
				<a href="#" onclick="updateSubmit();"><img src="../<%=LangPage.langPage.getButton_img_path()%>ok_001.gif"  border="0" align="top" vspace="1" /></a>&nbsp;&nbsp;
				<a href="#" onclick="updateCancel();"><img src="../<%=LangPage.langPage.getButton_img_path()%>cancel_001.gif"  border="0" align="top" vspace="1" /></a>
			</td>
		</tr>
		</table>
	</div>

	<div align="center" id="download_div" style="display:none;">
		<iframe src="" name="DownloadFrame"></iframe>
	</div>

</body>

</html>
