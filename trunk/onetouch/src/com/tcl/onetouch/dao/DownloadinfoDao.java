package com.tcl.onetouch.dao;

import java.util.List;
import java.util.Map;

import org.apache.log4j.Logger;

import com.tcl.onetouch.domain.Downloadinfo;

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
	
	public void save(Downloadinfo downloadinfo) {
		getSqlMapClientTemplate().insert("saveDownloadinfo", downloadinfo);
	}

	public List<Downloadinfo> findListByDidAndGame(Map map) {
		return  getSqlMapClientTemplate().queryForList("findListByDidAndGame",map);
	}

	public List<Downloadinfo> findListByDid(Map map) {
		return  getSqlMapClientTemplate().queryForList("findListByDid",map);
	}

	public List<Downloadinfo> findListByGame(Map map) {
		return  getSqlMapClientTemplate().queryForList("findListByGame",map);
	}
}
