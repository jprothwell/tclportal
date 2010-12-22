package com.tclPaypal.service;

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
	
	
}
