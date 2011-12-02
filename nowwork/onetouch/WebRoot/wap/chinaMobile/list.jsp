<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE html PUBLIC "-//WAPFORUM//DTD XHTML Mobile 1.0//EN" "http://www.wapforum.org/DTD/xhtml-mobile10.dtd">
<%@ page contentType="text/vnd.wap.wml;charset=UTF-8" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@ taglib uri="http://struts.apache.org/tags-bean" prefix="bean" %>

<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
<meta http-equiv="Pragma" content="no-cache"/>
<meta http-equiv="Cache-Control" content="no-cache"/>
<meta http-equiv="Expires" content="0"/>
<link href="css/wapstyle.css" rel="stylesheet" type="text/css" />
<title>手机游戏</title>
</head>
<body>
<div id="body" style="width:100%;" >
	<div id="content">
 <div class="list">
 <c:choose>
	<c:when test="${numCount>0}">
 <c:forEach items="${list}" var="obj" varStatus="statu">
<table cellpadding="0" cellspacing="0">
 <tr><td valign="top"  align="left">
 <div style="padding: 3px;">
 <a href="<%=request.getContextPath()%>/mobileGame.do?action=gameinfo&amp;did=${did}&amp;gameId=${obj.id}"><img border="0" src="game/${obj.id}/${obj.icon}" alt=""/></a></div>
 </td><td valign="top" align="left"><div style="padding: 3px;"><a href="<%=request.getContextPath()%>/mobileGame.do?action=gameinfo&amp;did=${did}&amp;gameId=${obj.id}" style="color: #002464;"> <b>${statu.count+(pagenum-1)*gamenum}.${obj.gamename}
</b><br/>${obj.brief} </a></div>
</td>
</tr>
</table>
</c:forEach>
</c:when>
	<c:otherwise>
		游戏正在陆续更新中，敬请期待。<br/>
	</c:otherwise>
</c:choose>

		</div>
<div class="title"><c:if test="${checkNextPage==1}">
<a href="<%=request.getContextPath()%>/mobileGame.do?action=gameList&amp;did=${did}&amp;pagenum=${pagenum+1}">下页</a>
</c:if>
<c:if test="${pagenum>1}">
|<a href="<%=request.getContextPath()%>/mobileGame.do?action=gameList&amp;did=${did}&amp;pagenum=${pagenum-1}">上页</a>
</c:if></div>
<!-- 
<%@ include file="head.jsp" %>
 -->
<div id="backindex"> 
</div>
</div>
</div>
</body>
</html>
