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
<!----------------------------------------------------------->
<!-------------------显示SP选择窗口--------------------------->
	var cur_spid = "";
	var spwindow = new SimpleWindow();
	function showCP(){
		spwindow.Create('sp_window','<%=LangPage.langPage.getWindowsTitle("sp_selectsp")%>',600,400,spHTML);
		spwindow.Show();
		listPageURL.put('splist','../GetSpByCountry.do?index=#index#');
		openPage('splist','1');
	}

	function selectSP(){
		if(listCurrentKey.get('splist') == ""){
			alert("<%=LangAction.langAction.getNoselect_sp()%>");
			return;
		}else{
			sendG("../GetFeeInfo.do?SPId="+listCurrentKey.get('splist'),getSPDetail);
		}
	}

	function getSPDetail(cartXML){
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
			if(name == "<%=sp.getAliasByFiled("SPId")%>"){
				cur_spid = value;
			}else if(name == "<%=sp.getAliasByFiled("SPName")%>"){
				document.all["apptitle"].innerHTML = "<%=sp.getAliasByFiled("SPName")%> [" + value + "]";
				showButton();
			}
		}
		spwindow.Close();
		if(cur_spid != ""){
			listPageURL.put('chargecodelist','../GetFeeCannelBySP.do?SPId='+cur_spid+'&index=#index#');
			openPage('chargecodelist','1');
		}
	}
	
	function searchBySP(){
		listPageURL.put('splist','../GetSPListBySP.do?SPName='+encodeURIComponent(SearchBySP.value)+'&index=#index#');	//用encodeURIComponent(appName)函数转码为UTF-8
		openPage('splist','1');
	}

	function showButton(){
		if(cur_spid==""){
			shownew.style.visibility = "hidden";
			showupdate.style.visibility = "hidden";
			showdelete.style.visibility = "hidden";
			showchannel.style.visibility = "hidden";
		}else{
			shownew.style.visibility = "visible";
			showupdate.style.visibility = "visible";
			showdelete.style.visibility = "visible";
			showchannel.style.visibility = "visible";
		}
	}
<!------------------------------------------------------------->

<!---------------添加一个计费代码------------------------------->
	var newwindow = new SimpleWindow();
	var reg=/[\u4E00-\u9FA5]/g; //汉字判断
	var zimu =/[a-zA-Z]/ ;  //字母判断
	var shuzi =/^[0-9]*[1-9][0-9]*$/; //数字
	var cur_flowid = "";
	function showNew(){
		if(cur_spid=="" || cur_spid=="0"){
			alert("<%=LangAction.langAction.getNoselect_sp()%>");
			return false;
		}    
		newwindow.Create('new_window','<%=LangPage.langPage.getWindowsTitle("fee_addfeechannel")%>',350,405,newHTML);
		newwindow.Show();
		NewChargeCode.PartnerId.value=cur_spid;
	}

	function newCancel(){
		newwindow.Close();
	}
	
	function newSubmit(){
		if(NewChargeCode.FeeName.value == ""){
			alert("<%=LangPage.langPage.getPlease_input()%><%=fee.getAliasByFiled("FeeName")%>");
			NewChargeCode.FeeName.focus();
			return false;
		}
		if(!shuzi.test(NewChargeCode.Price.value)){
			alert("<%=LangPage.langPage.getPlease_input()%><%=fee.getAliasByFiled("Price")%>");
			NewChargeCode.Price.focus();
			return false;
		}
		if(NewChargeCode.Uri.value==""){
			alert("<%=LangPage.langPage.getPlease_input()%><%=fee.getAliasByFiled("URI")%>");
			return false;
		}
		if(NewChargeCode.Param.value==""){
			alert("<%=LangPage.langPage.getPlease_input()%><%=fee.getAliasByFiled("Param")%>");
			return false;
		}
		sendP("../AddChargeCode.do",getP(NewChargeCode),newResult);
	}
	
	function newResult(cartXML){
		var cart = cartXML.getElementsByTagName("result")[0];
		var flowId = cart.getElementsByTagName("info")[0].firstChild.nodeValue;
		cur_flowid = flowId;

		newwindow.Close();
		openWFNodeSet();
	}
<!-------------------------------------------------------->

<!-------------------修改计费代码-------------------------->
	var updatewindow = new SimpleWindow();
	function showUpdate(){
		if(listCurrentKey.get('chargecodelist')==""){
			alert("<%=LangAction.langAction.getNoselect_feechannel()%>");
			return;
		}else{
			updatewindow.Create('update_window','<%=LangPage.langPage.getWindowsTitle("fee_updatefeechannel")%>',350,405,updateHTML);
			updatewindow.Show();
			sendG("../GetChargeCodeInfo.do?ChargeCodeId="+listCurrentKey.get('chargecodelist'),getUpdate);
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
			if(name == "<%=fee.getAliasByFiled("FeeId")%>") UpdateChargeCode.ChargeCodeId.value = value;
			else if(name == "<%=fee.getAliasByFiled("CountryCode")%>") UpdateChargeCode.CountryCode.value = value;
			else if(name == "<%=fee.getAliasByFiled("FeeName")%>") UpdateChargeCode.FeeName.value = value;
			else if(name == "<%=fee.getAliasByFiled("OpCode")%>") UpdateChargeCode.OpCode.value = value;
			else if(name == "<%=fee.getAliasByFiled("CommandType")%>") UpdateChargeCode.CommandType.value = value;
			else if(name == "<%=fee.getAliasByFiled("URI")%>") UpdateChargeCode.Uri.value = value;
			else if(name == "<%=fee.getAliasByFiled("Param")%>") UpdateChargeCode.Param.value = value;
			else if(name == "<%=fee.getAliasByFiled("Price")%>") UpdateChargeCode.Price.value = value;
			else if(name == "<%=fee.getAliasByFiled("ValidPrice")%>") UpdateChargeCode.ValidPrice.value = value;
			else if(name == "<%=fee.getAliasByFiled("Remark")%>") UpdateChargeCode.Desc.value = value;
			else if(name == "省份列表") UpdateChargeCode.Province.value = value;
			else if(name == "<%=fee.getAliasByFiled("SpName")%>") UpdateChargeCode.SpName.value = value;
			else if(name == "<%=fee.getAliasByFiled("BusinessName")%>") UpdateChargeCode.BusinessName.value = value;
			else if(name == "<%=fee.getAliasByFiled("SpTel")%>") UpdateChargeCode.SpTel.value = value;			
			else if(name == "<%=fee.getAliasByFiled("LevelFlag")%>") UpdateChargeCode.LevelFlag.value = value;
			else if(name == "<%=fee.getAliasByFiled("Province")%>") UpdateChargeCode.ProvinceId.value = value;
			else if(name == "<%=fee.getAliasByFiled("Open2x")%>") UpdateChargeCode.Open2x.value = value;
		}
	}

	function updateSubmit(){
		if(UpdateChargeCode.FeeName.value == ""){
			alert("<%=LangPage.langPage.getPlease_input()%><%=fee.getAliasByFiled("FeeName")%>");
			UpdateChargeCode.FeeName.focus();
			return false;
		}

		if(!shuzi.test(UpdateChargeCode.Price.value)){
			alert("<%=LangPage.langPage.getPlease_input()%><%=fee.getAliasByFiled("Price")%>");
			UpdateChargeCode.Price.focus();
			return false;
		}
		
		if(UpdateChargeCode.Uri.value==""){
			alert("<%=LangPage.langPage.getPlease_input()%><%=fee.getAliasByFiled("URI")%>");
			return false;
		}
		
		if(UpdateChargeCode.Param.value==""){
			alert("<%=LangPage.langPage.getPlease_input()%><%=fee.getAliasByFiled("Param")%>");
			return false;
		}
			
		sendP("../UpdateChargeCode.do",getP(UpdateChargeCode),updateResult);
	}
	
	function updateResult(cartXML){
		var cart = cartXML.getElementsByTagName("result")[0];
		var flowId = cart.getElementsByTagName("info")[0].firstChild.nodeValue;
		cur_flowid = flowId;

		updatewindow.Close();
		openWFNodeSet();
	}
<!------------------------------------------------------------->
		
<!---------------删除计费代码----------------------------------->
	function deleteObj(){
		if(listCurrentKey.get('chargecodelist')==""){
			alert("<%=LangAction.langAction.getNoselect_feechannel()%>");
			return;
		}else{
			if(confirm("<%=LangPage.langPage.getDelete_confirm()%>")){
				sendG("../DeleteChargeCode.do?ChargeCodeId="+listCurrentKey.get('chargecodelist'),deleteResult);
				}
		}
	}

	function deleteResult(cartXML){
		var cart = cartXML.getElementsByTagName("result")[0];
		var flowId = cart.getElementsByTagName("info")[0].firstChild.nodeValue;
		cur_flowid = flowId;

		handlewindow.Create('hdl_window','<%=LangPage.langPage.getWindowsTitle("workflow_sub")%>',350,300,handleHTML);
		handlewindow.Show();
		listPageURL.put('sublist','../GetSubWFList.do?index=#index#&AppSeqNo=1&FlowId='+cur_flowid);
		openPage('sublist','1');
	}
<!----------------------------------------------------------------->
<!------------------------计费通道配置------------------------------>
	var versionwindow = new SimpleWindow();
	function showChannel(){
		if(listCurrentKey.get('chargecodelist')=="")
		{
			alert("<%=LangAction.langAction.getNoselect_feechannel()%>");
			return;
		}else{
			 	versionwindow.Create('appversion_window','<%=LangPage.langPage.getWindowsTitle("fee_selectchannel")%>',550,400,versionHTML);
				versionwindow.Show();
				sendG("../GetChargeCodeInfo.do?ChargeCodeId="+listCurrentKey.get('chargecodelist'),getShowChannelResult);
			 }
}

	function getShowChannelResult(cartXML){
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
			if	   (name == "<%=fee.getAliasByFiled("FeeName")%>") 		document.all["td_FeeName"].innerHTML = value;
			else if(name == "<%=fee.getAliasByFiled("Price")%>")   		document.all["td_Price"].innerHTML = value;
			else if(name == "<%=fee.getAliasByFiled("CountryCode")%>")	document.all["td_CountryCode"].innerHTML = value;
			else if(name == "<%=fee.getAliasByFiled("BusinessName")%>") document.all["td_BusinessName"].innerHTML = value;
		}
	    showChannelConfigDetail();
	}
	
	function showChannelConfigDetail(){
		sendG('../GetFeeConfiginfo.do?FeeId='+listCurrentKey.get('chargecodelist'),getCCDResult);
	}

	function getCCDResult(cartXML){
		var xsl = loadXSL("../xsl/feechannelconfig.xsl");
		document.all["feechannelconfiglist"].innerHTML = cartXML.transformNode(xsl);
	}	
	function getCCDResult1(cartXML){
	}

	<!------------------------修改计费通道配置===省份开通标致------------>
	function clickOpenProvinceMarks(proId,feeId,openId){	
					
		// alert("省份ID ："+proId+"-------计费通道ID ："+feeId+"---------开通标致"+openId);		
		sendG('../UpdateFeeConfig.do?ProvinceId='+proId+'&FeeId='+feeId+'&OpenId='+openId,getCCDResult1);	
		showChannelConfigDetail();
	}
	
	<!------------------------修改计费通道配置===二次确认开拓标志------------>
	function clickSecConfir(proId,feeId,secId){	
	
		// alert("省份ID ："+proId+"-------计费通道ID ："+feeId+"---------二次确认"+secId);		
		sendG('../UpdateFeeConfig.do?ProvinceId='+proId+'&FeeId='+feeId+'&SecId='+secId,getCCDResult1);	
		showChannelConfigDetail();
	}
	<!------------------------修改计费通道配置===X.x开通标致------------>
	function clickOpen2x(proId,feeId,open2xId){	
	
		//  alert("省份ID ："+proId+"-------计费通道ID ："+feeId+"---------X.x开通标致"+open2xId);		
		sendG('../UpdateFeeConfig.do?ProvinceId='+proId+'&FeeId='+feeId+'&Open2xId='+open2xId,getCCDResult1);
		showChannelConfigDetail();	
	}
	<!------------------------修改计费通道配置===日上限------------>
	function updateDayTop(proId,feeId){	
		if(event.keyCode == 13){
		//	alert("省份ID ："+proId+"-------计费通道ID ："+feeId+"---------日上限"+document.all["daytop"+proId].value);	
			sendG('../UpdateFeeConfig.do?ProvinceId='+proId+'&FeeId='+feeId+'&DayTop='+document.all["daytop"+proId].value,getCCDResult1);
			showChannelConfigDetail();	
			//alert("1");
		}	
	}
	function updateMonthTop(proId,feeId){	
		if(event.keyCode == 13){
		//	alert("省份ID ："+proId+"-------计费通道ID ："+feeId+"----------月上限"+document.all["monthtop"+proId].value);		
			sendG('../UpdateFeeConfig.do?ProvinceId='+proId+'&FeeId='+feeId+'&MonthTop='+document.all["monthtop"+proId].value,getCCDResult1);
			showChannelConfigDetail();	
		}	
	}
	
<!------------------显示收费渠道选择窗口---------------------------->
	var showFrom = "1";
	var feewindow = new SimpleWindow();
	function showPartner(from){
		showFrom = from;
		feewindow.Create('fee_window','<%=LangPage.langPage.getWindowsTitle("fee_selectchannel")%>',300,300,feeHTML);
		feewindow.Show();
		openPage('feelist','1');
	}

	//选择收费渠道
	function selectFee(){
		if(listCurrentKey.get('feelist') == ""){
			alert("<%=LangAction.langAction.getNoselect_feechannel()%>");
			return;
		}else{
			sendG("../GetFeeInfo.do?SPId="+listCurrentKey.get('feelist'),getPDetail);
		}
	}

	function getPDetail(cartXML){

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
			if(showFrom == "1"){
				if(name == "<%=sp.getAliasByFiled("SPId")%>") NewChargeCode.PartnerId.value = value;
				else if(name == "<%=sp.getAliasByFiled("ShortName")%>") NewChargeCode.PartnerName.value = value;
			}else if(showFrom == "2"){
				if(name == "<%=sp.getAliasByFiled("SPId")%>") UpdateChargeCode.PartnerId.value = value;
				else if(name == "<%=sp.getAliasByFiled("ShortName")%>") UpdateChargeCode.PartnerName.value = value;
			}
		}
		feewindow.Close();
	}
<!------------------------------------------------------------->

<!------------------显示省份选择窗口---------------------------->
	var provinceFrom = "1";
	var provincewindow = new SimpleWindow();
	function showProvince(from){
		provinceFrom = from;
		if(provinceFrom == "1"){
			sel_provinceid = NewChargeCode.ProvinceId.value;
			sel_province = NewChargeCode.Province.value;
		}else if(provinceFrom == "2"){
			sel_provinceid = UpdateChargeCode.ProvinceId.value;
			sel_province = UpdateChargeCode.Province.value;
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
			NewChargeCode.Province.value = sel_province;
			NewChargeCode.ProvinceId.value = sel_provinceid;
		}
		else if(provinceFrom == "2"){
			UpdateChargeCode.Province.value = sel_province;
			UpdateChargeCode.ProvinceId.value = sel_provinceid;
		}
		provincewindow.Close();
	}
<!------------------------------------------------------------->

	var cur_countrycode = "";
	var country_from = "1";

<!------------------显示国家选择窗口---------------------------->
	var countrywindow = new SimpleWindow();
	function showCountry(from){
		country_from = from;
		countrywindow.Create('country_window','<%=LangPage.langPage.getWindowsTitle("sp_selectcountry")%>',200,300,countryHTML);
		countrywindow.Show();
		openPage('countrylist','1');
	}

	function selectCountry(){
		if(listCurrentKey.get('countrylist') == ""){
			alert("<%=LangAction.langAction.getNoselect_country()%>");
			return;
		}else{
			if(country_from == "1"){
				if(NewChargeCode.CountryCode.value != listCurrentKey.get('countrylist')){
					NewChargeCode.CountryCode.value = listCurrentKey.get('countrylist');
					NewChargeCode.OpCode.value = "";
				}
			}else if(country_from == "2"){
				if(UpdateChargeCode.CountryCode.value != listCurrentKey.get('countrylist')){
					UpdateChargeCode.CountryCode.value = listCurrentKey.get('countrylist');
					UpdateChargeCode.OpCode.value = "";
				}
			}
			countrywindow.Close();
		}
	}
<!------------------------------------------------------------->

<!------------------显示运营商选择窗口---------------------------->
	var opFrom = "1";
	var opwindow = new SimpleWindow();
	function showOP(from){
		opFrom = from;
		var ccode = "";
		    sel_op = "";
		if(opFrom == "1"){
			sel_op = NewChargeCode.OpCode.value;
			ccode = NewChargeCode.CountryCode.value;
		}else if(opFrom == "2"){
			sel_op = UpdateChargeCode.OpCode.value;
			ccode = UpdateChargeCode.CountryCode.value;
		}
		if(ccode == ""){
			alert("<%=LangAction.langAction.getNoselect_country()%>");
		}else{
			opwindow.Create('province_window','<%=LangPage.langPage.getWindowsTitle("fee_selectprovince")%>',400,350,opHTML);
			opwindow.Show();
			sendG("../GetOPByCountry3.do?CountryCode="+ccode,getOPResult);
		}
	}
		
	function getOPResult(cartXML){
		var xsl = loadXSL("../xsl/checklist2.xsl");
		document.all["oplist"].innerHTML = cartXML.transformNode(xsl);
		selectedCheck1();
	}
		
	function selectedCheck1(){
		var from = sel_op.indexOf(";");
		var to = 0;
		if(from>=0 && from!=sel_op.length-1) to = sel_op.indexOf(";",from+1);
		while (to > 0){
			var temp = sel_op.substring(from+1, to);
			if(temp != ""){
				document.all["chk2_"+temp].checked = true;
			}
			from = to;
			if(from!=sel_op.length-1) to = sel_op.indexOf(";",from+1);
			else to = -1;
		}
	}
	
	//选择省份
	var sel_op = "";
	function clickCheck2(id,name){
		if(document.all["chk2_"+id].checked){
			if(sel_op.indexOf(";"+id+";")<0){
				if(sel_op == "") sel_op = ";"+id+";";
				else sel_op = sel_op+id+";";
			}
		}else{
			if(sel_op.indexOf(";"+id+";")>=0){
				sel_op = sel_op.replace(";"+id+";",";");
			}
		}
	}
	
	function doSelect2(){
		if(opFrom == "1"){
			NewChargeCode.OpCode.value = sel_op;
		}
		else if(opFrom == "2"){
			UpdateChargeCode.OpCode.value = sel_op;
		}
		opwindow.Close();
	}
<!------------------------------------------------------------->

<!------------------页面初始化---------------------->
	var newHTML = "";
	var updateHTML = "";
	var newHTML1 = "";
	var updateHTML1 = "";
	var smsHTML = "";
	var provinceHTML = "";
	var feeHTML = "";
	var spHTML = "";
	var countryHTML = "";
	var opHTML = "";
	var versionHTML = "";
		
	function init(){
		newHTML = document.all["tb_new"].innerHTML;
		document.all["tb_new"].innerHTML = "";
		
		updateHTML = document.all["tb_update"].innerHTML;
		document.all["tb_update"].innerHTML = "";
		
		provinceHTML =document.all["select_province"].innerHTML;
		document.all["select_province"].innerHTML = "";
		
		feeHTML = document.all["tb_fee"].innerHTML;
		document.all["tb_fee"].innerHTML = "";

		spHTML = document.all["tb_sp"].innerHTML;
		document.all["tb_sp"].innerHTML = "";
		
		countryHTML = document.all["tb_country"].innerHTML;
		document.all["tb_country"].innerHTML = "";
		
		opHTML = document.all["tb_op"].innerHTML;
		document.all["tb_op"].innerHTML = "";

		versionHTML = document.all["version_window"].innerHTML;
		document.all["version_window"].innerHTML = "";
		
		showButton();
		initList();
		openPage('chargecodelist','1');
	}

	function initList(){
		listIndex.put('chargecodelist','1');
		listPageURL.put('chargecodelist','');
		listDetailURL.put('chargecodelist','../GetChargeCodeInfo.do?ChargeCodeId=#id#');
		listCurrentId.put('chargecodelist','');
		listCurrentKey.put('chargecodelist','');
		listDetailWidth.put('chargecodelist','300');
		listDetailHeight.put('chargecodelist','320');
		listListXSL.put('chargecodelist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
		listDetailXSL.put('chargecodelist','../xsl/jwdf_sdetail.xsl');

		listIndex.put('countrylist','1');
		listPageURL.put('countrylist','../GetAllCountry.do?index=#index#');
		listDetailURL.put('countrylist','');
		listCurrentId.put('countrylist','');
		listCurrentKey.put('countrylist','');
		listDetailWidth.put('countrylist','300');
		listDetailHeight.put('countrylist','320');
		listListXSL.put('countrylist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
		listDblClickEvent.put('countrylist',selectCountry);

		listIndex.put('oplist','1');
		listPageURL.put('oplist','');
		listDetailURL.put('oplist','');
		listCurrentId.put('oplist','');
		listCurrentKey.put('oplist','');
		listDetailWidth.put('oplist','300');
		listDetailHeight.put('oplist','320');
		listListXSL.put('oplist','');
		
		listIndex.put('feelist','1');
		listPageURL.put('feelist','../GetAllFee.do');
		listDetailURL.put('feelist','');
		listCurrentId.put('feelist','');
		listCurrentKey.put('feelist','');
		listDetailWidth.put('feelist','300');
		listDetailHeight.put('feelist','320');
		listListXSL.put('feelist','../xsl/jwdf_listnopage.xsl');
		listDetailXSL.put('feelist','');
		listClickEvent.put('feelist',selectFee);

		listIndex.put('splist','1');
		//listPageURL.put('splist','../GetCPList.do?index=#index#');
		listDetailURL.put('splist','');
		listCurrentId.put('splist','');
		listCurrentKey.put('splist','');
		listDetailWidth.put('splist','300');
		listDetailHeight.put('splist','320');
		listListXSL.put('splist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
		listDetailXSL.put('splist','');
		listDblClickEvent.put('splist',selectSP);
	}
<!------------------------------------------------------------->
</script>
</head>

<body onload="init();">
<!-- 页面标题 -->
<table class="table_pagetitle" border="0" cellspacing="0" cellpadding="0" align="center">
<tr>
	<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("FeeChannel")%></td>
</tr>
</table>

<!-- 选择的内容提供商 -->
<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
<tr>
	<td width="100" class="td_buttonbar" valign="middle" style="font-size:9pt;">
		<a href="#" onclick="showCP();"><img src="../<%=LangPage.langPage.getButton_img_path()%>selectsp_001.gif" border="0" align="top" vspace="1"/></a>
	</td>
	<td id="apptitle" class="td_buttonbar" valign="middle" style="font-size:9pt;"><%=sp.getAliasByFiled("SPName")%> []</td>
</tr>
</table>

<!-- 操作按钮 -->
<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
<tr>	
	<td class="td_buttonbar" valign="middle">
		<a id="shownew" href="#" onclick="showNew();"><img src="../<%=LangPage.langPage.getButton_img_path()%>add_001.gif"   		  border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
		<a id="showupdate" href="#" onclick="showUpdate();"><img src="../<%=LangPage.langPage.getButton_img_path()%>update_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
		<a id="showdelete" href="#" onclick="deleteObj();"><img src="../<%=LangPage.langPage.getButton_img_path()%>delete_001.gif"    border="0" align="top" vspace="1"/></a>&nbsp;
		<a id="showchannel" href="#" onclick="showChannel();"><img src="../<%=LangPage.langPage.getButton_img_path()%>channel_001.gif"border="0" align="top" vspace="1"/></a>&nbsp;
<td/>
</tr>
</table>

<!-- 计费代码列表显示区域 -->
<div align="center" id="chargecodelist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
</div>

<!-- 添加计费代码表单 -->
<div id="tb_new" class="datainfo">
<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
	<form method="POST" name="NewChargeCode" class="editform">
	<input type="hidden" name="PartnerId" value="">
	<tr>
		<td width="25%" class="td_edittitle"><%=fee.getAliasByFiled("FeeName")%></td>
		<td width="75%" class="td_editcontent">
			<input class="input_edit" style="width:100%;" type="text" name="FeeName" maxlength="15">
		</td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=fee.getAliasByFiled("URI")%></td>
		<td class="td_editcontent">
			<input class="input_edit" style="width:100%;" type="text" name="Uri" maxlength="25">
		</td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=fee.getAliasByFiled("Param")%></td>
		<td class="td_editcontent">
			<input class="input_edit" style="width:100%;" type="text" name="Param" maxlength="20">
		</td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=fee.getAliasByFiled("Price")%></td>
		<td class="td_editcontent">
			<input class="input_edit" style="width:100%;" type="text" name="Price" maxlength="5">
		</td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=fee.getAliasByFiled("ValidPrice")%></td>
		<td class="td_editcontent">
			<input class="input_edit" style="width:100%;" type="text" name="ValidPrice" maxlength="10">
		</td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=fee.getAliasByFiled("CommandType")%></td>
		<td class="td_editcontent">
			<select name="CommandType" value="1">
				<option value="1">精确</option>
				<option value="2">模糊</option>
			</select>
		</td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=fee.getAliasByFiled("CountryCode")%></td>
		<td class="td_editcontent">
			<input style="width:200;" class="input_edit" type="text" name="CountryCode" readonly>
			<a href="#" onclick="showCountry('1');"><img src="../<%=LangPage.langPage.getButton_img_path()%>select_001.gif"   border="0" align="top" vspace="1" /></a>
		</td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=fee.getAliasByFiled("OpCode")%></td>
		<td class="td_editcontent">
			<input style="width:200;" class="input_edit" type="text" name="OpCode" readonly>
			<a href="#" onclick="showOP('1');"><img src="../<%=LangPage.langPage.getButton_img_path()%>select_001.gif"   border="0" align="top" vspace="1" /></a>
		</td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=fee.getAliasByFiled("Province")%></td>
		<td class="td_editcontent">
			<input style="width:200;" class="input_edit" type="text" name="Province" readonly>
			<a href="#" onclick="showProvince('1');"><img src="../<%=LangPage.langPage.getButton_img_path()%>select_001.gif"   border="0" align="top" vspace="1" /></a>
			<input type="hidden" name="ProvinceId"> 			
		</td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=fee.getAliasByFiled("Open2x")%></td>
		<td class="td_editcontent">
			<select name="Open2x" value="0">
				<option value="0">不开通</option>
				<option value="1">开通</option>
			</select>
		</td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=fee.getAliasByFiled("SpName")%></td>
		<td class="td_editcontent">
			<input class="input_edit" style="width:100%;" type="text" name="SpName" maxlength="25">
		</td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=fee.getAliasByFiled("BusinessName")%></td>
		<td class="td_editcontent">
			<input class="input_edit" style="width:100%;" type="text" name="BusinessName" maxlength="20">
		</td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=fee.getAliasByFiled("SpTel")%></td>
		<td class="td_editcontent">
			<input class="input_edit" style="width:100%;" type="text" name="SpTel" maxlength="20">
		</td>
	</tr>
	<tr>
	    <td class="td_edittitle"><%=fee.getAliasByFiled("LevelFlag")%></td>
		<td class="td_editcontent">
			<select name="LevelFlag">
				<option value="1"><%=LangPage.langPage.getSelect("levelflag_green")%></option>
				<option value="2"><%=LangPage.langPage.getSelect("levelflag_org")%></option>
				<option value="3"><%=LangPage.langPage.getSelect("levelflag_red")%></option>
				<option value="0"><%=LangPage.langPage.getSelect("levelflag_unknow")%></option>
			</select>
	    </td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=fee.getAliasByFiled("Remark")%></td>
		<td class="td_editcontent">
			<textarea name="Desc" class="input_textarea" ></textarea>
		</td>
	</tr>
	</form>
	<tr>
		<td class="td_editbutton" colspan="2">
			<a href="#" onclick="newSubmit();"><img src="../<%=LangPage.langPage.getButton_img_path()%>next_001.gif"   border="0" align="top" vspace="1" /></a>&nbsp;&nbsp;
			<a href="#" onclick="newCancel();"><img src="../<%=LangPage.langPage.getButton_img_path()%>cancel_001.gif"   border="0" align="top" vspace="1" /></a>
		</td>
	</tr>
</table>
</div>

<!-- 修改计费代码表单 -->
<div id="tb_update" class="datainfo">
<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
	<form method="POST" name="UpdateChargeCode" class="editform">
	<input type="hidden" name="ChargeCodeId" value="">
	<tr>
		<td class="td_edittitle" width="25%"><%=fee.getAliasByFiled("FeeName")%></td>
		<td class="td_editcontent" width="75%">
			<input class="input_edit" style="width:100%;" type="text" name="FeeName" maxlength="15">
		</td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=fee.getAliasByFiled("URI")%></td>
		<td class="td_editcontent">
			<input class="input_edit" style="width:100%;" type="text" name="Uri" maxlength="25">
		</td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=fee.getAliasByFiled("Param")%></td>
		<td class="td_editcontent">
			<input class="input_edit" style="width:100%;" type="text" name="Param" maxlength="20">
		</td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=fee.getAliasByFiled("Price")%></td>
		<td class="td_editcontent">
			<input class="input_edit" style="width:100%;" type="text" name="Price" maxlength="5">
		</td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=fee.getAliasByFiled("ValidPrice")%></td>
		<td class="td_editcontent">
			<input class="input_edit" style="width:100%;" type="text" name="ValidPrice" maxlength="10">
		</td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=fee.getAliasByFiled("CommandType")%></td>
		<td class="td_editcontent">
			<select name="CommandType" value="1">
				<option value="1">精确</option>
				<option value="2">模糊</option>
			</select>
		</td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=fee.getAliasByFiled("CountryCode")%></td>
		<td class="td_editcontent">
			<input style="width:200;" class="input_edit" type="text" name="CountryCode" readonly>
			<a href="#" onclick="showCountry('2');"><img src="../<%=LangPage.langPage.getButton_img_path()%>select_001.gif"   border="0" align="top" vspace="1" /></a>
		</td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=fee.getAliasByFiled("OpCode")%></td>
		<td class="td_editcontent">
			<input style="width:200;" class="input_edit" type="text" name="OpCode" readonly>
			<a href="#" onclick="showOP('2');"><img src="../<%=LangPage.langPage.getButton_img_path()%>select_001.gif"   border="0" align="top" vspace="1" /></a>
		</td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=fee.getAliasByFiled("Province")%></td>
		<td class="td_editcontent">
			<input style="width:200;" class="input_edit" type="text" name="Province" readonly>
			<a href="#" onclick="showProvince('2');"><img src="../<%=LangPage.langPage.getButton_img_path()%>select_001.gif"   border="0" align="top" vspace="1" /></a>
			<input type="hidden" name="ProvinceId"> 
		</td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=fee.getAliasByFiled("Open2x")%></td>
		<td class="td_editcontent">
			<select name="Open2x" value="0">
				<option value="0">不开通</option>
				<option value="1">开通</option>
			</select>
		</td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=fee.getAliasByFiled("SpName")%></td>
		<td class="td_editcontent">
			<input class="input_edit" style="width:100%;" type="text" name="SpName" maxlength="25">
		</td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=fee.getAliasByFiled("BusinessName")%></td>
		<td class="td_editcontent">
			<input class="input_edit" style="width:100%;" type="text" name="BusinessName" maxlength="20">
		</td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=fee.getAliasByFiled("SpTel")%></td>
		<td class="td_editcontent">
			<input class="input_edit" style="width:100%;" type="text" name="SpTel" maxlength="20">
		</td>
	</tr>
	<tr>
	    <td class="td_edittitle"><%=fee.getAliasByFiled("LevelFlag")%></td>
		<td class="td_editcontent">
			<select name="LevelFlag">
				<option value="1"><%=LangPage.langPage.getSelect("levelflag_green")%></option>
				<option value="2"><%=LangPage.langPage.getSelect("levelflag_org")%></option>
				<option value="3"><%=LangPage.langPage.getSelect("levelflag_red")%></option>
				<option value="0"><%=LangPage.langPage.getSelect("levelflag_unknow")%></option>
			</select>
		</td>
	</tr>
	<tr>
		<td class="td_edittitle"><%=fee.getAliasByFiled("Remark")%></td>
		<td class="td_editcontent">
			<textarea name="Desc" class="input_textarea"></textarea>
		</td>
	</tr>
	</form>
	<tr>
		<td class="td_editbutton" colspan="2">
			<a href="#" onclick="updateSubmit();"><img src="../<%=LangPage.langPage.getButton_img_path()%>next_001.gif"   border="0" align="top" vspace="1" /></a>&nbsp;&nbsp;
			<a href="#" onclick="updateCancel();"><img src="../<%=LangPage.langPage.getButton_img_path()%>cancel_001.gif"  border="0" align="top" vspace="1" /></a>
		</td>
	</tr>
</table>
</div>


<!-- 选择适配省份窗口 -->
<div id="select_province" class="datainfo">
<div id="provincelist"
	style="width:100%;height:150; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
</div>
<br>
<center>
	<a href="#" onclick="doSelect();"><img src="../<%=LangPage.langPage.getButton_img_path()%>select_001.gif"  border="0" align="top" vspace="1" /></a>
</center>
</div>

<div id="tb_fee" class="datainfo">
<div align="center" id="feelist"
	style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
</div>
</div>

	<!-- cp列表显示区域 -->
	<div id="tb_sp" class="datainfo">
		<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
			<tr>
				<td class="td_buttonbar" valign="middle" style="font-size:9pt;"><%=LangPage.langPage.getSearch("search_bycp")%>

					<input type="text" class="input_edit"  name="SearchBySP">
					<a href="#" onclick="searchBySP();"><img src="../<%=LangPage.langPage.getButton_img_path()%>search_003.gif" border="0" align="top" vspace="1" /></a>
				</td>
			</tr>
		</table>
		<div align="center" id="splist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		</div>
	</div>

	<!-- 国家列表显示区域 -->
	<div id="tb_country" class="datainfo">
		<div align="center" id="countrylist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		</div>
	</div>

	<!-- 运营商列表显示区域 -->
	<div id="tb_op" class="datainfo">
		<div align="center" id="oplist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		</div>
	</div>
	
	
	<!-- 通道-->
     <div align="center" id="version_window" class="datainfo">
		<!-- 当前程序信息 -->
		<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
		<tr>										
			<td class="td_edittitle" width="15%"><%=fee.getAliasByFiled("FeeName")%></td>
			<td class="td_editcontent" width="35%" id="td_FeeName"></td>
			<td class="td_edittitle" width="15%"><%=fee.getAliasByFiled("Price")%></td>
			<td class="td_editcontent" width="35%" id="td_Price"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=fee.getAliasByFiled("CountryCode")%></td>
			<td class="td_editcontent" id="td_CountryCode"></td>
			<td class="td_edittitle"><%=fee.getAliasByFiled("BusinessName")%></td>
			<td class="td_editcontent" id="td_BusinessName"></td>
		</tr>
		</table>
		
	<!-- 版本列表显示区域 -->
		<div id="feechannelconfiglist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		</div>
	</div>
</body>
</html>
