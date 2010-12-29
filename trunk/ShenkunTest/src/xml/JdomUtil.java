package xml;
import java.io.FileInputStream;
import java.io.InputStream;

import org.jdom.Document;
import org.jdom.Element;
import org.jdom.input.SAXBuilder;

public class JdomUtil {
	public static void main(String[] args) throws Exception {
		
		//��ȡ�ļ����������ӵ�ǰclasspath���н��л�ȡ
		InputStream is = new FileInputStream("E:\\TestDocument\\ecds.xml");
		//�����������ж�ȡXML������һ��Doucment����
		SAXBuilder builder = new SAXBuilder();
		//�õ�����XML�ĵ�
		Document document = builder.build(is);
		//�õ���Ԫ��
		Element rootElement = document.getRootElement();
		System.out.println("XML�ĵ���Ԫ��Ϊ��" + rootElement.getName());
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
