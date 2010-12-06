package com.tcl.wapStatistic.util;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.Callable;

import com.tcl.wapStatistic.domain.Location;

public class GetIps implements Callable<List>{
	
	private List<Location> list;
	public GetIps(List<Location> sublist) {
		this.list = sublist;
	}

	public List<Location> call() throws Exception {
		//List<Location> returnList = new ArrayList<Location>();
		for(Location location:list){
			location.setCountry(GetIp.getIp(location.getIp()+".2"));
			//returnList.add(o)
		}
		return list;
	}

}
