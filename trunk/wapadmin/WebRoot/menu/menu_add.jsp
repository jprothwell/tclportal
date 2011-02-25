<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import ="cn.alcatel.wap.db.dao.menuDao"%>
<%@ page import ="cn.alcatel.wap.db.*"%>
<%@ page import ="java.util.List"%>
<%@ page import ="java.sql.Date"%>
<%
String name= (String)request.getParameter("name");
//String fid = (String)request.getParameter("fid");
int f_id=0;//Integer.parseInt(fid);
String images = (String)request.getParameter("images");
String lg = (String)request.getParameter("lg");
String groupid = (String)request.getParameter("groupid");
int group_id=Integer.parseInt(groupid);
String pageid = (String)request.getParameter("pageid");
int page_id=Integer.parseInt(pageid);
String info = (String)request.getParameter("info");
String rel = (String)request.getParameter("rel");
int rel1=Integer.parseInt(rel);

//out.println("<br>name="+name);
//out.println("<br>fid="+fid);
//out.println("<br>images="+images);
//out.println("<br>lg="+lg);
//out.println("<br>group_id="+group_id);
//out.println("<br>info="+info);

///////////
menuDao dao = new menuDao();
int k=dao.insertMenu(name,f_id,images,lg,group_id,info,page_id,rel1);
//out.println("k="+k);
if(k==1)out.print("<script>alert('输入成功，请返回!');window.location='menu.jsp?lg="+lg+"&groupid="+groupid+"';</script>");
else out.print("<script>alert('保存失败，请与管理员联系!');history.back();</script>");
 %>
