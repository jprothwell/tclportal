<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import ="java.util.List"%>
<%@ page import ="java.sql.Date"%>
<%@ page import ="cn.alcatel.wap.db.DBMap"%>
<%@ page import="cn.alcatel.wap.db.DBInfo"%>
<%@ page import="cn.alcatel.wap.db.dao.*"%>
<%
String lg=request.getParameter("lg");
String ua=request.getParameter("ua");
uamenuDao dao1=new uamenuDao();
DBMap[] map= dao1.uamenuList(lg,ua);
%>
<link href="../styles/dtree.css" rel="stylesheet" type="text/css" />
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
function submitForm() {
var list = document.form.list;
var theList = "?idlist=";
for (i = 0; i < list.options.length; i++) {
if(i==0)theList +=list.options[i].value;
else theList +=","+list.options[i].value;
}
location.href = document.form.action + theList;
}
</script>
<form method="post" action="2.jsp" name="form">
<table>
<tr>
<td align="middle">
 <%
  if(map != null){
    out.println("<select name='list' size='"+map.length+"'>");
    for(int i = 0; i < map.length; i++){
  out.println("<option value='"+map[i].get("id")+"'>"+map[i].get("name")+"</option>");
    }
    out.println("</select>");
  }
  %>
<br><br>
<input type="button" value="submit" onClick="submitForm()">
</td>
<td valign="top">
<input type="button" value="↑"
onClick="move(this.form.list.selectedIndex,-1)"><br><br>
<input type="button" value="↓"
onClick="move(this.form.list.selectedIndex,+1)">
</td>
</tr>
</table>
</form>
