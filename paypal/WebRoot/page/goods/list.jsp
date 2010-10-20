<%@ page language="java" import="java.util.*" pageEncoding="UTF-8" autoFlush="true"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/fmt" prefix="fmt"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title></title>
</head>

<body>
    <table width="80%" border="0" cellpadding="0" cellspacing="1" bgcolor="#a8c7ce">
      <tr>
        <td width="30%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">名称</span></div></td>
        <td width="30%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">单价</span></div></td>
        <td width="30%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">详细</span></div></td>
      </tr>
      <c:forEach items="${list}" var="obj" varStatus="statu">
      <tr>
        <td height="30%" bgcolor="#FFFFFF" class="STYLE19"><div align="center"><c:out value="${obj.name}"/></div></td>
        <td height="30%" bgcolor="#FFFFFF" class="STYLE19"><div align="center"><c:out value="${obj.price}"/></div></td>
        <td width="30%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><a href="<%=request.getContextPath()%>/goods.do?action=view&id=${obj.id}&did=1&groupid=2">查看</a></div></td>
      </tr>
      </c:forEach>
    </table>
</body>
</html>
