<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE wml PUBLIC "-//WAPFORUM//DTD WML 1.1//EN" "http://www.wapforum.org/DTD/wml_1.1.xml">
<%@ page contentType="text/vnd.wap.wml;charset=UTF-8" %>
<wml>
<card title="用户注册">
<p>
=用户注册=<br/>
-------------------<br/>
登录名称：<input name="userName" type="text" size="16" maxlength="20" emptyok="true" /><br/>
登录密码：<input name="passWord1" type="text" size="16" maxlength="20" emptyok="true" /><br/>
密码确认：<input name="passWord2" type="text" size="16" maxlength="20" emptyok="true" /><br/>
手机号码：<input name="mobile" type="text" size="16" maxlength="20" emptyok="true" /><br/>
用户邮箱：<input name="email" type="text" size="16" maxlength="20" emptyok="true" /><br/>
<anchor><go href="saveemail.do" method="get">
<postfield name="userName" value="$(userName)"/>
<postfield name="passWord1" value="$(passWord1)"/>
<postfield name="passWord2" value="$(passWord2)"/>
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
 <a href="/welcome.jsp?did=231">动感无限-手机游戏专区</a>
</p>
</card>
</wml>
