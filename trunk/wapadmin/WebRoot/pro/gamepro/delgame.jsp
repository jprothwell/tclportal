<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import ="cn.alcatel.wap.db.dao.gameadmin"%>
<%@ page import ="cn.alcatel.wap.db.dao.Configuration"%>
<%@ page import ="servlets.myfile"%>
<%
 int  gameid = Integer.parseInt(request.getParameter("gameid"));
 String ua=request.getParameter("ua");
 String gamepic=request.getParameter("gamepic");
 String jar=request.getParameter("jar");
 String jad=request.getParameter("jad");
 String gamepath=Configuration.gamespath+ua+Configuration.pathurl+"view"+Configuration.pathurl;
 String jarpath=Configuration.gamespath+ua+Configuration.pathurl;
 String jadpath=Configuration.gamespath+ua+Configuration.pathurl;
 int delpic=myfile.delFile(gamepath,gamepic);
 int deljar=myfile.delFile(jarpath,jar);
 int deljad=myfile.delFile(jadpath,jad);
 if((1==gameadmin.delete_game(gameid)&&(1==deljar))){
%>
<script type="text/javascript">
   alert('删除成功');location.href='gameindex.jsp?ua=<%=ua%>';
</script>
<%
  } else{
      out.print("<script>alert('删除不成功');location.href='gameindex.jsp?ua=ua';</script>");
    }
%>

