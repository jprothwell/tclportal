package com.tcl.wapStatistic.util;

import java.util.concurrent.Callable;

import com.tcl.wapStatistic.domain.Location;

public class BatchGetCountry implements Callable<String>{
	
	Location location;
	public BatchGetCountry(Location location){
		this.location = location;
	}
	public String call() throws Exception {
		String country = GetIp.getIp(location.getIp()+".2");
		if("".equals(country)){
			return "";
		}
		return location.getId()+":"+country;
	}

}
