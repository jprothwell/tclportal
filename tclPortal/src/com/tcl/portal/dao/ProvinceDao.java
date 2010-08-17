package com.tcl.portal.dao;

import java.util.List;
import java.util.Map;

import org.apache.log4j.Logger;

import com.tcl.portal.domain.Province;

public class ProvinceDao extends  BaseDao{
	
	public Logger logger = Logger.getLogger(ProvinceDao.class);

	public int findCount(Map map) {
		return (Integer) getSqlMapClientTemplate().queryForObject("findProvinceCount",map);
	}

	public List<Province> findList(Map map) {
		return  getSqlMapClientTemplate().queryForList("findProvinceList",map);
	}

	public void save(Province province) {
		getSqlMapClientTemplate().insert("saveProvince", province);
	}

	public void update(Province province) {
		getSqlMapClientTemplate().update("updateProvince",province);
	}

	public Province queryProvince(int id) {
		return (Province)getSqlMapClientTemplate().queryForObject("queryProvince", id);
	}

	public List<Province> findAll() {
		return getSqlMapClientTemplate().queryForList("findProvinceAll");
	}
}
