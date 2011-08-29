<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangDBTable"%>
<%@ page import="com.vogins.sps.db.touse.*"%>
<%
 Touse touse = new Touse();
%>
<html>

<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<TITLE><%=LangPage.langPage.getPageTitle("user_touse")%></TITLE>
	<meta http-equiv="Pragma" content="no-cache">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_main.css">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_swin.css">
	<link rel="stylesheet" type="text/css" href="../css/jwdf_cal.css">
	<SCRIPT language="JavaScript" type="text/javascript" src="../js/jwdf_util.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_xml.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_view.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_swin.js"></SCRIPT>
	<SCRIPT language="JavaScript" type="text/javascript" src="../<%=LangPage.langPage.getJs_path()%>jwdf_cal.js"></SCRIPT>
	<script language=javascript>
<!----------------读取用户投诉记录----------------------->
		function showTouse(){
			listPageURL.put('touselist','../SearchTouse.do?'+getP(SearchForm)+'&index=#index#');
			openPage('touselist','1');
		}
<!------------------------------------------------------------->

<!-------------------修投诉信息-------------------------->
		var updatewindow = new SimpleWindow();
		function showUpdate(){
			if(listCurrentKey.get('touselist')==""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=touse.getAliasByFiled("TouseId")%>");
				//alert("请先指定要修改的用户投诉！");
				return;
			}else{
				updatewindow.Create('update_window','<%=LangPage.langPage.getWindowsTitle("mobile_updatetouse")%>',280,302,updateHTML);
				updatewindow.Show();
				sendG("../GetTouseInfo.do?TouseId="+listCurrentKey.get('touselist'),getUpdate);
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
			
				if(name == "<%=touse.getAliasByFiled("TouseId")%>") UpdateTouse.TouseId.value = value;
				else if(name == "<%=touse.getAliasByFiled("SubscriberId")%>") UpdateTouse.SubscriberId.value = value;
				else if(name == "<%=touse.getAliasByFiled("Mobile")%>") UpdateTouse.Mobile.value = value;
				else if(name == "<%=touse.getAliasByFiled("MobileId")%>") UpdateTouse.MobileId.value = value;
				else if(name == "<%=touse.getAliasByFiled("MobileName")%>") UpdateTouse.MobileName.value = value;
				else if(name == "<%=touse.getAliasByFiled("AppName")%>") UpdateTouse.AppName.value = value;
				else if(name == "<%=touse.getAliasByFiled("TouseContent")%>") UpdateTouse.TouseContent.value = value;
				else if(name == "<%=touse.getAliasByFiled("Solution")%>") UpdateTouse.Solution.value = value;
				else if(name == "<%=touse.getAliasByFiled("Compensation")%>") UpdateTouse.Compensation.value = value;
				else if(name == "<%=touse.getAliasByFiled("Remark")%>") UpdateTouse.Remark.value = value;
				else if(name == "<%=touse.getAliasByFiled("TouseStatus")%>"){
					for(var j=0;j<UpdateTouse.TouseStatus.length;j++){
						if(UpdateTouse.TouseStatus[j].value == value)
							UpdateTouse.TouseStatus[j].checked = true;
					}
					if(value=='2'){
						updatewindow.Close();
						alert('用户已经享受补偿，该投诉不能修改！');
					}
				}
			}
		}
		function updateSubmit(){
			sendP("../UpdateTouse.do",getP(UpdateTouse),updateResult);
		}
		function updateResult(){
			updatewindow.Close();
			openPage('touselist',listIndex.get('touselist'));
		}
<!------------------------------------------------------------->

<!-------------------删除投诉---------------------->
		function deleteObj(){
			if(listCurrentKey.get('touselist')==""){
				alert("<%=LangPage.langPage.getPlease_input()%><%=touse.getAliasByFiled("TouseId")%>");
				return;
			}else{
				if(confirm("<%=LangPage.langPage.getDelete_confirm()%>")){
					sendG("../DeleteTouse.do?TouseId="+listCurrentKey.get('touselist'),deleteResult);
				}
			}
		}
		function deleteResult(){
			openPage('touselist',listIndex.get('touselist'));
		}
<!------------------------------------------------------------->

<!------------------页面初始化---------------------->
		var updateHTML = "";
		function init(){
			updateHTML = document.all["tb_update"].innerHTML;
			document.all["tb_update"].innerHTML = "";
			initList();
			showTouse();
		}

		function initList(){
			listIndex.put('touselist','1');
			listPageURL.put('touselist','');
			listDetailURL.put('touselist','../GetTouseInfo.do?TouseId=#id#');
			listCurrentId.put('touselist','');
			listCurrentKey.put('touselist','');
			listDetailWidth.put('touselist','400');
			listDetailHeight.put('touselist','300');
			listListXSL.put('touselist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('touselist','../xsl/jwdf_sdetail.xsl');
		}
<!------------------------------------------------------------->
	</script>
</head>

<body onload="init();">
	<!-- 页面标题 -->
	<table class="table_pagetitle" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("user_touse")%></td>
	</tr>
	</table>

	<!-- 查询条件 -->
	<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr><td height="5"></td></tr>
	<tr>
		<td valign="middle" style="font-size:9pt;color:#4796ee;">
			<form method="POST" name="SearchForm" class="editform">
			<b><%=LangPage.langPage.getSearch("search_conditions")%></b><%=LangPage.langPage.getSearch("search_mobilenum")%><input class="input_edit" type="text" name="Mobile0" style="width:80;" value="">
			&nbsp;&nbsp;<%=LangPage.langPage.getSearch("search_userid")%><input class="input_edit" type="text" name="SubscriberId0" style="width:80;" value=""><br>
			<b>　　　　　</b><%=LangPage.langPage.getSearch("search_startdate")%><input class="input_edit" type="text" name="StartDate" style="width:80;" value="">&nbsp;<a href="#" onclick="LtCalendar.create('StartDate',68,165);"><img src="../<%=LangPage.langPage.getButton_img_path()%>point_001.gif"   border="0" align="top" vspace="1" /></a>
			&nbsp;&nbsp;<%=LangPage.langPage.getSearch("search_enddate")%><input class="input_edit" type="text" name="EndDate" style="width:80;" value="">&nbsp;<a href="#" onclick="LtCalendar.create('EndDate',68,345);"><img src="../<%=LangPage.langPage.getButton_img_path()%>point_001.gif"  border="0" align="top" vspace="1" /></a><br/>
			<b>　　　　　</b><%=LangPage.langPage.getSearch("search_status")%><select name="TouseStatus"><option value=""><%=LangPage.langPage.getSelect("status_all")%></option><option value="0"><%=LangPage.langPage.getSelect("status_continue")%></option><option value="1"><%=LangPage.langPage.getSelect("status_complete")%></option></select>
			&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href="#" onclick="showTouse();"><img src="../<%=LangPage.langPage.getButton_img_path()%>search_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			</form>
		</td>
	</tr>
	<tr><td height="5"></td></tr>
	</table>

	<!-- 投诉列表显示区域 -->
	<div align="center" id="touselist" style="width:100%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
	</div>
	
	<!-- 操作按钮 -->
	<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_buttonbar" valign="middle">
			<a href="#" onclick="showUpdate();"><img src="../<%=LangPage.langPage.getButton_img_path()%>update_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			<a href="#" onclick="deleteObj();"><img src="../<%=LangPage.langPage.getButton_img_path()%>delete_001.gif"   border="0" align="top" vspace="1"/></a>
		</td>
	</tr>
	</table>

	<!-- 修改投诉表单 -->
	<div align="center" id="tb_update" class="datainfo">
		<table class="table_edit" cellpadding="0" cellspacing="1" align="center">
		<form method="POST" name="UpdateTouse" class="editform">
			<input type="hidden" name="TouseId" value="">
		<tr>
			<td class="td_edittitle" width="80"><%=touse.getAliasByFiled("SubscriberId")%></td>
			<td class="td_editcontent" width="200"><input class="input_edit" style="width:100%;" readonly type="text" name="SubscriberId"></td>
		</tr>
		<tr>
			<td class="td_edittitle" width="80"><%=touse.getAliasByFiled("Mobile")%></td>
			<td class="td_editcontent" width="200"><input class="input_edit" style="width:100%;" readonly type="text" name="Mobile"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=touse.getAliasByFiled("MobileName")%></td>
			<td class="td_editcontent">
				<input class="input_edit" style="width:100%;" readonly type="text" name="MobileName">
				<input type="hidden" name="MobileId" value="">
			</td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=touse.getAliasByFiled("AppName")%></td>
			<td class="td_editcontent">
				<input class="input_edit" style="width:100%;" readonly type="text" name="AppName">
			</td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=touse.getAliasByFiled("TouseContent")%></td>
			<td class="td_editcontent"><textarea class="input_textarea" name="TouseContent"></textarea></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=touse.getAliasByFiled("Solution")%></td>
			<td class="td_editcontent"><textarea class="input_textarea" name="Solution"></textarea></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=touse.getAliasByFiled("Compensation")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="Compensation"></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=touse.getAliasByFiled("TouseStatus")%></td>
			<td class="td_editcontent">
				<input name="TouseStatus" type="radio" value="0" checked><%=LangPage.langPage.getSelect("status_continue")%>&nbsp;&nbsp;
				<input type="radio" name="TouseStatus" value="1"><%=LangPage.langPage.getSelect("status_complete")%></td>
		</tr>
		<tr>
			<td class="td_edittitle"><%=touse.getAliasByFiled("Remark")%></td>
			<td class="td_editcontent"><input class="input_edit" style="width:100%;" type="text" name="Remark"></td>
		</tr>
		</form>
		<tr>
				<td class="td_editbutton" colspan="2">
					<a href="#" onclick="updateSubmit();"><img src="../<%=LangPage.langPage.getButton_img_path()%>ok_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
					<a href="#" onclick="updateCancel();"><img src="../<%=LangPage.langPage.getButton_img_path()%>cancel_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
				</td>
			</tr>
		</table>
	</div>
</body>

</html>
