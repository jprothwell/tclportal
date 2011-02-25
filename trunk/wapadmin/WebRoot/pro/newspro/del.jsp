<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import ="cn.alcatel.wap.db.dao.newadmin"%>
<%@ page import ="cn.alcatel.wap.db.dao.Configuration"%>
<%@ page import ="servlets.myfile"%>
<%
 int  new_id = Integer.parseInt(request.getParameter("indexid"));
 String picdir=request.getParameter("picdir");
 myfile.delFile(Configuration.newspath,picdir);
 if(newadmin.delete_mobile(new_id)==1){
    out.print("<script>alert('删除成功！');location.href='index.jsp';</script>");
 }
%>
