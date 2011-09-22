package com.tcl.onetouch.util;

import java.text.DecimalFormat;

public class NumberFormatUtil {
	
	public static String fomateNumber(String info){
		DecimalFormat df = new DecimalFormat("######");
		return df.format(Double.parseDouble(info));
	}
}