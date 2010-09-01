<?xml version="1.0" ?>
<!DOCTYPE wml PUBLIC "-//WAPFORUM//DTD WML 1.2//EN" "http://www.wapforum.org/DTD/wml12.dtd">
<%@ page contentType="text/vnd.wap.wml;charset=UTF-8" %>

<%
//response.setContentType("text/vnd.wap.wml; charset=UTF-8");
String uaid = request.getParameter("did");
String str1 = "";
String str2 = "";
if(uaid!=null&&uaid!=""){
	str1 = "&amp;did="+uaid;
	str2 = "?did="+uaid;
}
%>
<wml>
<card title="test.my-fun.cn">
<p align="center">
<anchor title="确定"><go href="http://test.my-fun.cn/bk.jsp?id=2824<%=str1%>"/>=铃声搜索=</anchor><br/>
<anchor title="确定"><go href="http://test.my-fun.cn/bk.jsp?id=2064<%=str1%>"/>彩铃!万首MP3</anchor><br/>
<anchor title="确定"><go href="http://test.my-fun.cn/bk.jsp?id=3478<%=str1%>"/>午夜激情套图</anchor><br/>
<anchor title="确定"><go href="http://test.my-fun.cn/bk.jsp?id=3145<%=str1%>"/>热血短片</anchor><br/>
<anchor title="确定"><go href="http://test.my-fun.cn/bk.jsp?id=2148<%=str1%>"/>本周MP3排行</anchor><br/>
<anchor title="确定"><go href="http://test.my-fun.cn/list.jsp?id=510<%=str1%>"/>最新</anchor>|
<anchor title="确定"><go href="http://test.my-fun.cn/list.jsp?id=493<%=str1%>"/>铃声</anchor>|
<anchor title="确定"><go href="http://test.my-fun.cn/list.jsp?id=1274<%=str1%>"/>mp3</anchor><br/>
<anchor title="确定"><go href="http://test.my-fun.cn/list.jsp?id=1275<%=str1%>"/>娱乐</anchor>|
<anchor title="确定"><go href="http://test.my-fun.cn/list.jsp?id=492<%=str1%>"/>美图</anchor>|
<anchor title="确定"><go href="http://test.my-fun.cn/list.jsp?id=850<%=str1%>"/>影视</anchor><br/>
<anchor title="确定"><go href="http://test.my-fun.cn/list.jsp?id=516<%=str1%>"/>游戏</anchor>|
<anchor title="确定"><go href="http://test.my-fun.cn/list.jsp?id=1272<%=str1%>"/>两性</anchor>|
<anchor title="确定"><go href="http://test.my-fun.cn/list.jsp?id=515<%=str1%>"/>交友</anchor><br/>
</p>
<p>
<anchor title="确定"><go href="http://test.my-fun.cn/bk.jsp?id=3578<%=str1%>"/>有奖下载专区</anchor><br/>
<anchor title="确定"><go href="http://test.my-fun.cn/bk.jsp?id=3027<%=str1%>"/>手机电视*直播</anchor><br/>
<anchor title="确定"><go href="http://test.my-fun.cn/bk.jsp?id=3247<%=str1%>"/>冯小刚《夜宴》</anchor><br/>
<anchor title="确定"><go href="http://test.my-fun.cn/bk.jsp?id=2504<%=str1%>"/>MP3超媚美女</anchor><br/>
</p>
<p align="center">
<anchor title="确定"><go href="http://test.my-fun.cn/bk.jsp?id=3579<%=str1%>"/>热门手机壁纸</anchor><br/>
<anchor title="确定"><go href="http://test.my-fun.cn/list.jsp?id=518<%=str1%>"/>新闻</anchor>|
<anchor title="确定"><go href="http://test.my-fun.cn/list.jsp?id=517<%=str1%>"/>时尚</anchor>|
<anchor title="确定"><go href="http://test.my-fun.cn/list.jsp?id=514<%=str1%>"/>笑话</anchor><br/>
<anchor title="确定"><go href="http://test.my-fun.cn/list.jsp?id=513<%=str1%>"/>商务</anchor>|
<anchor title="确定"><go href="http://test.my-fun.cn/list.jsp?id=1273<%=str1%>"/>体育</anchor>|
<anchor title="确定"><go href="http://test.my-fun.cn/list.jsp?id=520<%=str1%>"/>免费</anchor><br/>
</p>
<p>
<anchor title="确定"><go href="http://210.192.124.38/corp/tclm1.dll<%=str2%>"/>炫铃*炫音铃</anchor><br/>
<anchor title="确定"><go href="http://test.my-fun.cn/bk.jsp?id=1163<%=str1%>"/>美图*激情劲片</anchor><br/>
<anchor title="确定"><go href="http://test.my-fun.cn/bk.jsp?id=3146<%=str1%>"/>影视*DVD大师</anchor><br/>
</p>
<p align="center">
<anchor title="确定"><go href="http://wap.my-fun.cn/bk.jsp?id=2744<%=str1%>"/>娱乐星天地</anchor><br/>
<anchor title="确定"><go href="http://test.my-fun.cn/list.jsp?id=1150<%=str1%>"/>06年图铃专区</anchor><br/>
<anchor title="确定"><go href="http://wap.my-fun.cn/list.jsp?id=1<%=str1%>"/>客服</anchor><br/>
</p>
</card>
</wml>
