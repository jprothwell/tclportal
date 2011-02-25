<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import ="cn.alcatel.wap.db.dao.picres"%>
<%@ page import ="cn.alcatel.wap.db.dao.Configuration"%>
<%@ page import ="cn.alcatel.wap.db.DBInfo"%>
<%@ page import ="servlets.myfile"%>
<%
 int  pic_id = Integer.parseInt(request.getParameter("indexid"));
 int  sizeid = Integer.parseInt(request.getParameter("sizeid"));
 int  kindid = Integer.parseInt(request.getParameter("kindid"));
 String pathview=request.getParameter("pathview");
 String pathpic=request.getParameter("pathpic");
 String viewpath = Configuration.picpath;
 String picpath  = Configuration.picpath;
 /////////////////////
  viewpath=viewpath+DBInfo.FILE_SIZE[sizeid]+Configuration.pathurl;
  viewpath=viewpath+DBInfo.IMAGE_KINDID[kindid]+Configuration.pathurl;
  viewpath=viewpath+"view"+Configuration.pathurl;
  picpath=picpath+DBInfo.FILE_SIZE[sizeid]+Configuration.pathurl;
  picpath=picpath+DBInfo.IMAGE_KINDID[kindid]+Configuration.pathurl;
 pathview=pathview.substring(pathview.lastIndexOf("/")+1);
 pathpic=pathpic.substring(pathpic.lastIndexOf("/")+1);
 int delview=myfile.delFile(viewpath,pathview);
 int delpath=myfile.delFile(picpath,pathpic);
if((1==picres.delete_pic(pic_id)&&(1==delpath))){
%>
<script type="text/javascript">
alert('删除成功！');location.href='index.jsp?sizeid=<%=sizeid%>&amp;kindid=<%=kindid%>';
</script>
<%
  }
%>
