/**************************************
	* �Զ���JavaScript������
	* ���ߣ�Steven Chen
	* EMail��stevenchen_1977@hotmail.com
	* �汾��1.0
	*************************************/

function HashMap(){
	var size = 0;	//��С
	var entry = new Object();	//�������
	
	this.put = function(key,value){
		if(!this.containsKey(key)){
			size ++ ;
		}
		entry[key] = value;
	}	//��
    
	this.get = function(key){
		return this.containsKey(key) ? entry[key] : null;
	}	//ȡ
    
	this.remove = function(key){
		if(this.containsKey(key)&&(delete entry[key])){
			size --;
		}
	}	//ɾ��
    
	this.containsKey = function(key){
		return (key in entry);
	}	//�Ƿ���� Key
    
	this.containsValue = function(value){
		for(var prop in entry){
			if(entry[prop] == value){
				return true;
			}
		}
		return false;
	}	//�Ƿ���� Value
    
	this.values = function(){
		var values = new Array();
		for(var prop in entry){
			values.push(entry[prop]);
		}
		return values;
	}	//���� Value
    
	this.keys = function(){
		var keys = new Array();
		for(var prop in entry){
			keys.push(prop);
		}
		return keys;
	}	//���� Key
    
	this.size = function(){
		return size;
	}	//size
    
	this.clear = function(){
		size = 0;
		entry = new Object();
	}	//���
}//HashMap
 
