<%@ page language="java" import="java.util.*" pageEncoding="UTF-8" autoFlush="true"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/fmt" prefix="fmt"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<HEAD>
<title></title>
<LINK href="sdk.css" rel="stylesheet" type="text/css">
</HEAD>
<body>

<center>
<!-- 
<form method="POST" action="<%=request.getContextPath()%>/business.do?action=mobliePay">
<P><span id="apiheader"><font size=3 color=black face=Verdana><b>手机支付 SetExpress
Checkout</b> </font> </span></P>

<TABLE id="Table1">
	
	<TH>Shopping cart Products:</TH>
	<tr>
		<td align=right><br>
		Buyer's Email:</td>
		<td align=left><br>
		<input type="text" size="30" name="buyersemail"
			value="tmotion@tcl.com"><b>(Required)</b></td>

	</tr>
	<tr>
		<td class="field">商品名称</td>
		<td><input type="text" size="30" maxlength="32" name="L_NAME0"
			value="${obj.name}" /></td>


		<td class="field">单价:</td>
		<td><input type="text" name="L_AMT0" size="5" maxlength="32"
			value="${obj.price}" /></td>

		<td class="field">Quantity:</td>
		<td><input type="text" size="3" maxlength="32" name="L_QTY0"
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
	<TR>
		<TD><input type="image" name="submit"
			src="https://www.paypal.com/en_US/i/btn/btn_xpressCheckout.gif" /> 
<input type="hidden" name=paymentType value=<%=request.getParameter("paymentType")%>/></TD>
		<TD><BR>
		<BR>
		Save time. Pay securely without sharing your financial information.</TD>
	</TR>
</TABLE>
<BR>
</form>
 -->
<form method="POST" action="<%=request.getContextPath()%>/business.do?action=payFor">
<P><span id="apiheader"></span></P>

<TABLE id="Table1">
	
	<TH>Shopping cart Products:</TH>
	<tr>
		<td class="field"><br>
		Buyer's Email:</td>
		<td align=left><br>
		<input type="text" size="30" name="buyersemail"
			value="tmotion@tcl.com" readonly=readonly><b>(Required)</b></td>

	</tr>

	<tr>
	<input type="hidden" name="id" value="1"/>
		<td class="field">商品名称:</td>
		<td><input type="text" size="30" maxlength="32" name="tradeId"
			value="shangmail" readonly=readonly/></td>

		<td class="field">单价:</td>
		<td><input type="text" name="price" size="5" maxlength="32"
			value="1.10" readonly=readonly/></td>
		<td><input type="hidden" size="3" maxlength="32" name="price"
			value="1.01" /></td>

	</tr>
	<tr>
		<td class="field">Currency: <br />
		</td>
		<td><select name="currency">
			<option value="USD">USD</option>
			<option value="GBP">GBP</option>
			<option value="EUR">EUR</option>
			<option value="JPY">JPY</option>
			<option value="CAD">CAD</option>
			<option value="AUD">AUD</option>
		</select></td>
	</tr>
	<TR>
		<TD><input type="image" name="submit"
			src="<%=request.getContextPath()%>/images/btn_xpressCheckout.gif" /> 
</TD>
		<TD><BR>
		<BR>
		Save time. Pay securely without sharing your financial information.</TD>
	</TR>
</TABLE>
<BR>
</form>
</center>
<br>
</body>
</HTML>