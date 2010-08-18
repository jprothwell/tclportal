package com.tcl.gamePortal.dao;

import java.util.List;
import java.util.Map;

import com.tcl.gamePortal.domain.Gameinfo;

public class GameinfoDao extends BaseDao{

	public List<Gameinfo> findGame(Map map) {
		return getSqlMapClientTemplate().queryForList("findGame", map);
	}

}
