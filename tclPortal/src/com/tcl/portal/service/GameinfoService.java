package com.tcl.portal.service;

import java.util.List;
import java.util.Map;

import net.sf.ehcache.Cache;
import net.sf.ehcache.Element;

import com.tcl.portal.dao.GameinfoDao;
import com.tcl.portal.domain.Country;
import com.tcl.portal.domain.Gameinfo;

public class GameinfoService {
	
	private GameinfoDao gameinfoDao;
	
	private Cache cache;
		
	public void setCache(Cache cache) {
		this.cache = cache;
	}
		
	public void setGameinfoDao(GameinfoDao gameinfoDao) {
		this.gameinfoDao = gameinfoDao;
	}

	public Gameinfo queryGameinfo(int id) {
		List<Gameinfo> list = this.findAll();
		for(Gameinfo gameinfo:list){
			if(gameinfo.getId()==id){
				return gameinfo;
			}
		}
		return null;
	}

	public void update(Gameinfo gameinfo) {
		gameinfoDao.update(gameinfo);
		this.updateCache();
	}

	public void save(Gameinfo gameinfo) {
		gameinfoDao.save(gameinfo);
		this.updateCache();
	}

	public List<Gameinfo> findList(Map map) {
		return gameinfoDao.findList(map);
	}

	public int findCount(Map map) {
		return gameinfoDao.findCount(map);
	}
	
	public List<Gameinfo> findAll(){
		List<Gameinfo> gameinfos = null;
		Element element = this.cache.get(Gameinfo.CACHE_GAMEINFO);
		if (null != element) {
			gameinfos = (List<Gameinfo>)element.getValue();
      } else {
    	  gameinfos = this.gameinfoDao.findAll();
          element = new Element(Gameinfo.CACHE_GAMEINFO, gameinfos);
          this.cache.put(element);
      }
      return gameinfos;
	}
	private void updateCache(){
        if(null != this.cache)
              this.cache.remove(Gameinfo.CACHE_GAMEINFO);
	}
}
