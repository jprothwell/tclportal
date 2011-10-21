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
                <td width="94%" valign="bottom"><span class="STYLE1">业务统计--用户评论</span></td>
              </tr>
            </table></td>
            <td><div align="right"><span class="STYLE1">
              <img src="images/add.gif" width="10" height="10" /> <a href="#" onclick="checkAll()">全选</a>  &nbsp;
              <img src="images/add.gif" width="10" height="10" /> <a href="#" onclick="cancelAll()">全不选</a>  &nbsp;
              <img src="images/add.gif" width="10" height="10" /> <a href="#" onclick="showComment('1')">显示选中</a>&nbsp;
              <img src="images/add.gif" width="10" height="10" /> <a href="#" onclick="showComment('0')">不显示选中</a>&nbsp;
              <img src="images/add.gif" width="10" height="10" /> <a href="#" onclick="deleteComment()">删除选中</a>&nbsp;</div>
              </td>
          </tr>
        </table></td>
      </tr>
    </table></td>
  </tr>
  <tr>
    <td>
    <form  action="<%=request.getContextPath()%>/comment.do?action=findList" target="rightFrame" method="post" >
<table  width="100%" border="0" cellpadding="0" cellspacing="1" bgcolor="#EFF5FB">
				<input type="hidden" id="gameid" name="gameid" value="${gameid}"/>
				<tr>
				<c:if test="${gameid==''||gameid==null}">
					<td width="10%" height="30" align="right"><span class="STYLE10">游戏名称：</span></td>
					<td width="20%" >
					<input type="text" id="gameName" name="gameName" value=""/> 
					</td>
				</c:if>
				
				
				<td width="15%" height="30" align="right"><span class="STYLE10">起始时间：</span></td>
				<td width="25%" colspan="1" ><input name="startDate" type="text" class="Wdate" onFocus="WdatePicker({skin:'whyGreen'})" value="${startDate}" style="WIDTH:90px"></td>

				<td width="15%" height="30" align="right"><span class="STYLE10">结束时间：</span></td>
				<td width="25%" colspan="1" ><input name="endDate" type="text" class="Wdate" onFocus="WdatePicker({skin:'whyGreen'})" value="${endDate}" style="WIDTH:90px"></td>
				
				<td width="20%" colspan="1" align="left"><input type="submit" value="查询"></td>
				</tr>
	</table>
    <table width="100%" border="0" cellpadding="0" cellspacing="1" bgcolor="#a8c7ce">
      <tr>
       <td width="3%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">选择</span></div></td>
        <td width="20%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">用户</span></div></td>
        <td width="10%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">did</span></div></td>
        <td width="20%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">游戏</span></div></td>
         <td width="30%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">内容</span></div></td>
          <td width="10%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">时间</span></div></td>
           <td width="10%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">是否显示</span></div></td>
      </tr>
      <c:forEach items="${list}" var="obj" varStatus="statu">
      <tr>
       <td height="20" bgcolor="#FFFFFF" class="STYLE19"><div align="center"><input type="checkbox" name="check"  value="${obj.id}" /></div></td>
        <td height="20" bgcolor="#FFFFFF" class="STYLE19"><div align="center"><c:out value="${obj.mobileuserid}"/></div></td>
        <td height="20" bgcolor="#FFFFFF" class="STYLE19"><div align="center"><c:out value="${obj.did}"/></div></td>
 		<td height="20" bgcolor="#FFFFFF" class="STYLE19"><div align="center"><c:out value="${obj.gameName}"/></div></td>
 		<td height="20" bgcolor="#FFFFFF" class="STYLE19"><div align="center"><c:out value="${obj.content}"/></div></td>
 		<td height="20" bgcolor="#FFFFFF" class="STYLE19"><div align="center"><fmt:formatDate pattern="yyyy-MM-dd" value="${obj.ctime}"/></div></td>
 		<td height="20" bgcolor="#FFFFFF" class="STYLE19"><div align="center">
 		<c:choose>
 			<c:when test="${obj.disable==0}">不显示</c:when>
 			<c:when test="${obj.disable==1}">显示</c:when>
 		</c:choose>
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
	function checkAll(){
	
		var objs = document.getElementsByName("check");
		 for(var i=0; i<objs.length; i++) {
		  		objs[i].checked=true;
		  	}
	}
	
	function cancelAll(){
		var objs = document.getElementsByName("check");
		 for(var i=0; i<objs.length; i++) {
		  		objs[i].checked=false;
		  	}
	}
	
	function deleteComment(){
		 var nid = "";
      	 var objs = document.getElementsByName("check");
		  for(var i=0; i<objs.length; i++) {
		  		if(objs[i].checked==true){
		  			nid += objs[i].value+",";
		  		}	
		  	}
		  if(nid==""){
		  	alert("请先选择！");
		  	return false;
		  }	
		$.ajax({
		                type : "post",
		                url : "<%=request.getContextPath() %>/comment.do",
		               	data : "action=delete&nid="+nid,
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
		            
	function showComment(flag){
	
		 var nid = "";
      	 var objs = document.getElementsByName("check");
		  for(var i=0; i<objs.length; i++) {
		  		if(objs[i].checked==true){
		  			nid += objs[i].value+",";
		  		}	
		  	}
		  
		  if(nid==""){
		  	alert("请先选择！");
		  	return false;
		  }	
		  	
		$.ajax({
		                type : "post",
		                url : "<%=request.getContextPath() %>/comment.do",
		               	data : "action=update&flag="+flag+"&nid="+nid,
		                datatype : "text",
		                success : function(data)
		                {  	
		                	if(data!=1){
		                		alert("更新失败！");
		                	}
		                	window.location.reload();
		                },
		                error: function(){
		                	alert("更新失败！");
		                }
		            });
	}
</script>
</html>