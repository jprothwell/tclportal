<?xml version="1.0" encoding="utf-8"?>
<%@ page contentType="text/vnd.wap.wml;charset=UTF-8" language="java" import="java.util.*" pageEncoding="UTF-8" autoFlush="true"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/fmt" prefix="fmt"%>
<%
String groupid = (String)request.getAttribute("groupid");
String did = (String)request.getParameter("did");
String fid = (String)request.getAttribute("id");
%>
<!DOCTYPE html PUBLIC "-//WAPFORUM//DTD XHTML Mobile 1.0//EN" "http://www.wapforum.org/DTD/xhtml-mobile10.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
<meta http-equiv="Pragma" content="no-cache"/>
<meta http-equiv="Cache-Control" content="no-cache"/>
<meta http-equiv="Expires" content="0"/>
<LINK href="sdk.css" rel="stylesheet" type="text/css"/>
<title></title>
</head>
<body>
<center>
<form method="post" action="<%=request.getContextPath()%>/business.do?action=mobliePay">
<input type="hidden" name="id" value="${obj.id}"/>
<input type="hidden" size="3" maxlength="32" name="buyersemail" value="tmotion@tcl.com" />
<input type="hidden" size="3" maxlength="32" name="name" value="${obj.name}" />
<input type="hidden" size="3" maxlength="32" name="price" value="${obj.price}" />
<input type="hidden" size="3" maxlength="32" name="currencyCodeType" value="USD" />
<TABLE id="Table1">
	<tr><td colspan="2"><b>Shopping cart Products</b></td></tr>
	<tr  class="field">
		<td>Buyer's Email:</td>
		<td align="left">tmotion@tcl.com</td>
	</tr>
	<tr class="field">
		<td>商品名称:</td>
		<td align="left">${obj.name}</td>
	</tr>
		<tr class="field">
		<td>单价:</td>
		<td align="left">${obj.price}</td>
	</tr>
	<tr class="field">
		<td>Currency:</td>
		<td align="left">USD</td>
	</tr>
		<tr class="field">
		<td>支付Email:</td>
		<td align="left"><input type="text" size="20" name="chargeEmail" value=""/></td>
	</tr>
	<TR>
		<TD><input type="image" name="submit" src="<%=request.getContextPath()%>/images/btn_xpressCheckout.gif" /></TD>
	<TD align="left"><a href="/main?action=yewu&amp;groupid=${groupid}&amp;fid=${obj.id}&amp;did=${did}">返回</a></TD>
	</TR>
	<tr><td colspan="2">Save time. Pay securely without sharing your financial information.</td></tr>
</TABLE>
<BR/>
</form>
</center>
<br/>
</body>
</html>