package com.tcl.portal.service;

import java.util.List;
import java.util.Map;

import net.sf.ehcache.Cache;
import net.sf.ehcache.Element;

import org.apache.log4j.Logger;

import com.tcl.portal.dao.CityDao;
import com.tcl.portal.domain.City;

public class CityService {
	
	public Logger logger = Logger.getLogger(CityService.class);
	
	private CityDao cityDao;
	
	private Cache cache;
	
	public void setCache(Cache cache) {
		this.cache = cache;
	}
	
	public void setCityDao(CityDao cityDao) {
		this.cityDao = cityDao;
	}
	
	public int findCount(Map map) {
		return cityDao.findCount(map);
	}

	public List<City> findList(Map map) {
		return cityDao.findList(map);
	}

	public void save(City city) {
		cityDao.save(city);
		this.updateCache();
	}

	public void update(City city) {
		cityDao.update(city);
		this.updateCache();
	}

	public City queryCountry(int id) {
		return cityDao.queryCountry(id);
	}
	
	public List<City> findAll(){
		List<City> citys = null;
		Element element = this.cache.get(City.CACHE_CITY);
		if (null != element) {
			citys = (List<City>)element.getValue();
      } else {
    	  citys = this.cityDao.findAll();
          element = new Element(City.CACHE_CITY, citys);
          this.cache.put(element);
      }
      return citys;
	}
	private void updateCache(){
        if(null != this.cache)
              this.cache.remove(City.CACHE_CITY);
	}
}
