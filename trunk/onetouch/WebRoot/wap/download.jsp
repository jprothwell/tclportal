<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE wml PUBLIC "-//WAPFORUM//DTD WML 1.1//EN" "http://www.wapforum.org/DTD/wml_1.1.xml">
<%@ page contentType="text/vnd.wap.wml;charset=UTF-8" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<wml>
<card>
<anchor type='onenterforward'>
	<c:if test="${type==0}">
		<go href="<%=request.getContextPath()%>/${javaPath}"/> 
	</c:if>
  
</anchor>
 <c:if test="${type==1}">
 <%
	String url = request.getParameter("url");
	response.sendRedirect(url);
%>
	<!-- 
		<a href="${url}"/> 
		 -->
	</c:if>
</card>
</wml>



