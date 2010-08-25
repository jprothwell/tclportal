package com.tcl.portal.dao;

import java.util.List;
import java.util.Map;

import com.tcl.portal.domain.Types;

public class TypesDao extends BaseDao{

	public List<Types> findAll() {
		return getSqlMapClientTemplate().queryForList("findAllTypes");
	}

	public int findCount(Map map) {
		return (Integer)getSqlMapClientTemplate().queryForObject("findTypesCount", map);
	}

	public List<Types> findList(Map map) {
		return getSqlMapClientTemplate().queryForList("findTypesList", map);
	}

	public void save(Types types) {
		getSqlMapClientTemplate().insert("saveTypes", types);
	}

	public void update(Types types) {
		getSqlMapClientTemplate().update("updateTypes", types);
	}

}
