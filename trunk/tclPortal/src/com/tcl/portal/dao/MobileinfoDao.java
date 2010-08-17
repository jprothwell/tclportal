package com.tcl.portal.dao;

import java.util.List;
import java.util.Map;

import org.apache.log4j.Logger;

import com.tcl.portal.domain.Mobileinfo;

public class MobileinfoDao extends  BaseDao{
	
	public Logger logger = Logger.getLogger(MobileinfoDao.class);
	
	public int findCount(Map map) {
		return (Integer) getSqlMapClientTemplate().queryForObject("findMobileinfoCount",map);
	}

	public List<Mobileinfo> findList(Map map) {
		return  getSqlMapClientTemplate().queryForList("findMobileinfoList",map);
	}

	public void save(Mobileinfo mobileinfo) {
		getSqlMapClientTemplate().insert("saveMobileinfo", mobileinfo);
	}

	public void update(Mobileinfo mobileinfo) {
		getSqlMapClientTemplate().update("updateMobileinfo",mobileinfo);
	}

	public Mobileinfo queryMobileinfo(int id) {
		return (Mobileinfo)getSqlMapClientTemplate().queryForObject("queryMobileinfo", id);
	}

	public List<Mobileinfo> findAll() {
		return  getSqlMapClientTemplate().queryForList("findMobileinfoAll");
	}

}
