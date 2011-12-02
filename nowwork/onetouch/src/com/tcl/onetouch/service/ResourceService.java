package com.tcl.onetouch.service;

import java.util.List;
import java.util.Map;

import net.sf.ehcache.Cache;
import net.sf.ehcache.Element;

import com.tcl.onetouch.dao.ResourceDao;
import com.tcl.onetouch.domain.Resource;



public class ResourceService {
	
	private ResourceDao resourceDao;
	private Cache cache = null;
	
	public void setResourceDao(ResourceDao resourceDao) {
		this.resourceDao = resourceDao;
	}

	public void setCache(Cache cache) {
		this.cache = cache;
	}

	public int findCount(Map map) {
		return resourceDao.findCount(map);
	}

	public List<Resource> findList(Map map) {
		return resourceDao.findList(map);
	}

	public void save(Resource resource) {
		resourceDao.save(resource);
		this.updateCache();
	}

	public void update(Resource resource) {
		resourceDao.update(resource);
		this.updateCache();
		}

	public Resource queryResource(String id) {
		return resourceDao.queryResource(id);
	}
	public List<Resource> findAll(){
		List<Resource> resourcs = null;
		Element element = this.cache.get(Resource.CACHE_RESOURCE);
		if (null != element) {
			resourcs = (List<Resource>)element.getValue();
      } else {
    	  resourcs = this.resourceDao.findAll();
          element = new Element(Resource.CACHE_RESOURCE, resourcs);
          this.cache.put(element);
      }
      return resourcs;
	}
	private void updateCache(){
        if(null != this.cache)
               this.cache.remove(Resource.CACHE_RESOURCE);
	}
}
