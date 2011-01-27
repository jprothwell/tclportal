package com.tcl.portal.service;

import java.util.List;
import java.util.Map;

import com.tcl.portal.dao.VisiteinfoDao;
import com.tcl.portal.domain.Visiteinfo;

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

}
