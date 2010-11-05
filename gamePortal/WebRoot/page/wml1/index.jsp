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
<c:choose>
	<c:when test="${username==''}">
		<a href="customer.do?action=selectLogin">用户登录</a>　<a href="customer.do?action=selectReg">免费注册</a><br/>
	</c:when>
	<c:otherwise>
		欢迎您：${username}，精彩手机软件等待您的下载。<br/>
	</c:otherwise>
</c:choose>
 ==免费应用程序==<br/>
  <c:forEach items="${list}" var="obj" varStatus="statu">
	 	<c:if test="${obj.typeid==2}">
		<a href="gameinfo.do?action=queryGameinfo&amp;location=${obj.typeid}&amp;gameId=${obj.id}">${obj.gamename}</a><br/>
	</c:if>		
</c:forEach>  
<a href="index.do?action=menulist&amp;kindid=4">更多>>..</a><br/>
  <input name="content" type="text" size="6" maxlength="255" emptyok="true" value="QQ"/>
<anchor><go href="index.do?action=menulist" method="post">
<postfield name="content" value="$(content)"/>
</go>搜游戏</anchor><br/>
==游戏热门推荐==<br/>
 <c:forEach items="${list}" var="obj" varStatus="statu">
 	<c:if test="${obj.typeid==1}">
		<a href="gameinfo.do?action=queryGameinfo&amp;location=${obj.typeid}&amp;gameId=${obj.id}">${obj.gamename}</a><br/>	
	</c:if>	
</c:forEach>
==最新游戏上线==<br/>
  <c:forEach items="${list}" var="obj" varStatus="statu">
	 	<c:if test="${obj.typeid==3}">
	 	<a href="gameinfo.do?action=queryGameinfo&amp;location=${obj.typeid}&amp;gameId=${obj.id}">[${obj.kindName}]${obj.gamename}</a><br/>
	</c:if>		
</c:forEach>  
<a href="index.do?action=menulist">更多>>..</a><br/>
<%@ include file="head.jsp" %>
</p>
</card>
</wml>
