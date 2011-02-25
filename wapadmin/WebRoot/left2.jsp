<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="checksession.jsp"%>
<%@ page import="cn.alcatel.wap.db.DBInfo"%>
<%@ page import ="java.util.List"%>
<script type="text/javascript" src="styles/dtree.js"></script>
<link href="styles/dtree.css" rel="stylesheet" type="text/css" />
<table width="100%" border="0" align="center" cellpadding="4" cellspacing="1">
  <tr>
    <td valign="top" bgcolor="#FFFFFF">
	<table width="100%" border="0" cellspacing="0" cellpadding="0">
      <tr><td valign="top">
<div class="dtree">
<p><a href="javascript: d.openAll();">open all</a> | <a href="javascript: d.closeAll();">close all</a></p>
<script type="text/javascript">
d = new dTree('d');
d.add(1,-1,'资源管理','','','right');
d.add(2,1,'图片管理','','','right');
d.add(3,1,'铃声管理','','','right');
d.add(4,1,'视频管理','','','right');
d.add(5,1,'游戏管理','pro/gamepro/index.jsp','','right');
<!--d.add(6,1,'业务管理','pro/sppro/index.jsp','','right');-->
d.add(7,1,'资讯管理','pro/newspro/index.jsp','','right');
<%
    int menu_num=8;
    int menu_n=0;
    int image_num=DBInfo.IMAGE_SIZE.length;
    int imagekind_num=DBInfo.IMAGE_KINDID.length;
    int ring_num=DBInfo.RING_TYPEID.length;
    int video_num=DBInfo.VIDEO_TYPEID.length;
    for(int i=0;i<image_num;i++){
    out.println("d.add("+menu_num+",2,'"+DBInfo.IMAGE_SIZE[i]+"','','','');");
    menu_num=menu_num+1;
    menu_n=menu_num-1;
    for(int e=0;e<imagekind_num;e++){
    out.println("d.add("+menu_num+","+menu_n+",'"+DBInfo.IMAGE_KINDID[e]+"','pro/imagepro/index.jsp?sizeid="+i+"&amp;kindid="+e+"','','right');");
    menu_num=menu_num+1;
    }
    }
%>
<%
    for(int j=0;j<ring_num;j++,menu_num++){
%>
     d.add(<%=menu_num%>,3,'<%=DBInfo.RING_TYPEID[j]%>','pro/ringpro/index.jsp?typeid=<%=j%>','','right');
<%
   }
%>
<%
   for(int k=0;k<video_num;k++,menu_num++){
%>
     d.add(<%=menu_num%>,4,'<%=DBInfo.VIDEO_TYPEID[k]%>','pro/videopro/index.jsp?typeid=<%=k%>','','right');
<%
  }
%>
document.write(d);
</script>
</div>
</td></tr>
</table>
</td></tr>
</table>
