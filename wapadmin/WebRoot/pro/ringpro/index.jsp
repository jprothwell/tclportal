<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import="cn.alcatel.wap.db.DBInfo"%>
<%@ page import="cn.alcatel.wap.db.dao.ringadmin"%>
<script LANGUAGE="JAVASCRIPT">
function delobject(typeid,ringid,ringname) {
	if (confirm("确定删除")){
		location="delring.jsp?typeid=" + typeid+"&ringid=" +ringid+"&fileaddr="+fileaddr;
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
    pagestart = (pageNum-1) * ringadmin.pagecnt;
  }
// 获取最大页数
  int count_0 =ringadmin.get_pagecnt(typeid);
// 判断是否超过最大页数
  if(pageNum >=count_0){
    if(0==count_0){
        pagestart=0;
      }
    else{
        pagestart= (count_0-1)*ringadmin.pagecnt;
    }
        pageNum = count_0;
  }
// 查询数据
cn.alcatel.wap.db.DBMap[] ringinfo=ringadmin.get_page_info(pagestart,typeid);
%>
<table width="100%" border="1" align="center" cellpadding="1" cellspacing="1" class="dtree">
  <tr>
    <td colspan="6"><%=DBInfo.RING_TYPEID[typeid]%>管理 | <a href="add.jsp?typeid=<%=typeid%>">添加铃声</a></td>
  </tr>

  <tr>
    <td>名称</td>
    <td>语言</td>
    <td>类型</td>
    <td>文件路径</td>
    <td>文件说明</td>
    <td>操作</td>
  </tr>
<%
    if(null!=ringinfo){
       for(int count=ringinfo.length;count>0;count--){
%>
  <tr>
     <td><%=ringinfo[count-1].get("na")%></td>
     <td><%=ringinfo[count-1].get("lg")%></td>
     <td><%
           int ringtype=Integer.parseInt(ringinfo[count-1].get("typeid").toString());
           for(int i=0;i<DBInfo.RING_TYPEID.length;i++){
               if(i==ringtype)
               out.print(DBInfo.RING_TYPEID[i]);
             }
     %></td>
     <td><%=ringinfo[count-1].get("fileaddr")%></td>
     <td><%=ringinfo[count-1].get("info")%></td>
  <td>
  <a href='edit.jsp?typeid=<%=typeid%>&amp;ringid=<%=ringinfo[count-1].get("id")%>'>修改</a>
  <a href="delring.jsp?typeid=<%=typeid%>&ringid=<%=ringinfo[count-1].get("id")%>&fileaddr=<%=ringinfo[count-1].get("fileaddr")%>" onclick="return delobject(<%=typeid%>,'ringid','fileaddr')">删除</a>
</tr>
<%
    }
    }
%>
 <tr><td align="center" colspan="6">
   共<%=ringadmin.tempcnt%>首铃声
   <%=pageNum%>/<%=count_0%>页
    <a href="index.jsp?page=1&typeid=<%=typeid%>">首页</a>|
    <a href="index.jsp?page=<%=pageNum-1%>&typeid=<%=typeid%>">上一页</a>|
    <a href="index.jsp?page=<%=pageNum+1%>&typeid=<%=typeid%>">下一页</a>|
    <a href="index.jsp?page=<%=count_0%>&typeid=<%=typeid%>">末页</a>
   </td>
</table>
