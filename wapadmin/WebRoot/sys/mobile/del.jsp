<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import ="cn.alcatel.wap.db.dao.mobiledb"%>
<%
 int  mobile_id = Integer.parseInt(request.getParameter("indexid"));
 if(mobiledb.delete_mobile(mobile_id)==1){
    out.print("<script>alert('删除文件成功！');location.href='index.jsp';</script>");
 }
%>
