package com.tcl.portal.service;

import java.util.List;
import java.util.Map;

import com.tcl.portal.dao.CustomerDao;
import com.tcl.portal.domain.Customer;

public class CustomerService {
	
	private CustomerDao customerDao;
	
	public void setCustomerDao(CustomerDao customerDao) {
		this.customerDao = customerDao;
	}

	public int findCount(Map map) {
		return customerDao.findCount(map);
	}

	public List<Customer> findList(Map map) {
		return customerDao.findList(map);
	}

}
