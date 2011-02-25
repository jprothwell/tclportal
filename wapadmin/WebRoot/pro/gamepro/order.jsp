<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import ="java.util.List"%>
<%@ page import ="java.sql.Date"%>
<%@ page import ="cn.alcatel.wap.db.DBMap"%>
<%@ page import="cn.alcatel.wap.db.DBInfo"%>
<%@ page import="cn.alcatel.wap.db.dao.*"%>
<%
String ua=request.getParameter("ua");
gameDao dao1=new gameDao();
DBMap[] map= dao1.uagameList(ua);
%>
<link href="../../styles/dtree.css" rel="stylesheet" type="text/css" />
<script>
function move(index,to) {
var list = document.form.list;
var total = list.options.length-1;
if (index == -1) return false;
if (to == +1 && index == total) return false;
if (to == -1 && index == 0) return false;
var items = new Array;
var values = new Array;
for (i = total; i >= 0; i--) {
items[i] = list.options[i].text;
values[i] = list.options[i].value;
}
for (i = total; i >= 0; i--) {
if (index == i) {
list.options[i + to] = new Option(items[i],values[i], 0, 1);
list.options[i] = new Option(items[i + to],values[i + to]);
i--;
}
else {
list.options[i] = new Option(items[i], values[i]);
   }
}
list.focus();
}
function submitForm(ua) {
var list = document.form.list;
var theList = "?idlist=";
for (i = 0; i < list.options.length; i++) {
if(i==0)theList +=list.options[i].value;
else theList +=","+list.options[i].value;
}
location.href = document.form.action + theList+"&ua="+ua;
}
</script>
<form method="post" action="saveorder.jsp" name="form">
<input  type="hidden" name="ua" value="<%=ua%>"/>
<table width="100%" border="1" align="center" cellpadding="1" cellspacing="1" class="dtree">
  <tr><td  colspan="2">
<a href="index.jsp">机型游戏管理</a> | <a href="gindex.jsp?ua=<%=ua%>"><%=ua%>游戏管理</a> | <a href="addgame.jsp?ua=<%=ua%>"><%=ua%>游戏添加</a>| <%=ua%>游戏排序
      </td> </tr>
<tr>
<td width="50%" align="right">
 <%
  if(map != null){
    out.println("<select name='list' size='"+map.length+"'>");
    for(int i = 0; i < map.length; i++){
  out.println("<option value='"+map[i].get("id")+"'>"+map[i].get("name")+"("+map[i].get("lg")+")</option>");
    }
    out.println("</select>");
  }
  %>
<br><br>
<input type="button" value="submit" onClick="submitForm('<%=ua%>')">
</td>
<td valign="top" width="50%">
<input type="button" value="↑"
onClick="move(this.form.list.selectedIndex,-1)"><br><br>
<input type="button" value="↓"
onClick="move(this.form.list.selectedIndex,+1)">
</td>
</tr>
</table>
</form>
