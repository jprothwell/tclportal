<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import ="java.util.List"%>
<%@ page import ="java.sql.Date"%>
<%@ page import ="cn.alcatel.wap.db.DBMap"%>
<%@ page import="cn.alcatel.wap.db.DBInfo"%>
<%@ page import="cn.alcatel.wap.db.dao.*"%>
<%
String id=request.getParameter("id");
String lg=request.getParameter("lg");
String ua=request.getParameter("ua");
resourceDao dao = new resourceDao();
String perPage=request.getParameter("perPage");
int total_num=0;
int per_page=1;
int total_page=0;
 if(perPage==null || perPage.equals(""))per_page=1;
 else per_page=Integer.parseInt(perPage);
int page_num=200;//DBInfo.PAGE_PER_NUM;
int start_num=(per_page-1)*page_num;
int last_num=per_page-1;
int next_num=per_page+1;
total_num=dao.gameTotalnum(lg,ua);
if((total_num % page_num)==0) total_page=total_num/page_num;
else total_page=total_num/page_num+1;
DBMap[] map1 = dao.gameList(ua,lg,start_num,page_num);
%>
<link href="../styles/dtree.css" rel="stylesheet" type="text/css" />
<table width="100%" border="1" align="center" cellpadding="1" cellspacing="1" class="dtree">
<tr><td colspan="5" align="center">共<%=total_num%>纪录 <%=per_page%>/<%=total_page%>页 <a href="javamenu.jsp?id=<%=id%>&amp;perPage=1">首页</a>|
    <%
    if(per_page>1)out.println("<a href='javamenu.jsp?id="+id+"&amp;perPage="+last_num+"'>上页</a>");
     else out.println("上页");
     %>
    |
        <%
    if(per_page<total_page)out.println("<a href='javamenu.jsp?id="+id+"&amp;perPage="+next_num+"'>下页</a>");
     else out.println("下页");
     %>
    |<a href="javamenu.jsp?id=<%=id%>&amp;perPage=<%=total_page%>">末页</a></td></tr>
    <tr>
 <tr><td>id</td><td>游戏名称</td><td>jad</td><td>jar</td><td>语言</td></tr>
  </tr>
   <%
  if(map1 != null){
    for(int i = 0; i < map1.length; i++){
      try{
  %>
<tr>
  <td><%=map1[i].get("id")%></td>
  <td><%=map1[i].get("name")%></td>
  <td><%=map1[i].get("file1")%></td>
  <td><%=map1[i].get("file2")%></td>
  <td><%=map1[i].get("lg")%></td>
</tr>
<%}catch(Exception e){
        e.printStackTrace();
      }
    }
  }
%>
<tr><td colspan="5" align="center">共<%=total_num%>纪录 <%=per_page%>/<%=total_page%>页 <a href="javamenu.jsp?id=<%=id%>&amp;perPage=1">首页</a>|
    <%
    if(per_page>1)out.println("<a href='javamenu.jsp?id="+id+"&amp;perPage="+last_num+"'>上页</a>");
     else out.println("上页");
     %>
    |
        <%
    if(per_page<total_page)out.println("<a href='javamenu.jsp?id="+id+"&amp;perPage="+next_num+"'>下页</a>");
     else out.println("下页");
     %>
    |<a href="javamenu.jsp?id=<%=id%>&amp;perPage=<%=total_page%>">末页</a></td></tr></table>
