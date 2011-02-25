<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import="cn.alcatel.wap.db.DBInfo"%>
<%@ page import="cn.alcatel.wap.db.DBMap"%>
<%@ page import="cn.alcatel.wap.db.dao.mobileDao"%>
<%@ page import="cn.alcatel.wap.db.dao.menuDao"%>
<%@ page import ="java.util.List"%>
<%@ page import ="java.sql.Date"%>
<%
String lg=request.getParameter("lg");
String ua=request.getParameter("ua");
String qrel=request.getParameter("qrel");
String groupid=request.getParameter("groupid");
int group_id=0;
if(groupid!=null)group_id=Integer.parseInt(groupid);
menuDao dao = new menuDao();
DBMap[] map = dao.menuList(lg,group_id);
%>
<script type="text/javascript" src="../styles/dtree.js"></script>
<link href="../styles/dtree.css" rel="stylesheet" type="text/css" />
<table width="100%" border="0" cellspacing="0" cellpadding="0">
      <tr>
        <td valign="top" width="20%">
<div class="dtree">
	<script type="text/javascript">
		d = new dTree('d');
d.add(1,-1,'<%=lg%>','','','');
<%
int menu_num=1;
int m_num=DBInfo.MENU_GROUP.length;
for(int i=0;i<m_num;i++){
menu_num=menu_num+1;
%>
d.add(<%=menu_num%>,1,'<%=DBInfo.MENU_GROUP[i]%>','1.jsp?lg=<%=lg%>&ua=<%=ua%>&groupid=<%=i%>','','')
<%}
%>
document.write(d);
	</script>
</div>
		  </td>
                  <td valign="top" width="80%">
<table width="100%" border="1" align="center" cellpadding="1" cellspacing="1" class="dtree">
<tr class="dtree"><td>栏目ID</td><td>栏目名称</td><td>栏目语言</td><td>栏目类别</td><td>栏目说明</td><td>操作</td></tr>
  </tr>
     <%
  if(map != null){
    for(int i = 0; i < map.length; i++){
      try{
  %>
  <tr>
<td><%=map[i].get("id")%></td>
<td><%=map[i].get("name")%></td>
<td><%=map[i].get("lg")%></td>
<td>0</td>
<td><%=map[i].get("info")%></td>
<td align="center">
<a href="add_menu.jsp?lg=<%=lg%>&amp;ua=<%=ua%>&amp;qrel=<%=qrel%>&amp;menuid=<%=map[i].get("id")%>"/>增加</a></td>
</tr>
<%}catch(Exception e){
        e.printStackTrace();
      }
    }
  }
%>
</table>
                  </td>
      </tr>
    </table>
<!--<script>opener.location.reload();window.close();</script>-->
