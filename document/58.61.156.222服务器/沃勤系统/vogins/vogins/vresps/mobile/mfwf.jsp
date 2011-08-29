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
	<TITLE><%=LangPage.langPage.getPageTitle("mfwf")%></TITLE>
	<meta http-equiv="Pragma" content="no-cache">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_main.css">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_swin.css">
	<SCRIPT language="JavaScript" type="text/javascript" src="../js/jwdf_util.js"></SCRIPT>
		<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_xml.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_view.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_swin.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>sps_workflow.js"></SCRIPT>
	<script language=javascript>

<!----------------添加客户ID---------------------------->
	var newwindow = new SimpleWindow();
	function showNew(){
		newwindow.Create('new_window','<%=LangPage.langPage.getWindowsTitle("cw_newua")%>',300,70,newHTML);
		newwindow.Show();
	}
	function newCancel(){
		newwindow.Close();
	}
	
	function newSubmit(){
		if(NewUACode.UACode.value == ""){
			alert("<%=LangPage.langPage.getPlease_input()%><%=mf.getAliasByFiled("UAId")%>");
			NewUACode.UACode.focus();
			return false;
		}
		sendP("../AddMFUACode.do",getP(NewUACode),newResult);
	}
	function newResult(){
		newwindow.Close();
		alert("<%=LangAction.langAction.getSuccess_operate()%>");
		window.open("../workflow/view.htm","JWDFMainFrame");
	}
<!------------------------------------------------------------->

		function showMF(){
			sendG("../GetMFInfo_MF.do",getMFResult);
		}

		function getMFResult(cartXML){
			var xsl = loadXSL("../xsl/jwdf_sdetail.xsl");
			var html = cartXML.transformNode(xsl);
			document.all["mfinfo"].innerHTML = html;
		}
		
<!------------------页面初始化---------------------->
		var newHTML = "";
		
		function init(){
			newHTML = document.all["tb_new"].innerHTML;
			document.all["tb_new"].innerHTML = "";
            
			showMF();
		}
<!------------------------------------------------------------->
	</script>
</head>

<body onload="init();">
	<!-- 页面标题 -->
	<table class="table_pagetitle" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("mfwf")%></td>
	</tr>
	</table>
	
	<!-- 操作按钮 -->
	<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_buttonbar" valign="middle">
			<a href="#" onclick="showNew();"><img src="../<%=LangPage.langPage.getButton_img_path()%>newid_001.gif"  border="0" align="top" vspace="1" /></a>
		</td>
	</tr>
	</table>

	<!-- 手机厂商信息显示区域 -->
	<center>
	<div align="center" id="mfinfo" style="width:80%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
	</div>
	</center>

	<!-- 新客户ID申请 -->
	<div id="tb_new" class="datainfo">
		<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
		<form method="POST" name="NewUACode" class="editform">
			<input type="hidden" name="MFId" value="">
		<tr>
			<td class="td_edittitle" width="25%"><%=mf.getAliasByFiled("UAId")%></td>
			<td class="td_editcontent" width="75%"><input class="input_edit" style="width:100%;" type="text" name="UACode"></td>
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
</body>

</html>
