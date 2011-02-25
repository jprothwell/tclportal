<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import="servlets.myfile"%>
<%@ page import="cn.alcatel.wap.db.dao.Configuration"%>
<%@ page import="cn.alcatel.wap.db.dao.pagedb"%>
<html>
<head>
<title>
delpage
</title>
</head>
<body bgcolor="#ffffff">
<%
   int pageid=Integer.parseInt(request.getParameter("pageid"));
   String filename=request.getParameter("filename");
   int delfilestatus=myfile.delFile(Configuration.pageaddress,filename);
   int delcol=pagedb.delete_page(pageid);
   if((1==delfilestatus)&&(1==delcol)){
    out.print("<script>alert('删除成功！');location.href='index.jsp';</script>");
  }
  else{
     out.print("<script>alert('删除不成功！');location.href='index.jsp';</script>");
    }
%>
</body>
</html>
