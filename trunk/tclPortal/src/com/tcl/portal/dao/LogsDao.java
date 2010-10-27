package com.tcl.portal.dao;

import java.util.List;
import java.util.Map;

import org.apache.log4j.Logger;

import com.tcl.portal.domain.Logs;

public class LogsDao extends  BaseDao{
	
	public Logger logger = Logger.getLogger(LogsDao.class);
	
	public int findCount(Map map) {
		return (Integer) getSqlMapClientTemplate().queryForObject("findLogsCount",map);
	}

	public List<Logs> findList(Map map) {
		return  getSqlMapClientTemplate().queryForList("findLogsList",map);
	}

	public void save(Logs logs) {
		getSqlMapClientTemplate().insert("saveLogs", logs);
	}
}
