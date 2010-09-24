package com.tcl.paypal.service;

import java.util.List;
import java.util.Map;

import com.tcl.paypal.dao.BusinessDao;
import com.tcl.paypal.domain.Business;

public class BusinessService {
	
	private BusinessDao businessDao;
	
	public void setBusinessDao(BusinessDao businessDao) {
		this.businessDao = businessDao;
	}

	public int findBusiness(Map map) {
		return businessDao.findBusiness(map);
	}

	public void save(Business business) {
		businessDao.save(business);
	}

}
