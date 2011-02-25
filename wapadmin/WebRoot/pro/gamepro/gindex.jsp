<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import="cn.alcatel.wap.db.DBInfo"%>
<%@ page import="cn.alcatel.wap.db.DBMap"%>
<%@ page import="cn.alcatel.wap.db.dao.gameadmin"%>
<link href="../../styles/dtree.css" rel="stylesheet" type="text/css" />
<!--处理每页的数据-->
<%
String ua=request.getParameter("ua");
String lg=request.getParameter("lg");
gameadmin dao=new gameadmin();
DBMap[] map=null;
if(lg==null)map=dao.uagameList(ua);
else map=dao.uagameList(ua,lg);
%>
<table width="100%" border="1" align="center" cellpadding="1" cellspacing="1" class="dtree">
  <tr><td  colspan="5">
<a href="index.jsp">机型游戏管理</a> | <%=ua%>游戏管理 | <a href="addgame.jsp?ua=<%=ua%>"><%=ua%>游戏添加</a>| <a href="order.jsp?ua=<%=ua%>"><%=ua%>游戏排序</a>
      </td> </tr>
  <tr>
    <td width="13%">游戏ID</td>
    <td width="13%">名称</td>
    <td width="20%">游戏jar包</td>
    <td width="20%">游戏jad包</td>
    <td width="10%">语言</td>
  </tr>
  <form name="frm" action="delmenu.jsp" method="post" class="dtree">
  <input type="hidden" name="ua" value="<%=ua%>"/>
<%
   if(null!=map){
     for(int i=0;i<map.length;i++){
%>
  <tr>
    <td><%=map[i].get("fid")%><input type='checkbox' name='idlist' value='<%=map[i].get("id")%>'></td>
    <td width="10%"><%=map[i].get("name")%></td>
    <td width="10%"><%=map[i].get("file1")%></td>
    <td width="10%"><%=map[i].get("file2")%></td>
    <td width="10%"><%=map[i].get("lg")%></td>
 </tr>
<%
  }
   }else{
  out.print("<tr><td  colspan='5'>目前没有游戏!</td></tr>");
     }
%>
<tr><td  colspan='5'>
    <input type="button" value="全选" onclick="checkAll('idlist')"  class="dtree"/>
  &nbsp;&nbsp;<input type="button" value="取消" onclick="clearAll('idlist')" class="dtree"/>
  &nbsp;&nbsp;<input type="button" value="删除"  class="dtree" onclick="doDel()"/>
  </td></tr>
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
     var message="确定要删除吗?";
    if(confirm(message) == false){
      return false;
    }else{
      frm.submit();
    }
      }
  }
</script>
