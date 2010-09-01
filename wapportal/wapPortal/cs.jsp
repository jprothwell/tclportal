<?xml version="1.0" encoding="utf-8"?><!DOCTYPE wml PUBLIC "-//WAPFORUM//DTD WML 1.1//EN" "http://www.wapforum.org/DTD/wml_1.1.xml">
<%@ page contentType="text/vnd.wap.wml;charset=UTF-8" %>
<wml>
<card title="动感无限客服">
<p>
   <img src="img/25.gif"/><br/>
   ＝客服帮助＝<br/>
   尊敬的用户，您在下载过程中遇到任何业务相关问题，均可以致电相应的业务所属公司的客服中心或10086进行咨询。<br/>
   ＝资费详解＝<br/>
   尊敬的用户，您在下载具体的业务时，业务所属公司会收取相应的内容信息费，另中国移动按照其现有资费标准收取对应上网访问业务时产生的的GRPS流量费，具体流量费可咨询10086。
   ==申明==<br/>
 
本站所提供的信息和内容由相关服务提供商提供。由于该信息内容的准确性、安全性与合法性产生的一切争议和赔偿责任，均由相关服务提供商负责与承担，与本站无关。
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
