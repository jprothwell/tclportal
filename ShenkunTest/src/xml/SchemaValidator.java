package xml;

import org.dom4j.Document;
import org.dom4j.DocumentException;
import org.dom4j.io.SAXReader;
import org.iso_relax.verifier.Schema;
import org.iso_relax.verifier.Verifier;
import org.iso_relax.verifier.VerifierFactory;
import org.iso_relax.verifier.VerifierFilter;
import org.xml.sax.ErrorHandler;
import org.xml.sax.SAXParseException;

import com.sun.msv.verifier.jarv.TheFactoryImpl;

public class SchemaValidator {
	
	public static void main(String args[]){
		
		String xmlUrl = "E:\\TestDocument\\change\\xml\\ecds.003.001.01.xml";
        String xsdUrl = "E:\\TestDocument\\change\\Schemas\\ecds.003.001.01.xsd";
      
        SAXReader reader = null;
		try {
			reader = createSAXReader(xsdUrl);
		} catch (Exception e) {
			e.printStackTrace();
			System.out.println("XSD parse false!");
		}
		System.out.println("==========");
		Document document = null;
        try {
        	document = reader.read(xmlUrl);
		} catch (DocumentException e) {
			e.printStackTrace();
			
			System.out.println("error validation...");
		}
		//System.out.println(document.asXML());
	}

	private static SAXReader createSAXReader(String schemaURI) throws Exception {
		 System.out.println("Loaded schema document: " + schemaURI);

	        // use autodetection of schemas
	        VerifierFactory factory = new TheFactoryImpl();
	        Schema schema = factory.compileSchema(schemaURI);

	        Verifier verifier = schema.newVerifier();
	        verifier.setErrorHandler(new ErrorHandler() {
	            public void error(SAXParseException e) {
	                System.out.println("ERROR: " + e);
	            }

	            public void fatalError(SAXParseException e) {
	                System.out.println("FATAL: " + e);
	            }

	            public void warning(SAXParseException e) {
	                System.out.println("WARNING: " + e);
	            }
	        });

	        // now install the verifying filter
	        VerifierFilter filter = verifier.getVerifierFilter();
	        SAXReader reader = new SAXReader();
	        reader.setXMLFilter(filter);
	        return reader;
	}
}
