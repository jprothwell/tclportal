package com.tcl.portal.service;

import java.util.List;
import java.util.Map;

import net.sf.ehcache.Cache;
import net.sf.ehcache.Element;

import org.apache.log4j.Logger;

import com.tcl.portal.dao.TelecomoperatorsDao;
import com.tcl.portal.domain.Telecomoperators;

public class TelecomoperatorsService {
	
	public Logger logger = Logger.getLogger(TelecomoperatorsService.class);
	
	private TelecomoperatorsDao telecomoperatorsDao;
	
	public void setTelecomoperatorsDao(TelecomoperatorsDao telecomoperatorsDao) {
		this.telecomoperatorsDao = telecomoperatorsDao;
	}
	
	private Cache cache;
	
	public void setCache(Cache cache) {
		this.cache = cache;
	}
	public int findCount(Map map) {
		return telecomoperatorsDao.findCount(map);
	}

	public List<Telecomoperators> findList(Map map) {
		return telecomoperatorsDao.findList(map);
	}

	public void save(Telecomoperators telecomoperators) {
		telecomoperatorsDao.save(telecomoperators);
		this.updateCache();
	}

	public void update(Telecomoperators telecomoperators) {
		telecomoperatorsDao.update(telecomoperators);
		this.updateCache();
	}

	public Telecomoperators queryTelecomoperators(int id) {
		return telecomoperatorsDao.queryTelecomoperators(id);
	}
	
	public List<Telecomoperators> findAll(){
		List<Telecomoperators> telecoms = null;
		Element element = this.cache.get(Telecomoperators.CACHE_TELECOMOPERATORS);
		if (null != element) {
			telecoms = (List<Telecomoperators>)element.getValue();
      } else {
    	  telecoms = this.telecomoperatorsDao.findAll();
          element = new Element(Telecomoperators.CACHE_TELECOMOPERATORS, telecoms);
          this.cache.put(element);
      }
      return telecoms;
	}
	private void updateCache(){
        if(null != this.cache)
              this.cache.remove(Telecomoperators.CACHE_TELECOMOPERATORS);
	}
}
