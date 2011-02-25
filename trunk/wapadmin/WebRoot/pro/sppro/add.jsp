<%@ page contentType="text/html; charset=UTF-8" %>
<%@ page import ="java.util.List"%>
<%@ page import ="java.sql.Date"%>
<%@ page import="cn.alcatel.wap.db.DBInfo"%>
<%
int kindid=Integer.parseInt(request.getParameter("kindid"));
%>
<link href="../../styles/dtree.css" rel="stylesheet" type="text/css" />
<script language="JavaScript">
function checkFields( ){
if((document.fm_add.user_name.value.length==0)){
	alert("Please enter your login name.");
	document.fm_add.user_name.focus();
	return false ;
}
if((document.fm_add.user_pass.value.length==0) || (document.fm_add.user_pass2.value.length==0)){
	alert("Please enter your password.");
	document.fm_add.user_pass.focus();
	return false ;
}
if((document.fm_add.user_pass.value != document.fm_add.user_pass2.value)){
	alert("Please enter your password right.");
	document.fm_add.user_pass.focus();
	return false ;
}
}
</script>
<table width="100%" border="0" align="center" cellpadding="4" cellspacing="1">
  <tr>
    <td class="dtree"><a href="index.jsp?kindid=<%=kindid%>">图片管理</a> | 图片添加</td>
  </tr>
  <tr><td>
    <form name="fm_add" action="add2.jsp" method="post" class="dtree" onsubmit="return checkFields()">
<table width="540" border="0" cellspacing="2" cellpadding="2" class="dtree" >
<tr>
<td align="right">图片名称 : </td>
<td><input type="text" name="user_name" size="59"></td>
</tr>
<tr>
<td align="right">图片规格: </td>
<td>
<select  name="D1">
<%
for(int i=0;i<DBInfo.IMAGE_INFO.length;i++){
	if(kindid==i){
out.println("<option value="+i+" selected>"+DBInfo.IMAGE_INFO[i]+"</option>");
}else
out.println("<option value="+i+">"+DBInfo.IMAGE_INFO[i]+"</option>");
	}
%>
 </select>
</td>
</tr>
<tr>
<td align="right">小图片</td>
<td><input type="file" name="file1" size="60"></td>
</tr>
<tr>
<td align="right">大图片</td>
<td><input type="file" name="file2" size="60"></td>
</tr>
<tr>
<td>&nbsp;</td>
<td><input type="submit" name="submit" value="submit"></td>
</tr>
<tr>
<td colspan="2">&nbsp;</td>
</tr>
</table>
</form></td>
  </tr>
</table>
