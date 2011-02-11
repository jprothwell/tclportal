package com.tcl.portal.dao;

import java.util.List;
import java.util.Map;

import org.apache.log4j.Logger;

import com.tcl.portal.domain.Downloadinfo;

public class DownloadinfoDao extends  BaseDao{
	
	public Logger logger = Logger.getLogger(DownloadinfoDao.class);
	
	public int findCount(Map map) {
		return (Integer) getSqlMapClientTemplate().queryForObject("findDownloadinfoCount",map);
	}

	public List<Downloadinfo> findList(Map map) {
		return  getSqlMapClientTemplate().queryForList("findDownloadinfoList",map);
	}

	public List<Downloadinfo> findListForExcel(Map map) {
		return getSqlMapClientTemplate().queryForList("findDownloadListForExcel",map);
	}

}
