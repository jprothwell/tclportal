<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangAction"%>
<%@ page import="com.vogins.sps.db.mobile.Permission"%>
<%@ page import="com.vogins.sps.db.mobile.MFPartner"%>
<%@ page import="com.vogins.sps.db.mobile.Mobile"%>
<%
	Permission perm = new Permission();
	MFPartner mf = new MFPartner();
	Mobile mobile = new Mobile();
%>
<html>

<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<TITLE><%=LangPage.langPage.getPageTitle("perm")%></TITLE>
	<meta http-equiv="Pragma" content="no-cache">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_main.css">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_swin.css">
	<SCRIPT language="JavaScript" type="text/javascript" src="../js/jwdf_util.js"></SCRIPT>
		<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_xml.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_view.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_swin.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>sps_workflow.js"></SCRIPT>
	<script language=javascript>
		<!--------------------修改授权------------------------------>
		var updatewindow = new SimpleWindow();
		function showUpdate(){
			if(listCurrentKey.get('permissionlist')==""){
				alert("<%=LangAction.langAction.getNoselect_perm()%>");
				return;
			}else{
				updatewindow.Create('update_window','<%=LangPage.langPage.getWindowsTitle("mobile_updateperm")%>',480,239,updateHTML);
				updatewindow.Show();
				sendG("../GetPermissionInfo.do?RecId="+listCurrentKey.get('permissionlist'),getUpdate);
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
				UpdatePermission.RecId.value = listCurrentKey.get('permissionlist');
				if(name == "<%=perm.getAliasByFiled("OpIndex")%>") UpdatePermission.OpIndex.value = value;
				else if(name == "<%=perm.getAliasByFiled("TypeName")%>") UpdatePermission.TypeName.value = value;
				else if(name == "<%=perm.getAliasByFiled("EnName")%>") UpdatePermission.EnName.value = value;
				else if(name == "<%=perm.getAliasByFiled("FuncList")%>") UpdatePermission.FuncList.value = value;
				else if(name =="<%=perm.getAliasByFiled("OpPermission")%>"){
					if(value=="1"){
						UpdatePermission.OpPermission[0].checked=true;
					}else{
						UpdatePermission.OpPermission[1].checked=true;
					}
				}    
				else if(name == "<%=perm.getAliasByFiled("Remark")%>") UpdatePermission.Remark.value = value;
			}
		}
		function updateResult(){
			updatewindow.Close();
			openPage('permissionlist',listIndex.get('permissionlist'));
		}
		function updateSubmit(){
			if(UpdatePermission.OpPermission.value == ""){
				alert("<%=LangAction.langAction.getNoselect_perm()%>");
				return false;
			}
			sendP("../UpdatePermission.do",getP(UpdatePermission),updateResult);
		}
		<!------------------------------------------------------------->
		
		<!--------------------生成默认授权----------------------------->
		function generatePerm(){
			if(document.all['SelMobile'].value=="" || document.all['SelMobile'].value=="0"){
				alert("<%=LangAction.langAction.getNoselect_mobile()%>");
				return;
			}else{
				sendG("../GeneratePerm.do?MobileId="+document.all['SelMobile'].value,generateResult);
			}
		}
		function generateResult(){
			showPermission();
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
				if(name == "<%=mobile.getAliasByFiled("MobileId")%>"){
					cur_mobid = value;
					SelMobile.value = value;
				}
				if(name == "<%=mobile.getAliasByFiled("MobileName")%>"){
					SelMobileText.value = value;
				}
			}
			mobwindow.Close();
			showPermission();
		}
		

		<!----------------------------显示初始化列表--------------------------------->
		function showPermission(){
			listPageURL.put('permissionlist','../GetPermissionList.do?MobileId='+document.all['SelMobile'].value+'&index=#index#');
			openPage('permissionlist','1');
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
		var updateHTML = "";
		var mfHTML = "";
		var mobHTML = "";
		
		function init(){
			updateHTML = document.all["tb_update"].innerHTML;
			document.all["tb_update"].innerHTML = "";

			mfHTML = document.all["tb_mf"].innerHTML;
			document.all["tb_mf"].innerHTML = "";

			mobHTML = document.all["tb_mob"].innerHTML;
			document.all["tb_mob"].innerHTML = "";

			//showMF();
			showPermission();
			
			initList();
		}
		
		function initList(){
			listIndex.put('permissionlist','1');
			//listPageURL.put('permissionlist','../GetPermissionList.do?MobileId=0&index=#index#');
			listDetailURL.put('permissionlist','');
			listCurrentId.put('permissionlist','');
			listCurrentKey.put('permissionlist','');
			listDetailWidth.put('permissionlist','250');
			listDetailHeight.put('permissionlist','65');
			listListXSL.put('permissionlist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('permissionlist','');

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
	<table class="table_pagetitle" border="0" cellspacing="0" cellpadding="0">
		<tr>
			<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("perm")%></td>
		</tr>
	</table>
	
	<!-- 查看条件显示区 -->
	<table align="center" width="100%" border="0" cellpadding="0" cellspacing="0">
		<tr>
			<td class="td_bottomline" style="font-size:9pt;padding-left:20;padding-top:5;padding-bottom:5;">
			<%=LangPage.langPage.getSearch("search_mf")%><input type="text" class="input_edit"  name="SelMFText" readonly>
				<input type="hidden" name="SelMF">
				<a href="#" onclick="showMF();"><img src="../<%=LangPage.langPage.getButton_img_path()%>choice_001.gif"   border="0" align="top" vspace="1" /></a>
				&nbsp;&nbsp;<%=LangPage.langPage.getSearch("search_mobile")%><input type="text" class="input_edit"  name="SelMobileText" readonly>
				<input type="hidden" name="SelMobile" readonly>
				<a href="#" onclick="showMob();"><img src="../<%=LangPage.langPage.getButton_img_path()%>choice_001.gif"   border="0" align="top" vspace="1"  /></a>
			</td>
		</tr>
	</table>
	
	
	<!-- 操作按钮 -->
	<table align="center" width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
		<tr>
			<td class="td_buttonbar" valign="middle">
				<a href="#" onclick="showUpdate();"><img src="../<%=LangPage.langPage.getButton_img_path()%>update_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
				<a href="#" onclick="generatePerm();"><img src="../<%=LangPage.langPage.getButton_img_path()%>fond_001.gif"   border="0" align="top" vspace="1"/></a>
			</td>
		</tr>
	</table>

	<!-- 角色列表显示区域 -->
	<div align="center" id="permissionlist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;"></div>
	
	<!-- 修改角色表单 -->
	<div align="center" id="tb_update"  class="datainfo">
		<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
		<form method="POST" name="UpdatePermission" class="editform">
			<input type="hidden" name="RecId" value="">
		<tr>
			<td class="td_edittitle" width="25%"><%=perm.getAliasByFiled("OpIndex")%></td>
			<td class="td_editcontent" width="75%"><input class="input_edit" readonly style="width:100%;" type="text" name="OpIndex"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=perm.getAliasByFiled("TypeName")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="TypeName"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=perm.getAliasByFiled("EnName")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="EnName"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=perm.getAliasByFiled("FuncList")%></td>
			<td class="td_editcontent"><textarea class="input_textarea" name="FuncList"></textarea></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=perm.getAliasByFiled("OpPermission")%></td>
			<td class="td_editcontent">
				<input type="radio" name="OpPermission" value="1"><%=LangPage.langPage.getSelect("perm_agree")%>
				<input type="radio" name="OpPermission" value="0"><%=LangPage.langPage.getSelect("perm_stop")%>
			</td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=perm.getAliasByFiled("Remark")%></td>
			<td class="td_editcontent"><textarea class="input_textarea" name="Remark"></textarea></td>
		</tr>
		</form>
		<tr>
			<td class="td_editbutton" colspan="2">
				<a href="#" onclick="updateSubmit();"><img src="../<%=LangPage.langPage.getButton_img_path()%>ok_001.gif"  border="0" align="top" vspace="1" /></a>&nbsp;&nbsp;
				<a href="#" onclick="updateCancel();"><img src="../<%=LangPage.langPage.getButton_img_path()%>cancel_001.gif"   border="0" align="top" vspace="1" /></a>
			</td>
		</tr>
		</table>
	</div>
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
					<a href="#" onclick="searchMobByName();"><img src="../<%=LangPage.langPage.getButton_img_path()%>search_003.gif"  border="0" align="top" vspace="1" /></a>
				</td>
			</tr>
		</table>
		<div align="center" id="moblist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		</div>
	</div>
</html>
