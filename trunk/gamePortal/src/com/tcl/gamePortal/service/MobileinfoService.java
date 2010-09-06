package com.tcl.gamePortal.service;

import java.util.List;
import java.util.Map;

import com.tcl.gamePortal.dao.MobileinfoDao;
import com.tcl.gamePortal.domain.Gameinfo;
import com.tcl.gamePortal.domain.Mobileinfo;

public class MobileinfoService {

	
     private MobileinfoDao mobileinfoDao;

	public void setMobileinfoDao(MobileinfoDao mobileinfoDao) {
		this.mobileinfoDao = mobileinfoDao;
	}
	public String getMobileUa(int did){
		  return mobileinfoDao.getMobileUa(did);
	  }
	public List<Mobileinfo> findMobile() {
		// TODO Auto-generated method stub
		return mobileinfoDao.findMobile();
	}  
}