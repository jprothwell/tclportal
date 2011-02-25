<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import="cn.alcatel.wap.db.DBInfo"%>
<%@ page import="cn.alcatel.wap.db.dao.gameadmin"%>
<link href="../../styles/dtree.css" rel="stylesheet" type="text/css" />
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
    pagestart = pageNum * gameadmin.pagecnt ;
  }
  int count_0 =gameadmin.get_pagecnt();
// 获取最大页数
// 判断是否超过最大页数
  if(pageNum >=count_0){
    if(0==count_0){
        pagestart=0;
      }
      else{
          pagestart= (count_0-1)*gameadmin.pagecnt;
      }
          pageNum = count_0;
  }
// 查询数据
cn.alcatel.wap.db.DBMap[] gameinfo=gameadmin.get_page_info(pagestart);
%>
<table width="100%" border="1" align="center" cellpadding="1" cellspacing="1" class="dtree">
  <tr>
    <td>机型游戏管理 | <a href="gameindex.jsp">游戏管理</a> | <a href="add.jsp">游戏添加</a></td>
  </tr>
    <%
      if(null!=gameinfo){
  %>
<tr><td>
<table width="100%" border="0" cellspacing="2" cellpadding="2" class="dtree" >
<tr><td align="left" colspan="10">
<%
       int cyc=0;
       for(int count=gameinfo.length;count>0;count--){
         cyc++;
        gameadmin.all_model_count(gameinfo[count-1].get("ua").toString());
%>
   <a href="gindex.jsp?ua=<%=gameinfo[count-1].get("ua")%>"><img src="../../img/folder.gif"/><%=gameinfo[count-1].get("ua")%>(<%=gameadmin.gamecount%>)
   </a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
<%
       if(4==cyc){
          out.print("<br>");
          cyc=0;
         }
     }
      }
%>
</td></tr>
</table>
  </td>
  </tr>
  <tr><td align="center" colspan="10">
    共<%
      if(null==gameinfo){
        out.print("0");
        }
      else{
        out.print(gameinfo.length);
        }
    %>条
   <%=pageNum%>/<%=gameadmin.get_pagecnt()%>页
   <a href="index.jsp?page=0">首页</a>|
   <a href="index.jsp?page=<%=pageNum-1%>">上一页</a>|
   <a href="index.jsp?page=<%=pageNum+1%>">下一页</a>|
   <a href="index.jsp?page=<%=count_0%>">末页</a>
</table>
