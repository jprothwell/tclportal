package com.tcl.gamePortal.dao;

import java.util.Map;

import com.tcl.gamePortal.domain.Gameresouce;

public class GameresouceDao extends BaseDao{

	public Gameresouce queryGameresouce(Map map) {
		return (Gameresouce)getSqlMapClientTemplate().queryForObject("queryGameresouce", map);
	}

}
