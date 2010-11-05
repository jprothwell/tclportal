package com.tcl.gamePortal.dao;

import java.util.List;
import java.util.Map;

import com.tcl.gamePortal.domain.Gameinfo;

public class GameinfoDao extends BaseDao{

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

	public Gameinfo queryGameinfo(int id) {
		return (Gameinfo)getSqlMapClientTemplate().queryForObject("queryGameinfo", id);
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

}
