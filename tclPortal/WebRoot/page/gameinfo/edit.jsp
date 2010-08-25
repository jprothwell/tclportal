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
                <td width="94%" valign="bottom"><span class="STYLE1">游戏基本信息--修改</span></td>
              </tr>
            </table>
           </td>
          </tr>
          </table>
        </td>
      </tr>
</table>

<form name="form" id="form" action="<%=request.getContextPath() %>/gameinfo.do?action=update" method="post" enctype="multipart/form-data">
<table  width="100%" border="0" cellpadding="0" cellspacing="1" bgcolor="#EFF5FB">
				<input type="hidden" id="id" name="id" value="${obj.id}"/>
				<input type="hidden" id="spidSelect" name="spidSelect" value="${obj.spid}"/>
				<tr>
				<td  height="30" align="right"><span class="STYLE10">名称：</span></td>
				<td ><input type="text" id="gamename" name="gamename" value="${obj.gamename}"/> 
				</td>
				</tr>
					<tr>
				<td  height="30" align="right"><span class="STYLE10">图片名：</span></td>
				<td ><input type="text" id="imagename" name="imagename" value="${obj.imagename}" disabled="disabled"/> 
				</td>
				</tr>
				
					<tr>
				<td  height="30" align="right"><span class="STYLE10">小图标名：</span></td>
				<td ><input type="text" id="icon" name="icon" value="${obj.icon}" disabled="disabled"/> 
				</td>
				</tr>
					<tr>
				<td  height="30" align="right"><span class="STYLE10">类别：</span></td>
				<td ><input type="hidden" id="kindidSelect" name="kindidSelect" value="${obj.kindid}"/> 
				<select id="kindid" name="kindid">
					<option value="">选择类别</option>
				<c:forEach items="${listTypes}" var="obj" varStatus="statu">
					<option value="${obj.id}">${obj.typevalue}</option>
				</c:forEach>
				</select> 
				</td>
				</tr>
				
				
			
				
					<tr>
				<td  height="30" align="right"><span class="STYLE10">SP：</span></td>
				<td ><select id="spid" name="spid">
					<option value="">选择SP</option>
				<c:forEach items="${spinfoList}" var="obj" varStatus="statu">
					<option value="${obj.id}">${obj.name}</option>
				</c:forEach>
				</select>  
				</td>
				</tr>
				
			
				
					<tr>
				<td  height="30" align="right"><span class="STYLE10">语言：</span></td>
				<td ><input type="hidden" id="languageSelect" name="languageSelect" value="${obj.language}"/> 
				<select id="language" name="language">
					<option value="">选择语言</option>
				<c:forEach items="${languageList}" var="obj" varStatus="statu">
					<option value="${obj.id}">${obj.language}</option>
				</c:forEach>
				</select> 
				</td>
				</tr>
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">风格：</span></td>
				<td ><input type="text" id="style" name="style" value="${obj.style}"/> 
				</td>
				</tr>
				
			
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">简介：</span></td>
				<td ><textarea cols="30" rows="2" id="brief" name="brief"/>${obj.brief}</textarea>
				</td>
				</tr>
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">详细：</span></td>
				<td ><textarea cols="30" rows="5" id="detailinfo" name="detailinfo"/>${obj.detailinfo}</textarea>
				</td>
				</tr>
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">级别：</span></td>
				<td ><input type="text" id="lev" name="lev" value="${obj.lev}"/> 
				</td>
				</tr>
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">是否可用：</span></td>
				<td >	
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
				<td  height="30" align="right"><span class="STYLE10">添加时间：</span></td>
				<td ><input type="text" id="addtime" name="addtime" class="Wdate" onFocus="WdatePicker({skin:'whyGreen'})" value="<fmt:formatDate pattern="yyyy-MM-dd" value="${obj.addtime}"/>" style="WIDTH:90px"/> 
				</td>
				</tr>
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">图标上传：</span></td>
				<td ><input type="file" id="filesOne" name="fileOne" value=""/> 
				</td>
				</tr>
				
				<tr>
				<td  height="30" align="right"><span class="STYLE10">小图标上传：</span></td>
				<td ><input type="file" id="filesTwo" name="fileTwo" value=""/> 
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
				var spidSelect = document.getElementById("spidSelect").value;
				var languageSelect = document.getElementById("languageSelect").value;
				var kindidSelect = document.getElementById("kindidSelect").value;
				$("#spid").val(spidSelect);
				$("#language").val(languageSelect);
				$("#kindid").val(kindidSelect);
			}
</script>
</html>
