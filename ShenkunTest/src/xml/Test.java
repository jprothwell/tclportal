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
		//得到整份XML文档
		Document document = builder.build(is);
		//得到根元素
		Element rootElement = document.getRootElement();
		
	}

}
