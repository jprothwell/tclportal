<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangDBTable"%>
<%@ page import="com.language.langdata.LangAction"%>
<%@ page import="com.oa.workflow.db.WorkFlow"%>
<%@ page import="com.oa.workflow.db.SubWorkFlow"%>
<%@ page import="org.jwdf.util.DateUtil"%>
<%@ page import="org.jwdf.framework.console.Console"%>
<%@ page import="com.jspsmart.upload.*"%>
<%
  SubWorkFlow sub = new SubWorkFlow();
  WorkFlow flow = new WorkFlow();
%>

<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
<title><%=LangPage.langPage.getPageTitle("wf_wait")%></title>
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
	<script language=javascript>
	
		var cur_seqno = "";

<!-------------------打开窗口------------------------------->
		var cur_flowid = "";
		function openWF(){
			if(listCurrentKey.get('workflowlist')==''){
				alert("<%=LangAction.langAction.getNo_select_record()%>");
				//alert("请先选择要打开的工作流！");
			}else{
				cur_flowid = listCurrentKey.get('workflowlist');
				sendG("../GetWFBaseInfo.do?FlowId="+cur_flowid,getWFResult);
			}
		}

		function getWFResult(cartXML){
			var cart = cartXML.getElementsByTagName("result")[0];
			var seqno = cart.getElementsByTagName("seqno")[0].firstChild.nodeValue;
			cur_seqno = seqno;
			if(seqno == "1"){
//				sendG("../GetWFField.do?FlowId="+cur_flowid,getFieldResult);
				sendG("../GetWFView.do?FlowId="+cur_flowid,getWFResult1);
			}else{
				var xsl = loadXSL("../xsl/wf_baseinfo.xsl");
				document.all["workflow_new"].innerHTML = cartXML.transformNode(xsl);
				handlewindow1.Hide();
				workflowwindow.Show();
			}
		}

		function getWFResult1(cartXML){
			var xsl = loadXSL("../xsl/wf_deleteview.xsl");
			document.all["workflow_new"].innerHTML = cartXML.transformNode(xsl);
			workflowwindow.Show();
		}

<!--------------------删除工作流-------------------------->
		function deleteWF(){
			if(listCurrentKey.get('workflowlist')==null){
				alert("<%=LangAction.langAction.getNo_select_record()%>");
				//alert("请首先选择要删除的工作流！");
				return;
			}else{
				if(confirm("<%=LangPage.langPage.getDelete_confirm()%>")){
					sendG("../DeleteWorkFlow.do?FlowId="+listCurrentKey.get('workflowlist'),deleteWFResult);
				}
			}
		}
		function deleteWFResult(cartXML){
			workflowwindow.Close();
			openPage('workflowlist','1');
		}
<!------------------------------------------------------------->
		
<!------------------------------------------------------------->

		function showHandle(){
			handlewindow1.Hide();
			sendG("../GetWFHandle.do?FlowId="+cur_flowid,getHandleResult);
		}

		function getHandleResult(cartXML){
			var xsl = loadXSL("../<%=LangPage.langPage.getXsl_path()%>wf_handle.xsl");
			document.all["workflow_new"].innerHTML = cartXML.transformNode(xsl);
			workflowwindow.Show();
		}

		function doHandle(){
			sendP("../DoWFHandle.do",getP(NewForm),doHandleResult);
		}

		function doHandleResult(){
			workflowwindow.Hide();
			openPage('workflowlist',listIndex.get('workflowlist'));
		}
		
		function doCancel(){
			workflowwindow.Hide();
		}
		
<!-----------------------取消------------------------------->
		function newCancel(){
			workflowwindow.Hide();
		}
<!------------------------------------------------------------->

<!------------------------------------------------------------->
		function doSetHandle(){
			attachmentwindow.Hide();
			listPageURL.put('sublist','../GetSubWFList.do?index=#index#&AppSeqNo='+cur_seqno+'&FlowId='+cur_flowid);
			openPage('sublist','1');
			handlewindow.Show();
		}
		function doSetHandle1(){
			workflowwindow.Hide();
			listPageURL.put('sublist1','../GetHandleSubList.do?index=#index#&AppSeqNo='+cur_seqno+'&FlowId='+cur_flowid);
			openPage('sublist1','1');
			handlewindow1.Show();
		}
<!------------------------------------------------------------->

<!--------------------设置执行人------------------------------>
		var updatewindow = new SimpleWindow();
		var handle_flag = '0';
		var cur_multi = '0';
		function setHandle(){
			handle_flag = '0';
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
		function setHandle1(){
			handle_flag = '1';
			if(listCurrentKey.get('sublist1')==""){
			   alert("<%=LangPage.langPage.getPlease_input()%><%=sub.getAliasByFiled("SubName")%>");
			   //alert("请先指定要设置执行人的步骤！");
				return;
			}else{
				updatewindow.Create('update_window','<%=LangPage.langPage.getWindowsTitle("workflow_sethandle")%>',280,150,updateHTML);
				updatewindow.Show();
				sendG("../GetSubWFInfo.do?SubId="+listCurrentKey.get('sublist1'),getUpdate);
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
			if(handle_flag == '1'){
				openPage('sublist1',listIndex.get('sublist1'));
			}else{
				openPage('sublist',listIndex.get('sublist'));
			}
		}
		function updateSubmit(){
			if(SetHandle.HandleStaff.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=sub.getAliasByFiled("HandleStaff")%>");
				//alert("请输入执行人！");
				SetHandle.HandleStaff.focus();
				return false;
			}
			sendP("../SetHandleStaff.do?AppSeqNo="+cur_seqno,getP(SetHandle),updateResult);
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
					sendG("../DeleteSubFlow.do?AppSeqNo="+cur_seqno+"&SubId="+listCurrentKey.get('sublist'),deleteResult);
				}
			}
		}
		function deleteResult(){
			openPage('sublist',listIndex.get('sublist'));
		}
		function deleteObj1(){
			if(listCurrentKey.get('sublist1')==""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=sub.getAliasByFiled("SubName")%>");
				//alert("请首先选择要删除的步骤！");
				return;
			}else{
				if(confirm("<%=LangPage.langPage.getDelete_confirm()%>")){
					sendG("../DeleteSubFlow.do?AppSeqNo="+cur_seqno+"&SubId="+listCurrentKey.get('sublist1'),deleteResult1);
				}
			}
		}
		function deleteResult1(){
			openPage('sublist1',listIndex.get('sublist1'));
		}
<!------------------------------------------------------------->

<!--------------------跳过步骤----------------------------->
		function jumpNode(){
			if(listCurrentKey.get('sublist')==""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=sub.getAliasByFiled("SubName")%>");;
				return;
			}else{
				if(confirm("确认要跳过选定步骤吗？")){
					sendG("../SetJumpSub.do?AppSeqNo="+cur_seqno+"&SubId="+listCurrentKey.get('sublist'),jumpResult);
				}
			}
		}
		function jumpResult(){
			openPage('sublist',listIndex.get('sublist'));
		}
		function jumpNode1(){
			if(listCurrentKey.get('sublist1')==""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=sub.getAliasByFiled("SubName")%>");
				return;
			}else{
				if(confirm("确认要跳过选定步骤吗？")){
					sendG("../SetJumpSub.do?AppSeqNo="+cur_seqno+"&SubId="+listCurrentKey.get('sublist1'),jumpResult1);
				}
			}
		}
		function jumpResult1(){
			openPage('sublist1',listIndex.get('sublist1'));
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
			showMStaffList();
			mStaffWindow.Create('mstaff_window','<%=LangPage.langPage.getWindowsTitle("workflow_selecthandle")%>',300,250,mstaffHTML);
			mStaffWindow.Show();
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

		var mStaffWindow1 = new SimpleWindow();
		function showMStaff1(){
			mStaffWindow1.Create('staff1_window','<%=LangPage.langPage.getWindowsTitle("workflow_selectweituo")%>',300,250,staffHTML1);
			mStaffWindow1.Show();
			treeSubXSL.put('stafftree1','../xsl/jwdf_subtree.xsl');
			showSub('stafftree1','00','1','00');
		}
<!------------------------------------------------------------->

		var sel_staffs = "";
		function clickCheck(id,name){
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

		function doSelect(){
				if(treeCurrentId.get('stafftree1') == ""){
					alert("请选择员工！");
				}else{
					if(treeCurrentChild.get('stafftree1')=='1'){
						alert("请选择员工！");
					}else{
						TrustForm.TrustStaff.value = treeCurrentId.get('stafftree1');
						mStaffWindow1.Close();
					}
				}
		}
	
<!------------------页面初始化---------------------->
		var workflowwindow = new SimpleWindow();
		var workflowHTML = "";
		var updateHTML = "";
		var handleHTML = "";
		var handleHTML1 = "";
		var mstaffHTML = "";
		var staffHTML1 = "";
		var handlewindow = new SimpleWindow();
		var handlewindow1 = new SimpleWindow();
		function init(){
			updateHTML = document.all["tb_update"].innerHTML;
			document.all["tb_update"].innerHTML = "";

			workflowHTML = document.all["workflow_window"].innerHTML;
			document.all["workflow_window"].innerHTML = "";
			handleHTML = document.all["handle_window"].innerHTML;
			document.all["handle_window"].innerHTML = "";
			handleHTML1 = document.all["handle_window1"].innerHTML;
			document.all["handle_window1"].innerHTML = "";
			mstaffHTML = document.all["tb_multistaff"].innerHTML;
			document.all["tb_multistaff"].innerHTML = "";
			staffHTML1 = document.all["tb_staff1"].innerHTML;
			document.all["tb_staff1"].innerHTML = "";

			workflowwindow.FreeAction();
			workflowwindow.Create('wf_window','<%=LangPage.langPage.getWindowsTitle("workflow_basicinfo")%>',500,400,workflowHTML);
			handlewindow.FreeAction();
			handlewindow.Create('hdl_window','<%=LangPage.langPage.getWindowsTitle("workflow_sub")%>',500,300,handleHTML);
			handlewindow1.FreeAction();
			handlewindow1.Create('hdl_window1','<%=LangPage.langPage.getWindowsTitle("workflow_sub")%>',500,300,handleHTML1);

			initList();
			initTree();
			openPage('workflowlist','1');
		}
		
		function initList(){
			listIndex.put('workflowlist','1');
			listPageURL.put('workflowlist','../GetWaitWF.do?index=#index#');
			listDetailURL.put('workflowlist','');
			listCurrentId.put('workflowlist','');
			listCurrentKey.put('workflowlist','');
			listDetailWidth.put('workflowlist','400');
			listDetailHeight.put('workflowlist','300');
			listListXSL.put('workflowlist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('workflowlist','');

			listIndex.put('sublist','1');
			listPageURL.put('sublist','../GetSubWFList.do?index=#index#&AppSeqNo=1');
			listDetailURL.put('sublist','');
			listCurrentId.put('sublist','');
			listCurrentKey.put('sublist','');
			listDetailWidth.put('sublist','400');
			listDetailHeight.put('sublist','300');
			listListXSL.put('sublist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('sublist','');

			listIndex.put('sublist1','1');
			listPageURL.put('sublist1','../GetHandleSubList.do?index=#index#');
			listDetailURL.put('sublist1','');
			listCurrentId.put('sublist1','');
			listCurrentKey.put('sublist1','');
			listDetailWidth.put('sublist1','400');
			listDetailHeight.put('sublist1','300');
			listListXSL.put('sublist1','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('sublist1','');
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

			treeCurrentId.put('stafftree1','');
			treeCurrentName.put('stafftree1','');
			treeCurrentParent.put('stafftree1','');
			treeCurrentChild.put('stafftree1','');
			treeSubURL.put('stafftree1','../GetStaffList.do?GroupName=#id#');
			treeLeafURL.put('stafftree1','');
			treeSubXSL.put('stafftree1','../xsl/jwdf_subtree.xsl');
			treeLeafXSL.put('stafftree1','');
			treeLeafInfo.put('stafftree1','0');
		}
<!------------------------------------------------------------->
	</script>
</head>

<body onload="init();">
	<!-- 页面标题 -->
	<table class="table_pagetitle" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("wf_wait")%></td>
	</tr>
	</table>

	<!-- 操作按钮 -->
	<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_buttonbar" valign="middle">
			<a href="#" onclick="openWF();"><img src="../<%=LangPage.langPage.getButton_img_path()%>open_001.gif"  border="0" align="top" vspace="1" /></a>&nbsp;&nbsp;
		</td>
	</tr>
	</table>

	<!-- 信息列表显示区域 -->
	<div align="center" id="workflowlist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;"></div>	

	<div align="center" id="workflow_window" class="datainfo">
	<!-- 信息列表显示区域 -->
	<div align="center" id="workflow_new" style="width:100%; height:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;"></div>	
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

	<!--步骤列表显示区域 -->
	<div align="center" id="handle_window1" class="datainfo">
		<table align="center" width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
			<tr>
				<td class="td_buttonbar" valign="middle">
					<input type="button"  value="设置执行人" onclick="setHandle1();" class="button" style="width:80;" onmouseover="this.className='buttonover';"  onmouseout="this.className='button';">&nbsp;&nbsp;
					<input type="button"  value="上一步" onclick="openWF();" class="button" style="width:40;" onmouseover="this.className='buttonover';"  onmouseout="this.className='button';">&nbsp;&nbsp;
					<input type="button"  value="下一步" onclick="showHandle();" class="button" style="width:80;" onmouseover="this.className='buttonover';"  onmouseout="this.className='button';">
				</td>
			</tr>
		</table>
		<div align="center" id="sublist1" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;"></div>	
	</div>

	<!-- 设置执行人表单 -->
	<div align="center" id="tb_update" class="datainfo">
		<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
		<form method="POST" name="SetHandle" class="editform">
		<tr>
			<td class="td_edittitle" width="80"><%sub.getAliasByFiled("SubId");%></td>
			<td class="td_editcontent" width="200"><input class="input_edit" style="width:100%;" readonly type="text" name="SubId"></td>
		</tr>
		<tr>
			<td class="td_edittitle" width="80"><%sub.getAliasByFiled("SubName");%></td>
			<td class="td_editcontent" width="200"><input class="input_edit" style="width:100%;" readonly type="text" name="SubName"></td>
		</tr>
		<tr>
			<td class="td_edittitle" width="80"><%sub.getAliasByFiled("HandleStaff");%></td>
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

	<div id="tb_staff1" class="datainfo">
		<div id="stafftree1" class="div_main" style="display:;">
			<table class="table_menuitem" border="0" cellpadding="0" cellspacing="0">
			<tr style="display:none;" id="stafftree1tr00">
				<td id="stafftree1td000">&nbsp;</td>
			</tr>
			</table>
		</div>
		<center style="padding-top:5;">
		<input type="button"  value="选择" onclick="doSelect();" class="button" onmouseover="this.className='buttonover';"  onmouseout="this.className='button';">
		</center>
	</div>

</body>
</html>
