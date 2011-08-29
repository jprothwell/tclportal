var simple_windows = new HashMap();

function SimpleWindow(){
	this.top = 0;
	this.left = 0;
	this.width = 200;
	this.height = 150;
	this.name = "";
	this.title = "";
	this.html = "";
	this.Create = Create;
	this.Show = Show;
	this.Close = Close;
	this.Repaint = Repaint;
	this.OpenURL = OpenURL;
	
	function Create(name,title,width,height,html){
		var temp = name;
		if(name == "") name = "NewWindow";
		if(!simple_windows.containsKey("window_"+temp)){
			if(name == ""){
				this.name = "NewWindow";
			}else{
				this.name = name;
			}
			if(title == ""){
				this.title = "新窗口";
			}else{
				this.title = title;
			}
			this.width = width;
			this.height = height;
			this.html = html;
			this.left = (document.body.offsetWidth-this.width)/2;
			this.top = (document.body.offsetHeight-this.height)/2;
	
			strFrame = "<div id='window_" + this.name + "' class='swindow_div' style='width:" + this.width + ";height:" + this.height + ";display:none;left:" + this.left + ";top:" + this.top + ";'>";
			strFrame = strFrame + "</div>";
			
			strWindow = "<table class='swindow_table'  cellpadding='0' cellspacing='0' align='center'>";
			strWindow = strWindow + "<tr>";
			strWindow = strWindow + "<td id='title1_" + this.name + "' class='swindowtitle_td' valign='middle' align='center' width='18'><div class='swindowtitle_div1'></div></td>";
			strWindow = strWindow + "<td id='title2_" + this.name + "' class='swindowtitle_td' width='100%'>" + this.title + "</td>";
			strWindow = strWindow + "<td id='title3_" + this.name + "' class='swindowtitle_td' valign='middle' align='center' width='14'><div class='swindowtitle_div2' onclick=\"win_close('" + this.name + "');\"></div></td>";
			strWindow = strWindow + "</tr>";
			strWindow = strWindow + "<tr>";
			strWindow = strWindow + "<td valign='top' class='swindowmain_td' colspan='3' width='100%' height='100%'>";
			strWindow = strWindow + "<div id='windowmain_" + this.name + "' class='swindowmain_div' style='width:100%;height:100%;'>";
			strWindow = strWindow + html;
			strWindow = strWindow + "</div>";
			strWindow = strWindow + "</td>";
			strWindow = strWindow + "</tr>";
			strWindow = strWindow + "</table>";
	
			var NewNode = document.createElement(strFrame);
			NewNode.innerHTML = strWindow;
			document.body.appendChild(NewNode);
			simple_windows.put("window_"+this.name,"1");
		}
	}
	
	function Repaint(html){
		this.html = html;
		document.all["windowmain_"+this.name].innerHTML = this.html;
	}
	
	function OpenURL(href){
		var frame = "<iframe name='IFrame_"+this.name+"' frameborder='0' style='width:100%;height:100%;' scrolling='auto' src=''></iframe>";
		document.all["windowmain_"+this.name].innerHTML = frame;
		window.open(href,'IFrame_'+this.name);
	}
	
	function Show(){
		if(this.name != ""){
			document.all["window_" + this.name].style.display = "";
		}
	}
	
	function Close(){
		win_close(this.name);
	}
}

/*--------------窗口关闭按钮处理 Start------------------*/
function win_close(winname){
	var allWindows=document.body.getElementsByTagName("div");
	for(i=0;i<allWindows.length;i++){
		if(allWindows[i].id==("window_" + winname)){
			document.body.removeChild(allWindows[i]);
			simple_windows.remove("window_" + winname);
		}
	}
}
/*--------------窗口关闭按钮处理 End------------------*/
