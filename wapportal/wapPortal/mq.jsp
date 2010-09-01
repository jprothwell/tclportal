<?xml version="1.0" encoding="UTF-8"?>
<%@ page contentType="application/vnd.wap.xhtml+xml;charset=UTF-8"%>
<%@ page import="java.net.URLEncoder,java.util.*" %>
<%
String menu="zh_cmcc_index";
//Stat.statIndex(request, menu+"_everytime");//统计
//
String did = request.getParameter("did");
String didStr = "";
if(did !=null && did.length()>0){
	//didStr = "&amp;did="+did;
}
%>
<%
int total=30;
int tnum=0;
String[] name=new String[total];
String[] url=new String[total];
String[] resourceID=new String[total];
String[] provider=new String[total];
String[] href=new String[total];
//
name[tnum]="高清*大片";
url[tnum]="http://my3g.info/nz.jsp?c=2486&t=1&s=video44&k=e362";
resourceID[tnum]="4";
provider[tnum++]="Chinam";
//
name[tnum]="视频[流畅片]";
url[tnum]="http://wap.tom.com/nz/trip.jsp?c=306&t=0";
resourceID[tnum]="44";
provider[tnum++]="Tom";
//
/*2009-2-24 18:56 Aman
name[tnum]="QQ聊天*火";
url[tnum]="http://waprelay.qq.com/r/terminal_6697_alcatel_bt_ring2";
resourceID[tnum]="49";
provider[tnum++]="Tencent";*/
//
name[tnum]="视频直播";
url[tnum]="http://my3g.info/nz.jsp?c=2486&t=1&s=video47&k=e362";
resourceID[tnum]="2";
provider[tnum++]="Chinam";
//
name[tnum]="*极品屏保";
url[tnum]="http://wap.tom.com/wap/misc/sicangwy.jsp?c=306&t=0";
resourceID[tnum]="45";
provider[tnum++]="Tom";
//
name[tnum]="实录视频";
url[tnum]="http://my3g.info/nz.jsp?c=2486&t=1&s=video43&k=e362";
resourceID[tnum]="1";
provider[tnum++]="Chinam";
//
name[tnum]="手机宠物";
url[tnum]="http://wap.tom.com/wap/misc/joinlover.jsp?c=306&t=0";
resourceID[tnum]="46";
provider[tnum++]="Tom";
//
name[tnum]="甜美佳人";
url[tnum]="http://my3g.info/nz.jsp?c=2486&t=1&s=video50&k=e362";
resourceID[tnum]="3";
provider[tnum++]="Chinam";
//
name[tnum]="最流行MP3[嗨曲]MV";
url[tnum]="http://wap.tom.com/nz/allring.jsp?c=306&t=0";
resourceID[tnum]="47";
provider[tnum++]="Tom";
//
name[tnum]="劲片*小电影";
url[tnum]="http://my3g.info/nz.jsp?c=2486&t=1&s=video46&k=e362";
resourceID[tnum]="5";
provider[tnum++]="Chinam";
//
name[tnum]="幸福心语";
url[tnum]="http://my3g.info/nz.jsp?c=2486&t=1&s=video45&k=e362";
resourceID[tnum]="6";
provider[tnum++]="Chinam";
//
name[tnum]="MP3*现场版";
url[tnum]="http://my3g.info/nz.jsp?c=2486&t=1&s=ring49&k=e362";
resourceID[tnum]="7";
provider[tnum++]="Chinam";
//
name[tnum]="美图收藏";
url[tnum]="http://my3g.info/nz.jsp?c=2486&t=1&s=pic52&k=e362";
resourceID[tnum]="8";
provider[tnum++]="Chinam";
//
name[tnum]="真人*整曲*劲播";
url[tnum]="http://my3g.info/nz.jsp?c=2486&t=1&s=ring48&k=e362";
resourceID[tnum]="9";
provider[tnum++]="Chinam";
//
name[tnum]="精美壁纸";
url[tnum]="http://my3g.info/nz.jsp?c=2486&t=1&s=pic81&k=e362";
resourceID[tnum]="10";
provider[tnum++]="Chinam";
//
name[tnum]="美女最爱小游戏";
url[tnum]="http://my3g.info/nz.jsp?c=2486&t=1&s=ani16&k=e362";
resourceID[tnum]="11";
provider[tnum++]="Chinam";
//
name[tnum]="在线小说*珍藏版";
url[tnum]="http://my3g.info/nz.jsp?c=2486&t=1&s=text58&k=e362";
resourceID[tnum]="12";
provider[tnum++]="Chinam";
//
name[tnum]="*搜我喜欢*yesh";
url[tnum]="http://wap.tom.com/nz/swxhyesh.jsp?c=306&t=0";
resourceID[tnum]="25";
provider[tnum++]="Tom";
//
name[tnum]="新[七界传说]最牛网游";
url[tnum]="http://wap.tom.com/nz.jsp?c=306&t=14001";
resourceID[tnum]="26";
provider[tnum++]="Tom";
//
name[tnum]="MP3*现场版";
url[tnum]="http://my3g.info/nz.jsp?c=2486&t=1&s=ring49&k=e362";
resourceID[tnum]="7";
provider[tnum++]="Chinam";
//
name[tnum]="美图收藏";
url[tnum]="http://my3g.info/nz.jsp?c=2486&t=1&s=pic52&k=e362";
resourceID[tnum]="8";
provider[tnum++]="Chinam";
//
name[tnum]="真人*整曲*劲播";
url[tnum]="http://my3g.info/nz.jsp?c=2486&t=1&s=ring48&k=e362";
resourceID[tnum]="9";
provider[tnum++]="Chinam";
//
name[tnum]="精美壁纸";
url[tnum]="http://my3g.info/nz.jsp?c=2486&t=1&s=pic81&k=e362";
resourceID[tnum]="10";
provider[tnum++]="Chinam";
//
name[tnum]="美女最爱小游戏";
url[tnum]="http://my3g.info/nz.jsp?c=2486&t=1&s=ani16&k=e362";
resourceID[tnum]="11";
provider[tnum++]="Chinam";
//
name[tnum]="在线小说*珍藏版";
url[tnum]="http://my3g.info/nz.jsp?c=2486&t=1&s=text58&k=e362";
resourceID[tnum]="12";
provider[tnum++]="Chinam";
//
name[tnum]="*搜我喜欢*yesh";
url[tnum]="http://wap.tom.com/nz/swxhyesh.jsp?c=306&t=0";
resourceID[tnum]="25";
provider[tnum++]="Tom";
//
name[tnum]="新[七界传说]最牛网游";
url[tnum]="http://wap.tom.com/nz.jsp?c=306&t=14001";
resourceID[tnum]="26";
provider[tnum++]="Tom";
%>
<%
for(int i=0;i<tnum;i++){
	if(name[i]!=null && name[i].length()>0){
	href[i]="../go.jsp?menuFlag=0&amp;menu1="+menu+"&amp;resourcename="+resourceID[i]+"&amp;spname="+URLEncoder.encode(provider[i],"UTF-8")+"&amp;go="+URLEncoder.encode(url[i],"UTF-8");//+didStr
	}
}
%>
<!DOCTYPE html PUBLIC "-//WAPFORUM//DTD XHTML Mobile 1.0//EN" "http://www.wapforum.org/DTD/xhtml-mobile10.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<title>游戏 图铃 视频 小说...</title>
<style type="text/css">
body, table, tr, td, form, div, p, h1, h2, h3, h4, a:link, a:visited, a:hover, a {
	margin: 0 0 0 0;
	padding: 0;
	/*font-family: Arial, Verdana, Geneva, Helvetica, sans-serif;*/
	/*font-size: medium;*/
	/*font-style: normal;*/
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
/*div, table, tr, td, img {margin: 0 0 0 0; padding: 0;}*/
#img{
border:0px;
}
.header{
/*font-family: Arial, Verdana, Geneva, Helvetica, sans-serif;*/
background-color:#000000;
color: #FF6633;
text-align :left;
padding-top:3px;
border-bottom:2px solid  #999999;
}
.menu{
/*font-family: Arial, Verdana, Geneva, Helvetica, sans-serif;*/
/*font-size: medium;*/
/*font-weight:normal;*/
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
color: #000000;
}
.indexService{
/*font-size:10px;*/
color:#666666;
}
.footer{
/*font-family: Arial, Verdana, Geneva, Helvetica, sans-serif;*/
/*font-size:10px;*/
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
background-color:#ededed;
text-align:center;
color:#000000;
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
<div class="" style="padding-top:3px; padding-left:5px;"><img src="images/logo_3.gif" alt="动感无限" width="116" height="34"/></div>
<div class="menu">
<div class="txtLine" style="background-color:#ededed; color: #666666; border-top:1px dashed #CCCCCC;"><a href="index_q.jsp">首页</a>>>视频</div>
<%for(int m=0;m<10;m++){
if(name[m]!=null && name[m].length()>0){
%>
<div class="txtLine">
<a href="<%=href[m]%>" title="<%=resourceID[m]%>/<%=m+1%>"><font class="txt1"><%=name[m]%></font></a>
<%
if(m==0 || m==3 || m== 5){
%>
<img src="images/hot_4.gif" alt="Hot" />
<%
}else if(m==1 || m==2 || m==4){
%>
<img src="images/new_4.gif" alt="New" />
<%
}
%>
</div>
<%}
}%>
<%
for(int i=0;i<3;i++ ){
	%>
<div class="txtLine">
<span class="menu_1"><a href="video.jsp?<%=didStr%>" title=""><font class="txt2">视频</font></a></span><span class="menu_1"><a href="rp.jsp?<%=didStr%>" title=""><font class="txt2">铃图</font></a></span><span class="menu_1"><a href="game.jsp?<%=didStr%>" title=""><font class="txt2">游戏</font></a></span><span class="menu_1"><a href="story.jsp?<%=didStr%>" title=""><font class="txt2">小说</font></a></span>
</div>
	<%
}
%>
</div>
<div style="text-align:center"><a href="#Header"><font style="color:#999999;">^TOP</font></a></div>
<div class="footer">
＝<a href="helpInfo.jsp">客服帮助</font>＝
</div>
</div>
</body>
</html>
