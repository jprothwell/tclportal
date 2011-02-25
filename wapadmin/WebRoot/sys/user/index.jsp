<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import="cn.alcatel.wap.db.dao.*"%>
<%@ page import="cn.alcatel.wap.db.*"%>
<%@ page import ="java.util.List"%>
<%@ page import ="java.sql.Date"%>
<link href="../../styles/dtree.css" rel="stylesheet" type="text/css" />
<script LANGUAGE="JAVASCRIPT">
function delobject(pid) {
	if (confirm("确定删除")) {
		location="del.jsp?user_id=" + pid;
		return true;
	}
}
</script>
<table width="100%" border="1	" align="center" cellpadding="4" cellspacing="1" class="dtree">
  <tr>
    <td valign="center" colspan="3">用户管理 | <a href="add.jsp">添加用户</a></td>
  </tr>
  <tr><td>账号</td><td>修改</td><td>删除</td>
  </tr>
  <%
  userDao dao = new userDao();
  DBMap[] map =dao.userList();
   if(map != null){
    String href=null;
    for(int i = 0; i < map.length; i++){
      try{
     /////////////////
//  out.println("<tr><td>"+map[i].get("user_name")+"</td>");
//  out.println("<td><a href='edit.jsp?user_id="+map[i].get("user_id")+"'><img src='../img/edit.png' alt='edit' border='0'></a></td>");
//  out.println("<td><a href='javascript:delobject('"+map[i].get("user_id")+"');'><img src='../img/application_delete.png' alt='delete' border='0'></a></td></tr>");
//
  %>
  <tr>
<td><a href='edit.jsp?user_id=<%=map[i].get("user_id")%>'><%=map[i].get("user_name")%></a></td>
<td><a href='edit.jsp?user_id=<%=map[i].get("user_id")%>'><img src='../../img/edit.png' alt='edit' border='0'></a></td>
<td><a href="javascript:delobject('<%=map[i].get("user_id")%>');"><img src='../../img/application_delete.png' alt='delete' border='0'></a></td>
  </tr>
  <%  }catch(Exception e){
        e.printStackTrace();
      }
    }
  }%>
</table>
