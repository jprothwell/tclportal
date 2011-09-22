package com.tcl.onetouch.dao;

import java.util.List;
import java.util.Map;

import com.tcl.onetouch.domain.Resource;


public class ResourceDao extends  BaseDao{

	public int findCount(Map map) {
		return (Integer) getSqlMapClientTemplate().queryForObject("findResourceCount",map);
	}

	public List<Resource> findList(Map map) {
		return  getSqlMapClientTemplate().queryForList("findResourceList",map);
	}

	public void save(Resource resource) {
		getSqlMapClientTemplate().insert("saveResource", resource);
	}

	public void update(Resource resource) {
		getSqlMapClientTemplate().update("upateResource", resource);
	}

	public Resource queryResource(String id) {
		return (Resource)getSqlMapClientTemplate().queryForObject("queryResource", Integer.parseInt(id));
	}

	public List<Resource> findAll() {
		return getSqlMapClientTemplate().queryForList("findResourceAll");
	}

}
