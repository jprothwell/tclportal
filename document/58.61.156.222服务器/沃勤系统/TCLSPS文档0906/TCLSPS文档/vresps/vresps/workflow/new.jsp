<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.oa.workflow.db.WFAttachment"%>
<%@ page import="org.jwdf.util.DateUtil"%>
<%@ page import="org.jwdf.framework.console.Console"%>
<%@ page import="com.jspsmart.upload.*"%>
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangDBTable"%>
<%@ page import="com.oa.workflow.db.WorkFlow"%>
<%@ page import="com.oa.workflow.db.WFType"%>
<%@ page import="com.oa.workflow.db.SubWorkFlow"%>
<%
WorkFlow flow = new WorkFlow();
WFType type = new WFType();
SubWorkFlow sub = new SubWorkFlow();
%>

<html>

<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<TITLE><%=LangPage.langPage.getPageTitle("wf_new")%></TITLE>
	<meta http-equiv="Pragma" content="no-cache">
	<link href="../css/oa_wf.css" rel="stylesheet" type="text/css" />
	<link rel="stylesheet" type="text/css" href="../css/jwdf_main.css">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_swin.css">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_popmenu.css">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_cal.css">
	<SCRIPT language="JavaScript" type="text/javascript" src="../js/jwdf_util.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_xml.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_view.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_swin.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_cal.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>sps_workflow.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../js/jwdf_cal.js"></SCRIPT>
	<script language=javascript>
<!-----------------更新类别选择下拉框------------------------------->
		function showType(){
			sendG("../GetAllType.do",getTypeResult);
		}
		function getTypeResult(cartXML){
			var cart = cartXML.getElementsByTagName("result")[0];
			var list = cart.getElementsByTagName("list")[0];
			var rows = list.getElementsByTagName("row");
			document.all["SelType"].options.length = 0;
			document.all["SelType"].add(document.createElement("OPTION"));
			document.all["SelType"].options[0].text="请选择...";
			document.all["SelType"].options[0].value="0";
			for(var i=0;i<rows.length;i++){
				var key = rows[i].getElementsByTagName("key")[0].firstChild.nodeValue;
				var field = rows[i].getElementsByTagName("field")[0].firstChild.nodeValue;
				document.all["SelType"].add(document.createElement("OPTION"));
				document.all["SelType"].options[i+1].text=field;
				document.all["SelType"].options[i+1].value=key;
			}
		}
<!------------------------------------------------------------->

<!-------------------显示输入窗口------------------------------->
		function showNew(){
			if(document.all["SelType"].value != "0"){
				sendG("../GetTypeField.do?TypeId="+document.all["SelType"].value,getFieldResult);
			}else{
			  alert("<%=LangPage.langPage.getPlease_input()%><%=type.getAliasByFiled("TypeName")%>");
				//alert("请选择工作类别！");
			}
		}

		function getFieldResult(cartXML){
			var xsl = loadXSL("../xsl/wf_shownew.xsl");
			document.all["workflow_new"].innerHTML = cartXML.transformNode(xsl);
			workflowwindow.Show();
		}
<!------------------------------------------------------------->

<!-----------------------添加------------------------------->
		var cur_flowid = "";
		function newSubmit(){
			if(NewForm.Subject.value == ""){
				alert("请输入标题！");
				NewForm.Subject.focus();
				return false;
			}
			if(NewForm.EditType.value == "0"){
				sendP("../AddWorkFlow.do",getP(NewForm),newResult);
			}else if(NewForm.EditType.value == "1"){
				sendP("../UpdateWorkFlow.do?FlowId="+cur_flowid,getP(NewForm),newResult);
			}
		}
		function newResult(cartXML){
			if(NewForm.EditType.value == "0"){
				var cart = cartXML.getElementsByTagName("result")[0];
				var flowId = cart.getElementsByTagName("info")[0].firstChild.nodeValue;
				cur_flowid = flowId;
			}

			doAttach();
		}
		
		function doAttach(){
			workflowwindow.Hide();
			handlewindow.Hide();
			attachmentwindow.Show();
			listPageURL.put('attachlist','../GetWFAttachList.do?FlowId='+cur_flowid);
			openPage('attachlist','1');
		}
<!------------------------------------------------------------->

<!-----------------------取消------------------------------->
		function newCancel(){
			NewForm.reset();
		}
<!------------------------------------------------------------->

<!---------------------修改信息------------------------------->
		function doUpdateInfo(){
			NewForm.EditType.value = "1";
			attachmentwindow.Hide();
			handlewindow.Hide();
			workflowwindow.Show();
		}
<!------------------------------------------------------------->

<!--------------------删除附件-------------------------->
		function deleteAttach(){
			if(listCurrentKey.get('attachlist')==null){
				alert("请首先选择要删除的附件！");
				return;
			}else{
				if(confirm("<%=LangPage.langPage.getDelete_confirm()%>")){
					sendG("../DelWFAttach.do?AttachmentId="+listCurrentKey.get('attachlist'),deleteResult);
				}
			}
		}
		function deleteResult(cartXML){
			openPage('attachlist','1');
		}
<!------------------------------------------------------------->

<!---------------上传附件窗口------------------------->
		function uploadFile(){
			if(cur_flowid != ""){
				var uploadwindow = new SimpleWindow();
				uploadwindow.Create('new_attachment_window','<%=LangPage.langPage.getWindowsTitle("workflow_upfujian")%>',400,150,'');
				uploadwindow.Show();
				uploadwindow.OpenURL('upload/addattach.jsp?FlowId='+cur_flowid);
			}else{
				alert("不能确定要上传附件的工作流！");
			}
		}
<!------------------------------------------------------------->

<!------------------------------------------------------------->
		function doSetHandle(){
			attachmentwindow.Hide();
			listPageURL.put('sublist','../GetSubWFList.do?index=#index#&AppSeqNo=1&FlowId='+cur_flowid);
			openPage('sublist','1');
			handlewindow.Show();
		}
<!------------------------------------------------------------->

<!--------------------设置执行人------------------------------>
		var updatewindow = new SimpleWindow();
		var cur_multi = '0';
		function setHandle(){
			if(listCurrentKey.get('sublist')==""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=sub.getAliasByFiled("SubName")%>");
				//alert("请先指定要设置执行人的步骤！");
				return;
			}else{
				updatewindow.Create('update_window','<%=LangPage.langPage.getWindowsTitle("workflow_sethandle")%>',280,150,updateHTML);
				updatewindow.Show();
				sendG("../GetSubWFInfo.do?SubId="+listCurrentKey.get('sublist'),getUpdate);
			}
		}
		function updateCancel(){
			updatewindow.Close();
		}
		function getUpdate(cartXML){
			var cart = cartXML.getElementsByTagName("result")[0];
			var code = cart.getElementsByTagName("code")[0].firstChild.nodeValue;
			var multi = cart.getElementsByTagName("multi")[0].firstChild.nodeValue;
			cur_multi = multi;
			var detail = cart.getElementsByTagName("detail")[0];
			var fields = detail.getElementsByTagName("field");
			for(i=0;i<fields.length;i++){
				var name = fields[i].getElementsByTagName("name")[0].firstChild.nodeValue;
				var value = "";
				if(fields[i].getElementsByTagName("value")[0].firstChild != null){
					value = fields[i].getElementsByTagName("value")[0].firstChild.nodeValue;
				}
				if(name == "<%=sub.getAliasByFiled("SubId")%>") SetHandle.SubId.value = value;
				else if(name == "<%=sub.getAliasByFiled("SubName")%>") SetHandle.SubName.value = value;
				else if(name == "<%=sub.getAliasByFiled("HandleStaff")%>") SetHandle.HandleStaff.value = value;
			}
		}
		function updateResult(){
			updatewindow.Close();
			openPage('sublist',listIndex.get('sublist'));
		}
		function updateSubmit(){
			if(SetHandle.HandleStaff.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=sub.getAliasByFiled("HandleStaff")%>");
				SetHandle.HandleStaff.focus();
				return false;
			}
			sendP("../SetHandleStaff.do",getP(SetHandle),updateResult);
		}
<!------------------------------------------------------------->

<!--------------------删除步骤----------------------------->
		function deleteObj(){
			if(listCurrentKey.get('sublist')==""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=sub.getAliasByFiled("SubName")%>");
				//alert("请首先选择要删除的步骤！");
				return;
			}else{
				if(confirm("<%=LangPage.langPage.getDelete_confirm()%>")){
					sendG("../DeleteSubFlow.do?AppSeqNo=1&SubId="+listCurrentKey.get('sublist'),deleteResult);
				}
			}
		}
		function deleteResult(){
			openPage('sublist',listIndex.get('sublist'));
		}
<!------------------------------------------------------------->

<!--------------------跳过步骤----------------------------->
		function jumpNode(){
			if(listCurrentKey.get('sublist')==""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=sub.getAliasByFiled("SubName")%>");
				//alert("请首先选择要跳过的步骤！");
				return;
			}else{
				if(confirm("确认要跳过选定步骤吗？")){
					sendG("../SetJumpSub.do?AppSeqNo=1&SubId="+listCurrentKey.get('sublist'),jumpResult);
				}
			}
		}
		function jumpResult(){
			openPage('sublist',listIndex.get('sublist'));
		}
<!------------------------------------------------------------->

<!--------------------提交工作流----------------------------->
		function doApp(){
			if(confirm("确认要提交工作流吗？")){
				sendG("../SubmitWF.do?FlowId="+cur_flowid,submitAppResult);
			}
		}
		function submitAppResult(){
			alert("提交成功！");
			window.open("view.htm","JWDFMainFrame");
		}
<!------------------------------------------------------------->

<!------------------显示员工选择窗口---------------------------->
		var mStaffWindow = new SimpleWindow();
		function showMStaff(){
			sel_staffs = "";
			mStaffWindow.Create('mstaff_window','<%=LangPage.langPage.getWindowsTitle("workflow_selecthandle")%>',300,250,mstaffHTML);
			mStaffWindow.Show();
			showMStaffList();
		}
		function showMStaffList(){
			initTree();
			if(cur_multi == '1'){
				treeSubXSL.put('stafftree','../xsl/wf_checktree.xsl');
				showSub('stafftree','00','1','00');
			}else{
				treeSubXSL.put('stafftree','../xsl/jwdf_subtree.xsl');
				showSub('stafftree','00','1','00');
			}
		}
<!------------------------------------------------------------->

		var sel_staffs = "";
		function clickCheck(id){
			if(document.all["chk_"+id].checked){
				if(sel_staffs.indexOf(";"+id+";")<0){
					if(sel_staffs == "") sel_staffs = ";"+id+";";
					else sel_staffs = sel_staffs+id+";";
				}
			}else{
				if(sel_staffs.indexOf(";"+id+";")>=0){
					sel_staffs = sel_staffs.replace(";"+id+";",";");
				}
			}
		}
		function doSelect1(){
			if(cur_multi == '1'){
				if(sel_staffs == ""){
					alert("请选择员工！");
				}else{
					SetHandle.HandleStaff.value = sel_staffs.substring(1);
					mStaffWindow.Close();
					cur_staffs = "";
				}
			}else{
				if(treeCurrentId.get('stafftree') == ""){
					alert("请选择员工！");
				}else{
					if(treeCurrentChild.get('stafftree')=='1'){
						alert("请选择员工！");
					}else{
						SetHandle.HandleStaff.value = treeCurrentId.get('stafftree');
						mStaffWindow.Close();
						cur_staffs = "";
					}
				}
			}
		}
	
<!------------------页面初始化---------------------->
		var updateHTML = "";
		var workflowHTML = "";
		var attachmentHTML = "";
		var handleHTML = "";
		var workflowwindow = new SimpleWindow();
		var attachmentwindow = new SimpleWindow();
		var handlewindow = new SimpleWindow();
		var mstaffHTML = "";
		function init(){
			updateHTML = document.all["tb_update"].innerHTML;
			document.all["tb_update"].innerHTML = "";
			workflowHTML = document.all["workflow_window"].innerHTML;
			document.all["workflow_window"].innerHTML = "";
			attachmentHTML = document.all["attachment_window"].innerHTML;
			document.all["attachment_window"].innerHTML = "";
			handleHTML = document.all["handle_window"].innerHTML;
			document.all["handle_window"].innerHTML = "";
			mstaffHTML = document.all["tb_multistaff"].innerHTML;
			document.all["tb_multistaff"].innerHTML = "";

			workflowwindow.FreeAction();
			workflowwindow.Create('wf_window','<%=LangPage.langPage.getWindowsTitle("workflow_basicinfo")%>',500,400,workflowHTML);
			attachmentwindow.FreeAction();
			attachmentwindow.Create('attach_window','<%=LangPage.langPage.getWindowsTitle("workflow_fujian")%>',500,300,attachmentHTML);
			handlewindow.FreeAction();
			handlewindow.Create('hdl_window','<%=LangPage.langPage.getWindowsTitle("workflow_sub")%>',500,300,handleHTML);

			initList();
			initTree();
			showType();
		}

		function initList(){
			listIndex.put('attachlist','1');
			listPageURL.put('attachlist','../GetWFAttachList.do');
			listDetailURL.put('attachlist','');
			listCurrentId.put('attachlist','');
			listCurrentKey.put('attachlist','');
			listDetailWidth.put('attachlist','400');
			listDetailHeight.put('attachlist','300');
			listListXSL.put('attachlist','../xsl/jwdf_listnopage.xsl');
			listDetailXSL.put('attachlist','');

			listIndex.put('sublist','1');
			listPageURL.put('sublist','../GetSubWFList.do?index=#index#&AppSeqNo=1');
			listDetailURL.put('sublist','');
			listCurrentId.put('sublist','');
			listCurrentKey.put('sublist','');
			listDetailWidth.put('sublist','400');
			listDetailHeight.put('sublist','300');
			listListXSL.put('sublist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('sublist','');
		}
		
		function initTree(){
			treeCurrentId.put('stafftree','');
			treeCurrentName.put('stafftree','');
			treeCurrentParent.put('stafftree','');
			treeCurrentChild.put('stafftree','');
			treeSubURL.put('stafftree','../GetStaffList.do?GroupName=#id#');
			treeLeafURL.put('stafftree','');
			treeSubXSL.put('stafftree','../xsl/jwdf_subtree.xsl');
			treeLeafXSL.put('stafftree','');
			treeLeafInfo.put('stafftree','0');
		}
		
<!------------------------------------------------------------->
	</script>
</head>

<body onload="init();">
	<table width="100%" border="0" cellspacing="0" cellpadding="0">
	  <tr>
	    <td width="38" background="../images/All_titleBG.gif"><img src="../images/title_icon05.gif" width="38" height="30" /></td>
	    <td align="left" background="../images/All_titleBG.gif" class="title"><%=LangPage.langPage.getPageTitle("wf_new")%></td>
	  </tr>
	</table>
	
	<!-- 操作按钮 -->
	<table align="center" width="100%" border="0" cellspacing="0" cellpadding="0" align="center">
		<tr>
			<td class="td_buttonbar" valign="middle" style="font-size:9pt;">
				&nbsp;&nbsp;选择类别：<select name="SelType"><option value="0">请选择...</option></select>&nbsp;&nbsp;
				<input type="button"  value="确定" onclick="showNew();" class="button" style="width:40;" onmouseover="this.className='buttonover';"  onmouseout="this.className='button';">
			</td>
		</tr>
	</table>

	<div align="center" id="workflow_window" class="datainfo">
	<!-- 信息列表显示区域 -->
	<div align="center" id="workflow_new" style="width:100%; height:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;"></div>	
	</div>

	<!--附件列表显示区域 -->
	<div align="center" id="attachment_window" class="datainfo">
		<table align="center" width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
			<tr>
				<td class="td_buttonbar" valign="middle">
					<input type="button"  value="上传" onclick="uploadFile();" class="button" style="width:40;" onmouseover="this.className='buttonover';"  onmouseout="this.className='button';">&nbsp;&nbsp;
					<input type="button"  value="删除" onclick="deleteAttach();" class="button" style="width:40;" onmouseover="this.className='buttonover';"  onmouseout="this.className='button';">&nbsp;&nbsp;
					<input type="button"  value="刷新" onclick="openPage('attachlist','1');" class="button" style="width:40;" onmouseover="this.className='buttonover';"  onmouseout="this.className='button';">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
					<input type="button"  value="上一步" onclick="doUpdateInfo();" class="button" style="width:40;" onmouseover="this.className='buttonover';"  onmouseout="this.className='button';">&nbsp;&nbsp;
					<input type="button"  value="下一步" onclick="doSetHandle();" class="button" style="width:40;" onmouseover="this.className='buttonover';"  onmouseout="this.className='button';">
				</td>
			</tr>
		</table>
		<div align="center" id="attachlist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;"></div>	
	</div>

	<!--步骤列表显示区域 -->
	<div align="center" id="handle_window" class="datainfo">
		<table align="center" width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
			<tr>
				<td class="td_buttonbar" valign="middle">
					<input type="button"  value="设置执行人" onclick="setHandle();" class="button" style="width:80;" onmouseover="this.className='buttonover';"  onmouseout="this.className='button';">&nbsp;&nbsp;
					<input type="button"  value="删除" onclick="deleteObj();" class="button" style="width:40;" onmouseover="this.className='buttonover';"  onmouseout="this.className='button';">&nbsp;&nbsp;
					<input type="button"  value="跳过" onclick="jumpNode();" class="button" style="width:40;" onmouseover="this.className='buttonover';"  onmouseout="this.className='button';">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
					<input type="button"  value="上一步" onclick="doAttach();" class="button" style="width:40;" onmouseover="this.className='buttonover';"  onmouseout="this.className='button';">&nbsp;&nbsp;
					<input type="button"  value="提交申请" onclick="doApp();" class="button" style="width:80;" onmouseover="this.className='buttonover';"  onmouseout="this.className='button';">
				</td>
			</tr>
		</table>
		<div align="center" id="sublist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;"></div>	
	</div>

	<!-- 设置执行人表单 -->
	<div align="center" id="tb_update">
		<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
		<form method="POST" name="SetHandle" class="editform">
		<tr>
			<td class="td_edittitle" width="80"><%=sub.getAliasByFiled("SubId") %></td>
			<td class="td_editcontent" width="200"><input class="input_edit" style="width:100%;" readonly type="text" name="SubId"></td>
		</tr>
		<tr>
			<td class="td_edittitle" width="80"><%=sub.getAliasByFiled("SubName") %></td>
			<td class="td_editcontent" width="200"><input class="input_edit" style="width:100%;" readonly type="text" name="SubName"></td>
		</tr>
		<tr>
			<td class="td_edittitle" width="80"><%=sub.getAliasByFiled("HandleStaff") %></td>
			<td class="td_editcontent" width="200">
				<input class="input_edit" style="width:80%;" readonly="true" type="text" name="HandleStaff">
				<input type="button" onclick="showMStaff();" value="..." class="button" onmouseover="this.className='buttonover';"  onmouseout="this.className='button';">
			</td>
		</tr>
		</form>
		<tr>
			<td class="td_editbutton" colspan="2">
				<a href="#" onclick="updateSubmit();"><img src="../<%=LangPage.langPage.getButton_img_path()%>ok_001.gif"  border="0" align="top" vspace="1" /></a>&nbsp;&nbsp;
				<a href="#" onclick="updateCancel();"><img src="../<%=LangPage.langPage.getButton_img_path()%>cancel_001.gif"  border="0" align="top" vspace="1" /></a>
			</td>
		</tr>
		</table>
	</div>

	<div id="tb_multistaff" class="datainfo">
		<div id="stafftree" class="div_main" style="display:;">
			<table class="table_menuitem" border="0" cellpadding="0" cellspacing="0">
			<tr style="display:none;" id="stafftreetr00">
				<td id="stafftreetd000">&nbsp;</td>
			</tr>
			</table>
		</div>
		<center style="padding-top:5;">
		<input type="button"  value="选择" onclick="doSelect1();" class="button" onmouseover="this.className='buttonover';"  onmouseout="this.className='button';">
		</center>
	</div>
	
</body>

</html>
