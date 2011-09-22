package com.tcl.onetouch.dao;

import java.util.List;
import java.util.Map;

import org.apache.log4j.Logger;

import com.tcl.onetouch.domain.Language;

public class LanguageDao extends  BaseDao{
	
	public Logger logger = Logger.getLogger(LanguageDao.class);
	
	public int findCount(Map map) {
		return (Integer) getSqlMapClientTemplate().queryForObject("findLanguageCount",map);
	}

	public List<Language> findList(Map map) {
		return  getSqlMapClientTemplate().queryForList("findLanguageList",map);
	}

	public void save(Language language) {
		getSqlMapClientTemplate().insert("saveLanguage", language);
	}

	public void update(Language language) {
		getSqlMapClientTemplate().update("updateLanguage",language);
	}

	public Language queryLanguage(int id) {
		return (Language)getSqlMapClientTemplate().queryForObject("queryLanguage", id);
	}

	public List<Language> findAll() {
		return  getSqlMapClientTemplate().queryForList("findLanguageAll");
	}

	public int delete(int id) {
		return getSqlMapClientTemplate().delete("deleteLanguage",id);
	}

}
