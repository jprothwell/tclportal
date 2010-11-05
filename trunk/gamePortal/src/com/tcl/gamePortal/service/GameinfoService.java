package com.tcl.gamePortal.service;

import java.util.List;
import java.util.Map;

import com.tcl.gamePortal.dao.GameinfoDao;
import com.tcl.gamePortal.domain.Gameinfo;

public class GameinfoService {
	
	private GameinfoDao gameinfoDao;
	
	public void setGameinfoDao(GameinfoDao gameinfoDao) {
		this.gameinfoDao = gameinfoDao;
	}


	public List<Gameinfo> findGame(Map map) {
		return gameinfoDao.findGame(map);
	}


	public int findGameMenoCount(Map map) {
		return gameinfoDao.findGameMenoCount(map);
	}


	public List<Gameinfo> findGameMeno(Map map) {
		return gameinfoDao.findGameMeno(map);
	}


	public Gameinfo queryGameinfo(int id) {
		return gameinfoDao.queryGameinfo(id);
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

}
