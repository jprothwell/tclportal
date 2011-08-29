<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangAction"%>
<%@ page import="com.language.langdata.LangDBTable"%>
<%@ page import="com.vogins.sps.db.touse.LogFee"%>
<%@ page import="com.vogins.sps.db.fee.FeeChannel"%>
<%
	LogFee lf = new LogFee();
	FeeChannel fc=new FeeChannel();
%>

<html>
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<TITLE><%=LangPage.langPage.getPageTitle("cp")%></TITLE>
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
		var	cur_cpid="";
		var	cur_mfid="";
		var appFrom="";
		var mfForm="";
		var uaForm="";



<!------------------选择APP-------------------------------------------------------->			
<!------------------显示CP选择窗口---------------------------->


var cpwindow = new SimpleWindow();
function showCP(from){
	appFrom=from;
	cpwindow.Create('cp_window','<%=LangPage.langPage.getWindowsTitle("cp_selectcp")%>',600,400,cpHTML);
	cpwindow.Show();
	listPageURL.put('cplist','../GetCPList.do?index=#index#');
	openPage('cplist','1');
}

function selectCP(){
	if(listCurrentKey.get('cplist') == ""){
		alert("<%=LangAction.langAction.getNoselect_cp()%>");
		return;
	}else{
		listPageURL.put('cplist','../GetAppList.do?CPId='+cur_cpid+'&index=#index#');
		openPage('cplist','1');	
	}
}

var app_window = new SimpleWindow();
function selectAPP(){		
	cur_cpid=listCurrentKey.get('cplist');
	if(cur_cpid != ""){
		app_window.Create('app_window','<%=LangPage.langPage.getWindowsTitle("cp_selectapp")%>',500,300,appHTML);
		app_window.Show();
		listPageURL.put('applist','../GetAppList.do?CPId='+cur_cpid+'&index=#index#');
		openPage('applist','1');				
	}
}
	
function showAppNameValue(){
	if(listCurrentKey.get('applist') == ""){
		alert("<%=LangAction.langAction.getNoselect_cp()%>");
		return;
	}else{
		sendG("../GetAppInfo.do?AppId="+listCurrentKey.get('applist'),getShowApplistResult);
	}
}

function getShowApplistResult(cartXML){
	var cart = cartXML.getElementsByTagName("result")[0];
	var code = cart.getElementsByTagName("code")[0].firstChild.nodeValue;
	var detail = cart.getElementsByTagName("detail")[0];
	var fields = detail.getElementsByTagName("field");
	for(i=0;i<fields.length;i++){
		var name = fields[i].getElementsByTagName("name")[0].firstChild.nodeValue;
		var value = "";
		if(fields[i].getElementsByTagName("value")[0].firstChild != null){
			value = fields[i].getElementsByTagName("value")[0].firstChild.nodeValue;
		}	
		if(appFrom=="1"){		
			if	   (name == "编号") 										NewPartner.AppId.value = value;	
			if	   (name == "<%=lf.getAliasByFiled("AppName")%>") 		NewPartner.AppName.value = value;	
		}	
		else if(appFrom=="2")
		{
			if	   (name == "编号") 										UpdatePartner.AppId.value = value;	
			if	   (name == "<%=lf.getAliasByFiled("AppName")%>") 		UpdatePartner.AppName.value = value;
		}
		else{
				alert("出错啦！！！！！")
			}	
		}
	  cpwindow.Close();
	  app_window.Close();
}
	
<!---------------------------选择省份----------------------------------------------------->
<!------------------显示省份选择窗口---------------------------->
	var provinceFrom = "1";
	var provincewindow = new SimpleWindow();
	function showProvince(from){
		provinceFrom = from;
		if(provinceFrom == "1"){
			sel_provinceid = NewPartner.ProvinceId.value;
			sel_province =   NewPartner.Province.value;
		}else if(provinceFrom == "2"){
			sel_provinceid = UpdatePartner.ProvinceId.value;
			sel_province =   UpdatePartner.Province.value;
		}else{
			sel_province = "";
			sel_provinceid = "";
		}
		showProvinceList();
		provincewindow.Create('province_window','<%=LangPage.langPage.getWindowsTitle("fee_selectprovince")%>',200,225,provinceHTML);
		provincewindow.Show();
	}

	function showProvinceList(){
		sendG("../GetAllProvince.do",getProvinceResult);
	}

	function getProvinceResult(cartXML){
		var xsl = loadXSL("../xsl/checklist.xsl");
		document.all["provincelist"].innerHTML = cartXML.transformNode(xsl);
		selectedCheck();
	}
		
	function selectedCheck(){
		var from = sel_provinceid.indexOf(";");
		var to = 0;
		if(from>=0 && from!=sel_provinceid.length-1) to = sel_provinceid.indexOf(";",from+1);
		while (to > 0){
			var temp = sel_provinceid.substring(from+1, to);
			if(temp != ""){
				document.all["chk_"+temp].checked = true;
			}
			from = to;
			if(from!=sel_provinceid.length-1) to = sel_provinceid.indexOf(";",from+1);
			else to = -1;
		}
	}

	//选择省份
	var sel_province = "";
	var sel_provinceid = "";
	function clickCheck(id,name){
		if(document.all["chk_"+id].checked){
			if(sel_province.indexOf(";"+name+";")<0){
				if(sel_province == "") sel_province = ";"+name+";";
				else sel_province = sel_province+name+";";
			}
			if(sel_provinceid.indexOf(";"+id+";")<0){
				if(sel_provinceid == "") sel_provinceid = ";"+id+";";
				else sel_provinceid = sel_provinceid+id+";";
			}
		}else{
			if(sel_province.indexOf(";"+name+";")>=0){
				sel_province = sel_province.replace(";"+name+";",";");
			}
			if(sel_provinceid.indexOf(";"+id+";")>=0){
				sel_provinceid = sel_provinceid.replace(";"+id+";",";");
			}
		}
	}

	function doSelect(){
		if(provinceFrom == "1"){
			NewPartner.Province.value = sel_province;
			NewPartner.ProvinceId.value = sel_provinceid;
		}
		else if(provinceFrom == "2"){
			UpdatePartner.Province.value = sel_province;
			UpdatePartner.ProvinceId.value = sel_provinceid;
		}
		provincewindow.Close();
	}

<!---------------------------选择厂商----------------------------------------------------->
<!---------------------------显示厂商选择窗口---------------------------->
var mfwindow = new SimpleWindow();
function showMF(form){
	mfForm=form;
	mfwindow.Create('mf_window','<%=LangPage.langPage.getWindowsTitle("mf_selectmf")%>',600,400,mfHTML);
	mfwindow.Show();
	listPageURL.put('mflist','../GetMFList.do?index=#index#');
	openPage('mflist','1');
}

function showMFValue(){
	if(listCurrentKey.get('mflist') == ""){
		alert("<%=LangAction.langAction.getNoselect_cp()%>");
		return;
	}else{
		sendG("../GetMFInfo.do?PartnerId="+listCurrentKey.get('mflist'),getShowMFlistResult);
	}
}

function getShowMFlistResult(cartXML){
	var cart = 	 cartXML.getElementsByTagName("result")[0];
	var code = 	 cart.getElementsByTagName("code")[0].firstChild.nodeValue;
	var detail = cart.getElementsByTagName("detail")[0];
	var fields = detail.getElementsByTagName("field");
	for(i=0;i<fields.length;i++){
		var name = fields[i].getElementsByTagName("name")[0].firstChild.nodeValue;
		var value = "";
		if(fields[i].getElementsByTagName("value")[0].firstChild != null){
			value = fields[i].getElementsByTagName("value")[0].firstChild.nodeValue;
		}	
		if(mfForm=="1"){		
			if	   (name == "编号") 		NewPartner.MFId.value = value;	
			if	   (name == "公司名称") 	NewPartner.MFName.value = value;
			NewPartner.MobileId.value = "";
			NewPartner.MobileName.value = "";
		}	
		else if(mfForm=="2")
		{
			if	   (name == "编号") 		UpdatePartner.MFId.value = value;	
			if	   (name == "公司名称") 	UpdatePartner.MFName.value = value;
			UpdatePartner.MobileId.value = "";
			UpdatePartner.MobileName.value = "";
		}
		else{
			alert("出错啦！！！！！")
		}	
  }
	mfwindow.Close();
}

<!---------------------------显示机型选择窗口---------------------------->
var mfuawindow = new SimpleWindow();
function showUA(form){
	uaForm=form;
	mfuawindow.Create('mfua_window','<%=LangPage.langPage.getWindowsTitle("mf_selectmf")%>',600,400,mf_uaHTML);
	mfuawindow.Show();
	listPageURL.put('mf_ualist','../GetMFList.do?index=#index#');
	openPage('mf_ualist','1');
}

var uawindow = new SimpleWindow();	
function selectUA(){		
	cur_mfid=listCurrentKey.get('mf_ualist');
	//alert("11111----"+cur_mfid);
	if(cur_mfid != ""){
		uawindow.Create('uawindow','<%=LangPage.langPage.getWindowsTitle("")%>',500,300,uaHTML);
		uawindow.Show();
		listPageURL.put('ualist','../GetMobileList.do?PartnerId='+cur_mfid+'&index=#index#');
		openPage('ualist','1');				
	}
}


function selectUaValue(){
	if(listCurrentKey.get('ualist') == ""){
		alert("<%=LangAction.langAction.getNoselect_cp()%>");
		return;
	}else{
		sendG("../GetMobileInfo.do?MobileId="+listCurrentKey.get('ualist'),getShowUAlistResult);
	}
}

function getShowUAlistResult(cartXML){
	var cart = cartXML.getElementsByTagName("result")[0];
	var code = cart.getElementsByTagName("code")[0].firstChild.nodeValue;
	var detail = cart.getElementsByTagName("detail")[0];
	var fields = detail.getElementsByTagName("field");
	for(i=0;i<fields.length;i++){
		var name = fields[i].getElementsByTagName("name")[0].firstChild.nodeValue;
		var value = "";
		if(fields[i].getElementsByTagName("value")[0].firstChild != null){
			value = fields[i].getElementsByTagName("value")[0].firstChild.nodeValue;
		}
		
		if(uaForm=="1")
		{
			if	   (name == "编号") 		NewPartner.MobileId.value = value;	
			if	   (name == "机型名称") 	NewPartner.MobileName.value = value;	
		}
		else if(uaForm=="2")
		{
			if	   (name == "编号") 		UpdatePartner.MobileId.value = value;	
			if	   (name == "机型名称") 	UpdatePartner.MobileName.value = value;	
		}	
		else{
			alert("出错啦！！！！！")
		}			
	}
	showMFValue_2();
	mfuawindow.Close();
	uawindow.Close();
}


function showMFValue_2(){
	if(listCurrentKey.get('mf_ualist') == ""){
		alert("<%=LangAction.langAction.getNoselect_cp()%>");
		return;
	}else{
		sendG("../GetMFInfo.do?PartnerId="+listCurrentKey.get('mf_ualist'),getShowMFlistResult_2);
	}
}

function getShowMFlistResult_2(cartXML){
	var cart = cartXML.getElementsByTagName("result")[0];
	var code = cart.getElementsByTagName("code")[0].firstChild.nodeValue;
	var detail = cart.getElementsByTagName("detail")[0];
	var fields = detail.getElementsByTagName("field");
	for(i=0;i<fields.length;i++){
		var name = fields[i].getElementsByTagName("name")[0].firstChild.nodeValue;
		var value = "";
		if(fields[i].getElementsByTagName("value")[0].firstChild != null){
			value = fields[i].getElementsByTagName("value")[0].firstChild.nodeValue;
		}
		if(uaForm=="1")
		{
			if	   (name == "编号") 		NewPartner.MFId.value = value;	
			if	   (name == "公司名称") 	NewPartner.MFName.value = value;
		}
		else if(uaForm=="2")
		{
			if	   (name == "编号") 		UpdatePartner.MFId.value = value;	
			if	   (name == "公司名称") 	UpdatePartner.MFName.value = value;
		}	
		else{
			alert("出错啦！！！！！")
		}				
	}
	mfwindow.Close();
}



<!--------------------添加---------------------->
		var newwindow = new SimpleWindow();
		function showNew(){
			newwindow.Create('new_window','<%=LangPage.langPage.getWindowsTitle("")%>',250,250,newHTML);
			newwindow.Show();
		}
		function newCancel(){
			newwindow.Close();
		}
		function newSubmit(){
			if(NewPartner.AppName.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=lf.getAliasByFiled("AppName")%>");
				NewPartner.AppName.focus();
				return false;
			}	
			if(NewPartner.Province.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=lf.getAliasByFiled("Province")%>");
				NewPartner.Province.focus();
				return false;
			}
			if(NewPartner.MFName.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=lf.getAliasByFiled("MFName")%>");
				NewPartner.MFName.focus();
				return false;
			}
			//if(NewPartner.MobileName.value == ""){
			//	alert("<%=LangPage.langPage.getPlease_input()%><%=lf.getAliasByFiled("MobileName")%>");
			//	NewPartner.MobileName.focus();
		    //	return false;
			//}
			if(NewPartner.Operator.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=fc.getAliasByFiled("OpCode")%>");
				NewPartner.Operator.focus();
				return false;
			}

		   sendP("../AddFreeConfig.do",getP(NewPartner),newResult);		

			
			function newResult(cartXML){
				var cart = cartXML.getElementsByTagName("result")[0];
			}
			newwindow.Close();
			openPage('freeconfiglist','1');	
		}



<!-------------------删除---------------------->
		function DelFreeConfig(){	
			if(listCurrentKey.get('freeconfiglist')!=""){	
				if(confirm("<%=LangPage.langPage.getDelete_confirm()%>")){
					sendG('../DeleteFreeConfig.do?RecId='+listCurrentKey.get('freeconfiglist'),getResult);
				}
			}
		//	openPage('freeconfiglist','1');	
		}
		function getResult(cartXML){
			var xsl = loadXSL("../xsl/freeconfig.xsl");
	    	document.all["freeconfiglist"].innerHTML = cartXML.transformNode(xsl);
	    	openPage('freeconfiglist','1');	
		}
<!-------------------修改---------------------------------->
var updatewindow = new SimpleWindow();
function showUpdate(){
	if(listCurrentKey.get('freeconfiglist')!=""){
		updatewindow.Create('update_window','<%=LangPage.langPage.getWindowsTitle("")%>',250,250,updateHTML);
		updatewindow.Show();
		sendG("../GetFreeConfiginfo.do?RecId="+listCurrentKey.get('freeconfiglist'),getUpdate);
	}
}
function updateCancel(){
	updatewindow.Close();
}

function getUpdate(cartXML){
	var cart = cartXML.getElementsByTagName("result")[0];
	var code = cart.getElementsByTagName("code")[0].firstChild.nodeValue;
	var detail = cart.getElementsByTagName("detail")[0];
	var fields = detail.getElementsByTagName("field");
	for(i=0;i<fields.length;i++){
		var name = fields[i].getElementsByTagName("name")[0].firstChild.nodeValue;
		var value = "";
		if(fields[i].getElementsByTagName("value")[0].firstChild != null){
			value = fields[i].getElementsByTagName("value")[0].firstChild.nodeValue;
		}
		if(		name == "编号") 				UpdatePartner.RecId.value = value;
		
		else if(name == "产品编号")   		UpdatePartner.AppId.value = value;
		else if(name == "产品名称")   		UpdatePartner.AppName.value = value;
		
		else if(name == "省份编号")   		UpdatePartner.ProvinceId.value = value;	
		else if(name == "省份名称")   		UpdatePartner.Province.value = value;
		
		else if(name == "厂商编号") 			UpdatePartner.MFId.value = value;
		else if(name == "厂商名称") 			UpdatePartner.MFName.value = value;
		
		else if(name == "机型编号") 			UpdatePartner.MobileId.value = value;
		else if(name == "机型名称") 			UpdatePartner.MobileName.value = value;
		
		else if(name == "运营商") 			UpdatePartner.Operator.value = value;
		
		
		
		
	}
}

function updateSubmit(){
	if(UpdatePartner.AppName.value == ""){
		alert("<%=LangPage.langPage.getPlease_input()%><%=lf.getAliasByFiled("AppName")%>");
		NewPartner.AppName.focus();
		return false;
	}	
	if(UpdatePartner.Province.value == ""){
		alert("<%=LangPage.langPage.getPlease_input()%><%=lf.getAliasByFiled("Province")%>");
		NewPartner.Province.focus();
		return false;
	}
	if(UpdatePartner.MFName.value == ""){
		alert("<%=LangPage.langPage.getPlease_input()%><%=lf.getAliasByFiled("MFName")%>");
		NewPartner.MFName.focus();
		return false;
	}
//	if(UpdatePartner.MobileName.value == ""){
//		alert("<%=LangPage.langPage.getPlease_input()%><%=lf.getAliasByFiled("MobileName")%>");
//		NewPartner.MobileName.focus();
//		return false;
//	}
	if(UpdatePartner.Operator.value == ""){
		alert("<%=LangPage.langPage.getPlease_input()%><%=fc.getAliasByFiled("Operator")%>");
		NewPartner.Operator.focus();
		return false;
	}
		
	sendP("../UpdateFreeConfig.do",getP(UpdatePartner),updateResult);

	function updateResult(cartXML){
		var cart = cartXML.getElementsByTagName("result")[0];	
	}
	updatewindow.Close();

	openPage('freeconfiglist','1');	
}


<!---------------------------按CP查询列表---------------------------------->
function searchByCP(){
	listIndex.put('cplist','1');
	var cpName = SearchByCP.value;
	listPageURL.put('cplist','../GetCPListByCP.do?CPName='+encodeURIComponent(cpName)+'&index=#index#');			//用encodeURIComponent(appName)函数转码为UTF-8
	listDetailURL.put('cplist','');
	listCurrentId.put('cplist','');
	listCurrentKey.put('cplist','');
	listDetailWidth.put('cplist','400');
	listDetailHeight.put('cplist','300');
	listListXSL.put('cplist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
	listDblClickEvent.put('cplist',selectAPP);
	openPage('cplist','1');
}	
<!---------------------------按厂商查询列表---------------------------------->
var formid="";
function searchByMF(form){
	formid=form;
	if(formid=='1')
	{
		listIndex.put('mflist','1');
		var mfName_1 = SearchByMF_1.value;
		listPageURL.put('mflist','../GetMFListByMFName.do?MFName='+encodeURIComponent(mfName_1)+'&index=#index#');
		listDetailURL.put('mflist','');
		listCurrentId.put('mflist','');
		listCurrentKey.put('mflist','');
		listDetailWidth.put('mflist','400');
		listDetailHeight.put('mflist','300');
		listListXSL.put('mflist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
		listDblClickEvent.put('mflist',showMFValue);
		openPage('mflist','1');
	}else if(formid=='2')
	{
		listIndex.put('mf_ualist','1');
		var mfName_2 = SearchByMF_2.value;
		listPageURL.put('mf_ualist','../GetMFListByMFName.do?MFName='+encodeURIComponent(mfName_2)+'&index=#index#');
		listDetailURL.put('mf_ualist','');
		listCurrentId.put('mf_ualist','');
		listCurrentKey.put('mf_ualist','');
		listDetailWidth.put('mf_ualist','400');
		listDetailHeight.put('mf_ualist','300');
		listListXSL.put('mf_ualist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
		listDblClickEvent.put('mf_ualist',showMFValue);
		openPage('mf_ualist','1');
	}
	else
	{
		alert("出错啦！！！");
	}						

}



<!------------------------------------------------------------->				
<!------------------页面初始化---------------------->
		var newHTML = "";
		var updateHTML = "";
		var cpHTML = "";
		var appHTML = "";
		var provinceHTML = "";
		var mfHTML="";
		var uaHTML="";
		var mf_uaHTML="";
		
     	function init(){
			newHTML = document.all["tb_new"].innerHTML;
			document.all["tb_new"].innerHTML = "";
			
			updateHTML = document.all["tb_update"].innerHTML;
			document.all["tb_update"].innerHTML = "";
		
			cpHTML = document.all["tb_cp"].innerHTML;
			document.all["tb_cp"].innerHTML = "";
			
			appHTML = document.all["tb_app"].innerHTML;
			document.all["tb_app"].innerHTML = "";

			provinceHTML =document.all["select_province"].innerHTML;
			document.all["select_province"].innerHTML = "";

			mfHTML = document.all["tb_mf"].innerHTML;
			document.all["tb_mf"].innerHTML = "";
			
			

			mf_uaHTML = document.all["tb_mfua"].innerHTML;
			document.all["tb_mfua"].innerHTML = "";
			
			uaHTML = document.all["tb_ua"].innerHTML;
			document.all["tb_ua"].innerHTML = "";

			
			initList();
			openPage('freeconfiglist','1');
		}
		

		function initList(){
			listIndex.put('freeconfiglist','1');
	        listPageURL.put('freeconfiglist','../GetFreeConfiglist.do');
		    listCurrentId.put('freeconfiglist','');
			listCurrentKey.put('freeconfiglist','');
			listDetailWidth.put('freeconfiglist','300');
			listDetailHeight.put('freeconfiglist','320');
			listListXSL.put('freeconfiglist','../<%=LangPage.langPage.getXsl_path()%>freeconfig.xsl');
			listDetailXSL.put('freeconfiglist','../xsl/freeconfig.xsl');


			listIndex.put('cplist','1');
			listDetailURL.put('cplist','');
			listCurrentId.put('cplist','');
			listCurrentKey.put('cplist','');
			listDetailWidth.put('cplist','300');
			listDetailHeight.put('cplist','320');
			listListXSL.put('cplist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('cplist','../xsl/jwdf_sdetail.xsl');
			listDblClickEvent.put('cplist',selectAPP);

			listIndex.put('applist','1');
			listPageURL.put('applist','');
			listCurrentId.put('applist','');
			listCurrentKey.put('applist','');
			listDetailWidth.put('applist','400');
			listDetailHeight.put('applist','380');
			listListXSL.put('applist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('applist','../xsl/jwdf_sdetail.xsl');
			listDblClickEvent.put('applist',showAppNameValue);
			

			listIndex.put('mflist','1');
			listDetailURL.put('mflist','');
			listCurrentId.put('mflist','');
			listCurrentKey.put('mflist','');
			listDetailWidth.put('mflist','300');
			listDetailHeight.put('mflist','320');
			listListXSL.put('mflist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('mflist','');
			listDblClickEvent.put('mflist',showMFValue);


			

			listIndex.put('mf_ualist','1');
			listDetailURL.put('mf_ualist','');
			listCurrentId.put('mf_ualist','');
			listCurrentKey.put('mf_ualist','');
			listDetailWidth.put('mf_ualist','300');
			listDetailHeight.put('mf_ualist','320');
			listListXSL.put('mf_ualist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('mf_ualist','');
			listDblClickEvent.put('mf_ualist',selectUA);

			
			listIndex.put('ualist','1');
			listPageURL.put('ualist','');
			listCurrentId.put('ualist','');
			listCurrentKey.put('ualist','');
			listDetailWidth.put('ualist','400');
			listDetailHeight.put('ualist','380');
			listListXSL.put('ualist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('ualist','../xsl/jwdf_sdetail.xsl');
			listDblClickEvent.put('ualist',selectUaValue);
	}
		
<!------------------------------------------------------------->
	</script>
</head>

<body onload="init();">
	<!-- 页面标题 -->
	<table class="table_pagetitle" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("cp")%></td>
	</tr>
	</table>
	
	<!-- 操作按钮 -->
	<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_buttonbar" valign="middle">
			<a href="#" onclick="showNew();"><img src="../<%=LangPage.langPage.getButton_img_path()%>add_001.gif" border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a href="#" onclick="showUpdate();"><img src="../<%=LangPage.langPage.getButton_img_path()%>update_001.gif" border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a href="#" onclick="DelFreeConfig();"><img src="../<%=LangPage.langPage.getButton_img_path()%>delete_001.gif" border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
		</td>
	</tr>
	</table>

	<!-- 免费产品配置列表显示区域 -->
	<div align="center" id="freeconfiglist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
	</div>

	<!-- cp列表显示区域 -->
	<div id="tb_cp" class="datainfo">
		<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
			<tr>
				<td class="td_buttonbar" valign="middle" style="font-size:9pt;"><%=LangPage.langPage.getSearch("search_bycp")%>

					<input type="text" class="input_edit"  name="SearchByCP">
					<a href="#" onclick="searchByCP();"><img src="../<%=LangPage.langPage.getButton_img_path()%>search_003.gif" border="0" align="top" vspace="1" /></a>
				</td>
			</tr>
		</table>
		<div align="center" id="cplist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		</div>
	</div>

	<!-- App列表显示区域 -->
	<div id="tb_app" class="datainfo">
		<div align="center" id="applist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		</div>
	</div>

	<!-- 厂商列表显示区域 -->
	<div id="tb_mf" class="datainfo">
		<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
			<tr>
				<td class="td_buttonbar" valign="middle" style="font-size:9pt;"><%=LangPage.langPage.getSearch("search_bymf")%>

					<input type="text" class="input_edit"  name="SearchByMF_1">
					<a href="#" onclick="searchByMF('1');"><img src="../<%=LangPage.langPage.getButton_img_path()%>search_003.gif" border="0" align="top" vspace="1" /></a>
				</td>
			</tr>
		</table>
		<div align="center" id="mflist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		</div>
	</div>

	<div id="tb_mfua" class="datainfo">
		<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
			<tr>
				<td class="td_buttonbar" valign="middle" style="font-size:9pt;"><%=LangPage.langPage.getSearch("search_bycp")%>

					<input type="text" class="input_edit"  name="SearchByMF_2">
					<a href="#" onclick="searchByMF('2');"><img src="../<%=LangPage.langPage.getButton_img_path()%>search_003.gif" border="0" align="top" vspace="1" /></a>
				</td>
			</tr>
		</table>
		<div align="center" id="mf_ualist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		</div>
	</div>
	<!-- 机型列表显示区域 -->
	<div id="tb_ua" class="datainfo">
		<div align="center" id="ualist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		</div>
	</div>

<!-- 选择适配省份窗口 -->
<div id="select_province" class="datainfo">
	<div id="provincelist" style="width:100%;height:150; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
	</div>	
	<br>
		<center>
			<a href="#" onclick="doSelect();"><img src="../<%=LangPage.langPage.getButton_img_path()%>select_001.gif"  border="0" align="top" vspace="1" /></a>
		</center>
</div>

	<!-- 添加内容提供商表单 -->
	<div id="tb_new" class="datainfo">
		<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
		<form method="POST" name="NewPartner" class="editform">
		<tr>
			<td class="td_edittitle" width="21%"><%=lf.getAliasByFiled("AppName")%></td>			
			<td class="td_editcontent">
			<input style="width:140;" class="input_edit" type="hidden" name="AppId"    readonly>
			<input style="width:140;" class="input_edit" type="text"  name="AppName"  readonly>
			<a href="#" onclick="showCP('1');"><img src="../<%=LangPage.langPage.getButton_img_path()%>select_001.gif"   border="0" align="top" vspace="1" /></a>
		
		</td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=lf.getAliasByFiled("Province")%></td>
			<td class="td_editcontent">
				<input style="width:140;" class="input_edit" type="hidden" name="ProvinceId" readonly>
				<input style="width:140;" class="input_edit" type="text" name="Province" readonly>
				<a href="#" onclick="showProvince('1');"><img src="../<%=LangPage.langPage.getButton_img_path()%>select_001.gif"   border="0" align="top" vspace="1" /></a>
			</td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=lf.getAliasByFiled("MFName")%></td>
			<td class="td_editcontent">
				<input style="width:140;" class="input_edit" type="hidden" name="MFId" readonly>
				<input style="width:140;" class="input_edit" type="text" name="MFName" readonly>
				<a href="#" onclick="showMF('1');"><img src="../<%=LangPage.langPage.getButton_img_path()%>select_001.gif"   border="0" align="top" vspace="1" /></a>
			</td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=lf.getAliasByFiled("MobileName")%></td>
			<td class="td_editcontent">
				<input style="width:140;" class="input_edit" type="hidden" name="MobileId" readonly>
				<input style="width:140;" class="input_edit" type="text" name="MobileName" readonly>
				<a href="#" onclick="showUA('1');"><img src="../<%=LangPage.langPage.getButton_img_path()%>select_001.gif"   border="0" align="top" vspace="1" /></a>
			</td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=fc.getAliasByFiled("OpCode")%></td>
			<td class="td_editcontent">
				<select name="Operator" value="">
					<option value="0">请选择</option>					
					<option value="1">中国移动</option>
					<option value="2">中国联通</option>
				</select>
			</td>
			
		</tr>
		
		</form>
		<tr>
			<td class="td_editbutton" colspan="2">
				<a href="#" onclick="newSubmit();"><img src="../<%=LangPage.langPage.getButton_img_path()%>submit_001.gif" border="0" align="top" vspace="1" /></a>&nbsp;&nbsp;
				<a href="#" onclick="newCancel();"><img src="../<%=LangPage.langPage.getButton_img_path()%>cancel_001.gif" border="0" align="top" vspace="1" /></a>
			</td>
		</tr>
		</table>
	</div>


	<!-- 修改内容提供商表单 -->
	<div id="tb_update" class="datainfo">
		<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
		<form method="POST" name="UpdatePartner" class="editform">
		<input type="hidden" name="RecId" value="">
		<tr>
			<td class="td_edittitle" width="21%"><%=lf.getAliasByFiled("AppName")%></td>			
			<td class="td_editcontent">
			<input style="width:140;" class="input_edit" type="hidden" name="AppId"    readonly>
			<input style="width:140;" class="input_edit" type="text"   name="AppName"  readonly>
			<a href="#" onclick="showCP('2');"><img src="../<%=LangPage.langPage.getButton_img_path()%>select_001.gif"   border="0" align="top" vspace="1" /></a>
		
		</td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=lf.getAliasByFiled("Province")%></td>
			<td class="td_editcontent">
				<input style="width:140;" class="input_edit" type="hidden" name="ProvinceId" readonly>
				<input style="width:140;" class="input_edit" type="text" name="Province" readonly>
				<a href="#" onclick="showProvince('2');"><img src="../<%=LangPage.langPage.getButton_img_path()%>select_001.gif"   border="0" align="top" vspace="1" /></a>
			</td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=lf.getAliasByFiled("MFName")%></td>
			<td class="td_editcontent">
				<input style="width:140;" class="input_edit" type="hidden" name="MFId" readonly>
				<input style="width:140;" class="input_edit" type="text" name="MFName" readonly>
				<a href="#" onclick="showMF('2');"><img src="../<%=LangPage.langPage.getButton_img_path()%>select_001.gif"   border="0" align="top" vspace="1" /></a>
			</td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=lf.getAliasByFiled("MobileName")%></td>
			<td class="td_editcontent">
				<input style="width:140;" class="input_edit" type="hidden" name="MobileId" readonly>
				<input style="width:140;" class="input_edit" type="text" name="MobileName" readonly>
				<a href="#" onclick="showUA('2');"><img src="../<%=LangPage.langPage.getButton_img_path()%>select_001.gif"   border="0" align="top" vspace="1" /></a>
			</td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=fc.getAliasByFiled("OpCode")%></td>
			<td class="td_editcontent">
				<select name="Operator" value="">
					<option value="0">请选择</option>					
					<option value="1">中国移动</option>
					<option value="2">中国联通</option>
				</select>
			</td>
			
		</tr>
		
		</form>
		<tr>
			<td class="td_editbutton" colspan="2">
				<a href="#" onclick="updateSubmit();"><img src="../<%=LangPage.langPage.getButton_img_path()%>submit_001.gif" border="0" align="top" vspace="1" /></a>&nbsp;&nbsp;
				<a href="#" onclick="updateCancel();"><img src="../<%=LangPage.langPage.getButton_img_path()%>cancel_001.gif" border="0" align="top" vspace="1" /></a>
			</td>
		</tr>
		</table>
	</div>


</body>

</html>
