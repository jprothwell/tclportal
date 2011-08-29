<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangAction"%>
<%@ page import="com.language.langdata.LangDBTable"%>
<%@ page import="com.vogins.sps.db.fee.FeeChannel"%>
<%@ page import="com.vogins.sps.db.fee.SPPartner"%>
<%
	FeeChannel fee = new FeeChannel();
	SPPartner sp = new SPPartner();
%>
<html>

<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<TITLE><%=LangPage.langPage.getPageTitle("prefix_suffix")%></TITLE>
<meta http-equiv="Pragma" content="no-cache">
<link rel="stylesheet" type="text/css" href="../css/jwdf_main.css">
<link rel="stylesheet" type="text/css" href="../css/jwdf_swin.css">
<SCRIPT language="JavaScript" type="text/javascript" src="../js/jwdf_util.js"></SCRIPT>
<SCRIPT language="JavaScript" type="text/javascript" src="../js/jwdf_check.js"></SCRIPT>
<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_xml.js"></SCRIPT>
<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_view.js"></SCRIPT>
<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_swin.js"></SCRIPT>
<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>sps_workflow.js"></SCRIPT>
<script language=javascript>
	

	function showPrefixAndSuffix(){
		sendG('../GetPreAndSuffix.do',getResult);
	}

	function getResult(cartXML){
		//alert(cartXML.xml);
		var xsl = loadXSL("../"+"<%=LangPage.langPage.getXsl_path()%>"+"presuffix.xsl");
		document.all["prefix_suffix"].innerHTML = cartXML.transformNode(xsl);
	}
	
	function updatePreSuffix(){	
		if(event.keyCode == 13){
			sendG('../UpdatePreSuffix.do?PrefixValue='+encodeURIComponent(document.all["prefix"].value)+'&SuffixValue='+encodeURIComponent(document.all["suffix"].value),getUpdateResult);
			showPrefixAndSuffix();
		}	
	}

	function getUpdateResult(cartXML){
		var xsl = loadXSL("../"+"<%=LangPage.langPage.getXsl_path()%>"+"updateresult.xsl");
		document.all["updateresult"].innerHTML = cartXML.transformNode(xsl);
	}

	function cleanResult(){	
		document.all["updateresult"].innerHTML = "";
	}
	
	function init(){
		showPrefixAndSuffix();
	}

</script>
</head>

<body onload="init();">
<!-- 页面标题 -->
<table class="table_pagetitle" border="0" cellspacing="0" cellpadding="0" align="center">
<tr>
	<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("prefix_suffix")%></td>
</tr>
</table>
		
	<!-- 列表显示区域 -->
	<center>
		<div id="prefix_suffix" style="width:900; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;"/>
		</div>
		<table width="200" border="0" cellspacing="0" cellpadding="0" align="center">
			<tr>
				<td align="center" class="td_buttonbar" valign="middle" style="font-size:9pt;" id="updateresult">
				</td>
			</tr>
		</table>
	</center>
</body>
</html>
