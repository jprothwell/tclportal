package com.tcl.gamePortal.dao;

public class PageinfoDao extends BaseDao{

	public int queryPageName(String did) {
		return (Integer)getSqlMapClientTemplate().queryForObject("queryPageName",did);
	}

}
