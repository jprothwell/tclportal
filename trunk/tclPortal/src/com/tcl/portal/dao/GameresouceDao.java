package com.tcl.portal.dao;

import java.util.List;
import java.util.Map;

import org.apache.log4j.Logger;

import com.tcl.portal.domain.Gameresouce;

public class GameresouceDao extends  BaseDao{
	
	public Logger logger = Logger.getLogger(GameresouceDao.class);
	
	public int findCount(Map map) {
		return (Integer) getSqlMapClientTemplate().queryForObject("findGameresouceCount",map);
	}

	public List<Gameresouce> findList(Map map) {
		return  getSqlMapClientTemplate().queryForList("findGameresouceList",map);
	}

	public void save(Gameresouce gameresouce) {
		getSqlMapClientTemplate().insert("saveGameresouce", gameresouce);
	}

	public void update(Gameresouce gameresouce) {
		getSqlMapClientTemplate().update("updateGameresouce",gameresouce);
	}

	public Gameresouce queryGameresouce(int id) {
		return (Gameresouce)getSqlMapClientTemplate().queryForObject("queryGameresouce", id);
	}

	public List<Gameresouce> findAll() {
		return  getSqlMapClientTemplate().queryForList("findGameresouceAll");
	}
}
