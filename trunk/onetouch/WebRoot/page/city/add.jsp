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
                <td width="94%" valign="bottom"><span class="STYLE1">城市信息--增加</span></td>
              </tr>
            </table>
           </td>
          </tr>
          </table>
        </td>
      </tr>
</table>

<form name="form" id="form" action="<%=request.getContextPath() %>/city.do?action=save" method="post">
<table  width="100%" border="0" cellpadding="0" cellspacing="1" bgcolor="#EFF5FB">
				<tr>
				<td height="30" align="right"><span class="STYLE10">国家：</span></td>
				<td ><select id="countryid" name="countryid" onchange="getProvince()">
					<option value="">选择国家</option>
				<c:forEach items="${listCountry}" var="obj" varStatus="statu">
					<option value="${obj.id}">${obj.name}</option>
				</c:forEach>
				</select> 
				</td>
				</tr>
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">省（州）：</span></td>
				<td >
				<select id="provinceid" name="provinceid">
					<option value="">选择省州</option>
				</select> 
				</td>
				</tr>
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">城市：</span></td>
				<td ><input type="text" id="cityname" name="cityname" value=""/> 
				</td>
				</tr>
				
					<tr>
				<td  height="30" align="right"><span class="STYLE10">编号：</span></td>
				<td ><input type="text" id="citycode" name="citycode" value=""/> 
				</td>
				</tr>
				
					<tr>
				<td  height="30" align="right"><span class="STYLE10">备注：</span></td>
				<td ><input type="text" id="remarker" name="remarker" value=""/> 
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
function getProvince(){
		var countryid = document.getElementById("countryid").value;
		$.ajax({
		                type : "post",
		                url : "<%=request.getContextPath() %>/province.do",
		               	data : "action=findProvinceByCountry&countryid="+countryid,
		                datatype : "text",
		                success : function(data)
		                {  	
		                	$("#provinceid").html(data);
		                },
		                error: function(){
		                	alert("服务器没有返回数据，请重试");
		                }
		            });
	}
	
	function checkInfo(){
		//国家
		var countryid = document.getElementById("countryid").value;
		if(countryid==null||countryid==""){
			alert("请选择国家！");
			return false;
		}
		//省份
		var provinceid = document.getElementById("provinceid").value;
		if(provinceid==null||provinceid==""){
			alert("请选择省份！");
			return false;
		}
		//城市
		var cityname = document.getElementById("cityname").value;
		if(cityname==null||cityname==""){
			alert("请输入城市！");
			return false;
		}
	}

	</script>
</html>