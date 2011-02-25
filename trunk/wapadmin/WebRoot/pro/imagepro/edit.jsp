<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import ="java.util.List"%>
<%@ page import ="java.sql.Date"%>
<%@ page import="cn.alcatel.wap.db.DBInfo"%>
<%@ page import="cn.alcatel.wap.db.dao.spadmin"%>
<%@ page import="cn.alcatel.wap.db.dao.picres"%>
<%@ page import ="cn.alcatel.wap.db.DBMap"%>
<%
int editid=Integer.parseInt(request.getParameter("editid"));
int sizeid=Integer.parseInt(request.getParameter("sizeid"));
int kindid=Integer.parseInt(request.getParameter("kindid"));
 picres dao1= new picres();
 DBMap[] map =dao1.listimages(editid);
%>
<link href="../../styles/dtree.css" rel="stylesheet" type="text/css" />
<script language="JavaScript">
function checkFields(){
if((document.pic_fm_add.picname.value.length==0)){
	alert("请输入图片名称！");
	document.pic_fm_add.picname.focus();
	return false ;
}
}
</script>
<table width="100%" border="1" align="center" cellpadding="4" cellspacing="1">
  <tr>
    <td class="dtree"><a href="index.jsp?sizeid=<%=sizeid%>&amp;kindid=<%=kindid%>"><%=DBInfo.IMAGE_SIZE[sizeid]%>-<%=DBInfo.IMAGE_KINDID[kindid]%>图片管理</a> | 图片修改</td>
  </tr>
  <tr><td>
    <form name="pic_fm_add" action="../../editpic" method="post"  enctype="multipart/form-data" class="dtree" onsubmit="return checkFields()">
<table width="100%" border="0" cellspacing="2" cellpadding="2" class="dtree" >
<input type="hidden" name="editid" size="30" value="<%=editid%>">
<input type="hidden" name="sizeid" size="30" value="<%=sizeid%>">
<input type="hidden" name="picName" size="30" value="<%=map[0].get("file2")%>">
<input type="hidden" name="viewName" size="30" value="<%=map[0].get("file1")%>">
<tr>
<td align="right" width="20%">图片名称 : <font color="red">*</font></td>
<td width="80%"><input type="text" name="picname" size="30" value="<%=map[0].get("name")%>"></td>
</tr>
<tr>
<td align="right" width="20%">语言 <%=map[0].get("lg")%>: </td>
<td width="80%">
<%
   for(int i=0;i<DBInfo.LG_INFO.length;i++){
      if(DBInfo.LG_INFO[i].equals(map[0].get("lg").toString())){
         out.println("<input type='radio' value='"+DBInfo.LG_INFO[i]+"' checked name='lg'>"+DBInfo.LG_INFO[i]+"");
       }
     else{
         out.println("<input type='radio' value='"+DBInfo.LG_INFO[i]+"' name='lg'>"+DBInfo.LG_INFO[i]+"");
     }
   }
%>
</tr>
<!--<tr>
<td align="right" width="20%">屏幕尺寸: </td>
<td width="80%">
<%
for(int i=0;i<DBInfo.IMAGE_SIZE.length;i++){
    if(i==Integer.parseInt(map[0].get("sizeid").toString())){
       out.println("<input type='radio' value='"+i+"' checked name='screensize'>"+DBInfo.IMAGE_SIZE[i]+"");
    }
    else{
       out.println("<input type='radio' value='"+i+"' name='screensize'>"+DBInfo.IMAGE_SIZE[i]+"");
   }
}
%>
</td>
</tr>-->
<tr>
<td align="right" width="20%">图片提供商 : </td>
<td width="80%">
<select  name="spname">
  <%
spadmin dao= new spadmin();
DBMap[] map1 = dao.listSp();
for(int i=0;i<map1.length;i++){
  if(map[0].get("spid").toString().equals(map1[i].get("id").toString()))
  out.println("<option value='"+map1[i].get("id")+"' selected>"+map1[i].get("sp_name")+"</option>");
else out.println("<option value='"+map1[i].get("id")+"'>"+map1[i].get("sp_name")+"</option>");
}
%>
</select></td>
</tr>
<tr>
<td align="right" width="20%">图片类别: </td>
<td width="80%"><select  name="kindid">
<%
for(int i=0;i<DBInfo.IMAGE_KINDID.length;i++){
   if(i==Integer.parseInt(map[0].get("kindid").toString())){
      out.println("<option value='"+i+"' selected>"+DBInfo.IMAGE_KINDID[i]+"</option>");
   }
   else{
      out.println("<option value='"+i+"'>"+DBInfo.IMAGE_KINDID[i]+"</option>");
   }
}
%>
 </select></td>
</tr>
<tr>
<td align="right" width="20%">小图片（预览图）</td>
<td width="80%"><input type="file" name="view" size="30"></td>
</tr>
<tr>
<td align="right" width="20%">大图片</td>
<td width="80%"><input type="file" name="pic" size="30"></td>
</tr>
<tr>
<td align="right" width="20%">图片说明</td>
<td width="80%"><textarea rows="4" name="picdesc" cols="55"><%=map[0].get("info")%></textarea></td>
</tr>
<tr>
<td width="20%">&nbsp;</td>
<td width="80%"><input type="submit" name="submit" value="提交"></td>
</tr>
</table>
</form></td>
  </tr>
</table>
