<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="checksession.jsp"%>
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
d.add(1,-1,'系统管理','','','right');
d.add(2,1,'终端管理','sys/mobile/index.jsp','','right');
d.add(3,1,'Cp-Sp管理','sys/spcp/index.jsp','','right');
d.add(4,1,'地域管理','http://wap.my-onetouch.com/location','','blank');
d.add(5,1,'页面管理','sys/page/index.jsp','','right');
d.add(6,1,'用户管理','sys/user/index.jsp','','right');
d.add(7,1,'游戏咨询','sys/spcp/admin.jsp','','right');
document.write(d);
	</script>
</div>
		  </td>
      </tr>
    </table></td>
  </tr>
</table>
