<%@ page contentType="text/html; charset=UTF-8" %>
<%@ page import ="java.io.*"%>
<%@ page import="java.util.*" %>
<%
String sessuserName=(String)session.getAttribute("sessionUsername");
String sessuserRole=(String)session.getAttribute("sessionRole");
int tickn1=0;
int tickn2=0;
int tickn3=0;
int tickn4=0;
if (sessuserName==null || sessuserRole==null){
out.println("<script language='javascript'>function al(){alert('对不起，请登陆!');return false;}al();location.href='login.jsp';</script>");
return;
}else{
  ////////////////////////////
  String[] kn=sessuserRole.split(",");
  for(int i=0;i<kn.length;i++){
    if(kn[i].equals("1"))tickn1=1;
    if(kn[i].equals("2"))tickn2=1;
    if(kn[i].equals("3"))tickn3=1;
    if(kn[i].equals("4"))tickn4=1;
    }
  /////////////////////////////////
  }
%>


