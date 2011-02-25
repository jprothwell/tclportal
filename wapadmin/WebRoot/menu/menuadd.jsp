<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import ="java.util.List"%>
<%@ page import ="java.sql.Date"%>
<%@ page import ="cn.alcatel.wap.db.DBMap"%>
<%@ page import="cn.alcatel.wap.db.DBInfo"%>
<%@ page import="cn.alcatel.wap.util.StringUtil"%>
<%@ page import="cn.alcatel.wap.db.dao.*"%>
<%
String groupid=request.getParameter("groupid");
String lg=request.getParameter("lg");
String idlist=null;
int group_id=Integer.parseInt(groupid);
pageDao dao = new pageDao();
switch(group_id){
  case 0:idlist="1";break;
  case 1:idlist="2";break;
  case 2:idlist="3";break;
  case 3:idlist="4,5";break;
  case 4:idlist="6,7";break;
 default:idlist="8";break;
  }

DBMap[] map = dao.pageList(idlist);
%>
<link href="../styles/dtree.css" rel="stylesheet" type="text/css" />
<table width="100%" border="1" align="center" cellpadding="4" cellspacing="1">
  <tr>
    <td class="dtree"  colspan="4" width="100%"><a href="menu.jsp?lg=<%=lg%>&amp;groupid=<%=groupid%>"><%=lg%> <%=DBInfo.MENU_GROUP[group_id]%>栏目管理</a> | 栏目添加</td>
  </tr>
  <tr>
  <td>
    <form name="frm" action="menu_add.jsp" method="post" class="dtree" onsubmit="return checkFields()">
<!--	<input type="hidden" name="fid" value="">-->
<table width="100%" border="0" cellspacing="2" cellpadding="2" class="dtree" >
<tr>
<td align="right" width="20%"><font color=red>&nbsp;*&nbsp;</font>栏目名称 : </td>
<td width="80%"><input type="text" name="name" size="20"></td>
</tr>
<!--<tr>
<td align="right" width="20%">上级栏目: </td>
<td width="80%"><input id="parentName" class="input" disabled="disabled"  size="20"/><font color=red>&nbsp;*&nbsp;</font></td>
</tr>-->
<tr>
<td align="right" width="20%">栏目图标: </td>
<td width="80%"><input type="text" name="images" size="20"></td>
</tr>
<tr>
<td align="right" width="20%">语言: </td>
<td width="80%"><%
for(int i=0;i<DBInfo.LG_INFO.length;i++){
if(lg.equals(DBInfo.LG_INFO[i])){
out.println("<input type='radio' value='"+DBInfo.LG_INFO[i]+"' checked name='lg'>"+DBInfo.LG_INFO[i]+"");
}else
out.println("<input type='radio' value='"+DBInfo.LG_INFO[i]+"' name='lg'>"+DBInfo.LG_INFO[i]+"");
}
%></td>
</tr>
<tr>
<td align="right" width="20%">栏目还是业务: </td>
<td width="80%">
<input type="radio" value="0" name="rel" checked="checked" />栏目
<input type="radio" value="1" name="rel" />业务
 </td>
</tr>
<tr>
<td align="right" width="20%">所属栏目组: </td>
<td width="80%">
<%
for(int i=0;i<DBInfo.MENU_GROUP.length;i++){
if(group_id==i){
out.println("<input type='radio' value='"+i+"' checked name='groupid'>"+DBInfo.MENU_GROUP[i]+"");
}else
out.println("<input type='radio' value='"+i+"' name='groupid'>"+DBInfo.MENU_GROUP[i]+"");
}
%>
</tr>
<tr>
<td align="right" width="20%">栏目说明 : </td>
<td width="80%">
<textarea rows="4" name="info" cols="40"></textarea><font color=red>
</td>
</tr>
<tr>
<td align="right" width="20%"><font color=red>&nbsp;*&nbsp;</font>选择页面: </td>
<td width="80%"><%
if(map != null){
    for(int i = 0; i < map.length; i++){
if(i==0)out.println("<input type='radio' value='"+map[i].get("id")+"' checked name='pageid'>"+map[i].get("name")+"");
else out.println("<input type='radio' value='"+map[i].get("id")+"' name='pageid'>"+map[i].get("name")+"");
if((i+1)%2==0)out.print("<br>");
}
}
%>

</td>
</tr>
<tr>
<td width="20%">&nbsp;</td>
<td width="80%"><input type="submit" name="submit" value="submit"></td>
</tr>
</table>
</form></td>
  </tr>
</table>
<script language="JavaScript">
function checkFields( ){
if((document.frm.name.value.length==0)){
	alert("Please enter menu name.");
	document.frm.name.focus();
	return false ;
}
if((document.frm.pageid.value.length==0)){
	alert("Please select page name.");
	document.frm.pageid.focus();
	return false ;
}
}
</script>
