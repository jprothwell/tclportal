<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import ="java.util.List"%>
<%@ page import ="java.sql.Date"%>
<%@ page import="cn.alcatel.wap.db.DBInfo"%>
<link href="../../styles/dtree.css" rel="stylesheet" type="text/css" />
<script language="JavaScript">
function checkFields(){
if((document.sp_fm_add.spname.value.length==0)){
	alert("SP名称不能为空");
	document.sp_fm_add.spname.focus();
	return false;
}
}
</script>
<table width="100%" border="1" align="center" cellpadding="4" cellspacing="1">
  <tr>
    <td class="dtree"><a href="index.jsp">SP-CP信息管理</a> | SP-CP信息添加 </td>
  </tr>
  <tr><td>
    <form name="sp_fm_add" action="../../spadd" method="post"  m-datclass="dtree" onsubmit="return checkFields()">
<table width="100%" border="0" cellspacing="2" cellpadding="2" class="dtree" >

<tr>
<td align="right" width="20%">SP名称: </td>
<td width="80%">
  <input type="text" name="spname" size="20">&nbsp;&nbsp;&nbsp;<font color="red">(*必填)</font></td>
</tr>

<tr>
<td align="right" width="20%">联系人: </td>
<td width="80%">
  <input type="text" name="username" size="20"></td>
</tr>

<tr>
<td align="right" width="20%">电话号码: </td>
<td width="80%">
  <input type="text" name="userphone" size="20"></td>
</tr>


<tr>
<td align="right" width="20%">邮件: </td>
<td width="80%">
  <input type="text" name="useremail" size="20"></td>
</tr>

<tr>
<td align="right" width="20%">客户电话: </td>
<td width="80%">
  <input type="text" name="clientphone" size="20"></td>
</tr>

<tr>
<td align="right" width="20%">页面说明 : </td>
<td width="80%">
 <textarea name="spinfo" cols="30" rows="4"></textarea>
</tr>
<tr>

<tr>
<td width="20%">&nbsp;</td>
<td width="80%"><input type="submit" name="submit" value="提交"></td>
</tr>
</table>
</form></td>
  </tr>
</table>
