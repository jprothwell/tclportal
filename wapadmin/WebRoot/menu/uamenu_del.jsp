<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import ="cn.alcatel.wap.db.dao.uamenuDao"%>
<%@ page import ="cn.alcatel.wap.db.*"%>
<%@ page import ="java.util.List"%>
<%@ page import ="java.sql.Date"%>
<%
String id= (String)request.getParameter("id");
String id1= (String)request.getParameter("id1");
int id2=Integer.parseInt(id1);

 //out.println("<br>id="+id);
 //out.println("<br>id1="+id1);
///////////
uamenuDao dao = new uamenuDao();
int k=dao.delUamenu(id2);
if(k==1)out.print("<script>alert('删除成功，请返回!');window.location='index.jsp?id="+id+"';</script>");
else out.print("<script>alert('删除失败，请与管理员联系!');history.back();</script>");
 %>
