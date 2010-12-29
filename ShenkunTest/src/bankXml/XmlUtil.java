package bankXml;


import java.io.ByteArrayInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.util.List;

import org.jdom.Document;
import org.jdom.Element;
import org.jdom.input.SAXBuilder;


/**
 *  XML tools class
 *
 * @author	wenxm@erongsoft.com
 * @version     %I%, %G%
 */
public	class	XmlUtil {
	public static Element verifySchemas(InputStream xml, String xsd) {
		try {
			if (xsd==null) {
				SAXBuilder builder = new SAXBuilder();
				Document document = builder.build(xml);
				return	document.getRootElement();
			}

			//
			File xsdFile = new File(xsd);
			if (!xsdFile.canRead()) {
				return	null;
			}
			
			SAXBuilder builder = new SAXBuilder(
				"org.apache.xerces.parsers.SAXParser", true);
			
			builder.setFeature("http://apache.org/xml/features/validation/schema", true);
			
			builder.setProperty(
				"http://apache.org/xml/properties/schema"
				+ "/external-noNamespaceSchemaLocation",
				xsdFile.toURL().toString());
			
			Document doc = builder.build(xml);
			return	doc.getRootElement();
		} catch (Exception e) {
			Syslog.printStackTrace(e);
		}
		return	null;
	}

	// </root/node[i]/child/name>
	public	static	String	getValue(Element element, String name) {
		Element node = getNode(element, name);
		if (node == null)
			return	null;

		//检查是否是叶节点
		if (node.getChildren().size()!=0) {
			Syslog.showDebug("Node<"+node.getName()
				+"> not leaf, size="+ node.getChildren().size());
			return	null;
		}

		Syslog.showDebug("Node<"+node.getName()
			+">=<"+ node.getText()+">");

		return	node.getText();
	}
	
	//
	//xpathx = /root/node[i]/child/
	private	static	Element	getNode(Element element, String path) {
		if (Util.isEmpty(path))
			return	element;
		
		boolean bRoot = path.startsWith("/");

		// "/root/node" split -> "" "root" "node"
		
		String	[]paths = path.split("/");
		return	getNode(element, bRoot, paths, paths.length);
        }

	//
	private	static	Element	getNode(Element element, boolean bRoot, String paths[], int l) {
		StringBuffer	sb = new StringBuffer();
		int	off = bRoot?1:0;
		Element	base = element;

		String	root = element.getName();
		if ((l>off) && !root.equals(paths[off])) {
			Syslog.showDebug("Root<"+base.getName()+">!=" + paths[off]);
			return	null;
		}
		if (l>off)
			sb.append(paths[off] + "/");
		off ++; //skip root

		//
		for (int i= off; i<l; i++) {
			if (Util.isEmpty(paths[i])) {
//				continue;
				Syslog.showDebug("Empty Node<"+sb+"/> name!");
				return	null;
			}
			sb.append(paths[i] + "/");
			base = getChild(base, paths[i]);
			if (base == null) {
				Syslog.showDebug("Node<"+sb+"> not found!");
				return	null;
			}
		}

//		Syslog.showDebug("getNode: Node = <"+base.getName()+">, child#="+ base.getChildren().size());

		return	base;
        }

        // name[n], empty name means all children
	private	static	Element	getChild(Element base, String name) {
		if (!name.endsWith("]"))
			return	base.getChild(name);
		
		int	k = name.indexOf('[');
		if (k<0) //
			return	base.getChild(name);
			
		//split "name[n]" into <name, n>
		String	x = name.substring(0, k);
		String	y = name.substring(k+1, name.length()-1).trim();
		int	n = Integer.parseInt(y);
//		Syslog.showDebug("Node="+x+", sub="+y);

		List	elements = (k==0)?base.getChildren():base.getChildren(x);
		if ((n+1)>elements.size())
			return	null;
		return	(Element)elements.get(n);
	}



	//test
	public static void main(String[] args) 
		throws	Exception {
		FileInputStream	f = new FileInputStream("001.pkt");
		byte[]	req = new byte[1100];
		f.read(req);
		f.close();
		
		int	len = 900;
		//skip lead space
		int	off = 200;
		while ((len>0) && (req[off]!='<')) {
			off++;
			len--;
		}
		while ((len>0) && (req[off+len-1]!='>')) {
			len--;
		}
		
//		String	s = new String(req, 200, 900);
		String	s = new String(req, off, len);
		System.out.println("XML=["+s+"]");
		
		ByteArrayInputStream bi = new ByteArrayInputStream(req, off, len);
		XmlUtil.verifySchemas(bi, "001.xsd");
	}

}
