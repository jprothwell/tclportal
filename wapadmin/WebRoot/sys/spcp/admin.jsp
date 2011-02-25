<%@ page contentType="text/html; charset=utf-8" %>
<%//@ include file="../../checksession.jsp"%>
<%@ page import="cn.alcatel.wap.db.DBInfo"%>
<%@ page import="cn.alcatel.wap.db.dao.questionDao"%>
<link href="../../styles/dtree.css" rel="stylesheet" type="text/css" />
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
    pagestart = (pageNum-1) * questionDao.pagecnt;
  }
 // System.out.println(pageNum);
// 获取最大页码
  int count_0 =questionDao.get_pagecnt();
  if(pageNum >=count_0){
    if(0==count_0){
        pagestart=0;
      }
    else{
       pagestart= (count_0-1)*questionDao.pagecnt;
      }
       pageNum = count_0;
  }
// 取页面数据
    cn.alcatel.wap.db.DBMap[] spinfo=questionDao.get_page_info(pagestart);
%>
<table width="100%" border="1" align="center" cellpadding="1" cellspacing="1" class="dtree">
<tr>
    <td colspan="10">游戏问题咨询</td>
  </tr>
  <tr>
  <tr>
    <td>日期</td>
    <td>问题</td>
    <td>联系方式</td>
    <td>did</td>
    <td>手机号码</td>
    <td>国家</td>
    <td>操作</td>
  </tr>
<%
    if(null!=spinfo){
    for(int count=spinfo.length;count>0;count--){
    String resU="没有处理";
    if("1".equals(spinfo[count-1].get("rel").toString())) resU="已经处理";
%>
   <tr>
    <td><%=spinfo[count-1].get("sdate")%></td>
    <td><%=spinfo[count-1].get("y_content")%></td>
    <td><%=spinfo[count-1].get("y_contact")%></td>
    <td><%=spinfo[count-1].get("did")%></td>
    <td><%=spinfo[count-1].get("phonenum")%></td>
    <td><%=spinfo[count-1].get("country")%></td>
     <td>
<a href="editq.jsp?id=<%=spinfo[count-1].get("id")%>"><%=resU%></a>
</td>
  </tr>
<%
 }
    }
%>
 <tr><td align="center" colspan="10">
    共<%=questionDao.all_page_count()%>条
   <%=pageNum%>/<%=questionDao.get_pagecnt()%>页
   <a href="admin.jsp?page=0">首页</a>|
   <a href="admin.jsp?page=<%=pageNum-1%>">上一页</a>|
   <a href="admin.jsp?page=<%=pageNum+1%>">下一页</a>|
   <a href="admin.jsp?page=<%=count_0%>">末页</a>
   </td></tr>
</table>
