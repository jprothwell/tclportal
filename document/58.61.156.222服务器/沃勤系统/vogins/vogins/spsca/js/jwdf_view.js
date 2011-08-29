
var listIndex = new HashMap();
var listPageURL = new HashMap();
var listDetailURL = new HashMap();
var listCurrentId = new HashMap();
var listCurrentKey = new HashMap();
var listDetailWidth = new HashMap();
var listDetailHeight = new HashMap();
var listListXSL = new HashMap();
var listDetailXSL = new HashMap();
var listClickEvent = new HashMap();
var listDblClickEvent = new HashMap();
var listPopMenu = new HashMap();

function clickRow(area,id,key){
	var tds=document.all[area+"tr"+id].getElementsByTagName("td");
	if(listCurrentId.get(area)==null || listCurrentId.get(area)==""){
		for(i=0;i<tds.length;i++){
			tds[i].className="td_listcontent0";
		}
		listCurrentId.put(area,id);
		listCurrentKey.put(area,key);
	}else{
		var tds0=document.all[area+"tr"+listCurrentId.get(area)].getElementsByTagName("td");
		for(i=0;i<tds0.length;i++){
			tds0[i].className="td_listcontent";
		}
		for(i=0;i<tds.length;i++){
			tds[i].className="td_listcontent0";
		}
		listCurrentId.put(area,id);
		listCurrentKey.put(area,key);
	}
	var event = listClickEvent.get(area);
	if(event != null){
		new event;
	}
}

function pageEnterUnsigned() {
	if ((event.keyCode < 48 || event.keyCode > 57) && (event.keyCode < 96 || event.keyCode > 105) && event.keyCode != 8 && event.keyCode != 46 && event.keyCode != 37 && event.keyCode != 39 && event.keyCode != 38 && event.keyCode != 40){
		event.returnValue = false;
	}
}

function openEnterPage(area,index,max){
	if(index == "") index = listIndex.get(area);
	if((index-0) > (max-0)){
		alert('超出范围！');
	}else{
		openPage(area,index);
	}
}

function openPage(area,index){
	if(index==null || index=='') index = '1';
	listIndex.put(area,index);
	url = listPageURL.get(area);
	if(url==null || url==''){
	}else{
		url=url.replace(/#index#/g,index);
		sendG(url,getListResult,area);
	}
}

function getListResult(cartXML,area){
	var xsl = loadXSL(listListXSL.get(area));
	xsl.loadXML(xsl.xml.replace(/#areaname#/g,area));
	document.all[area].innerHTML = cartXML.transformNode(xsl);
	listCurrentId.put(area,"");
	listCurrentKey.put(area,"");
}

function showDetail(area,id){
	url = listDetailURL.get(area);
	if(url==null || url==''){
	}else{
		url=url.replace(/#id#/g,id);
		sendG(url,detailResult,area);
	}
	var event = listDblClickEvent.get(area);
	if(event != null){
		new event;
	}
}

function detailResult(cartXML,area){
	var xsl = loadXSL(listDetailXSL.get(area));
	var cpwindow = new SimpleWindow();
	cpwindow.Create('detail_window_'+area,'详细信息',listDetailWidth.get(area),listDetailHeight.get(area),cartXML.transformNode(xsl));
	cpwindow.Show();
}

function showPopMenu_List(area,id,key){
	clickRow(area,id,key);
	var popmenu_temp = listPopMenu.get(area);
	if(popmenu_temp != null){
		popmenu_temp.show();
	}
}

var treeCurrentId = new HashMap();
var treeCurrentName = new HashMap();
var treeCurrentParent = new HashMap();
var treeCurrentChild = new HashMap();
var treeSubURL = new HashMap();
var treeSubInfo = new HashMap();
var treeLeafURL = new HashMap();
var treeLeafInfo = new HashMap();
var treeSubXSL = new HashMap();
var treeLeafXSL = new HashMap();
var treeLeafEvent = new HashMap();
var treePopMenu = new HashMap();

function clickLeaf(area,id,child,parent,name){
	var cur_id = treeCurrentId.get(area);
	if(cur_id!=null && cur_id!="" && cur_id!="0" && cur_id!="00"){
		document.all[area+"td"+cur_id].style.backgroundColor="";
		document.all[area+"td"+cur_id].style.color="black";
	}
	document.all[area+"td"+id].style.backgroundColor="#08246b";
	document.all[area+"td"+id].style.color="white";
	treeCurrentId.put(area,id);
	if(name == null || name == ""){
		treeCurrentName.put(area,id);
	}else{
		treeCurrentName.put(area,name);
	}
	treeCurrentParent.put(area,parent);
	treeCurrentChild.put(area,child);
	if(treeLeafInfo.get(area)!='0'){
		showLeafDetail(area,id);
	}
	var event = treeLeafEvent.get(area);
	if(event != null){
		new event;
	}
}

function showSub(area,id,child,parent,name){
	var cur_id = treeCurrentId.get(area);
	if(cur_id!=null && cur_id!="" && cur_id!="0" && cur_id!="00"){
		document.all[area+"td"+cur_id].style.backgroundColor="";
		document.all[area+"td"+cur_id].style.color="black";
	}
	if(id!=null && id!="" && id!="0" && id!="00"){
		document.all[area+"td"+id].style.backgroundColor="#08246b";
		document.all[area+"td"+id].style.color="white";
	}
	if(treeLeafInfo.get(area)!='0'){
		document.all[area+"_detail"].innerHTML = "&nbsp;";
	}
	if(treeSubInfo.get(area)=='1' && id != "" && id != "0" && id != "00"){
		showLeafDetail(area,id);
	}
	treeCurrentId.put(area,id);
	if(name == null || name == ""){
		treeCurrentName.put(area,id);
	}else{
		treeCurrentName.put(area,name);
	}
	treeCurrentParent.put(area,parent);
	treeCurrentChild.put(area,child);
	if(id != "" && id != "0" && id != "00"){
		if (document.all[area+"tr"+id].style.display == ""){
			document.all[area+"tr"+id].style.display = "none";
			document.all[area+"img_"+id].src = "../images/folderclosed.gif";
		}else{
			getSubData(area,id);
		}
	}else{
		getSubData(area,id);
	}
}

function getSubData(area,id){
	url = treeSubURL.get(area);
	if(url==null || url==''){
	}else{
		url=url.replace(/#id#/g,id);
		sendG(url,getSubTreeResult,area);
	}
}

function getSubTreeResult(cartXML,area){
	var xsl = loadXSL(treeSubXSL.get(area));
	xsl.loadXML(xsl.xml.replace(/#areaname#/g,area));
	var cur_id = treeCurrentId.get(area);
	if(cur_id == null || cur_id == '' || cur_id == '0') cur_id = '00';
	document.all[area+"td0"+cur_id].innerHTML = cartXML.transformNode(xsl);
	document.all[area+"tr"+cur_id].style.display = "";
	if(cur_id != "00")
		document.all[area+"img_"+cur_id].src = "../images/folderopen.gif";
}
		
function showLeafDetail(area,id){
	url = treeLeafURL.get(area);
	if(url==null || url==''){
	}else{
		url=url.replace(/#id#/g,id);
		sendG(url,detailLeafResult,area);
	}
}

function detailLeafResult(cartXML,area){
	var xsl = loadXSL(treeLeafXSL.get(area));
	document.all[area+"_detail"].innerHTML = cartXML.transformNode(xsl);
}

function showPopMenu_Tree(area,id,child,parent){
	var cur_id = treeCurrentId.get(area);
	if(cur_id!=null && cur_id!="" && cur_id!="0" && cur_id!="00"){
		document.all[area+"td"+cur_id].style.backgroundColor="";
		document.all[area+"td"+cur_id].style.color="black";
	}
	if(id!=null && id!="" && id!="0" && id!="00"){
		document.all[area+"td"+id].style.backgroundColor="#08246b";
		document.all[area+"td"+id].style.color="white";
	}
	if(treeLeafInfo.get(area)!='0'){
		document.all[area+"_detail"].innerHTML = "&nbsp;";
	}
	if(treeSubInfo.get(area)=='1' && id != "" && id != "0" && id != "00"){
		showLeafDetail(area,id);
	}
	treeCurrentId.put(area,id);
	treeCurrentName.put(area,id);
	treeCurrentParent.put(area,parent);
	treeCurrentChild.put(area,child);

	var event = treeLeafEvent.get(area);
	if(event != null){
		new event;
	}

	var popmenu_temp = treePopMenu.get(area);
	if(popmenu_temp != null){
		popmenu_temp.show();
	}
}
