package com.tcl.gamePortal.dao;

public class MobileinfoDao extends BaseDao{
  public String getMobileUa(int did){
	  return (String)getSqlMapClientTemplate().queryForObject("getMobileUa", did);
  }
}
