package com.tcl.onetouch.dao;

import java.util.List;
import java.util.Map;

import org.apache.log4j.Logger;

import com.tcl.onetouch.domain.Customer;

public class CustomerDao extends  BaseDao{
	
	public Logger logger = Logger.getLogger(CustomerDao.class);
	
	public int findCount(Map map) {
		return (Integer) getSqlMapClientTemplate().queryForObject("findCustomerCount",map);
	}

	public List<Customer> findList(Map map) {
		return  getSqlMapClientTemplate().queryForList("findCustomerList",map);
	}

}
