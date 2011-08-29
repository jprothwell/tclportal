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
<TITLE><%=LangPage.langPage.getPageTitle("FeeChannel")%></TITLE>
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
	

	function showChannelConfigDetail(){
		sendG('../GetFeeSecConfig.do',getCCDResult);
	}

	function getCCDResult(cartXML){
		var xsl = loadXSL("../xsl/feesecconfig.xsl");
		document.all["feesecconfiglist"].innerHTML = cartXML.transformNode(xsl);
	}
	function getCCDResult1(cartXML){	
	}
	
	function clickSecconfig(proId,secconfig)
	{
		//alert("省份ID ："+proId+"-------二次确认打开状态 ："+secconfig);		
		sendG('../UpdateFeSecConfig.do?ProvinceId='+proId+'&Secconfig='+secconfig,getCCDResult1);	
		showChannelConfigDetail();
	}
  
	
	function clickMsecconfig(proId,msecconfig){	
		
		//alert("省份ID ："+proId+"-------模拟二次确认打开状态 ："+msecconfig);		
		sendG('../UpdateFeSecConfig.do?ProvinceId='+proId+'&MSecconfig='+msecconfig,getCCDResult1);	
		showChannelConfigDetail();
	}
	
	function updateOvertime(proId,feeId){	
		if(event.keyCode == 13){
			//alert("省份ID ："+proId+"---------超时时间"+document.all["overtime"+proId].value);	
			sendG('../UpdateFeSecConfig.do?ProvinceId='+proId+'&Overtime='+document.all["overtime"+proId].value,getCCDResult1);
			showChannelConfigDetail();
		}	
	}
	
	function init(){
		showChannelConfigDetail();
	}

</script>
</head>

<body onload="init();">
<!-- 页面标题 -->
<table class="table_pagetitle" border="0" cellspacing="0" cellpadding="0" align="center">
<tr>
	<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("FeeChannel")%>			
	</td>
</tr>
</table>
		
	<!-- 列表显示区域 -->
		<center>
		<div id="feesecconfiglist" style="width:900; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		<input />
		</div>
		</center>
	</div>
</body>
</html>
