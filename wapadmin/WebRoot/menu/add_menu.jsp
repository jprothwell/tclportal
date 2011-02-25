<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import ="cn.alcatel.wap.db.dao.uamenuDao"%>
<%@ page import ="cn.alcatel.wap.db.*"%>
<%@ page import ="java.util.List"%>
<%@ page import ="java.sql.Date"%>
<%
String ua= (String)request.getParameter("ua");
String qrel= (String)request.getParameter("qrel");
String lg = (String)request.getParameter("lg");
String menuid = (String)request.getParameter("menuid");
int menu_id=Integer.parseInt(menuid);

//out.println("<br>ua="+ua);
//out.println("<br>lg="+lg);
//out.println("<br>menu_id="+menu_id);

///////////
uamenuDao dao = new uamenuDao();
if(dao.checkUamenu(ua,lg,menu_id)){
 out.print("<script>alert('此机型，此栏目已经添加，请返回!');history.back();</script>");
  }
else {
int k=dao.insertUamenu(ua,lg,menu_id);
if(k==1)out.print("<script>alert('输入成功，请返回!');opener.location.reload();history.back();</script>");
else out.print("<script>alert('保存失败，请与管理员联系!');history.back();</script>");
}
%>
