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
                <td width="94%" valign="bottom"><span class="STYLE1">游戏资源信息--修改顺序</span></td>
              </tr>
            </table>
           </td>
          </tr>
          </table>
        </td>
      </tr>
</table>

<form name="form" id="form" action="<%=request.getContextPath() %>/gameresouce.do?action=update" method="post" enctype="multipart/form-data">
<table  width="100%" border="0" cellpadding="0" cellspacing="1" bgcolor="#EFF5FB">
				
				<tr>		
				<td width="10%" height="30" align="right"><span class="STYLE10">机型：</span></td>
				<td width="10%" >
				<select id="did" name="did">
					<option value="">选择机型</option>
				<c:forEach items="${mobileList}" var="obj" varStatus="statu">
					<option value="${obj.did}">${obj.phonetype}</option>
				</c:forEach>
				</select> 
				</td>
				
				<td width="10%" height="30" align="right"><span class="STYLE10">类型：</span></td>
				<td width="10%" >
				<select id="typeId" name="typeId">
					<option value="">选择类型</option>
				<c:forEach items="${typeList}" var="obj" varStatus="statu">
					<option value="${obj.id}">${obj.typevalue}</option>
				</c:forEach>
				</select> 
				</td>
				
				<td width="10%" height="30" align="right"><span class="STYLE10">国家：</span></td>
				<td width="10%" >
				<select id="countryid" name="countryid" onchange="getProvince()">
					<option value="">选择国家</option>
				<c:forEach items="${listCountry}" var="obj" varStatus="statu">
					<option value="${obj.id}">${obj.name}</option>
				</c:forEach>
				</select> 
				</td>
				
				<td width="10%"  height="30" align="right"><span class="STYLE10">省（州）：</span></td>
				<td width="10%" >
				<select id="provinceid" name="provinceid">
					<option value="">选择省(州)</option>
						${provinceidSelect}
				</select> 
				</td>
				
				<td width="10%" align="left">
				<input type="submit" value="查询" onclick="return checkInfo()"></td>
				</tr>
				<tr>
			
				<tr>
				<td  height="30" align="center"><span class="STYLE10"></span></td>
				
				<td  height="30" align="center"><span class="STYLE10">游戏列表：</span></td>
				<td ><select id='selList' size='20' style='width: 250px'> 
				<c:forEach items="${listCountry}" var="obj" varStatus="statu">
					<option value="${obj.id}">${obj.gameName}</option>
				 </c:forEach>
				 </select>
				</td>
				</tr>
				
				<tr>
				<td  height="30" align="center"><span class="STYLE10"></span></td>
				<td  height="30" align="center"><span class="STYLE10">
				</span></td>
				<td ><input type="button" value="▲" id="btnMoveUp" title="快速鍵: alt+向上" />  
  				 	<input type="button" value="▼" id="btnMoveDown" title="快速鍵: alt+向下"/>
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
		//机型
		var did = document.getElementById("did").value;
		if(did==null||did==""){
			alert("请选择机型！");
			return false;
		}
		var typeId = document.getElementById("typeId").value;
		if(typeId==null||typeId==""){
			alert("请选择类型！");
			return false;
		}
		var countryid = document.getElementById("countryid").value;
		if(countryid==null||countryid==""){
			alert("请选择国家！");
			return false;
		}
	}
	
	  $(function() {  
		  $("#btnMoveUp,#btnMoveDown").click(function() {  
		    var $opt = $("#selList option:selected:first");  
		    if (!$opt.length) return;  
		    if (this.id == "btnMoveUp") $opt.prev().before($opt);  
		    else $opt.next().after($opt);  
  		});  
  		
  		//按Alt加上下鍵也可以移動  
 	 	$("#selList").keydown(function(evt) {  
		    if (!evt.altKey) return;  
		    var k = evt.which;  
		    if (k == 38) { $("#btnMoveUp").click(); return false; }  
		    else if (k == 40) { $("#btnMoveDown").click(); return false; }  
  			});  
  		});  
	</script>
</html>
