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
	<div class="title"><a href="index.jsp">首页</a>-用户登录</div>
	<c:choose>
	<c:when test="${result!=''}">
		<div class="title">${result}</div>
	</c:when>
</c:choose>
<div class="list">
登录名称：<input name="user" type="text" size="16" maxlength="20" emptyok="true" /><br/>
登录密码：<input name="pwd" type="password" size="16" maxlength="20" emptyok="true" /><br/>
<anchor><go href="customer.do?action=login" method="get">
<postfield name="user" value="$(user)"/>
<postfield name="pwd" value="$(pwd)"/>
</go>登录</anchor> [<a href="customer.do?action=selectReg">注册</a>]
		</div>
<div class="title"> 
			【<a href="list2.jsp">角色</a>】【<a href="#">动作</a>】【<a href="#">益智</a>】【<a href="#">棋牌</a>】 <br/> 
			【<a href="#">竞速</a>】【<a href="#">格斗</a>】【<a href="#">射击</a>】【<a href="#">策略</a>】 <br/> 
			【<a href="#">冒险</a>】【<a href="#">模拟</a>】【<a href="#">休闲</a>】【<a href="#">音乐</a>】 <br/> 
			【<a href="#">体育</a>】【<a href="#">解谜</a>】【<a href="#">格斗</a>】【<a href="#">动作</a>】
</div>
<div id="backindex"> 
</div>		
<div class="copy"><a href="index.jsp">返回首页</a></div>
</div>
</div>
</body>
</html>
