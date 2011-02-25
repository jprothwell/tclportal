<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import ="java.util.List"%>
<%@ page import ="java.sql.Date"%>
<%@ page import="cn.alcatel.wap.db.DBInfo"%>
<link href="../../styles/dtree.css" rel="stylesheet" type="text/css" />
<script language="JavaScript">
function checkFields(){
if((document.page_fm_add.pagename.value.length==0)){
	alert("页面名称不能为空！");
	document.page_fm_add.pagename.focus();
	return false;
}
}
</script>
<table width="100%" border="1" align="center" cellpadding="4" cellspacing="1">
  <tr>
    <td class="dtree"><a href="index.jsp">页面信息</a> | 页面信息添加</td>
  </tr>
  <tr><td>
    <form name="page_fm_add" action="../../pageadd" method="post" enctype="multipart/form-data" class="dtree" onsubmit="return checkFields()">
<input type="hidden" name="urlName" value="/wapPortal/jsp/" />
<table width="100%" border="0" cellspacing="2" cellpadding="2" class="dtree" >
<tr>
<td align="right" width="20%">页面名称 : </td>
<td width="80%">
  <input type="text" name="pagename" size="20"><font color="red">&nbsp;&nbsp;&nbsp;(*必填)</font></td>
</tr>
<tr>
<td align="right" width="20%">页面类型 : </td>
<td width="80%">
<select  name="pagekind">
<%
for(int i=0;i<DBInfo.PAGE_KIND.length;i++){
if(i==0){
out.println("<option value='"+i+"' name='pagekind'>"+DBInfo.PAGE_KIND[i]+"</option>");
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
if(i==0){
out.println("<option name='screen_size' 'selected'>"+DBInfo.LG_INFO[i]+"</option>");
}else
out.println("<option name='screen_size'>"+DBInfo.LG_INFO[i]+"</option>");
}
%>
 </select>
</td>
</tr>


<tr>
<td align="right" width="20%">页面说明 : </td>
<td width="80%">
 <textarea name="pagedescription" cols="30" rows="4"></textarea>
</tr>
<tr>

<tr>
<td align="right" width="20%">页面 :</td>
<td width="80%"><input type="file" name="images" size="40"><font color="red">&nbsp;&nbsp;&nbsp;(*必填)</font></td>
</tr>
<tr>
<td width="20%">&nbsp;</td>
<td width="80%"><input type="submit" name="submit" value="提交" ></td>
</tr>
</table>
</form></td>
  </tr>
</table>
