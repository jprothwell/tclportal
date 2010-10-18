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
                <td width="94%" valign="bottom"><span class="STYLE1">手机信息--增加</span></td>
              </tr>
            </table>
           </td>
          </tr>
          </table>
        </td>
      </tr>
</table>

<form name="form" id="form" action="<%=request.getContextPath() %>/mobileinfo.do?action=save" method="post">
<table  width="100%" border="0" cellpadding="0" cellspacing="1" bgcolor="#EFF5FB">
				
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">DID：</span></td>
				<td ><input type="text" id="did" name="did" value=""/> 
				</td>
				</tr>
				
					<tr>
				<td  height="30" align="right"><span class="STYLE10">机型：</span></td>
				<td ><input type="text" id="phonetype" name="phonetype" value=""/> 
				</td>
				</tr>
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">屏幕：</span></td>
				<td ><input type="text" id="screen" name="screen" value=""/> 
				</td>
				</tr>
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">UA：</span></td>
				<td ><input type="text" id="ua" name="ua" value=""/> 
				</td>
				</tr>
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">WAP：</span></td>
				<td ><input type="text" id="wap" name="wap" value=""/> 
				</td>
				</tr>
				
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">内存大小：</span></td>
				<td ><input type="text" id="memory" name="memory" value=""/> 
				</td>
				</tr>
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">机型平台：</span></td>
				<td ><input type="text" id="platform" name="platform" value=""/> 
				</td>
				</tr>
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">页面：</span></td>
				<td >
				<select id="pageid" name="pageid">
						<option value="">选择页面</option>
					<c:forEach items="${pageinfoList}" var="obj" varStatus="statu">
						<option value="${obj.id}">${obj.pagename}</option>
					</c:forEach>
				</select> 
				</td>
				</tr>
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">触摸支持：</span></td>
				<td ><input type="radio" id="touchscreen" name="touchscreen" value = "1"><span class="STYLE10">支持</span>
				<input type="radio" id="touchscreen" name="touchscreen" value = "0" checked><span class="STYLE10">不支持</span>
				</td>
				</tr>
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">键盘类型：</span></td>
				<td >
				<input type="hidden" id="keyboard" name="keyboard" value=""/> 
				<input type="checkbox" id="keyboardCheck" name="keyboardCheck" value = "0"><span class="STYLE10">全键盘</span>
				<input type="checkbox" id="keyboardCheck" name="keyboardCheck" value = "1"><span class="STYLE10">九键键盘</span>
				<input type="checkbox" id="keyboardCheck" name="keyboardCheck" value = "2"><span class="STYLE10">全触摸</span>
				</td>
				</tr>
				
				<!--  
				<tr>
				<td  height="30" align="right"><span class="STYLE10">JAVA参数：</span></td>
				<td >
				<input type="hidden" id="javaparameter" name="javaparameter" value=""/>
				 <c:forEach items="${javaparameters}" var="obj" varStatus="statu">
				 	<c:if test="${statu.count%5==0}"><br/></c:if>
				 	<input type="checkbox" id="jp" name="jp" value="${obj.id}"/>${obj.name}
				 </c:forEach>
				</td>
				</tr>
				-->
				<tr>
				<td  height="30" align="right"><span class="STYLE10">时间：</span></td>
				<td ><input type="text" id="mtime" name="mtime" class="Wdate" onFocus="WdatePicker({skin:'whyGreen'})" value="<fmt:formatDate pattern="yyyy-MM-dd" value="${date}"/>" style="WIDTH:90px"/> 
				</td>
				</tr>
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">备注：</span></td>
				<td ><textarea id="remark"  name="remark" cols="25" rows="5"/></textarea>
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
	
		//DID
		var did = document.getElementById("did").value;
		if(did==null||did==""){
			alert("请填写DID！");
			return false;
		}
		
		//机型
		var phonetype = document.getElementById("phonetype").value;
		if(phonetype==null||phonetype==""){
			alert("请填写机型！");
			return false;
		}
		
		//UA
		var ua = document.getElementById("ua").value;
		if(ua==null||ua==""){
			alert("请填写UA！");
			return false;
		}
		//页面
		var pageid = document.getElementById("pageid").value;
		if(pageid==null||pageid==""){
			alert("请选择页面！");
			return false;
		}
		
		//
		//var javaparameters = document.getElementsByName("jp");
		//var javaparameter = "";
		//for(var i=0;i<javaparameters.length;i++){
		//	if(javaparameters[i].checked == true){
		//		javaparameter += javaparameters[i].value+":";
		//	}
		//}
		//document.getElementById("javaparameter").value = javaparameter;
		
		var keyboardCheck = document.getElementsByName("keyboardCheck");
		var keyboard ="";
		for(var i=0;i<keyboardCheck.length;i++){
			if(keyboardCheck[i].checked == true){
				keyboard += keyboardCheck[i].value+":";
			}
		}
		document.getElementById("keyboard").value = keyboard;
	}
</script>
</html>
