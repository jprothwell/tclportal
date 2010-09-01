<?xml version="1.0" encoding="utf-8"?><!DOCTYPE wml PUBLIC "-//WAPFORUM//DTD WML 1.1//EN" "http://www.wapforum.org/DTD/wml_1.1.xml">
<%@ page contentType="text/vnd.wap.wml;charset=UTF-8" %>
<%@ page import="cn.funstar.wap.util.*,cn.funstar.wap.action.*,cn.funstar.wap.db.*" %>
<%
indexAction action = new indexAction(request);
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
   <img src="img/icon.gif"/><br/>
   <%
   DBMap[] list =action.getList("25");
   String href = null;
   String name = null;
   if(list!=null){
     for(int i = 0;i<list.length;i++){
        if("1".equals(list[i].get(DBInfo.COMMON_IS_SERVICE))){
        href="bk.jsp?id="+list[i].get(DBInfo.COMMON_ID)+str1;
        name=StringUtil.shift(list[i].get(DBInfo.SERVICE_NAME));
   %>
   <a href="<%=href%>"><%=action.getAlias(name)%></a><br/>
   <%
       }
     }
   }
   %>

   <a href="list1.jsp?id=11<%=str1%>">视频</a>|
   <a href="list1.jsp?id=15<%=str1%>">两性</a>|
   <a href="list1.jsp?id=14<%=str1%>">美图</a><br/>
   <a href="list1.jsp?id=17<%=str1%>">书屋</a>|
   <a href="list1.jsp?id=16<%=str1%>">情感</a>|
   <a href="list1.jsp?id=21<%=str1%>">游戏</a><br/>
   <a href="bk.jsp?id=100<%=str1%>">移动搜索</a><br/>

   <img src="img/icon1.gif"/><br/>
   <%
   list =action.getList("26");
   if(list!=null){
     for(int i = 0;i<list.length;i++){
        if("1".equals(list[i].get(DBInfo.COMMON_IS_SERVICE))){
        href="bk.jsp?id="+list[i].get(DBInfo.COMMON_ID)+str1;
        name=StringUtil.shift(list[i].get(DBInfo.SERVICE_NAME));
   %>
   <a href="<%=href%>"><%=action.getAlias(name)%></a><br/>
   <%
        }
     }
   }
   %>
   <img src="img/icon2.gif"/><br/>
   <%
   list =action.getList("27");
   if(list!=null){
     for(int i = 0;i<list.length;i++){
        if("1".equals(list[i].get(DBInfo.COMMON_IS_SERVICE))){
        href="bk.jsp?id="+list[i].get(DBInfo.COMMON_ID)+str1;
        name=StringUtil.shift(list[i].get(DBInfo.SERVICE_NAME));
   %>
   <a href="<%=href%>"><%=action.getAlias(name)%></a><br/>
   <%
        }
     }
   }
   %>

   <img src="img/icon3.gif"/><br/>
   <%
   list =action.getList("28");
   if(list!=null){
     for(int i = 0;i<list.length;i++){
        if("1".equals(list[i].get(DBInfo.COMMON_IS_SERVICE))){
        href="bk.jsp?id="+list[i].get(DBInfo.COMMON_ID)+str1;
        name=StringUtil.shift(list[i].get(DBInfo.SERVICE_NAME));
   %>
   <a href="<%=href%>"><%=action.getAlias(name)%></a><br/>
   <%
        }
     }
   }
   %>
   <a href="list.jsp?id=10<%=str1%>">MP3</a>|
   <a href="list.jsp?id=12<%=str1%>">娱乐</a>|
   <a href="list.jsp?id=13<%=str1%>">交友</a><br/>
   <a href="list.jsp?id=19<%=str1%>">影视</a>|
   <a href="list.jsp?id=20<%=str1%>">商务</a>|
   <a href="list.jsp?id=22<%=str1%>">新闻</a><br/>
   <a href="list.jsp?id=23<%=str1%>">动漫</a>|
   <a href="list.jsp?id=24<%=str1%>">体育</a>|
   <a href="bk.jsp?id=99<%=str1%>">客服</a>
</p>
</card>
</wml>
