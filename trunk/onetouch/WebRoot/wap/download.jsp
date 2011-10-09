<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE wml PUBLIC "-//WAPFORUM//DTD WML 1.1//EN" "http://www.wapforum.org/DTD/wml_1.1.xml">
<%@ page contentType="text/vnd.wap.wml;charset=UTF-8" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<wml>
<card>
<onevent type='onenterforward'>
	<c:if test="${type==0}">
		<go href="<%=request.getContextPath()%>/${javaPath}"/> 
	</c:if>
   <c:if test="${type==1}">
		<go href="${url}"/> 
	</c:if>
</onevent>
</card>
</wml>



