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
   <%//推荐业务1
   DBMap[] list =action.getList("202");
   String href = null;
   String name = null;
   if(list!=null){
     for(int i = 0;i<list.length;i++){
     if("1".equals(list[i].get(DBInfo.COMMON_IS_SERVICE))){
        Object o = list[i].get("url");
        if(o!=null){
        String url=o.toString();
        if(url.startsWith("ivr://")){
           href="wtai://wp/mc;"+url.substring(6);
        }else if(url.startsWith("sms://")){
          break;
        }else {
          href="bk.jsp"+str2+"&amp;id="+list[i].get(DBInfo.COMMON_ID);
        }
        name=StringUtil.shift(list[i].get(DBInfo.SERVICE_NAME));
        }else{
          break;
        }
         %>
         <a href="<%=href%>"><%=name%></a><br/>
         <%
      }
     }
   }   
   %>
   <br/>
   <a href="list3.jsp?id=210<%=str1%>">动感旋风*铃声地带</a><br/>
   <a href="list3.jsp?id=211<%=str1%>">极度热门*酷辣影视</a><br/>
   <a href="list3.jsp?id=212<%=str1%>">时尚体验*语音传情</a><br/>
   <a href="list3.jsp?id=213<%=str1%>">品味生活*娱乐休闲</a><br/>
   <br/>
   <%//首页业务2
   list =action.getList("203");
   if(list!=null){
      for(int i = 0;i<list.length;i++){
       if("1".equals(list[i].get(DBInfo.COMMON_IS_SERVICE))){
        Object o = list[i].get("url");
        if(o!=null){
        String url=o.toString();
        if(url.startsWith("ivr://")){
           href="wtai://wp/mc;"+url.substring(6);
        }else if(url.startsWith("sms://")){
          break;
        }else {
          href="bk.jsp"+str2+"&amp;id="+list[i].get(DBInfo.COMMON_ID);
        }
        name=StringUtil.shift(list[i].get(DBInfo.SERVICE_NAME));
        }else{
          break;
        }
         %>
         <a href="<%=href%>"><%=name%></a><br/>
         <%
      }
     }
   }
   %>
   <a href="bk.jsp?id=98<%=str1%>">客户服务</a>
</p>
</card>
</wml>
