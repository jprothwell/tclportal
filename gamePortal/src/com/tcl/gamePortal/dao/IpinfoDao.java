package com.tcl.gamePortal.dao;

import com.tcl.gamePortal.domain.Ipinfo;

public class IpinfoDao extends BaseDao{

	public Ipinfo queryIpinfo(String ip) {
		return (Ipinfo)getSqlMapClientTemplate().queryForObject("queryIpinfo", ip);
	}
	  public String getMobileUa(int did){
		  return (String)getSqlMapClientTemplate().queryForObject("getMobileUa", did);
	  }
}
