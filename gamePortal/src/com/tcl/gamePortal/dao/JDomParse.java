package com.tcl.gamePortal.dao;


import java.io.StringReader;
import java.util.ArrayList;
import java.util.HashMap;

import java.util.List;
import org.jdom.Document;
import org.jdom.Element;

import org.jdom.input.SAXBuilder;

import org.xml.sax.InputSource;


public class JDomParse {
	public List getGGListByXmlStr(String xmlStr){
		List list=new ArrayList();
		try {
			StringReader read = new StringReader(xmlStr);
			InputSource source = new InputSource(read);
			SAXBuilder sb = new SAXBuilder();
			Document doc = sb.build(source);
			Element root = doc.getRootElement();
			List GGList=root.getChildren("adcode");
			for(int i=0;i<GGList.size();i++){
				Element adcode=(Element)GGList.get(i);
				HashMap hashmap=new HashMap();
				Element type=adcode.getChild("imgurl");
				String returnCode=adcode.getChildText("returncode");
				if(returnCode.equals("400")){
					continue;
				}
				if(type==null)
					hashmap.put("type","text");
				else
					hashmap.put("type", "img");
				hashmap.put("adposition",adcode.getChildText("adposition"));
				hashmap.put("returncode", adcode.getChildText("returncode"));
				hashmap.put("clickurl", adcode.getChildText("clickurl"));
				if(type==null){
					hashmap.put("text",adcode.getChildText("text"));
				}else{
					hashmap.put("imgurl",adcode.getChildText("imgurl"));
					hashmap.put("imgalt",adcode.getChildText("imgalt"));
				}
				list.add(hashmap);
			}
			
			
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return list;
	}

	 ////////////
	}