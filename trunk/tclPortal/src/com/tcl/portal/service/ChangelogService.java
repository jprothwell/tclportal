package com.tcl.portal.service;

import java.util.List;
import java.util.Map;

import com.tcl.portal.dao.ChangelogDao;
import com.tcl.portal.domain.Changelog;

public class ChangelogService {
	
	private ChangelogDao changelogDao;
	
	public void setChangelogDao(ChangelogDao changelogDao) {
		this.changelogDao = changelogDao;
	}

	public int findCount(Map map) {
		return changelogDao.findCount(map);
	}

	public List<Changelog> findList(Map map) {
		return changelogDao.findList(map);
	}
	
	public void save(Changelog changelog){
		changelogDao.save(changelog);
	}

	public List<Changelog> findList() {
		return changelogDao.findList();
	}
}
