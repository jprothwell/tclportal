package com.tcl.gamePortal.service;

import com.tcl.gamePortal.dao.MobileinfoDao;

public class MobileinfoService {

	
     private MobileinfoDao mobileinfoDao;

	public void setMobileinfoDao(MobileinfoDao mobileinfoDao) {
		this.mobileinfoDao = mobileinfoDao;
	}
	public String getMobileUa(int did){
		  return mobileinfoDao.getMobileUa(did);
	  } 
     
}