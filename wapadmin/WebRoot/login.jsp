<%@page contentType="text/html; charset=utf-8"%>
<%@ page  import="java.awt.* "%>
<%@ page import="java.awt.image.*"%>
<%@ page import="java.util.*"%>
<%@ page import="javax.imageio.*" %>
<html>
<head>
  <meta http-equiv="contentType" content="text/html;charset=utf-8" />
<title>servletlogin</title>
<script language="JavaScript">
function submitForm(theForm)
{
 if(theForm.username.value==""){
           alert("请输入用户名");
           theForm.username.focus();
           return false;
    }else if(theForm.password.value==""){
           alert("请输入密码");
           theForm.password.focus();
           return false;
    }else return true;
}
</script>
</head>
<body bgcolor="#ffffff">
<center>
  <h1>wap后台管理系统</h1>
 <form name="frmlog" method="post" action="checklogin" onsubmit="javascript:return submitForm(this);">
  <br>
  <br>
  <table align="center">
    <tr><td>用户名：&nbsp;<input type="text" name="username" value="" size="18"/></td></tr>
     <tr><td></td></tr>
    <tr><td>
      密&nbsp;&nbsp;&nbsp;码：&nbsp;&nbsp;<input type="password" name="password" value="" size="20"/></td></tr>
      <tr><td></td></tr>
       <tr><td></td></tr>
       <tr><td>
        验证码：&nbsp;<input type="text" name="check" value="" size="18"/>
        </td> </tr>
           <tr><td></td></tr>
           <tr><td></td></tr>
        <tr>
        <td >&nbsp;&nbsp;&nbsp;
          &nbsp;&nbsp;&nbsp;
          &nbsp;&nbsp;&nbsp;
          &nbsp;&nbsp;&nbsp;
          &nbsp;&nbsp;&nbsp;
          <img border=0 src="testCheck.jsp" alt="看不清？请刷新" width="60" height="20" onclick="this.src=this.src+'?'"> <br></td>
         </tr>
        <tr><td></td></tr>
       <tr><td>
         <!-- 验证码实现代码 -->
       </td></tr>
    <tr><td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <input type="submit" name="Submit" value="登录">&nbsp;&nbsp;
        <input type="reset" value="重置">
      </td>
    </tr>
  </table>
  </form>
</center>
</body>
</html>
