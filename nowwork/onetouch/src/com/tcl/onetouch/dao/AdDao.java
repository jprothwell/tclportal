package com.tcl.onetouch.dao;

import java.util.List;
import java.util.Map;

import org.apache.log4j.Logger;

import com.tcl.onetouch.domain.Ad;

public class AdDao  extends  BaseDao{
	
	public Logger logger = Logger.getLogger(AdDao.class);
	
	public int findCount(Map map) {
		return (Integer) getSqlMapClientTemplate().queryForObject("findAdCount",map);
	}

	public List<Ad> findList(Map map) {
		return getSqlMapClientTemplate().queryForList("findAdList",map);
	}

	public void save(Ad ad) {
		getSqlMapClientTemplate().insert("saveAd", ad);
	}

	public void update(Ad ad) {
		getSqlMapClientTemplate().update("updateAd", ad);
	}

	public Ad queryAd(int id) {
		return (Ad)getSqlMapClientTemplate().queryForObject("queryAd",id);
	}
	
	public Ad queryAdByDid(String did) {
		return (Ad)getSqlMapClientTemplate().queryForObject("queryAdByDid",did);
	}
}
