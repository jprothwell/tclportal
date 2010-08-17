package com.tcl.portal.dao;

import java.util.List;
import java.util.Map;

import org.apache.log4j.Logger;

import com.tcl.portal.domain.Gameinfo;

public class GameinfoDao extends  BaseDao{
	
		public Logger logger = Logger.getLogger(GameinfoDao.class);

		public int findCount(Map map) {
			return (Integer) getSqlMapClientTemplate().queryForObject("findGameinfoCount",map);
		}

		public List<Gameinfo> findList(Map map) {
			return  getSqlMapClientTemplate().queryForList("findGameinfoList",map);
		}

		public void save(Gameinfo gameinfo) {
			getSqlMapClientTemplate().insert("saveGameinfo", gameinfo);
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
	
}
