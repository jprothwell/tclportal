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

	public Mobileinfo queryMobileinfo(String did) {
		return (Mobileinfo)getSqlMapClientTemplate().queryForObject("queryMobileinfo", did);
	}

	public List<Mobileinfo> findAll() {
		return  getSqlMapClientTemplate().queryForList("findMobileinfoAll");
	}

	public int delete(String did) {
		return getSqlMapClientTemplate().delete("deleteMobileinfo", did);
	}

	public int checkDual(String did) {
		return (Integer)getSqlMapClientTemplate().queryForObject("checkDidDual",did);
	}

	public int checkUaDual(String ua) {
		return (Integer)getSqlMapClientTemplate().queryForObject("checkUaDual",ua);
	}

}
