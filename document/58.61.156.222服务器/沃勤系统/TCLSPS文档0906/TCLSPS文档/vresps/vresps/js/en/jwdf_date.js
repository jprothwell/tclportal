	function initArray()  
	{  
		for(i=0;i<initArray.arguments.length;i++)  
			this[i]=initArray.arguments[i];  
	}  
	var isnMonths=new initArray("Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec");  
	var isnDays=new initArray("Sun","Mon","Tue","Wed","Thu","Fri","Sat","Sun");  
	today=new Date();  
	hrs=today.getHours();  
	min=today.getMinutes();  
	sec=today.getSeconds();  
	clckh=""+((hrs>12)?hrs-12:hrs);  
	clckm=((min<10)?"0":"")+min;clcks=((sec<10)?"0":"")+sec;  
	clck=(hrs>=12)?"AM":"PM";  
	var stnr="";  
	var ns="0123456789";  
	var a="";  

	function getFullYear(d)  
	{  
		yr=d.getYear();if(yr<1000)  
		yr+=1900;return yr;
	}  
	
	function getCurDate(){
		strDate ="Today: " + isnMonths[today.getMonth()]+" "+today.getDate() + "," + getFullYear(today)+ " " + isnDays[today.getDay()];
		return strDate;
	}
	
	function getCurTime(){
		return "LoginTime: " + hrs+":"+clckm+":"+clcks;
	}
