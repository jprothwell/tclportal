/*************************************************************************
 * 设置工作流各步骤执行人及工作流提交的Javascript
 *************************************************************************/	
	var cur_flowid = "";
	var handlewindow = new SimpleWindow();
	var sethandlewindow = new SimpleWindow();

	var handleHTML = "";
	var sethandleHTML = "";
	var mstaffHTML = "";
	
	function initHandleHTML(){
		handleHTML = "<table align='center' width='90%' border='0' cellspacing='0' cellpadding='0' align='center'>";
		handleHTML = handleHTML + "<tr>";
		handleHTML = handleHTML + "<td class='td_buttonbar' valign='middle'>";
		handleHTML = handleHTML + "<input type='button'  value='Select Operator' onclick='setHandle();' class='button' style='width:80;' onmouseover='this.className=\"buttonover\";'  onmouseout='this.className=\"button\";'>&nbsp;&nbsp;";
		handleHTML = handleHTML + "<input type='button'  value='Submit Workflow' onclick='doApp();' class='button' style='width:80;' onmouseover='this.className=\"buttonover\";'  onmouseout='this.className=\"button\";'>";
		handleHTML = handleHTML + "</td>";
		handleHTML = handleHTML + "</tr>";
		handleHTML = handleHTML + "</table>";
		handleHTML = handleHTML + "<div align='center' id='sublist' style='width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;'></div>";	
	}
	
	function initSetHandleHTML(){
		sethandleHTML = "<table class='table_edit' cellpadding='0' cellspacing='1' align='center'>";
		sethandleHTML = sethandleHTML + "<form method='POST' name='SetHandle' class='editform'>";
		sethandleHTML = sethandleHTML + "<tr>";
		sethandleHTML = sethandleHTML + "<td class='td_edittitle' width='80'>Node ID</td>";
		sethandleHTML = sethandleHTML + "<td class='td_editcontent' width='200'><input class='input_edit' style='width:100%;' readonly type='text' name='SubId'></td>";
		sethandleHTML = sethandleHTML + "</tr>";
		sethandleHTML = sethandleHTML + "<tr>";
		sethandleHTML = sethandleHTML + "<td class='td_edittitle' width='80'>Node Name</td>";
		sethandleHTML = sethandleHTML + "<td class='td_editcontent' width='200'><input class='input_edit' style='width:100%;' readonly type='text' name='SubName'></td>";
		sethandleHTML = sethandleHTML + "</tr>";
		sethandleHTML = sethandleHTML + "<tr>";
		sethandleHTML = sethandleHTML + "<td class='td_edittitle' width='80'>Operator</td>";
		sethandleHTML = sethandleHTML + "<td class='td_editcontent' width='200'>";
		sethandleHTML = sethandleHTML + "<input class='input_edit' style='width:80%;' readonly='true' type='text' name='HandleStaff'>";
		sethandleHTML = sethandleHTML + "<input type='button' onclick='showMStaff();' value='...' class='button' onmouseover='this.className=\"buttonover\";'  onmouseout='this.className=\"button\";'>";
		sethandleHTML = sethandleHTML + "</td>";
		sethandleHTML = sethandleHTML + "</tr>";
		sethandleHTML = sethandleHTML + "</form>";
		sethandleHTML = sethandleHTML + "<tr>";
		sethandleHTML = sethandleHTML + "<td class='td_editbutton' colspan='2'>";
		sethandleHTML = sethandleHTML + "<input type='button'  value='Submit' onclick='sethandleSubmit();' class='button' onmouseover='this.className=\"buttonover\";'  onmouseout='this.className=\"button\";'>&nbsp;&nbsp;";
		sethandleHTML = sethandleHTML + "<input type='button'  value='Cancel' onclick='sethandleCancel();' class='button' onmouseover='this.className=\"buttonover\";'  onmouseout='this.className=\"button\";'>";
		sethandleHTML = sethandleHTML + "</td>";
		sethandleHTML = sethandleHTML + "</tr>";
		sethandleHTML = sethandleHTML + "</table>";
	}

	function initMstaffHTML(){
		mstaffHTML = "<div id='stafftree' class='div_main' style='display:;'>";
		mstaffHTML = mstaffHTML + "<table class='table_menuitem' border='0' cellpadding='0' cellspacing='0'>";
		mstaffHTML = mstaffHTML + "<tr style='display:none;' id='stafftreetr00'>";
		mstaffHTML = mstaffHTML + "<td id='stafftreetd000'>&nbsp;</td>";
		mstaffHTML = mstaffHTML + "</tr>";
		mstaffHTML = mstaffHTML + "</table>";
		mstaffHTML = mstaffHTML + "</div>";
		mstaffHTML = mstaffHTML + "<center style='padding-top:5;'>";
		mstaffHTML = mstaffHTML + "<input type='button'  value='Select' onclick='doSelect1();' class='button' onmouseover='this.className=\"buttonover\";'  onmouseout='this.className=\"button\";'>";
		mstaffHTML = mstaffHTML + "</center>";
	}

	function initSubList(){
		listIndex.put('sublist','1');
		listPageURL.put('sublist','../GetSubWFList.do?index=#index#&AppSeqNo=1');
		listDetailURL.put('sublist','');
		listCurrentId.put('sublist','');
		listCurrentKey.put('sublist','');
		listDetailWidth.put('sublist','400');
		listDetailHeight.put('sublist','300');
		listListXSL.put('sublist','../xsl/en/jwdf_list.xsl');
		listDetailXSL.put('sublist','');
	}
	
	function initStaffTree(){
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
	
	function openWFNodeSet(){
		handlewindow.Create('hdl_window','Workflow-Node',350,300,handleHTML);
		handlewindow.Show();
		listPageURL.put('sublist','../GetSubWFList.do?index=#index#&AppSeqNo=1&FlowId='+cur_flowid);
		openPage('sublist','1');
	}

	var cur_multi = '0';
	function setHandle(){
		if(listCurrentKey.get('sublist')==""){
			alert("Please Select Node!");
			return;
		}else{
			sethandlewindow.Create('sethandle_window','Select Operator',280,150,sethandleHTML);
			sethandlewindow.Show();
			sendG("../GetSubWFInfo.do?SubId="+listCurrentKey.get('sublist'),getSetHandle);
		}
	}
	
	function sethandleCancel(){
		sethandlewindow.Close();
	}

	function getSetHandle(cartXML){
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
			if(name == "SubId") SetHandle.SubId.value = value;
			else if(name == "SubName") SetHandle.SubName.value = value;
			else if(name == "HandleStaff") SetHandle.HandleStaff.value = value;
		}
	}
	
	function setHandleResult(){
		sethandlewindow.Close();
		openPage('sublist',listIndex.get('sublist'));
	}
	
	function sethandleSubmit(){
		if(SetHandle.HandleStaff.value == ""){
			alert("Please Select Operator!");
			SetHandle.HandleStaff.focus();
			return false;
		}
		sendP("../SetHandleStaff.do",getP(SetHandle),setHandleResult);
	}

	function doApp(){
		if(confirm("Submit Confirm?")){
			sendG("../SubmitWF.do?FlowId="+cur_flowid,submitAppResult);
		}
	}
	
	function submitAppResult(){
		alert("Submit Success!");
		window.open("../workflow/view.jsp","JWDFMainFrame");
	}

	var mStaffWindow = new SimpleWindow();
	function showMStaff(){
		sel_staffs = "";
		mStaffWindow.Create('mstaff_window','Select Operator',300,250,mstaffHTML);
		mStaffWindow.Show();
		showMStaffList();
	}

	function showMStaffList(){
		initStaffTree();
		if(cur_multi == '1'){
			treeSubXSL.put('stafftree','../xsl/wf_checktree.xsl');
			showSub('stafftree','00','1','00');
		}else{
			treeSubXSL.put('stafftree','../xsl/jwdf_subtree.xsl');
			showSub('stafftree','00','1','00');
		}
	}

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
				alert("Please Select Operator!");
			}else{
				SetHandle.HandleStaff.value = sel_staffs.substring(1);
				mStaffWindow.Close();
				cur_staffs = "";
			}
		}else{
			if(treeCurrentId.get('stafftree') == ""){
				alert("sps_workflow.js");
			}else{
				if(treeCurrentChild.get('stafftree')=='1'){
					alert("sps_workflow.js");
				}else{
					SetHandle.HandleStaff.value = treeCurrentId.get('stafftree');
					mStaffWindow.Close();
					cur_staffs = "";
				}
			}
		}
	}
	
	initHandleHTML();
	initSetHandleHTML();
	initMstaffHTML();
	initSubList();
	initStaffTree();
	