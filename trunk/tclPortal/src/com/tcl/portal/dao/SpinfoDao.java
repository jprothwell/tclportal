package com.tcl.portal.dao;

import java.util.List;
import java.util.Map;

import org.apache.log4j.Logger;

import com.tcl.portal.domain.Spinfo;

public class SpinfoDao extends  BaseDao{
	
	public Logger logger = Logger.getLogger(SpinfoDao.class);

	public int findCount(Map map) {
		return (Integer) getSqlMapClientTemplate().queryForObject("findSpinfoCount",map);
	}

	public List<Spinfo> findList(Map map) {
		return  getSqlMapClientTemplate().queryForList("findSpinfoList",map);
	}

	public void save(Spinfo spinfo) {
		getSqlMapClientTemplate().insert("saveSpinfo", spinfo);
	}

	public void update(Spinfo spinfo) {
		getSqlMapClientTemplate().update("updateSpinfo",spinfo);
	}

	public Spinfo querySpinfo(int id) {
		return (Spinfo)getSqlMapClientTemplate().queryForObject("querySpinfo", id);
	}

	public List<Spinfo> findAll() {
		return  getSqlMapClientTemplate().queryForList("findSpinfoAll");
	}

	public int delete(int id) {
		return  getSqlMapClientTemplate().delete("deleteSpinfo",id);
	}
	
}
