package com.tcl.portal.service;

import java.util.List;
import java.util.Map;

import com.tcl.portal.dao.GameresouceDao;
import com.tcl.portal.domain.Gameresouce;

public class GameresouceService {
	
	private GameresouceDao  gameresouceDao;
	
	public void setGameresouceDao(GameresouceDao gameresouceDao) {
		this.gameresouceDao = gameresouceDao;
	}

	public int findCount(Map map) {
		return gameresouceDao.findCount(map);
	}

	public List<Gameresouce> findList(Map map) {
		return gameresouceDao.findList(map);
	}

	public void save(Gameresouce gameresouce) {
		gameresouceDao.save(gameresouce);
	}

	public void update(Gameresouce gameresouce) {
		gameresouceDao.update(gameresouce);
	}

	public Gameresouce queryGameresouce(int id) {
		return gameresouceDao.queryGameresouce(id);
	}

}
