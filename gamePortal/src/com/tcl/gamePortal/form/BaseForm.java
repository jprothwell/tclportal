package com.tcl.gamePortal.form;

import org.apache.commons.beanutils.ConvertUtils;
import org.apache.struts.action.ActionForm;

import com.tcl.gamePortal.util.DateConvert;



public class BaseForm extends ActionForm{
	
	static{
		ConvertUtils.register(new DateConvert(),java.util.Date.class); 
	}
}
