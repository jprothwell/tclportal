package com.tcl.onetouch.dao;

import java.util.List;
import java.util.Map;

import org.apache.log4j.Logger;

import com.tcl.onetouch.domain.Gameinfo;
import com.tcl.onetouch.domain.MobileGame;

public class GameinfoDao extends  BaseDao{
	
		public Logger logger = Logger.getLogger(GameinfoDao.class);

		public int findCount(Map map) {
			return (Integer) getSqlMapClientTemplate().queryForObject("findGameinfoCount",map);
		}

		public List<Gameinfo> findList(Map map) {
			return  getSqlMapClientTemplate().queryForList("findGameinfoList",map);
		}

		public int save(Gameinfo gameinfo) {
			return (Integer)getSqlMapClientTemplate().insert("saveGameinfo", gameinfo);
		}

		public void update(Gameinfo gameinfo) {
			getSqlMapClientTemplate().update("updateGameinfo",gameinfo);
		}

		public Gameinfo queryGameinfo(int id) {
			return (Gameinfo)getSqlMapClientTemplate().queryForObject("queryGameinfo", id);
		}

		public List<Gameinfo> findAll() {
			return  getSqlMapClientTemplate().queryForList("findGameinfoAll");
		}

		public int delete(int id) {
			return getSqlMapClientTemplate().delete("deleteGameinfo", id);
		}
		//wap
		public List<Gameinfo> findGame(Map map) {
			return getSqlMapClientTemplate().queryForList("findGame", map);
		}
		
		public int findGameMenoCount(Map map) {
			// TODO Auto-generated method stub
			return (Integer)getSqlMapClientTemplate().queryForObject("findGameMenoCount", map);
		}


		public List<Gameinfo> findGameMeno(Map map) {
			// TODO Auto-generated method stub
			return getSqlMapClientTemplate().queryForList("findGameMeno",map);
		}

		public int findGMCount(Map map) {
			// TODO Auto-generated method stub
			return (Integer)getSqlMapClientTemplate().queryForObject("findGMCount", map);
		}

		public List<Gameinfo> findGM(Map map) {
			// TODO Auto-generated method stub
			return getSqlMapClientTemplate().queryForList("findGM",map);
		}

		public int newGMCount(Map map) {
			// TODO Auto-generated method stub
			return (Integer)getSqlMapClientTemplate().queryForObject("newGMCount", map);
		}

		public List<Gameinfo> newGM(Map map) {
			// TODO Auto-generated method stub
			return getSqlMapClientTemplate().queryForList("newGM",map);
		}
		
		//新portal方法
		public int findGameinfoByKindCount(Map map) {
			return (Integer)getSqlMapClientTemplate().queryForObject("findGameinfoByKindCount",map);
		}

		public List<Gameinfo> findGameinfoByKind(Map map) {
			return getSqlMapClientTemplate().queryForList("findGameinfoByKindCount",map);
		}

		public int findGameinfoByContentCount(Map map) {
			return (Integer)getSqlMapClientTemplate().queryForObject("findGameinfoByContentCount",map);
		}

		public List<Gameinfo> findGameinfoByContent(Map map) {
			return getSqlMapClientTemplate().queryForList("findGameinfoByContent",map);
		}

		public int findNewGameCount(Map map) {
			return (Integer)getSqlMapClientTemplate().queryForObject("findNewGameCount",map);
		}

		public List<Gameinfo> findNewGame(Map map) {
			return getSqlMapClientTemplate().queryForList("findNewGame",map);
		}

		public List<Gameinfo> findGameByLanAndDid(Map map) {
			return getSqlMapClientTemplate().queryForList("findGameByLanAndDid",map);
		}

		public Gameinfo queryGameinfoByLanguage(Map map) {
			return (Gameinfo)getSqlMapClientTemplate().queryForObject("queryGameinfoByLanguage", map);
		}

		public List<MobileGame> findMobileGameAll() {
			return getSqlMapClientTemplate().queryForList("findMobileGameAll");
		}

		public int delMobileGame(Map<String, String> map) {
			return getSqlMapClientTemplate().delete("deleteMobileGame", map);
		}

		public int addMobileGame(Map<String, String> map) {
			return getSqlMapClientTemplate().delete("saveMobileGame", map);
		}

		public void updateMobileGame(Map viewMap) {
			getSqlMapClientTemplate().update("updateMobileGame",viewMap);
		}

		public Gameinfo queryGameinfoNoCache(int id) {
			return null;
		}

		public int saveChinaMobileGame(Gameinfo gameinfo) {
			return (Integer)getSqlMapClientTemplate().insert("saveChinaMobileGame", gameinfo);
		}

		public void updateMobileGame(Gameinfo gameinfo) {
			getSqlMapClientTemplate().update("updateGameinfoChinaMobileGame", gameinfo);
		}
}
