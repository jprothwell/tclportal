package com.tcl.gamePortal.service;

import com.tcl.gamePortal.dao.PageinfoDao;

public class PageinfoService {
	
	private PageinfoDao pageinfoDao;
	
	
	public void setPageinfoDao(PageinfoDao pageinfoDao) {
		this.pageinfoDao = pageinfoDao;
	}


	public int queryPageName(String did) {
		return pageinfoDao.queryPageName(did);
	}

}
