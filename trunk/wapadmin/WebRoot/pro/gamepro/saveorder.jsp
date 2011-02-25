<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import ="cn.alcatel.wap.db.dao.gameDao"%>
<%@ page import ="cn.alcatel.wap.db.*"%>
<%@ page import ="java.util.List"%>
<%@ page import ="java.sql.Date"%>
<%
gameDao dao = new gameDao();
String idlist= (String)request.getParameter("idlist");
String ua= (String)request.getParameter("ua");
//out.println("idlist="+idlist);
//out.println("ua="+ua);
String[] k=idlist.split(",");
int f=1;
int t=0;
  for(int i=0;i<k.length;i++){
 t=Integer.parseInt(k[i]);
 f = dao.editOrder(t,i);
}
if(f==1) out.print("<script>alert('排序成功');location.href='order.jsp?ua="+ua+"';</script>");
else out.print("<script>alert('排序失败，请与管理员联系!');history.back();</script>");
%>
