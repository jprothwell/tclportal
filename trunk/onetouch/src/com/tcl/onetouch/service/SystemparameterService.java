package com.tcl.onetouch.service;

import java.util.List;
import java.util.Map;

import net.sf.ehcache.Cache;
import net.sf.ehcache.Element;

import com.tcl.onetouch.dao.SystemparameterDao;
import com.tcl.onetouch.domain.Systemparameter;


public class SystemparameterService {
	
	private SystemparameterDao systemparameterDao;
	
	private Cache cache;
	
	public void setCache(Cache cache) {
		this.cache = cache;
	}
	
	public void setSystemparameterDao(SystemparameterDao systemparameterDao) {
		this.systemparameterDao = systemparameterDao;
	}

	public int findCount(Map map) {
		return systemparameterDao.findCount(map);
	}

	public List<Systemparameter> findList(Map map) {
		return systemparameterDao.findList(map);
	}

	public void save(Systemparameter systemparameter) {
		systemparameterDao.save(systemparameter);
		this.updateCache();
	}

	public void update(Systemparameter systemparameter) {
		systemparameterDao.update(systemparameter);
		this.updateCache();
	}

	public Systemparameter querySystemparameter(int id) {
		List<Systemparameter> list = this.findAll();
		for(Systemparameter systemparameter:list){
			if(id==systemparameter.getId()){
				return systemparameter;
			}
		}
		return null;
	}
	
	public String queryByKey(String key){
		List<Systemparameter> list = this.findAll();
		for(Systemparameter systemparameter:list){
			if(key.equals(systemparameter.getName())){
				return systemparameter.getValue();
			}
		}
		return "";
	}
	public List<Systemparameter> findAll() {
		List<Systemparameter> systemparameters = null;
		Element element = this.cache.get(Systemparameter.CACHE_SYSTEMPARAMETER);
		if (null != element) {
			systemparameters = (List<Systemparameter>)element.getValue();
      } else {
    	  systemparameters = this.systemparameterDao.findAll();
          element = new Element(Systemparameter.CACHE_SYSTEMPARAMETER, systemparameters);
          this.cache.put(element);
      }
      return systemparameters;
	}
	
	private void updateCache(){
        if(null != this.cache)
              this.cache.remove(Systemparameter.CACHE_SYSTEMPARAMETER);
	}
}
