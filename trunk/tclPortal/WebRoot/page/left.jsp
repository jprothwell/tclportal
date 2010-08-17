<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>TCL游戏管理平台</title>
<script type="text/javascript" src="../js/jquery.js"></script>
<script type="text/javascript" src="../js/chili-1.7.pack.js"></script>
<script type="text/javascript" src="../js/jquery.easing.js"></script>
<script type="text/javascript" src="../js/jquery.dimensions.js"></script>
<script type="text/javascript" src="../js/jquery.accordion.js"></script>
<script language="javascript">
	jQuery().ready(function(){
		jQuery('#navigation').accordion({
			header: '.head',
			navigation1: true, 
			event: 'click',
			fillSpace: true,
			animated: 'bounceslide'
		});
	});
</script>
<style type="text/css">
body {
	margin:0px;
	padding:0px;
	font-size: 12px;
}
#navigation {
	margin:0px;
	padding:0px;
	width:147px;
}
#navigation a.head {
	cursor:pointer;
	background:url(../images/main_34.gif) no-repeat scroll;
	display:block;
	font-weight:bold;
	margin:0px;
	padding:5px 0 5px;
	text-align:center;
	font-size:12px;
	text-decoration:none;
}
#navigation ul {
	border-width:0px;
	margin:0px;
	padding:0px;
	text-indent:0px;
}
#navigation li {
	list-style:none; display:inline;
}
#navigation li li a {
	display:block;
	font-size:12px;
	text-decoration: none;
	text-align:center;
	padding:3px;
}
#navigation li li a:hover {
	background:url(../images/tab_bg.gif) repeat-x;
		border:solid 1px #adb9c2;
}
</style>
</head>
<body>
<div  style="height:100%;">

  <ul id="navigation">
  	
    <li> <a class="head">业务统计</a>
    <ul id="search">
    <c:forEach items="${sessionScope.authres}" var="obj" varStatus="statu">
    <c:choose>
       <c:when test="${obj.value=='/visiteinfo.do'}">
        <li id="5"><a href="<%=request.getContextPath()%>/visiteinfo.do?action=findList" target="rightFrame">访问信息</a></li>
       </c:when>
       
         <c:when test="${obj.value=='/downloadinfo.do'}">
        <li id="5"><a href="<%=request.getContextPath()%>/downloadinfo.do?action=findList" target="rightFrame">下载信息</a></li>
       </c:when>
       
       <c:when test="${obj.value=='/changelog.do'}">
        <li id="5"><a href="<%=request.getContextPath()%>/changelog.do?action=findList" target="rightFrame">业务变更</a></li>
       </c:when>
       
        <c:when test="${obj.value=='/logs.do'}">
        <li id="5"><a href="<%=request.getContextPath()%>/logs.do?action=findList" target="rightFrame">后台日志</a></li>
       </c:when>
       
        <c:when test="${obj.value=='/customer.do'}">
        <li id="5"><a href="<%=request.getContextPath()%>/customer.do?action=findList" target="rightFrame">手机用户</a></li>
       </c:when>
       
        <c:when test="${obj.value=='/comment.do'}">
        <li id="5"><a href="<%=request.getContextPath()%>/comment.do?action=findList" target="rightFrame">用户评论</a></li>
       </c:when>
       
      </c:choose>
      </c:forEach>
      </ul>
    </li>
 
 	<c:if test="${sessionScope.roleid==4||sessionScope.roleid==3}">
    <li> <a class="head">游戏信息</a>
      <ul>
      <c:forEach items="${sessionScope.authres}" var="obj" varStatus="statu">
     <c:choose>
       <c:when test="${obj.value=='/gameinfo.do'}">
       	<li id="11"><a href="<%=request.getContextPath()%>/gameinfo.do?action=findList" target="rightFrame">游戏基本信息</a></li>
       </c:when>
       <c:when test="${obj.value=='/gameresouce.do'}">
        <li id="12"><a href="<%=request.getContextPath()%>/gameresouce.do?action=findList" target="rightFrame">游戏资源信息</a></li>
       </c:when>
      </c:choose>
      </c:forEach>
      </ul>
    </li>
   </c:if>
   <c:if test="${sessionScope.roleid==5||sessionScope.roleid==4||sessionScope.roleid==3}">
    <li> <a class="head">基础数据</a>
      <ul>
       <c:forEach items="${sessionScope.authres}" var="obj" varStatus="statu">
        <c:choose>
             <c:when test="${obj.value=='/mobileinfo.do'}">
      	 <li id="18"><a href="<%=request.getContextPath()%>/mobileinfo.do?action=findList" target="rightFrame">手机信息</a></li>
      	</c:when>
      
        <c:when test="${obj.value=='/country.do'}">
      	 <li id="18"><a href="<%=request.getContextPath()%>/country.do?action=findList" target="rightFrame">国家信息</a></li>
      	</c:when>
      	<c:when test="${obj.value=='/province.do'}">
      	 <li id="19"><a href="<%=request.getContextPath()%>/province.do?action=findList" target="rightFrame">省份信息</a></li>
      	 </c:when>
      	 <c:when test="${obj.value=='/city.do'}">
      	 <li id="20"><a href="<%=request.getContextPath()%>/city.do?action=findList" target="rightFrame">城市信息</a></li>
      	 </c:when>
      	  <c:when test="${obj.value=='/ipinfo.do'}">
         <li id="21"><a href="<%=request.getContextPath()%>/ipinfo.do?action=findList" target="rightFrame">IP信息</a></li>
         </c:when>
         <c:when test="${obj.value=='/spinfo.do'}">
         <li id="22"><a href="<%=request.getContextPath()%>/spinfo.do?action=findList" target="rightFrame">SP信息</a></li>
         </c:when>
          <c:when test="${obj.value=='/telecomoperators.do'}">
         <li id="22"><a href="<%=request.getContextPath()%>/telecomoperators.do?action=findList" target="rightFrame">运营商信息</a></li>
         </c:when>
          <c:when test="${obj.value=='/language.do'}">
         <li id="22"><a href="<%=request.getContextPath()%>/language.do?action=findList" target="rightFrame">语言信息</a></li>
         </c:when>
           <c:when test="${obj.value=='/javapara.do'}">
         <li id="22"><a href="<%=request.getContextPath()%>/javapara.do?action=findList" target="rightFrame">Java参数</a></li>
         </c:when>
         
         <c:when test="${obj.value=='/pageinfo.do'}">
         <li id="22"><a href="<%=request.getContextPath()%>/pageinfo.do?action=findList" target="rightFrame">页面信息</a></li>
         </c:when>
         
          <c:when test="${obj.value=='/locationpage.do'}">
         <li id="22"><a href="<%=request.getContextPath()%>/locationpage.do?action=findList" target="rightFrame">页面位置信息</a></li>
         </c:when>
          </c:choose>
       </c:forEach>
      </ul>
     </li>
     </c:if>
      <c:if test="${sessionScope.roleid==3}">
      <li> <a class="head">用户管理</a>
      	<ul>
      	<c:forEach items="${sessionScope.authres}" var="obj" varStatus="statu">
      	  <c:choose>
      	 <c:when test="${obj.value=='/user.do'}">
      		<li id="6"><a href="<%=request.getContextPath()%>/user.do?action=findList" target="rightFrame">用户信息</a></li>
      	 </c:when>
      	 
      	 <c:when test="${obj.value=='/role.do'}">
      	 <li id="7"><a href="<%=request.getContextPath()%>/role.do?action=findList" target="rightFrame">角色信息</a></li>
      	 </c:when>
      	 
      	 <c:when test="${obj.value=='/resource.do'}">
      	 <li id="8"><a href="<%=request.getContextPath()%>/resource.do?action=findList" target="rightFrame">资源信息</a></li>
      	 </c:when>
      	 </c:choose>
      	 </c:forEach>
      	</ul>
      </li>
      </c:if>
  </ul>
</div>
<input type="hidden"  id="resource" name="resource" value="${sessionScope.roleResources}"/>
</body>

</html>
