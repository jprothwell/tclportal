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
                <td width="94%" valign="bottom"><span class="STYLE1">游戏资源信息--修改</span></td>
              </tr>
            </table>
           </td>
          </tr>
          </table>
        </td>
      </tr>
</table>

<form name="form" id="form" action="<%=request.getContextPath() %>/gameresouce.do?action=update" method="post">
<table  width="100%" border="0" cellpadding="0" cellspacing="1" bgcolor="#EFF5FB">
				<input type="hidden" id="id" name="id" value="${obj.id}"/>
				<tr>
				<td height="30" align="right"><span class="STYLE10">游戏：</span></td>
				<td ><input type="text" id="gameName" name="gameName" value="${gameName}" disabled="disabled"/>
				<input type="hidden" id="gameid" name="gameid" value="${obj.gameid}"/> 
				</td>
				</tr>
				
					<tr>
				<td  height="30" align="right"><span class="STYLE10">机型：</span></td>
				<td ><input type="text" id="did" name="did" value="${obj.did}" readonly="readonly"/> 
				</td>
				</tr>
				
				<input type="hidden" id="countryIdSelect" name="countryIdSelect" value="${countryId}"/>
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
					${provinceidSelect}
				</select> 
				</td>
				</tr>
				
			
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">存放路径：</span></td>
				<td ><input type="text" id="path" name="path" value="${obj.path}"/> 
				</td>
				</tr>
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">优先级：</span></td>
				<td ><input type="text" id="priority" name="priority" value="${obj.priority}"/> 
				</td>
				</tr>
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">价格：</span></td>
				<td ><input type="text" id="price" name="price" value="${obj.price}"/> 
				<input type="hidden" id="oprice" name="oprice" value="${obj.price}"/> 
				</td>
				</tr>
				
					<tr>
				<td  height="30" align="right"><span class="STYLE10">标示类别：</span></td>
				<td ><input type="text" id="type" name="type" value="${obj.type}"/> 
				</td>
				</tr>
				
					<tr>
				<td  height="30" align="right"><span class="STYLE10">是否可用：</span></td>
				<td >	
				<input type="hidden" id="odisable" name="odisable" value="${obj.disable}"/>
				<span class="STYLE10">
				<c:choose>
					<c:when test="${obj.disable=='1'}">
						<input type="radio" id="disable" name="disable" value = "1" checked>可用
						<input type="radio" id="disable" name="disable" value = "0">不可用
					</c:when>
					<c:when test="${obj.disable=='0'}">
						<input type="radio" id="disable" name="disable" value = "1" >可用
						<input type="radio" id="disable" name="disable" value = "0" checked>不可用
					</c:when>
				</c:choose>
				</span> 
				</td>
				</tr>
				
					<tr>
				<td  height="30" align="right"><span class="STYLE10">上线时间：</span></td>
				<td >
				<input type="text" id="starttime" name="starttime" class="Wdate" onFocus="WdatePicker({skin:'whyGreen'})" value="<fmt:formatDate pattern="yyyy-MM-dd" value="${obj.starttime}"/>" style="WIDTH:90px"/> 
				</td>
				</tr>
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">上传：</span></td>
				<td ><input type="file" id="files" name="files" value=""/> 
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
<script language="JavaScript" type="text/javascript">
	window.onload = function(){
				var countryIdSelect = document.getElementById("countryIdSelect").value;
				$("#countryid").val(countryIdSelect);
			}

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
	</script>
</html>
