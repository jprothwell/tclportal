package com.tcl.portal.service;

import java.util.List;
import java.util.Map;

import com.tcl.portal.dao.LogsDao;
import com.tcl.portal.domain.Logs;

public class LogsService {
	
	private LogsDao logsDao;
	
	public void setLogsDao(LogsDao logsDao) {
		this.logsDao = logsDao;
	}

	public int findCount(Map map) {
		return logsDao.findCount(map);
	}

	public List<Logs> findList(Map map) {
		return logsDao.findList(map);
	}

}
