<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import ="java.util.List"%>
<%@ page import ="java.sql.Date"%>
<%@ page import ="cn.alcatel.wap.db.DBMap"%>
<%@ page import="cn.alcatel.wap.db.DBInfo"%>
<%@ page import="cn.alcatel.wap.db.dao.*"%>
<%
int qianrel=0;
String qrel=request.getParameter("qrel");
if(qrel!=null)qianrel=Integer.parseInt(qrel);

String id=request.getParameter("id");
String perPage=request.getParameter("perPage");
int id1=Integer.parseInt(id);
mobileDao dao = new mobileDao();
DBMap[] map = dao.menuInfo(id1);
uamenuDao dao1=new uamenuDao();
 String d = map[0].get("ring_format").toString();
 String p="";
  String[] k=d.split(",");
  for(int i=0;i<k.length;i++){
 int t=Integer.parseInt(k[i]);
 if(i>0)p=p+","+DBInfo.RING_TYPEID[t];
 else p=p+DBInfo.RING_TYPEID[t];
}
///////////
 String vid = map[0].get("video_format").toString();
 String pvid="";
 if("888".equals(vid))pvid="不支持";
 else{
  String[] kvid=vid.split(",");
  for(int r=0;r<kvid.length;r++){
 int t=Integer.parseInt(k[r]);
 if(r>0)pvid=pvid+","+DBInfo.VIDEO_TYPEID[t];
 else pvid=pvid+DBInfo.VIDEO_TYPEID[t];
}
 }
    ///////////////
    String urlName="imagemenu.jsp";
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
<table width="100%" border="1" align="center" cellpadding="1" cellspacing="1">
  <tr class="dtree">
    <td colspan="2"><%=map[0].get("name")%>(<%=map[0].get("did")%>)</a> | <a href="index1.jsp?id=<%=id%>">栏目排序</a></td>
  </tr>
  <tr class="dtree"><td width="20%">手机名称：</td><td><%=map[0].get("name")%></td></tr>
  <tr class="dtree"><td width="20%">UA(did):</td><td><%=map[0].get("ua")%>(<%=map[0].get("did")%>)</td></tr>
  <tr class="dtree"><td width="20%">屏幕尺寸:</td><td><%=DBInfo.IMAGE_SIZE[Integer.parseInt(map[0].get("image_size").toString())]%></td></tr>
  <tr class="dtree"><td width="20%">铃声格式:</td><td><%=p%></td></tr>
  <tr class="dtree"><td width="20%">视频格式:</td><td><%=pvid%></td></tr>
  <tr class="dtree"><td width="20%">是否支持java:</td><td>
    <%
    if(map[0].get("game_rel").toString().equals("1"))out.println("Yes");
    else out.println("No");
    %></td></tr>
<tr>
    <td colspan="2">
<DIV id=macrolong_tabView>
<%
int lg_num=DBInfo.LG_INFO.length;
String lgStr="";
for(int i=0;i<lg_num;i++){
  if(i>0)lgStr=lgStr+",";
  lgStr=lgStr+"'"+DBInfo.LG_INFO[i]+"'";
%>
<DIV class=macrolong_aTab>
 <table width="100%" border="1" align="center" cellpadding="1" cellspacing="1" class="dtree">
  <tr><td>ID</td><td><%=DBInfo.LG_INFO[i]%>栏目名称</td><td>栏目语言</td><td>栏目类别</td><td>栏目说明</td><td>栏目</td><td>操作</td></tr>
  </tr>
 <form name="frm" action="uamenu_del.jsp" method="post" class="dtree">
 <input type="hidden" name="id" value="<%=id%>"/>
 <%
DBMap[] map1= dao1.uamenuList(DBInfo.LG_INFO[i],map[0].get("ua").toString());
  if(map1 != null){
    for(int j = 0; j < map1.length; j++){
      try{
  int group_id=Integer.parseInt(map1[j].get("groupid").toString());
switch(group_id){
  case 0:urlName="imagemenu.jsp?groupid="+group_id; break;
  case 1:urlName="ringmenu.jsp?groupid="+group_id; break;
  case 2:urlName="videomenu.jsp?groupid="+group_id; break;
  case 3:urlName="../pro/gamepro/gindex.jsp?ua="+map[0].get("ua")+"&lg="+DBInfo.LG_INFO[i];break;
  case 4:urlName="newsmenu.jsp?groupid="+group_id+"&lg="+DBInfo.LG_INFO[i]; break;
  case 5:urlName="spinfomenu.jsp?groupid="+group_id; break;
  }
if(Integer.parseInt(map1[j].get("rel").toString())==1 && group_id==3)urlName="gamemenu.jsp?ua="+map[0].get("ua")+"&amp;groupid="+group_id+"&amp;lg="+map1[j].get("lg");
//out.print("<br>rel="+map1[j].get("rel"));
//out.print("<br>group_id="+group_id);
%>
<tr>
<td><%=map1[j].get("id")%></td>
    <td><%=map1[j].get("name")%></td>
    <td><%=map1[j].get("lg")%></td>
    <td><%=DBInfo.MENU_GROUP[Integer.parseInt(map1[j].get("groupid").toString())]%></td>
    <td><%=map1[j].get("info")%></td>
    <td align="center">
    <%
    if(Integer.parseInt(map1[j].get("new_r").toString())==0)
    out.print("<a href=\"javascript:addobject('"+map1[j].get("id")+"','"+id+"','1');\">最新</a> | <a href=\"javascript:addobject('"+map1[j].get("id")+"','"+id+"','2');\">热点</a>");
    if(Integer.parseInt(map1[j].get("new_r").toString())==1)
    out.print("<a href=\"javascript:addobject('"+map1[j].get("id")+"','"+id+"','0');\">取消</a> | <a href=\"javascript:addobject('"+map1[j].get("id")+"','"+id+"','2');\">热点</a>");
    if(Integer.parseInt(map1[j].get("new_r").toString())==2)
    out.print("<a href=\"javascript:addobject('"+map1[j].get("id")+"','"+id+"','0');\">取消</a> | <a href=\"javascript:addobject('"+map1[j].get("id")+"','"+id+"','1');\">最新</a>");
    %>
</td>
    <td align="center">
    <a href="javascript:delobject('<%=map1[j].get("id")%>','<%=id%>');">删除</a>|
    <a href="<%=urlName%>&amp;id=<%=map1[j].get("menuid")%>&amp;contentid=<%=map1[j].get("contentid")%>">资源</a></td>
    </tr>
  </tr>
  <%}catch(Exception e){
        e.printStackTrace();
      }
    }
  }
%>
<tr><td colspan="7">
  <input type="button" class="dtree" value="增加栏目" onclick="doAdd('<%=map[0].get("ua")%>','<%=DBInfo.LG_INFO[i]%>','<%=qrel%>')"/>
  <input type="button" class="dtree" value="栏目排序" onclick="doOrder('<%=map[0].get("ua")%>','<%=DBInfo.LG_INFO[i]%>')"/>
  </td></tr>
</form>
</table>
</DIV>
<%}%>
<DIV class=macrolong_aTab>
</DIV>
</DIV>
<!--下面是引用代码-->
<SCRIPT type="text/javascript">
initTabs(Array(<%=lgStr%>),<%=qianrel%>,'98%','100%');
/*
参数说明:
Array为标签标题
默认显示标签的序号0,1,2,...
宽
高
*/
</SCRIPT>
    </td>
  </tr>
<tr>
</table>
<script type="text/javascript">
  <!-------start------>
  function doAdd(ua,lg,qrel) {
	if (confirm("确定要增加栏目？")) {
window.open('1.jsp?ua='+ua+'&lg='+lg+'&qrel='+qrel,'newwindow','height=300,width=600,top=80,left=0,toolbar=no,menubar=no,scrollbars=yes,resizable=no,location=no,status=no');
		return true;
	}
}
  function doOrder(ua,lg) {
if (confirm("确定栏目需要重新排序么？")) {
window.open('index1.jsp?ua='+ua+'&lg='+lg,'newwindow','height=300,width=250,top=200,left=600,toolbar=no,menubar=no,scrollbars=yes,resizable=no,location=no,status=no');
		return true;
	}
}
<!-------end------->
function delobject(id1,id) {
	if (confirm("确定删除")) {
		location="uamenu_del.jsp?id1="+id1+"&id="+id;
		return true;
	}
}
<!-------end------->
function addobject(id1,id,new_r) {
	if (confirm("确定修改")) {
		location="uamenu_add.jsp?id1="+id1+"&id="+id+"&new_r="+new_r;
		return true;
	}
}
</script>
