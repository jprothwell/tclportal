package com.tcl.paypal.dao;

import java.util.Map;

import com.tcl.paypal.domain.Business;

public class BusinessDao extends BaseDao{

	public int findBusiness(Map map) {
		return (Integer)getSqlMapClientTemplate().queryForObject("findBusinessCount",map);
	}

	public void save(Business business) {
		getSqlMapClientTemplate().insert("insertBusiness", business);
	}

}
