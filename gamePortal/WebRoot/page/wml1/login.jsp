﻿<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE wml PUBLIC "-//WAPFORUM//DTD WML 1.1//EN" "http://www.wapforum.org/DTD/wml_1.1.xml">
<%@ page contentType="text/vnd.wap.wml;charset=UTF-8" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<wml>
<card title="用户登录">
<p>
=用户登录=<br/>
<c:choose>
	<c:when test="${result!=''}">
		${result}<br/>
	</c:when>
</c:choose>
-------------------<br/>
登录名称：<input name="user" type="text" size="16" maxlength="20" emptyok="true" /><br/>
登录密码：<input name="pwd" type="password" size="16" maxlength="20" emptyok="true" /><br/>
<anchor><go href="customer.do?action=login" method="post">
<postfield name="user" value="$(user)"/>
<postfield name="pwd" value="$(pwd)"/>
</go>登录</anchor> [<a href="customer.do?action=selectReg">注册</a>]<br/>
 -------------------<br/>
<%@ include file="head.jsp" %>
 <a href="index.jsp">动感无限-手机游戏专区</a>
</p>
</card>
</wml>