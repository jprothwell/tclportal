<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangAction"%>
<%@ page import="com.language.langdata.LangDBTable"%>
<%@ page import="com.vogins.sps.db.as30.MobileSearch"%>
<%
	MobileSearch mob = new MobileSearch();
%>
<html>
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<TITLE><%=LangPage.langPage.getPageTitle("mobilesearch")%></TITLE>
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
				newwindow.Create('new_window','<%=LangPage.langPage.getWindowsTitle("as_addsearch")%>',500,114,newHTML);
				newwindow.Show();
			}
	
		function newCancel(){
			newwindow.Close();
		}
		function newSubmit(){
			if(NewSearch.SearchName.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=mob.getAliasByFiled("SearchName")%>");
				NewSearch.SearchName.focus();
				return false;
			}
			if(NewSearch.Url.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=mob.getAliasByFiled("Url")%>");
				NewSearch.Url.focus();
				return false;
			}else{
				if(NewSearch.Url.value.indexOf("[]")<=0){
					alert("<%=LangPage.langPage.getMobilesearch_alert()%>");
					return false;
				}
			}
			sendP("../AddSearch.do",getP(NewSearch),newResult);
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
		    
			if(listCurrentKey.get('weblist')==""){
				alert("<%=LangAction.langAction.getNoselect_searchengine()%>");
				return;
			}else{
				updatewindow.Create('update_window','<%=LangPage.langPage.getWindowsTitle("as_addsearch")%>',500,114,updateHTML);
				updatewindow.Show();
				sendG("../GetSearchInfo.do?SearchId="+listCurrentKey.get('weblist'),getUpdate);
			}
		}
		function updateCancel(){
			updatewindow.Close();
		}
		function getUpdate(cartXML){
			UpdateSearch.reset();
		
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
				if(name == "<%=mob.getAliasByFiled("SearchId")%>") UpdateSearch.SearchId.value = value;
				else if(name == "<%=mob.getAliasByFiled("SearchName")%>") UpdateSearch.SearchName.value = value;
				else if(name == "<%=mob.getAliasByFiled("Url")%>") UpdateSearch.Url.value = value;
				else if(name == "<%=mob.getAliasByFiled("CodeType")%>") UpdateSearch.codeType.value = value;
				
			}
			
		}
		function updateSubmit(){
			if(UpdateSearch.SearchName.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=mob.getAliasByFiled("SearchName")%>");
				UpdateSearch.SearchName.focus();
				return false;
			}
			if(UpdateSearch.Url.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=mob.getAliasByFiled("Url")%>");
				UpdateSearch.Url.focus();
				return false;
			}else{
				if(UpdateSearch.Url.value.indexOf("[]")<=0){
					alert("<%=LangPage.langPage.getMobilesearch_alert()%>");
					return false;
				}
			}
			
			sendP("../UpdateSearch.do",getP(UpdateSearch),updateResult);
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
			if(listCurrentKey.get('weblist')==""){
				alert("<%=LangAction.langAction.getNoselect_searchengine()%>");
				return;
			}else{
				if(confirm("<%=LangPage.langPage.getDelete_confirm()%>")){
					sendG("../DeleteSearch.do?SearchId="+listCurrentKey.get('weblist'),deleteResult);
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
			openPage('weblist','1');
		}

		function initList(){
			listIndex.put('weblist','1');
			listPageURL.put('weblist','../GetAllSearch.do?index=#index#');
			listDetailURL.put('weblist','../GetSearchInfo.do?SearchId=#id#');
			listCurrentId.put('weblist','');
			listCurrentKey.put('weblist','');
			listDetailWidth.put('weblist','350');
			listDetailHeight.put('weblist','300');
			listListXSL.put('weblist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('weblist','../xsl/jwdf_sdetail.xsl');
		
		  
		}
		
<!------------------------------------------------------------->
	</script>
</head>

<body onload="init();">
	<!-- 页面标题 -->
	<table class="table_pagetitle" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("mobilesearch")%></td>
	</tr>
	</table>
	
	<!-- 操作按钮 -->
	<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_buttonbar" valign="middle">
			<a href="#" onclick="showNew();"><img src="../<%=LangPage.langPage.getButton_img_path()%>add_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a href="#" onclick="showUpdate();"><img src="../<%=LangPage.langPage.getButton_img_path()%>update_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a href="#" onclick="deleteObj();"><img src="../<%=LangPage.langPage.getButton_img_path()%>delete_001.gif"   border="0" align="top" vspace="1"/></a>
		</td>
	</tr>
	</table>

	<!-- 酷站列表显示区域 -->
	<div align="center" id="weblist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
	</div>

	<!-- 添加酷站表单 -->
	<div id="tb_new" class="datainfo">
		<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
		<form method="POST" name="NewSearch" class="editform">
		<tr>
			<td class="td_edittitle" width="25%"><%=mob.getAliasByFiled("SearchName")%></td>
			<td class="td_editcontent" width="75%"><input class="input_edit" style="width:100%;" type="text" maxlength="20" name="SearchName"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=mob.getAliasByFiled("Url")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="Url"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=mob.getAliasByFiled("CodeType")%></td>
			<td class="td_editcontent" width="200"><select name="codeType">
		   <option value="GB2312">GB2312</option>
		   <option value="UTF-8">UTF-8</option>
		   </select>
		</tr>
		</form>
		<tr>
			<td class="td_editbutton" colspan="2">
				<a href="#" onclick="newSubmit();"><img src="../<%=LangPage.langPage.getButton_img_path()%>add_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
				<a href="#" onclick="newCancel();"><img src="../<%=LangPage.langPage.getButton_img_path()%>cancel_001.gif"   border="0" align="top" vspace="1" /></a>
			</td>
		</tr>
		</table>
	</div>

	<!-- 修改酷站表单 -->
	<div id="tb_update" class="datainfo">
		<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
		<form method="POST" name="UpdateSearch" class="editform">
			<input type="hidden" name="SearchId" value="">
		<tr>
			<td class="td_edittitle" width="25%"><%=mob.getAliasByFiled("SearchName")%></td>
			<td class="td_editcontent" width="75%"><input class="input_edit" style="width:100%;" type="text" maxlength="20" name="SearchName"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=mob.getAliasByFiled("Url")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="Url"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=mob.getAliasByFiled("CodeType")%></td>
			<td class="td_editcontent" width="200"><select name="codeType">
		   <option value="GB2312">GB2312</option>
		   <option value="UTF-8">UTF-8</option>
		   </select>
		</tr>	</form>
		<tr>
			<td class="td_editbutton" colspan="2">
				<a href="#" onclick="updateSubmit();"><img src="../<%=LangPage.langPage.getButton_img_path()%>ok_001.gif"   border="0" align="top" vspace="1" /></a>&nbsp;&nbsp;
				<a href="#" onclick="updateCancel();"><img src="../<%=LangPage.langPage.getButton_img_path()%>cancel_001.gif"   border="0" align="top" vspace="1" /></a>
			</td>
		</tr>
		</table>
	</div>
</body>

</html>
