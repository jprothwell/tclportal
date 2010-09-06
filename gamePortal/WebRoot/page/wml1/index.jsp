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
		<a href="login.jsp">用户登录</a>　<a href="register.jsp">免费注册</a><br/>
	</c:when>
	<c:otherwise>
		${username}<br/>
	</c:otherwise>
</c:choose>
 <c:forEach items="${list}" var="obj" varStatus="statu">
 	<c:if test="${obj.typeid==1}">
		<a href="<%=request.getContextPath()%>/gameinfo.do?action=queryGameinfo&amp;location=${obj.typeid}&amp;gameId=${obj.id}">${obj.gamename}</a><br/>	
	</c:if>	
</c:forEach>
   <a href="<%=request.getContextPath()%>/visit.do?action=menulist&amp;kindid=1">角色</a>|
   <a href="<%=request.getContextPath()%>/visit.do?action=menulist&amp;kindid=2">动作</a>|
   <a href="#">益智</a><br/>
   <a href="#">棋牌</a>|
   <a href="#">竞速</a>|
   <a href="#">格斗</a><br/>
   *手机应用热推榜*<br/>
  <c:forEach items="${list}" var="obj" varStatus="statu">
	 	<c:if test="${obj.typeid==2}">
		<a href="#">${obj.gamename}</a><br/>	
	</c:if>		
</c:forEach>   
   *手机游戏重点推荐*<br/>
  <c:forEach items="${list}" var="obj" varStatus="statu">
	 	<c:if test="${obj.typeid==3}">
		<a href="#">[${obj.kindName}]${obj.gamename}</a><br/>	
	</c:if>		
</c:forEach>  
   <a href="#">射击</a>|
   <a href="#">策略</a>|
   <a href="#">冒险</a><br/>
   <a href="#">模拟</a>|
   <a href="#">休闲</a>|
   <a href="#">音乐</a><br/>
   <a href="#">体育</a>|
   <a href="#">解谜</a>|
   <a href="#">客服</a>
   <br/>
</p>
</card>
</wml>
