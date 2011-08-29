//�������������Ϣ�����Ƚ��ȳ�ԭ��˳��ִ�У�������������죬�ݲ�֧�ֲ�������
var reqtypes = new Array();
var urls = new Array();
var paras = new Array();
var cbs = new Array();
var areas = new Array();
var run = false;

//����һ��Request
function newX(){
	var req = false;
	if(window.XMLHttpRequest){
		req = new XMLHttpRequest();
    if (req.overrideMimeType) {
      req.overrideMimeType('text/xml');
    }
	}else if (window.ActiveXObject){
		try{
			req = new ActiveXObject("Msxml2.XMLHTTP");
		}catch (e1){
			try{
				req = new ActiveXObject("Microsoft.XMLHTTP");
			}catch (e2){}
		}
	}
	return req;
}

//����POST���󣬽������󱣴浽�������
function sendP(url,para,cb){
	reqtypes.push("POST");
	urls.push(url);
	paras.push(para);
	cbs.push(cb);
	areas.push(null);
	doSend();
}

//����GET���󣬽������󱣴浽�������
function sendG(url,cb,area){
	reqtypes.push("GET");
	urls.push(url);
	paras.push(null);
	cbs.push(cb);
	areas.push(area);
	doSend();
}

//�������������ĵ�һ������
function doSend(){
	if(!run && reqtypes.length>0){
		var type = reqtypes.shift();
		var url = urls.shift();
		var para = paras.shift();
		var cb = cbs.shift();
		var area = areas.shift();
		if(type == "POST"){
			run = true;
			showWaiting();
			var req = newX();
			var hf = getC(req,cb);
			req.onreadystatechange = hf;
			req.open("POST",urlP(url),true);
			req.setRequestHeader("Content-Type", "application/x-www-form-urlencoded;text/xml;charset=utf-8");
			req.send(para);
		}else if(type == "GET"){
			run = true;
			showWaiting();
			var req = newX();
			var hf = getC(req,cb,area);
			req.onreadystatechange = hf;
			req.open("GET",urlP(url),true);
			req.setRequestHeader("Content-Type", "text/xml;charset=utf-8");
			req.send(null);
		}
	}
}

//������Ӧ������
function getC(req, cb, area){
	return function(){
		if (req.readyState == 4){
			if (req.status == 200){
				run=false;
				closeWaiting();
				doSend();
				checkL(req.responseXML,cb,area);
			}else{
				alert("HTTP����: "+req.status);
				run=false;
				closeWaiting();
				doSend();
			}
		}
	}
}

//������URL�����һ���������,������ͬURL����ˢ�����ݵ�����
function urlP(url){
	if(url.indexOf("?")>0){
		var a = new Date();
		url = url+"&randomid="+a.getTime();
	}else{
		var a = new Date();
		url = url+"?randomid="+a.getTime();
	}
	return url;
}

//��鷵��xml�е�״̬,���ʧ�ܾ���ʾ��Ӧ�Ĵ�����Ϣ
function checkL(cartXML,cb,area){
	var cart = cartXML.getElementsByTagName("result")[0];
	var code = cart.getElementsByTagName("code")[0].firstChild.nodeValue;
	if(code=="9"){
		alert("û�е�¼���¼��ʱ�������µ�¼��");
		if(window.name == 'JWDFMainFrame'){
			window.parent.location.href="../login.htm";
		}else{
			window.location.href="login.htm";
		}
	}
	else if(code=="8"){
		alert("��û�и������Ȩ�ޣ�");
	}
	else if(code=="1"){
		cb(cartXML,area);
	}
	else if(code=="0"){
		var info = cart.getElementsByTagName("info")[0].firstChild.nodeValue;
		alert("����ʧ�ܣ�"+info);
	}
	else{
		alert("δ֪��Ӧ��");
	}
}

//ȡ��FORM�еĲ���
function getP(f){
	var p = "";
	for(i = 0; i < f.elements.length; i++){
		if(f.elements(i).name != ""){
			if(f.elements(i).type != "radio"){
				if(p != ""){
					p = p + "&" + f.elements(i).name + "=" + encodeURIComponent(f.elements(i).value);
				}else{
					p = f.elements(i).name + "=" + encodeURIComponent(f.elements(i).value);
				}
			}else{
				if(f.elements(i).checked){
					if(p != ""){
						p = p + "&" + f.elements(i).name + "=" + encodeURIComponent(f.elements(i).value);
					}else{
						p = f.elements(i).name + "=" + encodeURIComponent(f.elements(i).value);
					}
				}
			}
		}
	}
	return p;
}

//��ȡXSL�ļ�
function loadXSL(url){
	var xsldoc;
	if(document.implementation&&document.implementation.createDocument){
		xsldoc = document.implementation.createDocument("", "doc", null);
		xsldoc.load(url);
	}else if(window.ActiveXObject) {
		xsldoc = new ActiveXObject("Microsoft.XMLDOM");
		xsldoc.async = false;
		xsldoc.load(url);
	}
	return xsldoc;
}

//��ʾ�ȴ�������
function showWaiting(){
	strFrame = "<div align='center' valign='middle' id='jwdf_ajax_waiting' class='waitbar' style='width:150;height:35;left:" + (document.body.clientWidth-150)/2 + ";top:" + (document.body.clientHeight-35)/2 + ";'>";
	strFrame = strFrame + "</div>";
	if((window.location.href.indexOf('/login.htm')>0) || (window.location.href.indexOf('/index.htm')>0)){
		strInfo = "<table style='color:red;font-size:9pt;'><tr><td><img src='images/jwdf-loader.gif'></img></td><td>�����У����Ժ�...</td></tr></table>";
	}else{
		strInfo = "<table style='color:red;font-size:9pt;'><tr><td><img src='../images/jwdf-loader.gif'></img></td><td>�����У����Ժ�...</td></tr></table>";
	}
	var NewNode = document.createElement(strFrame);
	NewNode.innerHTML = strInfo;
	document.body.appendChild(NewNode);
	document.all["jwdf_ajax_waiting"].style.visibility = "visible";
}

//�رյȴ�������
function closeWaiting(){
	document.body.removeChild(document.all["jwdf_ajax_waiting"]);
}
