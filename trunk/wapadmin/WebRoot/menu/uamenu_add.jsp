<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import ="cn.alcatel.wap.db.dao.uamenuDao"%>
<%@ page import ="cn.alcatel.wap.db.*"%>
<%@ page import ="java.util.List"%>
<%@ page import ="java.sql.Date"%>
<%
String id= (String)request.getParameter("id");
String id1= (String)request.getParameter("id1");
String new_r= (String)request.getParameter("new_r");
int id2=Integer.parseInt(id1);
int id3=Integer.parseInt(new_r);
///////////
uamenuDao dao = new uamenuDao();
int k=dao.updateUamenu(id2,id3);
if(k==1)out.print("<script>alert('修改成功，请返回!');window.location='index.jsp?id="+id+"';</script>");
else out.print("<script>alert('修改失败，请与管理员联系!');history.back();</script>");
 %>
