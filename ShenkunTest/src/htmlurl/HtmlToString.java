package htmlurl;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.URL;
import java.net.URLConnection;

import org.apache.log4j.Logger;
/*
 * 传入路径，解析html以String的形式返回 
 */
public class HtmlToString {
	
	private final static Logger log = Logger.getLogger(HtmlToString.class);
	
	public static String getHtml(String path) throws Exception{
		URL url = new URL(path);
		URLConnection conn = null;
		try{
		conn = url.openConnection();
		}catch(Exception e){
			log.info("链接出现异常");
			return "NO";
		}
		conn.setDoOutput(true);
		//conn.setReadTimeout(50000);
		BufferedReader reader = new BufferedReader(new InputStreamReader(conn.getInputStream(),"UTF-8"));
		
		String line;
		StringBuilder builder = new StringBuilder();
		while((line = reader.readLine())!=null){
			builder.append(line);
			builder.append("\n");
		}
		//System.out.println("静态页面为："+builder.toString());
			return builder.toString();
	}
}
