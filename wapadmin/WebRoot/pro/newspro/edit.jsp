<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import="cn.alcatel.wap.db.DBInfo"%>
<%@ page import="cn.alcatel.wap.db.dao.newadmin"%>
<%@ page import ="cn.alcatel.wap.db.DBMap"%>
<link href="../../styles/dtree.css" rel="stylesheet" type="text/css" />
<script language="JavaScript">
function checkFields( ){
if((document.view_fm_add.viewname.value.length==0)){
	alert("请输入名称！");
	document.view_fm_add.viewname.focus();
	return false ;
}
}
</script>

<table width="100%" border="1" align="center" cellpadding="4" cellspacing="1">
<%
  int newsid=Integer.parseInt(request.getParameter("newsid"));
  newadmin dao= new newadmin();
  DBMap[] map =dao.newsList(newsid);
%>
  <tr>
    <td class="dtree"><a href="index.jsp">资讯管理</a> | 添加资讯</td>
  </tr>
  <tr><td>
<form name="view_fm_add" action="../../viewedit" enctype="multipart/form-data" method="post" class="dtree" onsubmit="return checkFields()">
<table width="100%" border="0" cellspacing="2" cellpadding="2" class="dtree" >
<input type="hidden" name="newid" size="30" value="<%=newsid%>">
<input type="hidden" name="fileName" size="30" value="<%=map[0].get("images")%>">
<tr>
<td align="right" width="20%">标题 : </td>
<td width="80%"><input type="text" name="viewname" size="30" value="<%=map[0].get("name")%>"></td>
</tr>

<tr>
<td align="right" width="20%">语言版本 : </td>
<td width="80%">
<%
for(int i=0;i<DBInfo.LG_INFO.length;i++){
if(DBInfo.LG_INFO[i].equals(map[0].get("lg").toString())){
out.println("<input type='radio' value='"+DBInfo.LG_INFO[i]+"' checked name='lg'>"+DBInfo.LG_INFO[i]+"");
}else
out.println("<input type='radio' value='"+DBInfo.LG_INFO[i]+"' name='lg'>"+DBInfo.LG_INFO[i]+"");
}
%>
</tr>
<!--
<tr>
<td align="right" width="20%">类别 : </td>
<td width="80%">
<select  name="kindid">
<%
//for(int i=0;i<DBInfo.NEWS_KINDID.length;i++){
//if(i==0){
//out.println("<option value='"+i+" selected'>"+DBInfo.NEWS_KINDID[i]+"</option>");
//}else
//out.println("<option value='"+i+"'>"+DBInfo.NEWS_KINDID[i]+"</option>");
//}
%>
 </select>
</td>
</tr>-->

<tr>
<td align="right" width="20%">图片 :</td>
<td width="80%"><input type="file" name="images" size="40"></td>
</tr>

<tr>
<td align="right" width="20%">说明 :</td>
<td width="80%"><textarea rows="20" name="newinfo" cols="50"><%=map[0].get("info")%></textarea></td>
</tr>

<tr>
<td width="20%">&nbsp;</td>
<td width="80%"><input type="submit" name="submit" value="提交"></td>
</tr>
</table>
</form></td>
  </tr>
</table>
