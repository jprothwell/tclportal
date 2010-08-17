package com.tcl.portal.service;

import java.util.List;
import java.util.Map;

import net.sf.ehcache.Cache;
import net.sf.ehcache.Element;

import org.apache.log4j.Logger;

import com.tcl.portal.dao.CountryDao;
import com.tcl.portal.domain.Country;
import com.tcl.portal.domain.User;

public class CountryService {
	
	public Logger logger = Logger.getLogger(CountryService.class);
	
	private CountryDao countryDao;
	
    private Cache cache = null;
	
	public void setCache(Cache cache) {
		this.cache = cache;
	}
	
	public void setCountryDao(CountryDao countryDao) {
		this.countryDao = countryDao;
	}

	public int findCount(Map map) {
		return countryDao.findCount(map);
	}

	public List<Country> findList(Map map) {
		return countryDao.findList(map);
	}

	public void save(Country country) {
		countryDao.save(country);
		this.updateCache();
	}

	public void update(Country country) {
		countryDao.update(country);
		this.updateCache();
	}

	public Country queryCountry(int parseInt) {
		List<Country> list = this.findAll();
		for(Country country:list){
			if(parseInt==country.getId()){
				return country;
			}
		}
		return null;
	}

	public List<Country> findAll() {
		List<Country> countrys = null;
		Element element = this.cache.get(Country.CACHE_COUNTRY);
		if (null != element) {
			countrys = (List<Country>)element.getValue();
      } else {
    	  countrys = this.countryDao.findAll();
          element = new Element(Country.CACHE_COUNTRY, countrys);
          this.cache.put(element);
      }
      return countrys;
	}
	
	private void updateCache(){
        if(null != this.cache)
              this.cache.remove(Country.CACHE_COUNTRY);
	}

	public int delete(int id) {
		return countryDao.delete(id);
	}
}
