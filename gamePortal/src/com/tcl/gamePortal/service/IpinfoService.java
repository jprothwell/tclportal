package com.tcl.gamePortal.service;

import org.apache.log4j.Logger;

import com.tcl.gamePortal.dao.IpinfoDao;
import com.tcl.gamePortal.domain.Ipinfo;

public class IpinfoService {
	
	public Logger logger = Logger.getLogger(IpinfoService.class);
	
	private IpinfoDao ipinfoDao;

	public void setIpinfoDao(IpinfoDao ipinfoDao) {
		this.ipinfoDao = ipinfoDao;
	}

	public Ipinfo queryIpinfo(String ip) {
		return ipinfoDao.queryIpinfo(ip);
	}
	
	
}
