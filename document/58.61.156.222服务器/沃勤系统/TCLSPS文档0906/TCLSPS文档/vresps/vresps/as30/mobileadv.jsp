<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangAction"%>
<%@ page import="com.language.langdata.LangDBTable"%>
<%@ page import="com.vogins.sps.db.as30.advertising"%>
<%
	advertising adv = new advertising();
%>
<html>

<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<TITLE><%=LangPage.langPage.getPageTitle("mobileadv")%></TITLE>
	<meta http-equiv="Pragma" content="no-cache">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_main.css">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_swin.css">
	<SCRIPT language="JavaScript" type="text/javascript" src="../js/jwdf_util.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_xml.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_view.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_swin.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>sps_workflow.js"></SCRIPT>
	<script language=javascript>
	
<!---------------添加------------------------->
		var newwindow = new SimpleWindow();
		function showNew(){
				newwindow.Create('new_window','<%=LangPage.langPage.getWindowsTitle("as_addadv")%>',500,91,newHTML);
				newwindow.Show();
			}
		function newCancel(){
			newwindow.Close();
		}
	  function newSubmit(){
		if(NewAdv.AdvName.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=adv.getAliasByFiled("AdvName")%>");
				NewAdv.AdvName.focus();
				return false;
			}
		if(NewAdv.Url.value == ""){
			alert("<%=LangPage.langPage.getPlease_input()%><%=adv.getAliasByFiled("Url")%>");
			NewAdv.Url.focus();
			return false;
		}
			sendP("../AddAdv.do",getP(NewAdv),newResult);
		}
		function newResult(cartXML){
			var cart = cartXML.getElementsByTagName("result")[0];
			var flowId = cart.getElementsByTagName("info")[0].firstChild.nodeValue;
			cur_flowid = flowId;

			newwindow.Close();
			openWFNodeSet();
		}

<!---------------修改------------------------->
		var updatewindow = new SimpleWindow();
		function showUpdate(){

			if(listCurrentKey.get('advlist')==""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=adv.getAliasByFiled("AdvName")%>");
				return;
			}else{
				updatewindow.Create('update_window','<%=LangPage.langPage.getWindowsTitle("as_updateadv")%>',280,91,updateHTML);
				updatewindow.Show();
				sendG("../GetAdvInfo.do?AdvId="+listCurrentKey.get('advlist'),getUpdate);
			}
		}
		function updateCancel(){
			updatewindow.Close();
		}
		function getUpdate(cartXML){
			UpdateAdv.reset();
		
			var cart = cartXML.getElementsByTagName("result")[0];
			var code = cart.getElementsByTagName("code")[0].firstChild.nodeValue;
			var detail = cart.getElementsByTagName("detail")[0];
			var fields = detail.getElementsByTagName("field");
			var upothertable = document.getElementById("Upothertable");
			var upviewType = document.getElementById("UpviewTable");
			for(i=0;i<fields.length;i++){
				var name = fields[i].getElementsByTagName("name")[0].firstChild.nodeValue;
				var value = "";
				if(fields[i].getElementsByTagName("value")[0].firstChild != null){
					value = fields[i].getElementsByTagName("value")[0].firstChild.nodeValue;
				}
			    if(name == "<%=adv.getAliasByFiled("AdvId")%>") UpdateAdv.AdvId.value = value;
				else if(name == "<%=adv.getAliasByFiled("AdvName")%>") UpdateAdv.AdvName.value = value;
				else if(name == "<%=adv.getAliasByFiled("Url")%>") UpdateAdv.Url.value = value;
				
			}
			
		}
		function updateSubmit(){
			if(UpdateAdv.AdvName.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=adv.getAliasByFiled("AdvName")%>");
				UpdateAdv.AdvName.focus();
				return false;
			}
			if(UpdateAdv.Url.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=adv.getAliasByFiled("Url")%>");
				UpdateAdv.Url.focus();
				return false;
			}
			sendP("../UpdateAdv.do",getP(UpdateAdv),updateResult);
		}
		function updateResult(cartXML){
			var cart = cartXML.getElementsByTagName("result")[0];
			var flowId = cart.getElementsByTagName("info")[0].firstChild.nodeValue;
			cur_flowid = flowId;

			updatewindow.Close();
			openWFNodeSet();
		}
		
<!---------------删除消息------------------------>
		function deleteObj(){
			if(listCurrentKey.get('advlist')==""){
				alert("<%=LangAction.langAction.getNoselect_adv()%>");
				return;
			}else{
				if(confirm("<%=LangPage.langPage.getDelete_confirm()%>")){
					sendG("../DeleteAdv.do?AdvId="+listCurrentKey.get('advlist'),deleteResult);
				}
			}
		}
		function deleteResult(cartXML){
			var cart = cartXML.getElementsByTagName("result")[0];
			var flowId = cart.getElementsByTagName("info")[0].firstChild.nodeValue;
			cur_flowid = flowId;

			openWFNodeSet();
		}


<!------------------页面初始化---------------------->
		var newHTML = "";
		var updateHTML = "";

		
		function init(){
			newHTML = document.all["tb_new"].innerHTML;
			document.all["tb_new"].innerHTML = "";
			updateHTML = document.all["tb_update"].innerHTML;
			document.all["tb_update"].innerHTML = "";
       
			initList();
			openPage('advlist','1');
		}

		function initList(){
		

			listIndex.put('advlist','1');
			listPageURL.put('advlist','../GetAllAdv.do?index=#index#');
			listDetailURL.put('advlist','../GetadvInfo.do?AdvId=#id#');
			listCurrentId.put('advlist','');
			listCurrentKey.put('advlist','');
			listDetailWidth.put('advlist','350');
			listDetailHeight.put('advlist','320');
			listListXSL.put('advlist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('advlist','../xsl/jwdf_sdetail.xsl');
			

		}
		
<!------------------------------------------------------------->
	</script>
</head>

<body onload="init();">
	<!-- 页面标题 -->
	<table class="table_pagetitle" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("mobileadv")%></td>
	</tr>
	</table>
	
	<!-- 操作按钮 -->
	<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_buttonbar" valign="middle">
			<a href="#" onclick="showNew();"><img src="../<%=LangPage.langPage.getButton_img_path()%>add_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a href="#" onclick="showUpdate();"><img src="../<%=LangPage.langPage.getButton_img_path()%>update_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a href="#" onclick="deleteObj();"><img src="../<%=LangPage.langPage.getButton_img_path()%>delete_001.gif"  border="0" align="top" vspace="1"/></a>
		</td>
	</tr>
	</table>


<!-- 广告列表显示区域 -->
<div id="advlist"
	style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
</div>

</div>	
	<!-- 添加adv表单 -->
	<div align="center" id="tb_new" class="datainfo">
		<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
		<form method="POST" name="NewAdv" class="editform">
			<input type="hidden" name="SearchId" value="">
		<tr>
			<td class="td_edittitle" width="80"><%=adv.getAliasByFiled("AdvName")%></td>
			<td class="td_editcontent" width="200"><input class="input_edit" style="width:100%;" type="text" name="AdvName" maxlength="64"></td>
		</tr>
		<tr>
			<td class="td_edittitle" width="80"><%=adv.getAliasByFiled("Url")%></td>
			<td class="td_editcontent" width="200"><input class="input_edit" style="width:100%;" type="text" name="Url"></td>
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

	<!-- 修改adv表单 -->
	<div align="center" id="tb_update" class="datainfo">
		<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
		<form method="POST" name="UpdateAdv" class="editform">
			<input type="hidden" name="AdvId" value="">
		<tr>
			<td class="td_edittitle" width="80"><%=adv.getAliasByFiled("AdvName")%></td>
			<td class="td_editcontent" width="200"><input class="input_edit" style="width:100%;" type="text" name="AdvName" maxlength="64"></td>
		</tr>
		<tr>
			<td class="td_edittitle" width="80"><%=adv.getAliasByFiled("Url")%></td>
			<td class="td_editcontent" width="200"><input class="input_edit" style="width:100%;" type="text" name="Url"></td>
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

</html>
