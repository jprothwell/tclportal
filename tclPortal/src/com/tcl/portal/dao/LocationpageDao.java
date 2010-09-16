package com.tcl.portal.dao;

import java.util.List;
import java.util.Map;

import org.apache.log4j.Logger;

import com.tcl.portal.domain.Locationpage;

public class LocationpageDao extends  BaseDao{
	
	public Logger logger = Logger.getLogger(LocationpageDao.class);
	
	public int findCount(Map map) {
		return (Integer) getSqlMapClientTemplate().queryForObject("findLocationpageCount",map);
	}

	public List<Locationpage> findList(Map map) {
		return  getSqlMapClientTemplate().queryForList("findLocationpageList",map);
	}

	public void save(Locationpage locationpage) {
		getSqlMapClientTemplate().insert("saveLocationpage", locationpage);
	}

	public void update(Locationpage locationpage) {
		getSqlMapClientTemplate().update("updateLocationpage",locationpage);
	}

	public Locationpage queryLocationpage(int id) {
		return (Locationpage)getSqlMapClientTemplate().queryForObject("queryLocationpage", id);
	}

	public List<Locationpage> findAll() {
		return  getSqlMapClientTemplate().queryForList("findLocationpageAll");
	}

	public int delete(int id) {
		return getSqlMapClientTemplate().delete("deleteLocationpage", id);
	}

}
