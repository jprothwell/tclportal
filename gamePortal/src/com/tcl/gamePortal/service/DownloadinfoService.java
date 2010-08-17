package com.tcl.gamePortal.service;

import com.tcl.gamePortal.dao.DownloadinfoDao;
import com.tcl.gamePortal.domain.Downloadinfo;

/**
 * 下载信息
 * @author kun.shen
 *
 */
public class DownloadinfoService {
	
	private DownloadinfoDao downloadinfoDao;

	public void setDownloadinfoDao(DownloadinfoDao downloadinfoDao) {
		this.downloadinfoDao = downloadinfoDao;
	}
	
	public void save(Downloadinfo downloadinfo){
		downloadinfoDao.save(downloadinfo);
	}
}
