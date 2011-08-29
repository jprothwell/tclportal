<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangAction"%>
<html>

<head>
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
	<TITLE><%=LangPage.langPage.getPageTitle("topdldFolder")%></TITLE>
	<meta http-equiv="Pragma" content="no-cache">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_main.css">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_swin.css">
	<SCRIPT language="JavaScript" type="text/javascript" src="../js/jwdf_util.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_xml.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_view.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_swin.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>sps_workflow.js"></SCRIPT>
	
	<script language=javascript>
<!---------------------显示产品类别列表（树型）------------------------>
		var cur_trid="";
		var cur_typecode="";
		
		//显示子类别
		function showsubmenu(id){
			if(cur_trid!="" && cur_trid != "0"){
				document.all["td"+cur_trid].style.backgroundColor="";
				document.all["td"+cur_trid].style.color="black";
			}
			if(id != "" && id != "0"){
				document.all["td"+id].style.backgroundColor="#08246b";
				document.all["td"+id].style.color="white";
			}
			cur_trid=id;
			cur_typecode = id;
			if(id != "" && id != "0") {
				//showBooks();
			}
			if(id != "" && id != "0"){
				if (document.all["tr"+id].style.display == ""){
					document.all["tr"+id].style.display = "none";
					document.all["img_"+id].src = "../images/folderclosed.gif";
				}else{
					sendG("../GetSubRTFolder.do?ParentId="+id,getMenuResult);
				}
			}else{
				sendG("../GetSubRTFolder.do?ParentId=0",getMenuResult);
			}
		}
		function getMenuResult(cartXML){
			var xsl = loadXSL("../xsl/submenulist.xsl");
			if(cur_typecode=="") cur_parentid="0";
			document.all["td0"+cur_typecode].innerHTML = cartXML.transformNode(xsl);
			document.all["tr"+cur_typecode].style.display = "";
			if(cur_typecode != "0")
				document.all["img_"+cur_typecode].src = "../images/folderopen.gif";
		}
<!------------------------------------------------------------->

<!-----------------添加产品类别------------------------------------>
		function showNew(){
			var newversionwindow = new SimpleWindow();
			newversionwindow.Create('new_version_window','<%=LangPage.langPage.getWindowsTitle("app_addmenu")%>',450,110,'');
			newversionwindow.Show();
			newversionwindow.OpenURL('upload/newTopDldDef.jsp?ParentId='+cur_typecode);
		}
<!------------------------------------------------------------->
		
<!---------------------修改产品类别----------------------------->
		function showUpdate(){
			if(cur_typecode==""  || cur_typecode == "0"){
				alert("<%=LangAction.langAction.getNoselect_folder()%>");
				return;
			}else{
				var updateversionwindow = new SimpleWindow();
				updateversionwindow.Create('update_version_window','<%=LangPage.langPage.getWindowsTitle("app_updatemenu")%>',450,110,'');
				updateversionwindow.Show();
				var a = new Date();
				updateversionwindow.OpenURL('upload/updateTopDldDef.jsp?FolderId='+cur_typecode+'&randomid='+a.getTime());
			}
		}
<!------------------------------------------------------------->
		
<!---------------------删除产品类别------------------------->
		function deleteObj(){
			if(cur_typecode=="" || cur_typecode == "0"){
				alert("<%=LangAction.langAction.getNoselect_folder()%>");
				return;
			}else{
				if(confirm("<%=LangPage.langPage.getDelete_confirm()%>")){
					sendG("../DeleteRTFolder.do?FolderId="+cur_typecode,deleteResult);
				}
			}
		}
		function deleteResult(){
			//document.all["applist"].innerHTML = "&nbsp;";
			cur_typecode = "";
			cur_trid = "";
			showsubmenu("0");
		}

<!--------------------------上移/下移产品目录----------------------------------->

		function typeUp(){
			if(cur_typecode==""){
				alert("<%=LangAction.langAction.getNoselect_folder()%>");
				return;
			}else{
				sendG("../UpRTFolder.do?FolderId="+cur_typecode,renovateTypeResult);
			}
		}
		function renovateTypeResult(){
			showsubmenu('0');
		}
		
		function typeDown(){
			if(cur_typecode==""){
				alert("<%=LangAction.langAction.getNoselect_folder()%>");
				return;
			}else{
				sendG("../DownRTFolder.do?FolderId="+cur_typecode,renovateTypeResult);
			}
		}

<!------------------页面初始化---------------------->
		function init(){
			showsubmenu('0');
			initList();
		}

		function initList(){
			listIndex.put('applist','1');
			listPageURL.put('applist','');
			//listDetailURL.put('applist','../GetAppRFolderInfo.do?RecId=#id#');
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
		<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("topdldFolder")%></td>
	</tr>
	</table>
	
	<table width="100%" height="100%" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td width="400" class="td_detailcontent1" style="padding-top:5;font-size:9pt;border-left:0.05cm solid #c3c3c3;" valign="top">
			<!-- 操作按钮 -->
			<table width="100%" border="0" cellspacing="0" cellpadding="0" align="center">
			<tr>
				<td class="td_buttonbar" valign="middle">
					<a href="#" onclick="showNew();"><img src="../<%=LangPage.langPage.getButton_img_path()%>add_001.gif"   border="0" align="top" vspace="1"/></a>
					<a href="#" onclick="showUpdate();"><img src="../<%=LangPage.langPage.getButton_img_path()%>update_001.gif"   border="0" align="top" vspace="1"/></a>
					<a href="#" onclick="deleteObj();"><img src="../<%=LangPage.langPage.getButton_img_path()%>delete_001.gif"   border="0" align="top" vspace="1"/></a>
					<a href="#" onclick="typeUp();"><img src="../<%=LangPage.langPage.getButton_img_path()%>up_001.gif"   border="0" align="top" vspace="1"/></a>
					<a href="#" onclick="typeDown();"><img src="../<%=LangPage.langPage.getButton_img_path()%>down_001.gif"   border="0" align="top" vspace="1"/></a>
					<a href="#" onclick="showsubmenu('0');"><img src="../<%=LangPage.langPage.getButton_img_path()%>refresh_001.gif"  border="0" align="top" vspace="1"/></a>
				</td>
			</tr>
			</table>
			<div id="servlet" class="div_main" style="display:;">
				<table class="table_menuitem" border="0" cellpadding="0" cellspacing="0">
				<tr style="display:none;" id="tr0">
					<td id="td00">&nbsp;</td>
				</tr>
				</table>
			</div>
		</td>
	</tr>
	</table>

	<div align="center" id="download_div" style="display:none;">
		<iframe src="" name="DownloadFrame"></iframe>
	</div>
	
</body>

</html>
