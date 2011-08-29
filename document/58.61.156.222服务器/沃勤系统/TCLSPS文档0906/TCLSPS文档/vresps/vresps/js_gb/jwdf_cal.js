var LtCalendar = new ltcalendar();

function ltcalendar()
{
	this.Node = "";
	this.HTML = "";
	this.top = 0;
	this.left = 0;
	this.object = "";
	this.show = false;
	this.create = create;
	this.hide = hide;
	
	function create(obj,ctop,cleft)
	{
		if(!this.show)
		{
			this.object = obj;
			this.top = ctop;
			this.left = cleft;
			this.Node = this.Node + "<div id=\"div_calendar" + "\" class=\"calendar_div\" style=\"display:none;\">";
			this.Node = this.Node + "</div>";
			this.HTML = callCalendar(this.object);
			var NewNode = document.createElement(this.Node);
			NewNode.innerHTML = this.HTML;
			document.body.appendChild(NewNode);
			document.all["div_calendar"].style.pixelTop = this.top;
			document.all["div_calendar"].style.pixelLeft = this.left;
			document.all["div_calendar"].style.display = "";
			this.show = true;
		}
		else
		{
			LtCalendar.hide();
		}
	}

	function hide()
	{
		document.body.removeChild(document.getElementById("div_calendar"));
		this.show = false;
	}
}

function julianDay( Y, M, D ){
	var y,m,d;
	y=parseInt(Y);
	m=parseInt(M);
	d=parseInt(D);
	
	var jy,ja,jm;
	if( y==0 ){
		alert("There was no year zero in the Julian calendar.");
		return "invalid";
	}
	if( y==1582 && m==10 && d>4 && d<15 ){
		alert("October 5th to 14th were skipped in October of 1582\nwhen Pope Gregory XIII implemented the calendar reforms\nof the commission headed by the Jesuit mathematician and astronomer\nChristoph Clavius.");
		return "invalid";
	}
	if(y<0) y++;
	if(m>2){
		jy=y;
		jm=m+1;
	}else{
		jy=y-1;
		jm=m+13;
	}
	
	var julian = Math.floor( Math.floor(365.25*jy) + Math.floor(30.6001*jm) + d + 1720995 );
	
	var gregorianStart = 15 + 31*( 10 + 12*1582 );
	
	if( d + 31*(m + 12*y) >= gregorianStart ){
		ja = Math.floor(0.01*jy);
		julian += 2 - ja + Math.floor(0.25*ja);
	}
	
	return julian;
}

function dayOfWeek( julian ){
	return (julian+1)%7;
}

function padWithZeros(number,length) {
	 var str = "" + number;
	 while( str.length < length ) str = '0' + str;
	 return str;
}

function formatISODate( year, month, day ){
	var delimiter="-";
	if(year<0){
		year= -year; year = "-" + padWithZeros(year,4);
	}else{
		year = padWithZeros(year,4);
	}
	return year + delimiter + padWithZeros(month,2) + delimiter + padWithZeros(day,2);
}

function setToday( objectId ){
	 
	var today = new Date();
	document.getElementById( objectId ).value = formatISODate( today.getFullYear(), today.getMonth()+1, today.getDate() );
	
}

function callCalendar( objectId ){
	var dateString=document.getElementById( objectId ).value;
	var re = new RegExp( '[/\.\ ]', 'gi' );
	dateString=dateString.replace( re, "-" );
	dateComponents=dateString.split("-");
	var year,month,day;
	year=dateComponents[0];
	month=dateComponents[1];
	day=dateComponents[2];
	return generateCalendar( year, month, day, objectId );
}

function setDate(day){
	year =document.getElementById("currentYear").value;
	month=document.getElementById("currentMonth").value;
	isoDateString=formatISODate(year,month,day);
	idString = document.getElementById("destinationId").value;
	document.getElementById( idString ).value=isoDateString;
	LtCalendar.hide();
//	window.close();
}

function previousYear(){
	year =parseInt(document.getElementById("currentYear").value);
	month=parseInt(document.getElementById("currentMonth").value);
	day  =parseInt(document.getElementById("currentDay").value);
	destination = document.getElementById("destinationId").value;
	year -= 1;
	if( year==0 ) year = -1;
	document.all["div_calendar"].innerHTML = generateCalendar(year,month,day,destination);
}

function previousMonth(){
	year =parseInt(document.getElementById("currentYear").value);
	month=parseInt(document.getElementById("currentMonth").value);
	day  =parseInt(document.getElementById("currentDay").value);
	destination = document.getElementById("destinationId").value;
	month -= 1;
	if(month<1){ 
		month = 12;
		year -= 1;
		if( year==0 ) year = -1;
	}
	document.all["div_calendar"].innerHTML = generateCalendar(year,month,day,destination);
}

function nextMonth(){
	year =parseInt(document.getElementById("currentYear").value);
	month=parseInt(document.getElementById("currentMonth").value);
	day  =parseInt(document.getElementById("currentDay").value);
	destination = document.getElementById("destinationId").value;
	month += 1;
	if(month>12){
		month = 1;
		year += 1;
		if( year==0 ) year = 1;
	}
	document.all["div_calendar"].innerHTML = generateCalendar(year,month,day,destination);
}

function nextYear(){
	year =parseInt(document.getElementById("currentYear").value);
	month=parseInt(document.getElementById("currentMonth").value);
	day  =parseInt(document.getElementById("currentDay").value);
	destination = document.getElementById("destinationId").value;
	year += 1;
	if( year==0 ) year = 1;
	document.all["div_calendar"].innerHTML = generateCalendar(year,month,day,destination);
}

function generateCalendar( Y, M, D, targetId ){
	
//	var Month = new Array("January","February","March","April","May","June","July","August","September","October","November","December");
	
//	var Day = new Array("Sun","Mon","Tue","Wed","Thu","Fri","Sat");
	var Month = new Array("1月","2月","3月","4月","5月","6月","7月","8月","9月","10月","11月","12月");
	
	var Day = new Array("日","一","二","三","四","五","六");
	
	var daysInMonth = new Array(31,28,31,30,31,30,31,31,30,31,30,31);
	var daysInAWeek=7;
	var OutputString;
	
	var today = new Date();
	if( Y=="" || isNaN(Y) ){
		thisYear=today.getFullYear();
	}else{
		thisYear=parseInt(Y);
	}
	if( M=="" || isNaN(M) ){
		thisMonth=today.getMonth()+1;
	}else{
		thisMonth=parseInt(M);
		if(thisMonth<1) thisMonth=1;
		if(thisMonth>12) thisMonth=12;
	}
	if( D=="" || isNaN(D) ){
		thisDay=today.getDate();
	}else{
		thisDay=parseInt(D);
		if(thisDay<0) thisDay=1;
		if(thisDay>31) thisDay=31;
	}
	
	if ((thisYear % 4) == 0){
		daysInMonth[ 1 ] = 29;
		if((thisYear % 100) == 0 && (thisYear % 400) != 0){
			daysInMonth[ 1 ] = 28;
		}
	}
	
	// Start the calendar table with day headings:
	OutputString = "<table class=\"table_calendar\" border='1'>\n <tr>\n";
	OutputString += " <td class=\"calendarheading\"><div class=\"cssleftstretcharrow\" onclick=\"previousYear()\"><!-- left arrow --></div></td>\n";
	OutputString += " <td class=\"calendarheading\"><div class=\"cssleftarrow\" onclick=\"previousMonth()\"><!-- left arrow --></div></td>\n";
	// Print the month heading:
	OutputString += " <td class=\"calendarheading1\">";
	// Print the year heading: If year<0, negate and print "BCE"; if 0<year<1000, print "CE":
	if( thisYear < 0 ) yearString = -thisYear + " BCE";
	else if( thisYear < 1000 ) yearString = thisYear + " CE";
	else yearString = thisYear;
	OutputString += yearString + "年<br>" + Month[ thisMonth-1 ] + "</td>\n";
	OutputString += " <td class=\"calendarheading\"><div class=\"cssrightarrow\" onclick=\"nextMonth()\"><!-- right arrow --></div></td>\n";
	OutputString += " <td class=\"calendarheading\"><div class=\"cssrightstretcharrow\" onclick=\"nextYear()\"><!-- right arrow --></div></td>\n";
	OutputString += "</tr>\n</table><table class=\"table_calendar\"> <tr>\n";
	for(i=0;i<daysInAWeek;i++)
	{
		OutputString += "  <th>" + Day[i] + "</th>\n";
	}
	OutputString += " </tr>\n <tr>\n";
	
	var firstDay=dayOfWeek( julianDay( thisYear, thisMonth, 1 ) ); 
	
	for(i=0;i<firstDay;i++)
	{
		OutputString += "  <td class=\"normaltd\" onclick=\"previousMonth()\">&nbsp;</td>\n";
	}

	for(d=1;i<daysInAWeek;i++,d++)
	{
		if( d==5 && thisMonth==10 && thisYear==1582 ) d+=10;
		OutputString += "  <td";
		if(d==thisDay) OutputString += " class='thisday'";
		else OutputString += " class=\"normaltd\"";
		OutputString += " onclick=\"setDate(" + d + ")\">" + d + "</td>\n";
	}
	
	var lastDayOfMonth=daysInMonth[thisMonth-1];
	for(j=1;j<6 && d<=lastDayOfMonth;j++)
	{
		OutputString += " </tr>\n <!-- Week " + (j+1) + " -->\n<tr>\n";
		for( i=0; i<daysInAWeek && d<=lastDayOfMonth;i++,d++)
		{  
			OutputString += "  <td";
			if(d==thisDay) OutputString += " class='thisday'";
			else OutputString += " class=\"normaltd\"";
			OutputString += " onclick=\"setDate(" + d + ")\">" + d + "</td>\n";
		}
		for(;i<daysInAWeek;i++)
		{
			OutputString += "  <td class=\"normaltd\" onclick=\"nextMonth()\">&nbsp;</td>\n";      
		}
	}

	OutputString += "  </tr>\n";
	OutputString += " </table>\n";
	OutputString += " <p>\n";
	OutputString += "  <input type=\"hidden\" id=\"currentYear\" value=\"" + thisYear + "\">\n";
	OutputString += "  <input type=\"hidden\" id=\"currentMonth\" value=\"" + thisMonth + "\">\n";
	OutputString += "  <input type=\"hidden\" id=\"currentDay\" value=\"" + thisDay + "\">\n";
	OutputString += "  <input type=\"hidden\" id=\"destinationId\" value=\"" + targetId + "\">\n";   
	OutputString += " </p>\n";

	return OutputString;	
}

var ltcalendarload = true;
