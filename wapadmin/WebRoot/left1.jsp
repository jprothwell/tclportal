<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="checksession.jsp"%>
<%@ page import="cn.alcatel.wap.db.DBInfo"%>
<%@ page import="cn.alcatel.wap.db.DBMap"%>
<%@ page import="cn.alcatel.wap.db.dao.mobileDao"%>
<%@ page import ="java.util.List"%>
<%@ page import ="java.sql.Date"%>
<%
mobileDao dao = new mobileDao();
%>
<script type="text/javascript" src="styles/dtree.js"></script>
<script type="text/javascript" src="styles/timeMenu.js"></script>
<link href="styles/dtree.css" rel="stylesheet" type="text/css" />
<table width="100%" border="0" align="center" cellpadding="4" cellspacing="1">
  <tr>
    <td valign="top" bgcolor="#FFFFFF">
	<table width="100%" border="0" cellspacing="0" cellpadding="0">
      <tr>
        <td valign="top">
<div class="dtree">
	<p><a href="javascript: d.openAll();">open all</a> | <a href="javascript: d.closeAll();">close all</a></p>
	<script type="text/javascript">
		d = new dTree('d');
d.add(1,-1,'PORTAL管理','','','');
d.add(2,1,'栏目管理','','','');
d.add(3,1,'PORTAL发布','','','');
<%
int menu_num=3;
int lg_num=DBInfo.LG_INFO.length;
int m_num=DBInfo.MENU_GROUP.length;
int image_num=DBInfo.IMAGE_SIZE.length;
int imagekind_num=DBInfo.IMAGE_KINDID.length;
int f_num=0;
for(int i=0;i<lg_num;i++){
menu_num=menu_num+1;
f_num=menu_num;
out.println("d.add("+menu_num+",2,'"+DBInfo.LG_INFO[i]+"','','','');");
for(int j=0;j<m_num;j++){
menu_num=menu_num+1;
out.println("d.add("+menu_num+","+f_num+",'"+DBInfo.MENU_GROUP[j]+"','menu/menu.jsp?lg="+DBInfo.LG_INFO[i]+"&groupid="+j+"','','right');");
}
}
 for(int e=0;e<image_num;e++){
    menu_num=menu_num+1;
    f_num=menu_num;
    out.println("d.add("+menu_num+",3,'"+DBInfo.IMAGE_SIZE[e]+"','','','');");
    DBMap[] map=dao.mobileList(e);
    if(map != null){
    for(int i = 0; i < map.length; i++){
    menu_num=menu_num+1;
    out.println("d.add("+menu_num+","+f_num+",'"+map[i].get("name")+"("+map[i].get("did")+")','menu/index.jsp?id="+map[i].get("id")+"&groupid="+e+"','','right');");
     }
   }
 }
%>
document.write(d);
	</script>
</div>
		  </td>
      </tr>
    </table></td>
  </tr>
</table>
