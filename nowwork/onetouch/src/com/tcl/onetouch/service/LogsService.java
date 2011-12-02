package com.tcl.onetouch.service;

import java.util.List;
import java.util.Map;

import com.tcl.onetouch.dao.LogsDao;
import com.tcl.onetouch.domain.Logs;


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
	
	public void save(Logs logs){
		logsDao.save(logs);
	}
}
