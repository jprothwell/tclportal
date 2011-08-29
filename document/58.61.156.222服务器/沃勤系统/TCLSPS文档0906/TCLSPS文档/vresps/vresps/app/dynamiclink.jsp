<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.oa.workflow.db.WorkFlow"%>
<%@ page import="com.oa.workflow.db.SubWorkFlow"%>
<%@ page import="com.language.langdata.LangAction"%>
<%
  SubWorkFlow sub = new SubWorkFlow();
  WorkFlow flow = new WorkFlow();
%>
<html>

<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<TITLE><%=LangPage.langPage.getPageTitle("appstore")%></TITLE>
	<meta http-equiv="Pragma" content="no-cache">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_main.css">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_swin.css">
	<SCRIPT language="JavaScript" type="text/javascript" src="../js/jwdf_util.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_xml.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_view.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_swin.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>sps_workflow.js"></SCRIPT>
	<script language=javascript>
		var cur_flowid = "";

<!---------------添加一个应用程序版本------------------------->
		function showNew(){
			var newversionwindow = new SimpleWindow();
			newversionwindow.Create('new_version_window','<%=LangPage.langPage.getWindowsTitle("app_addversion")%>',500,250,'');
			newversionwindow.Show();
			newversionwindow.OpenURL('upload/newDlink.jsp');
		}
<!------------------------------------------------------------->

<!-------------------修改应用程序信息-------------------------->
		function showUpdate(){
			if(listCurrentKey.get('applist')==""){
				alert("<%=LangAction.langAction.getNoselect_appversion()%>");
				return;
			}else{
				var updateversionwindow = new SimpleWindow();
				updateversionwindow.Create('update_version_window','<%=LangPage.langPage.getWindowsTitle("app_updateversion")%>',500,250,'');
				updateversionwindow.Show();
				var a = new Date();
				updateversionwindow.OpenURL('upload/updateDlink.jsp?RecId='+listCurrentKey.get('applist')+'&randomid='+a.getTime());
			}
		}
<!------------------------------------------------------------->
		
<!---------------删除版本信息------------------------>
		function deleteObj(){
			if(listCurrentKey.get('applist')==""){
				alert("<%=LangAction.langAction.getNoselect_appversion()%>");
				return;
			}else{
				if(confirm("<%=LangPage.langPage.getDelete_confirm()%>")){
					sendG("../DeleteDl.do?RecId="+listCurrentKey.get('applist'),deleteResult1);
				}
			}
		}
		function deleteResult1(cartXML){
			var cart = cartXML.getElementsByTagName("result")[0];
			openPage('applist','1');	
		}
<!------------------------------------------------------------->
		
		function downloadFile(){
			if(listCurrentKey.get('applist')==""){
				alert(listCurrentKey.get('applist'));
				alert("<%=LangAction.langAction.getNoselect_appversion()%>");
				return;
			}else{
				window.open("../ASDLDownload.do?RecId="+listCurrentKey.get('applist'),"DownloadFrame");
			}
		}


<!------------------页面初始化---------------------->
		function init(){
			initList();
			openPage('applist','1');
		}

		function initList(){
			listIndex.put('applist','1');
			listPageURL.put('applist','../GetDlinkList.do');
			listDetailURL.put('applist','../GetDlinkinfo.do?RecId=#id#');
			listCurrentId.put('applist','');
			listCurrentKey.put('applist','');
			listDetailWidth.put('applist','400');
			listDetailHeight.put('applist','380');
			listListXSL.put('applist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('applist','../xsl/jwdf_sdetail.xsl');
		}
<!------------------------------------------------------------->
	</script>
</head>

<body onload="init();">
	<!-- 页面标题 -->
	<table class="table_pagetitle" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_pagetitle" valign="middle">动态连接库</td>
	</tr>
	</table>

	<!-- 操作按钮 -->
	<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_buttonbar" valign="middle">
			<a href="#" onclick="showNew();"><img src="../<%=LangPage.langPage.getButton_img_path()%>add_001.gif"  border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a href="#" onclick="showUpdate();"><img src="../<%=LangPage.langPage.getButton_img_path()%>update_001.gif"  border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a href="#" onclick="deleteObj();"><img src="../<%=LangPage.langPage.getButton_img_path()%>delete_001.gif"  border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a href="#" onclick="openPage('applist',listIndex.get('applist'));"><img src="../<%=LangPage.langPage.getButton_img_path()%>refresh_001.gif"  border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a href="#" onclick="downloadFile();"><img src="../<%=LangPage.langPage.getButton_img_path()%>download_001.gif"  border="0" align="top" vspace="1"/></a>
		</td>
	</tr>
	</table>

	<!-- 产品列表显示区域 -->
	<div align="center" id="applist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
	</div>
	
	<div align="center" id="download_div" style="display:none;">
		<iframe src="" name="DownloadFrame"></iframe>
	</div>
</body>

</html>
