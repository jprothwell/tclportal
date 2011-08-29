<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangAction"%>
<html>

<head>
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
	<TITLE><%=LangPage.langPage.getPageTitle("cpblack")%></TITLE>
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

<!---------------添加一组CP到类别------------------------->
		function newSubmit22(){
			if(sel_appid == ""){
				alert("<%=LangAction.langAction.getNoselect_app()%>");
				return false;
			}
			sendG("../AddCPBlack.do?CPId="+sel_appid,newResult22);
			sel_appid = "";
		}
		function newResult22(cartXML){
			var cart = cartXML.getElementsByTagName("result")[0];
			var flowId = cart.getElementsByTagName("info")[0].firstChild.nodeValue;
			cur_flowid = flowId;

			openWFNodeSet();
		}
<!------------------------------------------------------------->

<!---------------从类别中删除产品------------------------>
		function deleteObj1(){
			if(listCurrentKey.get('applist')==""){
				alert("<%=LangAction.langAction.getNoselect_app()%>");
				return;
			}else{
				if(confirm("<%=LangPage.langPage.getDelete_confirm()%>")){
					sendG("../DeleteCPBlack.do?CPId="+listCurrentKey.get('applist'),deleteResult1);
				}
			}
		}
		function deleteResult1(cartXML){
			var cart = cartXML.getElementsByTagName("result")[0];
			var flowId = cart.getElementsByTagName("info")[0].firstChild.nodeValue;
			cur_flowid = flowId;

			openWFNodeSet();
		}
<!------------------------------------------------------------->

<!------------------显示CP选择窗口---------------------------->
		var curIndex2 = "1";
		var bookwindow = new SimpleWindow();
		function showBook(){
			bookwindow.Create('product_window','<%=LangPage.langPage.getWindowsTitle("cp_selectcp")%>',200,300,'');
			openPage2('1');
		}
		function openPage2(index){
			curIndex2 = index;
			sendG("../GetAllCp.do",getAppResult);
		}
		function getAppResult(cartXML){
			var xsl = loadXSL("../xsl/checklist2.xsl");
			bookwindow.Repaint(cartXML.transformNode(xsl));
			bookwindow.Show();
		}

		var sel_appid = "";
		function clickCheck2(id){
			if(document.all["chk2_"+id].checked){
				if(sel_appid.indexOf(";"+id+";")<0){
					if(sel_appid == "") sel_appid = ";"+id+";";
					else sel_appid = sel_appid+id+";";
				}
			}else{
				if(sel_appid.indexOf(";"+id+";")>=0){
					sel_appid = sel_appid.replace(";"+id+";",";");
				}
			}
		}
		function doSelect2(){
			newSubmit22();
			bookwindow.Close();
		}
<!------------------------------------------------------------->

		function showBlackList(){
			listPageURL.put('applist','../GetCPBlack.do?index=#index#');
			openPage('applist','1');
		}

<!------------------页面初始化---------------------->
		
		function init(){

			initList();
			showBlackList();
		}

		function initList(){
			listIndex.put('applist','1');
			listPageURL.put('applist','../GetCPBlack.do?index=#index#');
			listDetailURL.put('applist','../GetCPInfo.do?CPId=#id#');
			listCurrentId.put('applist','');
			listCurrentKey.put('applist','');
			listDetailWidth.put('applist','400');
			listDetailHeight.put('applist','300');
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
		<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("cpblack")%></td>
	</tr>
	</table>

	<table width="100%" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td valign="top">
				
			<!-- 操作按钮 -->
			<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
			<tr>
				<td class="td_buttonbar" valign="middle">
					<a href="#" onclick="showBook();"><img src="../<%=LangPage.langPage.getButton_img_path()%>addcp_001.gif" border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
					<a href="#" onclick="deleteObj1();"><img src="../<%=LangPage.langPage.getButton_img_path()%>deletecp_001.gif" border="0" align="top" vspace="1"/></a>
				</td>
			</tr>
			</table>

			<!-- 产品列表显示区域 -->
			<center>
			<div align="center" id="applist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
			</div>
			</center>
		</td>
	</tr>
	</table>

</body>

</html>
