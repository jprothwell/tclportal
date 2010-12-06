package com.tcl.wapStatistic.service;

import java.util.List;

import com.tcl.wapStatistic.dao.LocationDAO;
import com.tcl.wapStatistic.domain.Location;

public class LocationService {
	
	private LocationDAO locationDAO;

	public void setLocationDAO(LocationDAO locationDAO) {
		this.locationDAO = locationDAO;
	}

	public List<Location> findLocationCountryIsNull() {
		return locationDAO.findLocationCountryIsNull();
	}

	public void updateLocation(List<Location> listLocation) {
		locationDAO.updateLocation(listLocation);
	}

	public void updateLocationSigle(Location location) {
		locationDAO.updateLocationSingle(location);
	}
	
	
}
