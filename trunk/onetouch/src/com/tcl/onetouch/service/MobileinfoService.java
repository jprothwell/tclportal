package com.tcl.onetouch.service;

import java.util.List;
import java.util.Map;

import net.sf.ehcache.Cache;
import net.sf.ehcache.Element;

import com.tcl.onetouch.dao.MobileinfoDao;
import com.tcl.onetouch.domain.Mobileinfo;


public class MobileinfoService {
	
	private MobileinfoDao mobileinfoDao;
	
	private Cache cache;
	
	public void setCache(Cache cache) {
		this.cache = cache;
	}
	
	public void setMobileinfoDao(MobileinfoDao mobileinfoDao) {
		this.mobileinfoDao = mobileinfoDao;
	}

	public int findCount(Map map) {
		return mobileinfoDao.findCount(map);
	}

	public List<Mobileinfo> findList(Map map) {
		return mobileinfoDao.findList(map);
	}

	public void save(Mobileinfo mobileinfo) {
		mobileinfoDao.save(mobileinfo);
		this.updateCache();
	}

	public void update(Mobileinfo mobileinfo) {
		mobileinfoDao.update(mobileinfo);
		this.updateCache();
	}

	public Mobileinfo queryMobileinfo(String did) {
		List<Mobileinfo> list = this.findAll();
		for(Mobileinfo mobileinfo:list){
			if(mobileinfo.getDid().equals(did)){
				return mobileinfo;
			}
		}
		return null;
	}
	
	public List<Mobileinfo> findAll() {
		List<Mobileinfo> mobileinfos = null;
		Element element = this.cache.get(Mobileinfo.CACHE_MOBILEINFO);
		if (null != element) {
			mobileinfos = (List<Mobileinfo>)element.getValue();
      } else {
    	  mobileinfos = this.mobileinfoDao.findAll();
          element = new Element(Mobileinfo.CACHE_MOBILEINFO, mobileinfos);
          this.cache.put(element);
      }
      return mobileinfos;
	}

	public int delete(String did) {
		this.updateCache();
		return mobileinfoDao.delete(did);
		
	}
	
	private void updateCache(){
        if(null != this.cache)
              this.cache.remove(Mobileinfo.CACHE_MOBILEINFO);
	}

	public int checkDual(String did) {
		return mobileinfoDao.checkDual(did);
	}

	public int checkUaDual(String ua) {
		return mobileinfoDao.checkUaDual(ua);
	}
	
	public List<Mobileinfo> findMobile() {
		// TODO Auto-generated method stub
		return mobileinfoDao.findMobile();
	}  
}
