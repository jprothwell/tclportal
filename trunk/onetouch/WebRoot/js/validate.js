//mobile
String.prototype.IsMobile = function(){
	var regexp = /^\d{11}$/;
	return regexp.test(this);
}
//number check
String.prototype.IsNumberCheck = function(){
	var regexp = /^\d{1,10}$/;
	return regexp.test(this);
}