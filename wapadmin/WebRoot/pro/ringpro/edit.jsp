<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import ="java.sql.Date"%>
<%@ page import="cn.alcatel.wap.db.DBInfo"%>
<%@ page import="cn.alcatel.wap.db.dao.spadmin"%>
<%@ page import="cn.alcatel.wap.db.dao.ringadmin"%>
<%@ page import ="cn.alcatel.wap.db.DBMap"%>
<%
    int typeid=Integer.parseInt(request.getParameter("typeid"));
    int ringid=Integer.parseInt(request.getParameter("ringid"));
    ringadmin dao= new ringadmin();
    DBMap[] map =dao.listring(ringid);
%>
<link href="../../styles/dtree.css" rel="stylesheet" type="text/css" />
<script language="JavaScript">
function checkFields( ){
if((document.ring_fm_add.ringname.value.length==0)){
	alert("请输入名称！");
	document.ring_fm_add.ringname.focus();
	return false ;
}
}
</script>
<table width="100%" border="1" align="center" cellpadding="4" cellspacing="1">

  <tr>
    <td class="dtree"><a href="index.jsp?typeid=<%=typeid%>">铃声管理</a> | 铃声添加</td>
  </tr>
  <tr><td>
  <form name="ring_fm_add" action="../../ringedit"  enctype="multipart/form-data" method="post" class="dtree" onsubmit="return checkFields()">
<table width="100%" border="0" cellspacing="2" cellpadding="2" class="dtree" >
<input type="hidden" name="ringid" size="30" value="<%=ringid%>">
<input type="hidden" name="typeid" size="30" value="<%=typeid%>">
<input type="hidden" name="fileName" size="30" value="<%=map[0].get("file1")%>">
<tr>
<td align="right" width="20%">名称 : </td>
<td width="80%"><input type="text" name="ringname" size="30" value="<%=map[0].get("name")%>"><font color="red">*</font></td>
</tr>

<tr>
<td align="right" width="20%">语言 : </td>
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

<tr>
<!--<td align="right" width="20%">铃声类型: </td>
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
</tr>-->

<tr>
<td align="right" width="20%">铃声提供商 : </td>
<td width="80%">
<select  name="ringsppro">
 <%
spadmin dao1= new spadmin();
DBMap[] map1 = dao1.listSp();
for(int i=0;i<map1.length;i++){
  if(map[0].get("spid").toString().equals(map1[i].get("id").toString()))
  out.println("<option value='"+map1[i].get("id")+"' selected>"+map1[i].get("sp_name")+"</option>");
else out.println("<option value='"+map1[i].get("id")+"'>"+map1[i].get("sp_name")+"</option>");
}
%>
 </select>
 </td>
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
<td width="80%"><input type="file" name="file1" size="50"></td>
</tr>

<tr>
<td align="right" width="20%">铃声说明</td>
<td width="80%"><textarea rows="4" name="ringinfo" cols="55"><%=map[0].get("info")%></textarea></td>
</tr>

<tr>
<td width="20%">&nbsp;</td>
<td width="80%"><input type="submit" name="submit" value="提交" ></td>
</tr>

</table>
</form></td>
  </tr>
</table>
