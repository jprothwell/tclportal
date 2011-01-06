package com.tclPaypal.message;

import org.apache.commons.httpclient.HttpClient;
import org.apache.commons.httpclient.methods.GetMethod;

import com.tclPaypal.util.Constants;

public class GetResponse {
	
	public static String getShangmailResponse(String orderId){
		String returnValue = "";
		try {
		String url = Constants.SHANGMAIL_URL+orderId;
		HttpClient httpclient = new HttpClient();
		GetMethod get = new GetMethod(url);
		httpclient.executeMethod(get);
		if(get.getStatusCode()==200){
			returnValue = get.getResponseBodyAsString();
		}
		get.releaseConnection();
		} catch (Exception e) {
			e.printStackTrace();
			return returnValue;
		}
		return returnValue;
	}
}
