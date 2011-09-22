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
                <td width="94%" valign="bottom"><span class="STYLE1">IP信息--增加</span></td>
              </tr>
            </table>
           </td>
          </tr>
          </table>
        </td>
      </tr>
</table>

<form name="form" id="form" action="<%=request.getContextPath() %>/ipinfo.do?action=update" method="post">
<table  width="100%" border="0" cellpadding="0" cellspacing="1" bgcolor="#EFF5FB">
				<input type="hidden" id="id" name="id" value="${obj.id}"/>
				<input type="hidden" id="countryIdSelect" name="countryIdSelect" value="${obj.country}"/>
				<tr>
				<td height="30" align="right"><span class="STYLE10">国家：</span></td>
				<td ><select id="country" name="country" onchange="getProvince()">
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
				<select id="proviceid" name="proviceid" onchange="getCity()">
					<option value="">选择省州</option>
					${provinceSelect}
				</select> 
				</td>
				</tr>
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">城市：</span></td>
				<td >
				<select id="city" name="city">
					<option value="">选择城市</option>
					${citySelect}
				</select> 
				</td>
				</tr>
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">运营商：</span></td>
				<td >
				<select id="telecomoperators" name="telecomoperators">
					<option value="">选择运营商</option>
					${telecomoperatorsSelect}
				</select>
				</td>
				</tr>
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">IP：</span></td>
				<td >
				<input type="text" id="ip" name="ip" value="${obj.ip}"  onblur="ipFormat()"/><span class="STYLE10">格式(*.*.*)</span>
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
	window.onload = function(){
				var countryIdSelect = document.getElementById("countryIdSelect").value;
				$("#country").val(countryIdSelect);
			}
			
function getCity(){
		var provinceid = document.getElementById("proviceid").value;
		$.ajax({
		                type : "post",
		                url : "<%=request.getContextPath() %>/city.do",
		               	data : "action=findCityByProvince&provinceid="+provinceid,
		                datatype : "text",
		                success : function(data)
		                {  	
		                	$("#city").html(data);
		                },
		                error: function(){
		                	alert("服务器没有返回数据，请重试");
		                }
		            });
	}
	
	function getProvince(){
		var countryid = document.getElementById("country").value;
		$.ajax({
		                type : "post",
		                url : "<%=request.getContextPath() %>/province.do",
		               	data : "action=findProvAndTelecomByCountry&countryid="+countryid,
		                datatype : "text",
		                success : function(data)
		                {  	
		                	var response = data.split(";");
		                	$("#proviceid").html(response[0]);
		                	$("#telecomoperators").html(response[1]);
		                },
		                error: function(){
		                	alert("服务器没有返回数据，请重试");
		                }
		            });
	}
	
	function checkInfo(){
		//国家
		var country = document.getElementById("country").value;
		if(country==null||country==""){
			alert("请选择国家！");
			return false;
		}
		
		//运营商
		var telecomoperators = document.getElementById("telecomoperators").value;
		if(telecomoperators==null||telecomoperators==""){
			alert("请选择运营商！");
			return false;
		}
		//ip
		var ip = document.getElementById("ip").value;
		if(ip==null||ip==""){
			alert("请输入IP！");
			return false;
		}
		
	}
	
	//ip输入检测
	function ipFormat(){
		var ip = document.getElementById("ip").value;
		//检测格式
		var re=/^(\d+)\.(\d+)\.(\d+)\$/g //匹配
		if(re.test(ip))
		{
			if(RegExp.$1 <256 && RegExp.$2<256 && RegExp.$3<256){
				//检测是否重复
					$.ajax({
		                type : "post",
		                url : "<%=request.getContextPath() %>/ipinfo.do",
		               	data : "action=checkDual&ip="+ip,
		                datatype : "text",
		                success : function(data)
		                {  	
		                	if(data==1){
		                		alert(ip+",该IP已经存在！");
		                		document.getElementById("ip").value = "";
		                		return false;
		                	}
		                },
		                error: function(){
		                	alert("数据库连接错误，请稍后重试！");
		                	return false;
		                }
		            });
				return true;
			}else{
				alert("超出ip范围！");
				document.getElementById("ip").value = "";
				return false;
			}
			
		}else{
			alert("格式不正确！");
			document.getElementById("ip").value = "";
			return false;
		}
	}
	</script>
</html>
