<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangAction"%>
<%@ page import="com.vogins.sps.db.mobile.MFPartner"%>
<%
	MFPartner mfpar = new MFPartner();
%>
<html>

<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<TITLE><%=LangPage.langPage.getPageTitle("UAQuery")%></TITLE>
	<meta http-equiv="Pragma" content="no-cache">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_main.css">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_swin.css">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_cal.css">
	<SCRIPT language="JavaScript" type="text/javascript" src="../js/jwdf_util.js"></SCRIPT>
		<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_xml.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_view.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_swin.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_cal.js"></SCRIPT>
	<script language="javascript">


<!-----------------------显示汇总结果--------------------------->
		function showReport(){
		       if(SearchForm.UserAgent.value==""){
		           alert("<%=LangPage.langPage.getPlease_input()%><%=mfpar.getAliasByFiled("UAId")%>");
		           return false;
		       }
				sendG("../Report_UserAgent.do?"+getP(SearchForm),getResult);
				
		}
		function getResult(cartXML){
		   var cart = cartXML.getElementsByTagName("result")[0];
			var count = cart.getElementsByTagName("info")[0].firstChild.nodeValue;
		   if(count==-1){
		     alert("<%=LangPage.langPage.getUserid_nofind()%>");
		   }else if(count==-2){
		       alert("<%=LangPage.langPage.getUserid_styleerror()%>");
		   }else if(count==0){
		     alert("<%=LangPage.langPage.getUa_no()%>");
		   }else if(count>0){
		     alert("<%=LangPage.langPage.getUa_yes()%>");
		   }
		
		}
<!------------------------------------------------------------->
</script>
</head>
<body>
	<!-- 页面标题 -->
	<table class="table_pagetitle" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("UAQuery")%></td>
	</tr>
	</table>

	<!-- 查询条件 -->
	<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr><td height="5"></td></tr>
	<tr>
		<td valign="middle" style="font-size:9pt;color:#4796ee;">
			<form method="POST" name="SearchForm" class="editform">
		<b><%=LangPage.langPage.getSearch("search_conditions")%></b>UA： <input class="input_edit" type="text" name="UserAgent" style="width:123;" value=""/>
			&nbsp;&nbsp;<a href="#" onclick="showReport();"><img src="../<%=LangPage.langPage.getButton_img_path()%>search_001.gif"   border="0" align="top" vspace="1" /></a>
			</form>
		</td>
	</tr>
	<tr><td valign="middle" style="font-size:9pt;color:#4796ee;"><%=LangPage.langPage.getUa_desc()%></td></tr>
	</table>

</body>
</html>
