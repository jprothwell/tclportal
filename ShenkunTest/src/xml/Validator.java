package xml;

import org.dom4j.Document;
import org.dom4j.io.SAXReader;
import org.dom4j.io.SAXWriter;
import org.iso_relax.verifier.Schema;
import org.iso_relax.verifier.Verifier;
import org.iso_relax.verifier.VerifierFactory;
import org.iso_relax.verifier.VerifierHandler;
import org.xml.sax.ErrorHandler;
import org.xml.sax.SAXParseException;

import com.sun.msv.verifier.jarv.TheFactoryImpl;
 
public   class   Validator   {  
 
   // private   final   static   CATEGORY   =   Category.getInstance(Validator.class);  
    private   String   schemaURI;  
    private   Document   document;  
 
    public   Validator(Document   document,   String   schemaURI)   {  
        this.schemaURI   =   schemaURI;  
        this.document   =   document;  
    }  
     
    public   boolean   test() throws   Exception   {  
     
        //   (1)   use   autodetection   of   schemas  
        VerifierFactory   factory   =   new  TheFactoryImpl();  
        Schema   schema   =   factory.compileSchema(schemaURI);  
         
        //   (2)   configure   a   Vertifier  
        Verifier   verifier   =   schema.newVerifier();  
        verifier.setErrorHandler(  
                        new   ErrorHandler()   {  
                                public   void   error(SAXParseException   saxParseEx)   {  
                                     //CATEGORY.error(   "Error   during   validation.",   saxParseEx);  
                                }  
                                 
                                public   void   fatalError(SAXParseException   saxParseEx)   {  
                                     // CATEGORY.fatal(   "Fatal   error   during   validation.",   saxParseEx);  
                                }  
                                 
                                public   void   warning(SAXParseException   saxParseEx)   {  
                                      //CATEGORY.warn(   saxParseEx   );  
                                }  
                        }  
                );                  
        VerifierHandler handler = verifier.getVerifierHandler();  
        SAXWriter writer = new SAXWriter(handler);  
        writer.write(document);        
        return   handler.isValid();  
    }  
    
    public static void main(String[] args) throws Exception{
    	SAXReader reader = new SAXReader();
    	Document   document   =   reader.read("E:\\TestDocument\\ecds.xml");
    	Validator validator = new Validator(document,"E:\\TestDocument\\ecds.xsd");
    	System.out.println(validator.test());
    }
     
    }  
     
  
