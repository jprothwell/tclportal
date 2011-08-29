/**************************************
	* 自定义JavaScript常用类
	* 作者：Steven Chen
	* EMail：stevenchen_1977@hotmail.com
	* 版本：1.0
	*************************************/

function HashMap(){
	var size = 0;	//大小
	var entry = new Object();	//保存对象
	
	this.put = function(key,value){
		if(!this.containsKey(key)){
			size ++ ;
		}
		entry[key] = value;
	}	//存
    
	this.get = function(key){
		return this.containsKey(key) ? entry[key] : null;
	}	//取
    
	this.remove = function(key){
		if(this.containsKey(key)&&(delete entry[key])){
			size --;
		}
	}	//删除
    
	this.containsKey = function(key){
		return (key in entry);
	}	//是否包含 Key
    
	this.containsValue = function(value){
		for(var prop in entry){
			if(entry[prop] == value){
				return true;
			}
		}
		return false;
	}	//是否包含 Value
    
	this.values = function(){
		var values = new Array();
		for(var prop in entry){
			values.push(entry[prop]);
		}
		return values;
	}	//所有 Value
    
	this.keys = function(){
		var keys = new Array();
		for(var prop in entry){
			keys.push(prop);
		}
		return keys;
	}	//所有 Key
    
	this.size = function(){
		return size;
	}	//size
    
	this.clear = function(){
		size = 0;
		entry = new Object();
	}	//清空
}//HashMap
 
