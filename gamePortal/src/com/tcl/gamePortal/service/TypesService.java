package com.tcl.gamePortal.service;

import com.tcl.gamePortal.dao.TypesDao;

public class TypesService {
	
	private TypesDao typesDao;
	
	public void setTypesDao(TypesDao typesDao) {
		this.typesDao = typesDao;
	}


	public String queryType(int kindid) {
		return typesDao.queryType(kindid);
	}

}
