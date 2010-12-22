package com.tclPaypal.dao;

import com.tclPaypal.domain.Business;

public class BusinessDao extends BaseDao{

	public void save(Business business) {
		this.getSqlMapClientTemplate().insert("saveBusiness", business);
	}
	
}