package com.tclPaypal.service;

import java.util.List;
import java.util.Map;

import com.tclPaypal.dao.BusinessDao;
import com.tclPaypal.domain.Business;

public class BusinessService {
	
	private BusinessDao businessDao;

	public void setBusinessDao(BusinessDao businessDao) {
		this.businessDao = businessDao;
	}

	public void save(Business business) {
		businessDao.save(business);
	}

	public void update(Business business) {
		businessDao.update(business);
		
	}

	public List<Business> findBusiness(Map map) {
		return businessDao.findBusiness(map);
	}

	public int findBusinessCount(Map map) {
		return businessDao.findBusinessCount(map);
	}

	public List<Business> findBusinessNeedResend() {
		return businessDao.findBusinessNeedResend();
	}
	
	
}
