package com.tcl.onetouch.service;

import java.util.List;
import java.util.Map;

import com.tcl.onetouch.dao.GameresouceDao;
import com.tcl.onetouch.domain.Gameresouce;

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

	public int delete(int id) {
		return gameresouceDao.delete(id);
	}

	public List<Gameresouce> findSequenceList(Map map) {
		return gameresouceDao.findSequenceList(map);
	}

	public void update(Map map) {
		gameresouceDao.update(map);
		
	}

	public List<Gameresouce> findGameByDid(Map map) {
		return gameresouceDao.findGameByDid(map);
	}

	public List<Gameresouce> findGameByGameAndDid(Map map) {
		return gameresouceDao.findGameByGameAndDid(map);
	}

	public void batchCreate(List<Gameresouce> gameresouces) {
		gameresouceDao.batchCreate(gameresouces);
	}
	//wap调用
	public  Gameresouce queryGameresouce(Map map) {
		return gameresouceDao.queryGameresouce(map);
	}

	public List<Gameresouce> findGameByCountryAndDid(Map map) {
		return gameresouceDao.findGameByCountryAndDid(map);
	}
}
