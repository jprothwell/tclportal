package com.tcl.onetouch.util;

import java.util.Locale;

public class LocalUtil {
	
	public static Locale getLocal(String lan){
		if("en".equals(lan)){
			return Locale.ENGLISH;
		}else if("zh".equals(lan)){
			return Locale.CHINA;
		}
		return Locale.ENGLISH;
	}
}
