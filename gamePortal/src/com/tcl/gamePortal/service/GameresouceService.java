package com.tcl.gamePortal.service;

import java.util.Map;

import com.tcl.gamePortal.dao.GameresouceDao;
import com.tcl.gamePortal.domain.Gameresouce;

public class GameresouceService {
	
	private GameresouceDao gameresouceDao;
	
	public void setGameresouceDao(GameresouceDao gameresouceDao) {
		this.gameresouceDao = gameresouceDao;
	}


	public  Gameresouce queryGameresouce(Map map) {
		return gameresouceDao.queryGameresouce(map);
	}



}
