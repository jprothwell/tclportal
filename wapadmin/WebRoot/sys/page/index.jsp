<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import="cn.alcatel.wap.db.DBInfo"%>
<jsp:useBean id="pdb" scope="session" class="cn.alcatel.wap.db.dao.pagedb">
</jsp:useBean>
<link href="../../styles/dtree.css" rel="stylesheet" type="text/css" />
<script LANGUAGE="JAVASCRIPT">
function delobject(pid,filename,pageurl) {
	if (confirm("是否删除文件?")) {
		location="delpage.jsp?pageid=" + pid+"&filename="+filename+"&pageurl="+pageurl;
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
    pagestart = (pageNum-1) * pdb.pagecnt ;
  }
// 获取最大页码
  int count_0 =pdb.get_pagecnt();
  if(pageNum >=count_0){
    if(0==count_0){
       pagestart=0;
    }
    else{
      pagestart= (count_0-1)*pdb.pagecnt;
      }
    pageNum = count_0;
  }
// 取页面数据
    cn.alcatel.wap.db.DBMap[] pageinfo=pdb.get_page_info(pagestart);
%>
 <form method="POST" action="../../pagelistall" name="listallform">
<table width="100%" border="1" align="center" cellpadding="1" cellspacing="1" class="dtree">
<tr>
    <td colspan="10">页面信息管理 | <a href="pageadd.jsp">页面信息添加</a></td>
  </tr>
  <tr>
  <tr>
    <td>页面名称</td>
    <td>文件名称</td>
     <td>语言</td>
    <td>文件类型</td>
    <td>页面说明</td>
    <td>访问路径</td>
    <td>操作</td>
  </tr>
<%
   if(null!=pageinfo){
    for(int count=pageinfo.length;count>0;count--){
%>
   <tr>
    <td><%=pageinfo[count-1].get("na")%></td>
    <td><%=pageinfo[count-1].get("fname")%></td>
    <td><%=pageinfo[count-1].get("lg")%></td>
    <td><%
          int pagekind=Integer.parseInt(pageinfo[count-1].get("pagekind").toString());
          for(int i=0;i<DBInfo.PAGE_KIND.length;i++)
            if(pagekind==i)out.print(DBInfo.PAGE_KIND[i]);
          %></td>
    <td><%=pageinfo[count-1].get("descrip")%></td>
    <td><%=pageinfo[count-1].get("url")%></td>
    <td>
      <a href="editpage.jsp?pageid=<%=pageinfo[count-1].get("id")%>">修改</a>|
      <a href="delpage.jsp?pageid=<%=pageinfo[count-1].get("id")%>&amp;filename=<%=pageinfo[count-1].get("fname")%>&amp;pageurl=<%=pageinfo[count-1].get("url")%>" onclick="return delobject('pageid','filename','pageurl')">删除</a>
      </td>
  </tr>
<%
 }
 }
%>
 <tr><td align="center" colspan="10">
    共<%=pdb.all_page_count()%>页
   <%=pageNum%>/<%=pdb.get_pagecnt()%>页
   <a href="index.jsp?page=0">首页</a>|
   <a href="index.jsp?page=<%=pageNum-1%>">上一页</a>|
   <a href="index.jsp?page=<%=pageNum+1%>">下一页</a>|
   <a href="index.jsp?page=<%=count_0%>">末页</a>
   </td></tr>
</table>
</form>
