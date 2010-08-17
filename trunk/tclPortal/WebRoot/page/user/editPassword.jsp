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
<title>卓意综合管理平台</title>

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
                <td width="6%" height="19" valign="bottom"><div align="center"><img src="../../images/tb.gif" width="14" height="14" /></div></td>
                <td width="94%" valign="bottom"><span class="STYLE1">用户信息--修改密码</span></td>
              </tr>
            </table>
           </td>
          </tr>
          </table>
        </td>
      </tr>
</table>

<form name="form" id="form" action="<%=request.getContextPath() %>/user.do?action=updatePassword" method="post">
<table  width="100%" border="0" cellpadding="0" cellspacing="1" bgcolor="#EFF5FB">
				<input type="hidden" id="id" name="id" value="${sessionScope.user.id}"/>
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">原始密码：</span></td>
				<td ><input type="password" id="password" name="password" value=""/> 
				</td>
				</tr>
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">新密码：</span></td>
				<td ><input type="password" id="newPassword" name="newPassword" value=""/> 
				</td>
				</tr>
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">确认密码：</span></td>
				<td ><input type="password" id="checkPassword" name="checkPassword" value=""/> 
				</td>
				</tr>
				<tr>
				<td width="30%"></td>
				<td width="20%" height="30" align="center">
				<span class="STYLE10"><input type="reset" id="reset" name="reset" value="重置"/></span>
					<span class="STYLE10"><input type="button" id="submit" name="submit" value="提交" onclick="return submitInfo()"/> </span>
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
function submitInfo(){
		var id = document.getElementById("id").value;
		var password = document.getElementById("password").value;
		var newPassword = document.getElementById("newPassword").value;
		var checkPassword = document.getElementById("checkPassword").value;
		if(newPassword!=checkPassword){
			alert("二次输入密码不一致！");
			return false;
		}
		$.ajax({
		                type : "post",
		                url : "<%=request.getContextPath() %>/login.do",
		               	data : "action=updatePassword&id="+id+"&password="+password+"&newPassword="+newPassword,
		                datatype : "text",
		                success : function(data)
		                {  	
		                	if(data==1){
		                		alert("更新成功");
		                	}else{
		                	    alert("更新失败，原始密码错误");
		                	}
		                	
		                },
		                error: function(){
		                	alert("服务器没有返回数据，请重试");
		                }
		            });
	}
	</script>
</html>
