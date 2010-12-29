import java.io.BufferedInputStream;
import java.io.ByteArrayInputStream;
import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.List;

import org.jdom.Document;
import org.jdom.Element;
import org.jdom.input.SAXBuilder;


public class UrlTest {

	/**
	 * @param args
	 * @throws Exception 
	 */
	public static void main(String[] args) throws Exception {
		 URL url = new URL("http://m.caishijie.com/wap/jsp/ad/GGServices.jsp?x-ad-position=50003539");
		 HttpURLConnection connection = (HttpURLConnection) url.openConnection();
		  //InputStream is = new FileInputStream(xmlStr);
		  InputStream is = new BufferedInputStream(connection.getInputStream());
		  StringBuilder test = new StringBuilder();
			byte[] bytes = new byte[1024];
			int len =0;
			while((len = is.read(bytes, 0, 1024))>0){
				test.append(new String(bytes,0,len));
			}
			System.out.println(test.toString());
			
		  //dom4j
//			SAXReader reader = new SAXReader();
//			Document document = reader.read(new ByteArrayInputStream(test.toString().getBytes("UTF-8")));
//			Element rootElement = document.getRootElement();
		  SAXBuilder sb = new SAXBuilder();
		  Document doc = sb.build(new ByteArrayInputStream(test.toString().getBytes("UTF-8")));
		  Element root = doc.getRootElement();
		  List GGList=root.getChildren("adcode");
//		  for(int i=0;i<GGList.size();i++){
//		  Element adcode=(Element)GGList.get(i);
//		  HashMap hashmap=new HashMap();
//		  System.out.println("o1="+adcode.getChildText("adposition"));
//		  System.out.println("o2="+adcode.getChildText("text"));
		  //////////////////////////////////
//		  if(codeName.equals("50003539")){
//		  hashmap.put("name",adcode.getChildText("text"));
//		  hashmap.put("urlName",adcode.getChildText("clickurl"));
//		  }else{
//		    hashmap.put("name",adcode.getChildText("imgurl"));
//		  hashmap.put("urlName",adcode.getChildText("clickurl"));
//		  }
		  }
//	}
	}


