package com.tcl.portal.dao;

import java.util.List;
import java.util.Map;

import org.apache.log4j.Logger;

import com.tcl.portal.domain.Pageinfo;

public class PageinfoDao extends  BaseDao{
	
	public Logger logger = Logger.getLogger(PageinfoDao.class);
	
	public int findCount(Map map) {
		return (Integer) getSqlMapClientTemplate().queryForObject("findPageinfoCount",map);
	}

	public List<Pageinfo> findList(Map map) {
		return  getSqlMapClientTemplate().queryForList("findPageinfoList",map);
	}

	public void save(Pageinfo pageinfo) {
		getSqlMapClientTemplate().insert("savePageinfo", pageinfo);
	}

	public void update(Pageinfo pageinfo) {
		getSqlMapClientTemplate().update("updatePageinfo",pageinfo);
	}

	public Pageinfo queryPageinfo(int id) {
		return (Pageinfo)getSqlMapClientTemplate().queryForObject("queryPageinfo", id);
	}

	public List<Pageinfo> findAll() {
		return  getSqlMapClientTemplate().queryForList("findPageinfoAll");
	}

	public int delete(int id) {
		return getSqlMapClientTemplate().delete("deletePageinfo", id);
	}

}
