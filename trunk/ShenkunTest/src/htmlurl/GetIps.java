package htmlurl;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.Callable;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import org.apache.commons.httpclient.Header;
import org.apache.commons.httpclient.HttpClient;
import org.apache.commons.httpclient.HttpException;
import org.apache.commons.httpclient.methods.GetMethod;

public class GetIps implements Callable<List>{
	
	List<String> list;
	public GetIps(List<String> list){
		this.list = list;
	}
	private final static  String url= "http://www.ip-adress.com/ip_tracer/";	
	private final static String headValue = "Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1; QQDownload 1.7; .NET CLR 1.1.4322; CIBA; .NET CLR 2.0.50727)";
	public  List<String> getIps(){
		List<String> returnlist = new ArrayList();
		for(String s:list){
			returnlist.add(getIp(s));
		}
		return list;
	}

	public static String getIp(String ip) {
		HttpClient httpclient = new HttpClient(); 
		Header head = new Header("User-Agent",headValue);
		GetMethod get = new GetMethod(url+ip);
		get.setRequestHeader(head);
		
//		PostMethod post = new PostMethod(url);
//		post.setRequestHeader(head);
//		NameValuePair[] params = new NameValuePair[2];
//		params[0] = new NameValuePair("QRY","166.230.8.3");
		//post.setRequestBody(params);
//		httpclient.executeMethod(post);
//		System.out.println(post.getResponseBodyAsString());
		String result="";
		 try {
			httpclient.executeMethod(get);
			String html = get.getResponseBodyAsString();
			Pattern pattern = Pattern.compile("<(?i)title(.*?)</(?i)title>",Pattern.DOTALL);
			Matcher matcher = pattern.matcher(html);
			
			if(matcher.find()){
				result = matcher.group();			
			}
			String s1 = result.split("-")[1].trim();
			String strs = s1.split("IP")[0];
			//System.out.println(strs.trim());
		} catch (HttpException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		get.releaseConnection();
		return result;
	}

	public List call() throws Exception {
		// TODO Auto-generated method stub
		return null;
	}
}
