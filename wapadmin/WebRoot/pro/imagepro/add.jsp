<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import ="java.util.List"%>
<%@ page import ="java.sql.Date"%>
<%@ page import="cn.alcatel.wap.db.DBInfo"%>
<%@ page import="cn.alcatel.wap.db.dao.spadmin"%>
<%@ page import ="cn.alcatel.wap.db.DBMap"%>
<%
  int sizeid=Integer.parseInt(request.getParameter("sizeid"));
  int kindid=Integer.parseInt(request.getParameter("kindid"));
%>
<link href="../../styles/dtree.css" rel="stylesheet" type="text/css" />
<script language="JavaScript">
function checkFields(){
if((document.pic_fm_add.picname.value.length==0)){
	alert("请输入图片名称！");
	document.pic_fm_add.picname.focus();
	return false ;
}
if((document.pic_fm_add.view.value.length==0)){
	alert("请添加小图片！");
	document.pic_fm_add.view.focus();
	return false ;
}
if((document.pic_fm_add.pic.value.length==0)){
	alert("请添加大图片！");
	document.pic_fm_add.pic.focus();
	return false ;
}
}
</script>
<table width="100%" border="1" align="center" cellpadding="4" cellspacing="1">
  <tr>
    <td class="dtree"><a href="index.jsp?sizeid=<%=sizeid%>&amp;kindid=<%=kindid%>"><%=DBInfo.IMAGE_SIZE[sizeid]%>-<%=DBInfo.IMAGE_KINDID[kindid]%>图片管理</a> | 图片添加</td>
  </tr>
  <tr><td>
    <form name="pic_fm_add" action="../../picadd" method="post"  enctype="multipart/form-data" class="dtree" onsubmit="return checkFields()">
<table width="100%" border="0" cellspacing="2" cellpadding="2" class="dtree" >
<tr>
<td align="right" width="20%">图片名称 <font color="red">*</font> </td>
<td width="80%"><input type="text" name="picname" size="30"></td>
</tr>
<tr>
<td align="right" width="20%">语言 : </td>
<td width="80%">
<%
   for(int i=0;i<DBInfo.LG_INFO.length;i++){
      if(i==0){
         out.println("<input type='radio' value='"+DBInfo.LG_INFO[i]+"' checked name='lg'>"+DBInfo.LG_INFO[i]+"");
       }
     else{
         out.println("<input type='radio' value='"+DBInfo.LG_INFO[i]+"' name='lg'>"+DBInfo.LG_INFO[i]+"");
     }
   }
%>
</tr>
<tr>
<td align="right" width="20%">屏幕尺寸: </td>
<td width="80%">
<%
for(int i=0;i<DBInfo.IMAGE_SIZE.length;i++){
    if(i==sizeid){
       out.println("<input type='radio' value='"+i+"' checked name='screensize'>"+DBInfo.IMAGE_SIZE[i]+"");
    }
    else{
       out.println("<input type='radio' value='"+i+"' name='screensize'>"+DBInfo.IMAGE_SIZE[i]+"");
   }
}
%>
</td>
</tr>
<tr>
<td align="right" width="20%">图片提供商 : </td>
<td width="80%">
<select  name="spname">
<%
spadmin dao= new spadmin();
DBMap[] map = dao.listSp();
for(int i=0;i<map.length;i++){
     out.println("<option value='"+map[i].get("id")+"'>"+map[i].get("sp_name")+"</option>");
}
%>
</select></td>
</tr>
<tr>
<td align="right" width="20%">图片类别: </td>
<td width="80%"><select  name="kindid">
<%
for(int i=0;i<DBInfo.IMAGE_KINDID.length;i++){
   if(i==kindid){
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
<td align="right" width="20%">小图片（预览图）<font color="red">*</font></td>
<td width="80%"><input type="file" name="view" size="40"></td>
</tr>
<tr>
<td align="right" width="20%">大图片<font color="red">*</font></td>
<td width="80%"><input type="file" name="pic" size="40"></td>
</tr>
<tr>
<td align="right" width="20%">图片说明</td>
<td width="80%"><textarea rows="4" name="picdesc" cols="55">user to All language!</textarea></td>
</tr>
<tr>
<td width="20%">&nbsp;</td>
<td width="80%"><input type="submit" name="submit" value="提交"></td>
</tr>
</table>
</form></td>
  </tr>
</table>
