<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE wml PUBLIC "-//WAPFORUM//DTD WML 1.1//EN" "http://www.wapforum.org/DTD/wml_1.1.xml">
<%@ page contentType="text/vnd.wap.wml;charset=UTF-8" %>
<%@ page import="cn.funstar.wap.util.*,cn.funstar.wap.action.*,cn.funstar.wap.db.*" %>
<%@ page errorPage="error.jsp" %>
<%
 listAction action = new listAction(request);
 Message message = new Message("zh");
%>
<wml>
<card title="<%=action.getChannelName()!=null?action.getChannelName():message.title()%>">
<p>
<%
  String did = action.getDid();
  int rows = action.getRows();
  DBMap[] list = action.getList();
  String prevUrl = action.getPrevUrl();
  String nextUrl = action.getNextUrl();
  String append="";
  append+="did="+did;
  if(list != null){
    String href = null;
    String name = null;
    String icon = null;
    for(int i = 0; i < list.length; i++){
      if("1".equals(list[i].get(DBInfo.COMMON_IS_SERVICE))){
        href="bk.jsp?"+append+"&amp;id="+list[i].get(DBInfo.COMMON_ID);
        name=StringUtil.shift(list[i].get(DBInfo.SERVICE_NAME));
        //icon=(String)list[i].get(DBInfo.SERVICE_ICON);
      }else{
        href="list1.jsp?"+append+"&amp;id="+list[i].get(DBInfo.COMMON_ID);
        name=StringUtil.shift(list[i].get(DBInfo.CHANNEL_NAME));
        //icon=(String)list[i].get(DBInfo.CHANNEL_ICON);
      }
       %>
       <a href="<%=href%>"><%=name%></a><br/>
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
</p>
<p>
    <a href="welcome.jsp?<%=append%>"><%=message.home()%></a>
</p>
</card>
</wml>
<%
    action.log();
%>
