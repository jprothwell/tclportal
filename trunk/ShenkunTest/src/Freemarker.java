import java.io.BufferedWriter;
import java.io.File;
import java.io.StringWriter;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Locale;
import java.util.Map;

import freemarker.cache.MruCacheStorage;
import freemarker.template.Configuration;
import freemarker.template.DefaultObjectWrapper;
import freemarker.template.Template;


public class Freemarker {
	
		@SuppressWarnings("unchecked")
		public static void main(String[] args) throws Exception{
			String path = "E:\\TestDocument";
			String fileName = "ecds_zh_CN.ftl";
			Map map = new HashMap();
			List list = new ArrayList();
			FreemarkerUser user1 = new FreemarkerUser();
			user1.setName("s1");
			list.add(user1);
			
			FreemarkerUser user2 = new FreemarkerUser();
			user2.setName("s2");
			//list.add(user2);
			
			map.put("list",list);
			
			map.put("no","no");
			map.put("Id",2);
			map.put("CreDtTm",new Date());
			map.put("PrtcptrSgntr","");
			long s1 = System.currentTimeMillis();
			String s = getEmailContext(map,path,fileName);
			long s2 = System.currentTimeMillis();
			System.out.println(s2-s1);
			System.out.println(s);
		}
		 /** 
		      * 传入装有信息的root,模板文件所在的路径pah和模板文件名fileName 
		      * 返回的是经过map信息改变后的摸板内容 
		      */  
		      public static String getEmailContext(Map root,String path,String fileName) throws Exception{  
		             Configuration cfg = new Configuration();  
		             cfg.setEncoding(Locale.getDefault(), "UTF-8");  
		             cfg.setDirectoryForTemplateLoading(new File(path));  
		             cfg.setObjectWrapper(new DefaultObjectWrapper());  
		             cfg.setCacheStorage(new MruCacheStorage(20,250));  
		               
		             Template temp = cfg.getTemplate(fileName);  
		             temp.setEncoding("UTF-8");  
		             StringWriter stringWriter = new StringWriter();  
		             Writer out = new BufferedWriter(stringWriter);  
		             temp.process(root, out);  
		             out.flush();   
		             return stringWriter.toString();  
		     }  
}
