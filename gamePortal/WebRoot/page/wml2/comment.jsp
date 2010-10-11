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
  <a href="<%=request.getContextPath()%>/download.do?action=download&amp;gameId=${obj.id}">免费下载</a><br/>
  <form name="comment" action="comment.do?action=save" method="post">
  <input name="content" type="text" size="16" maxlength="200" emptyok="true" value="游戏不错"/><br/>
  <input type="hidden" name="gameId" value="${obj.id}" />
　<input type="hidden" name="location" value="${location}" />
  <input type="submit" value="发表评论"/> [<a href="customer.do?action=selectLogin">登录</a>]
</form>
 -------------------<br/>
 <c:forEach items="${list}" var="comment" varStatus="statu">
  	${numCount-statu.count+1}.${comment.content}(<fmt:formatDate pattern="yyyy-MM-dd hh:mm:ss" value="${comment.ctime}"/>)<br/>
  </c:forEach>
  <c:if test="${checkNextPage==1}">
<a href="<%=request.getContextPath()%>/comment.do?action=list&amp;gameId=${obj.id}&amp;pagenum=${pagenum+1}">下页</a>
</c:if>
<c:if test="${pagenum>1}">
|<a href="<%=request.getContextPath()%>/comment.do?action=list&amp;gameId=${obj.id}&amp;pagenum=${pagenum-1}">上页</a>
</c:if>	
<br/>-----------------<br/>
</div>
<%@ include file="head.jsp" %>
<div id="backindex"> 
</div>		
<div class="copy"><a href="index.jsp">返回首页</a></div>
</div>
</div>
</body>
</html>
