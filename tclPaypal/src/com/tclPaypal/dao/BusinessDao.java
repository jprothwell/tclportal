package com.tclPaypal.dao;

import java.util.List;
import java.util.Map;

import com.tclPaypal.domain.Business;

public class BusinessDao extends BaseDao{

	public void save(Business business) {
		this.getSqlMapClientTemplate().insert("saveBusiness", business);
	}

	public void update(Business business) {
		this.getSqlMapClientTemplate().update("updateBusiness", business);
	}

	public List<Business> findBusiness(Map map) {
		return this.getSqlMapClientTemplate().queryForList("findBusiness", map);
	}

	public int findBusinessCount(Map map) {
		return (Integer)this.getSqlMapClientTemplate().queryForObject("findBusinessCount", map);
	}

	public List<Business> findBusinessNeedResend() {
		return this.getSqlMapClientTemplate().queryForList("findBusinessNeedResend");
	}
	
}