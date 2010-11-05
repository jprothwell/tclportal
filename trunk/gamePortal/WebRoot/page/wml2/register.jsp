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
<title>动感无限-手机游戏</title>
</head>
<body>
<div id="body" style="width:100%;" >
	<div id="content">
		<div class="title"><a href="index.jsp">首页</a>-免费注册</div>
		<c:choose>
	<c:when test="${result!=''}">
		<div class="title">${result}</div>
	</c:when>
</c:choose>
<div class="list">
<form name="register" action="customer.do?action=save" method="post">
登录名称：<input name="username" type="text" size="16" maxlength="100" emptyok="true" />*<br/>
登录密码：<input name="password" type="password" size="16" maxlength="100" emptyok="true" />*<br/>
密码确认：<input name="password1" type="password" size="16" maxlength="100" emptyok="true" />*<br/>
用户邮箱：<input name="email" type="text" size="16" maxlength="100" emptyok="true" /><br/>
手机号码：<input name="mobile" type="text" size="16" maxlength="20" emptyok="true" /><br/>
<input type="submit" value="注册"/>   [<a href="customer.do?action=selectLogin">登录</a>]
</form>
 </div>
<%@ include file="head.jsp" %>
<div id="backindex"> 
</div>		
<div class="copy"><a href="index.jsp">返回首页</a></div>
</div>
</div>
</body>
</html>
