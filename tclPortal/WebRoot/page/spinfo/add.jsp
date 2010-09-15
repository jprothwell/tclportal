<%@ page pageEncoding="UTF-8" autoFlush="true"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
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
</style>
<title>TCL通讯游戏发布平台</title>

</head>

<body bgcolor="#EFF5FB">

<table width="100%" border="0" align="center" cellpadding="0" cellspacing="0">
  <tr>
    <td height="30"><table width="100%" border="0" cellspacing="0" cellpadding="0">
      <tr>
        <td height="24" bgcolor="#353c44">
        <table width="100%" border="0" cellspacing="0" cellpadding="0">
          <tr>
            <td>
            <table width="100%" border="0" cellspacing="0" cellpadding="0">
              <tr>
                <td width="6%" height="19" valign="bottom"><div align="center"><img src="images/tb.gif" width="14" height="14" /></div></td>
                <td width="94%" valign="bottom"><span class="STYLE1">SP信息--增加</span></td>
              </tr>
            </table>
           </td>
          </tr>
          </table>
        </td>
      </tr>
</table>

<form name="form" id="form" action="<%=request.getContextPath() %>/spinfo.do?action=save" method="post">
<table  width="100%" border="0" cellpadding="0" cellspacing="1" bgcolor="#EFF5FB">
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">SP：</span></td>
				<td ><input type="text" id="name" name="name" value=""/> 
				</td>
				</tr>
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">联系人：</span></td>
				<td ><input type="text" id="contactperson" name="contactperson" value=""/> 
				</td>
				</tr>
				
					<tr>
				<td  height="30" align="right"><span class="STYLE10">电话：</span></td>
				<td ><input type="text" id="phone" name="phone" value=""/> 
				</td>
				</tr>
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">地址：</span></td>
				<td ><input type="text" id="address" name="address" value=""/> 
				</td>
				</tr>
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">合同开始日期：</span></td>
				<td ><input type="text" id="begaintime" name="begaintime" class="Wdate" onFocus="WdatePicker({skin:'whyGreen'})" value="" style="WIDTH:90px"/> 
				</td>
				</tr>
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">合同结束日期：</span></td>
				<td ><input type="text" id="endtime" name="endtime" class="Wdate" onFocus="WdatePicker({skin:'whyGreen'})" value="" style="WIDTH:90px"/> 
				</td>
				</tr>
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">备注：</span></td>
				<td ><input type="text" id="remark" name="remark" value=""/> 
				</td>
				</tr>
				
				<tr>
				<td width="30%"></td>
				<td width="20%" height="30" align="center">
				<span class="STYLE10"><input type="reset" id="reset" name="reset" value="重置"/></span>
					<span class="STYLE10"><input type="submit" id="submit" name="submit" value="提交" onclick="return checkInfo()"/> </span>
				</td>

				<td width="15%" height="30" align="center">
			
				</td>
				<td width="35%">
				</td>
				</tr>
	</table>
</form>
</body>
<script language="JavaScript" type="text/javascript">
	function checkInfo(){
		//语言
		var name = document.getElementById("name").value;
		if(name==null||name==""){
			alert("请输入SP！");
			return false;
		}
	}
</script>
</html>
