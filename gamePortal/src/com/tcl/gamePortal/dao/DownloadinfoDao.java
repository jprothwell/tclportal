package com.tcl.gamePortal.dao;

import com.tcl.gamePortal.domain.Downloadinfo;

public class DownloadinfoDao extends BaseDao{

	public void save(Downloadinfo downloadinfo) {
		getSqlMapClientTemplate().insert("saveDownloadinfo", downloadinfo);
	}

}
