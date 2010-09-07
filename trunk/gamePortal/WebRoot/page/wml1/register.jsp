<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE wml PUBLIC "-//WAPFORUM//DTD WML 1.1//EN" "http://www.wapforum.org/DTD/wml_1.1.xml">
<%@ page contentType="text/vnd.wap.wml;charset=UTF-8" %>
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
登录名称：<input name="username" type="text" size="16" maxlength="20" emptyok="true" />*<br/>
登录密码：<input name="password" type="text" size="16" maxlength="20" emptyok="true" />*<br/>
密码确认：<input name="password1" type="text" size="16" maxlength="20" emptyok="true" />*<br/>
手机号码：<input name="mobile" type="text" size="16" maxlength="20" emptyok="true" /><br/>
用户邮箱：<input name="email" type="text" size="16" maxlength="20" emptyok="true" /><br/>
<anchor><go href="<%=request.getContextPath() %>/customer.do?action=save" method="get">
<postfield name="username" value="$(username)"/>
<postfield name="password" value="$(password)"/>
<postfield name="password1" value="$(password1)"/>
<postfield name="mobile" value="$(mobile)"/>
<postfield name="email" value="$(email)"/>
</go>注册</anchor> [<a href="login.jsp">登录</a>]<br/>
 -------------------<br/>
   <a href="#">射击</a>|
   <a href="#">策略</a>|
   <a href="#">冒险</a><br/>
   <a href="#">模拟</a>|
   <a href="#">休闲</a>|
   <a href="#">音乐</a><br/>
   <a href="#">体育</a>|
   <a href="#">解谜</a>|
   <a href="#">客服</a><br/>
 <a href="/index.jsp">动感无限-手机游戏专区</a>
</p>
</card>
</wml>
