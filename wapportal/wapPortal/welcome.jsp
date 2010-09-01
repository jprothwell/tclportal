<%@ page contentType="text/vnd.wap.wml;charset=UTF-8" %>
<%@ page import="cn.funstar.wap.util.*,cn.funstar.wap.action.*" %>
<%
if(!MobileParse.isUnicom(request)){
   indexAction action = new indexAction(request);
   String forward = action.getPageUrl();
   //response.sendRedirect(forward);
   this.getServletConfig().getServletContext().getRequestDispatcher("/"+forward).forward(request, response);
   action.log();
}else{
   response.sendRedirect("http://cnwap.my-onetouch.com/unicom/?"+request.getQueryString());
}
%>
