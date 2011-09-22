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
                <td width="94%" valign="bottom"><span class="STYLE1">角色信息--增加</span></td>
              </tr>
            </table>
           </td>
          </tr>
          </table>
        </td>
      </tr>
</table>

<form name="form" id="form" action="<%=request.getContextPath() %>/role.do?action=save" method="post">
<table  width="100%" border="0"  cellpadding="0" cellspacing="1" bgcolor="#EFF5FB">
				<input type="hidden" id="id" name="id" value="${obj.id}"/>
				<tr>
				<td height="30" align="center"><span class="STYLE10">角色：</span></td>
				<td><input type="text" id="name" name="name" value="${obj.name}"/> </td>
				</tr>
				
				<tr>
				<td  height="30" align="center"><span class="STYLE10">说明：</span></td>
				<td><textarea id="description"  cols="30" rows="5" name="description"/>${obj.description}</textarea>
				</td>
				</tr>
				
				<tr>
				<td  height="30" align="center"><span class="STYLE10">拥有权限：</span></td>
				<td>
				<input type="hidden" id="resourceIdOrig" name="resourceIdOrig" value="${obj.resources}"/>
				 <c:forEach items="${listResource}" var="obj" varStatus="statu">
				 <c:if test="${statu.count%5==0}"><br/></c:if>
				 	<input type="checkbox" id="resourceId" name="resourceId" value="${obj.id}"/>${obj.name}
				 </c:forEach>
				</td>
				</tr>
				
				<tr>
				<td height="30" align="center">
				<span class="STYLE10"><input type="reset" id="reset" name="reset" value="重置"/></span></td>
				<td>
				<span class="STYLE10"><input type="button" id="submit" name="submit" value="提交" onclick="submitInfo()"/> </span>
				</td>
				</tr>
	</table>
</form>
</body>
<script language="JavaScript" type="text/javascript">
	window.onload = function(){
			var resourceIdOrig = document.getElementById("resourceIdOrig").value;
			var resourceOrig = resourceIdOrig.split(":");
			var resourceIds = document.getElementsByName("resourceId");
			for(var i=0;i<resourceIds.length;i++){
				for(var j=0;j<resourceOrig.length;j++){
					if(resourceIds[i].value==resourceOrig[j]){
						resourceIds[i].checked=true;
					}
				}
			}
		}
		
	function submitInfo(){
		var id = document.getElementById("id").value;
		var name = document.getElementById("name").value;
		var description = document.getElementById("description").value;
		var resourceIds = document.getElementsByName("resourceId");
		var resourceId = "";
		for(var i=0;i<resourceIds.length;i++){
			if(resourceIds[i].checked == true){
				resourceId += resourceIds[i].value+":";
			}
			
		}
		$.ajax({
		                type : "post",
		                url : "<%=request.getContextPath() %>/role.do",
		               	data : "action=update&id="+id+"&name="+name+"&description="+description+"&resources="+resourceId,
		                datatype : "text",
		                success : function(data)
		                {  	
		                	alert("更新成功");
		                },
		                error: function(){
		                	alert("服务器没有返回数据，请重试");
		                }
		            });
	}
</script>
</html>
