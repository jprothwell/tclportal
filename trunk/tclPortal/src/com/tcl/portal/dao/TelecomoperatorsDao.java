package com.tcl.portal.dao;

import java.util.List;
import java.util.Map;

import org.apache.log4j.Logger;

import com.tcl.portal.domain.Telecomoperators;


public class TelecomoperatorsDao extends  BaseDao{
	
	public Logger logger = Logger.getLogger(TelecomoperatorsDao.class);

	public int findCount(Map map) {
		return (Integer) getSqlMapClientTemplate().queryForObject("findTelecomoperatorsCount",map);
	}

	public List<Telecomoperators> findList(Map map) {
		return  getSqlMapClientTemplate().queryForList("findTelecomoperatorsList",map);
	}

	public void save(Telecomoperators telecomoperators) {
		getSqlMapClientTemplate().insert("saveTelecomoperators", telecomoperators);
	}

	public void update(Telecomoperators telecomoperators) {
		getSqlMapClientTemplate().update("updateTelecomoperators",telecomoperators);
	}

	public Telecomoperators queryTelecomoperators(int id) {
		return (Telecomoperators)getSqlMapClientTemplate().queryForObject("queryTelecomoperators", id);
	}

	public List<Telecomoperators> findAll() {
		return  getSqlMapClientTemplate().queryForList("findTelecomoperatorsAll");
	}

	public int delete(int id) {
		return getSqlMapClientTemplate().delete("deleteTelecomoperators",id);
	}
}
