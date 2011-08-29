<%@ page contentType="text/html;charset=UTF-8"%>   
<%@ page import="com.language.langdata.LangPage"%>
<%@ page import="com.language.langdata.LangAction"%>
<%@ page import="com.language.langdata.LangDBTable"%>
<html>

<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<TITLE><%=LangPage.langPage.getPageTitle("report_usr")%></TITLE>
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

    	<!-----------------------显示汇总结果--------------------------->
		function showReport(){
            if(SearchForm.StartDate.value==''){
              alert("<%=LangAction.langAction.getNo_select_begin()%>");
              return false;
            }else if(SearchForm.EndDate.value==''){
              alert("<%=LangAction.langAction.getNo_select_end()%>");
              return false;
            }else{
			if(document.all["reporcontent"].value == "1"&&document.all["reporttype"].value=="1"){       // 注册用户按日期
				listPageURL.put('reportlist','../RegUser_Date.do?'+getP(SearchForm)+'&index=#index#');
				openPage('reportlist','1');
			}else if(document.all["reporcontent"].value == "1"&&document.all["reporttype"].value=="2"){  //注册用户按时段
				listPageURL.put('reportlist','../RegUser_Hour.do?'+getP(SearchForm)+'&index=#index#');
				openPage('reportlist','1');
			}else if(document.all["reporcontent"].value == "2"&&document.all["reporttype"].value=="1"){   //计费用户按日期
				listPageURL.put('reportlist','../FeeUser_Date.do?'+getP(SearchForm)+'&index=#index#');
				openPage('reportlist','1');
			}else if(document.all["reporcontent"].value == "2"&&document.all["reporttype"].value=="2"){   //计费用户按时段
				listPageURL.put('reportlist','../Feeuser_Hour.do?'+getP(SearchForm)+'&index=#index#');
				openPage('reportlist','1');
			}else if(document.all["reporcontent"].value == "3"&&document.all["reporttype"].value=="1"){   //活跃用户按日期
				listPageURL.put('reportlist','../ActUser_Date.do?'+getP(SearchForm)+'&index=#index#');
				openPage('reportlist','1');
			}else if(document.all["reporcontent"].value == "3"&&document.all["reporttype"].value=="2"){   //活跃用户按时段
				listPageURL.put('reportlist','../ActUser_Hour.do?'+getP(SearchForm)+'&index=#index#');
				openPage('reportlist','1');
			}
			}
		}

 
<!----------------------页面初始化----------------------->
		var reportdetailHTML = "";
		function init(){
			
			initList();
		}

		function initList(){
			listIndex.put('reportlist','1');
			listPageURL.put('reportlist','');
			listDetailURL.put('reportlist','');
			listCurrentId.put('reportlist','');
			listCurrentKey.put('reportlist','');
			listDetailWidth.put('reportlist','400');
			listDetailHeight.put('reportlist','300');
			listListXSL.put('reportlist','../<%=LangPage.langPage.getXsl_path()%>jwdf_list.xsl');
			listDetailXSL.put('reportlist','');

		
		}
<!------------------------------------------------------------->
	</script>
</head>

<body onload="init();">
	<!-- 页面标题 -->
	<table class="table_pagetitle" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr>
		<td class="td_pagetitle" valign="middle"><%=LangPage.langPage.getPageTitle("report_usr")%></td>
	</tr>
	</table>

	<!-- 查询条件 -->
	<table width="90%" border="0" cellspacing="0" cellpadding="0" align="center">
	<tr><td height="5"></td></tr>
	<tr>
		<td valign="middle" style="font-size:9pt;color:#4796ee;">
			<form method="POST" name="SearchForm" class="editform">
			
			<b><%=LangPage.langPage.getSearch("search_conditions")%></b><%=LangPage.langPage.getSearch("search_startdate")%><input class="input_edit" type="text" name="StartDate" style="width:80;" value="">&nbsp;<a href="#" onclick="LtCalendar.create('StartDate',68,165);"><img src="../<%=LangPage.langPage.getButton_img_path()%>point_001.gif"   border="0" align="top" vspace="1" /></a>
			&nbsp;&nbsp;<%=LangPage.langPage.getSearch("search_enddate")%><input class="input_edit" type="text" name="EndDate" style="width:80;" value="">&nbsp;<a href="#" onclick="LtCalendar.create('EndDate',68,345);"><img src="../<%=LangPage.langPage.getButton_img_path()%>point_001.gif"   border="0" align="top" vspace="1" /></a><br/>
			<b>			</b>&nbsp;&nbsp;&nbsp;&nbsp;<%=LangPage.langPage.getSearch("search_content")%><select name="reporcontent" ><option value="1"><%=LangPage.langPage.getSearch("search_newuser")%></option><option value="2"><%=LangPage.langPage.getSearch("search_feeuser")%></option><option value="3"><%=LangPage.langPage.getSearch("search_actuser")%></option></select>
			&nbsp;&nbsp;<%=LangPage.langPage.getSearch("search_type")%><select name="reporttype" ><option value="1"><%=LangPage.langPage.getSearch("search_bydate")%></option><option value="2"><%=LangPage.langPage.getSearch("search_byhour")%></option></select>
			&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href="#" onclick="showReport();"><img src="../<%=LangPage.langPage.getButton_img_path()%>search_001.gif"   border="0" align="top" vspace="1"/></a>&nbsp;&nbsp;
			</form>
		</td>
	</tr>
	<tr><td height="5"></td></tr>
	</table>

	<!-- 查询结果显示区域 -->
	<center>
	<div align="center" id="reportlist" style="width:90%; overflow-x:auto; overflow-y:auto; scrollbar-face-color:#efebef;">
	</div>
	</center>
</body>

</html>
