<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import="cn.alcatel.wap.db.dao.questionDao"%>
<link href="../../styles/dtree.css" rel="stylesheet" type="text/css" />
<script language="JavaScript">
function checkFields(){
if((document.sp_fm_modify.info.value.length==0)){
	alert("回复内容不能为空");
	document.sp_fm_modify.info.focus();
	return false;
}
}
</script>
<%
   int id = Integer.parseInt(request.getParameter("id"));
  cn.alcatel.wap.db.DBMap[] spinfo=questionDao.get_modify_info(id);
%>
<a href="admin.jsp">游戏问题咨询</a>
<form name="sp_fm_modify" action="saveedit.jsp" method="post"  m-datclass="dtree" onsubmit="return checkFields()">
<table width="60%" border="1" cellspacing="2" cellpadding="2" class="dtree" align="center">
<input type="hidden" name="id" value="<%=id%>">

<tr>
<td align="right" width="20%">咨询内容: </td>
<td width="80%"><%=spinfo[0].get("y_content")%>
  </td>
</tr>

<tr>
<td align="right" width="20%">联系方式: </td>
<td width="80%"><%=spinfo[0].get("y_contact")%>
  </td>
</tr>

<tr>
<td align="right" width="20%">处理方法: </td>
<td width="80%">
 <textarea name="info" cols="30" rows="4" ><%=spinfo[0].get("info")%></textarea></td>
</tr>
<tr>
<td align="right" width="20%">提交: </td>
<td width="80%"><input type="submit" name="submit" value="提交" ></td>
</tr>
</table>
</form>
