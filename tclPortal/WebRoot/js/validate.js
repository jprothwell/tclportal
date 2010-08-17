//mobile
String.prototype.IsMobile = function(){
	var regexp = /^\d{11}$/;
	return regexp.test(this);
}