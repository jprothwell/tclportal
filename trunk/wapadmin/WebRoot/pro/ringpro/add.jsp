<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import ="java.sql.Date"%>
<%@ page import="cn.alcatel.wap.db.DBInfo"%>
<%@ page import="cn.alcatel.wap.db.dao.ringadmin"%>
<%
    int typeid=Integer.parseInt(request.getParameter("typeid"));
%>
<link href="../../styles/dtree.css" rel="stylesheet" type="text/css" />
<script language="JavaScript">
function checkFields( ){
if((document.ring_fm_add.ringname.value.length==0)){
	alert("请输入名称！");
	document.ring_fm_add.ringname.focus();
	return false ;
}
if((document.ring_fm_add.file1.value.length==0)){
	alert("请输入铃声文件！");
	document.ring_fm_add.file1.focus();
	return false ;
}
}
</script>
<table width="100%" border="1" align="center" cellpadding="4" cellspacing="1">

  <tr>
    <td class="dtree"><a href="index.jsp?typeid=<%=typeid%>">铃声管理</a> | 铃声添加</td>
  </tr>
  <tr><td>
  <form name="ring_fm_add" action="../../ringadd"  enctype="multipart/form-data" method="post" class="dtree" onsubmit="return checkFields()">
<table width="100%" border="0" cellspacing="2" cellpadding="2" class="dtree" >

<tr>
<td align="right" width="20%">名称 : </td>
<td width="80%"><input type="text" name="ringname" size="30"><font color="red">*</font></td>
</tr>

<tr>
<td align="right" width="20%">语言 : </td>
<td width="80%">
<%
for(int i=0;i<DBInfo.LG_INFO.length;i++){
if(i==0){
out.println("<input type='radio' value='"+DBInfo.LG_INFO[i]+"' checked name='lg'>"+DBInfo.LG_INFO[i]+"");
}else
out.println("<input type='radio' value='"+DBInfo.LG_INFO[i]+"' name='lg'>"+DBInfo.LG_INFO[i]+"");
}
%>
</tr>

<tr>
<td align="right" width="20%">铃声类型: </td>
<td width="80%">
<%
for(int i=0;i<DBInfo.RING_TYPEID.length;i++){
if(i==typeid){
out.println("<input type='radio' value='"+i+"' checked name='typeid'>"+DBInfo.RING_TYPEID[i]+"");
}else
out.println("<input type='radio' value='"+i+"' name='typeid'>"+DBInfo.RING_TYPEID[i]+"");
}
%>
</td>
</tr>

<tr>
<td align="right" width="20%">铃声提供商 : </td>
<td width="80%">
<select  name="ringsppro">
<%
  cn.alcatel.wap.db.DBMap[] sp=ringadmin.get_sp_info();
  if(null==sp){
        out.print("无提供商");
    }
  else{
  for(int i=0;i<sp.length;i++){
      out.print("<option value='"+Integer.parseInt(sp[i].get("id").toString())+"' name='ringsppro'>"+sp[i].get("spname").toString()+"</option>");
    }
  }
%>
 </select></td>
 </select></td>
</tr>

<tr>
<td align="right" width="20%">铃声类别 : </td>
<td width="80%">
<select  name="typeid">
<%
for(int i=0;i<DBInfo.IMAGE_KINDID.length;i++){
if(i==0){
out.println("<option value='"+i+" selected'>"+DBInfo.IMAGE_KINDID[i]+"</option>");
}else
out.println("<option value='"+i+"'>"+DBInfo.IMAGE_KINDID[i]+"</option>");
}
%>
 </select>
 </td>
</tr>

<tr>
<td align="right" width="20%">铃声文件</td>
<td width="80%"><input type="file" name="file1" size="50"><font color="red">*</font></td>
</tr>

<tr>
<td align="right" width="20%">铃声说明</td>
<td width="80%"><textarea rows="4" name="ringinfo" cols="55"></textarea></td>
</tr>

<tr>
<td width="20%">&nbsp;</td>
<td width="80%"><input type="submit" name="submit" value="提交" ></td>
</tr>

</table>
</form></td>
  </tr>
</table>
