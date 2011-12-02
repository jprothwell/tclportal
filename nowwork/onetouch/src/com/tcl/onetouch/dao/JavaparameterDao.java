package com.tcl.onetouch.dao;

import java.util.List;
import java.util.Map;

import org.apache.log4j.Logger;

import com.tcl.onetouch.domain.Javaparameter;

public class JavaparameterDao extends  BaseDao{
	
	public Logger logger = Logger.getLogger(JavaparameterDao.class);

	public int findCount(Map map) {
		return (Integer) getSqlMapClientTemplate().queryForObject("findJavaparaCount",map);
	}

	public List<Javaparameter> findList(Map map) {
		return  getSqlMapClientTemplate().queryForList("findJavaparaList",map);
	}

	public void save(Javaparameter javapara) {
		getSqlMapClientTemplate().insert("saveJavapara", javapara);
	}

	public void update(Javaparameter javapara) {
		getSqlMapClientTemplate().update("updateJavapara",javapara);
	}

	public Javaparameter queryJavapara(int id) {
		return (Javaparameter)getSqlMapClientTemplate().queryForObject("queryJavapara", id);
	}

	public List<Javaparameter> findAll() {
		return  getSqlMapClientTemplate().queryForList("findJavaparaAll");
	}

	public int delete(int id) {
		return getSqlMapClientTemplate().delete("deleteJavapara", id);
	}

}
