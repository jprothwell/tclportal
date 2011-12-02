package com.tcl.onetouch.util;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.OutputStreamWriter;
import java.io.StringWriter;
import java.io.Writer;
import java.util.Locale;
import java.util.Map;

import freemarker.template.Configuration;
import freemarker.template.DefaultObjectWrapper;
import freemarker.template.Template;

public class TemplateConfiguration {
	/**
	 * 
	 * @param hashMap	封装传入freemarker中的数据
	 * @param path		模板路径
	 * @param fileName	模板名
	 * @return
	 * @throws Exception
	 */
	public static String getTemplateContextOutString(Map hashMap, String path, String fileName) throws Exception{
			Configuration cfg = new Configuration();  
			cfg.setEncoding(Locale.getDefault(), "UTF-8");  
			cfg.setDirectoryForTemplateLoading(new File(path)); 
			cfg.setObjectWrapper(new DefaultObjectWrapper());  
			cfg.setCacheStorage(new freemarker.cache.MruCacheStorage(20,250));  
					              
			Template temp = cfg.getTemplate(fileName);  
			temp.setEncoding("UTF-8");  
			StringWriter stringWriter = new StringWriter();  
			Writer out = new BufferedWriter(stringWriter);  
			temp.process(hashMap, out);  
			out.flush();  
			return stringWriter.toString();  
		
	}
}
