<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import ="cn.alcatel.wap.db.dao.ringadmin"%>
<%@ page import ="cn.alcatel.wap.db.dao.Configuration"%>
<%@ page import ="servlets.myfile"%>
<%
 int  typeid = Integer.parseInt(request.getParameter("typeid"));
 int  ringid = Integer.parseInt(request.getParameter("ringid"));
 String fileaddr=request.getParameter("fileaddr");
 int delring=myfile.delFile(Configuration.ringpath,fileaddr);
 if((1==ringadmin.delete_ring(ringid)&&(1==delring))){
%>
<script type="text/javascript">
   alert('删除成功！');location.href='index.jsp?typeid=<%=typeid%>';
</script>
<%
  }
%>
