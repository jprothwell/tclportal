if(!window.js)
{
	var js = new Object();
}

js.Pager = function(){};

$.extend(js.Pager.prototype,
{
	initialize:function(url,method,sizeEl,pageEl,navBtnEl)
	{
		this.url = url;
		this.method = method || "doPager";
		this.sizeEl = document.getElementById(sizeEl);
		this.pageEl = document.getElementById(pageEl);
		this.navBtnEl = document.getElementById(navBtnEl);
	},
	
	buildUrl:function(page)
	{
		var url = this.url ;
		url += "&action=" + this.method;
		url += "&pageNo=" + page;
		url += "&pageSize=" + this.sizeEl.value ;
		return url;
	},
	
	navTo:function(page)
	{
		page = page || this.pageEl.value;
		var url = this.buildUrl(page)
		window.location = url;
	},
	
	setMethod:function(method)
	{
		this.method = method;
	}
}
);