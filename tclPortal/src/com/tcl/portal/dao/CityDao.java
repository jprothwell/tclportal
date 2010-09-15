package com.tcl.portal.dao;

import java.util.List;
import java.util.Map;

import org.apache.log4j.Logger;

import com.tcl.portal.domain.City;

public class CityDao extends  BaseDao{
	
	public Logger logger = Logger.getLogger(CityDao.class);

	public int findCount(Map map) {
		return (Integer) getSqlMapClientTemplate().queryForObject("findCityCount",map);
	}

	public List<City> findList(Map map) {
		return  getSqlMapClientTemplate().queryForList("findCityList",map);
	}

	public void save(City city) {
		getSqlMapClientTemplate().insert("saveCity", city);
	}

	public void update(City city) {
		getSqlMapClientTemplate().update("updateCity",city);
	}

	public City queryCountry(int id) {
		return (City)getSqlMapClientTemplate().queryForObject("queryCity", id);
	}

	public List<City> findAll() {
		return  getSqlMapClientTemplate().queryForList("findCityAll");
	}

	public int delete(int id) {
		return getSqlMapClientTemplate().delete("deleteCity", id);
	}
}
