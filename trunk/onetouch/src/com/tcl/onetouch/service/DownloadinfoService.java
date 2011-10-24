package com.tcl.onetouch.service;

import java.util.List;
import java.util.Map;

import com.tcl.onetouch.dao.DownloadinfoDao;
import com.tcl.onetouch.domain.Downloadinfo;


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
	
	public void save(Downloadinfo downloadinfo){
		downloadinfoDao.save(downloadinfo);
	}

	//下载访问统计
	public List<Downloadinfo> findListByDidAndGame(Map map) {
		return downloadinfoDao.findListByDidAndGame(map);
	}

	public List<Downloadinfo> findListByDid(Map map) {
		return downloadinfoDao.findListByDid(map);
	}
	

	public List<Downloadinfo> findListByGame(Map map) {
		return downloadinfoDao.findListByGame(map);
	}
}
