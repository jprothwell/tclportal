<?xml version="1.0" encoding="UTF-8"?>
<%@ page contentType="application/vnd.wap.xhtml+xml;charset=UTF-8"%>
<%@ page import="java.net.URLEncoder,java.util.*" %>
<%@ page import="cn.funstar.wap.util.*,cn.funstar.wap.action.*,cn.funstar.wap.db.*" %>
<%@ page errorPage="error.jsp" %>
<%
 listAction action = new listAction(request);
 Message message = new Message("zh");
 int img_id[]={2,1,1,0,0,0,0,0,0,0,2,1,1};
  String did = action.getDid();
  int rows = action.getRows();
  DBMap[] list = action.getList();
  String prevUrl = action.getPrevUrl();
  String nextUrl = action.getNextUrl();
  String append="";
  append+="did="+did;
%>
<!DOCTYPE html PUBLIC "-//WAPFORUM//DTD XHTML Mobile 1.0//EN" "http://www.wapforum.org/DTD/xhtml-mobile10.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<title>动感无限...</title>
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
<div class="" style="padding-top:3px; padding-left:5px;"><img src="img/logo_3.gif" alt="动感无限" width="116" height="34"/></div>
<div class="menu">
<div class="txtLine" style="background-color:#ededed; color: #666666; border-top:1px dashed #CCCCCC;"><a href="welcome.jsp?<%=append%>">首页</a>>><%=action.getChannelName()!=null?action.getChannelName():message.title()%></div>
<%if(list != null){
    String href = null;
    String name = null;
    String icon = null;
    for(int i = 0; i < list.length; i++){
      if("1".equals(list[i].get(DBInfo.COMMON_IS_SERVICE))){
        href="bk.jsp?"+append+"&amp;id="+list[i].get(DBInfo.COMMON_ID);
        name=StringUtil.shift(list[i].get(DBInfo.SERVICE_NAME));
        //icon=(String)list[i].get(DBInfo.SERVICE_ICON);
      }else{
        href="list2.jsp?"+append+"&amp;id="+list[i].get(DBInfo.COMMON_ID);
        name=StringUtil.shift(list[i].get(DBInfo.CHANNEL_NAME));
        //icon=(String)list[i].get(DBInfo.CHANNEL_ICON);
      }
       %>
       <div class="txtLine">
<a href="<%=href%>" ><font class="txt1"><%=name%></font></a>
</div>
       <%
    }
    //上一页，下一页
    if(action.getTotalpage()>1)
    {
      for(int i =1;i<=action.getTotalpage();i++){
        if(action.getPage()==i){
          %>
          <%=i%>
          <%
        }else{
    %>
    <a href="<%=action.getPrefixUrl()+i%>"><%=i%></a>
    <%
       }
      }
  }
  }else{
    %>
    <%=message.build()%>
    <br />
    <%
  }
%>
<div style="text-align:center"><a href="welcome.jsp?<%=append%>"><%=message.home()%></a></div>
<div style="text-align:center"><a href="#Header"><font style="color:#999999;">^TOP</font></a></div>
<div class="footer">
＝<a href="helpInfo.jsp">客服帮助</font>＝
</div>
</div>
</body>
</html>
<%
    action.log();
%>
