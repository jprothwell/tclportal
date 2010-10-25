package com.tcl.portal.dao;

import java.util.List;
import java.util.Map;

import org.apache.log4j.Logger;

import com.tcl.portal.domain.Ipinfo;

public class IpinfoDao extends  BaseDao{
	
	public Logger logger = Logger.getLogger(IpinfoDao.class);

	public int findCount(Map map) {
		return (Integer) getSqlMapClientTemplate().queryForObject("findIpinfoCount",map);
	}

	public List<Ipinfo> findList(Map map) {
		return  getSqlMapClientTemplate().queryForList("findIpinfoList",map);
	}

	public void save(Ipinfo ipinfo) {
		getSqlMapClientTemplate().insert("saveIpinfo", ipinfo);
	}

	public void update(Ipinfo ipinfo) {
		getSqlMapClientTemplate().update("updateIpinfo",ipinfo);
	}

	public Ipinfo queryIpinfo(int id) {
		return (Ipinfo)getSqlMapClientTemplate().queryForObject("queryIpinfo", id);
	}

	public List<Ipinfo> findAll() {
		return  getSqlMapClientTemplate().queryForList("findIpinfoAll");
	}

	public int delete(int id) {
		return getSqlMapClientTemplate().delete("deleteIpinfo", id);
	}

	public int checkDual(String ip) {
		return (Integer)getSqlMapClientTemplate().queryForObject("checkIpDual",ip);
	}

	public void batchAddFromDownload() {
		getSqlMapClientTemplate().update("batchAddFromDownload");
		
	}

	public void batchAddFormVisite() {
		getSqlMapClientTemplate().update("batchAddFormVisite");
		
	}
	
}
