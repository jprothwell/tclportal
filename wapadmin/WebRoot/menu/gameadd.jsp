<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import ="cn.alcatel.wap.db.dao.resourceDao"%>
<%@ page import ="cn.alcatel.wap.db.*"%>
<%@ page import ="java.util.List"%>
<%@ page import ="java.sql.Date"%>
<%
//////////
String contentid= request.getParameter("contentid");
String id= (String)request.getParameter("id");
int id1=Integer.parseInt(id);
resourceDao dao = new resourceDao();
int k=dao.editResource(id1,contentid);
if(k==1)out.print("<script>alert('添加成功，请返回!');history.back();;</script>");
else out.print("<script>alert('添加失败，请与管理员联系!');history.back();</script>");
//
%>
