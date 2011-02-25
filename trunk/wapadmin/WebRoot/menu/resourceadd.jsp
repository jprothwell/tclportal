<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import ="cn.alcatel.wap.db.dao.resourceDao"%>
<%@ page import ="cn.alcatel.wap.db.*"%>
<%@ page import ="java.util.List"%>
<%@ page import ="java.sql.Date"%>
<%
//////////
String groupid=request.getParameter("groupid");
String ua=request.getParameter("ua");
String lg=request.getParameter("lg");
String urlName="imagemenu.jsp";
int group_id=Integer.parseInt(groupid);
switch(group_id){
  case 0:urlName="imagemenu.jsp?groupid="+groupid; break;
  case 1:urlName="ringmenu.jsp?groupid="+groupid; break;
  case 2:urlName="videomenu.jsp?groupid="+groupid; break;
  case 3:urlName="javamenu.jsp?groupid="+groupid; break;
  case 4:urlName="newsmenu.jsp?groupid="+groupid+"&lg="+lg; break;
  case 5:urlName="spinfomenu.jsp?groupid="+groupid; break;
  }
/////////////
String id= (String)request.getParameter("id");
int id1=Integer.parseInt(id);
String[] role1= request.getParameterValues("idlist");
/////////将数组转化为字符串
 StringBuffer   str   =   new   StringBuffer();
 for(int i=0;i <role1.length;i++){
   if(i>0)str.append(",");
   str.append(role1[i]);
 }

///////////
resourceDao dao = new resourceDao();
int k=dao.editResource(id1,str.toString());
if(k==1)out.print("<script>alert('添加成功，请返回!');window.location='"+urlName+"&id="+id+"&contentid="+str+"';</script>");
else out.print("<script>alert('添加失败，请与管理员联系!');history.back();</script>");
//
%>
