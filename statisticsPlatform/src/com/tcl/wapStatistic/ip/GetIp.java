package com.tcl.wapStatistic.ip;

import org.apache.log4j.Logger;


public class GetIp {
	
	public static Logger log = Logger.getLogger(GetIp.class);
	
	public static String getIp(String ip) {
		String result = "";
		if(!"".equals(result=IpAddress.getIp(ip))){
			return result;
//		}else if(!"".equals(result=Whatismyipaddress.getIp(ip))){
//			return result;
		}else if(!"".equals(result=Webyield.getIp(ip))){
			return result;
		}
		return result;
	}
}
