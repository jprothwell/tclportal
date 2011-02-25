<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import="cn.alcatel.wap.db.DBInfo"%>
<%@ page import="cn.alcatel.wap.db.dao.picres"%>
<%@ page import="servlets.myfile"%>
<%@ page import="cn.alcatel.wap.db.dao.Configuration"%>
<script LANGUAGE="JAVASCRIPT">
function delobject(pid,sizeid,picname,pathview,pathpic) {
	if (confirm("确定删除")) {
		location="delpic.jsp?indexid=" + pid+"&sizeid=" +sizeid+"&picname="+picname+"&pathview="+pathview+"&pathpic="+pathpic;
		return true;
	}
        else{
               return false;
          }
}
</script>
<link href="../../styles/dtree.css" rel="stylesheet" type="text/css" />
<%
String filePath=Configuration.picpath;
int sizeid=0;
int kindid=0;
sizeid =Integer.parseInt(request.getParameter("sizeid"));
kindid =Integer.parseInt(request.getParameter("kindid"));
filePath=filePath+DBInfo.FILE_SIZE[sizeid]+Configuration.pathurl+DBInfo.IMAGE_KINDID[kindid]+Configuration.pathurl;
%>
<!--处理每页的数据-->
<%
// pageNum存储页数
  int pageNum = 1;
  try {
// 接收url重写参数
       pageNum = Integer.parseInt(request.getParameter("page"));
  }
  catch (Exception ex) {
    pageNum = 1;
  }
  int pagestart = 0;
// 判断是否小于最小页数
  if (pageNum <= 1) {
    pagestart = 0;
    pageNum = 1;
  }
  else {
    pagestart = (pageNum-1) * picres.pagecnt ;
  }
// 获取最大页数
  int count_0 =picres.get_pagecnt(sizeid,kindid);
// 判断是否超过最大页数
  if(pageNum >=count_0){
    if(0==count_0){
       pagestart=0;
       pageNum=count_0;
      }
    else{
         pagestart= (count_0-1)*picres.pagecnt;
         pageNum = count_0;
    }
  }
// 查询数据
  cn.alcatel.wap.db.DBMap[] picresinfo=picres.get_page_info(pagestart,sizeid,kindid);
%>
<table width="100%" border="1" align="center" cellpadding="1" cellspacing="1" class="dtree">
  <tr>
    <td colspan="3"><%=DBInfo.IMAGE_SIZE[sizeid]%>-<%=DBInfo.IMAGE_KINDID[kindid]%>图片管理 | <a href="add.jsp?sizeid=<%=sizeid%>&amp;kindid=<%=kindid%>">添加图片</a></td>
  </tr>
  <tr>
    <td>预览图</td>
    <td>属性</td>
    <td>操作</td>
  </tr>
<%
    if(null!=picresinfo){
    for(int i=0;i<picresinfo.length;i++){
%>
  <tr>
<td width="15%">
 <img src="<%=Configuration.serveraddress%><%=picresinfo[i].get("pathview")%>"/>
</td>
<td width="70%">
图片名称：<%=picresinfo[i].get("na")%><br>
图片大小：<%
String picName="";
       picName=picresinfo[i].get("pathpic").toString();
       picName=picName.substring(picName.lastIndexOf("/")+1);
String filePath1=filePath+picName;
java.io.File myFile = new java.io.File(filePath1);
out.println(myfile.getFileSize(myFile)/1024+"K");
%><br>
图片规格：<%=DBInfo.IMAGE_SIZE[sizeid]%><br>
录入时间：<%=picresinfo[i].get("sdate")%><br>
</td>
<td width="15%">
   <a href="edit.jsp?editid=<%=picresinfo[i].get("id")%>&amp;sizeid=<%=sizeid%>&amp;kindid=<%=kindid%>">编辑</a>
   <a href="delpic.jsp?indexid=<%=picresinfo[i].get("id")%>&amp;sizeid=<%=sizeid%>&amp;kindid=<%=kindid%>&amp;pathpic=<%=picresinfo[i].get("pathpic")%>&amp;pathview=<%=picresinfo[i].get("pathview")%>" onclick="return delobject('indexid','<%=sizeid%>','picname','pathview','pathpic')">删除</a>
  </td></tr>
<%
    }
    }
%>
 <tr><td align="center" colspan="3">
   共<%=picres.tempcnt%>张图片
   <%=pageNum%>/<%=count_0%>行
    <a href="index.jsp?page=1&amp;sizeid=<%=sizeid%>&amp;kindid=<%=kindid%>">首页</a>|
    <a href="index.jsp?page=<%=pageNum-1%>&amp;sizeid=<%=sizeid%>&amp;kindid=<%=kindid%>">上一页</a>|
    <a href="index.jsp?page=<%=pageNum+1%>&amp;sizeid=<%=sizeid%>&amp;kindid=<%=kindid%>">下一页</a>|
    <a href="index.jsp?page=<%=count_0%>&amp;sizeid=<%=sizeid%>&amp;kindid=<%=kindid%>">末页</a>
</td>
</table>
