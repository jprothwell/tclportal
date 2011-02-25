<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import ="java.util.List"%>
<%@ page import ="java.sql.Date"%>
<%@ page import ="cn.alcatel.wap.db.DBMap"%>
<%@ page import="cn.alcatel.wap.db.DBInfo"%>
<%@ page import="cn.alcatel.wap.db.dao.*"%>
<%@ page import="cn.alcatel.wap.db.dao.Configuration"%>
<%
int qianrel=0;
int sizeid1=1;
int kindid1=0;
String qrel=request.getParameter("qrel");
if(qrel!=null)qianrel=Integer.parseInt(qrel);

String sizeid=request.getParameter("sizeid");
if(sizeid!=null)sizeid1=Integer.parseInt(sizeid);

String kindid=request.getParameter("kindid");
if(kindid!=null)kindid1=Integer.parseInt(kindid);

String id=request.getParameter("id");
String groupid=request.getParameter("groupid");
String contentid=request.getParameter("contentid");
String lg=request.getParameter("lg");
resourceDao dao = new resourceDao();
String perPage=request.getParameter("perPage");
int total_num=0;
int per_page=1;
int total_page=0;
 if(perPage==null || perPage.equals(""))per_page=1;
 else per_page=Integer.parseInt(perPage);
int page_num=200;//DBInfo.PAGE_PER_NUM;
int start_num=(per_page-1)*page_num;
int last_num=per_page-1;
int next_num=per_page+1;
total_num=dao.imageTotalnum(sizeid1,kindid1);
if((total_num % page_num)==0) total_page=total_num/page_num;
else total_page=total_num/page_num+1;
DBMap[] map1 = dao.imageList(start_num,page_num,sizeid1,kindid1);
%>
<link href="../styles/dtree.css" rel="stylesheet" type="text/css" />
<style type="text/css">
<!--
BODY {
	MARGIN: 10px
}
.ad {
	MARGIN-TOP: 30px; PADDING-TOP: 10px
}
.macrolong_tabPane {
	BORDER-BOTTOM: #919b9c 1px solid; HEIGHT: 21px
}
.macrolong_aTab {
	BORDER-RIGHT: #919b9c 1px solid; PADDING-RIGHT: 5px; PADDING-LEFT: 5px; PADDING-BOTTOM: 5px; BORDER-LEFT: #919b9c 1px solid; PADDING-TOP: 5px; BORDER-BOTTOM: #919b9c 1px solid; FONT-FAMILY: Trebuchet MS, Lucida Sans Unicode, Arial, sans-serif
}
.macrolong_tabPane DIV {
	BACKGROUND-POSITION: left bottom; PADDING-LEFT: 3px; FLOAT: left; MARGIN-LEFT: 0px; VERTICAL-ALIGN: middle; CURSOR: pointer; BOTTOM: -1px; MARGIN-RIGHT: 0px; BACKGROUND-REPEAT: no-repeat; POSITION: relative; HEIGHT: 100%
}
.macrolong_tabPane .tabActive {
	Z-INDEX: 10; BACKGROUND-IMAGE: url(images/tab_left_active.gif); MARGIN-LEFT: 0px; MARGIN-RIGHT: 0px
}
.macrolong_tabPane .tabInactive {
	Z-INDEX: 1; BACKGROUND-IMAGE: url(images/tab_left_inactive.gif); MARGIN-LEFT: 0px; MARGIN-RIGHT: 0px
}
.macrolong_tabPane .inactiveTabOver {
	BACKGROUND-IMAGE: url(images/tab_left_over.gif); MARGIN-LEFT: 0px; MARGIN-RIGHT: 0px
}
.macrolong_tabPane SPAN {
	PADDING-RIGHT: 3px; PADDING-LEFT: 3px; FONT-SIZE: 11px; FLOAT: left; VERTICAL-ALIGN: top; LINE-HEIGHT: 21px; FONT-FAMILY: arial
}
.macrolong_tabPane .tabActive SPAN {
	PADDING-BOTTOM: 1px; LINE-HEIGHT: 20px
}
.macrolong_tabPane IMG {
	FLOAT: left
}
-->
</style>
<script language="javascript" src="js/dhtmlTab.js"></script>
<DIV id=macrolong_tabView>
<DIV class=macrolong_aTab>
<table width="100%" border="1" align="center" cellpadding="1" cellspacing="1" class="dtree">
  <tr><td colspan="2">
  <input type="button" class="dtree" value="返回" onclick="history.back();"/>
  <input type="button" class="dtree" value="栏目排序" onclick="doOrder('<%=contentid%>','<%=groupid%>')"/>
  </td></tr>
  <tr><td>预览图</td><td>属性</td><!--<td>排序</td>--></tr>
<tr>
  <%
  if(contentid.equals("null")||contentid.length()==0)out.println("<tr><td colspan='2'>目前此栏目没有资源！</td></tr>");
  else {
    DBMap[] map = dao.reimageList(contentid);
    for(int i=0;i<map.length;i++){
  %>
<td width="20%"><img src="<%=Configuration.serveraddress%><%=map[i].get("file1")%>"/></td>
<td width="60%">
图片名称：<%=map[i].get("name")%><br>
图片规格：<%=DBInfo.IMAGE_SIZE[Integer.parseInt(map[i].get("sizeid").toString())]%><br>
适合国家：<%=map[i].get("lg")%><br>
录入时间：<%=map[i].get("sdate")%>
</td>
<!--<td width="10%">
  <%if(i!=0){%>
<input type="button" value="↑" onClick="move('<%=contentid%>','<%=map[i].get("id")%>','<%=groupid%>','0')">
  <%}if(i!=(map.length-1)){%>
<input type="button" value="↓" onClick="move('<%=contentid%>','<%=map[i].get("id")%>','<%=groupid%>','1')">
<%}%>
</td>-->
  </tr>
  <%}}%>
  <tr><td colspan="3">
  <input type="button" class="dtree" value="返回" onclick="history.back();"/>
  <input type="button" class="dtree" value="栏目排序" onclick="doOrder('<%=contentid%>','<%=groupid%>')"/>
  </td></tr>
</table>
</DIV>
<DIV class=macrolong_aTab>
<table width="100%" border="1" align="center" cellpadding="1" cellspacing="1" class="dtree">
<tr><td colspan="3" align="center">
<form action="imagemenu.jsp">
 <input type="hidden" name="qrel" value="1" />
 <input type="hidden" name="groupid" value="<%=groupid%>" />
 <input type="hidden" name="lg" value="<%=lg%>" />
 <input type="hidden" name="id" value="<%=id%>" />
 <input type="hidden" name="contentid" value="<%=contentid%>" />
 选择 图片尺寸:<select  class="dtree" name="sizeid">
<%
for(int i=0;i<DBInfo.IMAGE_SIZE.length;i++){
   if(i==sizeid1){
      out.println("<option value='"+i+"' selected>"+DBInfo.IMAGE_SIZE[i]+"</option>");
   }
   else{
      out.println("<option value='"+i+"'>"+DBInfo.IMAGE_SIZE[i]+"</option>");
   }
}
%>
 </select>
 图片类别:<select class="dtree"  name="kindid">
<%
for(int i=0;i<DBInfo.IMAGE_KINDID.length;i++){
   if(i==kindid1){
      out.println("<option value='"+i+"' selected>"+DBInfo.IMAGE_KINDID[i]+"</option>");
   }
   else{
      out.println("<option value='"+i+"'>"+DBInfo.IMAGE_KINDID[i]+"</option>");
   }
}
%>
 </select>
<input type="submit" class="dtree" value="搜索" />
</form>
</tr> <tr>
<tr><td colspan="3" align="center">共<%=total_num%>纪录 <%=per_page%>/<%=total_page%>页 <a href="imagemenu.jsp?id=<%=id%>&amp;contentid=<%=contentid%>&amp;perPage=1&amp;qrel=1&amp;kindid=<%=kindid%>&amp;sizeid=<%=sizeid%>">首页</a>|
    <%
    if(per_page>1)out.println("<a href='imagemenu.jsp?id="+id+"&amp;contentid="+contentid+"&amp;perPage="+last_num+"&amp;qrel=1&amp;kindid="+kindid+"&sizeid="+sizeid+"'>上页</a>");
     else out.println("上页");
     %>
    |
        <%
    if(per_page<total_page)out.println("<a href='imagemenu.jsp?qrel=1&amp;kindid="+kindid+"&amp;sizeid="+sizeid+"&amp;id="+id+"&amp;contentid="+contentid+"&amp;perPage="+next_num+"'>下页</a>");
     else out.println("下页");
     %>
    |<a href="imagemenu.jsp?qrel=1&amp;id=<%=id%>&amp;contentid=<%=contentid%>&amp;kindid=<%=kindid%>&amp;sizeid=<%=sizeid%>&amp;perPage=<%=total_page%>">末页</a></td></tr>
    <tr>
  <td>id</td><td>预览图</td><td>属性</td>
  </tr>
  <tr>
  <form name="frm" action="resourceadd.jsp" method="post" class="dtree">
  <input type="hidden" name="id" value="<%=id%>"/>
  <input type="hidden" name="groupid" value="<%=groupid%>"/>
   <%
  if(map1 != null){
    for(int i = 0; i < map1.length; i++){
      try{
  %>
<td>
  <%
  out.println(map1[i].get("id"));
  boolean t=false;
  if(contentid.equals("null")||contentid.length()==0)t=false;
  else {
    String[] e=contentid.split(",");
   for(int j=0;j<e.length;j++){
  if(Integer.parseInt(e[j])==Integer.parseInt(map1[i].get("id").toString()))t=true;
   }
  }
   if(t)  out.println("<input type='checkbox' name='idlist' checked value='"+map1[i].get("id")+"'>");
  else out.println("<input type='checkbox' name='idlist' value='"+map1[i].get("id")+"'>");
 %></td>
<td width="15%"><img src="<%=Configuration.serveraddress%><%=map1[i].get("file1")%>"/></td>
<td width="70%">
图片名称：<%=map1[i].get("name")%><br>
图片规格：<%=DBInfo.IMAGE_SIZE[Integer.parseInt(map1[i].get("sizeid").toString())]%><br>
适合国家：<%=map1[i].get("lg")%><br>
录入时间：<%=map1[i].get("sdate")%>
</td></tr>
<%}catch(Exception e){
        e.printStackTrace();
      }
    }
  }
%>
<tr><td colspan="3" class="dtree" >
  <input type="button" class="dtree" value="返回" onclick="history.back();"/>
  <input type="button" value="全选" onclick="checkAll('idlist')"  class="dtree"/>&nbsp;&nbsp;<input type="button" value="取消" onclick="clearAll('idlist')" class="dtree"/>&nbsp;&nbsp;
  <input class="dtree" type="button" value="增加" onclick="doAdd()"/></td></tr>
</form>
<tr><td colspan="3" align="center">共<%=total_num%>纪录 <%=per_page%>/<%=total_page%>页 <a href="imagemenu.jsp?id=<%=id%>&amp;contentid=<%=contentid%>&amp;perPage=1">首页</a>|
     <%
    if(per_page>1)out.println("<a href='imagemenu.jsp?id="+id+"&amp;contentid="+contentid+"&amp;perPage="+last_num+"&amp;qrel=1&amp;kindid="+kindid+"&sizeid="+sizeid+"'>上页</a>");
     else out.println("上页");
     %>
    |
        <%
    if(per_page<total_page)out.println("<a href='imagemenu.jsp?qrel=1&amp;kindid="+kindid+"&amp;sizeid="+sizeid+"&amp;id="+id+"&amp;contentid="+contentid+"&amp;perPage="+next_num+"'>下页</a>");
     else out.println("下页");
     %>
    |<a href="imagemenu.jsp?qrel=1&amp;id=<%=id%>&amp;contentid=<%=contentid%>&amp;kindid=<%=kindid%>&amp;sizeid=<%=sizeid%>&amp;perPage=<%=total_page%>">末页</a></td></tr>
</table>
</DIV>
</DIV>
<!--下面是引用代码-->
<SCRIPT type="text/javascript">
initTabs(Array('列表','增加'),<%=qianrel%>,'98%','100%');
/*
参数说明:
Array为标签标题
默认显示标签的序号0,1,2,...
宽
高
*/
</SCRIPT>
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
 function doAdd(){
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
      frm.submit();
      }
  }
   function doOrder(contentid,groupid) {
    window.open('order.jsp?contentid='+contentid+'&groupid='+groupid,'newwindow','height=300,width=250,top=200,left=600,toolbar=no,menubar=no,scrollbars=yes,resizable=no,location=no,status=no');
		return true;
}
function move(contentid,groupid,id,rel) {
window.open('resourceorder.jsp?contentid='+contentid+'&groupid='+groupid+'&id='+id+'&rel='+rel,'newwindow','height=300,width=250,top=200,left=600,toolbar=no,menubar=no,scrollbars=yes,resizable=no,location=no,status=no');
return true
}
</script>
</script>
