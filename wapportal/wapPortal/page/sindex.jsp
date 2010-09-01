<?xml version="1.0" ?>
<!DOCTYPE wml PUBLIC "-//WAPFORUM//DTD WML 1.2//EN" "http://www.wapforum.org/DTD/wml12.dtd">
<%@ page contentType="text/vnd.wap.wml;charset=UTF-8" %>
<%
String uaid = request.getParameter("did");
String lg ="zh1";
String str1 = "";
if(uaid!=null&&uaid.length()>0){
	str1 = "&amp;did="+uaid+"&amp;lg="+lg;
}
%>
<wml>
<card title="My one touch">
<p>
<anchor title="确定"><go href="../bk.jsp?id=1<%=str1%>"/>网络资讯箱</anchor><br/>
<anchor title="确定"><go href="../list.jsp?id=5<%=str1%>"/>Eurosport 视频片段</anchor><br/>
<anchor title="确定"><go href="../list.jsp?id=6<%=str1%>"/>和弦旋律</anchor><br/>
<anchor title="确定"><go href="../list.jsp?id=7<%=str1%>"/>Alcatel 视频片段</anchor><br/>
<anchor title="确定"><go href="../list.jsp?id=8<%=str1%>"/>图片</anchor><br/>
<anchor title="确定"><go href="../list.jsp?id=9<%=str1%>"/>相框</anchor><br/>
<anchor title="确定"><go href="../list.jsp?id=10<%=str1%>"/>游戏及应用</anchor><br/>
</p>

<p>
搜索：
<input type="text" name="key" emptyok="true" maxlength="10"/>
	<br/>
	<anchor>新闻
		<go href="../sh.jsp" method="post">
			<postfield name="k" value="$key"/>
			<postfield name="type" value="news"/>
		</go>
	</anchor>|
	<anchor>图片
		<go href="../sh.jsp" method="post">
			<postfield name="k" value="$key"/>
			<postfield name="type" value="picture"/>
		</go>
	</anchor>|
	<anchor>铃声
		<go href="../sh.jsp" method="post">
			<postfield name="k" value="$key"/>
			<postfield name="type" value="ring"/>
		</go>
	</anchor>|
	<anchor>全部
		<go href="../sh.jsp" method="post">
			<postfield name="k" value="$key"/>
			<postfield name="type" value="game"/>
		</go>
	</anchor>
</p>

</card>
</wml>
