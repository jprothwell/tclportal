package bankXml;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;

import org.jdom.Document;
import org.jdom.Element;
import org.jdom.input.SAXBuilder;

public class Test {

	public static void main(String[] args) throws Exception {
		InputStream is = new FileInputStream("E:\\TestDocument\\ecds.xml");
		SAXBuilder builder = new SAXBuilder();
		//�õ�����XML�ĵ�
		Document document = builder.build(is);
		//�õ���Ԫ��
		Element rootElement = document.getRootElement();
	}

}
