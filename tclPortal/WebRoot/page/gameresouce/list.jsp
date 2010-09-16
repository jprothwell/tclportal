<%@ page language="java" import="java.util.*" pageEncoding="UTF-8" autoFlush="true"%>
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
a:link,a:visited,a:hover   {font-size:12px;color:#0066FF}
</style>
<title>TCL通讯游戏发布平台</title>

</head>

<body>
<table width="100%" border="0" align="center" cellpadding="0" cellspacing="0">
  <tr>
    <td height="30"><table width="100%" border="0" cellspacing="0" cellpadding="0">
      <tr>
        <td height="24" bgcolor="#353c44"><table width="100%" border="0" cellspacing="0" cellpadding="0">
          <tr>
            <td><table width="100%" border="0" cellspacing="0" cellpadding="0">
              <tr>
                <td width="6%" height="19" valign="bottom"><div align="center"><img src="images/tb.gif" width="14" height="14" /></div></td>
                <td width="94%" valign="bottom"><span class="STYLE1">游戏信息--游戏资源信息</span></td>
              </tr>
            </table></td>
               <td><div align="right"><span class="STYLE1">
            <img src="images/add.gif" width="10" height="10" /> <a href="<%=request.getContextPath()%>/gameresouce.do?action=add">增加</a>  &nbsp;</div>
              </td>
          </tr>
        </table></td>
      </tr>
    </table></td>
  </tr>
  <tr>
    <td>
    <form  action="<%=request.getContextPath()%>/gameresouce.do?action=findList" target="rightFrame" method="post" >
    <table  width="100%" border="0" cellpadding="0" cellspacing="1" bgcolor="#EFF5FB">
    			<input type="hidden" id="countryidSelect" name="countryidSelect" value="${countryidSelect}"/>
				<tr>		
				<td width="10%" height="30" align="right"><span class="STYLE10">游戏名称：</span></td>
				<td width="10%" >
				<input type="text" id="gamename" name="gamename" value=""/> 
				</td>
				
				<td width="10%" height="30" align="right"><span class="STYLE10">DID：</span></td>
				<td width="10%" >
				<input type="text" id="did" name="did" value=""/> 
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
				
				<td width="20%" align="center">
				<input type="submit" value="查询"></td>
				</tr>
	</table>
    <table width="100%" border="0" cellpadding="0" cellspacing="1" bgcolor="#a8c7ce">
      <tr>
      <td width="10%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">游戏</span></div></td>
        <td width="10%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">省份</span></div></td>
         <td width="10%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">机型</span></div></td>
         <td width="20%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">jar,jad文件名</span></div></td>
         <td width="10%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">优先级</span></div></td>
         <td width="5%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">标示类别</span></div></td>
          <td width="5%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">价格</span></div></td>
          <td width="10%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">是否可用</span></div></td>
            <td width="10%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">上线时间</span></div></td>
          <td width="10%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">操作</span></div></td>
      </tr>
      <c:forEach items="${list}" var="obj" varStatus="statu">
      <tr>
       <td height="20" bgcolor="#FFFFFF" class="STYLE19"><div align="center"><c:out value="${obj.gameName}"/></div></td>
        <td height="20" bgcolor="#FFFFFF" class="STYLE19"><div align="center"><c:out value="${obj.provinceName}"/></div></td>
        <td height="20" bgcolor="#FFFFFF" class="STYLE19"><div align="center"><c:out value="${obj.did}"/></div></td>
        <td height="20" bgcolor="#FFFFFF" class="STYLE19"><div align="center"><c:out value="${obj.jarfile};${obj.jadfile}"/></div></td>
        <td height="20" bgcolor="#FFFFFF" class="STYLE19"><div align="center"><c:out value="${obj.priority}"/></div></td>
        <td height="20" bgcolor="#FFFFFF" class="STYLE19"><div align="center"><c:out value="${obj.typeid}"/></div></td>
         <td height="20" bgcolor="#FFFFFF" class="STYLE19"><div align="center"><c:out value="${obj.price}"/></div></td>
        <td height="20" bgcolor="#FFFFFF" class="STYLE19"><div align="center">
          <c:choose>
          	<c:when test="${obj.disable==0}">不可用</c:when>
          	<c:when test="${obj.disable==1}">可用</c:when>
          </c:choose></div></td>
          <td height="20" bgcolor="#FFFFFF" class="STYLE19"><div align="center"><fmt:formatDate pattern="yyyy-MM-dd" value="${obj.starttime}"/></div></td>
        <td height="20" bgcolor="#FFFFFF" class="STYLE19"><div align="center">
          <a href="<%=request.getContextPath()%>/gameresouce.do?action=edit&id=${obj.id}">修改</a>
           <a href="#" onclick="deleteInfo('${obj.id}')">删除</a>
        </div></td>
      </tr>
      </c:forEach>
    </table>
    </form>
    </td>
  </tr>
  <tr>
    <td height="30"><table width="100%" border="0" cellspacing="0" cellpadding="0">
      <tr>
	<td colspan="10" id="no-right-border" class="h24"><div><jsp:include page="../pageUtil/pager.jsp"></jsp:include>
   	<script type="text/javascript">
      pager.method='findList';
   	</script></div></td>
	</tr>
    </table></td>
  </tr>
</table>
</body>
<script type="text/javascript">
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
	
	window.onload = function(){
		var countryidSelect = document.getElementById("countryidSelect").value;
		$("#countryid").val(countryidSelect);
	}
	
	function deleteInfo(id){
		$.ajax({
		                type : "post",
		                url : "<%=request.getContextPath() %>/gameresouce.do",
		               	data : "action=delete&id="+id,
		                datatype : "text",
		                success : function(data)
		                {  	
		                	if(data!=1){
		                		alert("删除失败！");
		                	}
		                	window.location.reload();
		                },
		                error: function(){
		                	alert("删除失败！");
		                }
		            });
		            }
</script>
</html>
