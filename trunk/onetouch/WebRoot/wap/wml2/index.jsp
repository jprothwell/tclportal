<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE html PUBLIC "-//WAPFORUM//DTD XHTML Mobile 1.0//EN" "http://www.wapforum.org/DTD/xhtml-mobile10.dtd">
<%@ page contentType="text/vnd.wap.wml;charset=UTF-8" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
<meta http-equiv="Pragma" content="no-cache"/>
<meta http-equiv="Cache-Control" content="no-cache"/>
<meta http-equiv="Expires" content="0"/>
<link href="css/wapstyle.css" rel="stylesheet" type="text/css" />
<title>动感无限-手机游戏</title>
</head>
<body>
<div id="body" style="width:100%;" >
	<div id="content">
		<div class="title">

<a href="${ad.url}"><img border="0" src="ad/${ad.image}" alt=""/></a><br/>
<c:choose>
	<c:when test="${mdid==231}">
		<a href="http://a.10086.cn:7070/j/658/5610001006"><img border="0" src="images/suole.jpg" alt=""/></a><br/>
	</c:when>
	<c:when test="${mdid==237}">
		<a href="http://a.10086.cn:7070/j/657/5610001007"><img border="0" src="images/suole.jpg" alt=""/></a><br/>
	</c:when>
	<c:when test="${mdid==238}">
		<a href="http://a.10086.cn:7070/j/656/5610001008"><img border="0" src="images/suole.jpg" alt=""/></a><br/>
	</c:when>
</c:choose>
		</div>
<div class="title">
	==免费应用程序==
</div>
<div class="list">
<c:forEach items="${list}" var="obj" varStatus="statu">
	 	<c:if test="${obj.typeid==2}">
		<a href="index.do?action=queryGameinfo&amp;did=${did}&amp;pageid=${pageid}&amp;country=${country}&amp;location=${obj.typeid}&amp;gameId=${obj.id}">${obj.gamename}</a><br/>	
	</c:if>		
</c:forEach> 
<a href="index.do?action=menulist&amp;did=${did}&amp;pageid=${pageid}&amp;country=${country}&amp;kindid=4">更多>>..</a>
</div>	
<div class="title">
	==游戏热门推荐==
</div>
<div class="list">
 <c:forEach items="${list}" var="obj" varStatus="statu">
 	<c:if test="${obj.typeid==1}">
<table cellpadding="0" cellspacing="0">
 <tr><td valign="top"  align="left">
 <div style="padding: 3px;">
 <a href="index.do?action=queryGameinfo&amp;did=${did}&amp;pageid=${pageid}&amp;country=${country}&amp;location=${obj.typeid}&amp;gameId=${obj.id}"><img border="0" src="game/${obj.id}/${obj.icon}" alt=""/></a></div>
 </td><td valign="top" align="left"><div style="padding: 3px;"><a href="<%=request.getContextPath()%>/index.do?action=queryGameinfo&amp;did=${did}&amp;pageid=${pageid}&amp;country=${country}&amp;location=${obj.typeid}&amp;gameId=${obj.id}" style="color: #002464;"> <b>${obj.gamename}
</b><br/>${obj.brief} </a></div>
</td>
</tr>
</table>
	</c:if>	
</c:forEach>
		</div>
		<div class="title">
			==最新游戏上线==<br/>
		</div>
		<div class="list">
<c:forEach items="${list}" var="obj" varStatus="statu">
	 	<c:if test="${obj.typeid==3}">
		<a href="index.do?action=queryGameinfo&amp;did=${did}&amp;pageid=${pageid}&amp;country=${country}&amp;location=${obj.typeid}&amp;gameId=${obj.id}">[${obj.kindName}]${obj.gamename}</a><br/>	
	</c:if>		
</c:forEach>  
<a href="index.do?action=menulist&amp;did=${did}&amp;pageid=${pageid}&amp;country=${country}">更多>>..</a>
 </div>
<%@ include file="head.jsp" %>
<div id="backindex"> 
</div>		
<div class="copy"><a href="http://wap.my-fun.cn/bk.jsp?id=77&amp;did=163">客户服务</a></div>
</div>
</div>
</body>
</html>
