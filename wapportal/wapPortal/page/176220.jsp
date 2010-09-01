<?xml version="1.0" encoding="utf-8"?><!DOCTYPE wml PUBLIC "-//WAPFORUM//DTD WML 1.1//EN" "http://www.wapforum.org/DTD/wml_1.1.xml">
<%@ page contentType="text/vnd.wap.wml;charset=UTF-8" %>
<%
String did = request.getParameter("did");
String str1 = "";
String str2 = "";
if(did!=null&&did!=""){
	str1 = "&amp;did="+did;
	str2 = "?did="+did;
}
%>
<wml>
<card title="动感无限">
<p>
   <img src="img/logo20.gif"/><br/>
   <a href="bk.jsp?id=101<%=str1%>">2007新流行真唱MP3</a><br/>
   <a href="bk.jsp?id=102<%=str1%>">超长MP3*热铃排行</a><br/>
   <a href="bk.jsp?id=103<%=str1%>">QQ聊天*火</a><br/>
   <a href="list.jsp?id=10<%=str1%>">MP3</a>|<a href="list.jsp?id=11<%=str1%>">视频</a>|
   <a href="list.jsp?id=12<%=str1%>">娱乐</a><br/>
   <a href="list.jsp?id=13<%=str1%>">交友</a>|<a href="list.jsp?id=14<%=str1%>">美图</a>|
   <a href="list.jsp?id=15<%=str1%>">两性</a><br/>
   <a href="list.jsp?id=16<%=str1%>">时尚</a>|<a href="list.jsp?id=17<%=str1%>">书屋</a><br/>
   <a href="bk.jsp?id=100<%=str1%>">移动搜索</a><br/>
   <img src="img/logo21.gif"/><br/>    
   <a href="bk.jsp?id=104<%=str1%>">本周=MP3排行</a><br/>
   <a href="bk.jsp?id=105<%=str1%>">*2007超酷铃音*</a><br/>
   <a href="bk.jsp?id=106<%=str1%>">十万mp3*搜索大全</a><br/>
   <img src="img/logo22.gif"/><br/>    
   <a href="bk.jsp?id=107<%=str1%>">极品绝色*美女图</a><br/>
   <a href="bk.jsp?id=108<%=str1%>">娇艳MM梦工厂</a><br/>
   <a href="bk.jsp?id=109<%=str1%>">美女写真+偷拍</a><br/>	
   *时尚生活休闲*<br/>   
   <a href="bk.jsp?id=112<%=str1%>">痴情男女*情爱测试</a><br/>
   <a href="bk.jsp?id=113<%=str1%>">娱乐头条*抢先看</a><br/>
   <a href="bk.jsp?id=114<%=str1%>">男欢女爱*乐园</a><br/>  
   <a href="list.jsp?id=18<%=str1%>">博客</a>|<a href="list.jsp?id=19<%=str1%>">影视</a>|
   <a href="list.jsp?id=20<%=str1%>">商务</a><br/>
   <a href="list.jsp?id=21<%=str1%>">游戏</a>|<a href="list.jsp?id=22<%=str1%>">新闻</a>|
   <a href="list.jsp?id=23<%=str1%>">动漫</a><br/>
   <a href="list.jsp?id=24<%=str1%>">体育</a>|<a href="bk.jsp?id=99<%=str1%>">客服</a><br/>
</p>
</card>
</wml>
