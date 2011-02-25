<%@ page contentType="text/html; charset=utf-8" %>
<%//@ include file="../../checksession.jsp"%>
<%@ page import="cn.alcatel.wap.db.DBInfo"%>
<%@ page import="cn.alcatel.wap.db.dao.spadmin"%>
<link href="../../styles/dtree.css" rel="stylesheet" type="text/css" />
<script LANGUAGE="JAVASCRIPT">
function delobject(pid) {
	if (confirm("确定删除")) {
		location="del.jsp?indexid=" + pid;
		return true;
	}
        else{
                return false;
          }

}
</script>
<%
// pageNum当前页
  int pageNum = 1;
  try {
// 获取传输的页码
       pageNum = Integer.parseInt(request.getParameter("page"));
  }
  catch (Exception ex) {
    pageNum = 1;
  }
  int pagestart = 0;
//  计算取的数据的开始值
  if (pageNum <= 1) {
    pagestart = 0;
    pageNum = 1;
  }
  else {
    pagestart = (pageNum-1) * spadmin.pagecnt ;
  }
 // System.out.println(pageNum);
// 获取最大页码
  int count_0 =spadmin.get_pagecnt();
  if(pageNum >=count_0){
    if(0==count_0){
        pagestart=0;
      }
    else{
       pagestart= (count_0-1)*spadmin.pagecnt;
      }
       pageNum = count_0;
  }
// 取页面数据
    cn.alcatel.wap.db.DBMap[] spinfo=spadmin.get_page_info(pagestart);
%>
<form method="POST" action="../../pagelistall" name="listallform">
<table width="100%" border="1" align="center" cellpadding="1" cellspacing="1" class="dtree">
<tr>
    <td colspan="10">SP-CP信息管理 | <a href="spadd.jsp">SP-CP信息添加</a></td>
  </tr>
  <tr>
  <tr>
    <td>SP名称</td>
    <td>联系人</td>
    <td>电话</td>
    <td>电子邮件</td>
    <td>客户电话</td>
    <td>SP信息</td>
    <td>操作</td>
  </tr>
<%
    if(null!=spinfo){
    for(int count=spinfo.length;count>0;count--){
%>
   <tr>
    <td><%=spinfo[count-1].get("spname")%></td>
    <td><%=spinfo[count-1].get("username")%></td>
    <td><%=spinfo[count-1].get("userphone")%></td>
    <td><%=spinfo[count-1].get("useremail")%></td>
    <td><%=spinfo[count-1].get("clientphone")%></td>
    <td><%=spinfo[count-1].get("spinfo")%></td>
    <td>
      <a href="edit.jsp?spid=<%=spinfo[count-1].get("id")%>&spname=<%=spinfo[count-1].get("spname")%>&username=<%=spinfo[count-1].get("username")%>&userphone=<%=spinfo[count-1].get("userphone")%>&useremail=<%=spinfo[count-1].get("useremail")%>&clientphone=<%=spinfo[count-1].get("clientphone")%>&spinfo=<%=spinfo[count-1].get("spinfo")%>">修改</a>
        | <a href="del.jsp?spid=<%=spinfo[count-1].get("id")%>" onclick="return delobject('indexid')">删除</a>
      </td>
  </tr>
<%
 }
    }
%>
 <tr><td align="center" colspan="10">
    共<%=spadmin.all_page_count()%>条
   <%=pageNum%>/<%=spadmin.get_pagecnt()%>页
   <a href="index.jsp?page=0">首页</a>|
   <a href="index.jsp?page=<%=pageNum-1%>">上一页</a>|
   <a href="index.jsp?page=<%=pageNum+1%>">下一页</a>|
   <a href="index.jsp?page=<%=count_0%>">末页</a>
   </td></tr>
</table>
</form>
