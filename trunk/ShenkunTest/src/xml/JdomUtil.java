package xml;
import java.io.FileInputStream;
import java.io.InputStream;

import org.jdom.Document;
import org.jdom.Element;
import org.jdom.input.SAXBuilder;

public class JdomUtil {
	public static void main(String[] args) throws Exception {
		
		//获取文件输入流，从当前classpath当中进行获取
		InputStream is = new FileInputStream("E:\\TestDocument\\ecds.xml");
		//从输入流当中读取XML，构造一个Doucment对象
		SAXBuilder builder = new SAXBuilder();
		//得到整份XML文档
		Document document = builder.build(is);
		//得到根元素
		Element rootElement = document.getRootElement();
		System.out.println("XML文档根元素为：" + rootElement.getName());
		Element CommercialDraftRegisterRequest = rootElement.getChild("CommercialDraftRegisterRequest");
		Element MsgId = CommercialDraftRegisterRequest.getChild("MsgId");
		
		String Id = MsgId.getChildText("Id");
		String CreDtTm = MsgId.getChildText("CreDtTm");
		System.out.println(Id + " ?? " + CreDtTm );
		is.close();
	}
	
	private String getElementValue(Element rootElement,String s1,String s2){
		Element element = rootElement.getChild(s1);
		
		return null;
	}
}
