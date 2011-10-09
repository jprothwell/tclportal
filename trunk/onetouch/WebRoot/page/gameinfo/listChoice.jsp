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
                <td width="94%" valign="bottom"><span class="STYLE1">游戏信息--游戏基本信息</span></td>
              </tr>
            </table></td>
               <td>
               <div align="right">
           <input type="button" id="checkValue" name="checkValue" value="确定" onclick="setValue()"/>&nbsp;</div>
              </td>
          </tr>
        </table></td>
      </tr>
    </table></td>
  </tr>
  <tr>
    <td>
    <form  action="<%=request.getContextPath()%>/gameinfo.do?action=findList" target="rightFrame" method="post" >
    <table width="100%" border="0" cellpadding="0" cellspacing="1" bgcolor="#a8c7ce">
      <tr>
      <td width="5%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">选择</span></div></td>
       <td width="10%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">游戏</span></div></td>
      <td width="10%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">名称</span></div></td>
        <td width="10%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">类别</span></div></td>
          <td width="10%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">SP</span></div></td>
          <td width="10%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">语言</span></div></td>
          <td width="15%" height="20" bgcolor="d3eaef" class="STYLE6"><div align="center"><span class="STYLE10">添加时间</span></div></td>
      </tr>
      <c:forEach items="${list}" var="obj" varStatus="statu">
      <tr>
      <td height="20" bgcolor="#FFFFFF" class="STYLE19"><div align="center"><input type="checkbox" name="check"  value="${obj.id}" /></div></td>
      <td height="20" bgcolor="#FFFFFF" class="STYLE19"><div align="center"><c:out value="${obj.name}"/></div></td>
       <td height="20" bgcolor="#FFFFFF" class="STYLE19"><div align="center"><c:out value="${obj.gamename}"/></div></td>
        <td height="20" bgcolor="#FFFFFF" class="STYLE19"><div align="center"><c:out value="${obj.kindid}"/></div></td>
        <td height="20" bgcolor="#FFFFFF" class="STYLE19"><div align="center"><c:out value="${obj.spName}"/></div></td>
          <td height="20" bgcolor="#FFFFFF" class="STYLE19"><div align="center"><c:out value="${obj.languageName}"/></div></td>
           <td height="20" bgcolor="#FFFFFF" class="STYLE19"><div align="center"><fmt:formatDate pattern="yyyy-MM-dd" value="${obj.addtime}"/></div></td>
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
      pager.method='findListChoice';
   	</script></div></td>
	</tr>
    </table></td>
  </tr>
</table>
</body>
<script language="JavaScript" type="text/javascript">
	 var oMyObject = window.dialogArguments; //得到父窗口传递过来的对象  
      function setValue() {  
      		  var nid = "";
      		  var objs = document.getElementsByName("check");
      		  var j = 1;
		  		for(var i=0; i<objs.length; i++) {
		  			if(objs[i].checked==true)
		  			{
		  				if(j<2)
		  				{
		  					nid = objs[i].value;
		  					j++;
		  				}else
		  				{
		  					alert("只能选中一个游戏");
		  					return;
		  				}
		  			}//end if	
		  		}//end for
		  		if(nid==""){
		  			alert("请选择游戏");
		  		}
		  	 $.ajax({
		                type : "post",
		                url : "<%=request.getContextPath() %>/gameinfo.do",
		               	data : "action=queryGame&id="+nid,
		                datatype : "text",
		                success : function(data)
		                {  	
		                	 window.dialogArguments.gameid = data.split(",")[0];  
              				 window.dialogArguments.gameName = data.split(",")[1];  
              				 window.close();  
		                },
		                error: function(){
		                	alert("服务器没有返回数据，请重试");
		                }
		            });
             
            }  
</script>
</html>
