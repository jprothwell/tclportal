<%@ page import="cn.funstar.wap.util.*" %>
<%
if(MobileParse.isUnicom(request)){
  response.sendRedirect("http://cnwap.my-onetouch.com/?"+request.getQueryString());
}
%>


