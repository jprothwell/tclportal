package com.tclPaypal.message;

import java.net.URLEncoder;

import org.apache.commons.httpclient.HttpClient;
import org.apache.commons.httpclient.methods.GetMethod;

import com.tclPaypal.util.Constants;

public class GetResponse {
	
	public static String getShangmailResponse(String url){
		String returnValue = "";
		try {
//		String url = Constants.SHANGMAIL_URL+orderId+"&sign="+URLEncoder.encode(sign,"UTF-8");
//		System.err.println("url::::"+url);
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
