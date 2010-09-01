<?xml version="1.0" encoding="utf-8"?><!DOCTYPE wml PUBLIC "-//WAPFORUM//DTD WML 1.1//EN" "http://www.wapforum.org/DTD/wml_1.1.xml">
<%@ page contentType="text/vnd.wap.wml;charset=UTF-8" %>
<wml>
<card title="动感无限客服">
<p>
  尊敬的用户，如果您需要查询、退订WAP产品，请登陆“联通互动视界”，进入“客户服务”，即可根据提示进行查询、退订等操作
</p>
<p>
<%
  String did = request.getParameter("did");
  if(did==null||did.length()==0){
    did="0";
  }
%>
 <a href="welcome.jsp?did=<%=did%>">动感无限首页</a>
</p>
</card>
</wml>
