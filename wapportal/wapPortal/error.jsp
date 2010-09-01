<%@ page isErrorPage="true"%>
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE wml PUBLIC "-//WAPFORUM//DTD WML 1.1//EN" "http://www.wapforum.org/DTD/wml_1.1.xml">
<%@ page contentType="text/vnd.wap.wml;charset=UTF-8" %>
<%@ page import="cn.funstar.wap.util.*,cn.funstar.wap.action.*" %>
<%
String lg = MobileParse.getAcceptLanguage(request);
Message message= new Message(lg);
%>
<wml>
<card>
<p>
<br/><%=message.busy()%>
</p>
<p>
<a href="welcome.jsp"><%=message.home()%></a>
</p>
</card>
</wml>
