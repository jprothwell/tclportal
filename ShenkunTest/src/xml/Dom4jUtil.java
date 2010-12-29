package xml;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import org.dom4j.Attribute;
import org.dom4j.Document;
import org.dom4j.DocumentHelper;
import org.dom4j.Element;
import org.dom4j.io.SAXReader;
import org.dom4j.io.XMLWriter;

public class Dom4jUtil {
	public static void main(String[] args) throws Exception{
		
		SAXReader reader = new SAXReader();
		InputStream is = new FileInputStream("e:/TaskTree.xml");
		Document document = reader.read(is);
		
		Element rootElement = document.getRootElement();
		Dom4jUtil dom4jUtil = new Dom4jUtil();
		List tList = new ArrayList();
		List list = dom4jUtil.getList(rootElement,tList);
		
		is.close();
		Iterator iter = list.iterator();
		while(iter.hasNext()){
			XmlObject x = (XmlObject)iter.next();
			System.out.print(x.getId()+"|");
			System.out.print(x.getName().trim()+"|");
			System.out.print(x.getValue().trim()+"|");
			System.out.print(x.getParentId()+"|");
			System.out.println(x.getContent());
		}
		
		//根据list数据产生xml
		generateXml(list);
	}
	private static void generateXml(List list) {
		Document document = DocumentHelper.createDocument();
		Iterator iter = list.iterator();
		Element root = null;
		int rootId = 0;
		Element aElement = null;
		Element bElement = null;
		Element cElement = null;
		Element dElement = null;
		for(int i=0;i<list.size();i++){
			XmlObject xmlObject = (XmlObject)list.get(i);
			if(xmlObject.getId()==xmlObject.getParentId()){
				rootId = xmlObject.getId();
				root = document.addElement(xmlObject.getName());
				String content = xmlObject.getContent().trim();
				String[] contents = content.split(";");
				if(!(content.equals(null)||"".equals(content))){
					for(int j=0;j<contents.length;j++){
						String[] values = contents[j].split(":");
						root.addAttribute(values[0], values[1]);
					}
				}
			}
		}
		//generateChildren(list,root,rootId);
//		while(iter.hasNext()){
//			XmlObject xmlObject = (XmlObject)iter.next();
//			if(xmlObject.getId()==0){
//				root = document.addElement(xmlObject.getName());
//				String content = xmlObject.getContent();
//				String[] contents = content.split(";");
//				for(int i=0;i<contents.length;i++){
//					String[] values = contents[i].split(":");
//					root.addAttribute(values[0], values[1]);
//				}
//			}
//			
//			if(xmlObject.getId()==1){
//				aElement = root.addElement(xmlObject.getName());
//				aElement.setText(xmlObject.getValue());
//				String content = xmlObject.getContent();
//				String[] contents = content.split(";");
//				for(int i=0;i<contents.length;i++){
//					String[] values = contents[i].split(":");
//					aElement.addAttribute(values[0], values[1]);
//				}
//			}
//			if(xmlObject.getId()==2){
//				bElement = aElement.addElement(xmlObject.getName());
//				bElement.setText(xmlObject.getValue());
//				String content = xmlObject.getContent().trim();
//				if(!(content.equals(null)||"".equals(content))){
//					String[] contents = content.split(";");
//					for(int i=0;i<contents.length;i++){
//						String[] values = contents[i].split(":");
//						bElement.addAttribute(values[0], values[1]);
//					}
//				}
//			}
//			if(xmlObject.getId()==3){
//				cElement = bElement.addElement(xmlObject.getName());
//				cElement.setText(xmlObject.getValue());
//				String content = xmlObject.getContent().trim();
//				if(!(content.equals(null)||"".equals(content))){
//					String[] contents = content.split(";");
//					for(int i=0;i<contents.length;i++){
//						String[] values = contents[i].split(":");
//						cElement.addAttribute(values[0], values[1]);
//					}
//				}
//			}
//			if(xmlObject.getId()==4){
//				dElement = cElement.addElement(xmlObject.getName());
//				dElement.setText(xmlObject.getValue());
//				String content = xmlObject.getContent().trim();
//				if(!(content.equals(null)||"".equals(content))){
//					String[] contents = content.split(";");
//					for(int i=0;i<contents.length;i++){
//						String[] values = contents[i].split(":");
//						dElement.addAttribute(values[0], values[1]);
//					}
//				}
//			}
//		}	
		XMLWriter writer;
		try {
			writer = new XMLWriter(new FileOutputStream("e:/output.xml"));
			writer.write(document);
		    writer.close(); 
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	private static void generateChildren(List list, Element root, int id) {
		Element e = null;
		for(int i=0;i<list.size();i++){
			XmlObject xmlObject = (XmlObject)list.get(i);
			if(xmlObject.getParentId()==id&&xmlObject.getId()!=id){
				e = root.addElement(xmlObject.getName());
				e.setText(xmlObject.getValue());
				String content = xmlObject.getContent().trim();
				String[] contents = content.split(";");
				if(!(content.equals(null)||"".equals(content))){
					for(int j=0;j<contents.length;j++){
						String[] values = contents[j].split(":");
						e.addAttribute(values[0], values[1]);
				}
			}
		  }
		}
		for(int i=0;i<list.size();i++){
			XmlObject xmlObject = (XmlObject)list.get(i);
			if(xmlObject.getParentId()==id&&xmlObject.getId()!=id)
			{	
				generateChildren(list,e,xmlObject.getId());
			}
		}
		
	}
	private List getList(Element rootElement, List list) {
		int num = 0;
		XmlObject xo = new XmlObject();
		xo.setId(num);
		xo.setName(rootElement.getName().trim());
		xo.setParentId(num);
		xo.setValue(rootElement.getText().trim());
		xo = getAttribute(rootElement,xo);
		list.add(xo);
		//子节点
		return getChildNode(rootElement,num,list);
	}

	private static List getChildNode(Element element,int num, List list) {
		
		//解析子节点
		Iterator iter = element.elementIterator();
		
		while(iter.hasNext()){
			Element e = (Element)iter.next();
			
			XmlObject xo = new XmlObject();
			xo.setId(num+1);
			xo.setName(e.getName());
			xo.setParentId(num);
			xo.setValue(e.getText());
			xo = getAttribute(e,xo);
			list.add(xo);
			getChildNode(e,num+1,list);
		}
		return list;
	}
	
	//节点属性
	private static XmlObject getAttribute(Element element, XmlObject xo) {
		String name = element.getName();
		int count = element.attributeCount();
		StringBuilder sb = new StringBuilder();
		for(int i=0 ;i<count;i++){
			Attribute attr = element.attribute(i);
			sb.append(attr.getName());
			sb.append(":");
			sb.append(attr.getText());
			sb.append(";");
		}
		xo.setContent(sb.toString());
		//System.out.println(">>"+sb.toString());
		return xo;
	}
}
