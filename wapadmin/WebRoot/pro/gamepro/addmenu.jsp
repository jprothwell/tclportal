<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import ="cn.alcatel.wap.db.dao.gameDao"%>
<%@ page import ="cn.alcatel.wap.db.*"%>
<%@ page import ="java.util.List"%>
<%@ page import ="java.sql.Date"%>
<%
String ua= (String)request.getParameter("ua");
String[] role1= request.getParameterValues("idlist");
gameDao dao = new gameDao();
int gameid=0;
int k=0;
/////////将数组转化为字符串
 for(int i=0;i <role1.length;i++){
  gameid=Integer.parseInt(role1[i]);
 k=dao.insertGame(ua,gameid);
 }
///////////
if(k>0)out.print("<script>alert('添加成功，请返回!');window.location='gindex.jsp?ua="+ua+"';</script>");
else out.print("<script>alert('添加失败，请与管理员联系!');history.back();</script>");
 %>
