<?xml version="1.0" encoding="utf-8"?>
<%@ page contentType="text/vnd.wap.wml;charset=UTF-8" language="java" import="java.util.*" pageEncoding="UTF-8" autoFlush="true"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/fmt" prefix="fmt"%>
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
<P><span id="apiheader"><font size="3" color="black" face="Verdana"><b>支付下载</b> </font> </span></P>

<TABLE id="Table1">
	
	<TH>Shopping cart Products:</TH>
	<tr>
		<td class="field"><br/>
		Buyer's Email:</td>
		<td align="left"><br/>
		<input type="text" size="30" name="buyersemail"
			value="tmotion@tcl.com" readonly="readonly"/>
		<b>(Required)</b>
		</td>
	</tr>

	<tr>
	<input type="hidden" name="id" value="${obj.id}"/>
		<td class="field">商品名称:</td>
		<td><input type="text" size="30" maxlength="32" name="name"
			value="${obj.name}" readonly="readonly"/></td>

		<td class="field">单价:</td>
		<td><input type="text" name="price" size="5" maxlength="32"
			value="0.01" readonly="readonly"/></td>
		<td><input type="hidden" size="3" maxlength="32" name="num"
			value="1" /></td>

	</tr>
	<tr>
		<td class="field">Currency: <br />
		</td>
		<td><select name="currencyCodeType">
			<option value="USD">USD</option>
			<option value="GBP">GBP</option>
			<option value="EUR">EUR</option>
			<option value="JPY">JPY</option>
			<option value="CAD">CAD</option>
			<option value="AUD">AUD</option>
		</select></td>
	</tr>
		<tr>
		<td class="field"><br/>
		支付Email:</td>
		<td align="left"><br/>
		<input type="text" size="30" name="chargeEmail"
			value=""/><b>(已支付填写，可直接下载)</b></td>
	</tr>
	<TR>
		<TD><input type="image" name="submit"
			src="<%=request.getContextPath()%>/images/btn_xpressCheckout.gif" /></TD>
		<TD><BR/>
		<BR/>
		Save time. Pay securely without sharing your financial information.</TD>
	</TR>
</TABLE>
<BR/>
</form>
</center>
<br/>
</body>
</html>