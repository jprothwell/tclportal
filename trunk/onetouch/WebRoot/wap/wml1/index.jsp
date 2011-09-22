<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE wml PUBLIC "-//WAPFORUM//DTD WML 1.1//EN" "http://www.wapforum.org/DTD/wml_1.1.xml">
<%@ page contentType="text/vnd.wap.wml;charset=UTF-8" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<wml>
<head> 
<meta http-equiv="Cache-Control" content="no-Cache"/> 
<meta http-equiv="Cache-Control" content="max-age=0"/> 
</head> 
<card title="动感无限-手机游戏">
<p>
<a href="${ad.url}"><img border="0" src="ad/${ad.image}" alt=""/></a><br/>
<!--  
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
-->
 ==免费应用程序==<br/>
  <c:forEach items="${list}" var="obj" varStatus="statu">
	 	<c:if test="${obj.typeid==2}">
		<a href="index.do?action=queryGameinfo&amp;did=${did}&amp;pageid=${pageid}&amp;country=${country}&amp;location=${obj.typeid}&amp;gameId=${obj.id}">${obj.gamename}</a><br/>
	</c:if>		
</c:forEach>  
<a href="index.do?action=menulist&amp;did=${did}&amp;pageid=${pageid}&amp;country=${country}&amp;kindid=4">更多>>..</a><br/>
  <input name="searchName" type="text" size="6" maxlength="255" emptyok="true" value=""/>
<anchor><go href="index.do?action=menulist" method="post">
<postfield name="searchName" value="$(searchName)"/>
<postfield name="did" value="${did}"/>
<postfield name="pageid" value="${pageid}"/>
<postfield name="country" value="${country}"/>
</go>搜游戏</anchor><br/>
==游戏热门推荐==<br/>
 <c:forEach items="${list}" var="obj" varStatus="statu">
 	<c:if test="${obj.typeid==1}">
		<a href="index.do?action=queryGameinfo&amp;did=${did}&amp;pageid=${pageid}&amp;country=${country}&amp;location=${obj.typeid}&amp;gameId=${obj.id}">${obj.gamename}</a><br/>	
	</c:if>	
</c:forEach>
==最新游戏上线==<br/>
  <c:forEach items="${list}" var="obj" varStatus="statu">
	 	<c:if test="${obj.typeid==3}">
	 	<a href="index.do?action=queryGameinfo&amp;did=${did}&amp;pageid=${pageid}&amp;country=${country}&amp;location=${obj.typeid}&amp;gameId=${obj.id}">[${obj.kindName}]${obj.gamename}</a><br/>
	</c:if>		
</c:forEach>  
<a href="index.do?action=menulist&amp;did=${did}&amp;pageid=${pageid}&amp;country=${country}">更多>>..</a><br/>
<%@ include file="head.jsp" %>
</p>
</card>
</wml>
