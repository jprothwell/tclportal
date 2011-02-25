<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import ="java.util.List"%>
<%@ page import ="java.sql.Date"%>
<%@ page import="cn.alcatel.wap.db.DBInfo"%>
<%@ page import="cn.alcatel.wap.db.dao.pagedb"%>
<%@ page import="cn.alcatel.wap.db.DBMap"%>
<link href="../../styles/dtree.css" rel="stylesheet" type="text/css" />
<script language="JavaScript">
function checkFields(){
if((document.page_fm_edit.pagename.value.length==0)){
	alert("页面名称不能为空！");
	document.page_fm_edit.pagename.focus();
	return false;
}
}
</script>
<%
   int pageid=Integer.parseInt(request.getParameter("pageid"));
   pagedb  dao=new pagedb();
   DBMap[] map=dao.listpage(pageid);
%>
<table width="100%" border="1" align="center" cellpadding="4" cellspacing="1">
  <tr>
    <td class="dtree"><a href="index.jsp">页面信息</a> | 页面信息添加</td>
  </tr>
  <tr><td>
    <form name="page_fm_edit" action="../../pageedit" method="post" enctype="multipart/form-data" class="dtree" onsubmit="return checkFields()">
<table width="100%" border="0" cellspacing="2" cellpadding="2" class="dtree" >

 <input type="hidden" name="pageid"  value="<%=pageid%>">
 <input type="hidden" name="fileName"  value="<%=map[0].get("file1")%>">
<tr>
<td align="right" width="20%">页面名称 : </td>
<td width="80%">
  <input type="text" name="pagename" size="20" value="<%=map[0].get("name")%>">&nbsp;&nbsp;&nbsp;<font color="red">(*必填)</font></td>
</tr>
<tr>
<td align="right" width="20%">页面类型 : </td>
<td width="80%">
<select  name="pagekind">
<%
for(int i=0;i<DBInfo.PAGE_KIND.length;i++){
if(i==Integer.parseInt(map[0].get("kindid").toString())){
out.println("<option value='"+i+"' name='pagekind' selected>"+DBInfo.PAGE_KIND[i]+"</option>");
}else
out.println("<option value='"+i+"' name='pagekind'>"+DBInfo.PAGE_KIND[i]+"</option>");
}
%>
 </select>
</td>
</tr>

<tr>
<td align="right" width="20%">语言 : </td>
<td width="80%">
<select  name="language">
<%
for(int i=0;i<DBInfo.LG_INFO.length;i++){
if(DBInfo.LG_INFO[i].equals(map[0].get("file1").toString())){
out.println("<option name='language' selected>"+DBInfo.LG_INFO[i]+"</option>");
}else
out.println("<option name='language'>"+DBInfo.LG_INFO[i]+"</option>");
}
%>
 </select>
</td>
</tr>


<tr>
<td align="right" width="20%">页面说明 : </td>
<td width="80%">
 <textarea name="pagedescription" cols="30" rows="4"><%=map[0].get("info")%></textarea>
</tr>
<tr>

<tr>
<td align="right" width="20%">页面 :</td>
<td width="80%"><input type="file" name="images" size="40"></td>
</tr>
<tr>
<td width="20%">&nbsp;</td>
<td width="80%"><input type="submit" name="submit" value="提交" ></td>
</tr>
</table>
</form></td>
  </tr>
</table>
