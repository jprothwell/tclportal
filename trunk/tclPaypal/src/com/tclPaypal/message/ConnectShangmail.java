package com.tclPaypal.message;

import java.util.concurrent.Callable;

import com.tclPaypal.domain.Business;

public class ConnectShangmail implements Callable<String>{

	private Business business;
	
	public ConnectShangmail(Business business){
		this.business = business;
	}
	public String call() throws Exception {
		return GetResponse.getShangmailResponse(business.getOrdernum());
	}

}
