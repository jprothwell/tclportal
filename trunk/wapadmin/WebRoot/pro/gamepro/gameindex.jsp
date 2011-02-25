<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import="cn.alcatel.wap.db.DBInfo"%>
<%@ page import="cn.alcatel.wap.db.dao.gameadmin"%>
<script LANGUAGE="JAVASCRIPT">
function delobject(lg,gameid,gamepic,jar,jad) {
	if (confirm("确定删除")){
		location="delgame.jsp?lg="+lg+"&gameid=" + gameid+"&gamepic=" +gamepic+"&jar="+jar+"&jad="+jad;
		return true;
	}
        else{
               return false;
          }
}
</script>
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
    pagestart = (pageNum-1) * gameadmin.pagecnt ;
  }
  int count_0 =gameadmin.get_singlepagecnt();
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
cn.alcatel.wap.db.DBMap[] singlegameinfo=gameadmin.get_singlepage_info(pagestart);
%>
<table width="100%" border="1" align="center" cellpadding="1" cellspacing="1" class="dtree">
  <tr><td  colspan="7">
<a href="index.jsp">机型游戏管理 </a> | 游戏管理| <a href="add.jsp">游戏添加</a>
      </td> </tr>

  <tr>
    <td width="8%">ID</td>
    <td width="13%">名称</td>
    <td width="20%">游戏jar包</td>
    <td width="20%">游戏jad包</td>
    <td width="10%">语言</td>
    <td width="10%">优先级</td>
    <td width="14%">管理</td>
  </tr>
<%
   if(null!=singlegameinfo){
     for(int i=0;i<singlegameinfo.length;i++){
%>
  <tr>
    <td width="10%"><%=singlegameinfo[i].get("id")%></td>
    <td width="10%"><%=singlegameinfo[i].get("name")%></td>
    <td width="10%"><%=singlegameinfo[i].get("jar")%></td>
    <td width="10%"><%=singlegameinfo[i].get("jad")%></td>
    <td width="10%"><%=singlegameinfo[i].get("lg")%></td>
    <td width="15%"><%=singlegameinfo[i].get("sort")%></td>
    <td width="15%">
      <a href="edit.jsp?gameid=<%=singlegameinfo[i].get("id")%>">修改</a>
      |
      <a href="delgame.jsp?lg=<%=singlegameinfo[i].get("lg")%>&amp;gameid=<%=singlegameinfo[i].get("id")%>&amp;gamepic=<%=singlegameinfo[i].get("images")%>&amp;jar=<%=singlegameinfo[i].get("jar")%>&amp;jad=<%=singlegameinfo[i].get("jad")%>" onclick="return delobject('lg','gameid','gamepic','jar','jad')"> 删除</a></td>
  </tr>
<%
  }
   }
%>
 <tr><td align="center" colspan="10">
    共<%
        if(null==singlegameinfo){
            out.print("0");
          }
        else{
            out.print(singlegameinfo.length);
          }
    %>条
   <%=pageNum%>/<%=gameadmin.get_singlepagecnt()%>页
   <a href="gameindex.jsp?page=0">首页</a>|
   <a href="gameindex.jsp?page=<%=pageNum-1%>">上一页</a>|
   <a href="gameindex.jsp?page=<%=pageNum+1%>">下一页</a>|
   <a href="gameindex.jsp?page=<%=count_0%>">末页</a>
</table>
