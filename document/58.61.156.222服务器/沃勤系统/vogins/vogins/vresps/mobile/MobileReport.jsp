<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangAction"%>
<%@ page import="com.language.langdata.LangDBTable"%>
<%@ page import="com.vogins.sps.db.mobile.Mobile"%>
<%@ page import="com.vogins.sps.db.mobile.MFPartner"%>
<%
	Mobile mob = new Mobile();
	MFPartner mf = new MFPartner();
%>
<html>

<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<TITLE><%=LangPage.langPage.getPageTitle("MobileReport")%></TITLE>
<meta http-equiv="Pragma" content="no-cache">
<link rel="stylesheet" type="text/css" href="../css/jwdf_main.css">
<link rel="stylesheet" type="text/css" href="../css/jwdf_swin.css">
<SCRIPT language="JavaScript" type="text/javascript"
	src="../js/jwdf_util.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_xml.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_view.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_swin.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>sps_workflow.js"></SCRIPT>
<script language=javascript>
   
<!----------------读取指定厂商的机型----------------------->
		function showMobile(){
			listPageURL.put('mobilelist','../GetMFMobileList.do?index=#index#');
			openPage('mobilelist','1');
		}
<!------------------------------------------------------------->

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
				if(name == "<%=mob.getAliasByFiled("MobileId")%>") DetaileMobile.MobileId.value = value;
				else if(name == "<%=mob.getAliasByFiled("MFId")%>") DetaileMobile.MFId.value = value;
				else if(name == "<%=mob.getAliasByFiled("MobileName")%>")document.all["MobileName"].innerHTML = value;
				else if(name == "<%=mob.getAliasByFiled("UserAgent")%>") document.all["UserAgent"].innerHTML = value;
				else if(name == "<%=mob.getAliasByFiled("InputType")%>"){    
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
				else if(name == "<%=mob.getAliasByFiled("ScreenWidth")%>") document.all["ScreenWidth"].innerHTML = value;
				else if(name == "<%=mob.getAliasByFiled("ScreenHeight")%>") document.all["ScreenHeight"].innerHTML = value;
				else if(name == "<%=mob.getAliasByFiled("VREVersion")%>")document.all["VREVersion"].innerHTML = value; 
				else if(name == "<%=mob.getAliasByFiled("MTKVersion")%>") document.all["MTKVersion"].innerHTML = value;
				else if(name == "<%=mob.getAliasByFiled("MemorySize")%>")  document.all["MemorySize"].innerHTML = value; 
		       else if(name == "<%=mob.getAliasByFiled("FileExtName")%>")document.all["FileExtName"].innerHTML = value; 
		       else if(name=="<%=mob.getAliasByFiled("AppListType")%>"){
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
<!------------------页面初始化---------------------->
		var detailHTML = "";
		
		function init(){
			detailHTML = document.all["tb_detail"].innerHTML;
			document.all["tb_detail"].innerHTML = "";
			showMobile();
			initList();
		}
		function initList(){
		
			listIndex.put('mobilelist','1');
			listPageURL.put('mobilelist','');
			//listDetailURL.put('mobilelist','../GetMobileInfo.do?MobileId=#id#');
			listCurrentId.put('mobilelist','');
			listCurrentKey.put('mobilelist','');
			//listDetailWidth.put('mobilelist','350');
			//listDetailHeight.put('mobilelist','500');
			listListXSL.put('mobilelist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('mobilelist','../xsl/jwdf_sdetail.xsl');
			listDblClickEvent.put('mobilelist',ShowdetailInfo);
		
		}

	</script>
</head>

<body onload="init();">
<!-- 页面标题 -->
<table class="table_pagetitle" border="0" cellspacing="0"
	cellpadding="0" align="center">
	<tr>
		<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("MobileReport")%></td>
	</tr>
</table>

	<center>
		<div align="center" id="mobilelist"
			style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
		</div>
	  	</center>
	
<!-- 详细信息显示表单 -->
<div align="center" id="tb_detail" class="datainfo"
	style="background-color:white;">
<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
	<form method="POST" name="DetaileMobile" class="editform"><input
		type="hidden" name="MobileId" value=""> <input type="hidden"
		name="MFId" value="">
	<tr>
		<td class="td_edittitle" width="80"><%=mob.getAliasByFiled("MobileName")%></td>
		<td id="MobileName" class="td_editcontent" width="200"></td>
		<td class="td_edittitle" width="80"><%=mob.getAliasByFiled("UserAgent")%></td>
		<td id="UserAgent" class="td_editcontent" width="200"></td>
	</tr>
	<tr>
		<td class="td_edittitle" width="100"><%=mob.getAliasByFiled("VREVersion")%></td>
		<td id="VREVersion" class="td_editcontent" width="200"></td>
		<td class="td_edittitle" width="100"><%=mob.getAliasByFiled("MTKVersion")%></td>
		<td id="MTKVersion" class="td_editcontent" width="200"></td>
	</tr>
	<tr>
		<td class="td_edittitle" width="80"><%=mob.getAliasByFiled("FileExtName")%></td>
		<td id="FileExtName" class="td_editcontent" width="200">
		<td class="td_edittitle" width="80" nowrap><%=mob.getAliasByFiled("MemorySize")%></td>
		<td id="MemorySize" class="td_editcontent" width="200"></td>
	</tr>
	<tr>
		<td class="td_edittitle" width="80"><%=mob.getAliasByFiled("ScreenHeight")%></td>
		<td id="ScreenHeight" class="td_editcontent" width="200"></td>
		<td class="td_edittitle" width="80"><%=mob.getAliasByFiled("ScreenWidth")%></td>
		<td id="ScreenWidth" class="td_editcontent" width="200"></td>
	</tr>
	<tr>
		<td class="td_edittitle" width="80"><%=mob.getAliasByFiled("InputType")%></td>
		<td id="InputType" class="td_editcontent" width="200"></td>
		<td class="td_edittitle" width="80"><%=mob.getAliasByFiled("AppListType")%></td>
		<td id="AppListType" class="td_editcontent" width="200"></td>
	</tr>
	<tr>
	   <td class="td_edittitle" width="80"><%=mob.getAliasByFiled("Remark")%></td>
		<td id="Remark" class="td_editcontent" width="200" colspan="3"></td>
	</tr>
	</form>
</table>
</div>
</body>

</html>
