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
                <td width="94%" valign="bottom"><span class="STYLE1">游戏资源信息--类似机型匹配</span></td>
              </tr>
            </table>
           </td>
          </tr>
          </table>
        </td>
      </tr>
</table>

<form name="form" id="form" action="<%=request.getContextPath() %>/gameresouce.do?action=saveSimilar" method="post" enctype="multipart/form-data">

<table  width="100%" border="0" cellpadding="0" cellspacing="1" bgcolor="#EFF5FB">
			
					<input type="hidden" id="gameName" name="gameName" value=""/> 
				<tr>
				<td  height="30" align="right"><span class="STYLE10">新机型：</span></td>
				<td ><input type="text" id="did" name="did" value="" /> 
				<input type="button" id="getDid" name="getDid" value="选择机型" onclick="getMobileDid()"/>
				</td>
				</tr>
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">类似旧机型：</span></td>
				<td ><input type="text" id="did2" name="did2" value="" /> 
				<input type="button" id="getDid" name="getDid" value="选择机型" onclick="getMobileDid2()"/>
				</td>
				</tr>
				
				<tr>
				<td height="30" align="right"><span class="STYLE10">旧机型游戏：</span></td>
		
				<td >
				<input type="text" id="gameid" name="gameid" value="" /> 
				<input type="button" id="getGameName" name="getGameName" value="选择游戏" onclick="return getGame()"/>
				</td>
				</tr>
				
				<tr>
				<td width="30%"></td>
				<td width="30%" height="30" align="center">
				<span class="STYLE10"><input type="reset" id="reset" name="reset" value="重置"/></span>
					<span class="STYLE10"><input type="submit" id="submit" name="submit" value="提交"/> </span>
				</td>

				<td width="10%" height="30" align="center">
			
				</td>
				<td width="30%">
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
		var did2 = document.getElementById("did2").value;
		var did = document.getElementById("did").value;
		if(did2==""||did==""){
			alert("两处机型必填！");
			return;
		}
		var tempDid = did2.split(',');
		var myObject = new Object();
		myObject.gameid = document.getElementById("gameid").value;
		myObject.gameName = document.getElementById("gameName").value;
		
		window.showModalDialog("<%=request.getContextPath()%>/gameresouce.do?action=findGameByDid&did="+tempDid[0],myObject,'dialogHeight:500px; dialogLeft:500px;');
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
	
	function getMobileDid2(){
		var myObject = new Object();
		myObject.did = document.getElementById("did2").value;
		
		window.showModalDialog("<%=request.getContextPath()%>/mobileinfo.do?action=findListChoice",myObject,'dialogHeight:500px; dialogLeft:500px;');
		   if (myObject.did != '') {  
             document.getElementById('did2').value = myObject.did;  
          } 
	}
	</script>
</html>
