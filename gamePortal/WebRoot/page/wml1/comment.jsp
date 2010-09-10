<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE wml PUBLIC "-//WAPFORUM//DTD WML 1.1//EN" "http://www.wapforum.org/DTD/wml_1.1.xml">
<%@ page contentType="text/vnd.wap.wml;charset=UTF-8" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/fmt" prefix="fmt"%>
<wml>
<card title="${obj.gamename}">
<p>
  ${obj.gamename}<br/>
  <a href="<%=request.getContextPath()%>/download.do?action=download&amp;gameId=${obj.id}">免费下载</a><br/>
 <input name="content" type="text" size="16" maxlength="20" emptyok="true" value="游戏不错"/><br/>
<anchor><go href="comment.do?action=save" method="get">
<postfield name="content" value="$(content)"/>
<postfield name="gameId" value="${obj.id}"/>
<postfield name="location" value="${location}"/>
</go>发表评论${numCount}=${checkNextPage1}</anchor> [<a href="customer.do?action=selectLogin">登录</a>]<br/>
 -------------------<br/>
  <c:forEach items="${list}" var="comment" varStatus="statu">
  	${numCount-statu.count+1}.${comment.content}(<fmt:formatDate pattern="yyyy-MM-dd hh:mm:ss" value="${comment.ctime}"/>)<br/>
  </c:forEach>
  <c:if test="${checkNextPage==1}">
<a href="<%=request.getContextPath()%>/visit.do?action=menulist&amp;kindid=${kindid}amp;pagenum=${pagenum+1}">下页</a>
</c:if>
<c:if test="${pagenum>1}">
|<a href="<%=request.getContextPath()%>/visit.do?action=menulist&amp;kindid=${kindid}amp;pagenum=${pagenum-1}">上页</a>
</c:if>	
<br/>-----------------<br/>
   <a href="#">射击</a>|
   <a href="#">策略</a>|
   <a href="#">冒险</a><br/>
   <a href="#">模拟</a>|
   <a href="#">休闲</a>|
   <a href="#">音乐</a><br/>
   <a href="#">体育</a>|
   <a href="#">解谜</a>|
   <a href="#">客服</a><br/>
 <a href="index.jsp">动感无限-手机游戏专区</a>
</p>
</card>
</wml>
