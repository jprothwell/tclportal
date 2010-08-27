package com.tcl.gamePortal.dao;

public class TypesDao extends BaseDao{

	public String queryType(int kindid) {
		return (String)getSqlMapClientTemplate().queryForObject("queryType", kindid);
	}

}
