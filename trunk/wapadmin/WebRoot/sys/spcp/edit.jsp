<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import="cn.alcatel.wap.db.dao.spadmin"%>
<link href="../../styles/dtree.css" rel="stylesheet" type="text/css" />
<script language="JavaScript">
function checkFields(){
if((document.sp_fm_modify.spname.value.length==0)){
	alert("spname不能为空");
	document.sp_fm_modify.spname.focus();
	return false;
}
}
</script>
<%
   int spid = Integer.parseInt(request.getParameter("spid"));
   spadmin.iddb(spid);
%>
<a href="index.jsp">返回SP-CP管理</a>
<form name="sp_fm_modify" action="../../spedit" method="post"  m-datclass="dtree" onsubmit="return checkFields()">
<table width="60%" border="1" cellspacing="2" cellpadding="2" class="dtree" align="center">
<input type="hidden" name="spid" value="<%=spid%>">

<tr>
<td align="right" width="20%">SP名称: </td>
<td width="80%">
  <input type="text" name="spname" size="10" value="<%=spadmin.spname%>">&nbsp;&nbsp;&nbsp;<font color="red">(*必填)</font></td>
</tr>

<tr>
<td align="right" width="20%">联系人: </td>
<td width="80%">
  <input type="text" name="username" size="10" value="<%=spadmin.username%>"></td>
</tr>

<tr>
<td align="right" width="20%">电话号码: </td>
<td width="80%">
  <input type="text" name="userphone" size="20" value="<%=spadmin.userphone%>"></td>
</tr>


<tr>
<td align="right" width="20%">邮件: </td>
<td width="80%">
  <input type="text" name="useremail" size="20" value="<%=spadmin.useremail%>"></td>
</tr>

<tr>
<td align="right" width="20%">客户电话: </td>
<td width="80%">
  <input type="text" name="clientphone" size="20" value="<%=spadmin.clientphone%>"></td>
</tr>

<tr>
<td align="right" width="20%">页面说明 : </td>
<td width="80%">
 <textarea name="spinfo" cols="30" rows="4" ><%=spadmin.spinfo%></textarea>
</tr>
<tr>

<tr>
<td align="right" width="20%">提交: </td>
<td width="80%"><input type="submit" name="submit" value="提交" ></td>
</tr>

</table>
</form>
