<%@ page language="java" import="java.util.*" pageEncoding="UTF-8" autoFlush="true"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/fmt" prefix="fmt"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<script type="text/javascript" src="<%=request.getContextPath()%>/js/My97DatePicker/WdatePicker.js"></script>
<script src="<%=request.getContextPath()%>/js/jquery.js" type="text/javascript"></script>
<script src="<%=request.getContextPath()%>/js/validate.js" type="text/javascript"></script>
<style type="text/css">
body {
	margin-left: 3px;
	margin-top: 0px;
	margin-right: 3px;
	margin-bottom: 0px;
}
.STYLE1 {
	color: #e1e2e3;
	font-size: 12px;
}
.STYLE6 {color: #000000; font-size: 12; }
.STYLE10 {color: #000000; font-size: 12px; }
.STYLE19 {
	color: #344b50;
	font-size: 12px;
}
.STYLE21 {
	font-size: 12px;
	color: #3b6375;
}
.STYLE22 {
	font-size: 12px;
	color: #295568;
}
a:link,a:visited,a:hover   {font-size:12px;color:#0066FF}
</style>
<title>TCL通讯游戏发布平台</title>

</head>

<body>
<table width="100%" border="0" align="center" cellpadding="0" cellspacing="0">
  <tr>
    <td height="30"><table width="100%" border="0" cellspacing="0" cellpadding="0">
      <tr>
        <td height="24" bgcolor="#353c44"><table width="100%" border="0" cellspacing="0" cellpadding="0">
          <tr>
            <td><table width="100%" border="0" cellspacing="0" cellpadding="0">
              <tr>
                <td width="6%" height="19" valign="bottom"><div align="center"><img src="images/tb.gif" width="14" height="14" /></div></td>
                <td width="94%" valign="bottom"><span class="STYLE1">业务统计--访问统计</span></td>
              </tr>
            </table></td>
          </tr>
        </table></td>
      </tr>
    </table></td>
  </tr>
  <tr>
    <td>
    <form  action="<%=request.getContextPath()%>/visiteinfo.do?action=findList" target="rightFrame" method="post" >

    <table width="100%" border="0" cellpadding="0" cellspacing="1" bgcolor="#a8c7ce">
      <tr>
        <td width="15%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">IP</span></div></td>
        <td width="10%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">手机号</span></div></td>
         <td width="10%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">DID</span></div></td>
          <td width="10%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">栏目</span></div></td>
        <td width="15%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">游戏</span></div></td>
         <td width="10%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">位置</span></div></td>
         <td width="10%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">访问时间</span></div></td>
      </tr>
      <c:forEach items="${list}" var="obj" varStatus="statu">
      <tr>
        <td height="20" bgcolor="#FFFFFF" class="STYLE19"><div align="center"><c:out value="${obj.ip}"/></div></td>
 		<td height="20" bgcolor="#FFFFFF" class="STYLE19"><div align="center"><c:out value="${obj.telephone}"/></div></td>
 		<td height="20" bgcolor="#FFFFFF" class="STYLE19"><div align="center"><c:out value="${obj.did}"/></div></td>
 		<td height="20" bgcolor="#FFFFFF" class="STYLE19"><div align="center"><c:out value="${obj.titleid}"/></div></td>
 		<td height="20" bgcolor="#FFFFFF" class="STYLE19"><div align="center"><c:out value="${obj.gameid}"/></div></td>
 		<td height="20" bgcolor="#FFFFFF" class="STYLE19"><div align="center"><c:out value="${obj.location}"/></div></td>
 		<td height="20" bgcolor="#FFFFFF" class="STYLE19"><div align="center"><fmt:formatDate pattern="yyyy-MM-dd" value="${obj.vtime}"/></div></td>
      </tr>
      </c:forEach>
    </table>
    </form>
    </td>
  </tr>
  <tr>
    <td height="30"><table width="100%" border="0" cellspacing="0" cellpadding="0">
      <tr>
	<td colspan="10" id="no-right-border" class="h24"><div><jsp:include page="../pageUtil/pager.jsp"></jsp:include>
   	<script type="text/javascript">
      pager.method='findList';
   	</script></div></td>
	</tr>
    </table></td>
  </tr>
</table>
</body>
</html>
