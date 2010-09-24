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
  <form method="POST" action="<%=request.getContextPath()%>/business.do?action=doExpressCheckoutPayment">
    <table width=400>
	<tr>
	   <td>
	    ${resp}
	   </td>
	</tr>

	<tr>
		<td colspan="2" class="header">
			
			<input type="hidden" name="token" value="${token}" />
			<input type="hidden" name="PayerID" value="${PayerID}" />
			<input type="hidden" name="TotalAmount" value="${TotalAmount}" />
			<input type="submit" name="submit" id="submit" value="支付确认"/>
		</td>
	</tr>
</table>
    </form>
  </body>
</html>
