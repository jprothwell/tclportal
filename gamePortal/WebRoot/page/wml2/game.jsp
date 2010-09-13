<?xml version="1.0" encoding="utf-8"?>
<%@ page contentType="text/vnd.wap.wml;charset=UTF-8" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/fmt" prefix="fmt"%>
<!DOCTYPE html PUBLIC "-//WAPFORUM//DTD XHTML Mobile 1.0//EN" "http://www.wapforum.org/DTD/xhtml-mobile10.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
<meta http-equiv="Pragma" content="no-cache"/>
<meta http-equiv="Cache-Control" content="no-cache"/>
<meta http-equiv="Expires" content="0"/>
<link href="css/style.css" rel="stylesheet" type="text/css" />
<title>动感无限-手机游戏</title>
</head>
<body>
<div id="body" style="width:100%;" >
	<div id="content">
		<div class="title">${obj.gamename}</div>

<div class="list">
<img border="0" src="game/${obj.id}/${obj.imagename}" alt=""/><br/>
   应用介绍:<br/>
 文字介绍：${obj.brief}
  <br/>
  <a href="<%=request.getContextPath()%>/download.do?action=download&amp;gameId=${obj.id}">免费下载</a><br/>
 星级评定：<img src="images/star_${obj.lev}.gif"/><br/>
<a href="comment.do?action=list&amp;gameId=${obj.id}">用户评论</a>(${numCount}条)<br/>
 <c:forEach items="${list}" var="comment" varStatus="statu">
  	${numCount-statu.count+1}.${comment.content}(<fmt:formatDate pattern="yyyy-MM-dd hh:mm:ss" value="${comment.ctime}"/>)<br/>
  </c:forEach>
 <input name="content" type="text" size="16" maxlength="20" emptyok="true" value="游戏不错"/><br/>
<anchor><go href="comment.do?action=save" method="post">
<postfield name="content" value="$(content)"/>
<postfield name="gameId" value="${obj.id}"/>
<postfield name="location" value="${location}"/>
</go>发表评论</anchor> [<a href="customer.do?action=selectLogin">登录</a>]<br/>
</div>
<%@ include file="head.jsp" %>
<div id="backindex"> 
</div>		
<div class="copy"><a href="index.jsp">返回首页</a></div>
</div>
</div>
</body>
</html>
