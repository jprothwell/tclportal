<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangAction"%>
<%@ page import="com.language.langdata.LangDBTable"%>
<%@ page import="com.vogins.sps.db.app.MFArea"%>
<%
	MFArea mf = new MFArea();
%>
<html>

<head>
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
	<TITLE><%=LangPage.langPage.getPageTitle("mfarea")%></TITLE>
	<meta http-equiv="Pragma" content="no-cache">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_main.css">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_swin.css">
	<SCRIPT language="JavaScript" type="text/javascript" src="../js/jwdf_util.js"></SCRIPT>
    <SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_xml.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_view.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_swin.js"></SCRIPT>
	<script language=javascript>
<!---------------显示所有CP列表，供用户选择------------------------>
		function showCP(){
			sendG("../GetMFAreaList.do",getCPResult);
		}
		function getCPResult(cartXML){
			var xsl = loadXSL("../xsl/click_list.xsl");
			document.all["arealist"].innerHTML = cartXML.transformNode(xsl);
		}
<!------------------------------------------------------------->

<!---------------选定CP后，读取该CP应用程序的操作---------------->
		cur_cpnum = "";
		cur_cpid = "";
		cur_cpname = "";
		function doClick(id,key,name){
			var tds=document.all["clicktr"+id].getElementsByTagName("td");
			if(cur_cpnum==""){
				for(i=0;i<tds.length;i++){
					tds[i].className="td_listcontent0";
				}
				cur_cpnum=id;
				cur_cpid = key;
				cur_cpname = name;
			}else{
				var tds0=document.all["clicktr"+cur_cpnum].getElementsByTagName("td");
				for(i=0;i<tds0.length;i++){
					tds0[i].className="td_listcontent";
				}
				for(i=0;i<tds.length;i++){
					tds[i].className="td_listcontent0";
				}
				cur_cpnum=id;
				cur_cpid = key;
				cur_cpname = name;
			}
			showApp();
		}
<!------------------------------------------------------------->

		var mfwindow = new SimpleWindow();
		function showPartner(){
			mfwindow.Create('mf_window','<%=LangPage.langPage.getWindowsTitle("mf_selectmf")%>',500,350,mfHTML);
			mfwindow.Show();
			openPage('selectmflist','1');
		}
		
		//选择收费渠道
		function selectMF(){
			if(listCurrentKey.get('selectmflist') == ""){
				alert("<%=LangAction.langAction.getNoselect_mf()%>");
				return;
			}else{
				NewType.MFId.value = listCurrentKey.get('selectmflist');
				mfwindow.Close();
			}
		}

<!-----------------添加应用类别------------------------------------>
		var newwindow = new SimpleWindow();
		function showNew(){
			newwindow.Create('new_window','<%=LangPage.langPage.getWindowsTitle("mf_addmfarea")%>',280,135,newHTML);
			newwindow.Show();
		}
		function newCancel(){
			newwindow.Close();
		}
		function newSubmit(){
			if(NewType.MFId.value == ""){
				alert("<%=LangAction.langAction.getNoselect_mf()%>");
				NewType.MFId.focus();
				return false;
			}
			if(NewType.AreaName.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=mf.getAliasByFiled("AreaName")%>");
				NewType.FolderName.focus();
				return false;
			}
			sendP("../AddMFArea.do",getP(NewType),newResult);
		}
		function newResult(){
			newwindow.Close();
			showCP();
		}
<!------------------------------------------------------------->
		
<!---------------------修改产品类别----------------------------->
		var updatewindow = new SimpleWindow();
		function showUpdate(){
			if(cur_cpid=="" || cur_cpid=="0"){
				alert("<%=LangAction.langAction.getNoselect_mfarea()%>");
				return;
			}else{
				updatewindow.Create('update_window','<%=LangPage.langPage.getWindowsTitle("mf_updatemfarea")%>',280,114,updateHTML);
				updatewindow.Show();
				UpdateType.AreaId.value = cur_cpid;
				sendG("../GetMFAreaInfo.do?AreaId="+cur_cpid,getUpdate);
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
				if(name == "<%=mf.getAliasByFiled("AreaId")%>")	UpdateType.AreaId.value = value;
				else if(name == "<%=mf.getAliasByFiled("AreaName")%>") UpdateType.AreaName.value = value;
				else if(name == "<%=mf.getAliasByFiled("DataSource")%>") UpdateType.DataSource.value = value;
				else if(name == "<%=mf.getAliasByFiled("DataURL")%>") UpdateType.DataURL.value = value;
			}
		}
		function updateResult(){
			updatewindow.Close();
			document.all["applist"].innerHTML = "&nbsp;";
			cur_cpnum = "";
			cur_cpid = "";
			cur_cpname = "";
			showCP();
		}
		function updateSubmit(){
			sendP("../UpdateMFArea.do",getP(UpdateType),updateResult);
		}
<!------------------------------------------------------------->
		
<!---------------------删除产品类别------------------------->
		function deleteObj(){
			if(cur_cpid=="" || cur_cpid == "0"){
				alert("<%=LangAction.langAction.getNoselect_mfarea()%>");
				return;
			}else{
				if(confirm("<%=LangPage.langPage.getDelete_confirm()%>")){
					sendG("../DeleteMFArea.do?AreaId="+cur_cpid,deleteResult);
				}
			}
		}
		function deleteResult(){
			document.all["applist"].innerHTML = "&nbsp;";
			cur_cpnum = "";
			cur_cpid = "";
			cur_cpname = "";
			showCP();
		}
<!------------------------------------------------------------->

<!----------------读取指定CP的应用程序（游戏）----------------------->
		function showApp(index){
			listPageURL.put('applist','../GetAreaAppList.do?AreaId='+cur_cpid+'&index=#index#');
			openPage('applist','1');
		}
<!------------------------------------------------------------->

<!---------------添加一组产品到类别------------------------->
		function newSubmit22(){
			if(cur_cpid == "" || cur_cpid=="0"){
				alert("<%=LangAction.langAction.getNoselect_mfarea()%>");
				return false;
			}else if(sel_appid == ""){
				alert("<%=LangAction.langAction.getNoselect_app()%>");
				return false;
			}
			sendG("../AddAreaApp.do?AreaId="+cur_cpid+"&AppId="+sel_appid,newResult22);
			sel_appid = "";
		}
		function newResult22(){
			openPage('applist',listIndex.get('applist'));
		}
<!------------------------------------------------------------->

<!---------------从类别中删除产品------------------------>
		function deleteObj1(){
			if(cur_cpid == "" || cur_cpid == "0"){
				alert("<%=LangAction.langAction.getNoselect_mfarea()%>");
			}else if(listCurrentKey.get('applist')==""){
				alert("<%=LangAction.langAction.getNoselect_app()%>");
				return;
			}else{
				if(confirm("<%=LangPage.langPage.getDelete_confirm()%>")){
					sendG("../DeleteAreaApp.do?RecId="+listCurrentKey.get('applist'),deleteResult1);
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
			if(cur_cpid == "" || cur_cpid=="0"){
				alert("<%=LangAction.langAction.getNoselect_mfarea()%>");
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

		function moveUp(){
			if(listCurrentKey.get('applist')==""){
				alert("<%=LangAction.langAction.getNoselect_app()%>");
				return;
			}else{
				sendG("../UpAreaApp.do?RecId="+listCurrentKey.get('applist'),renovateResult);
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
				sendG("../DownAreaApp.do?RecId="+listCurrentKey.get('applist'),renovateResult);
			}
		}

<!------------------页面初始化---------------------->
		var newHTML = "";
		var updateHTML = "";
		var mfHTML = "";
		function init(){
			newHTML = document.all["tb_new"].innerHTML;
			document.all["tb_new"].innerHTML = "";
			updateHTML = document.all["tb_update"].innerHTML;
			document.all["tb_update"].innerHTML = "";
			mfHTML = document.all["tb_mf"].innerHTML;
			document.all["tb_mf"].innerHTML = "";

			showCP();
			initList();
		}

		function initList(){
			listIndex.put('applist','1');
			listPageURL.put('applist','');
			listDetailURL.put('applist','../GetAreaAppInfo.do?RecId=#id#');
			listCurrentId.put('applist','');
			listCurrentKey.put('applist','');
			listDetailWidth.put('applist','400');
			listDetailHeight.put('applist','300');
			listListXSL.put('applist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('applist','../xsl/jwdf_sdetail.xsl');

			listIndex.put('selectmflist','1');
			listPageURL.put('selectmflist','../GetMFList.do?index=#index#');
			listDetailURL.put('selectmflist','');
			listCurrentId.put('selectmflist','');
			listCurrentKey.put('selectmflist','');
			listDetailWidth.put('selectmflist','400');
			listDetailHeight.put('selectmflist','320');
			listListXSL.put('selectmflist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('selectmflist','');
			listClickEvent.put('selectmflist',selectMF);
		}
<!------------------------------------------------------------->
	</script>
</head>

<body onload="init();">
	<!-- 页面标题 -->
	<table class="table_pagetitle" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("mfarea")%></td>
	</tr>
	</table>
	
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
					<a href="#" onclick="moveDown();"><img src="../<%=LangPage.langPage.getButton_img_path()%>down_001.gif"   border="0" align="top" vspace="1"/></a>
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
			<!-- 操作按钮 -->
			<table width="100%" border="0" cellspacing="0" cellpadding="0" align="center">
			<tr>
				<td class="td_buttonbar" valign="middle">
					<a href="#" onclick="showNew();"><img src="../<%=LangPage.langPage.getButton_img_path()%>add_001.gif"   border="0" align="top" vspace="1"/></a>
					<a href="#" onclick="showUpdate();"><img src="../<%=LangPage.langPage.getButton_img_path()%>update_001.gif"   border="0" align="top" vspace="1"/></a>
					<a href="#" onclick="deleteObj();"><img src="../<%=LangPage.langPage.getButton_img_path()%>delete_001.gif"   border="0" align="top" vspace="1"/></a>
				</td>
			</tr>
			</table>
			
			<!-- 内容提供商列表显示区域 -->
			<div id="arealist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
			</div>
		</td>
	</tr>
	</table>

	<!-- 添加应用程序类别 -->
	<div align="center" id="tb_new" class="datainfo">
		<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
		<form method="POST" name="NewType" class="editform">
		<tr>
			<td class="td_edittitle" width="80"><%=mf.getAliasByFiled("MFId")%></td>
			<td class="td_editcontent" width="200">
				<input class="input_edit" style="width:60%;" type="text" name="MFId">
				<a href="#" onclick="showPartner();"><img src="../<%=LangPage.langPage.getButton_img_path()%>select_001.gif"   border="0" align="top" vspace="1" /></a>
			</td>
		</tr>
		<tr>
			<td class="td_edittitle" width="80"><%=mf.getAliasByFiled("AreaName")%></td>
			<td class="td_editcontent" width="200"><input class="input_edit" style="width:100%;" type="text" name="AreaName"></td>
		</tr>
		<tr>
			<td class="td_edittitle" width="80"><%=mf.getAliasByFiled("DataSource")%></td>
			<td class="td_editcontent" width="200">
				<select name="DataSource">
					<option value="0"><%=LangPage.langPage.getSelect("mfarea_config")%></option>
					<option value="1"><%=LangPage.langPage.getSelect("mfarea_customize")%></option>
				</select>
			</td>
		</tr>
		<tr>
			<td class="td_edittitle" width="80"><%=mf.getAliasByFiled("DataURL")%></td>
			<td class="td_editcontent" width="200"><input class="input_edit" style="width:100%;" type="text" name="DataURL"></td>
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

	<!-- 修改应用程序表单 -->
	<div align="center" id="tb_update" class="datainfo">
		<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
		<form method="POST" name="UpdateType" class="editform">
			<input type="hidden" name="AreaId" value="">
		<tr>
			<td class="td_edittitle" width="80"><%=mf.getAliasByFiled("AreaName")%></td>
			<td class="td_editcontent" width="200"><input class="input_edit" style="width:100%;" type="text" name="AreaName"></td>
		</tr>
		<tr>
			<td class="td_edittitle" width="80"><%=mf.getAliasByFiled("DataSource")%></td>
			<td class="td_editcontent" width="200">
				<select name="DataSource">
					<option value="0"><%=LangPage.langPage.getSelect("mfarea_config")%></option>
					<option value="1"><%=LangPage.langPage.getSelect("mfarea_customize")%></option>
				</select>
			</td>
		</tr>
		<tr>
			<td class="td_edittitle" width="80"><%=mf.getAliasByFiled("DataURL")%></td>
			<td class="td_editcontent" width="200"><input class="input_edit" style="width:100%;" type="text" name="DataURL"></td>
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
	
	<div id="tb_mf" class="datainfo">
		<div align="center" id="selectmflist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		</div>
	</div>	
</body>

</html>
