<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import ="java.util.List"%>
<%@ page import ="java.sql.Date"%>
<%@ page import ="cn.alcatel.wap.db.DBMap"%>
<%@ page import="cn.alcatel.wap.db.DBInfo"%>
<%@ page import="cn.alcatel.wap.db.dao.*"%>
<%
String id=request.getParameter("id");
String contentid=request.getParameter("contentid");
String lg=request.getParameter("lg");
String ua=request.getParameter("ua");
String groupid=request.getParameter("groupid");
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
DBMap[] map1 = dao.gameList(lg,start_num,page_num);
//out.println("contentid="+contentid);
%>
<link href="../styles/dtree.css" rel="stylesheet" type="text/css" />
<style type="text/css">
<!--
BODY {
	MARGIN: 10px
}
.ad {
	MARGIN-TOP: 30px; PADDING-TOP: 10px
}
.macrolong_tabPane {
	BORDER-BOTTOM: #919b9c 1px solid; HEIGHT: 21px
}
.macrolong_aTab {
	BORDER-RIGHT: #919b9c 1px solid; PADDING-RIGHT: 5px; PADDING-LEFT: 5px; PADDING-BOTTOM: 5px; BORDER-LEFT: #919b9c 1px solid; PADDING-TOP: 5px; BORDER-BOTTOM: #919b9c 1px solid; FONT-FAMILY: Trebuchet MS, Lucida Sans Unicode, Arial, sans-serif
}
.macrolong_tabPane DIV {
	BACKGROUND-POSITION: left bottom; PADDING-LEFT: 3px; FLOAT: left; MARGIN-LEFT: 0px; VERTICAL-ALIGN: middle; CURSOR: pointer; BOTTOM: -1px; MARGIN-RIGHT: 0px; BACKGROUND-REPEAT: no-repeat; POSITION: relative; HEIGHT: 100%
}
.macrolong_tabPane .tabActive {
	Z-INDEX: 10; BACKGROUND-IMAGE: url(images/tab_left_active.gif); MARGIN-LEFT: 0px; MARGIN-RIGHT: 0px
}
.macrolong_tabPane .tabInactive {
	Z-INDEX: 1; BACKGROUND-IMAGE: url(images/tab_left_inactive.gif); MARGIN-LEFT: 0px; MARGIN-RIGHT: 0px
}
.macrolong_tabPane .inactiveTabOver {
	BACKGROUND-IMAGE: url(images/tab_left_over.gif); MARGIN-LEFT: 0px; MARGIN-RIGHT: 0px
}
.macrolong_tabPane SPAN {
	PADDING-RIGHT: 3px; PADDING-LEFT: 3px; FONT-SIZE: 11px; FLOAT: left; VERTICAL-ALIGN: top; LINE-HEIGHT: 21px; FONT-FAMILY: arial
}
.macrolong_tabPane .tabActive SPAN {
	PADDING-BOTTOM: 1px; LINE-HEIGHT: 20px
}
.macrolong_tabPane IMG {
	FLOAT: left
}
-->
</style>
<table width="100%" border="1" align="center" cellpadding="1" cellspacing="1" class="dtree">
<tr><td colspan="6" align="center">共<%=total_num%>纪录 <%=per_page%>/<%=total_page%>页 <a href="gamemenu.jsp?id=<%=id%>&amp;contentid=<%=contentid%>&amp;perPage=1">首页</a>|
    <%
    if(per_page>1)out.println("<a href='gamemenu.jsp?id="+id+"&amp;contentid="+contentid+"&amp;perPage="+last_num+"'>上页</a>");
     else out.println("上页");
     %>
    |
        <%
    if(per_page<total_page)out.println("<a href='gamemenu.jsp?id="+id+"&amp;contentid="+contentid+"&amp;perPage="+next_num+"'>下页</a>");
     else out.println("下页");
     %>
    |<a href="gamemenu.jsp?id=<%=id%>&amp;contentid=<%=contentid%>&amp;perPage=<%=total_page%>">末页</a></td></tr>
   <tr><td>id</td><td>游戏名称</td><td>jad</td><td>jar</td><td>语言</td></tr>
  <form name="frm" action="gameadd.jsp" method="post" class="dtree">
  <input type="hidden" name="id" value="<%=id%>"/>
   <%
  if(map1 != null){
    for(int i = 0; i < map1.length; i++){
      try{
  %>
<tr><td>
  <%
  out.println(map1[i].get("id"));
  boolean t=false;
  if(contentid.equals("null")||contentid.length()==0)t=false;
  else {
  if(Integer.parseInt(contentid)==Integer.parseInt(map1[i].get("id").toString()))t=true;
  }
   if(t) out.println("<input type='radio' value='"+map1[i].get("id")+"' name='contentid' checked='checked' />");
  else out.println("<input type='radio' value='"+map1[i].get("id")+"' name='contentid' />");
 %>
 </td>
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
<tr><td colspan="6" class="dtree" >
  <input type="button" class="dtree" value="返回" onclick="history.back();"/>
  <input class="dtree" type="button" value="选择" onclick="doAdd()"/></td></tr>
</form>
<tr><td colspan="6" align="center">共<%=total_num%>纪录 <%=per_page%>/<%=total_page%>页 <a href="gamemenu.jsp?id=<%=id%>&amp;contentid=<%=contentid%>&amp;perPage=1">首页</a>|
    <%
    if(per_page>1)out.println("<a href='gamemenu.jsp?id="+id+"&amp;contentid="+contentid+"&amp;perPage="+last_num+"'>上页</a>");
     else out.println("上页");
     %>
    |
        <%
    if(per_page<total_page)out.println("<a href='gamemenu.jsp?id="+id+"&amp;contentid="+contentid+"&amp;perPage="+next_num+"'>下页</a>");
     else out.println("下页");
     %>
    |<a href="gamemenu.jsp?id=<%=id%>&amp;contentid=<%=contentid%>&amp;perPage=<%=total_page%>">末页</a></td></tr></table>
<script type="text/javascript">
 function doAdd(){
  var a = document.getElementsByName("contentid");
  var n = a.length;
  var k = 0;
  for (var i=0; i<n; i++){
    if(a[i].checked)k = 1;
    }
if(k==0){
        alert("Please select delete id.");
	return false ;
    }
    else
    {
      frm.submit();
      }
  }
</script>
