package xml;

import org.dom4j.Document;
import org.dom4j.io.SAXReader;
import org.dom4j.util.XMLErrorHandler;

public class Schema {

	public static void main(String[] args) throws Exception {
		
		SAXReader reader = new SAXReader();
		reader.setValidation(true);
		reader.setProperty("http://apache.org/xml/properties/schema/external-noNamespaceSchemaLocation","E:\\TestDocument\\ecds3.xsd");
		XMLErrorHandler errorHandler = new XMLErrorHandler();
		reader.setErrorHandler(errorHandler);
		Document   document = reader.read("E:\\TestDocument\\ecds.xml");
		System.out.println(document.asXML());
//		XMLWriter   writer   =   new   XMLWriter(OutputFormat.createPrettyPrint());  
//	    writer.write(errorHandler.getErrors()); 
//	    writer.close();
	}
}
