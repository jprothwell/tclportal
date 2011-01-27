package com.tcl.portal.dao;

import java.util.List;
import java.util.Map;

import org.apache.log4j.Logger;

import com.tcl.portal.domain.Visiteinfo;

public class VisiteinfoDao extends  BaseDao{
	
	public Logger logger = Logger.getLogger(VisiteinfoDao.class);
	
	public int findCount(Map map) {
		return (Integer) getSqlMapClientTemplate().queryForObject("findVisiteinfoCount",map);
	}

	public List<Visiteinfo> findList(Map map) {
		return  getSqlMapClientTemplate().queryForList("findVisiteinfoList",map);
	}

	public List<Visiteinfo> findListForExcel(Map map) {
		return  getSqlMapClientTemplate().queryForList("findVisiteinfoListForExcel",map);
	}

}
