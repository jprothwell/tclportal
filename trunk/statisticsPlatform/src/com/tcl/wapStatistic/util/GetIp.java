package com.tcl.wapStatistic.util;

import java.io.IOException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import org.apache.commons.httpclient.Header;
import org.apache.commons.httpclient.HttpClient;
import org.apache.commons.httpclient.HttpException;
import org.apache.commons.httpclient.methods.GetMethod;

public class GetIp {
	
	private final static  String url1= "http://www.ip-adress.com/ip_tracer/";		
	private final static  String url2= "http://whatismyipaddress.com/ip/";
	private final static String headValue = "Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1; QQDownload 1.7; .NET CLR 1.1.4322; CIBA; .NET CLR 2.0.50727)";
	public static String getIp(String ip) {
		HttpClient httpclient = new HttpClient(); 
		Header head = new Header("User-Agent",headValue);
		
		String result="";
		 try {
			GetMethod get1 = new GetMethod(url1+ip);
			get1.setRequestHeader(head);
			httpclient.executeMethod(get1);
			if(get1.getStatusCode()!=403){
				String html = get1.getResponseBodyAsString();
				Pattern pattern = Pattern.compile("<(?i)title(.*?)</(?i)title>",Pattern.DOTALL);
				Matcher matcher = pattern.matcher(html);
				
				if(matcher.find()){
					result = matcher.group();	
					
				}
				String s1 = result.split("-")[1].trim();
				result = s1.split("IP")[0];
				get1.releaseConnection();
			}else{

				GetMethod get2 = new GetMethod(url2+ip);
				get2.setRequestHeader(head);
				httpclient.executeMethod(get2);
				//if(get1.getStatusCode()!=403){
					String html = get2.getResponseBodyAsString();
					System.out.print("html"+html);
					Pattern pattern = Pattern.compile("<meta name=\"description\" (.*?)>",Pattern.DOTALL);
					Matcher matcher = pattern.matcher(html);
					String ms = "";
					if(matcher.find()){
						ms = matcher.group();
						//System.out.println(ms);
					}//end if
					String s1 = ms.split("-")[0].trim();
					result = s1.split(",")[1].trim();
					get2.releaseConnection();
				//}//end if
			}
		} catch (HttpException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		return result;
	}
}
