<?xml version="1.0" encoding="utf-8"?>
<%@ page contentType="text/vnd.wap.wml;charset=UTF-8" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/fmt" prefix="fmt"%>
<%@ taglib uri="http://struts.apache.org/tags-bean" prefix="bean" %>

<!DOCTYPE html PUBLIC "-//WAPFORUM//DTD XHTML Mobile 1.0//EN" "http://www.wapforum.org/DTD/xhtml-mobile10.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
<meta http-equiv="Pragma" content="no-cache"/>
<meta http-equiv="Cache-Control" content="no-cache"/>
<meta http-equiv="Expires" content="0"/>
<link href="css/wapstyle.css" rel="stylesheet" type="text/css" />
<title><bean:message key="wap.index.title"/></title>
</head>
<body>
<div id="body" style="width:100%;" >
	<div id="content">
		<div class="title">${gameLanguage.name}</div>

<div class="list">
<c:if test="${result!=''}">
	${result}	<br/>
	</c:if>	
<img border="0" src="game/${obj.id}/${obj.imagename}" alt=""/><br/>
  ${gameLanguage.name}- <bean:message key="wap.game.breif"/>:${gameLanguage.brief}<br/>
 <bean:message key="wap.game.detail"/>：${gameLanguage.detailinfo}
  <br/>
  <c:if test="${type==0}">
  	<a href="<%=request.getContextPath()%>/index.do?action=download&amp;did=${did}&amp;gameId=${obj.id}&amp;language=${language}"><bean:message key="wap.game.download"/></a><br/>
  </c:if>
  <c:if test="${type==1}"> 
		<a href="${url}"><bean:message key="wap.game.download"/></a><br/>
	</c:if>
 <bean:message key="wap.game.star"/>：<img src="images/star_${obj.lev}.gif"/><br/>
</div>
<%@ include file="head.jsp" %>
<div id="backindex"> 
</div>		
<div class="copy"><a href="index.jsp?did=${did}&amp;pageid=${pageid}"><bean:message key="wap.index.home"/></a></div>
</div>
</div>
</body>
</html>
