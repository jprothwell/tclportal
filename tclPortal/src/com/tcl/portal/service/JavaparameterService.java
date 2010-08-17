package com.tcl.portal.service;

import java.util.List;
import java.util.Map;

import com.tcl.portal.dao.JavaparameterDao;
import com.tcl.portal.domain.Javaparameter;

public class JavaparameterService {
	
	private JavaparameterDao javaparameterDao;

	public void setJavaparameterDao(JavaparameterDao javaparameterDao) {
		this.javaparameterDao = javaparameterDao;
	}

	public int findCount(Map map) {
		return javaparameterDao.findCount(map);
	}

	public List<Javaparameter> findList(Map map) {
		return javaparameterDao.findList(map);
	}

	public void save(Javaparameter javaparameter) {
		javaparameterDao.save(javaparameter);
	}

	public void update(Javaparameter javapara) {
		javaparameterDao.update(javapara);
	}

	public Javaparameter queryJavaparameter(int id) {
		return javaparameterDao.queryJavapara(id);
	}
	
	
}
