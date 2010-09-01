<?xml version="1.0" ?>
<!DOCTYPE wml PUBLIC "-//WAPFORUM//DTD WML 1.2//EN" "http://www.wapforum.org/DTD/wml12.dtd">
<%@ page contentType="text/vnd.wap.wml;charset=UTF-8" %>
<%
String uaid = request.getParameter("did");
String lg ="zh2";
String str1 = "";
if(uaid!=null&&uaid.length()>0){
	str1 = "&amp;did="+uaid+"&amp;lg="+lg;
}
%>
<wml>
<card title="My One Touch">
<p>
<anchor ><go href="http://localhost/wapPortal/bk.jsp?id=1<%=str1%>"/>�W·�YӍ��</anchor><br/>
<anchor ><go href="http://localhost/wapPortal/list.jsp?id=12<%=str1%>"/>Eurosport ӰƬ</anchor><br/>
<anchor ><go href="http://localhost/wapPortal/list.jsp?id=13<%=str1%>"/>�����׃��������</anchor><br/>
<anchor ><go href="http://localhost/wapPortal/list.jsp?id=14<%=str1%>"/>��������ӰƬ</anchor><br/>
<anchor ><go href="http://localhost/wapPortal/list.jsp?id=15<%=str1%>"/>�DƬ</anchor><br/>
<anchor ><go href="http://localhost/wapPortal/list.jsp?id=1537<%=str1%>"/>stamps</anchor><br/>
<anchor ><go href="http://localhost/wapPortal/list.jsp?id=16<%=str1%>"/>���</anchor><br/>
<anchor ><go href="http://localhost/wapPortal/list.jsp?id=17<%=str1%>"/>�[�򼰑���</anchor><br/>
<anchor ><go href="http://localhost/wapPortal/list.jsp?id=1539<%=str1%>"/>ݔ���ܴa</anchor><br/>
</p>
</card>
</wml>
