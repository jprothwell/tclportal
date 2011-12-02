package com.tcl.onetouch.service;

import java.util.List;
import java.util.Map;

import com.tcl.onetouch.dao.VisiteinfoDao;
import com.tcl.onetouch.domain.Visiteinfo;


public class VisiteinfoService {
	
	private VisiteinfoDao visiteinfoDao;
	
	public void setVisiteinfoDao(VisiteinfoDao visiteinfoDao) {
		this.visiteinfoDao = visiteinfoDao;
	}

	public int findCount(Map map) {
		return visiteinfoDao.findCount(map);
	}

	public List<Visiteinfo> findList(Map map) {
		return visiteinfoDao.findList(map);
	}

	public List<Visiteinfo> findListForExcel(Map map) {
		return visiteinfoDao.findListForExcel(map);
	}
	
	public void save(Visiteinfo visiteinfo){
		visiteinfoDao.save(visiteinfo);
	}
}
