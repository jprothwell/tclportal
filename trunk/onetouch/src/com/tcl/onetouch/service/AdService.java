package com.tcl.onetouch.service;

import java.util.List;
import java.util.Map;

import com.tcl.onetouch.dao.AdDao;
import com.tcl.onetouch.domain.Ad;

public class AdService {
	
	private AdDao  adDao;
	
	public void setAdDao(AdDao adDao) {
		this.adDao = adDao;
	}

	public int findCount(Map map) {
		return adDao.findCount(map);
	}

	public List<Ad> findList(Map map) {
		return adDao.findList(map);
	}

	public void save(Ad ad) {
		adDao.save(ad);
	}

	public void update(Ad ad) {
		adDao.update(ad);
	}

	public Ad queryAd(int id) {
		return adDao.queryAd(id);
	}
	
	public Ad queryAdByDid(String did) {
		
		return (Ad)adDao.queryAdByDid(did);
	}
}
