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
<link href="css/style.css" rel="stylesheet" type="text/css" />
<title>手机游戏-${kindName}</title>
</head>
<body>
<div id="body" style="width:100%;" >
	<div id="content">
		<div class="title"><a href="index.jsp">首页</a>-${kindName}</div>
<div class="list">
 <div class="list">
 <c:forEach items="${list}" var="obj" varStatus="statu">
<table cellpadding="0" cellspacing="0">
 <tr><td valign="top"  align="left">
 <div style="padding: 3px;">
 <a href="<%=request.getContextPath()%>/gameinfo.do?action=queryGameinfo&amp;location=${obj.typeid}&amp;gameId=${obj.id}"><img border="0" src="game/${obj.id}/${obj.icon}" alt=""/></a></div>
 </td><td valign="top" align="left"><div style="padding: 3px;"><a href="<%=request.getContextPath()%>/gameinfo.do?action=queryGameinfo&amp;location=${obj.typeid}&amp;gameId=${obj.id}" style="color: #002464;"> <b>${statu.count+(pagenum-1)*gamenum}.${obj.gamename}
</b><br/>${obj.brief} </a></div>
</td>
</tr>
</table>
</c:forEach>
		</div>
		</div>
<div class="title"><c:if test="${checkNextPage==1}">
<a href="<%=request.getContextPath()%>/visit.do?action=menulist&amp;kindid=${kindid}amp;pagenum=${pagenum+1}">下页</a>
</c:if>
<c:if test="${pagenum>1}">
|<a href="<%=request.getContextPath()%>/visit.do?action=menulist&amp;kindid=${kindid}amp;pagenum=${pagenum-1}">上页</a>
</c:if></div>
<div class="title"> 
			【<a href="#">角色</a>】【<a href="#">动作</a>】【<a href="#">益智</a>】【<a href="#">棋牌</a>】 <br/> 
			【<a href="#">竞速</a>】【<a href="#">格斗</a>】【<a href="#">射击</a>】【<a href="#">策略</a>】 <br/> 
			【<a href="#">冒险</a>】【<a href="#">模拟</a>】【<a href="#">休闲</a>】【<a href="#">音乐</a>】 <br/> 
			【<a href="#">体育</a>】【<a href="#">解谜</a>】【<a href="#">格斗</a>】【<a href="#">动作</a>】
</div>
<div id="backindex"> 
</div>		
<div class="copy"><a href="index.jsp">返回首页</a></div>
</div>
</div>
</body>
</html>
