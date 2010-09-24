package com.tcl.paypal.service;

import com.tcl.paypal.dao.GameresourceDao;
import com.tcl.paypal.domain.Gameresource;

public class GameresourceService {
	
	private GameresourceDao gameresourceDao;
	
	public void setGameresourceDao(GameresourceDao gameresourceDao) {
		this.gameresourceDao = gameresourceDao;
	}


	public Gameresource queryGameresource(int id) {
		return gameresourceDao.queryGameresource(id);
	}



}
