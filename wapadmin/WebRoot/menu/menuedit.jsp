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
String id=request.getParameter("id");
String lg=request.getParameter("lg");
String idlist=null;
int group_id=Integer.parseInt(groupid);
int id1=Integer.parseInt(id);
menuDao dao = new menuDao();
DBMap[] map = dao.menuInfo(id1);
pageDao dao1 = new pageDao();
switch(group_id){
  case 0:idlist="1";break;
  case 1:idlist="2";break;
  case 2:idlist="3";break;
  case 3:idlist="4,5";break;
  case 4:idlist="6,7";break;
 default:idlist="8";break;
  }
DBMap[] map1 = dao1.pageList(idlist);
%>
<link href="../styles/dtree.css" rel="stylesheet" type="text/css" />
<table width="100%" border="1" align="center" cellpadding="4" cellspacing="1">
  <tr>
    <td class="dtree"  colspan="4" width="100%"><a href="menu.jsp?lg=<%=lg%>&amp;groupid=<%=groupid%>"><%=lg%> <%=DBInfo.MENU_GROUP[group_id]%>栏目管理</a> | 栏目修改</td>
  </tr>
  <tr>
  <td>
<form name="frm" action="menu_edit.jsp" method="post" class="dtree" onsubmit="return checkFields()">
<input type="hidden" name="id" value="<%=id%>">
<table width="100%" border="0" cellspacing="2" cellpadding="2" class="dtree" >
<tr>
<td align="right" width="20%">栏目名称<%=map[0].get("pageid")%> : </td>
<td width="80%"><input type="text" name="name" size="20" value="<%=map[0].get("name")%>"><font color=red>&nbsp;*&nbsp;</font></td>
</tr>
<tr>
<td align="right" width="20%">栏目图标: </td>
<td width="80%"><input type="text" name="images" size="20" value="<%=map[0].get("images")%>"></td>
</tr>
<tr>
<td align="right" width="20%">语言: </td>
<td width="80%"><%
for(int i=0;i<DBInfo.LG_INFO.length;i++){
if(lg.equals(DBInfo.LG_INFO[i].toString())){
out.println("<input type='radio' value='"+DBInfo.LG_INFO[i]+"' checked name='lg'>"+DBInfo.LG_INFO[i]+"");
}else
out.println("<input type='radio' value='"+DBInfo.LG_INFO[i]+"' name='lg'>"+DBInfo.LG_INFO[i]+"");
}
%></td>
</tr>
<tr>
<td align="right" width="20%">栏目与业务: </td>
<td width="80%">

<input type="radio" value="0" name="rel" <%if(Integer.parseInt(map[0].get("rel").toString())==0)out.println("checked");%>/>栏目
<input type="radio" value="1" name="rel" <%if(Integer.parseInt(map[0].get("rel").toString())==1)out.println("checked");%>/>业务
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
<textarea rows="4" name="info" cols="40"><%=map[0].get("info")%></textarea><font color=red>
</td>
</tr>
<tr>
<td align="right" width="20%"><font color=red>&nbsp;*&nbsp;</font>选择页面:</td>
<td width="80%"><%
if(map1 != null){
int b=1;
int e=0;
if((map[0].get("pageid")) != null)b=Integer.parseInt(map[0].get("pageid").toString());
  for(int i = 0; i < map1.length; i++){
if((map1[i].get("id")) !=null)e=Integer.parseInt(map1[i].get("id").toString());
//out.println("b="+b+";e="+e);
if(b==e)
out.println("<input type='radio' value='"+map1[i].get("id")+"' checked name='pageid'>"+map1[i].get("name")+"");
else out.println("<input type='radio' value='"+map1[i].get("id")+"' name='pageid'>"+map1[i].get("name")+"");
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
}
</script>
