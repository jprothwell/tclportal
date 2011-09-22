package com.tcl.onetouch.service;

import java.util.List;
import java.util.Map;

import net.sf.ehcache.Cache;
import net.sf.ehcache.Element;

import com.tcl.onetouch.dao.PageinfoDao;
import com.tcl.onetouch.domain.Mobileinfo;
import com.tcl.onetouch.domain.Pageinfo;


public class PageinfoService {
	
	private MobileinfoService mobileinfoService;
	
	private PageinfoDao pageinfoDao;
	
	private Cache cache;
	
	public void setMobileinfoService(MobileinfoService mobileinfoService) {
		this.mobileinfoService = mobileinfoService;
	}

	public void setCache(Cache cache) {
		this.cache = cache;
	}
	
	public void setPageinfoDao(PageinfoDao pageinfoDao) {
		this.pageinfoDao = pageinfoDao;
	}

	public int findCount(Map map) {
		return pageinfoDao.findCount(map);
	}

	public List<Pageinfo> findList(Map map) {
		return pageinfoDao.findList(map);
	}

	public void save(Pageinfo pageinfo) {
		pageinfoDao.save(pageinfo);
		this.updateCache();
	}

	public void update(Pageinfo pageinfo) {
		pageinfoDao.update(pageinfo);
		this.updateCache();
	}

	public Pageinfo queryPageinfo(int id) {
		List<Pageinfo> pageinfos = findAll();
		for(Pageinfo pageinfo:pageinfos){
			if(pageinfo.getId()==id){
				return pageinfo;
			}
		}
		return null;
	}
	
	public List<Pageinfo> findAll(){
		List<Pageinfo> pageinfos = null;
		Element element = this.cache.get(Pageinfo.CACHE_PAGEINFO);
		if (null != element) {
			pageinfos = (List<Pageinfo>)element.getValue();
      } else {
    	  pageinfos = this.pageinfoDao.findAll();
          element = new Element(Pageinfo.CACHE_PAGEINFO, pageinfos);
          this.cache.put(element);
      }
      return pageinfos;
	}
	private void updateCache(){
        if(null != this.cache)
              this.cache.remove(Pageinfo.CACHE_PAGEINFO);
	}

	public int delete(int id) {
		int i = pageinfoDao.delete(id);
		this.updateCache();
		return i;
	}
	
	//wap调用
//	public int queryPageName(String did) {
//		return pageinfoDao.queryPageName(did);
//	}
}
