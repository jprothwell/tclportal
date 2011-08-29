	//检查输入内容的长度
	function checkLength(name,length){
		var maxlen=length;
		var bytes = getBytes(document.all[name].value);
		if (event.keyCode != 8 && event.keyCode != 46 && event.keyCode != 37 && event.keyCode != 39 && event.keyCode != 38 && event.keyCode != 40){
			if (bytes.length >= maxlen){
				event.returnValue = false;
				document.all[name].value = document.all[name].value.substring(0,maxlen);
			}
		}
	}

	function checkLength1(name,length){
		var maxlen=length;
		if (event.keyCode != 8 && event.keyCode != 46 && event.keyCode != 37 && event.keyCode != 39 && event.keyCode != 38 && event.keyCode != 40){
			if (document.all[name].value.length >= maxlen){
				event.returnValue = false;
				document.all[name].value = document.all[name].value.substring(0,maxlen);
			}
		}
	}
	
	function getBytes(chrList){
		var bytes = [];
		for(var i = 0;i<chrList.length;i++){
			c = "";
			ch = chrList.charAt(i);
			execScript("c = Hex(Asc(ch))","vbscript");
			if(c.length == 2){
				bytes.push(c);
			}else if(c.length == 4){
				bytes.push(c.substring(0,2));
				bytes.push(c.substring(2,4));
			}
    }
		return bytes;
	}
	
	//输入整数数据:0--9,'-'
	function enterInteger(){
		if ((event.keyCode < 48 || event.keyCode > 57) && (event.keyCode < 96 || event.keyCode > 105) && event.keyCode != 189 && event.keyCode != 45 && event.keyCode != 109 && event.keyCode != 8 && event.keyCode != 46 && event.keyCode != 37 && event.keyCode != 39 && event.keyCode != 38 && event.keyCode != 40){
			event.returnValue = false;
		}
	}

	//输入无符号整型数据:0--9
	function enterUnsigned() {
		if ((event.keyCode < 48 || event.keyCode > 57) && (event.keyCode < 96 || event.keyCode > 105) && event.keyCode != 8 && event.keyCode != 46 && event.keyCode != 37 && event.keyCode != 39 && event.keyCode != 38 && event.keyCode != 40){
			event.returnValue = false;
		}
	}

	//输入浮点类型的数据:0--9,'.','-'
	function enterFloat(){
		if ((event.keyCode < 48 || event.keyCode > 57) && (event.keyCode < 96 || event.keyCode > 105) && event.keyCode != 189 && event.keyCode != 190 && event.keyCode != 45 && event.keyCode != 46 && event.keyCode != 109 && event.keyCode != 110 && event.keyCode != 8 && event.keyCode != 46 && event.keyCode != 37 && event.keyCode != 39 && event.keyCode != 38 && event.keyCode != 40){
			event.returnValue = false;
		}
	}
	