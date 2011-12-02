<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE wml PUBLIC "-//WAPFORUM//DTD WML 1.1//EN" "http://www.wapforum.org/DTD/wml_1.1.xml">
<%@ page contentType="text/vnd.wap.wml;charset=UTF-8" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@ taglib uri="http://struts.apache.org/tags-bean" prefix="bean" %>
<wml>
<head> 
<meta http-equiv="Cache-Control" content="no-Cache"/> 
<meta http-equiv="Cache-Control" content="max-age=0"/> 
</head> 
<card title="<bean:message key="wap.index.title"/> ${kindName}"> 

<p>
<a href="index.jsp?did=${did}&amp;pageid=${pageid}&amp;language=${language}"><bean:message key="wap.index.home"/></a> - ${kindName}<br/>
-----------------<br/>
<c:choose>
	<c:when test="${numCount>0}">
       <c:forEach items="${list}" var="obj" varStatus="statu">
	${statu.count+(pagenum-1)*gamenum}.<a href="<%=request.getContextPath()%>/gameinfo.do?action=queryGameinfo&amp;did=${did}&amp;pageid=${pageid}&amp;language=${language}&amp;gameId=${obj.id}">${obj.gamename}</a><br/>	
       </c:forEach>
	</c:when>
	<c:otherwise>
		<bean:message key="wap.list.gameInfo"/><br/>
	</c:otherwise>
</c:choose>

<c:if test="${checkNextPage==1}">
<a href="<%=request.getContextPath()%>/index.do?action=menulist&amp;kindid=${kindid}&amp;did=${did}&amp;pageid=${pageid}&amp;language=${language}&amp;content=${content}&amp;pagenum=${pagenum+1}"><bean:message key="wap.list.next"/></a>
</c:if>
<c:if test="${pagenum>1}">
|<a href="<%=request.getContextPath()%>/index.do?action=menulist&amp;kindid=${kindid}&amp;did=${did}&amp;pageid=${pageid}&amp;language=${language}&amp;content=${content}&amp;pagenum=${pagenum-1}"><bean:message key="wap.list.prev"/></a>
</c:if>	


</p>
</card>
</wml>
