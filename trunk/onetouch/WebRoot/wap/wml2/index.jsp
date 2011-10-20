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
<title><bean:message key="wap.index.title"/></title>
</head>
<body>
<div id="body" style="width:100%;" >
<a href="<%=request.getContextPath()%>/index.do?action=chooseLanguage&amp;language=zh&amp;did=${did}">中文</a>
<a href="<%=request.getContextPath()%>/index.do?action=chooseLanguage&amp;language=en&amp;did=${did}">english</a>
	<div id="content">
	
		<div class="title">

<a href="${ad.url}"><img border="0" src="ad/${ad.image}" alt=""/></a><br/>

		</div>
<div class="title">
==<bean:message key="wap.index.freeApp"/>==
	
</div>
<div class="list">
<c:forEach items="${list}" var="obj" varStatus="statu">
	 	<c:if test="${obj.typeid==2}">
		<a href="index.do?action=queryGameinfo&amp;did=${did}&amp;pageid=${pageid}&amp;language=${language}&amp;location=${obj.typeid}&amp;gameId=${obj.id}">${obj.gamename}</a><br/>	
	</c:if>		
</c:forEach> 
<a href="index.do?action=menulist&amp;did=${did}&amp;pageid=${pageid}&amp;language=${language}&amp;kindid=4"><bean:message key="wap.index.more"/>>>..</a>
</div>	
<div class="title">
==<bean:message key="wap.index.hotGame"/>==
</div>
<div class="list">
 <c:forEach items="${list}" var="obj" varStatus="statu">
 	<c:if test="${obj.typeid==1}">
<table cellpadding="0" cellspacing="0">
 <tr><td valign="top"  align="left">
 <div style="padding: 3px;">
 <a href="index.do?action=queryGameinfo&amp;did=${did}&amp;pageid=${pageid}&amp;language=${language}&amp;location=${obj.typeid}&amp;gameId=${obj.id}"><img border="0" src="game/${obj.id}/${obj.icon}" alt=""/></a></div>
 </td><td valign="top" align="left"><div style="padding: 3px;"><a href="<%=request.getContextPath()%>/index.do?action=queryGameinfo&amp;did=${did}&amp;pageid=${pageid}&amp;language=${language}&amp;location=${obj.typeid}&amp;gameId=${obj.id}" style="color: #002464;"> <b>${obj.gamename}
</b><br/>${obj.brief} </a></div>
</td>
</tr>
</table>
	</c:if>	
</c:forEach>
		</div>
		<div class="title">
			==<bean:message key="wap.index.newGame"/>==<br/>
		</div>
		<div class="list">
<c:forEach items="${list}" var="obj" varStatus="statu">
	 	<c:if test="${obj.typeid==3}">
		<a href="index.do?action=queryGameinfo&amp;did=${did}&amp;pageid=${pageid}&amp;language=${language}&amp;location=${obj.typeid}&amp;gameId=${obj.id}">${obj.gamename}</a><br/>	
	</c:if>		
</c:forEach>  
<a href="index.do?action=menulist&amp;did=${did}&amp;pageid=${pageid}&amp;language=${language}"><bean:message key="wap.index.more"/>>>..</a>
 </div>
<%@ include file="head.jsp" %>
<div id="backindex"> 
</div>		
<div class="copy"><a href="<%=request.getContextPath()%>/wap/help.jsp"><bean:message key="wap.index.help"/></a></div>
</div>
</div>
</body>
</html>
