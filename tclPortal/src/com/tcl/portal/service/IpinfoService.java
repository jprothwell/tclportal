package com.tcl.portal.service;

import java.util.List;
import java.util.Map;

import com.tcl.portal.dao.IpinfoDao;
import com.tcl.portal.domain.Ipinfo;

public class IpinfoService {
	
	private IpinfoDao ipinfoDao;
	
	public void setIpinfoDao(IpinfoDao ipinfoDao) {
		this.ipinfoDao = ipinfoDao;
	}

	public int findCount(Map map) {
		return ipinfoDao.findCount(map);
	}

	public List<Ipinfo> findList(Map map) {
		return ipinfoDao.findList(map);
	}

	public void save(Ipinfo ipinfo) {
		ipinfoDao.save(ipinfo);
	}

	public void update(Ipinfo ipinfo) {
		ipinfoDao.update(ipinfo);
	}

	public Ipinfo queryIpinfo(int id) {
		return ipinfoDao.queryIpinfo(id);
	}

	public int delete(int id) {
		return ipinfoDao.delete(id);
	}

	public int checkDual(String ip) {
		return ipinfoDao.checkDual(ip);
	}

}
