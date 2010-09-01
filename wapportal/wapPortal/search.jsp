<?xml version="1.0" ?>
<!DOCTYPE wml PUBLIC "-//WAPFORUM//DTD WML 1.2//EN" "http://www.wapforum.org/DTD/wml12.dtd">
<%@ page contentType="text/vnd.wap.wml;charset=UTF-8" %>
<%
String uaid = request.getParameter("did");
//if(uaid==null||uaid.length()==0){
//	uaid = "0";
//}
%>
<wml>
<card title="移动搜索">
<p align="left">
搜索：
<input type="text" name="key" maxlength="10"/><br/>
    <anchor>搜网页
		<go href="sh.jsp" method="post">
			<postfield name="k" value="$key"/>
			<postfield name="t" value="baidu"/>
			<postfield name="did" value="<%=uaid%>"/>
		</go>
	</anchor><br/>
	<anchor>铃声
		<go href="sh.jsp" method="post">
			<postfield name="k" value="$key"/>
			<postfield name="t" value="ring"/>
			<postfield name="did" value="<%=uaid%>"/>
		</go>
	</anchor><br/>
	<anchor>图片
		<go href="sh.jsp" method="post">
			<postfield name="k" value="$key"/>
			<postfield name="t" value="pic"/>
			<postfield name="did" value="<%=uaid%>"/>
		</go>
	</anchor><br/>
    <anchor>视频
		<go href="sh.jsp" method="post">
			<postfield name="k" value="$key"/>
			<postfield name="t" value="video"/>
			<postfield name="did" value="<%=uaid%>"/>
		</go>
	</anchor><br/>
    <anchor>图书
		<go href="sh.jsp" method="post">
			<postfield name="k" value="$key"/>
			<postfield name="t" value="book"/>
			<postfield name="did" value="<%=uaid%>"/>
		</go>
	</anchor>       
</p>
<p>
    <a href="welcome.jsp?did=<%=uaid%>">动感无限首页</a>
</p>
</card>
</wml>
