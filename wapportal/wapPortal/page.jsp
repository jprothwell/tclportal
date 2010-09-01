<?xml version="1.0" encoding="UTF-8"?>
<%@ page contentType="application/vnd.wap.xhtml+xml;charset=UTF-8"%>
<%@ page import="java.net.URLEncoder,java.util.*" %>
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
int img_id[]={2,1,1,0,0,0,0,0,0,0,2,1,1};
%>
<!DOCTYPE html PUBLIC "-//WAPFORUM//DTD XHTML Mobile 1.0//EN" "http://www.wapforum.org/DTD/xhtml-mobile10.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<title>动感无限...</title>
<style type="text/css">
body, table, tr, td, form, div, p, h1, h2, h3, h4, a:link, a:visited, a:hover, a {
	margin: 0 0 0 0;
	padding: 0;
	font-size:12px;
}
a{text-decoration : none}
a:link, a:visited {color: #4d4e4e; font-weight: normal; text-decoration: none;}
a:hover, a:active {color: #4d4e4e; text-decoration: underline; background-color: #FFCCCC}
ul{
padding:0 0 0 15px; 
margin: 0 0 0 0;
}
li{
padding:0 0 0 -10px; 
margin: 0 0 0 0;
}
#img{
border:0px;
}
.header{
background-color:#000000;
color: #FF6633;
text-align :left;
padding-top:3px;
border-bottom:2px solid  #999999;
}
.menu{
color: #000000;
background-color:#FFFFFF;
padding-top:2px
}
.txtLine{
padding:2px;
border-bottom:1px dashed #CCCCCC;
}
.txt1{
color: #000000;
}
.txt2{
color: #FFFFFF;
}
.indexService{
color:#666666;
}
.footer{
background-color:#ededed;
color:#666666;
border-top: 2px solid #999999;
text-align : center;
padding:2px;
}
.menu_1{
padding-top:1px;
padding-bottom:1px;
padding-left:2px;
padding-right:2px;
background-color:#cc0000;
text-align:center;
color:#FFFFFF;
margin-right:1px;
margin-top:1px;
margin-bottom:1px;
margin-left:0px;
}
</style>
</head>
<body topmargin="0" leftmargin="0" rightmargin="0" bottommargin="0" bgcolor="#FFFFFF">
<a name="Header" id="Header"></a>
<div style="background-color:#FFFFFF">
<div class="" style="padding-top:3px; padding-left:5px;border-bottom:1px dashed #CCCCCC;"><img src="img/logo_3.gif" alt="动感无限" width="116" height="34"/></div>
<div class="menu">
   <%
   DBMap[] list =action.getList("19");
   String href = null;
   String name = null;
   if(list!=null){
     for(int i = 0;i<list.length;i++){
        if("1".equals(list[i].get(DBInfo.COMMON_IS_SERVICE))){
        href="bk.jsp?id="+list[i].get(DBInfo.COMMON_ID)+str1;
        name=StringUtil.shift(list[i].get(DBInfo.SERVICE_NAME));
   %>
<div class="txtLine">
<a href="<%=href%>"><%=action.getAlias(name)%></a>
<%if(1==img_id[i]){%>
<img src="img/hot_4.gif" alt="Hot" />
<%}if(2==img_id[i]){%>
<img src="img/new_4.gif" alt="New" />
<%}%>
</div>
   <%
       }
     }
   }
   %>
<div class="txtLine">
<span class="menu_1"><a href="list1.jsp?id=10<%=str1%>"><font class="txt2">视频</font></a></span><span class="menu_1"><a href="list1.jsp?id=11<%=str1%>"><font class="txt2">炫铃</font></a></span><span class="menu_1"><a href="list1.jsp?id=12<%=str1%>"><font class="txt2">美图</font></a></span><span class="menu_1"><a href="list1.jsp?id=13<%=str1%>"><font class="txt2">网游</font></a></span>
</div>
  <%
 list =action.getList("20");
   if(list!=null){
     for(int i = 0;i<list.length;i++){
        if("1".equals(list[i].get(DBInfo.COMMON_IS_SERVICE))){
        href="bk.jsp?id="+list[i].get(DBInfo.COMMON_ID)+str1;
        name=StringUtil.shift(list[i].get(DBInfo.SERVICE_NAME));
   %>
<div class="txtLine">
<a href="<%=href%>"><%=action.getAlias(name)%></a>
</div>
   <%
       }
     }
   }
   %>
<div class="txtLine">
<span class="menu_1"><a href="list1.jsp?id=16<%=str1%>"><font class="txt2">影视</font></a></span><span class="menu_1"><a href="list1.jsp?id=15<%=str1%>"><font class="txt2">MP3</font></a></span><span class="menu_1"><a href="list1.jsp?id=14<%=str1%>"><font class="txt2">书城</font></a></span><span class="menu_1"><a href="list1.jsp?id=17<%=str1%>"><font class="txt2">时尚</font></a></span>
</div>
 <%
  list =action.getList("21");

   if(list!=null){
     for(int i = 0;i<list.length;i++){
        if("1".equals(list[i].get(DBInfo.COMMON_IS_SERVICE))){
        href="bk.jsp?id="+list[i].get(DBInfo.COMMON_ID)+str1;
        name=StringUtil.shift(list[i].get(DBInfo.SERVICE_NAME));
   %>
<div class="txtLine">
<a href="<%=href%>"><%=action.getAlias(name)%></a>
</div>
   <%
       }
     }
   }
   %>
<div class="txtLine">
<span class="menu_1"><a href="list1.jsp?id=18<%=str1%>"><font class="txt2">交友</font></a></span><span class="menu_1"><a href="list1.jsp?id=23<%=str1%>"><font class="txt2">星座</font></a></span><span class="menu_1"><a href="list1.jsp?id=24<%=str1%>"><font class="txt2">情感</font></a></span><span class="menu_1"><a href="list1.jsp?id=25<%=str1%>"><font class="txt2">两性</font></a></span>
</div>	
 <%
 list =action.getList("22");
   if(list!=null){
     for(int i = 0;i<list.length;i++){
        if("1".equals(list[i].get(DBInfo.COMMON_IS_SERVICE))){
        href="bk.jsp?id="+list[i].get(DBInfo.COMMON_ID)+str1;
        name=StringUtil.shift(list[i].get(DBInfo.SERVICE_NAME));
   %>
<div class="txtLine">
<a href="<%=href%>"><%=action.getAlias(name)%></a>
</div>
   <%
       }
     }
   }
   %>
   </div>
<div style="text-align:center"><a href="#Header"><font style="color:#999999;">^TOP</font></a></div>
<div class="footer">
＝<a href="bk.jsp?id=1<%=str1%>">客服帮助</font>＝
</div>
</div>
</body>
</html>
