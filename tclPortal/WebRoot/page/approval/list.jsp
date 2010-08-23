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
                <td width="94%" valign="bottom"><span class="STYLE1">业务统计--审批</span></td>
              </tr>
            </table></td>
            <c:if test="${roleId==1}">
             <td><div align="right"><span class="STYLE1">
            <img src="images/add.gif" width="10" height="10" /> <a href="<%=request.getContextPath()%>/approval.do?action=add">增加</a>  &nbsp;</div>
              </td>
              </c:if>
          </tr>
        </table></td>
        
      </tr>
    </table></td>
  </tr>
  <tr>
    <td>
    <form  action="<%=request.getContextPath()%>/approval.do?action=findList" target="rightFrame" method="post" >

    <table width="100%" border="0" cellpadding="0" cellspacing="1" bgcolor="#a8c7ce">
      <tr>
        <td width="15%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">游戏</span></div></td>
        <td width="10%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">描述</span></div></td>
         <td width="10%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">申请人</span></div></td>
         <td width="10%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">申请时间</span></div></td>
         <td width="10%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">状态</span></div></td>
         <td width="10%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">操作</span></div></td>
      </tr>
      <c:forEach items="${list}" var="obj" varStatus="statu">
      <tr>
        <td height="20" bgcolor="#FFFFFF" class="STYLE19"><div align="center"><c:out value="${obj.game}"/></div></td>
 		<td height="20" bgcolor="#FFFFFF" class="STYLE19"><div align="center"><c:out value="${obj.content}"/></div></td>
 		<td height="20" bgcolor="#FFFFFF" class="STYLE19"><div align="center"><c:out value="${obj.proposerName}"/></div></td>
 		<td height="20" bgcolor="#FFFFFF" class="STYLE19"><div align="center"><fmt:formatDate pattern="yyyy-MM-dd" value="${obj.protime}"/></div></td>
 		<td height="20" bgcolor="#FFFFFF" class="STYLE19"><div align="center">
 		<c:choose>
 			<c:when test="${obj.status==1}">申请</c:when>
 			<c:when test="${obj.status==2}">初审</c:when>
 			<c:when test="${obj.status==3}">复核</c:when>
 		</c:choose>
 		</div></td>
 		 <td height="20" bgcolor="#FFFFFF" class="STYLE19"><div align="center">
 		 <c:choose>
 		 	<c:when test="${obj.status==1&&roleId==2}">
 		 		<a href="<%=request.getContextPath()%>/approval.do?action=edit&tag=2&id=${obj.id}">审核</a>
 		 	</c:when>
 		 	<c:when test="${obj.status==1&&roleId==1}">
 		 		<a href="<%=request.getContextPath()%>/approval.do?action=edit&tag=1&id=${obj.id}">修改</a>
 		 	</c:when>
 		 	<c:when test="${obj.status==2&&roleId==3}">
 		 		<a href="<%=request.getContextPath()%>/approval.do?action=edit&tag=3&id=${obj.id}">复审</a>
 		 	</c:when>
 		 	<c:when test="${obj.status==3}">
 		 		<a href="<%=request.getContextPath()%>/approval.do?action=edit&tag=4&id=${obj.id}">查看</a>
 		 	</c:when>
 		 </c:choose>
          
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

</script>
</html>
