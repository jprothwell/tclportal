package com.tcl.portal.service;

import java.util.List;
import java.util.Map;

import com.tcl.portal.dao.PageinfoDao;
import com.tcl.portal.domain.Pageinfo;

public class PageinfoService {
	
	private PageinfoDao pageinfoDao;
	
	public void setPageinfoDao(PageinfoDao pageinfoDao) {
		this.pageinfoDao = pageinfoDao;
	}

	public int findCount(Map map) {
		return pageinfoDao.findCount(map);
	}

	public List<Pageinfo> findList(Map map) {
		return pageinfoDao.findList(map);
	}

	public void save(Pageinfo pageinfo) {
		pageinfoDao.save(pageinfo);
	}

	public void update(Pageinfo pageinfo) {
		pageinfoDao.update(pageinfo);
	}

	public Pageinfo queryPageinfo(int id) {
		return pageinfoDao.queryPageinfo(id);
	}

}
