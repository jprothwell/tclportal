<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE wml PUBLIC "-//WAPFORUM//DTD WML 1.1//EN" "http://www.wapforum.org/DTD/wml_1.1.xml">
<%@ page contentType="text/vnd.wap.wml;charset=UTF-8" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<wml>
<head> 
<meta http-equiv="Cache-Control" content="no-Cache"/> 
<meta http-equiv="Cache-Control" content="max-age=0"/> 
</head> 
<card title="手机游戏-${kindName}"> 

<p>
<a href="index.jsp">首页</a> - ${kindName}<br/>
-----------------<br/>
 <c:forEach items="${list}" var="obj" varStatus="statu">
	${statu.count+(pagenum-1)*gamenum}.<a href="<%=request.getContextPath()%>/gameinfo.do?action=queryGameinfo&amp;gameId=${obj.id}">${obj.gamename}</a><br/>	
</c:forEach>
<c:if test="${checkNextPage==1}">
<a href="<%=request.getContextPath()%>/visit.do?action=menulist&amp;kindid=${kindid}amp;pagenum=${pagenum+1}">下页</a>
</c:if>
<c:if test="${pagenum>1}">
|<a href="<%=request.getContextPath()%>/visit.do?action=menulist&amp;kindid=${kindid}amp;pagenum=${pagenum-1}">上页</a>
</c:if>	
<br/>-----------------<br/>
=游戏分类=<br/>
   <a href="<%=request.getContextPath()%>/index.do?action=menulist&amp;kindid=1">射击</a>|
   <a href="<%=request.getContextPath()%>/index.do?action=menulist&amp;kindid=2">策略</a>|
   <a href="<%=request.getContextPath()%>/index.do?action=menulist&amp;kindid=3">冒险</a><br/>
   <a href="<%=request.getContextPath()%>/index.do?action=menulist&amp;kindid=4">模拟</a>|
   <a href="<%=request.getContextPath()%>/index.do?action=menulist&amp;kindid=1">休闲</a>|
   <a href="<%=request.getContextPath()%>/index.do?action=menulist&amp;kindid=1">音乐</a><br/>
   <a href="<%=request.getContextPath()%>/index.do?action=menulist&amp;kindid=1">体育</a>|
   <a href="<%=request.getContextPath()%>/index.do?action=menulist&amp;kindid=1">解谜</a>|
   <a href="<%=request.getContextPath()%>/index.do?action=menulist&amp;kindid=1">客服</a><br/>
<a href="index.jsp">动感无限-手机游戏专区</a>
</p>
</card>
</wml>
