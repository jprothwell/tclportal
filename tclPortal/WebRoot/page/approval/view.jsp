<%@ page pageEncoding="UTF-8" autoFlush="true"%>
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
                <td width="94%" valign="bottom"><span class="STYLE1">审批信息--终审</span></td>
              </tr>
            </table>
           </td>
          </tr>
          </table>
        </td>
      </tr>
</table>

<form name="form" id="form" action="<%=request.getContextPath() %>/approval.do?action=update&tag=3" method="post">
<table  width="100%" border="0" cellpadding="0" cellspacing="1" bgcolor="#EFF5FB">
				<input type="hidden" id="id" name="id" value="${obj.id}"/> 
				<tr>
				<td  height="30" align="right"><span class="STYLE10">游戏：</span></td>
				<td ><input type="text" value="${obj.game}" readonly="readonly"/> 
				</td>
				</tr>
				
					<tr>
				<td  height="30" align="right"><span class="STYLE10">申请人：</span></td>
				<td ><input type="text" value="${obj.proposerName}" readonly="readonly"/> 
				</td>
				</tr>
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">申请人意见：</span></td>
				<td ><textarea cols="30" rows="5" readonly="readonly" />${obj.content}</textarea>
				</td>
				</tr>
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">申请时间：</span></td>
				<td ><fmt:formatDate pattern="yyyy-MM-dd" value="${obj.protime}"/>
				</td>
				</tr>
				
					<tr>
				<td  height="30" align="right"><span class="STYLE10">复核人：</span></td>
				<td ><input type="text" value="${obj.checkerName}" readonly="readonly"/> 
				</td>
				</tr>
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">审核人意见：</span></td>
				<td ><textarea  cols="30" rows="5" id="checkinfo" name="checkinfo" readonly="readonly"/>${obj.checkinfo}</textarea>
				</td>
				</tr>
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">复核时间：</span></td>
				<td ><fmt:formatDate pattern="yyyy-MM-dd" value="${obj.checktime}"/>
				</td>
				</tr>
				
						<tr>
				<td  height="30" align="right"><span class="STYLE10">终审人：</span></td>
				<td ><input type="text" value="${obj.finalcheckerName}" readonly="readonly"/> 
				</td>
				</tr>
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">终审意见：</span></td>
				<td ><textarea  cols="30" rows="5" id="finalcheckinfo"  name="finalcheckinfo" readonly="readonly"/>${obj.finalcheckinfo}</textarea>
				</td>
				</tr>
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">终审时间：</span></td>
				<td ><fmt:formatDate pattern="yyyy-MM-dd" value="${obj.finalchecktime}"/>
				</td>
				</tr>
				
				<tr>
				<td width="30%"></td>
				<td width="20%" height="30" align="center">
				<span class="STYLE10"><input type="reset" id="reset" name="reset" value="重置"/></span>
					<span class="STYLE10"><input type="submit" id="submit" name="submit" value="提交"/> </span>
				</td>

				<td width="15%" height="30" align="center">
			
				</td>
				<td width="35%">
				</td>
				</tr>
	</table>
</form>
</body>
</html>
