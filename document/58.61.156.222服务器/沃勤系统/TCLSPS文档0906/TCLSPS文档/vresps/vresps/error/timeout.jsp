<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<html>

<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<TITLE><%=LangPage.langPage.getPageTitle("timeout")%></TITLE>
	<meta http-equiv="Pragma" content="no-cache">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_main.css">
	<script language=javascript>
		function relogin(){
			if(window.parent != null){
				window.parent.location.href="../login.jsp";
			}else{
				window.location.href="../login.jsp";
			}
		}
	</script>
</head>

<body>
	<table class="table_pagetitle" border="0" cellspacing="0" cellpadding="0">
	<tr>
		<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("timeout")%></td>
	</tr>
	</table>
	<br>
	<table width="100%" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_buttonbar" valign="middle" style="font-size:9pt;color:red;">
			&nbsp;&nbsp;<%=LangPage.langPage.getTimeout_message()%>&nbsp;&nbsp;<a href="#" onclick="relogin();"><img src="../<%=LangPage.langPage.getButton_img_path()%>relogin_001.gif"  border="0" align="top" vspace="1" /></a>&nbsp;&nbsp;		
		</td>
	</tr>
	</table>
</body>

</html>
