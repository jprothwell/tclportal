package xml;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;

import org.jdom.Document;
import org.jdom.Element;
import org.jdom.JDOMException;
import org.jdom.input.SAXBuilder;

public class Test {
	
	public static void main(String[] args) throws Exception {
		
		InputStream is = new FileInputStream("");
		SAXBuilder builder = new SAXBuilder();
		//�õ�����XML�ĵ�
		Document document = builder.build(is);
		//�õ���Ԫ��
		Element rootElement = document.getRootElement();
		
	}

}
