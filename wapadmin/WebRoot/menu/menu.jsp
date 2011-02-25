<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import="cn.alcatel.wap.db.DBInfo"%>
<%@ page import="cn.alcatel.wap.db.DBMap"%>
<%@ page import="cn.alcatel.wap.db.dao.menuDao"%>
<%
String groupid=request.getParameter("groupid");
String lg=request.getParameter("lg");
String perPage=request.getParameter("perPage");
String urlName="imagemenu.jsp";
int group_id=Integer.parseInt(groupid);
switch(group_id){
  case 0:urlName="imagemenu.jsp?groupid="+groupid; break;
  case 1:urlName="ringmenu.jsp?groupid="+groupid; break;
  case 2:urlName="videomenu.jsp?groupid="+groupid; break;
  case 3:urlName="../pro/gamepro/index.jsp?groupid="+groupid+"&lg="+lg; break;
  case 4:urlName="newsmenu.jsp?groupid="+groupid+"&lg="+lg; break;
  case 5:urlName="spinfomenu.jsp?groupid="+groupid; break;
  }
 // out.print("urlName="+urlName);
int total_num=0;
int per_page=1;
int total_page=0;
 if(perPage == null || perPage.equals(""))per_page=1;
 else per_page=Integer.parseInt(perPage);
int page_num=50;//DBInfo.PAGE_PER_NUM;
int start_num=(per_page-1)*page_num;
int last_num=per_page-1;
int next_num=per_page+1;
menuDao dao = new menuDao();
total_num=dao.menuTotalnum(lg,group_id);
if((total_num % page_num)==0) total_page=total_num/page_num;
else total_page=total_num/page_num+1;
DBMap[] map = dao.menuList(lg,group_id,start_num,page_num);
%>
<link href="../styles/dtree.css" rel="stylesheet" type="text/css" />
<table width="100%" border="1" align="center" cellpadding="1" cellspacing="1" class="dtree">
  <tr>
    <td colspan="6"><%=lg%> <%=DBInfo.MENU_GROUP[group_id]%>栏目管理 | <a href="menuadd.jsp?lg=<%=lg%>&amp;groupid=<%=groupid%>">添加栏目</a></td>
  </tr>
  <tr><td colspan="6" align="center">共<%=total_num%>纪录 <%=per_page%>/<%=total_page%>页 <a href="menu.jsp?lg=<%=lg%>&amp;groupid=<%=groupid%>&amp;perPage=1">首页</a>|
    <%
    if(per_page>1)out.println("<a href='menu.jsp?lg="+lg+"&amp;groupid="+groupid+"&amp;perPage="+last_num+"'>上页</a>");
     else out.println("上页");
     %>
    |
        <%
    if(per_page<total_page)out.println("<a href='menu.jsp?lg="+lg+"&amp;groupid="+groupid+"&amp;perPage="+next_num+"'>下页</a>");
     else out.println("下页");
     %>
    |<a href="menu.jsp?lg=<%=lg%>&amp;groupid=<%=groupid%>&amp;perPage=<%=total_page%>">末页</a></td></tr>
  <tr><td>栏目ID</td><td>栏目名称</td><td>栏目语言</td><td>栏目类别</td><td>栏目说明</td><td>操作</td></tr>
  </tr>
 <form name="frm" action="menu_del.jsp" method="post" class="dtree">
 <input type="hidden" name="groupid" value="<%=groupid%>"/>
 <input type="hidden" name="lg" value="<%=lg%>"/>
   <%
  if(map != null){
    for(int i = 0; i < map.length; i++){
      try{
  if(Integer.parseInt(map[i].get("rel").toString())==1 && group_id==3)urlName="gamemenu.jsp?ua=Alcatel-Tcl&amp;groupid="+groupid;
  %>
    <tr>
<td><%=map[i].get("id")%><input type='checkbox' name='idlist' value='<%=map[i].get("id")%>'></td>
<td><%=map[i].get("name")%></td>
<td><%=map[i].get("lg")%></td>
<td><%=DBInfo.MENU_GROUP[group_id]%></td>
<td><%=map[i].get("info")%></td>
<td align="center">
  <a href="menuedit.jsp?groupid=<%=groupid%>&amp;lg=<%=lg%>&amp;id=<%=map[i].get("id")%>">察看编辑</a>|
  <a href="<%=urlName%>&amp;lg=<%=lg%>&amp;id=<%=map[i].get("id")%>&amp;contentid=<%=map[i].get("contentid")%>">察看资源</a></td>
</tr>
<%}catch(Exception e){
        e.printStackTrace();
      }
    }
  }
%>
<tr><td colspan="6" class="dtree" > <input type="button" value="全选" onclick="checkAll('idlist')"  class="dtree"/>&nbsp;&nbsp;<input type="button" value="取消" onclick="clearAll('idlist')" class="dtree"/>&nbsp;&nbsp;
  <input type="button" value="删除"  class="dtree" onclick="doDel()"/></td></tr>
</form>
<tr><td colspan="6" align="center">共<%=total_num%>纪录 <%=per_page%>/<%=total_page%>页 <a href="menu.jsp?lg=<%=lg%>&amp;groupid=<%=groupid%>&amp;perPage=1">首页</a>|
    <%
    if(per_page>1)out.println("<a href='menu.jsp?lg="+lg+"&amp;groupid="+groupid+"&amp;perPage="+last_num+"'>上页</a>");
     else out.println("上页");
     %>
    |
        <%
    if(per_page<total_page)out.println("<a href='menu.jsp?lg="+lg+"&amp;groupid="+groupid+"&amp;perPage="+next_num+"'>下页</a>");
     else out.println("下页");
     %>
    |<a href="menu.jsp?lg=<%=lg%>&amp;groupid=<%=groupid%>&amp;perPage=<%=total_page%>">末页</a></td></tr>
</table>
<script type="text/javascript">
function checkAll(name){
var el = document.getElementsByTagName('input');
var len = el.length;
for(var i=0; i<len; i++)
{
if((el[i].type=="checkbox") && (el[i].name==name))
{
el[i].checked = true;
}
}
}
function clearAll(name) {
var el = document.getElementsByTagName('input');
var len = el.length;
for(var i=0; i<len; i++)     {
if((el[i].type=="checkbox") && (el[i].name==name)) {
el[i].checked = false;
}
}
}
 function doDel(){
  var a = document.getElementsByName("idlist");
  var n = a.length;
  var k = 0;
  for (var i=0; i<n; i++){
    if(a[i].checked)k = 1;
    }
if(k==0){
        alert("Please select delete id.");
	return false ;
    }
    else
    {
     var message="确定要删除吗?";
    if(confirm(message) == false){
      return false;
    }else{
      frm.submit();
    }
      }
  }
</script>

