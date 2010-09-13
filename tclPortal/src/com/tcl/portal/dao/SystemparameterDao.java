package com.tcl.portal.dao;

import java.util.List;
import java.util.Map;

import org.apache.log4j.Logger;

import com.tcl.portal.domain.Systemparameter;

public class SystemparameterDao extends  BaseDao{
	
	public Logger logger = Logger.getLogger(SystemparameterDao.class);

	public int findCount(Map map) {
		return (Integer) getSqlMapClientTemplate().queryForObject("findSystemparameterCount",map);
	}

	public List<Systemparameter> findList(Map map) {
		return getSqlMapClientTemplate().queryForList("findSystemparameterList", map);
	}

	public void save(Systemparameter systemparameter) {
		getSqlMapClientTemplate().insert("saveSystemparameter", systemparameter);
	}

	public void update(Systemparameter systemparameter) {
		getSqlMapClientTemplate().update("updateSystemparameter",systemparameter);
	}

	public Systemparameter querySystemparameter(int id) {
		return (Systemparameter)getSqlMapClientTemplate().queryForObject("querySystemparameter",id);
	}

	public List<Systemparameter> findAll() {
		return getSqlMapClientTemplate().queryForList("findSystemparameterAll");
	}

}
