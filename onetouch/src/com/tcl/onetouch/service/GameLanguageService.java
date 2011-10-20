package com.tcl.onetouch.service;

import java.util.List;
import java.util.Map;

import com.tcl.onetouch.dao.GameLanguageDao;
import com.tcl.onetouch.domain.GameLanguage;
import com.tcl.onetouch.domain.Ipinfo;

public class GameLanguageService {
	
	private GameLanguageDao gameLanguageDao;
	
	public void setGameLanguageDao(GameLanguageDao gameLanguageDao) {
		this.gameLanguageDao = gameLanguageDao;
	}

	public void save(GameLanguage gameLanguage) {
		gameLanguageDao.save(gameLanguage);
	}

	public void update(GameLanguage gameLanguage) {
		gameLanguageDao.update(gameLanguage);
	}

	public List<GameLanguage> findAll() {
		return  gameLanguageDao.findAll();
	}

	public int delete(int id) {
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
}
