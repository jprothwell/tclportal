<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import="cn.alcatel.wap.db.dao.spadmin"%>
<%
 int id = Integer.parseInt(request.getParameter("spid"));
 int del=spadmin.delete_sp(id);
 if(1==del){
    out.print("<script>alert('删除成功，请返回!');window.location='index.jsp';</script>");
 }
 else{
         out.print("<script>alert('删除失败，请返回!');window.location='index.jsp';</script>");
 }
 %>
