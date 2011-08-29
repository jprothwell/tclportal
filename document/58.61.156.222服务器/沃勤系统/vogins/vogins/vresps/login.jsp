<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<html>
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<title><%=LangPage.langPage.getLogin_title()%></title>
	<link rel="stylesheet" type="text/css" href="css/jwdf_login.css">
	<link rel="stylesheet" type="text/css" href="css/jwdf_main.css">
	<SCRIPT language="JavaScript" type="text/javascript" src="js/jwdf_util.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="js/jwdf_xml.js"></SCRIPT>
	<script language="javascript">
		function checkinput(){
			if(document.all["UserName"].value == ""){
				alert('<%=LangPage.langPage.getPlease_input()%><%=LangPage.langPage.getLogin_username()%>');
				document.all["UserName"].focus();
				return false;
			}else if(document.all["LoginPass"].value == ""){
				alert('<%=LangPage.langPage.getPlease_input()%><%=LangPage.langPage.getLogin_password()%>');
				document.all["LoginPass"].focus();
				return false;
			}
			sendP("login.do",getParas(),loginResult);
		}

		function getParas(){
			var para = "UserName="+document.all["UserName"].value + "&LoginPass="+document.all["LoginPass"].value;
			return para;
		}
		
		function cancelinput(){
			document.all["UserName"].value = "";
			document.all["LoginPass"].value = "";
			window.close();
		}

		function enteruserid(){
			if(event.keyCode==13){
				document.all["LoginPass"].focus();
			}
		}
		
		function enterpassword(){
			if(event.keyCode==13){
				checkinput();
			}
		}

		function loginResult(){
			window.open("index.jsp","_self");
		}
	</script>
</head>
	
<body onload="document.all['UserName'].focus();">
  <table align="center" width="96%" border="0" cellpadding="0" cellspacing="0" class="top">
    <tr>
	  <td align="center" valign="middle" style="color:blue;font-size:14pt;"><b>Vogins VRE SPS</b></td>
    </tr>
  </table>
  <table align="center" width="96%" border="0" cellpadding="0" cellspacing="0" class="bg">
    <tr>
      <td align="center" valign="middle"><table align="center" width="316" border="0" cellspacing="6" cellpadding="0">
        <tr>
          <td width="152" align="center"><img src="images/login_zhanghao.gif" height="43" /></td>
          <td width="146" align="center"><img src="images/login_mima.gif" height="43" /></td>
        </tr>
        <tr>
          <td align="left" nowrap="nowrap" class="ini"><%=LangPage.langPage.getLogin_username()%>
            <input  type="text" name="UserName" onkeypress="enteruserid();" class="in"/></td>
          <td align="left" nowrap="nowrap" class="ini"><%=LangPage.langPage.getLogin_password()%>
            <input type="password" name="LoginPass" onkeypress="enterpassword();" class="in" /></td>
        </tr>
        <tr>
          <td height="36" align="right" valign="middle" class="bt"><a href="#" onclick="checkinput();"><img src="<%=LangPage.langPage.getButton_img_path()%>login_001.jpg" width="78" height="21" border="0" /></a></td>
          <td height="36" align="left" valign="middle" class="bt"><a href="#" onclick="cancelinput();"><img src="<%=LangPage.langPage.getButton_img_path()%>login_002.jpg" width="78" height="21" border="0" /></a></td>
        </tr>
      </table></td>
    </tr>
  </table>
</html>
