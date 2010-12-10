package com.tcl.wapStatistic.ip;

import java.io.IOException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import org.apache.commons.httpclient.Header;
import org.apache.commons.httpclient.HttpClient;
import org.apache.commons.httpclient.HttpException;
import org.apache.commons.httpclient.methods.GetMethod;
import org.apache.log4j.Logger;

import com.tcl.wapStatistic.util.Constants;

public class IpAddress {
	
	public static Logger log = Logger.getLogger(IpAddress.class);
	public static final  String url= "http://www.ip-adress.com/ip_tracer/";
	
	public static String getIp(String ip) {
		HttpClient httpclient = new HttpClient(); 
		Header head = new Header("User-Agent",Constants.HEAD_VALUE);
		
		String result="";
		 try {
			GetMethod get = new GetMethod(url+ip);
			get.setRequestHeader(head);
			httpclient.executeMethod(get);
			if(get.getStatusCode()!=403){
				String html = get.getResponseBodyAsString();
				Pattern pattern = Pattern.compile("<(?i)title(.*?)</(?i)title>",Pattern.DOTALL);
				Matcher matcher = pattern.matcher(html);
				
				if(matcher.find()){
					result = matcher.group();	
				}
				String s1 = result.split("-")[1].trim();
				result = s1.split("IP")[0];
			}
			get.releaseConnection();
	}catch (Exception e) {
		e.printStackTrace();
		return "";
	}
	
	return result;
	}
}
