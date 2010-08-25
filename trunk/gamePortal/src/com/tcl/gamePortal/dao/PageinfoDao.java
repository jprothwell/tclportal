package com.tcl.gamePortal.dao;

public class PageinfoDao extends BaseDao{

	public String queryPageName(String did) {
		return (String)getSqlMapClientTemplate().queryForObject("queryPageName",did);
	}

}
