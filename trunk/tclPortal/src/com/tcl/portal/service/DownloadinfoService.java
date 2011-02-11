package com.tcl.portal.service;

import java.util.List;
import java.util.Map;

import com.tcl.portal.dao.DownloadinfoDao;
import com.tcl.portal.domain.Downloadinfo;

public class DownloadinfoService {
	
	private DownloadinfoDao downloadinfoDao;
	
	public void setDownloadinfoDao(DownloadinfoDao downloadinfoDao) {
		this.downloadinfoDao = downloadinfoDao;
	}

	public int findCount(Map map) {
		return downloadinfoDao.findCount(map);
	}

	public List<Downloadinfo> findList(Map map) {
		return downloadinfoDao.findList(map);
	}

	public List<Downloadinfo> findListForExcel(Map map) {
		return downloadinfoDao.findListForExcel(map);
	}

}
