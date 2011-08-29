var pop_menu_count = 0;
		
function PopMenu(){
	var name = "PopMenu_New";
	var itemCount = 0;
	var items = new Array();
	
	this.addItem = function(caption,icon,call){
		var item = new Array();
		item.push(caption);
		item.push(icon);
		item.push(call);
		items.push(item);
		itemCount = itemCount+1;
	}
	
	this.create = function(){
		this.name = "PopMenu_" + pop_menu_count;
		pop_menu_count = pop_menu_count + 1;

		strFrame = "<div id='"+this.name+"' class='popmenu_div' style='visibility:hidden;'>";
		strFrame = strFrame + "</div>";
		strInfo = "<table border='0' cellpadding='0' cellspacing='0' class='popmenu_table'>";
		for(i=0;i<itemCount;i++){
			if(items[i][0] == ""){
				strInfo = strInfo + "<tr>";
				strInfo = strInfo + "<td class='popmenu_split_icon_td'></td>";
				strInfo = strInfo + "<td class='popmenu_split_td'><img style='border-bottom:1px solid #7E7E81;width:100%;height:0px;'></td>";
				strInfo = strInfo + "</tr>";
			}else{
				strInfo = strInfo + "<tr onmouseover=\"select_popmenu('"+this.name+"','"+i+"');\" onmouseout=\"unselect_popmenu('"+this.name+"','"+i+"');\">";
				if(items[i][1] == "")
					strInfo = strInfo + "<td id='"+this.name+"_icon_"+i+"' class='popmenu_icon_td'>&nbsp;</td>";
				else
					strInfo = strInfo + "<td id='"+this.name+"_icon_"+i+"' align='center' valign='middle' class='popmenu_icon_td'><img src='"+items[i][1]+"'></img></td>";
				if(items[i][2] == "")
					strInfo = strInfo + "<td id='"+this.name+"_caption_"+i+"' class='popmenu_caption_td' onclick=\"document.all['"+this.name+"'].style.visibility='hidden';\">"+items[i][0]+"</td>";
				else
					strInfo = strInfo + "<td id='"+this.name+"_caption_"+i+"' class='popmenu_caption_td' onclick=\"document.all['"+this.name+"'].style.visibility='hidden';"+items[i][2]+"();\">"+items[i][0]+"</td>";			
				strInfo = strInfo + "</tr>";
			}
		}
		strInfo = strInfo + "</table>";
		var NewNode = document.createElement(strFrame);
		NewNode.innerHTML = strInfo;
		document.body.appendChild(NewNode);
	}
	
	this.show = function(){
		document.all[this.name].style.left = event.clientX;
		document.all[this.name].style.top = event.clientY;
		document.all[this.name].style.visibility = "visible";
	}

	this.hide = function(){
		document.all[this.name].style.visibility = "hidden";
	}
}

function select_popmenu(name,index){
	document.all[name+"_icon_"+index].className = "popmenu_icon_td1";
	document.all[name+"_caption_"+index].className = "popmenu_caption_td1";
}

function unselect_popmenu(name,index){
	document.all[name+"_icon_"+index].className = "popmenu_icon_td";
	document.all[name+"_caption_"+index].className = "popmenu_caption_td";
}
