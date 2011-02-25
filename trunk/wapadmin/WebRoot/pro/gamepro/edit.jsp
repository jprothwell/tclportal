<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import="cn.alcatel.wap.db.DBInfo" %>
<%@ page import="cn.alcatel.wap.db.dao.gameadmin" %>
<%@ page import ="cn.alcatel.wap.db.DBMap"%>
<%@ page import="cn.alcatel.wap.db.dao.spadmin"%>
<link href="../../styles/dtree.css" rel="stylesheet" type="text/css" />
<script language="JavaScript">
function checkFields( ){
if((document.gameedit.gamename.value.length==0)){
	alert("请输入游戏名称！");
	document.gameedit.gamename.focus();
	return false ;
}
}
</script>
<%
    int gameid=Integer.parseInt(request.getParameter("gameid"));
    gameadmin dao= new gameadmin();
    DBMap[] map =dao.gamelist(gameid);
%>
<table width="100%" border="1" align="center" cellpadding="4" cellspacing="1">
  <tr>
    <td class="dtree"><a href="index.jsp">机型游戏管理 </a> | <a href="gameindex.jsp">游戏管理</a> | 游戏修改</td>
  </tr>
  <tr><td>
    <form name="gameedit" action="../../gameedit" method="post" class="dtree" enctype="multipart/form-data" onsubmit="return checkFields()">
<table width="563" border="0" cellspacing="2" cellpadding="2" class="dtree" >
<input type="hidden" name="gameid" size="30" value="<%=gameid%>">
<input type="hidden" name="imageName" size="30" value="<%=map[0].get("images")%>">
<input type="hidden" name="file1Name" size="30" value="<%=map[0].get("file1")%>">
<input type="hidden" name="file2Name" size="30" value="<%=map[0].get("file2")%>">
<tr>
<td align="right" width="115">游戏名称 : </td>
<td width="430"><input type="text" name="gamename" size="30" value="<%=map[0].get("name")%>"><font color="red">*</font></td>
</tr>
<tr>
<td align="right" width="115">游戏语言 : </td>
<td width="430">
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
<td align="right" width="115">游戏与应用 : </td>
<td width="430">
<%
for(int i=0;i<DBInfo.GAME_TYPEID.length;i++){
if(i==Integer.parseInt(map[0].get("typeid").toString())){
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
if(i==Integer.parseInt(map[0].get("sizeid").toString())){
out.println("<input type='radio' value='"+i+"' checked name='screen'>"+DBInfo.IMAGE_SIZE[i]+"");
}else
out.println("<input type='radio' value='"+i+"' name='screen'>"+DBInfo.IMAGE_SIZE[i]+"");
}
%>
</td>
</tr>
<tr>
<td align="right" width="115">游戏提供商 : </td>
<td width="430">
  <select  name="sppro">
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
<td align="right" width="115">游戏价格</td>
<td width="430"><input type="file" name="price" size="40"  value="<%=map[0].get("price")%>" class="dtree"></td>
</tr>
<tr>
<td align="right" width="115">预览图片</td>
<td width="430"><input type="file" name="images" size="50"></td>
</tr>

<tr>
<td align="right" width="115">jar文件</td>
<td width="430"><input type="file" name="file1" size="50"></td>
</tr>

<tr>
<td align="right" width="115">jad文件</td>
<td width="430"><input type="file" name="file2" size="50"></td>
</tr>

<tr>
<td align="right" width="115">游戏说明</td>
<td width="430"><textarea rows="7" name="gameinfo" cols="55"><%=map[0].get("info")%></textarea></td>
</tr>

<tr>
<td width="115">&nbsp;</td>
<td width="430"><input type="submit" name="submit" value="提交"></td>
</tr>
</table>
</form></td>
  </tr>
</table>
