<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import="cn.alcatel.wap.db.dao.*"%>
<%@ page import="cn.alcatel.wap.db.*"%>
<%@ page import ="java.util.List"%>
<%@ page import ="java.sql.Date"%>
<%
String user_id = (String)request.getParameter("user_id");
String[] role1= request.getParameterValues("role");
 ///////////////////
  if(role1==null){
    out.print("<script>alert('清输入用户管理权限!');window.location='edit.jsp?user_id="+user_id+"';</script>");
    return;
   }
   //////////////////将数组转化为字符串
 StringBuffer   str   =   new   StringBuffer();
 for(int   i=0;i <role1.length;i++){
   if(i>0)str.append(",");
   str.append(role1[i]);
 }
 ////////////
userDao dao = new userDao();
String temp_role=str.toString();
int uid=Integer.parseInt(user_id);
int y=dao.updateUser(temp_role,uid);
//out.print("temp_role="+temp_role);
//out.print("<br>");
//out.print("uid="+uid);
//out.print("<br>");
//out.print("y="+y);
//out.print("<br>");
if(y==1)out.print("<script>alert('修改成功，请返回!');window.location='index.jsp';</script>");
else out.print("<script>alert('修改失败，请与管理员联系!');window.location='add.jsp';</script>");
 %>
