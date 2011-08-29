<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangAction"%>
<%@ page import="com.vogins.sps.db.mobile.MFPartner"%>
<%@ page import="com.vogins.sps.db.mobile.Mobile"%>
<%
	MFPartner mf = new MFPartner();
	Mobile mobile = new Mobile();
%>
<html>

<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<TITLE><%=LangPage.langPage.getPageTitle("phonemodel")%></TITLE>
<meta http-equiv="Pragma" content="no-cache">
<link rel="stylesheet" type="text/css" href="../css/jwdf_main.css">
<link rel="stylesheet" type="text/css" href="../css/jwdf_swin.css">
	<SCRIPT language="JavaScript" type="text/javascript" src="../js/jwdf_util.js"></SCRIPT>
		<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_xml.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_view.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_swin.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>sps_workflow.js"></SCRIPT>
<script language=javascript>

<!---------------------------------------------->
function thawMobile(){
	if(listCurrentKey.get('mobilelist')==""){
		alert("<%=LangAction.langAction.getNoselect_mobile()%>");
		return;
	}else{
		if(confirm("确定要解冻该机型吗？")){
			sendG("../ThawMobile.do?UserAgent="+listCurrentKey.get('mobilelist'),thawResult);
		}
	}
}
function thawResult(){
	openPage('mobilelist',1);
}
<!------------------------------------------------------------->
<!------------------页面初始化---------------------->
		function init(){
			initList();
			openPage('mobilelist',1);
		}

		function initList(){
			listIndex.put('mobilelist','1');
			listPageURL.put('mobilelist','../GetFMobileList.do');
			//listDetailURL.put('mobilelist','../GetMobileInfo.do?MobileId=#id#');
			listCurrentId.put('mobilelist','');
			listCurrentKey.put('mobilelist','');
			listListXSL.put('mobilelist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('mobilelist','');
		}
		 
	<!------------------------------------------------>
	</script>
</head>

<body onload="init();">
<!-- 页面标题 -->
<table class="table_pagetitle" border="0" cellspacing="0"
	cellpadding="0" align="center">
	<tr>
		<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("phonemodel")%></td>
	</tr>
</table>

<table width="100%" height="100%" border="0" cellspacing="0"
	cellpadding="0" align="center">
	<tr>
		<!-- 操作按钮 -->
		<table width="90%" border="0" cellspacing="0" cellpadding="0"
			align="center">
			<tr>
				<td class="td_buttonbar" valign="middle">
					<a id="updatemf" href="#" onclick="thawMobile();"><img src="../<%=LangPage.langPage.getButton_img_path()%>uploadmobile_001.gif"   border="0" align="top" vspace="1" /></a>
				</td>
			</tr>
		</table>

		<!-- 机型列表显示区域 -->
		<div align="center" id="mobilelist"
			style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		</div>
		</td>
	</tr>
</table>

</body>
</html>
