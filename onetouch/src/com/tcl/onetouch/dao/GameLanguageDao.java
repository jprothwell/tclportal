package com.tcl.onetouch.dao;

import java.util.List;

import org.apache.log4j.Logger;

import com.tcl.onetouch.domain.GameLanguage;
import com.tcl.onetouch.domain.Ipinfo;

public class GameLanguageDao extends  BaseDao{
	
	public Logger logger = Logger.getLogger(GameLanguageDao.class);
	
	public void save(GameLanguage gameLanguage) {
		getSqlMapClientTemplate().insert("saveGameLanguage", gameLanguage);
	}

	public void update(GameLanguage gameLanguage) {
		getSqlMapClientTemplate().update("updateGameLanguage",gameLanguage);
	}

	public List<GameLanguage> findAll() {
		return  getSqlMapClientTemplate().queryForList("findGameLanguageAll");
	}

	public int delete(int id) {
		return getSqlMapClientTemplate().delete("deleteGameLanguage", id);
	}

	public List<GameLanguage> findListByGameId(int id) {
		return getSqlMapClientTemplate().queryForList("findListByGameId",id);
	}
}
