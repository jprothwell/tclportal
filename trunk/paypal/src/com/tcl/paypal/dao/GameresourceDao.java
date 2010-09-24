package com.tcl.paypal.dao;

import com.tcl.paypal.domain.Gameresource;

public class GameresourceDao extends BaseDao{

	public Gameresource queryGameresource(int id) {
		return (Gameresource)getSqlMapClientTemplate().queryForObject("queryGameresource", id);
	}

}
