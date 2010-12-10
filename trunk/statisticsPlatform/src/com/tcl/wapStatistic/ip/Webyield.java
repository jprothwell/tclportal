package com.tcl.wapStatistic.ip;

import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import org.apache.commons.httpclient.Header;
import org.apache.commons.httpclient.HttpClient;
import org.apache.commons.httpclient.NameValuePair;
import org.apache.commons.httpclient.methods.PostMethod;
import org.apache.log4j.Logger;

import com.tcl.wapStatistic.util.Constants;

public class Webyield {
	
	public static Logger log = Logger.getLogger(IpAddress.class);
	public static final  String url= "http://webyield.net/ip/index.php";
	
	public static String getIp(String ip) {
		HttpClient httpclient = new HttpClient(); 
		Header head = new Header("User-Agent",Constants.HEAD_VALUE);
		
		String result="";
		 try {
				PostMethod post = new PostMethod(url);
				post.setRequestHeader(head);
				NameValuePair[] params = new NameValuePair[2];
				params[0] = new NameValuePair("ip",ip);
				params[1] = new NameValuePair("lang","English");
				post.setRequestBody(params);
				httpclient.executeMethod(post);
				String html = post.getResponseBodyAsString();
				post.releaseConnection();
				result = parseHtml(html);
	}catch (Exception e) {
		e.printStackTrace();
		return "";
	}
	
	return result;
	}
	private static String parseHtml(String html) {
		Pattern pattern = Pattern.compile("<td width=\"50%\" align=\"left\">(.*?)</td>",Pattern.DOTALL);
		Matcher matcher = pattern.matcher(html);
		List<String> list = new ArrayList<String>();
		while(matcher.find()){
			list.add(matcher.group(1));
		}
		//System.out.println("result:"+list.get(5));
		return list.get(5);
	}
	
	public static void main(String[] args){
		System.out.println(Webyield.getIp("166.230.8.3"));
	}
}
