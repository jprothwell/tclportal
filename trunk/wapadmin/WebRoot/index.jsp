<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="checksession.jsp"%>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<title>wap后台管理系统</title>
<style type="text/css">
<!--
body {
	margin-left: 0px;
	margin-top: 0px;
	margin-right: 0px;
	margin-bottom: 0px;
}
-->
</style>
<script language="JavaScript">
function loadHref( ){
window.rigth.location="right.jsp";
}
</script>
<link href="styles/base.css" rel="stylesheet" type="text/css" />
</head>
<body>
<table width="100%" border="0" align="center" cellpadding="0" cellspacing="0">
  <tr>
    <td height="72" valign="top"><table width="100%" border="0" cellspacing="0" cellpadding="0">
  <tr>
    <td background="img/di_top.gif"><table width="100%" border="0" cellpadding="0" cellspacing="0">
        <tr>
          <td width="192"><img src="img/title.jpg" width="192" height="71" /></td>
          <td width="77"><img src="img/02.jpg" width="77" height="71" /></td>
          <td align="right" valign="bottom"><table border="0" cellspacing="0" cellpadding="0">
            <tr>
<%
String urlName="left1.jsp";
if(tickn1==1)urlName="left1.jsp";
else{
if(tickn2==1)urlName="left1.jsp";
if(tickn3==1)urlName="left2.jsp";
if(tickn4==1)urlName="left3.jsp";
}
if(tickn1==1 || tickn2==1){
  %>
<td width="60" align="left"><a href='left1.jsp' target='left'><img src="img/b_01.gif" width="56" height="49" border="0" /></a></td>
<%}
if(tickn1==1 || tickn3==1){
%>
<td width="60" align="left"><a href='left2.jsp' target='left'><img src="img/b_02.gif" width="56" height="49" border="0" /></a></td>
<%}
if(tickn1==1 || tickn4==1){
%>
<td width="60" align="left"><a href='left3.jsp' target='left'><img src="img/b_03.gif" width="56" height="49" border="0" /></a></td>
<%}
%>
<td width="70" align="left">
<a href="#" onclick="javascript:window.close();"><img src="img/b_04.gif" width="56" height="49" border="0" /></a></td>
            </tr>
          </table></td>
        </tr>
      </table></td>
  </tr>
</table>
<table width="100%" border="0" cellspacing="0" cellpadding="0">
  <tr>
    <td background="img/dot_01.gif"><img src="img/dot_01.gif" width="3" height="1" /></td>
  </tr>
</table></td>
  </tr>
</table>
<table width="100%" border="0" align="center" cellpadding="0" cellspacing="1">
  <tr>
    <td valign="top" bgcolor="#FFFFFF"><table width="100%" border="0" cellspacing="0" cellpadding="0">
      <tr>
        <td width="22%" align="center" valign="top">
          <table width="100%" border="0" cellspacing="0" cellpadding="0">
            <tr>
              <td valign="top"><iframe frameborder="0" name="left" src="<%=urlName%>" scrolling="yes" width="100%" height="480"></iframe></td>
            </tr>
          </table>
          </td>
        <td width="78%" align="center" valign="top"><table width="100%" border="0" cellspacing="0" cellpadding="0">
          <tr>
            <td valign="top"><iframe frameborder="0" name="right" src="right.jsp" width="100%" height="480" scrolling="auto"></iframe></td>
          </tr>
        </table>
          </td>
      </tr>
    </table></td>
  </tr>
</table>
<table width="100%" border="0" cellspacing="0" cellpadding="0">
  <tr>
    <td align="center"><iframe frameborder="0" name="dizhi" src="dizhi.jsp" scrolling="no" width="100%" height="65"></iframe></td>
  </tr>
</table>
</body>
</html>
