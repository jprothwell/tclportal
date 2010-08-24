package com.tcl.portal.service;

import java.util.List;
import java.util.Map;

import com.tcl.portal.dao.MobileinfoDao;
import com.tcl.portal.domain.Mobileinfo;

public class MobileinfoService {
	
	private MobileinfoDao mobileinfoDao;

	public void setMobileinfoDao(MobileinfoDao mobileinfoDao) {
		this.mobileinfoDao = mobileinfoDao;
	}

	public int findCount(Map map) {
		return mobileinfoDao.findCount(map);
	}

	public List<Mobileinfo> findList(Map map) {
		return mobileinfoDao.findList(map);
	}

	public void save(Mobileinfo mobileinfo) {
		mobileinfoDao.save(mobileinfo);
	}

	public void update(Mobileinfo mobileinfo) {
		mobileinfoDao.update(mobileinfo);
	}

	public Mobileinfo queryMobileinfo(String did) {
		return mobileinfoDao.queryMobileinfo(did);
	}
	
	
}
