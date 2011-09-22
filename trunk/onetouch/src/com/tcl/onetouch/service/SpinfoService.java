package com.tcl.onetouch.service;

import java.util.List;
import java.util.Map;

import net.sf.ehcache.Cache;
import net.sf.ehcache.Element;

import org.apache.log4j.Logger;

import com.tcl.onetouch.dao.SpinfoDao;
import com.tcl.onetouch.domain.Spinfo;

public class SpinfoService {
	
	public Logger logger = Logger.getLogger(SpinfoService.class);
	
	private Cache cache;
	
	public void setCache(Cache cache) {
		this.cache = cache;
	}
	
	private SpinfoDao spinfoDao;

	public void setSpinfoDao(SpinfoDao spinfoDao) {
		this.spinfoDao = spinfoDao;
	}
	
	public List<Spinfo> findList(Map map) {
		return spinfoDao.findList(map);
	}

	public int findCount(Map map) {
		return spinfoDao.findCount(map);
	}

	public void save(Spinfo spinfo) {
		spinfoDao.save(spinfo);
		this.updateCache();
	}

	public void update(Spinfo spinfo) {
		spinfoDao.update(spinfo);
		this.updateCache();
	}

	public Spinfo querySpinfo(int id) {
		List<Spinfo> list = findAll();
		for(Spinfo spinfo:list){
			if(spinfo.getId()==id){
				return spinfo;
			}
		}
		return null;
	}
	
	public List<Spinfo> findAll(){
		List<Spinfo> spinfos = null;
		Element element = this.cache.get(Spinfo.CACHE_SPINFO);
		if (null != element) {
			spinfos = (List<Spinfo>)element.getValue();
      } else {
    	  spinfos = this.spinfoDao.findAll();
          element = new Element(Spinfo.CACHE_SPINFO, spinfos);
          this.cache.put(element);
      }
      return spinfos;
	}
	
	private void updateCache(){
        if(null != this.cache)
              this.cache.remove(Spinfo.CACHE_SPINFO);
	}

	public int delete(int id) {
		int i = spinfoDao.delete(id);
		this.updateCache();
		return i;
	}
}
