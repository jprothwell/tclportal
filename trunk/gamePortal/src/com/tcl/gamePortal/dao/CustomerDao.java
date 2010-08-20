package com.tcl.gamePortal.dao;

import org.apache.log4j.Logger;

import com.tcl.gamePortal.domain.Customer;

public class CustomerDao extends BaseDao{
	
	public Logger logger = Logger.getLogger(CustomerDao.class);
	
	public void save(Customer customer) {
		getSqlMapClientTemplate().insert("saveCustomer", customer);
	}

	public Customer queryCustomer(int id) {
		return (Customer)getSqlMapClientTemplate().queryForObject("queryCustomer", id);
		
	}

	public void update(Customer customer) {
		getSqlMapClientTemplate().update("updateCustomer", customer);
	}

	public Customer queryCustomerByName(String userName) {
		return (Customer)getSqlMapClientTemplate().queryForObject("queryCustomerByName", userName);
	}

}
