<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import="cn.alcatel.wap.db.DBInfo"%>
<%@ page import="cn.alcatel.wap.db.dao.videoadmin"%>
<%@ page import="java.io.*"%>
<script LANGUAGE="JAVASCRIPT">
function delobject(typeid,videoid,fileaddr,picdir) {
	if (confirm("确定删除")){
		location="delvideo.jsp?typeid=" + typeid+"&videoid=" +videoid+"&fileaddr="+fileaddr+"&picdir"+picdir;
		return true;
	}
        else{
               return false;
          }
}
</script>
<link href="../../styles/dtree.css" rel="stylesheet" type="text/css" />
<%
     int typeid=Integer.parseInt(request.getParameter("typeid"));
%>
<!--处理每页的数据-->
<%
// //pageNum存储页数
int pageNum = 1;
  try {
// //接收url重写参数
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
    pagestart = (pageNum-1) * videoadmin.pagecnt ;
  }
  // 获取最大页数
  int count_0 =videoadmin.get_pagecnt(typeid);
// 判断是否超过最大页数
  if(pageNum >=count_0){
    if(0==count_0){
        pagestart=0;
    }
    else{
         pagestart= (count_0-1)*videoadmin.pagecnt;
      }
       pageNum = count_0;
  }
// 查询数据
cn.alcatel.wap.db.DBMap[] videoinfo=videoadmin.get_page_info(pagestart,typeid);
%>
<table width="100%" border="1" align="center" cellpadding="1" cellspacing="1" class="dtree">
  <tr><td colspan="6">
    <%=DBInfo.VIDEO_TYPEID[typeid]%>管理 | <a href="add.jsp?typeid=<%=typeid%>">添加视频</a></td>
  </tr>
      </td> </tr>

  <tr>
    <td>名称</td>
    <td>屏幕大小</td>
    <td>图片路径</td>
    <td>视频文件路径</td>
    <td>语言</td>
    <td>管理</td>
  </tr>
<%
   if(null!=videoinfo){
     for(int i=0;i<videoinfo.length;i++){
%>
  <tr>
    <td><%=videoinfo[i].get("na")%></td>
    <td><%=DBInfo.IMAGE_SIZE[Integer.parseInt(videoinfo[i].get("sizeid").toString())]%></td>
    <td><%=videoinfo[i].get("picdir")%></td>
    <td><%=videoinfo[i].get("fileaddr")%></td>
    <td><%=videoinfo[i].get("lg")%></td>
    <td>
     <a href="edit.jsp?typeid=<%=typeid%>&amp;videoid=<%=videoinfo[i].get("id")%>">编辑</a>
      |
     <a href="delvideo.jsp?typeid=<%=typeid%>&amp;videoid=<%=videoinfo[i].get("id")%>&fileaddr=<%=videoinfo[i].get("fileaddr")%>&picdir=<%=videoinfo[i].get("picdir")%>" onclick="return delobject(<%=typeid%>,'videoid','fileaddr','picdir')">删除</a>
      </td>
     </tr>
<%
  }
   }
%>
 <tr><td align="center" colspan="10">
    共<%=videoadmin.tempcnt%>条
   <%=pageNum%>/<%=videoadmin.get_pagecnt(typeid)%>页
   <a href="index.jsp?page=0&typeid=<%=typeid%>">首页</a>|
   <a href="index.jsp?page=<%=pageNum-1%>&typeid=<%=typeid%>">上一页</a>|
   <a href="index.jsp?page=<%=pageNum+1%>&typeid=<%=typeid%>">下一页</a>|
   <a href="index.jsp?page=<%=count_0%>&typeid=<%=typeid%>">末页</a>
</table>

