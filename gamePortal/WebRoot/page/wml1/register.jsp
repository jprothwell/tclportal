<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE wml PUBLIC "-//WAPFORUM//DTD WML 1.1//EN" "http://www.wapforum.org/DTD/wml_1.1.xml">
<%@ page contentType="text/vnd.wap.wml;charset=UTF-8" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<wml>
<card title="用户注册">
<p>
=用户注册=<br/>
<c:choose>
	<c:when test="${result!=''}">
		${result}<br/>
	</c:when>
</c:choose>
-------------------<br/>
登录名称：<input name="username" type="text" size="16" maxlength="100" emptyok="true" />*<br/>
登录密码：<input name="password" type="password" size="16" maxlength="100" emptyok="true" />*<br/>
密码确认：<input name="password1" type="password" size="16" maxlength="100" emptyok="true" />*<br/>
手机号码：<input name="mobile" type="text" size="16" maxlength="20" emptyok="true" /><br/>
用户邮箱：<input name="email" type="text" size="16" maxlength="200" emptyok="true" /><br/>
<anchor><go href="customer.do?action=save" method="post">
<postfield name="username" value="$(username)"/>
<postfield name="password" value="$(password)"/>
<postfield name="password1" value="$(password1)"/>
<postfield name="mobile" value="$(mobile)"/>
<postfield name="email" value="$(email)"/>
<postfield name="did" value="${did}"/>
<postfield name="pageid" value="${pageid}"/>
<postfield name="proviceid" value="${proviceid}"/>
</go>注册</anchor> [<a href="customer.do?action=selectLogin&amp;did=${did}&amp;pageid=${pageid}&amp;proviceid=${proviceid}">登录</a>]<br/>
 -------------------<br/>
<%@ include file="head.jsp" %>
 <a href="index.jsp?did=${did}&amp;pageid=${pageid}&amp;proviceid=${proviceid}">动感无限-手机游戏专区</a>
</p>
</card>
</wml>
