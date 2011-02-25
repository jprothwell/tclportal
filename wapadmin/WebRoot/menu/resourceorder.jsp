<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import ="cn.alcatel.wap.db.dao.resourceDao"%>
<%@ page import ="cn.alcatel.wap.db.*"%>
<%@ page import ="java.util.List"%>
<%@ page import ="java.sql.Date"%>
<%
resourceDao dao = new resourceDao();
String idlist= (String)request.getParameter("idlist");
String groupid= (String)request.getParameter("groupid");
//String contentid= (String)request.getParameter("contentid");
//out.println("idlist="+idlist);
//out.println("<br>groupid="+groupid);
//out.println("<br>contentid="+contentid);
int group_id=Integer.parseInt(groupid);
String DBName="imageresource";
switch(group_id){
  case 0:DBName="imageresource"; break;
  case 1:DBName="ringresource"; break;
  case 2:DBName="videosresource"; break;
  case 3:DBName="gameresource"; break;
  case 4:DBName="newsresource"; break;
  case 5:DBName="spresource"; break;
  }
/////////
String[] k=idlist.split(",");
int f=1;
int t=0;
  for(int i=0;i<k.length;i++){
 t=Integer.parseInt(k[i]);
 f = dao.resourceOrder(DBName,t,i);
}
if(f==1)out.print("<script>alert('排序成功，请返回!');opener.location.reload();window.close();</script>");
else out.print("<script>alert('排序失败，请与管理员联系!');history.back();</script>");
%>
