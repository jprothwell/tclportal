<%@ page language="java" import="java.util.*" pageEncoding="UTF-8" autoFlush="true"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/fmt" prefix="fmt"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<script type="text/javascript" src="<%=request.getContextPath()%>/js/My97DatePicker/WdatePicker.js"></script>
<script src="<%=request.getContextPath()%>/js/jquery.js" type="text/javascript"></script>
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
<title>查询</title>

</head>
<body>
<table width="100%" border="0" align="center" cellpadding="0" cellspacing="0">
</table>
 <form  action="<%=request.getContextPath()%>/business.do?action=findList" target="rightFrame" method="post" >
<table  width="100%" border="0" cellpadding="0" cellspacing="1" bgcolor="#EFF5FB">
				<tr>
				<td width="15%" height="30" align="right"><span class="STYLE10">订单：</span></td>
				<td width="25%" colspan="1" ><input name="tradeId" type="text" value=""></td>

				<td width="15%" height="30" align="right"><span class="STYLE10">paypal账号：</span></td>
				<td width="25%" colspan="1" ><input name="customerPaypal" type="text" value=""></td>
				
				</tr>
				<tr>
				<td width="15%" height="30" align="right"><span class="STYLE10">起始时间：</span></td>
				<td width="25%" colspan="1" ><input name="startDate" type="text" class="Wdate" onFocus="WdatePicker({skin:'whyGreen'})" value="${startDate}" style="WIDTH:90px"></td>

				<td width="15%" height="30" align="right"><span class="STYLE10">结束时间：</span></td>
				<td width="25%" colspan="1" ><input name="endDate" type="text" class="Wdate" onFocus="WdatePicker({skin:'whyGreen'})" value="${endDate}" style="WIDTH:90px"></td>
				
				<td width="20%" colspan="1" align="left"><input type="submit" value="查询"></td>
				</tr>
	</table>
    <table width="100%" border="0" cellpadding="0" cellspacing="1" bgcolor="#a8c7ce">
      <tr>
        <td width="40%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">订单号</span></div></td>
        <td width="40%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">paypal账号</span></div></td>
        <td width="10%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">状态</span></div></td>
         <td width="10%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">时间</span></div></td>
      </tr>
      <c:forEach items="${list}" var="obj" varStatus="statu">
      <tr>
        <td height="20" bgcolor="#FFFFFF" class="STYLE19"><div align="center"><c:out value="${obj.ordernum}"/></div></td>
 		<td height="20" bgcolor="#FFFFFF" class="STYLE19"><div align="center"><c:out value="${obj.customerpaypalnum}"/></div></td>
 		<td height="20" bgcolor="#FFFFFF" class="STYLE19"><div align="center">
 		  <c:choose>
 			<c:when test="${obj.statute==0}">支付成功</c:when>
          	<c:when test="${obj.statute==1}">确认成功</c:when>
          	<c:when test="${obj.statute==20}">确认失败，重发</c:when>
          	<c:when test="${obj.statute==30}">重发失败</c:when>
          </c:choose>
 		</div></td>
 		<td height="20" bgcolor="#FFFFFF" class="STYLE19"><div align="center"><fmt:formatDate pattern="yyyy-MM-dd" value="${obj.savetime}"/></div></td>
      </tr>
      </c:forEach>
    </table>
    </form>

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

</body>
</html>
