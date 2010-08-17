package com.tcl.gamePortal.service;

import com.tcl.gamePortal.dao.VisiteinfoDao;
import com.tcl.gamePortal.domain.Visiteinfo;

public class VisiteinfoService {
	
	private VisiteinfoDao visiteinfoDao;

	public void setVisiteinfoDao(VisiteinfoDao visiteinfoDao) {
		this.visiteinfoDao = visiteinfoDao;
	}
	
	public void save(Visiteinfo visiteinfo){
		visiteinfoDao.save(visiteinfo);
	}
}
