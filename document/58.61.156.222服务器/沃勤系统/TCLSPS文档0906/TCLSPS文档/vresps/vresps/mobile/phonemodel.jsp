<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangAction"%>
<%@ page import="com.vogins.sps.db.mobile.MFPartner"%>
<%@ page import="com.vogins.sps.db.mobile.Mobile"%>
<%
	MFPartner mf = new MFPartner();
	Mobile mobile = new Mobile();
%>
<html>

<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<TITLE><%=LangPage.langPage.getPageTitle("phonemodel")%></TITLE>
<meta http-equiv="Pragma" content="no-cache">
<link rel="stylesheet" type="text/css" href="../css/jwdf_main.css">
<link rel="stylesheet" type="text/css" href="../css/jwdf_swin.css">
	<SCRIPT language="JavaScript" type="text/javascript" src="../js/jwdf_util.js"></SCRIPT>
		<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_xml.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_view.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_swin.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>sps_workflow.js"></SCRIPT>
<script language=javascript>
        var reg=/[\u4E00-\u9FA5]/g; //汉字判断
		var zimu =/[a-zA-Z]/ ;  //字母判断
		var shuzi =/^[0-9]*[1-9][0-9]*$/; //数字
		var fudian  =/^(-?\\d+)(\\.\\d+)?$/; //浮点数判断

		var cur_flowid = "";
	<!----------------读取指定厂商的机型----------------------->
		function showMobile(){
			listPageURL.put('mobilelist','../GetMobileList.do?PartnerId=0&index=#index#');
			openPage('mobilelist','1');
		}

	<!-------------------显示详细信息-------------------------->
		var dtwindow = new SimpleWindow();
		function ShowdetailInfo(){
			if(listCurrentKey.get('mobilelist')==""){
				alert("<%=LangAction.langAction.getNoselect_mobile()%>");
				return;
			}else{
	         dtwindow.Create('detail_window','<%=LangPage.langPage.getWindowsTitle("cw_detail")%>',500,260,detailHTML);
	         
	         dtwindow.Show();
				sendG("../GetMobileInfo.do?MobileId="+listCurrentKey.get('mobilelist'),getDetailInfo);
			}
		}
		function getDetailInfo(cartXML){
			DetaileMobile.reset();
			var cart = cartXML.getElementsByTagName("result")[0];
			var code = cart.getElementsByTagName("code")[0].firstChild.nodeValue;
			var detail = cart.getElementsByTagName("detail")[0];
			var fields = detail.getElementsByTagName("field");
		    var screenWeight ="";
		    var screenHeight ="";
			for(i=0;i<fields.length;i++){
				var name = fields[i].getElementsByTagName("name")[0].firstChild.nodeValue;
				var value = "";
				if(fields[i].getElementsByTagName("value")[0].firstChild != null){
					value = fields[i].getElementsByTagName("value")[0].firstChild.nodeValue;
				}
				if(name == "<%=mobile.getAliasByFiled("MobileId")%>") DetaileMobile.MobileId.value = value;
				else if(name == "<%=mobile.getAliasByFiled("MFId")%>") DetaileMobile.MFId.value = value;
				else if(name == "<%=mobile.getAliasByFiled("MobileName")%>")document.all["MobileName"].innerHTML = value;
				else if(name == "<%=mobile.getAliasByFiled("UserAgent")%>") document.all["UserAgent"].innerHTML = value;
				else if(name == "<%=mobile.getAliasByFiled("InputType")%>"){    
				    var InputType=""            
				    if(value=="1")InputType="<%=LangPage.langPage.getSelect("screen_keypad")%><br>";
					if(value=="2")InputType="<%=LangPage.langPage.getSelect("screen_touch")%><br>";
					if(value=="3")InputType="<%=LangPage.langPage.getSelect("screen_keypad")%><br><%=LangPage.langPage.getSelect("screen_touch")%><br>";
					if(value=="4")InputType="<%=LangPage.langPage.getSelect("screen_gravitysensor")%><br>";
					if(value=="5")InputType="<%=LangPage.langPage.getSelect("screen_keypad")%><br><%=LangPage.langPage.getSelect("screen_gravitysensor")%><br>";
					if(value=="6")InputType="<%=LangPage.langPage.getSelect("screen_touch")%><br><%=LangPage.langPage.getSelect("screen_gravitysensor")%><br>";
					if(value=="7")InputType="<%=LangPage.langPage.getSelect("screen_keypad")%><br><%=LangPage.langPage.getSelect("screen_touch")%><br><%=LangPage.langPage.getSelect("screen_gravitysensor")%><br>";
					if(value=="8")InputType="<%=LangPage.langPage.getSelect("screen_opticalsensor")%><br>";
					if(value=="9")InputType="<%=LangPage.langPage.getSelect("screen_keypad")%><br><%=LangPage.langPage.getSelect("screen_opticalsensor")%><br>";
					if(value=="10")InputType="<%=LangPage.langPage.getSelect("screen_touch")%><br><%=LangPage.langPage.getSelect("screen_opticalsensor")%><br>";
					if(value=="11")InputType="<%=LangPage.langPage.getSelect("screen_keypad")%><br><%=LangPage.langPage.getSelect("screen_touch")%><br><%=LangPage.langPage.getSelect("screen_opticalsensor")%><br>";
					if(value=="12")InputType="<%=LangPage.langPage.getSelect("screen_gravitysensor")%><br><%=LangPage.langPage.getSelect("screen_opticalsensor")%><br>";
					if(value=="13")InputType="<%=LangPage.langPage.getSelect("screen_keypad")%><br><%=LangPage.langPage.getSelect("screen_gravitysensor")%><br><%=LangPage.langPage.getSelect("screen_opticalsensor")%><br>";
					if(value=="14")InputType="<%=LangPage.langPage.getSelect("screen_touch")%><br><%=LangPage.langPage.getSelect("screen_gravitysensor")%><br><%=LangPage.langPage.getSelect("screen_opticalsensor")%><br>";
					if(value=="15")InputType="<%=LangPage.langPage.getSelect("screen_keypad")%><br><%=LangPage.langPage.getSelect("screen_touch")%><br><%=LangPage.langPage.getSelect("screen_gravitysensor")%><br><%=LangPage.langPage.getSelect("screen_opticalsensor")%><br>";
					document.all["InputType"].innerHTML = InputType;
					
				}
				else if(name == "<%=mobile.getAliasByFiled("ScreenWidth")%>") document.all["ScreenWidth"].innerHTML = value;
				else if(name == "<%=mobile.getAliasByFiled("ScreenHeight")%>") document.all["ScreenHeight"].innerHTML = value;
				else if(name == "<%=mobile.getAliasByFiled("VREVersion")%>")document.all["VREVersion"].innerHTML = value; 
				else if(name == "<%=mobile.getAliasByFiled("MTKVersion")%>") document.all["MTKVersion"].innerHTML = value;
				else if(name == "<%=mobile.getAliasByFiled("MemorySize")%>")  document.all["MemorySize"].innerHTML = value; 
		       else if(name == "<%=mobile.getAliasByFiled("FileExtName")%>")document.all["FileExtName"].innerHTML = value; 
		       else if(name=="<%=mobile.getAliasByFiled("AppListType")%>"){
		          var type="";
		           if(value=="2")type="<%=LangPage.langPage.getSelect("app_mobile")%>";
		           if(value=="1")type="<%=LangPage.langPage.getSelect("app_type")%>";
		           document.all["AppListType"].innerHTML  = type; 
		          
		         }
		        else {
                    document.all["Remark"].innerHTML = value;
              }
			}
		}

	<!---------------------------添加或修改厂商时选择厂商---------------------------------->


		var updateMFwindow = new SimpleWindow();
		function showPartner(){
			updateMFwindow.Create('updatemf_window','<%=LangPage.langPage.getWindowsTitle("mf_selectmf")%>',300,400,mfUpdateHTML);
			updateMFwindow.Show();
			openPage('Allmflist','1');

		}
		
		function selectUpdateMF(){
			if(listCurrentKey.get('Allmflist') == ""){
				alert("<%=LangAction.langAction.getNoselect_mf()%>");
				return;
			}else{
				sendG("../GetMFInfo.do?PartnerId="+listCurrentKey.get('Allmflist'),getmfetail);
			}
		}
		function getmfetail(cartXML){
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
			    if(name == "<%=mf.getAliasByFiled("MFId")%>") UpdateMobile.MFId.value = value;
				else if(name == "<%=mf.getAliasByFiled("MFName")%>") UpdateMobile.MFName.value = value;
			}
			updateMFwindow.Close();
		}
		
	<!------------------选择手机厂商---------------------------->
		var cur_mfid = "";
		cur_mfname = "";
		var mfwindow = new SimpleWindow();
		function showMF(){
			mfwindow.Create('mf_window','<%=LangPage.langPage.getWindowsTitle("mf_selectmf")%>',600,400,mfHTML);
			mfwindow.Show();
			listPageURL.put('mflist','../GetMFList.do?index=#index#');
			openPage('mflist','1');
		}
		
		function selectMF(){
			if(listCurrentKey.get('mflist') == ""){
				alert("<%=LangAction.langAction.getNoselect_mf()%>");
				return;
			}else{
				sendG("../GetMFInfo.do?PartnerId="+listCurrentKey.get('mflist'),getMFDetail);
			}
		}
		
		function getMFDetail(cartXML){
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
				if(name == "<%=mf.getAliasByFiled("MFId")%>"){
					cur_mfid = value;
				}else if(name == "<%=mf.getAliasByFiled("ShortName")%>"){
					cur_mfname = value;
					document.all["mobiletitle"].innerHTML = "[" + cur_mfname + "]";
					showButton();
				}
			}
			mfwindow.Close();
			if(cur_mfid != ""){
				listPageURL.put('mobilelist','../GetMobileList.do?PartnerId='+cur_mfid+'&index=#index#');
				openPage('mobilelist','1');
			}
		}	
	<!-------------------修改厂商-------------------------->
		var updatewindow = new SimpleWindow();
		function showUpdate(){
			if(listCurrentKey.get('mobilelist')==""){
				alert("<%=LangAction.langAction.getNoselect_mobile()%>");
				return;
			}else{
				updatewindow.Create('update_window','<%=LangPage.langPage.getWindowsTitle("mf_updatemf")%>',300,93,updateHTML);
				updatewindow.Show();
				sendG("../GetMobileInfo.do?MobileId="+listCurrentKey.get('mobilelist'),getUpdate);
			}
		}
		function updateCancel(){
			updatewindow.Close();
		}
		function getUpdate(cartXML){
			UpdateMobile.reset();
			var cart = cartXML.getElementsByTagName("result")[0];
			var code = cart.getElementsByTagName("code")[0].firstChild.nodeValue;
			var detail = cart.getElementsByTagName("detail")[0];
			var fields = detail.getElementsByTagName("field");
			var upothertable = document.getElementById("Upothertable");
			var upviewType = document.getElementById("UpviewTable");
			for(i=0;i<fields.length;i++){
				var name = fields[i].getElementsByTagName("name")[0].firstChild.nodeValue;
				var value = "";
				if(fields[i].getElementsByTagName("value")[0].firstChild != null){
					value = fields[i].getElementsByTagName("value")[0].firstChild.nodeValue;
				}
				if(name == "<%=mobile.getAliasByFiled("MobileId")%>") UpdateMobile.MobileId.value = value;
				else if(name == "<%=mobile.getAliasByFiled("MFId")%>") UpdateMobile.MFId.value = value;
				else if(name == "<%=mobile.getAliasByFiled("MFName")%>") UpdateMobile.MFName.value = value;
				else if(name == "<%=mobile.getAliasByFiled("LevelFlag")%>") UpdateMobile.LevelFlag.value = value;
			}
		}
		
	<!------------------工作流部分-下一步-------------------------->
	function updateSubmit(){
			
			sendP("../UpdateMobile.do",getP(UpdateMobile),updateResult);
		}
		function updateResult(cartXML){
		 	var cart = cartXML.getElementsByTagName("result")[0];
			var flowId = cart.getElementsByTagName("info")[0].firstChild.nodeValue;
			cur_flowid = flowId;

		
			handlewindow.Create('hdl_window','<%=LangPage.langPage.getWindowsTitle("workflow_sub")%>',350,300,handleHTML);
			handlewindow.Show();
			listPageURL.put('sublist','../GetSubWFList.do?index=#index#&AppSeqNo=1&FlowId='+cur_flowid);
			openPage('sublist','1');
		}
	
	<!---------------------------手机厂商查询列表---------------------------------->
		function searchMFByName(){
			listIndex.put('mflist','1');
			var mfName = SearchMFByName.value;
			listPageURL.put('mflist','../GetMFListByMFName.do?MFName='+encodeURIComponent(mfName)+'&index=#index#');
			listDetailURL.put('mflist','');
			listCurrentId.put('mflist','');
			listCurrentKey.put('mflist','');
			listDetailWidth.put('mflist','400');
			listDetailHeight.put('mflist','300');
			listListXSL.put('mflist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDblClickEvent.put('mflist',selectMF);
			openPage('mflist','1');
		}

	<!------------------控制隐藏显示按钮---------------------->
		function showButton(){
			if(cur_mfname==""){
				updatemf.style.visibility = "hidden";
			}else{
				updatemf.style.visibility = "visible";
			}
		}
	<!------------------页面初始化---------------------->
		var mfHTML ="";
		var updateHTML = "";
		var mfUpdateHTML = "";
		
		function init(){
			detailHTML = document.all["tb_detail"].innerHTML;
			document.all["tb_detail"].innerHTML = "";
			
			mfHTML = document.all["tb_mf"].innerHTML;
			document.all["tb_mf"].innerHTML = "";
			
			updateHTML = document.all["tb_update"].innerHTML;
			document.all["tb_update"].innerHTML = "";
			
			mfUpdateHTML = document.all["tb_mfupdate"].innerHTML;
			document.all["tb_mfupdate"].innerHTML = "";

			//showButton();
			showMobile();
			initList();
		}

		function initList(){
		
			listIndex.put('mobilelist','1');
			listPageURL.put('mobilelist','');
			//listDetailURL.put('mobilelist','../GetMobileInfo.do?MobileId=#id#');
			listCurrentId.put('mobilelist','');
			listCurrentKey.put('mobilelist','');
			listListXSL.put('mobilelist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('mobilelist','../xsl/jwdf_sdetail.xsl');
			listDblClickEvent.put('mobilelist',ShowdetailInfo);
			
			listIndex.put('Allmflist','1');
			listPageURL.put('Allmflist','../GetAllMF.do');
			listDetailURL.put('Allmflist','');
			listCurrentId.put('Allmflist','');
			listCurrentKey.put('Allmflist','');
			listDetailWidth.put('Allmflist','300');
			listDetailHeight.put('Allmflist','320');
			listListXSL.put('Allmflist','../xsl/jwdf_listnopage.xsl');
			listDetailXSL.put('Allmflist','');
			listClickEvent.put('Allmflist',selectUpdateMF);
			
			listIndex.put('mflist','1');
			//listPageURL.put('mflist','../GetMFList.do?index=#index#');
			listDetailURL.put('mflist','');
			listCurrentId.put('mflist','');
			listCurrentKey.put('mflist','');
			listDetailWidth.put('mflist','300');
			listDetailHeight.put('mflist','320');
			listListXSL.put('mflist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('mflist','');
			listDblClickEvent.put('mflist',selectMF);
		    
		}
		 
	<!------------------------------------------------>
	</script>
</head>

<body onload="init();">
<!-- 页面标题 -->
<table class="table_pagetitle" border="0" cellspacing="0"
	cellpadding="0" align="center">
	<tr>
		<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("phonemodel")%></td>
	</tr>
</table>

<table width="100%" height="100%" border="0" cellspacing="0"
	cellpadding="0" align="center">
	<tr>
		<td valign="top">

		<!-- 操作按钮 -->
		<table width="90%" border="0" cellspacing="0" cellpadding="0"
			align="center">
			<tr>
				<td class="td_buttonbar" valign="middle">
					<a id="updatemf" href="#" onclick="showUpdate();"><img src="../<%=LangPage.langPage.getButton_img_path()%>uploadmobile_001.gif"   border="0" align="top" vspace="1" /></a>
				</td>
			</tr>
		</table>

		<!-- 机型列表显示区域 -->
		<div align="center" id="mobilelist"
			style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		</div>
		</td>
	</tr>
</table>
<!-- 详细信息显示表单 -->
<div align="center" id="tb_detail" class="datainfo"
	style="background-color:white;">
<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
	<form method="POST" name="DetaileMobile" class="editform"><input
		type="hidden" name="MobileId" value=""> <input type="hidden"
		name="MFId" value="">
	<tr>
		<td class="td_edittitle" width="80"><%=mobile.getAliasByFiled("MobileName")%></td>
		<td id="MobileName" class="td_editcontent" width="200"></td>
		<td class="td_edittitle" width="80"><%=mobile.getAliasByFiled("UserAgent")%></td>
		<td id="UserAgent" class="td_editcontent" width="200"></td>
	</tr>
	<tr>
		<td class="td_edittitle" width="100"><%=mobile.getAliasByFiled("VREVersion")%></td>
		<td id="VREVersion" class="td_editcontent" width="200"></td>
		<td class="td_edittitle" width="100"><%=mobile.getAliasByFiled("MTKVersion")%></td>
		<td id="MTKVersion" class="td_editcontent" width="200"></td>
	</tr>
	<tr>
		<td class="td_edittitle" width="80"><%=mobile.getAliasByFiled("FileExtName")%></td>
		<td id="FileExtName" class="td_editcontent" width="200">
		<td class="td_edittitle" width="80" nowrap><%=mobile.getAliasByFiled("MemorySize")%></td>
		<td id="MemorySize" class="td_editcontent" width="200"></td>
	</tr>
	<tr>
		<td class="td_edittitle" width="80"><%=mobile.getAliasByFiled("ScreenHeight")%></td>
		<td id="ScreenHeight" class="td_editcontent" width="200"></td>
		<td class="td_edittitle" width="80"><%=mobile.getAliasByFiled("ScreenWidth")%></td>
		<td id="ScreenWidth" class="td_editcontent" width="200"></td>
	</tr>
	<tr>
		<td class="td_edittitle" width="80"><%=mobile.getAliasByFiled("InputType")%></td>
		<td id="InputType" class="td_editcontent" width="200"></td>
		<td class="td_edittitle" width="80"><%=mobile.getAliasByFiled("AppListType")%></td>
		<td id="AppListType" class="td_editcontent" width="200"></td>
	</tr>
	<tr>
	   <td class="td_edittitle" width="80"><%=mobile.getAliasByFiled("Remark")%></td>
		<td id="Remark" class="td_editcontent" width="200" colspan="3"></td>
	</tr>
	</form>
</table>
</div>
<div align="center" id="tb_update" class="datainfo">
<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
	<form method="POST" name="UpdateMobile" class="editform"><input
		type="hidden" name="MobileId" value="">
	<tr>
	    <td class="td_edittitle" width="80"><%=mf.getAliasByFiled("MFName")%></td>
		<td class="td_editcontent" width="200"><input type="hidden"
			name="MFId"> <input class="input_edit" type="text"
			name="MFName">
			<a href="#" onclick="showPartner();"><img src="../<%=LangPage.langPage.getButton_img_path()%>select_001.gif"   border="0" align="top" vspace="1" /></a>
	    </td>
	</tr>
	<tr>
	    <td class="td_edittitle" width="80"><%=mobile.getAliasByFiled("LevelFlag")%></td>
		<td class="td_editcontent" width="200"><select name="LevelFlag">
		    <option value="1"><%=LangPage.langPage.getSelect("levelflag_green")%></option>
		   <option value="2"><%=LangPage.langPage.getSelect("levelflag_org")%></option>
		   <option value="3"><%=LangPage.langPage.getSelect("levelflag_red")%></option>
		   <option value="0"><%=LangPage.langPage.getSelect("levelflag_unknow")%></option>
		   </select>
	    </td>
	</tr>
	</form>
	<tr>
		<td class="td_editbutton" colspan="4">
			<a href="#" onclick="updateSubmit();"><img src="../<%=LangPage.langPage.getButton_img_path()%>next_001.gif"   border="0" align="top" vspace="1" /></a>&nbsp;&nbsp;
			<a href="#" onclick="updateCancel();"><img src="../<%=LangPage.langPage.getButton_img_path()%>cancel_001.gif"   border="0" align="top" vspace="1" /></a>
		</td>
	</tr>
</table>
</div>
<div id="tb_mfupdate" class="datainfo">
<div align="center" id="Allmflist"
	style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
</div>
</div>

</body>
	<!-- 手机厂商列表显示区域 -->
	<div id="tb_mf" class="datainfo">
		<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
			<tr>
				<td class="td_buttonbar" valign="middle" style="font-size:9pt;"><%=LangPage.langPage.getSelect("search_searmf")%>

					<input type="text" class="input_edit"  name="SearchMFByName">
					<a href="#" onclick="searchMFByName();"><img src="../<%=LangPage.langPage.getButton_img_path()%>search_003.gif"   border="0" align="top" vspace="1" /></a>
				</td>
			</tr>
		</table>
		<div align="center" id="mflist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		</div>
	</div>
</html>
