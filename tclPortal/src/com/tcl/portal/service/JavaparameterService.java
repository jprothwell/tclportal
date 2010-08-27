package com.tcl.portal.service;

import java.util.List;
import java.util.Map;

import net.sf.ehcache.Cache;
import net.sf.ehcache.Element;

import com.tcl.portal.dao.JavaparameterDao;
import com.tcl.portal.domain.City;
import com.tcl.portal.domain.Javaparameter;

public class JavaparameterService {
	
	private JavaparameterDao javaparameterDao;
	
	private Cache cache;
	
	public void setCache(Cache cache) {
		this.cache = cache;
	}
	
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
		this.updateCache();
	}

	public void update(Javaparameter javapara) {
		javaparameterDao.update(javapara);
		this.updateCache();
	}

	public Javaparameter queryJavaparameter(int id) {
		List<Javaparameter> list = findAll();
		for(Javaparameter javaparameter:list){
			if(javaparameter.getId()==id){
				return javaparameter;
			}
		}
		return null;
	}

	public List<Javaparameter> findAll() {
		List<Javaparameter> javaparameters = null;
		Element element = this.cache.get(Javaparameter.CACHE_JAVAPARAMETER);
		if (null != element) {
			javaparameters = (List<Javaparameter>)element.getValue();
      } else {
    	  javaparameters = this.javaparameterDao.findAll();
          element = new Element(Javaparameter.CACHE_JAVAPARAMETER, javaparameters);
          this.cache.put(element);
      }
      return javaparameters;
	}
	
	private void updateCache(){
        if(null != this.cache)
              this.cache.remove(Javaparameter.CACHE_JAVAPARAMETER);
	}
}
