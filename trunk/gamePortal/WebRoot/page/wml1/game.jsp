<?xml version="1.0" encoding="utf-8"?>
<%@ page contentType="text/vnd.wap.wml;charset=UTF-8" %>
<!DOCTYPE wml PUBLIC "-//WAPFORUM//DTD WML 1.1//EN" "http://www.wapforum.org/DTD/wml_1.1.xml">
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/fmt" prefix="fmt"%>
<wml>
<card title="${obj.gamename}">
<p>
  <img src="game/${obj.id}/${obj.imagename}"/><br/>
   ${obj.gamename}-应用介绍:<br/>
 文字介绍：${obj.detailinfo}
  <br/>
  <a href="<%=request.getContextPath()%>/download.do?action=download&amp;gameId=${obj.id}">免费下载</a><br/>
 星级评定：<img src="images/star_${obj.lev}.gif"/><br/>
 <a href="comment.do?action=list&amp;gameId=${obj.id}">用户评论</a>(${numCount}条)<br/>
  <c:forEach items="${list}" var="comment" varStatus="statu">
  	${numCount-statu.count+1}.${comment.content}(<fmt:formatDate pattern="yyyy-MM-dd hh:mm:ss" value="${comment.ctime}"/>)<br/>
  </c:forEach>
 <input name="content" type="text" size="16" maxlength="255" emptyok="true" value="游戏不错"/><br/>
<anchor><go href="comment.do?action=save" method="post">
<postfield name="content" value="$(content)"/>
<postfield name="gameId" value="${obj.id}"/>
<postfield name="location" value="${location}"/>
</go>发表评论</anchor> [<a href="customer.do?action=selectLogin">登录</a>]<br/>
 -------------------<br/>
<%@ include file="head.jsp" %>
 <a href="index.jsp">动感无限-手机游戏专区</a>
</p>
</card>
</wml>
