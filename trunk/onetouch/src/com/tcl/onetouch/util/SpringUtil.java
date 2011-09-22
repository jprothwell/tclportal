package com.tcl.onetouch.util;

import javax.servlet.ServletContext;
import javax.servlet.jsp.PageContext;

import org.springframework.context.ApplicationContext;
import org.springframework.web.context.support.WebApplicationContextUtils;

public class SpringUtil {
	
	
	
	/**
	 * ��WEB�����л�ȡSpring������
	 * @param pageContext
	 * @return
	 */
	public static ApplicationContext getWebApplicationContext(PageContext pageContext) {
		ServletContext servletContext = pageContext.getServletContext();
		ApplicationContext wac = WebApplicationContextUtils
				.getRequiredWebApplicationContext(servletContext);
		return wac;
		
	}
	
	public static ApplicationContext getWebApplicationContext(ServletContext servletContext) {
		ApplicationContext wac = WebApplicationContextUtils
				.getRequiredWebApplicationContext(servletContext);
		return wac;
		
	}
}
