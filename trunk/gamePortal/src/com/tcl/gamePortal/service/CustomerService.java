package com.tcl.gamePortal.service;

import org.apache.log4j.Logger;

import com.tcl.gamePortal.action.CustomerAction;
import com.tcl.gamePortal.dao.CustomerDao;
import com.tcl.gamePortal.domain.Customer;

public class CustomerService {
	
	public Logger logger = Logger.getLogger(CustomerService.class);
	
	private CustomerDao customerDao;
	
	public void setCustomerDao(CustomerDao customerDao) {
		this.customerDao = customerDao;
	}


	public void save(Customer customer) {
		customerDao.save(customer);
	}


	public Customer queryCustomer(int id) {
		return customerDao.queryCustomer(id);
	}


	public void update(Customer customer) {
		customerDao.update(customer);
	}

}
