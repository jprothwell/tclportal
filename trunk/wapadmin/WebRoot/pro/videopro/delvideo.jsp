<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import ="cn.alcatel.wap.db.dao.videoadmin"%>
<%@ page import ="cn.alcatel.wap.db.dao.Configuration"%>
<%@ page import ="servlets.myfile"%>
<%
 int  typeid = Integer.parseInt(request.getParameter("typeid"));
 int  videoid = Integer.parseInt(request.getParameter("videoid"));
 String fileaddr=request.getParameter("fileaddr");
 String picdir=request.getParameter("picdir");
 int delvideoimage=myfile.delFile(Configuration.videopath,fileaddr);
 int delvideo=myfile.delFile(Configuration.videopath,picdir);
 if((1==videoadmin.delete_video(videoid)&&(1==delvideoimage))){
%>
<script type="text/javascript">
   alert('删除成功！');location.href='index.jsp?typeid=<%=typeid%>';
</script>
<%
  }
%>
