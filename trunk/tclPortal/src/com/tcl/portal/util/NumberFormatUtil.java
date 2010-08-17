package com.tcl.portal.util;

import java.text.DecimalFormat;

public class NumberFormatUtil {
	
	public static String fomateNumber(String info){
		DecimalFormat df = new DecimalFormat("######");
		return df.format(Double.parseDouble(info));
	}
}