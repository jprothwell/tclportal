<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import="cn.alcatel.wap.db.DBInfo"%>
<%@ page import="cn.alcatel.wap.db.dao.newadmin"%>
<link href="../../styles/dtree.css" rel="stylesheet" type="text/css" />
<script LANGUAGE="JAVASCRIPT">
function delobject(pid,picdir) {
	if (confirm("确定删除")) {
		location="del.jsp?indexid=" + pid+"&picdir="+picdir;
		return true;
	}
        else{
                return false;
          }

}
</script>
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
    pagestart = pageNum * newadmin.pagecnt;
  }
// 获取最大页数
  int count_0 =newadmin.get_pagecnt();
// 判断是否超过最大页数
  if(pageNum >=count_0){
    if(0==count_0){
        pagestart= 0;
    }
    else{
         pagestart= (count_0-1)*newadmin.pagecnt;
      }
    pageNum = count_0;
  }
// 查询数据
cn.alcatel.wap.db.DBMap[] newinfo=newadmin.get_page_info(pagestart);
%>
<table width="100%" border="1" align="center" cellpadding="1" cellspacing="1" class="dtree">
  <tr>
    <td colspan="6">资讯管理 | <a href="add.jsp">添加资讯</a></td>
  </tr>
  <tr>
    <td>ID</td>
    <td>标题</td>
    <td>预览图片路径</td>
    <td>语言</td>
    <td>录入时间</td>
    <td>操作</td>
  </tr>

<%
    if(null!=newinfo){
    for(int i=0;i<newinfo.length;i++) {
%>
<tr>
  <td><%=newinfo[i].get("id")%></td>
  <td><%=newinfo[i].get("na")%></td>
  <td><%=newinfo[i].get("picdir")%></td>
  <td><%=newinfo[i].get("lg")%></td>
  <td><%=newinfo[i].get("sdate")%></td>
  <td >
    <a href='edit.jsp?newsid=<%=newinfo[i].get("id")%>'>编辑</a>
    |
    <a href="del.jsp?newsid=<%=newinfo[i].get("id")%>&amp;picdir=<%=newinfo[i].get("picdir")%>" onclick="return delobject('indexid','picdir')">删除</a>
<%
    }
}
%>
 <tr><td align="center" colspan="7">
   共<%=newadmin.all_new_count()%>条信息
   <%=pageNum%>/<%=count_0%>页
    <a href="index.jsp?page=1">首页</a>|
    <a href="index.jsp?page=<%=pageNum-1%>">上一页</a>|
    <a href="index.jsp?page=<%=pageNum+1%>">下一页</a>|
    <a href="index.jsp?page=<%=count_0%>">末页</a>
   </td>
</table>
