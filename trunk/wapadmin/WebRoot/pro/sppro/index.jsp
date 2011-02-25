<%@ page contentType="text/html; charset=UTF-8" %>
<%@ page import="cn.alcatel.wap.db.DBInfo"%>
<%
int kindid=0;
%>
<link href="../../styles/dtree.css" rel="stylesheet" type="text/css" />
<script LANGUAGE="JAVASCRIPT">
function delobject(pid) {
	if (confirm("确定删除")) {
		location="del.jsp?user_id=" + pid;
		return true;
	}
}
</script>
<table width="100%" border="1" align="center" cellpadding="1" cellspacing="1" class="dtree">
  <tr>
    <td colspan="3"><%=DBInfo.IMAGE_INFO[kindid]%>图片管理 | <a href="add.jsp?kindid=<%=kindid%>">添加图片</a></td>
  </tr>
  <tr><td colspan="3" align="center">共88张图片 2/9页 首页|上页|下页|末页</td>
  <tr><td>预览图</td><td>属性</td><td>操作</td>
  </tr>
  <tr>
<td width="15%"><img src="../../img/01.gif"/></td>
<td width="70%">
图片名称：100012<br>
图片规格：128*160<br>
适合国家：en,fr<br>
录入时间：2009-7-18
</td>
<td width="15%"><a href='edit.jsp?user_id='><img src='../../img/edit.png' alt='edit' border='0'></a>  <a href="javascript:delobject('<%%>');"><img src='../../img/application_delete.png' alt='delete' border='0'></a></td>
  </tr>
    <tr>
<td><img src="../../img/01.gif"/></td>
<td>
图片名称：100012<br>
图片规格：128*160<br>
适合国家：en,fr<br>
录入时间：2009-7-18
</td>
<td><a href='edit.jsp?'><img src='../../img/edit.png' alt='edit' border='0'></a>  <a href="javascript:delobject('');"><img src='../../img/application_delete.png' alt='delete' border='0'></a></td>
  </tr>
 <tr><td align="center" colspan="3">共88张图片 2/9页 首页|上页|下页|末页</td>
</table>
