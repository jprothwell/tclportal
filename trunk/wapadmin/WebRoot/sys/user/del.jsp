<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import="cn.alcatel.wap.db.dao.*"%>
<%@ page import="cn.alcatel.wap.db.*"%>
<%@ page import ="java.util.List"%>
<%@ page import ="java.sql.Date"%>
<%
String user_id = (String)request.getParameter("user_id");
int id=Integer.parseInt(user_id);
//out.println("id="+id);
userDao dao = new userDao();
//out.println("<br>");
//out.println("www="+dao.delUser(id));
if(dao.delUser(id)==1)out.print("<script>alert('删除成功，请返回!');window.location='index.jsp';</script>");
out.print("<script>alert('删除失败，请返回!');window.location='index.jsp';</script>");
 %>
