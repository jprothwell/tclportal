<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import="cn.alcatel.wap.db.DBInfo"%>
<%@ page import="cn.alcatel.wap.db.DBMap"%>
<%@ page import="cn.alcatel.wap.db.dao.gameDao"%>
<%
String ua=request.getParameter("ua");
String perPage=request.getParameter("perPage");
int total_num=0;
int per_page=1;
int total_page=0;
 if(perPage == null || perPage.equals(""))per_page=1;
 else per_page=Integer.parseInt(perPage);
int page_num=200;//DBInfo.PAGE_PER_NUM;
int start_num=(per_page-1)*page_num;
int last_num=per_page-1;
int next_num=per_page+1;
gameDao dao = new gameDao();
total_num=dao.gameTotalnum(ua);
total_page=total_num/page_num+1;
DBMap[] map = dao.gameList(ua,start_num,page_num);
%>
<link href="../../styles/dtree.css" rel="stylesheet" type="text/css" />
<table width="100%" border="1" align="center" cellpadding="1" cellspacing="1" class="dtree">
  <tr><td  colspan="5">
    <a href="index.jsp">机型游戏管理</a> | <a href="gindex.jsp?ua=<%=ua%>"><%=ua%>游戏管理</a> | <%=ua%>游戏添加| <a href="order.jsp?ua=<%=ua%>"><%=ua%>游戏排序</a></td>
    </tr>
  <tr><td colspan="5" align="center">共<%=total_num%>纪录 <%=per_page%>/<%=total_page%>页 <a href="addgame.jsp?ua=<%=ua%>&amp;perPage=1">首页</a>|
    <%
    if(per_page>1)out.println("<a href='addgame.jsp?ua="+ua+"&amp;perPage="+last_num+"'>上页</a>");
     else out.println("上页");
     %>
    |
        <%
    if(per_page<total_page)out.println("<a href='addgame.jsp?ua="+ua+"&amp;perPage="+next_num+"'>下页</a>");
     else out.println("下页");
     %>
    |<a href="addgame.jsp?ua=<%=ua%>&amp;perPage=<%=total_page%>">末页</a></td></tr>
  <tr><td>游戏ID</td><td>游戏名称</td><td>JRR</td><td>JAD</td><td>语言</td></tr>
  </tr>
 <form name="frm" action="addmenu.jsp" method="post" class="dtree">
 <input type="hidden" name="ua" value="<%=ua%>"/>
   <%
  if(map != null){
    for(int i = 0; i < map.length; i++){
      try{
  %>
    <tr>
<td><%=map[i].get("id")%><input type='checkbox' name='idlist' value='<%=map[i].get("id")%>'></td>
<td><%=map[i].get("name")%></td>
<td><%=map[i].get("file1")%></td>
<td><%=map[i].get("file2")%></td>
<td><%=map[i].get("lg")%></td>
</tr>
<%}catch(Exception e){
        e.printStackTrace();
      }
    }
  }
%>
<tr><td colspan="6" class="dtree" >
  <input type="button" value="全选" onclick="checkAll('idlist')"  class="dtree"/>
  &nbsp;&nbsp;<input type="button" value="取消" onclick="clearAll('idlist')" class="dtree"/>
  &nbsp;&nbsp;<input type="button" value="添加"  class="dtree" onclick="doDel()"/></td></tr>
</form>
<tr><td colspan="5" align="center">共<%=total_num%>纪录 <%=per_page%>/<%=total_page%>页 <a href="addgame.jsp?ua=<%=ua%>&amp;perPage=1">首页</a>|
    <%
    if(per_page>1)out.println("<a href='addgame.jsp?ua="+ua+"&amp;perPage="+last_num+"'>上页</a>");
     else out.println("上页");
     %>
    |
        <%
    if(per_page<total_page)out.println("<a href='addgame.jsp?ua="+ua+"&amp;perPage="+next_num+"'>下页</a>");
     else out.println("下页");
     %>
    |<a href="addgame.jsp?ua=<%=ua%>&amp;perPage=<%=total_page%>">末页</a></td></tr>
</table>
<script type="text/javascript">
function checkAll(name){
var el = document.getElementsByTagName('input');
var len = el.length;
for(var i=0; i<len; i++)
{
if((el[i].type=="checkbox") && (el[i].name==name))
{
el[i].checked = true;
}
}
}
function clearAll(name) {
var el = document.getElementsByTagName('input');
var len = el.length;
for(var i=0; i<len; i++)     {
if((el[i].type=="checkbox") && (el[i].name==name)) {
el[i].checked = false;
}
}
}
 function doDel(){
  var a = document.getElementsByName("idlist");
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
     var message="确定<%=ua%>机型添加这些游戏?";
    if(confirm(message) == false){
      return false;
    }else{
      frm.submit();
    }
      }
  }
</script>

