package com.tcl.portal.util;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

import org.apache.commons.beanutils.Converter;

public class DateConvert implements Converter{
	
SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd");
	
	public Object convert(Class type, Object value) {
		
		Object returnValue = null;
		
		if(value==null||("").equals(value)) 
		{
			return null;
		}else{
			try {
				if(value instanceof Date){
					returnValue = value;
				}else{
					returnValue = dateFormat.parseObject(value.toString());
				}
				
			} catch (ParseException e) {
				e.printStackTrace();
			}
		}
		return returnValue;	
	}
	
}

