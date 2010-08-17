package com.tcl.portal.dao;

import java.util.List;
import java.util.Map;

import org.apache.log4j.Logger;

import com.tcl.portal.domain.Changelog;

public class ChangelogDao extends  BaseDao{
	
	public Logger logger = Logger.getLogger(ChangelogDao.class);
	
	public int findCount(Map map) {
		return (Integer) getSqlMapClientTemplate().queryForObject("findChangelogCount",map);
	}

	public List<Changelog> findList(Map map) {
		return  getSqlMapClientTemplate().queryForList("findChangelogList",map);
	}

	public void save(Changelog changelog) {
		getSqlMapClientTemplate().insert("saveChangelog", changelog);
	}

	public List<Changelog> findList() {
		return  getSqlMapClientTemplate().queryForList("findChangelogListReport");
	}

}
