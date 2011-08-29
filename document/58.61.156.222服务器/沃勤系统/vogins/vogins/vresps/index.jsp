<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<html>

<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<title>Vogins VRE SPS</title>
	<link rel="stylesheet" type="text/css" href="css/jwdf_main.css">
	<SCRIPT language="JavaScript" type="text/javascript" src="<%=LangPage.langPage.getJs_path()%>jwdf_date.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="js/jwdf_util.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="js/jwdf_xml.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="js/jwdf_view.js"></SCRIPT>
	<script language=javascript>
	<!----------------系统菜单操作---------------------->
	var cur_menuid="";
	var cur_parent="";
	var cur_rootmenu = "";
	//显示根菜单
	function showRootMenu(id,child,parent){
		cur_rootmenu=id;
		if(document.all["tr"+id].style.display == ""){
			document.all["tr"+id].style.display = "none";
		}else{
			sendG("GetUserSubMenu.do?MenuId="+id,getListResult1);
		}
	}
	function getListResult1(cartXML)
	{
		var xsl = loadXSL("xsl/jwdf_mainmenu.xsl");
		document.all["td0"+cur_rootmenu].innerHTML = cartXML.transformNode(xsl);
		document.all["tr"+cur_rootmenu].style.display = "";
	}

	//显示子菜单
	function showsubmenu(id,child,link){
		if(cur_menuid!="" && cur_menuid != "00" && cur_parent != "00"){
			document.all["td"+cur_menuid].style.backgroundColor="";
			document.all["td"+cur_menuid].style.color="black";
		}
		if(id != "00"){
			document.all["td"+id].style.backgroundColor="#08246b";
			document.all["td"+id].style.color="white";
		}

		if(child=="1"){
			if(id != "" && id != "00"){
				if (document.all["tr"+id].style.display == ""){
					document.all["img_"+id].src = "images/menu_folder_close.gif";
					document.all["tr"+id].style.display = "none";
				}else{
					sendG("GetUserSubMenu.do?MenuId="+id,getListResult);
				}
			}else{
				sendG("GetUserSubMenu.do?MenuId="+id,getListResult);
			}
		}else{
			window.open(link,"JWDFMainFrame");
		}
		cur_menuid=id;
		cur_parent="";
	}
	function getListResult(cartXML){
		var xsl = loadXSL("xsl/jwdf_mainmenu.xsl");
		document.all["td0"+cur_menuid].innerHTML = cartXML.transformNode(xsl);
		document.all["tr"+cur_menuid].style.display = "";
		if(cur_menuid != "00" && cur_parent != "00"){
			document.all["img_"+cur_menuid].src = "images/menu_folder_open.gif";
		}
	}
<!--------------------------------------------->
		
<!-----------------显示登录信息---------------------------->
		function showLoginInfo(){
			sendG("GetLoginInfo.do",getLoginResult);
		}
		function getLoginResult(cartXML){
			var cart = cartXML.getElementsByTagName("result")[0];
			var username = cart.getElementsByTagName("username")[0].firstChild.nodeValue;
			var logintime = cart.getElementsByTagName("logintime")[0].firstChild.nodeValue;
			document.all["ShowUserName"].innerHTML = "<strong><font color='#FF9900'>"+username+"</font></strong>";
//			document.all["ShowLoginTime"].innerHTML = "登录时间："+logintime;
		}
<!------------------------------------------------------------->


<!-----------------显示快捷方式---------------------------->
		function showShortCut(){
			sendG("ShowShortCut.do",shortcutResult);
		}
		function shortcutResult(cartXML){
			var xsl = loadXSL("xsl/jwdf_shortcut.xsl");
			document.all["shortcut_bar"].innerHTML = cartXML.transformNode(xsl);
		}
<!------------------------------------------------------------->

<!----------------------退出操作------------------------>
		function logout(){
			sendG("logout.do",logoutResult);
		}
		function logoutResult(){
			window.open("login.jsp","_self");
		}
<!------------------------------------------------------------->
		
<!-------------------页面初始化------------------------------->
		function init(){
			showsubmenu("00",1,"");
			showLoginInfo();
			showShortCut();
			document.all['showdate'].innerText = getCurDate()+"    "+getCurTime();
		}
<!------------------------------------------------------------->
	</script>
</head>

<body onload="init();">
<table style="width:100%;height:100%;font-size:12px;" border="0" cellpadding="0" cellspacing="0">
	<tr>
		<td height="144">
	<div class="top_main">
		<div class="top_all">
	  	<div class="top_left">
				<div class="top_left_logo"><img src="images/logo.gif" /></div>
				<div class="top_left_nameTit">-Vogins VRE SPS-</div>
			</div>
			<div class="top_right">
				<div class="top_right_button"><a href="#"><img src="images/index_help_icon.gif" border="0" /></a><a href="#" onclick="logout();return false;"><img src="images/index_quit_icon.gif" border="0" /></a></div><div class="top_right_kjICON" id="shortcut_bar"></div>
			</div>
		</div>
	</div>
  <div class="top_bottom">
  	<div class="top_bottom_left">
	  <div class="top_bottom_left_t">
  		<table style="width:100%;height:80%;font-size:12px;" border="0" cellpadding="0" cellspacing="0">
  		<tr>
  			<td align="right"><strong><font color="#FFFFFF"><%=LangPage.langPage.getIndex_username()%></font></strong></td>
  			<td id="ShowUserName" align="center"><font color="#FF9900"></font></td>
  			<td><strong><font color="#FFFFFF"><%=LangPage.langPage.getIndex_welcome()%></font></strong></td>
  		</tr>
  		<tr>
  			<td colspan="3" align="center">
					[ <a  href='system/changepwd.htm' target='JWDFMainFrame'><%=LangPage.langPage.getIndex_updatepassword()%></a>&nbsp;|&nbsp;<a href="#" onclick="logout();return false;"><%=LangPage.langPage.getIndex_exit()%></a> ]
  			</td>
  		</tr>
  		</table>
    </div>
		</div>
		<div class="top_bottom_right">
		  <div class="top_bottom_right_t">
			  <li><input name="textfield" type="text" class="top_search_in" />
			  <a href="#"><img src="<%=LangPage.langPage.getButton_img_path()%>index_search_t.gif" border="0" /></a></li>
			  <li><img src="images/index_search_icon.gif" width="31" height="34" /></li>
			  <li style="margin-right:50px; color:#FFFFFF;" id="showdate">&nbsp;</li>
			  <li><img src="images/index_search_time.gif" width="26" height="34" /></li>
			</div>
		</div>
	</div>
		</td>
	</tr>
	<tr>
		<td>
			<table style="width:100%;height:100%;font-size:12px;" border="0" cellpadding="0" cellspacing="0">
			<tr>
				<td width="204">
					<table style="width:100%;height:100%;font-size:12px;" border="0" cellpadding="0" cellspacing="0">
						<tr><td style="height:13;background-image:url(images/left_top_bg.gif);"></td></tr>
						<tr>
							<td style="background-image:url(images/left_bg2.gif);background-repeat: repeat-y;">
			<center>
			<div id="menu" class="div_main" style="display:;width:167;">
				<table class="table_menuitem" border="0" cellpadding="0" cellspacing="0">
				<tr style="display:none;" id="tr00">
					<td id="td000">&nbsp;</td>
				</tr>
				</table>
			</div>
			</center>
							</td>
						</tr>
					</table>
				</td>
				<td style="padding-left:10;padding-right:10;">
					<iframe name="JWDFMainFrame" frameborder="0" style="width:100%;height:100%;" scrolling="auto" src="welcome.jsp"></iframe>
				</td>
			</tr>
			</table>
		</td>
	</tr>
	<tr>
		<td height="63"><div class="bottom_left"><img src="images/left_bottom.gif" width="200" height="20" /></div><div class="bottom_top"></div><div class="bottom">
		沃勤科技有限公司<br>
 Vogins Technology (Shanghai) Co.,Ltd. </div></td>
	</tr>
</table>

</body>

</html>
