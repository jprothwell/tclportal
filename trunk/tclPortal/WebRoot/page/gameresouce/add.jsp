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

<script src="<%=request.getContextPath()%>/js/jqueryAutocomplete/autocomplete.js" type="text/javascript"></script>
<link href="<%=request.getContextPath()%>/js/jqueryAutocomplete/autocomplete.css" rel="stylesheet" type="text/css" />
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
                <td width="94%" valign="bottom"><span class="STYLE1">游戏资源信息--增加</span></td>
              </tr>
            </table>
           </td>
          </tr>
          </table>
        </td>
      </tr>
</table>

<form name="form" id="form" action="<%=request.getContextPath() %>/gameresouce.do?action=save" method="post" enctype="multipart/form-data">

<table  width="100%" border="0" cellpadding="0" cellspacing="1" bgcolor="#EFF5FB">
				<tr>
				<td height="30" align="right"><span class="STYLE10">游戏：</span></td>
				<td ><input type="text" id="gameName" name="gameName" value="" /> 
				<input type="button" id="getGameName" name="getGameName" value="选择游戏" onclick="getGame()"/>
				<input type="hidden" id="gameid" name="gameid" value=""/> 
				</td>
				</tr>
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">机型：</span></td>
				<td ><input type="text" id="did" name="did" value="" /> 
				<input type="button" id="getDid" name="getDid" value="选择机型" onclick="getMobileDid()"/>
				</td>
				</tr>
				
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
				<td  height="30" align="right"><span class="STYLE10">优先级：</span></td>
				<td ><input type="text" id="priority" name="priority" value=""/> 
				</td>
				</tr>
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">价格：</span></td>
				<td ><input type="text" id="price" name="price" value=""/> 
				</td>
				</tr>
				
					<tr>
				<td  height="30" align="right"><span class="STYLE10">标示类别：</span></td>
				<td ><input type="text" id="typeid" name="typeid" value=""/> 
				</td>
				</tr>
				
					<tr>
				<td  height="30" align="right"><span class="STYLE10">是否可用：</span></td>
				<td >
				<span class="STYLE10">
				<input type="radio" id="disable" name="disable" value = "1" checked>可用
				<input type="radio" id="disable" name="disable" value = "0">不可用
				</span>
				</td>
				</tr>
				<tr>
				<td  height="30" align="right"><span class="STYLE10">上线时间：</span></td>
				<td ><input type="text" id="starttime" name="starttime" class="Wdate" onFocus="WdatePicker({skin:'whyGreen'})" value="<fmt:formatDate pattern="yyyy-MM-dd" value="${date}"/>" style="WIDTH:100px"/> 
				</td>
				</tr>
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">jar上传：</span></td>
				<td ><input type="file" id="fileOne" name="fileOne" value=""/> 
				</td>
				</tr>
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">jad上传：</span></td>
				<td ><input type="file" id="fileTwo" name="fileTwo" value=""/> 
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
	
	function getGame(){
		var myObject = new Object();
		myObject.gameid = document.getElementById("gameid").value;
		myObject.gameName = document.getElementById("gameName").value;
		
		window.showModalDialog("<%=request.getContextPath()%>/gameinfo.do?action=findListChoice",myObject,'dialogHeight:500px; dialogLeft:500px;');
		   if (myObject.gameid != '') {  
             document.getElementById('gameid').value = myObject.gameid;  
           } 
          if (myObject.gameName != '') {  
                document.getElementById('gameName').value = myObject.gameName;  
           } 
	}
	
	function getMobileDid(){
		var myObject = new Object();
		myObject.did = document.getElementById("did").value;
		
		window.showModalDialog("<%=request.getContextPath()%>/mobileinfo.do?action=findListChoice",myObject,'dialogHeight:500px; dialogLeft:500px;');
		   if (myObject.did != '') {  
             document.getElementById('did').value = myObject.did;  
          } 
	}
	
	//验证
	function checkInfo(){
	
		//游戏名称
		var gameid = document.getElementById("gameid").value;
		if(gameid==null||gameid==""){
			alert("请选择游戏！");
			return false;
		}
		//机型
		var did = document.getElementById("did").value;
		if(did==null||did==""){
			alert("请选择机型！");
			return false;
		}
		//价格
		var price = document.getElementById("price").value;
		if(!price.IsNumberCheck()){
			alert("请正确填写价格！");
			return false;
		}
		
		//上传文件
   			var jar = document.getElementById("fileOne").value;
    	 	if(jar == ""){
   				alert("请上传jar文件！");
   				return false;
   			}else{
   				//检查文件格式
   				var files = jar.split('\\');
   				var fileName = files[files.length-1].split('.')[1];
   				if(!(fileName=='jar')){
   					alert("上传jar格式不正确！");
   					return false;
   					}
   			}
   			//小图标
   			var jad = document.getElementById("fileTwo").value;
    	 	if(jad == ""){
   				alert("请上传小图标！");
   				return false;
   			}else{
   				//检查文件格式
   				var files = jad.split('\\');
   				var fileName = files[files.length-1].split('.')[1];
   				if(!(fileName=='jad')){
   					alert("上传jad格式不正确！");
   					return false;
   					}
   			}
	}
	</script>
</html>
