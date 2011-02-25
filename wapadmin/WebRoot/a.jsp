<%@ page contentType="text/html; charset=UTF-8" %>
<img border=0 src="testCheck.jsp" alt="看不清？请刷新" width="176" height="30" onclick="this.src=this.src+'?'">
<%
String rand=(String)session.getAttribute("rand");
out.println("rand="+rand);
%>