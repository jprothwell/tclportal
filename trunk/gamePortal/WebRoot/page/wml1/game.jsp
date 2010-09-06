<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE wml PUBLIC "-//WAPFORUM//DTD WML 1.1//EN" "http://www.wapforum.org/DTD/wml_1.1.xml">
<%@ page contentType="text/vnd.wap.wml;charset=UTF-8" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<wml>
<card title="${obj.gamename}">
<p>
  <img src="images/icon.gif"/><br/>
   应用介绍:<br/>
 文字介绍：${obj.brief}
  <br/>
  <a href="<%=request.getContextPath()%>/download.do?action=download&amp;gameId=${obj.id}">免费下载</a><br/>
 星级评定：<img src="images/star_08.gif"/><br/>
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
 -------------------<br/>
   <a href="#">射击</a>|
   <a href="#">策略</a>|
   <a href="#">冒险</a><br/>
   <a href="#">模拟</a>|
   <a href="#">休闲</a>|
   <a href="#">音乐</a><br/>
   <a href="#">体育</a>|
   <a href="#">解谜</a>|
   <a href="#">客服</a><br/>
 <a href="/welcome.jsp?did=231">动感无限-手机游戏专区</a>
</p>
</card>
</wml>
