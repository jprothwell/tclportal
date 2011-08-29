<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangAction"%>
<%@ page import="com.vogins.sps.db.as30.WapList"%>
<%
	WapList wap = new WapList();
%>
<html>

<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<TITLE><%=LangPage.langPage.getPageTitle("waplist")%></TITLE>
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
				newwindow.Create('new_window','<%=LangPage.langPage.getWindowsTitle("as_addwap")%>',500,91,newHTML);
				newwindow.Show();
			}
		function newCancel(){
			newwindow.Close();
		}
		function newSubmit(){
			if(NewWap.WapName.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=wap.getAliasByFiled("WapName")%>");
				NewWap.WapName.focus();
				return false;
			}
			if(NewWap.Url.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=wap.getAliasByFiled("Url")%>");
				NewWap.Url.focus();
				return false;
			}
			sendP("../AddWap.do",getP(NewWap),newResult);
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
		    
			if(listCurrentKey.get('waplist')==""){
				alert("<%=LangAction.langAction.getNoselect_wap()%>");
				return;
			}else{
				updatewindow.Create('update_window','<%=LangPage.langPage.getWindowsTitle("as_updatewap")%>',500,91,updateHTML);
				updatewindow.Show();
				sendG("../GetWapInfo.do?WapId="+listCurrentKey.get('waplist'),getUpdate);
			}
		}
		function updateCancel(){
			updatewindow.Close();
		}
		function getUpdate(cartXML){
			UpdateWap.reset();
		
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
				if(name == "<%=wap.getAliasByFiled("WapId")%>") UpdateWap.WapId.value = value;
				else if(name == "<%=wap.getAliasByFiled("WapName")%>") UpdateWap.WapName.value = value;
				else if(name == "<%=wap.getAliasByFiled("Url")%>") UpdateWap.Url.value = value;
				
			}
			
		}
		function updateSubmit(){
			if(UpdateWap.WapName.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=wap.getAliasByFiled("WapName")%>");
				UpdateWap.WapName.focus();
				return false;
			}
			if(UpdateWap.Url.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=wap.getAliasByFiled("Url")%>");
				UpdateWap.Url.focus();
				return false;
			}
			sendP("../UpdateWap.do",getP(UpdateWap),updateResult);
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
			if(listCurrentKey.get('waplist')==""){
				alert("<%=LangAction.langAction.getNoselect_wap()%>");
				return;
			}else{
				if(confirm("<%=LangPage.langPage.getDelete_confirm()%>")){
					sendG("../DeleteWap.do?WapId="+listCurrentKey.get('waplist'),deleteResult);
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
			openPage('waplist','1');
		}

		function initList(){
			listIndex.put('waplist','1');
			listPageURL.put('waplist','../GetAllWap.do?index=#index#');
			listDetailURL.put('waplist','../GetWapInfo.do?WapId=#id#');
			listCurrentId.put('waplist','');
			listCurrentKey.put('waplist','');
			listDetailWidth.put('waplist','350');
			listDetailHeight.put('waplist','300');
			listListXSL.put('waplist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('waplist','../xsl/jwdf_sdetail.xsl');


		}
		
<!------------------------------------------------------------->
	</script>
</head>

<body onload="init();">
	<!-- 页面标题 -->
	<table class="table_pagetitle" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("waplist")%></td>
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
	<div align="center" id="waplist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
	</div>

	
	<!-- 添加wap表单 -->
	<div align="center" id="tb_new" class="datainfo">
		<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
		<form method="POST" name="NewWap" class="editform">
		<tr>
			<td class="td_edittitle" width="80"><%=wap.getAliasByFiled("WapName")%></td>
			<td class="td_editcontent" width="200"><input class="input_edit" style="width:100%;" type="text" name="WapName" maxlength="20"></td>
		</tr>
		<tr>
			<td class="td_edittitle" width="80"><%=wap.getAliasByFiled("Url")%></td>
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
	<!-- 修改wap表单 -->
	<div align="center" id="tb_update" class="datainfo">
		<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
		<form method="POST" name="UpdateWap" class="editform">
			<input type="hidden" name="WapId" value="">
		<tr>
			<td class="td_edittitle" width="80"><%=wap.getAliasByFiled("WapName")%></td>
			<td class="td_editcontent" width="200"><input class="input_edit" style="width:100%;" type="text" name="WapName" maxlength="20"></td>
		</tr>
		<tr>
			<td class="td_edittitle" width="80"><%=wap.getAliasByFiled("Url")%></td>
			<td class="td_editcontent" width="200"><input class="input_edit" style="width:100%;" type="text" name="Url"></td>
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
</body>

</html>
