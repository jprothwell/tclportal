<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import="cn.alcatel.wap.db.DBInfo" %>
<%@ page import="cn.alcatel.wap.db.dao.gameadmin" %>
<link href="../../styles/dtree.css" rel="stylesheet" type="text/css" />
<script language="JavaScript">
function checkFields( ){
if((document.game_fm_add.gamename.value.length==0)){
	alert("请输入游戏名称！");
	document.game_fm_add.gamename.focus();
	return false ;
}
if((document.game_fm_add.file1.value.length==0)){
	alert("请输入jar文件！");
	document.game_fm_add.file1.focus();
	return false ;
}
if((document.game_fm_add.file2.value.length==0)){
	alert("请输入jad文件！");
	document.game_fm_add.file2.focus();
	return false ;
}
}
</script>
<table width="100%" border="1" align="center" cellpadding="4" cellspacing="1">
  <tr>
    <td class="dtree"><a href="index.jsp">机型游戏管理 </a> | <a href="gameindex.jsp">游戏管理</a> | 游戏添加</td>
  </tr>
  <tr><td>
    <form name="game_fm_add" action="../../gameadd" method="post" class="dtree" enctype="multipart/form-data" onsubmit="return checkFields()">
<table width="563" border="0" cellspacing="2" cellpadding="2" class="dtree" >

<tr>
<td align="right" width="115">游戏名称 : </td>
<td width="430"><input type="text" name="gamename" size="30"><font color="red">*</font></td>
</tr>

<tr>
<td align="right" width="115">游戏语言 : </td>
<td width="430">
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
<td align="right" width="115">游戏与应用 : </td>
<td width="430">
<%
for(int i=0;i<DBInfo.GAME_TYPEID.length;i++){
if(i==0){
out.println("<input type='radio' value='"+i+"' checked name='gameapp'>"+DBInfo.GAME_TYPEID[i]+"");
}else
out.println("<input type='radio' value='"+i+"' name='gameapp'>"+DBInfo.GAME_TYPEID[i]+"");
}
%>
</td>
</tr>

<tr>
<td align="right" width="115">屏幕尺寸: </td>
<td>
<%
for(int i=0;i<DBInfo.IMAGE_SIZE.length;i++){
if(i==1){
out.println("<input type='radio' value='"+i+"' checked name='screen'>"+DBInfo.IMAGE_SIZE[i]+"");
}else
out.println("<input type='radio' value='"+i+"' name='screen'>"+DBInfo.IMAGE_SIZE[i]+"");
}
%>
</td>
</tr>

<tr>
<td align="right" width="115">提供商:</td>
<td width="430">
<select  name="sppro">
<%
  cn.alcatel.wap.db.DBMap[] sp=gameadmin.get_sp_info();
  if(null==sp){
    out.print("无提供商");
  }
  else{
      for(int i=0;i<sp.length;i++){
         out.print("<option value='"+Integer.parseInt(sp[i].get("id").toString())+"' name='sppro'>"+sp[i].get("spname").toString()+"</option>");
    }
    }
%>
 </select>
类别 :<select  name="kindid">
<%
for(int i=0;i<DBInfo.GAME_KINDID.length;i++){
if(i==0){
out.println("<option value='"+i+" selected'>"+DBInfo.GAME_KINDID[i]+"</option>");
}else
out.println("<option value='"+i+"'>"+DBInfo.GAME_KINDID[i]+"</option>");
}
%>
 </select>

</td>
</tr>
<tr>
<td align="right" width="115">游戏价格</td>
<td width="430"><input type="file" name="price" size="40" class="dtree"></td>
</tr>
<tr>
<td align="right" width="115">预览图片</td>
<td width="430"><input type="file" name="images" size="40" class="dtree"></td>
</tr>

<tr>
<td align="right" width="115">jar文件</td>
<td width="430"><input type="file" name="file1" size="40" class="dtree"><font color="red">*</font></td>
</tr>

<tr>
<td align="right" width="115">jad文件</td>
<td width="430"><input type="file" name="file2" size="40" class="dtree"><font color="red">*</font></td>
</tr>

<tr>
<td align="right" width="115">游戏说明</td>
<td width="430"><textarea rows="7" name="gameinfo" cols="55"></textarea></td>
</tr>

<tr>
<td width="115">&nbsp;</td>
<td width="430"><input type="submit" name="submit" value="提交"></td>
</tr>
</table>
</form></td>
  </tr>
</table>
