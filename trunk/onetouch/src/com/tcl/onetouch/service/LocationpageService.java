package com.tcl.onetouch.service;

import java.util.List;
import java.util.Map;

import com.tcl.onetouch.dao.LocationpageDao;
import com.tcl.onetouch.domain.Locationpage;


public class LocationpageService {
	
	private LocationpageDao  locationpageDao;
	
	public void setLocationpageDao(LocationpageDao locationpageDao) {
		this.locationpageDao = locationpageDao;
	}

	public int findCount(Map map) {
		return locationpageDao.findCount(map);
	}

	public List<Locationpage> findList(Map map) {
		return locationpageDao.findList(map);
	}

	public void save(Locationpage locationpage) {
		locationpageDao.save(locationpage);
	}

	public void update(Locationpage locationpage) {
		locationpageDao.update(locationpage);
	}

	public Locationpage queryLocationpage(int id) {
		return locationpageDao.queryLocationpage(id);
	}

	public int delete(int id) {
		return  locationpageDao.delete(id);
		
	}

	public List<Locationpage> findAll() {
		return locationpageDao.findAll();
	}

}