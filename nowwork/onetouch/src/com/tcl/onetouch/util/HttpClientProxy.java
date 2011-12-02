package com.tcl.onetouch.util;

import java.util.HashMap;
import java.util.Map;

import org.apache.commons.httpclient.Header;
import org.apache.commons.httpclient.HttpClient;
import org.apache.commons.httpclient.HttpStatus;
import org.apache.commons.httpclient.NameValuePair;
import org.apache.commons.httpclient.methods.GetMethod;
import org.apache.commons.httpclient.methods.PostMethod;
import org.apache.commons.httpclient.methods.RequestEntity;
import org.apache.commons.httpclient.methods.StringRequestEntity;

public class HttpClientProxy {
	
	public static String postMethod(String url,Map param) throws Exception{
		//发送验证信息
		HttpClient httpClient = new HttpClient(); 
//		Header head = new Header("User-Agent",Constants.HEAD_VALUE);
		PostMethod postMethod = new PostMethod(url);
		postMethod.setRequestHeader("Content-type", "text/xml; charset=iso-8859-1");
		
		NameValuePair[] data = { new NameValuePair("userName", (String)param.get("userName")),
				new NameValuePair("pwd", (String)param.get("pwd")),
				new NameValuePair("channelCode", (String)param.get("channelCode")),
				new NameValuePair("insertType", (String)param.get("insertType"))};
		postMethod.setRequestBody(data);
		int result = httpClient.executeMethod(postMethod);
		System.out.println("result:"+result);
		String responseXML = new String(postMethod.getResponseBodyAsString().getBytes("iso-8859-1")); 
		System.out.println(responseXML);
		postMethod.releaseConnection();
		return responseXML;
	}
	
	public static String postMethodXML(String url,String xml) throws Exception{
		//发送验证信息
		HttpClient httpClient = new HttpClient(); 
//		Header head = new Header("User-Agent",Constants.HEAD_VALUE);
		PostMethod postMethod = new PostMethod(url);
		postMethod.setRequestHeader("Content-type", "text/xml; charset=iso-8859-1");
		
		RequestEntity entity = new StringRequestEntity(xml, "text/xml","UTF-8");
		postMethod.setRequestEntity(entity);

//		NameValuePair[] data = {new NameValuePair("",xml)};
//		postMethod.setRequestBody(data);
		int result = httpClient.executeMethod(postMethod);
		System.out.println("result:"+result);
		String responseXML = new String(postMethod.getResponseBodyAsString().getBytes("iso-8859-1")); 
		System.out.println(responseXML);
		postMethod.releaseConnection();
		return responseXML;
	}
	
	public static String getMethod(String url) throws Exception{
		HttpClient httpClient = new HttpClient(); 
		GetMethod getMethod = new GetMethod(url);
		int statuscode = httpClient.executeMethod(getMethod);
		if(statuscode==200){
			
		}else if((statuscode == HttpStatus.SC_MOVED_TEMPORARILY) ||
	            (statuscode == HttpStatus.SC_MOVED_PERMANENTLY) ||
	            (statuscode == HttpStatus.SC_SEE_OTHER) ||
	            (statuscode == HttpStatus.SC_TEMPORARY_REDIRECT)){
			//重定向
			//读取新的URL地址
            Header header = getMethod.getResponseHeader("location");
            if (header != null) {
                String newuri = header.getValue();
                if ((newuri == null) || (newuri.equals("")))
                    newuri = "/";
                GetMethod redirect = new GetMethod(newuri);
                httpClient.executeMethod(redirect);
                System.out.println("Redirect:"+ redirect.getStatusLine().toString());
                redirect.releaseConnection();
            }
		}
		getMethod.releaseConnection();
		return null;	
	}
	
	public static String getMethodNoRedirect(String url) throws Exception{
		HttpClient httpClient = new HttpClient(); 
		GetMethod getMethod = new GetMethod(url);
		int statuscode = httpClient.executeMethod(getMethod);
		String returnURL = new String(getMethod.getResponseBodyAsString().getBytes("UTF-8"));
		System.out.println("statuscode:"+statuscode);
		return returnURL;
	}
	public static void main(String[] args) throws Exception{
		Map param = new HashMap();
		param.put("userName", "tcl");
		param.put("pwd", "abcd1234");
		param.put("channelCode", "10010000");
		param.put("insertType", "00");
		String path = "e:/test";
		String xmlString = TemplateConfiguration.getTemplateContextOutString(param,path,"\\validateInsert.ftl");
		System.out.println(xmlString);
		String responseXML = HttpClientProxy.postMethodXML("http://gmpbeta.g188.net/channelSyscment/validateInsert",xmlString);
		Map map = Dom4jProxy.parseXml(responseXML);
		String tokenPwd = (String)map.get("tokenPwd");
		String channelCode = (String)map.get("channelCode");
		System.out.println("tokenPwd:"+tokenPwd+",channelCode="+channelCode);
		String url = "http://gmpbeta.g188.net/channelSyscment/serviceValidate?serviceType=1" +
				"&channelcode=" +channelCode+
				"&tokenPwd=" +tokenPwd+
				"&gameId=110223972000";
		HttpClientProxy.getMethodNoRedirect(url);
	
	}
}
