package com.tcl.onetouch.util;

import java.io.ByteArrayInputStream;
import java.io.InputStream;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

import org.dom4j.Document;
import org.dom4j.Element;
import org.dom4j.io.SAXReader;


public class Dom4jProxy {
	
	public static Map parseXml(String xml) throws Exception{
		
		InputStream is = new ByteArrayInputStream(xml.getBytes());;
		SAXReader reader = new SAXReader(); 
		Document document = reader.read(is);
		
		Element rootElement = document.getRootElement();
		Iterator iter = rootElement.elementIterator();
		Map map = new HashMap();
		while(iter.hasNext()){
			Element e = (Element)iter.next();
			map.put(e.getName(), e.getText());
		}
		
		return map;
	}
	
}
