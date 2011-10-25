package com.tcl.onetouch.service;

import java.util.List;
import java.util.Map;

import net.sf.ehcache.Cache;
import net.sf.ehcache.Element;

import com.tcl.onetouch.dao.GameLanguageDao;
import com.tcl.onetouch.domain.City;
import com.tcl.onetouch.domain.GameLanguage;
import com.tcl.onetouch.domain.Ipinfo;

public class GameLanguageService {
	
	private GameLanguageDao gameLanguageDao;
	
	public void setGameLanguageDao(GameLanguageDao gameLanguageDao) {
		this.gameLanguageDao = gameLanguageDao;
	}
	
	private Cache cache;
	
	public void setCache(Cache cache) {
		this.cache = cache;
	}
	
	public void save(GameLanguage gameLanguage) {
		gameLanguageDao.save(gameLanguage);
		this.updateCache();
	}

	public void update(GameLanguage gameLanguage) {
		gameLanguageDao.update(gameLanguage);
		this.updateCache();
	}

	public List<GameLanguage> findAll() {
		List<GameLanguage> gameLanguages = null;
		Element element = this.cache.get(GameLanguage.CACHE_GAMLANGUAGE);
		if (null != element) {
			gameLanguages = (List<GameLanguage>)element.getValue();
      } else {
    	  gameLanguages = gameLanguageDao.findAll();
          element = new Element(GameLanguage.CACHE_GAMLANGUAGE, gameLanguages);
          this.cache.put(element);
      }
      return gameLanguages;
		//return  gameLanguageDao.findAll();
	}

	public int delete(int id) {
		this.updateCache();
		return gameLanguageDao.delete(id);
		
	}

	public List<GameLanguage> findListByGameId(int id) {
		return gameLanguageDao.findListByGameId(id);
	}

	public GameLanguage queryGameLanguage(int id) {
		 List<GameLanguage> list = findAll();
		 for(GameLanguage gamelanguage:list){
			 if(id==gamelanguage.getId()){
				 return gamelanguage;
			 }
		 }
		return null;
	}

	public GameLanguage queryGameLanguage(int id, int language) {
		 List<GameLanguage> list = findAll();
		 for(GameLanguage gamelanguage:list){
			 if(id==gamelanguage.getGameId()&&language==gamelanguage.getLanguage()){
				 return gamelanguage;
			 }
		 }
		return null;
	}
	
	private void updateCache(){
        if(null != this.cache)
              this.cache.remove(GameLanguage.CACHE_GAMLANGUAGE);
	}
}
