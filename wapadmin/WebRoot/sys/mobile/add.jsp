<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import ="java.util.List"%>
<%@ page import ="java.sql.Date"%>
<%@ page import="cn.alcatel.wap.db.DBInfo"%>
<%@ page import="cn.alcatel.wap.db.dao.mobiledb"%>
<link href="../../styles/dtree.css" rel="stylesheet" type="text/css" />
<script language="JavaScript">
function checkFields(){
if((document.mobile_fm_add.mobilename.value.length==0)){
	alert("手机名称不能为空");
	document.mobile_fm_add.mobilename.focus();
	return false;
}
if((document.mobile_fm_add.uaname.value.length==0)){
	alert("手机UA不能为空");
	document.mobile_fm_add.uaname.focus();
	return false;
}
if((document.mobile_fm_add.mobiledid.value.length==0)){
	alert("手机did不能为空");
	document.mobile_fm_add.mobiledid.focus();
	return false;
}
}
</script>
<table width="100%" border="1" align="center" cellpadding="4" cellspacing="1">
  <tr>
    <td class="dtree"><a href="index.jsp">终端信息管理</a> | 终端信息添加</td>
  </tr>
  <tr><td>
    <form name="mobile_fm_add" action="../../test" method="post" enctype="multipart/form-data" class="dtree" onsubmit="return checkFields()">
<table width="100%" border="0" cellspacing="2" cellpadding="2" class="dtree" >
<tr>
<td align="right" width="20%">手机名称 : </td>
<td width="80%">
  <input type="text" name="mobilename" size="40">&nbsp;&nbsp;&nbsp;<font color="red">(*必填)</font></td>
</tr>
<tr>
<td align="right" width="20%">手机UA : </td>
<td width="80%"><input type="text" name="uaname" size="40">&nbsp;&nbsp;&nbsp;<font color="red">(*必填)</font></td>
</tr>
<tr>
<td align="right" width="20%">手机did : </td>
<td width="80%"><input type="text" name="mobiledid" size="40" onkeyup="this.value=this.value.replace(/\D/g,'')" onafterpaste="this.value=this.value.replace(/\D/g,'')">&nbsp;&nbsp;&nbsp;<font color="red">(*必填)</font></td>
</tr>

<tr>
<td align="right" width="20%">WAP版本 : </td>
<td width="80%">
<%
for(int i=0;i<DBInfo.WAP_INFO.length;i++){
if(i==0){
out.println("<input type='radio' value='"+i+"' checked name='wapinfo'>"+DBInfo.WAP_INFO[i]+"");
}else
out.println("<input type='radio' value='"+i+"' name='wapinfo'>"+DBInfo.WAP_INFO[i]+"");
}
%>
</tr>
<%
cn.alcatel.wap.db.DBMap[]  pageclass=mobiledb.all_mobile_page();
if(null!=pageclass){
%>
<tr>
<td align="right" width="20%">页面类型 : </td>
<td width="80%">
<%
for(int i=0;i<pageclass.length;i++){
if(i==0){
out.println("<input type='radio' value='"+pageclass[i].get("id")+"' checked name='pageclass'>"+pageclass[i].get("na")+"");
}else
out.println("<input type='radio' value='"+pageclass[i].get("id")+"' name='pageclass'>"+pageclass[i].get("na")+"");
}
}
%>
</tr>

<tr>
<td align="right" width="20%">网络信息 : </td>
<td width="80%">
<%
for(int i=0;i<DBInfo.NET_INFO.length;i++){
if(i==0){
out.println("<input type='radio' value='"+i+"' checked name='net'>"+DBInfo.NET_INFO[i]+"");
}else
out.println("<input type='radio' value='"+i+"' name='net'>"+DBInfo.NET_INFO[i]+"");
}
%>
</td>
</tr>
<tr>
<td align="right" width="20%">是否支持java : </td>
<td width="80%">
<input type="radio" value="0" name="game_rel" />不支持
<input type="radio" value="1" checked name="game_rel"/>支持
</td>
</tr>
<tr>
<td align="right" width="20%">铃声格式 : </td>
<td width="80%">
  <%
  for(int i=0;i<DBInfo.RING_TYPEID.length;i++){
  out.print("<input type='checkbox' name='ring_format' value='"+i+"'/>"+DBInfo.RING_TYPEID[i]+"");
    }
  %>
  &nbsp;&nbsp;&nbsp;<font color="red">(*必填)</font>
</td>
</tr>
<tr>
<td align="right" width="20%">视频格式 : </td>
<td width="80%">
<%
  for(int i=0;i<DBInfo.VIDEO_TYPEID.length;i++){
  out.print("<input type='checkbox' name='video_format' value='"+i+"'/>"+DBInfo.VIDEO_TYPEID[i]+"");
    }
  %>
（不选表示不支持视频）
</td>
</tr>
<tr>
<td align="right" width="20%">屏幕尺寸 : </td>
<td width="80%">
<select  name="kindid">
<%
for(int i=0;i<DBInfo.IMAGE_SIZE.length;i++){
if(i==1){
out.println("<option value='"+i+"' name='screen_size' selected>"+DBInfo.IMAGE_SIZE[i]+"</option>");
}else
out.println("<option value='"+i+"' name='screen_size'>"+DBInfo.IMAGE_SIZE[i]+"</option>");
}
%>
 </select>
</td>
</tr>
<tr>
<td align="right" width="20%">图片 :</td>
<td width="80%"><input type="file" name="images" size="40"></td>
</tr>
<tr>
<td width="20%">&nbsp;</td>
<td width="80%"><input type="submit" name="submit" value="submit" ></td>
</tr>
</table>
</form></td>
  </tr>
</table>
