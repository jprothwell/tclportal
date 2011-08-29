<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.oa.workflow.db.WFAttachment"%>
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangDBTable"%>
<%@ page import="com.oa.workflow.db.WorkFlow"%>
<%@ page import="org.jwdf.util.DateUtil"%>
<%@ page import="org.jwdf.framework.console.Console"%>
<%@ page import="com.jspsmart.upload.*"%>

<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<title><%=LangPage.langPage.getPageTitle("wf_trust")%></title>
	<meta http-equiv="Pragma" content="no-cache">
	<link href="../css/oa_wf.css" rel="stylesheet" type="text/css" />
	<link rel="stylesheet" type="text/css" href="../css/jwdf_main.css">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_swin.css">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_popmenu.css">
	<SCRIPT language="JavaScript" type="text/javascript" src="../js/jwdf_util.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_xml.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_view.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_swin.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_cal.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>sps_workflow.js"></SCRIPT>
	<script language=javascript>
		function showNew(){
			window.open("new.htm","JWDFMainFrame");
		}

<!----------------------下载附件--------------------------->
		function downAttach(id){
			if(id != ""){
				window.open("../down?AttachId="+id+"&AttachType=2","DownloadFrame");
			}
		}
<!------------------------------------------------------------->

<!------------------页面初始化---------------------->
		function init(){
			initList();
			openPage('workflowlist','1');
			openPage('workflowlist_f','1');
		}
		
		function initList(){
			listIndex.put('workflowlist','1');
			listPageURL.put('workflowlist','../GetTrustWF.do?index=#index#');
			listDetailURL.put('workflowlist','../GetWFView.do?FlowId=#id#');
			listCurrentId.put('workflowlist','');
			listCurrentKey.put('workflowlist','');
			listDetailWidth.put('workflowlist','400');
			listDetailHeight.put('workflowlist','300');
			listListXSL.put('workflowlist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('workflowlist','../xsl/wf_view.xsl');

			listIndex.put('workflowlist_f','1');
			listPageURL.put('workflowlist_f','../GetTrustWF_F.do?index=#index#');
			listDetailURL.put('workflowlist_f','../GetWFView.do?FlowId=#id#');
			listCurrentId.put('workflowlist_f','');
			listCurrentKey.put('workflowlist_f','');
			listDetailWidth.put('workflowlist_f','500');
			listDetailHeight.put('workflowlist_f','400');
			listListXSL.put('workflowlist_f','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('workflowlist_f','../xsl/wf_view.xsl');
		}
<!------------------------------------------------------------->
	</script>
</head>

<body onload="init();">
<table width="100%" border="0" cellspacing="0" cellpadding="0">
  <tr>
    <td width="38" background="../images/All_titleBG.gif"><img src="../images/title_icon05.gif" width="38" height="30" /></td>
    <td align="left" background="../images/All_titleBG.gif" class="title"><%=LangPage.langPage.getPageTitle("wf_trust")%></td>
  </tr>
</table>
<table width="100%" border="0" cellspacing="0" cellpadding="0">
  <tr>
    <td height="32"><a href="#" onclick="showNew();"><img src="../images/button_newWork.gif" width="75" height="22" border="0" /></a></td>
  </tr>
</table>

	<div align="center" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
			<table width="100%" border="0" cellpadding="0" cellspacing="1" bgcolor="#5B88C1">
			  <tr>
			    <td align="center" bgcolor="#FFFFFF">
			    <table width="100%" border="0" cellpadding="0" cellspacing="1" bgcolor="#FFFFFF">
			      <tr>
			        <td align="left" bgcolor="#E7F1FD" height="25" style="font-size:9pt;"><b>处理中</b></td>
			      </tr>
			    </table>
					</td>
				</tr>
			</table>

			<!-- 信息列表显示区域 -->
			<div align="center" id="workflowlist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;"></div>	
	</div>

	<br>

	<div align="center" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
			<table width="100%" border="0" cellpadding="0" cellspacing="1" bgcolor="#5B88C1">
			  <tr>
			    <td align="center" bgcolor="#FFFFFF">
			    <table width="100%" border="0" cellpadding="0" cellspacing="1" bgcolor="#FFFFFF">
			      <tr>
			        <td align="left" bgcolor="#E7F1FD" height="25" style="font-size:9pt;"><b>已经完成</b></td>
			      </tr>
			    </table>
					</td>
				</tr>
			</table>
			<!-- 信息列表显示区域 -->
			<div align="center" id="workflowlist_f" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;"></div>	
	</div>

	<div align="center" id="download_div" style="display:none;">
		<iframe src="" name="DownloadFrame"></iframe>
	</div>
</body>
</html>
