<?xml version="1.0" encoding="utf-8"?>
<%@ page contentType="text/vnd.wap.wml;charset=UTF-8" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
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
 用户评论(${listSize}条)<br/>
 <c:forEach items="${list}" var="comment" varStatus="statu">
  	${comment.content}<br/>
  </c:forEach>
 <input name="Searchword53" type="text" size="16" maxlength="20" emptyok="true" value="游戏不错"/><br/>
<anchor><go href="＃" method="get">
<postfield name="fr" value="3g_in_w"/>
<postfield name="q" value="$(Searchword53)"/>
<postfield name="dq" value="鐖辨槒浜嗗ご"/>
<postfield name="gaid" value="TW96aWxsYQ%3d%3d"/>
<postfield name="guid" value=""/>
<postfield name="jt" value="5_s001"/>
</go>发表评论</anchor> [<a href="#">登录</a>]<br/>
</div>
<div class="title"> 
			【<a href="#">角色</a>】【<a href="#">动作</a>】【<a href="#">益智</a>】【<a href="#">棋牌</a>】 <br/> 
			【<a href="#">竞速</a>】【<a href="#">格斗</a>】【<a href="#">射击</a>】【<a href="#">策略</a>】 <br/> 
			【<a href="#">冒险</a>】【<a href="#">模拟</a>】【<a href="#">休闲</a>】【<a href="#">音乐</a>】 <br/> 
			【<a href="#">体育</a>】【<a href="#">解谜</a>】【<a href="#">格斗</a>】【<a href="#">动作</a>】
</div>
<div id="backindex"> 
</div>		
<div class="copy"><a href="index2.jsp">返回首页</a></div>
</div>
</div>
</body>
</html>
