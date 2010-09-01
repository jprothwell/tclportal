<?xml version="1.0" ?>
<!DOCTYPE wml PUBLIC "-//WAPFORUM//DTD WML 1.2//EN" "http://www.wapforum.org/DTD/wml12.dtd">
<%@ page contentType="text/vnd.wap.wml;charset=UTF-8" %>
<%
String uaid = request.getParameter("did");
String lg ="zh1";
String str1 = "";
if(uaid!=null&&uaid.length()>0){
	str1 = "&amp;did="+uaid+"&amp;lg="+lg;
}
%>
<wml>
<card title="My One Touch">
<p>
<anchor ><go href="http://localhost/wapPortal/bk.jsp?id=3580<%=str1%>"/>Web Box</anchor><br/>
<anchor ><go href="http://localhost/wapPortal/list.jsp?id=1534<%=str1%>"/>Eurosport 视频片段</anchor><br/>
<anchor ><go href="http://localhost/wapPortal/list.jsp?id=1535<%=str1%>"/>和弦旋律</anchor><br/>
<anchor ><go href="http://localhost/wapPortal/list.jsp?id=1536<%=str1%>"/>Alcatel 视频片段</anchor><br/>
<anchor ><go href="http://localhost/wapPortal/list.jsp?id=1537<%=str1%>"/>图片</anchor><br/>
<anchor ><go href="http://localhost/wapPortal/list.jsp?id=1538<%=str1%>"/>相框</anchor><br/>
<anchor ><go href="http://localhost/wapPortal/list.jsp?id=1539<%=str1%>"/>游戏及应用</anchor><br/>
</p>
</card>
</wml>
