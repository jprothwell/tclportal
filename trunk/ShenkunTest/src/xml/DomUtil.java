package xml;

import java.io.FileInputStream;

import java.io.FileNotFoundException;

import java.io.IOException;

import java.io.InputStream;

import javax.xml.parsers.DocumentBuilder;

import javax.xml.parsers.DocumentBuilderFactory;

import javax.xml.parsers.ParserConfigurationException;

import org.w3c.dom.Document;

import org.w3c.dom.Element;

import org.w3c.dom.Node;

import org.w3c.dom.NodeList;

import org.xml.sax.SAXException;

public class DomUtil {

	public static void main(String[] args) {
		
		DocumentBuilderFactory domfac = DocumentBuilderFactory.newInstance();
		try {
			DocumentBuilder dombuilder = domfac.newDocumentBuilder();
			InputStream is = new FileInputStream("E:\\TestDocument\\ecds.xml");
			Document doc = dombuilder.parse(is);
			Element root = doc.getDocumentElement();
			System.out.println(root.getNodeName());
			NodeList books= root.getChildNodes();
			
			if(books != null){
				for(int i=0;i<books.getLength();i++){
					Node book = books.item(i);
					System.out.println(book.getNodeName());
					String Id = book.getNodeValue();
					//System.out.println(Id);
				}
			}
			System.out.println(books.getLength());
			
		} catch (ParserConfigurationException e) {
			e.printStackTrace();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (SAXException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}

	}

}
