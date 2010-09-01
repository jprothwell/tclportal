<%@ page import="cn.funstar.wap.util.*,cn.funstar.wap.action.*,cn.funstar.wap.db.*" %>
<%
  bkAction action = new bkAction(request);
  String forward = action.getUrl();
  if(forward != null && !forward.equals("")){
  response.sendRedirect(forward);
  }else{
    String homepage = "welcome.jsp?did="+action.getDid();
    Message message = new Message("zh");
%>
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE wml PUBLIC "-//WAPFORUM//DTD WML 1.1//EN" "http://www.wapforum.org/DTD/wml_1.1.xml">
<%@ page contentType="text/vnd.wap.wml;charset=UTF-8" %>
<wml>
<head>
<meta http-equiv="Cache-Control" content="no-cache"/></head>
    <card title="<%=message.title()%>">
    <p><%=message.build()%></p>
    <p><a href="<%=homepage%>"><%=message.home()%></a></p>
    </card>
</wml>
<%
  }
%>
<%
  action.log();
%>
