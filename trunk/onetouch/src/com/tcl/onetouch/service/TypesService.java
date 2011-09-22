package com.tcl.onetouch.service;

import java.util.List;
import java.util.Map;

import net.sf.ehcache.Cache;
import net.sf.ehcache.Element;

import com.tcl.onetouch.dao.TypesDao;
import com.tcl.onetouch.domain.Types;


public class TypesService {
	
	private TypesDao typesDao;
	
	private Cache cache;
	
	public void setCache(Cache cache) {
		this.cache = cache;
	}
	
	public void setTypesDao(TypesDao typesDao) {
		this.typesDao = typesDao;
	}

	public int findCount(Map map) {
		return typesDao.findCount(map);
	}

	public List<Types> findList(Map map) {
		return typesDao.findList(map);
	}

	public void save(Types types) {
		typesDao.save(types);
		this.updateCache();
	}

	public void update(Types types) {
		typesDao.update(types);
		this.updateCache();
	}

	public Types queryTypes(int id) {
		List<Types> types = findAll();
		for(Types type:types){
			if(type.getId()==id){
				return type;
			}
		}
		return null;
	}
	
	public List<Types> findAll(){
		List<Types> types = null;
		Element element = this.cache.get(Types.CACHE_TYPES);
		if (null != element) {
			types = (List<Types>)element.getValue();
      } else {
    	  types = this.typesDao.findAll();
          element = new Element(Types.CACHE_TYPES, types);
          this.cache.put(element);
      }
      return types;
	}
	
	private void updateCache(){
        if(null != this.cache)
              this.cache.remove(Types.CACHE_TYPES);
	}

	public int delete(int id) {
		int i = typesDao.delete(id);
		this.updateCache();
		return i;
	}
	
	public String queryType(int kindid) {
		return typesDao.queryType(kindid);
	}
}
