package com.tcl.portal.dao;

import java.util.List;
import java.util.Map;

import org.apache.log4j.Logger;

import com.tcl.portal.domain.Country;
import com.tcl.portal.domain.User;

public class CountryDao extends  BaseDao{
	
	public Logger logger = Logger.getLogger(CountryDao.class);

	public int findCount(Map map) {
		return (Integer) getSqlMapClientTemplate().queryForObject("findCountryCount",map);
	}

	public List<Country> findList(Map map) {
		return  getSqlMapClientTemplate().queryForList("findCountryList",map);
	}

	public void save(Country country) {
		getSqlMapClientTemplate().insert("saveCountry", country);
	}

	public void update(Country country) {
		getSqlMapClientTemplate().update("updateCountry",country);
	}

	public Country queryCountry(int id) {
		return (Country)getSqlMapClientTemplate().queryForObject("queryCountry", id);
	}

	public List<Country> findAll() {
		return  getSqlMapClientTemplate().queryForList("findCountryAll");
	}

	public int delete(int id) {
		return getSqlMapClientTemplate().delete("deleteCountry", id);
	}
	
}
