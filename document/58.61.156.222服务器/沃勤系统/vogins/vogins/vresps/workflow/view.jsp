<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.oa.workflow.db.WFAttachment"%>
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangDBTable"%>
<%@ page import="com.language.langdata.LangAction"%>
<%@ page import="com.oa.workflow.db.WorkFlow"%>
<%@ page import="org.jwdf.util.DateUtil"%>
<%@ page import="org.jwdf.framework.console.Console"%>
<%@ page import="com.jspsmart.upload.*"%>
<%
WorkFlow flow = new WorkFlow();
%>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<title><%=LangPage.langPage.getPageTitle("wf_view")%></title>
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

<!-------------------打开窗口------------------------------->
		var cur_flowid = "";
		function openWF(){
			if(listCurrentKey.get('workflowlist')==''){
				alert("<%=LangAction.langAction.getNo_select_record()%>");
				//alert("请先选择要打开的工作流！");
			}else{
				cur_flowid = listCurrentKey.get('workflowlist');
				sendG("../GetWFView.do?FlowId="+cur_flowid,getWFResult);
			}
		}

		function getWFResult(cartXML){
			var xsl = loadXSL("../xsl/wf_view.xsl");
			document.all["workflow_new"].innerHTML = cartXML.transformNode(xsl);
			workflowwindow.Show();
		}
<!------------------------------------------------------------->
function repealWF(){
	if(listCurrentKey.get('workflowlist')==""){
		alert("<%=LangAction.langAction.getNo_select_record()%>");
		//alert("请首先选择要撤销的工作流！");
		return;
	}else{
		if(confirm("确认要撤销该工作流吗？")){
			sendG("../RepealWorkFlow.do?FlowId="+listCurrentKey.get('workflowlist'),repealWFResult);
		}
	}
}
function repealWFResult(){
	openPage('workflowlist',listIndex.get('workflowlist'));
}
<!----------------------下载附件--------------------------->
		function downAttach(id){
			if(id != ""){
				window.open("../down?AttachId="+id+"&AttachType=2","DownloadFrame");
			}
		}
<!------------------------------------------------------------->
<!------------------页面初始化---------------------->
		var workflowwindow = new SimpleWindow();
		function init(){
			workflowHTML = document.all["workflow_window"].innerHTML;
			document.all["workflow_window"].innerHTML = "";

			workflowwindow.FreeAction();
			workflowwindow.Create('wf_window','<%=LangPage.langPage.getWindowsTitle("workflow_basicinfo")%>',500,400,workflowHTML);

			initList();
			openPage('workflowlist','1');
		}
		
		function initList(){
			listIndex.put('workflowlist','1');
			listPageURL.put('workflowlist','../GetViewWF.do?index=#index#');
			listDetailURL.put('workflowlist','');
			listCurrentId.put('workflowlist','');
			listCurrentKey.put('workflowlist','');
			listDetailWidth.put('workflowlist','400');
			listDetailHeight.put('workflowlist','300');
			listListXSL.put('workflowlist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('workflowlist','');
		}
<!------------------------------------------------------------->
	</script>
</head>

<body onload="init();">
	<!-- 页面标题 -->
	<table class="table_pagetitle" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("wf_view")%></td>
	</tr>
	</table>

	<!-- 操作按钮 -->
	<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_buttonbar" valign="middle">
			<a href="#" onclick="openWF();"><img src="../<%=LangPage.langPage.getButton_img_path()%>open_001.gif"  border="0" align="top" vspace="1" /></a>&nbsp;&nbsp;
			<a href="#" onclick="repealWF();"><img src="../<%=LangPage.langPage.getButton_img_path()%>disfrock_001.gif"  border="0" align="top" vspace="1" /></a>
		</td>
	</tr>
	</table>

	<!-- 信息列表显示区域 -->
	<div align="center" id="workflowlist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;"></div>	

	<div align="center" id="workflow_window" class="datainfo">
	<!-- 信息列表显示区域 -->
	<div align="center" id="workflow_new" style="width:100%; height:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;"></div>	
	</div>

	<div align="center" id="download_div" style="display:none;">
		<iframe src="" name="DownloadFrame"></iframe>
	</div>
</body>
</html>
