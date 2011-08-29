<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangAction"%>
<%@ page import="com.language.langdata.LangDBTable"%>
<%@ page import="com.vogins.sps.db.mobile.MFPartner"%>
<%
	MFPartner mf = new MFPartner();
%>
<html>

<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<TITLE><%=LangPage.langPage.getPageTitle("submf")%></TITLE>
	<meta http-equiv="Pragma" content="no-cache">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_main.css">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_swin.css">
	<SCRIPT language="JavaScript" type="text/javascript" src="../js/jwdf_util.js"></SCRIPT>
		<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_xml.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_view.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_swin.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>sps_workflow.js"></SCRIPT>
	<script language=javascript>
	
<!----------------添加手机厂商---------------------------->
		var newwindow = new SimpleWindow();
		function showNew(){
			newwindow.Create('new_window','<%=LangPage.langPage.getWindowsTitle("mobile_addsonmf")%>',350,261,newHTML);
			newwindow.Show();
		}
		function newCancel(){
			newwindow.Close();
		}
		
		function newSubmit(){
			if(NewPartner.PartnerName.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=mf.getAliasByFiled("MFName")%>");
				NewPartner.PartnerName.focus();
				return false;
			}
			sendP("../AddSubMF.do",getP(NewPartner),newResult);
		}
		function newResult(cartXML){
			newwindow.Close();
			openPage('mflist','1');
		}
<!------------------------------------------------------------->

<!---------------修改手机厂商--------------------------------->
		var updatewindow = new SimpleWindow();
		function showUpdate(){
			if(listCurrentKey.get('mflist')==""){
				alert("<%=LangAction.langAction.getNoselect_submf()%>");
				return;
			}else{
				updatewindow.Create('update_window','<%=LangPage.langPage.getWindowsTitle("mobile_updatesonmf")%>',350,261,updateHTML);
				updatewindow.Show();
				sendG("../GetSubMFInfo.do?SubMFId="+listCurrentKey.get('mflist'),getUpdate);
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
				if(name == "<%=mf.getAliasByFiled("MFId")%>") UpdatePartner.SubMFId.value = value;
				else if(name == "<%=mf.getAliasByFiled("MFName")%>") UpdatePartner.PartnerName.value = value;
				else if(name == "<%=mf.getAliasByFiled("ShortName")%>") UpdatePartner.ShortName.value = value;
				else if(name == "<%=mf.getAliasByFiled("Address")%>") UpdatePartner.Address.value = value;
				else if(name == "<%=mf.getAliasByFiled("Phone")%>") UpdatePartner.Phone.value = value;
				else if(name == "<%=mf.getAliasByFiled("Fax")%>") UpdatePartner.Fax.value = value;
				else if(name == "<%=mf.getAliasByFiled("HomePage")%>") UpdatePartner.HomePage.value = value;
				else if(name == "<%=mf.getAliasByFiled("SystemUser")%>") UpdatePartner.SystemUser.value = value;
			}
		}
	
		function updateSubmit(){
			if(UpdatePartner.PartnerName.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=mf.getAliasByFiled("MFName")%>");
				UpdatePartner.PartnerName.focus();
				return false;
			}
			sendP("../UpdateSubMF.do",getP(UpdatePartner),updateResult);
		}
		
		function updateResult(cartXML){
			updatewindow.Close();
			openPage('mflist','1');
		}
<!------------------------------------------------------------->

<!----------------删除手机厂商--------------------------->
		function deleteObj(){
			if(listCurrentKey.get('mflist')==""){
				alert("<%=LangAction.langAction.getNoselect_submf()%>");
				return;
			}else{
				if(confirm("<%=LangPage.langPage.getDelete_confirm()%>")){
					sendG("../DeleteSubMF.do?SubMFId="+listCurrentKey.get('mflist'),deleteResult);
				}
			}
		}
		function deleteResult(cartXML){
			openPage('mflist','1');
		}
<!------------------------------------------------------------->

		<!------------------页面初始化---------------------->
		var newHTML = "";
		var updateHTML = "";
		
		function init(){
			newHTML = document.all["tb_new"].innerHTML;
			document.all["tb_new"].innerHTML = "";
			updateHTML = document.all["tb_update"].innerHTML;
			document.all["tb_update"].innerHTML = "";
            
			initList();
			openPage('mflist','1');
		}

		function initList(){
			listIndex.put('mflist','1');
			listPageURL.put('mflist','../GetSubMFList.do?index=#index#');
			listDetailURL.put('mflist','../GetSubMFInfo.do?SubMFId=#id#');
			listCurrentId.put('mflist','');
			listCurrentKey.put('mflist','');
			listDetailWidth.put('mflist','350');
			listDetailHeight.put('mflist','300');
			listListXSL.put('mflist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('mflist','../xsl/jwdf_sdetail.xsl');
		}
		<!------------------------------------------------------------->
	</script>
</head>

<body onload="init();">
	<!-- 页面标题 -->
	<table class="table_pagetitle" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("submf")%></td>
	</tr>
	</table>
	
	<!-- 操作按钮 -->
	<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_buttonbar" valign="middle">
			<a href="#" onclick="showNew();"><img src="../buttons/add_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a href="#" onclick="showUpdate();"><img src="../buttons/update_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a href="#" onclick="deleteObj();"><img src="../buttons/delete_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
		</td>
	</tr>
	</table>

	<!-- 手机厂商列表显示区域 -->
	<div align="center" id="mflist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
	</div>

	<!-- 添加手机厂商表单 -->
	<div id="tb_new" class="datainfo">
		<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
		<form method="POST" name="NewPartner" class="editform">
		<tr>
			<td class="td_edittitle" width="25%"><%=mf.getAliasByFiled("MFName") %></td>
			<td class="td_editcontent" width="75%"><input class="input_edit" style="width:100%;" type="text" name="PartnerName"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=mf.getAliasByFiled("ShortName") %></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="ShortName"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=mf.getAliasByFiled("Address") %></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="Address"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=mf.getAliasByFiled("Phone") %></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="Phone"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=mf.getAliasByFiled("Fax") %></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="Fax"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=mf.getAliasByFiled("HomePage") %></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="HomePage"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=mf.getAliasByFiled("SystemUser") %></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text"  name="SystemUser"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=mf.getAliasByFiled("PassWord") %></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text"  name="SystemPassword"></td>
		</tr>
		</form>
		<tr>
			<td class="td_editbutton" colspan="2">
				<a href="#" onclick="newSubmit();"><img src="../<%=LangPage.langPage.getButton_img_path()%>next_001.gif"   border="0" align="top" vspace="1" /></a>
				<a href="#" onclick="newCancel();"><img src="../<%=LangPage.langPage.getButton_img_path()%>cancel_001.gif"   border="0" align="top" vspace="1" /></a>
			</td>
		</tr>
		</table>
	</div>

	<!-- 修改手机厂商表单 -->
	<div id="tb_update" class="datainfo">
		<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
		<form method="POST" name="UpdatePartner" class="editform">
			<input type="hidden" name="SubMFId" value="">
		<tr>
			<td class="td_edittitle" width="25%"><%=mf.getAliasByFiled("MFName") %></td>
			<td class="td_editcontent" width="75%"><input class="input_edit" style="width:100%;" type="text" name="PartnerName"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=mf.getAliasByFiled("ShortName") %></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="ShortName"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=mf.getAliasByFiled("Address") %></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="Address"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=mf.getAliasByFiled("Phone") %></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="Phone"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=mf.getAliasByFiled("Fax") %></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="Fax"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=mf.getAliasByFiled("HomePage") %></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="HomePage"></td>
		</tr>
		</tr>
		<tr>
			<td class="td_edittitle"><%=mf.getAliasByFiled("SystemUser") %></td>
			<td class="td_editcontent"><input class="input_edit" readonly style="width:100%;" type="text"  name="SystemUser"></td>
		</tr>
		</form>
		<tr>
			<td class="td_editbutton" colspan="2">
				<a href="#" onclick="updateSubmit();"><img src="../<%=LangPage.langPage.getButton_img_path()%>next_001.gif"   border="0" align="top" vspace="1" /></a>
				<a href="#" onclick="updateCancel();"><img src="../<%=LangPage.langPage.getButton_img_path()%>cancel_001.gif"   border="0" align="top" vspace="1" /></a>
			</td>
		</tr>
		</table>
	</div>
</body>

</html>
