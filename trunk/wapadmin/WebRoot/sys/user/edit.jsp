<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import="cn.alcatel.wap.db.dao.*"%>
<%@ page import="cn.alcatel.wap.db.*"%>
<%@ page import ="java.util.List"%>
<%@ page import ="java.sql.Date"%>
<%
String user_id = (String)request.getParameter("user_id");
int id=Integer.parseInt(user_id);
int tick1=0;
int tick2=0;
int tick3=0;
int tick4=0;
int tick5=0;
int tick6=0;
  userDao dao = new userDao();
  DBMap[] map =dao.userInfo(id);
  String d = map[0].get("role").toString();
  String[] k=d.split(",");
  for(int i=0;i<k.length;i++){
    if(k[i].equals("1"))tick1=1;
    if(k[i].equals("2"))tick2=1;
    if(k[i].equals("3"))tick3=1;
    if(k[i].equals("4"))tick4=1;
    if(k[i].equals("5"))tick5=1;
    if(k[i].equals("6"))tick6=1;
    }
%>
<link href="../../styles/dtree.css" rel="stylesheet" type="text/css" />
<table width="100%" border="0" align="center" cellpadding="4" cellspacing="1">
  <tr>
    <td class="dtree"><a href="index.jsp">用户管理</a> | <a href="add.jsp">添加用户</a> | 修改用户权限</td>
  </tr>
  <tr><td>
    <form name="fm_add" action="edit2.jsp" method="post" class="dtree">
<input type="hidden" name="user_id" value="<%=user_id%>"/>
<table width="540" border="0" cellspacing="2" cellpadding="2" class="dtree" >
<tr>
<td align="right">用户名 : </td>
<td><input type="text" name="user_name" size="59" value="<%=map[0].get("user_name")%>" disabled="disabled"></td>
</tr>
<tr>
<td align="right" valign="top">access right : </td>
<td>
<input type="checkbox" name="role" value="1" <%if(tick1==1)out.print("checked");%>> Administrator<br>
<input type="checkbox" name="role" value="2" <%if(tick2==1)out.print("checked");%>>业务管理<br>
<input type="checkbox" name="role" value="3" <%if(tick3==1)out.print("checked");%>>资源管理<br>
<input type="checkbox" name="role" value="4" <%if(tick4==1)out.print("checked");%>>系统管理<br>
</td>
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
