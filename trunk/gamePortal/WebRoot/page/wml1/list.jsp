<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE wml PUBLIC "-//WAPFORUM//DTD WML 1.1//EN" "http://www.wapforum.org/DTD/wml_1.1.xml">
<%@ page contentType="text/vnd.wap.wml;charset=UTF-8" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<wml>
<head> 
<meta http-equiv="Cache-Control" content="no-Cache"/> 
<meta http-equiv="Cache-Control" content="max-age=0"/> 
</head> 
<card title="动感无限-${kindName}"> 

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
   <a href="list.jsp">射击</a>|
   <a href="#">策略</a>|
   <a href="#">冒险</a><br/>
   <a href="#">模拟</a>|
   <a href="#">休闲</a>|
   <a href="#">音乐</a><br/>
   <a href="#">体育</a>|
   <a href="#">解谜</a>|
   <a href="#">客服</a><br/>
<a href="index.jsp?did=">动感无限-手机游戏专区</a>
</p>
</card>
</wml>
