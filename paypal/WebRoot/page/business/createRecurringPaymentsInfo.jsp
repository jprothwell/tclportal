<%@ page language="java" import="java.util.*" pageEncoding="utf-8"%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <title></title>
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
  </head>
  
  <body>
  <form method="POST" action="<%=request.getContextPath()%>/business.do?action=getRecurringPaymentsProfileDetails">
    <table width=400>
	<tr>
	   <td>
	    ${resp}
	   </td>
	</tr>
</table>
<input type="submit" id="sub" name="sub" value="获取详细信息"/>
    </form>
  </body>
</html>
