<?xml version="1.0" encoding="utf-8"?><!DOCTYPE wml PUBLIC "-//WAPFORUM//DTD WML 1.1//EN" "http://www.wapforum.org/DTD/wml_1.1.xml">
<%@ page contentType="text/vnd.wap.wml;charset=UTF-8" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<wml>
<head> 
<meta http-equiv="Cache-Control" content="no-Cache"/> 
<meta http-equiv="Cache-Control" content="max-age=0"/> 
</head> 
<card title="手机游戏">
<p>
请选择对应机型进入Java应用下载<br/>
-----------------<br/>
<c:forEach items="${list}" var="obj" varStatus="statu">
 <a href="<%=request.getContextPath()%>/index.do?action=index&amp;did=${obj.did}">${obj.phonetype}</a>
 <c:if test="${statu.count%5==0}"><br/></c:if>
</c:forEach>
 
<br/>-----------------<br/>
</p>
</card>
</wml>
