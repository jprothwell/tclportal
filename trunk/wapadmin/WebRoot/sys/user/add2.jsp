<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import="cn.alcatel.wap.db.dao.*"%>
<%@ page import="cn.alcatel.wap.db.*"%>
<%@ page import ="java.util.List"%>
<%@ page import ="java.sql.Date"%>
<%
String user_name = (String)request.getParameter("user_name");
String user_pass = (String)request.getParameter("user_pass");
MD5Util md5dao= new MD5Util();
String temp_pass=md5dao.MD5(user_pass);
String[] role1= request.getParameterValues("role");
//out.println("ppp="+role1);

/////////将数组转化为字符串
  if(role1==null){
    out.print("<script>alert('清输入用户管理权限!');window.location='add.jsp';</script>");
    return;
   }
 //////////////////
 StringBuffer   str   =   new   StringBuffer();
 for(int i=0;i <role1.length;i++){
   if(i>0)str.append(",");
   str.append(role1[i]);
 }
///////////判断用户是否存在
userDao dao = new userDao();
if(dao.checkUser(user_name)){
  out.print("<script>alert('此用户存在，请重新输入!');window.location='add.jsp';</script>");
  return;
  }
  else {
 int k=dao.insertUser(user_name,temp_pass,str.toString());
if(k==1)out.print("<script>alert('输入成功，请返回!');window.location='index.jsp';</script>");
else out.print("<script>alert('保存失败，请与管理员联系!');window.location='add.jsp';</script>");
  }
 %>
