package com.tcl.onetouch.service;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import net.sf.ehcache.Cache;
import net.sf.ehcache.Element;

import com.tcl.onetouch.dao.GameinfoDao;
import com.tcl.onetouch.domain.Gameinfo;
import com.tcl.onetouch.domain.MobileGame;
import com.tcl.onetouch.domain.Mobileinfo;


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
	
	public Gameinfo queryGameinfoNoCache(int id) {
		return gameinfoDao.queryGameinfo(id);
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
	//获取所有游戏列表，不使用缓存
	public List<Gameinfo> findAllNoCache(){
		return gameinfoDao.findAll();
	}
	//游戏基地业务调用 获取游戏和机型对照表的信息
//	public List<MobileGame> findMobileGameAll(){
//		List<MobileGame> mobileGames;
//		Element element = this.cache.get(MobileGame.CACHE_MOBILEGAME);
//		if (null != element) {
//			mobileGames = (List<MobileGame>)element.getValue();
//      } else {
//    	  mobileGames = this.gameinfoDao.findMobileGameAll();
//          element = new Element(MobileGame.CACHE_MOBILEGAME, mobileGames);
//          this.cache.put(element);
//      }
//      return mobileGames;
//	}
	//游戏基地业务调用 按机型获取游戏列表
	public List<MobileGame> findMobileGameByDid(String did){

		List<MobileGame> suitableMobileGame = new ArrayList<MobileGame>();
		 List<MobileGame> mobileGames = gameinfoDao.findMobileGameAll();
		for(MobileGame mobileGame:mobileGames){
			if(did.equals(mobileGame.getDid())){
				suitableMobileGame.add(mobileGame);
			}
		}
		return suitableMobileGame;
	}
	//游戏基地业务调用 在游戏和机型中间表中删除数据
	
	//游戏基地业务调用 在游戏盒中间表中增加数据
	
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

	public int delMobileGame(Map<String, String> map) {
		return gameinfoDao.delMobileGame(map);
	}

	public int addMobileGame(Map<String, String> map) {
		return gameinfoDao.addMobileGame(map);
	}

	public void updateMobileGame(Map viewMap) {
		gameinfoDao.updateMobileGame(viewMap);
	}

	public int saveChinaMobileGame(Gameinfo gameinfo) {
		return gameinfoDao.saveChinaMobileGame(gameinfo);
	}

	public void updateMobileGame(Gameinfo gameinfo) {
		gameinfoDao.updateMobileGame(gameinfo);
	}
	
}
