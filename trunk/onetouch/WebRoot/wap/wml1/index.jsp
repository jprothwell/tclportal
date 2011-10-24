<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE wml PUBLIC "-//WAPFORUM//DTD WML 1.1//EN" "http://www.wapforum.org/DTD/wml_1.1.xml">
<%@ page contentType="text/vnd.wap.wml;charset=UTF-8" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@ taglib uri="http://struts.apache.org/tags-bean" prefix="bean" %>

<wml>
<head> 
<meta http-equiv="Cache-Control" content="no-Cache"/> 
<meta http-equiv="Cache-Control" content="max-age=0"/> 
</head> 

<a href="<%=request.getContextPath()%>/index.do?action=chooseLanguage&amp;language=zh&amp;did=${did}">中文</a>
<a href="<%=request.getContextPath()%>/index.do?action=chooseLanguage&amp;language=en&amp;did=${did}">english</a>
<card title="<bean:message key="wap.index.title"/>">
<p>
<a href="${ad.url}"><img border="0" src="ad/${ad.image}" alt=""/></a><br/>
<!--  
	<c:choose>
	<c:when test="${mdid==231}">
		<a href="http://a.10086.cn:7070/j/658/5610001006"><img border="0" src="images/suole.jpg" alt=""/></a><br/>
	</c:when>
	<c:when test="${mdid==237}">
		<a href="http://a.10086.cn:7070/j/657/5610001007"><img border="0" src="images/suole.jpg" alt=""/></a><br/>
	</c:when>
	<c:when test="${mdid==238}">
		<a href="http://a.10086.cn:7070/j/656/5610001008"><img border="0" src="images/suole.jpg" alt=""/></a><br/>
	</c:when>
</c:choose>
-->
==<bean:message key="wap.index.freeApp"/>==<br/>
  <c:forEach items="${list}" var="obj" varStatus="statu">
	 	<c:if test="${obj.typeid==2}">
		<a href="index.do?action=queryGameinfo&amp;did=${did}&amp;pageid=${pageid}&amp;language=${language}&amp;location=${obj.typeid}&amp;gameId=${obj.id}">${obj.gamename}</a><br/>
	</c:if>		
</c:forEach>  
<a href="index.do?action=menulist&amp;did=${did}&amp;pageid=${pageid}&amp;language=${language}&amp;kindid=4"><bean:message key="wap.index.more"/> >>..</a><br/>
  <input name="searchName" type="text" size="6" maxlength="255" emptyok="true" value=""/>
<anchor><go href="index.do?action=menulist" method="post">
<postfield name="searchName" value="$(searchName)"/>
<postfield name="did" value="${did}"/>
<postfield name="pageid" value="${pageid}"/>
<postfield name="language" value="${language}"/>
</go><bean:message key="wap.head.search"/></anchor><br/>
==<bean:message key="wap.index.hotGame"/>==<br/>
 <c:forEach items="${list}" var="obj" varStatus="statu">
 	<c:if test="${obj.typeid==1}">
		<a href="index.do?action=queryGameinfo&amp;did=${did}&amp;pageid=${pageid}&amp;language=${language}&amp;location=${obj.typeid}&amp;gameId=${obj.id}">${obj.gamename}</a><br/>	
	</c:if>	
</c:forEach>
==<bean:message key="wap.index.newGame"/>==<br/>
  <c:forEach items="${list}" var="obj" varStatus="statu">
	 	<c:if test="${obj.typeid==3}">
	 	<a href="index.do?action=queryGameinfo&amp;did=${did}&amp;pageid=${pageid}&amp;language=${language}&amp;location=${obj.typeid}&amp;gameId=${obj.id}">[${obj.kindName}]${obj.gamename}</a><br/>
	</c:if>		
</c:forEach>  
<a href="index.do?action=menulist&amp;did=${did}&amp;pageid=${pageid}&amp;language=${language}"><bean:message key="wap.index.more"/> >>..</a><br/>

</p>
</card>
</wml>
