package com.tcl.portal.service;

import java.util.List;
import java.util.Map;

import net.sf.ehcache.Cache;
import net.sf.ehcache.Element;

import org.apache.log4j.Logger;

import com.tcl.portal.dao.ProvinceDao;
import com.tcl.portal.domain.Country;
import com.tcl.portal.domain.Province;


public class ProvinceService {
	
	public Logger logger = Logger.getLogger(ProvinceService.class);
	
	private ProvinceDao provinceDao;
	
	private Cache cache = null;
		
	public void setCache(Cache cache) {
		this.cache = cache;
	}
		
	public void setProvinceDao(ProvinceDao provinceDao) {
		this.provinceDao = provinceDao;
	}


	public int findCount(Map map) {
		return provinceDao.findCount(map);
	}


	public List<Province> findList(Map map) {
		return provinceDao.findList(map);
	}


	public void save(Province province) {
		provinceDao.save(province);
		this.updateCache();
	}


	public void update(Province province) {
		provinceDao.update(province);
		this.updateCache();
	}


	public Province queryProvince(int id) {
		List<Province> provinces = this.findAll();
		for(Province province:provinces){
			if(id==province.getId()){
				return province;
			}
		}
		return null;
	}
	
	public List<Province> findAll(){
		List<Province> provinces = null;
		Element element = this.cache.get(Province.CACHE_PROVINCE);
		if (null != element) {
			provinces = (List<Province>)element.getValue();
      } else {
    	  provinces = this.provinceDao.findAll();
          element = new Element(Province.CACHE_PROVINCE, provinces);
          this.cache.put(element);
      }
      return provinces;
	}
	private void updateCache(){
        if(null != this.cache)
              this.cache.remove(Province.CACHE_PROVINCE);
	}
}
