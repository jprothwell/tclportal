<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>TCL游戏发布平台</title>
<style type="text/css">
body {
	margin:0;
	padding:0;
	overflow:hidden;
	background:url(images/login_03.gif) repeat-x #152753;
	font-size: 12px;
	color: #adc9d9;
}
#top {
	margin-left:280px;
	clear:both;
	height:318px;
	width:847px;
	background:url(images/login_04.jpg) no-repeat;
}
#center {
	height:84px;
	text-align:center;
}
#center_left {
	margin-left:280px;
	float:left;
	background:url(images/login_06.gif) no-repeat;
	height:84px;
	width:381px;
}
/* IE7 HACK*/
*+html #center_left {
	margin-left:206px !important;
}
/* END HACK*/
#center_middle {
	float:left;
	background:url(images/login_07.gif) no-repeat;
	height:84px;
	width:162px;
}
#center_middle_right {
	float:left;
	background:url(images/login_08.gif) no-repeat;
	height:84px;
	width:26px;
}
#center_submit {
	float:left;
	background:url(images/login_09.gif) no-repeat;
	height:84px;
	width:67px;
}
#center_right {
	float:left;
	background:url(images/login_10.gif) no-repeat;
	height:84px;
	width:211px;
}
#footer {
	margin-left:280px;
	background:url(images/login_11.gif) no-repeat;
	height:206px;
	width:847px;
}
INPUT {
	width:100px;
	height:17px;
	background-color:#87adbf;
	border:solid 1px #153966;
	font-size:12px;
	color:#283439;
}
.chknumber_input {
	width:40px;
}
.user {
	margin: 15px auto;
}
/* IE7 HACK*/
*+html .user {
	margin: 4px auto;
}
/* END HACK*/
.chknumber {
	margin-bottom:3px;
	text-align:left;
	padding-left:3px
}
.button {
	margin: 15px auto;
}
IMG {
	border:none;
	cursor:pointer;
}
FORM {
	margin:0;
	padding:0
}
</style>
</head>
<body>
<div id="top"> </div>
<form id="login" name="login" action="<%=request.getContextPath()%>/login.do?action=login" method="post">
  <div id="center">
    <div id="center_left"></div>
    <div id="center_middle">
      <div class="user">
        <label>用户名：
        <input type="text" name="user" id="user" />
        </label>
      </div>
      <div class="user">
        <label>密　码：
        <input type="password" name="pwd" id="pwd" onkeydown="submitInfo()"/>
        </label>
      </div>
    </div>
    <div id="center_middle_right"></div>
    <div id="center_submit">
      <div class="button"> <img src="images/dl.gif" width="57" height="20" onclick="form_submit()"/> </div>
      <div class="button"> <img src="images/cz.gif" width="57" height="20" onclick="form_reset()"/> </div>
    </div>
    <div id="center_right"></div>
  </div>
</form>
<div id="footer"></div>
</body>
<script type="text/javascript">
	function form_submit(){
		document.getElementById("login").submit();
	}
	function form_reset(){
		document.getElementById("login").reset();
	}
	function submitInfo(){
		e = event.keyCode; 
		if(e==13||e==32){
			document.getElementById("login").submit();
		}
	}
</script>
</html>
