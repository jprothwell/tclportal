<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangAction"%>
<%@ page import="com.language.langdata.LangDBTable"%>
<%@ page import="com.vogins.sps.db.fee.FeeGroupInfo"%>
<%
	FeeGroupInfo fee = new FeeGroupInfo();
%>
<html>


<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<TITLE><%=LangPage.langPage.getPageTitle("FeeGroup")%></TITLE>
<meta http-equiv="Pragma" content="no-cache">
<link rel="stylesheet" type="text/css" href="../css/jwdf_main.css">
<link rel="stylesheet" type="text/css" href="../css/jwdf_swin.css">
<SCRIPT language="JavaScript" type="text/javascript" src="../js/jwdf_util.js"></SCRIPT>
<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_xml.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_view.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_swin.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>sps_workflow.js"></SCRIPT>
	
<script language=javascript>

		var newwindow = new SimpleWindow();
		function showNew(){
			newwindow.Create('new_window','<%=LangPage.langPage.getWindowsTitle("fee_addfeegroup")%>',280,315,newHTML);
			newwindow.Show();
		}
		function newCancel(){
			newwindow.Close();
		}
		function newSubmit(){
			if(NewFeeGroup.FeeGroupName.value == ""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=fee.getAliasByFiled("FeeGroupName")%>");
				NewFeeGroup.FeeGroupName.focus();
				return false;
			}
			sendP("../AddFeeGroup.do",getP(NewFeeGroup),newResult);
		}
		function newResult(){
			newwindow.Close();
			openPage('grouplist',listIndex.get('grouplist'));
		}

<!------------------------------------------------------------->


		var Channelwindow = new SimpleWindow();
		function showChannellist(){                     //添加
			if(listCurrentKey.get('grouplist')==""){
				alert("<%=LangAction.langAction.getNoselect_feegroup()%>");
			}else{
				Channelwindow.Create('list_window','<%=LangPage.langPage.getWindowsTitle("fee_selectchannel")%>',500,300,selectHTML);
				Channelwindow.Show();
				openPage('selectlist','1');
			}
		}
		function doSelect(){
			if(listCurrentKey.get('selectlist') == ""){
				alert("<%=LangAction.langAction.getNoselect_feechannel()%>");
				return;
			}else{
				newSubmit1();
			   Channelwindow.Close();
			}
		}
		
<!---------------添加一个通道到通道组------------------------->
        var cur_groupId="";
		function newSubmit1(){
			if(cur_groupid == ""){
				alert("<%=LangAction.langAction.getNoselect_feechannel()%>");
				return false;
			}
		
			sendG("../AddGroupConfig.do?GroupId="+cur_groupid+"&FeeId="+listCurrentKey.get('selectlist'),newResult1);
		}
		function newResult1(cartXML){
			var cart = cartXML.getElementsByTagName("result")[0];
			var flowId = cart.getElementsByTagName("info")[0].firstChild.nodeValue;
			cur_flowid = flowId;

			handlewindow.Create('hdl_window','<%=LangPage.langPage.getWindowsTitle("workflow_sub")%>',350,300,handleHTML);
			handlewindow.Show();
			listPageURL.put('sublist','../GetSubWFList.do?index=#index#&AppSeqNo=1&FlowId='+cur_flowid);
			openPage('sublist','1');
		}
<!---------------从通道组删除该通道------------------------->
        
		function deleteObj1(){
			if(listCurrentKey.get('channellist') == ""){
				alert("<%=LangAction.langAction.getNoselect_feechannel()%>");
				return false;
			}
	
			sendG("../DeleteGroupConfig.do?RecId="+listCurrentKey.get('channellist'),delResult1);
		}
		function delResult1(cartXML){
			var cart = cartXML.getElementsByTagName("result")[0];
			var flowId = cart.getElementsByTagName("info")[0].firstChild.nodeValue;
			cur_flowid = flowId;

//			updatewindow.Close();
			handlewindow.Create('hdl_window','<%=LangPage.langPage.getWindowsTitle("workflow_sub")%>',350,300,handleHTML);
			handlewindow.Show();
			listPageURL.put('sublist','../GetSubWFList.do?index=#index#&AppSeqNo=1&FlowId='+cur_flowid);
			openPage('sublist','1');
		}
<!---------------------------------国际化----------------------------------->
		function showCountry(){
		    sendG("../GetAllCountry.do",getCounResult);
		}
		function getCounResult(cartXML){
		 	var cart = cartXML.getElementsByTagName("result")[0];
			var list = cart.getElementsByTagName("list")[0];
			var rows = list.getElementsByTagName("row");
			SearchForm.CountryCode.options.length = 0;
			SearchForm.CountryCode.add(document.createElement("OPTION"));
			SearchForm.CountryCode.options[0].text="<%=LangPage.langPage.getSearch("search_pleaseselect")%>";
			SearchForm.CountryCode.options[0].value="";
			for(var i=0;i<rows.length;i++){
				var key = rows[i].getElementsByTagName("key")[0].firstChild.nodeValue;
				var field = rows[i].getElementsByTagName("field")[0].firstChild.nodeValue;
				SearchForm.CountryCode.add(document.createElement("OPTION"));
				SearchForm.CountryCode.options[i+1].text=field;
			    SearchForm.CountryCode.options[i+1].value=key;
		 
			}
		}
		function getGroupByCountry(){
		    sendG("../GetGroupByCountry.do?CountryCode="+SearchForm.CountryCode.value,getGroupResult);
		}
		function getGroupResult(cartXML){
			var xsl = loadXSL("../xsl/click_list.xsl");
			initList();
			cur_groupnum = "";
			cur_groupid = "";
			cur_groupname = "";
			document.all["grouplist"].innerHTML = cartXML.transformNode(xsl);
		}
	<!---------------选定通道组后，读取该通道组所属通道的操作---------------->
		cur_groupnum = "";
		cur_groupid = "";
		cur_groupname = "";
		function doClick(id,key,name){
			var tds=document.all["clicktr"+id].getElementsByTagName("td");
			if(cur_groupnum=="" || cur_groupnum=="0"){
				for(i=0;i<tds.length;i++){
					tds[i].className="td_listcontent0";
				}
				cur_groupnum=id;
				cur_groupid = key;
				cur_groupname = name;
			}else{
				var tds0=document.all["clicktr"+cur_groupnum].getElementsByTagName("td");
				for(i=0;i<tds0.length;i++){
					tds0[i].className="td_listcontent";
				}
				for(i=0;i<tds.length;i++){
					tds[i].className="td_listcontent0";
				}
				cur_groupnum=id;
				cur_groupid = key;
				cur_groupname = name;
			}
        	showChannel();
		}
<!------------------------------------------------------------->

<!----------------读取指定通道组的通道----------------------->
		function showChannel(){
	
			if(cur_groupid != ""){
				listPageURL.put('channellist','../GetChannelList.do?GroupId='+cur_groupid+'&index=#index#');
			    openPage('channellist','1');
			   
			}
		}
<!------------------------------------------------------------->
<!---------------------------------显示国家选择窗口------------------------------------->
<!------------------页面初始化---------------------->
		var newHTML = "";
		var updateHTML = "";
		var selectHTML ="";
		
		function init(){		
			updateHTML = document.all["tb_update"].innerHTML;
			document.all["tb_update"].innerHTML = "";
			selectHTML = document.all["tb_select"].innerHTML;
			document.all["tb_select"].innerHTML = "";
			initList();
			showCountry();
			
		}

		function initList(){
	
			listIndex.put('channellist','1');
			listPageURL.put('channellist','../GetChannelList.do?GroupId=#id#');
			listDetailURL.put('channellist','');
			listCurrentId.put('channellist','');
			listCurrentKey.put('channellist','');
			listDetailWidth.put('channellist','400');
			listDetailHeight.put('channellist','300');
			listListXSL.put('channellist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('channellist','');
			
			listIndex.put('countrylist','1');
			listPageURL.put('countrylist','../GetAllCountry.do?index=#index#');
			listDetailURL.put('countrylist','');
			listCurrentId.put('countrylist','');
			listCurrentKey.put('countrylist','');
			listDetailWidth.put('countrylist','300');
			listDetailHeight.put('countrylist','320');
			listListXSL.put('countrylist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			
			listIndex.put('selectlist','1');
			listPageURL.put('selectlist','../GetChannByCountry.do?CountryCode='+SearchForm.CountryCode.value+'&index=#index#');
			listDetailURL.put('selectlist','');
			listCurrentId.put('selectlist','');
			listCurrentKey.put('selectlist','');
			listDetailWidth.put('selectlist','400');
			listDetailHeight.put('selectlist','300');
			listListXSL.put('selectlist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('selectlist','');
			listDblClickEvent.put('selectlist',doSelect);
		
		}
		
<!------------------------------------------------------------->
	</script>
</head>

<body onload="init();">
<!-- 页面标题 -->
<table class="table_pagetitle" border="0" cellspacing="0"
	cellpadding="0" align="center">
	<tr>
		<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("FeeGroup")%></td>
	</tr>
	
</table>
<table width="100%" height="100%" border="0" cellspacing="0"
	cellpadding="0" align="center">
	<tr>
		<td valign="top"><!-- 选择的机型 -->
		<!-- 操作按钮 -->
		<table width="100%" border="0" cellspacing="0" cellpadding="0"
			align="center">
			<tr>
		<td class="td_buttonbar" valign="middle">
			<a href="#" onclick="showChannellist();"><img src="../<%=LangPage.langPage.getButton_img_path()%>add_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a href="#" onclick="deleteObj1();"><img src="../<%=LangPage.langPage.getButton_img_path()%>delete_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a href="#" onclick="openPage('channellist',listIndex.get('channellist'));"><img src="../<%=LangPage.langPage.getButton_img_path()%>refresh_001.gif"   border="0" align="top" vspace="1"/></a>
	　　　</td>
	  
	　　</tr>
	</table>
	    <div align="center" id="channellist" 
   			style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		</div>
		</td>
	
	   		<td width="150" class="td_detailcontent1"
			style="padding-top:5;font-size:9pt;border-left:0.05cm solid #c3c3c3;"
			valign="top"><form method="POST" name="SearchForm" class="editform">
		<b><%=LangPage.langPage.getSearch("search_country")%></b><select name="CountryCode" onchange="getGroupByCountry();"><option selected value=""><%=LangPage.langPage.getSearch("search_pleaseselect")%></option></select>
		　</form>
		<div id="grouplist"
			style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		</div>
		</td>
	</tr>
</table>


<!-- 修改通道组的表单 -->
<div id="tb_update" class="datainfo">
<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
	<form method="POST" name="UpdateFeeGroup" class="editform"><input
		type="hidden" name="GroupId" value="">
	<tr>
		<td class="td_edittitle" width="80"><%=fee.getAliasByFiled("FeeGroupName")%></td>
		<td class="td_editcontent" width="200"><input class="input_edit"
			style="width:100%;" type="text" name="FeeGroupName" maxlength="20"></td>
	</tr>
	<tr>
		<td class="td_editbutton" colspan="2">
			<a href="#" onclick="updateSubmit();"><img src="../<%=LangPage.langPage.getButton_img_path()%>ok_001.gif"   border="0" align="top" vspace="1" /></a>&nbsp;&nbsp;
			<a href="#" onclick="updateCancel();"><img src="../<%=LangPage.langPage.getButton_img_path()%>cancel_001.gif"   border="0" align="top" vspace="1" /></a>
		</td>
	</tr>
	</form>
</table>
</div>
<div id="tb_select" class="datainfo">
		<div align="center" id="selectlist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		</div>
</div>	
</body>

</html>
