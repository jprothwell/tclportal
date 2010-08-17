package com.tcl.gamePortal.dao;

import com.tcl.gamePortal.domain.Visiteinfo;

public class VisiteinfoDao extends BaseDao{

	public void save(Visiteinfo visiteinfo) {
		getSqlMapClientTemplate().insert("saveVisiteinfo", visiteinfo);
	}

}
