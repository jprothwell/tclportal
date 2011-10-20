package com.tcl.onetouch.service;

import java.util.List;
import java.util.Map;

import net.sf.ehcache.Cache;
import net.sf.ehcache.Element;

import org.apache.log4j.Logger;

import com.tcl.onetouch.dao.LanguageDao;
import com.tcl.onetouch.domain.Language;


public class LanguageService {
	
	public Logger logger = Logger.getLogger(LanguageService.class);
	
	private LanguageDao languageDao;

	public void setLanguageDao(LanguageDao languageDao) {
		this.languageDao = languageDao;
	}
	
	private Cache cache;
	
	public void setCache(Cache cache) {
		this.cache = cache;
	}
	
	public int findCount(Map map) {
		return languageDao.findCount(map);
	}

	public List<Language> findList(Map map) {
		return languageDao.findList(map);
	}

	public void save(Language language) {
		languageDao.save(language);
		this.updateCache();
	}

	public void update(Language language) {
		languageDao.update(language);
		this.updateCache();
	}

	public Language queryLanguage(int id) {
		return languageDao.queryLanguage(id);
	}
	
	public List<Language> findAll(){
		List<Language> languages = null;
		Element element = this.cache.get(Language.CACHE_LANGUAGE);
		if (null != element) {
			languages = (List<Language>)element.getValue();
      } else {
    	  languages = this.languageDao.findAll();
          element = new Element(Language.CACHE_LANGUAGE, languages);
          this.cache.put(element);
      }
      return languages;
	}
	private void updateCache(){
        if(null != this.cache)
              this.cache.remove(Language.CACHE_LANGUAGE);
	}

	public String queryLanguageName(int languageid) {
		List<Language> languages = findAll();
		for(Language language:languages){
			if(language.getId()==languageid){
				return language.getLanguage();
			}
		}
		return "";
	}

	public int delete(int id) {
		int i = languageDao.delete(id);
		this.updateCache();
		return i;
	}

	public int queryLanguage(String language) {
		List<Language> languages = findAll();
		for(Language lan:languages){
			if(language.equals(lan.getLanguage())){
				return lan.getId();
			}
		}
		return 1;
	}
}
