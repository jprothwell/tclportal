package com.tcl.wapStatistic.ip;

import java.io.IOException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import org.apache.commons.httpclient.Header;
import org.apache.commons.httpclient.HttpClient;
import org.apache.commons.httpclient.methods.GetMethod;
import org.apache.log4j.Logger;

import com.tcl.wapStatistic.util.Constants;

public class Whatismyipaddress {
	
	public static Logger log = Logger.getLogger(Whatismyipaddress.class);
	
	private final static  String url = "http://whatismyipaddress.com/ip/";
	
	public static void main(String[] args){
		System.out.println(getIp("166.230.8.3"));
	}
	public static String getIp(String ip) {
		HttpClient httpclient = new HttpClient(); 
		Header head = new Header("User-Agent",Constants.HEAD_VALUE);
		
		String result="";
		 try {
			 GetMethod get = new GetMethod(url+ip);
				get.setRequestHeader(head);
				httpclient.executeMethod(get);
				if(get.getStatusCode()!=503){
					String html = get.getResponseBodyAsString();
					
					Pattern pattern = Pattern.compile("<meta name=\"description\" (.*?)>",Pattern.DOTALL);
					Matcher matcher = pattern.matcher(html);
					String ms = "";
					if(matcher.find()){
						ms = matcher.group(1);
					}//end if
					String s1 = ms.split(",")[1].trim();
					String[] strs = s1.split("-");
					if(strs.length!=0){
						result = strs[0].trim();
					}
				}
				get.releaseConnection();
	}catch (IOException e) {
		e.printStackTrace();
		return result;
	}
	
	return result;
	}
}
