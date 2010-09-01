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
   <img src="img/200706191040550.gif"/><br/>
   <a href="bk.jsp?id=2824<%=str1%>">精品SP业务1</a><br/>
   <a href="bk.jsp?id=2824<%=str1%>">精品SP业务2</a><br/>
   <a href="bk.jsp?id=2824<%=str1%>">精品SP业务3</a><br/>
   <a href="list.jsp?id=2824<%=str1%>">MP3</a>|<a href="list.jsp?id=2824<%=str1%>">视频</a>|
   <a href="list.jsp?id=2824<%=str1%>">娱乐</a>|<a href="list.jsp?id=2824<%=str1%>">交友</a><br/>
   <a href="list.jsp?id=2824<%=str1%>">美图</a>|<a href="list.jsp?id=2824<%=str1%>">两性</a>|
   <a href="list.jsp?id=2824<%=str1%>">时尚</a>|<a href="list.jsp?id=2824<%=str1%>">书屋</a><br/>
   <a href="bk.jsp?id=2824<%=str1%>">移动搜索</a><br/>
   <img src="img/200706191040550.gif"/><br/>    
   <a href="bk.jsp?id=2824<%=str1%>">推荐SP业务1</a><br/>
   <a href="bk.jsp?id=2824<%=str1%>">推荐SP业务2</a><br/>
   <a href="bk.jsp?id=2824<%=str1%>">推荐SP业务3</a><br/>
   <img src="img/200706191040550.gif"/><br/>    
   <a href="bk.jsp?id=2824<%=str1%>">推荐SP业务1</a><br/>
   <a href="bk.jsp?id=2824<%=str1%>">推荐SP业务2</a><br/>
   <a href="bk.jsp?id=2824<%=str1%>">推荐SP业务3</a><br/>	
   ※时尚生活休闲※<br/>
   <a href="bk.jsp?id=2824<%=str1%>">推荐SP业务1</a><br/>
   <a href="bk.jsp?id=2824<%=str1%>">推荐SP业务2</a><br/>
   <a href="bk.jsp?id=2824<%=str1%>">推荐SP业务3</a><br/>
   <a href="bk.jsp?id=2824<%=str1%>">推荐SP业务4</a><br/>
   <a href="bk.jsp?id=2824<%=str1%>">推荐SP业务5</a><br/>  
   <a href="list.jsp?id=2824">博客</a>|<a href="list.jsp?id=2824">影视</a>|
   <a href="list.jsp?id=2824">商务</a>|<a href="list.jsp?id=2824">游戏</a><br/>
   <a href="list.jsp?id=2824">新闻</a>|<a href="list.jsp?id=2824">动漫</a>|
   <a href="list.jsp?id=2824">体育</a>|<a href="list.jsp?id=2824">客服</a><br/>
</p>
</card>
</wml>
