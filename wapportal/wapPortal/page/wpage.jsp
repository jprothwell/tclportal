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
   <%
   DBMap[] list =action.getList("7");
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
</p>
</card>
</wml>
