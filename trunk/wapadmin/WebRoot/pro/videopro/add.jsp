<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import ="java.util.List"%>
<%@ page import ="java.sql.Date"%>
<%@ page import="cn.alcatel.wap.db.DBInfo"%>
<%@ page import="cn.alcatel.wap.db.dao.videoadmin"%>
<%@ page import="cn.alcatel.wap.db.dao.spadmin"%>
<%@ page import ="cn.alcatel.wap.db.DBMap"%>
<%
int typeid=Integer.parseInt(request.getParameter("typeid"));
%>
<link href="../../styles/dtree.css" rel="stylesheet" type="text/css" />
<script language="JavaScript">
function checkFields(){
if((document.video_fm_add.videoname.value.length==0)){
	alert("请输入名称！");
	document.video_fm_add.videoname.focus();
	return false ;
}
if((document.video_fm_add.images.value.length==0)){
	alert("请输入预览图片！");
	document.video_fm_add.images.focus();
	return false ;
}
if((document.video_fm_add.file1.value.length==0)){
	alert("请输入视频文件！");
	document.video_fm_add.file1.focus();
	return false ;
}
}
</script>
<table width="100%" border="1" align="center" cellpadding="4" cellspacing="1">
  <tr>
    <td class="dtree"><a href="index.jsp?typeid=<%=typeid%>">视频管理</a> | 视频添加</td>
  </tr>
  <tr><td>
    <form name="video_fm_add" action="../../videoadd"  enctype="multipart/form-data" method="post" class="dtree" onsubmit="return checkFields()">
<table width="100%" border="0" cellspacing="2" cellpadding="2" class="dtree" >

<tr>
<td align="right" width="20%">视频名称 : </td>
<td width="80%"><input type="text" name="videoname" size="30"><font color="red">*</font></td>
</tr>

<tr>
<td align="right" width="20%">语言版本 : </td>
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
<td align="right" width="20%">视频类型 : </td>
<td width="80%">
<%
for(int i=0;i<DBInfo.VIDEO_TYPEID.length;i++){
if(i==typeid){
out.println("<input type='radio' value='"+i+"' checked name='typeid'>"+DBInfo.VIDEO_TYPEID[i]+"");
}else
out.println("<input type='radio' value='"+i+"' name='typeid'>"+DBInfo.VIDEO_TYPEID[i]+"");
}
%>
</td>
</tr>

<tr>
<td align="right" width="20%">视频尺寸 : </td>
<td width="80%"><select  name="videosize">
<%
for(int i=0;i<DBInfo.IMAGE_SIZE.length;i++){
if(i==1){
out.println("<option value='"+i+"' selected>"+DBInfo.IMAGE_SIZE[i]+"</option>");
}else
out.println("<option value='"+i+"'>"+DBInfo.IMAGE_SIZE[i]+"</option>");
}
%>
 </select>
 </td>
</tr>

<tr>
<td align="right" width="20%">适用机型 : </td>
<td width="80%"><select  name="model">
<%
  cn.alcatel.wap.db.DBMap[] model=videoadmin.get_model_info();
  if(null==model){
     out.print("无适用机型");
    }
  else{
  for(int i=0;i<model.length;i++){
      out.print("<option value='"+model[i].get("ua")+"' name='model'>"+model[i].get("ua").toString()+"</option>");
    }
  }
%>
 </select>
 </td>
</tr>

<tr>
<td align="right" width="20%">视频提供商 : </td>
<td width="80%">
<select  name="videosppro">
<%
spadmin dao= new spadmin();
DBMap[] map = dao.listSp();
for(int i=0;i<map.length;i++){
     out.println("<option value='"+map[i].get("id")+"'>"+map[i].get("sp_name")+"</option>");
}
%>
 </select>
</td>
</tr>

<tr>
<td align="right" width="20%">视频类别 : </td>
<td width="80%">
 <select  name="typeid">
<%
for(int i=0;i<DBInfo.VIDEO_KINDID.length;i++){
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
<td align="right" width="20%">预览图片 :</td>
<td width="80%"><input type="file" name="images" size="30"><font color="red">*</font></td>
</tr>

<tr>
<td align="right" width="20%">视频文件 :</td>
<td width="80%"><input type="file" name="file1" size="30"><font color="red">*</font></td>
</tr>

<tr>
<td align="right" width="20%">视频说明 :</td>
<td width="80%"><textarea rows="4" name="videoinfo" cols="40"></textarea></td>
</tr>

<tr>
<td width="20%">&nbsp;</td>
<td width="80%"><input type="submit" name="submit" value="提交"></td>
</tr>

</table>
</form></td>
  </tr>
</table>
