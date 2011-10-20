package com.tcl.onetouch.service;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import net.sf.ehcache.Cache;
import net.sf.ehcache.Element;

import com.tcl.onetouch.dao.GameinfoDao;
import com.tcl.onetouch.domain.Gameinfo;


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

	public int save(Gameinfo gameinfo) {
		System.out.println("insert gameinfo ......");
		int id = gameinfoDao.save(gameinfo);
		this.updateCache();
		return id;
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
	/**
	 * 列出可用游戏
	 * @return
	 */
	public List<Gameinfo> findUseGameInfo(){
		List<Gameinfo> gameinfos = findAll();
		List<Gameinfo> useGameinfos = new ArrayList<Gameinfo>();
		for(Gameinfo gameinfo:gameinfos){
			if(gameinfo.getDisable()==1){
				useGameinfos.add(gameinfo);
			}
		}
		return useGameinfos;
	}
	private void updateCache(){
        if(null != this.cache)
              this.cache.remove(Gameinfo.CACHE_GAMEINFO);
	}

	public int delete(int id) {
		int i = gameinfoDao.delete(id);
		this.updateCache();
		return i;
	}
	
	public List<Gameinfo> findGame(Map map) {
		return gameinfoDao.findGame(map);
	}
	//wap
	public List<Gameinfo> findGameWap(Map map) {
		return gameinfoDao.findGame(map);
	}


	public int findGameMenoCount(Map map) {
		return gameinfoDao.findGameMenoCount(map);
	}


	public List<Gameinfo> findGameMeno(Map map) {
		return gameinfoDao.findGameMeno(map);
	}


	public int findGMCount(Map map) {
		// TODO Auto-generated method stub
		return gameinfoDao.findGMCount(map);
	}


	public List<Gameinfo> findGM(Map map) {
		// TODO Auto-generated method stub
		return gameinfoDao.findGM(map);
	}


	public int newGMCount(Map map) {
		// TODO Auto-generated method stub
		return gameinfoDao.newGMCount(map);
	}


	public List<Gameinfo> newGM(Map map) {
		// TODO Auto-generated method stub
		return gameinfoDao.newGM(map);
	}

	public int findGameinfoByKindCount(Map map) {
		return gameinfoDao.findGameinfoByKindCount(map);
	}

	public List<Gameinfo> findGameinfoByKind(Map map) {
		return gameinfoDao.findGameinfoByKind(map);
	}

	public int findGameinfoByContentCount(Map map) {
		return gameinfoDao.findGameinfoByContentCount(map);
	}

	public List<Gameinfo> findGameinfoByContent(Map map) {
		return gameinfoDao.findGameinfoByContent(map);
	}

	public int findNewGameCount(Map map) {
		return gameinfoDao.findNewGameCount(map);
	}

	public List<Gameinfo> findNewGame(Map map) {
		return gameinfoDao.findNewGame(map);
	}

	public List<Gameinfo> findGameByLanAndDid(Map map) {
		return gameinfoDao.findGameByLanAndDid(map);
	}

	public Gameinfo queryGameinfoByLanguage(Map map) {
		return gameinfoDao.queryGameinfoByLanguage(map);
	}
	
}
