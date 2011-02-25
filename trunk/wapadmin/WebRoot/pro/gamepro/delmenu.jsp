<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import ="cn.alcatel.wap.db.dao.gameDao"%>
<%@ page import ="cn.alcatel.wap.db.*"%>
<%@ page import ="java.util.List"%>
<%@ page import ="java.sql.Date"%>
<%
String ua= (String)request.getParameter("ua");
String[] role1= request.getParameterValues("idlist");
/////////将数组转化为字符串
 StringBuffer   str   =   new   StringBuffer();
 for(int i=0;i <role1.length;i++){
   if(i>0)str.append(",");
   str.append(role1[i]);
 }
///////////
gameDao dao = new gameDao();
int k=dao.delallGame(str.toString());
if(k>0)out.print("<script>alert('删除成功，请返回!');window.location='gindex.jsp?ua="+ua+"';</script>");
else out.print("<script>alert('删除失败，请与管理员联系!');history.back();</script>");
 %>
