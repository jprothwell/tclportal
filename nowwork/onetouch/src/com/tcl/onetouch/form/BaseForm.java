package com.tcl.onetouch.form;

import org.apache.commons.beanutils.ConvertUtils;
import org.apache.struts.action.ActionForm;

import com.tcl.onetouch.util.DateConvert;


public class BaseForm extends ActionForm{
	
	static{
		ConvertUtils.register(new DateConvert(),java.util.Date.class); 
	}
}
