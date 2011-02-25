<%@ page contentType="text/html; charset=utf-8" %>
<%@ page import="java.util.*,cn.alcatel.wap.db.*" %>
<%@ page import="java.util.*,cn.alcatel.wap.db.dao.*" %>
<%
  int id =Integer.parseInt(request.getParameter("id"));
  String info = (String)request.getParameter("info");
  questionDao dao=new questionDao();
  int i=dao.updateQ(id,info);
if(i==1)out.print("<script>alert('修改成功，请返回!');window.location='admin.jsp';</script>");
else out.print("<script>alert('修改失败，请与管理员联系!');history.back();</script>");
%>
