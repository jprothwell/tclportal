<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import="cn.alcatel.wap.db.dao.*"%>
<%@ page import ="java.util.List"%>
<%@ page import ="java.sql.Date"%>
<link href="../../styles/dtree.css" rel="stylesheet" type="text/css" />
<script language="JavaScript">
function checkFields( ){
if((document.fm_add.user_name.value.length==0)){
	alert("Please enter your login name.");
	document.fm_add.user_name.focus();
	return false ;
}
if((document.fm_add.user_pass.value.length==0) || (document.fm_add.user_pass2.value.length==0)){
	alert("Please enter your password.");
	document.fm_add.user_pass.focus();
	return false ;
}
if((document.fm_add.user_pass.value != document.fm_add.user_pass2.value)){
	alert("Please enter your password right.");
	document.fm_add.user_pass.focus();
	return false ;
}
}
</script>
<table width="100%" border="0" align="center" cellpadding="4" cellspacing="1">
  <tr>
    <td class="dtree"><a href="index.jsp">用户管理</a> | 添加用户</td>
  </tr>
  <tr><td>
    <form name="fm_add" action="add2.jsp" method="post" class="dtree" onsubmit="return checkFields()">
<table width="540" border="1" cellspacing="1" cellpadding="1" class="dtree" >
<tr>
<td align="right">用户名 : </td>
<td><input type="text" name="user_name" size="30"><font color="red">*</font></td>
</tr>
<tr>
<td align="right">password : </td>
<td><input type="password" name="user_pass" size="30"><font color="red">*</font></td>
</tr>
<tr>
<td align="right">confirm password : </td>
<td><input type="password" name="user_pass2" size="30"><font color="red">*</font></td>
</tr>
<tr>
<td colspan="2">&nbsp;</td>
</tr>
<tr>
<td align="right" valign="top">access right : </td>
<td>
<input type="checkbox" name="role" value="1"> Administrator<br>
<input type="checkbox" name="role" value="2">业务管理<br>
<input type="checkbox" name="role" value="3">资源管理<br>
<input type="checkbox" name="role" value="4">系统管理<br>
</td>
</tr>
<tr>
<td colspan="2">&nbsp;</td>
</tr>
<tr>
<td>&nbsp;</td>
<td><input type="submit" name="submit" value="submit"></td>
</tr>
<tr>
<td colspan="2">&nbsp;</td>
</tr>
</table>
</form></td>
  </tr>
</table>
